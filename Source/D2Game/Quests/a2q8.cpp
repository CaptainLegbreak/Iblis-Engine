#include "D2MonsterIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __fastcall ACT2Q8_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E3C0

void __fastcall ACT2Q8_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E3F0

extern char gpAct2Q8NpcMessages[];                                                                          // 0x0073BD58

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

enum
{
    QUESTSTATEFLAG_A2Q8 = 31,
};

bool __fastcall ACT2Q8_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E4A0

bool __fastcall ACT2Q8_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059E4B0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit);                                         // 0x006221A0

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);           // 0x0065C360

enum
{
    QUEST_A2Q1_RADAMENT = 8,
    QUESTSTATEFLAG_A2Q1 = 9,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q6_DURIEL = 13,
    QUESTSTATEFLAG_A2Q6 = 14,
    QUESTSTATEFLAG_A2Q7 = 30,
    QFLAG_PRIMARYGOALDONE = 13,
};

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState);            // 0x0065C310

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

enum
{
    QUESTSTATEFLAG_A2Q3 = 11,
};

#define QFLAG_REWARDPENDING 1

#define QFLAG_REWARDGRANTED 0

int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760

// 0x0059E3C0
void __fastcall ACT2Q8_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNPCNo == MONSTER_ACT2GUARD5 && pQuestArg->nMessageIndex == 303)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q8, 0);
    }
}

// 0x0059E3F0
void __fastcall ACT2Q8_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNpcId != MONSTER_ACT2GUARD5)
    {
        return;
    }

    D2QuestDataStrc* pQuestData13 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData13 || !pQuestData13->bNotIntro || pQuestData13->fState >= 2)
    {
        return;
    }

    D2QuestDataStrc* pQuestData10 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q3_TAINTEDSUN);
    if (pQuestData10 && pQuestData10->bNotIntro && pQuestData10->fState < 4)
    {
        return;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, 1) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, 0))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD5, 0);
    }
}

// 0x0059E4A0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x0059E4B0
bool __fastcall ACT2Q8_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_ACT2GUARD5)
    {
        D2GameStrc* pGame = pQuest->pGame;
        D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A2Q6_DURIEL);
        if (pQuestData && pQuestData->bNotIntro && pQuestData->fState < 2
            && QUESTS_GetGlobalState(pQuest->pGame, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE)
            && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}

// 0x0059E530
void __fastcall ACT2Q8_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT2Q8_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT2Q8_Callback00_NpcActivate;
    pQuestData->pNPCMessages = gpAct2Q8NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    D2Act2Quest8Strc* pQuestDataEx = (D2Act2Quest8Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest8Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q8.cpp", 150, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestDataEx->unk0x00 = 0;
    pQuestDataEx->unk0x01 = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q8;
    pQuestData->pfStatusFilter = ACT2Q8_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Q8_ActiveFilterCallback;
}


