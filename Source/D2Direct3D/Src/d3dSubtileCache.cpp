#include "D2Direct3D.h"
#include "D2GlideTypes.h"
#include "D2D3DTypes.h"
#include "FogApi.h"

struct D2SurfaceStrc;

struct D2SurfaceVtableStrc;

struct D2SubtileEntryStrc;

struct D2SubtileSetStrc;

struct D2Node006BABD0Strc;

struct D2List006BABD0Strc;



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


struct D2SurfaceVtableStrc { void* unknown[31]; int (__stdcall* SetPalette)(D2SurfaceStrc*, void*); };

struct D2SurfaceStrc { D2SurfaceVtableStrc* vtable; };

struct D2SubtileEntryStrc { char unknown[8]; D2SurfaceStrc* surface; char tail[12]; };

struct D2SubtileSetStrc { int count; char unknown[20]; D2SubtileEntryStrc* entries; };

void __fastcall D3DCORE_LogDDrawError(const char*, int); // 0x006B20E0

struct D2Node006BABD0Strc
{
    unsigned char unk_00[0x10];
    D2Node006BABD0Strc* pNext10;
    D2Node006BABD0Strc* pPrev14;
};

struct D2List006BABD0Strc
{
    unsigned char unk_00[8];
    D2Node006BABD0Strc* pHead8;
    D2Node006BABD0Strc* pTailC;
    unsigned char unk_10[8];
    D2Node006BABD0Strc* pNodes18;
};

static void D3DSUBTILECACHE_SubtileCacheAppendUsed(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode); // 0x006BAB30

// Kept noinline: a static whose callers here pass its arguments in registers (the #368 case).
static __declspec(noinline) void sub_006BAB30_AppendTail(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode);

D2SubtilePoolEntryStrc* __fastcall sub_006BABD0_Unlink(D2SubtilePoolStrc* pList, int nIndex);

D2SubtilePoolEntryStrc* __fastcall D3DSUBTILECACHE_SubtileCacheUnlink(D2SubtilePoolStrc* pList); // 0x006BABD0

struct D2CacheBindingStrc { int unk_00; short value; };

struct D2CacheNodeStrc { int id; D2CacheBindingStrc* binding; int unk_08; int unk_0C; D2CacheNodeStrc* next; D2CacheNodeStrc* previous; };

struct D2CacheListStrc { int capacity; int count; D2CacheNodeStrc* firstUsed; D2CacheNodeStrc* lastUsed; D2CacheNodeStrc* firstFree; D2CacheNodeStrc* lastFree; };

static int sub_006BAC50_TakeFreeNode(D2CacheListStrc* list); // 0x006BAC50

// 0x006BA9A0
int __fastcall D3DSUBTILECACHE_SubtileCacheInit(D2SubtilePoolStrc* pPool, unsigned int nBase, unsigned int nLimit, unsigned int nUnit)
{
	pPool->nCapacity = (nLimit - nBase) / nUnit;
	pPool->nCapacity = pPool->nCapacity < 0x800 ? pPool->nCapacity : 0x800;

	int nSize = pPool->nCapacity * sizeof(D2SubtilePoolEntryStrc);
// build: symbol ?gszSubtilePoolSourceFile@* 0x006FC3A8
	pPool->pEntries = (D2SubtilePoolEntryStrc*)FOG_Alloc(nSize, gszSubtilePoolSourceFile, 45, 0);
	D2_ASSERT(pPool->pEntries, 46);
	memset(pPool->pEntries, 0, nSize);

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2SubtilePoolEntryStrc* pEntry = &pPool->pEntries[i];
		pEntry->nIndex = i;
		if (i < pPool->nCapacity - 1)
		{
			pEntry->pNext = &pPool->pEntries[i + 1];
		}
		if (i > 0)
		{
			pEntry->pPrev = &pPool->pEntries[i - 1];
		}

		if (!sub_006B58A0_CreateTexture(&pEntry->pTexture, &pEntry->pSurface, 32, 32))
		{
			if (pEntry->pPrev)
			{
				pEntry->pPrev->pNext = 0;
			}
			pPool->nCapacity = i;
			D2_ASSERT(i, 73);
			break;
		}
	}

	pPool->nInUse = 0;
	pPool->pInUseFirst = 0;
	pPool->pInUseLast = 0;
	pPool->pSpareFirst = pPool->pEntries;
	pPool->pSpareLast = &pPool->pEntries[pPool->nCapacity - 1];
	return pPool->nCapacity * nUnit + nBase;
}

// 0x006BAAC0
void __fastcall D3DSUBTILECACHE_SetSubtileCachePalette(D2SubtileSetStrc* textures, void* palette)
{
    if (!palette) return;
    for (int i=0; i<textures->count-1; ++i) {
        D2SubtileEntryStrc* entry=&textures->entries[i];
        if (entry->surface) {
            int result=entry->surface->vtable->SetPalette(entry->surface,palette);
            if (result) { D3DCORE_LogDDrawError("SetPalette (subtile surface)",result); return; }
        }
    }
}

// 0x006BAB30
static void D3DSUBTILECACHE_SubtileCacheAppendUsed(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode)
{
    if (!pList->pInUseFirst)
    {
        pList->pInUseFirst = pNode;
        pList->pInUseLast = pNode;
        return;
    }
    pList->pInUseLast->pNext = pNode;
    pNode->pPrev = pList->pInUseLast;
    pList->pInUseLast = pNode;
}

void __cdecl sub_006BAB30_EmitCaller(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode)
{
    D3DSUBTILECACHE_SubtileCacheAppendUsed(pList, pNode);
}

static void sub_006BAB30_AppendInUse(D2SubtilePoolStrc* pPool, D2SubtilePoolEntryStrc* pEntry)
{
	if (!pPool->pInUseFirst)
	{
		pPool->pInUseFirst = pEntry;
		pPool->pInUseLast = pEntry;
	}
	else
	{
		pPool->pInUseLast->pNext = pEntry;
		pEntry->pPrev = pPool->pInUseLast;
		pPool->pInUseLast = pEntry;
	}
}

// 0x006BAB50
static void D3DSUBTILECACHE_SubtileCacheAppendFree(D2SubtilePoolStrc* pPool, D2SubtilePoolEntryStrc* pEntry)
{
	if (!pPool->pSpareFirst)
	{
		pPool->pSpareFirst = pEntry;
		pPool->pSpareLast = pEntry;
	}
	else
	{
		pPool->pSpareLast->pNext = pEntry;
		pEntry->pPrev = pPool->pSpareLast;
		pPool->pSpareLast = pEntry;
	}
}

// 0x006BAB70
static D2SubtilePoolEntryStrc* D3DSUBTILECACHE_SubtileCachePopUsed(D2SubtilePoolStrc* pPool)
{
	D2SubtilePoolEntryStrc* pEntry = pPool->pInUseFirst;
	if (!pEntry)
	{
		return 0;
	}

	pPool->pInUseFirst = pEntry->pNext;
	if (pPool->pInUseFirst)
	{
		pPool->pInUseFirst->pPrev = 0;
	}
	else
	{
		pPool->pInUseLast = 0;
	}
	pEntry->pNext = 0;
	pEntry->pPrev = 0;
	return pEntry;
}

// 0x006BABA0
static D2SubtilePoolEntryStrc* D3DSUBTILECACHE_SubtileCachePopFree(D2SubtilePoolStrc* pPool)
{
	D2SubtilePoolEntryStrc* pEntry = pPool->pSpareFirst;
	if (!pEntry)
	{
		return 0;
	}

	pPool->pSpareFirst = pEntry->pNext;
	if (pPool->pSpareFirst)
	{
		pPool->pSpareFirst->pPrev = 0;
	}
	else
	{
		pPool->pSpareLast = 0;
	}
	pEntry->pNext = 0;
	pEntry->pPrev = 0;
	return pEntry;
}

// 0x006BABD0
D2Node006BABD0Strc* __fastcall D3DSUBTILECACHE_SubtileCacheUnlink(D2List006BABD0Strc* pList, int nIndex)
{
    D2Node006BABD0Strc* pHead = pList->pHead8;
    if (!pHead)
    {
        return 0;
    }
    D2Node006BABD0Strc* pNode = &pList->pNodes18[nIndex];
    if (pNode == pHead)
    {
        pList->pHead8 = pHead->pNext10;
        if (pList->pHead8)
        {
            pList->pHead8->pPrev14 = 0;
        }
        else
        {
            pList->pTailC = 0;
        }
        pHead->pNext10 = 0;
        pHead->pPrev14 = 0;
        return pHead;
    }
    if (pNode == pList->pTailC)
    {
        pList->pTailC = pList->pTailC->pPrev14;
        pList->pTailC->pNext10 = 0;
    }
    else
    {
        pNode->pPrev14->pNext10 = pNode->pNext10;
        pNode->pNext10->pPrev14 = pNode->pPrev14;
    }
    pNode->pNext10 = 0;
    pNode->pPrev14 = 0;
    return pNode;
}

// 0x006BAC50
static int D3DSUBTILECACHE_SubtileCacheAlloc(D2SubtilePoolStrc* pPool)
{
	if (pPool->nInUse == pPool->nCapacity)
	{
		return 0;
	}

	D2SubtilePoolEntryStrc* pEntry = D3DSUBTILECACHE_SubtileCachePopFree(pPool);
	sub_006BAB30_AppendInUse(pPool, pEntry);
	++pPool->nInUse;
	return pEntry->nIndex + 1;
}

static void sub_006BAB30_AppendTail(D2SubtilePoolStrc* pList, D2SubtilePoolEntryStrc* pNode)
{
    if (!pList->pInUseFirst)
    {
        pList->pInUseFirst = pNode;
        pList->pInUseLast = pNode;
        return;
    }
    pList->pInUseLast->pNext = pNode;
    pNode->pPrev = pList->pInUseLast;
    pList->pInUseLast = pNode;
}


// 0x006BACB0
void __fastcall D3DSUBTILECACHE_SubtileCacheTouch(D2SubtilePoolStrc* pList, int nIndex)
{
    if (pList->nInUse > 1)
    {
        LRU_ASSERT(nIndex, 199);
        LRU_ASSERT(nIndex <= pList->nCapacity, 200);
        LRU_ASSERT(nIndex >= 1, 201);
        sub_006BAB30_AppendTail(pList, sub_006BABD0_Unlink(pList, nIndex - 1));
    }
}

static inline D2SubtilePoolEntryStrc* TakeNode(D2SubtilePoolStrc* pList)
{
    D2SubtilePoolEntryStrc* pNode = pList->pInUseFirst;
    if (!pNode)
    {
        return 0;
    }

    D2SubtilePoolEntryStrc* pNewHead = pNode->pNext;
    pList->pInUseFirst = pNewHead;
    if (pNewHead)
    {
        pNewHead->pPrev = 0;
    }
    else
    {
        pList->pInUseLast = 0;
    }

    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x006BAD10
void __fastcall D3DSUBTILECACHE_SubtileCacheEvict(D2SubtilePoolStrc* pList)
{
    if (pList->nInUse)
    {
        D2SubtilePoolEntryStrc* pNode = TakeNode(pList);
        if (pNode)
        {
            if (pNode->pOwner)
            {
                pNode->pOwner->nCacheIndex = 0;
                pNode->pOwner = 0;
            }
            if (!pList->pSpareFirst)
            {
                pList->pSpareFirst = pNode;
                pList->pSpareLast = pNode;
            }
            else
            {
                pList->pSpareLast->pNext = pNode;
                pNode->pPrev = pList->pSpareLast;
                pList->pSpareLast = pNode;
            }
        }
        --pList->nInUse;
    }
}

// 0x006BAD70
void __fastcall D3DSUBTILECACHE_SubtileCacheRelease(D2SubtilePoolStrc* pList)
{
    if (pList->nInUse)
    {
        D2SubtilePoolEntryStrc* pNode = D3DSUBTILECACHE_SubtileCacheUnlink(pList);
        if (pNode)
        {
            if (pNode->pOwner)
            {
                pNode->pOwner->nCacheIndex = 0;
                pNode->pOwner = 0;
            }
            if (!pList->pSpareFirst)
            {
                pList->pSpareFirst = pNode;
                pList->pSpareLast = pNode;
            }
            else
            {
                pList->pSpareLast->pNext = pNode;
                pNode->pPrev = pList->pSpareLast;
                pList->pSpareLast = pNode;
            }
        }
        --pList->nInUse;
    }
}

void __fastcall sub_006BAD10_ReleaseOldest(D2SubtilePoolStrc* pPool)
{
	if (pPool->nInUse)
	{
		D2SubtilePoolEntryStrc* pEntry = D3DSUBTILECACHE_SubtileCachePopUsed(pPool);
		if (pEntry)
		{
			if (pEntry->pOwner)
			{
				pEntry->pOwner->nCacheIndex = 0;
				pEntry->pOwner = 0;
			}
			D3DSUBTILECACHE_SubtileCacheAppendFree(pPool, pEntry);
		}
		--pPool->nInUse;
	}
}

// 0x006BADC0
void __fastcall D3DSUBTILECACHE_SubtileCacheDestroy(D2SubtilePoolStrc* pPool, int bReleaseAll)
{
	D2_ASSERT(pPool, 96);

	if (!pPool->pEntries)
	{
		D2_ASSERT(!pPool->nInUse, 99);
		return;
	}

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2SubtilePoolEntryStrc* pEntry = &pPool->pEntries[i];
		if (pEntry->pSurface)
		{
			pEntry->pSurface->lpVtbl->Release(pEntry->pSurface);
			pEntry->pSurface = 0;
		}
		if (pEntry->pTexture)
		{
			pEntry->pTexture->lpVtbl->Release(pEntry->pTexture);
			pEntry->pTexture = 0;
		}
	}

	if (bReleaseAll)
	{
		while (pPool->nInUse)
		{
			sub_006BAD10_ReleaseOldest(pPool);
		}
	}

	if (pPool->pEntries)
	{
		FOG_Free(pPool->pEntries, gszSubtilePoolSourceFile, 130, 0);
		pPool->pEntries = 0;
	}

	memset(pPool, 0, sizeof(D2SubtilePoolStrc));
}

int __fastcall sub_006BAF00_AllocOrEvict(D2SubtilePoolStrc* pPool)
{
	int nId = D3DSUBTILECACHE_SubtileCacheAlloc(pPool);
	while (!nId)
	{
		sub_006BAD10_ReleaseOldest(pPool);
		nId = D3DSUBTILECACHE_SubtileCacheAlloc(pPool);
	}
	return nId;
}

static inline D2CacheNodeStrc* PopNode(D2CacheNodeStrc*& first, D2CacheNodeStrc*& last)
{
    D2CacheNodeStrc* node = first;
    if (!node)
        return 0;
    first = node->next;
    if (first)
        first->previous = 0;
    else
        last = 0;
    node->next = 0;
    node->previous = 0;
    return node;
}

static inline void AppendNode(D2CacheNodeStrc*& first, D2CacheNodeStrc*& last, D2CacheNodeStrc* node)
{
    if (!first)
        first = node;
    else
    {
        last->next = node;
        node->previous = last;
    }
    last = node;
}

static int sub_006BAC50_TakeFreeNode(D2CacheListStrc* list)
{
    if (list->count == list->capacity)
        return 0;
    D2CacheNodeStrc* node = PopNode(list->firstFree, list->lastFree);
    AppendNode(list->firstUsed, list->lastUsed, node);
    ++list->count;
    return node->id + 1;
}

// 0x006BAF00
int __fastcall D3DSUBTILECACHE_SubtileCacheAdd(D2CacheListStrc* list)
{
    int result = sub_006BAC50_TakeFreeNode(list);
    if (result)
        return result;
    for (;;)
    {
        if (list->count)
        {
            D2CacheNodeStrc* node = PopNode(list->firstUsed, list->lastUsed);
            if (node)
            {
                if (node->binding)
                {
                    node->binding->value = 0;
                    node->binding = 0;
                }
                AppendNode(list->firstFree, list->lastFree, node);
            }
            --list->count;
        }
        if (list->count == list->capacity)
            continue;
        D2CacheNodeStrc* node = PopNode(list->firstFree, list->lastFree);
        if (!list->firstUsed)
            list->firstUsed = node;
        else
        {
            list->lastUsed->next = node;
            node->previous = list->lastUsed;
        }
        ++list->count;
        list->lastUsed = node;
        result = node->id + 1;
        if (result)
            return result;
    }
}

extern "C" const char gData_006FC3A8[28] = ".\\Src\\d3dSubtileCache.cpp"; // 0x006FC3A8
#pragma comment(linker, "/alternatename:?gszSubtilePoolSourceFile@@3QBDB=_gData_006FC3A8")
