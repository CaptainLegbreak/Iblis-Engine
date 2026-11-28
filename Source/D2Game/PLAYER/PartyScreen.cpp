#include "D2Game.h"
#include "D2Structs.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
struct D2GameStrc;

struct D2PartyScreenCallbackStrc;
struct D2UnitStrc;
struct D2ClientStrc;


struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);                           // 0x005A5690
};

#include "D2GameFuncs.h"
#include "D2CommonApi.h"

struct D2PartyScreenCallbackStrc
{
    D2UnitStrc* pPlayer1;
    D2UnitStrc* pPlayer2;
    unsigned short nPartyId;
};

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

short __fastcall PARTY_CreateParty(D2GameStrc* pGame); // 0x00540100
int __fastcall PARTY_AddPlayerToParty(D2GameStrc* pGame, short nPartyId, D2UnitStrc* pPlayer); // 0x00540320
void __fastcall PLAYERLIST_ResetPendingPartyInvitations(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055B650
void __fastcall PARTYSCREEN_PlayerIterate_PartyJoined(D2GameStrc* pGame, D2UnitStrc* pLocalPlayer, void* pArgs); // 0x005A5970

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

enum { JOIN_RELATION = 2 };

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArgs);

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0

#pragma pack(push, 1)


#define PARTYSCREENTYPE_HOSTILE 3
enum D2C_M187TrapConstants
{
    STAT_LEVEL = 12,
    STAT_TOHIT = 19,
    STAT_MINDAMAGE = 21,
    STAT_MAXDAMAGE = 22,
    STAT_FIREMINDAM = 48,
    STAT_FIREMAXDAM = 49,
    STAT_LIGHTMINDAM = 50,
    STAT_LIGHTMAXDAM = 51,
    STAT_POISONMINDAM = 57,
    STAT_POISONMAXDAM = 58,
    STAT_POISONLENGTH = 59,
};
// 0x005A5750
static void __stdcall PARTYSCREEN_SetPlayerListFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned short nFlag, int nParam)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);
    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, nFlag) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, nFlag, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

// 0x005A5CB0
void __fastcall PARTYSCREEN_PlayerIterate_RefreshPartyRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg)
{
    D2UnitStrc* pPlayer2 = (D2UnitStrc*)pArg;
    if (pPlayer1 == pPlayer2)
    {
        PLAYERLIST_SetPartyState(pPlayer1, pPlayer1, 1);
        SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer1);
    }
    else
    {
        PLAYERLIST_SetPartyState(pPlayer1, pPlayer2, 0);
        if (SUNIT_GetPartyId(pPlayer1) == -1)
        {
            PLAYERLIST_SetPartyState(pPlayer2, pPlayer1, 0);
        }
        else
        {
            PLAYERLIST_SetPartyState(pPlayer2, pPlayer1, 1);
        }

        SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
        SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
    }
}

static bool IsFemaleClass(D2UnitStrc* pUnit)
{
    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0:
    case 1:
    case 6:
        return true;
    }
    return false;
}

// 0x005A57B0
void __fastcall PARTYSCREEN_ToggleLootability(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    if (!CLIENTS_CheckFlag(UnitGetClient(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 74), 4))
    {
        return;
    }

    PARTYSCREEN_SetPlayerListFlag(pGame, pPlayer1, pPlayer2, 1, nParam);

    int nType;
    if (pPlayer1 && IsFemaleClass(pPlayer1))
    {
        nType = nParam != 0 ? 2 : 11;
    }
    else
    {
        nType = nParam != 0 ? 1 : 10;
    }

    UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 101)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, nType);
}

// 0x005A5840
void __fastcall PARTYSCREEN_ToggleIgnore(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 2) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, 2, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

// 0x005A58A0
void __fastcall PARTYSCREEN_ToggleSquelch(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 4) != nParam)
    {
        PLAYERLIST_ToggleFlag(pGame, pPlayer1, pPlayer2, 4, nParam);
    }

    SCMD_Send0x75_PartyRosterUpdate(pPlayer1, pPlayer2);
    SCMD_Send0x75_PartyRosterUpdate(pPlayer2, pPlayer1);
}

// 0x005A5690
void D2ClientStrc::PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType)
{
    const unsigned char nEvent = *(unsigned char volatile*)&nType; // volatile only reproduces the original reading nType at entry, before the packet is cleared
    D2GSPacketSrv5A packet;
    memset(&packet, 0, sizeof(packet));
    packet.dwParam = nUnitGUID;
    packet.nHeader = 0x5A;
    packet.nType = 7;
    packet.nColor = 3;
    packet.nParam = nEvent;
    switch (nEvent)
    {
    case 1:
        packet.nColor = 4;
        break;
    case 2:
        packet.nColor = 4;
        break;
    case 3:
        packet.nColor = 8;
        break;
    case 4:
        packet.nColor = 0;
        break;
    case 5:
        packet.nColor = 2;
        break;
    case 6:
        packet.nColor = 9;
        break;
    case 7:
        packet.nColor = 2;
        break;
    case 8:
        packet.nColor = 2;
        break;
    case 9:
        packet.nColor = 9;
        break;
    case 10:
        packet.nColor = 9;
        break;
    case 11:
        packet.nColor = 9;
        break;
    }
    D2GAME_PACKETS_SendPacket0x5A(this, &packet);
}

// 0x005A5D20
void __fastcall PARTYSCREEN_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer1);
    PARTY_IteratePartyMembers(pGame, nPartyId, PARTYSCREEN_PartyIterate_PlayerLeftParty, pPlayer1);
    PARTY_LeaveParty(pGame, pPlayer1);
}

// 0x005A5900
static void PARTYSCREEN_UpdatePartyStateWithPlayer(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer)
{
    const int nLocalGUID = !pLocalPlayer ? -1 : pLocalPlayer->dwUnitId;
    const int nOtherGUID = !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId;

    if (nLocalGUID == nOtherGUID)
    {
        return;
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pLocalPlayer);
    if (nPartyId == 0xFFFF)
    {
        if (PLAYERLIST_GetPartyState(pOtherPlayer, pLocalPlayer) == 4)
        {
            PLAYERLIST_SetPartyState(pLocalPlayer, pOtherPlayer, 2);
        }
        else
        {
            PLAYERLIST_SetPartyState(pOtherPlayer, pLocalPlayer, 0);
            PLAYERLIST_SetPartyState(pLocalPlayer, pOtherPlayer, 1);
        }
    }
    else
    {
        PLAYERLIST_SetPartyState(pOtherPlayer, pLocalPlayer, 1);
        PLAYERLIST_SetPartyState(pLocalPlayer, pOtherPlayer, 1);
    }
}

// 0x005A5A30
void __fastcall PARTYSCREEN_AcceptInvitation(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, int nParam, int* pFailure)
{
    unsigned short nPartyId = SUNIT_GetPartyId(pTarget);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer, pTarget);
    PLAYERLIST_AllocPlayerList(pGame, pTarget, pPlayer);
    if (PLAYERLIST_GetPartyState(pPlayer, pTarget) != JOIN_RELATION)
    {
        PLAYERLIST_SendPartyState(pTarget, pPlayer);
        PLAYERLIST_SendPartyState(pPlayer, pTarget);
        return;
    }

    if (nPartyId == 0xFFFF)
    {
        nPartyId = PARTY_CreateParty(pGame);
        PARTY_AddPlayerToParty(pGame, nPartyId, pTarget);
        PARTY_AddPlayerToParty(pGame, nPartyId, pPlayer);
        PLAYERLIST_ResetPendingPartyInvitations(pGame, pTarget);
    }
    else
    {
        PARTY_AddPlayerToParty(pGame, nPartyId, pPlayer);
    }

    PLAYERLIST_ResetPendingPartyInvitations(pGame, pPlayer);
    UnitGetClient(pPlayer, ".\\PLAYER\\PartyScreen.cpp", 233)->PARTYSCREEN_SendEventUpdateToClient(!pTarget ? -1 : pTarget->dwUnitId, 8);
    D2PartyScreenCallbackStrc tArgs = D2PartyScreenCallbackStrc();
    tArgs.pPlayer1 = pTarget;
    tArgs.pPlayer2 = pPlayer;
    tArgs.nPartyId = nPartyId;
    SUNIT_IterateLivingPlayers(pGame, PARTYSCREEN_PlayerIterate_PartyJoined, &tArgs);
}

// 0x005A5970
void __fastcall PARTYSCREEN_PlayerIterate_PartyJoined(D2GameStrc* pGame, D2UnitStrc* pLocalPlayer, void* pArgs)
{
    D2PartyScreenCallbackStrc* pArg = (D2PartyScreenCallbackStrc*)pArgs;

    const unsigned short nPartyId = SUNIT_GetPartyId(pLocalPlayer);
    PLAYERLIST_AllocPlayerList(pGame, pLocalPlayer, pArg->pPlayer1);
    PLAYERLIST_AllocPlayerList(pGame, pArg->pPlayer1, pLocalPlayer);
    PLAYERLIST_AllocPlayerList(pGame, pLocalPlayer, pArg->pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pArg->pPlayer2, pLocalPlayer);

    PARTYSCREEN_UpdatePartyStateWithPlayer(pLocalPlayer, pArg->pPlayer1);
    PARTYSCREEN_UpdatePartyStateWithPlayer(pLocalPlayer, pArg->pPlayer2);

    if (nPartyId == pArg->nPartyId && nPartyId != 0xFFFF && pLocalPlayer != pArg->pPlayer2)
    {
        UnitGetClient(pLocalPlayer, ".\\PLAYER\\PartyScreen.cpp", 183)->PARTYSCREEN_SendEventUpdateToClient(!pArg->pPlayer2 ? -1 : pArg->pPlayer2->dwUnitId, 7);
    }

    PLAYERLIST_SendPartyState(pLocalPlayer, pArg->pPlayer1);
    PLAYERLIST_SendPartyState(pLocalPlayer, pArg->pPlayer2);
    SCMD_BroadcastPlayerParty(pGame, pLocalPlayer);
}

// 0x005A5BE0
void __fastcall PARTYSCREEN_ReceivedInvitation(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_GetPartyState(pPlayer1, pPlayer2))
    {
        PLAYERLIST_SendPartyState(pPlayer1, pPlayer2);
        PLAYERLIST_SendPartyState(pPlayer2, pPlayer1);
        return;
    }

    PLAYERLIST_SetPartyState(pPlayer1, pPlayer2, 4);
    PLAYERLIST_SetPartyState(pPlayer2, pPlayer1, 2);

    UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 306)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 5);

    PLAYERLIST_SendPartyState(pPlayer1, pPlayer2);
    PLAYERLIST_SendPartyState(pPlayer2, pPlayer1);
}

// 0x005A5B30
void __fastcall PARTYSCREEN_InvitationCancelled(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_GetPartyState(pPlayer1, pPlayer2) == 4)
    {
        if (SUNIT_GetPartyId(pPlayer2) == -1)
        {
            PLAYERLIST_SetPartyState(pPlayer1, pPlayer2, 0);
        }
        else
        {
            PLAYERLIST_SetPartyState(pPlayer1, pPlayer2, 1);
        }

        if (SUNIT_GetPartyId(pPlayer1) == -1)
        {
            PLAYERLIST_SetPartyState(pPlayer2, pPlayer1, 0);
        }
        else
        {
            PLAYERLIST_SetPartyState(pPlayer2, pPlayer1, 1);
        }

        UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 274)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 6);
    }

    PLAYERLIST_SendPartyState(pPlayer1, pPlayer2);
    PLAYERLIST_SendPartyState(pPlayer2, pPlayer1);
}

// 0x005A5C70
void __fastcall PARTYSCREEN_PartyIterate_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg)
{
    D2UnitStrc* pPlayer2 = (D2UnitStrc*)pArg;
    if (pPlayer1 != pPlayer2)
    {
        UnitGetClient(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 323)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer2 ? -1 : pPlayer2->dwUnitId, 9);
    }
}
// 0x005A5D50
void __fastcall PARTYSCREEN_PartyIterate_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, void* pArg)
{
    D2UnitStrc* pPlayer2 = (D2UnitStrc*)pArg;
    if (pPlayer2 == pPlayer1 || STATLIST_GetUnitBaseStat(pPlayer1, STAT_LEVEL, 0) < 9)
    {
        return;
    }

    FRIENDLY_OpenHostility(pGame, pPlayer2, pPlayer1);
    FRIENDLY_OpenHostility(pGame, pPlayer1, pPlayer2);

    UnitGetClient(pPlayer1, ".\\PLAYER\\PartyScreen.cpp", 391)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer2 ? -1 : pPlayer2->dwUnitId, PARTYSCREENTYPE_HOSTILE);
}

// 0x005A5FF0
void __fastcall PARTYSCREEN_RefreshPartyRelationsAfterLeave(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    SUNIT_IterateLivingPlayers(pGame, PARTYSCREEN_PlayerIterate_RefreshPartyRelations, pPlayer);
}

typedef void(__fastcall* PartyCommandFunc)(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure);

typedef int(__stdcall* FARPROC)();

extern PartyCommandFunc gpfnPartyCommands[10]; // 0x006E2218

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

// 0x005A6000
int __fastcall PARTYSCREEN_CommandHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCallbackId, int nOtherPlayerGUID, int nParam)
{
    int bFailure = 0;
    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOtherPlayerGUID);
    if (!pOtherPlayer)
    {
        return 0;
    }

    if (gpfnPartyCommands[nCallbackId])
    {
        if (IsBadCodePtr((FARPROC)gpfnPartyCommands[nCallbackId]))
        {
            return 3;
        }

        gpfnPartyCommands[nCallbackId](pGame, pUnit, pOtherPlayer, nParam, &bFailure);
        if (bFailure)
        {
            return 3;
        }
    }

    return 0;
}


extern "C" void __cdecl PARTYSCREEN_InvitationCancelled(); // 0x005A5B30
extern "C" void __cdecl PARTYSCREEN_PlayerLeftParty(); // 0x005A5D20
extern "C" void __cdecl PARTYSCREEN_ReceivedInvitation(); // 0x005A5BE0
extern "C" void __cdecl PARTYSCREEN_ToggleHostile(); // 0x005A5E50
extern "C" void __cdecl PARTYSCREEN_ToggleIgnore(); // 0x005A5840
extern "C" void __cdecl PARTYSCREEN_ToggleLootability(); // 0x005A57B0
extern "C" void __cdecl PARTYSCREEN_ToggleSquelch(); // 0x005A58A0
extern "C" void __cdecl PARTYSCREEN_AcceptInvitation(); // 0x005A5A30
extern "C" void __cdecl MONSTERUNIQUE_UMod26_Teleport(); // 0x005A1600
extern "C" void __cdecl MONSTERUNIQUE_UMod38_Possessed(); // 0x005A1230
extern "C" void __cdecl MONSTERUNIQUE_UModChampion(); // 0x005A1280

extern "C" const PartyCommandFunc gData_006E2218[10]; // 0x006E2218

extern "C" const PartyCommandFunc gData_006E2218[10] = { 0, (PartyCommandFunc)&PARTYSCREEN_ToggleLootability, (PartyCommandFunc)&PARTYSCREEN_ToggleIgnore, (PartyCommandFunc)&PARTYSCREEN_ToggleSquelch, (PartyCommandFunc)&PARTYSCREEN_ToggleHostile, 0, (PartyCommandFunc)&PARTYSCREEN_ReceivedInvitation, (PartyCommandFunc)&PARTYSCREEN_InvitationCancelled, (PartyCommandFunc)&PARTYSCREEN_AcceptInvitation, (PartyCommandFunc)&PARTYSCREEN_PlayerLeftParty }; // 0x006E2218
#pragma comment(linker, "/alternatename:?gpfnPartyCommands@@3PAP6IXPAUD2GameStrc@@PAUD2UnitStrc@@1HPAH@ZA=_gData_006E2218")
