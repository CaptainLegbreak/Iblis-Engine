#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2Packets.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CommonApi.h"


#include "D2GameFuncs.h"
#include "D2CommonApi2.h"

struct D2PoolSystemStrc;
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230

#define QUESTSTATEFLAG_A5Q6 40

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_PRIMARYGOALDONE 13

#define QUEST_A5Q6_BAAL 36

#define UNIT_PLAYER 0

struct D2PlayerDataStrc;

struct D2Act5Quest6Strc;


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


struct D2GameStrc;

struct D2UnitStrc;

struct D2BitBufferStrc;

struct D2ActiveRoomStrc;

struct D2ClientStrc;

struct D2QuestDataStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

extern "C" const char gszA5Q6SourceFile[];                                                                  // 0x006E1AF0

extern char gpAct5Q6NpcMessages[];                                                                          // 0x00735800

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID);                                   // 0x00545300


void __fastcall ACT5Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058D870

void __fastcall ACT5Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x0058D940

void __fastcall ACT5Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0058D9F0


extern unsigned int gnA5Q6NpcActivateIndices[4]; // 0x00735EE4

void __fastcall ACT5Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058DCF0

void __fastcall ACT5Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058DF20

void __fastcall ACT5Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);     // 0x0058E190


void __fastcall ACT5Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT5Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT5Q6_SeqCallback(D2QuestDataStrc* pQuestData);

struct D2DynamicPathStrc;


void __fastcall D2Game_10034_Return(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax);                                       // 0x004BC500



int __fastcall ACT5Q6_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DEA0

int __fastcall ACT5Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DD90

int __fastcall ACT5Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DDE0

int __fastcall ACT5Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DE30

#define FX_ID 19

#define GOLD_STEP 6000

#define GOLD_MIN 1500

#define GOLD_MAX 3000

#define DEATH_MISSILE 625

#define QUEST_A5Q5_ANCIENTS 35

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM1 5

#define QFLAG_CUSTOM2 6

#define QFLAG_CUSTOM3 7

#define QFLAG_CUSTOM4 8

#define QFLAG_CUSTOM6 10


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380


enum D2C_F33QuestConstants
{
    ACT_V = 4,
    QUEST_A1Q2_BLOODRAVEN = 2,
    QUEST_A1Q3_MALUS = 3,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUESTSTATEFLAG_A1Q2 = 2,
    QUESTSTATEFLAG_A1Q3 = 3,
    QUESTSTATEFLAG_A1Q4 = 4,
    OBJMODE_NEUTRAL = 0,
    OBJMODE_OPERATING = 1,
    OBJMODE_OPENED = 2,
    OBJMODE_SPECIAL1 = 3,
    MONMODE_NEUTRAL = 1,
    EVENTTYPE_ENDANIM = 1,
    EVENTTYPE_QUESTFN = 7,
    STAT_LEVEL = 12,
    ITEMQUAL_NORMAL = 2,
    MONSTATSFLAGINDEX_ZOO = 22,
};


void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190


// 0x0058DC60
void __fastcall ACT5Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 40, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 40, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 40, 0);
    QUESTRECORD_SetQuestState(pQuestFlags, 40, 13);
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 384), 5, pGame->nDifficulty);
}


static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

// 0x0058DCF0
void __fastcall ACT5Q6_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, UNITS_GetUnitId(pQuestArg->pPlayer));
}

// 0x0058DD30
static void __stdcall ACT5Q6_CompleteQuestForPlayer(D2UnitStrc* pPlayer, D2GameStrc* pGame, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED);
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 418), 5, pGame->nDifficulty);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q6_BAAL);
    if (pQuestData)
    {
        ++((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->nCompletions;
    }
}

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

// 0x0058DD90
int __fastcall ACT5Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 40, 13))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q6_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}


// 0x0058DDE0
int __fastcall ACT5Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 40, 0) == 1)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 40, 14);
    QUESTS_SendLogUpdateEx(pUnit, 36, 0);
    return 0;
}

// 0x0058E500
void __fastcall ACT5Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT5Q6_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q6_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT5Q6_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT5Q6_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q6_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT5Q6_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q6_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT5Q6_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q6NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest6Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 809, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 40;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q6_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q6_SeqCallback;
    pQuestData->nSeqId = 37;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest6Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
    pQuestDataEx->nBaalPortalObjectMode = 1;
    pQuestDataEx->nLastPortalObjectMode = 1;
}

// 0x0058E600
void __fastcall ACT5Q6_OpenWorldStoneChamber(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x24);
    if (!pQuestData)
    {
        return;
    }

    ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen = 1;

    if (pQuestData->bNotIntro && pQuestData->fLastState < 3)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058E640
int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x24);
    if (pQuestData && ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen == 1)
    {
        return 0;
    }

    return 1;
}

// 0x0058DEA0
int __fastcall ACT5Q6_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pPlayerFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pPlayerFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED) == 1)
    {
        return 0;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_THEWORLDSTONECHAMBER && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDPENDING))
    {
        ACT5Q6_CompleteQuestForPlayer(pUnit, pGame, pQuestFlags);
    }
    return 0;
}

// 0x0058E120
static void ACT5Q6_SendZooMonsterId(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 579);
    D2GSPacketSrv50 packet50;
    packet50.nHeader = 0x50;
    packet50.nQuestId = QUEST_A5Q6_BAAL;
    packet50.nParams[0] = ((D2Act5Quest6Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q6_BAAL)->pQuestDataEx)->nZooMonsterId;
    D2GAME_SendPacket0x50(pClient, &packet50);
}

// 0x0058E670
void __fastcall OBJECTS_InitFunction75_BaalsPortal(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)QUESTS_GetQuestData(pOp->pGame, 36)->pQuestDataEx;

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nBaalPortalObjectMode);
    pQuestDataEx->nBaalPortalObjectMode = 2;
}

inline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0058DF20
void __fastcall ACT5Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest6Strc* pEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    QUESTS_TriggerFX(pQuestData->pGame,FX_ID);
    if (pQuestData->bNotIntro) {
        bool bDropGold = false;
        pEx->pRoom = UNITS_GetRoom(pQuestArg->pTarget);
        if (!pEx->pRoom) return;
        QUESTS_UnitIterate(pQuestData,4,0,ACT5Q6_UnitIterate_StatusCyclerEx,true);
        if (pQuestArg->pPlayer) {
            if (pQuestData->bNotIntro) {
                D2GameStrc* pGame = pQuestArg->pGame;
                D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
                if (!QUESTRECORD_GetQuestState(pFlags,40,0)) bDropGold = true;
            }
            pEx->nCompletions = 0;
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,ACT5Q6_UnitIterate_SetRewardGranted);
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,ACT5Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,ACT5Q6_UnitIterate_SetCompletionFlag);
            SUNIT_IterateUnitsOfType(pQuestArg->pGame,0,pQuestArg->pTarget,ACT5Q6_UnitIterate_AttachCompletionSound);
            if (bDropGold) {
                int nGoldMin = GOLD_MIN + GOLD_STEP * pQuestData->pGame->nDifficulty;
                unsigned int nGoldMax = GOLD_MAX + GOLD_STEP * pQuestData->pGame->nDifficulty;
                if (nGoldMax >= 65535) nGoldMax = 65535;
                for (int i=0; i<pEx->nCompletions; ++i) {
                    D2Game_10034_Return(pQuestData,pQuestArg,95);
                    int nGold = OBJECTS_RollRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame),nGoldMin,nGoldMax);
                    ITEMS_DropGoldPile(pQuestData->pGame,pQuestArg->pTarget,nGold);
                }
            }
            GAME_SaveAndSendClientSaves(pQuestData->pGame);
        }
        if (pQuestData->fState != 5) pQuestData->fState = 5;
    }
    D2UnitStrc* pMissile = D2GAME_CreateMissile(pQuestArg->pGame,pQuestArg->pTarget,0,1,DEATH_MISSILE,CLIENTS_GetUnitX(pQuestArg->pTarget),CLIENTS_GetUnitY(pQuestArg->pTarget));
    if (pMissile) {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        DUNGEON_ToggleHasPortalFlag(pRoom,0);
    }
}

// 0x0058DE30
int __fastcall ACT5Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 472);
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nQuestId = QUEST_A5Q6_BAAL;
    packet5D.nFlags = 2;
    SCMD_SendPacket0x5D(pClient, &packet5D);

    SUNIT_AttachSound(pUnit, 83, pUnit);
    return 0;
}

// 0x0058E6A0
int __fastcall OBJECTS_OperateFunction70_BaalPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 36);
    if (!pQuestData)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hPlayer);
    if (!pRoom)
    {
        return 0;
    }

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_THRONEOFDESTRUCTION)
    {
        if (((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bWorldStoneChamberOpen == 1)
        {
            LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, 132, 11);
        }
    }
    else
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, 131, 0);
    }

    return 0;
}

// 0x0058E710
void __fastcall OBJECTS_InitFunction77_LastPortal(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)QUESTS_GetQuestData(pOp->pGame, 36)->pQuestDataEx;

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nLastPortalObjectMode);
    pQuestDataEx->nLastPortalObjectMode = 2;
}

// 0x0058E740
int __fastcall OBJECTS_OperateFunction72_LastPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q6_BAAL);
    if (((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->nLastPortalObjectMode != OBJMODE_OPENED)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = pOp->hPlayer;
    D2GameStrc* pGame = pOp->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, LEVEL_HARROGATH, 0);
        D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 923);
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOp->hPlayer);
        GAME_SaveAndSendClientSaves(pQuestData->pGame);
        if (pClient && !PLAYER_IsBusy(pOp->hPlayer))
        {
            SUNIT_ResetInteractInfo(pOp->hPlayer);
            pPlayerData->bBusy = 1;
            D2GAME_PACKETS_SendPacket0x61(pClient, 7);
            QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_CUSTOM6);
        }
    }
    else
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    }

    return 0;
}

struct D2MonStatsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}


// 0x0058E830
void __fastcall OBJECTS_InitFunction79_Zoo(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q6_BAAL);
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bZooInitialized)
    {
        return;
    }

    int i = 0;
    const int nRecordCount = sgptDataTables->nMonStatsTxtRecordCount;
    while (!pQuestDataEx->bZooInitialized)
    {
        if (i >= 10)
        {
            break;
        }

        pQuestDataEx->nZooMonsterId = OBJECTS_RollRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 1, nRecordCount);
        ++i;
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecordInline(pQuestDataEx->nZooMonsterId);
        int bZoo = 0;
        if (pMonStatsTxtRecord)
        {
            bZoo = pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_ZOO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_ZOO & 7];
        }

        if (bZoo)
        {
            pQuestDataEx->bZooInitialized = 1;
        }
    }

    if (!pQuestDataEx->bZooInitialized)
    {
        pQuestDataEx->bZooInitialized = 1;
        pQuestDataEx->nZooMonsterId = 0;
    }

    if (pQuestDataEx->bZooInitialized)
    {
        SUNIT_IterateUnitsOfType(pOp->pGame, UNIT_PLAYER, 0, ACT5Q6_UnitIterate_SendZooMonsterIdToClient);
    }
}

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

// 0x0058E920
void __fastcall ACT5Q6_SpawnTyrael(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    D2CoordStrc coord;
    D2ActiveRoomStrc* pFreeRoom = 0;
    UNITS_GetCoords(pUnit, &coord);
    coord.nX -= 5;
    coord.nY -= 5;
    QUESTS_GetFreePosition(pRoom, &coord, 5, 0x400, &pFreeRoom, 19, 100);
    if (pFreeRoom)
    {
        D2GAME_SpawnMonster(pGame, pFreeRoom, coord.nX, coord.nY, MONSTER_TYRAEL3, MONMODE_NEUTRAL, 4, 66);
    }
}

// 0x0058E180
int __fastcall ACT5Q6_UnitIterate_SendZooMonsterIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    ACT5Q6_SendZooMonsterId(pGame, pUnit);
    return 0;
}

// 0x0058E190
void __fastcall ACT5Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    const int nNewLevel = pQuestArg->nNewLevel;
    if (nNewLevel == LEVEL_HARROGATH)
    {
        ACT5Q6_SendZooMonsterId(pQuestArg->pGame, pQuestArg->pPlayer);
    }

    if (nOldLevel == LEVEL_HARROGATH)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState == 2)
        {
            D2UnitStrc* pPlayer = pQuestArg->pPlayer;
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) == 1)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 626);
            if (pQuestData->fLastState != 1)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
            }

            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q6_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel >= LEVEL_THRONEOFDESTRUCTION)
    {
        if (pQuestData->bNotIntro && pQuestData->fLastState < 2)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q6_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x0058E2B0
bool __fastcall ACT5Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId >= MONSTER_ANCIENTSTATUE1 && nNpcId <= MONSTER_ANCIENTSTATUE3)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A5Q5_ANCIENTS);
        if (pQuestData)
        {
            D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
            if (pQuestDataEx->bAncientsActivated && !pQuestDataEx->nAncientsAlive && pQuest->fState == 1 && !((D2Act5Quest6Strc*)pQuest->pQuestDataEx)->bQuestStarted)
            {
                return true;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    switch (nNpcId)
    {
    case MONSTER_LARZUK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_ENTERAREA))
        {
            return true;
        }
        break;

    case MONSTER_CAIN6:
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM6))
        {
            break;
        }
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM1))
        {
            return true;
        }
        break;

    case MONSTER_MALAH:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM2))
        {
            return true;
        }
        break;

    case MONSTER_TYRAEL3:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM3))
        {
            return true;
        }
        break;

    case MONSTER_QUAL_KEHK:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM4))
        {
            return true;
        }
        break;

    case MONSTER_DREHYA:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM5))
        {
            return true;
        }
        break;

    default:
        break;
    }

    return false;
}

// 0x0058E390
bool __fastcall ACT5Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 36);

    if (pQuest->bNotIntro && !pQuest->fState)
    {
        ((D2Act5Quest6Strc*)pQuest->pQuestDataEx)->bQuestStarted = 1;
        pQuest->fState = 2;
        pQuest->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuest, 1, 0, ACT5Q6_UnitIterate_StatusCyclerEx, 1);
        SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT5Q6_UnitIterate_UpdateQuestStateFlags);
    }

    return true;
}

// 0x0058E3F0
void __fastcall ACT5Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 10);
    }
}

// 0x0058E430
void __fastcall ACT5Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 10);
        CLIENTS_UpdateCharacterProgression(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q6.cpp", 766), 5, pQuestData->pGame->nDifficulty);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) != 1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3) == 1)
        {
            pQuestData->fLastState = 1;
            pQuestData->fState = 3;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2) == 1)
        {
            ((D2Act5Quest6Strc*)pQuestData->pQuestDataEx)->bQuestStarted = 1;
            pQuestData->fLastState = 1;
            pQuestData->fState = 3;
        }
    }
}

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

// 0x0058D770
int __fastcall ACT5Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 40, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 40, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 40, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 40, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 36);
    }
    return 0;
}

// 0x0058D7D0
int __fastcall ACT5Q6_UnitIterate_CreateLastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_THEWORLDSTONECHAMBER)
    {
        D2CoordStrc coord;
        UNITS_GetCoords(pUnit, &coord);
        coord.nX += 5;
        D2ActiveRoomStrc* pFreeRoom = UNITS_GetRoom(pUnit);
        QUESTS_GetFreePosition(pRoom, &coord, 5, 0x400, &pFreeRoom, 18, 100);
        if (pFreeRoom)
        {
            SUNIT_AllocUnitData(2, 0x235, coord.nX, coord.nY, pGame, pFreeRoom, 1, 1, 0);
        }

        return 1;
    }

    return 0;
}

// 0x0058D870
void __fastcall ACT5Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestArg->pTarget && (unsigned short)pQuestArg->pTarget->dwClassId == 0x209 && !pQuestDataEx->bLastPortalOpened)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, pQuestArg->pPlayer, ACT5Q6_UnitIterate_CreateLastPortal);
        pQuestDataEx->bLastPortalOpened = 1;
    }
}

// 0x0058D8B0
int __fastcall ACT5Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q6_BAAL);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_STARTED);
    }
    else if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x0058D940
void __fastcall ACT5Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    switch (pQuestArg->nMessageIndex)
    {
    case 20178:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 4);
        break;
    }
    case 20177:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 5);
        break;
    }
    case 20179:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 6);
        break;
    }
    case 20175:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 7);
        break;
    }
    case 20180:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 8);
        break;
    }
    case 20176:
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 9);
        break;
    }
    }
}

// 0x0058D9F0
void __fastcall ACT5Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act5Quest6Strc* pQuestDataEx = (D2Act5Quest6Strc*)pQuestData->pQuestDataEx;
    switch (nNpcId)
    {
    case MONSTER_ANCIENTSTATUE1:
    case MONSTER_ANCIENTSTATUE2:
    case MONSTER_ANCIENTSTATUE3:
    {
        D2QuestDataStrc* pAncientsQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A5Q5_ANCIENTS);
        if (pAncientsQuest && ((D2Act5Quest5Strc*)pAncientsQuest->pQuestDataEx)->bAncientsActivated && !((D2Act5Quest5Strc*)pAncientsQuest->pQuestDataEx)->nAncientsAlive)
        {
            if ((pQuestData->fState == 1 && !pQuestDataEx->bQuestStarted) || (pQuestData->fState == 2 && pQuestDataEx->bQuestStarted))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
        return;
    }
    default:
        break;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))
    {
        switch (nNpcId)
        {
        case MONSTER_LARZUK:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_ENTERAREA))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
            else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
            break;
        case MONSTER_CAIN6:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_CUSTOM6))
            {
                if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM1))
                    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
                else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
                    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
            }
            break;
        case MONSTER_MALAH:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM2))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
            else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
            break;
        case MONSTER_TYRAEL3:
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
            break;
        case MONSTER_QUAL_KEHK:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM4))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
            else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
            break;
        case MONSTER_DREHYA:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_CUSTOM5))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
            else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q6, QFLAG_PRIMARYGOALDONE))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
            break;
        }
        return;
    }

    if (pQuestData->fState < 4)
    {
        unsigned int nIndex = gnA5Q6NpcActivateIndices[pQuestData->fState];
        if (nIndex != -1 && nIndex < 9)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

