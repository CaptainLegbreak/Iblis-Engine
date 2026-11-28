#include "D2LanguageNames.h"

#include "D2Client.h"
#include "FogApi.h"

#include "D2CMPApi.h"
#include "D2HellApi.h"

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);
extern "C" char* __cdecl strcat(char* szDst, const char* szSrc);
void __stdcall CelFileNormalize(D2CelFileStrc* pFile, D2CelFileStrc** ppOutFile, const char* szFile, int nLine, int nSpecVersion, const char* szPath); // 0x00601340

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

