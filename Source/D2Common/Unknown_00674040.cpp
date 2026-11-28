#include "D2Common.h"
#include "D2CommonInternal.h"
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

#pragma pack(push, 1)
struct d2data_0074996C_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_0074996C_t gData_0074996C; // 0x0074996C
extern "C" const D2OutdoorOffsetStrc gData_006F05D8[4]; // 0x006F05D8

extern "C" struct d2data_0074996C_t gData_0074996C = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x0074996C

extern "C" const D2OutdoorOffsetStrc gData_006F05D8[4] = {
    { -4, 4 },
    { 4, -4 },
    { 12, 4 },
    { 4, 12 }
}; // 0x006F05D8
#pragma comment(linker, "/alternatename:?gaOutLinkVisOffsets@@3PAUD2OutdoorOffsetStrc@@A=_gData_006F05D8")
