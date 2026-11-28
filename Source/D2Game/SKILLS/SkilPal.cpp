#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"
#include "D2LanguageNames.h"
#include "D2AnimData.h"
#include "D2CommonApi.h"
// build: symbol _gaszLanguageNames 0x00741A58

struct D2ActiveRoomStrc;

struct D2UnkCallRecordStrc;

struct D2MonsterRegionStrc;

struct D2StaticPathStrc;

struct D2ModeChangeStrc;

struct D2MonsterDataStrc;

struct D2CurseStrc;

struct D2AuraCallbackStrc;

struct D2StaticFieldCallbackArgStrc;

struct D2BasicAuraParamStrc;

struct D2DamageAuraParamStrc;

struct D2UnkPalSkillStrc2;

struct D2AiCmdStrc;

struct D2DifficultyLevelsTxt;

struct D2MissilesTxt;

struct D2SkillsTxt;

union D2SeedStrc;

struct D2UnitFindDataStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2DamageStrc;

struct D2MissileStrc;

struct D2DataTablesStrc;

enum D2C_F39Constants
{
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_SUCCESSFULHIT = 1,
    DAMAGERESULTFLAG_WILLDIE = 2,
    SKILLSFLAGINDEX_01 = 1,
    UNITFLAG_NOTC = 0x20000,
    EVENTTYPE_ENDANIM = 1,
    STATLIST_FLAG_8 = 8,
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20




#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540


int __fastcall SKILLS_ApplyAuraToSelf(D2GameStrc* pGame, D2UnitStrc* pUnit, AURACALLBACK pCallback, void* pArgs); // 0x0056B740


void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0


int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50

int __fastcall D2GAME_RollElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0







void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0






void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390


void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc*, void (__fastcall*)(D2UnitStrc*,int,D2StatListStrc*)); // 0x00625CE0

void __fastcall SKILLS_StatRemoveCallback_Conversion(D2UnitStrc*,int,D2StatListStrc*); // 0x005D01A0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10

void __stdcall D2COMMON_10476(D2StatListStrc*, int); // 0x006260B0


enum D2C_J10SkillPalConstants
{
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_CANBEATTACKED = 0x00000004,
};

int __fastcall sub_0045C390_SeedRollLimited(D2SeedStrc* pSeed, int nMax);                                    // 0x0045C390

struct D2RedemptionAuraParamStrc
{
    int nSkillId;
    int nSkillLevel;
    int nRedeemed;
};

void __fastcall SKILLS_CurseStateCallback_HolyFreeze(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005D0770

int __fastcall SKILLS_AuraCallback_HolyFreeze(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005D07C0



int __fastcall SKILLS_GetSequenceEventFrame(D2UnitStrc* pUnit); // 0x005CF8C0


static inline int GetUnitType(D2UnitStrc* pUnit) { int nType = 6; if (pUnit) nType = pUnit->dwUnitType; return nType; }

static inline int GetUnitId(D2UnitStrc* pUnit) { int nId = -1; if (pUnit) nId = pUnit->dwUnitId; return nId; }

struct D2RedemptionAuraCallbackArgStrc
{
    int nSkillId;
    int nSkillLevel;
    int nCounter;
};

struct D2MonStatsTxt;

int __fastcall SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005CF2A0

struct D2CharStatsTxt;

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0

int __fastcall SKILLS_GetFirstSkillParam(int nSkillId); // 0x004C9460



void __stdcall PATH_SetVelocity(D2DynamicPathStrc*, int, const char*, int); // 0x00648690

void __fastcall SKILLS_CurseStateCallback_BasicAura(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005CEC50

int __stdcall PLRSAVE_ShortenPoisonAndCurses(D2GameStrc* pGame, D2UnitStrc* pUnit, int nPercent); // 0x005CEC90


extern D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc*); // 0x00535BC0

extern int __stdcall sub_00646CA0_EvaluateFormula(D2UnitStrc*,unsigned int,int,int); // 0x00646CA0


extern void __fastcall SUNITDMG_AllocCombat(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,D2DamageStrc*,int); // 0x0057DBF0

typedef char chk_D2DamageStrc_size[sizeof(D2DamageStrc) == 0x70 ? 1 : -1];

typedef char chk_D2SkillsTxt_size[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define UNIT_PLAYER 0

#define MONMODE_ATTACK2 5

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

#define HITFLAG_SMITE 2

#define HITCLASS_SMITE 0x65

#define SRCDAM_SMITE 0x80

typedef int BOOL;


inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

inline unsigned char UNITS_GetMonsterComponent(D2UnitStrc* pUnit, int nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[nComponent];
    }

    return 0;
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

// 0x005CE790
int __fastcall SKILLS_SrvSt29_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
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
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
    return 1;
}

// 0x005CE8E0
int __fastcall SKILLS_SrvDo064_Sacrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    D2DamageStrc damage;
    if (pDamage)
    {
        memset(&damage, 0, sizeof(damage));
        damage.dwHitFlags |= 0x1000;

        const int nBaseDamage = D2_MIN(STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0), pDamage->dwPhysDamage);

        const int nDamage = DATATBLS_ApplyRatio(nBaseDamage, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel), 100);
        damage.dwPhysDamage = nDamage;
        damage.dwDmgTotal = nDamage;
        SUNITDMG_ExecuteEvents(pGame, pUnit, pUnit, 0, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pUnit, &damage);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    return 1;
}

// 0x005CE9F0
int __fastcall SKILLS_SrvDo150_Smite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pShield;
        if (!INVENTORY_GetEquippedShield(pUnit->pInventory, &pShield))
        {
            return 0;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pShield ? -1 : pShield->dwClassId);
        if (!pItemsTxtRecord)
        {
            return 0;
        }

        int nMinDamage = pItemsTxtRecord->nMinDam << 8;
        int nMaxDamage = pItemsTxtRecord->nMaxDam << 8;
        if (STATES_CheckState(pUnit, STATE_HOLYSHIELD))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HOLYSHIELD);
            if (pStatList)
            {
                const int nHolyShieldId = (int)STATLIST_GetSkillId(pStatList);
                const int nHolyShieldLevel = STATLIST_GetSkillLevel(pStatList);
                nMinDamage += SKILLS_GetMinPhysDamage(pUnit, nHolyShieldId, nHolyShieldLevel, 1);
                nMaxDamage += SKILLS_GetMaxPhysDamage(pUnit, nHolyShieldId, nHolyShieldLevel, 1);
            }
        }

        const int nDamagePercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage = SUNITDMG_ApplyDamageBonuses(pUnit, 0, pShield, nMinDamage, nMaxDamage, nDamagePercent, 0, SRCDAM_SMITE);

        const int nStunLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }

        D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);

        damage.dwStunLen = nStunLength;
        damage.dwHitFlags = HITFLAG_SMITE;
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0) | DAMAGERESULTFLAG_SUCCESSFULHIT;
    }
    else
    {
        MONSTERMODE_UpdateModeAttackStats(pUnit, MONMODE_ATTACK2);
        damage.dwStunLen = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
    }

    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    }

    damage.dwHitClass = HITCLASS_SMITE;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, SRCDAM_SMITE);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}


// 0x005CEC50
void __fastcall SKILLS_CurseStateCallback_BasicAura(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
    if (STATES_CheckState(pUnit, STATE_NOMANAREGEN))
    {
        STATES_ToggleState(pUnit, 85, 0);
    }

    D2GAME_RefreshPassiveSkills(pUnit);
    SKILLS_ClampVitalsAndUpdateAnimRate(pUnit);
}

#define EVENTTYPE_REMOVESTATE 12

int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090

// 0x005CEC90
int __stdcall PLRSAVE_ShortenPoisonAndCurses(D2GameStrc* pGame, D2UnitStrc* pUnit, int nPercent)
{
    int bPoisonedOrCursed = 0;
    if (STATES_CheckState(pUnit, STATE_POISON))
    {
        D2StatListStrc* pPoisonStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_POISON);
        if (pPoisonStatList)
        {
            const int nFrame = pGame->dwGameFrame;
            const int nRemaining = D2COMMON_10473(pPoisonStatList) - nFrame;
            const int nExpireFrame = DATATBLS_ApplyRatio(nRemaining, nPercent, 100) + nFrame;
            D2COMMON_10476(pPoisonStatList, nExpireFrame);
            EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
            bPoisonedOrCursed = 1;
        }
    }

    for (int i = 0; i < sgptDataTables->nCurseStates; ++i)
    {
        const int nCurseStateId = sgptDataTables->pCurseStates[i];
        if (STATES_CheckState(pUnit, nCurseStateId))
        {
            D2StatListStrc* pCurseStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nCurseStateId);
            if (pCurseStatList)
            {
                if (STATES_CheckStateMaskCurableByStateId(nCurseStateId))
                {
                    const int nFrame = pGame->dwGameFrame;
                    const int nRemaining = D2COMMON_10473(pCurseStatList) - nFrame;
                    const int nExpireFrame = DATATBLS_ApplyRatio(nRemaining, nPercent, 100) + nFrame;
                    D2COMMON_10476(pCurseStatList, nExpireFrame);
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
                }
                bPoisonedOrCursed = 1;
            }
        }
    }

    return bPoisonedOrCursed;
}

// 0x005CEDC0
int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2CurseStrc curse = {};
    D2BasicAuraParamStrc* pArgs = (D2BasicAuraParamStrc*)pAuraCallback->pArgs;
    curse.pTarget = pUnit;
    curse.pUnit = pAuraCallback->pOwner;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = -1;
    curse.nStatValue = 0;
    curse.nState = pArgs->nAuraState;
    if (pArgs->pStateRemoveCallback)
        curse.pStateRemoveCallback = (StatListRemoveFunc)pArgs->pStateRemoveCallback;
    else if (pAuraCallback->pOwner == pUnit)
        curse.pStateRemoveCallback = SKILLS_CurseStateCallback_BasicAura;
    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList) return 0;
    pArgs->pStatList = pStatList;
    int* pAuraStat = pArgs->nAuraStat;
    for (int i = 0; i < 6; ++i, ++pAuraStat)
    {
        if (!pAuraStat[6]) continue;
        int nStat = *pAuraStat;
        if (nStat <= 0 || nStat >= sgptDataTables->nItemStatCostTxtRecordCount) continue;
        if (nStat == 110)
        {
            if (PLRSAVE_ShortenPoisonAndCurses(pAuraCallback->pGame, pUnit, pAuraStat[6]))
                ++pArgs->nAffectedUnits;
            continue;
        }
        int nValue = SKILLS_ApplyResistanceImmunityPenalty(pUnit, nStat, pAuraStat[6]);
        if (!nValue) continue;
// build: symbol ?PLAYER_GetItemStatCostTxtRecord@* 0x0045C4F0
        D2ItemStatCostTxt* pRecord = PLAYER_GetItemStatCostTxtRecord(nStat);
        if (!pRecord) continue;
        if (!(pRecord->nItemStatFlags[0] & gdwBitMasks[4]))
        {
            if (STATLIST_GetStatValue(pStatList, nStat, 0) != nValue)
                STATES_ToggleGfxStateFlag(pUnit, curse.nState, 1);
            switch (nStat)
            {
            case 67:
            case 68:
            {
                int nColdEffect = SUNITDMG_GetColdEffect(SUNIT_GetGameFromUnit(pUnit), pUnit);
                if (nValue < nColdEffect) nValue = nColdEffect;
                break;
            }
            }
            STATLIST_SetStat(pStatList, nStat, nValue, 0);
            if (nStat == 68) STATLIST_SetStat(pStatList, STAT_OTHER_ANIMRATE, nValue, 0);
            ++pArgs->nAffectedUnits;
        }
        else
        {
            int nOldValue = STATLIST_UnitGetStatValue(pUnit, nStat, 0);
            nValue += nOldValue;
            int nMaxStat = pRecord->wMaxStat;
            if (nMaxStat < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                int nMax = STATLIST_UnitGetStatValue(pUnit, nMaxStat, 0);
                if (nValue >= nMax) nValue = nMax;
            }
            if (nValue != nOldValue)
            {
                STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
                ++pArgs->nAffectedUnits;
            }
        }
    }
    UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkilPal.cpp", 413);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, pArgs->nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, pArgs->nSkillLevel, 0);
    if (pArgs->nPassiveState > 0)
    {
        D2StatListStrc* pPassive = STATLIST_GetStatListFromUnitAndState(pUnit, pArgs->nPassiveState);
        if (pPassive)
        {
            D2Common_10474(pUnit, pPassive);
            STATLIST_FreeStatList(pPassive);
            STATES_ToggleGfxStateFlag(pUnit, pArgs->nPassiveState, 1);
        }
    }
    return 1;
}

// 0x005CF010
int __fastcall SKILLS_SrvDo065_BasicAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nManaCost = SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);

    D2BasicAuraParamStrc args;
    memset(&args, 0, sizeof(args));
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel) - pGame->dwGameFrame + 1;

    if (pSkillsTxtRecord->nPassiveState > 0)
    {
        args.nPassiveState = pSkillsTxtRecord->nPassiveState;
    }

    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER || nMana >= nManaCost)
    {
        for (int i = 0; i < 6; ++i)
        {
            const int nAuraStat = pSkillsTxtRecord->wAuraStat[i];
            if (nAuraStat < 0)
            {
                break;
            }

            args.nAuraStat[i] = nAuraStat;
            args.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
    }

    if (pSkillsTxtRecord->nAuraState > 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        args.nAuraState = pSkillsTxtRecord->nAuraState;

        SKILLS_ApplyAuraToSelf(pGame, pUnit, SKILLS_AuraCallback_BasicAura, &args);

        if (args.pStatList && nMana > nManaCost && pSkillsTxtRecord->nPassiveState <= 0)
        {
            for (int i = 0; i < 5; ++i)
            {
                const int nStat = pSkillsTxtRecord->nPassiveStat[i];
                const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
                if (nValue && nStat > 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    STATLIST_SetStat(args.pStatList, nStat, nValue, 0);
                }
            }
        }
    }

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        args.nAuraState = pSkillsTxtRecord->wAuraTargetState;

        const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);

        SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_BasicAura, &args, 1, ".\\SKILLS\\SkilPal.cpp", 502);

        if (nManaCost > 0)
        {
            if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
            {
                if (args.nAffectedUnits > 0)
                {
                    STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 1);
                    D2GAME_SKILLMANA_AuraConsume(pUnit, nManaCost);
                }
                else
                {
                    STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
                }
            }
        }
    }

    return 1;
}

// 0x005CF280
static int SKILLS_IsUnitOutsideTown(D2UnitStrc* pUnit)
{
    return !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit));
}

// 0x005CF2A0
int __fastcall SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageAuraParamStrc* pArgs = (D2DamageAuraParamStrc*)pAuraCallback->pArgs;
    D2GameStrc* pGame = pAuraCallback->pGame;
    D2UnitStrc* pOwner = pAuraCallback->pOwner;
    if (pArgs->nPassiveState)
    {
        D2BasicAuraParamStrc args;
        memset(&args, 0, sizeof(args));
        args.nAuraState = pArgs->nAuraState;
        args.nSkillId = pArgs->nSkillId;
        args.nSkillLevel = pArgs->nSkillLevel;
        args.nDuration = pArgs->nDuration;
        for (int i = 0; i < 6; ++i)
        {
            args.nAuraStat[i] = pArgs->nAuraStat[i];
            args.nAuraStatCalcValue[i] = pArgs->nAuraStatCalcValue[i];
        }

        D2AuraCallbackStrc auraCallback;
        auraCallback.pOwner = pOwner;
        auraCallback.pArgs = &args;
        auraCallback.pGame = pGame;
        SKILLS_AuraCallback_BasicAura(&auraCallback, pUnit);
    }

    if (pArgs->pDamage)
    {
        D2DamageStrc damage = *pArgs->pDamage;
        SUNITDMG_ExecuteEvents(pGame, pOwner, pUnit, 1, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pOwner, pUnit, &damage);
    }

    return 1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordOrNull(int nSkillId)
{
    D2SkillsTxt* pRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return pRecord;
}

// 0x005CF3A0
int __fastcall SKILLS_SrvDo066_HolyFire_HolyShock_Sanctuary_Conviction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordOrNull(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nManaCost = SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel) - pGame->dwGameFrame + 1;

    D2BasicAuraParamStrc args1;
    memset(&args1, 0, sizeof(args1));
    args1.nSkillId = nSkillId;
    args1.nSkillLevel = nSkillLevel;
    args1.nAuraState = pSkillsTxtRecord->nAuraState;
    args1.nDuration = nFrame;

    for (int i = 0; i < 5; ++i)
    {
        args1.nAuraStat[i] = pSkillsTxtRecord->nPassiveStat[i];
        if (GAME_GetUnitTypeOrInvalid(pUnit) != UNIT_PLAYER || nMana >= nManaCost)
        {
            args1.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
    }

    SKILLS_ApplyAuraToSelf(pGame, pUnit, SKILLS_AuraCallback_BasicAura, &args1);

    if (!SKILLS_IsUnitOutsideTown(pUnit))
    {
        return 1;
    }

    D2DamageAuraParamStrc args2;
    args2.nSkillId = nSkillId;
    args2.nSkillLevel = nSkillLevel;
    args2.nDuration = nFrame;
    args2.nAuraState = pSkillsTxtRecord->wAuraTargetState;
    args2.pDamage = 0;
    args2.nAffectedUnits = 0;
    args2.nPassiveState = 0;

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        for (int i = 0; i < 6; ++i)
        {
            args2.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
            if (nMana >= nManaCost)
            {
                args2.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
                if (args2.nAuraStatCalcValue[i])
                {
                    args2.nPassiveState = 1;
                }
            }
            else
            {
                args2.nAuraStatCalcValue[i] = 0;
            }
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    if (D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel))
    {
        damage.dwHitClass |= 0xD;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags | 0x20;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        args2.pDamage = &damage;
    }

    unsigned int const tArg7 = pSkillsTxtRecord->dwAuraRangeCalc;
    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, tArg7, nSkillId, nSkillLevel);

    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_HolyFire_HolyShock_Sanctuary_Conviction, &args2, 0, gszSkillPalSourceFile, 698);

    if (nManaCost > 0 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (args2.nAffectedUnits > 0)
        {
            STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 1);
            D2GAME_SKILLMANA_AuraConsume(pUnit, nManaCost);
        }
        else
        {
            STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
        }
    }

    return 1;
}

static inline int UNITS_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static inline int UNITS_GetUnitIdChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

// 0x005CF6B0
int __fastcall SKILLS_SrvSt31_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecordOrNull(nSkillId)) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath) return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget) {
        if (UNITS_IsInMeleeRange(pUnit, pTarget, 0)) {
            if (pUnit->dwUnitType == UNIT_PLAYER) return SKILLS_StartBasicAttack(pGame, pUnit, pTarget);
            SUNIT_SetCombatMode(pGame, pUnit, 1);
            UNITS_SetUsedSkill(pUnit, 0);
            const int nMonsterId = CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit));
            const int nMode = nMonsterId != MONSTER_CLAWVIPER1 ? (nMonsterId == MONSTER_DURIEL ? 5 : 4) : 5;
            D2ModeChangeStrc modeChange;
            MONSTERMODE_GetModeChangeInfo(pUnit, nMode, &modeChange);
            modeChange.pTargetUnit = pTarget;
            return D2GAME_ModeChange(pGame, &modeChange, 1);
        }
        if (!STATES_CheckState(pTarget, STATE_UNINTERRUPTABLE)) {
            SKILLS_SetParam1(pSkill, UNITS_GetUnitTypeChecked(pTarget));
            SKILLS_SetParam2(pSkill, UNITS_GetUnitIdChecked(pTarget));
        } else {
            SKILLS_SetParam1(pSkill, 6);
            SKILLS_SetParam2(pSkill, 0);
        }
    } else {
        SKILLS_SetParam1(pSkill, 6);
        SKILLS_SetParam2(pSkill, 0);
    }
    SKILLS_SetParam4(pSkill, 7);
    int nVelocity = 256;
    if (pUnit->dwUnitType == UNIT_PLAYER) {
        D2CharStatsTxt* pRecord = sub_004833E0_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pRecord) nVelocity = pRecord->nRunSpeed << 8;
    } else {
        const int nMonsterId = pUnit->dwClassId;
        D2MonStatsTxt* pRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
        if (pRecord) {
            nVelocity = pRecord->nRun << 8;
            if (nMonsterId == MONSTER_DURIEL) SKILLS_SetParam4(pSkill, 15);
            PATH_ClearPreviousTargetPoint(pPath);
            PATH_SetNewDistance(pPath, 20);
        }
    }
    int nBonus = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
    if (nBonus <= 50) nBonus = 50;
    PATH_SetVelocity(pPath, DATATBLS_ApplyRatio(nVelocity, SKILLS_GetFirstSkillParam(nSkillId) + nBonus, 100), ".\\SKILLS\\SkilPal.cpp", 816);
    D2Common_10142(pPath, pUnit, 0);
    SKILLS_SetFlags(pSkill, 0x1001);
    STATES_ToggleState(pUnit, 18, 1);
    return 1;
}

// 0x005CF8A0
static inline D2UnitStrc* SKILLS_FindMeleeTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID)
{
    return SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, 3, 3, nUnitGUID, 0);
}

struct D2AnimSeqTxt;

// 0x005CF8C0
int __fastcall SKILLS_GetSequenceEventFrame(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pMonSeqTxtRecord = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    if (pMonSeqTxtRecord)
    {
        const int nSequenceFrameCount = DATATBLS_GetSeqFrameCount(pUnit);
        for (int i = 0; i < nSequenceFrameCount; ++i)
        {
            if (!pMonSeqTxtRecord->nEvent)
            {
                return i - 1;
            }
        }
    }

    return 7;
}

static inline D2SkillsTxt* GetSkillsRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005CF900
int __fastcall SKILLS_SrvDo067_Charge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pRecord = GetSkillsRecord(nSkillId);
    if (!pRecord) return 0;
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    if (DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit)) DATATBLS_GetSeqFrameCount(pUnit);
    int nFrame = SKILLS_GetSequenceEventFrame(pUnit);
    int nTargetType = SKILLS_GetParam1(pSkill);
    int nTargetId = SKILLS_GetParam2(pSkill);
    D2UnitStrc* pTarget = 0;
    if (nTargetType != 6) pTarget = SUNIT_GetServerUnit(pGame, nTargetType, nTargetId);
    int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
    {
        int nRange = 0;
        if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && (nFlags & 2)) nRange = 3;
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, nRange))
        {
            SKILLS_SetFlags(pSkill, 0);
            D2GAME_SKILLS_RewindSkillEx(pGame, pUnit, nFrame + 1);
            SUNITMSG_QueueSkillStop(pUnit, nSkillId);
            return 1;
        }
        if (nFlags & 2)
        {
            SKILLS_SetFlags(pSkill, 0);
            SUNITMSG_QueueSkillStop(pUnit, nSkillId);
            pTarget = SKILLS_FindMeleeTarget(pGame, pUnit, nTargetId);
            if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                SKILLS_SetParam1(pSkill, GetUnitType(pTarget));
                SKILLS_SetParam2(pSkill, GetUnitId(pTarget));
            }
            else
            {
                if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit)) != 436 || CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit)) != 441)
                {
                    D2GAME_EVENTS_Delete(pGame, pUnit, 1, 0);
                    EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 1, 0, 0);
                }
                return 0;
            }
        }
        else
        {
            if (pGame->dwGameFrame - (pUnit->nSeqCurrentFramePrecise >> 8) >= nFrame)
            {
                D2GAME_SKILLS_RewindSkillEx(pGame, pUnit, 0);
                SKILLS_SetFlags(pSkill, 1);
            }
            D2GAME_EVENTS_Delete(pGame, pUnit, 0, 0);
            EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 1, 1, 0);
            pUnit->dwFlags &= ~0x40;
        }
        return 1;
    }
    SKILLS_SetFlags(pSkill, 0);
    SKILLS_SetParam1(pSkill, 0);
    SKILLS_SetParam2(pSkill, 0);
    SUNITMSG_QueueSkillStop(pUnit, nSkillId);
    D2GAME_SKILLS_RewindSkillEx(pGame, pUnit, nFrame);
    if (pUnit) pUnit->dwFlags |= 0x40;
    if (!pTarget)
    {
        pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, 3, 3, -1, 0);
        if (!pTarget)
        {
            D2GAME_EVENTS_Delete(pGame, pUnit, 1, 0);
            EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + 1, 0, 0);
            return 0;
        }
    }
    int nRange = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER) nRange = 3;
    if (UNITS_IsInMeleeRange(pUnit, pTarget, nRange) && !SUNIT_IsDead(pUnit))
    {
        D2DamageStrc damage;
        memset(&damage, 0, sizeof(damage));
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
        {
            damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0) | 8;
        }
        else damage.wResultFlags = 9;
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0) damage.nConvType = pRecord->nEType;
        }
        D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
        if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        {
            int nMode;
            switch (CUNIT_ValidateMonsterId(pUnit->dwClassId))
            {
            case 73: nMode = 8; break;
            case 211: case 436: nMode = 5; break;
            default: nMode = 4; break;
            }
            MONSTERMODE_UpdateModeAttackStats(pUnit, nMode);
        }
        damage.dwHitClass = 0x70;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, pRecord->nSrcDam);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        UNITS_SetOverlay(pTarget, 147, 0);
    }
    return 1;
}

static inline unsigned int RollLimited(D2SeedStrc* pSeed,int nRange)
{
    if (nRange<=0) return 0;
    if (nRange & (nRange-1))
    {
        const unsigned __int64 nSeed=pSeed->nHighSeed+0x6ac690c5i64*pSeed->nLowSeed;
        pSeed->nHighSeed=(unsigned int)(nSeed>>32);
        pSeed->nLowSeed=(unsigned int)nSeed;
        return (unsigned int)nSeed % nRange;
    }
    const unsigned __int64 nSeed=pSeed->nHighSeed+0x6ac690c5i64*pSeed->nLowSeed;
    pSeed->nLowSeed=(unsigned int)nSeed;
    pSeed->nHighSeed=(unsigned int)(nSeed>>32);
    return (unsigned int)nSeed & (nRange-1);
}

// 0x005CFD20
static int __cdecl SKILLS_RollWeaponPhysicalDamage(D2UnitStrc* pUnit)
{
    int nMinimum;
    int nMaximum;
    if (PLAYER_GetWeaponForSkill(pUnit))
    {
        if (INVENTORY_GetWieldType(pUnit,pUnit->pInventory)==2)
        {
            nMinimum=STATLIST_UnitGetStatValue(pUnit,23,0);
            nMaximum=STATLIST_UnitGetStatValue(pUnit,24,0);
        }
        else
        {
            nMinimum=STATLIST_UnitGetStatValue(pUnit,21,0);
            nMaximum=STATLIST_UnitGetStatValue(pUnit,22,0);
        }
    }
    else
    {
        nMinimum=STATLIST_UnitGetStatValue(pUnit,21,0);
        if (nMinimum<=0) nMinimum=1;
        nMaximum=STATLIST_UnitGetStatValue(pUnit,22,0);
        if (nMaximum<=1) nMaximum=2;
    }
    nMinimum<<=8;
    nMaximum<<=8;
    if (nMinimum<1) nMinimum=256;
    if (nMaximum<=nMinimum) nMaximum=nMinimum+256;
    return RollLimited(&pUnit->pSeed,nMaximum-nMinimum)+nMinimum;
}

// 0x005CFE10
int __fastcall SKILLS_SrvSt35_Vengeance(D2GameStrc* pGame,D2UnitStrc* pUnit,int nSkillId,int nSkillLevel)
{
    D2SkillsTxt* pRecord;
    if (nSkillId>=0 && nSkillId<sgptDataTables->nSkillsTxtRecordCount)
        pRecord=&sgptDataTables->pSkillsTxt[nSkillId];
    else
        pRecord=0;
    if (!pRecord) return 0;
    D2SkillStrc* pSkill=UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    D2UnitStrc* pTarget=SUNIT_GetTargetUnit(pGame,pUnit);
    if (!pTarget) return 0;
    D2DamageStrc damage;
    memset(&damage,0,sizeof(damage));
    damage.wResultFlags=SUNITDMG_GetResultFlags(pGame,pUnit,pTarget,SKILLS_GetToHitFactor(pUnit,nSkillId,nSkillLevel),0);
    if (damage.wResultFlags & 1)
    {
        damage.dwPhysDamage=SUNITDMG_ApplyDamageBonuses(pUnit,1,0,0,0,0,0,pRecord->nSrcDam);
        damage.dwHitFlags=1;
        damage.wResultFlags|=pRecord->wResultFlags;
        damage.dwHitFlags=pRecord->dwHitFlags|1;
        const int nDamage=SKILLS_RollWeaponPhysicalDamage(pUnit);
        int nPercent=sub_00646CA0_EvaluateFormula(pUnit,pRecord->dwCalc[0],nSkillId,nSkillLevel);
        if (nPercent)
        {
            const int nMastery=STATLIST_UnitGetStatValue(pUnit,329,0);
            if (nMastery) nPercent+=DATATBLS_ApplyRatio(nPercent,nMastery,100);
        }
        damage.dwFireDamage+=DATATBLS_ApplyRatio(nDamage,nPercent,100);
        nPercent=sub_00646CA0_EvaluateFormula(pUnit,pRecord->dwCalc[1],nSkillId,nSkillLevel);
        if (nPercent)
        {
            const int nMastery=STATLIST_UnitGetStatValue(pUnit,331,0);
            if (nMastery) nPercent+=DATATBLS_ApplyRatio(nPercent,nMastery,100);
        }
        damage.dwColdDamage+=DATATBLS_ApplyRatio(nDamage,nPercent,100);
        nPercent=sub_00646CA0_EvaluateFormula(pUnit,pRecord->dwCalc[2],nSkillId,nSkillLevel);
        if (nPercent)
        {
            const int nMastery=STATLIST_UnitGetStatValue(pUnit,330,0);
            if (nMastery) nPercent+=DATATBLS_ApplyRatio(nPercent,nMastery,100);
        }
        damage.dwLtngDamage+=DATATBLS_ApplyRatio(nDamage,nPercent,100);
        damage.dwColdLen+=SKILLS_GetElementalLength(pUnit,nSkillId,nSkillLevel,1);
        const int nParameter=SKILLS_GetParam1(pSkill);
        switch(nParameter)
        {
        case 0: damage.dwHitClass=32; break;
        case 1: damage.dwHitClass=48; break;
        case 2: damage.dwHitClass=64; break;
        }
        SKILLS_SetParam1(pSkill,(nParameter+1)%3);
    }
    SUNITDMG_AllocCombat(pGame,pUnit,pTarget,&damage,128);
    return 1;
}

enum D2C_SkilPal_005D0040Constants
{
    PATHTYPE_BLESSEDHAMMER = 0x0E,
};

// 0x005D0040
int __fastcall SKILLS_SrvDo073_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    int nTargetX;
    int nTargetY;
    D2UnitStrc* pMissile = 0;
    if (nMissileId > 0 && D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nTargetX, &nTargetY))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
        }

        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 0x20;
        missileParams.pOwner = pUnit;
        missileParams.pOrigin = pUnit;
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nMissile = nMissileId;

        pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    if (!pMissile)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    PATH_SetType(pPath, PATHTYPE_BLESSEDHAMMER);
    D2Common_10142(pPath, pMissile, 0);

    const int nBonus = SKILLS_GetConcentrationDamageBonus(pUnit, nSkillId);
    if (nBonus)
    {
        const int nPercentage = nBonus + 100;
        const int nMinDamage = DATATBLS_ApplyRatio(STATLIST_GetUnitBaseStat(pMissile, STAT_MAGICMINDAM, 0), nPercentage, 100);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMINDAM, nMinDamage, 0);
        const int nMaxDamage = DATATBLS_ApplyRatio(STATLIST_GetUnitBaseStat(pMissile, STAT_MAGICMAXDAM, 0), nPercentage, 100);
        STATLIST_SetUnitStat(pMissile, STAT_MAGICMAXDAM, nMaxDamage, 0);
    }

    return 1;
}

// 0x005D0180
int __fastcall SKILLS_SrvSt36_HolyShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    return INVENTORY_GetEquippedShield(pUnit->pInventory, 0) != 0;
}

// 0x005D01A0
void __fastcall SKILLS_StatRemoveCallback_Conversion(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
    SUNIT_SetAlignment(pUnit, 0, 1);
    TARGETS_RemoveUnitNode(SUNIT_GetGameFromUnit(pUnit), pUnit);

    D2StatListStrc* pConversionStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONVERSION_SAVE);
    if (!pConversionStatList)
    {
        return;
    }

    const int nConversionLevel = STATLIST_GetStatValue(pConversionStatList, STAT_CONVERSION_LEVEL, 0);
    const int nConversionMaxHp = STATLIST_GetStatValue(pConversionStatList, STAT_CONVERSION_MAXHP, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;

    int nNewHp = 1;
    if (nMaxHp)
    {
        nNewHp = DATATBLS_ApplyRatio(nConversionMaxHp, nHitpoints, nMaxHp);
    }

    STATLIST_SetUnitStat(pUnit, STAT_LEVEL, nConversionLevel, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp << 8, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nConversionMaxHp, 0);
    D2Common_10474(pUnit, pConversionStatList);
    STATLIST_FreeStatList(pConversionStatList);

    for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pUnit, STATLIST_FLAG_8); i; i = STATLIST_GetStatListFromUnitAndFlag(pUnit, STATLIST_FLAG_8))
    {
        D2Common_10474(pUnit, i);
        STATLIST_FreeStatList(i);
    }
}

// 0x005D02B0
static int __stdcall SKILLS_CanConvertTarget(D2UnitStrc* pUnit, int nSkillLevel, int bRoll, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord && !MONSTERS_GetHirelingTypeId(pTarget))
    {
        const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
        if (nType == 1 && !STATLIST_GetUnitAlignment(pTarget) && SKILLS_CanSwitchAi(pTarget, 11))
        {
            const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
            if (!bRoll || (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x005D0350
int __fastcall SKILLS_SrvDo079_Conversion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
 D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
 if (!pSkillsTxtRecord) return 0;
 if (pUnit) pUnit->dwFlags |= 0x40;
 D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
 if (!pTarget) return 0;
 int bConverted = 0;
 if (SUNITDMG_GetDamageFromUnits(pUnit, pTarget))
  bConverted = SKILLS_CanConvertTarget(pUnit, nSkillLevel, 1, pTarget, nSkillId);
 if (pSkillsTxtRecord->wAuraTargetState < 0)
 {
Drain:
  SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
  return 1;
 }
 if (pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
  goto Drain;
 if (!bConverted)
  goto Drain;
 int nFrame = pGame->dwGameFrame;
 int nExpireFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel) + nFrame;
 if (nExpireFrame <= nFrame + 1) nExpireFrame = nFrame + 1;
 D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState);
 if (!pStatList)
 {
  int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
  int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
  pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0x802, nExpireFrame, nUnitType, nUnitId);
  if (!pStatList) return 0;
  STATLIST_SetState(pStatList, pSkillsTxtRecord->wAuraTargetState);
  STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_Conversion);
  D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
  STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
 }
 D2COMMON_10476(pStatList, nExpireFrame);
 EVENT_SetEvent(pGame, pTarget, 12, nExpireFrame, 0, 0);
 SKILLS_ClearMonsterMinionOwnership(pTarget);
 SUNIT_SetAlignment(pTarget, 2, 1);
 D2GAME_UpdateSummonAI(pGame, pTarget, 0, pUnit->dwNodeIndex);
 UNITS_SetTargetUnitForDynamicUnit(pUnit, 0);
 for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pTarget, 8); i; i = STATLIST_GetStatListFromUnitAndFlag(pTarget, 8))
 {
  D2Common_10474(pTarget, i);
  STATLIST_FreeStatList(i);
 }
 int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, STAT_LEVEL, 0);
 int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
 if (nTargetLevel && nUnitLevel < nTargetLevel && !STATLIST_GetStatListFromUnitAndState(pTarget, STATE_CONVERSION_SAVE))
 {
  int nTargetId = pTarget->dwUnitId;
  int nTargetType = pTarget->dwUnitType;
  D2StatListStrc* pSave = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, nTargetType, nTargetId);
  if (pSave)
  {
   STATLIST_SetState(pSave, STATE_CONVERSION_SAVE);
   D2COMMON_10475_PostStatToStatList(pTarget, pSave, 1);
   int nHp = STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0) >> 8;
   int nMaxHp = STATLIST_GetMaxLifeFromUnit(pTarget) >> 8;
   STATLIST_SetStatIfListIsValid(pSave, STAT_CONVERSION_LEVEL, nTargetLevel, 0);
   STATLIST_SetStatIfListIsValid(pSave, STAT_CONVERSION_MAXHP, nMaxHp, 0);
   int nNewHp = DATATBLS_ApplyRatio(nHp, nUnitLevel, nTargetLevel) << 8;
   int nNewMaxHp = DATATBLS_ApplyRatio(nMaxHp, nUnitLevel, nTargetLevel) << 8;
   if (nNewMaxHp < 1) nNewMaxHp = 1;
   nNewHp = (nNewHp > 1 ? nNewHp : 1) < nNewMaxHp ? (nNewHp > 1 ? nNewHp : 1) : nNewMaxHp;
   STATLIST_SetUnitStat(pTarget, STAT_LEVEL, nUnitLevel, 0);
   STATLIST_SetUnitStat(pTarget, STAT_HITPOINTS, nNewHp, 0);
   STATLIST_SetUnitStat(pTarget, STAT_MAXHP, nNewMaxHp, 0);
  }
 }
 return 1;
}

static inline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005D0670
int __fastcall SKILLS_SrvDo080_FistOfTheHeavens(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
        return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
        return 0;
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pTarget);
    missileParams.nY = CLIENTS_GetUnitY(pTarget);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
        return 0;
    MISSILE_SetTargetX(pMissile, !pTarget ? 6 : pTarget->dwUnitType);
    MISSILE_SetTargetY(pMissile, !pTarget ? -1 : pTarget->dwUnitId);
    if (pSkillsTxt->wSrvOverlay >= 0 && pSkillsTxt->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
        UNITS_SetOverlay(pTarget, pSkillsTxt->wSrvOverlay, 0);
    return 1;
}

// 0x005D0770
void __fastcall SKILLS_CurseStateCallback_HolyFreeze(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);

        if (!SUNIT_IsDead(pUnit))
        {
            STATES_ToggleState(pUnit, STATE_SHATTER, 0);
        }

        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkilPal.cpp", 1558);
    }
}

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x005D07C0
int __fastcall SKILLS_AuraCallback_HolyFreeze(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pAuraCallback->pGame;
    D2UnitStrc* pOwner = pAuraCallback->pOwner;
    D2DamageAuraParamStrc* pArgs = (D2DamageAuraParamStrc*)pAuraCallback->pArgs;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }
        if (pMonStatsTxtRecord->nColdEffect[pGame->nDifficulty] >= 0)
        {
            return 0;
        }
    }

    if (pArgs->nPassiveState)
    {
        D2BasicAuraParamStrc args;
        memset(&args, 0, sizeof(args));
        args.nAuraState = pArgs->nAuraState;
        args.nSkillId = pArgs->nSkillId;
        args.nSkillLevel = pArgs->nSkillLevel;
        args.nDuration = pArgs->nDuration;
        int i = 0;
        do
        {
            args.nAuraStat[i] = pArgs->nAuraStat[i];
            args.nAuraStatCalcValue[i] = pArgs->nAuraStatCalcValue[i];
            ++i;
        } while (i < 6);

        D2AuraCallbackStrc auraCallback;
        auraCallback.pOwner = pOwner;
        auraCallback.pArgs = &args;
        auraCallback.pGame = pGame;
        SKILLS_AuraCallback_BasicAura(&auraCallback, pUnit);
    }

    D2DamageStrc* pDamage = pArgs->pDamage;
    if (pDamage)
    {
        D2DamageStrc damage = *pDamage;
        SUNITDMG_ExecuteEvents(pGame, pOwner, pUnit, 1, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pOwner, pUnit, &damage);
    }

    const int nRoll = ITEMS_RollRandomNumber(&pUnit->pSeed) % 100;
    if (nRoll < 20)
    {
        STATES_ToggleState(pUnit, 0x6B, 1);
        return 1;
    }

    STATES_ToggleState(pUnit, 0x6B, 0);
    return 1;
}

// 0x005D0920
int __fastcall SKILLS_SrvDo081_HolyFreeze(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nManaCost = SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nFrame = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel) - pGame->dwGameFrame + 1;

    D2BasicAuraParamStrc args1;
    memset(&args1, 0, sizeof(args1));
    args1.nSkillId = nSkillId;
    args1.nSkillLevel = nSkillLevel;
    args1.nDuration = nFrame;
    args1.nAuraState = pSkillsTxtRecord->nAuraState;
    args1.pStateRemoveCallback = SKILLS_CurseStateCallback_HolyFreeze;

    for (int i = 0; i < 5; ++i)
    {
        args1.nAuraStat[i] = pSkillsTxtRecord->nPassiveStat[i];
        if (GAME_GetUnitTypeOrInvalid(pUnit) != UNIT_PLAYER || nMana >= nManaCost)
        {
            args1.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
    }

    SKILLS_ApplyAuraToSelf(pGame, pUnit, SKILLS_AuraCallback_BasicAura, &args1);

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        return 1;
    }

    D2DamageAuraParamStrc args2;
    memset(&args2, 0, sizeof(args2));
    args2.nSkillId = nSkillId;
    args2.nSkillLevel = nSkillLevel;
    args2.nDuration = nFrame;
    args2.nAuraState = pSkillsTxtRecord->wAuraTargetState;

    if (pSkillsTxtRecord->wAuraTargetState >= 0 && pSkillsTxtRecord->wAuraTargetState < sgptDataTables->nStatesTxtRecordCount)
    {
        for (int i = 0; i < 6; ++i)
        {
            args2.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
            if (nMana >= nManaCost)
            {
                args2.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
                if (args2.nAuraStatCalcValue[i])
                {
                    args2.nPassiveState = 1;
                }
            }
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    if (D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel))
    {
        damage.dwHitClass |= 0xD;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags | 0x20;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        args2.pDamage = &damage;
    }

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);

    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_HolyFreeze, &args2, 0, ".\\SKILLS\\SkilPal.cpp", 1722);

    if (nManaCost > 0 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (args2.nAffectedUnits > 0)
        {
            STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 1);
            D2GAME_SKILLMANA_AuraConsume(pUnit, nManaCost);
        }
        else
        {
            STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
        }
    }

    return 1;
}

// 0x005D0C40
int __fastcall SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillId, int nSkillLevel, int bSkipChanceRoll)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !pCorpse || !SKILLS_CanUnitCorpseBeSelected(pCorpse))
    {
        return 0;
    }

    if (!bSkipChanceRoll)
    {
        const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (sub_0045C390_SeedRollLimited(&pUnit->pSeed, 100) >= nChance)
        {
            return 0;
        }
    }

    {
        const int nLifeBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) << 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        int nNewHp = nLifeBonus + STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
        if (nMaxLife < nNewHp)
        {
            nNewHp = nMaxLife;
        }
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

        const int nManaBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel) << 8;
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
        int nNewMana = nManaBonus + STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
        if (nMaxMana < nNewMana)
        {
            nNewMana = nMaxMana;
        }
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewMana, 0);

        STATES_ToggleState(pCorpse, STATE_REDEEMED, 1);
        pCorpse->dwFlags &= ~(UNITFLAG_TARGETABLE | UNITFLAG_CANBEATTACKED);
        return 1;
    }
}

static inline int SKILLS_ApplyRedemptionEffect_Inline(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillId, int nSkillLevel, int bSkipChanceRoll)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!pCorpse)
    {
        return 0;
    }

    if (!SKILLS_CanUnitCorpseBeSelected(pCorpse))
    {
        return 0;
    }

    if (!bSkipChanceRoll)
    {
        const int nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (sub_0045C390_SeedRollLimited(&pUnit->pSeed, 100) >= nChance)
        {
            return 0;
        }
    }

    {
        const int nLifeBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) << 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        int nNewHp = nLifeBonus + STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
        if (nMaxLife < nNewHp)
        {
            nNewHp = nMaxLife;
        }
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

        const int nManaBonus = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel) << 8;
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
        int nNewMana = nManaBonus + STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
        if (nMaxMana < nNewMana)
        {
            nNewMana = nMaxMana;
        }
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewMana, 0);

        STATES_ToggleState(pCorpse, STATE_REDEEMED, 1);
        pCorpse->dwFlags &= ~(UNITFLAG_TARGETABLE | UNITFLAG_CANBEATTACKED);
        return 1;
    }
}

// 0x005D0D70
int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2RedemptionAuraCallbackArgStrc* pArgs = (D2RedemptionAuraCallbackArgStrc*)pAuraCallback->pArgs;

    D2UnitStrc* pOwner = pAuraCallback->pOwner;
    const int nSkillLevel = pArgs->nSkillLevel;
    const int nSkillId = pArgs->nSkillId;

    const int nResult = SKILLS_ApplyRedemptionEffect_Inline(pAuraCallback->pGame, pOwner, pUnit, nSkillId, nSkillLevel, 0);
    if (nResult)
    {
        ++pArgs->nCounter;
    }

    return nResult;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordChecked(int nSkillId)
{
    if (!(nSkillId >= 0))
        return 0;
    if (!(nSkillId < sgptDataTables->nSkillsTxtRecordCount))
        return 0;
    return &sgptDataTables->pSkillsTxt[nSkillId];
}

// 0x005D0E90
int __fastcall SKILLS_SrvDo082_Redemption(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordChecked(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nManaCost = SKILLS_GetManaCosts(nSkillId, nSkillLevel);
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nDuration = SKILL_ComputePeriodicRate(pGame, pUnit, pSkillsTxtRecord, nSkillId, nSkillLevel) - pGame->dwGameFrame + 1;

    D2BasicAuraParamStrc args;
    memset(&args, 0, sizeof(args));
    args.nSkillLevel = nSkillLevel;
    args.nDuration = nDuration;
    args.nSkillId = nSkillId;
    args.nAuraState = pSkillsTxtRecord->nAuraState;

    for (int i = 0; i < 5; ++i)
    {
        const int nStat = pSkillsTxtRecord->nPassiveStat[i];
        args.nAuraStat[i] = nStat;
        if (nStat >= 0)
        {
            if (GAME_GetUnitTypeOrInvalid(pUnit) != UNIT_PLAYER || nMana >= nManaCost)
            {
                args.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
            }
        }
    }

    SKILLS_ApplyAuraToSelf(pGame, pUnit, SKILLS_AuraCallback_BasicAura, &args);

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        return 1;
    }

    D2RedemptionAuraParamStrc redemptionArgs;
    redemptionArgs.nSkillId = nSkillId;
    redemptionArgs.nSkillLevel = nSkillLevel;
    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_Redemption, &redemptionArgs, 1, gszSkillPalSourceFile, 0x753);

    if (nManaCost > 0)
    {
        if (pUnit && (!pUnit ? 6 : pUnit->dwUnitType) == UNIT_PLAYER)
        {
            if (redemptionArgs.nRedeemed > 0)
            {
                STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 1);
                D2GAME_SKILLMANA_AuraConsume(pUnit, nManaCost);
            }
            else
            {
                STATES_ToggleState(pUnit, STATE_NOMANAREGEN, 0);
            }
        }
    }

    return 1;
}

