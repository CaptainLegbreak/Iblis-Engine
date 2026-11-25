#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"

struct D2UnitStrc;

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord);                                     // 0x00620870

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem);                                                // 0x00628250

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);                                  // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem);                                             // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem);                                              // 0x0063DFD0

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810

#define UNIT_PLAYER 0

#define STAT_GOLD 14

#define STAT_QUESTITEMDIFFICULTY 356

#define GOLD_PILE_MAX 2000000000

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet);                         // 0x006280D0

#define UNIT_MONSTER 1

#define STAT_LEVEL 12

#define ITEMDROPFLAG_NEVERETH 0x2

#define ITEMDROPFLAG_NOSOCKETS 0x8

static inline void D2GAME_SetStatOrResetGold_Inline(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case STAT_GOLDBANK:
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

__forceinline int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
            return nLevel > 1 ? nLevel : 1;
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
            return nLevel > 1 ? nLevel : 1;
        }

        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    }
    else if (!nLevelId)
    {
        return 1;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    const int nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    return nLevel > 1 ? nLevel : 1;
}

// 0x00559CE0
D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed)
{
    if (nItemLevel <= 0)
    {
        nItemLevel = 1;
    }

    D2ItemDropStrc itemDrop = {};
    itemDrop.wItemFormat = pGame->wItemFormat;
    itemDrop.pSeed = 0;
    itemDrop.nSpawnType = nSpawnTarget;
    itemDrop.nX = 0;
    itemDrop.nY = 0;
    itemDrop.pRoom = 0;
    itemDrop.nQuality = nQuality;
    itemDrop.dwFlags2 |= (bNoEthereal ? ITEMDROPFLAG_NEVERETH : 0) | (bNoSockets ? ITEMDROPFLAG_NOSOCKETS : 0);
    itemDrop.nId = nItemId;
    itemDrop.pUnit = pPlayer;
    itemDrop.pGame = pGame;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.dwSeed = dwSeed;
    itemDrop.dwItemSeed = dwItemSeed;

    if (nItemLevel == -1)
    {
        itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
    }
    else
    {
        itemDrop.nItemLvl = nItemLevel;
    }

    if (itemDrop.nItemLvl <= 0)
    {
        itemDrop.nItemLvl = 1;
    }

    D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, bUseSeed);
    if (pItem)
    {
        ITEMS_SetItemFlag(pItem, 0x10, 1);
    }
    return pItem;
}

void __fastcall ITEMS_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090