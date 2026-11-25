#include "D2LevelIds.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2CmpTileRecord.h"
#include "D2GameTypes.h"
#include "D2CmpTypes.h"
#include "D2LRUNode.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgTiles.h"
#include "D2TxtItems.h"
#include "D2DrlgMaps.h"
#include "D2DrlgRooms.h"
#include "D2ItemModes.h"
#include "D2DrlgWarp.h"

unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed);

struct D2ObjGroupTxt
{
    char unk0x00[0x34];
};

struct D2LvlTypesTxt
{
    char szFile[32][60];
    unsigned char nAct;
};

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern D2ShrinesTxt* gpShrinesTxt;                                                                          // 0x0096D468

extern D2ObjGroupTxt* gpObjgroupTxt;                                                                        // 0x0096D478

int gnObjgroupTxtRecordCount;                                                                               // 0x0096D47C

extern const int gnFirstLevelIdByAct[];                                                                 // 0x006EB2F0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                  // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                  // 0x00648900

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId);                                         // 0x0061E470

D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId);                               // 0x00642AE0

#define ACT_I 0

#define ACT_II 1

#define MAX_PATH 260

#define DRLGROOMFLAG_0x40000 0x40000

struct Level;

struct Room;

struct D2DrlgOutdoorInfoStrc;

struct D2DrlgActStrc;

struct D2DrlgCoordStrc;

struct D2DrlgStrc;

struct Node;

struct DrlgAuxNode;

struct Dungeon;

struct D2DrlgWarpStrc;

struct D2LevelDefBin;

struct D2DrlgOrthStrc;

struct D2DrlgTableEntryStrc;

union D2SeedStrc;

struct D2DrlgCoordsStrc;

struct D2DrlgVertexStrc;

struct D2UnkDrlgRoomTileStrc2;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDst, const char* szFormat, ...); // 0x006CC468

int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoord, int nX, int nY); // 0x0066B980

struct Room
{
    char pad_0[36];
    Room* next;
    char pad_28[56];
    unsigned flags;
};

struct Node
{
    char pad_0[12];
    Node* next;
};

struct DrlgAuxNode
{
    char pad_0[68];
    DrlgAuxNode* next;
};

struct Level
{
    int kind;
    char pad_4[4];
    int f_8;
    int activeCount;
    Room* rooms;
    char pad_14[24];
    char regionA[384];
    Level* next;
    void* mapData;
    char pad_1B4[8];
    void* allocation;
    char pad_1C0[12];
    Node* nodes;
    char pad_1D0[4];
    int inactiveTicks;
    int state;
    char pad_1DC[4];
    char regionB[76];
    unsigned* savedFlags;
};

struct Dungeon
{
    char pad_0[144];
    DrlgAuxNode* aux;
    char pad_94[996];
    void* pool;
    Level* levels;
};

extern "C" void* __fastcall sub_0040B430_Allocate(void*, unsigned, const char*, int, int); // 0x0040B430

extern "C" int __fastcall sub_0040B480_Free(void*, void*, const char*, int, int); // 0x0040B480

extern "C" void __fastcall DRLGROOM_FreeRoomEx(Room*); // 0x0066C100

extern "C" void __fastcall DRLGPRESET_FreeDrlgMap(void*, void*); // 0x006683D0

extern "C" void __fastcall DRLGOUTDOORS_FreeOutdoorInfo(Level*, int); // 0x006754C0

extern "C" void __fastcall DRLGPRESET_ResetDrlgMap(Level*, int); // 0x006674D0

extern "C" void __fastcall DRLGMAZE_ResetMazeRecord(Level*, int); // 0x00673FE0

extern "C" int __stdcall DRLG_FreeInactiveVisRoomTiles(Level*); // 0x00643060

typedef unsigned int size_t;

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

struct D2DrlgTableEntryStrc
{
    char unk0x00[0x38];
};

extern const int gnTileTypeMappingTable[]; // 0x006EEF20

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall DRLG_AddLevelActivity(D2DrlgLevelStrc* pLevel, int nDelta); // 0x00642F70

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730

D2ActiveRoomStrc* __fastcall DUNGEON_AllocRoom(D2DrlgActStrc* pAct, D2DrlgRoomStrc* pDrlgRoom, D2DrlgCoordsStrc* pDrlgCoords, D2DrlgRoomTilesStrc* pRoomTiles, int nLowSeed, int nFlags); // 0x00619890

int __fastcall DRLGOUTDOORS_GetOutLinkVisFlag(D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pDrlgVertex); // 0x00674040

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570

void __fastcall DRLGGRID_AlterFlagsAlongVertexEdge(D2DrlgGridStrc* pDrlgGrid, D2DrlgVertexStrc* pDrlgVertex, int nFlag, int nOperation, int bAlterNextVertex); // 0x0067C760

extern const D2UnkDrlgRoomTileStrc gaDrlgRoomTileLevelRanges[37]; // 0x006EEFC8

extern const D2UnkDrlgRoomTileStrc2 gaDrlgRoomTilePresetUnits[]; // 0x006EF188

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0

struct D2DrlgLevelStrc;

typedef char D2DrlgLevelStrc_size_check[(sizeof(D2DrlgLevelStrc) == 0x230) ? 1 : -1];

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);            // 0x0040B430

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

void __fastcall DRLGMAZE_InitLevelData(D2DrlgLevelStrc* pLevel);                                            // 0x00673B10

void __fastcall DRLGPRESET_InitLevelData(D2DrlgLevelStrc* pLevel);                                          // 0x00667430

void __fastcall DRLGOUTDOORS_AllocOutdoorInfo(D2DrlgLevelStrc* pLevel);                                     // 0x00675320

void __fastcall MazeLevelGenerate(D2DrlgLevelStrc* pLevel);                                            // 0x00673B30

void __fastcall DRLGPRESET_GenerateLevel(D2DrlgLevelStrc* pLevel);                                          // 0x00668100

void __fastcall DRLGOUTDOORS_GenerateLevel(D2DrlgLevelStrc* pLevel);                                        // 0x00675360

int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId);         // 0x0066AF30

void __stdcall SKILLS_GameTileToSubtileCoords(int* pX, int* pY);                                           // 0x00643560

struct D2GameStrc;

void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY); // 0x00642520

typedef void (__stdcall* AUTOMAPFN)(D2RoomStrc*);

typedef void (__stdcall* TOWNAUTOMAPFN)(int, int, int, int);

void* __fastcall DUNGEON_GetMemPoolFromAct(D2DrlgActStrc* pAct); // 0x00619550

void __fastcall DRLGACTIVATE_InitializeRoomExStatusLists(D2DrlgStrc* pDrlg); // 0x0061B7E0

void __fastcall DRLG_LoadTownTiles(D2DrlgStrc* pDrlg); // 0x00641F60

void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg, unsigned char nAct); // 0x00678AD0

struct D2CmpTileStrc;

int __stdcall TileLibraryGetTiles(D2TileLibraryHeaderStrc** ppProjects, int nOrientation, int nMainIndex, int nSubIndex, D2CmpTileStrc** ppTiles, int nMaxTiles); // 0x00604AE0

void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2CmpTileStrc* pTileLibraryEntry); // 0x0066DDE0

int __fastcall DRLG_GetLevelIdFromCoordinates(D2DrlgStrc* pDrlg, int nX, int nY);                   // 0x006427A0

D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00642630

int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040

typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc*,void*);

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*,D2DrlgCoordsStrc*); // 0x00619730

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc*,D2ActiveRoomStrc***,int*); // 0x00619790

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510

// build: symbol ?SKILLS_IsPointNearRoom@* 0x004C5BD0
static int SKILLS_IsPointNearRoom(D2ActiveRoomStrc*,int,int,int); // 0x00641930

inline int D2_ABS(int n) { return n < 0 ? -n : n; }

int __stdcall DRLGROOMTILE_FindTilePresetUnitIndex(int nLevelId, unsigned int nPackedTileInformation, int bIsRightWallWithDoor); // 0x0066D960

struct D2GfxLightStrc;

struct D2BinFieldStrc;

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2MissilesTxt;

struct D2StatesTxt;

struct D2MissileStrc;

struct D2PlayerDataStrc;


typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


void __stdcall DATATBLS_UnloadBin(void* pBinFile); // 0x006125C0
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390

void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit); // 0x00480420

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

int __cdecl D2GFX_IsHardwareRenderMode(); // 0x004F51C0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath); // 0x00648BF0

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile); // 0x0064A3B0

int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730

int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel); // 0x00663270

unsigned int __stdcall sub_00620510(D2UnitStrc*); // 0x00620510

extern int gnUnitDistanceTable[64]; // 0x006EB180

void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive);

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

void __fastcall PLAYER_SetPlayerMode(int nMode, D2UnitStrc* pUnit, int nArg1, int nArg2); // 0x00460780

static int DRLG_IsUnitAlive(D2UnitStrc* pUnit);

D2UnitStrc* __stdcall D2Common_10406(D2UnitStrc* pSource,D2UnitFindCallback pCallback,void* pArg);

void __fastcall UNITS_SetInteractData(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2);

inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x006412F0
D2ObjGroupTxt* __stdcall DATATBLS_GetObjGroupTxtRecord(int nId)
{
    if (gnObjgroupTxtRecordCount > nId)
    {
        return &gpObjgroupTxt[nId];
    }

    return 0;
}

static inline int U04_IsNearRoomY(const D2DrlgCoordsStrc* pCoords, int nY, int nRadius)
{
    return nY + nRadius >= pCoords->nSubtileY || nY - nRadius <= pCoords->nSubtileHeight + pCoords->nSubtileY;
}

inline D2PlayerDataStrc* UNITS_GetPlayerData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return pUnit->pPlayerData;
    }

    return 0;
}

// 0x00641320
void __fastcall DATATBLS_LoadShrinesTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "Code", 4, 0, 0, 0 },
        { "Arg0", 2, 0, 4, 0 },
        { "Arg1", 2, 0, 8, 0 },
        { "Duration in frames", 2, 0, 12, 0 },
        { "reset time in minutes", 4, 0, 16, 0 },
        { "rarity", 4, 0, 17, 0 },
        { "view name", 1, 31, 18, 0 },
        { "niftyphrase", 1, 127, 50, 0 },
        { "effectclass", 4, 0, 178, 0 },
        { "LevelMin", 2, 0, 180, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpShrinesTxt = (D2ShrinesTxt *)DATATBLS_CompileTxt(hArchive, "shrines", pTbl, &gnShrinesTxtRecordCount, 184);
}

// 0x006414B0
D2ShrinesTxt* __stdcall DATATBLS_GetShrinesTxtRecord(int nShrineId)
{
    D2_ASSERT(nShrineId < gnShrinesTxtRecordCount, 351);
    D2_ASSERT(nShrineId >= 0, 352);
    return &gpShrinesTxt[nShrineId];
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }
    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int SizeDifference(D2UnitStrc* a,D2UnitStrc* b)
{
 const unsigned int first=sub_00620510(a)/2;
 const unsigned int second=sub_00620510(b)/2;
 int value=first+second;
 return value<0 ? -value:value;
}

// 0x00641510
void __fastcall DATATBLS_UnloadShrinesTxt()
{
    DATATBLS_UnloadBin(gpShrinesTxt);
    gpShrinesTxt = 0;
    gnShrinesTxtRecordCount = 0;
}

// 0x00641530
int __stdcall sub_00641530(D2UnitStrc* a,D2UnitStrc* b)
{
 const int rawX=CLIENTS_GetUnitXInline(b)-CLIENTS_GetUnitXInline(a);
 int dx=rawX>=0 ? rawX : -rawX;
 int dy=CLIENTS_GetUnitYInline(b)-CLIENTS_GetUnitYInline(a);
 if(dy<0) dy=-dy;
 const int sizeA=sub_00620510(a);
 const int sizeB=sub_00620510(b);
 if(dx<8 && dy<8 && sizeA<4 && sizeB<4) {
  int distance=gnUnitDistanceTable[dx+8*dy];
  if(distance<0) return 0;
  if(sizeA==3 || sizeB==3) --distance;
  if(distance<0) distance=0;
  if(sizeA<=1 || sizeB<=1) ++distance;
  return distance;
 }
 dx-=SizeDifference(a,b);
 dy-=SizeDifference(a,b);
 if(dx<0) dx=0;
 if(dy<0) dy=0;
 return dx>dy ? dy+2*dx : dx+2*dy;
}

inline int UNITS_InlineGetX(D2UnitStrc* pUnit)
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

inline int UNITS_InlineGetY(D2UnitStrc* pUnit)
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

// 0x006416D0
int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    int nX = UNITS_InlineGetX(pOther) - UNITS_InlineGetX(pUnit);
    int nXDiff = nX >= 0 ? nX : -nX;
    int nY = UNITS_InlineGetY(pOther) - UNITS_InlineGetY(pUnit);
    int nYDiff = nY < 0 ? -nY : nY;

    int nSize1 = UNITS_GetUnitSizeX(pUnit);
    int nSize2 = UNITS_GetUnitSizeX(pOther);
    nXDiff = nXDiff - nSize1 / 2 - nSize2 / 2;
    nYDiff = nYDiff - nSize1 / 2 - nSize2 / 2;

    if (nXDiff < 0)
    {
        nXDiff = 0;
    }

    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    return (nXDiff > nYDiff ? nYDiff + 2 * nXDiff : nXDiff + 2 * nYDiff) / 2;
}

static inline int UNITS_ApproxDistance(int nXDiff, int nYDiff)
{
    if (nXDiff > nYDiff)
    {
        return (nYDiff + 2 * nXDiff) / 2;
    }

    return (nXDiff + 2 * nYDiff) / 2;
}

// 0x006417F0
int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY)
{
    int nDX = nX - UNITS_InlineGetX(pUnit);
    int nXDiff = nDX < 0 ? -nDX : nDX;
    int nDY = nY - UNITS_InlineGetY(pUnit);
    int nYDiff = nDY < 0 ? -nDY : nDY;

    if (nXDiff < 0)
    {
        nXDiff = 0;
    }

    if (nYDiff < 0)
    {
        nYDiff = 0;
    }

    return UNITS_ApproxDistance(nXDiff, nYDiff);
}

// 0x00641890
int __stdcall UNITS_IsInRange(D2UnitStrc* pUnit, D2CoordStrc* pCoord, int nDistance)
{
    const int nDiffX = pCoord->nX - UNITS_InlineGetXPosition(pUnit);
    const int nDistanceX = nDiffX < 0 ? -nDiffX : nDiffX;
    int nDistanceY = pCoord->nY - UNITS_InlineGetYPosition(pUnit);
    if (nDistanceY < 0)
    {
        nDistanceY = -nDistanceY;
    }

    return nDistanceX * nDistanceX + nDistanceY * nDistanceY <= nDistance * nDistance;
}

static inline int IsNearRoomY(const D2DrlgCoordsStrc* pCoords,int nY,int nRadius) {
 return nY+nRadius>=pCoords->nSubtileY || nY-nRadius<=pCoords->nSubtileHeight+pCoords->nSubtileY;
}

inline int GetX(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return pUnit->pStaticPath->nXPos;}
 return pUnit->pDynamicPath?PATH_GetXPosition(pUnit->pDynamicPath):0;
}

inline int GetY(D2UnitStrc* pUnit) {
 switch(pUnit->dwUnitType) {case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return pUnit->pStaticPath->nYPos;}
 return pUnit->pDynamicPath?PATH_GetYPosition(pUnit->pDynamicPath):0;
}

static inline int IsTarget(D2UnitStrc* pUnit) {
 switch(pUnit ? pUnit->dwUnitType : UNIT_INVALID) {
 case 0: return pUnit->dwAnimMode!=IMODE_STORED && pUnit->dwAnimMode!=17;
 case 1: return pUnit->dwAnimMode!=IMODE_STORED && pUnit->dwAnimMode!=12;
 case 2: return 0;
 case 3: return 1;
 case 4: return 0;
 }
 return 0;
}

// 0x00641930
static int SKILLS_IsPointNearRoom(D2ActiveRoomStrc* pRoom, int nX, int nY, int nRadius)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (nX + nRadius >= tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    if (nX - nRadius <= tCoords.nSubtileWidth + tCoords.nSubtileX)
    {
        return U04_IsNearRoomY(&tCoords, nY, nRadius);
    }

    return 0;
}

// 0x006419A0
static int DRLG_IsUnitAlive(D2UnitStrc* pUnit) {
 if(!pUnit) return 0;
 switch(pUnit->dwUnitType) {
 case UNIT_PLAYER:
  if(pUnit->dwAnimMode==PLRMODE_DEATH || pUnit->dwAnimMode==PLRMODE_DEAD) return 0;
  return 1;
 case UNIT_MONSTER:
  if(pUnit->dwAnimMode==MONMODE_DEATH || pUnit->dwAnimMode==MONMODE_DEAD) return 0;
  return 1;
 case UNIT_OBJECT: return 0;
 case UNIT_MISSILE: return 1;
 case UNIT_ITEM: return 0;
 default: return 0;
 }
}

// 0x006419F0
D2UnitStrc* __stdcall D2Common_10406(D2UnitStrc* pSource,D2UnitFindCallback pCallback,void* pArg) {
 int nSize=UNITS_GetUnitSizeX(pSource);
 if(nSize<1 || nSize>3) return 0;
 int nSizeIndex=3*(nSize-1);
 D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pSource);
 if(!pRoom) return 0;
 int nX=CLIENTS_GetUnitX(pSource);
 int nY=CLIENTS_GetUnitY(pSource);
 D2ActiveRoomStrc** ppRooms;
 int nRooms;
 DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRooms,&nRooms);
 for(int i=0;i<nRooms;++i) {
  if(!SKILLS_IsPointNearRoom(ppRooms[i],nX,nY,2)) continue;
  for(D2UnitStrc* pUnit=ppRooms[i]->pUnitFirst;pUnit;pUnit=pUnit->ptRoomNext) {
   if(!DRLG_IsUnitAlive(pUnit)) continue;
   int nUnitSize=UNITS_GetUnitSizeX(pUnit);
   if(nUnitSize>=3) nUnitSize=3;
   else if(nUnitSize<=0) continue;
   int nUnitX=GetX(pUnit);
   int nUnitY=GetY(pUnit);
   int bInRange=0;
   switch(nSizeIndex+nUnitSize) {
   case 1:
    if(nX==nUnitX && nY==nUnitY) { if(pUnit!=pSource && pCallback(pUnit,pArg)) return pUnit; }
    break;
   case 2: case 4:
    if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=1) bInRange=1;
    break;
   case 3: case 7: {
    // volatile: the original reads the coordinates from their stack slots here
    const int rangeX=*(const volatile int*)&nX;
    if(rangeX>=nUnitX-1 && rangeX<=nUnitX+1) {
     const int rangeY=*(const volatile int*)&nY;
     if(rangeY>=nUnitY-1 && rangeY<=nUnitY+1) bInRange=1;
    }
    break;
   }
   case 5:
    if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=2) bInRange=1;
    break;
   case 6: {
    int dx=D2_ABS(nX-nUnitX); int dy=D2_ABS(nY-nUnitY);
    if((dx<=2 && dy<=1) || (dy<=2 && dx<=1)) bInRange=1;
    break;
   }
   case 8: {
    int dx=D2_ABS(nX-nUnitX); int dy=D2_ABS(nY-nUnitY);
    if((dx<=2 && dy<=1) || (dy<=2 && dx<=1)) bInRange=1;
    break;
   }
   case 9: {
    const int rangeX=*(const volatile int*)&nX;
    if(rangeX>=nUnitX-2 && rangeX<=nUnitX+2) {
     const int rangeY=*(const volatile int*)&nY;
     if(rangeY>=nUnitY-2 && rangeY<=nUnitY+2) bInRange=1;
    }
    break;
   }
   default: break;
   }
   if(bInRange && pUnit!=pSource && pCallback(pUnit,pArg)) return pUnit;
  }
 }
 return 0;
}

// 0x00641CB0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom,int nX,int nY,D2UnitFindCallback pCallback,void* pArg,int nSize) {
 if(!pRoom) return 0;
 if(nSize<1 || nSize>3) return 0;
 nSize=(nSize-1)*3;
 D2ActiveRoomStrc** ppRoomList;
 int nRooms;
 DUNGEON_GetAdjacentRoomsListFromRoom(pRoom,&ppRoomList,&nRooms);
 for(int i=0;i<nRooms;++i) {
  if(!SKILLS_IsPointNearRoom(ppRoomList[i],nX,nY,2)) continue;
  for(D2UnitStrc* pUnit=ppRoomList[i]->pUnitFirst;pUnit;pUnit=pUnit->ptRoomNext) {
   if(IsTarget(pUnit)) {
    int nUnitSize=UNITS_GetUnitSizeX(pUnit);
    if(nUnitSize>=3) nUnitSize=3;
    else if(nUnitSize<=0) continue;
    int nUnitX=GetX(pUnit);
    int nUnitY=GetY(pUnit);
    int bInRange=0;
    switch(nSize+nUnitSize) {
    case 1:
     if(nX==nUnitX && nY==nUnitY) { if(pCallback(pUnit,pArg)) return pUnit; }
     break;
    case 2: case 4:
     if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=1) bInRange=1;
     break;
    case 3: case 7:
     if(nX>=nUnitX-1 && nX<=nUnitX+1 && nY>=nUnitY-1 && nY<=nUnitY+1) bInRange=1;
     break;
    case 5:
     if(D2_ABS(nX-nUnitX)+D2_ABS(nY-nUnitY)<=2) bInRange=1;
     break;
    case 6: case 8: {
     int dx=D2_ABS(nX-nUnitX); int dy=D2_ABS(nY-nUnitY);
     if((dx<=2 && dy<=1) || (dy<=2 && dx<=1)) bInRange=1;
     break;
    }
    case 9:
     if(nX>=nUnitX-2 && nX<=nUnitX+2 && nY>=nUnitY-2 && nY<=nUnitY+2) bInRange=1;
     break;
    default: break;
    }
    if(bInRange && pCallback(pUnit,pArg)) return pUnit;
   }
  }
 }
 return 0;
}

// 0x00641F20
void __fastcall UNITS_SetInteractData(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_PLAYER)
    {
        if (D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit))
        {
            pPlayerData->nState = 1;
        }

        PLAYER_SetPlayerMode(nMode, pUnit, nArg1, nArg2);
    }
}

// 0x00641F60
void __fastcall DRLG_LoadTownTiles(D2DrlgStrc* pDrlg)
{
    char szPath[MAX_PATH] = { 0 };
    switch (pDrlg->nAct)
    {
    case ACT_I:
// build: symbol ?gszDataGlobal@* 0x006D4118
        wsprintfA(szPath, "%s\\Tiles\\Act1\\Town\\Floor.dt1", gszDataGlobal);
        break;

    case ACT_II:
        wsprintfA(szPath, "%s\\Tiles\\Act2\\Town\\Ground.dt1", gszDataGlobal);
        break;

    case ACT_III:
        wsprintfA(szPath, "%s\\Tiles\\ACT3\\Kurast\\sets.dt1", gszDataGlobal);
        break;

    default:
        return;
    }

    TileLibraryAddProject(pDrlg->pTiles, szPath);
}

// 0x00642010
static void __stdcall DRLG_FreeLevel(void* pool, int keep, Level* level)
{
    if (keep)
    {
        if (!level->savedFlags)
        {
            if (level->f_8)
                level->savedFlags = (unsigned*)sub_0040B430_Allocate(pool, 4 * level->f_8, ".\\DRLG\\Drlg.cpp", 124, 0);
            else
                level->f_8 = 0;
            memset(level->savedFlags, 0, 4 * level->f_8);
        }
    }
    else if (level->savedFlags)
    {
        sub_0040B480_Free(pool, level->savedFlags, ".\\DRLG\\Drlg.cpp", 132, 0);
        level->savedFlags = 0;
    }
    Room* room = level->rooms;
    if (room)
    {
        int index = 0;
        do
        {
            Room* current = room;
            room = room->next;
            if (level->savedFlags)
                level->savedFlags[index++] = current->flags & 1;
            DRLGROOM_FreeRoomEx(current);
        } while (room);
        level->rooms = 0;
        level->f_8 = 0;
    }
    if (level->mapData)
    {
        DRLGPRESET_FreeDrlgMap(pool, level->mapData);
        level->mapData = 0;
    }
    switch (level->kind)
    {
    case 1: DRLGMAZE_ResetMazeRecord(level, keep); break; // 0x00673FE0
    case 2: DRLGPRESET_ResetDrlgMap(level, keep); break; // 0x006674D0
    case 3: DRLGOUTDOORS_FreeOutdoorInfo(level, keep); break; // 0x006754C0
    }
    memset(level->regionA, 0, 384);
    level->state = 0;
    memset(level->regionB, 0, 76);
    if (!keep && level->allocation)
    {
        sub_0040B480_Free(pool, level->allocation, ".\\DRLG\\Drlg.cpp", 183, 0);
        level->allocation = 0;
    }
    Node* node = level->nodes;
    if (node)
    {
        do
        {
            Node* current = node;
            node = node->next;
            sub_0040B480_Free(pool, current, ".\\DRLG\\Drlg.cpp", 197, 0);
        } while (node);
        level->nodes = 0;
    }
}

// 0x00642190
void __fastcall DRLG_FreeDrlg(Dungeon* dungeon)
{
    Level* level = dungeon->levels;
    if (level)
    {
        do
        {
            Level* current = level;
            level = level->next;
            DRLG_FreeLevel(dungeon->pool, 0, current);
            sub_0040B480_Free(dungeon->pool, current, ".\\DRLG\\Drlg.cpp", 221, 0);
        } while (level);
        dungeon->levels = 0;
    }
    DrlgAuxNode* aux = dungeon->aux;
    if (aux)
    {
        do
        {
            DrlgAuxNode* current = aux;
            aux = aux->next;
            sub_0040B480_Free(dungeon->pool, current, ".\\DRLG\\Drlg.cpp", 236, 0);
        } while (aux);
        dungeon->aux = 0;
    }
    sub_0040B480_Free(dungeon->pool, dungeon, ".\\DRLG\\Drlg.cpp", 242, 0);
}

// 0x00642230
int __fastcall DRLG_GetHoradricStaffTombLevelId(D2DrlgStrc* pDrlg)
{
    if (pDrlg)
    {
        return pDrlg->nStaffTombLevel;
    }

    return 0;
}

// 0x00642240
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2)
{
    if (pDrlgCoord1->nPosX > pDrlgCoord2->nPosX)
    {
        if (pDrlgCoord1->nPosX == pDrlgCoord2->nPosX + pDrlgCoord2->nWidth)
            return 0;
    }
    else
    {
        if (pDrlgCoord2->nPosX == pDrlgCoord1->nPosX + pDrlgCoord1->nWidth)
            return 2;
    }

    if (pDrlgCoord1->nPosY > pDrlgCoord2->nPosY)
    {
        if (pDrlgCoord1->nPosY == pDrlgCoord2->nPosY + pDrlgCoord2->nHeight)
            return 1;
    }
    else
    {
        if (pDrlgCoord2->nPosY == pDrlgCoord1->nPosY + pDrlgCoord1->nHeight)
            return 3;
    }

    return -1;
}

// 0x006422A0
void __fastcall DRLG_CreateRoomForRoomEx(D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgCoordsStrc tDrlgCoords = { 0 };

    tDrlgCoords.nTileXPos = pDrlgRoom->pDrlgCoord.nPosX;
    tDrlgCoords.nTileYPos = pDrlgRoom->pDrlgCoord.nPosY;
    tDrlgCoords.nTileWidth = pDrlgRoom->pDrlgCoord.nWidth;
    tDrlgCoords.nTileHeight = pDrlgRoom->pDrlgCoord.nHeight;

    tDrlgCoords.nSubtileX = pDrlgRoom->pDrlgCoord.nPosX;
    tDrlgCoords.nSubtileY = pDrlgRoom->pDrlgCoord.nPosY;
    tDrlgCoords.nSubtileWidth = pDrlgRoom->pDrlgCoord.nWidth;
    tDrlgCoords.nSubtileHeight = pDrlgRoom->pDrlgCoord.nHeight;

    DUNGEON_GameTileToSubtileCoords(&tDrlgCoords.nSubtileX, &tDrlgCoords.nSubtileY);
    DUNGEON_GameTileToSubtileCoords(&tDrlgCoords.nSubtileWidth, &tDrlgCoords.nSubtileHeight);

    D2DrlgRoomTilesStrc* pTiles = &pDrlgRoom->ptDrlgTiles->pTiles;
    if (pTiles->nWalls || pTiles->nFloors)
    {
        int nFlags = 0;
        if (pDrlgRoom->dwFlags & DRLGROOMFLAG_0x40000)
        {
            nFlags = 4;
        }
        else if (pDrlgRoom->dwOtherFlags & 1)
        {
            nFlags = 1;
        }

        pDrlgRoom->pRoom = DUNGEON_AllocRoom(pDrlg->pAct, pDrlgRoom, &tDrlgCoords, pTiles, (int)SEED_RollRandomNumber(&pDrlgRoom->pSeed), nFlags);
    }
}

// 0x00642380
int* __fastcall DRLG_GetRoomCenterX_RoomWarpXFromRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->ptDrlgLevel->nRoom_Center_Warp_X;
}

// 0x00642390
static void DRLG_RestoreSavedRoomFlags(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->nRooms && pLevel->pPresetMaps)
    {
        int nCounter = 0;
        for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
        {
            if (pLevel->pPresetMaps[nCounter++])
            {
                pDrlgRoom->dwOtherFlags |= 1;
            }
        }
    }
}

// 0x006423D0
static void DRLG_ComputeLevelWarpInfo(D2DrlgLevelStrc* pLevel)
{
    int bHasWarp = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (pDrlgRoom->dwFlags & 0x30000)
        {
            bHasWarp = 1;
        }

        if ((pDrlgRoom->dwFlags & 0xFF0) && !bHasWarp)
        {
            unsigned int nMask = 0x10;
            unsigned char nWarpIndex = 0;
            for (; nMask & 0xFF0; nMask <<= 1, ++nWarpIndex)
            {
                if ((pDrlgRoom->dwFlags & nMask) && DRLGWARP_GetWarpDestinationFromArray(pLevel, nWarpIndex) != -1)
                {
                    bHasWarp = 1;
                    break;
                }
            }
        }

        if (bHasWarp)
        {
            int* pX = &pLevel->nRoom_Center_Warp_X[pLevel->nRoomCoords];
            int* pY = &pLevel->nRoom_Center_Warp_Y[pLevel->nRoomCoords];
            *pX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth / 2;
            bHasWarp = 0;
            *pY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight / 2;
            SKILLS_GameTileToSubtileCoords(pX, pY);
            ++pLevel->nRoomCoords;
        }
    }
}

// 0x006424A0
void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel)
{
    SEED_InitLowSeed(&pLevel->pSeed, pLevel->eLevelId + pLevel->pDrlg->dwStartSeed);

    switch (pLevel->nDrlgType)
    {
    case 1:
        MazeLevelGenerate(pLevel);
        break;
    case 2:
        DRLGPRESET_GenerateLevel(pLevel);
        break;
    case 3:
        DRLGOUTDOORS_GenerateLevel(pLevel);
        break;
    }

    DRLG_RestoreSavedRoomFlags(pLevel);
    DRLG_ComputeLevelWarpInfo(pLevel);
}

// 0x00642520
void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY)
{
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    const D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;

    *pTileMinX = pDrlgCoord->nPosX;
    *pTileMinY = pDrlgCoord->nPosY;
    *pTileMaxX = pDrlgCoord->nPosX + pDrlgCoord->nWidth;
    *pTileMaxY = pDrlgCoord->nPosY + pDrlgCoord->nHeight;

    while (pDrlgRoom)
    {
        if (pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth > *pTileMaxX)
        {
            *pTileMaxX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        }

        if (pDrlgRoom->pDrlgCoord.nPosX < *pTileMinX)
        {
            *pTileMinX = pDrlgRoom->pDrlgCoord.nPosX;
        }

        if (pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight > *pTileMaxY)
        {
            *pTileMaxY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        }

        if (pDrlgRoom->pDrlgCoord.nPosY < *pTileMinY)
        {
            *pTileMinY = pDrlgRoom->pDrlgCoord.nPosY;
        }

        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }
}

// 0x00642590
void __fastcall DRLG_UpdateRoomExCoordinates(D2DrlgLevelStrc* pLevel)
{
    int nTileX[2];
    int nTileY[2];

    if (!pLevel)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 739);
        exit(-1);
    }

    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    if (!pDrlgRoom)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 740);
        exit(-1);
    }

    DRLG_GetMinAndMaxCoordinatesFromLevel(pLevel, &nTileX[0], &nTileY[0], &nTileX[1], &nTileY[1]);

    D2DrlgRoomStrc* pRoom = pDrlgRoom;

    if (pLevel->nWidth < nTileX[1] - nTileX[0])
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 747);
        exit(-1);
    }

    if (pLevel->nHeight < nTileY[1] - nTileY[0])
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 748);
        exit(-1);
    }

    const int nMinX = nTileX[0];
    const int nMinY = nTileY[0];
    for (; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        pRoom->pDrlgCoord.nPosX += pLevel->nPosX - nMinX;
        pRoom->pDrlgCoord.nPosY += pLevel->nPosY - nMinY;
    }
}

// 0x00642630
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2_ASSERT(pLevel, 0x2FD);
    D2_ASSERT(pLevel->ptRoomFirst, 0x2FE);
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pDrlgRoom->pDrlgCoord, nX, nY))
            return pDrlgRoom;
    }
    return 0;
}

// 0x006426A0
int __fastcall DRLG_IsTownLevel(int nLevelId)
{
    switch (nLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
    case LEVEL_LUTGHOLEIN:
    case LEVEL_KURASTDOCKTOWN:
    case LEVEL_THEPANDEMONIUMFORTRESS:
    case LEVEL_HARROGATH:
        return 1;

    default:
        return 0;
    }
}

inline D2DrlgLevelStrc* DRLG_InlineGetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->eLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00642740
int __cdecl sub_00642740()
{
    return 0;
}

// 0x00642750
int __stdcall DRLG_GetLevelTypeFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwLevelType;
}

// 0x00642770
int __fastcall DRLG_GetDrlgTypeFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwDrlgType;
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00642780
static inline D2DrlgLevelStrc* DRLG_WalkLevelList(D2DrlgStrc* pDrlg)
{
    D2DrlgLevelStrc* pLevel = pDrlg->pLevel;
    while (pLevel)
    {
        pLevel = pLevel->pNextLevel;
    }
    return pLevel;
}

// 0x006427A0
int __fastcall DRLG_GetLevelIdFromCoordinates(D2DrlgStrc* pDrlg, int nX, int nY)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pLevel->pLevelCoords, nX, nY))
        {
            return pLevel->eLevelId;
        }
    }

    return 0;
}

// 0x006427F0
unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId)
{
    for (int nAct = 1; nAct <= 5; ++nAct)
    {
        if (nLevelId < gnFirstLevelIdByAct[nAct])
        {
            return nAct - 1;
        }
    }

    return 0;
}

// 0x00642820
int __stdcall DRLG_GetSaveMonstersFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwSaveMonsters;
}

// 0x00642840
int __stdcall DRLG_GetLOSDrawFromLevelId(int nLevelId)
{
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwLOSDraw;
}

// 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* i = pDrlg->pWarp; i; i = i->pNext)
    {
        if (i->nLevel == nLevelId)
        {
            return i;
        }
    }

    D2LevelDefBin* pLevelDefBin = DATATBLS_GetLevelDefRecord(nLevelId);
    D2DrlgWarpStrc* pDrlgWarp = (D2DrlgWarpStrc*)sub_0040B430(pDrlg->pMempool, sizeof(D2DrlgWarpStrc), ".\\DRLG\\Drlg.cpp", 0x3E0, 0);
    pDrlgWarp->nLevel = nLevelId;

    for (int i = 0; i < 8; ++i)
    {
        pDrlgWarp->nVis[i] = pLevelDefBin->dwVis[i];
        pDrlgWarp->nWarp[i] = pLevelDefBin->dwWarp[i];
    }

    pDrlgWarp->pNext = pDrlg->pWarp;
    pDrlg->pWarp = pDrlgWarp;

    return pDrlgWarp;
}

// 0x00642920
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nId)
{
    for (int i = 0; i < 8; ++i)
    {
        if (pDrlgWarp->nVis[i] == nVis)
        {
            pDrlgWarp->nWarp[i] = nWarp;
            return pDrlgWarp;
        }
    }

    if (nId == -1)
    {
        for (int i = 0; i < 8 && nId == -1; ++i)
        {
            if (!pDrlgWarp->nVis[i] && pDrlgWarp->nWarp[i] == -1)
            {
                nId = i;
            }
        }
    }

    pDrlgWarp->nVis[nId] = nVis;
    pDrlgWarp->nWarp[nId] = nWarp;
    return pDrlgWarp;
}

D2DrlgLevelStrc* __stdcall sub_M121_Emit_00642780(D2DrlgStrc* pDrlg) { return DRLG_WalkLevelList(pDrlg); }

// 0x006429D0
void __cdecl DRLG_Nop()
{
}

// 0x006429E0
unsigned char __stdcall DRLG_GetActFromLevelType(int nLevelType)
{
    return DATATBLS_GetLevelTypesTxtRecord(nLevelType)->nAct;
}

// 0x00642A00
int __fastcall DRLG_IsOnClient(D2DrlgStrc* pDrlg)
{
    D2_ASSERT(pDrlg, 0x42E);

    return pDrlg->dwFlags & 1;
}

// 0x00642A30
void __fastcall DRLGANIM_InitCache(D2DrlgStrc* pDrlg, D2DrlgTileDataStrc* pTileData)
{
    D2CmpTileStrc* ppTileLibraryEntry[40];

    D2_ASSERT(pDrlg, 1079);
    D2_ASSERT(pTileData, 1080);

    memset(pTileData, 0x00, sizeof(D2DrlgTileDataStrc));

    int nSequence = 0;
    int nStyle = 0;
    switch (pDrlg->nAct)
    {
    case 0:
        break;

    case 1:
        nSequence = 1;
        break;

    case 2:
        nStyle = 29;
        nSequence = 12;
        break;

    default:
        return;
    }

    D2_ASSERT(TileLibraryGetTiles(pDrlg->pTiles, 0, nStyle, nSequence, ppTileLibraryEntry, 40), 1100);
    DRLGROOMTILE_InitTileData(0, pTileData, 0, 0, 0, ppTileLibraryEntry[0]);
}

#pragma function(memset)

// 0x00642AE0
D2DrlgLevelStrc* __fastcall DRLG_AllocLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    D2DrlgLevelStrc* pLevel = (D2DrlgLevelStrc*)FOG_AllocPool(pDrlg->pMempool, sizeof(D2DrlgLevelStrc), ".\\DRLG\\Drlg.cpp", 0x1A8, 0);
    memset(pLevel, 0, sizeof(D2DrlgLevelStrc));

    pLevel->pDrlg = pDrlg;
    pLevel->eLevelId = nLevelId;
    pLevel->nLevelType = DATATBLS_GetLevelDefRecord(nLevelId)->dwLevelType;
    pLevel->nDrlgType = DATATBLS_GetLevelDefRecord(nLevelId)->dwDrlgType;

    if (pDrlg->dwFlags & 1)
    {
        pLevel->dwFlags |= 0x10;
    }

    SEED_InitLowSeed(&pLevel->pSeed, pLevel->eLevelId + pLevel->pDrlg->dwStartSeed);

    switch (pLevel->nDrlgType)
    {
    case 1:
        DRLGMAZE_InitLevelData(pLevel);
        break;
    case 2:
        DRLGPRESET_InitLevelData(pLevel);
        break;
    case 3:
        DRLGOUTDOORS_AllocOutdoorInfo(pLevel);
        break;
    default:
        break;
    }

    pLevel->pNextLevel = pDrlg->pLevel;
    pDrlg->pLevel = pLevel;

    return pLevel;
}

// 0x00642BB0
D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgLevelStrc* pLevel = pDrlg->pLevel; pLevel; pLevel = pLevel->pNextLevel)
    {
        if (pLevel->eLevelId == nLevelId)
        {
            return pLevel;
        }
    }

    return DRLG_AllocLevel(pDrlg, nLevelId);
}

// 0x00642BE0
int __fastcall DRLG_GetNumberOfPopulatedRoomsInLevel(D2DrlgStrc* pDrlg, int nLevelId)
{
    int nCounter = 0;
    D2DrlgLevelStrc* pLevel = DRLG_InlineGetLevel(pDrlg, nLevelId);

    for (D2DrlgRoomStrc* i = pLevel->ptRoomFirst; i; i = i->pDrlgRoomNext)
    {
        if (!(i->dwFlags & 0x800000))
        {
            ++nCounter;
        }
    }

    return nCounter;
}

// 0x00642C30
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pDrlgRoomHint, D2DrlgLevelStrc* pLevel)
{
    if (pDrlgRoomHint)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&pDrlgRoomHint->pDrlgCoord, nX, nY))
        {
            return pDrlgRoomHint;
        }

        for (int i = 0; i < pDrlgRoomHint->nRoomsNear; ++i)
        {
            D2DrlgRoomStrc* pNear = pDrlgRoomHint->ppRoomsNear[i];
            if (pDrlgRoomHint != pNear && DRLGROOM_AreXYInsideCoordinates(&pNear->pDrlgCoord, nX, nY))
            {
                return pNear;
            }
        }
    }

    if (!pLevel)
    {
        pLevel = DRLG_InlineGetLevel(pDrlg, DRLG_GetLevelIdFromCoordinates(pDrlg, nX, nY));
    }

    if (!pLevel->ptRoomFirst)
    {
        DRLG_InitLevel(pLevel);
    }

    return DRLG_GetRoomExFromLevelAndCoordinates(pLevel, nX, nY);
}

// 0x00642D10
void __fastcall DRLG_SetLevelPositionAndSize(D2DrlgStrc* pDrlg,D2DrlgLevelStrc* pLevel)
{
 D2LevelDefBin* def=DATATBLS_GetLevelDefRecord(pLevel->eLevelId);
 D2DrlgLevelStrc* depend=0;
 int x=0,y=0;
 const int width=def->dwSizeX[pDrlg->nDifficulty];
 const int dependencyId=def->dwDepend;
 pLevel->nWidth=width;
 pLevel->nHeight=def->dwSizeY[pDrlg->nDifficulty];
 if(dependencyId) { depend=DRLG_GetLevel(pDrlg,dependencyId);x=depend->nPosX;y=depend->nPosY; }
 pLevel->nPosX=x+def->dwOffsetX;
 pLevel->nPosY=y+def->dwOffsetY;
}

#pragma intrinsic(memset)

// 0x00642DA0
D2DrlgStrc* __fastcall DRLG_AllocDrlg(D2DrlgActStrc* pAct, unsigned char nActNo, void* hArchive, unsigned int nInitSeed, int nTownLevelId, unsigned int nFlags, D2GameStrc* pGame, unsigned char nDifficulty, AUTOMAPFN pfAutoMap, TOWNAUTOMAPFN pfTownAutoMap)
{
    void* pMemPool = DUNGEON_GetMemPoolFromAct(pAct);
    D2DrlgStrc* pDrlg = (D2DrlgStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgStrc), ".\\DRLG\\Drlg.cpp", 0x3A, 0);
    memset(pDrlg, 0, sizeof(D2DrlgStrc));

    pDrlg->pMempool = pMemPool;
    pDrlg->hArchive = hArchive;
    pDrlg->nAct = nActNo;
    pDrlg->pAct = pAct;

    SEED_InitLowSeed(&pDrlg->pSeed, nInitSeed);

    pDrlg->dwStartSeed = SEED_RollRandomNumber(&pDrlg->pSeed);
    pDrlg->dwGameLowSeed = nInitSeed;
    pDrlg->dwFlags = nFlags;
    pDrlg->pGame = pGame;
    pDrlg->nDifficulty = nDifficulty;
    pDrlg->pfAutomap = pfAutoMap;
    pDrlg->pfTownAutomap = pfTownAutoMap;

    if (nActNo == 1)
    {
        unsigned int nStaffLevelOffset;
        unsigned int nBossLevelOffset;
        unsigned __int64 lSeed;
        do
        {
            lSeed = (unsigned __int64)pDrlg->pSeed.nLowSeed * 0x6AC690C5 + pDrlg->pSeed.nHighSeed;
            pDrlg->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pDrlg->pSeed.nLowSeed = (unsigned int)lSeed;
            nStaffLevelOffset = (unsigned int)lSeed % 7;
            lSeed = (unsigned __int64)pDrlg->pSeed.nLowSeed * 0x6AC690C5 + pDrlg->pSeed.nHighSeed;
            pDrlg->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pDrlg->pSeed.nLowSeed = (unsigned int)lSeed;
            nBossLevelOffset = (unsigned int)lSeed % 7;
        }
        while (nStaffLevelOffset == nBossLevelOffset);

        pDrlg->nStaffTombLevel = nStaffLevelOffset + 0x42;
        pDrlg->nBossTombLevel = nBossLevelOffset + 0x42;
    }
    else if (nActNo == 2)
    {
        pDrlg->bJungleInterlink = SEED_RollRandomNumber(&pDrlg->pSeed) & 1;
    }

    DRLG_LoadTownTiles(pDrlg);
    DRLGACTIVATE_InitializeRoomExStatusLists(pDrlg);
    DRLGOUTPLACE_CreateLevelConnections(pDrlg, nActNo);

    if (nTownLevelId)
    {
        DRLG_InitLevel(DRLG_GetLevel(pDrlg, nTownLevelId));
    }

    return pDrlg;
}

// 0x00642F70
void __fastcall DRLG_AddLevelActivity(D2DrlgLevelStrc* pLevel, int nDelta)
{
    pLevel->bActive += nDelta;
    pLevel->bActive = pLevel->bActive <= 0 ? 0 : pLevel->bActive;
    pLevel->dwInactiveFrames = 10;

    int* pVisLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
    for (int i = 0; i < 8; ++i)
    {
        const int nVisLevelId = pVisLevelIds[i];
        if (nVisLevelId)
        {
            D2DrlgLevelStrc* pVisLevel = DRLG_InlineGetLevel(pLevel->pDrlg, nVisLevelId);
            pVisLevel->bActive += nDelta;
            pVisLevel->bActive = pVisLevel->bActive <= 0 ? 0 : pVisLevel->bActive;
            pVisLevel->dwInactiveFrames = 10;
        }
    }
}

// 0x00643020
void __fastcall DRLG_UpdateLevelActivityOnRoomChange(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2)
{
    D2DrlgLevelStrc* pLevel1 = pDrlgRoom1 ? pDrlgRoom1->ptDrlgLevel : 0;
    D2DrlgLevelStrc* pLevel2 = pDrlgRoom2 ? pDrlgRoom2->ptDrlgLevel : 0;

    if (pLevel1 != pLevel2)
    {
        if (pLevel1)
        {
            DRLG_AddLevelActivity(pLevel1, -1);
        }

        if (pLevel2)
        {
            DRLG_AddLevelActivity(pLevel2, 1);
        }
    }
}

// 0x00643060
int __stdcall DRLG_FreeInactiveVisRoomTiles(D2DrlgLevelStrc* pLevel)
{
    void* pMemPool = pLevel->pDrlg->pMempool;

    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if (pRoom->fRoomStatus <= 3 || pRoom->dwFlags & 0x100000)
        {
            return 0;
        }
    }

    int* pLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
    for (int j = 0; j < 8; ++j)
    {
        if (pLevelIds[j])
        {
            D2DrlgLevelStrc* pCurrentLevel = DRLG_InlineGetLevel(pLevel->pDrlg, pLevelIds[j]);
            D2DrlgRoomStrc* pRoom = pCurrentLevel->ptRoomFirst;
            if (pRoom)
            {
                int* pLevels = DRLGROOM_GetVisArrayFromLevelId(pCurrentLevel->pDrlg, pCurrentLevel->eLevelId);
                unsigned int dwFlags = 0;
                for (int i = 0; i < 8; ++i)
                {
                    if (pLevels[i] == pLevel->eLevelId)
                    {
                        dwFlags |= 1 << (i + 4);
                    }
                }

                for (; pRoom; pRoom = pRoom->pDrlgRoomNext)
                {
                    if (pRoom->dwFlags & dwFlags && (pRoom->fRoomStatus <= 3 || pRoom->dwFlags & 0x100000))
                    {
                        return 0;
                    }
                }

                for (pRoom = pCurrentLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
                {
                    if (pRoom->dwFlags & dwFlags)
                    {
                        DRLGROOM_FreeRoomTiles(pMemPool, pRoom);
                        if (pRoom->ppRoomsNear)
                        {
                            FOG_FreeServerMemory(pMemPool, pRoom->ppRoomsNear, ".\\DRLG\\Drlg.cpp", 367, 0);
                            pRoom->ppRoomsNear = 0;
                            pRoom->nRoomsNear = 0;
                        }
                    }
                }
            }
        }
    }

    return 1;
}

// 0x00643200
void __fastcall DRLG_UpdateAndFreeInactiveRooms(Dungeon* dungeon)
{
    Level* level = dungeon->levels;
    void* pool = dungeon->pool;
    while (level)
    {
        if (!level->activeCount && level->rooms)
        {
            if (level->inactiveTicks)
                --level->inactiveTicks;
            else if (DRLG_FreeInactiveVisRoomTiles(level))
                DRLG_FreeLevel(pool, 1, level);
            else
                level->inactiveTicks = 10;
        }
        level = level->next;
    }
}

// 0x00643260
void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    *pX = 16 * (nX - nY);
    *pY = 8 * (nX + nY);
}

// 0x00643290
void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    *pX = (nX - nY) >> 1;
    *pY = (nX + nY) >> 2;
}

int __fastcall sub_U04_Emit_00641930(D2ActiveRoomStrc** ppRooms, int nCount, int nX, int nY)
{
    for (int i = 0; i < nCount; ++i)
    {
        if (SKILLS_IsPointNearRoom(ppRooms[i], nX, nY, 2))
        {
            return i;
        }
    }
    return -1;
}

// 0x006432C0
void __stdcall DUNGEON_ClientToGameTileCoords(int* pX, int* pY)
{
    const int nX = *pX;
    const int nY = *pY;
    *pX = (2 * nY + nX) / 160;
    *pY = (2 * nY - nX) / 160;
}

// 0x00643310
void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY)
{
    int nX = *pX;
    int nY = *pY;
    *pX = 80 * (nX - nY);
    *pY = (80 * (nX + nY)) >> 1;
}

// 0x006433C0
void __stdcall DUNGEON_GameToClientTileDrawPositionCoords(int nX, int nY, int* pX, int* pY)
{
    *pX = 80 * (nX - nY);
    *pY = 40 * (nX + nY);
    *pX -= 80;
    *pY += 80;
}

// 0x00674200
int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    return !(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x1B81);
}

// 0x00675770
void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;
    do
    {
        if (pVertex->dwFlags & 1)
        {
            int nVisFlag = DRLGOUTDOORS_GetOutLinkVisFlag(pLevel, pVertex);
            int nPacked = 2 * (pVertex->nDirection != 0) + 1;
            DRLGGRID_AlterFlagsAlongVertexEdge(&pOutdoors->pGrid[1], pVertex, nVisFlag, 0, 1);
            DRLGGRID_AlterFlagsAlongVertexEdge(&pOutdoors->pGrid[2], pVertex, nPacked, 0, 1);
        }
        pVertex = pNext;
        pNext = pVertex->pNext;
    }
    while (pVertex != pOutdoors->pVertex);
}

#include "gen/data/Source/D2Common/DRLG/Drlg.inc"
