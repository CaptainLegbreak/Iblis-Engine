#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2LevelTxt.h"

struct D2DrlgCoordStrc;

struct D2DrlgVertexStrc;

struct D2OutdoorOffsetStrc;

struct D2DrlgOutdoorInfoStrc;

struct D2LvlPrestTxt;

struct D2OutdoorOffsetStrc { int nX; int nY; };

extern D2OutdoorOffsetStrc gaOutLinkVisOffsets[]; // 0x006F05D8

int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY); // 0x0066B980

int __fastcall DATATBLS_GetVisFlagToLevel(D2DrlgLevelStrc* pLevel, D2DrlgLevelStrc* pOtherLevel); // 0x00673FF0

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId); // 0x0061F0B0

int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C4A0

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pDrlgGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0

int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040

// 0x00673FF0
int __fastcall DATATBLS_GetVisFlagToLevel(D2DrlgLevelStrc* pLevel, D2DrlgLevelStrc* pOtherLevel)
{
    int* pLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
    int i = 0;
    for (; i < 8; ++i)
    {
        if (pLevelIds[i] == pOtherLevel->eLevelId)
        {
            break;
        }
    }

    if (i == 8)
    {
        return 0;
    }

    return 1 << (i + 4);
}

// 0x00674040
int __fastcall DRLGOUTDOORS_GetOutLinkVisFlag(D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pVertex)
{
    int y = pVertex->nPosY;
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    int x = pVertex->nPosX;
    int side;
    if (!x)
        side = y == 0;
    else
    {
        int const nMaxX = pOutdoor->nGridWidth - 1;
        if (!y)
            side = (x == nMaxX) + 1;
        else if (x == nMaxX)
            side = (y == pOutdoor->nGridHeight - 1) + 2;
        else if (y == pOutdoor->nGridHeight - 1)
            side = 3;
        else
            return 0;
    }
    int nSubtileX = gaOutLinkVisOffsets[side].nX + 8 * pVertex->nPosX + pLevel->nPosX;
    int nSubtileY = gaOutLinkVisOffsets[side].nY + 8 * pVertex->nPosY + pLevel->nPosY;
    for (D2DrlgOrthStrc* pLink = pOutdoor->pRoomData; pLink; pLink = pLink->pNext)
    {
        if (side == pLink->nDirection && DRLGROOM_AreXYInsideCoordinates(pLink->pBox, nSubtileX, nSubtileY))
        {
            if (pLink->bInit)
                return 0;
            return DATATBLS_GetVisFlagToLevel(pLevel, pLink->pLevel);
        }
    }
    return 0;
}

// 0x00674120
int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (!(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x200))
    {
        return 0;
    }
    return DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY);
}

static inline int DRLGOUTDOORS_GetPackedGrid2Info(D2DrlgOutdoorInfoStrc* pOutdoors, int nX, int nY)
{
    return DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
}

static inline int DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    return !(DRLGOUTDOORS_GetPackedGrid2Info(pLevel->pOutdoors, nX, nY) & 0x1B81);
}

// 0x00674160
void __fastcall DRLGOUTDOORS_AlterAdjacentPresetGridCells(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[0], nX, nY, 0, 3);
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0, 3);
}

// 0x006741A0
void __fastcall DRLGOUTDOORS_SetBlankGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[0], nX, nY, 0, 3);
    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x100, 3);
}

// 0x006741E0
unsigned int __fastcall DRLGOUTDOORS_TestGridCellNonLvlLink(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    const unsigned int nPackedValue = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
    return ((nPackedValue >> 10) & 1) == 0;
}

// 0x00674230
int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, int nFlags)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nSizeX;
    int nSizeY;
    if (!nLevelPrestId)
    {
        nSizeX = 1;
        nSizeY = 1;
    }
    else
    {
        D2LvlPrestTxt* pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
        nSizeX = pLvlPrestTxtRecord->nSizeX / 8;
        nSizeY = pLvlPrestTxtRecord->nSizeY / 8;
    }

    if (nOffset)
    {
        if (nFlags & 1)
        {
            nY -= nOffset;
            nSizeY += nOffset;
        }
        if (nFlags & 2)
        {
            nSizeX += nOffset;
        }
        if (nFlags & 4)
        {
            nSizeY += nOffset;
        }
        if (nFlags & 8)
        {
            nX -= nOffset;
            nSizeX += nOffset;
        }
    }
    const int nYEnd = nY + nSizeY;
    for (int i = nY; i < nYEnd; ++i)
    {

        for (int j = nX; j < nX + nSizeX; ++j)
        {
            if (!DRLGGRID_IsPointInsideGridArea(&pOutdoors->pGrid[2], j, i) || !DRLGOUTDOORS_TestGridCellSpawnValid(pLevel, j, i))
            {
                return 0;
            }
        }
    }

    return 1;
}

#include "gen/data/Source/D2Common/Unknown_00674040.inc"
