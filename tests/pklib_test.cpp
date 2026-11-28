// Tests of the open PKWARE DCL routines (Source/Storm/pklib).
//
//   pklib_test                    round trips, and the published DCL test stream
//   pklib_test ARCHIVE.mpq ...    also: every file in each archive that the original library compressed is
//                                 exploded and checked against the archive's (attributes) CRC32, then imploded
//                                 and exploded again
//
// Builds on its own (no game source): cl /O2 /EHsc tests\pklib_test.cpp Source\Storm\pklib\*.cpp, or with
// CMake (-DIBLIS_TESTS=ON), or with g++ -D__cdecl= on other systems. The archives are the player's own
// (d2data.mpq, d2exp.mpq, ...); nothing is read from them but what the test checks.
#include "../Source/Storm/pklib/pklib.h"

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <random>
#include <string>
#include <vector>

typedef std::vector<unsigned char> Bytes;

static int gnFailures = 0;
#define CHECK(c, ...) do { if (!(c)) { ++gnFailures; printf("FAIL: " __VA_ARGS__); printf("\n"); } } while (0)

// ---------------------------------------------------------------- explode/implode over byte vectors

struct Io
{
    const unsigned char* pIn;
    size_t nIn, nPos, nChunk;
    Bytes out;
};

static unsigned int __cdecl Read(char* pBuf, unsigned int* pSize, void* pParam)
{
    Io* io = (Io*)pParam;
    size_t n = *pSize;
    if (io->nChunk && n > io->nChunk)
        n = io->nChunk;
    if (n > io->nIn - io->nPos)
        n = io->nIn - io->nPos;
    if (n)
        memcpy(pBuf, io->pIn + io->nPos, n);
    io->nPos += n;
    return (unsigned int)n;
}

static void __cdecl Write(char* pBuf, unsigned int* pSize, void* pParam)
{
    Io* io = (Io*)pParam;
    io->out.insert(io->out.end(), (unsigned char*)pBuf, (unsigned char*)pBuf + *pSize);
}

static char gExplodeWork[EXP_BUFFER_SIZE];
static char gImplodeWork[CMP_BUFFER_SIZE];

static Bytes Explode(const unsigned char* p, size_t n, unsigned int* pErr, size_t nChunk = 0)
{
    Io io = {p, n, 0, nChunk, Bytes()};
    *pErr = explode(Read, Write, gExplodeWork, &io);
    return io.out;
}

static Bytes Implode(const Bytes& in, unsigned int nType, unsigned int nDict, size_t nChunk = 0)
{
    Io io = {in.data(), in.size(), 0, nChunk, Bytes()};
    unsigned int t = nType, d = nDict;
    const unsigned int err = implode(Read, Write, gImplodeWork, &io, &t, &d);
    CHECK(err == CMP_NO_ERROR, "implode returned %u", err);
    return io.out;
}

static void RoundTrip(const Bytes& u, const char* szWhat)
{
    static const unsigned int kDicts[] = {0x400, 0x800, 0x1000};
    for (unsigned int t = 0; t < 2; ++t)
        for (int k = 0; k < 3; ++k)
        {
            const Bytes c = Implode(u, t, kDicts[k], u.size() % 3 ? 0 : 1 + u.size() % 257);
            unsigned int err;
            const Bytes d = Explode(c.data(), c.size(), &err, u.size() % 2 ? 0 : 1 + u.size() % 113);
            CHECK(err == CMP_NO_ERROR && d == u, "%s: round trip (mode %u, dictionary %u, %u bytes)", szWhat, t,
                  kDicts[k], (unsigned)u.size());
        }
}

static void SelfTests()
{
    // The example stream from the format's description (see zlib contrib/blast).
    static const unsigned char kStream[] = {0x00, 0x04, 0x82, 0x24, 0x25, 0x8f, 0x80, 0x7f};
    unsigned int err;
    const Bytes out = Explode(kStream, sizeof(kStream), &err);
    CHECK(err == CMP_NO_ERROR && std::string(out.begin(), out.end()) == "AIAIAIAIAIAIA", "the published test stream");

    std::mt19937 rng(1);
    int n = 0;
    for (int k = 0; k < 200; ++k)
    {
        const size_t len = k < 10 ? k : rng() % 70000;
        Bytes u(len);
        for (size_t i = 0; i < len; ++i)
        {
            switch (k % 4)
            {
            case 0: u[i] = (unsigned char)rng(); break;
            case 1: u[i] = "the quick brown fox jumps over the lazy dog. "[rng() % 45]; break;
            case 2: u[i] = (unsigned char)(i % 517 < 300 ? 'A' : rng() % 3); break;
            default: u[i] = (unsigned char)(i > 8 && rng() % 4 ? u[i - 1 - rng() % 8] : rng()); break;
            }
        }
        RoundTrip(u, "generated data");
        n += 6;
    }
    printf("self tests: %d round trips\n", n);
}

// ---------------------------------------------------------------- MPQ archives

static uint32_t gaCrypt[0x500];

static void InitCrypt()
{
    uint32_t seed = 0x00100001;
    for (int i = 0; i < 0x100; ++i)
        for (int k = 0, j = i; k < 5; ++k, j += 0x100)
        {
            seed = (seed * 125 + 3) % 0x2AAAAB;
            const uint32_t hi = (seed & 0xFFFF) << 16;
            seed = (seed * 125 + 3) % 0x2AAAAB;
            gaCrypt[j] = hi | (seed & 0xFFFF);
        }
}

static uint32_t HashString(const char* s, int nType)
{
    uint32_t a = 0x7FED7FED, b = 0xEEEEEEEE;
    for (; *s; ++s)
    {
        int c = (unsigned char)*s;
        if (c >= 'a' && c <= 'z')
            c -= 32;
        if (c == '/')
            c = '\\';
        a = gaCrypt[nType * 0x100 + c] ^ (a + b);
        b = c + a + b + (b << 5) + 3;
    }
    return a;
}

static void Decrypt(uint32_t* p, size_t n, uint32_t key)
{
    uint32_t seed = 0xEEEEEEEE;
    for (size_t i = 0; i < n; ++i)
    {
        seed += gaCrypt[0x400 + (key & 0xFF)];
        const uint32_t v = p[i] ^ (key + seed);
        key = ((~key << 21) + 0x11111111) | (key >> 11);
        seed = v + seed + (seed << 5) + 3;
        p[i] = v;
    }
}

static uint32_t Crc32(const Bytes& b)
{
    uint32_t c = 0xFFFFFFFF;
    for (size_t i = 0; i < b.size(); ++i)
    {
        c ^= b[i];
        for (int k = 0; k < 8; ++k)
            c = (c >> 1) ^ (0xEDB88320 & (0 - (c & 1)));
    }
    return ~c;
}

struct Block
{
    uint32_t nPos, nCSize, nSize, nFlags;
};

enum
{
    MPQ_IMPLODE = 0x100,
    MPQ_COMPRESS = 0x200,
    MPQ_ENCRYPTED = 0x10000,
    MPQ_SINGLE_UNIT = 0x1000000,
    MPQ_EXISTS = 0x80000000,
};

struct Archive
{
    FILE* f;
    uint64_t nBase;
    uint32_t nSectorSize;
    std::vector<uint32_t> hash;
    std::vector<Block> blocks;
};

static bool ReadAt(FILE* f, uint64_t pos, void* p, size_t n)
{
#ifdef _WIN32
    if (_fseeki64(f, (long long)pos, SEEK_SET))
        return false;
#else
    if (fseeko(f, (off_t)pos, SEEK_SET))
        return false;
#endif
    return fread(p, 1, n, f) == n;
}

static bool OpenArchive(const char* szPath, Archive* a)
{
    a->f = fopen(szPath, "rb");
    if (!a->f)
        return false;
    uint32_t h[8];
    for (a->nBase = 0; ReadAt(a->f, a->nBase, h, sizeof(h)); a->nBase += 0x200)
    {
        if (h[0] != 0x1A51504D)     // 'MPQ\x1A'
            continue;
        a->nSectorSize = 0x200u << (h[3] >> 16 & 0xFFFF);
        const uint32_t nHashPos = h[4], nBlockPos = h[5], nHashes = h[6], nBlocks = h[7];
        a->hash.resize(nHashes * 4);
        a->blocks.resize(nBlocks);
        if (!ReadAt(a->f, a->nBase + nHashPos, a->hash.data(), nHashes * 16) ||
            !ReadAt(a->f, a->nBase + nBlockPos, a->blocks.data(), nBlocks * 16))
            return false;
        Decrypt(a->hash.data(), nHashes * 4, HashString("(hash table)", 3));
        Decrypt((uint32_t*)a->blocks.data(), nBlocks * 4, HashString("(block table)", 3));
        return true;
    }
    return false;
}

static int FindBlock(const Archive& a, const char* szName)
{
    const size_t n = a.hash.size() / 4;
    const uint32_t i0 = HashString(szName, 0), h1 = HashString(szName, 1), h2 = HashString(szName, 2);
    for (size_t k = 0, i = i0 % n; k < n; ++k, i = (i + 1) % n)
    {
        const uint32_t* e = &a.hash[i * 4];
        if (e[3] == 0xFFFFFFFF)
            return -1;
        if (e[0] == h1 && e[1] == h2 && e[3] < a.blocks.size())
            return (int)e[3];
    }
    return -1;
}

// Reads a file by block. *pbOriginal is set when a sector was compressed by the PKWARE library (imploded).
// Returns false when the file can't be read here (encrypted, or another compression).
static bool ReadBlock(const Archive& a, const Block& b, Bytes* pOut, bool* pbOriginal, std::string* pWhy)
{
    *pbOriginal = false;
    if (b.nFlags & MPQ_ENCRYPTED)
    {
        *pWhy = "encrypted";
        return false;
    }
    if (!(b.nFlags & (MPQ_IMPLODE | MPQ_COMPRESS)))
    {
        pOut->resize(b.nSize);
        return b.nSize == 0 || ReadAt(a.f, a.nBase + b.nPos, pOut->data(), b.nSize);
    }
    const uint32_t nSectors = (b.nFlags & MPQ_SINGLE_UNIT) ? 1 : (b.nSize + a.nSectorSize - 1) / a.nSectorSize;
    std::vector<uint32_t> offs(nSectors + 1);
    if (b.nFlags & MPQ_SINGLE_UNIT)
    {
        offs[0] = 0;
        offs[1] = b.nCSize;
    }
    else if (!ReadAt(a.f, a.nBase + b.nPos, offs.data(), offs.size() * 4))
        return false;
    pOut->clear();
    for (uint32_t s = 0; s < nSectors; ++s)
    {
        const uint32_t nWant = (b.nFlags & MPQ_SINGLE_UNIT) ? b.nSize
                             : (s + 1 < nSectors ? a.nSectorSize : b.nSize - s * a.nSectorSize);
        Bytes raw(offs[s + 1] - offs[s]);
        if (raw.empty() || !ReadAt(a.f, a.nBase + b.nPos + offs[s], raw.data(), raw.size()))
            return false;
        if (raw.size() >= nWant)
        {
            pOut->insert(pOut->end(), raw.begin(), raw.begin() + nWant);
            continue;
        }
        const unsigned char* p = raw.data();
        size_t n = raw.size();
        if (b.nFlags & MPQ_COMPRESS)
        {
            if (p[0] != 0x08)
            {
                *pWhy = "another compression";
                return false;
            }
            ++p;
            --n;
        }
        unsigned int err;
        const Bytes sector = Explode(p, n, &err);
        if (err != CMP_NO_ERROR || sector.size() != nWant)
        {
            *pWhy = "explode failed";
            return false;
        }
        *pbOriginal = true;
        pOut->insert(pOut->end(), sector.begin(), sector.end());
    }
    return true;
}

static void TestArchive(const char* szPath)
{
    Archive a = {};
    if (!OpenArchive(szPath, &a))
    {
        CHECK(false, "%s: not an MPQ archive", szPath);
        return;
    }
    std::vector<uint32_t> crcs;
    const int nAttr = FindBlock(a, "(attributes)");
    if (nAttr >= 0)
    {
        Bytes attr;
        bool bOriginal;
        std::string why;
        if (ReadBlock(a, a.blocks[nAttr], &attr, &bOriginal, &why) && attr.size() >= 8 && (attr[4] & 1))
        {
            crcs.resize(a.blocks.size());
            memcpy(crcs.data(), attr.data() + 8, std::min(attr.size() - 8, crcs.size() * 4));
        }
    }
    int nExploded = 0, nChecked = 0, nSkipped = 0;
    unsigned long long nBytes = 0;
    for (size_t i = 0; i < a.blocks.size(); ++i)
    {
        const Block& b = a.blocks[i];
        if (!(b.nFlags & MPQ_EXISTS) || (int)i == nAttr)
            continue;
        Bytes data;
        bool bOriginal;
        std::string why;
        if (!ReadBlock(a, b, &data, &bOriginal, &why))
        {
            CHECK(why != "explode failed", "%s: block %u: %s", szPath, (unsigned)i, why.c_str());
            ++nSkipped;
            continue;
        }
        if (!bOriginal)
            continue;
        ++nExploded;
        nBytes += data.size();
        if (!crcs.empty() && crcs[i])
        {
            CHECK(Crc32(data) == crcs[i], "%s: block %u: CRC32 differs after explode", szPath, (unsigned)i);
            ++nChecked;
        }
        if (nExploded % 50 == 1)
            RoundTrip(data, szPath);
    }
    printf("%s: %d files the original library compressed exploded (%llu bytes), %d checked against (attributes), "
           "%d skipped\n", szPath, nExploded, nBytes, nChecked, nSkipped);
    CHECK(nExploded > 0, "%s: no imploded file found", szPath);
    fclose(a.f);
}

int main(int argc, char** argv)
{
    InitCrypt();
    SelfTests();
    for (int i = 1; i < argc; ++i)
        TestArchive(argv[i]);
    printf(gnFailures ? "%d FAILURES\n" : "all passed\n", gnFailures);
    return gnFailures ? 1 : 0;
}
