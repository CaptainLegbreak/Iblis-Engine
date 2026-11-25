#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2DrlgTiles.h"
#include "D2Common.h"

#pragma function(memset)

struct D2DrlgCoordStrc;

struct D2CoordStrc;

struct D2DrlgStrc;

struct D2DrlgLevelStrc;

struct D2DrlgGridStrc;

struct D2RoomCoordListStrc;

struct D2DrlgLogicalRoomInfoStrc;

struct D2DrlgTileDataStrc;

struct D2DrlgTileLinkStrc;

struct D2DrlgRoomTilesStrc;

struct D2DrlgTileGridStrc;

struct D2DrlgRoomStrc;

union D2PackedFloorStrc;

struct D2UnkDrlgLogicStrc;


struct D2DrlgLogicalRoomInfoStrc
{
    int dwFlags;
    int nLists;
    D2DrlgGridStrc pIndexX;
    D2DrlgGridStrc pIndexY;
    D2RoomCoordListStrc* pCoordList;
};

union D2PackedFloorStrc
{
    unsigned int nPackedValue;
    struct
    {
        unsigned int nLow : 31;
        unsigned int bHidden : 1;
    };
};

struct D2UnkDrlgLogicStrc
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2DrlgGridStrc* field_4;
    D2DrlgGridStrc* pTileTypeGrid;
    D2DrlgGridStrc* pWallGrid;
    D2DrlgGridStrc* pFloorGrid;
    D2DrlgGridStrc* field_14;
    int field_18;
    int nFlags;
};

extern "C" const D2CoordStrc gLogicDirections[]; // 0x006EEE14

extern "C" const int gnLogicTileFlags[]; // 0x006EEE38

extern "C" const int gnLogicTileIndex[]; // 0x006EEEA0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance); // 0x0066B860

int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY); // 0x0066B9D0

int __fastcall DRLGGRID_IsGridValid(D2DrlgGridStrc* pGrid); // 0x0067C480

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight); // 0x0067CB80

void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags); // 0x0067CBF0

void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid); // 0x0067CDC0

static void __stdcall DRLGLOGIC_MarkBlockingTilesInGrid(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pDrlgGrid);

void __stdcall DRLGLOGIC_SetCoordListForTiles(D2DrlgRoomStrc* pDrlgRoom); // 0x0066C9C0

void __stdcall DRLGLOGIC_AssignCoordListsForGrids(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLogicalRoomInfoStrc* pDrlgCoordList); // 0x0066CA50


void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid); // 0x0067CD90

D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordListAtSubtile(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);

enum D2C_U04DrlgLogicConstants
{
    FLAG_OPERATION_OVERWRITE = 3,
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430

void __fastcall DRLGLOGIC_SetTileGridFlags(D2UnkDrlgLogicStrc* a1, int nX, int nY, int a4);

static void DRLGLOGIC_FloodFillUnassignedTiles(D2UnkDrlgLogicStrc* a1);

D2DrlgLogicalRoomInfoStrc* __fastcall DRLGLOGIC_AllocLogicalRoomInfo(void* pMemPool, int nUnused, D2DrlgRoomStrc* pDrlgRoom);

static void DRLGLOGIC_AllocCoordListArray(void* pMemPool, D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo, int nLists);

void __fastcall DRLGLOGIC_ReplaceCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nIndex1, int nIndex2, int bNode);

static void __stdcall DRLGLOGIC_MarkWallTilesInGrid(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pWallGrid);

void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom);

int __fastcall DRLGLOGIC_GetRoomCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);

static void __stdcall DRLGLOGIC_MergeCoordListsAtPoint(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nX, int nY);

static void DRLGLOGIC_MergeCoordListsWithNearRooms(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid);

inline int HasMapTileLayer(unsigned int dwFlags)
{
    return (dwFlags & 0x1C000) != 0;
}

// 0x0066C3D0
void __fastcall DRLGLOGIC_SetTileGridFlags(D2UnkDrlgLogicStrc* a1, int nX, int nY, int a4)
{
    while (DRLGROOM_AreXYInsideCoordinatesOrOnBorder(&a1->pDrlgRoom->pDrlgCoord, nX + a1->pDrlgRoom->pDrlgCoord.nPosX, nY + a1->pDrlgRoom->pDrlgCoord.nPosY))
    {
        if (DRLGGRID_GetGridEntry(a1->field_4, nX, nY) & 0x10000000)
        {
            return;
        }

        if (!DRLGGRID_GetGridEntry(a1->field_14, nX, nY))
        {
            DRLGGRID_AlterGridFlag(a1->field_4, nX, nY, a1->nFlags, 0);

            for (int i = 0; i < 4; ++i)
            {
                DRLGLOGIC_SetTileGridFlags(a1, nX + gLogicDirections[i].nX, nY + gLogicDirections[i].nY, i);
            }
            return;
        }

        int nIndex = 0;
        if (DRLGGRID_IsGridValid(a1->pTileTypeGrid))
        {
            nIndex = DRLGGRID_GetGridEntry(a1->pTileTypeGrid, nX, nY);
        }

        const int nFlags = gnLogicTileFlags[a4 + 5 * gnLogicTileIndex[nIndex] + 1];
        if (nFlags & 1)
        {
            DRLGGRID_AlterGridFlag(a1->field_4, nX, nY, a1->nFlags, 0);
        }

        if (nFlags & 2 && a4 != 2)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX + 1, nY, 0);
        }

        if (nFlags & 4 && a4 != 3)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX, nY + 1, 1);
        }

        if (nFlags & 8 && a4 != 0)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX - 1, nY, 2);
        }

        if (nFlags & 16 && a4 != 1)
        {
            DRLGLOGIC_SetTileGridFlags(a1, nX, nY - 1, 3);
        }

        if (!(nFlags & 32))
        {
            return;
        }

        ++nY;
        ++nX;

        a4 = -1;
    }
}

// 0x0066C580
static void DRLGLOGIC_FloodFillUnassignedTiles(D2UnkDrlgLogicStrc* a1)
{
    const int nWidth = a1->pDrlgRoom->pDrlgCoord.nWidth;
    const int nHeight = a1->pDrlgRoom->pDrlgCoord.nHeight;

    for (int j = 0; j <= nHeight; ++j)
    {
        for (int i = 0; i <= nWidth; ++i)
        {
            if (!(DRLGGRID_GetGridEntry(a1->field_4, i, j) & 0x10000000))
            {
                ++a1->field_18;
                a1->nFlags = (a1->field_18 & 0xFFFFFFF) | 0x10000000;

                D2PackedFloorStrc tFloor;
                tFloor.nPackedValue = DRLGGRID_GetGridEntry(a1->pFloorGrid, i, j);
                if ((tFloor.nPackedValue & 0x1E0FF00) == 0x1E00000 || tFloor.bHidden)
                {
                    a1->nFlags |= 0x20000000;
                }

                DRLGLOGIC_SetTileGridFlags(a1, i, j, -1);
            }
        }
    }
}

// 0x0066C620
int __fastcall DRLGLOGIC_SetTileCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY)
{
    int nCoordList = 0;
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = pDrlgRoom->pLogicalRoomInfo;
    if (!pLogicalRoomInfo)
    {
        pTileData->pCoordList = 0;
    }
    else if (pLogicalRoomInfo->dwFlags & 1)
    {
        pTileData->pCoordList = 0;
    }
    else
    {
        nCoordList = DRLGGRID_GetGridEntry(&pLogicalRoomInfo->pIndexY, nX - pDrlgRoom->pDrlgCoord.nPosX, nY - pDrlgRoom->pDrlgCoord.nPosY);
        pTileData->pCoordList = (D2RoomCoordListStrc*)nCoordList;
    }
    return nCoordList;
}

// 0x0066C660
D2DrlgLogicalRoomInfoStrc* __fastcall DRLGLOGIC_AllocLogicalRoomInfo(void* pMemPool, int nUnused, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = (D2DrlgLogicalRoomInfoStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgLogicalRoomInfoStrc), ".\\DRLG\\DrlgLogic.cpp", 223, 0);
    memset(pLogicalRoomInfo, 0, sizeof(D2DrlgLogicalRoomInfoStrc));
    pDrlgRoom->pLogicalRoomInfo = pLogicalRoomInfo;
    return pLogicalRoomInfo;
}

// 0x0066C6A0
static void DRLGLOGIC_AllocCoordListArray(void* pMemPool, D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo, int nLists)
{
    pLogicalRoomInfo->nLists = nLists;
    pLogicalRoomInfo->pCoordList = (D2RoomCoordListStrc*)FOG_AllocPool(pMemPool, sizeof(D2RoomCoordListStrc) * nLists, ".\\DRLG\\DrlgLogic.cpp", 233, 0);
    memset(pLogicalRoomInfo->pCoordList, 0, sizeof(D2RoomCoordListStrc) * pLogicalRoomInfo->nLists);
}

// 0x0066C6E0
void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = pDrlgRoom->pLogicalRoomInfo;

    if (pLogicalRoomInfo)
    {
        if (pLogicalRoomInfo->dwFlags & 2)
        {
            DRLGGRID_FreeGrid(pMemPool, &pLogicalRoomInfo->pIndexX);
            DRLGGRID_FreeGrid(pMemPool, &pLogicalRoomInfo->pIndexY);
        }

        D2RoomCoordListStrc* pRoomCoordList = pLogicalRoomInfo->pCoordList;
        while (pRoomCoordList)
        {
            D2RoomCoordListStrc* pNext = pRoomCoordList->pNext;
            sub_0040B480(pMemPool, pRoomCoordList, ".\\DRLG\\DrlgLogic.cpp", 257, 0);
            pRoomCoordList = pNext;
        }

        sub_0040B480(pMemPool, pLogicalRoomInfo, ".\\DRLG\\DrlgLogic.cpp", 262, 0);
        pDrlgRoom->pLogicalRoomInfo = 0;
    }
}

// 0x0066C770
void __fastcall DRLGLOGIC_ReplaceCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nIndex1, int nIndex2, int bNode)
{
    if (!pDrlgRoom->pLogicalRoomInfo || (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1))
    {
        return;
    }

    int bContinue = 0;
    D2RoomCoordListStrc* pRoomCoordList = pDrlgRoom->pLogicalRoomInfo->pCoordList;
    if (pRoomCoordList)
    {
        do
        {
            if (pRoomCoordList->nIndex == nIndex1)
            {
                bContinue = 1;
                pRoomCoordList->nIndex = nIndex2;
            }
            pRoomCoordList = pRoomCoordList->pNext;
        }
        while (pRoomCoordList);

        if (bContinue)
        {
            for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
            {
                D2DrlgRoomStrc* pDrlgRoomNear = pDrlgRoom->ppRoomsNear[i];
                if (pDrlgRoomNear != pDrlgRoom && pDrlgRoomNear->ptDrlgLevel->eLevelId == pDrlgRoom->ptDrlgLevel->eLevelId)
                {
                    DRLGLOGIC_ReplaceCoordListIndex(pDrlgRoomNear, nIndex1, nIndex2, bNode);
                }
            }
        }
    }
}

// 0x0066C7F0
static void __stdcall DRLGLOGIC_MarkWallTilesInGrid(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pWallGrid)
{
    D2DrlgRoomTilesStrc* pDrlgRoomTiles = &pDrlgRoom->ptDrlgTiles->pTiles;
    for (unsigned int i = 0; i < pDrlgRoomTiles->nWalls; ++i)
    {
        if (pDrlgRoomTiles->pWallTiles[i].dwFlags & 4 && !(pDrlgRoomTiles->pWallTiles[i].dwFlags & 0x1C000))
        {
            DRLGGRID_AlterGridFlag(pWallGrid, pDrlgRoomTiles->pWallTiles[i].nPosX, pDrlgRoomTiles->pWallTiles[i].nPosY, 8, 0);
        }
    }
}

// 0x0066C840
int __fastcall DRLG_CheckLayer1ButNotWallObject(D2DrlgTileDataStrc* pTileData)
{
    if ((pTileData->dwFlags & 0x1C000) != 0x4000)
    {
        return 0;
    }

    if (pTileData->nTileType == 15)
    {
        return 0;
    }

    return !(pTileData->dwFlags & 0x800);
}

// 0x0066C870
static void __stdcall DRLGLOGIC_MarkBlockingTilesInGrid(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pDrlgGrid)
{
    D2DrlgRoomTilesStrc* pDrlgRoomTiles = &pDrlgRoom->ptDrlgTiles->pTiles;
    for (unsigned int i = 0; i < pDrlgRoomTiles->nWalls; ++i)
    {
        D2DrlgTileDataStrc* pWallTileData = &pDrlgRoomTiles->pWallTiles[i];
        if (DRLG_CheckLayer1ButNotWallObject(pWallTileData))
        {
            DRLGGRID_AlterGridFlag(pDrlgGrid, pWallTileData->nPosX, pWallTileData->nPosY, 1, 0);
        }
    }

    for (unsigned int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        D2DrlgRoomStrc* pDrlgRoomNear = pDrlgRoom->ppRoomsNear[i];
        if (pDrlgRoomNear != pDrlgRoom && pDrlgRoomNear->ptDrlgTiles)
        {
            for (D2DrlgTileLinkStrc* pDrlgTileLink = pDrlgRoomNear->ptDrlgTiles->pMapLinks; pDrlgTileLink; pDrlgTileLink = pDrlgTileLink->pNext)
            {
                if (!pDrlgTileLink->bFloor)
                {
                    for (D2DrlgTileDataStrc* pDrlgTileData = pDrlgTileLink->pMapTile; pDrlgTileData; pDrlgTileData = pDrlgTileData->pNext)
                    {
                        if (DRLG_CheckLayer1ButNotWallObject(pDrlgTileData))
                        {
                            const int nX = pDrlgRoomNear->pDrlgCoord.nPosX + pDrlgTileData->nPosX;
                            const int nY = pDrlgRoomNear->pDrlgCoord.nPosY + pDrlgTileData->nPosY;
                            if (DRLGROOM_AreXYInsideCoordinatesOrOnBorder(&pDrlgRoom->pDrlgCoord, nX, nY))
                            {
                                DRLGGRID_AlterGridFlag(pDrlgGrid, nX - pDrlgRoom->pDrlgCoord.nPosX, nY - pDrlgRoom->pDrlgCoord.nPosY, 1, 0);
                            }
                        }
                    }
                }
            }
        }
    }
}

// 0x0066C9C0
void __stdcall DRLGLOGIC_SetCoordListForTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->ptDrlgTiles->pTiles;
    for (unsigned int i = 0; i < pTiles->nWalls; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles->pWallTiles[i];
        int nY = pTile->nPosY + pDrlgRoom->pDrlgCoord.nPosY;
        int nX = pTile->nPosX + pDrlgRoom->pDrlgCoord.nPosX;
        if (!pDrlgRoom->pLogicalRoomInfo)
            pTile->pCoordList = 0;
        else if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
            pTile->pCoordList = 0;
        else
        {
            nX -= pDrlgRoom->pDrlgCoord.nPosX;
            nY -= pDrlgRoom->pDrlgCoord.nPosY;
            pTile->pCoordList = (D2RoomCoordListStrc*)DRLGGRID_GetGridEntry(&pDrlgRoom->pLogicalRoomInfo->pIndexY, nX, nY);
        }
    }
}

// 0x0066CA50
void __stdcall DRLGLOGIC_AssignCoordListsForGrids(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLogicalRoomInfoStrc* pDrlgCoordList)
{
    void* pMempool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    DRLGGRID_InitializeGridCells(pMempool, &pDrlgCoordList->pIndexY, pDrlgRoom->pDrlgCoord.nWidth + 1, pDrlgRoom->pDrlgCoord.nHeight + 1);
    const int nWidth = pDrlgRoom->pDrlgCoord.nWidth + 1;
    const int nHeight = pDrlgRoom->pDrlgCoord.nHeight + 1;

    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            const int nFlags = DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexX, nX, nY);
            const int nIndex = nFlags & 0x0FFFFFFF;

            if (!DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexY, nX, nY))
            {
                D2RoomCoordListStrc* pRoomCoordList = (D2RoomCoordListStrc*)FOG_AllocPool(pMempool, sizeof(D2RoomCoordListStrc), ".\\DRLG\\DrlgLogic.cpp", 0x201, 0);
                memset(pRoomCoordList, 0, sizeof(D2RoomCoordListStrc));

                pRoomCoordList->nIndex = nIndex;
                pRoomCoordList->bNode = (nFlags & 0x20000000) == 0x20000000;
                pRoomCoordList->pNext = pDrlgCoordList->pCoordList;

                pDrlgCoordList->pCoordList = pRoomCoordList;

                pRoomCoordList->pBox[0].left = nX;
                pRoomCoordList->pBox[0].top = nY;
                int nTmpWidth;
                for (nTmpWidth = nX; nTmpWidth < nWidth; ++nTmpWidth)
                {
                    if (nIndex != (DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexX, nTmpWidth, nY) & 0x0FFFFFFF))
                    {
                        break;
                    }

                    if (DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexY, nTmpWidth, nY))
                    {
                        break;
                    }
                }
                pRoomCoordList->pBox[0].right = nTmpWidth;

                int bBreak = 0;
                int nTmpHeight;
                for (nTmpHeight = nY; !bBreak && nTmpHeight < nHeight; ++nTmpHeight)
                {
                    for (int i = nX; i < pRoomCoordList->pBox[0].right; ++i)
                    {
                        if (nIndex != (DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexX, i, nTmpHeight) & 0x0FFFFFFF) || DRLGGRID_GetGridEntry(&pDrlgCoordList->pIndexY, i, nTmpHeight))
                        {
                            bBreak = 1;
                            --nTmpHeight;
                            break;
                        }
                    }
                }
                pRoomCoordList->pBox[0].bottom = nTmpHeight;

                for (nTmpHeight = pRoomCoordList->pBox[0].top; nTmpHeight < pRoomCoordList->pBox[0].bottom; ++nTmpHeight)
                {
                    for (int i = pRoomCoordList->pBox[0].left; i < pRoomCoordList->pBox[0].right; ++i)
                    {
                        DRLGGRID_AlterGridFlag(&pDrlgCoordList->pIndexY, i, nTmpHeight, (int)pRoomCoordList, FLAG_OPERATION_OVERWRITE);
                    }
                }

                pRoomCoordList->pBox[0].top += pDrlgRoom->pDrlgCoord.nPosY;
                pRoomCoordList->pBox[0].bottom += pDrlgRoom->pDrlgCoord.nPosY;
                pRoomCoordList->pBox[0].left += pDrlgRoom->pDrlgCoord.nPosX;
                pRoomCoordList->pBox[0].right += pDrlgRoom->pDrlgCoord.nPosX;

                pRoomCoordList->pBox[1] = pRoomCoordList->pBox[0];

                if (pRoomCoordList->pBox[1].right >= pDrlgRoom->pDrlgCoord.nWidth + pDrlgRoom->pDrlgCoord.nPosX)
                {
                    pRoomCoordList->pBox[1].right = pDrlgRoom->pDrlgCoord.nWidth + pDrlgRoom->pDrlgCoord.nPosX;
                }

                if (pRoomCoordList->pBox[1].bottom >= pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight)
                {
                    pRoomCoordList->pBox[1].bottom = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
                }

                if (pRoomCoordList->pBox[1].left >= pDrlgRoom->pDrlgCoord.nWidth + pDrlgRoom->pDrlgCoord.nPosX || pRoomCoordList->pBox[1].top >= pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight)
                {
                    pRoomCoordList->pBox[1].left = 0;
                    pRoomCoordList->pBox[1].top = 0;
                    pRoomCoordList->pBox[1].right = 0;
                    pRoomCoordList->pBox[1].bottom = 0;
                }
            }
        }
    }
}

// 0x0066CCB0
void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgLevelStrc* pLevel = pDrlgRoom->ptDrlgLevel;
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo = DRLGLOGIC_AllocLogicalRoomInfo(pMemPool, 0, pDrlgRoom);

    pLogicalRoomInfo->dwFlags |= 1;
    pLevel->nCoordLists = 1;
    DRLGLOGIC_AllocCoordListArray(pMemPool, pLogicalRoomInfo, 1);

    pLogicalRoomInfo->pCoordList->nIndex = pLevel->nCoordLists;
    pLogicalRoomInfo->pCoordList->pBox[0].top = pDrlgRoom->pDrlgCoord.nPosY;
    pLogicalRoomInfo->pCoordList->pBox[0].bottom = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
    pLogicalRoomInfo->pCoordList->pBox[0].left = pDrlgRoom->pDrlgCoord.nPosX;
    pLogicalRoomInfo->pCoordList->pBox[0].right = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
    pLogicalRoomInfo->pCoordList->pBox[1].top = pDrlgRoom->pDrlgCoord.nPosY;
    pLogicalRoomInfo->pCoordList->pBox[1].bottom = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
    pLogicalRoomInfo->pCoordList->pBox[1].left = pDrlgRoom->pDrlgCoord.nPosX;
    pLogicalRoomInfo->pCoordList->pBox[1].right = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
}

// 0x0066CDA0
static D2RoomCoordListStrc* DRLGLOGIC_GetRoomCoordListAtTile(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    if (!pDrlgRoom->pLogicalRoomInfo)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 668);
        exit(-1);
    }

    if (pDrlgRoom->pLogicalRoomInfo->dwFlags & 1)
    {
        return pDrlgRoom->pLogicalRoomInfo->pCoordList;
    }

    nX -= pDrlgRoom->pDrlgCoord.nPosX;
    nY -= pDrlgRoom->pDrlgCoord.nPosY;
    return (D2RoomCoordListStrc*)DRLGGRID_GetGridEntry(&pDrlgRoom->pLogicalRoomInfo->pIndexY, nX, nY);
}

// 0x0066CDE0
static int DRLGLOGIC_GetCoordListIndexAtTile(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    D2RoomCoordListStrc* pRoomCoordList = DRLGLOGIC_GetRoomCoordListAtTile(pDrlgRoom, nX, nY);
    if (pRoomCoordList)
    {
        return pRoomCoordList->nIndex;
    }

    return -1;
}

// 0x0066CE30
int __fastcall DRLGLOGIC_GetRoomCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    return DRLGLOGIC_GetCoordListIndexAtTile(pDrlgRoom, nX / 5, nY / 5);
}

// 0x0066CEB0
D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordListAtSubtile(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY)
{
    return DRLGLOGIC_GetRoomCoordListAtTile(pDrlgRoom, nX / 5, nY / 5);
}

// 0x0066CF30
D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordList(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom->pLogicalRoomInfo)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 717);
        exit(-1);
    }

    return pDrlgRoom->pLogicalRoomInfo->pCoordList;
}

// 0x0066CF60
static void __stdcall DRLGLOGIC_MergeCoordListsAtPoint(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nX, int nY)
{
    if (DRLGROOM_AreXYInsideCoordinatesOrOnBorder(&pDrlgRoom2->pDrlgCoord, nX, nY))
    {
        D2RoomCoordListStrc* pRoomCoordList2 = DRLGLOGIC_GetRoomCoordListAtTile(pDrlgRoom2, nX, nY);
        D2RoomCoordListStrc* pRoomCoordList1 = DRLGLOGIC_GetRoomCoordListAtTile(pDrlgRoom1, nX, nY);

        if (pRoomCoordList2->nIndex && pRoomCoordList1->nIndex)
        {
            if (pDrlgRoom2->ptDrlgLevel->eLevelId == pDrlgRoom1->ptDrlgLevel->eLevelId && pRoomCoordList2->nIndex != pRoomCoordList1->nIndex && pRoomCoordList2->bNode == pRoomCoordList1->bNode)
            {
                DRLGLOGIC_ReplaceCoordListIndex(pDrlgRoom1, pRoomCoordList1->nIndex, pRoomCoordList2->nIndex, pRoomCoordList2->bNode);
            }
        }
    }
}

// 0x0066D040
static void DRLGLOGIC_MergeCoordListsWithNearRooms(D2DrlgRoomStrc* pDrlgRoom)
{
    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        D2DrlgRoomStrc* pCurrentRoomEx = pDrlgRoom->ppRoomsNear[i];
        if (pCurrentRoomEx != pDrlgRoom && pCurrentRoomEx->pLogicalRoomInfo)
        {
            if (!DRLG_CheckNotOverlappingUsingManhattanDistance(&pDrlgRoom->pDrlgCoord, &pCurrentRoomEx->pDrlgCoord, 1))
            {
                for (int j = pDrlgRoom->pDrlgCoord.nPosX; j <= pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth; ++j)
                {
                    DRLGLOGIC_MergeCoordListsAtPoint(pDrlgRoom, pCurrentRoomEx, j, pDrlgRoom->pDrlgCoord.nPosY);
                    DRLGLOGIC_MergeCoordListsAtPoint(pDrlgRoom, pCurrentRoomEx, j, pDrlgRoom->pDrlgCoord.nHeight + pDrlgRoom->pDrlgCoord.nPosY);
                }

                for (int j = pDrlgRoom->pDrlgCoord.nPosY; j <= pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight; ++j)
                {
                    DRLGLOGIC_MergeCoordListsAtPoint(pDrlgRoom, pCurrentRoomEx, pDrlgRoom->pDrlgCoord.nPosX, j);
                    DRLGLOGIC_MergeCoordListsAtPoint(pDrlgRoom, pCurrentRoomEx, pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth, j);
                }
            }
        }
    }
}

// 0x0066D110
void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid)
{
    int nCellPositions[1024];
    int nCellFlags[256];

    D2DrlgLevelStrc* pLevel = pDrlgRoom->ptDrlgLevel;
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgLogicalRoomInfoStrc* pDrlgCoordList = DRLGLOGIC_AllocLogicalRoomInfo(pMemPool, 0, pDrlgRoom);

    DRLGLOGIC_MarkWallTilesInGrid(pDrlgRoom, pWallGrid);

    pDrlgCoordList->dwFlags |= 2;

    DRLGGRID_InitializeGridCells(pMemPool, &pDrlgCoordList->pIndexX, pDrlgRoom->pDrlgCoord.nWidth + 1, pDrlgRoom->pDrlgCoord.nHeight + 1);

    if (!pLevel->nCoordLists)
    {
        pLevel->nCoordLists = 1;
    }

    const int nLists = pLevel->nCoordLists;

    D2DrlgGridStrc pDrlgGrid;
    DRLGGRID_FillGrid(&pDrlgGrid, pDrlgRoom->pDrlgCoord.nWidth + 1, pDrlgRoom->pDrlgCoord.nHeight + 1, nCellPositions, nCellFlags);

    DRLGLOGIC_MarkBlockingTilesInGrid(pDrlgRoom, &pDrlgGrid);

    D2UnkDrlgLogicStrc tDRLGLogicUnkStrc = {};
    tDRLGLogicUnkStrc.field_4 = &pDrlgCoordList->pIndexX;
    tDRLGLogicUnkStrc.pTileTypeGrid = pTileTypeGrid;
    tDRLGLogicUnkStrc.pDrlgRoom = pDrlgRoom;
    tDRLGLogicUnkStrc.pWallGrid = pWallGrid;
    tDRLGLogicUnkStrc.pFloorGrid = pFloorGrid;
    tDRLGLogicUnkStrc.field_14 = &pDrlgGrid;
    tDRLGLogicUnkStrc.field_18 = nLists;

    DRLGLOGIC_FloodFillUnassignedTiles(&tDRLGLogicUnkStrc);

    DRLGGRID_ResetGrid(&pDrlgGrid);

    DRLGLOGIC_AllocCoordListArray(pMemPool, pDrlgCoordList, tDRLGLogicUnkStrc.field_18 - nLists + 1);
    pLevel->nCoordLists += pDrlgCoordList->nLists;

    DRLGLOGIC_AssignCoordListsForGrids(pDrlgRoom, pDrlgCoordList);
    DRLGLOGIC_SetCoordListForTiles(pDrlgRoom);
    DRLGLOGIC_MergeCoordListsWithNearRooms(pDrlgRoom);
}

#include "gen/data/Source/D2Common/DRLG/DrlgLogic.inc"
