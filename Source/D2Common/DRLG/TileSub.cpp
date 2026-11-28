#include "D2LevelIds.h"
#include "D2ItemsWorld.h"
#include "D2Common.h"
#include "D2CommonInternal.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2DrlgTiles.h"
#include "D2DrlgRooms.h"
#include "D2Path.h"
#include "D2TxtTables.h"
#include "D2DrlgTileFlags.h"
#include "D2DrlgOutdoor.h"
#include "FogApi.h"
#include "FogApi2.h"
#include "D2CMPApi.h"

#pragma function(memset)

struct D2PoolSystemStrc;
struct D2DrlgTileDataStrc;

union D2SeedStrc;

union D2C_PackedTileInformation;

struct D2DrlgRoomTilesStrc;

struct D2DrlgTileLinkStrc;

struct D2DrlgCoordStrc;

struct D2RoomTileStrc;

struct D2DrlgActStrc;

struct D2ActiveRoomStrc;

struct D2TileLibraryEntryStrc;

struct D2DrlgRoomStrc;

struct D2DrlgTileGridStrc;

struct D2DrlgStrc;

struct D2DrlgLevelStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall TileLibraryGetTiles(D2TileLibraryHeaderStrc** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries); // 0x00604AE0




void __fastcall sub_0040B480(void*,void*,const char*,int,int); // 0x0040B480

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430





extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0






static void DRLGROOMTILE_ResetRoomTileSelections(D2DrlgRoomStrc* pDrlgRoom);

#define RANGE_COUNT 37

#define STYLE_SHIFT 20

#define SEQ_SHIFT 8

extern const D2UnkDrlgRoomTileStrc gaDrlgRoomTileLevelRanges[RANGE_COUNT];                                  // 0x006EEFC8

extern const D2UnkDrlgRoomTileStrc2 gaDrlgRoomTilePresetUnits[];                                   // 0x006EF188

extern const D2CoordStrc gaWarpTileOffsets[4];                                                     // 0x006EF554

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId);                                              // 0x004E6C50



int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoords, int nX, int nY);                   // 0x0066B980

void __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, D2PoolSystemStrc* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY); // 0x0066BF30

void __fastcall DRLGROOMTILE_InitTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DDE0

static void __stdcall DRLGROOMTILE_AddTilePresetUnits(D2DrlgTileDataStrc* pTileData, int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY); // 0x0066D9E0

struct D2PresetUnitStrc;

static void __stdcall DRLGROOMTILE_InitializeTileDataFlags(unsigned int nTileFlags, int nY, D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData, int nType, int nX); // 0x0066DB20

static void __stdcall DRLGROOMTILE_LoadWallWarpTiles(D2DrlgTileDataStrc* pTileData, unsigned int nPackedTileInformation, int nTileType, D2DrlgRoomStrc* pDrlgRoom); // 0x0066E260

static void __stdcall DRLGROOMTILE_UpdateAndGetLvlWarpTxtRecord(int nTileType, D2RoomTileStrc* pWarpTile);

static int __stdcall DRLGROOMTILE_AddWarp(int nX, int nTileType, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nY);

static void __stdcall DRLGROOMTILE_LoadFloorWarpTiles(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int nTileType, unsigned int nPackedTileInformation);

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_FindLinkedTileInRoom(D2DrlgRoomStrc* pNearRoom, int bFloor, int nX, int nY, unsigned int nPackedTileInformation);

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_GetLinkedTileData(int bFloor, int nX, int nY, D2DrlgRoomStrc** ppDrlgRoom, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation);

static D2DrlgTileDataStrc* __stdcall DRLGROOMTILE_AddLinkedTileData(D2PoolSystemStrc* pMemPool, unsigned int nPackedTileInformation, int nX, int nY, D2DrlgRoomStrc* pDrlgRoom, int nTileType);


static void __stdcall DRLGROOMTILE_GetCreateLinkedTileData(D2PoolSystemStrc* pMemPool, D2DrlgRoomStrc* pDrlgRoom, int nTileType, unsigned int nPackedTileInformation, int nX, int nY); // 0x0066E940

static void __stdcall DRLGROOMTILE_LoadInitRoomTile(D2PoolSystemStrc* pMemPool, int nX, int nY, int bFillBlanks, D2DrlgRoomStrc* pDrlgRoom, unsigned int nPackedTileInformation, int nTileType);

static void __stdcall DRLGROOMTILE_SetTileDataPosition(D2DrlgTileDataStrc* pTileData, D2DrlgRoomStrc* pDrlgRoom, int nX, int nY);





struct D2DrlgSubstGroupStrc;

struct D2LvlSubTxt;


struct D2DrlgOutdoorInfoStrc;

struct D2CoordStrc;

struct D2DrlgOutdoorRoomStrc;


static int __stdcall DRLGTILESUB_TestReplaceSubPreset(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, D2UnkOutdoorStrc* pOutdoor); // 0x0066F3B0

extern int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc* pSeed, int nLimit); // 0x0045C3E0

static int __stdcall sub_0066F350_GetFloorGridEntry(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY);

static int __stdcall sub_0066F380_GetWallGridEntry(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY);

static void __stdcall DRLGROOMTILE_LinkedTileDataManager(D2PoolSystemStrc* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, D2DrlgTileDataStrc* pTileData, int nTileType, unsigned int nPackedTileInformation, int nX, int nY);

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

int __stdcall sub_0066FCF0_CanPlaceSubstGroup(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord);

void __fastcall sub_006707A0_SubstWaypointShrine(D2UnkOutdoorStrc2* pOutdoor);



static void __stdcall sub_0066FA10_AddPresetUnits(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2UnkOutdoorStrc2* pOutdoor, D2PoolSystemStrc* pMemPool, D2LvlSubTxt* pLvlSubTxtRecord);

void __stdcall sub_0066FAD0_PlaceSubstGroup(D2PoolSystemStrc* pMemPool, int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nPick); // 0x0066FAD0



static int __stdcall DRLGTILESUB_TestSubstGroupTiles(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup); // 0x0066FE00

static void __stdcall DRLGTILESUB_DoSubstitutions(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pRecord);


void __stdcall sub_0066FAD0_PlaceSubstGroup(D2PoolSystemStrc* pMemPool, int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset);

static inline unsigned int SEED_RollRandomNumberHighFirst(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x0066F350
static int __stdcall sub_0066F350_GetFloorGridEntry(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    if (pLvlSubTxtRecord->pDrlgFile->nFloorLayers)
    {
        return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pFloorGrid, nX, nY);
    }

    return 0;
}

// 0x0066F380
static int __stdcall sub_0066F380_GetWallGridEntry(D2LvlSubTxt* pLvlSubTxtRecord, int nX, int nY)
{
    if (pLvlSubTxtRecord->pDrlgFile->nWallLayers)
    {
        return DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pWallGrid, nX, nY);
    }

    return 0;
}

// 0x0066F3B0
static int __stdcall DRLGTILESUB_TestReplaceSubPreset(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, D2UnkOutdoorStrc* pOutdoor)
{
    nX -= nX % pLvlSubTxtRecord->dwGridSize;
    nY -= nY % pLvlSubTxtRecord->dwGridSize;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nFloorFlags = sub_0066F350_GetFloorGridEntry(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            const int nWallFlags = sub_0066F380_GetWallGridEntry(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            const int nPosX = nX + i * pLvlSubTxtRecord->dwGridSize;
            const int nPosY = nY + j * pLvlSubTxtRecord->dwGridSize;

            const int nEntry = DRLGGRID_GetGridEntry(pOutdoor->pGrid1, nPosX, nPosY);
            if (pOutdoor->field_24)
            {
                if (!pOutdoor->field_24(pOutdoor->pLevel, nPosX, nPosY, nEntry, nFloorFlags, nWallFlags))
                {
                    return 0;
                }
            }
            else if (nWallFlags & 1)
            {
                const int nStyle = ((nWallFlags >> 8) & 0xFF) - 1;
                if (nStyle != pOutdoor->field_14 && nStyle + pOutdoor->nLevelPrestId != nEntry)
                {
                    return 0;
                }

                if (!pOutdoor->field_1C(pOutdoor->pLevel, nPosX, nPosY))
                {
                    return 0;
                }
            }
            else if (nFloorFlags & 2)
            {
                if (!pOutdoor->field_20(pOutdoor->pLevel, nPosX, nPosY, 0, 0, 0))
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

// 0x0066F520
void __stdcall DRLGTILESUB_ReplaceSubPreset(int nX, int nY, D2UnkOutdoorStrc* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset)
{
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int nBaseX = pSubstGroup->tBox.nPosX + nOffset;
    const int nBaseY = pSubstGroup->tBox.nPosY;

    nX -= nX % pLvlSubTxtRecord->dwGridSize;
    nY -= nY % pLvlSubTxtRecord->dwGridSize;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nWallFlags = sub_0066F380_GetWallGridEntry(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            const int nFloorFlags = sub_0066F350_GetFloorGridEntry(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            const int nPosX = nX + i * pLvlSubTxtRecord->dwGridSize;
            const int nPosY = nY + j * pLvlSubTxtRecord->dwGridSize;
            if (nWallFlags & 1)
            {
                const int nStyle = (nWallFlags >> 8) & 0xFF;
                const int nSubStyle = nStyle - 1;
                int nPresetId = 0;
                if (pOutdoor->field_28)
                {
                    nPresetId = pOutdoor->field_28(pLevel, ((unsigned int)nWallFlags >> 20) & 0x3F, nStyle);
                }
                else
                {
                    nPresetId = nSubStyle + pOutdoor->nLevelPrestId;
                }

                if (nPresetId != -5 && nSubStyle != pOutdoor->field_14)
                {
                    pOutdoor->field_34(pLevel, nPosX, nPosY, nPresetId, 0, 1);
                }
            }
            else if (nFloorFlags & 2)
            {
                pOutdoor->field_2C(pLevel, nPosX, nPosY);
            }
            else
            {
                pOutdoor->field_30(pLevel, nPosX, nPosY);
            }
        }
    }
}

static inline unsigned int DRLGTILESUB_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int DRLGTILESUB_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return DRLGTILESUB_RollRandomNumberInline(pSeed) % nMax;
    return DRLGTILESUB_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x0066F690
int __stdcall DRLGTILESUB_ApplySubstGroup(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup)
{
    D2CoordStrc pCoord[256];
    int bWilderness;
    int bSmallWilderness;
    int* pBox = pOutdoor->field_4;
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int bSubType1 = pOutdoor->nLvlSubId == 1;
    const int nFlags = pLevel->pOutdoors->dwFlags & 12;

    if (pLevel->eLevelId >= 2 && pLevel->eLevelId <= 7)
        bWilderness = 1;
    else
        bWilderness = 0;

    const int nOffset = bSubType1 && nFlags ? -1 : 1;
    const int nWidth = pBox[2] - pSubstGroup->tBox.nWidth * pLvlSubTxtRecord->dwGridSize + nOffset;
    const int nHeight = pBox[3] - pSubstGroup->tBox.nHeight * pLvlSubTxtRecord->dwGridSize + 1;
    const int nArea = nWidth * nHeight;
    if (nArea)
    {
        if (bSubType1 && bWilderness && nWidth < 6 && nHeight < 6)
            bSmallWilderness = 1;
        else
            bSmallWilderness = 0;

        for (int i = 0; i < nArea; ++i)
        {
            pCoord[i].nX = i % nWidth;
            pCoord[i].nY = i / nWidth;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nRand1 = DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, nArea);
            const int nRand2 = DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, nArea);
            const D2CoordStrc tTemp = pCoord[nRand1];
            pCoord[nRand1] = pCoord[nRand2];
            pCoord[nRand2] = tTemp;
        }

        for (int i = 0; i < nArea; ++i)
        {
            const int nX = pCoord[i].nX;
            const int nY = pCoord[i].nY;
            if (!bSmallWilderness || nX != 2 || nY != 2)
            {
                if (DRLGTILESUB_TestReplaceSubPreset(nX, nY, pSubstGroup, pLvlSubTxtRecord, pOutdoor))
                {
                    DRLGTILESUB_ReplaceSubPreset(nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, (DRLGTILESUB_RollLimitedRandomNumberInline(&pLevel->pSeed, pSubstGroup->nSubstGroup) + 1) * (pSubstGroup->tBox.nWidth + 1));
                    if (pLvlSubTxtRecord->dwBordType == 0)
                        return 1;
                    else if (pLvlSubTxtRecord->dwBordType == 1)
                        return 1;
                }
            }
        }
    }
    return 0;
}

// 0x0066F990
static void __stdcall DRLGTILESUB_ApplySecondaryGroups(D2UnkOutdoorStrc* pOutdoor, D2LvlSubTxt* pRecord)
{
    D2DrlgFileStrc* pFile = pRecord->pDrlgFile;
    D2DrlgLevelStrc* pLevel = pOutdoor->pLevel;
    const int nGroups = pFile->nSubstGroups;
    int nStart = 0;
    if (nGroups)
    {
        if (pOutdoor->field_14 == -1)
            pOutdoor->field_14 = 62;
        if (!pRecord->dwBordType)
            nStart = sub_0045C3E0_RollLimited(&pLevel->pSeed, nGroups);
        for (int i = 0; i < nGroups; ++i)
        {
            if (DRLGTILESUB_ApplySubstGroup(pOutdoor, pRecord, &pFile->pSubstGroups[(nStart + i) % nGroups])
                && !pRecord->dwBordType)
                break;
        }
    }
}

// 0x0066FA10
static void __stdcall sub_0066FA10_AddPresetUnits(int nX, int nY, D2DrlgSubstGroupStrc* pSubstGroup, D2UnkOutdoorStrc2* pOutdoor, D2PoolSystemStrc* pMemPool, D2LvlSubTxt* pLvlSubTxtRecord)
{
    int nSubX = nX;
    int nSubY = nY;
    int nMinX = pSubstGroup->tBox.nPosX;
    int nMinY = pSubstGroup->tBox.nPosY;
    int nSizeX = pSubstGroup->tBox.nWidth;
    int nSizeY = pSubstGroup->tBox.nHeight;

    DUNGEON_GameTileToSubtileCoords(&nSubX, &nSubY);
    DUNGEON_GameTileToSubtileCoords(&nMinX, &nMinY);
    DUNGEON_GameTileToSubtileCoords(&nSizeX, &nSizeY);

    for (D2PresetUnitStrc* pPresetUnit = pLvlSubTxtRecord->pDrlgFile->pPresetUnit; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        if (pPresetUnit->nXpos > nMinX && pPresetUnit->nYpos > nMinY && pPresetUnit->nXpos < nMinX + nSizeX && pPresetUnit->nYpos < nMinY + nSizeY)
        {
            DRLGROOM_AllocPresetUnit(pOutdoor->pDrlgRoom, pMemPool, pPresetUnit->nUnitType, pPresetUnit->nIndex, pPresetUnit->nMode, nSubX + pPresetUnit->nXpos - nMinX, nSubY + pPresetUnit->nYpos - nMinY);
        }
    }
}

static int __stdcall DRLGTILESUB_GetWallGridEntry(D2LvlSubTxt* pLvlSubTxtRecord, int nLayer, int nX, int nY)
{
    return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pWallGrid[nLayer], nX, nY);
}

static int __stdcall DRLGTILESUB_GetTileTypeEntry(D2LvlSubTxt* pLvlSubTxtRecord, int nLayer, int nX, int nY)
{
    return DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pTileTypeGrid[nLayer], nX, nY);
}

// 0x0066FAD0
void __stdcall sub_0066FAD0_PlaceSubstGroup(D2PoolSystemStrc* pMemPool, int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord, int nOffset)
{
    const int nBaseX = pSubstGroup->tBox.nPosX + nOffset;
    const int nWallLayers = pLvlSubTxtRecord->pDrlgFile->nWallLayers;
    D2DrlgRoomStrc* pDrlgRoom = pOutdoor->pDrlgRoom;
    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    const int nBaseY = pSubstGroup->tBox.nPosY;
    int nCounter = 0;
    int nFlags = 0;
    int i;
    int j;

    for (j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (i = 0; i < pSubstGroup->tBox.nWidth;)
        {
            if (DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j) & 0x8000000)
            {
                ++nCounter;
                ++i;
            }
            else
            {
                ++i;
            }
        }
    }

    DRLGROOMTILE_ReallocRoofTileGrid(pMemPool, pTileGrid, nCounter);

    for (j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            nFlags = sub_0066F350_GetFloorGridEntry(pLvlSubTxtRecord, nBaseX + i, nBaseY + j);
            if (nFlags & 2)
            {
                DRLGGRID_AlterGridFlag(pOutdoor->pFloorGrid, nX + i, nY + j, nFlags | 0x80, 3);
            }

            for (int nLayer = 0; nLayer < nWallLayers; ++nLayer)
            {
                nFlags = DRLGTILESUB_GetWallGridEntry(pLvlSubTxtRecord, nLayer, nBaseX + i, nBaseY + j);
                if (nFlags & 1 && pOutdoor->pWallsGrids[nLayer])
                {
                    DRLGGRID_AlterGridFlag(pOutdoor->pWallsGrids[nLayer], nX + i, nY + j, nFlags, 3);
                }

                nFlags = DRLGTILESUB_GetTileTypeEntry(pLvlSubTxtRecord, nLayer, nBaseX + i, nBaseY + j);
                if (nFlags && pOutdoor->pOutdoorRooms[nLayer])
                {
                    DRLGGRID_AlterGridFlag(&pOutdoor->pOutdoorRooms[nLayer]->pTileTypeGrid, nX + i, nY + j, nFlags, 3);
                }
            }

            nFlags = DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pShadowGrid, nBaseX + i, nBaseY + j);
            if (nFlags & 0x8000000)
            {
                DRLGROOMTILE_InitTileShadow(pDrlgRoom, pDrlgRoom->pDrlgCoord.nPosX + i + nX, pDrlgRoom->pDrlgCoord.nPosY + j + nY, nFlags);
            }
        }
    }

    sub_0066FA10_AddPresetUnits(nX, nY, pSubstGroup, pOutdoor, pMemPool, pLvlSubTxtRecord);
}

// 0x0066FCF0
int __stdcall sub_0066FCF0_CanPlaceSubstGroup(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2DrlgSubstGroupStrc* pSubstGroup, D2LvlSubTxt* pLvlSubTxtRecord)
{
    const int nLayers = pOutdoor->nLayers;

    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            if (DRLGGRID_GetGridEntry(&pLvlSubTxtRecord->pFloorGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY) & 2
                || pLvlSubTxtRecord->pWallGrid[0].nWidth && DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pWallGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY) & 1)
            {
                const int nFlags = DRLGGRID_GetGridEntry(pOutdoor->pFloorGrid, nX + i, nY + j);
                if (nFlags & 0x3F0FF00 || !(nFlags & 2))
                {
                    return 0;
                }

                for (int nLayer = 0; nLayer < nLayers; ++nLayer)
                {
                    if (pOutdoor->pWallsGrids[nLayer] && DRLGGRID_GetGridEntry(pOutdoor->pWallsGrids[nLayer], nX + i, nY + j) & 1)
                    {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

// 0x0066FE00
static int __stdcall DRLGTILESUB_TestSubstGroupTiles(int nX, int nY, D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord, D2DrlgSubstGroupStrc* pSubstGroup)
{
    for (int j = 0; j < pSubstGroup->tBox.nHeight; ++j)
    {
        for (int i = 0; i < pSubstGroup->tBox.nWidth; ++i)
        {
            const int nTileType = DRLGGRID_GetGridEntry(pLvlSubTxtRecord->pTileTypeGrid, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            if (nTileType != DRLGGRID_GetGridEntry(&pOutdoor->pOutdoorRooms[0]->pTileTypeGrid, i + nX, j + nY))
            {
                return 0;
            }

            const int nFloorFlags1 = sub_0066F350_GetFloorGridEntry(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            if (nFloorFlags1 & 2)
            {
                const int nFloorFlags2 = DRLGGRID_GetGridEntry(pOutdoor->pFloorGrid, i + nX, j + nY);
                if (!(nFloorFlags2 & 2))
                {
                    return 0;
                }

                if ((nFloorFlags1 ^ nFloorFlags2) & 0x3F0FF00)
                {
                    return 0;
                }
            }

            const int nWallFlags1 = sub_0066F380_GetWallGridEntry(pLvlSubTxtRecord, i + pSubstGroup->tBox.nPosX, j + pSubstGroup->tBox.nPosY);
            if (nWallFlags1 & 1)
            {
                const int nWallFlags2 = DRLGGRID_GetGridEntry(pOutdoor->pWallsGrids[0], i + nX, j + nY);
                if (!(nWallFlags2 & 1))
                {
                    return 0;
                }

                if ((nWallFlags1 ^ nWallFlags2) & 0x3F0FF00)
                {
                    return 0;
                }
            }
        }
    }

    return 1;
}

static inline int SEED_RollLimitedRandomNumberU(D2SeedStrc* pSeed, unsigned int nMax)
{
    if ((int)nMax <= 0)
        return 0;
    if ((nMax - 1) & nMax)
        return SEED_RollRandomNumberHighFirst(pSeed) % nMax;
    return SEED_RollRandomNumberHighFirst(pSeed) & (nMax - 1);
}

// 0x0066FF50
void __stdcall sub_0066FF50_SubstituteAll(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pLvlSubTxtRecord)
{
    D2DrlgRoomStrc* pDrlgRoom = pOutdoor->pDrlgRoom;
    D2PoolSystemStrc* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgFileStrc* pDrlgFile = pLvlSubTxtRecord->pDrlgFile;

    for (int nGroup = 0; nGroup < pDrlgFile->nSubstGroups; ++nGroup)
    {
        D2DrlgSubstGroupStrc* pSubstGroup = &pDrlgFile->pSubstGroups[nGroup];
        const int nWidth = pDrlgRoom->pDrlgCoord.nWidth - pSubstGroup->tBox.nWidth + 1;
        const int nHeight = pDrlgRoom->pDrlgCoord.nHeight - pSubstGroup->tBox.nHeight + 1;
        if (nWidth > 0 && nHeight > 0)
        {
            switch (pDrlgFile->nSubstMethod)
            {
            case 1:
                for (int nY = 1; nY < nHeight; ++nY)
                {
                    for (int nX = 1; nX < nWidth; ++nX)
                    {
                        if (sub_0066FCF0_CanPlaceSubstGroup(nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord))
                        {
                            sub_0066FAD0_PlaceSubstGroup(pMemPool, nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, 0);
                        }
                    }
                }
                break;

            case 2:
                for (int nY = 0; nY < nHeight; ++nY)
                {
                    for (int nX = 0; nX < nWidth; ++nX)
                    {
                        if (DRLGTILESUB_TestSubstGroupTiles(nX, nY, pOutdoor, pLvlSubTxtRecord, pSubstGroup))
                        {
                            const int nRoll = SEED_RollLimitedRandomNumberU(&pDrlgRoom->pSeed, 100);
                            if (pLvlSubTxtRecord->nProb[pOutdoor->nSubTheme] < nRoll)
                            {
                                const int nPick = SEED_RollLimitedRandomNumberU(&pDrlgRoom->pSeed, pSubstGroup->nSubstGroup);
                                sub_0066FAD0_PlaceSubstGroup(pMemPool, nX, nY, pOutdoor, pSubstGroup, pLvlSubTxtRecord, (pSubstGroup->tBox.nWidth + 1) * (nPick + 1));
                            }
                        }
                    }
                }
                break;
            }
        }
    }
}

// 0x00670170
static void __stdcall DRLGTILESUB_DoSubstitutions(D2UnkOutdoorStrc2* pOutdoor, D2LvlSubTxt* pRecord)
{
    D2DrlgRoomStrc* pRoom = pOutdoor->pDrlgRoom;
    D2PoolSystemStrc* pMemPool = pRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgFileStrc* pFile = pRecord->pDrlgFile;
    const int nMax = pRecord->nMax[pOutdoor->nSubTheme];
    if (!pFile->nSubstGroups) return;
    for (int nCount = 0; nCount < nMax; ++nCount)
    {
        D2DrlgSubstGroupStrc* pGroup = &pFile->pSubstGroups[SEED_RollLimitedRandomNumberU(&pRoom->pSeed, pFile->nSubstGroups)];
        int nHeight = pRoom->pDrlgCoord.nHeight - pGroup->tBox.nHeight + 1;
        int nWidth = pRoom->pDrlgCoord.nWidth - pGroup->tBox.nWidth + 1;
        if (nWidth > 1 && nHeight > 1)
        {
            const int nTrials = pRecord->nTrials[pOutdoor->nSubTheme];
            if (nTrials == -1)
            {
                const int nAvailableWidth = nWidth - 1;
                const int nArea = nAvailableWidth * (nHeight - 1);
                if (!nArea) continue;
                D2CoordStrc tCoords[256];
                for (int i = 0; i < nArea; ++i)
                {
                    tCoords[i].nX = i % nAvailableWidth;
                    tCoords[i].nY = i / nAvailableWidth;
                }
                for (int i = 0; i < nArea; ++i)
                {
                    unsigned int nRand1 = SEED_RollLimitedRandomNumberU(&pRoom->pSeed, nArea);
                    unsigned int nRand2 = SEED_RollLimitedRandomNumberU(&pRoom->pSeed, nArea);
                    D2CoordStrc tTemp = tCoords[nRand1];
                    tCoords[nRand1] = tCoords[nRand2];
                    tCoords[nRand2] = tTemp;
                }
                for (int i = 0; i < nArea; ++i)
                {
                    int nX = tCoords[i].nX + 1;
                    int nY = tCoords[i].nY + 1;
                    if (sub_0066FCF0_CanPlaceSubstGroup(nX,nY,pOutdoor,pGroup,pRecord))
                    {
                        sub_0066FAD0_PlaceSubstGroup(pMemPool,nX,nY,pOutdoor,pGroup,pRecord,0);
                        break;
                    }
                }
            }
            else
            {
                for (int i=0; i<nTrials; ++i)
                {
                    int nX = SEED_RollLimitedRandomNumberU(&pRoom->pSeed,nWidth-1)+1;
                    int nY = SEED_RollLimitedRandomNumberU(&pRoom->pSeed,nHeight-1)+1;
                    if (sub_0066FCF0_CanPlaceSubstGroup(nX,nY,pOutdoor,pGroup,pRecord))
                    {
                        sub_0066FAD0_PlaceSubstGroup(pMemPool,nX,nY,pOutdoor,pGroup,pRecord,0);
                        break;
                    }
                }
            }
        }
    }
}

// 0x006704E0
void __fastcall DRLGTILESUB_InitializeDrlgFile(void* hArchive, D2LvlSubTxt* pLvlSubTxtRecord)
{
    D2DrlgFileStrc** ppDrlgFile = &pLvlSubTxtRecord->pDrlgFile;
    if (!pLvlSubTxtRecord->pDrlgFile)
    {
        DRLGPRESET_LoadDrlgFile(ppDrlgFile, hArchive, pLvlSubTxtRecord->szFile);

        const int nWidth = (*ppDrlgFile)->nWidth + 1;
        const int nHeight = (*ppDrlgFile)->nHeight + 1;
        D2DrlgCoordStrc pDrlgCoord;
        pDrlgCoord.nPosX = 0;
        pDrlgCoord.nPosY = 0;
        pDrlgCoord.nWidth = nWidth;
        pDrlgCoord.nHeight = nHeight;

        D2_ASSERT((*ppDrlgFile)->nSubstGroups, 694);

        for (int i = 0; i < (*ppDrlgFile)->nWallLayers; ++i)
        {
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pWallGrid[i], (int*)(*ppDrlgFile)->pWallLayer[i], &pDrlgCoord, nWidth);
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pTileTypeGrid[i], (int*)pLvlSubTxtRecord->pDrlgFile->pTileTypeLayer[i], &pDrlgCoord, nWidth);
        }

        for (int i = 1; i < (*ppDrlgFile)->nWallLayers; ++i)
        {
            DRLGGRID_AlterAllGridFlags(&pLvlSubTxtRecord->pWallGrid[i], i << 18, 0);
        }

        if ((*ppDrlgFile)->nFloorLayers)
        {
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pFloorGrid, (int*)(*ppDrlgFile)->pFloorLayer[0], &pDrlgCoord, nWidth);
        }

        if ((*ppDrlgFile)->pShadowLayer)
        {
            DRLGGRID_FillNewCellFlags(0, &pLvlSubTxtRecord->pShadowGrid, (int*)(*ppDrlgFile)->pShadowLayer, &pDrlgCoord, nWidth);
        }
    }
}


inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00670630
void __fastcall DRLGTILESUB_FreeDrlgFile(D2LvlSubTxt* pLvlSubTxtRecord)
{
    if (pLvlSubTxtRecord->pDrlgFile)
    {
        for (int i = 0; i < pLvlSubTxtRecord->pDrlgFile->nWallLayers; ++i)
        {
            DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pWallGrid[i]);
            DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pTileTypeGrid[i]);
        }

        DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pFloorGrid);
        DRLGGRID_FreeGrid(0, &pLvlSubTxtRecord->pShadowGrid);

        DRLGPRESET_FreeDrlgFile(&pLvlSubTxtRecord->pDrlgFile);
    }
}

// 0x006706A0
int __fastcall DRLGTILESUB_PickSubThemes(D2DrlgRoomStrc* pDrlgRoom, int nSubType, int nSubTheme)
{
    if (nSubType != -1 && nSubTheme != -1)
    {
        D2LvlSubTxt* pLvlSubTxtRecord = DATATBLS_GetLvlSubTxtRecord(nSubType);
        int nMask = 0;
        int nCounter = 0;
        while (pLvlSubTxtRecord->dwType == nSubType)
        {
            if ((int)((unsigned int)SEED_RollRandomNumber(&pDrlgRoom->pSeed) % 100) < pLvlSubTxtRecord->nProb[nSubTheme])
            {
                nMask |= 1 << nCounter;
                pDrlgRoom->dwDT1Mask |= pLvlSubTxtRecord->dwDt1Mask;
            }
            ++pLvlSubTxtRecord;
            ++nCounter;
        }
        return nMask;
    }
    return 0;
}

// 0x00670750
void __fastcall DRLGTILESUB_ApplySubstitutionBorder(D2UnkOutdoorStrc* pOutdoor)
{
    D2LvlSubTxt* pRecord = DATATBLS_GetLvlSubTxtRecord(pOutdoor->nLvlSubId);
    void* hArchive = pOutdoor->pLevel->pDrlg->hArchive;
    while (pRecord->dwType == pOutdoor->nLvlSubId)
    {
        DRLGTILESUB_InitializeDrlgFile(hArchive, pRecord);
        DRLGTILESUB_ApplySecondaryGroups(pOutdoor, pRecord);
        ++pRecord;
    }
}

// 0x006707A0
void __fastcall sub_006707A0_SubstWaypointShrine(D2UnkOutdoorStrc2* pOutdoor)
{
    if (pOutdoor->nSubWaypoint_Shrine != -1)
    {
        D2LvlSubTxt* pLvlSubTxtRecord = DATATBLS_GetLvlSubTxtRecord(pOutdoor->nSubWaypoint_Shrine);
        unsigned int nThemeFlag = pOutdoor->nSubThemePicked;
        void* hArchive = pOutdoor->pDrlgRoom->ptDrlgLevel->pDrlg->hArchive;
        while (nThemeFlag)
        {
            if (nThemeFlag & 1)
            {
                DRLGTILESUB_InitializeDrlgFile(hArchive, pLvlSubTxtRecord);

                if (pLvlSubTxtRecord->dwCheckAll)
                {
                    sub_0066FF50_SubstituteAll(pOutdoor, pLvlSubTxtRecord);
                }
                else
                {
                    DRLGTILESUB_DoSubstitutions(pOutdoor, pLvlSubTxtRecord);
                }
            }

            nThemeFlag >>= 1;
            ++pLvlSubTxtRecord;
        }
    }
}
