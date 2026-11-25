#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2GameTypes.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0073E810

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall ACT3Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6ED0

void __fastcall ACT3Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6F20

void __fastcall ACT3Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6FD0

extern char gpAct3Q0NpcMessages[]; // 0x0073EAA0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B6F90

bool __fastcall ACT3Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B6FA0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

void __fastcall PLRINTRO_SetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x00572360

// 0x005B6C60
void __fastcall ACT3Intro_Callback11_ScrollMessage(void* pUnused, D2QuestArgStrc* pArgs)
{
    const int nNpcId = pArgs->nOldLevel;
    const unsigned short nIndex = pArgs->nMessageIndex;
    switch (nNpcId)
    {
    case 254:
        if (nIndex == 502 || nIndex == 501)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 264:
        if (nIndex == 479 || nIndex == 478)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 252:
        if (nIndex == 491 || nIndex == 490)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 255:
        if (nIndex == 515 || nIndex == 514)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 297:
        if (nIndex == 453)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    case 245:
        if (nIndex == 458)
            PLRINTRO_SetQuestIntroFlag(pArgs->pPlayer, pArgs->pGame, nNpcId);
        break;
    }
}

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0

// 0x005B6D30
void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nPlayerClass = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;

    int nSpecialIntroClass = 7;
    switch (nNpcId)
    {
    case 254:
        nSpecialIntroClass = 2;
        break;
    case 264:
        nSpecialIntroClass = 4;
        break;
    case 252:
        nSpecialIntroClass = 0;
        break;
    case 255:
        nSpecialIntroClass = 3;
        break;
    case 245:
    case 297:
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

// 0x005B6E20
bool __fastcall ACT3Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    return false;
}

// 0x005B6E30
bool __fastcall ACT3Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 245 && !PLRINTRO_GetQuestIntroFlag(pPlayer, pQuest->pGame, 245))
    {
        return true;
    }
    return false;
}

extern char gpAct3IntroNpcMessages[];                                                                       // 0x0073E850

void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B6C60

// 0x005B6E60
void __fastcall ACT3Intro_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT3Intro_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Intro_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct3IntroNpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 42;
    pQuestData->pfStatusFilter = ACT3Intro_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Intro_ActiveFilterCallback;
}

// 0x005B6ED0
void __fastcall ACT3Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
    if (nMessageIndex == 465 || nMessageIndex == 466)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 16, 0);
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}

// 0x005B6F20
void __fastcall ACT3Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 253)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0))
    {
        return;
    }

    const int nClassId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;
    if (nClassId == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 1);
    }
    else
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 253, 0);
    }
}

// 0x005B6F90
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x005B6FA0
bool __fastcall ACT3Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 253 && !QUESTRECORD_GetQuestState(pQuestFlags, 16, 0))
    {
        return true;
    }
    return false;
}

// 0x005B6FD0
void __fastcall ACT3Q0_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 16, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 16, 13);
    }
}

// 0x005B7010
void __fastcall ACT3Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[11] = ACT3Q0_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT3Q0_Callback00_NpcActivate;
    pQuestData->pCallback[13] = ACT3Q0_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct3Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;

    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest0Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q0.cpp", 148, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest0Strc));

    pQuestData->eFilter = 16;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q0_ActiveFilterCallback;
}


#include "gen/data/Source/D2Game/Quests/a3q0.inc"
