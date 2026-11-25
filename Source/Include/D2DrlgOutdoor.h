#pragma once
// Drlg: records the outdoor level code passes between its units: the outdoor generation context (level,
// grids, preset and the tile callbacks), the room's tile grids, and the jungle branch record.

#include "D2Check.h"

struct D2DrlgLevelStrc;
struct D2DrlgGridStrc;
struct D2DrlgRoomStrc;
struct D2DrlgOutdoorRoomStrc;

struct D2UnkOutdoorStrc
{
    D2DrlgLevelStrc* pLevel;
    int* field_4;
    D2DrlgGridStrc* pGrid1;
    D2DrlgGridStrc* pGrid2;
    int nLevelPrestId;
    int field_14;
    int nLvlSubId;
    unsigned int(__fastcall* field_1C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    int(__fastcall* field_20)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nId, int nOffset, char nFlags);
    int(__fastcall* field_24)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nEntry, int nFloorFlags, unsigned int nWallFlags);
    int(__fastcall* field_28)(D2DrlgLevelStrc* pLevel, int, int nStyle);
    void(__fastcall* field_2C)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_30)(D2DrlgLevelStrc* pLevel, int nX, int nY);
    void(__fastcall* field_34)(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag);
};

struct D2UnkOutdoorStrc2
{
    D2DrlgRoomStrc* pDrlgRoom;
    D2DrlgOutdoorRoomStrc* pOutdoorRooms[4];
    D2DrlgGridStrc* pWallsGrids[4];
    D2DrlgGridStrc* pFloorGrid;
    int field_28;
    int nLayers;
    int nSubWaypoint_Shrine;
    int nSubTheme;
    int nSubThemePicked;
};

struct D2OffsetPosStrc
{
    int nX;
    int nY;
    int nA;
    int nB;
    int nDir;
};

struct D2JungleStrc
{
    D2OffsetPosStrc tCoord;
    int nBranch;
    D2JungleStrc* pBasedOn;
    D2JungleStrc* pBranches[3];
    int nPresetsBlocksX;
    int nPresetsBlocksY;
    int* pJungleDefs;
    int nJungleDefs;
};
