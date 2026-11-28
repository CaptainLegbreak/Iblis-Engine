#pragma once
struct D2PoolSystemStrc;
// A unit's skills: the skill record and the per-unit skill list

#include "D2Check.h"
#include "D2Structs.h"

struct D2SkillsTxt;
struct D2SkillStrc;
struct D2SkillListStrc;

struct D2SkillStrc
{
    D2SkillsTxt* pSkillsTxt; // 0x00
    D2SkillStrc* pNextSkill; // 0x04
    int dwSkillMode; // 0x08
    unsigned int dwFlags; // 0x0C
    int unk0x10[2]; // 0x10
    unsigned int nXpos; // 0x18
    unsigned int nYpos; // 0x1C
    unsigned int nPar3; // 0x20
    unsigned int nPar4; // 0x24
    int nSkillLevel; // 0x28
    int nLevelBonus; // 0x2C
    int nQuantity; // 0x30
    int nOwnerGUID; // 0x34
    int nCharges; // 0x38
    int bExcludeFromHighestLevelLookup; // 0x3C
};

struct D2SkillListStrc
{
    D2PoolSystemStrc* pMemPool; // 0x00
    D2SkillStrc* pFirstSkill; // 0x04
    D2SkillStrc* pLeftSkill; // 0x08
    D2SkillStrc* pRightSkill; // 0x0C
    D2SkillStrc* pUsedSkill; // 0x10
    void* unk0x14; // 0x14
};

D2_CHECK_SIZE(D2SkillStrc, 0x40);
D2_CHECK_SIZE(D2SkillListStrc, 0x18);

struct D2UnitStrc;

struct D2ItemCalcStrc
{
    D2UnitStrc* pUnit; // 0x00
    D2UnitStrc* pItem; // 0x04
};

struct D2MissileCalcStrc
{
    D2UnitStrc* pMissile; // 0x00
    D2UnitStrc* pOwner; // 0x04
    int nMissileId; // 0x08
    int nMissileLevel; // 0x0C
};

D2_CHECK_SIZE(D2ItemCalcStrc, 0x8);
D2_CHECK_SIZE(D2MissileCalcStrc, 0x10);
