#pragma once
// Data tables: the level, level preset and difficulty records, and the unique item, superunique, hireling, state and pet type records.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Records.h"

struct D2LevelsTxt;
struct D2LvlPrestTxt;
struct D2DifficultyLevelsTxt;
struct D2UniqueItemsTxt;
struct D2SuperUniquesTxt;
struct D2HirelingTxt;
struct D2StatesTxt;
struct D2PetTypeTxt;

struct D2LevelsTxt
{
    unsigned short wLevelNo; // 0x00
    unsigned char nPal; // 0x02
    unsigned char nAct; // 0x03
    unsigned char nTeleport; // 0x04
    unsigned char nRain; // 0x05
    unsigned char nMud; // 0x06
    unsigned char nNoPer; // 0x07
    unsigned char nIsInside; // 0x08
    unsigned char nDrawEdges; // 0x09
    unsigned short pad0x0A; // 0x0A
    unsigned int dwWarpDist; // 0x0C
    unsigned short wMonLvl[3]; // 0x10
    short wMonLvlEx[3]; // 0x16
    unsigned int dwMonDen[3]; // 0x1C
    unsigned char nMonUMin[3]; // 0x28
    unsigned char nMonUMax[3]; // 0x2B
    unsigned char nWandering; // 0x2E
    unsigned char nMonSpcWalk; // 0x2F
    unsigned char nQuest; // 0x30
    unsigned char nRangedSpawn; // 0x31
    unsigned char nNumMon; // 0x32
    unsigned char nNumNormalMonsters; // 0x33
    unsigned char nNumNightmareHellMonsters; // 0x34
    unsigned char nNumUniqueMonsters; // 0x35
    short wNormalMonsters[25]; // 0x36
    short wNightmareHellMonsters[25]; // 0x68
    short wUniqueMonsters[25]; // 0x9A
    short wCMon[4]; // 0xCC
    short wCPct[4]; // 0xD4
    short wCAmt[4]; // 0xDC
    unsigned char nWaypoint; // 0xE4
    unsigned char nObjGroup[8]; // 0xE5
    unsigned char nObjPrb[8]; // 0xED
    char szLevelName[40]; // 0xF5
    char szLevelWarp[40]; // 0x11D
    char szEntryFile[40]; // 0x145
    unsigned char pad0x16D; // 0x16D
    unsigned short wszLevelName[40]; // 0x16E
    unsigned short wszLevelWarp[40]; // 0x1BE
    unsigned short pad0x20E; // 0x20E
    unsigned int dwThemes; // 0x210
    unsigned int dwFloorFilter; // 0x214
    unsigned int dwBlankScreen; // 0x218
    unsigned char nSoundEnv; // 0x21C
    unsigned char pad0x21D; // 0x21D
    unsigned short pad0x21E; // 0x21E
};

struct D2LvlPrestTxt
{
    int dwDef; // 0x00
    int dwLevelId; // 0x04
    int dwPopulate; // 0x08
    int dwLogicals; // 0x0C
    int dwOutdoors; // 0x10
    int dwAnimate; // 0x14
    int dwKillEdge; // 0x18
    int dwFillBlanks; // 0x1C
    int dwExpansion; // 0x20
    int nAnimSpeed; // 0x24
    int nSizeX; // 0x28
    int nSizeY; // 0x2C
    int dwAutoMap; // 0x30
    int dwScan; // 0x34
    int dwPops; // 0x38
    int dwPopPad; // 0x3C
    int dwFiles; // 0x40
    char szFile[6][60]; // 0x44
    unsigned int dwDt1Mask; // 0x1AC
};

struct D2DifficultyLevelsTxt
{
    int dwResistPenalty; // 0x00
    unsigned int dwDeathExpPenalty; // 0x04
    int dwUberCodeOddsNorm; // 0x08
    int dwUberCodeOddsGood; // 0x0C
    int dwMonsterSkillBonus; // 0x10
    int dwMonsterFreezeDiv; // 0x14
    int dwMonsterColdDiv; // 0x18
    int dwAiCurseDivisor; // 0x1C
    int dwUltraCodeOddsNorm; // 0x20
    int dwUltraCodeOddsGood; // 0x24
    int dwLifeStealDiv; // 0x28
    int dwManaStealDiv; // 0x2C
    int dwUniqueDamageBonus; // 0x30
    int dwChampionDmgBonus; // 0x34
    int dwHireableBossDamagePercent; // 0x38
    int nMonsterCEDamagePercent; // 0x3C
    int dwStaticFieldMin; // 0x40
};

struct D2UniqueItemsTxt
{
    short wId; // 0x00
    char szName[32]; // 0x02
    unsigned short wTblIndex; // 0x22
    int nVersion; // 0x24
    unsigned int dwCode; // 0x28
    unsigned char nUniqueItemFlags[4]; // 0x2C
    int nRarity; // 0x30
    unsigned char nLevel; // 0x34
    unsigned char pad0x35; // 0x35
    unsigned short wLvlReq; // 0x36
    char nChrTransform; // 0x38
    char nInvTransform; // 0x39
    char szFlippyFile[32]; // 0x3A
    char szInvFile[32]; // 0x5A
    unsigned short pad0x7A; // 0x7A
    int dwCostMult; // 0x7C
    int dwCostAdd; // 0x80
    short wDropSound; // 0x84
    short wUseSound; // 0x86
    unsigned char nDropSfxFrame; // 0x88
    unsigned char pad0x89; // 0x89
    unsigned short pad0x8A; // 0x8A
    D2PropertyStrc pProperties[12]; // 0x8C
};

struct D2SuperUniquesTxt
{
    unsigned short wSuperUnique; // 0x00
    unsigned short wNameStr; // 0x02
    int dwClass; // 0x04
    int dwHcIdx; // 0x08
    int dwMod[3]; // 0x0C
    int dwMonSound; // 0x18
    int dwMinGrp; // 0x1C
    int dwMaxGrp; // 0x20
    unsigned char nAutopos; // 0x24
    unsigned char nEclass; // 0x25
    unsigned char nStacks; // 0x26
    unsigned char nReplaceable; // 0x27
    unsigned char nModes[3]; // 0x28
    unsigned char pad0x2B; // 0x2B
    unsigned short wTC[3]; // 0x2C
    unsigned short pad0x32; // 0x32
};

struct D2HirelingTxt
{
    unsigned short wVersion; // 0x00
    unsigned short pad0x02; // 0x02
    int nId; // 0x04
    int dwClass; // 0x08
    int dwAct; // 0x0C
    int dwDifficulty; // 0x10
    int dwSeller; // 0x14
    int nGold; // 0x18
    int nHirelingLevel; // 0x1C
    int dwExpPerLvl; // 0x20
    int dwHitpoints; // 0x24
    int dwHitpointsPerLvl; // 0x28
    int dwDefense; // 0x2C
    int dwDefensePerLvl; // 0x30
    int nStr; // 0x34
    int nStrPerLvl; // 0x38
    int nDex; // 0x3C
    int nDexPerLvl; // 0x40
    int dwAttackRate; // 0x44
    int dwAttackRatePerLvl; // 0x48
    int dwShare; // 0x4C
    int nDmgMin; // 0x50
    int nDmgMax; // 0x54
    int nDmgPerLvl; // 0x58
    int dwResist; // 0x5C
    int dwResistPerLvl; // 0x60
    int dwDefaultChance; // 0x64
    int dwEquipment[4]; // 0x68
    int dwSkill[6]; // 0x78
    int dwChance[6]; // 0x90
    int dwChancePerLvl[6]; // 0xA8
    char nMode[6]; // 0xC0
    char nLevel[6]; // 0xC6
    char nSLvlPerLvl[6]; // 0xCC
    unsigned char nHireDesc; // 0xD2
    char szNameFirst[32]; // 0xD3
    char szNameLast[32]; // 0xF3
    unsigned char pad0x113; // 0x113
    unsigned short wNameFirst; // 0x114
    unsigned short wNameLast; // 0x116
};

struct D2StatesTxt
{
    unsigned short wState; // 0x00
    short wOverlay[4]; // 0x02
    unsigned short wCastOverlay; // 0x0A
    unsigned short wRemoveOverlay; // 0x0C
    short wPrgOverlay; // 0x0E
    unsigned char nStateFlags[8]; // 0x10
    short wStat; // 0x18
    short wSetFunc; // 0x1A
    short wRemFunc; // 0x1C
    unsigned short wGroup; // 0x1E
    unsigned char nColorPri; // 0x20
    unsigned char nColorShift; // 0x21
    unsigned char nLightRGB[3]; // 0x22
    unsigned char pad0x25; // 0x25
    short wOnSound; // 0x26
    short wOffSound; // 0x28
    short wItemType; // 0x2A
    unsigned char nItemTrans; // 0x2C
    unsigned char nGfxType; // 0x2D
    short wGfxClass; // 0x2E
    short wCltEvent; // 0x30
    short wCltEventFunc; // 0x32
    short wCltActiveFunc; // 0x34
    short callback; // 0x36
    short wSkill; // 0x38
    short wMissile; // 0x3A
};

struct D2PetTypeTxt
{
    unsigned int dwHcIdx; // 0x00
    unsigned char nPetFlags[4]; // 0x04
    short wGroup; // 0x08
    short wBaseMax; // 0x0A
    unsigned short wStringId; // 0x0C
    union
    {
        struct
        {
            unsigned char nIconType; // 0x0E
            char szBaseicon[209]; // 0x0F
        };
        struct
        {
            unsigned char nIconType; // 0x0E
            char szIcon[5][32]; // 0x0F
            char pad0xAF; // 0xAF
            unsigned short wClass[5]; // 0xB0
        };
    };
};

D2_CHECK_SIZE(D2LevelsTxt, 0x220);
D2_CHECK_SIZE(D2LvlPrestTxt, 0x1B0);
D2_CHECK_SIZE(D2DifficultyLevelsTxt, 0x44);
D2_CHECK_SIZE(D2UniqueItemsTxt, 0x14C);
D2_CHECK_SIZE(D2SuperUniquesTxt, 0x34);
D2_CHECK_SIZE(D2HirelingTxt, 0x118);
D2_CHECK_SIZE(D2StatesTxt, 0x3C);
D2_CHECK_SIZE(D2PetTypeTxt, 0xE0);
