#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ItemModes.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_ITEM 4

#define UNITFLAGEX_ISVENDORITEM 0x00000004

#define IFLAG_NEWITEM 0x00000001

#define IFLAG_BROKEN 0x00000100

#define IFLAG_REPAIRED 0x00000200

#define IFLAG_UNK2 0x00040000

#define IFLAG_SWITCHOUT 0x00000080

struct D2InventoryNodeStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"


void __fastcall D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0B0

void __fastcall D2GAME_SendP0x9D_ItemAction_Unequip(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0D0

void __fastcall D2GAME_SendP0x9D_ItemAction_SwapBodyItem(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0F0

void __fastcall D2GAME_SendP0x9D_ItemAction_WeaponSwitch(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D110

void __fastcall D2GAME_SendP0x9D_ItemAction_AutoUnequip(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D2C0

void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x14(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D350

void __fastcall D2GAME_SendP0x9D_ItemAction_UpdateStats(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D420

void __fastcall SCMD_SendItemFlagUpdate(D2ClientStrc* pClient, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int dwFlag, int bSet); // 0x0053D440

void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x16(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D4B0

void __fastcall D2GAME_SendP0x9C_ItemAction_GroundToCursor(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EC20


void __fastcall D2GAME_SendP0x9C_ItemAction_AddQuantity(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EDB0

void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInContainer(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE10


void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag); // 0x0053EED0

void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInBelt(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EEF0

void __fastcall D2GAME_SendP0x9C_ItemAction_ToCursor(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0053EF10

void __fastcall D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char nShopAction); // 0x0053EF30

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60


void __fastcall sub_0055F4F0_Nop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused); // 0x0055F4F0

int __fastcall D2GAME_NPC_IsItemInNpcInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, int bRemoveFromShop); // 0x00579360

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

extern unsigned int gdwItemFlags[8]; // 0x00738C4C

extern unsigned int gnItemFlagCount; // 0x00738C6C

extern unsigned int gdwItemCmdFlags[21]; // 0x00738C70

extern unsigned int gnItemCmdFlagCount; // 0x00738CC4



struct D2StaticPathStrc;







inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x005973F0
static int INVMODE_SendItemToClient(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pUnused, D2ClientStrc* pClient)
{
    D2UnitStrc* pClientPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pClientPlayer);

    if (pItem)
    {
        if (UNIT_HasFlagEx(pItem, UNITFLAGEX_ISVENDORITEM))
        {
            if (pInteractUnit == pPlayer && D2GAME_NPC_IsItemInNpcInventory(pGame, pClientPlayer, pInteractUnit, pItem, 0))
            {
                D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop(pClient, pPlayer, pItem, 56);
            }
            return 1;
        }

        if (UNIT_HasFlagEx(pItem, UNITFLAGEX_ITEMINIT))
        {
            if (pInteractUnit == pPlayer && D2GAME_NPC_IsItemInNpcInventory(pGame, pClientPlayer, pInteractUnit, pItem, 1))
            {
                D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop(pClient, pPlayer, pItem, 57);
            }
            return 1;
        }
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x40) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_GroundToCursor(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x80000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9D_ItemAction_Unknown0x16(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if ((ITEMS_CheckItemCMDFlag(pItem, 2) || ITEMS_CheckItemCMDFlag(pItem, 0x80)) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_PutInContainer(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 4) && pPlayer == pClientPlayer)
    {
        D2GAME_UpdateClientItem(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 8) || ITEMS_CheckItemCMDFlag(pItem, 0x200))
    {
        D2GAME_SendP0x9D_ItemAction_Equip(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x10000))
    {
        D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x10))
    {
        D2GAME_SendP0x9D_ItemAction_Unequip(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x20))
    {
        D2GAME_SendP0x9D_ItemAction_SwapBodyItem(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x100) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_AddQuantity(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x40000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_SwapInContainer(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if ((ITEMS_CheckItemCMDFlag(pItem, 0x400) || ITEMS_CheckItemCMDFlag(pItem, 0x2000)) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_PutInBelt(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x800) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_RemoveFromBelt(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x1000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_SwapInBelt(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x100000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_ToCursor(pClient, pPlayer, pItem);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x200000))
    {
        D2GAME_SendP0x9D_ItemAction_WeaponSwitch(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x4000))
    {
        D2GAME_SendP0x9D_ItemAction_AutoUnequip(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x8000))
    {
        D2GAME_SendP0x9D_ItemAction_Unknown0x14(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 183, ".\\INVENTORY\\InvMode.cpp"))
    {
        if (pPlayer != pClientPlayer && (!pItem || pItem->dwAnimMode != IMODE_EQUIP))
        {
            return 0;
        }
        SCMD_SendItemFlagUpdate(pClient, pPlayer, pItem, IFLAG_BROKEN, ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 193, ".\\INVENTORY\\InvMode.cpp"));
        return 1;
    }
    else if (ITEMS_CheckItemFlag(pItem, IFLAG_REPAIRED, 197, ".\\INVENTORY\\InvMode.cpp"))
    {
        if (pPlayer == pClientPlayer || pItem && pItem->dwAnimMode == IMODE_EQUIP)
        {
            SCMD_SendItemFlagUpdate(pClient, pPlayer, pItem, IFLAG_REPAIRED, ITEMS_CheckItemFlag(pItem, IFLAG_REPAIRED, 207, ".\\INVENTORY\\InvMode.cpp"));
            return 1;
        }
    }
    else if (ITEMS_CheckItemFlag(pItem, IFLAG_NEWITEM, 211, ".\\INVENTORY\\InvMode.cpp"))
    {
        const int nAnimMode = !pItem ? 0 : pItem->dwAnimMode;

        if (pPlayer != pClientPlayer && (nAnimMode == IMODE_STORED || nAnimMode == IMODE_INBELT))
        {
            return 0;
        }

        if (nAnimMode != IMODE_STORED && nAnimMode != IMODE_EQUIP && nAnimMode != IMODE_INBELT)
        {
            return 0;
        }

        if (pPlayer != pClientPlayer || !ITEMS_CheckItemFlag(pItem, IFLAG_UNK2, 227, ".\\INVENTORY\\InvMode.cpp"))
        {
            D2GAME_SendP0x9D_ItemAction_UpdateStats(pClient, pPlayer, pItem, 0);
            return 1;
        }
    }

    return 0;
}

// 0x00597890
void __fastcall D2GAME_INVMODE_First(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg)
{
    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 244);

    if (pInventoryArg)
    {
        hInventory = pInventoryArg;
    }

    D2InventoryNodeStrc* pNode = INVENTORY_GetTradeInventory(hInventory);
    if (!pNode)
    {
        return;
    }

    do
    {
        D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(pNode));
        if (pItem)
        {
            INVMODE_SendItemToClient(pUnit, pItem, 0, pClient);

            if (UNIT_HasFlagEx(pItem, UNITFLAGEX_HASINV))
            {
                D2_ASSERT(pItem->pInventory, 264);

                for (D2InventoryNodeStrc* i = INVENTORY_GetTradeInventory(pItem->pInventory); i; i = INVENTORY_GetNextNode(i))
                {
                    D2UnitStrc* pNestedItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(i));
                    if (pNestedItem)
                    {
                        INVMODE_SendItemToClient(pUnit, pItem, pNestedItem, pClient);
                    }
                }
            }
        }

        pNode = INVENTORY_GetNextNode(pNode);
    }
    while (pNode);

    if (MONSTERS_GetHirelingTypeId(pUnit))
    {
        D2GAME_ITEMS_UpdateInventoryItems(pGame, pUnit, 0, 1);
        sub_0055F4F0_Nop(pGame, pUnit, 1);
    }
}

// 0x005979B0
void __fastcall D2GAME_ResetSomeItemFlags(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (pItem)
    {
        pItem->dwFlagEx &= ~0x14;
    }

    for (unsigned int i = 0; i < gnItemCmdFlagCount; ++i)
    {
        ITEMS_SetItemCMDFlag(pItem, gdwItemCmdFlags[i], 0);
    }

    for (unsigned int i = 0; i < gnItemFlagCount; ++i)
    {
        ITEMS_SetItemFlag(pItem, gdwItemFlags[i], 0);
    }
}

struct D2ClientStrc;

struct D2UnitStrc;

static inline int CheckFlag(D2UnitStrc* unit, int bit)
{
    if (!unit)
    {
        return 0;
    }
    return (unit->dwFlagEx >> bit) & 1;
}

// 0x00597A20
int __fastcall INVMODE_IsTradeBusy(D2GameStrc* game, D2UnitStrc* unit)
{
    if (!CheckFlag(unit, 22) && !CheckFlag(unit, 23))
    {
        D2InventoryNodeStrc* node = INVENTORY_GetTradeInventory(unit->pInventory);
        while (node)
        {
            D2UnitStrc* item = SUNIT_GetServerUnit(game, 4, INVENTORY_GetItemGUIDFromNode(node));
            D2InventoryNodeStrc* next = INVENTORY_GetNextNode(node);
            if (item)
            {
                return 1;
            }
            node = next;
        }
        return 0;
    }
    return 1;
}

// 0x00597AA0
static void INVMODE_ResetSwitchBodyLoc(D2UnitStrc* pItem)
{
    if (ITEMS_CheckItemCMDFlag(pItem, 0x10) || ITEMS_CheckItemCMDFlag(pItem, 0x4000))
    {
        ITEMS_SetBodyLocation(pItem, 0);
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x20) && ITEMS_CheckItemFlag(pItem, IFLAG_SWITCHOUT, 384, ".\\INVENTORY\\InvMode.cpp"))
    {
        ITEMS_SetBodyLocation(pItem, 0);
    }
}

// 0x00597B00
void __fastcall D2GAME_INVMODE_Last(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    UNITS_RefreshInventory(pUnit, 0);

    for (D2InventoryNodeStrc* pInventoryNode = INVENTORY_GetTradeInventory(pInventory); pInventoryNode; pInventoryNode = INVENTORY_GetNextNode(pInventoryNode))
    {
        D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(pInventoryNode));
        if (pItem)
        {
            INVMODE_ResetSwitchBodyLoc(pItem);

            D2GAME_ResetSomeItemFlags(pGame, pItem);

            if (UNIT_HasFlagEx(pItem, UNITFLAGEX_HASINV))
            {
                UNITS_RefreshInventory(pItem, 0);

                D2InventoryStrc* pItemInventory = pItem->pInventory;
                D2_ASSERT(pItemInventory, 420);

                for (D2InventoryNodeStrc* i = INVENTORY_GetTradeInventory(pItemInventory); i; i = INVENTORY_GetNextNode(i))
                {
                    D2UnitStrc* pNestedItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, INVENTORY_GetItemGUIDFromNode(i));
                    if (pNestedItem)
                    {
                        D2GAME_ResetSomeItemFlags(pGame, pNestedItem);
                    }
                }

                INVENTORY_FreeTradeInventory(pItemInventory);
            }

            if (ITEMS_CheckItemCMDFlag(pItem, 1))
            {
                ITEMS_RemoveFromAllPlayers(pGame, pItem);
            }
        }
    }

    INVENTORY_FreeTradeInventory(pInventory);
}

extern unsigned int gdwItemFlags[8] = { 0x20, 2, 8, 0x80, 0x40, 1, 0x200, 0x40000 }; // 0x00738C4C

extern unsigned int gnItemFlagCount = 8; // 0x00738C6C

extern unsigned int gdwItemCmdFlags[21] = {
    2, 4, 8, 0x10, 0x20, 0x40, 0x80, 0x100, 0x40000, 0x400, 0x800, 0x1000, 0x2000, 0x200, 0x4000, 0x8000,
    0x10000, 0x20000, 0x80000, 0x100000, 0x200000
}; // 0x00738C70

extern unsigned int gnItemCmdFlagCount = 0x15; // 0x00738CC4
