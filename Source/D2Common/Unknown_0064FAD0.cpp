#include "D2Common.h"
#include "D2StormLink.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Structs.h"

#include "D2Txt.h"

#include "D2Drlg.h"

#include "D2AnimData.h"
#include "FogApi.h"
#include "D2ClientApi.h"

#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2InventoryStrc;

struct D2CoordStrc;

union D2FP32_16;

struct D2DrlgCoordsStrc;

struct D2AnimDataRecordStrc;

struct D2MonStatsTxt;

extern int gaTanToDirectionTable[128 * 3]; // 0x006EB7E0

typedef int BOOL;

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const D2CoordStrc gtPathZeroVelocity; // 0x006EB7D4

void __stdcall COLLISION_ResetMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, int nMask); // 0x0064EBA0

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

unsigned short __fastcall COLLISION_TryMoveUnitCollisionMask(D2ActiveRoomStrc* pRoom, int nX1, int nY1, int nX2, int nY2, int nUnitSize, int nCollisionMask, int nMoveConditionMask); // 0x0064ED20

unsigned short __fastcall COLLISION_TryTeleportUnitCollisionMask(D2ActiveRoomStrc* pRoom, int nX1, int nY1, int nX2, int nY2, int nCollisionPattern, int nFootprintCollisionMask, int nMoveConditionMask); // 0x0064EDA0

unsigned short __fastcall COLLISION_ForceTeleportUnitCollisionMaskAndGetCollision(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nUnitSize, int nFootprintCollisionMask, int nMoveConditionMask); // 0x0064EE70

unsigned short __fastcall COLLISION_TeleportUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nUnitSize, int nMask); // 0x0064EED0

int __fastcall COLLISION_TrySetUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nCollisionPattern, int nFootprintCollisionMask, int nMoveConditionMask); // 0x0064EF10

void __fastcall COLLISION_SetUnitCollisionMask(D2ActiveRoomStrc* pRoom1, int nX1, int nY1, D2ActiveRoomStrc* pRoom2, int nX2, int nY2, int nCollisionPattern, int nCollisionMask); // 0x0064EFA0



void __fastcall PATH_NormalizeStep(int* pX, int* pY); // 0x00678F00

void __fastcall PATHUTIL_GetTargetPathPoint(D2PathPointStrc* pOutPathPoint, D2DynamicPathStrc* pPath); // 0x00679250

inline BOOL DUNGEON_TestRoomGame(D2ActiveRoomStrc* pRoom, unsigned short nX, unsigned short nY)
{
    return nX >= pRoom->tCoords.nSubtileX && nX < pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
        && nY >= pRoom->tCoords.nSubtileY && nY < pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight;
}

inline void PATHMISC_SetRoom(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pNewRoom)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    pPath->pPreviousRoom = pPath->pRoom;
    if (pPath->pRoom)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }

    pPath->dwFlags |= 2;
    pPath->pRoom = pNewRoom;
    if (pNewRoom)
    {
        UNITROOM_AddUnitToRoom(pUnit, pNewRoom);
        UNITROOM_RefreshUnit(pUnit);
    }
}

BOOL __stdcall PATH_GetStepToNextPoint(D2CoordStrc* pVelocity, D2DynamicPathStrc* pPath); // 0x00650090

static BOOL __stdcall PATH_TraceSteps(D2CoordStrc tDelta, D2FP32_16* pOutCoord, int* pSteps, D2DynamicPathStrc* pPath); // 0x00650150

BOOL PATH_CheckPathDone(D2DynamicPathStrc* pPath); // 0x006503F0

static BOOL __stdcall PATH_AdvanceOnPath(D2FP32_16* pOutCoord, int* pSteps, D2DynamicPathStrc* pPath); // 0x00650660

BOOL __stdcall D2Common_10226(D2UnitStrc* pUnit, int nBaseVelocity); // 0x00650840

static inline void SwapPrecision(unsigned int& a, unsigned int& b)
{
    unsigned int temp = a;
    a = b;
    b = temp;
}

// 0x0064FAD0
static void __stdcall PATH_RecacheRoom(D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath)
{
    unsigned short nX = pPath->tGameCoords.wPosX;
    unsigned short nY = pPath->tGameCoords.wPosY;
    if (pPath->pRoom && DUNGEON_TestRoomGame(pPath->pRoom, nX, nY))
    {
        return;
    }

    D2ActiveRoomStrc* pRoomAtLocation = sub_00463740_FindRoomAtPoint(pPath->pRoom, nX, nY);
    if (!pRoomAtLocation && pHintRoom)
    {
        pRoomAtLocation = sub_00463740_FindRoomAtPoint(pHintRoom, nX, nY);
    }

    if (pRoomAtLocation || !(pPath->dwFlags & 0x40000))
    {
        PATHMISC_SetRoom(pPath, pRoomAtLocation);
    }
    else
    {
        pPath->dwPathPoints = 0;
    }
}

// 0x0064FB90
static void __stdcall PATH_RecacheRoomAtCoordIfNeeded(D2FP32_16 tCoord, D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath)
{
    if ((pPath->dwFlags & 0x40000) && !sub_00463740_FindRoomAtPoint(pPath->pRoom, tCoord.dwPrecisionX >> 16, tCoord.dwPrecisionY >> 16))
    {
        pPath->dwPathPoints = 0;
        return;
    }

    pPath->tGameCoords.dwPrecisionX = tCoord.dwPrecisionX;
    pPath->tGameCoords.dwPrecisionY = tCoord.dwPrecisionY;

    int nX = tCoord.dwPrecisionX >> 11;
    int nY = tCoord.dwPrecisionY >> 11;
    DUNGEON_GameToClientCoords(&nX, &nY);
    pPath->dwClientCoordX = nX;
    pPath->dwClientCoordY = nY;

    if (pPath->pUnit && (pPath->dwFlags & 1))
    {
        PATH_RecacheRoom(pHintRoom, pPath);
    }
}

#define PATH_CURRENT_ROOM_INVALID 2

extern int gnPathResetPrecisionX; // 0x006EB7C8

extern int gnPathResetPrecisionY; // 0x006EB7CC

// 0x0064FC20
void __stdcall PATH_ResetDynamicPathRoom(D2DynamicPathStrc* pDynamicPath)
{
    const int nPrecisionX = gnPathResetPrecisionX;
    const int nPrecisionY = gnPathResetPrecisionY;

    pDynamicPath->tGameCoords.dwPrecisionX = nPrecisionX;
    pDynamicPath->dwClientCoordX = nPrecisionX;
    pDynamicPath->tGameCoords.dwPrecisionY = nPrecisionY;
    pDynamicPath->dwClientCoordY = nPrecisionY;
    pDynamicPath->dwPathPoints = 0;

    if (pDynamicPath->pRoom)
    {
        pDynamicPath->pPreviousRoom = pDynamicPath->pRoom;
        UNITROOM_RemoveUnitFromRoom(pDynamicPath->pUnit);
        pDynamicPath->dwFlags |= PATH_CURRENT_ROOM_INVALID;
    }
}

// 0x0064FC60
void __fastcall PATH_GetDirectionVector(D2CoordStrc* pDirectionVector, int* pOutDirection, D2FP32_16 tStart, D2FP32_16 tTarget)
{
    int bPositiveX;
    unsigned int dwMaxX;
    unsigned int dwMinX;
    if (tStart.dwPrecisionX <= tTarget.dwPrecisionX)
    {
        dwMaxX = tTarget.dwPrecisionX;
        dwMinX = tStart.dwPrecisionX;
        bPositiveX = 1;
    }
    else
    {
        dwMaxX = tStart.dwPrecisionX;
        dwMinX = tTarget.dwPrecisionX;
        bPositiveX = 0;
    }
    int bPositiveY;
    unsigned int dwMaxY;
    unsigned int dwMinY;
    if (tStart.dwPrecisionY <= tTarget.dwPrecisionY)
    {
        dwMaxY = tTarget.dwPrecisionY;
        dwMinY = tStart.dwPrecisionY;
        bPositiveY = 1;
    }
    else
    {
        dwMaxY = tStart.dwPrecisionY;
        dwMinY = tTarget.dwPrecisionY;
        bPositiveY = 0;
    }
    int bSwapped;
    if ((int)(dwMaxX - dwMinX) <= (int)(dwMaxY - dwMinY))
    {
        bSwapped = 0;
    }
    else
    {
        SwapPrecision(dwMaxX, dwMaxY);
        bSwapped = 1;
        SwapPrecision(dwMinX, dwMinY);
    }
    int nIndex;
    if ((int)(dwMaxY - dwMinY) != 0)
        nIndex = (int)(127 * (dwMaxX - dwMinX)) / (int)(dwMaxY - dwMinY);
    else
        nIndex = 0;
    const int nEntry = 3 * nIndex;
    int nDirection = gaTanToDirectionTable[nEntry + 2];
    if (bSwapped)
    {
        pDirectionVector->nY = gaTanToDirectionTable[nEntry];
        pDirectionVector->nX = gaTanToDirectionTable[nEntry + 1];
        nDirection = (-1 - nDirection) & 0x0F;
    }
    else
    {
        pDirectionVector->nX = gaTanToDirectionTable[nEntry];
        pDirectionVector->nY = gaTanToDirectionTable[nEntry + 1];
    }
    if (!bPositiveY)
    {
        pDirectionVector->nY = -pDirectionVector->nY;
        nDirection = (-1 - nDirection) & 0x1F;
    }
    if (bPositiveX)
    {
        nDirection = (-1 - nDirection) & 0x3F;
    }
    else
    {
        pDirectionVector->nX = -pDirectionVector->nX;
    }
    *pOutDirection = (nDirection + 8) & 0x3F;
}

#pragma pack(push, 1)
struct d2data_006EB7C8_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006EB7CC_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006EB7D0_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006EB7D4_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006EB7DC_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0074595C_t
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

extern "C" const struct d2data_006EB7C8_t gData_006EB7C8; // 0x006EB7C8
extern "C" const struct d2data_006EB7CC_t gData_006EB7CC; // 0x006EB7CC
extern "C" const struct d2data_006EB7D0_t gData_006EB7D0; // 0x006EB7D0
extern "C" const struct d2data_006EB7D4_t gData_006EB7D4; // 0x006EB7D4
extern "C" const struct d2data_006EB7DC_t gData_006EB7DC; // 0x006EB7DC
extern "C" const int gData_006EB7E0[128 * 3]; // 0x006EB7E0
extern "C" struct d2data_0074595C_t gData_0074595C; // 0x0074595C

extern "C" const struct d2data_006EB7C8_t gData_006EB7C8 = {
    { 0x00 }
}; // 0x006EB7C8
#pragma comment(linker, "/alternatename:?gnPathResetPrecisionX@@3HA=_gData_006EB7C8")

extern "C" const struct d2data_006EB7CC_t gData_006EB7CC = {
    { 0x00 }
}; // 0x006EB7CC
#pragma comment(linker, "/alternatename:?gnPathResetPrecisionY@@3HA=_gData_006EB7CC")

extern "C" const struct d2data_006EB7D0_t gData_006EB7D0 = {
    { 0x00 }
}; // 0x006EB7D0

extern "C" const struct d2data_006EB7D4_t gData_006EB7D4 = {
    { 0x00 }
}; // 0x006EB7D4
#pragma comment(linker, "/alternatename:?gtPathZeroVelocity@@3UD2CoordStrc@@B=_gData_006EB7D4")

extern "C" const struct d2data_006EB7DC_t gData_006EB7DC = {
    { 0x00 }
}; // 0x006EB7DC

extern "C" const int gData_006EB7E0[128 * 3] = {
    0, 4096, 0, 32, 4095, 0, 64, 4095, 0, 96, 4094, 0, 128, 4093, 0, 161,
    4092, 0, 193, 4091, 0, 225, 4089, 0, 257, 4087, 0, 289, 4085, 0, 321, 4083,
    0, 353, 4080, 0, 385, 4077, 0, 417, 4074, 1, 448, 4071, 1, 480, 4067, 1,
    511, 4063, 1, 543, 4059, 1, 574, 4055, 1, 606, 4050, 1, 637, 4046, 1, 668,
    4041, 1, 699, 4035, 1, 729, 4030, 1, 760, 4024, 1, 791, 4018, 1, 821, 4012,
    2, 851, 4006, 2, 881, 3999, 2, 911, 3993, 2, 941, 3986, 2, 971, 3979, 2,
    1000, 3971, 2, 1030, 3964, 2, 1059, 3956, 2, 1088, 3948, 2, 1117, 3940, 2, 1145,
    3932, 2, 1174, 3924, 2, 1202, 3915, 3, 1230, 3906, 3, 1258, 3897, 3, 1286, 3888,
    3, 1313, 3879, 3, 1340, 3870, 3, 1368, 3860, 3, 1394, 3851, 3, 1421, 3841, 3,
    1448, 3831, 3, 1474, 3821, 3, 1500, 3811, 3, 1526, 3800, 3, 1552, 3790, 3, 1577,
    3780, 4, 1602, 3769, 4, 1627, 3758, 4, 1652, 3747, 4, 1677, 3736, 4, 1701, 3725,
    4, 1725, 3714, 4, 1749, 3703, 4, 1773, 3692, 4, 1796, 3680, 4, 1820, 3669, 4,
    1843, 3657, 4, 1866, 3646, 4, 1888, 3634, 4, 1911, 3622, 4, 1933, 3610, 5, 1955,
    3599, 5, 1977, 3587, 5, 1998, 3575, 5, 2020, 3563, 5, 2041, 3551, 5, 2062, 3539,
    5, 2082, 3526, 5, 2103, 3514, 5, 2123, 3502, 5, 2143, 3490, 5, 2163, 3478, 5,
    2183, 3465, 5, 2202, 3453, 5, 2221, 3441, 5, 2240, 3428, 5, 2259, 3416, 5, 2278,
    3403, 6, 2296, 3391, 6, 2314, 3379, 6, 2332, 3366, 6, 2350, 3354, 6, 2368, 3341,
    6, 2385, 3329, 6, 2402, 3317, 6, 2419, 3304, 6, 2436, 3292, 6, 2453, 3279, 6,
    2469, 3267, 6, 2486, 3255, 6, 2502, 3242, 6, 2518, 3230, 6, 2533, 3218, 6, 2549,
    3205, 6, 2564, 3193, 6, 2580, 3181, 6, 2595, 3169, 6, 2609, 3156, 7, 2624, 3144,
    7, 2639, 3132, 7, 2653, 3120, 7, 2667, 3108, 7, 2681, 3096, 7, 2695, 3084, 7,
    2709, 3072, 7, 2722, 3060, 7, 2736, 3048, 7, 2749, 3036, 7, 2762, 3024, 7, 2775,
    3012, 7, 2788, 3000, 7, 2800, 2988, 7, 2813, 2977, 7, 2825, 2965, 7, 2837, 2953,
    7, 2849, 2942, 7, 2861, 2930, 7, 2873, 2919, 7, 2884, 2907, 7, 2896, 2896, 7
}; // 0x006EB7E0
#pragma comment(linker, "/alternatename:?gaTanToDirectionTable@@3PAHA=_gData_006EB7E0")

extern "C" struct d2data_0074595C_t gData_0074595C = {
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
}; // 0x0074595C
#include "D2CommonApi.h"

inline unsigned int PATH_ToFP16Center(unsigned int nValue)
{
    return (nValue << 16) + 0x8000;
}

inline unsigned int PATH_FP16FitToCenter(unsigned int nValue)
{
    return (nValue & 0xFFFF0000) + 0x8000;
}

inline D2FP32_16 PATH_MakeCoord(unsigned int nPrecisionX, unsigned int nPrecisionY)
{
    D2FP32_16 tCoord;
    tCoord.dwPrecisionX = nPrecisionX;
    tCoord.dwPrecisionY = nPrecisionY;
    return tCoord;
}

int GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

void __stdcall PATH_RecacheRoomAtCoordIfNeeded(D2FP32_16 tCoord, D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath); // 0x0064FB90



static inline unsigned short PATH_FromFP16(unsigned int nValue)
{
    return (nValue >> 16) & 0xFFFF;
}

// 0x0064FD70
void __fastcall PATH_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint)
{
    D2CoordStrc tStart;
    D2CoordStrc tTarget;
    tStart.nX = (tStartPoint.X << 16) + 0x8000;
    tStart.nY = (tStartPoint.Y << 16) + 0x8000;
    tTarget.nX = (tTargetPoint.X << 16) + 0x8000;
    tTarget.nY = (tTargetPoint.Y << 16) + 0x8000;
    PATH_GetDirectionVector(pDirectionVector, pOutDirection, *(D2FP32_16*)&tStart, *(D2FP32_16*)&tTarget);
}

// 0x0064FDC0
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2)
{
    D2CoordStrc tCoords;
    int nDirection;
    D2CoordStrc tStart;
    D2CoordStrc tTarget;
    tStart.nX = (nX1 << 16) + 0x8000;
    tStart.nY = (nY1 << 16) + 0x8000;
    tTarget.nX = (nX2 << 16) + 0x8000;
    tTarget.nY = (nY2 << 16) + 0x8000;
    PATH_GetDirectionVector(&tCoords, &nDirection, *(D2FP32_16*)&tStart, *(D2FP32_16*)&tTarget);
    return nDirection;
}

// 0x0064FE10
int __stdcall PATH_ComputeDirectionFromPreciseCoords(unsigned int dwStartPrecisionX, unsigned int dwStartPrecisionY, unsigned int dwTargetPrecisionX, unsigned int dwTargetPrecisionY)
{

    PATH_GetDirectionVector((D2CoordStrc*)&dwStartPrecisionX, (int*)&dwTargetPrecisionY, *(D2FP32_16*)&dwStartPrecisionX, *(D2FP32_16*)&dwTargetPrecisionX);

    return (int)dwTargetPrecisionY;
}

// 0x0064FE40
int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization)
{
    D2FP32_16* const ptGameCoords = &pPath->tGameCoords;
    D2FP32_16 tTarget;
    tTarget.dwPrecisionX = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].X);
    tTarget.dwPrecisionY = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].Y);
    while (tTarget.dwPrecisionX == ptGameCoords->dwPrecisionX && tTarget.dwPrecisionY == ptGameCoords->dwPrecisionY)
    {
        if (pPath->dwCurrentPointIdx >= pPath->dwPathPoints - 1)
        {
            const int nZeroX = gtPathZeroVelocity.nX;
            const int nZeroY = gtPathZeroVelocity.nY;
            pPath->tDirectionVector.nX = nZeroX;
            pPath->tDirectionVector.nY = nZeroY;
            pPath->tVelocityVector.nX = nZeroX;
            pPath->tVelocityVector.nY = nZeroY;
            pPath->dwCurrentPointIdx = pPath->dwPathPoints;
            pPath->dwVelocity = 0;
            return 1;
        }

        ++pPath->dwCurrentPointIdx;
        tTarget.dwPrecisionX = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].X);
        tTarget.dwPrecisionY = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].Y);
    }

    D2CoordStrc tDirectionVector;
    int nDirection;
    PATH_GetDirectionVector(&tDirectionVector, &nDirection, *ptGameCoords, tTarget);

    pPath->tDirectionVector.nX = tDirectionVector.nX;
    pPath->tDirectionVector.nY = tDirectionVector.nY;
    if (pPath->dwFlags & 0x200)
    {
        nDirection = (nDirection - 32) & 63;
    }

    pPath->tVelocityVector.nX = (pPath->dwVelocity * tDirectionVector.nX) >> 8;
    pPath->tVelocityVector.nY = (pPath->dwVelocity * tDirectionVector.nY) >> 8;

    const int bSame = PATH_FromFP16(tTarget.dwPrecisionX) == PATH_FromFP16(ptGameCoords->dwPrecisionX + pPath->tVelocityVector.nX)
        && PATH_FromFP16(tTarget.dwPrecisionY) == PATH_FromFP16(ptGameCoords->dwPrecisionY + pPath->tVelocityVector.nY);

    if (bForceDirectionNormalization || bSame && bNormalizeDirectionIfSamePos)
    {
        PATH_SetNewDirection(pPath, (unsigned char)nDirection);
    }

    return bSame;
}

inline BOOL PATH_IsZeroPoint(D2PathPointStrc tPoint)
{
    return tPoint.X == 0 && tPoint.Y == 0;
}

static void __stdcall PATH_RecacheRoomAtCoordIfNeeded(D2FP32_16 tCoord, D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath); // 0x0064FB90

// 0x0064FF90
static BOOL __stdcall PATH_TestStepCollision(D2PathPointStrc tNext, D2PathPointStrc tCurrent, D2DynamicPathStrc* pPath)
{
    if (pPath->dwFlags & 4)
    {
        D2_ASSERT(GAME_GetUnitTypeOrInvalid(pPath->pUnit) == 0 || GAME_GetUnitTypeOrInvalid(pPath->pUnit) == 1, 0x209);
        COLLISION_SetUnitCollisionMask(pPath->pRoom, tCurrent.X, tCurrent.Y, pPath->pRoom, tNext.X, tNext.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        return 1;
    }

    const unsigned int bMissile = pPath->dwFlags & 0x40000;
    int nMoveTestCollisionMask = pPath->nMoveTestCollisionMask;
    if (nMoveTestCollisionMask == 0x3401)
    {
        nMoveTestCollisionMask = 0x3C01;
    }

    if (bMissile)
    {
        pPath->nCollidedWithMask |= COLLISION_TryMoveUnitCollisionMask(pPath->pRoom, tCurrent.X, tCurrent.Y, tNext.X, tNext.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask, nMoveTestCollisionMask);
    }
    else
    {
        pPath->nCollidedWithMask |= COLLISION_TryTeleportUnitCollisionMask(pPath->pRoom, tCurrent.X, tCurrent.Y, tNext.X, tNext.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask, nMoveTestCollisionMask);
    }

    const unsigned short nCollidedWithMask = pPath->nCollidedWithMask;
    if (nCollidedWithMask && !bMissile)
    {
        return FALSE;
    }

    if (bMissile && (nCollidedWithMask & 5))
    {
        return FALSE;
    }

    return 1;
}



static void __stdcall PATH_RecacheRoomAtCoordIfNeeded(D2FP32_16 tCoord, D2ActiveRoomStrc* pHintRoom, D2DynamicPathStrc* pPath); // 0x0064FB90


// 0x00650090
static BOOL __stdcall PATH_GetStepToNextPoint(D2CoordStrc* pVelocity, D2DynamicPathStrc* pPath)
{
    *pVelocity = pPath->tVelocityVector;
    if (pPath->eType == 4)
    {
        return FALSE;
    }

    D2CoordStrc tTarget;
    tTarget.nX = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].X);
    tTarget.nY = PATH_ToFP16Center(pPath->PathPoints[pPath->dwCurrentPointIdx].Y);
    const int nDeltaX = tTarget.nX - pPath->tGameCoords.dwPrecisionX;
    const int nAbsDeltaX = D2_ABS(nDeltaX);
    const int nTargetDeltaY = tTarget.nY - pPath->tGameCoords.dwPrecisionY;
    const int nAbsDeltaY = D2_ABS(nTargetDeltaY);
    const int nMaxStep = D2_MAX(D2_ABS(pVelocity->nX), D2_ABS(pVelocity->nY));
    if (nAbsDeltaX > nMaxStep || nAbsDeltaY > nMaxStep)
    {
        return FALSE;
    }

    pVelocity->nX = nDeltaX;
    pVelocity->nY = tTarget.nY - pPath->tGameCoords.dwPrecisionY;
    return 1;
}

// 0x00650150
static BOOL __stdcall PATH_TraceSteps(D2CoordStrc tDelta, D2FP32_16* pOutCoord, int* pSteps, D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tCurrent;
    D2PathPointStrc tEnd;
    unsigned int bSaveSteps;
    D2CoordStrc tStep;
    D2FP32_16 tEndCoord;
    D2FP32_16 tNextCoord;

    pPath->nSavedStepsCount = 0;

    unsigned int dwX = tDelta.nX;
    unsigned int dwY = tDelta.nY;
    tStep.nX = dwX;
    tStep.nY = dwY;
    PATH_NormalizeStep(&tStep.nX, &tStep.nY);

    dwX = pPath->tGameCoords.dwPrecisionX;
    dwY = pPath->tGameCoords.dwPrecisionY;
    tCurrent.X = dwX >> 16;
    tCurrent.Y = dwY >> 16;
    tEndCoord = pPath->tGameCoords;
    tEndCoord.dwPrecisionY += tDelta.nY;
    tEndCoord.dwPrecisionX += tDelta.nX;
    tEnd.X = tEndCoord.dwPrecisionX >> 16;
    tEnd.Y = tEndCoord.dwPrecisionY >> 16;
    bSaveSteps = pPath->dwFlags & 0x20000;

    while (tCurrent.X != tEnd.X || tCurrent.Y != tEnd.Y)
    {
        tNextCoord.dwPrecisionX = dwX + tStep.nX;
        tNextCoord.dwPrecisionY = dwY + tStep.nY;
        D2PathPointStrc tNext;
        tNext.X = tNextCoord.dwPrecisionX >> 16;
        tNext.Y = tNextCoord.dwPrecisionY >> 16;

        if (tCurrent.X != tNext.X || tCurrent.Y != tNext.Y)
        {
            if (!PATH_TestStepCollision(tNext, tCurrent, pPath))
            {
                pOutCoord->dwPrecisionX = (dwX & 0xFFFF0000) + 0x8000;
                pOutCoord->dwPrecisionY = (dwY & 0xFFFF0000) + 0x8000;
                *pSteps = pPath->nSavedStepsCount;
                return TRUE;
            }

            if (bSaveSteps)
            {
                pPath->SavedSteps[pPath->nSavedStepsCount] = tNext;
            }

            ++pPath->nSavedStepsCount;
            if (pPath->nSavedStepsCount >= 10)
            {
                break;
            }
        }

        dwX = tNextCoord.dwPrecisionX;
        dwY = tNextCoord.dwPrecisionY;
        tCurrent = tNext;
    }

    if (pPath->nSavedStepsCount)
    {
        pPath->dwFlags |= 8;
    }

    *pOutCoord = tEndCoord;
    *pSteps = pPath->nSavedStepsCount;
    return FALSE;
}

void PATH_UpdateVelocity(int nBaseVelocity, D2DynamicPathStrc* pPath); // 0x006502D0

int __stdcall PATH_GetDistance(D2DynamicPathStrc* pDynamicPath); // 0x00649120

void __stdcall PATH_AddToDistance(D2DynamicPathStrc* pDynamicPath, int nAddition); // 0x00649140

static inline int UNITS_IsServerSide(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
    {
        bResult = (pUnit->dwFlags >> 21) & 1;
    }
    return bResult;
}

static inline int GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x006502D0
static void PATH_UpdateVelocity(int nBaseVelocity, D2DynamicPathStrc* pPath)
{
    if (nBaseVelocity <= 0)
    {
        nBaseVelocity = 0x400;
    }

    if (int nAcceleration = pPath->dwAcceleration)
    {
        pPath->dwAccelerationsCounter++;
        if (pPath->dwAccelerationsCounter >= 5)
        {
            pPath->dwVelocity = nAcceleration + pPath->dwVelocity;
            const int nMaxVelocity = pPath->dwMaxVelocity;
            if (pPath->dwVelocity > nMaxVelocity)
            {
                pPath->dwVelocity = nMaxVelocity;
                pPath->dwAcceleration = 0;
            }
            else if (pPath->dwVelocity < 0)
            {
                pPath->dwVelocity = 0;
            }

            pPath->dwAccelerationsCounter = 0;
        }
    }

    const int nVelocityMagnitude = (nBaseVelocity * pPath->dwVelocity) >> 6;
    pPath->tVelocityVector.nX = (nVelocityMagnitude * pPath->tDirectionVector.nX) >> 12;
    pPath->tVelocityVector.nY = (nVelocityMagnitude * pPath->tDirectionVector.nY) >> 12;
}

// 0x00650350
int __stdcall D2Common_10236(D2UnitStrc* pUnit, int a2)
{
    int nResult = 0;

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    if (!(pDynamicPath->dwFlags & 0x10))
    {
        const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (nType == 1 && !PATH_GetDistance(pUnit->pDynamicPath))
        {
            return 0;
        }

        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= 1;

        PATH_AddToDistance(pDynamicPath, -pDynamicPath->dwCurrentPointIdx);
    }

    switch (pDynamicPath->eType)
    {
    case 2:
    case 13:
    case 15:
        break;

    default:
        return D2Common_10142(pDynamicPath, pUnit, 0);
    }

    if (a2)
    {
        pDynamicPath->eType = 13;
    }
    else
    {
        pDynamicPath->eType = 2;
        pDynamicPath->tTargetCoord = pDynamicPath->tFinalTargetCoord;
    }

    nResult = D2Common_10142(pDynamicPath, pUnit, 0);
    if (!nResult)
    {
        pDynamicPath->eType = 15;
        nResult = D2Common_10142(pDynamicPath, pUnit, 0);
    }

    return nResult;
}

// 0x006503F0
static BOOL PATH_CheckPathDone(D2DynamicPathStrc* pDynamicPath)
{
    switch (pDynamicPath->eType)
    {
    case 5:
    case 6:
        if (pDynamicPath->dwCurrentPointIdx >= pDynamicPath->dwPathPoints)
        {
            return TRUE;
        }
        break;
    }

    D2UnitStrc* pTargetUnit = pDynamicPath->hTarget;
    D2UnitStrc* pUnit = pDynamicPath->pUnit;
    if (!pTargetUnit)
    {
        const int bAtEnd = pDynamicPath->dwCurrentPointIdx >= pDynamicPath->dwPathPoints;
        if (bAtEnd)
        {
            D2PathPointStrc tCoord;
            tCoord.X = pDynamicPath->tGameCoords.wPosX;
            tCoord.Y = pDynamicPath->tGameCoords.wPosY;
            if (tCoord.X != pDynamicPath->tFinalTargetCoord.X || tCoord.Y != pDynamicPath->tFinalTargetCoord.Y)
            {
                return D2Common_10236(pUnit, FALSE);
            }
        }
        return TRUE;
    }

    const int nDistance = D2Common_10399(pTargetUnit, pUnit);
    if (nDistance <= pDynamicPath->nStepNum)
    {
        return FALSE;
    }

    D2PathPointStrc tCoord;
    tCoord.X = pDynamicPath->tGameCoords.wPosX;
    tCoord.Y = pDynamicPath->tGameCoords.wPosY;

    D2PathPointStrc tTargetPoint;
    PATHUTIL_GetTargetPathPoint(&tTargetPoint, pDynamicPath);

    pTargetUnit = pDynamicPath->hTarget;
    if (pTargetUnit && pTargetUnit->dwUnitType >= 0 && pTargetUnit->dwUnitType <= 1)
    {
        const int nDiffX = pDynamicPath->tPrevTargetCoord.X - tTargetPoint.X;
        const int nDiffY = pDynamicPath->tPrevTargetCoord.Y - tTargetPoint.Y;
        if (D2_ABS(nDiffX) > 5 || D2_ABS(nDiffY) > 5)
        {
            return D2Common_10236(pUnit, TRUE);
        }
    }

    if (pDynamicPath->dwCurrentPointIdx < pDynamicPath->dwPathPoints
        || (pDynamicPath->tFinalTargetCoord.X == tCoord.X && pDynamicPath->tFinalTargetCoord.Y == tCoord.Y))
    {
        return TRUE;
    }
    return D2Common_10236(pUnit, TRUE);
}

// 0x006504F0
int __fastcall PATH_TestPathFlag10(D2UnitStrc* pUnit, D2DynamicPathStrc* pPath)
{
    switch (GAME_GetUnitTypeOrInvalid(pUnit))
    {
    case 0:
        if (!(pPath->dwFlags & 0x10))
        {
            return 0;
        }
        break;

    case 1:
        if (pPath->dwFlags & 0x10)
        {
            if (!UNITS_IsServerSide(pUnit))
            {
                return 0;
            }
        }
        break;
    }

    return 1;
}

// 0x00650540
int __stdcall D2Common_10227(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 1;
    }

    if (pDynamicPath->hTarget && D2Common_10399(pDynamicPath->hTarget, pUnit) <= pDynamicPath->nStepNum)
    {
        return 1;
    }

    return pDynamicPath->tGameCoords.wPosX == pDynamicPath->tTargetCoord.X && pDynamicPath->tGameCoords.wPosY == pDynamicPath->tTargetCoord.Y;
}

// 0x00650590
void __stdcall PATH_RecacheRoomIfNeeded(D2DynamicPathStrc* pPath)
{
    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionX), PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionY)), 0, pPath);
}

// 0x006505C0
int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc* pPath)
{
    if (!pPath)
    {
        return 0;
    }

    return pPath->dwFlags & 8;
}

// 0x006505E0
void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit)
{
    D2_ASSERT(pRiderUnit, 0x54E);
    D2_ASSERT(pMountUnit, 0x54F);

    D2DynamicPathStrc* pRiderPath = pRiderUnit->pDynamicPath;
    D2DynamicPathStrc* pMountPath = pMountUnit->pDynamicPath;
    if (pRiderPath->tGameCoords.wPosX == pMountPath->tGameCoords.wPosX && pRiderPath->tGameCoords.wPosY == pMountPath->tGameCoords.wPosY)
    {
        pRiderPath->dwFlags &= 0xFFFFFFF7;
    }
    else
    {
        pRiderPath->dwFlags |= 8;
    }

    if (pRiderPath->pRoom != pMountPath->pRoom)
    {
        pRiderPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(pMountPath->tGameCoords, pMountPath->pRoom, pRiderPath);
}

// 0x00650660
static BOOL __stdcall PATH_AdvanceOnPath(D2FP32_16* pOutCoord, int* pSteps, D2DynamicPathStrc* pPath)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    pPath->nCollidedWithMask = 0;
    *pSteps = 0;

    const BOOL bRepath = pUnit && pUnit->dwUnitType == UNIT_MONSTER && (pPath->dwFlags & 0x10);
    if (!pPath->tVelocityVector.nX && !pPath->tVelocityVector.nY)
    {
        pPath->dwPathPoints = 0;
        pPath->dwCurrentPointIdx = 0;
        pOutCoord->dwPrecisionX = PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionX);
        pOutCoord->dwPrecisionY = PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionY);
        return FALSE;
    }

    D2CoordStrc tVelocity;
    const BOOL bReachedPoint = PATH_GetStepToNextPoint(&tVelocity, pPath);
    const unsigned int nPrecX = pPath->tGameCoords.dwPrecisionX;
    const unsigned int nPrecY = pPath->tGameCoords.dwPrecisionY;
    D2FP32_16 tNewCoord;
    tNewCoord.dwPrecisionX = tVelocity.nX + nPrecX;
    tNewCoord.dwPrecisionY = tVelocity.nY + nPrecY;
    D2PathPointStrc tOld;
    tOld.X = nPrecX >> 16;
    tOld.Y = nPrecY >> 16;
    D2PathPointStrc tNew;
    tNew.X = tNewCoord.dwPrecisionX >> 16;
    tNew.Y = tNewCoord.dwPrecisionY >> 16;
    if (tOld.X != tNew.X || tOld.Y != tNew.Y)
    {
        if (pPath->nDist && pPath->eType != 8 && pPath->eType != 11)
        {
            --pPath->nDist;
        }

        if (PATH_TraceSteps(tVelocity, pOutCoord, pSteps, pPath))
        {
            if (bRepath)
            {
                return !D2Common_10236(pUnit, pPath->hTarget != 0);
            }

            pPath->dwCurrentPointIdx = pPath->dwPathPoints;
            return FALSE;
        }
    }

    *pOutCoord = tNewCoord;
    if (bReachedPoint)
    {
        ++pPath->dwCurrentPointIdx;
        return TRUE;
    }

    return FALSE;
}

void PATH_ResetMovement(D2DynamicPathStrc* pPath); // 0x006507B0

BOOL __stdcall PATH_UpdateCollisionMask(D2ActiveRoomStrc* pDestRoom, D2PathPointStrc tDest, D2DynamicPathStrc* pPath); // 0x00650910

BOOL __stdcall D2Common_10231_Impl(D2ActiveRoomStrc* pRoomDest, D2PathPointStrc tDest, D2DynamicPathStrc* pPath); // 0x00650AA0

// 0x006507B0
static void PATH_ResetMovement(D2DynamicPathStrc* pPath)
{
    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionX), PATH_FP16FitToCenter(pPath->tGameCoords.dwPrecisionY)), 0, pPath);
    const D2CoordStrc tZeroVelocity = gtPathZeroVelocity;
    pPath->dwFlags &= 0xFFFFFFDF;
    pPath->dwPathPoints = 0;
    pPath->dwCurrentPointIdx = 0;
    pPath->tVelocityVector = tZeroVelocity;
}

// 0x00650800
D2DynamicPathStrc* __fastcall PATH_CheckPathMoving(D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    pPath->dwFlags &= 0xFFFFFFF7;
    if (pPath->dwFlags & 0x40000)
    {
        pPath->nCollidedWithMask = 0;
    }

    if ((pPath->dwFlags & 0x20) && pPath->dwPathPoints > 0 && pPath->dwVelocity)
    {
        return pPath;
    }

    PATH_ResetMovement(pPath);
    return 0;
}

// 0x00650840
BOOL __stdcall D2Common_10226(D2UnitStrc* pUnit, int nBaseVelocity)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return FALSE;
    }

    pPath->dwFlags &= 0xFFFFFFF7;
    if ((pPath->dwFlags & 0x40000) != 0)
    {
        pPath->nCollidedWithMask = 0;
    }

    if ((pPath->dwFlags & 0x20) != 0 && pPath->dwPathPoints > 0 && pPath->dwVelocity != 0)
    {
        if ((((pPath->dwFlags >> 18) & 1) || PATH_CheckPathDone(pPath)) && pPath->dwCurrentPointIdx < pPath->dwPathPoints)
        {
            PATH_UpdateVelocity(nBaseVelocity, pPath);
            if (pPath->tVelocityVector.nX || pPath->tVelocityVector.nY)
            {
                int nSteps;
                D2FP32_16 tCoord;
                PATH_AdvanceOnPath(&tCoord, &nSteps, pPath);
                PATH_RecacheRoomAtCoordIfNeeded(tCoord, 0, pPath);
                if (pPath->eType != 4 && pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                {
                    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pPath, 1, 1);
                }

                if (pPath->dwCurrentPointIdx < pPath->dwPathPoints)
                {
                    return 1;
                }
            }
        }
    }

    PATH_ResetMovement(pPath);
    return FALSE;
}

// 0x00650910
static BOOL __stdcall PATH_UpdateCollisionMask(D2ActiveRoomStrc* pDestRoom, D2PathPointStrc tDest, D2DynamicPathStrc* pPath)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
    {
        if (PATH_IsZeroPoint(tDest))
        {
            COLLISION_ResetMaskWithSize(pPath->pRoom, pPath->tGameCoords.wPosX, pPath->tGameCoords.wPosY, pPath->dwUnitSize, pPath->nFootprintCollisionMask);
            pPath->nCollidedWithMask = 0;
        }
        else
        {
            D2PathPointStrc tPathPos;
            tPathPos.X = pPath->tGameCoords.wPosX;
            tPathPos.Y = pPath->tGameCoords.wPosY;
            if (tPathPos.X == tDest.X && tPathPos.Y == tDest.Y)
            {
                pPath->dwFlags &= 0xFFFFFFF7;
            }
            else
            {
                pPath->dwFlags |= 8;
            }

            pPath->nCollidedWithMask = COLLISION_ForceTeleportUnitCollisionMaskAndGetCollision(pPath->pRoom, tPathPos.X, tPathPos.Y, pDestRoom, tDest.X, tDest.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask, pPath->nMoveTestCollisionMask);
            pPath->nSavedStepsCount = 1;
            pPath->SavedSteps[0] = tDest;
        }
    }
    else
    {
        D2PathPointStrc tPathPos;
        tPathPos.X = pPath->tGameCoords.wPosX;
        tPathPos.Y = pPath->tGameCoords.wPosY;
        if (!tDest.X && !tDest.Y)
        {
            COLLISION_ResetMaskWithPattern(pPath->pRoom, tPathPos.X, tPathPos.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_SetUnitCollisionMask(pPath->pRoom, tPathPos.X, tPathPos.Y, pDestRoom, tDest.X, tDest.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
    }

    if (pPath->pRoom != pDestRoom)
    {
        pPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_ToFP16Center(tDest.X), PATH_ToFP16Center(tDest.Y)), pDestRoom, pPath);
    D2_ASSERT((!tDest.X && !tDest.Y) || sub_00463740_FindRoomAtPoint(pDestRoom, tDest.X, tDest.Y), 0x489);
    PATH_ResetMovement(pPath);
    return 1;
}

// 0x00650AA0
static BOOL __stdcall D2Common_10231_Impl(D2ActiveRoomStrc* pRoomDest, D2PathPointStrc tDest, D2DynamicPathStrc* pPath)
{
    D2PathPointStrc tCurrentPos;
    tCurrentPos.X = pPath->tGameCoords.wPosX;
    tCurrentPos.Y = pPath->tGameCoords.wPosY;
    if (pPath->pUnit && pPath->pUnit->dwUnitType == UNIT_MISSILE)
    {
        if (PATH_IsZeroPoint(tDest))
        {
            COLLISION_ResetMaskWithSize(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_TeleportUnitCollisionMask(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pRoomDest, tDest.X, tDest.Y, pPath->dwUnitSize, pPath->nFootprintCollisionMask);
        }
    }
    else
    {
        if (!tDest.X && !tDest.Y)
        {
            COLLISION_ResetMaskWithPattern(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
        else
        {
            COLLISION_SetUnitCollisionMask(pPath->pRoom, tCurrentPos.X, tCurrentPos.Y, pRoomDest, tDest.X, tDest.Y, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask);
        }
    }

    if (pPath->pRoom != pRoomDest)
    {
        pPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_ToFP16Center(tDest.X), PATH_ToFP16Center(tDest.Y)), pRoomDest, pPath);
    D2_ASSERT((!tDest.X && !tDest.Y) || sub_00463740_FindRoomAtPoint(pRoomDest, tDest.X, tDest.Y), 0x4CC);
    PATH_ResetMovement(pPath);
    return 1;
}

// 0x00650BE0
BOOL __stdcall D2Common_10229(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pDestRoom, unsigned int nDestX, unsigned int nDestY)
{
    D2PathPointStrc tCoords;
    tCoords.X = (unsigned short)nDestX;
    tCoords.Y = (unsigned short)nDestY;
    const BOOL bResult = PATH_UpdateCollisionMask(pDestRoom, tCoords, pDynamicPath);
    if (!bResult)
    {
        return bResult;
    }

    pDynamicPath->dwPathPoints = 0;
    return 1;
}

// 0x00650C20
int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY)
{
    D2PathPointStrc tDest;
    tDest.X = nX;
    tDest.Y = nY;
    D2Common_10231_Impl(pRooms, tDest, pDynamicPath);
    pDynamicPath->dwPathPoints = 0;
    return 1;
}

// 0x00650C60
BOOL __stdcall D2Common_10230(D2DynamicPathStrc* pDynamicPath, int nUnused, D2ActiveRoomStrc* pRoom, unsigned int X, short Y)
{
    D2PathPointStrc tPos;
    tPos.X = (unsigned short)X;
    tPos.Y = Y;
    const BOOL bResult = PATH_UpdateCollisionMask(pRoom, tPos, pDynamicPath);
    if (!bResult)
    {
        return bResult;
    }

    pDynamicPath->unk0x38 = 15;
    return 1;
}

// 0x00650CA0
BOOL __stdcall D2Common_10232(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pDestRoom, int nTargetX, int nTargetY)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nUnitType == 0 || nUnitType == 1, 0x50D);

    if (COLLISION_TrySetUnitCollisionMask(pPath->pRoom, pPath->tGameCoords.wPosX, pPath->tGameCoords.wPosY, pDestRoom, nTargetX, nTargetY, pPath->dwCollisionPattern, pPath->nFootprintCollisionMask, pPath->nMoveTestCollisionMask))
    {
        return FALSE;
    }

    if (pPath->pRoom != pDestRoom)
    {
        pPath->dwFlags |= 1;
    }

    PATH_RecacheRoomAtCoordIfNeeded(PATH_MakeCoord(PATH_ToFP16Center(nTargetX), PATH_ToFP16Center(nTargetY)), pDestRoom, pPath);
    D2_ASSERT(sub_00463740_FindRoomAtPoint(pDestRoom, nTargetX, nTargetY), 0x524);
    PATH_ResetMovement(pPath);
    return 1;
}

