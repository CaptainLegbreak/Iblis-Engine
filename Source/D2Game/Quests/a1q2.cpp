#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2QuestData.h"

#define DIAG_LINE_NUMBER 447

#define STATE_LINE 448

#define QUEST_STATE 4

#define TIMER_TICKS 15

#define GLOBAL_STATE 13

struct D2GameStrc;

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState);                         // 0x00544720

extern "C" const char gszA1Q2SourceFile[];                                                                  // 0x006E1B98

bool __fastcall ACT1Q2_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);  // 0x00590BF0

int __fastcall ACT1Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590DD0

int __fastcall ACT1Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590E30

int __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590E70

int __fastcall ACT1Q2_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);  // 0x00590C40

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_COMPLETEDBEFORE 15

#define QUESTSTATEFLAG_A1Q2 2

#define A1Q2_INITNO 4

#define A1Q2_SEQID 4

#define LINE_SEQ_DEBUG 0x230

#define LINE_SEQ_ASSERT 0x23B

#define LINE_INIT_ALLOC 0x27F

struct D2NPCMessageTableStrc;

struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2Act1Quest2Strc;

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate); // 0x00544300

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate); // 0x005537D0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

int __fastcall ACT1Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00590830

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef int(__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern char gpAct1Q2NpcMessages[]; // 0x00736CE8

void __fastcall ACT1Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590980

void __fastcall ACT1Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590B10

void __fastcall ACT1Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590920

void __fastcall ACT1Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590C10

void __fastcall ACT1Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590EC0

void __fastcall ACT1Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00590FA0

bool __fastcall ACT1Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00591080

bool __fastcall ACT1Q2_SeqCallback(D2QuestDataStrc* pQuestData);

void __fastcall ACT1Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

enum D2C_F33QuestConstants
{
    ACT_V = 4,
    QUEST_A1Q2_BLOODRAVEN = 2,
    QUEST_A1Q3_MALUS = 3,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUEST_A5Q6_BAAL = 36,
    QUESTSTATEFLAG_A1Q3 = 3,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A5Q6 = 40,
    QFLAG_CUSTOM6 = 10,
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

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780

#define QFLAG_PRIMARYGOALDONE 13

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

// 0x00591210
void __fastcall ACT1Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT1Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = ACT1Q2_Callback08_MonsterKilled;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT1Q2_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT1Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT1Q2_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT1Q2_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT1Q2_Callback13_PlayerStartedGame;
    pQuestData->pfSeqFilter = ACT1Q2_SeqCallback;
    pQuestData->pNPCMessages = gpAct1Q2NpcMessages;
    pQuestData->eFilter = QUESTSTATEFLAG_A1Q2;
    pQuestData->bActive = 1;

    D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest2Strc), gszA1Q2SourceFile, LINE_INIT_ALLOC, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = A1Q2_INITNO;
    pQuestData->nSeqId = A1Q2_SEQID;
    pQuestData->pfActiveFilter = ACT1Q2_ActiveFilterCallback;

    pQuestDataEx->bUnk0x01 = 0;
    pQuestDataEx->bUnk0x00 = 0;
    pQuestDataEx->bKashyaActivated = 0;
    pQuestDataEx->bBloodravenKilled = 0;
    pQuestDataEx->nBloodravenGUID = 0;

    pQuestData->fState = 0;
}

#define QFLAG_CUSTOM7 11

#define QFLAG_COMPLETEDNOW 14

#define ACT_III 2

struct Obj00590810;

struct Obj00590810 {
    unsigned char bUnknown00[9];
    unsigned char bFlag09;
    unsigned char bUnknown0A[2];
    unsigned char bValue0C;
};

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

// 0x00590810
extern "C" __declspec(dllexport) bool __fastcall sub_00590810(Obj00590810* pObj) {
    if (pObj->bFlag09 && pObj->bValue0C >= 4) {
        return true;
    }
    return false;
}

// 0x00590830
int __fastcall ACT1Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 2);
    }

    return 0;
}

// 0x00590890
int __fastcall ACT1Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestRecord, 2, 0) == 1 || QUESTRECORD_GetQuestState(pQuestRecord, 2, 1) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 2);
    if (!pQuestData)
    {
        return 0;
    }
    const unsigned char nState = pQuestData->fState;
    if (nState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestRecord, 2, 2);
        return 0;
    }
    if (nState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestRecord, 2, 3);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestRecord, 2, 4);
    }
    return 0;
}

// 0x00590920
void __fastcall ACT1Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_KASHYA)
    {
        return;
    }

    D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bKashyaActivated != 1)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bKashyaActivated = 0;
    pQuestData->pCallback[2] = 0;
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
}

// 0x00590980
void __fastcall ACT1Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNPCNo != MONSTER_KASHYA)
    {
        return;
    }

    if (nMessageIndex == 81)
    {
        ((D2Act1Quest2Strc*)pQuestData->pQuestDataEx)->bKashyaActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, gszA1Q2SourceFile, 192);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 92)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
        {
            return;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE) && pQuestData->fState != 5)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 0);
            QUESTS_StateDebug(pQuestData, 5, gszA1Q2SourceFile, 205);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 206);
            pQuestData->pfSeqFilter(pQuestData);
        }

        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
        QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING);
        QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        D2GAME_NPC_AssignMercenary_6FCCB520(pQuestData->pGame, pQuestArg->pPlayer, MONSTER_KASHYA);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
}

extern "C" unsigned int gnAct1Quest2NpcIndices[]; // 0x00737180

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

// 0x00590B10
void __fastcall ACT1Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (!pQuestData->fState)
    {
        return;
    }

    if (bRewardGranted == 1)
    {
        return;
    }

    if (pQuestData->fState >= 4)
    {
        return;
    }

    const unsigned int nIndex = gnAct1Quest2NpcIndices[pQuestData->fState];
    if (nIndex != -1 && nIndex < 6)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00590BF0
bool __fastcall ACT1Q2_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 3, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 1);
    return true;
}

// 0x00590C10
void __fastcall ACT1Q2_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

// 0x00590C40
int __fastcall ACT1Q2_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pUnit);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q2_BLOODRAVEN);
    D2_ASSERT(pQuestData, 307);

    D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bBloodravenKilled)
    {
        return 0;
    }

    D2ActiveRoomStrc* pMonsterRoom = UNITS_GetRoom(SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nBloodravenGUID));
    if (!pPlayerRoom)
    {
        return 0;
    }

    int bInRange = 0;
    if (pPlayerRoom == pMonsterRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pRoom, 334);

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nRooms);
        for (unsigned int i = 0; i < nRooms; ++i)
        {
            if (ppRoomList[i] == pMonsterRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    if (!bInRange)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING);
    return 0;
}

// 0x00590D60
void __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == ACT_I)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING);
    }
}

// 0x00590DD0
int __fastcall ACT1Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_REWARDPENDING) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, 2, 0);
    }

    return 0;
}

// 0x00590E30
int __fastcall ACT1Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE) == 1)
    {
        SUNIT_AttachSound(pUnit, 34, pUnit);
    }

    return 0;
}

// 0x00590E70
int __fastcall ACT1Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_PRIMARYGOALDONE))
    {
        return 0;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q2_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00590EC0
void __fastcall ACT1Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestData->bNotIntro)
    {
        QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", gszA1Q2SourceFile, DIAG_LINE_NUMBER);
        QUESTS_StateDebug(pQuestData, QUEST_STATE, gszA1Q2SourceFile, STATE_LINE);
        D2Act1Quest2Strc* pQuestDataEx = (D2Act1Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->bUnk0x01 = 1;
        pQuestDataEx->bBloodravenKilled = 1;
        pQuestDataEx->nBloodravenGUID = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwUnitId;
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_SetCompletionFlag);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q2_UnitIterate_AttachCompletionSound);
        QUESTS_CreateTimer(pQuestData, ACT1Q2_Timer_StatusCycler, TIMER_TICKS);
        pQuestData->pCallback[2] = 0;
        pQuestDataEx->bUnk0x00 = 1;
        pQuestDataEx->unk0x04 = 1;
        QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, GLOBAL_STATE);
    }
}

// 0x00590FA0
void __fastcall ACT1Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;

    if (pQuestArg->nNewLevel == LEVEL_BURIALGROUNDS && pQuestData->bNotIntro == 1)
    {
        bool bStateUpdated = false;
        if (pQuestData->fState < 3)
        {
            QUESTS_StateDebug(pQuestData, 3, gszA1Q2SourceFile, 489);
            pQuestData->nStatusFlags = 0;
            bStateUpdated = true;
        }

        if (pQuestData->fLastState == 1 || !pQuestData->fLastState)
        {
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT1Q2_UnitIterate_StatusCyclerEx, 1);
            bStateUpdated = true;
        }

        if (bStateUpdated)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
            return;
        }
    }

    if (nOldLevel != LEVEL_ROGUEENCAMPMENT)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) == 1)
        {
            return;
        }
    }

    QUESTS_StateDebug(pQuestData, 3, gszA1Q2SourceFile, 519);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q2_UnitIterate_UpdateQuestStateFlags);
}

// 0x00591080
bool __fastcall ACT1Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_KASHYA && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) != 1)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) == 1)
        {
            return true;
        }
    }

    return false;
}

// 0x005910F0
bool __fastcall ACT1Q2_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, gszA1Q2SourceFile, LINE_SEQ_DEBUG);
        return true;
    }

    if (pQuestData->fState != QSTATE_5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), LINE_SEQ_ASSERT);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00591180
void __fastcall ACT1Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = QSTATE_2;
        pQuestData->fState = QSTATE_3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = QSTATE_3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q2, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = QSTATE_2;
        pQuestData->fLastState = 1;
    }
}

#include "gen/data/Source/D2Game/Quests/a1q2.inc"
