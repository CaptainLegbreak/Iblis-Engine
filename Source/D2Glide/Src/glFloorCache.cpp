#include "D2Glide.h"
#include "D2DrlgMaps.h"

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern int gdwGlobal_0087EFB8; // 0x0087EFB8

extern D2GlideTileCacheStrc gtGlideTileCache; // 0x0087EB48
extern D2GlideFloorCacheStrc gtGlideFloorCache; // 0x0087EB68
void __fastcall GLSUBTILECACHE_TileCacheRelease(D2GlideTileCacheStrc* pCache, int nIndex); // 0x0050F1B0
D2GlideFloorCacheEntryStrc* __fastcall GLSMACK_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F570
void __fastcall GLSMACK_FloorCacheRemove(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F750

void __fastcall GLSMACK_FloorCacheEvict(D2GlideFloorCacheStrc* pCache); // 0x0050F6D0

// 0x0050F320
int __fastcall GLFLOORCACHE_FloorCacheInit(D2GlideFloorCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nBlockSize)
{
    const int nCount = (nEnd - nStart) / nBlockSize;
    pCache->nBlockSize = nBlockSize;
    pCache->nCount = nCount;
    pCache->pEntries = (D2GlideFloorCacheEntryStrc*)FOG_Alloc(nCount * sizeof(D2GlideFloorCacheEntryStrc), ".\\Src\\glFloorCache.cpp", 0x29, 0);
    D2_ASSERT(pCache->pEntries, 0x2A);
    memset(pCache->pEntries, 0, nCount * sizeof(D2GlideFloorCacheEntryStrc));

    for (int i = 0; i <= pCache->nCount - 1; ++i)
    {
        D2GlideFloorCacheEntryStrc* pEntry = &pCache->pEntries[i];
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
// 0x0050F4D0
static __declspec(noinline) void GLFLOORCACHE_FloorCacheAppendUsed(D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
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

// 0x0050F510
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

// build: symbol ?GLSUBTILECACHE_FloorCacheAppendFree@* 0x0050F4F0
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

// build: symbol ?GLSUBTILECACHE_FloorCachePopFree@* 0x0050F540
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

D2GlideFloorCacheEntryStrc* __fastcall sub_M117_Emit_0050F150(D2GlideTileCacheStrc* pTileCache, D2GlideFloorCacheStrc* pCache, D2GlideFloorCacheEntryStrc* pEntry)
{
    GLFLOORCACHE_TileCacheEvict(pTileCache);
    GLSUBTILECACHE_FloorCacheAppendFree(pCache, pEntry);
    return GLSUBTILECACHE_FloorCachePopFree(pCache);
}

// 0x0050F5F0
static int GLFLOORCACHE_FloorCacheAlloc(D2GlideFloorCacheStrc* pCache)
{
    if (pCache->nUsed == pCache->nCount)
        return 0;

    D2GlideFloorCacheEntryStrc* pEntry = pCache->pFreeHead;
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
    D2_ASSERT(pEntry, 0x9F);

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

// 0x0050F820
short __fastcall GLFLOORCACHE_FloorCacheAdd(D2GlideFloorCacheStrc* pCache)
{
    int nId = GLFLOORCACHE_FloorCacheAlloc(pCache);
    if (!nId)
    {
        GLSMACK_FloorCacheEvict(pCache);
        nId = GLFLOORCACHE_FloorCacheAlloc(pCache);
        D2_ASSERT(nId, 0x8B);
    }
    return nId;
}

// 0x0050F670
void __fastcall GLFLOORCACHE_FloorCacheTouch(D2GlideFloorCacheStrc* pCache, int nIndex)
{
    if (pCache->nUsed <= 1)
    {
        return;
    }

    D2_ASSERT(nIndex, 0xBC);
    D2_ASSERT(nIndex <= pCache->nCount, 0xBD);
    D2_ASSERT(nIndex >= 1, 0xBE);
    GLFLOORCACHE_FloorCacheAppendUsed(pCache, GLSMACK_FloorCacheUnlink(pCache, nIndex - 1));
}

// 0x0050FCB0
void __fastcall GLFLOORCACHE_ReleaseTileCache(D2TileLibraryEntryStrc* pTile)
{
    if (pTile->nCacheIndex > 0)
    {
        GLSMACK_FloorCacheRemove(&gtGlideFloorCache, (short)(pTile->nCacheIndex - 1));
    }

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        if (pTile->pBlocks[i].nCacheIndex > 0)
        {
            GLSUBTILECACHE_TileCacheRelease(&gtGlideTileCache, (short)(pTile->pBlocks[i].nCacheIndex - 1));
        }
    }
}

// 0x0050F7C0
void __fastcall GLFLOORCACHE_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush)
{
    if (bFlush)
    {
        while (pCache->nUsed)
            GLSMACK_FloorCacheEvict(pCache);
    }
    if (pCache->pEntries)
    {
        FOG_Free(pCache->pEntries, ".\\Src\\glFloorCache.cpp", 0x74, 0);
        pCache->pEntries = 0;
    }
    memset(pCache, 0, sizeof(*pCache));
}
