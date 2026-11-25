#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0073140C

#pragma intrinsic(_ReadWriteBarrier)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


#define PARTY_FIRST_ID 3



struct D2PartyNodeStrc;

struct D2PartyStrc;

struct D2PartyControlStrc;

struct D2UnitStrc;

struct D2GameStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall D2GAME_PACKETS_SendPacket0x8D_6FC3F960(D2UnitStrc* pUnit, D2UnitStrc* pPlayer); // 0x0053DF00

typedef void(__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053CDF0

unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540710

int __fastcall PARTY_GetPartyMemberCount(D2GameStrc* pGame, short nPartyId); // 0x00540460

void __fastcall PARTY_RemoveParty(D2GameStrc* pGame, short nPartyId); // 0x00540220

void __fastcall SCMD_BroadcastPlayerParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0053DEC0

int __fastcall FRIENDLY_RemoveHostility(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pPlayer2); // 0x005A6080

void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits); // 0x005404F0

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

void __fastcall PLRTRADE_AddGold(D2UnitStrc*, int, int); // 0x0053FF00

static D2PartyStrc* PARTY_FindParty(D2GameStrc*, short); // 0x00540290

static void __stdcall PARTY_CalculatePickAndDrop(int*, int*, D2UnitStrc*, int); // 0x00540650

void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc*, D2UnitStrc*, PartyCallbackFunction, void*); // 0x005405A0

extern "C" void _ReadWriteBarrier();

extern "C" const char gszPartySourceFile[]; // 0x006E0B88

static D2PartyStrc* sub_M08_FindPartyById(D2PartyControlStrc* pPartyControl, short nPartyId);

void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit);

void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pUnit);

int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGoldValue);

static D2PartyStrc* PARTY_FindParty_Inlined(D2GameStrc* pGame, short nPartyId)
{
    D2_ASSERT(pGame->hParty, 210);

    for (D2PartyStrc* pParty = pGame->hParty->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            return pParty;
        }
    }

    return 0;
}

// 0x0053FF90
void __fastcall PARTY_AllocPartyControl(D2GameStrc* ptGame)
{
    D2_ASSERT(ptGame, 0x18);
    D2_ASSERT(!ptGame->hParty, 0x19);

    D2PartyControlStrc* pPartyControl = (D2PartyControlStrc*)FOG_AllocPool(ptGame->pMemoryPool, sizeof(D2PartyControlStrc), ".\\UNIT\\Party.cpp", 0x1A, 0);
    D2_ASSERT(pPartyControl, 0x1B);

    memset(pPartyControl, 0, sizeof(D2PartyControlStrc));
    pPartyControl->nNextPartyId = 3;

    ptGame->hParty = pPartyControl;
}

// 0x00540000
void __fastcall PARTY_FreePartyControl(D2GameStrc* ptGame)
{
    D2_ASSERT(ptGame, 0x2E);
    D2PartyControlStrc* pPartyControl = ptGame->hParty;
    if (!pPartyControl)
        return;
    D2PartyStrc* pParty = pPartyControl->pParties;
    while (pParty)
    {
        D2PartyStrc* pNextParty = pParty->pNext;
        D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes;
        while (pPartyNode)
        {
            D2PartyNodeStrc* pNextPartyNode = pPartyNode->pNext;
            FOG_FreeServerMemory(ptGame->pMemoryPool, pPartyNode, ".\\UNIT\\Party.cpp", 0x3F, 0);
            pPartyNode = pNextPartyNode;
        }
        FOG_FreeServerMemory(ptGame->pMemoryPool, pParty, ".\\UNIT\\Party.cpp", 0x43, 0);
        pParty = pNextParty;
    }
    FOG_FreeServerMemory(ptGame->pMemoryPool, pPartyControl, ".\\UNIT\\Party.cpp", 0x47, 0);
    ptGame->hParty = 0;
}

// 0x005400B0
static short PARTY_GetFreePartyId(D2GameStrc* pGame)
{
    D2PartyControlStrc* pPartyControl = pGame->hParty;
    short nPartyId = pPartyControl->nNextPartyId;
    if ((unsigned short)nPartyId < PARTY_FIRST_ID)
    {
        nPartyId = PARTY_FIRST_ID;
    }

    for (;;)
    {
        D2PartyStrc* pCurrent = pPartyControl->pParties;
        while (pCurrent && pCurrent->nPartyId != nPartyId)
        {
            pCurrent = pCurrent->pNext;
        }

        if (!pCurrent)
        {
            break;
        }

        ++nPartyId;
        if ((unsigned short)nPartyId < PARTY_FIRST_ID)
        {
            nPartyId = PARTY_FIRST_ID;
        }
    }

    pPartyControl->nNextPartyId = nPartyId + 1;
    return nPartyId;
}

// 0x00540100
short __fastcall PARTY_CreateParty(D2GameStrc* pGame)
{
    D2PartyControlStrc* pPartyControl = pGame->hParty;
    D2_ASSERT(pPartyControl, 0x7F);
    D2PartyStrc* pParty = (D2PartyStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PartyStrc), ".\\UNIT\\Party.cpp", 0x80, 0);
    D2_ASSERT(pParty, 0x81);
    *pParty = D2PartyStrc();
    pParty->nPartyId = PARTY_GetFreePartyId(pGame);
    pParty->pNext = pPartyControl->pParties;
    pPartyControl->pParties = pParty;
    return pParty->nPartyId;
}

// 0x00540180
static void __stdcall PARTY_FreeParty(D2PartyStrc* pParty, D2GameStrc* pGame)
{
    D2_ASSERT(pParty, 149);
    D2PartyNodeStrc* pNode = pParty->pPartyNodes;
    while (pNode)
    {
        D2UnitStrc* pMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pNode->nUnitGUID);
        D2_ASSERT(pMember, 154);
        sub_6FC7B450(pGame, pMember);
        D2GAME_PACKETS_SendPacket0x8D_6FC3F960(pMember, pMember);
        D2PartyNodeStrc* pNext = pNode->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pNode, ".\\UNIT\\Party.cpp", 162, 0);
        pNode = pNext;
    }
    FOG_FreeServerMemory(pGame->pMemoryPool, pParty, ".\\UNIT\\Party.cpp", 165, 0);
}

// 0x00540220
void __fastcall PARTY_RemoveParty(D2GameStrc* pGame, short nPartyId)
{
    D2PartyControlStrc* pPartyControl = pGame->hParty;
    D2PartyStrc* pPrevious = 0;
    D2_ASSERT(pPartyControl, 180);
    for (D2PartyStrc* pParty = pPartyControl->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            if (pPrevious)
            {
                pPrevious->pNext = pParty->pNext;
            }
            else
            {
                pPartyControl->pParties = pParty->pNext;
            }
            PARTY_FreeParty(pParty, pGame);
            return;
        }
        pPrevious = pParty;
    }
}

// 0x00540290
static D2PartyStrc* PARTY_FindParty(D2GameStrc* pGame, short nPartyId)
{
    D2_ASSERT(pGame->hParty, 210);
    for (D2PartyStrc* pParty = pGame->hParty->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            return pParty;
        }
    }
    return 0;
}

// 0x005402D0
static int PARTY_HasMember(D2PartyStrc* pParty, int nUnitGUID)
{
    D2_ASSERT(pParty, 229);
    for (D2PartyNodeStrc* pNode = pParty->pPartyNodes; pNode; pNode = pNode->pNext)
    {
        if (pNode->nUnitGUID == nUnitGUID)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00540320
int __fastcall PARTY_AddPlayerToParty(D2GameStrc* pGame, short nPartyId, D2UnitStrc* hPlayer)
{
    D2_ASSERT(pGame->hParty, 210);
    D2PartyStrc* pParty = sub_M08_FindPartyById(pGame->hParty, nPartyId);
    const int nUnitGUID = !hPlayer ? -1 : hPlayer->dwUnitId;
    int nUnitType;
    if (pParty && hPlayer && (nUnitType = hPlayer->dwUnitType, _ReadWriteBarrier(), nUnitType == UNIT_PLAYER))
    {
        if (PARTY_HasMember(pParty, nUnitGUID))
        {
            return 1;
        }
        D2PartyNodeStrc* ptNode = (D2PartyNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PartyNodeStrc), gszPartySourceFile, 264, 0);
        D2_ASSERT(ptNode, 265);
        const D2PartyNodeStrc tZeroNode = {};
        *ptNode = tZeroNode;
        ptNode->nUnitGUID = nUnitGUID;
        ptNode->pNext = pParty->pPartyNodes;
        pParty->pPartyNodes = ptNode;
        SCMD_BroadcastPlayerParty(pGame, hPlayer);
        for (D2PartyNodeStrc* i = ptNode->pNext; i; i = i->pNext)
        {
            D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, i->nUnitGUID);
            if (pPartyMember)
            {
                FRIENDLY_RemoveHostility(pGame, hPlayer, pPartyMember);
                FRIENDLY_RemoveHostility(pGame, pPartyMember, hPlayer);
            }
        }
        return 1;
    }
    else
    {
        if (!pParty)
        {
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 254);
            exit(-1);
        }
        else
        {
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 255);
            exit(-1);
        }
    }
}

// 0x00540460
int __fastcall PARTY_GetPartyMemberCount(D2GameStrc* pGame, short nPartyId)
{
    D2PartyStrc* pParty = PARTY_FindParty_Inlined(pGame, nPartyId);
    int nCount = 0;
    if (!pParty)
    {
        return -1;
    }

    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        ++nCount;
    }

    return nCount;
}

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

// 0x005404C0
void __fastcall PARTY_AddLivingMemberLevelCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs)
{
    if (!SUNIT_IsDead(pUnit))
        *(int*)pArgs += STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
}

// 0x005404F0
void __fastcall PARTY_CountLivingUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pLivingUnits)
{
    if (pUnit && !SUNIT_IsDead(pUnit))
    {
        ++*((int*)pLivingUnits);
    }
}

// 0x00540510
void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs)
{
    D2_ASSERT(pGame->hParty, 210);

    for (D2PartyStrc* pParty = pGame->hParty->pParties; pParty; pParty = pParty->pNext)
    {
        if ((unsigned short)pParty->nPartyId == nPartyId)
        {
            if (nPartyId != 0xFFFF)
            {
                for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
                {
                    D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
                    if (pPartyMember)
                    {
                        pCallback(pGame, pPartyMember, pArgs);
                    }
                }
            }
            return;
        }
    }
}

// 0x005405A0
void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        pCallback(pGame, pUnit, pArgs);
        return;
    }
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId == D2PartyIdNone)
    {
        pCallback(pGame, pUnit, pArgs);
        return;
    }
    D2PartyStrc* pParty = PARTY_FindParty(pGame, nPartyId);
    if (!pParty)
    {
        return;
    }
    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
        if (pPartyMember)
        {
            D2ActiveRoomStrc* pPartyMemberRoom = UNITS_GetRoom(pPartyMember);
            if (pPartyMemberRoom && DUNGEON_GetLevelIdFromRoom(pPartyMemberRoom) == nLevelId)
            {
                pCallback(pGame, pPartyMember, pArgs);
            }
        }
    }
}

// 0x00540650
static void __stdcall PARTY_CalculatePickAndDrop(int* pGoldToPick, int* pGoldToDrop, D2UnitStrc* pUnit, int nValue)
{
    const int nGoldLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    *pGoldToDrop = 0;
    *pGoldToPick = nValue;
    if (nGold + nValue > nGoldLimit)
    {
        *pGoldToPick = nGoldLimit - nGold;
        *pGoldToDrop = nValue - *pGoldToPick;
    }
}

// 0x005406A0
void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\UNIT\\Party.cpp", 591);
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId == D2PartyIdNone)
    {
        return;
    }
    D2PartyStrc* pParty = PARTY_FindParty(pGame, nPartyId);
    if (!pParty)
    {
        return;
    }
    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
        if (pPartyMember && pPartyMember != pUnit)
        {
            sub_6FC3E200(pClient, pPartyMember);
        }
    }
}

// 0x00540710
unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* ptGame, D2UnitStrc* pUnit)
{
    int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    if (pUnit->pInventory)
    {
        nUnitGUID = INVENTORY_GetOwnerId(pUnit->pInventory);
    }

    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x27B);
    D2_ASSERT(ptGame, 0x27C);

    if (!ptGame->hParty)
    {
        return D2PartyIdNone;
    }

    for (D2PartyStrc* pParty = ptGame->hParty->pParties; pParty; pParty = pParty->pNext)
    {
        for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
        {
            if (pPartyNode->nUnitGUID == nUnitGUID)
            {
                return pParty->nPartyId;
            }
        }
    }

    return D2PartyIdNone;
}

static D2PartyStrc* sub_M08_FindPartyById(D2PartyControlStrc* pPartyControl, short nPartyId)
{
    for (D2PartyStrc* pParty = pPartyControl->pParties; pParty; pParty = pParty->pNext)
    {
        if (pParty->nPartyId == nPartyId)
        {
            return pParty;
        }
    }
    return 0;
}

int __fastcall sub_00540320(D2GameStrc* pGame, short nPartyId, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pGame->hParty, 210);
    D2PartyStrc* pParty = sub_M08_FindPartyById(pGame->hParty, nPartyId);
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2_ASSERT(pParty, 254);
    const int nType = pPlayer ? pPlayer->dwUnitType : UNIT_INVALID;
    D2_ASSERT(pPlayer && nType == UNIT_PLAYER, 255);
    if (PARTY_HasMember(pParty, nUnitGUID))
    {
        return 1;
    }
    D2PartyNodeStrc* pPartyNode = (D2PartyNodeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PartyNodeStrc), ".\\UNIT\\Party.cpp", 264, 0);
    D2_ASSERT(pPartyNode, 265);
    pPartyNode->nUnitGUID = 0;
    pPartyNode->pNext = 0;
    pPartyNode->nUnitGUID = nUnitGUID;
    pPartyNode->pNext = pParty->pPartyNodes;
    pParty->pPartyNodes = pPartyNode;
    SCMD_BroadcastPlayerParty(pGame, pPlayer);
    for (D2PartyNodeStrc* i = pPartyNode->pNext; i; i = i->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, i->nUnitGUID);
        if (pPartyMember)
        {
            FRIENDLY_RemoveHostility(pGame, pPlayer, pPartyMember);
            FRIENDLY_RemoveHostility(pGame, pPartyMember, pPlayer);
        }
    }
    return 1;
}

// 0x005407A0
void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2PartyNodeStrc* pPreviousPartyNode = 0;
    int nUnitGUID;
    const int nType = pUnit ? (nUnitGUID = pUnit->dwUnitId, pUnit->dwUnitType) : UNIT_INVALID;
    D2_ASSERT(nType == UNIT_PLAYER, 304);
    const unsigned short nPartyId = PARTY_GetPartyIdForUnitOwner(pGame, pUnit);
    if (nPartyId == D2PartyIdNone)
    {
        return;
    }
    D2PartyStrc* ptParty = PARTY_FindParty(pGame, nPartyId);
    D2_ASSERT(ptParty, 312);
    for (D2PartyNodeStrc* pPartyNode = ptParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        if (pPartyNode->nUnitGUID == nUnitGUID)
        {
            if (pPreviousPartyNode)
            {
                pPreviousPartyNode->pNext = pPartyNode->pNext;
            }
            else
            {
                ptParty->pPartyNodes = pPartyNode->pNext;
            }
            sub_6FC7B450(pGame, pUnit);
            D2GAME_PACKETS_SendPacket0x8D_6FC3F960(pUnit, pUnit);
            FOG_FreeServerMemory(pGame->pMemoryPool, pPartyNode, ".\\UNIT\\Party.cpp", 328, 0);
            break;
        }
        pPreviousPartyNode = pPartyNode;
    }
    if (PARTY_GetPartyMemberCount(pGame, nPartyId) <= 1)
    {
        PARTY_RemoveParty(pGame, nPartyId);
    }
}

// 0x005408E0
int __fastcall PARTY_GetLivingPartyMemberCountInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLivingPartyMembers = 0;
    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, PARTY_CountLivingUnits, &nLivingPartyMembers);
    return nLivingPartyMembers;
}

static inline void PLRTRADE_AddGoldInline(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    const int nNewValue = STATLIST_UnitGetStatValue(pUnit, nStat, 0) + nValue;
    if (nNewValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nNewValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;

        case STAT_GOLDBANK:
            if (nNewValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
}

static inline int PARTY_GetLivingUnitsInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLivingUnits = 0;
    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, PARTY_CountLivingUnits, &nLivingUnits);
    return nLivingUnits;
}

// 0x00540900
int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGoldValue)
{
    const int nLivingUnits = PARTY_GetLivingUnitsInSameLevel(pGame, pUnit);
    int nGoldToPick;
    int nGoldToDrop;
    if (nLivingUnits <= 1)
    {
        PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pUnit, nGoldValue);
        PLRTRADE_AddGoldInline(pUnit, STAT_GOLD, nGoldToPick);
        return nGoldToDrop;
    }

    const int nPartyId = SUNIT_GetPartyId(pUnit);
    D2PartyStrc* pParty = PARTY_FindParty(pGame, nPartyId);
    if (!pParty)
    {
        PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pUnit, nGoldValue);
        PLRTRADE_AddGold(pUnit, STAT_GOLD, nGoldToPick);
        return nGoldToDrop;
    }

    const int nDividedGold = nGoldValue / nLivingUnits;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    for (D2PartyNodeStrc* pPartyNode = pParty->pPartyNodes; pPartyNode; pPartyNode = pPartyNode->pNext)
    {
        D2UnitStrc* pPartyMember = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPartyNode->nUnitGUID);
        if (pPartyMember && pPartyMember != pUnit)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPartyMember);
            if (pRoom && DUNGEON_GetLevelIdFromRoom(pRoom) == nLevelId && sub_00451F70_GetUnitMode(pUnit) != 0 && sub_00451F70_GetUnitMode(pUnit) != 17)
            {
                nGoldToPick = 0;
                nGoldToDrop = 0;
                PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pPartyMember, nDividedGold);
                PLRTRADE_AddGold(pPartyMember, STAT_GOLD, nGoldToPick);
                nGoldValue += nGoldToDrop - nDividedGold;
            }
        }
    }

    PARTY_CalculatePickAndDrop(&nGoldToPick, &nGoldToDrop, pUnit, nGoldValue);
    PLRTRADE_AddGold(pUnit, STAT_GOLD, nGoldToPick);
    return nGoldToDrop;
}

