#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"
#include "D2ObjModes.h"
#include "D2LanguageNames.h"

#define QUESTSTATEFLAG_A1Q1 1
#define QUESTSTATEFLAG_A2Q1 9
#define QUESTSTATEFLAG_A2Q4 12
#define QUESTSTATEFLAG_A2Q7 30
#define QFLAG_REWARDGRANTED 0
#define QFLAG_REWARDPENDING 1
#define QFLAG_CUSTOM3 7
#define QFLAG_CUSTOM4 8
#define QFLAG_PRIMARYGOALDONE 13

#define QUESTSTATEFLAG_A1INTRO 42
#define QUEST_A1Q1_DENOFEVIL 1
#define QFLAG_STARTED 2
#define QFLAG_LEAVETOWN 3
#define QFLAG_ENTERAREA 4
#define QFLAG_COMPLETEDNOW 14
#define QFLAG_COMPLETEDBEFORE 15
struct D2PlayerDataStrc;
struct D2Act2Quest4Strc;
struct D2Act1Quest1Strc;

void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc*, D2GameStrc*, int); // 0x00572360

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct1IntroNpcMessages[]; // 0x007361F8
extern char gpAct1Q0NpcMessages[]; // 0x00736460
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
void __fastcall sub_0058F870_ScrollMessage(D2QuestDataStrc* quest, D2QuestArgStrc* arg); // 0x0058F870
void __fastcall ACT1Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058F8F0
bool __fastcall ACT1Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058F9B0
bool __fastcall ACT1Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058F9C0
void __fastcall ACT1Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058FA90
bool __fastcall ACT1Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058FB40
bool __fastcall ACT1Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058FB50
void __fastcall ACT1Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

int __fastcall ACT1Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058FBE0
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300

// 0x0058F870
void __fastcall sub_0058F870_ScrollMessage(D2QuestDataStrc* quest, D2QuestArgStrc* arg)
{
    int npc = arg->nOldLevel;
    unsigned short message = arg->nMessageIndex;
    switch (npc) {
    case 148:
        if (message == 11 || message == 12) PLRINTRO_SetQuestIntroFlag(arg->pPlayer, arg->pGame, npc);
        break;
    case 147:
        if (message == 45 || message == 46) PLRINTRO_SetQuestIntroFlag(arg->pPlayer, arg->pGame, npc);
        break;
    case 154:
        if (message == 36 || message == 37) PLRINTRO_SetQuestIntroFlag(arg->pPlayer, arg->pGame, npc);
        break;
    case 150:
        if (message == 24 || message == 25) PLRINTRO_SetQuestIntroFlag(arg->pPlayer, arg->pGame, npc);
        break;
    }
}

// 0x0058F8F0
void __fastcall ACT1Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialClass;
    switch (nNpcId)
    {
    case 150:
        nSpecialClass = 0;
        break;
    case 147:
        nSpecialClass = 2;
        break;
    case 154:
        nSpecialClass = 4;
        break;
    case 148:
        nSpecialClass = 1;
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x0058F9B0
bool __fastcall ACT1Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

// 0x0058F9C0
bool __fastcall ACT1Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pPlayerQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pPlayerQuestFlags, QUESTSTATEFLAG_A1Q1, QFLAG_REWARDGRANTED) != 1
        && nNpcId == MONSTER_AKARA
        && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, MONSTER_AKARA))
    {
        return true;
    }

    return false;
}

// 0x0058FA20
void __fastcall ACT1Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Intro_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = sub_0058F870_ScrollMessage;
    pQuestData->pNPCMessages = gpAct1IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A1INTRO;
    pQuestData->pfStatusFilter = ACT1Intro_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT1Intro_ActiveFilterCallback;
}

// 0x0058FAD0
void __fastcall ACT1Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != MONSTER_WARRIV1)
    {
        return;
    }

    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q0, QFLAG_REWARDGRANTED))
    {
        return;
    }

    if (pQuestArg->pPlayer && pQuestArg->pPlayer->dwClassId == PCLASS_PALADIN)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_WARRIV1, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_WARRIV1, 0);
    }
}

// 0x0058FB80
void __fastcall ACT1Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q0_Callback00_NpcActivate;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A1Q0;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q0_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct1Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->pfStatusFilter = ACT1Q0_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT1Q0_ActiveFilterCallback;
}

#include "gen/data/Source/D2Game/Unknown_0058F870.inc"

// 0x0058FA90
void __fastcall ACT1Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo == MONSTER_WARRIV1 && (nMessageIndex == 0 || nMessageIndex == 1))
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q0, QFLAG_REWARDGRANTED);
    }
}

// 0x0058FB40
bool __fastcall ACT1Q0_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x0058FB50
bool __fastcall ACT1Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_WARRIV1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q0, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    return false;
}
