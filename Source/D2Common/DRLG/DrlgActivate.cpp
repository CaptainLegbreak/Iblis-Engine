#include "D2LevelIds.h"
#include "D2Win32Base.h"
#include "D2StormLink.h"
#include "D2CmpCache.h"
#include "D2Unicode.h"
#include "D2DrlgTiles.h"
#include "D2Path.h"
#include "D2Win32Types.h"
#include "D2Skills.h"
#include "D2TxtTables.h"

#include "D2Common.h"

#include "D2Drlg.h"

#include "D2Structs.h"

#include "D2DrlgRooms.h"
#include "D2CommonLevelNode.h"

struct D2DrlgStrc;

struct D2DrlgTableRefStrc;

struct D2Entry0061B7E0Strc;

struct D2Owner0061B7E0Strc;

struct D2ColorRecordStrc;

struct D2DrlgTableRefStrc
{
    char unk0x00[0x28];
    int nValue;
    int nIndex;
};

extern int gnTimeRates[]; // 0x007443E4

int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg); // 0x00642A00

int __fastcall DRLG_IsTownLevel(int nLevelId); // 0x006426A0

void __fastcall DRLGACTIVATE_RoomExPropagateUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus); // 0x0061B5B0

void __fastcall DRLGROOM_InitNearRooms(void* pContext, D2DrlgRoomStrc* pNode); // 0x0066C370

void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EE40

void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x006422A0

struct D2Entry0061B7E0Strc
{
    unsigned char unk_00[0x1C];
    D2Entry0061B7E0Strc* pSelf1C;
    unsigned char unk_20[0x10];
    int nValue30;
    unsigned char unk_34[0x10];
    unsigned char nIndex44;
    unsigned char unk_45[0xA3];
    D2Entry0061B7E0Strc* pSelfE8;
};

struct D2Owner0061B7E0Strc
{
    unsigned char unk_00[0xA0];
    D2Entry0061B7E0Strc pEntries[4];
};

struct D2ColorRecordStrc
{
    char unk0x00[0x18];
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

static int gnRoomStats_0096C8B8; // 0x0096C8B8

static int gnRoomStats_0096C8BC; // 0x0096C8BC

static int gnRoomStats_0096C8C0; // 0x0096C8C0

static int gnRoomStats_0096C8C4; // 0x0096C8C4

void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0066F240

static void DRLGACTIVATE_ForceRoomExStatusImpl(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus); // 0x0061B210

#define DRLGROOMFLAG_HAS_ROOM 0x100000

#define DRLGROOMFLAG_HASPORTAL 0x400000

#define DRLGROOMFLAG_TILELIB_LOADED 0x1000000

#define DRLGROOMFLAG_PRESET_UNITS_ADDED 0x2000000

#define DRLGTYPE_PRESET 2

struct D2DrlgEnvironmentStrc;

struct D2DrlgActStrc;

enum D2C_J07DungeonConstants
{
    UNITFLAGINDEX_ISCLIENTUNIT = 22,
    UNITFLAG_J07_PATHUPDATE = 0x800000,
    UNITFLAGEX_J07_REMOVED = 0x20,
};

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit); // 0x0064C450

void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0064CA10

void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom); // 0x0061A2C0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const int gnTownLevelIdsByAct[5]; // 0x006E7D1C

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg); // 0x00642230

D2DrlgStrc* __fastcall DRLGROOM_GetDrlgFromRoomEx(D2DrlgRoomStrc* pRoom); // 0x0066C0B0

static int DRLGACTIVATE_RoomEx_EnsureHasRoom(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);

static int gnStatsClientAllocatedRooms; // 0x0096C8B8

static int gnStatsClientFreedRooms; // 0x0096C8BC

static int gnStatsAllocatedRooms; // 0x0096C8C4

static int gnStatsFreedRooms; // 0x0096C8C0

static inline D2DrlgRoomStrc* DRLGACTIVATE_RoomExStatusList_GetFirst(D2DrlgStrc* pDrlg, unsigned char nStatus);

static int gStatsClientFreedRooms; // 0x0096C8BC

static int gStatsClientAllocatedRooms; // 0x0096C8B8

static int gStatsFreedRooms; // 0x0096C8C0

static int gStatsAllocatedRooms; // 0x0096C8C4

void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg);

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0

D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel); // 0x00642C30

D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0061B730

static void DRLGACTIVATE_RoomSetAndPropagateStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus);

void __fastcall DRLGACTIVATE_SetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoomHint);

void __fastcall DRLGACTIVATE_ChangeClientRoom(D2DrlgRoomStrc* pPreviousRoom, D2DrlgRoomStrc* pNewRoom);

static void DRLGACTIVATE_RoomExStatusUnlink(D2DrlgRoomStrc* pDrlgRoom);

static void DRLGACTIVATE_ForceRoomExStatus_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom);

static void DRLGACTIVATE_ForceRoomExStatus_ClientInSight(D2DrlgRoomStrc* pDrlgRoom);

static void DRLGACTIVATE_ForceRoomExStatus_Untile(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInSight(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExSetStatus_Untile(D2DrlgRoomStrc* pDrlgRoom);

static void DRLGACTIVATE_RoomExIdentifyRealStatus(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientInSight(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExStatusUnset_Untile(D2DrlgRoomStrc* pDrlgRoom);

static void DRLGACTIVATE_ForceRoomExStatus_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom);

// 0x0061B170
static inline void DRLGACTIVATE_InitRoomsInitTimeout(D2DrlgStrc* pDrlg)
{
    pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) ? 5 : 7;
}

// 0x0061B190
static int DRLGACTIVATE_RoomEx_EnsureHasRoom(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgStrc* pDrlg = pDrlgRoom->ptDrlgLevel->pDrlg;
    if (!pDrlgRoom->nRoomsNear)
        DRLGROOM_InitNearRooms(pMemPool, pDrlgRoom);
    DRLGROOMTILE_InitRoomGrids(pDrlgRoom);
    DRLGROOMTILE_AddRoomMapTiles(pDrlgRoom);
    DRLG_CreateRoomForRoomEx(pDrlg, pDrlgRoom);
    ++pDrlg->nRoomsInitSinceLastUpdate;
    ++pDrlg->nAllocatedRooms;
    return 1;
}

// 0x0061B1D0
static void DRLGACTIVATE_RoomExStatusUnlink(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->pStatusPrev && pDrlgRoom->pStatusNext)
    {
        pDrlgRoom->pStatusPrev->pStatusNext = pDrlgRoom->pStatusNext;
        pDrlgRoom->pStatusNext->pStatusPrev = pDrlgRoom->pStatusPrev;
        pDrlgRoom->pStatusPrev = 0;
        pDrlgRoom->pStatusNext = 0;
    }
}

// 0x0061B210
static void DRLGACTIVATE_ForceRoomExStatusImpl(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    if (pDrlgRoom->fRoomStatus == nStatus)
        return;

    DRLGACTIVATE_RoomExStatusUnlink(pDrlgRoom);
    if (nStatus < 4)
    {
        D2DrlgRoomStrc* pHead = &pDrlgRoom->ptDrlgLevel->pDrlg->tStatusRoomsLists[nStatus];
        pDrlgRoom->pStatusNext = pHead;
        pDrlgRoom->pStatusPrev = pHead->pStatusPrev;
        pHead->pStatusPrev->pStatusNext = pDrlgRoom;
        pHead->pStatusPrev = pDrlgRoom;
        pDrlgRoom->fRoomStatus = nStatus;
    }
}

// 0x0061B290
static void DRLGACTIVATE_ForceRoomExStatus_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 0);
}

// 0x0061B2A0
static void DRLGACTIVATE_ForceRoomExStatus_ClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 1);
}

// 0x0061B2B0
static void DRLGACTIVATE_ForceRoomExStatus_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 3);
}

// 0x0061B2C0
void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatus_ClientInRoom(pDrlgRoom);
}

// 0x0061B2D0
void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom->pRoom && !(pDrlgRoom->dwFlags & 0x100000))
    {
        D2DrlgStrc* pDrlg = pDrlgRoom->ptDrlgLevel->pDrlg;
        DRLGACTIVATE_RoomEx_EnsureHasRoom(pDrlg->pMempool, pDrlgRoom);
        pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) == 0 ? 7 : 5;
    }
    if (pDrlgRoom->fRoomStatus > 1)
        DRLGACTIVATE_ForceRoomExStatus_ClientInSight(pDrlgRoom);
}

// 0x0061B320
void __fastcall DRLGACTIVATE_RoomExSetStatus_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & 0x1000000))
        DRLGROOMTILE_LoadDT1FilesForRoom(pDrlgRoom);
    if (pDrlgRoom->nType == 2 && !(pDrlgRoom->dwFlags & 0x2000000))
        DRLGPRESET_SpawnHardcodedPresetUnits(pDrlgRoom);
    if (pDrlgRoom->fRoomStatus > 3)
        DRLGACTIVATE_ForceRoomExStatus_Untile(pDrlgRoom);
}

void __stdcall sub_M121_Emit_0061B170(D2DrlgStrc* pDrlg) { DRLGACTIVATE_InitRoomsInitTimeout(pDrlg); }

// 0x0061B360
static inline void DRLGACTIVATE_SetStatusIfUnreferenced(D2DrlgRoomStrc* pDrlgRoom, int nStatus)
{
    if (pDrlgRoom->fRoomStatus >= nStatus)
    {
        for (int i = 0; i <= nStatus; ++i)
        {
            if (pDrlgRoom->wRoomsInList[i])
            {
                return;
            }
        }
        gRoomExSetStatus[nStatus](pDrlgRoom);
    }
}

static bool RoomExHasRefCount(D2DrlgRoomStrc* pDrlgRoom, int nMaxStatus)
{
    for (int i = 0; i <= nMaxStatus; i++)
    {
        if (pDrlgRoom->wRoomsInList[i])
        {
            return true;
        }
    }
    return false;
}

typedef void (__fastcall* LEVELNODEFN)(D2CommonLevelNodeStrc* pNode);
extern const LEVELNODEFN gpfnRoomExSetStatus[]; // 0x00744384
void __fastcall DRLGROOM_InitNearRooms(void* pContext, D2CommonLevelNodeStrc* pNode); // 0x0066C370
static inline int sub_F45_IsFirstAtLevel(D2CommonLevelNodeStrc* pNode, int nLevel)
{
    for (int i = 0; i <= nLevel; ++i)
    {
        if (pNode->wLevelCounts[i])
            return 0;
    }
    return 1;
}
static inline void sub_F45_VisitChild(D2CommonLevelNodeStrc* pChild, int nLevel)
{
    if (pChild->nMaxLevel >= nLevel && sub_F45_IsFirstAtLevel(pChild, nLevel))
        gpfnRoomExSetStatus[nLevel](pChild);
    ++pChild->wLevelCounts[nLevel];
}

// 0x0061B390
void __fastcall DRLGACTIVATE_RoomExPropagateSetStatus(void* pContext, D2CommonLevelNodeStrc* pNode, unsigned char nLevel)
{
    if (!pNode->nChildren)
        DRLGROOM_InitNearRooms(pContext, pNode);
    if (nLevel < 3)
    {
        for (int i = 0; i < pNode->nChildren; ++i)
        {
            D2CommonLevelNodeStrc* pChild = pNode->ppChildren[i];
            DRLGACTIVATE_RoomExPropagateSetStatus(pContext, pChild, nLevel + 1);
            sub_F45_VisitChild(pChild, nLevel);
        }
    }
    else
    {
        for (int i = 0; i < pNode->nChildren; ++i)
            sub_F45_VisitChild(pNode->ppChildren[i], nLevel);
    }
}

// 0x0061B490
static void DRLGACTIVATE_RoomSetAndPropagateStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    DRLGACTIVATE_RoomExPropagateSetStatus(pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, pDrlgRoom, nStatus + 1);
    const int nIndex = nStatus;
    if (pDrlgRoom->fRoomStatus >= nIndex)
    {
        if (!RoomExHasRefCount(pDrlgRoom, nIndex))
        {
            gRoomExSetStatus[nIndex](pDrlgRoom);
        }
    }
    ++pDrlgRoom->wRoomsInList[nIndex];
}

// 0x0061B4F0
static void DRLGACTIVATE_RoomExIdentifyRealStatus(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->fRoomStatus < 4 && pDrlgRoom->wRoomsInList[pDrlgRoom->fRoomStatus])
        return;

    unsigned char nStatus;
    for (nStatus = 0; nStatus < 4; ++nStatus)
    {
        if (pDrlgRoom->wRoomsInList[nStatus])
            break;
    }
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, nStatus);
    pDrlgRoom->fRoomStatus = nStatus;
}

// 0x0061B530
void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientInRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
}

// 0x0061B540
void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientInSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
}

// 0x0061B550
void __fastcall DRLGACTIVATE_RoomExStatusUnset_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
}

// 0x0061B560
void __fastcall DRLGACTIVATE_RoomExStatusUnset_Untile(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->fRoomStatus != 4)
    {
        DRLGACTIVATE_RoomExIdentifyRealStatus(pDrlgRoom);
        if (pDrlgRoom->fRoomStatus == 4 && DRLG_IsOnClient(pDrlgRoom->ptDrlgLevel->pDrlg))
            DRLGROOMTILE_FreeRoom(pDrlgRoom, 0);
    }
}

void __stdcall sub_M121_Emit_0061B360(D2DrlgRoomStrc* pDrlgRoom, int nStatus) { DRLGACTIVATE_SetStatusIfUnreferenced(pDrlgRoom, nStatus); }

// 0x0061B5A0
static inline void DRLGACTIVATE_CallRoomExUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    gRoomExUnsetStatus[nStatus](pDrlgRoom);
}

// 0x0061B5B0
void __fastcall DRLGACTIVATE_RoomExPropagateUnsetStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        D2DrlgRoomStrc* pNearRoom = pDrlgRoom->ppRoomsNear[i];
        if (pNearRoom)
        {
            --pNearRoom->wRoomsInList[nStatus];
            gRoomExUnsetStatus[nStatus](pNearRoom);
            if (nStatus < 3)
            {
                DRLGACTIVATE_RoomExPropagateUnsetStatus(pNearRoom, nStatus + 1);
            }
        }
    }
}

void __stdcall sub_M121_Emit_0061B5A0(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus) { DRLGACTIVATE_CallRoomExUnsetStatus(pDrlgRoom, nStatus); }

// 0x0061B610
static inline void DRLGACTIVATE_RoomUnsetAndPropagateStatus(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus)
{
    if (pDrlgRoom->wRoomsInList[nStatus])
    {
        --pDrlgRoom->wRoomsInList[nStatus];
        gRoomExUnsetStatus[nStatus](pDrlgRoom);
        DRLGACTIVATE_RoomExPropagateUnsetStatus(pDrlgRoom, nStatus + 1);
    }
}

// 0x0061B640
void __fastcall DRLGACTIVATE_SetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoomHint)
{
    D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, nLevelId);
    if (pDrlgRoomHint && pDrlgRoomHint->ptDrlgLevel->eLevelId != nLevelId)
    {
        pDrlgRoomHint = 0;
    }
    D2DrlgRoomStrc* pDrlgRoom = DRLG_GetRoomExFromCoordinates(nX, nY, pDrlg, pDrlgRoomHint, pLevel);
    if (!pDrlgRoom->wRoomsInList[1])
    {
        DRLGACTIVATE_RoomSetAndPropagateStatus(pDrlgRoom, 1);
    }
}

// 0x0061B690
void __fastcall DRLGACTIVATE_UnsetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoomHint)
{
    D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, nLevelId);
    if (pDrlgRoomHint && pDrlgRoomHint->ptDrlgLevel->eLevelId != nLevelId)
    {
        pDrlgRoomHint = 0;
    }
    D2DrlgRoomStrc* pDrlgRoom = DRLG_GetRoomExFromCoordinates(nX, nY, pDrlg, pDrlgRoomHint, pLevel);
    if (pDrlgRoom && pDrlgRoom->wRoomsInList[1])
    {
        --pDrlgRoom->wRoomsInList[1];
        gRoomExUnsetStatus[1](pDrlgRoom);
        DRLGACTIVATE_RoomExPropagateUnsetStatus(pDrlgRoom, 2);
    }
}

// 0x0061B6F0
void __fastcall DRLGACTIVATE_ChangeClientRoom(D2DrlgRoomStrc* pPreviousRoom, D2DrlgRoomStrc* pNewRoom)
{
    if (pPreviousRoom == pNewRoom)
    {
        return;
    }
    if (pNewRoom)
    {
        DRLGACTIVATE_RoomSetAndPropagateStatus(pNewRoom, 0);
    }
    if (pPreviousRoom && pPreviousRoom->wRoomsInList[0])
    {
        --pPreviousRoom->wRoomsInList[0];
        gRoomExUnsetStatus[0](pPreviousRoom);
        DRLGACTIVATE_RoomExPropagateUnsetStatus(pPreviousRoom, 1);
    }
}

static inline void DUNGEON_GetClientUnitFlag(D2UnitStrc* pUnit, unsigned int dwFlags, int* pResult)
{
    *pResult = pUnit ? (dwFlags >> UNITFLAGINDEX_ISCLIENTUNIT) & 1 : 0;
}

// 0x0061B730
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_TILELIB_LOADED))
        DRLGROOMTILE_LoadDT1FilesForRoom(pDrlgRoom);

    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_PRESET_UNITS_ADDED) && pDrlgRoom->nType == DRLGTYPE_PRESET)
        DRLGPRESET_SpawnHardcodedPresetUnits(pDrlgRoom);

    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_HAS_ROOM))
    {
        D2DrlgStrc* pDrlg = pDrlgRoom->ptDrlgLevel->pDrlg;
        if (!pDrlgRoom->nRoomsNear)
            DRLGROOM_InitNearRooms(pDrlg->pMempool, pDrlgRoom);

        DRLGROOMTILE_InitRoomGrids(pDrlgRoom);
        DRLGROOMTILE_AddRoomMapTiles(pDrlgRoom);
        DRLG_CreateRoomForRoomEx(pDrlg, pDrlgRoom);
        ++pDrlg->nRoomsInitSinceLastUpdate;
        ++pDrlg->nAllocatedRooms;
    }
    return pDrlgRoom->pRoom;
}

// 0x0061B7B0
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_StreamRoomAtCoords(D2DrlgStrc* pDrlg, int nX, int nY)
{
    if (D2DrlgRoomStrc* pDrlgRoom = DRLG_GetRoomExFromCoordinates(nX, nY, pDrlg, 0, 0))
    {
        return DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
    }
    return 0;
}

// 0x0061B7E0
void __fastcall DRLGACTIVATE_InitializeRoomExStatusLists(D2Owner0061B7E0Strc* pOwner)
{
    unsigned int i;
    D2Entry0061B7E0Strc* pEntry;
    for (i = 0, pEntry = pOwner->pEntries; i < 4; ++i, ++pEntry)
    {
        pEntry->nIndex44 = (unsigned char)i;
        pEntry->pSelf1C = pEntry;
        pEntry->pSelfE8 = pEntry;
    }
}

void __stdcall sub_M121_Emit_0061B610(D2DrlgRoomStrc* pDrlgRoom, unsigned char nStatus) { DRLGACTIVATE_RoomUnsetAndPropagateStatus(pDrlgRoom, nStatus); }

// 0x0061B810
static inline D2DrlgRoomStrc* DRLGACTIVATE_RoomExStatusList_GetFirst(D2DrlgStrc* pDrlg, unsigned char nStatus)
{
    if (pDrlg->tStatusRoomsLists[nStatus].pStatusNext != &pDrlg->tStatusRoomsLists[nStatus])
    {
        return pDrlg->tStatusRoomsLists[nStatus].pStatusNext;
    }
    return 0;
}

// 0x0061B840
D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInClientSight(D2DrlgStrc* pDrlg)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGACTIVATE_RoomExStatusList_GetFirst(pDrlg, 0);
    if (!pDrlgRoom)
        pDrlgRoom = DRLGACTIVATE_RoomExStatusList_GetFirst(pDrlg, 1);
    if (pDrlgRoom)
        return pDrlgRoom->pRoom;
    return 0;
}

D2DrlgRoomStrc* __stdcall sub_M121_Emit_0061B810(D2DrlgStrc* pDrlg, unsigned char nStatus) { return DRLGACTIVATE_RoomExStatusList_GetFirst(pDrlg, nStatus); }

static inline D2Entry0061B7E0Strc* sub_0061B870_GetFirst(D2Owner0061B7E0Strc* pOwner, unsigned char nIndex)
{
    if (pOwner->pEntries[nIndex].pSelf1C != &pOwner->pEntries[nIndex])
    {
        return pOwner->pEntries[nIndex].pSelf1C;
    }
    return 0;
}

static inline int sub_0061B870_IsListHead(D2Owner0061B7E0Strc* pOwner, D2Entry0061B7E0Strc* pNext, unsigned char nIndex)
{
    return pNext == &pOwner->pEntries[nIndex];
}

static inline int sub_0061B870_IsStatus(D2Entry0061B7E0Strc* pEntry, int nStatus)
{
    if (pEntry->nIndex44 == nStatus)
    {
        return 1;
    }
    return 0;
}

// 0x0061B870
int __fastcall DRLGACTIVATE_GetNextValue(D2Owner0061B7E0Strc* pOwner, D2Entry0061B7E0Strc* pEntry)
{
    unsigned char nIndex = pEntry->nIndex44;
    D2Entry0061B7E0Strc* pNext = pEntry->pSelf1C;
    if (sub_0061B870_IsStatus(pEntry, 0) && sub_0061B870_IsListHead(pOwner, pNext, nIndex))
        pNext = sub_0061B870_GetFirst(pOwner, 1);
    return pNext ? pNext->nValue30 : 0;
}

// 0x0061B8B0
static inline void DRLGACTIVATE_UpdateRoomsAllocationStats(D2DrlgStrc* pDrlg)
{
    if (DRLG_IsOnClient(pDrlg))
    {
        gnRoomStats_0096C8B8 = pDrlg->nAllocatedRooms;
        gnRoomStats_0096C8BC = pDrlg->nFreedRooms;
    }
    else
    {
        gnRoomStats_0096C8C4 = pDrlg->nAllocatedRooms;
        gnRoomStats_0096C8C0 = pDrlg->nFreedRooms;
    }
}

// 0x0061B8F0
void __fastcall DRLGACTIVATE_GetRoomsAllocationStats(int* pOutStatsClientAllocatedRooms, int* pOutStatsClientFreedRooms, int* pOutStatsAllocatedRooms, int* pOutStatsFreedRooms)
{
    *pOutStatsClientAllocatedRooms = gStatsClientAllocatedRooms;
    *pOutStatsClientFreedRooms = gStatsClientFreedRooms;
    *pOutStatsAllocatedRooms = gStatsAllocatedRooms;
    *pOutStatsFreedRooms = gStatsFreedRooms;
}

// 0x0061B920
void __stdcall DRLGACTIVATE_Update(D2DrlgStrc* pDrlg)
{
    if (DRLG_IsOnClient(pDrlg))
    {
        gnStatsClientAllocatedRooms = pDrlg->nAllocatedRooms;
        gnStatsClientFreedRooms = pDrlg->nFreedRooms;
    }
    else
    {
        gnStatsAllocatedRooms = pDrlg->nAllocatedRooms;
        gnStatsFreedRooms = pDrlg->nFreedRooms;
    }

    if (pDrlg->nRoomsInitSinceLastUpdate > 1)
    {
        pDrlg->nRoomsInitSinceLastUpdate = 0;
        return;
    }

    --pDrlg->nRoomsInitTimeout;
    if (pDrlg->nRoomsInitTimeout == 0)
    {
        pDrlg->nRoomsInitTimeout = DRLG_IsOnClient(pDrlg) == 0 ? 7 : 5;
        if (!pDrlg->pDrlgRoom || pDrlg->pDrlgRoom->fRoomStatus != 2)
            pDrlg->pDrlgRoom = pDrlg->tStatusRoomsLists[2].pStatusNext;

        if (D2DrlgRoomStrc* pDrlgRoomExListHead = pDrlg->pDrlgRoom)
        {
            D2DrlgRoomStrc* pCurRoomEx = pDrlgRoomExListHead;
            do
            {
                if (!(pCurRoomEx->dwFlags & 0x100000) && pCurRoomEx != &pDrlg->tStatusRoomsLists[2] && !pCurRoomEx->pRoom)
                    DRLGACTIVATE_RoomEx_EnsureHasRoom(pDrlg->pMempool, pCurRoomEx);
                pCurRoomEx = pCurRoomEx->pStatusNext;
            }
            while (pCurRoomEx != pDrlgRoomExListHead && pDrlg->nRoomsInitSinceLastUpdate < 1);

            pDrlg->pDrlgRoom = pCurRoomEx;
            pDrlg->nRoomsInitSinceLastUpdate = 0;
        }
    }
}

void __stdcall sub_M121_Emit_0061B8B0(D2DrlgStrc* pDrlg) { DRLGACTIVATE_UpdateRoomsAllocationStats(pDrlg); }

// 0x0061BA10
static inline int DRLGACTIVATE_CanUntileLevel(int nLevelId)
{
    if (DRLG_IsTownLevel(nLevelId))
    {
        return 0;
    }
    return nLevelId != LEVEL_ROCKYSUMMIT;
}

// 0x0061BA30
int __fastcall DRLGACTIVATE_TestRoomCanUnTile(D2DrlgRoomStrc* ptRoom)
{
    if (ptRoom->dwFlags & DRLGROOMFLAG_HASPORTAL)
        return 0;

    D2_ASSERT(!DRLG_IsOnClient(DRLGROOM_GetDrlgFromRoomEx(ptRoom)), 0x2E7);

    if (ptRoom->fRoomStatus <= 1)
        return 0;

    int nLevelId = ptRoom->ptDrlgLevel->eLevelId;
    if (DRLG_IsTownLevel(nLevelId) || nLevelId == LEVEL_ROCKYSUMMIT)
    {
        for (D2DrlgRoomStrc* pCurrentRoomEx = ptRoom->ptDrlgLevel->ptRoomFirst; pCurrentRoomEx; pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext)
        {
            if (pCurrentRoomEx->fRoomStatus <= 1)
                return 0;
        }
    }
    return 1;
}

// 0x0061BAC0
void __fastcall DRLGACTIVATE_ToggleHasPortalFlag(D2DrlgRoomStrc* pDrlgRoom, int bReset)
{
    if (bReset)
        pDrlgRoom->dwFlags &= ~0x400000;
    else
        pDrlgRoom->dwFlags |= 0x400000;
}

// 0x0061BAE0
unsigned char __fastcall DRLGACTIVATE_GetRoomStatusFlags(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->fRoomStatus;
}

// 0x0061BAF0
static void DRLGACTIVATE_ForceRoomExStatus_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_ForceRoomExStatusImpl(pDrlgRoom, 2);
    if (pDrlgRoom->wRoomsInList[1])
        DRLGACTIVATE_RoomExSetStatus_ClientInSight(pDrlgRoom);
}

// 0x0061BB10
void __fastcall DRLGACTIVATE_RoomExSetStatus_ClientOutOfSight(D2DrlgRoomStrc* pDrlgRoom)
{
    if ((pDrlgRoom->dwFlags & 0x1000000) && (pDrlgRoom->nType != 2 || (pDrlgRoom->dwFlags & 0x2000000)))
    {
        if (pDrlgRoom->fRoomStatus > 2)
            DRLGACTIVATE_ForceRoomExStatus_ClientOutOfSight(pDrlgRoom);
    }
}

int __stdcall sub_M121_Emit_0061BA10(int nLevelId) { return DRLGACTIVATE_CanUntileLevel(nLevelId); }

// 0x0061BB50
static inline void DRLGACTIVATE_ApplyTimeRate(D2DrlgTableRefStrc* pRecord)
{
    pRecord->nValue = gnTimeRates[pRecord->nIndex];
}

void __stdcall sub_M121_Emit_0061BB50(D2DrlgTableRefStrc* pRecord) { DRLGACTIVATE_ApplyTimeRate(pRecord); }

// 0x0061BB60
static void __stdcall DRLGACTIVATE_ApplyArreatSummitLightColor(D2ColorRecordStrc* pRecord, int nId)
{
    if (nId == 0x78)
    {
        pRecord->nRed = 0xF5;
        pRecord->nGreen = 0xF0;
        pRecord->nBlue = 0xFF;
    }
}

// calling-convention shim (not game code)
void __stdcall sub_K14_EmitSetColorForId(D2ColorRecordStrc* pRecord, int nId)
{
    DRLGACTIVATE_ApplyArreatSummitLightColor(pRecord, nId);
}

#include "gen/data/Source/D2Common/DRLG/DrlgActivate.inc"
