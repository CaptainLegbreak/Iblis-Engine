#include "D2Glide.h"
#include "D2CelContext.h"

struct D2GlideTexDimsStrc;

extern int gnRenderWidth; // 0x007C9138

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0

void* __stdcall CelGetHardwareData(D2CelStrc* pCel); // 0x00601B10

void __fastcall GLCORE_SetTextureCombineMode(int nTmu); // 0x00509460

void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0

void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500

void __fastcall GLCORE_SetTextureFilterMode(int nMode); // 0x005095D0

int __cdecl sub_0050BF40_GlideGetBlendedShadows(); // 0x0050BF40

void __fastcall GLVERTEX_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor); // 0x0050DC30

int __cdecl GLVERTEX_IsPerspective(); // 0x0050DD30

void __fastcall GLPERSPECTIVE_PerspectiveTransform(int nX, int nY, int nZ, int* pScreenX, int* pScreenY); // 0x0050DD60

void __fastcall GLTEXTURECACHE_TexCacheTouch(D2GlideTexCacheStrc* pCache, int nId); // 0x0050EBE0

int __fastcall GLTEXTURECACHE_TexCacheAdd(D2GlideTexCacheStrc* pList); // 0x0050ED10

void (__stdcall* gpfnGrTexDownloadMipMap)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);        // 0x0087EAB8

extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98

extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4

int gbGlideSpriteFlag;                                                                             // 0x0087EFF0

int gbGlideMultiTmu;                                                                               // 0x0087EFF4

extern D2GlideSpriteVertexStrc gatGlideSpriteVertices[4]; // 0x0087EFF8

extern D2GlideTexCacheStrc gaGlideTexCaches[4]; // 0x0087F048

extern unsigned char* gpGlideSpriteBufferA; // 0x0087F0C8

extern unsigned char* gpGlideSpriteBufferB_0087F0CC; // 0x0087F0CC

extern int gnGlideSpriteScale; // 0x00880B64

extern D2GlideTexDimsStrc gaGlideAspectTexDims[7]; // 0x0072F278

void* gpGlideBuffer_0087F0C8; // 0x0087F0C8

void* gpGlideSpriteBufferB; // 0x0087F0CC

static int GLSPRITE_InitTexInfo(D2CelContextStrc* pContext, D2GlideTexInfoStrc* pInfo); // 0x0050A260

typedef void (__stdcall* gpfGlideTexDownloadMipMap_0087EAB8_t)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);

typedef void (__stdcall* gpfGlideTexSource_0087EB98_t)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo);

typedef void (__stdcall* gpfGlideDrawVertexArrayContiguous_0087EAC4_t)(int nMode, int nCount, void* pVertices, int nStride);

typedef void (__stdcall* gpfGlideAlphaFunction_0087EAB4_t)(int nFunction);

typedef void (__stdcall* gpfGlideConstantColor_0087EFA0_t)(unsigned int dwColor);

static void __stdcall GLSPRITE_DrawSpriteQuad(int nX, int nY, unsigned int dwColor, int bTinted, D2GlideTexInfoStrc* pInfo, int nPaletteIndex); // 0x0050A9A0

static void GLSPRITE_SetSpriteBlendMode(int nMode); // 0x0050ABF0

static int __stdcall GLSPRITE_ClipSprite(D2GlideTexInfoStrc* pInfo, int nY, const D2BoundsStrc* pBounds, int nX, D2ClipStrc* pClip); // 0x0050B390

static int __stdcall GLSPRITE_UploadTexInfo(int nPalette, int nColor, int nType, D2GlideTexInfoStrc* pInfo); // 0x0050A450

typedef void (__stdcall* PFNGLIDEDRAWVERTEXARRAY)(int nMode, int nCount, void* pVertices, int nStride);

typedef void (__stdcall* PFNGLIDEALPHAFUNCTION)(int nFunction);

struct D2GlideAspectScaleStrc
{
	int nScaleS;
	int nScaleT;
};

extern D2GlideAspectScaleStrc gatGlideAspectScale[];                                                 // 0x0072F290

extern void (__stdcall* gpfnGrDrawVertexArrayContiguous_0087EAC4)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4

extern void (__stdcall* gpfnGrGlideState_0087EAB4)(int nState);                                             // 0x0087EAB4

extern D2GlideSpriteVertexStrc gGlideVertices_0087EFF8[4];                                                        // 0x0087EFF8

static int GLSPRITE_InitTexInfo(D2CelContextStrc* pData, D2GlideTexInfoStrc* pInfo); // 0x0050A260

static void GLSPRITE_SetupTexInfoSize(D2GlideTexInfoStrc* pInfo);             // 0x0050A2D0

static int __stdcall GLSPRITE_ClipSprite(D2GlideTexInfoStrc* pInfo, int nY, const D2BoundsStrc* pBounds, int nX, D2ClipStrc* pClip); // 0x0050B390

typedef void (__fastcall* PixelDataFreeCallback)(void* pData);

int __cdecl GLCORE_GetFloorTilesFlag();                                                                                  // 0x00509650

void __fastcall sub_0050A110_GlideFreeCelData(void* pData);                                                 // 0x0050A110

void __stdcall CelSetHardwareFreeCallback(PixelDataFreeCallback pfnCallback); // 0x00601A30

extern D2GrTexInfoStrc gtGlideSmackTexInfoA;                                                        // 0x0072F680

extern D2GrTexInfoStrc gtGlideSmackTexInfoB;                                                        // 0x0072F694

extern D2GfxSettingsStrc* gpGfxSettings;                                                           // 0x007C9148

extern int gnGlideTmuCount;                                                                        // 0x0087EFB4

extern unsigned char* gpGlideSmackBufferB;                                                          // 0x00880B70

extern unsigned char* gpGlideSmackBufferC;                                                          // 0x00880B74

int gnGlideSmackTexAddrA;                                                                          // 0x00880BE8

int gnGlideSmackTexAddrB;                                                                          // 0x00880BEC

extern int gnGlideSmackTmu;                                                                        // 0x00880BF4

// 0x0050A0C0
void __cdecl GLSPRITE_FreeSpriteBuffers()
{
    if (gpGlideBuffer_0087F0C8)
    {
        FOG_Free(gpGlideBuffer_0087F0C8, ".\\Src\\glSprite.cpp", 0x74, 0);
        gpGlideBuffer_0087F0C8 = 0;
    }
    if (gpGlideSpriteBufferB)
    {
        FOG_Free(gpGlideSpriteBufferB, ".\\Src\\glSprite.cpp", 0x7A, 0);
        gpGlideSpriteBufferB = 0;
    }
}

// 0x0050A1E0
static inline int GLSPRITE_RoundTexSize(int nSize)
{
    if (nSize > 128)
        return 256;
    if (nSize > 64)
        return 128;
    if (nSize > 32)
        return 64;
    if (nSize > 16)
        return 32;
    return nSize > 8 ? 16 : 8;
}

// 0x0050A220
static inline int GLSPRITE_GetTexSizeExponent(int nSize)
{
    if (nSize == 256)
        return 8;
    if (nSize == 128)
        return 7;
    if (nSize == 64)
        return 6;
    if (nSize == 32)
        return 5;
    return nSize == 16 ? 4 : 3;
}

void (__stdcall* gpfnGrDitherMode)(int nFunction); // 0x0087EAB4

void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0

// 0x0050A260
static int GLSPRITE_InitTexInfo(D2CelContextStrc* pContext, D2GlideTexInfoStrc* pInfo)
{
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    D2_ASSERT(pContext->pCel, 0xCE);

    pInfo->pContext = pContext;
    pInfo->nWidth = CelGetWidth(pContext->pCel);
    pInfo->nOffsetX = CelGetOffsetX(pContext->pCel);
    pInfo->nHeight = CelGetHeight(pContext->pCel);
    pInfo->nOffsetY = CelGetOffsetY(pContext->pCel);
    return 1;
}

// 0x0050A2D0
static void GLSPRITE_SetupTexInfoSize(D2GlideTexInfoStrc* pInfo)
{
    int nTexWidth;
    if (pInfo->nWidth > 0x80)
        nTexWidth = 0x100;
    else if (pInfo->nWidth > 0x40)
        nTexWidth = 0x80;
    else if (pInfo->nWidth > 0x20)
        nTexWidth = 0x40;
    else if (pInfo->nWidth > 0x10)
        nTexWidth = 0x20;
    else
        nTexWidth = pInfo->nWidth > 8 ? 0x10 : 8;
    pInfo->nTexWidth = nTexWidth;

    int nTexHeight;
    if (pInfo->nHeight > 0x80)
        nTexHeight = 0x100;
    else if (pInfo->nHeight > 0x40)
        nTexHeight = 0x80;
    else if (pInfo->nHeight > 0x20)
        nTexHeight = 0x40;
    else if (pInfo->nHeight > 0x10)
        nTexHeight = 0x20;
    else
        nTexHeight = pInfo->nHeight > 8 ? 0x10 : 8;
    pInfo->nTexHeight = nTexHeight;

    const int nMax = nTexWidth > nTexHeight ? nTexWidth : nTexHeight;
    int nLod;
    if (nMax == 0x100)
        nLod = 8;
    else if (nMax == 0x80)
        nLod = 7;
    else if (nMax == 0x40)
        nLod = 6;
    else if (nMax == 0x20)
        nLod = 5;
    else
        nLod = (nMax == 0x10) + 3;
    pInfo->nLod = nLod;

    if (nTexWidth == nTexHeight)
    {
        pInfo->nAspect = 0;
    }
    else if (nTexWidth < nTexHeight)
    {
        int i;
        for (i = 0; i < 3; ++i)
        {
            nTexWidth += nTexWidth;
            if (nTexWidth > nTexHeight)
                break;
        }
        pInfo->nTexWidth = nTexHeight >> i;
// build: symbol ?gaGlideAspectLodTall@* 0x0072F258
        pInfo->nAspect = gaGlideAspectLodTall[i];
    }
    else
    {
        int i;
        for (i = 0; i < 3; ++i)
        {
            nTexHeight += nTexHeight;
            if (nTexHeight > nTexWidth)
                break;
        }
        pInfo->nTexHeight = nTexWidth >> i;
// build: symbol ?gaGlideAspectLodWide@* 0x0072F268
        pInfo->nAspect = gaGlideAspectLodWide[i];
    }

    if (!GLVERTEX_IsPerspective())
    {
        pInfo->fS0 = 0.0f;
        pInfo->fS1 = (float)pInfo->nWidth / pInfo->nTexWidth;
        pInfo->fT0 = 1.0f - (float)pInfo->nHeight / pInfo->nTexHeight;
        pInfo->fT1 = 1.0f;
    }
    else
    {
        pInfo->fS0 = 0.0f;
        pInfo->fS1 = 1.0f;
        pInfo->fT0 = 0.0f;
        pInfo->fT1 = 1.0f;
    }
    pInfo->nTexSize = pInfo->nTexHeight * pInfo->nTexWidth;
}

static void GLSPRITE_SetSpriteBlendMode(int nMode); // 0x0050ABF0

// 0x0050A450
static int __stdcall GLSPRITE_UploadTexInfo(int nPalette, int nColor, int nType, D2GlideTexInfoStrc* pInfo)
{
    D2CelStrc* pCell = pInfo->pContext->pCel;
    D2_ASSERT(pCell, 0x12D);

    D2GlideTexSlotStrc* pSlots = (D2GlideTexSlotStrc*)CelGetHardwareData(pCell);
    const int nRequested = nType;
    if (nType == 4)
        nType = 1;

    D2GrTexInfoStrc tTexInfo;
    tTexInfo.nSmallLodLog2 = tTexInfo.nLargeLodLog2 = pInfo->nLod;
    tTexInfo.nAspectRatioLog2 = pInfo->nAspect;
    tTexInfo.nFormat = 5;
    tTexInfo.pData = gpGlideSpriteBufferA;

    D2GlideTexSlotStrc* pSlot = &pSlots[nType];
    if (!pSlot->nCache)
    {
        if (pInfo->nTexSize <= 0x1000)
            pSlot->nCache = 3;
        else if (pInfo->nTexSize <= 0x4000)
            pSlot->nCache = 2;
        else if (pInfo->nTexSize <= 0x10000)
            pSlot->nCache = 1;
        else
            return 0;
    }

    const int nCache = pSlot->nCache;
    D2GlideTexCacheStrc* pCache = &gaGlideTexCaches[nCache];
    if (gbGlideSpriteFlag)
        gbGlideMultiTmu = nCache == 1;

    int nAddress;
    if (pSlots[nType].nId && (pCache->pEntries[pSlots[nType].nId - 1].nPalette == nPalette || nRequested == 4))
    {
        GLTEXTURECACHE_TexCacheTouch(&gaGlideTexCaches[nCache], pSlot->nId);
        nAddress = pCache->pEntries[pSlot->nId - 1].nAddress;
    }
    else
    {
        if (!pSlot->nId)
            pSlot->nId = GLTEXTURECACHE_TexCacheAdd(pCache);

        pCache->pEntries[pSlot->nId - 1].pOwner = pSlots;
        pCache->pEntries[pSlot->nId - 1].nOwnerIndex = nType;
        pCache->pEntries[pSlot->nId - 1].nPalette = nPalette;
        nAddress = pCache->pEntries[pSlot->nId - 1].nAddress;

        unsigned char* pBuffer = gpGlideSpriteBufferA;
        D2_ASSERT(pBuffer, 0x184);
        D2_ASSERT(pInfo->nTexSize <= 0x10000, 0x185);
        memset(pBuffer, 0, pInfo->nTexSize);

        switch (nType)
        {
        case 1:
        case 4:
            CelDraw(pInfo->pContext, -pInfo->nOffsetX, pInfo->nTexHeight - pInfo->nOffsetY - 1, 0, 0, pBuffer, pInfo->nTexHeight, pInfo->nTexWidth, 0, 0, nPalette);
            break;

        case 2:
        {
            CelDraw(pInfo->pContext, -pInfo->nOffsetX, pInfo->nTexHeight - pInfo->nOffsetY - 1, 0, 0, pBuffer, pInfo->nTexHeight, pInfo->nTexWidth, 0, 0, nPalette);
            unsigned char* pPixel = gpGlideSpriteBufferA;
            unsigned char* pRemap = gpGfxPaletteView_007C9150->pRemap;
            for (int i = 0; i < pInfo->nTexSize; ++i)
            {
                if (*pPixel)
                    *pPixel = pRemap[*pPixel];
                ++pPixel;
            }
            break;
        }

        case 3:
        {
            CelDraw(pInfo->pContext, 1 - pInfo->nOffsetX, pInfo->nTexHeight - pInfo->nOffsetY - 2, 0, 0, pBuffer, pInfo->nTexHeight, pInfo->nTexWidth, 0, 0, 0);
            unsigned char* pOutline = gpGlideSpriteBufferB_0087F0CC;
            D2_ASSERT(pOutline, 0x1AD);
            D2_ASSERT(pInfo->nTexSize <= 0x10000, 0x1AE);
            memset(pOutline, 0, pInfo->nTexSize);

            unsigned char* pSrc = gpGlideSpriteBufferA + pInfo->nTexWidth;
            unsigned char* pDst = pOutline + pInfo->nTexWidth;
            const int nPitch = pInfo->nTexWidth;
            const int nCount = pInfo->nTexSize - 2 * nPitch;
            for (int i = 0; i < nCount; ++i)
            {
                if (*pSrc++)
                {
                    pDst[-pInfo->nTexWidth] = (unsigned char)nColor;
                    pDst[-1] = (unsigned char)nColor;
                    pDst[1] = (unsigned char)nColor;
                    pDst[pInfo->nTexWidth] = (unsigned char)nColor;
                }
                ++pDst;
            }
            tTexInfo.pData = pOutline;
            break;
        }
        }

        gpfnGrTexDownloadMipMap(gbGlideMultiTmu, nAddress, 3, &tTexInfo);
    }

    gpfnGrTexSource(gbGlideMultiTmu, nAddress, 3, &tTexInfo);
    GLCORE_SetTextureCombineMode(gbGlideMultiTmu);
    return 1;
}

// 0x0050A7B0
static void __stdcall GLSPRITE_DrawIsoQuad(int nX, int nY, D2GlideTexInfoStrc* pInfo)
{
    const int nDimIndex = pInfo->nAspect + 3;
    int nTexW = gaGlideAspectTexDims[nDimIndex].nWidth;
    int nTexH = gaGlideAspectTexDims[nDimIndex].nHeight;
    const float fS0 = pInfo->fS0 * nTexW;
    const float fS1 = pInfo->fS1 * nTexW;
    const float fT0 = pInfo->fT0 * nTexH;
    const float fT1 = pInfo->fT1 * nTexH;

    const int bPerspective = GLVERTEX_IsPerspective();
    int nWidth;
    int nHeight;
    if (!bPerspective)
    {
        nWidth = pInfo->nWidth;
        nHeight = pInfo->nHeight;
    }
    else
    {
        nWidth = pInfo->nTexWidth;
        nHeight = pInfo->nTexHeight;
    }

    pInfo->nOffsetY >>= 1;
    nHeight >>= 1;
    int nLeft = pInfo->nOffsetX + pInfo->nOffsetY;
    int nTop = pInfo->nOffsetY - nHeight;
    if (bPerspective && gnGlideSpriteScale != 0x100)
    {
        nLeft = nLeft * gnGlideSpriteScale / 0x100;
        nTop = nTop * gnGlideSpriteScale / 0x100;
        nWidth = nWidth * gnGlideSpriteScale / 0x100;
        nHeight = nHeight * gnGlideSpriteScale / 0x100;
    }

    const int nX0 = nX + nLeft;
    const int nY0 = nY + nTop;
    const float fXA = (float)(nX0 - nHeight);
    const float fY0 = (float)nY0;
    const float fXB = (float)nX0;
    const float fY1 = (float)(nY0 + nHeight);
    const float fXC = (float)(nX0 + nWidth);
    const float fXD = (float)(nX0 - nHeight + nWidth);

    gatGlideSpriteVertices[0].x = fXA;
    gatGlideSpriteVertices[0].y = fY0;
    gatGlideSpriteVertices[0].oow = 1.0f;
    gatGlideSpriteVertices[0].sow = fS0;
    gatGlideSpriteVertices[0].tow = fT0;
    gatGlideSpriteVertices[1].x = fXB;
    gatGlideSpriteVertices[1].y = fY1;
    gatGlideSpriteVertices[1].oow = 1.0f;
    gatGlideSpriteVertices[1].sow = fS0;
    gatGlideSpriteVertices[1].tow = fT1;
    gatGlideSpriteVertices[2].x = fXC;
    gatGlideSpriteVertices[2].y = fY1;
    gatGlideSpriteVertices[2].oow = 1.0f;
    gatGlideSpriteVertices[2].sow = fS1;
    gatGlideSpriteVertices[2].tow = fT1;
    gatGlideSpriteVertices[3].x = fXD;
    gatGlideSpriteVertices[3].y = fY0;
    gatGlideSpriteVertices[3].oow = 1.0f;
    gatGlideSpriteVertices[3].sow = fS1;
    gatGlideSpriteVertices[3].tow = fT0;
    gatGlideSpriteVertices[0].dwColor = 0;
    gatGlideSpriteVertices[1].dwColor = 0;
    gatGlideSpriteVertices[2].dwColor = 0;
    gatGlideSpriteVertices[3].dwColor = 0;
    gpfnGrDrawVertexArrayContiguous(5, 4, gatGlideSpriteVertices, sizeof(D2GlideSpriteVertexStrc));
}

// 0x0050A9A0
static void __stdcall GLSPRITE_DrawSpriteQuad(int nX, int nY, unsigned int dwColor, int bTinted, D2GlideTexInfoStrc* pInfo, int nPaletteIndex)
{
    GLCORE_SetColorCombineMode(1);
    GLCORE_SetTextureFilterMode(1);

    if (!nPaletteIndex && !bTinted)
    {
        GLVERTEX_SetVertexColor(gatGlideSpriteVertices, dwColor);
    }
    else
    {
        gatGlideSpriteVertices[0].dwColor = ((gpGfxPaletteView_007C9150->pStandardColorsPalette[nPaletteIndex * 3] | 0xFFFFFF00) << 8
            | gpGfxPaletteView_007C9150->pStandardColorsPalette[nPaletteIndex * 3 + 1]) << 8 | gpGfxPaletteView_007C9150->pStandardColorsPalette[nPaletteIndex * 3 + 2];
    }
    gatGlideSpriteVertices[3].dwColor = gatGlideSpriteVertices[0].dwColor;
    gatGlideSpriteVertices[2].dwColor = gatGlideSpriteVertices[0].dwColor;
    gatGlideSpriteVertices[1].dwColor = gatGlideSpriteVertices[0].dwColor;

    const int nDimIndex = pInfo->nAspect + 3;
    int nTexW = gaGlideAspectTexDims[nDimIndex].nWidth;
    int nTexH = gaGlideAspectTexDims[nDimIndex].nHeight;
    const float fS0 = pInfo->fS0 * nTexW;
    const float fS1 = pInfo->fS1 * nTexW;
    const float fT0 = pInfo->fT0 * nTexH;
    const float fT1 = pInfo->fT1 * nTexH;

    const int bPerspective = GLVERTEX_IsPerspective();
    int nWidth;
    int nHeight;
    if (!bPerspective)
    {
        nWidth = pInfo->nWidth;
        nHeight = pInfo->nHeight;
    }
    else
    {
        nWidth = pInfo->nTexWidth;
        nHeight = pInfo->nTexHeight;
    }

    int nLeft = pInfo->nOffsetX;
    int nTop = pInfo->nOffsetY - nHeight;
    if (bPerspective && gnGlideSpriteScale != 0x100)
    {
        nLeft = nLeft * gnGlideSpriteScale / 0x100;
        nTop = nTop * gnGlideSpriteScale / 0x100;
        nWidth = nWidth * gnGlideSpriteScale / 0x100;
        nHeight = nHeight * gnGlideSpriteScale / 0x100;
    }

    const int nX0 = nX + nLeft;
    const float fX0 = (float)nX0;
    const float fX1 = (float)(nX0 + nWidth);
    const int nY0 = nY + nTop;
    const float fY0 = (float)nY0;
    const float fY1 = (float)(nY0 + nHeight);

    gatGlideSpriteVertices[0].x = fX0;
    gatGlideSpriteVertices[0].y = fY0;
    gatGlideSpriteVertices[0].oow = 1.0f;
    gatGlideSpriteVertices[0].sow = fS0;
    gatGlideSpriteVertices[0].tow = fT0;
    gatGlideSpriteVertices[1].x = fX0;
    gatGlideSpriteVertices[1].y = fY1;
    gatGlideSpriteVertices[1].oow = 1.0f;
    gatGlideSpriteVertices[1].sow = fS0;
    gatGlideSpriteVertices[1].tow = fT1;
    gatGlideSpriteVertices[2].x = fX1;
    gatGlideSpriteVertices[2].y = fY1;
    gatGlideSpriteVertices[2].oow = 1.0f;
    gatGlideSpriteVertices[2].sow = fS1;
    gatGlideSpriteVertices[2].tow = fT1;
    gatGlideSpriteVertices[3].x = fX1;
    gatGlideSpriteVertices[3].y = fY0;
    gatGlideSpriteVertices[3].oow = 1.0f;
    gatGlideSpriteVertices[3].sow = fS1;
    gatGlideSpriteVertices[3].tow = fT0;
    gpfnGrDrawVertexArrayContiguous(5, 4, gatGlideSpriteVertices, sizeof(D2GlideSpriteVertexStrc));
    gpfnGrDitherMode(2);
}

void __fastcall sub_leg345d_Emit_0050A9A0(D2GlideTexInfoStrc* pInfo, int nX, int nY, unsigned int dwColor, int nMode, int nPaletteIndex)
{
    D2GlideTexInfoStrc tInfo = *pInfo;
    if (nMode == 1)
        GLSPRITE_DrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, nPaletteIndex);
    else if (nMode == 2)
        GLSPRITE_DrawSpriteQuad(nX - 1, nY + 1, -1, 1, &tInfo, 0);
    else
        GLSPRITE_DrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, 0);
}

static void GLSPRITE_SetupTexInfoSize(D2GlideTexInfoStrc* pInfo); // 0x0050A2D0

static int __stdcall GLSPRITE_UploadTexInfo(int nPalette, int nColor, D2GlideTexInfoStrc* pInfo, int nType); // 0x0050A450

static void __stdcall GLSPRITE_DrawIsoQuad(int nX, int nY, D2GlideTexInfoStrc* pInfo); // 0x0050A7B0

static void __stdcall GLSPRITE_DrawSpriteQuad(int nX, int nY, unsigned int dwColor, int bTinted, D2GlideTexInfoStrc* pInfo, int nPaletteIndex); // 0x0050A9A0

// 0x0050ABF0
static void GLSPRITE_SetSpriteBlendMode(int nMode)
{
    switch (nMode)
    {
    case 5:
    case 7:
        GLCORE_SetAlphaBlendMode(1);
        break;

    case 3:
        GLCORE_SetAlphaBlendMode(2);
        gpfnGrConstantColorValue(0xFF);
        gpfnGrDitherMode(0);
        break;

    case 4:
        GLCORE_SetAlphaBlendMode(3);
        gpfnGrConstantColorValue(0xFF);
        gpfnGrDitherMode(0);
        break;

    default:
        GLCORE_SetAlphaBlendMode(4);
        gpfnGrDitherMode(0);
        if (nMode == 0)
            gpfnGrConstantColorValue(0x40);
        else if (nMode == 1)
            gpfnGrConstantColorValue(0x80);
        else if (nMode == 2)
            gpfnGrConstantColorValue(0xC0);
        break;
    }
}

// 0x0050AC90
static inline int GLSPRITE_IsOutsideScreen(int nX, int nY, D2GlideRectViewStrc* pRect)
{
    nX += pRect->nOffsetX;
// build: symbol ?gnRenderHeight@* 0x007C913C
    if (nX > gnRenderWidth || pRect->nLeft + nX < 0 || (nY += pRect->nOffsetY) < 0 || nY - pRect->nTop >= gnRenderHeight)
        return 1;
    return 0;
}

// 0x0050ACC0
int __fastcall GLSPRITE_CelFlatSpriteDraw(D2CelContextStrc* pData, int nX, int nY, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette)
{
	D2GlideTexInfoStrc tInfo;
	int nScreenX;
	int nScreenY;

	if (!GLSPRITE_InitTexInfo(pData, &tInfo))
	{
		return 0;
	}

	GLSPRITE_SetupTexInfoSize(&tInfo);

	const int nScaleS = gatGlideAspectScale[tInfo.nAspect].nScaleS;
	const int nScaleT = gatGlideAspectScale[tInfo.nAspect].nScaleT;
	const float fS0 = nScaleS * tInfo.fS0;
	const float fS1 = nScaleS * tInfo.fS1;
	const float fT0 = nScaleT * tInfo.fT0;
	const float fT1 = nScaleT * tInfo.fT1;

	int nWidth;
	int nHeight;
	if (!GLVERTEX_IsPerspective())
	{
		nWidth = tInfo.nWidth << 11;
		nHeight = tInfo.nHeight << 12;
	}
	else
	{
		nWidth = tInfo.nTexWidth << 11;
		nHeight = tInfo.nTexHeight << 12;
	}

	const int nOffsetX = tInfo.nOffsetX << 11;
	const int nOffsetY = tInfo.nOffsetY << 12;
	nX += nOffsetY + nOffsetX;
	nY += nOffsetY - nOffsetX;

	GLPERSPECTIVE_PerspectiveTransform(nX - nHeight, nY - nHeight, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[0].x = (float)nScreenX;
	gGlideVertices_0087EFF8[0].y = (float)nScreenY;
	gGlideVertices_0087EFF8[0].oow = 1.0f;
	gGlideVertices_0087EFF8[0].sow = fS0;
	gGlideVertices_0087EFF8[0].tow = fT0;

	GLPERSPECTIVE_PerspectiveTransform(nX, nY, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[1].x = (float)nScreenX;
	gGlideVertices_0087EFF8[1].y = (float)nScreenY;
	gGlideVertices_0087EFF8[1].oow = 1.0f;
	gGlideVertices_0087EFF8[1].sow = fS0;
	gGlideVertices_0087EFF8[1].tow = fT1;

	GLPERSPECTIVE_PerspectiveTransform(nX + nWidth, nY - nWidth, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[2].x = (float)nScreenX;
	gGlideVertices_0087EFF8[2].y = (float)nScreenY;
	gGlideVertices_0087EFF8[2].oow = 1.0f;
	gGlideVertices_0087EFF8[2].sow = fS1;
	gGlideVertices_0087EFF8[2].tow = fT1;

	GLPERSPECTIVE_PerspectiveTransform(nX + nWidth - nHeight, nY - nHeight - nWidth, 0, &nScreenX, &nScreenY);
	gGlideVertices_0087EFF8[3].x = (float)nScreenX;
	gGlideVertices_0087EFF8[3].y = (float)nScreenY;
	gGlideVertices_0087EFF8[3].oow = 1.0f;
	gGlideVertices_0087EFF8[3].sow = fS1;
	gGlideVertices_0087EFF8[3].tow = fT0;

	const int nShift = gnRenderWidth / 4;
	if (nScreenMode == 1)
	{
		const float fShift = (float)nShift;
		gGlideVertices_0087EFF8[0].x -= fShift;
		gGlideVertices_0087EFF8[1].x -= fShift;
		gGlideVertices_0087EFF8[2].x -= fShift;
		gGlideVertices_0087EFF8[3].x -= fShift;
	}
	else if (nScreenMode == 2)
	{
		const float fShift = (float)nShift;
		gGlideVertices_0087EFF8[0].x += fShift;
		gGlideVertices_0087EFF8[1].x += fShift;
		gGlideVertices_0087EFF8[2].x += fShift;
		gGlideVertices_0087EFF8[3].x += fShift;
	}

	const int nScreenWidth = gnRenderWidth;
	const int nScreenHeight = gnRenderHeight - 47;
	if ((gGlideVertices_0087EFF8[0].x >= 0.0f && gGlideVertices_0087EFF8[0].x < nScreenWidth && gGlideVertices_0087EFF8[0].y >= 0.0f && gGlideVertices_0087EFF8[0].y < nScreenHeight)
		|| (gGlideVertices_0087EFF8[1].x >= 0.0f && gGlideVertices_0087EFF8[1].x < nScreenWidth && gGlideVertices_0087EFF8[1].y >= 0.0f && gGlideVertices_0087EFF8[1].y < nScreenHeight)
		|| (gGlideVertices_0087EFF8[2].x >= 0.0f && gGlideVertices_0087EFF8[2].x < nScreenWidth && gGlideVertices_0087EFF8[2].y >= 0.0f && gGlideVertices_0087EFF8[2].y < nScreenHeight)
		|| (gGlideVertices_0087EFF8[3].x >= 0.0f && gGlideVertices_0087EFF8[3].x < nScreenWidth && gGlideVertices_0087EFF8[3].y >= 0.0f && gGlideVertices_0087EFF8[3].y < nScreenHeight))
	{
		if (!GLSPRITE_UploadTexInfo((int)pPalette, 0, 1, &tInfo))
		{
			return 1;
		}

		GLSPRITE_SetSpriteBlendMode(eDrawMode);
		GLCORE_SetColorCombineMode(1);
		GLCORE_SetTextureFilterMode(1);
		GLVERTEX_SetVertexColor(gGlideVertices_0087EFF8, dwGamma);
		gGlideVertices_0087EFF8[1].dwColor = gGlideVertices_0087EFF8[0].dwColor;
		gGlideVertices_0087EFF8[2].dwColor = gGlideVertices_0087EFF8[0].dwColor;
		gGlideVertices_0087EFF8[3].dwColor = gGlideVertices_0087EFF8[0].dwColor;
		gpfnGrDrawVertexArrayContiguous_0087EAC4(5, 4, gGlideVertices_0087EFF8, sizeof(D2GlideSpriteVertexStrc));
		gpfnGrGlideState_0087EAB4(2);
		return 1;
	}

	return 1;
}

// 0x0050B0D0
int __fastcall GLSPRITE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, unsigned int dwColor, int nMode, int nPalette)
{
    D2GlideTexInfoStrc tInfo;
    if (!GLSPRITE_InitTexInfo(pContext, &tInfo))
        return 0;

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

    GLSPRITE_SetupTexInfoSize(&tInfo);
    if (nMode == 7)
    {
        if (!GLSPRITE_UploadTexInfo(nPalette, 0, 2, &tInfo))
            return 1;
    }
    else if (!GLSPRITE_UploadTexInfo(nPalette, 0, 1, &tInfo))
    {
        return 1;
    }

    GLSPRITE_SetSpriteBlendMode(nMode);
    GLSPRITE_DrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, 0);
    return 1;
}

// 0x0050B190
int __fastcall GLSPRITE_CelDrawColor(D2CelContextStrc* pContext, int nX, int nY, unsigned int dwColor, int nMode, int nPaletteIndex)
{
    D2GlideTexInfoStrc tInfo;
    if (!GLSPRITE_InitTexInfo(pContext, &tInfo))
        return 0;

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

    GLSPRITE_SetupTexInfoSize(&tInfo);
    if (GLSPRITE_UploadTexInfo(0, 0, 1, &tInfo))
    {
        GLSPRITE_SetSpriteBlendMode(nMode);
        GLSPRITE_DrawSpriteQuad(nX, nY, dwColor, 0, &tInfo, nPaletteIndex);
    }
    return 1;
}

// 0x0050B230
void __fastcall GLSPRITE_CelDrawEx(D2CelContextStrc* pContext, int nX, int nY, unsigned int nSkip, unsigned int nRows, int nMode)
{
    GLSPRITE_SetSpriteBlendMode(nMode);

    D2GlideTexInfoStrc tInfo;
    if (!GLSPRITE_InitTexInfo(pContext, &tInfo))
        return;

    GLSPRITE_SetupTexInfoSize(&tInfo);
    if (!GLSPRITE_UploadTexInfo(0, 0, 1, &tInfo))
        return;

    const float fScale = 1.0f / tInfo.nTexHeight;
    if (!GLVERTEX_IsPerspective())
    {
        if (nSkip)
        {
            nY -= nSkip;
            tInfo.fT0 += (tInfo.nHeight - nSkip - nRows) * fScale;
            tInfo.fT1 -= nSkip * fScale;
        }
        else
        {
            tInfo.fT0 += (tInfo.nHeight - nRows) * fScale;
        }
        tInfo.nHeight = nRows;
    }
    else
    {
        if (nSkip)
        {
            nY -= nSkip;
            const unsigned int nRest = tInfo.nTexHeight - nSkip;
            tInfo.fT0 = (nRest - nRows) * fScale;
            tInfo.fT1 = nRest * fScale;
        }
        else
        {
            tInfo.fT0 = (tInfo.nTexHeight - nRows) * fScale;
        }
        tInfo.nTexHeight = nRows;
    }

    GLSPRITE_DrawSpriteQuad(nX, nY, -1, 0, &tInfo, 0);
}

// 0x0050B390
static int __stdcall GLSPRITE_ClipSprite(D2GlideTexInfoStrc* pInfo, int nY, const D2BoundsStrc* pBounds, int nX, D2ClipStrc* pClip)
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
// build: symbol ?gszEmptyString@* 0x006CC837
// build: symbol ?FOG_DisplayHalt@* 0x00408A60
        FOG_DisplayHalt(gszEmptyString, sub_00408090(), 1060);
        exit(-1);
    }
    return 0;
}

int __fastcall Harness_ClipSprite(D2GlideTexInfoStrc* pInfo, int nX, int nY, const D2BoundsStrc* pBounds)
{
    D2ClipStrc tClip;
    if (GLSPRITE_ClipSprite(pInfo, nY, pBounds, nX, &tClip))
    {
        return 0;
    }
    return tClip.nLeft + tClip.nWidth + tClip.nTop + tClip.nHeight;
}

// 0x0050B500
void __fastcall GLSPRITE_CelDrawClipped(D2CelContextStrc* pContext, int nX, int nY, const D2BoundsStrc* pBounds, int nMode)
{
    GLSPRITE_SetSpriteBlendMode(nMode);
    D2GlideTexInfoStrc tInfo;
    if (!GLSPRITE_InitTexInfo(pContext, &tInfo))
        return;
    GLSPRITE_SetupTexInfoSize(&tInfo);
    if (!GLSPRITE_UploadTexInfo(0, 0, 1, &tInfo))
        return;

    D2ClipStrc tClip;
    if (GLSPRITE_ClipSprite(&tInfo, nY, pBounds, nX, &tClip))
        return;

    const float fScaleT = 1.0f / tInfo.nTexHeight;
    const float fScaleS = 1.0f / tInfo.nTexWidth;
    if (!GLVERTEX_IsPerspective())
    {
        if (tClip.nTop)
        {
            nY -= tClip.nTop;
            tInfo.fT0 += (tInfo.nHeight - tClip.nHeight - tClip.nTop) * fScaleT;
            tInfo.fT1 -= tClip.nTop * fScaleT;
        }
        else
        {
            tInfo.fT0 += (tInfo.nHeight - tClip.nHeight) * fScaleT;
        }
        tInfo.nHeight = tClip.nHeight;
        if (tClip.nLeft)
        {
            nX += tClip.nLeft;
            tInfo.fS0 = tClip.nLeft * fScaleS;
            tInfo.fS1 = (tClip.nWidth + tClip.nLeft) * fScaleS;
        }
        else
        {
            tInfo.fS1 = tClip.nWidth * fScaleS;
        }
        tInfo.nWidth = tClip.nWidth;
    }
    else
    {
        if (tClip.nTop)
        {
            nY -= tClip.nTop;
            tInfo.fT0 = (tInfo.nTexHeight - tClip.nHeight - tClip.nTop) * fScaleT;
            tInfo.fT1 = (tInfo.nTexHeight - tClip.nTop) * fScaleT;
        }
        else
        {
            tInfo.fT0 = (tInfo.nTexHeight - tClip.nHeight) * fScaleT;
        }
        tInfo.nTexHeight = tClip.nHeight;
        if (tClip.nLeft)
        {
            nX += tClip.nLeft;
            tInfo.fS0 = tClip.nLeft * fScaleS;
            tInfo.fS1 = (tClip.nWidth + tClip.nLeft) * fScaleS;
        }
        else
        {
            tInfo.fS1 = tClip.nWidth * fScaleS;
        }
        tInfo.nTexWidth = tClip.nWidth;
    }
    GLSPRITE_DrawSpriteQuad(nX, nY, -1, 0, &tInfo, 0);
}

// 0x0050B690
void __fastcall GLSPRITE_CelDrawShadow(D2CelContextStrc* pContext, int nX, int nY)
{
    D2GlideTexInfoStrc tInfo;
    if (!GLSPRITE_InitTexInfo(pContext, &tInfo))
        return;

    GLSPRITE_SetupTexInfoSize(&tInfo);
    if (!GLSPRITE_UploadTexInfo(0, 0, 4, &tInfo))
        return;

    GLCORE_SetColorCombineMode(1);
    if (sub_0050BF40_GlideGetBlendedShadows())
    {
        GLCORE_SetAlphaBlendMode(4);
        gpfnGrConstantColorValue(0xC0);
    }
    else
    {
        GLCORE_SetAlphaBlendMode(1);
    }
    GLCORE_SetTextureFilterMode(1);
    GLSPRITE_DrawIsoQuad(nX, nY, &tInfo);
}

// 0x0050B720
void __fastcall GLSPRITE_CelDrawHilight(D2CelContextStrc* pContext, int nX, int nY, int nColor)
{
    GLCORE_SetAlphaBlendMode(4);
    gpfnGrDitherMode(0);
    gpfnGrConstantColorValue(0x40);

    D2GlideTexInfoStrc tInfo;
    if (!GLSPRITE_InitTexInfo(pContext, &tInfo))
        return;

    tInfo.nWidth += 2;
    tInfo.nHeight += 2;
    GLSPRITE_SetupTexInfoSize(&tInfo);
    if (!GLSPRITE_UploadTexInfo(0, nColor, 3, &tInfo))
        return;

    GLSPRITE_DrawSpriteQuad(nX - 1, nY + 1, -1, 1, &tInfo, 0);
}

int __fastcall GLSPRITE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, unsigned int dwColor, int nMode, int nPalette); // 0x0050B0D0

int __fastcall GLSPRITE_CelDrawColor(D2CelContextStrc* pContext, int nX, int nY, unsigned int dwColor, int nMode, int nPaletteIndex); // 0x0050B190

void __fastcall GLSPRITE_CelDrawEx(D2CelContextStrc* pContext, int nX, int nY, unsigned int nSkip, unsigned int nRows, int nMode); // 0x0050B230

void __fastcall GLSPRITE_CelDrawShadow(D2CelContextStrc* pContext, int nX, int nY); // 0x0050B690

void __fastcall GLSPRITE_CelDrawHilight(D2CelContextStrc* pContext, int nX, int nY, int nColor); // 0x0050B720

void __cdecl sub_004095D0_Nop()
{
}

void __cdecl sub_00409C70_Nop()
{
}

void __cdecl sub_0047B4D0_Nop()
{
}

void __cdecl sub_004BF9C0_Nop()
{
}

// 0x0050B7A0
void __cdecl GLSPRITE_DebugFillBackBuffer()
{
}

// 0x0050B7B0
void __cdecl GLSPRITE_InitSprites()
{
    D2_ASSERT(!gpGlideSpriteBufferA, 0x4A);
    D2_ASSERT(!gpGlideSpriteBufferB_0087F0CC, 0x4B);
    gpGlideSpriteBufferA = (unsigned char*)FOG_Alloc(0x10000, ".\\Src\\glSprite.cpp", 0x4C, 0);
    gpGlideSpriteBufferB_0087F0CC = (unsigned char*)FOG_Alloc(0x10000, ".\\Src\\glSprite.cpp", 0x4D, 0);
    CelSetHardwareFreeCallback(sub_0050A110_GlideFreeCelData);
    gbGlideSpriteFlag = 0;
    gbGlideMultiTmu = gnGlideTmuCount > 1;
    if (gnGlideTmuCount > 1 && !GLCORE_GetFloorTilesFlag())
        gbGlideSpriteFlag = 1;
}


// 0x0050DFE0
int __fastcall GLSPRITE_SetSmackTexAddresses(int nBase, int nAlign)
{
    int nSize = 0x8000;
    const int nMask = nAlign - 1;
    if (nSize & nMask)
        nSize = (nSize | nMask) + 1;
    if (nBase & nMask)
        nBase = (nBase | nMask) + 1;
    gnGlideSmackTexAddrB = nBase + nSize;
    gnGlideSmackTexAddrA = nBase;
    gtGlideSmackTexInfoA.pData = gpGlideSmackBufferB;
    gtGlideSmackTexInfoB.pData = gpGlideSmackBufferC;
    return nSize * 2;
}

// 0x0050E330
void __cdecl GLSPRITE_UploadSmackTextures()
{
    gpfnGrTexDownloadMipMap(gnGlideSmackTmu, gnGlideSmackTexAddrA, 3, &gtGlideSmackTexInfoA);
    gpfnGrTexDownloadMipMap(gnGlideSmackTmu, gnGlideSmackTexAddrB, 3, &gtGlideSmackTexInfoB);
}

int __fastcall sub_M120_Emit_0050A1E0(D2GlideRectViewStrc* pRect, int nA, int nB)
{
    int n = GLSPRITE_RoundTexSize(nA);
    n += GLSPRITE_GetTexSizeExponent(nB);
    n += GLSPRITE_IsOutsideScreen(nA, nB, pRect);
    return n;
}

#include "gen/data/Source/D2Glide/Src/glSprite.inc"
