#include "D2ObjectIds.h"
#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2DataTbls.h"

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"

#define QUEST_A5Q5_ANCIENTS 35

#define STAT_LEVEL 12

struct D2ModeChangeStrc;

struct D2Act5Quest5Strc;

struct D2ObjOperateFnStrc;

struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2ObjInitFnStrc;

struct D2Act5Quest6Strc;

struct D2GameStrc;

struct D2CoordStrc;

struct D2UnitStrc;

struct D2QuestDataStrc;

struct D2DataTablesStrc;

struct D2ObjectsTxt;

struct D2QuestArgStrc;


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* pUnit, int a2); // 0x005544B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

void __fastcall SUNITINACTIVE_DeleteSingleListNode(D2GameStrc* pGame, unsigned short nUnitType, unsigned short nClassId, unsigned char nAct); // 0x00543140

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex); // 0x00545C30

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

int __fastcall ACT5Q5_UnitIterate_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D510

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __fastcall ACT5Q5_UnitIterate_ClosePortals(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D2C0

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

extern "C" const char gszA5Q5SourceFile[]; // 0x006E1ABC

extern "C" const char gszA5Q6SourceFile[];

int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer); // 0x005353F0

void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00535430

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage); // 0x005456A0

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

int __fastcall ACT5Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058BE20

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

void __fastcall D2GAME_WarpPlayerToTile_6FCA5B20(D2ObjOperateFnStrc* pOp); // 0x0059D9D0

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

int __fastcall ACT5Q6_UnitIterate_CreateLastPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058D7D0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty); // 0x00538680

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0

void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00570880

unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800

int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QFLAG_REWARDGRANTED 0

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern int gpAct5Q5NpcMessages[]; // 0x00735100

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall ACT5Q5_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058BE80

void __fastcall ACT5Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058C290

void __fastcall ACT5Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058C440

void __fastcall ACT5Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058C9A0

void __fastcall ACT5Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0058CBA0

bool __fastcall ACT5Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0058CCF0

typedef int (__fastcall *Iter)(D2GameStrc*,D2UnitStrc*,void*);



int __fastcall ACT5Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc*,D2UnitStrc*,void*); // 0x0058C210

int __stdcall ACT5Q5_ActivateAncientStatues(D2QuestDataStrc*,D2Act5Quest5Strc*); // 0x0058BF40

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*,D2UnitStrc*); // 0x00543520


#define NPC_SHIFT 0

#define FLAG_SHIFT 0

#define MESSAGE_SHIFT 0

#define MESSAGE_LIMIT 9u

struct D2BitBufferStrc;

struct D2TextHeaderStrc;

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

extern unsigned int gnA5Q5NpcActivateIndices[];  // 0x007357E4


#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define ACT_V 4

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2);                                      // 0x00545760

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

bool __fastcall ACT5Q5_Timer_RespawnAncientStatueObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData);   // 0x0058BD50

int __fastcall ACT5Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);     // 0x0058C780

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams);  // 0x0059FA30

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX);                                      // 0x0064A710

static void __stdcall ACT5Q5_RewardPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058C5C0

void __fastcall ACT5Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0058DC60

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

enum D2C_F33QuestConstants
{
    QUEST_A1Q2_BLOODRAVEN = 2,
    QUEST_A1Q3_MALUS = 3,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUEST_A5Q6_BAAL = 36,
    QUESTSTATEFLAG_A1Q2 = 2,
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
    ITEMQUAL_NORMAL = 2,
    MONSTATSFLAGINDEX_ZOO = 22,
};

// 0x0058BE80
void __fastcall ACT5Q5_Callback02_NpcDeactivate(D2QuestDataStrc* quest, D2QuestArgStrc* argument)
{
    if (argument->pTarget && (unsigned short)argument->pTarget->dwClassId == 515)
    {
        D2Act5Quest5Strc* data = (D2Act5Quest5Strc*)quest->pQuestDataEx;
        if (data->bQualKehkActivated == 1)
        {
            quest->nStatusFlags = 0;
            QUESTS_UnitIterate(quest, 1, 0, ACT5Q5_UnitIterate_StatusCyclerEx, true);
            data->bQualKehkActivated = 0;
        }
    }
}

// 0x0058BEC0
static bool ACT5Q5_RemoveAncientMonster(D2GameStrc* pGame, int nAncientMonsterGUID)
{
    D2UnitStrc* pAncientMonster = SUNIT_GetServerUnit(pGame, 1, nAncientMonsterGUID);
    if (!pAncientMonster)
    {
        return false;
    }

    if (STATES_CheckState(pAncientMonster, STATE_UNINTERRUPTABLE))
    {
        SUNIT_SetUninterruptable(pAncientMonster, 0);
    }

    if (UNITS_GetRoom(pAncientMonster))
    {
        D2ModeChangeStrc modeChange;
        MONSTERMODE_GetModeChangeInfo(pAncientMonster, 0x0C, &modeChange);
        D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);

        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pAncientMonster), 1, nAncientMonsterGUID);
        UNITS_FreeCollisionPath(pAncientMonster);
        UNITROOM_RemoveUnitFromRoom(pAncientMonster);
    }

    return true;
}

// 0x0058BF40
int __stdcall ACT5Q5_ActivateAncientStatues(D2QuestDataStrc* pQuestData, D2Act5Quest5Strc* pQuestDataEx)
{
    D2UnitStrc* pUnit[3];
    for (int i = 0; i < 3; ++i)
    {
        pUnit[i] = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nAncientStatueGUID[i]);
        if (!pUnit[i])
        {
            return 0;
        }

        DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pUnit[i]), 0);
    }

    for (int k = 0; k < 3; ++k)
    {
        UNITS_ChangeAnimMode(pUnit[k], OBJMODE_SPECIAL1);
        UNITS_FreeCollisionPath(pUnit[k]);
        EVENT_SetEvent(pQuestData->pGame, pUnit[k], EVENTTYPE_QUESTFN, pQuestData->pGame->dwGameFrame + 20, 0, 0);
        pQuestDataEx->nAncientStatueObjectMode[k] = OBJMODE_SPECIAL1;
    }

    pQuestDataEx->nAncientsSpawned = 0;
    pQuestDataEx->nAncientsAlive = 0;
    return 1;
}

// 0x0058C000
static void __stdcall ACT5Q5_DeactivateAncientMonsters(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2Act5Quest5Strc* pQuestDataEx)
{
    for (int i = 0; i < 0x03; ++i)
    {
        if (pQuestDataEx->bAncientMonsterSpawned[i])
        {
            if (ACT5Q5_RemoveAncientMonster(pGame, pQuestDataEx->nAncientMonsterGUID[i]))
            {
                --pQuestDataEx->nAncientsSpawned;
                --pQuestDataEx->nAncientsAlive;
            }
            else
            {
                SUNITINACTIVE_DeleteSingleListNode(pGame, 1, i + 0x21C, 0x04);
            }

            pQuestDataEx->bAncientMonsterSpawned[i] = 0;
        }
    }

    pQuestDataEx->bAncientsActivated = 0;

    for (int i = 0; i < 0x03; ++i)
    {
        pQuestDataEx->bAncienStatueRespawned[i] = 0;
        D2UnitStrc* pAncientStatue = SUNIT_GetServerUnit(pQuestData->pGame, 0x02, pQuestDataEx->nAncientStatueGUID[i]);
        if (pAncientStatue)
        {
            UNITS_ChangeAnimMode(pAncientStatue, 0);
        }
        pQuestDataEx->nAncientStatueObjectMode[i] = 0;
    }

    pQuestDataEx->nAltarObjectMode = 0;
    D2UnitStrc* pAltar = SUNIT_GetServerUnit(pGame, 0x02, pQuestDataEx->nAltarGUID);
    if (pAltar)
    {
        UNITS_ChangeAnimMode(pAltar, 0);
    }
}

// 0x0058C750
void __fastcall ACT5Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x0058CDA0
void __fastcall ACT5Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bQuestCompletedBefore = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_STARTED) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
}

static inline bool IsAncientStatue(int nNpcId)
{
    if (nNpcId < 537 + NPC_SHIFT)
        return false;
    if (nNpcId > 539 + NPC_SHIFT)
        return false;
    return true;
}

// 0x0058CD30
bool __fastcall ACT5Q5_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
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
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 981);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x0058CE30
void __fastcall ACT5Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_PLAYERLEAVESGAME] = ACT5Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT5Q5_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = ACT5Q5_Callback08_MonsterKilled;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT5Q5_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT5Q5_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT5Q5_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT5Q5_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = gpAct5Q5NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)sub_0040B430(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 1053, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = QUESTSTATEFLAG_A5Q5;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q5_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q5_SeqCallback;
    pQuestData->nSeqId = 36;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest5Strc));
}

// 0x0058CBA0
void __fastcall ACT5Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    const int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == LEVEL_HARROGATH)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        if (pQuestData->fState == 2)
        {
            D2UnitStrc* pPlayer = pQuestArg->pPlayer;
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 899);
            if (pQuestData->fLastState != 1)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
            }

            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q5_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if (nNewLevel == LEVEL_ROCKYSUMMIT)
    {
        unsigned char bUpdate = 0;
        if (pQuestData->fLastState < 2 && pQuestData->fState > 2)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
            bUpdate = 1;
        }

        if (pQuestData->fState < 3)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 919);
            bUpdate = 1;
        }

        if (bUpdate)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT5Q5_UnitIterate_UpdateQuestStateFlags);
        }

        if (!pQuestDataEx->bAncientsDefeated && pQuestDataEx->bSummitDoorInitialized)
        {
            D2UnitStrc* pSummitDoor = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nSummitDoorGUID);
            if (pSummitDoor && pQuestDataEx->nSummitDoorObjectMode == OBJMODE_NEUTRAL)
            {
                pQuestDataEx->nSummitDoorObjectMode = OBJMODE_OPENED;
                UNITS_ChangeAnimMode(pSummitDoor, OBJMODE_OPERATING);
            }
        }
    }
}

// 0x0058CCF0
bool __fastcall ACT5Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId != MONSTER_QUAL_KEHK || pQuest->fState != 1)
    {
        return false;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED))
    {
        return false;
    }

    return true;
}

// 0x0058C210
int __fastcall ACT5Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) == 1 || STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < 20 * (pGame->nDifficulty + 1))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_STARTED);
    }
    else if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_LEAVETOWN);
    }

    return 0;
}

// 0x0058C290
void __fastcall ACT5Q5_Callback11_ScrollMessage(D2QuestDataStrc* q,D2QuestArgStrc* a)
{
 short msg=(short)a->nMessageIndex;
 unsigned short npc=a->nNPCNo;
 D2Act5Quest5Strc* ex=(D2Act5Quest5Strc*)q->pQuestDataEx;
 if(msg==20153){
  if(npc==515){
   if(!q->bNotIntro||q->fState!=1)return;
   QUESTS_StateDebug(q,2,gszA5Q5SourceFile,413);
   if(q->fLastState!=1){q->dwFlags&=0xFFFFFF00;QUESTS_UnitIterate(q,1,0,ACT5Q5_UnitIterate_StatusCyclerEx,1);}
   SUNIT_IterateUnitsOfType(q->pGame,0,0,ACT5Q5_UnitIterate_UpdateQuestStateFlags);
   ex->bQualKehkActivated=1;return;
  }
 }else if(msg==20002){
  if(q->bNotIntro&&q->fState<4&&q->fLastState!=3){q->dwFlags&=0xFFFFFF00;QUESTS_UnitIterate(q,3,0,ACT5Q5_UnitIterate_StatusCyclerEx,1);}
  if(ex->nActivePortalCount>0)return;
  for(int i=0;i<3;++i)if(ex->nAncientStatueObjectMode[i])return;
  if(ACT5Q5_ActivateAncientStatues(q,ex)){ex->active=1;ex->bActivatable=1;}
  return;
 }else if(msg==20169){
 D2GameStrc* game=q->pGame;
 D2BitBufferStrc* pQuestFlags=UNITS_GetPlayerData(!a ? 0 : a->pPlayer)->pQuestData[game->nDifficulty];
 QUESTRECORD_SetQuestState(pQuestFlags,39,4);
 return;}
 switch(npc){
 case 511: if(msg==20167)QUESTRECORD_SetQuestState(sub_00543520(q->pGame,a->pPlayer),q->eFilter,5);break;
 case 520: if(msg==20165)QUESTRECORD_SetQuestState(sub_00543520(q->pGame,a->pPlayer),q->eFilter,6);break;
 case 512: if(msg==20166)QUESTRECORD_SetQuestState(sub_00543520(q->pGame,a->pPlayer),q->eFilter,7);break;
 case 513: if(msg==20168)QUESTRECORD_SetQuestState(sub_00543520(q->pGame,a->pPlayer),q->eFilter,8);break;
 case 515: if(msg==20164)QUESTRECORD_SetQuestState(sub_00543520(q->pGame,a->pPlayer),q->eFilter,9);break;
 }
}

// 0x0058C440
void __fastcall ACT5Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestData->pGame;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    int bRewarded = QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 0 + FLAG_SHIFT);
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (!pQuestData->bNotIntro)
        return;
    if (bRewarded)
    {
        int bPrimaryGoal = QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 13 + FLAG_SHIFT);
        switch (nNpcId)
        {
        case 511 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 5 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 520 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 6 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 512 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 7 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 513 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 8 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        case 515 + NPC_SHIFT:
            if (!QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 9 + FLAG_SHIFT))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5 + MESSAGE_SHIFT);
            else if (bPrimaryGoal)
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3 + MESSAGE_SHIFT);
            break;
        }
        return;
    }
    if (IsAncientStatue(nNpcId) && !pQuestDataEx->active)
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4 + MESSAGE_SHIFT);
    unsigned int nIndex = gnA5Q5NpcActivateIndices[pQuestData->fState];
    if (nIndex != -1 && nIndex < MESSAGE_LIMIT)
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
}

static
// 0x0058C5C0
void __stdcall ACT5Q5_RewardPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    int nRewardExp = 1400000;
    switch (pGame->nDifficulty)
    {
    case 1:
        nRewardExp = 20000000;
        break;
    case 2:
        nRewardExp = 40000000;
        break;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    const int nMaxLevel = DATATBLS_GetMaxLevel(nClassId);
    int nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nCurrentLevel >= nMaxLevel)
    {
        return;
    }

    const unsigned int nNextThreshold = DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel + 1);
    const int nDeltaExpThreshold = nNextThreshold - DATATBLS_GetLevelThreshold(nClassId, nCurrentLevel);
    if (nRewardExp > nDeltaExpThreshold)
    {
        nRewardExp = nDeltaExpThreshold;
    }

    do
    {
        if (!nRewardExp)
        {
            break;
        }

        const int nNextExp = STATLIST_GetUnitBaseStat(pUnit, STAT_NEXTEXP, 0);
        const unsigned int nDeltaExp = nNextExp - STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
        if ((unsigned int)nRewardExp >= nDeltaExp)
        {
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nNextExp, 0);
            STATLIST_SetUnitStat(pUnit, STAT_LASTEXP, nDeltaExp, 0);
            PLAYERSTATS_LevelUp(pGame, pUnit);
            nRewardExp -= nDeltaExp;
            nCurrentLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        }
        else
        {
            nRewardExp += STATLIST_GetUnitBaseStat(pUnit, STAT_EXPERIENCE, 0);
            STATLIST_SetUnitStat(pUnit, STAT_EXPERIENCE, nRewardExp, 0);
            nRewardExp ^= nRewardExp;
        }
    }
    while (nCurrentLevel < nMaxLevel);
}

// 0x0058C6D0
void __fastcall ACT5Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) || STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < 20 * (pGame->nDifficulty + 1))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != ACT_V)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE);
    ACT5Q5_RewardPlayer(pGame, pUnit);
}

// 0x0058C780
int __fastcall ACT5Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_COMPLETEDNOW);
        QUESTS_SendLogUpdateEx(pUnit, QUEST_A5Q5_ANCIENTS, 0);
    }

    return 0;
}

// 0x0058C7E0
int __fastcall ACT5Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS);
    D2_ASSERT(pQuestData, 725);

    if (STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0) < 20 * (pGame->nDifficulty + 1) || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROCKYSUMMIT)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_PRIMARYGOALDONE);
    QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED);
    ACT5Q5_RewardPlayer(pGame, pUnit);

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q5_UnitIterate_SetPrimaryGoalDone, 0);
    }

    return 0;
}

// 0x0058C8D0
static void __stdcall ACT5Q5_SpawnStatueMissile(D2QuestArgStrc* pQuestArg, int nObjectId, D2QuestDataStrc* pQuestData)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, nObjectId);
    if (!pObject)
    {
        return;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x420;
    missileParams.nMissile = MISSILE_ANCIENT_DEATH_CENTER;
    missileParams.pOwner = pQuestArg->pTarget;
    missileParams.pOrigin = pQuestArg->pTarget;
    missileParams.nTargetX = UNITS_GetXPositionInline(pObject);
    missileParams.nTargetY = UNITS_GetYPositionInline(pObject);
    missileParams.nSkillLevel = 1;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pQuestData->pGame, &missileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, nObjectId);
    }
}

// 0x0058C9A0
void __fastcall ACT5Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bActivatable || !pQuestDataEx->active || pQuestDataEx->nActivePortalCount)
    {
        return;
    }

    if (!pQuestDataEx->bTimerActive)
    {
        pQuestDataEx->bTimerActive = 1;
        QUESTS_CreateTimer(pQuestData, ACT5Q5_Timer_RespawnAncientStatueObjects, 2);
    }

    const int nMonsterId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    int nObjectId;
    switch (nMonsterId)
    {
    case MONSTER_ANCIENTBARB1:
        pQuestDataEx->bAncienStatueRespawned[2] = 1;
        nObjectId = pQuestDataEx->nAncientStatueGUID[2];
        break;

    case MONSTER_ANCIENTBARB2:
        pQuestDataEx->bAncienStatueRespawned[0] = 1;
        nObjectId = pQuestDataEx->nAncientStatueGUID[0];
        break;

    case MONSTER_ANCIENTBARB3:
        pQuestDataEx->bAncienStatueRespawned[1] = 1;
        nObjectId = pQuestDataEx->nAncientStatueGUID[1];
        break;

    default:
        return;
    }

    ACT5Q5_SpawnStatueMissile(pQuestArg, nObjectId, pQuestData);
    QUESTS_TriggerFX(pQuestData->pGame, 18);

    --pQuestDataEx->nAncientsAlive;
    if (pQuestDataEx->nAncientsAlive)
    {
        return;
    }

    pQuestDataEx->bAncientsDefeated = 1;
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    if (pQuestArg->pPlayer)
    {
        D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestData->pGame, pQuestArg->pPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED) && STATLIST_GetUnitBaseStat(pQuestArg->pPlayer, STAT_LEVEL, 0) >= 20 * (pQuestData->pGame->nDifficulty + 1))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_REWARDGRANTED);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q5, QFLAG_PRIMARYGOALDONE);
            ACT5Q5_RewardPlayer(pQuestArg->pGame, pQuestArg->pPlayer);
        }
    }

    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT5Q5_UnitIterate_SetCompletionFlag);
    QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 842);
    SUNIT_AllocUnitData(UNIT_OBJECT, 561, CLIENTS_GetUnitX(pQuestArg->pTarget), CLIENTS_GetUnitY(pQuestArg->pTarget), pQuestArg->pGame, UNITS_GetRoom(pQuestArg->pTarget), 1, 0, 0);

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 855);
        pQuest->pfSeqFilter(pQuest);
    }

    if (pQuestData->fLastState != 13)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x0058C0E0
void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    if ((pUnit && pUnit->dwAnimMode == 0x04) || pQuestDataEx->nAncientsSpawned >= 0x03)
    {
        return;
    }

    const int nObjectId = !pUnit ? -1 : pUnit->dwClassId;

    D2UnitStrc* pAncient;
    D2CoordStrc tCoord;
    int nIndex = 0;
    int nMonsterId = 0;
    // the three Ancients are super-unique ids 43, 44 and 45
    switch (nObjectId)
    {
    case OBJECT_ANCIENTSTATUE3:
        nIndex = 1;
        nMonsterId = sgptDataTables->nSuperUniqueIds[45];
        break;

    case OBJECT_ANCIENTSTATUE1:
        nIndex = 0;
        nMonsterId = sgptDataTables->nSuperUniqueIds[43];
        break;

    case OBJECT_ANCIENTSTATUE2:
        nIndex = 0x02;
        nMonsterId = sgptDataTables->nSuperUniqueIds[44];
        break;

    default:
        return;
    }

    if (pQuestDataEx->nActivePortalCount > 0)
    {
        ACT5Q5_DeactivateAncientMonsters(pQuestData->pGame, pQuestData, pQuestDataEx);
        return;
    }

    UNITS_GetCoords(pUnit, &tCoord);
    pAncient = QUESTS_SpawnMonster(pQuestData->pGame, pUnit, &tCoord, 0x02, nMonsterId);
    if (!pAncient)
    {
        EVENT_SetEvent(pQuestData->pGame, pUnit, 0x07, pQuestData->pGame->dwGameFrame + 0x0A, 0, 0);
        return;
    }

    if (!pUnit || pUnit->dwAnimMode != 0x04)
    {
        UNITS_ChangeAnimMode(pUnit, 0x04);
        pQuestDataEx->nAncientStatueObjectMode[nIndex] = 0x04;
    }

    pQuestDataEx->bAncientMonsterSpawned[pQuestDataEx->nAncientsSpawned] = 1;
    pQuestDataEx->nAncientMonsterGUID[pQuestDataEx->nAncientsSpawned] = !pAncient ? -1 : pAncient->dwUnitId;

    ++pQuestDataEx->nAncientsSpawned;
    ++pQuestDataEx->nAncientsAlive;

    pQuestDataEx->bAncientsActivated = 1;
}

// 0x0058CF00
void __fastcall ACT5Q5_OnPortalOpened(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROCKYSUMMIT)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bAncientsDefeated)
    {
        return;
    }

    ++((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount;
    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 0;
    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->active = 0;
    ACT5Q5_DeactivateAncientMonsters(pGame, pQuestData, (D2Act5Quest5Strc*)pQuestData->pQuestDataEx);
}

// 0x0058CF50
void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROCKYSUMMIT)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    --((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount;
    if (!((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nActivePortalCount && ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->active)
    {
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 1;
    }
}

// 0x0058CF90
int __fastcall ACT5Q5_IsNotActivatable(D2GameStrc* pGame)
{
    return ((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, 0x23)->pQuestDataEx)->bActivatable == 0;
}

// 0x0058CFB0
int __fastcall ACT5Q5_GetPortalCount(D2GameStrc* pGame)
{
    return ((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS)->pQuestDataEx)->nActivePortalCount;
}

// 0x0058CFD0
void __cdecl sub_0058CFD0_Nop()
{
}

// 0x0058CFE0
int __fastcall ACT5Q5_IsActivatable(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS);

    return pQuestData && ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable;
}

// 0x0058D000
int __fastcall ACT5Q5_AreAncientsDefeated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (pQuestData)
    {
        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bAncientsActivated && !pQuestDataEx->nAncientsAlive)
        {
            return 1;
        }
    }
    return 0;
}

// 0x0058D030
D2UnitStrc* __fastcall ACT5Q5_FindAncientMonsterByClassId(D2GameStrc* pGame, int nClassId)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, QUEST_A5Q5_ANCIENTS)->pQuestDataEx;
    for (int i = 0; i < pQuestDataEx->nAncientsSpawned; ++i)
    {
        D2UnitStrc* pAncient = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pQuestDataEx->nAncientMonsterGUID[i]);
        const int nAncientClassId = !pAncient ? -1 : pAncient->dwClassId;
        if (nAncientClassId == nClassId)
        {
            return pAncient;
        }
    }

    return 0;
}

// 0x0058D090
int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (!pQuestData->bNotIntro)
    {
        return 0;
    }

    return ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bAncientsDefeated == 0;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwClassId;
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}

static inline int UNITS_GetAnimMode(D2UnitStrc* pUnit)
{
    if (!pUnit) return 0;
    return pUnit->dwAnimMode;
}

static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0058D0C0
static void ACT5Q5_SetAncientStatueMode(D2Act5Quest5Strc* pQuestDataEx, D2ObjInitFnStrc* pOp)
{
    D2UnitStrc* pObject = pOp->pObject;
    int nIndex;
    switch (UNITS_GetWeaponClass(pObject))
    {
    case 0x1DA: nIndex = 1; break;
    case 0x1DB: nIndex = 0; break;
    case 0x1DC: nIndex = 2; break;
    default: return;
    }
    UNITS_ChangeAnimMode(pObject, pQuestDataEx->nAncientStatueObjectMode[nIndex]);
}

// 0x0058D110
void __fastcall OBJECTS_InitFunction65_AncientStatue2(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[0] = UNITS_GetUnitId(pOp->pObject);
    ACT5Q5_SetAncientStatueMode(pQuestDataEx, pOp);
}

// 0x0058D150
void __fastcall OBJECTS_InitFunction63_AncientStatue3(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[1] = UNITS_GetUnitId(pOp->pObject);
    ACT5Q5_SetAncientStatueMode(pQuestDataEx, pOp);
}

// 0x0058D190
void __fastcall OBJECTS_InitFunction64_AncientStatue1(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->nAncientStatueGUID[2] = UNITS_GetUnitId(pOp->pObject);
    ACT5Q5_SetAncientStatueMode(pQuestDataEx, pOp);
}

// 0x0058D1D0
static inline void ACT5Q5_PlayStatueSound(D2ObjOperateFnStrc* pOp)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
}

// 0x0058D1E0
int __fastcall OBJECTS_OperateFunction62_AncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    return 0;
}

// 0x0058D200
int __fastcall OBJECTS_OperateFunction63_AncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    return 0;
}

// 0x0058D220
int __fastcall OBJECTS_OperateFunction64_AncientStatue(D2ObjOperateFnStrc* pOp, int nOperate)
{
    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
    return 0;
}

// 0x0058D240
void __fastcall OBJECTS_InitFunction72_AncientsAltar(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (!pQuestData)
    {
        return;
    }

    ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nAltarGUID = UNITS_GetUnitId(pOp->pObject);
    UNITS_ChangeAnimMode(pOp->pObject, ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->nAltarObjectMode);
}

// 0x0058D280
void __fastcall OBJECTS_InitFunction73_AncientsDoor(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (!pQuestData)
    {
        return;
    }

    if (((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bQuestCompletedBefore)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, 0);
    }
}

// 0x0058D2C0
int __fastcall ACT5Q5_UnitIterate_ClosePortals(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, PLAYER_GetUniqueIdFromPlayerData(pUnit));
    if (!pPortal)
    {
        return 0;
    }

    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal)) == LEVEL_ROCKYSUMMIT)
    {
        PLAYER_RemoveTownPortal(pGame, pUnit);
    }

    return 0;
}

void __stdcall sub_M114_Emit_0058D1D0(D2ObjOperateFnStrc* pOp)
{
    ACT5Q5_PlayStatueSound(pOp);
}

// 0x0058D300
void __fastcall ACT5Q5_ClosePortals(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
}

// 0x0058D310
int __fastcall OBJECTS_OperateFunction65_AncientsAltar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (pQuestData)
    {
        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pOp->hObject && pOp->hObject->dwAnimMode != 0)
        {
            return 0;
        }

        if (!pQuestData->bNotIntro)
        {
            if (pQuestDataEx->nActivePortalCount > 0)
            {
                SUNIT_IterateUnitsOfType(pOp->pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
            }

            QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20002);
        }
        else if (pQuestData->fState < 4)
        {
            if (pQuestDataEx->nActivePortalCount > 0)
            {
                SUNIT_IterateUnitsOfType(pOp->pGame, 0, 0, ACT5Q5_UnitIterate_ClosePortals);
            }

            QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20002);

            if (pQuestData->fState < 2)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q5.cpp", 1439);
            }

            if (pQuestData->fLastState != 3)
            {
                QUESTS_UnitIterate(pQuestData, 3, 0, ACT5Q5_UnitIterate_StatusCyclerEx, 1);
            }
        }

        if (!pOp->hObject || pOp->hObject->dwAnimMode == 0)
        {
            UNITS_ChangeAnimMode(pOp->hObject, 1);
            pQuestDataEx->nAltarObjectMode = 2;
        }
    }

    return 0;
}

// 0x0058D400
int __fastcall OBJECTS_OperateFunction66_AncientsDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (pQuestData)
    {
        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
        if (pQuestData->bNotIntro && !pQuestDataEx->bAncientsDefeated || pQuestDataEx->bAncientsActivated && !pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        switch (UNITS_GetAnimMode(pOp->hObject))
        {
        case 0:
            UNITS_ChangeAnimMode(pOp->hObject, 1);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->hObject), 0);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
            break;

        case 2:
            D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pOp->hObject), 1);
            return 0;
        }
    }

    return 0;
}

// 0x0058D510
int __fastcall ACT5Q5_UnitIterate_CountLivingPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROCKYSUMMIT)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 0x11)
    {
        return 0;
    }

    ++((D2Act5Quest5Strc*)QUESTS_GetQuestData(pGame, 0x23)->pQuestDataEx)->nLivingPlayersOnSummit;
    return 0;
}

// 0x0058D560
void __fastcall ACT5Q5_OnPlayerDied(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_ROCKYSUMMIT)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x23);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nActivePortalCount || pQuestDataEx->bAncientsDefeated || !pQuestDataEx->bActivatable)
    {
        return;
    }

    pQuestDataEx->nLivingPlayersOnSummit = 0;
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT5Q5_UnitIterate_CountLivingPlayers);

    if (!pQuestDataEx->nLivingPlayersOnSummit)
    {
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->bActivatable = 0;
        ((D2Act5Quest5Strc*)pQuestData->pQuestDataEx)->active = 0;
        ACT5Q5_DeactivateAncientMonsters(pGame, pQuestData, (D2Act5Quest5Strc*)pQuestData->pQuestDataEx);
    }
}

// 0x0058D5E0
int __fastcall OBJECTS_OperateFunction69_InvisibleAncient(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x27, 0))
    {
        pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x27, 4))
        {
            QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, 20169);
        }
    }
    return 0;
}

// 0x0058D640
void __fastcall OBJECTS_InitFunction76_SummitDoor(D2ObjInitFnStrc* pOp)
{
    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)QUESTS_GetQuestData(pOp->pGame, 0x23)->pQuestDataEx;
    pQuestDataEx->bSummitDoorInitialized = 1;
    pQuestDataEx->nSummitDoorGUID = UNITS_GetUnitId(pOp->pObject);
    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nSummitDoorObjectMode);
    if (!pQuestDataEx->bAncientsDefeated && pQuestDataEx->nSummitDoorObjectMode != 2)
    {
        pQuestDataEx->nSummitDoorObjectMode = 2;
        UNITS_ChangeAnimMode(pOp->pObject, 1);
    }
}

// 0x0058D6A0
int __fastcall OBJECTS_OperateFunction71_SummitDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0x23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act5Quest5Strc* pQuestDataEx = (D2Act5Quest5Strc*)pQuestData->pQuestDataEx;
    switch (UNITS_GetAnimMode(pOp->hObject))
    {
    case 0:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            UNITS_ChangeAnimMode(pOp->hObject, 1);
            pQuestDataEx->nSummitDoorObjectMode = 2;
            return 0;
        }

        D2GAME_WarpPlayerToTile_6FCA5B20(pOp);
        return 0;

    case 2:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        }
        else if (pQuestDataEx->bAncientsActivated)
        {
            UNITS_ChangeAnimMode(pOp->hObject, 0);
            pQuestDataEx->nSummitDoorObjectMode = 0;
        }

    case 1:
        if (!pQuestDataEx->bAncientsDefeated)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            UNITS_ChangeAnimMode(pOp->hObject, 2);
        }
        else
        {
            pQuestDataEx->nSummitDoorObjectMode = 0;
            UNITS_ChangeAnimMode(pOp->hObject, 0);
        }
        return 0;
    }

    return 0;
}

