#include "D2LevelIds.h"
#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2TxtTables.h"
#include "D2DrlgRooms.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"

extern "C" const char gszEmptyAssertText;                                                     // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                        // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);     // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                 // 0x00681E09

void __fastcall DRLG_SetLevelPositionAndSize(D2DrlgStrc* pDrlg, D2DrlgLevelStrc* pLevel);                       // 0x00642D10

D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType);                     // 0x0066B3E0

int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pCoord1, D2DrlgCoordStrc* pCoord2, int nDistance);    // 0x0066B860

int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDistance);   // 0x0066B900

void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom);                   // 0x0066B970

void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom);                                           // 0x0066C100

extern const int gnMazeExpansionPresetRemap[16][2];                                                         // 0x006EF6D8

extern const int gnMazePresetRemap[16][3];                                                      // 0x006EF758

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

struct D2DrlgOrthStrc;

struct D2DrlgBuildStrc;

struct D2DrlgCoordStrc;

union D2SeedStrc;

struct D2DrlgPresetRoomStrc;

struct D2LvlPrestTxt;

struct D2DrlgMapStrc;

struct D2DrlgPresetInfoStrc;

struct D2DrlgStrc;

struct D2MazeLevelIdStrc;

struct D2MazeLavaSetStrc;

struct D2DrlgRoomStrc;

struct D2DrlgLevelStrc;

struct D2LvlMazeTxt;

void __stdcall DRLGMAZE_MergeMazeRooms(D2DrlgRoomStrc* pDrlgRoom);

int __fastcall DRLG_GetDirectionFromCoordinates(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2); // 0x00642240

int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY); // 0x0066B800

extern const D2MazeLevelIdStrc gnAct2ArcaneSummonerIds[4]; // 0x006F00F8

typedef D2DrlgRoomStrc* (__fastcall* D2MazeRoomFn)(D2DrlgLevelStrc* pLevel);

extern D2MazeRoomFn const gpfnMazeGetBarracksEntryRoom[3]; // 0x006F0468

static D2DrlgRoomStrc* __stdcall sSetChamberPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom); // 0x006709B0

static int DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection); // 0x00672340

static void __stdcall DRLGMAZE_InitBasicMazeLayout(int nRoomsPerDirection, D2DrlgLevelStrc* pLevel);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

D2DrlgMapStrc* __fastcall DRLGPRESET_AllocDrlgMap(D2DrlgLevelStrc* pLevel, int nLvlPrestId, D2DrlgCoordStrc* pDrlgCoord, D2SeedStrc* pSeed); // 0x00666ED0

D2DrlgRoomStrc* __fastcall DRLGPRESET_BuildArea(D2DrlgLevelStrc* pLevel, D2DrlgMapStrc* pDrlgMap, int nFlags, int bSingleRoom); // 0x00667ED0

static __declspec(noinline) int __stdcall DRLGMAZE_LinkMazeRooms(D2DrlgRoomStrc* pDrlgRoom, int nDirection, D2DrlgRoomStrc* pNewRoomEx);

static D2DrlgRoomStrc* DRLGMAZE_GetFreeLocationForRoomSouth(D2DrlgLevelStrc* pLevel);

static inline unsigned int MAZE_RollSeed(D2SeedStrc* pSeed);

static inline D2DrlgRoomStrc* MAZE_ReplaceRoomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nPickedFile);

static D2DrlgRoomStrc* __stdcall DRLGMAZE_PlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms); // 0x00670D70

static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddSpecialPreset(int nDirection, int nLvlPrestId, int nFile, D2DrlgLevelStrc* pLevel);

static D2DrlgRoomStrc* __stdcall DRLGMAZE_InitRoomFixedPreset(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int nLvlPrestId, int nFile, int bUseInitPreset);

static void __stdcall DRLGMAZE_ScanReplaceSpecialPreset(D2DrlgLevelStrc* pLevel, const D2MazeLevelIdStrc* pMazeInit, int* pRand);

extern const D2MazeLevelIdStrc gnAct2SewerPrevIds[4];                                       // 0x006EFCE8

extern const D2MazeLevelIdStrc gnAct2SewerNextIds[4];                                       // 0x006EFD28

extern const D2MazeLevelIdStrc gnAct2SewerWaypointIds[4];                                   // 0x006EFD68

extern const D2MazeLevelIdStrc gnAct2SewerRadamentIds[4];                                   // 0x006EFDA8

extern const D2MazeLevelIdStrc gnAct2SewerChestIds[4];                                      // 0x006EFDE8

D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomWest(D2DrlgLevelStrc* pLevel); // 0x00672460

static void DRLGMAZE_ScanReplaceSpecialAct2SewersPresets(D2DrlgLevelStrc* pLevel);

static int DRLGMAZE_HasSingleRoomForDifficulty(D2DrlgLevelStrc* pLevel);

D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomNorth(D2DrlgLevelStrc* pLevel);

void __fastcall DRLGMAZE_PlaceSummonerPreset(D2DrlgLevelStrc* pLevel);

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);          // 0x0045C390

void __fastcall DRLG_UpdateRoomExCoordinates(D2DrlgLevelStrc* pLevel);                      // 0x00642590

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                  // 0x00642BB0

void __fastcall DRLG_GetMinAndMaxCoordinatesFromLevel(D2DrlgLevelStrc* pLevel, int* pTileMinX, int* pTileMinY, int* pTileMaxX, int* pTileMaxY); // 0x00642520

void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection); // 0x0066B5E0

void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset); // 0x0066B790

D2DrlgRoomStrc* __fastcall DRLGMAZE_GetRandomRoomExFromLevel(D2DrlgLevelStrc* pLevel);      // 0x006711A0

void __fastcall DRLGMAZE_RollAct_1_2_3_BasicPresets(D2DrlgLevelStrc* pLevel);               // 0x006735F0

void __fastcall DRLGMAZE_PlaceArcaneSanctuary(D2DrlgLevelStrc* pLevel);

extern const D2MazeLavaSetStrc gnMazeAct5LavaSets[8];                                       // 0x006EF828

extern const int gnMazeTombBaalPrevPresets[4][2];                                           // 0x006EF888

extern const D2MazeLevelIdStrc gnAct1CavePrevIds[4];                                        // 0x006EF8A8

extern const D2MazeLevelIdStrc gnAct1CaveDOEIds[4];                                         // 0x006EF8E8

extern const D2MazeLevelIdStrc gnAct1CaveDownIds[4];                                        // 0x006EF928

extern const D2MazeLevelIdStrc gnAct1CaveColdcrowIds[4];                                    // 0x006EF968

extern const D2MazeLevelIdStrc gnAct1CaveNextIds[4];                                        // 0x006EF9A8

extern const D2MazeLevelIdStrc gnAct1CryptPrevIds[4];                                       // 0x006EF9E8

extern const D2MazeLevelIdStrc gnAct1CryptSpecialIds[4];                                    // 0x006EFA28

extern const D2MazeLevelIdStrc gnAct1CryptChestIds[4];                                      // 0x006EFAA8

extern const D2MazeLevelIdStrc gnAct1CryptNextIds[4];                                       // 0x006EFAE8

extern const D2MazeLevelIdStrc gnAct1JailPrevIds[4];                                        // 0x006EFB28

extern const D2MazeLevelIdStrc gnAct1JailCathIds[4];                                        // 0x006EFB68

extern const D2MazeLevelIdStrc gnAct1JailNextIds[4];                                        // 0x006EFBA8

extern const D2MazeLevelIdStrc gnAct1JailWaypointIds[4];                                    // 0x006EFBE8

extern const D2MazeLevelIdStrc gnAct1JailPitspawnIds[4];                                    // 0x006EFC28

extern const D2MazeLevelIdStrc gnAct1CatacombsNextIds[4];                                   // 0x006EFC68

extern const D2MazeLevelIdStrc gnAct1CatacombsWaypointIds[4];                               // 0x006EFCA8

extern const D2MazeLevelIdStrc gnAct2TombPrevIds[4];                                        // 0x006EFE28

extern const D2MazeLevelIdStrc gnAct2TombNextIds[4];                                        // 0x006EFE68

extern const D2MazeLevelIdStrc gnAct2TombTreasureIds[4];                                    // 0x006EFEA8

extern const D2MazeLevelIdStrc gnAct2TombTalRashaIds[4];                                    // 0x006EFEE8

extern const D2MazeLevelIdStrc gnAct2TombNext2Ids[4];                                       // 0x006EFF28

extern const D2MazeLevelIdStrc gnAct2TombChest2Ids[4];                                      // 0x006EFF68

extern const D2MazeLevelIdStrc gnAct2TombOrificeIds[4];                                     // 0x006EFFA8

extern const D2MazeLevelIdStrc gnAct2TombBossIds[4];                                        // 0x006EFFE8

extern const D2MazeLevelIdStrc gnAct2LairPrevIds[4];                                        // 0x006F0028

extern const D2MazeLevelIdStrc gnAct2LairSpecialIds[9];                                     // 0x006F0068

extern const D2MazeLevelIdStrc gnAct3DungeonPrevIds[4];                                     // 0x006F0138

extern const D2MazeLevelIdStrc gnAct3DungeonNextIds[4];                                     // 0x006F0178

extern const D2MazeLevelIdStrc gnAct3SewerPrevIds[4];                                       // 0x006F01B8

extern const D2MazeLevelIdStrc gnAct3SewerNextIds[4];                                       // 0x006F01F8

extern const D2MazeLevelIdStrc gnAct3KurastPrevIds[4];                                      // 0x006F0238

extern const D2MazeLevelIdStrc gnAct3KurastNextIds[4];                                      // 0x006F0278

extern const D2MazeLevelIdStrc gnAct3KurastChestIds[4];                                     // 0x006F02B8

extern const D2MazeLevelIdStrc gnAct5TemplePrevIds[4];                                      // 0x006F02F8

extern const D2MazeLevelIdStrc gnAct5TempleNextIds[4];                                      // 0x006F0328

extern const D2MazeLevelIdStrc gnAct5BaalPrevIds[4];                                        // 0x006F0368

extern const D2MazeLevelIdStrc gnAct5BaalNextIds[4];                                        // 0x006F03A8

extern const D2MazeLevelIdStrc gnAct1BarracksNextIds[4];                                    // 0x006F03E8

extern const D2MazeLevelIdStrc gnAct1BarracksForgeIds[4];                                   // 0x006F0428

extern const D2MazeLevelIdStrc gnAct4LavaForgeIds[2];                                       // 0x006F0474

extern const D2MazeLevelIdStrc gnAct5IcePrevIds[4];                                         // 0x006F0498

extern const D2MazeLevelIdStrc gnAct5IceNextIds[4];                                         // 0x006F04D8

extern const D2MazeLevelIdStrc gnAct5IceShrineIds[4];                                       // 0x006F0518

extern const D2MazeLevelIdStrc gnAct5IceSpecialIds[4];                                      // 0x006F0558

extern const D2MazeLevelIdStrc gnAct5IceWaypointIds[4];                                     // 0x006F0598

extern const char gszDrlgMazeFile[];

static void __stdcall DRLGMAZE_FillBlankMazeSpaces(D2DrlgLevelStrc* pLevel, int nLevelPrest, D2DrlgRoomStrc* pIgnoreRoomEx); // 0x00671320

static void DRLGMAZE_PlaceAct5LavaPresets(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct1CaveStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct1CryptStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct1JailStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct1CatacombsStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct2TombStuff(D2DrlgLevelStrc* pLevel); // 0x00672BE0

static void DRLGMAZE_PlaceAct2LairStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct3DungeonStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct3SewerStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct3MephistoStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct5TempleStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct5BaalStuff(D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_PlaceAct1Barracks(D2DrlgLevelStrc* pLevel); // 0x00673120

static void DRLGMAZE_PlaceAct4Lava(D2DrlgLevelStrc* pLevel); // 0x00673320

static void DRLGMAZE_PlaceAct5IceStuff(D2DrlgLevelStrc* pLevel);

static void __stdcall DRLGMAZE_BuildRoomPresetArea(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel);

static void DRLGMAZE_RollBasicPresets(D2DrlgLevelStrc* pLevel);

void __stdcall DRLGMAZE_BuildBasicMaze(D2DrlgLevelStrc* pLevel); // 0x00671210

void __stdcall DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(D2DrlgLevelStrc* pLevel); // 0x006718C0

D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomEast(D2DrlgLevelStrc* pLevel);

static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddAdjacentMazeRoom(D2DrlgRoomStrc* pDrlgRoom, int bMergeRooms, int nDirection);

static void __stdcall DRLGMAZE_InitFirstMazeRoom(D2DrlgLevelStrc* pLevel, int bFirstLevel);

void __fastcall MazeLevelGenerate(D2DrlgLevelStrc* pLevel);

// 0x006738C0
static void __stdcall DRLGMAZE_PickDrlgMapFile(D2DrlgMapStrc* pDrlgMap, int nPickedFile, D2DrlgLevelStrc* pLevel);

// 0x00670810
static int DRLGMAZE_HasSingleRoomForDifficulty(D2DrlgLevelStrc* pLevel)
{
    if (!pLevel)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 28);
        exit(-1);
    }

    if (!pLevel->pMaze)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 30);
        exit(-1);
    }

    return pLevel->pMaze->dwRooms[pLevel->pDrlg->nDifficulty] == 1;
}

// 0x00670860
static void DRLGMAZE_SetRoomSize(D2DrlgRoomStrc* pDrlgRoom)
{
    D2LvlMazeTxt* pMaze = pDrlgRoom->ptDrlgLevel->pMaze;
    pDrlgRoom->pDrlgCoord.nWidth = pMaze->dwSizeX;
    pDrlgRoom->pDrlgCoord.nHeight = pMaze->dwSizeY;
}

// 0x00670880
static int __stdcall DRLGMAZE_LinkMazeRooms(D2DrlgRoomStrc* pDrlgRoom, int nDirection, D2DrlgRoomStrc* pNewRoomEx)
{
    D2DrlgCoordStrc* pCoord = &pNewRoomEx->pDrlgCoord;
    switch (nDirection)
    {
    case 0:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY;
        break;

    case 1:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 2:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY;
        break;

    case 3:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 4:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 5:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY - pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 6:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX + pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        break;

    case 7:
        pCoord->nPosX = pDrlgRoom->pDrlgCoord.nPosX - pDrlgRoom->pDrlgCoord.nWidth;
        pCoord->nPosY = pDrlgRoom->pDrlgCoord.nPosY + pDrlgRoom->pDrlgCoord.nHeight;
        break;

    default:
        break;
    }

    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (!DRLG_CheckNotOverlappingUsingManhattanDistance(pCoord, pDrlgOrth->pBox, 0))
        {
            return 0;
        }
    }

    return DRLGMAZE_CheckRoomNotOverlaping(pNewRoomEx->ptDrlgLevel, pNewRoomEx, pDrlgRoom, 0);
}

// 0x00670960
static int DRLGMAZE_HasMapDS1(D2DrlgRoomStrc* pDrlgRoom)
{
    return !((pDrlgRoom->pMaze->dwFlags >> 1) & 1);
}

// 0x00670970
static D2DrlgRoomStrc* __stdcall DRLGMAZE_SetPickedFileAndPresetId(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile, int bResetFlag)
{
    D2DrlgPresetRoomStrc* pMaze = pDrlgRoom->pMaze;
    pMaze->nLevelPrest = nLevelPrest;
    pMaze->nPickedFile = nPickedFile;

    if (bResetFlag)
    {
        pMaze->dwFlags &= ~2;
    }
    else
    {
        pMaze->dwFlags |= 2;
    }

    return pDrlgRoom;
}

// 0x006709A0
static void DRLGMAZE_SetPickedFile(D2DrlgRoomStrc* pDrlgRoom, int nPickedFile)
{
    pDrlgRoom->pMaze->nPickedFile = nPickedFile;
}

// 0x006709B0
static D2DrlgRoomStrc* __stdcall sSetChamberPreset(int bResetFlag, D2DrlgRoomStrc* pDrlgRoom)
{
    int nLevelPrest = 0;
    int nPickedFile = -1;

    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        switch (pDrlgOrth->nDirection)
        {
        case 0:
            nLevelPrest |= 1;
            break;

        case 1:
            nLevelPrest |= 8;
            break;

        case 2:
            nLevelPrest |= 2;
            break;

        case 3:
            nLevelPrest |= 4;
            break;

        default:
            break;
        }
    }

    D2DrlgLevelStrc* pLevel = pDrlgRoom->ptDrlgLevel;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLevelPrest += 52;
        break;

    case 4:
        nLevelPrest += 108;
        break;

    case 7:
        nLevelPrest += 167;
        break;

    case 8:
        nLevelPrest += 205;
        break;

    case 10:
        nLevelPrest += 257;
        break;

    case 13:
        nLevelPrest += 301;
        break;

    case 14:
        nLevelPrest = gnMazePresetRemap[nLevelPrest][0];
        break;

    case 15:
        nLevelPrest = gnMazePresetRemap[nLevelPrest][1];
        if (pLevel->eLevelId == LEVEL_PALACECELLARLEV1 && nLevelPrest == 361)
        {
            nPickedFile = 2;
        }

        if (pLevel->eLevelId == LEVEL_PALACECELLARLEV3 && (nLevelPrest == 361 || nLevelPrest == 359))
        {
            nPickedFile = 3;
        }
        break;

    case 17:
        nLevelPrest += 413;
        break;

    case 18:
        nLevelPrest += 481;
        break;

    case 19:
        nLevelPrest += 509;
        break;

    case 22:
        nLevelPrest += 753;
        break;

    case 23:
        nLevelPrest = gnMazePresetRemap[nLevelPrest][2];
        if (pLevel->eLevelId == LEVEL_SPIDERCAVE && nLevelPrest == 662)
        {
            nLevelPrest = 664;
        }

        if (pLevel->eLevelId == LEVEL_SPIDERCAVERN && nLevelPrest == 661)
        {
            nLevelPrest = 663;
        }
        break;

    case 24:
        nLevelPrest += 664;
        break;

    case 25:
        nLevelPrest += 704;
        break;

    case 28:
        nLevelPrest += 836;
        break;

    case 33:
        if (!DRLGMAZE_HasSingleRoomForDifficulty(pLevel))
        {
            nLevelPrest += 1002;
        }
        break;

    case 32:
        nLevelPrest = gnMazeExpansionPresetRemap[nLevelPrest][0];
        break;

    case 34:
        nLevelPrest += 1058;
        break;

    case 35:
        nLevelPrest = gnMazeExpansionPresetRemap[nLevelPrest][1];
        break;

    default:
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 352);
        exit(-1);
    }

    if (nLevelPrest)
    {
        DRLGMAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrest, nPickedFile, bResetFlag);
    }

    return pDrlgRoom;
}

// 0x00670C10
static D2DrlgRoomStrc* __stdcall DRLGMAZE_ReplaceRoomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nPickedFile, int bResetFlag)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGMAZE_HasMapDS1(pDrlgRoom) && pDrlgRoom->pMaze->nLevelPrest == nLevelPrestId1)
            return DRLGMAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrestId2, nPickedFile, bResetFlag);
    }
    return 0;
}

D2DrlgRoomStrc* __fastcall sub_M116_Emit_00670860(D2DrlgRoomStrc* pDrlgRoom, int nFile)
{
    DRLGMAZE_SetRoomSize(pDrlgRoom);
    DRLGMAZE_SetPickedFile(pDrlgRoom, nFile);
    return DRLGMAZE_ReplaceRoomPreset(pDrlgRoom->ptDrlgLevel, nFile, 0x2C5, -1, 0);
}

static inline unsigned int MAZE_RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int MAZE_IsPresetUnset(D2DrlgRoomStrc* pDrlgRoom)
{
    return !((pDrlgRoom->pMaze->dwFlags >> 1) & 1);
}

static inline void MAZE_SetRoomSizeFromMaze(D2DrlgRoomStrc* pDrlgRoom)
{
    D2LvlMazeTxt* pMaze = pDrlgRoom->ptDrlgLevel->pMaze;
    pDrlgRoom->pDrlgCoord.nWidth = pMaze->dwSizeX;
    pDrlgRoom->pDrlgCoord.nHeight = pMaze->dwSizeY;
}

static inline void MAZE_SetPreset(D2DrlgRoomStrc* pDrlgRoom, int nLevelPrest, int nPickedFile)
{
    D2DrlgPresetRoomStrc* pPreset = pDrlgRoom->pMaze;
    pPreset->nLevelPrest = nLevelPrest;
    pPreset->nPickedFile = nPickedFile;
    pPreset->dwFlags |= 2;
}

// 0x00670C70
void __stdcall DRLGMAZE_MergeMazeRooms(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!MAZE_IsPresetUnset(pDrlgRoom))
    {
        return;
    }

    D2LvlMazeTxt* pMaze = pDrlgRoom->ptDrlgLevel->pMaze;
    for (D2DrlgRoomStrc* pRoom = pDrlgRoom->ptDrlgLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if (pRoom != pDrlgRoom && MAZE_IsPresetUnset(pRoom))
        {
            int nX = 0;
            int nY = 0;
            if (!DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(&pDrlgRoom->pDrlgCoord, &pRoom->pDrlgCoord, 1, &nX, &nY) && nX != nY)
            {
                D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth;
                while (pDrlgOrth && pDrlgOrth->pRoom != pRoom)
                {
                    pDrlgOrth = pDrlgOrth->pNext;
                }

                if (!pDrlgOrth && (int)(MAZE_RollSeed(&pRoom->pSeed) % 1000) < pMaze->dwMerge)
                {
                    const int nDirection = DRLG_GetDirectionFromCoordinates(&pRoom->pDrlgCoord, &pDrlgRoom->pDrlgCoord);
                    if (nDirection != -1)
                    {
                        DRLGROOM_AllocDrlgOrthsForRooms(pRoom, pDrlgRoom, nDirection);
                        sSetChamberPreset(1, pRoom);
                    }
                }
            }
        }
    }
}

// 0x00670D70
static D2DrlgRoomStrc* __stdcall DRLGMAZE_PlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->ptDrlgLevel, 2);
    MAZE_SetRoomSizeFromMaze(pNewRoomEx);

    if (!DRLGMAZE_LinkMazeRooms(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        return 0;
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
    if (bMergeRooms)
    {
        DRLGMAZE_MergeMazeRooms(pNewRoomEx);
    }
    DRLGROOM_AddRoomExToLevel(pDrlgRoom->ptDrlgLevel, pNewRoomEx);
    return pNewRoomEx;
}

// 0x00670DE0
static D2DrlgRoomStrc* __stdcall DRLGMAZE_InitRoomFixedPreset(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int nLvlPrestId, int nFile, int bUseInitPreset)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->ptDrlgLevel, 2);
    MAZE_SetRoomSizeFromMaze(pNewRoomEx);

    if (!DRLGMAZE_LinkMazeRooms(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        pNewRoomEx = 0;
    }
    else
    {
        DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
        DRLGROOM_AddRoomExToLevel(pDrlgRoom->ptDrlgLevel, pNewRoomEx);
        if (bUseInitPreset)
        {
            sSetChamberPreset(1, pDrlgRoom);
        }

        MAZE_SetPreset(pNewRoomEx, nLvlPrestId, nFile);
    }

    return pNewRoomEx;
}

// 0x00670E70
static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddAdjacentMazeRoom(D2DrlgRoomStrc* pDrlgRoom, int bMergeRooms, int nDirection)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGMAZE_PlaceAdjacentPresetRoom(pDrlgRoom, nDirection, bMergeRooms);
    if (pNewRoomEx)
    {
        if (bMergeRooms)
        {
            sSetChamberPreset(1, pDrlgRoom);
        }
        sSetChamberPreset(1, pNewRoomEx);
    }
    return pNewRoomEx;
}

// 0x00670EB0
static D2DrlgRoomStrc* __stdcall DRLGMAZE_AddSpecialPreset(int nDirection, int nLvlPrestId, int nFile, D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    D2DrlgRoomStrc* pNewRoomEx = 0;
    while (pDrlgRoom)
    {
        if (MAZE_IsPresetUnset(pDrlgRoom))
        {
            pNewRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, nDirection, nLvlPrestId, nFile, 1);
            if (pNewRoomEx)
            {
                break;
            }
        }
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }
    return pNewRoomEx;
}

static __forceinline D2DrlgRoomStrc* DRLGMAZE_PlaceAdjacentPresetRoomInline(D2DrlgRoomStrc* pDrlgRoom, int nDirection, int bMergeRooms)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGROOM_AllocRoomEx(pDrlgRoom->ptDrlgLevel, 2);
    MAZE_SetRoomSizeFromMaze(pNewRoomEx);

    if (!DRLGMAZE_LinkMazeRooms(pDrlgRoom, nDirection, pNewRoomEx))
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
        return 0;
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pNewRoomEx, nDirection);
    if (bMergeRooms)
    {
        DRLGMAZE_MergeMazeRooms(pNewRoomEx);
    }
    DRLGROOM_AddRoomExToLevel(pDrlgRoom->ptDrlgLevel, pNewRoomEx);
    return pNewRoomEx;
}

static __forceinline D2DrlgRoomStrc* DRLGMAZE_AddAdjacentMazeRoomInline(D2DrlgRoomStrc* pDrlgRoom, int bMergeRooms, int nDirection)
{
    D2DrlgRoomStrc* pNewRoomEx = DRLGMAZE_PlaceAdjacentPresetRoomInline(pDrlgRoom, nDirection, bMergeRooms);
    if (pNewRoomEx)
    {
        if (bMergeRooms)
        {
            sSetChamberPreset(1, pDrlgRoom);
        }
        sSetChamberPreset(1, pNewRoomEx);
    }
    return pNewRoomEx;
}

// 0x00670F60
static void __stdcall DRLGMAZE_InitBasicMazeLayout(int nRoomsPerDirection, D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    D2DrlgRoomStrc* pDrlgRoom = pFirstRoomEx;

    {
        const int nCount = nRoomsPerDirection - 1;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 1);
            } while (--i);
        }
    }

    {
        const int nCount = nRoomsPerDirection - 1;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 0);
            } while (--i);
        }
    }

    {
        const int nCount = nRoomsPerDirection - 1;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 3);
            } while (--i);
        }
    }

    {
        const int nCount = nRoomsPerDirection - 2;
        if (nCount > 0)
        {
            int i = nCount;
            do
            {
                pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 2);
            } while (--i);
        }
    }

    DRLGROOM_AllocDrlgOrthsForRooms(pDrlgRoom, pFirstRoomEx, 2);
    sSetChamberPreset(1, pDrlgRoom);
    sSetChamberPreset(1, pFirstRoomEx);
}

static inline unsigned int MAZE_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return MAZE_RollSeed(pSeed) % nMax;
    }

    return MAZE_RollSeed(pSeed) & (nMax - 1);
}

// 0x006711A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetRandomRoomExFromLevel(D2DrlgLevelStrc* pLevel)
{
    int i = MAZE_RollLimitedRandomNumberInline(&pLevel->pSeed, pLevel->nRooms);
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    for (; i; --i)
    {
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
    }

    return pDrlgRoom;
}

// 0x00671210
void __stdcall DRLGMAZE_BuildBasicMaze(D2DrlgLevelStrc* pLevel)
{
    int nRooms = pLevel->pMaze->dwRooms[pLevel->pDrlg->nDifficulty];
    if (pLevel->eLevelId == pLevel->pDrlg->nStaffTombLevel)
    {
        nRooms *= 3;
    }

    if (pLevel->eLevelId == pLevel->pDrlg->nBossTombLevel)
    {
        nRooms *= 2;
    }

    while (pLevel->nRooms < nRooms)
    {
        D2DrlgRoomStrc* pRandomRoomEx = DRLGMAZE_GetRandomRoomExFromLevel(pLevel);
        const int nDirection = MAZE_RollSeed(&pRandomRoomEx->pSeed) & 3;
        if (MAZE_IsPresetUnset(pRandomRoomEx))
        {
            DRLGMAZE_AddAdjacentMazeRoomInline(pRandomRoomEx, 1, nDirection);
        }
    }
}

// 0x00671320
static void __stdcall DRLGMAZE_FillBlankMazeSpaces(D2DrlgLevelStrc* pLevel, int nLevelPrest, D2DrlgRoomStrc* pIgnoreRoomEx)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    D2DrlgRoomStrc** ppDrlgRooms = (D2DrlgRoomStrc**)FOG_AllocPool(pMemPool, sizeof(D2DrlgRoomStrc*) * pLevel->nRooms, ".\\DRLG\\Maze.cpp", 625, 0);

    D2DrlgRoomStrc* pTemp = pLevel->ptRoomFirst;
    const int nRooms = pLevel->nRooms;
    for (int i = 0; i < nRooms; ++i)
    {
        ppDrlgRooms[i] = pTemp;
        pTemp = pTemp->pDrlgRoomNext;
    }

    for (int i = 0; i < nRooms; ++i)
    {
        if (ppDrlgRooms[i] != pIgnoreRoomEx)
        {
            for (int j = 0; j < 8; ++j)
            {
                DRLGMAZE_InitRoomFixedPreset(ppDrlgRooms[i], j, nLevelPrest, -1, 0);
            }
        }
    }

    sub_0040B480(pMemPool, ppDrlgRooms, ".\\DRLG\\Maze.cpp", 648, 0);
}

// 0x00671430
static void DRLGMAZE_PlaceAct5LavaPresets(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    const int nSet = 2 * (MAZE_RollSeed(&pFirstRoomEx->pSeed) & 3);
    D2_ASSERT(nSet < 7, 683);

    const D2MazeLavaSetStrc* pSet = &gnMazeAct5LavaSets[nSet];
    DRLGMAZE_InitRoomFixedPreset(pFirstRoomEx, pSet->nDirection, pSet->nLevelPrest, pSet->nPickedFile, 1);
    ++pSet;
    DRLGMAZE_InitRoomFixedPreset(pFirstRoomEx, pSet->nDirection, pSet->nLevelPrest, pSet->nPickedFile, 1);
    DRLGMAZE_FillBlankMazeSpaces(pLevel, 836, 0);
}

// 0x006714D0
static void __stdcall DRLGMAZE_InitFirstMazeRoom(D2DrlgLevelStrc* pLevel, int bFirstLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    if (bFirstLevel)
    {
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 1);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 2);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 3);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 0);
        MAZE_SetPreset(pFirstRoomEx, 290, -1);
    }
    else if (MAZE_RollSeed(&pLevel->pSeed) & 1)
    {
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 0);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 2);
        MAZE_SetPreset(pFirstRoomEx, 288, -1);
    }
    else
    {
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 1);
        DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, 3);
        MAZE_SetPreset(pFirstRoomEx, 289, -1);
    }
}

// 0x006718C0
void __stdcall DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    int nDirection = MAZE_RollSeed(&pLevel->pSeed) & 3;
    for (int i = 0; i < 3; ++i)
    {
        DRLGMAZE_AddAdjacentMazeRoomInline(pFirstRoomEx, 1, nDirection);
        nDirection = (nDirection + 1) % 4;
    }

    switch (pLevel->nLevelType)
    {
    case 17:
        MAZE_SetPreset(pFirstRoomEx, gnMazeTombBaalPrevPresets[nDirection][0], -1);
        break;
    case 34:
        MAZE_SetPreset(pFirstRoomEx, gnMazeTombBaalPrevPresets[nDirection][1], -1);
        break;
    }
}

// 0x006719F0
void __fastcall DRLGMAZE_PlaceArcaneSanctuary(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pRooms[60];
    D2DrlgRoomStrc* pFirstRoomEx = pLevel->ptRoomFirst;
    const int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    int n = 0;

    memset(pRooms, 0, sizeof(pRooms));

    for (int i = 0; i < 4; ++i)
    {
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pFirstRoomEx, 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 3) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 1) % 4);
        ++n;
        DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, i % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 2], 1, (i + 1) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 2) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 2) % 4);
        ++n;
        DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 3) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 2], 1, (i + 2) % 4);
        ++n;
        pRooms[n] = DRLGMAZE_AddAdjacentMazeRoom(pRooms[n - 1], 1, (i + 2) % 4);
        ++n;
    }

    for (int j = 0; j < 60; ++j)
    {
        if (pRooms[j])
        {
            pRooms[j]->pMaze->nPickedFile = (j / 15 + nRand) % 4;
        }
    }

    pFirstRoomEx->pMaze->nPickedFile = 4;
}

// 0x00672340
static int DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(D2DrlgRoomStrc* pDrlgRoom, int nDirection)
{
    if (!MAZE_IsPresetUnset(pDrlgRoom))
    {
        return 0;
    }

    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (pDrlgOrth->nDirection == nDirection)
        {
            return 0;
        }
    }

    D2DrlgRoomStrc* pNewRoomEx = DRLGMAZE_PlaceAdjacentPresetRoom(pDrlgRoom, nDirection, 0);
    if (pNewRoomEx)
    {
        sSetChamberPreset(1, pNewRoomEx);
    }

    const int bResult = pNewRoomEx != 0;
    if (pNewRoomEx)
    {
        DRLGROOM_FreeRoomEx(pNewRoomEx);
    }
    return bResult;
}

static void __stdcall DRLGMAZE_PickDrlgMapFile(D2DrlgMapStrc* pDrlgMap, int nPickedFile, D2DrlgLevelStrc* pLevel)
{
    void* pMemPool = pLevel->pDrlg->pMempool;
    if (nPickedFile != -1)
    {
        pDrlgMap->nPickedFile = nPickedFile;
        return;
    }

    const int nLevelDef = pDrlgMap->pLvlPrestTxtRecord->dwDef;
    const int nFiles = pDrlgMap->pLvlPrestTxtRecord->dwFiles;
    int nLvlPrestId = 0;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLvlPrestId = 52;
        break;

    case 4:
        nLvlPrestId = 108;
        break;

    case 7:
        nLvlPrestId = 167;
        break;

    case 8:
        nLvlPrestId = 205;
        break;

    case 10:
        nLvlPrestId = 257;
        break;

    case 13:
        nLvlPrestId = 301;
        break;

    case 17:
        nLvlPrestId = 413;
        break;

    case 18:
        nLvlPrestId = 481;
        break;

    case 22:
        nLvlPrestId = 753;
        break;

    case 24:
        nLvlPrestId = 664;
        break;

    case 25:
        nLvlPrestId = 704;
        break;

    case 28:
        nLvlPrestId = 836;
        break;

    case 33:
        nLvlPrestId = 1002;
        break;

    case 34:
        nLvlPrestId = 1058;
        break;

    case 35:
        nLvlPrestId = 1052;
        break;

    default:
        nLvlPrestId = nLevelDef;
        break;
    }

    if (nLevelDef > nLvlPrestId && nLevelDef < nLvlPrestId + 16)
    {
        D2DrlgBuildStrc* pDrlgBuild = pLevel->pBuild;
        while (pDrlgBuild)
        {
            if (pDrlgBuild->nPreset == nLevelDef)
            {
                break;
            }
            pDrlgBuild = pDrlgBuild->pNext;
        }

        if (!pDrlgBuild)
        {
            pDrlgBuild = (D2DrlgBuildStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgBuildStrc), ".\\DRLG\\Maze.cpp", 1920, 0);
            memset(pDrlgBuild, 0, sizeof(D2DrlgBuildStrc));
            pDrlgBuild->nPreset = nLevelDef;
            pDrlgBuild->nDivisor = nFiles;
            pDrlgBuild->nRand = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, nFiles);
            pDrlgBuild->pNext = pLevel->pBuild;
            pLevel->pBuild = pDrlgBuild;
        }

        pDrlgBuild->nRand = (pDrlgBuild->nRand + 1) % pDrlgBuild->nDivisor;
        pDrlgMap->nPickedFile = pDrlgBuild->nRand;
    }
}

// 0x006723E0
static D2DrlgRoomStrc* DRLGMAZE_GetFreeLocationForRoomSouth(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if ((!pResult || pRoom->pDrlgCoord.nPosY < pResult->pDrlgCoord.nPosY)
            && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pRoom, 1))
        {
            pResult = pRoom;
        }
    }
    return pResult;
}

// 0x00672420
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomEast(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosX < pResult->pDrlgCoord.nPosX) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pDrlgRoom, 0))
        {
            pResult = pDrlgRoom;
        }
    }
    return pResult;
}

static __forceinline D2DrlgRoomStrc* MAZE_ReplaceRoomPreset(D2DrlgLevelStrc* pLevel, int nLevelPrestId1, int nLevelPrestId2, int nPickedFile)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (MAZE_IsPresetUnset(pDrlgRoom) && pDrlgRoom->pMaze->nLevelPrest == nLevelPrestId1)
        {
            DRLGMAZE_SetPickedFileAndPresetId(pDrlgRoom, nLevelPrestId2, nPickedFile, 0);
            return pDrlgRoom;
        }
    }
    return 0;
}

// 0x00672460
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomWest(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if ((!pResult || pDrlgRoom->pDrlgCoord.nPosX > pResult->pDrlgCoord.nPosX) && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pDrlgRoom, 2))
        {
            pResult = pDrlgRoom;
        }
    }
    return pResult;
}

// 0x006724A0
D2DrlgRoomStrc* __fastcall DRLGMAZE_GetFreeLocationForRoomNorth(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pResult = 0;
    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        if ((!pResult || pRoom->pDrlgCoord.nPosY > pResult->pDrlgCoord.nPosY)
            && DRLGMAZE_CheckIfMayPlaceAdjacentPresetRoom(pRoom, 3))
        {
            pResult = pRoom;
        }
    }
    return pResult;
}

// 0x006724E0
static void __stdcall DRLGMAZE_ScanReplaceSpecialPreset(D2DrlgLevelStrc* pLevel, const D2MazeLevelIdStrc* pMazeInit, int* pRand)
{
    if (!MAZE_ReplaceRoomPreset(pLevel, pMazeInit->nLevelPrestId1, pMazeInit->nLevelPrestId2, pMazeInit->nPickedFile))
    {
        DRLGMAZE_AddSpecialPreset(pMazeInit->nDirection, pMazeInit->nLevelPrestId2, pMazeInit->nPickedFile, pLevel);
    }

    if (pRand)
    {
        *pRand = (*pRand + 1) % 4;
    }
}

// 0x00672550
static void DRLGMAZE_PlaceAct1CaveStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CavePrevIds[nRand], &nRand);
    if (pLevel->eLevelId == LEVEL_DENOFEVIL)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveDOEIds[nRand], &nRand);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveDownIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_CAVELEV1)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveColdcrowIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_UNDERGROUNDPASSAGELEV1)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CaveNextIds[nRand], &nRand);
    }
}

// 0x00672610
static void DRLGMAZE_PlaceAct1CryptStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptPrevIds[nRand], &nRand);
    if (pLevel->eLevelId == LEVEL_CRYPT)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptSpecialIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_MAUSOLEUM || pLevel->eLevelId == LEVEL_PANDEMONIUMRUN1)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptChestIds[nRand], &nRand);
    }

    if (pLevel->eLevelId >= 21 && pLevel->eLevelId <= 24)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CryptNextIds[nRand], &nRand);
    }
}

// 0x006726D0
static void DRLGMAZE_PlaceAct1JailStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailPrevIds[nRand], &nRand);
    if (pLevel->eLevelId == LEVEL_JAILLEV1)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailWaypointIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_JAILLEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailPitspawnIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_JAILLEV3)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailCathIds[nRand], &nRand);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1JailNextIds[nRand], &nRand);
    }
}

// 0x006727A0
static void DRLGMAZE_PlaceAct1CatacombsStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CatacombsNextIds[nRand], &nRand);
    if (pLevel->eLevelId == LEVEL_CATACOMBSLEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1CatacombsWaypointIds[nRand], &nRand);
    }
}

// 0x00672810
static void DRLGMAZE_ScanReplaceSpecialAct2SewersPresets(D2DrlgLevelStrc* pLevel)
{
    const int nDirection = (2 * (MAZE_RollSeed(&pLevel->pSeed) & 1)) | 1;
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;

    switch (pLevel->eLevelId)
    {
    case 47:
    {
        D2DrlgRoomStrc* pDrlgRoom = DRLGMAZE_GetFreeLocationForRoomSouth(pLevel);
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 1);
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 1);
        DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 0, 333, 0, 1);

        pDrlgRoom = DRLGMAZE_GetFreeLocationForRoomWest(pLevel);
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 2);
        pDrlgRoom = DRLGMAZE_AddAdjacentMazeRoomInline(pDrlgRoom, 1, 2);
        pDrlgRoom = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, nDirection, 336, 0, 1);
        D2DrlgRoomStrc* pLastRoomEx = DRLGMAZE_PlaceAdjacentPresetRoomInline(pDrlgRoom, nDirection, 0);
        if (pLastRoomEx)
        {
            sSetChamberPreset(1, pLastRoomEx);
        }

        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerNextIds[nRand], &nRand);
        break;
    }
    case 48:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerPrevIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerWaypointIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerNextIds[nRand], &nRand);
        break;

    case 49:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerPrevIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerRadamentIds[nRand], &nRand);
        break;

    case 65:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerPrevIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2SewerChestIds[nRand], &nRand);
        break;

    default:
        break;
    }
}

// 0x00672BE0
static void DRLGMAZE_PlaceAct2TombStuff(D2DrlgLevelStrc* pLevel)
{
    D2DrlgPresetRoomStrc* pPreset = 0;
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        pPreset = pDrlgRoom->pMaze;
        if (pPreset->nLevelPrest > 428)
        {
            break;
        }
    }

    int nRand = 0;
    switch (pPreset->nLevelPrest)
    {
    case 446:
        nRand = 0;
        break;

    case 445:
        nRand = 1;
        break;

    case 447:
        nRand = 2;
        break;

    case 444:
        nRand = 3;
        break;

    default:
        D2_ASSERT(0, 1305);
    }

    if (pLevel->eLevelId >= 55 && pLevel->eLevelId <= 58)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombPrevIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_HALLSOFTHEDEADLEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombNextIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_STONYTOMBLEV2 || pLevel->eLevelId == LEVEL_CLAWVIPERTEMPLELEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombTreasureIds[nRand], &nRand);
    }

    if (pLevel->eLevelId >= 66 && pLevel->eLevelId <= 72 && pLevel->eLevelId != pLevel->pDrlg->nStaffTombLevel)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombTreasureIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_STONYTOMBLEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombTalRashaIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_HALLSOFTHEDEADLEV3)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombNext2Ids[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_STONYTOMBLEV2 || pLevel->eLevelId == LEVEL_CLAWVIPERTEMPLELEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombChest2Ids[nRand], &nRand);
    }

    if (pLevel->eLevelId == pLevel->pDrlg->nStaffTombLevel)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombOrificeIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == pLevel->pDrlg->nBossTombLevel)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2TombBossIds[nRand], &nRand);
    }
}

// 0x00672DC0
static void DRLGMAZE_PlaceAct2LairStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    if (pLevel->eLevelId == LEVEL_MAGGOTLAIRLEV3)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairSpecialIds[8], &nRand);
        nRand = 3;
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairSpecialIds[7], &nRand);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairSpecialIds[nRand], &nRand);
    }

    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2LairPrevIds[nRand], &nRand);
}

// 0x00672E50
void __fastcall DRLGMAZE_PlaceSummonerPreset(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct2ArcaneSummonerIds[nRand], &nRand);
}

// 0x00672EA0
static void DRLGMAZE_PlaceAct3DungeonStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3DungeonPrevIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3DungeonNextIds[nRand], &nRand);
}

// 0x00672F00
static void DRLGMAZE_PlaceAct3SewerStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3SewerPrevIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3SewerNextIds[nRand], &nRand);
}

// 0x00672F60
static void DRLGMAZE_PlaceAct3MephistoStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastPrevIds[nRand], &nRand);
    if (pLevel->eLevelId == LEVEL_DURANCEOFHATELEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastNextIds[nRand], &nRand);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastChestIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_DURANCEOFHATELEV1)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct3KurastChestIds[nRand], &nRand);
    }
}

// 0x00673000
static void DRLGMAZE_PlaceAct5TempleStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) % 3;
    const int nFirstRand = nRand;
    if (pLevel->eLevelId != LEVEL_HALLSOFVAUGHT)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5TemplePrevIds[nRand], &nRand);
    }

    if (pLevel->eLevelId == LEVEL_HALLSOFDEATHSCALLING)
    {
        D2_ASSERT(nRand != nFirstRand, 1532);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5TempleNextIds[nRand], &nRand);
    }
}

// 0x006730B0
static void DRLGMAZE_PlaceAct5BaalStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5BaalPrevIds[nRand], &nRand);
    if (pLevel->eLevelId == LEVEL_THEWORLDSTONEKEEPLEV2)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5BaalNextIds[nRand], &nRand);
    }
}

// 0x00673120
static void DRLGMAZE_PlaceAct1Barracks(D2DrlgLevelStrc* pLevel)
{
    D2DrlgLevelStrc* pOuterCloisterLevel = DRLG_GetLevel(pLevel->pDrlg, LEVEL_OUTERCLOISTER);
    int nDirection = pOuterCloisterLevel->pPreset->nDirection;
    D2DrlgRoomStrc* pDrlgRoom = gpfnMazeGetBarracksEntryRoom[nDirection](pLevel);
    int nX = pOuterCloisterLevel->nPosX;
    D2LvlMazeTxt* pMaze = pLevel->pMaze;
    int nY = pOuterCloisterLevel->nPosY;
    D2DrlgRoomStrc* pBarracksRoomEx = 0;

    switch (nDirection)
    {
    case 0:
        pBarracksRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 2, 167, 0, 1);
        DRLGROOM_AddOrth(&pBarracksRoomEx->pDrlgOrth, pOuterCloisterLevel, 2, 0);
        nX -= pBarracksRoomEx->pDrlgCoord.nPosX + pMaze->dwSizeX;
        nY += pOuterCloisterLevel->nHeight / 2 - pBarracksRoomEx->pDrlgCoord.nPosY;
        break;

    case 1:
        pBarracksRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 3, 167, 1, 1);
        DRLGROOM_AddOrth(&pBarracksRoomEx->pDrlgOrth, pOuterCloisterLevel, 3, 0);
        nX += pOuterCloisterLevel->nWidth / 2 - pBarracksRoomEx->pDrlgCoord.nPosX - 6;
        nY -= pBarracksRoomEx->pDrlgCoord.nPosY + pMaze->dwSizeY;
        break;

    case 2:
        pBarracksRoomEx = DRLGMAZE_InitRoomFixedPreset(pDrlgRoom, 0, 167, 2, 1);
        DRLGROOM_AddOrth(&pBarracksRoomEx->pDrlgOrth, pOuterCloisterLevel, 0, 0);
        nX += pOuterCloisterLevel->nWidth - pBarracksRoomEx->pDrlgCoord.nPosX;
        nY += pOuterCloisterLevel->nHeight / 2 - pBarracksRoomEx->pDrlgCoord.nPosY + 1;
        break;

    default:
        break;
    }

    if (MAZE_RollSeed(&pLevel->pSeed) & 1)
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksNextIds[nDirection], &nDirection);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksForgeIds[nDirection], &nDirection);
    }
    else
    {
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksForgeIds[nDirection], &nDirection);
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct1BarracksNextIds[nDirection], &nDirection);
    }

    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        pRoom->pDrlgCoord.nPosX += nX;
        pRoom->pDrlgCoord.nPosY += nY;
    }

    int nTileMinX = 0;
    int nTileMinY = 0;
    int nTileMaxX = 0;
    int nTileMaxY = 0;
    DRLG_GetMinAndMaxCoordinatesFromLevel(pLevel, &nTileMinX, &nTileMinY, &nTileMaxX, &nTileMaxY);
    pLevel->nPosX = nTileMinX;
    pLevel->nPosY = nTileMinY;
    pLevel->nWidth = nTileMaxX - nTileMinX;
    pLevel->nHeight = nTileMaxY - nTileMinY;
}

// 0x00673320
static void DRLGMAZE_PlaceAct4Lava(D2DrlgLevelStrc* pLevel)
{
    if (pLevel->pDrlg->nAct == 4)
    {
        return;
    }

    D2DrlgLevelStrc* pChaosSanctum = DRLG_GetLevel(pLevel->pDrlg, LEVEL_CHAOSSANCTUM);
    D2DrlgRoomStrc* pParentRoom = DRLGMAZE_GetFreeLocationForRoomNorth(pLevel);
    DRLGMAZE_InitRoomFixedPreset(pParentRoom, 3, 852, -1, 1);

    pParentRoom = DRLGMAZE_GetFreeLocationForRoomSouth(pLevel);
    D2DrlgRoomStrc* pBridgeRoomEx1 = DRLGMAZE_InitRoomFixedPreset(pParentRoom, 1, 855, -1, 1);
    D2DrlgRoomStrc* pBridgeRoomEx2 = DRLGMAZE_PlaceAdjacentPresetRoom(pBridgeRoomEx1, 1, 0);
    if (pBridgeRoomEx2)
    {
        MAZE_SetPreset(pBridgeRoomEx2, 856, -1);
    }

    D2DrlgRoomStrc* pBridgeRoomEx3 = DRLGMAZE_PlaceAdjacentPresetRoom(pBridgeRoomEx2, 1, 0);
    if (pBridgeRoomEx3)
    {
        MAZE_SetPreset(pBridgeRoomEx3, 856, -1);
    }

    DRLGROOM_AddOrth(&pBridgeRoomEx3->pDrlgOrth, pChaosSanctum, 1, 0);
    const int nX = pChaosSanctum->nPosX + 2 * pBridgeRoomEx3->pDrlgCoord.nWidth - pBridgeRoomEx3->pDrlgCoord.nPosX;
    const int nY = pChaosSanctum->nPosY + pChaosSanctum->nHeight - pBridgeRoomEx3->pDrlgCoord.nPosY;

    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct4LavaForgeIds[MAZE_RollSeed(&pLevel->pSeed) & 1], 0);
    DRLGMAZE_FillBlankMazeSpaces(pLevel, 836, pBridgeRoomEx3);

    for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
    {
        pRoom->pDrlgCoord.nPosX += nX;
        pRoom->pDrlgCoord.nPosY += nY;
    }

    int nTileMinX = 0;
    int nTileMinY = 0;
    int nTileMaxX = 0;
    int nTileMaxY = 0;
    DRLG_GetMinAndMaxCoordinatesFromLevel(pLevel, &nTileMinX, &nTileMinY, &nTileMaxX, &nTileMaxY);
    pLevel->nPosX = nTileMinX;
    pLevel->nPosY = nTileMinY;
    pLevel->nWidth = nTileMaxX - nTileMinX;
    pLevel->nHeight = nTileMaxY - nTileMinY;
}

// 0x00673530
static void DRLGMAZE_PlaceAct5IceStuff(D2DrlgLevelStrc* pLevel)
{
    int nRand = MAZE_RollSeed(&pLevel->pSeed) & 3;
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IcePrevIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceNextIds[nRand], &nRand);
    DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceShrineIds[nRand], &nRand);

    switch (pLevel->eLevelId)
    {
    case 115:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceSpecialIds[nRand], &nRand);

    case 113:
    case 118:
        DRLGMAZE_ScanReplaceSpecialPreset(pLevel, &gnAct5IceWaypointIds[nRand], &nRand);
        break;

    default:
        break;
    }
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x006735F0
void __fastcall DRLGMAZE_RollAct_1_2_3_BasicPresets(D2DrlgLevelStrc* pLevel)
{
    int nLevelPrestId;
    switch (pLevel->nLevelType)
    {
    case 3:
        nLevelPrestId = 52;
        break;

    case 4:
        nLevelPrestId = 108;
        break;

    case 7:
        nLevelPrestId = 167;
        break;

    case 8:
        nLevelPrestId = 205;
        break;

    case 10:
        nLevelPrestId = 257;
        break;

    case 13:
        nLevelPrestId = 301;
        break;

    case 17:
        nLevelPrestId = 413;
        break;

    case 22:
        nLevelPrestId = 753;
        break;

    case 24:
        nLevelPrestId = 664;
        break;

    case 25:
        nLevelPrestId = 704;
        break;

    default:
        return;
    }

    if (pLevel->eLevelId == LEVEL_DENOFEVIL)
    {
        return;
    }

    int aSlots[15] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int nIndex = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
    int nRemaining = D2_MAX(pLevel->nRooms / 5 + 1, 2);
    int nTries = 2 * pLevel->nRooms;

    for (int i = 0; i < 15; ++i)
    {
        const int nFirst = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
        const int nSecond = SEED_RollRandomNumber(&pLevel->pSeed) % 15;
        const int nSlot = aSlots[nFirst];
        aSlots[nFirst] = aSlots[nSecond];
        aSlots[nSecond] = nSlot;
    }

    while (nRemaining && nTries)
    {
        const int nPreset = nLevelPrestId + aSlots[nIndex];
        const int nNewPreset = nLevelPrestId + aSlots[nIndex] + 15;
        for (D2DrlgRoomStrc* pRoom = pLevel->ptRoomFirst; pRoom; pRoom = pRoom->pDrlgRoomNext)
        {
            if ((~(pRoom->pMaze->dwFlags >> 1) & 1) && pRoom->pMaze->nLevelPrest == nPreset)
            {
                D2DrlgPresetRoomStrc* pMaze = pRoom->pMaze;
                pMaze->dwFlags |= 2;
                --nRemaining;
                pMaze->nLevelPrest = nNewPreset;
                pMaze->nPickedFile = -1;
                break;
            }
        }

        --nTries;
        ++nIndex;
        nIndex -= nIndex / 15 * 15;
    }
}

// 0x00673A60
static void __stdcall DRLGMAZE_BuildRoomPresetArea(D2DrlgRoomStrc* pDrlgRoom, D2DrlgLevelStrc* pLevel)
{
    D2DrlgPresetRoomStrc* pPreset = pDrlgRoom->pMaze;
    D2DrlgCoordStrc* pDrlgCoord = &pDrlgRoom->pDrlgCoord;
    D2DrlgMapStrc* pDrlgMap = DRLGPRESET_AllocDrlgMap(pLevel, pPreset->nLevelPrest, pDrlgCoord, &pLevel->pSeed);
    DRLGMAZE_PickDrlgMapFile(pDrlgMap, pPreset->nPickedFile, pLevel);
    D2DrlgRoomStrc* pBuiltRoomEx = DRLGPRESET_BuildArea(pLevel, pDrlgMap, 0, pDrlgCoord->nWidth <= 12 && pDrlgCoord->nHeight <= 12);
    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (pDrlgOrth->bInit == 1)
        {
            DRLGROOM_AllocDrlgOrthsForRooms(pBuiltRoomEx, pDrlgOrth->pRoom, pDrlgOrth->nDirection);
        }
    }
    DRLGROOM_FreeRoomEx(pDrlgRoom);
}

// 0x00673AF0
static void DRLGMAZE_RollBasicPresets(D2DrlgLevelStrc* pLevel)
{
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    while (pDrlgRoom)
    {
        D2DrlgRoomStrc* pCurrentRoomEx = pDrlgRoom;
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
        DRLGMAZE_BuildRoomPresetArea(pCurrentRoomEx, pLevel);
    }
}

// 0x00673B10
void __fastcall DRLGMAZE_InitLevelData(D2DrlgLevelStrc* pLevel)
{
    pLevel->pMaze = DATATBLS_GetLvlMazeTxtRecordFromLevelId(pLevel->eLevelId);
    DRLG_SetLevelPositionAndSize(pLevel->pDrlg, pLevel);
}

// 0x00673B30
void __fastcall MazeLevelGenerate(D2DrlgLevelStrc* ptDrlgLevel)
{
    D2DrlgRoomStrc* pDrlgRoom = DRLGROOM_AllocRoomEx(ptDrlgLevel, 2);
    MAZE_SetRoomSizeFromMaze(pDrlgRoom);
    pDrlgRoom->pDrlgCoord.nPosX = ptDrlgLevel->nPosX + (ptDrlgLevel->nWidth - pDrlgRoom->pDrlgCoord.nWidth) / 2;
    pDrlgRoom->pDrlgCoord.nPosY = ptDrlgLevel->nPosY + (ptDrlgLevel->nHeight - pDrlgRoom->pDrlgCoord.nHeight) / 2;
    DRLGROOM_AddRoomExToLevel(ptDrlgLevel, pDrlgRoom);

    switch (ptDrlgLevel->nLevelType)
    {
    case 3:
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct1CaveStuff(ptDrlgLevel);
        break;

    case 4:
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct1CryptStuff(ptDrlgLevel);
        break;

    case 7:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        break;

    case 8:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct1JailStuff(ptDrlgLevel);
        break;

    case 10:
        DRLGMAZE_InitFirstMazeRoom(ptDrlgLevel, ptDrlgLevel->eLevelId == LEVEL_CATACOMBSLEV1);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct1CatacombsStuff(ptDrlgLevel);
        break;

    case 13:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_ScanReplaceSpecialAct2SewersPresets(ptDrlgLevel);
        break;

    case 14:
    case 15:
    case 23:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        break;

    case 17:
        if (ptDrlgLevel->eLevelId == LEVEL_CLAWVIPERTEMPLELEV2)
        {
            MAZE_SetPreset(pDrlgRoom, 480, -1);
        }
        else
        {
            DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(ptDrlgLevel);
            DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
            DRLGMAZE_PlaceAct2TombStuff(ptDrlgLevel);
        }
        break;

    case 18:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct2LairStuff(ptDrlgLevel);
        break;

    case 19:
        DRLGMAZE_PlaceArcaneSanctuary(ptDrlgLevel);
        DRLGMAZE_PlaceSummonerPreset(ptDrlgLevel);
        break;

    case 22:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct3MephistoStuff(ptDrlgLevel);
        break;

    case 24:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct3DungeonStuff(ptDrlgLevel);
        break;

    case 25:
        if (ptDrlgLevel->eLevelId == LEVEL_SEWERSA3LEV1)
        {
            DRLGMAZE_InitBasicMazeLayout(5, ptDrlgLevel);
            D2_ASSERT(MAZE_ReplaceRoomPreset(ptDrlgLevel, 709, 735, -1), 2121);
            D2_ASSERT(MAZE_ReplaceRoomPreset(ptDrlgLevel, 710, 736, -1), 2122);
            D2_ASSERT(MAZE_ReplaceRoomPreset(ptDrlgLevel, 713, 737, -1), 2123);
            D2_ASSERT(MAZE_ReplaceRoomPreset(ptDrlgLevel, 714, 738, -1), 2124);
            DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
            DRLGMAZE_PlaceAct3SewerStuff(ptDrlgLevel);
        }
        else
        {
            DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
            DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
            DRLGMAZE_PlaceAct3SewerStuff(ptDrlgLevel);
        }
        break;

    case 28:
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        break;

    case 33:
        switch (ptDrlgLevel->eLevelId)
        {
        case 114:
            D2_ASSERT(ptDrlgLevel->ptRoomFirst, 2142);
            MAZE_SetPreset(ptDrlgLevel->ptRoomFirst, SEED_RollLimitedRandomNumber(&pDrlgRoom->ptDrlgLevel->pSeed, 2) ? 1038 : 1039, -1);
            break;

        case 116:
            MAZE_SetPreset(ptDrlgLevel->ptRoomFirst, 1040, -1);
            break;

        case 119:
            MAZE_SetPreset(ptDrlgLevel->ptRoomFirst, 1041, -1);
            break;

        default:
            DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
            DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
            DRLGMAZE_PlaceAct5IceStuff(ptDrlgLevel);
            break;
        }
        break;

    case 32:
        DRLGMAZE_InitBasicMazeLayout(2, ptDrlgLevel);
        DRLGMAZE_PlaceAct5TempleStuff(ptDrlgLevel);
        break;

    case 34:
        DRLGMAZE_PlaceAct2TombPrev_Act5BaalPrev(ptDrlgLevel);
        DRLGMAZE_BuildBasicMaze(ptDrlgLevel);
        DRLGMAZE_PlaceAct5BaalStuff(ptDrlgLevel);
        break;

    case 35:
        DRLGMAZE_PlaceAct5LavaPresets(ptDrlgLevel);
        break;

    default:
        D2_ASSERT(0, 2179);
    }

    switch (ptDrlgLevel->eLevelId)
    {
    case 28:
        DRLGMAZE_PlaceAct1Barracks(ptDrlgLevel);
        break;

    case 107:
        DRLGMAZE_PlaceAct4Lava(ptDrlgLevel);
        break;

    default:
        DRLG_UpdateRoomExCoordinates(ptDrlgLevel);
        break;
    }

    DRLGMAZE_RollAct_1_2_3_BasicPresets(ptDrlgLevel);
    DRLGMAZE_RollBasicPresets(ptDrlgLevel);
}

// 0x00673FE0
void __fastcall DRLGMAZE_ResetMazeRecord(D2DrlgLevelStrc* pLevel, int bKeepMazeRecord)
{
    if (!bKeepMazeRecord)
    {
        pLevel->pMaze = 0;
    }
}

#include "gen/data/Source/D2Common/DRLG/Maze.inc"
