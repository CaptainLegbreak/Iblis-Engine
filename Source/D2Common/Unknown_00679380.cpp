#include "D2Common.h"
#include "D2DrlgPresets.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Structs.h"

#include "D2PathFind.h"

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2PathInfoStrc;

struct D2CoordStrc;

struct D2StaticPathStrc;

struct D2CollisionTestStrc;

union D2SeedStrc;

struct D2PathIDAStarNodeStrc;

struct D2DrlgCoordsStrc;

struct D2PathFoWallNodeStrc;

struct D2PathMovStrc;


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40

void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70

int __stdcall PATH_GetTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00679380
static int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord); // 0x00679A60
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo); // 0x00679B30
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath); // 0x00679720

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

extern const D2CoordStrc gatDirectionToOffset[8]; // 0x006F1798

void __fastcall PATH_GetScaledDirectionVector(int nVelocity, D2CoordStrc* pDirectionVector, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067A390

static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo); // 0x006793E0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern const int gaIdaStar_PointCacheHashMaskX[128]; // 0x006F1998

extern const int gaIdaStar_PointCacheHashMaskY[128]; // 0x006F1B98


extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

extern const D2CoordStrc gnDirectionsToAdjacentCellOffsets[16]; // 0x006F1D98

extern const int gaPathHeuristicTable[]; // 0x006F1698
void __fastcall PATH_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

static inline int PATH_ScaleDelta(int nScale, int nDelta, int nMax)
{
    int nResult = nScale;
    nResult *= nDelta;
    return nResult / nMax;
}

// 0x00679380
int __stdcall PATH_GetTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nDiffX = pPoint1.X - pPoint2.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = pPoint1.Y - pPoint2.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    if (nDiffX < 8 && nDiffY < 8)
    {
        const int nResult = gaPathHeuristicTable[nDiffX + 8 * nDiffY];
        if (nResult < 0)
        {
            return 0;
        }
        return nResult + 1;
    }

    if (nDiffX > nDiffY)
    {
        return nDiffY + 2 * nDiffX;
    }
    return nDiffX + 2 * nDiffY;
}

// 0x006793E0
static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 52);

    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;

    const int nX0 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[0]].nX);
    const int nY0 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[0]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX0, nY0, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[0];
        return 1;
    }

    const int nX1 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[1]].nX);
    const int nY1 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[1]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX1, nY1, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[1];
        return 1;
    }

    D2_ASSERT(pTestDir[2] != 0xFF, 76);

    const int nX2 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[2]].nX);
    const int nY2 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[2]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX2, nY2, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[2];
        return 1;
    }

    return 0;
}

int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo); // 0x00679C80

int __fastcall PATH_AStar_ComputePath(D2PathInfoStrc* pPathInfo); // 0x0067B850

int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    if (pPath->nDirOffset)
    {
        return sub_6FDAA720(pPathInfo);
    }

    D2PathPointStrc nNextPoint = pPathInfo->tTargetCoord;
    pPath->PathPoints[0] = nNextPoint;

    if (PATH_CheckCollisionsToNextPosition(pPath, &nNextPoint))
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        return pPath->dwPathPoints;
    }

    if (PATH_GetTableHeuristic(nNextPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14)
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints += 1;
        return pPath->dwPathPoints;
    }

    {
        D2PathPointStrc tPoint = pPathInfo->tStartCoord;
        D2PathPointStrc tCurCoords = pPathInfo->tStartCoord;
        if (tPoint.X != nNextPoint.X || tPoint.Y != nNextPoint.Y)
        {
            pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
            pPath->dwPathPoints += 1;
            tPoint = nNextPoint;
            tCurCoords = nNextPoint;
        }

        const int nDistMax = pPathInfo->nDistMax;
        nNextPoint = pPathInfo->tTargetCoord;
        int nPrevDir = 0xFF;
        int nNewPointsCount = pPath->dwPathPoints;
        int bNotStraightLine = 0;
        int nCurDist = 0;
        if (nDistMax > 0)
        {
            D2PathPointStrc* pPathPointsEnd = &pPath->PathPoints[pPath->dwPathPoints];
            do
            {
                if (tCurCoords.X == nNextPoint.X && tCurCoords.Y == nNextPoint.Y)
                {
                    break;
                }

                bNotStraightLine = 0;
                int aTestDir[3];
                PATH_GetDirections_6FDAB790(aTestDir, tPoint, nNextPoint);
                int nDirection;
                if (!sub_6FDAA880(tPoint, aTestDir, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDir)
                {
                    goto ADD_LAST_POINT;
                }

                tCurCoords.X += gatDirectionToOffset[nDirection].nX;
                tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
                if (nDirection != nPrevDir)
                {
                    if (tPoint.X != pPathInfo->tStartCoord.X || tPoint.Y != pPathInfo->tStartCoord.Y)
                    {
                        *pPathPointsEnd = tPoint;
                        nNewPointsCount += 1;
                        ++pPathPointsEnd;
                    }
                    bNotStraightLine = 1;
                }
                tPoint = tCurCoords;
                nPrevDir = nDirection;
                nCurDist += 1;
            }
            while (nCurDist < nDistMax);

            if (bNotStraightLine)
            {
                goto STORE_POINT_COUNT;
            }
        ADD_LAST_POINT:
            if (nCurDist)
            {
                pPath->PathPoints[nNewPointsCount] = tPoint;
                nNewPointsCount += 1;
            }
        }
    STORE_POINT_COUNT:
        pPath->dwPathPoints = nNewPointsCount;
    }

    return pPath->dwPathPoints;
}

// 0x00679A60
static int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord)
{
    D2PathPointStrc tPoint;

    D2_ASSERT(((pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER) || (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 324);
    D2_ASSERT(pDynamicPath->eType != 4, 325);
    D2_ASSERT(pGameCoord->X != 0, 326);
    D2_ASSERT(pGameCoord->Y != 0, 327);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pDynamicPath, 1, 1);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    tPoint.X = pDynamicPath->wPosX;
    tPoint.Y = pDynamicPath->wPosY;
    return PATH_RayTrace(tPoint, pGameCoord, pDynamicPath);
}

// 0x00679B30
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    int nPrevDirection = 0xFF;
    int nbPathPoints = pDynamicPath->dwPathPoints;
    const int nDistMax = pPathInfo->nDistMax;
    D2PathPointStrc tLastSegmentEndCoord = pPathInfo->tStartCoord;
    const int nDirectionOffset = pDynamicPath->nDirOffset;
    {
        int bSegmentEndAlreadyAdded = 0;
        const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;

        D2PathPointStrc tCurCoords = tLastSegmentEndCoord;
        int nCurDistance;
        for (nCurDistance = 0; nCurDistance < nDistMax; nCurDistance += 1)
        {
            if (tCurCoords.X == tTargetCoord.X && tCurCoords.Y == tTargetCoord.Y)
            {
                break;
            }

            bSegmentEndAlreadyAdded = 0;
            int nDirections[3];
            PATH_GetDirections_6FDAB790(nDirections, tLastSegmentEndCoord, tTargetCoord);
            nDirections[0] = (nDirections[0] + nDirectionOffset) & 7;
            nDirections[1] = (nDirections[1] + nDirectionOffset) & 7;
            nDirections[2] = (nDirections[2] + nDirectionOffset) & 7;
            int nDirection;
            if (!sub_6FDAA880(tLastSegmentEndCoord, nDirections, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDirection)
            {
                break;
            }

            tCurCoords.X += gatDirectionToOffset[nDirection].nX;
            tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
            if (nDirection != nPrevDirection)
            {
                pDynamicPath->PathPoints[nbPathPoints] = tLastSegmentEndCoord;
                nbPathPoints += 1;
                bSegmentEndAlreadyAdded = 1;
            }
            tLastSegmentEndCoord = tCurCoords;
            nPrevDirection = nDirection;
        }

        if (!bSegmentEndAlreadyAdded && nCurDistance != 0)
        {
            pDynamicPath->PathPoints[nbPathPoints] = tLastSegmentEndCoord;
            nbPathPoints += 1;
        }
    }

    pDynamicPath->dwPathPoints = nbPathPoints;
    return nbPathPoints;
}

inline unsigned int PATH_ToFP16Center(unsigned short value)
{
    return (value << 16) + (1 << 15);
}

// 0x00678F00
void __fastcall PATH_NormalizeStep(int* a1, int* a2)
{
    if (*a1 >= 0)
    {
        while (*a1 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a1 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }

    if (*a2 >= 0)
    {
        while (*a2 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a2 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
}

// 0x00679530
static int __stdcall sub_00679530_TraceLineFP16(D2DynamicPathStrc* pDynamicPath, D2CoordStrc* pDirectionVector, D2PathPointStrc tStartCoord, D2PathPointStrc* pDestination)
{
    D2ActiveRoomStrc* pRoom = pDynamicPath->pRoom;
    const int nCollisionPattern = pDynamicPath->dwCollisionPattern;
    const int nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    D2PathPointStrc tPrevPoint = tStartCoord;
    int nX = PATH_ToFP16Center(tPrevPoint.X);
    int nY = PATH_ToFP16Center(tPrevPoint.Y);
    D2PathPointStrc tTargetPoint = *pDestination;
    const int nDeltaX = tTargetPoint.X - (unsigned short)(nX >> 16);
    const int nDeltaY = tTargetPoint.Y - (unsigned short)(nY >> 16);
    int nVelocityX = pDirectionVector->nX;
    int nVelocityY = pDirectionVector->nY;
    D2_ASSERT(D2_ABS(nVelocityX) > 0 || D2_ABS(nVelocityY) > 0, 110);
    PATH_NormalizeStep(&nVelocityX, &nVelocityY);
    const int nStepX = nVelocityX;
    const int nStepY = nVelocityY;
    if (D2_ABS(nDeltaX) > D2_ABS(nDeltaY))
    {
        while (tPrevPoint.X != tTargetPoint.X)
        {
            const int nNewX = nStepX + nX;
            const int nNewY = nStepY + nY;
            D2PathPointStrc tNewPoint;
            tNewPoint.X = (unsigned short)(nNewX >> 16);
            tNewPoint.Y = (unsigned short)(nNewY >> 16);
            if (tPrevPoint.X != tNewPoint.X || tPrevPoint.Y != tNewPoint.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tNewPoint.X, tNewPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            nX = nNewX;
            nY = nNewY;
            tPrevPoint = tNewPoint;
        }
    }
    else
    {
        while (tPrevPoint.Y != tTargetPoint.Y)
        {
            const int nNewX = nStepX + nX;
            const int nNewY = nStepY + nY;
            D2PathPointStrc tNewPoint;
            tNewPoint.X = (unsigned short)(nNewX >> 16);
            tNewPoint.Y = (unsigned short)(nNewY >> 16);
            if (tPrevPoint.X != tNewPoint.X || tPrevPoint.Y != tNewPoint.Y)
            {
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tNewPoint.X, tNewPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pDestination = tPrevPoint;
                    return 0;
                }
            }
            nX = nNewX;
            nY = nNewY;
            tPrevPoint = tNewPoint;
        }
    }
    D2_ASSERT(tTargetPoint.X, 171);
    D2_ASSERT(tTargetPoint.Y, 172);
    return 1;
}

// 0x00679E50
int __fastcall sub_6FDAB0B0(D2PathInfoStrc* pPathInfo)
{
    pPathInfo->pDynamicPath->dwCurrentPointIdx = 0;
    return PATH_Toward_6FDAA9F0(pPathInfo);
}

// 0x00679E60
int __fastcall PATH_BackupTurn_Compute(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->nDirOffset = -4;

    const int nResult = sub_6FDAA720(pPathInfo);
    if (!nResult)
    {
        return 0;
    }

    pDynamicPath->dwPathPoints = nResult;
    pDynamicPath->nDirOffset = -2;

    int nExtra = sub_6FDAA720(pPathInfo) - nResult;
    if (!nExtra)
    {
        pDynamicPath->nDirOffset = 2;
        nExtra = sub_6FDAA720(pPathInfo) - nResult;
    }

    pDynamicPath->nDirOffset = -4;
    return nResult + nExtra;
}

// 0x00679ED0
int __fastcall PATH_Straight_Compute(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->dwPathPoints = 0;

    int nPathPoints = PATH_Toward_6FDAA9F0(pPathInfo);
    if (nPathPoints)
    {
        D2PathPointStrc tPathLastPoint = pDynamicPath->PathPoints[nPathPoints - 1];
        if (PATH_GetTableHeuristic(tPathLastPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14
            && (tPathLastPoint.X != pPathInfo->tStartCoord.X || tPathLastPoint.Y != pPathInfo->tStartCoord.Y))
        {
            return nPathPoints;
        }
    }

    const int nMaxDist = 18;
    const int nMaxDistSquared = nMaxDist * nMaxDist;

    int nDX = pPathInfo->tStartCoord.X - pPathInfo->tTargetCoord.X;
    const int nDiffX = nDX < 0 ? -nDX : nDX;
    int nDY = pPathInfo->tStartCoord.Y - pPathInfo->tTargetCoord.Y;
    const int nDiffY = nDY < 0 ? -nDY : nDY;
    const int nSquaredDistance = nDiffX * nDiffX + nDiffY * nDiffY;

    if (nSquaredDistance <= nMaxDistSquared)
    {
        if (int nAStarPathPoints = PATH_AStar_ComputePath(pPathInfo))
        {
            return nAStarPathPoints;
        }
        else if (nPathPoints)
        {
            nPathPoints = PATH_Toward_6FDAA9F0(pPathInfo);
        }
    }
    return nPathPoints;
}

// 0x00679F70
int __fastcall PATH_Leap_6FDAB1E0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    D2PathPointStrc pGameCoord = pPathInfo->tTargetCoord;
    pDynamicPath->PathPoints[0] = pGameCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pGameCoord);
    if (pPathInfo->tStartCoord.X == pGameCoord.X && pPathInfo->tStartCoord.Y == pGameCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = pGameCoord;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}

// 0x00679FD0
int __fastcall PATH_Knockback_Client(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->PathPoints[0] = pPathInfo->tTargetCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pDynamicPath->PathPoints[0]);
    return 1;
}

// 0x0067A000
int __fastcall PATH_Knockback_Server(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    int nDeltaX = 0;
    int nDeltaY = 0;
    const int nHalfDist = (pDynamicPath->nDist >> 1) + 1;
    D2PathPointStrc tFinalCoords;
    if ((pDynamicPath ? pDynamicPath->hTarget : 0))
    {
        tFinalCoords = pPathInfo->tStartCoord;

        const int nTargetUnitX = UNITS_GetXPositionInline((pDynamicPath ? pDynamicPath->hTarget : 0));
        const int nTargetUnitY = UNITS_GetYPositionInline((pDynamicPath ? pDynamicPath->hTarget : 0));
        nDeltaX = pPathInfo->tStartCoord.X - nTargetUnitX;
        nDeltaY = pPathInfo->tStartCoord.Y - nTargetUnitY;
        if (const int nMax = D2_MAX(D2_ABS(nDeltaX), D2_ABS(nDeltaY)))
        {
            nDeltaX = PATH_ScaleDelta(nHalfDist, nDeltaX, nMax);
            nDeltaY = PATH_ScaleDelta(nHalfDist, nDeltaY, nMax);
        }
        tFinalCoords.X += nDeltaX;
        tFinalCoords.Y += nDeltaY;
    }
    else
    {
        tFinalCoords = pPathInfo->tTargetCoord;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    PATH_RayTrace(pPathInfo->tStartCoord, &tFinalCoords, pDynamicPath);
    D2COMMON_10170_PathSetTargetPos(pDynamicPath, tFinalCoords.X, tFinalCoords.Y);
    if (tFinalCoords.X == pPathInfo->tStartCoord.X && tFinalCoords.Y == pPathInfo->tStartCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}

// 0x0067A140
int __fastcall PATH_ComputePathBlessedHammer_6FDAB3C0(D2DynamicPathStrc* pPath, D2SeedStrc* pSeed)
{
    D2FP32_16 tCenter = pPath->tGameCoords;
    D2FP32_16 tPrevious = tCenter;
    int nAngle = 0;
    int nRadius = 0;
    int nPoints = 0;

    do
    {
        nRadius += 0x2580;
        nAngle += 16;
        float fRadius = (float)nRadius;
// build: symbol ?FOG_10083_Cos_LUT@* 0x0040B330
        unsigned int nX = (unsigned int)(FOG_10083_Cos_LUT(nAngle) * fRadius) + tCenter.dwPrecisionX;
// build: symbol ?FOG_10084_Sin_LUT@* 0x0040B350
        unsigned int nY = (unsigned int)(FOG_10084_Sin_LUT(nAngle) * fRadius) + tCenter.dwPrecisionY;
        if ((unsigned short)(nX >> 16) != (unsigned short)(tPrevious.dwPrecisionX >> 16) || (nY >> 16) != (unsigned short)(tPrevious.dwPrecisionY >> 16))
        {
            tPrevious.dwPrecisionX = nX;
            tPrevious.dwPrecisionY = nY;
            pPath->PathPoints[nPoints].X = (unsigned short)(nX >> 16);
            pPath->PathPoints[nPoints].Y = (unsigned short)(nY >> 16);
            ++nPoints;
        }
    }
    while (nPoints < 77);

    pPath->dwPathPoints = nPoints;
    return nPoints;
}

// 0x0067A390
void __fastcall PATH_GetScaledDirectionVector(int nVelocity, D2CoordStrc* pDirectionVector, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDirection;
    PATH_GetDirectionVectorFromPoints(pDirectionVector, &nDirection, tPoint1, tPoint2);
    pDirectionVector->nX = (pDirectionVector->nX * nVelocity) >> 8;
    pDirectionVector->nY = (pDirectionVector->nY * nVelocity) >> 8;
    D2_ASSERT(D2_MAX(D2_ABS(pDirectionVector->nX), D2_ABS(pDirectionVector->nY)) < 0x200000, 817);
}

// 0x0067A420
static int __stdcall sub_0067A420_TraceSegment(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc tStartCoord, D2PathPointStrc tTargetCoord)
{
    if (!pDynamicPath->dwVelocity)
        return 0;

    D2CoordStrc tDirectionVector;
    PATH_GetScaledDirectionVector(pDynamicPath->dwVelocity, &tDirectionVector, tStartCoord, tTargetCoord);
    D2_ASSERT(D2_ABS(tDirectionVector.nX) > 0 || D2_ABS(tDirectionVector.nY) > 0, 834);
    PATH_NormalizeStep(&tDirectionVector.nX, &tDirectionVector.nY);
    return sub_00679530_TraceLineFP16(pDynamicPath, &tDirectionVector, tStartCoord, &tTargetCoord);
}

// 0x0067A4A0
int __fastcall sub_0067A4A0_TestPathPoints(D2PathInfoStrc* pPathInfo)
{
    D2PathPointStrc tPrevPoint = pPathInfo->tStartCoord;
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    struct LoopState { int count; D2ActiveRoomStrc* room; int pattern; int mask; int index; } loop;
    loop.room=pDynamicPath->pRoom;
    loop.count=pDynamicPath->dwPathPoints;
    loop.pattern=pDynamicPath->dwCollisionPattern;
    loop.mask=pDynamicPath->nMoveTestCollisionMask;
    loop.index=0;
    for (; loop.index < loop.count; ++loop.index)
    {
        const D2PathPointStrc tPoint = pDynamicPath->PathPoints[loop.index];
        int deltaX=tPoint.X-tPrevPoint.X;
        if (deltaX<0) deltaX=-deltaX;
        int deltaY;
        if (deltaX <= 1 && ((deltaY=tPoint.Y-tPrevPoint.Y), (deltaY<0 ? -deltaY : deltaY)) <= 1)
        {
            if (COLLISION_CheckAnyCollisionWithPattern(loop.room, tPoint.X, tPoint.Y, loop.pattern, loop.mask))
                return 0;
        }
        else if (!sub_0067A420_TraceSegment(pDynamicPath, tPrevPoint, tPoint))
        {
            return 0;
        }
        tPrevPoint = tPoint;
    }
    return 1;
}

// 0x00679720
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath)
{
    D2ActiveRoomStrc* pRoom = pDynamicPath->pRoom;
    int nCollisionPattern = pDynamicPath->dwCollisionPattern;
    int nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    const D2PathPointStrc tTargetPoint = *pPathDestination;

    D2PathPointStrc tLastPointWithoutCollision = tStartCoord;
    D2PathPointStrc tCurPoint = tStartCoord;
    const int nDeltaX = tTargetPoint.X - tStartCoord.X;
    const int nDeltaY = tTargetPoint.Y - tStartCoord.Y;
    const int nPointsX = (nDeltaX < 0 ? -nDeltaX : nDeltaX) + 1;
    const int nPointsY = (nDeltaY < 0 ? -nDeltaY : nDeltaY) + 1;
    int nXIncrement;
    int nYIncrement;

    if (nPointsX > nPointsY)
    {
        if (nDeltaX == 0)
        {
            nYIncrement = nDeltaY >= 0 ? 1 : -1;
            while (tLastPointWithoutCollision.Y != tTargetPoint.Y)
            {
                tCurPoint.Y += nYIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tStartCoord.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
        else
        {
            nXIncrement = nDeltaX >= 0 ? 1 : -1;
            nYIncrement = nDeltaY >= 0 ? 1 : -1;
            int nYOffset = nPointsY;
            while (tLastPointWithoutCollision.X != tTargetPoint.X)
            {
                tCurPoint.X += nXIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                nYOffset += nPointsY;
                if (nYOffset >= nPointsX)
                {
                    nYOffset -= nPointsX;
                    tCurPoint.Y += nYIncrement;
                    if (nYOffset > 0)
                    {
                        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                        {
                            *pPathDestination = tLastPointWithoutCollision;
                            return 0;
                        }
                    }
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
    }

    if (nPointsX < nPointsY)
    {
        if (nDeltaY == 0)
        {
            nXIncrement = nDeltaX >= 0 ? 1 : -1;
            while (tLastPointWithoutCollision.X != tTargetPoint.X)
            {
                tCurPoint.X += nXIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tStartCoord.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
        else
        {
            nXIncrement = nDeltaX >= 0 ? 1 : -1;
            nYIncrement = nDeltaY >= 0 ? 1 : -1;
            int nEndOffsetX = nPointsX;
            while (tLastPointWithoutCollision.Y != tTargetPoint.Y)
            {
                tCurPoint.Y += nYIncrement;
                if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
                nEndOffsetX += nPointsX;
                if (nEndOffsetX >= nPointsY)
                {
                    nEndOffsetX -= nPointsY;
                    tCurPoint.X += nXIncrement;
                    if (nEndOffsetX > 0)
                    {
                        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
                        {
                            *pPathDestination = tLastPointWithoutCollision;
                            return 0;
                        }
                    }
                }
                tLastPointWithoutCollision = tCurPoint;
            }
            return 1;
        }
    }

    nXIncrement = nDeltaX >= 0 ? 1 : -1;
    nYIncrement = nDeltaY >= 0 ? 1 : -1;
    while (tLastPointWithoutCollision.X != tTargetPoint.X)
    {
        tCurPoint.X += nXIncrement;
        tCurPoint.Y += nYIncrement;
        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, tCurPoint.X, tCurPoint.Y, nCollisionPattern, nCollisionMask))
        {
            *pPathDestination = tLastPointWithoutCollision;
            return 0;
        }
        tLastPointWithoutCollision = tCurPoint;
    }
    return 1;
}


#include "gen/data/Source/D2Common/Unknown_00679380.inc"

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0067A240
int __fastcall PATH_ComputePathChargedBolt_6FDAB4A0(D2DynamicPathStrc* pDynamicPath, D2SeedStrc* pSeed)
{

    int dirOffsetSequence[32] = {
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1, 0, 1,
        -1,   1,
    };

    int nMaxPathPoints = pDynamicPath->bDistMax >> 1;
    int nCurPointIdx = 0;
    D2PathPointStrc nPrevPoint;
    nPrevPoint.X = pDynamicPath->wPosX;
    nPrevPoint.Y = pDynamicPath->wPosY;

    int v16[3];
    PATH_GetDirections_6FDAB790(v16, nPrevPoint, pDynamicPath->tTargetCoord);

    for (; nCurPointIdx < nMaxPathPoints; nCurPointIdx++)
    {
        unsigned int nDir = dirOffsetSequence[SEED_RollRandomNumber(pSeed) & 31];
        nDir = (v16[0] + nDir) % 8;
        pDynamicPath->PathPoints[nCurPointIdx] = nPrevPoint;
        nPrevPoint.X += 2 * gatDirectionToOffset[nDir].nX;
        nPrevPoint.Y += 2 * gatDirectionToOffset[nDir].nY;
    }

    pDynamicPath->PathPoints[nCurPointIdx] = nPrevPoint;
    nCurPointIdx += 1;
    pDynamicPath->dwPathPoints = nCurPointIdx;
    return nCurPointIdx;
}

