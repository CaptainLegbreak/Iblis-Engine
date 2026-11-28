#include "D2CMP.h"
#include "D2CmpTypes.h"
#include "D2CelDataHash.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

// 0x0060AEB0
void __fastcall CelDataHashFreeEntry(D2CelDataHashStrc* pHash, D2CelDataHashEntryStrc* pEntry, D2PoolSystemStrc* pMemPool)
{
    if (pHash->pBuckets[pEntry->nKey] == pEntry)
        pHash->pBuckets[pEntry->nKey] = pEntry->pNext;
    FOG_FreePool(pMemPool, pEntry, ".\\SRC\\CelDataHash.cpp", 0x3A, 0);
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

// 0x0060AEE0
void __fastcall CelDataHashInit(D2CelDataHashStrc* pHash)
{
    memset(pHash, 0, sizeof(D2CelDataHashStrc));
}

// 0x0060AF90
D2CelDataHashEntryStrc* __fastcall CelDataHashFind(D2CelDataHashStrc* pHash, const char* szName)
{
    if (!*szName)
        return 0;

    unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nKey = ((((((nHash >> 8) ^ nHash) >> 8) ^ nHash) >> 8) ^ nHash) & 0x1FF;
    for (D2CelDataHashEntryStrc* pEntry = pHash->pBuckets[nKey]; pEntry; pEntry = pEntry->pNext)
    {
        if (!strcmp(szName, pEntry->szName))
            return pEntry;
    }
    return 0;
}

// 0x0060AF00
void __fastcall CelDataHashFreeAll(D2PoolSystemStrc* pMemPool, D2CelDataHashStrc* pHash)
{
    for (unsigned int i = 0; i < 0x200; i++)
    {
        D2CelDataHashEntryStrc* pEntry = pHash->pBuckets[i];
        while (pEntry)
        {
            D2CelDataHashEntryStrc* pNext = pEntry->pNext;
            CelDataHashFreeEntry(pHash, pEntry, pMemPool);
            pEntry = pNext;
        }
        D2_ASSERT(!pHash->nCheck[i], 0x5B);
    }
}

// 0x0060B010
D2CelDataHashEntryStrc* __fastcall CelDataHashAdd(D2PoolSystemStrc* pMemPool, D2CelDataHashStrc* pHash, int nValue, const char* szName)
{
    D2CelDataHashEntryStrc* pEntry = (D2CelDataHashEntryStrc*)FOG_AllocPool(pMemPool, sizeof(D2CelDataHashEntryStrc), ".\\SRC\\CelDataHash.cpp", 0x88, 0);
    pEntry->nValue = nValue;
    unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nKey = ((nHash ^ (nHash >> 8)) ^ ((nHash ^ (nHash >> 8)) >> 16)) & 0x1FF;
    pEntry->pPrev = 0;
    pEntry->pNext = pHash->pBuckets[nKey];
    if (pEntry->pNext)
        pEntry->pNext->pPrev = pEntry;
    pEntry->nKey = nKey;
    strcpy(pEntry->szName, szName);
    pHash->pBuckets[nKey] = pEntry;
    return pEntry;
}

// 0x0060B0B0
void __fastcall CelDataHashRemove(D2PoolSystemStrc* pMemPool, D2CelDataHashStrc* pHash, D2CelDataHashEntryStrc* pEntry)
{
    D2_ASSERT(pEntry, 0xB2);
    if (pEntry->pPrev)
        pEntry->pPrev->pNext = pEntry->pNext;
    if (pEntry->pNext)
        pEntry->pNext->pPrev = pEntry->pPrev;
    if (pHash->pBuckets[pEntry->nKey] == pEntry)
        pHash->pBuckets[pEntry->nKey] = pEntry->pNext;
    FOG_FreePool(pMemPool, pEntry, ".\\SRC\\CelDataHash.cpp", 0x3A, 0);
}
