#include "D2LevelIds.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgRooms.h"

typedef int BOOL;

struct D2DrlgStrc;


void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nPickedFile, int a6); // 0x006743C0


int __fastcall DRLGOUTDOORS_SpawnRandomOutdoorDS1(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand);

void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel);                                   // 0x00674B70

void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines);                      // 0x00674E40

void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId); // 0x006752A0

void __fastcall DRLGOUTPLACE_SetOutGridLinkFlags(D2DrlgLevelStrc* pLevel);                                  // 0x00675770

void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel);                           // 0x00675850

void __fastcall DRLGOUTDOORS_SpawnAct1DirtPaths(D2DrlgLevelStrc* pLevel);                                   // 0x00681420

void __stdcall DRLGOUTDESR_SpawnRiverAndCliffCaves(D2DrlgLevelStrc* pLevel); // 0x00680200

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);

int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordStrc* pCoords, int nLevelPrestId, int nPickedFile, int a5, int a6);

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);

void __stdcall DRLGOUTDESR_PlaceColumns(D2DrlgLevelStrc* pLevel, int nColumn); // 0x0067FE90

extern "C" const char gszEmptyAssertText;

extern "C" const char* __cdecl sub_00408090();

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730

int __fastcall DRLGOUTDOORS_SpawnRandomOutdoorDS1(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand);       // 0x00674920


static inline unsigned int SEED_RollRandomNumber_Wild(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

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

// build: symbol ?DRLGOUTDESR_IsRectAdjacent@* 0x0067FFB0
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

// build: symbol ?DRLGOUTDESR_IsSpecialVertex@* 0x0067FFF0
static inline BOOL DRLGOUTDESR_IsSpecialVertex(D2DrlgVertexStrc* pDrlgVertex)
{
    D2DrlgVertexStrc* pNext = pDrlgVertex->pNext;

    if (pDrlgVertex->nPosX >= pNext->nPosX || pNext->nPosY >= pNext->pNext->nPosY || pDrlgVertex->dwFlags & 1 || pNext->dwFlags & 1)
    {
        if (pDrlgVertex->nPosY <= pNext->nPosY || pNext->nPosX >= pNext->pNext->nPosX || pDrlgVertex->dwFlags & 1 || pNext->dwFlags & 1)
        {
            return 0;
        }
    }

    return 1;
}

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

    return (unsigned char)pNext->dwFlags & 1;
}

// 0x006804E0
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

void __fastcall sub_M90_Emit_006804E0(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_SpawnRandomOutdoorDS1(pLevel, 0x2E, -1);
    DRLGOUTWILD_SpawnCottage(0, 0x2F, pLevel);
    DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x1D, -1, 0, 15);
    DRLGOUTWILD_SpawnCottage(1, 0x30, pLevel);
}

// 0x00680580
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

// build: symbol ?DRLGOUTDESR_MarkVertexDirections@* 0x00680070
static void DRLGOUTDESR_MarkVertexDirections(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pPreviousVertex = pVertex;
    BOOL bBreak = 0;

    for (D2DrlgVertexStrc* i = pVertex->pNext; i != pVertex; i = i->pNext)
    {
        pPreviousVertex = i;
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

static void DRLGOUTWILD_SpawnTownTransitionsAndCaves(D2DrlgLevelStrc* pLevel); // 0x006803D0

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
        int bAdded = 0;
        if (pLevel->eLevelId == LEVEL_BLOODMOOR)
        {
            D2DrlgCoordStrc* pCoords = &DRLG_GetLevel(pLevel->pDrlg, LEVEL_ROGUEENCAMPMENT)->pLevelCoords;
            bAdded = DRLGOUTDOORS_SpawnPresetFarAway(pLevel, pCoords, 0x34, -1, 1, 15);
        }
        else
        {
            bAdded = DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, 0x33, -1, 1, 15);
        }

        D2_ASSERT(bAdded, 0x1E5);
        pOutdoors->dwFlags |= 0x40;
    }
}

static void __stdcall DRLGOUTWILD_SpawnCottage(int bExtraCottage, int nLvlPrestId, D2DrlgLevelStrc* pLevel);

static void DRLGOUTWILD_SpawnSpecialPresets(D2DrlgLevelStrc* pLevel); // 0x00680580

static void DRLGOUTWILD_SpawnSpecialPresets(D2DrlgLevelStrc* pLevel);

// 0x006807F0
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

void __fastcall sub_C07_Emit_00680580(D2DrlgLevelStrc* pLevel)
{
    DRLGOUTDOORS_SpawnAct12Shrines(pLevel, 5);
    DRLGOUTWILD_SpawnSpecialPresets(pLevel);
}

#include "gen/data/Source/D2Common/DRLG/OutWild.inc"
