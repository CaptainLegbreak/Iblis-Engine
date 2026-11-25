#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
struct D2GameStrc;
struct D2UnitStrc;


struct D2ClientStrc
{
    void PARTYSCREEN_SendEventUpdateToClient(int nUnitGUID, unsigned char nType);                           // 0x005A5690
};

typedef void(__fastcall* PARTYCALLBACK)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine);    // 0x005531C0
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer);                                                     // 0x00554630
void __fastcall FRIENDLY_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);      // 0x005A60E0
int __fastcall FRIENDLY_RemoveHostility(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pPlayer2); // 0x005A6080
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, short nPartyId, PARTYCALLBACK pfCallback, void* pArg); // 0x00540510
void __fastcall PARTYSCREEN_PartyIterate_OpenHostility(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);                             // 0x005A5D50
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);  // 0x0055B140
int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300
void __fastcall PLAYERLIST_BroadcastFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2);                // 0x0055B4C0
int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B6C0
void __fastcall PLAYERLIST_SetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int a3); // 0x0055B720
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit);             // 0x00553380
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource); // 0x00566D90
void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer);                                       // 0x00535430
void __fastcall PARTYSCREEN_PlayerLeftParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure); // 0x005A5D20
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

// 0x005A5DC0
static void __stdcall PARTYSCREEN_OpenHostilityWithPlayerOrParty(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    const unsigned short nPartyId = SUNIT_GetPartyId(pPlayer2);
    if (nPartyId == 0xFFFF)
    {
        FRIENDLY_OpenHostility(pGame, pPlayer1, pPlayer2);
        FRIENDLY_OpenHostility(pGame, pPlayer2, pPlayer1);
        UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 412)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 3);
    }
    else if (STATLIST_GetUnitBaseStat(pPlayer1, STAT_LEVEL, 0) >= 9)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, PARTYSCREEN_PartyIterate_OpenHostility, pPlayer1);
    }
}

// 0x005A5E50
void __fastcall PARTYSCREEN_ToggleHostile(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer1);
    if (!pRoom || !DUNGEON_IsRoomInTown(pRoom) || STATLIST_GetUnitBaseStat(pPlayer1, STAT_LEVEL, 0) < 9 || STATLIST_GetUnitBaseStat(pPlayer2, STAT_LEVEL, 0) < 9)
    {
        *pFailure = 1;
        return;
    }

    PLAYERLIST_AllocPlayerList(pGame, pPlayer1, pPlayer2);
    PLAYERLIST_AllocPlayerList(pGame, pPlayer2, pPlayer1);

    if (PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 8) == nParam)
    {
        PLAYERLIST_BroadcastFlags(pGame, pPlayer1, pPlayer2);
        PLAYERLIST_BroadcastFlags(pGame, pPlayer2, pPlayer1);
        return;
    }

    if (!PLAYERLIST_CheckFlag(pPlayer1, pPlayer2, 8) && STATLIST_UnitGetStatValue(pPlayer2, STAT_LEVEL, 0) < 9)
    {
        return;
    }

    if (nParam)
    {
        if (PLAYERLIST_GetHostileDelay(pPlayer1, pPlayer2) > GetTickCount())
        {
            SUNIT_AttachSound(pPlayer1, 19, pPlayer1);
            PLRTRADE_SendEventPacketToPlayer(pPlayer1, 16, 0);
            PLAYERLIST_BroadcastFlags(pGame, pPlayer1, pPlayer2);
            PLAYERLIST_BroadcastFlags(pGame, pPlayer2, pPlayer1);
            return;
        }

        PLAYERLIST_SetHostileDelay(pPlayer1, pPlayer2, GetTickCount() + 60000);
        PARTYSCREEN_OpenHostilityWithPlayerOrParty(pGame, pPlayer1, pPlayer2);
        PLAYER_RemoveTownPortal(pGame, pPlayer1);

        short nPartyId = SUNIT_GetPartyId(pPlayer1);
        if (nPartyId != -1 && nPartyId == SUNIT_GetPartyId(pPlayer2))
        {
            PARTYSCREEN_PlayerLeftParty(pGame, pPlayer1, 0, 0, (int*)&nPartyId);
        }
        return;
    }

    FRIENDLY_RemoveHostility(pGame, pPlayer1, pPlayer2);
    UnitGetClient(pPlayer2, ".\\PLAYER\\PartyScreen.cpp", 534)->PARTYSCREEN_SendEventUpdateToClient(!pPlayer1 ? -1 : pPlayer1->dwUnitId, 4);
}
