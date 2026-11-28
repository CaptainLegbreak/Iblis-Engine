#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2DataTbls.h"
#include "D2ObjModes.h"
#include "D2Packets.h"
#include "D2CommonApi.h"

#define QUEST_A4Q2_DIABLO 23

#define QUESTSTATEFLAG_A4Q2 26

#define QFLAG_REWARDGRANTED 0

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_COMPLETEDBEFORE 15

struct D2PoolSystemStrc;
struct D2PlayerDataStrc;

struct D2Act4Quest1Strc;

struct D2Act4Quest2Strc;

struct D2Act3Quest2Strc;

struct D2Act3Quest3Strc;

struct D2Act3Quest4Strc;

struct D2Act3Quest5Strc;

struct D2Act3Quest6Strc;


struct D2ObjInitFnStrc;

struct D2ModeChangeStrc;

struct D2ObjOperateFnStrc;

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

void __fastcall ACT4Q1_UnitIterate_CheckDistanceToIzualGhost(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B43D0

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

int __fastcall ACT4Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3D30

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60




int __fastcall ACT4Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc*, D2UnitStrc*, void*); // 0x005B4560

int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc*, D2UnitStrc*, void*); // 0x005B4E40

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern int gpAct4Q2NpcMessages[]; // 0x0073DBB8

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

bool __fastcall ACT4Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B4450

bool __fastcall ACT4Q2_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B4530

void __fastcall ACT4Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4670

void __fastcall ACT4Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4790

void __fastcall ACT4Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4EA0

void __fastcall ACT4Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4F90

void __fastcall ACT4Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B52E0


void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


bool __fastcall ACT4Q2_SpawnDiablo(D2GameStrc* pGame, D2QuestDataStrc* pQuestData); // 0x005B4BE0

static void __stdcall ACT4Q2_KillAllMonstersInCS(D2GameStrc* pGame, D2Act4Quest2Strc* pQuestDataEx);


D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230


D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

struct D2QuestDataStrc;

void __fastcall D2Game_10034_Return(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, int nValue); // 0x00545990

int __fastcall ACT4Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B4970

int __fastcall ACT4Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B49C0

int __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005B4DF0

int __fastcall ACT4Q2_UnitIterate_UpdatePlayerState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B5140

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


int __fastcall ACT4Q2_UnitIterate_UpdatePlayerState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B5140

int __fastcall OBJECTS_OperateFunction52_DiabloSeal(D2ObjOperateFnStrc* pOp);

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380

void __fastcall PLAYER_CloseInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005351C0


void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190


// 0x005B4450
bool __fastcall ACT4Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 367)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 15) && pQuest->fState == 1
            || !pQuest->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && QUESTRECORD_GetQuestState(pQuestFlags, 26, 7))
        {
            return true;
        }

        if (pQuest->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 9))
        {
            return true;
        }
    }
    else if (nNpcId == 246)
    {
        if (!pQuest->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && QUESTRECORD_GetQuestState(pQuestFlags, 26, 6))
        {
            return true;
        }

        if (!pQuest->pGame->bExpansion || !QUESTRECORD_GetQuestState(pQuestFlags, 26, 0))
        {
            return false;
        }

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 8))
        {
            return true;
        }
    }

    return false;
}

// 0x005B4530
bool __fastcall ACT4Q2_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (!pQuestData->fState && pQuestData->bNotIntro == 1)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 145);
    }
    return 1;
}

// 0x005B4560
int __fastcall ACT4Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 2);
        return 0;
    }
    if (pQuestData->fState == 3)
    {
        if (pQuestData->fLastState == 1)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 26, 3);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 4);
    }
    return 0;
}

// 0x005B45E0
static void ACT4Q2_SpawnPortalToHarrogath(D2QuestArgStrc* pQuestArg, D2Act4Quest2Strc* pQuestDataEx)
{
    D2CoordStrc pCoord;
    UNITS_GetCoords(pQuestArg->pTarget, &pCoord);
    pCoord.nX += 5;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    QUESTS_GetFreePosition(UNITS_GetRoom(pQuestArg->pTarget), &pCoord, 2, 0x400, &pRoom, 12, 100);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pPortal = SUNIT_AllocUnitData(2, 566, pCoord.nX, pCoord.nY, pQuestArg->pGame, pRoom, 1, 1, 0);
    if (!pPortal)
    {
        return;
    }

    pQuestDataEx->bSpawnPortalToAct5Pending = 0;
    pQuestDataEx->bPortalToAct5Spawned = 1;
    pPortal->dwFlags |= 0x3000000;
}

static D2BitBufferStrc* GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B4670
void __fastcall ACT4Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    const short nMessageIndex = pQuestArg->nMessageIndex;
    if (pQuestArg->nNPCNo == 0x16F)
    {
        if (nMessageIndex == 0x2A9)
        {
            pQuestDataEx->bTalkedToTyrael = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 0xE1);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
        else if (nMessageIndex == 0x2AC)
        {
            QUESTRECORD_ClearQuestState(GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 7);
        }
        else if (nMessageIndex == 0x4E20)
        {
            if (!pQuestData->pGame->bExpansion)
            {
                return;
            }

            QUESTRECORD_SetQuestState(sub_00543520(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 9);
            if (!pQuestDataEx->bPortalToAct5Spawned)
            {
                ACT4Q2_SpawnPortalToHarrogath(pQuestArg, pQuestDataEx);
            }
        }
    }
    else if (pQuestArg->nNPCNo == 0xF6)
    {
        if (nMessageIndex == 0x2AD)
        {
            QUESTRECORD_ClearQuestState(GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 6);
        }
        else if (nMessageIndex == 0x4E21)
        {
            QUESTRECORD_SetQuestState(GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer), 0x1A, 8);
        }
    }
}


extern int gnAct4Q2NpcMessageIndices[]; // 0x0073D56C

// 0x005B4790
void __fastcall ACT4Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int bCustom3 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 7);
    const int bCustom2 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 6);
    const int bCustom5 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 9);
    const int bCustom4 = QUESTRECORD_GetQuestState(pQuestFlags, 26, 8);

    if (!pQuestData->pGame->bExpansion)
    {
        if (bCustom3 && nNpcId == 367)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 2);
            return;
        }
        if (bCustom2 && nNpcId == 246)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 2);
            return;
        }
        if (bCustom3)
        {
            if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 3);
            }
            return;
        }
        if (bCustom2)
        {
            if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 3);
            }
            return;
        }
    }

    if (bRewardGranted == 1)
    {
        if (!pQuestData->pGame->bExpansion)
        {
            return;
        }

        if (!bCustom5)
        {
            if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 4);
            }
            else if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 5);
            }
        }

        if (!bCustom4)
        {
            if (nNpcId == 246)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 246, 4);
            }
            else if (nNpcId == 367)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 367, 5);
            }
        }
        return;
    }

    if ((pQuestData->fState < 4 || bPrimaryGoalDone) && pQuestData->bNotIntro && pQuestData->fState)
    {
        const int nIndex = gnAct4Q2NpcMessageIndices[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 7)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}


// 0x005B4970
int __fastcall ACT4Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 14);
    QUESTS_SendLogUpdateEx(pUnit, 23, 0);
    return 0;
}

// 0x005B49C0
int __fastcall ACT4Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 420);
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nQuestId = 23;
    packet5D.nFlags = 2;
    SCMD_SendPacket0x5D(pClient, &packet5D);
    SUNIT_AttachSound(pUnit, 75, pUnit);
    return 0;
}

// 0x005B4A30
static void ACT4Q2_WarpPlayerToFortress(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    LEVEL_WarpUnit(pGame, pPlayer, 103, 0);
    D2ClientStrc* pClient = UnitGetClient(pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 440);
    D2GSPacketSrv5D packet = {};
    packet.nHeader = 0x5D;
    packet.nQuestId = 0x17;
    packet.nFlags = 1;
    SCMD_SendPacket0x5D(pClient, &packet);
}

// 0x005B4BE0
bool __fastcall ACT4Q2_SpawnDiablo(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bNeedToSpawnDiablo)
    {
        ++pQuestDataEx->dwTickCount;
        if (pQuestDataEx->dwTickCount < 10 || !pQuestDataEx->bDiabloStartPointInitialized)
            return false;

        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nDiabloStartPointObjectGUID);
        if (!pObject)
            return false;

        if (!ACT4Q2_TrySpawnDiablo(pQuestData->pGame, UNITS_GetRoom(pObject), CLIENTS_GetUnitX(pObject), CLIENTS_GetUnitY(pObject), pQuestDataEx))
            return false;

        pQuestDataEx->bNeedToSpawnDiablo = 0;
        pQuestDataEx->bTimerCreated = 0;
        return true;
    }

    if (pQuestDataEx->bEndGameTimerActive)
    {
        if (pQuestDataEx->bNeedToEndGame && pQuestDataEx->dwTickCount + 95000 < GetTickCount())
        {
            pQuestDataEx->bTimerCreated = 0;
            pQuestDataEx->bEndGameTimerActive = 0;
            pQuestDataEx->bNeedToEndGame = 0;
            if (pQuestData->pGame->bExpansion)
                return true;

            GAME_EndGameForConnectedClient(pGame, 0);
            return true;
        }

        if (pQuestDataEx->dwTickCount + 90000 < GetTickCount())
        {
            if (pQuestDataEx->bNeedToWarpPlayers)
            {
                if (!pQuestData->pGame->bExpansion)
                    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT4Q2_UnitIterate_WarpToTownEndGame);

                pQuestDataEx->bNeedToWarpPlayers = 0;
            }
            return false;
        }

        if (pQuestDataEx->dwTickCount + 75000 < GetTickCount() && !pQuestDataEx->bClientsSaved)
        {
            pQuestDataEx->bClientsSaved = 1;
            GAME_SaveAndSendClientSaves(pGame);
        }
        return false;
    }

    return true;
}

// 0x005B4A80
int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    PLAYER_CloseInteraction(pGame, pUnit);
    UNITS_GetPlayerData(pUnit)->bBusy = 1;

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)QUESTS_GetQuestData(pGame, 23)->pQuestDataEx;
    pQuestDataEx->pWarpedPlayer = pUnit;

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        ACT4Q2_WarpPlayerToFortress(pGame, pUnit);
    }
    else
    {
        D2GSPacketSrv50 packet50;
        packet50.nHeader = 0x50;
        packet50.nQuestId = 23;
        D2GAME_SendPacket0x50(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 474), &packet50);
    }

    return 0;
}

// 0x005B4B60
D2UnitStrc* __fastcall ACT4Q2_TrySpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx)
{
    D2UnitStrc* pDiablo = D2GAME_SpawnMonster(pGame, pRoom, nX, nY, MONSTER_DIABLO, 1, -1, 0);
    if (!pDiablo)
    {
        pDiablo = D2GAME_SpawnMonster(pGame, pRoom, nX, nY, MONSTER_DIABLO, 1, 5, 0);
    }

    if (!pDiablo)
    {
        pDiablo = D2GAME_SpawnMonster(pGame, pRoom, nX, nY, MONSTER_DIABLO, 1, 10, 0);
        if (!pDiablo)
        {
            return 0;
        }
    }

    pDiablo->dwFlags |= 0x3000000;
    pQuestDataEx->bDiabloSpawned = 1;
    return pDiablo;
}

// 0x005B4D20
static void __stdcall ACT4Q2_SetQuestCompleted(D2GameStrc* pGame, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pUnit)
{
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 26, 0);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, 26);
    if (!pGame->bExpansion)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 6);
        QUESTRECORD_SetQuestState(pQuestFlags, 26, 7);
        CLIENTS_UpdateCharacterProgression(UnitGetClient(pUnit, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 592), 4, pGame->nDifficulty);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData)
    {
        ++((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->nPlayerCount;
    }
}

// 0x005B4DA0
void __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 3)
    {
        return;
    }

    ACT4Q2_SetQuestCompleted(pGame, pQuestFlags, pUnit);
}

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

// 0x005B4DF0
int __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT4Q2_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

// 0x005B4E40
int __fastcall ACT4Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 26, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 26, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 23);
    }
    return 0;
}

// 0x005B4EA0
void __fastcall ACT4Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    int nNewLevel = pQuestArg->nNewLevel;
    if (pQuestArg->nOldLevel == 103 && pQuestData->fState == 2)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1)
            return;
        if (pQuestData->fState < 3)
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 687);
        if (pQuestData->fLastState < 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, false);
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
    }
    if (nNewLevel == 108 && pQuestData->bNotIntro)
    {
        if (pQuestData->fState < 3)
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 703);
        if (pQuestData->fLastState < 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, true);
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q2_UnitIterate_UpdateQuestStateFlags);
    }
}

// 0x005B4F90
void __fastcall ACT4Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != 0x16F)
    {
        return;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bTalkedToTyrael == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bTalkedToTyrael = 0;
    }

    if (pQuestData->pGame->bExpansion && pQuestDataEx->bSpawnPortalToAct5Pending && !pQuestDataEx->bPortalToAct5Spawned)
    {
        ACT4Q2_SpawnPortalToHarrogath(pQuestArg, pQuestDataEx);
    }
}


// 0x005B4FF0
void __stdcall ACT4Q2_ActivateHarrogathWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    unsigned short nWpNo;
    if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_HARROGATH, &nWpNo))
    {
        D2WaypointDataStrc* pWaypointData = UNITS_GetPlayerData(pPlayer)->pWaypointData[pGame->nDifficulty];
        WAYPOINTS_ActivateWaypoint(pWaypointData, nWpNo);
    }
}

inline D2BitBufferStrc* ACT4Q2_GetQuestFlagsInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B5030
void __fastcall ACT4Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    if (!pGame->bExpansion)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5) && !QUESTRECORD_GetQuestState(pQuestFlags, 28, QFLAG_REWARDGRANTED))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5);
    }
}

// 0x005B5080
void __fastcall ACT4Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = ACT4Q2_GetQuestFlagsInline(pQuestArg->pGame, pQuestArg->pPlayer);

    if (pQuestArg->pGame->bExpansion && QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5) && !QUESTRECORD_GetQuestState(pQuestFlags, 28, QFLAG_REWARDGRANTED))
    {
        QUESTRECORD_ClearQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_CUSTOM5);
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_COMPLETEDBEFORE))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_ENTERAREA) == 1)
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_LEAVETOWN) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q2, QFLAG_STARTED) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005B54C0
void __fastcall ACT4Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = ACT4Q2_Callback08_MonsterKilled;
    pQuestData->pCallback[QUESTEVENT_CHANGEDLEVEL] = ACT4Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[QUESTEVENT_NPCACTIVATE] = ACT4Q2_Callback00_NpcActivate;
    pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = ACT4Q2_Callback02_NpcDeactivate;
    pQuestData->pCallback[QUESTEVENT_SCROLLMESSAGE] = ACT4Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[QUESTEVENT_PLAYERSTARTEDGAME] = ACT4Q2_Callback13_PlayerStartedGame;
    pQuestData->pCallback[QUESTEVENT_PLAYERJOINEDGAME] = ACT4Q2_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct4Q2NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->eFilter = QUESTSTATEFLAG_A4Q2;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT4Q2_ActiveFilterCallback;

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 1048, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfSeqFilter = ACT4Q2_SeqCallback;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest2Strc));
}

// 0x005B52E0
void __fastcall ACT4Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (UNIT_CLASSID_OR_INVALID(pQuestArg->pTarget) != 243)
    {
        ++pQuestDataEx->nBossesKilled;
        if (pQuestDataEx->nBossesKilled != 3)
        {
            return;
        }

        for (int i = 0; i < 5; ++i)
        {
            if (!pQuestDataEx->bSealActivated[i])
            {
                return;
            }
        }

        ACT4Q2_KillAllMonstersInCS(pQuestData->pGame, pQuestDataEx);
        if (pQuestDataEx->bTimerCreated)
        {
            return;
        }

        pQuestDataEx->dwTickCount = 0;
        pQuestDataEx->bNeedToSpawnDiablo = 1;
        pQuestDataEx->bEndGameTimerActive = 0;
        pQuestDataEx->bTimerCreated = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
        return;
    }
    if (!pQuestData->pGame->bExpansion)
    {
        QUESTS_TriggerFX(pQuestData->pGame, 13);
    }

    pQuestDataEx->bDiabloKilled = 1;
    bool bQuestNotDone = false;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
    if (!pRoom)
    {
        return;
    }

    pQuestDataEx->pRoom = pRoom;
    if (pQuestArg->pPlayer)
    {
        if (!((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bTimerCreated)
        {
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToSpawnDiablo = 0;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bEndGameTimerActive = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToEndGame = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bNeedToWarpPlayers = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bClientsSaved = 0;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bTimerCreated = 1;
            ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->dwTickCount = GetTickCount();
            QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
        }

        if (!pQuestData->bNotIntro)
        {
            return;
        }

        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0))
        {
            bQuestNotDone = true;
        }
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    pQuestDataEx->nPlayerCount = 0;
    QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q2_UnitIterate_StatusCyclerEx, 1);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_UpdatePlayerState);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_SetCompletionFlag);
    SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q2_UnitIterate_AttachCompletionSound);
    if (!bQuestNotDone)
    {
        return;
    }

    for (int i = 0; i < pQuestDataEx->nPlayerCount; ++i)
    {
        D2Game_10034_Return(pQuestData, pQuestArg, 0x40);
    }
}

struct D2GameStrc;

struct D2UnitStrc;

// 0x005B5140
int __fastcall ACT4Q2_UnitIterate_UpdatePlayerState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) == 1)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    int bInRange = 0;
    if (pRoom == pQuestDataEx->pRoom)
    {
        bInRange = 1;
    }
    else
    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pQuestDataEx->pRoom)
            {
                bInRange = 1;
                break;
            }
        }
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 1) && bInRange)
    {
        ACT4Q2_SetQuestCompleted(pGame, pQuestFlags, pUnit);
    }

    return 0;
}

// 0x005B5210
extern "C" unsigned int __fastcall ACT4Q2_IsChaosSanctumCleared(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x17);
    if (pQuestData)
        return ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bSanctumCleared;
    return 0;
}

// 0x005B5230
static void __stdcall ACT4Q2_KillAllMonstersInCS(D2GameStrc* pGame, D2Act4Quest2Strc* pQuestDataEx)
{
    if (pQuestDataEx->bSanctumCleared)
    {
        return;
    }

    pQuestDataEx->bSanctumCleared = 1;
    QUESTS_TriggerFX(pGame, 12);

    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[3]); pRoom; pRoom = pRoom->pRoomNext)
    {
        if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_CHAOSSANCTUM)
        {
            D2UnitStrc* pNext = 0;
            for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNext)
            {
                pNext = pUnit->ptRoomNext;
                if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwClassId != 243 && !SUNIT_IsDead(pUnit) && STATLIST_GetUnitAlignment(pUnit) == 0)
                {
                    D2ModeChangeStrc modeChange;
                    MONSTERMODE_GetModeChangeInfo(pUnit, 0, &modeChange);
                    D2GAME_ModeChange(pGame, &modeChange, 1);
                }
            }
        }
    }
}

// 0x005B5590
void __fastcall OBJECTS_InitFunction55_DiabloStartPoint(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bDiabloSpawned)
    {
        return;
    }

    pQuestDataEx->bDiabloStartPointInitialized = 1;
    pQuestDataEx->nDiabloStartPointObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    for (int nCounter = 0; nCounter < 5; ++nCounter)
    {
        if (!pQuestDataEx->bSealActivated[nCounter])
        {
            return;
        }
    }

    if (pQuestDataEx->nBossesKilled != 3)
    {
        return;
    }

    ACT4Q2_KillAllMonstersInCS(pOp->pGame, pQuestDataEx);
    if (pQuestDataEx->bTimerCreated)
    {
        return;
    }

    pQuestDataEx->dwTickCount = 0;
    pQuestDataEx->bNeedToSpawnDiablo = 1;
    pQuestDataEx->bEndGameTimerActive = 0;
    pQuestDataEx->bTimerCreated = 1;
    QUESTS_CreateTimer(pQuestData, (QUESTUPDATE)ACT4Q2_SpawnDiablo, 1);
}

// 0x005B5620
void __cdecl OBJECTS_InitFunction56_Unused()
{
}

// 0x005B5630
int __fastcall OBJECTS_OperateFunction52_DiabloSeal(D2ObjOperateFnStrc* pOp)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, 1);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 7) + pOp->pGame->dwGameFrame, 0, 0);

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
        if (!pQuestData)
        {
            return 0;
        }

        D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;

        switch (!pOp->hObject ? -1 : pOp->hObject->dwClassId)
        {
        case 392:
            pQuestDataEx->bSealActivated[0] = 1;
            break;
        case 393:
            pQuestDataEx->bSealActivated[1] = 1;
            break;
        case 394:
            pQuestDataEx->bSealActivated[2] = 1;
            break;
        case 395:
            pQuestDataEx->bSealActivated[3] = 1;
            break;
        case 396:
            pQuestDataEx->bSealActivated[4] = 1;
            break;
        default:
            break;
        }

        for (int nCounter = 0; nCounter < 5; ++nCounter)
        {
            if (!pQuestDataEx->bSealActivated[nCounter])
            {
                return 0;
            }
        }

        if (pQuestDataEx->nBossesKilled != 3)
        {
            return 0;
        }

        ACT4Q2_KillAllMonstersInCS(pOp->pGame, pQuestDataEx);
        if (pQuestDataEx->bTimerCreated)
        {
            return 0;
        }

        pQuestDataEx->dwTickCount = 0;
        pQuestDataEx->bNeedToSpawnDiablo = 1;
        pQuestDataEx->bEndGameTimerActive = 0;
        pQuestDataEx->bTimerCreated = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q2_SpawnDiablo, 1);
    }

    return 0;
}

// 0x005B5730
unsigned char __fastcall ACT4Q2_IsDiabloKilled(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData) return ((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bDiabloKilled;
    return 0;
}

// 0x005B5750
void __fastcall ACT4Q2_SpawnSealBoss(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc tCoords;
    UNITS_GetCoords(pUnit, &tCoords);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (!pQuestData)
    {
        return;
    }
    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    D2UnitStrc* pMonster;
    if (tCoords.nX == pQuestDataEx->pSealCoords[0].nX && tCoords.nY == pQuestDataEx->pSealCoords[0].nY)
    {
        pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->pSealCoords[0], 2, sgptDataTables->nSuperUniqueIds[36]);
    }
    else if (tCoords.nX == pQuestDataEx->pSealCoords[1].nX)
    {
        if (tCoords.nY == pQuestDataEx->pSealCoords[1].nY)
        {
            pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->pSealCoords[1], 2, sgptDataTables->nSuperUniqueIds[37]);
        }
        else if (tCoords.nX == pQuestDataEx->pSealCoords[2].nX && tCoords.nY == pQuestDataEx->pSealCoords[2].nY)
        {
            const int nMonId = sgptDataTables->nSuperUniqueIds[38];
            pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->pSealCoords[2], 2, nMonId);
        }
        else
        {
            return;
        }
        if (!pMonster)
        {
            EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 10, 0, 0);
        }
        return;
    }
    else if (tCoords.nX == pQuestDataEx->pSealCoords[2].nX && tCoords.nY == pQuestDataEx->pSealCoords[2].nY)
    {
        const int nMonId = sgptDataTables->nSuperUniqueIds[38];
        pMonster = QUESTS_SpawnMonster(pGame, pUnit, &pQuestDataEx->pSealCoords[2], 2, nMonId);
    }
    else
    {
        return;
    }
    if (!pMonster)
    {
        EVENT_SetEvent(pGame, pUnit, 7, pGame->dwGameFrame + 10, 0, 0);
    }
}

// 0x005B5810
int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame)
{
    if (pGame->bExpansion)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 23);
    if (pQuestData && !((D2Act4Quest2Strc*)pQuestData->pQuestDataEx)->bDiabloKilled)
    {
        return 0;
    }

    return 1;
}

// 0x005B5840
void __fastcall OBJECTS_InitFunction78_LastLastPortal(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A4Q2_DIABLO);
    if (!pQuestData)
    {
        return;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nLastLastPortalObjectMode != OBJMODE_OPENED)
    {
        pQuestDataEx->nLastLastPortalObjectMode = OBJMODE_OPENED;
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

// 0x005B5880
int __fastcall OBJECTS_OperateFunction73_LastLastPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2GameStrc* pGame = pOp->pGame;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pOp->hPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 26, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 26, 13))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hPlayer);
    if (!pRoom)
    {
        return 0;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != 3)
    {
        return 0;
    }

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 28, 0))
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 28, 0);
        QUESTRECORD_SetQuestState(pQuestFlags, 28, 13);

        D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q2.cpp", 1370);
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pOp->hPlayer);
        if (pClient && !PLAYER_IsBusy(pOp->hPlayer))
        {
            SUNIT_ResetInteractInfo(pOp->hPlayer);
            pPlayerData->bBusy = 1;

            D2GSPacketSrv5D packet5D = {};
            packet5D.nHeader = 0x5D;
            packet5D.nQuestId = 23;
            packet5D.nFlags = 2;
            SCMD_SendPacket0x5D(pClient, &packet5D);
            D2GAME_PACKETS_SendPacket0x61(pClient, 5);
        }
    }

    D2GAME_PlayerChangeAct(pOp->pGame, pOp->hPlayer, 109, 5);
    QUESTS_UpdatePlayerFlags(pOp->pGame, pOp->hPlayer);
    ACT4Q2_ActivateHarrogathWaypoint(pOp->pGame, pOp->hPlayer);
    return 0;
}

static int GetAnimMode(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

// 0x005B6AD0
static void ACT4Q2_SpawnSealObject(D2ObjOperateFnStrc* pOp, D2CoordStrc* pCoord, int nSeal)
{
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pOp->hObject), pCoord->nX, pCoord->nY);
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc* pNewRoom = 0;
    QUESTS_GetFreePosition(pRoom, pCoord, 3, 0x3F11, &pNewRoom, nSeal == 1 ? 13 : (nSeal == 3 ? 14 : 15), 100);
    if (pNewRoom && SUNIT_AllocUnitData(2, 131, pCoord->nX, pCoord->nY, pOp->pGame, pNewRoom, 1, 0, 0))
    {
        DUNGEON_ToggleHasPortalFlag(pNewRoom, 0);
        OBJECTS_OperateFunction52_DiabloSeal(pOp);
    }
}

// 0x005B6B70
int __fastcall OBJECTS_OperateFunction54_DiabloSeal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (GetAnimMode(pOp->hObject) != 0)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc* pCoord = &pQuestDataEx->pSealCoords[0];
    UNITS_GetCoords(pOp->hObject, pCoord);
    pQuestDataEx->pSealCoords[0].nX -= 12;
    pQuestDataEx->pSealCoords[0].nY -= 52;
    ACT4Q2_SpawnSealObject(pOp, pCoord, 1);
    return 0;
}

// 0x005B6BC0
int __fastcall OBJECTS_OperateFunction55_DiabloSeal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (GetAnimMode(pOp->hObject) != 0)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc* pCoord = &pQuestDataEx->pSealCoords[1];
    UNITS_GetCoords(pOp->hObject, pCoord);
    pQuestDataEx->pSealCoords[1].nX -= 39;
    pQuestDataEx->pSealCoords[1].nY += 33;
    ACT4Q2_SpawnSealObject(pOp, pCoord, 3);
    return 0;
}

// 0x005B6C10
int __fastcall OBJECTS_OperateFunction56_DiabloSeal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (GetAnimMode(pOp->hObject) != 0)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 23);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest2Strc* pQuestDataEx = (D2Act4Quest2Strc*)pQuestData->pQuestDataEx;
    D2CoordStrc* pCoord = &pQuestDataEx->pSealCoords[2];
    UNITS_GetCoords(pOp->hObject, pCoord);
    pQuestDataEx->pSealCoords[2].nX += 32;
    pQuestDataEx->pSealCoords[2].nY += 16;
    ACT4Q2_SpawnSealObject(pOp, pCoord, 5);
    return 0;
}

