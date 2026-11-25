#include "D2Client.h"

#include "D2DrlgMaps.h"

#include "D2ClientUi.h"

#include "D2ClientSound.h"
#include "D2ClientTileLight.h"



struct D2TileLightEntryStrc
{
    int unk0x00[8];
    D2TileLightNodeStrc* pList;
};

struct D2TileLightCtxStrc
{
    int unk0x00;
    int nX;
    int nY;
    int unk0x0C[6];
    int f_24;
    int f_28;
    char unk0x2C[0xEAA8 - 0x2C];
    D2TileLightEntryStrc* pEntries;
    int unk0xEAAC;
    unsigned int nSize;
};

extern D2LightOffsetsStrc gaLightOffsetsA[]; // 0x0072ABC8

extern D2LightOffsetsStrc gaLightOffsetsB[]; // 0x0072A9E8

int __cdecl sub_0045AE90(); // 0x0045AE90

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

void __fastcall SCMD_ReadGridCell(int nX, int nY, unsigned char* pValue0, unsigned char* pValue1, unsigned char* pValue2, unsigned char* pValue3); // 0x00475AA0

int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha); // 0x004F6950

int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels); // 0x004F6920

// 0x004DEDB0
static D2LightOffsetsStrc* __stdcall sub_004DEDB0_GetLightOffsets(D2TileLibraryEntryStrc* pTile, unsigned int* pCount, int bAlternate)
{
// build: symbol ?gaLightSampleCounts@* 0x006DB9D8
    *pCount = gaLightSampleCounts[pTile->nLightDirection];
    if (bAlternate)
        return &gaLightOffsetsA[pTile->nLightDirection];
    return &gaLightOffsetsB[pTile->nLightDirection];
}

// 0x004DEDF0
static void __stdcall sub_004DEDF0_UpdateTileLights(D2TileLightEntryStrc* pEntry, D2TileLightCtxStrc* pCtx)
{
    if (!pEntry->pList)
        return;

    const int nScreenPanels = sub_0045AE90();
    const int bPerspective = sub_004F51D0_IsPerspective();
    const unsigned int nTick = GetTickCount();
    for (D2TileLightNodeStrc* pNode = pEntry->pList; pNode; pNode = pNode->pNext)
    {
        D2DrlgTileDataStrc* pTileData = pNode->pTileData;
        if ((pTileData->dwPopFlags & 4) && nTick >= pTileData->nPopTick)
        {
            pTileData->dwPopFlags &= ~4;
            pTileData->dwFlags |= 8;
        }

        if (pTileData->dwFlags & 0x408)
            continue;

        if (!(pTileData->dwFlags & 0x1C000))
            continue;

        unsigned int nCount;
        D2LightOffsetsStrc* pOffsets = sub_004DEDB0_GetLightOffsets(pTileData->pTile, &nCount, pTileData->dwPopFlags & 1);
        D2GfxLightStrc tLight;
        for (unsigned int i = 0; i < nCount; ++i)
        {
            unsigned char nValue0;
            unsigned char nValue1;
            unsigned char nValue2;
            unsigned char nValue3;
            SCMD_ReadGridCell(pNode->nX + 8 * pOffsets->aOffset[i].nX, pNode->nY + 8 * pOffsets->aOffset[i].nY, &nValue0, &nValue1, &nValue2, &nValue3);
            nValue0 = nValue0 > 0 ? nValue0 : 0;
            tLight.aColor[i] = (nValue3 << 24) | (nValue2 << 16) | (nValue1 << 8) | nValue0;
        }

        const unsigned char nAlpha = pTileData->nRed;
        int nX;
        int nY;
        if (bPerspective)
        {
            nX = pNode->nX;
            nY = pNode->nY;
        }
        else
        {
            nX = pCtx->nX - pCtx->f_24 + pTileData->nWidth;
            nY = pTileData->nHeight - pCtx->f_28 + pCtx->nY;
        }

        int bDrawn;
        if (nAlpha != 0xFF)
            bDrawn = TILE_TileDrawTrans(pTileData->pTile, nX, nY, &tLight, nScreenPanels, nAlpha);
        else
            bDrawn = TILE_TileDrawLit(pTileData->pTile, nX, nY, &tLight, nScreenPanels);

        if (bDrawn)
            pTileData->dwFlags |= 0x20000;
    }
}

// 0x004DF480
void __fastcall sub_004DF480_UpdateAllTileLights(D2TileLightCtxStrc* pCtx)
{
    int nCount = pCtx->nSize * pCtx->nSize;
    D2TileLightEntryStrc* pEntry = pCtx->pEntries;
    while (nCount--)
    {
        sub_004DEDF0_UpdateTileLights(pEntry, pCtx);
        ++pEntry;
    }
}

#include "gen/data/Source/D2Client/Unknown_004DEDB0.inc"
