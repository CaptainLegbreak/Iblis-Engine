#include "D2DDraw.h"
#include "D2CelContext.h"
#include "D2CmpTypes.h"
#include "D2Win32Base.h"
#include "FogApi.h"
#include "D2CMPApi.h"

struct D2CelStrc;
struct D2DDrawClipRectStrc;
struct D2DDrawCelClipStrc;

extern int gnDDrawClipLeft; // 0x0088129C

struct D2DDrawClipRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2DDrawCelClipStrc
{
    int nLeft;
    int nRight;
    int nFirstRow;
    int nRows;
};

int __stdcall D2CMPSpriteValidate(D2GfxDataStrc* pContext, int nArg2, int nArg3);

extern D2PaletteTableStrc* gpGfxPaletteView; // 0x007C9150
extern int gnDDrawClipRight; // 0x008812A0

int gnDDrawClipRight; // 0x008812A0

// 0x00511DF0
void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode)
{
    if (nResolutionMode == 0)
    {
        gnDDrawClipLeft = 0;
        gnDDrawClipRight = 640;
    }
    else
    {
        gnDDrawClipLeft = 0;
        gnDDrawClipRight = 800;
    }
}

// 0x00511E10
static int __stdcall sub_00511E10_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += CelGetOffsetX(pCel);
// build: symbol ?gnRenderWidth@* 0x007C9138
    if (nX < gnRenderWidth && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
// build: symbol ?gnRenderHeight@* 0x007C913C
        if (nY >= 0 && nY - nHeight < gnRenderHeight)
            return 0;
    }

    return 1;
}

// 0x00511E80
static int __fastcall sub_00511E80_ClipCel(D2CelStrc* pCel, int nY, int nX, D2DDrawCelClipStrc* pOut, const D2DDrawClipRectStrc* pClip)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);

    const int nLeft = D2_MAX(pClip->nLeft, 0);
    const int nRight = D2_MIN(pClip->nRight, gnRenderWidth);
    if (nLeft <= nRight)
    {
        nX += CelGetOffsetX(pCel);
        if (nX < nRight && nWidth + nX >= nLeft)
        {
            const int nTop = D2_MAX(pClip->nTop, 0);
            const int nBottom = D2_MIN(pClip->nBottom, gnRenderHeight);
            if (nTop <= nBottom)
            {
                nY += CelGetOffsetY(pCel);
                if (nY >= nTop && nY - nHeight <= nBottom)
                {
                    pOut->nLeft = nLeft;
                    pOut->nRight = nRight;
                    if (nY <= nBottom)
                        pOut->nFirstRow = 0;
                    else
                        pOut->nFirstRow = nY - nBottom - 1;
                    if (nY - nHeight >= nTop)
                        pOut->nRows = nHeight - pOut->nFirstRow;
                    else
                        pOut->nRows = nY - pOut->nFirstRow - nTop + 1;

                    D2_ASSERT(pOut->nRows > 0, 0xAB);
                    return 0;
                }
            }
        }
    }

    return 1;
}

// 0x00512250
void __fastcall sub_00512250_DrawCel(D2GfxDataStrc* pContext, int nX, int nY, const D2DDrawClipRectStrc* pClip, int nDrawMode)
{
    D2DDrawCelClipStrc tOut;
    tOut.nLeft = 0;
    tOut.nRight = 0;
    tOut.nFirstRow = 0;
    tOut.nRows = 0;
    if (!D2CMPSpriteValidate(pContext, 0, 1))
        return;
    if (sub_00511E80_ClipCel(pContext->pCel, nY, nX, &tOut, pClip))
        return;
    CelDrawEx((D2CmpCelContextStrc*)pContext, nX, nY, tOut.nLeft, tOut.nRight, gpScreenBuffer_007C9154,
        gnRenderHeight, gnRenderWidth, 0, DDCORE_GetDrawModePalette(nDrawMode, (int*)&pClip), tOut.nFirstRow, tOut.nRows, 0); // 0x00511D70
}

// 0x00511FB0
int __fastcall sub_00511FB0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette)
{
    D2GfxDataStrc* pContext = (D2GfxDataStrc*)pData;
    if (!D2CMPSpriteValidate(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    const int nGamma = (unsigned char)dwGamma;
    unsigned char* pGammaTable = 0;
    const int nCaps = DDCORE_GetDrawModePalette(nDrawMode, (int*)&dwGamma);
    if (nGamma != 0xFF)
        pGammaTable = gpGfxPaletteView->pShadowLightGammaPalettes[nGamma >> 3];
    if (nDrawMode == 7)
        pGammaTable = gpGfxPaletteView->pRemap;

    CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnDDrawClipLeft, gnDDrawClipRight,
        gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPalette);
    return 1;
}

// 0x005123A0
void __stdcall DDRAW_CelDrawHilight(int nUnused1, int nUnused2)
{
}

// 0x005123B0
void __fastcall sub_005123B0_DDrawDebugFillBackBuffer(int nX, int nY)
{
    D2_ASSERT(nX > 0 && nX < gnRenderWidth - 0x50, 0x186);
    D2_ASSERT(nY > 0 && nY < gnRenderHeight - 0x50, 0x187);
    CmpDoLensEffect(gpScreenBuffer_007C9154 + gnRenderWidth * nY + nX, gnRenderWidth);
}

struct D2CelStrc;

int __stdcall D2CMPSpriteValidate(D2GfxDataStrc* pContext, int nArg2, int nArg3);
int gnDDrawClipLeft;                                                                                // 0x0088129C

// 0x005120A0
int __fastcall sub_005120A0_DrawImagePalette(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nPalette)
{
    D2GfxDataStrc* pContext = (D2GfxDataStrc*)pData;
    if (!D2CMPSpriteValidate(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    {
        unsigned char* pGammaTable = 0;
        unsigned char* pPaletteTable = 0;
        int nType;
        const int nCaps = DDCORE_GetDrawModePalette(nDrawMode, &nType);
        const int nGamma = (unsigned char)dwGamma;
        if (nGamma != 0xFF)
            pGammaTable = gpGfxPaletteView->pShadowLightGammaPalettes[nGamma >> 3];
        if (nDrawMode == 7)
            pGammaTable = gpGfxPaletteView->pRemap;
        if (nPalette)
            pPaletteTable = gpGfxPaletteView->pStandardShiftPalettes[nPalette];

        CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnDDrawClipLeft, gnDDrawClipRight,
            gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPaletteTable);
    }
    return 1;
}

struct D2CelStrc;
int __stdcall D2CMPSpriteValidate(D2CmpCelContextStrc*, int, int); // 0x006001F0
extern int gnRenderWidth; // 0x007C9138
extern int gnRenderHeight; // 0x007C913C
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154

// 0x005121A0
void __fastcall sub_005121A0_DrawClipped(D2CmpCelContextStrc* context, int x, int y, int top, int rows, int index)
{
    if (!D2CMPSpriteValidate(context, 0, 1)) return;
    if (sub_00511E10_IsCelOffScreen(context->pCel, x, y, 0)) return;
    int screenHeight = gnRenderHeight;
    CelDrawEx(context, x, y, gnDDrawClipLeft, gnDDrawClipRight, gpScreenBuffer_007C9154, screenHeight, gnRenderWidth, 0, DDCORE_GetDrawModePalette(index, &rows), top, rows, 0);
}

struct D2CelStrc;
int __stdcall D2CMPSpriteValidate(D2CmpCelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
extern int* gpShadowTable_007C9150; // 0x007C9150

// 0x005122E0
void __fastcall sub_005122E0_DrawShadow(D2CmpCelContextStrc* pContext, int nX, int nY)
{
    if (!D2CMPSpriteValidate(pContext, 0, 1))
        return;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 1))
        return;

    int nTable = 0;
    if (DDCORE_GetBlendedShadows())
        nTable = *gpShadowTable_007C9150;
    CelDrawShadow(pContext, nX, nY, gnDDrawClipLeft, gnDDrawClipRight, gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, nTable, 0);
}

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
#pragma function(memset)

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))


// 0x00512410
int __fastcall GLVERTEX_CelFlatSpriteDraw(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nScreenMode, void* pPalette)
{
    return sub_00511FB0_DrawImage(pData, nX, nY, dwGamma, nDrawMode, pPalette);
}

// 0x00512710
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode)
{
    int nTransMode;
    const unsigned char* pTable = (const unsigned char*)DDCORE_GetDrawModePalette(nDrawMode, &nTransMode);

    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnRenderWidth - 1);
    const int nX2 = D2_MIN(D2_MAX(nXEnd, 0), gnRenderWidth - 1);
    if (nX1 == nX2)
        return;

    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnRenderHeight - 1);
    const int nY2 = D2_MIN(D2_MAX(nYEnd, 0), gnRenderHeight - 1);
    if (nY2 == nY1)
        return;

    D2_ASSERT(nY2 > nY1, 0x39);

    unsigned char* pDst = gpScreenBuffer_007C9154 + gnRenderWidth * nY1 + nX1;
    int nRows = nY2 - nY1;

    switch (nTransMode)
    {
    default:
        while (nRows--)
        {
            memset(pDst, (unsigned char)dwColor, nX2 - nX1);
            pDst += gnRenderWidth;
        }
        break;

    case 2:
        while (nRows--)
        {
            unsigned char* p = pDst;
            int n = nX2 - nX1;
            while (n--)
            {
                *p = pTable[(*p << 8) + (unsigned char)dwColor];
                ++p;
            }
            pDst += gnRenderWidth;
        }
        break;

    case 1:
        while (nRows--)
        {
            unsigned char* p = pDst;
            int n = nX2 - nX1;
            while (n--)
            {
                *p = pTable[*p];
                ++p;
            }
            pDst += gnRenderWidth;
        }
        break;
    }
}

struct tagRECT;

static void __fastcall DDRAW_PutPixel(int nX, int nY, unsigned char nColor)
{
// build: symbol ?gnRenderWidth@* 0x007C9138
// build: symbol ?gnRenderHeight@* 0x007C913C
    if (nX >= 0 && nX < gnRenderWidth && nY >= 0 && nY < gnRenderHeight)
        gpScreenBuffer_007C9154[gnRenderWidth * nY + nX] = nColor;
}

// 0x00512930
void __fastcall sub_00512930_DDrawDrawLine(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nUnused)
{
    int nX = nX1;
    int nY = nY1;
    int nDX = nX2 - nX1;
    int nDY = nY2 - nY1;
    int nStepX;
    int nStepY;

    if (nDX < 0)
    {
        nStepX = -1;
        nDX = -nDX;
    }
    else
    {
        nStepX = 1;
    }

    if (nDY < 0)
    {
        nStepY = -1;
        nDY = -nDY;
    }
    else
    {
        nStepY = 1;
    }

    DDRAW_PutPixel(nX1, nY1, nColor);

    int nError = 0;
    if (nDX < nDY)
    {
        for (int i = 0; i < nDY; ++i)
        {
            nY += nStepY;
            nError += nDX;
            if (nError > nDY)
            {
                nX += nStepX;
                nError -= nDY;
            }

            DDRAW_PutPixel(nX, nY, nColor);
        }
    }
    else
    {
        for (int i = 0; i < nDX; ++i)
        {
            nX += nStepX;
            nError += nDY;
            if (nError > nDX)
            {
                nY += nStepY;
                nError -= nDX;
            }

            DDRAW_PutPixel(nX, nY, nColor);
        }
    }
}

// 0x00512D90
void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x165);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x166);
    if (pRect->right < 0 || pRect->left >= gnRenderWidth || pRect->bottom < 0 || pRect->top >= gnRenderHeight)
        return;
    if (pRect->left < 0)
        pRect->left = 0;
    if (pRect->right >= gnRenderWidth)
        pRect->right = gnRenderWidth - 1;
    if (pRect->top < 0)
        pRect->top = 0;
    if (pRect->bottom >= gnRenderHeight)
        pRect->bottom = gnRenderHeight - 1;
    const unsigned int nWidth = pRect->right - pRect->left;
    int nHeight = pRect->bottom - pRect->top;
    if (!nWidth || !nHeight)
        return;
    unsigned char* pDst = &gpScreenBuffer_007C9154[pRect->top * gnRenderWidth + pRect->left];
    while (nHeight--)
    {
        for (unsigned int x = 0; x < nWidth; ++x)
            pDst[x] = nColor;
        pDst += gnRenderWidth;
    }
}

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CoordPairStrc { int nX; int nY; };
static void __stdcall sub_00512A50_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor); // 0x00512A50

// 0x00512C20
void __fastcall sub_00512C20_DrawDiamond(tagRECT* pRect, int nValue)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x12D);
    int nBottom = pRect->bottom;
    D2_ASSERT(pRect->top <= nBottom, 0x12E);

    unsigned int nWidth = pRect->right - pRect->left;
    unsigned int nHeight = nBottom - pRect->top;
    if (!nWidth || !nHeight)
        return;

    D2CoordPairStrc ptTop;
    D2CoordPairStrc ptLeft;
    D2CoordPairStrc ptBottom;
    ptTop.nX = pRect->left + (nWidth >> 1);
    D2CoordPairStrc ptRight;
    ptTop.nY = pRect->top;
    ptRight.nX = pRect->right;
    ptRight.nY = pRect->top + (nHeight >> 1);
    ptBottom.nX = pRect->left + (nWidth >> 1);
    ptBottom.nY = nBottom;
    ptLeft.nX = pRect->left;
    ptLeft.nY = pRect->top + (nHeight >> 1);

    sub_00512A50_DrawLine(&ptTop, &ptRight, nValue);
    sub_00512A50_DrawLine(&ptRight, &ptBottom, nValue);
    sub_00512A50_DrawLine(&ptBottom, &ptLeft, nValue);
    sub_00512A50_DrawLine(&ptLeft, &ptTop, nValue);
}

static void __stdcall sub_00512A50_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor)
{
    const int nDeltaX = pTo->nX - pFrom->nX;
    const int nDeltaY = pTo->nY - pFrom->nY;
    if (!nDeltaX && !nDeltaY)
    {
        return;
    }

    const int nLength = nDeltaY * nDeltaY + nDeltaX * nDeltaX;
    int nSteps = 0;
    while (nSteps * nSteps < nLength)
    {
        ++nSteps;
    }

    const int nStepX = (nDeltaX << 16) / nSteps;
    const int nStepY = (nDeltaY << 16) / nSteps;
    int nX = pFrom->nX;
    int nY = pFrom->nY;
    int nFracX = 0;
    int nFracY = 0;
    int i = 0;
    for (;;)
    {
        if (nY >= 0 && nY < gnRenderHeight && nX >= 0 && nX < gnRenderWidth)
        {
            break;
        }

        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nMove = nFracX / 0x10000;
            nX += nMove;
            nFracX += nMove * -0x10000;
        }

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nMove = nFracY / 0x10000;
            nY += nMove;
            nFracY += nMove * -0x10000;
        }

        if (i >= nSteps)
        {
            return;
        }
        ++i;
    }

    unsigned char* pDst = gpScreenBuffer_007C9154 + gnRenderWidth * nY + nX;
    *pDst = nColor;
    for (++i; i < nSteps; ++i)
    {
        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nMove = nFracX / 0x10000;
            nX += nMove;
            pDst += nMove;
            nFracX += nMove * -0x10000;
        }

        if (nX < 0 || nX >= gnRenderWidth)
        {
            return;
        }

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nMove = nFracY / 0x10000;
            nY += nMove;
            pDst += gnRenderWidth * nMove;
            nFracY += nMove * -0x10000;
        }

        if (nY < 0 || nY >= gnRenderHeight)
        {
            return;
        }

        *pDst = nColor;
    }
}

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x00512CE0
void __fastcall sub_00512CE0_DrawRect(tagRECT* pRect, int nColor)
{
    const int nLeft = pRect->left;
    D2_ASSERT(nLeft <= pRect->right, 0x149);
    const int nTop = pRect->top;
    D2_ASSERT(nTop <= pRect->bottom, 0x14A);
    const unsigned int nWidth = pRect->right - nLeft;
    const unsigned int nHeight = pRect->bottom - nTop;
    if (!nWidth || !nHeight)
        return;

    D2CoordPairStrc aCorners[4];
    aCorners[1].nX = nLeft;
    aCorners[1].nY = pRect->top;
    aCorners[3].nX = pRect->right;
    aCorners[3].nY = pRect->top;
    aCorners[2].nX = pRect->right;
    aCorners[2].nY = pRect->bottom;
    aCorners[0].nX = nLeft;
    aCorners[0].nY = pRect->bottom;
    sub_00512A50_DrawLine(&aCorners[1], &aCorners[3], nColor);
    sub_00512A50_DrawLine(&aCorners[3], &aCorners[2], nColor);
    sub_00512A50_DrawLine(&aCorners[2], &aCorners[0], nColor);
    sub_00512A50_DrawLine(&aCorners[0], &aCorners[1], nColor);
}

