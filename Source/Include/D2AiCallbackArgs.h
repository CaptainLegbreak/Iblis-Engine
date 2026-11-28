#pragma once
// Game: the argument records the monster AI passes through its unit-search callbacks (targets, distances
// and counters each think function gathers), and the few small records those think functions share.

#include "D2Check.h"

struct D2UnitStrc;

struct D2PantherAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unused0x08[8];
};

struct D2BaalThroneAiCallbackArgStrc
{
    D2UnitStrc* pTarget1;
    int nDistance1;
    D2UnitStrc* pTarget2;
    int nDistance2;
    int unused0x10[6];
};

struct D2BaalToStairsAiCallbackArgStrc
{
    int unused0x00;
    int nMaxDistance;
    int unused0x08[8];
};

struct D2SandRaiderAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int unused0x08[8];
};

struct D2SiegeBeastTowerAiCallbackArgStrc
{
    int nMaxDistance;
    int unused0x04;
    int unused0x08[8];
};

struct D2NihlathakOverseerAiCallbackArgStrc
{
    int nMaxDistance;
    int nDistantMaxDistance;
    int nMaxLifePercentage;
    D2UnitStrc* pTarget;
    D2UnitStrc* pDistantTarget;
    int nCounter;
    int unused0x18[4];
};

struct D2MinionSpawnerAiCallbackArgStrc
{
    int nMinions;
    int unused0x04[9];
};

struct D2ShadowMasterAiCallbackArgStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pClosestTarget;
    int nClosestDistanceSquared;
    int nCloseTargetCount;
    D2UnitStrc* pClosestTargetToOwner;
    int nClosestToOwnerDistanceSquared;
    int nTargetsNearOwner;
    int nTargetCount;
    int nSentryCount;
    D2UnitStrc* pKillableTarget;
};

struct D2ZakarumPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nCounter;
    int nMaxLifePercentage;
    int nMaxDistance;
    int unused0x10[6];
};

struct D2FetishShamanAiCallbackArgStrc
{
    D2UnitStrc* pClosestDeadTarget;
    int nSquaredDistanceToClosestDeadTarget;
    int nMaxSearchRangeSquared;
    D2UnitStrc* pClosestAliveTarget;
    int nSquaredDistanceToClosestAliveTarget;
    int nAliveTargets;
    int nHealCapability;
    int unused0x1C[3];
};

struct D2OblivionKnightAiCallbackArgStrc
{
    D2UnitStrc* pClosestDoomKnight;
    D2UnitStrc* pClosestWoundedDoomKnight;
    int nMaxDistanceSquared;
    int nClosestDistanceSquared;
    int nClosestWoundedDistanceSquared;
    int unused0x14[5];
};

struct D2GreaterMummyAiCallbackArgStrc
{
    D2UnitStrc* pReviveTarget;
    D2UnitStrc* pHealTarget;
    int nHealReviveCounter;
    int nCounter;
    int nMaxDistance;
    int bRadament;
    int bNormal;
    int unused0x1C[3];
};

struct D2HighPriestAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nLifePercentage;
    int nMaxDistance;
    int unused0x0C[7];
};

struct D2MephistoAiCallbackArgStrc
{
    D2UnitStrc* pClosestTarget;
    int nClosestDistanceSquared;
    int nCloseTargetCount;
    D2UnitStrc* pLowestLifeTarget;
    int nLowestLife;
    D2UnitStrc* pClosestTargetForPlayerActor;
    int nClosestPlayerActorDistanceSquared;
    int nCounter;
    int unused0x20;
    int unused0x24;
};

struct D2VultureAiCallbackArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    int nLifePercentage;
    int unused0x0C[7];
};

struct D2ShadowMasterSkillStrc
{
    D2UnitStrc* pTarget;
    int nSkillId;
    int nChance;
    int nX;
    int nY;
};

struct D2PetMoveStrc
{
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
    int nCounter;
};

struct D2Unk005EAD50CounterStrc
{
    char unused0x00[0x14];
    int nFrame;
    int nValue;
    int nBase;
};

struct D2Unk005EAD50LimitsStrc
{
    char unused0x00[0x82];
    short nMin;
    short nMax;
};

struct D2Unk005EAD50ArgStrc
{
    D2Unk005EAD50CounterStrc* pCounter;
    char unused0x04[0x18];
    D2Unk005EAD50LimitsStrc* pLimits;
};
