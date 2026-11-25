#include "D2Common.h"

#include "D2LevelIds.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Structs.h"

#include "D2DrlgTiles.h"

#include "D2Drlg.h"

#include "D2DrlgPresets.h"
#include "D2DrlgOutdoor.h"

#define DRLGTYPE_OUTDOOR 3

#define DRLGTYPE_PRESET 2

#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))

struct D2DrlgStrc;

struct D2DrlgOrthStrc;

struct D2DrlgOutdoorInfoStrc;

struct D2CoordStrc;

struct D2DrlgCoordStrc;

union D2SeedStrc;

struct D2DrlgLinkStrc;

struct D2DrlgLevelLinkDataStrc;

struct D2LevelDefBin;

struct D2UnkOutdoorStrc3;

struct D2PosStrc;


void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY); // 0x0067C570

static void __stdcall DRLGOUTPLACE_PlaceCoordBeside(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4); // 0x00675EB0

static void __stdcall DRLGOUTPLACE_PlaceCoordCentered(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4); // 0x00675F80

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470

extern D2DrlgLinkStrc gAct1MonasteryDrlgLink[]; // 0x006F0840

extern D2DrlgLinkStrc gAct2OutdoorDrlgLink[]; // 0x006F0930

int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance); // 0x0066B860

struct D2UnkOutdoorStrc3
{
    int nLevelId;
    int nIgnoredLevel1;
    int nIgnoredLevel2;
    int nRand;
    int nNextRand;
    int nFlags;
};

extern D2DrlgLinkStrc gAct2CanyonDrlgLink[15]; // 0x006F0A20

extern D2DrlgLinkStrc gAct5UbersDrlgLink[15]; // 0x006F0B10

extern D2DrlgLinkStrc gAct4OutdoorDrlgLink[15]; // 0x006F0C00

extern D2DrlgLinkStrc gAct4ChaosSanctumDrlgLink[15]; // 0x006F0CF0

extern const D2UnkOutdoorStrc3 gaAct1OutdoorRandFlags[15]; // 0x006F1258

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0

int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240

void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset); // 0x0066B790

struct D2PosStrc
{
    int nX;
    int nY;
};


static int DRLGOUTPLACE_IsYGreater(const D2PosStrc* pPos1, const D2PosStrc* pPos2); // 0x00677870

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// build: symbol ?gaBorderIndicesByDelta@* 0x006F1088
// build: symbol ?gaBarricadeCliffBorderIds@* 0x006F06F0
// build: symbol ?gaBorderLevelPrestIds@* 0x006F0630

// 0x00675670
void __fastcall DRLGOUTPLACE_SetBlankBorderGridCells(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const D2CoordStrc aOffsets[4][2] = {
        {{  0,  0 }, {  1,  1 }},
        {{  1,  0 }, { -1,  1 }},
        {{  0,  1 }, {  1, -1 }},
        {{  1,  1 }, { -1, -1 }}
    };

    for (int k = 0; k < 4; ++k)
    {
        int nX = aOffsets[k][0].nX;
        if (nX)
        {
            nX = pOutdoor->nGridWidth - 1;
        }

        int nY = aOffsets[k][0].nY;
        if (nY)
        {
            nY = pOutdoor->nGridHeight - 1;
        }

        int nDirX = aOffsets[k][1].nX;
        int nDirY = aOffsets[k][1].nY;

        int i = nX;
        int j = nY;
        while (!(DRLGGRID_GetGridEntry(&pOutdoor->pGrid[2], nX, j) & 1))
        {
            while (!(DRLGGRID_GetGridEntry(&pOutdoor->pGrid[2], i, j) & 1))
            {
                DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], i, j, 0x100, 0);
                i += nDirX;
            }
            j += nDirY;
            i = nX;
        }
    }
}

#define LARGE_SHIFT 16
#define SMALL_SHIFT 8

// 0x00675DE0
static void __fastcall DRLGOUTPLACE_Place(D2DrlgCoordStrc* src,int mode,int side,D2DrlgCoordStrc* dst) {
 switch(side) {
 case 0:
  dst->nPosX=src->nPosX;
  dst->nPosY=src->nHeight+src->nPosY;
  if(mode==1) dst->nPosX-=LARGE_SHIFT;
  break;
 case 1:
  dst->nPosX=src->nPosX-dst->nWidth;
  dst->nPosY=src->nPosY;
  if(mode==1) dst->nPosY-=LARGE_SHIFT;
  else if(mode==2) dst->nPosY+=SMALL_SHIFT;
  break;
 case 2:
  dst->nPosX=src->nWidth-dst->nWidth+src->nPosX;
  dst->nPosY=src->nPosY-dst->nHeight;
  if(mode==1) dst->nPosX+=LARGE_SHIFT;
  break;
 case 3:
  dst->nPosX=src->nWidth+src->nPosX;
  dst->nPosY=src->nHeight-dst->nHeight+src->nPosY;
  if(mode==1) dst->nPosY+=LARGE_SHIFT;
  else if(mode==2) dst->nPosY-=SMALL_SHIFT;
  else if(mode==3) dst->nPosY+=SMALL_SHIFT;
  break;
 }
}

void __fastcall EmitPlacement(D2DrlgCoordStrc* src,int mode,int side,D2DrlgCoordStrc* dst) {
 DRLGOUTPLACE_Place(src,mode,side,dst);
}
#undef LARGE_SHIFT
#undef SMALL_SHIFT

// 0x00675EB0
static void __stdcall DRLGOUTPLACE_PlaceCoordBeside(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nWidth - pCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += 16;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += 16;
        }
        else if (a4 == 2)
        {
            pCoord->nPosY -= 8;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= 16;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= 16;
        }
        else if (a4 == 2)
        {
            pCoord->nPosY += 8;
        }
        else if (a4 == 3)
        {
            pCoord->nPosY -= 8;
        }
        break;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_00675EB0_Shim(D2DrlgCoordStrc* pCoords, int nCount)
{
    for (int i = 1; i < nCount; ++i)
    {
        DRLGOUTPLACE_PlaceCoordBeside(&pCoords[i - 1], &pCoords[i], i & 3, i & 1);
    }
}

// 0x00675F80
static void __stdcall DRLGOUTPLACE_PlaceCoordCentered(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX -= pCoord->nWidth / 2 + 8;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += pCoord->nWidth / 2 + 8;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= pCoord->nHeight / 2 + 8;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += pCoord->nHeight / 2 + 8;
        }
        break;
    case 4:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= pCoord->nWidth / 2 + 8;
        }
        break;
    case 5:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX += pCoord->nWidth / 2 + 8;
        }
        break;
    case 6:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= pCoord->nHeight / 2 + 8;
        }
        break;
    case 7:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += pCoord->nHeight / 2 + 8;
        }
        break;
    }
}

// calling-convention shim (not game code)
void __fastcall sub_00675F80_Shim(D2DrlgCoordStrc* pCoords, int nCount)
{
    for (int i = 1; i < nCount; ++i)
    {
        DRLGOUTPLACE_PlaceCoordCentered(&pCoords[i - 1], &pCoords[i], i & 7, i & 1);
    }
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static void __fastcall sub_6FD815E0(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
    switch (a3)
    {
    case 0:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 1:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 2:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 3:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY += pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 4:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 5:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += pDrlgCoord2->nWidth / 2 + 8;
        }
        break;
    case 6:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    case 7:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;
        if (a4 == 1)
        {
            pDrlgCoord2->nPosY += pDrlgCoord2->nHeight / 2 + 8;
        }
        break;
    default:
        return;
    }
}

// 0x006760F0
int __fastcall DRLGOUTPLACE_PlaceAtLevelDefOffset(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }

    D2LevelDefBin* pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(pLevelLinkData->nCurrentLevel);
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosX = pLevelDefBinRecord->dwOffsetX;
    pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration].nPosY = pLevelDefBinRecord->dwOffsetY;

    return 1;
}

// 0x00676450
int __fastcall DRLGOUTPLACE_LinkStepDirectionSide(D2DrlgLevelLinkDataStrc* pData)
{
    if (pData->nRand[1][pData->nIteration] == -1)
    {
        pData->nRand[1][pData->nIteration] = SEED_RollRandomNumber(&pData->pSeed) & 3;
        pData->nRand[0][pData->nIteration] = pData->nRand[1][pData->nIteration];
        pData->nRand[3][pData->nIteration] = SEED_RollRandomNumber(&pData->pSeed) & 1;
        pData->nRand[2][pData->nIteration] = pData->nRand[3][pData->nIteration];
    }
    else
    {
        const int nNext = (pData->nRand[0][pData->nIteration] + pData->nRand[2][pData->nIteration]) % 4;
        const int nSide = (pData->nRand[2][pData->nIteration] + 1) % 2;
        if (nNext == pData->nRand[1][pData->nIteration] && nSide == pData->nRand[3][pData->nIteration])
        {
            return 0;
        }

        pData->nRand[0][pData->nIteration] = nNext;
        pData->nRand[2][pData->nIteration] = nSide;
    }

    const int nIndex = pData->nIteration;
    D2DrlgCoordStrc* pLinkCoord = &pData->pLevelCoord[pData->pLink[nIndex].nLevelLink];
    if (pData->nRand[2][nIndex] == 1)
    {
        switch (pData->nRand[0][nIndex])
        {
        case 0:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
            break;
        case 1:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX - pData->pLevelCoord[nIndex].nWidth;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY + 8;
            break;
        case 2:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth - pData->pLevelCoord[nIndex].nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY - pData->pLevelCoord[nIndex].nHeight;
            break;
        case 3:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight - pData->pLevelCoord[nIndex].nHeight + pLinkCoord->nPosY - 8;
            break;
        }
    }
    else
    {
        switch (pData->nRand[0][nIndex])
        {
        case 0:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth - pData->pLevelCoord[nIndex].nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
            break;
        case 1:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX - pData->pLevelCoord[nIndex].nWidth;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight - pData->pLevelCoord[nIndex].nHeight + pLinkCoord->nPosY - 8;
            break;
        case 2:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY - pData->pLevelCoord[nIndex].nHeight;
            break;
        case 3:
            pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
            pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY + 8;
            break;
        }
    }

    return 1;
}

static inline void DRLGOUTPLACE_PlaceCoordSide1(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX -= 16;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= 16;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nWidth - pCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX += 16;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += 16;
        }
        break;
    }
}

static inline void DRLGOUTPLACE_PlaceCoordSide0(D2DrlgCoordStrc* pLinkCoord, D2DrlgCoordStrc* pCoord, int nDirection, int a4)
{
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pLinkCoord->nWidth - pCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosX += 16;
        }
        break;
    case 1:
        pCoord->nPosX = pLinkCoord->nPosX - pCoord->nWidth;
        pCoord->nPosY = pLinkCoord->nHeight - pCoord->nHeight + pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY += 16;
        }
        break;
    case 2:
        pCoord->nPosX = pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY - pCoord->nHeight;
        if (a4 == 1)
        {
            pCoord->nPosX -= 16;
        }
        break;
    case 3:
        pCoord->nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pCoord->nPosY = pLinkCoord->nPosY;
        if (a4 == 1)
        {
            pCoord->nPosY -= 16;
        }
        break;
    }
}

// 0x00676650
int __fastcall DRLGOUTPLACE_LinkStepDirectionSideSized(D2DrlgLevelLinkDataStrc* pData)
{
    if (pData->nRand[1][pData->nIteration] == -1)
    {
        pData->nRand[1][pData->nIteration] = SEED_RollRandomNumber(&pData->pSeed) & 3;
        pData->nRand[0][pData->nIteration] = pData->nRand[1][pData->nIteration];
        pData->nRand[3][pData->nIteration] = SEED_RollRandomNumber(&pData->pSeed) & 1;
        pData->nRand[2][pData->nIteration] = pData->nRand[3][pData->nIteration];
    }
    else
    {
        const int nNext = (pData->nRand[0][pData->nIteration] + pData->nRand[2][pData->nIteration]) % 4;
        const int nSide = (pData->nRand[2][pData->nIteration] + 1) % 2;
        if (nNext == pData->nRand[1][pData->nIteration] && nSide == pData->nRand[3][pData->nIteration])
        {
            return 0;
        }

        pData->nRand[0][pData->nIteration] = nNext;
        pData->nRand[2][pData->nIteration] = nSide;
    }

    pData->pLevelCoord[pData->nIteration].nWidth = (pData->nRand[0][pData->nIteration] % 2) ? 96 : 56;
    pData->pLevelCoord[pData->nIteration].nHeight = (pData->nRand[0][pData->nIteration] % 2) ? 56 : 96;

    const int nIndex = pData->nIteration;
    D2DrlgCoordStrc* pLinkCoord = &pData->pLevelCoord[pData->pLink[nIndex].nLevelLink];
    if (pData->nRand[2][nIndex] == 1)
    {
        DRLGOUTPLACE_PlaceCoordSide1(pLinkCoord, &pData->pLevelCoord[nIndex], pData->nRand[0][nIndex], 1);
    }
    else
    {
        DRLGOUTPLACE_PlaceCoordSide0(pLinkCoord, &pData->pLevelCoord[nIndex], pData->nRand[0][nIndex], 1);
    }

    return 1;
}

// 0x006768C0
int __fastcall DRLGOUTPLACE_PlaceLevel(D2DrlgLevelLinkDataStrc* pData)
{
    pData->nRand[1][pData->nIteration] = 0;
    pData->nRand[0][pData->nIteration] = pData->nRand[1][pData->nIteration];
    const int nIndex = pData->nIteration;
    const int nDirection = pData->nRand[0][nIndex];
    D2DrlgCoordStrc* pLinkCoord = &pData->pLevelCoord[pData->pLink[nIndex].nLevelLink];
    switch (nDirection)
    {
    case 0:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight + pLinkCoord->nPosY;
        break;
    case 1:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nPosX - pData->pLevelCoord[nIndex].nWidth;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY;
        break;
    case 2:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth - pData->pLevelCoord[nIndex].nWidth + pLinkCoord->nPosX;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nPosY - pData->pLevelCoord[nIndex].nHeight;
        break;
    case 3:
        pData->pLevelCoord[nIndex].nPosX = pLinkCoord->nWidth + pLinkCoord->nPosX;
        pData->pLevelCoord[nIndex].nPosY = pLinkCoord->nHeight - pData->pLevelCoord[nIndex].nHeight + pLinkCoord->nPosY;
        break;
    }
    return 1;
}

static inline void sub_6FD81430(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
	switch (a3)
	{
	case 0:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosX -= 16;
		}
		break;

	case 1:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosY -= 16;
		}
		else if (a4 == 2)
		{
			pDrlgCoord2->nPosY += 8;
		}
		break;

	case 2:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth - pDrlgCoord2->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosX += 16;
		}
		break;

	case 3:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight - pDrlgCoord2->nHeight;

		switch (a4)
		{
		case 1:
			pDrlgCoord2->nPosY += 16;
			break;

		case 2:
			pDrlgCoord2->nPosY -= 8;
			break;

		case 3:
			pDrlgCoord2->nPosY += 8;
			break;
		default:
			break;
		}
		break;

	default:
		return;
	}
}

static inline void sub_6FD81850(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
	switch (a3)
	{
	case 0:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth - pDrlgCoord2->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosX += 16;
		}
		break;

	case 1:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight - pDrlgCoord2->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosY += 16;
		}
		else if (a4 == 2)
		{
			pDrlgCoord2->nPosY -= 8;
		}
		break;

	case 2:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;

		if (a4 == 1)
		{
			pDrlgCoord2->nPosX -= 16;
		}
		break;

	case 3:
		pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
		pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;

		switch (a4)
		{
		case 1:
			pDrlgCoord2->nPosY -= 16;
			break;

		case 2:
			pDrlgCoord2->nPosY += 8;
			break;

		case 3:
			pDrlgCoord2->nPosY -= 8;
			break;
		default:
			break;
		}
		break;

	default:
		return;
	}
}

// 0x006769A0
int __fastcall sub_6FD81B30(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = 0;

    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = (SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1) + 1;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        nRand = pLevelLinkData->nRand[0][pLevelLinkData->nIteration] != 1 ? 1 : 2;

        if (nRand == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    }

    D2DrlgCoordStrc* pDrlgCoord1 = &pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink];
    D2DrlgCoordStrc* pDrlgCoord2 = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    const int nDirection = pLevelLinkData->nRand[0][pLevelLinkData->nIteration];
    if (nDirection == 1)
    {
        sub_6FD81430(pDrlgCoord1, pDrlgCoord2, 1, 0);
    }
    else
    {
        sub_6FD81850(pDrlgCoord1, pDrlgCoord2, nDirection, 0);
    }

    return 1;
}

// 0x00676AE0
int __fastcall DRLGOUTPLACE_TryNextCenteredSide(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = 0;

    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 7;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        nRand = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 8;

        if (nRand == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    }

    sub_6FD815E0(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 0);

    return 1;
}

static inline void DRLGOUTPLACE_PlaceCoord(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int a3, int a4)
{
    switch (a3)
    {
    case 0:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosX -= 16;
        }
        break;

    case 1:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosY -= 16;
        }
        else if (a4 == 2)
        {
            pDrlgCoord2->nPosY += 8;
        }
        break;

    case 2:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth - pDrlgCoord2->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight;

        if (a4 == 1)
        {
            pDrlgCoord2->nPosX += 16;
        }
        break;

    case 3:
        pDrlgCoord2->nPosX = pDrlgCoord1->nPosX + pDrlgCoord1->nWidth;
        pDrlgCoord2->nPosY = pDrlgCoord1->nPosY + pDrlgCoord1->nHeight - pDrlgCoord2->nHeight;

        switch (a4)
        {
        case 1:
            pDrlgCoord2->nPosY += 16;
            break;

        case 2:
            pDrlgCoord2->nPosY -= 8;
            break;

        case 3:
            pDrlgCoord2->nPosY += 8;
            break;

        default:
            break;
        }
        break;

    default:
        return;
    }
}

// 0x00676150
int __fastcall DRLGOUTPLACE_TryNextSideOffset(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 3;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        const int nNext = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 4;
        if (nNext == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nNext;
    }

    DRLGOUTPLACE_PlaceCoord(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 1);

    return 1;
}

// 0x00676280
int __fastcall DRLGOUTPLACE_TryNextCenteredSideOffset(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    int nRand = 0;

    if (pLevelLinkData->nRand[1][pLevelLinkData->nIteration] == -1)
    {
        pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 7;
        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];
    }
    else
    {
        nRand = (pLevelLinkData->nRand[0][pLevelLinkData->nIteration] + 1) % 8;

        if (nRand == pLevelLinkData->nRand[1][pLevelLinkData->nIteration])
        {
            return 0;
        }

        pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = nRand;
    }

    sub_6FD815E0(&pLevelLinkData->pLevelCoord[pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink], &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration], pLevelLinkData->nRand[0][pLevelLinkData->nIteration], 1);

    return 1;
}

static int gnDrlgLinkFlags_0096D66C; // 0x0096D66C

// 0x00676C00
int __fastcall DRLGOUTPLACE_PlaceLevelNextTo(D2DrlgLevelLinkDataStrc* pLevelLinkData)
{
    pLevelLinkData->nRand[1][pLevelLinkData->nIteration] = 3;
    pLevelLinkData->nRand[0][pLevelLinkData->nIteration] = pLevelLinkData->nRand[1][pLevelLinkData->nIteration];

    const int nLinkedLevel = pLevelLinkData->pLink[pLevelLinkData->nIteration].nLevelLink;
    D2DrlgCoordStrc* pDst = &pLevelLinkData->pLevelCoord[pLevelLinkData->nIteration];
    if (SEED_RollRandomNumber(&pLevelLinkData->pSeed) & 1)
    {
        D2DrlgCoordStrc* pSrc = &pLevelLinkData->pLevelCoord[nLinkedLevel];
        switch (pLevelLinkData->nRand[0][pLevelLinkData->nIteration])
        {
        case 0:
            pDst->nPosX = pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight + pSrc->nPosY;
            break;
        case 1:
            pDst->nPosX = pSrc->nPosX - pDst->nWidth;
            pDst->nPosY = pSrc->nPosY;
            break;
        case 2:
            pDst->nPosX = pSrc->nWidth - pDst->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - pDst->nHeight;
            break;
        case 3:
            pDst->nPosX = pSrc->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight - pDst->nHeight + pSrc->nPosY + 8;
            break;
        }
        gnDrlgLinkFlags_0096D66C = 0x800000;
    }
    else
    {
        D2DrlgCoordStrc* pSrc = &pLevelLinkData->pLevelCoord[nLinkedLevel];
        switch (pLevelLinkData->nRand[0][pLevelLinkData->nIteration])
        {
        case 0:
            pDst->nPosX = pSrc->nWidth - pDst->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nHeight + pSrc->nPosY;
            break;
        case 1:
            pDst->nPosX = pSrc->nPosX - pDst->nWidth;
            pDst->nPosY = pSrc->nHeight - pDst->nHeight + pSrc->nPosY;
            break;
        case 2:
            pDst->nPosX = pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - pDst->nHeight;
            break;
        case 3:
            pDst->nPosX = pSrc->nWidth + pSrc->nPosX;
            pDst->nPosY = pSrc->nPosY - 8;
            break;
        }
        gnDrlgLinkFlags_0096D66C = 0x400000;
    }

    return 1;
}

extern D2DrlgLinkStrc gAct1WildernessDrlgLink[15];                                                          // 0x006F0750

extern const int gnAct1WildernessLinkTable[];                                                               // 0x006F1158

// 0x00676DD0
int __fastcall DRLGOUTPLACE_LinkAct1Wilderness(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nCounter = 0;
    int nLevelLink = gAct1WildernessDrlgLink[nIteration].nLevelLink;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    switch (gAct1WildernessDrlgLink[nIteration].nLevel)
    {
    case LEVEL_ROGUEENCAMPMENT:
        return gnAct1WildernessLinkTable[pLevelLinkData->nRand[0][nIteration] + 4 * (pLevelLinkData->nRand[2][nIteration] + 2 * (pLevelLinkData->nRand[0][nLevelLink] + 4 * pLevelLinkData->nRand[2][nLevelLink]))];

    case LEVEL_BURIALGROUNDS:
        for (int i = 0; i < 15; ++i)
        {
            if (i != nIteration && gAct1WildernessDrlgLink[i].nLevelLink == nLevelLink && pLevelLinkData->nRand[0][nIteration] == pLevelLinkData->nRand[0][i])
            {
                return 0;
            }
        }
        break;
    }

    return 1;
}

// 0x00676EB0
int __fastcall DRLGOUTPLACE_LinkAct1Monastery(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    const int nLevelLink = gAct1MonasteryDrlgLink[nIteration].nLevelLink;
    int nCounter = 0;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    int bResult = 1;
    if (nIteration)
    {
        pLevelLinkData->pLevelCoord[0].nHeight += 200;
        pLevelLinkData->pLevelCoord[0].nPosY -= 200;

        bResult = DRLG_CheckNotOverlappingUsingManhattanDistance(pLevelLinkData->pLevelCoord, &pLevelLinkData->pLevelCoord[nCounter], 0);

        pLevelLinkData->pLevelCoord[0].nHeight -= 200;
        pLevelLinkData->pLevelCoord[0].nPosY += 200;
    }

    return bResult;
}

// 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nCounter = 0;
    const int nLevelLink = gAct2OutdoorDrlgLink[nIteration].nLevelLink;

    while (nCounter < nIteration)
    {
        if (nCounter != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[nCounter], 0))
        {
            return 0;
        }

        ++nCounter;
    }

    return 1;
}

// 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct2CanyonDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct5UbersDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct4OutdoorDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677110
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration)
{
    int nLevelLink = gAct4ChaosSanctumDrlgLink[nIteration].nLevelLink;

    for (int i = 0; i < nIteration; ++i)
    {
        if (i != nLevelLink && !DRLG_CheckNotOverlappingUsingManhattanDistance(&pLevelLinkData->pLevelCoord[nIteration], &pLevelLinkData->pLevelCoord[i], 0))
        {
            return 0;
        }
    }

    return 1;
}

// 0x00677180
void __fastcall DRLGOUTPLACE_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand)
{
    if (pLevel->nDrlgType == DRLGTYPE_OUTDOOR)
    {
        D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
        for (int i = 0; i < 15; ++i)
        {
            if (pLevel->eLevelId == gaAct1OutdoorRandFlags[i].nLevelId || !gaAct1OutdoorRandFlags[i].nLevelId)
            {
                if (pLevel->eLevelId != gaAct1OutdoorRandFlags[i].nIgnoredLevel1 && pLevel->eLevelId != gaAct1OutdoorRandFlags[i].nIgnoredLevel2 && pRand[nIteration] == gaAct1OutdoorRandFlags[i].nRand)
                {
                    if (pRand[nIteration + 1] == gaAct1OutdoorRandFlags[i].nNextRand)
                    {
                        pOutdoors->dwFlags |= gaAct1OutdoorRandFlags[i].nFlags;
                    }
                }
            }
        }
    }
}

#include "gen/data/Source/D2Common/DRLG/OutPlace.inc"

typedef int (__fastcall* DRLGLINKFN)(D2DrlgLevelLinkDataStrc* pLevelLinkData);
extern "C" const char gszOutPlaceFile[];                                                                    // 0x006F1500

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480
extern "C" void* __cdecl sub_00681EF0_Memset(void* pDst, int nValue, unsigned int nSize);                   // 0x00681EF0




extern const int gnSpiderForestPresets[];                                                          // 0x006F13BC
extern const int gnJunglePresets[][4];                                                             // 0x006F13F0

struct D2DrlgLevelLinkDataStrc;



struct D2DrlgWarpStrc;

typedef int (__fastcall* LINKFN)(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);
typedef void (__fastcall* FLAGFN)(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand);

#define DRLGTYPE_PRESET 2
#define DRLGTYPE_OUTDOOR 3
D2DrlgWarpStrc* __fastcall DRLG_GetDrlgWarpFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                    // 0x00642860
D2DrlgWarpStrc* __fastcall DRLG_SetWarpId(D2DrlgWarpStrc* pDrlgWarp, int nVis, int nWarp, int nShift);      // 0x00642920
int __fastcall DRLG_CheckOverlappingWithOrthogonalMargin(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMargin); // 0x0066B880
int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                        // 0x0066AEC0
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                           // 0x0066C040
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset);

int __fastcall DRLGOUTPLACE_LinkAct1Wilderness(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);    // 0x00676DD0
int __fastcall DRLGOUTPLACE_LinkAct1Monastery(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);                       // 0x00676EB0
int __fastcall DRLGOUTPLACE_LinkAct2Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);      // 0x00676F50
int __fastcall DRLGOUTPLACE_LinkAct2Canyon(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);        // 0x00676FC0
int __fastcall DRLGOUTPLACE_LinkAct5Ubers(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);         // 0x00677030
int __fastcall DRLGOUTPLACE_LinkAct4Outdoors(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);      // 0x006770A0
int __fastcall DRLGOUTPLACE_LinkAct4ChaosSanctum(D2DrlgLevelLinkDataStrc* pLevelLinkData, int nIteration);  // 0x00677110
void __fastcall DRLGOUTPLACE_SetAct1OutdoorFlags(D2DrlgLevelStrc* pLevel, int nIteration, int* pRand);      // 0x00677180

extern D2DrlgLinkStrc gAct1WildernessDrlgLink[15];                                                          // 0x006F0750
extern D2DrlgLinkStrc gAct1MonasteryDrlgLink[15];                                                           // 0x006F0840
extern D2DrlgLinkStrc gAct2OutdoorDrlgLink[15];                                                             // 0x006F0930
extern D2DrlgLinkStrc gAct2CanyonDrlgLink[15];                                                              // 0x006F0A20
extern D2DrlgLinkStrc gAct5UbersDrlgLink[15];                                                               // 0x006F0B10
extern D2DrlgLinkStrc gAct4OutdoorDrlgLink[15];                                                             // 0x006F0C00
extern D2DrlgLinkStrc gAct4ChaosSanctumDrlgLink[15];                                                        // 0x006F0CF0
extern D2DrlgLinkStrc gAct5OutdoorDrlgLink[15];                                                             // 0x006F0DE0
extern D2DrlgLinkStrc gAct5TundraDrlgLink[15];                                                              // 0x006F0ED0

static inline unsigned int SEED_RollRandomNumber_Links(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

void __stdcall DRLGOUTPLACE_InitLevelLinks(D2DrlgLinkStrc* pDrlgLink, LINKFN pfLink, FLAGFN pfFlag, D2DrlgStrc* pDrlg); // 0x006772C0

static void __stdcall DRLGOUTPLACE_SetOverlapWarps(int nStartId, int nEndId, D2DrlgStrc* pDrlg); // 0x006775C0
// 0x006772C0
static void __stdcall DRLGOUTPLACE_InitLevelLinks(D2DrlgLinkStrc* pDrlgLink, LINKFN pfLink, FLAGFN pfFlag, D2DrlgStrc* pDrlg)
{
    D2DrlgLevelLinkDataStrc pLevelLinkData = {};
    D2LevelDefBin* pLevelDefBinRecord = 0;
    D2DrlgPresetInfoStrc* pPresetInfo = 0;
    D2DrlgLevelStrc* pLevel = 0;
    D2DrlgLinkStrc* pLink;
    int nLevelId = 0;
    int nCounter = 0;
    int nVisEx = 0;
    int nVis = 0;

    for (int i = 0; i < 15; ++i)
    {
        pLevelLinkData.nRand[2][i] = -1;
        pLevelLinkData.nRand[3][i] = -1;
        pLevelLinkData.nRand[0][i] = -1;
        pLevelLinkData.nRand[1][i] = -1;
    }

    pLevelLinkData.pLink = pDrlgLink;
    pLevelLinkData.pSeed = pDrlg->pSeed;

    for (int i = 0; pDrlgLink[i].nLevel; ++i)
    {
        pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(pDrlgLink[i].nLevel);

        pLevelLinkData.pLevelCoord[i].nWidth = pLevelDefBinRecord->dwSizeX[pDrlg->nDifficulty];
        pLevelLinkData.pLevelCoord[i].nHeight = pLevelDefBinRecord->dwSizeY[pDrlg->nDifficulty];
    }

    nCounter = 0;
    pLink = pDrlgLink;
    while (pLink->nLevel)
    {
        pLevelLinkData.nIteration = nCounter;
        pLevelLinkData.nCurrentLevel = pLink->nLevel;

        if (!((DRLGLINKFN)pLink->pfLinker)(&pLevelLinkData))
        {
            pLevelLinkData.nRand[2][nCounter] = -1;
            pLevelLinkData.nRand[3][nCounter] = -1;
            pLevelLinkData.nRand[0][nCounter] = -1;
            pLevelLinkData.nRand[1][nCounter] = -1;

            --nCounter;
        }
        else if (!pfLink || pfLink(&pLevelLinkData, nCounter))
        {
            ++nCounter;
        }

        pLink = &pDrlgLink[nCounter];
    }

    nCounter = 0;
    pLink = pDrlgLink;
    while (pLink->nLevel)
    {
        nLevelId = pLink->nLevel;

        if (pLink->nLevelLink == -1)
        {
            nVis = 0;
        }
        else
        {
            nVis = pDrlgLink[pLink->nLevelLink].nLevel;
        }

        if (pLink->nLevelLinkEx == -1)
        {
            nVisEx = 0;
        }
        else
        {
            nVisEx = pDrlgLink[pLink->nLevelLinkEx].nLevel;
        }

        pLevel = DRLG_GetLevel(pDrlg, nLevelId);

        pLevel->pLevelCoords = pLevelLinkData.pLevelCoord[nCounter];

        if (pLevel->nDrlgType == DRLGTYPE_PRESET)
        {
            pPresetInfo = pLevel->pPreset;
            switch (pLevel->eLevelId)
            {
            case 1:
                pPresetInfo->nDirection = pLevelLinkData.nRand[0][nCounter];
                break;
            case 0x28:
                pPresetInfo->nDirection = pLevelLinkData.nRand[0][nCounter + 1];
                break;
            }
        }

        if (pLevel->eLevelId == LEVEL_BLACKMARSH)
        {
            D2DrlgLevelStrc* pOuterLevel = DRLG_GetLevel(pDrlg, LEVEL_OUTERCLOISTER);
            pPresetInfo = pOuterLevel->pPreset;
            switch (pLevelLinkData.nRand[0][nCounter])
            {
            case 1:
                pPresetInfo->nDirection = ((unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1) ? 1 : 2;
                break;
            case 3:
                pPresetInfo->nDirection = ~(unsigned char)SEED_RollRandomNumber(&pDrlg->pSeed) & 1;
                break;
            }
        }

        if (pfFlag)
        {
            pfFlag(pLevel, nCounter, pLevelLinkData.nRand[0]);
        }

        if (pDrlg->nAct != 4)
        {
            if (nVis)
            {
                D2DrlgWarpStrc* pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                D2DrlgWarpStrc* pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVis);
                DRLG_SetWarpId(pDrlgWarp1, nVis, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }

            if (nVisEx)
            {
                D2DrlgWarpStrc* pDrlgWarp1 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nLevelId);
                D2DrlgWarpStrc* pDrlgWarp2 = DRLG_GetDrlgWarpFromLevelId(pDrlg, nVisEx);
                DRLG_SetWarpId(pDrlgWarp1, nVisEx, -1, -1);
                DRLG_SetWarpId(pDrlgWarp2, nLevelId, -1, -1);
            }
        }

        ++nCounter;
        pLink = &pDrlgLink[nCounter];
    }
}

// 0x006775C0
static void __stdcall DRLGOUTPLACE_SetOverlapWarps(int nStartId, int nEndId, D2DrlgStrc* pDrlg)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);
        D2DrlgWarpStrc* pDrlgWarp = DRLG_GetDrlgWarpFromLevelId(pDrlg, i);

        for (int j = nStartId; j <= nEndId; ++j)
        {
            if (i != j)
            {
                D2DrlgLevelStrc* pOtherLevel = DRLG_GetLevel(pDrlg, j);
                if (DRLG_CheckOverlappingWithOrthogonalMargin(&pLevel->pLevelCoords, &pOtherLevel->pLevelCoords, -1))
                {
                    DRLG_SetWarpId(pDrlgWarp, j, -1, -1);
                }
            }
        }
    }
}

void DRLGOUTPLACE_AddOrthToLevel(D2DrlgLevelStrc* pLevel, int nLevelId); // 0x00677640


struct D2ActiveRoomStrc;

// 0x00677640
static inline void DRLGOUTPLACE_AddOrthToLevel(D2DrlgLevelStrc* pLevel, int nLevelId)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgLevelStrc* pWarpLevel = DRLG_GetLevel(pLevel->pDrlg, nLevelId);
    const int nDirection = DRLG_GetDirectionFromCoordinates(&pLevel->pLevelCoords, &pWarpLevel->pLevelCoords);
    DRLGROOM_AddOrth(&pOutdoors->pRoomData, pWarpLevel, nDirection, pWarpLevel->nDrlgType == DRLGTYPE_PRESET);
}

// 0x00677680
static void __stdcall DRLGOUTPLACE_AddLevelOrths(D2DrlgStrc* pDrlg, int nEndId, int nStartId)
{
    for (int i = nStartId; i <= nEndId; ++i)
    {
        D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, i);

        if (pLevel->nDrlgType == DRLGTYPE_OUTDOOR)
        {
            int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, i);
            int* pWarpIdArray = DRLGWARP_GetWarpIdArrayFromLevelId(pDrlg, i);

            for (int j = 0; j < 8; ++j)
            {
                if (pVisArray[j] && pWarpIdArray[j] == -1)
                {
                    DRLGOUTPLACE_AddOrthToLevel(pLevel, pVisArray[j]);
                }
            }
        }
    }
}

// 0x00677750
static void DRLGOUTPLACE_CreateAct1LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct1WildernessDrlgLink, DRLGOUTPLACE_LinkAct1Wilderness, DRLGOUTPLACE_SetAct1OutdoorFlags, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct1MonasteryDrlgLink, DRLGOUTPLACE_LinkAct1Monastery, DRLGOUTPLACE_SetAct1OutdoorFlags, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x11, 1);
}

// 0x00677790
static void DRLGOUTPLACE_CreateAct2LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct2OutdoorDrlgLink, DRLGOUTPLACE_LinkAct2Outdoors, 0, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct2CanyonDrlgLink, DRLGOUTPLACE_LinkAct2Canyon, 0, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x2E, 0x28);
}

// 0x006777D0
static void __stdcall DRLGOUTPLACE_OffsetByDirection(const D2PosStrc* pBase, int nDir, int nA, int nB, D2OffsetPosStrc* pOut)
{
    int nDx = 0;
    int nDy = 0;
    switch (nDir)
    {
    case 0:
        nDx = 0;
        nDy = -nB;
        break;

    case 1:
        nDx = -nA;
        nDy = nB / -3;
        break;

    case 2:
        nDx = nA;
        nDy = nB / -3;
        break;

    case 3:
        nDx = -nA;
        nDy = -nB * 2 / 3;
        break;

    case 4:
        nDx = nA;
        nDy = -nB * 2 / 3;
        break;
    }

    pOut->nX = pBase->nX + nDx;
    pOut->nY = pBase->nY + nDy;
    pOut->nA = nA;
    pOut->nB = nB;
    pOut->nDir = nDir;
}

// 0x00677870
static int DRLGOUTPLACE_IsYGreater(const D2PosStrc* pPos1, const D2PosStrc* pPos2)
{
    return pPos1->nY > pPos2->nY;
}

int __fastcall sub_00677870_Emit(const D2PosStrc* pPos1, const D2PosStrc* pPos2)
{
    return DRLGOUTPLACE_IsYGreater(pPos1, pPos2);
}

static inline unsigned int SEED_RollRandomNumber_Jungle(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber_Jungle(pSeed) % (unsigned int)nMax;
    }

    return SEED_RollRandomNumber_Jungle(pSeed) & (nMax - 1);
}

#define SEED_ROLL_LIMITED(pSeed, nMax, nResult) \
    if ((nMax) <= 0) \
    { \
        nResult = 0; \
    } \
    else if (((nMax) - 1) & (nMax)) \
    { \
        nResult = SEED_RollRandomNumber_Jungle(pSeed) % (unsigned int)(nMax); \
    } \
    else \
    { \
        nResult = SEED_RollRandomNumber_Jungle(pSeed) & ((nMax) - 1); \
    }

static inline int JUNGLE_ABS(int n)
{
    return n < 0 ? -n : n;
}

static D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel);

static D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel); // 0x00677880

static D2DrlgLevelStrc* DRLG_GenerateJungles(D2DrlgLevelStrc* pLevel)
{
    D2LevelDefBin* pLevelDef = DATATBLS_GetLevelDefRecord(LEVEL_SPIDERFOREST);
    int nIdx = 1;
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int nSizeX = pLevelDef->dwSizeX[pDrlg->nDifficulty];
    int nSizeY = pLevelDef->dwSizeY[pDrlg->nDifficulty];
    int nBlocksX = nSizeX / 32;
    int nBlocksY = nSizeY / 32;
    int nMinX = pLevel->nPosX;
    int nMaxY = pLevel->nPosY;
    int nMaxX = nMinX + nSizeX;
    int nMinY = nMaxY - nSizeY;

    D2JungleStrc tJungles[3];
    sub_00681EF0_Memset(tJungles, 0, sizeof(tJungles));

    DRLGOUTPLACE_OffsetByDirection((const D2PosStrc*)&pLevel->nPosX, 0, nSizeX, nSizeY, &tJungles[0].tCoord);

    int nJ;
    while (nIdx < 3)
    {
        unsigned int nBaseOn;
        SEED_ROLL_LIMITED(&pDrlg->pSeed, nIdx, nBaseOn);
        DRLGOUTPLACE_OffsetByDirection((const D2PosStrc*)&tJungles[nBaseOn].tCoord, SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 5), nSizeX, nSizeY, &tJungles[nIdx].tCoord);

        for (nJ = 0; nJ < nIdx; nJ++)
        {
            if (!DRLG_CheckNotOverlappingUsingManhattanDistance((D2DrlgCoordStrc*)&tJungles[nJ].tCoord, (D2DrlgCoordStrc*)&tJungles[nIdx].tCoord, 0))
            {
                break;
            }
        }

        if (nJ < nIdx)
        {
            continue;
        }

        tJungles[nBaseOn].pBranches[tJungles[nBaseOn].nBranch] = &tJungles[nIdx];
        tJungles[nIdx].pBasedOn = &tJungles[nBaseOn];
        ++tJungles[nBaseOn].nBranch;
        D2_ASSERT(tJungles[nBaseOn].nBranch <= 3, 0x63E);

        if (nMinX > tJungles[nIdx].tCoord.nX)
        {
            nMinX = tJungles[nIdx].tCoord.nX;
        }
        if (nMinY > tJungles[nIdx].tCoord.nY)
        {
            nMinY = tJungles[nIdx].tCoord.nY;
        }
        if (nMaxX < tJungles[nIdx].tCoord.nX + tJungles[nIdx].tCoord.nA)
        {
            nMaxX = tJungles[nIdx].tCoord.nX + tJungles[nIdx].tCoord.nA;
        }

        ++nIdx;
    }

    D2_ASSERT((nMaxX - nMinX) % 32 == 0, 0x64D);
    D2_ASSERT((nMaxY - nMinY) % 32 == 0, 0x64E);

    int x;
    int y;
    int nColumnSize;
    int nW = (nMaxX - nMinX) / 32 + 2;
    int nH = (nMaxY - nMinY) / 32 + 2;
    int nSize = nH * nW * sizeof(int);

    int* pPreset0 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x658, 0);
    int* pPreset1 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x659, 0);
    int* pPreset2 = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x65A, 0);
    int* pLevelPresetId = (int*)FOG_AllocPool(pMemPool, nSize, gszOutPlaceFile, 0x65B, 0);

RESTART:
    sub_00681EF0_Memset(pPreset0, 0, nSize);
    sub_00681EF0_Memset(pPreset1, 0, nSize);
    sub_00681EF0_Memset(pPreset2, 0, nSize);
    sub_00681EF0_Memset(pLevelPresetId, 0, nSize);

    for (nJ = 0; nJ < 3; nJ++)
    {
        int nBY;
        int nBX = (tJungles[nJ].tCoord.nX - nMinX) / 32 + 1;
        nBY = (tJungles[nJ].tCoord.nY - nMinY) / 32 + 1;
        tJungles[nJ].nPresetsBlocksX = nBX;
        tJungles[nJ].nPresetsBlocksY = nBY;
        tJungles[nJ].pJungleDefs = (int*)FOG_AllocPool(pMemPool, nBlocksY * nBlocksX * sizeof(int), gszOutPlaceFile, 0x66F, 0);

        int bOffset;
        if (nJ == 0)
        {
            bOffset = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 2);
        }
        else
        {
            bOffset = (tJungles[nJ].tCoord.nDir % 2) == 1;
        }

        int nAttach;
        do
        {
            for (int y = 0; y < nBlocksY; y++)
            {
                for (int x = 0; x < nBlocksX; x++)
                {
                    pPreset0[(nBY + y) * nW + nBX + x] = nJ + 1;
                    pPreset1[(nBY + y) * nW + nBX + x] = 0;
                    pPreset2[(nBY + y) * nW + nBX + x] = 0;
                    pLevelPresetId[(nBY + y) * nW + nBX + x] = 0;
                }
            }

            x = bOffset + nBX;
            y = nBY + nBlocksY - 1;
            if (nJ != 0)
            {
                pPreset2[nW * y + x] = 1;
                pPreset2[nW * y + x + (bOffset ? -1 : 1)] = 2;
            }

            for (int i = 0; i < tJungles[nJ].nBranch; i++)
            {
                switch (tJungles[nJ].pBranches[i]->tCoord.nDir)
                {
                case 0:
                    pPreset2[nBY * nW + nBX] = 1;
                    break;
                case 1:
                    pPreset2[(nBY + 3) * nW + nBX] = 1;
                    break;
                case 2:
                    pPreset2[(nBY + 3) * nW + nBX + 1] = 1;
                    break;
                case 3:
                    pPreset2[(nBY + 1) * nW + nBX] = 1;
                    break;
                case 4:
                    pPreset2[(nBY + 1) * nW + nBX + 1] = 1;
                    break;
                }
            }

            nAttach = nJ != 0;
            int nStep = 0;
            nColumnSize = 0;
            while (y >= nBY)
            {
                const int nRow = nW * y;
                pPreset1[x + nRow] = (nJ + 1) * 100 + nStep;
                ++nStep;

                if (nColumnSize == 0 || y == nBY || SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 3))
                {
                    ++nColumnSize;
                    if (nColumnSize >= 2 && y > 1)
                    {
                        if (pPreset2[nRow + x + (bOffset ? -1 : 1)] == 0)
                        {
                            ++nAttach;
                            pPreset2[nRow + x + (bOffset ? -1 : 1)] = 2;
                        }
                    }
                    --y;
                }
                else
                {
                    nColumnSize = 0;
                    if (bOffset)
                    {
                        --x;
                        bOffset = 0;
                    }
                    else
                    {
                        ++x;
                        bOffset = 1;
                    }
                }
            }
        }
        while (nAttach < 2);

        int nCount = nAttach;
        while (nCount > 3)
        {
            unsigned int nRemove;
            SEED_ROLL_LIMITED(&pDrlg->pSeed, nCount, nRemove);
            int bFinished = 0;
            nColumnSize = 0;
            for (int y = 0; y < nBlocksY && !bFinished; y++)
            {
                for (int x = 0; x < nBlocksX && !bFinished; x++)
                {
                    if (pPreset2[(nBY + y) * nW + nBX + x] == 2)
                    {
                        if (nRemove == nColumnSize)
                        {
                            pPreset2[(nBY + y) * nW + nBX + x] = 0;
                            bFinished = 1;
                            --nCount;
                        }
                        ++nColumnSize;
                    }
                }
            }
        }
    }

    for (y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {

            const int nP0 = pPreset0[y * nW + x];
            int nLast = 0x7FFFFFFF;
            int nFlags = 0;
            if (pPreset2[y * nW + x] == 1)
            {
                if (pPreset1[(y - 1) * nW + x] && pPreset1[(y - 1) * nW + x] < nLast && pPreset0[(y - 1) * nW + x] == nP0)
                {
                    nFlags = 8;
                    nLast = pPreset1[(y - 1) * nW + x];
                }
                if (pPreset1[(y + 1) * nW + x] && pPreset1[(y + 1) * nW + x] < nLast && pPreset0[(y + 1) * nW + x] == nP0)
                {
                    nFlags = 4;
                    nLast = pPreset1[(y + 1) * nW + x];
                }
                if (pPreset1[y * nW + x + 1] && pPreset1[y * nW + x + 1] < nLast && pPreset0[y * nW + x + 1] == nP0)
                {
                    nFlags = 2;
                    nLast = pPreset1[y * nW + x + 1];
                }
                if (pPreset1[y * nW + x - 1] && pPreset1[y * nW + x - 1] < nLast && pPreset0[y * nW + x - 1] == nP0)
                {
                    nFlags = 1;
                    nLast = pPreset1[y * nW + x - 1];
                }

                if (nFlags & 8)
                {
                    pLevelPresetId[(y - 1) * nW + x] |= 4;
                }
                if (nFlags & 4)
                {
                    pLevelPresetId[(y + 1) * nW + x] |= 8;
                }
                if (nFlags & 2)
                {
                    pLevelPresetId[y * nW + x + 1] |= 1;
                }
                if (nFlags & 1)
                {
                    pLevelPresetId[y * nW + x - 1] |= 2;
                }

                if (pPreset2[(y - 1) * nW + x] == 1 && pPreset0[(y - 1) * nW + x] != nP0)
                {
                    nFlags |= 8;
                }
                if (pPreset2[(y + 1) * nW + x] == 1 && pPreset0[(y + 1) * nW + x] != nP0)
                {
                    nFlags |= 4;
                }
                if (pPreset2[y * nW + x + 1] == 1 && pPreset0[y * nW + x + 1] != nP0)
                {
                    nFlags |= 2;
                }
                if (pPreset2[y * nW + x - 1] == 1 && pPreset0[y * nW + x - 1] != nP0)
                {
                    nFlags |= 1;
                }
            }

            const int nP1 = pPreset1[y * nW + x];
            if (nP1)
            {
                if (JUNGLE_ABS(nP1 - pPreset1[(y - 1) * nW + x]) == 1)
                {
                    nFlags |= 8;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[(y + 1) * nW + x]) == 1)
                {
                    nFlags |= 4;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[y * nW + x + 1]) == 1)
                {
                    nFlags |= 2;
                }
                if (JUNGLE_ABS(nP1 - pPreset1[y * nW + x - 1]) == 1)
                {
                    nFlags |= 1;
                }
            }

            pLevelPresetId[y * nW + x] |= nFlags;
        }
    }

    for (y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {

            const int nP0 = pPreset0[y * nW + x];
            int nLevelPreset = pLevelPresetId[y * nW + x];
            nColumnSize = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 4);
            const int bHadNoPreset = nLevelPreset == 0;
            if (pPreset2[y * nW + x] == 2)
            {
                nJ = 0;
                int bLook = 1;
                for (; nJ < 4 && bLook; nJ++)
                {
                    switch ((nColumnSize + nJ) % 4)
                    {
                    case 0:
                        if (pPreset0[(y - 1) * nW + x] == nP0 && pLevelPresetId[(y - 1) * nW + x] && pLevelPresetId[(y - 1) * nW + x] < 15)
                        {
                            nLevelPreset |= 0x80;
                            bLook = 0;
                        }
                        break;
                    case 1:
                        if (pPreset0[(y + 1) * nW + x] == nP0 && pLevelPresetId[(y + 1) * nW + x] && pLevelPresetId[(y + 1) * nW + x] < 15)
                        {
                            nLevelPreset |= 0x40;
                            bLook = 0;
                        }
                        break;
                    case 2:
                        if (pPreset0[y * nW + x + 1] == nP0 && pLevelPresetId[y * nW + x + 1] && pLevelPresetId[y * nW + x + 1] < 15)
                        {
                            nLevelPreset |= 0x20;
                            bLook = 0;
                        }
                        break;
                    case 3:
                        if (pPreset0[y * nW + x - 1] == nP0 && pLevelPresetId[y * nW + x - 1] && pLevelPresetId[y * nW + x - 1] < 15)
                        {
                            nLevelPreset |= 0x10;
                            bLook = 0;
                        }
                        break;
                    }
                }

                if (!nLevelPreset)
                {
                    goto RESTART;
                }

                if (bHadNoPreset)
                {
                    nJ = 0;
                    bLook = 1;
                    for (; nJ < 4 && bLook; nJ++)
                    {
                        switch ((nColumnSize + nJ) % 4)
                        {
                        case 0:
                            if (pPreset0[(y - 1) * nW + x] != nP0 && pPreset2[(y - 1) * nW + x] == 2)
                            {
                                nLevelPreset |= 0x80;
                                bLook = 0;
                            }
                            break;
                        case 1:
                            if (pPreset0[(y + 1) * nW + x] != nP0 && pPreset2[(y + 1) * nW + x] == 2)
                            {
                                nLevelPreset |= 0x40;
                                bLook = 0;
                            }
                            break;
                        case 2:
                            if (pPreset0[y * nW + x + 1] != nP0 && pPreset2[y * nW + x + 1] == 2)
                            {
                                nLevelPreset |= 0x20;
                                bLook = 0;
                            }
                            break;
                        case 3:
                            if (pPreset0[y * nW + x - 1] != nP0 && pPreset2[y * nW + x - 1] == 2)
                            {
                                nLevelPreset |= 0x10;
                                bLook = 0;
                            }
                            break;
                        }
                    }

                    bLook = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 2) != 0 && bLook;
                    nColumnSize = SEED_RollLimitedRandomNumber(&pDrlg->pSeed, 4);

                    for (nJ = 0; nJ < 4 && bLook; nJ++)
                    {
                        switch ((nColumnSize + nJ) % 4)
                        {
                        case 0:
                            if (pLevelPresetId[(y - 1) * nW + x] && pLevelPresetId[(y - 1) * nW + x] < 15 && !(nLevelPreset & 0x80))
                            {
                                nLevelPreset |= 0x80;
                                bLook = 0;
                            }
                            break;
                        case 1:
                            if (pLevelPresetId[(y + 1) * nW + x] && pLevelPresetId[(y + 1) * nW + x] < 15 && !(nLevelPreset & 0x40))
                            {
                                nLevelPreset |= 0x40;
                                bLook = 0;
                            }
                            break;
                        case 2:
                            if (pLevelPresetId[y * nW + x + 1] && pLevelPresetId[y * nW + x + 1] < 15 && !(nLevelPreset & 0x20))
                            {
                                nLevelPreset |= 0x20;
                                bLook = 0;
                            }
                            break;
                        case 3:
                            if (pLevelPresetId[y * nW + x - 1] && pLevelPresetId[y * nW + x - 1] < 15 && !(nLevelPreset & 0x10))
                            {
                                nLevelPreset |= 0x10;
                                bLook = 0;
                            }
                            break;
                        }
                    }
                }

                if (nLevelPreset & 0x80)
                {
                    pLevelPresetId[(y - 1) * nW + x] |= 0x40;
                }
                if (nLevelPreset & 0x40)
                {
                    pLevelPresetId[(y + 1) * nW + x] |= 0x80;
                }
                if (nLevelPreset & 0x20)
                {
                    pLevelPresetId[y * nW + x + 1] |= 0x10;
                }
                if (nLevelPreset & 0x10)
                {
                    pLevelPresetId[y * nW + x - 1] |= 0x20;
                }

                pPreset2[y * nW + x] = 0;
            }

            pLevelPresetId[y * nW + x] |= nLevelPreset;
        }
    }

    for (y = 0; y < nH; y++)
    {
        for (x = 0; x < nW; x++)
        {
            const int nId = pLevelPresetId[y * nW + x];
            int nPDef = nId % 16;
            if (nPDef != 0)
            {
                if (nId >= 16)
                {
                    if (nId & 0x10)
                    {
                        nPDef = gnJunglePresets[nPDef][0];
                    }
                    if (nId & 0x20)
                    {
                        nPDef = gnJunglePresets[nPDef][1];
                    }
                    if (nId & 0x40)
                    {
                        nPDef = gnJunglePresets[nPDef][2];
                    }
                    if (nId & 0x80)
                    {
                        nPDef = gnJunglePresets[nPDef][3];
                    }
                    D2_ASSERT(nPDef != 0, 0x78C);
                }
                else
                {
                    nPDef += 0x211;
                }
            }
            else if (nId >= 16)
            {
                nPDef = gnSpiderForestPresets[nId >> 4];
                D2_ASSERT(nPDef != 0, 0x799);
            }

            pLevelPresetId[y * nW + x] = nPDef;
        }
    }

    for (nJ = 0; nJ < 3; nJ++)
    {
        int nDef = 0;
        for (int by = 0; by < nBlocksY; by++)
        {
            for (int bx = 0; bx < nBlocksX; bx++)
            {
                tJungles[nJ].pJungleDefs[nDef] = pLevelPresetId[(tJungles[nJ].nPresetsBlocksY + by) * nW + bx + tJungles[nJ].nPresetsBlocksX];
                if (tJungles[nJ].pJungleDefs[nDef] > 0x23E)
                {
                    ++tJungles[nJ].nJungleDefs;
                }
                ++nDef;
            }
        }
    }

    int bSwapped;
    do
    {
        bSwapped = 0;
        for (nJ = 0; nJ < 2; nJ++)
        {
            if (tJungles[nJ + 1].tCoord.nY > tJungles[nJ].tCoord.nY)
            {
                D2JungleStrc tTemp = tJungles[nJ + 1];
                tJungles[nJ + 1] = tJungles[nJ];
                tJungles[nJ] = tTemp;
                bSwapped = 1;
            }
        }
    }
    while (bSwapped);

    D2DrlgLevelStrc* pJungleLevel = 0;
    for (nJ = 0; nJ < 3; nJ++)
    {
        pJungleLevel = DRLG_GetLevel(pDrlg, nJ + 76);
        pJungleLevel->pnJungleDefs = tJungles[nJ].pJungleDefs;
        pJungleLevel->nJungleDefs = tJungles[nJ].nJungleDefs;
        pJungleLevel->nPosX = tJungles[nJ].tCoord.nX;
        pJungleLevel->nPosY = tJungles[nJ].tCoord.nY;
        pJungleLevel->nWidth = tJungles[nJ].tCoord.nA;
        pJungleLevel->nHeight = tJungles[nJ].tCoord.nB;
    }

    FOG_FreePool(pMemPool, pPreset0, gszOutPlaceFile, 0x7D2, 0);
    FOG_FreePool(pMemPool, pPreset1, gszOutPlaceFile, 0x7D3, 0);
    FOG_FreePool(pMemPool, pPreset2, gszOutPlaceFile, 0x7D4, 0);
    FOG_FreePool(pMemPool, pLevelPresetId, gszOutPlaceFile, 0x7D5, 0);

    return pJungleLevel;
}

// 0x00678910
D2DrlgLevelStrc* __stdcall DRLGOUTPLACE_PlaceKurastLevels(D2DrlgLevelStrc* pLevel)
{
    D2LevelDefBin* pLevelDef;
    D2DrlgLevelStrc* pAdjacentLevel;
    int nSizeX;
    int nSizeY;
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    int nHalfWidth = pLevel->nWidth / 2;
    int nPosY = 0;

    for (int i = 0; i < 5; ++i)
    {
        pLevelDef = DATATBLS_GetLevelDefRecord(79 + i);
        nSizeX = pLevelDef->dwSizeX[pDrlg->nDifficulty];
        nSizeY = pLevelDef->dwSizeY[pDrlg->nDifficulty];
        nPosY -= nSizeY;
        pAdjacentLevel = DRLG_GetLevel(pDrlg, 79 + i);
        const int nOffsetX = nHalfWidth - nSizeX / 2;
        pAdjacentLevel->nPosX = nOffsetX + pLevel->nPosX;
        pAdjacentLevel->nPosY = pLevel->nPosY + nPosY;
        pAdjacentLevel->nWidth = nSizeX;
        pAdjacentLevel->nHeight = nSizeY;
    }

    return pAdjacentLevel;
}


static void DRLGOUTPLACE_CreateAct3LevelConnections(D2DrlgStrc* pDrlg); // 0x006789B0
// 0x006789B0
static void DRLGOUTPLACE_CreateAct3LevelConnections(D2DrlgStrc* pDrlg)
{
    D2DrlgLevelStrc* pLevel = DRLG_GetLevel(pDrlg, LEVEL_KURASTDOCKTOWN);
    D2LevelDefBin* pDef = DATATBLS_GetLevelDefRecord(LEVEL_KURASTDOCKTOWN);
    pLevel->nPosX = pDef->dwOffsetX;
    pLevel->nPosY = pDef->dwOffsetY;
    pLevel->nWidth = pDef->dwSizeX[pDrlg->nDifficulty];
    pLevel->nHeight = pDef->dwSizeY[pDrlg->nDifficulty];
    pLevel = DRLG_GenerateJungles(pLevel);
    DRLGOUTPLACE_PlaceKurastLevels(pLevel);
    DRLGOUTPLACE_SetOverlapWarps(75, 83, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 83, 75);
}

// 0x00678A20
static void DRLGOUTPLACE_CreateAct4LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct4OutdoorDrlgLink, DRLGOUTPLACE_LinkAct4Outdoors, 0, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct4ChaosSanctumDrlgLink, DRLGOUTPLACE_LinkAct4ChaosSanctum, 0, pDrlg);

    DRLG_GetLevel(pDrlg, LEVEL_OUTERSTEPPES)->pOutdoors->dwFlags |= gnDrlgLinkFlags_0096D66C;

    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x6A, 0x67);
}

// 0x00678A70
static void DRLGOUTPLACE_CreateAct5LevelConnections(D2DrlgStrc* pDrlg)
{
    DRLGOUTPLACE_InitLevelLinks(gAct5OutdoorDrlgLink, 0, 0, pDrlg);
    DRLGOUTPLACE_InitLevelLinks(gAct5TundraDrlgLink, 0, 0, pDrlg);

    DRLGOUTPLACE_SetOverlapWarps(0x6F, 0x70, pDrlg);
    DRLGOUTPLACE_AddLevelOrths(pDrlg, 0x70, 0x6F);

    DRLGOUTPLACE_SetOverlapWarps(0x6E, 0x6F, pDrlg);
    DRLGOUTPLACE_SetOverlapWarps(0x6D, 0x6E, pDrlg);

    DRLGOUTPLACE_InitLevelLinks(gAct5UbersDrlgLink, DRLGOUTPLACE_LinkAct5Ubers, 0, pDrlg);
}
// 0x00678AD0
void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg, unsigned char nAct)
{
    switch (nAct)
    {
    case 0:
        DRLGOUTPLACE_CreateAct1LevelConnections(pDrlg);
        break;
    case 1:
        DRLGOUTPLACE_CreateAct2LevelConnections(pDrlg);
        break;
    case 2:
        DRLGOUTPLACE_CreateAct3LevelConnections(pDrlg);
        break;
    case 3:
        DRLGOUTPLACE_CreateAct4LevelConnections(pDrlg);
        break;
    case 4:
        DRLGOUTPLACE_CreateAct5LevelConnections(pDrlg);
        break;
    }
}
