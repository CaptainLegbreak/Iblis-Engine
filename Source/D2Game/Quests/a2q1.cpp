#include "D2LevelIds.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Game.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"

#pragma function(memset)

#define CHECK(p,line) if(!(p)){FOG_DisplayHalt(text_006CC837,sub_00408090(),line);sub_00681E09(-1);}

struct D2BitBufferStrc;

struct D2ActiveRoomStrc;

struct D2QuestArgStrc;

struct D2QuestDataStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2Act2Quest0Strc;

struct D2Act2Quest1Strc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" char gpAct2IntroNpcMessages[]; // 0x00738D60

extern "C" char gpAct2Q0NpcMessages[]; // 0x00738FC8

void __fastcall ACT2Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005984C0

void __fastcall ACT2Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005983E0

bool __fastcall ACT2Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005985B0

bool __fastcall ACT2Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005985C0

void __fastcall ACT2Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005986B0

bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x00598770

bool __fastcall ACT2Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00598780

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

extern "C" const char gszA2Q0SourceFile[]; // 0x006E1F2C

// build: symbol _gszA2Q1SourceFile 0x006E1F60
extern "C" const char gszA2Q1SourceFile[],text_006CC837[]; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char*,const char*,int); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl sub_00681E09(int); // 0x00681E09

void __fastcall QUESTS_StateDebug(D2QuestDataStrc*,int,const char*,int); // 0x00544350

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc*,int,void*,QUESTUNITITERATE); // 0x005537D0

int __fastcall ACT2Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005989E0

int __fastcall ACT2Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005988B0

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc*,int,int); // 0x0065C3A0

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00545780

enum
{
    QUESTSTATEFLAG_A2Q1 = 9,
};

extern char gpAct2Q1NpcMessages[];                                                                          // 0x00739218

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine);  // 0x00544350

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg);          // 0x00545310

bool __fastcall ACT2Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00598910

void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00598980

void __fastcall ACT2Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);   // 0x00598990

void __fastcall ACT2Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00598A70

void __fastcall ACT2Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);      // 0x00598C40

void __fastcall ACT2Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x00599020

bool __fastcall ACT2Q1_SeqCallback(D2QuestDataStrc* pQuestData);                                            // 0x005991C0

void __fastcall ACT2Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT2Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

#define TERMINAL_STATE 5

#define ASSERT_LINE 579

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn);                                  // 0x006CC34C

static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

// 0x005988B0
int __fastcall ACT2Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 9, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 9, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 9, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 9, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 8);
    }
    return 0;
}

#define QFLAG_PRIMARYGOALDONE 13

struct Flags;

struct D2Act3Quest5Strc;

struct Quest { char pad[9]; unsigned char notIntro; char padA[2]; unsigned char state; char padD[0xD3]; int filter; };

int __stdcall QUESTRECORD_GetQuestState(Flags*,int,int); // 0x0065C310

enum { NPC_ID = 176 };

extern "C" const char gszAct3Q5SourceFile[];

int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestState, int nFlag);

void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00545530

int __fastcall ACT3Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

// 0x00598910
bool __fastcall ACT2Q1_ActiveFilterCallback(Quest* quest,int npc,D2UnitStrc* player,Flags* flags,D2UnitStrc* npcUnit)
{
    if (npc == NPC_ID && QUESTRECORD_GetQuestState(flags,quest->filter,0)!=1) {
        if (quest->notIntro && quest->state==1 && !QUESTRECORD_GetQuestState(flags,quest->filter,15)) return true;
        if (QUESTRECORD_GetQuestState(flags,quest->filter,1)==1) return true;
    }
    return false;
}

// 0x00598980
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x00598990
void __fastcall ACT2Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != 0xB0)
    {
        return;
    }

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bAtmaActivated != 1)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q1_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bAtmaActivated = 0;
    pQuestData->pCallback[2] = 0;
}

// 0x005989E0
int __fastcall ACT2Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 9, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 9, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 9, 2);
    }
    else if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 9, 3);
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 9, 4);
        }
    }

    return 0;
}

// build: symbol _text_006E1F60 0x006E1F60
// 0x00598A70
void __fastcall ACT2Q1_Callback11_ScrollMessage(D2QuestDataStrc* q,D2QuestArgStrc* arg)
{
 const unsigned short message=arg->nMessageIndex;
 const unsigned short npc=arg->nNPCNo;
 D2BitBufferStrc* flags=PLAYER_GetQuestFlags(arg->pGame,arg->pPlayer);
 if(npc!=176) return;
 D2Act2Quest1Strc* ex=(D2Act2Quest1Strc*)q->pQuestDataEx;
 if(message==304) {
  ex->bAtmaActivated=1;
  QUESTS_StateDebug(q,2,gszA2Q1SourceFile,239);
  SUNIT_IterateUnitsOfType(q->pGame,0,0,ACT2Q1_UnitIterate_UpdateQuestStateFlags);
 } else {
  if(message!=334) return;
  const int filter=q->eFilter;
  if(!QUESTRECORD_GetQuestState(flags,filter,1)) return;
  if(QUESTRECORD_GetQuestState(flags,q->eFilter,13)) {
   if(q->fState!=5) {
    q->dwFlags&=0xFFFFFF00;
    QUESTS_UnitIterate(q,13,0,ACT2Q1_UnitIterate_StatusCyclerEx,true);
    q->pCallback[2]=0;
    QUESTS_StateDebug(q,5,gszA2Q1SourceFile,253);
    CHECK(!IsBadCodePtr((int (__stdcall*)())q->pfSeqFilter),254);
    q->pfSeqFilter(q);
   }
   if(!q->bNotIntro) QUESTS_SetGlobalState(q->pGame,9,13);
  } else if(ex->rewardPending) {
   D2QuestDataStrc* seq=QUESTS_GetQuestData(q->pGame,q->nSeqId);
   if(seq) {
    CHECK(!IsBadCodePtr((int (__stdcall*)())q->pfSeqFilter),269);
    seq->pfSeqFilter(seq);
   }
  }
  QUESTRECORD_SetQuestState(flags,q->eFilter,0);
  QUESTRECORD_ClearQuestState(flags,q->eFilter,1);
  QUESTS_AddPlayerGUID(&q->tPlayerGUIDs,UNITS_GetUnitId(arg->pPlayer));
 }
 QUESTS_NPCActivateSpeeches(arg->pGame,arg->pPlayer,arg->pTarget);
}

enum D2C_P08QuestConstants
{
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
};

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

extern int gnAct2Q1NpcMessageIndices[]; // 0x007398FC

// 0x00598C40
void __fastcall ACT2Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (bRewardGranted != 1)
    {
        if (!pQuestData->fState || (pQuestData->fState >= 4 && !bPrimaryGoalDone))
        {
            return;
        }

        const unsigned int nIndex = gnAct2Q1NpcMessageIndices[pQuestData->fState];
        if (nIndex != -1 && nIndex < 9)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x00598D40
void __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 9, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 9, 1) == 1)
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

    QUESTRECORD_SetQuestState(pQuestFlags, 9, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 9, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 9, 5);
    QUESTS_UpdatePlayerFlags(pGame, pUnit);
}

// 0x00598DC0
int __fastcall ACT2Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 9, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 9, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 9, 14);
        QUESTS_SendLogUpdateEx(pUnit, 8, 0);
    }
    return 0;
}

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

// 0x00598E20
int __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
    D2_ASSERT(pQuestData, 390);

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 405);

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

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0))
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
    {
        return 0;
    }

    if (!bInRange)
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 1);
    QUESTRECORD_SetQuestState(pQuestFlags, 9, 5);
    QUESTS_UpdatePlayerFlags(pQuestData->pGame, pUnit);

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x00598F70
bool __fastcall ACT2Q1_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 4)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT2Q1_UnitIterate_StatusCyclerEx, 1);
    }
    pQuestDataEx->bStatusTimerStarted = 0;
    return 1;
}

// 0x00598FA0
int __fastcall ACT2Q1_UnitIterate_DetermineSkillBookDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pGame, pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 9, 5))
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
        if (pQuestData && !ITEMS_FindQuestItem(pGame, pUnit, ' ssa'))
        {
            ++((D2Act2Quest1Strc*)pQuestData->pQuestDataEx)->nSkillBookDropCount;
        }
    }

    pQuestFlags = PLAYER_GetQuestFlags(pGame, pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 9, 13))
    {
        SUNIT_AttachSound(pUnit, 50, pUnit);
    }
    return 0;
}

#define QUEST_A2Q1_RADAMENT 8
#define ITEMQUAL_NORMAL 2
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10
int __fastcall ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00598E20
struct D2ItemDropStrc;

// 0x00599020
void __fastcall ACT2Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    QUESTS_DebugOutput(pQuestData->pGame, "killed radament for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 495);
    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 496);
    QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
    pQuestData->pCallback[2] = 0;
    pQuestDataEx->bRadamentKilled = 1;
    pQuestDataEx->pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q1_UnitIterate_SetCompletionFlag);
    pQuestDataEx->nSkillBookDropCount = 0;
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q1_UnitIterate_DetermineSkillBookDropCount);

    if (!pQuestDataEx->bStatusTimerStarted)
    {
        pQuestDataEx->bStatusTimerStarted = 1;
        QUESTS_CreateTimer(pQuestData, ACT2Q1_Timer_StatusCycler, 12);
    }

    if (!pQuestDataEx->nSkillBookDropCount)
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' ssa';
    for (int i = 0; i < pQuestDataEx->nSkillBookDropCount; ++i)
    {
        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pQuestData->pGame, pQuestArg->pTarget, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
    }
}

// 0x00599420
void __fastcall ACT2Q1_OnRadamentActivated(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q1_RADAMENT);
    if (!pQuestData || pQuestData->bNotIntro != 1 || (pQuestData->fState >= 3u && pQuestData->fLastState >= 2u))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_SEWERSLEV3)
    {
        return;
    }

    pQuestData->pCallback[2] = 0;

    bool bStepped = false;
    if (pQuestData->fState < 3)
    {
        bStepped = true;
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 708);
    }

    if (pQuestData->fLastState < 2)
    {
        D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)pQuestData->pQuestDataEx;
        pQuestData->dwFlags &= 0xFFFFFF00;

        bool bIterate = false;
        if (!pQuestDataEx->bRadamentStatusIterated)
        {
            pQuestDataEx->bRadamentStatusIterated = 1;
            bIterate = true;
        }
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q1_UnitIterate_StatusCyclerEx, bIterate);
    }
    else if (!bStepped)
    {
        return;
    }
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q1_UnitIterate_UpdateQuestStateFlags);
}

// 0x005994F0
bool __fastcall ACT2Q1_IsDoneOrInactive(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 8);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return true;
    }
    return pQuestData->fState == 5 ? true : false;
}

// 0x00599130
void __fastcall ACT2Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != LEVEL_LUTGHOLEIN)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 551);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q1_UnitIterate_UpdateQuestStateFlags);
}

// 0x005991B0
void __stdcall ACT2Q1_OnRadamentCreated(int nUnused1)
{
}

// 0x005991C0
bool __fastcall ACT2Q1_SeqCallback(D2QuestDataStrc* pQuestData)
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

// 0x00599230
void __fastcall ACT2Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 0) == 1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 5) == 1 && !ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' ssa'))
        {
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 0);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 1);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 15);
            QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 5);
        }
        QUESTS_SetGlobalState(pQuestData->pGame, QUESTSTATEFLAG_A2Q1, 13);
        pQuestData->bNotIntro = 0;
        pQuestData->fState = 0;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 15) == 1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 1) == 1)
        {
            ((D2Act2Quest1Strc*)pQuestData->pQuestDataEx)->rewardPending = 1;
        }
        pQuestData->fState = 0;
        pQuestData->bNotIntro = 0;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 4) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00599340
void __fastcall ACT2Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->bActive = 1;
    pQuestData->fState = 1;
    pQuestData->pCallback[3] = ACT2Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT2Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT2Q1_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[2] = ACT2Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[13] = ACT2Q1_Callback13_PlayerStartedGame;
    pQuestData->nSeqId = 13;
    pQuestData->pfSeqFilter = ACT2Q1_SeqCallback;
    pQuestData->pNPCMessages = gpAct2Q1NpcMessages;

    D2Act2Quest1Strc* pQuestDataEx = (D2Act2Quest1Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act2Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q1.cpp", 670, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A2Q1;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT2Q1_ActiveFilterCallback;

    memset(pQuestDataEx, 0x00, sizeof(D2Act2Quest1Strc));
    pQuestDataEx->pRoom = 0;
    pQuestDataEx->bRadamentKilled = 0;
}

