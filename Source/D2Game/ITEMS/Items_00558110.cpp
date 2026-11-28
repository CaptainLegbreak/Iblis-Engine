// D2GAME_CreateItemUnit (0x00559CE0) sits in Items.cpp's run but stays in a file of its own. The image has
// ITEMS_GetItemLevelForNewItem (0x00558200) inline in it, and in one file with that function's definition the
// compiler calls it instead (it doesn't inline that 99-byte function there). Written as a forceinline helper
// that 0x00558200 also uses, both build equal, but the compiler also emits the helper's unused out-of-line
// copy (95 bytes), and the checker counts that as a second form of 0x00558200. With that, ITEMS_DropGoldPiles
// (0x0055A090) also needs a noinline on 0x00559CE0, which it calls out of line.
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2CommonApi.h"

struct D2UnitStrc;



#include "D2GameFuncs.h"
#include "D2CommonApi2.h"





#define UNIT_PLAYER 0

#define STAT_GOLD 14

#define STAT_QUESTITEMDIFFICULTY 356

#define GOLD_PILE_MAX 2000000000




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
D2UnitStrc* __fastcall D2GAME_CreateItemUnit(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed)
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

    D2UnitStrc* pItem = D2GAME_CreateItemEx(pGame, &itemDrop, bUseSeed);
    if (pItem)
    {
        ITEMS_SetItemFlag(pItem, 0x10, 1);
    }
    return pItem;
}
