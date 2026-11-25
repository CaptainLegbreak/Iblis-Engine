#include "D2LevelIds.h"
#include "D2DrlgTiles.h"
#include "D2TxtItems.h"
#include "D2DrlgMaps.h"
#include "D2DrlgRooms.h"
#include "D2ItemModes.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2Drlg.h"
#include "D2Common.h"
#include "D2Path.h"

struct D2DrlgStrc;

struct D2DrlgOutDesertInitStrc
{
    int nLvlPrestId;
    int nRand;
    int nX;
    int nY;
};

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId);                                     // 0x0061F0B0

void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730

void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel);                                   // 0x00674B70

void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines);                      // 0x00674E40

void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId); // 0x006752A0

void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel);                                  // 0x00675770

void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel);                           // 0x00675850

void __fastcall DRLGOUTDESR_PlaceDesertTransitionToTown(D2DrlgLevelStrc* pLevel);                           // 0x0067F560

void __fastcall DRLGOUTDESR_AddExits(D2DrlgLevelStrc* pLevel);                                              // 0x0067F670

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                  // 0x00642BB0

int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordStrc* pCoords, int nLevelPrestId, int nPickedFile, int a5, int a6); // 0x006744F0

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                // 0x0067C570

void __stdcall DRLGOUTDESR_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn);                             // 0x0067FE90

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern const D2DrlgOutDesertInitStrc gaDesertCliffs[8][5];                                         // 0x006F2390

extern const D2DrlgOutDesertInitStrc gaCanyonTombEntries[9];                                       // 0x006F2610

union D2SeedStrc;

struct D2DrlgOutdoorInfoStrc;

struct D2DrlgCoordsStrc;

struct D2LvlPrestTxt;

struct D2DrlgOutDesertInitStrc;

static void __stdcall DRLGOUTDESR_PlacePresetVariants(const int* pLevelPrestIds, int nVariants, int bIterateFiles, D2DrlgLevelStrc* pLevel); // 0x0067F470

static void DRLGOUTWILD_SpawnTownTransitionsAndCaves(D2DrlgLevelStrc* pLevel); // 0x006803D0

static void DRLGOUTDESR_PlaceCliffs(D2DrlgLevelStrc* pLevel); // 0x0067F5C0

static void DRLGOUTDESR_PlaceBorders(D2DrlgLevelStrc* pLevel);

static void DRLGOUTDESR_PlaceRockyWasteVariants(D2DrlgLevelStrc* pLevel);

static void DRLGOUTDESR_PlaceDryHillsVariants(D2DrlgLevelStrc* pLevel);

static void DRLGOUTDESR_PlaceFarOasisVariants(D2DrlgLevelStrc* pLevel);

static void DRLGOUTDESR_PlaceFillsInFarOasis(D2DrlgLevelStrc* pLevel);

static void DRLGOUTDESR_PlaceRuinsInLostCity(D2DrlgLevelStrc* pLevel);

static void DRLGOUTDESR_PlaceFillsInLostCity(D2DrlgLevelStrc* pLevel);

static void DRLGOUTDESR_PlaceTombEntriesInCanyon(D2DrlgLevelStrc* pLevel); // 0x0067F8D0

static void DRLGOUTDESR_PlaceFillsInCanyon(D2DrlgLevelStrc* pLevel);

void __fastcall DRLGOUTDESR_InitAct2OutdoorLevel(D2DrlgLevelStrc* pLevel);

static int DRLGOUTWILD_TestSpawnRiver(int nX, D2DrlgLevelStrc* pLevel);

static int __stdcall DRLGOUTWILD_SpawnCliffCaves(D2DrlgLevelStrc* pLevel, int nX, int nY);

void __stdcall DRLGOUTDESR_SpawnRiverAndCliffCaves(D2DrlgLevelStrc* pLevel); // 0x00680200

struct D2PresetPairStrc;

struct D2PresetPairStrc
{
    int nFirst;
    int nSecond;
};

extern D2PresetPairStrc gaPresetPairs_006F2680[]; // 0x006F2680

void __stdcall sub_M127_EmitSink(int nValue);

extern D2OutdoorColumnFilesStrc gaPresetPairs[]; // 0x006F2680

typedef int BOOL;

#define M303_OFFSET_CHECK(name, type, field, offset) typedef char name[((unsigned int)&((type*)0)->field == (offset)) ? 1 : -1]

M303_OFFSET_CHECK(M303_check_pOutdoors, D2DrlgLevelStrc, pOutdoors, 0x14);

M303_OFFSET_CHECK(M303_check_pLevelCoords, D2DrlgLevelStrc, pLevelCoords, 0x1C);

M303_OFFSET_CHECK(M303_check_pDrlg, D2DrlgLevelStrc, pDrlg, 0x1B4);

M303_OFFSET_CHECK(M303_check_pSeed, D2DrlgLevelStrc, pSeed, 0x1C4);

M303_OFFSET_CHECK(M303_check_nLevelId, D2DrlgLevelStrc, eLevelId, 0x1D0);

M303_OFFSET_CHECK(M303_check_nGridWidth, D2DrlgOutdoorInfoStrc, nGridWidth, 0x5C);

M303_OFFSET_CHECK(M303_check_nGridHeight, D2DrlgOutdoorInfoStrc, nGridHeight, 0x60);

M303_OFFSET_CHECK(M303_check_pVertex, D2DrlgOutdoorInfoStrc, pVertex, 0x64);

M303_OFFSET_CHECK(M303_check_nDirection, D2DrlgVertexStrc, nDirection, 0x08);

M303_OFFSET_CHECK(M303_check_nFlags, D2DrlgVertexStrc, dwFlags, 0x0C);

M303_OFFSET_CHECK(M303_check_pNext, D2DrlgVertexStrc, pNext, 0x10);

M303_OFFSET_CHECK(M303_check_pBounds, D2DrlgOutRectStrc, pBounds, 0x10);

int __fastcall DRLGOUTDOORS_SpawnRandomOutdoorDS1(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand);

void __fastcall DRLGOUTDOORS_SpawnAct1DirtPaths(D2DrlgLevelStrc* pLevel);                                   // 0x00681420

static inline int DRLGOUTDESR_IsRectAdjacent(D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther); // 0x0067FFB0

static void DRLGOUTWILD_SpawnSpecialPresets(D2DrlgLevelStrc* pLevel); // 0x00680580

static inline BOOL DRLGOUTDESR_IsSpecialVertex(D2DrlgVertexStrc* pDrlgVertex); // 0x0067FFF0

static void DRLGOUTDESR_MarkVertexDirections(D2DrlgLevelStrc* pLevel); // 0x00680070

static void DRLGOUTDESR_MarkVertexDirections(D2DrlgLevelStrc* pLevel); // 0x00680070

void __stdcall DRLGOUTWILD_SpawnCottage(int bExtraCottage, int nLvlPrestId, D2DrlgLevelStrc* pLevel); // 0x006804E0

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
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber_Inline(pSeed) % nMax;
    }

    return SEED_RollRandomNumber_Inline(pSeed) & (nMax - 1);
}

// 0x0067F470
static void __stdcall DRLGOUTDESR_PlacePresetVariants(const int* pLevelPrestIds, int nVariants, int bIterateFiles, D2DrlgLevelStrc* pLevel)
{
    int nRand = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, nVariants);
    DATATBLS_GetLvlPrestTxtRecord(pLevelPrestIds[nRand]);

    for (int i = 0; i < nVariants; ++i)
    {
        if (bIterateFiles)
        {
            const int nFiles = DATATBLS_GetLvlPrestTxtRecord(pLevelPrestIds[nRand])->dwFiles;
            for (int nFile = 0; nFile < nFiles; ++nFile)
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, pLevelPrestIds[nRand], nFile, 0, 15);
            }
        }
        else
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, pLevelPrestIds[nRand], -1, 0, 15);
        }

        nRand = (nRand + 1) % nVariants;
    }
}

// 0x0067F560
void __fastcall DRLGOUTDESR_PlaceDesertTransitionToTown(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOrthStrc* pTownRoomData = pLevel->pOutdoors->pRoomData;

    while (pTownRoomData && pTownRoomData->pLevel->eLevelId != LEVEL_LUTGHOLEIN)
    {
        pTownRoomData = pTownRoomData->pNext;
    }

    if (pTownRoomData)
    {
        if (pTownRoomData->nDirection == 3)
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, pLevel->pOutdoors->nGridHeight - 1, 0x16B, -1, 0);
        }
        else
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pLevel->pOutdoors->nGridWidth - 1, 0, 0x16A, -1, 0);
        }
    }
}

// 0x0067F5C0
static void DRLGOUTDESR_PlaceCliffs(D2DrlgLevelStrc* pLevel)
{
    const unsigned int nRand = SEED_RollRandomNumber_Inline(&pLevel->pSeed) & 7;

    const int* pY = &gaDesertCliffs[nRand][0].nY;
    for (int i = 0; i < 5; ++i, pY += 4)
    {
        const D2DrlgOutDesertInitStrc* pEntry = (const D2DrlgOutDesertInitStrc*)(pY - 3);
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pEntry->nX, pEntry->nY, pEntry->nLvlPrestId, pEntry->nRand, 0);
    }
}

// 0x0067F630
static void DRLGOUTDESR_PlaceBorders(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 0x16C);
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 0x16C);
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 0x16C);
}

// 0x0067F670
void __fastcall DRLGOUTDESR_AddExits(D2DrlgLevelStrc* pLevel)
{
    int nLevelPrestId = 0;

    switch (pLevel->eLevelId)
    {
    case 41:
    case 42:
        nLevelPrestId = 0x184;
        break;

    case 43:
        nLevelPrestId = 0x186;
        break;

    case 44:
        nLevelPrestId = 0x19C;
        break;

    case 45:
        nLevelPrestId = 0x185;
        break;
    }

    D2_ASSERT(nLevelPrestId && DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nLevelPrestId, -1, 0, 15), 0xAA);
}

// 0x0067F6F0
static void DRLGOUTDESR_PlaceRockyWasteVariants(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds[] = { 0x18B, 0x19B, 0x191, 0x192, 0x18F, 0x18E, 0x193 };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds, 7, 0, pLevel);
}

// 0x0067F740
static void DRLGOUTDESR_PlaceDryHillsVariants(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[] = { 0x18B, 0x19B, 0x190, 0x18E };
    const int nLevelPrestIds2[] = { 0x194, 0x195, 0x196, 0x197 };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 4, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 4, 1, pLevel);
}

// 0x0067F7A0
static void DRLGOUTDESR_PlaceFarOasisVariants(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds[] = { 0x18C, 0x18D };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds, 2, 0, pLevel);
}

// 0x0067F7D0
static void DRLGOUTDESR_PlaceFillsInFarOasis(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[4] = { 0x19B, 0x18F, 0x18E, 0x193 };
    const int nLevelPrestIds2[1] = { 0x18B };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 4, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
}

// 0x0067F830
static void DRLGOUTDESR_PlaceRuinsInLostCity(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds[4] = { 0x19D, 0x198, 0x199, 0x19A };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds, 4, 0, pLevel);
}

// 0x0067F870
static void DRLGOUTDESR_PlaceFillsInLostCity(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[5] = { 0x18B, 0x190, 0x18E, 0x194, 0x195 };
    const int nLevelPrestIds2[1] = { 0x19B };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 5, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 1, 1, pLevel);
}

// 0x0067F8D0
static void DRLGOUTDESR_PlaceTombEntriesInCanyon(D2DrlgLevelStrc* pLevel)
{
    for (int i = 0; i < 9; ++i)
    {
        const D2DrlgOutDesertInitStrc* pInit = &gaCanyonTombEntries[i];
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pInit->nX, pInit->nY, pInit->nLvlPrestId, pInit->nRand, 0);
    }

    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 4, 4, 0x18A, -1, 0);
}

// 0x0067F920
static void DRLGOUTDESR_PlaceFillsInCanyon(D2DrlgLevelStrc* pLevel)
{
    const int nLevelPrestIds1[5] = { 0x191, 0x192, 0x196, 0x197, 0x193 };
    const int nLevelPrestIds2[2] = { 0x188, 0x189 };
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds1, 5, 0, pLevel);
    DRLGOUTDESR_PlacePresetVariants(nLevelPrestIds2, 2, 1, pLevel);
}

// 0x0067F980
void __fastcall DRLGOUTDESR_InitAct2OutdoorLevel(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    DRLGOUTPLACE_PlaceAct1245OutdoorBorders(pLevel);

    switch (pLevel->eLevelId)
    {
    case LEVEL_ROCKYWASTE:
        DRLGOUTDESR_PlaceDesertTransitionToTown(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceRockyWasteVariants(pLevel);
        break;

    case LEVEL_DRYHILLS:
        DRLGOUTDESR_PlaceCliffs(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceDryHillsVariants(pLevel);
        break;

    case LEVEL_FAROASIS:
        DRLGOUTDESR_PlaceCliffs(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        DRLGOUTDESR_PlaceFarOasisVariants(pLevel);
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceFillsInFarOasis(pLevel);
        break;

    case LEVEL_LOSTCITY:
        DRLGOUTDESR_PlaceCliffs(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_AddExits(pLevel);
        DRLGOUTDESR_PlaceRuinsInLostCity(pLevel);
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceFillsInLostCity(pLevel);
        break;

    case LEVEL_VALLEYOFSNAKES:
        DRLGOUTDESR_AddExits(pLevel);
        break;

    case LEVEL_CANYONOFTHEMAGI:
        DRLGOUTDESR_PlaceTombEntriesInCanyon(pLevel);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        DRLGOUTDESR_PlaceFillsInCanyon(pLevel);
        break;

    case LEVEL_PANDEMONIUMRUN2:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 4, 4, 0x18A, -1, 0);
        DRLGOUTDESR_PlaceBorders(pLevel);
        DRLGOUTDESR_PlaceFillsInCanyon(pLevel);
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
        break;

    default:
        return;
    }
}

// build: symbol ?DRLGOUTWILD_FindBridgeInColumn@@YGXPAUD2DrlgLevelStrc@@HPAH1@Z 0x0067FB90
static void __stdcall DRLGOUTWILD_FindBridgeInColumn(D2DrlgLevelStrc* pLevel, int nX, int* pX, int* pY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int nY = 1; nY < pOutdoors->nGridWidth - 1; ++nY)
    {
        const int nEntry = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY);
        const unsigned int nPacked = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
        const int nPickedFile = (nPacked >> 16) & 0xF;
        if (nEntry == 28 && nPickedFile == 1)
        {
            *pX = nX;
            *pY = nY;
            return;
        }
    }

    *pX = -1;
    *pY = -1;
}

// 0x0067FC20
void __fastcall DRLGOUTWILD_GetBridgeCoords(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    DRLGOUTWILD_FindBridgeInColumn(pLevel, pLevel->pOutdoors->nGridWidth / 2 - 1, pX, pY);
}

// 0x0067FC50
void __fastcall DRLGOUTDESR_FindBridgeInLastColumn(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    DRLGOUTWILD_FindBridgeInColumn(pLevel, pLevel->pOutdoors->nGridWidth - 2, pX, pY);
}

// 0x0067FC70
static int DRLGOUTWILD_TestSpawnRiver(int nX, D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    for (int nY = 0; nY < pOutdoors->nGridHeight; ++nY)
    {
        if (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 2)
        {
            return 0;
        }

        if (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX + 1, nY) & 2)
        {
            return 0;
        }
    }

    return 1;
}

// 0x0067FCD0
static inline int __stdcall DRLGOUTDESR_GetPresetPairValue(int bFirst, int nIndex, unsigned int nFlags)
{
    if (nIndex)
    {
        if (nIndex == 7 && (nFlags & 0xF0000) == 0x30000)
        {
            return nIndex - 4;
        }
        if (bFirst)
        {
            return gaPresetPairs_006F2680[nIndex].nFirst;
        }
        return gaPresetPairs_006F2680[nIndex].nSecond;
    }
    return (nFlags & 0x100) ? 0 : 3;
}

// 0x0067FD20
static void __stdcall DRLGOUTDESR_PlacePair(int nColumn, D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const int bBridge = pOutdoor->dwFlags & 4;
    const int nRowRange = pOutdoor->nGridHeight - 2;
    const int nRand = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, nRowRange);
    for (int i = 0; i < nRowRange; ++i)
    {
        const int nY = (nRand + i) % nRowRange + 1;
        if (bBridge)
        {
            if (!sub_00674200_IsValid(pLevel, nColumn - 1, nY))
                continue;
        }
        else
        {
            if (!sub_00674200_IsValid(pLevel, nColumn - 1, nY))
                continue;
            if (!sub_00674200_IsValid(pLevel, nColumn + 2, nY))
                continue;
        }
        if ((sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn, nY) & 0xF0000) == 0x30000
            && (sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn + 1, nY) & 0xF0000) == 0x30000)
        {
            sub_006743C0_PlacePreset(pLevel, nColumn, nY, 28, 1, 0);
            sub_006743C0_PlacePreset(pLevel, nColumn + 1, nY, 28, bBridge ? 3 : 2, 0);
            return;
        }
    }
}

void __fastcall sub_M127_Emit_0067FCD0(int nValue, D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther, unsigned int nFlags)
{
    sub_M127_EmitSink(DRLGOUTDESR_GetPresetPairValue(nValue & 1, nValue, nFlags));
    for (D2DrlgOutRectStrc* p = pOther; p; p = p->pBounds)
    {
        sub_M127_EmitSink(DRLGOUTDESR_IsRectAdjacent(pRect, p));
    }
}

static inline unsigned __int64 RollSeedInline(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return nSeed;
}

static inline unsigned int RollLimitedInline(D2SeedStrc* pSeed, int nLimit)
{
    if (nLimit <= 0)
        return 0;
    if ((nLimit - 1) & nLimit)
        return (unsigned int)RollSeedInline(pSeed) % nLimit;
    return RollSeedInline(pSeed) & (nLimit - 1);
}

// 0x0067FE90
void __stdcall DRLGOUTDESR_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    for (int nRow = 0; nRow < pOutdoor->nGridHeight; ++nRow)
    {
        int nFlags = sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn, nRow);
        int nType = sub_0067C570_GetGrid(&pOutdoor->pGrid[0], nColumn, nRow);
        int nFile;
        if (nType)
        {
            if (nType == 7 && (nFlags & 0xF0000) == 0x30000)
                nFile = 3;
            else
                nFile = gaPresetPairs[nType].nLeft;
        }
        else
            nFile = (nFlags & 0x100) ? 0 : 3;
        sub_006743C0_PlacePreset(pLevel, nColumn, nRow, 26, nFile, 0);

        nFlags = sub_0067C570_GetGrid(&pOutdoor->pGrid[2], nColumn + 1, nRow);
        nType = sub_0067C570_GetGrid(&pOutdoor->pGrid[0], nColumn + 1, nRow);
        if (nType)
        {
            if (nType == 7 && (nFlags & 0xF0000) == 0x30000)
                nFile = 3;
            else
                nFile = gaPresetPairs[nType].nRight;
        }
        else
            nFile = (nFlags & 0x100) ? 0 : 3;
        sub_006743C0_PlacePreset(pLevel, nColumn + 1, nRow, 27, nFile, 0);
    }
    if (pOutdoor->dwFlags & 0x14)
        DRLGOUTDESR_PlacePair(nColumn, pLevel);
}

// 0x0067FFB0
static inline int DRLGOUTDESR_IsRectAdjacent(D2DrlgOutRectStrc* pRect, D2DrlgOutRectStrc* pOther)
{
    D2DrlgOutRectStrc* pBounds = pRect->pBounds;
    if (pRect->nX < pBounds->nX && pOther->nY > pRect->nY && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    if (pRect->nY > pBounds->nY && pOther->nX > pRect->nX && !(pRect->nFlags & 1) && !(pOther->nFlags & 1))
    {
        return 1;
    }
    return 0;
}

static inline unsigned int SEED_RollRandomNumber_Wild(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0067FFF0
static inline BOOL DRLGOUTDESR_IsSpecialVertex(D2DrlgVertexStrc* pDrlgVertex)
{
    D2DrlgVertexStrc* pNext = pDrlgVertex->pNext;

    if (pDrlgVertex->nPosX < pDrlgVertex->pNext->nPosX && pNext->nPosY < pNext->pNext->nPosY && !(pDrlgVertex->dwFlags & 1) && !(pNext->dwFlags & 1))
    {
        return 1;
    }

    if (pDrlgVertex->nPosY > pDrlgVertex->pNext->nPosY && pNext->nPosX < pNext->pNext->nPosX && !(pDrlgVertex->dwFlags & 1) && !(pNext->dwFlags & 1))
    {
        return 1;
    }

    return 0;
}

// 0x00680040
static inline BOOL DRLGOUTWILD_IsVertexBlocking(D2DrlgVertexStrc* pDrlgVertex)
{
    D2DrlgVertexStrc* pNext = pDrlgVertex->pNext;

    if (pDrlgVertex->nPosY < pNext->nPosY)
    {
        return 1;
    }

    if (pDrlgVertex->nPosX > pNext->nPosX)
    {
        return 1;
    }

    if (pDrlgVertex->dwFlags & 1)
    {
        return 1;
    }

    if (pNext->dwFlags & 1)
    {
        return 1;
    }

    return 0;
}

// 0x00680070
static void DRLGOUTDESR_MarkVertexDirections(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pPreviousVertex = pVertex;
    BOOL bBreak = 0;

    while (pPreviousVertex->pNext != pVertex)
    {
        pPreviousVertex = pPreviousVertex->pNext;
    }

    do
    {
        if (DRLGOUTDESR_IsRectAdjacent((D2DrlgOutRectStrc*)pVertex, (D2DrlgOutRectStrc*)pPreviousVertex))
        {
            D2DrlgVertexStrc* pFirstVertex = pVertex;
            D2DrlgVertexStrc* pSpecialVertex = 0;
            do
            {
                if (pVertex == pOutdoors->pVertex)
                {
                    bBreak = 1;
                }

                if (DRLGOUTWILD_IsVertexBlocking(pVertex))
                {
                    break;
                }

                if (DRLGOUTDESR_IsSpecialVertex(pVertex))
                {
                    pSpecialVertex = pVertex;
                }

                pVertex = pVertex->pNext;
            }
            while (pVertex != pFirstVertex);

            if (pSpecialVertex)
            {
                D2DrlgVertexStrc* pTemp = pFirstVertex;
                for (; pTemp != pSpecialVertex; pTemp = pTemp->pNext)
                {
                    pTemp->nDirection = 1;
                }

                pTemp->nDirection = 1;
                pOutdoors->dwFlags |= 0x20;
            }
        }

        pPreviousVertex = pVertex;
        pVertex = pVertex->pNext;
    }
    while (!bBreak && pVertex != pOutdoors->pVertex);
}

// 0x006801A0
static int __stdcall DRLGOUTWILD_SpawnCliffCaves(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    switch (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY))
    {
    case 16:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, 0x19, -1, 0);
        pOutdoors->dwFlags |= 0x40;
        return 1;

    case 17:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, 0x18, -1, 0);
        pOutdoors->dwFlags |= 0x40;
        return 1;

    default:
        return 0;
    }
}

// 0x006801F0
int __fastcall DRLGOUTDESR_GetCliffPresetId(D2DrlgLevelStrc* pLevel)
{
    return (pLevel->eLevelId == LEVEL_BLOODMOOR) + 0x33;
}

static inline unsigned int SEED_RollRandomNumberHighFirst_Inline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int DRLG_IsBloodmoor_Inline(D2DrlgLevelStrc* pLevel)
{
    if (!pLevel)
    {
        return 0;
    }
    return pLevel->eLevelId == LEVEL_BLOODMOOR;
}

static inline unsigned __int64 SEED_RollRandomNumber64_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x00680200
void __stdcall DRLGOUTDESR_SpawnRiverAndCliffCaves(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_MOOMOOFARM)
    {
        return;
    }

    int nX;
    int nY;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (pOutdoors->dwFlags & 0xC)
    {
        nX = pOutdoors->nGridWidth - 2;
        if (DRLGOUTWILD_TestSpawnRiver(nX, pLevel))
        {
            DRLGOUTDESR_PlaceColumns(pLevel, nX);
        }
    }

    if ((pOutdoors->dwFlags & 0x20) && !(pOutdoors->dwFlags & 0x40))
    {
        int bAdded = 0;
        if (SEED_RollRandomNumberHighFirst_Inline(&pLevel->pSeed) & 1)
        {
            for (nX = 0; nX < pOutdoors->nGridHeight; ++nX)
            {
                if (bAdded)
                {
                    break;
                }

                for (nY = 0; nY < pOutdoors->nGridWidth; ++nY)
                {
                    if (bAdded)
                    {
                        break;
                    }

                    bAdded = DRLGOUTWILD_SpawnCliffCaves(pLevel, nX, nY);
                }
            }
        }
        else
        {
            for (nY = 0; nY < pOutdoors->nGridHeight; ++nY)
            {
                if (bAdded)
                {
                    break;
                }

                for (nX = 0; nX < pOutdoors->nGridWidth; ++nX)
                {
                    if (bAdded)
                    {
                        break;
                    }

                    bAdded = DRLGOUTWILD_SpawnCliffCaves(pLevel, nX, nY);
                }
            }
        }

        D2_ASSERT(bAdded, 0x194);
    }

    if ((pOutdoors->dwFlags & 0x1C) && !(pOutdoors->dwFlags & 0x40))
    {
        int nCornerX = pOutdoors->nGridWidth - ((pOutdoors->dwFlags & 0x10) ? 4 : 5);
        int nCornerY = pOutdoors->nGridHeight - 4;
        const int nRand = (int)(SEED_RollRandomNumber64_Inline(&pLevel->pSeed) & 3);
        if (nRand % 2)
        {
            nCornerX = 3;
        }

        if (nRand / 2)
        {
            nCornerY = 3;
        }
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nCornerX, nCornerY, DRLG_IsBloodmoor_Inline(pLevel) + 0x33, -1, 0);
        pOutdoors->dwFlags |= 0x40;
    }
}

// 0x006803D0
static void DRLGOUTWILD_SpawnTownTransitionsAndCaves(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId == LEVEL_MOOMOOFARM)
    {
        return;
    }

    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (pOutdoors->dwFlags & 0x10)
    {
        const int nX = pOutdoors->nGridWidth / 2 - 1;
        if (DRLGOUTWILD_TestSpawnRiver(nX, pLevel))
        {
            DRLGOUTDESR_PlaceColumns(pLevel, nX);
        }
    }

    if (pOutdoors->dwFlags & 0x80)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 0, 3, 1, 0);
    }

    if (pOutdoors->dwFlags & 0x100)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, pOutdoors->nGridWidth - 7, 0, 3, 2, 0);
    }

    if (pOutdoors->dwFlags & 0x200)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, 1, 2, 1, 0);
    }

    if (pOutdoors->dwFlags & 0x400)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 0, pOutdoors->nGridHeight - 6, 2, 1, 0);
    }

    if (!(pOutdoors->dwFlags & 0x40))
    {
        int fAdded = 0;
        if (pLevel->eLevelId == LEVEL_BLOODMOOR)
        {
            D2DrlgCoordStrc* pCoords = &DRLG_GetLevel(pLevel->pDrlg, LEVEL_ROGUEENCAMPMENT)->pLevelCoords;
            fAdded = DRLGOUTDOORS_SpawnPresetFarAway(pLevel, pCoords, 0x34, -1, 1, 15);
        }
        else
        {
            fAdded = DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x33, -1, 1, 15);
        }

        D2_ASSERT(fAdded, 0x1E5);
        pOutdoors->dwFlags |= 0x40;
    }
}

void __fastcall sub_A14_Emit_006803D0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 4);
    DRLGOUTWILD_SpawnTownTransitionsAndCaves(pLevel);
    DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 4);
}

void __fastcall sub_I19_Emit_0067F8D0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
    DRLGOUTDESR_PlaceTombEntriesInCanyon(pLevel);
    DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
}


static void __stdcall DRLGOUTWILD_SpawnCottage(int bExtraCottage, int nLvlPrestId, D2DrlgLevelStrc* pLevel)
{
    if (SEED_RollRandomNumber_Wild(&pLevel->pSeed) & 3)
    {
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, nLvlPrestId, -1);

        if (bExtraCottage && (SEED_RollRandomNumber_Wild(&pLevel->pSeed) & 1))
        {
            DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, 0x31, -1);
        }
    }
    else
    {
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, nLvlPrestId, -1);
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, nLvlPrestId, -1);
    }
}

static void DRLGOUTWILD_SpawnSpecialPresets(D2DrlgLevelStrc* pLevel)
{
    switch (pLevel->eLevelId)
    {
    case LEVEL_BLOODMOOR:
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, 0x2E, -1);
        DRLGOUTWILD_SpawnCottage(0, 0x2F, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_COLDPLAINS:
        DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x2C, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_STONYFIELD:
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, 0xA0, -1);
        DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, 0x2D, -1);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0xA2, -1, 0, 15);
        DRLGOUTWILD_SpawnCottage(1, 0x2F, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2A, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1F, -1, 0, 15);
        return;

    case LEVEL_DARKWOOD:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0xA1, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x29, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x28, -1, 0, 15);
        DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2B, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_BLACKMARSH:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0xA3, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x26, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x27, -1, 0, 15);
        DRLGOUTWILD_SpawnCottage(1, 0x2F, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2A, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    case LEVEL_TAMOEHIGHLAND:
        DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
        DRLGOUTWILD_SpawnCottage(0, 0x2B, pLevel);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1F, -1, 0, 15);
        return;

    case LEVEL_BURIALGROUNDS:
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, 1, 1, 0x6C, -1, 0);
        return;

    case LEVEL_MOOMOOFARM:
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x32, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x2E, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1F, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x26, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x27, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
        DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1E, -1, 0, 15);
        return;

    default:
        return;
    }
}

void __fastcall DRLGOUTWILD_InitAct1OutdoorLevel(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->eLevelId != LEVEL_BLOODMOOR && pLevel->eLevelId != LEVEL_COLDPLAINS && pLevel->eLevelId != LEVEL_BURIALGROUNDS)
    {
        DRLGOUTDESR_MarkVertexDirections(pLevel);
    }

    DRLGOUTPLACE_SetOutGridLinkFlags(pLevel);
    DRLGOUTPLACE_PlaceAct1245OutdoorBorders(pLevel);

    if (pLevel->eLevelId >= LEVEL_BLOODMOOR && pLevel->eLevelId <= LEVEL_TAMOEHIGHLAND)
    {
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 0, 4);
        DRLGOUTDESR_SpawnRiverAndCliffCaves(pLevel);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 4);
        DRLGOUTWILD_SpawnTownTransitionsAndCaves(pLevel);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 4);
        DRLGOUTDOORS_SpawnAct1DirtPaths(pLevel);
    }

    if (pLevel->eLevelId == LEVEL_MOOMOOFARM)
    {
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 0, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 1, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 2, 4);
        DRLGOUTDOORS_AddAct124SecondaryBorder(pLevel, 3, 4);
    }

    if (pLevel->eLevelId >= LEVEL_COLDPLAINS && pLevel->eLevelId <= LEVEL_BLACKMARSH)
    {
        DRLGOUTDOORS_SpawnAct12Waypoint(pLevel);
    }

    if (pLevel->eLevelId >= LEVEL_BLOODMOOR && pLevel->eLevelId <= LEVEL_TAMOEHIGHLAND)
    {
        DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
    }

    DRLGOUTWILD_SpawnSpecialPresets(pLevel);
}

#include "gen/data/Source/D2Common/DRLG/OutDesr.inc"
