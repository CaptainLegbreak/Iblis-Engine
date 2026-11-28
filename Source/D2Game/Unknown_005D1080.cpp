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
// build: symbol _gaszLanguageNames 0x00741A94

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
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"




D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540


void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0



typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nInitSeed);



enum
{
    EVENTTYPE_ACTIVESTATE = 5,
    EVENTTYPE_REMOVESTATE = 12,
};




extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20






#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

struct D2StaticPathStrc;

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0



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







D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit);                              // 0x00541860







void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0






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






int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0

































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

struct Seed
{
    unsigned int low;
    unsigned int high;
};

struct Unit
{
    int type;
    int classId;
    unsigned int unknown08;
    int id;
    int mode;
    Monster* monster;
    unsigned int unknown18;
    void* pool;
    Seed seed;
};

struct AuraRequest
{
    Unit* owner;
    Unit* target;
    int skill;
    int level;
    int duration;
    int stat;
    int amount;
    int state;
    void* callback;
};

struct ModeRequest
{
    int mode;
    Unit* target;
    unsigned int field08;
    unsigned int field0C;
    unsigned int field10;
    unsigned int f_14;
    unsigned int f_18;
    unsigned int field1C;
};

extern "C" int __stdcall sub_00646CA0_Evaluate(Unit*, unsigned int, int, int); // 0x00646CA0

struct D2PlayerDataStrc;

struct D2AiCmdStrc;

struct D2MonStatsTxt;









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

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005D1080
static inline int SKILLS_GetThornsPercent(D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    const int nThornsPercent = STATLIST_UnitGetStatValue(pDefender, STAT_THORNS_PERCENT, 0);
    if (nThornsPercent <= 0)
    {
        return 0;
    }
    if (!(pAttacker && pAttacker->dwUnitType == UNIT_PLAYER) && !MONSTERS_GetHirelingTypeId(pAttacker))
    {
        return nThornsPercent;
    }
    return (nThornsPercent + 4) / 8;
}

// 0x005D10C0
void __fastcall SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    int nPercent;
    const int nThornsPercent = STATLIST_UnitGetStatValue(pDefender, STAT_THORNS_PERCENT, 0);
    if (nThornsPercent <= 0)
    {
        return;
    }

    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pAttacker))
    {
        nPercent = (nThornsPercent + 4) / 8;
    }
    else
    {
        nPercent = nThornsPercent;
    }

    if (nPercent <= 0)
    {
        return;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwPhysDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercent, 100);
    damage.dwHitClass = 0x8D;
    damage.wResultFlags = 0x4021;
    SUNITDMG_ExecuteEvents(pGame, pDefender, pAttacker, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pDefender, pAttacker, &damage);
}

int __stdcall sub_M121_Emit_005D1080(D2UnitStrc* pDefender, D2UnitStrc* pAttacker) { return SKILLS_GetThornsPercent(pDefender, pAttacker); }

// 0x005D1170
int __fastcall SKILLS_SrvDo125_WakeOfDestruction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);

    int nTargetX;
    int nTargetY;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nTargetX = nTargetX - CLIENTS_GetUnitX(pUnit);
    missileParams.nTargetY = nTargetY - CLIENTS_GetUnitY(pUnit);

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -missileParams.nTargetY);
    MISSILE_SetTargetY(pMissile, missileParams.nTargetX);
    return 1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005D1280
int __fastcall SKILLS_SrvSt59_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nTimeout < 1)
    {
        nTimeout = 1;
    }

    SKILLS_SetParam1(pSkill, nTimeout + pGame->dwGameFrame);

    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 1);
    }

    return 1;
}

// 0x005D1320
static inline void SKILLS_ResetEventsAndScheduleAiThink(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete(pGame, pUnit, 0, 0);
    EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 13, 0, 0);
}

void __stdcall sub_M121_Emit_005D1320(D2GameStrc* pGame, D2UnitStrc* pUnit) { SKILLS_ResetEventsAndScheduleAiThink(pGame, pUnit); }

// 0x005D1350
int __fastcall SKILLS_SrvDo126_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath)
        {
            D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
            UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x25;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nVelocity = pMissilesTxtRecord->nVel + nSkillLevel * pMissilesTxtRecord->nVelLev / 8;
    missileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    missileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pMissile)
    {
        const int nFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) + pMissilesTxtRecord->dwParam[1];
        PATH_SetNewDistance(pMissile->pDynamicPath, nFrame);
        MISSILE_SetTotalFrames(pMissile, nFrame);
        MISSILE_SetCurrentFrame(pMissile, nFrame);
    }

    SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);

    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + 3, 0, 0);
    }
    else
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 13, 0, 0);
    }

    return 1;
}

int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0056E620

// 0x005D1570
int __fastcall SKILLS_SrvSt60_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.dwHitFlags |= 2;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        SUNITDMG_RollSuckBloodDamage(pGame, pUnit, pTarget, nSkillId, nSkillLevel, &damage);
        const int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage += DATATBLS_ApplyRatio(damage.dwPhysDamage, nPercent, 100);
        const int nLifeLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        const int nManaLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        damage.dwLifeLeech += nLifeLeech;
        damage.dwManaLeech += nManaLeech;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
    }

    return 1;
}

static inline int SKILLDRUID_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x005D16A0
int __fastcall SKILLS_SrvDo127_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
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
        pUnit->dwFlags |= 0x40;
    }

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (!pDamage)
    {
        return 0;
    }

    if (pDamage->wResultFlags & 1)
    {
        D2UnitStrc* pOwner = 0;
        if (SKILLDRUID_GetUnitType(pUnit) == 1)
        {
            pOwner = AIGENERAL_GetMinionOwner(pUnit);
            if (!pOwner)
            {
                pOwner = pUnit;
            }
        }

        int nLife = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pOwner);
        const int nAmount = SKILLDRUID_MIN(pDamage->dwPhysDamage, STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0));
        nLife += DATATBLS_ApplyRatio(nAmount, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel), 100);
        nLife = SKILLDRUID_MIN(SKILLDRUID_MAX(nLife, 1), nMaxLife);
        STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nLife, 0);
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005D1800
int __fastcall SKILLS_SrvDo128_CryHelp(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2AiCmdStrc aiCmd;
    aiCmd.nCmdParam[0] = 1;
    aiCmd.nCmdParam[1] = pTarget->dwUnitType;
    aiCmd.nCmdParam[2] = pTarget->dwUnitId;

    int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nTimeout < 1)
    {
        nTimeout = 1;
    }

    aiCmd.nCmdParam[3] = nTimeout + pGame->dwGameFrame;
    AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);

    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
    }

    return 1;
}

// 0x005D18E0
void __fastcall SKILLS_AttachImpToMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pTarget)
    {
        return;
    }

    const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
    if (nBaseId < 0)
    {
        return;
    }

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    if (nBaseId >= nMonStatsCount || nBaseId != MONSTER_IMP1)
    {
        return;
    }

    int nTargetBaseId = CUNIT_GetMonsterBaseId(pTarget);
    if (nTargetBaseId < 0 || nTargetBaseId >= nMonStatsCount)
    {
        nTargetBaseId = -1;
    }

    switch (nTargetBaseId)
    {
    case MONSTER_BARRICADETOWER:
    case MONSTER_SIEGEBEAST1:
        STATES_ToggleState(pUnit, STATE_ATTACHED, 1);
        UNITS_StoreOwner(pUnit, pTarget);
        UNITS_StoreOwner(pTarget, pUnit);
        D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        EVENT_SetRecurringEvent(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId, nSkillLevel);
        pUnit->dwFlags &= ~UNITFLAG_TARGETFLAGS;
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnitInline(pUnit), AISPECIALSTATE_MOUNTING_UNIT);
        break;
    }
}

// 0x005D19D0
void __fastcall SKILLS_DetachImpFromMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pOwner)
    {
        return;
    }

    const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
    if (nBaseId < 0)
    {
        return;
    }

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    if (nBaseId >= nMonStatsCount || nBaseId != MONSTER_IMP1)
    {
        return;
    }

    int nOwnerBaseId = CUNIT_GetMonsterBaseId(pOwner);
    if (nOwnerBaseId < 0 || nOwnerBaseId >= nMonStatsCount)
    {
        nOwnerBaseId = -1;
    }

    switch (nOwnerBaseId)
    {
    case MONSTER_BARRICADETOWER:
    case MONSTER_SIEGEBEAST1:
        STATES_ToggleState(pUnit, STATE_ATTACHED, 0);
        UNITS_StoreOwner(pUnit, 0);
        UNITS_StoreOwner(pOwner, 0);
        if (UNITS_GetCurrentLifePercentage(pUnit) < 10)
        {
            SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        }
        else
        {
            pUnit->dwFlags |= UNITFLAG_TARGETFLAGS;
            D2GAME_EVENTS_Delete(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
            AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), AISPECIALSTATE_NONE);
        }
        break;
    }
}

// 0x005D1AB0
int __fastcall SKILLS_SrvDo129_ImpTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pOwner)
    {
        int nTargetX;
        int nTargetY;
        D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nTargetX, &nTargetY);
        SUNIT_TeleportUnit(pGame, pUnit, 0, nTargetX, nTargetY, 0, 0);
        SKILLS_DetachImpFromMonster(pGame, pUnit, pOwner, nSkillId, nSkillLevel);
        return 1;
    }

    if (!pTarget)
    {
        return SKILLS_SrvDo098_MonTeleport(pGame, pUnit, nSkillId, nSkillLevel);
    }

    if (SUNIT_GetOwner(pGame, pTarget) || SUNIT_IsDead(pTarget) || !SUNIT_TeleportUnit(pGame, pUnit, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 1, 0))
    {
        return 0;
    }

    SKILLS_AttachImpToMonster(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    return 1;
}

// 0x005D1BF0
int __fastcall SKILLS_SrvSt61_SelfResurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkill, int nLevel)
{
    const unsigned int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return 0;
    SKILLS_ResurrectUnit(pGame, pUnit);
    pUnit->dwFlags &= ~14;
    PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 256);
    return 1;
}

// 0x005D1C30
static int __stdcall SKILLS_CreateMissileVolley(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCount, int nMissile, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissile;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;
    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &missileParams.nX, &missileParams.nY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
// build: symbol ?gnVolleyOffsetX@* 0x006E3254
        missileParams.nTargetX = gnVolleyOffsetX[i & 3];
// build: symbol ?gnVolleyOffsetY@* 0x006E3264
        missileParams.nTargetY = gnVolleyOffsetY[i & 3];
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005D1CD0
int __fastcall SKILLS_SrvDo130_VineAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile <= 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    SKILLS_CreateMissileVolley(pGame, pUnit, nCount, nMissile, nSkillId, nSkillLevel);
    return 1;
}

static inline SkillRecord* GetSkillRecord(int skill)
{
    if (skill < 0)
        return 0;
    if (skill >= gVar_00744304->skillCount)
        return 0;
    return &gVar_00744304->skills[skill];
}

static inline int GetUnitType(Unit* unit)
{
    return unit ? unit->type : 6;
}

static inline AiState* GetAiState(Unit* unit)
{
    if (GetUnitType(unit) == 1 && unit->monster)
        return unit->monster->ai;
    return 0;
}

static inline int SkillChanceSucceeds(Unit* owner, SkillRecord* record, int skill, int level)
{
    int chance = sub_00646CA0_Evaluate(owner, record->chance, skill, level);
    return sub_0045C390_Roll(&owner->seed, 100) < chance;
}

// 0x005D1D70
static void __stdcall SKILLS_ApplyAuraStateToTarget(Unit* owner, Unit* target, int level, int skill)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return;
    AuraRequest request;
    memset(&request, 0, sizeof(request));
    request.owner = owner;
    request.target = target;
    request.skill = skill;
    request.level = level;
    request.duration = sub_00646CA0_Evaluate(owner, record->calc, skill, level);
    request.stat = -1;
    request.state = record->state;
    D2StatListStrc* list = SKILLS_ApplyStateEffect(&request);
    if (list)
        SKILLS_ApplyAuraStatsToStatList(owner, list, record, skill, level);
}

// 0x005D1E10
static void __stdcall SKILLS_ApplyShapeshift(Unit* owner, int level, int skill, Game* game, Unit* target)
{
    SkillRecord* record = 0;
    if (skill >= 0 && skill < gVar_00744304->skillCount)
        record = &gVar_00744304->skills[skill];
    if (!record)
        return;

    int selected = D2GAME_GetSummonIdFromSkill(owner, 0, skill, level, &level, 0, 0);
    if (selected < 0)
        return;
    if (GetUnitType(target) != 1)
        return;

    int variant;
    DATATBLS_GetMonsterChainInfo(!target ? -1 : target->classId, 0, &variant);
// build: symbol ?SKILLS_GetMonsterClassFromChain@* 0x0054DA60
    int resolved = SKILLS_GetMonsterClassFromChain(selected, variant);
// build: symbol ?MONSTER_Reinitialize@* 0x00574370
    MONSTER_Reinitialize(game, target, resolved, level);

    AiState* ai;
    if (target->type == 1 && target->monster)
        ai = target->monster->ai;
    else
        ai = 0;
    AITHINK_ExecuteAiFn(game, target, ai, 15);

    ModeRequest mode;
    MONSTERMODE_GetModeChangeInfo(target, level, &mode);
    D2GAME_ModeChange(game, &mode, 1);
    STATES_ToggleState(target, 142, 1);

    int ownerType;
    unsigned int ownerId;
    if (owner == 0)
    {
        ownerId = -1;
        ownerType = 6;
    }
    else
    {
        ownerId = owner->id;
        ownerType = owner->type;
    }
    D2StatListStrc* list = sub_006251F0_Allocate(game->pool, 0, 0, ownerType, ownerId);
    if (list)
    {
        D2COMMON_10475_PostStatToStatList(target, list, 1);
        sub_006252D0_State(list, 142);
        sub_00627150_Stat(list, 355, resolved, 0);
    }

    if (record->effect > 0 && record->effect < 43)
// build: symbol ?D2GAME_BOSSES_AssignUMod@* 0x005A4850
        D2GAME_BOSSES_AssignUMod(game, target, record->effect, 0);
}

// 0x005D1F70
extern "C" int __fastcall SKILLS_SrvDo131_OverseerWhip(Game* game, Unit* owner, int skill, int level)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return 0;
    if (record->state < 0)
        return 0;
    if (record->state >= gVar_00744304->stateCount)
        return 0;
    Unit* target = SUNIT_GetTargetUnit(game, owner);
    if (target && !SUNIT_IsDead(target))
    {
        const int type = GetUnitType(target);
        int bSkip = 1;
        if (type == 1 && CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(target)) == 453)
        {
            bSkip = SkillChanceSucceeds(owner, record, skill, level);
        }
        if (bSkip)
        {
            SKILLS_ApplyAuraStateToTarget(owner, target, level, skill);
        }
        else if (STATES_CheckState(target, record->state))
        {
            SKILLS_ApplyAuraStateToTarget(owner, target, level, skill);
        }
        else
        {
            SKILLS_ApplyShapeshift(owner, level, skill, game, target);
        }
        return 1;
    }
    return 0;
}

static inline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int UNITS_TestIgnoreTargetFlag(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 30) & 1;
    return bResult;
}


// 0x005D2090
int __fastcall SKILLS_SrvDo132_ImpFireMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    int nMissileOffset;
    DATATBLS_GetMonsterChainInfo(nClassId, 0, &nMissileOffset);
    SKILLS_CreateMissileAtOffset(pGame, nMissileOffset + nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    return 1;
}

// 0x005D2140
int __fastcall SKILLS_CanImpregnateTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    int nBaseId = CUNIT_GetMonsterBaseId(pTarget);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nBaseId = -1;
    }

    switch (nBaseId)
    {
    case MONSTER_PUTRIDDEFILER1:
    case MONSTER_PAINWORM1:
        return 0;
    }

    if (STATES_CheckState(pTarget, STATE_PREGNANT))
    {
        return 0;
    }

    return STATLIST_GetUnitAlignment(pTarget) != 2;
}

extern const int gnVolleyOffsetX[4] = { 0, 0, 1, -1 }; // 0x006E3254

extern const int gnVolleyOffsetY[4] = { 1, -1 }; // 0x006E3264
