#include "FogApi.h"
#include "D2GfxApi.h"
extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260

struct D2TileGfxStrc
{
    unsigned int nOrientation;
};

struct D2CellTileStrc
{
    int nX;
    int nY;
    char unk0x08[0x0C];
    unsigned int dwFlags;
    D2TileGfxStrc* pTile;
    int eTileType;
    int unk0x20;
    unsigned int dwFadeFlags;
    unsigned char nAlpha;
    unsigned char nAlphaFrom;
    unsigned char nAlphaTo;
    unsigned char unk0x2B;
    unsigned int dwEndTick;
};

struct D2LightPointStrc
{
    int nX;
    int nY;
};

struct D2CellTileNodeStrc
{
    unsigned int dwFlags;
    D2LightPointStrc* pLightA;
    D2LightPointStrc* pLightB;
    D2CellTileStrc* pTile;
    D2CellTileNodeStrc* pNext;
};

struct D2GridCellStrc
{
    int unk0x00[4];
    D2CellTileNodeStrc* pNodes;
    D2CellTileNodeStrc* pTiles;
};

struct D2CellGridViewStrc
{
    int unk0x00;
    int nOffsetX;
    int nOffsetY;
    int unk0x0C[6];
    int nScrollX;
    int nScrollY;
};

struct D2LightPairStrc
{
    int nA;
    int nB;
};

int __cdecl UI_GetPanelSlideMode();                                                                         // 0x0045AE90
int __cdecl DLIGHTMAP_GetRenderMode();                                                                                 // 0x00477730
void __fastcall SCMD_ReadGridCell(D2LightPointStrc* pA, D2LightPointStrc* pB, unsigned char* pC0, unsigned char* pC1, unsigned char* pC2, unsigned char* pC3); // 0x00475AA0
int __stdcall TILE_TileDrawLit(D2TileGfxStrc* pTile, int nX, int nY, unsigned int* pLight, int nGamma);   // 0x004F6920
int __stdcall TILE_TileDrawTrans(D2TileGfxStrc* pTile, int nX, int nY, unsigned int* pLight, int nGamma, unsigned char nAlpha); // 0x004F6950

extern unsigned int gaLightSampleCounts[];                                                           // 0x006DB9D8
extern D2LightPairStrc gaLightOffsetsB[][6];                                                         // 0x0072A9E8
extern D2LightPairStrc gaLightOffsetsA[][6];                                                         // 0x0072ABC8

static D2LightPairStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileGfxStrc* pTile, unsigned int* pCount, int bAlternate)
{
    *pCount = gaLightSampleCounts[pTile->nOrientation];
    if (bAlternate)
        return gaLightOffsetsA[pTile->nOrientation];
    return gaLightOffsetsB[pTile->nOrientation];
}

// 0x004DEF80
void __stdcall DWALL_DrawCellTiles(D2GridCellStrc* pCell, int nPass, D2CellGridViewStrc* pView)
{
    const int nGamma = UI_GetPanelSlideMode();
    const int bPerspective = D2GFX_CheckPerspective();
    const int nDetail = DLIGHTMAP_GetRenderMode();
    const unsigned int dwTick = GetTickCount();
    const int bFade = nDetail >= 4;
    D2_ASSERT(nPass == 0 || nPass == 1, 0xF3);

    for (D2CellTileNodeStrc* pNode = pCell->pTiles; pNode; pNode = pNode->pNext)
    {
        D2CellTileStrc* ptTile = pNode->pTile;
        D2_ASSERT(ptTile->eTileType != 0xF, 0xF9);

        const unsigned int dwFade = ptTile->dwFadeFlags;
        if (dwFade & 2)
        {
            if (bFade)
            {
                if (dwTick < ptTile->dwEndTick)
                {
                    ptTile->nAlpha = ptTile->nAlphaFrom + (ptTile->nAlphaTo - ptTile->nAlphaFrom) * (int)(dwTick - ptTile->dwEndTick + 500) / 500;
                }
                else
                {
                    unsigned char* pAlpha = &ptTile->nAlpha;
                    *pAlpha = ptTile->nAlphaTo;
                    ptTile->dwFadeFlags = dwFade & ~2;
                }
            }
            else
            {
                unsigned char* pAlpha = &ptTile->nAlpha;
                *pAlpha = ptTile->nAlphaTo;
                ptTile->dwFadeFlags = dwFade & ~2;
            }

            if (!ptTile->nAlpha)
                ptTile->dwFlags |= 0x400;
            else
                ptTile->dwFlags &= ~0x400;
        }

        if ((ptTile->dwFadeFlags & 4) && dwTick >= ptTile->dwEndTick)
        {
            ptTile->dwFadeFlags &= ~4;
            ptTile->dwFlags |= 8;
        }

        if (!(ptTile->dwFlags & 0x408) && nPass != ((ptTile->dwFlags & 0x1C000) != 0))
        {
            unsigned int nCount;
            const D2LightPairStrc* pPairs = sub_004DEDB0_GetLightOffsets(ptTile->pTile, &nCount, ptTile->dwFadeFlags & 1);
            unsigned int aLight[8];
            for (unsigned int i = 0; i < nCount; ++i)
            {
                unsigned char nC0, nC1, nC2, nC3;
                SCMD_ReadGridCell(&pNode->pLightA[pPairs[i].nA], &pNode->pLightB[pPairs[i].nB], &nC0, &nC1, &nC2, &nC3);
                nC0 = nC0 > 0 ? nC0 : 0;
                aLight[i] = (((((nC3 << 8) | nC2) << 8) | nC1) << 8) | nC0;
            }

            const unsigned char nAlpha = ptTile->nAlpha;
            int nX;
            int nY;
            if (bPerspective)
            {
                nX = (int)pNode->pLightA;
                nY = (int)pNode->pLightB;
            }
            else
            {
                nX = pView->nOffsetX - pView->nScrollX + ptTile->nX;
                nY = ptTile->nY - pView->nScrollY + pView->nOffsetY;
            }

            int bDrawn;
            if (nAlpha != 0xFF)
                bDrawn = TILE_TileDrawTrans(ptTile->pTile, nX, nY, aLight, nGamma, nAlpha);
            else
                bDrawn = TILE_TileDrawLit(ptTile->pTile, nX, nY, aLight, nGamma);

            if (bDrawn)
                ptTile->dwFlags |= 0x20000;
        }
    }
}
