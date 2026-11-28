#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameAux.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2GameObjs.h"
#include "D2QuestData.h"
#include "D2ObjModes.h"
#include "D2MonModes.h"
#include "D2Packets.h"
#include "FogApi.h"
#include "D2CommonApi.h"

struct D2PoolSystemStrc;
struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2Act5Quest3Strc;

struct D2MonsterDataStrc;

struct D2StaticPathStrc;

struct D2ModeChangeStrc;

struct D2MapAIHolderStrc;

struct D2ObjInitFnStrc;

union D2SeedStrc;

struct D2GSPacketSrv5D;

struct D2ItemsTxt;

struct D2QuestRewardItemsStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2CoordStrc;

struct D2QuestDataStrc;

struct D2QuestArgStrc;

struct D2MapAIStrc;

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"


typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

D2UnitStrc* __fastcall QUESTS_SpawnCriticalMonster(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int bQuestFlags, int nMonsterId); // 0x005459A0


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230

int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0

void __fastcall MONSTERAI_CloseNpcInteractions(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide); // 0x00573180

D2MapAIStrc** __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000


void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath); // 0x00648730


bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00589160


int __fastcall ACT5Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00588F10


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc*, int); // 0x005452C0

extern unsigned int gnAct5Q3MessageIndices[]; // 0x00734304

static void ACT5Q3_RemoveTownNpcs(D2QuestDataStrc* pQuestData);

static void __stdcall ACT5Q3_SpawnDrehyaInTown(D2QuestDataStrc* pQuestData, D2Act5Quest3Strc* pQuestDataEx);


#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2MapAIPathPositionStrc;

struct D2ObjectControlStrc;

struct D2Act5Quest5Strc;

struct D2Act5Quest6Strc;

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall ACT5Q3_UpdateResistances(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue); // 0x00589FF0


void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern char gpAct5Q3NpcMessages[]; // 0x00734320

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300


void __fastcall ACT5Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589D20

void __fastcall ACT5Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589D80

void __fastcall ACT5Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589B00

void __fastcall ACT5Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00588F80

void __fastcall ACT5Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00589580

void __fastcall ACT5Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT5Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT5Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0058A300

bool __fastcall ACT5Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00589F10

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_CUSTOM4 8

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

void __fastcall ACT5Q3_UnitIterate_CheckForDefrostPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs); // 0x0058A270


struct D2QuestRewardItemsStrc { unsigned int* pCodes; int nCount; };

extern D2QuestRewardItemsStrc gNormalRewards[]; // 0x00735F6C

extern D2QuestRewardItemsStrc gNightmareRewards[]; // 0x00735EFC

extern D2QuestRewardItemsStrc gHellRewards[]; // 0x00735F34

int __fastcall ACT5Q3_RemoveDrehyaIced(D2GameStrc*, D2UnitStrc*, void*); // 0x005890B0



extern "C" void* __cdecl memset(void*, int, unsigned int);

#define QUEST_A5Q3_PRISONOFICE 33

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

// 0x00588EB0
int __fastcall ACT5Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 37, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 37, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 37, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 33);
    }

    return 0;
}

// 0x00588F10
int __fastcall ACT5Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 2);
    }
    else if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 3);
    }

    return 0;
}

// 0x00588F80
void __fastcall ACT5Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nClassId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if ((short)nClassId != 0x201)
    {
        return;
    }

    if (pQuestDataEx->bMalahIntroActivated)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bMalahIntroActivated = 0;
    }

    if (pQuestData->bNotIntro && pQuestDataEx->bMalahActivated && pQuestData->fLastState < 4)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bMalahActivated = 0;
    }
}

// 0x00589000
void __fastcall ACT5Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == 4)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 0xD);
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 1);
    }
}

static inline int CLIENTS_GetUnitX_Inlined(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nX;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitY_Inlined(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nY;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x0058A0A0
void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nValue = 0;
    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[0], 0x25, 7))
    {
        nValue = 10;
    }

    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[1], 0x25, 7))
    {
        nValue += 10;
    }

    if (QUESTRECORD_GetQuestState(UNITS_GetPlayerData(pUnit)->pQuestData[2], 0x25, 7))
    {
        nValue += 10;
    }

    if (nValue)
    {
        ACT5Q3_UpdateResistances(pGame, pUnit, nValue);
    }
}

// 0x0058A270
void __fastcall ACT5Q3_UnitIterate_CheckForDefrostPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!ITEMS_FindQuestItem(pGame, pUnit, 0x20656369))
    {
        return;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 3);
    if (pQuestData)
    {
        ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bDefrostPotionAcquired = 1;
    }
}

// 0x00589340
static void ACT5Q3_KillNihlathakInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pNihlathak); // 0x00589340

static inline int CLIENTS_GetUnitX_A5Q3(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitY_A5Q3(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}


// 0x0058A2A0
static int ACT5Q3_HasDefrostPotion(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer)
{
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' eci'))
    {
        return 1;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuest->pQuestDataEx;
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId == 0xFFFF)
    {
        return 0;
    }

    pQuestDataEx->bDefrostPotionAcquired = 0;
    PARTY_IteratePartyMembers(pQuest->pGame, nPartyId, ACT5Q3_UnitIterate_CheckForDefrostPotion, 0);
    return pQuestDataEx->bDefrostPotionAcquired != 0;
}

// 0x0058A300
bool __fastcall ACT5Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;
    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDGRANTED))
    {
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING) || QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_PRIMARYGOALDONE))
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, QFLAG_CUSTOM4) && !QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, QFLAG_CUSTOM5))
        {
            *pStatus = 6;
            return true;
        }

        if (!QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, QFLAG_CUSTOM4))
        {
            *pStatus = 5;
            return true;
        }

        *pStatus = 13;
        return true;
    }

    if (!pQuest->bNotIntro)
    {
        return true;
    }

    if (ACT5Q3_HasDefrostPotion(pQuest, pPlayer))
    {
        *pStatus = 4;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, QUESTSTATEFLAG_A5Q3, QFLAG_COMPLETEDNOW))
    {
        *pStatus = 12;
    }
    else if (pQuest->fState < 5)
    {
        *pStatus = pQuest->fLastState;
    }

    return true;
}

// 0x0058A410
void __fastcall ACT5Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT5Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT5Q3_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT5Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q3_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT5Q3_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 1482, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 37;
    pQuestData->pfStatusFilter = ACT5Q3_StatusFilterCallback;
    pQuestData->nInitNo = 5;
    pQuestData->pfActiveFilter = ACT5Q3_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q3_SeqCallback;
    pQuestData->nSeqId = 34;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest3Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
    pQuestDataEx->nDrehyaState = 0;
    pQuestDataEx->bNihlathakLeftTown = 0;
}

static inline D2BitBufferStrc* QUESTS_GetPlayerFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0058A110
void __fastcall ACT5Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, 0x20656369))
    {
        pQuestDataEx->nDefrostPotionsInGame = 1;
    }
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        pQuestDataEx->nDrehyaState = 2;
        pQuestDataEx->bNihlathakLeftTown = 1;
        return;
    }
    if (!pQuestData->bNotIntro)
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3))
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2))
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
    if (pQuestDataEx->nDefrostPotionsInGame)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 4;
    }
}

// 0x0058A1E0
void __fastcall ACT5Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20656369))
    {
        ++((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->nDefrostPotionsInGame;
    }
    if (pQuestData->bNotIntro && pQuestData->fState < 5)
    {
        return;
    }
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 34);
    if (!pQuest)
    {
        return;
    }
    if (!pQuest->bNotIntro)
    {
        return;
    }
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 37, 1)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 6)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 38, 14);
    }
}

#define ITEMCODE_DEFROST_POTION 0x20656369
struct D2ObjOperateFnStrc;
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}


// 0x0058ABC0
int __fastcall OBJECTS_OperateFunction67_FrozenAnya(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;

    if (!ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ITEMCODE_DEFROST_POTION))
    {
        QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20131);

        if (pQuestData->fLastState == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        }

        return 0;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED)
        && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING)
        && ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ITEMCODE_DEFROST_POTION))
    {
        --pQuestDataEx->nDefrostPotionsInGame;
        QUESTS_DeleteItem(pOp->pGame, pOp->hPlayer, ITEMCODE_DEFROST_POTION);
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 2001);

        pQuestDataEx->nDrehyaState = 1;
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_REWARDPENDING);

        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 5, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        QUESTS_TriggerFX(pQuestData->pGame, 16);

        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT5Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT5Q3_UnitIterate_SetCompletionFlag);

        if (!pQuestDataEx->bTimerActive)
        {
            pQuestDataEx->bTimerActive = 1;
            pQuestDataEx->pDrehyaObjectOutsideTownCoords.nX = CLIENTS_GetUnitX(pOp->hObject);
            pQuestDataEx->pDrehyaObjectOutsideTownCoords.nY = CLIENTS_GetUnitY(pOp->hObject);

            QUESTS_CreateTimer(pQuestData, ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown, 1);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->hObject), 0);
        }
    }

    return 0;
}


// 0x0058AD80
void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pMapAi)
    {
        return;
    }

    pQuestDataEx->pDrehyaMapAI = DRLGPRESET_CreateCopyOfMapAI(pQuestData->pGame->pMemoryPool, pMapAi);
    if (!pQuestDataEx->bDrehyaMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pDrehya = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_MONSTER, pQuestDataEx->nDrehyaMonsterInTownGUID);
    if (pDrehya && pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, AIGENERAL_GetMapAiFromUnit(pDrehya));
        pQuestDataEx->bDrehyaMapAIChanged = 1;
    }
}

// 0x0058AE10
void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData || !pMapAi)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pNilathakMapAI = DRLGPRESET_CreateCopyOfMapAI(pQuestData->pGame->pMemoryPool, pMapAi);
    if (!pQuestDataEx->bNihlathakMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pNihlathak = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_MONSTER, pQuestDataEx->NihlathakMonsterInTownGUID);
    if (pNihlathak && pQuestDataEx->pNilathakMapAI && pQuestDataEx->pNilathakMapAI->pPosition && !pQuestDataEx->bNilathakMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNilathakMapAI, AIGENERAL_GetMapAiFromUnit(pNihlathak));
        pQuestDataEx->bNilathakMapAIChanged = 1;
    }
}

// 0x0058EAC0
void __fastcall OBJECTS_InitFunction66_DrehyaStartInTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (pQuestData)
    {
        D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nDrehyaObjectInTownGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
        pQuestDataEx->bDrehyaInTownInitialized = 1;
        pQuestDataEx->pDrehyaObjectInTownCoords.nX = pOp->nX;
        pQuestDataEx->pDrehyaObjectInTownCoords.nY = pOp->nY;
        switch (pQuestDataEx->nDrehyaState)
        {
        case 2:
            ACT5Q3_SeqCallback(pQuestData);
            if (!pQuestDataEx->bDrehyaMonsterInTownSpawned)
            {
                D2UnitStrc* pDrehya = QUESTS_SpawnCriticalMonster(pOp->pGame, pOp->nX, pOp->nY, pOp->pRoom, 1, MONSTER_DREHYA);
                if (pDrehya)
                {
                    pQuestDataEx->nDrehyaMonsterInTownGUID = !pDrehya ? -1 : pDrehya->dwUnitId;
                    pQuestDataEx->bDrehyaMonsterInTownSpawned = 1;
                    D2MapAIStrc** ppMapAI = AIGENERAL_GetMapAiFromUnit(pDrehya);
                    if (pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
                    {
                        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, ppMapAI);
                        pQuestDataEx->bDrehyaMapAIChanged = 1;
                    }
                }
            }
            break;
        }
    }
    D2UnitStrc* pObject = pOp->pObject;
    D2GameStrc* pGame = pOp->pGame;
    D2QuestDataStrc* pOtherQuest = QUESTS_GetQuestData(pGame, 34);
    if (pOtherQuest && ((D2Act5Quest4Strc*)pOtherQuest->pQuestDataEx)->bNeedsToOpenPortal)
        EVENT_SetEvent(pGame, pObject, 7, pGame->dwGameFrame + 12, 0, 0);
}

// 0x0058A500
void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bFrozenAnyaObjectSpawned)
    {
        return;
    }

    D2UnitStrc* pFrozenDrehya = SUNIT_AllocUnitData(2, 558, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), pGame, UNITS_GetRoom(pUnit), 1, 0, 0);
    if (pFrozenDrehya)
    {
        pFrozenDrehya->dwFlags |= 0x3000000;
        pQuestDataEx->bFrozenAnyaObjectSpawned = 1;
        pQuestDataEx->nFrozenDrehyaObjectGUID = !pFrozenDrehya ? -1 : pFrozenDrehya->dwUnitId;
    }
    else
    {
        EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
    }
}

// 0x0058A5B0
void __fastcall OBJECTS_InitFunction67_DrehyaStartOutsideTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nDrehyaObjectOutsideTownGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    if (!pQuestDataEx->bFrozenAnyaObjectSpawned)
    {
        EVENT_SetEvent(pQuestData->pGame, pOp->pObject, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
    }
}

// 0x0058A610
void __fastcall OBJECTS_InitFunction68_NihlathakStartInTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nNihlathakObjectInTownGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (pQuestDataEx->bNihlathakLeftTown || pQuestDataEx->bNihlathakMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pNihlathak = QUESTS_SpawnCriticalMonster(pOp->pGame, pOp->nX, pOp->nY, pOp->pRoom, 1, MONSTER_NIHLATHAK);
    if (!pNihlathak)
    {
        return;
    }

    pQuestDataEx->NihlathakMonsterInTownGUID = !pNihlathak ? -1 : pNihlathak->dwUnitId;
    pQuestDataEx->bNihlathakMonsterInTownSpawned = 1;

    D2MapAIStrc** ppMapAI = AIGENERAL_GetMapAiFromUnit(pNihlathak);
    if (pQuestDataEx->pNilathakMapAI && pQuestDataEx->pNilathakMapAI->pPosition && !pQuestDataEx->bNilathakMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pNilathakMapAI, ppMapAI);
        pQuestDataEx->bNilathakMapAIChanged = 1;
    }
}

// 0x0058A820
int __fastcall ACT5Q3_SpawnDrehyaPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return 0;
    }
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDrehyaPortalOutsideTownSpawned)
    {
        return 1;
    }
    if (!pQuestDataEx->nDrehyaState)
    {
        return 0;
    }
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), pQuestDataEx->pDrehyaPortalCoords.nX, pQuestDataEx->pDrehyaPortalCoords.nY);
    if (!pRoom)
    {
        pQuestDataEx->pDrehyaPortalCoords.nX += 3;
        pQuestDataEx->pDrehyaPortalCoords.nY += 3;
        return 0;
    }
    D2UnitStrc* pDrehyaPortal = SUNIT_AllocUnitData(2, 189, pQuestDataEx->pDrehyaPortalCoords.nX, pQuestDataEx->pDrehyaPortalCoords.nY, pGame, pRoom, 1, 1, 0);
    if (!pDrehyaPortal)
    {
        return 0;
    }
    pQuestDataEx->bDrehyaPortalOutsideTownSpawned = 1;
    pQuestDataEx->nDrehyaPortalOutsideTownGUID = pDrehyaPortal->dwUnitId;
    return 1;
}

// 0x0058A8D0
int __fastcall ACT5Q3_GetDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->nDrehyaState)
    {
        return 0;
    }

    if (!pQuestDataEx->bDrehyaPortalOutsideTownSpawned)
    {
        UNITS_GetCoords(pUnit, pCoord);
        return 1;
    }

    pCoord->nX = pQuestDataEx->pDrehyaPortalCoords.nX;
    pCoord->nY = pQuestDataEx->pDrehyaPortalCoords.nY;
    return 1;
}

// 0x0058A940
int __fastcall ACT5Q3_InitializeDrehyaPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return 0;
    }
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    UNITS_GetCoords(pUnit, &pQuestDataEx->pDrehyaPortalCoords);
    pQuestDataEx->bDrehyaPortalCoordsInitialized = 1;
    return 1;
}

// 0x0058A980
void __fastcall ACT5Q3_OnDrehyaRescued(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bChangeToSpecialObjectModeOutsideTown = 1;
    pQuestDataEx->nDrehyaState = 2;
    ACT5Q3_SpawnDrehyaInTown(pQuestData, pQuestDataEx);
}

// 0x0058A9B0
void __fastcall ACT5Q3_SetDrehyaSpecialModeInTown(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (pQuestData)
    {
        ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bChangeToSpecialObjectModeInTown = 1;
    }
}

// 0x0058A9D0
int __fastcall ACT5Q3_GetQuestFlagAF(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
    if (!pQuestData)
    {
        return 0;
    }
    return ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->unused0xAF != 0;
}

// 0x0058A9F0
int __fastcall ACT5Q3_IsDrehyaNotRescued(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return 0;
    }

    return ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->nDrehyaState == 0;
}

static int __fastcall OBJMODE_GetSuperUniqueId(unsigned int nIndex)
{
    if (nIndex <= 65)
    {
        return sgptDataTables->nSuperUniqueIds[nIndex];
    }

    return -1;
}

// 0x0058A6C0
void __fastcall OBJECTS_InitFunction69_NihlathakStartOutsideTown(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bNihlathakLeftTown != 1 || pQuestDataEx->bNilathakOutsideTownSpawned)
    {
        return;
    }

    const int nMonsterId = DATATBLS_MapSuperUniqueId(2, OBJMODE_GetSuperUniqueId(60));
    const int nY = pOp->nY;
    const int nX = pOp->nX;
    D2UnitStrc* pNihlathak = D2GAME_SpawnPresetMonster(pOp->pGame, pOp->pRoom, nMonsterId, nX, nY, 1);
    if (pNihlathak)
    {
        pQuestDataEx->nNihlathakOutsideTownGUID = !pNihlathak ? -1 : pNihlathak->dwUnitId;
        pQuestDataEx->bNilathakOutsideTownSpawned = 1;
    }
}

// 0x0058A730
void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;

    switch (nAnimMode)
    {
    case OBJMODE_OPERATING:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_OPENED);
        break;

    case OBJMODE_OPENED:
    {
        D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
        if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_HARROGATH)
        {
            if (++pQuestDataEx->nObjectUpdateInvocations > 5)
            {
                pQuestDataEx->bChangeToSpecialObjectModeInTown = 1;
            }

            if (pQuestDataEx->bChangeToSpecialObjectModeInTown)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        else
        {
            if (pQuestDataEx->bChangeToSpecialObjectModeOutsideTown)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        break;
    }

    case OBJMODE_SPECIAL1:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL2);
        break;
    }

    EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
}

// 0x0058A7D0
int __fastcall ACT5Q3_GetDrehyaPortalInTownCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDrehyaPortalInTownSpawned || pQuestDataEx->bChangeToSpecialObjectModeInTown)
    {
        return 0;
    }

    pCoord->nX = pQuestDataEx->tDrehyaPortalInTownCoords.nX;
    pCoord->nY = pQuestDataEx->tDrehyaPortalInTownCoords.nY;
    return 1;
}

// 0x0058AA10
void __fastcall ACT5Q3_UpdateStatusOnActivate(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058AA50
void __fastcall OBJECTS_InitFunction74_FrozenAnya(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 33);
    if (!pQuestData)
    {
        return;
    }
    ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->nFrozenAnyaObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    if (pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058AAB0
bool __fastcall ACT5Q3_SpawnDrehyaIcedMonsterOutsideTown(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDrehyaIcedMonsterSpawned)
    {
        D2UnitStrc* pFrozenDrehya = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nFrozenAnyaObjectGUID);
        if (!pQuestDataEx->nTimerInvocations)
        {
            if (pFrozenDrehya)
            {
                UNITS_ChangeAnimMode(pFrozenDrehya, 2);
                UNITS_FreeCollisionPath(pFrozenDrehya);
            }

            pQuestDataEx->nTimerInvocations = 1;
        }
        else if (pQuestDataEx->nTimerInvocations == 1)
        {
            pQuestDataEx->nTimerInvocations = 2;
            if (pFrozenDrehya)
            {
                D2UnitStrc* pDrehya = QUESTS_SpawnCriticalMonster(pGame, pQuestDataEx->pDrehyaObjectOutsideTownCoords.nX, pQuestDataEx->pDrehyaObjectOutsideTownCoords.nY, UNITS_GetRoom(pFrozenDrehya), 1, MONSTER_DREHYAICED);
                if (pDrehya)
                {
                    const int nUnitGUID = pFrozenDrehya->dwUnitId;
                    const int nUnitType = pFrozenDrehya->dwUnitType;
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pFrozenDrehya), nUnitType, nUnitGUID);
                    UNITROOM_RemoveUnitFromRoom(pFrozenDrehya);

                    D2MapAIStrc** ppMapAi = AIGENERAL_GetMapAiFromUnit(pDrehya);
                    if (pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
                    {
                        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, ppMapAi);
                        pQuestDataEx->bDrehyaMapAIChanged = 1;
                    }

                    const int nDrehyaGUID = (pDrehya ? pDrehya->dwUnitId : -1);
                    pQuestDataEx->nDrehyaIcedMonsterGUID = nDrehyaGUID;
                    pQuestDataEx->bDrehyaIcedMonsterSpawned = 1;
                    ACT5Q3_SeqCallback(pQuestData);
                    pQuestDataEx->bTimerActive = 0;
                    return true;
                }
            }
        }
    }

    return false;
}

// 0x00589070
void __fastcall ACT5Q3_SendPacket0x5DToClient(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nFlags = 32;
    packet5D.nQuestId = QUEST_A5Q3_PRISONOFICE;
    SCMD_SendPacket0x5D(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 286), &packet5D);
}

#define UNIT_INVALID 6

// 0x005890B0
int __fastcall ACT5Q3_RemoveDrehyaIced(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!pUnit || pUnit->dwClassId != MONSTER_DREHYAICED)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2MonsterInteractStrc* pMonInteract = nType == UNIT_MONSTER && pUnit->pMonsterData ? pUnit->pMonsterData->pMonInteract : 0;

    if (MONSTERAI_HasInteractUnit(pMonInteract))
    {
        MONSTERAI_CloseNpcInteractions(pGame, pUnit, ACT5Q3_SendPacket0x5DToClient, 0);
        return 1;
    }

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, MONMODE_DEAD, &modeChange);
    D2GAME_ModeChange(pGame, &modeChange, 1);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q3_PRISONOFICE);
    if (pQuestData)
    {
        ((D2Act5Quest3Strc*)pQuestData->pQuestDataEx)->bDrehyaIcedRemoved = 1;
    }

    return 1;
}

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

// 0x00589160
bool __fastcall ACT5Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < 5 && pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            pQuestData->fState = 1;
        }
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 331);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005891D0
static void __stdcall ACT5Q3_SpawnDrehyaInTown(D2QuestDataStrc* pQuestData, D2Act5Quest3Strc* pQuestDataEx)
{
    if (pQuestDataEx->bDrehyaInTownInitialized != 1)
    {
        return;
    }

    D2UnitStrc* pDrehyaInTown = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nDrehyaObjectInTownGUID);
    if (!pDrehyaInTown)
    {
        return;
    }

    D2ObjInitFnStrc op;
    op.pRoom = UNITS_GetRoom(pDrehyaInTown);
    op.nX = CLIENTS_GetUnitX_Inlined(pDrehyaInTown);
    op.nY = CLIENTS_GetUnitY_Inlined(pDrehyaInTown);
    if (pQuestDataEx->bDrehyaMonsterInTownSpawned)
    {
        return;
    }

    D2UnitStrc* pDrehya = QUESTS_SpawnCriticalMonster(pQuestData->pGame, op.nX, op.nY, op.pRoom, 1, MONSTER_DREHYA);
    if (!pDrehya)
    {
        return;
    }

    pQuestDataEx->nDrehyaMonsterInTownGUID = !pDrehya ? -1 : pDrehya->dwUnitId;
    pQuestDataEx->bDrehyaMonsterInTownSpawned = 1;

    D2MapAIStrc** ppMapAI = AIGENERAL_GetMapAiFromUnit(pDrehya);
    if (pQuestDataEx->pDrehyaMapAI && pQuestDataEx->pDrehyaMapAI->pPosition && !pQuestDataEx->bDrehyaMapAIChanged)
    {
        pQuestDataEx->bDrehyaMapAIChanged = 1;
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pDrehyaMapAI, ppMapAI);
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pDrehya, &pCoord);

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pDrehya), pCoord.nX, pCoord.nY);
    if (pRoom)
    {
        D2UnitStrc* pDrehyaPortal = SUNIT_AllocUnitData(2, 0xBD, pCoord.nX, pCoord.nY, pQuestData->pGame, pRoom, 1, 1, 0);
        if (pDrehyaPortal)
        {
            pQuestDataEx->bDrehyaPortalInTownSpawned = 1;
            pQuestDataEx->nDrehyaPortalInTownGUID = !pDrehyaPortal ? -1 : pDrehyaPortal->dwUnitId;
        }
    }

    ACT5Q3_SeqCallback(pQuestData);
}

// 0x00589340
static void ACT5Q3_KillNihlathakInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pNihlathak)
{
    D2MonsterInteractStrc* pMonInteract = pNihlathak && pNihlathak->dwUnitType == UNIT_MONSTER && pNihlathak->pMonsterData ? pNihlathak->pMonsterData->pMonInteract : 0;
    if (MONSTERAI_HasInteractUnit(pMonInteract))
    {
        MONSTERAI_CloseNpcInteractions(pQuestData->pGame, pNihlathak, 0, 0);
    }

    D2Common_10153(pNihlathak->pDynamicPath);
    D2GAME_EVENTS_Delete(pQuestData->pGame, pNihlathak, 2, 0);
    STATLIST_SetUnitStat(pNihlathak, STAT_HITPOINTS, 0, 0);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pNihlathak, 12, &modeChange);
    modeChange.nX = 0;
    modeChange.nY = 0;
    D2GAME_ModeChange(pQuestData->pGame, &modeChange, 1);
    UNITROOM_RefreshUnit(pNihlathak);
    pNihlathak->dwFlags |= 1;
}

// 0x005893E0
static void ACT5Q3_RemoveTownNpcs(D2QuestDataStrc* pQuestData)
{
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDrehyaMonsterInTownSpawned && pQuestDataEx->nDrehyaState != 2)
    {
        D2UnitStrc* pDrehya = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nDrehyaMonsterInTownGUID);
        if (pDrehya)
        {
            D2MonsterInteractStrc* pMonInteract = pDrehya->dwUnitType == UNIT_MONSTER && pDrehya->pMonsterData ? pDrehya->pMonsterData->pMonInteract : 0;
            if (MONSTERAI_HasInteractUnit(pMonInteract))
            {
                MONSTERAI_CloseNpcInteractions(pQuestData->pGame, pDrehya, 0, 0);
            }

            D2ModeChangeStrc modeChange;
            MONSTERMODE_GetModeChangeInfo(pDrehya, 12, &modeChange);
            D2GAME_ModeChange(pQuestData->pGame, &modeChange, 1);

            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pDrehya), !pDrehya ? 6 : pDrehya->dwUnitType, pQuestDataEx->nDrehyaMonsterInTownGUID);
            UNITS_FreeCollisionPath(pDrehya);
            UNITROOM_RemoveUnitFromRoom(pDrehya);
        }
        else
        {
            SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 0x200, 4);
        }

        pQuestDataEx->bDrehyaMonsterInTownSpawned = 0;
    }

    if (pQuestDataEx->bNihlathakMonsterInTownSpawned)
    {
        D2UnitStrc* pNihlathak = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->NihlathakMonsterInTownGUID);
        if (pNihlathak)
        {
            ACT5Q3_KillNihlathakInTown(pQuestData, pNihlathak);

            const int nObjectGUID = pQuestDataEx->nNihlathakObjectInTownGUID;
            D2UnitStrc* pNihlathakInTown = SUNIT_GetServerUnit(pQuestData->pGame, 2, nObjectGUID);
            if (pNihlathakInTown)
            {
                D2GameStrc* pGame = pQuestData->pGame;
                const int nFrame = pGame->dwGameFrame;
                EVENT_SetEvent(pGame, pNihlathakInTown, 7, nFrame + 1, 0, 0);
            }
        }
        else
        {
            SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 0x202, 4);
        }

        pQuestDataEx->bNihlathakMonsterInTownSpawned = 0;
    }

    if (!pQuestDataEx->bNihlathakLeftTown)
    {
        pQuestDataEx->bNihlathakLeftTown = 1;
    }
}

// 0x00589540
void __fastcall ACT5Q3_RemoveNihlathakFromTown(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x21);
    if (!pQuestData)
    {
        return;
    }

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pNihlathak = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->NihlathakMonsterInTownGUID);
    if (pNihlathak)
    {
        ACT5Q3_KillNihlathakInTown(pQuestData, pNihlathak);
    }
}

// 0x00589580
void __fastcall ACT5Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    const unsigned short nNpcId = (unsigned short)pQuestArg->nOldLevel;
    const unsigned short nMessage = (unsigned short)pQuestArg->nNewLevel;
    D2BitBufferStrc* pQuestFlags = QUESTS_GetPlayerFlags(pGame, pQuestArg->pPlayer);
    if (nNpcId == 513)
    {
        if (nMessage == 20116)
        {
            pQuestDataEx->bMalahIntroActivated = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x208);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            return;
        }
        if (nMessage == 20127)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' eci') || pQuestDataEx->nDefrostPotionsInGame)
                return;
            if (!QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' eci', 0, 2, 1))
                return;
            ++pQuestDataEx->nDefrostPotionsInGame;
            D2ClientStrc* pClient = UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x214);
            D2GSPacketSrv5D packet;
            memset(&packet, 0, sizeof(packet));
            packet.nHeader = 0x5D;
            packet.nQuestId = 33;
            packet.nFlags = 1;
            SCMD_SendPacket0x5D(pClient, &packet);
            pQuestDataEx->bMalahActivated = 1;
            return;
        }
        if (nMessage == 20132)
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 1) && !QUESTRECORD_GetQuestState(pQuestFlags, 37, 0))
            {
                if (!QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2rt', 0, 2, 1))
                    return;
                QUESTRECORD_SetQuestState(pQuestFlags, 37, 8);
                D2ClientStrc* pClient = UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x22B);
                D2GSPacketSrv5D packet;
            memset(&packet, 0, sizeof(packet));
                packet.nHeader = 0x5D;
                packet.nQuestId = 33;
                packet.nFlags = 2;
                SCMD_SendPacket0x5D(pClient, &packet);
                if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 9))
                {
                    QUESTRECORD_ClearQuestState(pQuestFlags, 37, 1);
                    QUESTRECORD_SetQuestState(pQuestFlags, 37, 0);
                }
                else if (pQuestData->bNotIntro && pQuestData->fLastState < 6)
                {
                    pQuestData->nStatusFlags = 0;
                    QUESTS_UnitIterate(pQuestData, 6, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
                }
                if (pQuestDataEx->nDrehyaState == 1)
                {
                    pQuestDataEx->bDrehyaIcedRemoved = 0;
                    SUNIT_IterateUnitsOfType(pQuestData->pGame, 1, 0, ACT5Q3_RemoveDrehyaIced);
                    if (!pQuestDataEx->bDrehyaIcedRemoved)
                        SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 527, 4);
                    pQuestDataEx->bChangeToSpecialObjectModeOutsideTown = 1;
                    pQuestDataEx->nDrehyaState = 2;
                    ACT5Q3_SpawnDrehyaInTown(pQuestData, pQuestDataEx);
                }
                QUESTS_UpdatePlayerFlags(pQuestArg->pGame, pQuestArg->pPlayer);
                return;
            }
            if ((QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
                && !pQuestDataEx->bRewarded && QUESTRECORD_GetQuestState(pQuestFlags, 37, 8)
                && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 7)
                && !ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2rt'))
            {
                if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2rt', 0, 2, 1))
                    pQuestDataEx->bRewarded = 1;
            }
            return;
        }
    }
    else if (nNpcId == 512 && nMessage == 20136)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 37, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 37, 0))
            return;
        D2QuestRewardItemsStrc* pRewardTable = gNormalRewards;
        const unsigned int nLevel = STATLIST_GetUnitBaseStat(pQuestArg->pPlayer, STAT_LEVEL, 0);
        switch (pQuestArg->pGame->nDifficulty)
        {
        case 1:
            if (pQuestArg->pGame->nGameType == 3 || nLevel > 45)
                pRewardTable = gNightmareRewards;
            break;
        case 2:
            if (pQuestArg->pGame->nGameType == 3 || nLevel > 65)
                pRewardTable = gHellRewards;
            break;
        }
        if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 10))
            return;
        const int nClassId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwClassId;
        const unsigned int nIndex = SEED_RollLimitedRandomNumber(QUESTS_GetGlobalSeed(pQuestArg->pGame), pRewardTable[nClassId].nCount);
        const unsigned int nCode = pRewardTable[nClassId].pCodes[nIndex];
        D2UnitStrc* pItem = QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, nCode, ITEMS_GetItemLevelForNewItem(pQuestArg->pPlayer, 0), 6, 1);
        if (!pItem)
            return;
        const int nItemClassId = pItem->dwClassId;
        D2GSPacketSrv5D packet;
        memset(&packet, 0, sizeof(packet));
        packet.nHeader = 0x5D;
        packet.nFlags = 16;
        packet.nQuestId = 33;
        D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nItemClassId);
        if (pItemsTxt && pItemsTxt->wDropSound > 0)
            packet.field_4 = pItemsTxt->wDropSound;
        SCMD_SendPacket0x5D(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x375), &packet);
        QUESTRECORD_SetQuestState(pQuestFlags, 37, 9);
        if (QUESTRECORD_GetQuestState(pQuestFlags, 37, 8))
        {
            QUESTRECORD_ClearQuestState(pQuestFlags, 37, 1);
            QUESTRECORD_SetQuestState(pQuestFlags, 37, 0);
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 37, 10);
        return;
    }
    if (nMessage == 20131 && pQuestData->bNotIntro)
    {
        if (pQuestData->fState <= 3)
        {
            QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x387);
            ACT5Q3_RemoveTownNpcs(pQuestData);
        }
        if (pQuestData->fLastState < 3)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
        }
    }
}

// 0x00589A50
int __fastcall ACT5Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0xD))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q3_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00589AA0
int __fastcall ACT5Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x25, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x25, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x21, 0);
    }

    return 0;
}

// 0x00589B00
void __fastcall ACT5Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    if (nNpcId == 527)
    {
        if (pQuestData->fState == 6)
        {
            D2ModeChangeStrc mode;
            MONSTERMODE_GetModeChangeInfo(pQuestArg->pTarget, 12, &mode);
            D2GAME_ModeChange(pQuestArg->pGame, &mode, 1);
        }
        return;
    }
    if (nNpcId == 513)
    {
        if (pQuestData->fState == 4)
        {
            if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20656369) && !pQuestDataEx->nDefrostPotionsInGame)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 513, 3);
            return;
        }
        if ((QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 15))
            && !pQuestDataEx->bRewarded && QUESTRECORD_GetQuestState(pFlags, 37, 8)
            && !QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 7)
            && !ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20327274)
            && !QUESTRECORD_GetQuestState(pFlags, 37, 8))
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 513, 5);
    }
    if (QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 1))
    {
        if (nNpcId == 512 && QUESTRECORD_GetQuestState(pFlags, 37, 9)) return;
        if (nNpcId == 513 && QUESTRECORD_GetQuestState(pFlags, 37, 8)) return;
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        return;
    }
    if (bRewardGranted != 1 && (pQuestData->fState < 5 || bPrimaryGoalDone) && pQuestData->bNotIntro)
    {
        const unsigned int nIndex = gnAct5Q3MessageIndices[pQuestData->fState];
        if (nIndex != -1 && nIndex < 10)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00589D20
void __fastcall ACT5Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' eci'))
    {
        --pQuestDataEx->nDefrostPotionsInGame;
    }
}

// 0x00589D80
void __fastcall ACT5Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;
    if (pQuestArg->nNewLevel == 0x70)
    {
        if (pQuestData->bNotIntro && !pQuestData->fState)
        {
            pQuestData->fState = 1;
            ACT5Q3_RemoveTownNpcs(pQuestData);
        }
    }
    else if ((pQuestArg->nNewLevel == 0x71 || pQuestArg->nNewLevel == 0x72) && pQuestData->bNotIntro)
    {
        bool bStateChanged = false;
        if (pQuestData->fState <= 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x451);
            bStateChanged = true;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
        }
        else if (bStateChanged)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
        }

        ACT5Q3_RemoveTownNpcs(pQuestData);
    }

    if (nOldLevel == 0x6D)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState == 2)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q3.cpp", 0x46E);
            if (!pQuestData->fLastState)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q3_UnitIterate_StatusCyclerEx, 1);
            }
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q3_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel < 0x79 || nNewLevel > 0x7C || !pQuestData->bNotIntro || pQuestData->fState >= 5)
    {
        return;
    }

    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q3_UnitIterate_SetCompletionFlag);
    pQuestData->fState = 6;

    D2Act5Quest3Strc* pQuestDataEx = (D2Act5Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nDrehyaState = 2;
    if (!pQuestDataEx->bNihlathakLeftTown)
    {
        pQuestDataEx->bNihlathakLeftTown = 1;
    }
}

// 0x00589F10
bool __fastcall ACT5Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_MALAH)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM4))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return false;
        }

        if (pQuest->fState == 1)
        {
            return true;
        }

        if (pQuest->fState == 4 && ((D2Act5Quest3Strc*)pQuest->pQuestDataEx)->nDefrostPotionsInGame == 0)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_DREHYAICED)
    {
        if (pQuest->bNotIntro && pQuest->fState < 5 && !ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ITEMCODE_DEFROST_POTION))
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_DREHYA)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return false;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM5) == 0)
        {
            return true;
        }
    }

    return false;
}

#define STAT_FIRERESIST 39

#define STAT_LIGHTRESIST 41

#define STAT_COLDRESIST 43

#define STAT_POISONRESIST 45

void __fastcall D2GAME_UpdateAttribute(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520


// D2Game passes a D2StatListStrc here; D2CommonApi2.h types it D2StatListExStrc (one object, two record views).
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

// 0x00589FF0
void __fastcall ACT5Q3_UpdateResistances(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    if (!pStatList)
    {
        return;
    }

    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);

    STATLIST_SetStat(pStatList, STAT_FIRERESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_LIGHTRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_COLDRESIST, nValue, 0);
    STATLIST_SetStat(pStatList, STAT_POISONRESIST, nValue, 0);

    D2GAME_UpdateAttribute(pUnit, STAT_FIRERESIST, nValue, pUnit);
    D2GAME_UpdateAttribute(pUnit, STAT_LIGHTRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute(pUnit, STAT_COLDRESIST, nValue, pUnit);
    D2GAME_UpdateAttribute(pUnit, STAT_POISONRESIST, nValue, pUnit);
}

#pragma pack(push, 1)
struct d2data_00735FA4_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00735FB8_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00735FCC_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00735FE0_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00735FF4_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736008_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0073601C_t
{
    unsigned char b0[28];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736038_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0073604C_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736060_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736074_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736088_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0073609C_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007360B0_t
{
    unsigned char b0[28];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007360CC_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007360E0_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007360F4_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736108_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0073611C_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736130_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00736144_t
{
    unsigned char b0[28];
};
#pragma pack(pop)

extern "C" struct d2data_00735FA4_t gdwAmazonNormalQuestRewardCodes; // 0x00735FA4
extern "C" struct d2data_00735FB8_t gdwSorceressNormalQuestRewardCodes; // 0x00735FB8
extern "C" struct d2data_00735FCC_t gdwNecromancerNormalQuestRewardCodes; // 0x00735FCC
extern "C" struct d2data_00735FE0_t gdwPaladinNormalQuestRewardCodes; // 0x00735FE0
extern "C" struct d2data_00735FF4_t gdwBarbarianNormalQuestRewardCodes; // 0x00735FF4
extern "C" struct d2data_00736008_t gdwDruidNormalQuestRewardCodes; // 0x00736008
extern "C" struct d2data_0073601C_t gdwAssassinNormalQuestRewardCodes; // 0x0073601C
extern "C" struct d2data_00736038_t gdwAmazonExceptionalQuestRewardCodes; // 0x00736038
extern "C" struct d2data_0073604C_t gdwSorceressExceptionalQuestRewardCodes; // 0x0073604C
extern "C" struct d2data_00736060_t gdwNecromancerExceptionalQuestRewardCodes; // 0x00736060
extern "C" struct d2data_00736074_t gdwPaladinExceptionalQuestRewardCodes; // 0x00736074
extern "C" struct d2data_00736088_t gdwBarbarianExceptionalQuestRewardCodes; // 0x00736088
extern "C" struct d2data_0073609C_t gdwDruidExceptionalQuestRewardCodes; // 0x0073609C
extern "C" struct d2data_007360B0_t gdwAssassinEliteQuestRewardCodes; // 0x007360B0
extern "C" struct d2data_007360CC_t gdwAmazonEliteQuestRewardCodes; // 0x007360CC
extern "C" struct d2data_007360E0_t gdwSorceressEliteQuestRewardCodes; // 0x007360E0
extern "C" struct d2data_007360F4_t gdwNecromancerEliteQuestRewardCodes; // 0x007360F4
extern "C" struct d2data_00736108_t gdwPaladinEliteQuestRewardCodes; // 0x00736108
extern "C" struct d2data_0073611C_t gdwBarbarianEliteQuestRewardCodes; // 0x0073611C
extern "C" struct d2data_00736130_t gdwDruidEliteQuestRewardCodes; // 0x00736130
extern "C" struct d2data_00736144_t gData_00736144; // 0x00736144

extern D2QuestRewardItemsStrc gNightmareRewards[7] = {
    { (unsigned int*)&gdwAmazonEliteQuestRewardCodes, 5 },
    { (unsigned int*)&gdwSorceressEliteQuestRewardCodes, 5 },
    { (unsigned int*)&gdwNecromancerEliteQuestRewardCodes, 5 },
    { (unsigned int*)&gdwPaladinEliteQuestRewardCodes, 5 },
    { (unsigned int*)&gdwBarbarianEliteQuestRewardCodes, 5 },
    { (unsigned int*)&gdwDruidEliteQuestRewardCodes, 5 },
    { (unsigned int*)&gData_00736144, 7 }
}; // 0x00735EFC

extern D2QuestRewardItemsStrc gHellRewards[7] = {
    { (unsigned int*)&gdwAmazonExceptionalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwSorceressExceptionalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwNecromancerExceptionalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwPaladinExceptionalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwBarbarianExceptionalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwDruidExceptionalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwAssassinEliteQuestRewardCodes, 7 }
}; // 0x00735F34

extern D2QuestRewardItemsStrc gNormalRewards[7] = {
    { (unsigned int*)&gdwAmazonNormalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwSorceressNormalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwNecromancerNormalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwPaladinNormalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwBarbarianNormalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwDruidNormalQuestRewardCodes, 5 },
    { (unsigned int*)&gdwAssassinNormalQuestRewardCodes, 7 }
}; // 0x00735F6C

extern "C" struct d2data_00735FA4_t gdwAmazonNormalQuestRewardCodes = {
    {
        0x61, 0x6D, 0x31, 0x20, 0x61, 0x6D, 0x32, 0x20, 0x61, 0x6D, 0x33, 0x20, 0x61, 0x6D, 0x34, 0x20,
        0x61, 0x6D, 0x35, 0x20
    }
}; // 0x00735FA4

extern "C" struct d2data_00735FB8_t gdwSorceressNormalQuestRewardCodes = {
    {
        0x6F, 0x62, 0x31, 0x20, 0x6F, 0x62, 0x32, 0x20, 0x6F, 0x62, 0x33, 0x20, 0x6F, 0x62, 0x34, 0x20,
        0x6F, 0x62, 0x35, 0x20
    }
}; // 0x00735FB8

extern "C" struct d2data_00735FCC_t gdwNecromancerNormalQuestRewardCodes = {
    {
        0x6E, 0x65, 0x31, 0x20, 0x6E, 0x65, 0x32, 0x20, 0x6E, 0x65, 0x33, 0x20, 0x6E, 0x65, 0x34, 0x20,
        0x6E, 0x65, 0x35, 0x20
    }
}; // 0x00735FCC

extern "C" struct d2data_00735FE0_t gdwPaladinNormalQuestRewardCodes = {
    {
        0x70, 0x61, 0x31, 0x20, 0x70, 0x61, 0x32, 0x20, 0x70, 0x61, 0x33, 0x20, 0x70, 0x61, 0x34, 0x20,
        0x70, 0x61, 0x35, 0x20
    }
}; // 0x00735FE0

extern "C" struct d2data_00735FF4_t gdwBarbarianNormalQuestRewardCodes = {
    {
        0x62, 0x61, 0x31, 0x20, 0x62, 0x61, 0x32, 0x20, 0x62, 0x61, 0x33, 0x20, 0x62, 0x61, 0x34, 0x20,
        0x62, 0x61, 0x35, 0x20
    }
}; // 0x00735FF4

extern "C" struct d2data_00736008_t gdwDruidNormalQuestRewardCodes = {
    {
        0x64, 0x72, 0x31, 0x20, 0x64, 0x72, 0x32, 0x20, 0x64, 0x72, 0x33, 0x20, 0x64, 0x72, 0x34, 0x20,
        0x64, 0x72, 0x35, 0x20
    }
}; // 0x00736008

extern "C" struct d2data_0073601C_t gdwAssassinNormalQuestRewardCodes = {
    {
        0x6B, 0x74, 0x72, 0x20, 0x77, 0x72, 0x62, 0x20, 0x61, 0x78, 0x66, 0x20, 0x63, 0x65, 0x73, 0x20,
        0x63, 0x6C, 0x77, 0x20, 0x62, 0x74, 0x6C, 0x20, 0x73, 0x6B, 0x72, 0x20
    }
}; // 0x0073601C

extern "C" struct d2data_00736038_t gdwAmazonExceptionalQuestRewardCodes = {
    {
        0x61, 0x6D, 0x62, 0x20, 0x61, 0x6D, 0x63, 0x20, 0x61, 0x6D, 0x64, 0x20, 0x61, 0x6D, 0x65, 0x20,
        0x61, 0x6D, 0x66, 0x20
    }
}; // 0x00736038

extern "C" struct d2data_0073604C_t gdwSorceressExceptionalQuestRewardCodes = {
    {
        0x6F, 0x62, 0x62, 0x20, 0x6F, 0x62, 0x63, 0x20, 0x6F, 0x62, 0x64, 0x20, 0x6F, 0x62, 0x65, 0x20,
        0x6F, 0x62, 0x66, 0x20
    }
}; // 0x0073604C

extern "C" struct d2data_00736060_t gdwNecromancerExceptionalQuestRewardCodes = {
    {
        0x6E, 0x65, 0x62, 0x20, 0x6E, 0x65, 0x63, 0x20, 0x6E, 0x65, 0x64, 0x20, 0x6E, 0x65, 0x65, 0x20,
        0x6E, 0x65, 0x66, 0x20
    }
}; // 0x00736060

extern "C" struct d2data_00736074_t gdwPaladinExceptionalQuestRewardCodes = {
    {
        0x70, 0x61, 0x62, 0x20, 0x70, 0x61, 0x63, 0x20, 0x70, 0x61, 0x64, 0x20, 0x70, 0x61, 0x65, 0x20,
        0x70, 0x61, 0x66, 0x20
    }
}; // 0x00736074

extern "C" struct d2data_00736088_t gdwBarbarianExceptionalQuestRewardCodes = {
    {
        0x62, 0x61, 0x62, 0x20, 0x62, 0x61, 0x63, 0x20, 0x62, 0x61, 0x64, 0x20, 0x62, 0x61, 0x65, 0x20,
        0x62, 0x61, 0x66, 0x20
    }
}; // 0x00736088

extern "C" struct d2data_0073609C_t gdwDruidExceptionalQuestRewardCodes = {
    {
        0x64, 0x72, 0x62, 0x20, 0x64, 0x72, 0x63, 0x20, 0x64, 0x72, 0x64, 0x20, 0x64, 0x72, 0x65, 0x20,
        0x64, 0x72, 0x66, 0x20
    }
}; // 0x0073609C

extern "C" struct d2data_007360B0_t gdwAssassinEliteQuestRewardCodes = {
    {
        0x37, 0x61, 0x72, 0x20, 0x37, 0x77, 0x62, 0x20, 0x37, 0x78, 0x66, 0x20, 0x37, 0x63, 0x73, 0x20,
        0x37, 0x6C, 0x77, 0x20, 0x37, 0x74, 0x77, 0x20, 0x37, 0x71, 0x72, 0x20
    }
}; // 0x007360B0

extern "C" struct d2data_007360CC_t gdwAmazonEliteQuestRewardCodes = {
    {
        0x61, 0x6D, 0x36, 0x20, 0x61, 0x6D, 0x37, 0x20, 0x61, 0x6D, 0x38, 0x20, 0x61, 0x6D, 0x39, 0x20,
        0x61, 0x6D, 0x61, 0x20
    }
}; // 0x007360CC

extern "C" struct d2data_007360E0_t gdwSorceressEliteQuestRewardCodes = {
    {
        0x6F, 0x62, 0x36, 0x20, 0x6F, 0x62, 0x37, 0x20, 0x6F, 0x62, 0x38, 0x20, 0x6F, 0x62, 0x39, 0x20,
        0x6F, 0x62, 0x61, 0x20
    }
}; // 0x007360E0

extern "C" struct d2data_007360F4_t gdwNecromancerEliteQuestRewardCodes = {
    {
        0x6E, 0x65, 0x36, 0x20, 0x6E, 0x65, 0x37, 0x20, 0x6E, 0x65, 0x38, 0x20, 0x6E, 0x65, 0x39, 0x20,
        0x6E, 0x65, 0x61, 0x20
    }
}; // 0x007360F4

extern "C" struct d2data_00736108_t gdwPaladinEliteQuestRewardCodes = {
    {
        0x70, 0x61, 0x36, 0x20, 0x70, 0x61, 0x37, 0x20, 0x70, 0x61, 0x38, 0x20, 0x70, 0x61, 0x39, 0x20,
        0x70, 0x61, 0x61, 0x20
    }
}; // 0x00736108

extern "C" struct d2data_0073611C_t gdwBarbarianEliteQuestRewardCodes = {
    {
        0x62, 0x61, 0x36, 0x20, 0x62, 0x61, 0x37, 0x20, 0x62, 0x61, 0x38, 0x20, 0x62, 0x61, 0x39, 0x20,
        0x62, 0x61, 0x61, 0x20
    }
}; // 0x0073611C

extern "C" struct d2data_00736130_t gdwDruidEliteQuestRewardCodes = {
    {
        0x64, 0x72, 0x36, 0x20, 0x64, 0x72, 0x37, 0x20, 0x64, 0x72, 0x38, 0x20, 0x64, 0x72, 0x39, 0x20,
        0x64, 0x72, 0x61, 0x20
    }
}; // 0x00736130

extern "C" struct d2data_00736144_t gData_00736144 = {
    {
        0x39, 0x61, 0x72, 0x20, 0x39, 0x77, 0x62, 0x20, 0x39, 0x78, 0x66, 0x20, 0x39, 0x63, 0x73, 0x20,
        0x39, 0x6C, 0x77, 0x20, 0x39, 0x74, 0x77, 0x20, 0x39, 0x71, 0x72, 0x20
    }
}; // 0x00736144
