#include "D2Direct3D.h"
#include "D2D3DTypes.h"

struct D2SurfaceStrc;

struct D2SurfaceVtableStrc;

struct D2TextureEntryStrc;

struct D2TextureSetStrc;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SurfaceVtableStrc { void* unknown[31]; int (__stdcall* SetPalette)(D2SurfaceStrc*, void*); };

struct D2SurfaceStrc { D2SurfaceVtableStrc* vtable; };

struct D2TextureEntryStrc { char unknown[16]; D2SurfaceStrc* surface; char tail[12]; };

struct D2TextureSetStrc { int count; char unknown[20]; D2TextureEntryStrc* entries; };

void __fastcall D3DCORE_LogDDrawError(const char*, int); // 0x006B20E0

static void D3DTEXTURECACHE_Append(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode); // 0x006BA5C0

static __declspec(noinline) void sub_006BA5C0_AppendTail(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode);

D2TexPoolEntryStrc* __fastcall sub_006BA660_Unlink(D2TexPoolStrc* pList, int nIndex);

struct D2OwnerSlot006BA7C0Strc
{
    int n0;
    int n4;
};

struct D2Node006BA7C0Strc;

struct D2Link006BA7C0Strc
{
    D2Node006BA7C0Strc* pNext;
    D2Node006BA7C0Strc* pPrev;
};

struct D2Node006BA7C0Strc
{
    unsigned char unk_00[4];
    D2OwnerSlot006BA7C0Strc* pOwnerSlots;
    int nOwnerIndex;
    unsigned char unk_0C[0x0C];
    D2Link006BA7C0Strc f_18;
};

struct D2List006BA7C0Strc
{
    unsigned char unk_00[4];
    int nCount4;
    D2Node006BA7C0Strc* pFreeHead8;
    D2Node006BA7C0Strc* pFreeTailC;
    D2Node006BA7C0Strc* pHead10;
    D2Node006BA7C0Strc* pTail14;
};

int __fastcall sub_006BA420_Init(D2TexPoolStrc* pPool, int nBase, int nLimit, int nWidth, int nHeight);

static void D3DTEXTURECACHE_AppendSpare(D2TexPoolStrc* pPool, D2TexPoolEntryStrc* pEntry); // 0x006BA5E0

static D2TexPoolEntryStrc* D3DTEXTURECACHE_PopInUse(D2TexPoolStrc* pPool); // 0x006BA600

static D2TexPoolEntryStrc* D3DTEXTURECACHE_PopSpare(D2TexPoolStrc* pPool); // 0x006BA630

static int sub_006BA6D0_Alloc(D2TexPoolStrc* pPool);

void __fastcall sub_006BA830_Destroy(D2TexPoolStrc* pPool, int bReleaseAll);

int __fastcall D3DTEXTURECACHE_AllocOrEvict(D2TexPoolStrc* pPool); // 0x006BA920

// 0x006BA420
int __fastcall sub_006BA420_Init(D2TexPoolStrc* pPool, int nBase, int nLimit, int nWidth, int nHeight)
{
// build: symbol ?gnBytesPerPixel@* 0x00970E80
	int nUnit = gnBytesPerPixel * nWidth * nHeight;

	pPool->nCapacity = (nLimit - nBase) / nUnit;
	pPool->nCapacity = pPool->nCapacity < 0x400 ? pPool->nCapacity : 0x400;

	int nSize = pPool->nCapacity * sizeof(D2TexPoolEntryStrc);
// build: symbol ?gszTexPoolSourceFile@* 0x006FC36C
	pPool->pEntries = (D2TexPoolEntryStrc*)FOG_Alloc(nSize, gszTexPoolSourceFile, 55, 0);
	memset(pPool->pEntries, 0, nSize);

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2TexPoolEntryStrc* pEntry = &pPool->pEntries[i];
		pEntry->nIndex = i;
		if (i < pPool->nCapacity - 1)
		{
			pEntry->pNext = &pPool->pEntries[i + 1];
		}
		if (i > 0)
		{
			pEntry->pPrev = &pPool->pEntries[i - 1];
		}

		if (!sub_006B58A0_CreateTexture(&pEntry->pTexture, &pEntry->pSurface, nWidth, nHeight))
		{
			if (pEntry->pPrev)
			{
				pEntry->pPrev->pNext = 0;
			}
			pPool->nCapacity = i;
			D2_ASSERT(i, 90);
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

// 0x006BA550
void __fastcall D3DTEXTURECACHE_SetTexturePalette(D2TextureSetStrc* textures, void* palette)
{
    if (!palette) return;
    for (int i=0; i<textures->count-1; ++i) {
        D2TextureEntryStrc* entry=&textures->entries[i];
        if (entry->surface) {
            int result=entry->surface->vtable->SetPalette(entry->surface,palette);
            if (result) { D3DCORE_LogDDrawError("SetPalette (texture surface)",result); return; }
        }
    }
}

// 0x006BA5C0
static void D3DTEXTURECACHE_Append(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode)
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

void __cdecl sub_006BA5C0_EmitCaller(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode)
{
    D3DTEXTURECACHE_Append(pList, pNode);
}

static void sub_006BA5C0_AppendInUse(D2TexPoolStrc* pPool, D2TexPoolEntryStrc* pEntry)
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

// 0x006BA5E0
static void D3DTEXTURECACHE_AppendSpare(D2TexPoolStrc* pPool, D2TexPoolEntryStrc* pEntry)
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

// 0x006BA600
static D2TexPoolEntryStrc* D3DTEXTURECACHE_PopInUse(D2TexPoolStrc* pPool)
{
	D2TexPoolEntryStrc* pEntry = pPool->pInUseFirst;
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

// 0x006BA630
static D2TexPoolEntryStrc* D3DTEXTURECACHE_PopSpare(D2TexPoolStrc* pPool)
{
	D2TexPoolEntryStrc* pEntry = pPool->pSpareFirst;
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

// 0x006BA660
D2TexPoolEntryStrc* __fastcall sub_006BA660_Unlink(D2TexPoolStrc* pList, int nIndex)
{
    D2TexPoolEntryStrc* pHead = pList->pInUseFirst;
    if (!pHead)
    {
        return 0;
    }
    D2TexPoolEntryStrc* pNode = &pList->pEntries[nIndex];
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

// 0x006BA6D0
static int sub_006BA6D0_Alloc(D2TexPoolStrc* pPool)
{
	if (pPool->nInUse == pPool->nCapacity)
	{
		return 0;
	}

	D2TexPoolEntryStrc* pEntry = D3DTEXTURECACHE_PopSpare(pPool);
	D2_ASSERT(pEntry, 215);
	D2_ASSERT(pEntry->nIndex < pPool->nCapacity, 216);
	sub_006BA5C0_AppendInUse(pPool, pEntry);
	++pPool->nInUse;
	return pEntry->nIndex + 1;
}

static void sub_006BA5C0_AppendTail(D2TexPoolStrc* pList, D2TexPoolEntryStrc* pNode)
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

// 0x006BA760
void __fastcall D3DTEXTURECACHE_MoveToTail(D2TexPoolStrc* pList, int nIndex)
{
    if (pList->nInUse > 1)
    {
        LRU_ASSERT(nIndex, 245);
        LRU_ASSERT(nIndex <= pList->nCapacity, 246);
        LRU_ASSERT(nIndex >= 1, 248);
        sub_006BA5C0_AppendTail(pList, sub_006BA660_Unlink(pList, nIndex - 1));
    }
}

static inline void ResetLink(D2Link006BA7C0Strc* pLink)
{
    pLink->pNext = 0;
    pLink->pPrev = 0;
}

// 0x006BA7C0
void __fastcall D3DTEXTURECACHE_MoveFreeNode(D2List006BA7C0Strc* pList)
{
    if (pList->nCount4)
    {
        D2Node006BA7C0Strc* pNode = pList->pFreeHead8;
        if (pNode)
        {
            pList->pFreeHead8 = pNode->f_18.pNext;
            if (pList->pFreeHead8)
            {
                pList->pFreeHead8->f_18.pPrev = 0;
            }
            else
            {
                pList->pFreeTailC = 0;
            }
            ResetLink(&pNode->f_18);
            if (pNode->pOwnerSlots)
            {
                pNode->pOwnerSlots[pNode->nOwnerIndex].n0 = 0;
                pNode->pOwnerSlots[pNode->nOwnerIndex].n4 = 0;
                pNode->pOwnerSlots = 0;
            }
            if (!pList->pHead10)
            {
                pList->pHead10 = pNode;
                pList->pTail14 = pNode;
            }
            else
            {
                pList->pTail14->f_18.pNext = pNode;
                pNode->f_18.pPrev = pList->pTail14;
                pList->pTail14 = pNode;
            }
        }
        --pList->nCount4;
    }
}

void __fastcall sub_006BA7C0_ReleaseOldest(D2TexPoolStrc* pPool)
{
	if (pPool->nInUse)
	{
		D2TexPoolEntryStrc* pEntry = D3DTEXTURECACHE_PopInUse(pPool);
		if (pEntry)
		{
			if (pEntry->pOwnerSlots)
			{
				pEntry->pOwnerSlots[pEntry->nOwnerSlot].pTexture = 0;
				pEntry->pOwnerSlots[pEntry->nOwnerSlot].pInfo = 0;
				pEntry->pOwnerSlots = 0;
			}
			D3DTEXTURECACHE_AppendSpare(pPool, pEntry);
		}
		--pPool->nInUse;
	}
}

// 0x006BA830
void __fastcall sub_006BA830_Destroy(D2TexPoolStrc* pPool, int bReleaseAll)
{
	D2_ASSERT(pPool, 113);

	if (!pPool->pEntries)
	{
		D2_ASSERT(!pPool->nInUse, 116);
		return;
	}

	for (int i = 0; i <= pPool->nCapacity - 1; ++i)
	{
		D2TexPoolEntryStrc* pEntry = &pPool->pEntries[i];
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
			sub_006BA7C0_ReleaseOldest(pPool);
		}
	}

	if (pPool->pEntries)
	{
		FOG_Free(pPool->pEntries, gszTexPoolSourceFile, 148, 0);
		pPool->pEntries = 0;
	}

	memset(pPool, 0, sizeof(D2TexPoolStrc));
}

// 0x006BA920
int __fastcall D3DTEXTURECACHE_AllocOrEvict(D2TexPoolStrc* pPool)
{
	int nId = sub_006BA6D0_Alloc(pPool);
	while (!nId)
	{
		sub_006BA7C0_ReleaseOldest(pPool);
		nId = sub_006BA6D0_Alloc(pPool);
	}
	return nId;
}

#include "gen/data/Source/D2Direct3D/Src/d3dTextureCache.inc"
