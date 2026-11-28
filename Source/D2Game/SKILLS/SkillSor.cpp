#include "D2GameEvents.h"
#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"
#include "D2LanguageNames.h"
#include "D2CommonApi.h"
struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2UnitStrc;
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

#include "D2GameFuncs.h"
#include "D2CommonApi3.h"

enum D2C_F39Constants
{
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_SUCCESSFULHIT = 1,
    DAMAGERESULTFLAG_WILLDIE = 2,
    SKILLSFLAGINDEX_01 = 1,
    UNITFLAG_NOTC = 0x20000,
    STATLIST_FLAG_8 = 8,
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
D2MissilesTxt* __fastcall sub_0046ACE0_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0
void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0
int __fastcall D2GAME_RollElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0
D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0
int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0056E620
int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90
int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0
void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int nUnused); // 0x00621E40
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0
int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20

struct D2MonStatsTxt;

struct D2MonStats2Txt;


static void SKILLS_StopInferno(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C8C10

inline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);


void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

extern "C" void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0


inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005C8BF0
void __fastcall SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }
}

// 0x005C8C10
static void SKILLS_StopInferno(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nInfernoLength = 1;
    STATES_ToggleState(pUnit, 12, 0);
    D2GAME_EVENTS_Delete(pGame, pUnit, 0, 0);

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(!pUnit ? -1 : pUnit->dwClassId);
    if (pMonStats2TxtRecord)
    {
        nInfernoLength = pMonStats2TxtRecord->nInfernoLen;
    }

    EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + nInfernoLength, 0, 0);
}

// 0x005C8CA0
int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    int nX;
    int nY;
    if (!pSkillsTxtRecord || nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetParam1(pSkill))
    {
        int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.nMissile = nMissileId;
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.dwFlags = 0x8020;
        missileParams.pOwner = pUnit;
        missileParams.pOrigin = pUnit;
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        missileParams.nRange = nRange;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    SKILLS_SetParam1(pSkill, 1);

    const bool bIsMonster = pUnit && pUnit->dwUnitType == UNIT_MONSTER;
    if (!bIsMonster)
    {
        SUNIT_RewindAnimationByFrames(pGame, pUnit, 1);
        return 1;
    }

    pUnit->nSeqCurrentFramePrecise = 0xB00;
    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 1, 0);
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + 2, 4, 0);
        return 1;
    }

    SKILLS_StopInferno(pGame, pUnit);
    return 1;
}

// 0x005C8E30
int __fastcall SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (nTimeout < 1)
        {
            nTimeout = 1;
        }

        SKILLS_SetParam1(UNITS_GetUsedSkill(pUnit), nTimeout + pGame->dwGameFrame);
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_INFERNO);
    if (!pStatList)
    {
        const int nExpireFrame = pGame->dwGameFrame + 20;
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_RemoveState);
        STATLIST_SetState(pStatList, STATE_INFERNO);
        STATES_ToggleState(pUnit, 12, 1);
        SKILLS_SetParam1(UNITS_GetUsedSkill(pUnit), 0);
        return 1;
    }

    SUNIT_RewindAnimationByFrames(pGame, pUnit, 1);
    const int nEndFrame = pGame->dwGameFrame + 6;
    D2COMMON_10476(pStatList, nEndFrame);
    EVENT_SetEvent(pGame, pUnit, 12, nEndFrame, 0, 0);
    SKILLS_DoInferno(pGame, pUnit, nSkillId, nSkillLevel, nMissileId);
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

// 0x005C8FA0
int __fastcall SKILLS_SrvSt11_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!STATES_CheckState(pUnit, STATE_INFERNO) && STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < pSkillsTxtRecord->wStartMana << 8)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return SKILLS_StartInferno(pGame, pUnit, nSkillId, nSkillLevel, nMissileId);
}

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0

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

// 0x005C9030
int __fastcall SKILLS_SrvSt12_Telekinesis_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    const int nMaxDistance = nRange * nRange;
    if (PATH_ComputeSquaredDistance(UNITS_GetUnitXPositionInline(pUnit), UNITS_GetUnitYPositionInline(pUnit), UNITS_GetUnitXPositionInline(pTarget), UNITS_GetUnitYPositionInline(pTarget)) > nMaxDistance)
    {
        return 0;
    }

    switch (pTarget->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
        if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
        {
            return 0;
        }
        break;
    }

    return 1;
}


// 0x005C91C0
int __fastcall SKILLS_SrvSt13_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!DATATBLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, -1);
    SKILLS_SetParam2(pSkill, 1);
    return 1;
}

// 0x005C9220
int __fastcall SKILLS_SrvSt14_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pTargetRoom)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(pTargetRoom);
}

enum
{
    PATHINIT_MAX_FRAMES = 78,
    PATHINIT_CAP_FRAMES = 77,
    PATHTYPE_CHARGEDBOLT = 10,
};


void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330


// 0x005C9290
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= PATHINIT_MAX_FRAMES)
    {
        nFrames = PATHINIT_CAP_FRAMES;
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, D2COMMON_10175_PathGetFirstPointX(pPath) + nSeedOffset);
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nFrames);
    D2Common_10142(pPath, pMissile, 0);
}


// 0x005C9300
int __fastcall SKILLS_SrvDo017_ChargedBolt_BoltSentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nMissileCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    for (int i = 0; i < nMissileCount; ++i)
    {
        missileParams.nInitArg = i;
        if (D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY) && missileParams.nTargetX && missileParams.nTargetY)
        {
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }

    return 1;
}

// 0x005C9420
void __fastcall SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

    if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, nState))
    {
        STATES_ToggleState(pUnit, nState, 0);
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillSor.cpp", 425);
        SKILLS_RefreshPassivesAndPetLimits(pUnit);
    }
}


// 0x005C9480
int __fastcall SKILLS_SrvDo018_DefensiveBuff(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    SKILLS_RemoveStatesInGroup(pUnit, pSkillsTxtRecord->nAuraState, 1);

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->nAuraState;
    curse.pStateRemoveCallback = SKILLS_CurseStateCallback_DefensiveBuff;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    SKILLS_ApplyPassiveStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    if (pSkillsTxtRecord->wAuraEvent[0] >= 0)
    {
        SUNITEVENT_Unregister(pGame, pUnit, 1, pSkillsTxtRecord->nAuraState);

        for (int i = 0; i < 3; i += 1)
        {
            if (pSkillsTxtRecord->wAuraEvent[i] < 0)
            {
                break;
            }

            SKILLS_RegisterUnitEvent(pGame, pUnit, pSkillsTxtRecord->wAuraEvent[i], nSkillId, nSkillLevel, pSkillsTxtRecord->wAuraEventFunc[i], 1, pSkillsTxtRecord->nAuraState);
        }
    }

    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);
    return (int)pStatList;
}

// 0x005C9640
int __fastcall SKILLS_SrvDo019_Inferno_ArcticBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return SKILLS_DoInferno(pGame, pUnit, nSkillId, nSkillLevel, nMissileId);
}

// 0x005C96A0
int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender)
{
    D2StaticFieldCallbackArgStrc* pArgs = (D2StaticFieldCallbackArgStrc*)pAuraCallback->pArgs;
    D2UnitStrc* pOwner = pAuraCallback->pOwner;

    const int nHitpoints = STATLIST_UnitGetStatValue(pDefender, STAT_HITPOINTS, 0) >> 8;
    if (nHitpoints < 1)
    {
        return 0;
    }

    if (pArgs->nStaticFieldMin)
    {
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pDefender) >> 8;
        if (nHitpoints <= DATATBLS_ApplyRatio(nMaxLife, pArgs->nStaticFieldMin, 100))
        {
            return 0;
        }
    }

    int nDamage = DATATBLS_ApplyRatio(nHitpoints, pArgs->nDamagePct, 100);
    if (nHitpoints - nDamage < 1)
    {
        nDamage = nHitpoints - 1;
    }

    nDamage <<= 8;
    if (nDamage < pArgs->nMinDamage)
    {
        nDamage = pArgs->nMinDamage;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    int nStatId = -1;
    int nElementalType = pArgs->nElementalType;
    SKILLS_AddElementalDamage(pOwner, &damage, nElementalType, nDamage, pArgs->nElementalLength, &nStatId, &nElementalType);

    if (nStatId >= 0)
    {
        const int nValue = STATLIST_UnitGetStatValue(pDefender, nStatId, 0);
        if (nValue < 0)
        {
            nDamage = DATATBLS_ApplyRatio(nDamage, 100, 100 - nValue);
        }
    }

    memset(&damage, 0, sizeof(damage));
    SKILLS_AddElementalDamage(pOwner, &damage, nElementalType, nDamage, pArgs->nElementalLength, 0, 0);

    damage.dwHitClass |= 0xD;
    damage.nHitClassActiveSet = 1;
    damage.wResultFlags = 0x4001;
    SUNITDMG_ExecuteEvents(pAuraCallback->pGame, pOwner, pDefender, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pAuraCallback->pGame, pOwner, pDefender, &damage);
    return 1;
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

// 0x005C9800
int __fastcall SKILLS_SrvDo020_StaticField(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if (!pDifficultyLevelsTxtRecord)
    {
        return 0;
    }

    D2StaticFieldCallbackArgStrc staticField;
    staticField.nMinDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    staticField.nDamagePct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    staticField.nStaticFieldMin = 0;
    if (pGame->bExpansion)
    {
        staticField.nStaticFieldMin = pDifficultyLevelsTxtRecord->dwStaticFieldMin;
    }

    staticField.nElementalLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    staticField.nElementalType = pSkillsTxtRecord->nEType;

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_StaticField, &staticField, 0, gszSkillSorSourceFile, 627);
    return 1;
}

union D2SeedStrc;

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390


int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380


static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x005C98F0
int __fastcall SKILLS_SrvDo021_Telekinesis(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !pUnit || pUnit->dwUnitType != UNIT_PLAYER || PLAYER_IsBusy(pUnit))
        return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
        return 0;
    pUnit->dwFlags |= 0x40;
    int nItemStatus = 0;
    int nResult;
    const int nTargetType = sub_0044BE50(pTarget);
    switch (nTargetType)
    {
    case 0:
    case 1:
        {
            if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
                return 0;
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
                return 0;
            if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
                return 0;
            int bKnockback = 0;
            if ((int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < SKILLDESC_GetSkillParamTwo(nSkillId))
                bKnockback = 1;
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            D2GAME_RollPhysicalDamage(pUnit, &damage, nSkillId, nSkillLevel);
            D2GAME_RollElementalDamage(pUnit, &damage, nSkillId, nSkillLevel);
            damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
            damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
            if (pSkillsTxtRecord->dwHitClass)
                damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
            if (bKnockback)
                damage.wResultFlags |= 9;
            SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
            SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
            return 1;
        }
    case 4:
        if (!ITEMSIsA(pTarget, 0x16)
            && !ITEMSIsA(pTarget, 4)
            && !ITEMSIsA(pTarget, 0x26)
            && !ITEMSIsA(pTarget, 0x38)
            && !ITEMSIsA(pTarget, 9)
            && !ITEMSIsA(pTarget, 0x29))
        {
            SUNIT_AttachSound(pUnit, 0x13, pUnit);
            return 1;
        }
        D2GAME_PickupItem(pGame, pUnit, sub_00451F50(pTarget), &nItemStatus);
        return 1;
    case 2:
        {
            OBJECTS_OperateHandler(pGame, pUnit, sub_0044BE50(pTarget), sub_00451F50(pTarget), &nResult);
        }
        break;
    }
    return 1;
}


// 0x005C9B50
int __fastcall SKILLS_SrvDo022_NovaAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissileId, nSkillLevel);
    nVelocity += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    SKILLS_CreateMissileRing(pGame, pUnit, pUnit, nMissileId, nSkillId, nSkillLevel, nVelocity);
    return 1;
}

// 0x005C9C10
int __fastcall SKILLS_SrvDo023_Blaze_EnergyShield_SpiderLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nStatValue = 0;
    curse.nState = pSkillsTxtRecord->nAuraState;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    SKILLS_ApplyPassiveStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    if (pSkillsTxtRecord->wAuraEvent[0] >= 0)
    {
        SUNITEVENT_Unregister(pGame, pUnit, 1, pSkillsTxtRecord->nAuraState);

        for (int i = 0; i < 3; i += 1)
        {
            if (pSkillsTxtRecord->wAuraEvent[i] < 0)
            {
                break;
            }

            SKILLS_RegisterUnitEvent(pGame, pUnit, pSkillsTxtRecord->wAuraEvent[i], nSkillId, nSkillLevel, pSkillsTxtRecord->wAuraEventFunc[i], 1, pSkillsTxtRecord->nAuraState);
        }
    }

    return 1;
}

#define STAT_MODIFIERLIST_SKILL 350

#define STAT_MODIFIERLIST_LEVEL 351

// 0x005C9D90
void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit->pDynamicPath || !PATH_HasEnteredNewSubtile(pUnit->pDynamicPath))
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_BLAZE);
    if (!pStatList)
    {
        return;
    }

    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    if (nSkillId <= 0)
    {
        return;
    }

    D2DataTablesStrc* pDataTables = sgptDataTables;
    if (nSkillId >= pDataTables->nSkillsTxtRecordCount)
    {
        return;
    }

    if (nSkillLevel < 0)
    {
        nSkillLevel = 1;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= pDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nMissile = nMissileId;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
}

// 0x005C9EA0
int __fastcall SKILLS_SrvDo024_FireWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !SKILLS_IsMissileTargetPositionClear(pGame, pUnit, nMissileId))
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nX = 0;
    int nY = 0;
    if (pTarget)
    {
        const int nTargetX = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
        nX = nTargetX;
    }
    else
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    }

    if (!nX || !nY)
    {
        return 0;
    }

    D2ActiveRoomStrc* const tArg1 = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(tArg1, nX, nY);
    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));

    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    const int nDiffX = CLIENTS_GetUnitX(pUnit) - nX;
    const int nDiffY = CLIENTS_GetUnitY(pUnit) - nY;

    missileParams.nTargetX = nX - nDiffY;
    missileParams.nTargetY = nY + nDiffX;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    missileParams.nTargetX = nX + nDiffY;
    missileParams.nTargetY = nY - nDiffX;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    const int nMissileB = pSkillsTxtRecord->wSrvMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        missileParams.nTargetX = 0;
        missileParams.nTargetY = 0;
        missileParams.nMissile = nMissileB;
        missileParams.dwFlags = 1;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005CA030
int __fastcall SKILLS_SrvDo025_Enchant(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount
        || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget && !SUNIT_AreUnitsAligned(pGame, pUnit, pTarget))
    {
        pTarget = pUnit;
    }

    if (!pTarget)
    {
        pTarget = pUnit;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->nAuraState;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] >= 0 && pSkillsTxtRecord->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStat(pStatList, pSkillsTxtRecord->wAuraStat[i], nValue, 0);
            }
        }
    }

    STATES_ToggleGfxStateFlag(pTarget, pSkillsTxtRecord->nAuraState, 1);
    return 1;
}

// 0x005CA1B0
int __fastcall SKILLS_SrvDo026_ChainLightning(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nParam);
    return 1;
}

// 0x005CA260
int __fastcall SKILLS_SrvDo151_CreateMissileAtTargetOffset(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nDiffX = 0;
    int nDiffY = 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        nDiffX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        nDiffY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }

    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, nDiffX, nDiffY, 0, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nParam);
    return 1;
}

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

enum D2C_TeleportConstants
{
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};

// 0x005CA360
int __fastcall SKILLS_SrvDo027_Teleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nTargetX, &nTargetY);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    if (pLevelsTxtRecord && pLevelsTxtRecord->nTeleport != 0 && (pLevelsTxtRecord->nTeleport != 2 || !UNITS_TestCollisionByCoordinates(pUnit, nTargetX, nTargetY, COLLIDE_MASK_PLAYER_FLYING)))
    {
        return SUNIT_TeleportUnit(pGame, pUnit, 0, nTargetX, nTargetY, 0, 0);
    }

    return 0;
}

#define UNIT_FLAG 0x40


// 0x005CA3E0
int __fastcall SKILLS_SrvDo028_Meteor_Blizzard_Eruption_BaalTaunt_Catapult(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= UNIT_FLAG;
    if (!SKILLS_IsMissileTargetPositionClear(pGame, pUnit, nMissileId))
        return 0;
    return D2GAME_CreateMissile(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, 0, 0) != 0;
}

struct D2EnergyShieldDataStrc;


extern "C" int __fastcall SKILLS_GetSkillsTxtParam7(int nSkillId); // 0x005C8BC0



struct D2EnergyShieldDataStrc
{
    int nDamageOffset;
    int bPlayerOnly;
};

extern const D2EnergyShieldDataStrc gaEnergyShieldData[8]; // 0x006E30E0

// 0x005CA470
static D2UnitStrc* __stdcall SKILLS_CreateThunderStormBolt(D2GameStrc* pGame, int nMissileId, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pUnit && pTarget && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return D2GAME_CreateMissile(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
    }
    return 0;
}

// 0x005CA4D0
int __fastcall SKILLS_SrvDo029_ThunderStorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState) && !SKILLS_GetParam2(pSkill))
    {
        const int nParam1 = SKILLS_GetParam1(pSkill);
        const int nRange = SKILLS_GetSkillsTxtParam7(nSkillId);
        D2UnitStrc* pTarget = SKILLS_FindNextAuraTarget(pGame, pUnit, 0, 0, nRange, 3, nParam1, 0);
        if (pTarget)
        {
            D2UnitStrc* pMissile = SKILLS_CreateThunderStormBolt(pGame, nMissileId, nSkillId, nSkillLevel, pUnit, pTarget);
            if (pMissile)
            {
                MISSMODE_SrvDmgHitHandler(pGame, pMissile, pTarget, 1);
                SUNIT_RemoveUnit(pGame, pMissile);
                SUNITMSG_QueueSkillEvent(pUnit, pTarget, nSkillId, nSkillLevel, 0, 0, 0);
            }

            SKILLS_SetParam1(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        }
        else
        {
            SKILLS_SetParam1(pSkill, -1);
        }
    }
    else
    {
        D2CurseStrc curse = {};
        curse.pUnit = pUnit;
        curse.pTarget = pUnit;
        curse.nSkill = nSkillId;
        curse.nSkillLevel = nSkillLevel;
        curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
        curse.nStat = -1;
        curse.nStatValue = 0;
        curse.nState = pSkillsTxtRecord->nAuraState;

        D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
        if (pStatList)
        {
            STATLIST_SetStatIfListIsValid(pStatList, 350, nSkillId, 0);
            STATLIST_SetStatIfListIsValid(pStatList, 351, nSkillLevel, 0);
        }
    }

    SKILLS_SetParam2(pSkill, 0);
    return 1;
}

// 0x005CA6C0
int __fastcall SKILLS_EventFunc24_EnergyShield(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
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
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount || !STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }

    const int nMultiplier = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nMultiplier <= 0)
    {
        return 0;
    }

    int nMana = STATLIST_UnitGetStatValue(pAttacker, STAT_MANA, 0);
    int nDivisor = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nDivisor <= 0)
    {
        nDivisor = 1;
    }

    int bIsPlayer = 1;
    if (pUnit && (pUnit->dwUnitType != UNIT_MONSTER || MONSTERS_GetHirelingTypeId(pUnit)))
    {
        bIsPlayer = 0;
    }

    int nAbsorbedDamage = 0;
    for (int i = 0; i < 8; ++i)
    {
        const D2EnergyShieldDataStrc* pEnergyShieldData = &gaEnergyShieldData[i];
        if (!pEnergyShieldData->bPlayerOnly || bIsPlayer)
        {
            int* pDamageValue = (int*)((char*)pDamage + pEnergyShieldData->nDamageOffset);
            const int nDamage = *pDamageValue;
            if (nDamage > 0)
            {
                int nAbsorb = DATATBLS_ApplyRatio(nDamage, nMultiplier, 100);
                const int nMax = DATATBLS_ApplyRatio(nMana, 16, nDivisor);
                if (nAbsorb >= nMax)
                {
                    nAbsorb = nMax;
                }

                nAbsorbedDamage += nAbsorb;
                *pDamageValue = nDamage - nAbsorb;
                nMana -= DATATBLS_ApplyRatio(nAbsorb, nDivisor, 16);
                nMana = nMana > 0 ? nMana : 0;
            }
        }
    }

    nMana = nMana > 0 ? nMana : 0;

    STATLIST_SetUnitStat(pAttacker, STAT_MANA, nMana, 0);

    if (pUnit && nAbsorbedDamage > 0 && pSkillsTxtRecord->wPrgOverlay >= 0 && pSkillsTxtRecord->wPrgOverlay <= sgptDataTables->nOverlayTxtRecordCount)
    {
        const int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pAttacker, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        const int nOffset = INVENTORY_GetEightWayDirection(nDirection);
        UNITS_SetOverlay(pAttacker, pSkillsTxtRecord->wPrgOverlay + nOffset, 0);
    }

    if (nMana <= 0)
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState);
        if (pStatList)
        {
            D2Common_10474(pAttacker, pStatList);
            STATLIST_FreeStatList(pStatList);
            return 1;
        }

        STATES_ToggleState(pAttacker, pSkillsTxtRecord->nAuraState, 0);
    }

    return 1;
}

struct D2SummonArgStrc;

int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620


int __fastcall D2GAME_SetSummonPassiveStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit);                              // 0x00541860

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel);                           // 0x004E6CA0


void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0


// 0x005CA910
int __fastcall SKILLS_SrvDo144_Hydra(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
        return 0;
    int nPetType = (signed char)pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
        return 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit(pGame, pUnit, &nX, &nY))
        return 0;
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        return 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && MONSTERS_GetHirelingTypeId(pUnit))
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
            pUnit = pOwner;
    }
    const int nExpireFrame = pGame->dwGameFrame + SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel);
    D2SummonArgStrc summonArg;
    memset(&summonArg, 0, sizeof(summonArg));
    summonArg.dwFlags |= 1;
    summonArg.pOwner = pUnit;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
    int nResult = 0;
    for (int i = 0; i < 3; i += 1)
    {
        summonArg.nHcIdx = nSummonId + i;
        summonArg.pPosition.nX = nX + gnHydraOffsetX[i];
        summonArg.pPosition.nY = nY + gnHydraOffsetY[i];
        D2UnitStrc* pPet = D2GAME_SummonPet(pGame, &summonArg);
        if (pPet)
        {
            D2GAME_SetSkills(pPet, nSkillId, nSkillLevel, 1);
            D2GAME_SetSummonPassiveStats(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
            nResult = 1;
            D2AiControlStrc* pAiControl = AIGENERAL_GetAiControlFromUnit(pPet);
            if (pAiControl)
                AITHINK_SetAiControlParams(pAiControl, nExpireFrame, -666, -666);
            if (GAME_GetUnitTypeOrInvalid(pUnit) == 1)
                SUNIT_SetAlignment(pPet, STATLIST_GetUnitAlignment(pUnit), 1);
        }
    }
    return nResult;
}

// 0x005CAB40
int __fastcall SKILLS_EventFunc01_ChillingArmor(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (!pOwner || !SUNIT_AreUnitsHostile(pGame, pAttacker, pOwner))
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (nSkillLevel < 0)
    {
        nLevel = 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0_GetMissilesTxtRecord(pUnit->dwClassId);
    if (!(pMissilesTxtRecord->nMissileFlags[MISSILESFLAGINDEX_RETURNFIRE >> 3] & gdwBitMasks[MISSILESFLAGINDEX_RETURNFIRE & 7]))
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pAttacker;
    missileParams.pOrigin = pAttacker;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nTargetX = CLIENTS_GetUnitX(pOwner);
    missileParams.nTargetY = CLIENTS_GetUnitY(pOwner);
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005CAC50
int __fastcall SKILLS_EventFunc02_FrozenArmor(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pDamage && pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel < 0)
    {
        nLevel = 1;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags |= 0x20;
    damage.dwFrzLen = SKILLS_EvaluateSkillFormula(pAttacker, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);

    if (pSkillsTxtRecord->wCltOverlayA >= 0 && pSkillsTxtRecord->wCltOverlayA < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pUnit, pSkillsTxtRecord->wCltOverlayA, 0);
    }

    return 1;
}

// 0x005CAD40
int __fastcall SKILLS_EventFunc03_ShiverArmor(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel < 0)
    {
        nLevel = 1;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollElementalDamage(pAttacker, &damage, nSkillId, nLevel);
    damage.nHitClassActiveSet = 1;
    damage.dwHitClass |= 0xD;
    damage.wResultFlags = 0x4021;
    SUNITDMG_ExecuteEvents(pGame, pAttacker, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, pUnit, &damage);

    if (pSkillsTxtRecord->wCltOverlayA >= 0 && pSkillsTxtRecord->wCltOverlayA < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pUnit, pSkillsTxtRecord->wCltOverlayA, 0);
    }

    return 1;
}

extern "C" const char gszSkillSorSourceFile[22] = ".\\SKILLS\\SkillSor.cpp"; // 0x006E30C4

extern const int gnHydraOffsetY[3] = { -1, 0, -1 }; // 0x006E3120

extern const int gnHydraOffsetX[3] = { -1, 0, 1 }; // 0x006E312C

extern const D2EnergyShieldDataStrc gaEnergyShieldData[8] = {
    { 8 },
    { 16 },
    { 28 },
    { 36 },
    { 32 },
    { 56, 1 },
    { 60, 1 },
    { 64, 1 }
}; // 0x006E30E0
