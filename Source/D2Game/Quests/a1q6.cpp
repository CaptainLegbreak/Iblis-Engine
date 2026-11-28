#include "D2GameEvents.h"
#include "D2ObjectIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"
#include "D2ObjModes.h"
#include "D2MonsterIds.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

struct D2PoolSystemStrc;
struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2GameStrc;

struct D2QuestDataStrc;

struct D2UnitStrc;

#define QUEST_A2Q1_RADAMENT 8

#define QUEST_A2Q6_DURIEL 13

#define QUESTSTATEFLAG_A2Q0 8

#define MONSTER_JERHYN 201

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define ITEMQUAL_NORMAL 2

struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2ObjInitFnStrc;

struct D2Act1Quest4Strc;

struct D2Act1Quest5Strc;

struct D2Act1Quest6Strc;

struct D2Act2Quest4Strc;

struct D2Act2Quest6Strc;

struct D2Act2Quest1Strc;

enum D2C_P08QuestConstants
{
    ACT_II = 1,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A1Q5 = 5,
    QUESTSTATEFLAG_A1Q6 = 6,
    QUESTSTATEFLAG_A2Q2 = 10,
    QUESTSTATEFLAG_A2Q3 = 11,
    QUESTSTATEFLAG_A2Q4 = 12,
    QUESTSTATEFLAG_A4Q2 = 26,
    QUESTSTATEFLAG_A5Q6 = 40,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_STARTED = 2,
    QFLAG_LEAVETOWN = 3,
    QFLAG_ENTERAREA = 4,
    QFLAG_CUSTOM1 = 5,
    QFLAG_CUSTOM2 = 6,
    QFLAG_CUSTOM6 = 10,
    QFLAG_PRIMARYGOALDONE = 13,
};


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0

#include "D2GameFuncs.h"
#include "D2ClientApi.h"

void __fastcall D2Game_10034_Return(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60


D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230


void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300


int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310


int __fastcall ACT1Q4_UnitIterate_SetCustom6Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00593E30


int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00595B20

int __fastcall ACT1Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00595BD0


void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


int __fastcall ACT2Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598DC0

int __fastcall ACT2Q1_UnitIterate_DetermineSkillBookDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598FA0

bool __fastcall ACT2Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x00598F70


#define UNIT_MONSTER 1

#define QUEST_A1Q6_ANDARIEL 6

#define QUESTSTATEFLAG_A1Q6 6

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_PRIMARYGOALDONE 13

union D2SeedStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

extern int gpAct1Q6NpcMessages[]; // 0x007382E0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall ACT1Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00595B80

void __fastcall ACT1Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00595C60

void __fastcall ACT1Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00595E20

void __fastcall ACT1Q6_Callback03_ChangedLevel(D2QuestDataStrc* q,D2QuestArgStrc* arg); // 0x00596010

void __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596320

int __fastcall ACT1Q6_UnitIterate_CreatePortalToTown(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596490

void __fastcall ACT1Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005965A0

char __fastcall ACT1Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005967F0

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc*); // 0x00545310


extern "C" unsigned int gdwA1Q6ChippedGemCodes[7]; // 0x007361DC

extern "C" unsigned int gdwA1Q6NormalGemCodes[7]; // 0x00736444


int __fastcall ACT1Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596170

void __fastcall ACT1Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pArgs); // 0x005961C0

int __fastcall ACT1Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005963E0

int __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00596440

bool __fastcall ACT1Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuest); // 0x00596500

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

extern unsigned int gnAct1Q6NpcMessageIndices[]; // 0x007382C4

inline D2BitBufferStrc* QUESTS_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

__forceinline int ACT1Q5_ContainsGUID_Inline(const int* pGUIDs, int nCount, int nUnitId)
{
    for (int i = 0; i < nCount; ++i)
    {
        if (pGUIDs[i] == nUnitId)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00595A50
void __fastcall OBJECTS_InitFunction47_CountessChest(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    const int nUnitId = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    for (int i = 0; i < pQuestDataEx->nCountessChestCount; ++i)
    {
        if (pQuestDataEx->nObjectGUIDs[i] == nUnitId)
        {
            return;
        }
    }

    if (pQuestDataEx->nCountessChestCount < 8)
    {
        pQuestDataEx->nObjectGUIDs[pQuestDataEx->nCountessChestCount] = nUnitId;
        ++pQuestDataEx->nCountessChestCount;
    }

    ACT1Q5_SpawnTowerChestMissiles(pQuestData, pQuestDataEx);
    if (pQuestDataEx->bCountessKilled && !pQuestDataEx->bDeathMissilesCreated)
    {
        EVENT_SetEvent(pQuestData->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + 10, 0, 0);
    }
}

// 0x00595B20
int __fastcall ACT1Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 6, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 6, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 6, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 6);
    }
    return 0;
}

// 0x00595B80
void __fastcall ACT1Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->pTarget && (unsigned short)pQuestArg->pTarget->dwClassId == 265)
    {
        D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bCainActivated == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q6_UnitIterate_StatusCyclerEx, true);
            pQuestDataEx->bCainActivated = 0;
            pQuestData->pCallback[2] = 0;
        }
    }
}

// 0x00595BD0
int __fastcall ACT1Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 6, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 6);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 6, 2);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 6, 3);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 6, 4);
        }
    }
    return 0;
}

// 0x00595C60
void __fastcall ACT1Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;

    if (nNPCNo == MONSTER_CAIN5)
    {
        if (nMessageIndex == 166)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 192);
            pQuestDataEx->bCainActivated = 1;
            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q6_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        else if (nMessageIndex == 184)
        {
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
        }
    }
    else if (nNPCNo == MONSTER_WARRIV1)
    {
        if (nMessageIndex != 183)
        {
            return;
        }

        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING))
        {
            return;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE))
        {
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT1Q6_UnitIterate_StatusCyclerEx, 0);
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 214);
            QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE);
        }

        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED);
        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
    }
    else if (nNPCNo == MONSTER_AKARA)
    {
        if (nMessageIndex == 179)
        {
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
        }
    }
    else if (nNPCNo == MONSTER_KASHYA)
    {
        if (nMessageIndex == 181)
        {
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
        }
    }
}

struct D2ItemDropStrc;

// 0x00595E20
void __fastcall ACT1Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE);
    const int bRewardPending = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;
    const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;

    switch (nNpcId)
    {
    case MONSTER_AKARA:
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID2, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_AKARA, 3);
            return;
        }
        break;
    case MONSTER_KASHYA:
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID3, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_KASHYA, 3);
            return;
        }
        break;
    case MONSTER_CAIN5:
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID1, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN5, 3);
            return;
        }
        break;
    }

    if (bRewardPending)
    {
        if (nNpcId == MONSTER_CAIN5 || nNpcId == MONSTER_AKARA || nNpcId == MONSTER_KASHYA)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        else
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (pQuestData->fState == 1 && nNpcId == MONSTER_CAIN5 && !bRewardGranted)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN5, 0);
    }
    else
    {
        if (!pQuestData->fState || (bRewardGranted == 1 && !bPrimaryGoalDone))
        {
            return;
        }

        if (pQuestData->fState >= 4 && !bPrimaryGoalDone)
        {
            return;
        }

        if (bRewardGranted == 1 && bPrimaryGoalDone == 1)
        {
            return;
        }

        const unsigned int nIndex = gnAct1Q6NpcMessageIndices[pQuestData->fState];
        if (nIndex != -1 && nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* game,D2UnitStrc* player)
{
 return UNITS_GetPlayerData(player)->pQuestData[game->nDifficulty];
}

// 0x00596010
void __fastcall ACT1Q6_Callback03_ChangedLevel(D2QuestDataStrc* q,D2QuestArgStrc* arg)
{
 const int oldLevel=arg->nOldLevel;
 const int newLevel=arg->nNewLevel;
 if((unsigned)(newLevel-34)<=3 && q->bNotIntro) {
  bool changed=false;
  if(q->fState<3) {
   QUESTS_StateDebug(q,3,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",358);
   changed=true;
  }
  if(newLevel==37) {
   if(q->fLastState<2) {
    *(unsigned char*)&q->dwFlags=0;
    QUESTS_UnitIterate(q,2,0,ACT1Q6_UnitIterate_StatusCyclerEx,true);
    changed=true;
   }
  } else if(!q->fLastState) {
   *(unsigned char*)&q->dwFlags=0;
   QUESTS_UnitIterate(q,1,0,ACT1Q6_UnitIterate_StatusCyclerEx,false);
   changed=true;
  }
  if(changed) SUNIT_IterateUnitsOfType(q->pGame,0,0,ACT1Q6_UnitIterate_UpdateQuestStateFlags);
  QUESTS_DebugOutput(arg->pGame,"started quest by jumping to level","d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",384);
  return;
 }
 if(q->fState==4 && newLevel==40) {
  QUESTS_StateDebug(q,5,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",391);
  return;
 }
 if(oldLevel==1) {
  QUESTS_QuickRemovePlayerGUID(q);
  if(q->fState==2) {
   D2BitBufferStrc* flags=PLAYER_GetQuestFlags(arg->pGame,arg->pPlayer);
   if(QUESTRECORD_GetQuestState(flags,q->eFilter,0)!=1 && QUESTRECORD_GetQuestState(flags,q->eFilter,1)!=1) {
    QUESTS_StateDebug(q,3,"d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp",405);
    SUNIT_IterateUnitsOfType(q->pGame,0,0,ACT1Q6_UnitIterate_UpdateQuestStateFlags);
   }
  }
 }
}

// 0x00596170
int __fastcall ACT1Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, 33, pUnit);
    }

    return 0;
}

// 0x005961C0
void __fastcall ACT1Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pArgs)
{
    QUESTS_RemovePlayerGUID(pQuestData, pArgs);
    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;

    const int nUnitId = !pArgs->pPlayer ? -1 : pArgs->pPlayer->dwUnitId;

    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
}

// 0x00596210
static void __stdcall ACT1Q6_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING);
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 451), 1, pGame->nDifficulty);
}

// 0x00596260
int __fastcall ACT1Q6_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_COMPLETEDBEFORE) == 1)
    {
        return 0;
    }

    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_CATACOMBSLEV4)
    {
        return 0;
    }

    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)QUESTS_GetQuestData(pGame, QUEST_A1Q6_ANDARIEL)->pQuestDataEx;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
    ACT1Q6_SetPrimaryGoalDone(pGame, pUnit, pQuestFlags);
    return 0;
}

// 0x00596320
void __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_I)
    {
        return;
    }

    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)QUESTS_GetQuestData(pGame, QUEST_A1Q6_ANDARIEL)->pQuestDataEx;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID1, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID2, nUnitId);
    QUESTS_AddPlayerGUID(&pQuestDataEx->pGUID3, nUnitId);
    ACT1Q6_SetPrimaryGoalDone(pGame, pUnit, pQuestFlags);
}

// 0x005963E0
int __fastcall ACT1Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A1Q6_ANDARIEL, 0);
    }

    return 0;
}

inline unsigned __int64 A1Q6_RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline D2BitBufferStrc* A1Q6_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline int A1Q6_GetQuestStateInline(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nState)
{
    D2BitBufferStrc* pQuestFlags = A1Q6_GetQuestFlagsInline(pGame, pPlayer);
    return QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, nState);
}

// 0x00596440
int __fastcall ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != (unsigned short)-1)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q6_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00596490
int __fastcall ACT1Q6_UnitIterate_CreatePortalToTown(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_CATACOMBSLEV4)
    {
        return 0;
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);
    D2GAME_CreatePortalObject(pGame, pUnit, pRoom, pCoord.nX, pCoord.nY, LEVEL_ROGUEENCAMPMENT, 0, 59, 0);
    return 1;
}

// 0x00596500
bool __fastcall ACT1Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuest)
{
    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuest->pQuestDataEx;
    ++pQuestDataEx->nTimerInvocations;

    if (pQuestDataEx->nTimerInvocations == 10)
    {
        SUNIT_IterateUnitsOfType(pGame, 0, SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nAndarielGUID), ACT1Q6_UnitIterate_CreatePortalToTown);
        return false;
    }

    if (pQuestDataEx->nTimerInvocations != 12)
    {
        return false;
    }

    if (pQuest->fLastState != 3 && pQuest->fLastState != 13)
    {
        pQuest->dwFlags &= 0xFFFFFF00;
        QUESTS_UnitIterate(pQuest, 3, 0, ACT1Q6_UnitIterate_StatusCyclerEx, 1);
    }

    return true;
}

// 0x00596580
bool __fastcall ACT1Q6_Timer_StateDebug(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 605);
    }

    return true;
}

// 0x005965A0
void __fastcall ACT1Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuestData->pQuestDataEx;

    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;

    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer
            && !A1Q6_GetQuestStateInline(pQuestData->pGame, pQuestArg->pPlayer, QFLAG_REWARDGRANTED)
            && !A1Q6_GetQuestStateInline(pQuestData->pGame, pQuestArg->pPlayer, QFLAG_REWARDPENDING))
        {
            D2BitBufferStrc* pQuestFlags = A1Q6_GetQuestFlagsInline(pQuestData->pGame, pQuestArg->pPlayer);
            ACT1Q6_SetPrimaryGoalDone(pQuestData->pGame, pQuestArg->pPlayer, pQuestFlags);

            int nItemLevel;
            for (int i = 0; i < 2; ++i)
            {
                pQuestArg->pTarget->dwDropItemCode = gdwA1Q6ChippedGemCodes[(unsigned int)A1Q6_RollSeedInline(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7];
                D2GAME_DropItemAtUnit(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
            }

            pQuestArg->pTarget->dwDropItemCode = gdwA1Q6NormalGemCodes[(unsigned int)A1Q6_RollSeedInline(QUESTS_GetGlobalSeed(pQuestData->pGame)) % 7];
            D2GAME_DropItemAtUnit(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);

            pQuestArg->pTarget->dwDropItemCode = 0;
        }

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q6_UnitIterate_SetCompletionFlag);
    }

    pQuestDataEx->nAndarielGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
    pQuestDataEx->nTimerInvocations = 1;

    if (pQuestData->bNotIntro)
    {
        QUESTS_CreateTimer(pQuestData, ACT1Q6_Timer_StatusCycler, 1);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q6_UnitIterate_AttachCompletionSound);
    }

    pQuestDataEx->bAndarielKilled = 1;
    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 688);
    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q6_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = 0;
}

// 0x005967F0
char __fastcall ACT1Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;

    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)pQuest->pQuestDataEx;
    if (nNpcId == MONSTER_CAIN5)
    {
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID1, nUnitId))
        {
            return 1;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) != 1 && pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING))
        {
            return 1;
        }
    }
    else if (nNpcId == MONSTER_WARRIV1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDGRANTED) != 1)
        {
            return QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_REWARDPENDING) == 1;
        }
    }
    else if (nNpcId == MONSTER_AKARA)
    {
        return QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID2, nUnitId) != 0;
    }
    if (nNpcId == MONSTER_KASHYA)
    {
        return QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pGUID3, nUnitId) != 0;
    }

    return 0;
}

// 0x005968C0
int __fastcall ACT1Q6_IsAndarielKilled(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->bNotIntro)
        return ((D2Act1Quest6Strc*)pQuestData->pQuestDataEx)->bAndarielKilled;
    return 1;
}

// 0x005968E0
bool __fastcall ACT1Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_CreateTimer(pQuestData, ACT1Q6_Timer_StateDebug, 20);
    }

    return true;
}


// 0x00596900
void __fastcall ACT1Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q6, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00596990
void __fastcall ACT1Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));

    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT1Q6_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = ACT1Q6_Callback08_MonsterKilled;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q6_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q6_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT1Q6_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT1Q6_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q6_SeqCallback;

    pQuestData->eFilter = QUESTSTATEFLAG_A1Q6;
    pQuestData->pNPCMessages = gpAct1Q6NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fLastState = 0;
    pQuestData->fState = 0;

    D2Act1Quest6Strc* pQuestDataEx = (D2Act1Quest6Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest6Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q6.cpp", 837, 0);

    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nSeqId = 37;
    pQuestData->pfActiveFilter = (QUESTACTIVEFILTER)ACT1Q6_ActiveFilterCallback;

    pQuestDataEx->nAndarielGUID = 0;
    pQuestDataEx->unused0x190 = 0;
    pQuestDataEx->nTimerInvocations = 0;
    pQuestDataEx->bAndarielKilled = 0;
    pQuestDataEx->bCainActivated = 0;

    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pGUID1);
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pGUID2);
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pGUID3);
}

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00596A90
void __fastcall ACT1Q7_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg)
{
    if ((!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId) != MONSTER_NAVI)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, 1);
    if (QUESTS_GetGlobalState(pQuestArg->pGame, 1, 13) || !pQuestData->bNotIntro)
    {
        QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, MONSTER_NAVI, ITEMS_RollRandomNumber(&pQuestArg->pPlayer->pSeed) % 3 + 2);
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 1, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, 1, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 1, 1))
    {
        QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, MONSTER_NAVI, ITEMS_RollRandomNumber(&pQuestArg->pPlayer->pSeed) % 3 + 2);
        return;
    }

    QUESTS_InitScrollTextChain(pQuest, pQuestArg->pTextControl, MONSTER_NAVI, SEED_RollLimitedRandomNumber(&pQuestArg->pPlayer->pSeed, 2));
}

// 0x00596BA0
void __fastcall ACT1Q6_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}

