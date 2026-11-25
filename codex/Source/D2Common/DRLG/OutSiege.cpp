#include "D2LevelIds.h"
#include "D2DrlgPresets.h"
#include "D2DrlgRooms.h"
#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"

struct D2CoordStrc;

struct D2DrlgVertexStrc;

struct D2DrlgOutdoorInfoStrc;

struct D2LvlPrestRecordStrc;

struct D2DrlgOutPlaceCtxStrc;

struct D2Act5CornerPresetStrc;

struct D2Act5TypeRangeStrc;

struct D2Act5LevelPresetStrc;

struct D2LvlPrestRecordStrc
{
    char unk0x00[0x28];
    int nSizeX;
    int nSizeY;
};

struct D2DrlgOutPlaceCtxStrc
{
    D2DrlgLevelStrc* pLevel;
    int* pUnk54;
    D2DrlgGridStrc* pGrid04;
    D2DrlgGridStrc* pGrid2C;
    int unk0x10;
    int n14;
    int n18;
    int unk0x1C;
    int unk0x20;
    int (__fastcall* pfnTest)(D2DrlgLevelStrc*, int, int, int, int, unsigned int);
    int (__fastcall* pfnGetPreset)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn2C)(D2DrlgLevelStrc*, int, int);
    int (__fastcall* pfn30)(D2DrlgLevelStrc*, int, int);
    void (__fastcall* pfnPlace)(D2DrlgLevelStrc*, int, int, int, int, int);
};

struct D2Act5CornerPresetStrc
{
    int nLevelId;
    int nArg;
    int f_8;
    int nPresetTall;
    int nPresetWide;
};

struct D2Act5TypeRangeStrc
{
    int nType;
    int nMin;
    int nMax;
    int nPresetA;
    int nPresetB;
};

struct D2Act5LevelPresetStrc
{
    int nLevelId;
    int nPresetTall;
    int nPresetWide;
    int nArg;
    int nUnk10;
    int nCount;
    int bRequired;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlag, int eOperation); // 0x0067C4F0

void __fastcall DRLGVER_GetCoordDiff(D2DrlgVertexStrc* pVertex, int* pDirectionX, int* pDirectionY); // 0x0067D280

D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6); // 0x006743C0

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nPresetId, int nArg, int a4, int a5); // 0x00674730

void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770

void __fastcall sub_00670750(D2DrlgOutPlaceCtxStrc* pCtx); // 0x00670750

unsigned int __fastcall DRLGOUTDOORS_TestGridCellNonLvlLink(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741E0

int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674120

int __fastcall DRLGOUTDOORS_AlterAdjacentPresetGridCells(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674160

int __fastcall DRLGOUTDOORS_SetBlankGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741A0

int __fastcall DRLGOUTDOORS_GetBorderLevelPrestId(int nDirX, int nDirY, int nSize); // 0x006755C0

int __fastcall DRLGOUTDOORS_GetCornerPresetId(int nDirX, int nDirY, int nNextDirX, int nNextDirY, int nSize); // 0x00675600

void __stdcall DRLGOUTSIEGE_PlaceCliffBorder(D2DrlgLevelStrc* pLevel); // 0x0067DCF0

void __stdcall DRLGOUTSIEGE_PlaceRavineBorder(D2DrlgLevelStrc* pLevel); // 0x0067DEF0

int __fastcall DRLGOUTDOORS_GetPresetIndexFromGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674120

struct D2LvlPrestTxt;

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nId); // 0x0061F0B0

void __fastcall sub_006743C0(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nDirection, int a6);

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730

int __fastcall sub_006741E0(D2DrlgLevelStrc* pLevel, int nX, int nY);

void DRLGACT5_PlaceCornerPresets(D2DrlgLevelStrc* pLevel);

int __stdcall DRLGOUTSIEGE_SpawnPresetAtLvlLinkCell(D2DrlgOutdoorInfoStrc* pInfo, int nX, int nY, D2DrlgLevelStrc* pLevel, int nPresetId);

void __stdcall DRLGOUTSIEGE_PlaceBarricadeEntrancesAndExits(D2DrlgLevelStrc* pLevel);

void DRLGOUTSIEGE_MarkBottomRightLvlLinkCells(D2DrlgLevelStrc* pLevel);

int __fastcall DRLGOUTSIEGE_GetBorderLookupId(D2DrlgLevelStrc* pLevel);

int __fastcall DRLGOUTSIEGE_GetSecondaryBorderPresetId(D2DrlgLevelStrc* pLevel, int nType, int nIndex);

int __fastcall DRLGOUTSIEGE_TestSecondaryBorderCell(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nUnused, unsigned int dwCellFlags);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

static int DRLGOUTSIEGE_PlacePrisonAtCell(D2DrlgLevelStrc* pLevel, int nX, int nY);

struct D2DrlgOutSiegeInitStrc
{
    int nLevelId;
    int field_4;
    int field_8;
    int nLevelPrestId1;
    int nLevelPrestId2;
};

extern const D2DrlgOutSiegeInitStrc gaOutSiegeCaves[3]; // 0x006F1F9C

void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel); // 0x00675770

void __stdcall DRLGOUTSIEGE_PlaceSpecialPresets(D2DrlgLevelStrc* pLevel); // 0x0067E160

static void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel); // 0x0067DA70

int DRLGACT5_ReplaceTransitionPreset(D2DrlgLevelStrc* pLevel, int nX, int nY);

void __stdcall DRLGOUTSIEGE_PlaceSiegeToTownPresets(D2DrlgLevelStrc* pLevel);

void __fastcall DRLGOUTSIEGE_InitAct5OutdoorLevel(D2DrlgLevelStrc* pLevel);

static void DRLGOUTSIEGE_AddAct5SecondaryBorder(D2DrlgLevelStrc* pLevel);

static void DRLGOUTSIEGE_PlacePrisons(D2DrlgLevelStrc* pLevel);

static void DRLGOUTSIEGE_ConnectBarricadeAndSiege(D2DrlgLevelStrc* pLevel);

extern const D2CoordStrc gaAct5WallSteps[12]; // 0x006F1FD8

void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nIndex, int nPresetId);                     // 0x006752A0

void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel);                                                  // 0x00675850

static const int gAct4SecondPresetBase[3] = { 828, 832, 832 }; // 0x006F22A4

static const int gAct4FirstPresetBase[3] = { 812, 817, 823 }; // 0x006F22B0

int __fastcall DRLGOUTDOORS_GetBorderLevelPrestId(int nA, int nB, int nC);                                             // 0x006755C0

static const D2Act5CornerPresetStrc gAct5CornerPresets[3] =
{
    { 112, 0, 0, 913, 914 },
    { 117, 0, 1, 983, 984 },
    { 117, 0, 0, 985, 986 },
};

// 0x0067DA70
static void DRLGOUTSIEGE_PlaceCaves(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int i = 0; i < 3; ++i)
    {
        if (pLevel->eLevelId == gaOutSiegeCaves[i].nLevelId)
        {
            int nLevelPrestId;
            int nX;
            int nY;
            if (pLevel->nWidth > pLevel->nHeight)
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId2;
                DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
                nX = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridWidth - 2 : 0;
                nY = 2;
            }
            else
            {
                nLevelPrestId = gaOutSiegeCaves[i].nLevelPrestId1;
                DATATBLS_GetLvlPrestTxtRecord(nLevelPrestId);
                nX = 2;
                nY = gaOutSiegeCaves[i].field_8 ? pOutdoors->nGridHeight - 2 : 0;
            }
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nLevelPrestId, gaOutSiegeCaves[i].field_4, 0);
        }
    }
}

// build: symbol ?DRLGOUTSIEGE_InitAct5OutdoorLevel@@YIXPAUD2DrlgLevelStrc@@@Z 0x0067E600
// build: symbol ?DRLGOUTSIEGE_PlaceSpecialPresets@@YGXPAUD2DrlgLevelStrc@@@Z 0x0067E160
// 0x0067DB00
static int __stdcall DRLGOUTSIEGE_SpawnPresetAtLvlLinkCell(D2DrlgOutdoorInfoStrc* pInfo, int nX, int nY, D2DrlgLevelStrc* pLevel, int nPresetId)
{
    if (DRLGGRID_GetGridEntry(&pInfo->pGrid[2], nX, nY) & 0x400)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPresetId, (pLevel->eLevelId == LEVEL_BLOODYFOOTHILLS) ? 1 : -1, 0);
        return 1;
    }
    return 0;
}

// 0x0067DB50
void __stdcall DRLGOUTSIEGE_PlaceBarricadeEntrancesAndExits(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;

    for (int nX = 0; nX < pInfo->nGridWidth; ++nX)
    {
        if (DRLGOUTSIEGE_SpawnPresetAtLvlLinkCell(pInfo, nX, 0, pLevel, 0x38D))
        {
            break;
        }
    }

    int nBottom = pInfo->nGridHeight - 2;
    for (int nX = 0; nX < pInfo->nGridWidth; ++nX)
    {
        if (DRLGOUTSIEGE_SpawnPresetAtLvlLinkCell(pInfo, nX, nBottom, pLevel, 0x38C))
        {
            break;
        }
    }

    for (int nY = 0; nY < pInfo->nGridHeight; ++nY)
    {
        if (DRLGOUTSIEGE_SpawnPresetAtLvlLinkCell(pInfo, 0, nY, pLevel, 0x38E))
        {
            break;
        }
    }

    int nRight = pInfo->nGridWidth - 2;
    for (int nY = 0; nY < pInfo->nGridHeight; ++nY)
    {
        if (DRLGOUTSIEGE_SpawnPresetAtLvlLinkCell(pInfo, nRight, nY, pLevel, 0x38B))
        {
            break;
        }
    }
}

// 0x0067DCA0
static void DRLGOUTSIEGE_MarkBottomRightLvlLinkCells(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;

    const int nX = pInfo->nGridWidth - 2;
    const int nY = pInfo->nGridHeight - 3;
    D2DrlgGridStrc* const pGrid = &pInfo->pGrid[2];
    DRLGGRID_AlterGridFlag(pGrid, pInfo->nGridWidth - 2, pInfo->nGridHeight - 4, 0x400, 0);
    DRLGGRID_AlterGridFlag(pGrid, nX, nY, 0x400, 0);
}

// 0x0067DCE0
int __fastcall DRLGOUTSIEGE_GetBorderLookupId(D2DrlgLevelStrc* pLevel)
{
    return (pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS) + 4;
}

// 0x0067DCF0
void __stdcall DRLGOUTSIEGE_PlaceCliffBorder(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pInfo->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;
    int nSize = DRLGOUTSIEGE_GetBorderLookupId(pLevel);

    do
    {
        int nDirX;
        int nDirY;
        int nNextDirX;
        int nNextDirY;
        DRLGVER_GetCoordDiff(pVertex, &nDirX, &nDirY);
        DRLGVER_GetCoordDiff(pNext, &nNextDirX, &nNextDirY);

        int nAbsDirX = nDirX < 0 ? -nDirX : nDirX;
        int nAbsDirY = nDirY >= 0 ? nDirY : -nDirY;

        int nX = pVertex->nPosX & ~1;
        int nY = pVertex->nPosY & ~1;
        int nNextX = pNext->nPosX & ~1;
        int nNextY = pNext->nPosY & ~1;
        int nPresetId = DRLGOUTDOORS_GetBorderLevelPrestId(nDirX, nDirY, nSize);

        if (!(pVertex->dwFlags & 2))
        {
            while (nX != nNextX || nY != nNextY)
            {
                nX += 2 * nDirX;
                nY += 2 * nDirY;
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPresetId, -1, 0);
                DRLGGRID_AlterGridFlag(&pInfo->pGrid[2], nX, nY, 1, 0);
            }
        }

        if (pVertex->dwFlags & 1)
        {
            int nMaxX = pVertex->nPosX <= pNext->nPosX ? pNext->nPosX : pVertex->nPosX;
            int nMarkX = (nMaxX - 4 * nAbsDirX) & ~1;
            int nMaxY = pVertex->nPosY > pNext->nPosY ? pVertex->nPosY : pNext->nPosY;
            int nMarkY = (nMaxY - 4 * nAbsDirY) & ~1;
            DRLGGRID_AlterGridFlag(&pInfo->pGrid[2], nMarkX, nMarkY, 0x400, 0);
            DRLGGRID_AlterGridFlag(&pInfo->pGrid[2], nMarkX + 2 * nAbsDirX, nMarkY + 2 * nAbsDirY, 0x400, 0);
        }

        int nCornerPresetId = DRLGOUTDOORS_GetCornerPresetId(2 * nDirX, 2 * nDirY, 2 * nNextDirX, 2 * nNextDirY, nSize);
        if (nCornerPresetId)
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nNextX, nNextY, nCornerPresetId, -1, 0);
            DRLGGRID_AlterGridFlag(&pInfo->pGrid[2], nNextX, nNextY, 1, 0);
        }

        pVertex = pNext;
        pNext = pNext->pNext;
    }
    while (pVertex != pInfo->pVertex);

    if (pLevel->eLevelId == LEVEL_ID_ACT5_BARRICADE_1)
    {
        DRLGOUTSIEGE_MarkBottomRightLvlLinkCells(pLevel);
    }
}

// 0x0067DEF0
void __stdcall DRLGOUTSIEGE_PlaceRavineBorder(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    int nRight = pInfo->nGridWidth - 2;
    int nX = nRight;
    int nY = 0;
    int nBottom = pInfo->nGridHeight - 2;
    int bTundra = pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS;
    int nKindBase = bTundra ? 0x3BD : 0x371;
    int nPresetBase = bTundra ? 0x3C9 : 0x37D;

    while (nX != 0 || nY != nBottom)
    {
        const int nEntry = DRLGGRID_GetGridEntry(&pInfo->pGrid[0], nX, nY);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nEntry - nKindBase + nPresetBase, -1, 0);
        nX += 2 * gaAct5WallSteps[nEntry - nKindBase].nX;
        nY += 2 * gaAct5WallSteps[nEntry - nKindBase].nY;
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nRight, 0, bTundra ? 0x3D6 : 0x38A, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, nBottom, bTundra ? 0x3D5 : 0x389, -1, 0);
}

static const D2CoordStrc gAct5WallSteps[12] =
{
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
    { 0, -1 }, { 1, 0 }, { 0, 1 }, { -1, 0 },
    { -1, 0 }, { 0, -1 }, { 1, 0 }, { 0, 1 },
};

static const D2Act5TypeRangeStrc gAct5TypeRanges[10] = // 0x006F2038
{
    { 49, 1, 16, 915, 987 },
    { 49, 31, 46, 915, 987 },
    { 48, 1, 1, 883, 959 },
    { 48, 2, 3, 881, 957 },
    { 48, 4, 4, 884, 960 },
    { 48, 5, 5, 895, 971 },
    { 48, 6, 7, 893, 969 },
    { 48, 8, 8, 896, 972 },
    { 48, 30, 30, 0, 0 },
    { 48, 31, 31, -5, -5 },
};

// 0x0067E000
int __fastcall DRLGOUTSIEGE_GetSecondaryBorderPresetId(D2DrlgLevelStrc* pLevel, int nType, int nIndex)
{
    if (nType != 48 && nType != 49)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 388);
        exit(-1);
    }

    int bTundra = pLevel->eLevelId == LEVEL_TUNDRAWASTELANDS;
    for (int i = 0; i < 10; ++i)
    {
        const D2Act5TypeRangeStrc* pEntry = &gAct5TypeRanges[i];
        if (nType == pEntry->nType && nIndex >= pEntry->nMin && nIndex <= pEntry->nMax)
        {
            if (bTundra)
            {
                return pEntry->nPresetB - pEntry->nMin + nIndex;
            }
            return pEntry->nPresetA - pEntry->nMin + nIndex;
        }
    }

    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 421);
    exit(-1);
}

// 0x0067E080
int __fastcall DRLGOUTSIEGE_TestSecondaryBorderCell(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nUnused, unsigned int dwCellFlags)
{
    int nResult = DRLGOUTSIEGE_GetSecondaryBorderPresetId(pLevel, (dwCellFlags >> 20) & 0x3F, (dwCellFlags >> 8) & 0xFF);
    if (nResult == -5)
    {
        return 1;
    }

    if (nResult != nPresetId)
    {
        return 0;
    }

    return DRLGOUTDOORS_TestGridCellNonLvlLink(pLevel, nX, nY) != 0;
}

// 0x0067E0E0
static void DRLGOUTSIEGE_AddAct5SecondaryBorder(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_BLOODYFOOTHILLS)
    {
        return;
    }

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    D2DrlgOutPlaceCtxStrc tCtx;
    memset(&tCtx, 0, sizeof(tCtx));
    tCtx.pLevel = pLevel;
    tCtx.pUnk54 = &pInfo->nWidth;
    tCtx.pGrid04 = &pInfo->pGrid[0];
    tCtx.pGrid2C = &pInfo->pGrid[2];
    tCtx.pfnTest = DRLGOUTSIEGE_TestSecondaryBorderCell;
    tCtx.pfn2C = DRLGOUTDOORS_AlterAdjacentPresetGridCells;
    tCtx.pfn30 = DRLGOUTDOORS_SetBlankGridCell;
    tCtx.pfnPlace = DRLGOUTDOORS_SpawnOutdoorLevelPresetEx;
    tCtx.pfnGetPreset = DRLGOUTSIEGE_GetSecondaryBorderPresetId;
    tCtx.n14 = -1;
    tCtx.n18 = 12;
    sub_00670750(&tCtx);
}

static const D2Act5LevelPresetStrc gAct5LevelPresets[15] = // 0x006F2100
{
    { 111, 955, 956, 0, 25, 1, 1 },
    { 112, 955, 956, 0, 25, 1, 1 },
    { 117, 955, 956, 1, 25, 1, 1 },
    { 112, 953, 953, -1, 25, 1, 1 },
    { 117, 954, 954, -1, 25, 1, 1 },
    { 111, 944, 947, -1, 10, 1, 0 },
    { 111, 942, 945, -1, 20, 4, 0 },
    { 111, 943, 946, -1, 20, 4, 0 },
    { 112, 941, 941, -1, 10, 1, 0 },
    { 112, 939, 939, -1, 8, 1, 0 },
    { 112, 940, 940, -1, 15, 5, 0 },
    { 117, 948, 948, -1, 9, 4, 0 },
    { 117, 949, 949, -1, 9, 4, 0 },
    { 117, 950, 950, -1, 9, 4, 0 },
    { 117, 951, 951, -1, 5, 3, 0 },
};

// 0x0067E160
void __stdcall DRLGOUTSIEGE_PlaceSpecialPresets(D2DrlgLevelStrc* pLevel)
{
    int bTall = pLevel->nWidth < pLevel->nHeight;
    for (int i = 0; i < 15; ++i)
    {
        if (pLevel->eLevelId == gAct5LevelPresets[i].nLevelId)
        {
            int nPresetId;
            if (bTall)
            {
                nPresetId = gAct5LevelPresets[i].nPresetTall;
            }
            else
            {
                nPresetId = gAct5LevelPresets[i].nPresetWide;
            }

            int nArg = gAct5LevelPresets[i].nArg;
            int bPlaced = 0;
            for (int j = 0; j < gAct5LevelPresets[i].nCount; ++j)
            {
                bPlaced = DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nPresetId, nArg, 0, 15);
            }

            if (!(bPlaced || !gAct5LevelPresets[i].bRequired))
            {
                FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 537);
                exit(-1);
            }
        }
    }
}

// 0x0067E210
static inline int DRLGOUTSIEGE_PlacePrisonAtCell(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    const int nPreset = DRLGOUTDOORS_GetPresetIndexFromGridCell(pLevel, nX, nY);
    if (nPreset >= 0x393 && nPreset <= 0x39A)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPreset + 0x10, -1, 0);
        return 1;
    }
    return 0;
}

int __fastcall sub_M119_Emit_0067E210(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    return DRLGOUTSIEGE_PlacePrisonAtCell(pLevel, nY, nX);
}

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

// 0x0067E240
static void DRLGOUTSIEGE_PlacePrisons(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId != LEVEL_ID_ACT5_BARRICADE_1)
        return;

    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (!pInfo)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 564);
        exit(-1);
    }

    int nPlaced;
    int i;
    for (i = 0, nPlaced = 0; i < 90 && nPlaced < 3; ++i)
    {
        const int nX = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nGridWidth / 2);
        const int nY = 2 * SEED_RollLimitedRandomNumber(&pLevel->pSeed, pInfo->nGridHeight / 2);
        if (DRLGOUTSIEGE_PlacePrisonAtCell(pLevel, nX, nY))
            ++nPlaced;
    }

    const int nOffsetX = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nGridWidth / 2);
    const int nOffsetY = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, pInfo->nGridHeight / 2);
    for (int y = 0; y < pInfo->nGridHeight && nPlaced < 3; ++y)
    {
        for (int x = 0; x < pInfo->nGridWidth && nPlaced < 3; ++x)
        {
            const int nX = (x + 2 * nOffsetX) % pInfo->nGridWidth;
            const int nY = (y + 2 * nOffsetY) % pInfo->nGridHeight;
            if (DRLGOUTSIEGE_PlacePrisonAtCell(pLevel, nX, nY))
                ++nPlaced;
        }
    }

    if (nPlaced < 3)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 601);
        exit(-1);
    }
}

void __fastcall sub_Emit_0067E240(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTSIEGE_PlacePrisons(pLevel);
    DRLGOUTSIEGE_PlacePrisons(pLevel);
}

static int DRLGACT5_ReplaceTransitionPreset(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    int nPresetId = DRLGOUTDOORS_GetPresetIndexFromGridCell(pLevel, nX, nY);
    if (nPresetId < 0x393 || nPresetId > 0x39A)
    {
        return 0;
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nPresetId + 0x10, -1, 0);
    return 1;
}

// 0x0067E4B0
static void DRLGOUTSIEGE_ConnectBarricadeAndSiege(D2DrlgLevelStrc* ptLevelData)
{
    if (!ptLevelData)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 623);
        exit(-1);
    }

    if (ptLevelData->eLevelId != LEVEL_ID_ACT5_BARRICADE_1)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 624);
        exit(-1);
    }

    D2DrlgOutdoorInfoStrc* pInfo = ptLevelData->pOutdoors;
    if (!pInfo)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 627);
        exit(-1);
    }

    D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(0x370);
    if (!pRecord)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 631);
        exit(-1);
    }

    int nX = pInfo->nGridWidth - pRecord->nSizeX / 8;
    int nY = pInfo->nGridHeight - pRecord->nSizeY / 8;
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(ptLevelData, nX, nY, 0x370, -1, 0);
    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(ptLevelData, nX, nY - 2, 0x380, -1, 0);
}

// 0x0067E560
void __stdcall DRLGOUTSIEGE_PlaceSiegeToTownPresets(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (!pInfo)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 650);
        exit(-1);
    }

    D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(0x361);
    if (!pRecord)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 653);
        exit(-1);
    }

    int nStep = pRecord->nSizeX / 8;
    int nX = pInfo->nGridWidth - nStep;
    for (int i = 0; i < 15; ++i)
    {
        if (nX < 0)
        {
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 660);
            exit(-1);
        }

        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, 0, 0x361 + i, 0, 0);
        nX -= nStep;
    }
}

// 0x0067E600
void __fastcall DRLGOUTSIEGE_InitAct5OutdoorLevel(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_BLOODYFOOTHILLS)
    {
        DRLGOUTSIEGE_PlaceSiegeToTownPresets(pLevel);
        return;
    }

    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    DRLGOUTSIEGE_PlaceCliffBorder(pLevel);
    DRLGOUTSIEGE_PlaceRavineBorder(pLevel);
    DRLGOUTSIEGE_PlaceBarricadeEntrancesAndExits(pLevel);
    DRLGOUTSIEGE_PlaceCaves(pLevel);

    if (pLevel->eLevelId == LEVEL_ID_ACT5_BARRICADE_1)
    {
        DRLGOUTSIEGE_ConnectBarricadeAndSiege(pLevel);
    }

    DRLGOUTSIEGE_AddAct5SecondaryBorder(pLevel);
    DRLGOUTSIEGE_PlacePrisons(pLevel);
    DRLGOUTSIEGE_PlaceSpecialPresets(pLevel);
}

static const int gAct4Level108Presets[25] = // 0x006F22C0
{
    836, 836, 836, 836, 836,
    836, 836, 861, 836, 836,
    836, 858, 862, 859, 836,
    836, 836, 860, 836, 836,
    836, 836, 857, 836, 836,
};

// 0x0067E660
static void sub_0067E660(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pInfo = pLevel->pOutdoors;
    if (pInfo->dwFlags & 0x400000)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 1, 0x31E, -1, 0);
    }
    if (pInfo->dwFlags & 0x800000)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 4, 0x31E, -1, 0);
    }
}

// 0x0067E6A0
static void sub_0067E6A0(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_CITYOFTHEDAMNED)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x32B, -1, 0, 15);
    }

    int nFirst = gAct4FirstPresetBase[pLevel->eLevelId - 104];
    int nSecond = gAct4SecondPresetBase[pLevel->eLevelId - 104];

    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 1, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 1, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 2, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 2, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 3, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 3, -1, 0, 15);

    if (pLevel->eLevelId == LEVEL_PLAINSOFDESPAIR)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x336, -1, 0, 15);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 4, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 4, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 4, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nFirst + 4, -1, 0, 15);

    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 1, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 1, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 2, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 2, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 3, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 3, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 3, -1, 0, 15);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nSecond + 3, -1, 0, 15);
}

// 0x0067E840
static void sub_0067E840(D2DrlgLevelStrc* pLevel)
{
    for (int i = 0; i < 25; ++i)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, (i % 5) * 3, (i / 5) * 3, gAct4Level108Presets[i], -1, 0);
    }
}

// 0x0067E890
void __fastcall sub_0067E890(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_CHAOSSANCTUM)
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    }
    else
    {
        DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
        DRLGOUTPLACE_PlaceAct1245OutdoorBorders(pLevel);
    }

    switch (pLevel->eLevelId)
    {
    case 104:
    case 105:
    case 106:
        sub_0067E660(pLevel);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 0x31F);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 0x31F);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 0x31F);
        sub_0067E6A0(pLevel);
        break;

    case 108:
        sub_0067E840(pLevel);
        break;
    }
}

#include "gen/data/Source/D2Common/DRLG/OutSiege.inc"
