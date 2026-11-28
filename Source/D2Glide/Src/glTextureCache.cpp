#include "D2Glide.h"
#include "D2DrlgMaps.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2GlideTexCacheEntryStrc* __fastcall GLTEXTURECACHE_TexCacheUnlink(D2GlideTexCacheStrc* pCache, int nIndex); // 0x0050EAE0

void __fastcall GLTEXTURECACHE_TexCacheEvict(D2GlideTexCacheStrc* pCache); // 0x0050EC40
extern D2GrTexInfoStrc gtGlideFloorTexInfo; // 0x0072F6BC
extern void (__stdcall* gpfnGrTexDownloadMipMap)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EAB8
extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
extern int gnGlideTileTmu; // 0x00880BF8
extern unsigned char* gpGlideFloorDecodeBuffer; // 0x00880C00

int gdwGlobal_0087EFB8; // 0x0087EFB8

static D2GlideTexCacheEntryStrc* sub_N19_TexPopHead(D2GlideTexCacheStrc* pCache);

// 0x0050E890
int __fastcall GLTEXTURECACHE_TexCacheInit(D2GlideTexCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nBlockSize)
{
    const int nCount = (nEnd - nStart) / nBlockSize;
    pCache->nBlockSize = nBlockSize;
    pCache->nCount = nCount;
    pCache->pEntries = (D2GlideTexCacheEntryStrc*)FOG_Alloc(nCount * sizeof(D2GlideTexCacheEntryStrc), ".\\Src\\glTextureCache.cpp", 45, 0);
    memset(pCache->pEntries, 0, nCount * sizeof(D2GlideTexCacheEntryStrc));

    for (int i = 0; i <= pCache->nCount - 1; ++i)
    {
        D2GlideTexCacheEntryStrc* pEntry = &pCache->pEntries[i];
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
// 0x0050EA40
static __declspec(noinline) void GLTEXTURECACHE_TexCacheAppendUsed(D2GlideTexCacheEntryStrc* pEntry, D2GlideTexCacheStrc* pCache)
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

// 0x0050EAE0
D2GlideTexCacheEntryStrc* __fastcall GLTEXTURECACHE_TexCacheUnlink(D2GlideTexCacheStrc* pCache, int nIndex)
{
    D2GlideTexCacheEntryStrc* pNode = pCache->pHead;
    if (!pNode)
        return 0;
    D2GlideTexCacheEntryStrc* pEntry = &pCache->pEntries[nIndex];
    if (pEntry == pNode)
    {
        pCache->pHead = pNode->pNext;
        if (pCache->pHead)
            pCache->pHead->pPrev = 0;
        else
            pCache->pTail = 0;
        pNode->pNext = 0;
        pNode->pPrev = 0;
        return pNode;
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

// 0x0050EBE0
void __fastcall GLTEXTURECACHE_TexCacheTouch(D2GlideTexCacheStrc* pCache, int nId)
{
    if (pCache->nUsed > 1)
    {
        D2_ASSERT(nId, 0xDE);
        D2_ASSERT(nId <= pCache->nCount, 0xDF);
        D2_ASSERT(nId >= 1, 0xE0);
        GLTEXTURECACHE_TexCacheAppendUsed(GLTEXTURECACHE_TexCacheUnlink(pCache, nId - 1), pCache);
    }
}

// 0x0050EA60
static void GLTEXTURECACHE_TexCacheAppendFree(D2GlideTexCacheEntryStrc* pEntry, D2GlideTexCacheStrc* pCache)
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

// 0x0050EA80
static D2GlideTexCacheEntryStrc* GLTEXTURECACHE_TexCachePopUsed(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->pHead;
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

// 0x0050EAB0
static D2GlideTexCacheEntryStrc* GLTEXTURECACHE_TexCachePopFree(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->pFreeHead;
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

// 0x0050EC40
void __fastcall GLTEXTURECACHE_TexCacheEvict(D2GlideTexCacheStrc* pCache)
{
    if (!pCache->nUsed)
        return;
    D2GlideTexCacheEntryStrc* pEntry = sub_N19_TexPopHead(pCache);
    if (pEntry)
    {
        if (pEntry->pOwner)
        {
            pEntry->pOwner[pEntry->nOwnerIndex].nCache = 0;
            pEntry->pOwner[pEntry->nOwnerIndex].nId = 0;
            pEntry->pOwner = 0;
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


// 0x0050EF60
static void GLTEXTURECACHE_TileCacheAppendFree(D2GlideTileCacheEntryStrc* pEntry, D2GlideTileCacheStrc* pCache)
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

// 0x0050EFB0
static D2GlideTileCacheEntryStrc* GLTEXTURECACHE_TileCachePopFree(D2GlideTileCacheStrc* pCache)
{
    D2GlideTileCacheEntryStrc* pEntry = pCache->pFreeHead;
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

void __fastcall sub_M116_Emit_0050EA60(D2GlideTexCacheStrc* pTex, D2GlideTileCacheStrc* pTile)
{
    GLTEXTURECACHE_TexCacheAppendFree(GLTEXTURECACHE_TexCachePopUsed(pTex), pTex);
    GLTEXTURECACHE_TexCacheAppendFree(GLTEXTURECACHE_TexCachePopFree(pTex), pTex);
    GLTEXTURECACHE_TileCacheAppendFree(GLTEXTURECACHE_TileCachePopFree(pTile), pTile);
}

// 0x0050EB60
static int GLTEXTURECACHE_TexCacheAlloc(D2GlideTexCacheStrc* pList)
{
    if (pList->nUsed == pList->nCount)
    {
        return 0;
    }

    D2GlideTexCacheEntryStrc* pNode = pList->pFreeHead;
    if (pNode)
    {
        pList->pFreeHead = pNode->pNext;
        if (pList->pFreeHead)
        {
            pList->pFreeHead->pPrev = 0;
        }
        else
        {
            pList->pFreeTail = 0;
        }
        pNode->pNext = 0;
        pNode->pPrev = 0;
        if (!pList->pHead)
        {
            pList->nUsed += 1;
            pList->pHead = pNode;
            pList->pTail = pNode;
            return pNode->nId + 1;
        }
    }
    else
    {
        D2_ASSERT(pNode, 0xC1);
    }

    pList->pTail->pNext = pNode;
    pNode->pPrev = pList->pTail;
    pList->nUsed += 1;
    pList->pTail = pNode;
    return pNode->nId + 1;
}

static D2GlideTexCacheEntryStrc* sub_N19_TexPopHead(D2GlideTexCacheStrc* pCache)
{
    D2GlideTexCacheEntryStrc* pEntry = pCache->pHead;
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

// 0x0050ED10
int __fastcall GLTEXTURECACHE_TexCacheAdd(D2GlideTexCacheStrc* pList)
{
    int nId;
    while (!(nId = GLTEXTURECACHE_TexCacheAlloc(pList)))
    {
        GLTEXTURECACHE_TexCacheEvict(pList);
    }
    return nId;
}

D2GlideFloorCacheStrc gtGlideFloorCache; // 0x0087EB68

// 0x0050ECB0
void __fastcall GLTEXTURECACHE_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush)
{
    if (bFlush)
    {
        while (pCache->nUsed)
            GLTEXTURECACHE_TexCacheEvict(pCache);
    }
    if (pCache->pEntries)
    {
        FOG_Free(pCache->pEntries, ".\\Src\\glTextureCache.cpp", 0x7F, 0);
        pCache->pEntries = 0;
    }
    memset(pCache, 0, sizeof(*pCache));
}


// 0x0050FAD0
int __fastcall GLTEXTURECACHE_BindFloorTexture(D2TileLibraryEntryStrc* pTile)
{
    int bResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        D2_ASSERT(pTile->nCacheIndex >= 0, 0xD8);
        int nTexAddress;
        if (pTile->nCacheIndex == 0)
        {
            GLVERTEX_DecodeTileBlocks(pTile, gpGlideFloorDecodeBuffer);
            pTile->nCacheIndex = GLFLOORCACHE_FloorCacheAdd(&gtGlideFloorCache);
            const int nEntry = pTile->nCacheIndex - 1;
            D2_ASSERT(nEntry >= 0, 0xE5);
            D2_ASSERT(nEntry < gtGlideFloorCache.nCount, 0xE6);
            gtGlideFloorCache.pEntries[pTile->nCacheIndex - 1].pTile = pTile;
            nTexAddress = gtGlideFloorCache.pEntries[pTile->nCacheIndex - 1].nAddress;
            gpfnGrTexDownloadMipMap(gnGlideTileTmu, nTexAddress, 3, &gtGlideFloorTexInfo);
        }
        else
        {
            GLFLOORCACHE_FloorCacheTouch(&gtGlideFloorCache, pTile->nCacheIndex);
            nTexAddress = gtGlideFloorCache.pEntries[pTile->nCacheIndex - 1].nAddress;
        }
        gpfnGrTexSource(gnGlideTileTmu, nTexAddress, 3, &gtGlideFloorTexInfo);
        GLCORE_SetTextureCombineMode(gnGlideTileTmu);
        bResult = 1;
    }
    return bResult;
}

D2GrTexInfoStrc gtGlideFloorTexInfo = { 8, 8, 1, 5 }; // 0x0072F6BC
