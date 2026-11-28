#include "D2ItemTypes.h"

#include "D2CmpTileRecord.h"

#include "D2GameTypes.h"

#include "D2DrlgMaps.h"

#include "D2CmpTypes.h"

#include "D2LRUNode.h"

#include "D2MonsterIds.h"

#include "D2Common.h"

#include "D2ClientTypes.h"

#include "D2Structs.h"

#include "D2Path.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2Skills.h"

#include "D2ItemsWorld.h"

#include "D2TxtItems.h"

#include "D2ItemModes.h"
#include "D2InventoryPair.h"
#include "FogApi.h"
#include "D2ClientApi.h"

#define STATEMASK_BLUE 18

#define INVENTORY_SIGNATURE 0x01020304

#define NUM_BODYLOC 13

#define NUM_BODYLOC_NOSWITCH 11

#define WEAPONCLASS_HT1 12

#define COMPOSIT_RIGHTHAND 5

#define STAT_QUANTITY 70

#define ITEMCODE_ISC 0x20637369

#define ITEMCODE_TSC 0x20637374

struct D2PoolSystemStrc;
struct D2InventoryStrc;

struct Inventory;

struct ItemRecord;

struct AppearanceRecord;

struct ItemData;

struct ItemLink;

struct D2ItemExtraDataStrc;

struct D2ItemDataStrc;

struct D2InventoryPairStrc;

struct D2InventoryGridStrc;

struct D2InventoryNodeStrc;

struct D2CorpseStrc;



struct D2SkillsTxt;

struct D2SkillListStrc;



struct AppearanceSix;

struct CodeEntry;

struct D2ItemsTxt;

struct D2ItemDataTbl;

struct D2InventoryComponentItemTypeStrc;

struct D2InventoryGridInfoStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2SkillStrc;

struct D2CoordStrc;

struct D2StaticPathStrc;

struct D2InvRectStrc;

struct D2BeltsTxt;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304



extern "C" int __fastcall sub_0045ADF0_GetX(D2UnitStrc* pItem); // 0x0045ADF0

extern "C" int __fastcall sub_0045AE20_GetY(D2UnitStrc* pItem); // 0x0045AE20

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szSource, int nLine); // 0x006286C0

void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nCell); // 0x00629ED0

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pOwner, D2UnitStrc* pItem); // 0x006277F0

extern "C" const char gszInventorySource_006EA918; // 0x006EA918

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);


int __fastcall FOG_FreePool(D2PoolSystemStrc* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480





typedef unsigned short u16;

typedef unsigned int u32;

typedef int s32;

struct AppearanceSix
{
    u8 f_0;
    u8 f_1;
    u8 field2;
    u8 field3;
    u8 f_4;
    u8 field5;
};

struct CodeEntry
{
    u32 code;
    s32 type;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern CodeEntry gTable_0096CC68[]; // 0x0096CC68

u8 __stdcall ITEMS_GetBodyLocation(D2UnitStrc*); // 0x00627D40

u8 __stdcall ITEMS_GetComponent(D2UnitStrc*); // 0x00628660


s32 __stdcall ITEMS_GetColor(D2UnitStrc*, D2UnitStrc*, u8*, s32); // 0x0062C100

ItemRecord* __stdcall sub_006335F0_ItemRecord(s32); // 0x006335F0

ItemRecord* __stdcall sub_00633640_RecordByCode(u32, s32*); // 0x00633640

D2UnitStrc* __stdcall INVENTORY_GetCompositItem(Inventory*, s32); // 0x0063C050

u32 __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*, Inventory*, s32*, s32, s32); // 0x0064F380

s32 __stdcall COMPOSIT_IsArmorComponent(s32); // 0x0064F420

s32 __stdcall COMPOSIT_GetArmorTypeFromComponent(s32, AppearanceSix*); // 0x0064F500

AppearanceRecord* __stdcall DATATBLS_GetArmTypeTxtRecord(s32); // 0x0065B620

#include "D2ItemDataTbl.h"

#include "D2InventoryComponentItemTypeStrc.h"

D2ItemDataTbl* __stdcall DATATBLS_GetItemDataTables(); // 0x00633590

extern D2InventoryComponentItemTypeStrc gaComponentItemTypeMap[283]; // 0x00744CA8




int __stdcall ITEMS_Is1Or2Handed(D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0062A1E0


typedef int BOOL;

void* __fastcall FOG_ReallocPool(D2PoolSystemStrc* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850

void __stdcall DATATBLS_GetInventoryGridInfo(int nInventoryRecordId, int nUnused, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0

extern unsigned char gabDirection64To16[64]; // 0x007455C0
extern unsigned char gabDirection64To8[256]; // 0x00745600
extern unsigned char gabDirection8To64[8]; // 0x00745640

extern const signed char gaDirectionDeltaX[32]; // 0x006EA998

extern const signed char gaDirectionDeltaY[32]; // 0x006EA978

static s32 __cdecl INVENTORY_FindComponentArrayIndex(u32 second, u32 first);

static int INVENTORY_CanItemsBeWieldedTogether(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2);

static BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory);

extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo; // 0x0074479C

extern D2InventoryGridInfoStrc gBeltInventoryGridInfo; // 0x007447B4

int __stdcall UNITS_GetBeltType(D2UnitStrc* pUnit); // 0x00621ED0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480


unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pUnit); // 0x00628660

int __stdcall ITEMS_ComparePotionTypes(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x00628A40




unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640


void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int bHigherRes, D2BeltsTxt* pRecord); // 0x00660CB0

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

static D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* inventory, int index, D2InventoryGridInfoStrc* info); // 0x0063ADD0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* inventory, int slot); // 0x0063C7F0

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem);    // 0x0063AD50

int __stdcall INVENTORY_CheckForItemInTradeInventory(D2InventoryStrc* pInventory, int nItemId);            // 0x0063CC30

static D2InventoryComponentItemTypeStrc gaTxtComponentItemTypeMap[255]; // 0x0096CC68

static int gnComponentArrayRecordCount; // 0x0096D460

static int gbComponentArrayInitialized; // 0x0096D464

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __stdcall UNITS_SetXForStaticUnit(D2UnitStrc* pUnit, int nX); // 0x00620470

void __stdcall UNITS_SetYForStaticUnit(D2UnitStrc* pUnit, int nY); // 0x006204C0


void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID); // 0x00629ED0

int __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId); // 0x0063C600


void __stdcall DATATBLS_GetInventoryGridInfo(int nInventoryRecordId, int nUnused, D2InventoryGridInfoStrc* pInventoryGridInfo); // 0x0065C1F0

static BOOL __stdcall INVENTORY_PlaceItemInGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryGrid, int nInventoryRecordId); // 0x0063AFD0

static unsigned char __stdcall INVENTORY_GetPlacementWeight(D2InventoryGridStrc* pInventoryGrid, int nXPos, int nYPos, unsigned char nItemWidth, unsigned char nItemHeight); // 0x0063B340

int __stdcall ITEMS_CheckWeaponClass(D2UnitStrc* pItem, int nWeaponClass); // 0x00628950

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory); // 0x0063AC40

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory);



struct D2BeltsTxtLayout
{
    unsigned char nIndex;
    unsigned char pad0x01[3];
    unsigned char nBoxes;
    unsigned char pad0x05[3];
    D2InvRectStrc beltBoxes[16];
};

void* __fastcall FOG_ReallocPool(D2PoolSystemStrc* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

#define BODYLOC_LAST (13 - 1)

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(D2PoolSystemStrc* pMemPool, D2UnitStrc* pOwner);

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraDataFromItem(D2UnitStrc* pItem);

static inline D2UnitStrc* INVENTORY_GetBodyLocItemInline(D2InventoryStrc* pInventory, int nBodyLoc);

D2UnitStrc* __stdcall INVENTORY_GetEquippedItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pCheckItem);

struct D2DynamicPathStrc;



D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nGridX, int nGridY, int* pX, int* pY, int nInventoryRecordId, unsigned char nPage);

static BOOL __stdcall INVENTORY_FindFreePositionBottomRightToTopLeftWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight); // 0x0063B490

static BOOL __stdcall INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight); // 0x0063B620

static void __stdcall INVENTORY_FillItemComponentGfxInfo(D2UnitStrc* unit, u8* firstOutput, u8* secondOutput, D2UnitStrc* item);

int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc);                                     // 0x0062ED50


int __stdcall INVENTORY_IsItemBodyLocFree(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc, int nInventoryRecordId); // 0x0063CB00

static int __stdcall INVENTORY_CheckHandSlotPlacement(D2UnitStrc* pUnit, int nOtherLoc, D2UnitStrc* pNewItem, D2UnitStrc* pLocItem, D2UnitStrc* pOtherItem);

int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck);

static BOOL __stdcall INVENTORY_AreGridCellsFree(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight);

static void __stdcall INVENTORY_FillGridCells(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight, D2UnitStrc* pItem);

static void INVENTORY_LinkItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem);

static void __stdcall INVENTORY_LinkGridItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, D2UnitStrc* pItem);

inline BOOL INVENTORY_ValidateBodyLoc(int nBodyLoc);

static BOOL __stdcall INVENTORY_CanItemBePlacedAtPos(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight);

static BOOL __stdcall INVENTORY_FindFreePositionRightToLeft(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight);

static BOOL __stdcall INVENTORY_FindFreePositionForSingleRowItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight);

static BOOL __stdcall INVENTORY_FindFreePositionTopLeftToBottomRight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight);

static BOOL __stdcall INVENTORY_FindFreePositionForTallNarrowItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight);

static BOOL __stdcall INVENTORY_FindFreePositionForSquareItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight);

static BOOL __stdcall INVENTORY_FindFreePositionForOtherItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight);

BOOL __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryRecordId, BOOL bUnused, unsigned char nPage);

BOOL __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc);

static BOOL INVENTORY_PlaceItemInBeltGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot);

BOOL __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot);

BOOL __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem);

D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pCheckItem);

static void __cdecl INVENTORY_GetArmorComponents(D2UnitStrc* item, AppearanceSix* output);

BOOL __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused);

BOOL __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, BOOL bUnused, unsigned char nPage, const char* szFile, int nLine);

static void __stdcall INVENTORY_SetBowHandComponents(u8* firstOutput, u8* secondOutput, D2UnitStrc* item, D2UnitStrc* unit);

inline void INVENTORY_SetLeftItemGUIDInline(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int bSet);

void __stdcall INVENTORY_GetItemSaveGfxInfo(D2UnitStrc* unit, u8* firstOutput, u8* secondOutput);

static int STATES_CheckStateMaskFlagsOnUnit(D2UnitStrc* pUnit, const unsigned int* pStateMask)
{
    unsigned int* pStatFlags = D2COMMON_STATES_GetStatFlags(pUnit);
    if (!pStatFlags)
    {
        return 0;
    }

    for (int i = 0; i < (sgptDataTables->nStatesTxtRecordCount + 31) / 32; ++i)
    {
        if (pStatFlags[i] & pStateMask[i])
        {
            return 1;
        }
    }

    return 0;
}

static inline D2ItemExtraDataStrc* ITEMS_GetExtraDataFromItem(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }
    return 0;
}

// 0x0063A810
static void __cdecl INVENTORY_UnlinkItem(D2InventoryPairStrc* pPair, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = ITEMS_GetExtraDataFromItem(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousItem)
    {
        if (pPair->pFirstItem == pItem)
        {
            pPair->pFirstItem = pExtra->pNextItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = ITEMS_GetExtraDataFromItem(pExtra->pPreviousItem);
        if (pPrevious)
        {
            pPrevious->pNextItem = pExtra->pNextItem;
        }
    }
    if (!pExtra->pNextItem)
    {
        if (pPair->pLastItem == pItem)
        {
            pPair->pLastItem = pExtra->pPreviousItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = ITEMS_GetExtraDataFromItem(pExtra->pNextItem);
        if (pNext)
        {
            pNext->pPreviousItem = pExtra->pPreviousItem;
        }
    }
    pExtra->pNextItem = 0;
    pExtra->pPreviousItem = 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraInline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }

    return 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraTyped(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }

    return 0;
}

static D2ItemExtraDataStrc* INVENTORY_GetItemExtraDataNoInl(D2UnitStrc* pItem) // 0x0063A7E0
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData)
    {
        return &pItem->pItemData->pExtraData;
    }

    return 0;
}

// 0x0063A8A0
static BOOL __stdcall INVENTORY_AreGridCellsFree(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    for (int y = nY; y < nY + nItemHeight; ++y)
    {
        D2UnitStrc** ppRow = &pInventoryGrid->ppItems[y * pInventoryGrid->nGridWidth];
        for (int x = nX; x < nX + nItemWidth; ++x)
        {
            if (ppRow[x])
            {
                return FALSE;
            }
        }
    }

    return TRUE;
}

// 0x0063A910
static void __stdcall INVENTORY_FillGridCells(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight, D2UnitStrc* pItem)
{
    for (int y = nY; y < nY + nItemHeight; ++y)
    {
        D2UnitStrc** ppRow = &pInventoryGrid->ppItems[y * pInventoryGrid->nGridWidth];
        for (int x = nX; x < nX + nItemWidth; ++x)
        {
            ppRow[x] = pItem;
        }
    }
}

// 0x0063A970
static void __stdcall INVENTORY_UnlinkGridItem(D2InventoryGridStrc* pGrid, int bMultiCell, D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType != 4)
    {
        return;
    }
    D2ItemExtraDataStrc* pExtra = ITEMS_GetExtraDataFromItem(pItem);
    if (!pExtra)
    {
        return;
    }
    if (!pExtra->pPreviousGridItem)
    {
        if (pGrid->pItem == pItem)
        {
            pGrid->pItem = pExtra->pNextGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pPrevious = ITEMS_GetExtraDataFromItem(pExtra->pPreviousGridItem);
        if (pPrevious)
        {
            pPrevious->pNextGridItem = pExtra->pNextGridItem;
        }
    }
    if (!pExtra->pNextGridItem)
    {
        if (pGrid->pLastItem == pItem)
        {
            pGrid->pLastItem = pExtra->pPreviousGridItem;
        }
    }
    else
    {
        D2ItemExtraDataStrc* pNext = ITEMS_GetExtraDataFromItem(pExtra->pNextGridItem);
        if (pNext)
        {
            pNext->pPreviousGridItem = pExtra->pPreviousGridItem;
        }
    }
    if (pGrid->ppItems)
    {
        if (bMultiCell)
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, &gszInventorySource_006EA918, SIZE_LINE);
            for (int nRow = nY; nRow < nY + nHeight; ++nRow)
            {
                D2UnitStrc** ppRow = pGrid->ppItems + nRow * pGrid->nGridWidth;
                for (int nColumn = nX; nColumn < nX + nWidth; ++nColumn)
                {
                    ppRow[nColumn] = 0;
                }
            }
        }
        else
        {
            const int nX = sub_0045ADF0_GetX(pItem);
            const int nY = sub_0045AE20_GetY(pItem);
            pGrid->ppItems[nX + nY * pGrid->nGridWidth] = 0;
        }
    }
    pExtra->pNextGridItem = 0;
    pExtra->pPreviousGridItem = 0;
    pExtra->nNodePos = 0;
}

// 0x0063AAD0
int __fastcall INVENTORY_IsUnitItem(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_ITEM)
    {
        return 1;
    }
    return 0;
}

// @ref 0x0063AAF0
int __fastcall sub_0063AAF0_RemoveItem(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType == 4)
    {
        D2ItemExtraDataStrc* pExtra = ITEMS_GetExtraDataFromItem(pItem);
        if (!pExtra)
        {
            return 0;
        }
        D2InventoryStrc* pInventory = pExtra->pParentInv;
        if (!pInventory)
        {
            return 0;
        }
        if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        {
            return 0;
        }
        if ((signed char)pExtra->nNodePos > 0)
        {
            const int nGrid = (signed char)pExtra->nNodePos - 1;
            if (pInventory->nGridCount > nGrid)
            {
                INVENTORY_UnlinkGridItem(&pInventory->pGrids[nGrid], nGrid >= 1, pItem);
            }
        }
        if (pInventory->pCursorItem == pItem)
        {
            pInventory->pCursorItem = 0;
        }
        else
        {
            INVENTORY_UnlinkItem((D2InventoryPairStrc*)&pInventory->pFirstItem, pItem);
            --pInventory->dwItemCount;
        }
        pExtra->pParentInv = 0;
        pExtra->nNodePos = 0;
        pExtra->nNodePosOther = 0;
        ITEMS_SetOwnerId(pItem, -1);
        if (pInventory->pOwner)
        {
            STATLIST_ExpireUnitStatlist(pInventory->pOwner, pItem);
        }
        const int nItemId = pItem->dwUnitId;
        if (pInventory->dwLeftItemGUID == nItemId)
        {
            pInventory->dwLeftItemGUID = -1;
        }
    return 1;
    }
    return 0;
}

// 0x0063AAF0
int __fastcall INVENTORY_RemoveItem(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : -1;
    if (nType == 4)
    {
        D2ItemExtraDataStrc* pExtra = ITEMS_GetExtraDataFromItem(pItem);
        if (!pExtra)
        {
            return 0;
        }
        D2InventoryStrc* pInventory = pExtra->pParentInv;
        if (!pInventory)
        {
            return 0;
        }
        if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        {
            return 0;
        }
        if ((signed char)pExtra->nNodePos > 0)
        {
            const int nGrid = (signed char)pExtra->nNodePos - 1;
            if (pInventory->nGridCount > nGrid)
            {
                INVENTORY_UnlinkGridItem(&pInventory->pGrids[nGrid], nGrid >= 1, pItem);
            }
        }
        if (pInventory->pCursorItem == pItem)
        {
            pInventory->pCursorItem = 0;
        }
        else
        {
            INVENTORY_UnlinkItem((D2InventoryPairStrc*)&pInventory->pFirstItem, pItem);
            --pInventory->dwItemCount;
        }
        pExtra->pParentInv = 0;
        pExtra->nNodePos = 0;
        pExtra->nNodePosOther = 0;
        ITEMS_SetOwnerId(pItem, -1);
        if (pInventory->pOwner)
        {
            STATLIST_ExpireUnitStatlist(pInventory->pOwner, pItem);
        }
        if (pInventory->dwLeftItemGUID == (!pItem ? -1 : pItem->dwUnitId))
        {
            pInventory->dwLeftItemGUID = -1;
        }
    return 1;
    }
    return 0;
}

// 0x0063ABD0
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(D2PoolSystemStrc* pMemPool, D2UnitStrc* pOwner)
{
    if (!pMemPool && pOwner)
    {
        pMemPool = pOwner->pMemoryPool;
    }
    D2InventoryStrc* pInventory = (D2InventoryStrc*)FOG_AllocPool(pMemPool, sizeof(D2InventoryStrc), ".\\INVENTORY\\Inventory.cpp", 0x22D, 0);
    if (!pInventory)
    {
        return 0;
    }
    memset(pInventory, 0, sizeof(D2InventoryStrc));
    pInventory->dwSignature = 0x1020304;
    pInventory->pMemPool = pMemPool;
    pInventory->pOwner = pOwner;
    if (pOwner)
    {
        pOwner->pInventory = pInventory;
        pInventory->dwOwnerGuid = !pOwner ? -1 : pOwner->dwUnitId;
    }
    return pInventory;
}

inline D2InventoryStrc* INVENTORY_GetPtrIfValid(D2InventoryStrc* pInventory)
{
    return (pInventory && pInventory->dwSignature == 0x01020304) ? pInventory : 0;
}

// 0x0063AC40
void __stdcall INVENTORY_FreeInventory(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        if (pInventory->pCursorItem)
        {
            INVENTORY_RemoveItem(pInventory->pCursorItem);
        }

        for (D2UnitStrc* pItem = pInventory->pFirstItem; pItem; pItem = pInventory->pFirstItem)
        {
            INVENTORY_RemoveItem(pItem);
        }

        for (int i = 0; i < pInventory->nGridCount; ++i)
        {
            D2InventoryGridStrc* pGrid = &pInventory->pGrids[i];
            if (pGrid->ppItems)
            {
                FOG_FreePool(pInventory->pMemPool, pGrid->ppItems, gszInventorySourceFile, 0x261, 0);
            }
        }

        if (pInventory->pGrids)
        {
            FOG_FreePool(pInventory->pMemPool, pInventory->pGrids, gszInventorySourceFile, 0x267, 0);
        }

        if (pInventory->pOwner)
        {
            pInventory->pOwner->pInventory = 0;
        }

        D2InventoryNodeStrc* pNextNode = 0;
        for (D2InventoryNodeStrc* pNode = pInventory->pFirstNode; pNode; pNode = pNextNode)
        {
            pNextNode = pNode->pNext;
            FOG_FreePool(pInventory->pMemPool, pNode, gszInventorySourceFile, 0x273, 0);
        }

        D2CorpseStrc* pNextCorpse = 0;
        for (D2CorpseStrc* pCorpse = pInventory->pFirstCorpse; pCorpse; pCorpse = pNextCorpse)
        {
            pNextCorpse = pCorpse->pNextCorpse;
            FOG_FreePool(pInventory->pMemPool, pCorpse, gszInventorySourceFile, 0x27B, 0);
        }

        FOG_FreePool(pInventory->pMemPool, pInventory, gszInventorySourceFile, 0x27F, 0);
    }
}

// Kept noinline: INVENTORY_RemoveItemFromInventory (0x0063AD90) calls it once out of line in the image, and inlining it here changes that caller.
// 0x0063AD50
__declspec(noinline) int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return 0;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
    if (!pItemExtraData)
    {
        return 0;
    }

    return pItemExtraData->pParentInv == pInventory;
}

inline D2UnitStrc* INVENTORY_UnitIsItemInline(D2UnitStrc* pItem)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        return pItem;
    }

    return 0;
}

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

inline D2ItemExtraDataStrc* INVENTORY_GetItemExtraDataFromItem(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return &pItemData->pExtraData;
    }

    return 0;
}

// 0x0063AD90
D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (!INVENTORY_UnitIsItemInline(pItem))
    {
        return 0;
    }

    if (INVENTORY_CompareWithItemsParentInventory(pInventory, pItem))
    {
        INVENTORY_RemoveItem(pItem);
        return pItem;
    }

    return 0;
}

// 0x0063B850
BOOL __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_ITEM || !INVENTORY_GetItemExtraInline(pItem))
    {
        return FALSE;
    }

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile, 1452);
    if (nWidth <= 0 || nHeight <= 0)
    {
        return FALSE;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nPage + INVGRID_INVENTORY, &tInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return FALSE;
    }

    if (nHeight == 1)
    {
        return INVENTORY_FindFreePositionForSingleRowItem(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
    }

    if (nHeight == 3 && nWidth <= 2)
    {
        return INVENTORY_FindFreePositionForTallNarrowItem(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
    }

    if (nHeight == 2 && nWidth == 2)
    {
        return INVENTORY_FindFreePositionForSquareItem(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
    }

    return INVENTORY_FindFreePositionForOtherItem(pInventory, pInventoryGrid, pFreeX, pFreeY, nWidth, nHeight);
}

// 0x0063ADD0
D2InventoryGridStrc* __stdcall INVENTORY_GetGrid(D2InventoryStrc* pInventory, int nInventoryGrid, D2InventoryGridInfoStrc* pInventoryGridInfo)
{
    D2PoolSystemStrc** const pInventoryMemPool = &pInventory->pMemPool;
    D2InventoryGridStrc* pInventoryGrid;
    if (pInventory->nGridCount > nInventoryGrid)
    {
        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        if (!pInventoryGridInfo)
        {
            if (!pInventoryGrid->ppItems)
            {
                return 0;
            }
        }
        else
        {
            if (!pInventoryGrid->ppItems)
            {
                pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
                pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
                pInventoryGrid->ppItems = (D2UnitStrc**)FOG_AllocPool(*pInventoryMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridHeight * pInventoryGrid->nGridWidth, gszInventorySourceFile, LINE_GRID_ALLOC1, 0);
                unsigned int nSize = pInventoryGrid->nGridWidth;
                nSize *= pInventoryGrid->nGridHeight;
                nSize *= sizeof(D2UnitStrc*);
                memset(pInventoryGrid->ppItems, 0, nSize);
            }

            if (pInventoryGrid->nGridWidth != pInventoryGridInfo->nGridX || pInventoryGrid->nGridHeight != pInventoryGridInfo->nGridY)
            {
                return 0;
            }
        }
    }
    else
    {
        if (!pInventoryGridInfo)
        {
            return 0;
        }

        pInventory->pGrids = (D2InventoryGridStrc*)FOG_ReallocPool(*pInventoryMemPool, pInventory->pGrids, sizeof(D2InventoryGridStrc) * (nInventoryGrid + 1), gszInventorySourceFile, LINE_GRID_REALLOC, 0);
        memset(&pInventory->pGrids[pInventory->nGridCount], 0, sizeof(D2InventoryGridStrc) * (nInventoryGrid - pInventory->nGridCount + 1));
        pInventory->nGridCount = nInventoryGrid + 1;

        pInventoryGrid = &pInventory->pGrids[nInventoryGrid];
        pInventoryGrid->nGridWidth = pInventoryGridInfo->nGridX;
        pInventoryGrid->nGridHeight = pInventoryGridInfo->nGridY;
        pInventoryGrid->ppItems = (D2UnitStrc**)FOG_AllocPool(*pInventoryMemPool, sizeof(D2UnitStrc*) * pInventoryGrid->nGridHeight * pInventoryGrid->nGridWidth, gszInventorySourceFile, LINE_GRID_ALLOC2, 0);
        unsigned int nSize = pInventoryGrid->nGridWidth;
                nSize *= pInventoryGrid->nGridHeight;
                nSize *= sizeof(D2UnitStrc*);
                memset(pInventoryGrid->ppItems, 0, nSize);
    }

    return pInventoryGrid;
}

// 0x0063AF20
static void INVENTORY_LinkItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraTyped(pItem);
    if (!pItemExtraData)
    {
        return;
    }

    if (pInventory->pLastItem)
    {
        D2ItemExtraDataStrc* pLastItemExtraData = INVENTORY_GetItemExtraInline(pInventory->pLastItem);
        if (pLastItemExtraData)
        {
            pLastItemExtraData->pNextItem = pItem;
        }
    }
    else
    {
        pInventory->pFirstItem = pItem;
    }

    pItemExtraData->pPreviousItem = pInventory->pLastItem;
    pInventory->pLastItem = pItem;
    pItemExtraData->pParentInv = pInventory;
}

static inline int UNITS_GetAnimModeInline(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

// 0x0063AF70
static void __stdcall INVENTORY_LinkGridItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, D2UnitStrc* pItem)
{
    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraTyped(pItem);
    if (!pItemExtraData || pItemExtraData->pParentInv != pInventory)
    {
        return;
    }

    if (pInventoryGrid->pLastItem)
    {
        D2ItemExtraDataStrc* pLastItemExtraData = INVENTORY_GetItemExtraInline(pInventoryGrid->pLastItem);
        if (pLastItemExtraData)
        {
            pLastItemExtraData->pNextGridItem = pItem;
        }
    }
    else
    {
        pInventoryGrid->pItem = pItem;
    }

    pItemExtraData->pPreviousGridItem = pInventoryGrid->pLastItem;
    pInventoryGrid->pLastItem = pItem;
}

// 0x0063AFD0
static BOOL __stdcall INVENTORY_PlaceItemInGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryGrid, int nInventoryRecordId)
{
    if (!pInventory || pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraInline(pItem);
    if (!pItemExtraData)
    {
        return FALSE;
    }

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile, 869);
    if (nWidth <= 0 || nHeight <= 0)
    {
        return FALSE;
    }

    D2InventoryGridStrc* pInventoryGrid;
    D2InventoryGridInfoStrc tInventoryGridInfo;
    if (nInventoryGrid >= INVGRID_INVENTORY)
    {
        DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);
        if (nXPos < 0 || nXPos + nWidth > tInventoryGridInfo.nGridX || nYPos < 0 || nYPos + nHeight > tInventoryGridInfo.nGridY)
        {
            return FALSE;
        }

        pInventoryGrid = INVENTORY_GetGrid(pInventory, nInventoryGrid, &tInventoryGridInfo);
    }
    else
    {
        nWidth = 1;
        nHeight = 1;
        switch (nInventoryGrid)
        {
        case INVGRID_BODYLOC:
            pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
            break;

        case INVGRID_BELT:
            pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
            break;

        default:
            return FALSE;
        }
    }

    if (!pInventoryGrid)
    {
        return FALSE;
    }

    if (!INVENTORY_AreGridCellsFree(pInventoryGrid, nXPos, nYPos, nWidth, nHeight))
    {
        return FALSE;
    }

    if (UNITS_GetAnimModeInline(pItem) == IMODE_ONGROUND && UNITS_GetRoom(pItem))
    {
        if (ITEMS_CheckUnitFlagEx(pItem, UNITFLAGEX_SERVERUNIT))
        {
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? UNIT_INVALID : pItem->dwUnitType, !pItem ? D2UnitInvalidGUID : pItem->dwUnitId);
        }

        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    INVENTORY_RemoveItem(pItem);
    INVENTORY_LinkItem(pInventory, pItem);
    INVENTORY_LinkGridItem(pInventory, pInventoryGrid, pItem);
    INVENTORY_FillGridCells(pInventoryGrid, nXPos, nYPos, nWidth, nHeight, pItem);

    pItemExtraData->nNodePos = nInventoryGrid + 1;
    ++pInventory->dwItemCount;

    UNITS_SetXForStaticUnit(pItem, nXPos);
    UNITS_SetYForStaticUnit(pItem, nYPos);

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        ITEMS_SetOwnerId(pItem, !pInventory->pOwner ? D2UnitInvalidGUID : pInventory->pOwner->dwUnitId);
    }
    else
    {
        ITEMS_SetOwnerId(pItem, D2UnitInvalidGUID);
    }

    if (nInventoryGrid >= INVGRID_INVENTORY)
    {
        ITEMS_SetInvPage(pItem, nInventoryGrid - INVGRID_INVENTORY);
    }

    switch (nInventoryGrid)
    {
    case INVGRID_BODYLOC:
        pItemExtraData->nNodePosOther = (nXPos >= 11) ? 4 : 3;
        break;

    case INVGRID_BELT:
        pItemExtraData->nNodePosOther = 2;
        break;

    default:
        pItemExtraData->nNodePosOther = 1;
        break;
    }

    return TRUE;
}

// 0x0063B210
BOOL __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nUnused)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    D2UnitStrc* pOwner = pInventory->pOwner;
    if (!pOwner)
    {
        return TRUE;
    }

    int nItemType;
    if (!pItem || (nItemType = pItem->dwUnitType) != UNIT_ITEM)
    {
        return FALSE;
    }

    if ((!pOwner ? 6 : pOwner->dwUnitType) != nItemType)
    {
        return TRUE;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataNoInl(pItem);
    if (!pItemExtraData)
    {
        return FALSE;
    }

    INVENTORY_RemoveItem(pItem);
    INVENTORY_LinkItem(pInventory, pItem);

    UNITS_SetXForStaticUnit(pItem, pInventory->dwItemCount);
    UNITS_SetYForStaticUnit(pItem, 0);

    pItemExtraData->nNodePos = 0;
    pItemExtraData->nNodePosOther = 1;
    ++pInventory->dwItemCount;

    ITEMS_SetOwnerId(pItem, D2UnitInvalidGUID);
    return TRUE;
}

// 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pFirstItem;
}

// 0x0063B2E0
D2UnitStrc* __stdcall INVENTORY_GetLastItem(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pLastItem;
}

// 0x0063B300
static BOOL __stdcall INVENTORY_CanItemBePlacedAtPos(D2InventoryGridStrc* pInventoryGrid, int nX, int nY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (nItemWidth + nX > pInventoryGrid->nGridWidth || nItemHeight + nY > pInventoryGrid->nGridHeight)
    {
        return FALSE;
    }

    return INVENTORY_AreGridCellsFree(pInventoryGrid, nX, nY, nItemWidth, nItemHeight);
}

// 0x0063B340
static unsigned char __stdcall INVENTORY_GetPlacementWeight(D2InventoryGridStrc* pInventoryGrid, int nXPos, int nYPos, unsigned char nItemWidth, unsigned char nItemHeight)
{
    int nResult = 0;

    if (nXPos > 0)
    {
        const int nLeft = nXPos - 1;
        for (int y = nYPos; y < nYPos + nItemHeight; ++y)
        {
            if (pInventoryGrid->ppItems[nLeft + y * pInventoryGrid->nGridWidth])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult = nItemHeight;
    }

    const int nRight = nXPos + nItemWidth;
    if (nRight < pInventoryGrid->nGridWidth)
    {
        for (int y = nYPos; y < nYPos + nItemHeight; ++y)
        {
            if (pInventoryGrid->ppItems[y * pInventoryGrid->nGridWidth + nRight])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult += nItemHeight;
    }

    if (nYPos > 0)
    {
        const int nTop = nYPos - 1;
        for (int x = nXPos; x < nRight; ++x)
        {
            if (pInventoryGrid->ppItems[nTop * pInventoryGrid->nGridWidth + x])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult += nItemWidth;
    }

    const int nBottom = nYPos + nItemHeight;
    if (nBottom < pInventoryGrid->nGridHeight)
    {
        for (int x = nXPos; x < nRight; ++x)
        {
            if (pInventoryGrid->ppItems[nBottom * pInventoryGrid->nGridWidth + x])
            {
                ++nResult;
            }
        }
    }
    else
    {
        nResult += nItemWidth;
    }

    if (nResult >= 2 * (nItemWidth + nItemHeight))
    {
        nResult = 255;
    }

    return nResult;
}

// 0x0063B490
static BOOL __stdcall INVENTORY_FindFreePositionBottomRightToTopLeftWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    unsigned char nMax = 0;
    for (int nX = pInventoryGrid->nGridWidth - 1; nX >= 0; --nX)
    {
        for (int nY = pInventoryGrid->nGridHeight - 1; nY >= 0; --nY)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                const unsigned char nWeight = INVENTORY_GetPlacementWeight(pInventoryGrid, nX, nY, nItemWidth, nItemHeight);
                if (nWeight > nMax)
                {
                    nMax = nWeight;
                    *pFreeX = nX;
                    *pFreeY = nY;

                    if (nWeight == 255)
                    {
                        return TRUE;
                    }
                }
            }
        }
    }

    return nMax > 0;
}

// 0x0063B540
static BOOL __stdcall INVENTORY_FindFreePositionRightToLeft(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    for (int nX = pInventoryGrid->nGridWidth - 1; nX >= 0; --nX)
    {
        for (int nY = 0; nY < pInventoryGrid->nGridHeight; ++nY)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                *pFreeX = nX;
                *pFreeY = nY;
                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063B5E0
static BOOL __stdcall INVENTORY_FindFreePositionForSingleRowItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionBottomRightToTopLeftWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return INVENTORY_FindFreePositionRightToLeft(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B620
static BOOL __stdcall INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    int nX;
    int nY;
    unsigned char nMax = 0;
    for (nY = 0; nY < pInventoryGrid->nGridHeight; ++nY)
    {
        for (nX = 0; nX < pInventoryGrid->nGridWidth; ++nX)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                const unsigned char nWeight = INVENTORY_GetPlacementWeight(pInventoryGrid, nX, nY, nItemWidth, nItemHeight);
                if (nWeight > nMax)
                {
                    nMax = nWeight;
                    *pFreeX = nX;
                    *pFreeY = nY;

                    if (nWeight == 255)
                    {
                        return TRUE;
                    }
                }
            }
        }
    }

    return nMax > 0;
}

// 0x0063B6E0
static BOOL __stdcall INVENTORY_FindFreePositionTopLeftToBottomRight(D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    for (int nX = 0; nX < pInventoryGrid->nGridWidth; ++nX)
    {
        for (int nY = 0; nY < pInventoryGrid->nGridHeight; ++nY)
        {
            if (!pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth] && INVENTORY_CanItemBePlacedAtPos(pInventoryGrid, nX, nY, nItemWidth, nItemHeight))
            {
                *pFreeX = nX;
                *pFreeY = nY;
                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063B790
static BOOL __stdcall INVENTORY_FindFreePositionForTallNarrowItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return INVENTORY_FindFreePositionTopLeftToBottomRight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B7D0
static BOOL __stdcall INVENTORY_FindFreePositionForSquareItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return INVENTORY_FindFreePositionTopLeftToBottomRight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B810
static BOOL __stdcall INVENTORY_FindFreePositionForOtherItem(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, int* pFreeX, int* pFreeY, unsigned char nItemWidth, unsigned char nItemHeight)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        return INVENTORY_FindFreePositionTopLeftToBottomRightWithWeight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
    }

    return INVENTORY_FindFreePositionTopLeftToBottomRight(pInventoryGrid, pFreeX, pFreeY, nItemWidth, nItemHeight);
}

// 0x0063B950
BOOL __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, BOOL bUnused, unsigned char nPage, const char* szFile, int nLine)
{
    int nX;
    int nY;
    if (!pInventory)
    {
        return FALSE;
    }

    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_ITEM)
    {
        if (!INVENTORY_GetFreePosition(pInventory, pItem, nInventoryRecordId, &nX, &nY, nPage))
        {
            return FALSE;
        }

        return INVENTORY_PlaceItemInGrid(pInventory, pItem, nX, nY, nPage + INVGRID_INVENTORY, nInventoryRecordId);
    }

    return FALSE;
}

// 0x0063B9C0
void __cdecl INVENTORY_Nop()
{
}

// 0x0063B9D0
BOOL __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryRecordId, D2UnitStrc** ppExchangeItem, unsigned int* pHoveredItems, unsigned char nPage)
{
    *pHoveredItems = 0;

    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    if (!INVENTORY_UnitIsItemInline(pItem))
    {
        return FALSE;
    }

    if (nPage == 0xFF)
    {
        return FALSE;
    }

    if (nXPos < 0 || nYPos < 0)
    {
        return FALSE;
    }

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile, 0x656);
    if (nWidth <= 0 || nHeight <= 0)
    {
        return FALSE;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nPage + 2, &tInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return FALSE;
    }

    BOOL bFree = TRUE;
    for (int nY = nYPos; nY < nYPos + nHeight; ++nY)
    {
        if (nY >= pInventoryGrid->nGridHeight)
        {
            bFree = FALSE;
            break;
        }

        for (int nX = nXPos; nX < nXPos + nWidth; ++nX)
        {
            if (nX >= pInventoryGrid->nGridWidth)
            {
                bFree = FALSE;
                break;
            }

            D2UnitStrc* pCurrentItem = pInventoryGrid->ppItems[nX + nY * pInventoryGrid->nGridWidth];
            if (pCurrentItem)
            {
                bFree = FALSE;
                if (*ppExchangeItem == pCurrentItem)
                {
                    break;
                }

                *ppExchangeItem = pCurrentItem;
                ++*pHoveredItems;
            }
        }
    }

    return bFree;
}

// 0x0063BB20
int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nInventoryRecordId, D2UnitStrc** ppOtherItem, unsigned char nPage, int bExcludeCube)
{
    if (!pInventory)
        return 0;
    if (pInventory->dwSignature != 0x1020304)
        return 0;
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
        return 0;
    if (nPage == 0xFF)
        return 0;
    if (nX < 0 || nY < 0)
        return 0;

    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile, 1723);
    if (nWidth <= 0 || nHeight <= 0)
        return 0;

    D2InventoryGridInfoStrc tGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tGridInfo);
    D2InventoryGridStrc* pGrid = INVENTORY_GetGrid(pInventory, nPage + 2, &tGridInfo);
    if (!pGrid)
        return 0;
    if (nY + nHeight > pGrid->nGridHeight || nX + nWidth > pGrid->nGridWidth)
        return 0;

    D2UnitStrc* pLastItem = 0;
    int nItems = 0;
    for (int nTestY = nY; nTestY < nY + nHeight; ++nTestY)
    {
        for (int nTestX = nX; nTestX < nX + nWidth; ++nTestX)
        {
            D2UnitStrc* pOtherItem = pGrid->ppItems[nTestX + nTestY * pGrid->nGridWidth];
            if (pOtherItem)
            {
                *ppOtherItem = pOtherItem;
                D2ItemsTxt* pRecord = DATATBLS_GetItemsTxtRecord(!pOtherItem ? -1 : pOtherItem->dwClassId);
                if (bExcludeCube && pRecord->dwCode == ' xob')
                    return 0;
                if (pOtherItem != pLastItem)
                {
                    ++nItems;
                    pLastItem = pOtherItem;
                }
            }
        }
    }
    if (nItems > 1)
    {
        *ppOtherItem = 0;
        return 0;
    }
    return 1;
}

// 0x0063BCB0
int __stdcall INVENTORY_ReturnTrue(int nUnused1, int nUnused2, int nUnused3, int nUnused4)
{
    return 1;
}

// 0x0063BCC0
BOOL __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nXPos, int nYPos, int nInventoryRecordId, BOOL bUnused, unsigned char nPage)
{
    if (!pInventory)
    {
        return FALSE;
    }

    return INVENTORY_PlaceItemInGrid(pInventory, pItem, nXPos, nYPos, nPage + INVGRID_INVENTORY, nInventoryRecordId);
}

// 0x0063BCF0
void __stdcall INVENTORY_Return(const char* szFile, int nLine, D2InventoryStrc* pInventory, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage)
{
}

inline D2UnitStrc* INVENTORY_UnitIsItem_Inl(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM) ? pItem : 0;
}

// 0x0063BD00
void __stdcall D2COMMON_10251_Return(int nUnused)
{
}

// 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nGridX, int nGridY, int* pX, int* pY, int nInventoryRecordId, unsigned char nPage)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nPage + INVGRID_INVENTORY, &tInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    if (nGridX >= 0 && nGridX <= pInventoryGrid->nGridWidth && nGridY >= 0 && nGridY <= pInventoryGrid->nGridHeight)
    {
        D2UnitStrc* pItem = pInventoryGrid->ppItems[nGridX + nGridY * pInventoryGrid->nGridWidth];
        if (pItem)
        {
            *pX = CLIENTS_GetUnitX(pItem);
            *pY = CLIENTS_GetUnitY(pItem);
            return pItem;
        }
    }

    return 0;
}

// 0x0063BDB0
BOOL __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc)
{
    if (pInventory && nBodyLoc >= 0 && nBodyLoc < NUM_BODYLOC)
    {
        return INVENTORY_PlaceItemInGrid(pInventory, pItem, nBodyLoc, 0, INVGRID_BODYLOC, 0);
    }

    return FALSE;
}

inline D2UnitStrc* INVENTORY_GetNextGridItemInline(D2UnitStrc* pItem)
{
    if (D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraInline(pItem))
    {
        return pItemExtraData->pNextGridItem;
    }

    return 0;
}

static inline unsigned int INVENTORY_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// Kept noinline: INVENTORY_UpdateWeaponGUIDOnRemoval (0x0063D2B0) calls it once out of line in the image, and inlining it here changes that caller.
// 0x0063BDE0
__declspec(noinline) D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    if ((unsigned int)nBodyLoc > 12)
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    return pInventoryGrid->ppItems[nBodyLoc];
}

// 0x0063BE30
void __stdcall sub_0063BE30_Return(int nUnused1, int nUnused2)
{
}

// 0x0063BE40
BOOL __stdcall INVENTORY_CheckEquipmentForWeaponByClass(D2InventoryStrc* pInventory, int nWeaponClass)
{
    if (!pInventory)
    {
        return FALSE;
    }

    D2UnitStrc* pItem;
    D2InventoryGridStrc* pInventoryGrid;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        pItem = 0;
    }
    else
    {
        pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (!pInventoryGrid)
        {
            pItem = 0;
        }
        else
        {
            pItem = pInventoryGrid->ppItems[BODYLOC_LARM];
        }
    }

    if (ITEMS_CanBeEquipped(pItem) && ITEMS_CheckWeaponClass(pItem, nWeaponClass))
    {
        return TRUE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        pItem = 0;
    }
    else
    {
        pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (!pInventoryGrid)
        {
            pItem = 0;
        }
        else
        {
            pItem = pInventoryGrid->ppItems[BODYLOC_RARM];
        }
    }

    if (ITEMS_CanBeEquipped(pItem) && ITEMS_CheckWeaponClass(pItem, nWeaponClass))
    {
        return TRUE;
    }

    return FALSE;
}

static __forceinline D2UnitStrc* GetBodyItemSigInl(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (!pInventory || pInventory->dwSignature != INVENTORY_SIGNATURE)
        return 0;
    D2InventoryGridStrc* pGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pGrid)
        return 0;
    return pGrid->ppItems[nBodyLoc];
}

// 0x0063BEF0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory)
{
    if (!pInventory)
        return 0;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return 0;
    if (pInventory->dwLeftItemGUID == -1)
        return 0;
    D2UnitStrc* pItem = GetBodyItemSigInl(pInventory, BODYLOC_LARM);
    if (pItem && sub_00629BB0_CheckItemType(pItem, 45) && (!pItem ? -1 : pItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pItem;
    pItem = GetBodyItemSigInl(pInventory, BODYLOC_RARM);
    if (pItem && sub_00629BB0_CheckItemType(pItem, 45) && (!pItem ? -1 : pItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pItem;
    return 0;
}

D2InventoryGridStrc* __stdcall EmitInventoryGridCaller(D2InventoryStrc* inventory, int index, D2InventoryGridInfoStrc* info)
{
    return INVENTORY_GetGrid(inventory, index, info);
}

static inline D2UnitStrc* GetBodyItem(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && (unsigned int)nBodyLoc <= 12)
    {
        D2InventoryGridStrc* pGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (pGrid)
        {
            return pGrid->ppItems[nBodyLoc];
        }
    }
    return 0;
}

// 0x0063BF90
D2UnitStrc* __stdcall INVENTORY_GetSecondaryWeapon(D2InventoryStrc* pInventory)
{
    if (!pInventory)
        return 0;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return 0;
    if (pInventory->dwLeftItemGUID == -1)
        return 0;

    D2UnitStrc* pItem = GetBodyItem(pInventory, BODYLOC_LARM);
    D2UnitStrc* pLeftItem;
    if (pItem)
    {
        pLeftItem = pItem;
        if (!sub_00629BB0_CheckItemType(pItem, 45))
            pLeftItem = 0;
    }
    else
    {
        pLeftItem = 0;
    }

    D2UnitStrc* pRightItem = GetBodyItem(pInventory, BODYLOC_RARM);
    if (!pRightItem || !sub_00629BB0_CheckItemType(pRightItem, 45))
        pRightItem = 0;

    if (pLeftItem && (!pLeftItem ? -1 : pLeftItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pRightItem;
    if (pRightItem && (!pRightItem ? -1 : pRightItem->dwUnitId) == pInventory->dwLeftItemGUID)
        return pLeftItem;
    return 0;
}

// 0x0063C050
D2UnitStrc* __stdcall INVENTORY_GetCompositItem(D2InventoryStrc* pInventory, int nComponent)
{
    int nInventoryGrid = INVGRID_BODYLOC;
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, nInventoryGrid, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    {
        D2UnitStrc* pLeftHandItem = INVENTORY_GetLeftHandWeapon(pInventory);

        for (int i = 0; i < NUM_GRID_BODYLOCS; ++i)
        {
            D2UnitStrc* pItem = pInventoryGrid->ppItems[i];
            if (pItem)
            {
                const int nWeaponClass = ITEMS_GetWeaponClassId(pInventoryGrid->ppItems[i]);
                if (nWeaponClass == WEAPONCLASS_1HS || nWeaponClass == WEAPONCLASS_1HT || nWeaponClass == WEAPONCLASS_HT1)
                {
                    if (nComponent == COMPOSIT_LEFTHAND)
                    {
                        if (pItem != pLeftHandItem)
                        {
                            return pItem;
                        }
                    }
                    else if (nComponent == COMPOSIT_RIGHTHAND && pItem == pLeftHandItem)
                    {
                        return pItem;
                    }
                }
                else
                {
                    if (ITEMS_GetComponent(pItem) == nComponent)
                    {
                        return pItem;
                    }
                }
            }
        }
    }

    return 0;
}

// 0x0063C110
int __stdcall INVENTORY_GetBodyLocFromEquippedItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && INVENTORY_UnitIsItem_Inl(pItem))
    {
        const int nBodyLoc = UNITS_GetXPosition(pItem);
        return nBodyLoc < NUM_BODYLOC_NOSWITCH ? nBodyLoc : 0;
    }

    return 0;
}

// 0x0063C150
int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && INVENTORY_UnitIsItem_Inl(pItem))
    {
        return UNITS_GetXPosition(pItem);
    }

    return 0;
}

// 0x0063C180
void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        if (!pItem)
        {
            if (INVENTORY_GetItemExtraDataFromItem(pInventory->pCursorItem))
            {
                INVENTORY_RemoveItem(pInventory->pCursorItem);
            }
        }
        else
        {
            if (D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem))
            {
                pInventory->pCursorItem = pItem;
                pItemExtraData->pParentInv = pInventory;
            }
        }
    }
}

// 0x0063C1E0
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pCursorItem;
}

// 0x0063C200
D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    D2InventoryGridInfoStrc* pInventoryGridInfo = 0;
    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pInventory->pOwner, 0, 1);
        DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);
        pInventoryGridInfo = &tInventoryGridInfo;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_INVENTORY, pInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        while (pItem)
        {
            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }
    }

    while (pItem)
    {
        if (ITEMS_AreStackablesEqual(pItem, pStackable) && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < ITEMS_GetTotalMaxStack(pItem))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063C2F0
D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        while (pItem)
        {
            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }
    }

    while (pItem)
    {
        if (ITEMS_AreStackablesEqual(pItem, pStackable) && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < ITEMS_GetTotalMaxStack(pItem))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063C3B0
D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pScrolls, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    D2InventoryGridInfoStrc* pInventoryGridInfo = 0;
    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pInventory->pOwner, 0, 1);
        DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);
        pInventoryGridInfo = &tInventoryGridInfo;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_INVENTORY, pInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        while (pItem)
        {
            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }
    }

    while (pItem)
    {
        if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && ITEMS_GetSuffixId(pItem, 0) == ITEMS_GetSuffixId(pScrolls, 0) && STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) < ITEMS_GetTotalMaxStack(pItem))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063C4B0
int __stdcall sub_0063C4B0_AlwaysZero(int nUnused)
{
    return 0;
}

// Kept noinline: a static whose callers here pass its arguments in registers (the #368 case).
// 0x0063C4C0
static __declspec(noinline) BOOL INVENTORY_PlaceItemInBeltGrid(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot)
{
    if (pInventory && INVENTORY_UnitIsItemInline(pItem) && nSlot >= 0 && nSlot < BELT_SLOTS)
    {
        return INVENTORY_PlaceItemInGrid(pInventory, pItem, nSlot, 0, INVGRID_BELT, 0);
    }

    return FALSE;
}

// 0x0063C4F0
BOOL __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot)
{
    if (INVENTORY_UnitIsItemInline(pItem) && ITEMS_CheckIfBeltable(pItem))
    {
        unsigned char nHeight;
        unsigned char nWidth;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile, 2731);
        if (nWidth == 1 && nHeight == 1)
        {
            return INVENTORY_PlaceItemInBeltGrid(pInventory, pItem, nSlot);
        }
    }

    return FALSE;
}

// 0x0063C550
void __stdcall D2COMMON_10267_Return(int nUnused1, int nUnused2)
{
}

// 0x0063C560
BOOL __stdcall INVENTORY_HasSimilarPotionInBelt(D2InventoryStrc* pInventory, D2UnitStrc* pPotion)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    const int nUnitType = pPotion ? pPotion->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return FALSE;
    }

    const int nClassId = pPotion->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pItemsTxtRecord || pItemsTxtRecord->dwCode == ITEMCODE_ISC || pItemsTxtRecord->dwCode == ITEMCODE_TSC)
    {
        return FALSE;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return FALSE;
    }

    for (int i = 0; i < BELT_COLUMNS; ++i)
    {
        D2UnitStrc* pBeltItem = pInventoryGrid->ppItems[i];
        if (pBeltItem && ITEMS_ComparePotionTypes(pPotion, pBeltItem))
        {
            return TRUE;
        }
    }

    return FALSE;
}

// 0x0063C600
BOOL __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return FALSE;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return FALSE;
    }

    if (!ITEMS_CheckIfBeltable(pItem))
    {
        return FALSE;
    }

    unsigned char nHeight;
    unsigned char nWidth;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszInventorySourceFile, LINE_GETDIMENSIONS);
    if (nWidth != 1 || nHeight != 1)
    {
        return FALSE;
    }

    D2UnitStrc* pBelt = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_BELT);
    int nBeltType = BELT_DEFAULT_TYPE;
    if (pBelt)
    {
        nBeltType = UNITS_GetBeltType(pBelt);
    }

    D2BeltsTxtLayout tBeltsTxtRecord;
    DATATBLS_GetBeltsTxtRecord(nBeltType, 0, (D2BeltsTxt*)&tBeltsTxtRecord);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
    if (pInventoryGrid)
    {
        for (int i = 0; i < BELT_COLUMNS; ++i)
        {
            D2UnitStrc* pBeltItem = pInventoryGrid->ppItems[i];
            if (pBeltItem && ITEMS_ComparePotionTypes(pItem, pBeltItem))
            {
                for (int nId = i; nId < tBeltsTxtRecord.nBoxes; nId += BELT_COLUMNS)
                {
                    if (!pInventoryGrid->ppItems[nId])
                    {
                        *pFreeSlotId = nId;
                        return TRUE;
                    }
                }
            }
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (!pItemsTxtRecord || !pItemsTxtRecord->nAutoBelt)
        {
            return FALSE;
        }

        for (int i = 0; i < BELT_COLUMNS; ++i)
        {
            if (!pInventoryGrid->ppItems[i])
            {
                *pFreeSlotId = i;
                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063C790
BOOL __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    int nFreeSlot = 0;
    if (!INVENTORY_GetFreeBeltSlot(pInventory, pItem, &nFreeSlot) || !pInventory || !INVENTORY_UnitIsItemInline(pItem))
    {
        return FALSE;
    }

    if (nFreeSlot < 0)
    {
        return FALSE;
    }

    if (nFreeSlot >= BELT_SLOTS)
    {
        return FALSE;
    }

    return INVENTORY_PlaceItemInGrid(pInventory, pItem, nFreeSlot, 0, INVGRID_BELT, 0);
}

// 0x0063C7F0
D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc* pInventory, int nSlotId)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BELT, &gBeltInventoryGridInfo);
        if (pInventoryGrid && nSlotId >= 0 && nSlotId < BELT_SLOTS)
        {
            return pInventoryGrid->ppItems[nSlotId];
        }
    }

    return 0;
}

// 0x0063C830
int __stdcall INVENTORY_GetUseableItemFromBeltSlot(D2InventoryStrc* inventory, D2UnitStrc* item, int slot, D2UnitStrc** previous)
{
    if (!inventory)
        return 0;
    if (inventory->dwSignature != 0x01020304)
        return 0;
    D2InventoryGridStrc* grid = INVENTORY_GetGrid(inventory, 1, &gBeltInventoryGridInfo);
    if (!grid)
        return 0;
    if (!item || item->dwUnitType != UNIT_ITEM || !ITEMS_CheckIfBeltable(item))
        return 0;
    unsigned char width;
    unsigned char height;
    ITEMS_GetDimensions(item, &width, &height, gszInventorySourceFile, 0xBC9);
    if (width != 1 || height != 1)
        return 0;
    D2ItemsTxt* record = DATATBLS_GetItemsTxtRecord(!item ? -1 : item->dwClassId);
    if (!record || record->bFlag0x11D != 1 || record->nBelt != 1)
        return 0;
    *previous = INVENTORY_GetItemFromBeltSlot(inventory, slot);
    return 1;
}

// 0x0063C8F0
BOOL __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem)
{
    if (!pInventory)
    {
        return FALSE;
    }

    if (ppItem)
    {
        *ppItem = 0;
    }

    D2UnitStrc* pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_RARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMSIsA(pItem, ITEMTYPE_ANY_SHIELD))
    {
        if (ppItem)
        {
            *ppItem = pItem;
        }

        return TRUE;
    }

    pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_LARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMSIsA(pItem, ITEMTYPE_ANY_SHIELD))
    {
        if (ppItem)
        {
            *ppItem = pItem;
        }

        return TRUE;
    }

    return FALSE;
}

// 0x0063C9B0
BOOL __stdcall INVENTORY_GetEquippedWeapon(D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int* pBodyLoc, BOOL* pIsLeftHandItem)
{
    if (!pInventory)
    {
        return FALSE;
    }

    *pIsLeftHandItem = FALSE;

    D2UnitStrc* pLeftHandItem = INVENTORY_GetLeftHandWeapon(pInventory);

    D2UnitStrc* pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_RARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMSIsA(pItem, ITEMTYPE_WEAPON))
    {
        *ppItem = pItem;
        *pBodyLoc = BODYLOC_RARM;

        if (pItem == pLeftHandItem)
        {
            *pIsLeftHandItem = TRUE;
        }

        return TRUE;
    }

    pItem = INVENTORY_GetBodyLocItemInline(pInventory, BODYLOC_LARM);
    if (ITEMS_CanBeEquipped(pItem) && ITEMSIsA(pItem, ITEMTYPE_WEAPON))
    {
        *ppItem = pItem;
        *pBodyLoc = BODYLOC_LARM;

        if (pItem == pLeftHandItem)
        {
            *pIsLeftHandItem = TRUE;
        }

        return TRUE;
    }

    *ppItem = 0;
    return FALSE;
}

// 0x0063CAB0
BOOL __stdcall INVENTORY_HasBodyArmorEquipped(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (pInventoryGrid)
        {
            D2UnitStrc* pItem = pInventoryGrid->ppItems[BODYLOC_TORSO];
            if (pItem && ITEMSIsA(pItem, ITEMTYPE_ARMOR))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063CB00
BOOL __stdcall INVENTORY_IsItemBodyLocFree(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc, int nInventoryRecordId)
{
    if (INVENTORY_GetPtrIfValid(pInventory) && (unsigned int)nBodyLoc <= BODYLOC_LAST)
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (pInventoryGrid)
        {
            D2UnitStrc* pBodyLocItem = pInventoryGrid->ppItems[nBodyLoc];
            if (pBodyLocItem && pItem)
            {
                int nFreeX;
                int nFreeY;
                return INVENTORY_GetFreePosition(pInventory, pBodyLocItem, nInventoryRecordId, &nFreeX, &nFreeY, 0) != 0;
            }
        }
    }

    return FALSE;
}

// 0x0063CB70
void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        for (D2UnitStrc* pItem = pInventory->pFirstItem; pItem; pItem = pInventory->pFirstItem)
        {
            INVENTORY_RemoveItem(pItem);
        }
    }
}

// 0x0063CBB0
D2InventoryNodeStrc* __stdcall INVENTORY_GetTradeInventory(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pFirstNode;
}

// 0x0063CBD0
void __stdcall INVENTORY_FreeTradeInventory(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2InventoryNodeStrc* pNextNode = 0;
        for (D2InventoryNodeStrc* pNode = pInventory->pFirstNode; pNode; pNode = pNextNode)
        {
            pNextNode = pNode->pNext;
            FOG_FreeServerMemory(pInventory->pMemPool, pNode, gszInventorySourceFile, 3259, 0);
        }

        pInventory->pFirstNode = 0;
        pInventory->pLastNode = 0;
    }
}

// 0x0063CC30
int __stdcall INVENTORY_CheckForItemInTradeInventory(D2InventoryStrc* pInventory, int nItemId)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        for (D2InventoryNodeStrc* pNode = pInventory->pFirstNode; pNode; pNode = pNode->pNext)
        {
            if (pNode->nItemId == nItemId)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x0063CC70
void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!INVENTORY_GetPtrIfValid(pInventory))
    {
        return;
    }

    if (!INVENTORY_UnitIsItemInline(pItem))
    {
        return;
    }

    if (INVENTORY_CheckForItemInTradeInventory(pInventory, pItem->dwUnitId))
    {
        return;
    }

    D2InventoryNodeStrc* ptNode = (D2InventoryNodeStrc*)FOG_AllocPool(pInventory->pMemPool, sizeof(D2InventoryNodeStrc), gszInventorySourceFile, 3337, 0);
    D2_ASSERT(ptNode, 3338);
    memset(ptNode, 0x00, sizeof(D2InventoryNodeStrc));
    ptNode->nItemId = pItem->dwUnitId;

    if (!pInventory->pFirstNode)
    {
        pInventory->pFirstNode = ptNode;
    }
    else
    {
        pInventory->pLastNode->pNext = ptNode;
    }

    ptNode->pNext = 0;
    pInventory->pLastNode = ptNode;
}

// 0x0063CD20
D2InventoryNodeStrc* __stdcall INVENTORY_GetNextNode(D2InventoryNodeStrc* pNode)
{
    if (!pNode)
    {
        return 0;
    }

    return pNode->pNext;
}

// 0x0063CD40
int __stdcall INVENTORY_GetItemGUIDFromNode(D2InventoryNodeStrc* pNode)
{
    if (!pNode)
    {
        return 0;
    }

    return pNode->nItemId;
}

// 0x0063CD60
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->dwItemCount;
}

// 0x0063CD80
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridInfoStrc tInventoryGridInfo;
    D2InventoryGridInfoStrc* pInventoryGridInfo = 0;
    if (pInventory->pOwner && pInventory->pOwner->dwUnitType == UNIT_PLAYER)
    {
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pInventory->pOwner, 0, 1);
        DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);
        pInventoryGridInfo = &tInventoryGridInfo;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_INVENTORY, pInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        for (;;)
        {
            if (!pItem)
            {
                return 0;
            }

            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }

        D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataNoInl(pItem);
        pItem = pItemExtraData ? pItemExtraData->pNextGridItem : 0;
    }

    while (pItem)
    {
        if (ITEMSIsA(pItem, nItemType))
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

static inline D2UnitStrc* INVENTORY_GetBodyLocItemInline(D2InventoryStrc* pInventory, int nBodyLoc)
{
    D2UnitStrc* pItem;
    if (!INVENTORY_GetPtrIfValid(pInventory))
    {
        pItem = 0;
    }
    else
    {
        D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
        if (!pInventoryGrid)
        {
            pItem = 0;
        }
        else
        {
            pItem = pInventoryGrid->ppItems[nBodyLoc];
        }
    }

    return pItem;
}

// 0x0063CE60
D2UnitStrc* __stdcall INVENTORY_GetEquippedItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pCheckItem)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        while (pItem)
        {
            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }
    }

    while (pItem)
    {
        if (ITEMSIsA(pItem, nItemType) && INVENTORY_GetUnitXInline(pItem) < INVENTORY_GRID_X_LIMIT)
        {
            return pItem;
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063CF30
D2UnitStrc* __stdcall INVENTORY_GetEquippedItemByCode(D2InventoryStrc* pInventory, int nItemCode, D2UnitStrc* pCheckItem)
{
    int nClassId;
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    if (!DATATBLS_GetItemRecordFromItemCode(nItemCode, &nClassId))
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        while (pItem)
        {
            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }
    }

    while (pItem)
    {
        if ((!pItem ? -1 : pItem->dwClassId) == nClassId)
        {
            if (INVENTORY_GetUnitXInline(pItem) < INVENTORY_GRID_X_LIMIT)
            {
                return pItem;
            }
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063D010
D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByCode(D2InventoryStrc* pInventory, int nItemCode, D2UnitStrc* pCheckItem)
{
    int nClassId;
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    if (!DATATBLS_GetItemRecordFromItemCode(nItemCode, &nClassId))
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_INVENTORY, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    D2UnitStrc* pItem = pInventoryGrid->pItem;
    if (pCheckItem)
    {
        while (pItem)
        {
            if (pItem == pCheckItem)
            {
                break;
            }

            pItem = INVENTORY_GetNextGridItemInline(pItem);
        }
    }

    while (pItem)
    {
        if ((!pItem ? -1 : pItem->dwClassId) == nClassId)
        {
            if (INVENTORY_GetUnitXInline(pItem) < INVENTORY_GRID_X_LIMIT)
            {
                return pItem;
            }
        }

        pItem = INVENTORY_GetNextGridItemInline(pItem);
    }

    return 0;
}

// 0x0063D0F0
int __stdcall INVENTORY_GetSetItemEquipCountByFileIndex(D2InventoryStrc* inventory,int fileIndex)
{
 if (!inventory) return 0;
 if (inventory->dwSignature != 0x1020304) return 0;
 D2InventoryGridStrc* grid=INVENTORY_GetGrid(inventory,0,&gBodyLocInventoryGridInfo);
 if (!grid) return 0;
 int count=0;
 for (D2UnitStrc* item=grid->pItem;item;) {
  if (ITEMS_GetItemQuality(item)==ITEMQUAL_SET && ITEMS_GetFileIndex(item)==fileIndex) {
   unsigned int x;
   if (item->dwUnitType==UNIT_OBJECT || (item->dwUnitType>3 && item->dwUnitType<=5)) x=item->pStaticPath->tGameCoords.nX;
   else x=item->pDynamicPath ? PATH_GetXPosition(item->pDynamicPath):0;
   if (x<11) ++count;
  }
  if (item->dwUnitType!=UNIT_ITEM) return count;
  D2ItemDataStrc* data=item->pItemData;
  if (!data) return count;
  D2ItemExtraDataStrc* extra=&data->pExtraData;
  if (!extra) return count;
  item=extra->pNextGridItem;
 }
 return count;
}

// 0x0063D190
void __fastcall INVENTORY_SetLeftItemGUID(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int bSet)
{
    if (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE && pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        const int nItemGUID = pItem->dwUnitId;
        if (bSet)
        {
            pInventory->dwLeftItemGUID = nItemGUID;
        }
        else if (pInventory->dwLeftItemGUID == nItemGUID)
        {
            pInventory->dwLeftItemGUID = D2UnitInvalidGUID;
        }
    }
}

// 0x0063D1D0
void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return;
    }
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_ITEM)
    {
        return;
    }
    if (!ITEMSIsA(pItem, ITEMTYPE_WEAPON))
    {
        return;
    }
    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc != BODYLOC_RARM && nBodyLoc != BODYLOC_LARM)
    {
        return;
    }
    if (!ITEMS_CanBeEquipped(pItem))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 0);
        return;
    }
    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 1);
        return;
    }
    if (!ITEMSIsA(pWeapon, ITEMTYPE_WEAPON))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 1);
        return;
    }
    if (ITEMSIsA(pWeapon, ITEMTYPE_MISSILE_POTION))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 1);
        return;
    }
    INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 0);
}

inline void INVENTORY_SetLeftItemGUIDInline(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int bSet)
{
    if (pInventory && pInventory->dwSignature == INVENTORY_SIGNATURE && pItem && pItem->dwUnitType == UNIT_ITEM)
    {
        const int nItemGUID = pItem ? pItem->dwUnitId : D2UnitInvalidGUID;
        if (bSet)
        {
            pInventory->dwLeftItemGUID = nItemGUID;
        }
        else if (pInventory->dwLeftItemGUID == nItemGUID)
        {
            pInventory->dwLeftItemGUID = D2UnitInvalidGUID;
        }
    }
}

// 0x0063D2B0
void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (!pInventory)
    {
        return;
    }
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_ITEM)
    {
        return;
    }
    if (!ITEMSIsA(pItem, ITEMTYPE_WEAPON))
    {
        return;
    }
    INVENTORY_SetLeftItemGUIDInline(pInventory, pItem, 0);
    const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    D2UnitStrc* pWeapon = 0;
    if (nBodyLoc == BODYLOC_RARM)
    {
        pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
    }
    else if (nBodyLoc == BODYLOC_LARM)
    {
        pWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
    }
    else
    {
        return;
    }
    if (pWeapon && ITEMS_CanBeEquipped(pWeapon))
    {
        INVENTORY_SetLeftItemGUIDInline(pInventory, pWeapon, 1);
    }
}

inline D2UnitStrc* INVENTORY_GetItemFromBodyLocInl(D2InventoryStrc* pInventory, int nBodyLoc)
{
    if (!pInventory)
    {
        return 0;
    }
    if (pInventory->dwSignature != 0x1020304)
    {
        return 0;
    }
    if (!INVENTORY_ValidateBodyLoc(nBodyLoc))
    {
        return 0;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return 0;
    }

    return pInventoryGrid->ppItems[nBodyLoc];
}

// 0x0063D340
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    D2UnitStrc* pLeftHandItem = INVENTORY_GetItemFromBodyLocInl(pInventory, BODYLOC_LARM);
    D2UnitStrc* pRightHandItem = INVENTORY_GetItemFromBodyLocInl(pInventory, BODYLOC_RARM);
    if (pLeftHandItem)
    {
        if (pRightHandItem)
        {
            if (ITEMS_Is1Or2Handed(pPlayer, pLeftHandItem) || ITEMS_Is1Or2Handed(pPlayer, pRightHandItem))
            {
                return 1;
            }

            if (ITEMS_CheckWeaponIfTwoHanded(pLeftHandItem) || ITEMS_CheckWeaponIfTwoHanded(pRightHandItem))
            {
                return 2;
            }
        }
        else
        {
            if (ITEMS_CheckWeaponIfTwoHanded(pLeftHandItem) || ITEMS_Is1Or2Handed(pPlayer, pLeftHandItem))
            {
                return 2;
            }
        }
    }
    else if (pRightHandItem)
    {
        if (ITEMS_CheckWeaponIfTwoHanded(pRightHandItem) || ITEMS_Is1Or2Handed(pPlayer, pRightHandItem))
        {
            return 2;
        }
    }

    return -1;
}

// 0x0063D430
void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc* pInventory, int nOwnerGuid)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        pInventory->dwOwnerGuid = nOwnerGuid;
    }
}

// 0x0063D450
int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return D2UnitInvalidGUID;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return D2UnitInvalidGUID;
    }

    return pInventory->dwOwnerGuid;
}

// 0x0063D470
void __stdcall INVENTORY_CreateCorpseForPlayer(D2InventoryStrc* pInventory, int nUnitId, int nMercNameId, int bCounted)
{
    if (!pInventory)
        return;
    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
        return;

    D2CorpseStrc* pLastCorpse = pInventory->pLastCorpse;
    D2CorpseStrc* pCorpse = (D2CorpseStrc*)FOG_AllocPool(pInventory->pMemPool, sizeof(D2CorpseStrc), gszInventorySourceFile, 0xFEA, 0);
    pCorpse->bCounted = bCounted;
    pCorpse->dwUnitId = nUnitId;
    pCorpse->nMercNameId = nMercNameId;
    pCorpse->pNextCorpse = 0;

    pInventory->pLastCorpse = pCorpse;
    if (!pInventory->pFirstCorpse)
        pInventory->pFirstCorpse = pCorpse;
    else
        pLastCorpse->pNextCorpse = pCorpse;

    if (pCorpse->bCounted)
        ++pInventory->nCorpseCount;
}

// 0x0063D4E0
int __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, unsigned int nUnitId, unsigned int bWasCounted)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    D2CorpseStrc* pPreviousCorpse = 0;
    D2CorpseStrc* pCorpse = pInventory->pFirstCorpse;
    for (; pCorpse; pCorpse = pCorpse->pNextCorpse)
    {
        if (pCorpse->dwUnitId == nUnitId && pCorpse->bCounted == bWasCounted)
        {
            break;
        }

        pPreviousCorpse = pCorpse;
    }

    if (!pCorpse)
    {
        return 0;
    }

    D2CorpseStrc* pNextCorpse = pCorpse->pNextCorpse;
    if (!pPreviousCorpse)
    {
        pInventory->pFirstCorpse = pNextCorpse;
        if (!pNextCorpse)
        {
            pInventory->pLastCorpse = 0;
        }
    }
    else
    {
        pPreviousCorpse->pNextCorpse = pNextCorpse;
        if (!pNextCorpse)
        {
            pInventory->pLastCorpse = pPreviousCorpse;
        }
    }

    if (pCorpse->bCounted)
    {
        --pInventory->nCorpseCount;
    }

    FOG_FreeServerMemory(pInventory->pMemPool, pCorpse, gszInventorySourceFile, 4148, 0);
    return 1;
}

// 0x0063D570
D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->pFirstCorpse;
}

// 0x0063D590
void __stdcall INVENTORY_FreeAllCorpses(D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetPtrIfValid(pInventory))
    {
        D2CorpseStrc* pNextCorpse = 0;
        for (D2CorpseStrc* pCorpse = pInventory->pFirstCorpse; pCorpse; pCorpse = pNextCorpse)
        {
            pNextCorpse = pCorpse->pNextCorpse;
            FOG_FreeServerMemory(pInventory->pMemPool, pCorpse, gszInventorySourceFile, 4209, 0);
        }

        pInventory->pFirstCorpse = 0;
        pInventory->pLastCorpse = 0;
    }
}

// 0x0063D5F0
int __stdcall INVENTORY_GetCorpseCount(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    return pInventory->nCorpseCount;
}

// 0x0063D610
D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse)
{
    if (!pCorpse)
    {
        return pCorpse;
    }

    return pCorpse->pNextCorpse;
}

// 0x0063D630
D2SkillStrc* __stdcall SKILLS_GetFirstSkillFromSkillList(D2SkillListStrc* pSkillList)
{
    if (!pSkillList)
        return 0;
    return pSkillList->pFirstSkill;
}

// 0x0063D650
unsigned int __stdcall INVENTORY_GetCorpseMercNameId(D2CorpseStrc* pCorpse)
{
    if (!pCorpse)
    {
        return 0;
    }

    return pCorpse->nMercNameId;
}

// 0x0063D670
unsigned int __stdcall INVENTORY_IsPlayerCorpse(D2CorpseStrc* pCorpse)
{
    if (!pCorpse)
    {
        return 0;
    }

    return pCorpse->bCounted;
}

// 0x0063D690
static void __cdecl INVENTORY_GetArmorComponents(D2UnitStrc* item, AppearanceSix* output)
{
    if (item)
    {
        ItemRecord* record = sub_006335F0_ItemRecord(FIELD(s32, item, 4));
        D2_ASSERT(record, 0x121E);
        output->f_0 = FIELD(u8, record, 0x116);
        output->f_1 = FIELD(u8, record, 0x117);
        output->field2 = FIELD(u8, record, 0x118);
        output->field3 = FIELD(u8, record, 0x119);
        output->f_4 = FIELD(u8, record, 0x11A);
        output->field5 = FIELD(u8, record, 0x11B);
    }
    else
    {
        memset(output, 0, sizeof(AppearanceSix));
    }
}

// 0x0063D710
void __fastcall INVENTORY_InitializeComponentArray()
{
    if (!gbComponentArrayInitialized)
    {
        gbComponentArrayInitialized = 1;

        memset(gaTxtComponentItemTypeMap, 0, sizeof(gaTxtComponentItemTypeMap));

        D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();

        gaTxtComponentItemTypeMap[1].dwCode = 0x2074696C;
        gaTxtComponentItemTypeMap[1].nItemType = ITEMTYPE_ARMOR;
        gaTxtComponentItemTypeMap[2].dwCode = 0x2064656D;
        gaTxtComponentItemTypeMap[2].nItemType = ITEMTYPE_ARMOR;
        gaTxtComponentItemTypeMap[3].dwCode = 0x20797668;
        gaTxtComponentItemTypeMap[3].nItemType = ITEMTYPE_ARMOR;

        int nCurrentTableEntries = 4;

        for (int i = 0; i < pItemDataTbl->nItemsTxtRecordCount; ++i)
        {
            D2ItemsTxt* pItemsTxtRecord = &pItemDataTbl->pItemsTxt[i];

            int dwCode = 0;
            if (pItemsTxtRecord->dwAltCode2)
            {
                dwCode = pItemsTxtRecord->dwAltCode2;
            }
            else
            {
                dwCode = pItemsTxtRecord->dwCode;
            }

            int bNeedsToBeAdded = 1;
            if (!(ITEMS_CheckType(pItemsTxtRecord->wType[0], ITEMTYPE_WEAPON)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], ITEMTYPE_ARMOR)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], ITEMTYPE_ANY_SHIELD)
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], ITEMTYPE_HELM))
                || ITEMS_CheckType(pItemsTxtRecord->wType[0], ITEMTYPE_CIRCLET))
            {
                bNeedsToBeAdded = 0;
            }

            int bFound = 0;
            for (int nCounter = 0; nCounter < nCurrentTableEntries; ++nCounter)
            {
                if (gaTxtComponentItemTypeMap[nCounter].dwCode == dwCode)
                {
                    bFound = 1;
                    break;
                }
            }

            if (!bFound && bNeedsToBeAdded == 1)
            {
                int nIndex = nCurrentTableEntries;

                while (ITEMS_CheckType(gaComponentItemTypeMap[nIndex].nItemType, ITEMTYPE_WEAPON) && ITEMS_CheckType(pItemsTxtRecord->wType[0], ITEMTYPE_WEAPON)
                       || ITEMS_CheckType(gaComponentItemTypeMap[nIndex].nItemType, ITEMTYPE_ANY_ARMOR) && ITEMS_CheckType(pItemsTxtRecord->wType[0], ITEMTYPE_ANY_ARMOR)
                       || gaTxtComponentItemTypeMap[nIndex].dwCode)
                {
                    ++nIndex;
                }

                if (nIndex >= 255)
                {
                    nIndex = nCurrentTableEntries;
                }

                gaTxtComponentItemTypeMap[nIndex].dwCode = dwCode;
                gaTxtComponentItemTypeMap[nIndex].nItemType = pItemsTxtRecord->wType[0];

                if (nCurrentTableEntries == nIndex)
                {
                    ++nCurrentTableEntries;
                }
            }
        }

        gnComponentArrayRecordCount = 255;
    }
}

// 0x0063D900
static s32 __cdecl INVENTORY_FindComponentArrayIndex(u32 second, u32 first)
{
    sub_0063D710_InitCodes();
    for (u32 index = 1; index < 0xFF; ++index)
    {
        const u32 code = gTable_0096CC68[index].code;
        if (code == first || code == second)
        {
            return index;
        }
    }
    return 0;
}

// 0x0063D930
static void __stdcall INVENTORY_SetBowHandComponents(u8* firstOutput, u8* secondOutput, D2UnitStrc* hItem, D2UnitStrc* unit)
{
    D2_ASSERT(unit, 0x13B3);
    D2_ASSERT(hItem, 0x13B4);
    const u8 page = ITEMS_GetBodyLocation(hItem);
    if (page == 4 || page == 5)
    {
        Inventory* inventory = FIELD(Inventory*, unit, 0x60);
        s32 mode;
        const u32 weapon = COMPOSIT_GetWeaponClassId(unit, inventory, &mode, -1, 1);
        const u8 slot = ITEMS_GetComponent(hItem);
        if (weapon == 0x20776278)
        {
            if (slot == 5 || slot == 6)
            {
                if (inventory)
                {
                    D2UnitStrc* equipped = INVENTORY_GetCompositItem(inventory, 5);
                    if (equipped)
                    {
                        s32 equippedId = FIELD(s32, equipped, 4);
                        ItemRecord* record = sub_006335F0_ItemRecord(equippedId);
                        D2_ASSERT(record, 0x13CF);
                        const u32 c80 = FIELD(u32, record, 0x80);
 const u32 c90 = FIELD(u32, record, 0x90);
 const s32 code = INVENTORY_FindComponentArrayIndex(c80, c90);
                        if (code <= 0)
                        {
                            firstOutput[6] = 0xFF;
                            secondOutput[6] = 0xFF;
                        }
                        else
                        {
                            firstOutput[6] = (u8)code;
                        }
                    }
                }
            }
        }
        else if (weapon == 0x20776F62)
        {
            if (slot == 6)
            {
                s32 recordIndex;
                ItemRecord* record = sub_00633640_RecordByCode(0x2074696C, &recordIndex);
                if (record)
                {
                    const u32 c80 = FIELD(u32, record, 0x80);
 const u32 c90 = FIELD(u32, record, 0x90);
 const s32 code = INVENTORY_FindComponentArrayIndex(c80, c90);
                    if (!code)
                    {
                        firstOutput[5] = 0xFF;
                        secondOutput[5] = 0xFF;
                    }
                    else
                    {
                        firstOutput[5] = (u8)code;
                    }
                }
            }
        }
    }
}

// 0x0063DA70
static void __stdcall INVENTORY_FillItemComponentGfxInfo(D2UnitStrc* unit, u8* firstOutput, u8* secondOutput, D2UnitStrc* item)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (inventory)
    {
        D2UnitStrc* firstHand = INVENTORY_GetCompositItem(inventory, 5);
        D2UnitStrc* secondHand = INVENTORY_GetCompositItem(inventory, 6);
        ItemRecord* record = sub_006335F0_ItemRecord(!item ? -1 : FIELD(s32, item, 4));
        D2_ASSERT(record, 0x140C);
        u8 slot = ITEMS_GetComponent(item);
        const u32 code1 = FIELD(u32, record, 0x80);
        const u32 code2 = FIELD(u32, record, 0x90);
        const s32 code = INVENTORY_FindComponentArrayIndex(code1, code2);
        if (!code)
        {
            if (slot < 0x10)
            {
                firstOutput[slot] = 0xFF;
                secondOutput[slot] = 0xFF;
            }
        }
        else
        {
            if (item == firstHand)
            {
                slot = 5;
            }
            else if (item == secondHand)
            {
                slot = 6;
            }
            else if (slot >= 0x10)
            {
                return;
            }
            firstOutput[slot] = (u8)code;
            INVENTORY_SetBowHandComponents(firstOutput, secondOutput, item, unit);
            if (!ITEMS_GetColor(unit, item, &secondOutput[slot], 0))
            {
                secondOutput[slot] = 0xFF;
            }
            else
            {
                ++secondOutput[slot];
            }
        }
    }
}

// 0x0063DB80
void __stdcall sub_0063DB80_Nop(int nUnused1, int nUnused2)
{
}

// 0x0063DB90
static int __stdcall INVENTORY_SelectValue(int a, int b)
{
    if (b)
        return a ? 5 : 1;
    return a ? 3 : 0;
}

int __stdcall sub_K15_Emit5(int* p, int n)
{
    return INVENTORY_SelectValue(p[0], n) + INVENTORY_SelectValue(p[n], p[3]);
}

// 0x0063DBC0
static int INVENTORY_CanItemsBeWieldedTogether(D2UnitStrc* pUnit, D2UnitStrc* pItem1, D2UnitStrc* pItem2)
{
    if (!pItem1 || !pItem2
        || ITEMS_GetAmmoType(pItem1) && ITEMSIsA(pItem2, ITEMS_GetAmmoType(pItem1))
        || ITEMS_GetAmmoType(pItem2) && ITEMSIsA(pItem1, ITEMS_GetAmmoType(pItem2)))
    {
        return 1;
    }

    if (ITEMS_GetQuiverType(pItem1) || ITEMS_GetQuiverType(pItem2))
    {
        return 0;
    }

    if (ITEMS_CheckWeaponIfTwoHanded(pItem1) && !ITEMS_Is1Or2Handed(pUnit, pItem1))
    {
        return 0;
    }

    if (ITEMS_CheckWeaponIfTwoHanded(pItem2) && !ITEMS_Is1Or2Handed(pUnit, pItem2))
    {
        return 0;
    }

    if (ITEMSIsA(pItem1, 0x2D) && ITEMSIsA(pItem2, 0x2D))
    {
        if (!pUnit)
        {
            return 0;
        }

        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            switch (MONSTERS_GetBaseIdFromMonsterId(pUnit->dwClassId))
            {
            case MONSTER_SHADOWWARRIOR:
            case MONSTER_SHADOWMASTER:
                return ITEMSIsA(pItem1, 0x43) && ITEMSIsA(pItem2, 0x43);

            case MONSTER_ANCIENTBARB1:
            case MONSTER_ANCIENTBARB2:
            case MONSTER_ANCIENTBARB3:
                return 1;

            default:
                return 0;
            }
        }

        if (pUnit->dwUnitType != UNIT_PLAYER)
        {
            return 0;
        }

        if (pUnit->dwClassId == 4)
        {
            return 1;
        }

        if (pUnit->dwClassId != 6 || !ITEMSIsA(pItem1, 0x43))
        {
            return 0;
        }

        if (!ITEMSIsA(pItem2, 0x43))
        {
            return 0;
        }
    }
    else
    {
        if (ITEMSIsA(pItem1, 0x2D))
        {
            return 1;
        }

        if (!ITEMSIsA(pItem2, 0x2D))
        {
            return 0;
        }
    }

    return 1;
}

// 0x0063DD90
static int __stdcall INVENTORY_CheckHandSlotPlacement(D2UnitStrc* pUnit, int nOtherLoc, D2UnitStrc* pNewItem, D2UnitStrc* pLocItem, D2UnitStrc* pOtherItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pNewItem)
    {
        if (pLocItem)
        {
            if (ITEMS_AreStackablesEqual(pLocItem, pNewItem))
            {
                return 6;
            }

            if (INVENTORY_CanItemsBeWieldedTogether(pUnit, pNewItem, pOtherItem))
            {
                return 5;
            }

            return INVENTORY_IsItemBodyLocFree(pInventory, pNewItem, nOtherLoc, UNITS_GetInventoryRecordId(pUnit, 0, 1)) ? 7 : 0;
        }

        if (pOtherItem)
        {
            return INVENTORY_CanItemsBeWieldedTogether(pUnit, pNewItem, pOtherItem) ? 1 : 2;
        }

        return 1;
    }

    if (pLocItem)
    {
        return 3;
    }

    if (pOtherItem && ITEMS_CheckWeaponIfTwoHanded(pOtherItem))
    {
        return 4;
    }

    return 0;
}

// 0x0063E050
void __stdcall sub_0063E050_Nop(int nUnused1, int nUnused2)
{
}

// 0x0063E490
void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int nBodyLoc)
{
    if (!INVENTORY_GetPtrIfValid(pInventory))
    {
        return;
    }

    const BOOL bDualWield = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;
    if (*ppItem || !INVENTORY_ValidateBodyLoc(nBodyLoc))
    {
        return;
    }

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, INVGRID_BODYLOC, &gBodyLocInventoryGridInfo);
    if (!pInventoryGrid)
    {
        return;
    }

    if (nBodyLoc == BODYLOC_RARM)
    {
        if (bDualWield)
        {
            *ppItem = pInventoryGrid->ppItems[BODYLOC_LARM];
        }
    }
    else if (nBodyLoc == BODYLOC_LARM)
    {
        if (bDualWield)
        {
            *ppItem = pInventoryGrid->ppItems[BODYLOC_RARM];
        }
    }
}

enum
{
    ANIMSEQ_EVENT_MELEE_ATTACK = 1,
    ANIMSEQ_EVENT_MISSILE_ATTACK = 2,
};

extern int gnMonStatsMissileOffsets[];                                                             // 0x006EA938

inline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            return &sgptDataTables->pMonStatsTxt[nClassId];
        }
    }
    return 0;
}

// 0x0063E6B0
int __stdcall D2Common_11050(D2UnitStrc* pUnit, int a2)
{
    if (a2)
    {
        if (!pUnit->nActionFrame)
        {
            return -1;
        }

        int nFrame;
        int nFrameCount;
        UNITS_GetFrameMetrics(pUnit, &nFrame, &nFrameCount);

        int nStart = nFrame - pUnit->wAnimSpeed;
        nFrame >>= 8;
        nStart >>= 8;

        if (nStart >= nFrame)
        {
            return -1;
        }

        int nCounter = nStart;
        while (nCounter <= nFrame)
        {
            if (UNITS_GetEventFrameInfo(pUnit, nCounter) == ANIMSEQ_EVENT_MISSILE_ATTACK || UNITS_GetEventFrameInfo(pUnit, nCounter) == ANIMSEQ_EVENT_MELEE_ATTACK)
            {
                break;
            }

            ++nCounter;
        }

        if (nCounter > nFrame)
        {
            return -1;
        }

        if (nCounter <= nStart)
        {
            return -1;
        }
    }

    const int nOffset = gnMonStatsMissileOffsets[UNITS_GetAnimModeInline(pUnit)];
    if (!nOffset)
    {
        return -1;
    }

    return *(short*)((char*)MONSTERS_GetMonStatsTxtRecordFromUnit(pUnit) + nOffset);
}

// 0x0063E780
unsigned char __stdcall D2Common_11052(unsigned char nIndex)
{
    return gabDirection64To16[nIndex];
}

// 0x0063E7A0
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex)
{
    return gabDirection64To8[nIndex];
}

// 0x0063E7C0
unsigned char __stdcall D2Common_11054(unsigned char nIndex)
{
    return gabDirection8To64[nIndex];
}

// 0x0063E7E0
void __stdcall INVENTORY_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY)
{
    *pX = gaDirectionDeltaX[nDirection];
    *pY = gaDirectionDeltaY[nDirection];
}

// 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return pItem;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    return nUnitType == UNIT_ITEM ? pItem : 0;
}

// 0x0063E000
int __stdcall INVENTORY_GetItemGUID(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    return pItem->dwUnitId;
}

// 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
    if (!pItemExtraData)
    {
        return 0;
    }

    return pItemExtraData->pNextItem;
}

// 0x0063DE60
int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    if (pItem)
    {
        if (!ITEMS_CheckBodyLocation(pItem, nBodyLoc))
        {
            return 0;
        }

        if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, pUnit, 1, 0, 0, 0))
        {
            return 0;
        }
    }

    switch (nBodyLoc)
    {
    case 0:
        return 0;

    case 4:
    case 5:
    {
        const int nOtherLoc = nBodyLoc != 5 ? 5 : 4;
        D2UnitStrc* pLocItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        D2UnitStrc* pOtherItem = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherLoc);
        return INVENTORY_CheckHandSlotPlacement(pUnit, nOtherLoc, pItem, pLocItem, pOtherItem);
    }

    case 11:
    case 12:
    {
        const int nOtherLoc = nBodyLoc != 12 ? 12 : 11;
        D2UnitStrc* pLocItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        D2UnitStrc* pOtherItem = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherLoc);
        return INVENTORY_CheckHandSlotPlacement(pUnit, nOtherLoc, pItem, pLocItem, pOtherItem);
    }

    default:
    {
        D2UnitStrc* pEquipped = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        if (pItem)
        {
            return pEquipped ? 5 : 1;
        }
        return pEquipped ? 3 : 0;
    }
    }
}

// 0x0063E020
int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return 0;
    }

    const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem);
    if (!pItemExtraData)
    {
        return 0;
    }

    return (char)pItemExtraData->nNodePosOther;
}

// 0x0063E060
int __stdcall sub_0063E060_AlwaysZero(int nUnused)
{
    return 0;
}

static __forceinline BOOL INVENTORY_TryPlaceInFreePosition(D2InventoryStrc* pInventory, D2InventoryGridStrc* pInventoryGrid, D2UnitStrc* pItem, int nInventoryRecordId, unsigned char* pHeight)
{
    int nX;
    int nY;
    unsigned char nWidth;
    if (pInventoryGrid && INVENTORY_GetFreePosition(pInventory, pItem, nInventoryRecordId, &nX, &nY, 0))
    {
        ITEMS_GetDimensions(pItem, &nWidth, pHeight, gszInventorySourceFile, 0x16D5);

        if (nWidth && *pHeight)
        {
            const int nPosX = nX;
            if (nPosX >= 0 && nPosX + nWidth <= pInventoryGrid->nGridWidth && nY >= 0 && nY + *pHeight <= pInventoryGrid->nGridHeight)
            {
                for (int y = nY; y < nY + *pHeight; ++y)
                {
                    for (int x = nPosX; x < nPosX + nWidth; ++x)
                    {
                        pInventoryGrid->ppItems[x + y * pInventoryGrid->nGridWidth] = (D2UnitStrc*)-1;
                    }
                }

                return TRUE;
            }
        }
    }

    return FALSE;
}

// 0x0063E070
D2UnitStrc* __stdcall INVENTORY_IsItemInInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    if (pInventory)
    {
        const int nUnitType = pItem ? pItem->dwUnitType : UNIT_INVALID;
        if (nUnitType == UNIT_ITEM)
        {
            if (D2ItemExtraDataStrc* pItemExtraData = INVENTORY_GetItemExtraDataFromItem(pItem))
            {
                return pInventory == pItemExtraData->pParentInv ? pItem : 0;
            }
        }
    }

    return 0;
}

// 0x0063E0B0
int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory)
{
    if (!pInventory)
    {
        return 0;
    }

    if (pInventory->dwSignature != INVENTORY_SIGNATURE)
    {
        return 0;
    }

    pInventory->pCursorItem = 0;
    pInventory->dwLeftItemGUID = D2UnitInvalidGUID;

    while (pInventory->pFirstItem)
    {
        if (!INVENTORY_RemoveItem(pInventory->pFirstItem))
        {
            return 0;
        }
    }

    return 1;
}

// 0x0063E100
static BOOL INVENTORY_CopyUnitItemsToTradeInventory(D2InventoryStrc* pTradeInventory, D2UnitStrc* pUnit)
{
    if (!pTradeInventory)
    {
        return FALSE;
    }

    if (pTradeInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, 0, 1);
    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pTradeInventoryGrid = INVENTORY_GetGrid(pTradeInventory, 2, &tInventoryGridInfo);
    if (pTradeInventoryGrid && INVENTORY_GetPtrIfValid(pUnit->pInventory))
    {
        D2InventoryGridStrc* pUnitInventoryGrid = INVENTORY_GetGrid(pUnit->pInventory, 2, &tInventoryGridInfo);
        if (pUnitInventoryGrid && pUnitInventoryGrid->nGridWidth > 0 && pUnitInventoryGrid->nGridHeight > 0
            && pUnitInventoryGrid->nGridWidth == pTradeInventoryGrid->nGridWidth && pUnitInventoryGrid->nGridHeight == pTradeInventoryGrid->nGridHeight
            && pUnitInventoryGrid->ppItems && pTradeInventoryGrid->ppItems)
        {
            memcpy(pTradeInventoryGrid->ppItems, pUnitInventoryGrid->ppItems, sizeof(D2UnitStrc*) * pUnitInventoryGrid->nGridWidth * pUnitInventoryGrid->nGridHeight);
            return 1;
        }
    }

    return FALSE;
}

inline BOOL INVENTORY_ValidateBodyLoc(int nBodyLoc)
{
    return nBodyLoc >= 0 && nBodyLoc < 13;
}

// 0x0063E1C0
static BOOL __stdcall INVENTORY_CanItemBePlacedInInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory)
{
    unsigned char nHeight;
    if (!pInventory)
    {
        return FALSE;
    }

    if (pInventory->dwSignature != 0x1020304)
    {
        return FALSE;
    }

    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pPlayer, 0, TRUE);
    D2InventoryGridInfoStrc tInventoryGridInfo;
    DATATBLS_GetInventoryGridInfo(nInventoryRecordId, 0, &tInventoryGridInfo);

    D2InventoryGridStrc* pInventoryGrid = INVENTORY_GetGrid(pInventory, 2, &tInventoryGridInfo);
    return INVENTORY_TryPlaceInFreePosition(pInventory, pInventoryGrid, pItem, nInventoryRecordId, &nHeight);
}

static inline s32 INVENTORY_CheckSignature_Inline(Inventory* inventory)
{
    return inventory && FIELD(u32, inventory, 0) == 0x01020304;
}

static inline ItemData* ITEMS_GetItemData_Inline(D2UnitStrc* item)
{
    return (item && FIELD(s32, item, 0) == 4 && FIELD(ItemData*, item, 0x14)) ? FIELD(ItemData*, item, 0x14) : 0;
}

static inline D2UnitStrc* INVENTORY_GetNextItem_Inline(D2UnitStrc* item)
{
    const s32 nUnitType = item ? FIELD(s32, item, 0) : 6;
    if (nUnitType != 4)
    {
        return 0;
    }
    ItemData* data = ITEMS_GetItemData_Inline(item);
    if (!data)
    {
        return 0;
    }
    ItemLink* link = (ItemLink*)((u8*)data + 0x5C);
    if (!link)
    {
        return 0;
    }
    return FIELD(D2UnitStrc*, link, 8);
}

// 0x0063E510
void __stdcall INVENTORY_GetItemSaveGfxInfo(D2UnitStrc* unit, u8* firstOutput, u8* secondOutput)
{
    Inventory* inventory = FIELD(Inventory*, unit, 0x60);
    if (INVENTORY_CheckSignature_Inline(inventory))
    {
        for (D2UnitStrc* item = FIELD(D2UnitStrc*, inventory, 0x0C); item; item = INVENTORY_GetNextItem_Inline(item))
        {
            if (FIELD(u32, item, 0) == 4 && FIELD(s32, item, 0x10) == 1)
            {
                ItemRecord* record = sub_006335F0_ItemRecord(!item ? -1 : FIELD(s32, item, 4));
                D2_ASSERT(record, 0x1446);
                const u8 page = ITEMS_GetBodyLocation(item);
                if (page != 1 && page != 4 && page != 5)
                {
                    if (page == 3)
                    {
                        AppearanceSix appearance;
                        INVENTORY_GetArmorComponents(item, &appearance);
                        for (u32 slot = 0; slot < 0x10; ++slot)
                        {
                            if (COMPOSIT_IsArmorComponent(slot))
                            {
                                AppearanceRecord* appearanceRecord = DATATBLS_GetArmTypeTxtRecord(COMPOSIT_GetArmorTypeFromComponent(slot, &appearance));
                                if (GAME_GetUnitClassId(item) > 0)
                                {
                                    const u32 appearanceCode = FIELD(u32, appearanceRecord, 0x20);
                                    const s32 code = INVENTORY_FindComponentArrayIndex(appearanceCode, appearanceCode);
                                    if (code)
                                    {
                                        if (slot < 0x10)
                                        {
                                            firstOutput[slot] = (u8)code;
                                            if (!ITEMS_GetColor(unit, item, &secondOutput[slot], 0))
                                            {
                                                secondOutput[slot] = 0xFF;
                                            }
                                            else
                                            {
                                                ++secondOutput[slot];
                                            }
                                        }
                                        continue;
                                    }
                                }
                                if (slot < 0x10)
                                {
                                    firstOutput[slot] = 0xFF;
                                    secondOutput[slot] = 0xFF;
                                }
                            }
                        }
                    }
                }
                else
                {
                    if (!ITEMS_CheckType(FIELD(short, record, 0x11E), ITEMTYPE_CIRCLET))
                    {
                        INVENTORY_FillItemComponentGfxInfo(unit, firstOutput, secondOutput, item);
                    }
                }
            }
        }
    }
}

// 0x0063E2E0
static BOOL __stdcall INVENTORY_CanItemBePlacedInTradeInventory(D2UnitStrc* pPlayer2, D2InventoryStrc* pTradeInventory, D2UnitStrc* pPlayer1)
{
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer1->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCurrentItem = INVENTORY_UnitIsItem(pItem);
        D2UnitStrc* pNextItem = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(pCurrentItem) == 2 && !INVENTORY_CanItemBePlacedInInventory(pPlayer2, pCurrentItem, pTradeInventory))
        {
            return FALSE;
        }

        pItem = pNextItem;
    }

    return 1;
}

// 0x0063E370
BOOL __stdcall INVENTORY_CanItemsBeTraded(D2PoolSystemStrc* pMemPool, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int* pTradeState)
{
    BOOL bResult = FALSE;
    D2InventoryStrc* pTradeInventory1 = INVENTORY_AllocInventory(pMemPool, 0);
    D2InventoryStrc* pTradeInventory2 = INVENTORY_AllocInventory(pMemPool, 0);

    if (pTradeInventory1 && pTradeInventory2 && INVENTORY_CopyUnitItemsToTradeInventory(pTradeInventory1, pPlayer1) && INVENTORY_CopyUnitItemsToTradeInventory(pTradeInventory2, pPlayer2))
    {
        if (!INVENTORY_CanItemBePlacedInTradeInventory(pPlayer2, pTradeInventory2, pPlayer1))
        {
            if (pTradeState)
            {
                *pTradeState = 0;
            }
        }
        else if (!INVENTORY_CanItemBePlacedInTradeInventory(pPlayer1, pTradeInventory1, pPlayer2))
        {
            if (pTradeState)
            {
                *pTradeState = 1;
            }
        }
        else
        {
            bResult = 1;
        }
    }

    INVENTORY_FreeInventory(pTradeInventory1);
    INVENTORY_FreeInventory(pTradeInventory2);
    return bResult;
}

#pragma pack(push, 1)
struct d2data_007455C0_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00745640_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007447CC_t
{
    unsigned char b0[1244];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00744760_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00745600_t
{
    unsigned char b0[64];
};
#pragma pack(pop)

extern "C" struct d2data_007455C0_t gData_007455C0; // 0x007455C0
extern "C" struct d2data_00745640_t gData_00745640; // 0x00745640
extern "C" struct d2data_007447CC_t gData_007447CC; // 0x007447CC
extern "C" struct d2data_00744760_t gData_00744760; // 0x00744760
extern "C" struct d2data_00745600_t gData_00745600; // 0x00745600

extern "C" const char gszInventorySourceFile[26] = ".\\INVENTORY\\Inventory.cpp"; // 0x006EA918

extern "C" struct d2data_007455C0_t gData_007455C0 = {
    {
        0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04,
        0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x08, 0x08,
        0x08, 0x08, 0x09, 0x09, 0x09, 0x09, 0x0A, 0x0A, 0x0A, 0x0A, 0x0B, 0x0B, 0x0B, 0x0B, 0x0C, 0x0C,
        0x0C, 0x0C, 0x0D, 0x0D, 0x0D, 0x0D, 0x0E, 0x0E, 0x0E, 0x0E, 0x0F, 0x0F, 0x0F, 0x0F
    }
}; // 0x007455C0
#pragma comment(linker, "/alternatename:?gabDirection64To16@@3PAEA=_gData_007455C0")

extern "C" struct d2data_00745640_t gData_00745640 = {
    { 0x04, 0x0C, 0x14, 0x1C, 0x24, 0x2C, 0x34, 0x3C }
}; // 0x00745640
#pragma comment(linker, "/alternatename:?gabDirection8To64@@3PAEA=_gData_00745640")

extern D2InventoryComponentItemTypeStrc gaComponentItemTypeMap[283] = {
    { 0, 1 },
    { 544500076, 1 },
    { 543450477, 1 },
    { 544831080, 1 },
    { 544235875, 37 },
    { 544238451, 37 },
    { 544042088, 37 },
    { 543975526, 37 },
    { 544041063, 37 },
    { 544109155, 37 },
    { 543912813, 37 },
    { 543518819, 3 },
    { 543911011, 3 },
    { 543321970, 3 },
    { 543782257, 3 },
    { 543253868, 3 },
    { 543255656, 3 },
    { 544568435, 3 },
    { 543649394, 3 },
    { 543974259, 3 },
    { 544106595, 3 },
    { 544436834, 3 },
    { 543977587, 3 },
    { 544500848, 3 },
    { 543452262, 3 },
    { 543716455, 3 },
    { 543978854, 3 },
    { 543389026, 2 },
    { 543650412, 2 },
    { 544500075, 2 },
    { 544698228, 2 },
    { 543975276, 16 },
    { 543975277, 16 },
    { 543975272, 16 },
    { 544498284, 15 },
    { 544498285, 15 },
    { 544498280, 15 },
    { 543973996, 19 },
    { 543973997, 19 },
    { 543973992, 19 },
    { 544041058, 37 },
    { 543716194, 2 },
    { 543912051, 2 },
    { 543452791, 25 },
    { 544110457, 25 },
    { 544110434, 25 },
    { 543321187, 29 },
    { 544760168, 43 },
    { 543454067, 30 },
    { 544039795, 30 },
    { 543383917, 36 },
    { 543520865, 28 },
    { 543386726, 30 },
    { 543454060, 30 },
    { 543255654, 36 },
    { 544040040, 31 },
    { 544041079, 31 },
    { 544436835, 30 },
    { 544435302, 30 },
    { 543977575, 38 },
    { 544436327, 38 },
    { 543977583, 38 },
    { 544436335, 38 },
    { 544368484, 32 },
    { 540226404, 32 },
    { 540226407, 32 },
    { 544368996, 32 },
    { 544629098, 33 },
    { 544631911, 33 },
    { 543975792, 33 },
    { 544042083, 30 },
    { 543454055, 30 },
    { 544370803, 33 },
    { 543781492, 33 },
    { 543910256, 33 },
    { 544370803, 33 },
    { 544694899, 27 },
    { 544694892, 27 },
    { 543318643, 27 },
    { 543318636, 27 },
    { 544502643, 26 },
    { 544502636, 26 },
    { 544502627, 26 },
    { 544502626, 26 },
    { 544760172, 28 },
    { 544826227, 34 },
    { 544762215, 28 },
    { 544765026, 28 },
    { 543973736, 34 },
    { 544563565, 31 },
    { 544760176, 34 },
    { 543973736, 34 },
    { 543324264, 35 },
    { 543324268, 35 },
    { 544760180, 43 },
    { 543387763, 29 },
    { 544367219, 30 },
    { 544502637, 36 },
    { 544236403, 24 },
    { 544043111, 38 },
    { 544043119, 38 },
    { 543583092, 42 },
    { 543452258, 32 },
    { 543454050, 30 },
    { 544699234, 30 },
    { 544434226, 30 },
    { 544109154, 33 },
    { 544694888, 27 },
    { 544694883, 27 },
    { 543324019, 27 },
    { 543324012, 27 },
    { 544502647, 26 },
    { 544760162, 28 },
    { 544366946, 34 },
    { 544760167, 28 },
    { 543324274, 35 },
    { 543324269, 35 },
    { 544498298, 1 },
    { 544366945, 3 },
    { 544240748, 3 },
    { 543976819, 2 },
    { 544437351, 3 },
    { 544633185, 40 },
    { 544633187, 40 },
    { 543974006, 19 },
    { 543974004, 19 },
    { 543975286, 16 },
    { 543975284, 16 },
    { 544498294, 15 },
    { 544498292, 15 },
    { 543321190, 30 },
    { 543780973, 28 },
    { 543973730, 43 },
    { 543647084, 29 },
    { 544500849, 3 },
    { 544760114, 28 },
    { 544760183, 28 },
    { 544110439, 36 },
    { 543255911, 36 },
    { 543454071, 30 },
    { 544434535, 30 },
    { 543452258, 32 },
    { 543583074, 32 },
    { 544240499, 33 },
    { 544240500, 33 },
    { 543518835, 33 },
    { 544567158, 34 },
    { 543388535, 34 },
    { 543781483, 32 },
    { 544501875, 33 },
    { 543388519, 24 },
    { 544240503, 24 },
    { 544502632, 26 },
    { 543585133, 26 },
    { 543712872, 36 },
    { 543254585, 28 },
    { 544760121, 28 },
    { 543240761, 28 },
    { 544238905, 28 },
    { 543258425, 28 },
    { 543255609, 28 },
    { 543253049, 28 },
    { 544498233, 28 },
    { 543254329, 28 },
    { 543778617, 28 },
    { 544110393, 25 },
    { 544700729, 25 },
    { 544694841, 25 },
    { 544696121, 25 },
    { 543974201, 36 },
    { 543388473, 24 },
    { 544436537, 24 },
    { 544438073, 24 },
    { 544240441, 36 },
    { 543255865, 36 },
    { 544501049, 36 },
    { 543974969, 36 },
    { 543717177, 36 },
    { 540634425, 36 },
    { 544040761, 36 },
    { 544437049, 30 },
    { 544043833, 30 },
    { 543322937, 30 },
    { 543385145, 30 },
    { 544367417, 30 },
    { 544432697, 30 },
    { 544435257, 30 },
    { 543455033, 30 },
    { 543699513, 30 },
    { 544039737, 30 },
    { 544433977, 30 },
    { 540631609, 30 },
    { 543319609, 30 },
    { 543450937, 30 },
    { 543646777, 32 },
    { 543777849, 32 },
    { 544369465, 32 },
    { 543973945, 32 },
    { 543913017, 42 },
    { 543257657, 43 },
    { 543908409, 42 },
    { 540566073, 43 },
    { 543255097, 33 },
    { 543780921, 33 },
    { 540635961, 33 },
    { 543975225, 33 },
    { 544437305, 33 },
    { 544371513, 33 },
    { 544371769, 33 },
    { 544367161, 33 },
    { 544502585, 33 },
    { 540635193, 33 },
    { 540500537, 34 },
    { 544175673, 34 },
    { 540570425, 34 },
    { 543256633, 34 },
    { 540633145, 34 },
    { 543389497, 34 },
    { 544437048, 26 },
    { 544435256, 26 },
    { 544432952, 26 },
    { 544432696, 26 },
    { 544438072, 26 },
    { 543322936, 27 },
    { 543320120, 27 },
    { 543321144, 27 },
    { 543318840, 27 },
    { 540570424, 27 },
    { 540568632, 27 },
    { 544699192, 27 },
    { 544697400, 27 },
    { 544762936, 35 },
    { 544763192, 35 },
    { 544761912, 35 },
    { 544764472, 35 },
    { 544235896, 37 },
    { 544238456, 37 },
    { 544042104, 37 },
    { 543975544, 37 },
    { 544041080, 37 },
    { 544109176, 37 },
    { 543912824, 37 },
    { 543782264, 3 },
    { 543253880, 3 },
    { 543255672, 3 },
    { 544568440, 3 },
    { 543649400, 3 },
    { 543974264, 3 },
    { 544106616, 3 },
    { 544436856, 3 },
    { 543977592, 3 },
    { 544500856, 3 },
    { 543452280, 3 },
    { 543716472, 3 },
    { 543978872, 3 },
    { 544366968, 3 },
    { 544240760, 3 },
    { 543389048, 2 },
    { 543976824, 2 },
    { 543650424, 2 },
    { 544500088, 2 },
    { 544698232, 2 },
    { 544437368, 2 },
    { 543648888, 16 },
    { 543651448, 16 },
    { 543649144, 16 },
    { 543650936, 16 },
    { 543647864, 16 },
    { 543321208, 15 },
    { 543323768, 15 },
    { 543321464, 15 },
    { 543323256, 15 },
    { 543320184, 15 },
    { 543321210, 19 },
    { 543323770, 19 },
    { 543321466, 19 },
    { 543323258, 19 },
    { 543320186, 19 },
    { 540633208, 37 },
    { 543716216, 2 },
    { 543912056, 2 },
    { 540108401, 36 },
    { 540173937, 36 }
}; // 0x00744CA8

extern D2InventoryGridInfoStrc gBeltInventoryGridInfo = { 0x10, 1 }; // 0x007447B4

extern "C" struct d2data_007447CC_t gData_007447CC = {
    {
        0x36, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6C, 0x69, 0x74, 0x20, 0x6D, 0x65, 0x64, 0x20,
        0x68, 0x76, 0x79, 0x20, 0x63, 0x61, 0x70, 0x20, 0x73, 0x6B, 0x70, 0x20, 0x68, 0x6C, 0x6D, 0x20,
        0x66, 0x68, 0x6C, 0x20, 0x67, 0x68, 0x6D, 0x20, 0x63, 0x72, 0x6E, 0x20, 0x6D, 0x73, 0x6B, 0x20,
        0x63, 0x70, 0x65, 0x20, 0x63, 0x6C, 0x6B, 0x20, 0x72, 0x6F, 0x62, 0x20, 0x71, 0x75, 0x69, 0x20,
        0x6C, 0x65, 0x61, 0x20, 0x68, 0x6C, 0x61, 0x20, 0x73, 0x74, 0x75, 0x20, 0x72, 0x6E, 0x67, 0x20,
        0x73, 0x63, 0x6C, 0x20, 0x63, 0x68, 0x6E, 0x20, 0x62, 0x72, 0x73, 0x20, 0x73, 0x70, 0x6C, 0x20,
        0x70, 0x6C, 0x74, 0x20, 0x66, 0x6C, 0x64, 0x20, 0x67, 0x74, 0x68, 0x20, 0x66, 0x75, 0x6C, 0x20,
        0x62, 0x75, 0x63, 0x20, 0x6C, 0x72, 0x67, 0x20, 0x6B, 0x69, 0x74, 0x20, 0x74, 0x6F, 0x77, 0x20,
        0x6C, 0x67, 0x6C, 0x20, 0x6D, 0x67, 0x6C, 0x20, 0x68, 0x67, 0x6C, 0x20, 0x6C, 0x62, 0x74, 0x20,
        0x6D, 0x62, 0x74, 0x20, 0x68, 0x62, 0x74, 0x20, 0x6C, 0x62, 0x6C, 0x20, 0x6D, 0x62, 0x6C, 0x20,
        0x68, 0x62, 0x6C, 0x20, 0x62, 0x68, 0x6D, 0x20, 0x62, 0x73, 0x68, 0x20, 0x73, 0x70, 0x6B, 0x20,
        0x6F, 0x62, 0x31, 0x20, 0x6F, 0x62, 0x32, 0x20, 0x6F, 0x62, 0x33, 0x20, 0x6F, 0x62, 0x34, 0x20,
        0x6F, 0x62, 0x35, 0x20, 0x6E, 0x65, 0x31, 0x20, 0x6E, 0x65, 0x32, 0x20, 0x6E, 0x65, 0x33, 0x20,
        0x6E, 0x65, 0x34, 0x20, 0x6E, 0x65, 0x35, 0x20, 0x64, 0x72, 0x31, 0x20, 0x64, 0x72, 0x32, 0x20,
        0x64, 0x72, 0x33, 0x20, 0x64, 0x72, 0x34, 0x20, 0x64, 0x72, 0x35, 0x20, 0x77, 0x6E, 0x64, 0x20,
        0x79, 0x77, 0x6E, 0x20, 0x62, 0x77, 0x6E, 0x20, 0x63, 0x6C, 0x62, 0x20, 0x68, 0x61, 0x78, 0x20,
        0x73, 0x73, 0x64, 0x20, 0x73, 0x63, 0x6D, 0x20, 0x6D, 0x61, 0x63, 0x20, 0x61, 0x78, 0x65, 0x20,
        0x66, 0x6C, 0x63, 0x20, 0x6C, 0x73, 0x64, 0x20, 0x66, 0x6C, 0x61, 0x20, 0x68, 0x64, 0x6D, 0x20,
        0x77, 0x68, 0x6D, 0x20, 0x63, 0x72, 0x73, 0x20, 0x66, 0x6C, 0x73, 0x20, 0x67, 0x70, 0x6C, 0x20,
        0x67, 0x70, 0x73, 0x20, 0x6F, 0x70, 0x6C, 0x20, 0x6F, 0x70, 0x73, 0x20, 0x64, 0x67, 0x72, 0x20,
        0x64, 0x33, 0x33, 0x20, 0x67, 0x33, 0x33, 0x20, 0x64, 0x69, 0x72, 0x20, 0x6A, 0x61, 0x76, 0x20,
        0x67, 0x6C, 0x76, 0x20, 0x70, 0x69, 0x6C, 0x20, 0x63, 0x6C, 0x6D, 0x20, 0x67, 0x73, 0x64, 0x20,
        0x73, 0x70, 0x72, 0x20, 0x74, 0x72, 0x69, 0x20, 0x70, 0x69, 0x6B, 0x20, 0x73, 0x70, 0x72, 0x20,
        0x73, 0x62, 0x77, 0x20, 0x6C, 0x62, 0x77, 0x20, 0x73, 0x62, 0x62, 0x20, 0x6C, 0x62, 0x62, 0x20,
        0x73, 0x73, 0x74, 0x20, 0x6C, 0x73, 0x74, 0x20, 0x63, 0x73, 0x74, 0x20, 0x62, 0x73, 0x74, 0x20,
        0x6C, 0x61, 0x78, 0x20, 0x73, 0x63, 0x79, 0x20, 0x67, 0x69, 0x78, 0x20, 0x62, 0x74, 0x78, 0x20,
        0x68, 0x61, 0x6C, 0x20, 0x6D, 0x61, 0x75, 0x20, 0x70, 0x61, 0x78, 0x20, 0x68, 0x61, 0x6C, 0x20,
        0x68, 0x78, 0x62, 0x20, 0x6C, 0x78, 0x62, 0x20, 0x74, 0x61, 0x78, 0x20, 0x73, 0x70, 0x63, 0x20,
        0x73, 0x62, 0x72, 0x20, 0x6D, 0x73, 0x74, 0x20, 0x73, 0x63, 0x70, 0x20, 0x67, 0x70, 0x6D, 0x20,
        0x6F, 0x70, 0x6D, 0x20, 0x74, 0x6B, 0x66, 0x20, 0x62, 0x6C, 0x64, 0x20, 0x62, 0x73, 0x64, 0x20,
        0x62, 0x73, 0x77, 0x20, 0x32, 0x68, 0x73, 0x20, 0x62, 0x72, 0x6E, 0x20, 0x68, 0x62, 0x77, 0x20,
        0x63, 0x62, 0x77, 0x20, 0x73, 0x77, 0x62, 0x20, 0x6C, 0x77, 0x62, 0x20, 0x77, 0x73, 0x74, 0x20,
        0x62, 0x61, 0x78, 0x20, 0x62, 0x61, 0x72, 0x20, 0x67, 0x61, 0x78, 0x20, 0x72, 0x78, 0x62, 0x20,
        0x6D, 0x78, 0x62, 0x20, 0x7A, 0x62, 0x74, 0x20, 0x61, 0x61, 0x72, 0x20, 0x6C, 0x74, 0x70, 0x20,
        0x73, 0x6D, 0x6C, 0x20, 0x67, 0x74, 0x73, 0x20, 0x61, 0x71, 0x76, 0x20, 0x63, 0x71, 0x76, 0x20,
        0x76, 0x62, 0x6C, 0x20, 0x74, 0x62, 0x6C, 0x20, 0x76, 0x67, 0x6C, 0x20, 0x74, 0x67, 0x6C, 0x20,
        0x76, 0x62, 0x74, 0x20, 0x74, 0x62, 0x74, 0x20, 0x66, 0x6C, 0x62, 0x20, 0x6D, 0x70, 0x69, 0x20,
        0x62, 0x61, 0x6C, 0x20, 0x6C, 0x65, 0x67, 0x20, 0x71, 0x6C, 0x74, 0x20, 0x32, 0x61, 0x78, 0x20,
        0x77, 0x61, 0x78, 0x20, 0x67, 0x77, 0x6E, 0x20, 0x67, 0x6D, 0x61, 0x20, 0x77, 0x73, 0x64, 0x20,
        0x67, 0x69, 0x73, 0x20, 0x62, 0x6C, 0x64, 0x20, 0x62, 0x6B, 0x66, 0x20, 0x73, 0x73, 0x70, 0x20,
        0x74, 0x73, 0x70, 0x20, 0x73, 0x70, 0x65, 0x20, 0x76, 0x6F, 0x75, 0x20, 0x77, 0x73, 0x63, 0x20,
        0x6B, 0x72, 0x69, 0x20, 0x73, 0x70, 0x74, 0x20, 0x67, 0x73, 0x63, 0x20, 0x77, 0x73, 0x70, 0x20,
        0x68, 0x73, 0x74, 0x20, 0x6D, 0x73, 0x66, 0x20, 0x68, 0x66, 0x68, 0x20, 0x39, 0x68, 0x61, 0x20,
        0x39, 0x61, 0x78, 0x20, 0x39, 0x32, 0x61, 0x20, 0x39, 0x6D, 0x70, 0x20, 0x39, 0x77, 0x61, 0x20,
        0x39, 0x6C, 0x61, 0x20, 0x39, 0x62, 0x61, 0x20, 0x39, 0x62, 0x74, 0x20, 0x39, 0x67, 0x61, 0x20,
        0x39, 0x67, 0x69, 0x20, 0x39, 0x77, 0x6E, 0x20, 0x39, 0x79, 0x77, 0x20, 0x39, 0x62, 0x77, 0x20,
        0x39, 0x67, 0x77, 0x20, 0x39, 0x63, 0x6C, 0x20, 0x39, 0x73, 0x63, 0x20, 0x39, 0x71, 0x73, 0x20,
        0x39, 0x77, 0x73, 0x20, 0x39, 0x73, 0x70, 0x20, 0x39, 0x6D, 0x61, 0x20, 0x39, 0x6D, 0x74, 0x20,
        0x39, 0x66, 0x6C, 0x20, 0x39, 0x77, 0x68, 0x20, 0x39, 0x6D, 0x39, 0x20, 0x39, 0x67, 0x6D, 0x20,
        0x39, 0x73, 0x73, 0x20, 0x39, 0x73, 0x6D, 0x20, 0x39, 0x73, 0x62, 0x20, 0x39, 0x66, 0x63, 0x20,
        0x39, 0x63, 0x72, 0x20, 0x39, 0x62, 0x73, 0x20, 0x39, 0x6C, 0x73, 0x20, 0x39, 0x77, 0x64, 0x20,
        0x39, 0x32, 0x68, 0x20, 0x39, 0x63, 0x6D, 0x20, 0x39, 0x67, 0x73, 0x20, 0x39, 0x62, 0x39, 0x20,
        0x39, 0x66, 0x62, 0x20, 0x39, 0x67, 0x64, 0x20, 0x39, 0x64, 0x67, 0x20, 0x39, 0x64, 0x69, 0x20,
        0x39, 0x6B, 0x72, 0x20, 0x39, 0x62, 0x6C, 0x20, 0x39, 0x74, 0x6B, 0x20, 0x39, 0x74, 0x61, 0x20,
        0x39, 0x62, 0x6B, 0x20, 0x39, 0x62, 0x38, 0x20, 0x39, 0x6A, 0x61, 0x20, 0x39, 0x70, 0x69, 0x20,
        0x39, 0x73, 0x39, 0x20, 0x39, 0x67, 0x6C, 0x20, 0x39, 0x74, 0x73, 0x20, 0x39, 0x73, 0x72, 0x20,
        0x39, 0x74, 0x72, 0x20, 0x39, 0x62, 0x72, 0x20, 0x39, 0x73, 0x74, 0x20, 0x39, 0x70, 0x39, 0x20,
        0x39, 0x62, 0x37, 0x20, 0x39, 0x76, 0x6F, 0x20, 0x39, 0x73, 0x38, 0x20, 0x39, 0x70, 0x61, 0x20,
        0x39, 0x68, 0x39, 0x20, 0x39, 0x77, 0x63, 0x20, 0x38, 0x73, 0x73, 0x20, 0x38, 0x6C, 0x73, 0x20,
        0x38, 0x63, 0x73, 0x20, 0x38, 0x62, 0x73, 0x20, 0x38, 0x77, 0x73, 0x20, 0x38, 0x73, 0x62, 0x20,
        0x38, 0x68, 0x62, 0x20, 0x38, 0x6C, 0x62, 0x20, 0x38, 0x63, 0x62, 0x20, 0x38, 0x73, 0x38, 0x20,
        0x38, 0x6C, 0x38, 0x20, 0x38, 0x73, 0x77, 0x20, 0x38, 0x6C, 0x77, 0x20, 0x38, 0x6C, 0x78, 0x20,
        0x38, 0x6D, 0x78, 0x20, 0x38, 0x68, 0x78, 0x20, 0x38, 0x72, 0x78, 0x20, 0x6B, 0x74, 0x72, 0x20,
        0x61, 0x78, 0x66, 0x20, 0x63, 0x6C, 0x77, 0x20, 0x73, 0x6B, 0x72, 0x20, 0x39, 0x61, 0x72, 0x20,
        0x39, 0x78, 0x66, 0x20, 0x39, 0x6C, 0x77, 0x20, 0x39, 0x71, 0x72, 0x20, 0x78, 0x61, 0x70, 0x20,
        0x78, 0x6B, 0x70, 0x20, 0x78, 0x6C, 0x6D, 0x20, 0x78, 0x68, 0x6C, 0x20, 0x78, 0x68, 0x6D, 0x20,
        0x78, 0x72, 0x6E, 0x20, 0x78, 0x73, 0x6B, 0x20, 0x78, 0x75, 0x69, 0x20, 0x78, 0x65, 0x61, 0x20,
        0x78, 0x6C, 0x61, 0x20, 0x78, 0x74, 0x75, 0x20, 0x78, 0x6E, 0x67, 0x20, 0x78, 0x63, 0x6C, 0x20,
        0x78, 0x68, 0x6E, 0x20, 0x78, 0x72, 0x73, 0x20, 0x78, 0x70, 0x6C, 0x20, 0x78, 0x6C, 0x74, 0x20,
        0x78, 0x6C, 0x64, 0x20, 0x78, 0x74, 0x68, 0x20, 0x78, 0x75, 0x6C, 0x20, 0x78, 0x61, 0x72, 0x20,
        0x78, 0x74, 0x70, 0x20, 0x78, 0x75, 0x63, 0x20, 0x78, 0x6D, 0x6C, 0x20, 0x78, 0x72, 0x67, 0x20,
        0x78, 0x69, 0x74, 0x20, 0x78, 0x6F, 0x77, 0x20, 0x78, 0x74, 0x73, 0x20, 0x78, 0x6C, 0x67, 0x20,
        0x78, 0x76, 0x67, 0x20, 0x78, 0x6D, 0x67, 0x20, 0x78, 0x74, 0x67, 0x20, 0x78, 0x68, 0x67, 0x20,
        0x78, 0x6C, 0x62, 0x20, 0x78, 0x76, 0x62, 0x20, 0x78, 0x6D, 0x62, 0x20, 0x78, 0x74, 0x62, 0x20,
        0x78, 0x68, 0x62, 0x20, 0x7A, 0x6C, 0x62, 0x20, 0x7A, 0x76, 0x62, 0x20, 0x7A, 0x6D, 0x62, 0x20,
        0x7A, 0x74, 0x62, 0x20, 0x7A, 0x68, 0x62, 0x20, 0x78, 0x68, 0x39, 0x20, 0x78, 0x73, 0x68, 0x20,
        0x78, 0x70, 0x6B, 0x20, 0x71, 0x66, 0x31, 0x20, 0x71, 0x66, 0x32, 0x20, 0x63, 0x69, 0x30, 0x20,
        0x63, 0x69, 0x31, 0x20, 0x63, 0x69, 0x32, 0x20, 0x63, 0x69, 0x33, 0x20
    }
}; // 0x007447CC

extern const signed char gaDirectionDeltaY[32] = {
    -1, -1, 0, 1, 1, 1, 0, -1, -2, -2, -2, -1, 0, 1, 2, 2,
    2, 2, 2, 1, 0, -1, -2, -2, -3, -3, 0, 3, 3, 3, 0, -3
}; // 0x006EA978

extern const signed char gaDirectionDeltaX[32] = {
    0, -1, -1, -1, 0, 1, 1, 1, 0, -1, -2, -2, -2, -2, -2, -1,
    0, 1, 2, 2, 2, 2, 2, 1, 0, -3, -3, -3, 0, 3, 3, 3
}; // 0x006EA998

extern "C" struct d2data_00744760_t gData_00744760 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00744760

extern "C" struct d2data_00745600_t gData_00745600 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x02, 0x02, 0x02, 0x02,
        0x02, 0x02, 0x02, 0x02, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x03, 0x04, 0x04, 0x04, 0x04,
        0x04, 0x04, 0x04, 0x04, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x05, 0x06, 0x06, 0x06, 0x06,
        0x06, 0x06, 0x06, 0x06, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07, 0x07
    }
}; // 0x00745600
#pragma comment(linker, "/alternatename:?gabDirection64To8@@3PAEA=_gData_00745600")

extern D2InventoryGridInfoStrc gBodyLocInventoryGridInfo = { 0xD, 1 }; // 0x0074479C
