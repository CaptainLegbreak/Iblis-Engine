#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2DataTbls.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2DrlgRooms.h"
#include "D2GameObjs.h"
#include "D2DrlgMaps.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2Drlg.h"
#include "D2DrlgPresets.h"
#include "D2DrlgTiles.h"
#include "D2Common.h"
#include "D2StormLink.h"

struct D2MonPresetTxt
{
    unsigned char nAct;
    unsigned char nPlace;
    unsigned short wPlace;
};


struct D2ItemsTxt;

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330

extern "C" int __cdecl tolower(int nChar);                                                                  // 0x0068523E

unsigned int __fastcall sub_006C9A38(const char* szString);                                                    // 0x006C9A38

void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640

D2MonPresetTxt* __stdcall DATATBLS_GetMonPresetTxtActSection(int nAct, int* pnRecords);                     // 0x00659B40

int __fastcall DATATBLS_GetSuperUniquesTxtRecordCount(); // 0x00655710

__declspec(noinline) int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId); // 0x004E6C50

int __fastcall DRLGPRESET_MapTileType(int nId);                                                             // 0x0066D7F0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern const char* gpszPresetItemCodes[];                                                          // 0x00748AD4

extern int gnPresetObjectIndices[5][150];                                                                   // 0x00748AD8

struct D2ActiveRoomStrc;

struct D2LevelFileListStrc
{
    char szPath[0x104];
    long nRefCount;
    D2DrlgFileStrc* pFile;
    D2LevelFileListStrc* pNext;
};


struct D2DrlgVertexStrc;

struct D2RoomStrc;

struct D2DrlgRoomStrc;

extern "C" const char gszDrlgPresetSourceFile;                                                                    // 0x006EE7C4

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);         // 0x0040B480

D2LvlPrestTxt* __stdcall DATATBLS_GetLvlPrestTxtRecord(int nLvlPrestId);                                                  // 0x0061F0B0

D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);                            // 0x0066B3E0

void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom);                          // 0x0066B970

void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pGrid);                                     // 0x0067CD90

void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertices);                              // 0x0067D1E0

void __stdcall SKILLS_GameTileToSubtileCoords(int* pX, int* pY);                                                            // 0x00643560

struct D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY);   // 0x0066BF30

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY);                                          // 0x0067C570

void __fastcall DRLGGRID_AssignCellsOffsetsAndFlags(D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth, int* pBuffer);   // 0x0067CD30

void __fastcall DRLGGRID_ResetGrid(D2DrlgGridStrc* pGrid);                                                       // 0x0067CDC0

void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed);                    // 0x00667620

int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pCoord, int nX, int nY);                                          // 0x0066B980

void __fastcall DRLGGRID_FillNewCellFlags(void* pMemPool, D2DrlgGridStrc* pGrid, int* pCellFlags, D2DrlgCoordStrc* pCoord, int nWidth);   // 0x0067CCC0

void __fastcall DRLGGRID_AlterAllGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation);                              // 0x0067C590

void __fastcall DRLGGRID_AlterEdgeGridFlags(D2DrlgGridStrc* pGrid, int nFlags, int nOperation);                             // 0x0067C600

D2LvlPrestTxt* __fastcall DATATBLS_GetLvlPrestTxtRecordFromLevelId(int nLevelId);                                                  // 0x0061F0E0

D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed);   // 0x00666ED0

int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId);                                                  // 0x0066C040

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                                     // 0x00642BB0

void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel);                                                        // 0x006424A0

D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0061B730

int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId); // 0x0066AF30

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pGrid, int nX, int nY, int nFlags, int nOperation);             // 0x0067C4F0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                                         // 0x00640E90

void __fastcall DRLGROOMTILE_AllocTileGrid(D2DrlgRoomStrc* pDrlgRoom);                                                // 0x0066EEA0

void __fastcall DRLGROOMTILE_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY);   // 0x0066ECE0

void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int bKillEdgeX, int bKillEdgeY);   // 0x0066D290

void __fastcall DRLGROOMTILE_CountWallWarpTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bKillEdgeX, int bKillEdgeY);   // 0x0066EDB0

void __fastcall DRLGROOMTILE_AllocTileData(D2DrlgRoomStrc* pDrlgRoom);                                                 // 0x0066EEE0

void __fastcall DRLGROOMTILE_LoadInitRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, D2DrlgGridStrc* pTileTypeGrid, int bCheckCoordinatesValidity, int bKillEdgeX, int bKillEdgeY);   // 0x0066EC10

void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pDrlgRoom, int nAnimSpeed, D2DrlgGridStrc* pWallGrid, int nWallLayers, D2DrlgGridStrc* pFloorGrid, int nFloorLayers, D2DrlgGridStrc* pCellGrid);   // 0x0066D700

void __fastcall DRLGLOGIC_InitializeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pTileTypeGrid, D2DrlgGridStrc* pFloorGrid, D2DrlgGridStrc* pWallGrid);   // 0x0066D110

void __fastcall DRLGLOGIC_AllocCoordLists(D2DrlgRoomStrc* pDrlgRoom);                                               // 0x0066CCB0

D2LevelFileListStrc* gpLevelFilesList;                                                                            // 0x0096D60C

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

// A critical section for the whole run: initialized before main, deleted at exit.
struct CCritSect : D2CriticalSectionStrc
{
    CCritSect() { InitializeCriticalSection(this); }
    ~CCritSect() { DeleteCriticalSection(this); }
};

// build: symbol ??__EgLevelFilesCriticalSection@@YAXXZ 0x006CB010
// build: symbol ??__FgLevelFilesCriticalSection@@YAXXZ 0x006CB4E0
CCritSect gLevelFilesCriticalSection;                                                                              // 0x0096D610

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);          // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);          // 0x006CC214

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pValue);                             // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pValue);                             // 0x006CC204

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc** ppDrlgFile, void* hArchive, const char* szFile);

void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile);

void __fastcall DRLGPRESET_ParseDS1File(D2DrlgFileStrc* pDrlgFile, void* hArchive, const char* szFile);                  // 0x00665950

int __stdcall sub_00604B90(void* pTile);                                                                  // 0x00604B90

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                                // 0x006CC260

void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags);   // 0x0067CBF0

extern "C" const char gszEmptyAssertText;                                                                          // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                               // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                 // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                            // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                      // 0x006829C0

#pragma intrinsic(memset, memcpy)

static void __stdcall DRLGPRESET_AddPresetRiverObjects(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nOffsetX, D2DrlgGridStrc* pDrlgGrid);

static void DRLGPRESET_SpawnMapRivers(D2DrlgMapStrc* pDrlgMap, void* pMemPool); // 0x006663C0

void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom);

#pragma intrinsic(memset)

struct D2LevelFileListStrc;


struct D2DrlgCoordStrc;

struct D2MapAIPathPositionStrc;

struct D2MapAIStrc;

struct D2PresetUnitStrc;

struct D2LvlPrestTxt;


struct D2DrlgMapStrc;

struct D2DrlgPresetRoomStrc;

struct D2DrlgPresetLevelStrc;

struct D2DrlgStrc;

union D2SeedStrc;

struct D2CoordStrc;

struct D2StormLinkStrc;

struct D2StormListStrc;

struct D2Storm4167B0Strc;

struct D2Storm4168F0Strc;

struct D2Storm416A90Strc;

struct D2Unk00667420CStrc;

struct D2Unk00667420BStrc;

struct D2Unk00667420Strc;

struct D2ObjectsTxt;

struct D2DrlgTileInfoStrc;

struct D2DrlgGridStrc;

struct D2DrlgFileStrc;

struct D2DrlgLevelStrc;

struct D2DataTablesStrc;

struct D2DrlgPresetInfoStrc;


extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

struct D2Unk00667420CStrc
{
    char unk0x00[0x20];
    int n20;
};

struct D2Unk00667420BStrc
{
    D2Unk00667420CStrc* p00;
};

struct D2Unk00667420Strc
{
    char unk0x00[0x14];
    D2Unk00667420BStrc* p14;
};

void __fastcall DRLGROOMTILE_CountAllTileTypes(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pGrid, int bFillBlanks, int bKillEdgeX, int bKillEdgeY); // 0x0066ECE0

static void DRLGPRESET_FindTombStoneTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);

D2PresetUnitStrc* __fastcall DRLGPRESET_CopyPresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit, int nX, int nY); // 0x00667510

D2DrlgRoomStrc* __fastcall DRLGPRESET_InitPresetRoomData(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, D2DrlgCoordStrc* pDrlgCoord, unsigned int dwDT1Mask, int dwRoomFlags, int dwPresetFlags, D2DrlgGridStrc* pMazeGrid); // 0x00666680

static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, int bSingleRoom, D2DrlgMapStrc* pDrlgMap); // 0x00667970

static void __stdcall DRLGPRESET_InitPopsLocations(D2DrlgMapStrc* pDrlgMap, int nPops);

extern const char gszPresetFile[]; // 0x006EE7C4

int __fastcall sub_0045C3E0(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall DRLG_SetLevelPositionAndSize(D2DrlgStrc* pDrlg, D2DrlgLevelStrc* pLevel); // 0x00642D10

D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom);

D2MapAIStrc* __fastcall DRLGPRESET_CreateCopyOfMapAI(void* pMemPool, D2MapAIStrc* pMapAI);

D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc** ppMapAI2);

void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAI);

static void __stdcall DRLGPRESET_FreeDrlgGrids(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGPRESET_FreeDrlgGridsFromPresetRoom(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGPRESET_GetTombStoneTileCoords(D2DrlgRoomStrc* pDrlgRoom, D2CoordStrc** ppTombStoneTiles, int* pnTombStoneTiles);

int __fastcall DRLGPRESET_SetPickedFileInDrlgMap(D2DrlgMapStrc* pDrlgMap, int nPickedFile);

int __fastcall DRLGPRESET_GetSizeX(int nLvlPrestId);

int __fastcall DRLGPRESET_GetSizeY(int nLvlPrestId);

char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGPRESET_ResetDrlgMap(D2DrlgLevelStrc* pLevel, int bKeepPreset);

void __fastcall DRLGPRESET_FreePresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit);

static void __stdcall DRLGPRESET_AddSpawnedObjectPresetUnit(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nIndex, int nX, int nY);

static void DRLGPRESET_SpawnRiver(D2DrlgMapStrc* pDrlgMap, int nX, int nY, void* pMemPool);

static void __stdcall DRLGPRESET_AddNaviPresetUnit(D2DrlgMapStrc* pDrlgMap, void* pMemPool);

void __fastcall DRLGPRESET_SpawnHardcodedPresetUnits(D2DrlgRoomStrc* pDrlgRoom);

static void DRLGPRESET_MovePresetUnitsToRoom(D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGPRESET_InitPresetRoomGrids(D2DrlgRoomStrc* pDrlgRoom);

static void __stdcall DRLGPRESET_TogglePopsVisibility(D2DrlgRoomStrc* pDrlgRoom, int nPopSubIndex, D2DrlgCoordStrc* pDrlgCoord, int nTick, int bClose);

void __fastcall DRLGPRESET_UpdatePops(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int bOtherRoom);

void __stdcall DUNGEON_GameTileToSubtileCoords(int* pX, int* pY);

void __fastcall DRLGGRID_FillGrid(D2DrlgGridStrc* pGrid, int nWidth, int nHeight, int* pCellPos, int* pCellFlags);

void __fastcall DRLGPRESET_GenerateLevel(D2DrlgLevelStrc* pLevel);

void __fastcall DRLGPRESET_FreeDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap);

static inline int sub_IsSubstMethod(int nSubstMethod)
{
    switch (nSubstMethod)
    {
    case 1:
    case 2:
        return 1;
    }
    return 0;
}

// 0x00665810
static void DRLGPRESET_CopyCodePadded(D2PresetCodeStrc* pDst, const char* pSrc)
{
    if (!pSrc[0])
    {
        const char c = 0x20;
        pDst->c0 = c;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c0 = pSrc[0];
    if (!pSrc[1])
    {
        const char c = 0x20;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c1 = pSrc[1];
    if (!pSrc[2])
    {
        const char c = 0x20;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c2 = pSrc[2];
    pDst->c3 = 0x20;
}

// 0x00665900
static void DRLGPRESET_MapTileTypes(int* pTileTypes, int nCount)
{
    if (nCount > 0)
    {
        do
        {
            *pTileTypes = DRLGPRESET_MapTileType(*pTileTypes);
            ++pTileTypes;
        }
        while (--nCount);
    }
}

// 0x00665930
void __cdecl DRLGPRESET_LockLevelFiles()
{
    EnterCriticalSection(&gLevelFilesCriticalSection);
}

// 0x00665940
void __cdecl DRLGPRESET_UnlockLevelFiles()
{
    LeaveCriticalSection(&gLevelFilesCriticalSection);
}

void __fastcall sub_M107_Emit_00665810(D2PresetCodeStrc* pDst, const char* pSrc, int bCopy)
{
    if (bCopy)
        DRLGPRESET_CopyCodePadded(pDst, pSrc);
}

void __fastcall sub_M107_Emit_00665900(int* pTileTypes, int nCount, int bMap)
{
    if (bMap)
        DRLGPRESET_MapTileTypes(pTileTypes, nCount);
}

// 0x006658E0
int __stdcall DRLGPRESET_GetObjectIndexFromObjPreset(unsigned char nAct, int nUnitId)
{
    return gnPresetObjectIndices[nAct][nUnitId];
}

// 0x00665860
int __stdcall DRLGPRESET_CountPresetObjectsByAct(unsigned char nAct)
{
    int nCount = 0;
    for (int i = 0; i < 150; ++i)
    {
        if (!DRLGPRESET_GetObjectIndexFromObjPreset(nAct, i))
        {
            break;
        }

        ++nCount;
    }

    return nCount;
}

// 0x00665950
void __fastcall DRLGPRESET_ParseDS1File(D2DrlgFileStrc* pDrlgFile, void* hArchive, const char* szFileName)
{
    int* pData = (int*)ARCHIVE_AllocateBufferAndReadFile(hArchive, szFileName, 0, ".\\DRLG\\Preset.cpp", 0x300);
    pDrlgFile->pDS1File = pData;

    int nAct = 0;
    int nVersion = *pData++;
    pDrlgFile->nWidth = *pData++;
    pDrlgFile->nHeight = *pData++;

    if (nVersion >= 8)
    {
        nAct = *pData++;
        if (nAct > 4)
        {
            nAct = 4;
        }
    }

    pDrlgFile->nSubstMethod = 0;
    if (nVersion >= 10)
    {
        pDrlgFile->nSubstMethod = *pData++;
    }

    if (nVersion >= 3)
    {
        int nFiles = *pData++;
        for (int i = 0; i < nFiles; ++i)
        {
            pData = (int*)((char*)pData + sub_006C9A38((const char*)pData) + 1);
        }
    }

    int nCells = (pDrlgFile->nWidth + 1) * (pDrlgFile->nHeight + 1);

    if (nVersion >= 9 && nVersion <= 13)
    {
        pData += 2;
    }

    if (nVersion >= 4)
    {
        pDrlgFile->nWallLayers = *pData++;
        if (nVersion >= 16)
        {
            pDrlgFile->nFloorLayers = *pData++;
        }
        else
        {
            pDrlgFile->nFloorLayers = 1;
        }

        for (int i = 0; i < pDrlgFile->nWallLayers; ++i)
        {
            pDrlgFile->pWallLayer[i] = pData;
            pData += nCells;
            pDrlgFile->pTileTypeLayer[i] = pData;
            pData += nCells;
        }

        for (int i = 0; i < pDrlgFile->nFloorLayers; ++i)
        {
            pDrlgFile->pFloorLayer[i] = pData;
            pData += nCells;
        }
    }
    else
    {
        pDrlgFile->pWallLayer[0] = pData;
        pData += nCells;
        pDrlgFile->pFloorLayer[0] = pData;
        pData += nCells;
        pDrlgFile->pTileTypeLayer[0] = pData;
        pData += nCells;
        pDrlgFile->pSubstGroupTags = pData;
        pDrlgFile->nWallLayers = 1;
        pData += nCells;
    }

    if (nVersion < 7)
    {
        for (int i = 0; i < pDrlgFile->nWallLayers; ++i)
        {
            int* pTileType = (int*)pDrlgFile->pTileTypeLayer[i];
            for (int j = 0; j < nCells; ++j)
            {
                *pTileType = DRLGPRESET_MapTileType(*pTileType);
                ++pTileType;
            }
        }
    }

    pDrlgFile->pShadowLayer = pData;
    pData += nCells;

    switch (pDrlgFile->nSubstMethod)
    {
    case 1:
    case 2:
        pDrlgFile->pSubstGroupTags = pData;
        pData += nCells;
        break;
    }

    if (nVersion > 1)
    {
        int nObjects = *pData++;
        for (int i = 0; i < nObjects; ++i)
        {
            int nType = *pData++;
            int nIndex = *pData++;
            int nMode = 0;

            switch (nType)
            {
            case 1:
                nMode = 1;
                if (nVersion > 4)
                {
                    int nRecords = 0;
                    D2MonPresetTxt* pMonPreset = DATATBLS_GetMonPresetTxtActSection(nAct, &nRecords);
                    if (pMonPreset && nIndex < nRecords)
                    {
                        unsigned char nPlace = pMonPreset[nIndex].nPlace;
                        nIndex = pMonPreset[nIndex].wPlace;
                        switch (nPlace)
                        {
                        case 0:
                            nIndex += DATATBLS_GetSuperUniquesTxtRecordCount();
                            nIndex += sgptDataTables->nMonStatsTxtRecordCount;
                            break;
                        case 1:
                            break;
                        case 2:
                            nIndex += sgptDataTables->nMonStatsTxtRecordCount;
                            break;
                        default:
                            nIndex = -1;
                            break;
                        }
                    }

                    if (nAct == 2)
                    {
                        if (nIndex < sgptDataTables->nMonStatsTxtRecordCount)
                        {
                            if (nIndex == SKILLDESC_ValidateMonsterId(MONSTER_NATALYA))
                            {
                                nIndex = 382;
                                nType = 2;
                                nMode = 0;
                            }
                            else if (nIndex == SKILLDESC_ValidateMonsterId(MONSTER_COMPELLINGORB))
                            {
                                nIndex = 404;
                                nType = 2;
                                nMode = 0;
                            }
                        }
                    }
                    else if (nAct == 4)
                    {
                        if (nIndex < sgptDataTables->nMonStatsTxtRecordCount && nIndex >= 0)
                        {
                            switch (nIndex)
                            {
                            case 514:
                                nIndex = 461;
                                nType = 2;
                                nMode = 0;
                                break;
                            case 537:
                            case 538:
                            case 539:
                                nIndex = 1013 - nIndex;
                                nType = 2;
                                nMode = 0;
                                break;
                            }
                        }
                    }
                }
                break;

            case 2:
                if (nVersion > 5)
                {
                    if (nIndex < 150)
                    {
                        nIndex = gnPresetObjectIndices[nAct][nIndex];
                    }
                    else
                    {
                        nIndex -= 150;
                    }
                }
                else if (nIndex == 573)
                {
                    nIndex = -1;
                }
                break;

            case 4:
                if (nVersion > 4)
                {
                    char szCode[4];
                    strncpy(szCode, gpszPresetItemCodes[nIndex], 4);
                    szCode[3] = 0;
                    for (int j = 0; j < 3; ++j)
                    {
                        szCode[j] = tolower(szCode[j]);
                    }
                    unsigned int dwCode = 0;
                    DRLGPRESET_CopyCodePadded((D2PresetCodeStrc*)&dwCode, szCode);
                    DATATBLS_GetItemRecordFromItemCode(dwCode, &nIndex);
                }
                nMode = 3;
                break;
            }

            int nX = *pData++;
            int nY = *pData++;
            int nFlags = 0;
            if (nVersion > 5)
            {
                nFlags = *pData++;
            }

            if (nIndex >= 0 && (nType != 1 || nVersion > 4))
            {
                D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, 0, nType, nIndex, nMode, nX, nY);
                pPresetUnit->pNext = pDrlgFile->pPresetUnit;
                pDrlgFile->pPresetUnit = pPresetUnit;
                pPresetUnit->bSpawned |= nFlags;
            }
        }
    }

    if (nVersion >= 12 && sub_IsSubstMethod(pDrlgFile->nSubstMethod))
    {
        if (nVersion >= 18)
        {
            ++pData;
        }

        pDrlgFile->nSubstGroups = *pData++;
        pDrlgFile->pSubstGroups = (D2DrlgSubstGroupStrc*)FOG_AllocPool(0, sizeof(D2DrlgSubstGroupStrc) * pDrlgFile->nSubstGroups, ".\\DRLG\\Preset.cpp", 1142, 0);
        for (int i = 0; i < pDrlgFile->nSubstGroups; ++i)
        {
            pDrlgFile->pSubstGroups[i].tBox.nPosX = *pData++;
            pDrlgFile->pSubstGroups[i].tBox.nPosY = *pData++;
            pDrlgFile->pSubstGroups[i].tBox.nWidth = *pData++;
            pDrlgFile->pSubstGroups[i].tBox.nHeight = *pData++;
            if (nVersion >= 13)
            {
                pDrlgFile->pSubstGroups[i].nSubstGroup = *pData++;
            }
        }
    }

    if (nVersion >= 14)
    {
        int nNodes = *pData++;
        for (int i = 0; i < nNodes; ++i)
        {
            int nPoints = *pData++;
            int nX = *pData++;
            int nY = *pData++;
            if (nPoints)
            {
                D2PresetUnitStrc* pPresetUnit = pDrlgFile->pPresetUnit;
                while (pPresetUnit)
                {
                    if (pPresetUnit->nXpos == nX && pPresetUnit->nYpos == nY)
                    {
                        break;
                    }
                    pPresetUnit = pPresetUnit->pNext;
                }

                if (pPresetUnit)
                {
                    pPresetUnit->pMapAI = (D2MapAIStrc*)FOG_AllocPool(0, sizeof(D2MapAIStrc), ".\\DRLG\\Preset.cpp", 1192, 0);
                    pPresetUnit->pMapAI->pPosition = (D2MapAIPathPositionStrc*)FOG_AllocPool(0, sizeof(D2MapAIPathPositionStrc) * nPoints, ".\\DRLG\\Preset.cpp", 1193, 0);
                    pPresetUnit->pMapAI->nPathNodes = nPoints;
                    for (int j = 0; j < nPoints; ++j)
                    {
                        pPresetUnit->pMapAI->pPosition[j].nX = *pData++;
                        pPresetUnit->pMapAI->pPosition[j].nY = *pData++;
                        if (nVersion >= 15)
                        {
                            pPresetUnit->pMapAI->pPosition[j].nMapAIAction = *pData++;
                        }
                        else
                        {
                            pPresetUnit->pMapAI->pPosition[j].nMapAIAction = 1;
                        }
                    }
                }
                else
                {
                    pData += 2 * nPoints;
                    if (nVersion >= 15)
                    {
                        pData += nPoints;
                    }
                }
            }
        }
    }
}

// calling-convention shim (not game code)
int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId)
{

    return nMonsterId / sgptDataTables->nMonStatsTxtRecordCount;
}

static void __fastcall DRLGPRESET_AddTombStoneTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    int nTombStoneTiles = 0;

    if (pMaze->pTombStoneTiles)
    {
        return;
    }

    pMaze->pTombStoneTiles = (D2CoordStrc*)sub_0040B430(pMemPool, 6 * sizeof(D2CoordStrc), &gszDrlgPresetSourceFile, 1964, 0);

    for (int nY = 0; nY < pDrlgRoom->pDrlgCoord.nHeight; ++nY)
    {
        for (int nX = 0; nX < pDrlgRoom->pDrlgCoord.nWidth; ++nX)
        {
            const unsigned int nTileInfo = DRLGGRID_GetGridEntry(pMaze->pWallGrid, nX, nY);
            if (((unsigned char)(nTileInfo >> 20) & 0x3F) == 10 && (unsigned char)(nTileInfo >> 8) >= 23 && (unsigned char)(nTileInfo >> 8) <= 27)
            {
                if (nTombStoneTiles < 6)
                {
                    int nTileX = nX + pDrlgRoom->pDrlgCoord.nPosX;
                    int nTileY = nY + pDrlgRoom->pDrlgCoord.nPosY;
                    SKILLS_GameTileToSubtileCoords(&nTileX, &nTileY);
                    pMaze->pTombStoneTiles[nTombStoneTiles].nX = nTileX + 2;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nY = nTileY + 2;
                    ++nTombStoneTiles;
                }
            }
        }
    }

    pMaze->nTombStoneTiles = nTombStoneTiles;
}

static int DRLGPRESET_IsTileInsideCoord(D2DrlgCoordStrc* pDrlgCoord, D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc* pTileData)
{
    const int nX = pDrlgRoom->pDrlgCoord.nPosX + pTileData->nPosX;
    const int nY = pDrlgRoom->pDrlgCoord.nPosY + pTileData->nPosY;
    return DRLGROOM_AreXYInsideCoordinates(pDrlgCoord, nX, nY);
}

// 0x00665F40
void __fastcall DRLGPRESET_LoadDrlgFile(D2DrlgFileStrc** ppDrlgFile, void* hArchive, const char* szFile)
{
    EnterCriticalSection(&gLevelFilesCriticalSection);

    D2LevelFileListStrc* pLevelFile = gpLevelFilesList;
    if (gpLevelFilesList)
    {
        do
        {
            if (!strcmp(pLevelFile->szPath, szFile))
            {
                InterlockedIncrement(&pLevelFile->nRefCount);
                *ppDrlgFile = pLevelFile->pFile;
                LeaveCriticalSection(&gLevelFilesCriticalSection);
                return;
            }

            pLevelFile = pLevelFile->pNext;
        }
        while (pLevelFile);
    }

    D2LevelFileListStrc* pNewFile = (D2LevelFileListStrc*)sub_0040B430(0, sizeof(D2LevelFileListStrc), &gszDrlgPresetSourceFile, 1248, 0);
    *ppDrlgFile = (D2DrlgFileStrc*)sub_0040B430(0, sizeof(D2DrlgFileStrc), &gszDrlgPresetSourceFile, 1249, 0);
    memset(*ppDrlgFile, 0, sizeof(D2DrlgFileStrc));
    strcpy(pNewFile->szPath, szFile);
    D2LevelFileListStrc* pHead = gpLevelFilesList;
    pNewFile->nRefCount = 1;
    pNewFile->pFile = *ppDrlgFile;
    pNewFile->pNext = pHead;
    D2DrlgFileStrc* pNewDrlgFile = *ppDrlgFile;
    gpLevelFilesList = pNewFile;
    DRLGPRESET_ParseDS1File(pNewDrlgFile, hArchive, szFile);
    LeaveCriticalSection(&gLevelFilesCriticalSection);
}

// 0x00666070
static inline void DRLGPRESET_FindLevelFileListEntry(D2DrlgFileStrc** ppDrlgFile, D2LevelFileListStrc** ppPrevious, D2LevelFileListStrc** ppCurrent)
{
    D2LevelFileListStrc* pFirst = gpLevelFilesList;
    *ppPrevious = 0;
    for (*ppCurrent = pFirst; *ppCurrent; *ppCurrent = (*ppCurrent)->pNext)
    {
        if ((*ppCurrent)->pFile == *ppDrlgFile)
        {
            return;
        }
        *ppPrevious = *ppCurrent;
    }
}

// 0x006660B0
D2MapAIStrc* __fastcall DRLGPRESET_CreateCopyOfMapAI(void* pMemPool, D2MapAIStrc* pMapAI)
{
    D2MapAIStrc* pNewMapAI = (D2MapAIStrc*)sub_0040B430(pMemPool, sizeof(D2MapAIStrc), &gszDrlgPresetSourceFile, 1396, 0);
    memset(pNewMapAI, 0, sizeof(D2MapAIStrc));
    pNewMapAI->nPathNodes = pMapAI->nPathNodes;
    pNewMapAI->pPosition = (D2MapAIPathPositionStrc*)sub_0040B430(pMemPool, sizeof(D2MapAIPathPositionStrc) * pNewMapAI->nPathNodes, &gszDrlgPresetSourceFile, 1401, 0);
    memcpy(pNewMapAI->pPosition, pMapAI->pPosition, sizeof(D2MapAIPathPositionStrc) * pNewMapAI->nPathNodes);
    return pNewMapAI;
}

// 0x00666120
D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc** ppMapAI2)
{
    *ppMapAI2 = *ppMapAI1;
    *ppMapAI1 = 0;

    return *ppMapAI2;
}

// 0x00666130
void __fastcall DRLGPRESET_FreeMapAI(void* pMemPool, D2MapAIStrc* pMapAI)
{
    sub_0040B480(pMemPool, pMapAI->pPosition, &gszDrlgPresetSourceFile, 1431, 0);
    sub_0040B480(pMemPool, pMapAI, &gszDrlgPresetSourceFile, 1432, 0);
}

// 0x00666170
static void __stdcall DRLGPRESET_AddSpawnedObjectPresetUnit(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nIndex, int nX, int nY)
{
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 2, nIndex, 0, nX, nY);
    pPresetUnit->bSpawned |= 1;
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

// 0x006661A0
static void DRLGPRESET_SpawnRiver(D2DrlgMapStrc* pDrlgMap, int nX, int nY, void* pMemPool)
{
    int nSubtileX = nX;
    int nSubtileY = nY;
    int nEndSubtileX = 0;
    int nEndSubtileY = nY + pDrlgMap->ptFile->nHeight;

    SKILLS_GameTileToSubtileCoords(&nSubtileX, &nSubtileY);
    SKILLS_GameTileToSubtileCoords(&nEndSubtileX, &nEndSubtileY);

    while (nSubtileY < nEndSubtileY)
    {
        DRLGPRESET_AddSpawnedObjectPresetUnit(pDrlgMap, pMemPool, 65, nSubtileX, nSubtileY);
        nSubtileY += 40;
    }
}

static inline void __stdcall DRLGPRESET_AddRiverObject_Inline(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nIndex, int nX, int nY)
{
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 2, nIndex, 0, nX, nY);
    pPresetUnit->bSpawned |= 1;
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

// 0x00666220
static void __stdcall DRLGPRESET_AddPresetRiverObjects(D2DrlgMapStrc* pDrlgMap, void* pMemPool, int nOffsetX, D2DrlgGridStrc* pDrlgGrid)
{
    for (int nY = 0; nY < pDrlgMap->tCoords.nHeight; ++nY)
    {
        const int nX = nOffsetX > 0 ? nOffsetX : 0;
        int nObjectX = pDrlgMap->tCoords.nPosX + nOffsetX;
        int nObjectY = pDrlgMap->tCoords.nPosY + nY;
        DUNGEON_GameTileToSubtileCoords(&nObjectX, &nObjectY);
        nObjectX -= 5;

        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 40, nObjectX, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 5, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 10, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 41, nObjectX + 15, nObjectY);
        DRLGPRESET_AddRiverObject_Inline(pDrlgMap, pMemPool, 42, nObjectX + 20, nObjectY);
        const unsigned int nGridEntry = DRLGGRID_GetGridEntry(pDrlgGrid, nX, nY);
        if (((unsigned char)(nGridEntry >> 20) & 0x3F) == 4)
        {
            switch ((unsigned char)(nGridEntry >> 8))
            {
            case 0:
            case 4:
            case 8:
            case 16:
            case 29:
            case 39:
                nY += 3;
                break;

            default:
                break;
            }
        }
    }
}

// 0x006663C0
static void DRLGPRESET_SpawnMapRivers(D2DrlgMapStrc* pDrlgMap, void* pMemPool)
{
    D2DrlgCoordStrc tDrlgCoord;
    D2DrlgGridStrc tDrlgGrid;
    int nCellFlags[256];

    tDrlgCoord.nPosX = 0;
    tDrlgCoord.nPosY = 0;
    tDrlgCoord.nWidth = pDrlgMap->tCoords.nWidth;
    tDrlgCoord.nHeight = pDrlgMap->tCoords.nHeight;
    DRLGGRID_AssignCellsOffsetsAndFlags(&tDrlgGrid, (int*)pDrlgMap->ptFile->pFloorLayer[0], &tDrlgCoord, pDrlgMap->tCoords.nWidth + 1, nCellFlags);

    tDrlgCoord.nPosX = pDrlgMap->tCoords.nPosX;
    tDrlgCoord.nPosY = pDrlgMap->tCoords.nPosY;

    if (pDrlgMap->pLvlPrestTxtRecord->dwDef == 27)
    {
        DRLGPRESET_SpawnRiver(pDrlgMap, tDrlgCoord.nPosX - 1 + 1, tDrlgCoord.nPosY, pMemPool);
        DRLGPRESET_AddPresetRiverObjects(pDrlgMap, pMemPool, -1, &tDrlgGrid);
    }
    else
    {
        for (int nOffsetX = 0; nOffsetX < tDrlgCoord.nWidth; ++nOffsetX)
        {
            const unsigned int nGridEntry = DRLGGRID_GetGridEntry(&tDrlgGrid, nOffsetX, 0);
            if (((unsigned char)(nGridEntry >> 20) & 0x3F) == 2 && (unsigned char)(nGridEntry >> 8) == 24)
            {
                DRLGPRESET_SpawnRiver(pDrlgMap, tDrlgCoord.nPosX + nOffsetX + 1, tDrlgCoord.nPosY, pMemPool);
                DRLGPRESET_AddPresetRiverObjects(pDrlgMap, pMemPool, nOffsetX, &tDrlgGrid);
                nOffsetX += 4;
            }
        }
    }

    DRLGGRID_ResetGrid(&tDrlgGrid);
}

// 0x006664A0
static void __stdcall DRLGPRESET_AddNaviPresetUnit(D2DrlgMapStrc* pDrlgMap, void* pMemPool)
{
    int nX = pDrlgMap->tCoords.nPosX + pDrlgMap->tCoords.nWidth / 2;
    int nY = pDrlgMap->tCoords.nPosY + pDrlgMap->tCoords.nHeight / 2;
    SKILLS_GameTileToSubtileCoords(&nX, &nY);

    const int nClassId = sgptDataTables->nMonStatsTxtRecordCount <= 266 ? -1 : 266;
    D2PresetUnitStrc* pPresetUnit = DRLGROOM_AllocPresetUnit(0, pMemPool, 1, nClassId, 1, nX, nY);
    pPresetUnit->pNext = pDrlgMap->pPresetUnit;
    pDrlgMap->pPresetUnit = pPresetUnit;
}

// 0x00666520
static void __stdcall DRLGPRESET_FreeDrlgGrids(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze && pMaze->pMap)
    {
        D2DrlgFileStrc* pDrlgFile = pMaze->pMap->ptFile;
        if (pDrlgFile)
        {
            const int nWallLayers = pDrlgFile->nWallLayers;
            for (int i = 0; i < nWallLayers; ++i)
            {
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pTileTypeGrid[i]);
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pWallGrid[i]);
            }

            const int nFloorLayers = pDrlgFile->nFloorLayers;
            for (int i = 0; i < nFloorLayers; ++i)
            {
                DRLGGRID_FreeGrid(pMemPool, &pMaze->pFloorGrid[i]);
            }

            DRLGGRID_FreeGrid(pMemPool, &pMaze->pCellGrid);
        }
    }
}

// 0x006665B0
void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze)
    {
        DRLGPRESET_FreeDrlgGrids(pMemPool, pDrlgRoom);

        if (pMaze->pTombStoneTiles)
        {
            sub_0040B480(pMemPool, pMaze->pTombStoneTiles, &gszDrlgPresetSourceFile, 1783, 0);
        }

        sub_0040B480(pMemPool, pMaze, &gszDrlgPresetSourceFile, 1786, 0);
        pDrlgRoom->pMaze = 0;
    }
}

// 0x00666610
void __fastcall DRLGPRESET_FreeDrlgGridsFromPresetRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->pMaze)
    {
        DRLGPRESET_FreeDrlgGrids(pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, pDrlgRoom);
    }
}

// 0x00666630
void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = (D2DrlgPresetRoomStrc*)sub_0040B430(pDrlgRoom->ptDrlgLevel->pDrlg->pMempool, sizeof(D2DrlgPresetRoomStrc), &gszDrlgPresetSourceFile, 1807, 0);
    memset(pMaze, 0, sizeof(D2DrlgPresetRoomStrc));
    pDrlgRoom->pMaze = pMaze;
}

// 0x00666680
D2DrlgRoomStrc* __fastcall DRLGPRESET_InitPresetRoomData(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, D2DrlgCoordStrc* pDrlgCoord, unsigned int dwDT1Mask, int dwRoomFlags, int dwPresetFlags, D2DrlgGridStrc* pMazeGrid)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
    pDrlgRoom->dwDT1Mask = dwDT1Mask;
    pDrlgRoom->dwFlags |= dwRoomFlags;
    pDrlgRoom->pDrlgCoord.nPosX = pDrlgCoord->nPosX;
    pDrlgRoom->pDrlgCoord.nPosY = pDrlgCoord->nPosY;
    pDrlgRoom->pDrlgCoord.nWidth = pDrlgCoord->nWidth;
    pDrlgRoom->pDrlgCoord.nHeight = pDrlgCoord->nHeight;

    D2DrlgPresetRoomStrc* pDrlgPresetRoom = pDrlgRoom->pMaze;
    pDrlgPresetRoom->pMap = pDrlgMap;
    pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
    pDrlgPresetRoom->dwFlags = dwPresetFlags;
    pDrlgPresetRoom->pMazeGrid = pMazeGrid;

    if (pMazeGrid)
    {
        pMazeGrid->nHeight |= 1;
    }

    if (!pDrlgPresetRoom->pMap->pLvlPrestTxtRecord->dwPopulate)
    {
        pDrlgRoom->dwFlags |= 0x800000;
    }

    DRLGROOM_AddRoomExToLevel(pLevel, pDrlgRoom);
    return pDrlgRoom;
}

// 0x00666710
static void DRLGPRESET_MovePresetUnitsToRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgMapStrc* pDrlgMap = pDrlgRoom->pMaze->pMap;
    D2DrlgCoordStrc tDrlgCoord;
    tDrlgCoord.nPosX = pDrlgRoom->pDrlgCoord.nPosX;
    tDrlgCoord.nPosY = pDrlgRoom->pDrlgCoord.nPosY;
    tDrlgCoord.nWidth = pDrlgRoom->pDrlgCoord.nWidth;
    tDrlgCoord.nHeight = pDrlgRoom->pDrlgCoord.nHeight;
    SKILLS_GameTileToSubtileCoords(&tDrlgCoord.nPosX, &tDrlgCoord.nPosY);
    SKILLS_GameTileToSubtileCoords(&tDrlgCoord.nWidth, &tDrlgCoord.nHeight);

    D2PresetUnitStrc* pPresetUnit = pDrlgMap->pPresetUnit;
    const int nOffsetX = 5 * pDrlgRoom->pDrlgCoord.nPosX;
    D2PresetUnitStrc* pPrevious = 0;
    const int nOffsetY = 5 * pDrlgRoom->pDrlgCoord.nPosY;
    while (pPresetUnit)
    {
        if (DRLGROOM_AreXYInsideCoordinates(&tDrlgCoord, pPresetUnit->nXpos, pPresetUnit->nYpos))
        {
            pPresetUnit->nXpos -= nOffsetX;
            pPresetUnit->nYpos -= nOffsetY;

            if (pPrevious)
            {
                pPrevious->pNext = pPresetUnit->pNext;
            }
            else
            {
                pDrlgMap->pPresetUnit = pPresetUnit->pNext;
            }

            pPresetUnit->pNext = pDrlgRoom->pPresetUnits;
            pDrlgRoom->pPresetUnits = pPresetUnit;

            if (pPrevious)
            {
                pPresetUnit = pPrevious->pNext;
            }
            else
            {
                pPresetUnit = pDrlgMap->pPresetUnit;
            }
        }
        else
        {
            pPrevious = pPresetUnit;
            pPresetUnit = pPresetUnit->pNext;
        }
    }
}

// 0x006667D0
void __fastcall DRLGPRESET_InitPresetRoomGrids(D2DrlgRoomStrc* pDrlgRoom)
{
    int i = 0;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    D2DrlgMapStrc* pDrlgMap = pMaze->pMap;
    D2DrlgFileStrc* pDrlgFile = pDrlgMap->ptFile;
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    D2DrlgCoordStrc tDrlgCoord;
    tDrlgCoord.nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgMap->tCoords.nPosX;
    tDrlgCoord.nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgMap->tCoords.nPosY;
    tDrlgCoord.nWidth = pDrlgRoom->pDrlgCoord.nWidth + 1;
    tDrlgCoord.nHeight = pDrlgRoom->pDrlgCoord.nHeight + 1;

    const int nWidth = pDrlgMap->tCoords.nWidth + 1;

    for (i = 0; i < pDrlgFile->nWallLayers; ++i)
    {
        DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pWallGrid[i], (int*)pDrlgFile->pWallLayer[i], &tDrlgCoord, nWidth);
        DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pTileTypeGrid[i], (int*)pDrlgFile->pTileTypeLayer[i], &tDrlgCoord, nWidth);
    }

    if (pDrlgFile->nWallLayers)
    {
        DRLGGRID_AlterEdgeGridFlags(pMaze->pWallGrid, 0x84, 0);
    }

    for (i = 1; i < pDrlgFile->nWallLayers; ++i)
    {
        DRLGGRID_AlterAllGridFlags(&pMaze->pWallGrid[i], i << 18, 0);
    }

    for (i = 0; i < pDrlgFile->nFloorLayers; ++i)
    {
        DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pFloorGrid[i], (int*)pDrlgFile->pFloorLayer[i], &tDrlgCoord, nWidth);
        DRLGGRID_AlterAllGridFlags(&pMaze->pFloorGrid[i], i << 18, 0);
    }

    DRLGGRID_FillNewCellFlags(pMemPool, &pMaze->pCellGrid, (int*)pDrlgFile->pShadowLayer, &tDrlgCoord, nWidth);

    for (i = 0; i < pDrlgFile->nFloorLayers; ++i)
    {
        DRLGGRID_AlterEdgeGridFlags(&pMaze->pFloorGrid[i], 0x84, 0);
    }

    DRLGGRID_AlterEdgeGridFlags(&pMaze->pCellGrid, 0x84, 0);
    DRLGPRESET_MovePresetUnitsToRoom(pDrlgRoom);
}

// 0x00666990
static void DRLGPRESET_FindTombStoneTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    int nTombStoneTiles = 0;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    if (pMaze->pTombStoneTiles)
        return;

    pMaze->pTombStoneTiles = (D2CoordStrc*)FOG_AllocPool(pMemPool, 6 * sizeof(D2CoordStrc), gszDrlgPresetSourceFile_006EE7C4, 1964, 0);
    for (int i = 0; i < pDrlgRoom->pDrlgCoord.nHeight; ++i)
    {
        for (int j = 0; j < pDrlgRoom->pDrlgCoord.nWidth; ++j)
        {
            const unsigned int nPacked = DRLGGRID_GetGridEntry(pMaze->pWallGrid, j, i);
            const unsigned char nTileStyle = (nPacked >> 20) & 0x3F;
            const unsigned char nTileSequence = (unsigned char)(nPacked >> 8);
            if (nTileStyle == 10 && nTileSequence >= 23 && nTileSequence <= 27)
            {
                if (nTombStoneTiles < 6)
                {
                    int nY;
                    int nX;
                    nX = j + pDrlgRoom->pDrlgCoord.nPosX;
                    nY = i + pDrlgRoom->pDrlgCoord.nPosY;
                    DUNGEON_GameTileToSubtileCoords(&nX, &nY);
                    nX += 2;
                    nY += 2;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nX = nX;
                    pMaze->pTombStoneTiles[nTombStoneTiles].nY = nY;
                    ++nTombStoneTiles;
                }
            }
        }
    }
    pMaze->nTombStoneTiles = nTombStoneTiles;
}

// 0x00666A80
void __fastcall DRLGPRESET_GetTombStoneTileCoords(D2DrlgRoomStrc* pDrlgRoom, D2CoordStrc** ppTombStoneTiles, int* pnTombStoneTiles)
{
    if (pDrlgRoom->nType != 2)
    {
        *ppTombStoneTiles = 0;
        *pnTombStoneTiles = 0;
    }
    else
    {
        D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
        *ppTombStoneTiles = pMaze->pTombStoneTiles;
        *pnTombStoneTiles = pMaze->nTombStoneTiles;
    }
}

// 0x00666AC0
void __fastcall DRLGPRESET_AddPresetRoomMapTiles(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGROOMTILE_AllocTileGrid(pDrlgRoom);

    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    D2DrlgMapStrc* pMazeMap = pMaze->pMap;
    const int bAnimate = pMazeMap->pLvlPrestTxtRecord->dwAnimate;
    const int bFillBlanks = pMazeMap->pLvlPrestTxtRecord->dwFillBlanks;

    int bKillEdgeX = 0;
    int bKillEdgeY = 0;
    if (pMazeMap->pLvlPrestTxtRecord->dwKillEdge)
    {
        bKillEdgeX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth == pMazeMap->tCoords.nPosX + pMazeMap->tCoords.nWidth;
        bKillEdgeY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight == pMazeMap->tCoords.nPosY + pMazeMap->tCoords.nHeight;
    }

    D2DrlgGridStrc tTileTypeGrid;
    D2DrlgGridStrc tTileInfoGrid;
    int aTileTypeCellPos[1024];
    int aTileTypeCellFlags[256];
    int aTileInfoCellPos[1024];
    int aTileInfoCellFlags[256];
    int bTownOrGraveyard = 0;
    switch (pDrlgRoom->pMaze->nLevelPrest)
    {
    case 1:
    case 108:
        bTownOrGraveyard = 1;
        DRLGGRID_FillGrid(&tTileTypeGrid, pDrlgRoom->pDrlgCoord.nWidth + 1, pDrlgRoom->pDrlgCoord.nHeight + 1, aTileTypeCellPos, aTileTypeCellFlags);
        DRLGGRID_FillGrid(&tTileInfoGrid, pDrlgRoom->pDrlgCoord.nWidth + 1, pDrlgRoom->pDrlgCoord.nHeight + 1, aTileInfoCellPos, aTileInfoCellFlags);
        break;
    }

    const int nWallLayers = pMaze->pMap->ptFile->nWallLayers;
    const int nFloorLayers = pMaze->pMap->ptFile->nFloorLayers;

    for (int i = 0; i < nFloorLayers; ++i)
    {
        DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &pMaze->pFloorGrid[i], i == 0 && bFillBlanks, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pFloorGrid[i], 0, 0, bKillEdgeX, bKillEdgeY);
        }
    }

    for (int i = 0; i < nWallLayers; ++i)
    {
        DRLGROOMTILE_CountWallWarpTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], bKillEdgeX, bKillEdgeY);
        DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &pMaze->pWallGrid[i], 0, bKillEdgeX, bKillEdgeY);
        if (bAnimate)
        {
            DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], 0, bKillEdgeX, bKillEdgeY);
        }
    }

    DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &pMaze->pCellGrid, 0, bKillEdgeX, bKillEdgeY);
    if (bAnimate)
    {
        DRLGANIM_TestLoadAnimatedRoomTiles(pDrlgRoom, &pMaze->pCellGrid, 0, 13, bKillEdgeX, bKillEdgeY);
    }

    if (bTownOrGraveyard)
    {
        DRLGROOMTILE_CountAllTileTypes(pDrlgRoom, &tTileInfoGrid, 0, bKillEdgeX, bKillEdgeY);
    }

    DRLGROOMTILE_AllocTileData(pDrlgRoom);

    for (int i = 0; i < nFloorLayers; ++i)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pFloorGrid[i], 0, i == 0 && bFillBlanks, bKillEdgeX, bKillEdgeY);
    }

    for (int i = 0; i < nWallLayers; ++i)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pWallGrid[i], &pMaze->pTileTypeGrid[i], 0, bKillEdgeX, bKillEdgeY);
    }

    DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &pMaze->pCellGrid, 0, 0, bKillEdgeX, bKillEdgeY);

    if (bTownOrGraveyard)
    {
        DRLGROOMTILE_LoadInitRoomTiles(pDrlgRoom, &tTileInfoGrid, &tTileTypeGrid, 0, bKillEdgeX, bKillEdgeY);
    }

    if (bAnimate)
    {
        DRLGANIM_AllocAnimationTileGrids(pDrlgRoom, pMaze->pMap->pLvlPrestTxtRecord->nAnimSpeed, pMaze->pWallGrid, nWallLayers, pMaze->pFloorGrid, nFloorLayers, &pMaze->pCellGrid);
    }

    D2DrlgTileGridStrc* pTileGrid = pDrlgRoom->ptDrlgTiles;
    D2DrlgRoomTilesStrc* pTiles = &pTileGrid->pTiles;
    pTiles->nWalls = pTileGrid->nWalls;
    pTiles->nFloors = pTileGrid->nFloors;
    pTiles->nRoofs = pTileGrid->nShadows;

    if (pMaze->pMap->pLvlPrestTxtRecord->dwLogicals)
    {
        DRLGLOGIC_InitializeDrlgCoordList(pDrlgRoom, pMaze->pTileTypeGrid, pMaze->pFloorGrid, pMaze->pWallGrid);
    }
    else
    {
        DRLGLOGIC_AllocCoordLists(pDrlgRoom);
    }

    if (bTownOrGraveyard)
    {
        DRLGGRID_ResetGrid(&tTileTypeGrid);
        DRLGGRID_ResetGrid(&tTileInfoGrid);
    }

    if (pDrlgRoom->ptDrlgLevel->eLevelId == LEVEL_BURIALGROUNDS)
    {
        DRLGPRESET_FindTombStoneTiles(pMemPool, pDrlgRoom);
    }
}

// 0x00666E00
static void __stdcall DRLGPRESET_InitPopsLocations(D2DrlgMapStrc* pDrlgMap, int nPops)
{
    pDrlgMap->nPops = nPops;

    for (int i = 0; i < nPops; ++i)
    {
        D2DrlgCoordStrc* pPopsLocation = &pDrlgMap->pPopsLocation[i];
        const int nX1 = pPopsLocation->nPosX < pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY1 = pPopsLocation->nPosY < pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;
        const int nX2 = pPopsLocation->nPosX > pPopsLocation->nWidth ? pPopsLocation->nPosX : pPopsLocation->nWidth;
        const int nY2 = pPopsLocation->nPosY > pPopsLocation->nHeight ? pPopsLocation->nPosY : pPopsLocation->nHeight;

        pPopsLocation->nPosX = nX1 + pDrlgMap->tCoords.nPosX;
        pPopsLocation->nPosY = nY1 + pDrlgMap->tCoords.nPosY;
        pPopsLocation->nWidth = nX2 - nX1 + 1;
        pPopsLocation->nHeight = nY2 - nY1 + 1;
        pDrlgMap->pPopsIndex[i] = pDrlgMap->pPopsIndex[i] / 4 - 1;
    }
}

void __fastcall sub_Z16_EmitTombStoneTiles(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool)
{
    if (pDrlgRoom->pDrlgCoord.nWidth == 9)
        DRLGPRESET_FindTombStoneTiles(pMemPool, pDrlgRoom);
}

unsigned short __stdcall SFileGetLocale()
{
    return gwValue_0077905C;
}

void __stdcall sub_00416750_Nop()
{
}

void __stdcall sub_00416760_Nop()
{
}

char* __fastcall sub_004167A0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}

char* __fastcall sub_004167F0_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00666EB0
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

// 0x00666EC0
int __fastcall DRLGPRESET_SetPickedFileInDrlgMap(D2DrlgMapStrc* pDrlgMap, int nPickedFile)
{
    return pDrlgMap->nPickedFile = nPickedFile;
}

char* __fastcall sub_00416820_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416830_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416840_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

char* __fastcall sub_00416850_LinkNext(D2StormLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

char* __fastcall sub_00416860_LinkPrev(D2StormLinkStrc* pLink)
{
    D2StormLinkStrc* pPrev = pLink->m_prevlink->m_prevlink;
    return (int)pPrev->m_next > 0 ? pPrev->m_next : 0;
}

char* __fastcall sub_00416880_LinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}

void __fastcall sub_004169F0_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A00_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A10_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A20_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

void __fastcall sub_00416A30_InitTerminator(D2StormListStrc* pList)
{
    pList->m_terminator.m_prevlink = &pList->m_terminator;
    pList->m_terminator.m_next = (char*)~(unsigned int)&pList->m_terminator;
}

int __fastcall sub_00416A90_TestField150(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n150)
        return 1;
    return 0;
}

int __fastcall sub_00416AB0_TestField14C(D2Storm416A90Strc* pRecord)
{
    if (pRecord && pRecord->n14C)
        return 1;
    return 0;
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

// 0x00666ED0
D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed)
{
    D2DrlgMapStrc* pDrlgMap = (D2DrlgMapStrc*)FOG_AllocPool(pLevel->pDrlg->pMempool, sizeof(D2DrlgMapStrc), &gszDrlgPresetSourceFile, 2477, 0);
    memset(pDrlgMap, 0x00, sizeof(D2DrlgMapStrc));

    pDrlgMap->pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId);
    pDrlgMap->nLevelPrest = nLvlPrestId;

    pDrlgMap->nPickedFile = SEED_RollLimitedRandomNumber(pSeed, pDrlgMap->pLvlPrestTxtRecord->dwFiles);
    pDrlgMap->tCoords.nPosX = pDrlgCoord->nPosX;
    pDrlgMap->tCoords.nPosY = pDrlgCoord->nPosY;

    if (pDrlgMap->pLvlPrestTxtRecord->nSizeX && pDrlgMap->pLvlPrestTxtRecord->nSizeY)
    {
        pDrlgMap->tCoords.nWidth = pDrlgMap->pLvlPrestTxtRecord->nSizeX;
        pDrlgMap->tCoords.nHeight = pDrlgMap->pLvlPrestTxtRecord->nSizeY;
    }
    else
    {
        pDrlgMap->tCoords.nWidth = pDrlgCoord->nWidth;
        pDrlgMap->tCoords.nHeight = pDrlgCoord->nHeight;
    }

    pDrlgMap->bInited = 1;
    pDrlgMap->pNext = pLevel->pCurrentMap;
    pLevel->pCurrentMap = pDrlgMap;

    return pDrlgMap;
}

// 0x00666FD0
int __fastcall DRLGPRESET_GetSizeX(int nLvlPrestId)
{
    return DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId)->nSizeX;
}

// 0x00666FE0
int __fastcall DRLGPRESET_GetSizeY(int nLvlPrestId)
{
    return DATATBLS_GetLvlPrestTxtRecord(nLvlPrestId)->nSizeY;
}

void __stdcall sub_M121_Emit_00666070(D2DrlgFileStrc** ppDrlgFile, D2LevelFileListStrc** ppPrevious, D2LevelFileListStrc** ppCurrent)
{
    DRLGPRESET_FindLevelFileListEntry(ppDrlgFile, ppPrevious, ppCurrent);
}

// 0x00666FF0
int __fastcall DRLGPRESET_GetMazeGridFromRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    return (int)pDrlgRoom->pMaze->pMazeGrid;
}

// 0x00667000
int __fastcall DRLGPRESET_GetLevelPrestIdFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->pMaze->nLevelPrest;
}

// 0x00667010
char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    return pMaze->pMap->pLvlPrestTxtRecord->szFile[pMaze->pMap->nPickedFile];
}

struct D2Unk00667030InnerStrc
{
    int nValue0;
    int nValue1;
};

struct D2Unk00667030MidStrc
{
    char unk0x00[0x08];
    D2Unk00667030InnerStrc* pInner;
};

struct D2Unk00667030Strc
{
    char unk0x00[0x20];
    D2Unk00667030MidStrc* pMid;
};

// 0x00667030
void __fastcall DRLGPRESET_GetInnerPair(D2Unk00667030Strc* pRecord, int* pValue0, int* pValue1)
{
    D2Unk00667030MidStrc* pMid = pRecord->pMid;
    if (pValue0)
    {
        *pValue0 = pMid->pInner->nValue0;
    }
    if (pValue1)
    {
        *pValue1 = pMid->pInner->nValue1;
    }
}

// 0x00667060
static void __stdcall DRLGPRESET_TogglePopsVisibility(D2DrlgRoomStrc* ptRoom, int nPopSubIndex, D2DrlgCoordStrc* pDrlgCoord, int nTick, int bClose)
{
    if (!ptRoom->ptDrlgTiles)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 2619);
        exit(-1);
    }

    D2DrlgCoordStrc tDrlgCoord = { 0 };
    tDrlgCoord.nPosX = pDrlgCoord->nPosX - 1;
    tDrlgCoord.nPosY = pDrlgCoord->nPosY - 1;
    tDrlgCoord.nWidth = pDrlgCoord->nWidth + 2;
    tDrlgCoord.nHeight = pDrlgCoord->nHeight + 2;

    const int nWalls = ptRoom->ptDrlgTiles->nTileWalls;
    D2DrlgTileDataStrc* pWallTiles = ptRoom->ptDrlgTiles->pTiles.pWallTiles;
    for (int i = 0; i < nWalls; ++i)
    {
        D2DrlgTileDataStrc* pTileData = &pWallTiles[i];
        if (pTileData->dwFlags & 0x200 && DRLGPRESET_IsTileInsideCoord(&tDrlgCoord, ptRoom, pTileData))
        {
            if (bClose)
            {
                pTileData->dwPopFlags |= 4;
                pTileData->nPopTick = nTick;
            }
            else
            {
                pTileData->dwPopFlags &= ~4;
                pTileData->dwFlags &= ~8;
            }
        }
        else if (!(pTileData->dwFlags & 0x100) && sub_00604B90(pTileData->pTile) == nPopSubIndex && DRLGPRESET_IsTileInsideCoord(&tDrlgCoord, ptRoom, pTileData))
        {
            pTileData->dwPopFlags |= 2;
            if (bClose)
            {
                pTileData->nGreen = 0;
                pTileData->nBlue = 255;
                if (!pTileData->nRed)
                {
                    pTileData->nPopTick = nTick;
                }
                else
                {
                    pTileData->nPopTick = nTick - 500 * pTileData->nRed / 255;
                }
            }
            else
            {
                pTileData->nGreen = 255;
                pTileData->nBlue = 0;
                if (pTileData->nRed == 255)
                {
                    pTileData->nPopTick = nTick;
                }
                else
                {
                    pTileData->nPopTick = nTick + 500 * (pTileData->nRed - 255) / 255;
                }
            }
        }
    }
}

// 0x00668240
void __fastcall DRLGPRESET_FreeDrlgFileData(D2DrlgFileStrc* pDrlgFile)
{
    if (pDrlgFile->pDS1File)
    {
        FOG_Free(pDrlgFile->pDS1File, &gszDrlgPresetSourceFile, 1272, 0);
    }

    if (pDrlgFile->pSubstGroups)
    {
        sub_0040B480(0, pDrlgFile->pSubstGroups, &gszDrlgPresetSourceFile, 1273, 0);
    }

    D2PresetUnitStrc* pNext = pDrlgFile->pPresetUnit;
    while (pNext)
    {
        D2PresetUnitStrc* pPresetUnit = pNext;
        pNext = pPresetUnit->pNext;
        DRLGPRESET_FreePresetUnit(0, pPresetUnit);
    }

    sub_0040B480(0, pDrlgFile, &gszDrlgPresetSourceFile, 1285, 0);
}

// 0x00668300
void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile)
{
    if (!*ppDrlgFile)
    {
        return;
    }

    EnterCriticalSection(&gLevelFilesCriticalSection);

    D2LevelFileListStrc* pPrevious = 0;
    D2LevelFileListStrc* pCurrent = gpLevelFilesList;
    while (pCurrent && pCurrent->pFile != *ppDrlgFile)
    {
        pPrevious = pCurrent;
        pCurrent = pCurrent->pNext;
    }

    InterlockedDecrement(&pCurrent->nRefCount);

    if (pCurrent && pCurrent->nRefCount <= 0)
    {
        if (pPrevious)
        {
            pPrevious->pNext = pCurrent->pNext;
        }
        else
        {
            gpLevelFilesList = pCurrent->pNext;
        }

        LeaveCriticalSection(&gLevelFilesCriticalSection);
        DRLGPRESET_FreeDrlgFileData(*ppDrlgFile);
        sub_0040B480(0, pCurrent, &gszDrlgPresetSourceFile, 1336, 0);
        *ppDrlgFile = 0;
    }
    else
    {
        LeaveCriticalSection(&gLevelFilesCriticalSection);
    }
}

static inline int DRLGPRESET_GetFileCount(D2LvlPrestTxt* pLvlPrestTxtRecord)
{
	return pLvlPrestTxtRecord->dwFiles;
}

// 0x00667510
D2PresetUnitStrc* __fastcall DRLGPRESET_CopyPresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit, int nX, int nY)
{
    D2PresetUnitStrc* pNewPresetUnit = (D2PresetUnitStrc*)sub_0040B430(pMemPool, sizeof(D2PresetUnitStrc), &gszDrlgPresetSourceFile, 1354, 0);
    memset(pNewPresetUnit, 0, sizeof(D2PresetUnitStrc));
    pNewPresetUnit->nUnitType = pPresetUnit->nUnitType;
    pNewPresetUnit->nIndex = pPresetUnit->nIndex;
    pNewPresetUnit->nMode = pPresetUnit->nMode;
    pNewPresetUnit->nXpos = nX + pPresetUnit->nXpos;
    pNewPresetUnit->nYpos = nY + pPresetUnit->nYpos;
    pNewPresetUnit->bSpawned = pPresetUnit->bSpawned;

    if (pPresetUnit->pMapAI)
    {
        pNewPresetUnit->pMapAI = DRLGPRESET_CreateCopyOfMapAI(pMemPool, pPresetUnit->pMapAI);

        for (unsigned int i = 0; i < (unsigned int)pNewPresetUnit->pMapAI->nPathNodes; ++i)
        {
            pNewPresetUnit->pMapAI->pPosition[i].nX += nX;
            pNewPresetUnit->pMapAI->pPosition[i].nY += nY;
        }
    }

    return pNewPresetUnit;
}

// 0x006675D0
void __fastcall DRLGPRESET_FreePresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit)
{
    if (pPresetUnit->pMapAI)
    {
        DRLGPRESET_FreeMapAI(pMemPool, pPresetUnit->pMapAI);
    }

    sub_0040B480(pMemPool, pPresetUnit, &gszDrlgPresetSourceFile, 1387, 0);
}

// 0x00667890
void __fastcall DRLGPRESET_SpawnHardcodedPresetUnits(D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgMapStrc* pDrlgMap = pDrlgRoom->pMaze->pMap;
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;
    if (!pDrlgMap->ptFile)
    {
        DRLGPRESET_LoadDrlgFile(&pDrlgMap->ptFile, pDrlgRoom->ptDrlgLevel->pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
        DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pDrlgRoom->pSeed);
    }

    if (pDrlgMap->bInited == 1)
    {
        pDrlgMap->bInited = 0;

        switch (pDrlgMap->nLevelPrest)
        {
        case 4:
        case 5:
        case 6:
        case 7:
            if (pDrlgRoom->ptDrlgLevel->eLevelId == LEVEL_BLOODMOOR && pDrlgMap->nPickedFile == 3)
            {
                DRLGPRESET_AddNaviPresetUnit(pDrlgMap, pMemPool);
            }
            break;

        case 1:
        case 3:
        case 26:
        case 27:
        case 28:
        case 300:
            if (pDrlgRoom->dwFlags & 0x40000)
            {
                DRLGPRESET_SpawnMapRivers(pDrlgMap, pMemPool);
            }
            break;

        default:
            break;
        }
    }

    pDrlgRoom->dwFlags |= 0x2000000;
}

// 0x00667970
static void __stdcall DRLGPRESET_BuildPresetArea(D2DrlgLevelStrc* pLevel, D2DrlgGridStrc* pDrlgGrid, int nFlags, int bSingleRoom, D2DrlgMapStrc* pDrlgMap)
{
    D2DrlgStrc* pDrlg = pLevel->pDrlg;
    void* pMemPool = pDrlg->pMempool;
    int* pVisArray = DRLGROOM_GetVisArrayFromLevelId(pDrlg, pLevel->eLevelId);
    int nWarpFlag = 0x10;
    for (int i = 0; i < 8; ++i)
    {
        if (pVisArray[i] && DRLGWARP_GetWarpDestinationFromArray(pLevel, i) == -1)
        {
            nFlags |= nWarpFlag;
        }

        nWarpFlag <<= 1;
    }

    DRLGGRID_AlterAllGridFlags(pDrlgGrid, nFlags, 0);

    const int bScan = pDrlgMap->pLvlPrestTxtRecord->dwScan;
    const int nPops = pDrlgMap->pLvlPrestTxtRecord->dwPops;
    int nProcessedPops = 0;

    if (!bScan && !nPops)
    {
        return;
    }

    DRLGPRESET_LoadDrlgFile(&pDrlgMap->ptFile, pDrlg->hArchive, pDrlgMap->pLvlPrestTxtRecord->szFile[pDrlgMap->nPickedFile]);
    DRLGPRESET_AddPresetUnitToDrlgMap(pMemPool, pDrlgMap, &pLevel->pSeed);

    D2_ASSERT(pDrlgMap->ptFile->nWidth == pDrlgMap->tCoords.nWidth, 0x8B9);
    D2_ASSERT(pDrlgMap->ptFile->nHeight == pDrlgMap->tCoords.nHeight, 0x8BA);

    if (nPops)
    {
        pDrlgMap->pPopsIndex = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8BF, 0);
        pDrlgMap->pPopsSubIndex = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C0, 0);
        pDrlgMap->pPopsOrientation = (int*)FOG_AllocPool(pMemPool, sizeof(int) * nPops, &gszDrlgPresetSourceFile, 0x8C1, 0);
        pDrlgMap->pPopsLocation = (D2DrlgCoordStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgCoordStrc) * nPops, &gszDrlgPresetSourceFile, 0x8C2, 0);
    }

    memset(pDrlgMap->pPopsIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsSubIndex, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsOrientation, 0, sizeof(int) * nPops);
    memset(pDrlgMap->pPopsLocation, 0, sizeof(D2DrlgCoordStrc) * nPops);

    D2DrlgFileStrc* pFile = pDrlgMap->ptFile;
    D2DrlgCoordStrc tDrlgCoord = { 0 };
    D2DrlgGridStrc tTileTypeGrid = { 0 };
    D2DrlgGridStrc tWallGrid = { 0 };
    int nTileTypeCellFlags[0x100];
    int nWallCellFlags[0x100];

    tDrlgCoord.nWidth = pFile->nWidth + 1;
    tDrlgCoord.nHeight = pFile->nHeight + 1;

    for (int i = 0; i < pFile->nWallLayers; ++i)
    {
        DRLGGRID_AssignCellsOffsetsAndFlags(&tTileTypeGrid, (int*)pFile->pTileTypeLayer[i], &tDrlgCoord, pFile->nWidth + 1, nTileTypeCellFlags);
        DRLGGRID_AssignCellsOffsetsAndFlags(&tWallGrid, (int*)pFile->pWallLayer[i], &tDrlgCoord, pFile->nWidth + 1, nWallCellFlags);

        for (int nY = 0; nY < pFile->nHeight; ++nY)
        {
            for (int nX = 0; nX < pFile->nWidth; ++nX)
            {
                const int nTileType = DRLGGRID_GetGridEntry(&tTileTypeGrid, nX, nY);
                const int nWallFlags = DRLGGRID_GetGridEntry(&tWallGrid, nX, nY);
                const unsigned int nIndex = ((unsigned int)nWallFlags >> 0x14) & 0x3F;
                const int nSubIndex = (nWallFlags >> 8) & 0xFF;
                const int nUpperBit = nWallFlags & 0x80000000;

                if (nTileType == 0xB || nTileType == 0xA)
                {
                    if (bScan && nIndex <= 7 && (nSubIndex == 0 || nSubIndex == 4 || nUpperBit))
                    {
                        int nGridX;
                        int nGridY;
                        if (bSingleRoom)
                        {
                            nGridX = 0;
                            nGridY = 0;
                        }
                        else
                        {
                            nGridX = nX / 8;
                            nGridY = nY / 8;
                        }

                        DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 1 << (nIndex + 4), 0);
                    }

                    if (nPops && nIndex >= 8 && nIndex <= 0x1D)
                    {
                        int nCounter = 0;
                        while (nCounter < nProcessedPops)
                        {
                            if (pDrlgMap->pPopsIndex[nCounter] == nIndex)
                            {
                                pDrlgMap->pPopsLocation[nCounter].nWidth = nX;
                                pDrlgMap->pPopsLocation[nCounter].nHeight = nY;
                                break;
                            }

                            ++nCounter;
                        }

                        if (nCounter == nProcessedPops)
                        {
                            pDrlgMap->pPopsIndex[nProcessedPops] = nIndex;
                            pDrlgMap->pPopsSubIndex[nProcessedPops] = nSubIndex;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosX = nX;
                            pDrlgMap->pPopsLocation[nProcessedPops].nPosY = nY;
                            ++nProcessedPops;
                        }
                    }

                    if (bScan && nIndex >= 0x1E && nIndex <= 0x21)
                    {
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosX = nX + pDrlgMap->tCoords.nPosX;
                        pLevel->pTileInfo[pLevel->nTileInfo].nPosY = nY + pDrlgMap->tCoords.nPosY;

                        switch (nIndex)
                        {
                        case 0x1E:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex;
                            break;

                        case 0x1F:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = nSubIndex + 5;
                            break;

                        case 0x20:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xA;
                            break;

                        case 0x21:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xB;
                            break;

                        case 0x22:
                            pLevel->pTileInfo[pLevel->nTileInfo].nTileIndex = 0xC;
                            break;
                        }

                        ++pLevel->nTileInfo;
                    }
                }
            }
        }

        DRLGGRID_ResetGrid(&tWallGrid);
        DRLGGRID_ResetGrid(&tTileTypeGrid);
    }

    if (nPops)
    {
        DRLGPRESET_InitPopsLocations(pDrlgMap, nProcessedPops);
    }

    if (bScan)
    {
        for (D2PresetUnitStrc* pPresetUnit = pFile->pPresetUnit; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
        {
            if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 0x23D && DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40)
            {
                int nGridX;
                int nGridY;
                if (bSingleRoom)
                {
                    nGridX = 0;
                    nGridY = 0;
                }
                else
                {
                    nGridX = pPresetUnit->nXpos / 5 / 8;
                    nGridY = pPresetUnit->nYpos / 5 / 8;
                }

                DRLGGRID_AlterGridFlag(pDrlgGrid, nGridX, nGridY, 0x30000, 0);
            }
        }
    }
}

static inline int DRLGPRESET_GetMonsterId(int nMonsterId, int nMonStatsCount)
{
    if (nMonsterId >= 0 && nMonsterId < nMonStatsCount)
    {
        return nMonsterId;
    }

    return -1;
}

// 0x00667620
void __fastcall DRLGPRESET_AddPresetUnitToDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap, D2SeedStrc* pSeed)
{
    D2PresetUnitStrc* pPresetUnit = pDrlgMap->ptFile->pPresetUnit;
    int nX = pDrlgMap->tCoords.nPosX;
    int nY = pDrlgMap->tCoords.nPosY;
    DUNGEON_GameTileToSubtileCoords(&nX, &nY);

    for (; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
    {
        switch (pPresetUnit->nUnitType)
        {
        case 1:
        {
            const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
            if (pPresetUnit->nIndex < nMonStatsCount)
            {
                switch (DRLGPRESET_GetMonsterId(pPresetUnit->nIndex, nMonStatsCount))
                {
                case MONSTER_ACT2VENDOR1:
                case MONSTER_ACT2VENDOR2:
                case MONSTER_LIGHTNINGSPIRE:
                case MONSTER_FIRETOWER:
                    if (SEED_RollRandomNumber(pSeed) % 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            else if (pPresetUnit->nIndex - nMonStatsCount >= DATATBLS_GetSuperUniquesTxtRecordCount())
            {
                const int nCount = sgptDataTables->nMonStatsTxtRecordCount;
                switch (pPresetUnit->nIndex - nCount - DATATBLS_GetSuperUniquesTxtRecordCount())
                {
                case 33:
                    if (!(SEED_RollRandomNumber(pSeed) & 3))
                    {
                        continue;
                    }
                    break;

                case 34:
                    if (!(SEED_RollRandomNumber(pSeed) & 1))
                    {
                        continue;
                    }
                    break;

                case 35:
                    if (SEED_RollRandomNumber(pSeed) & 3)
                    {
                        continue;
                    }
                    break;
                }
            }
            break;
        }

        case 2:
            switch (pPresetUnit->nIndex)
            {
            case 196:
            case 261:
                if (SEED_RollRandomNumber(pSeed) & 1)
                {
                    continue;
                }
                break;

            case 581:
                if (!(SEED_RollRandomNumber(pSeed) & 3))
                {
                    continue;
                }
                break;
            }
            break;
        }

        D2PresetUnitStrc* pNew = DRLGPRESET_CopyPresetUnit(pMemPool, pPresetUnit, nX, nY);
        pNew->pNext = pDrlgMap->pPresetUnit;
        pDrlgMap->pPresetUnit = pNew;
    }
}

// 0x00667ED0
D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom)
{
    int nCellPos[0x400];
    int nCellFlags[0x100];
    D2DrlgGridStrc tDrlgGrid;

    const int nGridWidth = pDrlgMap->tCoords.nWidth / 8 + 1;
    const int nGridHeight = pDrlgMap->tCoords.nHeight / 8 + 1;
    if (pDrlgMap->pLvlPrestTxtRecord->dwOutdoors)
    {
        nFlags |= 0x80000;
    }

    DRLGGRID_FillGrid(&tDrlgGrid, nGridWidth, nGridHeight, nCellPos, nCellFlags);
    DRLGPRESET_BuildPresetArea(pLevel, &tDrlgGrid, nFlags, bSingleRoom, pDrlgMap);

    const unsigned int dwDT1Mask = pDrlgMap->pLvlPrestTxtRecord->dwDt1Mask;
    D2DrlgRoomStrc* pDrlgRoom = 0;
    if (bSingleRoom)
    {
        const int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, 0, 0);
        D2DrlgRoomStrc* pRoom = DRLGROOM_AllocRoomEx(pLevel, 2);
        pRoom->dwDT1Mask = dwDT1Mask;
        pRoom->dwFlags |= nGridFlags;
        pRoom->pDrlgCoord.nPosX = pDrlgMap->tCoords.nPosX;
        pRoom->pDrlgCoord.nPosY = pDrlgMap->tCoords.nPosY;
        pRoom->pDrlgCoord.nWidth = pDrlgMap->tCoords.nWidth;
        pRoom->pDrlgCoord.nHeight = pDrlgMap->tCoords.nHeight;

        D2DrlgPresetRoomStrc* pDrlgPresetRoom = pRoom->pMaze;
        pDrlgPresetRoom->pMap = pDrlgMap;
        pDrlgPresetRoom->nLevelPrest = pDrlgMap->pLvlPrestTxtRecord->dwDef;
        pDrlgPresetRoom->dwFlags = 1;
        pDrlgPresetRoom->pMazeGrid = 0;

        if (!pDrlgMap->pLvlPrestTxtRecord->dwPopulate)
        {
            pRoom->dwFlags |= 0x800000;
        }

        DRLGROOM_AddRoomExToLevel(pLevel, pRoom);
        pDrlgRoom = pRoom;
    }
    else
    {
        const int nXEnd = pDrlgMap->tCoords.nWidth + pDrlgMap->tCoords.nPosX;
        const int nYEnd = pDrlgMap->tCoords.nPosY + pDrlgMap->tCoords.nHeight;
        D2DrlgCoordStrc tDrlgCoord = { 0, 0, 0, 0 };

        for (int nY = pDrlgMap->tCoords.nPosY, nGridY = 0; nY < nYEnd; nY += 8, ++nGridY)
        {
            for (int nX = pDrlgMap->tCoords.nPosX, nGridX = 0; nX < nXEnd; nX += 8, ++nGridX)
            {
                const int nDeltaToEndX = nXEnd - nX;
                const int nDeltaToEndY = nYEnd - nY;
                tDrlgCoord.nPosX = nX;
                tDrlgCoord.nPosY = nY;

                if (nDeltaToEndX < 8)
                    tDrlgCoord.nWidth = nDeltaToEndX;
                else
                    tDrlgCoord.nWidth = 8;

                tDrlgCoord.nHeight = nDeltaToEndY;
                if (nDeltaToEndY >= 8)
                {
                    tDrlgCoord.nHeight = 8;
                }

                int nGridFlags = DRLGGRID_GetGridEntry(&tDrlgGrid, nGridX, nGridY);
                int nMapFlags = pDrlgMap->pVertices ? DRLGGRID_GetGridEntry(&pDrlgMap->pMapGrid, nGridX, nGridY) : 0;
                if (tDrlgCoord.nWidth && tDrlgCoord.nHeight)
                {
                    pDrlgRoom = DRLGPRESET_InitPresetRoomData(pLevel, pDrlgMap, &tDrlgCoord, dwDT1Mask, nGridFlags, 0, (D2DrlgGridStrc*)nMapFlags);
                }
            }
        }
    }

    DRLGGRID_ResetGrid(&tDrlgGrid);
    return pDrlgRoom;
}

// 0x006683D0
void __fastcall DRLGPRESET_FreeDrlgMap(void* pMemPool, D2DrlgMapStrc* pDrlgMap)
{
    D2DrlgMapStrc* pMap = pDrlgMap;
    while (pMap)
    {
        D2DrlgMapStrc* pNextMap = pMap->pNext;

        DRLGGRID_FreeGrid(pMemPool, &pMap->pMapGrid);
        DRLGVER_FreeVertices(pMemPool, &pMap->pVertices);
        DRLGPRESET_FreeDrlgFile(&pMap->ptFile);

        D2PresetUnitStrc* pPresetUnit = pMap->pPresetUnit;
        while (pPresetUnit)
        {
            D2PresetUnitStrc* pFreePresetUnit = pPresetUnit;
            pPresetUnit = pPresetUnit->pNext;
            DRLGPRESET_FreePresetUnit(pMemPool, pFreePresetUnit);
        }

        if (pMap->pPopsIndex)
        {
            sub_0040B480(pMemPool, pMap->pPopsIndex, &gszDrlgPresetSourceFile, 2554, 0);
        }

        if (pMap->pPopsSubIndex)
        {
            sub_0040B480(pMemPool, pMap->pPopsSubIndex, &gszDrlgPresetSourceFile, 2555, 0);
        }

        if (pMap->pPopsOrientation)
        {
            sub_0040B480(pMemPool, pMap->pPopsOrientation, &gszDrlgPresetSourceFile, 2556, 0);
        }

        if (pMap->pPopsLocation)
        {
            sub_0040B480(pMemPool, pMap->pPopsLocation, &gszDrlgPresetSourceFile, 2557, 0);
        }

        sub_0040B480(pMemPool, pMap, &gszDrlgPresetSourceFile, 2559, 0);
        pMap = pNextMap;
    }
}

// 0x006671E0
void __fastcall DRLGPRESET_UpdatePops(D2DrlgRoomStrc* pDrlgRoom, int nX, int nY, int bOtherRoom)
{
    D2DrlgMapStrc* pDrlgMap;
    int bUpdate;
    int nTick;
    int nPopIndex;

    pDrlgMap = 0;
    bUpdate = 0;
    nTick = GetTickCount() + 500;
    nPopIndex = 0;
    int i;
    int j;
    D2DrlgRoomStrc* pAdjacentRoom;
    D2DrlgMapStrc* pAdjacentMap;
    int nOrientation;

    if (pDrlgRoom->nType == 2)
    {
        pDrlgMap = pDrlgRoom->pMaze->pMap;
        for (i = 0; i < pDrlgMap->nPops; ++i)
        {
            D2DrlgCoordStrc tDrlgCoord = { 0 };
            tDrlgCoord.nPosX = 5 * pDrlgMap->pPopsLocation[i].nPosX;
            tDrlgCoord.nPosY = 5 * pDrlgMap->pPopsLocation[i].nPosY;
            tDrlgCoord.nWidth = pDrlgMap->pLvlPrestTxtRecord->dwPopPad + 5 * pDrlgMap->pPopsLocation[i].nWidth;
            tDrlgCoord.nHeight = pDrlgMap->pLvlPrestTxtRecord->dwPopPad + 5 * pDrlgMap->pPopsLocation[i].nHeight;

            if (DRLGROOM_AreXYInsideCoordinates(&tDrlgCoord, nX, nY))
            {
                nPopIndex = pDrlgMap->pPopsIndex[i];
                break;
            }
        }
    }

    for (i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        pAdjacentRoom = pDrlgRoom->ppRoomsNear[i];
        if (pAdjacentRoom->nType == 2 && pAdjacentRoom->pRoom)
        {
            pAdjacentMap = pAdjacentRoom->pMaze->pMap;
            for (j = 0; j < pAdjacentMap->nPops; ++j)
            {
                nOrientation = pAdjacentMap->pPopsOrientation[j];
                if ((pAdjacentMap != pDrlgMap || pAdjacentMap->pPopsIndex[j] != nPopIndex) && nOrientation)
                {
                    DRLGPRESET_TogglePopsVisibility(pAdjacentRoom, pAdjacentMap->pPopsSubIndex[j], &pAdjacentMap->pPopsLocation[j], nTick, 1);
                    bUpdate = 1;
                }

                if (pAdjacentMap == pDrlgMap && pAdjacentMap->pPopsIndex[j] == nPopIndex)
                {
                    if (!nOrientation)
                    {
                        DRLGPRESET_TogglePopsVisibility(pAdjacentRoom, pAdjacentMap->pPopsSubIndex[j], &pAdjacentMap->pPopsLocation[j], nTick, 0);
                        bUpdate = 1;
                    }
                    else if (bOtherRoom)
                    {
                        DRLGPRESET_TogglePopsVisibility(pAdjacentRoom, pAdjacentMap->pPopsSubIndex[j], &pAdjacentMap->pPopsLocation[j], nOrientation, 0);
                        bUpdate = 1;
                    }
                }
            }
        }
    }

    if (bUpdate)
    {
        for (i = 0; i < pDrlgRoom->nRoomsNear; ++i)
        {
            pAdjacentRoom = pDrlgRoom->ppRoomsNear[i];
            if (pAdjacentRoom->nType == 2)
            {
                pAdjacentMap = pAdjacentRoom->pMaze->pMap;
                for (j = 0; j < pAdjacentMap->nPops; ++j)
                {
                    if (pAdjacentMap != pDrlgMap || pAdjacentMap->pPopsIndex[j] != nPopIndex)
                    {
                        pAdjacentMap->pPopsOrientation[j] = 0;
                    }

                    if (pAdjacentMap == pDrlgMap && pAdjacentMap->pPopsIndex[j] == nPopIndex)
                    {
                        pAdjacentMap->pPopsOrientation[j] = nTick;
                    }
                }
            }
        }
    }
}

// 0x00667420
int __fastcall DRLGPRESET_GetChainField20(D2Unk00667420Strc* p)
{
    return p->p14->p00->n20;
}

// 0x00667430
void __fastcall DRLGPRESET_InitLevelData(D2DrlgLevelStrc* pLevel)
{
	void* const tArg1 = pLevel->pDrlg->pMempool;
	D2DrlgPresetInfoStrc* pPreset = (D2DrlgPresetInfoStrc*)FOG_AllocPool(tArg1, sizeof(D2DrlgPresetInfoStrc), gszPresetFile, 2809, 0);
	D2LvlPrestTxt* pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecordFromLevelId(pLevel->eLevelId);
	D2_ASSERT(pLvlPrestTxtRecord, 2811);

	pLevel->pPreset = pPreset;
	memset(pPreset, 0, sizeof(D2DrlgPresetInfoStrc));

	const int nFiles = DRLGPRESET_GetFileCount(pLvlPrestTxtRecord);
	if (nFiles)
	{
		pPreset->nDirection = sub_0045C3E0(&pLevel->pSeed, nFiles);
	}
	else
	{
		pPreset->nDirection = -1;
	}

	DRLG_SetLevelPositionAndSize(pLevel->pDrlg, pLevel);
}

// 0x00668100
void __fastcall DRLGPRESET_GenerateLevel(D2DrlgLevelStrc* pLevel)
{
    D2DrlgPresetInfoStrc* pPreset = pLevel->pPreset;
    D2LvlPrestTxt* pLvlPrestTxtRecord = DATATBLS_GetLvlPrestTxtRecordFromLevelId(pLevel->eLevelId);
    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, pLvlPrestTxtRecord->dwDef, &pLevel->pLevelCoords, &pLevel->pSeed);
    pPreset->pDrlgMap = pDrlgMap;

    if (pPreset->nDirection == -1)
    {
        pPreset->nDirection = pDrlgMap->nPickedFile;
    }
    else
    {
        pDrlgMap->nPickedFile = pPreset->nDirection;
    }

    DRLGPRESET_BuildArea(pLevel, pPreset->pDrlgMap, 0, 0);

    if (pLevel->eLevelId == LEVEL_LUTGHOLEIN || pLevel->eLevelId == LEVEL_THEPANDEMONIUMFORTRESS || pLevel->eLevelId == LEVEL_HARROGATH)
    {
        if (pLevel->pDrlg->pfTownAutomap && pDrlgMap->pLvlPrestTxtRecord->dwAutoMap)
        {
            pLevel->pDrlg->pfTownAutomap(pLevel->eLevelId, pDrlgMap->nPickedFile, pLevel->pLevelCoords.nPosX + pLevel->pLevelCoords.nWidth / 2, pLevel->pLevelCoords.nPosY + pLevel->pLevelCoords.nHeight / 2);
        }
    }
    else
    {
        if (pLevel->pDrlg->pfAutomap && pDrlgMap->pLvlPrestTxtRecord->dwAutoMap)
        {
            int* pVisLevelIds = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
            for (int i = 0; i < 8; ++i)
            {
                if (pVisLevelIds[i])
                {
                    D2DrlgLevelStrc* pCurrentLevel = DRLG_GetLevel(pLevel->pDrlg, pVisLevelIds[i]);
                    if (!pCurrentLevel->ptRoomFirst)
                    {
                        DRLG_InitLevel(pCurrentLevel);
                    }
                }
            }

            for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
            {
                DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
                pLevel->pDrlg->pfAutomap((D2RoomStrc*)pDrlgRoom->pRoom);
            }
        }
    }
}

// 0x006674D0
void __fastcall DRLGPRESET_ResetDrlgMap(D2DrlgLevelStrc* pLevel, int bKeepPreset)
{
    pLevel->pPreset->pDrlgMap = 0;

    if (!bKeepPreset)
    {
        sub_0040B480(pLevel->pDrlg->pMempool, pLevel->pPreset, &gszDrlgPresetSourceFile, 2906, 0);
        pLevel->pPreset = 0;
    }
}

#include "gen/data/Source/D2Common/DRLG/Preset.inc"
