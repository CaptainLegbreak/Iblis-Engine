#include "D2Gdi.h"
#include "D2Win32Base.h"
#include "D2GfxTypes.h"
#include "D2GlideTypes.h"
#include "D2DrlgMaps.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __fastcall GDICORE_GetSetting(unsigned int nSelector, int* pValue); // 0x006C8250

static inline int sub_006C8A60_Clip(int nValue, int nSize)
{
    int nClipped = nValue > 0 ? nValue : 0;
    return nClipped < nSize - 1 ? nClipped : nSize - 1;
}

// 0x006C8A60
void __fastcall sub_006C8A60_Draw(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nLevel)
{
    int nMode;
    unsigned char* pTable = (unsigned char*)GDICORE_GetSetting(nLevel, &nMode);

    nX1 = sub_006C8A60_Clip(nX1, gnStride_007C9138);
    nX2 = sub_006C8A60_Clip(nX2, gnStride_007C9138);
    if (nX1 == nX2)
        return;

    nY1 = sub_006C8A60_Clip(nY1, gnHeight_007C913C);
    nY2 = sub_006C8A60_Clip(nY2, gnHeight_007C913C);
    if (nY2 == nY1)
        return;

    D2_ASSERT(nY2 > nY1, 0x32);

    unsigned char* pDst = gpBuffer_007C9154 + nY1 * gnStride_007C9138 + nX1;
    int nRows = nY2 - nY1;
    switch (nMode)
    {
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
            pDst += gnStride_007C9138;
        }
        break;

    case 2:
        while (nRows--)
        {
            unsigned char* p = pDst;
            int n = nX2 - nX1;
            while (n--)
            {
                *p = pTable[(*p << 8) + nColor];
                ++p;
            }
            pDst += gnStride_007C9138;
        }
        break;

    default:
        while (nRows--)
        {
            memset(pDst, nColor, nX2 - nX1);
            pDst += gnStride_007C9138;
        }
        break;
    }
}

extern int gnWidth_007C9138; // 0x007C9138
extern int gnHeight_007C913C; // 0x007C913C
extern unsigned char* gpBuffer_007C9154; // 0x007C9154

// 0x006C8C50
void __fastcall sub_006C8C50_SetPixel(int nX, int nY, unsigned char nValue)
{
    if (nX >= 0 && nX < gnWidth_007C9138 && nY >= 0 && nY < gnHeight_007C913C)
        gpBuffer_007C9154[gnWidth_007C9138 * nY + nX] = nValue;
}

struct tagPOINT;
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern int gnRenderHeight; // 0x007C913C

void __fastcall sub_006C90E0_GdiUtilFilledRect(tagRECT* pRect, unsigned char nColor); // 0x006C90E0
void __stdcall sub_006C9220_ClearBuffer(int bPartial); // 0x006C9220

int gnRenderHeight; // 0x007C913C

static void __fastcall GDI_PutPixel(int nX, int nY, unsigned char nColor)
{
// build: symbol ?gnRenderWidth@* 0x007C9138
    if (nX >= 0 && nX < gnRenderWidth && nY >= 0 && nY < gnRenderHeight)
        gpScreenBuffer_007C9154[gnRenderWidth * nY + nX] = nColor;
}

// 0x006C8C80
void __fastcall sub_006C8C80_GdiDrawLine(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nUnused)
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

    GDI_PutPixel(nX1, nY1, nColor);

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

            GDI_PutPixel(nX, nY, nColor);
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

            GDI_PutPixel(nX, nY, nColor);
        }
    }
}

// 0x006C90E0
void __fastcall sub_006C90E0_FillRect(tagRECT* pRect, int nColor)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x15E);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x15F);

    if (pRect->right < 0)
    {
        return;
    }

    if (pRect->left >= gnRenderWidth)
    {
        return;
    }

    if (pRect->bottom < 0)
    {
        return;
    }

    if (pRect->top >= gnRenderHeight)
    {
        return;
    }

    if (pRect->left < 0)
    {
        pRect->left = 0;
    }

    if (pRect->right >= gnRenderWidth)
    {
        pRect->right = gnRenderWidth - 1;
    }

    if (pRect->top < 0)
    {
        pRect->top = 0;
    }

    if (pRect->bottom >= gnRenderHeight)
    {
        pRect->bottom = gnRenderHeight - 1;
    }

    unsigned int nWidth = pRect->right - pRect->left;
    int nHeight = pRect->bottom - pRect->top;

    if (!nWidth)
    {
        return;
    }

    if (!nHeight)
    {
        return;
    }

    unsigned char* pDst = &gpScreenBuffer_007C9154[pRect->top * gnRenderWidth + pRect->left];
    while (nHeight--)
    {
        if (nWidth > 0)
        {
            memset(pDst, nColor, nWidth);
        }

        pDst += gnRenderWidth;
    }
}

// 0x006C91D0
void __fastcall sub_006C91D0_GdiUtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_006C90E0_GdiUtilFilledRect(&tRect, nPaletteIndex);
    }
}

// 0x006C9220
void __stdcall sub_006C9220_ClearBuffer(int bPartial)
{
    if (bPartial)
    {
        memset(gpBuffer_007C9154, 0, gnStride_007C9138 * (gnRenderHeight - 47));
    }
    else
    {
        memset(gpBuffer_007C9154, 0, gnStride_007C9138 * gnRenderHeight);
    }
}

// 0x006C9270
void __fastcall sub_006C9270_Apply(int enabled)
{
    sub_006C9220_ClearBuffer(enabled);
}

// 0x006C9280
void __fastcall sub_006C9280_Apply(int enabled, unsigned char unusedRegister, int unusedA, int unusedB)
{
    sub_006C9220_ClearBuffer(enabled);
}

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CoordPairStrc { int nX; int nY; };
static void __stdcall sub_006C8DA0_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor); // 0x006C8DA0

// 0x006C8F70
void __fastcall sub_006C8F70_RectDiamond(tagRECT* pRect, int nValue)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x126);
    int nBottom = pRect->bottom;
    D2_ASSERT(pRect->top <= nBottom, 0x127);

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

    sub_006C8DA0_DrawLine(&ptTop, &ptRight, nValue);
    sub_006C8DA0_DrawLine(&ptRight, &ptBottom, nValue);
    sub_006C8DA0_DrawLine(&ptBottom, &ptLeft, nValue);
    sub_006C8DA0_DrawLine(&ptLeft, &ptTop, nValue);
}

extern int gnSurfaceWidth_007C9138;                                                                         // 0x007C9138
extern int gnSurfaceHeight_007C913C;                                                                        // 0x007C913C
extern unsigned char* gpSurfaceBits_007C9154;                                                               // 0x007C9154

static void __stdcall sub_006C8DA0_DrawLine(const D2CoordPairStrc* pFrom, const D2CoordPairStrc* pTo, unsigned char nColor)
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
        if (nY >= 0 && nY < gnSurfaceHeight_007C913C && nX >= 0 && nX < gnSurfaceWidth_007C9138)
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

    unsigned char* pDst = gpSurfaceBits_007C9154 + gnSurfaceWidth_007C9138 * nY + nX;
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

        if (nX < 0 || nX >= gnSurfaceWidth_007C9138)
        {
            return;
        }

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nMove = nFracY / 0x10000;
            nY += nMove;
            pDst += gnSurfaceWidth_007C9138 * nMove;
            nFracY += nMove * -0x10000;
        }

        if (nY < 0 || nY >= gnSurfaceHeight_007C913C)
        {
            return;
        }

        *pDst = nColor;
    }
}

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* pText, const char* pFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x006C9030
void __fastcall sub_006C9030_DrawRect(tagRECT* pRect, int nColor)
{
    const int nLeft = pRect->left;
    D2_ASSERT(nLeft <= pRect->right, 0x142);
    const int nTop = pRect->top;
    D2_ASSERT(nTop <= pRect->bottom, 0x143);
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
    sub_006C8DA0_DrawLine(&aCorners[1], &aCorners[3], nColor);
    sub_006C8DA0_DrawLine(&aCorners[3], &aCorners[2], nColor);
    sub_006C8DA0_DrawLine(&aCorners[2], &aCorners[0], nColor);
    sub_006C8DA0_DrawLine(&aCorners[0], &aCorners[1], nColor);
}

extern int gnSurfaceWidth_007C9138;                                                                         // 0x007C9138
extern int gnSurfaceHeight_007C913C;                                                                        // 0x007C913C
extern unsigned char* gpSurfaceBits_007C9154;                                                               // 0x007C9154


int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int bAsync, int nFlags); // 0x005FDEA0
int __cdecl sub_006C8A50_GetBlendedShadows(); // 0x006C8A50
extern int gnRenderHeight; // 0x007C913C

// 0x006C9290
int __fastcall sub_006C9290_DrawWallTile(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, void* pLight, int nScreenPanels)
{
    int bDrawn = 0;

    if (D2CMPTileValidate(pTile, 1, 0))
    {
        int nMinX = -32;
// build: symbol ?gnRenderWidth@* 0x007C9138
        int nMaxX = gnRenderWidth;
        int nMaxY = gnRenderHeight + 32;

        switch (nScreenPanels)
        {
        case 1:
            nMaxX -= gnRenderWidth / 2;
            break;
        case 2:
            nMinX = gnRenderWidth / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            D2GlideTileStrc* pBlock = &pTile->pBlocks[i];
            const int nX = pBlock->nPosX + nPosX;
            const int nY = pTile->pBlocks[i].nPosY + nPosY;
            if (nX >= nMinX && nX < nMaxX && nY >= -32 && nY < nMaxY)
            {
                bDrawn = 1;
                if (sub_006C8A50_GetBlendedShadows())
                    gpTileDrawFunctions_007C914C->pfDrawShadowBlock(pTile->pBlocks[i].pData, nX, nY, 0xC0);
                else
                    gpTileDrawFunctions_007C914C->pfDrawWallBlock(pTile->pBlocks[i].pData, nX, nY);
            }
        }
    }

    return bDrawn;
}

// 0x006C95C0
void __cdecl sub_006C95C0_Nop()
{
}

struct D2DrawTable006C95D0Strc
{
    unsigned char unk_00[0x0C];
    void (__fastcall* pfDraw)(void* a, int nX, int nY, void* b);
};
extern D2DrawTable006C95D0Strc* gpDrawTable_007C914C; // 0x007C914C
int __stdcall D2CMPTileValidate(void* a, int n1, int n0); // 0x005FDEA0

// 0x006C95D0
void __fastcall sub_006C95D0_DrawShifted(void* a, void* b, int nX, int nY, int nUnused1, int nUnused2, int nUnused3, int nMode, int nUnused4)
{
    if (D2CMPTileValidate(a, 1, 0))
    {
        nX -= 80;
        switch (nMode)
        {
        case 1:
// build: symbol ?gnRenderWidth@* 0x007C9138
            nX -= gnRenderWidth / 4;
            break;
        case 2:
            nX += gnRenderWidth / 4;
            break;
        }
        gpDrawTable_007C914C->pfDraw(a, nX, nY, b);
    }
}

