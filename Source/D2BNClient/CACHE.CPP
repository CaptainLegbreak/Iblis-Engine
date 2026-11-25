#include "D2BNClient.h"
#include "D2GameTypes.h"
#include "D2SysTypes.h"
#include "D2Primitives.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* szFileName); // 0x006CC1A0

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* szPathName, void* pSecurityAttributes); // 0x006CC1B8

extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C

void __cdecl CACHE_FreeCache(); // 0x00519300

int __cdecl CACHE_LoadCache(); // 0x005193E0

static void* ghCacheFile; // 0x0072FB78

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

// A critical section for the whole run: initialized before main, deleted at exit.
struct CCritSect : D2CriticalSectionStrc
{
    CCritSect() { InitializeCriticalSection(this); }
    ~CCritSect() { DeleteCriticalSection(this); }
};

// build: symbol ??__EgtCacheLock@@YAXXZ 0x006CAEA0
// build: symbol ??__FgtCacheLock@@YAXXZ 0x006CB440
CCritSect gtCacheLock;                                                                  // 0x00881894

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" int __cdecl toupper(int nChar);                                                                  // 0x00685385

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pFileSizeHigh); // 0x006CC2F0

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x00413800

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);                                         // 0x0041C340

void __cdecl BNDOWNLOAD_LogPrintf(const char* szFormat, ...);                                                   // 0x00518D40

void __cdecl sub_00519000_InitCryptTable();

void __cdecl CACHE_DeleteCacheFile();                                                                // 0x005192A0

struct D2CacheHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwHeaderSize;
    unsigned int dwFileSize;
    unsigned int unk0x0C;
    unsigned int dwHashOffset;
    unsigned int dwBlockOffset;
    unsigned int nHashTableSize;
    unsigned int nBlockTableSize;
    unsigned int dwHeaderCrc;
    unsigned int dwHashCrc;
    unsigned int dwBlockCrc;
};

struct D2CacheBlockEntryStrc
{
    unsigned int dwOffset;
    unsigned int dwSize;
    unsigned int dwDataSize;
    unsigned int dwFlags;
};

struct D2CacheRecordStrc
{
    unsigned int dwSize;
    unsigned int unk0x04;
    unsigned int unk0x08;
    unsigned int dwCrc;
    unsigned int dwDataCrc;
    unsigned int unk0x14;
    D2FileTimeStrc tLastAccess;
    D2FileTimeStrc tFileTime;
    D2FileTimeStrc tCreated;
    D2FileTimeStrc tStale;
    D2FileTimeStrc tExpiry;
    char szName[0x104];
};

extern unsigned int gadwCacheCrcTable[];                                                            // 0x0072FB80

static D2CacheHeaderStrc* gpCacheHeader; // 0x00881880

static D2CacheBlockEntryStrc* gpCacheBlockTable; // 0x00881884

static unsigned int* gpCacheCryptTable; // 0x00881888

static D2CacheHashEntryStrc* gpCacheHashTable; // 0x0088188C

int gbCacheLoaded; // 0x00881890

extern unsigned __int64 gqwCacheFileTime; // 0x008818AC

extern unsigned long gdwCacheTimeTick; // 0x008818B4

extern unsigned int gnCacheTimeSeconds; // 0x008818B8

extern const char gszCacheFile[]; // 0x006DEE70

extern const char gszCorruptFile[]; // 0x006DEEC0

extern const char gszCorruptCache[]; // 0x006DEF00

#define CACHE_CRC32(dwCrc, pBytes, nCount) \
    dwCrc = 0xFFFFFFFF; \
    for (; nCount; --nCount, ++pBytes) \
        dwCrc = (dwCrc >> 8) ^ gadwCacheCrcTable[(*pBytes ^ dwCrc) & 0xFF]; \
    dwCrc = ~dwCrc




extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

void* __stdcall sub_00413020_Alloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

void __cdecl CACHE_ResetCache(); // 0x005198C0

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8

extern "C" __declspec(dllimport) long __stdcall CompareFileTime(const D2FileTimeStrc* pFileTime1, const D2FileTimeStrc* pFileTime2); // 0x006CC390

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, void* pFileTime); // 0x006CC26C

static void CACHE_GetCacheFilePath(char* szPath); // 0x00519220

static unsigned int sub_00518DE0_Crc32(const void* pData, unsigned int nSize)
{
    VALIDATEBEGIN;
    VALIDATE(pData || !nSize);
    D2_ASSERT(pData || !nSize, 0x91);
    VALIDATEEND;

    const unsigned char* pBytes = (const unsigned char*)pData;
    unsigned int dwCrc;
    CACHE_CRC32(dwCrc, pBytes, nSize);
    return dwCrc;
}

static void sub_00518E60_DecryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    nLength >>= 2;
    while (nLength-- != 0)
    {
        dwSeed += gpCacheCryptTable[0x400 + (dwKey & 0xFF)];
        *pData ^= dwKey + dwSeed;
        unsigned int ch = *pData++;
        dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
        dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
    }
}

static void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    unsigned int nCount = nLength >> 2;
    if (nCount != 0)
    {
        const unsigned int* pTable = gpCacheCryptTable;
        do
        {
            --nCount;
            unsigned int ch = *pData;
            dwSeed += pTable[0x400 + (dwKey & 0xFF)];
            *pData = ch ^ (dwKey + dwSeed);
            dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
            dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
            ++pData;
        } while (nCount != 0);
    }
}

static D2FileTimeStrc* sub_00518F30_GetCacheFileTime(unsigned int nSeconds)
{
    if (nSeconds != gnCacheTimeSeconds || GetTickCount() != gdwCacheTimeTick)
    {
        D2SystemTimeStrc tSystemTime;
        GetSystemTime(&tSystemTime);
        SystemTimeToFileTime(&tSystemTime, &gqwCacheFileTime);
        gqwCacheFileTime += (unsigned __int64)nSeconds * 10000000;
        gnCacheTimeSeconds = nSeconds;
        gdwCacheTimeTick = GetTickCount();
    }
    return (D2FileTimeStrc*)&gqwCacheFileTime;
}

static unsigned int __stdcall sub_00518FA0_HashString(unsigned int nHashType, const char* szString)
{
    unsigned int dwSeed1 = 0x7FED7FED;
    unsigned int dwSeed2 = 0xEEEEEEEE;
    while (szString && *szString)
    {
        char ch = (char)toupper(*szString++);
        dwSeed1 = gpCacheCryptTable[(nHashType << 8) + ch] ^ (dwSeed1 + dwSeed2);
        dwSeed2 = ch + dwSeed1 + dwSeed2 + (dwSeed2 << 5) + 3;
    }
    return dwSeed1;
}

// 0x00519110
static int __stdcall CACHE_FindHashEntry(const char* szName, unsigned int dwLocale)
{
    unsigned int dwHash = sub_00518FA0_HashString(0, szName);
    unsigned int dwNameA = sub_00518FA0_HashString(1, szName);
    unsigned int dwNameB = sub_00518FA0_HashString(2, szName);
    unsigned int nSize = gpCacheHeader->nHashTableSize;
    unsigned int dwIndex = dwHash & (nSize - 1);
    D2CacheHashEntryStrc* pTable = gpCacheHashTable;
    unsigned int dwStart = dwIndex;
    int nFallback = -1;

    unsigned int dwBlock;
    while ((dwBlock = pTable[dwIndex].dwBlockIndex) != (unsigned int)-1)
    {
        if (pTable[dwIndex].dwNameA == dwNameA && pTable[dwIndex].dwNameB == dwNameB && dwBlock != (unsigned int)-2)
        {
            if (pTable[dwIndex].dwLocale == dwLocale)
                return dwIndex;
            if (!pTable[dwIndex].dwLocale)
                nFallback = dwIndex;
        }

        dwIndex = (dwIndex + 1) & (nSize - 1);
        if (dwIndex == dwStart)
            break;
    }

    return nFallback;
}

static void sub_H08_ClearBlockEntry(D2CacheBlockEntryStrc* pBlockTable, unsigned int nBlock)
{
    pBlockTable[nBlock].dwDataSize = 0;
    pBlockTable[nBlock].dwFlags = 0;
}

static void sub_005191D0_DeleteHashEntries(const char* szName)
{
    int nIndex;
    while ((nIndex = CACHE_FindHashEntry(szName, 0)) != -1)
    {
        unsigned int* pBlock = &gpCacheHashTable[nIndex].dwBlockIndex;
        if (*pBlock < gpCacheHeader->nBlockTableSize)
        {
            sub_H08_ClearBlockEntry(gpCacheBlockTable, *pBlock);
        }
        *pBlock = (unsigned int)-2;
    }
}

// 0x00519220
static void CACHE_GetCacheFilePath(char* szPath)
{
    D2_ASSERT(SHGetFolderPathA(0, 0x23, 0, 0, szPath) == 0, 0x112);
    SStrPack(szPath, "\\Blizzard Entertainment", 0x104);
    CreateDirectoryA(szPath, 0);
    SStrPack(szPath, "\\Diablo II", 0x104);
    CreateDirectoryA(szPath, 0);
    SStrPack(szPath, "\\bncache.dat", 0x104);
}

// 0x005192A0
void __cdecl CACHE_DeleteCacheFile()
{
    char szPath[260];

    if (ghCacheFile != (void*)-1)
    {
        CloseHandle(ghCacheFile);
        ghCacheFile = (void*)-1;
    }

    szPath[0] = 0;
    CACHE_GetCacheFilePath(szPath);
    DeleteFileA(szPath);
}

// 0x00519300
void __cdecl CACHE_FreeCache()
{
    EnterCriticalSection(&gtCacheLock);
    gbCacheLoaded = 0;
    if (gpCacheBlockTable)
    {
        SMemFree(gpCacheBlockTable, ".\\CACHE.CPP", 0x155, 0);
        gpCacheBlockTable = 0;
    }
    if (gpCacheHashTable)
    {
        SMemFree(gpCacheHashTable, ".\\CACHE.CPP", 0x159, 0);
        gpCacheHashTable = 0;
    }
    if (gpCacheHeader)
    {
        SMemFree(gpCacheHeader, ".\\CACHE.CPP", 0x15D, 0);
        gpCacheHeader = 0;
    }
    if (ghCacheFile != (void*)-1)
    {
        CloseHandle(ghCacheFile);
        ghCacheFile = (void*)-1;
    }
    if (gpCacheCryptTable)
    {
        SMemFree(gpCacheCryptTable, ".\\CACHE.CPP", 0x165, 0);
        gpCacheCryptTable = 0;
    }
    LeaveCriticalSection(&gtCacheLock);
}

// 0x005193C0
int __fastcall CACHE_FreeCachedFile(void* pData, unsigned int nSize)
{
    if (!pData)
        return 0;
    SMemFree(pData, ".\\CACHE.CPP", 0x16F, 0);
    return 1;
}

#pragma function(memset)

// 0x005193E0
int __cdecl CACHE_LoadCache()
{
    char szPath[0x104];
    unsigned long nTableRead;
    unsigned long nFileSize;
    unsigned long nHeaderRead;
    D2CacheHeaderStrc* pHeader;

    EnterCriticalSection(&gtCacheLock);
    if (gbCacheLoaded)
    {
        CACHE_FreeCache();
    }

    szPath[0] = 0;
    CACHE_GetCacheFilePath(szPath);
    ghCacheFile = CreateFileA(szPath, 0xC0000000, 0, 0, 4, 0x80, 0);
    if (ghCacheFile == (void*)-1)
    {
        CACHE_FreeCache();
        LeaveCriticalSection(&gtCacheLock);
        return 0;
    }

    gpCacheCryptTable = (unsigned int*)SMemAlloc(0x1400, ".\\CACHE.CPP", 0x193, 0);
    sub_00519000_InitCryptTable();
    gpCacheHeader = (D2CacheHeaderStrc*)SMemAlloc(sizeof(D2CacheHeaderStrc), ".\\CACHE.CPP", 0x197, 8);
    nFileSize = GetFileSize(ghCacheFile, 0);
    if (nFileSize && nFileSize <= 0xA00000)
    {
        int nError;
        unsigned int dwHeaderCrc;
        unsigned int nHashSize;
        unsigned int nBlockSize;
        if (nFileSize < sizeof(D2CacheHeaderStrc))
        {
            nError = 1;
            goto error;
        }

        ReadFile(ghCacheFile, gpCacheHeader, sizeof(D2CacheHeaderStrc), &nHeaderRead, 0);
        if (nHeaderRead < sizeof(D2CacheHeaderStrc))
        {
            nError = 2;
            goto error;
        }

        if (gpCacheHeader->dwMagic == 0x1A324E42)
        {
            goto create;
        }

        if (gpCacheHeader->dwMagic != 0x1A334E42)
        {
            nError = 3;
            goto error;
        }

        dwHeaderCrc = gpCacheHeader->dwHeaderCrc;
        {
            unsigned int nCount = sizeof(D2CacheHeaderStrc);
            gpCacheHeader->dwHeaderCrc = 0;
            const unsigned char* pBytes = (const unsigned char*)gpCacheHeader;
            unsigned int dwCrc;
            CACHE_CRC32(dwCrc, pBytes, nCount);
            if (dwHeaderCrc != dwCrc)
            {
                nError = 4;
                goto error;
            }
        }
        gpCacheHeader->dwHeaderCrc = dwHeaderCrc;

        if (!gpCacheHeader->dwHashOffset || !gpCacheHeader->nHashTableSize)
        {
            nError = 5;
            goto error;
        }

        if (!gpCacheHeader->dwBlockOffset || !gpCacheHeader->nBlockTableSize)
        {
            nError = 6;
            goto error;
        }

        nHashSize = gpCacheHeader->nHashTableSize;
        if (nHashSize < 0x400)
        {
            nHashSize = 0x400;
        }
        nHashSize *= sizeof(D2CacheHashEntryStrc);
        if (gpCacheHeader->dwHashOffset + nHashSize > nFileSize)
        {
            nError = 7;
            goto error;
        }

        gpCacheHashTable = (D2CacheHashEntryStrc*)SMemAlloc(nHashSize, ".\\CACHE.CPP", 0x1CC, 8);
        SetFilePointer(ghCacheFile, gpCacheHeader->dwHashOffset, 0, 0);
        ReadFile(ghCacheFile, gpCacheHashTable, nHashSize, &nTableRead, 0);
        if (nTableRead != nHashSize)
        {
            nError = 8;
            goto error;
        }

        if (gpCacheHeader->dwHashCrc != sub_00518DE0_Crc32(gpCacheHashTable, nHashSize))
        {
            nError = 9;
            goto error;
        }

        sub_00518E60_DecryptBlock((unsigned int*)gpCacheHashTable, nHashSize, sub_00518FA0_HashString(3, "(hash table)"));

        nBlockSize = gpCacheHeader->nBlockTableSize;
        if (nBlockSize < 0x400)
        {
            nBlockSize = 0x400;
        }
        nBlockSize *= sizeof(D2CacheBlockEntryStrc);
        if (gpCacheHeader->dwBlockOffset + nBlockSize > nFileSize)
        {
            nError = 10;
            goto error;
        }

        gpCacheBlockTable = (D2CacheBlockEntryStrc*)SMemAlloc(nBlockSize, ".\\CACHE.CPP", 0x1E2, 8);
        SetFilePointer(ghCacheFile, gpCacheHeader->dwBlockOffset, 0, 0);
        ReadFile(ghCacheFile, gpCacheBlockTable, nBlockSize, &nTableRead, 0);
        if (nTableRead != nBlockSize)
        {
            nError = 11;
            goto error;
        }

        if (gpCacheHeader->dwBlockCrc != sub_00518DE0_Crc32(gpCacheBlockTable, nBlockSize))
        {
            nError = 12;
            goto error;
        }

        sub_00518E60_DecryptBlock((unsigned int*)gpCacheBlockTable, nBlockSize, sub_00518FA0_HashString(3, "(block table)"));
        goto loaded;

error:
        BNDOWNLOAD_LogPrintf("WARNING- cache file is invalid. Replacing with new cache file", nError);
    }

create:
    if (!gbCacheLoaded)
    {
        if (gpCacheHashTable)
        {
            SMemFree(gpCacheHashTable, ".\\CACHE.CPP", 0x1FC, 0);
        }
        if (gpCacheBlockTable)
        {
            SMemFree(gpCacheBlockTable, ".\\CACHE.CPP", 0x1FE, 0);
        }
        CACHE_DeleteCacheFile();
        ghCacheFile = CreateFileA(szPath, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (ghCacheFile == (void*)-1)
        {
            CACHE_FreeCache();
            LeaveCriticalSection(&gtCacheLock);
            return 0;
        }

        pHeader = gpCacheHeader;
        memset(pHeader, 0, sizeof(D2CacheHeaderStrc));
        pHeader->dwMagic = 0x1A334E42;
        pHeader->dwHeaderSize = sizeof(D2CacheHeaderStrc);
        gpCacheHashTable = (D2CacheHashEntryStrc*)SMemAlloc(0x400 * sizeof(D2CacheHashEntryStrc), ".\\CACHE.CPP", 0x21C, 8);
        gpCacheHeader->dwHashOffset = sizeof(D2CacheHeaderStrc);
        gpCacheHeader->nHashTableSize = 0x400;
        gpCacheHeader->dwFileSize = gpCacheHeader->dwFileSize > sizeof(D2CacheHeaderStrc) + 0x400 * sizeof(D2CacheHashEntryStrc) ? gpCacheHeader->dwFileSize : sizeof(D2CacheHeaderStrc) + 0x400 * sizeof(D2CacheHashEntryStrc);
        for (int i = 0; i < 0x400; ++i)
        {
            gpCacheHashTable[i].dwBlockIndex = (unsigned int)-1;
        }

        gpCacheBlockTable = (D2CacheBlockEntryStrc*)SMemAlloc(0x400 * sizeof(D2CacheBlockEntryStrc), ".\\CACHE.CPP", 0x229, 8);
        gpCacheHeader->dwBlockOffset = sizeof(D2CacheHeaderStrc) + 0x400 * sizeof(D2CacheHashEntryStrc);
        gpCacheHeader->dwFileSize = gpCacheHeader->dwFileSize > sizeof(D2CacheHeaderStrc) + 0x400 * (sizeof(D2CacheHashEntryStrc) + sizeof(D2CacheBlockEntryStrc)) ? gpCacheHeader->dwFileSize : sizeof(D2CacheHeaderStrc) + 0x400 * (sizeof(D2CacheHashEntryStrc) + sizeof(D2CacheBlockEntryStrc));
loaded:
        gbCacheLoaded = 1;
    }

    LeaveCriticalSection(&gtCacheLock);
    return 1;
}

#pragma intrinsic(memset)

// 0x005198C0
void __cdecl CACHE_ResetCache()
{
    char szPath[260];

    if (gbCacheLoaded)
    {
        CACHE_FreeCache();
        CACHE_DeleteCacheFile();
    }

    szPath[0] = 0;
    CACHE_GetCacheFilePath(szPath);
    DeleteFileA(szPath);
    CACHE_LoadCache();
}

static __forceinline int sub_00519920_ReadEntry(const char* szName,D2FileTimeStrc* time,void** data,unsigned int* size,unsigned int block,int* pArchiveError,int* pFileError) {
 D2CacheRecordStrc header;
 unsigned long count; D2FileTimeStrc* tCreated;
 memset(&header,0,sizeof(header));
 if(gpCacheBlockTable[block].dwFlags&0xC0000000) {
 SetFilePointer(ghCacheFile,gpCacheBlockTable[block].dwOffset,0,0);
 ReadFile(ghCacheFile,&header,4,&count,0);
 if(count!=4){*pArchiveError=2;return 0;}
 if(header.dwSize!=sizeof(header)){*pArchiveError=3;return 0;}
 ReadFile(ghCacheFile,(char*)&header+4,sizeof(header)-4,&count,0);
 if(count!=sizeof(header)-4){*pArchiveError=4;return 0;}
 unsigned int stored=header.dwCrc;header.dwCrc=0;
 unsigned int crc=sub_00518DE0_Crc32(&header,sizeof(header));
 if(stored!=crc){*pFileError=1;return 0;}header.dwCrc=stored;
 }
 if(_stricmp(szName,header.szName)){*pFileError=2;return 0;}
 tCreated=(D2FileTimeStrc*)sub_00518F30_GetCacheFileTime(0);
 if(CompareFileTime(tCreated,&header.tExpiry)>0){*pFileError=3;return 0;}
 if(gpCacheBlockTable[block].dwDataSize>0x1000000){*pArchiveError=5;return 0;}
 if(time)*time=header.tFileTime;
 header.tLastAccess=*(D2FileTimeStrc*)sub_00518F30_GetCacheFileTime(0);
 SetFilePointer(ghCacheFile,gpCacheBlockTable[block].dwOffset,0,0);
 header.dwCrc=0;
 header.dwCrc=sub_00518DE0_Crc32(&header,sizeof(header));
 {unsigned int writeSize=header.dwSize;if(writeSize>sizeof(header))writeSize=sizeof(header);
 unsigned long written;
 WriteFile(ghCacheFile,&header,writeSize,&written,0);
 if(written!=writeSize){*pArchiveError=6;return 0;}}
 *data=sub_00413020_Alloc(gpCacheBlockTable[block].dwDataSize,gszCacheFile,0x2B5,0);
 SetFilePointer(ghCacheFile,gpCacheBlockTable[block].dwOffset+header.dwSize,0,0);
 ReadFile(ghCacheFile,*data,gpCacheBlockTable[block].dwDataSize,(unsigned long*)size,0);
 if(*size!=gpCacheBlockTable[block].dwDataSize){*pArchiveError=7;return 0;}
 if(header.dwDataCrc!=sub_00518DE0_Crc32(*data,*size)){*pFileError=4;return 0;}
 return 1;
}

// 0x00519920
int __fastcall CACHE_LoadCachedFile(const char* szName,D2FileTimeStrc* time,void** data,unsigned int* size) {
 if(time){memset(time,0,sizeof(*time));} if(data)*data=0;if(size)*size=0;
 if(!szName||!*szName||!data||!size||!gbCacheLoaded)return 0;
 int archiveError=0,fileError=0;
 EnterCriticalSection(&gtCacheLock);
 int index=CACHE_FindHashEntry(szName,0);
 if(index==-1){LeaveCriticalSection(&gtCacheLock);return 0;}
 unsigned int block=gpCacheHashTable[index].dwBlockIndex;
 if(block>=gpCacheHeader->nBlockTableSize) archiveError=1;
 else if(sub_00519920_ReadEntry(szName,time,data,size,block,&archiveError,&fileError)) goto unlock;
 if(archiveError){BNDOWNLOAD_LogPrintf(gszCorruptCache,archiveError);CACHE_ResetCache();}
 else {BNDOWNLOAD_LogPrintf(gszCorruptFile,szName,fileError);sub_005191D0_DeleteHashEntries(szName);}
 if(*data){SMemFree(*data,gszCacheFile,0x2DE,0);*data=0;}*size=0;
unlock: LeaveCriticalSection(&gtCacheLock);return !fileError&&!archiveError;
}

// 0x00519DB0
int __fastcall CACHE_WriteCachedFile(const char* szName, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, unsigned int nSeconds1, unsigned int nSeconds2)
{
    D2CacheRecordStrc tRecord;
    D2CacheRecordStrc tOld;

    if (!szName || !*szName || !pData || !nSize || !pFileTime || !nSeconds2 || !gbCacheLoaded || nSize > 0x1000000)
    {
        return 0;
    }

    int nError = 0;
    EnterCriticalSection(&gtCacheLock);
    sub_005191D0_DeleteHashEntries(szName);

    const unsigned int nNeeded = nSize + 0x144;
    unsigned int nBlock = 0;
    while (nBlock < gpCacheHeader->nBlockTableSize)
    {
        if (!gpCacheBlockTable[nBlock].dwFlags && gpCacheBlockTable[nBlock].dwSize >= nNeeded)
        {
            break;
        }
        ++nBlock;
    }

    if (nBlock >= gpCacheHeader->nBlockTableSize)
    {
        for (nBlock = 0; nBlock < gpCacheHeader->nBlockTableSize; ++nBlock)
        {
            if (gpCacheBlockTable[nBlock].dwSize < nNeeded)
            {
                continue;
            }

            unsigned long nCount;
            SetFilePointer(ghCacheFile, gpCacheBlockTable[nBlock].dwOffset, 0, 0);
            memset(&tOld, 0, sizeof(tOld));
            ReadFile(ghCacheFile, &tOld, 4, &nCount, 0);
            if (nCount != 4 || tOld.dwSize != 0x144)
            {
                break;
            }

            ReadFile(ghCacheFile, &tOld.unk0x04, 0x140, &nCount, 0);
            if (nCount != 0x140)
            {
                break;
            }

            if (CompareFileTime(sub_00518F30_GetCacheFileTime(0), &tOld.tStale) > 0)
            {
                break;
            }
        }
    }

    D2CacheHeaderStrc* pHeader = gpCacheHeader;
    if (nBlock < pHeader->nBlockTableSize)
    {
        for (unsigned int i = 0; i < pHeader->nHashTableSize; ++i)
        {
            if (gpCacheHashTable[i].dwBlockIndex == nBlock)
            {
                gpCacheHashTable[i].dwBlockIndex = (unsigned int)-2;
            }
        }
    }
    else
    {
        if (nBlock >= 0x400)
        {
            nError = 0xB;
            goto Fail;
        }

        gpCacheBlockTable[nBlock].dwOffset = pHeader->dwFileSize;
        gpCacheBlockTable[nBlock].dwSize = nNeeded;
        pHeader->dwFileSize += nNeeded;
        pHeader->nBlockTableSize = nBlock + 1;
    }

    {
        const unsigned int dwIndex = sub_00518FA0_HashString(0, szName);
        const unsigned int dwNameA = sub_00518FA0_HashString(1, szName);
        const unsigned int dwNameB = sub_00518FA0_HashString(2, szName);
        unsigned int nSlot = dwIndex & (gpCacheHeader->nHashTableSize - 1);
        const unsigned int nStart = nSlot;
        D2CacheHashEntryStrc* pTable = gpCacheHashTable;
        unsigned int dwEntryBlock = pTable[nSlot].dwBlockIndex;
        while (dwEntryBlock != (unsigned int)-1 && dwEntryBlock != (unsigned int)-2)
        {
            nSlot = (nSlot + 1) & (gpCacheHeader->nHashTableSize - 1);
            if (nSlot == nStart)
            {
                break;
            }
            dwEntryBlock = pTable[nSlot].dwBlockIndex;
        }

        D2CacheHashEntryStrc* pEntry = &pTable[nSlot];
        if (pEntry->dwBlockIndex != (unsigned int)-1 && pEntry->dwBlockIndex != (unsigned int)-2)
        {
            nError = 0xC;
            goto Fail;
        }

        pEntry->dwNameA = dwNameA;
        pEntry->dwNameB = dwNameB;
        pEntry->dwBlockIndex = nBlock;
        pEntry->dwLocale = 0;
    }

    {
    unsigned long nCount;
    gpCacheBlockTable[nBlock].dwDataSize = nSize;
    gpCacheBlockTable[nBlock].dwFlags = 0xC0000000;

    memset(&tRecord, 0, sizeof(tRecord));
    tRecord.dwSize = 0x144;

    const D2FileTimeStrc* pTime1 = sub_00518F30_GetCacheFileTime(0);
    tRecord.tCreated.dwLowDateTime = pTime1->dwLowDateTime;
    tRecord.tCreated.dwHighDateTime = pTime1->dwHighDateTime;
    tRecord.tFileTime.dwLowDateTime = pFileTime->dwLowDateTime;
    tRecord.tFileTime.dwHighDateTime = pFileTime->dwHighDateTime;
    const D2FileTimeStrc* pTime2 = sub_00518F30_GetCacheFileTime(nSeconds1);
    tRecord.tStale.dwLowDateTime = pTime2->dwLowDateTime;
    tRecord.tStale.dwHighDateTime = pTime2->dwHighDateTime;
    const D2FileTimeStrc* pTime3 = sub_00518F30_GetCacheFileTime(nSeconds2);
    tRecord.tExpiry.dwLowDateTime = pTime3->dwLowDateTime;
    tRecord.tExpiry.dwHighDateTime = pTime3->dwHighDateTime;
    const D2FileTimeStrc* pTime4 = sub_00518F30_GetCacheFileTime(0);
    tRecord.tLastAccess.dwLowDateTime = pTime4->dwLowDateTime;
    tRecord.tLastAccess.dwHighDateTime = pTime4->dwHighDateTime;
    strcpy(tRecord.szName, szName);
    tRecord.dwDataCrc = sub_00518DE0_Crc32(pData, nSize);
    {
        unsigned int nLeft = sizeof(tRecord);
        const unsigned char* pBytes = (const unsigned char*)&tRecord;
        unsigned int dwCrc;
        CACHE_CRC32(dwCrc, pBytes, nLeft);
        tRecord.dwCrc = dwCrc;
    }

    SetFilePointer(ghCacheFile, gpCacheBlockTable[nBlock].dwOffset, 0, 0);
    WriteFile(ghCacheFile, &tRecord, sizeof(tRecord), &nCount, 0);
    if (nCount != sizeof(tRecord))
    {
        nError = 0xD;
        goto Fail;
    }

    WriteFile(ghCacheFile, pData, nSize, &nCount, 0);
    if (nCount != nSize)
    {
        nError = 0xE;
        goto Fail;
    }

    {
        unsigned int nHashCount = gpCacheHeader->nHashTableSize;
        if (nHashCount < 0x400)
        {
            nHashCount = 0x400;
        }
        const unsigned int nHashBytes = nHashCount << 4;
        unsigned int nBlockCount = gpCacheHeader->nBlockTableSize;
        if (nBlockCount < 0x400)
        {
            nBlockCount = 0x400;
        }
        const unsigned int nBlockBytes = nBlockCount << 4;

        unsigned int* pBuffer = (unsigned int*)SMemAlloc(nHashBytes > nBlockBytes ? nHashBytes : nBlockBytes, ".\\CACHE.CPP", 0x391, 0);
        SetFilePointer(ghCacheFile, gpCacheHeader->dwHashOffset, 0, 0);
        memcpy(pBuffer, gpCacheHashTable, nHashBytes);
        sub_00518EC0_EncryptBlock(pBuffer, nHashBytes, sub_00518FA0_HashString(3, "(hash table)"));
        gpCacheHeader->dwHashCrc = sub_00518DE0_Crc32(pBuffer, nHashBytes);
        WriteFile(ghCacheFile, pBuffer, nHashBytes, &nCount, 0);
        if (nCount != nHashBytes)
        {
            SMemFree(pBuffer, ".\\CACHE.CPP", 0x39D, 0);
            nError = 0xF;
            goto Fail;
        }

        SetFilePointer(ghCacheFile, gpCacheHeader->dwBlockOffset, 0, 0);
        memcpy(pBuffer, gpCacheBlockTable, nBlockBytes);
        sub_00518EC0_EncryptBlock(pBuffer, nBlockBytes, sub_00518FA0_HashString(3, "(block table)"));
        gpCacheHeader->dwBlockCrc = sub_00518DE0_Crc32(pBuffer, nBlockBytes);
        WriteFile(ghCacheFile, pBuffer, nBlockBytes, &nCount, 0);
        SMemFree(pBuffer, ".\\CACHE.CPP", 0x3AB, 0);
        if (nCount != nBlockBytes)
        {
            nError = 0x10;
            goto Fail;
        }
    }

    {
        D2CacheHeaderStrc* pCacheHeader = gpCacheHeader;
        pCacheHeader->dwHeaderCrc = 0;
        unsigned int nLeft = sizeof(D2CacheHeaderStrc);
        const unsigned char* pBytes = (const unsigned char*)pCacheHeader;
        unsigned int dwCrc;
        CACHE_CRC32(dwCrc, pBytes, nLeft);
        pCacheHeader->dwHeaderCrc = dwCrc;
    }

    SetFilePointer(ghCacheFile, 0, 0, 0);
    WriteFile(ghCacheFile, gpCacheHeader, sizeof(D2CacheHeaderStrc), &nCount, 0);
    if (nCount != sizeof(D2CacheHeaderStrc))
    {
        nError = 0x11;
        goto Fail;
    }
    }
    goto Done;

Fail:
    BNDOWNLOAD_LogPrintf("bncache.dat is corrupt (%d) - rebuilding archive", nError);
    CACHE_ResetCache();

Done:
    LeaveCriticalSection(&gtCacheLock);
    return nError == 0;
}

#include "gen/data/Source/D2BNClient/CACHE.inc"
