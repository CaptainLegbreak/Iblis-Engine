#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgRooms.h"
#include "D2DrlgTiles.h"
#include "D2DrlgPresets.h"

struct D2DrlgOutdoorTileCtxStrc
{
    struct D2DrlgRoomStrc* pRoom;
    D2DrlgGridStrc* pGrid00;
    int unk0x08;
    int unk0x0C;
    int unk0x10;
    D2DrlgGridStrc* pGrid14;
    int unk0x18;
    int unk0x1C;
    int unk0x20;
    D2DrlgGridStrc* pGrid28;
    int n28;
    int n2C;
    int n30;
    int n34;
    int n38;
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);    // 0x0040B430

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);  // 0x0040B480

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid); // 0x0067CD90

void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex); // 0x0067D1E0

void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pRoom);                                                // 0x0066EEA0

void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5); // 0x0066EDB0

void __fastcall DRLGROOMTILE_CountAllTileTypes(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, int a3, int a4, int a5); // 0x0066ECE0

void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pRoom); // 0x0066EEE0

void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5, int a6); // 0x0066EC10

void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pRoom); // 0x0066CCB0

void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight);         // 0x0067CB80

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);            // 0x0067C4F0

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                          // 0x0067C570

void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation);                       // 0x0067C600

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                                            // 0x006427F0

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                          // 0x0061E470

void __fastcall sub_00680C80(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);                                // 0x00680C80

void __fastcall sub_006707A0(D2DrlgOutdoorTileCtxStrc* pCtx);                                                // 0x006707A0

D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType); // 0x0066B3E0

void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom); // 0x0066B970

int __fastcall DRLGTILESUB_PickSubThemes(D2DrlgRoomStrc* pRoom, int a2, int a3); // 0x006706A0

// build: symbol ?DRLGOUTROOM_InitOutdoorRoomGrids@@YIXPAUD2DrlgRoomStrc@@@Z 0x0067D2D0
void __fastcall DRLGOUTROOM_InitOutdoorRoomGrids(D2DrlgRoomStrc* pRoom)
{
    D2DrlgLevelStrc* pLevel = pRoom->ptDrlgLevel;
    void* pMemPool = pLevel->pDrlg->pMempool;
    int nLevelId = pLevel->eLevelId;
    unsigned char bSkip = DRLG_GetActNoFromLevelId(nLevelId);
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    D2LevelDefBin* pLevelDef = DATATBLS_GetLevelDefRecord(nLevelId);
    int nWidth = pRoom->pDrlgCoord.nWidth + 1;
    int nHeight = pRoom->pDrlgCoord.nHeight + 1;
    int nSubType1 = (pRoom->dwFlags >> 16) & 3;
    int nSubType2 = (pRoom->dwFlags >> 12) & 0xF;
    int nMask = 0;

    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoor->pTileTypeGrid, nWidth, nHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoor->tGrid14, nWidth, nHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoor->tGrid28, nWidth, nHeight);

    for (int nY = 0; nY < 8; ++nY)
    {
        for (int nX = 0; nX < 8; ++nX)
        {
            DRLGGRID_AlterGridFlag(&pOutdoor->tGrid28, nX, nY, 0x40002, 3);
        }
    }

    if (!bSkip)
    {
        sub_00680C80(pLevel, pRoom);
    }

    DRLGROOMTILE_AllocTileGrid(pRoom);

    D2DrlgOutdoorTileCtxStrc tCtx;
    memset(&tCtx, 0, sizeof(tCtx));
    tCtx.pRoom = pRoom;
    tCtx.pGrid00 = &pOutdoor->pTileTypeGrid;
    tCtx.pGrid14 = &pOutdoor->tGrid14;
    tCtx.pGrid28 = &pOutdoor->tGrid28;
    tCtx.n28 = 0;
    tCtx.n2C = 1;

    if (nSubType1)
    {
        tCtx.n30 = pLevelDef->dwSubWaypoint;
        tCtx.n34 = 0;
        tCtx.n38 = nSubType1;
        sub_006707A0(&tCtx);
    }

    if (nSubType2)
    {
        tCtx.n30 = pLevelDef->dwSubShrine;
        tCtx.n34 = 0;
        tCtx.n38 = nSubType2;
        sub_006707A0(&tCtx);
    }

    tCtx.n30 = pOutdoor->nTileInfo64;
    tCtx.n34 = pOutdoor->nTileInfo68;
    tCtx.n38 = pOutdoor->nTileInfo6C;
    sub_006707A0(&tCtx);

    switch (pLevel->nLevelType)
    {
    case 0x10:
        nMask = 0x100;
        break;
    case 0x15:
        nMask = 0x120000;
        break;
    case 0x16:
        nMask = 0x100000;
        break;
    case 0x1B:
        nMask = 0xA00000;
        break;
    case 0x1C:
        nMask = 0x1600000;
        break;
    case 0x1F:
        nMask = (pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS) ? 0x600000 : 0;
        break;
    }

    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            if (!(DRLGGRID_GetGridEntry(&pOutdoor->tGrid28, nX, nY) & 0x3F0FF80))
            {
                DRLGGRID_AlterGridFlag(&pOutdoor->tGrid28, nX, nY, nMask, 0);
            }
        }
    }

    DRLGGRID_AlterEdgeGridFlags(&pOutdoor->tGrid14, 4, 0);
    DRLGGRID_AlterEdgeGridFlags(&pOutdoor->tGrid28, 4, 0);
}

D2DrlgRoomStrc* __fastcall DRLGOUTPLACE_CreateOutdoorRoomEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50);

void DRLGOUTROOM_FreeOutdoorRoomGrids(void* pMemPool, D2DrlgOutdoorRoomStrc* pOutdoor);

void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom);

void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoomData(D2DrlgRoomStrc* pRoom);

void __fastcall DRLGOUTROOM_AllocDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom);

void __fastcall DRLGOUTROOM_InitializeDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom); // 0x0067D710

unsigned int __fastcall DRLGOUTROOM_CheckOutdoorRoomFlag(D2DrlgRoomStrc* pRoom);

void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pRoom); // 0x0066EEA0

D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);                                    // 0x0066B3E0

void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom);                                  // 0x0066B970

void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pRoom); // 0x0066CCB0

void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pRoom); // 0x0066EEE0

void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5); // 0x0066EDB0

void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pGrid2, int a4, int a5, int a6); // 0x0066EC10

struct D2DrlgCoordStrc;

union D2SeedStrc;

struct D2CoordStrc;

struct D2DrlgLinkStrc;

struct D2DrlgLevelLinkDataStrc;

extern const D2CoordStrc gOutdoorOrthOffsets[4]; // 0x006F1F7C

void __fastcall DRLGOUTROOM_InitOutdoorRoomGrids(D2DrlgRoomStrc* pRoom);

// 0x0067D540
D2DrlgRoomStrc* __fastcall DRLGOUTPLACE_CreateOutdoorRoomEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nWidth, int nHeight, unsigned int dwRoomFlags, unsigned int dwOutdoorFlags, int nOutdoor58, int nRoom50)
{
    D2DrlgRoomStrc* pRoom = DRLGROOM_AllocRoomEx(pLevel, 1);
    pRoom->pDrlgCoord.nPosX = nX;
    pRoom->pDrlgCoord.nPosY = nY;
    pRoom->pDrlgCoord.nWidth = nWidth;
    pRoom->pDrlgCoord.nHeight = nHeight;
    DRLGROOM_AddRoomExToLevel(pLevel, pRoom);

    pRoom->dwFlags |= dwRoomFlags | 0x80000;
    pRoom->dwDT1Mask = nRoom50;

    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    pOutdoor->dwFlags = dwOutdoorFlags;
    pOutdoor->dwFlagsEx = nOutdoor58;

    D2LevelDefBin* pLevelDef = DATATBLS_GetLevelDefRecord(pLevel->eLevelId);
    pOutdoor->nTileInfo64 = pLevelDef->dwSubType;
    pOutdoor->nTileInfo68 = pLevelDef->dwSubTheme;
    pOutdoor->nTileInfo6C = DRLGTILESUB_PickSubThemes(pRoom, pLevelDef->dwSubType, pLevelDef->dwSubTheme);
    return pRoom;
}

// 0x0067D5D0
static void DRLGOUTROOM_FreeOutdoorRoomGrids(void* pMemPool, D2DrlgOutdoorRoomStrc* pOutdoor)
{
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->pTileTypeGrid);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->tGrid14);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->tGrid28);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoor->tGrid3C);
    DRLGVER_FreeVertices(pMemPool, &pOutdoor->pVertex);
}

// 0x0067D610
void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom)
{
    void* pMemPool = pRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    if (pOutdoor)
    {
        DRLGOUTROOM_FreeOutdoorRoomGrids(pMemPool, pOutdoor);
        sub_0040B480(pMemPool, pOutdoor, ".\\DRLG\\OutRoom.cpp", 173, 0);
        pRoom->pOutdoor = 0;
    }
}

// 0x0067D680
void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoomData(D2DrlgRoomStrc* pRoom)
{
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    if (pOutdoor)
    {
        DRLGOUTROOM_FreeOutdoorRoomGrids(pRoom->ptDrlgLevel->pDrlg->pMempool, pOutdoor);
    }
}

// 0x0067D6D0
void __fastcall DRLGOUTROOM_AllocDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom)
{
    D2DrlgOutdoorRoomStrc* pOutdoor = (D2DrlgOutdoorRoomStrc*)sub_0040B430(pRoom->ptDrlgLevel->pDrlg->pMempool, sizeof(D2DrlgOutdoorRoomStrc), ".\\DRLG\\OutRoom.cpp", 197, 0);
    memset(pOutdoor, 0, sizeof(D2DrlgOutdoorRoomStrc));
    pRoom->pOutdoor = pOutdoor;
}

// 0x0067D710
void __fastcall DRLGOUTROOM_InitializeDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom)
{
    DRLGROOMTILE_AllocTileGrid(pRoom);

    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    DRLGROOMTILE_CountWallWarpTiles(pRoom, &pOutdoor->tGrid14, &pOutdoor->pTileTypeGrid, 0, 0);
    DRLGROOMTILE_CountAllTileTypes(pRoom, &pOutdoor->tGrid14, 0, 0, 0);
    DRLGROOMTILE_CountAllTileTypes(pRoom, &pOutdoor->tGrid28, 0, 0, 0);
    DRLGROOMTILE_AllocTileData(pRoom);
    DRLGROOMTILE_LoadInitRoomTiles(pRoom, &pOutdoor->tGrid14, &pOutdoor->pTileTypeGrid, 0, 0, 0);
    DRLGROOMTILE_LoadInitRoomTiles(pRoom, &pOutdoor->tGrid28, 0, 0, 0, 0);

    D2DrlgTileGridStrc* pTileGrid = pRoom->ptDrlgTiles;
    D2DrlgRoomTilesStrc* pTiles = &pTileGrid->pTiles;
    pTiles->nWalls = pTileGrid->nWalls;
    pTiles->nFloors = pTileGrid->nFloors;
    pTiles->nRoofs = pTileGrid->nShadows;

    DRLGLOGIC_AllocCoordLists(pRoom);
}

// 0x0067D7A0
unsigned int __fastcall DRLGOUTROOM_CheckOutdoorRoomFlag(D2DrlgRoomStrc* pRoom)
{
    return pRoom->pOutdoor->dwFlags & 0x80;
}

// 0x0067D7B0
static inline void sub_0067D7B0(D2DrlgCoordStrc* pCoords, int nType)
{
    switch (nType)
    {
    case 0:
        pCoords->nWidth = 0x40;
        pCoords->nHeight = 0xA0;
        break;

    case 1:
        pCoords->nWidth = 0xA0;
        pCoords->nHeight = 0x40;
        break;
    }
}

void __stdcall sub_M129_Emit_0067D7B0(D2DrlgCoordStrc* pCoords, int nType)
{
    sub_0067D7B0(pCoords, nType);
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x0067D7E0
static inline void __fastcall DRLGOUTROOM_SetOffsetCoords(D2DrlgCoordStrc* pCoords, D2DrlgCoordStrc* pLinkCoords, int nRand, int nLinkRand)
{
    switch (nRand)
    {
    case 0:
        pCoords->nWidth = 64;
        pCoords->nHeight = 160;
        break;
    case 1:
        pCoords->nWidth = 160;
        pCoords->nHeight = 64;
        break;
    }

    const int nIndex = nRand + 2 * nLinkRand;
    pCoords->nPosX = gOutdoorOrthOffsets[nIndex].nX + pLinkCoords->nPosX;
    pCoords->nPosY = gOutdoorOrthOffsets[nIndex].nY + pLinkCoords->nPosY;
}

// emits the static 0x0067D7E0 the way its lost caller did (not game code)
int __fastcall sub_M_Emit_0067D7E0(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int bRand0IsNull = pLevelLinkData->nRand[0][pLevelLinkData->nIteration] == 0;
        if (bRand0IsNull == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = bRand0IsNull;
    }

    const int nLevelLink = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    DRLGOUTROOM_SetOffsetCoords(&pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], &pLevelLinkData->pLevelCoord[nLevelLink], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], pLevelLinkData->nRand[0][nLevelLink]);
    return 1;
}

// 0x0067D830
int __fastcall DRLGOUTROOM_LinkLevelsByLevelCoords(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    D2DrlgLinkStrc* const& pLinks = pLevelLinkData->pLink;
    int nRand = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;

    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = nRand;

    D2DrlgCoordStrc* pCoord = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    sub_0067D7B0(pCoord, nRand);

    const int nIteration = pLevelLinkData->nIteration;
    D2DrlgCoordStrc* pLinkCoord = &pLevelLinkData->pLevelCoord[pLinks[nIteration].nLevelLink];
    pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
    pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY - 16;

    return 1;
}

static __forceinline void __fastcall DRLGOUTROOM_GetOrthCoords(D2DrlgCoordStrc* pCoords, int nRand, D2DrlgCoordStrc* pLinkCoords, int nLinkRand)
{
    sub_0067D7B0(pCoords, nRand);

    const int nIndex = nRand + 2 * nLinkRand;
    pCoords->nPosX = gOutdoorOrthOffsets[nIndex].nX + pLinkCoords->nPosX;
    pCoords->nPosY = gOutdoorOrthOffsets[nIndex].nY + pLinkCoords->nPosY;
}

// 0x0067D8E0
int __fastcall DRLGOUTROOM_LinkLevelsByLevelDef(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;

    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = nRand;

    D2DrlgCoordStrc* pCoord = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    switch (nRand)
    {
    case 0:
        pCoord->nWidth = 64;
        pCoord->nHeight = 160;
        break;

    case 1:
        pCoord->nWidth = 160;
        pCoord->nHeight = 64;
        break;
    }

    D2LevelDefBin* pLevelDefBin = DATATBLS_GetLevelDefRecord(pLevelLinkData->nCurrentLevel);

    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosX = pLevelDefBin->dwOffsetX;
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosY = pLevelDefBin->dwOffsetY;

    return 1;
}

// 0x0067D980
int __fastcall DRLGOUTROOM_LinkLevelsByOffsetCoords(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int bRand0IsNull = pLevelLinkData->nRand[0][pLevelLinkData->nIteration] == 0;
        if (bRand0IsNull == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = bRand0IsNull;
    }

    const int nLevelLink = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    DRLGOUTROOM_GetOrthCoords(&pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration],
        &pLevelLinkData->pLevelCoord[nLevelLink], pLevelLinkData->nRand[0][nLevelLink]);

    return 1;
}

#include "gen/data/Source/D2Common/DRLG/OutRoom.inc"
