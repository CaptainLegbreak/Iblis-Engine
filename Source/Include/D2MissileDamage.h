#pragma once
// D2Common's missile damage record: a missile's damage ranges, filled from its skill and owner (MISSILE_ functions).

struct D2MissileDamageDataStrc
{
    int nFlags; // 0x00
    int nMinDamage; // 0x04
    int nMaxDamage; // 0x08
    int nFireMinDamage; // 0x0C
    int nFireMaxDamage; // 0x10
    int nFireLength; // 0x14
    int nLightMinDamage; // 0x18
    int nLightMaxDamage; // 0x1C
    int nMagicMinDamage; // 0x20
    int nMagicMaxDamage; // 0x24
    int nColdMinDamage; // 0x28
    int nColdMaxDamage; // 0x2C
    int nColdLength; // 0x30
    int nPoisonMinDamage; // 0x34
    int nPoisonMaxDamage; // 0x38
    int nPoisonLength; // 0x3C
    int nPoisonCount; // 0x40
    int nLifeDrainMinDamage; // 0x44
    int nLifeDrainMaxDamage; // 0x48
    int nManaDrainMinDamage; // 0x4C
    int nManaDrainMaxDamage; // 0x50
    int nStaminaDrainMinDamage; // 0x54
    int nStaminaDrainMaxDamage; // 0x58
    int nStunLength; // 0x5C
    int nBurningMin; // 0x60
    int nBurningMax; // 0x64
    int nBurnLength; // 0x68
    int nDemonDamagePercent; // 0x6C
    int nUndeadDamagePercent; // 0x70
    int nDamageTargetAC; // 0x74
    int nDamagePercent; // 0x78
};
