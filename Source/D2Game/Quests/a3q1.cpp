#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2GameTypes.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct D2PlayerDataStrc;
struct D2QuestGUIDStrc;
struct D2ObjInitFnStrc;
struct D2Act3Quest0Strc;
struct D2Act3Quest1Strc;
struct D2GameStrc;
struct D2UnitStrc;
struct D2MapAIStrc;
struct D2QuestArgStrc;
struct D2QuestDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef bool (__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


extern char gpAct3Q1NpcMessages[]; // 0x0073ECF0
void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640
#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc* pUnit, int nQuestId); // 0x005458E0
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630
D2MapAIStrc** __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000
D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B6F90
bool __fastcall ACT3Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B72B0
int __fastcall ACT3Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B73A0
int __fastcall ACT3Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B74E0
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7610
bool __fastcall ACT3Q1_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B7CD0
bool __fastcall ACT3Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B7D70
int __fastcall ACT3Q1_UnitIterate_AddStatPointReward(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
int __fastcall ACT3Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT3Q1_UnitIterate_CheckForTomeItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);
void __fastcall ACT3Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Q1_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Q1_Callback05_ItemDropped(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Q1_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);
void __fastcall ACT3Q1_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

enum { FINAL_STATE = 5 };


// 0x005B70B0
void __fastcall OBJECTS_InitFunction49_HratliStart(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 14);
    if (!pQuestData || QUESTS_GetGlobalState(pOp->pGame, 16, 13))
    {
        return;
    }

    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bHratliStartCreated && SUNIT_GetServerUnit(pOp->pGame, 1, pQuestDataEx->nHratliGUID))
    {
        return;
    }

    D2UnitStrc* pHratli = D2GAME_SpawnMonster(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_HRATLI, 1, -1, 0);
    if (pHratli)
    {
        pQuestDataEx->nHratliGUID = pHratli->dwUnitId;
        pQuestDataEx->bHratliStartCreated = 1;
    }
}


// 0x005B7120
int __fastcall ACT3Q1_GetHratliEndCoords(D2GameStrc* pGame, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 14);
    if (!pQuestData)
    {
        return 0;
    }
    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bHratliEndObjectInitialized != 1 || !pQuestDataEx->bHratliStartIsPresent)
    {
        return 0;
    }
    pCoord->nX = pQuestDataEx->nHratliX;
    pCoord->nY = pQuestDataEx->nHratliY;
    return 1;
}

// 0x005B7160
void __fastcall OBJECTS_InitFunction50_HratliEnd(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 14);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bHratliEndObjectInitialized = 1;
    pQuestDataEx->nHratliX = pOp->nX;
    pQuestDataEx->nHratliY = pOp->nY;

    if (!QUESTS_GetGlobalState(pOp->pGame, 16, 13) || pQuestDataEx->bHratliEndCreated)
    {
        return;
    }

    if (pQuestDataEx->bHratliStartCreated && SUNIT_GetServerUnit(pOp->pGame, 1, pQuestDataEx->nHratliGUID))
    {
        pQuestDataEx->bHratliStartIsPresent = 1;
        return;
    }

    D2UnitStrc* pHratli = D2GAME_SpawnMonster(pOp->pGame, pOp->pRoom, pOp->nX, pOp->nY, MONSTER_HRATLI, 1, -1, 0);
    if (!pHratli)
    {
        return;
    }

    pQuestDataEx->nHratliGUID = !pHratli ? -1 : pHratli->dwUnitId;
    pQuestDataEx->bHratliEndCreated = 1;
    pHratli->dwFlags |= 0x3000000;

    if (pQuestDataEx->pHratliMapAI && pQuestDataEx->pHratliMapAI->pPosition && !pQuestDataEx->bHratliMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pHratliMapAI, AIGENERAL_GetMapAiFromUnit(pHratli));
        pQuestDataEx->bHratliMapAIChanged = 1;
    }
}

// 0x005B7230
void __fastcall ACT3Q1_ChangeHratliMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 14);
    if (!pQuestData)
        return;
    D2Act3Quest0Strc* pQuestDataEx = (D2Act3Quest0Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->pHratliMapAI = pMapAI;
    if (!pQuestDataEx->bHratliEndCreated)
        return;
    D2UnitStrc* pHratli = SUNIT_GetServerUnit(pQuestData->pGame, 1, pQuestDataEx->nHratliGUID);
    if (pHratli && pQuestDataEx->pHratliMapAI && pQuestDataEx->pHratliMapAI->pPosition && !pQuestDataEx->bHratliMapAIChanged)
    {
        DRLGPRESET_ChangeMapAI(&pQuestDataEx->pHratliMapAI, AIGENERAL_GetMapAiFromUnit(pHratli));
        pQuestDataEx->bHratliMapAIChanged = 1;
    }
}

// 0x005B72A0
void __stdcall sub_005B72A0_Nop(int nUnused1)
{
}

// 0x005B72B0
bool __fastcall ACT3Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 254)
    {
        if (pQuest->fState == 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 15))
        {
            return true;
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' bbb'))
        {
            return true;
        }
    }

    return false;
}

// 0x005B7310
void __fastcall ACT3Q1_InitTomeObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (!pQuestData)
    {
        return;
    }
    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, ((D2Act3Quest1Strc*)pQuestData->pQuestDataEx)->nTomeObjectMode);
    }
}

inline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B7340
int __fastcall ACT3Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 17, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 17, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 15);
    }

    return 0;
}

#define QFLAG_PRIMARYGOALDONE 13

struct D2Act3Quest5Strc;

extern "C" const char gszAct3Q5SourceFile[];


// 0x005B73A0
int __fastcall ACT3Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) == 1)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 1) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 15);
    if (pQuestData)
    {
        switch (pQuestData->fState)
        {
        case 2:
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 2);
            break;

        case 3:
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 2);
            break;
        }
    }

    return 0;
}


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


extern int gnAct3Q1NpcMessageIndices[]; // 0x0073F188

// 0x005B7400
void __fastcall ACT3Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, 17, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, 17, 13);
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;

    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' bbb'))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (bRewardGranted == 1)
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
        }
    }
    else if (pQuestData->bNotIntro && pQuestData->fState < 4)
    {
        const int nIndex = gnAct3Q1NpcMessageIndices[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}


// 0x005B74E0
int __fastcall ACT3Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 17, 1) && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == 2)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 13);
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 17, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
        }
    }
    return 0;
}

// 0x005B7580
int __fastcall ACT3Q1_UnitIterate_AddStatPointReward(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 1) == 1)
    {
        STATLIST_AddUnitStat(pUnit, STAT_STATPTS, 5, 0);
        QUESTS_SendLogUpdate(pUnit, 15);
        QUESTRECORD_ClearQuestState(pQuestFlags, 17, 1);
    }

    return 0;
}

// 0x005B75D0
int __fastcall ACT3Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) != 1
        && QUESTRECORD_GetQuestState(pQuestFlags, 17, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 17, 14);
    }

    return 0;
}

// 0x005B7610
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}

// 0x005B7620
void __fastcall ACT3Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nOldLevel = pQuestArg->nOldLevel;
    if (pQuestArg->nNewLevel == 79 && pQuestData->bNotIntro && pQuestData->fState < 1)
    {
        pQuestData->fState = 1;
    }

    if (nOldLevel != 75)
    {
        return;
    }

    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestData->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1
        || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1)
    {
        return;
    }

    if (pQuestData->fLastState != 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q1_UnitIterate_StatusCyclerEx, 1);
    }
    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 358);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q1_UnitIterate_UpdateQuestStateFlags);
}

// 0x005B76E0
void __fastcall ACT3Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != 254)
    {
        return;
    }

    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bTomeBroughtToAlkor != 1)
    {
        return;
    }

    const int nUnitGUID = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
    if (nUnitGUID != pQuestDataEx->nPlayerWithTomeGUID)
    {
        return;
    }

    if (!pQuestArg->pPlayer || pQuestArg->pPlayer->dwClassId != 6 && pQuestArg->pPlayer->dwClassId != 5)
    {
        SUNIT_AttachSound(pQuestArg->pPlayer, 67, pQuestArg->pPlayer);
    }

    pQuestDataEx->bTomeBroughtToAlkor = 0;
}

// 0x005B7A60
int __fastcall OBJECTS_OperateFunction28_LamEsenTome(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 15);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    if (!pOp->hObject || pOp->hObject->dwAnimMode == 0)
    {
        D2GameStrc* pGame = pOp->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pOp->hPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) == 1)
        {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }

        pOp->hObject->dwDropItemCode = ' bbb';
        int nItemLevel;
        if (D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->hObject, 2);

            D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;
            pQuestDataEx->nTomesInGame += 1;
            pQuestDataEx->bTomeActive = 1;
            pQuestDataEx->bTomeDropped = 1;
            pQuestDataEx->nTomeObjectMode = 2;
            pQuestDataEx->nTomeGUID = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;

            pQuestData->pCallback[0] = ACT3Q1_Callback00_NpcActivate;
            pQuestData->pCallback[11] = ACT3Q1_Callback11_ScrollMessage;

            if (pQuestData->fState != 3)
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 699);
            }

            if (pQuestData->fLastState != 1)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q1_UnitIterate_StatusCyclerEx, false);
            }
        }
    }

    return 0;
}

// 0x005B7740
void __fastcall ACT3Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;
    const unsigned short nNpcNo = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);

    if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) == 1 || nNpcNo != 254)
    {
        return;
    }

    if (nMessageIndex == 549)
    {
        QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 417);
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q1_UnitIterate_StatusCyclerEx, 1);
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT3Q1_UnitIterate_UpdateQuestStateFlags);
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
    }
    else if (nMessageIndex == 564)
    {
        QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0))
        {
            return;
        }

        if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20626262))
        {
            QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20626262);
            pQuestDataEx->bTomeBroughtToAlkor = 1;
            pQuestDataEx->nPlayerWithTomeGUID = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
            pQuestData->pCallback[2] = ACT3Q1_Callback02_NpcDeactivate;
        }

        if (pQuestDataEx->bCanGetReward == 1)
        {
            SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q1_UnitIterate_SetPrimaryGoalDone);
            pQuestDataEx->bCanGetReward = 0;
            SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q1_UnitIterate_AddStatPointReward);
            SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT3Q1_UnitIterate_SetCompletionFlag);
        }

        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT3Q1_UnitIterate_StatusCyclerEx, 0);

        QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

        if (!QUESTRECORD_GetQuestState(pQuestFlags, 17, 13) || !pQuestData->bNotIntro)
        {
            return;
        }

        QUESTS_SetGlobalState(pQuestArg->pGame, 17, 13);
        if (pQuestData->fState == 5)
        {
            return;
        }

        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 457);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 458);
        pQuestData->pfSeqFilter(pQuestData);
    }
}

// 0x005B7970
void __fastcall ACT3Q1_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    QUESTS_DebugOutput(pQuestData->pGame, "tome acquired", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 609);
    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q1_UnitIterate_StatusCyclerEx, 1);
    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 620);

    QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x005B7A00
void __fastcall ACT3Q1_Callback05_ItemDropped(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;

    QUESTS_FastRemovePlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);

    if (pQuestData->bNotIntro)
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 641);
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005B7B80
void __fastcall ACT3Q1_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;

    --pQuestDataEx->nTomesInGame;

    if (!pQuestDataEx->nTomesInGame && pQuestData->bNotIntro && pQuestDataEx->bTomeActive && pQuestData->fState <= 3)
    {
        pQuestDataEx->bPlayerWithTomeDropped = 1;
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 8, 0, ACT3Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005B7BC0
void __fastcall ACT3Q1_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;

    if (!ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20626262))
    {
        return;
    }

    ++pQuestDataEx->nTomesInGame;
    if (pQuestDataEx->nTomesInGame == 1 && pQuestData->bNotIntro && pQuestDataEx->bPlayerWithTomeDropped)
    {
        pQuestDataEx->bPlayerWithTomeDropped = 0;
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q1_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005B7C10
void __fastcall ACT3Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = sub_00543520(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 17, 13);
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, 0x20626262))
    {
        pQuestData->fLastState = 2;
        pQuestData->fState = 4;

        D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuestData->pQuestDataEx;
        ++pQuestDataEx->nTomesInGame;
        pQuestDataEx->nTomeObjectMode = 2;
        pQuestDataEx->bTomeActive = 1;

        QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 17, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005B7CD0
bool __fastcall ACT3Q1_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != FINAL_STATE && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pNextQuestData = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pNextQuestData)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 808);
        return pNextQuestData->pfSeqFilter(pNextQuestData);
    }

    return false;
}

// 0x005B7D40
void __fastcall ACT3Q1_UnitIterate_CheckForTomeItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, 0x20626262))
    {
        ((D2Act3Quest1Strc*)QUESTS_GetQuestData(pGame, 15)->pQuestDataEx)->bTomeAcquired = 1;
    }
}


struct D2ActiveRoomStrc;

// 0x005B7E90
void __fastcall ACT3Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct3Q1NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->eFilter = 17;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = ACT3Q1_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q1_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q1_SeqCallback;
    pQuestData->nSeqId = 19;

    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q1.cpp", 941, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pCallback[4] = ACT3Q1_Callback04_ItemPickedUp;
    pQuestData->pCallback[5] = ACT3Q1_Callback05_ItemDropped;
    pQuestData->pCallback[0] = ACT3Q1_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q1_Callback13_PlayerStartedGame;
    pQuestData->pCallback[14] = ACT3Q1_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[9] = ACT3Q1_Callback09_PlayerDroppedWithQuestItem;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest1Strc));

    pQuestDataEx->bTomeDropped = 0;
    pQuestDataEx->bTomeActive = 0;
    pQuestDataEx->bCanGetReward = 1;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x005B7D70
bool __fastcall ACT3Q1_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
        return true;
    }

    if (QUESTRECORD_GetQuestState(pFlags, 17, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 17, 13) ? 13 : 11;
        return true;
    }

    *pStatus = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, 0x20626262))
    {
        *pStatus = 2;
        return true;
    }

    D2Act3Quest1Strc* pQuestDataEx = (D2Act3Quest1Strc*)pQuest->pQuestDataEx;
    unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId != 0xFFFF)
    {
        pQuestDataEx->bTomeAcquired = 0;
        PARTY_IteratePartyMembers(pQuest->pGame, nPartyId, ACT3Q1_UnitIterate_CheckForTomeItem, 0);
        if (pQuestDataEx->bTomeAcquired)
        {
            *pStatus = 2;
            return true;
        }
    }

    if (pQuest->bNotIntro)
    {
        if (pQuest->fState <= 3)
        {
            *pStatus = 1;
            if (pQuestDataEx->bTomeActive == 1 && !pQuestDataEx->nTomesInGame)
            {
                *pStatus = (pQuest->pGame->nGameType != 3) + 8;
                return true;
            }
        }
        else
        {
            *pStatus = 12;
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
            if (pRoom && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == 2 && pQuestDataEx->nTomesInGame)
            {
                *pStatus = 1;
            }
        }
    }

    return true;
}
