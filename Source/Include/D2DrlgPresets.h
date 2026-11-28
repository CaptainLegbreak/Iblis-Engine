#pragma once
// Preset rooms and levels, room tiles, level links, collision grids and maze tables

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2Path.h"
#include "D2DrlgTiles.h"

struct D2DrlgMapStrc;
struct D2DrlgTileDataStrc;
struct D2DrlgPresetInfoStrc;
struct D2DrlgPresetRoomStrc;
struct D2DrlgPresetLevelStrc;
struct D2DrlgRoomTilesStrc;
struct D2DrlgTileLinkStrc;
struct D2DrlgLevelLinkDataStrc;
struct D2DrlgLinkStrc;
struct D2RoomCollisionGridStrc;
struct D2MazeLevelIdStrc;
struct D2MazeLavaSetStrc;
struct D2PathInfoStrc;

struct D2DrlgPresetInfoStrc
{
    D2DrlgMapStrc* pDrlgMap; // 0x00
    int nDirection; // 0x04
};

struct D2DrlgPresetRoomStrc
{
    int nLevelPrest; // 0x00
    int nPickedFile; // 0x04
    D2DrlgMapStrc* pMap; // 0x08
    unsigned int dwFlags; // 0x0C
    D2DrlgGridStrc pWallGrid[4]; // 0x10
    D2DrlgGridStrc pTileTypeGrid[4]; // 0x60
    D2DrlgGridStrc pFloorGrid[2]; // 0xB0
    D2DrlgGridStrc pCellGrid; // 0xD8
    D2DrlgGridStrc* pMazeGrid; // 0xEC
    D2CoordStrc* pTombStoneTiles; // 0xF0
    int nTombStoneTiles; // 0xF4
};

struct D2DrlgPresetLevelStrc
{
    D2DrlgMapStrc* pDrlgMap; // 0x00
    int nDirection; // 0x04
};

struct D2DrlgTileLinkStrc
{
    int bFloor; // 0x00
    D2DrlgTileDataStrc* pMapTile; // 0x04
    D2DrlgTileLinkStrc* pNext; // 0x08
};

struct D2DrlgLevelLinkDataStrc
{
    D2SeedStrc pSeed; // 0x00
    D2DrlgCoordStrc pLevelCoord[15]; // 0x08
    D2DrlgLinkStrc* pLink; // 0xF8
    int nRand[4][15]; // 0xFC
    int nIteration; // 0x1EC
    int nCurrentLevel; // 0x1F0
};

struct D2DrlgLinkStrc
{
    void* pfLinker; // 0x00
    int nLevel; // 0x04
    int nLevelLink; // 0x08
    int nLevelLinkEx; // 0x0C
};

struct D2RoomCollisionGridStrc
{
    union // 0x00
    {
        struct
        {
            int nSubtileX; // 0x00
            int nSubtileY; // 0x04
            int nSubtileWidth; // 0x08
            int nSubtileHeight; // 0x0C
            int nTileX; // 0x10
            int nTileY; // 0x14
            int nTileWidth; // 0x18
            int nTileHeight; // 0x1C
        };
        D2DrlgCoordsStrc pRoomCoords;
    };
    unsigned short* pCollisionMask; // 0x20
};

struct D2MazeLevelIdStrc
{
    int nLevelPrestId1; // 0x00
    int nLevelPrestId2; // 0x04
    int nPickedFile; // 0x08
    int nDirection; // 0x0C
};

struct D2MazeLavaSetStrc
{
    int nLevelPrest; // 0x00
    int nDirection; // 0x04
    int nPickedFile; // 0x08
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord; // 0x00
    D2PathPointStrc tTargetCoord; // 0x04
    D2ActiveRoomStrc* pStartRoom; // 0x08
    D2ActiveRoomStrc* pTargetRoom; // 0x0C
    int unused0x10; // 0x10
    unsigned char field_14; // 0x14
    unsigned char pad0x15; // 0x15
    unsigned short pad0x16; // 0x16
    int nDistMax; // 0x18
    unsigned char nMinimumFScoreToEvaluate; // 0x1C
    unsigned char pad0x1D; // 0x1D
    unsigned short pad0x1E; // 0x1E
    int nPathType; // 0x20
    int nUnitSize; // 0x24
    int nCollisionPattern; // 0x28
    int nCollisionMask; // 0x2C
    D2DynamicPathStrc* pDynamicPath; // 0x30
};

D2_CHECK_SIZE(D2DrlgPresetInfoStrc, 0x8);
D2_CHECK_SIZE(D2DrlgPresetRoomStrc, 0xF8);
D2_CHECK_SIZE(D2DrlgPresetLevelStrc, 0x8);
D2_CHECK_SIZE(D2DrlgTileLinkStrc, 0xC);
D2_CHECK_SIZE(D2DrlgLevelLinkDataStrc, 0x1F4);
D2_CHECK_SIZE(D2DrlgLinkStrc, 0x10);
D2_CHECK_SIZE(D2RoomCollisionGridStrc, 0x24);
D2_CHECK_SIZE(D2MazeLevelIdStrc, 0x10);
D2_CHECK_SIZE(D2MazeLavaSetStrc, 0xC);
D2_CHECK_SIZE(D2PathInfoStrc, 0x34);

struct D2PresetCodeStrc
{
    char c0; // 0x00
    char c1; // 0x01
    char c2; // 0x02
    char c3; // 0x03
};

D2_CHECK_SIZE(D2PresetCodeStrc, 0x4);
