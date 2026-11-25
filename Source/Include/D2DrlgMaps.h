#pragma once
// Level generation, map building: preset maps and their files, tile data and tile library entries, outdoor vertices and the orthogonal links between rooms.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2Win32Base.h"

struct D2DrlgSubstGroupStrc;
struct D2GlideTileStrc;
struct D2LRUNodeStrc;
struct D2LvlPrestTxt;
struct D2PresetUnitStrc;
struct D2RoomCoordListStrc;
struct D2DrlgTileDataStrc;
struct D2DrlgVertexStrc;
struct D2DrlgFileStrc;
struct D2DrlgMapStrc;
struct D2DrlgOrthStrc;
struct D2TileLibraryEntryStrc;

struct D2RoomCoordListStrc
{
    tagRECT pBox[2]; // 0x00
    int bNode; // 0x20
    int bRoomActive; // 0x24
    int nIndex; // 0x28
    D2RoomCoordListStrc* pNext; // 0x2C
};

struct D2DrlgTileDataStrc
{
    int nWidth; // 0x00
    int nHeight; // 0x04
    int nPosX; // 0x08
    int nPosY; // 0x0C
    D2RoomCoordListStrc* pCoordList; // 0x10
    unsigned int dwFlags; // 0x14
    D2TileLibraryEntryStrc* pTile; // 0x18
    int nTileType; // 0x1C
    D2DrlgTileDataStrc* pNext; // 0x20
    int dwPopFlags; // 0x24
    unsigned char nRed; // 0x28
    unsigned char nGreen; // 0x29
    unsigned char nBlue; // 0x2A
    unsigned char nIntensity; // 0x2B
    int nPopTick; // 0x2C
};

struct D2DrlgFileStrc
{
    int nSubstMethod; // 0x00
    void* pDS1File; // 0x04
    int unk0x08; // 0x08
    int nWidth; // 0x0C
    int nHeight; // 0x10
    int nWallLayers; // 0x14
    int nFloorLayers; // 0x18
    void* pTileTypeLayer[4]; // 0x1C
    void* pWallLayer[4]; // 0x2C
    void* pFloorLayer[2]; // 0x3C
    void* pShadowLayer; // 0x44
    int* pSubstGroupTags; // 0x48
    int nSubstGroups; // 0x4C
    D2DrlgSubstGroupStrc* pSubstGroups; // 0x50
    D2PresetUnitStrc* pPresetUnit; // 0x54
    D2DrlgFileStrc* pNext; // 0x58
};

struct D2DrlgMapStrc
{
    int nLevelPrest; // 0x00
    int nPickedFile; // 0x04
    D2LvlPrestTxt* pLvlPrestTxtRecord; // 0x08
    D2DrlgFileStrc* ptFile; // 0x0C
    D2DrlgCoordStrc tCoords; // 0x10
    D2DrlgVertexStrc* pVertices; // 0x20
    D2DrlgGridStrc pMapGrid; // 0x24
    D2PresetUnitStrc* pPresetUnit; // 0x38
    int bInited; // 0x3C
    int nPops; // 0x40
    int* pPopsIndex; // 0x44
    int* pPopsSubIndex; // 0x48
    int* pPopsOrientation; // 0x4C
    D2DrlgCoordStrc* pPopsLocation; // 0x50
    D2DrlgMapStrc* pNext; // 0x54
};

struct D2DrlgOrthStrc
{
    union // 0x00
    {
        D2DrlgRoomStrc* pRoom;
        D2DrlgLevelStrc* pLevel;
    };
    int nDirection; // 0x04
    int bPreset; // 0x08
    int bInit; // 0x0C
    D2DrlgCoordStrc* pBox; // 0x10
    D2DrlgOrthStrc* pNext; // 0x14
};

struct D2TileLibraryEntryStrc
{
    int nLightDirection; // 0x00
    unsigned short nRoofHeight; // 0x04
    unsigned short nFlags; // 0x06
    int nHeight; // 0x08
    int nWidth; // 0x0C
    int nHeightToBottom; // 0x10
    int nOrientation; // 0x14
    int nIndex; // 0x18
    int nSubIndex; // 0x1C
    int nRarity; // 0x20
    int transparentColorRGB24; // 0x24
    unsigned char aSubtileFlags[25]; // 0x28
    unsigned char unk0x41; // 0x41
    short nCacheIndex; // 0x42
    int unk0x44; // 0x44
    int nFileOffset; // 0x48
    unsigned int nSize; // 0x4C
    int nBlocks; // 0x50
    D2GlideTileStrc* pBlocks; // 0x54
    const char* szFilePath; // 0x58
    D2LRUNodeStrc* pNode; // 0x5C
};

D2_CHECK_SIZE(D2RoomCoordListStrc, 0x30);
D2_CHECK_SIZE(D2DrlgTileDataStrc, 0x30);
D2_CHECK_SIZE(D2DrlgFileStrc, 0x5C);
D2_CHECK_SIZE(D2DrlgMapStrc, 0x58);
D2_CHECK_SIZE(D2DrlgOrthStrc, 0x18);
D2_CHECK_SIZE(D2TileLibraryEntryStrc, 0x60);
