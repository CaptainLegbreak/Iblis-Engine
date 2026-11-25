#include "D2Common.h"
#include "D2PathFind.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DrlgPresets.h"
#include "D2PathFoWallContext.h"

struct D2DynamicPathStrc;

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2CoordStrc;

struct D2StaticPathStrc;

struct D2CollisionTestStrc;

struct D2PathInfoStrc;

struct D2PathFoWallNodeStrc;

struct D2PathFoWallContextStrc;

struct D2PathMovStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

int __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40

void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70

int __stdcall PATH_GetTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00679380

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

extern const D2CoordStrc gatDirectionToOffset[8]; // 0x006F1798

int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo); // 0x006793E0

static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath); // 0x00679720

int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo); // 0x00679B30

typedef int BOOL;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern const int gaIdaStar_PointCacheHashMaskX[]; // 0x006F1998

extern const int gaIdaStar_PointCacheHashMaskY[]; // 0x006F1B98

int __stdcall PATH_AStar_Heuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067ADC0

D2PathFoWallNodeStrc* __stdcall PATH_AStar_GetNodeFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint); // 0x0067AE00

D2PathFoWallNodeStrc* __stdcall PATH_AStar_FindPointInVisitedCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint); // 0x0067AE50

D2PathFoWallNodeStrc* __fastcall PATH_AStar_AllocNewNode(D2PathFoWallContextStrc* pContext); // 0x0067B1C0

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

extern const D2CoordStrc gnDirectionsToAdjacentCellOffsets[16]; // 0x006F1D98

int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord); // 0x00679A60

void PATH_AStar_PropagateNewFScoreToChildren(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNewNode); // 0x0067AFE0

int PATH_FindNonCollidingTargetPoint(D2PathInfoStrc* pInfo, D2PathMovStrc* pMov); // 0x0067BBF0

static void __stdcall PATH_ReplaceSubpathPoints(D2PathPointStrc* pPoints, int* pSubPathStartIdx, int nSubPathLastIdx, int* nMaxIndex, D2PathMovStrc* pMov);

// build: symbol ?gaPathDeltaTable@* 0x006F1E28
int __stdcall PATH_GetAdjacentPointDirection(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0067BBC0

int __fastcall PATH_FindSubpathWithoutObstacles(D2PathInfoStrc* pInfo, D2PathPointStrc tSubPathStart, D2PathPointStrc* pPathPoints, int* pSubPathStartIdx, int* nMaxIndex, int nMaxLength, int nMajorDirection);

int __fastcall PATH_SimplifyToLines(D2PathPointStrc tStartCoord, D2PathPointStrc* pOutPathPoints, D2PathPointStrc* pInputPoints, int nbTempPoints); // 0x0067C1E0

static int __stdcall PATH_BresenhamLine(D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint, int nDistMax, int* nMajorDirection, D2PathPointStrc* pOutPoints);

inline const int& PATH_MaxRef(const int& a, const int& b)
{
    return a > b ? a : b;
}

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

static inline int PATH_TestCollision(const D2CollisionTestStrc* pTest, int nX, int nY)
{
    return COLLISION_CheckAnyCollisionWithPattern(pTest->pRoom, nX, nY, pTest->nCollisionPattern, pTest->nCollisionMask);
}

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

static inline int PATH_ScaleDelta(int nScale, int nDelta, int nMax)
{
    int nResult = nScale;
    nResult *= nDelta;
    return nResult / nMax;
}

static inline unsigned short PATH_AStar_HeuristicInline(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDiffX = tPoint1.X - tPoint2.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = tPoint1.Y - tPoint2.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    if (nDiffX >= nDiffY)
    {
        return nDiffY + 2 * nDiffX;
    }
    return nDiffX + 2 * nDiffY;
}

static inline D2PathFoWallNodeStrc* PATH_AStar_RemoveFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pToRemove)
{
    D2PathFoWallNodeStrc* pPrev = 0;
    const int nHash = (gaIdaStar_PointCacheHashMaskY[pToRemove->tPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[pToRemove->tPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pCur = pContext->aPendingCache[nHash]; pCur != pToRemove; pCur = pCur->pNextCachePoint)
    {
        pPrev = pCur;
    }

    if (pPrev)
    {
        pPrev->pNextCachePoint = pToRemove->pNextCachePoint;
    }
    else
    {
        pContext->aPendingCache[nHash] = pToRemove->pNextCachePoint;
    }
    pToRemove->pNextCachePoint = 0;
    return pPrev;
}

static inline void PATH_AStar_AddChildToNode(D2PathFoWallNodeStrc* pNode, D2PathFoWallNodeStrc* pChild)
{
    if (!pNode->pChildren[0])
        pNode->pChildren[0] = pChild;
    else if (!pNode->pChildren[1])
        pNode->pChildren[1] = pChild;
    else if (!pNode->pChildren[2])
        pNode->pChildren[2] = pChild;
    else if (!pNode->pChildren[3])
        pNode->pChildren[3] = pChild;
    else if (!pNode->pChildren[4])
        pNode->pChildren[4] = pChild;
    else if (!pNode->pChildren[5])
        pNode->pChildren[5] = pChild;
    else if (!pNode->pChildren[6])
        pNode->pChildren[6] = pChild;
    else if (!pNode->pChildren[7])
        pNode->pChildren[7] = pChild;
}

static inline D2PathFoWallNodeStrc* PATH_AStar_GetNewNode(D2PathFoWallContextStrc* pContext)
{
    D2PathFoWallNodeStrc* pNewNode = 0;
    if (pContext->nNodesCount != 200)
    {
        pNewNode = &pContext->aNodesStorage[pContext->nNodesCount++];
        memset(pNewNode, 0, sizeof(*pNewNode));
    }
    return pNewNode;
}

// 0x0067B9C0
int __stdcall PATH_GetSquaredDistanceBetweenPoints(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    const int nDiffX = tPoint1.X - tPoint2.X;
    const int nDiffY = tPoint1.Y - tPoint2.Y;
    return nDiffY * nDiffY + nDiffX * nDiffX;
}

// 0x0067B9F0
static int __stdcall PATH_BresenhamLine(D2PathPointStrc tStartPoint, D2PathPointStrc tTargetPoint, int nDistMax, int* nMajorDirection, D2PathPointStrc* pOutPoints)
{
    nDistMax--;
    *nMajorDirection = 0;

    int nAbsDiffX = tTargetPoint.X - tStartPoint.X;
    int nAbsDiffY = tTargetPoint.Y - (int)tStartPoint.Y;
    int nStepY = 0;
    int nStepX = 0;
    int nbPoints = 0;
    if (nAbsDiffX < 0)
    {
        nAbsDiffX = -nAbsDiffX;
        nStepX = -1;
    }
    else
    {
        nStepX = 1;
    }
    if (nAbsDiffY < 0)
    {
        nAbsDiffY = -nAbsDiffY;
        nStepY = -1;
    }
    else
    {
        nStepY = 1;
    }

    if (nAbsDiffX == 0)
    {
        if (nAbsDiffY > 0)
        {
            unsigned short nY = tStartPoint.Y;
            *nMajorDirection = nStepY <= 0 ? 0 : 2;
            if (nAbsDiffY > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            do
            {
                pOutPoints[nbPoints].X = tStartPoint.X;
                nY += nStepY;
                pOutPoints[nbPoints].Y = (int)nY;
                ++nbPoints;
                --nAbsDiffY;
            }
            while (nAbsDiffY);
        }
    }
    else
    {
        unsigned short nX = tStartPoint.X;
        unsigned short nY = tStartPoint.Y;
        if (nAbsDiffY == 0)
        {
            *nMajorDirection = nStepX <= 0 ? 3 : 1;
            if (nAbsDiffX > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            do
            {
                nX += nStepX;
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = tStartPoint.Y;
                ++nbPoints;
                --nAbsDiffX;
            }
            while (nAbsDiffX);
        }
        else if (nAbsDiffX >= nAbsDiffY)
        {
            *nMajorDirection = nStepX <= 0 ? 3 : 1;
            if (nAbsDiffX > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }

            int nDeviation = 0;
            nDistMax = nAbsDiffX;
            do
            {
                nX += nStepX;
                nDeviation += nAbsDiffY;
                if (nDeviation >= nAbsDiffX)
                {
                    nDeviation -= nAbsDiffX;
                    nY += nStepY;
                }
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = nY;
                ++nbPoints;
                --nDistMax;
            }
            while (nDistMax);
        }
        else
        {
            *nMajorDirection = nStepY <= 0 ? 0 : 2;
            if (nAbsDiffY > nDistMax)
            {
                pOutPoints[0].X = 0;
                return 0;
            }
            int nRemainingStepsY = nAbsDiffY;
            int nDeviation = 0;
            do
            {
                nY += nStepY;
                nDeviation += nAbsDiffX;
                if (nDeviation >= nAbsDiffY)
                {
                    nDeviation -= nAbsDiffY;
                    nX += nStepX;
                }
                pOutPoints[nbPoints].X = nX;
                pOutPoints[nbPoints].Y = nY;
                ++nbPoints;
                --nRemainingStepsY;
            }
            while (nRemainingStepsY);
        }
    }

    pOutPoints[nbPoints].X = 0;
    return nbPoints;
}


// 0x0067BBC0
int __stdcall PATH_GetAdjacentPointDirection(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
// build: symbol ?gaPathDeltaTable@* 0x006F1E28
    return gaPathDeltaTable[3 * (tPoint2.Y - tPoint1.Y) + (tPoint2.X - tPoint1.X)];
}

static __forceinline int PATH_TestNewTargetPoint(D2PathMovStrc* pMov, D2ActiveRoomStrc* pRoom, int nCollisionPattern, int nCollisionMask)
{
    pMov->tTargetCoord.X = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nX + pMov->tCurrentCoord.X);
    pMov->tTargetCoord.Y = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nY + pMov->tCurrentCoord.Y);
    return COLLISION_CheckAnyCollisionWithPattern(pRoom, pMov->tTargetCoord.X, pMov->tTargetCoord.Y, nCollisionPattern, nCollisionMask);
}

// 0x0067BBF0
static int PATH_FindNonCollidingTargetPoint(D2PathInfoStrc* pInfo, D2PathMovStrc* pMov)
{
    D2ActiveRoomStrc* pRoom = pInfo->pStartRoom;
    const int nCollisionPattern = pInfo->nCollisionPattern;
    const int nCollisionMask = pInfo->nCollisionMask;
    D2_ASSERT(((pInfo->pDynamicPath->pUnit && pInfo->pDynamicPath->pUnit->dwUnitType == UNIT_PLAYER) || (pInfo->pDynamicPath->pUnit && pInfo->pDynamicPath->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 290);

    pMov->bReachedDeadEnd = 0;
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    if (!PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask))
        return 1;

    pMov->bReachedDeadEnd = 1;
    pMov->nDirectionIndex = pMov->pNextDirection[pMov->nDirectionIndex];
    return !PATH_TestNewTargetPoint(pMov, pRoom, nCollisionPattern, nCollisionMask);
}

// 0x0067BD70
static inline void sub_0067BD70_SwapPoints(D2PathPointStrc* pA, D2PathPointStrc* pB)
{
    const D2PathPointStrc tPoint = *pA;
    *pA = *pB;
    *pB = tPoint;
}

// emits the static 0x0067BD70 (not game code)
void __fastcall sub_M110_Emit_0067BD70(D2PathPointStrc* pPoints, int nCount)
{
    sub_0067BD70_SwapPoints(pPoints, pPoints + nCount);
}

// 0x0067BD80
static void __stdcall PATH_ReplaceSubpathPoints(D2PathPointStrc* pPoints, int* pSubPathStartIdx, int nSubPathLastIdx, int* nMaxIndex, D2PathMovStrc* pMov)
{
    const int nPointsDiff = (*pSubPathStartIdx - nSubPathLastIdx) + (pMov->nPoints - 1);
    const int nLastReplacedPointIdx = nSubPathLastIdx + nPointsDiff;
    memmove(&pPoints[nLastReplacedPointIdx + 1], &pPoints[nSubPathLastIdx + 1], (*nMaxIndex - nSubPathLastIdx - 1) * sizeof(D2PathPointStrc));
    memcpy(&pPoints[*pSubPathStartIdx], &pMov->pPoints[0], pMov->nPoints * sizeof(D2PathPointStrc));
    *nMaxIndex += nPointsDiff;
    *pSubPathStartIdx = nLastReplacedPointIdx + 1;
}

static inline int PATH_GetSquaredDistance(D2PathPointStrc tPoint, D2PathPointStrc tTarget)
{
    const int nDX = tPoint.X - tTarget.X;
    const int nDY = tPoint.Y - tTarget.Y;
    return nDX * nDX + nDY * nDY;
}

// 0x0067BDF0
int __fastcall PATH_FindSubpathWithoutObstacles(D2PathInfoStrc* pInfo, D2PathPointStrc tSubPathStart, D2PathPointStrc* pPathPoints, int* pSubPathStartIdx, int* nMaxIndex, int nMaxLength, int nMajorDirection)
{
    D2PathMovStrc* pOtherPath;
    D2PathMovStrc* pCurPath;
    D2PathMovStrc tCache1 = { 0, 0, { 0, 0 }, { 0, 0 }, 0, gnPreviousDirection1, gnNextDirection1, 0, 0, 0 };
    D2PathMovStrc tCache2 = { 0, 0, { 0, 0 }, { 0, 0 }, 0, gnPreviousDirection2, gnNextDirection2, 0, 0, 0 };
    pOtherPath = &tCache2;
    pCurPath = &tCache1;

    const int nAdjacentCellIndex = PATH_GetAdjacentPointDirection(tSubPathStart, pPathPoints[*pSubPathStartIdx]);
    tCache1.nDirectionIndex = nAdjacentCellIndex + 1;
    tCache2.nDirectionIndex = nAdjacentCellIndex + 7;

    tCache2.tCurrentCoord = tSubPathStart;
    tCache1.tCurrentCoord = tSubPathStart;

    do
    {
        if (!pCurPath->bPathFinished)
        {
            if (PATH_FindNonCollidingTargetPoint(pInfo, pCurPath))
            {
                if (pCurPath->nPoints > 0)
                {
                    int nMajorDirectionDistance = 0;
                    switch (nMajorDirection)
                    {
                    case 0:
                        nMajorDirectionDistance = tSubPathStart.Y - pCurPath->tTargetCoord.Y;
                        break;
                    case 1:
                        nMajorDirectionDistance = pCurPath->tTargetCoord.X - tSubPathStart.X;
                        break;
                    case 2:
                        nMajorDirectionDistance = pCurPath->tTargetCoord.Y - tSubPathStart.Y;
                        break;
                    case 3:
                        nMajorDirectionDistance = tSubPathStart.X - pCurPath->tTargetCoord.X;
                        break;
                    }

                    if (nMajorDirectionDistance > 0)
                    {
                        nMajorDirectionDistance += *pSubPathStartIdx - 1;
                        if (nMajorDirectionDistance < *nMaxIndex && pCurPath->tTargetCoord.X == pPathPoints[nMajorDirectionDistance].X && pCurPath->tTargetCoord.Y == pPathPoints[nMajorDirectionDistance].Y)
                        {
                            D2_ASSERT(pCurPath->nPoints < nMaxLength, 443);
                            pCurPath->pPoints[pCurPath->nPoints] = pCurPath->tTargetCoord;
                            pCurPath->nPoints++;
                            pCurPath->pPoints[pCurPath->nPoints].X = 0;
                            PATH_ReplaceSubpathPoints(pPathPoints, pSubPathStartIdx, nMajorDirectionDistance, nMaxIndex, pCurPath);
                            return pCurPath->nPoints;
                        }
                    }
                }

                if (pOtherPath->nPoints > 1)
                {
                    if (pCurPath->nLastSyncPointWithOtherPathIndex)
                    {
                        if (pCurPath->tTargetCoord.X == pOtherPath->pPoints[pCurPath->nLastSyncPointWithOtherPathIndex - 2].X && pCurPath->tTargetCoord.Y == pOtherPath->pPoints[pCurPath->nLastSyncPointWithOtherPathIndex - 2].Y)
                        {
                            pPathPoints[*pSubPathStartIdx].X = 0;
                            *nMaxIndex = *pSubPathStartIdx;
                            return 0;
                        }
                        pCurPath->nLastSyncPointWithOtherPathIndex = 0;
                    }

                    if (pCurPath->tTargetCoord.X == pOtherPath->tCurrentCoord.X && pCurPath->tTargetCoord.Y == pOtherPath->tCurrentCoord.Y)
                        pCurPath->nLastSyncPointWithOtherPathIndex = pOtherPath->nPoints;
                }

                pCurPath->pPoints[pCurPath->nPoints] = pCurPath->tTargetCoord;
                pCurPath->nPoints++;
                pCurPath->tCurrentCoord = pCurPath->tTargetCoord;
                pCurPath->nDirectionIndex = pCurPath->pPrevDirection[pCurPath->nDirectionIndex];

                if (pCurPath->nPoints >= nMaxLength - *nMaxIndex - 1)
                    pCurPath->bPathFinished = 1;
            }
            else
            {
                pCurPath->bPathFinished = 1;
            }
        }

        D2PathMovStrc* pSwap = pOtherPath;
        if (!pCurPath->nLastSyncPointWithOtherPathIndex)
        {
            pOtherPath = pCurPath;
            pCurPath = pSwap;
        }
    }
    while (!(tCache1.bPathFinished || tCache2.bPathFinished));

    if (nMaxLength > 80)
    {
        pPathPoints[*pSubPathStartIdx].X = 0;
        *nMaxIndex = *pSubPathStartIdx;
        return 0;
    }

    const int nSquaredDist1 = PATH_GetSquaredDistance(tCache1.pPoints[tCache1.nPoints - 1], pInfo->tTargetCoord);
    const int nSquaredDist2 = PATH_GetSquaredDistance(tCache2.pPoints[tCache2.nPoints - 1], pInfo->tTargetCoord);
    const int nSquaredDistStartToTarget = PATH_GetSquaredDistance(pInfo->tStartCoord, pInfo->tTargetCoord);

    if (nSquaredDist2 <= nSquaredDist1)
    {
        if (nSquaredDistStartToTarget < nSquaredDist2)
            return 0;
        const int nStartIdx = *pSubPathStartIdx;
        if (tCache2.nPoints > 0)
        {
            for (int i = 0; i < tCache2.nPoints; ++i)
                pPathPoints[nStartIdx + i] = tCache2.pPoints[i];
        }
        *pSubPathStartIdx += tCache2.nPoints;
        *nMaxIndex = *pSubPathStartIdx;
        pPathPoints[*pSubPathStartIdx].X = 0;
        return pCurPath->nPoints;
    }
    else
    {
        if (nSquaredDistStartToTarget < nSquaredDist1)
            return 0;
        const int nStartIdx = *pSubPathStartIdx;
        if (tCache1.nPoints > 0)
        {
            for (int i = 0; i < tCache1.nPoints; ++i)
                pPathPoints[nStartIdx + i] = tCache1.pPoints[i];
        }
        *pSubPathStartIdx += tCache1.nPoints;
        *nMaxIndex = *pSubPathStartIdx;
        pPathPoints[*pSubPathStartIdx].X = 0;
        return pCurPath->nPoints;
    }
}

// 0x0067C1E0
int __fastcall PATH_SimplifyToLines(D2PathPointStrc* pOutPathPoints, D2PathPointStrc* pInputPoints, D2PathPointStrc tStartCoord, int nbTempPoints)
{
    if (nbTempPoints < 2)
    {
        if (nbTempPoints == 1)
        {
            *pOutPathPoints = *pInputPoints;
            return 1;
        }
        return 0;
    }

    int nCurrentPointIdx = 0;
    int prevDeltaX = pInputPoints->X - tStartCoord.X;
    int nbOutPoints = 0;
    int nbPointsInLine = 0;
    int prevDeltaY = pInputPoints->Y - tStartCoord.Y;
    for (; nCurrentPointIdx < nbTempPoints - 1; )
    {
        int deltaX = pInputPoints[nCurrentPointIdx + 1].X - pInputPoints[nCurrentPointIdx].X;
        int deltaY = pInputPoints[nCurrentPointIdx + 1].Y - pInputPoints[nCurrentPointIdx].Y;
        if (deltaX == prevDeltaX && deltaY == prevDeltaY)
        {
            ++nbPointsInLine;
            ++nCurrentPointIdx;
        }
        else if (nbPointsInLine > 0)
        {
            pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
            nbPointsInLine = 0;
            ++nCurrentPointIdx;
        }
        else if (prevDeltaX == deltaX || prevDeltaY == deltaY)
        {
            pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
            nbPointsInLine = 0;
            ++nCurrentPointIdx;
        }
        else
        {
            nbPointsInLine = 1;
            deltaX = -2;
            ++nCurrentPointIdx;
        }
        prevDeltaY = deltaY;
        prevDeltaX = deltaX;
    }
    if (nCurrentPointIdx < nbTempPoints)
    {
        pOutPathPoints[nbOutPoints++] = pInputPoints[nCurrentPointIdx];
    }

    return nbOutPoints;
}

static inline int PATH_TestNewTargetPointWF(D2PathMovStrc* pMov, D2ActiveRoomStrc* pRoom, int nCollisionPattern, int nCollisionMask)
{
    pMov->tTargetCoord.X = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nX + pMov->tCurrentCoord.X);
    pMov->tTargetCoord.Y = (unsigned short)(gnDirectionsToAdjacentCellOffsets[pMov->nDirectionIndex].nY + pMov->tCurrentCoord.Y);
    return COLLISION_CheckAnyCollisionWithPattern(pRoom, pMov->tTargetCoord.X, pMov->tTargetCoord.Y, nCollisionPattern, nCollisionMask);
}

// 0x0067C2D0
int __fastcall PATH_ComputePathOrSlideAlongObstacles(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* ptPathInfo = pPathInfo->pDynamicPath;
    D2_ASSERT(((ptPathInfo->pUnit && ptPathInfo->pUnit->dwUnitType == UNIT_PLAYER) || (ptPathInfo->pUnit && ptPathInfo->pUnit->dwUnitType == UNIT_MONSTER)) != 0, 0x2AD);

    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const unsigned char nDist = ptPathInfo->bDistMax;
    int i = 0;
    const D2PathPointStrc tStart = pPathInfo->tStartCoord;
    const D2PathPointStrc tTarget = pPathInfo->tTargetCoord;
    D2PathPointStrc tPrevious = tStart;
    int nDistMax = nDist;
    if (ptPathInfo->hTarget && nDist < 40)
    {
        nDistMax = 40;
    }

    D2PathPointStrc aPathPoints[78];
    int nMajorDirection;
    int nPoints = PATH_BresenhamLine(tStart, tTarget, nDistMax, &nMajorDirection, aPathPoints);
    if (nPoints <= 2)
    {
        return 0;
    }

    for (; i < nPoints; ++i)
    {
        const D2PathPointStrc* pPoint = &aPathPoints[i];
        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, pPoint->X, pPoint->Y, nCollisionPattern, nCollisionMask))
        {
            if (!PATH_FindSubpathWithoutObstacles(pPathInfo, tPrevious, aPathPoints, &i, &nPoints, nDistMax - i, nMajorDirection))
            {
                return PATH_SimplifyToLines(tStart, ptPathInfo->PathPoints, aPathPoints, i);
            }
        }

        tPrevious = aPathPoints[i];
    }

    if (!nPoints)
    {
        return 0;
    }

    return PATH_SimplifyToLines(tStart, ptPathInfo->PathPoints, aPathPoints, nPoints);
}

#include "gen/data/Source/D2Common/Unknown_0067B9C0.inc"
