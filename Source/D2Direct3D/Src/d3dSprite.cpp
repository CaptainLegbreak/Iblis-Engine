#include "D2Direct3D.h"

#include "D2CelContext.h"

#include "D2D3DTypes.h"
#include "D2CMPApi.h"

struct D2Direct3D006B7110Strc;

struct D2VertexBufferDescStrc;

struct D2Direct3DVtbl006B7110Strc;

struct D2CelFileStrc;




extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2VertexBufferDescStrc
{
    unsigned int dwSize;
    unsigned int dwCaps;
    unsigned int dwFVF;
    unsigned int dwNumVertices;
};

struct D2Direct3DVtbl006B7110Strc
{
    void* unknown0[9];
    long (__stdcall* CreateVertexBuffer)(D2Direct3D006B7110Strc* pThis, D2VertexBufferDescStrc* pDesc, void** ppVertexBuffer, unsigned int dwFlags, void* pUnknown);
};

struct D2Direct3D006B7110Strc
{
    D2Direct3DVtbl006B7110Strc* lpVtbl;
};

typedef void (__fastcall* PixelDataFreeCallback)(void* pData);

void __stdcall CelSetHardwareFreeCallback(PixelDataFreeCallback pfnCallback); // 0x00601A30

int __fastcall D3DCORE_CreateMemoryTexture(void** ppSurface, void** ppTexture, int nWidth, int nHeight); // 0x006B3730


void __fastcall D3DSPRITE_ClearResourceEntries(void* pData); // 0x006B5BB0

extern D2Direct3D006B7110Strc* gpDirect3D3; // 0x00970E64

extern void* gpSpriteBuffer; // 0x00970F34

extern void* gpSpriteOutlineBuffer; // 0x00970F38


extern D2D3DObjStrc* gapSpriteTextures[3]; // 0x00970F1C

extern D2D3DObjStrc* gapSpriteSurfaces[3]; // 0x00970F28

extern D2D3DObjStrc* gpSpriteObject_00970F3C; // 0x00970F3C

int __stdcall D2CMPSpriteValidate(D2GfxDataStrc* pContext, int bAsync, int nFlags); // 0x006001F0


static int __stdcall D3D_LoadSpriteInfo(D2GfxDataStrc* pContext, D2SpriteInfoStrc* pInfo); // 0x006B5C80

static void __stdcall D3DSPRITE_SetTextureSize(D2SpriteInfoStrc* pInfo); // 0x006B5CF0

void* gpSpriteBuffer; // 0x00970F34

void* gpSpriteOutlineBuffer; // 0x00970F38

#include "D2GfxTypes.h"
#include "D2DDrawTypes.h"
#include "D2ClientTypes.h"
#include "FogApi.h"
#include "FogApi.h"

struct D2CelStrc;

extern D2PaletteTableStrc* gpGlideState_007C9150; // 0x007C9150

struct D2TexturePoolEntryStrc
{
    int unk0x00;
    int* pSlots;
    int nMode;
    int nArg;
    void* pTarget;
    D2D3DTextureStrc* pTexture;
    int unk0x18;
    int unk0x1C;
};

struct D2TexturePoolStrc
{
    int nCount;
    int unk0x04[5];
    D2TexturePoolEntryStrc* pEntries;
};

typedef char check_desc_size[(sizeof(D2DDSurfaceDesc2Strc) == 0x7C) ? 1 : -1];

typedef char check_pool_size[(sizeof(D2TexturePoolStrc) == 0x1C) ? 1 : -1];

typedef char check_entry_size[(sizeof(D2TexturePoolEntryStrc) == 0x20) ? 1 : -1];

extern "C" const char gszEmptyAssertText;                                                   // 0x006CC837

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                // 0x00681EF0


void __stdcall CelDraw(D2GfxDataStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0


void __fastcall D3DCORE_LogDDrawError(const char* szWhere, int hResult); // 0x006B20E0

void __fastcall D3DCORE_CopySurface(void* pTarget, D2DDSurfaceStrc* pSurface, int nRows); // 0x006B38A0

void __fastcall D3DTEXTURECACHE_MoveToTail(D2TexturePoolStrc* pPool, int nIndex); // 0x006BA760

int __fastcall D3DTEXTURECACHE_AllocOrEvict(D2TexturePoolStrc* pPool); // 0x006BA920

extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8

extern const unsigned int gnRenderFlag; // 0x006CE290

extern D2TexturePoolStrc gaTexturePools[]; // 0x00970EAC

extern D2D3DTextureStrc* gapTextures[]; // 0x00970F18

extern D2DDSurfaceStrc* gapSurfaces_00970F24[]; // 0x00970F24

extern unsigned char* gpBuffer_00970F34; // 0x00970F34

extern unsigned char* gpBuffer_00970F38; // 0x00970F38

extern "C" const char gszSetTextureFailed[]; // 0x006FC26C

extern "C" const char gszFailedToUnlockMemorySurface[]; // 0x006FC284

extern "C" const char gszFailedToLockMemorySurface[]; // 0x006FC2A4

extern D2D3DDeviceStrc* gpDevice_00970E78; // 0x00970E78

D2VertexBufferStrc* gpVertexBuffer;        // 0x00970F3C

int gnPerspectiveScale;        // 0x00989748

extern const char gszSpriteError[]; // 0x006FC238


int* __stdcall sub_00601B10_GetCelTextureSlots(D2CelStrc* cel); // 0x00601B10



void __fastcall sub_006B9780_SetColor(D2TLVertexStrc* pVertex, unsigned int nPacked, unsigned char nAlpha); // 0x006B9780


static int __stdcall D3DSPRITE_UploadTexture(D2SpriteInfoStrc* pInfo, int nMode, int nArg3, unsigned char nColor); // 0x006B5D40

static int __stdcall D3DSPRITE_DrawSpriteQuad(D2SpriteInfoStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette); // 0x006B63F0

struct D2TexLocationStrc
{
    int nCache;
    int nIndex;
};

struct D2SpriteQuad006B61A0Strc
{
    int unk_00[3];
    int nX;
    int nHalf;
    int nWidth;
    int nHeight;
    int unk_1C;
    float fU0;
    float fU1;
    float fV0;
    float fV1;
};

static void __stdcall D3DSPRITE_DrawTexturedQuad(int nOffsetX, int nOffsetY, unsigned char nAlpha, D2SpriteQuad006B61A0Strc* pQuad); // 0x006B61A0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __fastcall sub_006B9860_Project(int nX, int nY, int nZ, int* pScreenX, int* pScreenY);                  // 0x006B9860

extern int gnRenderWidth; // 0x007C9138

extern int gnRenderHeight; // 0x007C913C

void __fastcall D3DTEXTURECACHE_MoveToTail(int* pValue, int nValue); // 0x006BA760

extern const char gszEmptyString[]; // 0x006CC837

static int __stdcall D3DSPRITE_ClipSprite(D2SpriteInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds, D2ClipStrc* pClip); // 0x006B6D70


void __fastcall D3DSPRITE_DrawSpriteRows(D2GfxDataStrc* pContext, int nX, int nY, unsigned int nSkip, unsigned int nRows, int nBlendMode); // 0x006B6C90

void __fastcall D3DSPRITE_DrawSpriteClipped(D2GfxDataStrc* pContext, int nX, int nY, const D2BoundsStrc* pBounds, int nBlendMode); // 0x006B6EE0

static int gnVertexBufferPos; // 0x00970F40

// 0x006B5B10
void __cdecl D3DSPRITE_ReleaseSprites()
{
    if (gpSpriteObject_00970F3C)
    {
        gpSpriteObject_00970F3C->lpVtbl->Release(gpSpriteObject_00970F3C);
        gpSpriteObject_00970F3C = 0;
    }

    if (gpSpriteBuffer)
    {
        FOG_Free(gpSpriteBuffer, ".\\Src\\d3dSprite.cpp", 136, 0);
        gpSpriteBuffer = 0;
    }

    if (gpSpriteOutlineBuffer)
    {
        FOG_Free(gpSpriteOutlineBuffer, ".\\Src\\d3dSprite.cpp", 142, 0);
        gpSpriteOutlineBuffer = 0;
    }

    for (int i = 0; i < 3; ++i)
    {
        if (gapSpriteTextures[i])
        {
            gapSpriteTextures[i]->lpVtbl->Release(gapSpriteTextures[i]);
            gapSpriteTextures[i] = 0;
        }

        if (gapSpriteSurfaces[i])
        {
            gapSpriteSurfaces[i]->lpVtbl->Release(gapSpriteSurfaces[i]);
            gapSpriteSurfaces[i] = 0;
        }
    }
}

struct D2ResourceEntryStrc { int value0; int value4; int rest[6]; };
struct D2ResourceGroupStrc { D2ResourceEntryStrc* entries; int rest[6]; };
struct D2ResourcePairStrc { int group; int entry; };
struct D2ResourceSetStrc { D2ResourcePairStrc pairs[5]; };
extern D2ResourceGroupStrc gaResourceGroups[]; // 0x00970EE0

// 0x006B5BB0
void __fastcall D3DSPRITE_ClearResourceEntries(D2ResourceSetStrc* set)
{
    for (int i = 0; i < 5; ++i)
    {
        int group = set->pairs[i].group - 1;
        if (group >= 0)
        {
            int entry = set->pairs[i].entry - 1;
            if (entry >= 0)
                gaResourceGroups[group].entries[entry].value4 = 0;
        }
    }
}

// 0x006B5C80
static int __stdcall D3D_LoadSpriteInfo(D2GfxDataStrc* pContext, D2SpriteInfoStrc* pInfo)
{
    if (!D2CMPSpriteValidate(pContext, 0, 1))
    {
        return 0;
    }

    if (!pContext->pCel)
    {
        LOGMANAGER_WriteLogLine("error loading sprite unit:%d  class:%d  mode:%d  %s", pContext->nUnitType, pContext->nUnitIndex, pContext->nMode, pContext->szName);
        return 0;
    }

    pInfo->pContext = pContext;
    pInfo->nWidth = CelGetWidth(pContext->pCel);
    pInfo->nOffsetX = CelGetOffsetX(pContext->pCel);
    pInfo->nHeight = CelGetHeight(pContext->pCel);
    pInfo->nOffsetY = CelGetOffsetY(pContext->pCel);
    return 1;
}

// 0x006B5CF0
static void __stdcall D3DSPRITE_SetTextureSize(D2SpriteInfoStrc* pInfo)
{
    int nSize = 0x20;
    if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
    {
        nSize = 0x80;
        if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
        {
            nSize = 0x100;
            if (pInfo->nWidth > nSize || pInfo->nHeight > nSize)
            {
                goto done;
            }
        }
    }
    pInfo->nTexWidth = nSize;
    pInfo->nTexHeight = nSize;
done:
    pInfo->nTexSize = pInfo->nTexHeight * pInfo->nTexWidth;
    pInfo->fU0 = 0.0f;
    pInfo->fU1 = 1.0f;
    pInfo->fV0 = 0.0f;
    pInfo->fV1 = 1.0f;
}

// 0x006B5D40
static int __stdcall D3DSPRITE_UploadTexture(D2SpriteInfoStrc* ptInfo, int nMode, int nArg3, unsigned char nColor)
{
    D2_ASSERT(ptInfo->pContext->pCel, 0x11E);
    int* pSlots = sub_00601B10_GetCelTextureSlots(ptInfo->pContext->pCel);
    const int nOrigMode = nMode;
    if (nMode == 4)
    {
        nMode = 1;
    }

    D2TexLocationStrc* tLocation = &((D2TexLocationStrc*)pSlots)[nMode];
    if (!tLocation->nCache)
    {
        if (ptInfo->nWidth <= 32 && ptInfo->nHeight <= 32)
        {
            tLocation->nCache = 3;
        }
        else if (ptInfo->nWidth <= 128 && ptInfo->nHeight <= 128)
        {
            tLocation->nCache = 2;
        }
        else if (ptInfo->nWidth <= 256 && ptInfo->nHeight <= 256)
        {
            tLocation->nCache = 1;
        }
        else
        {
            return 0;
        }
    }

    D2TexturePoolStrc* pPool = &gaTexturePools[tLocation->nCache];
    long hResult;
    if (((D2TexLocationStrc*)pSlots)[nMode].nIndex && (pPool->pEntries[((D2TexLocationStrc*)pSlots)[nMode].nIndex - 1].nArg == nArg3 || nOrigMode == 4))
    {
        D3DTEXTURECACHE_MoveToTail(pPool, tLocation->nIndex);
        D2TexturePoolEntryStrc* pHit = &pPool->pEntries[tLocation->nIndex - 1];
        hResult = gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, pHit->pTexture);
        if (hResult)
        {
            D3DCORE_ShowD3DError(gszSetTextureFailed, hResult);
        }
        return 1;
    }

    {
    D2DDSurfaceStrc* pSurface = gapSurfaces_00970F24[tLocation->nCache];
    D2D3DTextureStrc* pSource = gapTextures[tLocation->nCache];
    if (!((D2TexLocationStrc*)pSlots)[nMode].nIndex)
    {
        tLocation->nIndex = D3DTEXTURECACHE_AllocOrEvict(pPool);
    }
    D2_ASSERT(tLocation->nIndex - 1 >= 0, 0x164);
    D2_ASSERT(tLocation->nIndex - 1 < pPool->nCount, 0x165);

    unsigned char* pBuffer = gpBuffer_00970F34;
    unsigned char* pData = gpBuffer_00970F34;
    D2TexturePoolEntryStrc* pEntry = &pPool->pEntries[tLocation->nIndex - 1];
    pEntry->pSlots = pSlots;
    pEntry->nMode = nMode;
    pEntry->nArg = nArg3;
    D2_ASSERT(pEntry->pTarget, 0x16D);
    D2_ASSERT(pEntry->pTexture, 0x16E);
    D2_ASSERT(pBuffer, 0x171);
    D2_ASSERT(ptInfo->nTexSize <= 0x10000, 0x172);
    memset(pBuffer, 0, ptInfo->nTexSize);

    switch (nMode)
    {
    case 1:
    case 4:
        CelDraw(ptInfo->pContext, -ptInfo->nOffsetX, ptInfo->nTexHeight - ptInfo->nOffsetY - 1, 0, 0, pBuffer,
            ptInfo->nTexHeight, ptInfo->nTexWidth, 0, 0, nArg3);
        break;

    case 2:
    {
        CelDraw(ptInfo->pContext, -ptInfo->nOffsetX, ptInfo->nTexHeight - ptInfo->nOffsetY - 1, 0, 0, pBuffer,
            ptInfo->nTexHeight, ptInfo->nTexWidth, 0, 0, nArg3);
        unsigned char* pPixel = gpBuffer_00970F34;
        unsigned char* pRemap = gpGlideState_007C9150->pRemap;
        for (int i = 0; i < ptInfo->nTexSize; ++i)
        {
            if (*pPixel)
            {
                *pPixel = pRemap[*pPixel];
            }
            ++pPixel;
        }
        break;
    }

    case 3:
    {
        CelDraw(ptInfo->pContext, 1 - ptInfo->nOffsetX, ptInfo->nTexHeight - ptInfo->nOffsetY - 2, 0, 0, pBuffer,
            ptInfo->nTexHeight, ptInfo->nTexWidth, 0, 0, 0);
        unsigned char* pOutline = gpBuffer_00970F38;
        D2_ASSERT(pOutline, 0x19A);
        D2_ASSERT(ptInfo->nTexSize <= 0x10000, 0x19B);
        memset(pOutline, 0, ptInfo->nTexSize);
        unsigned char* pSrc = gpBuffer_00970F34 + ptInfo->nTexWidth;
        unsigned char* pDst = pOutline + ptInfo->nTexWidth;
        const int nPitch = ptInfo->nTexWidth;
        const int nCount = ptInfo->nTexSize - 2 * nPitch;
        for (int i = 0; i < nCount; ++i)
        {
            if (*pSrc++)
            {
                pDst[-ptInfo->nTexWidth] = nColor;
                pDst[-1] = nColor;
                pDst[1] = nColor;
                pDst[ptInfo->nTexWidth] = nColor;
            }
            ++pDst;
        }
        pData = pOutline;
        break;
    }
    }

    D2_ASSERT(pSurface, 0x1B4);
    D2_ASSERT(pSource, 0x1B5);

    D2DDSurfaceDesc2Strc tDesc = { sizeof(tDesc) };
    hResult = pSurface->lpVtbl->Lock(pSurface, 0, &tDesc, 0x21, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError(gszFailedToLockMemorySurface, hResult);
    }
    D2_ASSERT(tDesc.dwFlags & 8, 0x1C0);
    D3DCORE_BlitIndexedToHighColor(pData, (unsigned short*)tDesc.lpSurface, ptInfo->nTexWidth, ptInfo->nTexHeight, tDesc.lPitch >> 1,
        ptInfo->nTexHeight);
    hResult = pSurface->lpVtbl->Unlock(pSurface, 0);
    if (hResult)
    {
        D3DCORE_LogDDrawError(gszFailedToUnlockMemorySurface, hResult);
    }

    if (gnRenderFlags_0096F3A8 & gnRenderFlag)
    {
        D3DCORE_CopySurface(pEntry->pTarget, pSurface, ptInfo->nTexHeight);
    }
    else
    {
        pEntry->pTexture->lpVtbl->Load(pEntry->pTexture, pSource);
    }

    hResult = gpDevice_00970E78->lpVtbl->SetTexture(gpDevice_00970E78, 0, pEntry->pTexture);
    }
    if (hResult)
    {
        D3DCORE_ShowD3DError(gszSetTextureFailed, hResult);
    }
    return 1;
}

// 0x006B61A0
static void __stdcall D3DSPRITE_DrawTexturedQuad(int nOffsetX, int nOffsetY, unsigned char nAlpha, D2SpriteQuad006B61A0Strc* pQuad)
{
    float fU0 = pQuad->fU0;
    float fU1 = pQuad->fU1;
    float fV0 = pQuad->fV0;
    float fV1 = pQuad->fV1;
    int bPerspective = sub_006B9830_GetPerspective();

    D2QuadRectStrc tRect;
    tRect.nHeight = pQuad->nHeight >> 1;
    pQuad->nHalf >>= 1;
    tRect.nWidth = pQuad->nWidth;
    tRect.nX = pQuad->nX + pQuad->nHalf;
    tRect.nY = pQuad->nHalf - tRect.nHeight;

    if (bPerspective && gnPerspectiveScale != 256)
    {
        tRect.nX = gnPerspectiveScale * tRect.nX / 256;
        tRect.nY = gnPerspectiveScale * tRect.nY / 256;
        tRect.nWidth = gnPerspectiveScale * tRect.nWidth / 256;
        tRect.nHeight = gnPerspectiveScale * tRect.nHeight / 256;
    }

    int nX = tRect.nX + nOffsetX;
    int nY = tRect.nY + nOffsetY;
    int nWidth = tRect.nWidth;
    int nHeight = tRect.nHeight;
    float fTop = (float)nY;
    float fBottom = (float)(nY + nHeight);

    D2TLVertexStrc* pVertices;
    if (gpVertexBuffer->lpVtbl->Lock(gpVertexBuffer, 0x21, (void**)&pVertices, 0))
        return;

    pVertices += gnVertexBufferPos;
    int nLeft = nX - nHeight;
    pVertices[0].fX = (float)nLeft;
    pVertices[0].fY = fTop;
    pVertices[0].fZ = 0.5f;
    pVertices[0].fRhw = 1.0f;
    pVertices[0].fU = fU0;
    pVertices[0].fV = fV0;
    pVertices[1].fX = (float)nX;
    pVertices[1].fY = fBottom;
    pVertices[1].fZ = 0.5f;
    pVertices[1].fRhw = 1.0f;
    pVertices[1].fU = fU0;
    pVertices[1].fV = fV1;
    pVertices[2].fX = (float)(nX + nWidth);
    pVertices[2].fY = fBottom;
    pVertices[2].fZ = 0.5f;
    pVertices[2].fRhw = 1.0f;
    pVertices[2].fU = fU1;
    pVertices[2].fV = fV1;
    pVertices[3].fX = (float)(nLeft + nWidth);
    pVertices[3].fY = fTop;
    pVertices[3].fZ = 0.5f;
    pVertices[3].fRhw = 1.0f;
    pVertices[3].fU = fU1;
    pVertices[3].fV = fV0;
    pVertices[0].dwColor = (unsigned int)nAlpha << 24;
    pVertices[1].dwColor = pVertices[0].dwColor;
    pVertices[2].dwColor = pVertices[1].dwColor;
    pVertices[3].dwColor = pVertices[2].dwColor;

    gpVertexBuffer->lpVtbl->Unlock(gpVertexBuffer);
    gpDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpDevice_00970E78, 6, gpVertexBuffer, gnVertexBufferPos, 4, 0x1C);

    gnVertexBufferPos += 4;
    if (gnVertexBufferPos > 0x2B)
        gnVertexBufferPos = 0;
}

// 0x006B63F0
static int __stdcall D3DSPRITE_DrawSpriteQuad(D2SpriteInfoStrc* pSprite, int nX, int nY, unsigned int nColor, int nPaletteIndex, unsigned char nAlpha, int bPalette)
{
    D3DCORE_SetColorCombineMode(1);
    D3DCORE_SetTextureFilterMode(1);

    D2QuadRectStrc tRect;
    tRect.nX = pSprite->nOffsetX;
    float fU0 = pSprite->fU0;
    float fU1 = pSprite->fU1;
    float fV0 = pSprite->fV0;
    float fV1 = pSprite->fV1;

    int bPerspective = sub_006B9830_GetPerspective();
    tRect.nWidth = pSprite->nTexWidth;
    tRect.nHeight = pSprite->nTexHeight;
    tRect.nY = pSprite->nOffsetY - tRect.nHeight;
    if (bPerspective && gnPerspectiveScale != 256)
    {
        tRect.nX = gnPerspectiveScale * tRect.nX / 256;
        tRect.nY = gnPerspectiveScale * tRect.nY / 256;
        tRect.nWidth = gnPerspectiveScale * tRect.nWidth / 256;
        tRect.nHeight = gnPerspectiveScale * tRect.nHeight / 256;
    }

    int nLeft = tRect.nX + nX;
    float fX0 = (float)nLeft;
    float fX1 = (float)(nLeft + tRect.nWidth);
    int nTop = tRect.nY + nY;
    float fY0 = (float)nTop;
    float fY1 = (float)(nTop + tRect.nHeight);

    D2TLVertexStrc* pVertices;
    const long hResult = gpVertexBuffer->lpVtbl->Lock(gpVertexBuffer, 0x21, (void**)&pVertices, 0);
    if (hResult)
    {
        return hResult;
    }

    pVertices += gnVertexBufferPos;
    if (!nPaletteIndex && !bPalette)
    {
        sub_006B9780_SetColor(pVertices, nColor, nAlpha);
    }
    else
    {
        pVertices->dwColor = (((unsigned int)nAlpha << 8 | gpGlideState_007C9150->pStandardColorsPalette[nPaletteIndex * 3]) << 8 | gpGlideState_007C9150->pStandardColorsPalette[nPaletteIndex * 3 + 1]) << 8 | gpGlideState_007C9150->pStandardColorsPalette[nPaletteIndex * 3 + 2];
    }

    pVertices[1].dwColor = pVertices[0].dwColor;
    pVertices[2].dwColor = pVertices[1].dwColor;
    pVertices[3].dwColor = pVertices[2].dwColor;

    pVertices[0].fX = fX0;
    pVertices[0].fY = fY0;
    pVertices[0].fZ = 0.5f;
    pVertices[0].fRhw = 1.0f;
    pVertices[0].fU = fU0;
    pVertices[0].fV = fV0;

    pVertices[1].fX = fX0;
    pVertices[1].fY = fY1;
    pVertices[1].fZ = 0.5f;
    pVertices[1].fRhw = 1.0f;
    pVertices[1].fU = fU0;
    pVertices[1].fV = fV1;

    pVertices[2].fX = fX1;
    pVertices[2].fY = fY1;
    pVertices[2].fZ = 0.5f;
    pVertices[2].fRhw = 1.0f;
    pVertices[2].fU = fU1;
    pVertices[2].fV = fV1;

    pVertices[3].fX = fX1;
    pVertices[3].fY = fY0;
    pVertices[3].fZ = 0.5f;
    pVertices[3].fRhw = 1.0f;
    pVertices[3].fU = fU1;
    pVertices[3].fV = fV0;

    gpVertexBuffer->lpVtbl->Unlock(gpVertexBuffer);
    gpDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpDevice_00970E78, 6, gpVertexBuffer, gnVertexBufferPos, 4, 0x1C);
    gnVertexBufferPos += 4;
    if (gnVertexBufferPos > 43)
    {
        gnVertexBufferPos = 0;
    }
} // the normal path has no return statement, as in the original; callers use what eax holds

static
// 0x006B6680
unsigned char D3DSPRITE_SetBlendAndAlpha(int mode)
{
    unsigned char alpha = 255;
    switch (mode)
    {
    case 5:
    case 7:
        D3DCORE_SetAlphaBlendMode(1);
        break;
    case 3:
        D3DCORE_SetAlphaBlendMode(2);
        break;
    case 4:
        D3DCORE_SetAlphaBlendMode(3);
        break;
    default:
        D3DCORE_SetAlphaBlendMode(4);
        if (mode == 0)
            alpha = 64;
        else if (mode == 1)
            alpha = 128;
        else if (mode == 2)
            alpha = 192;
        break;
    }
    return alpha;
}

// 0x006B6700
static inline int D3DSPRITE_IsOutsideScreen(int nX, int nY, D2GlideRectViewStrc* pRect)
{
    nX += pRect->nOffsetX;
// build: symbol ?gnRenderWidth@* 0x007C9138
// build: symbol ?gnRenderHeight@* 0x007C913C
    if (nX > gnRenderWidth || pRect->nLeft + nX < 0 || (nY += pRect->nOffsetY) < 0 || nY - pRect->nTop >= gnRenderHeight)
        return 1;
    return 0;
}

// 0x006B6730
int __fastcall D3DSPRITE_DrawFlatSprite(D2GfxDataStrc* pData, int nX, int nY, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette)
{
	D2SpriteInfoStrc tInfo;
	D2TLVertexStrc pVertices[4];
	int nScreenX;
	int nScreenY;

	if (!D3D_LoadSpriteInfo(pData, &tInfo))
	{
		return 0;
	}

	D3DSPRITE_SetTextureSize(&tInfo);

	const int nOffsetX = tInfo.nOffsetX << 11;
	const int nOffsetY = tInfo.nOffsetY << 12;
	nX += nOffsetY + nOffsetX;
	nY += nOffsetY - nOffsetX;
	const int nHeight = tInfo.nTexHeight << 12;
	const int nWidth = tInfo.nTexWidth << 11;
	const int nTopY = nY - nHeight;

	sub_006B9860_Project(nX - nHeight, nTopY, 0, &nScreenX, &nScreenY);
	pVertices[0].fX = (float)nScreenX;
	pVertices[0].fY = (float)nScreenY;
	pVertices[0].fZ = 0.5f;
	pVertices[0].fRhw = 1.0f;
	pVertices[0].fU = tInfo.fU0;
	pVertices[0].fV = tInfo.fV0;

	sub_006B9860_Project(nX, nY, 0, &nScreenX, &nScreenY);
	pVertices[1].fX = (float)nScreenX;
	pVertices[1].fY = (float)nScreenY;
	pVertices[1].fZ = 0.5f;
	pVertices[1].fRhw = 1.0f;
	pVertices[1].fU = tInfo.fU0;
	pVertices[1].fV = tInfo.fV1;

	sub_006B9860_Project(nX + nWidth, nY - nWidth, 0, &nScreenX, &nScreenY);
	pVertices[2].fX = (float)nScreenX;
	pVertices[2].fY = (float)nScreenY;
	pVertices[2].fZ = 0.5f;
	pVertices[2].fRhw = 1.0f;
	pVertices[2].fU = tInfo.fU1;
	pVertices[2].fV = tInfo.fV1;

	sub_006B9860_Project(nX + nWidth - nHeight, nTopY - nWidth, 0, &nScreenX, &nScreenY);
	pVertices[3].fX = (float)nScreenX;
	pVertices[3].fY = (float)nScreenY;
	pVertices[3].fZ = 0.5f;
	pVertices[3].fRhw = 1.0f;
	pVertices[3].fU = tInfo.fU1;
	pVertices[3].fV = tInfo.fV0;

	switch (nScreenMode)
	{
	case 1:
	{
		const float fShift = (float)(gnRenderWidth / 4);
		pVertices[0].fX -= fShift;
		pVertices[1].fX -= fShift;
		pVertices[2].fX -= fShift;
		pVertices[3].fX -= fShift;
		break;
	}
	case 2:
	{
		const float fShift = (float)(gnRenderWidth / 4);
		pVertices[0].fX += fShift;
		pVertices[1].fX += fShift;
		pVertices[2].fX += fShift;
		pVertices[3].fX += fShift;
		break;
	}
	}

	const int nScreenWidth = gnRenderWidth;
	const int nScreenHeight = gnRenderHeight - 47;
	if ((pVertices[0].fX >= 0.0f && pVertices[0].fX < nScreenWidth && pVertices[0].fY >= 0.0f && pVertices[0].fY < nScreenHeight)
		|| (pVertices[1].fX >= 0.0f && pVertices[1].fX < nScreenWidth && pVertices[1].fY >= 0.0f && pVertices[1].fY < nScreenHeight)
		|| (pVertices[2].fX >= 0.0f && pVertices[2].fX < nScreenWidth && pVertices[2].fY >= 0.0f && pVertices[2].fY < nScreenHeight)
		|| (pVertices[3].fX >= 0.0f && pVertices[3].fX < nScreenWidth && pVertices[3].fY >= 0.0f && pVertices[3].fY < nScreenHeight))
	{
		const unsigned char nAlpha = D3DSPRITE_SetBlendAndAlpha(eDrawMode);
		if (!D3DSPRITE_UploadTexture(&tInfo, 1, (int)pPalette, 0))
		{
			return 1;
		}

		D3DCORE_SetColorCombineMode(1);
		D3DCORE_SetTextureFilterMode(1);
		sub_006B9780_SetColor(pVertices, dwGamma, nAlpha);
		pVertices[1].dwColor = pVertices[0].dwColor;
		pVertices[2].dwColor = pVertices[0].dwColor;
		pVertices[3].dwColor = pVertices[0].dwColor;

		D2TLVertexStrc* pLocked;
		if (gpVertexBuffer->lpVtbl->Lock(gpVertexBuffer, 0x21, (void**)&pLocked, 0))
		{
			return 1;
		}

		pLocked += gnVertexBufferPos;
		memcpy(pLocked, pVertices, sizeof(pVertices));
		gpVertexBuffer->lpVtbl->Unlock(gpVertexBuffer);
		gpD3DDevice_00970E78->lpVtbl->DrawPrimitiveVB(gpD3DDevice_00970E78, 6, gpVertexBuffer, gnVertexBufferPos, 4, 0x1C);

		gnVertexBufferPos += 4;
		if (gnVertexBufferPos > 43)
		{
			gnVertexBufferPos = 0;
			return 1;
		}
	}

	return 1;
}

// 0x006B6B40
int __fastcall D3DSPRITE_CelDraw(D2GfxDataStrc* pContext, int nX, int nY, unsigned int nColor, int nBlendMode, int nArg)
{
    D2SpriteInfoStrc tInfo;

    if (!D3D_LoadSpriteInfo(pContext, &tInfo))
    {
        return 0;
    }

    const int nLeft = nX + tInfo.nOffsetX;
    if (nLeft > gnRenderWidth)
        return 0;
    if (nLeft + tInfo.nWidth < 0)
        return 0;
    const int nBottom = nY + tInfo.nOffsetY;
    if (nBottom < 0)
        return 0;
    if (nBottom - tInfo.nHeight >= gnRenderHeight)
        return 0;

    D3DSPRITE_SetTextureSize(&tInfo);
    unsigned char nAlpha = D3DSPRITE_SetBlendAndAlpha(nBlendMode);
    if (nBlendMode == 7)
    {
        if (D3DSPRITE_UploadTexture(&tInfo, 2, nArg, 0))
        {
            D3DSPRITE_DrawSpriteQuad(&tInfo, nX, nY, nColor, 0, nAlpha, 0);
        }
    }
    else
    {
        if (D3DSPRITE_UploadTexture(&tInfo, 1, nArg, 0))
        {
            D3DSPRITE_DrawSpriteQuad(&tInfo, nX, nY, nColor, 0, nAlpha, 0);
        }
    }
    return 1;
}

static int D3D_IsOnScreen(D2SpriteInfoStrc* pInfo, int nX, int nY)
{
    nX += pInfo->nOffsetX;
    if (nX > gnRenderWidth || nX + pInfo->nWidth < 0)
    {
        return 0;
    }

    nY += pInfo->nOffsetY;
    if (nY < 0 || nY - pInfo->nHeight >= gnRenderHeight)
    {
        return 0;
    }

    return 1;
}

// 0x006B6BF0
int __fastcall D3DSPRITE_CelDrawColor(D2GfxDataStrc* pContext, int nX, int nY, unsigned int nColor, int nBlendMode, int nPaletteIndex)
{
    D2SpriteInfoStrc tInfo;

    if (!D3D_LoadSpriteInfo(pContext, &tInfo))
    {
        return 0;
    }

    if (!D3D_IsOnScreen(&tInfo, nX, nY))
    {
        return 0;
    }

    D3DSPRITE_SetTextureSize(&tInfo);
    if (D3DSPRITE_UploadTexture(&tInfo, 1, 0, 0))
    {
        const unsigned char nAlpha = D3DSPRITE_SetBlendAndAlpha(nBlendMode);
        D3DSPRITE_DrawSpriteQuad(&tInfo, nX, nY, nColor, nPaletteIndex, nAlpha, 0);
    }

    return 1;
}

// 0x006B6C90
void __fastcall D3DSPRITE_DrawSpriteRows(D2GfxDataStrc* pContext, int nX, int nY, unsigned int nSkip, unsigned int nRows, int nBlendMode)
{
    D2SpriteInfoStrc tInfo;

    unsigned char nAlpha = D3DSPRITE_SetBlendAndAlpha(nBlendMode);
    if (!D3D_LoadSpriteInfo(pContext, &tInfo))
    {
        return;
    }

    D3DSPRITE_SetTextureSize(&tInfo);
    if (!D3DSPRITE_UploadTexture(&tInfo, 1, 0, 0))
    {
        return;
    }

    float fScale = 1.0f / (float)tInfo.nTexHeight;
    int nTexHeight = tInfo.nTexHeight;
    if (nSkip)
    {
        nY -= nSkip;
        unsigned int nBottom = nTexHeight - nSkip;
        tInfo.fV0 = (float)(nBottom - nRows) * fScale;
        tInfo.fV1 = (float)nBottom * fScale;
    }
    else
    {
        tInfo.fV0 = (float)(nTexHeight - nRows) * fScale;
    }

    tInfo.nTexHeight = nRows;
    D3DSPRITE_DrawSpriteQuad(&tInfo, nX, nY, 0xFFFFFFFF, 0, nAlpha, 0);
}

// 0x006B6D70
int __stdcall D3DSPRITE_ClipSprite(D2SpriteInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds, D2ClipStrc* pClip)
{
    nX += pInfo->nOffsetX;
    int nWidth = pInfo->nWidth;
    int nHeight = pInfo->nHeight;
    nY += pInfo->nOffsetY;

    pClip->nLeft = 0;
    pClip->nWidth = nWidth;
    pClip->nTop = 0;
    pClip->nHeight = nHeight;

    int nLeft = pBounds->nLeft > 0 ? pBounds->nLeft : 0;
    int nRight = pBounds->nRight < gnRenderWidth ? pBounds->nRight : gnRenderWidth;
    if (nLeft > nRight || nX >= nRight || nX + nWidth < nLeft)
    {
        return 1;
    }

    int nTop = pBounds->nTop + 2 > 0 ? pBounds->nTop + 2 : 0;
    int nBottom = pBounds->nBottom < gnRenderHeight ? pBounds->nBottom : gnRenderHeight;
    if (nTop > nBottom || nY < nTop || nY - nHeight > nBottom)
    {
        return 1;
    }

    if (nX >= nLeft)
        pClip->nLeft = 0;
    else
        pClip->nLeft = nLeft - nX;

    if (nX + nWidth < nRight)
        pClip->nWidth = nWidth - pClip->nLeft;
    else
        pClip->nWidth = nRight - pClip->nLeft - nX;

    if (nY <= nBottom)
        pClip->nTop = 0;
    else
        pClip->nTop = nY - nBottom - 1;

    if (nY - nHeight >= nTop)
        pClip->nHeight = nHeight - pClip->nTop;
    else
        pClip->nHeight = nY - pClip->nTop - nTop + 1;

    if (pClip->nHeight <= 0)
    {
        FOG_DisplayHalt(gszEmptyString, sub_00408090(), 1114);
        exit(-1);
    }
    return 0;
}

// 0x006B6EE0
void __fastcall D3DSPRITE_DrawSpriteClipped(D2GfxDataStrc* pContext, int nX, int nY, const D2BoundsStrc* pBounds, int nBlendMode)
{
    D2SpriteInfoStrc tInfo;
    D2ClipStrc tClip;

    unsigned char nAlpha = D3DSPRITE_SetBlendAndAlpha(nBlendMode);
    if (!D3D_LoadSpriteInfo(pContext, &tInfo))
    {
        return;
    }

    D3DSPRITE_SetTextureSize(&tInfo);
    if (!D3DSPRITE_UploadTexture(&tInfo, 1, 0, 0))
    {
        return;
    }

    if (D3DSPRITE_ClipSprite(&tInfo, nX, nY, pBounds, &tClip))
    {
        return;
    }

    float fScaleV = 1.0f / (float)tInfo.nTexHeight;
    float fScaleU = 1.0f / (float)tInfo.nTexWidth;
    if (tClip.nTop)
    {
        tInfo.fV0 = (float)(tInfo.nTexHeight - tClip.nHeight - tClip.nTop) * fScaleV;
        nY -= tClip.nTop;
        tInfo.fV1 = (float)(tInfo.nTexHeight - tClip.nTop) * fScaleV;
    }
    else
    {
        tInfo.fV0 = (float)(tInfo.nTexHeight - tClip.nHeight) * fScaleV;
    }
    tInfo.nTexHeight = tClip.nHeight;

    if (tClip.nLeft)
    {
        nX += tClip.nLeft;
        tInfo.fU0 = (float)tClip.nLeft * fScaleU;
        tInfo.fU1 = (float)(tClip.nLeft + tClip.nWidth) * fScaleU;
    }
    else
    {
        tInfo.fU1 = (float)tClip.nWidth * fScaleU;
    }
    tInfo.nTexWidth = tClip.nWidth;

    D3DSPRITE_DrawSpriteQuad(&tInfo, nX, nY, 0xFFFFFFFF, 0, nAlpha, 0);
}

// 0x006B7000
void __fastcall D3DSPRITE_DrawSpriteShadow(D2GfxDataStrc* pContext, int nX, int nY)
{
    D2SpriteInfoStrc tInfo;
    unsigned char nAlpha = 255;

    if (!D3D_LoadSpriteInfo(pContext, &tInfo))
    {
        return;
    }

    D3DSPRITE_SetTextureSize(&tInfo);
    if (!D3DSPRITE_UploadTexture(&tInfo, 4, 0, 0))
    {
        return;
    }

    D3DCORE_SetColorCombineMode(1);
    if (sub_006B77A0_GetBlendedShadows())
    {
        D3DCORE_SetAlphaBlendMode(4);
        nAlpha = 192;
    }
    else
    {
        D3DCORE_SetAlphaBlendMode(1);
    }
    D3DCORE_SetTextureFilterMode(1);
    D3DSPRITE_DrawTexturedQuad(nX, nY, nAlpha, (D2SpriteQuad006B61A0Strc*)&tInfo);
}

// 0x006B7090
int __fastcall D3DSPRITE_CelDrawHilight(D2GfxDataStrc* pContext, int nX, int nY, int nArg)
{
    D2SpriteInfoStrc tInfo;

    D3DCORE_SetAlphaBlendMode(4);
    int nResult = D3D_LoadSpriteInfo(pContext, &tInfo);
    if (nResult)
    {
        tInfo.nWidth += 2;
        tInfo.nHeight += 2;
        D3DSPRITE_SetTextureSize(&tInfo);
        nResult = D3DSPRITE_UploadTexture(&tInfo, 3, 0, nArg);
        if (nResult)
        {
            nResult = D3DSPRITE_DrawSpriteQuad(&tInfo, nX - 1, nY + 1, 0xFFFFFFFF, 0, 0x40, 1);
        }
    }
    return nResult;
}

// calling-convention shim (not game code)
int __fastcall sub_006B6700_Shim(D2GlideRectViewStrc* pRect, int nA, int nB)
{
    int n = nA * 3;
    n += D3DSPRITE_IsOutsideScreen(nA, nB, pRect);
    return n;
}

// 0x006B7100
void __cdecl D3DSPRITE_DebugFillBackBuffer()
{
}

void* gpTexture_00970F1C; // 0x00970F1C

void* gpSpriteTexture128; // 0x00970F20

void* gpSpriteTexture32; // 0x00970F24

void* gpSurface_00970F28; // 0x00970F28

void* gpSpriteSurface128; // 0x00970F2C

void* gpSpriteSurface32; // 0x00970F30

// 0x006B7110
void __cdecl D3DSPRITE_InitSprites()
{
    D2_ASSERT(!gpSpriteBuffer, 0x55);
    D2_ASSERT(!gpSpriteOutlineBuffer, 0x56);
    gpSpriteBuffer = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x57, 0);
    gpSpriteOutlineBuffer = FOG_Alloc(0x10000, ".\\Src\\d3dSprite.cpp", 0x58, 0);
    D2_ASSERT(D3DCORE_CreateMemoryTexture(&gpSurface_00970F28, &gpTexture_00970F1C, 0x100, 0x100), 0x5E);
    D2_ASSERT(D3DCORE_CreateMemoryTexture(&gpSpriteSurface128, &gpSpriteTexture128, 0x80, 0x80), 0x61);
    D2_ASSERT(D3DCORE_CreateMemoryTexture(&gpSpriteSurface32, &gpSpriteTexture32, 0x20, 0x20), 0x64);

    D2VertexBufferDescStrc tDesc = { sizeof(tDesc) };
    tDesc.dwCaps = 0x10800;
    tDesc.dwFVF = 0x1C4;
    tDesc.dwNumVertices = 0x30;
    const long nResult = gpDirect3D3->lpVtbl->CreateVertexBuffer(gpDirect3D3, &tDesc, (void**)&gpVertexBuffer, 4, 0);
    if (nResult)
    {
        D3DCORE_ShowD3DError("CreateVertexBuffer failed!", nResult);
        return;
    }

    gnVertexBufferPos = 0;
    CelSetHardwareFreeCallback(D3DSPRITE_ClearResourceEntries);
}
extern "C" const char gData_006FC26C[24] = "Failed to set texture"; // 0x006FC26C
#pragma comment(linker, "/alternatename:_gszSetTextureFailed=_gData_006FC26C")
