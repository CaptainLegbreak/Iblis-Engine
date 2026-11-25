#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Game.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2LanguageNames.h"
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall ACT2Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00598640

void __fastcall ACT2Q0_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005987B0

void __fastcall ACT2Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005987D0

void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005986B0

extern "C" char gpAct2Q0NpcMessages[]; // 0x00738FC8

bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00598770

bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00598780

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290

void __fastcall ACT1Q4_RemovePlayerGUID(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005940A0

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

enum D2QuestConstants
{
    QUEST_A1Q1_DENOFEVIL = 1,
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUEST_A2Q5_SUMMONER = 12,
    QUEST_A2Q6_DURIEL = 13,
    QUESTSTATEFLAG_A1Q1 = 1,
    QUESTSTATEFLAG_A2Q0 = 8,
    QUESTSTATEFLAG_A2Q1 = 9,
    QUESTSTATEFLAG_A2Q4 = 12,
    QUESTSTATEFLAG_A2Q5 = 13,
    QUESTSTATEFLAG_A2Q6 = 14,
    QUESTSTATEFLAG_A2Q7 = 30,
    QFLAG_PRIMARYGOALDONE = 13,
};

#define QFLAG_REWARDGRANTED 0

void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x00572360

// 0x005983E0
void __fastcall ACT2Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = pQuestArg->nOldLevel;
    const unsigned short nMessage = pQuestArg->nMessageIndex;
    switch (nNpcId)
    {
    case 199:
        if (nMessage == 204 || nMessage == 203)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 200:
        if (nMessage == 231 || nMessage == 230)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 210:
        if (nMessage == 242 || nMessage == 241)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 178:
        if (nMessage == 264 || nMessage == 263)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 177:
        if (nMessage == 286 || nMessage == 285)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 198:
        if (nMessage == 190)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 175:
        if (nMessage == 215)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    case 202:
        if (nMessage == 274)
        {
            PLRINTRO_SetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId);
        }
        break;
    }
}

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0

// 0x005984C0
void __fastcall ACT2Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass = 7;
    switch (nNpcId)
    {
    case 199:
        nSpecialIntroClass = 2;
        break;
    case 200:
        nSpecialIntroClass = 4;
        break;
    case 210:
        nSpecialIntroClass = 0;
        break;
    case 178:
        nSpecialIntroClass = 3;
        break;
    case 177:
        nSpecialIntroClass = 1;
        break;
    case 175:
    case 198:
    case 202:
        break;
    default:
        return;
    }

    if (PLRINTRO_GetQuestIntroFlag(pQuestArg->pPlayer, pQuestArg->pGame, nNpcId))
    {
        return;
    }

    if (nPlayerClass == nSpecialIntroClass)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
    }
}

// 0x005985B0
bool __fastcall ACT2Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

extern "C" char gpAct2IntroNpcMessages[]; // 0x00738D60


// 0x005985C0
bool __fastcall ACT2Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    return false;
}

// 0x005985D0
void __fastcall ACT2Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT2Intro_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Intro_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct2IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 42;
    pQuestData->pfStatusFilter = ACT2Intro_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Intro_ActiveFilterCallback;
}

// 0x00598640
void __fastcall ACT2Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (nNPCNo == 201)
    {
        if (nMessageIndex == 253)
        {
            D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
            QUESTRECORD_SetQuestState(pQuestFlags, 8, 0);
            QUESTS_SetGlobalState(pQuestArg->pGame, 8, 13);
        }
    }
    else if (nNPCNo == 244)
    {
        if (nMessageIndex == 125)
        {
            D2Act2Quest0Strc* pQuestDataEx = (D2Act2Quest0Strc*)pQuestData->pQuestDataEx;
            QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
        }
    }
}

// 0x005986B0
void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (nNpcId == 201)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 8, 0))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 201, 0);
        }
    }
    else if (nNpcId == 244)
    {
        D2Act2Quest0Strc* pQuestDataEx = (D2Act2Quest0Strc*)pQuestData->pQuestDataEx;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 14) != 1)
        {
            return;
        }

        const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->tPlayerGUIDs, nUnitId))
        {
            return;
        }

        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 244, 1);
        ACT1Q4_RemovePlayerGUID(pQuestData->pGame, pQuestArg->pPlayer);
    }
}

// 0x00598770
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x00598780
bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_JERHYN && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q0, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    return false;
}

// 0x005987B0
void __fastcall ACT2Q0_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act2Quest0Strc* pQuestDataEx = (D2Act2Quest0Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
}

// 0x005987D0
void __fastcall ACT2Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 8, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 8, 13);
    }
}

// 0x00598810
void __fastcall ACT2Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT2Q0_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT2Q0_Callback00_NpcActivate;
    pQuestData->pCallback[10] = ACT2Q0_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[13] = ACT2Q0_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct2Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 8;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT2Q0_ActiveFilterCallback;

    D2Act2Quest0Strc* pQuestDataEx = (D2Act2Quest0Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest0Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q0.cpp", 172, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}


#include "gen/data/Source/D2Game/Quests/a2q0.inc"
