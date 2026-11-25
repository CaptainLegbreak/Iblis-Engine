#include "D2Common.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2DrlgTiles.h"
#include "D2DrlgWarp.h"

struct D2ActiveRoomStrc;

struct D2DrlgStrc;

struct D2DrlgListEntryStrc;

struct D2DrlgListOwnerStrc;

struct D2DrlgWarpStrc;

struct D2LevelDefBin;

struct D2RoomTileStrc;

union D2SeedStrc;

struct D2PresetUnitStrc;

struct D2ObjectsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2DrlgTileDataStrc
{
    char unk0x00[0x14];
    unsigned int dwFlags;
    char unk0x18[0x08];
    D2DrlgTileDataStrc* pNext;
};

struct D2DrlgRoomStrc
{
    char unk0x00[0x24];
    union
    {
        D2DrlgRoomStrc* pDrlgRoomNext;
        D2DrlgRoomStrc* pNext;
    };
    unsigned int dwFlags;
    char unk0x2C[0x04];
    D2ActiveRoomStrc* pRoom;
    int nTileXPos;
    int nTileYPos;
    int nTileWidth;
    int nTileHeight;
    unsigned char unk_44[0x8];
    D2RoomTileStrc* pRoomTiles;
    unsigned char unk_50[0xC];
    D2PresetUnitStrc* pPresetUnits;
};

struct D2DrlgTileInfoStrc
{
    int nPosX;
    int nPosY;
    int nTileIndex;
};

struct D2TileGroupStrc
{
    int bValid;
    int nGroup;
};

struct D2DrlgLevelStrc
{
    char unk0x00[0x08];
    int nRooms;
    char unk0x0C[0x04];
    D2DrlgRoomStrc* ptRoomFirst;
    char unk0x14[0x08];
    int nPosX;
    int nPosY;
    int nWidth;
    int nHeight;
    D2DrlgTileInfoStrc pTileInfo[32];
    char unk0x1AC[0x08];
    D2DrlgStrc* pDrlg;
    char unk0x1B8[0x0C];
    D2SeedStrc pSeed;
    char unk0x1CC[0x04];
    int eLevelId;
    char unk0x1D4[0x04];
    int nTileInfo;
    D2DrlgRoomStrc* sub_0066AC40_GetTileRoom(int nTileIndex, int* pX, int* pY);    // 0x0066AC40
};

struct D2DrlgListEntryStrc
{
    char unk0x00[0x24];
    D2DrlgListEntryStrc* pNext;
    int dwFlags;
};

struct D2DrlgListOwnerStrc
{
    char unk0x00[0x10];
    D2DrlgListEntryStrc* pFirst;
};

unsigned int __fastcall sub_006C9A38(const char* szString); // 0x006C9A38

D2ActiveRoomStrc* __fastcall DRLGACTIVATE_InitializeRoomEx(D2DrlgRoomStrc* pDrlgRoom); // 0x0061B730

struct D2DrlgStrc
{
    char unk0x00[0x90];
    D2DrlgWarpStrc* pWarp;
};

int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066AEC0

int* __fastcall DRLGROOM_GetVisArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId); // 0x0066C040

struct D2LvlWarpTxt
{
    int dwLevelId;
};


D2LevelDefBin* __fastcall DATATBLS_GetLevelDefRecord(int nLevelId); // 0x0061E470

unsigned int __fastcall DRLGROOM_CheckWaypointFlags(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BAA0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

D2DrlgLevelStrc* __stdcall DRLG_GetLevel(D2DrlgStrc* pDrlg, int nLevelId); // 0x00642BB0

D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromLevelAndCoordinates(D2DrlgLevelStrc* pLevel, int nX, int nY); // 0x00642630

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

D2PresetUnitStrc* __fastcall DRLGROOM_GetPresetUnits(D2DrlgRoomStrc* pDrlgRoom); // 0x0066BFA0

void __fastcall DRLGOUTPLACE_CreateLevelConnections(D2DrlgStrc* pDrlg); // 0x00678AD0

static D2DrlgRoomStrc* __stdcall DRLGWARP_GetWaypointRoomExFromLevel(D2DrlgLevelStrc* pLevel, int* pX, int* pY);

static D2DrlgRoomStrc* DRLGWARP_GetFirstWarpRoom(D2DrlgLevelStrc* pLevel);

D2ActiveRoomStrc* __fastcall DRLGWARP_GetLevelEntryRoom(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY);

// 0x0066A290
void __cdecl DRLGWARP_ShouldNeverBeCalled()
{
    D2_ASSERT(0, 0x65);
}

// 0x0066A870
static inline int DRLGWARP_SumStringBytes(const char* szText)
{
    int nSum = 0;
    while (*szText)
    {
        nSum += (unsigned char)*szText;
        ++szText;
    }

    return nSum & 0xFF;
}

// 0x0066A890
static inline int DRLGWARP_AreCodesEqual(const char* szA, const char* szB)
{
    D2_ASSERT(sub_006C9A38(szA) <= 8, 0xD9);
    D2_ASSERT(sub_006C9A38(szB) <= 8, 0xDA);
    if (*(const int*)szA != *(const int*)szB)
    {
        return 0;
    }

    return *(const int*)(szA + 4) == *(const int*)(szB + 4);
}

// 0x0066AB00
D2ActiveRoomStrc* __fastcall DRLGWARP_GetDestinationRoom(D2DrlgRoomStrc* pDrlgRoom, int nSourceLevel, int* pDestinationLevel, D2LvlWarpTxt** ppLvlWarpTxtRecord)
{
    for (D2RoomTileStrc* pSourceRoomTile = pDrlgRoom->pRoomTiles; pSourceRoomTile; pSourceRoomTile = pSourceRoomTile->pNext)
    {
        if (pSourceRoomTile->pLvlWarpTxtRecord->dwLevelId == nSourceLevel)
        {
            D2DrlgRoomStrc* pDestinationRoom = (D2DrlgRoomStrc*)pSourceRoomTile->pUnused;
            for (D2RoomTileStrc* pDestinationRoomTile = pDestinationRoom->pRoomTiles; pDestinationRoomTile; pDestinationRoomTile = pDestinationRoomTile->pNext)
            {
                if (pDestinationRoomTile->pUnused == pDrlgRoom)
                {
                    *pDestinationLevel = pDestinationRoomTile->pLvlWarpTxtRecord->dwLevelId;
                    *ppLvlWarpTxtRecord = pDestinationRoomTile->pLvlWarpTxtRecord;

                    if (!pDestinationRoom->pRoom)
                    {
                        DRLGACTIVATE_InitializeRoomEx(pDestinationRoom);
                    }

                    return pDestinationRoom->pRoom;
                }
            }

            return 0;
        }
    }

    return 0;
}

// 0x0066AB70
void __fastcall DRLGWARP_ToggleRoomTilesEnableFlag(D2DrlgRoomStrc* pDrlgRoom, int bEnabled)
{
    for (D2RoomTileStrc* i = pDrlgRoom->pRoomTiles; i; i = i->pNext)
    {
        i->bEnabled = bEnabled;
    }
}

// 0x0066AB90
void __fastcall DRLGWARP_UpdateWarpRoomSelect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId)
{
    for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
    {
        if (pRoomTile->pLvlWarpTxtRecord->dwLevelId == nLevelId)
        {
            if (pRoomTile->pSelectedTiles)
            {
                for (D2DrlgTileDataStrc* i = pRoomTile->pSelectedTiles; i; i = i->pNext)
                {
                    i->dwFlags &= 0xFFFFFFF7;
                }

                for (D2DrlgTileDataStrc* i = pRoomTile->pUnselectedTiles; i; i = i->pNext)
                {
                    i->dwFlags |= 8;
                }
            }
            return;
        }
    }
}

// 0x0066ABE0
void __fastcall DRLGWARP_UpdateWarpRoomDeselect(D2DrlgRoomStrc* pDrlgRoom, int nLevelId)
{
    for (D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles; pRoomTile; pRoomTile = pRoomTile->pNext)
    {
        if (pRoomTile->pLvlWarpTxtRecord->dwLevelId == nLevelId)
        {
            if (pRoomTile->pUnselectedTiles)
            {
                for (D2DrlgTileDataStrc* i = pRoomTile->pUnselectedTiles; i; i = i->pNext)
                {
                    i->dwFlags &= 0xFFFFFFF7;
                }

                for (D2DrlgTileDataStrc* i = pRoomTile->pSelectedTiles; i; i = i->pNext)
                {
                    i->dwFlags |= 8;
                }
            }
            return;
        }
    }
}

// 0x0066AC30
static inline D2ActiveRoomStrc* DRLGWARP_GetActiveRoomFromRoomEx(D2DrlgRoomStrc* pDrlgRoom)
{
    DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
    return pDrlgRoom->pRoom;
}

static inline int* sub_0066AEC0(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* pDrlgWarp = pDrlg->pWarp; pDrlgWarp; pDrlgWarp = pDrlgWarp->pNext)
    {
        D2_ASSERT(pDrlgWarp->nLevel, 418);
        if (nLevelId == pDrlgWarp->nLevel)
        {
            return pDrlgWarp->nWarp;
        }
    }
    return DATATBLS_GetLevelDefRecord(nLevelId)->dwWarp;
}

extern D2TileGroupStrc gaTileGroups[];                                                             // 0x006EED88
D2DrlgRoomStrc* __fastcall DRLG_GetRoomExFromCoordinates(int nX, int nY, D2DrlgStrc* pDrlg, D2DrlgRoomStrc* pRoomHint, D2DrlgLevelStrc* pLevel); // 0x00642C30

static inline int TileMatches(int nTileIndex, int nOther)
{
    return nTileIndex == nOther || (gaTileGroups[nTileIndex].bValid && gaTileGroups[nTileIndex].nGroup == gaTileGroups[nOther].nGroup);
}

static inline unsigned int SEED_RollLimitedRandomNumber_Inline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    unsigned int const tNHighSeed = pSeed->nHighSeed;
    if ((nMax - 1) & nMax)
    {
        unsigned __int64 lSeed = tNHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
        pSeed->nLowSeed = (unsigned int)lSeed;
        return (unsigned int)lSeed % nMax;
    }

    unsigned __int64 lSeed = tNHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed & (nMax - 1);
}

// 0x0066AC40
D2DrlgRoomStrc* D2DrlgLevelStrc::sub_0066AC40_GetTileRoom(int nTileIndex, int* pX, int* pY)
{
    int nCount = 0;
    for (int i = 0; i < nTileInfo; ++i)
    {
        if (TileMatches(nTileIndex, pTileInfo[i].nTileIndex))
        {
            ++nCount;
        }
    }

    int nPick;
    if (nCount)
    {
        nPick = SEED_RollLimitedRandomNumber_Inline(&pSeed, nCount) + 1;
    }
    else
    {
        nPick = 0;
    }

    int i = 0;
    const D2DrlgTileInfoStrc* pInfo = pTileInfo;
    for (; i < nTileInfo; ++i, ++pInfo)
    {
        const int nTile = pInfo->nTileIndex;
        if (nTileIndex == nTile || (gaTileGroups[nTileIndex].bValid && gaTileGroups[nTileIndex].nGroup == gaTileGroups[nTile].nGroup))
        {
            --nPick;
        }

        if (nPick <= 0)
        {
            break;
        }
    }

    *pX = pTileInfo[i].nPosX;
    *pY = pTileInfo[i].nPosY;
    return DRLG_GetRoomExFromCoordinates(*pX, *pY, pDrlg, 0, this);
}

// 0x0066AD80
static D2DrlgRoomStrc* __stdcall DRLGWARP_GetWaypointRoomExFromLevel(D2DrlgLevelStrc* pLevel, int* pX, int* pY)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (DRLGROOM_CheckWaypointFlags(pDrlgRoom))
        {
            DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
            for (D2PresetUnitStrc* pPresetUnit = pDrlgRoom->pPresetUnits; pPresetUnit; pPresetUnit = pPresetUnit->pNext)
            {
                if (pPresetUnit->nUnitType == 2 && pPresetUnit->nIndex < 573 && (DATATBLS_GetObjectsTxtRecord(pPresetUnit->nIndex)->nSubClass & 0x40))
                {
                    *pX = pDrlgRoom->nTileXPos + pPresetUnit->nXpos / 5;
                    *pY = pDrlgRoom->nTileYPos + pPresetUnit->nYpos / 5;
                    return pDrlgRoom;
                }
            }
            return pDrlgRoom;
        }
    }
    return 0;
}

// 0x0066AE30
D2DrlgRoomStrc* __fastcall DRLGROOM_GetRoomExAtLevelCenterOffset(D2DrlgLevelStrc* pLevel, int nUnused, int nOffsetX, int nOffsetY)
{
    const int nX = pLevel->nWidth / 2 + pLevel->nPosX + nOffsetX - 2;
    const int nY = pLevel->nHeight / 2 + pLevel->nPosY + nOffsetY - 2;
    return DRLG_GetRoomExFromLevelAndCoordinates(pLevel, nX, nY);
}

// 0x0066AEC0
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevelId(D2DrlgStrc* pDrlg, int nLevelId)
{
    for (D2DrlgWarpStrc* pDrlgWarp = pDrlg->pWarp; pDrlgWarp; pDrlgWarp = pDrlgWarp->pNext)
    {
        if (!pDrlgWarp->nLevel)
        {
            FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 418);
            exit(-1);
        }

        if (nLevelId == pDrlgWarp->nLevel)
        {
            return pDrlgWarp->nWarp;
        }
    }

    return DATATBLS_GetLevelDefRecord(nLevelId)->dwWarp;
}

// 0x0066AF10
int* __fastcall DRLGWARP_GetWarpIdArrayFromLevel(D2DrlgLevelStrc* pLevel)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId);
}

// 0x0066AF30
int __fastcall DRLGWARP_GetWarpDestinationFromArray(D2DrlgLevelStrc* pLevel, unsigned char nWarpId)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId)[nWarpId];
}

inline int DRLGWARP_GetWarpDestinationFromArrayInline(D2DrlgLevelStrc* pLevel, unsigned char nWarpId)
{
    return DRLGWARP_GetWarpIdArrayFromLevelId(pLevel->pDrlg, pLevel->eLevelId)[nWarpId];
}

// 0x0066AF50
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromWarpIdAndDirection(D2DrlgLevelStrc* pLevel, unsigned char nWarpId, char szDirection)
{
    return DATATBLS_GetLvlWarpTxtRecordFromLevelIdAndDirection(DRLGWARP_GetWarpDestinationFromArrayInline(pLevel, nWarpId), szDirection);
}

// 0x0066AF80
D2LvlWarpTxt* __fastcall DRLGWARP_GetLvlWarpTxtRecordFromUnit(D2DrlgRoomStrc* pDrlgRoom, D2UnitStrc* pUnit)
{
    D2RoomTileStrc* pRoomTile = pDrlgRoom->pRoomTiles;
    int nClassId;

    if (!pUnit)
    {
        nClassId = -1;
    }
    else
    {
        nClassId = pUnit->dwClassId;
    }

    while (pRoomTile)
    {
        if (pRoomTile->pLvlWarpTxtRecord->dwLevelId == (unsigned char)nClassId)
        {
            if (pRoomTile->bEnabled)
            {
                return pRoomTile->pLvlWarpTxtRecord;
            }

            return 0;
        }

        pRoomTile = pRoomTile->pNext;
    }

    return 0;
}

// 0x0066AFB0
static inline int DRLGWARP_FindVisIndex(D2DrlgStrc* pDrlg, int nLevelId, int nVisLevel, int nIndex)
{
    int* pVis = DRLGROOM_GetVisArrayFromLevelId(pDrlg, nLevelId);
    int nCount = 0;
    for (unsigned char i = 0; i < 8; ++i)
    {
        if (pVis[i] == nVisLevel)
        {
            if (nCount == nIndex)
            {
                return i;
            }

            ++nCount;
        }
    }

    return -1;
}

// 0x0066AFF0
static inline D2DrlgListEntryStrc* DRLGWARP_FindRoomWithWarpFlag(D2DrlgStrc* pDrlg, int nBit)
{
    const int nMask = 1 << (nBit + 4);
    for (D2DrlgListEntryStrc* pEntry = ((D2DrlgListOwnerStrc*)pDrlg)->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwFlags & nMask)
        {
            return pEntry;
        }
    }

    return 0;
}

int __fastcall sub_M117_Emit_0066A870(const char* szText, D2DrlgRoomStrc* pDrlgRoom, D2DrlgStrc* pDrlg, int nLevelId)
{
    int n = DRLGWARP_SumStringBytes(szText);
    n += DRLGWARP_AreCodesEqual(szText, (const char*)pDrlgRoom);
    n += (int)DRLGWARP_GetActiveRoomFromRoomEx(pDrlgRoom);
    n += DRLGWARP_FindVisIndex(pDrlg, nLevelId, n, nLevelId);
    n += (int)DRLGWARP_FindRoomWithWarpFlag(pDrlg, n);
    return n;
}

// 0x0066B010
D2PresetUnitStrc* __fastcall DRLGWARP_FindPresetTileUnit(D2DrlgRoomStrc* pDrlgRoom)
{
    D2PresetUnitStrc* pPreset = DRLGROOM_GetPresetUnits(pDrlgRoom);
    for (; pPreset; pPreset = pPreset->pNext)
    {
        if (pPreset->nUnitType == 5)
        {
            break;
        }
    }

    return pPreset;
}

static inline int FindVis(D2DrlgStrc* pDrlg,int nLevel,int nOther,int nIndex)
{
 int* pVis=DRLGROOM_GetVisArrayFromLevelId(pDrlg,nLevel);
 int nCount=0;
 for(unsigned char i=0;i<8;++i) if(pVis[i]==nOther) { if(nCount==nIndex)return i; ++nCount; }
 return -1;
}

static inline D2DrlgRoomStrc* FindRoom(D2DrlgLevelStrc* pLevel,int nIndex)
{
 int nMask=1<<(nIndex+4);
 for(D2DrlgRoomStrc* pRoom=pLevel->ptRoomFirst;pRoom;pRoom=pRoom->pNext) if(pRoom->dwFlags&nMask)return pRoom;
 return 0;
}

// 0x0066B030
void __fastcall DRLGWARP_InitializeConnectedLevels(D2DrlgStrc* pDrlg,int unused,int nLevel1,int nLevel2)
{
 DRLGOUTPLACE_CreateLevelConnections(pDrlg);
 D2DrlgLevelStrc* pLevel1=DRLG_GetLevel(pDrlg,nLevel1);
 if(!pLevel1->ptRoomFirst)DRLG_InitLevel(pLevel1);
 D2DrlgLevelStrc* pLevel2=DRLG_GetLevel(pDrlg,nLevel2);
 if(!pLevel2->ptRoomFirst)DRLG_InitLevel(pLevel2);
 for(int n=0;n<8;++n) {
  int i=FindVis(pDrlg,nLevel1,nLevel2,n);
  int j=FindVis(pDrlg,nLevel2,nLevel1,n);
  if(i==-1 || j==-1)return;
  DRLGWARP_GetWarpIdArrayFromLevelId(pLevel1->pDrlg,pLevel1->eLevelId);
  DRLGWARP_GetWarpIdArrayFromLevelId(pLevel2->pDrlg,pLevel2->eLevelId);
  D2DrlgRoomStrc* pRoom1=FindRoom(pLevel1,i);
  D2DrlgRoomStrc* pRoom2=FindRoom(pLevel2,j);
  DRLGACTIVATE_InitializeRoomEx(pRoom1);
  DRLGACTIVATE_InitializeRoomEx(pRoom2);
  D2PresetUnitStrc* pPreset=DRLGROOM_GetPresetUnits(pRoom1);
  while(pPreset && pPreset->nUnitType!=5)pPreset=pPreset->pNext;
  pPreset=DRLGROOM_GetPresetUnits(pRoom2);
  while(pPreset && pPreset->nUnitType!=5)pPreset=pPreset->pNext;
 }
}

// 0x0066AE70
static D2DrlgRoomStrc* DRLGWARP_GetRandomRoom(D2DrlgLevelStrc* pLevel)
{
    D2_ASSERT(pLevel, 318);
    D2_ASSERT(pLevel->ptRoomFirst, 319);
    int nRand = ITEMS_RollLimitedRandomNumber(&pLevel->pSeed, pLevel->nRooms);
    D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst;
    while (nRand)
    {
        pDrlgRoom = pDrlgRoom->pDrlgRoomNext;
        --nRand;
    }
    return pDrlgRoom;
}

// 0x0066B1F0
static D2DrlgRoomStrc* DRLGWARP_GetFirstWarpRoom(D2DrlgLevelStrc* pLevel)
{
    for (D2DrlgRoomStrc* pDrlgRoom = pLevel->ptRoomFirst; pDrlgRoom; pDrlgRoom = pDrlgRoom->pDrlgRoomNext)
    {
        if (pDrlgRoom->dwFlags & 0xFF0)
        {
            int nFlags = 0x10;
            unsigned char nCounter = 0;
            do
            {
                if ((nFlags & pDrlgRoom->dwFlags) && sub_0066AEC0(pLevel->pDrlg, pLevel->eLevelId)[nCounter] != -1)
                {
                    return pDrlgRoom;
                }
                nFlags *= 2;
                ++nCounter;
            }
            while (nFlags & 0xFF0);
        }
    }
    return 0;
}

// 0x0066B2B0
D2ActiveRoomStrc* __fastcall DRLGWARP_GetLevelEntryRoom(D2DrlgStrc* pDrlg, int nLevelId, int nTileIndex, int* pX, int* pY)
{
    D2LevelDefBin* pLevelDefBinRecord = 0;
    D2DrlgLevelStrc* pLevel = 0;
    D2DrlgRoomStrc* pDrlgRoom = 0;

    pLevelDefBinRecord = DATATBLS_GetLevelDefRecord(nLevelId);
    *pX = -1;
    *pY = -1;

    pLevel = DRLG_GetLevel(pDrlg, nLevelId);
    if (!pLevel->ptRoomFirst)
    {
        DRLG_InitLevel(pLevel);
    }

    if (pLevelDefBinRecord->dwPosition)
    {
        if (nTileIndex == 13)
        {
            pDrlgRoom = DRLGWARP_GetWaypointRoomExFromLevel(pLevel, pX, pY);
            DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
            return pDrlgRoom->pRoom;
        }

        pDrlgRoom = pLevel->sub_0066AC40_GetTileRoom(nTileIndex, pX, pY);
        DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
        return pDrlgRoom->pRoom;
    }

    pDrlgRoom = DRLGWARP_GetWaypointRoomExFromLevel(pLevel, pX, pY);
    if (!pDrlgRoom)
    {
        pDrlgRoom = DRLGWARP_GetFirstWarpRoom(pLevel);
        if (!pDrlgRoom)
        {
            const int nX = pLevel->nWidth / 2 + pLevel->nPosX - 2;
            const int nY = pLevel->nHeight / 2 + pLevel->nPosY - 2;
            pDrlgRoom = DRLG_GetRoomExFromLevelAndCoordinates(pLevel, nX, nY);
            if (!pDrlgRoom)
            {
                pDrlgRoom = DRLGWARP_GetRandomRoom(pLevel);
            }
        }
    }

    if (pDrlgRoom)
    {
        if (*pX == -1 || *pY == -1)
        {
            *pX = pDrlgRoom->nTileXPos + pDrlgRoom->nTileWidth / 2;
            *pY = pDrlgRoom->nTileYPos + pDrlgRoom->nTileHeight / 2;
        }

        DRLGACTIVATE_InitializeRoomEx(pDrlgRoom);
        return pDrlgRoom->pRoom;
    }

    return 0;
}

// 0x0066B7F0
void __cdecl DRLGWARP_Nop()
{
}

#include "gen/data/Source/D2Common/DRLG/DrlgWarp.inc"
