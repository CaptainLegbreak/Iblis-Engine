#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "D2CommonApi.h"
// build: symbol _gaszLanguageNames 0x00731F74

struct D2PlayerListStrc;

struct D2PlayerDataStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PLAYERLIST_IterateCallback_FreePlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x0055B1E0

// 0x0055B110
static D2PlayerListStrc* PLAYERLIST_FindPlayerList(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    const int nUnitGUID = !pPlayer2 ? -1 : pPlayer2->dwUnitId;
    if (pPlayer1 != pPlayer2)
    {
        for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
        {
            if (pPlayerList->nUnitGUID == nUnitGUID)
            {
                return pPlayerList;
            }
        }
    }

    return 0;
}

// 0x0055B140
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    if (pPlayer1 == pPlayer2 || STATES_CheckState(pPlayer2, STATE_PLAYERBODY) || STATES_CheckState(pPlayer1, STATE_PLAYERBODY))
    {
        return;
    }

    if (PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2))
    {
        return;
    }

    D2PlayerListStrc* pPlayerList = (D2PlayerListStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PlayerListStrc), ".\\UNIT\\PlayerList.cpp", 109, 0);
    memset(pPlayerList, 0, sizeof(D2PlayerListStrc));

    pPlayerList->nUnitGUID = !pPlayer2 ? -1 : pPlayer2->dwUnitId;
    pPlayerList->field_8 = 0;
    pPlayerList->field_C = SUNIT_GetPartyId(pPlayer2) != -1;
    pPlayerList->pNext = pPlayerData->pPlayerList;
    pPlayerData->pPlayerList = pPlayerList;
}

// 0x0055B780
void __fastcall PLAYERLIST_FreePlayerListCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    PLAYERLIST_IterateCallback_FreePlayerList(pGame, pPlayer, pArg);
}

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

void __fastcall D2GAME_PACKETS_SendPacket0x8C(D2UnitStrc* pUnit, int dwPlayerId1, int dwPlayerId2, unsigned short wRelationState); // 0x0053DE50

#include "D2GameFuncs.h"

short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00540710

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60


// 0x0055B1E0
void __fastcall PLAYERLIST_IterateCallback_FreePlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2UnitStrc* pPlayerArg = (D2UnitStrc*)pArg;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2PlayerListStrc* pPrevious = 0;
    const int nUnitGUID = !pPlayerArg ? -1 : pPlayerArg->dwUnitId;

    if (pPlayer == pPlayerArg)
    {
        return;
    }

    for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
    {
        if (pPlayerList->nUnitGUID == nUnitGUID)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pPlayerList->pNext;
            }
            else
            {
                pPlayerData->pPlayerList = pPlayerList->pNext;
            }

            FOG_FreePool(pGame->pMemoryPool, pPlayerList, ".\\UNIT\\PlayerList.cpp", 0x97, 0);
            return;
        }

        pPrevious = pPlayerList;
    }
}


// 0x0055B260
void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags, int bSet)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2 || !pPlayerList)
    {
        return;
    }

    if (bSet)
    {
        pPlayerList->dwFlags |= nFlags;
    }
    else
    {
        pPlayerList->dwFlags &= ~nFlags;
    }

    SCMD_BroadcastPlayerRelationship(pGame, !pPlayer1 ? -1 : pPlayer1->dwUnitId, !pPlayer2 ? -1 : pPlayer2->dwUnitId, pPlayerList->dwFlags);
}

// 0x0055B300
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2 || !pPlayerList)
    {
        return 0;
    }

    return pPlayerList->dwFlags & nFlags;
}

// 0x0055B540
void __fastcall PLAYERLIST_IterateCallback_InitializePlayerRelation(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2UnitStrc* pOther = (D2UnitStrc*)pArg;

    PLAYERLIST_AllocPlayerList(pGame, pPlayer, pOther);
    PLAYERLIST_AllocPlayerList(pGame, pOther, pPlayer);
    D2GAME_PACKETS_SendPacket0x8D(pOther, pPlayer);

    D2PlayerListStrc* pRecord = PLAYERLIST_FindPlayerList(pPlayer, pOther);
    if (pPlayer != pOther && pRecord)
    {
        pRecord->field_C = 0;
    }

    if (SUNIT_GetPartyId(pPlayer) == -1)
    {
        PLAYERLIST_SetPartyState(pOther, pPlayer, 0);
    }
    else
    {
        PLAYERLIST_SetPartyState(pOther, pPlayer, 1);
    }

    PLAYERLIST_SendPartyState(pOther, pPlayer);
    PLAYERLIST_SendPartyState(pPlayer, pOther);

    for (D2PlayerListStrc* pPlayerList = UNITS_GetPlayerData(pPlayer)->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
    {
        D2GAME_PACKETS_SendPacket0x8C(pOther, nUnitGUID, pPlayerList->nUnitGUID, (unsigned short)pPlayerList->dwFlags);
    }
}

// 0x0055B650
void __fastcall PLAYERLIST_ResetPendingPartyInvitations(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList; pPlayerList; pPlayerList = pPlayerList->pNext)
    {
        if (pPlayerList->field_C == 2)
        {
            D2UnitStrc* pOther = SUNIT_GetServerUnit(pGame, 0, pPlayerList->nUnitGUID);
            if (pOther)
            {
                pPlayerList->field_C = PARTY_GetPartyIdForUnitOwner(pGame, pOther) != -1;
                PLAYERLIST_SendPartyState(pPlayer, pOther);
            }
        }
    }
}

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


void __fastcall D2GAME_PACKETS_SendPacket0x8B(D2ClientStrc* pClient, int nUnitGUID, unsigned char nPartyState); // 0x0053DDC0

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg);       // 0x005538D0

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall PLAYERLIST_IterateCallback_InitializePlayerRelation(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x0055B540

void __fastcall PLAYERLIST_FreePlayerListCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x0055B780

// 0x0055B790
void __fastcall PLAYERLIST_FreePlayerLists(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    SUNIT_IterateLivingPlayers(pGame, PLAYERLIST_FreePlayerListCallback, pPlayer);

    D2PlayerListStrc* pPlayerList = pPlayerData->pPlayerList;
    while (pPlayerList)
    {
        D2PlayerListStrc* pNext = pPlayerList->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pPlayerList, ".\\UNIT\\PlayerList.cpp", 0x4E, 0);
        pPlayerList = pNext;
    }

    pPlayerData->pPlayerList = 0;
}

// 0x0055B350
unsigned short __fastcall PLAYERLIST_GetFlags(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (pPlayer1 != pPlayer2 && pPlayerList)
    {
        return pPlayerList->dwFlags;
    }

    return 0;
}

// 0x0055B3A0
void __fastcall PLAYERLIST_SetPartyState(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nPartyState)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2 || !pPlayerList)
    {
        return;
    }

    pPlayerList->field_C = nPartyState;
}

// 0x0055B3F0
short __fastcall PLAYERLIST_GetPartyState(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (pPlayer1 == pPlayer2)
    {
        return 1;
    }

    if (pPlayerList)
    {
        return pPlayerList->field_C;
    }

    return 0;
}

// 0x0055B440
void __fastcall PLAYERLIST_SendPartyState(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if ((!pPlayer1 ? -1 : pPlayer1->dwUnitId) != (!pPlayer2 ? -1 : pPlayer2->dwUnitId) && pPlayerList)
    {
        D2GAME_PACKETS_SendPacket0x8B(UnitGetClient(pPlayer1, ".\\UNIT\\PlayerList.cpp", 0x10B), !pPlayer2 ? -1 : pPlayer2->dwUnitId, pPlayerList->field_C);
    }
}

// 0x0055B4C0
void __fastcall PLAYERLIST_BroadcastFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (!pPlayerList)
    {
        return;
    }

    SCMD_BroadcastPlayerRelationship(pGame, !pPlayer1 ? -1 : pPlayer1->dwUnitId, !pPlayer2 ? -1 : pPlayer2->dwUnitId, pPlayerList->dwFlags);
}

// 0x0055B620
void __fastcall PLAYERLIST_InitializePlayerRelations(D2GameStrc* pGame, D2UnitStrc* hPlayer)
{
    D2_ASSERT(hPlayer, 0x14F);
    SUNIT_IterateLivingPlayers(pGame, PLAYERLIST_IterateCallback_InitializePlayerRelation, hPlayer);
}

// 0x0055B6C0
int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    if (!pPlayer2)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
        if (pPlayerData)
        {
            return pPlayerData->dwHostileDelay;
        }
    }

    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (!pPlayerList)
    {
        return 0;
    }

    return pPlayerList->field_8;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

// 0x0055B720
void __fastcall PLAYERLIST_SetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nHostileDelayEndTick)
{
    D2PlayerListStrc* pPlayerList = PLAYERLIST_FindPlayerList(pPlayer1, pPlayer2);
    if (pPlayerList)
    {
        pPlayerList->field_8 = nHostileDelayEndTick;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer1);
    if (pPlayerData)
    {
        pPlayerData->dwHostileDelay = GetTickCount();
    }
}

