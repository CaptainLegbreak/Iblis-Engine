#include "D2ObjectIds.h"
#include "D2MissileIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2GameObjs.h"
#include "D2ObjModes.h"

struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2GameStrc;

struct D2UnitStrc;

#define QUEST_A1Q4_CAIN 4

#define QUEST_A1Q5_COUNTESS 5

#define QUESTSTATEFLAG_A1Q5 5

#define QFLAG_REWARDPENDING 1

#define QFLAG_COMPLETEDNOW 14

#define PORTAL_RETRY_STEP 3

#define EVENTTYPE_QUESTFN 7

#define QUESTFN_DELAY 25

#define PORTAL_INVOCATIONS_MAX 5

#define MSG_TOWER_TOME 127

#define LINE_TOME_STATE2 514

struct D2NPCMessageTableStrc;

struct D2StaticPathStrc;

struct D2PlayerDataStrc;

struct D2QuestGUIDStrc;

struct D2ObjInitFnStrc;

struct D2ObjOperateFnStrc;

struct D2Act1Quest4Strc;

struct D2Act1Quest5Strc;

struct D2Act2Quest6Strc;

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);


typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

int __fastcall QUESTS_QuickCheckPlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545290

void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage); // 0x005456A0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

void __fastcall ACT1Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00594BB0

int __fastcall ACT1Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594F10

enum D2C_Q05QuestConstants
{
    QUESTSTATEFLAG_A1Q4 = 4,
    QUESTSTATEFLAG_A4Q2 = 26,
    QUESTSTATEFLAG_A5Q6 = 40,
    EVENTTYPE_ENDANIM = 1,
    QFLAG_REWARDGRANTED = 0,
    QFLAG_PRIMARYGOALDONE = 13,
    QFLAG_CUSTOM6 = 10,
    QFLAG_CUSTOM7 = 11,
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760

void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C3A0

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

#define UNIT_PLAYER 0

#define QFLAG_REWARDGRANTED 0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594830

int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594890

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern char gpAct1Q5NpcMessages[]; // 0x00737ED8

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070

void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pQuestGUID); // 0x00545300

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall ACT1Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00594960

void __fastcall ACT1Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00594C50

int __fastcall ACT1Q5_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x00594DD0

void __fastcall ACT1Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x00595010

bool __fastcall ACT1Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005952C0

void __fastcall ACT1Q5_UpdatePlayerListQuestState(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuestId, int nSoundId); // 0x00595420

void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx); // 0x005954F0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

struct D2BitBufferStrc;

struct D2QuestDataStrc;

static inline int UNITS_GetGUIDOrNone(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static inline int UNITS_GetAnimModeOrZero(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

inline D2BitBufferStrc* QUESTS_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00594700
static void __stdcall ACT1Q5_AddUnitGUID(D2Act1Quest5Strc* pQuestDataEx, int nUnitId, int bSecondList)
{
    if (bSecondList)
    {
        if (pQuestDataEx->nUnitCount2 < 12)
        {
            pQuestDataEx->nUnitGUIDs2[pQuestDataEx->nUnitCount2] = nUnitId;
            pQuestDataEx->nUnitCount2 += 1;
        }
    }
    else
    {
        if (pQuestDataEx->nUnitCount1 < 12)
        {
            pQuestDataEx->nUnitGUIDs1[pQuestDataEx->nUnitCount1] = nUnitId;
            pQuestDataEx->nUnitCount1 += 1;
        }
    }
}

// Out of line as in the original: it takes an argument in eax, a convention the compiler gives only a static whose callers are all in this object.
// 0x00594740
static __declspec(noinline) int __stdcall ACT1Q5_UpdateUnitGUIDLists(D2Act1Quest5Strc* pQuestDataEx, int nUnitGUID, int a3)
{
    if (a3)
    {
        for (int i = 0; i < pQuestDataEx->nUnitCount2; ++i)
        {
            if (pQuestDataEx->nUnitGUIDs2[i] == nUnitGUID)
            {
                if (i != pQuestDataEx->nUnitCount2 - 1)
                {
                    pQuestDataEx->nUnitGUIDs2[i] = pQuestDataEx->nUnitGUIDs2[pQuestDataEx->nUnitCount2 - 1];
                }
                --pQuestDataEx->nUnitCount2;
                return 1;
            }
        }
        return 0;
    }
    else
    {
        for (int i = 0; i < pQuestDataEx->nUnitCount1; ++i)
        {
            if (pQuestDataEx->nUnitGUIDs1[i] == nUnitGUID)
            {
                if (i != pQuestDataEx->nUnitCount1 - 1)
                {
                    pQuestDataEx->nUnitGUIDs1[i] = pQuestDataEx->nUnitGUIDs1[pQuestDataEx->nUnitCount1 - 1];
                }
                --pQuestDataEx->nUnitCount1;
                return 1;
            }
        }
        return 0;
    }
}

// 0x00594830
int __fastcall ACT1Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_COMPLETEDNOW))
    {
        QUESTS_StatusCyclerEx(pGame, pUnit, QUEST_A1Q5_COUNTESS);
    }

    return 0;
}

static int ACT1Q5_RemovePendingGUID_Inl(D2Act1Quest5Strc* pQuestDataEx, int nUnitGUID)
{
    for (int i = 0; i < pQuestDataEx->nUnitCount2; ++i)
    {
        if (pQuestDataEx->nUnitGUIDs2[i] == nUnitGUID)
        {
            if (i != pQuestDataEx->nUnitCount2 - 1)
            {
                pQuestDataEx->nUnitGUIDs2[i] = pQuestDataEx->nUnitGUIDs2[pQuestDataEx->nUnitCount2 - 1];
            }
            --pQuestDataEx->nUnitCount2;
            return 1;
        }
    }

    return 0;
}

// 0x00594890
int __fastcall ACT1Q5_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pFlags, 5, 0) == 1 || QUESTRECORD_GetQuestState(pFlags, 5, 1) == 1) return 0;
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, 5);
    if (!pQuest) return 0;
    if (pQuest->fState == 2)
    {
        QUESTRECORD_SetQuestState(pFlags, 5, 2);
        return 0;
    }
    if (pQuest->fState == 3)
    {
        switch (pQuest->fLastState)
        {
        case 1: QUESTRECORD_SetQuestState(pFlags, 5, 3); break;
        case 2: QUESTRECORD_SetQuestState(pFlags, 5, 4); break;
        case 3: QUESTRECORD_SetQuestState(pFlags, 5, 5); break;
        case 4: QUESTRECORD_SetQuestState(pFlags, 5, 6); break;
        }
    }
    return 0;
}

// 0x00594960
void __fastcall ACT1Q5_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const unsigned short nNpcId = pQuestArg->nNPCNo;
    const unsigned short nMsgId = pQuestArg->nMessageIndex;

    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;

    if (nMsgId == 127 && pQuestData->bNotIntro)
    {
        bool bUpdateQuestStateFlags = false;
        if (pQuestDataEx->bTowerTomeActivated == 1)
        {
            if (pQuestData->fLastState < 1)
            {
                bUpdateQuestStateFlags = true;
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
            }

            if (pQuestData->fLastState == 3)
            {
                bUpdateQuestStateFlags = true;
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                if (pQuestData->fState < 3)
                {
                    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 0x129);
                }
            }
        }

        if (pQuestData->fState < 2)
        {
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 0x130);
            bUpdateQuestStateFlags = true;
        }

        if (bUpdateQuestStateFlags)
        {
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
        }
    }

    if ((nNpcId == 0x9A || nNpcId == 0x96 || nNpcId == 0x109 || nNpcId == 0x9B || nNpcId == 0x94 || nNpcId == 0x93)
        && (nMsgId == 0x90 || nMsgId == 0x8C || nMsgId == 0x91 || nMsgId == 0x8D || nMsgId == 0x8F || nMsgId == 0x8E))
    {
        D2UnitStrc* pPlayer = pQuestArg->pPlayer;
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0xD) && pQuestDataEx->bTriggerSeqFilter)
        {
            pQuestDataEx->bTriggerSeqFilter = 0;
            QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 0x14C);
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 0x14D);
            pQuestData->pfSeqFilter(pQuestData);
        }

        const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;

        for (int i = 0; i < pQuestDataEx->nUnitCount2; ++i)
        {
            if (pQuestDataEx->nUnitGUIDs2[i] == nUnitId)
            {
                if (ACT1Q5_RemovePendingGUID_Inl(pQuestDataEx, nUnitId) && pQuestDataEx->nUnitCount1 < 12)
                {
                    pQuestDataEx->nUnitGUIDs1[pQuestDataEx->nUnitCount1] = nUnitId;
                    ++pQuestDataEx->nUnitCount1;
                }
                break;
            }
        }
    }
}

// 0x00594BB0
void __fastcall ACT1Q5_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nGUID = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
    D2Act1Quest5Strc* pEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    QUESTS_FastRemovePlayerGUID(&pEx->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    for (int i = 0; i < pEx->nUnitCount2; ++i)
    {
        if (pEx->nUnitGUIDs2[i] == nGUID)
        {
            if (i != pEx->nUnitCount2 - 1)
                pEx->nUnitGUIDs2[i] = pEx->nUnitGUIDs2[pEx->nUnitCount2 - 1];
            --pEx->nUnitCount2;
            break;
        }
    }
    for (int i = 0; i < pEx->nUnitCount1; ++i)
    {
        if (pEx->nUnitGUIDs1[i] == nGUID)
        {
            if (i != pEx->nUnitCount1 - 1)
                pEx->nUnitGUIDs1[i] = pEx->nUnitGUIDs1[pEx->nUnitCount1 - 1];
            --pEx->nUnitCount1;
            break;
        }
    }
}

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790


extern unsigned int gnAct1Q5NpcMessageIndices[]; // 0x007382AC

__forceinline int ACT1Q5_ContainsGUID_Inline(const int* pGUIDs, int nCount, int nUnitId)
{
    for (int i = 0; i < nCount; ++i)
    {
        if (pGUIDs[i] == nUnitId)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00594C50
void __fastcall ACT1Q5_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestData->bNotIntro)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = QUESTS_GetPlayerQuestFlags_Inline(pQuestArg->pGame, pQuestArg->pPlayer);
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_PRIMARYGOALDONE);
    if (bRewardGranted == 1 && !bPrimaryGoalDone)
    {
        return;
    }

    const int nNpcId = !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId;
    const int nUnitId = !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId;
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState >= 4)
    {
        if (!ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs2, pQuestDataEx->nUnitCount2, nUnitId) && !ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs1, pQuestDataEx->nUnitCount1, nUnitId))
        {
            return;
        }
    }

    if (ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs2, pQuestDataEx->nUnitCount2, nUnitId))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 2);
        return;
    }

    if (bRewardGranted == 1 && bPrimaryGoalDone == 1)
    {
        if (ACT1Q5_ContainsGUID_Inline(pQuestDataEx->nUnitGUIDs1, pQuestDataEx->nUnitCount1, nUnitId))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
        }
        return;
    }

    const unsigned int nIndex = gnAct1Q5NpcMessageIndices[pQuestData->fState];
    if (nIndex != -1 && nIndex < 5)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
    }
}

// 0x00594DB0
void __fastcall ACT1Q5_InitTowerTome(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp)
{
    if (!pQuestData->bNotIntro)
        UNITS_ChangeAnimMode(pOp->pObject, 3);
}

// 0x00594DD0
int __fastcall ACT1Q5_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDPENDING))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_GetLevelIdFromRoom(pRoom) != LEVEL_TOWERCELLARLEV5)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData)
    {
        return 0;
    }

    const int nUnitId = UNITS_GetGUIDOrNone(pUnit);

    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    if (!QUESTS_QuickCheckPlayerGUID(&pQuestDataEx->tPlayerGUIDs, nUnitId))
    {
        QUESTS_AddPlayerGUID(&pQuestDataEx->tPlayerGUIDs, nUnitId);
    }

    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_REWARDGRANTED);
    QUESTRECORD_SetQuestState(pQuestFlags, QUESTSTATEFLAG_A1Q5, QFLAG_PRIMARYGOALDONE);
    return 0;
}

// 0x00594E70
int __fastcall OBJECTS_OperateFunction06_TowerTome(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData || !pQuestData->bNotIntro)
    {
        return 0;
    }

    QUESTS_SendScrollMessage(pOp->hPlayer, pOp->hObject, MSG_TOWER_TOME);

    if (pQuestData->fState > 1)
    {
        return 0;
    }

    QUESTS_StateDebug(pQuestData, QSTATE_2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", LINE_TOME_STATE2);
    if (pQuestData->fLastState < 1)
    {
        ((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->bTowerTomeActivated = 1;
    }

    return 0;
}

inline D2BitBufferStrc* ACT1Q5_GetPlayerQuestFlags_Inline(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00594F10
int __fastcall ACT1Q5_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = ACT1Q5_GetPlayerQuestFlags_Inline(pGame, pUnit);
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0) == 1)
        return 0;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;

    if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_TOWERCELLARLEV5)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0xD);
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0);
        QUESTRECORD_ClearQuestState(pQuestFlags, 5, 1);
        SUNIT_AttachSound(pUnit, 0x25, pUnit);

        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 5);
        if (!pQuestData)
            return 0;

        D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
        const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
        ACT1Q5_AddUnitGUID(pQuestDataEx, nUnitId, 1);
        return 0;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 5, 0xE);
    return 0;
}

// 0x00594FD0
static inline void ACT1Q5_FinishCountessQuest(D2QuestDataStrc* pQuestData)
{
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q5_UnitIterate_AttachCompletionSound);
    QUESTS_SetGlobalState(pQuestData->pGame, 5, 13);
    if (!((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->nUnitCount2)
        pQuestData->bActive = 0;
    else
        pQuestData->pCallback[10] = ACT1Q5_Callback10_PlayerLeavesGame;
}

void __fastcall sub_M129_Emit_00594FD0(D2QuestDataStrc* pQuestData)
{
    ACT1Q5_FinishCountessQuest(pQuestData);
}

// 0x00595010
void __fastcall ACT1Q5_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    const int nNewLevel = pQuestArg->nNewLevel;
    const int nOldLevel = pQuestArg->nOldLevel;
    if (pQuestData->bNotIntro)
    {
        if (nNewLevel == LEVEL_FORGOTTENTOWER)
        {
            if (!pQuestData->fState)
            {
                QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 615);
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 3, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
            }
            else if (pQuestData->fState <= 3 && pQuestData->fLastState == 1)
            {
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 4, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
            }
            return;
        }

        if (nNewLevel == LEVEL_TOWERCELLARLEV5)
        {
            if (pQuestData->fState < 4 && pQuestData->fLastState != 2)
            {
                if (pQuestData->fState != 3)
                {
                    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 634);
                }
                pQuestData->nStatusFlags = 0;
                QUESTS_UnitIterate(pQuestData, 2, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
                SUNIT_IterateUnitsOfType(pQuestData->pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
            }
            return;
        }
    }

    if (nOldLevel == LEVEL_ROGUEENCAMPMENT)
    {
        if (pQuestData->fState == 2)
        {
            D2UnitStrc* pPlayer = pQuestArg->pPlayer;
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) != 1)
            {
                QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 653);
            }
        }
        else if (pQuestData->fState == 5 && pQuestData->bNotIntro)
        {
            D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
            if (ACT1Q5_UpdateUnitGUIDLists(pQuestDataEx, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId, 0) && !pQuestDataEx->nUnitCount1 && !pQuestDataEx->nUnitCount2)
            {
                pQuestData->bActive = 0;
            }
        }
    }
}


// 0x00595160
void __fastcall ACT1Q5_UpdateCountessQuestState(D2GameStrc* pGame, D2UnitStrc* pUnit, int bPending)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A1Q5_COUNTESS);
    if (!pQuestData)
    {
        return;
    }

    if (!pQuestData->bNotIntro)
    {
        return;
    }

    if (pQuestData->fState >= 4)
    {
        return;
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDGRANTED) == 1)
    {
        return;
    }

    if (bPending)
    {
        if (pQuestData->fState == 2 || pQuestData->fState == 3)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING);
        }
        return;
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, QFLAG_REWARDPENDING) != 1)
    {
        return;
    }

    if (pQuestData->fState == 3)
    {
        return;
    }

    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 705);
    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT1Q5_UnitIterate_StatusCyclerEx, true);
    SUNIT_IterateUnitsOfType(pGame, UNIT_PLAYER, 0, ACT1Q5_UnitIterate_UpdateQuestStateFlags);
}

// 0x00595240
bool __fastcall ACT1Q5_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState < 2 && pQuestData->bNotIntro == 1)
    {
        return true;
    }
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter), 736);
        return pQuest->pfSeqFilter(pQuest);
    }
    return false;
}

// 0x005952C0
bool __fastcall ACT1Q5_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuest->pQuestDataEx;
    int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;

    for (int i = 0; i < pQuestDataEx->nUnitCount2; ++i)
    {
        if (pQuestDataEx->nUnitGUIDs2[i] == nUnitId)
        {
            if (nNpcId == 155 || nNpcId == 147)
            {
                return false;
            }

            return true;
        }
    }

    return false;
}

// 0x00595320
int __fastcall ACT1Q5_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0) == 1)
    {
        return 0;
    }
    QUESTRECORD_SetQuestState(pQuestFlags, 5, 14);
    QUESTS_SendLogUpdateEx(pUnit, 5, 0);
    return 0;
}

// 0x00595370
void __fastcall ACT1Q5_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 0) == 1)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == 0)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 13);
        QUESTRECORD_SetQuestState(pQuestFlags, 5, 0);
    }
}

// 0x005953D0
int __fastcall ACT1Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 5, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT1Q5_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}

// 0x00595420
void __fastcall ACT1Q5_UpdatePlayerListQuestState(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuestId, int nSoundId)
{
    for (int i = 0; i < pQuestGUID->nPlayerCount; ++i)
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pQuestGUID->nPlayerGUIDs[i]);
        if (pPlayer)
        {
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, nQuestId, QFLAG_REWARDGRANTED) != 1)
            {
                QUESTRECORD_SetQuestState(pQuestFlags, nQuestId, QFLAG_PRIMARYGOALDONE);
                QUESTRECORD_SetQuestState(pQuestFlags, nQuestId, QFLAG_REWARDGRANTED);
                if (nSoundId)
                {
                    SUNIT_AttachSound(pPlayer, nSoundId, pPlayer);
                }
            }
        }
    }
}

// 0x005954C0
bool __fastcall ACT1Q5_Timer_StatusCycler(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 5)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 13, 0, ACT1Q5_UnitIterate_StatusCyclerEx, 1);
    }
    pQuestDataEx->unk0x11C = 0;
    return true;
}

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005954F0
void __stdcall ACT1Q5_SpawnTowerChestMissiles(D2QuestDataStrc* pQuestData, D2Act1Quest5Strc* pQuestDataEx)
{
    if (!pQuestDataEx->bCountessKilled || pQuestDataEx->bDeathMissilesCreated)
    {
        return;
    }

    D2UnitStrc* pTrapFirebolt = 0;

    for (int i = 0; i < pQuestDataEx->nCountessChestCount; ++i)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pQuestData->pGame, 2, pQuestDataEx->nObjectGUIDs[i]);
        if (pObject)
        {
            D2CoordStrc pCoord;
            pCoord.nX = pQuestDataEx->pCoord.nX;
            pCoord.nY = pQuestDataEx->pCoord.nY;

            if (!pTrapFirebolt)
            {
                D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pObject), pCoord.nX, pCoord.nY);

                if (pRoom)
                {
                    pTrapFirebolt = D2GAME_SpawnMonster_6FC69F10(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, MONSTER_TRAP_FIREBOLT, 0xC, -1, 8);
                }

                if (!pTrapFirebolt)
                {
                    UNITS_GetCoords(pObject, &pCoord);

                    pCoord.nX += 5;
                    pCoord.nY += 5;

                    pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pObject), pCoord.nX, pCoord.nY);
                    pTrapFirebolt = D2GAME_SpawnMonster_6FC69F10(pQuestData->pGame, pRoom, pCoord.nX, pCoord.nY, MONSTER_TRAP_FIREBOLT, 0xC, -1, 8);
                }
            }

            if (pTrapFirebolt)
            {
                pQuestDataEx->bDeathMissilesCreated = 1;

                D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pQuestData->pGame, pTrapFirebolt, 0, 1, MISSILE_TOWERCHESTSPAWNER, CLIENTS_GetUnitXInline(pObject), CLIENTS_GetUnitYInline(pObject));
                if (pMissile)
                {
                    MISSILE_SetTargetX(pMissile, pQuestDataEx->nObjectGUIDs[i]);
                    MISSILE_SetTargetY(pMissile, 0);
                    D2ActiveRoomStrc* pMissileRoom = UNITS_GetRoom(pMissile);
                    DUNGEON_ToggleHasPortalFlag(pMissileRoom, 0);
                }
            }
        }
    }
}

// 0x005956C0
void __fastcall ACT1Q5_SpawnChestMissilesAndEvent(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit)
{
    ACT1Q5_SpawnTowerChestMissiles(pQuestData, (D2Act1Quest5Strc*)pQuestData->pQuestDataEx);

    if (((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->bCountessKilled && !((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->bDeathMissilesCreated)
    {
        EVENT_SetEvent(pQuestData->pGame, pUnit, 7, pQuestData->pGame->dwGameFrame + 10, 0, 0);
    }
}

// 0x00595710
void __fastcall ACT1Q5_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)pQuestData->pQuestDataEx;
    UNITS_GetCoords(pQuestArg->pTarget, &pQuestDataEx->pCoord);
    if (pQuestData->bNotIntro)
    {
        QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 945);
        pQuestData->pCallback[2] = 0;
        QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 947);
        pQuestDataEx->bTriggerSeqFilter = 1;
        SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT1Q5_UnitIterate_AttachCompletionSound);
        QUESTS_SetGlobalState(pQuestData->pGame, 5, 13);
        if (!((D2Act1Quest5Strc*)pQuestData->pQuestDataEx)->nUnitCount2)
        {
            pQuestData->bActive = 0;
        }
        else
        {
            pQuestData->pCallback[10] = ACT1Q5_Callback10_PlayerLeavesGame;
        }
        pQuestDataEx->bCountessKilled = 1;
        pQuestData->pCallback[8] = 0;
        QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, 13);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q5_UnitIterate_SetRewardGranted);
        ACT1Q5_UpdatePlayerListQuestState(pQuestArg->pGame, &pQuestDataEx->tPlayerGUIDs, pQuestData->eFilter, 37);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q5_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT1Q5_UnitIterate_SetCompletionFlag);
        QUESTS_CreateTimer(pQuestData, ACT1Q5_Timer_StatusCycler, 7);
    }
    ACT1Q5_SpawnTowerChestMissiles(pQuestData, pQuestDataEx);
    if (!pQuestDataEx->bDeathMissilesCreated)
    {
        EVENT_SetEvent(pQuestData->pGame, pQuestArg->pTarget, 7, pQuestData->pGame->dwGameFrame + 10, 0, 0);
    }
}

// 0x00595860
void __fastcall ACT1Q5_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 4) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 6) == 1)
    {
        pQuestData->fLastState = 4;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 5) == 1)
    {
        pQuestData->fLastState = 3;
        pQuestData->fState = 2;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 5, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x00595920
void __fastcall ACT1Q5_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[3] = ACT1Q5_Callback03_ChangedLevel;
    pQuestData->pCallback[11] = ACT1Q5_Callback11_ScrollMessage;
    pQuestData->pCallback[0] = ACT1Q5_Callback00_NpcActivate;
    pQuestData->pCallback[10] = ACT1Q5_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[8] = ACT1Q5_Callback08_MonsterKilled;
    pQuestData->pCallback[13] = ACT1Q5_Callback13_PlayerStartedGame;
    pQuestData->eFilter = 5;
    pQuestData->pNPCMessages = gpAct1Q5NpcMessages;
    pQuestData->fLastState = 0;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->pfStatusFilter = 0;
    pQuestData->nInitNo = 4;
    pQuestData->pfActiveFilter = ACT1Q5_ActiveFilterCallback;
    pQuestData->pfSeqFilter = ACT1Q5_SeqCallback;
    D2Act1Quest5Strc* pQuestDataEx = (D2Act1Quest5Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act1Quest5Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a1q5.cpp", 1039, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->nSeqId = 3;
    memset(pQuestDataEx, 0x00, sizeof(D2Act1Quest5Strc));
    QUESTS_ResetPlayerGUIDCount(&pQuestDataEx->tPlayerGUIDs);
}

// 0x00595A00
void __fastcall OBJECTS_InitFunction04_TowerTome(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestInfo = QUESTS_GetQuestData(pOp->pGame, 5);
    if (pQuestInfo)
    {
        if (!pQuestInfo->bNotIntro)
        {
            UNITS_ChangeAnimMode(pOp->pObject, 3);
        }
        return;
    }
    D2_ASSERT(pQuestInfo, 1059);
}
