#include "D2GameEvents.h"
#include "D2MonsterIds.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2Path.h"
#include "D2GameObjs.h"
#include "D2Packets.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define QUEST_A1Q4_CAIN 4

#define ACT_II 1

#define QUEST_A3Q7_DARKWANDERER 28

#define QUEST_A5Q5_ANCIENTS 35

#define ITEMQUAL_NORMAL 2


#define QUESTSTATEFLAG_A5Q6 40

#define QUESTSTATEFLAG_A4Q1 25

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM1 5

#define QFLAG_CUSTOM2 6

#define QFLAG_CUSTOM3 7

#define QFLAG_CUSTOM4 8

#define QFLAG_CUSTOM6 10

#define MONSTER_ANCIENTSTATUE1 539

#define MONSTER_ANCIENTSTATUE3 541

struct D2PoolSystemStrc;
union D2SeedStrc;

struct D2ObjInitFnStrc;


struct D2QuestGUIDStrc;

struct D2Act1Quest4Strc;

struct D2Act3Quest7Strc;

struct D2Act4Quest3Strc;

struct D2Act5Quest5Strc;

struct D2Act5Quest6Strc;

struct D2Act2Quest2Strc;

struct D2Act2Quest3Strc;

struct D2PlayerDataStrc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500


typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A170


enum
{
    QUEST_A2Q3_TAINTEDSUN = 10,
    QUESTSTATEFLAG_A2Q3 = 11,
};

extern char gpAct2Q3NpcMessages[]; // 0x0073A188

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300


void __fastcall ACT2Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00599FB0

bool __fastcall ACT2Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059A1C0

void __fastcall ACT2Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059A270

bool __fastcall ACT2Q3_SeqCallback(D2QuestDataStrc* pQuestData); // 0x0059A480

void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059A5D0

void __fastcall ACT2Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059EBE0

void __fastcall ACT2Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059EE00

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310


int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599F50

int __fastcall ACT2Q3_UnitIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A100

int __fastcall ACT2Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A4F0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define ITEMQUAL_MAGIC 4

#define ITEMQUAL_UNIQUE 7

struct D2Act2Quest4Strc;

struct D2Act2Quest5Strc;

struct D2Act2Quest6Strc;

struct D2ObjOperateFnStrc;

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

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09



D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __fastcall ACT2Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00599FE0

int __fastcall ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A0B0

int __fastcall ACT2Q3_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A680

bool __fastcall ACT2Q3_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059A700

int __fastcall ACT2Q3_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A730

int __fastcall ACT2Q3_UnitIterate_DetermineViperAmuletDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059A770


#define PREFIX

#define TERMINAL_STATE 5

#define ASSERT_LINE 677

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

enum
{
    QUESTSTATEFLAG_A2Q2 = 10,
    QFLAG_STARTED = 2,
    QFLAG_LEAVETOWN = 3,
    QFLAG_COMPLETEDBEFORE = 15,
    A2Q3_SOUND_COMPLETE = 52,
    A2Q3_STATE_TIMER = 4,
    A2Q3_ITERATE_TIMER = 3,
};

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

extern "C" const char gszA2Q3SourceFile[];                                                                 // 0x006E1FB0


static bool ACT2Q3_ApplyDarkness(D2QuestDataStrc* pQuestData);

static void __stdcall ACT2Q3_StartDarknessForPlayer(D2UnitStrc* pPlayer, D2QuestDataStrc* pQuestData);


static inline int GetUnitId(D2UnitStrc* unit) { return !unit ? -1 : unit->dwUnitId; }


static inline void ACT2Q3_EndTaintedSun(D2QuestDataStrc* pQuestData, D2GameStrc* pGame);


static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00599C10
int __fastcall OBJECTS_OperateFunction40_HoradricScrollChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    int nResult = 0;
    if (QUESTS_SetObjectSelection(pOp))
    {
        pOp->hObject->dwDropItemCode = ' 1rt';

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q2_HORADRICSTAFF);
        if (pQuestData)
        {
            D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nItemDropCount = 0;
            SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT2Q2_UnitIterate_DetermineHoradricScrollDropCount);

            for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
            {
                int nItemLevel;
                D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, ITEMQUAL_UNIQUE, &nItemLevel, 0, -1, 1);
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nCounter; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
        }
    }
    return nResult;
}

// 0x00599CF0
int __fastcall OBJECTS_OperateFunction41_StaffOfKingsChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    int nResult = 0;
    if (QUESTS_SetObjectSelection(pOp))
    {
        pOp->hObject->dwDropItemCode = ' fsm';

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q2_HORADRICSTAFF);
        if (pQuestData)
        {
            D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nItemDropCount = 0;
            SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT2Q2_UnitIterate_DetermineStaffDropCount);

            for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
            {
                int nItemLevel;
                D2UnitStrc* pItem = D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, ITEMQUAL_UNIQUE, &nItemLevel, 0, -1, 1);
                if (pItem)
                {
                    ITEMS_SetItemFlag(pItem, 0x10, 1);
                    ++pQuestDataEx->nBaseStaffs;
                    pQuestDataEx->bHoradricScrollDropped = 1;
                }
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nCounter; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
        }
    }
    return nResult;
}

// 0x00599DF0
int __fastcall OBJECTS_OperateFunction39_HoradricCubeChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    int nResult = 0;
    if (QUESTS_SetObjectSelection(pOp))
    {
        pOp->hObject->dwDropItemCode = ' xob';

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q2_HORADRICSTAFF);
        if (pQuestData)
        {
            D2Act2Quest2Strc* pQuestDataEx = (D2Act2Quest2Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nItemDropCount = 0;
            SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT2Q2_UnitIterate_DetermineCubeDropCount);

            for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
            {
                int nItemLevel;
                if (D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
                {
                    ++pQuestDataEx->nHoradricCubes;
                    pQuestDataEx->bCubeDropped = 1;
                }
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nCounter; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
        }
    }
    return nResult;
}

// 0x00599EE0
void __fastcall OBJECTS_InitFunction31_Unused(D2ObjInitFnStrc* pOp)
{
}

// 0x00599EF0
void __fastcall OBJECTS_InitFunction33_Unused(D2ObjInitFnStrc* pOp)
{
}

// 0x00599F00
void __fastcall OBJECTS_InitFunction32_Unused(D2ObjInitFnStrc* pOp)
{
}

// 0x00599F10
void __fastcall ACT2Q3_GetHoradricCubeInfo(D2GameStrc* pGame, int* pnValue, unsigned char* pbFlag)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 9);
    if (pQuestData)
    {
        *pnValue = ((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->nHoradricCubes;
        *pbFlag = ((D2Act2Quest2Strc*)pQuestData->pQuestDataEx)->bCubeDropped;
    }
    *pnValue = 0;
    *pbFlag = 1;
}

// 0x00599F50
int __fastcall ACT2Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A2Q3_TAINTEDSUN);
    }

    return 0;
}

// 0x00599FB0
void __fastcall ACT2Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* quest, D2QuestArgStrc* argument)
{
    QUESTS_RemovePlayerGUID(quest, argument);
    D2UnitStrc* player = argument->pPlayer;
    D2Act2Quest3Strc* data = (D2Act2Quest3Strc*)quest->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&data->tPlayerGUIDs, GetUnitId(player));
}

// 0x00599FE0
int __fastcall ACT2Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 14);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A2Q3_TAINTEDSUN, 0);
    }

    return 0;
}

// 0x0059A040
void __fastcall ACT2Q3_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING) == 1)
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

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING);
}

// 0x0059A0B0
int __fastcall ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q3_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0059A100
int __fastcall ACT2Q3_UnitIterate_UpdateClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 322);
    if (CLIENTS_GetActNo(pClient) == ACT_II)
    {
        D2GSPacketSrv53 packet53;
        packet53.nHeader = 0x53;
        packet53.nCycleIndex = 5;
        packet53.nTicks = 0;
        packet53.nEclipse = 1;
        D2GAME_SendPacket0x53(pClient, &packet53);

        D2GSPacketSrv5D packet5D;
        memset(&packet5D, 0, sizeof(packet5D));
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = QUEST_A2Q3_TAINTEDSUN;
        packet5D.nFlags = 16;
        SCMD_SendPacket0x5D(pClient, &packet5D);
    }

    return 0;
}

// 0x0059A170
int __fastcall ACT2Q3_UnitIterate_SendPacket0x53ToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 357);
    if (CLIENTS_GetActNo(pClient) == ACT_II)
    {
        D2GSPacketSrv53 packet53;
        packet53.nHeader = 0x53;
        packet53.nCycleIndex = 2;
        packet53.nTicks = 0;
        packet53.nEclipse = 0;
        D2GAME_SendPacket0x53(pClient, &packet53);
    }

    return 0;
}

// 0x0059A1C0
bool __fastcall ACT2Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) == 1)
    {
        return false;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) == 1)
    {
        if (nNpcId == MONSTER_ATMA || nNpcId == MONSTER_WARRIV2 || nNpcId == MONSTER_GREIZ || nNpcId == MONSTER_ELZIX
            || nNpcId == MONSTER_DROGNAN || nNpcId == MONSTER_LYSANDER || nNpcId == MONSTER_CAIN2 || nNpcId == MONSTER_MESHIF1
            || nNpcId == MONSTER_GEGLASH || nNpcId == MONSTER_JERHYN)
        {
            return true;
        }
    }

    if (nNpcId == MONSTER_DROGNAN && pQuest->fState == 1)
    {
        return true;
    }

    return false;
}

#define QFLAG_COMPLETEDNOW 14


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


extern int gnAct2Q3NpcMessageIndices[]; // 0x0073A620

// 0x0059A270
void __fastcall ACT2Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_COMPLETEDNOW))
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId)) == 1)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        else if (pQuestData->fState && pQuestData->bNotIntro && QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) != 1 && pQuestData->fState < 4)
        {
            const int nIndex = gnAct2Q3NpcMessageIndices[pQuestData->fState];
            if (nIndex != -1 && (unsigned int)nIndex < 6)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
            }
        }
    }
}

struct D2GameStrc;

struct D2ItemDropStrc;

struct D2QuestDataStrc;

struct D2UnitStrc;

// 0x0059A350
static bool ACT2Q3_ApplyDarkness(D2QuestDataStrc* pQuestData)
{
    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
    if (!pQuestData->fState)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x211);
    }

    D2GameStrc* pGame = pQuestData->pGame;
    if (pGame->pAct[1])
    {
        ENVIRONMENT_TaintedSunBegin(pGame->pAct[1]);
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_UpdateClient);
        return true;
    }

    ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bDarknessPending = 1;
    return false;
}

// 0x0059A3C0
static inline void ACT2Q3_EndTaintedSun(D2QuestDataStrc* pQuestData, D2GameStrc* pGame)
{
    if (pGame->pAct[1])
    {
        ((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bDarknessApplied = 0;
        ENVIRONMENT_TaintedSunEnd(pGame->pAct[1]);
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q3_UnitIterate_SendPacket0x53ToClient);
    }
}

// 0x0059A3F0
void __fastcall ACT2Q3_InitAltarObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bAltarInitialized = 1;
    pQuestDataEx->nAltarGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (pQuestData->bNotIntro == 1)
    {
        if (pQuestData->fState <= 1)
        {
            if (!ACT2Q3_ApplyDarkness(pQuestData))
            {
                pQuestDataEx->bDarknessPending = 1;
            }
            else
            {
                pQuestDataEx->bDarknessApplied = 1;
            }

            pQuestData->fState = 3;
            pQuestData->nStatusFlags = 0;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
        }
    }

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nAltarMode);
}

// 0x0059A480
bool __fastcall ACT2Q3_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != TERMINAL_STATE && pQuestData->bNotIntro)
        return true;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
        {
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), ASSERT_LINE);
            exit(-1);
        }
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}

// 0x0059A4F0
int __fastcall ACT2Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q3_TAINTEDSUN);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState >= 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_STARTED);
    }

    if (pQuestData->fState == QFLAG_STARTED)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_LEAVETOWN);
    }
    else if (pQuestData->fState == QFLAG_LEAVETOWN)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_ENTERAREA);
    }

    return 0;
}

// 0x0059A570
static void __stdcall ACT2Q3_StartDarknessForPlayer(D2UnitStrc* pPlayer, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!ACT2Q3_ApplyDarkness(pQuestData))
    {
        pQuestDataEx->bDarknessPending = 1;
        D2GSPacketSrv5D packet5D = {};
        packet5D.nHeader = 0x5D;
        packet5D.nQuestId = 10;
        packet5D.nFlags = 1;
        D2ClientStrc* pClient = UnitGetClient(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x2E0);
        SCMD_SendPacket0x5D(pClient, &packet5D);
    }
    else
    {
        pQuestDataEx->bDarknessApplied = 1;
    }
}

// 0x0059A5D0
void __fastcall ACT2Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(!pQuestArg ? 0 : pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 11, 13);
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 2) != 1)
    {
        return;
    }

    ACT2Q3_StartDarknessForPlayer(pQuestArg->pPlayer, pQuestData);

    if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 4))
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 11, 3))
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 2;
    }
    else
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 1;
    }
}

// 0x0059A680
int __fastcall ACT2Q3_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q3_TAINTEDSUN);

    if (pRoom && pQuestData)
    {
        D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->nAltarLevelId == DUNGEON_GetLevelIdFromRoom(pRoom)
            && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDGRANTED) != 1
            && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_COMPLETEDBEFORE) != 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_REWARDPENDING);
        }
    }

    return 0;
}

// 0x0059A700
bool __fastcall ACT2Q3_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;

    if (pQuestData->fState == A2Q3_STATE_TIMER)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, A2Q3_ITERATE_TIMER, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 1);
    }
    pQuestDataEx->bTimerActive = 0;

    return 1;
}

// 0x0059A730
int __fastcall ACT2Q3_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, QFLAG_PRIMARYGOALDONE))
    {
        SUNIT_AttachSound(pUnit, A2Q3_SOUND_COMPLETE, pUnit);
    }

    return 0;
}

// 0x0059A770
int __fastcall ACT2Q3_UnitIterate_DetermineViperAmuletDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' piv') || ITEMS_FindQuestItem(pGame, pUnit, ' tsh'))
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q3_TAINTEDSUN);
    if (pQuestData)
    {
        ++((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->nViperAmuletDropCount;
    }

    return 0;
}

static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0059EEA0
void __fastcall ACT2Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT2Q3_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT2Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[10] = ACT2Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[13] = ACT2Q3_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct2Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 803, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q3;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT2Q3_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT2Q3_SeqCallback;
    pQuestData->nSeqId = QUESTSTATEFLAG_A2Q3;
    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest3Strc));
    pQuestDataEx->nAltarMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x0059A7E0
int __fastcall OBJECTS_OperateFunction24_TaintedSunAltar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 10);
    if (!pQuestData)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
    if ((QUESTRECORD_GetQuestState(pQuestFlags, 11, 1) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 11, 0) == 1)
        && (QUESTRECORD_GetQuestState(pQuestFlags, 10, 0) == 1 || ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ' piv') || ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, ' tsh')))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    if (pOp->hObject && pOp->hObject->dwAnimMode)
    {
        return 0;
    }

    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        pQuestDataEx->nAltarMode = 2;
        pQuestDataEx->nViperAmuletDropCount = 0;
        pQuestDataEx->bAltarDestroyed = 1;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT2Q3_UnitIterate_DetermineViperAmuletDropCount);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
        int nItemLevel = DUNGEON_GetLevelIdFromRoom(pRoom);
        int nAmuletsDropped = 0;
        pOp->hObject->dwDropItemCode = ' piv';
        for (int i = 0; i < pQuestDataEx->nViperAmuletDropCount; ++i)
        {
            D2UnitStrc* pItem = D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, 7, &nItemLevel, 0, -1, 0);
            if (pItem)
            {
                ITEMS_SetItemFlag(pItem, 16, 1);
                ++nAmuletsDropped;
            }
        }

        OBJMODE_DropFromChestTCWithQuality(pOp, 4);
        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
        const int nGoldDropCount = SEED_RollRandomNumber(pSeed) % 5 + 5;
        for (int i = 0; i < nGoldDropCount; ++i)
        {
            OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
        }

        D2QuestDataStrc* pQuestDataStaff = QUESTS_GetQuestData(pQuestData->pGame, 9);
        if (pQuestDataStaff)
        {
            ((D2Act2Quest2Strc*)pQuestDataStaff->pQuestDataEx)->nAmulets += nAmuletsDropped;
        }
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
    pQuestDataEx->pRoom = pRoom;
    pQuestDataEx->nAltarLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    UNITS_ChangeAnimMode(pOp->hObject, 1);
    pQuestDataEx->nAltarMode = 2;
    pQuestDataEx->bAltarInitialized = 1;
    pQuestDataEx->nAltarGUID = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
    pQuestDataEx->bAltarDestroyed = 1;

    if (pQuestData->bNotIntro)
    {
        ACT2Q3_EndTaintedSun(pQuestData, pQuestData->pGame);

        QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 991);
        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 992);
        QUESTS_TriggerFX(pQuestData->pGame, 6);
    }

    pQuestDataEx->nViperAmuletDropCount = 0;
    SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT2Q3_UnitIterate_DetermineViperAmuletDropCount);

    if (pQuestData->bNotIntro)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 11, 0))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 11, 1);
            QUESTRECORD_SetQuestState(pQuestFlags, 11, 13);
            QUESTRECORD_ClearQuestState(pQuestFlags, 11, 14);
        }

        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hObject, ACT2Q3_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hObject, ACT2Q3_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hObject, ACT2Q3_UnitIterate_AttachCompletionSound);
        QUESTS_SetGlobalState(pOp->pGame, pQuestData->eFilter, 13);
    }

    int nItemLevel = DUNGEON_GetLevelIdFromRoom(pQuestDataEx->pRoom);
    int nAmuletsDropped = 0;
    pOp->hObject->dwDropItemCode = ' piv';
    for (int i = 0; i < pQuestDataEx->nViperAmuletDropCount; ++i)
    {
        D2UnitStrc* pItem = D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, 7, &nItemLevel, 0, -1, 0);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, 16, 1);
            ++nAmuletsDropped;
        }
    }

    D2QuestDataStrc* pQuestDataStaff = QUESTS_GetQuestData(pQuestData->pGame, 9);
    if (pQuestDataStaff)
    {
        ((D2Act2Quest2Strc*)pQuestDataStaff->pQuestDataEx)->nAmulets += nAmuletsDropped;
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, 4);
    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nGoldDropCount = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nGoldDropCount; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_SetCompletionFlag);
    QUESTS_CreateTimer(pQuestData, ACT2Q3_Timer_StatusCycler, 10);
    return 0;
}

// 0x0059AC20
bool __fastcall ACT2Q3_IsDoneOrInactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 10);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return true;
    }
    return pQuestData->fState >= 4 ? true : false;
}

// 0x0059AC40
void __fastcall ACT2Q3_ApplyPendingDarkness(D2GameStrc* pGame, unsigned char nActNo)
{
    if (nActNo != 1)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 10);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDarknessPending != 1)
    {
        return;
    }

    ENVIRONMENT_TaintedSunBegin(pGame->pAct[1]);
    pQuestDataEx->bDarknessPending = 0;
    pQuestDataEx->bDarknessApplied = 1;
}


// 0x0059AC80
bool __fastcall ACT2Q3_IsAltarDestroyed(D2QuestDataStrc* pQuest)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, 10);
    if (pQuestData)
    {
        return *(bool*)&((D2Act2Quest3Strc*)pQuestData->pQuestDataEx)->bAltarDestroyed;
    }

    return false;
}

// 0x0059EBE0
void __fastcall ACT2Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int bScrollRead = 0;
    switch (pQuestArg->nMessageIndex)
    {
    case 348:
        if (pQuestData->bNotIntro && pQuestArg->nOldLevel == 0xB1)
        {
            if (pQuestData->fLastState == 1)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 0);
            }

            if (pQuestData->fState == 1)
            {
                QUESTS_StateDebug(pQuestData, 2, gszA2Q3SourceFile, 0xCD);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
            }
        }
        break;

    case 362:
    case 363:
    case 364:
    case 365:
    case 366:
    case 367:
    case 368:
    case 369:
    case 370:
    case 371:
    case 372:
        bScrollRead = 1;
        break;
    }

    if (bScrollRead)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (pQuestData->fState != 5 && pQuestData->bNotIntro == 1 && QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13))
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT2Q3_UnitIterate_StatusCyclerEx, 0);
            QUESTS_StateDebug(pQuestData, 5, gszA2Q3SourceFile, 0xDC);
            if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
            {
                FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xDD);
                exit(-1);
            }
            pQuestData->pfSeqFilter(pQuestData);
        }

        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q3, 1);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            if (!pQuestData->bNotIntro)
            {
                QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q3, 13);
            }
        }
    }
}

// 0x0059ED80
bool __fastcall ACT2Q3_DarkenEnvironment(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bDarkenTimerCreated = 0;
    if (pQuestDataEx->bDarknessApplied)
    {
        return true;
    }

    if (!ACT2Q3_ApplyDarkness(pQuestData))
    {
        pQuestDataEx->bDarknessPending = 1;
        return true;
    }

    pQuestDataEx->bDarknessApplied = 1;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
    return true;
}

// 0x0059EDC0
static void ACT2Q3_CreateDarkenTimer(D2QuestDataStrc* pQuestData)
{
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->fState && !pQuestDataEx->bDarkenTimerCreated)
    {
        D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pQuestData->pGame);
        QUESTS_CreateTimer(pQuestData, ACT2Q3_DarkenEnvironment, OBJECTS_RollRandomNumber(pSeed, 15, 17));
        pQuestDataEx->bDarkenTimerCreated = 1;
    }
}

// 0x0059EE00
void __fastcall ACT2Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;
    D2Act2Quest3Strc* pQuestDataEx = (D2Act2Quest3Strc*)pQuestData->pQuestDataEx;

    if ((nNewLevel == 0x2C || nNewLevel == 0x2D) && !pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        ACT2Q3_CreateDarkenTimer(pQuestData);
    }

    if (nNewLevel == 0x28 && pQuestDataEx->bDarknessPending == 1 && ACT2Q3_ApplyDarkness(pQuestData))
    {
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestDataEx->bDarknessPending = 0;
    }

    if (nOldLevel == 0x28)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q3.cpp", 0x270);
        }
    }
}
