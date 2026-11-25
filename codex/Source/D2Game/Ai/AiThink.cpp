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

struct D2MonStatsTxt;

struct D2LevelsTxt;

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

int __fastcall AITHINK_GetSquaredDistance(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005B0BD0

int __fastcall AITHINK_TryBossTauntOnSight(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B1140

int __fastcall AITHINK_TryTeleportAway(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005B11F0

int __fastcall AIUTIL_HasClearApproachToTarget(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x005DC640

D2UnitStrc* __fastcall AIUTIL_FindTargetWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg, AITARGETCALLBACK pfnCallback, int nCallbackId); // 0x005DD0B0

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nMaxDistance); // 0x005DE200

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

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

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

__declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*);

int __stdcall STATES_CheckState(D2UnitStrc*,int); // 0x00639DF0

const D2AiTableStrc* __fastcall AITHINK_GetAiTableRecord(D2UnitStrc*,int); // 0x005B15D0

void __fastcall AIGENERAL_FreeAllAiCommands(D2GameStrc*,D2UnitStrc*); // 0x0058EDE0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

void __fastcall AITHINK_Fn001_100_Idle_Buffy(D2GameStrc*,D2UnitStrc*,D2AiTickParamStrc*); // 0x005B0CD0

void __fastcall AITHINK_Fn051_Diablo(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick); // 0x005E9170

void __fastcall AITHINK_Fn126_CatapultSpotter(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EE040

void __fastcall AITHINK_Fn132_AncientStatue(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EEAA0

void __fastcall AITHINK_Fn134_BaalThrone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam); // 0x005EF320

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60

void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190

int __fastcall AITACTICS_UseSkill(D2GameStrc*, D2UnitStrc*, unsigned char, int, D2UnitStrc*, int, int); // 0x005DEAD0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900

int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nState); // 0x005B0E00

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
void __stdcall sub_005B0CC0(int nUnused1)
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

D2UnitStrc* __fastcall AITHINK_TargetCallback_Panther(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, void* pCallbackArg); // 0x005B0D00

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

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

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

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall D2GAME_AICORE_MinionLeash_6FCF0D10(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam); // 0x005B0FF0

int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, unsigned char nMaxDistance); // 0x005DF530

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380

int __fastcall AITACTICS_WalkAwayFromTarget(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0

static inline int CanWalk(D2UnitStrc* pMonster)
{
    return sub_0046C140_TestMonModeFlag(!pMonster ? -1 : pMonster->dwClassId, 2);
}

// 0x005B0FF0
int __fastcall D2GAME_AICORE_MinionLeash_6FCF0D10(D2GameStrc* pGame, D2UnitStrc* pMonster, D2AiTickParamStrc* pAiTickParam)
{
    int nOwnerGUID = 0;
    D2AiControlStrc* pAiControl = pAiTickParam->pAiControl;
    // volatile below only makes pAiControl live in memory (the original spills it, keeping pGame in a register)
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
    D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pMonster, pOwner, 19);
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

    return D2GAME_AICORE_MinionLeash_6FCF0D10(pGame, pUnit, pAiTickParam) != 0;
}

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

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

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20

int __fastcall sub_0054DC40_FindSpawnPosition(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nMonsterId, int* pX, int* pY, int a7); // 0x0054DC40

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

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

// build: symbol ?MONSTERUNIQUE_CheckMonStatsFlag@* 0x00457490
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

// build: symbol ?MONSTERUNIQUE_CheckMonStatsFlag@* 0x00457490
    if (!MONSTERUNIQUE_CheckMonStatsFlag(!pUnit ? -1 : pUnit->dwClassId, 1))
    {
        return 0;
    }

    if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 2))
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

int __fastcall AIUTIL_IsGettingHit(D2UnitStrc* pUnit); // 0x005DD2B0

static inline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005B14E0
void __fastcall D2GAME_AI_SpecialState02_6FCD1660(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pAiTickParam)
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
        D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pTarget, 12);
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

D2UnitStrc* __fastcall AITACTICS_FindTargetOrIdleInNeutralMode(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DE890

D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DD7F0

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
        pAiTickParam->pTarget = sub_6FCF2110(pGame, pUnit, pAiTickParam->pAiControl, &pAiTickParam->nTargetDistance, &pAiTickParam->bCombat);
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
void __fastcall AITHINK_ExecuteMonsterAiTick(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
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

#include "gen/data/Source/D2Game/Ai/AiThink.inc"
