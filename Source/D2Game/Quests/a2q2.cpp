#include "D2LevelIds.h"
#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2CommonApi.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

enum
{
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUESTSTATEFLAG_A2Q2 = 10,
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUEST_A2Q6_DURIEL = 13,
};

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"



bool __fastcall ACT2Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005996C0

void __fastcall ACT2Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005997F0

void __fastcall ACT2Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00599910

void __fastcall ACT2Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x00599A30

void __fastcall ACT2Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059E850

bool __fastcall ACT2Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059E630


void __fastcall ACT2Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT2Q2_Callback05_ItemDropped(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT2Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT2Q2_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

#define QUESTSTATEFLAG_A2Q2 10

#define QUEST_A2Q2_HORADRICSTAFF 9

#define QFLAG_REWARDGRANTED 0

#define QFLAG_LEAVETOWN 3

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190


static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

struct D2QuestGUIDStrc;

enum D2C_P08QuestConstants
{
    QFLAG_REWARDPENDING = 1,
    QFLAG_ENTERAREA = 4,
    QFLAG_CUSTOM1 = 5,
    QFLAG_CUSTOM2 = 6,
    QFLAG_CUSTOM6 = 10,
};


#define QFLAG_REWARDPENDING 1

#define QFLAG_ENTERAREA 4


// 0x00599510
static int __stdcall ACT2Q2_ShouldUpdateQuestStatus(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_COMPLETEDNOW))
    {
        return 1;
    }

    return 0;
}

// 0x00599570
static int ACT2Q2_CycleStatusIfDone(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (ACT2Q2_ShouldUpdateQuestStatus(pGame, pPlayer))
    {
        QUESTS_StatusCyclerEx(pGame, pPlayer, QUEST_A2Q2_HORADRICSTAFF);
    }

    return 0;
}

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


// 0x00599590
static bool __stdcall ACT2Q2_CheckItemsAndState(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit, unsigned char* pData)
{
    *pData = 0xFF;

    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' tsh'))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM6))
        {
            *pData = 4;
            return true;
        }
        else
        {
            *pData = 5;
            return false;
        }
    }
    else
    {
        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' xob'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM2))
            {
                *pData = 3;
                return true;
            }
            *pData = 9;
        }

        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' 1rt'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN))
            {
                *pData = 0;
                return true;
            }
            *pData = 6;
        }

        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' piv'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_ENTERAREA))
            {
                *pData = 1;
                return true;
            }
            *pData = 7;
        }

        if (ITEMS_FindQuestItem(pQuestData->pGame, pUnit, ' fsm'))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM1))
            {
                *pData = 2;
                return true;
            }
            *pData = 8;
        }

        return false;
    }
}

// 0x005996C0
bool __fastcall ACT2Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_CAIN2)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }

        unsigned char nData;
        if (ACT2Q2_CheckItemsAndState(pQuest, pPlayer, &nData))
        {
            return true;
        }
    }

    return false;
}


// 0x00599700
int __fastcall ACT2Q2_UnitIterate_DetermineHoradricScrollDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 0) == 1)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 3))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q2_HORADRICSTAFF);
    if (pQuestData)
    {
        ++((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }

    return 0;
}

// 0x00599750
int __fastcall ACT2Q2_UnitIterate_DetermineStaffDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 0))
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pGame, pUnit, ' fsm') || ITEMS_FindQuestItem(pGame, pUnit, ' tsh'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q2_HORADRICSTAFF);
    if (pQuestData)
    {
        ++((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }

    return 0;
}

// 0x005997C0
int __fastcall ACT2Q2_UnitIterate_DetermineCubeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' xob'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q2_HORADRICSTAFF);
    if (pQuestData)
    {
        ++((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }

    return 0;
}

// 0x005997F0
void __fastcall ACT2Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo == MONSTER_CAIN2)
    {
        switch (nMessageIndex)
        {
        case 335:
            QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20317274);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 336:
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_ENTERAREA);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 337:
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM1);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 338:
            pQuestData->dwFlags &= 0xFFFFFF00;
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM2);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);
            break;

        case 339:
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDPENDING);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);

            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));

            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM6);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_ENTERAREA);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM2);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM1);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            break;

        default:
            return;
        }
    }
}

// 0x00599910
void __fastcall ACT2Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_PRIMARYGOALDONE);
    const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED);

    const int nTargetClassId = pQuestArg->pTarget ? pQuestArg->pTarget->dwClassId : -1;
    if (nTargetClassId != MONSTER_CAIN2)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, 4);
        return;
    }

    unsigned char nData;
    if (ACT2Q2_CheckItemsAndState(pQuestData, pQuestArg->pPlayer, &nData) && nData != 0xFF)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, nData);
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, 5);
        return;
    }

    if (nRewardGranted == 1)
    {
        if (!nPrimaryGoalDone || nPrimaryGoalDone == 1)
        {
            return;
        }
    }

    if (nData > 9)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN))
        {
            return;
        }

        nData = 6;
    }

    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_CAIN2, nData);
}

// 0x00599A00
void __fastcall ACT2Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel == LEVEL_LUTGHOLEIN)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }
}


// 0x00599A10
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x00599A20
void __fastcall ACT2Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
}
// 0x0059EB00
void __fastcall ACT2Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct2Q2NpcMessages;
    pQuestData->bActive = 1;

    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q2.cpp", 1005, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q2;
    pQuestData->pfStatusFilter = ACT2Q2_StatusFilterCallback;
    pQuestData->nInitNo = 0;
    pQuestData->pfActiveFilter = ACT2Q2_ActiveFilterCallback;
    pQuestData->pCallback[3] = ACT2Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT2Q2_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[10] = ACT2Q2_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[4] = ACT2Q2_Callback04_ItemPickedUp;
    pQuestData->pCallback[5] = ACT2Q2_Callback05_ItemDropped;
    pQuestData->pCallback[8] = ACT2Q2_Callback08_MonsterKilled;
    pQuestData->pCallback[13] = ACT2Q2_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT2Q2_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT2Q2_Callback09_PlayerDroppedWithQuestItem;
    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest2Strc));
    pQuestData->fLastState = 13;
}

// 0x00599A30
void __fastcall ACT2Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nItemId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bLeftTown = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_LEAVETOWN);

    pQuestData->nStatusFlags = 0;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pPlayer);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (pQuestData->nActNo == DRLG_GetActNoFromLevelId(nLevelId))
    {
        ACT2Q2_ShouldUpdateQuestStatus(pQuestArg->pGame, pQuestArg->pPlayer);
    }

    if (pItemsTxtRecord->dwCode == ' 1rt' && !bLeftTown)
    {
        pQuestData->fLastState = 1;
        ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        return;
    }

    if (pItemsTxtRecord->dwCode == ' piv')
    {
        if (bLeftTown)
        {
            pQuestData->fLastState = 2;
            ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 6;
            ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        return;
    }

    if (pItemsTxtRecord->dwCode == ' xob')
    {
        if (!bLeftTown)
        {
            pQuestData->fLastState = 6;
            ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 2;
            ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        return;
    }

    if (pItemsTxtRecord->dwCode == ' fsm')
    {
        if (!bLeftTown)
        {
            pQuestData->fLastState = 6;
            ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
        else
        {
            pQuestData->fLastState = 2;
            ACT2Q2_CycleStatusIfDone(pQuestData->pGame, pQuestArg->pPlayer);
        }
    }
}


// 0x00599B30
void __fastcall ACT2Q2_Callback05_ItemDropped(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nItemId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);

    if (pItemsTxtRecord->dwCode == ' piv' && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 4))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 4);
    }

    if (pItemsTxtRecord->dwCode == ' xob' && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 6))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 6);
    }

    if (pItemsTxtRecord->dwCode == ' fsm' && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 5))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, 5);
    }
}

// 0x00599BD0
void __fastcall ACT2Q2_AddAmulets(D2QuestDataStrc* pQuestData, int nCount)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 9);
    if (pQuest)
    {
        ((D2Act2Quest2Strc*)pQuest->pQuestDataEx)->nAmulets += nCount;
    }
}

// 0x00599BF0
int __fastcall ACT2Q2_HasNoHoradricStaff(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return !ITEMS_FindQuestItem(pGame, pUnit, ' tsh');
}


enum D2C_a2q2_0059E5C0Constants
{
    QFLAG_CUSTOM7 = 11,
};

// 0x0059E5C0
void __fastcall ACT2Q2_UpdateHoradricItemCounts(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q2_HORADRICSTAFF);
    if (pQuestData)
    {
        D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;

        pQuestDataEx->bStaffCubed = 1;
        pQuestDataEx->nPlayerGUID = !pUnit ? -1 : pUnit->dwUnitId;

        --pQuestDataEx->nBaseStaffs;
        --pQuestDataEx->nAmulets;
        ++pQuestDataEx->nCubedStaffs;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_CUSTOM7);

    ACT2Q4_OpenPalaceOrCycle(pGame);
}

extern "C" const char gszA2Q2SourceFile[];                                                                  // 0x006E211C

// 0x0059E630
bool __fastcall ACT2Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 7, 0))
    {
        *pStatus = 0;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 10, 0) || QUESTRECORD_GetQuestState(pFlags, 10, 1))
    {
        if (!QUESTRECORD_GetQuestState(pFlags, 14, 0))
        {
            *pStatus = QUESTRECORD_GetQuestState(pFlags, 10, 10) ? 5 : 6;
            return true;
        }

        *pStatus = QUESTRECORD_GetQuestState(pFlags, 10, 13) ? 13 : 11;
        return true;
    }

    *pStatus = 0;

    D2UnitStrc* pHoradricScroll = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1rt');
    D2UnitStrc* pBaseStaff = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' fsm');
    D2UnitStrc* pBox = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' xob');
    D2UnitStrc* pAmulet = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' piv');
    D2UnitStrc* pCubedStaff = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' tsh');
    const int bLeaveTown = QUESTRECORD_GetQuestState(pFlags, 10, 3);

    if (pBaseStaff && pBox && pAmulet)
    {
        if (QUESTRECORD_GetQuestState(pFlags, 10, 6))
        {
            *pStatus = 3;
        }
        else
        {
            *pStatus = bLeaveTown ? 2 : 4;
        }

        return true;
    }

    if (pCubedStaff)
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 10, 10) ? 5 : 6;
        return true;
    }

    if (pHoradricScroll && !QUESTRECORD_GetQuestState(pFlags, 10, 3))
    {
        *pStatus = 1;
        return true;
    }

    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuest->pQuestDataEx;
    if (pQuestDataEx->bCubeDropped && !pQuestDataEx->nHoradricCubes || !pQuestDataEx->nAmulets && ACT2Q3_IsAltarDestroyed(pQuest) || pQuestDataEx->bHoradricScrollDropped && !pQuestDataEx->nBaseStaffs)
    {
        *pStatus = 9;
    }

    if (bLeaveTown)
    {
        *pStatus = 2;
        return true;
    }

    if (pAmulet || pBaseStaff || pBox)
    {
        *pStatus = 4;
    }

    return true;
}

// 0x0059E850
void __fastcall ACT2Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* q,D2QuestArgStrc* arg)
{
    D2BitBufferStrc* flags=PLAYER_GetQuestFlags(arg->pGame,arg->pPlayer);
    D2UnitStrc* base=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' fsm');
    D2UnitStrc* box=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' xob');
    D2UnitStrc* amulet=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' piv');
    D2UnitStrc* staff=ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' tsh');
    D2Act2Quest2Strc* ex=(D2Act2Quest2Strc*)q->pQuestDataEx;
    if(base) ++ex->nBaseStaffs;
    if(amulet) ++ex->nAmulets;
    if(box) ++ex->nHoradricCubes;
    if(staff) ++ex->nCubedStaffs;
    if(!QUESTRECORD_GetQuestState(flags,10,0))
    {
        D2QuestDataStrc* duriel=QUESTS_GetQuestData(arg->pGame,13);
        if(duriel && duriel->bNotIntro && !((D2Act2Quest6Strc*)duriel->pQuestDataEx)->bDurielLairTombOpen && !ITEMS_FindQuestItem(arg->pGame,arg->pPlayer,' tsh') && (!base || !box || !amulet))
        {
            if(!base) QUESTRECORD_ClearQuestState(flags,10,5);
            if(!box) QUESTRECORD_ClearQuestState(flags,10,6);
            if(!amulet) QUESTRECORD_ClearQuestState(flags,10,4);
        }
    }
}

// 0x0059E970
void __fastcall ACT2Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' fsm'))
    {
        ++pQuestDataEx->nBaseStaffs;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' piv'))
    {
        ++pQuestDataEx->nAmulets;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' xob'))
    {
        ++pQuestDataEx->nHoradricCubes;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' tsh'))
    {
        ++pQuestDataEx->nCubedStaffs;
    }

    if (!pQuestDataEx->bStaffMissingDetected || pQuestDataEx->nCubedStaffs <= 0 && (!pQuestDataEx->nHoradricCubes || !pQuestDataEx->nAmulets || !pQuestDataEx->nBaseStaffs))
    {
        return;
    }

    D2QuestDataStrc* pQuestData13 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData13 || !pQuestData13->bNotIntro)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx13 = (D2Act2Quest6Strc*)pQuestData13->pQuestDataEx;
    if (pQuestDataEx13->bStaffItemsRemoved != 1)
    {
        pQuestDataEx13->bHoradricStaffIsMissing = 0;
    }
}

// 0x0059EA20
void __fastcall ACT2Q2_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
    switch ((unsigned int)ITEMS_GetBaseCode(pQuestArg->pTarget))
    {
    case ' xob':
        --pQuestDataEx->nHoradricCubes;
        break;
    case ' tsh':
        --pQuestDataEx->nCubedStaffs;
        break;
    case ' fsm':
        --pQuestDataEx->nBaseStaffs;
        break;
    case ' piv':
        --pQuestDataEx->nAmulets;
        break;
    default:
        break;
    }

    if (pQuestDataEx->bStaffMissingDetected || pQuestDataEx->nCubedStaffs)
    {
        return;
    }

    if (!pQuestDataEx->bCubeDropped || pQuestDataEx->nHoradricCubes)
    {
        D2QuestDataStrc* pQuestData10;
        if (pQuestDataEx->nAmulets
            || (pQuestData10 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q3_TAINTEDSUN)) == 0
            || !((D2Act2Quest3Strc*)pQuestData10->pQuestDataEx)->bAltarDestroyed)
        {
            if (!pQuestDataEx->bHoradricScrollDropped || pQuestDataEx->nBaseStaffs)
            {
                return;
            }
        }
    }

    D2QuestDataStrc* pQuestData13 = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData13 && pQuestData13->bNotIntro)
    {
        D2Act2Quest6Strc* pQuestDataEx13 = (D2Act2Quest6Strc*)pQuestData13->pQuestDataEx;
        if (pQuestDataEx13->bStaffItemsRemoved != 1)
        {
            if (pQuestData13->pGame->nGameType == 3)
            {
                pQuestDataEx13->bHoradricStaffIsMissing = 1;
                pQuestDataEx13->nQuestStatus = 8;
                pQuestDataEx->bStaffMissingDetected = 1;
                return;
            }
            pQuestDataEx13->bHoradricStaffIsMissing = 1;
            pQuestDataEx13->nQuestStatus = 9;
        }
    }
    pQuestDataEx->bStaffMissingDetected = 1;
}

