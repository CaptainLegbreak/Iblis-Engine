#include "D2GameEvents.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2Structs.h"
#include "D2GameAux.h"
#include "D2GameObjs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2Drlg.h"
#include "D2ObjModes.h"
#include "D2CommonApi.h"

#define QFLAG_REWARDGRANTED 0

#define QFLAG_CUSTOM7 11

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define ACT_III 2


#define QUESTSTATEFLAG_A3COMPLETED 23

struct D2PoolSystemStrc;
struct D2MapAIPathPositionStrc;

struct D2PlayerDataStrc;

struct D2Act3Quest6Strc;

struct D2QuestGUIDStrc;

struct D2ObjInitFnStrc;

struct Player;

struct QuestEx;

struct Args;

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"


typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630


void __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern unsigned gnAct3Q6NpcMessageIndices[]; // 0x00741518

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int nUnitGUID); // 0x005452C0

enum { QUEST_ID = 22 };

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);


extern "C" const char gszAct3Q6SourceFile[]; // 0x006E2F7C


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

int __fastcall ACT3Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC020


void __fastcall ACT3Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC370


#define UNIT_MONSTER 1

struct D2Act3Quest5Strc;

typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct3Q5SourceFile[];


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2MapAIStrc** __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

bool __fastcall ACT3Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BBFE0

void __fastcall ACT3Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC270

void __fastcall ACT3Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC3C0

void __fastcall ACT3Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC5A0

void __fastcall ACT3Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC710

void __fastcall ACT3Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BC8B0

bool __fastcall ACT3Q6_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005BCC60

void __fastcall ACT3Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BCC80

extern "C" char gpAct3Q6NpcMessages[]; // 0x00740EF8

struct D2QuestDataStrc;


typedef int(__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

#define UNIT_PLAYER 0

#define UNIT_OBJECT 2


#define ITEMQUAL_NORMAL 2


void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


void __fastcall D2Game_10034_Return(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990


void __fastcall ACT4Q3_OnSoulstonesDropped(D2GameStrc* pGame, int nSoulStonesDropped); // 0x005B6930

int __fastcall ACT3Q6_UnitIterate_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC190

bool __fastcall ACT3Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x005BC720

int __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC7C0

int __fastcall ACT3Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC810

int __fastcall ACT3Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC870


static void __stdcall ACT3Q6_SetCompletionStates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags);



// 0x005BBFE0
bool __fastcall ACT3Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 0) || nNpcId != 255 || pQuest->fState != 1)
    {
        return QUESTRECORD_GetQuestState(pQuestFlags, 22, 11);
    }

    return true;
}

// 0x005BC020
int __fastcall ACT3Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pFlags, 22, 0) == 1 || QUESTRECORD_GetQuestState(pFlags, 22, 11) == 1)
        return 0;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, 20);
    if (!pQuest)
        return 0;
    switch (pQuest->fState)
    {
    case 2:
        QUESTRECORD_SetQuestState(pFlags, 22, 2);
        return 0;
    case 3:
        QUESTRECORD_SetQuestState(pFlags, 22, 3);
        return 0;
    case 4:
        if (pQuest->fLastState == 2)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 4);
            return 0;
        }
        if (pQuest->fLastState == 3)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 5);
            return 0;
        }
        if (pQuest->fLastState == 4)
            QUESTRECORD_SetQuestState(pFlags, 22, 6);
        return 0;
    case 5:
        if (pQuest->fLastState == 2)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 7);
            return 0;
        }
        if (pQuest->fLastState == 3)
        {
            QUESTRECORD_SetQuestState(pFlags, 22, 8);
            return 0;
        }
        if (pQuest->fLastState == 4)
            QUESTRECORD_SetQuestState(pFlags, 22, 9);
        return 0;
    }
    return 0;
}

// 0x005BC140
static void __stdcall ACT3Q6_SetCompletionStates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7);
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 204), 3, pGame->nDifficulty);
}

// 0x005BC190
int __fastcall ACT3Q6_UnitIterate_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_DURANCEOFHATELEV3)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q6_MEPHISTO);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7))
    {
        return 0;
    }

    ACT3Q6_SetCompletionStates(pGame, pUnit, pQuestFlags);
    ++((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nSoulstonesToDrop;
    return 0;
}

// 0x005BC210
int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A3Q6_MEPHISTO);
    }

    return 0;
}

// 0x005BC270
void __fastcall ACT3Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    int bRewardPending = QUESTRECORD_GetQuestState(pQuestFlags, QUEST_ID, 0);
    int bGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUEST_ID, 13);
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, 11)) {
        QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, nNpcId, 5);
        return;
    }
    if (bRewardPending == 1) {
        if (QUESTS_CheckPlayerGUID(pQuest, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1) QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, nNpcId, 6);
        return;
    }
    unsigned char nState = pQuest->fState;
    if (nState >= 6) {
        if (bGoalDone == 1) QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, nNpcId, 6);
        return;
    }
    {
        unsigned nIndex = gnAct3Q6NpcMessageIndices[nState];
        if (nIndex != -1 && nIndex < 8) QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x005BC370
void __fastcall ACT3Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_ORMUS)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bOrmusActivated != 1)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bOrmusActivated = 0;
    pQuestData->pCallback[2] = 0;
}

static inline int ACT3Q6_CycleStatusFromLastState(D2QuestDataStrc* pQuestData)
{
    int bResult = 0;
    if (pQuestData->fLastState == 2)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        bResult = 1;
    }
    else if (pQuestData->fLastState == 0)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        bResult = 1;
    }
    return bResult;
}

// 0x005BC3C0
void __fastcall ACT3Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == 75)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState > 1 && pQuestData->fState <= 3)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1)
            {
                return;
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 11) == 1)
            {
                return;
            }

            if (pQuestData->fLastState < 3)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 0);
            }

            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 364);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 368);
            }

            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q6_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel >= 98 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
        pQuestData->pCallback[2] = ACT3Q6_Callback02_NpcDeactivate;
    }

    if (nNewLevel == 100)
    {
        int bUpdate = ACT3Q6_CycleStatusFromLastState(pQuestData);

        if (pQuestData->fState == 1)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 400);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 404);
            }
            bUpdate = 1;
        }

        if (bUpdate)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q6_UnitIterate_UpdateQuestStateFlags);
        }
    }
    else if (nNewLevel == 102)
    {
        if (pQuestData->fLastState != 4)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
        }

        if (pQuestData->fState != 4 && pQuestData->fState != 5)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 4, gszAct3Q6SourceFile, 426);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 5, gszAct3Q6SourceFile, 430);
            }
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q6_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x005BC5A0
void __fastcall ACT3Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 22, 11) && QUESTRECORD_GetQuestState(pQuestFlags, 22, 0))
    {
        return;
    }

    if (nNPCNo == 255 && nMessageIndex == 628)
    {
        if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 463);
        }
        else
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 467);
        }

        ((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->bOrmusActivated = 1;
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        return;
    }

    if (nMessageIndex == 658 || nMessageIndex == 657 || nMessageIndex == 659 || nMessageIndex == 660
        || nMessageIndex == 661 || nMessageIndex == 662 || nMessageIndex == 663)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 11))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 22, 13))
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q6_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 487);
            }

            QUESTRECORD_ClearQuestState(pQuestFlags, 22, 11);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}

// 0x005BC710
void __fastcall ACT3Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x005BC720
bool __fastcall ACT3Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fLastState != 4)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q6_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bTimerStarted = 0;
    return 1;
}

// 0x005BC750
void __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != ACT_III)
    {
        return;
    }

    ACT3Q6_SetCompletionStates(pGame, pUnit, pQuestFlags);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q6_MEPHISTO);
    if (pQuestData)
    {
        ++((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nSoulstonesToDrop;
    }
}

// 0x005BC7C0
int __fastcall ACT3Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q6_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x005BC810
int __fastcall ACT3Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A3Q6_MEPHISTO, 0);
    }

    return 0;
}

// 0x005BC870
int __fastcall ACT3Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 66, pUnit);
    }

    return 0;
}

static inline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005BC8B0
void __fastcall ACT3Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nItemLevel;

    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 619);
    QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 620);

    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT3Q6_Callback10_PlayerLeavesGame;
    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer && !QUESTRECORD_GetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED))
        {
            D2Game_10034_Return(pQuestData, pQuestArg, 62);

            if (!QUESTRECORD_GetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_CUSTOM7))
            {
                ++((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nSoulstonesToDrop;
            }

            ACT3Q6_SetCompletionStates(pQuestArg->pGame, pQuestArg->pPlayer, sub_00543520(pQuestData->pGame, pQuestArg->pPlayer));
        }

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_UpdateQuestStateAfterMonsterKill);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_SetCompletionFlag);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT3Q6_UnitIterate_AttachCompletionSound);

        if (!pQuestDataEx->bTimerStarted)
        {
            QUESTS_CreateTimer(pQuestData, ACT3Q6_Timer_StatusCycler, 12);
            pQuestDataEx->bTimerStarted = 1;
        }
    }

    QUESTS_SetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE);

    if (pQuestDataEx->bHellGatePortalInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nHellGatePortalGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, OBJMODE_OPERATING);
            const int nClassId = pObject->dwClassId;
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
            EVENT_SetEvent(pQuestData->pGame, pObject, EVENTTYPE_ENDANIM, pQuestData->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
        }
    }
    pQuestDataEx->nHellGatePortalObjectMode = OBJMODE_OPENED;

    pQuestArg->pTarget->dwDropItemCode = ' ssm';
    for (int i = 0; i < pQuestDataEx->nSoulstonesToDrop; ++i)
    {
        if (D2GAME_DropItemAtUnit(pQuestArg->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            ++pQuestDataEx->nSoulStonesDropped;
            pQuestDataEx->bSoulStoneDropped = 1;
        }
    }

    ACT4Q3_OnSoulstonesDropped(pQuestData->pGame, pQuestDataEx->nSoulStonesDropped);
    QUESTS_TriggerFX(pQuestData->pGame, 11);
}

static inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

// 0x005BCAC0
void __fastcall ACT3Q6_UpdateHellGatePortal(D2QuestDataStrc* pQuest, D2UnitStrc* pObject)
{
    D2Act3Quest6Strc* pEx = (D2Act3Quest6Strc*)pQuest->pQuestDataEx;
    if (pEx->nHellGatePortalObjectMode == 2)
    {
        const int nMode = !pObject ? 0 : pObject->dwAnimMode;
        if (nMode == 2) return;
        for (D2UnitStrc* pUnit = UNITS_GetRoom(pObject)->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            if (UNITS_GetUnitTypeInline(pUnit) == 0 && (unsigned int)D2Common_10399(pUnit, pObject) < 18)
            {
                if (nMode == 0)
                {
                    pEx->nMephistoBridgeObjectMode = 2;
                    UNITS_ChangeAnimMode(pObject, 1);
                }
                else if (nMode == 1)
                {
                    pEx->nMephistoBridgeObjectMode = 2;
                    UNITS_ChangeAnimMode(pObject, 2);
                    UNITS_FreeCollisionPath(pObject);
                }
                EVENT_SetEvent(pQuest->pGame, pObject, 7, pQuest->pGame->dwGameFrame + 24, 0, 0);
                return;
            }
        }
    }
    EVENT_SetEvent(pQuest->pGame, pObject, 7, pQuest->pGame->dwGameFrame + 24, 0, 0);
}

// 0x005BCB90
void __fastcall OBJECTS_InitFunction45_MephistoBridge(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q6_MEPHISTO);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bMephistoBridgeInitialized = 1;
    pQuestDataEx->nMephistoBridgeGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nMephistoBridgeObjectMode);
    if (pQuestDataEx->nMephistoBridgeObjectMode != OBJMODE_OPENED)
    {
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + 20, 0, 0);
    }
}

// 0x005BCBF0
void __fastcall OBJECTS_InitFunction44_HellGatePortal(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q6_MEPHISTO);
    if (DUNGEON_GetLevelIdFromRoom(pOp->pRoom) == LEVEL_OUTERSTEPPES)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
        return;
    }

    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bHellGatePortalInitialized = 1;
    pQuestDataEx->nHellGatePortalGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nHellGatePortalObjectMode);
}

// 0x005BCC60
bool __fastcall ACT3Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro)
    {
        pQuestData->fState = 1;
        pQuestData->pCallback[2] = ACT3Q6_Callback02_NpcDeactivate;
    }

    return true;
}

// 0x005BCC80
void __fastcall ACT3Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 11) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3COMPLETED, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE);
        ((D2Act3Quest6Strc*)pQuestData->pQuestDataEx)->nHellGatePortalObjectMode = OBJMODE_OPENED;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 9) == 1)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 4;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 8) == 1)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 7) == 1)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 6) == 1)
    {
        pQuestData->fState = 4;
        pQuestData->fLastState = 4;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 5) == 1)
    {
        pQuestData->fState = 4;
        pQuestData->fLastState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 4) == 1)
    {
        pQuestData->fState = 4;
        pQuestData->fLastState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 3) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q6, 2) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 2;
    }
}


// 0x005BCDC0
void __fastcall ACT3Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct3Q6NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pCallback[8] = ACT3Q6_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT3Q6_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q6_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q6_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q6_Callback13_PlayerStartedGame;
    pQuestData->pCallback[10] = ACT3Q6_Callback10_PlayerLeavesGame;
    pQuestData->pfSeqFilter = ACT3Q6_SeqCallback;
    pQuestData->fState = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A3Q6;
    pQuestData->nInitNo = 6;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT3Q6_ActiveFilterCallback;

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest6Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q6.cpp", 896, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest6Strc));
}

// 0x005BCE80
void __fastcall OBJECTS_InitFunction52_NatalyaStart(D2ObjInitFnStrc* pOp)
{
    if (QUESTS_GetGlobalState(pOp->pGame, QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE))
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q6_MEPHISTO)->pQuestDataEx;

    if (pQuestDataEx->bNatalyaSpawned)
    {
        D2UnitStrc* pNatalya = SUNIT_GetServerUnit(pOp->pGame, UNIT_MONSTER, pQuestDataEx->nNatalyaGUID);
        if (pNatalya && pNatalya->dwClassId == MONSTER_NATALYA)
        {
            return;
        }
    }

    D2UnitStrc* pNatalya = D2GAME_SpawnMonster(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_NATALYA, 1, -1, 0);
    if (!pNatalya)
    {
        pNatalya = D2GAME_SpawnMonster(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_NATALYA, 1, 3, 0);
    }

    if (!pNatalya)
    {
        pQuestDataEx->bNatalyaSpawned = 0;
        return;
    }

    pQuestDataEx->bNatalyaSpawned = 1;
    pQuestDataEx->nNatalyaGUID = !pNatalya ? -1 : pNatalya->dwUnitId;

    if (pNatalya && pQuestDataEx->pNatalyaMapAI && pQuestDataEx->pNatalyaMapAI->pPosition && !pQuestDataEx->bNatalyaMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNatalyaMapAI, AIGENERAL_GetMapAiFromUnit(pNatalya));
        pQuestDataEx->bNatalyaMapAIChanged = 1;
    }
}

// 0x005BCF60
void __fastcall ACT3Q6_UpdatePlayerStatus(D2GameStrc* pGame, bool bRestore)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q6_MEPHISTO);
    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fState >= 6)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    int nStatus;
    if (bRestore)
    {
        nStatus = pQuestDataEx->nSavedStatus;
    }
    else
    {
        pQuestDataEx->nSavedStatus = pQuestData->fLastState;
        nStatus = (pQuestData->pGame->nGameType != 3) ? 7 : 6;
    }

    bool bIterate = false;
    if (pQuestData->fState > 0)
    {
        bIterate = true;
    }
    QUESTS_UnitIterate(pQuestData, nStatus, 0, ACT3Q6_UnitIterate_StatusCyclerEx, bIterate);
}

// 0x005BCFD0
void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 20);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;

    pQuestDataEx->nHellGatePortalObjectMode = 2;
    pQuestDataEx->nMephistoBridgeObjectMode = 2;

    if (pQuestDataEx->bHellGatePortalInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nHellGatePortalGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, 1);
        }
    }

    if (pQuestDataEx->bMephistoBridgeInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nMephistoBridgeGUID);
        if (pObject)
        {
            UNITS_ChangeAnimMode(pObject, 2);
        }
    }
}

// 0x005BD040
void __fastcall ACT3Q6_ChangeNatalyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 20);
    if (!pQuestData)
        return;
    D2Act3Quest6Strc* pQuestDataEx = (D2Act3Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pNatalyaMapAI = pMapAI;
    if (!pQuestDataEx->bNatalyaSpawned)
        return;
    D2UnitStrc* pNatalya = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nNatalyaGUID);
    if (pNatalya && pQuestDataEx->pNatalyaMapAI && pQuestDataEx->pNatalyaMapAI->pPosition && !pQuestDataEx->bNatalyaMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNatalyaMapAI, AIGENERAL_GetMapAiFromUnit(pNatalya));
        pQuestDataEx->bNatalyaMapAIChanged = 1;
    }
}

struct D2ActiveRoomStrc;

struct D2GameStrc;

struct D2UnitStrc;

