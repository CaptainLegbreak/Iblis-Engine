// The oracle runner: maps the player's own stock 1.14d Game.exe into this process and binds the replay functions
// to their 1.14d addresses. The game's entry point is not run. See docs/REPLAY.md.
#include "entry_points.h"

#include <windows.h>
#include <bcrypt.h>
#include <stdio.h>
#include <string.h>
#include <vector>

namespace
{
const DWORD kImageBase = 0x00400000;     // 1.14d's preferred base; relocated if taken
const unsigned char kSha256[32] = {   // SHA-256 of the 1.14d Game.exe
    0x63, 0x10, 0x66, 0xc1, 0x64, 0x9c, 0x4e, 0xa9, 0xff, 0xe4, 0x8b, 0xf9, 0x7e, 0x24, 0xc0, 0x0b,
    0xca, 0x1f, 0x7a, 0x67, 0x59, 0xc2, 0x11, 0x50, 0xf1, 0xa7, 0x99, 0x82, 0x58, 0x9a, 0xda, 0xaf};

bool Fail(const char* szWhat, const char* szDetail = "")
{
    fprintf(stderr, "replay_oracle: %s%s\n", szWhat, szDetail);
    return false;
}

bool Sha256(const std::vector<unsigned char>& data, unsigned char out[32])
{
    BCRYPT_ALG_HANDLE hAlg = 0;
    BCRYPT_HASH_HANDLE hHash = 0;
    bool ok = BCryptOpenAlgorithmProvider(&hAlg, BCRYPT_SHA256_ALGORITHM, 0, 0) == 0 &&
              BCryptCreateHash(hAlg, &hHash, 0, 0, 0, 0, 0) == 0 &&
              BCryptHashData(hHash, (PUCHAR)data.data(), (ULONG)data.size(), 0) == 0 &&
              BCryptFinishHash(hHash, out, 32, 0) == 0;
    if (hHash)
        BCryptDestroyHash(hHash);
    if (hAlg)
        BCryptCloseAlgorithmProvider(hAlg, 0);
    return ok;
}

// Maps the image: headers and sections, base relocations, imports. Returns its base, or 0.
unsigned char* MapImage(const char* szPath)
{
    FILE* f = fopen(szPath, "rb");
    if (!f)
        return Fail("can't open ", szPath), (unsigned char*)0;
    std::vector<unsigned char> file;
    unsigned char buf[65536];
    size_t n;
    while ((n = fread(buf, 1, sizeof(buf), f)) > 0)
        file.insert(file.end(), buf, buf + n);
    fclose(f);

    unsigned char sum[32];
    if (!Sha256(file, sum) || memcmp(sum, kSha256, 32))
        return Fail("not the Diablo II 1.14d Game.exe: ", szPath), (unsigned char*)0;

    const IMAGE_DOS_HEADER* dos = (const IMAGE_DOS_HEADER*)file.data();
    const IMAGE_NT_HEADERS32* nt = (const IMAGE_NT_HEADERS32*)(file.data() + dos->e_lfanew);
    const DWORD nSize = nt->OptionalHeader.SizeOfImage;
    unsigned char* base = (unsigned char*)VirtualAlloc((void*)kImageBase, nSize, MEM_RESERVE | MEM_COMMIT,
                                                       PAGE_EXECUTE_READWRITE);
    if (!base)
        base = (unsigned char*)VirtualAlloc(0, nSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
    if (!base)
        return Fail("can't reserve memory for the image"), (unsigned char*)0;

    memcpy(base, file.data(), nt->OptionalHeader.SizeOfHeaders);
    const IMAGE_SECTION_HEADER* sec = IMAGE_FIRST_SECTION(nt);
    for (int i = 0; i < nt->FileHeader.NumberOfSections; ++i)
        if (sec[i].SizeOfRawData)
            memcpy(base + sec[i].VirtualAddress, file.data() + sec[i].PointerToRawData,
                   min(sec[i].SizeOfRawData, sec[i].Misc.VirtualSize ? sec[i].Misc.VirtualSize : sec[i].SizeOfRawData));

    // Base relocations, if the image isn't at its preferred base.
    const DWORD delta = (DWORD)base - nt->OptionalHeader.ImageBase;
    const IMAGE_DATA_DIRECTORY& rd = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_BASERELOC];
    if (delta && rd.Size)
    {
        const unsigned char* p = base + rd.VirtualAddress;
        const unsigned char* end = p + rd.Size;
        while (p < end)
        {
            const IMAGE_BASE_RELOCATION* blk = (const IMAGE_BASE_RELOCATION*)p;
            if (!blk->SizeOfBlock)
                break;
            const WORD* e = (const WORD*)(blk + 1);
            for (DWORD k = 0; k < (blk->SizeOfBlock - sizeof(*blk)) / 2; ++k)
                if ((e[k] >> 12) == IMAGE_REL_BASED_HIGHLOW)
                    *(DWORD*)(base + blk->VirtualAddress + (e[k] & 0xFFF)) += delta;
            p += blk->SizeOfBlock;
        }
    }

    // Imports, from the system and the DLLs next to Game.exe (Bink, Smacker, IJL).
    char szDir[MAX_PATH];
    strncpy(szDir, szPath, MAX_PATH - 1);
    szDir[MAX_PATH - 1] = 0;
    char* slash = strrchr(szDir, '\\');
    if (!slash)
        slash = strrchr(szDir, '/');
    if (slash)
    {
        *slash = 0;
        SetDllDirectoryA(szDir);
    }
    const IMAGE_DATA_DIRECTORY& id = nt->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
    for (const IMAGE_IMPORT_DESCRIPTOR* imp = (const IMAGE_IMPORT_DESCRIPTOR*)(base + id.VirtualAddress); imp->Name;
         ++imp)
    {
        const char* szDll = (const char*)(base + imp->Name);
        HMODULE h = LoadLibraryA(szDll);
        if (!h)
            return Fail("can't load ", szDll), (unsigned char*)0;
        const IMAGE_THUNK_DATA32* names =
            (const IMAGE_THUNK_DATA32*)(base + (imp->OriginalFirstThunk ? imp->OriginalFirstThunk : imp->FirstThunk));
        IMAGE_THUNK_DATA32* iat = (IMAGE_THUNK_DATA32*)(base + imp->FirstThunk);
        for (; names->u1.AddressOfData; ++names, ++iat)
        {
            FARPROC fn = IMAGE_SNAP_BY_ORDINAL32(names->u1.Ordinal)
                             ? GetProcAddress(h, (LPCSTR)(UINT_PTR)IMAGE_ORDINAL32(names->u1.Ordinal))
                             : GetProcAddress(h, ((const IMAGE_IMPORT_BY_NAME*)(base + names->u1.AddressOfData))->Name);
            iat->u1.Function = (DWORD)fn;     // a missing import stays 0: a case that reaches it fails loudly
        }
    }
    return base;
}
}

bool replay::Bind(Functions* f, int argc, char** argv)
{
    const char* szGame = 0;
    for (int i = 1; i + 1 < argc; ++i)
        if (!strcmp(argv[i], "--game"))
            szGame = argv[i + 1];
    if (!szGame)
        return Fail("--game PATH\\Game.exe is needed (the player's own 1.14d)");
    unsigned char* base = MapImage(szGame);
    if (!base)
        return false;
#define REPLAY_BIND(name, va, type) f->name = (Type<type>)(base + ((va) - kImageBase));
    REPLAY_FUNCTIONS(REPLAY_BIND)
#undef REPLAY_BIND
    return true;
}
