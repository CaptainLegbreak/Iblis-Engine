#include "D2Direct3D.h"
#include "D2DrlgMaps.h"
#include "D2DDrawTypes.h"
#include "D2D3DTypes.h"
#include "D2GlideTypes.h"

struct D2SurfaceStrc;

struct D2SurfaceVtableStrc;

struct D2FloorEntryStrc;

struct D2FloorSetStrc;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SurfaceVtableStrc { void* unknown[31]; int (__stdcall* SetPalette)(D2SurfaceStrc*, void*); };

struct D2SurfaceStrc { D2SurfaceVtableStrc* vtable; };

struct D2FloorEntryStrc { char unknown[8]; D2SurfaceStrc* surface; char tail[12]; };

struct D2FloorSetStrc { int count; char unknown[20]; D2FloorEntryStrc* entries; };

void __fastcall D3DCORE_LogDDrawError(const char*, int); // 0x006B20E0

D2FloorPoolEntryStrc* __fastcall D3DFLOORCACHE_FloorCacheUnlink(D2FloorPoolStrc* pList); // 0x006BB1F0

static __declspec(noinline) void sub_006BB150_AppendTail(D2FloorPoolStrc* pList, D2FloorPoolEntryStrc* pNode);

D2FloorPoolEntryStrc* __fastcall D3DFLOORCACHE_FloorCacheUnlink(D2FloorPoolStrc* pList, int nIndex); // 0x006BB1F0

#define RELEASE(p) if (p) { p->lpVtbl->Release((D2ComObject006BB640Strc*)p); p = 0; }

struct D2ComObject006BB640Strc;

struct D2ComObjectVtbl006BB640Strc;

struct D2ComPtr006BB640Strc;

struct D2CacheBindingStrc;

struct D2CacheNodeStrc;

struct D2CacheListStrc;

struct D2ComObjectVtbl006BB640Strc
{
    long (__stdcall* QueryInterface)(D2ComObject006BB640Strc* pThis, const void* riid, void** ppv);
    unsigned long (__stdcall* AddRef)(D2ComObject006BB640Strc* pThis);
    unsigned long (__stdcall* Release)(D2ComObject006BB640Strc* pThis);
};

struct D2ComObject006BB640Strc
{
    D2ComObject006BB640Strc* unk;
};

struct D2ComPtr006BB640Strc
{
    D2ComObjectVtbl006BB640Strc* lpVtbl;
};

extern D2ComPtr006BB640Strc* gpSurface_00989C00; // 0x00989C00

struct D2CacheBindingStrc
{
    int unk_00;
    short wSlot;
    short unk_06;
    int f_8[2];
    const unsigned char* pData;
};

struct D2CacheNodeStrc
{
    int id;
    D2CacheBindingStrc* binding;
    D2DDSurfaceStrc* pSurface;
    D2D3DTextureStrc* pTexture;
    D2CacheNodeStrc* next;
    D2CacheNodeStrc* previous;
};

struct D2CacheListStrc
{
    int capacity;
    int count;
    D2CacheNodeStrc* firstUsed;
    D2CacheNodeStrc* lastUsed;
    D2CacheNodeStrc* firstFree;
    D2CacheNodeStrc* lastFree;
    D2CacheNodeStrc* pNodes;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

void __fastcall D3DCORE_BlitIndexedToHighColor(const unsigned char* pSource, unsigned short* pDest, int nWidth, int nHeight, int nPitch, int nUnused); // 0x006B1DC0

void __fastcall D3DCORE_CopySurface(D2DDSurfaceStrc* pDst, D2DDSurfaceStrc* pSrc, unsigned int nRows); // 0x006B38A0

void __fastcall D3DSUBTILECACHE_SubtileCacheTouch(D2CacheListStrc* pList, int nSlot); // 0x006BACB0

int __fastcall D3DSUBTILECACHE_SubtileCacheAdd(D2CacheListStrc* pList); // 0x006BAF00

static void D3DFLOORCACHE_DecodeTileBlock(const unsigned char* source, unsigned char* destination); // 0x006BB6B0

extern "C" const char gszFailedToUnlockMemorySurface_006FC284[]; // 0x006FC284

extern "C" const char gszFailedToLockMemorySurface_006FC2A4[]; // 0x006FC2A4

extern const unsigned int gnRenderFlag; // 0x006CE290

extern D2D3DDeviceStrc* gpD3DDevice_00970E78; // 0x00970E78

extern D2D3DTextureStrc* gpMemoryTexture_00989C04; // 0x00989C04

D2ComPtr006BB640Strc* gpMemorySurface; // 0x00989BF8

D2ComPtr006BB640Strc* gpMemoryTexture; // 0x00989BFC

D2ComPtr006BB640Strc* gpMemoryTexture32; // 0x00989C04

extern D2CacheListStrc gBlockCache_0096FC80; // 0x0096FC80

extern D2CacheListStrc gTileCache_0096FC9C; // 0x0096FC9C

void __fastcall D3DFLOORCACHE_FloorCacheRelease(D2CacheListStrc* pCache, int nIndex); // 0x006BB390

void __fastcall D3DSUBTILECACHE_SubtileCacheRelease(D2CacheListStrc* pCache, int nIndex); // 0x006BAD70

int __fastcall D3DFLOORCACHE_FloorCacheInit(D2FloorPoolStrc* pPool, unsigned int nBase, unsigned int nLimit, unsigned int nUnit); // 0x006BAFC0

static void D3DFLOORCACHE_FloorCacheAppendUsed(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry); // 0x006BB150

static void D3DFLOORCACHE_FloorCacheAppendFree(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry); // 0x006BB170

static D2FloorPoolEntryStrc* D3DFLOORCACHE_FloorCachePopUsed(D2FloorPoolStrc* pPool); // 0x006BB190

static D2FloorPoolEntryStrc* D3DFLOORCACHE_FloorCachePopFree(D2FloorPoolStrc* pPool); // 0x006BB1C0

void __fastcall D3DFLOORCACHE_FloorCacheEvict(D2FloorPoolStrc* pPool); // 0x006BB330

void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2FloorPoolStrc* pPool, int bReleaseAll); // 0x006BB3E0

static int D3DFLOORCACHE_FloorCacheAlloc(D2FloorPoolStrc* pPool); // 0x006BB270

D2CacheListStrc gtSubtileCache; // 0x0096FC80

unsigned char gabTileBuffer[0x400]; // 0x009897F8

D2DDSurfaceStrc* gpMemorySurface32; // 0x00989C00

int __fastcall D3DCORE_CreateMemoryTexture(void** ppSurface, void** ppTexture, int nWidth, int nHeight); // 0x006B3730

extern int gnWidth_0096F4DC; // 0x0096F4DC

int __fastcall sub_006B58A0_CreateTexture(D2D3DObjStrc** ppTexture, D2D3DObjStrc** ppSurface, int nWidth, int nHeight); // 0x006B58A0

extern int gnFloorTextureWidth; // 0x0096F4DC

extern int gnFloorTextureHeight; // 0x009702B8

extern const char gszFloorPoolSourceFile[]; // 0x006FC3E4

struct D2TileBlockStrc {
 short x,y;
 int unk04;
 unsigned short flags;
 unsigned short unk0A;
 int unk0C;
 const unsigned char* data;
};

struct D2TileStrc { int unk00[20]; int count; D2TileBlockStrc* blocks; };

extern unsigned short gwPalette_0096FA80[]; // 0x0096FA80

int __fastcall D3DFLOORCACHE_FloorCacheAdd(D2FloorPoolStrc* pPool); // 0x006BB520

// 0x006BAFC0
int __fastcall D3DFLOORCACHE_FloorCacheInit(D2FloorPoolStrc* pPool, unsigned int nBase, unsigned int nLimit, unsigned int nUnit)
{
	pPool->nCapacity = (nLimit - nBase) / nUnit;
	pPool->nCapacity = pPool->nCapacity < 0x400 ? pPool->nCapacity : 0x400;

	int nSize = pPool->nCapacity * sizeof(D2FloorPoolEntryStrc);
	pPool->pEntries = (D2FloorPoolEntryStrc*)FOG_Alloc(nSize, gszFloorPoolSourceFile, 45, 0);
	D2_ASSERT(pPool->pEntries, 46);
	memset(pPool->pEntries, 0, nSize);

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2FloorPoolEntryStrc* pEntry = &pPool->pEntries[i];
		pEntry->nIndex = i;
		if (i < pPool->nCapacity - 1)
		{
			pEntry->pNext = &pPool->pEntries[i + 1];
		}
		if (i > 0)
		{
			pEntry->pPrev = &pPool->pEntries[i - 1];
		}

		if (!sub_006B58A0_CreateTexture(&pEntry->pTexture, &pEntry->pSurface, gnFloorTextureWidth, gnFloorTextureHeight))
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

// 0x006BB0E0
void __fastcall D3DFLOORCACHE_SetFloorCachePalette(D2FloorSetStrc* textures, void* palette)
{
    if (!palette) return;
    for (int i=0; i<textures->count-1; ++i) {
        D2FloorEntryStrc* entry=&textures->entries[i];
        if (entry->surface) {
            int result=entry->surface->vtable->SetPalette(entry->surface,palette);
            if (result) { D3DCORE_LogDDrawError("SetPalette (floor surface)",result); return; }
        }
    }
}

// 0x006BB150
static void D3DFLOORCACHE_FloorCacheAppendUsed(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry)
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

// 0x006BB170
static void D3DFLOORCACHE_FloorCacheAppendFree(D2FloorPoolStrc* pPool, D2FloorPoolEntryStrc* pEntry)
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

// 0x006BB190
static D2FloorPoolEntryStrc* D3DFLOORCACHE_FloorCachePopUsed(D2FloorPoolStrc* pPool)
{
	D2FloorPoolEntryStrc* pEntry = pPool->pInUseFirst;
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

// 0x006BB1C0
static D2FloorPoolEntryStrc* D3DFLOORCACHE_FloorCachePopFree(D2FloorPoolStrc* pPool)
{
	D2FloorPoolEntryStrc* pEntry = pPool->pSpareFirst;
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

// 0x006BB1F0
D2FloorPoolEntryStrc* __fastcall D3DFLOORCACHE_FloorCacheUnlink(D2FloorPoolStrc* pList, int nIndex)
{
    D2FloorPoolEntryStrc* pHead = pList->pInUseFirst;
    if (!pHead)
    {
        return 0;
    }
    D2FloorPoolEntryStrc* pNode = &pList->pEntries[nIndex];
    if (pNode == pHead)
    {
        pList->pInUseFirst = pHead->pNext;
        if (pList->pInUseFirst)
        {
            pList->pInUseFirst->pPrev = 0;
        }
        else
        {
            pList->pInUseLast = 0;
        }
        pHead->pNext = 0;
        pHead->pPrev = 0;
        return pHead;
    }
    if (pNode == pList->pInUseLast)
    {
        pList->pInUseLast = pList->pInUseLast->pPrev;
        pList->pInUseLast->pNext = 0;
    }
    else
    {
        pNode->pPrev->pNext = pNode->pNext;
        pNode->pNext->pPrev = pNode->pPrev;
    }
    pNode->pNext = 0;
    pNode->pPrev = 0;
    return pNode;
}

// 0x006BB270
static int D3DFLOORCACHE_FloorCacheAlloc(D2FloorPoolStrc* pPool)
{
	if (pPool->nInUse == pPool->nCapacity)
	{
		return 0;
	}

	D2FloorPoolEntryStrc* pEntry = D3DFLOORCACHE_FloorCachePopFree(pPool);
	D3DFLOORCACHE_FloorCacheAppendUsed(pPool, pEntry);
	++pPool->nInUse;
	return pEntry->nIndex + 1;
}

static void sub_006BB150_AppendTail(D2FloorPoolStrc* pList, D2FloorPoolEntryStrc* pNode)
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

// 0x006BB2D0
void __fastcall D3DFLOORCACHE_FloorCacheTouch(D2FloorPoolStrc* pList, int nIndex)
{
    if (pList->nInUse > 1)
    {
        LRU_ASSERT(nIndex, 199);
        LRU_ASSERT(nIndex <= pList->nCapacity, 200);
        LRU_ASSERT(nIndex >= 1, 201);
        sub_006BB150_AppendTail(pList, D3DFLOORCACHE_FloorCacheUnlink(pList, nIndex - 1));
    }
}

// 0x006BB330
void __fastcall D3DFLOORCACHE_FloorCacheEvict(D2FloorPoolStrc* pPool)
{
	if (pPool->nInUse)
	{
		D2FloorPoolEntryStrc* pEntry = D3DFLOORCACHE_FloorCachePopUsed(pPool);
		if (pEntry)
		{
			if (pEntry->pOwner)
			{
				pEntry->pOwner->nCacheIndex = 0;
				pEntry->pOwner = 0;
			}
			D3DFLOORCACHE_FloorCacheAppendFree(pPool, pEntry);
		}
		--pPool->nInUse;
	}
}

// 0x006BB390
void __fastcall D3DFLOORCACHE_FloorCacheRelease(D2FloorPoolStrc* pList)
{
    if (pList->nInUse)
    {
        D2FloorPoolEntryStrc* pNode = D3DFLOORCACHE_FloorCacheUnlink(pList);
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

// 0x006BB3E0
void __fastcall D3DFLOORCACHE_FloorCacheDestroy(D2FloorPoolStrc* pPool, int bReleaseAll)
{
	D2_ASSERT(pPool, 96);

	if (!pPool->pEntries)
	{
		D2_ASSERT(!pPool->nInUse, 99);
		return;
	}

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2FloorPoolEntryStrc* pEntry = &pPool->pEntries[i];
		if (pEntry->pTexture)
		{
			pEntry->pTexture->lpVtbl->Release(pEntry->pTexture);
			pEntry->pTexture = 0;
		}
		if (pEntry->pSurface)
		{
			pEntry->pSurface->lpVtbl->Release(pEntry->pSurface);
			pEntry->pSurface = 0;
		}
	}

	if (bReleaseAll)
	{
		while (pPool->nInUse)
		{
			D3DFLOORCACHE_FloorCacheEvict(pPool);
		}
	}

	if (pPool->pEntries)
	{
		FOG_Free(pPool->pEntries, gszFloorPoolSourceFile, 131, 0);
		pPool->pEntries = 0;
	}

	memset(pPool, 0, sizeof(D2FloorPoolStrc));
}

// 0x006BB520
int __fastcall D3DFLOORCACHE_FloorCacheAdd(D2FloorPoolStrc* pPool)
{
	int nId = D3DFLOORCACHE_FloorCacheAlloc(pPool);
	while (!nId)
	{
		D3DFLOORCACHE_FloorCacheEvict(pPool);
		nId = D3DFLOORCACHE_FloorCacheAlloc(pPool);
	}
	return nId;
}

// 0x006BB5E0
void __cdecl D3DFLOORCACHE_CreateTileSurfaces()
{
    D2_ASSERT(D3DCORE_CreateMemoryTexture((void**)&gpMemorySurface, (void**)&gpMemoryTexture, gnWidth_0096F4DC, gnHeight_009702B8), 0x27);
    D2_ASSERT(D3DCORE_CreateMemoryTexture((void**)&gpSurface_00989C00, (void**)&gpMemoryTexture32, 0x20, 0x20), 0x2A);
}

// 0x006BB640
void __cdecl D3DFLOORCACHE_ReleaseTileSurfaces()
{
    RELEASE(gpMemoryTexture);
    RELEASE(gpMemorySurface);
    RELEASE(gpMemoryTexture32);
    RELEASE(gpSurface_00989C00);
}

// 0x006BB6B0
static void D3DFLOORCACHE_DecodeTileBlock(const unsigned char* source, unsigned char* destination)
{
    int rows = 32;
    unsigned char* row = destination;
    unsigned char* pixel = destination;
    const unsigned char* input = source;
    memset(destination, 0, 1024);
    do
    {
        unsigned char skip = *input++;
        unsigned char count = *input++;
        if (!skip && !count)
        {
            --rows;
            row += 32;
            pixel = row;
        }
        else
        {
            pixel += skip;
            while (count--)
                *pixel++ = *input++;
        }
    } while (rows);
}

int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc*, int, int); // 0x005FDEA0

// 0x006BB720
void __stdcall D3DFLOORCACHE_RenderTile(D2TileStrc* tile,unsigned short* output,int stride)
{
 memset(output,0,gnHeight_009702B8*stride*sizeof(unsigned short));
 for(int i=0;i<tile->count;++i) {
  D2TileBlockStrc* block=&tile->blocks[i];
  unsigned short* dest=output+block->y*stride+block->x;
  if(block->flags&1) {
   if(block->flags&4) {
    const unsigned char* data=block->data;
    int rows=15;
    unsigned short* row=dest;
    unsigned short* p=dest;
    do {
     unsigned char skip=*data++;
     unsigned char count=*data++;
     if(!skip&&!count) {
      row+=stride;
      --rows;
      p=row;
     } else {
      p+=skip;
      while(count) {
       --count;
       *p++=gwPalette_0096FA80[*data++];
      }
     }
    } while(rows);
   } else {
    int count=4;
    unsigned short* row=dest+14;
    const unsigned char* data=block->data;
    int y=0;
    do {
     unsigned short* pixel=row;
     const unsigned char* source=data;
     if(count>0) {
      int n=count;
      do {
       *pixel++=gwPalette_0096FA80[*source++];
      } while(--n);
     }
     data+=count;
     if(y<7) {
      row+=stride-2;
      count+=4;
     } else {
      row+=stride+2;
      count-=4;
     }
    } while(++y<15);
   }
  }
 }
}

// 0x006BB870
int __fastcall sub_006BB870_BindTileTexture(D2TileLibraryEntryStrc* pTile)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        D2_ASSERT(pTile->nCacheIndex >= 0, 0x191);
        if (pTile->nCacheIndex == 0)
        {
            pTile->nCacheIndex = D3DFLOORCACHE_FloorCacheAdd((D2FloorPoolStrc*)&gTileCache_0096FC9C);
            const int nIndex = pTile->nCacheIndex - 1;
            D2_ASSERT(nIndex >= 0, 0x19C);
            D2_ASSERT(nIndex < gTileCache_0096FC9C.capacity, 0x19D);
            D2CacheNodeStrc* pNode = &gTileCache_0096FC9C.pNodes[pTile->nCacheIndex - 1];
            pNode->binding = (D2CacheBindingStrc*)pTile;
            {
                D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
                long hResult = ((D2DDSurfaceStrc*)gpMemorySurface)->lpVtbl->Lock((D2DDSurfaceStrc*)gpMemorySurface, 0, &tDesc, 0x21, 0);
                if (hResult) D3DCORE_LogDDrawError(gszFailedToLockMemorySurface_006FC2A4, hResult);
                D2_ASSERT(tDesc.dwFlags & 8, 0x1AD);
                D3DFLOORCACHE_RenderTile((D2TileStrc*)pTile, (unsigned short*)tDesc.lpSurface, tDesc.lPitch >> 1);
                hResult = ((D2DDSurfaceStrc*)gpMemorySurface)->lpVtbl->Unlock((D2DDSurfaceStrc*)gpMemorySurface, 0);
                if (hResult) D3DCORE_LogDDrawError(gszFailedToUnlockMemorySurface_006FC284, hResult);
            }
            if (gnRenderFlags_0096F3A8 & gnRenderFlag)
                D3DCORE_CopySurface(pNode->pSurface, (D2DDSurfaceStrc*)gpMemorySurface, gnHeight_009702B8);
            else
                pNode->pTexture->lpVtbl->Load(pNode->pTexture, (D2D3DTextureStrc*)gpMemoryTexture);
            gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
        }
        else
        {
            D2CacheNodeStrc* pNode = &gTileCache_0096FC9C.pNodes[pTile->nCacheIndex - 1];
            D3DFLOORCACHE_FloorCacheTouch((D2FloorPoolStrc*)&gTileCache_0096FC9C, pTile->nCacheIndex);
            gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
        }
        nResult = 1;
    }
    return nResult;
}

// 0x006BBA00
void __fastcall D3DFLOORCACHE_BindTileTexture(D2CacheBindingStrc* pTile)
{
    D2_ASSERT(pTile->wSlot >= 0, 0x1EF);

    if (!pTile->wSlot)
    {
        D3DFLOORCACHE_DecodeTileBlock(pTile->pData, gabTileBuffer);
        pTile->wSlot = D3DSUBTILECACHE_SubtileCacheAdd(&gtSubtileCache);
        const int nIndex = pTile->wSlot - 1;
        D2_ASSERT(nIndex >= 0, 0x1FC);
        D2_ASSERT(nIndex < gtSubtileCache.capacity, 0x1FD);

        D2CacheNodeStrc* pNode = &gtSubtileCache.pNodes[pTile->wSlot - 1];
        pNode->binding = pTile;

        D2DDSurfaceDesc2Strc tDesc = { sizeof(D2DDSurfaceDesc2Strc) };
        long hResult = gpMemorySurface32->lpVtbl->Lock(gpMemorySurface32, 0, &tDesc, 0x21, 0);
        if (hResult)
        {
            D3DCORE_LogDDrawError(gszFailedToLockMemorySurface_006FC2A4, hResult);
        }

        D2_ASSERT(tDesc.dwFlags & 8, 0x20B);

        D3DCORE_BlitIndexedToHighColor(gabTileBuffer, (unsigned short*)tDesc.lpSurface, 0x20, 0x20, tDesc.lPitch >> 1, 0x20);

        hResult = gpMemorySurface32->lpVtbl->Unlock(gpMemorySurface32, 0);
        if (hResult)
        {
            D3DCORE_LogDDrawError(gszFailedToUnlockMemorySurface_006FC284, hResult);
        }

        if (gnRenderFlags_0096F3A8 & gnRenderFlag)
        {
            D3DCORE_CopySurface(pNode->pSurface, gpMemorySurface32, 0x20);
        }
        else
        {
            pNode->pTexture->lpVtbl->Load(pNode->pTexture, gpMemoryTexture_00989C04);
        }

        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
    }
    else
    {
        D2CacheNodeStrc* pNode = &gtSubtileCache.pNodes[pTile->wSlot - 1];
        D3DSUBTILECACHE_SubtileCacheTouch(&gtSubtileCache, pTile->wSlot);
        gpD3DDevice_00970E78->lpVtbl->SetTexture(gpD3DDevice_00970E78, 0, pNode->pTexture);
    }
}

// 0x006BBB90
void __fastcall D3DFLOORCACHE_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile)
{
    if (pTile->nCacheIndex > 0)
    {
        D3DFLOORCACHE_FloorCacheRelease(&gTileCache_0096FC9C, (short)(pTile->nCacheIndex - 1));
    }

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        if (pTile->pBlocks[i].nCacheIndex > 0)
        {
            D3DSUBTILECACHE_SubtileCacheRelease(&gBlockCache_0096FC80, (short)(pTile->pBlocks[i].nCacheIndex - 1));
        }
    }
}

#include "gen/data/Source/D2Direct3D/Src/d3dFloorCache.inc"
