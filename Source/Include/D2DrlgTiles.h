#pragma once
// Level generation, tiles: a room's tile grid and its tiles, and the level definitions read from levels.bin.

#include "D2Check.h"
#include "D2Structs.h"

struct D2DrlgTileDataStrc;
struct D2DrlgTileLinkStrc;
struct D2LvlWarpTxt;
struct D2RoomTileStrc;
struct D2DrlgRoomTilesStrc;
struct D2DrlgTileGridStrc;
struct D2LevelDefBin;

struct D2RoomTileStrc
{
    void* pUnused; // 0x00
    D2RoomTileStrc* pNext; // 0x04
    int bEnabled; // 0x08
    D2DrlgTileDataStrc* pUnselectedTiles; // 0x0C
    D2LvlWarpTxt* pLvlWarpTxtRecord; // 0x10
    D2DrlgTileDataStrc* pSelectedTiles; // 0x14
};

struct D2DrlgRoomTilesStrc
{
    D2DrlgTileDataStrc* pWallTiles; // 0x00
    int nWalls; // 0x04
    D2DrlgTileDataStrc* pFloorTiles; // 0x08
    int nFloors; // 0x0C
    D2DrlgTileDataStrc* pRoofTiles; // 0x10
    int nRoofs; // 0x14
};

struct D2DrlgTileGridStrc
{
    D2DrlgTileLinkStrc* pMapLinks; // 0x00
    void* pAnimTiles; // 0x04
    int nWalls; // 0x08
    int nFloors; // 0x0C
    int nShadows; // 0x10
    union // 0x14
    {
        struct
        {
            D2DrlgTileDataStrc* pWallTiles; // 0x14
            int nTileWalls; // 0x18
            D2DrlgTileDataStrc* pFloorTiles; // 0x1C
            int nTileFloors; // 0x20
            D2DrlgTileDataStrc* pRoofTiles; // 0x24
            int nTileRoofs; // 0x28
        };
        D2DrlgRoomTilesStrc pTiles;
    };
};

struct D2LevelDefBin
{
    unsigned int dwQuestFlag; // 0x00
    unsigned int dwQuestFlagEx; // 0x04
    int dwLayer; // 0x08
    int dwSizeX[3]; // 0x0C
    int dwSizeY[3]; // 0x18
    int dwOffsetX; // 0x24
    int dwOffsetY; // 0x28
    int dwDepend; // 0x2C
    int dwDrlgType; // 0x30
    int dwLevelType; // 0x34
    int dwSubType; // 0x38
    int dwSubTheme; // 0x3C
    int dwSubWaypoint; // 0x40
    int dwSubShrine; // 0x44
    int dwVis[8]; // 0x48
    int dwWarp[8]; // 0x68
    unsigned char nIntensity; // 0x88
    unsigned char nRed; // 0x89
    unsigned char nGreen; // 0x8A
    unsigned char nBlue; // 0x8B
    int dwPortal; // 0x8C
    int dwPosition; // 0x90
    int dwSaveMonsters; // 0x94
    int dwLOSDraw; // 0x98
};

D2_CHECK_SIZE(D2RoomTileStrc, 0x18);
D2_CHECK_SIZE(D2DrlgRoomTilesStrc, 0x18);
D2_CHECK_SIZE(D2DrlgTileGridStrc, 0x2C);
D2_CHECK_SIZE(D2LevelDefBin, 0x9C);

struct D2DrlgAnimTileGridStrc
{
    D2DrlgTileDataStrc** ppMapTileData; // 0x00
    int nFrames; // 0x04
    int nCurrentFrame; // 0x08
    int nAnimationSpeed; // 0x0C
    D2DrlgAnimTileGridStrc* pNext; // 0x10
};

struct D2UnkDrlgRoomTileStrc
{
    int nLevelId; // 0x00
    int nArrayStartId; // 0x04
    int nArrayEndId; // 0x08
};

D2_CHECK_SIZE(D2DrlgAnimTileGridStrc, 0x14);
D2_CHECK_SIZE(D2UnkDrlgRoomTileStrc, 0xC);
