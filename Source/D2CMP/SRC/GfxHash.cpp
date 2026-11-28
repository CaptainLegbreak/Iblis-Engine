#include "D2CMP.h"
#include "D2SysTypes.h"
#include "D2CmpTypes.h"
#include "D2CmpTiles.h"
#include "D2CelDataHash.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct D2AsyncLoadStrc;

struct D2CmpGfxFrameStrc;

struct D2CmpGfxInfoStrc;

struct D2CmpGfxHashEntryStrc;

struct D2CmpGfxHashStrc;

struct D2CmpGfxKeyStrc;

struct D2CmpGfxCelStrc;


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char szGfxHashFile[]; // 0x006E5F44

typedef void(__fastcall* PixelDataFreeCallback)(void* pData);

void* __fastcall FOG_AsyncDataGetBuffer(D2AsyncLoadStrc* pAsync); // 0x0040A9E0

void __fastcall FOG_AsyncDataFree(D2AsyncLoadStrc* pAsync); // 0x0040AB00

void __fastcall FOG_FreeServerMemory(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

PixelDataFreeCallback __fastcall CelGetHardwareFreeCallback(struct D2CmpGfxHashStrc* pHash); // 0x00601A40

struct D2CmpGfxFrameStrc
{
    char unk0x00[0x14];
    int nSizeA;
    void* pPixelData;
    int nSizeB;
};

struct D2CmpGfxInfoStrc
{
    char unk0x00[0x21];
    unsigned char nCountB;
    char unk0x22[0x02];
    unsigned char nCountA;
    char unk0x25[0x03];
    int bHardware;
    char unk0x2C[0xB0 - 0x2C];
    D2AsyncLoadStrc* pAsync;
};

struct D2CmpGfxKeyStrc
{
    int unk0x00;
    unsigned int dwFlags;
    int nType;
    int nSubA;
    int nMode;
    int nSubB;
    int nKey1;
    int nKey2;
    int nKey3;
    int nKey4;
    int nKey5;
    const char* szName;
    int unk0x30[4];
    int nDirection;
    unsigned int dwFlags44;
};

struct D2CmpGfxCelStrc
{
    unsigned int dwFlags;
    int unk0x04[4];
    unsigned int nDirections;
};

int __stdcall CelGameDirToFileDir(int nDirection, unsigned int nDirections); // 0x00600C90

struct D2FindTileEntryStrc;

struct D2CmpBlockTableBStrc;

struct D2CelDataHashEntryStrc;

struct D2CelDataHashStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);


extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend); // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

long gnTileLockRefCount; // 0x008F03E4

D2CriticalSectionStrc gtCodecLock; // 0x008F03CC

// 0x0060AB80
unsigned int __fastcall GfxHashGetDirectionKey(D2CmpGfxKeyStrc* pKey, unsigned int* pDivisor, D2CmpGfxCelStrc* pCel)
{
    unsigned int nValue = 0;
    *pDivisor = 0;
    switch (pKey->nType)
    {
    case 0:
        *pDivisor = 8;
        if (pKey->nMode == 0 || pKey->nMode == 0x11 || (pKey->dwFlags44 & 2))
        {
            *pDivisor = 1;
        }
        if (!(pCel->dwFlags & 1))
        {
            nValue = CelGameDirToFileDir(pKey->nDirection, pCel->nDirections);
        }
        break;

    case 1:
        if (!(pCel->dwFlags & 1))
        {
            *pDivisor = pCel->nDirections == 8 ? 4 : 1;
            nValue = CelGameDirToFileDir(pKey->nDirection, pCel->nDirections);
        }
        break;

    default:
        *pDivisor = 1;
        if (pKey->nType == 2)
        {
            nValue = 0;
        }
        else if ((pKey->nType == 6 && (pKey->dwFlags & 2)) || pKey->nType == 4 || pKey->nType == 3)
        {
            if (pKey->nType == 4)
            {
                nValue = pKey->nDirection;
            }
            else if (!(pCel->dwFlags & 1))
            {
                nValue = CelGameDirToFileDir(pKey->nDirection, pCel->nDirections);
            }
        }
        break;
    }

    if (!*pDivisor)
    {
        return 0;
    }

    return nValue / *pDivisor;
}

// 0x0060AC60
static unsigned int GfxHashGetIndex(D2CmpGfxKeyStrc* pKey, int* pAux, void* pCel, unsigned int* pValue)
{
    const unsigned int nValue = GfxHashGetDirectionKey(pKey, (unsigned int*)pAux, (D2CmpGfxCelStrc*)pCel);
    *pValue = nValue;
    unsigned int nHash;
    if ((pKey->nType == 6 && (pKey->dwFlags & 2)) || pKey->nType == 3 || pKey->nType == 4)
    {
        D2_ASSERT(pKey->szName, 0x2C);
        nHash = SStrHash(pKey->szName, 1, 0) + *pValue;
    }
    else
    {
        nHash = pKey->nKey5 + pKey->nKey4 + pKey->nKey3 + pKey->nKey2 + pKey->nKey1 + nValue;
    }
    const unsigned int nShift = nHash >> 8;
    return ((nShift ^ nHash) >> 16 ^ nShift ^ nHash) & 0x1FFF;
}

void __stdcall sub_0054FB30_Nop()
{
}

// 0x0060ACE0
D2CmpGfxHashEntryStrc* __fastcall GfxHashFind(D2CmpGfxHashStrc* pHash, D2CmpGfxKeyStrc* pKey, unsigned int* pValue, int* pAux, void* pCel)
{
    const unsigned int nIndex = GfxHashGetIndex(pKey, pAux, pCel, pValue);
    const int nKey1 = pKey->nKey1;
    const int nKey2 = pKey->nKey2;
    const int nKey3 = pKey->nKey3;
    for (D2CmpGfxHashEntryStrc* pEntry = pHash->pBuckets[nIndex]; pEntry; pEntry = pEntry->pNext)
    {
        if (pKey->nType == 6 && (pKey->dwFlags & 2))
        {
            if (nKey1 == pEntry->nKey1 && nKey2 == pEntry->nKey2 && nKey3 == pEntry->nKey3 && pKey->nKey4 == pEntry->nKey4 && pKey->nKey5 == pEntry->nKey5
                && pKey->nSubB == pEntry->nSub && *pValue == pEntry->nValue)
            {
                return pEntry;
            }
        }
        else if (pKey->nType == 4 || pKey->nType == 3)
        {
            if (nKey1 == pEntry->nKey1 && nKey2 == pEntry->nKey2 && nKey3 == pEntry->nKey3 && pKey->nKey4 == pEntry->nKey4 && pKey->nKey5 == pEntry->nKey5
                && pKey->nSubA == pEntry->nSub && *pValue == pEntry->nValue)
            {
                return pEntry;
            }
        }
        else
        {
            if (nKey1 == pEntry->nKey1 && nKey2 == pEntry->nKey2 && nKey3 == pEntry->nKey3 && pKey->nKey4 == pEntry->nKey4 && pKey->nKey5 == pEntry->nKey5
                && *pValue == pEntry->nValue)
            {
                return pEntry;
            }
        }
    }
    return 0;
}

// 0x0060ADC0
D2CmpGfxHashEntryStrc* __fastcall GfxHashAdd(D2PoolSystemStrc* pMemPool, D2CmpGfxHashStrc* pHash, int nArg, D2CmpGfxKeyStrc* pKey, void* pCel)
{
    D2CmpGfxHashEntryStrc* pEntry = (D2CmpGfxHashEntryStrc*)FOG_AllocPool(pMemPool, sizeof(D2CmpGfxHashEntryStrc), ".\\SRC\\GfxHash.cpp", 0xEF, 0);
    pEntry->nArg = nArg;
    nArg = 0;
    const unsigned int nIndex = GfxHashGetIndex(pKey, &nArg, pCel, &pEntry->nValue);
    pEntry->nKey1 = pKey->nKey1;
    pEntry->nKey2 = pKey->nKey2;
    pEntry->nKey3 = pKey->nKey3;
    pEntry->nKey4 = pKey->nKey4;
    pEntry->nKey5 = pKey->nKey5;
    if (pKey->nType == 6 && (pKey->dwFlags & 2))
    {
        pEntry->nSub = pKey->nSubB;
    }
    else if (pKey->nType == 4 || pKey->nType == 3)
    {
        pEntry->nSub = pKey->nSubA;
    }
    pEntry->pPrev = 0;
    pEntry->pNext = pHash->pBuckets[nIndex];
    if (pEntry->pNext)
    {
        pEntry->pNext->pPrev = pEntry;
    }
    pEntry->nIndex = nIndex;
    pHash->pBuckets[nIndex] = pEntry;
    return pEntry;
}

// 0x0060CD30
void __cdecl CodecInitLock()
{
    if (InterlockedIncrement(&gnTileLockRefCount) == 1)
        InitializeCriticalSection(&gtCodecLock);
}

// 0x0060CD50
void __cdecl CodecReleaseLock()
{
    if (InterlockedDecrement(&gnTileLockRefCount) == 0)
        DeleteCriticalSection(&gtCodecLock);
}

// 0x0060A9D0
void __fastcall GfxHashFreeEntry(D2CmpGfxHashStrc* pHash, int nUnused, D2PoolSystemStrc* pMemPool, D2CmpGfxHashEntryStrc* pEntry)
{
    void* pBlocks = 0;
    D2CmpGfxHashEntryStrc* pEntryCopy = pEntry;
    D2CmpGfxHashEntryStrc** ppBucket = &*(pEntryCopy->nIndex + pHash->pBuckets);
    if (*ppBucket == pEntry)
    {
        *ppBucket = pEntry->pNext;
    }

    D2CmpGfxInfoStrc* pInfo = pEntry->pInfo;
    D2AsyncLoadStrc* pAsync = pInfo->pAsync;
    if (pAsync)
    {
        if (pInfo->bHardware)
        {
            PixelDataFreeCallback pfnFree = CelGetHardwareFreeCallback(pHash);
            char* pData = (char*)FOG_AsyncDataGetBuffer(pAsync);
            D2_ASSERT(pData, 0x5F);
            unsigned int nOffset = 0;
            pBlocks = ((D2CmpGfxFrameStrc*)pData)->pPixelData;
            for (unsigned int i = 0; i < pInfo->nCountA * (int)pInfo->nCountB;)
            {
                D2CmpGfxFrameStrc* pFrame = (D2CmpGfxFrameStrc*)(nOffset + pData);
                void* const tPPixelData = pFrame->pPixelData;
                if (tPPixelData)
                {
                    if (pfnFree)
                    {
                        pfnFree(tPPixelData);
                    }
                    pFrame->pPixelData = 0;
                }
                nOffset = nOffset + (pFrame->nSizeB + pFrame->nSizeA + 0x23);
                ++i;
            }

            if (pBlocks)
            {
                FOG_FreeServerMemory(pMemPool, pBlocks, szGfxHashFile, 0x82, 0);
            }
        }

        FOG_AsyncDataFree(pAsync);
        pInfo->pAsync = 0;
    }

    FOG_FreeServerMemory(pMemPool, pEntry, szGfxHashFile, 0x8E, 0);
}

// 0x0060AAF0
void __fastcall GfxHashInit(D2CmpBlockTableBStrc* pTable)
{
    memset(pTable, 0, sizeof(D2CmpBlockTableBStrc));
}

// 0x0060AB70
void __stdcall GfxHashDumpStats()
{
}

// 0x0060AC50
void __stdcall sub_0060AC50_Nop()
{
}

