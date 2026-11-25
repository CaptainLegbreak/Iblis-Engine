#include "D2Client.h"
#pragma pack(push, 1)
struct d2data_00712E0C_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00712E0C_t gData_00712E0C; // 0x00712E0C

extern "C" struct d2data_00712E0C_t gData_00712E0C = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00712E0C

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, const char* szPath); // 0x00601340

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile); // 0x00601A50
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

// 0x004788B0
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szPath, 0, ".\\CORE\\ARCHIVE.CPP", 0x53);
    D2CelFileStrc* pCellFile = 0;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\CORE\\ARCHIVE.CPP", 0x56, -1, szPath);
    return pCellFile;
}

// 0x00478950
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFileWithFileSize(const char* szFile, unsigned int* pFileSize, int nType)
{
    char szPath[260];
    strcpy(szPath, szFile);
    strcat(szPath, D2CMPGetGfxFileExtension(nType));
    void* pFile = ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szPath, pFileSize, ".\\CORE\\ARCHIVE.CPP", 0x68);
    D2CelFileStrc* pCellFile = 0;
    CelFileNormalize((D2CelFileStrc*)pFile, &pCellFile, ".\\CORE\\ARCHIVE.CPP", 0x6B, -1, szPath);
    return pCellFile;
}

// 0x00478A00
void __fastcall ARCHIVE_FreeClientCellFile(void* pCel)
{
    CelFileFreeHardware((D2CelFileStrc*)pCel);
    if (pCel)
        FOG_Free(pCel, ".\\CORE\\ARCHIVE.CPP", 0x7A, 0);
}

