#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2GameObjs.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2MonModes.h"
#include "D2Packets.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define QUEST_A1Q4_CAIN 4

#define QUEST_A5Q3_PRISONOFICE 33

#define QUEST_A5Q6_BAAL 36

#define QUESTSTATEFLAG_A5Q6 40

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_CUSTOM1 5

#define QFLAG_PRIMARYGOALDONE 13

#define UNIT_MONSTER 1

#define UNIT_INVALID 6

#define QUESTSTATEFLAG_A5Q4 38

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM4 8

#define ITEMCODE_DEFROST_POTION 0x20656369

struct D2PoolSystemStrc;
struct D2ObjectControlStrc;

struct D2PlayerDataStrc;

struct D2Act5Quest1Strc;

struct D2Act5Quest3Strc;

struct D2Act1Quest4Strc;


struct D2MonsterDataStrc;

struct D2ModeChangeStrc;

struct D2Act5Quest2Strc;

struct D2ObjInitFnStrc;

struct D2ObjOperateFnStrc;

struct D2CoordStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2QuestDataStrc;

struct D2MapAIStrc;

struct D2QuestArgStrc;

struct D2QuestGUIDStrc;

struct D2Act4Quest2Strc;

struct D2Act4Quest3Strc;


#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380




typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


extern unsigned int gnA5Q1NpcIndices[]; // 0x00733928


void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0

void __fastcall MONSTERAI_CloseNpcInteractions(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide); // 0x00573180


int __fastcall ACT5Q2_SpawnCagedWussies(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp, int nCount); // 0x00588600


void __fastcall ACT5Q3_SendPacket0x5DToClient(D2UnitStrc* pUnit); // 0x00589070


D2MapAIStrc** __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0);

extern "C" const char gszAct4Q3SourceFile[];

extern char gpAct4Q3NpcMessages[];

extern char gpAct4Q4NpcMessages[];

extern char gpAct3IntroNpcMessages[];


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310


bool __fastcall ACT4Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);


void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);


#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

typedef int(__fastcall* QUESTSEQFN)(D2QuestDataStrc* pQuestData);

typedef int(__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C


void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


int __fastcall ACT5Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586DE0

int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00586C80

#define QFLAG_COMPLETEDBEFORE 15

#define SUPERUNIQUE_SIEGE_BOSS 42

#define STAT_FIRERESIST 39

#define STAT_LIGHTRESIST 41

#define STAT_COLDRESIST 43

#define STAT_POISONRESIST 45

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

extern char gpAct5Q1NpcMessages[]; // 0x00733308

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

bool __fastcall ACT5Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00586CE0

void __fastcall ACT5Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586D80

void __fastcall ACT5Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586E70

void __fastcall ACT5Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00586FF0

int __fastcall ACT5Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587100

int __fastcall ACT5Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005872F0

bool __fastcall ACT5Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005874E0

bool __fastcall ACT5Q1_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00587560

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005870D0

void __fastcall ACT5Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005873E0

void __fastcall D2GAME_UpdateAttribute(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520


void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

#define PREFIX

#define TERMINAL_STATE 5

#define ASSERT_LINE 626

#define MONSTER_QUALKEHK 515


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_COMPLETEDNOW 14

// 0x00586C80
int __fastcall ACT5Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A5Q1_SHENK);
    }

    return 0;
}

// 0x00586CE0
bool __fastcall ACT5Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING) || QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE))
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, QFLAG_CUSTOM1))
        {
            *pStatus = 4;
            return true;
        }

        *pStatus = 3;
        return true;
    }

    if (!pQuest->bNotIntro)
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDNOW))
    {
        *pStatus = 12;
    }
    else if (pQuest->fState < 5)
    {
        *pStatus = pQuest->fLastState;
    }

    return true;
}

// 0x00586D80
void __fastcall ACT5Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != MONSTER_LARZUK)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bLarzukStartActivated == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bLarzukStartActivated = 0;
    }

    if (pQuestDataEx->bLarzukEndActivated == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bLarzukEndActivated = 0;
    }
}

// 0x00586DE0
int __fastcall ACT5Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_STARTED);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_ENTERAREA);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_LEAVETOWN);
        }
    }

    return 0;
}

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005871C0
void __fastcall ACT5Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 1) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD) == 1)
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

    QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 0xD);
}

// 0x00587240
int __fastcall ACT5Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q1_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

inline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00587290
int __fastcall ACT5Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x23, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x23, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x1F, 0);
    }

    return 0;
}

// 0x00587330
void __fastcall ACT5Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
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

    ((D2Act5Quest1Strc*)pQuestData->pQuestDataEx)->pRoom = pRoom;

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_SetRewardPending);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q1_UnitIterate_AttachCompletionSound);

    QUESTS_SetGlobalState(pQuestData->pGame, 0x23, 0xD);
    QUESTS_TriggerFX(pQuestData->pGame, 0xF);

    if (pQuestData->fLastState < 3)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005875F0
void __fastcall ACT5Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0xF)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        pQuestData->fLastState = 5;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 4) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
    else if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, 0x201) && !pQuestData->fState && pQuestData->bNotIntro)
    {
        pQuestData->fState = 1;
    }
}

// 0x005876E0
void __fastcall ACT5Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT5Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT5Q1_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT5Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q1_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct5Q1NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x2D3, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 0x23;
    pQuestData->pfStatusFilter = ACT5Q1_StatusFilterCallback;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q1_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q1_SeqCallback;
    pQuestData->nSeqId = 0x20;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest1Strc));
}

// 0x00586E70
void __fastcall ACT5Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != 0x1FF)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    if (nMessageIndex == 20077)
    {
        pQuestDataEx->bLarzukStartActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0xF8);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 20090)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) != 1)
        {
            return;
        }

        pQuestDataEx->bLarzukEndActivated = 1;
        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->eFilter);
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 5);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13) && pQuestData->fState != 5)
        {
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x108);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x109);
            pQuestData->pfSeqFilter(pQuestData);

            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
        }

        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}

static inline D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
}

// 0x00586FF0
void __fastcall ACT5Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_CUSTOM1))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
    }
    else if (bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone))
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        const unsigned int nIndex = gnA5Q1NpcIndices[pQuestData->fState];
        if (nIndex != -1 && nIndex < 8)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005870D0
void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x00587100
int __fastcall ACT5Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED))
    {
        D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK)->pQuestDataEx;
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
        if (bFound)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q1, QFLAG_PRIMARYGOALDONE);
        }
    }

    return 0;
}

// 0x005872F0
int __fastcall ACT5Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (QUESTRECORD_GetQuestState(GetQuestFlags(pGame, pUnit), 35, 13))
        SUNIT_AttachSound(pUnit, 80, pUnit);
    return 0;
}

// 0x005873E0
void __fastcall ACT5Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;

    switch (nNewLevel)
    {
    case 110:
    case 111:
    case 112:
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        if (pQuestData->fState == 1 || pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x229);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
        }
        return;

    default:
        break;
    }

    if (nOldLevel != 109)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q1.cpp", 0x23F);
    if (!pQuestData->fLastState)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q1_UnitIterate_UpdateQuestStateFlags);
}

// 0x005874E0
bool __fastcall ACT5Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_LARZUK)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_CUSTOM1))
        {
            return true;
        }

        if (pQuest->bNotIntro && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }

    return false;
}

// 0x00587560
bool __fastcall ACT5Q1_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != TERMINAL_STATE && pQuestData->bNotIntro)
        return true;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
        {
            FOG_DisplayHalt("", sub_00408090(), ASSERT_LINE);
            exit(-1);
        }
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}

// 0x005875D0
void __fastcall ACT5Q1_SetQuestStateIfIntroDone(D2QuestDataStrc* pQuest)
{
    if (!pQuest->fState && pQuest->bNotIntro)
    {
        pQuest->fState = 1;
    }
}

struct D2ActiveRoomStrc;

// 0x005877C0
void __fastcall ACT5Q1_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestInfo = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestInfo, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDGRANTED);
    QUESTRECORD_ClearQuestState(pQuestInfo, QUESTSTATEFLAG_A5Q1, QFLAG_REWARDPENDING);

    if (!QUESTRECORD_GetQuestState(pQuestInfo, QUESTSTATEFLAG_A5Q1, QFLAG_COMPLETEDBEFORE))
    {
        D2_ASSERT(QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK), 750);
    }
}

void __cdecl sub_00405A50_Nop();

void __cdecl sub_00405A60_Nop();

void __cdecl ITEMS_Nop();

void __cdecl sub_004DF920_Nop();

void __cdecl sub_004DF930_Nop();

// 0x00587830
void __cdecl OBJECTS_InitFunction70_Unused()
{
}

// 0x00587840
void __fastcall OBJECTS_InitFunction71_LarzukStandard(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x1F);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bLarzukSpawned)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom;
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;
    QUESTS_GetFreePosition(pOp->pRoom, &pCoord, 2, 0x100, &pRoom, 16, 100);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pLarzuk = D2GAME_SpawnMonster(pOp->pGame, pRoom, pCoord.nX, pCoord.nY, MONSTER_LARZUK, 1, 5, 0);
    if (!pLarzuk)
    {
        return;
    }

    pQuestDataEx->bLarzukSpawned = 1;
    pQuestDataEx->nLarzukGUID = !pLarzuk ? -1 : pLarzuk->dwUnitId;
    pLarzuk->dwFlags |= 0x3000000;

    if (pQuestDataEx->pLarzukMapAI && pQuestDataEx->pLarzukMapAI->pPosition && !pQuestDataEx->bLarzukMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pLarzukMapAI, AIGENERAL_GetMapAiFromUnit(pLarzuk));
        pQuestDataEx->bLarzukMapAIChanged = 1;
    }
}

// 0x00587900
void __fastcall ACT5Q1_OnSiegeBossActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState >= 2 || MONSTERUNIQUE_GetBossHcIdx(pUnit) != SUPERUNIQUE_SIEGE_BOSS)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q1_UnitIterate_StatusCyclerEx, 1);
}

// 0x00587950
void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q1_SHENK);
    if (!pQuestData || !pMapAi)
    {
        return;
    }

    D2Act5Quest1Strc* pQuestDataEx = (D2Act5Quest1Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pLarzukMapAI = DRLGPRESET_CreateCopyOfMapAI(pQuestData->pGame->pMemoryPool, pMapAi);
    if (!pQuestDataEx->bLarzukSpawned)
    {
        return;
    }

    D2UnitStrc* pLarzuk = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_MONSTER, pQuestDataEx->nLarzukGUID);
    if (pLarzuk && pQuestDataEx->pLarzukMapAI && pQuestDataEx->pLarzukMapAI->pPosition && !pQuestDataEx->bLarzukMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pLarzukMapAI, AIGENERAL_GetMapAiFromUnit(pLarzuk));
        pQuestDataEx->bLarzukMapAIChanged = 1;
    }
}

// 0x005879D0
int __fastcall ACT5Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xF)
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xD)
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xE))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 0x20);
    }

    return 0;
}

// 0x00587A30
void __fastcall ACT5Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != MONSTER_QUALKEHK)
    {
        return;
    }

    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bQualKehkActivated == 1 && pQuestDataEx->nKilledWussies < 5)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bQualKehkActivated = 0;
        pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}


