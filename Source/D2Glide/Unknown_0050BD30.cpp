#include "D2Glide.h"
#include "D2DrlgMaps.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GlideTypes.h"
#include "D2Win32Types.h"

struct D2GlideDebugCellStrc;

extern void (__stdcall* gpfnGrColorCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C

extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable); // 0x0087EB8C

extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0

extern D2GlideDebugCellStrc** gppGlideDebugBuffer; // 0x00880454

unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex); // 0x005093F0

void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0

void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500

int gnRenderWidth;                                                                                 // 0x007C9138

extern void (__stdcall* gpfnGrDrawLine)(const D2GlideSpriteVertexStrc* pStart, const D2GlideSpriteVertexStrc* pEnd); // 0x0087E978

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

extern void (__stdcall* gpfnGrBufferClear)(unsigned int color, unsigned int alpha, unsigned int depth); // 0x0087EB88

typedef char cc_M439_D2GlideSpriteVertexStrc_size[sizeof(D2GlideSpriteVertexStrc) == 0x1C ? 1 : -1];

struct D2GfxLightStrc;

struct D2GlideVtxStrc;

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC

extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98

extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4

extern D2GlideSpriteVertexStrc gaGlideDebugFontVertices[4]; // 0x00880258

extern int gaGlideDebugFontTexAddr[96]; // 0x008800D8

extern D2GrTexInfoStrc gtGlideDebugFontTexInfo; // 0x0072F2B4

void __fastcall GLCORE_SetTextureFilterMode(int nMode); // 0x005095D0

void __fastcall GLCORE_SetTextureCombineMode(int nTmu); // 0x00509460

extern void (__stdcall* gpfnGrDrawVertexArray)(int nMode, int nCount, void** ppVertices); // 0x0087EB18

void __fastcall GLVERTEX_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor); // 0x0050DC30

int __cdecl GLVERTEX_IsPerspective(); // 0x0050DD30

void __fastcall GLPERSPECTIVE_PerspectiveTransform(int nX, int nY, int nZ, int* pScreenX, int* pScreenY); // 0x0050DD60

struct D2GlideVtxStrc { float x; float y; float z; float oow; float sow; float tow; unsigned int color; };

extern D2GlideVtxStrc gaGlideVertices_00880678[36]; // 0x00880678

extern D2GlideVtxStrc* gapGlideTileStrips[60]; // 0x00880A68

int gaGlideDebugFontCharWidths[96]; // 0x008802C8

int gnGlideDebugFontTmu; // 0x00880450

static void sub_0050BD30_GlideDrawPointCross(unsigned int dwColor, int nX, int nY);

void sub_0050BD80_GlideDebugDrawLights();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define GLIDE_VERTEX_IN_RECT(v, r) ((v).x >= (r).left && (v).x < (r).right && (v).y >= (r).top && (v).y < (r).bottom)

extern int gnRenderHeight;                                                                         // 0x007C913C

extern int gaGlideWallCorner[10][6][3];                                                          // 0x0072F3A0

extern void* gapGlideTileStripA[10];                                                            // 0x0072F350

extern void* gapGlideTileStripB[10];                                                            // 0x0072F378

void __fastcall sub_0050DBE0_GlideSetVertexShade(D2GlideSpriteVertexStrc* pVertex, unsigned char nShade);   // 0x0050DBE0

void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile);                                   // 0x0050FBD0

int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int bAsync, int nFlags);                                   // 0x005FDEA0

static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, int nScreenPanels, tagRECT* pRect, int* pOffset);

void __cdecl sub_0050BE20_GlideDebugRefresh();

D2GlideSpriteVertexStrc gaGlideTileGrid[15]; // 0x00880458

D2GlideSpriteVertexStrc gaGlideTileQuad[4]; // 0x00880600

int gbGlideCornersScaled; // 0x00880670

int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels);

static int __stdcall sub_0050CF70_GlideTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels);

int __stdcall sub_0050D410_GlideTileDrawAlpha(int nPosX, int nPosY, D2GfxLightStrc* pLight, unsigned char nAlpha, D2TileLibraryEntryStrc* pTile, int nScreenPanels); // 0x0050D410

int __fastcall sub_0050D4C0_GlideTileDrawLit(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels); // 0x0050D4C0

static int __stdcall sub_0050CDD0_GlideTileDrawFlat(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels);

// 0x0050BD30
static void sub_0050BD30_GlideDrawPointCross(unsigned int dwColor, int nX, int nY)
{
    gpfnGrConstantColorValue(dwColor);
    for (int i = 0; i < 8; ++i)
    {
        D2GlideSpriteVertexStrc tVertex;
// build: symbol ?gaGlideCrossOffsetX@* 0x0072F2C8
        tVertex.x = (float)(gaGlideCrossOffsetX[i] + nX);
// build: symbol ?gaGlideCrossOffsetY@* 0x0072F2E8
        tVertex.y = (float)(gaGlideCrossOffsetY[i] + nY);
// build: symbol ?gpfnGrDrawPoint@* 0x0087EAA0
        gpfnGrDrawPoint(&tVertex);
    }
}

// 0x0050BD80
void sub_0050BD80_GlideDebugDrawLights()
{
    gpfnGrColorCombine(1, 0, 1, 2, 0);
    gpfnGrChromakeyMode(0);
    struct Row { int remaining; int yBase; int j; } row;
    row.j=0;
// build: symbol ?gaGlideDebugLight@* 0x0087F0D0
    unsigned int* light=gaGlideDebugLight;
    for (row.yBase=100;row.yBase<164;row.yBase+=2,++row.j)
    {
        struct Coordinates { int x; int y; } coordinates;
        coordinates.x=(0x113-row.j)*2;
        coordinates.y=row.yBase;
        row.remaining=32;
        do {
// build: symbol ?gaGlideLightPalette@* 0x0072F308
            sub_0050BD30_GlideDrawPointCross(gaGlideLightPalette[*light],coordinates.x,coordinates.y);
            ++light;
            coordinates.y+=2;
            coordinates.x+=2;
        } while (--row.remaining);
    }
    gpfnGrColorCombine(3, 1, 0, 1, 0);
    gpfnGrChromakeyMode(1);
}

// 0x0050BE20
void __cdecl sub_0050BE20_GlideDebugRefresh()
{
    gpfnGrColorCombine(1, 0, 1, 2, 0);
    gpfnGrChromakeyMode(0);
    for (int j = 0; j < 48; ++j)
    {
        for (int i = 0; i < 48; ++i)
        {
            int nX = i * 2 + 100;
            nX -= j << 1;
            const int nY = (j + i + 50) * 2;
            unsigned int dwColor;
            if (j == 24 && i == j)
            {
                dwColor = 0;
                sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
            }
            else
            {
                const D2GlideDebugCellStrc* pCell = &gppGlideDebugBuffer[j][i];
                const unsigned int nAlpha = pCell->nAlpha;
                dwColor = ((pCell->nRed * nAlpha / 256 * 256 + pCell->nGreen * nAlpha / 256) * 256 + pCell->nBlue * nAlpha / 256) * 256;
                sub_0050BD30_GlideDrawPointCross(dwColor, nX, nY);
            }
        }
    }
    gpfnGrColorCombine(3, 1, 0, 1, 0);
    gpfnGrChromakeyMode(1);
}

extern int gnGlideDebugX; // 0x008800D0
extern int gnGlideDebugY; // 0x008800D4

// 0x0050BEF0
void __fastcall GLIDE_DebugDraw(const unsigned int* pLight, const unsigned int* pPlayerLight, int nPosX, int nPosY)
{
    gnGlideDebugX = nPosX;
    gnGlideDebugY = nPosY;
    memcpy(gaGlideDebugLight, pLight, 0x1000);
    memcpy(*gppGlideDebugBuffer, pPlayerLight, 0x4800);
    sub_0050BE20_GlideDebugRefresh();
}

// 0x0050C270
void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha)
{
    if (nXEnd < 0 && nXStart < 0)
    {
        return;
    }
    if (nXEnd > gnRenderWidth && nXStart > gnRenderWidth)
    {
        return;
    }
    if (nYEnd < 0 && nYStart < 0)
    {
        return;
    }
// build: symbol ?gnRenderHeight@* 0x007C913C
    if (nYEnd > gnRenderHeight && nYStart > gnRenderHeight)
    {
        return;
    }

    unsigned int dwColor = GLCORE_GetPaletteColor(nColor);
    GLCORE_SetColorCombineMode(2);
    if (nAlpha == 0xFF)
    {
        GLCORE_SetAlphaBlendMode(1);
    }
    else
    {
        GLCORE_SetAlphaBlendMode(4);
        dwColor = (dwColor & 0xFFFFFF00) | nAlpha;
    }
    gpfnGrChromakeyMode(0);
    gpfnGrConstantColorValue(dwColor);

    if (nXStart == nXEnd && nYStart == nYEnd)
    {
        D2GlideSpriteVertexStrc tVertex;
        tVertex.x = (float)nXStart;
        tVertex.y = (float)nYStart;
        tVertex.oow = 1.0f;
        tVertex.sow = 0.0f;
        tVertex.tow = 0.0f;
        gpfnGrDrawPoint(&tVertex);
    }
    else
    {
        D2GlideSpriteVertexStrc tStart;
        D2GlideSpriteVertexStrc tEnd;
        tStart.x = (float)nXStart;
        tStart.y = (float)nYStart;
        tStart.oow = 1.0f;
        tStart.sow = 0.0f;
        tStart.tow = 0.0f;
        tEnd.x = (float)nXEnd;
        tEnd.y = (float)nYEnd;
        tEnd.oow = 1.0f;
        tEnd.sow = 0.0f;
        tEnd.tow = 0.0f;
        gpfnGrDrawLine(&tStart, &tEnd);
    }
    gpfnGrChromakeyMode(1);
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

// 0x0050C3A0
void __fastcall GLIDE_UtilDiamond(tagRECT* pRect, int nPaletteIndex)
{
    const int nX = pRect->left;
    const int nRight = pRect->right;
    D2_ASSERT(nX <= nRight, 0xB9);

    const int nY = pRect->top;
    const int nBottom = pRect->bottom;
    D2_ASSERT(nY <= nBottom, 0xBA);

    const unsigned int nWidth = nRight - nX;
    const unsigned int nHeight = nBottom - nY;
    if (!nWidth || !nHeight)
    {
        return;
    }

    const int nCenterX = nX + (nWidth >> 1);
    const int nCenterY = nY + (nHeight >> 1);
    const int nX2 = nX + nWidth;
    const int nY2 = nY + nHeight;
    if (nX2 < 0 || nX > gnRenderWidth || nY2 < 0 || nY > gnRenderHeight)
    {
        return;
    }

    sub_0050C270_GlideDrawLine(nCenterX, nY, nX2, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nCenterY, nCenterX, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nCenterX, nY2, nX, nCenterY, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX, nCenterY, nCenterX, nY, nPaletteIndex, 0xFF);
}

// 0x0050C490
void __fastcall GLIDE_UtilRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0xDF);
    D2_ASSERT(pRect->top <= pRect->bottom, 0xE0);

    const int nX1 = D2_MIN(D2_MAX(pRect->left, 0), gnRenderWidth - 1);
    const int nX2 = D2_MIN(D2_MAX(pRect->right, 0), gnRenderWidth - 1);
    if (nX1 == nX2)
    {
        return;
    }

    const int nY1 = D2_MIN(D2_MAX(pRect->top, 0), gnRenderHeight - 1);
    const int nY2 = D2_MIN(D2_MAX(pRect->bottom, 0), gnRenderHeight - 1);
    if (nY1 == nY2)
    {
        return;
    }

    D2_ASSERT(nY2 > nY1, 0xF0);

    sub_0050C270_GlideDrawLine(nX1, nY1, nX2, nY1, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY1, nX2, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX2, nY2, nX1, nY2, nPaletteIndex, 0xFF);
    sub_0050C270_GlideDrawLine(nX1, nY2, nX1, nY1, nPaletteIndex, 0xFF);
}

// 0x0050C5E0
void __fastcall sub_0050C5E0_GlideUtilFilledRect(tagRECT* pRect, int nPaletteIndex)
{
    D2_ASSERT(pRect->left <= pRect->right, 0x100);
    D2_ASSERT(pRect->top <= pRect->bottom, 0x101);
    sub_0050BF50_GlideDrawBox(pRect->left, pRect->top, pRect->right, pRect->bottom, nPaletteIndex, 5);
}

// 0x0050C630
void __fastcall GLIDE_UtilPoint(tagPOINT* pPoint, unsigned char nSize, int nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_0050BF50_GlideDrawBox(tRect.left, tRect.top, tRect.right, tRect.bottom, nPaletteIndex, 5);
    }
}

// 0x0050C680
void __cdecl sub_0050C680_ClearBuffer()
{
    gpfnGrBufferClear(0, 0, 0);
}

// 0x0050C690
static void __stdcall sub_0050C690_GlideGetDrawRect(int bPerspective, int nScreenPanels, tagRECT* pRect, int* pOffset)
{
    D2_ASSERT(pRect, 0x54);

    pRect->left = 0;
    pRect->right = gnRenderWidth;
    pRect->top = 0;
// build: symbol ?gnRenderHeight@* 0x007C913C
    pRect->bottom = gnRenderHeight - 0x2F;

    if (!bPerspective)
    {
        pRect->left = -0x20;
        pRect->bottom += 0x20;
        if (nScreenPanels == 1)
        {
            pRect->right += -(gnRenderWidth / 2);
        }
        else if (nScreenPanels == 2)
        {
            pRect->left = gnRenderWidth / 2 - 0x20;
        }
    }
    else
    {
        D2_ASSERT(pOffset, 0x68);

        const int nQuarter = gnRenderWidth / 4;
        if (nScreenPanels == 1)
        {
            *pOffset = -nQuarter;
        }
        else if (nScreenPanels == 2)
        {
            *pOffset = nQuarter;
        }
        else
        {
            return;
        }
        pRect->right -= nQuarter;
        pRect->left += nQuarter;
    }
}

// 0x0050C760
void __cdecl sub_0050C760_GlideInitVertices()
{
    gaGlideTileQuad[0].x = 0.0f;
    gaGlideTileQuad[0].y = 0.0f;
    gaGlideTileQuad[0].oow = 1.0f;
    gaGlideTileQuad[0].sow = 0.0f;
    gaGlideTileQuad[0].tow = 0.0f;

    gaGlideTileQuad[1].x = 0.0f;
    gaGlideTileQuad[1].y = 0.0f;
    gaGlideTileQuad[1].oow = 1.0f;
    gaGlideTileQuad[1].sow = 0.0f;
    gaGlideTileQuad[1].tow = 256.0f;

    gaGlideTileQuad[2].x = 0.0f;
    gaGlideTileQuad[2].y = 0.0f;
    gaGlideTileQuad[2].oow = 1.0f;
    gaGlideTileQuad[2].sow = 256.0f;
    gaGlideTileQuad[2].tow = 256.0f;

    gaGlideTileQuad[3].x = 0.0f;
    gaGlideTileQuad[3].y = 0.0f;
    gaGlideTileQuad[3].oow = 1.0f;
    gaGlideTileQuad[3].sow = 256.0f;
    gaGlideTileQuad[3].tow = 0.0f;

    for (int i = 0; i < 5; i++)
    {
        float fTow = (float)(i << 6);
        for (int j = 0; j < 3; j++)
        {
            gaGlideTileGrid[i * 3 + j].oow = 1.0f;
            gaGlideTileGrid[i * 3 + j].sow = (float)(j << 7);
            gaGlideTileGrid[i * 3 + j].tow = fTow;
        }
    }

    if (!gbGlideCornersScaled)
    {
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 6; j++)
            {
// build: symbol ?gaGlideWallCorner@* 0x0072F3A0
                int* pPoint = gaGlideWallCorner[i][j];
                pPoint[0] <<= 16;
                pPoint[1] <<= 16;
            }
        }
        gbGlideCornersScaled = 1;
    }
}

// 0x0050CA00
int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels)
{
    int nResult = 0;
    int nOffset = 0;

    int nOne = 1;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(1, nScreenPanels, &tRect, &nOffset);

    nPosX <<= 13;
    nPosY <<= 13;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const int nCol = pTile->pBlocks[i].nPosX >> 5;
        const int nRow = (pTile->pBlocks[i].nPosY + 0x60) >> 5;
        const int nWorldX = ((nCol + nRow * 2) << 16) - 0x38000;
        const int nWorldY = (((nRow << nOne) - nCol) << 16) + 0x18000;
        const int nY0 = nPosY + nWorldY;
        const int nX0 = nPosX + nWorldX;
        int nScreenX;
        int nScreenY;

        GLPERSPECTIVE_PerspectiveTransform(nX0, nY0, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[0].x = (float)nScreenX;
        gaGlideTileGrid[0].y = (float)nScreenY;
        GLPERSPECTIVE_PerspectiveTransform(nPosX + nWorldX + 0x20000, nPosY + nWorldY + 0x20000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[12].x = (float)nScreenX;
        gaGlideTileGrid[12].y = (float)nScreenY;
        GLPERSPECTIVE_PerspectiveTransform(nPosX + nWorldX + 0x30000, nPosY + nWorldY + 0x10000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[14].x = (float)nScreenX;
        gaGlideTileGrid[14].y = (float)nScreenY;
        GLPERSPECTIVE_PerspectiveTransform(nPosX + nWorldX + 0x10000, nPosY + nWorldY - 0x10000, 0, &nScreenX, &nScreenY);
        gaGlideTileGrid[2].x = (float)nScreenX;
        gaGlideTileGrid[2].y = (float)nScreenY;

        if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[0], tRect))
        {
DrawVisibleTile:
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            const float fOffset = (float)nOffset;
            D2GlideSpriteVertexStrc* pVertex = gaGlideTileGrid;
            int nStartY = nY0;
            int nStartX = nX0;
            do
            {
                int nX = nStartX;

                // the original keeps both row starts in memory and steps them separately; with a plain copy the two counters merge into one register
                int nY = *(volatile int*)&nStartY;
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    GLPERSPECTIVE_PerspectiveTransform(nX, nY, 0, &nScreenX, &nScreenY);
                    pVertex->y = (float)nScreenY;
                    pVertex->x = (float)nScreenX + fOffset;
                    sub_0050DBE0_GlideSetVertexShade(pVertex, eDrawMode);
                    nX += 0x8000;
                    ++pVertex;
                    nY -= 0x8000;
                }

                nStartX += 0x8000;
                nStartY += 0x8000;
            } while ((int)pVertex < (int)(gaGlideTileGrid + 15));

            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripA);
            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripB);
            nResult = 1;
        }
        else if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[12], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[14], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[2], tRect))
        {
            goto DrawVisibleTile;
        }
    }

    return nResult;
}

// 0x0050CDD0
static int __stdcall sub_0050CDD0_GlideTileDrawFlat(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(0, nScreenPanels, &tRect, 0);
    nPosY += 0x20;

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const int nBlockX = pTile->pBlocks[i].nPosX;
        const int nX = nPosX + nBlockX;
        const int nY = pTile->pBlocks[i].nPosY + nPosY;
        if (nX >= tRect.left && nX < tRect.right && nY >= tRect.top && nY < tRect.bottom)
        {
            const int nCol = nBlockX >> 5;
            const unsigned int dwColor0 = pLight->aColor[nCol];
            const unsigned int dwColor1 = pLight->aColor[nCol + 1];
            const int nY1 = nY - 0x20;
            const int nX1 = nX + 0x20;
            nResult = 1;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            gaGlideTileQuad[0].x = (float)nX;
            gaGlideTileQuad[0].y = (float)nY1;
            gaGlideTileQuad[1].x = (float)nX;
            gaGlideTileQuad[1].y = (float)nY;
            gaGlideTileQuad[2].x = (float)nX1;
            gaGlideTileQuad[2].y = (float)nY;
            gaGlideTileQuad[3].x = (float)nX1;
            gaGlideTileQuad[3].y = (float)nY1;
            GLVERTEX_SetVertexColor(&gaGlideTileQuad[0], dwColor0);
            GLVERTEX_SetVertexColor(&gaGlideTileQuad[1], dwColor0);
            GLVERTEX_SetVertexColor(&gaGlideTileQuad[2], dwColor1);
            GLVERTEX_SetVertexColor(&gaGlideTileQuad[3], dwColor1);
            gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideTileQuad, sizeof(D2GlideSpriteVertexStrc));
        }
    }

    return nResult;
}

// 0x0050CF70
static int __stdcall sub_0050CF70_GlideTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    int nOffset = 0;
    tagRECT tRect;
    sub_0050C690_GlideGetDrawRect(1, nScreenPanels, &tRect, &nOffset);

    nPosY <<= 13;
    nPosX <<= 13;
    const int nType = pTile->nLightDirection;
    D2_ASSERT(nType >= 0 && nType <= 9, 0x1B4);

    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        const int nCol = pTile->pBlocks[i].nPosX >> 5;
        const int nHeight = pTile->pBlocks[i].nPosY;
        D2_ASSERT(nCol >= 0 && nCol <= 4, 0x1BC);

// build: symbol ?gaGlideWallCorner@* 0x0072F3A0
        const int nX0 = gaGlideWallCorner[nType][nCol][0] + nPosX;
        const int nY0 = gaGlideWallCorner[nType][nCol][1] + nPosY;
        const int nZ0 = gaGlideWallCorner[nType][nCol][2] - nHeight;
        const int nX1 = gaGlideWallCorner[nType][nCol + 1][0] + nPosX;
        const int nY1 = gaGlideWallCorner[nType][nCol + 1][1] + nPosY;
        const int nZ1 = gaGlideWallCorner[nType][nCol + 1][2] - nHeight;
        int nScreenX;
        int nScreenY;

        GLPERSPECTIVE_PerspectiveTransform(nX0, nY0, nZ0, &nScreenX, &nScreenY);
        gaGlideTileGrid[0].x = (float)nScreenX;
        gaGlideTileGrid[0].y = (float)nScreenY;
        GLPERSPECTIVE_PerspectiveTransform(nX0, nY0, nZ0 - 0x20, &nScreenX, &nScreenY);
        gaGlideTileGrid[12].x = (float)nScreenX;
        gaGlideTileGrid[12].y = (float)nScreenY;
        GLPERSPECTIVE_PerspectiveTransform(nX1, nY1, nZ1 - 0x20, &nScreenX, &nScreenY);
        gaGlideTileGrid[14].x = (float)nScreenX;
        gaGlideTileGrid[14].y = (float)nScreenY;
        GLPERSPECTIVE_PerspectiveTransform(nX1, nY1, nZ1, &nScreenX, &nScreenY);
        gaGlideTileGrid[2].x = (float)nScreenX;
        gaGlideTileGrid[2].y = (float)nScreenY;

        if (GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[0], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[12], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[14], tRect)
            || GLIDE_VERTEX_IN_RECT(gaGlideTileGrid[2], tRect))
        {
            const int nMidX = (nX0 + nX1) >> 1;
            const int nMidY = (nY0 + nY1) >> 1;
            const int nMidZ = (nZ0 + nZ1) >> 1;
            unsigned int aColors[3];
            aColors[0] = pLight->aColor[nCol];
            aColors[2] = pLight->aColor[nCol + 1];
            const int nMixA = (unsigned char)(((unsigned char)(aColors[2] >> 24) + (unsigned char)(aColors[0] >> 24)) >> 1);
            const int nMixR = (unsigned char)(((unsigned char)(aColors[2] >> 16) + (unsigned char)(aColors[0] >> 16)) >> 1);
            const int nMixG = (unsigned char)(((unsigned char)(aColors[2] >> 8) + (unsigned char)(aColors[0] >> 8)) >> 1);
            const int nMixB = (unsigned char)(((unsigned char)aColors[2] + (unsigned char)aColors[0]) >> 1);
            aColors[1] = (((((nMixA << 8) + nMixR) << 8) + nMixG) << 8) + nMixB;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);

            const float fOffset = (float)nOffset;
            for (int nGridRow = 0; nGridRow < 5; ++nGridRow)
            {
                const int nDepth = nGridRow << 3;
                if (nGridRow != 0 && nGridRow != 4)
                {
                    GLPERSPECTIVE_PerspectiveTransform(nX0, nY0, nZ0 - nDepth, &nScreenX, &nScreenY);
                    gaGlideTileGrid[nGridRow * 3].x = (float)nScreenX;
                    gaGlideTileGrid[nGridRow * 3].y = (float)nScreenY;
                    GLPERSPECTIVE_PerspectiveTransform(nX1, nY1, nZ1 - nDepth, &nScreenX, &nScreenY);
                    gaGlideTileGrid[nGridRow * 3 + 2].x = (float)nScreenX;
                    gaGlideTileGrid[nGridRow * 3 + 2].y = (float)nScreenY;
                }

                GLPERSPECTIVE_PerspectiveTransform(nMidX, nMidY, nMidZ - nDepth, &nScreenX, &nScreenY);
                gaGlideTileGrid[nGridRow * 3 + 1].x = (float)nScreenX;
                gaGlideTileGrid[nGridRow * 3 + 1].y = (float)nScreenY;
                for (int nGridCol = 0; nGridCol < 3; ++nGridCol)
                {
                    D2GlideSpriteVertexStrc* pVertex = &gaGlideTileGrid[nGridRow * 3 + nGridCol];
                    pVertex->x = pVertex->x + fOffset;
                    GLVERTEX_SetVertexColor(pVertex, aColors[nGridCol]);
                }
            }

// build: symbol ?gapGlideTileStripA@* 0x0072F350
            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripA);
// build: symbol ?gapGlideTileStripB@* 0x0072F378
            gpfnGrDrawVertexArray(4, 10, gapGlideTileStripB);
            nResult = 1;
        }
    }

    return nResult;
}

// 0x0050D410
static int __stdcall sub_0050D410_GlideTileDrawAlpha(int nPosX, int nPosY, D2GfxLightStrc* pLight, unsigned char nAlpha, D2TileLibraryEntryStrc* pTile, int nScreenPanels)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        GLCORE_SetColorCombineMode(1);
        if (nAlpha == 0xFF)
        {
            GLCORE_SetAlphaBlendMode(1);
        }
        else
        {
            GLCORE_SetAlphaBlendMode(4);
            gpfnGrConstantColorValue(nAlpha);
        }

        GLCORE_SetTextureFilterMode(1);
        if (GLVERTEX_IsPerspective())
        {
            nResult = sub_0050CF70_GlideTileDrawPerspective(pTile, nPosX, nPosY, pLight, nScreenPanels);
        }
        else
        {
            nResult = sub_0050CDD0_GlideTileDrawFlat(pTile, nPosX, nPosY, pLight, nScreenPanels);
        }
    }

    return nResult;
}

// 0x0050D490
int __fastcall sub_0050D490_GlideTileDrawTrans(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha)
{
    return sub_0050D410_GlideTileDrawAlpha(nPosX, nPosY, pLight, nAlpha, pTile, nScreenPanels);
}

// 0x0050D4C0
int __fastcall sub_0050D4C0_GlideTileDrawLit(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        GLCORE_SetColorCombineMode(1);
        GLCORE_SetAlphaBlendMode(1);
        GLCORE_SetTextureFilterMode(1);
        if (GLVERTEX_IsPerspective())
        {
            nResult = sub_0050CF70_GlideTileDrawPerspective(pTile, nPosX, nPosY, pLight, nScreenPanels);
        }
        else
        {
            nResult = sub_0050CDD0_GlideTileDrawFlat(pTile, nPosX, nPosY, pLight, nScreenPanels);
        }
    }

    return nResult;
}

static inline float ScaleTexCoord(double dA, double dB, double dScale)
{
    return (float)(int)((dA + dB) * dScale);
}

// 0x0050D540
void __cdecl sub_0050D540_GlideInitD()
{
    D2GlideVtxStrc* pVertex = &gaGlideVertices_00880678[0];
    for (int nRow = 0; nRow < 6; ++nRow)
    {
        for (int nCol = 0; nCol < 6; ++nCol, ++pVertex)
        {
            int nBiasS = 0;
            int nBiasT = 0;
            if (nCol == 0)
            {
                nBiasS = nBiasT = 1;
            }
            else if (nCol == 5)
            {
                nBiasS = nBiasT = -1;
            }

            if (nRow == 0)
            {
                nBiasS -= 1;
                nBiasT += 1;
            }
            else if (nRow == 5)
            {
                nBiasS += 1;
                nBiasT -= 1;
            }

            pVertex->oow = 1.0f;
            pVertex->sow = ScaleTexCoord((float)((nBiasS + 80) * 0.00390625), (nCol - nRow) * 0.0625, 256.0);
            double const tArg3 = (nCol + nRow) * 0.0625;
            pVertex->tow = ScaleTexCoord(tArg3, (float)(nBiasT * 0.0078125), 128.0);
        }
    }

    for (int nRow = 0; nRow < 5; ++nRow)
    {
        for (int nCol = 0; nCol < 6; ++nCol)
        {
            gapGlideTileStrips[12 * nRow + 2 * nCol] = &gaGlideVertices_00880678[6 * nRow + nCol];
            D2GlideVtxStrc** ppBottom = &gapGlideTileStrips[12 * nRow + 2 * nCol + 1];
            *ppBottom = &gaGlideVertices_00880678[6 * nRow + nCol + 6];
        }
    }
}

extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148

// The original calls this getter from 0x50CD40 instead of inlining it.
// 0x0050BF40
__declspec(noinline) int __cdecl sub_0050BF40_GlideGetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}

struct D2GfxLightExStrc;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090
extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink);                            // 0x006CC5BC
extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0
extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink);                               // 0x006CC5C4
unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex);                                   // 0x005093F0
void __fastcall GLCORE_SetColorCombineMode(int nState);                                                      // 0x005094B0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500
void __cdecl sub_0050BE20_GlideDebugRefresh();                                                               // 0x0050BE20
void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue);                         // 0x0050DBC0
void __cdecl DDCORE_ReleaseSurfaces();                                                           // 0x00511A80
int __fastcall DDCORE_CreateSurface(void* hWnd, int nResolutionMode);                           // 0x005115E0
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710
extern "C" const char gszDisplay[];                                                                // 0x006DE1E8
extern "C" const char gszDdDebugFontSourceFile[];                                                  // 0x006DE1D0
extern unsigned long gdwDDrawDebugFontTextColor;                                                    // 0x0072F7F0
extern int gnRenderWidth;                                                                          // 0x007C9138
extern int gbRenderPaused;                                                                         // 0x007C9144
extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154
void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride);        // 0x0087EAC4
extern void (__stdcall* gpfnGrBufferClear)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
void (__stdcall* gpfnGrChromakeyMode)(int bEnable);                                                       // 0x0087EB8C
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor);                              // 0x0087EFA0
extern int gnGlideColorCombineState;                                                                           // 0x0087EFD8
extern int gnGlideAlphaCombineMode;                                                                           // 0x0087EFDC
extern int gnGlideTexFilterMode;                                                                           // 0x0087EFE0
extern int gbGlideDrawing;                                                                         // 0x0087EFE4
extern int gnGlideDebugX;                                                                          // 0x008800D0
extern int gnGlideDebugY;                                                                          // 0x008800D4
extern unsigned int gnGlideBinkY;                                                                  // 0x00880C04
extern unsigned int gnGlideBinkX;                                                                  // 0x00880C08
extern D2BinkStrc* gpGlideBink;                                                                    // 0x00880C0C
extern unsigned int gnGlideBinkFlags;                                                              // 0x00880C14
extern int gbGlideBinkDone;                                                                        // 0x00880C18
extern D2DDrawObjectStrc* gpDDrawObject_00881290;                                                           // 0x00881290
extern int gaDDrawDebugFontGlyphOffsets[96];                                                       // 0x008812A8
extern int gaDDrawDebugFontCharWidths[96];                                                         // 0x00881428
extern unsigned long gdwDDrawDebugFontBkColor;                                                     // 0x008815A8
extern unsigned char* gpDDrawDebugFontGlyphs;                                                      // 0x008815AC
extern unsigned int gnDDrawBinkY;                                                                  // 0x008816B8
extern unsigned int gnDDrawBinkX;                                                                  // 0x008816BC
extern D2BinkStrc* gpDDrawBink;                                                                    // 0x008816C0
extern unsigned int gnDDrawBinkFlags;                                                              // 0x008816C8
extern int gbDDrawBinkDone;                                                                        // 0x008816CC

// 0x0050BF50
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnRenderWidth);
    nXEnd = D2_MIN(D2_MAX(nXEnd, 0), gnRenderWidth);
    if (nX1 == nXEnd)
        return;
// build: symbol ?gnRenderHeight@* 0x007C913C
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnRenderHeight);
    nYEnd = D2_MIN(D2_MAX(nYEnd, 0), gnRenderHeight);
    if (nYEnd == nY1)
        return;
    D2_ASSERT(nYEnd > nY1, 0x29);
    GLCORE_SetColorCombineMode(2);
    GLCORE_SetAlphaBlendMode(4);
    gpfnGrChromakeyMode(0);
    vertices[0].x = (float)nX1;
    vertices[0].y = (float)nY1;
    vertices[0].oow = 1.0f;
    vertices[0].sow = 0.0f;
    vertices[0].tow = 0.0f;
    vertices[1].x = (float)nX1;
    vertices[1].y = (float)nYEnd;
    vertices[1].oow = 1.0f;
    vertices[1].sow = 0.0f;
    vertices[1].tow = 0.0f;
    vertices[2].x = (float)nXEnd;
    vertices[2].y = (float)nYEnd;
    vertices[2].oow = 1.0f;
    vertices[2].sow = 0.0f;
    vertices[2].tow = 0.0f;
    vertices[3].x = (float)nXEnd;
    vertices[3].y = (float)nY1;
    vertices[3].oow = 1.0f;
    vertices[3].sow = 0.0f;
    vertices[3].tow = 0.0f;
    unsigned int dwRGBA = GLCORE_GetPaletteColor((unsigned char)dwColor) & 0xFFFFFF00;
    switch (nDrawMode)
    {
    case 0:
        dwRGBA += 0x40;
        break;
    case 1:
        dwRGBA += 0x80;
        break;
    case 2:
        dwRGBA += 0xC0;
        break;
    default:
        dwRGBA += 0xFF;
        break;
    }
    gpfnGrConstantColorValue(dwRGBA);
    gpfnGrDrawVertexArrayContiguous(5, 4, vertices, sizeof(D2GlideSpriteVertexStrc));
    gpfnGrChromakeyMode(1);
}

// 0x0050C0F0
void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    D2GlideSpriteVertexStrc vertices[4];
    const int nX1 = D2_MIN(D2_MAX(nXStart, 0), gnRenderWidth);
    nXEnd = D2_MIN(D2_MAX(nXEnd, 0), gnRenderWidth);
    if (nX1 == nXEnd)
        return;
    const int nY1 = D2_MIN(D2_MAX(nYStart, 0), gnRenderHeight);
    nYEnd = D2_MIN(D2_MAX(nYEnd, 0), gnRenderHeight);
    if (nYEnd == nY1)
        return;
    D2_ASSERT(nYEnd > nY1, 0x61);
    GLCORE_SetColorCombineMode(2);
    GLCORE_SetAlphaBlendMode(4);
    gpfnGrChromakeyMode(0);
    vertices[0].x = (float)nX1;
    vertices[0].y = (float)nY1;
    vertices[0].oow = 1.0f;
    vertices[0].sow = 0.0f;
    vertices[0].tow = 0.0f;
    vertices[1].x = (float)nX1;
    vertices[1].y = (float)nYEnd;
    vertices[1].oow = 1.0f;
    vertices[1].sow = 0.0f;
    vertices[1].tow = 0.0f;
    vertices[2].x = (float)nXEnd;
    vertices[2].y = (float)nYEnd;
    vertices[2].oow = 1.0f;
    vertices[2].sow = 0.0f;
    vertices[2].tow = 0.0f;
    vertices[3].x = (float)nXEnd;
    vertices[3].y = (float)nY1;
    vertices[3].oow = 1.0f;
    vertices[3].sow = 0.0f;
    vertices[3].tow = 0.0f;
    gpfnGrConstantColorValue(GLCORE_GetPaletteColor((unsigned char)dwColor) & 0xFFFFFF00 | nAlpha);
    gpfnGrDrawVertexArrayContiguous(5, 4, vertices, sizeof(D2GlideSpriteVertexStrc));
    gpfnGrChromakeyMode(1);
}

extern int gnRenderWidth; // 0x007C9138
extern D2GlideSpriteVertexStrc gaGlideTileQuad[4]; // 0x00880600

typedef void (__stdcall* GLIDEDRAWVERTEXARRAYCONTIGUOUS)(int nMode, int nCount, void* pVertices, int nStride);

extern GLIDEDRAWVERTEXARRAYCONTIGUOUS gpfnGrDrawVertexArrayContiguous; // 0x0087EAC4
void __fastcall GLVERTEX_SetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nIntensity); // 0x0050DBE0

struct D2TileVertexStrc
{
    unsigned char aColor[4];
    int nX;
    int nY;
};

typedef void (__stdcall* GlideConstantColorFn)(unsigned int dwColor);

typedef void (__stdcall* GlideDrawVertexArrayFn)(int nMode, int nCount, void** ppVertices);

int __fastcall GLTEXTURECACHE_BindFloorTexture(void* pTile); // 0x0050FAD0
void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500
void __fastcall GLCORE_SetTextureFilterMode(int nMode); // 0x005095D0
extern GlideConstantColorFn gpfnGrConstantColorValue; // 0x0087EFA0
extern GlideDrawVertexArrayFn gpfnGrDrawVertexArray; // 0x0087EB18
extern unsigned char* gpBlendTable; // 0x00880B5C
extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148
extern D2GlideSpriteVertexStrc gatGlideTileVertices[36]; // 0x00880678
extern void* gapGlideTileFan[4]; // 0x0072F670
extern void* gapGlideTileStrips_00880A68[5][12]; // 0x00880A68

// 0x0050C890
int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels)
{
    tagRECT tRect;
    tRect.left = 0;
    tRect.top = 0;
    tRect.right = gnRenderWidth;
// build: symbol ?gnRenderHeight@* 0x007C913C
    tRect.bottom = gnRenderHeight - 47;
    tRect.left -= 32;
    tRect.bottom += 32;

    int bDrawn = 0;
    if (nScreenPanels == 1)
    {
        tRect.right += -(gnRenderWidth / 2);
    }
    else if (nScreenPanels == 2)
    {
        tRect.left = gnRenderWidth / 2 - 32;
    }

    nPosY += 32;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        int nLeft = nPosX + pTile->pBlocks[i].nPosX;
        int nBottom = pTile->pBlocks[i].nPosY + nPosY;
        if (nLeft >= tRect.left && nLeft < tRect.right && nBottom >= tRect.top && nBottom < tRect.bottom)
        {
            int nTop = nBottom - 32;
            bDrawn = 1;
            int nRight = nLeft + 32;
            sub_0050FBD0_GlideBindTileTexture(&pTile->pBlocks[i]);
            gaGlideTileQuad[0].x = (float)nLeft;
            gaGlideTileQuad[0].y = (float)nTop;
            gaGlideTileQuad[1].x = (float)nLeft;
            gaGlideTileQuad[1].y = (float)nBottom;
            gaGlideTileQuad[2].x = (float)nRight;
            gaGlideTileQuad[2].y = (float)nBottom;
            gaGlideTileQuad[3].x = (float)nRight;
            gaGlideTileQuad[3].y = (float)nTop;
            GLVERTEX_SetVertexAmbientColor(gaGlideTileQuad, nShade);
            gaGlideTileQuad[1].dwColor = gaGlideTileQuad[0].dwColor;
            gaGlideTileQuad[2].dwColor = gaGlideTileQuad[0].dwColor;
            gaGlideTileQuad[3].dwColor = gaGlideTileQuad[0].dwColor;
            gpfnGrDrawVertexArrayContiguous(5, 4, gaGlideTileQuad, sizeof(D2GlideSpriteVertexStrc));
        }
    }

    return bDrawn;
}

static __forceinline void GLIDE_SetTileVertex(const D2TileVertexStrc* pSource, D2GlideSpriteVertexStrc* pVertex)
{
    const unsigned char* pRow = &gpBlendTable[pSource->aColor[0] << 8];
    pVertex->dwColor = (((-1 << 8 | pRow[pSource->aColor[1]]) << 8 | pRow[pSource->aColor[2]]) << 8) | pRow[pSource->aColor[3]];
    pVertex->x = (float)pSource->nX;
    pVertex->y = (float)pSource->nY;
}

// 0x0050D6A0
void __fastcall sub_0050D6A0_GlideDrawFloorTile(void* pTile, const D2TileVertexStrc* pVertices, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, int bDepth)
{
    if (!GLTEXTURECACHE_BindFloorTexture(pTile))
        return;

    GLCORE_SetColorCombineMode(1);
    if (nAlpha == 0xFF)
    {
        GLCORE_SetAlphaBlendMode(1);
    }
    else
    {
        GLCORE_SetAlphaBlendMode(4);
        gpfnGrConstantColorValue(nAlpha);
    }
    if (bDepth)
        GLCORE_SetTextureFilterMode(2);
    else
        GLCORE_SetTextureFilterMode(1);

    if (gpGfxSettings->bLowQuality)
    {
        GLIDE_SetTileVertex(&pVertices[0], &gatGlideTileVertices[0]);
        GLIDE_SetTileVertex(&pVertices[5], &gatGlideTileVertices[5]);
        GLIDE_SetTileVertex(&pVertices[35], &gatGlideTileVertices[35]);
        GLIDE_SetTileVertex(&pVertices[30], &gatGlideTileVertices[30]);
        gpfnGrDrawVertexArray(5, 4, gapGlideTileFan);
        return;
    }

    const D2TileVertexStrc* pSrc = pVertices;
    D2GlideSpriteVertexStrc* pDst = gatGlideTileVertices;
    for (unsigned int i = 0; i < 36; i++, pSrc++, pDst++)
        GLIDE_SetTileVertex(pSrc, pDst);

    for (int i = 0; i < 5; i++)
        gpfnGrDrawVertexArray(4, 12, gapGlideTileStrips_00880A68[i]);
}

struct D2TileLibraryEntryStrc;

void __fastcall GLCORE_SetColorCombineMode(int nState);                                                      // 0x005094B0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500
void __fastcall GLCORE_SetTextureFilterMode(int nMode);                                                       // 0x005095D0
int __cdecl sub_0050BF40_GlideGetBlendedShadows();                                                                    // 0x0050BF40
int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels); // 0x0050C890
int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels); // 0x0050CA00
int __cdecl GLVERTEX_IsPerspective();                                                               // 0x0050DD30
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor);                              // 0x0087EFA0

// 0x0050CD40
int __fastcall sub_0050CD40_GlideShadowTileDraw(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels)
{
    int nResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
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
        if (GLVERTEX_IsPerspective())
        {
            nResult = sub_0050CA00_GlideShadowTileDrawPerspective(pTile, nPosX, nPosY, eDrawMode, nScreenPanels);
        }
        else
        {
            nResult = sub_0050C890_GlideTileDrawShaded(pTile, nPosX, nPosY, eDrawMode, nScreenPanels);
        }
    }

    return nResult;
}

#include "gen/data/Source/D2Glide/Unknown_0050BD30.inc"
