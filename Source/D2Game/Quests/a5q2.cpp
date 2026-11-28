#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Drlg.h"
#include "D2GameTypes.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2Packets.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM7 11

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

#define ACT_III 2

#define QUESTSTATEFLAG_A1Q1 1

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct Obj005452C0;

struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2Act5Quest2Strc;

struct D2Act1Quest1Strc;

struct D2ObjInitFnStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2QuestDataStrc;

struct D2QuestArgStrc;

struct D2ActiveRoomStrc;

typedef int (__stdcall* FARPROC)();

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern unsigned int gdwAct5Q2RuneCodes[3]; // 0x00732FEC

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2ClientApi.h"

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0



int __fastcall ACT5Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587A90

extern "C" int __fastcall QUESTS_CheckPlayerGUID(Obj005452C0* pObj, unsigned int dwValue); // 0x005452C0


typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nQuestId);


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern char gpAct5Q2NpcMessages[]; // 0x00733940

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430


void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20



void __fastcall ACT5Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587A30

void __fastcall ACT5Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587B00

void __fastcall ACT5Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587D30

void __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587E60

void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00587F20

int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00587F60

bool __fastcall ACT5Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x00588340

void __fastcall ACT5Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00588040

void __fastcall ACT5Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT5Q2_SeqCallback(D2QuestDataStrc* pQuestData);

void __fastcall ACT5Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT5Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

static inline void ACT5Q2_CountWussieKill(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit);

struct D2ActiveRoomUnitsStrc;

struct D2ActiveRoomUnitsStrc
{
    char unk0x00[0x74];
    D2UnitStrc* pUnitFirst;
};

typedef int (__fastcall* QUESTUNITITERATEFN)(D2GameStrc*, D2UnitStrc*, void*);

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00587D30
void __fastcall ACT5Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestData->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int nRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int nPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        return;
    }

    if (QUESTS_CheckPlayerGUID((Obj005452C0*)pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        return;
    }

    if (nRewardGranted == 1)
    {
        return;
    }

    const unsigned char nState = pQuestData->fState;
    if ((nState >= 4 && !nPrimaryGoalDone) || !pQuestData->bNotIntro)
    {
        return;
    }

    const unsigned int nIndex = gnA5Q2NpcActivateIndices[nState];
    if (gnA5Q2NpcActivateIndices[nState] == 2 && nNpcId == 0x203)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 4))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 0x203, 5);
            return;
        }
        goto send;
    }

    if (nIndex != -1 && nIndex < 12)
    {
send:
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00587E60
void __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2BitBufferStrc* pQuestFlags = pPlayerData->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) == 1)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 4)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 0xD);
    QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 1);

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x20);
    D2Act5Quest2Strc* const pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->nFreedWussies == 15)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 5);
    }
    else if (pQuestDataEx->nFreedWussies == 14)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 6);
    }
    else
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 7);
    }
}

// 0x00587F20
void __fastcall ACT1Q1_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
    D2Act1Quest1Strc* pQuestDataEx = (D2Act1Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->pQuestGUID, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
}

// 0x00587F60
int __fastcall ACT5Q2_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0xD) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 0xE);
        QUESTS_SendLogUpdateEx(pUnit, 0x20, 0);
    }

    return 0;
}


// 0x00588010
static inline void ACT5Q2_CountWussieKill(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    const int nIndex = ACT5Q2_GetWussieGroupIndex(pQuestData, pUnit);
    if (nIndex >= 0)
    {
        D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nGroupKills[nIndex] += 1;
        if (pQuestDataEx->nGroupKills[nIndex] >= 5)
        {
            pQuestDataEx->bGroupDone[nIndex] = 1;
        }
    }
}

// 0x00588450
void __fastcall ACT5Q2_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, 36, 4);
}

// 0x00587FC0
int __fastcall ACT5Q2_GetWussieGroupIndex(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    const int nGUID = !pUnit ? -1 : pUnit->dwUnitId;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            if (nGUID == pQuestDataEx->nWussieGUIDs[i][j])
            {
                return i;
            }
        }
    }

    return -1;
}

// 0x00588600
int __fastcall ACT5Q2_SpawnCagedWussies(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp, int nCount)
{
	int nWussiesSpawned = 0;
	if (pQuestData && pQuestData->bNotIntro)
	{
		for (int i = 0; i < 25; ++i)
		{
			D2UnitStrc* pWussies = D2GAME_SpawnMonster(pQuestData->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_ACT5POW, 1, 5, 0);
			if (pWussies)
			{
				pWussies->dwFlags |= 0x3000000;

				D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
				pQuestDataEx->nWussieGUIDs[nCount][nWussiesSpawned] = !pWussies ? -1 : pWussies->dwUnitId;
				++nWussiesSpawned;

				QUESTS_CreateChainRecord(pQuestData->pGame, pWussies, 32);
				if (nWussiesSpawned >= 5)
				{
					break;
				}
			}
		}
	}

	return nWussiesSpawned;
}


// 0x00588510
void __fastcall ACT5Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[10] = ACT1Q1_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT5Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT5Q2_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT5Q2_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT5Q2_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT5Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT5Q2_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT5Q2_Callback14_PlayerJoinedGame;
    pQuestData->pNPCMessages = gpAct5Q2NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act5Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 803, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->eFilter = 36;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT5Q2_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT5Q2_SeqCallback;
    pQuestData->nSeqId = 33;
    memset(pQuestDataEx, 0x00, sizeof(D2Act5Quest2Strc));
    QUESTS_ResetPlayerGUIDCount((D2QuestGUIDStrc*)pQuestDataEx->tPlayerGUIDs);
}

// 0x00587A90
int __fastcall ACT5Q2_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x20);
    if (!pQuestData)
    {
        return 0;
    }

    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 2);
    }
    else if (pQuestData->fState == 3)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 0x24, 3);
    }

    return 0;
}

// 0x00587B00
void __fastcall ACT5Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    const short nMessageIndex = pQuestArg->nMessageIndex;

    if (pQuestArg->nNPCNo != 0x203)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestData->pGame, pQuestArg->pPlayer);

    if (nMessageIndex == 20096)
    {
        pQuestDataEx->bQualKehkActivated = 1;
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x100);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 20110)
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            {
                bool bRewardGranted = false;

                if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13))
                {
                    if (pQuestData->fState != 5)
                    {
                        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x128);
                        if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
                        {
                            FOG_DisplayHalt("", sub_00408090(), 0x129);
                            exit(-1);
                        }
                        pQuestData->pfSeqFilter(pQuestData);

                        pQuestData->nStatusFlags = 0;
                        QUESTS_UnitIterate(pQuestData, 13, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 0);
                    }
                    pQuestData->pCallback[2] = 0;
                }

                int nRewards = 3;
                if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 6))
                {
                    nRewards = 2;
                }
                else if (QUESTRECORD_GetQuestState(pQuestFlags, 0x24, 7))
                {
                    nRewards = 1;
                }

                if (nRewards > 0)
                {
                    for (int i = 0; i < nRewards; ++i)
                    {
                        if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, gdwAct5Q2RuneCodes[i], 0, 2, 1))
                        {
                            bRewardGranted = true;
                        }
                    }

                    if (bRewardGranted)
                    {
                        QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, 0);
                        QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, 1);
                        QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->eFilter);

                        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

                        D2GSPacketSrv5D packet5D = {};
                        packet5D.nHeader = 0x5D;
                        packet5D.nQuestId = 0x20;
                        packet5D.nFlags = 2;
                        SCMD_SendPacket0x5D(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 0x14E), &packet5D);
                    }
                }
            }

            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
}

// 0x00588040
void __fastcall ACT5Q2_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2UnitStrc* pTarget = pQuestArg->pTarget;
    if (pTarget && pTarget->dwClassId == 0x1B2)
    {
        DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pTarget), 0);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pQuestArg->pTarget);
        if (pRoom)
        {
            D2ActiveRoomStrc** ppRooms;
            int nRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            for (unsigned int i = 0; i < nRooms; ++i)
            {
                for (D2UnitStrc* pUnit = ((D2ActiveRoomUnitsStrc*)ppRooms[i])->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
                {
                    if ((!pUnit ? 6 : pUnit->dwUnitType) == 1 && pUnit->dwClassId == 0x216 && pUnit->dwAnimMode != 12 && pUnit->dwAnimMode != 0
                        && DRLG_UnitEdgeDistance(pUnit, pQuestArg->pTarget) < 15)
                    {
                        pQuestDataEx->nFreedWussieUnitGUIDs[pQuestDataEx->nWussiesInRangeToDoor] = !pUnit ? -1 : pUnit->dwUnitId;
                        ++pQuestDataEx->nWussiesInRangeToDoor;
                        ++pQuestDataEx->nFreedWussies;
                    }
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < pQuestDataEx->nWussiesInRangeToDoor; ++i)
        {
            if ((!pTarget ? -1 : pTarget->dwUnitId) == pQuestDataEx->nFreedWussieUnitGUIDs[i])
            {
                ACT5Q2_CountWussieKill(pQuestData, pTarget);
                return;
            }
        }

        ++pQuestDataEx->nKilledWussies;
    }

    if (pQuestDataEx->nKilledWussies >= 5 && pQuestData->fLastState != 12)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 12, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestDataEx->bQualKehkActivated = 0;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, pQuestArg->pPlayer, ACT5Q2_UnitIterate_SetCompletionFlag);
    }

    const int nGroup = ACT5Q2_GetWussieGroupIndex(pQuestData, pQuestArg->pTarget);
    if (nGroup >= 0)
    {
        D2Act5Quest2Strc* pGroupData = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        ++pGroupData->nGroupKills[nGroup];
        if (pGroupData->nGroupKills[nGroup] >= 5)
        {
            pGroupData->bGroupDone[nGroup] = 1;
        }
    }
}

// 0x00588200
void __fastcall ACT5Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    switch (pQuestArg->nNewLevel)
    {
    case 111:
    case 112:
        if (!pQuestData->bNotIntro || ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
        {
            break;
        }

        bool bWasStarted = false;
        if (pQuestData->fState == 1 || pQuestData->fState == 2)
        {
            QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 632);
            bWasStarted = true;
        }

        if (!pQuestData->fLastState)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
            pQuestData->pCallback[2] = 0;
        }
        else if (!bWasStarted)
        {
            return;
        }
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        return;
    }

    if (nOldLevel == 109)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
        if (pQuestData->fState != 2)
        {
            return;
        }

        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 660);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT5Q2_UnitIterate_UpdateQuestStateFlags);
        if (pQuestData->fLastState || !pQuestData->bNotIntro || ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
        {
            return;
        }

        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestData->pCallback[2] = 0;
    }
}

// 0x00588340
bool __fastcall ACT5Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == MONSTER_QUAL_KEHK)
    {
        if (pQuest->fState == 1)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
            {
                return true;
            }

            return false;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }
    else if (nNpcId == MONSTER_ACT5POW)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q2, QFLAG_REWARDGRANTED) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A5Q2, QFLAG_REWARDPENDING))
        {
            return true;
        }
    }

    return false;
}

// 0x005883E0
bool __fastcall ACT5Q2_SeqCallback(D2QuestDataStrc* pQuestData)
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
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 717);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x00588470
void __fastcall ACT5Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    QUESTRECORD_ClearQuestState(pQuestFlags, pQuestData->eFilter, 4);

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1) == 1)
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005886A0
void __fastcall OBJECTS_InitFunction62_CagedWussie(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A5Q2_RESCUESOLDIERS);
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    if (pQuestData->fState < 2)
    {
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a5q2.cpp", 860);
    }

    if (!pQuestData->fLastState && pQuestDataEx->nKilledWussies < 5)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
    }

    for (int nCounter = 0; nCounter < 3; ++nCounter)
    {
        if (!pQuestDataEx->bWussiesSpawned[nCounter])
        {
            for (int i = 0; i < nCounter; ++i)
            {
                if (pQuestDataEx->pWussieCoords[i].nX == pOp->nX && pQuestDataEx->pWussieCoords[i].nY == pOp->nY)
                {
                    return;
                }
            }

            pQuestDataEx->pWussieCoords[nCounter].nX = pOp->nX;
            pQuestDataEx->pWussieCoords[nCounter].nY = pOp->nY;
            pQuestDataEx->nSpawnedWussies += ACT5Q2_SpawnCagedWussies(pQuestData, pOp, nCounter);
            pQuestDataEx->bWussiesSpawned[nCounter] = 1;
            pQuestDataEx->bPortalAttempted[nCounter] = 0;
            return;
        }
    }
}

// 0x005887A0
int __fastcall ACT5Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 36, 13))
    {
        const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
        if (nPartyId != 0xFFFF)
        {
            PARTY_IteratePartyMembers(pGame, nPartyId, ACT5Q2_UnitIterate_SetPrimaryGoalDone, 0);
        }
    }

    return 0;
}

// 0x005887F0
int __fastcall ACT5Q2_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 36, 13))
    {
        SUNIT_AttachSound(pUnit, 81, pUnit);
    }

    return 0;
}

// 0x00588830
int __fastcall ACT5Q2_CheckWussieCounters(D2GameStrc* pGame, D2UnitStrc* pWussie)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q2_RESCUESOLDIERS);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    const int nIndex = ACT5Q2_GetWussieGroupIndex(pQuestData, pWussie);
    if (nIndex >= 0 && ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nGroupKills[nIndex])
    {
        return 1;
    }

    return 0;
}

// 0x00588880
void __fastcall ACT5Q2_UpdateWussieCounters(D2GameStrc* pGame, int nUnused, D2UnitStrc* pWussie)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return;
    }

    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    int nIndex = ACT5Q2_GetWussieGroupIndex(pQuestData, pWussie);
    if (nIndex >= 0)
    {
        pQuestDataEx->nGroupKills[nIndex] += 1;
        if (pQuestDataEx->nGroupKills[nIndex] >= 5)
        {
            pQuestDataEx->bGroupDone[nIndex] = 1;
        }
    }
}

struct D2CoordStrc;

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230


static inline int FreedCount(D2Act5Quest2Strc* pEx) { return pEx->nFreedWussies; }

static inline int UnitId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }

// 0x005888D0
void __fastcall ACT5Q2_SpawnRescuePortal(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pTarget)
{
 D2QuestDataStrc* pQuestData=QUESTS_GetQuestData(pGame,32);
 if(!pQuestData) return;
 D2Act5Quest2Strc* pQuestDataEx= (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
 int nIndex=ACT5Q2_GetWussieGroupIndex(pQuestData,pTarget);
 if(nIndex<0 || pQuestDataEx->bPortalAttempted[nIndex]==1) return;
 else
 {
     D2CoordStrc tCoords;
     tCoords.nX=pQuestDataEx->pWussieCoords[nIndex].nX+12;
     tCoords.nY=pQuestDataEx->pWussieCoords[nIndex].nY;
     D2ActiveRoomStrc* pTargetRoom=UNITS_GetRoom(pTarget);
     D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
     bool bFound=false;
     if(!pRoom) return;
     D2ActiveRoomStrc** ppRooms;
     int nRooms;
     DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRooms,&nRooms);
     for(unsigned int i=0;i<(unsigned int)nRooms;++i)
     {
      D2UnitStrc* pUnit=ppRooms[i]->pUnitFirst;
      while(pUnit)
      {
       if((!pUnit ? 6 : pUnit->dwUnitType)==1 && pUnit->dwClassId==434 && pUnit->dwAnimMode==12 && DRLG_UnitEdgeDistance(pUnit,pTarget)<15) break;
       pUnit=pUnit->ptRoomNext;
      }
      if(pUnit)
      {
       pTargetRoom=UNITS_GetRoom(pUnit);
       UNITS_GetCoords(pUnit,&tCoords);
       tCoords.nX+=2;
       bFound=true;
      }
     }
     if(!bFound) return;
     pQuestDataEx->bPortalAttempted[nIndex]=1;
     pRoom=sub_00463740_FindRoomAtPoint(pTargetRoom,tCoords.nX,tCoords.nY);
     D2UnitStrc* pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX,tCoords.nY,pQuestData->pGame,pRoom,1,1,0);
     if(!pPortal)
     {
      pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX-2,tCoords.nY,pQuestData->pGame,pRoom,1,1,0);
      if(!pPortal && pRoom)
      {
       D2ActiveRoomStrc* pFreeRoom=pRoom;
       QUESTS_GetFreePosition(pRoom,&tCoords,2,0x8000,&pFreeRoom,17,100);
       if(pFreeRoom)
        pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX,tCoords.nY,pQuestData->pGame,pFreeRoom,1,1,0);
       else
        pPortal=SUNIT_AllocUnitData(2,189,tCoords.nX,tCoords.nY,pQuestData->pGame,pRoom,1,1,0);
      }
     }
     if(pPortal)
     {
      pQuestDataEx->bPortalSpawned[nIndex]=1;
      pQuestDataEx->nPortalGUIDs[nIndex]=UnitId(pPortal);
      EVENT_SetEvent(pQuestData->pGame,pPortal,7,pQuestData->pGame->dwGameFrame+25,0,0);
      DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pPortal),0);
     }
     D2BitBufferStrc* pQuestFlags=PLAYER_GetQuestFlags(pGame,pPlayer);
     if(pQuestDataEx->nSpawnedWussies==pQuestDataEx->nKilledWussies+pQuestDataEx->nFreedWussies && pQuestDataEx->bWussiesSpawned[0] && pQuestDataEx->bWussiesSpawned[1] && pQuestDataEx->bWussiesSpawned[2])
     {
      if(pQuestDataEx->nFreedWussies>11)
      {
       pQuestData->nStatusFlags = 0;
       QUESTS_UnitIterate(pQuestData,3,0,ACT5Q2_UnitIterate_StatusCyclerEx,true);
       if(!QUESTRECORD_GetQuestState(pQuestFlags,36,0) && !QUESTRECORD_GetQuestState(pQuestFlags,36,1))
       {
        QUESTRECORD_SetQuestState(pQuestFlags,36,13);
        QUESTRECORD_SetQuestState(pQuestFlags,36,1);
        const int nFreed = FreedCount(pQuestDataEx);
        if(nFreed==15) QUESTRECORD_SetQuestState(pQuestFlags,36,5);
        else if(nFreed==14) QUESTRECORD_SetQuestState(pQuestFlags,36,6);
        else QUESTRECORD_SetQuestState(pQuestFlags,36,7);
       }
       SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
       SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_SetCompletionFlag);
       SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_AttachCompletionSound);
      }
      else SUNIT_IterateUnitsOfType(pGame,0,pPlayer,ACT5Q2_UnitIterate_SetCompletionFlag);
     }
     else
     {
      QUESTRECORD_SetQuestState(pQuestFlags,36,4);
      if(pQuestDataEx->nKilledWussies<5)
      {
       pQuestData->nStatusFlags = 32;
       QUESTS_UnitIterate(pQuestData,2,0,ACT5Q2_UnitIterate_StatusCyclerEx,true);
      }
      pQuestDataEx->bQualKehkActivated=0;
     }
 }
}

// 0x00588C50
int __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData)
{
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;

    int nBarbs = 0;
    for (int i = 0; i < 3; ++i)
    {
        if (!pQuestDataEx->bWussiesSpawned[i])
        {
            nBarbs += 5;
        }
    }

    nBarbs += pQuestDataEx->nSpawnedWussies - pQuestDataEx->nFreedWussies - pQuestDataEx->nKilledWussies;
    if (nBarbs < 0)
    {
        nBarbs = 0;
    }

    return nBarbs;
}
// 0x00588CA0
void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pPortal)
{
    const int nUnitGUID = !pPortal ? -1 : pPortal->dwUnitId;
    int nCounter = 0;
    do
    {
        if (nUnitGUID == ((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nPortalGUIDs[nCounter])
        {
            goto found;
        }
        ++nCounter;
    }
    while (nCounter < 3);
    return;

found:
    D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
    switch (!pPortal ? 0 : pPortal->dwAnimMode)
    {
    case 1:
        UNITS_ChangeAnimMode(pPortal, 2);
        break;

    case 2:
        if (pQuestDataEx->bGroupDone[nCounter] == 1)
        {
            ++pQuestDataEx->nPortalUpdateInvocations[nCounter];
        }
        if (pQuestDataEx->nPortalUpdateInvocations[nCounter] > 5)
        {
            pQuestDataEx->bChangeToSpecialObjectMode[nCounter] = 1;
        }
        if (pQuestDataEx->bChangeToSpecialObjectMode[nCounter])
        {
            UNITS_ChangeAnimMode(pPortal, 3);
        }
        break;

    case 3:
        UNITS_ChangeAnimMode(pPortal, 4);
        break;
    }

    EVENT_SetEvent(pQuestData->pGame, pPortal, 7, pQuestData->pGame->dwGameFrame + 25, 0, 0);
}

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

// 0x00588D60
int __fastcall ACT5Q2_FindPortal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppPortal)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
    if (pQuestData)
    {
        D2Act5Quest2Strc* pQuestDataEx = (D2Act5Quest2Strc*)pQuestData->pQuestDataEx;
        int nIndex = ACT5Q2_GetWussieGroupIndex(pQuestData, pUnit);
        if (nIndex >= 0 && pQuestDataEx->bPortalSpawned[nIndex])
        {
            D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, pQuestDataEx->nPortalGUIDs[nIndex]);
            if (pPortal)
            {
                *ppPortal = pPortal;
                return 1;
            }
        }
    }

    return 0;
}

// 0x00588DD0
void __fastcall ACT5Q2_OnWussieActivated(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A5Q2_RESCUESOLDIERS);

    if (!pQuestData || !pQuestData->bNotIntro || pQuestData->fLastState == 5)
    {
        return;
    }

    if (((D2Act5Quest2Strc*)pQuestData->pQuestDataEx)->nKilledWussies >= 5)
    {
        return;
    }

    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 5, 0, ACT5Q2_UnitIterate_StatusCyclerEx, 1);
}

D2ClientStrc* __fastcall sub_00539070_GetFirstClient(D2GameStrc* pGame); // 0x00539070


// 0x00588E10
int __fastcall ACT5Q2_IsMonsterNearby(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pDefault)
{
    if (!pUnit)
    {
        if (pGame->nGameType == 3)
        {
            D2ClientStrc* pClient = sub_00539070_GetFirstClient(pGame);
            if (pClient)
            {
                pUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
            }
        }
        if (!pUnit)
        {
            pUnit = pDefault;
        }
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        goto NotFound;
    }

    D2ActiveRoomStrc** ppRoomList;
    int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < (unsigned int)nNumRooms; ++i)
    {
        for (D2UnitStrc* pTarget = ppRoomList[i]->pUnitFirst; pTarget; pTarget = pTarget->ptRoomNext)
        {
            if ((!pTarget ? 6 : pTarget->dwUnitType) == 1 && (!pTarget ? -1 : pTarget->dwClassId) == 0x1B2 && (!pTarget ? 0 : pTarget->dwAnimMode) == 12)
            {
                return 1;
            }
        }
    }

NotFound:
    return 0;
}

