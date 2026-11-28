#include "D2GameEvents.h"
#include "D2ObjectIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameObjs.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"
#include "D2ObjModes.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

#define QFLAG_REWARDGRANTED 0

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define QUESTSTATEFLAG_A2Q5 13

#define QUESTSTATEFLAG_A2Q6 14

#define QUEST_A2Q5_SUMMONER 12

#define ACT_II 1


#define UNITFLAG_ISRESURRECT_ISINIT 0x03000000

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct D2ObjectControlStrc;

struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2Act2Quest4Strc;

union D2SeedStrc;

struct D2ObjInitFnStrc;

struct D2ObjOperateFnStrc;

struct D2Act2Quest5Strc;

struct D2Act2Quest2Strc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

enum D2C_M11A2Q4Constants
{
    QUEST_A2Q4_HORAZONTOME = 11,
    QUESTSTATEFLAG_A2Q4 = 12,
    QFLAG_REWARDPENDING = 1,
    QFLAG_CUSTOM3 = 7,
    QFLAG_CUSTOM4 = 8,
    QFLAG_PRIMARYGOALDONE = 13,
};

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


int __fastcall ACT2Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059AD50

int __fastcall ACT2Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059ADB0

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510


void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230

int __fastcall AIUTIL_GetDistanceToCoordinates(D2UnitStrc* hUnit, int nX, int nY); // 0x005DC5C0


extern "C" int gnAct2Quest4NpcIndices[]; // 0x00738D44

typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

enum
{
    QUEST_A2Q2_HORADRICSTAFF = 9,
    QUESTSTATEFLAG_A2Q2 = 10,
    QFLAG_CUSTOM7 = 11,
};


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern char gpAct2Q4NpcMessages[]; // 0x0073A638

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

bool __fastcall ACT2Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059ACA0

void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059AD40

void __fastcall ACT2Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059AE60

void __fastcall ACT2Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059AF50

void __fastcall ACT2Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059B1C0

bool __fastcall ACT2Q4_SeqCallback(D2QuestDataStrc* pQuestData); // 0x0059B500

void __fastcall ACT2Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059B530

void __fastcall ACT2Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059F0C0

#define QUEST_A2Q4_HORAZONTOME 11

#define QFLAG_REWARDPENDING 1

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

static void __stdcall ACT2Q4_InitializeJerhynMonster(D2QuestDataStrc* pQuestData, D2CoordStrc* pCoords, D2ActiveRoomStrc* pRoom); // 0x0059EF70

int __fastcall MONSTERAI_HasInteractUnit(void*); // 0x00572DC0

void __fastcall MONSTERAI_CloseNpcInteractions(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide); // 0x00573180

D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc*,int,int); // 0x00463740

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

#define QUESTSTATEFLAG_A1Q1 1

#define QUESTSTATEFLAG_A2Q1 9

#define QUESTSTATEFLAG_A2Q7 30

#define QUESTSTATEFLAG_A1INTRO 42

#define QUEST_A1Q1_DENOFEVIL 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

struct D2Act1Quest1Strc;


// 0x0059ACA0
bool __fastcall ACT2Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) == 1)
    {
        return false;
    }

    if (nNpcId == MONSTER_ACT2GUARD2)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) == 1)
        {
            return false;
        }

        D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuest->pQuestDataEx;
        switch (pQuestDataEx->nHaremBlockerObjectMode)
        {
        case OBJMODE_OPENED:
            if (pQuestDataEx->bIsHaremBlockerNeutral && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM4))
            {
                return true;
            }
            break;

        case 0:
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM3))
            {
                return true;
            }
            break;
        }
    }
    else if (nNpcId == MONSTER_DROGNAN)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_JERHYN)
    {
        if (pQuest->fState == 2 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING)
            && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED))
        {
            return true;
        }
    }

    return false;
}


// 0x0059AD40
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x0059AD50
int __fastcall ACT2Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A2Q4_HORAZONTOME);
    }
    return 0;
}

struct D2Act3Quest5Strc;

extern "C" const char gszAct3Q5SourceFile[];


// 0x0059ADB0
int __fastcall ACT2Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 12, 0) == 1)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 12, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 12, 2);
        return 0;
    }

    if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 12, 3);
        return 0;
    }

    if (pQuestData->fState == 4)
    {
        if (pQuestData->fLastState == 2 || pQuestData->fLastState == 3)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 12, 4);
            return 0;
        }

        if (pQuestData->fLastState == 4)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 12, 5);
        }
    }

    return 0;
}

enum D2C_a2q4_0059AE60Constants
{
    A2Q4_ITERATE_DEACTIVATE = 2,
};

// 0x0059AE60
void __fastcall ACT2Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_DROGNAN)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDrognanActivated != 1)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, A2Q4_ITERATE_DEACTIVATE, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bDrognanActivated = 0;
    pQuestData->pCallback[2] = 0;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);
}

// 0x0059AEC0
int __fastcall ACT2Q4_IsHaremBlockerObjectOpened(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (pQuestData && ((D2Act2Quest4Strc*)pQuestData->pQuestDataEx)->nHaremBlockerObjectMode == 2)
    {
        return 1;
    }

    return 0;
}

// 0x0059AEF0
static void ACT2Q4_OpenPalace(D2QuestDataStrc* pQuestData, D2Act2Quest4Strc* pQuestDataEx)
{
    pQuestDataEx->bPalaceOpen = 1;
    if (pQuestDataEx->nHaremBlockerObjectMode == OBJMODE_NEUTRAL)
    {
        pQuestDataEx->bIsHaremBlockerNeutral = 1;
    }
    pQuestDataEx->nHaremBlockerObjectMode = OBJMODE_OPENED;

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);

    if (pQuestDataEx->bHaremBlockerInitialized != 1)
    {
        return;
    }

    D2UnitStrc* pHaremBlocker = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nHaremBlockerGUID);
    if (!pHaremBlocker)
    {
        return;
    }

    UNITS_ChangeAnimMode(pHaremBlocker, OBJMODE_OPENED);
    UNITS_FreeCollisionPath(pHaremBlocker);
}

// 0x0059F2A0
void __fastcall ACT2Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct2Q4NpcMessages;
    pQuestData->pCallback[0] = ACT2Q4_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Q4_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT2Q4_Callback03_ChangedLevel;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[2] = ACT2Q4_Callback02_NpcDeactivate;
    pQuestData->pCallback[13] = ACT2Q4_Callback13_PlayerStartedGame;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->pQuestDataEx = FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 989, 0);
    pQuestData->eFilter = 12;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 5;
    pQuestData->pfActiveFilter = ACT2Q4_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT2Q4_SeqCallback;
    pQuestData->nSeqId = 13;
    QUESTS_ResetPlayerGUIDCount(&pQuestData->tPlayerGUIDs);

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest4Strc));
    pQuestDataEx->unused0x00 = 0;
    pQuestDataEx->unused0x01 = 0;
    pQuestDataEx->unused0x02 = 0;
    pQuestDataEx->unused0x03 = 0;
    pQuestDataEx->bDrognanActivated = 0;
}

#define QUEST_A2Q6_DURIEL 13

#define QUESTSTATEFLAG_A2Q0 8

// 0x0059F380
void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bJerhynPalaceInitialized || QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q0, QFLAG_PRIMARYGOALDONE) || QUESTS_GetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE))
    {
        return;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuest || !pQuest->bNotIntro || pQuest->fState >= 2)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = pOp->pRoom;
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;

    QUESTS_GetFreePosition(pRoom, &pCoord, 2, 0x100, &pRoom, 10, 100);

    D2UnitStrc* pJerhyn = D2GAME_SpawnMonster(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, MONSTER_JERHYN, 1, -1, 0);
    if (pJerhyn)
    {
        pQuestDataEx->bJerhynStartInitialized = 1;
        pQuestDataEx->nJerhynGUID = pJerhyn->dwUnitId;
    }
}


// 0x0059F440
void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (QUESTS_GetGlobalState((!pQuestData ? 0 : pQuestData->pGame), 14, 13) != 1)
    {
        D2ActiveRoomStrc* pRoom = pOp->pRoom;
        pQuestDataEx->pGuardCoords.nX = pOp->nX + 1;
        pQuestDataEx->pGuardCoords.nY = pOp->nY;
        MONSTERSPAWN_SpawnAtCoordinates((pQuestData ? pQuestData->pGame : 0), pRoom, pQuestDataEx->pGuardCoords.nX, pQuestDataEx->pGuardCoords.nY, MONSTER_ACT2GUARD2, 1, 0);
    }

    EVENT_SetEvent(pOp->pGame, pOp->pObject, 7, pOp->pGame->dwGameFrame + 1, 0, 0);

    D2CoordStrc tCoords;
    tCoords.nX = pOp->nX;
    tCoords.nY = pOp->nY;
    if (pQuestDataEx->bJerhynPalaceInitialized)
    {
        return;
    }

    if (!QUESTS_GetGlobalState((pQuestData ? pQuestData->pGame : 0), 8, 13) && !QUESTS_GetGlobalState((pQuestData ? pQuestData->pGame : 0), 9, 13))
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData((pQuestData ? pQuestData->pGame : 0), 13);
        if (pQuest && pQuest->bNotIntro && pQuest->fState < 2)
        {
            return;
        }
    }

    ACT2Q4_InitializeJerhynMonster(pQuestData, &tCoords, pOp->pRoom);
}

// 0x0059F510
unsigned char __fastcall ACT2Q4_IsJerhynPalaceBlocked(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData11 = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData11 || !((D2Act2Quest4Strc*)pQuestData11->pQuestDataEx)->bJerhynPalaceInitialized)
    {
        return 1;
    }

    D2QuestDataStrc* pQuestData8 = QUESTS_GetQuestData(pQuestData11->pGame, 8);
    return !pQuestData8 || !pQuestData8->bNotIntro || pQuestData8->fState == 5 || ACT2Q6_IsTyraelPortalOpened(pQuestData11->pGame)
        || pQuestData11->bNotIntro != 1 || pQuestData11->fState >= 2;
}

// 0x0059F570
int __fastcall ACT2Q4_IsJerhynPalaceActivated(D2GameStrc* pGame)
{
    return ACT2Q4_IsJerhynPalaceBlocked(pGame) == 1 ? 1 : 0;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x0059AF50
void __fastcall ACT2Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;

    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo == MONSTER_ACT2GUARD2)
    {
        switch (nMessageIndex)
        {
        case 186:
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM3);
            break;

        case 187:
        case 188:
        case 189:
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM4);
            break;
        }
    }
    else
    {
        if (nMessageIndex == 406 || nMessageIndex == 403 || nMessageIndex == 397 || nMessageIndex == 400 || nMessageIndex == 398 || nMessageIndex == 399
            || nMessageIndex == 405 || nMessageIndex == 407 || nMessageIndex == 402 || nMessageIndex == 401 || nMessageIndex == 404)
        {
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING))
            {
                QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING);
                QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            }
        }

        if (nMessageIndex == 396)
        {
            if (pQuestData->bNotIntro && pQuestData->fLastState < 5)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 5, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 0);
            }

            if (!pQuestDataEx->bPortalToCanyonOpen && UNITS_GetRoom(pQuestArg->pPlayer) == pQuestDataEx->pRoom)
            {
                D2ActiveRoomStrc* pRoom = 0;
                D2CoordStrc pCoord;
                UNITS_GetCoords(pQuestArg->pPlayer, &pCoord);
                QUESTS_GetFreePosition(pQuestDataEx->pRoom, &pCoord, 2, 0xBE11, &pRoom, 8, 100);
                if (pRoom && D2GAME_CreatePortalObject(pQuestData->pGame, pQuestArg->pPlayer, pRoom, pCoord.nX, pCoord.nY, LEVEL_CANYONOFTHEMAGI, 0, OBJECT_PERMANENT_TOWN_PORTAL, 0))
                {
                    pQuestDataEx->bPortalToCanyonOpen = 1;
                    QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
                }
            }
        }

        if (nNPCNo == MONSTER_DROGNAN)
        {
            if (nMessageIndex == 373)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 466);
                pQuestDataEx->bDrognanActivated = 1;
                ACT2Q4_OpenPalace(pQuestData, pQuestDataEx);
                QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            }
        }
        else if (nNPCNo == MONSTER_JERHYN)
        {
            if (nMessageIndex == 377)
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 474);
                QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 3, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);
            }
        }
    }
}

// 0x0059B1C0
void __fastcall ACT2Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    int nNpcId;
    if (!pQuestArg->pTarget)
    {
        nNpcId = -1;
    }
    else
    {
        nNpcId = pQuestArg->pTarget->dwClassId;
        if (nNpcId == MONSTER_ACT2GUARD2)
        {
            D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pQuestData->pGame);
            if (((D2Act2Quest4Strc*)pQuestData->pQuestDataEx)->bPalaceOpen)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD2, SEED_RollRandomNumber(pSeed) % 3 + 8);
            }
            else
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, MONSTER_ACT2GUARD2, 7);
            }
            return;
        }
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
    }
    else if (pQuestData->fState && pQuestData->bNotIntro && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) != 1
        && (pQuestData->fState < 5 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE)))
    {
        const int nIndex = gnAct2Quest4NpcIndices[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 12)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x0059B320
int __fastcall ACT2Q4_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_COMPLETEDNOW);
    }

    return 0;
}

// 0x0059B360
void __fastcall ACT2Q4_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_II)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, QUESTSTATEFLAG_A2Q4);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM4);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM3);
}

struct D2GameStrc;

struct D2UnitStrc;

// 0x0059B3F0
int __fastcall ACT2Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ARCANESANCTUARY)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, QUESTSTATEFLAG_A2Q4);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM4);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM3);

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q4_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0059B4A0
static bool ACT2Q4_RunSeqFilter(D2QuestDataStrc* pQuestData)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x34E);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x0059B500
bool __fastcall ACT2Q4_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 0x35A);
        ACT2Q4_RunSeqFilter(pQuestData);
    }
    return true;
}

enum D2C_P08QuestConstants
{
    QUESTSTATEFLAG_A2Q3 = 11,
    QFLAG_CUSTOM1 = 5,
};


// 0x0059B530
void __fastcall ACT2Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED))
    {
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDPENDING) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE);
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20747368))
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 1;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_CUSTOM1) == 1)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 4;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 4;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 3;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_STARTED) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 2;
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) == 1)
    {
        pQuestDataEx->bPalaceOpen = 1;
        pQuestDataEx->nHaremBlockerObjectMode = 2;
    }
}

// 0x0059B660
void __fastcall ACT2Q4_OpenPalaceOrCycle(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->bNotIntro)
    {
        if (!pQuestData->fState)
        {
            QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 959);
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 1);
        }
    }
    else
    {
        ACT2Q4_OpenPalace(pQuestData, pQuestDataEx);
    }
}

// 0x0059B6C0
void __fastcall ACT2Q4_OnJerhynSpawned(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY){
}

// 0x0059B6D0
void __fastcall ACT2Q4_OnPalaceGuardSpawned(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY){
}

// 0x0059B6E0
int __fastcall ACT2Q4_IsGuardMoving(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bJerhynTeleportedToPalace != 1 || pQuestDataEx->bGuardMoveStarted)
    {
        return 0;
    }

    pQuestDataEx->bGuardMoveStarted = 1;
    return 1;
}

// 0x0059B710
void __fastcall ACT2Q4_InitializeHaremBlockerObject(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);
    if (pQuestDataEx->bPalaceOpen || pQuestDataEx->bHaremBlockerInitialized)
    {
        return;
    }

    pQuestDataEx->nHaremBlockerObjectMode = OBJMODE_NEUTRAL;
    pQuestDataEx->pHaremBlockerCoords.nX = pCoord.nX - 2;
    pQuestDataEx->pHaremBlockerCoords.nY = pCoord.nY - 1;

    D2UnitStrc* pHaremBlocker = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_EUNUCH_HAREM_BLOCKER, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY, pQuestData->pGame, UNITS_GetRoom(pUnit), 1, 0, 0);

    if (!pHaremBlocker)
    {
        pQuestDataEx->pHaremBlockerCoords.nY = pCoord.nY;
        pHaremBlocker = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_EUNUCH_HAREM_BLOCKER, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY, pQuestData->pGame, UNITS_GetRoom(pUnit), 1, 0, 0);
    }

    if (!pHaremBlocker)
    {
        return;
    }

    pHaremBlocker->dwFlags |= UNITFLAG_ISRESURRECT_ISINIT;
    pQuestDataEx->bHaremBlockerInitialized = 1;
    pQuestDataEx->nHaremBlockerGUID = !pHaremBlocker ? -1 : pHaremBlocker->dwUnitId;
}

// 0x0059B7D0
void __fastcall OBJECTS_InitFunction30_HaremBlocker(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nHaremBlockerObjectMode);

    pQuestDataEx->nHaremBlockerGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (pQuestDataEx->nHaremBlockerObjectMode == OBJMODE_OPENED)
    {
        UNITS_FreeCollisionPath(pOp->pObject);
    }
}

struct D2ActiveRoomStrc;

struct D2CoordStrc;

static inline void* GetMonsterInteract(D2UnitStrc* unit) {
    if (unit && unit->dwUnitType==UNIT_MONSTER && unit->pMonsterData) return unit->pMonsterData->pMonInteract;
    return 0;
}

// 0x0059B820
int __fastcall ACT2Q4_UnitIterate_CheckDistanceToHaremBlocker(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME)->pQuestDataEx;

    if ((unsigned int)AIUTIL_GetDistanceToCoordinates(pUnit, pQuestDataEx->pHaremBlockerCoords.nX, pQuestDataEx->pHaremBlockerCoords.nY) > 30)
    {
        return 0;
    }

    pQuestDataEx->bPlayerCloseToHaremBlocker = 1;
    pQuestDataEx->nPlayerCloseToHaremBlockerGUID = !pUnit ? -1 : pUnit->dwUnitId;
    return 1;
}

// 0x0059B8B0
int __fastcall ACT2Q4_HasGuardMovedToEndPosition(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (pQuestData)
    {
        D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->bGuardAtPost && !pQuestDataEx->bGuardSteppedAside)
        {
            return pQuestDataEx->nHaremBlockerObjectMode == 2;
        }

        return 0;
    }

    return 1;
}

// 0x0059B8F0
int __fastcall ACT2Q4_GetGuardCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bGuardAtPost)
    {
        *pCoord = pQuestDataEx->pGuardCoords;
        return 1;
    }

    if (pQuestDataEx->bGuardSteppedAside)
    {
        *pCoord = pQuestDataEx->pGuardCoords;
        pCoord->nY -= 4;
        return 1;
    }

    return 0;
}

void __stdcall EmitQuestNpc(D2QuestDataStrc* quest,D2CoordStrc* coords,D2ActiveRoomStrc* room) {
    ACT2Q4_InitializeJerhynMonster(quest,coords+1,room);
}

static
// 0x0059EF70
void __stdcall ACT2Q4_InitializeJerhynMonster(D2QuestDataStrc* quest,D2CoordStrc* coords,D2ActiveRoomStrc* room) {
    D2Act2Quest4Strc* ex=(D2Act2Quest4Strc*)quest->pQuestDataEx;
    if (ex->bJerhynStartInitialized==1) {
        D2UnitStrc* unit=SUNIT_GetServerUnit(quest->pGame,1,ex->nJerhynGUID);
        if (unit) {
            void* interact=GetMonsterInteract(unit);
            if (MONSTERAI_HasInteractUnit(interact)) {
                MONSTERAI_CloseNpcInteractions(quest->pGame,unit,0,1);
                return;
            }
            GAME_RemoveUnit(unit,quest->pGame);
            ex->bJerhynStartInitialized=0;
        }
    }
    if (ex->bJerhynPalaceInitialized==1) return;
    D2QuestDataStrc* other=QUESTS_GetQuestData(quest->pGame,13);
    int bDone=1;
    if (other && other->bNotIntro && other->fState < 2) bDone=0;
    if (bDone) coords->nX+=15;
    else coords->nX-=10;
    coords->nY-=3;
    D2ActiveRoomStrc* found=COLLISION_GetRoomBySubTileCoordinates(room,coords->nX,coords->nY);
    QUESTS_GetFreePosition(room,coords,3,0x100,&found,9,100);
    D2UnitStrc* npc=D2GAME_SpawnMonster(quest->pGame,found,coords->nX,coords->nY,MONSTER_JERHYN,1,-1,0);
    if (!npc) npc=D2GAME_SpawnMonster(quest->pGame,found,coords->nX,coords->nY,MONSTER_JERHYN,1,2,0);
    if (npc) {
        npc->dwFlags|=0x03000000;
        ex=(D2Act2Quest4Strc*)quest->pQuestDataEx;
        ex->bJerhynPalaceInitialized=1;
        if (!ex->bJerhynCoordinatesStored) {
            ex->bJerhynCoordinatesStored=1;
            ex->pJerhynCoords.nX=coords->nX;
            ex->pJerhynCoords.nY=coords->nY;
        }
    }
}

// 0x0059B940
int __fastcall ACT2Q4_UnitIterate_UselessGoalCheck(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE);

    return 0;
}

// 0x0059B970
int __fastcall OBJECTS_OperateFunction42_SanctuaryTome(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (pQuestData)
    {
        D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
        QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 396);

        pQuestDataEx->pRoom = UNITS_GetRoom(pOp->hObject);

        if (pQuestData->bNotIntro && pQuestData->fState != 5)
        {
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 1517);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_SetCompletionFlag);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UselessGoalCheck);
        }
    }

    return 0;
}

// 0x0059BA40
void __fastcall OBJECTS_InitFunction29_ArcaneSanctuaryPortal(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (!pQuestData)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;

    if (nLevelId == LEVEL_ARCANESANCTUARY)
    {
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nPortalModeInSanctuary);
        if (pQuestDataEx->nPortalModeInSanctuary == OBJMODE_OPERATING)
        {
            pQuestDataEx->nPortalModeInSanctuary = OBJMODE_OPENED;

            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
    }
    else if (nLevelId == LEVEL_PALACECELLARLEV3)
    {
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nPortalModeInCellar);
        if (pQuestDataEx->nPortalModeInCellar == OBJMODE_OPERATING)
        {
            pQuestDataEx->nPortalModeInCellar = OBJMODE_OPENED;

            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);
            EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
    }
}

// 0x0059BAF0
void __fastcall ACT2Q4_SetPortalMode(D2GameStrc* pGame, int nLevelId)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q4_HORAZONTOME);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (nLevelId == LEVEL_ARCANESANCTUARY)
    {
        if (!pQuestDataEx->nPortalModeInCellar)
        {
            pQuestDataEx->nPortalModeInCellar = OBJMODE_OPERATING;
            pQuestDataEx->nPortalModeInSanctuary = OBJMODE_OPENED;
        }
    }
    else if (nLevelId == LEVEL_PALACECELLARLEV3)
    {
        if (!pQuestDataEx->nPortalModeInSanctuary)
        {
            pQuestDataEx->nPortalModeInSanctuary = OBJMODE_OPERATING;
            pQuestDataEx->nPortalModeInCellar = OBJMODE_OPENED;
        }
    }
}

int __fastcall ACT2Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059BF80

static inline void* QUESTS_GetMonsterInteract(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }
    return 0;
}

static inline D2BitBufferStrc* QUESTS_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0059F0C0
void __fastcall ACT2Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    const int nNewLevel = pQuestArg->nNewLevel;
    if (nNewLevel == 74)
    {
        bool bChanged = false;
        if (pQuestData->fState < 4)
        {
            bChanged = true;
            QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 663);
        }

        if (pQuestData->fLastState < 4)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT2Q4_UnitIterate_StatusCyclerEx, 1);
        }
        else if (!bChanged)
        {
            return;
        }

        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);
        return;
    }

    if (nNewLevel == 50)
    {
        D2BitBufferStrc* pQuestFlags = QUESTS_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
        QUESTRECORD_SetQuestState(pQuestFlags, 12, 8);
        pQuestFlags = QUESTS_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);
        QUESTRECORD_SetQuestState(pQuestFlags, 12, 7);
    }

    if (nOldLevel != 40)
    {
        return;
    }

    D2Act2Quest4Strc* pQuestDataEx = (D2Act2Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bJerhynStartInitialized == 1)
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nJerhynGUID);
        if (!pUnit)
        {
            pQuestDataEx->bJerhynStartInitialized = 0;
        }
        else if (MONSTERAI_HasInteractUnit(QUESTS_GetMonsterInteract(pUnit)))
        {
            MONSTERAI_CloseNpcInteractions(pQuestData->pGame, pUnit, 0, 1);
        }
        else
        {
            GAME_RemoveUnit(pUnit, pQuestData->pGame);
            pQuestDataEx->bJerhynStartInitialized = 0;
        }
    }

    if (!pQuestDataEx->bJerhynPalaceInitialized && pQuestDataEx->bHaremBlockerInitialized)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nHaremBlockerGUID);
        if (pObject)
        {
            D2CoordStrc tCoords;
            UNITS_GetCoords(pObject, &tCoords);
            ACT2Q4_InitializeJerhynMonster(pQuestData, &tCoords, UNITS_GetRoom(pObject));
        }
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

    D2BitBufferStrc* pQuestFlags = QUESTS_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 12, 0) == 1)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 12, 1) == 1)
    {
        return;
    }

    if (pQuestData->fState == 3)
    {
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q4.cpp", 734);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q4_UnitIterate_UpdateQuestStateFlags);
    }
}

