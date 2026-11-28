#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2Txt.h"
#include "D2MonsterIds.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#define QUEST_A4Q3_HELLFORGE 24

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_CUSTOM1 5

struct D2PoolSystemStrc;
struct D2PlayerDataStrc;

struct D2Act4Quest3Strc;

struct D2QuestGUIDStrc;

struct D2Act3Quest3Strc;

struct D2Act3Quest4Strc;

struct D2Act3Quest5Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190


typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


int __fastcall ACT3Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B9E70

typedef int (__fastcall* UnitCallback)(D2GameStrc*,D2UnitStrc*,void*);

typedef void (__fastcall* PartyCallback)(D2GameStrc*,D2UnitStrc*,void*);


void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380


D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*,D2UnitStrc*); // 0x00543520

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc*,unsigned short,PartyCallback,void*); // 0x00540510


void __fastcall ACT4Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc*,D2UnitStrc*,void*); // 0x005B5B00

int __fastcall ACT4Q3_UnitIterate_SetCompletionFlag(D2GameStrc*,D2UnitStrc*,void*); // 0x005B5BB0

static inline int UNITS_GetClassIdInline(D2UnitStrc* unit){ if(!unit)return -1; return unit->dwClassId; }

static inline int UNITS_GetAnimModeInline(D2UnitStrc* unit){ if(!unit)return 0; return unit->dwAnimMode; }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern char gpAct4Q3NpcMessages[];                                                                          // 0x0073E140

extern char gpAct4Q4NpcMessages[];                                                                          // 0x0073E5C0


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);           // 0x00545310



bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B69E0


void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6C60


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0



// 0x005B59C0
int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A4Q3_HELLFORGE);
    }

    return 0;
}

#define PREFIX

#define QUEST_ID 24

#define STATE_A 13

#define STATE_B 2

#define STATE_C 3

#define FALLBACK_MODE 3

#define ITERATE_STATE 2

// 0x005B5A20
void __fastcall OBJECTS_InitFunction48_HellForge(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pOp->pGame, QUEST_ID);
    if (pQuest && pQuest->bNotIntro)
    {
        D2Act4Quest3Strc* pEx = (D2Act4Quest3Strc*)pQuest->pQuestDataEx;
        UNITS_ChangeAnimMode(pOp->pObject, pEx->nHellforgeMode);
        if (pQuest->fLastState != STATE_A && pQuest->fLastState != STATE_B && pQuest->fLastState != STATE_C)
        {
            pQuest->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuest, ITERATE_STATE, 0, ACT4Q3_UnitIterate_StatusCyclerEx, true);
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, FALLBACK_MODE);
    }
}

// 0x005B5A90
void __fastcall ACT4Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING)
        || !pQuestData->bNotIntro || pQuestData->fLastState == 13)
    {
        return;
    }

    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 135);
    }
}

// 0x005B5B00
void __fastcall ACT4Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_IV)
    {
        return;
    }

    QUESTS_DeleteItem(pGame, pUnit, ' hfh');
    QUESTS_DeleteItem(pGame, pUnit, ' ssm');
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, QUESTSTATEFLAG_A4Q3);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A4Q3_HELLFORGE);
    if (pQuestData)
    {
        ++((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->nPlayersInAct;
    }
}

// 0x005B5BB0
int __fastcall ACT4Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_COMPLETEDNOW);
    QUESTS_SendLogUpdateEx(pUnit, QUEST_A4Q3_HELLFORGE, 0);
    return 0;
}

// 0x005B5C10
int __fastcall OBJECTS_OperateFunction49_HellForge(D2ObjOperateFnStrc* operation)
{
 D2QuestDataStrc* quest=QUESTS_GetQuestData(operation->pGame,24);
 if(!quest)return 0;
 D2GameStrc* game=operation->pGame;
 D2BitBufferStrc* flags=UNITS_GetPlayerData(operation->hPlayer)->pQuestData[game->nDifficulty];
 if(QUESTRECORD_GetQuestState(flags,27,0)==1 || QUESTRECORD_GetQuestState(flags,27,1)==1)goto playSound;
 {
  D2Act4Quest3Strc* data=(D2Act4Quest3Strc*)quest->pQuestDataEx;
  D2ObjectsTxt* record=DATATBLS_GetObjectsTxtRecord(UNITS_GetClassIdInline(operation->hObject));
  int mode=UNITS_GetAnimModeInline(operation->hObject);
  switch(mode){
   case 0:
    if(ITEMS_FindQuestItem(operation->pGame,operation->hPlayer,0x2073736d)){
     UNITS_ChangeAnimMode(operation->hObject,1);
     EVENT_SetEvent(operation->pGame,operation->hObject,1,operation->pGame->dwGameFrame+(record->dwFrameCnt[1]>>8),0,0);
     data->nHellforgeMode=2;quest->dwFlags&=0xFFFFFF00;
     QUESTS_UnitIterate(quest,3,0,ACT4Q3_UnitIterate_StatusCyclerEx,true);
     QUESTS_DeleteItem(operation->pGame,operation->hPlayer,0x2073736d);
     return 0;
    }
    SUNIT_AttachSound(operation->hPlayer,19,operation->hPlayer);
    if(quest->bNotIntro && !quest->fState)QUESTS_StateDebug(quest,1,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp",241);
    break;
   case 2: {
    D2UnitStrc* item=ITEMS_FindQuestItem(operation->pGame,operation->hPlayer,0x20686668);
    if(!item)goto playSound;
    D2InventoryStrc* inventory=operation->hPlayer->pInventory;
    if(!inventory){SUNIT_AttachSound(operation->hPlayer,19,operation->hPlayer);return 0;}
    item=INVENTORY_GetLeftHandWeapon(inventory);
    if(!item || DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInline(item))->dwCode!=0x20686668)goto playSound;
    if(++data->nHammerHits>2){
    UNITS_ChangeAnimMode(operation->hObject,3);
    data->nHellforgeMode=3;
    QUESTS_DeleteItem(operation->pGame,operation->hPlayer,0x20686668);
    flags=sub_00543520(operation->pGame,operation->hPlayer);
    QUESTRECORD_SetQuestState(flags,27,13);
    QUESTRECORD_SetQuestState(flags,27,1);
    QUESTRECORD_ResetIntermediateStateFlags(flags,quest->eFilter);
    data->bRewardPending=1;data->bRewardDropsPending=1;data->nRewardState=4;data->nPlayersInAct=1;
    unsigned short party=SUNIT_GetPartyId(operation->hPlayer);
    if(party!=0xffff)PARTY_IteratePartyMembers(operation->pGame,party,ACT4Q3_UnitIterate_SetPrimaryGoalDone,0);
    QUESTS_StateDebug(quest,4,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp",293);
    quest->dwFlags&=0xFFFFFF00;
    QUESTS_UnitIterate(quest,13,0,ACT4Q3_UnitIterate_StatusCyclerEx,true);
    EVENT_SetEvent(operation->pGame,operation->hObject,7,operation->pGame->dwGameFrame+(record->dwFrameCnt[3]>>8),0,0);
    SUNIT_IterateUnitsOfType(operation->pGame,0,operation->hPlayer,ACT4Q3_UnitIterate_SetCompletionFlag);
    QUESTS_TriggerFX(operation->pGame,14);
    return 0;
    }
    break;
   }
  }
 }
 return 0;
playSound:
 SUNIT_AttachSound(operation->hPlayer,19,operation->hPlayer);
 return 0;
}

// 0x005B5EE0
bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nId = nNpcId;
    if (nId == MONSTER_CAIN4 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING)
        && pQuest->bNotIntro && pQuest->fState == 1 && !((D2Act4Quest3Strc*)pQuest->pQuestDataEx)->bSoulstoneAcquired)
    {
        return true;
    }

    return false;
}

// 0x005B6050
void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x005B64A0
void __fastcall ACT4Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_GetBaseCode(pQuestArg->pTarget) == 0x20686668)
    {
        --pQuestDataEx->nHellforgeHammersInGame;
    }
}

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B6080
void __fastcall ACT4Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != 103)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 433);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q3_UnitIterate_UpdateQuestStateFlags);
}

// 0x005B64C0
void __fastcall ACT4Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20686668))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }
}

// 0x005B6610
void __fastcall ACT4Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pfActiveFilter = ACT4Q3_ActiveFilterCallback;
    pQuestData->pQuestDataEx = 0;
    pQuestData->fLastState = 0;
    pQuestData->fState = 0;
    pQuestData->pNPCMessages = gpAct4Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfSeqFilter = ACT4Q3_SeqCallback;
    pQuestData->nSeqId = 23;
    pQuestData->eFilter = 27;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT4Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT4Q3_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT4Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT4Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT4Q3_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT4Q3_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT4Q3_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pCallback[8] = ACT4Q3_Callback08_MonsterKilled;
    pQuestData->pCallback[4] = ACT4Q3_Callback04_ItemPickedUp;

    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 856, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest3Strc));
}

union D2SeedStrc;


extern unsigned int gnHellforgeRunesNormal[]; // 0x0073E114

extern unsigned int gnHellforgeRunesNightmare[]; // 0x0073E514

extern unsigned int gnHellforgeRunesHell[]; // 0x0073E540

extern unsigned int gnHellforgeGemsFirst[]; // 0x0073E56C

extern unsigned int gnHellforgeGemsMiddle[]; // 0x0073E588

extern unsigned int gnHellforgeGemsLast[]; // 0x0073E5A4

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return (unsigned int)seed;
}

// 0x005B6710
void __fastcall ACT4Q3_CreateReward(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bRewardPending) UNITS_ChangeAnimMode(pUnit, 4);
    if (pQuestDataEx->bRewardDropsPending)
    {
        int nItemLevel = 50;
        int nDropped = 0;
        for (int i = 0; i < pQuestDataEx->nPlayersInAct; ++i)
        {
            switch (pQuestDataEx->nRewardState)
            {
            case 4: pUnit->dwDropItemCode = gnHellforgeGemsFirst[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            case 2:
            case 3: pUnit->dwDropItemCode = gnHellforgeGemsMiddle[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            case 1: pUnit->dwDropItemCode = gnHellforgeGemsLast[RollSeed(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7]; break;
            default: return;
            }
            if (D2GAME_DropItemAtUnit(pQuestData->pGame, pUnit, 2, &nItemLevel, 0, -1, 0)) ++nDropped;
        }
        if (!nDropped) return;
        --pQuestDataEx->nRewardState;
        if (pQuestDataEx->nRewardState <= 0)
        {
            pQuestDataEx->bRewardDropsPending = 0;
            if (pQuestData->pGame->bExpansion)
            {
                unsigned int* pCodes = gnHellforgeRunesNormal;
                switch (pQuestData->pGame->nDifficulty)
                {
                case 1: pCodes = gnHellforgeRunesNightmare; break;
                case 2: pCodes = gnHellforgeRunesHell; break;
                }
                pUnit->dwDropItemCode = pCodes[SEED_RollLimitedRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 11)];
                D2GAME_DropItemAtUnit(pQuestData->pGame, pUnit, 2, &nItemLevel, 0, -1, 0);
            }
        }
        else
            EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 20, 0, 0);
    }
}

// 0x005B6930
void __fastcall ACT4Q3_OnSoulstonesDropped(D2GameStrc* pGame, int nSoulStonesDropped)
{
}

// 0x005B5F40
bool __fastcall ACT4Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 341);
        return true;
    }

    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfSeqFilter), 349);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005B5FC0
int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A4Q3_HELLFORGE);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        if (((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_CUSTOM1);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_STARTED);
        }
        return 0;
    }

    if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q3, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x005B6100
void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNPCNo != 246)
    {
        return;
    }

    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (nMessageIndex == 678)
    {
        pQuestDataEx->bCainActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 462);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 679)
    {
        if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm', 0, 2, 1))
        {
            pQuestDataEx->bCainActivated = 1;
            if (pQuestData->fState < 2)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 513);
            }
            pQuestDataEx->bSoulstoneAcquired = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nMessageIndex == 680)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13) && pQuestData->fState != 5)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q3_UnitIterate_StatusCyclerEx, false);
                QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q3.cpp", 530);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 531);
                pQuestData->pfSeqFilter(pQuestData);
            }

            QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, 1);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

// 0x005B62D0
void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (pQuestData->fState && bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 27, 1) && pQuestData->bNotIntro)
    {
        if (pQuestData->fState == 1)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm'))
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
            }
            else if (!((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired && pQuestData->fLastState < 3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
            }
        }
        else
        {
            if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm') && pQuestData->fLastState < 3 && !((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
            }
        }
    }
}

// 0x005B6440
void __fastcall ACT4Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2UnitStrc* pTarget = pArg->pTarget;
    if (!pTarget || (unsigned short)pTarget->dwClassId != 0xF6)
    {
        return;
    }
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuest->pQuestDataEx;
    if (pQuestDataEx->bCainActivated != 1)
    {
        return;
    }
    if (pQuestDataEx->bSoulstoneAcquired)
    {
        QUESTS_UnitIterate(pQuest, 4, 0, ACT4Q3_UnitIterate_StatusCyclerEx, 1);
    }
    else
    {
        QUESTS_UnitIterate(pQuest, 1, 0, ACT4Q3_UnitIterate_StatusCyclerEx, 1);
    }
    pQuest->nStatusFlags = 0;
    pQuestDataEx->bCainActivated = 0;
    pQuest->pCallback[2] = 0;
    SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT4Q3_UnitIterate_UpdateQuestStateFlags);
}

// 0x005B64E0
void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' hfh'))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        return;
    }

    if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssm'))
    {
        pQuestData->fState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 5) == 1)
    {
        ((D2Act4Quest3Strc*)pQuestData->pQuestDataEx)->bSoulstoneAcquired = 1;
        pQuestData->fLastState = 4;
        pQuestData->fState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 3) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
}

// 0x005B65D0
void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest3Strc* pQuestDataEx = (D2Act4Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' hfh';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit(pQuestArg->pGame, pQuestArg->pTarget, 7, &nItemLevel, 0, -1, 0))
    {
        ++pQuestDataEx->nHellforgeHammersInGame;
    }
}

// 0x005B6940
void __fastcall ACT4Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 408)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 27, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 27, 13))
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 23);
        if (!pQuest || !((D2Act4Quest2Strc*)pQuest->pQuestDataEx)->bDiabloKilled)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 1);
        }
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 408, 0);
    }
}

// 0x005B69E0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x005B69F0
bool __fastcall ACT4Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 408)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pFlags, 27, 0) && !QUESTRECORD_GetQuestState(pFlags, 27, 1) && !QUESTRECORD_GetQuestState(pFlags, 27, 13))
        {
            return true;
        }

        if (!QUESTRECORD_GetQuestState(pFlags, 26, 13) && !QUESTRECORD_GetQuestState(pFlags, 26, 0))
        {
            return true;
        }
    }

    return false;
}

// 0x005B6A70
void __fastcall ACT4Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT4Q4_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct4Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 33;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q4_ActiveFilterCallback;
}

struct D2UnitStrc;

