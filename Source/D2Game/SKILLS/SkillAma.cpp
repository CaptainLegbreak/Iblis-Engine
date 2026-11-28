#include "D2StatIds.h"
#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"
#include "D2LanguageNames.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
// build: symbol _gaszLanguageNames 0x00741C0C

union D2SeedStrc;

struct D2SkillsTxt;

struct D2UnitStrc;

struct D2DamageStrc;

struct D2DataTablesStrc;



#include "D2GameFuncs.h"


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540


int __fastcall D2GAME_RollElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0


void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0



static void __stdcall SKILLS_DamageImpaleWeapon(D2GameStrc* pGame, int nChance, int nAmount, D2UnitStrc* pItem, D2UnitStrc* pUnit); // 0x005DAA40

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0


struct Skills;

struct Skills
{
    char pad0[0x138];
    unsigned rangeCalc,durationCalc;
    char pad140[0xFC];
};

struct Tables
{
    char pad0[0xB6C];
    int missileCount;
    char padB70[0x28];
    Skills* skills;
    void* linker;
    int skillCount;
};

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

int __stdcall sub_00646CA0(D2UnitStrc*,unsigned,int,int); // 0x00646CA0




enum { MISSILE_FLAGS = 0x20 };


int __fastcall SKILLS_CountAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter); // 0x0056BC80





D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60


int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20


int __fastcall SKILLDESC_GetSkillParamSix(int); // 0x004F4110


int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20


void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0


struct D2GameStrc;

int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620


void __fastcall D2GAME_SetSummonPassiveStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470



enum
{
    UNITFLAG_SKSRVDOFUNC = 0x40,
    AISPECIALSTATE_NONE = 0,
    EVENTTYPE_AITHINK = 2,
};

static inline unsigned int sub_M401_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5 + pUnit->pSeed.nHighSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005DA8F0
int __fastcall SKILLS_SrvSt05_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!DATATBLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    return SUNIT_GetTargetUnit(pGame, pUnit) != 0;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005DA940
int __fastcall SKILLS_SrvSt06_PowerStrike_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, pSkillsTxtRecord->nSrcDam);
    return 1;
}

// 0x005DAA40
static void __stdcall SKILLS_DamageImpaleWeapon(D2GameStrc* pGame, int nChance, int nAmount, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    if (!ITEMSIsA(pItem, 0x2D))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0 && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
        {
            SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit);
        }
    }
    else if (ITEMS_HasDurability(pItem) && (int)(sub_M401_RollUnitSeed(pUnit) % 100) < nChance)
    {
        int nNewDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) - nAmount;
        if (nNewDurability < 0)
        {
            nNewDurability = 0;
        }

        if (nNewDurability)
        {
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nNewDurability, 0);
            D2GAME_PACKETS_SendPacket0x3E(UnitGetClient(pUnit, ".\\SKILLS\\SkillAma.cpp", 0x9B), pItem, 1, 0x48, nNewDurability, 0);
        }
        else
        {
            ITEMMODE_BreakItem(pGame, pUnit, pItem);
        }
    }
}

// 0x005DAB40
int __fastcall SKILLS_SrvSt07_Impale(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DamageStrc damage;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget && SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
        {
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
            if (damage.wResultFlags & 1)
            {
                const int nDamagePercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
                damage.dwPhysDamage = SUNITDMG_ApplyDamageBonuses(pUnit, 1, 0, 0, 0, nDamagePercent, 0, pSkillsTxtRecord->nSrcDam);
                if (pSkillsTxtRecord->nEType > 0)
                {
                    damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
                    if (damage.dwConvPct > 0)
                    {
                        damage.nConvType = pSkillsTxtRecord->nEType;
                    }
                }

                D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
                damage.dwHitFlags = 1;

                D2UnitStrc* pItem = PLAYER_GetWeaponForSkill(pUnit);
                if (pItem && ITEMS_HasDurability(pItem))
                {
                    const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
                    const int nAmount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
                    SKILLS_DamageImpaleWeapon(pGame, nChance, nAmount, pItem, pUnit);
                }
            }

            SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
            return 1;
        }
    }

    return 0;
}

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x005DACD0
int __fastcall SKILLS_SrvSt08_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!SKILLS_CanUseWeaponAmmo(pUnit))
    {
        PLRMODE_HandleDepletedWeapons(pGame, pUnit);
        PLRMODE_BreakDepletedWeapons(pGame, pUnit);
        return 0;
    }

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);

    int nTargetCount = 0;
    if (!pTarget)
    {
        pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nAuraRange, 3, -1, &nTargetCount);
    }
    else
    {
        nTargetCount = SKILLS_CountAuraTargets(pGame, pUnit, 0, 0, nAuraRange, 3);
    }

    int nDesiredShots = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
    int nShotsRemaining = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nDesiredShots > nShotsRemaining)
    {
        nDesiredShots = nShotsRemaining;
    }

    nTargetCount = D2_MIN(D2_MAX(nTargetCount, nDesiredShots), nShotsRemaining);
    SKILLS_SetParam1(pSkill, nTargetCount);

    if (pTarget)
    {
        SKILLS_SetParam2(pSkill, sub_0044BE50(pTarget));
        SKILLS_SetParam3(pSkill, UNITS_GetUnitId(pTarget));
    }
    else
    {
        SKILLS_SetParam2(pSkill, 1);
        SKILLS_SetParam3(pSkill, -1);
    }

    SKILLS_ConsumeWeaponOrAmmoQuantity(pGame, pUnit);
    return 1;
}

static inline D2SkillsTxt* GetSkillsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}

// 0x005DAE30
int __fastcall SKILLS_SrvSt09_Fend(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return 0;
    int nRange = SKILLS_GetMeleeSearchRange(pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nTargets = 0;
    if (!pTarget)
    {
        pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 0x20003, -1, &nTargets);
        if (!pTarget)
        {
            SKILLS_SetParam1(pSkill, 0);
            return 1;
        }
    }
    else
        nTargets = SKILLS_CountAuraTargets(pGame, pUnit, 0, 0, nRange, 0x20003);
    int nMaxTargets = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    if (nTargets >= nMaxTargets)
        nTargets = nMaxTargets;
    SKILLS_SetParam1(pSkill, nTargets);
    int nTargetType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    SKILLS_SetParam2(pSkill, nTargetType);
    nRange = pTarget ? pTarget->dwUnitId : -1;
    SKILLS_SetParam3(pSkill, nRange);
    return 1;
}

// 0x005DAF40
int __fastcall SKILLS_SrvSt37_Zeal_Fury_BloodLordFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nAuraRange = SKILLS_GetMeleeSearchRange(pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nAuraRange, 0x20003, -1, 0);
    }

    if (!pTarget)
    {
        SKILLS_SetParam1(pSkill, 0);
        return 0;
    }

    SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    int nUnitType = UNIT_INVALID;
    if (pTarget)
    {
        nUnitType = pTarget->dwUnitType;
    }
    SKILLS_SetParam2(pSkill, nUnitType);
    int nUnitGUID;
    if (!pTarget)
    {
        nUnitGUID = -1;
    }
    else
    {
        nUnitGUID = pTarget->dwUnitId;
    }
    SKILLS_SetParam3(pSkill, nUnitGUID);
    return 1;
}

// 0x005DB020
int __fastcall SKILLS_SrvSt10_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
    if (damage.wResultFlags & 1)
    {
        const int nMinDamage = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        const int nMaxDamage = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
        damage.dwLtngDamage = nMinDamage + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage);
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}

inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

struct D2CurseStrc;
struct D2AuraCallbackStrc;

struct D2SrvDo06Strc
{
    int nSkillId;
    int nSkillLevel;
    int nDuration;
    int nAuraTargetState;
    int nAuraStatId;
    int nAuraStatCalcValue;
};

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int (__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0

// 0x005DB150
int __fastcall SKILLS_AuraCallback_InnerSight_SlowMissiles(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2SrvDo06Strc* pArgs = (D2SrvDo06Strc*)pAuraCallback->pArgs;

    D2CurseStrc curse = {};
    curse.pUnit = pAuraCallback->pOwner;
    curse.pTarget = pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = pArgs->nAuraStatId;
    curse.nStatValue = pArgs->nAuraStatCalcValue;
    curse.nState = pArgs->nAuraTargetState;
    SKILLS_ApplyStateEffect(&curse);
    return 1;
}

// 0x005DB1C0
int __fastcall SKILLS_SrvDo006_InnerSight_SlowMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount || pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    D2SrvDo06Strc args;
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    args.nAuraStatId = pSkillsTxtRecord->wAuraStat[0];
    args.nAuraStatCalcValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[0], nSkillId, nSkillLevel);

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_InnerSight_SlowMissiles, &args, 1, ".\\SKILLS\\SkillAma.cpp", 527);
    return 1;
}

// 0x005DB2D0
int __fastcall SKILLS_SrvDo007_Jab(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    int nType;
    if (!pUnit)
    {
        nType = UNIT_INVALID;
    }
    else
    {
        nType = pUnit->dwUnitType;
    }

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (nType == UNIT_MONSTER)
    {
        MONSTERMODE_UpdateModeAttackStats(pUnit, 8);
    }

    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005DB410
int __fastcall SKILLS_SrvDo008_MultipleShot_Teeth_ShockWave(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missile;
    if (pUnit) pUnit->dwFlags |= 0x40;
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    if (!pSkillsTxtRecord) goto ReturnZero;
    int nX;
    int nY;
    if (D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        const int nTotal = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        int nUnitX;
        switch (pUnit->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nUnitX = pUnit->pStaticPath->nXPos;
            break;
        default:
            nUnitX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
            break;
        }
        int nDx = nX - nUnitX;
        int nUnitY;
        switch (pUnit->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nUnitY = pUnit->pStaticPath->nYPos;
            break;
        default:
            nUnitY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
            break;
        }
        int nDy = nY - nUnitY;
        SKILLS_EnlargeVector(&nDx, &nDy);
        SKILLS_MakeShortPerpendicularVector(&nDx, &nDy);
        nX += -(nDx * nTotal / 2);
        nY += -(nDy * nTotal / 2);
        int nMissile = pSkillsTxtRecord->wSrvMissileA;
        if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxtRecord->wSrvMissileB >= 0) nMissile = pSkillsTxtRecord->wSrvMissileB;
        if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount) goto ReturnZero;
        int nActive = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        if (!nActive) nActive = nTotal;
        memset(&missile, 0, sizeof(missile));
        missile.dwFlags = 0x820;
        missile.pOwner = pUnit;
        missile.pOrigin = pUnit;
        missile.nSkill = nSkillId;
        missile.nSkillLevel = nSkillLevel;
        missile.nMissile = nMissile;
        missile.nActivateFrame = SKILLS_EvaluateSkillFormula(missile.pOwner, pSkillsTxtRecord->dwCalc[1], missile.nSkill, missile.nSkillLevel);
        missile.dwFlags |= 0x10000;
        const int nOutside = (nTotal - nActive) / 2;
        if (nOutside > 0)
        {
            int i = nOutside;
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--i);
        }
        missile.dwFlags &= ~0x10000u;
        if (nActive > 0)
        {
            int i = nActive;
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--i);
        }
        missile.dwFlags |= 0x10000;
        int nRemaining = nTotal - nOutside - nActive;
        if (nRemaining > 0)
        {
            do
            {
                missile.nTargetX = nX;
                missile.nTargetY = nY;
                MISSILES_CreateMissileFromParams(pGame, &missile);
                nX += nDx;
                nY += nDy;
            } while (--nRemaining);
        }
    }
    return 1;
ReturnZero:
    return 0;
}

#define STAT_DAMAGEPERCENT 25

// 0x005DB6A0
void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int nBonus)
{
    if (nBonus)
    {
        const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
        STATLIST_SetUnitStat(pUnit, STAT_DAMAGEPERCENT, nValue + nBonus, 0);
    }
}

// 0x005DB6D0
int __fastcall SKILLS_SrvDo010_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxtRecord->wSrvMissileB >= 0)
    {
        nMissileId = pSkillsTxtRecord->wSrvMissileB;
    }

    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nSkill = nSkillId;
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.pTarget = pTarget;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nTargetX = nTargetX;
    missileParams.nTargetY = nTargetY;
    missileParams.nMissile = nMissileId;

    if (nParam)
    {
        missileParams.pInitFunc = SKILLS_AddDamagePercentBonus;
    }
    missileParams.nInitArg = nParam;

    if (!pTarget)
    {
        missileParams.dwFlags = 0x420;
    }

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pMissile)
    {
        if (pTarget)
        {
            MISSILE_SetTargetX(pMissile, 1);
        }
        else
        {
            MISSILE_SetTargetX(pMissile, 2);
        }

        const short nDiffX = nTargetX - CLIENTS_GetUnitX(pUnit);
        const short nDiffY = nTargetY - CLIENTS_GetUnitY(pUnit);
        MISSILE_SetTargetY(pMissile, nDiffX + (nDiffY << 16));
    }

    return 1;
}

inline int UNITS_GetUnitXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_GetUnitYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005DB850
int __fastcall SKILLS_SrvDo011_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    const int nMissileCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    const int nTargetX = UNITS_GetUnitXPositionInline(pTarget);
    const int nTargetY = UNITS_GetUnitYPositionInline(pTarget);
    const int nDestX = 2 * nTargetX - UNITS_GetUnitXPositionInline(pUnit);
    const int nDestY = 2 * nTargetY - UNITS_GetUnitYPositionInline(pUnit);

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nMissile = nMissileId;
    missileParams.nX = nTargetX;
    missileParams.nY = nTargetY;
    missileParams.nTargetX = nDestX;
    missileParams.nTargetY = nDestY;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    for (int i = 0; i < nMissileCount; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

static inline int GetTargetType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static inline int GetTargetId(D2UnitStrc* pUnit)
{
    int nId = -1;
    if (pUnit)
    {
        nId = pUnit->dwUnitId;
    }
    return nId;
}

// 0x005DBA40
int __fastcall SKILLS_SrvDo012_Strafe(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nCount = SKILLS_GetParam1(pSkill);
    if (!nCount) return 0;
    const int nTargetId = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam2(pSkill), nTargetId);
    if (!pTarget)
    {
        pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 3, nTargetId, 0);
        if (!pTarget) return 1;
    }
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    int nX = 0;
    int nY = 0;
    D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY);
    int nMissile = pSkillsTxt->wSrvMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1 && pSkillsTxt->wSrvMissileB >= 0)
        nMissile = pSkillsTxt->wSrvMissileB;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount) return 0;
    const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    D2MissileStrc missile;
    memset(&missile, 0, sizeof(missile));
    missile.dwFlags = 0x21;
    missile.pOwner = pUnit;
    missile.nX = CLIENTS_GetUnitX(pUnit);
    missile.nY = CLIENTS_GetUnitY(pUnit);
    missile.nSkill = nSkillId;
    missile.nSkillLevel = nSkillLevel;
    missile.nMissile = nMissile;
    missile.nTargetX = nX;
    missile.nTargetY = nY;
    missile.pInitFunc = SKILLS_AddDamagePercentBonus;
    missile.nInitArg = nDamage;
    MISSILES_CreateMissileFromParams(pGame, &missile);
    --nCount;
    SKILLS_SetParam1(pSkill, nCount);
    if (nCount <= 0) return 0;
    D2UnitStrc* pNextTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 3, !pTarget ? -1 : pTarget->dwUnitId, 0);
    if (pNextTarget)
    {
        SKILLS_SetParam2(pSkill, GetTargetType(pNextTarget));
        SKILLS_SetParam3(pSkill, GetTargetId(pNextTarget));
        SKILLS_RewindUnitAnimation(pUnit, SKILLDESC_GetSkillParamSix(nSkillId));
    }
    return 1;
}

struct D2StaticPathStrc;

// 0x005DBC60
int __fastcall SKILLS_SrvDo013_Fend_Zeal_Fury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nAuraRange = SKILLS_GetMeleeSearchRange(pUnit);
    const int nTargetGUID = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam2(pSkill), nTargetGUID);
    if (!pTarget || !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nAuraRange, 0x20003, nTargetGUID, 0);
        if (!pTarget)
        {
            return 0;
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
            D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
        }
    }

    unsigned char& nSrcDam = *(unsigned char*)&nSkillLevel;
    nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 4);

    const int nAttacksRemaining = SKILLS_GetParam1(pSkill) - 1;
    SKILLS_SetParam1(pSkill, nAttacksRemaining);
    if (nAttacksRemaining <= 0)
    {
        return 0;
    }

    D2UnitStrc* pNextTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nAuraRange, 0x20003, !pTarget ? -1 : pTarget->dwUnitId, 0);
    if (!pNextTarget)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, !pNextTarget ? 6 : pNextTarget->dwUnitType);
    SKILLS_SetParam3(pSkill, !pNextTarget ? -1 : pNextTarget->dwUnitId);
    SKILLS_RewindUnitAnimation(pUnit, SKILLDESC_GetSkillParamTwo(nSkillId));
    return 0;
}

// 0x005DBE50
int __fastcall SKILLS_SrvDo014_LightningStrike(D2GameStrc* game,D2UnitStrc* unit,int skillId,int level)
{
    Skills* record=GetSkills(skillId);
    if(!record) return 0;
    D2UnitStrc* target=SUNIT_GetTargetUnit(game,unit);
    if(!target) return 0;
    SUNITDMG_DrainItemDurability(game,unit,target,0);
    int range=sub_00646CA0(unit,record->rangeCalc,skillId,level);
    const int targetId=target->dwUnitId;
    D2UnitStrc* other=SKILLS_FindNextAuraTarget(game,unit,UNITS_GetUnitXPosition(target),UNITS_GetUnitYPosition(target),range,3,targetId,0);
    if(!other) return 0;
    int missileId=SKILLS_GetProgressiveSkillMissileId(unit,skillId);
    if(missileId<0 || missileId>=tables->missileCount) return 0;
    int duration=sub_00646CA0(unit,record->durationCalc,skillId,level);
    D2MissileStrc params;
    memset(&params,0,sizeof(params));
    params.dwFlags=MISSILE_FLAGS;
    params.pOwner=unit;
    params.pOrigin=target;
    params.nSkill=skillId;
    params.nSkillLevel=level;
    params.nMissile=missileId;
    params.nTargetX=CLIENTS_GetUnitX(other);
    params.nTargetY=CLIENTS_GetUnitY(other);
    D2UnitStrc* missile=MISSILES_CreateMissileFromParams(game,&params);
    if(missile) MISSILE_SetTargetX(missile,duration);
    return 1;
}


void __fastcall D2GAME_BOSSES_AssignUMod(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850

// 0x005DC000
int __fastcall SKILLS_SrvDo015_Dopplezon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = 0;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    UNITS_StoreOwner(pPet, pUnit);

    int nHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    nHp = DATATBLS_ApplyRatio(nHp, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel), 100);
    STATLIST_SetUnitStat(pPet, STAT_HITPOINTS, nHp, 0);
    STATLIST_SetUnitStat(pPet, STAT_MAXHP, nHp, 0);
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    STATLIST_SetUnitStat(pPet, STAT_LEVEL, nLevel, 0);

    D2GAME_SKILLS_SetSummonBaseStats(pGame, pUnit, pPet, 0, nSkillLevel);
    D2GAME_SetSummonPassiveStats(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);

    const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    EVENT_SetEvent(pGame, pPet, 7, pGame->dwGameFrame + nDuration, 0, 0);
    D2GAME_BOSSES_AssignUMod(pGame, pPet, 21, 0);
    UNITS_SetOverlay(pPet, 171, 0);
    D2GAME_UpdateSummonAI(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}

// 0x005DC1E0
int __fastcall SKILLS_SrvDo016_Valkyrie(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_SKILLS_SetSummonBaseStats(pGame, pUnit, pPet, 0, nSkillLevel);
    D2GAME_SetSummonPassiveStats(pGame, pUnit, pPet, nSkillId, nSkillLevel, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel));
    D2GAME_EVENTS_Delete(pGame, pPet, EVENTTYPE_AITHINK, 0);
    EVENT_SetEvent(pGame, pPet, EVENTTYPE_AITHINK, pGame->dwGameFrame + 20, 0, 0);
    STATES_ToggleState(pPet, STATE_VALKYRIE, 1);
    UNITS_StoreOwner(pPet, pUnit);
    D2GAME_UpdateSummonAI(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}

