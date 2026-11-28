#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2MonModes.h"

#include "D2Primitives.h"
#include "D2LevelTxt.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
#include "D2CommonApi.h"
#include "FogApi.h"
#include "D2CommonApi2.h"
#define MONTYPEFLAG_UNIQUE 8
#define EVENTTYPE_REMOVESTATE 0x0C

#define UNITFLAG_DOUPDATE 1
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
struct D2ModeChangeStrc;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2ServerCallbacks;
struct D2StatesTxt;
struct D2GSPacketSrvAA;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

#include "D2GameFuncs.h"
#include "D2CommonApi3.h"
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

typedef void (__fastcall* LevelCallback)(unsigned int, int);

struct D2ServerCallbacks { char unk_00[44]; LevelCallback levelUp; };

extern D2ServerCallbacks* gpServerCallbacks; // 0x00883D50
void __fastcall SUNITPROXY_InitializeNpcEventChain(D2GameStrc*,D2UnitStrc*,int); // 0x00536850
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
int __stdcall UNITS_GetPlayerName(D2UnitStrc*,int,int); // 0x00622150
static void sub_00570A50_SpendStatPointsOnStrength(D2UnitStrc* pUnit, int nValue);
static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue);

#pragma pack(push, 1)

#pragma pack(pop)

extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern const unsigned int gdwInvBitMasks[]; // 0x006CE2E8

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x00570590
D2StatListStrc* __fastcall SKILLS_ApplyTimedState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nState, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    const int nAuraLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const unsigned int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nAuraLength + pGame->dwGameFrame, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }
    STATLIST_SetState(pStatList, nState);
    STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    STATES_ToggleState(pTarget, nState, 1);
    EVENT_SetEvent(pGame, pTarget, 0xC, nAuraLength + pGame->dwGameFrame, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    return pStatList;
}

// 0x005706A0
static void __stdcall sub_005706A0_UseActEntry(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }
    if (nAct >= gnActCount)
    {
        nAct = 0;
    }
    SUNITDMG_SetExperienceForTargetLevel(pGame, pUnit, gnStartingActTargetLevels[nAct]);
}

// 0x005706D0
void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }

    if (!pPlayer)
    {
        return;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }

    STATLIST_SetUnitStat(pPlayer, STAT_STRENGTH, pCharStatsTxtRecord->nStr, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_ENERGY, pCharStatsTxtRecord->nInt, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_DEXTERITY, pCharStatsTxtRecord->nDex, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_VITALITY, pCharStatsTxtRecord->nVit, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_TOHIT, 0, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_TOBLOCK, 0, 0);
    const int nLife = (pCharStatsTxtRecord->nVit + pCharStatsTxtRecord->nLifeAdd) << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXHP, nLife, 0);
    const int nMana = pCharStatsTxtRecord->nInt << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_MANA, nMana, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXMANA, nMana, 0);
    const int nStamina = pCharStatsTxtRecord->nStamina << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, nStamina, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXSTAMINA, nStamina, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_LEVEL, 1, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_NEXTEXP, DATATBLS_GetLevelThreshold(!pPlayer ? -1 : pPlayer->dwClassId, 1), 0);
    STATLIST_SetUnitStat(pPlayer, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_OTHER_ANIMRATE, 100, 0);

    if (nAct > 0)
    {
        sub_005706A0_UseActEntry(pGame, pPlayer, nAct);
    }
}

extern const int gnStartingActTargetLevels[5] = { 1, 15, 20, 26, 32 }; // 0x006E1520

extern int gnActCount = 5; // 0x007326B4
struct D2MonStatsTxt;

// 0x00570870
static inline void sub_00570870_ForwardToLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_IterateLivingPlayers(pGame, (SUNIT_IterateFn)PLAYERSTATS_OnPlayerLeveledUp, pUnit);
}

// 0x00570880
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* game,D2UnitStrc* unit)
{
 int classId;
 if(!unit) classId=-1; else classId=unit->dwClassId;
 int previousLevel=STATLIST_GetUnitBaseStat(unit,STAT_LEVEL,0);
 int level=DATATBLS_GetCurrentLevelFromExp(classId,STATLIST_UnitGetStatValue(unit,STAT_EXPERIENCE,0));
 STATLIST_SetUnitStat(unit,STAT_LEVEL,level,0);
 STATLIST_SetUnitStat(unit,STAT_NEXTEXP,DATATBLS_GetLevelThreshold(classId,level),0);
 int gained=level-previousLevel;
 if(gained>0) {
  D2CharStatsTxt* record=(classId>=0 && classId<sgptDataTables->nCharStatsTxtRecordCount)?&sgptDataTables->pCharStatsTxt[classId]:0;
  int life=STATLIST_GetUnitBaseStat(unit,STAT_MAXHP,0)+((record->lifePerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXHP,life,0);
  int maxLife=STATLIST_GetMaxLifeFromUnit(unit);
  if(STATLIST_UnitGetStatValue(unit,STAT_HITPOINTS,0)>0) STATLIST_SetUnitStat(unit,STAT_HITPOINTS,maxLife,0);
  int mana=STATLIST_GetUnitBaseStat(unit,STAT_MAXMANA,0)+((record->manaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXMANA,mana,0);
  int maxMana=STATLIST_GetMaxManaFromUnit(unit);
  STATLIST_SetUnitStat(unit,STAT_MANA,maxMana,0);
  int stamina=STATLIST_GetUnitBaseStat(unit,STAT_MAXSTAMINA,0)+((record->staminaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXSTAMINA,stamina,0);
  int maxStamina=STATLIST_GetMaxStaminaFromUnit(unit);
  STATLIST_SetUnitStat(unit,STAT_STAMINA,maxStamina,0);
  STATLIST_AddUnitStat(unit,STAT_STATPTS,record->statPerLevel*gained,0);
  STATLIST_AddUnitStat(unit,STAT_SKILLPTS,gained,0);
  SUNITPROXY_InitializeNpcEventChain(game,unit,level);
  SUNIT_AttachSound(unit,2,unit);
   sub_00570870_ForwardToLivingPlayers(game,unit);
  D2GAME_UpdatePlayerVitals(game,unit);
  D2GAME_UpdatePlayerItems(game,unit,1);
  if(gpServerCallbacks && gpServerCallbacks->levelUp) gpServerCallbacks->levelUp(game->nGameId,UNITS_GetPlayerName(unit,classId,level));
 }
}

// 0x00570E10
int __cdecl sub_00570E10_GetStateMaskCount()
{
    return (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
}

// 0x00570A50
static void sub_00570A50_SpendStatPointsOnStrength(D2UnitStrc* pUnit, int nValue)
{
    if (nValue)
    {
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nValue, 0);
        STATLIST_AddUnitStat(pUnit, STAT_STRENGTH, nValue, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
}


// 0x00570A80
static void sub_00570A80_AddEnergyPoints(D2UnitStrc* pUnit, int nPoints)
{
    if (nPoints && pUnit)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nPoints, 0);
            STATLIST_AddUnitStat(pUnit, STAT_ENERGY, nPoints, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, STAT_MANA, pCharStatsTxtRecord->nManaPerMagic * nPoints << 6, 0);
            }
            STATLIST_AddUnitStat(pUnit, STAT_MAXMANA, pCharStatsTxtRecord->nManaPerMagic * nPoints << 6, 0);
            const int nMaxMana = STATLIST_UnitGetStatValue(pUnit, STAT_MAXMANA, 0);
            if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) > nMaxMana)
            {
                STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
            }
        }
    }
}

// 0x00570B60
static void sub_00570B60_AddVitalityPoints(D2UnitStrc* pUnit, int nPoints)
{
    if (nPoints && pUnit)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nPoints, 0);
            STATLIST_AddUnitStat(pUnit, STAT_VITALITY, nPoints, 0);
            STATLIST_AddUnitStat(pUnit, STAT_MAXHP, pCharStatsTxtRecord->nLifePerVitality * nPoints << 6, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, STAT_HITPOINTS, pCharStatsTxtRecord->nLifePerVitality * nPoints << 6, 0);
            }
            const int nMaxHp = STATLIST_UnitGetStatValue(pUnit, STAT_MAXHP, 0);
            if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) > nMaxHp)
            {
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
            }
            STATLIST_AddUnitStat(pUnit, STAT_MAXSTAMINA, pCharStatsTxtRecord->nStaminaPerVitality * nPoints << 6, 0);
            if (nPoints > 0)
            {
                STATLIST_AddUnitStat(pUnit, STAT_STAMINA, pCharStatsTxtRecord->nStaminaPerVitality * nPoints << 6, 0);
            }
            const int nMaxStamina = STATLIST_UnitGetStatValue(pUnit, STAT_MAXSTAMINA, 0);
            if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) > nMaxStamina)
            {
                STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
            }
        }
    }
}

// 0x00570C80
void __fastcall sub_00570C80_PLAYERSTATS_ResetToBaseStats(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }
    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pUnit->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }
    sub_00570A50_SpendStatPointsOnStrength(pUnit, pCharStatsTxtRecord->nStr - STATLIST_GetUnitBaseStat(pUnit, STAT_STRENGTH, 0));
    sub_00570A80_AddEnergyPoints(pUnit, pCharStatsTxtRecord->nInt - STATLIST_GetUnitBaseStat(pUnit, STAT_ENERGY, 0));
    sub_00570B30_SpendStatPointsOnDexterity(pUnit, pCharStatsTxtRecord->nDex - STATLIST_GetUnitBaseStat(pUnit, STAT_DEXTERITY, 0));
    sub_00570B60_AddVitalityPoints(pUnit, pCharStatsTxtRecord->nVit - STATLIST_GetUnitBaseStat(pUnit, STAT_VITALITY, 0));
}

// 0x00570D60
int __fastcall PLAYERSTATS_SpendStatPoint(D2UnitStrc* pUnit, int nStatId)
{
    if (!STATLIST_UnitGetStatValue(pUnit, STAT_STATPTS, 0))
    {
        return 0;
    }
    switch (nStatId)
    {
    case 0:
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -1, 0);
        STATLIST_AddUnitStat(pUnit, STAT_STRENGTH, 1, 0);
        UNITROOM_RefreshUnit(pUnit);
        return 1;
    case 1:
        sub_00570A80_AddEnergyPoints(pUnit, 1);
        return 1;
    case 2:
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -1, 0);
        STATLIST_AddUnitStat(pUnit, STAT_DEXTERITY, 1, 0);
        UNITROOM_RefreshUnit(pUnit);
        return 1;
    case 3:
        sub_00570B60_AddVitalityPoints(pUnit, 1);
        return 1;
    }
    return 0;
}

// 0x00570B30
static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue)
{
    if (nValue)
    {
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, -nValue, 0);
        STATLIST_AddUnitStat(pUnit, STAT_DEXTERITY, nValue, 0);
        UNITROOM_RefreshUnit(pUnit);
    }
}

static inline D2StatesTxt* SKILLS_GetStatesTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nStatesTxtRecordCount) return 0; return &sgptDataTables->pStatesTxt[id]; }

static inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nItemStatCostTxtRecordCount) return 0; return &sgptDataTables->pItemStatCostTxt[id]; }

static inline int sub_GetUnitTypeOrInvalid(D2UnitStrc* pUnit) { if (!pUnit) return UNIT_INVALID; return pUnit->dwUnitType; }
