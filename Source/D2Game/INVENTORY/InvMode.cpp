#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ItemModes.h"
#include "D2LanguageNames.h"

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

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010

void __fastcall D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D090

void __fastcall D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem_6FC3EA70(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0B0

void __fastcall D2GAME_SendP0x9D_ItemAction_Unequip_6FC3EA90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0D0

void __fastcall D2GAME_SendP0x9D_ItemAction_SwapBodyItem_6FC3EAB0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D0F0

void __fastcall D2GAME_SendP0x9D_ItemAction_WeaponSwitch_6FC3EAD0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D110

void __fastcall D2GAME_SendP0x9D_ItemAction_AutoUnequip_6FC3EE20(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D2C0

void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x14_6FC3EEC0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D350

void __fastcall D2GAME_SendP0x9D_ItemAction_UpdateStats_6FC3EFA0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D420

void __fastcall SCMD_SendItemFlagUpdate(D2ClientStrc* pClient, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int a4, int a5); // 0x0053D440

void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x16_6FC3F040(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053D4B0

void __fastcall D2GAME_SendP0x9C_ItemAction_GroundToCursor_6FC3E870(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4); // 0x0053EC20

void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053ED50

void __fastcall D2GAME_SendP0x9C_ItemAction_AddQuantity_6FC3EAF0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4); // 0x0053EDB0

void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInContainer_6FC3EB40(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a4); // 0x0053EE10

void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags); // 0x0053EE70

void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag); // 0x0053EED0

void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInBelt_6FC3EC00(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int a3); // 0x0053EEF0

void __fastcall D2GAME_SendP0x9C_ItemAction_ToCursor_6FC3EEA0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0053EF10

void __fastcall D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char a3); // 0x0053EF30

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

void __fastcall sub_0055F4F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055F4F0

int __fastcall D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, int a4); // 0x00579360

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

D2InventoryNodeStrc* __stdcall INVENTORY_GetTradeInventory(D2InventoryStrc* pInventory); // 0x0063CBB0

D2InventoryNodeStrc* __stdcall INVENTORY_GetNextNode(D2InventoryNodeStrc* pNode); // 0x0063CD20

int __stdcall INVENTORY_GetItemGUIDFromNode(D2InventoryNodeStrc* pNode); // 0x0063CD40

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

extern unsigned int gdwItemFlags[8]; // 0x00738C4C

extern unsigned int gnItemFlagCount; // 0x00738C6C

extern unsigned int gdwItemCmdFlags[21]; // 0x00738C70

extern unsigned int gnItemCmdFlagCount; // 0x00738CC4

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc* pGame, D2UnitStrc* pItem); // 0x005979B0

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70

void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000

void __stdcall INVENTORY_FreeTradeInventory(D2InventoryStrc* pInventory); // 0x0063CBD0

struct D2StaticPathStrc;

void __fastcall D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char nHitClass, unsigned char nLifePct); // 0x0053B430

void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10

void __fastcall SCMD_SendUniqueMonsterInfo(D2ClientStrc* pClient, int a2, unsigned char a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7); // 0x0053D880

void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ClientStrc* pClient); // 0x00537680

void __fastcall SUNIT_SynchronizeRoomClients(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670

void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer); // 0x00571580

void __fastcall SUNITMSG_SendOverlay(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005715A0

void __fastcall SUNITMSG_SendHoverText(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620

void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740

void __fastcall SUNITMSG_SendQueuedMessages(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg); // 0x00597890

void __fastcall MONSTERMSG_SendMonsterModeUpdate(D2GameStrc* pGame, D2UnitStrc* pMonster, D2ClientStrc* pClient); // 0x00597E20

unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120

unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900


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
            if (pInteractUnit == pPlayer && D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(pGame, pClientPlayer, pInteractUnit, pItem, 0))
            {
                D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(pClient, pPlayer, pItem, 56);
            }
            return 1;
        }

        if (UNIT_HasFlagEx(pItem, UNITFLAGEX_ITEMINIT))
        {
            if (pInteractUnit == pPlayer && D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(pGame, pClientPlayer, pInteractUnit, pItem, 1))
            {
                D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop_6FC3F260(pClient, pPlayer, pItem, 57);
            }
            return 1;
        }
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x40) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_GroundToCursor_6FC3E870(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x80000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9D_ItemAction_Unknown0x16_6FC3F040(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if ((ITEMS_CheckItemCMDFlag(pItem, 2) || ITEMS_CheckItemCMDFlag(pItem, 0x80)) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_PutInContainer_6FC3E980(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 4) && pPlayer == pClientPlayer)
    {
        D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 8) || ITEMS_CheckItemCMDFlag(pItem, 0x200))
    {
        D2GAME_SendP0x9D_ItemAction_Equip_6FC3EA50(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x10000))
    {
        D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem_6FC3EA70(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x10))
    {
        D2GAME_SendP0x9D_ItemAction_Unequip_6FC3EA90(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x20))
    {
        D2GAME_SendP0x9D_ItemAction_SwapBodyItem_6FC3EAB0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x100) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_AddQuantity_6FC3EAF0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x40000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_SwapInContainer_6FC3EB40(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if ((ITEMS_CheckItemCMDFlag(pItem, 0x400) || ITEMS_CheckItemCMDFlag(pItem, 0x2000)) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_PutInBelt_6FC3EB90(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x800) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x1000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_SwapInBelt_6FC3EC00(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x100000) && pPlayer == pClientPlayer)
    {
        D2GAME_SendP0x9C_ItemAction_ToCursor_6FC3EEA0(pClient, pPlayer, pItem);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x200000))
    {
        D2GAME_SendP0x9D_ItemAction_WeaponSwitch_6FC3EAD0(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x4000))
    {
        D2GAME_SendP0x9D_ItemAction_AutoUnequip_6FC3EE20(pClient, pPlayer, pItem, 0);
        return 1;
    }

    if (ITEMS_CheckItemCMDFlag(pItem, 0x8000))
    {
        D2GAME_SendP0x9D_ItemAction_Unknown0x14_6FC3EEC0(pClient, pPlayer, pItem, 0);
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
            D2GAME_SendP0x9D_ItemAction_UpdateStats_6FC3EFA0(pClient, pPlayer, pItem, 0);
            return 1;
        }
    }

    return 0;
}

// 0x00597890
void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg)
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
        D2GAME_ITEMS_UpdateInventoryItems_6FC45050(pGame, pUnit, 0, 1);
        sub_0055F4F0(pGame, pUnit, 1);
    }
}

// 0x005979B0
void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc* pGame, D2UnitStrc* pItem)
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

void __fastcall sub_M105_Emit_00597AA0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (pItem)
    {
        INVMODE_ResetSwitchBodyLoc(pItem);
        D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pItem);
        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
}

// 0x00597B00
void __fastcall D2GAME_INVMODE_Last_6FC416D0(D2GameStrc* pGame, D2UnitStrc* pUnit)
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
            if (ITEMS_CheckItemCMDFlag(pItem, 0x10) || ITEMS_CheckItemCMDFlag(pItem, 0x4000))
            {
                ITEMS_SetBodyLocation(pItem, 0);
            }

            if (ITEMS_CheckItemCMDFlag(pItem, 0x20) && ITEMS_CheckItemFlag(pItem, IFLAG_SWITCHOUT, 384, ".\\INVENTORY\\InvMode.cpp"))
            {
                ITEMS_SetBodyLocation(pItem, 0);
            }

            D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pItem);

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
                        D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pNestedItem);
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

#include "gen/data/Source/D2Game/INVENTORY/InvMode.inc"
