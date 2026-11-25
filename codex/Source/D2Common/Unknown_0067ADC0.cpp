#include "D2Common.h"

#include "D2PathFind.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2DrlgPresets.h"
#include "D2PathFoWallContext.h"

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

static int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo);


extern const int gaIdaStar_PointCacheHashMaskX[]; // 0x006F1998

extern const int gaIdaStar_PointCacheHashMaskY[]; // 0x006F1B98

// 0x0067ADC0
int __stdcall PATH_AStar_Heuristic(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
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

// 0x0067AE00
D2PathFoWallNodeStrc* __stdcall PATH_AStar_GetNodeFromPendingCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[tPathPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[tPathPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pNode = pContext->aPendingCache[nHash]; pNode != 0; pNode = pNode->pNextCachePoint)
    {
        if (tPathPoint.X == pNode->tPoint.X && tPathPoint.Y == pNode->tPoint.Y)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x0067AE50
D2PathFoWallNodeStrc* __stdcall PATH_AStar_FindPointInVisitedCache(D2PathFoWallContextStrc* pContext, D2PathPointStrc tPathPoint)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[tPathPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[tPathPoint.X & 0x7F]) & 0x7F;
    for (D2PathFoWallNodeStrc* pNode = pContext->aVisitedCache[nHash]; pNode != 0; pNode = pNode->pNextCachePoint)
    {
        if (tPathPoint.X == pNode->tPoint.X && tPathPoint.Y == pNode->tPoint.Y)
        {
            return pNode;
        }
    }

    return 0;
}

typedef unsigned int size_t;

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

typedef int BOOL;

static __forceinline void PATH_AStar_AddChildToNode(D2PathFoWallNodeStrc* pNode, D2PathFoWallNodeStrc* pChild)
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

// 0x0067AEA0
static void PATH_AStar_PushToVisitedCache(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNode)
{
    const int nHash = (gaIdaStar_PointCacheHashMaskY[pNode->tPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[pNode->tPoint.X & 0x7F]) & 0x7F;
    pNode->pNextCachePoint = pContext->aVisitedCache[nHash];
    pContext->aVisitedCache[nHash] = pNode;
}

// emits the static 0x0067AEA0, which the original inlines at its callers and also keeps (not game code)
void sub_M_Emit_0067AEA0(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNode)
{
    PATH_AStar_PushToVisitedCache(pContext, pNode);
}

// 0x0067AED0
static void PATH_AStar_MakeCandidate(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNode)
{
    D2PathFoWallNodeStrc* pCur = pContext->pSortedListByFScore;
    D2PathFoWallNodeStrc* pPrev = 0;
    const int nHash = (gaIdaStar_PointCacheHashMaskY[pNode->tPoint.Y & 0x7F] + gaIdaStar_PointCacheHashMaskX[pNode->tPoint.X & 0x7F]) & 0x7F;
    pNode->pNextCachePoint = pContext->aPendingCache[nHash];
    pContext->aPendingCache[nHash] = pNode;

    const int nFScore = pNode->nFScore;
    for (; pCur; pCur = pCur->pNextSortedByFScore)
    {
        if (pCur->nFScore >= nFScore)
        {
            break;
        }
        pPrev = pCur;
    }

    if (pPrev)
    {
        pPrev->pNextSortedByFScore = pNode;
        pNode->pNextSortedByFScore = pCur;
    }
    else
    {
        pNode->pNextSortedByFScore = pContext->pSortedListByFScore;
        pContext->pSortedListByFScore = pNode;
    }
}

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

static D2PathFoWallNodeStrc* __stdcall PATH_AStar_PopBestScoreForVisit(D2PathFoWallContextStrc* pContext);

static int PATH_AStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode);

// 0x0067AF40
static D2PathFoWallNodeStrc* __stdcall PATH_AStar_PopBestScoreForVisit(D2PathFoWallContextStrc* pContext)
{
    D2PathFoWallNodeStrc* pPopped = pContext->pSortedListByFScore;
    if (!pPopped)
    {
        return 0;
    }

    pContext->pSortedListByFScore = pPopped->pNextSortedByFScore;

    const int nCacheIndex = (gaIdaStar_PointCacheHashMaskX[pPopped->tPoint.X & 0x7F] + gaIdaStar_PointCacheHashMaskY[pPopped->tPoint.Y & 0x7F]) & 0x7F;
    D2PathFoWallNodeStrc* pPreviousPoint = 0;
    for (D2PathFoWallNodeStrc* pCacheEntry = pContext->aPendingCache[nCacheIndex]; pCacheEntry != pPopped; pCacheEntry = pCacheEntry->pNextCachePoint)
    {
        pPreviousPoint = pCacheEntry;
    }

    if (!pPreviousPoint)
    {
        pContext->aPendingCache[nCacheIndex] = pPopped->pNextCachePoint;
    }
    else
    {
        pPreviousPoint->pNextCachePoint = pPopped->pNextCachePoint;
    }
    pPopped->pNextCachePoint = 0;

    const int nHash = (gaIdaStar_PointCacheHashMaskX[pPopped->tPoint.X & 0x7F] + gaIdaStar_PointCacheHashMaskY[pPopped->tPoint.Y & 0x7F]) & 0x7F;
    pPopped->pNextCachePoint = pContext->aVisitedCache[nHash];
    pContext->aVisitedCache[nHash] = pPopped;
    return pPopped;
}

// 0x0067AFE0
static void PATH_AStar_PropagateNewFScoreToChildren(D2PathFoWallContextStrc* pContext, D2PathFoWallNodeStrc* pNewNode)
{
    pContext->aPointsStack[pContext->nStackCount++] = pNewNode;
    while (pContext->nStackCount != 0)
    {
        D2PathFoWallNodeStrc* pCurrent = pContext->aPointsStack[--pContext->nStackCount];
        for (int i = 0; i < 8; ++i)
        {
            D2PathFoWallNodeStrc* pChild = pCurrent->pChildren[i];
            if (!pChild)
            {
                break;
            }

            const short nCost = (pCurrent->tPoint.X == pChild->tPoint.X || pCurrent->tPoint.Y == pChild->tPoint.Y) ? 2 : 3;
            const short nDistance = pCurrent->nBestDistanceFromStart + nCost;
            if (nDistance < pChild->nBestDistanceFromStart)
            {
                pChild->pBestParent = pCurrent;
                pChild->nBestDistanceFromStart = nDistance;
                pChild->nFScore = nDistance + pChild->nHeuristicDistanceToTarget;
                pContext->aPointsStack[pContext->nStackCount++] = pChild;
            }
        }
    }
}

// 0x0067B1C0
D2PathFoWallNodeStrc* __fastcall PATH_AStar_AllocNewNode(D2PathFoWallContextStrc* pContext)
{
    if (pContext->nNodesCount == 200)
    {
        return 0;
    }

    D2PathFoWallNodeStrc* pNode = &pContext->aNodesStorage[pContext->nNodesCount++];
    memset(pNode, 0, sizeof(D2PathFoWallNodeStrc));
    return pNode;
}

// 0x0067B200
static BOOL __stdcall PATH_AStar_EvaluateNeighbor(D2PathFoWallContextStrc* pContext, D2PathPointStrc tNewPointCoord, D2PathPointStrc tTargetCoord, D2PathFoWallNodeStrc* pCurrentNode)
{
    const short nCost = (pCurrentNode->tPoint.X == tNewPointCoord.X || pCurrentNode->tPoint.Y == tNewPointCoord.Y) ? 2 : 3;
    const short nNewPointDistance = pCurrentNode->nBestDistanceFromStart + nCost;

    D2PathFoWallNodeStrc* pNewNode = PATH_AStar_GetNodeFromPendingCache(pContext, tNewPointCoord);
    if (pNewNode)
    {
        PATH_AStar_AddChildToNode(pCurrentNode, pNewNode);
        if (nNewPointDistance < pNewNode->nBestDistanceFromStart)
        {
            pNewNode->pBestParent = pCurrentNode;
            pNewNode->nBestDistanceFromStart = nNewPointDistance;
            pNewNode->nFScore = nNewPointDistance + pNewNode->nHeuristicDistanceToTarget;
        }
        return TRUE;
    }

    pNewNode = PATH_AStar_FindPointInVisitedCache(pContext, tNewPointCoord);
    if (pNewNode)
    {
        PATH_AStar_AddChildToNode(pCurrentNode, pNewNode);
        if (nNewPointDistance < pNewNode->nBestDistanceFromStart)
        {
            pNewNode->pBestParent = pCurrentNode;
            pNewNode->nBestDistanceFromStart = nNewPointDistance;
            pNewNode->nFScore = nNewPointDistance + pNewNode->nHeuristicDistanceToTarget;
            PATH_AStar_PropagateNewFScoreToChildren(pContext, pNewNode);
        }
        return TRUE;
    }

    pNewNode = PATH_AStar_AllocNewNode(pContext);
    if (!pNewNode)
    {
        return FALSE;
    }

    pNewNode->pBestParent = pCurrentNode;
    pNewNode->nBestDistanceFromStart = nNewPointDistance;
    pNewNode->nHeuristicDistanceToTarget = PATH_AStar_Heuristic(tNewPointCoord, tTargetCoord);
    pNewNode->tPoint = tNewPointCoord;
    pNewNode->nFScore = pNewNode->nHeuristicDistanceToTarget + nNewPointDistance;
    PATH_AStar_MakeCandidate(pContext, pNewNode);
    PATH_AStar_AddChildToNode(pCurrentNode, pNewNode);
    return TRUE;
}

// 0x0067B440
static BOOL __stdcall PATH_AStar_ExploreChildren(D2PathFoWallContextStrc* pContext, D2PathPointStrc tTargetCoord, D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode)
{
    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    D2PathPointStrc tNew;

    tNew.X = pNode->tPoint.X - 1;
    tNew.Y = pNode->tPoint.Y - 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X - 1;
    tNew.Y = pNode->tPoint.Y + 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X + 1;
    tNew.Y = pNode->tPoint.Y - 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X + 1;
    tNew.Y = pNode->tPoint.Y + 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X - 1;
    tNew.Y = pNode->tPoint.Y;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X;
    tNew.Y = pNode->tPoint.Y - 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X + 1;
    tNew.Y = pNode->tPoint.Y;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    tNew.X = pNode->tPoint.X;
    tNew.Y = pNode->tPoint.Y + 1;
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, tNew.X, tNew.Y, nCollisionPattern, nCollisionMask) && !PATH_AStar_EvaluateNeighbor(pContext, tNew, tTargetCoord, pNode))
    {
        return FALSE;
    }

    return TRUE;
}

// 0x0067B690
static int PATH_AStar_FlushNodeToDynamicPath(D2PathInfoStrc* pPathInfo, D2PathFoWallNodeStrc* pNode)
{
    D2PathPointStrc* pPathPoints = pPathInfo->pDynamicPath->PathPoints;
    D2PathPointStrc aTempPathPoints[78];
    int nbPoints = 0;
    int nPrevDeltaX = -2;
    int nPrevDeltaY = -2;

    while (pNode && nbPoints < 78)
    {
        if (pNode->pBestParent)
        {
            const int nDeltaX = pNode->tPoint.X - pNode->pBestParent->tPoint.X;
            const int nDeltaY = pNode->tPoint.Y - pNode->pBestParent->tPoint.Y;
            if (nDeltaX != nPrevDeltaX || nDeltaY != nPrevDeltaY)
            {
                aTempPathPoints[77 - nbPoints] = pNode->tPoint;
                ++nbPoints;
                nPrevDeltaX = nDeltaX;
                nPrevDeltaY = nDeltaY;
            }
        }
        pNode = pNode->pBestParent;
    }

    if (nbPoints <= 0 || nbPoints >= 78)
    {
        return 0;
    }

    memcpy(pPathPoints, &aTempPathPoints[78 - nbPoints], sizeof(D2PathPointStrc) * nbPoints);
    return nbPoints;
}

// 0x0067B740
static int PATH_AStar_TargetLocationHasEnoughRoom(D2PathInfoStrc* pPathInfo)
{
    if (!pPathInfo->pDynamicPath->hTarget)
    {
        return 1;
    }
    D2ActiveRoomStrc* pStartRoom = pPathInfo->pStartRoom;
    const int nTargetX = pPathInfo->tTargetCoord.X;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;
    const int nTargetY = pPathInfo->tTargetCoord.Y;
    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY + 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY + 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX - 2, nTargetY + 0, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 0, nTargetY - 2, nCollisionPattern, nCollisionMask))
    {
        goto ReturnOne;
    }

    if (!COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 2, nTargetY + 0, nCollisionPattern, nCollisionMask))
    {
    ReturnOne:
        return 1;
    }

    return !COLLISION_CheckAnyCollisionWithPattern(pStartRoom, nTargetX + 0, nTargetY + 2, nCollisionPattern, nCollisionMask);
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

// 0x0067B850
int __fastcall PATH_AStar_ComputePath(D2PathInfoStrc* pPathInfo)
{
    if (!PATH_AStar_TargetLocationHasEnoughRoom(pPathInfo))
    {
        return 0;
    }

    int nResult = 0;
    D2PathFoWallContextStrc tContext;
    tContext.nNodesCount = 0;
    tContext.pSortedListByFScore = 0;
    tContext.nStackCount = 0;
    memset(tContext.aPendingCache, 0, sizeof(tContext.aPendingCache));
    memset(tContext.aVisitedCache, 0, sizeof(tContext.aVisitedCache));

    const D2PathPointStrc tStartCoord = pPathInfo->tStartCoord;
    const D2PathPointStrc tTargetCoord = pPathInfo->tTargetCoord;
    D2PathFoWallNodeStrc* pStartNode = PATH_AStar_GetNewNode(&tContext);
    pStartNode->nBestDistanceFromStart = 0;
    const unsigned short nDistToTarget = PATH_AStar_HeuristicInline(tStartCoord, tTargetCoord);
    pStartNode->nHeuristicDistanceToTarget = nDistToTarget;
    pStartNode->nFScore = nDistToTarget;
    pStartNode->tPoint = tStartCoord;
    PATH_AStar_MakeCandidate(&tContext, pStartNode);

    D2PathFoWallNodeStrc* pBestNode = 0;
    for (D2PathFoWallNodeStrc* pCur = PATH_AStar_PopBestScoreForVisit(&tContext); pCur; pCur = PATH_AStar_PopBestScoreForVisit(&tContext))
    {
        if (!pBestNode
            || pCur->nHeuristicDistanceToTarget < pBestNode->nHeuristicDistanceToTarget
            || (pCur->nHeuristicDistanceToTarget == pBestNode->nHeuristicDistanceToTarget
                && pCur->nBestDistanceFromStart > pBestNode->nBestDistanceFromStart + 5))
        {
            pBestNode = pCur;
        }

        if (pCur->nHeuristicDistanceToTarget == 0 || !PATH_AStar_ExploreChildren(&tContext, tTargetCoord, pPathInfo, pCur))
        {
            break;
        }
    }

    if (pBestNode)
    {
        nResult = PATH_AStar_FlushNodeToDynamicPath(pPathInfo, pBestNode);
    }
    return nResult;
}

int __stdcall sub_Emit_0067B740(D2PathInfoStrc* pPathInfo)
{
    return PATH_AStar_TargetLocationHasEnoughRoom(pPathInfo);
}

#include "gen/data/Source/D2Common/Unknown_0067ADC0.inc"
