#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2MonModes.h"
#include "D2PlayerModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2MonsterIds.h"
#include "D2UnitData.h"
#include "D2GameCallbackArgs.h"
#include "D2AiCallbackArgs.h"
#include "FogApi.h"
#include "D2CommonApi.h"

struct D2MonStatsTxt;

struct D2LevelsTxt;

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"


typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);


int __fastcall AITHINK_TryBossTauntOnSight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B1140

int __fastcall AITHINK_TryTeleportAway(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B11F0


D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0


#define ASSERT(expr,line) if (!(expr)) { FOG_DisplayHalt(gszEmptyString,sub_00408090(),line); exit(-1); }

#define AI_PARAM(n) (pMonStatsTxt->wAiParam[n][pGame->nDifficulty])

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


struct D2AiTableStrc;

struct D2StaticPathStrc;

struct D2AiCmdStrc;

struct D2SkillsTxt;

union D2SeedStrc;

struct D2UnitStrc;

struct D2AiControlStrc;

struct D2DataTablesStrc;

struct D2GameStrc;

struct D2AiTickParamStrc;

struct D2CoordStrc;

struct D2SuperUniquesTxt;

extern "C" void* __cdecl memset(void*,int,unsigned int);

typedef void (__fastcall* AiFn)(D2GameStrc*,D2UnitStrc*,D2AiTickParamStrc*);

struct D2AiTableStrc
{
    int unk00;
    AiFn init;
    AiFn function;
    AiFn alternate;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const char gszEmptyString[]; // 0x006CC837


__declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*);


const D2AiTableStrc* __fastcall AITHINK_GetAiTableRecord(D2UnitStrc*,int); // 0x005B15D0


void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc*,D2UnitStrc*,D2AiTickParamStrc*); // 0x005B0CD0

void __fastcall AITHINK_Fn051_Diablo(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick); // 0x005E9170

void __fastcall AITHINK_Fn126_CatapultSpotter(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EE040

void __fastcall AITHINK_Fn132_AncientStatue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EEAA0

void __fastcall AITHINK_Fn134_BaalThrone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EF320

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, unsigned char nArg); // 0x005DE190


extern "C" const char gszEmptyAssertText; // 0x006CC837

#define PATHTYPE_TOWARD 2

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005B0BD0
int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    const int nXDiff = CLIENTS_GetUnitXInline(pUnit1) - CLIENTS_GetUnitXInline(pUnit2);
    const int nYDiff = CLIENTS_GetUnitYInline(pUnit1) - CLIENTS_GetUnitYInline(pUnit2);
    return nXDiff * nXDiff + nYDiff * nYDiff;
}

// 0x005B0CC0
void __stdcall AITHINK_Fn000(int nUnused1)
{
}

// 0x005B0CD0
void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (UNITS_GetRoom(pUnit))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 200);
    }
}


// 0x005B0D00
D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg)
{
    D2PantherAiCallbackArgStrc* pArg = (D2PantherAiCallbackArgStrc*)pCallbackArg;

    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || pUnit == pTarget)
    {
        return 0;
    }

    if (CUNIT_GetMonsterBaseId(pUnit) != CUNIT_GetMonsterBaseId(pTarget) || MONSTERS_IsDead(pTarget))
    {
        return 0;
    }

    const int nDistance = AITHINK_GetSquaredDistance(pUnit, pTarget);
    if (nDistance >= pArg->nDistance)
    {
        return 0;
    }

    pArg->pTarget = pTarget;
    pArg->nDistance = nDistance;
    return 0;
}

// 0x005B0D60
int __fastcall AITHINK_GetSpecialStateFromAiControl(D2AiControlStrc* pAiControl)
{
    return pAiControl->nAiSpecialState;
}

// 0x005B0D70
void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2)
{
    if (!pAiControl)
    {
        return;
    }
    if (nParam0 != -666)
    {
        pAiControl->dwAiParam[0] = nParam0;
    }
    if (nParam1 != -666)
    {
        pAiControl->dwAiParam[1] = nParam1;
    }
    if (nParam2 != -666)
    {
        pAiControl->dwAiParam[2] = nParam2;
    }
}

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

// 0x005B0DA0
int __fastcall AITHINK_CanUnitSwitchAi(D2UnitStrc* pUnit, D2MonStatsTxt* pMonStatsTxtRecord, int nAiSpecialState, int bCheckIfSuperUnique)
{
    if (nAiSpecialState == 0)
    {
        return 1;
    }

    if (nAiSpecialState != 10 && nAiSpecialState != 11 && nAiSpecialState != 12)
    {
        return 1;
    }

    if (bCheckIfSuperUnique && MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 2))
    {
        return 0;
    }

    if (!pUnit)
    {
        return UNITS_CanSwitchAI(-1);
    }

    return UNITS_CanSwitchAI(pUnit->dwClassId);
}

// 0x005B0E00
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* hUnit, D2AiControlStrc* pAiControl, int nAiSpecialState)
{
    ASSERT(!STATES_CheckState(hUnit, STATE_UNINTERRUPTABLE), 422);

    if (!pGame || !hUnit || !pAiControl || nAiSpecialState >= 18 || (!hUnit ? 6 : hUnit->dwUnitType) != 1)
    {
        return;
    }

    const int nClassId = hUnit->dwClassId;
    if (nClassId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nAiSpecialState = 1;
    }

    if (pAiControl->pAiParamFn)
    {
        const D2AiTableStrc* pAiTableRecord = AITHINK_GetAiTableRecord(hUnit, pAiControl->nAiSpecialState);
        if ((AiFn)pAiControl->pAiParamFn == pAiTableRecord->function && pAiTableRecord->alternate)
        {
            pAiControl->nAiSpecialState = nAiSpecialState;
            pAiControl->pAiParamFn = (void*)pAiTableRecord->alternate;
            return;
        }
    }

    memset(pAiControl->dwAiParam, 0, 3 * sizeof(int));

    AIGENERAL_FreeAllAiCommands(pGame, hUnit);

    const D2AiTableStrc* __restrict pAiTableRecord = AITHINK_GetAiTableRecord(hUnit, nAiSpecialState);
    if (!pAiTableRecord)
    {
        return;
    }

    if (pAiTableRecord->init)
    {
        D2AiTickParamStrc aiTickParam = {};
        aiTickParam.pAiControl = pAiControl;
        aiTickParam.pMonstatsTxt = DATATBLS_GetMonStatsTxtRecord(nClassId);
        aiTickParam.pMonstats2Txt = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (!aiTickParam.pMonstatsTxt || !aiTickParam.pMonstats2Txt)
        {
            return;
        }

        pAiTableRecord->init(pGame, hUnit, &aiTickParam);
    }

    AiFn pAiParamFn = pAiTableRecord->function;
    if (!pAiParamFn)
    {
        pAiParamFn = AITHINK_Fn001_100_Idle_Buffy;
    }

    pAiControl->nAiSpecialState = nAiSpecialState;
    pAiControl->pAiParamFn = (void*)pAiParamFn;

    ASSERT(!IsBadCodePtr((void*)pAiParamFn), 498);
}


struct D2DoorObjectAiCallbackArgStrc;


unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0

#define MONSTATSFLAGINDEX_OPENDOORS 3

int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nObjectType, int nObjectGUID); // 0x00584540

int __fastcall AITHINK_TryOpenNearbyDoor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B0F50

extern unsigned int gdwBitMasks[]; // 0x006CE268

// 0x005B0F50
int __fastcall AITHINK_TryOpenNearbyDoor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (BITARRAY_CHECK(pAiTickParam->pMonstatsTxt->nMonStatsFlags, MONSTATSFLAGINDEX_OPENDOORS) && D2Common_10201(pUnit->pDynamicPath) & 0x800)
    {
        D2DoorObjectAiCallbackArgStrc arg;
        arg.pDoor = 0;
        arg.nDistance = 9;

        AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 8);

        D2UnitStrc* pDoor = arg.pDoor;
        if (pDoor)
        {
            const int nClassId = (pDoor ? pDoor->dwClassId : -1);
            if (DATATBLS_GetObjectsTxtRecord(nClassId)->nMonsterOK)
            {
                const int nDoorId = (pDoor ? pDoor->dwUnitId : -1);
                OBJMODE_OperateObjectInRange(pGame, pUnit, 2, nDoorId);
                AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
                return 1;
            }
        }
    }

    return 0;
}


int __fastcall D2GAME_AICORE_MinionLeash(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam); // 0x005B0FF0


int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc* pTarget, D2UnitStrc* pSource); // 0x005DC380


static inline int CanWalk(D2UnitStrc* pMonster)
{
    return MONSTERUNIQUE_TestMonModeFlag(!pMonster ? -1 : pMonster->dwClassId, 2);
}

// 0x005B0FF0
int __fastcall D2GAME_AICORE_MinionLeash(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam)
{
    int nOwnerGUID = 0;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    // volatile below only makes pAiControl live in memory (the original spills it, keeping pGame in a register).
    // Reading (c2force, plain form 198/237): pAiControl takes edi in round 1 (priority 43, pGame 22); below pGame
    // (--prio 1:pAiControl:-22) it is 232/237, with the held -1 constant left (the game compares with an immediate).
    nOwnerGUID = *(volatile int*)&pAiControl->dwOwnerGUID;
    if (nOwnerGUID == -1)
        return 0;
    if (!CanWalk(pMonster))
    {
        pAiControl->dwOwnerGUID = -1;
        return 0;
    }
    nOwnerGUID = pAiControl->dwOwnerGUID;
    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, !pAiControl ? 6 : pAiControl->dwOwnerType, nOwnerGUID);
    if (!pOwner)
    {
        (*(D2AiControlStrc* volatile*)&pAiControl)->dwOwnerGUID = -1;
        return 0;
    }
    if (SUNIT_IsDead(pOwner))
    {
        (*(D2AiControlStrc* volatile*)&pAiControl)->dwOwnerGUID = -1;
        return 0;
    }
    const int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pMonster, pOwner);
    if (nDistance <= 1 && (*(D2AiControlStrc* volatile*)&pAiControl)->dwOwnerType == 0)
    {
        if (AITACTICS_WalkAwayFromTarget(pGame, pMonster, pOwner, 19, 1))
            return 1;
    }
    else
    {
        if (nDistance <= 20)
            return 0;
        AITACTICS_SetAiParam(pMonster, 7, 0, 40);
    }
    D2GAME_AICORE_WalkToOwner(pGame, pMonster, pOwner, 19);
    return 1;
}

int __fastcall AITHINK_CheckAiTickPreconditions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B10E0

// 0x005B10E0
int __fastcall AITHINK_CheckAiTickPreconditions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (STATES_CheckState(pUnit, STATE_STUNNED))
    {
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 3);
        return 1;
    }

    if (AITHINK_TryOpenNearbyDoor(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    return D2GAME_AICORE_MinionLeash(pGame, pUnit, pAiTickParam) != 0;
}

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380


// 0x005B1140
int __fastcall AITHINK_TryBossTauntOnSight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const int bBoss = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 8) || MONSTERS_IsBoss(0, pUnit);
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount && pUnit->dwClassId == 250 || bBoss)
    {
        if (pAiTickParam->nTargetDistance < 20u && pAiTickParam->pTarget && pAiTickParam->pTarget->dwUnitType == UNIT_PLAYER && !AIUTIL_CheckAiControlFlag(pAiTickParam->pAiControl, 0x10))
        {
            SUNIT_AttachSound(pUnit, 16, 0);
            AIUTIL_ToggleAiControlFlag(pAiTickParam->pAiControl, 0x10, 1);
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 20);
            return 1;
        }
    }
    return 0;
}


int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, int* pX, int* pY, int bAvoidWarps); // 0x0054DC40


static inline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005B11F0
int __fastcall AITHINK_TryTeleportAway(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (!AIUTIL_CheckAiControlFlag(pAiTickParam->pAiControl, 0x20))
    {
        return 0;
    }

    if ((int)(SEED_RollRandomNumberInline(&pUnit->pSeed) % 100) >= 40)
    {
        return 0;
    }

    const int nId = CUNIT_GetMonsterBaseId(pUnit);
    const int nBaseId = (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) ? nId : -1;

    int bNoHeal = MONSTERUNIQUE_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, 1);
    if (nBaseId == MONSTER_BIGHEAD1 || nBaseId == MONSTER_COUNCILMEMBER1 || nBaseId == MONSTER_BAALHIGHPRIEST)
    {
        bNoHeal = 1;
    }

    const int nLifePct = UNITS_GetCurrentLifePercentage(pUnit);
    if (nLifePct >= 30)
    {
        if (bNoHeal)
        {
            return 0;
        }

        if ((unsigned int)pAiTickParam->nTargetDistance >= 10)
        {
            return 0;
        }
    }

    if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 15)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2RoomCoordListStrc* pCoordList = D2Common_10096(pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        int nX;
        int nY;
        if (sub_0054DC40_FindSpawnPosition(pGame, pRoom, pCoordList, nBaseId, &nX, &nY, 0))
        {
            D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
            if (pTargetRoom && !DUNGEON_IsRoomInTown(pTargetRoom))
            {
                if (nLifePct < 30 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < 25 && !STATES_CheckState(pUnit, STATE_PREVENTHEAL))
                {
                    int nHeal = STATLIST_UnitGetStatValue(pUnit, 12, 0) << 8;
                    const int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
                    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
                    if (nLife + nHeal > nMaxLife)
                    {
                        nHeal = nMaxLife - nLife;
                    }
                    STATLIST_AddUnitStat(pUnit, STAT_HITPOINTS, nHeal, 0);
                }

                AITACTICS_UseSkill(pGame, pUnit, 4, SKILL_MONTELEPORT, 0, nX, nY);
                return 1;
            }
        }
    }

    return 0;
}

int __fastcall AITHINK_HandleMonsterAiPreActions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B13E0

struct D2AiCallback11ArgStrc;

struct D2AiCallback11ArgStrc
{
    D2UnitStrc* pTarget;
    int nDistance;
    D2UnitStrc* unk0x08;
    int unk0x0C[7];
};

// 0x005B13E0
int __fastcall AITHINK_HandleMonsterAiPreActions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    if (!pAiTickParam->pTarget)
    {
        return 0;
    }

    if (AITHINK_TryBossTauntOnSight(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    if (AITHINK_TryTeleportAway(pGame, pUnit, pAiTickParam))
    {
        return 1;
    }

    if (!MONSTERUNIQUE_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, 1))
    {
        return 0;
    }

    if (!MONSTERUNIQUE_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nMonSpcWalk = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom))->nMonSpcWalk;
    if (nMonSpcWalk <= 0 || (unsigned int)pAiTickParam->nTargetDistance <= nMonSpcWalk)
    {
        return 0;
    }

    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    if (AIUTIL_HasClearApproachToTarget(pUnit, pTarget))
    {
        return 0;
    }

    D2AiCallback11ArgStrc arg;
    arg.pTarget = 0;
    arg.nDistance = 0x7FFFFFFF;
    arg.unk0x08 = pTarget;
    AIUTIL_FindTargetWithCallback(pGame, pUnit, &arg, 0, 11);

    if (!arg.pTarget)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
        return 1;
    }

    pAiTickParam->pTarget = arg.pTarget;
    pAiTickParam->nTargetDistance = arg.nDistance;
    return 0;
}


static inline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005B14E0
void __fastcall D2GAME_AI_SpecialState02(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    D2UnitStrc* pTarget = pAiTickParam->pTarget;
    int nDistance = pAiTickParam->nTargetDistance;
    if (AIUTIL_IsGettingHit(pUnit) || nDistance < 4)
    {
        AITHINK_ExecuteAiFn(pGame, pUnit, pAiTickParam->pAiControl, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    if (nDistance > 10 && !pAiControl->dwAiParam[0])
    {
        pAiControl->dwAiParam[0] = 1;
        D2GAME_AICORE_WalkToOwner(pGame, pUnit, pTarget, 12);
        return;
    }
    if ((AI_RollUnitSeed(pUnit) & 0xFF) < 77)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 4);
        return;
    }
    if ((AI_RollUnitSeed(pUnit) & 0xFF) < 26)
    {
        pAiControl->dwAiParam[0] = 0;
    }
    AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
}

extern D2AiTableStrc gaAiTable[148]; // 0x0073CA18
extern D2AiTableStrc gaSpecialAiStateTable[18]; // 0x0073D358

static inline D2MonStatsTxt* GetRec(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        return (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
    }
    return 0;
}

static inline const D2AiTableStrc* GetByIndex(D2MonStatsTxt* pRecord)
{
    short nIndex = pRecord->wAI;
    if (nIndex >= 0 && (unsigned short)nIndex < 148) {
        return &gaAiTable[nIndex];
    }
    return &gaAiTable[0];
}

// 0x005B15D0
const D2AiTableStrc* __fastcall AITHINK_GetAiTableRecord(D2UnitStrc* pUnit, int nMode)
{
    D2MonStatsTxt* pRecord = GetRec(pUnit);
    if (nMode) {
        if (nMode == 10 || nMode == 11 || nMode == 12) {
            if (!UNITS_CanSwitchAI(!pUnit ? -1 : pUnit->dwClassId)) {
                return GetByIndex(pRecord);
            }
        }
        return &gaSpecialAiStateTable[nMode];
    }
    return GetByIndex(pRecord);
}

int __fastcall AITHINK_FindAiTickTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B1650

struct D2AiStateStrc;

struct D2AiStateStrc
{
    int nTargetMode;
};

D2AiStateStrc* __fastcall sub_005B15D0_GetAiState(D2UnitStrc*, int); // 0x005B15D0


D2UnitStrc* __fastcall AITACTICS_FindTargetOrIdle(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DE9D0

// 0x005B1650
int __fastcall AITHINK_FindAiTickTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
{
    const D2AiControlStrc* v_pAiControl_22 = pAiTickParam->pAiControl;
    D2AiStateStrc* pState = sub_005B15D0_GetAiState(pUnit, v_pAiControl_22->nAiSpecialState);
    switch (pState->nTargetMode)
    {
    case 0:
        return 0;
    case 1:
        pAiTickParam->pTarget = AITACTICS_FindTargetOrIdleInNeutralMode(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return pAiTickParam->pTarget == 0;
    case 2:
        pAiTickParam->pTarget = AIUTIL_FindAiTarget(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return 0;
    case 4:
        pAiTickParam->pTarget = AITACTICS_FindTargetOrIdle(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return pAiTickParam->pTarget == 0;
    case 5:
        pAiTickParam->pTarget = AITACTICS_FindTargetOrIdle(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
        return 0;
    default:
        return 1;
    }
}

typedef void (__fastcall* AIPARAMFN)(D2GameStrc*, D2UnitStrc*, D2AiTickParamStrc*);

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }
    return 0;
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMonsterId = pUnit->dwClassId;
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nMonsterId];
        }
    }
    return 0;
}

static inline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecordFromUnit_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMonsterId = pUnit->dwClassId;
        if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
            if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
            {
                return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
            }
        }
    }
    return 0;
}

// 0x005B1740
void __fastcall AITHINK_ExecuteMonsterAiTick(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2)
{
    D2AiTickParamStrc aiTickParam = {};
    aiTickParam.pAiControl = AIGENERAL_GetAiControlFromUnit_Inline(pUnit);
    aiTickParam.pMonstatsTxt = MONSTERMODE_GetMonStatsTxtRecordFromUnit_Inline(pUnit);
    aiTickParam.pMonstats2Txt = MONSTERREGION_GetMonStats2TxtRecordFromUnit_Inline(pUnit);
    if (!aiTickParam.pMonstatsTxt || !aiTickParam.pMonstats2Txt)
    {
        return;
    }
    if (AITHINK_CheckAiTickPreconditions(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    if (AITHINK_FindAiTickTarget(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    if (AITHINK_HandleMonsterAiPreActions(pGame, pUnit, &aiTickParam))
    {
        return;
    }
    D2_ASSERT(!IsBadCodePtr((int (__stdcall*)())aiTickParam.pAiControl->pAiParamFn), 0x39E);
    ((AIPARAMFN)aiTickParam.pAiControl->pAiParamFn)(pGame, pUnit, &aiTickParam);
}

struct D2MonStats2Txt;

struct D2StatListStrc;

static inline int GetX(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int GetY(D2UnitStrc* pUnit) {
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline D2SkillsTxt* GetSkill(int nId) {
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}

extern "C" void __cdecl AITHINK_Fn002_Skeleton(); // 0x005EFCF0
extern "C" void __cdecl AITHINK_Fn003_Zombie(); // 0x005EFE20
extern "C" void __cdecl AITHINK_Fn004_Bighead(); // 0x005EFF50
extern "C" void __cdecl AITHINK_Fn005_BloodHawk(); // 0x005F00E0
extern "C" void __cdecl AITHINK_Fn006_Fallen(); // 0x005F02C0
extern "C" void __cdecl AITHINK_Fn007_Brute(); // 0x005EFB80
extern "C" void __cdecl sub_005F0700(); // 0x005F0700
extern "C" void __cdecl AITHINK_Fn009_Wraith(); // 0x005F0A20
extern "C" void __cdecl AITHINK_Fn010_CorruptRogue(); // 0x005F0B00
extern "C" void __cdecl AITHINK_Fn011_Baboon(); // 0x005F0CD0
extern "C" void __cdecl AITHINK_Fn012_019_Goatman_Swarm(); // 0x005F12A0
extern "C" void __cdecl AITHINK_Fn013_FallenShaman(); // 0x005F1440
extern "C" void __cdecl AITHINK_Fn014_QuillRat(); // 0x005F1140
extern "C" void __cdecl AITHINK_Fn015_SandMaggot(); // 0x005F1800
extern "C" void __cdecl AITHINK_SpecialFn015_SandMaggot(); // 0x005F1750
extern "C" void __cdecl AITHINK_Fn016_ClawViper(); // 0x005F1B60
extern "C" void __cdecl AITHINK_Fn017_SandLeaper(); // 0x005F20A0
extern "C" void __cdecl AITHINK_Fn018_PantherWoman(); // 0x005F22B0
extern "C" void __cdecl sub_005F2460_AiThink(); // 0x005F2460
extern "C" void __cdecl AITHINK_Fn020_Scarab(); // 0x005F2540
extern "C" void __cdecl AITHINK_Fn021_Mummy(); // 0x005F2850
extern "C" void __cdecl sub_005F2B10(); // 0x005F2B10
extern "C" void __cdecl sub_005F3170(); // 0x005F3170
extern "C" void __cdecl AITHINK_Fn024_Mosquito(); // 0x005F3730
extern "C" void __cdecl AITHINK_Fn025_Willowisp(); // 0x005F39B0
extern "C" void __cdecl AITHINK_Fn026_Arach(); // 0x005F4510
extern "C" void __cdecl AITHINK_Fn027_ThornHulk(); // 0x005F4850
extern "C" void __cdecl sub_005F4A70(); // 0x005F4A70
extern "C" void __cdecl AITHINK_Fn029_BatDemon(); // 0x005F5040
extern "C" void __cdecl AITHINK_BatDemon_HandleSpecialAiState(); // 0x005F4FD0
extern "C" void __cdecl sub_005F53E0(); // 0x005F53E0
extern "C" void __cdecl AITHINK_Fn031_NpcOutOfTown(); // 0x005E7880
extern "C" void __cdecl AITHINK_Fn032_Npc(); // 0x005E7130
extern "C" void __cdecl AITHINK_Fn033_HellMeteor(); // 0x005F56D0
extern "C" void __cdecl AITHINK_Fn034_Andariel(); // 0x005F5830
extern "C" void __cdecl AITHINK_Fn035_CorruptArcher(); // 0x005F5A20
extern "C" void __cdecl AITHINK_Fn036_CorruptLancer(); // 0x005F5D50
extern "C" void __cdecl AITHINK_Fn037_SkeletonBow(); // 0x005F6070
extern "C" void __cdecl AITHINK_Fn038_MaggotLarva(); // 0x005F6220
extern "C" void __cdecl AITHINK_Fn039_PinHead(); // 0x005F6340
extern "C" void __cdecl AITHINK_Fn040_MaggotEgg(); // 0x005F6530
extern "C" void __cdecl AITHINK_Fn041_Towner(); // 0x005E7540
extern "C" void __cdecl AITHINK_Fn042_Vendor(); // 0x005E9E00
extern "C" void __cdecl sub_005F6630_InitAiParamsFrame(); // 0x005F6630
extern "C" void __cdecl AITHINK_Fn043_FoulCrowNest(); // 0x005F6650
extern "C" void __cdecl AITHINK_Fn044_Duriel(); // 0x005F67B0
extern "C" void __cdecl AITHINK_Fn045_Sarcophagus(); // 0x005F6A10
extern "C" void __cdecl AITHINK_Fn046_ElementalBeast(); // 0x005F6B70
extern "C" void __cdecl AITHINK_Fn047_FlyingScimitar(); // 0x005F6CA0
extern "C" void __cdecl AITHINK_Fn048_ZakarumZealot(); // 0x005F6E60
extern "C" void __cdecl AITHINK_Fn049_ZakarumPriest(); // 0x005F72D0
extern "C" void __cdecl sub_005F78B0(); // 0x005F78B0
extern "C" void __cdecl AITHINK_ResetAiAndPreserveHomeCommand(); // 0x005E8480
extern "C" void __cdecl AITHINK_Fn052_FrogDemon(); // 0x005F8260
extern "C" void __cdecl sub_005F81D0(); // 0x005F81D0
extern "C" void __cdecl AITHINK_Fn053_Summoner(); // 0x005F85C0
extern "C" void __cdecl AITHINK_Fn054_NpcStationary(); // 0x005E73A0
extern "C" void __cdecl AITHINK_Fn055_Izual(); // 0x005F89B0
extern "C" void __cdecl AITHINK_Fn056_Tentacle(); // 0x005F8F80
extern "C" void __cdecl sub_005F9270(); // 0x005F9270
extern "C" void __cdecl AITHINK_Fn058_Navi(); // 0x005E7E20
extern "C" void __cdecl AITHINK_ResetBloodRavenReturnState(); // 0x005E6300
extern "C" void __cdecl AITHINK_Fn059_BloodRaven(); // 0x005E6320
extern "C" void __cdecl AITHINK_Fn060_GoodNpcRanged(); // 0x005E7AC0
extern "C" void __cdecl sub_005E52D0(); // 0x005E52D0
extern "C" void __cdecl sub_005E5280(); // 0x005E5280
extern "C" void __cdecl AITHINK_Fn062_TownRogue(); // 0x005E7D60
extern "C" void __cdecl sub_005F9490(); // 0x005F9490
extern "C" void __cdecl AITHINK_Fn064_SkeletonMage(); // 0x005F96C0
extern "C" void __cdecl AITHINK_Fn065_FetishShaman(); // 0x005F9A80
extern "C" void __cdecl sub_005F9950(); // 0x005F9950
extern "C" void __cdecl AITHINK_Fn066_SandMaggotQueen(); // 0x005F9CF0
extern "C" void __cdecl AITHINK_Fn067_NecroPet(); // 0x005E4CF0
extern "C" void __cdecl AITHINK_Fn068_VileMother(); // 0x005FA010
extern "C" void __cdecl AITHINK_Fn069_VileDog(); // 0x005FA280
extern "C" void __cdecl AITHINK_Fn070_FingerMage(); // 0x005FA380
extern "C" void __cdecl sub_005FA710(); // 0x005FA710
extern "C" void __cdecl AITHINK_Fn072_DoomKnight(); // 0x005FAA90
extern "C" void __cdecl AITHINK_Fn073_AbyssKnight(); // 0x005FAB80
extern "C" void __cdecl AITHINK_Fn074_OblivionKnight(); // 0x005FAF00
extern "C" void __cdecl AITHINK_Fn075_QuillMother(); // 0x005FB2A0
extern "C" void __cdecl AITHINK_Fn076_EvilHole(); // 0x005FB410
extern "C" void __cdecl AITHINK_Fn077_TrapMissile(); // 0x005FB5B0
extern "C" void __cdecl AITHINK_Fn078_TrapRightArrow(); // 0x005FB6C0
extern "C" void __cdecl AITHINK_Fn079_TrapLeftArrow(); // 0x005FB7E0
extern "C" void __cdecl sub_005FB900(); // 0x005FB900
extern "C" void __cdecl AITHINK_Fn081_JarJar(); // 0x005E7590
extern "C" void __cdecl sub_005E0160(); // 0x005E0160
extern "C" void __cdecl AITHINK_Fn083_MosquitoNest(); // 0x005E0260
extern "C" void __cdecl AITHINK_InitializeBoneWallLifetime(); // 0x005E0390
extern "C" void __cdecl AITHINK_Fn084_BoneWall(); // 0x005E0400
extern "C" void __cdecl AITHINK_Fn085_HighPriest(); // 0x005E0490
extern "C" void __cdecl AITHINK_Fn086_Hydra(); // 0x005E9E60
extern "C" void __cdecl AITHINK_Fn087_TrapMelee(); // 0x005FBA60
extern "C" void __cdecl AITHINK_Fn088_7TIllusion(); // 0x005EA080
extern "C" void __cdecl AITHINK_Fn089_Megademon(); // 0x005E0C80
extern "C" void __cdecl AITHINK_Fn090_Griswold(); // 0x005E5AC0
extern "C" void __cdecl AITHINK_Fn091_DarkWanderer(); // 0x005EA130
extern "C" void __cdecl sub_005FB9B0(); // 0x005FB9B0
extern "C" void __cdecl AITHINK_Fn093_ArcaneTower(); // 0x005E0F60
extern "C" void __cdecl AITHINK_Fn094_DesertTurret(); // 0x005E0980
extern "C" void __cdecl AITHINK_Fn095_PantherJavelin(); // 0x005E1080
extern "C" void __cdecl AITHINK_Fn096_FetishBlowgun(); // 0x005E1250
extern "C" void __cdecl AITHINK_Fn097_Spirit(); // 0x005E3840
extern "C" void __cdecl AITHINK_Fn098_Smith(); // 0x005E3890
extern "C" void __cdecl AITHINK_Fn099_TrappedSoul(); // 0x005E9F10
extern "C" void __cdecl sub_005E7F50(); // 0x005E7F50
extern "C" void __cdecl AITHINK_InitializeAssassinSentry(); // 0x005EA290
extern "C" void __cdecl AITHINK_Fn101_AssassinSentry(); // 0x005EA3D0
extern "C" void __cdecl AITHINK_InitializeBladeCreeper(); // 0x005EA510
extern "C" void __cdecl AITHINK_Fn102_BladeCreeper(); // 0x005EA540
extern "C" void __cdecl AITHINK_Fn103_InvisoPet(); // 0x005EA7A0
extern "C" void __cdecl sub_005EA980(); // 0x005EA980
extern "C" void __cdecl AITHINK_InitializeShadowWarrior(); // 0x005EAF50
extern "C" void __cdecl AITHINK_Fn105_ShadowWarrior(); // 0x005EAFA0
extern "C" void __cdecl AITHINK_InitializeShadowMaster(); // 0x005EB490
extern "C" void __cdecl sub_005EB970(); // 0x005EB970
extern "C" void __cdecl AITHINK_InitializeRaven(); // 0x005ECB70
extern "C" void __cdecl AITHINK_Fn107_Raven(); // 0x005ECC10
extern "C" void __cdecl AITHINK_Fn108_DruidWolf(); // 0x005ED710
extern "C" void __cdecl AITHINK_Fn109_Totem(); // 0x005ED9E0
extern "C" void __cdecl AITHINK_InitializeVineState(); // 0x005EC6A0
extern "C" void __cdecl AITHINK_Fn110_Vines(); // 0x005EC6C0
extern "C" void __cdecl AITHINK_Fn111_CycleOfLife(); // 0x005EC8C0
extern "C" void __cdecl AITHINK_Fn112_DruidBear(); // 0x005ED730
extern "C" void __cdecl AITHINK_Fn113_SiegeTower(); // 0x005E1860
extern "C" void __cdecl AITHINK_Fn114_ReanimatedHorde(); // 0x005E1540
extern "C" void __cdecl AITHINK_Fn115_SiegeBeast(); // 0x005E1900
extern "C" void __cdecl AITHINK_Fn116_Minion(); // 0x005E1B60
extern "C" void __cdecl sub_005E1D30(); // 0x005E1D30
extern "C" void __cdecl AITHINK_Fn118_Succubus(); // 0x005E1E00
extern "C" void __cdecl AITHINK_Fn119_SuccubusWitch(); // 0x005E2120
extern "C" void __cdecl AITHINK_Fn120_Overseer(); // 0x005E27A0
extern "C" void __cdecl AITHINK_Fn121_MinionSpawner(); // 0x005E2BD0
extern "C" void __cdecl AITHINK_InitializeImpMountTarget(); // 0x005E2FD0
extern "C" void __cdecl sub_005E2FF0(); // 0x005E2FF0
extern "C" void __cdecl AITHINK_Fn123_Catapult(); // 0x005E34C0
extern "C" void __cdecl sub_005E3530(); // 0x005E3530
extern "C" void __cdecl AITHINK_Fn125_BloodLord(); // 0x005E36F0
extern "C" void __cdecl sub_005EE5D0(); // 0x005EE5D0
extern "C" void __cdecl AITHINK_InitializeGenericSpawner(); // 0x005E6190
extern "C" void __cdecl AITHINK_Fn129_GenericSpawner(); // 0x005E61B0
extern "C" void __cdecl sub_005EE3C0(); // 0x005EE3C0
extern "C" void __cdecl AITHINK_Fn133_Ancient(); // 0x005EF1A0
extern "C" void __cdecl AITHINK_Fn135_BaalCrab(); // 0x005FCFE0
extern "C" void __cdecl AIBAAL_RunSpecialAiState(); // 0x005FCF30
extern "C" void __cdecl AITHINK_Fn136_BaalTaunt(); // 0x005EF710
extern "C" void __cdecl AITHINK_Fn137_PutridDefiler(); // 0x005EFA90
extern "C" void __cdecl AITHINK_Fn138_BaalToStairs(); // 0x005EF620
extern "C" void __cdecl sub_005EF820(); // 0x005EF820
extern "C" void __cdecl AITHINK_Fn140_BaalCrabClone(); // 0x005FD210
extern "C" void __cdecl AITHINK_Fn141_BaalMinion(); // 0x005EF910
extern "C" void __cdecl AITHINK_Fn142_ClawViperEx(); // 0x005F1DE0
extern "C" void __cdecl AITHINK_InitializeShadowMasterAttackSkills(); // 0x005EB5C0
extern "C" void __cdecl AITHINK_Fn144_UberIzual(); // 0x005F8C80
extern "C" void __cdecl AITHINK_Fn145_UberBaal(); // 0x005FD200
extern "C" void __cdecl AITHINK_Fn146_UberMephisto(); // 0x005F81C0
extern "C" void __cdecl AITHINK_Fn147_UberDiablo(); // 0x005E9DF0
extern "C" void __cdecl AITHINK_InitializeFormationOffsets(); // 0x005E5730
extern "C" void __cdecl sub_005E5870(); // 0x005E5870
extern "C" void __cdecl AITHINK_SpecialState06_HireableNonPlayerOwner(); // 0x005E7C10
extern "C" void __cdecl AITHINK_SpecialState08_TownRogue(); // 0x005E7DC0
extern "C" void __cdecl sub_005E7F80(); // 0x005E7F80
extern "C" void __cdecl AITHINK_SpecialState10_17_DimVision(); // 0x005E8020
extern "C" void __cdecl sub_005E80E0(); // 0x005E80E0
extern "C" void __cdecl sub_005E8140(); // 0x005E8140
extern "C" void __cdecl sub_005E8340(); // 0x005E8340
extern "C" void __cdecl AITHINK_SpecialState13_Countess(); // 0x005E5C50
extern "C" void __cdecl AITHINK_SpecialState14_AttackOrApproach(); // 0x005E2610
extern "C" void __cdecl AITHINK_InitializeMountedImpSkills(); // 0x005E2CD0
extern "C" void __cdecl sub_005E2D80(); // 0x005E2D80
extern "C" void __cdecl AITHINK_Fn130_DeathMauler(); // 0x005EE260
extern "C" void __cdecl AITHINK_Fn127_NpcBarb(); // 0x005EDC50
extern "C" void __cdecl sub_005EDC40_Nop(); // 0x005EDC40
extern "C" void __cdecl sub_005EE5C0_Nop(); // 0x005EE5C0
extern "C" void __cdecl sub_005EF310_Nop(); // 0x005EF310

#pragma pack(push, 1)
struct d2data_0073C9DC_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_0073C9DC_t gData_0073C9DC; // 0x0073C9DC

extern "C" struct d2data_0073C9DC_t gData_0073C9DC = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x0073C9DC

extern D2AiTableStrc gaAiTable[148] = {
    { 0, 0, (AiFn)&AITHINK_Fn000 },
    { 0, 0, (AiFn)&AITHINK_Fn001_100_Idle_Buffy },
    { 1, 0, (AiFn)&AITHINK_Fn002_Skeleton },
    { 1, 0, (AiFn)&AITHINK_Fn003_Zombie },
    { 1, 0, (AiFn)&AITHINK_Fn004_Bighead },
    { 1, 0, (AiFn)&AITHINK_Fn005_BloodHawk },
    { 1, 0, (AiFn)&AITHINK_Fn006_Fallen },
    { 1, 0, (AiFn)&AITHINK_Fn007_Brute },
    { 1, 0, (AiFn)&sub_005F0700 },
    { 1, 0, (AiFn)&AITHINK_Fn009_Wraith },
    { 1, 0, (AiFn)&AITHINK_Fn010_CorruptRogue },
    { 1, 0, (AiFn)&AITHINK_Fn011_Baboon },
    { 1, 0, (AiFn)&AITHINK_Fn012_019_Goatman_Swarm },
    { 1, 0, (AiFn)&AITHINK_Fn013_FallenShaman },
    { 1, 0, (AiFn)&AITHINK_Fn014_QuillRat },
    { 4, 0, (AiFn)&AITHINK_Fn015_SandMaggot, (AiFn)&AITHINK_SpecialFn015_SandMaggot },
    { 1, 0, (AiFn)&AITHINK_Fn016_ClawViper },
    { 1, 0, (AiFn)&AITHINK_Fn017_SandLeaper },
    { 1, 0, (AiFn)&AITHINK_Fn018_PantherWoman },
    { 1, 0, (AiFn)&sub_005F2460_AiThink },
    { 1, 0, (AiFn)&AITHINK_Fn020_Scarab },
    { 1, 0, (AiFn)&AITHINK_Fn021_Mummy },
    { 1, 0, (AiFn)&sub_005F2B10 },
    { 1, 0, (AiFn)&sub_005F3170 },
    { 1, 0, (AiFn)&AITHINK_Fn024_Mosquito },
    { 1, 0, (AiFn)&AITHINK_Fn025_Willowisp },
    { 1, 0, (AiFn)&AITHINK_Fn026_Arach },
    { 1, 0, (AiFn)&AITHINK_Fn027_ThornHulk },
    { 1, 0, (AiFn)&sub_005F4A70 },
    { 1, 0, (AiFn)&AITHINK_Fn029_BatDemon, (AiFn)&AITHINK_BatDemon_HandleSpecialAiState },
    { 1, 0, (AiFn)&sub_005F53E0 },
    { 0, 0, (AiFn)&AITHINK_Fn031_NpcOutOfTown },
    { 0, 0, (AiFn)&AITHINK_Fn032_Npc },
    { 1, 0, (AiFn)&AITHINK_Fn033_HellMeteor },
    { 1, 0, (AiFn)&AITHINK_Fn034_Andariel },
    { 1, 0, (AiFn)&AITHINK_Fn035_CorruptArcher },
    { 1, 0, (AiFn)&AITHINK_Fn036_CorruptLancer },
    { 1, 0, (AiFn)&AITHINK_Fn037_SkeletonBow },
    { 1, 0, (AiFn)&AITHINK_Fn038_MaggotLarva },
    { 1, 0, (AiFn)&AITHINK_Fn039_PinHead },
    { 1, 0, (AiFn)&AITHINK_Fn040_MaggotEgg },
    { 0, 0, (AiFn)&AITHINK_Fn041_Towner },
    { 0, 0, (AiFn)&AITHINK_Fn042_Vendor },
    { 1, (AiFn)&sub_005F6630_InitAiParamsFrame, (AiFn)&AITHINK_Fn043_FoulCrowNest },
    { 1, 0, (AiFn)&AITHINK_Fn044_Duriel },
    { 1, (AiFn)&sub_005F6630_InitAiParamsFrame, (AiFn)&AITHINK_Fn045_Sarcophagus },
    { 1, 0, (AiFn)&AITHINK_Fn046_ElementalBeast },
    { 1, 0, (AiFn)&AITHINK_Fn047_FlyingScimitar },
    { 1, 0, (AiFn)&AITHINK_Fn048_ZakarumZealot },
    { 1, 0, (AiFn)&AITHINK_Fn049_ZakarumPriest },
    { 1, 0, (AiFn)&sub_005F78B0 },
    { 1, 0, (AiFn)&AITHINK_Fn051_Diablo, (AiFn)&AITHINK_ResetAiAndPreserveHomeCommand },
    { 5, 0, (AiFn)&AITHINK_Fn052_FrogDemon, (AiFn)&sub_005F81D0 },
    { 1, 0, (AiFn)&AITHINK_Fn053_Summoner },
    { 0, 0, (AiFn)&AITHINK_Fn054_NpcStationary },
    { 1, 0, (AiFn)&AITHINK_Fn055_Izual },
    { 2, 0, (AiFn)&AITHINK_Fn056_Tentacle },
    { 2, 0, (AiFn)&sub_005F9270 },
    { 0, 0, (AiFn)&AITHINK_Fn058_Navi },
    { 1, (AiFn)&AITHINK_ResetBloodRavenReturnState, (AiFn)&AITHINK_Fn059_BloodRaven },
    { 0, 0, (AiFn)&AITHINK_Fn060_GoodNpcRanged },
    { 0, 0, (AiFn)&sub_005E52D0, (AiFn)&sub_005E5280 },
    { 1, 0, (AiFn)&AITHINK_Fn062_TownRogue },
    { 1, 0, (AiFn)&sub_005F9490 },
    { 1, 0, (AiFn)&AITHINK_Fn064_SkeletonMage },
    { 1, 0, (AiFn)&AITHINK_Fn065_FetishShaman, (AiFn)&sub_005F9950 },
    { 0, 0, (AiFn)&AITHINK_Fn066_SandMaggotQueen },
    { 0, 0, (AiFn)&AITHINK_Fn067_NecroPet },
    { 1, 0, (AiFn)&AITHINK_Fn068_VileMother },
    { 1, 0, (AiFn)&AITHINK_Fn069_VileDog },
    { 1, 0, (AiFn)&AITHINK_Fn070_FingerMage },
    { 1, 0, (AiFn)&sub_005FA710 },
    { 1, 0, (AiFn)&AITHINK_Fn072_DoomKnight },
    { 1, 0, (AiFn)&AITHINK_Fn073_AbyssKnight },
    { 1, 0, (AiFn)&AITHINK_Fn074_OblivionKnight },
    { 1, 0, (AiFn)&AITHINK_Fn075_QuillMother },
    { 1, 0, (AiFn)&AITHINK_Fn076_EvilHole },
    { 2, 0, (AiFn)&AITHINK_Fn077_TrapMissile },
    { 1, 0, (AiFn)&AITHINK_Fn078_TrapRightArrow },
    { 1, 0, (AiFn)&AITHINK_Fn079_TrapLeftArrow },
    { 2, 0, (AiFn)&sub_005FB900 },
    { 0, 0, (AiFn)&AITHINK_Fn081_JarJar },
    { 1, 0, (AiFn)&sub_005E0160 },
    { 0, 0, (AiFn)&AITHINK_Fn083_MosquitoNest },
    { 0, (AiFn)&AITHINK_InitializeBoneWallLifetime, (AiFn)&AITHINK_Fn084_BoneWall },
    { 1, 0, (AiFn)&AITHINK_Fn085_HighPriest },
    { 2, 0, (AiFn)&AITHINK_Fn086_Hydra },
    { 1, 0, (AiFn)&AITHINK_Fn087_TrapMelee },
    { 1, 0, (AiFn)&AITHINK_Fn088_7TIllusion },
    { 1, 0, (AiFn)&AITHINK_Fn089_Megademon },
    { 1, 0, (AiFn)&AITHINK_Fn090_Griswold },
    { 1, 0, (AiFn)&AITHINK_Fn091_DarkWanderer },
    { 1, 0, (AiFn)&sub_005FB9B0 },
    { 1, 0, (AiFn)&AITHINK_Fn093_ArcaneTower },
    { 1, 0, (AiFn)&AITHINK_Fn094_DesertTurret },
    { 1, 0, (AiFn)&AITHINK_Fn095_PantherJavelin },
    { 1, 0, (AiFn)&AITHINK_Fn096_FetishBlowgun },
    { 1, 0, (AiFn)&AITHINK_Fn097_Spirit },
    { 1, 0, (AiFn)&AITHINK_Fn098_Smith },
    { 1, 0, (AiFn)&AITHINK_Fn099_TrappedSoul },
    { 0, 0, (AiFn)&sub_005E7F50 },
    { 0, (AiFn)&AITHINK_InitializeAssassinSentry, (AiFn)&AITHINK_Fn101_AssassinSentry },
    { 0, (AiFn)&AITHINK_InitializeBladeCreeper, (AiFn)&AITHINK_Fn102_BladeCreeper },
    { 0, 0, (AiFn)&AITHINK_Fn103_InvisoPet },
    { 0, (AiFn)&AITHINK_InitializeAssassinSentry, (AiFn)&sub_005EA980 },
    { 2, (AiFn)&AITHINK_InitializeShadowWarrior, (AiFn)&AITHINK_Fn105_ShadowWarrior },
    { 2, (AiFn)&AITHINK_InitializeShadowMaster, (AiFn)&sub_005EB970 },
    { 2, (AiFn)&AITHINK_InitializeRaven, (AiFn)&AITHINK_Fn107_Raven },
    { 0, 0, (AiFn)&AITHINK_Fn108_DruidWolf },
    { 0, 0, (AiFn)&AITHINK_Fn109_Totem },
    { 2, (AiFn)&AITHINK_InitializeVineState, (AiFn)&AITHINK_Fn110_Vines },
    { 2, (AiFn)&AITHINK_InitializeVineState, (AiFn)&AITHINK_Fn111_CycleOfLife },
    { 0, 0, (AiFn)&AITHINK_Fn112_DruidBear },
    { 1, 0, (AiFn)&AITHINK_Fn113_SiegeTower },
    { 1, 0, (AiFn)&AITHINK_Fn114_ReanimatedHorde },
    { 1, 0, (AiFn)&AITHINK_Fn115_SiegeBeast },
    { 1, 0, (AiFn)&AITHINK_Fn116_Minion },
    { 1, 0, (AiFn)&sub_005E1D30 },
    { 1, 0, (AiFn)&AITHINK_Fn118_Succubus },
    { 1, 0, (AiFn)&AITHINK_Fn119_SuccubusWitch },
    { 1, 0, (AiFn)&AITHINK_Fn120_Overseer },
    { 1, (AiFn)&sub_005F6630_InitAiParamsFrame, (AiFn)&AITHINK_Fn121_MinionSpawner },
    { 1, (AiFn)&AITHINK_InitializeImpMountTarget, (AiFn)&sub_005E2FF0 },
    { 1, 0, (AiFn)&AITHINK_Fn123_Catapult },
    { 1, 0, (AiFn)&sub_005E3530 },
    { 1, 0, (AiFn)&AITHINK_Fn125_BloodLord },
    { 1, 0, (AiFn)&AITHINK_Fn126_CatapultSpotter },
    { 2, (AiFn)&sub_005EDC40_Nop, (AiFn)&AITHINK_Fn127_NpcBarb },
    { 2, (AiFn)&sub_005EE5C0_Nop, (AiFn)&sub_005EE5D0, (AiFn)&sub_005E5280 },
    { 1, (AiFn)&AITHINK_InitializeGenericSpawner, (AiFn)&AITHINK_Fn129_GenericSpawner },
    { 1, 0, (AiFn)&AITHINK_Fn130_DeathMauler },
    { 2, 0, (AiFn)&sub_005EE3C0 },
    { 0, 0, (AiFn)&AITHINK_Fn132_AncientStatue },
    { 2, 0, (AiFn)&AITHINK_Fn133_Ancient },
    { 2, (AiFn)&sub_005EF310_Nop, (AiFn)&AITHINK_Fn134_BaalThrone },
    { 0, 0, (AiFn)&AITHINK_Fn135_BaalCrab, (AiFn)&AIBAAL_RunSpecialAiState },
    { 1, 0, (AiFn)&AITHINK_Fn136_BaalTaunt },
    { 1, 0, (AiFn)&AITHINK_Fn137_PutridDefiler },
    { 1, 0, (AiFn)&AITHINK_Fn138_BaalToStairs },
    { 1, 0, (AiFn)&sub_005EF820 },
    { 0, 0, (AiFn)&AITHINK_Fn140_BaalCrabClone, (AiFn)&AIBAAL_RunSpecialAiState },
    { 1, 0, (AiFn)&AITHINK_Fn141_BaalMinion },
    { 1, 0, (AiFn)&AITHINK_Fn142_ClawViperEx },
    { 2, (AiFn)&AITHINK_InitializeShadowMasterAttackSkills, (AiFn)&sub_005EB970 },
    { 1, 0, (AiFn)&AITHINK_Fn144_UberIzual },
    { 1, 0, (AiFn)&AITHINK_Fn145_UberBaal, (AiFn)&AIBAAL_RunSpecialAiState },
    { 1, 0, (AiFn)&AITHINK_Fn146_UberMephisto },
    { 1, 0, (AiFn)&AITHINK_Fn147_UberDiablo, (AiFn)&AITHINK_ResetAiAndPreserveHomeCommand }
}; // 0x0073CA18

extern D2AiTableStrc gaSpecialAiStateTable[18] = {
    { 0 },
    { 0, 0, (AiFn)&AITHINK_Fn001_100_Idle_Buffy },
    { 1, 0, (AiFn)&D2GAME_AI_SpecialState02 },
    { 1, (AiFn)&AITHINK_InitializeFormationOffsets, (AiFn)&sub_005E5870 },
    { 0, 0, (AiFn)&sub_005E52D0, (AiFn)&sub_005E5280 },
    { 0, 0, (AiFn)&AITHINK_Fn060_GoodNpcRanged },
    { 0, 0, (AiFn)&AITHINK_SpecialState06_HireableNonPlayerOwner },
    { 0, 0, (AiFn)&AITHINK_Fn067_NecroPet },
    { 1, 0, (AiFn)&AITHINK_SpecialState08_TownRogue },
    { 1, 0, (AiFn)&sub_005E7F80 },
    { 1, 0, (AiFn)&AITHINK_SpecialState10_17_DimVision },
    { 1, (AiFn)&sub_005E80E0, (AiFn)&sub_005E8140 },
    { 0, 0, (AiFn)&sub_005E8340 },
    { 1, 0, (AiFn)&AITHINK_SpecialState13_Countess },
    { 1, 0, (AiFn)&AITHINK_SpecialState14_AttackOrApproach },
    { 1, 0, (AiFn)&sub_005E1D30 },
    { 1, (AiFn)&AITHINK_InitializeMountedImpSkills, (AiFn)&sub_005E2D80 },
    { 2, 0, (AiFn)&AITHINK_SpecialState10_17_DimVision }
}; // 0x0073D358

extern const char* gaszLanguageNames_0073D478[15] = { "English", "Spanish", "German", "French", "Portuguese", "Italian", "Japanese", "Korean", "Simplified Chinese", "Traditional Chinese", "Polish", "Russian", "English with Korean Chat", "Unknown", "14" }; // 0x0073D478
