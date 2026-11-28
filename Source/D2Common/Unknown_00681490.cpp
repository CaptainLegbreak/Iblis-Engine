#include "D2Drlg.h"

#include "D2Common.h"
#include "D2CommonInternal.h"

#include "D2DrlgMaps.h"

#include "D2DrlgRooms.h"

static D2DrlgPathNodeStrc* __stdcall sub_00681630_SearchRoad(D2DrlgPathSearchStrc* pSearch, int nMaxCost, D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pGoal);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);


int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY);          // 0x0066B980

extern const unsigned char gPathTurns[4][4]; // 0x006F2840

extern const char gPathStepY[4]; // 0x006F2850

extern const char gPathStepX[4]; // 0x006F2854

// 0x00681490
static D2DrlgPathNodeStrc* sub_00681490_AllocPathNode(D2DrlgPathSearchStrc* pSearch)
{
    if (pSearch->nNodes == 900)
    {
        return 0;
    }

    D2DrlgPathNodeStrc* pNode = &pSearch->tNodes[pSearch->nNodes++];
    memset(pNode, 0, sizeof(D2DrlgPathNodeStrc));
    return pNode;
}

// 0x006814E0
static int __stdcall sub_006814E0_EstimateCost(int nX1, int nY1, int nX2, int nY2)
{
    int nDiffX = nX1 - nX2;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = nY1 - nY2;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    int nMin = nDiffX < nDiffY ? nDiffX : nDiffY;
    int nMax = nDiffX > nDiffY ? nDiffX : nDiffY;
    return nMin + 2 * nMax;
}

// 0x00681510
static int __stdcall sub_00681510_GetStepCost(D2DrlgPathNodeStrc* pNode, int nX, int nY)
{
    return (pNode->nX == nX || pNode->nY == nY) ? 2 : 3;
}

// 0x00681540
static const unsigned char* __stdcall sub_00681540_GetTurnTable(unsigned char nDirection, unsigned char nBase)
{
    return gPathTurns[(unsigned char)(nDirection - nBase) & 3];
}


// 0x00681560
static D2DrlgPathNodeStrc* __stdcall sub_00681560_NextTurn(D2DrlgPathNodeStrc* pNode, D2DrlgPathNodeStrc** ppStart)
{
    if (pNode->nTried < 4)
    {
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
    }
    ++pNode->nTried;

    while (pNode->nTried == 3)
    {
        if (pNode == *ppStart)
        {
            return 0;
        }

        pNode = pNode->pParent;
        ++pNode->pTurn;
        pNode->nDirection = (*pNode->pTurn + pNode->nDirection) & 3;
        ++pNode->nTried;
    }

    return pNode;
}

// 0x006815C0
static int __stdcall sub_006815C0_CanStep(D2DrlgVertexStrc* pGoal, int nX, int nY, D2DrlgLevelStrc* pLevel, D2DrlgPathNodeStrc* pNode)
{
    if (nX == pGoal->nPosX && nY == pGoal->nPosY)
    {
        return 1;
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (!DRLGROOM_AreXYInsideCoordinates(&pInfo->tCoords, nX, nY) || (DRLGGRID_GetGridEntry(&pInfo->pGrid[2], nX, nY) & 0x200))
    {
        return 0;
    }

    for (D2DrlgPathNodeStrc* pParent = pNode; pParent; pParent = pParent->pParent)
    {
        if (pParent->nX == nX && pParent->nY == nY)
        {
            return 0;
        }
    }

    return 1;
}

// 0x00681630
static D2DrlgPathNodeStrc* __stdcall sub_00681630_SearchRoad(D2DrlgPathSearchStrc* pSearch, int nMaxCost, D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pGoal)
{
    D2DrlgPathNodeStrc* pNode = pSearch->pStart;
    int nGoalX = pGoal->nPosX;
    int nGoalY = pGoal->nPosY;

    while (1)
    {
        if (pNode->nX == nGoalX && pNode->nY == nGoalY)
        {
            return pNode;
        }

        int nX = gPathStepX[pNode->nDirection] + pNode->nX;
        int nY = gPathStepY[pNode->nDirection] + pNode->nY;
        if (!sub_006815C0_CanStep(pGoal, nX, nY, pLevel, pNode))
        {
            pNode = sub_00681560_NextTurn(pNode, &pSearch->pStart);
            if (!pNode)
            {
                return 0;
            }
            continue;
        }

        int nSpent = pNode->nSpent + sub_00681510_GetStepCost(pNode, nX, nY);

        const int rawX = nX - nGoalX;
        int dx = rawX < 0 ? -rawX : rawX;
        const int rawY = nY - nGoalY;
        int dy = rawY < 0 ? -rawY : rawY;
        int nMin = dx;
        if (dx >= dy)
        {
            nMin = dy;
            if (dx > dy)
                dy = dx;
        }
        int nEstimate = nMin + 2 * dy;
        int nCost = nEstimate + nSpent;
        if (nCost > nMaxCost)
        {
            pNode = sub_00681560_NextTurn(pNode, &pSearch->pStart);
            if (!pNode)
            {
                return 0;
            }
            continue;
        }

        if (!pNode->pChild)
        {
            pNode->pChild = sub_00681490_AllocPathNode(pSearch);
            if (!pNode->pChild)
            {
                return 0;
            }
            pNode->pChild->pParent = pNode;
        }

        pNode = pNode->pChild;
        pNode->nEstimate = nEstimate;
        pNode->nCost = nCost;
        pNode->nSpent = nSpent;
        pNode->nTried = 0;
        int nBase = PATH_GetFirstDirectionXY(nX, nY, nGoalX, nGoalY) / 2;
        pNode->pTurn = sub_00681540_GetTurnTable(pNode->pParent->nDirection, nBase);
        pNode->nDirection = (*pNode->pTurn + nBase) & 3;
        pNode->nX = nX;
        pNode->nY = nY;
    }
}

// emits the static 0x006814E0, which the original inlines into 0x00681630 and also keeps (not game code)
D2DrlgPathNodeStrc* __stdcall sub_M_Emit_006814E0(D2DrlgPathSearchStrc* pSearch, int nMaxCost, D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pGoal)
{
    D2DrlgPathNodeStrc* pNode = pSearch->pStart;
    int nGoalX = pGoal->nPosX;
    int nGoalY = pGoal->nPosY;

    while (1)
    {
        if (pNode->nX == nGoalX && pNode->nY == nGoalY)
        {
            return pNode;
        }

        int nX = gPathStepX[pNode->nDirection] + pNode->nX;
        int nY = gPathStepY[pNode->nDirection] + pNode->nY;
        if (sub_006815C0_CanStep(pGoal, nX, nY, pLevel, pNode))
        {
            int nSpent = pNode->nSpent + sub_00681510_GetStepCost(pNode, nX, nY);
            int nEstimate = sub_006814E0_EstimateCost(nX, nY, nGoalX, nGoalY);
            int nCost = nEstimate + nSpent;
            if (nCost <= nMaxCost)
            {
                if (!pNode->pChild)
                {
                    pNode->pChild = sub_00681490_AllocPathNode(pSearch);
                    if (!pNode->pChild)
                    {
                        return 0;
                    }
                    pNode->pChild->pParent = pNode;
                }

                pNode = pNode->pChild;
                pNode->nEstimate = nEstimate;
                pNode->nCost = nCost;
                pNode->nSpent = nSpent;
                pNode->nTried = 0;
                int nBase = PATH_GetFirstDirectionXY(nX, nY, nGoalX, nGoalY) / 2;
                pNode->pTurn = sub_00681540_GetTurnTable(pNode->pParent->nDirection, nBase);
                pNode->nDirection = (*pNode->pTurn + nBase) & 3;
                pNode->nX = nX;
                pNode->nY = nY;
                continue;
            }
        }

        pNode = sub_00681560_NextTurn(pNode, &pSearch->pStart);
        if (!pNode)
        {
            return 0;
        }
    }
}

// 0x006817D0
int __fastcall sub_006817D0_BuildRoad(D2DrlgLevelStrc* pLevel, int nRoad)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgVertexStrc tGoal = {};

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    D2DrlgVertexStrc tFrom;
    tFrom.nPosX = (pInfo->pVertices[nRoad + 6].nPosX - pLevel->nPosX) / 8;
    tFrom.nPosY = (pInfo->pVertices[nRoad + 6].nPosY - pLevel->nPosY) / 8;
    tGoal.nPosX = (pInfo->pVertices[nRoad + 12].nPosX - pLevel->nPosX) / 8;
    tGoal.nPosY = (pInfo->pVertices[nRoad + 12].nPosY - pLevel->nPosY) / 8;

    int nDiffX = tFrom.nPosX - tGoal.nPosX;
    if (nDiffX < 0)
        nDiffX = -nDiffX;
    int nDiffY = tFrom.nPosY - tGoal.nPosY;
    if (nDiffY < 0)
        nDiffY = -nDiffY;
    if (nDiffX + nDiffY < 2)
    {
        pInfo->pRoads[nRoad] = DRLGVER_AllocVertex(pMemPool, 0);
        pInfo->pRoads[nRoad]->nPosX = tFrom.nPosX;
        pInfo->pRoads[nRoad]->nPosY = tFrom.nPosY;
        D2DrlgVertexStrc* pGoalVertex = DRLGVER_AllocVertex(pMemPool, 0);
        pInfo->pRoads[nRoad]->pNext = pGoalVertex;
        pInfo->pRoads[nRoad]->pNext->nPosX = tGoal.nPosX;
        pInfo->pRoads[nRoad]->pNext->nPosY = tGoal.nPosY;
        return 1;
    }

    D2DrlgPathSearchStrc tSearch;
    D2DrlgPathNodeStrc tStart;
    int nDirection = PATH_GetFirstDirectionXY(tFrom.nPosX, tFrom.nPosY, tGoal.nPosX, tGoal.nPosY) / 2;
    tStart.nSpent = 0;
    int nDX = tFrom.nPosX - tGoal.nPosX;
    if (nDX < 0)
        nDX = -nDX;
    const int nRawY = tFrom.nPosY - tGoal.nPosY;
    const int nDY = nRawY < 0 ? -nRawY : nRawY;
    int nMin = nDX;
    int nMax = nDX;
    if (nDX >= nDY)
        nMin = nDY;
    if (nDX <= nDY)
        nMax = nDY;
    int nEstimate = nMin + 2 * nMax;
    tStart.nY = tFrom.nPosY;
    tStart.nDirection = nDirection & 3;
    memset(tSearch.tNodes, 0, sizeof(D2DrlgPathNodeStrc));
    tSearch.pStart = tSearch.tNodes;
    tStart.nX = tFrom.nPosX;
    int nMaxCost = nEstimate + nEstimate / 2;
    tStart.nEstimate = nEstimate;
    tStart.nCost = nEstimate;
    tStart.nTried = -1;
    tStart.pTurn = gPathTurns[0];
    tStart.pChild = 0;
    tStart.pParent = 0;
    tSearch.nNodes = 1;
    int nLimit = nMaxCost + 35;

    do
    {
        *tSearch.pStart = tStart;
        D2DrlgPathNodeStrc* pNode = sub_00681630_SearchRoad(&tSearch, nMaxCost, pLevel, &tGoal);
        nMaxCost += 5;
        if (tSearch.nNodes >= 900)
        {
            return 0;
        }

        tSearch.nNodes = 1;
        if (pNode)
        {
            D2DrlgVertexStrc* pVertex = 0;
            do
            {
                if (pInfo->pRoads[nRoad])
                {
                    pVertex = pVertex->pNext = DRLGVER_AllocVertex(pMemPool, 0);
                }
                else
                {
                    pVertex = pInfo->pRoads[nRoad] = DRLGVER_AllocVertex(pMemPool, 0);
                }

                pVertex->nPosX = pNode->nX;
                pVertex->nPosY = pNode->nY;
                pNode = pNode->pParent;
            }
            while (pNode);

            return 1;
        }
    }
    while (nMaxCost < nLimit);

    return 0;
}

#pragma pack(push, 1)
struct d2data_006F2850_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_006F2854_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00749DA4_t
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

extern "C" const struct d2data_006F2850_t gData_006F2850; // 0x006F2850
extern "C" const struct d2data_006F2854_t gData_006F2854; // 0x006F2854
extern "C" struct d2data_00749DA4_t gData_00749DA4; // 0x00749DA4

extern const unsigned char gPathTurns[4][4] = {
    { 0, 1, 2, 3 },
    { 0, 1, 1, 1 },
    { 3, 2, 1, 2 },
    { 0, 3, 2, 1 }
}; // 0x006F2840

extern "C" const struct d2data_006F2850_t gData_006F2850 = {
    { 0x00, 0x01, 0x00, 0xFF }
}; // 0x006F2850
#pragma comment(linker, "/alternatename:?gPathStepY@@3QBDB=_gData_006F2850")

extern "C" const struct d2data_006F2854_t gData_006F2854 = {
    { 0x01, 0x00, 0xFF }
}; // 0x006F2854
#pragma comment(linker, "/alternatename:?gPathStepX@@3QBDB=_gData_006F2854")

extern "C" struct d2data_00749DA4_t gData_00749DA4 = {
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
}; // 0x00749DA4
