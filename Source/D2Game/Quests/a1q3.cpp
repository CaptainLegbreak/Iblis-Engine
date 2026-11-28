#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2ObjModes.h"
#include "D2GameObjs.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_CUSTOM2 6

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define QUESTSTATEFLAG_A1Q3 3

#define QUEST_A1Q3_MALUS 3

#define STAT_LEVEL 12

#define LINE_CHANGEDLEVEL_DEBUG 0x189

#define LINE_SEQ_DEBUG 0x35A

#define LINE_SEQ_ASSERT 0x362

#define LINE_INIT_ALLOC 0x3AE

struct D2PoolSystemStrc;
struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2Act1Quest3Strc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs); // 0x00545300


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630



void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall ACT1Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005916A0

void __fastcall ACT1Q3_Callback06_MalusRemoved(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00591A90

bool __fastcall ACT1Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00591C30

bool __fastcall ACT1Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00591D30


void __fastcall ACT1Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall ACT1Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00591490

void __fastcall ACT1Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT1Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT1Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT1Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT1Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT1Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT1Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT1Q3_SeqCallback(D2QuestDataStrc* pQuestData);

struct D2GameStrc;

struct D2UnitStrc;

extern "C" unsigned int gnAct1Quest3NpcIndices[]; // 0x00737630


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60


void __fastcall ACT1Q3_UnitIterate_CheckForMalus(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);        // 0x00591CA0


// 0x005912E0
int __fastcall ACT1Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A1Q3_MALUS);
    }

    return 0;
}

// 0x00591340
int __fastcall ACT1Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* game, D2UnitStrc* unit, void* context)
{
    D2BitBufferStrc* flags = UNITS_GetPlayerData(unit)->pQuestData[game->nDifficulty];
    if (QUESTRECORD_GetQuestState(flags, 3, 0) == 1 || QUESTRECORD_GetQuestState(flags, 3, 1) == 1)
        return 0;
    D2QuestDataStrc* quest = QUESTS_GetQuestData(game, 3);
    if (quest) {
        signed char state = quest->fState;
        if (state == 2) {
            QUESTRECORD_SetQuestState(flags, 3, 2);
            return 0;
        }
        if (state == 3 || state == 4)
            QUESTRECORD_SetQuestState(flags, 3, 3);
    }
    return 0;
}

// 0x005913C0
void __fastcall ACT1Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_CHARSI)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bCharsiIntroActivated == 1)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bCharsiIntroActivated = 0;
    }
    else if (pQuestDataEx->bCharsiEndActivated == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, ITERSTATE_13, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bCharsiEndActivated = 0;
    }
}

// 0x00591430
void __fastcall ACT1Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    if (STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < MALUS_MIN_LEVEL)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING);
}

// 0x00591490
void __fastcall ACT1Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pItem = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS);
    D2GameStrc* pGame = pQuestArg->pGame;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo != MONSTER_CHARSI)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    if (nMessageIndex == MSG_CHARSI_END)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED))
        {
            return;
        }

        pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
        QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        if (pItem)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING);
            QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
            QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS);
            --pQuestDataEx->nMalusItemsInGame;

            const unsigned short nPartyId = SUNIT_GetPartyId(pQuestArg->pPlayer);
            if (nPartyId != 0xFFFF)
            {
                PARTY_IteratePartyMembers(pQuestArg->pGame, nPartyId, (PartyCallbackFunction)ACT1Q3_UnitIterate_SetPrimaryGoalDone, 0);
            }

            if (pQuestData->bNotIntro)
            {
                if (pQuestData->fState == QSTATE_4)
                {
                    QUESTS_StateDebug(pQuestData, QSTATE_5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_SCROLL_DEBUG5);
                    pQuestDataEx->bCharsiEndActivated = 1;
                    QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE);
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SCROLL_ASSERT1);
                    pQuestData->pfSeqFilter(pQuestData);
                }
                else if (pQuestDataEx->bStartingPlayerHasMalus)
                {
                    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
                    if (pQuest)
                    {
                        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SCROLL_ASSERT2);
                        pQuest->pfSeqFilter(pQuest);
                    }
                }
            }
        }

        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == MSG_CHARSI_INTRO)
    {
        QUESTS_StateDebug(pQuestData, QSTATE_2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_SCROLL_DEBUG2);
        pQuestDataEx->bCharsiIntroActivated = 1;
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}

// 0x005916A0
void __fastcall ACT1Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2GameStrc* pGame = pArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, 3, 0xD);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 3, 0);
    const int nNpcId = !pArg->pTarget ? -1 : pArg->pTarget->dwClassId;
    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    if (ITEMS_FindQuestItem(pArg->pGame, pArg->pPlayer, 0x206D6468))
    {
        if (STATLIST_GetUnitBaseStat(pArg->pPlayer, STAT_LEVEL, 0) >= 8 && !QUESTRECORD_GetQuestState(pQuestFlags, 3, 0))
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, 3);
        }
    }
    else if (bRewardGranted != 1)
    {
        if (!pQuest->fState || pQuest->fState == 4)
        {
            return;
        }

        const unsigned int nIndex = gnAct1Quest3NpcIndices[pQuest->fState];
        if (nIndex != -1 && nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x00591790
void __fastcall ACT1Q3_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_SetQuestState(pQuestFlags, 3, 0);
    QUESTRECORD_ClearQuestState(pQuestFlags, 3, 1);

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 3, 0x0F))
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 3);
        D2_ASSERT(pQuestData, 0x160);

        pQuestData->bActive = 0;

        QUESTS_DebugOutput(pGame, "deactivated tools of trade", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 0x164);
    }
}

// 0x00591810
void __fastcall ACT1Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    if (!pQuestData->bNotIntro)
    {
        pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = 0;
        return;
    }

    if (nOldLevel != LEVEL_ROGUEENCAMPMENT)
    {
        return;
    }

    if (pQuestData->fState != QSTATE_2)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    if (pQuestData->fLastState != 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
    }

    QUESTS_StateDebug(pQuestData, QSTATE_3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_CHANGEDLEVEL_DEBUG);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q3_UnitIterate_UpdateQuestStateFlags);
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = 0;
}

// 0x005918D0
static bool ACT1Q3_ResetMalus(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->bNotIntro)
    {
        return false;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nMalusObjectMode = 0;
    if (!pQuestDataEx->bMalusInitialized)
    {
        return false;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 0x1C8);
    pQuestData->nStatusFlags = 1;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, true);
    pQuestDataEx->unused0x08 = 0;
    if (pQuestDataEx->bMalusInitialized == 1)
    {
        D2UnitStrc* pMalus = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nMalusGUID);
        if (pMalus && pMalus->dwClassId == 0x6C)
        {
            UNITS_ChangeAnimMode(pMalus, 0);
            return true;
        }

        pQuestDataEx->bMalusInitialized = 0;
    }

    return true;
}

// 0x00591960
void __fastcall ACT1Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_CUSTOM2))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_CUSTOM2);
        SUNIT_AttachSound(pQuestArg->pPlayer, SOUND_MALUS_PICKUP, pQuestArg->pPlayer);
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, ITERSTATE_2, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
}

// 0x005919C0
static inline void ACT1Q3_SetLastStateTwo(D2QuestDataStrc* pQuestData)
{
    pQuestData->fLastState = 2;
}

// 0x005919D0
void __fastcall ACT1Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS))
    {
        return;
    }

    if (!pQuestData->bNotIntro || pQuestData->fState == QSTATE_5)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    ++pQuestDataEx->nMalusItemsInGame;

    if (pQuestDataEx->nMalusItemsInGame == 1 && pQuestDataEx->bMalusInitialized && pQuestDataEx->nMalusObjectMode == OBJMODE_OPENED)
    {
        ACT1Q3_SetLastStateTwo(pQuestData);
    }
}

// 0x00591A20
void __fastcall ACT1Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro || pQuestData->fState == QSTATE_5)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    --pQuestDataEx->nMalusItemsInGame;

    if (!pQuestDataEx->nMalusItemsInGame && pQuestDataEx->bMalusInitialized && pQuestDataEx->nMalusObjectMode == OBJMODE_OPENED)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, ITERSTATE_3, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x00591A60
void __fastcall ACT1Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x00591A90
void __fastcall ACT1Q3_Callback06_MalusRemoved(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
    --pQuestDataEx->nMalusItemsInGame;
    if (!pQuestDataEx->nMalusItemsInGame && pQuestDataEx->nMalusObjectMode == 2)
    {
        ACT1Q3_ResetMalus(pQuestData);
    }
}

struct D2ObjOperateFnStrc;
enum
{
    ITEMQUAL_NORMAL = 2,
};

struct D2ItemDropStrc;

// 0x00591AC0
int __fastcall OBJECTS_OperateFunction21_HoradrimMalus(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q3_MALUS);
    if (!pQuestData)
    {
        return 0;
    }

    const int nAnimMode = !pOp->hObject ? 0 : pOp->hObject->dwAnimMode;
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    if (!nAnimMode)
    {
        D2UnitStrc* pPlayer = pOp->hPlayer;
        D2GameStrc* pGame = pOp->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) == 1)
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING) == 1)
        {
            return 0;
        }

        if (STATLIST_GetUnitBaseStat(pOp->hPlayer, STAT_LEVEL, 0) < 8)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        int nItemLevel;
        pOp->hObject->dwDropItemCode = ' mdh';
        if (D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
            D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->bMalusInitialized = 1;
            pQuestDataEx->nMalusObjectMode = OBJMODE_OPENED;
            pQuestDataEx->nMalusGUID = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
            ++pQuestDataEx->nMalusItemsInGame;
            if (pQuestData->fState != 4)
            {
                QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", 706);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q3_UnitIterate_UpdateQuestStateFlags);
            }

            if (pQuestData->fLastState != 1)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q3_UnitIterate_StatusCyclerEx, 0);
            }
        }
    }

    return 0;
}

// 0x00591C30
bool __fastcall ACT1Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_CHARSI && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0) >= 8 && ITEMS_FindQuestItem(SUNIT_GetGameFromUnit(pPlayer), pPlayer, ' mdh'))
        {
            return true;
        }
    }

    return false;
}

// 0x00591CA0
void __fastcall ACT1Q3_UnitIterate_CheckForMalus(D2GameStrc* game, D2UnitStrc* unit, void* unused)
{
    if (ITEMS_FindQuestItem(game, unit, 0x206D6468))
    {
        D2QuestDataStrc* quest = QUESTS_GetQuestData(game, 3);
        if (quest)
            ((D2Act1Quest3Strc*)quest->pQuestDataEx)->bMalusAcquired = 1;
    }
}

// 0x00591CD0
static int ACT1Q3_HasHoradricMalus(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer)
{
    if (ITEMS_FindQuestItem(SUNIT_GetGameFromUnit(pPlayer), pPlayer, ' mdh'))
    {
        return 1;
    }

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuest->pQuestDataEx;
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId == 0xFFFF)
    {
        return 0;
    }

    pQuestDataEx->bMalusAcquired = 0;
    PARTY_IteratePartyMembers(pQuest->pGame, nPartyId, ACT1Q3_UnitIterate_CheckForMalus, 0);
    return pQuestDataEx->bMalusAcquired != 0;
}

// 0x00591D30
bool __fastcall ACT1Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING))
    {
        *pStatus = 10;
        return true;
    }

    if (ACT1Q3_HasHoradricMalus(pQuest, pPlayer))
    {
        if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDGRANTED))
        {
            *pStatus = 2;
        }
        return true;
    }

    if (!pQuest->bNotIntro)
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_REWARDPENDING) ? 10 : 13;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q3, QFLAG_COMPLETEDNOW))
    {
        *pStatus = 12;
        return true;
    }

    if (pQuest->fState < 5)
    {
        *pStatus = pQuest->fLastState;
        return true;
    }

    if (QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A1Q3, QFLAG_PRIMARYGOALDONE))
    {
        *pStatus = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0) >= 8 ? 12 : 4;
    }

    return true;
}

// 0x00591F70
void __fastcall ACT1Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT1Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM] = ACT1Q3_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pCallback[QUESTEVENT_PLAYERJOINEDGAME] = ACT1Q3_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[QUESTEVENT_ITEMPICKEDUP] = ACT1Q3_Callback04_ItemPickedUp;
    pQuestData->pCallback[QUESTEVENT_MALUSREMOVED] = ACT1Q3_Callback06_MalusRemoved;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q3_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT1Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT1Q3_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q3_SeqCallback;
    pQuestData->pNPCMessages = gpAct1Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->eFilter = QUESTSTATEFLAG_A1Q3;

    D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_INIT_ALLOC, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->fState = 0;
    pQuestData->pfStatusFilter = ACT1Q3_StatusFilterCallback;
    pQuestData->nInitNo = A1Q3_INITNO;
    pQuestData->pfActiveFilter = ACT1Q3_ActiveFilterCallback;
    pQuestData->nSeqId = A1Q3_SEQID;

    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest3Strc));
    pQuestDataEx->unused0x00 = 0;
    pQuestDataEx->nMalusGUID = 0;
    pQuestDataEx->unused0x10 = 0;
    pQuestDataEx->unused0x12 = 0;
    pQuestDataEx->bMalusInitialized = 0;
    pQuestDataEx->unused0x08 = 0;
    pQuestDataEx->bCharsiIntroActivated = 0;
    pQuestDataEx->bCharsiEndActivated = 0;
    pQuestDataEx->nMalusObjectMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x00591E40
bool __fastcall ACT1Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q3.cpp", LINE_SEQ_DEBUG);
        return true;
    }

    if (pQuestData->fState != QSTATE_5 && pQuestData->bNotIntro)
    {
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

// 0x00591ED0
void __fastcall ACT1Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEMCODE_MALUS))
    {
        D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
        ++pQuestDataEx->nMalusItemsInGame;
        pQuestDataEx->bStartingPlayerHasMalus = 1;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_STARTED) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = QSTATE_2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q3, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = QSTATE_3;
        pQuestData->fLastState = 1;
    }
}
// 0x00592090
void __fastcall ACT1Q3_ACT1Q3_InitMalusObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (pQuestData)
    {
        D2Act1Quest3Strc* pQuestDataEx = (D2Act1Quest3Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->bMalusInitialized = 1;
        pQuestDataEx->nMalusGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
        if (!pQuestData->bNotIntro)
        {
            pQuestDataEx->nMalusObjectMode = 2;
        }
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nMalusObjectMode);
    }
}

