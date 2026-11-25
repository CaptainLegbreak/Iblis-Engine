#include "D2Common.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2DrlgPresets.h"
#include "D2DrlgTiles.h"
extern const int gnTileTypeMappingTable[]; // 0x006EEF20

struct D2TileLibraryEntryStrc;

struct D2DrlgCoordStrc;

struct D2DrlgRoomTilesStrc;

struct D2DrlgTileDataStrc;

int __fastcall DRLGGRID_GetGridEntry(D2DrlgGridStrc* pGrid, int nX, int nY); // 0x0067C570

int __stdcall TileLibraryGetTiles(D2TileLibraryHeaderStrc** ppTiles, int nTileType, int nStyle, int nSequence, D2TileLibraryEntryStrc** ppTileEntries, int nMaxEntries); // 0x00604AE0

int __stdcall TileGetFlags(D2TileLibraryEntryStrc* hTile); // 0x00604BC0


extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

#define D2_ASSERTM(expr, msg, line) D2_ASSERT(expr, line)

char* __cdecl ERRORMANAGER_Sprintf(char* szDest, const char* szFormat, ...);                                // 0x00407310

extern "C" const char gszDrlgAnimSourceFile[];                                                              // 0x006EEF08

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

int __stdcall TileGetRarity(D2TileLibraryEntryStrc* hTile); // 0x00604C20

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitWallTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry, int nTileType); // 0x0066DC50

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitFloorTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DEF0

D2DrlgTileDataStrc* __fastcall DRLGROOMTILE_InitShadowTileData(D2DrlgRoomStrc* pDrlgRoom, D2DrlgTileDataStrc** ppTileData, int nX, int nY, unsigned int nPackedTileInformation, D2TileLibraryEntryStrc* pTileLibraryEntry); // 0x0066DF40

static void __fastcall DRLGANIM_AllocAnimationTileGrid(D2DrlgRoomStrc* pDrlgRoom, int nAnimationSpeed, D2DrlgTileDataStrc* pTiles, int nTiles, D2DrlgGridStrc* pDrlgGrid, int nUnused);

static inline int GetMapTileLayer(unsigned int nMapTileFlags) { return int((nMapTileFlags & 0x1C000) >> 14) - 1; }

struct D2CommonStormSlotListBStrc;

struct D2CommonStormSlotArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2CommonStormSlotListBStrc* m_data;
    unsigned int m_chunk;

    ~D2CommonStormSlotArrayBStrc();                                                                         // 0x0060F950
};

struct D2CommonStormSlotGrowArrayBStrc : D2CommonStormSlotArrayBStrc
{
    ~D2CommonStormSlotGrowArrayBStrc();
};

struct D2CommonStormZero6105F0Strc
{
    int unk0x00;
    int n0x04;
    int n0x08;
    int n0x0C;
    int n0x10;
    int n0x14;
    D2CommonStormZero6105F0Strc();
};

extern const int gnTileTypeTable[];                                                                // 0x006EEF88

void __stdcall DUNGEON_GameTileToClientCoords(int* pX, int* pY);                                            // 0x00643310

void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pRoom, int nAnimationSpeed, D2DrlgGridStrc* pWallGrid, int nWalls, D2DrlgGridStrc* pFloorGrid, int nFloors, D2DrlgGridStrc* pShadowGrid);

// 0x0066D290
void __fastcall DRLGANIM_TestLoadAnimatedRoomTiles(D2DrlgRoomStrc* pDrlgRoom, D2DrlgGridStrc* pDrlgGrid, D2DrlgGridStrc* pTileTypeGrid, int nTileType, int nTileX, int nTileY)
{
    D2TileLibraryEntryStrc* ppTileEntries[40];

    const int nWidth = (nTileX == 0) + pDrlgRoom->pDrlgCoord.nWidth;
    const int nHeight = (nTileY == 0) + pDrlgRoom->pDrlgCoord.nHeight;
    D2DrlgRoomTilesStrc* pRoomTiles = &pDrlgRoom->ptDrlgTiles->pTiles;

    for (int nY = 0; nY < nHeight; ++nY)
    {
        for (int nX = 0; nX < nWidth; ++nX)
        {
            const unsigned int nTileInfo = DRLGGRID_GetGridEntry(pDrlgGrid, nX, nY);
            if (nTileInfo & 0x8000003)
            {
                const int nType = pTileTypeGrid ? DRLGGRID_GetGridEntry(pTileTypeGrid, nX, nY) : nTileType;

                unsigned char nStyle;
                unsigned char nSequence;
                if (nTileInfo)
                {
                    nStyle = (unsigned char)(nTileInfo >> 20) & 0x3F;
                    nSequence = (unsigned char)(nTileInfo >> 8);
                }
                else
                {
                    nStyle = 0;
                    nSequence = 0;
                }

                const int nTiles = TileLibraryGetTiles(&pDrlgRoom->pTiles, nType, nStyle, nSequence, ppTileEntries, 40);
                if (nTiles && TileGetFlags(ppTileEntries[0]) & 0x100)
                {
                    if (nTileInfo & 2)
                    {
                        pRoomTiles->nFloors += nTiles - 1;
                    }
                    else if (nTileInfo & 1)
                    {
                        pRoomTiles->nWalls += nTiles - 1;
                    }
                    else
                    {
                        pRoomTiles->nRoofs += nTiles - 1;
                    }

                    pDrlgRoom->dwFlags |= 0x8000000;
                }
            }
        }
    }
}

// build: symbol ?DRLGANIM_AnimateRoomTiles@@YAXPAUD2DrlgRoomStrc@@@Z 0x0066D3B0
static void DRLGANIM_AnimateRoomTiles(D2DrlgRoomStrc* pRoom)
{
    if (pRoom->dwFlags & 0x8000000 && pRoom->ptDrlgTiles)
    {
        for (D2DrlgAnimTileGridStrc* pAnim = (D2DrlgAnimTileGridStrc*)pRoom->ptDrlgTiles->pAnimTiles; pAnim; pAnim = pAnim->pNext)
        {
            if (pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8])
            {
                pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8]->dwFlags |= 8;
            }

            pAnim->nCurrentFrame = (pAnim->nCurrentFrame + pAnim->nAnimationSpeed) % (pAnim->nFrames << 8);

            if (pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8])
            {
                pAnim->ppMapTileData[pAnim->nCurrentFrame >> 8]->dwFlags &= ~8;
            }
        }
    }
}

// 0x0066D410
void __fastcall DRLGANIM_AnimateTiles(D2DrlgRoomStrc* pRoom)
{
    for (int i = 0; i < pRoom->nRoomsNear; ++i)
    {
        DRLGANIM_AnimateRoomTiles(pRoom->ppRoomsNear[i]);
    }
}

// 0x0066D440
static void __fastcall DRLGANIM_AllocAnimationTileGrid(D2DrlgRoomStrc* pDrlgRoom, int nAnimationSpeed, D2DrlgTileDataStrc* pTiles, int nTiles, D2DrlgGridStrc* pDrlgGrid, int nUnused)
{
    (void)nUnused;
    void* pMemPool = pDrlgRoom->ptDrlgLevel->pDrlg->pMempool;

    if (!pTiles)
    {
        return;
    }

    if (nAnimationSpeed == 0)
    {
        nAnimationSpeed = 80;
    }

    D2TileLibraryEntryStrc* pTileLibraryEntries[40];

    for (int i = 0; i < nTiles; ++i)
    {
        D2DrlgTileDataStrc& pCurrentTileData = pTiles[i];
        if (pCurrentTileData.pTile && (D2CMP_10079_GetTileFlags(pCurrentTileData.pTile) & 0x100))
        {
            const int nGridIdx = GetMapTileLayer(pCurrentTileData.dwFlags);
            const unsigned int nPackedTileInformation = DRLGGRID_GetGridEntry(&pDrlgGrid[nGridIdx], pCurrentTileData.nPosX, pCurrentTileData.nPosY);
            unsigned char nStyle;
            unsigned char nSeq;
            if (nPackedTileInformation)
            {
                nStyle = (nPackedTileInformation >> 20) & 0x3F;
                nSeq = (unsigned char)(nPackedTileInformation >> 8);
            }
            else
            {
                nStyle = 0;
                nSeq = 0;
            }

            unsigned int nFrames = TileLibraryGetTiles(&pDrlgRoom->pTiles, pCurrentTileData.nTileType, nStyle, nSeq, pTileLibraryEntries, 40);

            D2DrlgAnimTileGridStrc* pDrlgAnimTileGrid = (D2DrlgAnimTileGridStrc*)FOG_AllocPool(pMemPool, sizeof(D2DrlgAnimTileGridStrc), gszDrlgAnimSourceFile, 155, 0);
            memset(pDrlgAnimTileGrid, 0x00, sizeof(D2DrlgAnimTileGridStrc));
            pDrlgAnimTileGrid->nFrames = nFrames;
            pDrlgAnimTileGrid->nCurrentFrame = 0;
            pDrlgAnimTileGrid->ppMapTileData = (D2DrlgTileDataStrc**)FOG_AllocPool(pMemPool, nFrames * sizeof(D2DrlgTileDataStrc*), gszDrlgAnimSourceFile, 161, 0);
            memset(pDrlgAnimTileGrid->ppMapTileData, 0x00, nFrames * sizeof(D2DrlgTileDataStrc*));
            pDrlgAnimTileGrid->nAnimationSpeed = nAnimationSpeed;
            pDrlgAnimTileGrid->pNext = (D2DrlgAnimTileGridStrc*)pDrlgRoom->ptDrlgTiles->pAnimTiles;
            pDrlgRoom->ptDrlgTiles->pAnimTiles = pDrlgAnimTileGrid;

            unsigned int nEntryIndex;
            for (nEntryIndex = 0; nEntryIndex < nFrames; ++nEntryIndex)
            {
                if (TileGetRarity(pTileLibraryEntries[nEntryIndex]) == 0)
                {
                    break;
                }
            }
            char szBuffer[100] = {};
            D2_ASSERTM(nEntryIndex < nFrames, ERRORMANAGER_Sprintf(szBuffer, "Animating tiles missing Rarity %d Tile - Style %d Seq %d", 0, nStyle, nSeq), 182);

            pCurrentTileData.pTile = pTileLibraryEntries[nEntryIndex];
            pDrlgAnimTileGrid->ppMapTileData[0] = &pCurrentTileData;

            int nX = pDrlgRoom->pDrlgCoord.nPosX + pCurrentTileData.nPosX;
            int nY = pDrlgRoom->pDrlgCoord.nPosY + pCurrentTileData.nPosY;

            for (unsigned int nRarity = 1; nRarity < nFrames; ++nRarity)
            {
                unsigned int nEntry;
                for (nEntry = 0; nEntry < nFrames; ++nEntry)
                {
                    if (TileGetRarity(pTileLibraryEntries[nEntry]) == nRarity)
                    {
                        break;
                    }
                }

                D2_ASSERTM(nEntry < nFrames, ERRORMANAGER_Sprintf(szBuffer, "Animating tiles missing Rarity %d Tile - Style %d Seq %d", nRarity, nStyle, nSeq), 203);

                D2DrlgTileDataStrc* pNewTileData;
                if (pCurrentTileData.nTileType != 0)
                {
                    if (pCurrentTileData.nTileType != 13)
                    {
                        pNewTileData = DRLGROOMTILE_InitWallTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pTileLibraryEntries[nEntry], pCurrentTileData.nTileType);
                    }
                    else
                    {
                        pNewTileData = DRLGROOMTILE_InitShadowTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pTileLibraryEntries[nEntry]);
                    }
                }
                else
                {
                    pNewTileData = DRLGROOMTILE_InitFloorTileData(pDrlgRoom, 0, nX, nY, nPackedTileInformation, pTileLibraryEntries[nEntry]);
                }

                pDrlgAnimTileGrid->ppMapTileData[nRarity] = pNewTileData;
                pNewTileData->dwFlags |= 8;
            }
        }
    }
}

// 0x0066D700
void __fastcall DRLGANIM_AllocAnimationTileGrids(D2DrlgRoomStrc* pRoom, int nAnimationSpeed, D2DrlgGridStrc* pWallGrid, int nWalls, D2DrlgGridStrc* pFloorGrid, int nFloors, D2DrlgGridStrc* pShadowGrid)
{
    D2DrlgTileGridStrc* pTileGrid = pRoom->ptDrlgTiles;
    DRLGANIM_AllocAnimationTileGrid(pRoom, nAnimationSpeed, pTileGrid->pTiles.pWallTiles, pTileGrid->nWalls, pWallGrid, 0);
    DRLGANIM_AllocAnimationTileGrid(pRoom, nAnimationSpeed, pTileGrid->pFloorTiles, pTileGrid->nFloors, pFloorGrid, 0);
    DRLGANIM_AllocAnimationTileGrid(pRoom, nAnimationSpeed, pTileGrid->pRoofTiles, pTileGrid->nShadows, pShadowGrid, 0);
}

// 0x0066D750
void __fastcall DRLGANIM_UpdateFrameInAdjacentRooms(D2DrlgRoomStrc* pRoom1, D2DrlgRoomStrc* pRoom2)
{
    if (!pRoom2)
    {
        return;
    }

    int nCurrentFrame = 0;
    if (pRoom1)
    {
        for (int i = 0; i < pRoom1->nRoomsNear; ++i)
        {
            if (pRoom1->ppRoomsNear[i]->ptDrlgTiles && pRoom1->ppRoomsNear[i]->ptDrlgTiles->pAnimTiles)
            {
                nCurrentFrame = ((D2DrlgAnimTileGridStrc*)pRoom1->ppRoomsNear[i]->ptDrlgTiles->pAnimTiles)->nCurrentFrame;
                break;
            }
        }
    }

    for (int i = 0; i < pRoom2->nRoomsNear; ++i)
    {
        if (D2DrlgTileGridStrc* pTileGrid = pRoom2->ppRoomsNear[i]->ptDrlgTiles)
        {
            for (D2DrlgAnimTileGridStrc* pAnim = (D2DrlgAnimTileGridStrc*)pTileGrid->pAnimTiles; pAnim; pAnim = pAnim->pNext)
            {
                pAnim->nCurrentFrame = nCurrentFrame;
            }
        }
    }
}

D2CommonStormSlotGrowArrayBStrc::~D2CommonStormSlotGrowArrayBStrc()
{
}

D2CommonStormZero6105F0Strc::D2CommonStormZero6105F0Strc() : n0x04(0), n0x08(0), n0x0C(0), n0x10(0), n0x14(0)
{
}

// 0x0066D7E0
int __fastcall DRLGANIM_MapTileType(int nId)
{
    return gnTileTypeTable[nId];
}

// 0x0066D7F0
int __fastcall DRLGPRESET_MapTileType(int nId)
{
    return gnTileTypeMappingTable[nId];
}

// 0x0066D800
void __fastcall DRLGANIM_TileToClientCoords(int* pX, int* pY)
{
    *pY += 1;
    DUNGEON_GameTileToClientCoords(pX, pY);
    *pY += 0x28;
}

#include "gen/data/Source/D2Common/DRLG/DrlgAnim.inc"
