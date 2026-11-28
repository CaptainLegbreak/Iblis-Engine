#include "D2Game.h"
#include "D2UnitData.h"
#include "D2GameStrc.h"
#include "D2MonsterIds.h"
#include "D2CommonApi.h"

// 0x00596BB0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

struct D2PlayerDataStrc;

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


enum D2QuestConstants
{
    QUEST_A1Q1_DENOFEVIL = 1,
    QUESTSTATEFLAG_A1Q1 = 1,
    QFLAG_PRIMARYGOALDONE = 13,
};

#include "D2GameFuncs.h"

// 0x00596BC0
bool __fastcall ACT1Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId != MONSTER_NAVI || !QUESTS_GetQuestData(pQuest->pGame, QUEST_A1Q1_DENOFEVIL)->bNotIntro || QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE))
    {
        return false;
    }

    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_PRIMARYGOALDONE)
        && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDPENDING))
    {
        return true;
    }

    return false;
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern unsigned char gaAct1Q7NpcMessages[]; // 0x00738778

void __fastcall ACT1Q7_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00596A90

void __fastcall ACT1Q6_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00596BA0

// 0x00596C40
void __fastcall ACT1Q7_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT1Q7_Callback00_NpcActivate;
    pQuestData->pCallback[8] = ACT1Q6_EmptyCallback;
    pQuestData->pNPCMessages = gaAct1Q7NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->eFilter = 29;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT1Q7_ActiveFilterCallback;
}


