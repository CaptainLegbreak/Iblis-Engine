#include "D2ObjectIds.h"
#include "D2LevelIds.h"
#include "D2Game.h"
#include "D2GameAux.h"
#include "D2UnitData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2Constants.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"
#include "D2ObjModes.h"
#include "D2LanguageNames.h"
#include "D2CommonApi.h"
#include "FogApi.h"
#include "D2CommonApi2.h"
#include "D2TxtItems.h"
#include "D2ClientApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_OBJECT 2

#define EVENTTYPE_MODECHANGE 0

#define EVENTTYPE_STATREGEN 3

#define OBJECTS_CONSTANT_00552AB0 2

#define UNIT_LIST_SIZE 128

#define WELL_PARAM 2

struct D2PoolSystemStrc;
struct D2TimerArg2Strc;

struct D2MonStatsTxt;

union D2SeedStrc;

struct D2ObjectDataStrc;

struct D2ObjectControlStrc;

struct D2ObjInitFnStrc;

struct D2LevelsTxt;

struct D2ObjectTableStrc;

struct D2LvlWarpTxt;

struct D2PlayerDataStrc;

struct D2WarpDelayStrc;

struct D2WarpEventArgStrc;


struct R00601DC0;

struct D2TimerArg2Strc
{
    int nUnitGUID;
    D2TimerArg2Strc* pNext;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* pGUIDList;
    unsigned int dwUnitId;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2ObjectTableStrc
{
    int nObjectId;
    int nMin;
    int nMax;
};

extern const D2ObjectTableStrc gaShrineObjectTable[6]; // 0x006E1080

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230

D2UnitStrc* __fastcall ITEMS_DropGoldAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords); // 0x00559300


D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0


#include "D2GameFuncs.h"

int __fastcall ACT2Q6_GetObjectIdForArcaneThing(D2GameStrc* pGame); // 0x0059D830

void __fastcall FOG_FreePool(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480


void __fastcall OBJECTS_InitFunction02_Urn(D2ObjInitFnStrc* pOp); // 0x0054FBB0

struct D2WarpDelayStrc
{
    char unk0x00[0xDC];
    unsigned int dwWarpDelay;
};

struct D2WarpEventArgStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    D2ActiveRoomStrc* pRoom;
    int unk0x0C;
    D2WarpDelayStrc* pDelay;
    int nX;
    int nY;
};

extern "C" const char gszSUnitSourceFile[]; // 0x006E10F8

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0



struct R00601DC0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_00601DC0_IsOpen();
};


void __fastcall OBJECTS_FreeTimerArg(D2GameStrc* pGame, D2TimerArgStrc* pTimerArg); // 0x0054F580



struct D2DrlgCoordsStrc;

struct D2ObjectPopulateStrc;

enum
{
    OBJECT_COUNTESSCHEST = 0x173,
};

D2UnitStrc* __fastcall OBJECTS_SpawnPresetChest(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused); // 0x0054F180

static int __stdcall OBJECTS_CanPlaceObject(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY);

struct D2ObjGroupTxt
{
    unsigned int dwId[8];
    unsigned char nDensity[8];
    unsigned char nProbability[8];
    unsigned char nShrines;
    unsigned char nWells;
    unsigned short pad0x32;
};

typedef int (__fastcall* OBJTHEMEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

struct D2ObjectPopulateStrc
{
    int bActive;
    OBJTHEMEFN pfPopulate;
};

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern D2ObjectPopulateStrc gaObjectThemeTable[7]; // 0x00731E68

extern OBJECTPOPULATEFN sgPopulateTable[10]; // 0x00731D00


#define LEVEL_FRIGIDHIGHLANDS 111

struct D2CoordInitStrc;

typedef D2UnitStrc* (__fastcall* PRESETSPAWNFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode);

extern PRESETSPAWNFN gpfnPresetObjectSpawners[]; // 0x00731D28

extern int gnPresetObjectSpawnerCount; // 0x00731D4C

void __stdcall OBJECTS_SpawnFliesOnCorpse(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00551150

struct D2CoordInitStrc
{
    D2CoordStrc* pCoords;
    int nCount;
};

extern D2CoordInitStrc gaCoordInit[]; // 0x00731EB4

D2UnitStrc* __stdcall OBJECTS_CreateObject(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom); // 0x00550380

#define ROOM_MIN_SUBTILES 2

#define CREATE_TRIES 5

#define CREATE_SIZE_GROW 6

#define LINE_CREATE_ROOM 1358

#define IFLAG_IDENTIFIED 0x00000010

#define PACKETSIZE06_HEADER 0x92

#define UPDATEUI_TRADEACCEPTED 6

#define TRADESTATE_ACCEPTED 3

#define D2_PAIR_CAPACITY 0x3FF

#define D2S_ERROR_READ_SIZE 0x14

struct D2StaticPathStrc;

struct D2PlayerListStrc;

struct D2ItemTradeStrc;

struct D2PlayerTradeStrc;

struct D2ItemsTxt;

struct D2SkillsTxt;

struct D2UnkPairStrc;

struct D2PackedWordStrc;

struct D2Unk0056DCC0Strc;

typedef void (__fastcall* D2ObjInitFn)(D2ObjInitFnStrc* pOp);

extern D2ObjInitFn sgInitTable[80]; // 0x00731BC0

D2TimerArgStrc* __fastcall OBJECTS_AllocTimerArg(D2GameStrc* pGame); // 0x0054F520

struct D2UnkPairStrc
{
    int nFirst;
    int nSecond;
};

struct D2Unk0056DCC0Strc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    int f_C;
    int f_10;
    int nUnk0x14;
    int nUnk0x18;
    int nUnk0x1C;
    void* pUnk0x20;
};

enum D2C_UnitFlags
{
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_ISVALIDTARGET = 0x00000008,
};

enum D2C_ElemTypes
{
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};


extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* lpSystemTime); // 0x006CC1D4

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

D2UnitStrc* __fastcall OBJECTS_PopulateFn3_CommonObjects(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability); // 0x00551470

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100


void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0


void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pUnit, int nArg); // 0x0053DA90


void __fastcall SKILLS_ApplyAreaEffect(D2GameStrc* pGame, D2Unk0056DCC0Strc* pRecord); // 0x0056DCC0





#define EVENTTYPE_PERIODICSTATS 9

static void __stdcall OBJECTS_SpawnArmorStandOrWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords, int bWeaponRack); // 0x00552200

typedef char (__fastcall* SPAWNCHECKFN)(D2GameStrc* pGame, int nArg, int nX, int nY);

static int __stdcall OBJECTS_CanPlaceObjectWithClearance(D2ActiveRoomStrc*, int, D2DrlgCoordsStrc*, D2CoordStrc*, int); // 0x00550220

extern int gnCasketClusterIds[]; // 0x00731D50

extern int gnCasket6ClusterIds[]; // 0x00731D5C

extern int gnUrnClusterIds[]; // 0x00731D64

extern int gnMummyCoffinClusterIds[]; // 0x00731D78

extern int gnBasketClusterIds[]; // 0x00731D80

extern int gnObjectSpawnOffsetsX[]; // 0x00731B7C

extern int gnObjectSpawnOffsetsY[]; // 0x00731B9C

extern int gnCasketClusterIdCount; // 0x00731D88

extern int gnCasket6ClusterIdCount; // 0x00731D8C

extern int gnUrnClusterIdCount; // 0x00731D90

extern int gnMummyCoffinClusterIdCount; // 0x00731D94

extern int gnBasketClusterIdCount; // 0x00731D98

struct D2ItemDropStrc;


extern int gaDirectionX_00731B7C[]; // 0x00731B7C

extern int gaDirectionY_00731B9C[]; // 0x00731B9C

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

#define D2_MAX(a,b) ((a)>(b)?(a):(b))

#define UNITFLAG_TARGETABLE 0x02

typedef bool (__fastcall* D2ObjectSpawnCallback)(D2GameStrc* pGame, int nArg, int nX, int nY);

typedef bool (__fastcall* OBJRGN_SpawnCheckFn)(D2GameStrc* pGame, int nLevelId, int nX, int nY);

bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId); // 0x00547300

bool __fastcall OBJRGN_CanSpawnWell(D2GameStrc* pGame, int nLevelId, int nX, int nY); // 0x005473A0

void __fastcall OBJRGN_SetWellCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY); // 0x00547400

D2UnitStrc* __stdcall sub_00550540_SpawnObjectInBox(D2GameStrc* pGame, int nObjectId, int nWidth, int nHeight, D2ActiveRoomStrc* pRoom, int nLevelId, OBJRGN_SpawnCheckFn pfnCheck); // 0x00550540

extern int gnObjectSpawnOffsetsX[8]; // 0x00731B7C

extern int gnObjectSpawnOffsetsY[8]; // 0x00731B9C

extern int gnUrnClusterIds[]; // 0x00731D64

D2UnitStrc* __fastcall OBJECTS_PopulateFn7_RogueOnStick(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

D2UnitStrc* __fastcall OBJECTS_PopulateFn2_WaypointShrine(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnused, int nObjectId, unsigned short nProbability);

int __fastcall OBJECTS_SpawnBarrel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

int __fastcall OBJECTS_SpawnRandomItemGrid(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

int __fastcall OBJECTS_SpawnArmorStand(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

int __fastcall OBJECTS_SpawnWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords);

static int gnUrnClusterIdCount; // 0x00731D90

static int __stdcall OBJECTS_PopulateRoomTheme(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned int nThemes, D2ObjectRegionStrc* pObjectRegion);

static int __stdcall OBJECTS_CanPopulateRoom(D2GameStrc* pGame, D2LevelsTxt* pLevelsTxtRecord, D2ActiveRoomStrc* pRoom);


static int __stdcall OBJECTS_GetShrineId(D2GameStrc* pGame, unsigned int nLevelId, D2ActiveRoomStrc* pRoom, unsigned char nShrineClass);

void __fastcall OBJECTS_InitFunction01_Shrine(D2ObjInitFnStrc* pOp);

static void __cdecl OBJECTS_ApplySubclassClassId(D2UnitStrc* pUnit);

void __stdcall DUNGEON_GetRoomCoordinates_Local(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords);

int __stdcall SKILLS_Return1(int nArg);

int __stdcall sub_00646260_AlwaysOne(int nArg);

int __stdcall sub_00646270_AlwaysOne(int nArg);

int __fastcall SKILLS_GetMinimum(int nA, int nB, int nUnused1, int nUnused2);

int __fastcall MISSILE_GetMinimum(int nA, int nB, int nUnused1, int nUnused2);

int __fastcall SKILLS_GetMaximum(int nA, int nB, int nUnused1, int nUnused2);

int __fastcall MISSILE_GetMaximum(int nA, int nB, int nUnused1, int nUnused2);

int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2);

void __fastcall SKILLS_ScaleUpDirection(int* pX, int* pY);

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline unsigned __int64 ITEMS_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0054F0D0
D2UnitStrc* __fastcall OBJECTS_SpawnShrine(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId < 574 || nClassId > 579)
        return 0;

    const D2ObjectTableStrc* pObjectTableRecord = &gaShrineObjectTable[nClassId - 574];
    D2_ASSERT(hRoom, 222);

    D2UnitStrc* pShrine = SUNIT_AllocUnitData(UNIT_OBJECT, pObjectTableRecord->nObjectId, nX, nY, pGame, hRoom, 1, nMode, 0);

    int nShrineId = ITEMS_RollLimitedRandomNumber(&pShrine->pSeed, pObjectTableRecord->nMax - pObjectTableRecord->nMin) + pObjectTableRecord->nMin;
    if (nShrineId == 5 || nShrineId == 4)
        nShrineId = 2;

    pShrine->pObjectData->InteractType = nShrineId;
    UNITS_SetShrineTxtRecordInObjectData(pShrine, DATATBLS_GetShrinesTxtRecord(nShrineId));
    return pShrine;
}

struct D2ActiveRoomStrc;

struct D2GameStrc;

struct D2SkillStrc;

struct D2UnitStrc;

inline unsigned __int64 RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

// 0x0054F490
D2UnitStrc* __fastcall OBJECTS_SpawnPresetObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode)
{
    if (nClassId <= 573)
    {
        return 0;
    }

    const int nIndex = nClassId - 574;
    if (nIndex >= gnPresetObjectSpawnerCount)
    {
        return 0;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnPresetObjectSpawners[nIndex]), 429);

    return gpfnPresetObjectSpawners[nIndex](pGame, pRoom, nClassId, nX, nY, nMode);
}

inline unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x0054F370
D2UnitStrc* __fastcall OBJECTS_SpawnSpecialChest(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nUnused)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    D2UnitStrc* pObject = OBJECTS_SpawnPresetChest(pGame, pRoom, nLevelId == LEVEL_TOWERCELLARLEV5 ? OBJECT_COUNTESSCHEST : nClassId, nX, nY, nUnused);
    if (pObject)
    {
        if (nLevelId >= LEVEL_MAGGOTLAIRLEV1 && nLevelId <= LEVEL_MAGGOTLAIRLEV3
            && (int)((unsigned int)SEED_RollRandomNumber(&OBJRGN_GetObjectControlFromGame(pGame, pRoom)->pSeed) % 100) > 50)
        {
            pObject->dwFlags |= 0x80;
            UNITS_ChangeAnimMode(pObject, 0);
            return pObject;
        }

        D2GAME_SetSparkChest(pObject, 1);
        if (nLevelId == LEVEL_TOWERCELLARLEV5)
        {
            pObject->pObjectData->InteractType = 3;
        }

        pObject->dwFlags |= 0x80;
        UNITS_ChangeAnimMode(pObject, 0);
    }

    return pObject;
}

// 0x0054F180
D2UnitStrc* __fastcall OBJECTS_SpawnPresetChest(
    D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nClassId, int nX, int nY, int nUnused)
{
    unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(hRoom));
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    int nLevel = DUNGEON_GetLevelIdFromRoom(hRoom);
    int nObject;
    switch (nAct)
    {
    case 1:
        if (nLevel == 0x4A)
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 3;
            int nChoices[] = { 0x183, 0x185, 0x186, 0x187 };
            nObject = nChoices[nIndex];
        }
        else
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 1;
            int nChoices[] = { 0x57, 0x58 };
            nObject = nChoices[nIndex];
        }
        break;
    case 2:
        if (nLevel == 0x53)
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 3;
            int nChoices[] = { 0x149, 0x14A, 0x14B, 0x14C };
            nObject = nChoices[nIndex];
        }
        else
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) & 1;
            int nChoices[] = { 0xB5, 0xB7 };
            nObject = nChoices[nIndex];
        }
        break;
    default:
        {
            unsigned int nIndex = (unsigned int)RollSeedInline(&pControl->pSeed) % 13;
            int nChoices[] = { 5, 6, 0x8B, 0x8C, 0x8D, 0x90, 0xB0, 0xB1, 0xC6, 0xF0, 0xF1, 0xF2, 0xF3 };
            nObject = nChoices[nIndex];
        }
        break;
    }
    if (nClassId == 0x173)
        nObject = 0x173;
    D2_ASSERT(hRoom, 0x157);
    return SUNIT_AllocUnitData(2, nObject, nX, nY, pGame, hRoom, 1, 0, 0);
}

// 0x0054F520
D2TimerArgStrc* __fastcall OBJECTS_AllocTimerArg(D2GameStrc* pGame)
{
    D2TimerArgStrc* pTimerArg = (D2TimerArgStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TimerArgStrc), ".\\OBJECTS\\Objects.cpp", 0x1B8, 0);
    memset(pTimerArg, 0, sizeof(D2TimerArgStrc));
    pTimerArg->dwUnitId = -1;

    D2TimerArg2Strc* pArg = (D2TimerArg2Strc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2TimerArg2Strc), ".\\OBJECTS\\Objects.cpp", 0x1BC, 0);
    pArg->nUnitGUID = -1;
    pArg->pNext = 0;
    pTimerArg->pGUIDList = pArg;
    return pTimerArg;
}

// 0x0054F580
void __fastcall OBJECTS_FreeTimerArg(D2GameStrc* pGame, D2TimerArgStrc* pTimerArg)
{
    D2TimerArg2Strc* pArg = pTimerArg->pGUIDList;
    while (pArg)
    {
        D2TimerArg2Strc* pNext = pArg->pNext;
        FOG_FreePool(pGame->pMemoryPool, pArg, ".\\OBJECTS\\Objects.cpp", 462, 0);
        pArg = pNext;
    }

    FOG_FreePool(pGame->pMemoryPool, pTimerArg, ".\\OBJECTS\\Objects.cpp", 465, 0);
}

// 0x0054F5D0
void __fastcall OBJECTS_InitHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pUnit);

    if (pUnit)
    {
        pUnit->dwUnitId = nUnitGUID;
    }

    D2GAME_SetSparkChest(pUnit, 0);

    int nMode;
    if (pUnit)
    {
        pUnit->dwFlags &= ~8u;
        pUnit->pHoverText = 0;
        nMode = pUnit->dwAnimMode;
    }
    else
    {
        nMode = 0;
    }

    D2_ASSERT(nMode < 8, 0x240);

    if (pObjectsTxtRecord->nIsAttackable0)
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 4u;
        }
    }
    else
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~4u;
        }
    }

    pUnit->pObjectData->InteractType = 0;

    const int wClass = pUnit->dwClassId;
    D2GAME_DeleteTimersOnUnit(pGame, pUnit);
    D2_ASSERT((unsigned short)wClass < 0x23D, 0x260);
    D2_ASSERT(pObjectsTxtRecord->nInitFn < 80, 0x262);

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);

    if (pObjectsTxtRecord->nInitFn < 80 && sgInitTable[pObjectsTxtRecord->nInitFn])
    {
        D2_ASSERT(!IsBadCodePtr((D2FarProcFn)sgInitTable[pObjectsTxtRecord->nInitFn]), 0x26A);

        D2ObjInitFnStrc pOp;
        pOp.pGame = pGame;
        pOp.pObject = pUnit;
        pOp.pRoom = pRoom;
        pOp.pObjectregion = pObjectControl;
        pOp.pObjectTxt = pObjectsTxtRecord;
        pOp.nX = nX;
        pOp.nY = nY;
        sgInitTable[pObjectsTxtRecord->nInitFn](&pOp);
    }

    if (pObjectsTxtRecord->nSelectable[nMode])
    {
        pUnit->dwFlags |= 2u;
    }
    else
    {
        pUnit->dwFlags &= ~2u;
    }

    int bFlag80 = 1;
    if (pObjectsTxtRecord->nAutomap13D)
    {
        bFlag80 = (pUnit->dwFlags & 0x80) != 0;
    }

    if (!bFlag80 && !SEED_RollLimitedRandomNumber(&pObjectControl->pSeed, 14))
    {
        UNITS_ChangeAnimMode(pUnit, 2);
    }

    UNITS_SetTimerArg(pUnit, OBJECTS_AllocTimerArg(pGame));
}

// 0x0054F860
void __fastcall OBJECTS_InitFunction10_Unused(D2ObjInitFnStrc* pOp)
{
    if (DUNGEON_GetLevelIdFromRoom(pOp->pRoom) == LEVEL_ROGUEENCAMPMENT)
    {
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_PERIODICSKILLS, pOp->pGame->dwGameFrame + 60, 0, 0);
    }
    else
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_MODECHANGE, pOp->pGame->dwGameFrame + 25, 0, 0);
    }
}

static inline unsigned int OBJECTS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int OBJECTS_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if (nMax & (nMax - 1))
        return OBJECTS_RollRandomNumberInline(pSeed) % nMax;
    return OBJECTS_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x0054F770
static int __stdcall OBJECTS_GetShrineId(D2GameStrc* pGame, unsigned int nLevelId, D2ActiveRoomStrc* pRoom, unsigned char nShrineClass)
{
    if (!nShrineClass || nShrineClass > 4)
        nShrineClass = 2;
    D2ShrineDataStrc* pShrineData = OBJRGN_GetShrineDataFromGame(pGame);
    if (pShrineData->nShrineSubTypes[nShrineClass])
    {
        int nRetries = 8;
        int nShrineId;
        do
        {
            const int nShrineSubTypes = pShrineData->nShrineSubTypes[nShrineClass];
            D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
            const unsigned int nIndex = OBJECTS_RollLimitedRandomNumberInline(&pObjectControl->pSeed, nShrineSubTypes);
            nShrineId = pShrineData->pShrineSubTypeIds[nShrineClass][nIndex];
            if (!nShrineId)
                nShrineId = 1;
            if (nLevelId >= DATATBLS_GetShrinesTxtRecord(nShrineId)->dwLevelMin)
                break;
            --nRetries;
        } while (nRetries > 0);
        return nShrineId;
    }
    FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),716);
    exit(-1);
}

static inline int OBJECTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        return pUnit->pStaticPath->nXPos;
    if (pUnit->pDynamicPath)
        return PATH_GetXPosition(pUnit->pDynamicPath);
    return 0;
}

static inline int OBJECTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        return pUnit->pStaticPath->nYPos;
    if (pUnit->pDynamicPath)
        return PATH_GetYPosition(pUnit->pDynamicPath);
    return 0;
}

// 0x00552830
void __fastcall OBJECTS_SetObjectPopulateDensity(unsigned char nDensity)
{
    gnObjectPopulateDensity = nDensity;
}

// 0x00552840
void __fastcall OBJECTS_PopulateObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nObjectId)
{
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
        return;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xC7D);
    if (sgPopulateTable[pObjectsTxtRecord->nPopulateFn])
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)sgPopulateTable[pObjectsTxtRecord->nPopulateFn]), 0xC80);
        sgPopulateTable[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, gnObjectPopulateDensity, nObjectId, 100);
    }
}

// 0x00551690
D2UnitStrc* __fastcall OBJECTS_PopulateFn6_RogueGuardCorpse(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nDensity, int nObjectId, int nProbability)
{
    D2UnitStrc* pObject = OBJECTS_PopulateFn3_CommonObjects(pGame, pRoom, nDensity, nObjectId, nProbability);
    if (pObject)
    {
        OBJECTS_SpawnFliesOnCorpse(pGame, pObject);
    }

    return pObject;
}

// 0x00551FF0
int __stdcall OBJECTS_SpawnNothing(int nArg)
{
    return 1;
}

// 0x005523C0
int __fastcall OBJECTS_SpawnArmorStand(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 0);
    return 1;
}

// 0x005523E0
int __fastcall OBJECTS_SpawnWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    OBJECTS_SpawnArmorStandOrWeaponRack(pGame, pRoom, pDrlgCoords, 1);
    return 1;
}

// 0x00552560
static int __stdcall OBJECTS_CanPopulateRoom(D2GameStrc* pGame, D2LevelsTxt* pLevelsTxtRecord, D2ActiveRoomStrc* pRoom)
{
    if (DUNGEON_HasWaypoint(pRoom))
    {
        return 0;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, nLevelId);
    if (!nLevelId)
    {
        return 0;
    }

    if (D2Common_10087(pRoom))
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    if (pObjectRegion->nPopulatedRooms == 0x7FFFFFFF)
    {
        pObjectRegion->nPopulatedRooms = DUNGEON_GetNumberOfPopulatedRoomsInLevel(pGame->pAct[pObjectRegion->nAct], nLevelId);
    }

    pObjectRegion->nProcessedRooms += 1;

    if (pLevelsTxtRecord->dwThemes)
    {
        if (OBJECTS_PopulateRoomTheme(pGame, pRoom, pLevelsTxtRecord->dwThemes, pObjectRegion) == 1)
        {
            return 0;
        }
    }

    return 1;
}

// 0x0054F9D0
void __fastcall OBJECTS_InitFunction01_Shrine(D2ObjInitFnStrc* pOp)
{
    const int nSelection = pOp->pObjectTxt->dwParm[0];
    const unsigned int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    int nShrineId;
    if (nSelection)
    {
        int nShrineClass;
        switch (nSelection)
        {
        case 1: nShrineClass = 2; break;
        case 2: nShrineClass = 3; break;
        default:
            nShrineClass = 4;
            if (!(OBJECTS_RollRandomNumberInline(&pOp->pObjectregion->pSeed) % 10))
                nShrineClass = 1;
            break;
        }
        nShrineId = OBJECTS_GetShrineId(pOp->pGame, nLevelId, pOp->pRoom, (unsigned char)nShrineClass);
    }
    else
    {
        int nRetries = 8;
        const unsigned int nRandomLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
        do
        {
            const int nCount = DATATBLS_GetShrinesTxtRecordCount() - 1;
            nShrineId = OBJECTS_RollLimitedRandomNumberInline(&pOp->pObjectregion->pSeed, nCount) + 1;
            if (nRandomLevelId >= DATATBLS_GetShrinesTxtRecord(nShrineId)->dwLevelMin)
                break;
            --nRetries;
        } while (nRetries > 0);
    }
    if (nShrineId == 5)
        nShrineId = 3;
    else if (nShrineId == 4)
        nShrineId = 2;
    else if (nShrineId == 16)
        nShrineId = 18;
    pOp->pObject->pObjectData->InteractType = (unsigned char)nShrineId;
    UNITS_SetShrineTxtRecordInObjectData(pOp->pObject, DATATBLS_GetShrinesTxtRecord(nShrineId));
}

// 0x0054FB30
void __stdcall sub_0054FB30_Nop()
{
}

// 0x0054FB40
void __fastcall OBJECTS_InitFunction22_Fire(D2ObjInitFnStrc* pOp)
{
    if (pOp->pObjectTxt->nMode[2])
    {
        if (!pOp->pObject || !pOp->pObject->dwAnimMode)
        {
            if (!pOp->pObjectTxt->nMode[0])
            {
                UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
            }
        }
    }

    EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_MODECHANGE, pOp->pGame->dwGameFrame + 25, 0, 0);
}

// 0x0054FB90
void __fastcall OBJECTS_InitFunction24_SpikeFloorTrap(D2ObjInitFnStrc* pOp)
{
    EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_STATREGEN, pOp->pGame->dwGameFrame + 25, 0, 0);
}

// 0x0054FBB0
void __fastcall OBJECTS_InitFunction02_Urn(D2ObjInitFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    unsigned char nInteractType = 0;
    const int nRoll = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 100;
    if (nRoll < (unsigned short)((short)pLevelsTxtRecord->wMonLvl[0] / 8 + 5))
        nInteractType = OBJECTS_RollRandomNumber(&pOp->pObjectregion->pSeed, 1, 9);

    pOp->pObject->pObjectData->InteractType = nInteractType;
}

// 0x0054FC50
void __fastcall OBJECTS_InitFunction27_GooPile(D2ObjInitFnStrc* pOp)
{
    unsigned char nInteractType = 0;
    const int nRoll = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 1000;
    if (nRoll < 333)
        nInteractType = 3;

    pOp->pObject->pObjectData->InteractType = nInteractType;
}

void __stdcall GfxHashDumpStats();

void __stdcall sub_0060AC50_Nop();

// 0x0054FCB0
void __fastcall OBJECTS_InitFunction03_Chest(D2ObjInitFnStrc* pOp)
{
    OBJECTS_InitFunction02_Urn(pOp);
    unsigned char nInteractType = pOp->pObject->pObjectData->InteractType;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(nLevelId);
    if (pOp->pObjectTxt->nLockable)
    {
        const int nRoll = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 100;
        if (nRoll < (short)pLevelsTxtRecord->wMonLvl[0] / 2 + 8)
            nInteractType |= 0x80;
        else
            nInteractType &= 0x7F;
    }
    else
    {
        nInteractType &= 0x7F;
    }
    SEED_InitLowSeed(&pOp->pObject->pSeed, (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 65534 + 1);
    pOp->pObject->pObjectData->InteractType = nInteractType;
}

// 0x00550220
static int __stdcall OBJECTS_CanPlaceObjectWithClearance(D2ActiveRoomStrc* pRoom, int nSizeY, D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, int nSizeX)
{
    if (pDrlgCoords->nSubtileWidth < nSizeX + 2 || pDrlgCoords->nSubtileHeight < nSizeY + 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 1
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 1
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileX - nSizeX + pDrlgCoords->nSubtileWidth - 2
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileY - nSizeY + pDrlgCoords->nSubtileHeight - 2
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 7, nSizeY + 7, 0xC01)
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX, nSizeY, 0x3F11))
    {
        return 1;
    }
    return 0;
}

// 0x005502F0
static int __stdcall OBJECTS_CanPlaceObject(D2DrlgCoordsStrc* pDrlgCoords, D2CoordStrc* pCoord, D2ActiveRoomStrc* pRoom, int nSizeX, int nSizeY)
{
    if (pDrlgCoords->nSubtileWidth < 2 || pDrlgCoords->nSubtileHeight < 2)
    {
        return 0;
    }

    if ((unsigned short)pCoord->nX > pDrlgCoords->nSubtileX + 2
        && (unsigned short)pCoord->nY > pDrlgCoords->nSubtileY + 2
        && (unsigned short)pCoord->nX < pDrlgCoords->nSubtileWidth + pDrlgCoords->nSubtileX - nSizeX
        && (unsigned short)pCoord->nY < pDrlgCoords->nSubtileHeight + pDrlgCoords->nSubtileY - nSizeY
        && !COLLISION_CheckMaskWithSizeXY(pRoom, pCoord->nX, pCoord->nY, nSizeX + 2, nSizeY + 2, 0x3F11))
    {
        return 1;
    }
    return 0;
}

// 0x0054FE70
void __fastcall OBJECTS_InitFunction12_PermanentPortal(D2ObjInitFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pOp->pRoom);
    if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 1);
        UNITS_BlockCollisionPath(pOp->pObject, pOp->pRoom, pOp->nX, pOp->nY);
        EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pOp->pObjectTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    const int nTombLevelId = DUNGEON_GetHoradricStaffTombLevelId(pOp->pGame->pAct[1]);
    switch (nLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        pOp->pObject->pObjectData->InteractType = LEVEL_MOOMOOFARM;
        return;

    case LEVEL_MOOMOOFARM:
        pOp->pObject->pObjectData->InteractType = LEVEL_ROGUEENCAMPMENT;
        return;

    case LEVEL_TRISTRAM:
        pOp->pObject->pObjectData->InteractType = LEVEL_STONYFIELD;
        return;

    case LEVEL_STONYFIELD:
        pOp->pObject->pObjectData->InteractType = LEVEL_TRISTRAM;
        return;

    case LEVEL_ARCANESANCTUARY:
        pOp->pObject->pObjectData->InteractType = LEVEL_CANYONOFTHEMAGI;
        return;

    case LEVEL_CANYONOFTHEMAGI:
        pOp->pObject->pObjectData->InteractType = LEVEL_ARCANESANCTUARY;
        return;

    case LEVEL_DURIELSLAIR:
        pOp->pObject->pObjectData->InteractType = nTombLevelId;
        return;

    case LEVEL_NIHLATHAKSTEMPLE:
        pOp->pObject->pObjectData->InteractType = LEVEL_HARROGATH;
        return;

    case LEVEL_HARROGATH:
        pOp->pObject->pObjectData->InteractType = LEVEL_NIHLATHAKSTEMPLE;
        return;

    case LEVEL_HELL1:
        pOp->pObject->pObjectData->InteractType = LEVEL_FRIGIDHIGHLANDS;
        return;

    case LEVEL_HELL2:
        pOp->pObject->pObjectData->InteractType = LEVEL_ARREATPLATEAU;
        return;

    case LEVEL_HELL3:
        pOp->pObject->pObjectData->InteractType = LEVEL_TUNDRAWASTELANDS;
        return;

    case LEVEL_FRIGIDHIGHLANDS:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL1)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL1;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    case LEVEL_ARREATPLATEAU:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL2)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL2;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    case LEVEL_TUNDRAWASTELANDS:
        if (pOp->pObject->pObjectData->InteractType != LEVEL_HELL3)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_HELL3;
            EVENT_SetEvent(pOp->pGame, pOp->pObject, 11, pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        return;

    default:
        if (nLevelId == nTombLevelId)
        {
            pOp->pObject->pObjectData->InteractType = LEVEL_DURIELSLAIR;
        }
        return;
    }
}

static inline int sub_E03_GetAnimMode(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

// 0x00550140
void __fastcall OBJECTS_InitFunction11_Portal(D2WarpEventArgStrc* pArgs)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pArgs->pRoom));
    const int eLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
    D2_ASSERT(eLevelId <= 0xFF, 0x46F);

    *((unsigned char*)pArgs->pUnit->pPlayerData + 4) = (unsigned char)eLevelId;

    if (sub_E03_GetAnimMode(pArgs->pUnit) == 1)
    {
        UNITS_BlockCollisionPath(pArgs->pUnit, pArgs->pRoom, pArgs->nX, pArgs->nY);
        EVENT_SetEvent(pArgs->pGame, pArgs->pUnit, 1, pArgs->pGame->dwGameFrame + (pArgs->pDelay->dwWarpDelay >> 8) + 1, 0, 0);
    }
}

// 0x005501F0
void __fastcall OBJECTS_InitFunction51_TrappedSoul(D2ObjInitFnStrc* pOp)
{
    if ((pOp->pObject && pOp->pObject->dwAnimMode == OBJMODE_OPENED) || (pOp->pObject && pOp->pObject->dwAnimMode == OBJMODE_OPERATING))
    {
        EVENT_SetEvent(pOp->pGame, pOp->pObject, EVENTTYPE_PERIODICSTATS, pOp->pGame->dwGameFrame + 35, 0, 0);
    }
}

static inline unsigned int OBJECTS_RollSeed_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)nSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    return (unsigned int)nSeed;
}

static inline unsigned int OBJECTS_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    }
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

static inline unsigned int OBJECTS_RollSeedHi_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

static inline unsigned int OBJECTS_RollLimitedHi_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }
    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeedHi_Inline(pSeed) % nMax;
    }
    return OBJECTS_RollSeedHi_Inline(pSeed) & (nMax - 1);
}

// 0x005500C0
void __fastcall OBJECTS_InitFunction08_Torch(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
}

// 0x005500D0
void __fastcall OBJECTS_InitFunction14_Brazier(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
}

// 0x005500E0
void __fastcall OBJECTS_SetOperatingMode(D2ObjInitFnStrc* pOp)
{
    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
}

static inline unsigned int SEED_RollLimitedRandomNumberInl(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return OBJECTS_RollSeedHi_Inline(pSeed) % nMax;
    }

    return OBJECTS_RollSeedHi_Inline(pSeed) & (nMax - 1);
}

int __fastcall sub_0045C3E0_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInl(pSeed, nMax);
}

// 0x00550540
D2UnitStrc* __stdcall OBJECTS_SpawnObjectInRoomWithCheck(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom, int nArg, SPAWNCHECKFN pfnCheck)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    if (tCoords.nSubtileWidth < 2 || tCoords.nSubtileHeight < 2 || tCoords.nSubtileWidth <= nSizeX || tCoords.nSubtileHeight <= nSizeY)
    {
        return 0;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    int nX;
    int nY;
    int i;
    for (i = 0; i < 5; ++i)
    {
        nX = tCoords.nSubtileX + sub_0045C3E0_RollLimitedRandomNumber(pSeed, tCoords.nSubtileWidth - nSizeX - 1);
        nY = tCoords.nSubtileY + sub_0045C3E0_RollLimitedRandomNumber(pSeed, tCoords.nSubtileHeight - nSizeY - 1);
        if (nX && nY
            && (unsigned short)nX >= tCoords.nSubtileX + 1 && (unsigned short)nY >= tCoords.nSubtileY + 1
            && (unsigned short)nX < tCoords.nSubtileX + tCoords.nSubtileWidth - 1 && (unsigned short)nY < tCoords.nSubtileY + tCoords.nSubtileHeight - 1)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)pfnCheck), 0x588);

            if (!COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + 6, nSizeY + 6, 0x3F11) && pfnCheck(pGame, nArg, nX, nY))
            {
                break;
            }
        }
    }

    if (i >= 5)
    {
        return 0;
    }

    D2_ASSERT(pRoom, 0x593);
    return SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}

// 0x0054F8C0
void __fastcall OBJECTS_InitFunction28_GoldPlaceHolder(D2ObjInitFnStrc* pOp)
{
    if (pOp->pObject && pOp->pObject->dwAnimMode != OBJMODE_NEUTRAL)
        return;

    UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    D2CoordStrc pCoord;
    pCoord.nX = pOp->nX;
    pCoord.nY = pOp->nY;

    const int nCounter = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) % 9 + 1;
    for (int i = 0; i < nCounter; ++i)
    {
        const int nOffsetX = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) & 3;
        const int nOffsetY = (unsigned int)ITEMS_RollRandomNumberForceInline(&pOp->pObjectregion->pSeed) & 3;
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(pOp->pRoom, pCoord.nX + nOffsetX, pCoord.nY + nOffsetY);
        if (pRoom == pOp->pRoom)
        {
            pCoord.nX = pOp->nX + nOffsetX;
            pCoord.nY = pOp->nY + nOffsetY;
            if (!COLLISION_CheckMaskWithSizeXY(pRoom, pCoord.nX, pCoord.nY, 1, 1, COLLIDE_MASK_PLACEMENT))
                ITEMS_DropGoldAtCoordinates(pOp->pGame, pOp->pRoom, &pCoord);
        }
    }
}

// 0x005500F0
void __fastcall OBJECTS_InitFunction34_HellBrazierFire(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pOp->pGame, pOp->pRoom);
    if ((unsigned int)ITEMS_RollRandomNumberForceInline(&pObjectControl->pSeed) & 1)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPERATING);
    }
}

// 0x00550130
void __cdecl OBJECTS_InitFunction05_Door()
{
}

static inline int sub_00550A30_IsInsideRoom(D2DrlgCoordsStrc* pCoords, unsigned short nX, unsigned short nY)
{
    return nX >= pCoords->nSubtileX + 1 && nY >= pCoords->nSubtileY + 1
        && nX < pCoords->nSubtileX + pCoords->nSubtileWidth - 1 && nY < pCoords->nSubtileY + pCoords->nSubtileHeight - 1;
}

// 0x00551850
D2UnitStrc* __fastcall OBJECTS_PopulateFn4_Barrel(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(OBJECT_BARREL);
    D2_ASSERT(bDensity <= 128, 0x955);
    int nCount = 0;
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    D2SeedStrc* pSeed = &pControl->pSeed;
    if ((unsigned int)OBJECTS_RollSeedHi_Inline(pSeed) % 100 > nProbability) return 0;
    D2DrlgCoordsStrc bounds;
    DUNGEON_GetRoomCoordinates(hRoom, &bounds);
    int nClusters = ((bounds.nSubtileWidth * bounds.nSubtileHeight >> 7) * bDensity) >> 8;
    int nTries = 2 * nClusters;
    D2UnitStrc* pObject = 0;
    while (nClusters > 0 && nTries > 0)
    {
        int nClassId;
        if (OBJECTS_RollLimitedHi_Inline(pSeed, 3))
            nClassId = 7;
        else
            nClassId = 11;
        D2CoordStrc base;
        base.nX = bounds.nSubtileX + OBJECTS_RollLimitedHi_Inline(pSeed, bounds.nSubtileWidth);
        base.nY = bounds.nSubtileY + OBJECTS_RollLimitedHi_Inline(pSeed, bounds.nSubtileHeight);
        D2CoordStrc coord;
        coord.nX = base.nX;
        coord.nY = base.nY;
        if (OBJECTS_CanPlaceObject(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY) == 1)
        {
            D2_ASSERT(hRoom, 0x98D);
            pObject = SUNIT_AllocUnitData(2, nClassId, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
            int nClusterSize = 1;
            ++nCount;
            if (nCount >= 8) return pObject;
            int bCanPlace = 1;
            pObject = 0;
            while (!OBJECTS_RollLimitedHi_Inline(pSeed, nClusterSize >> 1) && bCanPlace)
            {
                int i = 0;
                bCanPlace = 0;
                while (!bCanPlace)
                {
                    if (i >= 15) break;
                    const unsigned int nDirection = (unsigned int)OBJECTS_RollSeedHi_Inline(pSeed) & 7;
                    base.nX += pObjectsTxt->nXSpacing * gnObjectSpawnOffsetsX[nDirection];
                    base.nY += pObjectsTxt->nYSpacing * gnObjectSpawnOffsetsY[nDirection];
                    coord.nX = base.nX;
                    coord.nY = base.nY;
                    bCanPlace = OBJECTS_CanPlaceObject(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY);
                    ++i;
                }
                if (!bCanPlace) continue;
                int nNextClass;
                if ((unsigned int)OBJECTS_RollSeedHi_Inline(pSeed) & 3)
                    nNextClass = 7;
                else
                    nNextClass = 11;
                pObject = SUNIT_AllocUnitData(2, nNextClass, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
                ++nClusterSize;
                ++nCount;
                if (nCount >= 8) return pObject;
            }
            --nClusters;
        }
        --nTries;
    }
    return pObject;
}

static inline unsigned int RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0) return 0;
    if ((nMax - 1) & nMax) return OBJECTS_RollSeed_Inline(pSeed) % nMax;
    return OBJECTS_RollSeed_Inline(pSeed) & (nMax - 1);
}

// 0x00551200
D2UnitStrc* __fastcall OBJECTS_PopulateFn7_RogueOnStick(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    if (OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) % 100 > nProbability)
    {
        return 0;
    }

    const int nIndex = ITEMS_RollLimitedRandomNumber(&pObjectControl->pSeed, gnCoordInitCount);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    const int nSizeX = pObjectsTxtRecord->dwSizeX;
    const int nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(hRoom, &drlgCoords);

    int nTries = 8;
    D2UnitStrc* pObject = 0;
    D2CoordStrc base;
    while (1)
    {
        base.nX = drlgCoords.nSubtileX + OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileWidth - nSizeX - 1);
        base.nY = drlgCoords.nSubtileY + OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileHeight - nSizeY - 1);
        if (OBJECTS_CanPlaceObjectWithClearance(hRoom, 5, &drlgCoords, &base, 5) == 1)
        {
            break;
        }

        --nTries;
        if (nTries <= 0)
        {
            return 0;
        }
    }

    for (int j = 0; j < gaCoordInit[nIndex].nCount; ++j)
    {
        D2CoordStrc coord;
        coord.nX = base.nX + gaCoordInit[nIndex].pCoords[j].nX;
        coord.nY = base.nY + gaCoordInit[nIndex].pCoords[j].nY;
        if (OBJECTS_CanPlaceObjectWithClearance(hRoom, nSizeY, &drlgCoords, &coord, nSizeX) == 1)
        {
            const unsigned int nClassId = (OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 1) + 0x39;
            D2_ASSERT(nClassId <= 0x3A, 0x7DD);
            D2_ASSERT(hRoom, 0x7DE);
            pObject = SUNIT_AllocUnitData(2, nClassId, coord.nX, coord.nY, pGame, hRoom, 1, 0, 0);
            if (pObject)
            {
                OBJECTS_SpawnFliesOnCorpse(pGame, pObject);
            }
        }
    }

    return pObject;
}

// 0x00551580
D2UnitStrc* __fastcall OBJECTS_PopulateFn9_TrappedSoul(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2_ASSERT(bDensity <= 128, 0x893);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    int nSizeY;
    int nSizeX;
    nSizeX = pObjectsTxtRecord->dwSizeX;
    nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    D2SeedStrc* pSeed;
    if (pRoom)
    {
        pSeed = &pRoom->pSeed;
    }
    else
    {
        pSeed = 0;
    }
    if (OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability)
    {
        return 0;
    }
    const int nMax = bDensity * (drlgCoords.nSubtileWidth * drlgCoords.nSubtileHeight >> 7) >> 8;
    for (int i = nMax; i > 0; --i)
    {
        D2UnitStrc* pObject = OBJECTS_CreateObject(pGame, nObjectId, nSizeX, nSizeY, pRoom);
        if (pObject)
        {
            if (pObjectsTxtRecord->nSelectable[pObject->dwAnimMode])
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
            return pObject;
        }
    }
    return 0;
}

// 0x005506D0
void __fastcall OBJECTS_InitFunction46_TrappedSoulPlaceHolder(D2ObjInitFnStrc* op)
{
    if(op->pObject && op->pObject->dwAnimMode) return;
    D2DrlgCoordsStrc room;
    DUNGEON_GetRoomCoordinates(op->pRoom,&room);
    D2ObjectControlStrc* control=OBJRGN_GetObjectControlFromGame(op->pGame,op->pRoom);
    int nTries=12;
    int count=30*((room.nSubtileWidth*room.nSubtileHeight)>>7)>>8;
    int distance=5;
    while(count>0) {
        if(nTries<=0) break;
        D2CoordStrc xy;
        xy.nX=room.nSubtileX+OBJECTS_RollLimited_Inline(&control->pSeed,room.nSubtileWidth-4);
        xy.nY=room.nSubtileY+OBJECTS_RollLimited_Inline(&control->pSeed,room.nSubtileHeight-4);
        D2CoordStrc coord;coord.nX=xy.nX;coord.nY=xy.nY;
        if(OBJECTS_CanPlaceObjectWithClearance(op->pRoom,3,&room,&coord,3)==1) {
            unsigned int random=OBJECTS_RollSeedHi_Inline((D2SeedStrc*)op->pObjectregion);
            int monsterId=403;
            if(random&1) monsterId=404;
            if(D2GAME_SpawnMonster(op->pGame,op->pRoom,op->nX,op->nY,monsterId,1,-1,0)) {
                UNITS_ChangeAnimMode(op->pObject,2);--count;
            }
            int spawned=1;
            int placed=1;
            while(!OBJECTS_RollLimited_Inline(&control->pSeed,spawned>>1) && placed) {
                int tries=0;
                placed=0;
                int maximum=3*(count<4 ? 4 : count);
                while(!placed) {
                    if(tries>=maximum) break;
                    int direction=OBJECTS_RollLimited_Inline(&control->pSeed,8);
                    xy.nX+=2*(OBJECTS_RollLimited_Inline(&control->pSeed,distance)+distance)*gaDirectionX_00731B7C[direction];
                    xy.nY+=2*(OBJECTS_RollLimited_Inline(&control->pSeed,distance)+distance)*gaDirectionY_00731B9C[direction];
                    coord.nX=xy.nX;coord.nY=xy.nY;
                    placed=OBJECTS_CanPlaceObjectWithClearance(op->pRoom,3,&room,&coord,3);
                    ++tries;
                }
                if(placed) {
                    unsigned int random=OBJECTS_RollSeedHi_Inline((D2SeedStrc*)op->pObjectregion);
                    int monsterId=403;
                    if(random&1) monsterId=404;
                    ++spawned;
                    if(D2GAME_SpawnMonster(op->pGame,op->pRoom,xy.nX,xy.nY,monsterId,1,-1,0)) {
                        UNITS_ChangeAnimMode(op->pObject,2);--count;
                    }
                }
            }
        }
        --nTries;
    }
}

static inline int OBJECTS_RollChance_Inline(D2SeedStrc* pSeed, unsigned short nProbability)
{
    if (OBJECTS_RollSeed_Inline(pSeed) % 100 > nProbability)
    {
        return 0;
    }

    return 1;
}

// 0x00551470
D2UnitStrc* __fastcall OBJECTS_PopulateFn3_CommonObjects(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2_ASSERT(bDensity <= 128, 0x864);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    int nSizeY;
    int nSizeX;
    nSizeX = pObjectsTxtRecord->dwSizeX;
    nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
    if (!OBJECTS_RollChance_Inline(&pObjectControl->pSeed, nProbability))
    {
        return 0;
    }
    int nCount = bDensity * (drlgCoords.nSubtileWidth * drlgCoords.nSubtileHeight >> 7) >> 8;
    D2UnitStrc* pObject = 0;
    for (; nCount > 0; --nCount)
    {
        pObject = OBJECTS_CreateObject(pGame, nObjectId, nSizeX, nSizeY, pRoom);
        if (pObject)
        {
            if (pObjectsTxtRecord->nSelectable[pObject->dwAnimMode])
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
        }
    }
    return pObject;
}

// 0x00550380
D2UnitStrc* __stdcall OBJECTS_CreateObject(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* hRoom)
{
    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(hRoom, &drlgCoords);

    if (drlgCoords.nSubtileWidth < ROOM_MIN_SUBTILES || drlgCoords.nSubtileHeight < ROOM_MIN_SUBTILES)
    {
        return 0;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    int nX;
    int nY;
    int i;
    for (i = 0; i < CREATE_TRIES; ++i)
    {
        nX = OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileWidth - nSizeX - 1) + drlgCoords.nSubtileX;
        nY = OBJECTS_RollLimited_Inline(&pObjectControl->pSeed, drlgCoords.nSubtileHeight - nSizeY - 1) + drlgCoords.nSubtileY;
        if (nX && nY && (unsigned short)nX >= drlgCoords.nSubtileX + 1 && (unsigned short)nY >= drlgCoords.nSubtileY + 1
            && (unsigned short)nX < drlgCoords.nSubtileX + drlgCoords.nSubtileWidth - 1 && (unsigned short)nY < drlgCoords.nSubtileY + drlgCoords.nSubtileHeight - 1
            && !COLLISION_CheckMaskWithSizeXY(hRoom, nX, nY, nSizeX + CREATE_SIZE_GROW, nSizeY + CREATE_SIZE_GROW, COLLIDE_MASK_PLACEMENT))
        {
            break;
        }
    }

    if (i >= CREATE_TRIES)
    {
        return 0;
    }

    D2_ASSERT(hRoom, LINE_CREATE_ROOM);
    return SUNIT_AllocUnitData(UNIT_OBJECT, nClassId, nX, nY, pGame, hRoom, 1, 0, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static __forceinline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static __forceinline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

inline D2PlayerListStrc* PLAYERLIST_FindPlayerList(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
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

// 0x005528E0
void __fastcall OBJECTS_PopulateObjectGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nObjGroup)
{
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
    {
        return;
    }

    D2ObjGroupTxt* pObjGroupTxtRecord = DATATBLS_GetObjGroupTxtRecord(nObjGroup);
    D2SeedStrc* pSeed = &OBJRGN_GetObjectControlFromGame(pGame, pRoom)->pSeed;
    if (!pObjGroupTxtRecord)
    {
        return;
    }

    const unsigned __int64 nValue = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(nValue >> 32);
    pSeed->nLowSeed = (unsigned int)nValue;
    const int nProbability = (int)((unsigned int)nValue % 100);

    int nAccumulatedProbability = 0;
    for (int i = 0; i < 8; ++i)
    {
        const int nObjectId = pObjGroupTxtRecord->dwId[i];
        if (!nObjectId)
        {
            return;
        }

        nAccumulatedProbability += pObjGroupTxtRecord->nProbability[i];
        if (nProbability < nAccumulatedProbability)
        {
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
            D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xCA8);
            if (!sgPopulateTable[pObjectsTxtRecord->nPopulateFn])
            {
                return;
            }
            D2_ASSERT(!IsBadCodePtr((FARPROC)sgPopulateTable[pObjectsTxtRecord->nPopulateFn]), 0xCAB);
            D2_ASSERT(pObjGroupTxtRecord->nDensity[i] < 0x80, 0xCAC);
            sgPopulateTable[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, pObjGroupTxtRecord->nDensity[i], nObjectId, 100);
            return;
        }
    }
}

// 0x005516C0
D2UnitStrc* __fastcall OBJECTS_PopulateFn8_Well(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nWellType, int nObjectId, unsigned short nChance)
{
    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    if (OBJRGN_CanNotSpawnMoreWells(pGame, nLevelId))
    {
        return 0;
    }

    D2_ASSERT(nWellType <= 128, 0x8D0);

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    const int nSizeX = pObjectsTxtRecord->dwSizeX;
    const int nSizeY = pObjectsTxtRecord->dwSizeY;

    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    if (OBJECTS_RollSeedHi_Inline(pSeed) % 100 > nChance)
    {
        return 0;
    }

    D2UnitStrc* pUnit = sub_00550540_SpawnObjectInBox(pGame, nObjectId, 2 * nSizeX + 1, 2 * nSizeY + 1, pRoom, nLevelId, OBJRGN_CanSpawnWell);
    if (pUnit)
    {
        const int nMode = pUnit ? pUnit->dwAnimMode : 0;
        if (pObjectsTxtRecord->nSelectable[nMode])
        {
            pUnit->dwFlags |= 2;
        }
        else
        {
            pUnit->dwFlags &= ~2;
        }

        OBJRGN_SetWellCoordinates(pGame, nLevelId, UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit));
    }

    return pUnit;
}

// 0x00552000
int __fastcall OBJECTS_SpawnBarrel(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    const unsigned int nXEnd = pDrlgCoords->nSubtileWidth + pDrlgCoords->nSubtileX + 1;
    const unsigned int nYEnd = pDrlgCoords->nSubtileHeight + pDrlgCoords->nSubtileY + 1;
    int nCounter = 0;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(OBJECT_BARREL);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    D2CoordStrc coord;

    int nClassId;

    for (unsigned int nX = pDrlgCoords->nSubtileX; nX < nXEnd; nX += 2)
    {
        unsigned int nY = pDrlgCoords->nSubtileY;
        if (nY < nYEnd)
        {
            coord.nX = nX;
            do
            {
                const unsigned __int64 nSeed = (unsigned __int64)pObjectControl->pSeed.nLowSeed * 0x6AC690C5 + pObjectControl->pSeed.nHighSeed;
                pObjectControl->pSeed.nLowSeed = (unsigned int)nSeed;
                pObjectControl->pSeed.nHighSeed = (unsigned int)(nSeed >> 32);
                if ((unsigned int)nSeed & 3)
                {
                    nClassId = 7;
                }
                else
                {
                    nClassId = 11;
                }
                coord.nY = nY;
                if (OBJECTS_CanPlaceObject(pDrlgCoords, &coord, hRoom, pObjectsTxtRecord->dwSizeX, pObjectsTxtRecord->dwSizeY) == 1)
                {
                    D2_ASSERT(hRoom, 2696);
                    SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, hRoom, 1, 0, 0);
                    ++nCounter;
                    if (nCounter >= 32)
                    {
                        return 1;
                    }
                }
                nY += 2;
            }
            while (nY < nYEnd);
        }
    }

    return 1;
}

static __forceinline unsigned int OBJECTS_RollObjectIndex_Inline(D2SeedStrc* pSeed)
{
    if (gnUrnClusterIdCount <= 0) return 0;
    if ((gnUrnClusterIdCount - 1) & gnUrnClusterIdCount) return (unsigned int)OBJECTS_RollSeedHi_Inline(pSeed) % gnUrnClusterIdCount;
    return (unsigned int)OBJECTS_RollSeedHi_Inline(pSeed) & (gnUrnClusterIdCount - 1);
}

// 0x00551C00
D2UnitStrc* __fastcall OBJECTS_PopulateFn5_Crate(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, unsigned char bDensity, unsigned int nObjectId, unsigned short nProbability)
{
    D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nObjectId);
    D2_ASSERT(bDensity <= 128, 0x9D7);
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    D2SeedStrc* pSeed = &pControl->pSeed;
    if ((unsigned int)OBJECTS_RollSeedHi_Inline(pSeed) % 100 > nProbability) return 0;
    int nCount = 0;
    D2DrlgCoordsStrc bounds;
    DUNGEON_GetRoomCoordinates(hRoom, &bounds);
    int nClusters = ((bounds.nSubtileWidth * bounds.nSubtileHeight >> 7) * bDensity) >> 8;
    int nTries = 2 * nClusters;
    D2UnitStrc* pObject = 0;
    if (nClusters > 0)
    {
        int nLimit = 4 * nClusters;
        int bDone = 0;
        while (!bDone)
        {
            if (nTries <= 0)
                break;
        int nClassId = nObjectId;
        if (nObjectId != OBJECT_CRATE)
            nClassId = gnUrnClusterIds[OBJECTS_RollObjectIndex_Inline(pSeed)];
        D2CoordStrc base;
        base.nX = bounds.nSubtileX + OBJECTS_RollLimitedHi_Inline(pSeed, bounds.nSubtileWidth);
        base.nY = bounds.nSubtileY + OBJECTS_RollLimitedHi_Inline(pSeed, bounds.nSubtileHeight);
        D2CoordStrc coord;
        coord.nX = base.nX;
        coord.nY = base.nY;
        if (OBJECTS_CanPlaceObject(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY) == 1)
        {
            if (nClassId != 46)
                nClassId = gnUrnClusterIds[ITEMS_RollLimitedRandomNumber(pSeed, gnUrnClusterIdCount)];
            D2_ASSERT(hRoom, 0xA06);
            SUNIT_AllocUnitData(2, nClassId, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
            int nClusterSize = 1;
            int bCanPlace = 1;
            pObject = 0;
            while (!OBJECTS_RollLimitedHi_Inline(pSeed, nClusterSize >> 1) && bCanPlace)
            {
                int i = 0;
                bCanPlace = 0;
                int nMax = 4;
                if (nLimit >= 4) nMax = nLimit;
                while (!bCanPlace)
                {
                    if (i >= nMax) break;
                    const unsigned int nDirection = (unsigned int)OBJECTS_RollSeedHi_Inline(pSeed) & 7;
                    base.nX += pObjectsTxt->nXSpacing * gnObjectSpawnOffsetsX[nDirection];
                    base.nY += pObjectsTxt->nYSpacing * gnObjectSpawnOffsetsY[nDirection];
                    coord.nX = base.nX;
                    coord.nY = base.nY;
                    bCanPlace = OBJECTS_CanPlaceObject(&bounds, &coord, hRoom, pObjectsTxt->dwSizeX, pObjectsTxt->dwSizeY);
                    ++i;
                }
                if (!bCanPlace) continue;
                pObject = SUNIT_AllocUnitData(2, nClassId, base.nX, base.nY, pGame, hRoom, 1, 0, 0);
                if (pObject)
                {
                    ++nCount;
                    if (nCount >= 8) return pObject;
                }
                ++nClusterSize;
            }
            --nClusters;
            nLimit -= 4;
        }
            --nTries;
            if (nClusters <= 0)
                bDone = 1;
        }
    }
    return pObject;
}

int __stdcall sub_00436E90_AlwaysOne(int nArg);

int __stdcall sub_004C6020_AlwaysOne(int nArg);

// 0x00552140
int __fastcall OBJECTS_SpawnRandomItemGrid(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pDrlgCoords)
{
    const unsigned int nXEnd = pDrlgCoords->nSubtileX + (pDrlgCoords->nSubtileWidth > 12 ? 12 : pDrlgCoords->nSubtileWidth);
    const unsigned int nYEnd = pDrlgCoords->nSubtileY + (pDrlgCoords->nSubtileHeight > 12 ? 12 : pDrlgCoords->nSubtileHeight);
    int nCounter = 0;

    for (unsigned int nX = pDrlgCoords->nSubtileX + 1; nX < nXEnd; nX += 2)
    {
        for (unsigned int nY = pDrlgCoords->nSubtileY + 1; nY < nYEnd; nY += 2)
        {
            D2CoordStrc coord;
            coord.nX = nX;
            coord.nY = nY;
            if (OBJECTS_CanPlaceObject(pDrlgCoords, &coord, pRoom, 1, 1) == 1)
            {
                ITEMS_DropRandomItemAtCoordinates(pGame, pRoom, &coord, 0);
                ++nCounter;
                if (nCounter >= 32)
                {
                    return 1;
                }
            }
        }
    }

    return 1;
}

// 0x00552200
static void __stdcall OBJECTS_SpawnArmorStandOrWeaponRack(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, D2DrlgCoordsStrc* pDrlgCoords, int bWeaponRack)
{
    if (bWeaponRack >= gnArmorStandOrRackCount)
    {
        return;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    const int nRand = OBJECTS_RollSeed_Inline(&pObjectControl->pSeed) & 1;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(gnArmorStandOrRackIds[nRand + 2 * bWeaponRack]);
    const unsigned int nXEnd = pDrlgCoords->nSubtileWidth - pObjectsTxtRecord->dwSizeX + pDrlgCoords->nSubtileX;
    const unsigned int nYEnd = pDrlgCoords->nSubtileHeight - pObjectsTxtRecord->dwSizeY + pDrlgCoords->nSubtileY;
    D2CoordStrc coord;

    if (nRand == 0)
    {
        const int nY = pDrlgCoords->nSubtileY + 1;
        unsigned int nX = pDrlgCoords->nSubtileX + pObjectsTxtRecord->dwSizeX;
        for (; nX < nXEnd; nX += 2 * pObjectsTxtRecord->dwSizeX)
        {
            coord.nY = nY;
            coord.nX = nX;
            if (OBJECTS_CanPlaceObjectWithClearance(hRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
            {
                D2_ASSERT(hRoom, 2834);
                SUNIT_AllocUnitData(2, gnArmorStandOrRackIds[nRand + 2 * bWeaponRack], nX, nY, pGame, hRoom, 1, 0, 0);
            }
        }
    }
    else
    {
        const int nX = pDrlgCoords->nSubtileX + 1;
        unsigned int nY = pDrlgCoords->nSubtileY + pObjectsTxtRecord->dwSizeY;
        for (; nY < nYEnd; nY += 2 * pObjectsTxtRecord->dwSizeY)
        {
            coord.nX = nX;
            coord.nY = nY;
            if (OBJECTS_CanPlaceObjectWithClearance(hRoom, pObjectsTxtRecord->dwSizeY, pDrlgCoords, &coord, pObjectsTxtRecord->dwSizeX) == 1)
            {
                D2_ASSERT(hRoom, 2853);
                SUNIT_AllocUnitData(2, gnArmorStandOrRackIds[nRand + 2 * bWeaponRack], nX, nY, pGame, hRoom, 1, 0, 0);
            }
        }
    }
}

// 0x00619730
void __stdcall DUNGEON_GetRoomCoordinates_Local(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords)
{
    D2_ASSERT(pCoords, 209);

    if (!pRoom)
    {
        memset(pCoords, 0x00, sizeof(D2DrlgCoordsStrc));
        return;
    }

    memcpy(pCoords, &pRoom->tCoords, sizeof(D2DrlgCoordsStrc));
}

// 0x00550A30
D2UnitStrc* __stdcall OBJECTS_SpawnObjectInRoomWithCallback(D2GameStrc* pGame, int nClassId, int nSizeX, int nSizeY, D2ActiveRoomStrc* pRoom, int nMode, int nArg, D2ObjectSpawnCallback pfnCallback)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates_Local(pRoom, &tCoords);

    int nWidth = tCoords.nSubtileWidth;
    int nHeight = tCoords.nSubtileHeight;
    if (nWidth < nSizeX + 2 || nHeight < nSizeY + 2)
    {
        return 0;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    int nX;
    int nY;
    int i;
    for (i = 0; i < 5; ++i)
    {
        nWidth = tCoords.nSubtileWidth;
        nHeight = tCoords.nSubtileHeight;
        switch (nMode)
        {
        case 1:
            nX = tCoords.nSubtileX + ITEMS_RollLimitedRandomNumber(pSeed, nWidth / 2) + nWidth / 4;
            nY = tCoords.nSubtileY + OBJECTS_RollRandomNumber(pSeed, 1, 2);
            break;

        case 2:
            nX = tCoords.nSubtileX + OBJECTS_RollRandomNumber(pSeed, 1, 2);
            nY = tCoords.nSubtileY + ITEMS_RollLimitedRandomNumber(pSeed, nHeight / 2) + nHeight / 4;
            break;

        default:
            nX = tCoords.nSubtileX + ITEMS_RollLimitedRandomNumber(pSeed, nWidth - nSizeX - 1);
            nY = tCoords.nSubtileY + ITEMS_RollLimitedRandomNumber(pSeed, nHeight - nSizeY - 1);
            break;
        }

        if (nX && nY && sub_00550A30_IsInsideRoom(&tCoords, nX, nY))
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)pfnCallback), 0x634);

            if (!COLLISION_CheckMaskWithSizeXY(pRoom, nX, nY, nSizeX + 6, nSizeY + 6, 0x3F11))
            {
                if (pfnCallback(pGame, nArg, nX, nY))
                {
                    break;
                }
            }
        }
    }

    if (i >= 5)
    {
        return 0;
    }

    D2_ASSERT(pRoom, 0x64D);
    return SUNIT_AllocUnitData(2, nClassId, nX, nY, pGame, pRoom, 1, 0, 0);
}

// 0x00550C20
D2UnitStrc* __fastcall OBJECTS_PopulateFn1_CasketJarSarcophagusUrn(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, unsigned char nDensity, int nObjectId, unsigned short nProbability)
{
    D2CoordStrc position;
    D2ObjectsTxt* pRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    int nSizeX = pRecord->dwSizeX;
    int nSizeY = pRecord->dwSizeY;
    D2DrlgCoordsStrc roomCoords;
    DUNGEON_GetRoomCoordinates(hRoom, &roomCoords);
    D2ObjectControlStrc* pControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    if (OBJECTS_RollSeedHi_Inline(&pControl->pSeed) % 100 > nProbability) return 0;
    int nTries = 12;
    bool bSmall = false;
    int* pIds;
    int nRange, nBase;
    if (nObjectId == OBJECT_CASKET6) {
        pIds = gnCasket6ClusterIds; nObjectId = gnCasket6ClusterIdCount; nTries = 18; nRange = 5; nBase = 5;
    } else if (nObjectId == OBJECT_CASKET3 || nObjectId == OBJECT_CASKET5) {
        pIds = gnCasketClusterIds; nObjectId = gnCasketClusterIdCount; nRange = 5; nBase = 5;
    } else if (nObjectId == OBJECT_URN1) {
        pIds = gnUrnClusterIds; nObjectId = gnUrnClusterIdCount; nRange = 0; nBase = 1; bSmall = true;
    } else if (nObjectId == OBJECT_MUMMY_COFFIN_LEFT) {
        pIds = gnMummyCoffinClusterIds; nObjectId = gnMummyCoffinClusterIdCount; nRange = 5; nBase = 5;
    } else if (nObjectId == OBJECT_BASKET1 || nObjectId == OBJECT_BASKET2) {
        pIds = gnBasketClusterIds; nObjectId = gnBasketClusterIdCount; nRange = 0; nBase = 1; bSmall = true;
    } else return 0;
    int nClusters = ((roomCoords.nSubtileWidth * roomCoords.nSubtileHeight >> 7) * nDensity) >> 8;
    D2UnitStrc* pResult = 0;
    while (nClusters > 0) {
        if (nTries <= 0) break;
        int nClassId = pIds[RollLimited(&pControl->pSeed, nObjectId)];
        position.nX = roomCoords.nSubtileX + RollLimited(&pControl->pSeed, roomCoords.nSubtileWidth - nSizeX - 1);
        position.nY = roomCoords.nSubtileY + RollLimited(&pControl->pSeed, roomCoords.nSubtileHeight - nSizeY - 1);
        D2CoordStrc coord;
        coord.nX = position.nX; coord.nY = position.nY;
        if (OBJECTS_CanPlaceObjectWithClearance(hRoom, pRecord->dwSizeY, &roomCoords, &coord, pRecord->dwSizeX) == 1) {
            D2_ASSERT(hRoom, 0x714);
            SUNIT_AllocUnitData(2, nClassId, position.nX, position.nY, pGame, hRoom, 1, 0, 0);
            int nClusterTries = 1;
            int bSuccess = 1;
            pResult = 0;
            while (!RollLimited(&pControl->pSeed, nClusterTries >> 1) && bSuccess) {
                int i = 0;
                bSuccess = 0;
                int nLimit = 3 * (nClusters < 4 ? 4 : nClusters);
                while (!bSuccess) {
                    if (i >= nLimit) break;
                    nClassId = OBJECTS_RollSeedHi_Inline(&pControl->pSeed) & 7;
                    position.nX += 2 * gnObjectSpawnOffsetsX[nClassId] * (nBase + RollLimited(&pControl->pSeed, nRange));
                    position.nY += 2 * gnObjectSpawnOffsetsY[nClassId] * (nBase + RollLimited(&pControl->pSeed, nRange));
                    coord.nX = position.nX; coord.nY = position.nY;
                    if (bSmall) bSuccess = OBJECTS_CanPlaceObject(&roomCoords, &coord, hRoom, pRecord->dwSizeX, pRecord->dwSizeY);
                    else bSuccess = OBJECTS_CanPlaceObjectWithClearance(hRoom, pRecord->dwSizeY, &roomCoords, &coord, pRecord->dwSizeX);
                    ++i;

                }
                if (bSuccess) {
                    nClassId = pIds[RollLimited(&pControl->pSeed, nObjectId)];
                    pResult = SUNIT_AllocUnitData(2, nClassId, position.nX, position.nY, pGame, hRoom, 1, 0, 0);
                    ++nClusterTries;
                }
            }
            --nClusters;
        }
        --nTries;
    }
    return pResult;
}

// 0x00551150
void __stdcall OBJECTS_SpawnFliesOnCorpse(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pObject);
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, hRoom);
    if ((unsigned int)ITEMS_RollRandomNumberInline(&pObjectControl->pSeed) % 100 <= 70)
        return;

    D2CoordStrc tCoord;
    UNITS_GetCoords(pObject, &tCoord);
    D2_ASSERT(hRoom, 1946);
    SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FLIES, tCoord.nX, tCoord.nY, pGame, hRoom, 1, 0, 0);
}


static inline unsigned int OBJPOP_RollSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline int OBJPOP_RollLimited_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
    {
        return OBJPOP_RollSeed_Inline(pSeed) % nMax;
    }

    return OBJPOP_RollSeed_Inline(pSeed) & (nMax - 1);
}

// 0x00552610
void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord, 0xBEC);

    if (!OBJECTS_CanPopulateRoom(pGame, pLevelsTxtRecord, pRoom))
    {
        return;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    for (int i = 0; i < 8; ++i)
    {
        const int nObjGroup = pLevelsTxtRecord->nObjGroup[i];
        int nProbability = OBJPOP_RollSeed_Inline(pSeed) % 100;

        D2ObjectRegionStrc* pObjectRegion = OBJRGN_GetObjectRegionForLevel(pGame, DUNGEON_GetLevelIdFromPopulatedRoom(pRoom));
        if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->nProcessedRooms << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines
            && DATATBLS_GetObjectsTxtRecord(nObjGroup)->nSubClass)
        {
            nProbability = 100;
        }

        if (nObjGroup && nProbability <= pLevelsTxtRecord->nObjPrb[i])
        {
            D2ObjGroupTxt* pObjGroupTxtRecord = DATATBLS_GetObjGroupTxtRecord(nObjGroup);
            if (!pObjGroupTxtRecord)
            {
                return;
            }

            const int nRoll = OBJPOP_RollSeed_Inline(pSeed) % 100;
            int nAccumulatedProbability = 0;
            for (int j = 0; j < 8; ++j)
            {
                const unsigned int nObjectId = pObjGroupTxtRecord->dwId[j];
                if (!nObjectId)
                {
                    break;
                }

                nAccumulatedProbability += pObjGroupTxtRecord->nProbability[j];
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
                if (nRoll < nAccumulatedProbability && pObjectsTxtRecord->nGore <= gnObjectGoreLevel)
                {
                    D2_ASSERT(pObjectsTxtRecord->nPopulateFn < 10, 0xC43);
                    if (sgPopulateTable[pObjectsTxtRecord->nPopulateFn])
                    {
                        D2_ASSERT(!IsBadCodePtr((FARPROC)sgPopulateTable[pObjectsTxtRecord->nPopulateFn]), 0xC46);
                        D2_ASSERT(pObjGroupTxtRecord->nDensity[j] < 128, 0xC47);
                        sgPopulateTable[pObjectsTxtRecord->nPopulateFn](pGame, pRoom, pObjGroupTxtRecord->nDensity[j], nObjectId, 100);
                    }
                    break;
                }
            }
        }
    }
}

// 0x00552400
static int __stdcall OBJECTS_PopulateRoomTheme(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned int nThemes, D2ObjectRegionStrc* pObjectRegion)
{
    if (pObjectRegion->nPopulatedRooms >= 10 * pObjectRegion->nThemedRooms)
    {
        D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, pRoom);
        const int nRoll = OBJPOP_RollSeed_Inline(&pObjectControl->pSeed) % 100;

        int nProbability = 0;
        if (pObjectRegion->nProcessedRooms > pObjectRegion->nPopulatedRooms / 2)
        {
            nProbability = 5;
        }

        if (pObjectRegion->nProcessedRooms > pObjectRegion->nPopulatedRooms - pObjectRegion->nPopulatedRooms / 4)
        {
            nProbability += 5;
        }

        if (nRoll >= nProbability + 12)
        {
            return 0;
        }

        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

        unsigned int nThemeBit = 1;
        int nIndices[7] = {};
        int nMax = 0;
        int nTheme = 1;
        int nCount = 7;
        do
        {
            if (nThemes & nThemeBit)
            {
                nIndices[nMax] = nTheme;
                ++nMax;
            }
            nThemeBit += nThemeBit;
            ++nTheme;
        }
        while (--nCount);

        const int nIndex = OBJPOP_RollLimited_Inline(&pObjectControl->pSeed, nMax);
        const int nThemeId = nIndices[nIndex];
        if (nIndex < nMax && nThemeId < nMax && gaObjectThemeTable[nThemeId].bActive && gaObjectThemeTable[nThemeId].pfPopulate)
        {
            return gaObjectThemeTable[nThemeId].pfPopulate(pGame, pRoom, &drlgCoords);
        }

        return 0;
    }

    return 0;
}

// 0x0054FD90
void __fastcall OBJECTS_InitFunction57_SparklyChest(D2ObjInitFnStrc* pOp)
{
    OBJECTS_InitFunction03_Chest(pOp);
    D2GAME_SetSparkChest(pOp->pObject, 1);
}

bool R00601DC0::sub_00601DC0_IsOpen()
{
    return m_pFile != 0;
}

// 0x0054FDB0
void __fastcall OBJECTS_InitFunction58_Fissure(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pOp->pGame, pOp->pRoom);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 8, pOp->pGame->dwGameFrame + (unsigned int)ITEMS_RollRandomNumberForceInline(&pObjectControl->pSeed) % 250 + 25, 0, 0);
}

// 0x0054FE10
void __fastcall OBJECTS_InitFunction59_VileDogAfterglow(D2ObjInitFnStrc* pOp)
{
    if (pOp->pObject && pOp->pObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        return;
    }

    UNITS_ChangeAnimMode(pOp->pObject, 1);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 7, pOp->pGame->dwGameFrame + 27, 0, 0);
    EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, (pOp->pObjectTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
}

// 0x0054F430
D2UnitStrc* __fastcall OBJECTS_SpawnArcaneSymbol(D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nClassId, int nX, int nY, int nMode)
{
    const int nObjectId = ACT2Q6_GetObjectIdForArcaneThing(pGame);

    D2_ASSERT(hRoom, 391);

    return SUNIT_AllocUnitData(UNIT_OBJECT, nObjectId, nX, nY, pGame, hRoom, 1, 0, 0);
}

// 0x00552A00
void __fastcall OBJECTS_FreeHoverMessage(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && pObject->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pObject->pHoverText);
    }

    OBJECTS_FreeTimerArg(pGame, UNITS_GetTimerArg(pObject));
    EVENT_FreeUnitTimers(pGame, pObject);
}

// 0x00552A40
void __fastcall OBJECTS_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < UNIT_LIST_SIZE; ++i)
    {
        D2UnitStrc* pObject = pGame->pUnitList[UNIT_OBJECT][i];
        while (pObject)
        {
            D2UnitStrc* pCurrent = pObject;
            pObject = SUNIT_GetNextUnitFromList(pObject);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

// 0x00552AA0
unsigned char __fastcall OBJECTS_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord)
{
    return 2 * pObjectsTxtRecord->dwParm[2];
}

// 0x00552AB0
unsigned char __fastcall OBJECTS_GetRegenerateSteps()
{
    return OBJECTS_CONSTANT_00552AB0;
}

// 0x00552AC0
static void __cdecl OBJECTS_ApplySubclassClassId(D2UnitStrc* pUnit)
{
    int nClassId;
    if (!pUnit)
        nClassId = -1;
    else
        nClassId = pUnit->dwClassId;
    const int nSubClassId = DATATBLS_GetObjectsTxtRecord(nClassId)->dwParm[1];
    int nNewClassId = 84;
    if (nSubClassId && nSubClassId < 573)
        nNewClassId = nSubClassId;
    pUnit->dwClassId = nNewClassId;
}

// 0x00552AF0
void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* pPortal, int nUnitId)
{
    D2TimerArgStrc* pTimerArg = UNITS_GetTimerArg(pPortal);
    if (pTimerArg)
    {
        pTimerArg->dwUnitId = nUnitId;
    }
}

// 0x00552B10
int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit)
{
    D2TimerArgStrc* pTimerArg = UNITS_GetTimerArg(pUnit);
    if (pTimerArg)
    {
        return pTimerArg->dwUnitId;
    }

    return -1;
}

// 0x00552B30
void __fastcall OBJECTS_InitFunction16_Well(D2ObjInitFnStrc* pOp)
{
    pOp->pObject->pObjectData->InteractType = 2 * (unsigned char)pOp->pObjectTxt->dwParm[WELL_PARAM];
}

static inline int UNITS_GetAnimMode(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->dwAnimMode;
}

// 0x00552B50
D2UnitStrc* __fastcall OBJECTS_PopulateFn2_WaypointShrine(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnused, int nObjectId, unsigned short nProbability)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nObjectId);
    const int nSizeX = pObjectsTxtRecord->dwSizeX;
    const int nSizeY = pObjectsTxtRecord->dwSizeY;
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nLevelId = DUNGEON_GetLevelIdFromPopulatedRoom(pRoom);
    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;
    const unsigned int nRoll = OBJECTS_RollRandomNumberInline(pSeed);
    unsigned char bForce = 0;
    int nRetries = 3;
    if (OBJRGN_ShouldSpawnHealingShrineOrWell(pGame, nLevelId))
    {
        bForce = 1;
        nRetries = 30;
    }
    else if (nRoll % 100 > nProbability)
        return 0;
    if (OBJRGN_CanNotSpawnMoreShrines(pGame, nLevelId))
        return 0;
    while (nRetries > 0)
    {
        D2UnitStrc* pObject = OBJECTS_SpawnObjectInRoomWithCallback(pGame, nObjectId, nSizeX, nSizeY, pRoom, pObjectsTxtRecord->nSide, nLevelId, OBJRGN_CanSpawnShrine);
        if (pObject)
        {
            if (pObjectsTxtRecord->nSelectable[UNITS_GetAnimMode(pObject)])
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            else
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            if (pObject->pObjectData->InteractType != 2)
            {
                if (bForce)
                {
                    OBJECTS_ApplySubclassClassId(pObject);
                    OBJECTS_GetShrineId(pGame, 1, pRoom, 2);
                    pObject->pObjectData->InteractType = 2;
                    UNITS_SetShrineTxtRecordInObjectData(pObject, DATATBLS_GetShrinesTxtRecord(2));
                    OBJRGN_IncreaseHealingShrineCount(pGame, nLevelId);
                }
            }
            else
                OBJRGN_IncreaseHealingShrineCount(pGame, nLevelId);
            OBJRGN_SetShrineCoordinates(pGame, nLevelId, OBJECTS_GetUnitXInline(pObject), OBJECTS_GetUnitYInline(pObject));
            return pObject;
        }
        --nRetries;
    }
    return 0;
}

// 0x00555CD0
void __fastcall OBJECTS_AppendPair(int* pCount, D2UnkPairStrc* pPairs, int nSecond, int nFirst)
{
    const int nCount = *pCount;
    if (nCount < D2_PAIR_CAPACITY)
    {
        pPairs[nCount].nSecond = nSecond;
        pPairs[nCount].nFirst = nFirst;
        ++*pCount;
    }
}


// 0x0056CD50
int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPerDelay, nSkillId, nSkillLevel);
    if (nDelay <= 5)
    {
        nDelay = 5;
    }

    return (pGame->dwGameFrame + nDelay - 1) / nDelay * nDelay + 1;
}

// 0x00570850
void __fastcall PLAYERSTATS_OnPlayerLeveledUp(void* pUnused, D2UnitStrc* pUnit, int nArg)
{
    SCMD_Send0x75_PartyRosterUpdate(pUnit, nArg);
}

extern "C" void __cdecl OBJECTS_SpawnPresetChest(); // 0x0054F180
extern "C" void __cdecl sub_0054F370(); // 0x0054F370
extern "C" void __cdecl OBJECTS_InitFunction04_TowerTome(); // 0x00595A00
extern "C" void __cdecl OBJECTS_InitFunction09_InifussTree(); // 0x00593FC0
extern "C" void __cdecl OBJECTS_InitFunction13_InvisibleObject(); // 0x00594020
extern "C" void __cdecl OBJECTS_InitFunction17_Waypoint(); // 0x00547210
extern "C" void __cdecl OBJECTS_InitFunction18_JerhynPosition(); // 0x005448B0
extern "C" void __cdecl OBJECTS_InitFunction19_JerhynPositionEx(); // 0x005448E0
extern "C" void __cdecl OBJECTS_InitFunction20_TaintedAltar(); // 0x00544910
extern "C" void __cdecl OBJECTS_InitFunction21_HoradricOrifice(); // 0x0059DB50
extern "C" void __cdecl OBJECTS_InitFunction23_LamEsenTomeStand(); // 0x00544E30
extern "C" void __cdecl OBJECTS_InitFunction29_ArcaneSanctuaryPortal(); // 0x0059BA40
extern "C" void __cdecl OBJECTS_InitFunction30_HaremBlocker(); // 0x0059B7D0
extern "C" void __cdecl OBJECTS_InitFunction38_TyraelsDoor(); // 0x0059DAD0
extern "C" void __cdecl OBJECTS_InitFunction39_GidbinnAltar(); // 0x005B9D40
extern "C" void __cdecl OBJECTS_InitFunction41_SewerStairs(); // 0x005B8660
extern "C" void __cdecl OBJECTS_InitFunction42_SewerLever(); // 0x005B86B0
extern "C" void __cdecl OBJECTS_InitFunction43_DarkWanderer(); // 0x005BD1F0
extern "C" void __cdecl OBJECTS_InitFunction44_HellGatePortal(); // 0x005BCBF0
extern "C" void __cdecl OBJECTS_InitFunction45_MephistoBridge(); // 0x005BCB90
extern "C" void __cdecl OBJECTS_InitFunction47_CountessChest(); // 0x00595A50
extern "C" void __cdecl OBJECTS_InitFunction49_HratliStart(); // 0x005B70B0
extern "C" void __cdecl OBJECTS_InitFunction50_HratliEnd(); // 0x005B7160
extern "C" void __cdecl OBJECTS_InitFunction52_NatalyaStart(); // 0x005BCE80
extern "C" void __cdecl OBJECTS_InitFunction53_StairsR(); // 0x005BBB70
extern "C" void __cdecl OBJECTS_InitFunction54_CainStartPosition(); // 0x005940E0
extern "C" void __cdecl OBJECTS_InitFunction55_DiabloStartPoint(); // 0x005B5590
extern "C" void __cdecl OBJECTS_InitFunction60_CompellingOrb(); // 0x005BBBA0
extern "C" void __cdecl OBJECTS_InitFunction61_CainPortal(); // 0x00594290
extern "C" void __cdecl OBJECTS_InitFunction62_CagedWussie(); // 0x005886A0
extern "C" void __cdecl OBJECTS_InitFunction63_AncientStatue3(); // 0x0058D150
extern "C" void __cdecl OBJECTS_InitFunction64_AncientStatue1(); // 0x0058D190
extern "C" void __cdecl OBJECTS_InitFunction65_AncientStatue2(); // 0x0058D110
extern "C" void __cdecl OBJECTS_InitFunction67_DrehyaStartOutsideTown(); // 0x0058A5B0
extern "C" void __cdecl OBJECTS_InitFunction68_NihlathakStartInTown(); // 0x0058A610
extern "C" void __cdecl OBJECTS_InitFunction69_NihlathakStartOutsideTown(); // 0x0058A6C0
extern "C" void __cdecl OBJECTS_InitFunction71_LarzukStandard(); // 0x00587840
extern "C" void __cdecl OBJECTS_InitFunction72_AncientsAltar(); // 0x0058D240
extern "C" void __cdecl OBJECTS_InitFunction73_AncientsDoor(); // 0x0058D280
extern "C" void __cdecl OBJECTS_InitFunction74_FrozenAnya(); // 0x0058AA50
extern "C" void __cdecl OBJECTS_InitFunction75_BaalsPortal(); // 0x0058E670
extern "C" void __cdecl OBJECTS_InitFunction76_SummitDoor(); // 0x0058D640
extern "C" void __cdecl OBJECTS_InitFunction77_LastPortal(); // 0x0058E710
extern "C" void __cdecl OBJECTS_InitFunction78_LastLastPortal(); // 0x005B5840
extern "C" void __cdecl OBJECTS_InitFunction79_Zoo(); // 0x0058E830
extern "C" void __cdecl OBJECTS_InitFunction_005500E0(); // 0x005500E0
extern "C" void __cdecl OBJECTS_InitFunction15_MalusStand(); // 0x00544950
extern "C" void __cdecl OBJECTS_InitFunction07_CainGibbet(); // 0x00544990
extern "C" void __cdecl sub_005506D0(); // 0x005506D0
extern "C" void __cdecl OBJECTS_InitFunction70_Unused(); // 0x00587830
extern "C" void __cdecl OBJECTS_InitFunction66_DrehyaStartInTown(); // 0x0058EAC0
extern "C" void __cdecl sub_005935E0(); // 0x005935E0
extern "C" void __cdecl OBJECTS_InitFunction31_Unused(); // 0x00599EE0
extern "C" void __cdecl OBJECTS_InitFunction33_Unused(); // 0x00599EF0
extern "C" void __cdecl OBJECTS_InitFunction32_Unused(); // 0x00599F00
extern "C" void __cdecl OBJECTS_InitFunction56_Unused(); // 0x005B5620
extern "C" void __cdecl OBJECTS_InitFunction48_HellForge(); // 0x005B5A20
extern "C" void __cdecl OBJECTS_InitFunction25_Gidbinn(); // 0x005B9AE0
extern "C" void __cdecl OBJECTS_InitFunction37_Unused(); // 0x0059DA50
extern "C" void __cdecl sub_00550C20(); // 0x00550C20
extern "C" void __cdecl sub_005516C0(); // 0x005516C0
extern "C" void __cdecl sub_00551850(); // 0x00551850
extern "C" void __cdecl sub_00551C00(); // 0x00551C00

#pragma pack(push, 1)
struct d2data_00731D9C_t
{
    unsigned char b0[48];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00731DD0_t
{
    unsigned char b0[40];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00731DFC_t
{
    unsigned char b0[40];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00731E28_t
{
    unsigned char b0[56];
};
#pragma pack(pop)

extern "C" const D2ObjectTableStrc gData_006E1080[6]; // 0x006E1080
extern "C" struct d2data_00731D9C_t gData_00731D9C; // 0x00731D9C
extern "C" struct d2data_00731DD0_t gData_00731DD0; // 0x00731DD0
extern "C" struct d2data_00731DFC_t gData_00731DFC; // 0x00731DFC
extern "C" struct d2data_00731E28_t gData_00731E28; // 0x00731E28

extern "C" const D2ObjectTableStrc gData_006E1080[6] = {
    { 136, 2, 6 },
    { 136, 7, 7 },
    { 136, 8, 11 },
    { 136, 12, 12 },
    { 136, 1, 5 },
    { 136, 14, 14 }
}; // 0x006E1080
#pragma comment(linker, "/alternatename:?gaShrineObjectTable@@3QBUD2ObjectTableStrc@@B=_gData_006E1080")

extern unsigned char gnObjectPopulateDensity = 0x40; // 0x00731BBD

extern PRESETSPAWNFN gpfnPresetObjectSpawners[9] = { (PRESETSPAWNFN)&OBJECTS_SpawnShrine, (PRESETSPAWNFN)&OBJECTS_SpawnShrine, (PRESETSPAWNFN)&OBJECTS_SpawnShrine, (PRESETSPAWNFN)&OBJECTS_SpawnShrine, (PRESETSPAWNFN)&OBJECTS_SpawnShrine, (PRESETSPAWNFN)&OBJECTS_SpawnShrine, (PRESETSPAWNFN)&sub_0054F370, (PRESETSPAWNFN)&OBJECTS_SpawnPresetChest, (PRESETSPAWNFN)&OBJECTS_SpawnArcaneSymbol }; // 0x00731D28

extern int gnPresetObjectSpawnerCount = 9; // 0x00731D4C

extern "C" struct d2data_00731D9C_t gData_00731D9C = {
    {
        0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF
    }
}; // 0x00731D9C

extern "C" struct d2data_00731DD0_t gData_00731DD0 = {
    {
        0xF8, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x08
    }
}; // 0x00731DD0

extern int gnCoordInitCount = 4; // 0x00731E64

extern D2ObjInitFn sgInitTable[80] = {
    0, (D2ObjInitFn)&OBJECTS_InitFunction01_Shrine, (D2ObjInitFn)&OBJECTS_InitFunction02_Urn, (D2ObjInitFn)&OBJECTS_InitFunction03_Chest, (D2ObjInitFn)&OBJECTS_InitFunction04_TowerTome, (D2ObjInitFn)&OBJECTS_InitFunction05_Door, (D2ObjInitFn)&sub_005935E0, (D2ObjInitFn)&OBJECTS_InitFunction07_CainGibbet, (D2ObjInitFn)&OBJECTS_InitFunction08_Torch, (D2ObjInitFn)&OBJECTS_InitFunction09_InifussTree, (D2ObjInitFn)&OBJECTS_InitFunction10_Unused, (D2ObjInitFn)&OBJECTS_InitFunction11_Portal, (D2ObjInitFn)&OBJECTS_InitFunction12_PermanentPortal, (D2ObjInitFn)&OBJECTS_InitFunction13_InvisibleObject, (D2ObjInitFn)&OBJECTS_InitFunction14_Brazier, (D2ObjInitFn)&OBJECTS_InitFunction15_MalusStand,
    (D2ObjInitFn)&OBJECTS_InitFunction16_Well, (D2ObjInitFn)&OBJECTS_InitFunction17_Waypoint, (D2ObjInitFn)&OBJECTS_InitFunction18_JerhynPosition, (D2ObjInitFn)&OBJECTS_InitFunction19_JerhynPositionEx, (D2ObjInitFn)&OBJECTS_InitFunction20_TaintedAltar, (D2ObjInitFn)&OBJECTS_InitFunction21_HoradricOrifice, (D2ObjInitFn)&OBJECTS_InitFunction22_Fire, (D2ObjInitFn)&OBJECTS_InitFunction23_LamEsenTomeStand, (D2ObjInitFn)&OBJECTS_InitFunction24_SpikeFloorTrap, (D2ObjInitFn)&OBJECTS_InitFunction25_Gidbinn, (D2ObjInitFn)&OBJECTS_InitFunction_005500E0, (D2ObjInitFn)&OBJECTS_InitFunction27_GooPile, (D2ObjInitFn)&OBJECTS_InitFunction28_GoldPlaceHolder, (D2ObjInitFn)&OBJECTS_InitFunction29_ArcaneSanctuaryPortal, (D2ObjInitFn)&OBJECTS_InitFunction30_HaremBlocker, (D2ObjInitFn)&OBJECTS_InitFunction31_Unused,
    (D2ObjInitFn)&OBJECTS_InitFunction32_Unused, (D2ObjInitFn)&OBJECTS_InitFunction33_Unused, (D2ObjInitFn)&OBJECTS_InitFunction34_HellBrazierFire, 0, 0, (D2ObjInitFn)&OBJECTS_InitFunction37_Unused, (D2ObjInitFn)&OBJECTS_InitFunction38_TyraelsDoor, (D2ObjInitFn)&OBJECTS_InitFunction39_GidbinnAltar, 0, (D2ObjInitFn)&OBJECTS_InitFunction41_SewerStairs, (D2ObjInitFn)&OBJECTS_InitFunction42_SewerLever, (D2ObjInitFn)&OBJECTS_InitFunction43_DarkWanderer, (D2ObjInitFn)&OBJECTS_InitFunction44_HellGatePortal, (D2ObjInitFn)&OBJECTS_InitFunction45_MephistoBridge, (D2ObjInitFn)&sub_005506D0, (D2ObjInitFn)&OBJECTS_InitFunction47_CountessChest,
    (D2ObjInitFn)&OBJECTS_InitFunction48_HellForge, (D2ObjInitFn)&OBJECTS_InitFunction49_HratliStart, (D2ObjInitFn)&OBJECTS_InitFunction50_HratliEnd, (D2ObjInitFn)&OBJECTS_InitFunction51_TrappedSoul, (D2ObjInitFn)&OBJECTS_InitFunction52_NatalyaStart, (D2ObjInitFn)&OBJECTS_InitFunction53_StairsR, (D2ObjInitFn)&OBJECTS_InitFunction54_CainStartPosition, (D2ObjInitFn)&OBJECTS_InitFunction55_DiabloStartPoint, (D2ObjInitFn)&OBJECTS_InitFunction56_Unused, (D2ObjInitFn)&OBJECTS_InitFunction57_SparklyChest, (D2ObjInitFn)&OBJECTS_InitFunction58_Fissure, (D2ObjInitFn)&OBJECTS_InitFunction59_VileDogAfterglow, (D2ObjInitFn)&OBJECTS_InitFunction60_CompellingOrb, (D2ObjInitFn)&OBJECTS_InitFunction61_CainPortal, (D2ObjInitFn)&OBJECTS_InitFunction62_CagedWussie, (D2ObjInitFn)&OBJECTS_InitFunction63_AncientStatue3,
    (D2ObjInitFn)&OBJECTS_InitFunction64_AncientStatue1, (D2ObjInitFn)&OBJECTS_InitFunction65_AncientStatue2, (D2ObjInitFn)&OBJECTS_InitFunction66_DrehyaStartInTown, (D2ObjInitFn)&OBJECTS_InitFunction67_DrehyaStartOutsideTown, (D2ObjInitFn)&OBJECTS_InitFunction68_NihlathakStartInTown, (D2ObjInitFn)&OBJECTS_InitFunction69_NihlathakStartOutsideTown, (D2ObjInitFn)&OBJECTS_InitFunction70_Unused, (D2ObjInitFn)&OBJECTS_InitFunction71_LarzukStandard, (D2ObjInitFn)&OBJECTS_InitFunction72_AncientsAltar, (D2ObjInitFn)&OBJECTS_InitFunction73_AncientsDoor, (D2ObjInitFn)&OBJECTS_InitFunction74_FrozenAnya, (D2ObjInitFn)&OBJECTS_InitFunction75_BaalsPortal, (D2ObjInitFn)&OBJECTS_InitFunction76_SummitDoor, (D2ObjInitFn)&OBJECTS_InitFunction77_LastPortal, (D2ObjInitFn)&OBJECTS_InitFunction78_LastLastPortal, (D2ObjInitFn)&OBJECTS_InitFunction79_Zoo
}; // 0x00731BC0

extern int gnArmorStandOrRackIds[4] = { 104, 105, 106, 107 }; // 0x00731EA0

extern int gnArmorStandOrRackCount = 2; // 0x00731EB0

extern int gnCasketClusterIds[3] = { 79, 53, 1 }; // 0x00731D50

extern int gnCasket6ClusterIds[2] = { 3, 28 }; // 0x00731D5C

extern int gnValues_00731D64[5] = { 4, 9, 52, 94, 95 }; // 0x00731D64

extern int gnMummyCoffinClusterIds[2] = { 89, 284 }; // 0x00731D78

extern int gnBasketClusterIds[2] = { 208, 209 }; // 0x00731D80

extern int gnCasketClusterIdCount = 3; // 0x00731D88

extern int gnCasket6ClusterIdCount = 2; // 0x00731D8C

extern int gnCount_00731D90 = 5; // 0x00731D90

extern int gnMummyCoffinClusterIdCount = 2; // 0x00731D94

extern int gnBasketClusterIdCount = 2; // 0x00731D98

extern int gaDirectionX_00731B7C[8] = { -1, 0, 1, -1, 1, -1, 0, 1 }; // 0x00731B7C

extern int gaDirectionY_00731B9C[8] = { -1, -1, -1, 0, 0, 1, 1, 1 }; // 0x00731B9C

extern D2ObjectPopulateStrc gaObjectThemeTable[7] = {
    { 0 },
    { 1, (int (__fastcall *)(D2GameStrc *, D2ActiveRoomStrc *, D2DrlgCoordsStrc *))&OBJECTS_SpawnNothing },
    { 1, (int (__fastcall *)(D2GameStrc *, D2ActiveRoomStrc *, D2DrlgCoordsStrc *))&OBJECTS_SpawnBarrel },
    { 0 },
    { 1, (int (__fastcall *)(D2GameStrc *, D2ActiveRoomStrc *, D2DrlgCoordsStrc *))&OBJECTS_SpawnRandomItemGrid },
    { 1, (int (__fastcall *)(D2GameStrc *, D2ActiveRoomStrc *, D2DrlgCoordsStrc *))&OBJECTS_SpawnArmorStand },
    { 1, (int (__fastcall *)(D2GameStrc *, D2ActiveRoomStrc *, D2DrlgCoordsStrc *))&OBJECTS_SpawnWeaponRack }
}; // 0x00731E68

extern unsigned char gnObjectGoreLevel = 2; // 0x00731BBC

extern OBJECTPOPULATEFN sgPopulateTable[10] = { 0, (OBJECTPOPULATEFN)&sub_00550C20, (OBJECTPOPULATEFN)&OBJECTS_PopulateFn2_WaypointShrine, (OBJECTPOPULATEFN)&OBJECTS_PopulateFn3_CommonObjects, (OBJECTPOPULATEFN)&sub_00551850, (OBJECTPOPULATEFN)&sub_00551C00, (OBJECTPOPULATEFN)&OBJECTS_PopulateFn6_RogueGuardCorpse, (OBJECTPOPULATEFN)&OBJECTS_PopulateFn7_RogueOnStick, (OBJECTPOPULATEFN)&sub_005516C0, (OBJECTPOPULATEFN)&OBJECTS_PopulateFn9_TrappedSoul }; // 0x00731D00

extern int gnSource_00731DCC = 6; // 0x00731DCC

extern int gnSource_00731DF8 = 5; // 0x00731DF8

extern "C" struct d2data_00731DFC_t gData_00731DFC = {
    {
        0x00, 0x00, 0x00, 0x00, 0xF8, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0xFC, 0xFF, 0xFF, 0xFF,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x08
    }
}; // 0x00731DFC

extern int gnSource_00731E24 = 5; // 0x00731E24

extern "C" struct d2data_00731E28_t gData_00731E28 = {
    {
        0xF9, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFB, 0xFF, 0xFF, 0xFF, 0xFD, 0xFF, 0xFF, 0xFF,
        0xFD, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x05, 0x00, 0x00, 0x00, 0xFD, 0xFF, 0xFF, 0xFF,
        0x07, 0x00, 0x00, 0x00, 0xFB, 0xFF, 0xFF, 0xFF
    }
}; // 0x00731E28

extern int gnSource_00731E60 = 7; // 0x00731E60

D2CoordInitStrc gaCoordInit[] =
{
    { (D2CoordStrc*)&gData_00731D9C, gnSource_00731DCC },
    { (D2CoordStrc*)&gData_00731DD0, gnSource_00731DF8 },
    { (D2CoordStrc*)&gData_00731DFC, gnSource_00731E24 },
    { (D2CoordStrc*)&gData_00731E28, gnSource_00731E60 },
};
