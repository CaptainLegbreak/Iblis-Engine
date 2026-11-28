#include "D2ObjModes.h"
#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2Drlg.h"
#include "D2GameObjs.h"
#include "FogApi.h"
#include "D2CommonApi.h"


#define EVENTTYPE_ENDANIM 1

#define QUEST_A3Q3_GIDBINN 17

#define QFLAG_REWARDGRANTED 0

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

struct D2PoolSystemStrc;
struct D2Act3Quest2Strc;

union D2SeedStrc;

struct D2PlayerDataStrc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId); // 0x00552F60


void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190


#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2Act3Quest3Strc;

struct D2ObjInitFnStrc;

struct D2ObjOperateFnStrc;

struct D2ItemsTxt;

struct D2QuestGUIDStrc;

typedef int (__stdcall* FARPROC)();

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern char gpAct3Q3NpcMessages[]; // 0x0073FB98

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps); // 0x005A43E0

int __fastcall ACT3Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B8B20

int __fastcall ACT3Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B8BF0

void __fastcall ACT3Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8C50

bool __fastcall ACT3Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B8CC0

bool __fastcall ACT3Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B8E10

void __fastcall ACT3Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8EC0

void __fastcall ACT3Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B9240

void __fastcall ACT3Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B9700

void __fastcall ACT3Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B9980

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

int __fastcall ACT3Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B9130

void __fastcall ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B91B0


bool __fastcall ACT3Q3_SpawnGidbinnBoss(D2GameStrc*, D2QuestDataStrc*); // 0x005B9A30

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180


static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B8B20
int __fastcall ACT3Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 19, 6) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData)
    {
        return 0;
    }

    if (ITEMS_FindQuestItem(pGame, pUnit, ' 33g'))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 5);
        return 0;
    }

    if (((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bGidbinnDropped)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 4);

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 3))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 2);
        }
    }
    else
    {
        if (pQuestData->fState == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 3);
        }
    }

    return 0;
}

// 0x005B8BF0
int __fastcall ACT3Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_COMPLETEDBEFORE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A3Q3_GIDBINN);
    }

    return 0;
}

// 0x005B8C50
void __fastcall ACT3Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArg)
{
    const int nClassId = !pArg->pTarget ? -1 : pArg->pTarget->dwClassId;
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuest->pQuestDataEx;
    if ((unsigned short)nClassId == 0xFD)
    {
        if (pQuestDataEx->bHratliActivated == 1)
        {
            pQuest->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuest, 2, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bHratliActivated = 0;
            SUNIT_IterateUnitsOfType(pQuest->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
        }
    }
    else if ((unsigned short)nClassId == 0xFF && pQuestDataEx->bGidbinnBroughtToOrmus)
    {
        pQuestDataEx->bGidbinnBroughtToOrmus = 0;
        pQuestDataEx->bAltarCanBeActivated = 1;
    }
}

// 0x005B8CC0
bool __fastcall ACT3Q3_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 19, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 19, 13) ? 13 : 11;
        return true;
    }

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuest->pQuestDataEx;

    *pStatus = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g'))
    {
        *pStatus = 4;
        return true;
    }

    if (pQuestDataEx->bPlayerWithGidbinnDropped)
    {
        *pStatus = (pQuest->pGame->nGameType == 3) + 7;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 19, 6))
    {
        if (!QUESTRECORD_GetQuestState(pFlags, 19, 8))
        {
            *pStatus = 6;
        }
        if (!QUESTRECORD_GetQuestState(pFlags, 19, 7))
        {
            *pStatus = 5;
        }
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 4))
    {
        *pStatus = (pQuestDataEx->bGidbinnDropped == 1) + 2;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 3))
    {
        *pStatus = 2;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 19, 2))
    {
        *pStatus = 1;
    }

    return true;
}

// 0x005B8E10
bool __fastcall ACT3Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0))
    {
        return false;
    }

    if (nNpcId == 253)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g') || pQuest->fState != 1)
        {
            return false;
        }

        return true;
    }
    else if (nNpcId == 255)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 33g'))
        {
            return true;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
        {
            return true;
        }
    }
    else if (nNpcId == 252)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
        {
            return true;
        }
    }

    return false;
}


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


extern int gnAct3Q3NpcMessageIndices[]; // 0x007401B8

// 0x005B8EC0
void __fastcall ACT3Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 19, 0);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (bRewardGranted == 1)
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
        return;
    }

    D2UnitStrc* pGidbinn = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
    if (pGidbinn && QUESTRECORD_GetQuestState(pQuestFlags, 19, 5) && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 6))
    {
        const int bNoCustom4 = !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8);
        const int bNoCustom3 = !QUESTRECORD_GetQuestState(pQuestFlags, 19, 7);
        if (nNpcId == 252)
        {
            if (bNoCustom3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
                return;
            }
        }
        else
        {
            if (nNpcId == 255 && bNoCustom4)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
                return;
            }

            if (bNoCustom3)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
                return;
            }
        }

        if (bNoCustom4)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        }
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
            return;
        }

        if (pQuestData->fState < 4 && !pGidbinn)
        {
            const int nIndex = gnAct3Q3NpcMessageIndices[pQuestData->fState];
            if (nIndex != -1 && (unsigned int)nIndex < 8)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
            }
        }
    }
}

// 0x005B9090
void __fastcall ACT3Q3_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    if (pQuestArg->nNewLevel == 78 && pQuestData->bNotIntro && !pQuestData->fState)
    {
        pQuestData->fState = 1;
    }

    if (nOldLevel != 75)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);

    if (pQuestData->fState == 2)
    {
        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15) != 1)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 482);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
        }
    }
    else if (pQuestData->fState == 5)
    {
        pQuestData->bActive = 0;
    }
}

// 0x005B9130
int __fastcall ACT3Q3_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 0)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 6)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 8)
        && !QUESTRECORD_GetQuestState(pQuestFlags, 19, 7)
        && !ITEMS_FindQuestItem(pGame, pUnit, ' 33g'))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 14);
    }

    return 0;
}

// 0x005B91B0
void __fastcall ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (!QUESTS_GetQuestData(pGame, 17))
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, 19, 6)
        || QUESTRECORD_GetQuestState(pQuestFlags, 19, 8)
        || QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (DRLG_GetActNoFromLevelId(nLevelId) == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 19, 6);
    }
}

struct D2GameStrc;

struct D2QuestDataStrc;

struct D2RoomCoordListStrc;

struct D2UnitStrc;

// 0x005B9520
void __fastcall ACT3Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "ginbinn acquired", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 693);

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId);
    if (pQuestData->bNotIntro && pItemsTxtRecord->dwCode == ' 33g')
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 1);

        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 9))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 9);
            SUNIT_AttachSound(pQuestArg->pPlayer, 65, pQuestArg->pPlayer);
        }

        QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 710);
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 1);
    }

    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
}

// 0x005B9610
bool __fastcall ACT3Q3_SeqCallback(D2QuestDataStrc* pQuestData)
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
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 732);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005B9680
void __fastcall ACT3Q3_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g'))
    {
        ++pQuestDataEx->nGidbinnsInGame;
    }

    if (pQuestDataEx->bPlayerWithGidbinnDropped && pQuestDataEx->nGidbinnsInGame == 1)
    {
        pQuestDataEx->bPlayerWithGidbinnDropped = 0;
    }
}

// 0x005B96C0
void __fastcall ACT3Q3_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;

    if (ITEMS_GetBaseCode(pQuestArg->pTarget) != ' 33g')
    {
        return;
    }

    --pQuestDataEx->nGidbinnsInGame;
    if (!pQuestDataEx->nGidbinnsInGame && pQuestDataEx->bGidbinnDropped && pQuestData->bNotIntro && pQuestData->fState < 5)
    {
        pQuestDataEx->bPlayerWithGidbinnDropped = 1;
    }
}

// 0x005B9700
void __fastcall ACT3Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    D2UnitStrc* pGidbinn = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (pGidbinn)
    {
        ++pQuestDataEx->nGidbinnsInGame;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 0))
    {
    if (pGidbinn)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 4;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 6) == 1)
    {
        pQuestDataEx->nAltarObjectMode = 2;
        pQuestData->fState = 5;

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 7))
        {
            pQuestData->fLastState = 5;
        }
        else if (!QUESTRECORD_GetQuestState(pQuestFlags, 19, 8))
        {
            pQuestData->fLastState = 6;
        }
        else
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 19, 0);
            pQuestData->bNotIntro = 0;
        }
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 5) == 1)
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 2;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 4) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 19, 3) == 1)
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 2;
        }
        else if (QUESTRECORD_GetQuestState(pQuestFlags, 19, 2) == 1)
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 1;
        }
    }
    }
    else
    {
        pQuestDataEx->nAltarObjectMode = 2;
    }
}

// 0x005B9850
void __fastcall ACT3Q3_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct3Q3NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->eFilter = 19;
    pQuestData->pfActiveFilter = ACT3Q3_ActiveFilterCallback;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = ACT3Q3_StatusFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q3_SeqCallback;
    pQuestData->nSeqId = 15;
    pQuestData->pCallback[4] = ACT3Q3_Callback04_ItemPickedUp;
    pQuestData->pCallback[0] = ACT3Q3_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q3_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q3_Callback03_ChangedLevel;
    pQuestData->pCallback[2] = ACT3Q3_Callback02_NpcDeactivate;
    pQuestData->pCallback[13] = ACT3Q3_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT3Q3_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT3Q3_Callback09_PlayerDroppedWithQuestItem;

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest3Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 916, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest3Strc));
    pQuestDataEx->nAltarObjectMode = 0;
}

// 0x005B9240
void __fastcall ACT3Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNpcNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0) == 1)
    {
        return;
    }

    if (nNpcNo == MONSTER_ORMUS)
    {
        if (nMessageIndex == 587)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g') && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 5) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
            {
                ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bGidbinnBroughtToOrmus = 1;
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 33g');
                --((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->nGidbinnsInGame;
                QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 6);

                const unsigned short nPartyId = SUNIT_GetPartyId(pQuestArg->pPlayer);
                if (nPartyId != 0xFFFF)
                {
                    PARTY_IteratePartyMembers(pQuestData->pGame, nPartyId, ACT3Q3_UnitIterate_SetGidbinnBroughtBackQuestState, 0);
                }

                SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_SetCompletionFlag);
            }

            if (pQuestData->bNotIntro)
            {
                QUESTS_SetGlobalState(pQuestArg->pGame, QUESTSTATEFLAG_A3Q3, 13);
            }

            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q3_UnitIterate_StatusCyclerEx, 0);

            if (!pQuestData->bNotIntro || pQuestData->fState == 5)
            {
                return;
            }

            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 621);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 622);
            pQuestData->pfSeqFilter(pQuestData);
        }
        else if (nMessageIndex == 593 && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 6) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8);

            int nItemLevel = 21;
            switch (pQuestArg->pGame->nDifficulty)
            {
            case 1:
                nItemLevel = 35;
                break;
            case 2:
                nItemLevel = 75;
                break;
            }

            QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' nir', nItemLevel, 6, 1);

            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7))
            {
                return;
            }

            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 13);
            QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
        }
    }
    else if (nNpcNo == MONSTER_HRATLI)
    {
        if (nMessageIndex == 571)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 659);
            ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bHratliActivated = 1;
        }
    }
    else if (nNpcNo == MONSTER_ASHEARA)
    {
        if (nMessageIndex != 589 || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 7);
        D2GAME_NPC_AssignMercenary(pQuestData->pGame, pQuestArg->pPlayer, MONSTER_ASHEARA);

        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 8))
        {
            return;
        }

        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 13);
        QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q3, 0);
        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}

// Out of line as in the original: ACT3Q3_SpawnGidbinnBoss (0x5B9A30) and OBJECTS_InitFunction25_Gidbinn (0x5B9AE0) call it.
// 0x005B9930
static __declspec(noinline) void ACT3Q3_SpawnFetishBoss(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2Act3Quest3Strc* pQuestDataEx)
{
    pQuestDataEx->bBossIsSpawning = 1;
    D2UnitStrc* pMonster = MONSTERUNIQUE_SpawnUniqueGroup(pGame, pRoom, 0, 0x197, 1, 0, 0, 1);
    if (pMonster)
    {
        pQuestDataEx->bGidbinnObjectActivated = 0;
        pQuestDataEx->bBossHasSpawned = 1;
        pQuestDataEx->nFetishBossGUID = pMonster->dwUnitId;
    }
    pQuestDataEx->bBossIsSpawning = 0;
}

// 0x005B9960
unsigned char __fastcall ACT3Q3_IsBossSpawning(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (pQuestData)
    {
        return ((D2Act3Quest3Strc*)pQuestData->pQuestDataEx)->bBossIsSpawning;
    }
    return 0;
}

// 0x005B9980
void __fastcall ACT3Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q3.cpp", 991);

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;

    if (!pQuestDataEx->bBossHasSpawned || !pQuestData->bNotIntro || (!MONSTERUNIQUE_CheckMonTypeFlag(pQuestArg->pTarget, 14) && !MONSTERS_IsBoss(0, pQuestArg->pTarget)))
    {
        return;
    }

    pQuestArg->pTarget->dwDropItemCode = ' 33g';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0))
    {
        pQuestDataEx->bGidbinnDropped = 1;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q3_UnitIterate_UpdateQuestStateFlags);
        pQuestData->pCallback[8] = 0;
    }
    else
    {
        pQuestDataEx->bBossHasSpawned = 0;
    }
}

static inline bool ACT3Q3_CanSpawnFetishBoss(const D2Act3Quest3Strc* pQuestDataEx)
{
    return pQuestDataEx->bGidbinnObjectInitialized == 1 && pQuestDataEx->bGidbinnObjectActivated && !pQuestDataEx->bBossHasSpawned;
}

// 0x005B9A30
bool __fastcall ACT3Q3_SpawnGidbinnBoss(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bSpawnTimerStarted = 0;
    if (ACT3Q3_CanSpawnFetishBoss(pQuestDataEx))
    {
        if (pGame->pAct[2])
        {
            D2ActiveRoomStrc* pRoom = DUNGEON_FindRoomBySubtileCoordinates(pGame->pAct[2], pQuestDataEx->nGidbinnX, pQuestDataEx->nGidbinnY);
            if (pRoom)
            {
                D2ActiveRoomStrc** ppRoomList;
                int nNumRooms;
                DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
                for (unsigned int i = 0; i < nNumRooms; ++i)
                {
                    for (D2UnitStrc* pUnit = ppRoomList[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
                    {
                        if ((!pUnit ? UNIT_INVALID : pUnit->dwUnitType) == UNIT_PLAYER)
                        {
                            ACT3Q3_SpawnFetishBoss(pGame, pRoom, pQuestDataEx);
                            pQuestData->pCallback[8] = ACT3Q3_Callback08_MonsterKilled;
                            return true;
                        }
                    }
                }
            }
        }
    }
    return true;
}

// 0x005B9AE0
void __fastcall OBJECTS_InitFunction25_Gidbinn(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 17);
    if (pQuestData)
    {
        if (pQuestData->bNotIntro)
        {
            D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->bGidbinnObjectInitialized = 1;
            pQuestDataEx->nGidbinnX = pOp->nX;
            pQuestDataEx->nGidbinnY = pOp->nY;
            if (pQuestDataEx->bGidbinnObjectActivated && !pQuestDataEx->bBossHasSpawned)
            {
                ACT3Q3_SpawnFetishBoss(pOp->pGame, pOp->pRoom, pQuestDataEx);
            }
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->pObject, 2);
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

inline D2BitBufferStrc* GetPlayerQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B9B40
int __fastcall OBJECTS_OperateFunction31_GidbinnDecoy(D2ObjOperateFnStrc* pOp)
{
    if (pOp->hObject && pOp->hObject->dwAnimMode)
        return 0;
    if (QUESTRECORD_GetQuestState(GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 19, 0)
        || QUESTRECORD_GetQuestState(GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 19, 7)
        || QUESTRECORD_GetQuestState(GetPlayerQuestFlags(pOp->pGame, pOp->hPlayer), 19, 8))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pOp->pGame, 17);
    if (pQuest && pQuest->bNotIntro)
    {
        if (!pQuest->fState)
            pQuest->fState = 1;
        D2Act3Quest3Strc* pEx = (D2Act3Quest3Strc*)pQuest->pQuestDataEx;
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxt->dwFrameCnt[1] >> 8), 0, 0);
        pEx->bGidbinnObjectActivated = 1;
        if (!pEx->bSpawnTimerStarted)
        {
            pEx->bSpawnTimerStarted = 1;
            QUESTS_CreateTimer(pQuest, ACT3Q3_SpawnGidbinnBoss, 7);
        }
    }
    return 0;
}

// 0x005B9C50
bool __fastcall ACT3Q3_GetBossGUID(D2GameStrc* pGame, int* pGUID)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return false;
    }
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bBossHasSpawned)
    {
        return false;
    }
    *pGUID = pQuestDataEx->nFetishBossGUID;
    return true;
}

// 0x005B9C80
void __fastcall ACT3Q3_ClearBossSpawned(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bBossHasSpawned == 1 && pQuestDataEx->nFetishBossGUID == (!pUnit ? -1 : pUnit->dwUnitId))
    {
        pQuestDataEx->bBossHasSpawned = 0;
    }
}

// 0x005B9CA0
int __fastcall ACT3Q3_GetAltarCoordinates(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (pQuestData)
    {
        D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bAltarCanBeActivated)
        {
            pCoord->nX = pQuestDataEx->nAltarX;
            pCoord->nY = pQuestDataEx->nAltarY;
            return 1;
        }
    }

    return 0;
}

// 0x005B9CD0
void __fastcall ACT3Q3_SetAltarMode(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 17);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bAltarCanBeActivated = 0;

    D2UnitStrc* pAltar = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nAltarGUID);
    if (!pAltar)
    {
        return;
    }

    UNITS_ChangeAnimMode(pAltar, 1);
    const int nClassId = pAltar->dwClassId;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
    EVENT_SetEvent(pGame, pAltar, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
    pQuestDataEx->nAltarObjectMode = 2;
}

// 0x005B9D40
void __fastcall OBJECTS_InitFunction39_GidbinnAltar(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 17);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest3Strc* pQuestDataEx = (D2Act3Quest3Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->nAltarGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;
    pQuestDataEx->nAltarX = pOp->nX;
    pQuestDataEx->nAltarY = pOp->nY;

    UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nAltarObjectMode);
}
