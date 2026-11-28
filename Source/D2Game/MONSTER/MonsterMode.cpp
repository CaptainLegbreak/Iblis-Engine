#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2LevelTxt.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2Drlg.h"
#include "D2MonModes.h"
#include "D2PlayerModes.h"
#include "D2GameAux.h"
#include "D2Packets.h"
#include "D2MonStatsInit.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2PoolSystemStrc;
enum D2C_P08MonsterConstants
{
    MONLVL_DM = 6,
    EVENTTYPE_MONUMOD = 7,
};

typedef void (__fastcall* MonEventFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

extern MonEventFunc const gpMonsterEventFunctions[16];                                                            // 0x006E2490

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId);                       // 0x00451FE0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                            // 0x00553540


#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNITFLAG_NOTC 0x00020000

#define MONSTER_BASEID_63 63

struct D2AiParamStrc;

struct D2MonStatsTxt;

struct D2MonsterDataStrc;

struct D2ModeChangeStrc;

struct D2MonModeCallbackTableStrc;

struct D2Field14Strc;

struct D2MonStats2Txt;

struct D2MonModeInfoTableStrc;

struct D2MonsterModeDataStrc;

struct D2StaticPathStrc;

union D2SeedStrc;

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern const D2MonModeCallbackTableStrc gMonModeCallbacks[]; // 0x006E2260

extern const D2MonModeCallbackTableStrc gDiablo_Skill4_Callbacks; // 0x006E2360

extern const D2MonModeCallbackTableStrc gDiablo_Skill3_Callbacks; // 0x006E2370

extern const D2MonModeCallbackTableStrc gTrappedSoul_Attack_Callbacks; // 0x006E2380

extern const D2MonModeCallbackTableStrc gTrappedSoul_Skill_Callbacks; // 0x006E2390

extern const D2MonModeCallbackTableStrc gShadowMasterWarrior_Skill4_Callbacks; // 0x006E23A0







void __fastcall FOG_FreeServerMemory(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480


struct D2Field14Strc
{
    char unk0x00[0x14];
    int nField14;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2MonModeInfoTableStrc gtMonsterModeEventPolicies[]; // 0x006E23D0

int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange); // 0x005A73E0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

struct D2MonsterModeDataStrc
{
    int unk_00;
    int unk_04;
    int unk_08;
    int unk_0C;
    int unk_10;
    int unk_14;
    int unk_18;
    int unk_1C;
    int unk_20;
};

void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int nZero); // 0x0040B430

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

void __stdcall MONSTERMODE_DropTreasure(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFlag, D2ModeChangeStrc* pModeChange); // 0x005A6600

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60


D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0


void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

struct D2DynamicPathStrc;


#define PATHTYPE_ASTAR 1

#define PATHTYPE_TOWARD 2

#define PATHTYPE_STRAIGHT 7

#define PATHTYPE_LEAP 9

#define PATHTYPE_TOWARD_FINISH 13

#define UNITFLAG_DOUPDATE 0x1

#define UNITFLAG_MONMODEISCHANGING 0x80000

struct D2SuperUniquesTxt;

struct D2DifficultyLevelsTxt;

struct D2AiParamStrc
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned short unk0x02;
    struct D2UnitStrc* pTarget;
    int nX;
    int nY;
    int nVelocityPercent;
    int nTargetTimer;
    int nPathTypeOverride;
    int nVelocityPercentOverride;
    unsigned char nNewDistOverride;
};

typedef int (__fastcall* MonModeStartFunc)(D2GameStrc*, D2ModeChangeStrc*);



void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nUnused); // 0x0057D4F0




int __fastcall MONSTERMODE_CreateMonsterMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nParam); // 0x005A6D50

const D2MonModeCallbackTableStrc* __fastcall MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int nMode); // 0x005A78A0

void __fastcall AIGENERAL_UpdateMinionList(D2UnitStrc* pUnit); // 0x0058F6C0

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520

void __fastcall ITEMS_DropTreasureClassById(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, int nTCId, int nQuality, int nItemLevel, int bIgnoreNoDrop, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems); // 0x0055AFA0


int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __fastcall MONSTERUNIQUE_GetSuperUniqueBossHcIdx(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A03A0

void __stdcall MONSTERMODE_FireMissileVolley(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x005A6B70

void __fastcall MONSTERMODE_HandleEndAnimation(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A8030


static void MONSTERMODE_SetVelocityPercent(D2UnitStrc* pUnit, D2AiParamStrc* pParam);

static void MONSTERMODE_SetAiStateForMode(int nMode, D2UnitStrc* pMonster);

static int MONSTERMODE_IsModeEventEnabled(D2UnitStrc* pUnit, int nMode);

static int __stdcall MONSTERMODE_StartNeutralUnlessDead(D2GameStrc* pGame, int nMode, D2UnitStrc* pUnit);




static void MONSTERMODE_ApplyDeathAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit);

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

struct D2HoverTextStrc;

struct D2ActiveRoomStrc;







static void __stdcall MONSTERMODE_CleanupDeath(int nDirection, D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A6520

int __fastcall MONSTERMODE_StartDead(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange);

void __fastcall MONSTERMODE_TryDropTreasure(D2GameStrc*, D2ModeChangeStrc*, int); // 0x005A6830

void __fastcall sub_00547E50_RemoveMonster(void*, D2UnitStrc*); // 0x00547E50

void __stdcall DUNGEON_SaveKilledUnitGUID(D2ActiveRoomStrc*, int); // 0x0061AFA0



void __stdcall MONSTERMODE_HandleSiegeBeastDeath(D2GameStrc*, D2UnitStrc*); // 0x005A6EB0


int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc*, int); // 0x0045C3E0

int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc*, D2UnitStrc*, int, int, int, D2DamageStrc*, int, int, void*, int); // 0x0057E090


typedef int (__fastcall* MonModeUnitFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit);

struct D2MonModeCallbackTableStrc
{
    MonModeStartFunc pfnStart;
    MonModeUnitFunc pfnUpdate;
    MonModeUnitFunc pfnEnd;
    int bScheduleEvents;
};


#define UNITEVENT_DEATH 13

#define EVENTTYPE_AITHINK 2

struct D2StatListStrc;

struct D2SkillStrc;


extern "C" const char gszMonsterModeSourceFile[];                                                  // 0x006E23B0







static int __stdcall MONSTERMODE_ComputePath(int nPathType, D2AiParamStrc* pAiParam, D2UnitStrc* pUnit, unsigned char nNewDist);

static void __stdcall MONSTERMODE_UpdateModePath(D2GameStrc* pGame, D2UnitStrc* pUnit, int nVelocityPercent, D2AiParamStrc* pAiParam, int nPathType, unsigned char nNewDist);

static inline int MONSTERMODE_IsActionFrame(D2UnitStrc* pUnit);

struct D2MissilesTxt;


extern unsigned char gbModeReset[]; // 0x0073C6D0

typedef void (__fastcall *ModeCallback)(D2GameStrc*, D2UnitStrc*, int, int);


inline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord_Inline(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

inline D2MonsterDataStrc* MONSTER_GetMonsterData_Inline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Static(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline int UNITS_GetXPosition_Static(D2UnitStrc* pUnit)
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

static inline int UNITS_GetYPosition_Static(D2UnitStrc* pUnit)
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


// 0x005A6190
extern "C" __declspec(dllexport) unsigned int __fastcall MONSTERMODE_GetAiParamFromUnit(D2UnitStrc* pUnit) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        return (unsigned int)pUnit->pMonsterData->pAiParam;
    }
    return 0;
}

// 0x005A61B0
static void __stdcall MONSTERMODE_TakeVelocityParams(D2AiParamStrc* pRecord, int* pValueA, int* pValueB, unsigned char* pValueC)
{
    if (pRecord->nPathTypeOverride)
    {
        *pValueA = pRecord->nPathTypeOverride;
    }
    if (pRecord->nVelocityPercentOverride)
    {
        *pValueB = pRecord->nVelocityPercentOverride;
    }
    if (pRecord->nNewDistOverride)
    {
        *pValueC = pRecord->nNewDistOverride;
    }
    pRecord->nPathTypeOverride = 0;
    pRecord->nVelocityPercentOverride = 0;
    pRecord->nNewDistOverride = 0;
}

struct D2DamageStrc;

struct D2GameStrc;

struct D2UnitStrc;

// 0x005A6250
int* __fastcall MONSTERMODE_GetTargetTimerPtr(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

#define AIPARAM_MAX_STEPS 77

// 0x005A6260
void __fastcall MONSTERMODE_SetVelocityParams(D2AiParamStrc* pAiParam, int nParam18, int nParam1C, unsigned char nParam20)
{
    if (nParam18)
    {
        pAiParam->nPathTypeOverride = nParam18;
    }

    if (nParam1C)
    {
        pAiParam->nVelocityPercentOverride = nParam1C;
    }

    if (nParam20)
    {
        if (nParam20 >= AIPARAM_MAX_STEPS + 1)
        {
            nParam20 = AIPARAM_MAX_STEPS;
        }

        pAiParam->nNewDistOverride = nParam20;
    }
}

// 0x005A6290
static int __stdcall MONSTERMODE_ComputePath(int nPathType, D2AiParamStrc* pAiParam, D2UnitStrc* pUnit, unsigned char nNewDist)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    PATH_SetNewDistance(pPath, nNewDist);

    D2UnitStrc* pTarget = PATH_GetTargetUnit(pPath);
    const int nX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    if (pTarget != pAiParam->pTarget || nX != pAiParam->nX || nY != pAiParam->nY)
    {
        pAiParam->pTarget = pTarget;
        pAiParam->nX = nX;
        pAiParam->nY = nY;
        pAiParam->unk0x00 = 0;
        pAiParam->unk0x01 = 0;
    }

    PATH_SetType(pPath, nPathType);
    D2Common_10142(pPath, pUnit, 0);

    if (PATH_GetNumberOfPathPoints(pPath))
    {
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
        pAiParam->unk0x00 = 0;
        pAiParam->unk0x01 = 0;
        return nPathType;
    }

    switch (nPathType)
    {
    case PATHTYPE_TOWARD:
    case PATHTYPE_STRAIGHT:
    case PATHTYPE_LEAP:
    case PATHTYPE_TOWARD_FINISH:
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_DOUPDATE;
        PATH_SetType(pPath, PATHTYPE_WALL_FOLLOW);
        D2Common_10142(pPath, pUnit, 0);
        return PATHTYPE_WALL_FOLLOW;
    }

    return nPathType;
}

// 0x005A6380
static void MONSTERMODE_SetVelocityPercent(D2UnitStrc* pUnit, D2AiParamStrc* pParam)
{
    const int nVelocityPercent = pParam->nVelocityPercent;
    if (!nVelocityPercent)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x4000);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0x4004, 0, UNIT_MONSTER, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return;
        }

        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    }

    STATLIST_SetStatValue(pStatList, STAT_VELOCITYPERCENT, nVelocityPercent, 0);
    UnitUpdateAnimRateAndVel(pUnit, ".\\MONSTER\\MonsterMode.cpp", 269);
}

// 0x005A63F0
static void __stdcall MONSTERMODE_UpdateModePath(D2GameStrc* pGame, D2UnitStrc* pUnit, int nVelocityPercent, D2AiParamStrc* pAiParam, int nPathType, unsigned char nNewDist)
{
    MONSTERMODE_TakeVelocityParams(pAiParam, &nPathType, &nVelocityPercent, &nNewDist);

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    int nTargetTimer = -1;
    int nNewPathType = 0;
    if (nPathType == 100)
    {
        nNewPathType = 0;
        nVelocityPercent = 0;
    }
    else
    {
        if (!nNewDist)
        {
            nNewDist = 5;
        }

        if (nPathType == 101)
        {
            nPathType = PATHTYPE_TOWARD_FINISH;
        }

        nNewPathType = MONSTERMODE_ComputePath(nPathType, pAiParam, pUnit, nNewDist);
        if (nNewPathType != PATHTYPE_ASTAR && PATH_GetTargetUnit(pPath))
        {
            nTargetTimer = 10;
        }
    }

    pAiParam->nTargetTimer = nTargetTimer;
    pAiParam->nVelocityPercent = nVelocityPercent;

    ++pGame->dwPathTypesCount[nNewPathType];
    if (nNewPathType)
    {
        ++pGame->nTotalPathTypesCount;
    }
}


// 0x005A6490
D2MonsterModeDataStrc* __fastcall MONSTERMODE_AllocParams(D2GameStrc* pGame)
{
    D2MonsterModeDataStrc* pData = (D2MonsterModeDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2MonsterModeDataStrc), ".\\MONSTER\\MonsterMode.cpp", 319, 0);
    memset(pData, 0, sizeof(D2MonsterModeDataStrc));
    return pData;
}

// 0x005A64D0
void __fastcall D2GAME_MONSTERMODE_FreeParams(D2GameStrc* pGame, D2AiParamStrc* pAiParam)
{
    FOG_FreeServerMemory(pGame->pMemoryPool, pAiParam, ".\\MONSTER\\MonsterMode.cpp", 327, 0);
}

// 0x005A64F0
static inline int MONSTERMODE_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == MONMODE_SEQUENCE)
    {
        return (pUnit->dwFlags >> 6) & 1;
    }

    if (pUnit->nActionFrame == 1)
    {
        return 1;
    }

    return 0;
}

inline D2MonStatsTxt* GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nId = pUnit->dwClassId;
        if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nId];
        }
    }
    return 0;
}

// 0x005A6520
static void __stdcall MONSTERMODE_CleanupDeath(int nDirection, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= 0x100;
    }

    AIGENERAL_UpdateMinionList(pUnit);
    D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pUnit);
    TARGETS_RemoveUnitNode(pGame, pUnit);
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFF7FF3;
    }

    D2Common_10469(pUnit);
    STATES_UpdateStayDeathFlags(pUnit, MONSTERS_IsBoss(pMonStatsTxtRecord, pUnit));
    if (STATES_CheckStateMaskHideOnUnit(pUnit) && pUnit)
    {
        pUnit->dwFlags &= ~2;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, 0x13))
    {
        PATH_SetUnitDeadCollision(pUnit, 1);
    }

    sub_006488A0_SetDirection(pPath, nDirection);
    MONSTER_DeleteEvents(pGame, pUnit);
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005A68E0
static void MONSTERMODE_SetAiStateForMode(int nMode, D2UnitStrc* pMonster)
{
    const int nAiState = MONSTER_GetAiState(pMonster);
    if (nAiState >= 16)
    {
        nMode = nAiState - 16;
    }
    else if (nAiState == 13 && nMode == 3)
    {
        nMode = nAiState;
    }

    MONSTER_SetAiState(pMonster, nMode);
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A6830
void __fastcall MONSTERMODE_TryDropTreasure(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int nUnused)
{
    D2UnitStrc* hUnit = pModeChange->pUnit;
    D2_ASSERT(hUnit, 493);

    if (UNIT_HasFlag(hUnit, UNITFLAG_NOTC))
    {
        return;
    }

    D2_ASSERT(hUnit->dwClassId != MONSTER_BONEWALL, 504);

    if (!COLLISION_CheckMask(UNITS_GetRoom(hUnit), CLIENTS_GetUnitX(hUnit), CLIENTS_GetUnitY(hUnit), 0x801))
    {
        D2ActiveRoomStrc* hRoom = UNITS_GetRoom(hUnit);
        D2_ASSERT(hRoom, 511);

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(hUnit->dwClassId);
        D2_ASSERT(pMonStatsTxtRecord, 516);

        MONSTERMODE_DropTreasure(pGame, hUnit, 0, pModeChange);
    }
}

// 0x005A6600
void __stdcall MONSTERMODE_DropTreasure(D2GameStrc* pGame, D2UnitStrc* hUnit, int bIgnoreNoDrop, D2ModeChangeStrc* pModeChange)
{
    D2_ASSERT(hUnit, 404);

    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(hUnit);
    D2_ASSERT(hRoom, 406);

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(hRoom);
    DRLG_GetActNoFromLevelId(nLevelId);

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(hUnit->dwClassId);
    D2_ASSERT(pMonStatsTxtRecord, 410);

    const int nDifficulty = pGame->nDifficulty;
    int nTCId;
    const int nItemLevel = ITEMS_GetItemLevelForNewItem(hUnit, nLevelId);
    const int nSuperUniqueId = MONSTERUNIQUE_GetSuperUniqueBossHcIdx(pGame, hUnit);
    if (nSuperUniqueId != -1)
    {
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(nSuperUniqueId);
        if (!pSuperUniquesTxtRecord)
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][2];
        }
        else
        {
            nTCId = pSuperUniquesTxtRecord->wTC[nDifficulty];
        }
    }
    else
    {
        if (MONSTERUNIQUE_CheckMonTypeFlag(hUnit, 4))
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][1];
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(hUnit, 8))
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][2];
        }
        else
        {
            nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][0];
        }
    }

    if (pMonStatsTxtRecord->nTCQuestId > 0 && pMonStatsTxtRecord->wTreasureClass[nDifficulty][3] > 0 && pModeChange)
    {
        D2UnitStrc* pTarget = pModeChange->pTargetUnit;
        if (pTarget)
        {
            if (pTarget->dwUnitType != UNIT_PLAYER)
            {
                D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pTarget);
                if (STATES_CheckStateMaskExpOnUnit(pTarget))
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pTarget, 0x800);
                    if (pStatList)
                    {
                        const int nOwnerType = STATLIST_GetOwnerType(pStatList);
                        const int nOwnerGUID = STATLIST_GetOwnerGUID(pStatList);
                        pOwner = SUNIT_GetServerUnit(pGame, nOwnerType, nOwnerGUID);
                    }
                }

                if (pOwner)
                {
                    pTarget = pOwner;
                }
            }

            if (pTarget && pTarget->dwUnitType == UNIT_PLAYER)
            {
                D2BitBufferStrc* pQuestFlags = sub_00543520(pGame, pTarget);
                if (pQuestFlags && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, 15) != 1
                    && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, 1) != 1
                    && QUESTRECORD_GetQuestState(pQuestFlags, pMonStatsTxtRecord->nTCQuestId, pMonStatsTxtRecord->nTCQuestCP) != 1)
                {
                    nTCId = pMonStatsTxtRecord->wTreasureClass[nDifficulty][3];
                }
            }
        }
    }

    ITEMS_DropTreasureClassById(pGame, hUnit, pModeChange->pTargetUnit, nTCId, 0, nItemLevel, bIgnoreNoDrop, 0, 0, 0);
}

// 0x005A6D50
int __fastcall MONSTERMODE_CreateMonsterMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nParam)
{
    if (!pUnit)
    {
        return 0;
    }

    const int nMissileId = D2Common_11050(pUnit, nParam);
    if (nMissileId < 0)
    {
        return 0;
    }

    int nSkillLevel = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty)->dwMonsterSkillBonus + 1;
    if (UNIT_HasFlag(pUnit, 0x200))
    {
        nSkillLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    }

    if (SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, 0, nSkillLevel, 0, 0, 0, 0, 1))
    {
        MONSTERMODE_FireMissileVolley(pGame, pUnit, nMissileId);
    }

    return 1;
}

// 0x005A6DE0
int __fastcall D2GAME_RemoveModeChangeEventCallback(D2GameStrc* pGame, D2UnitStrc* pMonster)
{
    D2GAME_EVENTS_Delete(pGame, pMonster, 0, 0);
    return 1;
}

static inline int D2GAME_GetMonsterBaseId(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }

        return pUnit->dwClassId;
    }

    return -1;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

static __forceinline void sub_005A6B70_GetTargetCoords(D2UnitStrc* pTarget, D2DynamicPathStrc* pPath, int* pX, int* pY)
{
    if (!pTarget)
    {
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        *pY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        *pX = UNITS_GetUnitXPosition(pTarget);
        *pY = UNITS_GetUnitYPosition(pTarget);
    }
}

// 0x005A6B70
void __stdcall MONSTERMODE_FireMissileVolley(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId)
{
    const int nBaseId = D2GAME_GetMonsterBaseId(pUnit);
    if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_BASEID_63)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        int nX;
        int nY;
        sub_005A6B70_GetTargetCoords(pTarget, pPath, &nX, &nY);

        int nOffsetX = 5;
        int nOffsetY = 5;
        PATH_SetTargetUnit(pPath, 0);

        D2SeedStrc tSeed;
        SEED_InitSeed(&tSeed);
        SEED_InitLowSeed(&tSeed, 0x53454953);
        const int nClassId = pUnit->dwClassId;
        tSeed.nHighSeed = pUnit->dwUnitId;

        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(nClassId);
        for (int nCount = pMonStatsTxtRecord->wAiParam[2][pGame->nDifficulty]; nCount > 0; --nCount)
        {
            if ((unsigned int)SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetX = -nOffsetX;
            }
            if ((unsigned int)SEED_RollRandomNumber(&tSeed) & 1)
            {
                nOffsetY = -nOffsetY;
            }
            D2COMMON_10170_PathSetTargetPos(pPath, nOffsetX + nX, nOffsetY + nY);
            SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, 0, 1, 0, 0, 0, 0, 0);
        }

        PATH_SetTargetUnit(pPath, pTarget);
    }
}

// 0x005A6DF0
static void MONSTERMODE_ApplyDeathAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    for (D2UnitStrc* pTarget = UNITS_GetRoom(pUnit)->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
    {
        if ((!pTarget ? 6 : pTarget->dwUnitType) == 0 && pTarget->dwAnimMode != 17
            && DRLG_UnitEdgeDistance(pUnit, pTarget) <= 2
            && !UNITS_TestCollisionBetweenInteractingUnits(pTarget, pUnit, 0x3C01))
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.dwPhysDamage = STATLIST_UnitGetStatValue(pTarget, 6, 0) >> 5;
            damage.wResultFlags = 1;
            if (!STATES_CheckState(pTarget, STATE_UNINTERRUPTABLE))
                damage.wResultFlags |= 4;
            SUNITDMG_CalculateTotalDamage(pGame, pUnit, pTarget, &damage);
            SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
            SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
        }
    }
}

// 0x005A6EB0
void __stdcall MONSTERMODE_HandleSiegeBeastDeath(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMonster = SUNIT_GetOwner(pGame, pUnit);
    if (pMonster)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Static(pMonster->dwClassId);
        if (pMonStatsTxtRecord)
        {
            D2CoordStrc pCoord;
            pCoord.nX = UNITS_GetXPosition_Static(pMonster);
            pCoord.nY = UNITS_GetYPosition_Static(pMonster);
            const int bFree = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pMonster), &pCoord, UNITS_GetUnitSizeX(pMonster), 0x3C01, 0) != 0;
            if (STATLIST_GetUnitAlignment(pUnit) == 0 && bFree && AITACTICS_UseSkill(pGame, pMonster, pMonStatsTxtRecord->nSkillMode[0], pMonStatsTxtRecord->nSkill[0], 0, pCoord.nX, pCoord.nY))
            {
                D2GAME_EVENTS_Delete(pGame, pMonster, 2, 0);
            }
            else
            {
                SUNITDMG_KillMonster(pGame, pMonster, 0, 1);
            }
        }
    }
}

// 0x005A7EF0
void __fastcall MONSTERMODE_EventUpdateStatListExpirations(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}

#define UNITFLAG_HASTXTMSG 0x00000100

#define HOVER_EVENT 6

// 0x005A7F00
void __fastcall MONSTERMODE_EventFreeHoverText(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    if (!pUnit)
    {
        return;
    }

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
    {
        return;
    }

    const unsigned int nTimeout = CHAT_GetTimeoutFromHoverMsg(pHoverText);
    if (nTimeout <= pGame->dwGameFrame)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_HASTXTMSG;
    }
    else
    {
        EVENT_SetEvent(pGame, pUnit, HOVER_EVENT, nTimeout, 0, 0);
    }
}

// 0x005A7F70
void __fastcall MONSTERMODE_EventClearTargetOverride(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    MONSTERAI_ClearTargetOverride(pUnit);
}

#define EVENTTYPE_STATREGEN 3

#define EVENTTYPE_TRAP 4

#define EVENTTYPE_RESET 5

#define EVENTTYPE_REMOVESTATE 12

#define EVENTTYPE_COUNT 15

// 0x005A7F80
void __fastcall MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nSkillId, int nSkillLevel)
{
    if (nEvent < 0 || nEvent >= EVENTTYPE_COUNT)
    {
        return;
    }

    switch (nEvent)
    {
    case EVENTTYPE_STATREGEN:
    case EVENTTYPE_TRAP:
    case EVENTTYPE_RESET:
    case EVENTTYPE_PERIODICSKILLS:
    case EVENTTYPE_REMOVESTATE:
        break;
    default:
        if (STATES_CheckState(pUnit, STATE_FREEZE) && !SUNIT_IsDead(pUnit))
        {
            return;
        }
        break;
    }

    const MonEventFunc pfMonEvent = gpMonsterEventFunctions[nEvent];
    if (pfMonEvent)
    {
        pfMonEvent(pGame, pUnit, nSkillId, nSkillLevel);
    }
}

// 0x005A8000
void __fastcall MONSTERMODE_DropTreasureForFindItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nUnused)
{
    D2ModeChangeStrc modeChange;
    modeChange.pUnit = pUnit;
    modeChange.pTargetUnit = pTarget;
    MONSTERMODE_DropTreasure(pGame, pUnit, 1, &modeChange);
}


inline D2MonStatsTxt* GetMonStatsById(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMonStatsTxtRecordCount) return &sgptDataTables->pMonStatsTxt[nId];
    return 0;
}

__forceinline int GetBaseId(int nId)
{
    D2MonStatsTxt* pRecord = GetMonStatsById(nId);
    return pRecord ? pRecord->nBaseId : nId;
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit) nType = pUnit->dwUnitType;
    return nType;
}

inline int GetX(D2UnitStrc* pUnit)
{
    switch(GetUnitType(pUnit)) { case 2: case 4: case 5: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int GetY(D2UnitStrc* pUnit)
{
    switch(GetUnitType(pUnit)) { case 2: case 4: case 5: return pUnit->pStaticPath->nYPos; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

inline D2AiParamStrc* MONSTERMODE_GetVelocityParam(D2UnitStrc* pUnit)
{
    if (GetUnitType(pUnit) == 1)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
        {
            return (D2AiParamStrc*)pMonsterData->pAiParam;
        }
    }
    return 0;
}

// 0x005A61F0
void __fastcall D2GAME_MONSTERMODE_ResetVelocityParams(D2UnitStrc* pUnit)
{
    D2AiParamStrc* pAiParam = MONSTERMODE_GetVelocityParam(pUnit);
    pAiParam->nPathTypeOverride = 0;
    pAiParam->nVelocityPercentOverride = 0;
    pAiParam->nNewDistOverride = 0;
}


// 0x005A6220
int __fastcall sub_005A6220_GetField10(FieldStrc_005A6220* pObject)
{
    return pObject->unk0x10;
}

struct D2UnkFieldsStrc;

struct D2UnkFieldsStrc
{
    char pad0x00[0x18];
    int nUnk0x18;
    int nUnk0x1C;
    unsigned char nUnk0x20;
};

// 0x005A6230
void __fastcall MONSTERMODE_GetVelocityParams(D2UnkFieldsStrc* pFields, int* pUnk0x18, int* pUnk0x1C, unsigned char* pUnk0x20)
{
    *pUnk0x18 = pFields->nUnk0x18;
    *pUnk0x1C = pFields->nUnk0x1C;
    *pUnk0x20 = pFields->nUnk0x20;
}

static inline int HasCorpseExplosion(D2MonStatsTxt* pRecord)
{
    if (pRecord) return pRecord->nMonStatsFlags[2] & gdwBitMasks[4];
    return 0;
}

static __forceinline int GetValidBaseId(D2UnitStrc* pUnit)
{
    if (pUnit && GetUnitType(pUnit) == 1 && pUnit->dwClassId >= 0)
    {
        int nBaseId = GetBaseId(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return nBaseId;
        }
    }
    return -1;
}

// 0x005A7C20
int __stdcall D2GAME_ModeChange(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int bClearUsedSkill)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if ((pUnit ? pUnit->dwUnitType : UNIT_INVALID) != UNIT_MONSTER)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nMode = pModeChange->nMode;

    D2_ASSERT(!STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE), 1875);

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        SUNIT_SetUninterruptable(pUnit, 0);
        if (SUNIT_IsDead(pUnit))
        {
            return 1;
        }
    }

    if (!SUNIT_IsDead(pUnit))
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
    }

    if (pUnit->dwAnimMode != MONMODE_NEUTRAL)
    {
        MONSTERMODE_SetAiStateForMode(pUnit->dwAnimMode, pUnit);
    }

    D2AiParamStrc* pAiParam = 0;
    if (nMode != MONMODE_GETHIT)
    {
        if (pModeChange->pTargetUnit)
        {
            PATH_SetTargetUnit(pPath, pModeChange->pTargetUnit);
        }
        else
        {
            D2COMMON_10170_PathSetTargetPos(pPath, pModeChange->nX, pModeChange->nY);
        }

        PATH_SetDistance(pPath, 20);

        pAiParam = (pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? (D2AiParamStrc*)pUnit->pMonsterData->pAiParam : 0;
        MONSTERMODE_UpdateModePath(pGame, pUnit, pModeChange->nVelocityPercent, pAiParam, pModeChange->nEventFlag, pModeChange->nNewDist);
        MONSTERMODE_UpdateModeAttackStats(pUnit, nMode);
        MONSTERUNIQUE_ExecuteUModModeStartCallbacks(pGame, pUnit);
    }

    const D2MonModeCallbackTableStrc* pTargetRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nMode);
    if (!pTargetRecord)
    {
        MONSTERMODE_StartNeutralUnlessDead(pGame, nMode, pUnit);
        return 0;
    }
    if (!pTargetRecord->pfnStart)
    {
        MONSTERMODE_StartNeutralUnlessDead(pGame, nMode, pUnit);
        return 0;
    }

    const int nResult = pTargetRecord->pfnStart(pGame, pModeChange);
    if (!nResult)
    {
        UNITS_SetUsedSkill(pUnit, 0);
        if (nMode != MONMODE_DEATH && nMode != MONMODE_DEAD && SUNIT_IsDead(pUnit))
        {
            return 1;
        }

        MONSTERMODE_StartNeutral(pGame, pModeChange);
    }

    pUnit->dwFlags |= UNITFLAG_MONMODEISCHANGING;
    SUNIT_InitializeAnimation(pUnit);

    if (pAiParam)
    {
        MONSTERMODE_SetVelocityPercent(pUnit, pAiParam);
    }

    MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(pGame, pUnit);

    const int nCurrentAnimMode = pUnit->dwAnimMode;
    if (bClearUsedSkill && nMode == nCurrentAnimMode)
    {
        UNITS_SetUsedSkill(pUnit, 0);
    }

    D2GAME_DeletePlayerPerFrameEvents(pGame, pUnit);

    const D2MonModeCallbackTableStrc* pCurrentRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nCurrentAnimMode);
    if (!pCurrentRecord)
    {
        MONSTERMODE_StartNeutralUnlessDead(pGame, nMode, pUnit);
        return 0;
    }

    if (pCurrentRecord->bScheduleEvents)
    {
        if (MONSTERMODE_IsModeEventEnabled(pUnit, nCurrentAnimMode))
        {
            SUNIT_ResetRecurringModeChangeEvent(pGame, pUnit);
        }
        else
        {
            SUNIT_ScheduleAnimationEvents(pGame, pUnit);
        }
    }

    if (nCurrentAnimMode == MONMODE_GETHIT)
    {
        PATH_SetType(pPath, 0);
        PATH_SetNewDistance(pPath, 0);
    }

    return nResult;
}

// 0x005A7E60
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange)
{
    D2_ASSERT(nMode < 16, 1976);
    UNITS_SetUsedSkill(pUnit, 0);
    memset(pModeChange, 0, sizeof(D2ModeChangeStrc));
    pModeChange->nMode = nMode;
    pModeChange->pUnit = pUnit;
    int nEventFlag = 100;
    if (MONSTERMODE_IsModeEventEnabled(pUnit, nMode))
    {
        nEventFlag = 101;
    }

    pModeChange->nEventFlag = nEventFlag;
}

// 0x005A6920
void __fastcall MONSTERMODE_ApplyStatRegen(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nParam)
{
    int nRegen = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0);
    if (STATES_CheckStateMaskLifeOnUnit(pUnit))
    {
        nRegen -= STATLIST_GetUnitBaseStat(pUnit, STAT_HPREGEN, 0);
    }

    if (STATES_CheckState(pUnit, STATE_PREVENTHEAL) && nRegen >= 0)
    {
        return;
    }

    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, 0, 0);
    if (!nRegen)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 3, 0);
        return;
    }

    int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nRegen < 0 && nHitpoints < 0x100)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
        {
            return;
        }
    }

    nHitpoints += nRegen;
    if (nHitpoints > nMaxHp)
    {
        D2GAME_EVENTS_Delete(pGame, pUnit, 3, 0);
        nHitpoints = nMaxHp;
    }

    if (nHitpoints < 1)
    {
        nHitpoints = 0;
    }

    STATLIST_SetUnitStat(pUnit, 6, nHitpoints, 0);

    const unsigned char nOldPercent = STATLIST_UnitGetStatValue(pUnit, 0x160, 0);
    const unsigned char nNewPercent = MONSTERMODE_GetHpPercent128(pUnit);
    int nDiff = nOldPercent - nNewPercent;
    if (nDiff < 0)
    {
        nDiff = -nDiff;
    }
    if (nDiff > 4)
    {
        SUNITMSG_QueueLifeUpdate(pUnit, nNewPercent);
        STATLIST_SetUnitStat(pUnit, 0x160, nNewPercent, 0);
    }

    if (nHitpoints || !pUnit || !pUnit->dwAnimMode || pUnit->dwAnimMode == 12)
    {
        return;
    }

    D2StatListStrc* pStatList = 0;
    int nStates[2];
    nStates[0] = 2;
    nStates[1] = 0x3E;
    for (int i = 0; i < 2; ++i)
    {
        if (pStatList)
        {
            break;
        }
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nStates[i]);
    }

    D2UnitStrc* pKiller = 0;
    pUnit->dwLastHitClass = 0;
    if (pStatList)
    {
        pKiller = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        STATES_ToggleState(pUnit, 0x5C, 1);
        return;
    }

    SUNITDMG_KillMonster(pGame, pUnit, pKiller, 1);
    SUNITEVENT_Trigger(pGame, 10, pUnit, pKiller, 0);
    if (pKiller)
    {
        SUNITEVENT_Trigger(pGame, 9, pKiller, pUnit, 0);
    }
}

// 0x005A6B10
static int MONSTERMODE_IsModeEventEnabled(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || nMode >= 16)
    {
        return 0;
    }

    const D2MonModeInfoTableStrc* pMonModeInfoTableRecord = &gtMonsterModeEventPolicies[nMode];
    if (pMonModeInfoTableRecord->bAlwaysEnabled)
    {
        return 1;
    }

    if (!pMonModeInfoTableRecord->unk0x04 && pMonModeInfoTableRecord->bUseMovingFlags)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            return pMonStats2TxtRecord->nModeEnabledWhenMovingFlags[nMode >> 3] & gdwBitMasks[nMode & 7];
        }
    }

    return 0;
}

// 0x005A75C0
int __fastcall MONSTERMODE_StartAttackOrSkill(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (MONSTERMODE_IsModeEventEnabled(pUnit, pModeChange->nMode))
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!PATH_GetNumberOfPathPoints(pPath))
        {
            const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
            if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_VULTURE1)
            {
                D2Common_10142(pPath, pUnit, 0);
                SUNIT_SetCombatMode(pGame, pUnit, pModeChange->nMode);
                return 1;
            }

            return 0;
        }

        D2Common_10142(pPath, pUnit, 0);
    }

    SUNIT_SetCombatMode(pGame, pUnit, pModeChange->nMode);
    if (UNITS_GetUsedSkill(pUnit))
    {
        SKILLS_StartUsedSkill(pGame, pUnit);
    }

    return 1;
}

// 0x005A77C0
int __fastcall MONSTERMODE_StartBlock(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    SUNIT_SetCombatMode(pGame, pModeChange->pUnit, MONMODE_BLOCK);
    return 1;
}

// 0x005A6FF0
int __fastcall MONSTERMODE_StartDeath(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, 0);
    MONSTERMODE_CleanupDeath(pModeChange->nDirection, pGame, pUnit);
    MONSTERMODE_TryDropTreasure(pGame, pModeChange, 0);
    sub_00547E50_RemoveMonster(pGame->pMonReg, pUnit);
    int nUnitId;
    if (!pUnit) nUnitId = -1;
    else nUnitId = pUnit->dwUnitId;
    DUNGEON_SaveKilledUnitGUID(UNITS_GetRoom(pUnit), nUnitId);
    D2MonStatsTxt* pMonStats = GetMonStatsTxtRecord(pUnit);
    if (!HasCorpseExplosion(pMonStats))
    {
        return 1;
    }

    switch (GetValidBaseId(pUnit))
    {
    default:
        MONSTERMODE_ApplyDeathAreaDamage(pGame, pUnit);
        return 1;
    case 441:
        MONSTERMODE_HandleSiegeBeastDeath(pGame, pUnit);
        return 1;
    case 212:
    {
        int nX = GetX(pUnit);
        int nY = GetY(pUnit);
        D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, MISSILE_MONSTERCORPSEEXPLODE, pUnit, 0, 1, 0, 0, nX, nY, 1);
        if (!pMissile) return 1;
        D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
        if (!pDifficulty) return 1;
        D2MonStatsInitStrc stats;
        memset(&stats, 0, sizeof(stats));
        int nClassId = pUnit->dwClassId;
        DATATBLS_CalculateMonsterStatsByLevel(nClassId, pGame->dwGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 1, &stats);
        int nMaxDamage = DATATBLS_ApplyRatio(stats.nMaxHP, pDifficulty->nMonsterCEDamagePercent, 100);
        int nMinDamage;
        if (nMaxDamage > 0x100000)
        {
            if ((nMaxDamage & -16) < 1600) nMinDamage = (int)((__int64)nMaxDamage * 60 / 100);
            else nMinDamage = 60 * (nMaxDamage / 100);
        }
        else nMinDamage = 60 * nMaxDamage / 100;
        D2DamageStrc damage;
        memset(&damage, 0, sizeof(damage));
        damage.dwPhysDamage = (ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDamage - nMinDamage) + nMinDamage) << 7;
        SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pMissile, nX, nY, 5, &damage, 0, 0, 0, 0x581);
        break;
    }
    }
    return 1;
}

// 0x005A72B0
void __fastcall MONSTERMODE_EndDeath(D2GameStrc* pGame, D2UnitStrc* pAttacker)
{
    if (pAttacker)
    {
        SUNIT_SetCombatMode(pGame, pAttacker, MONMODE_DEAD);
        SUNITEVENT_Trigger(pGame, UNITEVENT_DEATH, pAttacker, 0, 0);
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (pMonStatsTxtRecord)
        {
            switch (pMonStatsTxtRecord->nSplEndDeath)
            {
            case 1:
                if (pMonStatsTxtRecord->wMinion[0] >= 0 && pMonStatsTxtRecord->wMinion[0] <= sgptDataTables->nMonStatsTxtRecordCount)
                {
                    MONSTER_Reinitialize(pGame, pAttacker, pMonStatsTxtRecord->wMinion[0], 1);
                    MONSTER_UpdateAiCallbackEvent(pGame, pAttacker);
                }
                break;
            case 2:
            {
                D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pAttacker);
                if (pOwner)
                {
                    SUNITDMG_KillMonster(pGame, pOwner, 0, 1);
                }
                break;
            }
            }
        }
    }
}

// 0x005A7350
int __fastcall MONSTERMODE_UpdateDeath(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!MONSTERS_IsSandLeaper(pUnit, 0))
    {
        SUNIT_SetCombatMode(pGame, pUnit, MONMODE_DEAD);
        return 1;
    }
    SUNIT_UpdateUnitPath(pGame, pUnit);
    UNITS_StopSequence(pUnit);
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        SUNIT_SetCombatMode(pGame, pUnit, MONMODE_DEAD);
    }
    return 1;
}

// 0x005A74E0
int __fastcall MONSTERMODE_StartSkill4(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_SKILL4);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 15, 0, 0);
    return 1;
}

// 0x005A7520
int __fastcall MONSTERMODE_StartWalk(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!PATH_GetNumberOfPathPoints(pUnit->pDynamicPath))
    {
        return 0;
    }
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_WALK);
    return 1;
}

// 0x005A7550
int __fastcall MONSTERMODE_StartRun(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!PATH_GetNumberOfPathPoints(pUnit->pDynamicPath))
    {
        return 0;
    }
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_RUN);
    return 1;
}

// 0x005A7580
int __fastcall MONSTERMODE_StartGetHit(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (pUnit)
    {
        if (pUnit->dwAnimMode != MONMODE_DEATH && pUnit->dwAnimMode != MONMODE_DEAD)
        {
            if (!sub_0046C140_TestMonModeFlag(pUnit->dwClassId, MONMODE_GETHIT))
            {
                return 0;
            }
            SUNIT_SetCombatMode(pGame, pUnit, MONMODE_GETHIT);
        }
    }
    return 1;
}


// 0x005A7670
int __fastcall MONSTERMODE_UpdateAttackOrSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        const int nFlags = SKILLS_GetFlags(pSkill);
        if (nFlags & 1)
        {
            SUNIT_ValidateTargetUnit(pGame, pUnit);
            if (SUNIT_UpdateUnitPath(pGame, pUnit) == 2)
            {
                SKILLS_SetFlags(pSkill, nFlags | 2);
                SKILLS_ExecuteUsedSkill(pGame, pUnit);
                if (MONSTERMODE_IsActionFrame(pUnit))
                {
                    SKILLS_ExecuteUsedSkill(pGame, pUnit);
                }

                UNITS_StopSequence(pUnit);
                return 1;
            }
        }

        SKILLS_ExecuteUsedSkill(pGame, pUnit);
        UNITS_StopSequence(pUnit);
        return 1;
    }

    const int bModeEvent = MONSTERMODE_IsModeEventEnabled(pUnit, !pUnit ? 0 : pUnit->dwAnimMode);
    if (bModeEvent)
    {
        SUNIT_UpdateUnitPath(pGame, pUnit);
        UNITS_StopSequence(pUnit);
        if (UNITS_IsAtEndOfFrameCycle(pUnit))
        {
            return 2;
        }

        if (!MONSTERMODE_IsActionFrame(pUnit))
        {
            return 1;
        }
    }

    if (!MONSTERMODE_CreateMonsterMissile(pGame, pUnit, bModeEvent))
    {
        MONSTERMODE_AllocateTargetCombat(pUnit, pGame);
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget)
        {
            SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        }
    }

    return 1;
}

// 0x005A7390
int __fastcall MONSTERMODE_StartDead(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (pUnit && pUnit->dwAnimMode)
    {
        MONSTERMODE_CleanupDeath(pModeChange->nDirection, pGame, pUnit);
    }

    SUNIT_SetCombatMode(pGame, pUnit, 12);
    D2GAME_EVENTS_Delete(pGame, pUnit, 8, 0);
    D2GAME_EVENTS_Delete(pGame, pUnit, 9, 0);
    return 1;
}

// 0x005A7B30
static int __stdcall MONSTERMODE_StartNeutralUnlessDead(D2GameStrc* pGame, int nMode, D2UnitStrc* pUnit)
{
    UNITS_SetUsedSkill(pUnit, 0);
    if (nMode && nMode != 12 && SUNIT_IsDead(pUnit))
    {
        return 1;
    }

    D2ModeChangeStrc tModeChange = {};
    tModeChange.pUnit = pUnit;
    tModeChange.nMode = MONMODE_NEUTRAL;
    MONSTERMODE_StartNeutral(pGame, &tModeChange);
    return 0;
}

// 0x005A73E0
int __fastcall MONSTERMODE_StartNeutral(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, 1);

    if (EVENT_GetEventFrame(pGame, pUnit, 2) <= pGame->dwGameFrame)
    {
        if (STATES_CheckState(pUnit, STATE_STUNNED))
        {
            EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 45, 0, 0);
            return 1;
        }

        if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
            if (pMonStatsTxtRecord)
            {
                int nAiDelay;
                if (!pGame->nGameType && !pGame->dwGameType)
                {
                    nAiDelay = pMonStatsTxtRecord->nAIdel[0];
                }
                else
                {
                    nAiDelay = pMonStatsTxtRecord->nAIdel[pGame->nDifficulty];
                }

                if (nAiDelay <= 0)
                {
                    nAiDelay = 15;
                }

                EVENT_SetEvent(pGame, pUnit, 2, nAiDelay + pGame->dwGameFrame, 0, 0);
            }
        }
    }

    return 1;
}

// 0x005A7490
int __fastcall MONSTERMODE_StartSkill3(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    SUNIT_SetCombatMode(pGame, pModeChange->pUnit, MONMODE_SKILL3);
    return 1;
}

// 0x005A74A0
int __fastcall MONSTERMODE_UpdateSkill3(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_UpdateUnitPath(pGame, pUnit);
    UNITS_StopSequence(pUnit);
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        SUNIT_SetCombatMode(pGame, pUnit, MONMODE_SKILL4);
    }
    return 1;
}

// 0x005A74D0
void __fastcall MONSTERMODE_EndSkill3(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
}

// 0x005A77D0
int __fastcall MONSTERMODE_StartKnockback(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 3))
    {
        return 0;
    }

    if (!sub_0046C140_TestMonModeFlag(!pUnit ? -1 : pUnit->dwClassId, 13))
    {
        return 0;
    }

    if (pUnit && pUnit->dwAnimMode)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        PATH_SetType(pPath, 8);
        int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
        if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
        {
            nBaseId = -1;
        }

        if (nBaseId != MONSTER_SANDLEAPER1)
        {
            D2COMMON_10190_PATH_SetDistance(pPath, 5);
        }
        else
        {
            D2COMMON_10190_PATH_SetDistance(pPath, 10);
        }
        D2Common_10142(pPath, pUnit, 0);
        SUNIT_SetCombatMode(pGame, pUnit, 13);
    }

    return 1;
}

// 0x005A7870
int __fastcall MONSTERMODE_StartSequence(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange)
{
    D2UnitStrc* pUnit = pModeChange->pUnit;
    SUNIT_SetCombatMode(pGame, pUnit, MONMODE_SEQUENCE);
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFBF;
    }
    return SKILLS_StartUsedSkill(pGame, pUnit);
}

// 0x005A78A0
const D2MonModeCallbackTableStrc* __fastcall MONSTERMODE_GetCallbackTableRecord(D2UnitStrc* pUnit, int nMode)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    const int nClassId = pUnit->dwClassId;
    D2MonStatsTxt* pMonStatsTxtRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nClassId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (nMode < 0 || nMode >= 16)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nSplGetModeChart)
    {
        switch (nClassId)
        {
        case 403:
            if (nMode == 4)
            {
                return &gTrappedSoul_Attack_Callbacks;
            }

            if (nMode == 5)
            {
                return &gTrappedSoul_Attack_Callbacks;
            }

            if (nMode == 9)
            {
                return &gTrappedSoul_Skill_Callbacks;
            }

            if (nMode == 8)
            {
                return &gTrappedSoul_Skill_Callbacks;
            }
            break;

        case 417:
        case 418:
            if (nMode == 11)
            {
                return &gShadowMasterWarrior_Skill4_Callbacks;
            }
            break;

        case 243:
        case 333:
        case 705:
            if (nMode == 11)
            {
                return &gDiablo_Skill4_Callbacks;
            }

            if (nMode == 10)
            {
                return &gDiablo_Skill3_Callbacks;
            }
            break;

        case 543:
            if (nMode == 10)
            {
                return &gMonModeCallbacks[7];
            }
            break;

        case 544:
        case 570:
        case 709:
            if (nMode == 10)
            {
                return &gMonModeCallbacks[7];
            }
            break;

        default:
            break;
        }
    }

    return &gMonModeCallbacks[nMode];
}

// 0x005A7BA0
void __fastcall MONSTERMODE_EventModeChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;
    const D2MonModeCallbackTableStrc* pMonModeCallbackTableRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nAnimMode);
    if (!pMonModeCallbackTableRecord)
    {
        MONSTERMODE_StartNeutralUnlessDead(pGame, nAnimMode, pUnit);
        return;
    }
    if (!pMonModeCallbackTableRecord->pfnUpdate)
    {
        MONSTERMODE_StartNeutralUnlessDead(pGame, nAnimMode, pUnit);
        return;
    }
    pMonModeCallbackTableRecord->pfnUpdate(pGame, pUnit);
}

// 0x005A7BE0
void __fastcall MONSTERMODE_EventEndAnimation(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;
    const D2MonModeCallbackTableStrc* pMonModeCallbackTableRecord = MONSTERMODE_GetCallbackTableRecord(pUnit, nAnimMode);
    if (!pMonModeCallbackTableRecord)
    {
        MONSTERMODE_StartNeutralUnlessDead(pGame, nAnimMode, pUnit);
        return;
    }
    if (!pMonModeCallbackTableRecord->pfnEnd)
    {
        MONSTERMODE_StartNeutralUnlessDead(pGame, nAnimMode, pUnit);
        return;
    }
    pMonModeCallbackTableRecord->pfnEnd(pGame, pUnit);
}

static inline D2MonStatsTxt* MONSTATS_GetRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

static inline int MONSTATS_GetBaseIdInline(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTATS_GetRecordInline(nClassId);
    if (!pMonStatsTxtRecord)
        return nClassId;
    return pMonStatsTxtRecord->nBaseId;
}

static inline int MONSTERS_GetBaseIdFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        return MONSTATS_GetBaseIdInline(pUnit->dwClassId);
    return -1;
}

static inline int MONSTERS_ValidateMonsterIdInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return nMonsterId;
    return -1;
}

static __forceinline void MONSTERMODE_AiThinkUnlessFrozen(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (STATES_CheckState(pUnit, STATE_FREEZE) && !SUNIT_IsDead(pUnit)) return;
    if (gpMonsterEventFunctions[2]) gpMonsterEventFunctions[2](pGame, pUnit, 0, 0);
}

// 0x005A8030
void __fastcall MONSTERMODE_HandleEndAnimation(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nMode = !pUnit ? 0 : pUnit->dwAnimMode;
    const int nRawId = MONSTERS_GetBaseIdFromUnitInline(pUnit);
    const int nBaseId = MONSTERS_ValidateMonsterIdInline(nRawId);
    D2MonStatsTxt* pRecord = MONSTATS_GetRecordInline(nRawId);
    if (pRecord->nSpecialEnd)
    {
        if (nBaseId == MONSTER_VULTURE1)
        {
            if (nMode == 8) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == MONSTER_FROGDEMON1)
        {
            if (nMode == 14) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == MONSTER_BATDEMON1)
        {
            if (nMode == 10 || nMode == 11) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == MONSTER_FIREBEAST || nBaseId == MONSTER_ICEGLOBE)
        {
            MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return;
        }
        else if (nBaseId == MONSTER_WILLOWISP1)
        {
            if (nMode == 2) { MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return; }
        }
        else if (nBaseId == MONSTER_TRAPPEDSOUL1)
        {
            MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit); return;
        }
    }
    if (gbModeReset[nMode])
    {
        UNITS_ChangeAnimMode(pUnit, 1);
        MONSTERMODE_AiThinkUnlessFrozen(pGame, pUnit);
        return;
    }
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        SUNIT_SetUninterruptable(pUnit, 0);
        if (SUNIT_IsDead(pUnit)) return;
    }
    UNITS_SetUsedSkill(pUnit, 0);
    D2ModeChangeStrc mode = {};
    mode.nMode = 1;
    mode.pUnit = pUnit;
    mode.nEventFlag = 100;
    mode.pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    D2GAME_ModeChange(pGame, &mode, 1);
}

// 0x005A8330
void __fastcall MONSTERMODE_EndTrappedSoulAttack(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    UNITS_SetUsedSkill(pUnit, 0);

    D2ModeChangeStrc modeChange = {};
    modeChange.nMode = MONMODE_SKILL1;
    modeChange.pUnit = pUnit;
    int nFlag = 100;

    if (pUnit)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (pMonStats2TxtRecord ? pMonStats2TxtRecord->nModeEnabledWhenMovingFlags[MONMODE_SKILL1 >> 3] & gdwBitMasks[MONMODE_SKILL1 & 7] : 0)
        {
            nFlag = 101;
        }
    }

    modeChange.nEventFlag = nFlag;
    modeChange.pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);

    D2GAME_ModeChange(pGame, &modeChange, 1);

    if (!STATES_CheckState(pUnit, STATE_FREEZE) || SUNIT_IsDead(pUnit))
    {
        if (gpMonsterEventFunctions[2])
        {
            gpMonsterEventFunctions[2](pGame, pUnit, 0, 0);
        }
    }
}

// 0x005A83E0
void __fastcall MONSTERMODE_EndTrappedSoulSkill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    UNITS_SetUsedSkill(pUnit, 0);

    D2ModeChangeStrc modeChange = {};
    modeChange.nMode = MONMODE_SKILL1;
    modeChange.pUnit = pUnit;
    int nFlag = 100;

    if (pUnit)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (pMonStats2TxtRecord ? pMonStats2TxtRecord->nModeEnabledWhenMovingFlags[MONMODE_SKILL1 >> 3] & gdwBitMasks[MONMODE_SKILL1 & 7] : 0)
        {
            nFlag = 101;
        }
    }

    modeChange.nEventFlag = nFlag;
    modeChange.pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);

    D2GAME_ModeChange(pGame, &modeChange, 1);

    if (!STATES_CheckState(pUnit, STATE_FREEZE) || SUNIT_IsDead(pUnit))
    {
        if (gpMonsterEventFunctions[2])
        {
            gpMonsterEventFunctions[2](pGame, pUnit, 0, 0);
        }
    }
}


D2UnitStrc* __fastcall SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CE4F0

void __fastcall MONSTERMODE_EndKnockback(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A8520

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline_Q05(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline int MONSTERMODE_GetBaseIdInline_Q05(int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordInline_Q05(nClassId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nClassId;
}

// 0x005A8490
int __fastcall MONSTERMODE_UpdateWalk(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (STATES_CheckState(pUnit, STATE_BLAZE))
    {
        SKILLS_CreateBlazeMissile(pGame, pUnit);
    }

    if (STATES_CheckState(pUnit, STATE_SPIDERLAY))
    {
        SKILLS_CreateSpiderLayMissile(pGame, pUnit);
    }

    if (SUNIT_UpdateUnitPath(pGame, pUnit) == 2)
    {
        MONSTERMODE_HandleEndAnimation(pGame, pUnit);
        return 2;
    }

    return 1;
}

// 0x005A84F0
int __fastcall MONSTERMODE_UpdateRun(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (SUNIT_UpdateUnitPath(pGame, pUnit) == 2)
    {
        MONSTERMODE_HandleEndAnimation(pGame, pUnit);
        return 2;
    }

    return 1;
}

// 0x005A8520
void __fastcall MONSTERMODE_EndKnockback(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    PATH_ResetToPreviousType(pUnit->pDynamicPath);

    const int nClassId = pUnit->dwClassId;
    if (!sub_0046C140_TestMonModeFlag(nClassId, MONMODE_GETHIT))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    int bSandLeaper = 0;
    if (nUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERMODE_GetBaseIdInline_Q05(nClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_SANDLEAPER1)
        {
            bSandLeaper = 1;
        }
    }

    if (!bSandLeaper)
    {
        UNITS_SetUsedSkill(pUnit, 0);

        D2ModeChangeStrc modeChange = {};
        modeChange.nMode = MONMODE_GETHIT;
        modeChange.pUnit = pUnit;
        modeChange.nEventFlag = 100;
        pUnit->dwLastHitClass = 160;
        D2GAME_ModeChange(pGame, &modeChange, 1);
        return;
    }

    int nFrame;
    if (STATES_CheckState(pUnit, STATE_STUNNED))
    {
        nFrame = pGame->dwGameFrame + 45;
    }
    else
    {
        nFrame = pGame->dwGameFrame + 15;
    }
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, nFrame, 0, 0);
}


// 0x005A8630
int __fastcall MONSTERMODE_UpdateKnockback(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_UpdateUnitPath(pGame, pUnit);
    UNITS_StopSequence(pUnit);
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        MONSTERMODE_EndKnockback(pGame, pUnit);
        return 2;
    }

    return 1;
}

// 0x005A8670
int __fastcall MONSTERMODE_UpdateSequence(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (UNITS_IsAtEndOfFrameCycle(pUnit))
    {
        MONSTERMODE_HandleEndAnimation(pGame, pUnit);
        return 2;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    int bCheck = 1;
    if (nSkillFlags & 1)
    {
        SUNIT_ValidateTargetUnit(pGame, pUnit);

        if (SUNIT_UpdateUnitPath(pGame, pUnit) == 2)
        {
            SKILLS_SetFlags(pSkill, nSkillFlags | 2);
            SKILLS_ExecuteUsedSkill(pGame, pUnit);
            bCheck = 0;
        }
    }

    const int nActionFrame = pUnit->nActionFrame;
    if (nActionFrame == 4 || bCheck && !UNIT_HasFlag(pUnit, 0x40) && (nActionFrame == 1 || nActionFrame == 2))
    {
        SKILLS_ExecuteUsedSkill(pGame, pUnit);
    }

    UNITS_StopSequence(pUnit);

    return 1;
}

inline int UNITS_IsValidTargetInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 3) & 1;
}

inline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 2) & 1;
}

// 0x005A8730
static int __stdcall MONSTERMODE_CanCollideWithUnit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2UnitStrc* pOwner, D2MissilesTxt* pMissilesTxtRecord)
{
    if (!UNITS_IsValidTargetInline(pUnit))
    {
        return 0;
    }

    if (!UNITS_CanBeAttackedInline(pUnit))
    {
        return 0;
    }

    if (pMissilesTxtRecord->nNextHit && STATES_CheckState(pUnit, STATE_JUSTHIT))
    {
        return 0;
    }

    if (MISSILE_CheckUnitIfOwner(pMissile, pUnit))
    {
        return 0;
    }

    return !pOwner || SUNIT_AreUnitsHostile(pGame, pOwner, pUnit) || pMissilesTxtRecord->nCollideFriend;
}



int __fastcall MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, void* pArgument)
{
    D2MissileUnitFindArgStrc* pArg = (D2MissileUnitFindArgStrc*)pArgument;
    if (!pArg || !pArg->pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1)
    {
        return 0;
    }

    return MONSTERMODE_CanCollideWithUnit(pArg->pGame, pArg->pMissile, pUnit, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

extern "C" void __cdecl SKILLS_EventCallback_ActiveState(); // 0x0056D790
extern "C" void __cdecl SKILLS_EventCallback_PeriodicSkillAura(); // 0x0056FCB0
extern "C" void __cdecl SKILLS_EventCallback_ItemAura(); // 0x0056FE40
extern "C" void __cdecl sub_005A7EF0(); // 0x005A7EF0
extern "C" void __cdecl AITHINK_ExecuteMonsterAiTick(); // 0x005B1740
extern "C" void __cdecl sub_005A6DE0(); // 0x005A6DE0
extern "C" void __cdecl sub_005A72B0(); // 0x005A72B0
extern "C" void __cdecl sub_005A7350(); // 0x005A7350
extern "C" void __cdecl sub_005A7490(); // 0x005A7490
extern "C" void __cdecl sub_005A74A0(); // 0x005A74A0
extern "C" void __cdecl sub_005A74E0(); // 0x005A74E0
extern "C" void __cdecl sub_005A7520(); // 0x005A7520
extern "C" void __cdecl sub_005A7550(); // 0x005A7550
extern "C" void __cdecl sub_005A7580(); // 0x005A7580
extern "C" void __cdecl sub_005A77C0(); // 0x005A77C0
extern "C" void __cdecl sub_005A7870(); // 0x005A7870
extern "C" void __cdecl sub_005A8030(); // 0x005A8030
extern "C" void __cdecl sub_005A8330(); // 0x005A8330
extern "C" void __cdecl sub_005A83E0(); // 0x005A83E0
extern "C" void __cdecl sub_005A8490(); // 0x005A8490
extern "C" void __cdecl sub_005A84F0(); // 0x005A84F0
extern "C" void __cdecl sub_005A8520(); // 0x005A8520
extern "C" void __cdecl sub_005A8630(); // 0x005A8630
extern "C" void __cdecl sub_005A8670(); // 0x005A8670
extern "C" void __cdecl MONSTERUNIQUE_EventExecuteUModCallbacks(); // 0x005A4370

#pragma pack(push, 1)
struct d2data_0073C578_t
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
    unsigned char b15[284];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0073C6D0_t
{
    unsigned char b0[16];
};
#pragma pack(pop)

extern "C" struct d2data_0073C578_t gData_0073C578; // 0x0073C578
extern "C" const D2MonModeCallbackTableStrc gData_006E2260[16]; // 0x006E2260
extern "C" const D2MonModeCallbackTableStrc gData_006E2360; // 0x006E2360
extern "C" const D2MonModeCallbackTableStrc gData_006E2370; // 0x006E2370
extern "C" const D2MonModeCallbackTableStrc gData_006E2380; // 0x006E2380
extern "C" const D2MonModeCallbackTableStrc gData_006E2390; // 0x006E2390
extern "C" const D2MonModeCallbackTableStrc gData_006E23A0; // 0x006E23A0
extern "C" const D2MonModeInfoTableStrc gData_006E23D0[16]; // 0x006E23D0
extern "C" struct d2data_0073C6D0_t gData_0073C6D0; // 0x0073C6D0

extern MonEventFunc const gpMonsterEventFunctions[16] = { (MonEventFunc)&MONSTERMODE_EventModeChange, (MonEventFunc)&MONSTERMODE_EventEndAnimation, (MonEventFunc)&AITHINK_ExecuteMonsterAiTick, (MonEventFunc)&MONSTERMODE_ApplyStatRegen, 0, (MonEventFunc)&SKILLS_EventCallback_ActiveState, (MonEventFunc)&MONSTERMODE_EventFreeHoverText, (MonEventFunc)&MONSTERUNIQUE_EventExecuteUModCallbacks, (MonEventFunc)&SKILLS_EventCallback_PeriodicSkillAura, (MonEventFunc)&SKILLS_EventCallback_ItemAura, (MonEventFunc)&MONSTERMODE_EventClearTargetOverride, 0, (MonEventFunc)&sub_005A7EF0 }; // 0x006E2490

extern "C" struct d2data_0073C578_t gData_0073C578 = {
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
    (const void*)"14",
    {
        0x24, 0x00, 0x00, 0x00, 0x25, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00, 0x27, 0x00, 0x00, 0x00,
        0x28, 0x00, 0x00, 0x00, 0x29, 0x00, 0x00, 0x00, 0x2A, 0x00, 0x00, 0x00, 0x2B, 0x00, 0x00, 0x00,
        0x2C, 0x00, 0x00, 0x00, 0x2D, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00,
        0x2D, 0x00, 0x00, 0x00, 0x2E, 0x00, 0x00, 0x00, 0x2F, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00,
        0x36, 0x00, 0x00, 0x00, 0x9C, 0x00, 0x00, 0x00, 0x3A, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x06, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0B, 0x01, 0x00, 0x00,
        0x3B, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0xD3, 0x00, 0x00, 0x00, 0x3D, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x0D, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xFA, 0x00, 0x00, 0x00,
        0x3C, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0C, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0xF2, 0x00, 0x00, 0x00, 0x3E, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x14, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00,
        0x3F, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x16, 0x00, 0x00, 0x00, 0x19, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0xF3, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x17, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x0E, 0x02, 0x00, 0x00,
        0x5E, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x22, 0x00, 0x00, 0x00, 0x26, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x20, 0x02, 0x00, 0x00, 0x5F, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x24, 0x00, 0x00, 0x00, 0x28, 0x00, 0x00, 0x00, 0x04
    }
}; // 0x0073C578

extern "C" const D2MonModeCallbackTableStrc gData_006E2260[16] = {
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartDeath, (MonModeUnitFunc)(unsigned int)&sub_005A7350, (MonModeUnitFunc)(unsigned int)&sub_005A72B0, 1 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartNeutral, (MonModeUnitFunc)(unsigned int)&sub_005A6DE0 },
    { (MonModeStartFunc)(unsigned int)&sub_005A7520, (MonModeUnitFunc)(unsigned int)&sub_005A8490, 0, 1 },
    { (MonModeStartFunc)(unsigned int)&sub_005A7580, (MonModeUnitFunc)(unsigned int)&sub_005A6DE0, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&sub_005A77C0, (MonModeUnitFunc)(unsigned int)&sub_005A6DE0, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&sub_005A7490, (MonModeUnitFunc)(unsigned int)&sub_005A74A0, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_EndSkill3 },
    { (MonModeStartFunc)(unsigned int)&sub_005A74E0, (MonModeUnitFunc)(unsigned int)&sub_005A6DE0 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartDead, (MonModeUnitFunc)(unsigned int)&sub_005A6DE0 },
    { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartKnockback, (MonModeUnitFunc)(unsigned int)&sub_005A8630, (MonModeUnitFunc)(unsigned int)&sub_005A8520, 1 },
    { (MonModeStartFunc)(unsigned int)&sub_005A7870, (MonModeUnitFunc)(unsigned int)&sub_005A8670, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 },
    { (MonModeStartFunc)(unsigned int)&sub_005A7550, (MonModeUnitFunc)(unsigned int)&sub_005A84F0, 0, 1 }
}; // 0x006E2260
#pragma comment(linker, "/alternatename:?gMonModeCallbacks@@3QBUD2MonModeCallbackTableStrc@@B=_gData_006E2260")

extern "C" const D2MonModeCallbackTableStrc gData_006E2360 = { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 }; // 0x006E2360
#pragma comment(linker, "/alternatename:?gDiablo_Skill4_Callbacks@@3UD2MonModeCallbackTableStrc@@B=_gData_006E2360")

extern "C" const D2MonModeCallbackTableStrc gData_006E2370 = { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 }; // 0x006E2370
#pragma comment(linker, "/alternatename:?gDiablo_Skill3_Callbacks@@3UD2MonModeCallbackTableStrc@@B=_gData_006E2370")

extern "C" const D2MonModeCallbackTableStrc gData_006E2380 = { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8330, 1 }; // 0x006E2380
#pragma comment(linker, "/alternatename:?gTrappedSoul_Attack_Callbacks@@3UD2MonModeCallbackTableStrc@@B=_gData_006E2380")

extern "C" const D2MonModeCallbackTableStrc gData_006E2390 = { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A83E0, 1 }; // 0x006E2390
#pragma comment(linker, "/alternatename:?gTrappedSoul_Skill_Callbacks@@3UD2MonModeCallbackTableStrc@@B=_gData_006E2390")

extern "C" const D2MonModeCallbackTableStrc gData_006E23A0 = { (MonModeStartFunc)(unsigned int)&MONSTERMODE_StartAttackOrSkill, (MonModeUnitFunc)(unsigned int)&MONSTERMODE_UpdateAttackOrSkill, (MonModeUnitFunc)(unsigned int)&sub_005A8030, 1 }; // 0x006E23A0
#pragma comment(linker, "/alternatename:?gShadowMasterWarrior_Skill4_Callbacks@@3UD2MonModeCallbackTableStrc@@B=_gData_006E23A0")

extern "C" const D2MonModeInfoTableStrc gData_006E23D0[16] = {
    { 0, 1 },
    { 0, 1 },
    { 1 },
    { 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 0, 1 },
    { 0, 1 },
    { 1 },
    { 1 },
    { 1 }
}; // 0x006E23D0
#pragma comment(linker, "/alternatename:?gtMonsterModeEventPolicies@@3PAUD2MonModeInfoTableStrc@@A=_gData_006E23D0")

extern "C" struct d2data_0073C6D0_t gData_0073C6D0 = {
    { 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01 }
}; // 0x0073C6D0
#pragma comment(linker, "/alternatename:?gbModeReset@@3PAEA=_gData_0073C6D0")
