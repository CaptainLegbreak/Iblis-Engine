#include "D2Common.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Drlg.h"

#include "D2DrlgMaps.h"

struct D2CoordStrc;

struct D2DrlgCoordsStrc;

struct D2DrlgVertexStrc;

struct D2DrlgCoordStrc;

enum D2DrlgGridFlagOperation
{
    DRLGGRID_FLAG_OR = 0,
    DRLGGRID_FLAG_AND = 1,
    DRLGGRID_FLAG_XOR = 2,
    DRLGGRID_FLAG_OVERWRITE = 3,
    DRLGGRID_FLAG_OVERWRITE_IF_ZERO = 4,
    DRLGGRID_FLAG_AND_NEGATED = 5
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordsStrc* pCoords, int nX, int nY); // 0x0066B980

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pGrid, int nX, int nY);

int* __fastcall DRLGGRID_GetGridCellPtr(D2DrlgGridStrc* pGrid, int nX, int nY);

int __fastcall sub_0067C570(D2DrlgGridStrc* pGrid, int nX, int nY);

void __fastcall DRLGGRID_AssignSubArea(D2DrlgGridStrc* pGrid, int* pCellsFlags, D2DrlgCoordsStrc* pCoords, int nStride, int* pCellsRowOffsets);

void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);

extern "C" const char gszDrlgGridSourceFile;

void __fastcall DRLGGRID_OverwriteFlag(int* pFlag, int nFlag);

void __fastcall DRLGGRID_OrFlag(int* pFlag, int nFlag);

void __fastcall DRLGGRID_AndFlag(int* pFlag, int nFlag);

void __fastcall DRLGGRID_XorFlag(int* pFlag, int nFlag);

void __fastcall DRLGGRID_OverwriteFlagIfZero(int* pFlag, int nFlag);

void __fastcall DRLGGRID_AndNegatedFlag(int* pFlag, int nFlag);

int __fastcall DRLGGRID_IsGridValid(D2DrlgGridStrc* pGrid);

static int* __stdcall DRLGGRID_GetCellFlagsPointer(D2DrlgGridStrc* pGrid, int nX, int nY);

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation);

void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation); // 0x0067C600

void __fastcall DRLGGRID_AlterGridFlagAtCoord(D2DrlgGridStrc* pGrid, D2CoordStrc* pCoord, int nFlag, int eOperation);

void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation);

void __fastcall DRLGGRID_AlterBottomAndRightEdgeFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation);

void __fastcall DRLGGRID_AlterFlagsAlongVertexEdge(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag, int eOperation, int bAlterNextVertex); // 0x0067C760

void __fastcall DRLGGRID_SetVertexGridFlags(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag); // 0x0067C890

void __fastcall DRLGGRID_AlterFlagsAlongVertexLine(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, D2DrlgCoordsStrc* pCoords, int nFlag, int eOperation, int nSize); // 0x0067C8E0

void __fastcall DRLGGRID_CopyGridFlags(D2DrlgGridStrc* pDstGrid, D2DrlgGridStrc* pSrcGrid);

void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight);

void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellsFlags, int* pCellsRowOffsets);

void __fastcall DRLGGRID_InitializeGridRowOffsets(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, int nWidth, int nHeight);

void __fastcall DRLGGRID_FillNewCellFlags(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, D2DrlgCoordsStrc* pCoords, int nStride);

void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);

// 0x0067C420
static void __fastcall DRLGGRID_OverwriteFlag(int* pFlag, int nFlag)
{
    *pFlag = nFlag;
}

// 0x0067C430
static void __fastcall DRLGGRID_OrFlag(int* pFlag, int nFlag)
{
    *pFlag |= nFlag;
}

// 0x0067C440
static void __fastcall DRLGGRID_AndFlag(int* pFlag, int nFlag)
{
    *pFlag &= nFlag;
}

// 0x0067C450
static void __fastcall DRLGGRID_XorFlag(int* pFlag, int nFlag)
{
    *pFlag ^= nFlag;
}

// 0x0067C460
static void __fastcall DRLGGRID_OverwriteFlagIfZero(int* pFlag, int nFlag)
{
    *pFlag = *pFlag ? *pFlag : nFlag;
}

// 0x0067C470
static void __fastcall DRLGGRID_AndNegatedFlag(int* pFlag, int nFlag)
{
    *pFlag &= ~nFlag;
}

static void (__fastcall* gpfnDrlgGridFlagOperations[])(int*, int) = // 0x00749BAC
{
    DRLGGRID_OrFlag,
    DRLGGRID_AndFlag,
    DRLGGRID_XorFlag,
    DRLGGRID_OverwriteFlag,
    DRLGGRID_OverwriteFlagIfZero,
    DRLGGRID_AndNegatedFlag,
};

// 0x0067C480
int __fastcall DRLGGRID_IsGridValid(D2DrlgGridStrc* pGrid)
{
    if (pGrid && pGrid->pCellsFlags)
    {
        return 1;
    }

    return 0;
}

// 0x0067C4A0
int __fastcall DRLGGRID_IsPointInsideGridArea(D2DrlgGridStrc* pDrlgGrid, int nX, int nY)
{
    return nX >= 0 && nX < pDrlgGrid->nWidth && nY >= 0 && nY < pDrlgGrid->nHeight ? 1 : 0;
}

// 0x0067C4D0
static int* __stdcall DRLGGRID_GetCellFlagsPointer(D2DrlgGridStrc* pGrid, int nX, int nY)
{
    return &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + nX];
}

// 0x0067C4F0
void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation)
{
    gpfnDrlgGridFlagOperations[eOperation](DRLGGRID_GetCellFlagsPointer(pGrid, nX, nY), nFlag);
}

// 0x0067C520
void __fastcall DRLGGRID_AlterGridFlagAtCoord(D2DrlgGridStrc* pGrid, D2CoordStrc* pCoord, int nFlag, int eOperation)
{
    gpfnDrlgGridFlagOperations[eOperation](DRLGGRID_GetCellFlagsPointer(pGrid, pCoord->nX, pCoord->nY), nFlag);
}

// 0x0067C550
int* __fastcall DRLGGRID_GetGridFlagsPointer(D2DrlgGridStrc* pDrlgGrid, int nX, int nY)
{
    return &pDrlgGrid->pCellsFlags[nX + pDrlgGrid->pCellsRowOffsets[nY]];
}

// 0x0067C570
int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY)
{
    return pDrlgGrid->pCellsFlags[nX + pDrlgGrid->pCellsRowOffsets[nY]];
}

// 0x0067C590
void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation)
{
    for (int nY = 0; nY < pGrid->nHeight; ++nY)
    {
        int* pCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY]];
        for (int nX = 0; nX < pGrid->nWidth; ++nX)
        {
            gpfnDrlgGridFlagOperations[eOperation](pCell, nFlag);
            ++pCell;
        }
    }
}

// 0x0067C600
void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation)
{
    int* pTopCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[0]];
    int* pBottomCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[pGrid->nHeight - 1]];

    for (int nX = 0; nX < pGrid->nWidth; ++nX)
    {
        gpfnDrlgGridFlagOperations[eOperation](pTopCell, nFlag);
        ++pTopCell;
        gpfnDrlgGridFlagOperations[eOperation](pBottomCell, nFlag);
        ++pBottomCell;
    }

    for (int nY = 1; nY < pGrid->nHeight; ++nY)
    {
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY]], nFlag);
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + pGrid->nWidth - 1], nFlag);
    }
}

// 0x0067C6D0
void __fastcall DRLGGRID_AlterBottomAndRightEdgeFlags(D2DrlgGridStrc* pGrid, int nFlag, int eOperation)
{
    int* pCell = &pGrid->pCellsFlags[pGrid->pCellsRowOffsets[pGrid->nHeight - 1]];

    for (int nX = 0; nX < pGrid->nWidth - 1; ++nX)
    {
        gpfnDrlgGridFlagOperations[eOperation](pCell, nFlag);
        ++pCell;
    }

    for (int nY = 0; nY < pGrid->nHeight; ++nY)
    {
        gpfnDrlgGridFlagOperations[eOperation](&pGrid->pCellsFlags[pGrid->pCellsRowOffsets[nY] + pGrid->nWidth - 1], nFlag);
    }
}

// 0x0067C760
void __fastcall DRLGGRID_AlterFlagsAlongVertexEdge(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag, int eOperation, int bAlterNextVertex)
{
    D2DrlgVertexStrc* pNext = pVertex->pNext;

    if (pVertex->nPosX == pNext->nPosX && pVertex->nPosY == pNext->nPosY)
    {
        DRLGGRID_AlterGridFlag(pGrid, pVertex->nPosX, pVertex->nPosY, nFlag, eOperation);
        return;
    }

    int nX;
    int nY;
    int nEndX;
    int nEndY;
    int bHorizontal;

    if (pVertex->nPosX == pNext->nPosX)
    {
        nX = pVertex->nPosX;
        nEndX = pVertex->nPosX;
        bHorizontal = 0;
        if (pVertex->nPosY < pNext->nPosY)
        {
            nY = pVertex->nPosY;
            nEndY = pNext->nPosY;
        }
        else
        {
            nY = pNext->nPosY;
            nEndY = pVertex->nPosY;
        }
    }
    else
    {
        bHorizontal = 1;
        nY = pVertex->nPosY;
        nEndY = pVertex->nPosY;
        if (pVertex->nPosX < pNext->nPosX)
        {
            nX = pVertex->nPosX;
            nEndX = pNext->nPosX;
        }
        else
        {
            nX = pNext->nPosX;
            nEndX = pVertex->nPosX;
        }
    }

    if (bHorizontal)
    {
        ++nX;
    }
    else
    {
        ++nY;
    }

    while (nX != nEndX || nY != nEndY)
    {
        DRLGGRID_AlterGridFlag(pGrid, nX, nY, nFlag, eOperation);
        if (bHorizontal)
        {
            ++nX;
        }
        else
        {
            ++nY;
        }
    }

    DRLGGRID_AlterGridFlag(pGrid, pVertex->nPosX, pVertex->nPosY, nFlag, eOperation);
    if (bAlterNextVertex)
    {
        DRLGGRID_AlterGridFlag(pGrid, pVertex->pNext->nPosX, pVertex->pNext->nPosY, nFlag, eOperation);
    }
}

typedef void (__fastcall* DRLGGRID_FlagOperation)(int* pFlag, int nFlag);
extern DRLGGRID_FlagOperation gpfnDrlgGridFlagOperations[6]; // 0x00749BAC

// 0x0067C890
void __fastcall DRLGGRID_SetVertexGridFlags(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, int nFlag)
{
    D2DrlgVertexStrc* pCurrent = pVertex;
    if (pVertex)
    {
        do
        {
            const int nX = pCurrent->nPosX;
            const int nY = pCurrent->nPosY;
            pCurrent = pCurrent->pNext;
            if (DRLGGRID_IsPointInsideGridArea(pGrid, nX, nY))
            {
                DRLGGRID_AlterGridFlag(pGrid, nX, nY, nFlag, 0);
            }
        }
        while (pCurrent);
    }
}

// 0x0067C8E0
void __fastcall DRLGGRID_AlterFlagsAlongVertexLine(D2DrlgGridStrc* pGrid, D2DrlgVertexStrc* pVertex, D2DrlgCoordsStrc* pCoords, int nFlag, int eOperation, int nSize)
{
    int nX = pVertex->nPosX;
    int nY = pVertex->nPosY;
    int nDiffX = pVertex->pNext->nPosX - nX;
    int nDiffY = pVertex->pNext->nPosY - nY;
    int nStepX = 0;
    int nStepY = 0;

    if (nDiffX < 0)
    {
        nStepX = -1;
        nDiffX = -nDiffX;
    }
    else
    {
        nStepX = 1;
    }

    if (nDiffY < 0)
    {
        nStepY = -1;
        nDiffY = -nDiffY;
    }
    else
    {
        nStepY = 1;
    }

    int nOffsetX = nX - pCoords->nSubtileX;
    int nOffsetY = nY - pCoords->nSubtileY;
    int nError = 0;

    if (nDiffX < nDiffY)
    {
        for (int i = 0; i < nSize; ++i)
        {
            if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX + i, nY))
            {
                DRLGGRID_AlterGridFlag(pGrid, nOffsetX + i, nOffsetY, nFlag, eOperation);
            }
        }

        for (int j = 0; j < nDiffY; ++j)
        {
            nY += nStepY;
            nError += nDiffX;
            if (nError > nDiffY)
            {
                nX += nStepX;
                nError -= nDiffY;
            }

            nOffsetX = nX - pCoords->nSubtileX;
            nOffsetY = nY - pCoords->nSubtileY;
            for (int i = 0; i < nSize; ++i)
            {
                if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX + i, nY))
                {
                    DRLGGRID_AlterGridFlag(pGrid, nOffsetX + i, nOffsetY, nFlag, eOperation);
                }
            }
        }
    }
    else
    {
        for (int i = 0; i < nSize; ++i)
        {
            if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX, nY + i))
            {
                DRLGGRID_AlterGridFlag(pGrid, nOffsetX, nOffsetY + i, nFlag, eOperation);
            }
        }

        for (int j = 0; j < nDiffX; ++j)
        {
            nX += nStepX;
            nError += nDiffY;
            if (nError > nDiffX)
            {
                nY += nStepY;
                nError -= nDiffX;
            }

            nOffsetX = nX - pCoords->nSubtileX;
            nOffsetY = nY - pCoords->nSubtileY;
            for (int i = 0; i < nSize; ++i)
            {
                if (DRLGROOM_AreXYInsideCoordinates(pCoords, nX, nY + i))
                {
                    DRLGGRID_AlterGridFlag(pGrid, nOffsetX, nOffsetY + i, nFlag, eOperation);
                }
            }
        }
    }
}

// 0x0067CB60
void __fastcall DRLGGRID_CopyGridFlags(D2DrlgGridStrc* pDstGrid, D2DrlgGridStrc* pSrcGrid)
{
    memcpy(pDstGrid->pCellsFlags, pSrcGrid->pCellsFlags, sizeof(int) * pSrcGrid->nHeight * pSrcGrid->nWidth);
}

// 0x0067CB80
void __fastcall DRLGGRID_InitializeGridCells(void* pMemPool, D2DrlgGridStrc* pGrid, int nWidth, int nHeight)
{
    pGrid->nWidth = nWidth;
    pGrid->nHeight = nHeight;

    int nSize = sizeof(int) * (nWidth + 1) * nHeight;
    pGrid->pCellsRowOffsets = (int*)sub_0040B430(pMemPool, nSize, ".\\DRLG\\DrlgGrid.cpp", 407, 0);
    memset(pGrid->pCellsRowOffsets, 0, nSize);
    pGrid->pCellsFlags = &pGrid->pCellsRowOffsets[nHeight];

    int nOffset = 0;
    for (int i = 0; i < nHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pGrid->nFlags = 0;
}

// 0x0067CBF0
void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellsFlags, int* pCellsRowOffsets)
{
    pGrid->nWidth = nWidth;
    pGrid->nHeight = nHeight;
    pGrid->pCellsFlags = pCellsFlags;
    memset(pCellsFlags, 0, sizeof(int) * nWidth * nHeight);
    pGrid->pCellsRowOffsets = pCellsRowOffsets;

    int nOffset = 0;
    for (int i = 0; i < nHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pGrid->nFlags = 0;
}

// 0x0067CC60
void __fastcall DRLGGRID_InitializeGridRowOffsets(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, int nWidth, int nHeight)
{
    pGrid->nWidth = nWidth;
    pGrid->nHeight = nHeight;
    pGrid->pCellsFlags = pCellsFlags;
    pGrid->pCellsRowOffsets = (int*)sub_0040B430(pMemPool, sizeof(int) * nHeight, ".\\DRLG\\DrlgGrid.cpp", 464, 0);

    int nOffset = 0;
    for (int i = 0; i < nHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pGrid->nFlags = 1;
}

// 0x0067CCC0
void __fastcall DRLGGRID_FillNewCellFlags(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellsFlags, D2DrlgCoordsStrc* pCoords, int nStride)
{
    pGrid->nWidth = pCoords->nSubtileWidth;
    pGrid->nHeight = pCoords->nSubtileHeight;
    pGrid->pCellsFlags = &pCellsFlags[pCoords->nSubtileY * nStride + pCoords->nSubtileX];
    pGrid->pCellsRowOffsets = (int*)sub_0040B430(pMemPool, sizeof(int) * pCoords->nSubtileHeight, ".\\DRLG\\DrlgGrid.cpp", 492, 0);

    int nOffset = 0;
    for (int i = 0; i < pCoords->nSubtileHeight; ++i)
    {
        pGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nStride;
    }

    pGrid->nFlags = 1;
}

// 0x0067CD30
void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pDrlgGrid, int* pCellPos, D2DrlgCoordStrc* pDrlgCoord, int nWidth, int* pCellFlags)
{
    pDrlgGrid->nWidth = pDrlgCoord->nWidth;
    pDrlgGrid->nHeight = pDrlgCoord->nHeight;
    pDrlgGrid->pCellsFlags = &pCellPos[pDrlgCoord->nPosY * nWidth + pDrlgCoord->nPosX];
    pDrlgGrid->pCellsRowOffsets = pCellFlags;

    int nOffset = 0;
    for (int i = 0; i < pDrlgCoord->nHeight; ++i)
    {
        pDrlgGrid->pCellsRowOffsets[i] = nOffset;
        nOffset += nWidth;
    }

    pDrlgGrid->nFlags = 1;
}

// 0x0067CD90
void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pDrlgGrid)
{
    if (pDrlgGrid->pCellsRowOffsets)
    {
        sub_0040B480(pMemPool, pDrlgGrid->pCellsRowOffsets, ".\\DRLG\\DrlgGrid.cpp", 0x218, 0);
    }

    pDrlgGrid->pCellsFlags = 0;
    pDrlgGrid->pCellsRowOffsets = 0;
}

// 0x0067CDC0
void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid)
{
    pGrid->pCellsFlags = 0;
    pGrid->pCellsRowOffsets = 0;
}

#include "gen/data/Source/D2Common/DRLG/DrlgGrid.inc"
