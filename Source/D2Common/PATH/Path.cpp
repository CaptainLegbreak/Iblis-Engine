#include "D2MonsterIds.h"

#include "D2ItemTypes.h"

#include "D2DrlgMaps.h"

#include "D2DrlgTiles.h"

#include "D2TxtTables.h"

#include "D2LevelIds.h"

#include "D2Unicode.h"

#include "D2StateIds.h"

#include "D2SkillIds.h"

#include "D2StatIds.h"

#include "D2Records.h"

#include "D2Skills.h"

#include "D2LevelTxt.h"

#include "D2PlayerModes.h"

#include "D2MonModes.h"

#include "D2PathFind.h"

#include "D2Common.h"
#include "D2CommonInternal.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Drlg.h"

#include "D2DrlgPresets.h"

#include "D2DataTbls.h"

#include "D2Txt.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2ClientApi.h"

#define PATH_UNKNOWN_FLAG_0x00001 0x00001

#define PATH_UNKNOWN_FLAG_0x00010 0x00010

#define PATH_UNKNOWN_FLAG_0x00020 0x00020

#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define PATH_CORPSE_SIZE 3

struct D2PoolSystemStrc;
struct D2CoordStrc;

union D2FP32_16;

struct D2DrlgCoordsStrc;

struct D2StaticPathStrc;

struct D2PathInfoStrc;

struct PATH_SetVelocity;

struct PATH_GetPathPoints;

struct PATH_GetLastPointX;

struct PATH_GetLastPointY;

struct DirectionRecord;

struct PATH_SetStepNum;

struct D2PathPointStrc;

struct D2ActiveRoomStrc;

struct D2UnitStrc;

struct D2DynamicPathStrc;

typedef int BOOL;

typedef int (__fastcall* PATH_FUNCTION)(D2PathInfoStrc* pPathInfo);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn); // 0x006CC34C

extern const D2CoordStrc gaDirectionToOffset[8]; // 0x006EB398

extern PATH_FUNCTION const gpfnPathFunctions[]; // 0x006EB6D8

int __stdcall UnitIsDoor(D2UnitStrc* pUnit); // 0x00621A70

int __fastcall UNITS_CheckIfObjectOrientationIs1(D2UnitStrc* pUnit); // 0x00621AC0

int __fastcall MONSTERS_CanBeInTown(D2UnitStrc* pMonster); // 0x0063E860

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064D910

int __fastcall PATH_ComputePathBlessedHammer(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed); // 0x0067A140

int __fastcall PATH_ComputePathChargedBolt(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed); // 0x0067A240

static void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo); // 0x00648050

static BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo);

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_word_width[sizeof(unsigned short)==2?1:-1];

struct DirectionRecord
{
    int x;
    int y;
    int angle;
};

typedef char check_DirectionRecord_y[OFFSET(DirectionRecord,y)==4?1:-1];

typedef char check_DirectionRecord_angle[OFFSET(DirectionRecord,angle)==8?1:-1];

typedef char check_DirectionRecord_size[sizeof(DirectionRecord)==12?1:-1];

extern DirectionRecord gaTanToDirectionTable[128];

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30

static unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo);

static int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath);

static int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit);

static BOOL PATH_IsTargetDestinationAllowed(D2PathInfoStrc* pPathInfo, D2UnitStrc* pUnit);

static BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo);

#define COLLIDE_MISSILE_BARRIER 0x4

#define MONSTATSFLAGINDEX_INTERACT 9

#define UNITFLAG_ISASYNC 0x00200000

#define PATH_UNKNOWN_FLAG_0x02000 0x00002000

#define PATH_WITH_PREVIOUS_VELOCITY 0x00008000

struct D2MonStatsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize); // 0x00648580

int __stdcall D2Common_10227(D2UnitStrc* pUnit); // 0x00650540

extern int gaOffsetForPathType[]; // 0x006EB648

extern int gaPathTypeFlags[]; // 0x006EB690

void __stdcall DUNGEON_ClientToGameCoords(int* pX, int* pY); // 0x00643540

int __stdcall UNITS_HasCollision(D2UnitStrc* pUnit); // 0x006219C0

void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

#define PATH_NB_DIRECTIONS 64

#define PATHTYPE_IDASTAR 0

#define PATH_CURRENT_ROOM_INVALID 0x00002

#define PATH_UNUSED_FLAG_0x00004 0x00004

#define PATH_UNKNOWN_FLAG_0x00040 0x00040

#define PATH_SAVE_STEPS_MASK 0x20000

static int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath);

static unsigned char PATH_AdvanceToDoor(D2PathInfoStrc* pPathInfo);

static unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo);

static int PATH_GetMonsterMoveTestMask(D2UnitStrc* pUnit);

int __stdcall PATH_ComputeDirectionFromPreciseCoords(D2FP32_16 tStart, D2FP32_16 tTarget); // 0x0064FE10

static int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit);

void __cdecl sub_00403F50_Nop()
{
}

inline unsigned int PATH_InlineGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline unsigned int PATH_InlineGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

void __fastcall sub_0040B480(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480



// 0x00647FB0
void __fastcall PATH_CheckPathInRoom(D2DynamicPathStrc* pDynamicPath)
{
    D2PathPointStrc* const pPathPoints = pDynamicPath->PathPoints;
    pDynamicPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00001;
    D2ActiveRoomStrc* pRoom = pDynamicPath->pRoom;
    for (int i = 0; i < pDynamicPath->dwPathPoints; ++i)
    {
        if (!pRoom
            || pPathPoints[i].X < pRoom->tCoords.nSubtileX || pPathPoints[i].X >= pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
            || pPathPoints[i].Y < pRoom->tCoords.nSubtileY || pPathPoints[i].Y >= pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight)
        {
            pDynamicPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00001;
            return;
        }
    }
}

// 0x00648020
static void __stdcall PATH_GetTablePair(int b, int a, int* pOut1, int* pOut2)
{
    *pOut1 = gaOffsetsForSnappingToCardinalDirection[a + PATH_SNAP_CENTER][b + PATH_SNAP_CENTER];
    *pOut2 = gaOffsetsForSnappingToCardinalDirection[b + PATH_SNAP_CENTER][a + PATH_SNAP_CENTER];
}

void __stdcall sub_K15_Emit8(int* p, int n)
{
    PATH_GetTablePair(p[1], n, p, p + 1);
    PATH_GetTablePair(n, p[2], p + 2, p + 3);
}

// 0x00648050
static void PATH_FindValidTargetCoordsByMovingOrthogonally(D2PathInfoStrc* pPathInfo)
{
    int nY;
    const int nDeltaX = pPathInfo->tTargetCoord.X - pPathInfo->tStartCoord.X;
    const int nDeltaY = pPathInfo->tTargetCoord.Y - pPathInfo->tStartCoord.Y;
    const int nAbsDeltaX = D2_ABS(nDeltaX);
    const int nAbsDeltaY = D2_ABS(nDeltaY);
    if (nAbsDeltaX < PATH_SNAP_RANGE && nAbsDeltaY < PATH_SNAP_RANGE && (nAbsDeltaX != 0 || nAbsDeltaY != 0))
    {
        int nX = pPathInfo->tTargetCoord.X;
        const int nCollisionPattern = pPathInfo->nCollisionPattern;
        const int nCollisionMask = pPathInfo->nCollisionMask;
        const int nOffsetX = gaOffsetsForSnappingToCardinalDirection[nDeltaY + PATH_SNAP_CENTER][nDeltaX + PATH_SNAP_CENTER];
        const int nOffsetY = gaOffsetsForSnappingToCardinalDirection[nDeltaX + PATH_SNAP_CENTER][nDeltaY + PATH_SNAP_CENTER];
        nY = pPathInfo->tTargetCoord.Y;
        int nChebyshevDistance = D2_MAX(nAbsDeltaX, nAbsDeltaY);
        while (nChebyshevDistance < PATH_SNAP_RANGE)
        {
            nX += nOffsetX;
            nY += nOffsetY;
            if (COLLISION_CheckAnyCollisionWithPattern(pPathInfo->pStartRoom, nX, nY, nCollisionPattern, nCollisionMask))
            {
                break;
            }

            pPathInfo->tTargetCoord.X = nX;
            pPathInfo->tTargetCoord.Y = nY;
            ++nChebyshevDistance;
        }
    }
}

// 0x00648120
static BOOL PATH_PreparePathTargetForPathUpdate(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* ptPath = pPathInfo->pDynamicPath;
    D2_ASSERT(!(ptPath->dwFlags & PATH_MISSILE_MASK), LINE_PREPARE_MISSILE);

    const unsigned short nStartX = pPathInfo->tStartCoord.X;
    const unsigned short nStartY = pPathInfo->tStartCoord.Y;
    const unsigned short nTargetX = pPathInfo->tTargetCoord.X;
    const unsigned short nTargetY = pPathInfo->tTargetCoord.Y;
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nUnitType = !ptPath->pUnit ? UNIT_NONE : ptPath->pUnit->dwUnitType;

    D2PathPointStrc aTestDirPathPoints[3];
    aTestDirPathPoints[0].X = nTargetX;
    aTestDirPathPoints[0].Y = nTargetY;
    aTestDirPathPoints[1].X = nTargetX;
    aTestDirPathPoints[1].Y = nTargetY;
    aTestDirPathPoints[2].X = nTargetX;
    aTestDirPathPoints[2].Y = nTargetY;

    int aTestDir[3];
    PATH_GetAltDirectionTriplet(aTestDir, pPathInfo->tTargetCoord, pPathInfo->tStartCoord);
    while (1)
    {
        if (nStartX == aTestDirPathPoints[0].X && nStartY == aTestDirPathPoints[0].Y)
        {
            break;
        }

        aTestDirPathPoints[0].X += gaDirectionToOffset[aTestDir[0]].nX;
        aTestDirPathPoints[0].Y += gaDirectionToOffset[aTestDir[0]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[0].X, aTestDirPathPoints[0].Y, nCollisionPattern, nCollisionMask))
        {
            pPathInfo->tTargetCoord.X = aTestDirPathPoints[0].X;
            pPathInfo->tTargetCoord.Y = aTestDirPathPoints[0].Y;
            if (aTestDirPathPoints[0].X == nStartX && aTestDirPathPoints[0].Y == nStartY)
            {
                return FALSE;
            }

            if (nUnitType == UNIT_PLAYER)
            {
                PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
            }
            return PATH_TRUE;
        }

        aTestDirPathPoints[1].X += gaDirectionToOffset[aTestDir[1]].nX;
        aTestDirPathPoints[1].Y += gaDirectionToOffset[aTestDir[1]].nY;
        if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[1].X, aTestDirPathPoints[1].Y, nCollisionPattern, nCollisionMask))
        {
            pPathInfo->tTargetCoord.X = aTestDirPathPoints[1].X;
            pPathInfo->tTargetCoord.Y = aTestDirPathPoints[1].Y;
            if (aTestDirPathPoints[1].X == nStartX && aTestDirPathPoints[1].Y == nStartY)
            {
                return FALSE;
            }

            if (nUnitType == UNIT_PLAYER)
            {
                PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
            }
            return PATH_TRUE;
        }

        if (aTestDir[2] != PATH_DIR_NULL)
        {
            aTestDirPathPoints[2].X += gaDirectionToOffset[aTestDir[2]].nX;
            aTestDirPathPoints[2].Y += gaDirectionToOffset[aTestDir[2]].nY;
            if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, aTestDirPathPoints[2].X, aTestDirPathPoints[2].Y, nCollisionPattern, nCollisionMask))
            {
                pPathInfo->tTargetCoord.X = aTestDirPathPoints[2].X;
                pPathInfo->tTargetCoord.Y = aTestDirPathPoints[2].Y;
                if (aTestDirPathPoints[2].X == nStartX && aTestDirPathPoints[2].Y == nStartY)
                {
                    return FALSE;
                }

                if (nUnitType == UNIT_PLAYER)
                {
                    PATH_FindValidTargetCoordsByMovingOrthogonally(pPathInfo);
                }
                return PATH_TRUE;
            }
        }

        int aNextTestDir[3];
        PATH_GetAltDirectionTriplet(aNextTestDir, aTestDirPathPoints[0], pPathInfo->tStartCoord);
        aTestDir[0] = aNextTestDir[0];
    }

    return FALSE;
}

#define MONSTATS2FLAGINDEX_REVIVE 8

#define MONSTATS2FLAGINDEX_ISATT 9

#define MONSTATS2FLAGINDEX_SMALL 10

inline D2MonStats2Txt* UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// 0x00648300
void __stdcall PATH_GetClientCoordsVelocity(D2UnitStrc* pUnit, int* pX, int* pY)
{
    if (pUnit && UNITS_IsInMovingMode(pUnit))
    {
        D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
        if (pDynamicPath->dwPathPoints)
        {
            *pX = pDynamicPath->tVelocityVector.nX;
            *pY = pDynamicPath->tVelocityVector.nY;
            *pX >>= 11;
            *pY >>= 11;
            DUNGEON_GameToClientCoords(pX, pY);
        }
        else
        {
            *pX = 0;
            *pY = 0;
        }
    }
    else
    {
        *pX = 0;
        *pY = 0;
    }
}

// 0x00648370
void __cdecl sub_00648370_Nop()
{
}

// 0x00648380
void __cdecl sub_00648380_Nop()
{
}

// 0x00648390
int __stdcall sub_00648390_AlwaysZero(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x006483A0
static BOOL PATH_IsTargetDestinationAllowed(D2PathInfoStrc* pPathInfo, D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_NONE;
    if (nUnitType != UNIT_MONSTER)
    {
        return TRUE;
    }

    if (MONSTERS_CanBeInTown(pUnit))
    {
        return TRUE;
    }

    D2ActiveRoomStrc* pTargetRoom = pPathInfo->pTargetRoom;
    if (!pTargetRoom)
    {
        const unsigned short nStartX = pPathInfo->tStartCoord.X;
        const unsigned short nStartY = pPathInfo->tStartCoord.Y;
        const unsigned short nTargetX = pPathInfo->tTargetCoord.X;
        const unsigned short nTargetY = pPathInfo->tTargetCoord.Y;
        D2ActiveRoomStrc* pRoomHalfway = sub_00463740_FindRoomAtPoint(
            pPathInfo->pStartRoom,
            nStartX + (nTargetX - nStartX) / 2,
            nStartY + (nTargetY - nStartY) / 2);
        pTargetRoom = sub_00463740_FindRoomAtPoint(pRoomHalfway, nTargetX, nTargetY);
    }

    return !DUNGEON_IsRoomInTown(pTargetRoom);
}

// 0x00648430
void __cdecl sub_00648430_Nop()
{
}

// 0x00648440
void __cdecl sub_00648440_Nop()
{
}

// 0x00648450
void __cdecl sub_00648450_Nop()
{
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x006484E0
int __stdcall PATH_GetCollisionPatternFromMonStats2Txt(int nMonsterId)
{
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId_Inl(nMonsterId);
    if (pMonStats2TxtRecord)
    {
        int nSizeX = pMonStats2TxtRecord->nSizeX;
        if (nSizeX >= 0 && nSizeX < COLLISION_UNIT_SIZE_COUNT)
        {
            int nCollisionPattern = gaCollisionPatternsFromSize[nSizeX];

            if (pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_REVIVE >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_REVIVE & 7]
                || pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_SMALL >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_SMALL & 7])
            {
                if (!(pMonStats2TxtRecord->nFlags[MONSTATS2FLAGINDEX_ISATT >> 3] & gdwBitMasks[MONSTATS2FLAGINDEX_ISATT & 7]))
                {
                    switch (nCollisionPattern)
                    {
                    case COLLISION_PATTERN_SMALL_UNIT_PRESENCE:
                        nCollisionPattern = COLLISION_PATTERN_SMALL_PET_PRESENCE;
                        break;
                    case COLLISION_PATTERN_BIG_UNIT_PRESENCE:
                        nCollisionPattern = COLLISION_PATTERN_BIG_PET_PRESENCE;
                        break;
                    }
                }
            }

            return nCollisionPattern;
        }
    }

    return COLLISION_PATTERN_SMALL_UNIT_PRESENCE;
}

// 0x00648640
void __stdcall D2COMMON_10193_PATH_AdjustDirection(D2DynamicPathStrc* pDynamicPath)
{
    if ((pDynamicPath->nDirection != pDynamicPath->nNewDirection) && !(pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00040))
    {
        pDynamicPath->nDirection = (pDynamicPath->nDirection + pDynamicPath->nDiffDirection) & 63;

        const unsigned char dirDiff = (pDynamicPath->nDirection - pDynamicPath->nNewDirection) & 63;
        if ((dirDiff > 31 && pDynamicPath->nDiffDirection > 63) || (dirDiff < 31 && pDynamicPath->nDiffDirection < 63))
        {
            pDynamicPath->nDirection = pDynamicPath->nNewDirection;
        }
    }
}

// 0x006486F0
int __stdcall PATH_GetMaxVelocity(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwMaxVelocity;
}

// 0x00648720
int __stdcall PATH_GetAcceleration(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwAcceleration;
}

// 0x00648770
int __stdcall D2COMMON_10209_PathCheckPathingFlag(D2DynamicPathStrc* pDynamicPath)
{
    return (pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00020);
}

// 0x006487C0
int __stdcall D2Common_10155(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwCurrentPointIdx;
}

// 0x00649180
int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit)
{
    return pUnit->pDynamicPath->dwCollisionPattern;
}

// 0x00648750
void __stdcall PATH_SetPathingFlag(D2DynamicPathStrc* pDynamicPath, int bSet)
{
    if (bSet)
    {
        pDynamicPath->dwFlags |= 0x20;
    }
    else
    {
        pDynamicPath->dwFlags &= ~0x20;
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00648460
void __stdcall PATH_FreeDynamicPath(D2PoolSystemStrc* pMemPool, D2DynamicPathStrc* pDynamicPath)
{
    sub_0040B480(pMemPool, pDynamicPath, ".\\PATH\\Path.cpp", 985, 0);
}

// 0x00648480
static int PATH_GetMonsterMoveTestMask(D2UnitStrc* pUnit)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? DATATBLS_GetMonStatsTxtRecordInl(pUnit->dwClassId) : 0;
    if (BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_FLYING))
    {
        return COLLIDE_MASK_FLYING_UNIT;
    }
    return BITARRAY_CHECK(pMonStatsTxtRecord->nMonStatsFlags, MONSTATSFLAGINDEX_OPENDOORS) ? COLLIDE_MASK_MONSTER_THAT_CAN_OPEN_DOORS : COLLIDE_MASK_MONSTER_PATH;
}

// 0x00648580
int __stdcall D2Common_11281_CollisionPatternFromSize(D2UnitStrc* pUnit, int nSize)
{
    if (nSize < 0 || nSize >= COLLISION_UNIT_SIZE_COUNT)
    {
        return COLLISION_PATTERN_SMALL_UNIT_PRESENCE;
    }

    int nCollisionPattern = gaCollisionPatternsFromSize[nSize];
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && MONSTERS_CanBeInTown(pUnit) && !MONSTERUNIQUE_CheckMonStatsFlag(pUnit->dwClassId, MONSTATSFLAGINDEX_INTERACT))
    {
        switch (nCollisionPattern)
        {
        case COLLISION_PATTERN_SMALL_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_SMALL_PET_PRESENCE;
            break;
        case COLLISION_PATTERN_BIG_UNIT_PRESENCE:
            nCollisionPattern = COLLISION_PATTERN_BIG_PET_PRESENCE;
            break;
        }
    }

    return nCollisionPattern;
}

// 0x00649190
void __stdcall PATH_SetUnitCollisionPattern(D2UnitStrc* pUnit, int nCollisionPattern)
{
    pUnit->pDynamicPath->dwCollisionPattern = nCollisionPattern;
}

// 0x006485F0
void __fastcall PATH_SetNewDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection)
{
    nDirection &= 63;
    int nUnitType;
    if (!pDynamicPath->pUnit)
    {
        nUnitType = 6;
    }
    else
    {
        nUnitType = pDynamicPath->pUnit->dwUnitType;
    }

    switch (nUnitType)
    {
    case 2:
    case 4:
        pDynamicPath->nDirection = nDirection;
        break;
    case 3:
        if (!(pDynamicPath->dwFlags & 0x40))
        {
            pDynamicPath->nDirection = nDirection;
        }
        break;
    default:
        if (nDirection != pDynamicPath->nNewDirection)
        {
            pDynamicPath->nNewDirection = nDirection;
            const unsigned char nDiff = nDirection - pDynamicPath->nDirection;
            pDynamicPath->nDiffDirection = gnDirectionDiffTable[nDiff & 63];
        }
        break;
    }
}

// 0x00648690
void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine){
    if (pDynamicPath)
    {
        if (nVelocity != pDynamicPath->dwVelocity)
        {
            pDynamicPath->unk0x38 = 15;
        }
        pDynamicPath->dwVelocity = nVelocity;
        pDynamicPath->dwMaxVelocity = nVelocity;
    }
}

// 0x00649F50
void __stdcall D2Common_10228(D2UnitStrc* pUnit)
{
    if (pUnit->pDynamicPath)
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
    }
}

// 0x0064A0E0
void __stdcall PATH_AddCollisionFootprintForOptionalUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
    }
}

// 0x006486C0
int __stdcall PATH_GetVelocity(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwVelocity;
}

// 0x006486D0
void __stdcall PATH_SetMaxVelocity(D2DynamicPathStrc* pDynamicPath, int nMaxVelocity)
{
    pDynamicPath->dwMaxVelocity = nMaxVelocity;
}

// 0x00648700
void __stdcall PATH_SetAcceleration(D2DynamicPathStrc* pDynamicPath, int nAcceleration)
{
    pDynamicPath->dwAcceleration = nAcceleration;
}

// 0x00648730
void __stdcall PATH_ClearPathingFlagAndPoints(D2DynamicPathStrc* pDynamicPath)
{
    pDynamicPath->dwFlags &= 0xFFFFFFDF;
    pDynamicPath->dwPathPoints = 0;
}

// 0x00648780
int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwPathPoints;
}

// 0x00648790
void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath, int nPathPoints)
{
    if (nPathPoints > 77)
    {
        nPathPoints = 77;
    }
    pDynamicPath->dwPathPoints = nPathPoints;
}

// 0x006487D0
int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc** ppPathPoints)
{
    *ppPathPoints = pDynamicPath->PathPoints;
    return pDynamicPath->dwPathPoints;
}

// 0x006487F0
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->nDirection;
}

// 0x00648810
unsigned char __stdcall PATH_GetNewDirection(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nNewDirection;
}

// 0x00648820
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char bDir)
{
    D2_ASSERT(bDir < PATH_NB_DIRECTIONS, 1650);

    const unsigned char nNormalizedDirection = bDir & (PATH_NB_DIRECTIONS - 1);
    int nUnitType;
    if (!pDynamicPath->pUnit)
    {
        nUnitType = UNIT_TYPES_COUNT;
    }
    else
    {
        nUnitType = pDynamicPath->pUnit->dwUnitType;
    }

    switch (nUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
        pDynamicPath->nDirection = nNormalizedDirection;
        break;
    case UNIT_MISSILE:
        if (!(pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x00040))
        {
            pDynamicPath->nDirection = nNormalizedDirection;
        }
        break;
    default:
        if (nNormalizedDirection != pDynamicPath->nNewDirection)
        {
            pDynamicPath->nNewDirection = nNormalizedDirection;
            const unsigned char nDiff = nNormalizedDirection - pDynamicPath->nDirection;
            pDynamicPath->nDiffDirection = gnDirectionDiffTable[nDiff & (PATH_NB_DIRECTIONS - 1)];
        }
        break;
    }
}

// 0x006488A0
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection)
{
    if (pDynamicPath)
    {
        const unsigned char nNewDirection = nDirection & 0x3F;
        pDynamicPath->nDirection = nNewDirection;
        pDynamicPath->nNewDirection = nNewDirection;
    }
}

// 0x006488C0
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1682);

    return hPath->tGameCoords.wPosX;
}

// 0x00648900
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1693);

    return hPath->tGameCoords.wPosY;
}

// 0x00648940
int __stdcall PATH_GetPrecisionX(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1704);

    return hPath->tGameCoords.dwPrecisionX;
}

// 0x00648970
int __stdcall PATH_GetPrecisionY(D2DynamicPathStrc* hPath)
{
    D2_ASSERT(hPath, 1715);

    return hPath->tGameCoords.dwPrecisionY;
}

// 0x006489A0
void __stdcall PATH_SetPrecisionX(D2DynamicPathStrc* pDynamicPath, unsigned int dwPrecisionX)
{
    pDynamicPath->dwPrecisionX = dwPrecisionX;
}

// 0x006489B0
void __stdcall PATH_SetPrecisionY(D2DynamicPathStrc* pDynamicPath, int nPrecisionY)
{
    pDynamicPath->tGameCoords.dwPrecisionY = nPrecisionY;
}

// 0x006489C0
int __stdcall PATH_GetClientCoordX(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwClientCoordX;
}

// 0x006489D0
int __stdcall PATH_GetClientCoordY(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwClientCoordY;
}

// 0x006489E0
void __fastcall PATH_SetClientCoordX(D2DynamicPathStrc* pPath, int nX)
{
    pPath->dwClientCoordX = nX;
}

// 0x006489F0
void __fastcall PATH_SetClientCoordY(D2DynamicPathStrc* pPath, int nY)
{
    pPath->dwClientCoordY = nY;
}

// 0x00648A00
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.X;
}

// 0x00648A10
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tTargetCoord.Y;
}

// 0x00648A20
unsigned int __stdcall PATH_GetFinalTargetX(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tFinalTargetCoord.X;
}

// 0x00648A30
unsigned int __stdcall PATH_GetFinalTargetY(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->tFinalTargetCoord.Y;
}

// 0x00648A40
unsigned int __stdcall PATH_GetLastPointX(D2DynamicPathStrc* pDynamicPath)
{
    const int nPathPoints = pDynamicPath->dwPathPoints;
    if (nPathPoints)
    {
        return pDynamicPath->PathPoints[nPathPoints - 1].X;
    }
    return 0;
}

// 0x00648A60
unsigned int __stdcall PATH_GetLastPointY(D2DynamicPathStrc* pDynamicPath)
{
    const int nPathPoints = pDynamicPath->dwPathPoints;
    if (nPathPoints)
    {
        return pDynamicPath->PathPoints[nPathPoints - 1].Y;
    }
    return 0;
}

// 0x00648A80
D2ActiveRoomStrc* __stdcall PATH_GetRoom(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->pRoom;
}

// 0x00648A90
void __stdcall PATH_SetRoom(D2DynamicPathStrc* pDynamicPath, D2ActiveRoomStrc* pRoom)
{
    pDynamicPath->pRoom = pRoom;
}

// 0x006497D0
static unsigned char PATH_AdvanceToDoor(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* hTarget = pPath->hTarget;

    D2_ASSERT(UnitIsDoor(hTarget), LINE_DOOR);

    if (UNITS_CheckIfObjectOrientationIs1(hTarget))
    {
        if (pPath->tGameCoords.wPosY < PATH_InlineGetUnitY(hTarget))
        {
            pPath->tTargetCoord.Y -= 2;
        }
        else
        {
            pPath->tTargetCoord.Y += 2;
        }
    }
    else
    {
        if (pPath->tGameCoords.wPosX < PATH_InlineGetUnitX(hTarget))
        {
            pPath->tTargetCoord.X -= 2;
        }
        else
        {
            pPath->tTargetCoord.X += 2;
        }
    }

    return 2;
}

// 0x00649970
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown)
{
    if (!pPath)
    {
        return 0;
    }

    D2_ASSERT(pPath->pUnit == pUnit, LINE_PATH_UNIT);

    if (pPath->dwFlags & PATH_MISSILE_MASK)
    {
        return PATH_MissileToTarget(pPath, pUnit);
    }

    pPath->nCollidedWithMask = 0;
    D2UnitStrc* pTargetUnit = pPath->hTarget;
    if (pTargetUnit && (!CLIENTS_GetUnitX(pTargetUnit) || !CLIENTS_GetUnitY(pTargetUnit)))
    {
        return 0;
    }

    D2PathInfoStrc tPathInfo;
    D2PathPointStrc tStart;
    tStart.X = pPath->tGameCoords.wPosX;
    tStart.Y = pPath->tGameCoords.wPosY;
    tPathInfo.tStartCoord = tStart;
    if (tStart.X != 0 || tStart.Y != 0)
    {
        tPathInfo.nUnitSize = pPath->dwUnitSize;
        tPathInfo.nCollisionPattern = pPath->dwCollisionPattern;
        tPathInfo.pDynamicPath = pPath;
        tPathInfo.nCollisionMask = pPath->nMoveTestCollisionMask;
        tPathInfo.nDistMax = pPath->bDistMax;
        tPathInfo.nMinimumFScoreToEvaluate = pPath->nIDAStarInitFScore;
        tPathInfo.field_14 = PATH_UpdateTargetUnit(&tPathInfo);

        if (pPath->tTargetCoord.X != 0 || pPath->tTargetCoord.Y != 0)
        {
            tPathInfo.tTargetCoord = pPath->tTargetCoord;
            if (tPathInfo.tStartCoord.X != tPathInfo.tTargetCoord.X || tPathInfo.tStartCoord.Y != tPathInfo.tTargetCoord.Y)
            {
                const int nDeltaX = tPathInfo.tTargetCoord.X - tPathInfo.tStartCoord.X;
                const int nDeltaY = tPathInfo.tTargetCoord.Y - tPathInfo.tStartCoord.Y;
                if (nDeltaX <= PATH_MAX_DISTANCE && -nDeltaX <= PATH_MAX_DISTANCE && nDeltaY <= PATH_MAX_DISTANCE && -nDeltaY <= PATH_MAX_DISTANCE)
                {
                    tPathInfo.pStartRoom = pPath->pRoom;
                    tPathInfo.pTargetRoom = sub_00463740_FindRoomAtPoint(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y);
                    if (tPathInfo.pStartRoom && tPathInfo.pTargetRoom && (PATH_IsTargetDestinationAllowed(&tPathInfo, pUnit) || bAllowInTown))
                    {
                        tPathInfo.nPathType = pPath->eType;

                        D2UnitStrc* pPathTargetUnit = pPath->hTarget;
                        BOOL bRemovedTargetUnitFootprint = FALSE;
                        PATH_RemoveCollisionFootprintForUnit(pUnit, FALSE);
                        if (pPathTargetUnit && UNITS_GetUnitSizeX(pPathTargetUnit) && (pPath->dwFlags & PATH_UNKNOWN_FLAG_0x00800))
                        {
                            bRemovedTargetUnitFootprint = PATH_RemoveCollisionFootprintForUnit(pPathTargetUnit, FALSE);
                        }

                        BOOL bUpdatePath = PATH_TRUE;
                        if ((pPath->dwFlags & PATH_UNKNOWN_FLAG_0x01000)
                            && COLLISION_CheckAnyCollisionWithPattern(tPathInfo.pStartRoom, tPathInfo.tTargetCoord.X, tPathInfo.tTargetCoord.Y, pPath->dwCollisionPattern, pPath->nMoveTestCollisionMask))
                        {
                            bUpdatePath = PATH_PreparePathTargetForPathUpdate(&tPathInfo);
                        }

                        pPath->tFinalTargetCoord.X = tPathInfo.tTargetCoord.X;
                        pPath->dwCurrentPointIdx = 0;
                        pPath->tFinalTargetCoord.Y = tPathInfo.tTargetCoord.Y;
                        pPath->dwPathPoints = 0;

                        int nPathPoints;
                        if (bUpdatePath)
                        {
                            pPath->dwCurrentPointIdx = 0;
                            D2_ASSERT(!IsBadCodePtr((void*)gpfnPathFunctions[tPathInfo.nPathType]), LINE_PATH_FUNCTION);
                            nPathPoints = gpfnPathFunctions[tPathInfo.nPathType](&tPathInfo);
                        }
                        else
                        {
                            pPath->dwCurrentPointIdx = 0;
                            nPathPoints = 0;
                        }
                        pPath->dwPathPoints = nPathPoints;

                        D2_ASSERT(tPathInfo.tStartCoord.X == tStart.X && tPathInfo.tStartCoord.Y == tStart.Y, LINE_START_COORD);

                        if (bRemovedTargetUnitFootprint)
                        {
                            PATH_AddCollisionFootprintForUnit(pPath->hTarget);
                        }
                        PATH_AddCollisionFootprintForUnit(pUnit);

                        if (!pPath->dwPathPoints)
                        {
                            pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
                            return 0;
                        }

                        PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_TRUE, PATH_TRUE);
                        if (pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                        {
                            PATH_CheckPathInRoom(pPath);
                            pPath->unk0x38 = 0;
                            pPath->tPrevTargetCoord.X = pPath->tTargetCoord.X;
                            pPath->tPrevTargetCoord.Y = pPath->tTargetCoord.Y;
                            const unsigned int nFlags = pPath->dwFlags;
                            if (!(nFlags & PATH_UNKNOWN_FLAG_0x00010) && !pPath->hTarget)
                            {
                                pPath->tTargetCoord.X = pPath->PathPoints[pPath->dwPathPoints - 1].X;
                                pPath->tTargetCoord.Y = pPath->PathPoints[pPath->dwPathPoints - 1].Y;
                            }

                            if (pPath->dwPathPoints)
                            {
                                pPath->dwFlags = nFlags | PATH_UNKNOWN_FLAG_0x00020;
                            }
                            else
                            {
                                pPath->dwFlags = nFlags & ~PATH_UNKNOWN_FLAG_0x00020;
                            }
                            return pPath->dwPathPoints;
                        }
                    }
                }
            }
        }
    }

    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    pPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00020;
    return 0;
}

// 0x00649CA0
void __stdcall D2Common_10214(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (pDynamicPath)
    {
        if (UNITS_GetRoom(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            pUnit->pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);
            PATH_AddCollisionFootprintForUnit(pUnit);
        }
        else
        {
            pUnit->pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);
        }
    }
}

// 0x00649F70
void __stdcall PATH_SetUnitDeadCollision(D2UnitStrc* pUnit, BOOL bForGameLogic)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (bForGameLogic || pUnit->dwUnitType != UNIT_MONSTER)
    {
        D2Common_10228(pUnit);
        COLLISION_SetMaskWithSizeXY(pPath->pRoom, pPath->wPosX, pPath->wPosY, PATH_CORPSE_SIZE, PATH_CORPSE_SIZE, COLLIDE_CORPSE);
    }
    else
    {
        PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
        pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
        PATH_SetFootprintCollisionMask(pPath, COLLIDE_CORPSE);
        PATH_AddCollisionFootprintForUnit(pUnit);
    }
    PATH_RecacheRoomIfNeeded(pPath);
}

// 0x00648AA0
D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->pPreviousRoom;
}

// 0x00648AB0
void __stdcall PATH_ClearNextRoom(D2DynamicPathStrc* pDynamicPath)
{
    pDynamicPath->pPreviousRoom = 0;
}

// 0x00648AD0
void __stdcall PATH_SetTargetPos(D2DynamicPathStrc* pDynamicPath, unsigned short nX, unsigned short nY)
{
    if (pDynamicPath)
    {
        pDynamicPath->tTargetCoord.X = nX;
        pDynamicPath->tTargetCoord.Y = nY;
        pDynamicPath->hTarget = 0;
    }
}

// 0x00648B00
void __stdcall PATH_SetTargetCoordFromClient(D2DynamicPathStrc* pDynamicPath, int nX, int nY)
{
    DUNGEON_ClientToGameCoords(&nX, &nY);
    nX >>= 11;
    nY >>= 11;
    pDynamicPath->tTargetCoord.X = nX;
    pDynamicPath->tTargetCoord.Y = nY;
}

// 0x00648B30
int __stdcall PATH_IsCurrentRoomInvalid(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwFlags & PATH_CURRENT_ROOM_INVALID;
}

// 0x00648B40
extern "C" void __stdcall PATH_SetCurrentRoomInvalid(D2DynamicPathStrc* pDynamicPath, int bInvalid)
{
    if (bInvalid)
    {
        pDynamicPath->dwFlags |= PATH_CURRENT_ROOM_INVALID;
    }
    else
    {
        pDynamicPath->dwFlags &= ~PATH_CURRENT_ROOM_INVALID;
    }
}

// 0x00648B60
void __stdcall PATH_SetUnusedFlag_0x00004(D2DynamicPathStrc* pDynamicPath, int bSet)
{
    if (bSet)
    {
        pDynamicPath->dwFlags |= PATH_UNUSED_FLAG_0x00004;
    }
    else
    {
        pDynamicPath->dwFlags &= ~PATH_UNUSED_FLAG_0x00004;
    }
}

// 0x00648B80
int __stdcall PATH_GetUnusedFlag_0x00004(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->dwFlags & PATH_UNUSED_FLAG_0x00004;
}

// 0x00648B90
extern "C" void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit)
{
    pDynamicPath->hTarget = pUnit;
    if (pUnit)
    {
        pDynamicPath->dwTargetType = pUnit->dwUnitType;
        pDynamicPath->dwTargetId = pUnit->dwUnitId;
    }
}

// 0x00648BB0
void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* ptPath, int* pTargetType, int* pTargetGUID)
{
    D2_ASSERT(ptPath->hTarget, 1984);

    *pTargetType = ptPath->dwTargetType;
    *pTargetGUID = ptPath->dwTargetId;
}

// 0x00648BF0
D2UnitStrc* __stdcall PATH_GetTargetUnit(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->hTarget;
}

// 0x00648C10
unsigned int __stdcall PATH_GetFootprintCollisionMaskExported(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0xFFFF;
    }
    return pDynamicPath->nFootprintCollisionMask;
}

// 0x00648C30
void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask)
{
    D2PathPointStrc tPosition;
    tPosition.X = pDynamicPath->tGameCoords.wPosX;
    tPosition.Y = pDynamicPath->tGameCoords.wPosY;

    if (pDynamicPath->pRoom)
    {
        if (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MISSILE)
        {
            COLLISION_ResetMaskWithSize(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwUnitSize, pDynamicPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_ResetMaskWithPattern(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwCollisionPattern, pDynamicPath->nFootprintCollisionMask);
        }
    }

    pDynamicPath->nFootprintCollisionMask = nCollisionMask;

    if (pDynamicPath->pRoom)
    {
        if (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MISSILE)
        {
            COLLISION_SetMaskWithSize(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwUnitSize, nCollisionMask);
        }
        else
        {
            COLLISION_SetMaskWithPattern(pDynamicPath->pRoom, tPosition.X, tPosition.Y, pDynamicPath->dwCollisionPattern, nCollisionMask);
        }
    }
}

// 0x00648CD0
unsigned int __stdcall PATH_GetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nMoveTestCollisionMask;
}

// 0x00648CE0
void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask)
{
    pDynamicPath->nMoveTestCollisionMask = nCollisionMask;
}

// 0x00648DC0
void __stdcall PATH_ResetToPreviousType(D2DynamicPathStrc* pDynamicPath)
{
    D2_ASSERT(pDynamicPath->pUnit, 2174);

    if (pDynamicPath->dwFlags & PATH_WITH_PREVIOUS_VELOCITY)
    {
        pDynamicPath->dwVelocity = pDynamicPath->nPreviousVelocity;
    }

    if (pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER)
    {
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
    }
    else if (pDynamicPath->dwFlags & PATH_UNKNOWN_FLAG_0x02000)
    {
        PATH_SetType(pDynamicPath, pDynamicPath->ePrevType);
    }
}

// 0x00648E30
int __stdcall PATH_GetType(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->eType;
}

// 0x00648E40
void __stdcall PATH_SetDist(D2DynamicPathStrc* pDynamicPath, unsigned char nDist)
{
    pDynamicPath->nDist = nDist;
}

// 0x00648E60
unsigned char __stdcall D2COMMON_10191_PATH_GetDistance(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nDist;
}

// 0x00648E70
extern "C" void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance)
{
    if (pDynamicPath)
    {
        if (nNewDistance >= 0x4D)
        {
            nNewDistance = 0x4D;
        }

        pDynamicPath->bDistMax = nNewDistance;
        pDynamicPath->nDist = nNewDistance;
    }
}

// 0x00648EA0
unsigned char __stdcall PATH_GetMaxDistance(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->bDistMax;
}

// 0x00648EB0
unsigned short __stdcall PATH_GetCollidedWithMask(D2DynamicPathStrc* pDynamicPath)
{
    if (pDynamicPath->dwVelocity == 0)
    {
        pDynamicPath->nCollidedWithMask = COLLISION_CheckMaskWithSize(pDynamicPath->pRoom, pDynamicPath->wPosX, pDynamicPath->wPosY, pDynamicPath->dwUnitSize, 0x7FFF);
    }
    return pDynamicPath->nCollidedWithMask;
}

// 0x00648EF0
unsigned short __stdcall D2Common_10202(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nCollidedWithMask;
}

// 0x00648F00
void __stdcall PATH_SetIDAStarInitFScore(D2DynamicPathStrc* ptPath, int nIDAStarInitFScore)
{
    D2_ASSERT(ptPath->eType == PATHTYPE_IDASTAR, 2280);

    ptPath->nIDAStarInitFScore = nIDAStarInitFScore;
}

// 0x00648F40
int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc* ptPath, D2PathPointStrc** ppPathPoints)
{
    D2_ASSERT(ptPath->dwFlags & PATH_SAVE_STEPS_MASK, 2292);

    *ppPathPoints = ptPath->SavedSteps;
    return ptPath->nSavedStepsCount;
}

// 0x00648F90
int __stdcall D2COMMON_10199_PathGetSaveX(D2DynamicPathStrc* ptPath)
{
    D2_ASSERT(ptPath->dwFlags & PATH_SAVE_STEPS_MASK, 2306);

    if (ptPath->nSavedStepsCount)
    {
        return ptPath->SavedSteps[ptPath->nSavedStepsCount - 1].X;
    }

    return 0;
}

// 0x00648FE0
int __stdcall D2COMMON_10200_PathGetSaveY(D2DynamicPathStrc* ptPath)
{
    D2_ASSERT(ptPath->dwFlags & PATH_SAVE_STEPS_MASK, 2321);

    if (ptPath->nSavedStepsCount)
    {
        return ptPath->SavedSteps[ptPath->nSavedStepsCount - 1].Y;
    }

    return 0;
}

// 0x00649030
void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pDynamicPath, int bReset)
{
    if (pDynamicPath)
    {
        if (!bReset)
        {
            pDynamicPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00040;
        }
        else
        {
            pDynamicPath->dwFlags &= ~PATH_UNKNOWN_FLAG_0x00040;
        }
    }
}

// 0x00649050
void __stdcall PATH_ClearPreviousTargetPoint(D2DynamicPathStrc* pDynamicPath)
{
    pDynamicPath->tPrevTargetCoord.X = 0;
    pDynamicPath->tPrevTargetCoord.Y = 0;
}

// 0x00649070
void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps)
{
    if (pDynamicPath)
    {
        if (nSteps >= 1 && nSteps <= 19)
        {
            pDynamicPath->nStepNum = nSteps - 1;
        }
        else
        {
            pDynamicPath->nStepNum = 0;
        }
    }
}

// 0x006490A0
int __stdcall PATH_GetStepNum(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nStepNum + 1;
}

// 0x006490C0
void __stdcall D2Common_10207(D2DynamicPathStrc* pDynamicPath, char a2, char dwSpeed)
{
    pDynamicPath->unk0x67 = a2;
    pDynamicPath->dwSpeed = dwSpeed;
}

// 0x006490E0
void __stdcall PATH_SetDistance(D2DynamicPathStrc* pDynamicPath, int nDist)
{
    D2_ASSERT(nDist >= 0 && nDist <= 255, 2405);

    pDynamicPath->nDistance = nDist;
}

// 0x00649120
int __stdcall PATH_GetDistance(D2DynamicPathStrc* pDynamicPath)
{
    return pDynamicPath->nDistance;
}

inline int __fastcall UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int __fastcall UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00649400
void __stdcall PATH_AddCollisionFootprintForUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    switch (nType)
    {
    case 0:
    case 1:
    {
        const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
        COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
        break;
    }

    case 2:
        COLLISION_SetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPosition(pUnit), CLIENTS_GetUnitY(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
        break;

    default:
        COLLISION_SetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        break;
    }
}

// 0x00649560
int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    switch (nType)
    {
    case 0:
        if ((pUnit && pUnit->dwAnimMode != 17 && pUnit->dwAnimMode != 0) || bForce)
        {
ResetPattern:
            const int nCollisionPattern = pUnit->pDynamicPath->dwCollisionPattern;
            COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), nCollisionPattern, UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    case 1:
        if ((pUnit && pUnit->dwAnimMode != 12 && pUnit->dwAnimMode != 0) || bForce)
        {
            goto ResetPattern;
        }
        break;

    case 2:
        if (UNITS_HasCollision(pUnit) || bForce)
        {
            COLLISION_ResetMaskWithSizeXY(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetUnitSizeY(pUnit), UNITS_GetCollisionMask(pUnit));
            return 1;
        }
        break;

    default:
        COLLISION_ResetMaskWithSize(UNITS_GetRoom(pUnit), UNITS_GetXPositionInl(pUnit), UNITS_GetYPositionInl(pUnit), UNITS_GetUnitSizeX(pUnit), UNITS_GetCollisionMask(pUnit));
        return 1;
    }

    return 0;
}

// 0x00649760
static int PATH_MissileToTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit)
{
    switch (pPath->eType)
    {
    case 4:
        if (PATH_ComputePathClassicMissile(pPath))
        {
            pPath->dwFlags |= 0x20;
            return pPath->dwPathPoints;
        }
        pPath->dwFlags &= ~0x20;
        return 0;
    case 10:
        PATH_ComputePathChargedBolt(pPath, &pUnit->pSeed);
        pPath->dwFlags |= 0x20;
        return pPath->dwPathPoints;
    case 14:
        PATH_ComputePathBlessedHammer(pPath, &pUnit->pSeed);
        pPath->dwFlags |= 0x20;
        return pPath->dwPathPoints;
    default:
        FOG_DisplayHalt("", sub_00408090(), 0x207);
        exit(-1);
    }
}

// 0x006498A0
static unsigned char PATH_UpdateTargetUnit(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    D2UnitStrc* pPathTargetUnit = pPath->hTarget;
    if (pPathTargetUnit)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPathTargetUnit);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPathTargetUnit);

        if (pPath->tTargetCoord.X == 0 && pPath->tTargetCoord.Y == 0)
        {
            return 0;
        }

        switch (pPathTargetUnit->dwUnitType)
        {
        case UNIT_ITEM:
            return 2;

        case UNIT_OBJECT:
            if (!UnitIsDoor(pPathTargetUnit))
            {
                return 2;
            }
            return PATH_AdvanceToDoor(pPathInfo);

        case UNIT_PLAYER:
        case UNIT_MONSTER:
            if (pPath->dwSpeed)
            {
                PATHUTIL_AdvanceTowardsTarget(pPath);
            }
            return 1;

        default:
            return 1;
        }
    }
    return 1;
}

// 0x00649140
void __stdcall PATH_AddToDistance(D2DynamicPathStrc* pDynamicPath, int nAddition)
{
    const int nDistance = pDynamicPath->nDistance + nAddition;
    if (nDistance < 0)
    {
        pDynamicPath->nDistance = 0;
    }
    else if (nDistance > 255)
    {
        pDynamicPath->nDistance = 255;
    }
    else
    {
        pDynamicPath->nDistance = nDistance;
    }
}

// 0x006491B0
void __stdcall D2COMMON_10212_PATH_SetMoveFlags(D2UnitStrc* pUnit, int bSet)
{
    D2DynamicPathStrc* ptPath = pUnit->pDynamicPath;

    D2_ASSERT(ptPath, 2466);

    if (bSet)
    {
        pUnit->dwFlagEx |= UNITFLAGEX_UNK_PATH_RELATED;
    }
    else
    {
        pUnit->dwFlagEx &= ~UNITFLAGEX_UNK_PATH_RELATED;
    }
    ptPath->unk0x38 = 0;
}

// 0x00649210
void __stdcall D2Common_10213(D2UnitStrc* pUnit)
{
    if (pUnit && !UNIT_HasFlag(pUnit, UNITFLAG_ISASYNC) && UNIT_HasFlagEx(pUnit, UNITFLAGEX_UNK_PATH_RELATED))
    {
        D2DynamicPathStrc* ptPath = pUnit->pDynamicPath;
        D2_ASSERT(ptPath, 2485);

        ++ptPath->unk0x38;
        if ((int)ptPath->unk0x38 > 1)
        {
            ptPath->unk0x38 = 0;
            if (!D2Common_10227(pUnit))
            {
                if (D2Common_10236(pUnit, PATH_GetTargetUnit(pUnit->pDynamicPath) != 0))
                {
                    UNITS_ChangeAnimMode(pUnit, 2);
                }
            }
        }
    }
}

inline unsigned int PATH_ToFP16Center(int nValue)
{
    return (nValue << 16) + 0x8000;
}

// 0x00649D00
void __stdcall PATH_AllocDynamicPath(D2PoolSystemStrc* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag)
{
    D2DynamicPathStrc* pDynamicPath = (D2DynamicPathStrc*)FOG_AllocPool(pMemPool, sizeof(D2DynamicPathStrc), ".\\PATH\\Path.cpp", 1107, 0);
    memset(pDynamicPath, 0, sizeof(D2DynamicPathStrc));

    pUnit->pDynamicPath = pDynamicPath;
    pDynamicPath->pUnit = pUnit;
    pDynamicPath->dwUnitSize = UNITS_GetUnitSizeX(pUnit);
    pDynamicPath->dwCollisionPattern = D2Common_11281_CollisionPatternFromSize(pUnit, pDynamicPath->dwUnitSize);

    pDynamicPath->dwPrecisionX = PATH_ToFP16Center(nX);
    pDynamicPath->dwPrecisionY = PATH_ToFP16Center(nY);
    pDynamicPath->dwVelocity = 2048;
    pDynamicPath->pRoom = pRoom;
    pDynamicPath->nStepNum = 0;
    pDynamicPath->nSavedStepsCount = 1;
    pDynamicPath->SavedSteps[0].X = nX;
    pDynamicPath->SavedSteps[0].Y = nY;

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        pDynamicPath->nFootprintCollisionMask = COLLIDE_PLAYER;
        pDynamicPath->nMoveTestCollisionMask = COLLIDE_MASK_PLAYER_PATH;
        PATH_SetType(pDynamicPath, PATHTYPE_STRAIGHT);
        pDynamicPath->bDistMax = 73;
        pDynamicPath->nIDAStarInitFScore = 70;
        break;

    case UNIT_MONSTER:
    {
        pDynamicPath->nFootprintCollisionMask = COLLIDE_MONSTER;

        D2_ASSERT(!(pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER), 2145);
        pDynamicPath->dwFlags &= 0xFFF800FF;
        pDynamicPath->eType = PATHTYPE_TOWARD;
        pDynamicPath->nDirOffset = 0;
        D2_ASSERT(pDynamicPath->ePrevType != PATHTYPE_KNOCKBACK_CLIENT, 2161);
        D2_ASSERT(pDynamicPath->ePrevType != PATHTYPE_KNOCKBACK_SERVER, 2162);

        const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            switch (nBaseId)
            {
            case MONSTER_WRAITH1:
                pUnit->pDynamicPath->dwCollisionPattern = COLLISION_PATTERN_SMALL_NO_PRESENCE;
                pDynamicPath->nMoveTestCollisionMask = COLLIDE_MISSILE_BARRIER | COLLIDE_DOOR;
                pDynamicPath->bDistMax = 14;
                break;

            default:
                pDynamicPath->nMoveTestCollisionMask = PATH_GetMonsterMoveTestMask(pUnit);
                pDynamicPath->bDistMax = 14;
                break;
            }
        }
        else
        {
            pDynamicPath->nMoveTestCollisionMask = PATH_GetMonsterMoveTestMask(pUnit);
            pDynamicPath->bDistMax = 14;
        }
        break;
    }

    case UNIT_MISSILE:
        pDynamicPath->nFootprintCollisionMask = 0;
        pDynamicPath->nMoveTestCollisionMask = 0;
        PATH_SetType(pDynamicPath, PATHTYPE_MISSILE);
        break;
    }

    if (pRoom)
    {
        PATH_AddCollisionFootprintForUnit(pUnit);
        UNITROOM_AddUnitToRoom(pUnit, pDynamicPath->pRoom);
    }

    int nClientX = pDynamicPath->dwPrecisionX >> 11;
    int nClientY = pDynamicPath->dwPrecisionY >> 11;
    DUNGEON_GameToClientCoords(&nClientX, &nClientY);
    pDynamicPath->dwClientCoordX = nClientX;
    pDynamicPath->dwClientCoordY = nClientY;

    if (bSetFlag)
    {
        pDynamicPath->dwFlags |= PATH_UNKNOWN_FLAG_0x00010;
    }
}

// 0x00649EF0
void __stdcall D2Common_10216(D2DynamicPathStrc* pDynamicPath, int nX, int nY, int bSetBothDirections)
{
    if (pDynamicPath)
    {
        D2FP32_16 tTarget;
        tTarget.dwPrecisionX = (nX << 16) + 0x8000;
        tTarget.dwPrecisionY = (nY << 16) + 0x8000;
        const int nDirection = PATH_ComputeDirectionFromPreciseCoords(pDynamicPath->tGameCoords, tTarget);
        if (bSetBothDirections)
        {
            pDynamicPath->nDirection = nDirection & 0x3F;
            pDynamicPath->nNewDirection = nDirection & 0x3F;
        }
        else
        {
            PATH_SetNewDirection(pDynamicPath, nDirection);
        }
    }
}

// 0x00648CF0
void __stdcall PATH_SetType(D2DynamicPathStrc* ptPath, int eType)
{
    D2_ASSERT(!(ptPath->pUnit && ptPath->pUnit->dwUnitType == UNIT_PLAYER && eType == 2), 0x861);

    int nFlag = gaPathTypeFlags[eType];
    if ((nFlag & 0x2000) && !(ptPath->dwFlags & 0x4000))
    {
        ptPath->ePrevType = ptPath->eType;
    }

    if ((nFlag & 0x8000) && !(ptPath->dwFlags & 0x10000))
    {
        ptPath->nPreviousVelocity = ptPath->dwVelocity;
    }

    ptPath->eType = eType;
    ptPath->dwFlags = nFlag | ptPath->dwFlags & 0xFFF800FF;
    ptPath->nDirOffset = gaOffsetForPathType[eType];

    D2_ASSERT(ptPath->ePrevType != 0xB, 0x871);
    D2_ASSERT(ptPath->ePrevType != 8, 0x872);
    D2_ASSERT((eType != 4) || (ptPath->bDistMax < 78), 0x873);
}

int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath)
{
    if (!pDynamicPath)
    {
        return 0xFFFF;
    }

    return pDynamicPath->nFootprintCollisionMask;
}

static __forceinline int sub_00649FF0_GetCollisionPattern(D2UnitStrc* pUnit)
{
    int nPattern = D2Common_11281_CollisionPatternFromSize(pUnit, UNITS_GetUnitSizeX(pUnit));
    const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
    if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        switch (nBaseId)
        {
        case MONSTER_WRAITH1:
        case MONSTER_BIRD1:
        case MONSTER_BIRD2:
        case MONSTER_PARROT:
            nPattern = 5;
            break;
        }
    }
    return nPattern;
}

// 0x00649FF0
void __stdcall PATH_SetUnitAliveCollision(D2UnitStrc* pUnit, int bSkip)
{
    if (bSkip)
    {
        return;
    }

    int nValue = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nValue == UNIT_MONSTER, 1346);

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (PATH_GetFootprintCollisionMask(pDynamicPath) == 0x8000)
    {
        nValue = sub_00649FF0_GetCollisionPattern(pUnit);
        if (UNITS_GetRoom(pUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
            pUnit->pDynamicPath->dwCollisionPattern = nValue;
            PATH_SetFootprintCollisionMask(pDynamicPath, 0x100);
            PATH_AddCollisionFootprintForUnit(pUnit);
        }
        else
        {
            pUnit->pDynamicPath->dwCollisionPattern = nValue;
            PATH_SetFootprintCollisionMask(pDynamicPath, 0x100);
        }
    }
}

// 0x006492A0
extern "C" __declspec(dllexport) int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2) {
    int nDX = nX2 - nX1;
    int nDY = nY2 - nY1;
    return nDX * nDX + nDY * nDY;
}

// 0x006492C0
int __stdcall D2Common_10237(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    return pDynamicPath->dwCurrentPointIdx < pDynamicPath->dwPathPoints;
}

// 0x006492F0
static int PATH_ComputePathClassicMissile(D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tOldCoords;
    tOldCoords.X = pPath->tGameCoords.wPosX;
    tOldCoords.Y = pPath->tGameCoords.wPosY;

    pPath->dwCurrentPointIdx = 0;

    if (pPath->hTarget)
    {
        pPath->tTargetCoord.X = PATH_InlineGetUnitX(pPath->hTarget);
        pPath->tTargetCoord.Y = PATH_InlineGetUnitY(pPath->hTarget);
    }

    int nXDistance = tOldCoords.X - pPath->tTargetCoord.X;
    if (nXDistance < 0)
    {
        nXDistance = -nXDistance;
    }
    if (nXDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    int nYDistance = tOldCoords.Y - pPath->tTargetCoord.Y;
    if (nYDistance < 0)
    {
        nYDistance = -nYDistance;
    }
    if (nYDistance >= PATH_MAX_DISTANCE)
    {
        return 0;
    }

    if (!pPath->tTargetCoord.X || !pPath->tTargetCoord.Y)
    {
        return 0;
    }

    pPath->PathPoints[0] = pPath->tTargetCoord;
    pPath->dwPathPoints = PATH_ONE;
    pPath->unk0x38 = 0;
    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, PATH_ONE, PATH_ONE);

    D2ActiveRoomStrc* pRoom = pPath->pRoom;
    if (!pRoom
        || !(pPath->tTargetCoord.X >= pRoom->tCoords.nSubtileX && pPath->tTargetCoord.X < pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
            && pPath->tTargetCoord.Y >= pRoom->tCoords.nSubtileY && pPath->tTargetCoord.Y < pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight))
    {
        pPath->dwFlags |= PATH_ONE;
    }
    return pPath->dwPathPoints;
}

// 0x0066A280
void __fastcall D2COMMON_10916_Return()
{
}

extern "C" void __cdecl PATH_AStar_ComputePath(); // 0x0067B850
extern "C" void __cdecl PATH_BackupTurn_Compute(); // 0x00679E60
extern "C" void __cdecl PATH_Knockback_Client(); // 0x00679FD0
extern "C" void __cdecl PATH_Straight_Compute(); // 0x00679ED0
extern "C" void __cdecl sub_00679C80(); // 0x00679C80
extern "C" void __cdecl sub_00679E50(); // 0x00679E50
extern "C" void __cdecl sub_00679F70(); // 0x00679F70
extern "C" void __cdecl sub_0067A000(); // 0x0067A000
extern "C" void __cdecl sub_0067AD00(); // 0x0067AD00
extern "C" void __cdecl sub_0067C2D0(); // 0x0067C2D0

#pragma pack(push, 1)
struct d2data_006EB3D8_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007457B0_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" const struct d2data_006EB3D8_t gData_006EB3D8; // 0x006EB3D8
extern "C" struct d2data_007457B0_t gData_007457B0; // 0x007457B0
extern "C" const int gData_006EB548[64]; // 0x006EB548
extern "C" const int gData_006EB648[18]; // 0x006EB648
extern "C" const int gData_006EB690[18]; // 0x006EB690

extern "C" const struct d2data_006EB3D8_t gData_006EB3D8 = {
    { 0x00 }
}; // 0x006EB3D8

extern const int gaCollisionPatternsFromSize[4] = { 0, 1, 1, 2 }; // 0x006EB3DC

extern "C" struct d2data_007457B0_t gData_007457B0 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x007457B0

extern const int gaOffsetsForSnappingToCardinalDirection[9][9] = {
    { -1, 0, 0, 0, 0, 0, 0, 0, 1 },
    { -1, -1, 0, 0, 0, 0, 0, 1, 1 },
    { -1, -1, -1, 0, 0, 0, 1, 1, 1 },
    { -1, -1, -1, -1, 0, 1, 1, 1, 1 },
    { -1, -1, -1, -1, 0, 1, 1, 1, 1 },
    { -1, -1, -1, -1, 0, 1, 1, 1, 1 },
    { -1, -1, -1, 0, 0, 0, 1, 1, 1 },
    { -1, -1, 0, 0, 0, 0, 0, 1, 1 },
    { -1, 0, 0, 0, 0, 0, 0, 0, 1 }
}; // 0x006EB3F0

extern const D2CoordStrc gaDirectionToOffset[8] = {
    { 1 },
    { 1, 1 },
    { 0, 1 },
    { -1, 1 },
    { -1 },
    { -1, -1 },
    { 0, -1 },
    { 1, -1 }
}; // 0x006EB398

extern "C" const int gData_006EB548[64] = {
    0, 1, 1, 1, 1, 1, 1, 1, 1, 4, 4, 4, 4, 4, 4, 4,
    4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
    -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8, -8,
    -4, -4, -4, -4, -4, -4, -4, -4, -1, -1, -1, -1, -1, -1, -1, -1
}; // 0x006EB548
#pragma comment(linker, "/alternatename:?gnDirectionDiffTable@@3PAHA=_gData_006EB548")

extern "C" const int gData_006EB648[18] = { 0, 0, 0, 0, 0, 2, -2, 0, 0, 0, 0, 0, -4 }; // 0x006EB648
#pragma comment(linker, "/alternatename:?gaOffsetForPathType@@3PAHA=_gData_006EB648")

extern "C" const int gData_006EB690[18] = { 137472, 6400, 0, 0, 393216, 0, 0, 137472, 124416, 124928, 393216, 124420, 0, 256, 393216, 2048 }; // 0x006EB690
#pragma comment(linker, "/alternatename:?gaPathTypeFlags@@3PAHA=_gData_006EB690")

extern PATH_FUNCTION const gpfnPathFunctions[17] = {
    (PATH_FUNCTION)&sub_0067AD00, (PATH_FUNCTION)&PATH_AStar_ComputePath, (PATH_FUNCTION)&sub_00679C80, (PATH_FUNCTION)&sub_00679E50, 0, (PATH_FUNCTION)&sub_00679C80, (PATH_FUNCTION)&sub_00679C80, (PATH_FUNCTION)&PATH_Straight_Compute, (PATH_FUNCTION)&sub_0067A000, (PATH_FUNCTION)&sub_00679F70, 0, (PATH_FUNCTION)&PATH_Knockback_Client, (PATH_FUNCTION)&PATH_BackupTurn_Compute, (PATH_FUNCTION)&sub_00679C80, 0, (PATH_FUNCTION)&sub_0067C2D0,
    (PATH_FUNCTION)&sub_0067AD00
}; // 0x006EB6D8
