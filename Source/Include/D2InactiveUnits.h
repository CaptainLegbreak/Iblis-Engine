#pragma once
// Inactive unit lists: units parked in rooms that are not loaded

#include "D2Check.h"
#include "D2Structs.h"

struct D2MapAIStrc;
struct D2MinionListStrc;
struct D2InactiveItemNodeStrc;
struct D2InactiveMonsterNodeStrc;
struct D2InactiveUnitNodeStrc;
struct D2InactiveUnitListStrc;

struct D2InactiveItemNodeStrc
{
    D2InactiveItemNodeStrc* pNext; // 0x00
    int nFrame; // 0x04
    int nOwnerId; // 0x08
    unsigned short nBitstreamSize; // 0x0C
    unsigned char pBitstream[1]; // 0x0E
    unsigned char pad0x0F; // 0x0F
};

struct D2InactiveMonsterNodeStrc
{
    int nX; // 0x00
    int nY; // 0x04
    int nClassId; // 0x08
    int nUnitId; // 0x0C
    unsigned int nUnitFlags; // 0x10
    unsigned int nUnitFlagsEx; // 0x14
    int nTypeFlags; // 0x18
    int nOwnerId; // 0x1C
    D2MinionListStrc* pMinionList; // 0x20
    D2MapAIStrc* pMapAI; // 0x24
    int nAiSpecialState; // 0x28
    int nLevelId; // 0x2C
    unsigned short nNameSeed; // 0x30
    unsigned char nMonUMods[9]; // 0x32
    unsigned char pad0x3B; // 0x3B
    unsigned short nBossHcIdx; // 0x3C
    unsigned short pad0x3E; // 0x3E
    int nExperience; // 0x40
    int nMaxHitpoints; // 0x44
    int nHitpoints; // 0x48
    int nCmdParam1; // 0x4C
    int nCmdParam2; // 0x50
    int nGameFrame; // 0x54
    D2InactiveMonsterNodeStrc* pNext; // 0x58
};

struct D2InactiveUnitNodeStrc
{
    int nX; // 0x00
    int nY; // 0x04
    int nUnitType; // 0x08
    int nClassId; // 0x0C
    int nMode; // 0x10
    int nGameFrame; // 0x14
    unsigned int nUnitFlags; // 0x18
    unsigned int nUnitFlagsEx; // 0x1C
    int nUnitId; // 0x20
    int nFrame; // 0x24
    unsigned char nInteractType; // 0x28
    unsigned char pad0x29; // 0x29
    unsigned short pad0x2A; // 0x2A
    int nDropItemCode; // 0x2C
    D2InactiveUnitNodeStrc* pNext; // 0x30
};

struct D2InactiveUnitListStrc
{
    int nX; // 0x00
    int nY; // 0x04
    D2InactiveItemNodeStrc* pInactiveItems; // 0x08
    D2InactiveMonsterNodeStrc* pInactiveMonsters; // 0x0C
    D2InactiveUnitNodeStrc* pInactiveUnits; // 0x10
    D2InactiveUnitListStrc* pNext; // 0x14
};

D2_CHECK_SIZE(D2InactiveItemNodeStrc, 0x10);
D2_CHECK_SIZE(D2InactiveMonsterNodeStrc, 0x5C);
D2_CHECK_SIZE(D2InactiveUnitNodeStrc, 0x34);
D2_CHECK_SIZE(D2InactiveUnitListStrc, 0x18);

struct D2InactiveItemBufferStrc
{
    D2InactiveItemNodeStrc* pNext; // 0x00
    int nFrame; // 0x04
    int nOwnerId; // 0x08
    unsigned short nBitstreamSize; // 0x0C
    unsigned char pBitstream[0x400]; // 0x0E
};

D2_CHECK_SIZE(D2InactiveItemBufferStrc, 0x410);
