#include "D2DDraw.h"

#include "D2DDrawTypes.h"

#include "D2GlideTypes.h"

#include "D2DrlgMaps.h"
#include "D2CoordPair.h"
#include "D2TileLight.h"

struct D2CoordPairStrc;

struct D2TileLightStrc;

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC

extern int gaDDrawDebugFontGlyphOffsets[96]; // 0x008812A8

extern unsigned char* gpDDrawDebugFontGlyphs; // 0x008815AC

extern int gaDDrawDebugFontCharWidths[96]; // 0x00881428


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern D2DDrawSurfaceStrc* gpDDrawOffscreenSurface; // 0x00881280


int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int bAsync, int nFlags); // 0x005FDEA0

int gaDDrawDebugFontCharWidths[96]; // 0x00881428

// 0x00512A50
void __fastcall sub_00512A50_DrawLine(D2CoordPairStrc* pFrom, D2CoordPairStrc* pTo, unsigned char nColor)
{
    const int nStartX = pTo->nX;
    const int nStartY = pTo->nY;
    int nDeltaX = pFrom->nX - nStartX;
    int nDeltaY = pFrom->nY - nStartY;
    if (!nDeltaX && !nDeltaY)
        return;

    const int nLengthSq = nDeltaX * nDeltaX + nDeltaY * nDeltaY;
    int nLength = 0;
    while (nLength * nLength < nLengthSq)
        ++nLength;

    const int nStepX = (nDeltaX << 16) / nLength;
    const int nStepY = (nDeltaY << 16) / nLength;
    int nFracX = 0;
    int nX = nStartX;
    int nFracY = 0;
    int nY = nStartY;
    int i = 0;

// build: symbol ?gnRenderHeight@* 0x007C913C
    while (!(nY >= 0 && nY < gnRenderHeight && nX >= 0 && nX < gnRenderWidth))
    {
        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nStep = nFracX / 0x10000;
            nX += nStep;
            nFracX -= nStep * 0x10000;
        }

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nStep = nFracY / 0x10000;
            nY += nStep;
            nFracY -= nStep * 0x10000;
        }

        if (i >= nLength)
            return;
        ++i;
    }

    unsigned char* pPixel = gpScreenBuffer_007C9154 + nY * gnRenderWidth + nX;
    *pPixel = nColor;

    for (++i; i < nLength; ++i)
    {
        nFracX += nStepX;
        if (nFracX >= 0x10000 || nFracX <= -0x10000)
        {
            const int nStep = nFracX / 0x10000;
            nX += nStep;
            pPixel += nStep;
            nFracX -= nStep * 0x10000;
        }

        if (nX < 0 || nX >= gnRenderWidth)
            return;

        nFracY += nStepY;
        if (nFracY >= 0x10000 || nFracY <= -0x10000)
        {
            const int nStep = nFracY / 0x10000;
            nY += nStep;
            pPixel += nStep * gnRenderWidth;
            nFracY -= nStep * 0x10000;
        }

        if (nY < 0 || nY >= gnRenderHeight)
            return;

        *pPixel = nColor;
    }
}

// 0x00512ED0
void __fastcall sub_00512ED0_ClearScreen(int bPartial)
{
    D2DDBltFxStrc tBltFx = { sizeof(D2DDBltFxStrc) };
    tBltFx.dwFillColor = 0;

    if (gpDDrawOffscreenSurface)
    {
        long nResult = gpDDrawOffscreenSurface->lpVtbl->Blt(gpDDrawOffscreenSurface, 0, 0, 0, 0x400, &tBltFx);
        if (nResult)
        {
            if (nResult == 0x887601AE)
            {
                if (bPartial)
                {
                    memset(gpScreenBuffer_007C9154, 0, gnRenderWidth * (gnRenderHeight - 47));
                }
                else
                {
                    memset(gpScreenBuffer_007C9154, 0, gnRenderWidth * gnRenderHeight);
                }
            }
            else
            {
                sub_005103B0("Blit (screen clear) failed!", nResult);
            }
        }
    }
}

int __cdecl DDCORE_GetBlendedShadows(); // 0x00512700

// 0x00512F90
int __fastcall sub_00512F90_DrawWallTile(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, void* pLight, int nScreenPanels)
{
    int bDrawn = 0;

    if (D2CMPTileValidate(pTile, 1, 0))
    {
        int nMinX = -32;
// build: symbol ?gnRenderWidth@* 0x007C9138
        int nMaxX = gnRenderWidth;
// build: symbol ?gnRenderHeight@* 0x007C913C
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
                if (DDCORE_GetBlendedShadows())
                    gpTileDrawFunctions_007C914C->pfDrawShadowBlock(pTile->pBlocks[i].pData, nX, nY, 0xC0);
                else
                    gpTileDrawFunctions_007C914C->pfDrawWallBlock(pTile->pBlocks[i].pData, nX, nY);
            }
        }
    }

    return bDrawn;
}

// 0x005130A0
int __fastcall sub_005130A0_DrawLitTile(D2TileLibraryEntryStrc* pTile, int nX, int nY, unsigned char* pLight, int nHalf, int nArg)
{
    int bResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        int nLeft = -32;
        int nRight = gnRenderWidth;
        const int nBottom = gnRenderHeight + 32;
        switch (nHalf)
        {
        case 1:
            nRight -= gnRenderWidth / 2;
            break;
        case 2:
            nLeft = gnRenderWidth / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            const int nPosX = pTile->pBlocks[i].nPosX + nX;
            const int nPosY = pTile->pBlocks[i].nPosY + nY;
            if (nPosX >= nLeft && nPosX < nRight && nPosY >= -32 && nPosY < nBottom)
            {
                const int nIndex = pTile->pBlocks[i].nPosX >> 5;
                D2GlideTileStrc* pBlock = i + pTile->pBlocks;
                D2TileLightStrc tLight;
                bResult = 1;
                tLight.nCorner[0] = pLight[4 * nIndex];
                tLight.nCorner[3] = pLight[4 * nIndex];
                tLight.nCorner[1] = pLight[4 * nIndex + 4];
                tLight.nCorner[2] = pLight[4 * nIndex + 4];
                gpTileDrawFunctions_007C914C->pfDrawLitBlock(pBlock->pData, nPosX, nPosY, &tLight, nArg);
            }
        }
    }

    return bResult;
}

// 0x005131B0
int __fastcall sub_005131B0_DrawTile(D2TileLibraryEntryStrc* pTile, int nX, int nY, unsigned char* pLight, int nHalf)
{
    int bResult = 0;
    if (D2CMPTileValidate(pTile, 1, 0))
    {
        int nLeft = -32;
        int nRight = gnRenderWidth;
        const int nBottom = gnRenderHeight + 32;
        switch (nHalf)
        {
        case 1:
            nRight -= gnRenderWidth / 2;
            break;
        case 2:
            nLeft = gnRenderWidth / 2 - 32;
            break;
        }

        for (int i = 0; i < pTile->nBlocks; ++i)
        {
            const int nPosX = pTile->pBlocks[i].nPosX + nX;
            const int nPosY = pTile->pBlocks[i].nPosY + nY;
            if (nPosX >= nLeft && nPosX < nRight && nPosY >= -32 && nPosY < nBottom)
            {
                const int nIndex = pTile->pBlocks[i].nPosX >> 5;
                D2GlideTileStrc* pBlock = i + pTile->pBlocks;
                D2TileLightStrc tLight;
                tLight.nCorner[3] = tLight.nCorner[0] = pLight[4 * nIndex];
                tLight.nCorner[2] = tLight.nCorner[1] = pLight[4 * nIndex + 4];
                bResult = 1;
                gpTileDrawFunctions_007C914C->pfDrawBlock(pBlock->pData, nPosX, nPosY, &tLight);
            }
        }
    }

    return bResult;
}
