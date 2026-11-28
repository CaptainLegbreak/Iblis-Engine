#include "D2GameEvents.h"
#include "D2MissileIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Txt.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2Packets.h"
#include "D2ObjectIds.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#define QUEST_A1Q4_CAIN 4

#define QUESTSTATEFLAG_A1Q4 4

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define LINE_ITEM_PICKED 1222

struct D2PoolSystemStrc;
struct D2NPCMessageTableStrc;

union D2SeedStrc;

struct D2PlayerDataStrc;

struct D2StaticPathStrc;

struct D2QuestGUIDStrc;

struct D2ObjOperateFnStrc;

struct D2MissilesTxt;

struct D2Act1Quest4Strc;

struct D2Act1Quest5Strc;

struct D2Act2Quest0Strc;

struct D2Act2Quest1Strc;

struct D2Act2Quest6Strc;

struct D2Act3Quest5Strc;

struct D2Act5Quest2Strc;


typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520

int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630


void __fastcall ACT1Q4_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005930B0


void __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598D40


void __fastcall ACT2Q6_UnitIterate_DeleteHoradricItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059DBD0

void __fastcall ACT3Q5_UnitIterate_DeleteKhalimItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BB850


D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740




typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005920D0

int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005928C0

int __fastcall ACT1Q4_UnitIterate_AddPlayerGUIDs(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00592B10

void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592C80

bool __fastcall ACT1Q4_Timer_RemoveCainFromTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x00593260

extern const char gszAct1Q4SourceFile[]; // 0x006E1C48

void __fastcall ACT1Q4_SetMonolithOrder(D2QuestDataStrc* pQuestData); // 0x00592E90


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

void __fastcall ACT1Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005921B0

void __fastcall ACT1Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592250

void __fastcall ACT1Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592580

void __fastcall ACT1Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592B90

void __fastcall ACT1Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592CF0

void __fastcall ACT1Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592E20

void __fastcall ACT1Q4_Callback06_ResetInifussTree(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00592E60

bool __fastcall ACT1Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00592FB0

bool __fastcall ACT1Q4_SeqCallback(D2QuestDataStrc* pQuestData); // 0x00593D70

void __fastcall ACT1Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00593E70

void __fastcall ACT1Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00596DE0

void __fastcall ACT1Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00597030

#define ITEM_RING 0x206E6972

#define DIFFMODE_NIGHTMARE 1

#define DIFFMODE_HELL 2

#define ITEMQUAL_NORMAL 2

#define ITEMQUAL_MAGIC 4

#define ITEMQUAL_RARE 6


void __fastcall QUESTS_SendLogUpdate(D2UnitStrc* pUnit, int nQuestId); // 0x005458E0


extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD


struct D2ObjInitFnStrc;

extern int gnA1Q4MessageIndices[]; // 0x00737648

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int nId); // 0x005452C0

typedef int(__fastcall* QUESTTIMERFN)(D2GameStrc*, D2QuestDataStrc*);

int __fastcall ACT1Q4_OpenPortalToTristram(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x00592D50

struct D2ActiveRoomStrc;

struct D2MonsterDataStrc;

struct D2ModeChangeStrc;

int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0

void __fastcall MONSTERAI_CloseNpcInteractions(D2GameStrc* pGame, D2UnitStrc* pMonster, void(__fastcall* pCallback)(D2UnitStrc*), char bClientSide); // 0x00573180

void __fastcall ACT1Q4_SendPacket0x5DToClient(D2UnitStrc* pUnit); // 0x00592880


int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


int __fastcall ACT1Q4_UnitIterate_FindPlayersInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00593220

int __fastcall ACT1Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00593130

int __fastcall ACT1Q4_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005931C0


struct D2CoordStrc;

struct D2QuestDataStrc;

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);           // 0x00545310


static void ACT1Q4_DebugStartedQuest(D2QuestDataStrc* pQuestData);

extern "C" const char gszStartedQuest[];                                                            // 0x006E1C7C



int __fastcall sub_005936B0_UpdateParty(D2GameStrc*,D2UnitStrc*,void*); // 0x005936B0

void __fastcall PARTY_IteratePartyMembers(D2GameStrc*,unsigned short,QUESTUNITITERATE,void*); // 0x00540510

static inline int GetGUID(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }

static void __stdcall ACT1Q4_SpawnCainInTown(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY);


inline D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer) { return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty]; }

static void __stdcall ACT1Q4_UpdateObjects(char bUseRemovalTimer, char bMoveCainToTown, D2QuestDataStrc* pQuestData);

void __fastcall ACT1Q4_StartCainRemoval(D2GameStrc* pGame);


int __fastcall OBJECTS_OperateFunction12_InifussTree(D2ObjOperateFnStrc* pOp, int nOperate);


struct D2Act1Quest4ExStrc
{
    unsigned char padding[0x46];
    unsigned char cainActive;
};

inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    D2MissilesTxt* pRecord;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        pRecord = 0;
    }
    else
    {
        pRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return pRecord;
}

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int UNITS_GetGUIDOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static inline int UNITS_GetClassIdOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x005920D0
int __fastcall ACT1Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A1Q4_CAIN);
    }

    return 0;
}

// 0x00592130
int __fastcall ACT1Q4_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestRecord, 4, 0) == 1 || QUESTRECORD_GetQuestState(pQuestRecord, 4, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestRecord, 4, 2);
        return 0;
    }
    if (pQuestData->fState >= 3 && pQuestData->fState <= 5)
    {
        QUESTRECORD_SetQuestState(pQuestRecord, 4, 3);
    }
    return 0;
}

// 0x005921B0
void __fastcall ACT1Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const short nClassId = UNITS_GetClassIdOrNone(pQuestArg->pTarget);
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    if (nClassId == MONSTER_AKARA)
    {
        if (pQuestDataEx->bAkaraIntroActivated == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bAkaraIntroActivated = 0;
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
        }

        if (pQuestDataEx->bAkaraActivatedForScroll == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, QSTATE_3, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
            pQuestDataEx->bAkaraActivatedForScroll = 0;
        }
    }
    else if (nClassId == MONSTER_CAIN1)
    {
        pQuestDataEx->bCainInTristramDeactivated = 1;
    }
}

// 0x005971B0
void __fastcall ACT1Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[3] = ACT1Q4_Callback03_ChangedLevel;
    pQuestData->pCallback[4] = ACT1Q4_Callback04_ItemPickedUp;
    pQuestData->pCallback[6] = ACT1Q4_Callback06_ResetInifussTree;
    pQuestData->pCallback[14] = ACT1Q4_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT1Q4_Callback09_PlayerDroppedWithQuestItem;
    pQuestData->pCallback[8] = ACT1Q4_Callback08_MonsterKilled;
    pQuestData->pNPCMessages = gpAct1Q4NpcMessages;
    pQuestData->eFilter = 4;
    pQuestData->fLastState = 0;
    pQuestData->bActive = 1;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 6;
    pQuestData->pfActiveFilter = ACT1Q4_ActiveFilterCallback;
    pQuestData->pCallback[0] = ACT1Q4_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT1Q4_Callback11_ScrollMessage;
    pQuestData->pCallback[10] = ACT1Q4_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[2] = ACT1Q4_Callback02_NpcDeactivate;
    pQuestData->pCallback[13] = ACT1Q4_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q4_SeqCallback;
    pQuestData->nSeqId = 3;

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 2399, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest4Strc));

    pQuestDataEx->nStoneCount = 0;
    pQuestDataEx->bMonolithStonesOrdered = 0;
    pQuestDataEx->bDecipheredScrollAcquired = 0;
    pQuestDataEx->unused0x4B = 0;
    pQuestDataEx->nCairnStoneInteractions = 0;
    pQuestDataEx->nInvisibleObjectGUID = 0;
    pQuestDataEx->bInvisbleObjectInitialized = 0;
    pQuestDataEx->nInifussTreeGUID = 0;
    pQuestDataEx->nDecipheredScrollGUID = 0;
    pQuestDataEx->bInifussTreeInitialized = 0;
    pQuestDataEx->bTimerActive = 0;
    pQuestDataEx->nInifussTreeObjectMode = 0;
    pQuestDataEx->nCainGibbetObjectMode = 0;
    pQuestDataEx->bCompleted = 0;
    pQuestDataEx->bCairnStonesActive[0] = 0;
    pQuestDataEx->bCairnStonesActive[1] = 0;
    pQuestDataEx->bCairnStonesActive[2] = 0;
    pQuestDataEx->bCairnStonesActive[3] = 0;
    pQuestDataEx->bCairnStonesActive[4] = 0;
    pQuestDataEx->bCainInTownSpawned = 0;
    pQuestDataEx->bCainInTownSpawnPending = 0;
    pQuestDataEx->bCainRemovedFromTristram = 0;
    pQuestDataEx->bCainNotCreated = 0;
    pQuestDataEx->bAkaraIntroActivated = 0;
    pQuestDataEx->bAkaraActivatedForScroll = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->pQuestGUID);
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

inline int GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

// 0x00592250
void __fastcall ACT1Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const short nNpcId = pQuestArg->nNPCNo;
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    const short nMessageIndex = pQuestArg->nMessageIndex;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNpcId == MONSTER_AKARA)
    {
        if (nMessageIndex == 97)
        {
            pQuestDataEx->bAkaraIntroActivated = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 333);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            return;
        }

        if (nMessageIndex == 112)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_BOOK_BKS))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_BOOK_BKS);
                D2UnitStrc* pDecipheredScroll = (D2UnitStrc*)QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_SCROLL_BKD, 0, ITEMQUAL_NORMAL, 1);
                if (pDecipheredScroll)
                {
                    pQuestDataEx->bAkaraActivatedForScroll = 1;
                    pQuestDataEx->unused0x4B = 1;
                    pQuestDataEx->bDecipheredScrollAcquired = 1;
                    pQuestDataEx->nDecipheredScrollGUID = !pDecipheredScroll ? -1 : pDecipheredScroll->dwUnitId;
                    QUESTS_DebugOutput(pQuestData->pGame, "deciphered scroll", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 351);
                    QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 352);
                    pQuestData->nStatusFlags = 0;
                    QUESTS_UnitIterate(pQuestData, 3, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 0);
                }
                else
                {
                    --pQuestDataEx->nScrollsInGame;
                }
            }
            return;
        }

        if (nMessageIndex != 118 || !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED);
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING);

        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);

        int nItemLevel = 7;
        int nItemQuality = ITEMQUAL_MAGIC;
        switch (pQuestArg->pGame->nDifficulty)
        {
        case DIFFMODE_NIGHTMARE:
            nItemQuality = ITEMQUAL_RARE;
            nItemLevel = 30;
            break;

        case DIFFMODE_HELL:
            nItemQuality = ITEMQUAL_RARE;
            nItemLevel = 60;
            break;
        }

        QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_RING, nItemLevel, nItemQuality, 1);
        QUESTS_SendLogUpdate(pQuestArg->pPlayer, QUEST_A1Q4_CAIN);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE))
        {
            if (pQuestData->fLastState != 13)
            {
                pQuestData->fLastState = 13;
            }

            if (pQuestData->fState != 6)
            {
                QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 399);
            }

            if (!QUESTS_GetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE))
            {
                QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 404);
                pQuestData->pfSeqFilter(pQuestData);
            }
        }

        if (pQuestDataEx->bQuestCompleteBefore == 1)
        {
            QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
        }
        return;
    }
    else if (nNpcId == MONSTER_CAIN5)
    {
        if (nMessageIndex == 125)
        {
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        else if (nMessageIndex == 126 || nMessageIndex == 123)
        {
            QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x00592580
void __fastcall ACT1Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    D2UnitStrc* pScroll = ITEMS_FindQuestItem(pArg->pGame, pArg->pPlayer, ' skb');
    int nNpc;
    if (!pArg->pTarget) nNpc = -1;
    else nNpc = pArg->pTarget->dwClassId;
    D2UnitStrc* pPlayer = pArg->pPlayer;
    D2GameStrc* pGame = pArg->pGame;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2BitBufferStrc* pFlags = pPlayerData->pQuestData[pGame->nDifficulty];
    D2Act1Quest4Strc* pEx = (D2Act1Quest4Strc*)pQuest->pQuestDataEx;
    if (nNpc == 146) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 146, 9);
    if (pEx->bOperatedWithLastCairnStone == 1 && ITEMS_FindQuestItem(pArg->pGame, pArg->pPlayer, ' dkb'))
    {
        QUESTS_DeleteItem(pArg->pGame, pArg->pPlayer, ' dkb');
        --pEx->nScrollsInGame;
    }
    int bRewardPending = QUESTRECORD_GetQuestState(pFlags, 4, 1);
    int bCompletedNow = QUESTRECORD_GetQuestState(pFlags, 4, 13);
    if (nNpc == 265 && !QUESTS_QuickCheckPlayerGUID(&pEx->tPlayerGUIDs, GetUnitId(pArg->pPlayer)) && bCompletedNow)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 5);
        return;
    }
    if (bRewardPending)
    {
        if (nNpc == 265)
        {
            if (QUESTS_QuickCheckPlayerGUID(&pEx->tPlayerGUIDs, GetUnitId(pArg->pPlayer))) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 7);
            else QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 5);
        }
        else QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 5);
        return;
    }
    if (QUESTS_QuickCheckPlayerGUID(&pEx->pQuestGUID, GetUnitId(pArg->pPlayer)) == 1)
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 6);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuest, GetUnitId(pArg->pPlayer)) == 1 && nNpc == 265 && !QUESTS_QuickCheckPlayerGUID(&pEx->tPlayerGUIDs, GetUnitId(pArg->pPlayer)))
    {
        QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, 265, 5);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuest, GetUnitId(pArg->pPlayer)) == 1)
    {
        if (QUESTRECORD_GetQuestState(pFlags, 4, 14))
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 8);
            return;
        }
        if (QUESTRECORD_GetQuestState(pFlags, 4, 0)) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 7);
        return;
    }
    else if (!QUESTRECORD_GetQuestState(pFlags, 4, 14) && pQuest->fState && QUESTRECORD_GetQuestState(pFlags, 4, 0) != 1 && !QUESTRECORD_GetQuestState(pFlags, 4, 15))
    {
        if (!pScroll && pQuest->fState == 4)
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 2);
        }
        else if (pScroll)
        {
            QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, 3);
        }
        else if (pQuest->fState < 6)
        {
            int nMessage = gnA1Q4MessageIndices[pQuest->fState];
            if (nMessage != -1 && (unsigned int)nMessage < 11) QUESTS_InitScrollTextChain(pQuest, pArg->pTextControl, nNpc, nMessage);
        }
    }
}

inline D2MonsterInteractStrc* MONSTERS_GetMonInteractInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

// 0x00592860
static void ACT1Q4_DebugStartedQuest(D2QuestDataStrc* pQuestData)
{
    QUESTS_DebugOutput(pQuestData->pGame, "Started quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 599);
}

// 0x00592880
void __fastcall ACT1Q4_SendPacket0x5DToClient(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nFlags = 1;
    packet5D.nQuestId = QUEST_A1Q4_CAIN;
    SCMD_SendPacket0x5D(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 613), &packet5D);
}

// 0x005928C0
int __fastcall ACT1Q4_UnitIterate_RemoveCainFromTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!pUnit || pUnit->dwClassId != 0x92)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (MONSTERAI_HasInteractUnit(nType == 1 ? MONSTERS_GetMonInteractInline(pUnit) : 0))
    {
        MONSTERAI_CloseNpcInteractions(pGame, pUnit, ACT1Q4_SendPacket0x5DToClient, 0);
        return 1;
    }

    D2ModeChangeStrc tModeChange;
    MONSTERMODE_GetModeChangeInfo(pUnit, 0, &tModeChange);
    D2GAME_ModeChange(pGame, &tModeChange, 1);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCainRemovedFromTristram = 1;
    }

    return 1;
}

// 0x00592960
static void __stdcall ACT1Q4_SpawnCainInTown(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    D2ActiveRoomStrc* pFreeRoom = pRoom;

    D2DrlgCoordsStrc pRoomCoord;
    DUNGEON_GetRoomCoordinates(pRoom, &pRoomCoord);

    D2CoordStrc pCoord;
    pCoord.nX = nX;
    pCoord.nY = nY;

    int nCounter = 0;
    while (pCoord.nX < pRoomCoord.nSubtileX || pCoord.nY < pRoomCoord.nSubtileY
        || pCoord.nX >= pRoomCoord.nSubtileWidth + pRoomCoord.nSubtileX - 1 || pCoord.nY >= pRoomCoord.nSubtileHeight + pRoomCoord.nSubtileY - 1)
    {
        ++nCounter;
        ++pCoord.nX;
        ++pCoord.nY;
        if (nCounter > 20)
        {
            pCoord.nX = nY;
            break;
        }
    }

    QUESTS_GetFreePosition(pRoom, &pCoord, 2, 0x100, &pFreeRoom, 1, 100);
    if (!pFreeRoom)
    {
        pFreeRoom = pRoom;
        pCoord.nX = nX;
        pCoord.nY = nY;
    }

    D2UnitStrc* pCain = D2GAME_SpawnMonster(pGame, pFreeRoom, pCoord.nX, pCoord.nY, MONSTER_CAIN5, 1, 5, 0);
    if (pCain)
    {
        pCain->dwFlags |= 0x3000000;
        pQuestDataEx->bCainInTownSpawned = 1;
        pQuestDataEx->bCainInTownSpawnPending = 0;
        pQuestDataEx->nCainMonsterInTownGUID = !pCain ? -1 : pCain->dwUnitId;
        return;
    }

    {
        nCounter = 0;
        do
        {
            ++pCoord.nX;
            ++pCoord.nY;
            pFreeRoom = sub_00463740_FindRoomAtPoint(pFreeRoom, pCoord.nX, pCoord.nY);
            if (!pFreeRoom)
            {
                pFreeRoom = pRoom;
                pCoord.nX = nX;
                pCoord.nY = nY;
            }

            QUESTS_GetFreePosition(pFreeRoom, &pCoord, 2, 0x100, &pFreeRoom, 2, 100);
            if (!pFreeRoom)
            {
                pFreeRoom = pRoom;
                pCoord.nX = nX;
                pCoord.nY = nY;
            }

            ++nCounter;
            pCain = D2GAME_SpawnMonster(pGame, pFreeRoom, pCoord.nX, pCoord.nY, MONSTER_CAIN5, 1, 10, 0);
            if (pCain)
            {
                pCain->dwFlags |= 0x3000000;
                pQuestDataEx->bCainInTownSpawned = 1;
                pQuestDataEx->bCainInTownSpawnPending = 0;
                pQuestDataEx->nCainMonsterInTownGUID = !pCain ? -1 : pCain->dwUnitId;
                return;
            }
        }
        while (nCounter < 20);
    }

    pCain = D2GAME_SpawnMonster(pGame, pRoom, nX, nY, MONSTER_CAIN5, 1, 15, 0);
    if (!pCain)
    {
        return;
    }

    pCain->dwFlags |= 0x3000000;
    pQuestDataEx->bCainInTownSpawned = 1;
    pQuestDataEx->bCainInTownSpawnPending = 0;
    pQuestDataEx->nCainMonsterInTownGUID = !pCain ? -1 : pCain->dwUnitId;
}

// 0x00592B10
int __fastcall ACT1Q4_UnitIterate_AddPlayerGUIDs(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDNOW);

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN)->pQuestDataEx;
    QUESTS_AddPlayerGUID(&pQuestDataEx->pQuestGUID, UNITS_GetGUIDOrNone(pUnit));

    return 0;
}

// 0x00592B90
void __fastcall ACT1Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    D2UnitStrc* pScroll = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_SCROLL_BKD);
    D2UnitStrc* pBook = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ITEM_BOOK_BKS);
    if (pScroll)
    {
        ++pQuestDataEx->nScrollsInGame;
    }

    if (pBook)
    {
        ++pQuestDataEx->nScrollsInGame;
    }
}

// 0x00592BD0
static void ACT1Q4_ResetInifussTree(D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    if (pQuestDataEx->bInifussTreeInitialized == 1)
    {
        D2UnitStrc* pInifussTree = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nInifussTreeGUID);
        if (pInifussTree && pInifussTree->dwClassId == 0x1E)
        {
            UNITS_ChangeAnimMode(pInifussTree, 0);
        }

        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q4_UnitIterate_StatusCyclerEx, true);
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x397);
        pQuestDataEx->nInifussTreeObjectMode = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
    }
    else
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q4_UnitIterate_StatusCyclerEx, true);
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x39F);
        pQuestDataEx->nInifussTreeObjectMode = 0;
    }
}

// 0x00592CF0
void __fastcall ACT1Q4_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, UNITS_GetGUIDOrNone(pQuestArg->pPlayer));
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, UNITS_GetGUIDOrNone(pQuestArg->pPlayer));
}

// 0x00592E20
void __fastcall ACT1Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "cairn stone item acquired", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", LINE_ITEM_PICKED);
    if (pQuestData->bNotIntro)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x00592E60
void __fastcall ACT1Q4_Callback06_ResetInifussTree(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bOperatedWithLastCairnStone != 1 && pQuestData->fState <= 5)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x501);
        ACT1Q4_ResetInifussTree(pQuestData);
    }
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00592E90
void __fastcall ACT1Q4_SetMonolithOrder(D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    int nStones[5] = { 17, 18, 19, 20, 21 };
    char szMessage[80];

    for (int i = 0; i < 5; ++i)
    {
        pQuestDataEx->nStoneOrder[i] = 0;
    }
    pQuestDataEx->nStoneCount = 0;

    int nCounter = 0;
    int nMax = 5;
    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pQuestData->pGame);
    while (nCounter < 5)
    {
        const unsigned int nRand = SEED_RollRandomNumber(pSeed) % nMax;
        if (!pQuestDataEx->nStoneOrder[nRand])
        {
            sprintf(szMessage, "stone %d is class %d", nRand, nStones[nCounter]);
            QUESTS_DebugOutput(pQuestData->pGame, szMessage, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 1329);
            pQuestDataEx->nStoneOrder[nRand] = nStones[nCounter];
            ++nCounter;
        }
    }
}

// 0x00592F80
void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bInvisbleObjectInitialized = 1;
    pQuestDataEx->nInvisibleObjectGUID = !pUnit ? -1 : pUnit->dwUnitId;
}


// 0x00592FB0
bool __fastcall ACT1Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED);
    const int bRewardPending = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDPENDING);
    if (nNpcId == MONSTER_AKARA)
    {
        if (pQuest->fState == 4 && !bRewardGranted && !bRewardPending)
        {
            if (ITEMS_FindQuestItem(SUNIT_GetGameFromUnit(pPlayer), pPlayer, ' skb'))
            {
                return true;
            }
        }

        if (pQuest->fState == 1 && !bRewardGranted && !bRewardPending)
        {
            return true;
        }

        if (pQuest->fState == 6 && bPrimaryGoalDone == 1 && !bRewardGranted)
        {
            return true;
        }

        if (bRewardPending)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_CAIN5)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuest->pQuestDataEx;
        if (QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->pQuestGUID, !pPlayer ? -1 : pPlayer->dwUnitId) == 1)
        {
            return true;
        }

        if (!QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pPlayer ? -1 : pPlayer->dwUnitId) && bPrimaryGoalDone)
        {
            return true;
        }
    }

    return false;
}

// 0x005930B0
void __fastcall ACT1Q4_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) == 1)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 0)
    {
        return;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 1);
    QUESTS_UpdatePlayerFlags(pGame, pUnit);
}

// 0x00593290
void __fastcall ACT1Q4_SpawnCainInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestData->bNotIntro || pQuestDataEx->bCompleted == 1)
        {
            return;
        }

        pQuestDataEx->nCainGibbetObjectMode = 3;
        UNITS_ChangeAnimMode(pUnit, 3);

        const int nX = CLIENTS_GetUnitX(pUnit) + 3;
        const int nY = CLIENTS_GetUnitY(pUnit) + 3;

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2UnitStrc* pCain = D2GAME_SpawnMonster(pGame, pRoom, nX, nY, MONSTER_CAIN1, 1, -1, 0);
        if (!pCain)
        {
            D2CoordStrc pCoord;
            pCoord.nX = nX;
            pCoord.nY = nY;

            D2ActiveRoomStrc* pFreeRoom;
            QUESTS_GetFreePosition(pRoom, &pCoord, 2, 0x100, &pFreeRoom, 3, 0x64);
            if (pFreeRoom)
            {
                pCain = D2GAME_SpawnMonster(pGame, pFreeRoom, pCoord.nX, pCoord.nY, MONSTER_CAIN1, 1, -1, 0);
            }
        }

        if (pCain)
        {
            pCain->dwFlags |= 0x3000000;
            D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, pQuestDataEx->nPlayerGUID);
            if (pPlayer)
            {
                SUNIT_AttachSound(pPlayer, 0x30, 0);
            }
        }
        else
        {
            QUESTS_DebugOutput(pGame, "Cain not created, look in town, dammit\n", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x6B6);
            pQuestDataEx->pPlayerInTristram = 0;
            SUNIT_IterateUnitsOfType(pGame, 0, pUnit, ACT1Q4_UnitIterate_FindPlayersInTristram);

            if (pQuestDataEx->pPlayerInTristram && !pQuestDataEx->bPortalFromTristramToTownSpawned)
            {
                if (D2GAME_CreatePortalObject(pGame, pQuestDataEx->pPlayerInTristram, pRoom, nX + 3, nY + 3, 1, 0, 0x3B, 0))
                {
                    pQuestDataEx->bPortalFromTristramToTownSpawned = 1;
                }
            }

            if (!pQuestDataEx->bCainInTownSpawned)
            {
                pQuestDataEx->bCainInTownSpawnPending = 1;
            }

            pQuestDataEx->bCainNotCreated = 1;
        }

        SUNIT_IterateUnitsOfType(pGame, 0, pUnit, ACT1Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pGame, 0, pUnit, ACT1Q4_UnitIterate_SetCompletionFlag);
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 6, 0, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
    }
    else
    {
        D2_ASSERT(pQuestData, 0x68E);
    }
}

// 0x00593130
int __fastcall ACT1Q4_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) == 1)
    {
        return 0;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_TRISTRAM)
    {
        return 0;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 1);
    QUESTS_UpdatePlayerFlags(pGame, pUnit);
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q4_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}

// 0x005931C0
int __fastcall ACT1Q4_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) == 1)
    {
        return 0;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 14);
    QUESTS_SendLogUpdateEx(pUnit, 4, 0);
    return 0;
}

// 0x00593220
int __fastcall ACT1Q4_UnitIterate_FindPlayersInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_TRISTRAM)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return 0;
    }
    ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->pPlayerInTristram = pUnit;
    return 1;
}

// 0x00593260
bool __fastcall ACT1Q4_Timer_RemoveCainFromTristram(D2GameStrc* unused, D2QuestDataStrc* quest)
{
    SUNIT_IterateUnitsOfType(quest->pGame, 1, 0, ACT1Q4_UnitIterate_RemoveCainFromTristram);
    ((D2Act1Quest4ExStrc*)quest->pQuestDataEx)->cainActive = 0;
    return true;
}

// 0x00593480
int __fastcall OBJECTS_OperateFunction10_CainGibbet(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    D2Act1Quest4Strc* pQuestDataEx = 0;
    if (pQuestData)
    {
        pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestData->bNotIntro || pQuestDataEx->bCompleted == 1 || pQuestData->fState >= 6)
        {
            return 0;
        }
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) || QUESTRECORD_GetQuestState(pQuestFlags, 4, 0))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);

    if (pOp->hObject && pOp->hObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        return 0;
    }

    UNITS_ChangeAnimMode(pOp->hObject, 1);
    EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);

    if (pQuestDataEx)
    {
        pQuestDataEx->nCainGibbetObjectMode = 3;
        pQuestDataEx->nPlayerGUID = !pOp->hPlayer ? -1 : pOp->hPlayer->dwUnitId;
    }

    EVENT_SetEvent(pOp->pGame, pOp->hObject, 7, pOp->pGame->dwGameFrame + 17, 0, 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->hObject), 0);

    QUESTRECORD_SetQuestState(pQuestFlags, 4, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 4, 1);

    QUESTS_UpdatePlayerFlags(pOp->pGame, pOp->hPlayer);

    const unsigned short nPartyId = SUNIT_GetPartyId(pOp->hPlayer);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pOp->pGame, nPartyId, ACT1Q4_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x005935E0
void __fastcall OBJECTS_InitFunction06_CairnStone(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    if (pQuestData)
    {
        D2UnitStrc* pObject = pOp->pObject;
        const int nClassId = !pObject ? -1 : pObject->dwClassId;
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (pQuestData->bNotIntro && !pQuestDataEx->bStonesActive)
        {
            if (pQuestDataEx->bActivateCairnStones)
            {
                UNITS_ChangeAnimMode(pObject, 2);
            }
            else if (pQuestDataEx->bCompleted)
            {
                UNITS_ChangeAnimMode(pObject, 2);
            }
            else
            {
                const int const tValue = nClassId - 17;
                if (pQuestDataEx->bCairnStonesActive[tValue] == 1)
                {
                    pQuestDataEx->bCairnStonesActive[tValue] = 0;
                    UNITS_ChangeAnimMode(pOp->pObject, 0);
                }
            }
            return;
        }

        pQuestDataEx->bStonesActive = 0;
        if (!pQuestDataEx->bPortalToTristramOpened && nClassId == 17)
        {
            pQuestDataEx->nCairnStoneAlphaGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
            if (!pQuestDataEx->bOpenPortalTimerActive)
            {
                pQuestDataEx->bOpenPortalTimerActive = 1;
                QUESTS_CreateTimer(pQuestData, (QUESTUPDATE)ACT1Q4_OpenPortalToTristram, 1);
            }
        }

        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        if (pOp->pObject && pOp->pObject->dwAnimMode == OBJMODE_OPENED)
        {
            return;
        }

        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x005936B0
void __fastcall ACT1Q4_UnitIterate_SetEnterAreaFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 4, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) == 1)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == 0)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 4, 4);
    }
}

static inline D2BitBufferStrc* GetPlayerQuestFlags(D2GameStrc* pGame,D2UnitStrc* pPlayer)
{
 return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00593710
int __fastcall OBJECTS_OperateFunction09_Monolith(D2ObjOperateFnStrc* pOp,int nOperate)
{
 D2QuestDataStrc* pQuestInfo=QUESTS_GetQuestData(pOp->pGame,4);
 D2_ASSERT(pQuestInfo,0x761);
 D2Act1Quest4Strc* pEx=(D2Act1Quest4Strc*)pQuestInfo->pQuestDataEx;
 if(!pEx->bMonolithStonesOrdered) {
  pEx->bMonolithStonesOrdered=1;
  ACT1Q4_SetMonolithOrder(pQuestInfo);
 }
 D2BitBufferStrc* pFlags=GetPlayerQuestFlags(pOp->pGame,pOp->hPlayer);
 if(QUESTRECORD_GetQuestState(pFlags,4,0)==1 || QUESTRECORD_GetQuestState(pFlags,4,1)==1) {
  SUNIT_AttachSound(pOp->hPlayer,0x13,pOp->hPlayer);return 0;
 }
 if(!ITEMS_FindQuestItem(pOp->pGame,pOp->hPlayer,0x20646B62)) {
  if((int)(unsigned short)pEx->nCairnStoneInteractions%64==0 && !QUESTRECORD_GetQuestState(pFlags,4,3) && !QUESTRECORD_GetQuestState(pFlags,4,4))
   SUNIT_AttachSound(pOp->hPlayer,0x27,pOp->hPlayer);
  ++pEx->nCairnStoneInteractions;return 0;
 }
 if(!pQuestInfo->bNotIntro || pQuestInfo->fState>=6) return 0;
 D2UnitStrc* pInvisible=0;
 if(pEx->bInvisbleObjectInitialized==1) {
  pInvisible=SUNIT_GetServerUnit(pOp->pGame,2,pEx->nInvisibleObjectGUID);
  if(!pEx->bDecipheredScrollAcquired && pInvisible && pInvisible->dwClassId==61) {
   if(!pQuestInfo->fState && pQuestInfo->bNotIntro==1) {
    ACT1Q4_DebugStartedQuest(pQuestInfo);
    QUESTS_StateDebug(pQuestInfo,1,gszA1Q4SourceFile,0x793);
   }
   if(!ITEMS_FindQuestItem(pOp->pGame,pOp->hPlayer,0x20646B62)) return 0;
  }
 }
 if(pEx->bOperatedWithLastCairnStone==1) return 0;
 if(pQuestInfo->fState!=5) {
  if(!pQuestInfo->fState && pQuestInfo->bNotIntro==1) {
   ACT1Q4_DebugStartedQuest(pQuestInfo);
   QUESTS_StateDebug(pQuestInfo,1,gszA1Q4SourceFile,0x7A5);
  }
  if(!ITEMS_FindQuestItem(pOp->pGame,pOp->hPlayer,0x20646B62)) return 0;
  pQuestInfo->fState=5;
 }
 if((unsigned short)pOp->nObjectIdx!=pEx->nStoneOrder[pEx->nStoneCount]) return 0;
 pEx->nMonolithGUIDs[pEx->nStoneCount]=GetGUID(pOp->hObject);
 ++pEx->nStoneCount;
 if(pOp->hObject && pOp->hObject->dwAnimMode) return 0;
 unsigned short nCount=pEx->nStoneCount;
 switch(nCount) {
 case 5: {
 UNITS_ChangeAnimMode(pOp->hObject,1);
 if(pInvisible) UNITS_ChangeAnimMode(pInvisible,6);
 pEx->bOperatedWithLastCairnStone=1;
 QUESTS_DeleteItem(pOp->pGame,pOp->hPlayer,0x20646B62);
 --pEx->nScrollsInGame;
 D2CoordStrc coords={0,0};
 for(int i=0;i<5;++i) {
  if(pEx->nStoneOrder[i]==21) {
   D2UnitStrc* pStone=SUNIT_GetServerUnit(pOp->pGame,2,pEx->nMonolithGUIDs[i]);
   if(pStone && pStone->dwClassId==21) UNITS_GetCoords(pStone,&coords);
  }
 }
 if(!coords.nX) {
  D2ActiveRoomStrc** ppRooms;
  int nRooms;
  DUNGEON_GetAdjacentRoomsListFromRoom(UNITS_GetRoom(pOp->hObject),&ppRooms,&nRooms);
  for(unsigned int i=0;i<nRooms;++i) {
   D2UnitStrc* pUnit=ppRooms[i]->pUnitFirst;
   while(pUnit) {
    D2UnitStrc* pNext=pUnit->ptRoomNext;
    if(pUnit->dwUnitType==UNIT_OBJECT && pUnit->dwClassId==21) {
     UNITS_GetCoords(pUnit,&coords);i=nRooms;break;
    }
    pUnit=pNext;
   }
  }
 }
 if(coords.nX) {
  const int nPortalX=coords.nX+6;
  const int nPortalY=coords.nY-3;
  D2UnitStrc* pPortal=D2GAME_CreateMissile(pOp->pGame,pOp->hPlayer,0,1,0x120,nPortalX,nPortalY);
  if(pPortal) { D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPortal);DUNGEON_ToggleHasPortalFlag(pRoom,0); }
 }
 if(pQuestInfo->fLastState<4) {
  pQuestInfo->dwFlags&=0xFFFFFF00;
  QUESTS_UnitIterate(pQuestInfo,4,pOp->hPlayer,ACT1Q4_UnitIterate_StatusCyclerEx,true);
  unsigned short nParty=SUNIT_GetPartyId(pOp->hPlayer);
  if(nParty!=0xFFFF) PARTY_IteratePartyMembers(pOp->pGame,nParty,sub_005936B0_UpdateParty,0);
  QUESTRECORD_SetQuestState(pFlags,4,4);
 }
 QUESTS_TriggerFX(pQuestInfo->pGame,1);
 return 0;
 }
 case 0:case 1:case 2:case 3:case 4:
  UNITS_ChangeAnimMode(pOp->hObject,1);
  if(pInvisible) UNITS_ChangeAnimMode(pInvisible,pEx->nStoneCount+1);
  return 0;
 }
 return 0;
}

static inline D2BitBufferStrc* sub_00593AF0_GetPlayerQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00593AF0
int __fastcall OBJECTS_OperateFunction12_InifussTree(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestInfo = QUESTS_GetQuestData(pOp->pGame, 4);
    D2_ASSERT(pQuestInfo, 0x828);

    if (!pQuestInfo->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        return 0;
    }

    if (pQuestInfo->fState >= 6)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags;
    if (pOp->hObject && pOp->hObject->dwAnimMode != OBJMODE_NEUTRAL
        || QUESTRECORD_GetQuestState(pQuestFlags = sub_00593AF0_GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 4, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 4, 1) == 1)
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ' dkb') || ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ' skb'))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestInfo->pQuestDataEx;
    SUNIT_AttachSound(pOp->hPlayer, 45, 0);

    pOp->hObject->dwDropItemCode = ' skb';
    ACT1Q4_DebugStartedQuest(pQuestInfo);
    QUESTS_StateDebug(pQuestInfo, 4, gszA1Q4SourceFile, 0x84B);

    int nItemLevel;
    D2UnitStrc* pItem = D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 0);
    if (pItem)
    {
        pQuestInfo->pCallback[9] = ACT1Q4_Callback09_PlayerDroppedWithQuestItem;
        pQuestInfo->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestInfo, 2, pOp->hPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->unused0x4B = 1;
        const int nScrollGUID = (pItem ? pItem->dwUnitId : -1);
        pQuestDataEx->nDecipheredScrollGUID = nScrollGUID;
        pQuestDataEx->nInifussTreeObjectMode = 1;
        pQuestDataEx->bScrollAcquired = 1;
        ++pQuestDataEx->nScrollsInGame;
        UNITS_ChangeAnimMode(pOp->hObject, 1);
    }

    pQuestDataEx->bInifussTreeInitialized = 1;
    pQuestDataEx->nInifussTreeGUID = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
    return 0;
}

// 0x00592C80
void __fastcall ACT1Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro || pQuestData->fState == 6)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    const int dwItemCode = ITEMS_GetBaseCode(pQuestArg->pTarget);
    if (dwItemCode == 0x20646B62 || dwItemCode == 0x20736B62)
    {
        --pQuestDataEx->nScrollsInGame;
    }

    if (!pQuestDataEx->nScrollsInGame && pQuestData->fState <= 5 && pQuestDataEx->bOperatedWithLastCairnStone != 1 && pQuestDataEx->bInifussTreeInitialized == 1)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x3F7);
        ACT1Q4_ResetInifussTree(pQuestData);
    }
}

// 0x00593CB0
void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return;
    }
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->bMonolithStonesOrdered)
        {
            pQuestDataEx->bMonolithStonesOrdered = 1;
            ACT1Q4_SetMonolithOrder(pQuestData);
        }
        D2GSPacketSrv50 packet;
        packet.nHeader = 0x50;
        packet.nQuestId = 4;
        D2ClientStrc* pClient = UnitGetClient(pUnit, gszAct1Q4SourceFile, 2169);
        int i = 0;
        if (i < 5)
        {
            do
            {
                packet.nParams[i] = pQuestDataEx->nStoneOrder[i] - 17;
                if (packet.nParams[i] >= 5)
                {
                    FOG_DisplayHalt("", sub_00408090(), 2175);
                    exit(-1);
                }
                ++i;
            } while (i < 5);
        }
        D2GAME_SendPacket0x50(pClient, &packet);
    }
}

// 0x00593D70
bool __fastcall ACT1Q4_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_DebugOutput(pQuestData->pGame, "Started quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 599);
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 2193);
        return true;
    }
    if (pQuestData->fState != 6 && pQuestData->bNotIntro)
    {
        return true;
    }
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 2201);
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}

// 0x00593E10
void __fastcall ACT1Q4_SetQuestCompleteBefore(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bQuestCompleteBefore = 1;
    }
}

// 0x00593E30
int __fastcall ACT1Q4_UnitIterate_SetCustom6Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_MOOMOOFARM)
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, 4, 10);
    }
    return 0;
}

void __fastcall D2Game_10034_Return(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990

inline D2BitBufferStrc* QUESTS_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

enum D2C_a1q4_00593E70Constants
{
    QFLAG_CUSTOM6 = 10,
    QUESTSTATEFLAG_A4Q2 = 26,
    QUESTSTATEFLAG_A5Q6 = 40,
};

// 0x00593E70
void __fastcall ACT1Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nItemLevel;
    if (pQuestArg->pPlayer)
    {
        if (QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pQuestArg->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM6))
        {
            return;
        }

        D2GameStrc* pGame = pQuestArg->pGame;
        if (pGame->bExpansion)
        {
            if (!QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))
            {
                return;
            }
        }
        else
        {
            if (!QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A4Q2, QFLAG_REWARDGRANTED))
            {
                return;
            }
        }

        QUESTRECORD_SetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pQuestArg->pGame, pQuestArg->pPlayer), QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM6);
    }

    SUNIT_IterateUnitsOfType(pQuestArg->pGame, UNIT_PLAYER, pQuestArg->pTarget, ACT1Q4_UnitIterate_SetCustom6Flag);
    D2Game_10034_Return(pQuestData, pQuestArg, 64);
    pQuestArg->pTarget->dwDropItemCode = 0x20737076;
    for (int i = 0; i < 8; ++i)
    {
        D2GAME_DropItemAtUnit(pQuestArg->pGame, pQuestArg->pTarget, 0, &nItemLevel, 0, -1, 0);
    }
}

// 0x00593F60
void __fastcall ACT1Q4_SetCainInTownSpawnPending(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCainInTownSpawnPending = 1;
    }
}

// 0x00593F80
int __fastcall ACT1Q4_IsCainNotCreated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        return ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCainNotCreated;
    }
    FOG_DisplayHalt("", sub_00408090(), 0x99D);
    exit(-1);
}

// 0x00593FC0
void __fastcall OBJECTS_InitFunction09_InifussTree(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->bInifussTreeInitialized = 1;
        if (!pQuestData->bNotIntro || pQuestDataEx->bCompleted)
        {
            pQuestDataEx->nInifussTreeObjectMode = 1;
        }
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nInifussTreeObjectMode);
    }
    else
    {
        if (!pOp->pObject || pOp->pObject->dwAnimMode != OBJMODE_OPENED)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
    }
}


// 0x00594020
void __fastcall OBJECTS_InitFunction13_InvisibleObject(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q4_CAIN);
    if (pQuestData)
    {
        QUESTS_CreateChainRecord(pQuestData->pGame, pOp->pObject, QUEST_A1Q4_CAIN);
    }
    else
    {
        if (!pOp->pObject || pOp->pObject->dwAnimMode != OBJMODE_OPENED)
        {
            UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
        }
    }
}

// 0x00594060
void __fastcall ACT1Q4_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nCainGibbetObjectMode);
        pQuestDataEx->bCageModeChanged = 1;
        pQuestDataEx->nCainGibbetGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    }
}

// 0x005940A0
void __fastcall ACT1Q4_RemovePlayerGUID(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN)->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, !pPlayer ? -1 : pPlayer->dwUnitId);
}

// 0x00597310
void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1 || ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCompleted)
    {
        return;
    }

    if (pQuestData->fState >= 6)
    {
        return;
    }

    ACT1Q4_DebugStartedQuest(pQuestData);
    ACT1Q4_UpdateObjects(0, 1, pQuestData);
    QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x9FD);
    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 5, pUnit, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
    QUESTS_SetGlobalState(pGame, 4, 13);
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT1Q4_UnitIterate_AddPlayerGUIDs);
}

struct D2GameStrc;

struct D2ItemDropStrc;

struct D2UnitStrc;

// 0x005940E0
void __fastcall OBJECTS_InitFunction54_CainStartPosition(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 4);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nCainObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    pQuestDataEx->bCainObjectInitialized = 1;
    pQuestDataEx->pCainStartPositionCoords.nX = pOp->nX;
    pQuestDataEx->pCainStartPositionCoords.nY = pOp->nY;

    if (pQuestDataEx->bCainInTownSpawnPending == 1 && !pQuestDataEx->bCainInTownSpawned)
    {
        ACT1Q4_SpawnCainInTown(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY);
    }
}

enum D2C_Q05QuestConstants
{
    QFLAG_CUSTOM7 = 11,
};

// 0x00594140
int __fastcall ACT1Q4_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom;
    if (QUESTS_GetGlobalState(pGame, QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM7)
        || QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM6))
    {
        goto fail;
    }

    if (!((!pGame->bExpansion && QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A4Q2, QFLAG_REWARDGRANTED))
        || (pGame->bExpansion && QUESTRECORD_GetQuestState(QUESTS_GetPlayerQuestFlags_Inline(pGame, pUnit), QUESTSTATEFLAG_A5Q6, QFLAG_REWARDGRANTED))))
    {
        goto fail;
    }

    pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROGUEENCAMPMENT)
    {
fail:
        SUNIT_AttachSound(pUnit, 20, pUnit);
        return 0;
    }

    D2CoordStrc pCoord;
    D2ActiveRoomStrc* pFreeRoom = 0;
    UNITS_GetCoords(pUnit, &pCoord);
    QUESTS_GetFreePosition(pRoom, &pCoord, 3, 0x400, &pFreeRoom, 4, 100);
    if (pFreeRoom && D2GAME_CreatePortalObject(pGame, pUnit, pFreeRoom, pCoord.nX, pCoord.nY, LEVEL_MOOMOOFARM, 0, OBJECT_PERMANENT_TOWN_PORTAL, 0))
    {
        QUESTS_SetGlobalState(pGame, QUESTSTATEFLAG_A1Q4, QFLAG_CUSTOM7);
        return 1;
    }

    SUNIT_AttachSound(pUnit, 20, pUnit);
    return 0;
}

// 0x00594270
int __fastcall ACT1Q4_CreateUberRunPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return 0;
}

// 0x00594280
int __fastcall ACT1Q4_CreateUberFinalePortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return 0;
}


#define QUESTFN_DELAY 25

// 0x00594290
void __fastcall OBJECTS_InitFunction61_CainPortal(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + QUESTFN_DELAY, 0, 0);
}

#define PORTAL_INVOCATIONS_MAX 5

static inline int UNITS_GetAnimModeOrZero(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x005942C0
void __fastcall ACT1Q4_UpdatePortalInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    switch (UNITS_GetAnimModeOrZero(pUnit))
    {
    case OBJMODE_OPERATING:
        UNITS_ChangeAnimMode(pUnit, OBJMODE_OPENED);
        break;

    case OBJMODE_OPENED:
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) == LEVEL_ROGUEENCAMPMENT)
        {
            ++pQuestDataEx->nObjectUpdateInvocations;
            if (pQuestDataEx->nObjectUpdateInvocations > PORTAL_INVOCATIONS_MAX)
            {
                pQuestDataEx->bChangePortalInTownToSpecialMode = 1;
            }

            if (pQuestDataEx->bChangePortalInTownToSpecialMode)
            {
                UNITS_ChangeAnimMode(pUnit, OBJMODE_SPECIAL1);
            }
        }
        else
        {
            if (pQuestDataEx->bChangePortalOutsideTownToSpecialMode)
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

    EVENT_SetEvent(pQuestData->pGame, pUnit, EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + QUESTFN_DELAY, 0, 0);
}

// 0x00594360
int __fastcall ACT1Q4_GetCainPortalInTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (pQuestData && pQuestData->bNotIntro)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bCainPortalInTownSpawned && !pQuestDataEx->bChangePortalInTownToSpecialMode)
        {
            pCoord->nX = pQuestDataEx->pCainPortalInTownCoords.nX;
            pCoord->nY = pQuestDataEx->pCainPortalInTownCoords.nY;
            return 1;
        }
    }

    return 0;
}

#define PORTAL_RETRY_STEP 3

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230

// 0x005943B0
int __fastcall ACT1Q4_SpawnCainPortalOutsideTown(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return 1;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bCainPortalOutsideTownSpawned)
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), pQuestDataEx->pCainPortalOutsideTownCoords.nX, pQuestDataEx->pCainPortalOutsideTownCoords.nY);
    if (!pRoom)
    {
        pQuestDataEx->pCainPortalOutsideTownCoords.nX += PORTAL_RETRY_STEP;
        pQuestDataEx->pCainPortalOutsideTownCoords.nY += PORTAL_RETRY_STEP;
        return 1;
    }

    D2UnitStrc* pCainPortal = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_CAINPORTAL, pQuestDataEx->pCainPortalOutsideTownCoords.nX, pQuestDataEx->pCainPortalOutsideTownCoords.nY, pGame, pRoom, 1, 1, 0);
    if (pCainPortal)
    {
        pQuestDataEx->bCainPortalOutsideTownSpawned = 1;
        pQuestDataEx->nCainPortalOutsideTownGUID = pCainPortal->dwUnitId;
    }

    return 1;
}

// 0x00594450
int __fastcall ACT1Q4_GetCainPortalOutsideTownCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bCainPortalOutsideTownSpawned)
    {
        UNITS_GetCoords(pUnit, pCoord);
    }
    else
    {
        pCoord->nX = pQuestDataEx->pCainPortalOutsideTownCoords.nX;
        pCoord->nY = pQuestDataEx->pCainPortalOutsideTownCoords.nY;
    }

    return 1;
}

// 0x005944B0
int __fastcall ACT1Q4_UpdateCainPortalCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bCainPortalCoordsInitialized)
    {
        return 0;
    }

    UNITS_GetCoords(pUnit, &pQuestDataEx->pCainPortalOutsideTownCoords);
    pQuestDataEx->bCainPortalCoordsInitialized = 1;
    return 1;
}

// 0x005944F0
void __fastcall ACT1Q4_SpawnCainPortalInTown(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (!pQuestData)
    {
        return;
    }

    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bChangePortalOutsideTownToSpecialMode = 1;
    pQuestDataEx->bCainInTownSpawnPending = 1;
    if (pQuestDataEx->bCainObjectInitialized != 1)
    {
        return;
    }

    D2UnitStrc* pCainObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nCainObjectGUID);
    if (!pCainObject)
    {
        return;
    }

    D2ObjInitFnStrc tObjInit;
    tObjInit.pObject = pCainObject;
    tObjInit.pGame = pGame;
    tObjInit.pRoom = UNITS_GetRoom(pCainObject);
    tObjInit.nX = CLIENTS_GetUnitX(pCainObject);
    tObjInit.nY = CLIENTS_GetUnitY(pCainObject);
    OBJECTS_InitFunction54_CainStartPosition(&tObjInit);

    if (pQuestDataEx->bCainInTownSpawned != 1)
    {
        return;
    }

    D2UnitStrc* pCain = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nCainMonsterInTownGUID);
    if (!pCain)
    {
        return;
    }

    D2CoordStrc tCoord;
    UNITS_GetCoords(pCain, &tCoord);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pCain), tCoord.nX, tCoord.nY);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_CAINPORTAL, tCoord.nX, tCoord.nY, pGame, pRoom, 1, 1, 0);
    if (pPortal)
    {
        pQuestDataEx->bCainPortalInTownSpawned = 1;
        pQuestDataEx->nCainPortalInTownGUID = pPortal->dwUnitId;
    }
}

// 0x005945F0
void __fastcall ACT1Q4_OnCainInTownActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bChangePortalInTownToSpecialMode = 1;
    }
}

// 0x00594610
int __fastcall ACT1Q4_IsCainInTristramDeactivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (!pQuestData)
    {
        return 0;
    }

    return ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->bCainInTristramDeactivated != 0;
}

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500

// 0x00594630
void __fastcall ACT1Q4_DropWirtsBodyGold(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bWirtsBodyInitialized)
    {
        pQuestDataEx->bWirtsBodyInitialized = 1;
        pQuestDataEx->nGoldPilesToDropFromWirtsBody = OBJECTS_RollRandomNumber(QUESTS_GetGlobalSeed(pQuestData->pGame), 10, 20);
        pUnit->dwDropItemCode = ' dlg';
    }

    if (pQuestDataEx->nGoldPilesToDropFromWirtsBody)
    {
        int nItemLevel = 0;
        if (D2GAME_DropItemAtUnit(pQuestData->pGame, pUnit, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            --pQuestDataEx->nGoldPilesToDropFromWirtsBody;
            if (pQuestDataEx->nGoldPilesToDropFromWirtsBody > 0)
            {
                EVENT_SetEvent(pQuestData->pGame, pUnit, EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + 10, 0, 0);
            }
        }
    }
}

// 0x005946D0
void __fastcall ACT1Q4_SetA1Q4Unk0xB0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q4_CAIN);
    if (pQuestData)
    {
        ((D2Act1Quest4Strc*)pQuestData->pQuestDataEx)->unused0xB0 = nValue;
    }
}

// 0x00596CA0
static void __stdcall ACT1Q4_UpdateObjects(char bUseRemovalTimer, char bMoveCainToTown, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pCage = 0;
    if (pQuestDataEx->bCageModeChanged == 1)
    {
        pCage = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nCainGibbetGUID);
    }

    if (pCage && pCage->dwClassId == 0x1A)
    {
        int nAnimMode = 0;
        if (pCage)
        {
            nAnimMode = pCage->dwAnimMode;
        }

        if (nAnimMode != 3)
        {
            UNITS_ChangeAnimMode(pCage, 3);
            pQuestDataEx->nCainGibbetObjectMode = 3;
        }
    }
    else
    {
        pQuestDataEx->nCainGibbetObjectMode = 3;
    }

    if (pQuestDataEx->bInifussTreeInitialized == 1)
    {
        D2UnitStrc* pInifussTree = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nInifussTreeGUID);
        if (pInifussTree)
        {
            UNITS_ChangeAnimMode(pInifussTree, 1);
        }
    }

    if (bUseRemovalTimer)
    {
        if (!pQuestDataEx->bTimerActive)
        {
            pQuestDataEx->bTimerActive = 1;
            QUESTS_CreateTimer(pQuestData, ACT1Q4_Timer_RemoveCainFromTristram, 1);
        }
    }
    else if (bMoveCainToTown)
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 1, 0, ACT1Q4_UnitIterate_RemoveCainFromTristram);
    }
    else
    {
        pQuestDataEx->bCompleted = 1;
        return;
    }

    if (!bMoveCainToTown)
    {
        pQuestDataEx->bCompleted = 1;
        return;
    }

    if (!pQuestDataEx->bCainRemovedFromTristram)
    {
        SUNITINACTIVE_DeleteSingleListNode(pQuestData->pGame, 1, 0x92, 0);
    }

    pQuestDataEx->bCompleted = 1;
    if (!pQuestDataEx->bCainInTownSpawned)
    {
        pQuestDataEx->bCainInTownSpawnPending = 1;
    }
}

// 0x00596D70
void __fastcall ACT1Q4_StartCainRemoval(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
    if (pQuestData)
    {
        D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (!pQuestDataEx->bCainRemovalStarted)
        {
            ACT1Q4_UpdateObjects(1, 0, pQuestData);
            QUESTS_StateDebug(pQuestData, 6, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x351);
            pQuestDataEx->bCainRemovalStarted = 1;
        }
    }
    else
    {
        D2_ASSERT(pQuestData, 0x357);
    }
}

// 0x00596DE0
void __fastcall ACT1Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
    int nOldLevel = pQuestArg->nOldLevel;
    const int nNewLevel = pQuestArg->nNewLevel;

    if (nNewLevel == 0x26 && !pQuestDataEx->bCainInTownSpawned && !pQuestDataEx->bCompleted && pQuestData->fState >= 6)
    {
        ACT1Q4_DebugStartedQuest(pQuestData);
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x422);
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 4, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 0);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_UpdateQuestStateFlags);
    }

    if (*(const int*)&nOldLevel == 1)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

        QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = GetQuestFlags(pGame, pQuestArg->pPlayer);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            return;
        }

        if (pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x436);
        }
    }

    if (nNewLevel == 1)
    {
        D2Act1Quest4Strc* pQuestDataEx2 = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx2->bCainObjectInitialized)
        {
            D2UnitStrc* pCain = SUNIT_GetServerUnit(pQuestArg->pGame, 2, pQuestDataEx2->nCainObjectGUID);
            if (pCain && pQuestDataEx2->bCainInTownSpawnPending == 1 && !pQuestDataEx2->bCainInTownSpawned)
            {
                ACT1Q4_SpawnCainInTown(pQuestArg->pGame, UNITS_GetRoom(pCain), CLIENTS_GetUnitX(pCain), CLIENTS_GetUnitY(pCain));
            }
        }
    }
    else if (nNewLevel == 0x28)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = GetQuestFlags(pGame, pQuestArg->pPlayer);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            return;
        }

        if (!pQuestDataEx->bCompleted && pQuestData->fState < 6)
        {
            ACT1Q4_DebugStartedQuest(pQuestData);
            ACT1Q4_UpdateObjects(0, 1, pQuestData);
            QUESTS_StateDebug(pQuestData, 7, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q4.cpp", 0x458);
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 5, pQuestArg->pPlayer, ACT1Q4_UnitIterate_StatusCyclerEx, 1);
            QUESTS_SetGlobalState(pQuestData->pGame, 4, 13);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q4_UnitIterate_AddPlayerGUIDs);
            pQuestDataEx->nInifussTreeObjectMode = 1;
        }
    }
}

enum D2C_P08QuestConstants
{
    QFLAG_STARTED = 2,
    QFLAG_LEAVETOWN = 3,
    QFLAG_ENTERAREA = 4,
};

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

// 0x00597030
void __fastcall ACT1Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act1Quest4Strc* pQuestDataEx = (D2Act1Quest4Strc*)pQuestData->pQuestDataEx;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) == 1)
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A1Q4_CAIN);
        if (pQuest)
        {
            ((D2Act1Quest4Strc*)pQuest->pQuestDataEx)->bCainInTownSpawnPending = 1;
        }

        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A1Q4, QFLAG_PRIMARYGOALDONE);
        pQuestDataEx->nCainGibbetObjectMode = OBJMODE_SPECIAL1;
        pQuestDataEx->bStonesActive = 1;
        pQuestDataEx->bActivateCairnStones = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_COMPLETEDBEFORE) == 1)
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A1Q4_CAIN);
        if (pQuest)
        {
            ((D2Act1Quest4Strc*)pQuest->pQuestDataEx)->bCainInTownSpawnPending = 1;
        }

        pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A1Q4_CAIN);
        if (pQuest)
        {
            ((D2Act1Quest4Strc*)pQuest->pQuestDataEx)->bQuestCompleteBefore = 1;
        }

        pQuestDataEx->nCainGibbetObjectMode = OBJMODE_SPECIAL1;
        pQuestDataEx->bStonesActive = 1;
        pQuestDataEx->bActivateCairnStones = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 5;
        pQuestDataEx->bStonesActive = 1;
        pQuestDataEx->bDecipheredScrollAcquired = 1;
        pQuestDataEx->bActivateCairnStones = 1;
        pQuestDataEx->bScrollAcquired = 1;
        pQuestDataEx->nInifussTreeObjectMode = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q4, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }

    D2UnitStrc* pDecipheredScroll = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' dkb');
    D2UnitStrc* pBarkScroll = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' skb');
    if (pDecipheredScroll)
    {
        ++pQuestDataEx->nScrollsInGame;
    }

    if (pBarkScroll)
    {
        ++pQuestDataEx->nScrollsInGame;
    }

    if (pDecipheredScroll)
    {
        pQuestData->fState = 5;
        pQuestData->fLastState = 3;
        pQuestDataEx->bDecipheredScrollAcquired = 1;
        pQuestDataEx->bScrollAcquired = 1;
        pQuestDataEx->nInifussTreeObjectMode = 1;
    }
    else if (pBarkScroll)
    {
        pQuestDataEx->bScrollAcquired = 1;
        pQuestData->fState = 4;
        pQuestData->fLastState = 2;
        pQuestDataEx->nInifussTreeObjectMode = 1;
    }
}

