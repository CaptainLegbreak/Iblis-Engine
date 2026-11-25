#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2UnitData.h"
#include "D2GameClient.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2RosterInfoStrc;

struct D2RosterPetStrc;

struct D2RosterGroupStrc;

struct D2RosterCorpseStrc;

struct D2RosterUnitStrc;

struct Obj00479B80;

struct Obj00479BA0;

struct Obj00479D20;

struct Obj0047A1B0;

struct Obj0047A1E0;

struct Obj0047A670;

extern D2RosterPetStrc* gpRosterPets; // 0x007BB5BC

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2RosterUnitStrc
{
    char unk0x00[0x38];
    D2RosterCorpseStrc* pCorpse;
    char unk0x3C[0x08];
    unsigned short wUnk0x44;
    unsigned char unk0x46[4];
    unsigned char unk0x4A[4];
};



D2StoredUnitRecordStrc* __stdcall GFX_SortRosterByName(D2StoredUnitRecordStrc* pList); // 0x004795F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0


void __fastcall MSG_SendPartyCommand(int nCommand, int nUnitId); // 0x00478780

void __cdecl ROSTER_RebuildRosterOrder(); // 0x00479AB0

void __cdecl PARTY_RebuildRosterUnits(); // 0x0049A640

unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440

struct Obj00479B80 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwValue18;
};

struct Obj00479BA0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwValue1C;
};

struct Obj00479D20 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwValue30;
};

struct Obj0047A1B0 { unsigned char bUnknown00[0x28]; unsigned int dwValue28; unsigned int dwValue2C; };

struct Obj0047A1E0 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwValue24;
};

struct Obj0047A670 { unsigned char bUnknown00[0x1C]; int nMode1C; };

struct D2PlayerDataStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

void __fastcall MSG_SendPvpCommand(int nCommand, int nUnitId, int bSet); // 0x00478740

void __cdecl GFX_UpdatePetFlags(); // 0x00478FA0

void __fastcall WARDENCLIENT_UpdateOwnerPetFlags(int nOwnerId); // 0x00479230

void __cdecl ROSTER_FreeRosterGroups(); // 0x004797C0

void __cdecl ROSTER_SortGroupMembers(); // 0x004799C0

void __cdecl ROSTER_JoinRosterGroups(); // 0x00479A00

void __fastcall PLAYERLIST_AddRosterInfo(int nUnitId1, int nUnitId2); // 0x004DC320

void __fastcall GFXUTIL_SetRelationFlag(int nUnitId1, int nUnitId2, unsigned int nFlags, int bSet); // 0x004DC3E0

void __fastcall GFXUTIL_SetRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC4C0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

static D2StoredUnitRecordStrc* gpStoredUnits; // 0x007BB5C0

static D2StoredUnitRecordStrc* gpStoredUnits2; // 0x007BB5C4

static D2RosterGroupStrc* gpRosterGroups; // 0x007BB5C8

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __cdecl ROSTER_SortRosterGroups();                                                               // 0x00479860

void __cdecl ROSTER_BuildRosterGroups();                                                              // 0x00479940

D2StoredUnitRecordStrc* __cdecl ROSTER_LeaveParty();                                                  // 0x00479F60

int __cdecl CHAT_IsNumberDisplayEnabled();                                                          // 0x0047A980

D2RosterInfoStrc** __cdecl PLAYERLIST_AllocRosterInfoList();                                              // 0x004DC270

struct D2PanelCtrlStrc_004B8370
{
    char unk0x00[0x5C];
    int nState;
};

struct D2SoundObjStrc_00515A30
{
    char unk0x00[0x40];
    int nValue40;
    int nValue44;
};

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];

typedef char check_size_ctrl[(sizeof(D2PanelCtrlStrc_004B8370) == 0x60) ? 1 : -1];

typedef char check_size_sound[(sizeof(D2SoundObjStrc_00515A30) == 0x48) ? 1 : -1];

#pragma intrinsic(memset)

struct D2StoredUnitRecordStrc;

static D2RosterGroupStrc* ROSTER_GetOrAddGroup(unsigned short wId); // 0x00479770

extern "C" const char szRosterCpp_006D7268[]; // 0x006D7268

static void ROSTER_MoveGroupMembers(D2RosterGroupStrc* pGroup); // 0x00479800

D2StoredUnitRecordStrc* __cdecl ROSTER_GetPlayerRosterUnit(); // 0x00479320

struct Unicode
{
    unsigned short wChar;

    int isWhitespace() const;
};

void __fastcall PLAYERLIST_FreeRosterInfoList(D2RosterInfoStrc** pList);                                  // 0x004DC2B0

unsigned short __fastcall CUNIT_GetPlayerPartyId(D2UnitStrc* pUnit);                           // 0x00465400

void __fastcall ROSTER_SetKillCount(int nUnitId, unsigned short nValue); // 0x00479B10

D2StoredUnitRecordStrc* __fastcall ROSTER_FindRosterUnitById(int nUnitId); // 0x00479BB0

unsigned short __fastcall ROSTER_LookupPartyNumber(D2UnitStrc* pUnit); // 0x00479C00

static void ROSTER_ToggleRelationFlag(D2StoredUnitRecordStrc* pEntry, unsigned short nFlag); // 0x00479D30

void __fastcall ROSTER_ToggleLoot(D2StoredUnitRecordStrc* pEntry); // 0x00479DA0

void __fastcall ROSTER_ToggleMute(D2StoredUnitRecordStrc* pEntry); // 0x00479DE0

void __fastcall ROSTER_ToggleSquelch(D2StoredUnitRecordStrc* pEntry); // 0x00479E20

void __fastcall ROSTER_ToggleHostile(D2StoredUnitRecordStrc* pEntry); // 0x00479FE0

int __fastcall ROSTER_IsHostileRelation(int nUnitId1, int nUnitId2); // 0x0047A070

void __fastcall ROSTER_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId); // 0x0047A0D0

void __fastcall ROSTER_SetPosition(int nUnitId, int nX, int nY); // 0x0047A100

int __fastcall ROSTER_GetPartyLife(int nUnitId); // 0x0047A150

char* __fastcall ROSTER_GetNameEx(int nUnitId); // 0x0047A1F0

char* __fastcall ROSTER_GetUnitName(D2UnitStrc* pUnit); // 0x0047A210

void __fastcall ROSTER_SetPortalIds(int nUnitId, int nA, int nB); // 0x0047A270

D2RosterInfoStrc** __fastcall ROSTER_GetRosterInfoList(int nUnitId); // 0x0047A310

void __fastcall ROSTER_SetPartyId(int nUnitId, unsigned short wPartyId); // 0x0047A330

void __fastcall ROSTER_SetPartyFlags(int nUnitId, unsigned char nFlags); // 0x0047A350

void __fastcall ROSTER_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags); // 0x0047A370

void __fastcall ROSTER_AddCorpse(int nUnitId, int nCorpseId); // 0x0047A3D0

void __fastcall ROSTER_DropCorpseEntry(int nUnitId, int nCorpseId); // 0x0047A490

int __fastcall ROSTER_CanLoot(int nUnitId1, int nUnitId2); // 0x0047A4F0

int __fastcall ROSTER_IsSameParty(int nUnitId1, int nUnitId2); // 0x0047A520

int __fastcall ROSTER_GetOtherPartyLife(int nUnitId); // 0x0047A6B0

void __fastcall ROSTER_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags); // 0x0047A850

static void ROSTER_MoveGroupMembers(D2RosterGroupStrc* pGroup); // 0x00479800

static void ROSTER_MovePlayerGroupToFront(int nPlayerId, unsigned short wPartyId); // 0x004798C0

void __cdecl ROSTER_BuildRosterGroups(); // 0x00479940

static void ROSTER_MovePlayerToFront(int nPlayerId); // 0x00479A60

void __fastcall ROSTER_AddRosterUnit(int nUnitId, int nClassId, const char* szName, unsigned short wLevel, unsigned short wPartyId, int nUnused, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildTag, const char* szGuildName); // 0x0047A6F0

static D2StoredUnitRecordStrc* ROSTER_FindRosterUnit(int nUnitId); // 0x004792E0

int __fastcall ROSTER_IsNotSquelched(int nUnitId); // 0x0047A170

static D2StoredUnitRecordStrc* ROSTER_FindRosterUnitByIdOrName(int nUnitId, const char* szName); // 0x00479360

static void __stdcall ROSTER_FillRosterUnit(int nUnitId, int nClassId, unsigned short wLevel, unsigned short wPartyId, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildName, const char* szGuildTag, const char* szName, D2StoredUnitRecordStrc* pRec); // 0x004793C0

static D2StoredUnitRecordStrc* ROSTER_SortRosterByKills(D2StoredUnitRecordStrc* pList); // 0x004796D0

void __cdecl ROSTER_SortMainListByKills(); // 0x00479740

void __cdecl ROSTER_SendLeaveParty(); // 0x00479FC0







// 0x004792C0
static inline int ROSTER_HasCorpse(D2RosterUnitStrc* pRosterUnit, unsigned int dwCorpseId)
{
    for (D2RosterCorpseStrc* pCorpse = pRosterUnit->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == dwCorpseId)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004792E0
static D2StoredUnitRecordStrc* ROSTER_FindRosterUnit(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = gpStoredUnits;
    if (nUnitId == -1)
        return 0;
    for (; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nUnitId)
            return pRec;
        for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
        {
            if (pCorpse->dwCorpseId == nUnitId)
                return pRec;
        }
    }
    return 0;
}

// 0x00479320
D2StoredUnitRecordStrc* __cdecl ROSTER_GetPlayerRosterUnit()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(!pPlayer ? -1 : pPlayer->dwUnitId);
    D2_ASSERT(pRec, 0x75);
    return pRec;
}

// 0x00479360
static D2StoredUnitRecordStrc* ROSTER_FindRosterUnitByIdOrName(int nUnitId, const char* szName)
{
    for (D2StoredUnitRecordStrc* pRec = gpStoredUnits; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nUnitId)
            return pRec;
        if (!strcmp(pRec->szName, szName))
            return pRec;
    }
    return 0;
}

// 0x004793C0
static void __stdcall ROSTER_FillRosterUnit(int nUnitId, int nClassId, unsigned short wLevel, unsigned short wPartyId, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildName, const char* szGuildTag, const char* szName, D2StoredUnitRecordStrc* pRec)
{
    strcpy(pRec->szName, szName);
    pRec->dwUnitId = nUnitId;
    pRec->dwClassId = nClassId;
    pRec->wLevel = wLevel;
    pRec->wPartyId = wPartyId;
    pRec->dwPartyFlags = nPartyFlags;
    pRec->wGuildFlags = wGuildFlags;
    strcpy(pRec->szGuildTag, szGuildTag);
    strcpy(pRec->szGuildName, szGuildName);
    if (szGuildTag[0])
        sprintf(pRec->szNameEx, "%s {%s}", szName, szGuildTag);
    else
        strcpy(pRec->szNameEx, szName);
}

// 0x00479470
static inline void ROSTER_FreeCorpses(D2RosterUnitStrc* pRosterUnit)
{
    D2RosterCorpseStrc* pCorpse = pRosterUnit->pCorpse;
    while (pCorpse)
    {
        D2RosterCorpseStrc* pPrev = pCorpse->pNext;
        FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x110, 0);
        pCorpse = pPrev;
    }
    pRosterUnit->pCorpse = 0;
}

int __fastcall sub_M119_Emit_004792C0(D2RosterUnitStrc* pRosterUnit, unsigned int dwCorpseId)
{
    if (ROSTER_HasCorpse(pRosterUnit, dwCorpseId + 1))
    {
        ROSTER_FreeCorpses(pRosterUnit);
    }
    return 1;
}







// 0x0047AA40
int Unicode::isWhitespace() const
{
    if (this->wChar < 0x100)
    {
        return ::isspace(this->wChar);
    }
    return 0;
}

static inline D2RosterGroupStrc* ROSTER_FindGroup(unsigned short wId)
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups; pGroup; pGroup = pGroup->pNext)
    {
        if (pGroup->wPartyId == wId)
        {
            return pGroup;
        }
    }
    return 0;
}

// 0x0047A850
void __fastcall ROSTER_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (!pRec)
        return;
    for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == nUnitId)
            return;
    }
    pRec->wPartyId = wPartyId;
    pRec->wLevel = wLevel;
    pRec->dwPartyFlags = nPartyFlags;
    GFX_UpdatePetFlags();
    ROSTER_RebuildRosterOrder();
    PARTY_RebuildRosterUnits();
}

// calling-convention shim (not game code)
void __fastcall sub_00479770_Shim(unsigned short* pIds, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        ROSTER_GetOrAddGroup(pIds[i])->unk0x02 = 1;
    }
}

// 0x004794B0
void __cdecl ROSTER_FreeRosterLists()
{
    D2StoredUnitRecordStrc* pEntry = gpStoredUnits;
    while (pEntry)
    {
        D2StoredUnitRecordStrc* pNext = pEntry->pNext;
        PLAYERLIST_FreeRosterInfoList(pEntry->pRosterInfo);
        pEntry->pRosterInfo = 0;
        D2RosterCorpseStrc* pSub = pEntry->pCorpse;
        while (pSub)
        {
            D2RosterCorpseStrc* pSubNext = pSub->pNext;
            FOG_Free(pSub, ".\\GAME\\Roster.cpp", 0x110, 0);
            pSub = pSubNext;
        }
        pEntry->pCorpse = 0;
        FOG_Free(pEntry, ".\\GAME\\Roster.cpp", 0x14D, 0);
        pEntry = pNext;
    }
    gpStoredUnits = 0;

    pEntry = gpStoredUnits2;
    while (pEntry)
    {
        D2StoredUnitRecordStrc* pNext = pEntry->pNext;
        PLAYERLIST_FreeRosterInfoList(pEntry->pRosterInfo);
        pEntry->pRosterInfo = 0;
        D2RosterCorpseStrc* pSub = pEntry->pCorpse;
        while (pSub)
        {
            D2RosterCorpseStrc* pSubNext = pSub->pNext;
            FOG_Free(pSub, ".\\GAME\\Roster.cpp", 0x110, 0);
            pSub = pSubNext;
        }
        pEntry->pCorpse = 0;
        FOG_Free(pEntry, ".\\GAME\\Roster.cpp", 0x159, 0);
        pEntry = pNext;
    }
    gpStoredUnits2 = 0;
}

// 0x004795A0
D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
        return pEntry->pNext;
    return gpStoredUnits;
}

// 0x004795C0
extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry)
{
    D2_ASSERT(pEntry, 372);
    return pEntry->szNameEx;
}

// 0x004796B0
void __cdecl ROSTER_SortMainListByName()
{
    gpStoredUnits = GFX_SortRosterByName(gpStoredUnits);
}

// 0x004796D0
static D2StoredUnitRecordStrc* ROSTER_SortRosterByKills(D2StoredUnitRecordStrc* pList)
{
    D2StoredUnitRecordStrc* pSorted = 0;
    D2StoredUnitRecordStrc* pCurrent = pList;
    while (pCurrent)
    {
        pList = pCurrent->pNext;
        D2StoredUnitRecordStrc* pPrevious = 0;
        for (D2StoredUnitRecordStrc* pRoster = pSorted; pRoster; pRoster = pRoster->pNext)
        {
            if (pCurrent->dwKillCount > pRoster->dwKillCount)
            {
                break;
            }
            pPrevious = pRoster;
        }
        if (pPrevious)
        {
            pCurrent->pNext = pPrevious->pNext;
            pPrevious->pNext = pCurrent;
        }
        else
        {
            pCurrent->pNext = pSorted;
            pSorted = pCurrent;
        }
        pCurrent = pList;
    }
    return pSorted;
}

// 0x00479740
void __cdecl ROSTER_SortMainListByKills()
{
    gpStoredUnits = ROSTER_SortRosterByKills(gpStoredUnits);
}

// 0x00479750
D2RosterGroupStrc* __fastcall ROSTER_FindPartyGroup(unsigned short wId)
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups; pGroup; pGroup = pGroup->pNext)
    {
        if (pGroup->wPartyId == wId)
        {
            return pGroup;
        }
    }
    return 0;
}

// 0x00479770
static D2RosterGroupStrc* ROSTER_GetOrAddGroup(unsigned short wId)
{
    D2RosterGroupStrc* pGroup = ROSTER_FindGroup(wId);
    if (pGroup)
    {
        return pGroup;
    }
    pGroup = (D2RosterGroupStrc*)FOG_Alloc(sizeof(D2RosterGroupStrc), ".\\GAME\\Roster.cpp", 0x1FC, 0);
    memset(pGroup, 0, 8);
    pGroup->wPartyId = wId;
    pGroup->pNext = gpRosterGroups;
    gpRosterGroups = pGroup;
    return pGroup;
}

// 0x004797C0
void __cdecl ROSTER_FreeRosterGroups()
{
    D2RosterGroupStrc* pGroup = gpRosterGroups;
    while (pGroup)
    {
        D2RosterGroupStrc* pNext = pGroup->pNext;
        FOG_Free(pGroup, ".\\GAME\\Roster.cpp", 559, 0);
        pGroup = pNext;
    }

    gpRosterGroups = 0;
}

// 0x00479800
static void ROSTER_MoveGroupMembers(D2RosterGroupStrc* pGroup)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRecord = gpStoredUnits;
    while (pRecord)
    {
        if (pRecord->wPartyId == pGroup->wPartyId)
        {
            D2StoredUnitRecordStrc* pMoved = pRecord;
            pRecord = pRecord->pNext;
            if (pPrev)
                pPrev->pNext = pRecord;
            else
                gpStoredUnits = pRecord;
            pMoved->pNext = pGroup->pFirst;
            pGroup->pFirst = pMoved;
        }
        else
        {
            pPrev = pRecord;
            pRecord = pRecord->pNext;
        }
    }
}

// 0x00479860
void __cdecl ROSTER_SortRosterGroups()
{
    D2RosterGroupStrc* pList = gpRosterGroups;
    D2RosterGroupStrc* pSorted = 0;
    D2RosterGroupStrc* pCurrent;
    while ((pCurrent = pList) != 0)
    {
        pList = pList->pNext;
        D2RosterGroupStrc* pPrevious = 0;
        for (D2RosterGroupStrc* pGroup = pSorted; pGroup; pGroup = pGroup->pNext)
        {
            if (pCurrent->wPartyId < pGroup->wPartyId)
            {
                break;
            }
            pPrevious = pGroup;
        }
        if (pPrevious)
        {
            pCurrent->pNext = pPrevious->pNext;
            pPrevious->pNext = pCurrent;
        }
        else
        {
            pCurrent->pNext = pSorted;
            pSorted = pCurrent;
        }
    }
    gpRosterGroups = pSorted;
}

// 0x004798C0
static void ROSTER_MovePlayerGroupToFront(int nPlayerId, unsigned short wPartyId)
{
    D2RosterGroupStrc* pHead = gpRosterGroups;
    D2RosterGroupStrc* pGroup = pHead;
    D2RosterGroupStrc* pPrevGroup = 0;
    D2StoredUnitRecordStrc* pPrev = 0;
    if (wPartyId == 0xFFFF)
        return;
    while (pGroup ? pGroup->wPartyId != wPartyId : false)
    {
        pPrevGroup = pGroup;
        pGroup = pGroup->pNext;
    }
    if (!pGroup)
        return;
    if (pPrevGroup)
    {
        pPrevGroup->pNext = pGroup->pNext;
        pGroup->pNext = pHead;
        gpRosterGroups = pGroup;
    }
    D2StoredUnitRecordStrc* pRec = pGroup->pFirst;
    while (pRec ? pRec->dwUnitId != nPlayerId : false)
    {
        pPrev = pRec;
        pRec = pRec->pNext;
    }
    if (!pRec)
        return;
    if (pPrev)
    {
        pPrev->pNext = pRec->pNext;
        pRec->pNext = pGroup->pFirst;
        pGroup->pFirst = pRec;
    }
}

// 0x00479940
void __cdecl ROSTER_BuildRosterGroups()
{
    while (gpStoredUnits)
    {
        const unsigned short wPartyId = gpStoredUnits->wPartyId;
        D2RosterGroupStrc* pGroup = gpRosterGroups;
        while (pGroup)
        {
            if (pGroup->wPartyId == wPartyId)
                break;
            pGroup = pGroup->pNext;
        }
        if (!pGroup)
        {
            pGroup = (D2RosterGroupStrc*)FOG_Alloc(sizeof(D2RosterGroupStrc), szRosterCpp_006D7268, 0x1FC, 0);
            memset(pGroup, 0, 8);
            pGroup->wPartyId = wPartyId;
            pGroup->pNext = gpRosterGroups;
            gpRosterGroups = pGroup;
        }
        ROSTER_MoveGroupMembers(pGroup);
    }
}

// 0x004799C0
void __cdecl ROSTER_SortGroupMembers()
{
    for (D2RosterGroupStrc* pGroup = gpRosterGroups; pGroup; pGroup = pGroup->pNext)
    {
        if (CHAT_IsNumberDisplayEnabled())
            pGroup->pFirst = ROSTER_SortRosterByKills(pGroup->pFirst);
        else
            pGroup->pFirst = GFX_SortRosterByName(pGroup->pFirst);
    }
    ROSTER_SortRosterGroups();
}

// 0x00479A00
void __cdecl ROSTER_JoinRosterGroups()
{
    D2StoredUnitRecordStrc* pTail = 0;
    for (D2RosterGroupStrc* pGroup = gpRosterGroups; pGroup; pGroup = pGroup->pNext)
    {
        if (pTail)
        {
            pTail->pNext = pGroup->pFirst;
        }
        else
        {
            pTail = pGroup->pFirst;
            gpStoredUnits = pTail;
        }
        pGroup->pFirst = 0;
        if (pTail)
        {
            while (pTail->pNext)
                pTail = pTail->pNext;
        }
    }
}

// 0x00479A60
static void ROSTER_MovePlayerToFront(int nPlayerId)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    for (D2StoredUnitRecordStrc* pRec = gpStoredUnits; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nPlayerId && pPrev)
        {
            pPrev->pNext = pRec->pNext;
            pRec->pNext = gpStoredUnits;
            gpStoredUnits = pRec;
        }
        pPrev = pRec;
    }
}

// 0x00479AB0
__declspec(noinline) void __cdecl ROSTER_RebuildRosterOrder()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nPlayerId);
    const unsigned short wPartyId = pRec ? pRec->wPartyId : 0xFFFF;
    ROSTER_BuildRosterGroups();
    ROSTER_SortGroupMembers();
    ROSTER_MovePlayerGroupToFront(nPlayerId, wPartyId);
    ROSTER_JoinRosterGroups();
    ROSTER_FreeRosterGroups();
    if (wPartyId == 0xFFFF)
        ROSTER_MovePlayerToFront(nPlayerId);
}

// 0x00479B10
void __fastcall ROSTER_SetKillCount(int nUnitId, unsigned short nValue)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (!pRec)
        return;
    if (nValue & 0x8000)
        pRec->dwKillCount = nValue - 0x10000;
    else
        pRec->dwKillCount = nValue;
    ROSTER_RebuildRosterOrder();
    PARTY_RebuildRosterUnits();
}

// 0x00479B50
unsigned short __fastcall ROSTER_GetGuildFlags(D2RosterUnitStrc* pRosterUnit)
{
    if (!pRosterUnit)
    {
        return 0;
    }
    return pRosterUnit->wUnk0x44;
}

// 0x00479B60
unsigned char* __fastcall ROSTER_GetGuildTag(D2RosterUnitStrc* pRosterUnit)
{
    if (!pRosterUnit)
    {
        return 0;
    }
    return pRosterUnit->unk0x46;
}

// 0x00479B70
unsigned char* __fastcall ROSTER_GetGuildName(D2RosterUnitStrc* pRosterUnit)
{
    if (!pRosterUnit)
    {
        return 0;
    }
    return pRosterUnit->unk0x4A;
}

// 0x00479B80
extern "C" __declspec(dllexport) unsigned int __fastcall ROSTER_GetKillCount(Obj00479B80* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}

// 0x00479B90
int __fastcall ROSTER_GetLevel(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        return pEntry->wLevel;
    }

    return 0;
}

// 0x00479BA0
extern "C" __declspec(dllexport) unsigned int __fastcall ROSTER_GetClassId(Obj00479BA0* pObj) {
    if (pObj) {
        return pObj->dwValue1C;
    }
    return 0;
}

// 0x00479BB0
D2StoredUnitRecordStrc* __fastcall ROSTER_FindRosterUnitById(int nUnitId)
{
    return ROSTER_FindRosterUnit(nUnitId);
}

// 0x00479BC0
unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry)
{
    D2StoredUnitRecordStrc* pRoster = gpStoredUnits;
    int nCount = 0;
    if (pEntry && pRoster)
    {
        const unsigned short wPartyId = pEntry->wPartyId;
        for (; pRoster; pRoster = pRoster->pNext)
        {
            if (pRoster->wPartyId == wPartyId)
                ++nCount;
        }
        if (nCount > 1)
            return wPartyId;
    }
    return 0xFFFF;
}

// 0x00479C00
unsigned short __fastcall ROSTER_LookupPartyNumber(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(pUnit->dwUnitId);
        if (pRec)
            return pRec->wPartyId;
    }
    return 0xFFFF;
}

// 0x00479C20
int __fastcall ROSTER_TestLootFlag(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1);
    }
    return 0;
}

// 0x00479C60
int __fastcall ROSTER_TestMuteFlag(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 2);
    }
    return 0;
}

// 0x00479CA0
int __fastcall ROSTER_TestSquelchFlag(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4);
    }
    return 0;
}

// 0x00479CE0
int __fastcall ROSTER_TestHostileFlag(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 8))
            return 1;
    }
    return 0;
}

// 0x00479D20
extern "C" __declspec(dllexport) unsigned int __fastcall ROSTER_GetPartyFlags(Obj00479D20* pObj) {
    if (pObj) {
        return pObj->dwValue30;
    }
    return 1;
}

// 0x00479D30
static void ROSTER_ToggleRelationFlag(D2StoredUnitRecordStrc* pEntry, unsigned short nFlag)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    D2_ASSERT(pEntry, 0x463);
    PLAYERLIST_AddRosterInfo(nPlayerId, pEntry->dwUnitId);
    GFXUTIL_SetRelationFlag(nPlayerId, pEntry->dwUnitId, nFlag, !GFXUTIL_TestRelationFlags(nPlayerId, pEntry->dwUnitId, nFlag));
}

// 0x00479DA0
void __fastcall ROSTER_ToggleLoot(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        ROSTER_ToggleRelationFlag(pEntry, 1);
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        MSG_SendPvpCommand(1, pEntry->dwUnitId, GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1));
    }
}

// 0x00479DE0
void __fastcall ROSTER_ToggleMute(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        ROSTER_ToggleRelationFlag(pEntry, 2);
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        MSG_SendPvpCommand(2, pEntry->dwUnitId, GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 2));
    }
}

// 0x00479E20
void __fastcall ROSTER_ToggleSquelch(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        ROSTER_ToggleRelationFlag(pEntry, 4);
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        MSG_SendPvpCommand(3, pEntry->dwUnitId, GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4));
        pPlayer = sub_00463DD0_GetPlayerUnit();
        if (GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4))
            sub_00611560_GetSquelchList()->Squelch(pEntry->szNameEx);
        else
            sub_00611560_GetSquelchList()->Unsquelch(pEntry->szNameEx);
    }
}

// 0x00479EB0
void __fastcall ROSTER_HandlePartyButton(D2StoredUnitRecordStrc* pEntry)
{
    if (!pEntry)
        return;

    int nCommand = 0;
    switch (pEntry->dwPartyFlags)
    {
    case 0:
        pEntry->dwPartyFlags = 4;
        nCommand = 6;
        break;
    case 1:
        D2_ASSERT(0, 0x4C7);
    case 2:
        nCommand = 8;
        pEntry->dwPartyFlags = 1;
        break;
    case 4:
        pEntry->dwPartyFlags = 0;
        nCommand = 7;
        break;
    case 3:
        nCommand = 9;
        pEntry->dwPartyFlags = 1;
        break;
    }
    MSG_SendPartyCommand(nCommand, pEntry->dwUnitId);
    ROSTER_RebuildRosterOrder();
    PARTY_RebuildRosterUnits();
}

inline int ROSTER_TestPvpFlag4Inl(D2StoredUnitRecordStrc* pEntry)
{
    if (pEntry)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        return GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 4);
    }
    return 0;
}

// 0x0047A6F0
void __fastcall ROSTER_AddRosterUnit(int nUnitId, int nClassId, const char* szName, unsigned short wLevel, unsigned short wPartyId, int nUnused, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildTag, const char* szGuildName)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pIter = gpStoredUnits2;
    D2_ASSERT(nUnitId != -1, 0xB3);
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnitByIdOrName(nUnitId, szName);
    if (pRec)
    {
        ROSTER_FillRosterUnit(nUnitId, nClassId, wLevel, wPartyId, nPartyFlags, wGuildFlags, szGuildName, szGuildTag, szName, pRec);
        ROSTER_RebuildRosterOrder();
        PARTY_RebuildRosterUnits();
        return;
    }
    while (pIter)
    {
        if (pIter->dwUnitId == nUnitId)
        {
            pRec = pIter;
            pIter = 0;
        }
        else
        {
            pPrev = pIter;
            pIter = pIter->pNext;
        }
    }
    if (pRec)
    {
        if (pPrev)
            pPrev->pNext = pRec->pNext;
        else
            gpStoredUnits2 = pRec->pNext;
        pRec->pNext = 0;
    }
    else
    {
        pRec = (D2StoredUnitRecordStrc*)FOG_Alloc(sizeof(D2StoredUnitRecordStrc), szRosterCpp_006D7268, 0xD8, 0);
        memset(pRec, 0, sizeof(D2StoredUnitRecordStrc));
    }
    pRec->pRosterInfo = PLAYERLIST_AllocRosterInfoList();
    ROSTER_FillRosterUnit(nUnitId, nClassId, wLevel, wPartyId, nPartyFlags, wGuildFlags, szGuildName, szGuildTag, szName, pRec);
    pRec->pNext = gpStoredUnits;
    gpStoredUnits = pRec;
    ROSTER_RebuildRosterOrder();
    PARTY_RebuildRosterUnits();
}

// 0x0047A8B0
void __fastcall ROSTER_RemoveRosterUnit(int nUnitId)
{
    D2StoredUnitRecordStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRec = gpStoredUnits;
    D2_ASSERT(nUnitId != -1, 0x121);
    for (; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwUnitId == nUnitId)
        {
            if (pPrev)
            {
                pPrev->pNext = pRec->pNext;
            }
            else
            {
                gpStoredUnits = pRec->pNext;
            }
            PLAYERLIST_FreeRosterInfoList(pRec->pRosterInfo);
            pRec->pRosterInfo = 0;
            D2RosterCorpseStrc* pCorpse = pRec->pCorpse;
            while (pCorpse)
            {
                D2RosterCorpseStrc* pNext = pCorpse->pNext;
                FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x110, 0);
                pCorpse = pNext;
            }
            pRec->pCorpse = 0;
            FOG_Free(pRec, ".\\GAME\\Roster.cpp", 0x131, 0);
            break;
        }
        pPrev = pRec;
    }
    ROSTER_RebuildRosterOrder();
    PARTY_RebuildRosterUnits();
}

// 0x00479F60
D2StoredUnitRecordStrc* __cdecl ROSTER_LeaveParty()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(!pPlayer ? -1 : pPlayer->dwUnitId);
    D2_ASSERT(pRec, 0x4ED);
    pRec->wPartyId = 0xFFFF;
    pRec->dwPartyFlags = 1;
    ROSTER_RebuildRosterOrder();
    PARTY_RebuildRosterUnits();
    return pRec;
}

// 0x00479FC0
void __cdecl ROSTER_SendLeaveParty()
{
    MSG_SendPartyCommand(9, ROSTER_LeaveParty()->dwUnitId);
}

// 0x00479FE0
void __fastcall ROSTER_ToggleHostile(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (!pEntry)
        return;
    if (!GFXUTIL_TestRelationFlags(nPlayerId, pEntry->dwUnitId, 8) && pEntry->wLevel < 9)
        return;
    ROSTER_ToggleRelationFlag(pEntry, 8);
    MSG_SendPvpCommand(4, pEntry->dwUnitId, GFXUTIL_TestRelationFlags(nPlayerId, pEntry->dwUnitId, 8));
    if (GFXUTIL_TestRelationFlags(nPlayerId, pEntry->dwUnitId, 8) && pEntry->wPartyId != 0xFFFF
        && ROSTER_GetPlayerRosterUnit()->wPartyId == pEntry->wPartyId)
        ROSTER_LeaveParty();
}

// 0x0047A070
int __fastcall ROSTER_IsHostileRelation(int nUnitId1, int nUnitId2)
{
    D2StoredUnitRecordStrc* pRec1 = ROSTER_FindRosterUnit(nUnitId1);
    D2StoredUnitRecordStrc* pRec2 = ROSTER_FindRosterUnit(nUnitId2);
    if (pRec1 && pRec2)
    {
        if (pRec1->wPartyId == pRec2->wPartyId && pRec1->wPartyId != 0xFFFF)
            return 0;
        return GFXUTIL_TestRelationFlags(pRec1->dwUnitId, pRec2->dwUnitId, 8) != 0;
    }
    return 1;
}

// 0x0047A0C0
int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord)
{
    if (pRecord)
    {
        return pRecord->dwUnitId;
    }
    return -1;
}

// 0x0047A0D0
void __fastcall ROSTER_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPartyLife = nLife;
        pRec->dwLevelId = wLevelId;
        ROSTER_RebuildRosterOrder();
        PARTY_RebuildRosterUnits();
    }
}

// 0x0047A100
void __fastcall ROSTER_SetPosition(int nUnitId, int nX, int nY)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPosX = nX;
        pRec->dwPosY = nY;
    }
}

// 0x0047A120
int __fastcall ROSTER_IsInPlayerParty(D2StoredUnitRecordStrc* pRecord)
{
    if (pRecord && pRecord->wPartyId != 0xFFFF && CUNIT_GetPlayerPartyId(sub_00463DD0_GetPlayerUnit()) == pRecord->wPartyId)
    {
        return 1;
    }
    return 0;
}

// 0x0047A150
int __fastcall ROSTER_GetPartyLife(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
        return pRec->dwPartyLife;
    return 0;
}

// 0x0047A170
int __fastcall ROSTER_IsNotSquelched(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
    {
        return !ROSTER_TestPvpFlag4Inl(pRec);
    }
    return 1;
}

// 0x0047A1B0
extern "C" __declspec(dllexport) void __fastcall ROSTER_GetPosition(Obj0047A1B0* pObj, unsigned int* pFirst, unsigned int* pSecond) {
    if (pObj) {
        *pFirst = pObj->dwValue28;
        *pSecond = pObj->dwValue2C;
    } else {
        *pFirst = 0;
        *pSecond = 0;
    }
}

// 0x0047A1E0
extern "C" __declspec(dllexport) unsigned int __fastcall ROSTER_GetLevelId(Obj0047A1E0* pObj) {
    if (pObj) {
        return pObj->dwValue24;
    }
    return 0;
}

// 0x0047A1F0
char* __fastcall ROSTER_GetNameEx(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
        return pRec->szNameEx;
    return 0;
}

// 0x0047A210
char* __fastcall ROSTER_GetUnitName(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x5DB);
    D2_ASSERT(pUnit->dwUnitType == UNIT_PLAYER, 0x5DC);
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(pUnit->dwUnitId);
    if (!pRec)
    {
        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
        D2_ASSERT(pPlayerData, 0x5E5);
        return pPlayerData->szName;
    }
    return pRec->szNameEx;
}

// 0x0047A270
void __fastcall ROSTER_SetPortalIds(int nUnitId, int nA, int nB)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPortalA = nA;
        pRec->dwPortalB = nB;
    }
}

// 0x0047A290
const char* __fastcall ROSTER_GetPortalOwnerName(int nUnitId)
{
    for (D2StoredUnitRecordStrc* pRec = gpStoredUnits; pRec; pRec = pRec->pNext)
    {
        if (pRec->dwPortalA == nUnitId || pRec->dwPortalB == nUnitId)
        {
            return pRec->szNameEx;
        }
    }
    return 0;
}

// 0x0047A2C0
int __fastcall ROSTER_HasPartyMate(D2UnitStrc* pUnit)
{
    D2StoredUnitRecordStrc* pRoster = gpStoredUnits;
    const int nUnitId = !pUnit ? -1 : pUnit->dwUnitId;
    const unsigned short wPartyId = CUNIT_GetPlayerPartyId(pUnit);
    if (wPartyId == 0xFFFF)
        return 0;

    for (; pRoster; pRoster = pRoster->pNext)
    {
        if (pRoster->wPartyId == wPartyId && pRoster->dwUnitId != nUnitId)
            return 1;
    }
    return 0;
}

// 0x0047A310
D2RosterInfoStrc** __fastcall ROSTER_GetRosterInfoList(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
        return pRec->pRosterInfo;
    return 0;
}

// 0x0047A330
void __fastcall ROSTER_SetPartyId(int nUnitId, unsigned short wPartyId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->wPartyId = wPartyId;
        ROSTER_RebuildRosterOrder();
        PARTY_RebuildRosterUnits();
    }
}

// 0x0047A350
void __fastcall ROSTER_SetPartyFlags(int nUnitId, unsigned char nFlags)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (pRec)
    {
        pRec->dwPartyFlags = nFlags;
        PARTY_RebuildRosterUnits();
    }
}

// 0x0047A370
void __fastcall ROSTER_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags)
{
    if (!ROSTER_FindRosterUnit(nUnitId1))
        return;
    PLAYERLIST_AddRosterInfo(nUnitId1, nUnitId2);
    GFXUTIL_SetRelationFlags(nUnitId1, nUnitId2, wFlags);
    PARTY_RebuildRosterUnits();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nUnitId2 == (!pPlayer ? -1 : pPlayer->dwUnitId))
        WARDENCLIENT_UpdateOwnerPetFlags(nUnitId1);
}

// 0x0047A3D0
void __fastcall ROSTER_AddCorpse(int nUnitId, int nCorpseId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (!pRec)
    {
        pRec = (D2StoredUnitRecordStrc*)FOG_Alloc(sizeof(D2StoredUnitRecordStrc), ".\\GAME\\Roster.cpp", 0x686, 0);
        D2_ASSERT(pRec, 0x687);
        memset(pRec, 0, sizeof(D2StoredUnitRecordStrc));
        pRec->dwUnitId = nUnitId;
        pRec->pNext = gpStoredUnits2;
        gpStoredUnits2 = pRec;
    }
    for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == nCorpseId)
            return;
    }
    D2RosterCorpseStrc* pNew = (D2RosterCorpseStrc*)FOG_Alloc(sizeof(D2RosterCorpseStrc), ".\\GAME\\Roster.cpp", 0x697, 0);
    D2_ASSERT(pNew, 0x698);
    memset(pNew, 0, sizeof(D2RosterCorpseStrc));
    pNew->dwCorpseId = nCorpseId;
    pNew->pNext = pRec->pCorpse;
    pRec->pCorpse = pNew;
}

// 0x0047A490
void __fastcall ROSTER_DropCorpseEntry(int nUnitId, int nCorpseId)
{
    D2RosterCorpseStrc* pPrev = 0;
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    if (!pRec)
        return;
    for (D2RosterCorpseStrc* pCorpse = pRec->pCorpse; pCorpse; pCorpse = pCorpse->pNext)
    {
        if (pCorpse->dwCorpseId == nCorpseId)
        {
            if (pPrev)
                pPrev->pNext = pCorpse->pNext;
            else
                pRec->pCorpse = pCorpse->pNext;
            FOG_Free(pCorpse, ".\\GAME\\Roster.cpp", 0x6BD, 0);
            return;
        }
        pPrev = pCorpse;
    }
}

// 0x0047A4F0
int __fastcall ROSTER_CanLoot(int nUnitId1, int nUnitId2)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId2);
    if (pRec)
    {
        const int nRecId = pRec->dwUnitId;
        if (nUnitId1 == nRecId)
            return 1;
        if (GFXUTIL_TestRelationFlags(nRecId, nUnitId1, 1))
            return 1;
    }
    return 0;
}

// 0x0047A520
int __fastcall ROSTER_IsSameParty(int nUnitId1, int nUnitId2)
{
    D2StoredUnitRecordStrc* pRec1 = ROSTER_FindRosterUnit(nUnitId1);
    D2StoredUnitRecordStrc* pRec2 = ROSTER_FindRosterUnit(nUnitId2);
    if (pRec1 && pRec2 && pRec1->wPartyId == pRec2->wPartyId && pRec1->wPartyId != 0xFFFF)
        return 1;
    return 0;
}

// 0x0047A560
int __cdecl ROSTER_IsAnyoneHostile()
{
    D2StoredUnitRecordStrc* pRoster = gpStoredUnits;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
    for (; pRoster; pRoster = pRoster->pNext)
    {
        if (GFXUTIL_TestRelationFlags(pRoster->dwUnitId, nPlayerId, 8))
            return 1;
    }
    return 0;
}

// 0x0047A5B0
int __fastcall ROSTER_IsHostileToPlayer(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && GFXUTIL_TestRelationFlags(pEntry->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId, 8))
        return 1;
    return 0;
}

// 0x0047A5E0
int __fastcall ROSTER_IsPlayerHostile(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 8))
        return 1;
    return 0;
}

// 0x0047A610
int __fastcall ROSTER_AllowsPlayerLoot(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && GFXUTIL_TestRelationFlags(pEntry->dwUnitId, !pPlayer ? -1 : pPlayer->dwUnitId, 1))
        return 1;
    return 0;
}

// 0x0047A640
int __fastcall ROSTER_PlayerAllowsLoot(D2StoredUnitRecordStrc* pEntry)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pEntry && pPlayer && GFXUTIL_TestRelationFlags(!pPlayer ? -1 : pPlayer->dwUnitId, pEntry->dwUnitId, 1))
        return 1;
    return 0;
}

// 0x0047A670
extern "C" __declspec(dllexport) int __fastcall ROSTER_IsMaleClass(Obj0047A670* pObj) {
    if (pObj) {
        switch (pObj->nMode1C) {
        case 0:
        case 1:
        case 6:
            return 0;
        }
    }
    return 1;
}

// 0x0047A690
void __fastcall ROSTER_SetPartyLife(int nUnitGUID, unsigned char nLifePct)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitGUID);
    if (pRec)
        pRec->dwPartyLife = nLifePct;
}

// 0x0047A6B0
int __fastcall ROSTER_GetOtherPartyLife(int nUnitId)
{
    D2StoredUnitRecordStrc* pRec = ROSTER_FindRosterUnit(nUnitId);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nUnitId != (!pPlayer ? -1 : pPlayer->dwUnitId) && pRec)
        return pRec->dwPartyLife;
    return 0;
}

// build: symbol @D2SOUND_SetSoundNoLoop@* 0x00515A30
extern "C" void __fastcall D2SOUND_SetSoundNoLoop(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 815);
    pSound->nValue40 = nValue;
}

// build: symbol @D2SOUND_SetSoundLoopStart@* 0x00515A60
extern "C" void __fastcall D2SOUND_SetSoundLoopStart(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 826);
    pSound->nValue44 = nValue;
}

extern "C" void __fastcall CLIENTS_SetPlayerUnitAlive(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 518);
    pClient->dwFlags |= 1;
}

#include "gen/data/Source/D2Client/GAME/Roster.inc"
