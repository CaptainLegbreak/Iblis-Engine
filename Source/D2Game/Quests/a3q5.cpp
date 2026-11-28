#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2LevelIds.h"
#include "D2MonsterIds.h"
#include "D2GameObjs.h"
#include "D2ObjModes.h"
#include "FogApi.h"
#include "D2CommonApi.h"

struct D2PoolSystemStrc;
struct D2UnitStrc;

struct D2BitBufferStrc;

struct D2ActiveRoomStrc;

struct D2GameStrc;

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);              // 0x00552F60



extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QUEST_FLAG 21

#define QUEST_ID 19

#define OTHER_QUEST_FLAG 18

#define ROOM_ASSERT_LINE 223

#define QFLAG_PRIMARYGOALDONE 13

struct D2PlayerDataStrc;

struct D2ItemsTxt;

struct D2Act3Quest5Strc;

struct D2QuestDataStrc;

struct D2QuestArgStrc;

struct D2Act3Quest2Strc;

typedef int (__stdcall* FARPROC)();

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuest);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern char gpAct3Q5NpcMessages[]; // 0x007408B8

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

bool __fastcall ACT3Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BAD60

void __fastcall ACT3Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BAFD0

void __fastcall ACT3Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB120

void __fastcall ACT3Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB210

void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB400

bool __fastcall ACT3Q5_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005BB410

void __fastcall ACT3Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB480

void __fastcall ACT3Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BBC00

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


void __fastcall ACT3Q5_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BB0C0


extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAE20

int __fastcall ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB6C0

int __fastcall ACT3Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB710

int __fastcall ACT3Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB770

int __fastcall ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB7B0

#define QUESTSTATEFLAG_A3Q5 21

#define QFLAG_REWARDGRANTED 0

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_PRIMARYGOALDONE 13



static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005BAD60
bool __fastcall ACT3Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0))
    {
        return false;
    }

    if (nNpcId == 255)
    {
        if (pQuest->fState == 1)
        {
            return true;
        }
    }
    else if (nNpcId == 245)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !((D2Act3Quest5Strc*)pQuest->pQuestDataEx)->bOrbSmashed)
        {
            return true;
        }
    }

    return false;
}

// 0x005BADC0
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_REWARDGRANTED) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q5_TRAVINCAL);
    if (!pQuestData)
    {
        return 0;
    }

    const unsigned char nState = pQuestData->fState;
    if (nState >= 2 && nState <= 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_STARTED);
    }

    if (((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bMonstersSpawned)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x005BAE20
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateAfterMonsterKill(D2GameStrc* pGame,D2UnitStrc* pUnit,void* pData)
{
    D2BitBufferStrc* pFlags=PLAYER_GetQuestFlags(pGame,pUnit);
    D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pUnit);
    if (!pRoom) return 0;
    if (QUESTRECORD_GetQuestState(pFlags,QUEST_FLAG,0) || QUESTRECORD_GetQuestState(pFlags,QUEST_FLAG,4)) return 0;
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))!=2) return 0;
    D2QuestDataStrc* pQuest=QUESTS_GetQuestData(pGame,QUEST_ID);
    D2Act3Quest5Strc* pEx=(D2Act3Quest5Strc*)pQuest->pQuestDataEx;
    D2UnitStrc* pMonster=SUNIT_GetServerUnit(pGame,1,pEx->nLastKilledMonsterGUID);
    if (!pMonster) return 0;
    D2ActiveRoomStrc* pMonsterRoom=UNITS_GetRoom(pMonster);
    if (!pMonsterRoom) return 0;
    int bInRange=0;
    if(pRoom==pMonsterRoom) bInRange=1;
    else {
        D2ActiveRoomStrc* pUnitRoom=UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom,ROOM_ASSERT_LINE);
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom,&ppRoomList,&nNumRooms);
        for(unsigned int i=0;i<nNumRooms;++i){
            if(ppRoomList[i]==pMonsterRoom){bInRange=1;break;}
        }
    }
    pFlags=UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if(bInRange){
        if(QUESTRECORD_GetQuestState(pFlags,OTHER_QUEST_FLAG,0)) QUESTRECORD_SetQuestState(pFlags,QUEST_FLAG,0);
        else QUESTRECORD_SetQuestState(pFlags,QUEST_FLAG,4);
        QUESTRECORD_SetQuestState(pFlags,QUEST_FLAG,13);
    }
    return 0;
}

// 0x005BAF70
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 21, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 21, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 21, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 19);
    }

    return 0;
}

struct D2ObjInitFnStrc;

extern unsigned int gnA3Q5NpcActivateIndices[8]; // 0x00740ED8


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

// 0x005BAFD0
void __fastcall ACT3Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_REWARDGRANTED);
    int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_PRIMARYGOALDONE);
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_ENTERAREA))
    {
        if (!((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrbSmashed)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
        return;
    }

    if (bRewardGranted == 1 && !QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
        return;

    unsigned char nState = pQuestData->fState;
    if (nState >= 6)
    {
        if (bPrimaryGoalDone == 1)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        return;
    }

    if (pQuestData->bNotIntro)
    {
        unsigned int nIndex = gnA3Q5NpcActivateIndices[nState];
        if (nIndex != -1 && nIndex < 8)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x005BB0C0
void __fastcall ACT3Q5_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (short)pQuestArg->pTarget->dwClassId != 255)
    {
        return;
    }

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bOrmusActivated != 1)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bOrmusActivated = 0;
    pQuestData->pCallback[2] = 0;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BB120
void __fastcall ACT3Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;

    if (pQuestArg->nNewLevel == 82 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
        pQuestData->pCallback[2] = ACT3Q5_Callback02_NpcDeactivate;
    }

    if (nOldLevel != 75)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

    if (pQuestData->fState <= 1 || pQuestData->fState > 3)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 4) == 1)
    {
        return;
    }

    if (pQuestData->fLastState < 3)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 0);
    }

    if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
    {
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 395);
    }
    else
    {
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 399);
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BB210
void __fastcall ACT3Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) == 1)
    {
        return;
    }

    if (nNPCNo == 255)
    {
        if (nMessageIndex == 594)
        {
            if (QUESTS_GetGlobalState(pQuestArg->pGame, 17, 13) == 1)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 432);
            }
            else
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 436);
            }

            ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrmusActivated = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nNPCNo == 245)
    {
        if (nMessageIndex == 626 && QUESTRECORD_GetQuestState(pQuestFlags, 21, 4))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' yeq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rhq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rbq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 1fq');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2fq');
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 13) && pQuestData->fState != 7)
            {
                QUESTS_SetGlobalState(pQuestArg->pGame, 21, 13);
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q5_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 462);
            }

            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 465);
            pQuestData->pfSeqFilter(pQuestData);

            QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, 21, 4);

            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x005BB400
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x005BB410
bool __fastcall ACT3Q5_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 7 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 501);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005BB480
void __fastcall ACT3Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        pQuestDataEx->bOrbSmashed = 1;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_ENTERAREA) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q5, QFLAG_PRIMARYGOALDONE);
        pQuestData->bNotIntro = 0;
        return;
    }

    pQuestDataEx->bQuest1RewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q1, QFLAG_REWARDGRANTED);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_STARTED))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_LEAVETOWN))
        {
            if (pQuestDataEx->bQuest1RewardGranted)
            {
                pQuestData->fLastState = 2;
                pQuestData->fState = 2;
            }
            else
            {
                pQuestData->fLastState = 2;
                pQuestData->fState = 3;
            }
            return;
        }
    }
    else if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q5, QFLAG_LEAVETOWN))
    {
        return;
    }

    if (pQuestDataEx->bQuest1RewardGranted)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 4;
    }
    else
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 5;
    }
}

// 0x005BB550
void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q5_TRAVINCAL);
    if (!pQuestData || !pQuestData->bNotIntro)
        return;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bMonstersSpawned = 1;
    if (pQuestDataEx->nSpawnCount >= 6)
        return;

    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;

    for (int i = 0; i < pQuestDataEx->nSpawnCount; ++i)
    {
        if (pQuestDataEx->nMonsterGUIDs[i] == nUnitId)
            return;
    }

    pQuestDataEx->nMonsterGUIDs[pQuestDataEx->nSpawnCount] = nUnitId;
    ++pQuestDataEx->nSpawnCount;
    pQuestDataEx->nMonstersLeftToKill = pQuestDataEx->nSpawnCount;

    if (pQuestData->fState <= 1)
    {
        if (pQuestData->fLastState != 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }
    else
    {
        if (pQuestData->fLastState != 3)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q5_UnitIterate_StatusCyclerEx, 1);
        }
    }

    if (QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A3Q1, QFLAG_PRIMARYGOALDONE) == 1)
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 630);
    else
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 634);

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x005BB640
void __fastcall ACT3Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
    }
    else
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 4);
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 21, 13);
}

// 0x005BB6C0
int __fastcall ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q5_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x005BB710
int __fastcall ACT3Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 14);
        QUESTS_SendLogUpdateEx(pUnit, 19, 0);
    }

    return 0;
}

// 0x005BB770
int __fastcall ACT3Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 13))
    {
        SUNIT_AttachSound(pUnit, 64, pUnit);
    }

    return 0;
}

// 0x005BB7B0
int __fastcall ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 0)
        && !ITEMS_FindQuestItem(pGame, pUnit, ' 1fq') && !ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        ++pQuestDataEx->nFlailsMissing;
    }

    if (!ITEMS_FindQuestItem(pGame, pUnit, ' xob'))
    {
        ++pQuestDataEx->nHoradricCubesMissing;
    }

    return 0;
}

inline int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

inline void SetUnitFlagMask(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

// 0x005BB850
void __fastcall ACT3Q5_UnitIterate_DeleteKhalimItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 0) == 1)
    {
        QUESTS_DeleteItem(pGame, pUnit, ' yeq');
        QUESTS_DeleteItem(pGame, pUnit, ' rhq');
        QUESTS_DeleteItem(pGame, pUnit, ' rbq');
        QUESTS_DeleteItem(pGame, pUnit, ' 1fq');
        QUESTS_DeleteItem(pGame, pUnit, ' 2fq');
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) != 2)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 18, 0);
    QUESTRECORD_SetQuestState(pQuestFlags, 18, 13);

    if (!D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        QUESTS_DeleteItem(pGame, pUnit, ' yeq');
        QUESTS_DeleteItem(pGame, pUnit, ' rhq');
        QUESTS_DeleteItem(pGame, pUnit, ' rbq');
        QUESTS_DeleteItem(pGame, pUnit, ' 1fq');
        QUESTS_DeleteItem(pGame, pUnit, ' 2fq');
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !QUESTRECORD_GetQuestState(pQuestFlags, 21, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 21, 0);
    }
}

struct D2ObjOperateFnStrc;

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520



// 0x005BB980
int __fastcall OBJECTS_OperateFunction53_CompellingOrb(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2UnitStrc* pItem = INVENTORY_GetLeftHandWeapon(pOp->hPlayer->pInventory);
        if (!pItem || ITEMS_GetBaseCode(pItem) != ' 2fq')
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        }
        else
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 19);
            D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;

            pQuestDataEx->nHits += 1;
            if (pQuestDataEx->nHits >= 2)
            {
                D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
                QUESTRECORD_SetQuestState(pQuestFlags, 18, 0);
                pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
                QUESTRECORD_SetQuestState(pQuestFlags, 18, 13);

                QUESTS_DeleteItem(pOp->pGame, pOp->hPlayer, ' 2fq');

                pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
                if (QUESTRECORD_GetQuestState(pQuestFlags, 21, 4) && !QUESTRECORD_GetQuestState(sub_00543520(pOp->pGame, pOp->hPlayer), 21, 0))
                {
                    QUESTRECORD_SetQuestState(sub_00543520(pOp->pGame, pOp->hPlayer), 21, 0);
                }

                D2UnitStrc* pCompellingOrb = SUNIT_GetServerUnit(pOp->pGame, 1, pQuestDataEx->nCompellingOrbGUID);
                if (pCompellingOrb)
                {
                    AITACTICS_ChangeModeAndTargetCoordinates(pOp->pGame, pCompellingOrb, 0, 0, 0);
                    QUESTSFX_SpawnCompellingOrbMissile(pOp->pGame, pCompellingOrb);
                }

                UNITS_ChangeAnimMode(pOp->hObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->hObject ? -1 : pOp->hObject->dwClassId);
                EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
                pQuestDataEx->bOrbSmashed = 1;

                QUESTS_TriggerFX(pQuestData->pGame, 10);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 851);
                pQuestData->pfSeqFilter(pQuestData);

                const unsigned short nPartyId = SUNIT_GetPartyId(pOp->hPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pOp->pGame, nPartyId, ACT3Q5_UnitIterate_DeleteKhalimItems, 0);
                }
            }
        }
    }

    return 0;
}

// 0x005BBB70
void __fastcall OBJECTS_InitFunction53_StairsR(D2ObjInitFnStrc* pOp)
{
    if (((D2Act3Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 19)->pQuestDataEx)->bOrbSmashed)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x005BBBA0
void __fastcall OBJECTS_InitFunction60_CompellingOrb(D2ObjInitFnStrc* pOp)
{
    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 19)->pQuestDataEx;
    if (pQuestDataEx->bOrbSmashed)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }

    if (pQuestDataEx->bCompellingOrbSpawned)
    {
        return;
    }

    D2UnitStrc* pCompellingOrb = MONSTERSPAWN_SpawnAtCoordinates(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_COMPELLINGORB, 1, 0);
    if (!pCompellingOrb)
    {
        return;
    }

    pCompellingOrb->dwFlags |= 0x20000;
    pQuestDataEx->nCompellingOrbGUID = pCompellingOrb->dwUnitId;
    pQuestDataEx->bCompellingOrbSpawned = 1;
}

// 0x005BBC00
void __fastcall ACT3Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 913);

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)pQuestData->pQuestDataEx;
    int i;
    if (UNITS_GetClassIdInline(pQuestArg->pTarget) == 366)
    {
        SetUnitFlagMask(pQuestArg->pTarget, 0x20000);
        return;
    }

    if (!pQuestDataEx->bFlailDropped || !pQuestDataEx->bCubeDropped)
    {
        pQuestDataEx->nFlailsMissing = 0;
        pQuestDataEx->nHoradricCubesMissing = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_DetermineFlailAndCubeDropCounts);
    }

    if (!pQuestDataEx->bFlailDropped)
    {
        pQuestArg->pTarget->dwDropItemCode = ' 1fq';
        int nFlailsDropped = 0;
        for (i = 0; i < pQuestDataEx->nFlailsMissing; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit(pQuestData->pGame, pQuestArg->pTarget, 7, &nItemLevel, 0, -1, 0))
            {
                ++nFlailsDropped;
            }
        }

        if (nFlailsDropped)
        {
            pQuestDataEx->bFlailDropped = 1;

            D2QuestDataStrc* pQuestData16 = QUESTS_GetQuestData(pQuestData->pGame, 16);
            if (pQuestData16)
            {
                D2Act3Quest2Strc* pQuestDataEx16 = (D2Act3Quest2Strc*)pQuestData16->pQuestDataEx;
                pQuestDataEx16->nFlailsDropped += nFlailsDropped;
                pQuestDataEx16->bFlailDropped = 1;
            }
        }
    }
    else if (!pQuestDataEx->bCubeDropped)
    {
        pQuestDataEx->bCubeDropped = 1;
        pQuestArg->pTarget->dwDropItemCode = ' xob';
        for (i = 0; i < pQuestDataEx->nHoradricCubesMissing; ++i)
        {
            int nItemLevel;
            D2GAME_DropItemAtUnit(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0);
        }
    }

    if (!pQuestData->bNotIntro || pQuestDataEx->nMonstersLeftToKill <= 0)
    {
        return;
    }

    --pQuestDataEx->nMonstersLeftToKill;
    if (pQuestDataEx->nMonstersLeftToKill)
    {
        return;
    }

    pQuestDataEx->nLastKilledMonsterGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
    pQuestData->nStatusFlags = 0;
    if (pQuestDataEx->bOrbSmashed)
    {
        QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 972);
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q5_UnitIterate_StatusCyclerEx, true);
    }
    else
    {
        QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 977);
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q5_UnitIterate_StatusCyclerEx, true);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateAfterMonsterKill);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q5_UnitIterate_AttachCompletionSound);
    QUESTS_SetGlobalState(pQuestData->pGame, 21, 13);
}

// 0x005BBE20
bool __fastcall ACT3Q5_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    *pStatus = pQuest->fLastState;
    if (QUESTRECORD_GetQuestState(pFlags, 21, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 21, 13) ? 13 : 11;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 21, 4))
    {
        *pStatus = ((D2Act3Quest5Strc*)pQuest->pQuestDataEx)->bOrbSmashed ? 13 : 4;
    }

    if (!pQuest->bNotIntro)
    {
        *pStatus = 0;
    }

    return true;
}

// 0x005BBEB0
void __fastcall ACT3Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct3Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pCallback[8] = ACT3Q5_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT3Q5_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q5_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q5_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q5_Callback13_PlayerStartedGame;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pfSeqFilter = ACT3Q5_SeqCallback;
    pQuestData->nSeqId = 20;
    pQuestData->fState = 0;
    pQuestData->eFilter = 21;
    pQuestData->pfActiveFilter = ACT3Q5_ActiveFilterCallback;
    pQuestData->nInitNo = 6;
    pQuestData->pfStatusFilter = 0;

    D2Act3Quest5Strc* pQuestDataEx = (D2Act3Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q5.cpp", 1061, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
    memset(pQuestData->pQuestDataEx, 0x00, sizeof(D2Act3Quest5Strc));
}

// 0x005BBF80
bool __fastcall ACT3Q5_IsOrbNotSmashed(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    if (pQuestData)
    {
        return ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrbSmashed == 0;
    }

    return true;
}

// 0x005BBFA0
int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 19);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);

    if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_DURANCEOFHATELEV2)
    {
        return 0;
    }

    if (pQuestData)
    {
        return ((D2Act3Quest5Strc*)pQuestData->pQuestDataEx)->bOrbSmashed == 0;
    }

    return 0;
}

