#include "D2Drlg.h"
#include "D2DrlgMaps.h"

struct D2DrlgCoordStrc;

struct D2DrlgVertexStrc;

struct D2DrlgOrthStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" const char* __cdecl sub_00408090();

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void __stdcall DRLGVER_SplitVerticesAtOrths(void* pMemPool, D2DrlgVertexStrc* pCurrentVertex, D2DrlgCoordStrc* pDrlgCoord, unsigned char nDirection, D2DrlgOrthStrc* pCurrentRoomData); // 0x0067CE20

D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection);

static void __stdcall DRLGVER_MarkVertex(D2DrlgVertexStrc* pVertex, int bInit);

static void __fastcall DRLGVER_MakeVerticesRelative(D2DrlgCoordStrc* pCoords, D2DrlgVertexStrc* pFirst);

void __fastcall DRLGVER_CreateVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex, D2DrlgCoordStrc* pCoords, unsigned char nDirection, D2DrlgOrthStrc* pOrth); // 0x0067D050

void __fastcall DRLGVER_ReverseVertexList(D2DrlgVertexStrc** ppVertex);

void __fastcall DRLGVER_GetCoordDiff(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY);

// build: symbol ?DRLGVER_AllocVertex@@YIPAUD2DrlgVertexStrc@@PAXE@Z 0x0067CDD0
D2DrlgVertexStrc* __fastcall DRLGVER_AllocVertex(void* pMemPool, unsigned char nDirection)
{
    D2DrlgVertexStrc* pVertex = (D2DrlgVertexStrc*)sub_0040B430(pMemPool, sizeof(D2DrlgVertexStrc), ".\\DRLG\\DrlgVer.cpp", 19, 0);
    memset(pVertex, 0, sizeof(D2DrlgVertexStrc));
    pVertex->nDirection = nDirection;
    return pVertex;
}

// 0x0067CE00
static void __stdcall DRLGVER_MarkVertex(D2DrlgVertexStrc* pVertex, int bInit)
{
    pVertex->dwFlags |= 1;
    if (bInit)
    {
        pVertex->dwFlags |= 2;
    }
}

// 0x0067CE20
void __stdcall DRLGVER_SplitVerticesAtOrths(void* pMemPool, D2DrlgVertexStrc* pCurrentVertex, D2DrlgCoordStrc* pDrlgCoord, unsigned char nDirection, D2DrlgOrthStrc* pCurrentRoomData)
{
    int nSign = 0;
    D2DrlgVertexStrc* pNextVertex = pCurrentVertex->pNext;
    D2DrlgVertexStrc* pLastVertex = pCurrentVertex->pNext->pNext;
    D2DrlgVertexStrc* pPreviousVertex = pCurrentVertex->pNext->pNext->pNext;

    while (pCurrentRoomData)
    {
        D2DrlgCoordStrc* pCurrentCoords;
        if (pCurrentRoomData->pBox)
            pCurrentCoords = pCurrentRoomData->pBox;
        else
            pCurrentCoords = pDrlgCoord;

        D2DrlgVertexStrc* pVertex;
        D2DrlgVertexStrc* pEndVertex;
        bool bDirection;
        int nFirst;
        int nSecond;
        int nStart;
        int nEnd;

        switch (pCurrentRoomData->nDirection)
        {
        case 0:
            pVertex = pCurrentVertex;
            bDirection = true;
            nSign = -1;
            pEndVertex = pNextVertex;
            nFirst = pCurrentCoords->nPosY + pCurrentCoords->nHeight;
            nSecond = pCurrentCoords->nPosY;
            break;

        case 1:
            pVertex = pNextVertex;
            bDirection = false;
            nSign = 1;
            pEndVertex = pLastVertex;
            nFirst = pCurrentCoords->nPosX;
            nSecond = pCurrentCoords->nPosX + pCurrentCoords->nWidth;
            break;

        case 2:
            pVertex = pLastVertex;
            bDirection = true;
            nSign = 1;
            pEndVertex = pPreviousVertex;
            nFirst = pCurrentCoords->nPosY;
            nSecond = pCurrentCoords->nPosY + pCurrentCoords->nHeight;
            break;

        case 3:
            pVertex = pPreviousVertex;
            bDirection = false;
            nSign = -1;
            pEndVertex = pCurrentVertex;
            nFirst = pCurrentCoords->nPosX + pCurrentCoords->nWidth;
            nSecond = pCurrentCoords->nPosX;
            break;

        default:
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 109);
            exit(-1);
        }

        if (bDirection)
        {
            nStart = pVertex->nPosY;
            nEnd = pEndVertex->nPosY;
        }
        else
        {
            nStart = pVertex->nPosX;
            nEnd = pEndVertex->nPosX;
        }

        if (nFirst * nSign <= nStart * nSign)
        {
            if (nSecond * nSign < nStart * nSign)
            {
                goto next;
            }
        }
        else
        {
            if (nFirst * nSign > nEnd * nSign)
            {
                goto next;
            }

            D2DrlgVertexStrc* pNewVertex = DRLGVER_AllocVertex(pMemPool, nDirection);
            if (bDirection)
            {
                pNewVertex->nPosX = pVertex->nPosX;
                pNewVertex->nPosY = nFirst;
            }
            else
            {
                pNewVertex->nPosY = pVertex->nPosY;
                pNewVertex->nPosX = nFirst;
            }
            pNewVertex->pNext = pVertex->pNext;
            pVertex->pNext = pNewVertex;
            pVertex = pNewVertex;
        }

        DRLGVER_MarkVertex(pVertex, pCurrentRoomData->bPreset);

        if (nSecond * nSign < nEnd * nSign)
        {
            D2DrlgVertexStrc* pNewVertex = DRLGVER_AllocVertex(pMemPool, nDirection);
            if (bDirection)
            {
                pNewVertex->nPosX = pVertex->nPosX;
                pNewVertex->nPosY = nSecond;
            }
            else
            {
                pNewVertex->nPosY = pVertex->nPosY;
                pNewVertex->nPosX = nSecond;
            }
            pNewVertex->pNext = pVertex->pNext;
            pVertex->pNext = pNewVertex;
        }

next:
        pCurrentRoomData = pCurrentRoomData->pNext;
    }
}

// 0x0067D030
static void __fastcall DRLGVER_MakeVerticesRelative(D2DrlgCoordStrc* pCoords, D2DrlgVertexStrc* pFirst)
{
    D2DrlgVertexStrc* pVertex = pFirst;
    do
    {
        pVertex->nPosX -= pCoords->nPosX;
        pVertex->nPosY -= pCoords->nPosY;
        pVertex = pVertex->pNext;
    }
    while (pVertex != pFirst);
}

// 0x0067D050
void __fastcall DRLGVER_CreateVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex, D2DrlgCoordStrc* pCoords, unsigned char nDirection, D2DrlgOrthStrc* pOrth)
{
    --pCoords->nWidth;
    --pCoords->nHeight;
    for (D2DrlgOrthStrc* pShrink = pOrth; pShrink; pShrink = pShrink->pNext)
    {
        --pShrink->pBox->nWidth;
        --pShrink->pBox->nHeight;
    }

    D2DrlgVertexStrc* pVertex0 = DRLGVER_AllocVertex(pMemPool, nDirection);
    *ppVertex = pVertex0;
    pVertex0->nPosX = pCoords->nPosX;
    pVertex0->nPosY = pCoords->nPosY + pCoords->nHeight;

    D2DrlgVertexStrc* pVertex1 = DRLGVER_AllocVertex(pMemPool, nDirection);
    pVertex0->pNext = pVertex1;
    pVertex1->nPosX = pCoords->nPosX;
    pVertex1->nPosY = pCoords->nPosY;

    D2DrlgVertexStrc* pVertex2 = DRLGVER_AllocVertex(pMemPool, nDirection);
    pVertex1->pNext = pVertex2;
    pVertex2->nPosX = pCoords->nPosX + pCoords->nWidth;
    pVertex2->nPosY = pCoords->nPosY;

    D2DrlgVertexStrc* pVertex3 = DRLGVER_AllocVertex(pMemPool, nDirection);
    pVertex2->pNext = pVertex3;
    pVertex3->nPosX = pCoords->nPosX + pCoords->nWidth;
    pVertex3->nPosY = pCoords->nPosY + pCoords->nHeight;
    pVertex3->pNext = *ppVertex;

    DRLGVER_SplitVerticesAtOrths(pMemPool, *ppVertex, pCoords, nDirection, pOrth);
    DRLGVER_MakeVerticesRelative(pCoords, *ppVertex);

    ++pCoords->nWidth;
    ++pCoords->nHeight;
    for (D2DrlgOrthStrc* pGrow = pOrth; pGrow; pGrow = pGrow->pNext)
    {
        ++pGrow->pBox->nWidth;
        ++pGrow->pBox->nHeight;
    }
}

// 0x0067D1E0
void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    if (*ppVertex)
    {
        D2DrlgVertexStrc* pVertex = (*ppVertex)->pNext;
        while (pVertex)
        {
            D2DrlgVertexStrc* pFree = pVertex;
            pVertex = pVertex->pNext;
            sub_0040B480(pMemPool, pFree, ".\\DRLG\\DrlgVer.cpp", 276, 0);

            if (pVertex == *ppVertex)
            {
                sub_0040B480(pMemPool, pVertex, ".\\DRLG\\DrlgVer.cpp", 279, 0);
                break;
            }
        }

        if (!pVertex)
        {
            sub_0040B480(pMemPool, *ppVertex, ".\\DRLG\\DrlgVer.cpp", 287, 0);
        }

        *ppVertex = 0;
    }
}

// 0x0067D250
void __fastcall DRLGVER_ReverseVertexList(D2DrlgVertexStrc** ppVertex)
{
    D2DrlgVertexStrc* pPrevious = 0;
    D2DrlgVertexStrc* pVertex = *ppVertex;
    while (pVertex)
    {
        D2DrlgVertexStrc* pNext = pVertex->pNext;
        pVertex->pNext = pPrevious;
        pPrevious = pVertex;
        pVertex = pNext;
    }

    *ppVertex = pPrevious;
}

// 0x0067D280
void __fastcall DRLGVER_GetCoordDiff(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY)
{
    *pDirectionX = pVertex->pNext->nPosX - pVertex->nPosX;
    *pDirectionY = pVertex->pNext->nPosY - pVertex->nPosY;

    if (*pDirectionX < 0)
    {
        *pDirectionX = -1;
    }
    else if (*pDirectionX > 0)
    {
        *pDirectionX = 1;
    }

    if (*pDirectionY < 0)
    {
        *pDirectionY = -1;
    }
    else if (*pDirectionY > 0)
    {
        *pDirectionY = 1;
    }
}

#include "gen/data/Source/D2Common/DRLG/DrlgVer.inc"
