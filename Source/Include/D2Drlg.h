#pragma once
// Level generation (DRLG): the generator, its levels and rooms, their grids and coordinates, and the active (loaded) room.

#include "D2Check.h"
#include "D2Path.h"

struct D2ClientStrc;
struct D2DrlgActStrc;
struct D2DrlgBuildStrc;
struct D2DrlgDeleteStrc;
struct D2DrlgLogicalRoomInfoStrc;
struct D2DrlgMapStrc;
struct D2DrlgOrthStrc;
struct D2DrlgRoomTilesStrc;
struct D2DrlgTileGridStrc;
struct D2DrlgVertexStrc;
struct D2DrlgWarpStrc;
struct D2GameStrc;
struct D2PresetUnitStrc;
struct D2RoomStrc;
struct D2RoomTileStrc;
struct D2TileLibraryHeaderStrc;
struct D2UnitStrc;
struct D2DrlgOutdoorRoomStrc;
struct D2DrlgPresetRoomStrc;
struct D2LvlMazeTxt;
struct D2DrlgPresetInfoStrc;
struct D2DrlgCoordStrc;
struct D2DrlgCoordsStrc;
struct D2DrlgGridStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2DrlgRoomStrc;
struct D2DrlgLevelStrc;
struct D2DrlgStrc;
struct D2ActiveRoomStrc;

struct D2DrlgTileInfoStrc
{
    int nPosX; // 0x00
    int nPosY; // 0x04
    int nTileIndex; // 0x08
};

struct D2DrlgCoordStrc
{
    int nPosX; // 0x00
    int nPosY; // 0x04
    int nWidth; // 0x08
    int nHeight; // 0x0C
};

struct D2DrlgCoordsStrc
{
    int nSubtileX; // 0x00
    int nSubtileY; // 0x04
    int nSubtileWidth; // 0x08
    int nSubtileHeight; // 0x0C
    int nTileXPos; // 0x10
    int nTileYPos; // 0x14
    int nTileWidth; // 0x18
    int nTileHeight; // 0x1C
};

struct D2DrlgGridStrc
{
    int* pCellsFlags; // 0x00
    int* pCellsRowOffsets; // 0x04
    int nWidth; // 0x08
    int nHeight; // 0x0C
    int nFlags; // 0x10
};

struct D2DrlgVertexStrc
{
    int nPosX; // 0x00
    int nPosY; // 0x04
    unsigned char nDirection; // 0x08
    unsigned char unk0x09; // 0x09
    unsigned short unk0x0A; // 0x0A
    unsigned int dwFlags; // 0x0C
    D2DrlgVertexStrc* pNext; // 0x10
};

struct D2DrlgOutdoorInfoStrc
{
    unsigned int dwFlags; // 0x00
    D2DrlgGridStrc pGrid[4]; // 0x04
    union // 0x54
    {
        struct
        {
            int nWidth; // 0x54
            int nRoomData; // 0x58
            int nGridWidth; // 0x5C
            int nGridHeight; // 0x60
        };
        D2DrlgCoordStrc tCoords;
    };
    D2DrlgVertexStrc* pVertex; // 0x64
    D2DrlgVertexStrc* pRoads[6]; // 0x68
    D2DrlgVertexStrc pVertices[24]; // 0x80
    int nVertices; // 0x260
    D2DrlgOrthStrc* pRoomData; // 0x264
};

struct D2DrlgRoomStrc
{
    D2DrlgOrthStrc* pDrlgOrth; // 0x00
    unsigned int dwInitSeed; // 0x04
    D2DrlgRoomStrc** ppRoomsNear; // 0x08
    unsigned short wRoomsInList[4]; // 0x0C
    D2SeedStrc pSeed; // 0x14
    D2DrlgRoomStrc* pStatusNext; // 0x1C
    union // 0x20
    {
        D2DrlgPresetRoomStrc* pMaze;
        D2DrlgOutdoorRoomStrc* pOutdoor;
    };
    D2DrlgRoomStrc* pDrlgRoomNext; // 0x24
    unsigned int dwFlags; // 0x28
    int nRoomsNear; // 0x2C
    D2ActiveRoomStrc* pRoom; // 0x30
    D2DrlgCoordStrc pDrlgCoord; // 0x34
    unsigned char fRoomStatus; // 0x44
    unsigned char unk0x45; // 0x45
    unsigned short unk0x46; // 0x46
    int nType; // 0x48
    D2RoomTileStrc* pRoomTiles; // 0x4C
    unsigned int dwDT1Mask; // 0x50
    D2DrlgTileGridStrc* ptDrlgTiles; // 0x54
    D2DrlgLevelStrc* ptDrlgLevel; // 0x58
    D2PresetUnitStrc* pPresetUnits; // 0x5C
    unsigned int dwOtherFlags; // 0x60
    D2DrlgLogicalRoomInfoStrc* pLogicalRoomInfo; // 0x64
    D2TileLibraryHeaderStrc* pTiles; // 0x68
    int unk0x6C[31]; // 0x6C
    D2DrlgRoomStrc* pStatusPrev; // 0xE8
};

struct D2DrlgLevelStrc
{
    int nDrlgType; // 0x00
    unsigned int dwFlags; // 0x04
    int nRooms; // 0x08
    int bActive; // 0x0C
    D2DrlgRoomStrc* ptRoomFirst; // 0x10
    union // 0x14
    {
        D2DrlgPresetInfoStrc* pPreset;
        D2DrlgOutdoorInfoStrc* pOutdoors;
        D2LvlMazeTxt* pMaze;
    };
    int unk0x18; // 0x18
    union // 0x1C
    {
        struct
        {
            int nPosX; // 0x1C
            int nPosY; // 0x20
            int nWidth; // 0x24
            int nHeight; // 0x28
        };
        D2DrlgCoordStrc pLevelCoords;
    };
    D2DrlgTileInfoStrc pTileInfo[32]; // 0x2C
    D2DrlgLevelStrc* pNextLevel; // 0x1AC
    D2DrlgMapStrc* pCurrentMap; // 0x1B0
    D2DrlgStrc* pDrlg; // 0x1B4
    int nJungleDefs; // 0x1B8
    int* pnJungleDefs; // 0x1BC
    int nLevelType; // 0x1C0
    D2SeedStrc pSeed; // 0x1C4
    D2DrlgBuildStrc* pBuild; // 0x1CC
    int eLevelId; // 0x1D0
    int dwInactiveFrames; // 0x1D4
    int nTileInfo; // 0x1D8
    int nCoordLists; // 0x1DC
    int nRoom_Center_Warp_X[9]; // 0x1E0
    int nRoom_Center_Warp_Y[9]; // 0x204
    int nRoomCoords; // 0x228
    int* pPresetMaps; // 0x22C
};

struct D2DrlgStrc
{
    D2SeedStrc pSeed; // 0x00
    int nAllocatedRooms; // 0x08
    D2TileLibraryHeaderStrc* pTiles[32]; // 0x0C
    unsigned int dwFlags; // 0x8C
    D2DrlgWarpStrc* pWarp; // 0x90
    int nStaffTombLevel; // 0x94
    unsigned char nRoomsInitSinceLastUpdate; // 0x98
    unsigned char unk0x99; // 0x99
    unsigned short unk0x9A; // 0x9A
    D2GameStrc* pGame; // 0x9C
    D2DrlgRoomStrc tStatusRoomsLists[4]; // 0xA0
    unsigned char nDifficulty; // 0x450
    unsigned char unk0x451; // 0x451
    unsigned short unk0x452; // 0x452
    void (__stdcall* pfAutomap)(D2RoomStrc*); // 0x454
    unsigned int dwGameLowSeed; // 0x458
    unsigned char nRoomsInitTimeout; // 0x45C
    unsigned char unk0x45D; // 0x45D
    unsigned short unk0x45E; // 0x45E
    D2DrlgRoomStrc* pDrlgRoom; // 0x460
    void* hArchive; // 0x464
    int nFreedRooms; // 0x468
    D2DrlgActStrc* pAct; // 0x46C
    unsigned int dwStartSeed; // 0x470
    int bJungleInterlink; // 0x474
    void* pMempool; // 0x478
    D2DrlgLevelStrc* pLevel; // 0x47C
    unsigned char nAct; // 0x480
    unsigned char unk0x481; // 0x481
    unsigned short unk0x482; // 0x482
    int nBossTombLevel; // 0x484
    void (__stdcall* pfTownAutomap)(int, int, int, int); // 0x488
};

struct D2ActiveRoomStrc
{
    D2ActiveRoomStrc** ppRoomList; // 0x00
    unsigned int nMaxClients; // 0x04
    D2DrlgRoomTilesStrc* pRoomTiles; // 0x08
    int nTileCount; // 0x0C
    D2DrlgRoomStrc* pDrlgRoom; // 0x10
    int nCurrentDeathIndex; // 0x14
    D2DrlgDeleteStrc* pDrlgDelete; // 0x18
    D2UnitStrc* pUnitUpdate; // 0x1C
    void* pCollisionGrid; // 0x20
    int nNumRooms; // 0x24
    int nAllies; // 0x28
    D2DrlgActStrc* pAct; // 0x2C
    int unk0x30; // 0x30
    unsigned int dwFlags; // 0x34
    int nLastDeadGUIDs[4]; // 0x38
    D2ClientStrc** ppClients; // 0x48
    D2DrlgCoordsStrc tCoords; // 0x4C
    D2SeedStrc pSeed; // 0x6C
    D2UnitStrc* pUnitFirst; // 0x74
    unsigned int nNumClients; // 0x78
    D2ActiveRoomStrc* pRoomNext; // 0x7C
};

D2_CHECK_SIZE(D2DrlgTileInfoStrc, 0xC);
D2_CHECK_SIZE(D2DrlgCoordStrc, 0x10);
D2_CHECK_SIZE(D2DrlgCoordsStrc, 0x20);
D2_CHECK_SIZE(D2DrlgVertexStrc, 0x14);
D2_CHECK_SIZE(D2DrlgGridStrc, 0x14);
D2_CHECK_SIZE(D2DrlgOutdoorInfoStrc, 0x268);
D2_CHECK_SIZE(D2DrlgRoomStrc, 0xEC);
D2_CHECK_SIZE(D2DrlgLevelStrc, 0x230);
D2_CHECK_SIZE(D2DrlgStrc, 0x48C);
D2_CHECK_SIZE(D2ActiveRoomStrc, 0x80);
