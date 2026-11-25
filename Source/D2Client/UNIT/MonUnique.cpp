#include "D2StatIds.h"

#include "D2Client.h"

#include "D2Structs.h"

#include "D2Txt.h"

#include "D2UnitData.h"

#include "D2SkillIds.h"

#include "D2DataTbls.h"

#include "D2LevelTxt.h"

#include "D2Unicode.h"

#define UNIT_MONSTER 1

#define MONTYPEFLAG_CHAMPION 4

struct D2GfxLightStrc;

union D2SeedStrc;

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit); // 0x00464930

D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

int __fastcall DLIGHTMAP_GetLightSize(D2GfxLightStrc* pLight); // 0x00474350

void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit);                                             // 0x0046B3C0

void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit);                                       // 0x0046B530

void __fastcall VIEW_SpawnBrDeathControl(D2UnitStrc* pUnit);                                           // 0x0046B680

void __fastcall sub_0046B710_SpawnMissileAtObject173(D2UnitStrc* pUnit);                                                            // 0x0046B710

void __fastcall VIEW_SpawnMissileNearObject(D2UnitStrc* pUnit);                                                            // 0x0046B850

void __fastcall VIEW_SpawnMephistoDeath(D2UnitStrc* pUnit);                                          // 0x0046B9A0

void __fastcall VIEW_SpawnAndarielDeath(D2UnitStrc* pUnit);                                               // 0x0046BA50

void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit);                                     // 0x0046BA90

void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit);                                     // 0x0046BB10

void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit);                                     // 0x0046BB90

void __fastcall VIEW_SpawnIzualDeath(D2UnitStrc* pUnit);                                             // 0x0046BC10

int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit);                                              // 0x0046BC70

void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit);                                        // 0x0046BC90

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

typedef void (__fastcall* UMODCALLBACK)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern const int gaUModList[4];                                                                     // 0x006DA4C8

extern UMODCALLBACK gpfnUModCallbacks[];                                                            // 0x00724D78

static inline unsigned __int64 SEED_RollLocalSeed(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer); // 0x00627260

#define NULL 0

extern "C" char* __cdecl strcpy(char*, const char*);

#pragma intrinsic(strcpy)

struct D2HoverModeStrc
{
    int nMode;
    unsigned short wStringId;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

// build: symbol ??__EgwszNameSeparator@@YAXXZ 0x006CAD00
Unicode gwszNameSeparator[2]; // 0x007C0C58

extern const D2HoverModeStrc gaHoverModes[];                                                       // 0x006DA488

int __fastcall sub_0045C390_RollRandom(D2SeedStrc* pSeed, int nMax);                                        // 0x0045C390

int __cdecl INV_FormatArgs(wchar_t* wszDest, const wchar_t* wszFormat, ...);                          // 0x0048BE80

int __fastcall MONSTER_IsChampionMonster(D2UnitStrc* pUnit);                                                             // 0x004AE320

wchar_t* __fastcall D2LANG_GetStringFromTblIndex(unsigned short wIndex);                                    // 0x00524A30

void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);                  // 0x00526320

void __fastcall MONSTERS_SetMonsterNameInMonsterData(D2UnitStrc* pUnit, const wchar_t* wszName);                        // 0x0063E810

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nSeed);                                             // 0x00650E40

wchar_t* __fastcall DATATBLS_RollRandomUniquePrefixString(D2UnitStrc* pUnit);                                          // 0x00653ED0

wchar_t* __fastcall DATATBLS_RollRandomUniqueSuffixString(D2UnitStrc* pUnit);                                          // 0x00653F10

wchar_t* __fastcall DATATBLS_RollRandomUniqueAppellationString(D2UnitStrc* pUnit);                                     // 0x00653F50

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId);                         // 0x006556E0

static D2MonsterDataStrc* CLIENT_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return NULL;
}

// 0x004AC730
D2MonsterDataStrc* __fastcall MONUNIQUE_MonsterDataOf(D2UnitStrc* pUnit)
{
    if (sub_0044BE50(pUnit) == 1)
        return pUnit->pMonsterData;
    return 0;
}

// 0x004AC740
unsigned char* __fastcall MONUNIQUE_GetMonUmods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = CLIENT_GetMonsterData(pUnit);
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}

// 0x004AC760
unsigned short __fastcall sub_004AC760_GetNameSeed(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = MONUNIQUE_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wNameSeed;
}

// 0x004AC780
void __fastcall sub_004AC780_SetMonsterWord(D2UnitStrc* pUnit, unsigned short nValue)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        pUnit->pMonsterData->wNameSeed = nValue;
}

// 0x004AC7A0
void __fastcall sub_004AC7A0_SetSuperUniqueId(D2UnitStrc* pUnit, unsigned short wSuperUniqueId)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        pUnit->pMonsterData->wBossHcIdx = wSuperUniqueId;
}

// 0x004AC7C0
short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = MONUNIQUE_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return pMonsterData->wBossHcIdx;
}

// 0x004AC7E0
int __fastcall sub_004AC7E0_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = MONUNIQUE_MonsterDataOf(pUnit);
    if (!pMonsterData)
        return 0;
    return (unsigned short)(pMonsterData->nTypeFlag & nFlag) != 0;
}

// 0x004AC810
void __fastcall MONUNIQUE_ToggleMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            if (bSet)
            {
                pMonsterData->nTypeFlag |= nFlag;
            }
            else
            {
                pMonsterData->nTypeFlag &= ~nFlag;
            }
        }
    }
}

// 0x004AC840
void __fastcall sub_004AC840_SetTypeFlag100(D2UnitStrc* pUnit, int bSet)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            if (bSet)
                pMonsterData->nTypeFlag |= 0x100;
            else
                pMonsterData->nTypeFlag &= ~0x100;
        }
    }
}

// 0x004AC870
void __fastcall MONUNIQUE_SetMonsterHoverName(D2UnitStrc* pUnit, int nMode, int bShow)
{
    wchar_t wszName[300];

    if (!bShow)
    {
        return;
    }

    for (int k = 0; k < 300; ++k)
    {
        wszName[k] = 0;
    }
    char szSpace[8];
    strcpy(szSpace, " ");
    sub_00526320_ToUnicode(gwszNameSeparator, szSpace, 2);

    D2SeedStrc* pSeed = &pUnit->pSeed;
    unsigned short nNameSeed = sub_004AC760_GetNameSeed(pUnit);
    D2MonsterDataStrc* pMonsterData = (pUnit && sub_0044BE50(pUnit) == 1) ? pUnit->pMonsterData : NULL;
    if (pMonsterData && (pMonsterData->nTypeFlag & 2))
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(sub_004AC7C0_GetSuperUniqueId(pUnit));
        if (!pSuperUniquesTxtRecord)
        {
            return;
        }

        unsigned short wNameStr = pSuperUniquesTxtRecord->wNameStr;
        if (!wNameStr)
        {
            wNameStr = 0x1506;
        }
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(wNameStr));
        return;
    }

    int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    if (MONSTER_IsChampionMonster(pUnit))
    {
        int i = 0;
        for (; i < 4; ++i)
        {
            if (gaHoverModes[i].nMode == nMode)
            {
                break;
            }
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        INV_FormatArgs(wszName, D2LANG_GetStringFromTblIndex(0x2B40), D2LANG_GetStringFromTblIndex(gaHoverModes[i].wStringId), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), 0);
        MONSTERS_SetMonsterNameInMonsterData(pUnit, wszName);
        return;
    }

    SEED_InitLowSeed(pSeed, nNameSeed);
    if (nMode == 12)
    {
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xC27));
        return;
    }

    switch (nClassId)
    {
    case 0x9C:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBCD));
        return;

    case 0xD3:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBEE));
        return;

    case 0xF2:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF6));
        return;

    case 0x100:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0x3F6));
        return;

    case 0xF3:
    case 0x14D:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF4));
        return;

    case 0x220:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF5));
        return;

    case 0x2C3:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0x2B92));
        return;

    case 0x2C4:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBEE));
        return;

    case 0x2C0:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF6));
        return;

    case 0x2C2:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0x3F6));
        return;

    case 0x2C1:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF4));
        return;

    case 0x2C5:
        MONSTERS_SetMonsterNameInMonsterData(pUnit, D2LANG_GetStringFromTblIndex(0xBF5));
        return;

    default:
        INV_FormatArgs(wszName, D2LANG_GetStringFromTblIndex(0x6B9), DATATBLS_RollRandomUniquePrefixString(pUnit), DATATBLS_RollRandomUniqueSuffixString(pUnit), 0);
        if (sub_0045C390_RollRandom(pSeed, 100) < 50)
        {
            INV_FormatArgs(wszName, D2LANG_GetStringFromTblIndex(0x6BA), DATATBLS_RollRandomUniquePrefixString(pUnit), DATATBLS_RollRandomUniqueSuffixString(pUnit), DATATBLS_RollRandomUniqueAppellationString(pUnit), 0);
        }
        MONSTERS_SetMonsterNameInMonsterData(pUnit, wszName);
        return;
    }
}

// 0x004ACC70
void __fastcall MONUNIQUE_InitUModLight(D2UnitStrc* pUnit, int nUnused, int bInit)
{
    if (!bInit)
    {
        return;
    }

    CUNIT_FreeLight(pUnit);

    D2GfxLightStrc* pLight;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData && (pUnit->pMonsterData->nTypeFlag & MONTYPEFLAG_CHAMPION))
    {
        const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
        D2SeedStrc seed;
        seed.nHighSeed = (unsigned int)(lSeed >> 32);
        seed.nLowSeed = (unsigned int)lSeed;
        const int nBlue = (int)lSeed;
        const int nGreen = (int)SEED_RollLocalSeed(&seed);
        const int nRed = (int)SEED_RollLocalSeed(&seed);
        pUnit->pSeed = seed;
        pLight = DLIGHTMAP_MakeLightEntry(pUnit, 0, 7, 0xFF, nRed, nGreen, nBlue);
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }

        pLight = DLIGHTMAP_MakeLightEntry(pUnit, 0, 7, 0xFF, pMonStats2TxtRecord->nLight_R, pMonStats2TxtRecord->nLight_G, pMonStats2TxtRecord->nLight_B);
    }

    pUnit->pLight = pLight;
    sub_00464CF0(pUnit, DLIGHTMAP_GetLightSize(pLight));
}

// 0x004ACD50
void __fastcall MONUNIQUE_ClearDurielFlag(D2UnitStrc* unit, void* unused, int unusedStack)
{
    if (GetUnitType(unit) == 1)
    {
        D2MonsterDataStrc* data = unit->pMonsterData;
        if (data)
            data->dwDurielFlag = 0;
    }
}

// 0x004ACD70
void __fastcall MONUNIQUE_AssignTeleportSkill(D2UnitStrc* pUnit, int nUnused, int bAssign)
{
    if (bAssign)
    {
        SKILLS_AssignSkill(pUnit, SKILL_MONTELEPORT, 1, 1, ".\\UNIT\\MonUnique.cpp", 0x157);
        SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_MONTELEPORT), 4);
    }
}

// 0x004ACDB0
int __fastcall MONUNIQUE_ApplyResistantMod(D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (bUnique)
    {
        if (nUMod == 28)
        {
            int nDefense = 2 * STATLIST_UnitGetStatValue(pUnit, STAT_ARMORCLASS, 0);
            STATLIST_SetUnitStat(pUnit, STAT_ARMORCLASS, nDefense, 0);
        }

        int nImmunities = 0;
        int nFireResist = STATLIST_UnitGetStatValue(pUnit, STAT_FIRERESIST, 0);
        int nLightResist = STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTRESIST, 0);
        int nColdResist = STATLIST_UnitGetStatValue(pUnit, STAT_COLDRESIST, 0);
        int nPoisonResist = STATLIST_UnitGetStatValue(pUnit, STAT_POISONRESIST, 0);
        int nDamageResist = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGERESIST, 0);
        int nMagicResist = STATLIST_UnitGetStatValue(pUnit, STAT_MAGICRESIST, 0);

        if (nFireResist >= 100) ++nImmunities;
        if (nLightResist >= 100) ++nImmunities;
        if (nColdResist >= 100) ++nImmunities;
        if (nPoisonResist >= 100) ++nImmunities;
        if (nDamageResist >= 100) ++nImmunities;
        if (nMagicResist >= 100) ++nImmunities;

        if (nImmunities < 2)
        {
            if (nUMod == 8)
            {
                if (nColdResist < 100)
                {
                    int nNewColdResist = nColdResist + 40;
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 100)
                    {
                        int nNewFireResist = nFireResist + 40;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 100)
                        {
                            int nNewLightResist = nLightResist + 40;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 9) STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nFireResist + 75, 0);
            else if (nUMod == 18) STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nColdResist + 75, 0);
            else if (nUMod == 17) STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nLightResist + 75, 0);
            else if (nUMod == 23) STATLIST_SetUnitStat(pUnit, STAT_POISONRESIST, nPoisonResist + 75, 0);
            else if (nUMod == 25) STATLIST_SetUnitStat(pUnit, STAT_MAGICRESIST, nMagicResist + 20, 0);
            else if (nUMod == 27)
            {
                if (nColdResist < 75)
                {
                    int nNewColdResist = nColdResist + 20;
                    STATLIST_SetUnitStat(pUnit, STAT_COLDRESIST, nNewColdResist, 0);
                    if (nNewColdResist >= 100) ++nImmunities;
                }
                if (nImmunities < 2)
                {
                    if (nFireResist < 75)
                    {
                        int nNewFireResist = nFireResist + 20;
                        STATLIST_SetUnitStat(pUnit, STAT_FIRERESIST, nNewFireResist, 0);
                        if (nNewFireResist >= 100) ++nImmunities;
                    }
                    if (nImmunities < 2)
                    {
                        if (nLightResist < 75)
                        {
                            int nNewLightResist = nLightResist + 20;
                            STATLIST_SetUnitStat(pUnit, STAT_LIGHTRESIST, nNewLightResist, 0);
                            if (nNewLightResist >= 100) return nImmunities + 1;
                        }
                    }
                }
            }
            else if (nUMod == 28) STATLIST_SetUnitStat(pUnit, STAT_DAMAGERESIST, nDamageResist + 50, 0);
        }
    }
}

// 0x004AD020
void __fastcall MONUNIQUE_ApplyUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
    {
        unsigned char* pUMods = pMonsterData->nMonUmod;
        if (pUMods && *pUMods)
        {
        const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);

        for (int j = 0; j < 4; ++j)
        {
            const int nUMod = gaUModList[j];
            if (gpfnUModCallbacks[nUMod])
                gpfnUModCallbacks[nUMod](pUnit, nUMod, bUnique);
        }

        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            if (gpfnUModCallbacks[nUMod])
                gpfnUModCallbacks[nUMod](pUnit, nUMod, bUnique);
        }
        }
    }
}

#include "gen/data/Source/D2Client/UNIT/MonUnique.inc"
