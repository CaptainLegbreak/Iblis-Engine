#include "D2MonsterIds.h"
#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2QuestData.h"
#include "D2CommonApi.h"


struct D2PoolSystemStrc;
typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);
typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);
typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);
typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0
void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId);                                // 0x00543640
#include "D2GameFuncs.h"
D2ActiveRoomStrc* __fastcall COLLISION_GetRoomBySubTileCoordinates(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005BD0B0
void __fastcall ACT3Q7_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

// 0x005BD0B0
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x005BD0C0
bool __fastcall ACT3Q7_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    return false;
}

// 0x005BD0D0
int __fastcall ACT3Q7_GetWandererCoordinates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pCoord)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 28);
    if (pQuestData)
    {
        D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bDarkWandererInitialized)
        {
            *pCoord = *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX;

            if (pQuestDataEx->bWandererCoordsCalculated)
            {
                return 1;
            }

            pCoord->nY += -20;
            pQuestDataEx->bWandererCoordsCalculated = 1;

            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nY += 9;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nX += 2;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nX += -4;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            *pCoord = *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX;
            pCoord->nY += -8;
            if (!UNITS_TestCollisionByCoordinates(pUnit, pCoord->nX, pCoord->nY, 0x3C01))
            {
                *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
                return 1;
            }

            pCoord->nY += 5;
            *(D2CoordStrc*)&pQuestDataEx->nDarkWandererX = *pCoord;
            return 1;
        }
    }

    return 0;
}

// 0x005BD1F0
void __fastcall OBJECTS_InitFunction43_DarkWanderer(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, 28);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bPrimaryGoalOpen)
    {
        pQuestDataEx->bDarkWandererInitialized = 1;
        return;
    }

    pQuestDataEx->nDarkWandererX = pOp->nX + 7;
    pQuestDataEx->nDarkWandererY = pOp->nY;

    D2ActiveRoomStrc* pRoom = COLLISION_GetRoomBySubTileCoordinates(pOp->pRoom, pQuestDataEx->nDarkWandererX, pQuestDataEx->nDarkWandererY);
    if (D2GAME_SpawnMonster(pOp->pGame, pRoom, pQuestDataEx->nDarkWandererX, pQuestDataEx->nDarkWandererY, MONSTER_DARKWANDERER, 1, -1, 0))
    {
        pQuestDataEx->bPrimaryGoalOpen = 0;
    }
    pQuestDataEx->bDarkWandererInitialized = 1;
}

// 0x005BD260
int __fastcall ACT3Q7_UnitIterate_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 32, 0) || !UNITS_GetRoom(pUnit))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId && DRLG_GetActNoFromLevelId(nLevelId) == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 32, 0);
    }

    return 0;
}

// 0x005BD2C0
void __fastcall ACT3Q7_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 32, 0) == 1)
    {
        QUESTS_SetGlobalState(pQuestData->pGame, 32, 13);
        ((D2Act3Quest7Strc*)pQuestData->pQuestDataEx)->bPrimaryGoalOpen = 0;
    }
}

// 0x005BD300
void __fastcall ACT3Q7_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[13] = ACT3Q7_Callback13_PlayerStartedGame;
    pQuestData->pNPCMessages = 0;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act3Quest7Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a3q7.cpp", 185, 0);
    memset(pQuestData->pQuestDataEx, 0x00, sizeof(D2Act3Quest7Strc));
    pQuestData->eFilter = 16;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT3Q7_ActiveFilterCallback;
    ((D2Act3Quest7Strc*)pQuestData->pQuestDataEx)->bPrimaryGoalOpen = 1;
}

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern D2CoordStrc gaSpawnOffsets[8];                                                              // 0x00741538


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230


static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005BD390
bool __fastcall ACT3Q7_SpawnVileDogs(D2GameStrc* pGame, D2QuestDataStrc* pQuestData)
{
    D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
    if (!pQuestDataEx->bVileDogsSpawned)
    {
        SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT3Q7_UnitIterate_SetRewardGranted);
        pQuestDataEx->bVileDogsSpawned = 1;
        pQuestDataEx->bVileDogSpawnTimerCreated = 0;

        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 1, pQuestDataEx->nUnitGUID);
        if (pUnit)
        {
            const unsigned int nRand = SEED_RollRandomNumber(QUESTS_GetGlobalSeed(pGame));
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            D2CoordStrc tCoords;
            UNITS_GetCoords(pUnit, &tCoords);
            for (unsigned int i = nRand & 1; i < 8; ++i)
            {
                D2CoordStrc tPos = tCoords;
                tPos.nX += gaSpawnOffsets[i].nX;
                tPos.nY += gaSpawnOffsets[i].nY;
                D2ActiveRoomStrc* pFoundRoom;
                QUESTS_GetFreePosition(pRoom, &tPos, 3, 0x3F11, &pFoundRoom, 11, 100);
                if (pFoundRoom)
                {
                    SUNIT_AllocUnitData(2, 0x83, tPos.nX, tPos.nY, pGame, pFoundRoom, 1, 0, 0);
                }
            }
        }
    }

    return true;
}

#define QUEST_A3Q7_DARKWANDERER 28


void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


// 0x005BD4A0
void __fastcall ACT3Q7_CreateVileDogSpawnTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, QUEST_A3Q7_DARKWANDERER);
    if (!pQuestData)
    {
        return;
    }

    D2Act3Quest7Strc* pQuestDataEx = (D2Act3Quest7Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bVileDogsSpawned || pQuestDataEx->bVileDogSpawnTimerCreated)
    {
        return;
    }

    pQuestDataEx->bVileDogSpawnTimerCreated = 1;
    pQuestDataEx->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    QUESTS_CreateTimer(pQuestData, ACT3Q7_SpawnVileDogs, 2);
}

