#include "D2Game.h"
#include "D2Packets.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Drlg.h"
#include "D2DrlgRooms.h"
#include "D2GameClient.h"
#include "D2DrlgDelete.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x0073131C
struct D2DrlgActStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define UNIT_MONSTER 1

struct D2DrlgCoordsStrc;
struct D2UnitStrc;
struct D2ActiveRoomStrc;
struct D2ClientStrc;
struct D2GameStrc;
struct D2CoordStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
#include "D2NetApi.h"

void __fastcall PLAYER_ClearTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00534AB0

void __fastcall D2GAME_PACKETS_SendPacket0x07(D2ClientStrc*, int, int, int); // 0x0053BC50

typedef void (__fastcall* AUTOMAPFN)(void*);

typedef void (__fastcall* TOWNAUTOMAPFN)(void*);

int __fastcall ARENA_GetAlternateStartTown(D2GameStrc* pGame); // 0x0053F5D0
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x006194A0
void __fastcall ACT2Q3_ApplyPendingDarkness(D2GameStrc* pGame, unsigned char nAct); // 0x0059AC40

int __stdcall D2Common_10229(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, unsigned int nX, unsigned int nY); // 0x00650BE0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
void __fastcall D2GAME_PACKETS_SendPacket0x08(D2ClientStrc* pClient, int nLevelId, int nX, int nY); // 0x0053BC90

static void LEVEL_ClearUnitTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);

static inline int UNITS_GetUnitTypeOrInvalid_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}


int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0

void __fastcall OBJMODE_SendObjectUpdates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00581AD0
void __fastcall ITEMMODE_SendUpdatedGroundItemToClient(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x0055BF30
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790



// 0x0053A500
static void __stdcall LEVEL_UpdateUnitForClient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(pUnit, 21);
    const int nUnitType = pUnit->dwUnitType;
    int bSkipInventory = 0;
    const int bInitSeedSet = (pUnit->dwFlags >> 4) & 1;
    if (bInitSeedSet)
    {
        if (CLIENTS_GetPlayerFromClient(pClient, 0) != pUnit)
        {
            if (bInitSeedSet && nUnitType == UNIT_MISSILE)
            {
                return;
            }
            SUNITMSG_SendUnitToClient(pGame, pUnit, pClient);
            bSkipInventory = 1;
        }
    }
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PLRMODE_SendPlayerUpdates(pGame, pUnit, pClient, bSkipInventory);
        break;
    case UNIT_MONSTER:
        MONSTERMSG_SendMonsterUpdates(pGame, pUnit, pClient, bSkipInventory);
        break;
    case UNIT_OBJECT:
        OBJMODE_SendObjectUpdates(pGame, pUnit, pClient);
        break;
    case UNIT_ITEM:
        ITEMMODE_SendUpdatedGroundItemToClient(pUnit, pClient);
        break;
    default:
        break;
    }
}

// 0x0053A5D0
static void __stdcall LEVEL_UpdateRoomUnitsForClient(D2GameStrc* pGame, D2ActiveRoomStrc* pAdjacentRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pAdjacentRoom, 68);
    D2UnitStrc* pUnit = pAdjacentRoom->pUnitUpdate;
    while (pUnit)
    {
        D2UnitStrc* pNextUnit = pUnit->pChangeNextUnit;
        LEVEL_UpdateUnitForClient(pGame, pUnit, pClient);
        pUnit = pNextUnit;
    }
}

// 0x0053A620
void __fastcall LEVEL_UpdateUnitsInAdjacentRooms(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    if (!pGame->pAct[CLIENTS_GetActNo(pClient)]->bHasPendingUnitListUpdates)
    {
        return;
    }
    D2_ASSERT(pRoom, 87);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        LEVEL_UpdateRoomUnitsForClient(pGame, ppRoomList[i], pClient);
    }
}

// 0x0053A6A0
static void LEVEL_FixRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x62);
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        SUNIT_UpdateClientIfRoomInvalid(pUnit, pClient);
}

// 0x0053A6F0
void __fastcall LEVEL_FixAdjacentRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x75);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
        LEVEL_FixRoomUnits(ppRoomList[i], pClient);
}

// 0x0053A770
void __fastcall LEVEL_RemoveUnitsExceptClientPlayer(D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(hRoom, 132);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(hRoom, &ppRoomList, &nNumRooms);

    D2UnitStrc* hUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2_ASSERT(hUnit, 136);

    const int nUnitType = hUnit->dwUnitType;
    const int nUnitGUID = hUnit->dwUnitId;
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2DrlgDeleteStrc* pDrlgDelete = DUNGEON_GetDrlgDeleteFromRoom(ppRoomList[i]); pDrlgDelete; pDrlgDelete = pDrlgDelete->pNext)
        {
            if (pDrlgDelete->nUnitType != nUnitType || pDrlgDelete->nUnitGUID != nUnitGUID)
            {
                D2GAME_PACKETS_SendPacket0x0A_RemoveObject(pClient, 0x0A, pDrlgDelete->nUnitType, pDrlgDelete->nUnitGUID);
            }
        }
    }
}

// 0x0053A820
void __fastcall LEVEL_FreeDrlgDeletes(D2GameStrc* pGame)
{
    for (int i = 0; i < NUM_ACTS; ++i)
    {
        D2DrlgActStrc* pAct = pGame->pAct[i];
        if (pAct && pAct->bHasPendingRoomDeletions)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
            {
                DUNGEON_FreeDrlgDelete(pRoom);
            }

            pAct->bHasPendingRoomDeletions = 0;
        }
    }
}

// 0x0053A880
static void LEVEL_UpdateMonsterAiCallbacks(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 1:
            MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
            break;
        }
    }
}

// 0x0053A8B0
static void LEVEL_DeleteMonsterEvents(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
        {
        case 1:
            MONSTER_DeleteEvents(pGame, pUnit);
            break;
        }
    }
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x0053A8E0
void __fastcall LEVEL_AddClient(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    if (!hRoom) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 207); exit(-1); }
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(hRoom, &tCoords);
    D2GAME_PACKETS_SendPacket0x07(pClient, DUNGEON_GetLevelIdFromRoom(hRoom), tCoords.nTileXPos, tCoords.nTileYPos);
    DUNGEON_AddClientToRoom(hRoom, pClient);
    if (hRoom->nNumClients <= 1)
    {
        LEVEL_UpdateMonsterAiCallbacks(pGame, hRoom);
    }
    D2UnitStrc* pUnit = hRoom->pUnitFirst;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    while (pUnit)
    {
        if (pPlayer != pUnit) SUNITMSG_SendUnitToClient(pGame, pUnit, pClient);
        pUnit = pUnit->ptRoomNext;
    }
}

// 0x0053A9B0
void __fastcall LEVEL_RemoveClient(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(hRoom, 0x104);

    for (D2UnitStrc* pUnit = hRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        SUNITMSG_SendRemoveObject(pUnit, pClient);
    }

    DUNGEON_RemoveClientFromRoom(hRoom, pClient);

    if (!hRoom->nNumClients)
    {
        LEVEL_DeleteMonsterEvents(pGame, hRoom);
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(hRoom, &drlgCoords);
    D2GAME_PACKETS_SendPacket0x08(pClient, DUNGEON_GetLevelIdFromRoom(hRoom), drlgCoords.nTileXPos, drlgCoords.nTileYPos);
}

// 0x0053AA70
static void LEVEL_ClearUnitTargetIfMatch(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    switch (UNITS_GetUnitTypeOrInvalid_Inline(pUnit))
    {
    case 0:
        PLAYER_ClearTargetIfMatch(pGame, pUnit, pTarget);
        break;

    case 1:
        MONSTER_ClearTargetIfMatches(pGame, pUnit, pTarget);
        break;
    }
}

// 0x0053AAA0
void __fastcall LEVEL_ClearRoomUnitTargets(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    D2_ASSERT(pRoom, 0x131);

    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        LEVEL_ClearUnitTargetIfMatch(pGame, pUnit, pTarget);
    }
}

// 0x0053AB10
void __fastcall LEVEL_ClearAdjacentRoomUnitTargets(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pTarget)
{
    D2_ASSERT(pRoom, 0x141);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
        LEVEL_ClearRoomUnitTargets(pGame, ppRoomList[i], pTarget);
}

// 0x0053AB80
void __fastcall LEVEL_RemoveClientFromAdjacentRooms(D2ActiveRoomStrc* hRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(hRoom, 334);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(hRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        DUNGEON_RemoveClientFromRoom(ppRoomList[i], pClient);
    }
}

// 0x0053ABE0
void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    D2GAME_PACKETS_SendPacket0x03(pClient, 3, nAct, pGame->dwInitSeed, pGame->dwObjSeed, DUNGEON_GetTownLevelIdFromAct(pGame->pAct[nAct]));

    int nCycleIndex;
    int nTicks;
    int nEclipse;
    ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(pGame->pAct[nAct], &nCycleIndex, &nTicks, &nEclipse);

    D2GSPacketSrv53 packet53;
    packet53.nHeader = 0x53;
    *(int*)&packet53.nCycleIndex = nCycleIndex;
    *(int*)&packet53.nTicks = nTicks;
    packet53.nEclipse = nEclipse;
    D2GAME_SendPacket0x53(pClient, &packet53);
}

// 0x0053AC70
static void LEVEL_AllocAct(D2GameStrc* pGame, unsigned char nAct)
{
    int nTownLevelId;
    if (ARENA_IsInArenaMode(pGame))
    {
        nTownLevelId = ARENA_GetAlternateStartTown(pGame);
    }
    else
    {
        nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
    }

    pGame->pAct[nAct] = DUNGEON_AllocAct(nAct, pGame->dwInitSeed, 0, pGame, pGame->nDifficulty, pGame->pMemoryPool, nTownLevelId, 0, 0);
    ACT2Q3_ApplyPendingDarkness(pGame, nAct);
}

// 0x0053ACC0
void __fastcall LEVEL_ChangeAct(D2GameStrc* pGame, D2ClientStrc* ptClient, int nDestinationLevelId, int nTileCalc)
{
    if (ARENA_IsInArenaMode(pGame))
    {
        return;
    }

    const unsigned char bNewAct = DRLG_GetActNoFromLevelId(nDestinationLevelId);
    D2_ASSERT(bNewAct != ptClient->bAct, 0x19F);

    if (!pGame->pAct[bNewAct])
    {
        LEVEL_AllocAct(pGame, bNewAct);
    }

    CLIENTS_SetClientState(ptClient, 5);

    D2UnitStrc* hUnit = CLIENTS_GetPlayerFromClient(ptClient, 0);
    D2_ASSERT(hUnit, 0x1AF);

    if (!pGame->bExpansion && hUnit->dwUnitType == UNIT_PLAYER)
    {
        D2GAME_KillPlayerPets(pGame, hUnit);
    }

    SKILLS_RemoveTransformStatesFromShapeshiftedUnit(hUnit);

    int nX;
    int nY;
    D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[bNewAct], nDestinationLevelId, nTileCalc, &nX, &nY, UNITS_GetUnitSizeX(hUnit));
    if (!pSpawnRoom)
    {
        return;
    }

    D2CoordStrc tSpawnPoint;
    tSpawnPoint.nX = nX;
    tSpawnPoint.nY = nY;

    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinatesEx(pSpawnRoom, &tSpawnPoint, UNITS_GetUnitSizeX(hUnit), 0x1C89, 5);
    if (!pRoom)
    {
        return;
    }

    nX = tSpawnPoint.nX;
    nY = tSpawnPoint.nY;

    D2DynamicPathStrc* pPath = hUnit->pDynamicPath;
    D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(hUnit);
    D2_ASSERT(D2Common_10229(pPath, hUnit, 0, 0, 0), 0x1D1);

    SUNIT_SynchronizeRoomClients(pGame, hUnit, pOldRoom);
    D2_ASSERT(D2Common_10229(pPath, hUnit, pRoom, nX, nY), 0x1D6);

    CLIENTS_SetRoomInClient(ptClient, 0);
    D2GAME_PACKETS_SendHeaderOnlyPacket(ptClient, 5);
    CLIENTS_SetActNo(ptClient, bNewAct);
    hUnit->nAct = bNewAct;
    hUnit->pDrlgAct = pGame->pAct[bNewAct];
    LEVEL_SynchronizeDayNightCycleWithClient(pGame, ptClient);
    CLIENTS_SetRoomInClient(ptClient, pRoom);
    UNITROOM_RefreshUnit(hUnit);
    hUnit->dwFlagEx |= 0x10000;
    SUNIT_SynchronizeRoomClients(pGame, hUnit, 0);
    UNITROOM_RefreshUnit(hUnit);

    if (hUnit->dwUnitType == UNIT_PLAYER)
    {
        PLAYERPETS_UpdatePetsForOwnerMove(pGame, hUnit, CLIENTS_GetUnitX(hUnit), CLIENTS_GetUnitY(hUnit));
    }
}

// 0x0053AEC0
void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc)
{
    const unsigned char nDestinationAct = DRLG_GetActNoFromLevelId(nDestinationLevelId);
    D2ClientStrc* hClient = UnitGetClient(pPlayer, ".\\GAME\\Level.cpp", 506);
    D2_ASSERT(hClient, 507);

    int nSourceLevelId = 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        nSourceLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    }

    if (nDestinationAct != CLIENTS_GetActNo(hClient))
    {
        SUNITPROXY_UpdateNpcsOnActChange(pGame, pPlayer, nSourceLevelId, nDestinationLevelId);
        LEVEL_ChangeAct(pGame, hClient, nDestinationLevelId, nTileCalc);
        return;
    }

    int nX;
    int nY;
    D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nDestinationAct], nDestinationLevelId, nTileCalc, &nX, &nY, UNITS_GetUnitSizeX(pPlayer));
    if (pSpawnRoom)
    {
        SUNIT_TeleportUnit(pGame, pPlayer, pSpawnRoom, nX, nY, 0, 0);
    }
}

// 0x0053AFB0
void __fastcall LEVEL_LoadAct(D2GameStrc* pGame, unsigned char nAct)
{
    if (!pGame->pAct[nAct])
    {
        LEVEL_AllocAct(pGame, nAct);
    }
}
struct D2MonsterDataStrc;



#pragma pack(push, 1)

// 0x0053AFD0
void __fastcall LEVEL_RemoveAllUnits(D2GameStrc* pGame)
{
    MONSTER_RemoveAll(pGame);
    OBJECTS_RemoveAll(pGame);
    PLAYER_RemoveAllPlayers(pGame);
    ITEMS_RemoveAll(pGame);
    MISSILES_RemoveAll(pGame);
    SUNIT_RemoveAllTiles(pGame);
}

// 0x0053B000
void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        D2DrlgActStrc* pAct = pGame->pAct[i];
        if (pAct && pAct->bHasPendingUnitListUpdates)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pAct); pRoom; pRoom = pRoom->pRoomNext)
            {
                for (D2UnitStrc* pUnit = pRoom->pUnitUpdate; pUnit; pUnit = pUnit->pChangeNextUnit)
                {
                    SUNIT_ClearUpdateData(pGame, pUnit);
                }

                UNITROOM_ClearUpdateQueue(pRoom);
            }

            pGame->pAct[i]->bHasPendingUnitListUpdates = 0;
        }
    }

    ARENA_ClearUpdateFlag(pGame);
}

// 0x0053B090
int __fastcall LEVEL_CountActRooms(D2GameStrc* pGame, unsigned char nAct)
{
    D2_ASSERT(nAct < 5, 0x294);
    D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]);
    int nCount = 0;
    while (pRoom)
    {
        pRoom = pRoom->pRoomNext;
        ++nCount;
    }
    return nCount;
}


