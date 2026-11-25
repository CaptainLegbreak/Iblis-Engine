#include "D2LevelIds.h"

#include "D2Common.h"

#include "D2Drlg.h"

#include "D2DrlgMaps.h"

#include "D2TxtTables.h"

#include "D2Structs.h"

#include "D2ItemsWorld.h"

#include "D2DrlgTiles.h"

struct D2DrlgVertexStrc;

struct D2RoomDataStrc;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0

D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY);  // 0x00642630

void __fastcall DRLGROOM_FreeRoomData(void* pMemPool, D2DrlgOrthStrc* pDrlgOrth);                           // 0x0066B530

int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY); // 0x0066B800

void __fastcall DRLGPRESET_FreeDrlgFile(D2DrlgFileStrc** ppDrlgFile);                                       // 0x00668300

void __fastcall DRLGGRID_AlterGridFlag(D2DrlgGridStrc* pDrlgGrid, int nX, int nY, int nFlag, int nOperation); // 0x0067C4F0

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pDrlgGrid, int nX, int nY);                            // 0x0067C570

void __fastcall DRLGGRID_FreeGrid(void* pMemPool, D2DrlgGridStrc* pDrlgGrid);                               // 0x0067CD90

void __fastcall DRLGVER_FreeVertices(void* pMemPool, D2DrlgVertexStrc** ppVertices);                        // 0x0067D1E0

#define DRLGROOMFLAG_NO_LOS_DRAW 0x80000

#define DRLGROOMFLAG_PRESET_UNITS_SPAWNED 0x4000000

struct D2PresetUnitStrc;

struct D2DrlgStrc;

union D2SeedStrc;

struct D2LvlSubTxt;

struct D2DrlgCoordStrc;

struct D2DrlgWarpStrc;

struct D2LevelDefBin;

struct D2DrlgOrthStrc;

enum D2C_J11DrlgConstants
{
    DRLGTYPE_MAZE = 1,
    DRLGTYPE_PRESET = 2,
    DRLGLEVELFLAG_AUTOMAP_REVEAL = 0x10,
    DRLGROOMFLAG_AUTOMAP_REVEAL = 0x40000,
};

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2LvlSubTxt* __fastcall DATATBLS_GetLvlSubTxtRecord(int nId); // 0x0061FA90

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __fastcall DRLGPRESET_AllocPresetRoomData(D2DrlgRoomStrc* pDrlgRoom); // 0x00666630

void __fastcall DRLGOUTROOM_AllocDrlgOutdoorRoom(D2DrlgRoomStrc* pRoom); // 0x0067D6D0

struct D2DrlgWarpStrc
{
    int nLevel;
    int nVis[16];
    D2DrlgWarpStrc* pNext;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470

D2DrlgRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0

char* __fastcall DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x00667010

D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord); // 0x0066AB00

unsigned int __fastcall DRLGOUTROOM_CheckOutdoorRoomFlag(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D7A0

int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall DRLGPRESET_FreePresetRoomData(D2DrlgRoomStrc* pDrlgRoom); // 0x006665B0

void __fastcall DRLGPRESET_FreePresetUnit(void* pMemPool, D2PresetUnitStrc* pPresetUnit); // 0x006675D0

void __fastcall DRLGROOM_FreeDrlgOrthToRoom(void* pMemPool, D2DrlgOrthStrc** ppDrlgOrth, D2DrlgRoomStrc* pDrlgRoom); // 0x0066B610

void __fastcall DRLGLOGIC_FreeDrlgCoordList(D2DrlgRoomStrc* pDrlgRoom); // 0x0066C6E0

void __fastcall DRLGROOMTILE_FreeTileGrid(D2DrlgRoomStrc* pDrlgRoom); // 0x0066F0B0

void __fastcall DRLGOUTROOM_FreeDrlgOutdoorRoom(D2DrlgRoomStrc* pDrlgRoom); // 0x0067D610

struct D2DrlgRoomStrc;

#pragma intrinsic(memset)

void __fastcall DRLGROOMTILE_FreeRoom(D2DrlgRoomStrc* pDrlgRoom, int bKeepRoom);                       // 0x0066F1A0

void __fastcall DRLGROOM_UnlinkActiveRoom(D2DrlgRoomStrc* pDrlgRoom, int bClient, unsigned int nFlags);

void __fastcall DRLGROOM_FreeRoomTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom);

void __fastcall DRLGROOM_AllocDrlgOrthForRoom(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection);

void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection);

void __fastcall DRLGROOM_FreeDrlgOrthsBetweenRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2);

static int DRLGROOM_CompareOrths(D2DrlgOrthStrc*, D2DrlgOrthStrc*); // 0x0066B6A0

static void __stdcall DRLGROOM_InsertOrthSorted(D2DrlgOrthStrc**, D2DrlgOrthStrc*); // 0x0066B720

static int DRLGROOM_CompareOrths(D2DrlgOrthStrc* pDrlgOrth1, D2DrlgOrthStrc* pDrlgOrth2);

static void __stdcall DRLGROOM_InsertOrthSorted(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgOrthStrc* pNew);

struct D2LvlWarpTxt;

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B4B0

void __stdcall DRLG_InitLevel(D2DrlgLevelStrc* pLevel);                                         // 0x006424A0

int __fastcall DRLG_IsTownLevel(int nLevelId);                                                       // 0x006426A0

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId);                      // 0x00642BB0

int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId);                   // 0x0066AF30

D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char nDirection);   // 0x0066AF50

void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset);

int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pIgnoredRoom, int nMargin);

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0066B3E0
D2DrlgRoomStrc* __fastcall DRLGROOM_AllocRoomEx(D2DrlgLevelStrc* pLevel, int nType)
{
    D2DrlgRoomStrc* pDrlgRoom = (D2DrlgRoomStrc*)sub_0040B430(pLevel->pDrlg->pMempool, sizeof(D2DrlgRoomStrc), ".\\DRLG\\DrlgRoom.cpp", 32, 0);
    memset(pDrlgRoom, 0, sizeof(D2DrlgRoomStrc));
    pDrlgRoom->nType = nType;
    pDrlgRoom->ptDrlgLevel = pLevel;
    pDrlgRoom->fRoomStatus = 4;
    SEED_InitLowSeed(&pDrlgRoom->pSeed, (unsigned int)SEED_RollRandomNumber(&pLevel->pSeed));
    pDrlgRoom->dwInitSeed = (unsigned int)SEED_RollRandomNumber(&pDrlgRoom->pSeed);
    if (pLevel->dwFlags & DRLGLEVELFLAG_AUTOMAP_REVEAL)
    {
        pDrlgRoom->dwFlags |= DRLGROOMFLAG_AUTOMAP_REVEAL;
    }
    switch (nType)
    {
    case DRLGTYPE_MAZE:
        DRLGOUTROOM_AllocDrlgOutdoorRoom(pDrlgRoom);
        break;
    case DRLGTYPE_PRESET:
        DRLGPRESET_AllocPresetRoomData(pDrlgRoom);
        break;
    }
    return pDrlgRoom;
}

// 0x0066B4C0
void __fastcall DRLGROOM_UnlinkActiveRoom(D2DrlgRoomStrc* pDrlgRoom, int bClient, unsigned int nFlags)
{
    pDrlgRoom->pRoom = 0;
    pDrlgRoom->dwOtherFlags = nFlags & 1;
    if (pDrlgRoom->dwFlags & 0x100000)
    {
        DRLGROOMTILE_FreeRoom(pDrlgRoom, bClient == 0);
    }
}

// 0x0066B4F0
void __fastcall DRLGROOM_FreeRoomTiles(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles;
    while (pRoomTile)
    {
        D2RoomTileStrc* pFree = pRoomTile;
        pRoomTile = pRoomTile->pNext;
        sub_0040B480(pMemPool, pFree, ".\\DRLG\\DrlgRoom.cpp", 88, 0);
    }

    pDrlgRoom->pRoomTiles = 0;
}

// 0x0066B800
int __fastcall DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY)
{
    if (pDrlgCoord1->nPosX < pDrlgCoord2->nPosX)
    {
        *pDistanceX = pDrlgCoord2->nPosX - pDrlgCoord1->nWidth - pDrlgCoord1->nPosX;
    }
    else
    {
        *pDistanceX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth - pDrlgCoord2->nPosX;
    }

    if (pDrlgCoord1->nPosY < pDrlgCoord2->nPosY)
    {
        *pDistanceY = pDrlgCoord2->nPosY - pDrlgCoord1->nHeight - pDrlgCoord1->nPosY;
    }
    else
    {
        *pDistanceY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight - pDrlgCoord2->nPosY;
    }

    return *pDistanceX >= nMaxDistance || *pDistanceY >= nMaxDistance;
}

// 0x0066B880
int __fastcall DRLG_CheckOverlappingWithOrthogonalMargin(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nOrthogonalDistanceMax)
{
    int nSignedDistanceX = 0;
    int nSignedDistanceY = 0;

    if (pDrlgCoord1->nPosX <= pDrlgCoord2->nPosX)
    {
        nSignedDistanceX = pDrlgCoord2->nPosX - pDrlgCoord1->nWidth - pDrlgCoord1->nPosX;
    }
    if (pDrlgCoord1->nPosX > pDrlgCoord2->nPosX)
    {
        nSignedDistanceX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth - pDrlgCoord2->nPosX;
    }

    if (pDrlgCoord1->nPosY <= pDrlgCoord2->nPosY)
    {
        nSignedDistanceY = pDrlgCoord2->nPosY - pDrlgCoord1->nHeight - pDrlgCoord1->nPosY;
    }
    if (pDrlgCoord1->nPosY > pDrlgCoord2->nPosY)
    {
        nSignedDistanceY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight - pDrlgCoord2->nPosY;
    }

    if (!nOrthogonalDistanceMax)
    {
        return nSignedDistanceX <= 0 && nSignedDistanceY <= 0;
    }

    if (nSignedDistanceX == 0 && nSignedDistanceY <= nOrthogonalDistanceMax)
    {
        return 1;
    }

    return nSignedDistanceY == 0 && nSignedDistanceX <= nOrthogonalDistanceMax;
}

// 0x0066BE10
static void __stdcall DRLGROOM_AddWarpRoomTile(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, unsigned char nWarpId)
{
    D2RoomTileStrc* pRoomTile = (D2RoomTileStrc*)sub_0040B430(pDrlgRoom1->ptDrlgLevel->pDrlg->pMempool, sizeof(D2RoomTileStrc), ".\\DRLG\\DrlgRoom.cpp", 802, 0);
    memset(pRoomTile, 0, sizeof(D2RoomTileStrc));
    pRoomTile->pUnused = pDrlgRoom2;
    pRoomTile->pLvlWarpTxtRecord = DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(pDrlgRoom1->ptDrlgLevel, nWarpId, 'b');
    pRoomTile->bEnabled = 1;
    pRoomTile->pNext = pDrlgRoom1->pRoomTiles;
    pDrlgRoom1->pRoomTiles = pRoomTile;
}

// 0x0066B560
void __fastcall DRLGROOM_AllocDrlgOrthForRoom(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection)
{
    for (D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom1->pDrlgOrth; pDrlgOrth; pDrlgOrth = pDrlgOrth->pNext)
    {
        if (pDrlgOrth->pRoom == pDrlgRoom2)
        {
            return;
        }
    }

    D2DrlgOrthStrc* pNew = (D2DrlgOrthStrc*)sub_0040B430(pDrlgRoom1->ptDrlgLevel->pDrlg->pMempool, sizeof(D2DrlgOrthStrc), ".\\DRLG\\DrlgRoom.cpp", 212, 0);
    memset(pNew, 0, sizeof(D2DrlgOrthStrc));
    pNew->pNext = pDrlgRoom1->pDrlgOrth;
    pDrlgRoom1->pDrlgOrth = pNew;
    pNew->pRoom = pDrlgRoom2;
    pNew->nDirection = nDirection;
    pNew->bInit = 1;
    pNew->pBox = &pDrlgRoom2->pDrlgCoord;
}

// 0x0066B5E0
void __fastcall DRLGROOM_AllocDrlgOrthsForRooms(D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2, int nDirection)
{
    DRLGROOM_AllocDrlgOrthForRoom(pDrlgRoom1, pDrlgRoom2, nDirection);
    DRLGROOM_AllocDrlgOrthForRoom(pDrlgRoom2, pDrlgRoom1, (nDirection - 2) & 3);
}

// 0x0066B670
void __fastcall DRLGROOM_FreeDrlgOrthsBetweenRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2)
{
    DRLGROOM_FreeDrlgOrthToRoom(pMemPool, &pDrlgRoom1->pDrlgOrth, pDrlgRoom2);
    DRLGROOM_FreeDrlgOrthToRoom(pMemPool, &pDrlgRoom2->pDrlgOrth, pDrlgRoom1);
}

// 0x0066B6A0
static int DRLGROOM_CompareOrths(D2DrlgOrthStrc* pDrlgOrth1, D2DrlgOrthStrc* pDrlgOrth2)
{
    if (pDrlgOrth1->nDirection > pDrlgOrth2->nDirection)
    {
        return 1;
    }

    if (pDrlgOrth1->nDirection == pDrlgOrth2->nDirection)
    {
        switch (pDrlgOrth2->nDirection)
        {
        case 0:
            if (pDrlgOrth1->pBox->nPosY > pDrlgOrth2->pBox->nPosY)
            {
                return 1;
            }
            break;

        case 1:
            if (pDrlgOrth1->pBox->nPosX < pDrlgOrth2->pBox->nPosX)
            {
                return 1;
            }
            break;

        case 2:
            if (pDrlgOrth1->pBox->nPosY < pDrlgOrth2->pBox->nPosY)
            {
                return 1;
            }
            break;

        case 3:
            if (pDrlgOrth1->pBox->nPosX > pDrlgOrth2->pBox->nPosX)
            {
                return 1;
            }
            break;
        }
    }

    return 0;
}

// 0x0066B720
static void __stdcall DRLGROOM_InsertOrthSorted(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgOrthStrc* pNew)
{
    if (!*ppDrlgOrth)
    {
        *ppDrlgOrth = pNew;
        return;
    }

    D2DrlgOrthStrc* pNext = (*ppDrlgOrth)->pNext;
    D2DrlgOrthStrc* pPrevious = *ppDrlgOrth;
    if (!pNext)
    {
        if (DRLGROOM_CompareOrths(pPrevious, pNew))
        {
            pNew->pNext = *ppDrlgOrth;
            *ppDrlgOrth = pNew;
            return;
        }
    }
    else
    {
        do
        {
            if (DRLGROOM_CompareOrths(pNext, pNew))
            {
                break;
            }

            pPrevious = pNext;
            pNext = pNext->pNext;
        }
        while (pNext);
    }

    pNew->pNext = pNext;
    pPrevious->pNext = pNew;
}

// 0x0066B790
void __fastcall DRLGROOM_AddOrth(D2DrlgOrthStrc** ppDrlgOrth, D2DrlgLevelStrc* pLevel, int nDirection, int bIsPreset)
{
    D2DrlgOrthStrc* pNew = (D2DrlgOrthStrc*)sub_0040B430(pLevel->pDrlg->pMempool, sizeof(D2DrlgOrthStrc), ".\\DRLG\\DrlgRoom.cpp", 351, 0);
    memset(pNew, 0, sizeof(D2DrlgOrthStrc));
    pNew->pLevel = pLevel;
    pNew->nDirection = nDirection;
    pNew->bPreset = bIsPreset;
    pNew->bInit = 0;
    pNew->pBox = &pLevel->pLevelCoords;
    DRLGROOM_InsertOrthSorted(ppDrlgOrth, pNew);
}

// 0x0066B860
int __fastcall DRLG_CheckNotOverlappingUsingManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistanceToAssumeCollision)
{
    int nSignedDistanceX;
    return DRLG_GetRectanglesManhattanDistanceAndCheckNotOverlapping(pDrlgCoord1, pDrlgCoord2, nMaxDistanceToAssumeCollision, &nSignedDistanceX, &nMaxDistanceToAssumeCollision);
}

// 0x0066B900
int __fastcall DRLGMAZE_CheckRoomNotOverlaping(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pIgnoredRoom, int nMargin)
{
    for (D2DrlgRoomStrc* pCurrentRoomEx = pLevel->ptRoomFirst; pCurrentRoomEx; pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext)
    {
        if (pCurrentRoomEx != pDrlgRoom1 && pCurrentRoomEx != pIgnoredRoom)
        {
            int nDistanceX;
            if (pDrlgRoom1->pDrlgCoord.nPosX < pCurrentRoomEx->pDrlgCoord.nPosX)
            {
                nDistanceX = pCurrentRoomEx->pDrlgCoord.nPosX - pDrlgRoom1->pDrlgCoord.nWidth - pDrlgRoom1->pDrlgCoord.nPosX;
            }
            else
            {
                nDistanceX = pDrlgRoom1->pDrlgCoord.nPosX - pCurrentRoomEx->pDrlgCoord.nWidth - pCurrentRoomEx->pDrlgCoord.nPosX;
            }

            int nDistanceY;
            if (pDrlgRoom1->pDrlgCoord.nPosY < pCurrentRoomEx->pDrlgCoord.nPosY)
            {
                nDistanceY = pCurrentRoomEx->pDrlgCoord.nPosY - pDrlgRoom1->pDrlgCoord.nHeight - pDrlgRoom1->pDrlgCoord.nPosY;
            }
            else
            {
                nDistanceY = pDrlgRoom1->pDrlgCoord.nPosY - pCurrentRoomEx->pDrlgCoord.nHeight - pCurrentRoomEx->pDrlgCoord.nPosY;
            }

            if (!(nDistanceX >= nMargin || nDistanceY >= nMargin))
            {
                return 0;
            }
        }
    }

    return 1;
}

// 0x0066B970
void __fastcall DRLGROOM_AddRoomExToLevel(D2DrlgLevelStrc* pLevel, D2DrlgRoomStrc* pDrlgRoom)
{
    pDrlgRoom->pDrlgRoomNext = pLevel->ptRoomFirst;
    ++pLevel->nRooms;
    pLevel->ptRoomFirst = pDrlgRoom;
}

// 0x0066B980
int __fastcall DRLGROOM_AreXYInsideCoordinates(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    if (nX < pDrlgCoord->nPosX)
    {
        return 0;
    }

    if (nY < pDrlgCoord->nPosY)
    {
        return 0;
    }

    if (nX >= pDrlgCoord->nWidth + pDrlgCoord->nPosX)
    {
        return 0;
    }

    return nY < pDrlgCoord->nHeight + pDrlgCoord->nPosY;
}

// 0x0066B9D0
int __fastcall DRLGROOM_AreXYInsideCoordinatesOrOnBorder(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    if (nX < pDrlgCoord->nPosX)
    {
        return 0;
    }

    if (nY < pDrlgCoord->nPosY)
    {
        return 0;
    }

    if (nX > pDrlgCoord->nWidth + pDrlgCoord->nPosX)
    {
        return 0;
    }

    return nY <= pDrlgCoord->nHeight + pDrlgCoord->nPosY;
}

// 0x0066BA20
int __fastcall DRLGROOM_AreSubtileXYInsideCoordinates(D2DrlgCoordStrc* pDrlgCoord, int nX, int nY)
{
    int nLeft = 5 * pDrlgCoord->nPosX;
    if (nX < nLeft)
    {
        return 0;
    }

    if (nX >= nLeft + 5 * pDrlgCoord->nWidth)
    {
        return 0;
    }

    int nTop = 5 * pDrlgCoord->nPosY;
    if (nY < nTop)
    {
        return 0;
    }

    return nY < nTop + 5 * pDrlgCoord->nHeight;
}

// 0x0066BA70
int __fastcall DRLGROOM_CheckLOSDraw(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case DRLGTYPE_MAZE:
        return 1;

    case DRLGTYPE_PRESET:
        return pDrlgRoom->dwFlags & DRLGROOMFLAG_NO_LOS_DRAW;
    }

    return 0;
}

// 0x0066BA90
unsigned int __fastcall DRLGROOM_CheckMazeRoomOutdoorFlag(D2DrlgRoomStrc* pDrlgRoom)
{
    switch (pDrlgRoom->nType)
    {
    case 1:
        return DRLGOUTROOM_CheckOutdoorRoomFlag(pDrlgRoom);
    }

    return 0;
}

// 0x0066BAA0
unsigned int __fastcall DRLGROOM_CheckWaypointFlags(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->dwFlags & 0x30000;
}

// 0x0066BAB0
int __fastcall DRLGROOM_GetLevelId(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->ptDrlgLevel->eLevelId;
}

// 0x0066BAC0
int __fastcall DRLGROOM_GetWarpDestinationLevel(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel)
{
    int nDestinationLevel;
    D2LvlWarpTxt* pLvlWarpTxtRecord;
    D2ActiveRoomStrc* pRoom = DRLGWARP_GetDestinationRoom(pDrlgRoom, nSourceLevel, &nDestinationLevel, &pLvlWarpTxtRecord);
    if (!pRoom)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 604);
        exit(-1);
    }

    pDrlgRoom = DUNGEON_GetRoomExFromRoom(pRoom);
    if (!pDrlgRoom)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 606);
        exit(-1);
    }

    if (!pDrlgRoom->ptDrlgLevel)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 607);
        exit(-1);
    }

    return pDrlgRoom->ptDrlgLevel->eLevelId;
}

// 0x0066BB20
int __fastcall DRLGROOM_GetLevelIdFromPopulatedRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!pDrlgRoom)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 619);
        exit(-1);
    }

    if (pDrlgRoom->dwFlags & 0x800000)
    {
        return 0;
    }

    return pDrlgRoom->ptDrlgLevel->eLevelId;
}

inline void DRLG_ComputeManhattanDistance(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int* pDistanceX, int* pDistanceY)
{
    if (pDrlgCoord1->nPosX < pDrlgCoord2->nPosX)
    {
        *pDistanceX = pDrlgCoord2->nPosX - pDrlgCoord1->nWidth - pDrlgCoord1->nPosX;
    }
    else
    {
        *pDistanceX = pDrlgCoord1->nPosX - pDrlgCoord2->nWidth - pDrlgCoord2->nPosX;
    }

    if (pDrlgCoord1->nPosY < pDrlgCoord2->nPosY)
    {
        *pDistanceY = pDrlgCoord2->nPosY - pDrlgCoord1->nHeight - pDrlgCoord1->nPosY;
    }
    else
    {
        *pDistanceY = pDrlgCoord1->nPosY - pDrlgCoord2->nHeight - pDrlgCoord2->nPosY;
    }
}

inline int DRLG_ComputeManhattanDistanceCheck(D2DrlgCoordStrc* pDrlgCoord1, D2DrlgCoordStrc* pDrlgCoord2, int nMaxDistance, int* pDistanceX, int* pDistanceY)
{
    DRLG_ComputeManhattanDistance(pDrlgCoord1, pDrlgCoord2, pDistanceX, pDistanceY);
    return *pDistanceX >= nMaxDistance || *pDistanceY >= nMaxDistance;
}

// 0x0066C100
void __fastcall DRLGROOM_FreeRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    DRLGROOM_FreeRoomTiles(pMemPool, pDrlgRoom);

    if (pDrlgRoom->ppRoomsNear)
    {
        sub_0040B480(pMemPool, pDrlgRoom->ppRoomsNear, ".\\DRLG\\DrlgRoom.cpp", 105, 0);
        pDrlgRoom->nRoomsNear = 0;
        pDrlgRoom->ppRoomsNear = 0;
    }

    switch (pDrlgRoom->nType)
    {
    case 1:
        DRLGOUTROOM_FreeDrlgOutdoorRoom(pDrlgRoom);
        break;

    case 2:
        DRLGPRESET_FreePresetRoomData(pDrlgRoom);
        break;
    }

    D2PresetUnitStrc* pPresetUnit = pDrlgRoom->pPresetUnits;
    while (pPresetUnit)
    {
        D2PresetUnitStrc* pFree = pPresetUnit;
        pPresetUnit = pPresetUnit->pNext;
        DRLGPRESET_FreePresetUnit(pMemPool, pFree);
    }

    D2DrlgOrthStrc* pDrlgOrth = pDrlgRoom->pDrlgOrth;
    while (pDrlgOrth)
    {
        D2DrlgOrthStrc* pCurrent = pDrlgOrth;
        pDrlgOrth = pDrlgOrth->pNext;
        if (pCurrent->bInit == 1)
        {
            D2DrlgRoomStrc* pTarget = pCurrent->pRoom;
            DRLGROOM_FreeDrlgOrthToRoom(pMemPool, &pDrlgRoom->pDrlgOrth, pTarget);
            DRLGROOM_FreeDrlgOrthToRoom(pMemPool, &pTarget->pDrlgOrth, pDrlgRoom);
        }
    }

    DRLGROOM_FreeRoomData(pMemPool, pDrlgRoom->pDrlgOrth);

    D2DrlgLevelStrc* pLevel = pDrlgRoom->ptDrlgLevel;
    D2DrlgRoomStrc* pCurrentRoomEx = pLevel->ptRoomFirst;
    if (pCurrentRoomEx == pDrlgRoom)
    {
        pLevel->ptRoomFirst = pDrlgRoom->pDrlgRoomNext;
        --pLevel->nRooms;
    }
    else
    {
        while (pCurrentRoomEx->pDrlgRoomNext)
        {
            if (pCurrentRoomEx->pDrlgRoomNext == pDrlgRoom)
            {
                pCurrentRoomEx->pDrlgRoomNext = pDrlgRoom->pDrlgRoomNext;
                --pLevel->nRooms;
                break;
            }

            pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext;
        }
    }

    DRLGROOMTILE_FreeTileGrid(pDrlgRoom);
    DRLGLOGIC_FreeDrlgCoordList(pDrlgRoom);
    sub_0040B480(pMemPool, pDrlgRoom, ".\\DRLG\\DrlgRoom.cpp", 174, 0);
}

// 0x0066B530
void __fastcall DRLGROOM_FreeRoomData(void* pMemPool, D2DrlgOrthStrc* pDrlgRoomData)
{
    D2DrlgOrthStrc* pRoomData = pDrlgRoomData;
    while (pRoomData)
    {
        D2DrlgOrthStrc* pFree = pRoomData;
        pRoomData = pRoomData->pNext;
        sub_0040B480(pMemPool, pFree, ".\\DRLG\\DrlgRoom.cpp", 189, 0);
    }
}

// 0x0066BBC0
static void DRLGROOM_SortRoomListByPosition(D2DrlgRoomStrc** ppRoomList, int nListSize)
{
    for (int j = nListSize - 1; j > 0; --j)
    {
        for (int i = 0; i < nListSize - 1; ++i)
        {
            D2DrlgRoomStrc* pDrlgRoom1 = ppRoomList[i + 1];
            D2DrlgRoomStrc* pDrlgRoom2 = ppRoomList[i];

            if (pDrlgRoom2->pDrlgCoord.nPosX >= pDrlgRoom1->pDrlgCoord.nPosX + pDrlgRoom1->pDrlgCoord.nWidth || pDrlgRoom2->pDrlgCoord.nPosY >= pDrlgRoom1->pDrlgCoord.nPosY + pDrlgRoom1->pDrlgCoord.nHeight)
            {
                ppRoomList[i] = pDrlgRoom1;
                ppRoomList[i + 1] = pDrlgRoom2;
            }
        }
    }
}

// 0x0066BDA0
static void __stdcall DRLGROOM_AddNearRoom(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, D2DrlgRoomStrc* pDrlgRoom2)
{
    ++pDrlgRoom1->nRoomsNear;
    pDrlgRoom1->ppRoomsNear = (D2DrlgRoomStrc**)FOG_ReallocPool(pMemPool, pDrlgRoom1->ppRoomsNear, sizeof(D2DrlgRoomStrc*) * pDrlgRoom1->nRoomsNear, ".\\DRLG\\DrlgRoom.cpp", 788, 0);
    if (!pDrlgRoom1->ppRoomsNear)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 789);
        exit(-1);
    }

    pDrlgRoom1->ppRoomsNear[pDrlgRoom1->nRoomsNear - 1] = pDrlgRoom2;
    DRLGROOM_SortRoomListByPosition(pDrlgRoom1->ppRoomsNear, pDrlgRoom1->nRoomsNear);
}

// 0x0066BE80
static int __stdcall DRLGROOM_LinkNearRoomsByWarp(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom1, unsigned char nWarpId, D2DrlgRoomStrc* pDrlgRoom2, char nWarpFlag, int nDirection)
{
    int bResult = 0;
    int nWarpMask = 1 << (nWarpFlag + 4);

    while (pDrlgRoom2)
    {
        if (nWarpMask & pDrlgRoom2->dwFlags)
        {
            if (nDirection == -1)
            {
                int nX;
                int nY;
                DRLG_ComputeManhattanDistance(&pDrlgRoom1->pDrlgCoord, &pDrlgRoom2->pDrlgCoord, &nX, &nY);

                if (nX < 6 && nY < 6)
                {
                    DRLGROOM_AddNearRoom(pMemPool, pDrlgRoom1, pDrlgRoom2);
                    bResult = 1;
                }
            }
            else
            {
                DRLGROOM_AddNearRoom(pMemPool, pDrlgRoom1, pDrlgRoom2);
                DRLGROOM_AddWarpRoomTile(pDrlgRoom1, pDrlgRoom2, nWarpId);
                return 1;
            }
        }

        pDrlgRoom2 = pDrlgRoom2->pDrlgRoomNext;
    }

    return bResult;
}

// 0x0066C220
static void __stdcall DRLGROOM_LinkRoomToWarpDestination(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom, unsigned char nWarpId)
{
    if (!pDrlgRoom || nWarpId >= 8)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 848);
        exit(-1);
    }

    D2DrlgLevelStrc* pLevel = pDrlgRoom->ptDrlgLevel;
    int nLevelId = pLevel->eLevelId;
    int* pSourceVisArray = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, nLevelId);
    int nDestinationLevelId = pSourceVisArray[nWarpId];
    D2DrlgLevelStrc* pDestinationLevel = DRLG_GetLevel(pLevel->pDrlg, nDestinationLevelId);
    int* pDestinationVisArray = DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, nDestinationLevelId);
    int nWarpDestination = DRLGWARP_GetWarpDestinationFromArray(pLevel, nWarpId);

    if (!pDestinationLevel->ptRoomFirst)
    {
        DRLG_InitLevel(pDestinationLevel);
    }

    int bLinkedWarp = 0;
    if (nWarpDestination != -1)
    {
        int nSourceVisCount = 0;
        int nDestinationVisCount = 0;
        for (unsigned char i = 0; i < nWarpId; ++i)
        {
            if (pSourceVisArray[i] == nDestinationLevelId)
            {
                ++nSourceVisCount;
            }
        }

        for (unsigned char i = 0; i < 8; ++i)
        {
            if (pDestinationVisArray[i] == nLevelId)
            {
                if (nSourceVisCount == nDestinationVisCount)
                {
                    if (DRLGROOM_LinkNearRoomsByWarp(pMemPool, pDrlgRoom, nWarpId, pDestinationLevel->ptRoomFirst, i, nWarpDestination))
                    {
                        bLinkedWarp = 1;
                    }
                    break;
                }

                ++nDestinationVisCount;
            }
        }
    }

    if (!bLinkedWarp)
    {
        for (unsigned char i = 0; i < 8; ++i)
        {
            if (pDestinationVisArray[i] == nLevelId && DRLGROOM_LinkNearRoomsByWarp(pMemPool, pDrlgRoom, nWarpId, pDestinationLevel->ptRoomFirst, i, nWarpDestination))
            {
                break;
            }
        }
    }
}

// 0x0066BC20
static void __stdcall DRLGROOM_CollectNearRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgRoomStrc* ppNearRooms[30];

    D2DrlgRoomStrc* pCurrentRoomEx = pDrlgRoom->ptDrlgLevel->ptRoomFirst;
    pDrlgRoom->nRoomsNear = 0;

    while (pCurrentRoomEx)
    {
        int nX;
        int nY;

        if (DRLG_ComputeManhattanDistanceCheck(&pDrlgRoom->pDrlgCoord, &pCurrentRoomEx->pDrlgCoord, 6, &nX, &nY))
        {
            pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext;
        }
        else
        {
            ppNearRooms[pDrlgRoom->nRoomsNear] = pCurrentRoomEx;
            pCurrentRoomEx = pCurrentRoomEx->pDrlgRoomNext;
            ++pDrlgRoom->nRoomsNear;
        }
    }

    int nRoomsNear = pDrlgRoom->nRoomsNear;
    DRLGROOM_SortRoomListByPosition(ppNearRooms, nRoomsNear);

    pDrlgRoom->ppRoomsNear = (D2DrlgRoomStrc**)sub_0040B430(pMemPool, sizeof(D2DrlgRoomStrc*) * nRoomsNear, ".\\DRLG\\DrlgRoom.cpp", 715, 0);

    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        pDrlgRoom->ppRoomsNear[i] = ppNearRooms[i];
    }
}

// 0x0066BD50
static void DRLGROOM_FlagIfNearTown(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!DRLG_IsTownLevel(pDrlgRoom->ptDrlgLevel->eLevelId))
    {
        for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
        {
            if (DRLG_IsTownLevel(pDrlgRoom->ppRoomsNear[i]->ptDrlgLevel->eLevelId))
            {
                pDrlgRoom->dwFlags |= 0x800000;
                return;
            }
        }
    }
}

// 0x0066C370
void __fastcall DRLGROOM_InitNearRooms(void* pMemPool, D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGROOM_CollectNearRooms(pMemPool, pDrlgRoom);

    if (pDrlgRoom->dwFlags & 0xFF0)
    {
        int nFlags = 0x10;
        unsigned char nWarpId = 0;

        do
        {
            if ((nFlags & pDrlgRoom->dwFlags) && pDrlgRoom->ptDrlgLevel->eLevelId != LEVEL_PANDEMONIUMRUN1)
            {
                DRLGROOM_LinkRoomToWarpDestination(pMemPool, pDrlgRoom, nWarpId);
            }

            nFlags <<= 1;
            ++nWarpId;
        }
        while (nFlags & 0xFF0);
    }

    DRLGROOM_FlagIfNearTown(pDrlgRoom);
}

// 0x0066B610
void __fastcall DRLGROOM_FreeDrlgOrthToRoom(void* pMemPool, D2DrlgOrthStrc** ppDrlgOrth, D2DrlgRoomStrc* pDrlgRoom)
{
    D2DrlgOrthStrc* pDrlgOrth = *ppDrlgOrth;
    D2DrlgOrthStrc* pNext = pDrlgOrth->pNext;
    if (pDrlgOrth->bInit == 1 && pDrlgOrth->pRoom == pDrlgRoom)
    {
        *ppDrlgOrth = pNext;
        pNext = pDrlgOrth;
    }
    else
    {
        if (!pNext)
        {
            return;
        }

        while (pNext->bInit != 1 || pNext->pRoom != pDrlgRoom)
        {
            pDrlgOrth = pNext;
            pNext = pNext->pNext;
            if (!pNext)
            {
                return;
            }
        }

        pDrlgOrth->pNext = pNext->pNext;
    }

    sub_0040B480(pMemPool, pNext, ".\\DRLG\\DrlgRoom.cpp", 277, 0);
}

// 0x0066BB60
int __fastcall DRLGROOM_HasWaypoint(D2DrlgRoomStrc* ptRoom)
{
    if (!ptRoom)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 630);
        exit(-1);
    }

    return DRLGROOM_CheckWaypointFlags(ptRoom) != 0;
}

// 0x0066BBA0
const char* __fastcall DRLGROOM_GetPickedLevelPrestFilePathFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    if (pDrlgRoom->nType == 2)
    {
        return DRLGPRESET_GetPickedLevelPrestFilePathFromRoomEx(pDrlgRoom);
    }

    return "None";
}

// 0x0066BCF0
int __fastcall DRLGROOM_GetNumberOfNearRooms(D2DrlgRoomStrc* pDrlgRoom)
{
    return pDrlgRoom->nRoomsNear;
}

// 0x0066BD00
int __fastcall DRLGROOM_ReorderNearRoomList(D2DrlgRoomStrc* pDrlgRoom, void** ppRoomList)
{
    int nRooms = 0;

    for (int i = 0; i < pDrlgRoom->nRoomsNear; ++i)
    {
        if (pDrlgRoom->ppRoomsNear[i]->pRoom)
        {
            ppRoomList[nRooms] = pDrlgRoom->ppRoomsNear[i]->pRoom;
            ++nRooms;
        }
    }

    for (int i = nRooms; i < pDrlgRoom->nRoomsNear; ++i)
    {
        ppRoomList[i] = 0;
    }

    return nRooms;
}

// 0x0066BF30
D2PresetUnitStrc* __fastcall DRLGROOM_AllocPresetUnit(D2DrlgRoomStrc* pDrlgRoom, void* pMemPool, int nUnitType, int nIndex, int nMode, int nX, int nY)
{
    D2PresetUnitStrc* pPresetUnit = (D2PresetUnitStrc*)sub_0040B430(pMemPool, sizeof(D2PresetUnitStrc), ".\\DRLG\\DrlgRoom.cpp", 950, 0);
    memset(pPresetUnit, 0, sizeof(D2PresetUnitStrc));
    pPresetUnit->nUnitType = nUnitType;
    pPresetUnit->nIndex = nIndex;
    pPresetUnit->nMode = nMode;
    pPresetUnit->nXpos = nX;
    pPresetUnit->nYpos = nY;

    if (pDrlgRoom)
    {
        pPresetUnit->pNext = pDrlgRoom->pPresetUnits;
        pDrlgRoom->pPresetUnits = pPresetUnit;
    }
    else
    {
        pPresetUnit->pNext = 0;
    }

    return pPresetUnit;
}

// 0x0066BFA0
D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom)
{
    if (!(pDrlgRoom->dwFlags & DRLGROOMFLAG_AUTOMAP_REVEAL))
    {
        if (pDrlgRoom->dwFlags & DRLGROOMFLAG_PRESET_UNITS_SPAWNED)
        {
            return 0;
        }

        pDrlgRoom->dwFlags |= DRLGROOMFLAG_PRESET_UNITS_SPAWNED;
    }

    return pDrlgRoom->pPresetUnits;
}

// 0x0066BFC0
void __fastcall DRLGROOM_SetRoom(D2DrlgRoomStrc* pDrlgRoom, D2ActiveRoomStrc* pRoom)
{
    pDrlgRoom->pRoom = pRoom;
}

// 0x0066BFD0
void __fastcall DRLGROOM_GetRGB_IntensityFromRoomEx(D2DrlgRoomStrc* pDrlgRoom, unsigned char* pIntensity, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue)
{
    D2LevelDefBin* pLevelDefRecord = DATATBLS_GetLevelDefRecord(pDrlgRoom->ptDrlgLevel->eLevelId);

    *pIntensity = pLevelDefRecord->nIntensity;
    *pRed = pLevelDefRecord->nRed;
    *pGreen = pLevelDefRecord->nGreen;
    *pBlue = pLevelDefRecord->nBlue;
}

// 0x0066C020
int __fastcall DRLGROOM_GetDrlgTypeFromRoom(D2DrlgRoomStrc* pDrlgRoom)
{
    return DATATBLS_GetLevelDefRecord(pDrlgRoom->ptDrlgLevel->eLevelId)->dwDrlgType;
}

// 0x0066C040
int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* pDrlgWarp = pDrlg->pWarp; pDrlgWarp; pDrlgWarp = pDrlgWarp->pNext)
    {
        if (!pDrlgWarp->nLevel)
        {
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1040);
            exit(-1);
        }

        if (nLevelId == pDrlgWarp->nLevel)
        {
            return pDrlgWarp->nVis;
        }
    }

    return DATATBLS_GetLevelDefRecord(nLevelId)->dwVis;
}

// 0x0066C090
int* __fastcall DRLGROOM_GetVisArrayFromLevel(D2DrlgLevelStrc* pLevel)
{
    return DRLGROOM_GetVisArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
}

// 0x0066C0B0
D2DrlgStrc* __fastcall DRLGROOM_GetDrlgFromRoomEx(D2DrlgRoomStrc* pRoom)
{
    if (!pRoom)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1067);
        exit(-1);
    }

    if (!pRoom->ptDrlgLevel)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1068);
        exit(-1);
    }

    if (!pRoom->ptDrlgLevel->pDrlg)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1069);
        exit(-1);
    }

    return pRoom->ptDrlgLevel->pDrlg;
}

#include "gen/data/Source/D2Common/DRLG/DrlgRoom.inc"
