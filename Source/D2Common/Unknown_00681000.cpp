#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DrlgRooms.h"

struct D2DrlgVertexStrc;

struct D2DrlgOrthStrc;

struct D2DrlgOutdoorInfoStrc;

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674200

void __fastcall DRLGOUTWILD_GetBridgeCoords(D2DrlgLevelStrc* pLevel, int* pX, int* pY); // 0x0067FC20

extern const int gnOutdoorScanXOffsets[4]; // 0x006F2810

extern const int gnOutdoorScanYOffsets[4]; // 0x006F2800

struct D2DrlgGridStrc;

void __fastcall DRLGGRID_SetVertexGridFlags(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag); // 0x0067C890

void __stdcall sub_00680D70(D2DrlgLevelStrc* pLevel); // 0x00680D70

void __stdcall sub_00681000(D2DrlgLevelStrc* pLevel); // 0x00681000

int __fastcall sub_006817D0(D2DrlgLevelStrc* pLevel, int nRoad); // 0x006817D0

D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection); // 0x0067CDD0

extern const int gnAct1PathOffsetX[4]; // 0x006F2820

extern const int gnAct1PathOffsetY[4]; // 0x006F2830

// build: symbol ?DRLGOUTDOORS_CalculatePathCoordinates@@YAXPAUD2DrlgLevelStrc@@PAUD2DrlgVertexStrc@@1@Z 0x00680CC0
static void DRLGOUTDOORS_CalculatePathCoordinates(D2DrlgLevelStrc* pLevel, D2DrlgVertexStrc* pVertex1, D2DrlgVertexStrc* pVertex2)
{
    pVertex2->nPosX = pVertex1->nPosX - pLevel->nPosX;
    pVertex2->nPosY = pVertex1->nPosY - pLevel->nPosY;

    switch (pVertex1->nDirection)
    {
    case 0:
        pVertex2->nPosX = 8 * (pVertex2->nPosX / 8) + 11;
        break;

    case 1:
        pVertex2->nPosY = 8 * (pVertex2->nPosY / 8) + 11;
        break;

    case 2:
        pVertex2->nPosX = 8 * (pVertex2->nPosX / 8) - 5;
        break;

    case 3:
        pVertex2->nPosY = 8 * (pVertex2->nPosY / 8) - 5;
        break;

    default:
        break;
    }

    pVertex2->nPosX += pLevel->nPosX;
    pVertex2->nPosY += pLevel->nPosY;
}

// 0x00681000
void __stdcall sub_00681000(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nX = -1;
    int nY = -1;

    if (pOutdoors->dwFlags & 0x10 && (DRLGOUTWILD_GetBridgeCoords(pLevel, &nX, &nY), nX != -1))
    {
        const int nPosX = pLevel->nPosX + 8 * nX + 3;
        const int nPosY = pLevel->nPosY + 8 * nY + 3;

        for (int i = 0; i < pOutdoors->nVertices; ++i)
        {
            if (pOutdoors->pVertices[i].nPosX > nPosX)
            {
                pOutdoors->pVertices[18 + i].nPosX = nPosX + 8;
                pOutdoors->pVertices[18 + i].nDirection = 0;
                pOutdoors->pVertices[18 + i].nPosY = nPosY;
            }
            else
            {
                pOutdoors->pVertices[18 + i].nPosX = nPosX;
                pOutdoors->pVertices[18 + i].nDirection = 2;
                pOutdoors->pVertices[18 + i].nPosY = nPosY;
            }
        }
    }
    else
    {
        const int* pnCount = &pOutdoors->nVertices;
        for (int i = 0; i < *pnCount; ++i)
        {
            if (!i)
            {
                int nPosX = 0;
                int nPosY = 0;
                int j = 0;
                if (*pnCount == 1)
                {
                    nPosX = pOutdoors->nGridWidth / 2;
                    nPosY = pOutdoors->nGridHeight / 2;
                }
                else
                {
                    for (int m = 0; m < *pnCount; ++m)
                    {
                        nPosX += pOutdoors->pVertices[m].nPosX - pLevel->nPosX;
                        nPosY += pOutdoors->pVertices[m].nPosY - pLevel->nPosY;
                    }
                    nPosX /= 8 * pOutdoors->nVertices;
                    nPosY /= 8 * pOutdoors->nVertices;
                }
                int bBreak = 0;
                for (; j < 8; ++j)
                {
                    if (bBreak)
                    {
                        break;
                    }

                    for (int k = 0; k < 4; ++k)
                    {
                        nX = nPosX + j * gnOutdoorScanXOffsets[k];
                        nY = nPosY + j * gnOutdoorScanYOffsets[k];

                        if (nX >= 0 && nX < pOutdoors->nGridWidth && nY >= 0 && nY < pOutdoors->nGridHeight)
                        {
                            if (DRLGOUTDOORS_TestGridCellSpawnValid(pLevel, nX, nY))
                            {
                                bBreak = 1;
                                break;
                            }
                        }
                    }
                }

                pOutdoors->pVertices[18].nPosX = pLevel->nPosX + 8 * nX + 3;
                pOutdoors->pVertices[18].nPosY = pLevel->nPosY + 8 * nY + 3;
                pOutdoors->pVertices[18].nDirection = 4;
            }
            else
            {
                pOutdoors->pVertices[18 + i].nPosX = pOutdoors->pVertices[18].nPosX;
                pOutdoors->pVertices[18 + i].nPosY = pOutdoors->pVertices[18].nPosY;
                pOutdoors->pVertices[18 + i].nDirection = 4;
            }
        }
    }

    for (int i = 0; i < pOutdoors->nVertices; ++i)
    {
        DRLGOUTDOORS_CalculatePathCoordinates(pLevel, &pOutdoors->pVertices[18 + i], &pOutdoors->pVertices[12 + i]);
    }
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

// 0x00681240
static void __stdcall sub_00681240(D2DrlgLevelStrc* pLevel, int nRoad)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pRoads[nRoad];
    int nRand = SEED_RollRandomNumber(&pLevel->pSeed) & 3;
    if (!pVertex)
    {
        return;
    }

    D2DrlgRoadStrc* pRoad = (D2DrlgRoadStrc*)((char*)pOutdoors + 20 * nRoad);
    if (pRoad->nStartType != 4)
    {
        D2DrlgVertexStrc* pNew = DRLGVER_AllocVertex(pMemPool, 0);
        pNew->nPosX = pRoad->tStart.nX;
        pNew->nPosY = pRoad->tStart.nY;
        pNew->pNext = pVertex;
        pOutdoors->pRoads[nRoad] = pNew;
    }

    pVertex->nPosX = pRoad->tStartInner.nX;
    pVertex->nPosY = pRoad->tStartInner.nY;

    for (pVertex = pVertex->pNext; pVertex; pVertex = pVertex->pNext)
    {
        if (!pVertex->pNext)
        {
            pVertex->nPosX = pRoad->tEndInner.nX;
            pVertex->nPosY = pRoad->tEndInner.nY;
            D2DrlgVertexStrc* pNew = DRLGVER_AllocVertex(pMemPool, 0);
            pNew->nPosX = pRoad->tEnd.nX;
            pNew->nPosY = pRoad->tEnd.nY;
            pVertex->pNext = pNew;
            return;
        }

        int nOffsetX = ((SEED_RollRandomNumber(&pLevel->pSeed) & 1) + 2) * gnAct1PathOffsetX[nRand];
        int nOffsetY = ((SEED_RollRandomNumber(&pLevel->pSeed) & 1) + 2) * gnAct1PathOffsetY[nRand];
        nRand = (nRand + 1) % 4;
        pVertex->nPosX *= 8;
        pVertex->nPosY *= 8;
        pVertex->nPosX = pLevel->nPosX + pVertex->nPosX + nOffsetX + 3;
        pVertex->nPosY = pLevel->nPosY + pVertex->nPosY + nOffsetY + 3;
    }
}

// 0x00681420
void __fastcall DRLGOUTDOORS_SpawnAct1DirtPaths(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    sub_00680D70(pLevel);
    sub_00681000(pLevel);

    for (int nPath = 0; nPath < pOutdoors->nVertices; ++nPath)
    {
        if (sub_006817D0(pLevel, nPath))
        {
            DRLGGRID_SetVertexGridFlags(&pOutdoors->pGrid[2], pOutdoors->pRoads[nPath], 0x80);
            sub_00681240(pLevel, nPath);
        }
    }
}

#include "gen/data/Source/D2Common/Unknown_00681000.inc"
