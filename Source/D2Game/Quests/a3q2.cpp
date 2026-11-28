#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2Packets.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define QFLAG_REWARDGRANTED 0

#define QFLAG_STARTED 2

#define QFLAG_CUSTOM3 7


#define ITEMQUAL_NORMAL 2

#define ITEMQUAL_MAGIC 4

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QUESTSTATEFLAG_A2COMPLETED 15

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM1 5

#define QFLAG_CUSTOM2 6

struct D2PoolSystemStrc;
union D2SeedStrc;

struct D2PlayerDataStrc;

struct D2Act3Quest2Strc;

struct D2ObjOperateFnStrc;

struct D2ObjInitFnStrc;

struct D2MonsterDataStrc;


struct D2QuestGUIDStrc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool (__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970



int __fastcall ACT3Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B7F90


void __fastcall ACT3Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8020






typedef int (__stdcall* FARPROC)();

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern char gpAct3Q2NpcMessages[]; // 0x0073F1A0

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

void __fastcall sub_005B7FE0_EmptyCallback(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7FE0

void __fastcall ACT3Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7FF0

void __fastcall ACT3Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8060

bool __fastcall ACT3Q2_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B8150

void __fastcall ACT3Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8210

void __fastcall ACT3Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B8470

bool __fastcall ACT3Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005BD500

void __fastcall ACT3Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BD630

bool __fastcall ACT3Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005BD850


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitId); // 0x00552F60


static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

// 0x005B7F90
int __fastcall ACT3Q2_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 15))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 16);
    }

    return 0;
}

// 0x005B7FE0
void __cdecl sub_005B7FE0_Nop()
{
}

// 0x005B7FF0
void __fastcall ACT3Q2_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNewLevel == 77 && pQuestData->bNotIntro && pQuestData->fState < 3)
    {
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 335);
    }
}

// 0x005B8020
void __fastcall ACT3Q2_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != MONSTER_CAIN3)
    {
        return;
    }

    if (((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->bInitiallyTalkedToCain == 1)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q2_UnitIterate_StatusCyclerEx, 1);
        pQuestData->pCallback[QUESTEVENT_NPCDEACTIVATE] = 0;
    }
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005B8060
void __fastcall ACT3Q2_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    const unsigned short nNPCNo = pQuestArg->nNPCNo;
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (nNPCNo == 245)
    {
        switch (nMessageIndex)
        {
        case 543:
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 504);
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 2);
            ((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->bInitiallyTalkedToCain = 1;
            pQuestData->pCallback[2] = ACT3Q2_Callback02_NpcDeactivate;
            break;

        case 545:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 3);
            break;

        case 544:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 6);
            break;

        case 546:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 4);
            break;

        case 547:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 5);
            break;

        case 548:
            QUESTRECORD_SetQuestState(pQuestFlags, 18, 7);
            break;

        default:
            return;
        }
    }
}

// 0x005B8150
bool __fastcall ACT3Q2_SeqCallback(D2QuestDataStrc* pQuestData)
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
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 539);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}

// 0x005B81C0
static void __stdcall ACT3Q2_SendKhalimPacket(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg, unsigned char nState)
{
    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nQuestId = QUEST_A3Q2_KHALIMFLAIL;
    packet5D.nFlags = (unsigned char)pQuestData->dwFlags;
    packet5D.nState = nState;
    SCMD_SendPacket0x5D(UnitGetClient(pQuestArg->pPlayer, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 568), &packet5D);
}

// 0x005BDA30
void __fastcall ACT3Q2_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->bActive = 1;
    pQuestData->fLastState = 1;
    pQuestData->pNPCMessages = gpAct3Q2NpcMessages;
    pQuestData->fState = 0;
    pQuestData->eFilter = 18;
    pQuestData->nInitNo = 0;
    pQuestData->pfStatusFilter = ACT3Q2_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q2_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q2_SeqCallback;
    pQuestData->nSeqId = 15;
    pQuestData->pCallback[0] = ACT3Q2_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q2_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q2_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q2_Callback13_PlayerStartedGame;
    pQuestData->pCallback[10] = sub_005B7FE0_EmptyCallback;
    pQuestData->pCallback[4] = ACT3Q2_Callback04_ItemPickedUp;

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest2Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q2.cpp", 923, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest2Strc));
    pQuestDataEx->nSewerStairsObjectMode = 0;
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x005BDB10
void __cdecl sub_005BDB10_Return()
{
}

// 0x005B8210
void __fastcall ACT3Q2_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2COMPLETED, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        return;
    }

    const unsigned int dwItemCode = ITEMS_GetBaseCode(pQuestArg->pTarget);

    bool bNoCustom1 = false;
    bool bNoCustom3 = false;
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_STARTED);
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_LEAVETOWN);
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_ENTERAREA);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM1))
    {
        bNoCustom1 = true;
    }
    QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM2);
    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM3))
    {
        bNoCustom3 = true;
    }

    bool bEyeAvailable = false;
    bool bHeartAvailable = false;
    bool bBrainAvailable = false;
    bool bBaseFlailAvailable = false;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 1fq'))
    {
        bBaseFlailAvailable = true;
    }

    ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 2fq');

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' yeq'))
    {
        bEyeAvailable = true;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rbq'))
    {
        bBrainAvailable = true;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' rhq'))
    {
        bHeartAvailable = true;
    }

    if (dwItemCode == ' 2fq')
    {
        if (pQuestData->fLastState)
        {
            pQuestData->fLastState = 7;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2COMPLETED, QFLAG_REWARDGRANTED))
        {
            return;
        }

        if (bNoCustom3)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 5);
        }
        else
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 6);
        }
    }
    else if (dwItemCode == ' 1fq')
    {
        if (!bEyeAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else if (!bBrainAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bHeartAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else if (bNoCustom1)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 5);
        }
        else
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' yeq')
    {
        if (!bBrainAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bBaseFlailAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bHeartAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' rhq')
    {
        if (!bBrainAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 2);
        }
        else if (!bBaseFlailAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bEyeAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
    else if (dwItemCode == ' rbq')
    {
        if (!bHeartAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 4);
        }
        else if (!bBaseFlailAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 3);
        }
        else if (!bEyeAvailable)
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 1);
        }
        else
        {
            ACT3Q2_SendKhalimPacket(pQuestData, pQuestArg, 7);
        }
    }
}

// 0x005B8470
void __fastcall ACT3Q2_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_REWARDGRANTED))
    {
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_CUSTOM3))
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 7;
    }
    else
    {
        if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q2, QFLAG_STARTED))
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 7;
        }

        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;

        if (pQuestDataEx->nEyesDropped + pQuestDataEx->nBrainsDropped + pQuestDataEx->nHeartsDropped + pQuestDataEx->nFlailsDropped)
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 7;
        }
    }
}

// 0x005B84E0
int __fastcall OBJECTS_OperateFunction44_SewerStairs(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->hObject;
    if (pObject && pObject->dwAnimMode == OBJMODE_OPENED)
    {
        D2GAME_WarpPlayerToTile(pOp);
    }
    return 0;
}

#define UNIT_OBJECT 2

#define EVENTTYPE_ENDANIM 1

#define QUEST_A3Q3_GIDBINN 17

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define QFLAG_COMPLETEDBEFORE 15

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

// 0x005B8500
int __fastcall ACT3Q2_IsSewerStairsClosed(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData && pQuestData->bNotIntro)
        return ((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nSewerStairsObjectMode != 2;
    return 0;
}

// 0x005B8530
int __fastcall OBJECTS_OperateFunction45_SewerLever(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->hObject;
    if (!pObject || !pObject->dwAnimMode)
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 16);
        if (pQuestData)
        {
            D2Act3Quest2Strc* pQuestDataEx = static_cast<D2Act3Quest2Strc*>(pQuestData->pQuestDataEx);
            if (pQuestDataEx->bSewerStairsInitialized != 1)
            {
                return 0;
            }

            if (SUNIT_GetServerUnit(pOp->pGame, 2, pQuestDataEx->nSewerStairsObjectGUID))
            {
                UNITS_ChangeAnimMode(pOp->hObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
                EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
                pQuestDataEx->nSewerStairsObjectMode = 2;
                EVENT_SetEvent(pOp->pGame, pOp->hObject, 7, pOp->pGame->dwGameFrame + 30, 0, 0);
                QUESTS_TriggerFX(pQuestData->pGame, 9);
            }
        }
    }

    return 0;
}

// 0x005B85E0
void __fastcall ACT3Q2_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bSewerStairsInitialized == 1)
    {
        D2UnitStrc* pFoundUnit = SUNIT_GetServerUnit(pQuestData->pGame, UNIT_OBJECT, pQuestDataEx->nSewerStairsObjectGUID);
        if (!pFoundUnit)
        {
            pQuestDataEx->nSewerStairsObjectMode = OBJMODE_OPENED;
            return;
        }

        UNITS_ChangeAnimMode(pFoundUnit, pQuestDataEx->nSewerStairsObjectMode);
        if (pQuestDataEx->nSewerStairsObjectMode != OBJMODE_OPENED)
        {
            pQuestDataEx->nSewerStairsObjectMode = OBJMODE_OPENED;
            const int nClassId = pFoundUnit->dwClassId;
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
            EVENT_SetEvent(pQuestData->pGame, pFoundUnit, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pQuestData->pGame->dwGameFrame, 0, 0);
        }
    }
}

// 0x005B8660
void __fastcall OBJECTS_InitFunction41_SewerStairs(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
    pQuestDataEx->bSewerStairsInitialized = 1;
    pQuestDataEx->nSewerStairsObjectGUID = !pOp->pObject ? -1 : pOp->pObject->dwUnitId;

    if (!pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, pQuestDataEx->nSewerStairsObjectMode);
    }
}

// 0x005B86B0
void __fastcall OBJECTS_InitFunction42_SewerLever(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData && !pQuestData->bNotIntro)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

// 0x005B86E0
void __fastcall ACT3Q2_UpdateKhalimItemCounts(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 0))
    {
        QUESTRECORD_GetQuestState(pQuestFlags, 18, 1);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 16);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;

    --pQuestDataEx->nEyesDropped;
    --pQuestDataEx->nHeartsDropped;
    --pQuestDataEx->nBrainsDropped;
    --pQuestDataEx->nFlailsDropped;
    ++pQuestDataEx->nCubedFlails;
}

// 0x005B8740
void __stdcall sub_005B8740_Nop(int nUnused1)
{
}

// 0x005B8750
int __fastcall ACT3Q2_LacksKhalimsWill(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ITEMS_FindQuestItem(pGame, pUnit, ' 2fq') == 0;
}

// 0x005B8770
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimEyeDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' yeq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B87C0
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimBrainDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' rbq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

struct D2GameStrc;

struct D2ItemDropStrc;

struct D2UnitStrc;

// 0x005B8810
int __fastcall ACT3Q2_UnitIterate_DetermineKhalimHeartDropCount(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    if (ITEMS_FindQuestItem(pGame, pUnit, ' rhq') || ITEMS_FindQuestItem(pGame, pUnit, ' 2fq'))
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        ++((D2Act3Quest2Strc*)pQuestData->pQuestDataEx)->nItemDropCount;
    }
    return 0;
}

// 0x005B8860
int __fastcall OBJECTS_OperateFunction57_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
    }
    pOp->hObject->dwDropItemCode = ' rhq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT3Q2_UnitIterate_DetermineKhalimHeartDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nHeartsDropped;
                pQuestDataEx->bHeartDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

// 0x005B8940
int __fastcall OBJECTS_OperateFunction58_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
    }
    pOp->hObject->dwDropItemCode = ' yeq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT3Q2_UnitIterate_DetermineKhalimEyeDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nEyesDropped;
                pQuestDataEx->bEyeDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

// 0x005B8A20
int __fastcall OBJECTS_OperateFunction59_KhalimChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!QUESTS_SetObjectSelection(pOp))
    {
        return 0;
    }

    D2SeedStrc* pSeed = QUESTS_GetGlobalSeed(pOp->pGame);
    const int nCounter = SEED_RollRandomNumber(pSeed) % 5 + 5;
    for (int i = 0; i < nCounter; ++i)
    {
        OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, ' dlg', 2);
    }
    pOp->hObject->dwDropItemCode = ' rbq';

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nItemDropCount = 0;
        SUNIT_IterateUnitsOfType(pOp->pGame, 0, pOp->hPlayer, ACT3Q2_UnitIterate_DetermineKhalimBrainDropCount);

        for (int i = 0; i < pQuestDataEx->nItemDropCount; ++i)
        {
            int nItemLevel;
            if (D2GAME_DropItemAtUnit(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 1))
            {
                ++pQuestDataEx->nBrainsDropped;
                pQuestDataEx->bBrainDropped = 1;
            }
        }
    }

    OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
    return 0;
}

// 0x005B8B00
void __fastcall ACT3Q2_AddFlailsDropped(D2GameStrc* pGame, int nCount)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q2_KHALIMFLAIL);
    if (pQuestData)
    {
        D2Act3Quest2Strc* pQuestDataEx = (D2Act3Quest2Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->nFlailsDropped += nCount;
        pQuestDataEx->bFlailDropped = 1;
    }
}


// 0x005BD500
bool __fastcall ACT3Q2_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 245)
    {
        if (pQuest->fState >= 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 2))
        {
            return true;
        }

        int nParts = 0;
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1fq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' yeq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 3))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rhq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 6))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rbq'))
        {
            ++nParts;
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 4))
            {
                return true;
            }
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 2fq') && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 7) && ACT3Q5_IsOrbNotSmashed(pQuest->pGame))
        {
            return true;
        }

        if (nParts == 4 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
        {
            return true;
        }
    }

    return false;
}

// 0x005BD630
void __fastcall ACT3Q2_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];

    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (nNpcId != 245)
    {
        return;
    }

    if (pQuestData->fState >= 1 && !QUESTRECORD_GetQuestState(pQuestFlags, 18, 2))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 0);
        return;
    }

    int nParts = 0;
    int bCubedFlail = 0;
    int bBaseFlail = 0;
    int bEye = 0;
    int bHeart = 0;
    int bBrain = 0;
    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' 2fq'))
    {
        bCubedFlail = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 7))
        {
            D2QuestDataStrc* pQuestData19 = QUESTS_GetQuestData(pQuestData->pGame, 19);
            const bool bNotSmashed = pQuestData19 ? ((D2Act3Quest5Strc*)pQuestData19->pQuestDataEx)->bOrbSmashed == 0 : true;
            if (bNotSmashed)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 5);
                return;
            }
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' 1fq'))
    {
        ++nParts;
        bBaseFlail = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 4);
            return;
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' yeq'))
    {
        ++nParts;
        bEye = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 3))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 1);
            return;
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' rhq'))
    {
        ++nParts;
        bHeart = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 6))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 2);
            return;
        }
    }

    if (ITEMS_FindQuestItem(pQuestData->pGame, pQuestArg->pPlayer, ' rbq'))
    {
        ++nParts;
        bBrain = 1;
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 18, 4))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 3);
            return;
        }
    }

    if (nParts > 0)
    {
        if (bBaseFlail)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 10);
            return;
        }

        if (bHeart)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 8);
            return;
        }

        if (bEye)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 7);
            return;
        }

        if (bBrain)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 9);
        }
        else
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 6);
        }
        return;
    }

    if (bCubedFlail)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 11);
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, 18, 2))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 245, 6);
    }
}

// 0x005BD850
bool __fastcall ACT3Q2_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    *pStatus = 0;

    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        return true;
    }

    const int bStarted = QUESTRECORD_GetQuestState(pFlags, 18, 2);
    if (bStarted || pQuest->bNotIntro && pQuest->fState >= 2)
    {
        *pStatus = 1;
    }

    int nParts = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 2fq'))
    {
        D2QuestDataStrc* pQuestData19 = QUESTS_GetQuestData(pQuest->pGame, 19);
        const bool bNotSmashed = pQuestData19 ? ((D2Act3Quest5Strc*)pQuestData19->pQuestDataEx)->bOrbSmashed == 0 : true;
        if (bNotSmashed)
        {
            *pStatus = 6;
        }
        else
        {
            *pStatus = 12;
        }
        return true;
    }

    int bBaseFlail = 0;
    int bEye = 0;
    int bHeart = 0;
    int bBrain = 0;
    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 1fq'))
    {
        ++nParts;
        bBaseFlail = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' yeq'))
    {
        ++nParts;
        bEye = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rhq'))
    {
        ++nParts;
        bHeart = 1;
    }

    if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' rbq'))
    {
        ++nParts;
        bBrain = 1;
    }

    if (nParts == 4)
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 18, 5) ? 5 : 7;
        return true;
    }

    if (nParts)
    {
        if (!bEye)
        {
            *pStatus = 1;
            return true;
        }

        if (!bBrain)
        {
            *pStatus = 2;
            return true;
        }

        if (!bHeart)
        {
            *pStatus = 4;
            return true;
        }

        *pStatus = bBaseFlail ? 7 : 3;
        return true;
    }

    if (bStarted)
    {
        *pStatus = 1;
        return true;
    }

    *pStatus = pQuest->fState > 1;
    return true;
}

