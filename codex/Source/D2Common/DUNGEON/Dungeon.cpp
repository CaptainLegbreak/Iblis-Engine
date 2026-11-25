#include "D2Common.h"

#include "D2Win32Base.h"

#include "D2StormLink.h"

#include "D2CmpCache.h"

#include "D2Structs.h"

#include "D2Unicode.h"

#include "D2Drlg.h"

#include "D2DrlgRooms.h"

#include "D2DrlgTiles.h"

#include "D2Path.h"

#include "D2Win32Types.h"

#include "D2Skills.h"

#include "D2TxtTables.h"
#include "D2DrlgDelete.h"
#include "D2CommonLevelNode.h"

struct D2DrlgRoomStrc;

#pragma function(memset)

#define ROOMFLAG_2 0x00000002

#define ROOMFLAG_4 0x00000004

#define gpUniquePrefixTxt (gpUniqueNameTxtTables[1])

#define gpUniqueSuffixTxt (gpUniqueNameTxtTables[2])

#define gpUniqueAppellationTxt (gpUniqueNameTxtTables[3])

#define gnUniquePrefixTxtRecordCount (gnUniqueNameTxtRecordCounts[1])

#define gnUniqueSuffixTxtRecordCount (gnUniqueNameTxtRecordCounts[2])

#define gnUniqueAppellationTxtRecordCount (gnUniqueNameTxtRecordCounts[3])

struct D2GameStrc;

struct D2DrlgStrc;

struct D2DrlgActStrc;

struct D2DrlgDeleteStrc;

struct D2PresetUnitStrc;

struct D2DrlgTileDataStrc;

struct D2RoomCoordListStrc;

struct D2DrlgRoomTilesStrc;

struct D2ClientStrc;

struct RoomEx;

struct Coord;

struct D2DrlgCoordsStrc;

struct Obj00619720;

struct sub_Z16_EmitRoomHolder;

union D2SeedStrc;

struct D2ActRoom00619DA0Strc;

struct D2Act00619DA0Strc;

struct Obj00619EE0;

struct Unicode;

struct Room;

struct Obj0061AFA0;

struct D2ActiveRoomStrc;

struct D2UnitStrc;

typedef void (__stdcall* AUTOMAPFN)(void* pRoom);

typedef void (__stdcall* TOWNAUTOMAPFN)(int nLevelId, int nPickedFile, int nX, int nY);

typedef void (__fastcall* ACTCALLBACKFN)(D2ActiveRoomStrc* pRoom);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2DrlgStrc* __fastcall DRLG_AllocDrlg(D2DrlgActStrc* pAct, unsigned char nActNo, void* hArchive, unsigned int nInitSeed, int nTownLevelId, unsigned int nFlags, D2GameStrc* pGame, unsigned char nDifficulty, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap); // 0x00642DA0

D2DrlgEnvironmentStrc* __fastcall ENVIRONMENT_AllocDrlgEnvironment(void* pMemPool); // 0x0061BE40

void __fastcall DRLGANIM_InitCache(D2DrlgStrc* pDrlg, void** ppTileData); // 0x00642A30

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall DRLGWARP_ToggleRoomTilesEnableFlag(D2DrlgRoomStrc* pDrlgRoom, int bEnabled); // 0x0066AB70

D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromUnit(D2DrlgRoomStrc* pDrlgRoom, D2UnitStrc* pUnit); // 0x0066AF80

void __fastcall DRLGROOM_GetRGB_IntensityFromRoomEx(D2DrlgRoomStrc* pDrlgRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0066BFD0

D2ActiveRoomStrc* __fastcall DRLGWARP_GetLevelEntryRoom(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY); // 0x0066B2B0

D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BFA0

void __fastcall DRLGACTIVATE_SetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B640

void __fastcall DRLGACTIVATE_UnsetClientIsInSight(D2DrlgStrc* pDrlg, int nLevelId, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B690

void __fastcall DRLGACTIVATE_ChangeClientRoom(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2); // 0x0061B6F0

D2ActiveRoomStrc* __fastcall DRLGACTIVATE_StreamRoomAtCoords(D2DrlgStrc* pDrlg, int nX, int nY); // 0x0061B7B0

int __fastcall DRLGROOM_GetLevelId(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BAB0

int __fastcall DRLGROOM_GetLevelIdFromPopulatedRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BB20

int __fastcall DRLGROOM_HasWaypoint(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BB60

const char* __fastcall DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BBA0

D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInClientSight(D2DrlgStrc* pDrlg); // 0x0061B840

D2ActiveRoomStrc* __fastcall DRLGACTIVATE_GetARoomInSightButWithoutClient(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x0061B870

int __fastcall DRLGACTIVATE_TestRoomCanUnTile(D2DrlgRoomStrc* pDrlgRoom); // 0x0061BA30

void __fastcall DRLG_UpdateLevelActivityOnRoomChange(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2); // 0x00643020

void __fastcall DRLG_UpdateAndFreeInactiveRooms(D2DrlgStrc* pDrlg); // 0x00643200

int __fastcall DRLGROOM_CheckLOSDraw(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BA70

int __fastcall DRLG_IsTownLevel(int nLevelId); // 0x006426A0

int __fastcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x00642740

unsigned int __fastcall DRLGROOM_CheckMazeRoomOutdoorFlag(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BA90

int __fastcall DRLG_GetNumberOfPopulatedRoomsInLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BE0

int* __fastcall DRLG_GetRoomCenterX_RoomWarpXFromRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x00642380

void __fastcall DRLGWARP_UpdateWarpRoomSelect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId); // 0x0066AB90

void __fastcall DRLGWARP_UpdateWarpRoomDeselect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId); // 0x0066ABE0

void __fastcall DRLGPRESET_UpdatePops(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int bOtherRoom); // 0x006671E0

D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordListAtSubtile(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY); // 0x0066CEB0

D2RoomCoordListStrc* __fastcall DRLGLOGIC_GetRoomCoordList(D2DrlgRoomStrc* pDrlgRoom); // 0x0066CF30

void __fastcall DRLGACTIVATE_ToggleHasPortalFlag(D2DrlgRoomStrc* pDrlgRoom, int bReset); // 0x0061BAC0

void __fastcall DRLGANIM_AnimateTiles(D2DrlgRoomStrc* pDrlgRoom); // 0x0066D410

void __fastcall DRLGANIM_UpdateFrameInAdjacentRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2); // 0x0066D750

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

struct Obj00619720 { unsigned int dwUnknown00[6]; unsigned int dwMember18; };

int __fastcall DRLGROOM_GetNumberOfNearRooms(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BCF0

int __fastcall DRLGROOM_ReorderNearRoomList(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc** ppRoomList); // 0x0066BD00

struct sub_Z16_EmitRoomHolder
{
    char unk0x00[0x5C];
    void* pMemory;
};

typedef char sub_G03_AssertRoomSize[sizeof(D2ActiveRoomStrc) == 0x80 ? 1 : -1];

typedef char sub_G03_AssertRoomSeed[(int)&((D2ActiveRoomStrc*)0)->pSeed == 0x6C ? 1 : -1];

typedef char sub_G03_AssertRoomNext[(int)&((D2ActiveRoomStrc*)0)->pRoomNext == 0x7C ? 1 : -1];

typedef char sub_G03_AssertActPool[(int)&((D2DrlgActStrc*)0)->pMemPool == 0x5C ? 1 : -1];

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __fastcall COLLISION_AllocRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0064C900

void __fastcall DRLGROOM_SetRoom(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc* pRoom); // 0x0066BFC0

struct D2ActRoom00619DA0Strc
{
    unsigned char unk_00[0x4C];
    int nX4C;
    int nY50;
    int nWidth54;
    int nHeight58;
    unsigned char unk_5C[0x7C - 0x5C];
    D2ActRoom00619DA0Strc* pNext7C;
};

struct D2Act00619DA0Strc
{
    unsigned char unk_00[0x10];
    D2ActRoom00619DA0Strc* pFirstRoom10;
};

struct Obj00619EE0 {
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
    int nCount28;
};


void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

unsigned char __fastcall DRLGACTIVATE_GetRoomStatusFlags(D2DrlgRoomStrc*); // 0x0061BAE0

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90

struct Room { char pad[0x10]; RoomEx* roomEx[2]; };

void __fastcall DRLGPRESET_GetTombStoneTileCoords(RoomEx*,Coord**,int*); // 0x00666A80

enum { ROOM_SLOT = 0 };

struct Obj0061AFA0 { unsigned char bUnknown00[0x14]; unsigned char bIndex14; unsigned char bUnknown15[0x23]; unsigned int dwRing38[4]; };

struct D2CoordStrc;

struct D2CommonLevelNodeStrc;

typedef tagRECT RECT;


typedef int (__stdcall* FARPROC)();

typedef int (__stdcall* ROOMCALLBACKFN)(D2ActiveRoomStrc* pRoom, void* pArgs);

typedef void (__fastcall* LEVELNODEFN)(D2CommonLevelNodeStrc* pNode);

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern const LEVELNODEFN gpfnRoomExSetStatus[]; // 0x00744384

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

void __fastcall DUNGEON_FreeRoom(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0061A840

void __fastcall ENVIRONMENT_FreeDrlgEnvironment(void* pMemPool, D2DrlgEnvironmentStrc* pEnvironment); // 0x0061BEC0

void __fastcall DRLG_FreeDrlg(D2DrlgStrc* pDrlg); // 0x00642190

void __stdcall DUNGEON_GameToClientTileDrawPositionCoords(int nX, int nY, int* pX, int* pY); // 0x006433C0

void __stdcall UNITROOM_SortUnitListByTargetY(D2ActiveRoomStrc* pRoom); // 0x0064C0C0

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x0066AB00

void __fastcall DRLGROOM_UnlinkActiveRoom(D2DrlgRoomStrc* pDrlgRoom, int bClient, unsigned int nFlags); // 0x0066B4C0

void __fastcall DRLGROOM_InitNearRooms(void* pContext, D2CommonLevelNodeStrc* pNode); // 0x0066C370

int __fastcall DRLGLOGIC_GetRoomCoordListIndex(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY); // 0x0066CE30

D2UniqueNameTxt* gpUniqueNameTxtTables[4]; // 0x0096D488

int gnUniqueNameTxtRecordCounts[4]; // 0x0096D498

Unicode gwszDataTablesDefault; // 0x0096D4B4

D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct);                       // 0x0061AA60

int gStatsClientAllocatedRooms;                                                                             // 0x0096C8B8

int gStatsClientFreedRooms;                                                                                 // 0x0096C8BC

int gStatsFreedRooms;                                                                                       // 0x0096C8C0

int gStatsAllocatedRooms;                                                                                   // 0x0096C8C4

#define ROOMFLAG_1 0x00000001

#define DRLGROOMFLAG_HAS_ROOM 0x100000

#define DRLGROOMFLAG_HASPORTAL 0x400000

#define DRLGROOMFLAG_TILELIB_LOADED 0x1000000

#define DRLGROOMFLAG_PRESET_UNITS_ADDED 0x2000000

#define DRLGTYPE_PRESET 2

enum D2C_J07DungeonConstants
{
    UNITFLAGINDEX_ISCLIENTUNIT = 22,
    UNITFLAG_J07_PATHUPDATE = 0x800000,
    UNITFLAGEX_J07_REMOVED = 0x20,
};

void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit); // 0x0064C450

void __fastcall COLLISION_FreeRoomCollisionGrid(void* pMemPool, D2ActiveRoomStrc* pRoom); // 0x0064CA10

void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* pRoom); // 0x0061A2C0

extern const int gnTownLevelIdsByAct[5]; // 0x006E7D1C

int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg); // 0x00642230

void __fastcall DRLGROOMTILE_LoadDT1FilesForRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0066F240

void __fastcall DRLGROOM_InitNearRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom); // 0x0066C370

void __fastcall DRLGROOMTILE_InitRoomGrids(D2DrlgRoomStrc* pDrlgRoom); // 0x0066EE40

void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom); // 0x006422A0

D2DrlgStrc* __fastcall DRLGROOM_GetDrlgFromRoomEx(D2DrlgRoomStrc* pRoom); // 0x0066C0B0

int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg); // 0x00642A00

// 0x006194A0
D2DrlgActStrc* __stdcall DUNGEON_AllocAct(unsigned char nAct, unsigned int nInitSeed, int bClient, D2GameStrc* pGame, unsigned char nDifficulty, void* pMemPool, int nTownLevelId, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap)
{
    D2DrlgActStrc* pAct = (D2DrlgActStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgActStrc), ".\\DUNGEON\\Dungeon.cpp", 0x19, 0);
    memset(pAct, 0, sizeof(D2DrlgActStrc));

    pAct->dwInitSeed = nInitSeed;
    pAct->bClient = bClient;
    pAct->nAct = nAct;
    pAct->pMemPool = pMemPool;

    if (bClient)
    {
        pAct->pDrlg = DRLG_AllocDrlg(pAct, nAct, 0, nInitSeed, 0, 1, pGame, nDifficulty, pfAutoMap, pfTownAutoMap);
    }
    else
    {
        pAct->nTownId = nTownLevelId;
        pAct->pDrlg = DRLG_AllocDrlg(pAct, nAct, 0, nInitSeed, nTownLevelId, 0, pGame, nDifficulty, pfAutoMap, pfTownAutoMap);
    }

    pAct->pEnvironment = ENVIRONMENT_AllocDrlgEnvironment(pMemPool);
    DRLGANIM_InitCache(pAct->pDrlg, pAct->pTileData);
    return pAct;
}

// 0x00619550
void* __fastcall DUNGEON_GetMemPoolFromAct(D2DrlgActStrc* pAct)
{
    return pAct->pMemPool;
}

// 0x00619560
void __stdcall DUNGEON_ToggleRoomTilesEnableFlag(D2ActiveRoomStrc* ptRoom, int bEnabled)
{
    D2_ASSERT(ptRoom, 98);

    DRLGWARP_ToggleRoomTilesEnableFlag(ptRoom->pDrlgRoom, bEnabled);
}

// 0x006195A0
D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc* pRoom, int nSourceLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord)
{
    D2_ASSERT(pRoom, 106);
    int nDestinationLevel;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    D2ActiveRoomStrc* pDestRoom = DRLGWARP_GetDestinationRoom(pRoom->pDrlgRoom, nSourceLevel, &nDestinationLevel, &pLvlWarpTxtRecord);
    D2_ASSERT(pDestRoom, 113);
    D2UnitStrc* pTile = pDestRoom->pUnitFirst;
    while (pTile)
    {
        const int nType = pTile ? pTile->dwUnitType : UNIT_INVALID;
        const int nClassId = pTile ? pTile->dwClassId : -1;
        if (nType == 5 && nClassId == nDestinationLevel)
            break;
        pTile = pTile->ptRoomNext;
    }
    *ppLvlWarpTxtRecord = pLvlWarpTxtRecord;
    return pTile;
}

// 0x00619620
D2LvlWarpTxt* __stdcall DUNGEON_GetLvlWarpTxtRecordFromRoomAndUnit(D2ActiveRoomStrc* ptRoom, D2UnitStrc* pUnit)
{
    D2_ASSERT(ptRoom, 138);

    return DRLGWARP_GetLvlWarpTxtRecordFromUnit(ptRoom->pDrlgRoom, pUnit);
}

// 0x00619660
D2DrlgTileDataStrc* __stdcall DUNGEON_GetFloorTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pFloorCount)
{
    if (pRoom && pRoom->pRoomTiles)
    {
        *pFloorCount = pRoom->pRoomTiles->nFloors;
        return pRoom->pRoomTiles->pFloorTiles;
    }

    *pFloorCount = 0;
    return 0;
}

// 0x006196A0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pWallCount)
{
    D2_ASSERT(pRoom, 177);

    *pWallCount = pRoom->pRoomTiles->nWalls;
    return pRoom->pRoomTiles->pWallTiles;
}

// 0x006196E0
D2DrlgTileDataStrc* __stdcall DUNGEON_GetRoofTilesFromRoom(D2ActiveRoomStrc* pRoom, int* pRoofCount)
{
    D2_ASSERT(pRoom, 190);

    *pRoofCount = pRoom->pRoomTiles->nRoofs;
    return pRoom->pRoomTiles->pRoofTiles;
}

// 0x00619720
extern "C" __declspec(dllexport) unsigned int* __stdcall DUNGEON_GetTileDataFromAct(Obj00619720* pObj) {
    return &pObj->dwMember18;
}

// 0x00619730
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords)
{
    D2_ASSERT(pCoords, 209);

    if (!pRoom)
    {
        memset(pCoords, 0x00, sizeof(D2DrlgCoordsStrc));
        return;
    }

    memcpy(pCoords, &pRoom->tCoords, sizeof(D2DrlgCoordsStrc));
}

// 0x00619790
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* ptRoom, D2ActiveRoomStrc*** pppRoomList, int* pNumRooms)
{
    D2_ASSERT(ptRoom, 236);

    *pNumRooms = ptRoom->nNumRooms;
    *pppRoomList = ptRoom->ppRoomList;
}

// 0x006197D0
void* __fastcall DUNGEON_AllocZeroedBlock(void* pMemPool)
{
    void* pBlock = FOG_AllocPool(pMemPool, 0x80, ".\\DUNGEON\\Dungeon.cpp", 0xF5, 0);
    memset(pBlock, 0, 0x80);
    return pBlock;
}

// 0x00619800
static void __stdcall DUNGEON_InitAdjacentRoomList(void* pMemory, D2ActiveRoomStrc* pRoom)
{
    const int nNear = DRLGROOM_GetNumberOfNearRooms(pRoom->pDrlgRoom);
    pRoom->ppRoomList = (D2ActiveRoomStrc**)FOG_AllocPool(pMemory, sizeof(D2ActiveRoomStrc*) * nNear, ".\\DUNGEON\\Dungeon.cpp", 256, 0);
    pRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pRoom->pDrlgRoom, pRoom->ppRoomList);
    for (unsigned int i = 0; i < pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pAdjacentRoom = pRoom->ppRoomList[i];
        D2_ASSERT(pAdjacentRoom, 264);
        if (pAdjacentRoom != pRoom)
            pAdjacentRoom->nNumRooms = DRLGROOM_ReorderNearRoomList(pAdjacentRoom->pDrlgRoom, pAdjacentRoom->ppRoomList);
    }
}

D2ActiveRoomStrc* __fastcall sub_Z16_EmitUpdateRoomsNear(sub_Z16_EmitRoomHolder* pOther, D2ActiveRoomStrc* pRoom)
{
    DUNGEON_InitAdjacentRoomList(pOther->pMemory, pRoom);
    return pRoom;
}

int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel); // 0x0066BAC0

// 0x00619B10
D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomByTileCoordinates(D2DrlgActStrc* pAct, int nX, int nY)
{
    for (D2ActiveRoomStrc* pRoom = pAct->pRoom; pRoom; pRoom = pRoom->pRoomNext)
    {
        if (nX >= pRoom->tCoords.nTileXPos && nX < pRoom->tCoords.nTileXPos + pRoom->tCoords.nTileWidth && nY >= pRoom->tCoords.nTileYPos
            && nY < pRoom->tCoords.nTileYPos + pRoom->tCoords.nTileHeight)
            return pRoom;
    }
    return 0;
}

// 0x00619D00
void __stdcall DUNGEON_GetSubtileRect(D2ActiveRoomStrc* pRoom, tagRECT* pRect)
{
    D2_ASSERT(pRoom, 0x1E3);
    pRect->top = pRoom->tCoords.nSubtileY;
    pRect->bottom = pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight;
    pRect->left = pRoom->tCoords.nSubtileX;
    pRect->right = pRoom->tCoords.nSubtileWidth + pRoom->tCoords.nSubtileX;
    D2_ASSERT(pRect->top <= pRect->bottom, 0x1EB);
    D2_ASSERT(pRect->left <= pRect->right, 0x1EC);
}

// 0x00619F20
void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        D2_ASSERT(pRoom->nAllies > 0, 0x27C);
        --pRoom->nAllies;
    }
}

// 0x0061A1D0
int __stdcall DUNGEON_GetWarpDestinationLevel(D2ActiveRoomStrc* pRoom, int nSourceLevel)
{
    if (!pRoom)
        return 0;
    return DRLGROOM_GetWarpDestinationLevel(pRoom->pDrlgRoom, nSourceLevel);
}

// 0x0061AFD0
void __stdcall DUNGEON_FreeAct(D2DrlgActStrc* ptAct)
{
    D2_ASSERT(ptAct, 58);
    if (ptAct->pDrlg)
    {
        DRLG_FreeDrlg(ptAct->pDrlg);
        ptAct->pDrlg = 0;
    }
    D2ActiveRoomStrc* pRoom = ptAct->pRoom;
    while (pRoom)
    {
        D2ActiveRoomStrc* pNext = pRoom->pRoomNext;
        DUNGEON_FreeRoom(ptAct->pMemPool, pRoom);
        pRoom = pNext;
    }
    if (ptAct->pEnvironment)
    {
        ENVIRONMENT_FreeDrlgEnvironment(ptAct->pMemPool, ptAct->pEnvironment);
        ptAct->pEnvironment = 0;
    }
    FOG_FreePool(ptAct->pMemPool, ptAct, ".\\DUNGEON\\Dungeon.cpp", 82, 0);
}

// 0x00619890
D2ActiveRoomStrc* __fastcall DUNGEON_AllocRoom(D2DrlgActStrc* ptAct, D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordsStrc* pDrlgCoords, D2DrlgRoomTilesStrc* pRoomTiles, int nLowSeed, unsigned int dwFlags)
{
    D2_ASSERT(ptAct, 281);

    D2ActiveRoomStrc* pRoom = (D2ActiveRoomStrc*)FOG_AllocPool(ptAct->pMemPool, sizeof(D2ActiveRoomStrc), ".\\DUNGEON\\Dungeon.cpp", 245, 0);
    memset(pRoom, 0, sizeof(D2ActiveRoomStrc));

    pRoom->dwFlags = dwFlags;
    SEED_InitLowSeed(&pRoom->pSeed, nLowSeed);

    pRoom->pDrlgRoom = pDrlgRoom;
    pRoom->tCoords = *pDrlgCoords;
    pRoom->pRoomTiles = pRoomTiles;
    pRoom->pRoomNext = ptAct->pRoom;
    ptAct->pRoom = pRoom;
    ptAct->bHasPendingRoomsUpdates = 1;
    pRoom->pAct = ptAct;

    DRLGROOM_SetRoom(pDrlgRoom, pRoom);
    DUNGEON_InitAdjacentRoomList(ptAct->pMemPool, pRoom);
    COLLISION_AllocRoomCollisionGrid(ptAct->pMemPool, pRoom);

    if (ptAct->pfnActCallBack)
    {
        ptAct->pfnActCallBack(pRoom);
    }

    return pRoom;
}

// 0x00619970
int __stdcall DUNGEON_DoRoomsTouchOrOverlap(D2ActiveRoomStrc* ptFirst, D2ActiveRoomStrc* ptSecond)
{
    D2_ASSERT(ptFirst, 318);
    D2_ASSERT(ptSecond, 321);
    if (ptFirst->tCoords.nTileXPos > ptSecond->tCoords.nTileXPos + ptSecond->tCoords.nTileWidth)
        return 0;
    if (ptFirst->tCoords.nTileXPos + ptFirst->tCoords.nTileWidth < ptSecond->tCoords.nTileXPos)
        return 0;
    if (ptFirst->tCoords.nTileYPos > ptSecond->tCoords.nTileYPos + ptSecond->tCoords.nTileHeight)
        return 0;
    return ptFirst->tCoords.nTileYPos + ptFirst->tCoords.nTileHeight >= ptSecond->tCoords.nTileYPos;
}

// 0x006199F0
int __stdcall DUNGEON_AreTileCoordinatesInsideRoom(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(pRoom, 360);
    if (nX >= pRoom->tCoords.nTileXPos && nX < pRoom->tCoords.nTileXPos + pRoom->tCoords.nTileWidth
        && nY >= pRoom->tCoords.nTileYPos && nY < pRoom->tCoords.nTileYPos + pRoom->tCoords.nTileHeight)
        return 1;
    return 0;
}

// 0x00619A50
int __stdcall DUNGEON_CheckRoomsOverlapping_BROKEN(D2ActiveRoomStrc* pPrimary, D2ActiveRoomStrc* pSecondary)
{
    D2_ASSERT(pPrimary, 379);

    const D2DrlgCoordsStrc* pFirst = (D2DrlgCoordsStrc*)&pPrimary->tCoords.nTileXPos;
    const D2DrlgCoordsStrc* pSecond = (D2DrlgCoordsStrc*)&pPrimary->tCoords.nTileXPos;
    const int nX2 = pSecond->nSubtileX;
    const int nX1 = pFirst->nSubtileX;
    if (nX1 > nX2 + pSecond->nSubtileWidth)
        return 0;
    if (nX1 + pFirst->nSubtileWidth < nX2)
        return 0;
    const int nY2 = pSecond->nSubtileY;
    if (pFirst->nSubtileY > nY2 + pSecond->nSubtileHeight)
        return 0;
    if (pFirst->nSubtileY + pFirst->nSubtileHeight < nY2)
        return 0;
    if (nX1 == nX2 + pSecond->nSubtileWidth)
        return 1;
    if (nX1 + pFirst->nSubtileWidth == nX2)
        return 2;
    if (pFirst->nSubtileY == nY2 + pSecond->nSubtileHeight)
        return 3;
    return 4;
}

// 0x00619B60
D2ActiveRoomStrc* __stdcall DUNGEON_GetAdjacentRoomByTileCoordinates(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(pRoom, 431);
    for (unsigned int i = 0; i < (unsigned int)pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pTemp = pRoom->ppRoomList[i];
        D2_ASSERT(pTemp, 435);
        if (DUNGEON_AreTileCoordinatesInsideRoom(pTemp, nX, nY))
            return pTemp;
    }
    return 0;
}

// 0x00619BD0
void __stdcall DUNGEON_CallRoomCallback(D2ActiveRoomStrc* ptRoom, ROOMCALLBACKFN pfnRoomCallback, void* pArgs)
{
    D2_ASSERT(ptRoom, 448);
    D2_ASSERT(!IsBadCodePtr((FARPROC)pfnRoomCallback), 450);
    for (unsigned int i = 0; i < (unsigned int)ptRoom->nNumRooms; ++i)
    {
        if (!pfnRoomCallback(ptRoom->ppRoomList[i], pArgs))
            break;
    }
}

// 0x00619C40
void __stdcall D2Common_10052(D2ActiveRoomStrc* pRoom, RECT* pRect)
{
    int nTemp;
    D2_ASSERT(pRoom, 464);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->tCoords.nTileXPos, pRoom->tCoords.nTileYPos, &nTemp, (int*)&pRect->top);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->tCoords.nTileXPos, pRoom->tCoords.nTileHeight + pRoom->tCoords.nTileYPos, (int*)&pRect->left, &nTemp);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->tCoords.nTileXPos + pRoom->tCoords.nTileWidth, pRoom->tCoords.nTileYPos, (int*)&pRect->right, &nTemp);
    DUNGEON_GameToClientTileDrawPositionCoords(pRoom->tCoords.nTileXPos + pRoom->tCoords.nTileWidth, pRoom->tCoords.nTileHeight + pRoom->tCoords.nTileYPos, &nTemp, (int*)&pRect->bottom);
    D2_ASSERT(pRect->top <= pRect->bottom, 474);
    D2_ASSERT(pRect->left <= pRect->right, 475);
}

// 0x00619D70
void __stdcall DUNGEON_GetRGB_IntensityFromRoom(D2ActiveRoomStrc* pRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    DRLGROOM_GetRGB_IntensityFromRoomEx(pRoom->pDrlgRoom, pIntensity, pRed, pGreen, pBlue);
}

// 0x00619DA0
D2ActRoom00619DA0Strc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2Act00619DA0Strc* pAct, int nX, int nY)
{
    if (!pAct)
    {
        return 0;
    }
    for (D2ActRoom00619DA0Strc* pRoom = pAct->pFirstRoom10; pRoom; pRoom = pRoom->pNext7C)
    {
        if (pRoom && nX >= pRoom->nX4C && nX < pRoom->nX4C + pRoom->nWidth54 && nY >= pRoom->nY50 && nY < pRoom->nY50 + pRoom->nHeight58)
        {
            return pRoom;
        }
    }
    return 0;
}

// 0x00619DF0
int __fastcall DUNGEON_AreSubtileCoordinatesInsideRoom(D2DrlgCoordsStrc* ptCoords, int nX, int nY)
{
    D2_ASSERT(ptCoords, 530);
    if (nX >= ptCoords->nSubtileX && nX < ptCoords->nSubtileX + ptCoords->nSubtileWidth
        && nY >= ptCoords->nSubtileY && nY < ptCoords->nSubtileY + ptCoords->nSubtileHeight)
        return 1;
    return 0;
}

// 0x00619E50
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocation(D2DrlgActStrc* ptAct, int nLevelId, int nTileIndex, int* pX, int* pY)
{
    D2_ASSERT(ptAct, 545);

    return DRLGWARP_GetLevelEntryRoom(ptAct->pDrlg, nLevelId, nTileIndex, pX, pY);
}

// 0x0061B060
D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* ptAct, int nLevelId, int nTileIndex, int* pX, int* pY, int nUnitSize)
{
    D2CoordStrc tCoord;
    D2_ASSERT(ptAct, 556);
    int nX = 0;
    int nY = 0;
    D2ActiveRoomStrc* pRoom = DRLGWARP_GetLevelEntryRoom(ptAct->pDrlg, nLevelId, nTileIndex, &nX, &nY);
    if (pRoom)
    {
        DUNGEON_GameTileToSubtileCoords(&nX, &nY);
        tCoord.nX = nX + 3;
        tCoord.nY = nY + 3;
        D2_ASSERT(COLLISION_GetFreeCoordinates(pRoom, &tCoord, nUnitSize, 0x1C09, 0), 568);
        *pX = tCoord.nX;
        *pY = tCoord.nY;
        return sub_00463740_FindRoomAtPoint(pRoom, *pX, *pY);
    }
    return 0;
}

// 0x0061B130
int __stdcall D2Common_10095(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2ActiveRoomStrc* pFoundRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pFoundRoom)
        return 0;
    return DRLGLOGIC_GetRoomCoordListIndex(pFoundRoom->pDrlgRoom, nX, nY);
}

// 0x00619EA0
D2UnitStrc* __stdcall DUNGEON_GetFirstUnitInRoom(D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptRoom, 585);
    UNITROOM_SortUnitListByTargetY(ptRoom);
    return ptRoom->pUnitFirst;
}

// 0x00619EE0
extern "C" __declspec(dllexport) void __stdcall DUNGEON_IncreaseAlliedCountOfRoom(Obj00619EE0* pObj) {
    if (pObj) {
        pObj->nCount28++;
    }
}

// 0x00619F00
int __stdcall DUNGEON_GetAlliedCountFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return pRoom->nAllies;
}

// 0x00619F60
D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 646);

    return &pRoom->pUnitFirst;
}

// 0x00619F90
D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate)
{
    D2_ASSERT(pRoom, 685);

    if (bUpdate)
    {
        pRoom->pAct->bHasPendingUnitListUpdates = 1;
    }

    return &pRoom->pUnitUpdate;
}

// 0x00619FD0
D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptRoom, 699);

    return DRLGROOM_GetPresetUnits(ptRoom->pDrlgRoom);
}

// 0x0061A010
void* __fastcall DUNGEON_GetCollisionGridFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 709);

    return pRoom->pCollisionGrid;
}

// 0x0061A040
void __fastcall DUNGEON_SetCollisionGridInRoom(D2ActiveRoomStrc* pRoom, void* pCollisionGrid)
{
    D2_ASSERT(pRoom, 718);

    pRoom->pCollisionGrid = pCollisionGrid;
}

// 0x0061A070
void __stdcall DUNGEON_SetClientIsInSight(D2DrlgActStrc* ptAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(ptAct, 727);

    DRLGACTIVATE_SetClientIsInSight(ptAct->pDrlg, nLevelId, nX, nY, pRoom ? pRoom->pDrlgRoom : 0);
}

// 0x0061A0C0
void __stdcall DUNGEON_UnsetClientIsInSight(D2DrlgActStrc* ptAct, int nLevelId, int nX, int nY, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(ptAct, 745);

    DRLGACTIVATE_UnsetClientIsInSight(ptAct->pDrlg, nLevelId, nX, nY, pRoom ? pRoom->pDrlgRoom : 0);
}

// 0x0061A110
void __stdcall DUNGEON_ChangeClientRoom(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = 0;
    D2DrlgRoomStrc* pDrlgRoom2 = 0;

    if (pRoom1)
    {
        pDrlgRoom1 = pRoom1->pDrlgRoom;
    }

    if (pRoom2)
    {
        pDrlgRoom2 = pRoom2->pDrlgRoom;
    }

    DRLGACTIVATE_ChangeClientRoom(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061A140
D2ActiveRoomStrc* __stdcall DUNGEON_StreamRoomAtCoords(D2DrlgActStrc* ptAct, int nX, int nY)
{
    D2_ASSERT(ptAct, 787);

    return DRLGACTIVATE_StreamRoomAtCoords(ptAct->pDrlg, nX, nY);
}

// 0x0061A180
D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 798);

    return pAct->pRoom;
}

// 0x0061A1B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetLevelId(pRoom->pDrlgRoom);
}

// 0x0061A1F0
int __stdcall DUNGEON_GetLevelIdFromPopulatedRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetLevelIdFromPopulatedRoom(pRoom->pDrlgRoom);
}

// 0x0061A210
int __stdcall DUNGEON_HasWaypoint(D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptRoom, 867);

    return DRLGROOM_HasWaypoint(ptRoom->pDrlgRoom);
}

// 0x0061A250
const char* __stdcall DUNGEON_GetPickedLevelPrestFilePathFromRoom(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(pRoom->pDrlgRoom);
}

// 0x0061A270
void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID)
{
    if (pRoom)
    {
        D2DrlgDeleteStrc* pDrlgDelete = (D2DrlgDeleteStrc*)FOG_AllocPool(pRoom->pAct->pMemPool, sizeof(D2DrlgDeleteStrc),
            ".\\DUNGEON\\Dungeon.cpp", 0x384, 0);
        pDrlgDelete->nUnitType = nUnitType;
        pDrlgDelete->nUnitGUID = nUnitGUID;
        pDrlgDelete->pNext = pRoom->pDrlgDelete;
        pRoom->pDrlgDelete = pDrlgDelete;
        pRoom->pAct->bHasPendingRoomDeletions = 1;
    }
}

// 0x0061A330
D2DrlgDeleteStrc* __stdcall DUNGEON_GetDrlgDeleteFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 934);

    return pRoom->pDrlgDelete;
}

// 0x0061A360
D2ActiveRoomStrc* __stdcall DUNGEON_GetARoomInClientSight(D2DrlgActStrc* ptAct)
{
    D2_ASSERT(ptAct, 965);

    return DRLGACTIVATE_GetARoomInClientSight(ptAct->pDrlg);
}

// 0x0061A3A0
D2ActiveRoomStrc* __stdcall DUNGEON_GetARoomInSightButWithoutClient(D2DrlgActStrc* ptAct, D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptAct, 974);

    D2_ASSERT(ptRoom, 977);

    return DRLGACTIVATE_GetARoomInSightButWithoutClient(ptAct->pDrlg, ptRoom->pDrlgRoom);
}

// 0x0061A3F0
int __stdcall DUNGEON_TestRoomCanUnTile(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pAct, 989);
    D2_ASSERT(!pAct->bClient, 990);
    D2_ASSERT(pRoom, 991);

    return DRLGACTIVATE_TestRoomCanUnTile(pRoom->pDrlgRoom);
}

// 0x0061A440
int __stdcall DUNGEON_GetRoomStatusFlags(D2ActiveRoomStrc* pRoom)
{
    return DRLGACTIVATE_GetRoomStatusFlags(pRoom->pDrlgRoom) >= 3;
}

// 0x0061A460
int __stdcall D2Common_10073(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1007);

    if (pRoom->nNumRooms == DRLGROOM_GetNumberOfNearRooms(pRoom->pDrlgRoom))
    {
        for (unsigned int i = 0; i < pRoom->nNumRooms; ++i)
        {
            if (!(pRoom->ppRoomList[i]->dwFlags & ROOMFLAG_1))
            {
                return 0;
            }
        }

        return 1;
    }

    return 0;
}

// 0x0061A4D0
int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1071);

    return pRoom->dwFlags & ROOMFLAG_2;
}

// 0x0061A510
void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet)
{
    D2_ASSERT(pRoom, 1080);

    if (bSet)
    {
        pRoom->dwFlags |= ROOMFLAG_2;
    }
    else
    {
        pRoom->dwFlags &= ~ROOMFLAG_2;
    }
}

// 0x0061A550
static int DUNGEON_ValidateRoomClients(D2ActiveRoomStrc* pRoom)
{
    for (unsigned int i = 0; i < pRoom->nNumClients; ++i)
    {
        D2_ASSERT(pRoom->ppClients[i], 0x453);
    }
    return 1;
}

// 0x0061A5A0
static void DUNGEON_UpdateClientListOfRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(DUNGEON_ValidateRoomClients(pRoom), 0x45B);

    for (int nClients = pRoom->nNumClients - 1; nClients > 0; --nClients)
    {
        int bContinue = 0;
        for (int i = 0; i < nClients; ++i)
        {
            if (pRoom->ppClients[i] > pRoom->ppClients[i + 1])
            {
                D2ClientStrc* pTemp = pRoom->ppClients[i];
                pRoom->ppClients[i] = pRoom->ppClients[i + 1];
                pRoom->ppClients[i + 1] = pTemp;
                bContinue = 1;
            }
        }
        if (!bContinue)
            return;
    }

    DUNGEON_ValidateRoomClients(pRoom);
}

// 0x0061A660
void __stdcall DUNGEON_AddClientToRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x473);
    D2_ASSERT(pClient, 0x474);
    D2_ASSERT(DUNGEON_ValidateRoomClients(pRoom), 0x475);
    D2_ASSERT(pRoom->nNumClients <= pRoom->nMaxClients, 0x477);

    if (pRoom->nNumClients == pRoom->nMaxClients)
    {
        pRoom->nMaxClients += 4;
        pRoom->ppClients = (D2ClientStrc**)FOG_ReallocPool(pRoom->pAct->pMemPool, pRoom->ppClients, sizeof(D2ClientStrc*) * pRoom->nMaxClients, ".\\DUNGEON\\Dungeon.cpp", 0x47B, 0);
    }

    pRoom->ppClients[pRoom->nNumClients] = pClient;
    ++pRoom->nNumClients;
    DUNGEON_UpdateClientListOfRoom(pRoom);
}

static inline void DUNGEON_GetClientUnitFlag(D2UnitStrc* pUnit, unsigned int dwFlags, int* pResult)
{
    *pResult = pUnit ? (dwFlags >> UNITFLAGINDEX_ISCLIENTUNIT) & 1 : 0;
}

// 0x0061A840
void __fastcall DUNGEON_FreeRoom(void* pMemPool, D2ActiveRoomStrc* pRoom)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pRoom->pUnitFirst)
    {
        const unsigned int dwFlags = pUnit->dwFlags;
        int bClient;
        DUNGEON_GetClientUnitFlag(pUnit, dwFlags, &bClient);
        if (!bClient)
        {
            pUnit->dwFlagEx |= UNITFLAGEX_J07_REMOVED;
        }

        pUnit->dwFlags = dwFlags | UNITFLAG_J07_PATHUPDATE;
        UNITROOM_UpdatePath(pUnit);
    }

    COLLISION_FreeRoomCollisionGrid(pMemPool, pRoom);
    DUNGEON_FreeDrlgDelete(pRoom);

    if (pRoom->ppClients)
    {
        FOG_FreeServerMemory(pRoom->pAct->pMemPool, pRoom->ppClients, ".\\DUNGEON\\Dungeon.cpp", 0x4E2, 0);
    }

    FOG_FreeServerMemory(pMemPool, pRoom->ppRoomList, ".\\DUNGEON\\Dungeon.cpp", 0x4E4, 0);
    FOG_FreeServerMemory(pMemPool, pRoom, ".\\DUNGEON\\Dungeon.cpp", 0x4E5, 0);
}

// 0x0061A2C0
void __stdcall DUNGEON_FreeDrlgDelete(D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptRoom, 912);

    D2DrlgDeleteStrc* pDrlgDelete = ptRoom->pDrlgDelete;
    void* pMemPool = ptRoom->pAct->pMemPool;
    if (pDrlgDelete)
    {
        do
        {
            D2DrlgDeleteStrc* pFree = pDrlgDelete;
            pDrlgDelete = pDrlgDelete->pNext;
            FOG_FreePool(pMemPool, pFree, ".\\DUNGEON\\Dungeon.cpp", 924, 0);
        }
        while (pDrlgDelete);
        ptRoom->pDrlgDelete = 0;
    }
}

// 0x0061A700
void __stdcall DUNGEON_RemoveClientFromRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x487);
    D2_ASSERT(pClient, 0x488);
    D2_ASSERT(DUNGEON_ValidateRoomClients(pRoom), 0x489);

    unsigned int i = 0;
    for (i = 0; i < pRoom->nNumClients; ++i)
    {
        if (pRoom->ppClients[i] == pClient)
            break;
    }
    D2_ASSERT(i < pRoom->nNumClients, 0x490);

    pRoom->ppClients[i] = pRoom->ppClients[pRoom->nNumClients - 1];
    --pRoom->nNumClients;
    DUNGEON_UpdateClientListOfRoom(pRoom);
}

// 0x0061A790
int __stdcall D2Common_10081_GetTileCountFromRoom(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1198);

    if (pRoom->nNumClients)
    {
        pRoom->nTileCount = 0;
    }
    else
    {
        ++pRoom->nTileCount;
    }

    return pRoom->nTileCount;
}

// 0x0061A7E0
int __fastcall DUNGEON_HasClientNotInRoom(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    for (int i = 0; i < (int)pRoom2->nNumClients; ++i)
    {
        int j = 0;
        while (j < (int)pRoom1->nNumClients && pRoom1->ppClients[j] != pRoom2->ppClients[i])
            ++j;
        if (j >= (int)pRoom1->nNumClients)
            return 1;
    }
    return 0;
}

// 0x0061A8E0
void __fastcall DUNGEON_ClearRoomTiles(D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 0x4EC);
    pRoom->pRoomTiles = 0;
}

// 0x0061A910
void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(pRoom, 1271);
    D2ActiveRoomStrc* pPreviousRoom = 0;
    D2ActiveRoomStrc* pCurrentRoom;
    for (pCurrentRoom = pAct->pRoom; pCurrentRoom; pCurrentRoom = pCurrentRoom->pRoomNext)
    {
        if (pCurrentRoom == pRoom)
            break;
        pPreviousRoom = pCurrentRoom;
    }
    D2_ASSERT(pCurrentRoom, 1282);
    if (pPreviousRoom)
        pPreviousRoom->pRoomNext = pCurrentRoom->pRoomNext;
    else
        pAct->pRoom = pCurrentRoom->pRoomNext;
    for (int i = 0; i < pRoom->nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pNearRoom = pRoom->ppRoomList[i];
        if (pNearRoom != pRoom)
        {
            for (int nCounter = 0; nCounter < pNearRoom->nNumRooms; ++nCounter)
            {
                if (pNearRoom->ppRoomList[nCounter] == pRoom)
                {
                    pNearRoom->ppRoomList[nCounter] = pNearRoom->ppRoomList[pNearRoom->nNumRooms - 1];
                    --pNearRoom->nNumRooms;
                    break;
                }
            }
        }
    }
    DRLGROOM_UnlinkActiveRoom(pRoom->pDrlgRoom, pAct->bClient, pRoom->dwFlags);
    DUNGEON_FreeRoom(pAct->pMemPool, pRoom);
}

// 0x0061A9F0
void __stdcall D2Common_10077(D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = pRoom1 ? pRoom1->pDrlgRoom : 0;
    D2DrlgRoomStrc* pDrlgRoom2 = pRoom2 ? pRoom2->pDrlgRoom : 0;
    DRLG_UpdateLevelActivityOnRoomChange(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061AA20
void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct)
{
    DRLG_UpdateAndFreeInactiveRooms(pAct->pDrlg);
}

// 0x0061AA40
int __stdcall DUNGEON_CheckLOSDraw(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLGROOM_CheckLOSDraw(pRoom->pDrlgRoom);
}

// 0x0061AA60
D2DrlgEnvironmentStrc* __fastcall DUNGEON_GetEnvironmentFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1351);

    return pAct->pEnvironment;
}

// 0x0061AA90
D2DrlgStrc* __stdcall DUNGEON_GetDrlgFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1360);

    return pAct->pDrlg;
}

// 0x0061AAC0
int __stdcall DUNGEON_GetInitSeedFromAct(D2DrlgActStrc* pAct)
{
    if (!pAct)
    {
        return 0;
    }
    return pAct->dwInitSeed;
}

// 0x0061AAE0
D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom)
{
    return pRoom->pDrlgRoom;
}

// 0x0061AAF0
int __stdcall DUNGEON_IsTownLevelId(int nLevelId)
{
    return DRLG_IsTownLevel(nLevelId);
}

// 0x0061AB00
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom)
{
    if (!pRoom)
    {
        return 0;
    }

    return DRLG_IsTownLevel(DRLGROOM_GetLevelId(pRoom->pDrlgRoom));
}

// 0x0061AB30
int __stdcall DUNGEON_GetActNoFromRoom(D2ActiveRoomStrc* pRoom)
{
    return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
}

// 0x0061AB60
int __stdcall D2Common_10084(D2ActiveRoomStrc* pRoom)
{
    return pRoom->dwFlags & ROOMFLAG_4;
}

// 0x0061AB70
int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct)
{
    D2_ASSERT(nAct < 5, 0x59A);
    return gnTownLevelIdsByAct[nAct];
}

// 0x0061ABB0
int __stdcall D2Common_10087(D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptRoom, 1445);

    return DRLGROOM_CheckMazeRoomOutdoorFlag(ptRoom->pDrlgRoom);
}

// 0x0061ABF0
int __stdcall DUNGEON_GetNumberOfPopulatedRoomsInLevel(D2DrlgActStrc* pAct, int nLevelId)
{
    return DRLG_GetNumberOfPopulatedRoomsInLevel(pAct->pDrlg, nLevelId);
}

// 0x0061AC10
int* __stdcall DUNGEON_GetWarpCoordinatesFromRoom(D2ActiveRoomStrc* ptRoom)
{
    D2_ASSERT(ptRoom, 1465);

    return DRLG_GetRoomCenterX_RoomWarpXFromRoom(ptRoom->pDrlgRoom);
}

// 0x0061AC50
void __stdcall DUNGEON_UpdateWarpRoomSelect(D2ActiveRoomStrc* ptRoom, int nLevelId)
{
    D2_ASSERT(ptRoom, 1476);

    DRLGWARP_UpdateWarpRoomSelect(ptRoom->pDrlgRoom, nLevelId);
}

// 0x0061AC90
void __stdcall DUNGEON_UpdateWarpRoomDeselect(D2ActiveRoomStrc* ptRoom, int nLevelId)
{
    D2_ASSERT(ptRoom, 1487);

    DRLGWARP_UpdateWarpRoomDeselect(ptRoom->pDrlgRoom, nLevelId);
}

// 0x0061ACD0
void __stdcall DUNGEON_UpdatePops(D2ActiveRoomStrc* ptRoom, int nX, int nY, int bOtherRoom)
{
    D2_ASSERT(ptRoom, 1498);

    DRLGPRESET_UpdatePops(ptRoom->pDrlgRoom, nX, nY, bOtherRoom);
}

// 0x0061AD10
void __stdcall DUNGEON_GetTombStoneTileCoords(Room* room,Coord** tiles,int* count)
{
    DRLGPRESET_GetTombStoneTileCoords(room->roomEx[ROOM_SLOT],tiles,count);
}

// 0x0061AD30
D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    return DRLGLOGIC_GetRoomCoordListAtSubtile(pRoom->pDrlgRoom, nX, nY);
}

// 0x0061AD50
D2RoomCoordListStrc* __stdcall DUNGEON_GetRoomCoordList(D2ActiveRoomStrc* pRoom)
{
    return DRLGLOGIC_GetRoomCoordList(pRoom->pDrlgRoom);
}

// 0x0061AD70
void __stdcall DUNGEON_GetPortalLevelArrayFromPortalFlags(void* pMemPool, int nFlags, int** ppLevels, int* pnLevels)
{
    int pLevels[32];
    int nPortalLevels;
    int nCurrentFlag = 1;
    int nCount = 0;
    int* pPortalLevels = DATATBLS_GetPortalLevels(&nPortalLevels);
    D2_ASSERT(nPortalLevels <= 32, 1546);
    for (int i = 0; i < nPortalLevels; ++i)
    {
        if (nFlags & nCurrentFlag)
        {
            pLevels[nCount] = pPortalLevels[i];
            ++nCount;
        }
        nCurrentFlag <<= 1;
    }
    if (nCount)
    {
        *ppLevels = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nCount, ".\\DUNGEON\\Dungeon.cpp", 1556, 0);
        memcpy(*ppLevels, pLevels, sizeof(int) * nCount);
    }
    else
    {
        *ppLevels = 0;
    }
    *pnLevels = nCount;
}

// 0x0061AE30
int __stdcall DUNGEON_GetPortalFlagFromLevelId(int nPortalLevelId)
{
    int nPortalLevels;
    int* pPortalLevels = DATATBLS_GetPortalLevels(&nPortalLevels);

    for (int i = 0; i < nPortalLevels; ++i)
    {
        if (nPortalLevelId == *pPortalLevels)
        {
            return 1 << i;
        }
        ++pPortalLevels;
    }

    return 0;
}

// 0x0061AE80
int __stdcall DUNGEON_GetTownLevelIdFromAct(D2DrlgActStrc* pAct)
{
    D2_ASSERT(pAct, 1588);

    return pAct->nTownId;
}

// 0x0061AEB0
int __stdcall DUNGEON_GetHoradricStaffTombLevelId(D2DrlgActStrc* pAct)
{
    if (pAct)
        return DRLG_GetHoradricStaffTombLevelId(pAct->pDrlg);
    return 0;
}

// 0x0061AED0
void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bReset)
{
    if (pRoom)
    {
        DRLGACTIVATE_ToggleHasPortalFlag(pRoom->pDrlgRoom, bReset);
    }
}

// 0x0061AEF0
void __stdcall DUNGEON_AnimateTiles(D2ActiveRoomStrc* pRoom)
{
    if (pRoom)
    {
        DRLGANIM_AnimateTiles(pRoom->pDrlgRoom);
    }
}

// 0x0061AF10
void __stdcall DUNGEON_InitRoomTileAnimation(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom1, D2ActiveRoomStrc* pRoom2)
{
    D2DrlgRoomStrc* pDrlgRoom1 = 0;
    D2DrlgRoomStrc* pDrlgRoom2 = 0;

    if (pRoom1)
    {
        for (D2ActiveRoomStrc* pRoom = pAct->pRoom; pRoom; pRoom = pRoom->pRoomNext)
        {
            if (pRoom == pRoom1)
            {
                pDrlgRoom1 = pRoom1->pDrlgRoom;
                break;
            }
        }
    }

    if (pRoom2)
    {
        pDrlgRoom2 = pRoom2->pDrlgRoom;
    }

    DRLGANIM_UpdateFrameInAdjacentRooms(pDrlgRoom1, pDrlgRoom2);
}

// 0x0061AF60
void __stdcall DUNGEON_SetActCallbackFunc(D2DrlgActStrc* pAct, ACTCALLBACKFN pActCallbackFunction)
{
    D2_ASSERT(pAct, 1663);

    pAct->pfnActCallBack = pActCallbackFunction;
}

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

// 0x00653ED0
const Unicode* __fastcall DATATBLS_RollRandomUniquePrefixString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniquePrefixTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniquePrefixTxtRecordCount);
        if (gpUniquePrefixTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniquePrefixTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653F10
const Unicode* __fastcall DATATBLS_RollRandomUniqueSuffixString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueSuffixTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueSuffixTxtRecordCount);
        if (gpUniqueSuffixTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueSuffixTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x00653F50
const Unicode* __fastcall DATATBLS_RollRandomUniqueAppellationString(D2UnitStrc* pUnit)
{
    if (pUnit && gnUniqueAppellationTxtRecordCount > 0)
    {
        const int nRand = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, gnUniqueAppellationTxtRecordCount);
        if (gpUniqueAppellationTxt[nRand].wStringId)
        {
            const Unicode* pString = D2LANG_GetStringFromTblIndex(gpUniqueAppellationTxt[nRand].wStringId);
            if (pString)
            {
                return pString;
            }
        }
    }
    return &gwszDataTablesDefault;
}

// 0x0061AFA0
extern "C" __declspec(dllexport) void __stdcall DUNGEON_SaveKilledUnitGUID(Obj0061AFA0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwRing38[pObj->bIndex14] = dwValue;
        pObj->bIndex14 = (pObj->bIndex14 + 1) & 3;
    }
}

void __fastcall DRLGACTIVATE_GetRoomsAllocationStats(int* pOutStatsClientAllocatedRooms, int* pOutStatsClientFreedRooms, int* pOutStatsAllocatedRooms, int* pOutStatsFreedRooms); // 0x0061B8F0

#include "gen/data/Source/D2Common/DUNGEON/Dungeon.inc"
