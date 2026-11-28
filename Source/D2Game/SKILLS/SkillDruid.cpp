#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2Constants.h"
#include "D2UnitData.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"
#include "D2LanguageNames.h"
#include "D2CommonApi.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x007419A4

#define STATEMASK_REMHIT 6

struct D2GameStrc;

struct D2UnitStrc;

#define UNITFLAG_SKSRVDOFUNC 0x40

#define AISPECIALSTATE_NONE 0

#define SKILLDRUID_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SKILLDRUID_MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2SummonArgStrc;

struct D2SkillsTxt;

union D2SeedStrc;

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620

#include "D2GameFuncs.h"
#include "D2CommonApi3.h"


void __fastcall D2GAME_SetSummonPassiveStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0


void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540


void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0


extern "C" void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0


extern "C" void __stdcall STATLIST_SetListExpireFrame(D2StatListStrc* pStatList, int nValue); // 0x006260B0

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30


int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760


typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nInitSeed);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390


enum
{
    EVENTTYPE_ACTIVESTATE = 5,
    EVENTTYPE_REMOVESTATE = 12,
};


void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0


extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20


D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740


void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0


unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30


#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

struct D2StaticPathStrc;

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0


int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0


void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nFlags); // 0x0057DBF0

enum D2C_Z09SkillConstants
{
    UNITFLAG_TARGETFLAGS = 0x0E,
    EVENTTYPE_ENDANIM = 1,
    AISPECIALSTATE_MOUNTING_UNIT = 0x10,
    PATHTYPE_BLESSEDHAMMER = 0x0E,
    PATHTYPE_KNOCKBACK_SERVER = 0x08,
    PATHTYPE_LEAP = 0x09,
    PATHTYPE_MON_OTHER_2 = 0x65,
};

















int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180











int __fastcall D2GAME_RollElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0


int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20

#define HIT_SUCCESS 1

#define HIT_FLAG 2

#define SOURCE_DAMAGE 128


enum D2C_F39Constants
{
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_WILLDIE = 2,
    SKILLSFLAGINDEX_01 = 1,
    UNITFLAG_NOTC = 0x20000,
    STATLIST_FLAG_8 = 8,
};

struct D2MonsterRegionStrc;


typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);


D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0




int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0

















void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150






int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910























int __fastcall SUNIT_TeleportUnit(Game*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0

enum { UNIT_FLAGS = 0xE };

struct D2MissilesTxt;

struct Monster;

enum D2C_Y09ImpInfernoConstants
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_AITHINK = 2,
};


struct Game
{
    unsigned char pad[28];
    void* pool;
};



struct D2PlayerDataStrc;

struct D2AiCmdStrc;

struct D2MonStatsTxt;

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380


void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190


int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc*, int); // 0x00472210

D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc*); // 0x0058EE80

D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc*, D2UnitStrc*, unsigned int*, int*); // 0x005DDC30


int __stdcall PATH_GetFinalTargetX(D2DynamicPathStrc*); // 0x00648A20

int __stdcall PATH_GetFinalTargetY(D2DynamicPathStrc*); // 0x00648A30

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline int SKILLS_IsValidPetType(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

// 0x005C6910
int __fastcall SKILLS_SrvDo114_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType((signed char)pSkillsTxtRecord->nPetType))
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
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
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

    pPet->dwFlags &= 0xFFFFFFFBu;
    STATLIST_SetUnitStat(pPet, STAT_HPREGEN, 0, 0);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C6A80
int __fastcall SKILLS_SrvDo115_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType((signed char)pSkillsTxtRecord->nPetType))
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
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.nMonMode = 8;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_UpdateSummonAI(pGame, pPet, 0, pUnit->dwNodeIndex);
    STATES_ToggleState(pPet, STATE_VINE_BEAST, 1);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    STATLIST_SetUnitStat(pPet, STAT_LEVEL, nLevel, 0);
    D2GAME_SetSummonPassiveStats(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C6BF0
int __fastcall SKILLS_GetConvertedMode(D2UnitStrc* pUnit, int nMode)
{
    int nUnitType;
    int nClassId;
    int nNewMode = nMode;

    int nTypeValue;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
        if (nTypeValue == 0)
        {
            return nMode;
        }
    }
    else
    {
        nTypeValue = 6;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nNewMode, gszSkillDruidSourceFile, 156);
    return nNewMode;
}

// 0x005C6C50
void __fastcall SKILLS_RemoveStateAndRestoreSkillMode(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList)
{
    SKILLS_RemoveStatesInGroup(pUnit, nStateId, 1);

    if (!pStatList)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (!pSkill)
    {
        return;
    }

    SKILLS_SetSkillMode(pSkill, SKILLS_GetConvertedMode(pUnit, 10));
    STATES_ToggleState(pUnit, nStateId, 0);
}

// 0x005C6CB0
void __fastcall SKILLS_RemoveAllStatesInGroup(D2UnitStrc* pUnit, int nState)
{
    SKILLS_RemoveStatesInGroup(pUnit, nState, 1);
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005C6CC0
void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pStatList)
    {
        return;
    }

    if (!pSkillsTxtRecord)
    {
        pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    }

    if (!pSkillsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        const int nStatId = pSkillsTxtRecord->wAuraStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        }

        if (pItemStatCostTxtRecord)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStatValue(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_ATTACKRATE)
                {
                    STATLIST_SetStat(pStatList, STAT_OTHER_ANIMRATE, nValue, 0);
                }
            }
        }
    }

    UnitUpdateAnimRateAndVel(pUnit, gszSkillDruidSourceFile, 248);
}

// 0x005C6DC0
void __fastcall SKILLS_ApplyPassiveStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pStatList)
    {
        return;
    }

    if (!pSkillsTxtRecord)
    {
        pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    }

    if (!pSkillsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        const int nStatId = pSkillsTxtRecord->nPassiveStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        }

        if (pItemStatCostTxtRecord)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStatValue(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_ATTACKRATE)
                {
                    STATLIST_SetStat(pStatList, STAT_OTHER_ANIMRATE, nValue, 0);
                }
            }
        }
    }

    UnitUpdateAnimRateAndVel(pUnit, gszSkillDruidSourceFile, 300);
}

// 0x005C6EC0
int __fastcall SKILLS_SrvDo116_Wearwolf_Wearbear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (SKILLS_RemoveStatesInGroup(pUnit, pSkillsTxtRecord->nAuraState, 1))
    {
        SKILLS_ApplySkillDelay(pGame, pUnit, nSkillId, nSkillLevel);
        return 0;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, pGame->dwGameFrame + nLength, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
    STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRestoreSkillMode);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, pGame->dwGameFrame + nLength, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (pSkill)
    {
        SKILLS_SetSkillMode(pSkill, 10);
    }

    return 1;
}

// 0x005C7040
int __fastcall SKILLS_CreateMissileSpread(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int bCreateFirstMissile)
{
    if (bCreateFirstMissile)
    {
        SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        --nSubMissiles;
        if (nSubMissiles <= 0)
        {
            return 1;
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 33;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 1;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
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

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

static inline int SKILLS_CreateSubMissilesInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int bFirstAtOffset)
{
    if (bFirstAtOffset)
    {
        SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        --nSubMissiles;
        if (nSubMissiles <= 0)
        {
            return 1;
        }
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = UNITS_GetUnitXPositionInline(pUnit);
    missileParams.nY = UNITS_GetUnitYPositionInline(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 1;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005C7160
int __fastcall SKILLS_SrvDo117_Firestorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nParam <= 0)
    {
        return 0;
    }

    return SKILLS_CreateSubMissilesInline(pGame, pUnit, nParam, nMissileId, nSkillId, nSkillLevel, 1);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005C72F0
int __fastcall SKILLS_SrvDo118_Twister_Tornado(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nParam <= 0)
    {
        return 0;
    }

    return SKILLS_CreateMissileSpread(pGame, pUnit, nParam, nMissileId, nSkillId, nSkillLevel, 0);
}

inline int SKILLS_IsValidPetType_Inline(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

// 0x005C7390
int __fastcall SKILLS_SrvDo119_DruidSummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType_Inline((signed char)pSkillsTxtRecord->nPetType))
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
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
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

    D2GAME_UpdateSummonAI(pGame, pPet, 0, pUnit->dwNodeIndex);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C7520
int __fastcall SKILLS_SummonDruidPetAtOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType((signed char)pSkillsTxtRecord->nPetType))
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
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
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

    D2GAME_UpdateSummonAI(pGame, pPet, 0, pUnit->dwNodeIndex);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C7690
int __fastcall SKILLS_SrvSt56_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        SKILLS_SetParam1(pSkill, 1);
    }
    else
    {
        SKILLS_SetParam1(pSkill, 0);
    }

    return 1;
}

// 0x005C77C0
int __fastcall SKILLS_SrvDo120_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 0x2AF) != nSkillId)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    if (!SKILLS_GetParam1(pSkill))
    {
        return 1;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const int nExpireFrame = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 1;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    STATLIST_SetListExpireFrame(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, 0xC, nExpireFrame, 0, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    const int nValue = SKILLDRUID_MIN(nParam, STATLIST_GetStatValue(pStatList, STAT_SKILL_FRENZY, 0) + 1);

    STATLIST_SetStatIfListIsValid(pStatList, STAT_SKILL_FRENZY, nValue, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nValue);
    return 1;
}

// 0x005C79E0
int __fastcall SKILLS_SrvSt57_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 753) != nSkillId)
    {
        return 0;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }
    SKILLS_SetParam1(pSkill, 0);
    D2DamageStrc damage;
    D2DamageStrc* pDamage = &damage;
    pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (!(pDamage->wResultFlags & 1))
    {
        return 0;
    }
    SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType > 0)
    {
        SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }
    SKILLS_SetParam1(pSkill, 1);
    return 1;
}

// 0x005C7B10
int __stdcall SKILLS_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState > sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nExpireFrame = pGame->dwGameFrame + nTimeout;
    if (STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }

    const unsigned int nUnitGUID = !pTarget ? -1 : pTarget->dwUnitId;
    const int nUnitType = !pTarget ? 6 : pTarget->dwUnitType;

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetState(pStatList, pSkillsTxtRecord->wAuraTargetState);
    STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
    STATLIST_SetListExpireFrame(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pTarget, 0xC, nExpireFrame, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    return 1;
}

// 0x005C7C20
static void __stdcall SKILLS_ApplyRabiesDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nLength, int nSkillLevel)
{
    if (nLength < 10)
    {
        nLength = 10;
    }

    D2DamageStrc damage = {};
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
    }

    SKILLS_SetElementalDurationFromSkill(pUnit, &damage, nLength, nSkillId);
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
}

// 0x005C7CE0
static void __stdcall SKILLS_CreateTargetAuraMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimeout, int nSkillLevel, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x8000;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pTarget;
    missileParams.pOrigin = pTarget;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nRange = nTimeout;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return;
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    MISSILE_SetTargetX(pMissile, nUnitType);
    MISSILE_SetTargetY(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
}

// 0x005C7DB0
int __fastcall SKILLS_ApplyTargetAuraAndMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel)
{
    if (nSkillLevel <= 0)
    {
        return 0;
    }

    if (SKILLS_ApplyAuraTargetState(pGame, pUnit, pTarget, nTimeout, nSkillId, nSkillLevel))
    {
        SKILLS_CreateTargetAuraMissile(pGame, pUnit, nTimeout, nSkillLevel, pTarget, nSkillId);
    }
    return 1;
}

// 0x005C8AD0
int __fastcall SKILLS_SrvDo121_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 967) != nSkillId || !SKILLS_GetParam1(pSkill))
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    SKILLS_AllocTransformSkillCombat(pGame, pUnit, nSkillLevel);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    SKILLS_ApplyTargetAuraAndMissile(pGame, pUnit, pTarget, nLength, nSkillId, nSkillLevel);
    SKILLS_ApplyRabiesDamage(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nLength, nSkillLevel);
    return 1;
}

// 0x005C8BC0
extern "C" int __fastcall SKILLS_GetSkillsTxtParam7(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[6];
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
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

static inline D2SkillsTxt* GetRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline int DeleteEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2GAME_EVENTS_Delete(pGame, pUnit, 5, nSkillId);
    return 0;
}

inline int m12_Abs(int n)
{
    return n < 0 ? -n : n;
}

// 0x005C7E00
int __fastcall SKILLS_SrvSt58_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord) return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget) return 0;
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & HIT_SUCCESS)
    {
        damage.dwHitFlags |= HIT_FLAG;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, SOURCE_DAMAGE);
    }
    return 1;
}

// 0x005C7F10
int __fastcall SKILLS_SrvDo122_Hunger(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= 2;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
        const int nDamagePct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage += DATATBLS_ApplyRatio(damage.dwPhysDamage, nDamagePct, 100);
        const int nLifeLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        const int nManaLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        damage.dwLifeLeech += nLifeLeech;
        damage.dwManaLeech += nManaLeech;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    return 1;
}

// 0x005C8080
int __fastcall SKILLS_SrvDo123_Volcano(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (!SKILLS_IsMissileTargetPositionClear(pGame, pUnit, nMissileId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const unsigned char nRand = (unsigned char)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 256);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nSkill = nSkillId;
    missileParams.nMissile = nMissileId;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nRand);
    SUNITMSG_QueueSkillEvent(pUnit, 0, nSkillId, nSkillLevel, nX, nY, nRand);
    return 1;
}

// 0x005C8190
int __fastcall SKILLS_SrvDo124_Armageddon_Hurricane(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillDruid.cpp", 1163) != nSkillId)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nParam = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 0x10000);
    int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (nDuration < 1)
    {
        nDuration = 1;
    }

    const int nExpireFrame = pGame->dwGameFrame + nDuration;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const unsigned int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    D2COMMON_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    const int nFrame = SKILLDESC_GetSkillParamFour(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nFrame, nSkillId, nSkillLevel);
    SKILLS_SetParam1(pSkill, nParam);
    return 1;
}

// 0x005C8380
int __fastcall SKILLS_SrvDo145_PeriodicAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || nSkillLevel <= 0 || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        return 0;
    }

    if (!STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 0);
            D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
            return 0;
        }
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    if (nRange <= 0)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        return 0;
    }

    const int nFrame = SKILLDESC_GetSkillParamFour(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nFrame, nSkillId, nSkillLevel);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollPhysicalDamage(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    SKILLS_ApplyAreaDamage(pGame, pUnit, 0, 0, nRange, &damage, pSkillsTxtRecord->dwAuraFilter);
    return 1;
}

static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x005C8520
int __fastcall SKILLS_SrvDo146_PeriodicRandomMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pRecord = GetRecord(nSkillId);
    if (!pRecord || nSkillLevel <= 0 || pRecord->nAuraState < 0 || pRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!STATES_CheckState(pUnit, pRecord->nAuraState))
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!(pRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            D2StatListStrc* pList = STATLIST_GetStatListFromUnitAndState(pUnit, pRecord->nAuraState);
            if (pList)
            {
                D2Common_10474(pUnit, pList);
                STATLIST_FreeStatList(pList);
            }
            STATES_ToggleState(pUnit, pRecord->nAuraState, 0);
            return DeleteEvent(pGame, pUnit, nSkillId);
        }
    }
    int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSkill || !pSeed) return DeleteEvent(pGame, pUnit, nSkillId);
    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    if (nRange <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    int nFrame = SKILLDESC_GetSkillParamFour(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete(pGame, pUnit, 5, nSkillId);
    EVENT_SetEvent(pGame, pUnit, 5, nFrame, nSkillId, nSkillLevel);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
    SEED_InitLowSeed(pSeed, SKILLS_GetParam1(pSkill));
    SKILLS_SetParam1(pSkill, SEED_RollLimitedRandomNumber(pSeed, 1000000));
    CLIENTS_GetUnitX(pUnit);
    CLIENTS_GetUnitY(pUnit);
    int nX, nY;
    int i = 0;
    for (; i < 5; ++i)
    {
        int nMax = 2 * nRange + 1;
        nX = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nX += CLIENTS_GetUnitX(pUnit);
        nY = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nY += CLIENTS_GetUnitY(pUnit);
        if (D2Common_11026(nX, nY, pUnit, 0x805))
        {
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
            if (pRoom && !COLLISION_CheckMask(pRoom, nX, nY, 1)) break;
        }
    }
    if (i >= 5) return 0;
    D2GAME_CreateMissile(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, nX, nY);
    SUNITMSG_QueueSkillEvent(pUnit, 0, nSkillId, nSkillLevel, nX, nY, 0);
    return 1;
}

// 0x005C8780
static int SKILLS_SubtractAbsorbedDamage(int* pDamage, int nValue)
{
    if (nValue <= *pDamage)
    {
        *pDamage -= nValue;
        return 0;
    }

    nValue -= *pDamage;
    *pDamage = 0;
    return nValue;
}

// 0x005C87A0
int __fastcall SKILLS_EventFunc25_AbsorbElementalDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    if (!pDamage)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        return 0;
    }

    const int nStat1 = pSkillsTxtRecord->wAuraStat[1];
    if (nStat1 < 0 || nStat1 >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    const int nValue1 = STATLIST_GetStatValue(pStatList, nStat1, 0);
    if (nValue1 <= 0)
    {
        return 0;
    }

    const int nStat0 = pSkillsTxtRecord->wAuraStat[0];
    if (nStat0 < 0 || nStat0 >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    int nValue0 = STATLIST_GetStatValue(pStatList, nStat0, 0);
    if (nValue0)
    {
        if (pDamage->dwFireDamage > 0)
        {
            nValue0 = SKILLS_SubtractAbsorbedDamage(&pDamage->dwFireDamage, nValue0);
        }
        if (pDamage->dwColdDamage > 0)
        {
            nValue0 = SKILLS_SubtractAbsorbedDamage(&pDamage->dwColdDamage, nValue0);
        }
        if (pDamage->dwLtngDamage > 0)
        {
            nValue0 = SKILLS_SubtractAbsorbedDamage(&pDamage->dwLtngDamage, nValue0);
        }
        STATLIST_SetStatIfListIsValid(pStatList, nStat0, nValue0, 0);
    }

    if (nValue0 > 0)
    {
        const int nNewParamValue = DATATBLS_ApplyRatio(nValue0, 100, nValue1);
        const int nOldParamValue = STATLIST_GetStatValue(pStatList, STAT_UNSENTPARAM1, 0);
        if (m12_Abs(nNewParamValue - nOldParamValue >= 5))
        {
            STATES_ToggleGfxStateFlag(pAttacker, pSkillsTxtRecord->nAuraState, 1);
            STATLIST_SetStatIfListIsValid(pStatList, STAT_UNSENTPARAM1, nNewParamValue, 0);
        }
    }
    else
    {
        STATES_ToggleState(pAttacker, pSkillsTxtRecord->nAuraState, 0);
        D2Common_10474(pAttacker, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    return 1;
}

// 0x005C8980
int __fastcall SKILLS_AllocTransformSkillCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nToHit = 0;
    unsigned char nSrcDam = 0x80;
    for (int i = 0; i < sgptDataTables->nTransformStates; i += 1)
    {
        const short nState = sgptDataTables->pTransformStates[i];
        if (STATES_CheckState(pUnit, nState) && DATATBLS_GetStatesTxtRecordInline(nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    nToHit += SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->nSrcDam)
                    {
                        nSrcDam = pSkillsTxtRecord->nSrcDam;
                    }
                }
            }
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    damage.dwHitClass = 1;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
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

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}



struct D2ActiveRoomStrc;

static __forceinline void HIRELING_StepAside(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned char nSteps)
{
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    UNITS_GetPlayerData(pOwner);
    int nX = PATH_GetFinalTargetX(pPath);
    int nY = PATH_GetFinalTargetY(pPath);
    AITACTICS_SetAiParam(pUnit, 7, 0, 0);
    if (D2GAME_AICORE_WalkToOwner(pGame, pUnit, pOwner, nSteps)) return;
    D2GAME_EVENTS_Delete(pGame, pUnit, 2, 0);
    if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pOwner, nSteps, 1)) return;
    AITACTICS_SetAiParam(pUnit, 0, 0, 40);
    AITACTICS_WalkToTargetCoordinates(pGame, pUnit, nX, nY);
}



// 0x005E52D0
void __fastcall AITHINK_Fn061_Hireable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    int nMonsterId;
    if (!pUnit) nMonsterId = -1;
    else nMonsterId = pUnit->dwClassId;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (nMonsterId == MONSTER_ROGUEHIRE)
        {
            AITHINK_ExecuteAiFn(pGame, pUnit, pTick->pAiControl, 5);
        }
        else
        {
            AITHINK_ExecuteAiFn(pGame, pUnit, pTick->pAiControl, 6);
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pOwner->dwUnitType != UNIT_PLAYER)
    {
        if (nMonsterId == MONSTER_ROGUEHIRE)
        {
            D2AiControlStrc* pControl = pTick->pAiControl;
            AITHINK_ExecuteAiFn(pGame, pUnit, pControl, 5);
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        D2AiControlStrc* pControl = pTick->pAiControl;
        AITHINK_ExecuteAiFn(pGame, pUnit, pControl, 6);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (STATES_CheckState(pUnit, STATE_INFERNO)) STATES_ToggleState(pUnit, 12, 0);
    int nMode;
    if (!pUnit) nMode = 0;
    else nMode = pUnit->dwAnimMode;
    if (nMode == 2 || nMode == 15) return;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    int nFar;
    unsigned int nNear;
    int nSteps;
    if (pAi->dwAiParam[0] > 16 && pAi->dwAiParam[0] < 20)
    {
        nFar = 2 * pAi->dwAiParam[0];
        nNear = pAi->dwAiParam[0];
        nSteps = pAi->dwAiParam[0] >> 1;
    }
    else { nFar = 24; nNear = 16; nSteps = 5; }
    unsigned int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nOwnerMode = pOwner->dwAnimMode;
    if (nDistance > 100)
    {
        AITHINK_PetMove(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }
    if (nDistance > (unsigned int)nFar)
    {
        AITHINK_PetMove(pGame, pOwner, pUnit, 1, 1, 60, 0);
        return;
    }
    if (nDistance > nNear)
    {
        if (nOwnerMode == 2 || nOwnerMode == 6)
        {
            AITHINK_PetMove(pGame, pOwner, pUnit, 0, 0, 0, 0);
            return;
        }
        if (nOwnerMode == 3)
        {
            AITHINK_PetMove(pGame, pOwner, pUnit, 0, 1, 60, 0);
            return;
        }
    }
    if (nMode != 1)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 2, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }
    int bRanged;
    switch (nMonsterId)
    {
    case MONSTER_ACT2HIRE: case MONSTER_ACT5HIRE1: case MONSTER_ACT5HIRE2: bRanged = 0; break;
    default: bRanged = 1; break;
    }
    int bBlocked = 0;
    int nPattern = PATH_GetUnitCollisionPattern(pUnit);
    if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nPattern, 0x40))
    {
        bBlocked = 1;
        int nChance = 6;
        if (bRanged) nChance = 12;
        if (sub_00472210_SeedRollMasked(pSeed, 128) < nChance)
        {
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
            return;
        }
    }
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int bCombat;
        D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, &bCombat);
        if (pTarget && nDistance < 25)
        {
            AITHINK_HirelingCombat(pGame, pUnit, nMonsterId, pOwner, pTarget, pSeed, pTick);
            return;
        }
    }
    if (bBlocked)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return;
    }
    int nRegion = D2Common_10095(UNITS_GetRoom(pOwner), CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
    if (D2Common_10095(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)) != nRegion)
    {
        AITHINK_PetMove(pGame, pOwner, pUnit, 0, 1, 60, 0);
        return;
    }
    nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nDistance <= 1)
    {
        HIRELING_StepAside(pGame, pOwner, pUnit, nSteps - 1);
        return;
    }
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 5) D2GAME_AICORE_WalkToOwner(pGame, pUnit, pOwner, nNear);
    else AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
}

