#include "D2GameEvents.h"
#include "D2ObjectIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameObjs.h"
#include "D2QuestData.h"
#include "D2UnitData.h"
#include "D2MonModes.h"
#include "D2ObjModes.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define QUEST_A5Q4_NIHLATHAK 34


struct D2PoolSystemStrc;
struct D2StaticPathStrc;

struct D2Act5Quest4Strc;

struct D2PlayerDataStrc;

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall SUNIT_AttachSound(D2UnitStrc* unit, int updateType, D2UnitStrc* updateUnit); // 0x00553380


int __stdcall QUESTRECORD_GetQuestState(void*,int,int); // 0x0065C310

struct D2NPCMessageTableStrc;


typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

#define QUEST_A5Q5_ANCIENTS 35

#define QUESTSTATEFLAG_A5Q4 38

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define INITNO_A5Q4 4

#define MSG_DREHYA_INTRO 20137

#define MSG_DREHYA_DONE 20148

#define QUESTFX_A5Q4 17

#define TIMER_TICKS_A5Q4 8

#define LINE_SEQ_DEBUG 255

#define LINE_SEQ_ASSERT 246

#define LINE_SCROLL_STATE2 283

#define LINE_SCROLL_STATE5 298

#define LINE_KILLED_STATE4 583

#define LINE_LEVEL_STATE3 748

#define LINE_INIT_ALLOC 781

#define PORTAL_DX 10

typedef int(__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

extern D2NPCMessageTableStrc gpAct5Q4NpcMessages;                                                           // 0x00734AC8

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer);    // 0x00543520

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190


void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs);                                      // 0x00545300


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

bool __fastcall ACT5Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058AF00

void __fastcall ACT5Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x0058B050

void __fastcall ACT5Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x0058B2C0

int __fastcall ACT5Q4_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);      // 0x0058B4A0

void __fastcall ACT5Q4_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);  // 0x0058B5B0

int __fastcall ACT5Q4_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058B730

bool __fastcall ACT5Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058B870

void __fastcall ACT5Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058B990

struct D2QuestGUIDStrc;

union D2SeedStrc;

struct D2MonStatsTxt;

struct D2ObjInitFnStrc;

struct D2ObjOperateFnStrc;

struct D2Act5Quest5Strc;

struct D2Act5Quest6Strc;

struct D2Act1Quest3Strc;

struct D2Act1Quest2Strc;

struct D2Act1Quest4Strc;

enum D2C_F33QuestConstants
{
    ACT_V = 4,
    QUEST_A1Q2_BLOODRAVEN = 2,
    QUEST_A1Q3_MALUS = 3,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUEST_A5Q6_BAAL = 36,
    QUESTSTATEFLAG_A1Q2 = 2,
    QUESTSTATEFLAG_A1Q3 = 3,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A5Q6 = 40,
    QFLAG_CUSTOM6 = 10,
    STAT_LEVEL = 12,
    ITEMQUAL_NORMAL = 2,
    MONSTATSFLAGINDEX_ZOO = 22,
};


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500


int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60


void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190


D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20





inline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
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

// 0x0058AEA0
int __fastcall ACT5Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A5Q4_NIHLATHAK);
    }

    return 0;
}

// 0x0058AF00
bool __fastcall ACT5Q4_StatusFilterCallback(D2QuestDataStrc* quest, D2UnitStrc* unit, D2BitBufferStrc* globalFlags, D2BitBufferStrc* flags, unsigned char* status)
{
    *status = 0;
    if (QUESTRECORD_GetQuestState(flags, 38, 0)) return true;
    if (QUESTRECORD_GetQuestState(flags, 38, 1) || QUESTRECORD_GetQuestState(flags, 38, 13)) {
        *status = QUESTRECORD_GetQuestState(flags, 38, 4) != 0 ? 5 : 4;
    } else if (quest->bNotIntro) {
        if (QUESTRECORD_GetQuestState(flags, 38, 14)) { *status = 12; return true; }
        if (quest->fState < 4) { *status = quest->fLastState; return true; }
    }
    return true;
}

// 0x0058AF90
static bool __stdcall ACT5Q4_OpenDrehyaPortal(D2QuestDataStrc* pQuestData, D2UnitStrc* pTarget)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bPortalCreated)
    {
        return false;
    }

    if (D2GAME_CreatePortalObject(pQuestData->pGame, 0, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget) + 10, CLIENTS_GetUnitY(pTarget) + 5, LEVEL_NIHLATHAKSTEMPLE, 0, OBJECT_PERMANENT_TOWN_PORTAL, 1))
    {
        pQuestDataEx->bPortalCreated = 1;
        pQuestDataEx->bNeedsToOpenPortal = 0;
        return true;
    }

    return false;
}

// 0x0058B140
bool __fastcall ACT5Q4_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < QSTATE_4 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_SEQ_DEBUG);
        }
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SEQ_ASSERT);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

static inline D2BitBufferStrc* QUESTS_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

static inline int UNITS_GetGUIDOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x0058B0B0
int __fastcall ACT5Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == QSTATE_2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_STARTED);
    }
    else if (pQuestData->fState == QSTATE_3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x0058B1C0
void __fastcall ACT5Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != MONSTER_DREHYA)
    {
        return;
    }

    if (nMessageIndex == MSG_DREHYA_INTRO)
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, QSTATE_2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_SCROLL_STATE2);
        pQuestDataEx->bDrehyaActivated = 1;
        pQuestDataEx->bNeedsToOpenPortal = 1;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q4_UnitIterate_UpdateQuestStateFlags);
    }
    else if (nMessageIndex == MSG_DREHYA_DONE)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, pQuestData->fLastState, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);

        QUESTRECORD_SetQuestState(QUESTS_GetQuestFlagsInline(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q4, QFLAG_ENTERAREA);

        if (!QUESTRECORD_GetQuestState(QUESTS_GetQuestFlagsInline(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE)
            && (pQuestData->bNotIntro || !QUESTRECORD_GetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING)))
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, QSTATE_5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_SCROLL_STATE5);
        ACT5Q4_SeqCallback(pQuestData);
    }
}


inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0058B2C0
void __fastcall ACT5Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING))
    {
        return;
    }

    if (nNpcId == MONSTER_DREHYA && pQuestData->fState == 1)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_DREHYA, 0);
        }
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_ENTERAREA))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
        else
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (bRewardGranted == 1 || pQuestData->fState >= 4 && !bPrimaryGoalDone || !pQuestData->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnA5Q4NpcIndices[pQuestData->fState];
    if (nIndex != -1 && nIndex < 8)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x0058B460
void __fastcall ACT5Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, UNITS_GetGUIDOrNone(pQuestArg->pPlayer));
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    const int nGUID = UNITS_GetGUIDOrNone(pQuestArg->pPlayer);
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, nGUID);
}

// 0x0058B4A0
int __fastcall ACT5Q4_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDNOW) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK)->pQuestDataEx;

    bool bFound = false;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bFound = true;
    }
    else
    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);

        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pQuestDataEx->pRoom)
            {
                bFound = true;
                break;
            }
        }
    }

    pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!bFound)
    {
        return 0;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE);
    return 0;
}

// 0x0058B680
int __fastcall ACT5Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q4_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0058B6D0
int __fastcall ACT5Q4_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDGRANTED) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_REWARDPENDING) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A5Q4_NIHLATHAK, 0);
    }

    return 0;
}

// 0x0058B770
bool __fastcall ACT5Q4_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;

    if (pQuestData->fLastState != QSTATE_4)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, QSTATE_4, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bTimerActive = 0;
    return true;
}

// 0x0058B7A0
void __fastcall ACT5Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    if (!pRoom)
    {
        return;
    }

    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pRoom = pRoom;

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q4_UnitIterate_SetRewardPending);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q4_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q4_UnitIterate_AttachCompletionSound);

    QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A5Q4, QFLAG_PRIMARYGOALDONE);
    QUESTS_TriggerFX(pQuestData->pGame, QUESTFX_A5Q4);
    QUESTS_StateDebug(pQuestData, QSTATE_4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_KILLED_STATE4);

    if (!pQuestDataEx->bTimerActive)
    {
        pQuestDataEx->bTimerActive = 1;
        QUESTS_CreateTimer(pQuestData, ACT5Q4_Timer_StatusCycler, TIMER_TICKS_A5Q4);
    }
}

// 0x0058BAB0
void __fastcall ACT5Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    const int nNewLevel = pQuestArg->nNewLevel;

    if (pQuestArg->nOldLevel == LEVEL_HARROGATH && pQuestData->fState == QSTATE_2)
    {
        QUESTS_StateDebug(pQuestData, QSTATE_3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_LEVEL_STATE3);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q4_UnitIterate_UpdateQuestStateFlags);
    }

    if (nNewLevel == LEVEL_NIHLATHAKSTEMPLE && pQuestData->fLastState == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, QSTATE_2, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bDrehyaActivated = 0;
    }
}

// 0x0058BB20
void __fastcall ACT5Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT5Q4_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT5Q4_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = ACT5Q4_Callback08_MonsterKilled;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT5Q4_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT5Q4_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT5Q4_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT5Q4_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = &gpAct5Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", LINE_INIT_ALLOC, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A5Q4;
    pQuestData->pfStatusFilter = ACT5Q4_StatusFilterCallback;
    pQuestData->nInitNo = INITNO_A5Q4;
    pQuestData->pfActiveFilter = ACT5Q4_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q4_SeqCallback;
    pQuestData->nSeqId = QUEST_A5Q5_ANCIENTS;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest4Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x0058BC00
void __fastcall ACT5Q4_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 0x26, 1);

    QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0x0F);
}

// 0x0058BC40
void __fastcall ACT5Q4_OnNihlathakActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x22);
    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState >= 3)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
}

// 0x0058B050
void __fastcall ACT5Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if ((unsigned short)(pQuestArg->pTarget ? pQuestArg->pTarget->dwClassId : -1) != MONSTER_DREHYA)
    {
        return;
    }

    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDrehyaActivated == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bDrehyaActivated = 0;
    }

    if (pQuestDataEx->bNeedsToOpenPortal && !pQuestDataEx->bPortalCreated)
    {
        ACT5Q4_OpenDrehyaPortal(pQuestData, pQuestArg->pTarget);
    }
}

// 0x0058B5B0
void __fastcall ACT5Q4_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0xE) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 1) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0xD) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 0x26, 1))
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x26, 0xD);
}

// 0x0058B730
int __fastcall ACT5Q4_UnitIterate_AttachCompletionSound(D2GameStrc* game, D2UnitStrc* player, void* unused)
{
    D2BitBufferStrc* flags = UNITS_GetPlayerData(player)->pQuestData[game->nDifficulty];
    if (QUESTRECORD_GetQuestState(flags, 38, 13))
        SUNIT_AttachSound(player, 82, player);
    return 0;
}

// 0x0058B870
bool __fastcall ACT5Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 512)
    {
        if (pQuest->fState == 1)
        {
            if (!(QUESTRECORD_GetQuestState(pQuestFlags, 37, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 37, 1))) goto inactive;
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 0)) goto inactive;
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 1)) goto inactive;
        }
        else
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 13)) goto inactive;
            if (QUESTRECORD_GetQuestState(pQuestFlags, 38, 4)) goto inactive;
        }
        return true;
    }
inactive:
    return false;
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x0058B900
void __fastcall ACT5Q4_RescheduleDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (pQuestData && ((D2Act5Quest4Strc*)pQuestData->pQuestDataEx)->bNeedsToOpenPortal)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_QUESTFN, pGame->dwGameFrame + 12, 0, 0);
    }
}

// 0x0058B940
void __fastcall ACT5Q4_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK);
    if (!pQuestData || !((D2Act5Quest4Strc*)pQuestData->pQuestDataEx)->bNeedsToOpenPortal)
    {
        return;
    }

    if (!ACT5Q4_OpenDrehyaPortal(pQuestData, pUnit))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 12, 0, 0);
    }
}

// 0x0058B990
void __fastcall ACT5Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        pQuestData->fState = 5;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2WaypointDataStrc* pWaypointFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pWaypointData[pGame->nDifficulty];
        unsigned short nWpNo;
        if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_HALLSOFDEATHSCALLING, &nWpNo) && !WAYPOINTS_IsActivated(pWaypointFlags, nWpNo))
        {
            pQuestDataEx->bWaypointNotActivated = 1;
        }
    }
    else
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q4, QFLAG_LEAVETOWN))
            {
                pQuestDataEx->bNeedsToOpenPortal = 1;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", 705);
            }
            else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_STARTED))
            {
                pQuestDataEx->bNeedsToOpenPortal = 1;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q4_UnitIterate_StatusCyclerEx, 1);
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q4.cpp", 711);
            }
        }
    }
}

// 0x0058BC80
void __fastcall ACT5Q4_AnyaOpenPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2Act5Quest4Strc* pQuestDataEx = (D2Act5Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q4_NIHLATHAK)->pQuestDataEx;
    if (!pQuestDataEx->bWaypointNotActivated)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_V)
    {
        return;
    }

    if (D2GAME_CreatePortalObject(pGame, 0, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit) + 10, CLIENTS_GetUnitY(pUnit) + 5, LEVEL_NIHLATHAKSTEMPLE, 0, OBJECT_PERMANENT_TOWN_PORTAL, 1))
    {
        pQuestDataEx->bWaypointNotActivated = 0;
    }
}

// 0x0058BD50
bool __fastcall ACT5Q5_Timer_RespawnAncientStatueObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    bool bStatueNotFound = false;
    if (!pQuestDataEx->nActivePortalCount && pQuestDataEx->bActivatable)
    {
        for (int i = 0; i < 3; ++i)
        {
            if (pQuestDataEx->bAncienStatueRespawned[i])
            {
                D2UnitStrc* pAncientStatue = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nAncientStatueGUID[i]);
                if (pAncientStatue)
                {
                    UNITS_ChangeAnimMode(pAncientStatue, OBJMODE_OPERATING);
                    const int nClassId = pAncientStatue->dwClassId;
                    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
                    const int nFrame = pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8);
                    EVENT_SetEvent(pGame, pAncientStatue, EVENTTYPE_ENDANIM, nFrame, 0, 0);
                    pQuestDataEx->bAncienStatueRespawned[i] = 0;
                    pQuestDataEx->nAncientStatueObjectMode[i] = OBJMODE_OPENED;
                }
                else
                {
                    bStatueNotFound = true;
                }
            }
        }

        if (bStatueNotFound)
        {
            return false;
        }
    }

    pQuestDataEx->bTimerActive = 0;
    return true;
}

// 0x0058BE20
int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A5Q5_ANCIENTS);
    }

    return 0;
}

struct D2GameStrc;

struct D2UnitStrc;

// 0x00592D50
bool __fastcall ACT1Q4_OpenPortalToTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pCairnStone = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nCairnStoneAlphaGUID);
    if (pCairnStone)
    {
        if (D2GAME_CreatePortalObject(pGame, 0, UNITS_GetRoom(pCairnStone), CLIENTS_GetUnitX(pCairnStone) + 4, CLIENTS_GetUnitY(pCairnStone) + 4, LEVEL_TRISTRAM, 0, OBJECT_PERMANENT_TOWN_PORTAL, 1))
        {
            pQuestDataEx->bPortalToTristramOpened = 1;
            pQuestDataEx->bOpenPortalTimerActive = 0;
            return true;
        }

        return false;
    }

    pQuestDataEx->bOpenPortalTimerActive = 0;
    return true;
}

struct D2ActiveRoomStrc;

struct D2ItemDropStrc;

