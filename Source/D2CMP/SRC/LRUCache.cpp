#include "D2CMP.h"
#include "D2CmpCache.h"
#include "FogApi.h"

struct D2PoolSystemStrc;
struct D2LRUCacheStrc
{
    D2PoolSystemStrc* pMemPool;
    unsigned int nCostLimit;
    unsigned int nCostInUse;
    unsigned int nNodesInUse;
    D2LRUNodeStrc* pNodes;
    unsigned int nNodes;
    D2LRUNodeStrc* pUsedFirst;
    D2LRUNodeStrc* pUsedLast;
    D2LRUNodeStrc* pFreeFirst;
    D2LRUNodeStrc* pFreeLast;
    void (__fastcall* pfnRelease)(D2LRUNodeStrc*);
    unsigned int nHits;
    unsigned int nMisses;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall sub_0040B430(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

void __fastcall FOG_FreeServerMemory(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" const char gszLRUCacheSourceFile[];                                                              // 0x006E5F1C




extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define LRU_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

static __inline void __fastcall LRUCacheAppendUsed(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode);

static __inline void __fastcall LRUCacheAppendFree(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode);

static D2LRUNodeStrc* __fastcall LRUCachePopUsed(D2LRUCacheStrc* pCache);

static __inline D2LRUNodeStrc* __fastcall LRUCACHE_UnlinkUsedHead(D2LRUCacheStrc* pCache);

static __inline D2LRUNodeStrc* __fastcall LRUCachePopFree(D2LRUCacheStrc* pCache);

static D2LRUNodeStrc* __fastcall LRUCacheUnlinkUsed(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode);

static D2LRUNodeStrc* __fastcall LRUCacheTakeFreeNode(D2LRUCacheStrc* pCache, unsigned int nSize);

void __fastcall LRUCacheInit(D2LRUCacheStrc* pCache, D2PoolSystemStrc* pMemPool, unsigned int nMaxSize, void (__fastcall* pfnRelease)(D2LRUNodeStrc*), unsigned int nNodes);

// 0x00609020
void __fastcall LRUCacheInit(D2LRUCacheStrc* pCache, D2PoolSystemStrc* pMemPool, unsigned int nCostLimit, void (__fastcall* pfnRelease)(D2LRUNodeStrc*), unsigned int nNodes)
{
    pCache->pMemPool = pMemPool;
    pCache->nCostLimit = nCostLimit;
    pCache->nCostInUse = 0;
    pCache->pfnRelease = pfnRelease;
    pCache->nNodes = nNodes;

    unsigned int nSize = pCache->nNodes * sizeof(D2LRUNodeStrc);
    pCache->pNodes = (D2LRUNodeStrc*)FOG_AllocPool(pCache->pMemPool, nSize, ".\\SRC\\LRUCache.cpp", 48, 0);
    memset(pCache->pNodes, 0, nSize);

    for (unsigned int i = 0; i < pCache->nNodes; ++i)
    {
        D2LRUNodeStrc* pNode = &pCache->pNodes[i];
        if (i < pCache->nNodes - 1)
        {
            pNode->pNext = &pCache->pNodes[i + 1];
        }
        if (i > 0)
        {
            pNode->pPrev = &pCache->pNodes[i - 1];
        }
        pNode->pData = 0;
        pNode->nSize = 0;
        pNode->nCost = 0;
    }

    pCache->nNodesInUse = 0;
    pCache->pUsedFirst = 0;
    pCache->pUsedLast = 0;
    pCache->nHits = 0;
    pCache->nMisses = 0;
    pCache->pFreeFirst = pCache->pNodes;
    pCache->pFreeLast = &pCache->pNodes[pCache->nNodes - 1];
}

// 0x006090E0
static __inline void __fastcall LRUCacheAppendUsed(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->pUsedLast)
    {
        pCache->pUsedFirst = pNode;
        pCache->pUsedLast = pNode;
        return;
    }

    pCache->pUsedLast->pNext = pNode;
    pNode->pPrev = pCache->pUsedLast;
    pCache->pUsedLast = pNode;
}

// 0x00609100
static __inline void __fastcall LRUCacheAppendFree(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->pFreeLast)
    {
        pCache->pFreeFirst = pNode;
        pCache->pFreeLast = pNode;
        return;
    }

    pCache->pFreeLast->pNext = pNode;
    pNode->pPrev = pCache->pFreeLast;
    pCache->pFreeLast = pNode;
}

// 0x00609120
static D2LRUNodeStrc* __fastcall LRUCachePopUsed(D2LRUCacheStrc* pCache)
{
    D2LRUNodeStrc* pNode = pCache->pUsedFirst;
    if (!pNode)
    {
        return 0;
    }

    pCache->pUsedFirst = pNode->pNext;
    if (pCache->pUsedFirst)
    {
        pCache->pUsedFirst->pPrev = 0;
    }
    else
    {
        pCache->pUsedLast = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

static __inline D2LRUNodeStrc* __fastcall LRUCACHE_UnlinkUsedHead(D2LRUCacheStrc* pCache)
{
    D2LRUNodeStrc* pNode = pCache->pUsedFirst;
    if (!pNode)
    {
        return 0;
    }

    pCache->pUsedFirst = pNode->pNext;
    if (pCache->pUsedFirst)
    {
        pCache->pUsedFirst->pPrev = 0;
    }
    else
    {
        pCache->pUsedLast = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x00609150
static __inline D2LRUNodeStrc* __fastcall LRUCachePopFree(D2LRUCacheStrc* pCache)
{
    D2LRUNodeStrc* pNode = pCache->pFreeFirst;
    if (!pNode)
    {
        return 0;
    }

    pCache->pFreeFirst = pNode->pNext;
    if (pCache->pFreeFirst)
    {
        pCache->pFreeFirst->pPrev = 0;
    }
    else
    {
        pCache->pFreeLast = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x00609180
static D2LRUNodeStrc* __fastcall LRUCacheUnlinkUsed(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode)
{
    if (pCache->pUsedFirst)
    {
        LRU_ASSERT(pNode, 370);

        if (pNode == pCache->pUsedFirst)
        {
            return LRUCachePopUsed(pCache);
        }

        if (pNode == pCache->pUsedLast)
        {
            pCache->pUsedLast = pCache->pUsedLast->pPrev;
            pCache->pUsedLast->pNext = 0;
        }
        else
        {
            pNode->pPrev->pNext = pNode->pNext;
            pNode->pNext->pPrev = pNode->pPrev;
        }

        pNode->pNext = 0;
        pNode->pPrev = 0;
    }

    return pNode;
}

// 0x00609200
void __fastcall LRUCacheIterate(D2LRUCacheStrc* pCache, int (__fastcall* pfnCallback)(D2LRUNodeStrc*, void*), void* pUserData)
{
    LRU_ASSERT(pCache, 412);

    for (D2LRUNodeStrc* pNode = pCache->pUsedFirst; pNode; )
    {
        D2LRUNodeStrc* pNext = pNode->pNext;
        if (!pfnCallback(pNode, pUserData))
        {
            return;
        }

        pNode = pNext;
    }
}

// 0x00609250
static D2LRUNodeStrc* __fastcall LRUCacheTakeFreeNode(D2LRUCacheStrc* pCache, unsigned int nSize)
{
    if (pCache->nNodesInUse == pCache->nNodes)
    {
        return 0;
    }

    if (pCache->nCostInUse + nSize > pCache->nCostLimit)
    {
        return 0;
    }

    D2LRUNodeStrc* pNode = LRUCachePopFree(pCache);
    LRUCacheAppendUsed(pCache, pNode);
    LRU_ASSERT(pNode, 159);

    ++pCache->nNodesInUse;
    pCache->nCostInUse += nSize;
    return pNode;
}

// 0x006092D0
void __fastcall LRUCacheRelease(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->nNodesInUse)
    {
        return;
    }

    if (!pNode)
    {
        pNode = LRUCACHE_UnlinkUsedHead(pCache);
    }
    else
    {
        LRUCacheUnlinkUsed(pCache, pNode);
    }

    if (pNode)
    {
        pCache->nCostInUse -= pNode->nSize;
        if (pNode->nCost)
        {
            pCache->pfnRelease(pNode);
        }

        if (pNode->pData)
        {
            FOG_FreeServerMemory(pCache->pMemPool, pNode->pData, gszLRUCacheSourceFile, 200, 0);
            pNode->pData = 0;
            pNode->nSize = 0;
            pNode->nCost = 0;
        }

        LRUCacheAppendFree(pCache, pNode);
    }

    --pCache->nNodesInUse;
}

// 0x006093E0
void __fastcall LRUCacheDestroy(D2LRUCacheStrc* pCache)
{
    while (pCache->nNodesInUse)
    {
        LRUCacheRelease(pCache, 0);
    }

    if (pCache->pNodes)
    {
        FOG_FreeServerMemory(pCache->pMemPool, pCache->pNodes, gszLRUCacheSourceFile, 99, 0);
        pCache->pNodes = 0;
    }
}

// 0x00609420
D2LRUNodeStrc* __fastcall LRUCacheAlloc(D2LRUCacheStrc* pCache, unsigned int nSize, int nFlags)
{
    LRU_ASSERT(nSize < pCache->nCostLimit, 118);

    ++pCache->nHits;
    ++pCache->nMisses;

    D2LRUNodeStrc* pNode = LRUCacheTakeFreeNode(pCache, nSize);
    while (!pNode)
    {
        LRUCacheRelease(pCache, 0);
        pNode = LRUCacheTakeFreeNode(pCache, nSize);
    }

    pNode->pData = sub_0040B430(pCache->pMemPool, nSize, gszLRUCacheSourceFile, 132, 0);
    LRU_ASSERT(pNode->pData, 133);
    pNode->nSize = nSize;
    pNode->nCost = nFlags;
    return pNode;
}

// 0x00609380
void __fastcall LRUCacheTouch(D2LRUCacheStrc* pCache, D2LRUNodeStrc* pNode)
{
    if (!pCache->nNodesInUse)
    {
        return;
    }

    ++pCache->nMisses;
    LRU_ASSERT(pNode, 233);

    LRUCacheUnlinkUsed(pCache, pNode);
    LRUCacheAppendUsed(pCache, pNode);
}
