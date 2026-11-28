#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QFLAG_PRIMARYGOALDONE 13

struct D2ActiveRoomStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2PlayerDataStrc;

struct D2QuestDataStrc;

struct D2QuestArgStrc;

struct D2ItemsTxt;

struct D2Act3Quest4Strc;

struct D2Act3Quest5Strc;

typedef int (__stdcall* FARPROC)();

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern char gpAct3Q4NpcMessages[]; // 0x007401D0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300


void __fastcall QUESTS_ResetPlayerGUIDCount(void* pQuestGUID); // 0x00545300

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380


bool __fastcall ACT3Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B9D90

void __fastcall ACT3Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B9ED0

void __fastcall ACT3Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BA320

void __fastcall ACT3Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BA870

void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BA990

void __fastcall ACT3Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BA9E0

bool __fastcall ACT3Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005BA170

typedef int (__fastcall* QUESTITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" const char gszAct3Q5SourceFile[];


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nUnitType, void* pData, QUESTITERATE pfnCallback);


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, QUESTUNITITERATE pfnCallback, void* pArgs); // 0x00540510


void __fastcall ACT3Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);    // 0x005BA0B0

static int __stdcall ACT3Q4_UpdatePartyQuestState(D2GameStrc* pGame, D2UnitStrc* pPlayer);

#define QUEST_A3Q3_GIDBINN 0x11

#define QUESTSTATEFLAG_A3Q5 21

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_STARTED 2

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

struct D2Act3Quest3Strc;

typedef void (__fastcall* QUESTCALLBACK)(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);


void __fastcall ACT3Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005BAB60


struct D2QuestDataExStrc;

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


struct D2QuestDataExStrc
{
    unsigned char unk_00[0x18];
    int nState18;
};

static inline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B9D90
bool __fastcall ACT3Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        return false;
    }

    if (nNpcId == 254)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g'))
        {
            return true;
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
        {
            return true;
        }
    }
    else if (nNpcId == 264)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j'))
        {
            return true;
        }
    }
    else if (nNpcId == 245)
    {
        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j') && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 2))
        {
            return true;
        }

        if (ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g') && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 4))
        {
            return true;
        }
    }

    return false;
}

// 0x005B9E70
int __fastcall ACT3Q4_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 20, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 20, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, 18);
    }

    return 0;
}

// 0x005B9ED0
void __fastcall ACT3Q4_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pGame, pQuestArg->pPlayer);
    int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q4, QFLAG_REWARDGRANTED);
    int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    if (bRewardGranted == 1)
    {
        if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId))
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 6);
        return;
    }

    if (nNpcId == MONSTER_ALKOR && ((D2Act3Quest4Strc*)pQuestData->pQuestDataEx)->bGoldenBirdBroughtToAlkor == 1)
        return;

    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q4, QFLAG_REWARDPENDING))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 5);
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g'))
    {
        if (nNpcId == MONSTER_CAIN3)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q4, QFLAG_ENTERAREA))
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
                return;
            }
        }
        else if (nNpcId == MONSTER_ALKOR)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q4, QFLAG_REWARDPENDING) && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q4, QFLAG_REWARDGRANTED))
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
            return;
        }

        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
        return;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j'))
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A3Q4, QFLAG_STARTED))
        {
            if (nNpcId == MONSTER_CAIN3 || nNpcId == MONSTER_ASHEARA)
            {
                QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 0);
                return;
            }
        }
        else if (nNpcId == MONSTER_CAIN3 || nNpcId == MONSTER_ASHEARA)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 7);
            return;
        }

        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 1);
    }
}

// 0x005BA0A0
void __fastcall ACT3Q4_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel == 75)
    {
        QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    }
}

// 0x005BA0B0
void __fastcall ACT3Q4_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;

    if ((short)nNpcId == 254)
    {
        if (pQuestDataEx->bTalkedToAlkor == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 5, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToAlkor = 0;
            pQuestDataEx->bGoldenBirdBroughtToAlkor = 1;
        }
    }
    else if ((short)nNpcId == 245)
    {
        if (pQuestDataEx->bTalkedToCainOnce == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 2, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToCainOnce = 0;
        }

        if (pQuestDataEx->bTalkedToCainTwice == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToCainTwice = 0;
        }
    }
    else if ((short)nNpcId == 264)
    {
        if (pQuestDataEx->bTalkedToMeshif == 1)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
            pQuestDataEx->bTalkedToMeshif = 0;
        }
    }
}

// 0x005BA170
bool __fastcall ACT3Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    if (!QUESTRECORD_GetQuestState(pFlags, 15, 0))
    {
        *pStatus = 0;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 20, 1))
    {
        *pStatus = 5;
    }
    else if (QUESTRECORD_GetQuestState(pFlags, 20, 0))
    {
        *pStatus = QUESTRECORD_GetQuestState(pFlags, 20, 13) ? 13 : 11;
    }
    else
    {
        *pStatus = 0;
        D2UnitStrc* pBird = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43g');
        D2UnitStrc* pJade = ITEMS_FindQuestItem(pQuest->pGame, pPlayer, ' 43j');
        if (pBird)
        {
            *pStatus = (QUESTRECORD_GetQuestState(pFlags, 20, 4) != 0) + 3;
        }
        else if (pJade)
        {
            *pStatus = (QUESTRECORD_GetQuestState(pFlags, 20, 2) != 0) + 1;
        }
        else if (pQuest->bNotIntro)
        {
            if (pQuest->fLastState >= 6)
            {
                *pStatus = (pQuest->pGame->nGameType != 3) + 6;
            }
            else
            {
                *pStatus = pQuest->fLastState;
            }
        }
    }

    return true;
}

// 0x005BA290
void __fastcall ACT3Q4_UnitIterate_UpdateCurrentQuestState(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnused)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 0x12);
    if (pQuestData)
    {
        D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestRecord, 0x14, 0) && !QUESTRECORD_GetQuestState(pQuestRecord, 0x14, 1))
        {
            QUESTRECORD_SetQuestState(pQuestRecord, 0x14, ((D2QuestDataExStrc*)pQuestData->pQuestDataEx)->nState18);
        }
    }
}

static inline int ACT3Q4_UpdatePartyQuestStateInline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q4_UnitIterate_UpdateCurrentQuestState, 0);
    }
    return 0;
}

// 0x005BA2F0
static int __stdcall ACT3Q4_UpdatePartyQuestState(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT3Q4_UnitIterate_UpdateCurrentQuestState, 0);
    }
    return 0;
}

// 0x005BA6A0
void __fastcall ACT3Q4_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        return;
    }

    QUESTS_DebugOutput(pQuestData->pGame, "something acquired", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 605);

    const unsigned int dwItemCode = DATATBLS_GetItemsTxtRecord(!pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId)->dwCode;
    if (dwItemCode == ' 43g')
    {
        QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 611);
        QUESTS_UnitIterate(pQuestData, 3, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
    }
    else if (dwItemCode == ' 43j')
    {
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
        QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 622);
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 20, 6))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 20, 6);
            SUNIT_AttachSound(pQuestArg->pPlayer, 72, pQuestArg->pPlayer);
        }
    }
}

// 0x005BA7B0
bool __fastcall ACT3Q4_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    bool bResult = false;
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 644);
        bResult = pQuest->pfSeqFilter(pQuest);
    }

    D2QuestDataStrc* pQuestData17 = QUESTS_GetQuestData(pQuestData->pGame, 17);
    if (pQuestData17)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 650);
        return pQuestData17->pfSeqFilter(pQuestData17) || bResult;
    }

    return bResult;
}

// 0x005BA870
void __fastcall ACT3Q4_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;

    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) || QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        pQuestData->bNotIntro = 0;
        pQuestDataEx->bWaitingForBoss = 0;
        pQuestDataEx->bJadeFigurineDropPending = 0;
        return;
    }

    D2UnitStrc* pGoldenBird = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g');
    D2UnitStrc* pJadeFigurine = ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j');
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
    {
        pQuestData->bNotIntro = 0;
        pQuestDataEx->bWaitingForBoss = 0;
        pQuestDataEx->bJadeFigurineDropPending = 0;
        return;
    }

    if (pGoldenBird)
    {
        pQuestDataEx->bWaitingForBoss = 0;
        pQuestDataEx->bJadeFigurineDropPending = 0;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 4))
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 4;
        }
        else
        {
            pQuestData->fState = 3;
            pQuestData->fLastState = 3;
        }
    }
    else if (pJadeFigurine)
    {
        pQuestDataEx->bWaitingForBoss = 0;
        pQuestDataEx->bJadeFigurineDropPending = 0;
        if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 2))
        {
            pQuestData->fState = 2;
            pQuestData->fLastState = 2;
        }
        else
        {
            pQuestData->fState = 1;
            pQuestData->fLastState = 1;
        }
    }
}

// 0x005BA9A0
void __fastcall ACT3Q4_Callback09_PlayerDroppedWithQuestItem(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;

    --pQuestDataEx->nGoldenBirdsInGame;
    if (!pQuestDataEx->nGoldenBirdsInGame && pQuestData->bNotIntro && pQuestDataEx->bJadeFigurineDropped && pQuestData->fState < 4)
    {
        pQuestDataEx->bPlayerDroppedWithItem = 1;
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 6, 0, ACT3Q4_UnitIterate_StatusCyclerEx, 1);
    }
}

// 0x005BA9E0
void __fastcall ACT3Q4_Callback14_PlayerJoinedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    bool bGoldAcquired = false;
    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j'))
    {
        ++pQuestDataEx->nGoldenBirdsInGame;
    }

    if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g'))
    {
        bGoldAcquired = true;
        ++pQuestDataEx->nGoldenBirdsInGame;
    }

    if (pQuestDataEx->nGoldenBirdsInGame != 1 || !pQuestData->bNotIntro || !pQuestDataEx->bPlayerDroppedWithItem)
    {
        return;
    }

    pQuestDataEx->bPlayerDroppedWithItem = 0;
    pQuestData->nStatusFlags = 0;

    int nState = 1;
    if (bGoldAcquired)
    {
        nState = 3;
    }

    QUESTS_UnitIterate(pQuestData, nState, 0, ACT3Q4_UnitIterate_StatusCyclerEx, true);
}

// 0x005BAA70
void __fastcall ACT3Q4_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pNPCMessages = gpAct3Q4NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->eFilter = 20;
    pQuestData->pfActiveFilter = ACT3Q4_ActiveFilterCallback;
    pQuestData->nInitNo = 0;
    pQuestData->pfStatusFilter = ACT3Q4_StatusFilterCallback;
    pQuestData->pfSeqFilter = ACT3Q4_SeqCallback;
    pQuestData->nSeqId = 16;
    pQuestData->pCallback[4] = ACT3Q4_Callback04_ItemPickedUp;
    pQuestData->pCallback[0] = ACT3Q4_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT3Q4_Callback11_ScrollMessage;
    pQuestData->pCallback[3] = ACT3Q4_Callback03_ChangedLevel;
    pQuestData->pCallback[13] = ACT3Q4_Callback13_PlayerStartedGame;
    pQuestData->pCallback[10] = ACT3Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[14] = ACT3Q4_Callback14_PlayerJoinedGame;
    pQuestData->pCallback[9] = ACT3Q4_Callback09_PlayerDroppedWithQuestItem;
    QUESTS_ResetPlayerGUIDCount(&pQuestData->tPlayerGUIDs);

    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest4Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 832, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    memset(pQuestDataEx, 0x00, sizeof(D2Act3Quest4Strc));
    pQuestDataEx->bJadeFigurineDropPending = 1;
    pQuestDataEx->bWaitingForBoss = 1;
}

// 0x005BA320
void __fastcall ACT3Q4_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNpcId = pQuestArg->nNPCNo;
    const unsigned short nMessageIndex = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pQuestArg->pGame, pQuestArg->pPlayer);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 0) == 1)
    {
        return;
    }

    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (nNpcId == 245)
    {
        if (nMessageIndex == 527)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 20, 2);
            if (pQuestData->fState == 1)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 478);
                pQuestDataEx->bTalkedToCainOnce = 1;
                pQuestData->pCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
            }
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            pQuestDataEx->nCurrentQuestFlag = 2;
            ACT3Q4_UpdatePartyQuestStateInline(pQuestArg->pGame, pQuestArg->pPlayer);
        }
        else if (nMessageIndex == 531)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 20, 4);
            pQuestDataEx->bTalkedToCainTwice = 1;
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            pQuestDataEx->nCurrentQuestFlag = 4;
            ACT3Q4_UpdatePartyQuestState(pQuestArg->pGame, pQuestArg->pPlayer);
        }
    }
    else if (nNpcId == 254)
    {
        if (nMessageIndex == 534)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g')
                && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 1)
                && !QUESTRECORD_GetQuestState(pQuestFlags, 20, 0))
            {
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g');
                --pQuestDataEx->nGoldenBirdsInGame;
                if (pQuestData->bNotIntro && pQuestData->fState != 4)
                {
                    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 509);
                }

                QUESTRECORD_SetQuestState(pQuestFlags, 20, 1);
                pQuestDataEx->bTalkedToAlkor = 1;
                pQuestData->pCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
                pQuestDataEx->nCurrentQuestFlag = 1;
                ACT3Q4_UpdatePartyQuestState(pQuestArg->pGame, pQuestArg->pPlayer);
            }
        }
        else if (nMessageIndex == 538)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 20, 0))
            {
                if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 1))
                {
                    QUESTRECORD_ClearQuestState(pQuestFlags, 20, 1);
                    QUESTRECORD_SetQuestState(pQuestFlags, 20, 0);
                    QUESTRECORD_SetQuestState(pQuestFlags, 20, 13);
                    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->eFilter);
                    QUESTRECORD_SetQuestState(pQuestFlags, 20, 5);
                    if (pQuestData->bNotIntro)
                    {
                        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 536);
                    }

                    QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' zyx', 0, 2, 1);
                    QUESTS_UpdatePlayerFlags(pQuestArg->pGame, pQuestArg->pPlayer);
                    QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, (!pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId));
                }

                if (QUESTRECORD_GetQuestState(pQuestFlags, 20, 13))
                {
                    QUESTS_SetGlobalState(pQuestArg->pGame, 20, 13);
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 545);
                    pQuestData->pfSeqFilter(pQuestData);
                }
            }
        }
    }
    else if (nNpcId == 264)
    {
        if (nMessageIndex == 529)
        {
            if (ITEMS_FindQuestItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j'))
            {
                pQuestData->pCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
                QUESTS_DeleteItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43j');
                --pQuestDataEx->nGoldenBirdsInGame;
                if (QUESTS_CreateItem(pQuestArg->pGame, pQuestArg->pPlayer, ' 43g', 0, 2, 1))
                {
                    ++pQuestDataEx->nGoldenBirdsInGame;
                    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 566);
                    pQuestDataEx->bTalkedToMeshif = 1;
                    pQuestData->pCallback[2] = ACT3Q4_Callback02_NpcDeactivate;
                }
            }
        }
    }
}

// 0x005BA990
void __fastcall ACT3Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_RemovePlayerGUID(pQuestData, pQuestArg);
}


// 0x005BAC70
int __fastcall ACT3Q4_UnitIterate_SetGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro || !pQuestDataEx->bJadeFigurineDropPending || pQuestDataEx->bWaitingForBoss != 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, QUEST_A3Q3_GIDBINN);
    if (pQuest && ((D2Act3Quest3Strc*)pQuest->pQuestDataEx)->bBossIsSpawning)
    {
        return 0;
    }

    QUESTS_CreateChainRecord(pQuestData->pGame, pUnit, QUEST_A3Q4_GOLDENBIRD);
    pQuestData->pCallback[QUESTEVENT_MONSTERKILLED] = ACT3Q4_Callback08_MonsterKilled;
    pQuestDataEx->bWaitingForBoss = 0;
    pQuestDataEx->bBossAssigned = 1;
    pQuestDataEx->nBossGUID = !pUnit ? -1 : pUnit->dwUnitId;
    return 1;
}

// 0x005BAB60
void __fastcall ACT3Q4_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_DebugOutput(pQuestData->pGame, "killed boss for quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 852);

    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (!pQuestData->bNotIntro || !pQuestDataEx->bBossAssigned || !pQuestDataEx->bJadeFigurineDropPending)
    {
        return;
    }

    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    if (pPlayer)
    {
        D2GameStrc* pGame = pQuestData->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0))
        {
            return;
        }
    }

    pQuestArg->pTarget->dwDropItemCode = ' 43j';
    int nItemLevel;
    if (D2GAME_DropItemAtUnit(pQuestData->pGame, pQuestArg->pTarget, 2, &nItemLevel, 0, -1, 0))
    {
        pQuestData->pCallback[8] = 0;
        pQuestDataEx->bJadeFigurineDropPending = 0;
        pQuestDataEx->bJadeFigurineDropped = 1;
        ++pQuestDataEx->nGoldenBirdsInGame;
        if (pQuestData->fState < 1)
        {
            QUESTS_StateDebug(pQuestData, 1, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q4.cpp", 879);
        }

        if (!pQuestData->fLastState)
        {
            QUESTS_UnitIterate(pQuestData, 1, 0, ACT3Q4_UnitIterate_StatusCyclerEx, true);
            pQuestDataEx->bBossAssigned = 0;
            return;
        }
    }
    else
    {
        pQuestDataEx->bWaitingForBoss = 1;
    }
    pQuestDataEx->bBossAssigned = 0;
}

// 0x005BACF0
void __fastcall ACT3Q4_CheckGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    D2Act3Quest4Strc* pQuestDataEx = (D2Act3Quest4Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bBossAssigned != 1)
    {
        return;
    }

    if (pQuestDataEx->nBossGUID == (!pUnit ? -1 : pUnit->dwUnitId))
    {
        pQuestDataEx->bBossAssigned = 0;
        pQuestDataEx->bWaitingForBoss = 1;
    }
}

// 0x005BAD20
int __fastcall ACT3Q4_GoldenBirdBroughtToAlkor(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 18);
    if (pQuestData && ((D2Act3Quest4Strc*)pQuestData->pQuestDataEx)->bGoldenBirdBroughtToAlkor)
    {
        return 1;
    }

    return 0;
}

// 0x005BAD40
void __fastcall ACT3Q4_ResetAlkor(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 18);

    if (pQuestData)
    {
        ((D2Act3Quest4Strc*)pQuestData->pQuestDataEx)->bGoldenBirdBroughtToAlkor = 0;
    }
}

