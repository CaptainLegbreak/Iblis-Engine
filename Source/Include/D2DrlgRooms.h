#pragma once
struct D2PoolSystemStrc;
// Level generation: outdoor room data, substitution groups, maze build lists, acts and room tile links

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Drlg.h"

struct D2DrlgEnvironmentStrc;
struct D2DrlgVertexStrc;
struct D2DrlgOutdoorRoomStrc;
struct D2DrlgSubstGroupStrc;
struct D2DrlgBuildStrc;
struct D2DrlgActStrc;
struct D2UnkDrlgRoomTileStrc2;

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

struct D2DrlgOutdoorRoomStrc
{
    D2DrlgGridStrc pTileTypeGrid; // 0x00
    D2DrlgGridStrc tGrid14; // 0x14
    D2DrlgGridStrc tGrid28; // 0x28
    D2DrlgGridStrc tGrid3C; // 0x3C
    D2DrlgVertexStrc* pVertex; // 0x50
    unsigned int dwFlags; // 0x54
    int dwFlagsEx; // 0x58
    int unk0x5C; // 0x5C
    int unk0x60; // 0x60
    int nTileInfo64; // 0x64
    int nTileInfo68; // 0x68
    int nTileInfo6C; // 0x6C
};

struct D2DrlgSubstGroupStrc
{
    D2DrlgCoordStrc tBox; // 0x00
    int unk0x10; // 0x10
    int nSubstGroup; // 0x14
};

struct D2DrlgBuildStrc
{
    int nPreset; // 0x00
    int nDivisor; // 0x04
    int nRand; // 0x08
    D2DrlgBuildStrc* pNext; // 0x0C
};

struct D2DrlgActStrc
{
    int bHasPendingUnitListUpdates; // 0x00
    D2DrlgEnvironmentStrc* pEnvironment; // 0x04
    int nTownId; // 0x08
    unsigned int dwInitSeed; // 0x0C
    D2ActiveRoomStrc* pRoom; // 0x10
    unsigned char nAct; // 0x14
    unsigned char unk0x15; // 0x15
    unsigned short unk0x16; // 0x16
    void* pTileData[12]; // 0x18
    D2DrlgStrc* pDrlg; // 0x48
    ACTCALLBACKFN pfnActCallBack; // 0x4C
    int bClient; // 0x50
    int bHasPendingRoomsUpdates; // 0x54
    int bHasPendingRoomDeletions; // 0x58
    D2PoolSystemStrc* pMemPool; // 0x5C
};

struct D2UnkDrlgRoomTileStrc2
{
    int nTileStyle; // 0x00
    int nTileSequence; // 0x04
    int bIsRightWallWithDoor; // 0x08
    int nUnitId; // 0x0C
    int nUnitType; // 0x10
    int nX; // 0x14
    int nY; // 0x18
};

D2_CHECK_SIZE(D2DrlgOutdoorRoomStrc, 0x70);
D2_CHECK_SIZE(D2DrlgSubstGroupStrc, 0x18);
D2_CHECK_SIZE(D2DrlgBuildStrc, 0x10);
D2_CHECK_SIZE(D2DrlgActStrc, 0x60);
D2_CHECK_SIZE(D2UnkDrlgRoomTileStrc2, 0x1C);

struct D2DrlgPathNodeStrc;

struct D2EnvironmentCycleStrc
{
    int nTicksBegin; // 0x00
    int nPeriodOfDay; // 0x04
    unsigned char nRed; // 0x08
    unsigned char nGreen; // 0x09
    unsigned char nBlue; // 0x0A
    unsigned char nIntensity; // 0x0B
};

struct D2DrlgOutRectStrc
{
    int nX; // 0x00
    int nY; // 0x04
    int unk0x08; // 0x08
    unsigned char nFlags; // 0x0C
    char pad0x0D[3]; // 0x0D
    D2DrlgOutRectStrc* pBounds; // 0x10
};

struct D2OutdoorColumnFilesStrc
{
    int nLeft; // 0x00
    int nRight; // 0x04
};

struct D2DrlgRoadStrc
{
    char _pad_0x00[0x80];
    D2CoordStrc tEnd;
    char _pad_0x88[0x70];
    D2CoordStrc tEndInner;
    char _pad_0x100[0x70];
    D2CoordStrc tStartInner;
    char _pad_0x178[0x70];
    D2CoordStrc tStart;
    unsigned char nStartType;
    char _pad_0x1F1[0x03];
};

struct D2DrlgPathNodeStrc
{
    int nCost; // 0x00
    int nEstimate; // 0x04
    int nSpent; // 0x08
    int nX; // 0x0C
    int nY; // 0x10
    int nTried; // 0x14
    const unsigned char* pTurn; // 0x18
    unsigned char nDirection; // 0x1C
    D2DrlgPathNodeStrc* pParent; // 0x20
    D2DrlgPathNodeStrc* pChild; // 0x24
};

struct D2DrlgPathSearchStrc
{
    D2DrlgPathNodeStrc* pStart;
    D2DrlgPathNodeStrc tNodes[900];
    int nNodes;
};

D2_CHECK_SIZE(D2EnvironmentCycleStrc, 0xC);
D2_CHECK_SIZE(D2DrlgOutRectStrc, 0x14);
D2_CHECK_SIZE(D2OutdoorColumnFilesStrc, 0x8);
D2_CHECK_SIZE(D2DrlgRoadStrc, 0x1F4);
D2_CHECK_SIZE(D2DrlgPathNodeStrc, 0x28);
D2_CHECK_SIZE(D2DrlgPathSearchStrc, 0x8CA8);

struct D2DrlgEnvironmentStrc
{
    int nCycleIndex; // 0x00
    int nPeriodOfDay; // 0x04
    int nTicks; // 0x08
    int nIntensity; // 0x0C
    unsigned int dwInitTick; // 0x10
    int unk0x14; // 0x14
    unsigned char nRed; // 0x18
    unsigned char nGreen; // 0x19
    unsigned char nBlue; // 0x1A
    unsigned char pad0x1B; // 0x1B
    float fCos; // 0x1C
    float fLast; // 0x20
    float fSin; // 0x24
    int nTimeRate; // 0x28
    int nTimeRateIndex; // 0x2C
    int bEclipse; // 0x30
    int nPrev; // 0x34
};

D2_CHECK_SIZE(D2DrlgEnvironmentStrc, 0x38);
