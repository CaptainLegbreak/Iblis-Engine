#include "D2Glide.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern int gdwGlobal_0087EFB8; // 0x0087EFB8

static D2GlideTileCacheEntryStrc* sub_M117_TilePopHead(D2GlideTileCacheStrc* pCache);

// 0x0050ED90
int __fastcall GLSUBTILECACHE_TileCacheInit(D2GlideTileCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nBlockSize)
{
    const int nCount = (nEnd - nStart) / nBlockSize;
    pCache->nBlockSize = nBlockSize;
    pCache->nCount = nCount;
    pCache->pEntries = (D2GlideTileCacheEntryStrc*)FOG_Alloc(nCount * sizeof(D2GlideTileCacheEntryStrc), ".\\Src\\glSubtileCache.cpp", 0x29, 0);
    D2_ASSERT(pCache->pEntries, 0x2A);
    memset(pCache->pEntries, 0, nCount * sizeof(D2GlideTileCacheEntryStrc));

    for (int i = 0; i <= pCache->nCount - 1; ++i)
    {
        D2GlideTileCacheEntryStrc* pEntry = &pCache->pEntries[i];
        pEntry->nId = i;
        if (i < pCache->nCount - 1)
        {
            pEntry->pNext = &pCache->pEntries[i + 1];
        }
        if (i > 0)
        {
            pEntry->pPrev = &pCache->pEntries[i - 1];
        }
        pEntry->nAddress = nStart + i * nBlockSize;
    }

    pCache->nUsed = 0;
    pCache->pHead = 0;
    pCache->pTail = 0;
    pCache->pFreeHead = pCache->pEntries;
    pCache->pFreeTail = &pCache->pEntries[pCache->nCount - 1];

    if (!gdwGlobal_0087EFB8)
    {
        for (int i = 1; i < pCache->nCount - 1; ++i)
        {
            const unsigned int nEntryAddress = pCache->pEntries[i].nAddress;
            if (nEntryAddress < 0x200000 && pCache->nBlockSize + nEntryAddress > 0x200000)
            {
                pCache->pEntries[i - 1].pNext = &pCache->pEntries[i + 1];
                pCache->pEntries[i + 1].pPrev = &pCache->pEntries[i - 1];
                pCache->pEntries[i].pPrev = 0;
                pCache->pEntries[i].pNext = 0;
                ++pCache->nUsed;
                break;
            }
        }

        if (pCache->pEntries[pCache->nCount - 1].nAddress < 0x200000 && pCache->nBlockSize + pCache->pEntries[pCache->nCount - 1].nAddress > 0x200000)
        {
            pCache->pEntries[pCache->nCount - 1].pPrev = 0;
            pCache->pEntries[pCache->nCount - 2].pNext = 0;
            pCache->pFreeTail = &pCache->pEntries[pCache->nCount - 2];
            --pCache->nCount;
        }
    }

    return pCache->nCount * nBlockSize + nStart;
}

// Kept noinline: a static whose callers here pass its arguments in registers (the #368 case).
// 0x0050EF40
static __declspec(noinline) void GLSUBTILECACHE_TileCacheAppendUsed(D2GlideTileCacheStrc* pCache, D2GlideTileCacheEntryStrc* pEntry)
{
    if (!pCache->pHead)
    {
        pCache->pHead = pEntry;
        pCache->pTail = pEntry;
        return;
    }

    pCache->pTail->pNext = pEntry;
    pEntry->pPrev = pCache->pTail;
    pCache->pTail = pEntry;
}

static D2GlideTileCacheEntryStrc* sub_0050EF80_TileCachePopUsed(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
    {
        return 0;
    }

    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
    {
        pCache->pHead->pPrev = 0;
    }
    else
    {
        pCache->pTail = 0;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050EF80
static D2GlideTileCacheEntryStrc* sub_M117_TilePopHead(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

static void GLFLOORCACHE_TileCacheEvict(D2GlideTileCacheStrc* pCache); // 0x0050F150

static void GLSUBTILECACHE_FloorCacheAppendFree(D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry); // 0x0050F4F0

static D2GlideFloorCacheEntryStrc* GLSUBTILECACHE_FloorCachePopFree(D2GlideFloorCacheStrc* pCache); // 0x0050F540

D2GlideFloorCacheEntryStrc* __fastcall sub_M117_Emit_0050F150(D2GlideTileCacheStrc* pTileCache, D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
{
    GLFLOORCACHE_TileCacheEvict(pTileCache);
    GLSUBTILECACHE_FloorCacheAppendFree(pCache, pEntry);
    return GLSUBTILECACHE_FloorCachePopFree(pCache);
}

// 0x0050EFE0
static D2GlideTileCacheEntryStrc* GLSUBTILECACHE_TileCacheUnlink(int nIndex, D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pNode = pCache->pHead;
    if (!pNode)
    {
        return 0;
    }

    D2_ASSERT(pCache->pEntries, 0x17D);
    D2GlideTileCacheEntryStrc* pEntry = &pCache->pEntries[nIndex];
    if (pEntry == pNode)
    {
        return sub_0050EF80_TileCachePopUsed(pCache);
    }

    pNode = pCache->pTail;
    if (pEntry == pNode)
    {
        pNode = pNode->pPrev;
        pCache->pTail = pNode;
        pNode->pNext = 0;
    }
    else
    {
        pNode = pEntry->pPrev;
        pNode->pNext = pEntry->pNext;
        pNode = pEntry->pNext;
        pNode->pPrev = pEntry->pPrev;
    }
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

static D2GlideTileCacheEntryStrc* sub_N19_TilePopHead(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pHead;
    if (!pEntry)
        return 0;
    pCache->pHead = pEntry->pNext;
    if (pCache->pHead)
        pCache->pHead->pPrev = 0;
    else
        pCache->pTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

static void sub_N19_TileEvict(D2GlideTileCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTileCacheEntryStrc* pEntry = sub_N19_TilePopHead(pCache);
    if (pEntry)
    {
        D2GlideTileStrc* pTile = pEntry->pTile;
        if (pTile)
        {
            pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F070
static int GLSUBTILECACHE_TileCacheAlloc(D2GlideTileCacheStrc* pCache)
{
    if (pCache->nUsed == pCache->nCount)
        return 0;

    D2GlideTileCacheEntryStrc* pEntry = pCache->pFreeHead;
    if (pEntry)
    {
        pCache->pFreeHead = pEntry->pNext;
        if (pCache->pFreeHead)
            pCache->pFreeHead->pPrev = 0;
        else
            pCache->pFreeTail = 0;
        pEntry->pNext = 0;
        pEntry->pPrev = 0;
    }
    D2_ASSERT(pEntry, 0x9D);

    if (!pCache->pHead)
    {
        ++pCache->nUsed;
        pCache->pHead = pEntry;
        pCache->pTail = pEntry;
        return pEntry->nId + 1;
    }

    pCache->pTail->pNext = pEntry;
    pEntry->pPrev = pCache->pTail;
    ++pCache->nUsed;
    pCache->pTail = pEntry;
    return pEntry->nId + 1;
}

// 0x0050F0F0
void __fastcall GLSUBTILECACHE_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex)
{
    if (pCache->nUsed <= 1)
    {
        return;
    }

    D2_ASSERT(nIndex, 0xBA);
    D2_ASSERT(nIndex <= pCache->nCount, 0xBB);
    D2_ASSERT(nIndex >= 1, 0xBC);
    GLSUBTILECACHE_TileCacheAppendUsed(pCache, GLSUBTILECACHE_TileCacheUnlink(nIndex - 1, pCache));
}

// 0x0050F150
static void GLFLOORCACHE_TileCacheEvict(D2GlideTileCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTileCacheEntryStrc* pEntry = sub_M117_TilePopHead(pCache);
    if (pEntry)
    {
        D2GlideTileStrc* pTile = pEntry->pTile;
        if (pTile)
        {
            pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }
        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F1B0
void __fastcall GLSUBTILECACHE_TileCacheRelease(D2GlideTileCacheStrc* pCache, int nIndex)
{
    if (!pCache->nUsed)
    {
        return;
    }

    D2GlideTileCacheEntryStrc* pEntry = GLSUBTILECACHE_TileCacheUnlink(nIndex, pCache);
    if (pEntry)
    {
        if (pEntry->pTile)
        {
            pEntry->pTile->nCacheIndex = 0;
            pEntry->pTile = 0;
        }

        if (!pCache->pFreeHead)
        {
            pCache->pFreeHead = pEntry;
            pCache->pFreeTail = pEntry;
        }
        else
        {
            pCache->pFreeTail->pNext = pEntry;
            pEntry->pPrev = pCache->pFreeTail;
            pCache->pFreeTail = pEntry;
        }
    }
    --pCache->nUsed;
}

// 0x0050F2B0
short __fastcall GLSUBTILECACHE_TileCacheAdd(D2GlideTileCacheStrc* pCache)
{
    int nId;
    while (!(nId = GLSUBTILECACHE_TileCacheAlloc(pCache)))
        sub_N19_TileEvict(pCache);
    return nId;
}

// 0x0050F4F0
static void GLSUBTILECACHE_FloorCacheAppendFree(D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
{
    if (!pCache->pFreeHead)
    {
        pCache->pFreeHead = pEntry;
        pCache->pFreeTail = pEntry;
        return;
    }

    pCache->pFreeTail->pNext = pEntry;
    pEntry->pPrev = pCache->pFreeTail;
    pCache->pFreeTail = pEntry;
}

// 0x0050F540
static D2GlideFloorCacheEntryStrc* GLSUBTILECACHE_FloorCachePopFree(D2GlideFloorCacheStrc* pCache)
{
    D2GlideFloorCacheEntryStrc* pEntry = pCache->pFreeHead;
    if (!pEntry)
        return 0;
    pCache->pFreeHead = pEntry->pNext;
    if (pCache->pFreeHead)
        pCache->pFreeHead->pPrev = 0;
    else
        pCache->pFreeTail = 0;
    pEntry->pNext = 0;
    pEntry->pPrev = 0;
    return pEntry;
}

// 0x0050F210
void __fastcall GLSUBTILECACHE_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush)
{
    if (bFlush)
    {
        while (pCache->nUsed)
            sub_N19_TileEvict(pCache);
    }
    if (pCache->pEntries)
    {
        FOG_Free(pCache->pEntries, ".\\Src\\glSubtileCache.cpp", 0x74, 0);
        pCache->pEntries = 0;
    }
    memset(pCache, 0, sizeof(*pCache));
}
