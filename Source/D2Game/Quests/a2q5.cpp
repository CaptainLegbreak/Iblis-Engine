#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2MonsterIds.h"
#define QFLAG_PRIMARYGOALDONE 13

struct D2UnitStrc;
struct D2QuestDataStrc;
struct D2Act3Quest5Strc;
struct D2GameStrc;
struct D2PlayerDataStrc;
struct D2QuestArgStrc;
struct D2Act2Quest5Strc;
struct D2Act2Quest6Strc;


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);



typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct3Q5SourceFile[];


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestState, int nFlag);


void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00545530
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, void* pData, QUESTITERATE pfnCallback); // 0x005537D0
int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);




extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern char gpAct2Q5NpcMessages[]; // 0x0073AF68
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2); // 0x00545760
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0
int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310
void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360
bool __fastcall ACT2Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059BB40
void __fastcall ACT2Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059BBC0
void __fastcall ACT2Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059BD70
int __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BE70
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059BF70
bool __fastcall ACT2Q5_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059BFD0
int __fastcall ACT2Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused); // 0x0059C6C0
void __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C920

int __fastcall ACT2Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BCB0

int __fastcall ACT2Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BD10

#define QUESTSTATEFLAG_A2Q5 13

#define QFLAG_REWARDPENDING 1

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

#define QFLAG_REWARDGRANTED 0

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780

#define QFLAG_UPDATEQUESTLOG 13

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x0059BB40
bool __fastcall ACT2Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if ((nNpcId == MONSTER_ATMA || nNpcId == MONSTER_WARRIV2 || nNpcId == MONSTER_ELZIX || nNpcId == MONSTER_DROGNAN
        || nNpcId == MONSTER_LYSANDER || nNpcId == MONSTER_CAIN2 || nNpcId == MONSTER_MESHIF1 || nNpcId == MONSTER_JERHYN
        || nNpcId == MONSTER_GEGLASH || nNpcId == MONSTER_FARA)
        && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING) == 1)
    {
        return true;
    }

    return false;
}

// 0x0059BBC0
void __fastcall ACT2Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pQuestArg->pPlayer);
    D2BitBufferStrc* pQuestFlags = pPlayerData->pQuestData[pGame->nDifficulty];
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
    }
    else if (pQuestData->bNotIntro && pQuestData->fState)
    {
        const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDGRANTED);
        const int nUpdateLog = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_UPDATEQUESTLOG);
        if (nRewardGranted == 1 && !nUpdateLog)
        {
            return;
        }

        if (pQuestData->fState >= 2 && !nUpdateLog)
        {
            return;
        }

        const int nIndex = gnAct2Quest5NpcIndices[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 4)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define QUEST_A2Q5_SUMMONER 12

// 0x0059BCB0
int __fastcall ACT2Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A2Q5_SUMMONER);
    }

    return 0;
}

// 0x0059BD10
int __fastcall ACT2Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 0) == 1)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 12);
    if (pQuestData && pQuestData->fState == 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 13, 2);
    }

    return 0;
}

// 0x0059BD70
void __fastcall ACT2Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    if (nMessageIndex == 427 || nMessageIndex == 424 || nMessageIndex == 419 || nMessageIndex == 423
        || nMessageIndex == 422 || nMessageIndex == 426 || nMessageIndex == 429 || nMessageIndex == 425
        || nMessageIndex == 421 || nMessageIndex == 420 || nMessageIndex == 428)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_PRIMARYGOALDONE))
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT2Q5_UnitIterate_StatusCyclerEx, 1);
                QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q5, QFLAG_PRIMARYGOALDONE);
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 244);
            }

            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDGRANTED);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING);
        }

        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0059BE70
int __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q5_SUMMONER);
    D2_ASSERT(pQuestData, 269);

    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 284);

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pQuestDataEx->pRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING) && bInRange)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_REWARDPENDING);
    }

    return 0;
}

// 0x0059BF70
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x0059BF80
int __fastcall ACT2Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q5, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ARCANESANCTUARY)
    {
        return 0;
    }

    SUNIT_AttachSound(pUnit, 51, pUnit);
    return 0;
}

// 0x0059BFD0
bool __fastcall ACT2Q5_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;

    if (!pQuestDataEx->bCompletionSoundAttached)
    {
        pQuestDataEx->bCompletionSoundAttached = 1;
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q5_UnitIterate_AttachCompletionSound);
        return false;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 4, 0, ACT2Q5_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bStatusTimerStarted = 0;
    return true;
}

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
        QUESTS_StateDebug(pQuestData, 4, gszAct3Q5SourceFile, 630);
    else
        QUESTS_StateDebug(pQuestData, 5, gszAct3Q5SourceFile, 634);

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x0059C020
void __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDoneInAct(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!QUESTS_GetQuestData(pGame, 12))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 13, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 1)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 13, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 13, 1);
}

// 0x0059C0A0
int __fastcall ACT2Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q5_UnitIterate_SetPrimaryGoalDoneInAct, 0);
        }
    }

    return 0;
}

// 0x0059C0F0
int __fastcall ACT2Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 13, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 13, 14);
        QUESTS_SendLogUpdateEx(pUnit, 12, 0);
    }

    return 0;
}

// 0x0059C150
void __fastcall ACT2Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestData->bNotIntro)
    {
        QUESTS_DebugOutput(pQuestData->pGame, "killed summoner for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x1BE);
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x1BF);

        D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->bStatusTimerStarted)
        {
            pQuestDataEx->bStatusTimerStarted = 1;
            QUESTS_CreateTimer(pQuestData, ACT2Q5_Timer_StatusCycler, 3);
        }

        pQuestDataEx->bCompletionSoundAttached = 0;
        pQuestDataEx->bSummonerKilled = 1;
        pQuestDataEx->pRoom = UNITS_GetRoom(pQuestArg->pTarget);

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q5_UnitIterate_SetPrimaryGoalDone);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q5_UnitIterate_SetCompletionFlag);
    }

    QUESTS_TriggerFX(pQuestData->pGame, 7);
}

// 0x0059C200
void __fastcall ACT2Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestData->bNotIntro && pQuestArg->nNewLevel >= 40 && pQuestArg->nOldLevel == 40)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }
}

// 0x0059C220
void __fastcall ACT2Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 13, 2) != 1)
    {
        return;
    }

    pQuestData->fLastState = 2;
    pQuestData->fState = 1;
}

// 0x0059C280
void __fastcall ACT2Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct2Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x212, 0);
    pQuestData->pCallback[0] = ACT2Q5_Callback00_NpcActivate;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 13;
    pQuestData->nInitNo = 2;
    pQuestData->pfActiveFilter = ACT2Q5_ActiveFilterCallback;
    pQuestData->pCallback[3] = ACT2Q5_Callback03_ChangedLevel;
    pQuestData->pCallback[11] = ACT2Q5_Callback11_ScrollMessage;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[13] = ACT2Q5_Callback13_PlayerStartedGame;
    pQuestData->pCallback[8] = ACT2Q5_Callback08_MonsterKilled;

    pQuestDataEx->bSummonerKilled = 0;
    pQuestDataEx->bSummonerActivated = 0;
    pQuestDataEx->bStatusTimerStarted = 0;
    pQuestDataEx->pRoom = 0;
}

// 0x0059C330
void __fastcall ACT2Q5_OnSummonerActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 12);
    if (!pQuestData || pQuestData->bNotIntro != 1)
    {
        return;
    }

    D2Act2Quest5Strc* pQuestDataEx = (D2Act2Quest5Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bSummonerActivated)
    {
        pQuestDataEx->bSummonerActivated = 1;
    }

    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q5.cpp", 0x238);
    }

    if (pQuestData->fLastState < 2)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q5_UnitIterate_StatusCyclerEx, 1);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q5_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x0059C3B0
void __stdcall ACT2Q5_OnSummonerCreated(int nUnused1)
{
}

int __fastcall ACT2Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C650

void __fastcall ACT2Q6_UnitIterate_SetCustom1Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059CF20

