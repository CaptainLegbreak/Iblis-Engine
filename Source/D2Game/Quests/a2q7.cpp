#include "D2MonsterIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2CommonApi.h"
#pragma function(memset)
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2BitBufferStrc;
struct D2TextHeaderStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);
typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);


enum
{
    QUEST_A2Q1_RADAMENT = 8,
    QUESTSTATEFLAG_A2Q1 = 9,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q6_DURIEL = 13,
    QUESTSTATEFLAG_A2Q6 = 14,
    QUESTSTATEFLAG_A2Q7 = 30,
    QUESTSTATEFLAG_A2Q8 = 31,
    QFLAG_PRIMARYGOALDONE = 13,
};

extern char gpAct2Q7NpcMessages[];                                                                          // 0x0073B8C0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                          // 0x0045C390
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
#include "D2GameFuncs.h"
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430
void __fastcall ACT2Q7_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x0059E140
void __fastcall ACT2Q7_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E2A0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E2B0
bool __fastcall ACT2Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059E2C0
bool __fastcall ACT2Q8_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E4A0

void __fastcall ACT2Q7_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT2Q7_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

// 0x0059E0B0
void __fastcall ACT2Q7_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_ACT2GUARD4)
    {
        return;
    }

    D2Act2Quest7Strc* pQuestDataEx = (D2Act2Quest7Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bGuardActivated == 1)
    {
        pQuestDataEx->bGuardActivated = 0;
        pQuestData->pCallback[2] = 0;
    }
}

// 0x0059E0E0
void __fastcall ACT2Q7_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNPCNo != MONSTER_ACT2GUARD4)
    {
        return;
    }

    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (nMessageIndex == 59 || nMessageIndex == 60)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, QFLAG_PRIMARYGOALDONE);
        pQuestData->pCallback[2] = ACT2Q7_Callback02_NpcDeactivate;
    }
    else
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, 0);
    }
}

extern "C" const char gszA2Q7SourceFile[];                                                                  // 0x006E20B4

extern "C" const char gszA2Q8SourceFile[];                                                                  // 0x006E20E8

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0059E140
void __fastcall ACT2Q7_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId) != MONSTER_ACT2GUARD4)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, 0))
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 0))
        {
            goto RollMessage;
        }
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, QFLAG_PRIMARYGOALDONE))
        {
            goto RollMessage;
        }
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 1))
        {
            goto RollMessage;
        }
        if (QUESTS_GetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A2Q1, QFLAG_PRIMARYGOALDONE))
        {
RollMessage:
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollRandomNumber_Inline(&pQuestArg->pPlayer->pSeed) % 3 + 2);
            return;
        }

        D2QuestDataStrc* pQuestData8 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q1_RADAMENT);
        if (pQuestData8 && !pQuestData8->bNotIntro)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollLimitedRandomNumber(&pQuestArg->pPlayer->pSeed, 3) + 2);
            return;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q7, QFLAG_PRIMARYGOALDONE))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollLimitedRandomNumber(&pQuestArg->pPlayer->pSeed, 2));
            return;
        }
    }

    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD4, SEED_RollRandomNumber_Inline(&pQuestArg->pPlayer->pSeed) % 3 + 2);
}

// 0x0059E2A0
void __fastcall ACT2Q7_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}

// 0x0059E2B0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

#define QUESTSTATEFLAG_A1Q1 1

#define QUESTSTATEFLAG_A2Q4 12

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_CUSTOM3 7

#define QFLAG_CUSTOM4 8

#define QUESTSTATEFLAG_A1INTRO 42

#define QUEST_A1Q1_DENOFEVIL 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

struct D2Act2Quest4Strc;

struct D2Act1Quest1Strc;


void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190


void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300

// 0x0059E2C0
bool __fastcall ACT2Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_ACT2GUARD4)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_PRIMARYGOALDONE))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q1, QFLAG_PRIMARYGOALDONE) == 1 && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q7, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}

// 0x0059E330
void __fastcall ACT2Q7_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT2Q7_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT2Q7_Callback00_NpcActivate;
    pQuestData->pCallback[8] = ACT2Q7_Callback08_MonsterKilled;
    pQuestData->pNPCMessages = gpAct2Q7NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    D2Act2Quest7Strc* pQuestDataEx = (D2Act2Quest7Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest7Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q7.cpp", 194, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestDataEx->bGuardActivated = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q7;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Q7_ActiveFilterCallback;
}

