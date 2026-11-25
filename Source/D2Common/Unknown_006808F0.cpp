#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgRooms.h"

struct D2DrlgCoordStrc;
struct D2DrlgVertexStrc;
struct D2DrlgOutdoorInfoStrc;
struct D2DrlgStrc;
struct D2DrlgOutdoorRoomStrc;
struct D2DrlgOrthStrc;









void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570
void __fastcall DRLGGRID_AlterFlagsAlongVertexLine(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, D2DrlgCoordStrc* pCoords, int nFlag, int eOperation, int nSize); // 0x0067C8E0
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight); // 0x0067CB80
extern const unsigned char gRoadPatternCodes[256]; // 0x006F2700


int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674200
void __fastcall DRLGOUTWILD_GetBridgeCoords(D2DrlgLevelStrc* pLevel, int* pX, int* pY); // 0x0067FC20
void __stdcall sub_00681000(D2DrlgLevelStrc* pLevel);

// 0x006808F0
static int sub_006808F0(int pFlags[3][3])
{
    if (!pFlags[1][1])
    {
        return 0;
    }

    int nCode = 0;
    if (pFlags[2][2]) ++nCode;
    nCode <<= 1;
    if (pFlags[2][1]) ++nCode;
    nCode <<= 1;
    if (pFlags[2][0]) ++nCode;
    nCode <<= 1;
    if (pFlags[1][2]) ++nCode;
    nCode <<= 1;
    if (pFlags[1][0]) ++nCode;
    nCode <<= 1;
    if (pFlags[0][2]) ++nCode;
    nCode <<= 1;
    if (pFlags[0][1]) ++nCode;
    nCode <<= 1;
    if (pFlags[0][0]) ++nCode;
    return nCode;
}

// 0x00680950
static void __stdcall sub_00680950(D2DrlgGridStrc* pGrid, int pFlags[3][3], int nX, int nY)
{
    pFlags[0][0] = pFlags[0][1];
    pFlags[0][1] = pFlags[0][2];
    pFlags[0][2] = pFlags[1][0];
    pFlags[1][0] = pFlags[1][1];
    pFlags[1][1] = pFlags[1][2];
    pFlags[1][2] = pFlags[2][0];
    pFlags[2][0] = pFlags[2][1];
    pFlags[2][1] = pFlags[2][2];
    pFlags[0][2] = DRLGGRID_GetGridEntry(pGrid, nX - 1, nY - 1);
    pFlags[1][2] = DRLGGRID_GetGridEntry(pGrid, nX, nY - 1);
    pFlags[2][2] = DRLGGRID_GetGridEntry(pGrid, nX + 1, nY - 1);
}

// 0x006809C0
static void __stdcall sub_006809C0(D2DrlgGridStrc* pGrid, int pFlags[3][3], int nX, int nY)
{
    pFlags[0][2] = DRLGGRID_GetGridEntry(pGrid, nX - 1, nY - 1);
    pFlags[0][1] = DRLGGRID_GetGridEntry(pGrid, nX - 1, nY);
    pFlags[0][0] = DRLGGRID_GetGridEntry(pGrid, nX - 1, nY + 1);
    pFlags[1][2] = DRLGGRID_GetGridEntry(pGrid, nX, nY - 1);
    pFlags[2][2] = DRLGGRID_GetGridEntry(pGrid, nX + 1, nY - 1);
    pFlags[1][1] = DRLGGRID_GetGridEntry(pGrid, nX, nY);
    pFlags[2][1] = DRLGGRID_GetGridEntry(pGrid, nX + 1, nY);
    pFlags[1][0] = DRLGGRID_GetGridEntry(pGrid, nX, nY + 1);
    pFlags[2][0] = DRLGGRID_GetGridEntry(pGrid, nX + 1, nY + 1);
}

// 0x00680A70
static void sub_00680A70(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    D2DrlgCoordStrc tCoords = pRoom->pDrlgCoord;
    tCoords.nPosX -= 1;
    tCoords.nPosY -= 1;
    tCoords.nWidth += 3;
    tCoords.nHeight += 3;

    for (int i = 0; i < pInfo->nVertices; ++i)
    {
        for (D2DrlgVertexStrc* pVertex = pInfo->pRoads[i]; pVertex; pVertex = pVertex->pNext)
        {
            if (pVertex->pNext)
            {
                DRLGGRID_AlterFlagsAlongVertexLine(&pOutdoor->tGrid3C, pVertex, &tCoords, 1, 0, 2);
            }
        }
    }
}

// 0x00680B10
static void __stdcall sub_00680B10(D2DrlgRoomStrc* pRoom)
{
    D2DrlgOutdoorRoomStrc* pOutdoor = pRoom->pOutdoor;
    for (int nX = 1; nX <= pRoom->pDrlgCoord.nWidth + 1; ++nX)
    {
        int aFlags[3][3];
        int nY = pRoom->pDrlgCoord.nHeight + 1;
        sub_006809C0(&pOutdoor->tGrid3C, aFlags, nX, nY);

        for (; nY >= 1; --nY)
        {
            int nCode = sub_006808F0(aFlags);
            if (nCode)
            {
                unsigned char nRoadCode = gRoadPatternCodes[nCode];
                if (nRoadCode)
                {
                    DRLGGRID_AlterGridFlag(&pOutdoor->tGrid28, nX - 1, nY - 1, (nRoadCode << 8) | 0x82, 3);
                }
            }

            if (nY > 1)
            {
                sub_00680950(&pOutdoor->tGrid3C, aFlags, nX, nY - 1);
            }
        }
    }
}

// 0x00680C80
void __fastcall sub_00680C80(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pRoom)
{
    DRLGGRID_InitializeGridCells(pLevel->pDrlg->pMempool, &pRoom->pOutdoor->tGrid3C, pRoom->pDrlgCoord.nWidth + 3, pRoom->pDrlgCoord.nHeight + 3);
    sub_00680A70(pLevel, pRoom);
    sub_00680B10(pRoom);
}

#include "gen/data/Source/D2Common/Unknown_006808F0.inc"

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

// 0x00680D70
void __stdcall sub_00680D70(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    pOutdoors->nVertices = 0;

    for (D2DrlgOrthStrc* pRoomData = pOutdoors->pRoomData; pRoomData; pRoomData = pRoomData->pNext)
    {
        D2DrlgLevelStrc* pRoomLevel = pRoomData->pLevel;
        D2DrlgVertexStrc* pVertex;
        switch (pRoomLevel->eLevelId)
        {
        case 1:
            pVertex = &pOutdoors->pVertices[pOutdoors->nVertices];
            pVertex->nDirection = pRoomData->nDirection;

            switch (pRoomData->nDirection)
            {
            case 0:
                pVertex->nPosX = pRoomLevel->nPosX + 59;
                pVertex->nPosY = pRoomLevel->nPosY + 19;
                break;

            case 1:
                pVertex->nPosX = pRoomLevel->nPosX + 29;
                pVertex->nPosY = pRoomLevel->nPosY + 35;
                break;

            case 2:
                pVertex->nPosX = pRoomLevel->nPosX + 4;
                pVertex->nPosY = pRoomLevel->nPosY + 22;
                break;

            case 3:
                pVertex->nPosX = pRoomLevel->nPosX + 29;
                pVertex->nPosY = pRoomLevel->nPosY + 3;
                break;

            default:
                break;
            }

            ++pOutdoors->nVertices;
            break;

        case 26:
            pVertex = &pOutdoors->pVertices[pOutdoors->nVertices];
            pVertex->nPosX = pRoomLevel->nPosX + 27;
            pVertex->nPosY = pRoomLevel->nPosY + 13;
            pVertex->nDirection = 1;
            ++pOutdoors->nVertices;
            break;
        }
    }

    for (int i = 0; i < pOutdoors->nGridWidth; ++i)
    {
        for (int j = 0; j < pOutdoors->nGridHeight; ++j)
        {
            const int nGrid0Entry = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], i, j);
            const unsigned int nPacked = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], i, j);

            D2DrlgVertexStrc* pVertex = &pOutdoors->pVertices[pOutdoors->nVertices];
            pVertex->nPosX = pLevel->nPosX + 8 * i + 3;
            pVertex->nPosY = pLevel->nPosY + 8 * j + 3;
            pVertex->nDirection = 4;

            const int nPickedFile = (nPacked >> 16) & 0xF;

            switch (nGrid0Entry)
            {
            case 4:
                if (nPickedFile == 3) pVertex->nDirection = 3;
                break;
            case 5:
                if (nPickedFile == 3) pVertex->nDirection = 0;
                break;
            case 6:
                if (nPickedFile == 3) pVertex->nDirection = 1;
                break;
            case 7:
                if (nPickedFile == 3) pVertex->nDirection = 2;
                break;
            case 24:
                pVertex->nDirection = 1;
                break;
            case 25:
                pVertex->nDirection = 0;
                break;
            case 51:
                pVertex->nDirection = nPickedFile != 0;
                break;
            case 52:
                pVertex->nDirection = nPickedFile != 0;
                break;
            case 28:
                if (nPickedFile == 1 && i == pOutdoors->nGridWidth - 2) pVertex->nDirection = 2;
                break;
            default:
                break;
            }

            if (pVertex->nDirection != 4)
            {
                ++pOutdoors->nVertices;
            }
        }
    }

    for (int i = 0; i < pOutdoors->nVertices; ++i)
    {
        DRLGOUTDOORS_CalculatePathCoordinates(pLevel, &pOutdoors->pVertices[i], &pOutdoors->pVertices[6 + i]);
    }
}
