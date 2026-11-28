#include "D2LevelIds.h"

#include "D2DrlgPresets.h"

#include "D2ItemTypes.h"

#include "D2DrlgTiles.h"

#include "D2TxtTables.h"

#include "D2Unicode.h"

#include "D2StateIds.h"

#include "D2SkillIds.h"

#include "D2StatIds.h"

#include "D2DataTbls.h"

#include "D2Records.h"

#include "D2Skills.h"

#include "D2LevelTxt.h"

#include "D2Txt.h"

#include "D2PlayerModes.h"

#include "D2MonModes.h"

#include "D2PathFind.h"

#include "D2Common.h"
#include "D2CommonInternal.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2Drlg.h"

#include "D2DrlgMaps.h"

#include "D2DrlgRooms.h"
#include "D2DrlgOutdoor.h"
#include "D2CommonApi.h"

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

struct D2PoolSystemStrc;
struct D2DrlgOutdoorInfoStrc;

union D2SeedStrc;

struct D2LvlPrestRecordStrc;

struct D2DrlgCoordsStrc;

struct D2DrlgVertexStrc;

struct D2DrlgGridStrc;

struct D2DrlgLevelStrc;

struct D2CoordStrc;

struct D2LvlPrestRecordStrc
{
    int nDef;
    char pad_04[60];
    int nFiles;
};

extern D2LvlPrestRecordStrc* __stdcall sub_0061F0B0(int nPresetId); // 0x0061F0B0

extern void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int nZero); // 0x0040B430

extern int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc* pSeed, int nLimit); // 0x0045C3E0




extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall DRLGOUTDOORS_TestOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nX, int nY, int nLevelPrestId, int nOffset, char nFlags); // 0x00674230



extern "C" const int gdwAct12ShrineFlags[4]; // 0x006F061C


#define FLAG_OPERATION_OR 0

struct D2DrlgStrc;

#define BORDER 2

#define CELL_OFFSET 1

#define TEST_FLAGS 15

int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags); // 0x00674730

extern const signed char gnRandomOutdoorDs1OffsetX[8];  // 0x006F0614

extern const signed char gnRandomOutdoorDs1OffsetY[8];  // 0x006F060C

struct Point { int x, y; };

struct D2DrlgMapStrc;

struct D2DrlgOrthStrc;

struct D2DrlgCoordStrc;

int __fastcall DRLGPRESET_SetPickedFileInDrlgMap(D2DrlgMapStrc* pDrlgMap, int nPickedFile); // 0x00666EC0


static void DRLGOUTDOORS_SpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel);




void __fastcall DRLGOUTDOORS_InitAct4OutdoorLevel(D2DrlgLevelStrc* pLevel); // 0x0067E890

void __fastcall DRLGOUTPLACE_InitAct3OutdoorLevel(D2DrlgLevelStrc* pLevel); // 0x0067F450

void __fastcall DRLGOUTWILD_InitAct1OutdoorLevel(D2DrlgLevelStrc* pLevel); // 0x006807F0

static void DRLGOUTDOORS_ScaleAndMergeVertices(D2PoolSystemStrc* pMemPool, D2DrlgVertexStrc** ppVertex);


// 0x00674320
static int __cdecl DRLGOUTDOORS_PickNextPresetFile(D2DrlgLevelStrc* pLevel, int nPresetId)
{
    D2PoolSystemStrc* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgBuildStrc* pFile = pLevel->pBuild;
    while (pFile)
    {
        if (pFile->nPreset == nPresetId)
            break;
        pFile = pFile->pNext;
    }
    if (!pFile)
    {
        D2LvlPrestRecordStrc* pRecord = sub_0061F0B0(nPresetId);
        pFile = (D2DrlgBuildStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgBuildStrc), ".\\DRLG\\Outdoors.cpp", 249, 0);
        memset(pFile, 0, sizeof(D2DrlgBuildStrc));
        pFile->nPreset = pRecord->nDef;
        pFile->nDivisor = pRecord->nFiles;
        pFile->nRand = sub_0045C3E0_RollLimited(&pLevel->pSeed, pRecord->nFiles);
        pFile->pNext = pLevel->pBuild;
        pLevel->pBuild = pFile;
    }
    pFile->nRand = (pFile->nRand + 1) % pFile->nDivisor;
    return pFile->nRand;
}

// 0x006743C0
void __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(D2DrlgLevelStrc* pLevel, int nX, int nY, int nPresetId, int nPickedFile, int bFlag)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const int nWidth = DRLGPRESET_GetSizeX(nPresetId) / 8;
    const int nHeight = DRLGPRESET_GetSizeY(nPresetId) / 8;
    if (nPickedFile == -1)
        nPickedFile = DRLGOUTDOORS_PickNextPresetFile(pLevel, nPresetId);
    for (int y = nY; y < nY + nHeight; ++y)
    {
        for (int x = nX; x < nX + nWidth; ++x)
        {
            DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], x, y, 983040, 5);
            DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], x, y, (nPickedFile << 16) | 512, 0);
            if (bFlag && ((nPresetId >= 4 && nPresetId <= 15) || (unsigned int)(nPresetId - 364) <= 11))
                DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[2], x, y, 1, 0);
            DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[0], x, y, 0, 3);
        }
    }
    DRLGGRID_AlterGridFlag(&pOutdoor->pGrid[0], nX, nY, nPresetId, 3);
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
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
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x006744F0
int __fastcall DRLGOUTDOORS_SpawnPresetFarAway(D2DrlgLevelStrc* pLevel, D2DrlgCoordStrc* pCoords, int nLevelPrestId, int nPickedFile, int nOffset, int nFlags)
{
    D2DrlgOutdoorInfoStrc* pOutdoor = pLevel->pOutdoors;
    const int nPosX = pLevel->nPosX;
    const int nPosY = pLevel->nPosY;
    const int nWidth = pOutdoor->nGridWidth - 2;
    const int nHeight = pOutdoor->nGridHeight - 2;
    const int nOffsetX = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nWidth);
    const int nOffsetY = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nHeight);
    int nBestDistance = 0;
    const int nCenterX = pCoords->nWidth / 2 + pCoords->nPosX;
    const int nCenterY = pCoords->nHeight / 2 + pCoords->nPosY;
    int nBestX = -1;
    int nBestY = -1;

    for (int j = 0; j <= nHeight; ++j)
    {
        for (int i = 0; i <= nWidth; ++i)
        {
            const int nY = (j + nOffsetY) % nHeight + 1;
            const int nX = (i + nOffsetX) % nWidth + 1;
            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nLevelPrestId, nOffset, nFlags))
            {
                const int nDeltaX = 8 * nX - nCenterX + nPosX + 4;
                const int nDiffX = D2_ABS(nDeltaX);
                const int nDeltaY = 8 * nY - nCenterY + nPosY + 4;
                const int nDiffY = D2_ABS(nDeltaY);
                const int nDistance = (nDiffX > nDiffY ? nDiffY + 2 * nDiffX : nDiffX + 2 * nDiffY) / 2;
                if (nBestDistance < nDistance)
                {
                    nBestDistance = nDistance;
                    nBestX = nX;
                    nBestY = nY;
                }
            }
        }
    }

    if (nBestX != -1 && nBestY != -1)
    {
        DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nBestX, nBestY, nLevelPrestId, nPickedFile, 0);
        return 1;
    }

    return 0;
}

// 0x00674730
int __fastcall DRLGOUTDOORS_SpawnOutdoorLevelPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId, int nRand, int nOffset, char nFlags)
{
    D2CoordStrc pCoord[256];

    const int nWidth = pLevel->pOutdoors->nGridWidth - 2;
    const int nArea = nWidth * (pLevel->pOutdoors->nGridHeight - 2);

    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const unsigned int nRand1 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);
            const unsigned int nRand2 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);

            const D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nX = pCoord[i].nX + 1;
            const int nY = pCoord[i].nY + 1;

            if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, nX, nY, nLevelPrestId, nOffset, nFlags))
            {
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, nLevelPrestId, nRand, 0);
                return 1;
            }
        }
    }

    return 0;
}

static inline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x00674920
int __fastcall DRLGOUTDOORS_SpawnRandomOutdoorDS1(D2DrlgLevelStrc* pLevel, int nLvlPrestId, int nRand)
{
    sub_0061F0B0(nLvlPrestId);
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    const int width = pOutdoors->nGridWidth - BORDER;
    const int count = width * (pOutdoors->nGridHeight - BORDER);
    if (!count) return 0;
    Point cells[256];
    for (int i = 0; i < count; ++i)
    {
        cells[i].x = i % width;
        cells[i].y = i / width;
    }
    for (int i = 0; i < count; ++i)
    {
        const int first = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, count);
        const int second = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, count);
        Point temp = cells[first];
        cells[first] = cells[second];
        cells[second] = temp;
    }
    for (int i = 0; i < count; ++i)
    {
        const int x = cells[i].x + CELL_OFFSET;
        const int y = cells[i].y + CELL_OFFSET;
        if (DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], x, y) & 0x80)
        {
            for (int j = 0; j < 8; ++j)
            {
                const int tx = x + gnRandomOutdoorDs1OffsetX[j];
                const int ty = y + gnRandomOutdoorDs1OffsetY[j];
                if (DRLGOUTDOORS_TestOutdoorLevelPreset(pLevel, tx, ty, nLvlPrestId, 0, TEST_FLAGS))
                {
                    DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, tx, ty, nLvlPrestId, nRand, 0);
                    return 1;
                }
            }
        }
    }
    return DRLGOUTDOORS_SpawnOutdoorLevelPreset(pLevel, nLvlPrestId, nRand, 0, TEST_FLAGS);
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

// 0x00674B70
void __fastcall DRLGOUTDOORS_SpawnAct12Waypoint(D2DrlgLevelStrc* pLevel)
{
    D2CoordStrc pCoord[256];
    const int nLevelId = pLevel->eLevelId;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    if (nLevelId == LEVEL_COLDPLAINS)
    {
        int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, nLevelId);
        int k;
        for (k = 0; k < 8; ++k)
        {
            if (pVisArray[k] == LEVEL_BLOODMOOR)
                break;
        }
        int nFlags = 1 << (k + 4);
        int nW = pOutdoors->nGridWidth;
        int nH = pOutdoors->nGridHeight;
        for (int i = 0; i < nH; ++i)
        {
            for (int j = 0; j < nW; ++j)
            {
                int a = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[1], j, i);
                int b = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], j, i);
                if ((a & nFlags) && (b & 0x400))
                {
                    if (!j) j = 1;
                    if (!i) i = 1;
                    if (j == nW - 1) --j;
                    if (i == nH - 1) --i;
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[1], j, i, 0x20000, FLAG_OPERATION_OR);
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], j, i, 0x800, FLAG_OPERATION_OR);
                    return;
                }
            }
        }
    }
    int nWidth = pOutdoors->nGridWidth - 2;
    int nArea = nWidth * (pOutdoors->nGridHeight - 2);
    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }
        for (int i = 0; i < nArea; ++i)
        {
            int nRand1 = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, nArea);
            int nRand2 = SEED_RollLimitedRandomNumber_Inline(&pLevel->pSeed, nArea);
            D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }
        for (int i = 0; i < nArea; ++i)
        {
            int nX = pCoord[i].nX + 1;
            int nY = pCoord[i].nY + 1;
            if (!(DRLGGRID_GetGridEntry(&pLevel->pOutdoors->pGrid[2], nX, nY) & 0x1B81))
            {
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[1], nX, nY, 0x10000, FLAG_OPERATION_OR);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x800, FLAG_OPERATION_OR);
                break;
            }
        }
    }
}

static int __fastcall DRLGOUTDOORS_TestGridCellSpawnValid(D2DrlgLevelStrc* pLevel, int nX, int nY)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    return !(DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY) & 0x1B81);
}

// 0x00674E40
void __fastcall DRLGOUTDOORS_SpawnAct12Shrines(D2DrlgLevelStrc* pLevel, int nShrines)
{
    D2CoordStrc pCoord[256];

    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nIndex = SEED_RollRandomNumber(&pLevel->pSeed) & 3;
    const int nWidth = pOutdoors->nGridWidth - 2;
    const int nArea = nWidth * (pOutdoors->nGridHeight - 2);

    if (nArea)
    {
        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const unsigned int nRand1 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);
            const unsigned int nRand2 = SEED_RollLimitedRandomNumber(&pLevel->pSeed, nArea);

            const D2CoordStrc tCoord = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tCoord;
        }

        for (int i = 0; i < nArea; ++i)
        {
            if (nShrines <= 0)
            {
                break;
            }

            const int nX = pCoord[i].nX + 1;
            const int nY = pCoord[i].nY + 1;

            if (DRLGOUTDOORS_TestGridCellSpawnValid(pLevel, nX, nY))
            {
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[1], nX, nY, gdwAct12ShrineFlags[nIndex], 0);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x1000, 0);
                nIndex = (nIndex + 1) % 4;
                --nShrines;
            }
        }
    }
}

// 0x00675080
static void DRLGOUTDOORS_ScaleAndMergeVertices(D2PoolSystemStrc* pMemPool, D2DrlgVertexStrc** ppVertex)
{
    D2DrlgVertexStrc* pVertex = *ppVertex;
    do
    {
        pVertex->nPosX /= 8;
        pVertex->nPosY /= 8;
        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);

    do
    {
        D2DrlgVertexStrc* pNextVertex = pVertex->pNext;

        if (pVertex->nPosX == pNextVertex->nPosX && pVertex->nPosY == pNextVertex->nPosY)
        {
            if (pNextVertex == *ppVertex)
            {
                *ppVertex = pVertex;
            }

            pVertex->pNext = pNextVertex->pNext;
            pVertex->dwFlags |= pNextVertex->dwFlags;
            pVertex->nDirection = pNextVertex->nDirection;
            FOG_FreeServerMemory(pMemPool, pNextVertex, ".\\DRLG\\Outdoors.cpp", 715, 0);
        }

        pVertex = pVertex->pNext;
    }
    while (pVertex != *ppVertex);
}

// 0x006750F0
static void DRLGOUTDOORS_SpawnPresetsAndRooms(D2DrlgLevelStrc* pLevel)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    int nLevelFlags = 0;
    switch (pLevel->nLevelType)
    {
    case 2:
        nLevelFlags = 0x44103;
        break;
    case 16:
        nLevelFlags = 1;
        break;
    case 21:
        nLevelFlags = 4;
        break;
    case 22:
        nLevelFlags = 1;
        break;
    case 27:
        nLevelFlags = 1;
        break;
    case 28:
        nLevelFlags = 1;
        break;
    case 30:
        nLevelFlags = 0x11;
        break;
    case 31:
        nLevelFlags = 0x11;
        break;
    }

    int nPosY = pLevel->pLevelCoords.nPosY;
    for (int nY = 0; nY < pOutdoors->nGridHeight; ++nY)
    {
        int nPosX = pLevel->pLevelCoords.nPosX;
        for (int nX = 0; nX < pOutdoors->nGridWidth; ++nX)
        {
            const int nRoomFlags = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[1], nX, nY);
            const unsigned int dwCellFlags = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[2], nX, nY);
            if (dwCellFlags & 0x200)
            {
                const int nLvlPrestId = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[0], nX, nY);
                if (nLvlPrestId)
                {
                    D2DrlgCoordStrc tDrlgCoord;
                    tDrlgCoord.nPosX = nPosX;
                    tDrlgCoord.nPosY = nPosY;
                    tDrlgCoord.nWidth = 0;
                    tDrlgCoord.nHeight = 0;
                    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, nLvlPrestId, &tDrlgCoord, &pLevel->pSeed);
                    DRLGPRESET_SetPickedFileInDrlgMap(pDrlgMap, (dwCellFlags >> 16) & 0xF);
                    DRLGPRESET_BuildArea(pLevel, pDrlgMap, nRoomFlags, 0);
                }
            }
            else if (!(dwCellFlags & 0x100))
            {
                const int nOutdoorEntry = DRLGGRID_GetGridEntry(&pOutdoors->pGrid[3], nX, nY);
                DRLGOUTPLACE_CreateOutdoorRoomEx(pLevel, nPosX, nPosY, 8, 8, nRoomFlags, dwCellFlags, nOutdoorEntry, nLevelFlags);
            }

            nPosX += 8;
        }

        nPosY += 8;
    }
}

// 0x00675290
int __fastcall DRLGOUTDOORS_GetRoadEntry(D2DrlgLevelStrc* pLevel, int nIndex)
{
    return (int)pLevel->pOutdoors->pRoads[nIndex];
}

void __fastcall DRLGTILESUB_ApplySubstitutionBorder(D2UnkOutdoorStrc* pOutdoor); // 0x00670750

void __fastcall DRLGOUTDOORS_AlterAdjacentPresetGridCells(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00674160

void __fastcall DRLGOUTDOORS_SetBlankGridCell(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x006741A0


// 0x006752A0
void __fastcall DRLGOUTDOORS_AddAct124SecondaryBorder(D2DrlgLevelStrc* pLevel, int nLvlSubId, int nLevelPrestId)
{
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2UnkOutdoorStrc tOutdoorInfo = {};

    tOutdoorInfo.pLevel = pLevel;
    tOutdoorInfo.field_4 = &pOutdoors->nWidth;
    tOutdoorInfo.pGrid1 = &pOutdoors->pGrid[0];
    tOutdoorInfo.pGrid2 = &pOutdoors->pGrid[2];
    tOutdoorInfo.nLevelPrestId = nLevelPrestId;
    tOutdoorInfo.field_14 = -1;
    tOutdoorInfo.nLvlSubId = nLvlSubId;
    tOutdoorInfo.field_1C = DRLGOUTDOORS_TestGridCellNonLvlLink;
    tOutdoorInfo.field_20 = DRLGOUTDOORS_TestOutdoorLevelPreset;
    tOutdoorInfo.field_2C = DRLGOUTDOORS_AlterAdjacentPresetGridCells;
    tOutdoorInfo.field_30 = DRLGOUTDOORS_SetBlankGridCell;
    tOutdoorInfo.field_34 = DRLGOUTDOORS_SpawnOutdoorLevelPresetEx;

    DRLGTILESUB_ApplySubstitutionBorder(&tOutdoorInfo);
}

// 0x00675320
void __fastcall DRLGOUTDOORS_AllocOutdoorInfo(D2DrlgLevelStrc* pLevel)
{
    pLevel->pOutdoors = (D2DrlgOutdoorInfoStrc*)FOG_AllocPool(pLevel->pDrlg->pMempool, 0x268, ".\\DRLG\\Outdoors.cpp", 0x34C, 0);
    memset(pLevel->pOutdoors, 0, 0x268);
}

// 0x00675360
void __fastcall DRLGOUTDOORS_GenerateLevel(D2DrlgLevelStrc* pLevel)
{
    D2PoolSystemStrc* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;

    pOutdoors->nWidth = 0;
    pOutdoors->nRoomData = 0;
    pOutdoors->nGridWidth = pLevel->pLevelCoords.nWidth / 8;
    pOutdoors->nGridHeight = pLevel->pLevelCoords.nHeight / 8;

    const int nGridWidth = pOutdoors->nGridWidth;
    const int nGridHeight = pOutdoors->nGridHeight;
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[0], nGridWidth, nGridHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[1], nGridWidth, nGridHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[2], nGridWidth, nGridHeight);
    DRLGGRID_InitializeGridCells(pMemPool, &pOutdoors->pGrid[3], nGridWidth, nGridHeight);

    unsigned char nAct = DRLG_GetActNoFromLevelId(pLevel->eLevelId);

    DRLGVER_CreateVertices(pMemPool, &pOutdoors->pVertex, &pLevel->pLevelCoords, 0, pOutdoors->pRoomData);
    DRLGOUTDOORS_ScaleAndMergeVertices(pMemPool, (D2DrlgVertexStrc**)&pOutdoors->pVertex);

    if (pLevel->eLevelId == LEVEL_PANDEMONIUMRUN2)
    {
        nAct = 1;
    }

    switch (nAct)
    {
    case 0:
        DRLGOUTWILD_InitAct1OutdoorLevel(pLevel);
        break;
    case 1:
        DRLGOUTDESR_InitAct2OutdoorLevel(pLevel);
        break;
    case 2:
        DRLGOUTPLACE_InitAct3OutdoorLevel(pLevel);
        break;
    case 3:
        DRLGOUTDOORS_InitAct4OutdoorLevel(pLevel);
        break;
    case 4:
        DRLGOUTSIEGE_InitAct5OutdoorLevel(pLevel);
        break;
    }

    DRLGOUTDOORS_SpawnPresetsAndRooms(pLevel);
}

// 0x006754C0
void __fastcall DRLGOUTDOORS_FreeOutdoorInfo(D2DrlgLevelStrc* pLevel, int bKeepRoomData)
{
    D2PoolSystemStrc* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;

    if (pOutdoors->dwFlags & 0x20)
    {
        pOutdoors->dwFlags ^= 0x20;
    }

    if (pOutdoors->dwFlags & 0x40)
    {
        pOutdoors->dwFlags ^= 0x40;
    }

    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[0]);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[1]);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[2]);
    DRLGGRID_FreeGrid(pMemPool, &pOutdoors->pGrid[3]);

    DRLGVER_FreeVertices(pMemPool, &pOutdoors->pVertex);

    for (int i = 0; i < 6; ++i)
    {
        DRLGVER_FreeVertices(pMemPool, &pOutdoors->pRoads[i]);
    }

    memset(&pOutdoors->pVertices[0], 0, 0x78);
    memset(&pOutdoors->pVertices[6], 0, 0x78);
    memset(&pOutdoors->pVertices[12], 0, 0x78);
    memset(&pOutdoors->pVertices[18], 0, 0x78);

    pOutdoors->nVertices = 0;

    if (!bKeepRoomData)
    {
        DRLGROOM_FreeRoomData(pMemPool, pOutdoors->pRoomData);
        FOG_FreeServerMemory(pMemPool, pLevel->pOutdoors, ".\\DRLG\\Outdoors.cpp", 940, 0);
        pLevel->pOutdoors = 0;
    }
}

// 0x006755C0
int __fastcall DRLGOUTDOORS_GetBorderLevelPrestId(int nA, int nB, int nC)
{
    const int nRow = gaBorderIndices[nA + 3 * nB];
    if (nC >= 4)
    {
        return gaBarricadeCliffBorderIds[nRow][nC - 4];
    }
    return gaBorderLevelPrestIds[nRow][nC];
}

// 0x00675600
int __fastcall DRLGOUTDOORS_GetCornerPresetId(int nA, int nB, int nC, int nD, int nE)
{
    if (nA < 0)
    {
        nA -= 2;
    }
    else if (nA > 0)
    {
        nA += 2;
    }

    if (nC < 0)
    {
        nC -= 2;
    }
    else if (nC > 0)
    {
        nC += 2;
    }

    const int nRow = gaBorderIndicesByDelta[nA + 9 * (nC + nD) + nB];
    if (nRow == -1)
    {
        return 0;
    }

    if (nE >= 4)
    {
        return gaBarricadeCliffBorderIds[nRow - 1][nE - 4];
    }

    return gaBorderLevelPrestIds[nRow - 1][nE];
}

// 0x006757E0
int __fastcall DRLGOUTDOORS_GetBorderLookupId(D2DrlgLevelStrc* pLevel, bool bFlag)
{
    switch (pLevel->nLevelType)
    {
    case 2:
        return !bFlag;
    case 16:
        return 2;
    case 27:
        return 3;
    case 31:
        return DRLGOUTSIEGE_GetBorderLookupId(pLevel);
    }
    return -1;
}

extern int gaDesertBorderIds[][2]; // 0x006F112C

void __fastcall DRLGOUTPLACE_SetBlankBorderGridCells(D2DrlgLevelStrc* pLevel); // 0x00675670

// 0x00675850
void __fastcall DRLGOUTPLACE_PlaceAct1245OutdoorBorders(D2DrlgLevelStrc* pLevel)
{
    int nCurrentDiffX;
    int nCurrentDiffY;
    int nNextDiffX;
    int nNextDiffY;
    int nCurrentDiffXAbs;
    int nCurrentDiffYAbs;
    int nCurrentX;
    int nCurrentY;
    int nNextX;
    int nNextY;
    int nDelta;
    int nDiff;
    int nX;
    int nY;
    int nIndex;
    int nLevelPrestId;
    int nStyle;
    int nPacked;
    unsigned char nDirection;

    unsigned char nAct = DRLG_GetActNoFromLevelId(pLevel->eLevelId);
    D2DrlgOutdoorInfoStrc* pOutdoors = pLevel->pOutdoors;
    D2DrlgVertexStrc* pVertex = pOutdoors->pVertex;
    D2DrlgVertexStrc* pNext = pVertex->pNext;

    do
    {
        DRLGVER_GetCoordDiff(pVertex, &nCurrentDiffX, &nCurrentDiffY);
        DRLGVER_GetCoordDiff(pNext, &nNextDiffX, &nNextDiffY);

        if (nCurrentDiffX >= 0)
        {
            nCurrentDiffXAbs = nCurrentDiffX;
        }
        else
        {
            nCurrentDiffXAbs = -nCurrentDiffX;
        }

        if (nCurrentDiffY < 0)
        {
            nCurrentDiffYAbs = -nCurrentDiffY;
        }
        else
        {
            nCurrentDiffYAbs = nCurrentDiffY;
        }

        nCurrentX = pVertex->nPosX;
        nCurrentY = pVertex->nPosY;
        nNextX = pNext->nPosX;
        nNextY = pNext->nPosY;
        if (nCurrentDiffXAbs)
        {
            nDelta = nCurrentX - nNextX;
            if (nDelta < 0)
            {
                nDiff = -nDelta;
            }
            else
            {
                nDiff = nDelta;
            }
        }
        else
        {
            nDelta = nCurrentY - nNextY;
            if (nDelta < 0)
            {
                nDiff = -nDelta;
            }
            else
            {
                nDiff = nDelta;
            }
        }

        nDirection = pVertex->nDirection;
        nPacked = nDirection != 0 ? 3 : 1;

        nLevelPrestId = DRLGOUTDOORS_GetBorderLevelPrestId(nCurrentDiffX, nCurrentDiffY, DRLGOUTDOORS_GetBorderLookupId(pLevel, nDirection != 0));

        if (!(pVertex->dwFlags & 2))
        {
            while (nCurrentX != nNextX || nCurrentY != nNextY)
            {
                nCurrentX += nCurrentDiffX;
                nCurrentY += nCurrentDiffY;
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nCurrentX, nCurrentY, nLevelPrestId, -1, 0);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nCurrentX, nCurrentY, nPacked, 0);
            }
        }

        if (pVertex->dwFlags & 1 && !(pVertex->dwFlags & 2))
        {
            switch (nAct)
            {
            case 0:
            case 4:
                nX = (pVertex->nPosX < pNext->nPosX ? pVertex->nPosX : pNext->nPosX) + nCurrentDiffXAbs * nDiff / 2;

                nY = (pVertex->nPosY < pNext->nPosY ? pVertex->nPosY : pNext->nPosY) + nCurrentDiffYAbs * nDiff / 2;

                if (pLevel->eLevelId == LEVEL_BURIALGROUNDS)
                {
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0xF0000, 5);
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x40400, 0);
                }
                else
                {
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0xF0000, 5);
                    DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x30400, 0);
                }
                break;

            case 3:
                nX = (pVertex->nPosX < pNext->nPosX ? pVertex->nPosX : pNext->nPosX) + nCurrentDiffXAbs * nDiff / 2;

                nY = (pVertex->nPosY < pNext->nPosY ? pVertex->nPosY : pNext->nPosY) + nCurrentDiffYAbs * nDiff / 2;

                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0xF0000, 5);
                DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nX, nY, 0x30400, 0);
                break;

            case 1:
                nX = (pVertex->nPosX < pNext->nPosX ? pVertex->nPosX : pNext->nPosX) + nCurrentDiffXAbs * nDiff / 2;

                nY = (pVertex->nPosY < pNext->nPosY ? pVertex->nPosY : pNext->nPosY) + nCurrentDiffYAbs * nDiff / 2;

                nIndex = nCurrentDiffX + 2 * nCurrentDiffY + 2;
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX, nY, gaDesertBorderIds[nIndex][0], -1, 0);
                DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nX + nCurrentDiffXAbs, nY + nCurrentDiffYAbs, gaDesertBorderIds[nIndex][1], -1, 0);
                break;
            }
        }

        if (nDirection || (nDirection = pNext->nDirection) != 0)
        {
            nPacked |= 2;
        }

        nStyle = DRLGOUTDOORS_GetBorderLookupId(pLevel, nDirection != 0);

        if (pVertex->dwFlags & 2)
        {
            if (pNext->dwFlags & 2)
            {
                nLevelPrestId = DRLGOUTDOORS_GetCornerPresetId(nCurrentDiffX, nCurrentDiffY, nNextDiffX, nNextDiffY, nStyle);
            }
            else
            {
                nLevelPrestId = DRLGOUTDOORS_GetCornerPresetId(nCurrentDiffX, nCurrentDiffY, 2 * nNextDiffX, 2 * nNextDiffY, nStyle);
            }
        }
        else
        {
            if (pNext->dwFlags & 2)
            {
                nLevelPrestId = DRLGOUTDOORS_GetCornerPresetId(2 * nCurrentDiffX, 2 * nCurrentDiffY, nNextDiffX, nNextDiffY, nStyle);
            }
            else
            {
                nLevelPrestId = DRLGOUTDOORS_GetCornerPresetId(2 * nCurrentDiffX, 2 * nCurrentDiffY, 2 * nNextDiffX, 2 * nNextDiffY, nStyle);
            }
        }

        if (nLevelPrestId == 19)
        {
            if (pVertex->nDirection == 1)
            {
                if (pNext->nDirection != 1)
                {
                    nLevelPrestId = 20;
                }
                else
                {
                    nLevelPrestId = 19;
                }
            }
            else
            {
                nLevelPrestId = 21;
            }
        }

        if (nLevelPrestId != 0)
        {
            DRLGOUTDOORS_SpawnOutdoorLevelPresetEx(pLevel, nNextX, nNextY, nLevelPrestId, -1, 0);
            DRLGGRID_AlterGridFlag(&pOutdoors->pGrid[2], nNextX, nNextY, nPacked, 0);
        }

        pVertex = pNext;
        pNext = pNext->pNext;
    }
    while (pVertex != pOutdoors->pVertex);

    DRLGOUTPLACE_SetBlankBorderGridCells(pLevel);
}

#pragma pack(push, 1)
struct d2data_007499A8_t
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

#pragma pack(push, 1)
struct d2data_006F061C_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

extern "C" struct d2data_007499A8_t gData_007499A8; // 0x007499A8
extern "C" const struct d2data_006F061C_t gData_006F061C; // 0x006F061C

extern "C" struct d2data_007499A8_t gData_007499A8 = {
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
}; // 0x007499A8

extern const signed char gnRandomOutdoorDs1OffsetY[8] = { 0, -1, 1, 0, -1, 1, -1, 1 }; // 0x006F060C

extern const signed char gnRandomOutdoorDs1OffsetX[8] = { -1, 0, 0, 1, -1, 1, 1, -1 }; // 0x006F0614

extern "C" const struct d2data_006F061C_t gData_006F061C = {
    { 0x00, 0x10 }
}; // 0x006F061C
#pragma comment(linker, "/alternatename:_gdwAct12ShrineFlags=_gData_006F061C")
