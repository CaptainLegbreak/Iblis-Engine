#include "D2GameEvents.h"
#include "D2LevelIds.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2Packets.h"
#include "D2ObjectIds.h"
#include "D2MonsterIds.h"
#include "D2DataTbls.h"
#include "D2MissileIds.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QUEST_A2Q6_DURIEL 13



struct D2PlayerDataStrc;

struct D2Act1Quest4Strc;

struct D2Act1Quest5Strc;

struct D2Act2Quest3Strc;

struct D2Act2Quest4Strc;

struct D2Act2Quest5Strc;

struct D2Act2Quest6Strc;


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"


typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


int __fastcall ACT2Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C710

int __fastcall ACT2Q6_GetTombArcaneThingObjectId(D2QuestDataStrc* pQuestData); // 0x0059D720

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

void __fastcall ACT2Q6_UnitIterate_CheckDistanceToTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059DF30

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


extern "C" void* __cdecl memset(void*,int,unsigned int);

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern char npc_messages[]; // 0x0073B288

void __fastcall ACT2Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059D1C0

void __fastcall ACT2Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059C3C0

void __fastcall ACT2Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059CB20

void __fastcall ACT2Q6_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059C6B0


void __fastcall ACT2Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059D4F0

void __fastcall ACT2Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059D4D0

void __fastcall ACT2Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059D050

bool __fastcall ACT2Q6_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x0059CA50

bool __fastcall ACT2Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x0059D300

bool __fastcall ACT2Q6_SeqCallback(D2QuestDataStrc* pQuestData); // 0x0059D450


#define QUEST_A2Q4_HORAZONTOME 11

struct D2ObjectControlStrc;

struct D2ObjOperateFnStrc;

struct D2QuestGUIDStrc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);


typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

void __fastcall ACT2Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x0059C760

int __fastcall ACT2Q6_UnitIterate_SetLeaveTownFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C860

int __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C9A0

int __fastcall ACT2Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059C9F0

struct D2GameStrc;

struct D2QuestDataStrc;

struct D2ObjInitFnStrc;


typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


extern "C" const char gszA2Q6DebugKilledDuriel[]; // 0x006E209C


void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


void __fastcall D2Game_10034_Return(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380


void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630


bool __fastcall ACT2Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x0059CEE0


int __fastcall ACT2Q6_UnitIterate_SetCustom1FlagForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x0059CFB0



extern "C" const char gszA2Q6SourceFile[]; // 0x006E2068

static void __stdcall ACT2Q6_SetPrimaryGoalDoneAndLeaveTown(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags); // 0x0059C810


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc*, int); // 0x005452C0

extern unsigned int gnAct2Quest6DialogIndex[]; // 0x0073B8A8


enum D2C_P08QuestConstants
{
    ACT_II = 1,
    QUEST_A1Q4_CAIN = 4,
    QUEST_A1Q5_COUNTESS = 5,
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A1Q5 = 5,
    QUESTSTATEFLAG_A1Q6 = 6,
    QUESTSTATEFLAG_A2Q2 = 10,
    QUESTSTATEFLAG_A2Q3 = 11,
    QUESTSTATEFLAG_A2Q4 = 12,
    QUESTSTATEFLAG_A4Q2 = 26,
    QUESTSTATEFLAG_A5Q6 = 40,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_REWARDPENDING = 1,
    QFLAG_STARTED = 2,
    QFLAG_LEAVETOWN = 3,
    QFLAG_ENTERAREA = 4,
    QFLAG_CUSTOM1 = 5,
    QFLAG_CUSTOM2 = 6,
    QFLAG_CUSTOM6 = 10,
    QFLAG_PRIMARYGOALDONE = 13,
};

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

// 0x0059D1C0
void __fastcall ACT2Q6_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    if (nNewLevel < LEVEL_LUTGHOLEIN || nNewLevel >= LEVEL_KURASTDOCKTOWN)
    {
        return;
    }

    if (pQuestArg->nOldLevel == LEVEL_LUTGHOLEIN)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bDurielKilled)
    {
        if (!pQuestDataEx->nStaffTombLevelId)
        {
            pQuestDataEx->nStaffTombLevelId = DUNGEON_GetHoradricStaffTombLevelId(pQuestArg->pGame->pAct[ACT_II]);
        }

        const int nTombLevelId = pQuestDataEx->nStaffTombLevelId;
        if (!nTombLevelId)
        {
            return;
        }

        if (nNewLevel == nTombLevelId)
        {
            if (pQuestData->fState == 2)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 881);
            if (pQuestData->fLastState <= 1)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 0);
            }

            ACT2Q6_UnitIterate_UpdateQuestStateFlags(pQuestArg->pGame, pQuestArg->pPlayer, 0);
            return;
        }

        if (nNewLevel == LEVEL_CANYONOFTHEMAGI)
        {
            if (!pQuestData->fState)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 897);
                ACT2Q6_UnitIterate_UpdateQuestStateFlags(pQuestArg->pGame, pQuestArg->pPlayer, 0);
            }

            if (!pQuestData->fLastState)
            {
                pQuestData->dwFlags &= 0xFFFFFF00;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            }

            return;
        }
    }

    if (nNewLevel != LEVEL_DURIELSLAIR || pQuestData->fState > 1)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 912);
    if (pQuestData->fLastState > 1)
    {
        return;
    }

    pQuestData->dwFlags &= 0xFFFFFF00;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 0);
    ACT2Q6_UnitIterate_UpdateQuestStateFlags(pQuestArg->pGame, pQuestArg->pPlayer, 0);
}

#define QUESTSTATEFLAG_A2Q6 14

#define QFLAG_CUSTOM3 7

#define QFLAG_CUSTOM4 8

#define QFLAG_CUSTOM7 11

// 0x0059D300
bool __fastcall ACT2Q6_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_JERHYN)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_REWARDGRANTED) == 1)
        {
            return false;
        }

        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_LEAVETOWN) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_ENTERAREA))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_LEAVETOWN) == 1)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_MESHIF1)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_ENTERAREA) == 1)
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_TYRAEL1)
    {
        D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuest->pQuestDataEx;
        if (pQuest->bNotIntro != 1 || pQuestDataEx->bDurielKilled != 1)
        {
            return false;
        }

        if (pQuestDataEx->bPortalToLutGholeinOpened == 0)
        {
            return true;
        }
    }
    else
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_PRIMARYGOALDONE))
        {
            return false;
        }

        if (nNpcId == MONSTER_ATMA)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM2))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_WARRIV2)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM3))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_DROGNAN)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM4))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_LYSANDER)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM5))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_CAIN2)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM6))
            {
                return true;
            }
        }
        else if (nNpcId == MONSTER_FARA)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q6, QFLAG_CUSTOM7))
            {
                return true;
            }
        }
    }

    return false;
}

// 0x0059D5B0
void __fastcall ACT2Q6_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[3] = ACT2Q6_Callback03_ChangedLevel;
    pQuestData->pCallback[0] = ACT2Q6_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT2Q6_Callback11_ScrollMessage;
    pQuestData->pCallback[10] = ACT2Q6_RemovePlayerGUID;
    pQuestData->pCallback[2] = ACT2Q6_Callback02_NpcDeactivate;
    pQuestData->pCallback[13] = ACT2Q6_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT2Q6_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[8] = ACT2Q6_Callback08_MonsterKilled;
    pQuestData->pNPCMessages = npc_messages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, 0x68, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 1090, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 14;
    pQuestData->pfStatusFilter = ACT2Q6_StatusFilterCallback;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT2Q6_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT2Q6_SeqCallback;
    memset(pQuestDataEx, 0x00, 0x68);
    pQuestDataEx->bDurielKilled = 0;
    pQuestDataEx->unused0x02 = 0;
    pQuestDataEx->bTimerActive = 0;
    pQuestDataEx->nTyraelsDoorObjectMode = 0;
    pQuestDataEx->unused0x1C = 0;
    pQuestDataEx->nStaffTombLevelId = 0;
}

// 0x0059C3C0
void __fastcall ACT2Q6_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId == 251)
    {
        if (((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->nTyraelsDoorObjectMode == 2)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
    {
        if (nNpcId == 176 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 6))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 176, 6);
            return;
        }
        if (nNpcId == 175 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 7))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 175, 6);
            return;
        }
        if (nNpcId == 177 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 8))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 177, 6);
            return;
        }
        if (nNpcId == 202 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 9))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 202, 6);
            return;
        }
        if (nNpcId == 244 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 10))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 244, 6);
            return;
        }
        if (nNpcId == 178 && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 11))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 178, 6);
            return;
        }
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 3))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 4))
    {
        if (nNpcId == 210)
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
        else
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }
    if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }
    if (!pQuestData->fState)
        return;
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 14, 0);
    const int bCustom1 = QUESTRECORD_GetQuestState(pQuestFlags, 14, 13);
    if (bRewardGranted == 1 && !bCustom1)
        return;
    const unsigned char nState = pQuestData->fState;
    if (nState >= 4 && !bCustom1)
        return;
    const unsigned int nIndex = gnAct2Quest6DialogIndex[nState];
    if (gnAct2Quest6DialogIndex[nState] == 1 && nNpcId == 177)
    {
        if (QUESTS_GetGlobalState(pQuestData->pGame, 12, 13) == 1)
            return;
    }
    else
    {
        if (nIndex == -1 || static_cast<unsigned int>(nIndex) >= 8)
            return;
    }
    QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
}

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

// 0x0059C650
int __fastcall ACT2Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 13);
    }

    return 0;
}


// 0x0059C6B0
void __fastcall ACT2Q6_RemovePlayerGUID(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x0059D050
void __fastcall ACT2Q6_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed duriel for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x305);
    if (pQuestData->bNotIntro)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x308);
        QUESTS_CreateTimer(pQuestData, ACT2Q6_Timer_StatusCycler, 8);

        if (pQuestArg->pPlayer)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 14, 0)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 3)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 4)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 5))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 14, 5);

                const unsigned short nPartyId = SUNIT_GetPartyId(pQuestArg->pPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pQuestArg->pGame, nPartyId, (PartyCallbackFunction)ACT2Q6_UnitIterate_SetCustom1Flag, 0);
                }

                D2Game_10034_Return(pQuestData, pQuestArg, 0x3D);
            }
        }
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestData->pCallback[2] = 0;
    pQuestData->pCallback[8] = 0;
    pQuestDataEx->bDurielKilled = 1;
    pQuestDataEx->pDurielRoom = UNITS_GetRoom(pQuestArg->pTarget);
    QUESTS_TriggerFX(pQuestData->pGame, 8);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT2Q6_UnitIterate_SetCustom1FlagForPartyMembers);

    if (pQuestDataEx->bTyraelsDoorInitialized)
    {
        D2UnitStrc* pTyraelsDoor = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nTyraelsDoorGUID);
        if (pTyraelsDoor)
        {
            UNITS_ChangeAnimMode(pTyraelsDoor, 1);
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pTyraelsDoor ? -1 : pTyraelsDoor->dwClassId);
            EVENT_SetEvent(pQuestData->pGame, pTyraelsDoor, 1, pQuestData->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
        }
    }

    pQuestDataEx->nTyraelsDoorObjectMode = 2;
}

// 0x0059D4D0
void __fastcall ACT2Q6_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, 0xA, 0x9);
}

// 0x0059D4F0
void __fastcall ACT2Q6_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    QUESTRECORD_ClearQuestState(pQuestFlags, 0xA, 0x9);

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0xA, 0))
    {
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bDurielLairPortalNeedsToOpen = 1;
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bObjectsNeedUpdate = 1;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0xF))
    {
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bRewardedOrCompletedBefore = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 0xE, 2) == 1)
    {
        pQuestData->fLastState = 1;
        pQuestData->fState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 0xE, 3) == 1)
    {
        pQuestData->fLastState = 5;
        pQuestData->fState = 5;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 0xE, 4) == 1)
    {
        pQuestData->fLastState = 6;
        pQuestData->fState = 5;
    }
}

static D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
}

// 0x0059C920
void __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!QUESTS_GetQuestData(pGame, 13))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 3) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 4) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 1)
    {
        return;
    }

    ACT2Q6_SetPrimaryGoalDoneAndLeaveTown(pGame, pUnit, pQuestFlags);
}

// 0x0059C9A0
int __fastcall ACT2Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q6_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}


// 0x0059C9F0
int __fastcall ACT2Q6_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 14, 3) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 14, 4) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 14);
        QUESTS_SendLogUpdateEx(pUnit, 13, 0);
    }

    return 0;
}

// 0x0059CA50
bool __fastcall ACT2Q6_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 7, 0)) { *pStatus = 0; return true; }
    D2Act2Quest6Strc* pEx = (D2Act2Quest6Strc*)pQuest->pQuestDataEx;
    if (pEx->bHoradricStaffIsMissing) { *pStatus = (unsigned char)pEx->nQuestStatus; return true; }
    *pStatus = 0;
    if (!QUESTRECORD_GetQuestState(pFlags, 14, 0))
    {
        if (QUESTRECORD_GetQuestState(pFlags, 14, 3) == 1) { *pStatus = 5; return true; }
        if (QUESTRECORD_GetQuestState(pFlags, 14, 4) == 1) { *pStatus = 6; return true; }
        if (pQuest->bNotIntro)
        {
            if (QUESTRECORD_GetQuestState(pFlags, 14, 5) == 1) { *pStatus = pQuest->fLastState; return true; }
            if (pQuest->fState < 3) { *pStatus = pQuest->fLastState; return true; }
            *pStatus = 12;
        }
    }
    return true;
}

static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x0059CB20
void __fastcall ACT2Q6_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    const unsigned short nMessage = pQuestArg->nMessageIndex;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;

    if (pQuestArg->nNPCNo == 251)
    {
        if (pQuestData->bNotIntro && nMessage == 302 && !pQuestDataEx->bPortalToLutGholeinOpened)
        {
            pQuestDataEx->bPortalIsOpening = 1;

            if (D2GAME_CreatePortalObject(pQuestData->pGame, pQuestArg->pPlayer, UNITS_GetRoom(pQuestArg->pPlayer), CLIENTS_GetUnitX(pQuestArg->pPlayer), CLIENTS_GetUnitY(pQuestArg->pPlayer), 40, 0, 59, 0))
            {
                QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 577);
                SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q6_UnitIterate_SetLeaveTownFlag);
                SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q6_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
                SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT2Q6_UnitIterate_SetCompletionFlag);

                pQuestDataEx->bPortalToLutGholeinOpened = 1;
                pQuestDataEx->bTyraelActivated = 1;
                pQuestData->pCallback[2] = ACT2Q6_Callback02_NpcDeactivate;
            }

            pQuestDataEx->bPortalIsOpening = 0;
        }
    }
    else if (pQuestArg->nNPCNo == 201)
    {
        if (nMessage == 430)
        {
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 596);
            D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 10);
            pQuestDataEx->bInitJerhynActivated = 1;
            pQuestData->pCallback[2] = ACT2Q6_Callback02_NpcDeactivate;
            if (pQuest)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 602);
                pQuest->pfSeqFilter(pQuest);
            }
        }
        else if (nMessage == 442 && QUESTRECORD_GetQuestState(pQuestFlags, 14, 3))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
            {
                QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 620);
            }
            pQuestDataEx->bEndJerhynActivated = 1;
            pQuestData->pCallback[2] = ACT2Q6_Callback02_NpcDeactivate;
            QUESTRECORD_SetQuestState(pQuestFlags, 14, 4);
            QUESTRECORD_ClearQuestState(pQuestFlags, 14, 3);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        return;
    }
    else if (pQuestArg->nNPCNo == 210)
    {
        if (nMessage == 450 && QUESTRECORD_GetQuestState(pQuestFlags, 14, 4))
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, 10, 0))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' tsh');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' piv');
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' fsm');
            }

            if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
            {
                QUESTS_SetGlobalState(pQuestData->pGame, 14, 13);
                QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 644);
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 13, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 14, 0);
            QUESTS_UpdatePlayerFlags(pQuestData->pGame, pQuestArg->pPlayer);
            QUESTRECORD_ClearQuestState(pQuestFlags, 14, 4);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
        return;
    }

    switch (nMessage)
    {
    case 445:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 6);
        break;
    case 446:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 7);
        break;
    case 449:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 8);
        break;
    case 444:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 9);
        break;
    case 452:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 10);
        break;
    case 447:
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 11);
        break;
    default:
        return;
    }
}

// 0x0059CEE0
bool __fastcall ACT2Q6_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fLastState != 5 && pQuestData->fLastState != 4 && pQuestData->fLastState != 3)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
    }

    pQuestDataEx->bStatusTimerActive = 0;
    return true;
}

// 0x0059CF20
void __fastcall ACT2Q6_UnitIterate_SetCustom1Flag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!QUESTS_GetQuestData(pGame, 13))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 3) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 4) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 5) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) == 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 14, 5);
    }
}

// 0x0059CFB0
int __fastcall ACT2Q6_UnitIterate_SetCustom1FlagForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_DURIELSLAIR)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 3)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 4)
        || QUESTRECORD_GetQuestState(pQuestFlags, 14, 5))
    {
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 14, 5);
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q6_UnitIterate_SetCustom1Flag, 0);
    }

    return 0;
}

// 0x0059D450
bool __fastcall ACT2Q6_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x3E9);
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, 0xA);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x3EE);
        return pQuest->pfSeqFilter(pQuest);
    }

    return true;
}

// 0x0059D6A0
void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0xD);
    D2GSPacketSrv50 packet50;
    packet50.nHeader = 0x50;
    packet50.nQuestId = 0xD;

    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x45F);
    const int nTombStaffLevel = DUNGEON_GetHoradricStaffTombLevelId(pGame->pAct[1]);
    if (!nTombStaffLevel)
    {
        packet50.nParams[0] = 0;
    }
    else
    {
        packet50.nParams[0] = nTombStaffLevel - 0x42;
        ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->nStaffTombLevelId = nTombStaffLevel;
    }
    D2GAME_SendPacket0x50(pClient, &packet50);
}

extern int gnArcaneThingObjectIds[]; // 0x00738FAC

// 0x0059D720
int __fastcall ACT2Q6_GetTombArcaneThingObjectId(D2QuestDataStrc* pQuestData)
{
    const int nTombStaffLevel = DUNGEON_GetHoradricStaffTombLevelId(pQuestData->pGame->pAct[1]);
    if (nTombStaffLevel)
    {
        D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
        const int nTombOffset = nTombStaffLevel - LEVEL_TALRASHASTOMB1;
        if (!pQuestDataEx->bObjectIdsInitialized)
        {
            pQuestDataEx->bObjectIdsInitialized = 1;

            int i = 0;
            int j = 0;
            for (int k = 0; k < 7; ++k)
            {
                if (j == nTombOffset)
                {
                    ++j;
                }
                else if (j < 7 && i < 6)
                {
                    pQuestDataEx->nArcaneThingObjectIds[i] = gnArcaneThingObjectIds[j];
                    ++i;
                    ++j;
                }
            }
        }

        if (pQuestDataEx->nArcaneThings == 6)
        {
            pQuestDataEx->nArcaneThings = 0;
        }

        return pQuestDataEx->nArcaneThingObjectIds[pQuestDataEx->nArcaneThings++];
    }

    return 307;
}

// 0x0059D7C0
bool __fastcall ACT2Q6_IsJerhynTalkDone(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fState < 2)
    {
        return false;
    }

    return true;
}

// 0x0059D7E0
unsigned char __fastcall ACT2Q6_IsAwaitingJerhynTalk(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fState == 1)
    {
        return 1;
    }

    return 0;
}

// 0x0059D800
unsigned char __fastcall ACT2Q6_IsNotBusy(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData && pQuestData->bNotIntro)
    {
        const unsigned char nState = pQuestData->fState;
        if (nState == 1 || !nState)
        {
            return 0;
        }
    }
    return 1;
}

// 0x0059D830
int __fastcall ACT2Q6_GetObjectIdForArcaneThing(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData)
    {
        return ACT2Q6_GetTombArcaneThingObjectId(pQuestData);
    }

    return 0x133;
}

// 0x0059D850
unsigned char __fastcall ACT2Q6_IsTombOpen(D2QuestArgStrc* pQuestArg)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuestArg->pGame, QUEST_A2Q6_DURIEL);
    if (pQuestData && pQuestData->bNotIntro)
    {
        return ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bDurielLairTombOpen;
    }
    return 1;
}

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230


// 0x0059D870
bool __fastcall ACT2Q6_Timer_UpdateObjects(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    int nObjects = 0;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bObjectsNeedUpdate == 1)
    {
        if (pQuestDataEx->bUnusedObjectInitialized)
        {
            D2UnitStrc* pUnusedObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nUnusedObjectGUID);
            if (pUnusedObject)
            {
                nObjects = 1;
                if (!pUnusedObject->dwAnimMode)
                {
                    if (pQuestDataEx->bDurielLairPortalNeedsToOpen)
                    {
                        UNITS_ChangeAnimMode(pUnusedObject, OBJMODE_OPENED);
                    }
                    else
                    {
                        UNITS_ChangeAnimMode(pUnusedObject, OBJMODE_OPERATING);
                        const int nClassId = pUnusedObject->dwClassId;
                        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
                        EVENT_SetEvent(pQuestData->pGame, pUnusedObject, EVENTTYPE_ENDANIM, pQuestData->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
                    }
                }
            }
        }

        if (pQuestDataEx->bHoradricOrificeInitialized)
        {
            D2UnitStrc* pHoradricOrifice = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, pQuestDataEx->nHoradricOrificeGUID);
            if (pHoradricOrifice)
            {
                const int nX = CLIENTS_GetUnitX(pHoradricOrifice) - 13;
                const int nY = CLIENTS_GetUnitY(pHoradricOrifice) + 3;

                D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pHoradricOrifice), nX, nY);
                if (pRoom)
                {
                    D2UnitStrc* pDurielLairPortal = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_PORTAL_TO_DURIELS_LAIR, nX, nY, pGame, pRoom, 1, 1, 0);
                    if (pDurielLairPortal)
                    {
                        ++nObjects;
                        if (pQuestDataEx->bDurielLairPortalNeedsToOpen)
                        {
                            UNITS_ChangeAnimMode(pDurielLairPortal, OBJMODE_OPENED);
                        }
                        else
                        {
                            UNITS_ChangeAnimMode(pDurielLairPortal, OBJMODE_OPERATING);
                            DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pHoradricOrifice), 1);
                            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
                        }
                    }
                }
            }
        }

        if (!nObjects)
        {
            return false;
        }

        pQuestDataEx->bDurielLairTombOpen = 1;
        pQuestDataEx->bObjectsNeedUpdate = 0;
    }

    pQuestDataEx->bTimerActive = 0;
    return true;
}

// 0x0059D9D0
void __fastcall D2GAME_WarpPlayerToTile(D2ObjOperateFnStrc* pOp)
{
    for (D2UnitStrc* i = UNITS_GetRoom(pOp->hObject)->pUnitFirst; i; i = i->ptRoomNext)
    {
        if (i->dwUnitType == UNIT_TILE)
        {
            SUNIT_WarpPlayer(pOp->pGame, pOp->hPlayer, i);
        }
    }
}

// 0x0059DA10
int __fastcall ACT2Q6_OperateTombPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData || pQuestData->bNotIntro != 1 || ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bDurielLairTombOpen)
    {
        if (pOp->hObject && pOp->hObject->dwAnimMode == OBJMODE_OPENED)
        {
            D2GAME_WarpPlayerToTile(pOp);
        }
    }
    return 0;
}

// 0x0059DA50
void __fastcall OBJECTS_InitFunction37_Unused(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* q=QUESTS_GetQuestData(pOp->pGame,13);
    if(q)
    {
        D2Act2Quest6Strc* ex=(D2Act2Quest6Strc*)q->pQuestDataEx;
        ex->bUnusedObjectInitialized=1;
        ex->nUnusedObjectGUID=!pOp->pObject ? -1 : pOp->pObject->dwUnitId;
        if(!q->bNotIntro) UNITS_ChangeAnimMode(pOp->pObject,2);
        else if(ex->bDurielLairTombOpen==1) UNITS_ChangeAnimMode(pOp->pObject,2);
        else if(ex->bObjectsNeedUpdate==1) UNITS_ChangeAnimMode(pOp->pObject,2);
        else UNITS_ChangeAnimMode(pOp->pObject,0);
    }
    else UNITS_ChangeAnimMode(pOp->pObject,2);
}

// 0x0059DAD0
void __fastcall OBJECTS_InitFunction38_TyraelsDoor(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0xD);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bTyraelsDoorInitialized = 1;
    pQuestDataEx->nTyraelsDoorGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nTyraelsDoorObjectMode);
    }
}

// 0x0059DB20
int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && pQuestData->bNotIntro)
    {
        return ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bDurielLairTombOpen == 0;
    }

    return 0;
}

// 0x0059DB50
void __fastcall OBJECTS_InitFunction21_HoradricOrifice(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 0xD);
    if (!pQuestData)
    {
        return;
    }

    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bHoradricOrificeInitialized = 1;
    pQuestDataEx->nHoradricOrificeGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (!pQuestDataEx->bDurielLairPortalNeedsToOpen || pQuestDataEx->bTimerActive || pQuestDataEx->bDurielLairTombOpen)
    {
        if (pQuestDataEx->bDurielLairTombOpen)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
    }
    else
    {
        QUESTS_CreateTimer(pQuestData, ACT2Q6_Timer_UpdateObjects, 1);
        pQuestDataEx->bTimerActive = 1;
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x0059DBD0
void __fastcall ACT2Q6_UnitIterate_DeleteHoradricItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0xA, 0) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) != 1)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0xA, 0);
    QUESTRECORD_SetQuestState(pQuestFlags, 0xA, 0xD);
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return;
    }

    QUESTS_DeleteItem(pGame, pUnit, 0x20747368);
    QUESTS_DeleteItem(pGame, pUnit, 0x20706976);
    QUESTS_DeleteItem(pGame, pUnit, 0x2066736D);
}

// 0x0059DC70
int __fastcall OBJECTS_OperateFunction25_StaffOrifice(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_GetQuestData(pOp->pGame, 0xD))
    {
        return 0;
    }

    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pOp->pGame, pOp->hPlayer);
    D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 0x635);
    switch (!pOp->hObject ? 0 : pOp->hObject->dwAnimMode)
    {
    case 0:
    {
        if (PLAYER_IsBusy(pOp->hPlayer) == 1)
        {
            return 1;
        }

        if (!ITEMS_FindQuestItem(pOp->pGame, pOp->hPlayer, 0x20747368))
        {
            SUNIT_AttachSound(pOp->hPlayer, 0x13, pOp->hPlayer);
            return 1;
        }

        SUNIT_SetInteractInfo(pOp->hPlayer, 2, !pOp->hObject ? -1 : pOp->hObject->dwUnitId);
        UNITS_ChangeAnimMode(pOp->hObject, 1);

        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        const int nUnitId = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
        packet58.nUnitId = nUnitId;
        packet58.nAction = 0;
        D2GAME_SendPacket0x58(pClient, &packet58);
        break;
    }
    case 1:
        if (pInteractUnit == pOp->hObject)
        {
            SUNIT_ResetInteractInfo(pOp->hPlayer);
            UNITS_ChangeAnimMode(pOp->hObject, 2);
        }
        break;
    }

    return 0;
}

struct D2MissilesTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


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

// 0x0059DD80
void __fastcall ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_SetQuestState(pQuestFlags, 10, 0);
    pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_SetQuestState(pQuestFlags, 10, 13);

    QUESTS_DeleteItem(pGame, pUnit, ' tsh');
    QUESTS_DeleteItem(pGame, pUnit, ' piv');
    QUESTS_DeleteItem(pGame, pUnit, ' fsm');

    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT2Q6_UnitIterate_DeleteHoradricItems, 0);
    }

    QUESTS_TriggerFX(pGame, 3);

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(MISSILE_HORADRICSTAFF);
    const int nTicks = (pMissilesTxtRecord->wRange - 75) / 20;

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bObjectsNeedUpdate = 1;
    pQuestDataEx->bStaffItemsRemoved = 1;
    if (!pQuestDataEx->bTimerActive)
    {
        QUESTS_CreateTimer(pQuestData, ACT2Q6_Timer_UpdateObjects, nTicks);
        pQuestDataEx->bTimerActive = 1;
    }

    UNITS_ChangeAnimMode(pObject, 1);

    D2ActiveRoomStrc* hRoomObject = UNITS_GetRoom(pObject);
    D2_ASSERT(hRoomObject, 1670);

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(hRoomObject, UNITS_GetUnitXPosition(pObject) - 13, UNITS_GetUnitYPosition(pObject) + 3);
    DUNGEON_ToggleHasPortalFlag(hRoomObject, 0);
    if (pRoom)
    {
        DUNGEON_ToggleHasPortalFlag(pRoom, 0);
    }
}


// 0x0059DF30
void __fastcall ACT2Q6_UnitIterate_CheckDistanceToTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pData;
    if (DRLG_UnitEdgeDistance(pUnit, pQuestDataEx->pTyrael) < 12)
    {
        pQuestDataEx->bCloseToTyrael = 1;
    }
}

// 0x0059DF50
int __fastcall ACT2Q6_IsInRangeOfTyrael(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData)
    {
        D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bRewardedOrCompletedBefore)
        {
            return 1;
        }

        if (pQuestDataEx->bPortalToLutGholeinOpened)
        {
            pQuestDataEx->bCloseToTyrael = 0;
            pQuestDataEx->pTyrael = pUnit;
            SUNIT_IterateLivingPlayers(pGame, ACT2Q6_UnitIterate_CheckDistanceToTyrael, pQuestDataEx);
            return pQuestDataEx->bCloseToTyrael == 0;
        }
    }

    return 0;
}

// 0x0059DFB0
bool __fastcall ACT2Q6_IsTyraelPortalOpened(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && pQuestData->bNotIntro && pQuestData->fState < 4)
    {
        return false;
    }

    return true;
}

// 0x0059DFD0
int __fastcall ACT2Q6_ActivateTomb(D2GameStrc* pGame, D2CoordStrc* pCoord, D2ActiveRoomStrc** ppRoom)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 13);
    if (pQuestData && ((D2Act2Quest6Strc*)pQuestData->pQuestDataEx)->bPortalIsOpening == 1)
    {
        int nX;
        int nY;
        D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[1], LEVEL_LUTGHOLEIN, 12, &nX, &nY, 3);
        if (pRoom)
        {
            GAME_ActivateRoom(pGame, pRoom);
            pRoom = COLLISION_GetFreeCoordinatesEx(pRoom, pCoord, 3, 0xBE11, 7);
            if (pRoom)
            {
                pCoord->nX = nX;
                pCoord->nY = nY;
                *ppRoom = pRoom;
                return 1;
            }
        }
    }

    return 0;
}

// 0x0059E060
void __fastcall ACT2Q6_SetPortalState(D2QuestDataStrc* pQuest, unsigned char bClear)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pQuest->pGame, QUEST_A2Q6_DURIEL);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bStaffItemsRemoved == 1)
    {
        return;
    }
    if (!bClear)
    {
        if (pQuestData->pGame->nGameType == 3)
        {
            pQuestDataEx->bHoradricStaffIsMissing = 1;
            pQuestDataEx->nQuestStatus = 8;
        }
        else
        {
            pQuestDataEx->bHoradricStaffIsMissing = 1;
            pQuestDataEx->nQuestStatus = 9;
        }
    }
    else
    {
        pQuestDataEx->bHoradricStaffIsMissing = 0;
    }
}

// 0x0059C6C0
int __fastcall ACT2Q6_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x0E, 0) != 1)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x0D);
        if (pQuestData && pQuestData->fState >= 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 0x0E, 2);
        }
    }

    return 0;
}

// 0x0059C710
int __fastcall ACT2Q6_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 14, 13))
    {
        SUNIT_AttachSound(pUnit, 54, pUnit);
    }

    return 0;
}

// 0x0059C750
void __fastcall ACT2Q6_AttachCompletionSoundToPlayers(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT2Q6_UnitIterate_AttachCompletionSound);
}

// 0x0059C760
void __fastcall ACT2Q6_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act2Quest6Strc* pQuestDataEx = (D2Act2Quest6Strc*)pQuestData->pQuestDataEx;
    if ((short)nNpcId == 251)
    {
        if (pQuestDataEx->bTyraelActivated == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTyraelActivated = 0;
            pQuestData->pCallback[2] = 0;
        }
    }
    else if ((short)nNpcId == 201)
    {
        if (pQuestDataEx->bInitJerhynActivated == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bInitJerhynActivated = 0;
        }
        else
        {
            if (pQuestDataEx->bEndJerhynActivated != 1)
            {
                return;
            }

            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 6, 0, ACT2Q6_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bEndJerhynActivated = 0;
        }

        pQuestData->pCallback[2] = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, (QUESTUNITITERATE)ACT2Q6_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x0059C810
static void __stdcall ACT2Q6_SetPrimaryGoalDoneAndLeaveTown(D2GameStrc* pGame, D2UnitStrc* pUnit, D2BitBufferStrc* pQuestFlags)
{
    QUESTRECORD_SetQuestState(pQuestFlags, 14, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 14, 3);
    CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a2q6.cpp", 386), 2, pGame->nDifficulty);
}

// 0x0059C860
int __fastcall ACT2Q6_UnitIterate_SetLeaveTownFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    struct { D2ActiveRoomStrc* pRoom; D2QuestDataStrc* pQuestInfo; } tLocals;
    tLocals.pRoom = UNITS_GetRoom(pUnit);
    if (!tLocals.pRoom)
    {
        return 0;
    }

    tLocals.pQuestInfo = QUESTS_GetQuestData(pGame, 13);
    D2_ASSERT(tLocals.pQuestInfo, 401);

    bool bInLair = false;
    if (DUNGEON_GetLevelIdFromRoom(tLocals.pRoom) == LEVEL_DURIELSLAIR)
    {
        bInLair = true;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 14, 13)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 3)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 14, 4)
        && bInLair)
    {
        ACT2Q6_SetPrimaryGoalDoneAndLeaveTown(pGame, pUnit, pQuestFlags);
    }

    return 0;
}

