#include "D2Structs.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2Txt.h"
#include "D2ClientUiRecords.h"
struct D2UnitStrc;
struct D2InventoryStrc;
struct D2BitBufferStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int vKey);

int __cdecl GAME_IsExpansion(); // 0x0044DCC0
unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0
D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0
void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070
D2UnitStrc* __cdecl CURSOR_GetCursorItem(); // 0x004680A0
int __cdecl sub_00468830(); // 0x00468830
void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0
void __fastcall MSG_SendFourDwords(char nCommand, int nArg0, int nArg1, int nArg2, int nArg3); // 0x00478700
int __cdecl INV_CheckTradeClickDelay(); // 0x00486D10
void __cdecl SPELLSEL_UpdateSkillIcons(); // 0x004A9DF0
int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230
D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0
int __fastcall NPCMENU_HandleTradeClick(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x004B3870
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60
void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pItem); // 0x004C21F0
int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pItem); // 0x004C2240
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0
void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0
int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0
unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250
void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0
int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900
int __stdcall ITEMS_GetSockets(D2UnitStrc* hItem); // 0x006299B0
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc* pItem); // 0x0062A130
unsigned int __stdcall ITEMS_CheckIfBeltable(D2UnitStrc* pItem); // 0x0062BAD0
unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20
int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0
int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850
int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nVendorId, int nTransactionType); // 0x0062FDC0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
int __stdcall INVENTORY_GetFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int* pFreeX, int* pFreeY, unsigned char nPage); // 0x0063B850
int __stdcall INVENTORY_CanItemBePlaced(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppExchangeItem, unsigned int* pCount, unsigned char nPage); // 0x0063B9D0
int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20
D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10
D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0
int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

extern "C" const char gszCmnItemsH[]; // 0x006D9B90
extern "C" const char gszInvCpp[]; // 0x006D9BC0

extern int gnHoverCellX; // 0x00721E4C
extern int gnHoverCellY; // 0x00721E50
extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88
static int gbNpcTradeClicked; // 0x007BCBEC
static int gnInvPanelMode; // 0x007BCBF0
static unsigned char gnSelectedTab; // 0x007BCC04

static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0
static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid); // 0x00486BD0
int __cdecl INV_IsTradeStateInteractive(); // 0x00486B30
static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable); // 0x004843E0
static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid);

// 0x004843E0
static int INV_CanSocketInto(D2UnitStrc* pItem, D2UnitStrc* pSocketable)
{
    if (!pSocketable || !pItem)
    {
        return 0;
    }
    if (gnInvPanelMode == 0xA || gnInvPanelMode == 0xB)
    {
        return 0;
    }
    if (!ITEMS_IsSocketFiller(pSocketable))
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, gszInvCpp))
    {
        return 0;
    }
    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return 0;
    }
    if (ITEMS_GetMaxSockets(pItem) <= 0)
    {
        return 0;
    }
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, gszInvCpp))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, gszInvCpp))
    {
        return 0;
    }
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        return 0;
    }
    return INVENTORY_GetItemCount(pInventory) < ITEMS_GetSockets(pItem);
}

// 0x00486B30
int __cdecl INV_IsTradeStateInteractive()
{
    switch (gnInvPanelMode)
    {
    case 0:
    case 1:
    case 2:
    case 0xB:
    case 0xC:
    case 0xE:
    case 0x13:
        return 1;
    case 3:
    case 4:
    case 5:
        return 0;
    }
    return 0;
}

static void __stdcall sub_00486BD0_GetItemCell(unsigned int nX, unsigned int nY, int* pOutX, int* pOutY, D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid)
{
    D2_ASSERT(pItem, 0x14E8);
    int nCellX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nCellY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    unsigned char nWidth;
    unsigned char nHeight;
    unsigned int nPixelWidth;
    unsigned int nPixelHeight;
    ITEMS_GetDimensions(pItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
    sub_004DBEA0(pItem, 0, 0, &nPixelWidth, &nPixelHeight);
    if (nWidth % 2 == 0)
    {
        nCellX = ((nPixelWidth >> 2) - pGrid->nGridLeft + nX) / pGrid->nGridBoxWidth;
    }
    if (nWidth == pGrid->nGridX)
    {
        nCellX = pGrid->nGridX / 2;
    }
    if (nHeight % 2 == 0)
    {
        nCellY = ((nPixelHeight >> 2) - pGrid->nGridTop + nY) / pGrid->nGridBoxHeight;
    }
    if (nHeight == pGrid->nGridY)
    {
        nCellY = pGrid->nGridY / 2;
    }
    *pOutX = nCellX;
    *pOutY = nCellY;
    if (nWidth > 1)
    {
        const int n = *pOutX - nWidth / 2;
        *pOutX = n < 0 ? 0 : n;
    }
    if (nHeight > 1)
    {
        const int n = *pOutY - nHeight / 2;
        *pOutY = n < 0 ? 0 : n;
    }
}

// 0x00487BA0
static void __stdcall INV_ForwardTradeClick(int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7)
{
    if (!nArg2)
        return;
    if (!NPCMENU_HandleTradeClick(nArg1, nArg2, nArg3, nArg4, nArg5, nArg6, nArg7, 0))
        return;
    if (!nArg7)
        gnInvPanelMode = 5;
    CURSOR_SetCursorItemState(0);
}

// 0x0048FFE0
static int __stdcall INV_ClickInvGrid(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, int nFlags, D2InventoryGridInfoStrc* pGrid, unsigned char nPage)
{
    int nResult = 0;
    if (nPage == 0xFF)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, nPage, GAME_IsExpansion());
    int nGridX = (nX - pGrid->nGridLeft) / pGrid->nGridBoxWidth;
    int nGridY = (nY - pGrid->nGridTop) / pGrid->nGridBoxHeight;
    int nOutX;
    int nOutY;

    if (sub_00468830() == 6)
    {
        D2UnitStrc* pCursor = CURSOR_GetCursorItem();
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pCursor && pHit)
        {
            nResult = 1;
            if (!ITEM_IsItemActionBlocked(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && INV_CheckTradeClickDelay())
                {
                    MSG_SendTwoDwords(0x27, !pHit ? -1 : pHit->dwUnitId, !pCursor ? -1 : pCursor->dwUnitId);
                    ITEM_SetUninterruptableState(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (sub_00468830() == 8)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            nResult = 1;
            if (!ITEM_IsItemActionBlocked(pHit))
            {
                if (pUnit == sub_00463DD0_GetPlayerUnit() && nPage != 1 && nPage != 2 && INV_CheckTradeClickDelay())
                {
                    MSG_SendDword(0x4C, pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pHit);
                }
                else
                {
                    nResult = 0;
                }
            }
        }
    }
    else if (!pCursorItem)
    {
        D2UnitStrc* pHit = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
        if (pHit)
        {
            const int bIsPlayer = pUnit == sub_00463DD0_GetPlayerUnit();
            if (INV_IsTradeStateInteractive() && bIsPlayer == 1)
            {
                if (!ITEM_IsItemActionBlocked(pHit) && INV_CheckTradeClickDelay())
                {
                    if (GetAsyncKeyState(0x11) & 0x8000)
                    {
                        int nNpcId;
                        if (NPCMENU_GetInteractNpcId(&nNpcId))
                        {
                            D2UnitStrc* pNpc = CUNIT_FindClientUnit(nNpcId, 1);
                            if (pNpc)
                            {
                                if (ITEMS_IsNotQuestItem(pHit))
                                {
                                    const int nCost = ITEMS_GetTransactionCost(sub_00463DE0_GetPlayerUnit(), pHit, GAME_GetDifficulty(), MONSTER_GetQuestFlags(), !pNpc ? -1 : pNpc->dwClassId, 1);
                                    MSG_SendFourDwords(0x33, !pNpc ? -1 : pNpc->dwUnitId, !pHit ? -1 : pHit->dwUnitId, !pHit ? -1 : pHit->dwAnimMode, nCost);
                                }
                                else
                                {
                                    UNITSND_PlayPlayerSpeech(pUnit, 0x13);
                                }
                            }
                        }
                    }
                    else if ((nFlags & 4) && ITEMS_CheckIfBeltable(pHit) && !ITEMS_GetInvPage(pHit))
                    {
                        MSG_SendDword(0x63, pHit->dwUnitId);
                        sub_004B9A00(0xEB, 0, 0, 0, 0);
                    }
                    else
                    {
                        MSG_SendDword(0x19, pHit->dwUnitId);
                        gbNpcTradeClicked = 1;
                    }
                    nResult = 1;
                    ITEM_SetUninterruptableState(pHit);
                }
            }
            else if (gnInvPanelMode < 0x13)
            {
                INV_ForwardTradeClick((int)pUnit, (int)pHit, bIsPlayer, nX, nY, 0, 0);
            }
        }
    }
    else
    {
        D2UnitStrc* pHit;
        unsigned int nCount;
        INVENTORY_CanItemBePlaced(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pHit, &nCount, nPage);
        D2UnitStrc* pOther = 0;
        int bPlace = 1;
        if (nCount > 1)
        {
            D2UnitStrc* pBox = 0;
            INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pBox, nPage, 1);
            if (pBox && DATATBLS_GetItemsTxtRecord((!pBox ? -1 : pBox->dwClassId))->dwCode == 0x20786F62)
            {
                pHit = pBox;
                goto LBL_CUBE;
            }
        }

        if (pHit && nCount == 1)
        {
            if (ITEMS_AreStackablesEqual(pCursorItem, pHit))
            {
                if (!ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != 0xB && nPage != 2)
                {
                    MSG_SendTwoDwords(0x21, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
            }
            else if (gnHoverCellX >= 0 && gnHoverCellY >= 0)
            {
                if (INV_CanSocketInto(pHit, pCursorItem) && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
                {
                    MSG_SendTwoDwords(0x28, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (ITEMSIsA(pCursorItem, 0x16) && ITEMSIsA(pHit, 0x12)
                    && ITEMS_GetSuffixId(pCursorItem, 0) == ITEMS_GetSuffixId(pHit, 0)
                    && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && gnInvPanelMode != 0xB)
                {
                    SPELLSEL_UpdateSkillIcons();
                    MSG_SendTwoDwords(0x29, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                    bPlace = 0;
                    nResult = 1;
                }

                if (DATATBLS_GetItemsTxtRecord(!pHit ? -1 : pHit->dwClassId)->dwCode == 0x20786F62)
                {
LBL_CUBE:
                    if (!ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
                    {
                        int nFreeX;
                        int nFreeY;
                        const int nCubeRecord = UNITS_GetInventoryRecordId(pUnit, 3, GAME_IsExpansion());
                        if (INVENTORY_GetFreePosition(pInventory, pCursorItem, nCubeRecord, &nFreeX, &nFreeY, 3))
                        {
                            MSG_SendTwoDwords(0x2A, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pHit ? -1 : pHit->dwUnitId);
                            ITEM_SetUninterruptableState(pCursorItem);
                            sub_004B9A00(ITEM_GetDropSound(pHit), 0, 0, 0, 0);
                            nResult = 1;
                        }
                        else
                        {
                            UNITSND_PlayPlayerSpeech(pUnit, 0x13);
                        }
                        goto LBL_DONE;
                    }
                }

                if (bPlace && INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 0)
                    && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay() && nPage != 2)
                {
                    MSG_SendFourDwords(0x1F, (!pCursorItem ? -1 : pCursorItem->dwUnitId), !pOther ? -1 : pOther->dwUnitId, gnHoverCellX, gnHoverCellY);
                    ITEM_SetUninterruptableState(pCursorItem);
                    sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                    nResult = 1;
                }
LBL_DONE:
                ;
            }
        }
        else
        {
            if (nPage == 3)
            {
                D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord((!pCursorItem ? -1 : pCursorItem->dwClassId));
                D2_ASSERT(pTxt, 0x163A);
                if (pTxt->dwCode == 0x20786F62)
                {
                    return 1;
                }
            }

            int nCellX;
            int nCellY;
            sub_00486BD0_GetItemCell(nX, nY, &nCellX, &nCellY, pCursorItem, pGrid);
            D2UnitStrc* pExchange;
            unsigned int nExchangeCount;
            if (INVENTORY_CanItemBePlaced(pInventory, pCursorItem, nCellX, nCellY, nRecord, &pExchange, &nExchangeCount, nPage)
                && !ITEM_IsItemActionBlocked(pCursorItem) && INV_CheckTradeClickDelay())
            {
                MSG_SendFourDwords(0x18, (!pCursorItem ? -1 : pCursorItem->dwUnitId), nCellX, nCellY, nPage);
                ITEM_SetUninterruptableState(pCursorItem);
                sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
                nResult = 1;
            }
        }
    }
    return nResult;
}

extern D2InvRectStrc gtPlayerInvRect; // 0x007BCAA0
extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58
extern D2InventoryGridInfoStrc gtTradePage2Grid; // 0x007BCA30
extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78
extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40
extern D2InventoryGridInfoStrc gtCubeGrid; // 0x007BCB70
extern int gnScreenWidth; // 0x0071146C
extern int gnScreenHeight; // 0x00711470
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
static int gbHoverInGrid; // 0x007BCBE4
static int gbHoverInBodyLoc; // 0x007BCBE8
static D2UnitStrc* gpHoverItem; // 0x007BCBF4
static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8
static int gbInvGoldButtonDown; // 0x007BCE30
static int gbPanelButtonDown; // 0x007BCE90
int __cdecl GAME_IsExitPending(); // 0x0044DA30
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
void __cdecl INV_LoadUiRecords(); // 0x004835B0
int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl sub_0045AE90(); // 0x0045AE90
void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS*); // 0x00498DC0
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0
void __cdecl sub_0048A730_SwapWeapons(); // 0x0048A730
extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0
typedef int (__fastcall *D2BodyClickFn)(D2UnitStrc*,D2InventoryStrc*,int);
extern D2BodyClickFn gaBodyClick[]; // 0x00721E58

int __fastcall INV_IsInPlayerInvRect(int nX, int nY); // 0x00483AB0
int __fastcall INV_IsInPlayerInvRect(int nX, int nY); // 0x00483AB0
// 0x00483AB0
int __fastcall INV_IsInPlayerInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverWeaponSwapTab(int nX, int nY); // 0x00486860
static int INV_IsOverWeaponSwapTab(int nX, int nY); // 0x00486860
// 0x00486860
static int INV_IsOverWeaponSwapTab(int nX, int nY)
{
    if (nX >= gaCompGrids[5].rect.nLeft && nX <= gaCompGrids[5].rect.nRight && nY >= gaCompGrids[5].rect.nTop - 0x18 && nY < gaCompGrids[5].rect.nTop)
    {
        return 1;
    }
    if (nX >= gaCompGrids[4].rect.nLeft && nX <= gaCompGrids[4].rect.nRight && nY >= gaCompGrids[4].rect.nTop - 0x18 && nY < gaCompGrids[4].rect.nTop)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0
static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0
// 0x00486DA0
static int INV_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
    {
        return 0;
    }
    if (nY >= gnScreenHeight + gnPanelOffsetY - 0x57 && nY <= gnScreenHeight + gnPanelOffsetY - 0x45
        && nX >= gnScreenWidth - gnPanelOffsetX - 0xED && nX <= gnScreenWidth - gnPanelOffsetX - 0xD9)
    {
        return 1;
    }
    return 0;
}

__declspec(noinline) int __fastcall INV_IsInNpcPanelRect(int nX, int nY);
int __fastcall INV_IsInNpcPanelRect(int nX, int nY); // 0x00486E10
// 0x00486E10
int __fastcall INV_IsInNpcPanelRect(int nX, int nY)
{
    if (nX < gnScreenWidth - gnPanelOffsetX - 0x12E || nX > gnScreenWidth - gnPanelOffsetX - 0x10E)
    {
        return 0;
    }
    if (nY < gnScreenHeight + gnPanelOffsetY - 0x60 || nY > gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 0;
    }
    return 1;
}

static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX); // 0x00486E60
static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX); // 0x00486E60
// 0x00486E60
static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX)
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        return;
    }
    if (nY > gnScreenHeight - 0x30)
    {
        return;
    }
    if (sub_0045AE90() == 1 && nX < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468830() == 6)
    {
        UI_CancelCursorItemUse();
    }
    if (sub_0045AE90() == 3 && gnInvPanelMode == 0 && nX < gnScreenWidth / 2)
    {
        return;
    }
    pMsg->bReturn = 1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004912A0
void __stdcall INV_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if(GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing()) {
        pMsg->bReturn=0;
        return;
    }
    const int y=pMsg->nYpos;
    const int x=pMsg->nXpos;
    if(x>gnScreenWidth) {
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* inventory=player->pInventory;
    int handled=0;
    if(!HIREABLES_AreBeltRowsShown()) {
        if(INV_IsOverGoldButton(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==11 || gnInvPanelMode==12 || gnInvPanelMode==15)) {
            gbInvGoldButtonDown=1;
            sub_004B9A00(4,0,0,0,0);
        }
        if(INV_IsInNpcPanelRect(x,y) && (gnInvPanelMode==0 || gnInvPanelMode==19)) {
            gbPanelButtonDown=1;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    if(!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && INV_IsInPlayerInvRect(x,y)) {
        if(INV_IsInNpcPanelRect(x,y)) {
            gbPanelButtonDown=1;
            UI_SetUIVar(1,1,0);
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_004B9A00(4,0,0,0,0);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        pMsg->bReturn=1;
        pMsg->lResult=0;
        int result=0;
        if(x>=gtPlayerInvGrid.nGridLeft && x<=gtPlayerInvGrid.nGridRight && y>=gtPlayerInvGrid.nGridTop && y<=gtPlayerInvGrid.nGridBottom) {
            result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtPlayerInvGrid,0);
            handled=1;
        }
        else {
            int bodyloc=0;
            for(;bodyloc<11;++bodyloc) {
                if(x>=gaCompGrids[bodyloc].rect.nLeft && x<=gaCompGrids[bodyloc].rect.nRight && y>=gaCompGrids[bodyloc].rect.nTop && y<=gaCompGrids[bodyloc].rect.nBottom) goto BODY_FOUND;
            }
            goto AFTER_BODY;
BODY_FOUND:
            {
                D2UnitStrc* cursor=INVENTORY_GetCursorItem(inventory);
                if(sub_00468830()==6 || sub_00468830()==8) {
USE_BODY_ACTION:
                    result=gaBodyClick[bodyloc](player,inventory,bodyloc);
                    handled=1;
                }
                else {
                    D2UnitStrc* bodyItem=INVENTORY_GetItemFromBodyLoc(inventory,bodyloc);
                    if(!INV_CanSocketInto(bodyItem,cursor)) goto USE_BODY_ACTION;
                    if(!ITEM_IsItemActionBlocked(cursor) && INV_CheckTradeClickDelay()) {
                        MSG_SendTwoDwords(0x28,!cursor?-1:cursor->dwUnitId,!bodyItem?-1:bodyItem->dwUnitId);
                        ITEM_SetUninterruptableState(cursor);
                        sub_004B9A00(ITEM_GetDropSound(bodyItem),0,0,0,0);
                        handled=1;
                    }
                    result=0;
                }
            }
AFTER_BODY:
            if(!handled && GAME_IsExpansion() && INV_IsOverWeaponSwapTab(x,y)) {
                pMsg->bReturn=1;
                sub_0048A730_SwapWeapons();
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        pMsg->lResult=0;
        pMsg->bReturn=1;
        if(!result) {
            if(sub_00468830()==6) UI_CancelCursorItemUse();
            else if(sub_00468830()==8) MSG_SendDword(0x4C,-1);
        }
        sub_00420290_BreakHandlerChain(pMsg);
        gbHoverInGrid=0;
        gbHoverInBodyLoc=0;
        gpHoverItem=0;
        gpLastHoverItem=0;
        if(!handled) INV_ClickOutsidePanel(y,pMsg,x);
        return;
    }
    switch(gnInvPanelMode) {
    case 14:
        if(x>=gtCubeGrid.nGridLeft && x<=gtCubeGrid.nGridRight && y>=gtCubeGrid.nGridTop && y<=gtCubeGrid.nGridBottom) {
            INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtCubeGrid,3);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        break;
    case 12:
        {
            int left,right,top,bottom;
            if(GAME_IsExpansion()) {
                left=gtBigBankGrid.nGridLeft;right=gtBigBankGrid.nGridRight;top=gtBigBankGrid.nGridTop;bottom=gtBigBankGrid.nGridBottom;
            }
            else {
                left=gtBankGrid.nGridLeft;right=gtBankGrid.nGridRight;top=gtBankGrid.nGridTop;bottom=gtBankGrid.nGridBottom;
            }
            if(x>=left && x<=right && y>=top && y<=bottom) {
                if(GAME_IsExpansion()) INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBigBankGrid,4);
                else INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtBankGrid,4);
                pMsg->lResult=0;
                pMsg->bReturn=1;
                gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
                sub_00420290_BreakHandlerChain(pMsg);
                return;
            }
        }
        break;
    case 11:
        if(x>=gtTradePage2Grid.nGridLeft && x<=gtTradePage2Grid.nGridRight && y>=gtTradePage2Grid.nGridTop && y<=gtTradePage2Grid.nGridBottom) {
            int result=INV_ClickInvGrid(player,inventory,x,y,pMsg->wParam,&gtTradePage2Grid,2);
            pMsg->lResult=0;
            pMsg->bReturn=1;
            gbHoverInGrid=0;gbHoverInBodyLoc=0;gpHoverItem=0;gpLastHoverItem=0;
            sub_00420290_BreakHandlerChain(pMsg);
            if(result) sub_004B90B0_SendState();
            return;
        }
        break;
    }
    pMsg->bReturn=0;
    INV_ClickOutsidePanel(y,pMsg,x);
}


extern D2PanelButtonStrc gaPanelButtons_007BC9E0[]; // 0x007BC9E0
extern int gnButtonCount; // 0x00722160
extern int gnButtonRow; // 0x0072215C
extern int gaNpcButtonX[][4]; // 0x00722168
extern int gnTabEnabled0; // 0x0072211E
extern int gnTabEnabled1; // 0x00722130
extern int gnTabEnabled2; // 0x00722142
extern int gnTabEnabled3; // 0x00722154
extern int gdwNpcPanelDelayTick; // 0x007BCC08
extern int gnInvMouseX; // 0x007BCA4C
extern int gnInvMouseY; // 0x007BCBD8
extern int gnGlobal_007BCBB0; // 0x007BCBB0
extern int gnGlobal_007BCBB4; // 0x007BCBB4
extern int gnGlobal_007BCBB8; // 0x007BCBB8
extern int gnGlobal_007BCBBC; // 0x007BCBBC
extern int gbPanelButtonClicked; // 0x007BCE9C
extern D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58
int __cdecl INV_IsNpcStateIdle(); // 0x00483E10
int __cdecl INV_ResetNpcButtons(); // 0x00487BE0
void __stdcall INV_SelectItemPageTab(unsigned char nTab); // 0x00487A10
int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc*,int,int*,Unicode*,int); // 0x004B2AD0
static inline int GetNpcTabLeft(int tab)
{
    return gnPanelOffsetX+80*tab;
}
static inline int GetNpcTabRight(int tab)
{
    return GetNpcTabLeft(tab)+80;
}
// 0x00491D20
void __stdcall INV_HandleNpcClick(SMSGHANDLER_PARAMS* msg)
{
    const int x=msg->nXpos;
    const int y=msg->nYpos;
    if(gnInvPanelMode!=0 && gnInvPanelMode!=1 && gnInvPanelMode!=3 && gnInvPanelMode!=2 && gnInvPanelMode!=4) goto HANDLE;
    if(!AUTOMAP_IsCursorOverMiniPanelButton(msg) && INV_IsInNpcPanelRect(x,y) && INV_IsNpcStateIdle()) {
        gbPanelButtonDown=1;msg->bReturn=1;msg->lResult=0;
        sub_004B9A00(4,0,0,0,0);
        sub_00420290_BreakHandlerChain(msg);return;
    }
    if(CURSOR_GetCursorItem()) {
        int nArg;
        if(AUTOMAP_IsCursorOverMiniPanelButton(msg)==1) {INV_ResetNpcButtons();return;}
        if(x<0 || x>gtPlayerInvRect.nLeft || y<0 || y>gtPlayerInvRect.nBottom) goto OUTSIDE;
        msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);
        if(x<gtNpcInvGrid.nGridLeft || x>gtNpcInvGrid.nGridRight || y<gtNpcInvGrid.nGridTop || y>gtNpcInvGrid.nGridBottom) return;
        if(sub_00468830()==6 || !NPCMENU_GetInteractNpcId(&nArg)) return;
        D2UnitStrc* player=CUNIT_FindClientUnit(nArg,1);
        if(!player) return;
        Unicode text[64];int cost;
        if(!NPCMENU_GetTradeCostText(CURSOR_GetCursorItem(),1,&cost,text,64)) return;
        const int arg=msg->wParam;
        D2UnitStrc* item=CURSOR_GetCursorItem();
        if(item && NPCMENU_HandleTradeClick((int)player,(int)item,1,x,y,arg,1,0)) CURSOR_SetCursorItemState(0);
        return;
    }
    if(AUTOMAP_IsCursorOverMiniPanelButton(msg)==1) {INV_ResetNpcButtons();return;}
    msg->bReturn=0;
    if(x>=gnPanelOffsetX && x<=gnScreenWidth/2-1 && y>=gnScreenHeight + gnPanelOffsetY-0x1DF && y<=gnPanelOffsetY+gnScreenHeight-0x1C1) {
        if(x>=GetNpcTabLeft(0) && x<=GetNpcTabRight(0)) {
            if(gnTabEnabled0 && gnSelectedTab!=0) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(0);
            }
        } else if(x>=GetNpcTabLeft(1) && x<=GetNpcTabRight(1)) {
            if(gnTabEnabled1 && gnSelectedTab!=1) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(1);
            }
        } else if(x>=GetNpcTabLeft(2) && x<=GetNpcTabRight(2)) {
            if(gnTabEnabled2 && gnSelectedTab!=2) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(2);
            }
        } else if(x>GetNpcTabLeft(3) && x<GetNpcTabRight(3)) {
            if(gnTabEnabled3 && gnSelectedTab!=3) {
                sub_004B9A00(6,0,0,0,0);gdwNpcPanelDelayTick=0;INV_SelectItemPageTab(3);
            }
        } else {
            msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
        }
        msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
    }
    if(x<gnGlobal_007BCBB0 || x>gnGlobal_007BCBB4) goto OUTSIDE;
    {
        const int top=gnScreenHeight+gnPanelOffsetY-0x6D;
        if(y>=top && y<=gnGlobal_007BCBBC) {
            int hasSelected=0;int selected=0;int clicked=-1;
            for(int i=0;i<gnButtonCount;++i) {
                if(gaPanelButtons_007BC9E0[i].nValue==1) {selected=i;hasSelected=1;}
                if(gnInvMouseX>gaNpcButtonX[gnButtonRow][i]+gnPanelOffsetX && gnInvMouseX<gaNpcButtonX[gnButtonRow][i]+gnPanelOffsetX+45 && gnInvMouseY>top && gnInvMouseY<gnPanelOffsetY+gnScreenHeight-0x41) clicked=i;
            }
            if(clicked!=-1) {
                if(gaPanelButtons_007BC9E0[clicked].bActive==1) {
                    sub_004B9A00(1,0,0,0,0);
                    if(hasSelected==1) {
                        if(clicked==selected) {
                            gaPanelButtons_007BC9E0[clicked].nValue=0;gnInvPanelMode=1;
                            if(sub_00463DD0_GetPlayerUnit()) {
                                D2InventoryStrc* inventory=sub_00463DD0_GetPlayerUnit()->pInventory;
                                if(inventory && !INVENTORY_GetCursorItem(inventory)) CURSOR_SetCursorItemState(0);
                            }
                        } else {
                            gaPanelButtons_007BC9E0[clicked].nValue=1;gaPanelButtons_007BC9E0[selected].nValue=0;
                        }
                    } else gaPanelButtons_007BC9E0[clicked].nValue=1;
                    gbPanelButtonClicked=1;
                } else {INV_ResetNpcButtons();gbPanelButtonClicked=0;}
            }
            msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
        }
    }
    if(y<gnGlobal_007BCBB8 || y>gnGlobal_007BCBBC) goto OUTSIDE;
    {
    int nArg;
    if((gnInvPanelMode==1 || gnInvPanelMode==2) && x>=gtNpcInvGrid.nGridLeft && x<=gtNpcInvGrid.nGridRight && y>=gtNpcInvGrid.nGridTop && y<=gtNpcInvGrid.nGridBottom && NPCMENU_GetInteractNpcId(&nArg)) {
        D2UnitStrc* player=CUNIT_FindClientUnit(nArg,1);
        if(player) INV_ClickInvGrid(player,player->pInventory,x,y,msg->wParam,&gtNpcInvGrid,gnSelectedTab);
    }
    }
HANDLE:
    msg->bReturn=1;msg->lResult=0;sub_00420290_BreakHandlerChain(msg);return;
OUTSIDE:
    INV_HandlePanelClick(msg);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040


#include "gen/data/Source/D2Client/UI/inv_00491D20.inc"
