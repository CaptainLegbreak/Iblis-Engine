#include "D2Client.h"
#include "D2Primitives.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2ItemsWorld.h"
#include "D2CelContext.h"
#include "D2ClientUiRecords.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StaticPathStrc;

struct Unicode;

struct D2SetItemsTxt;

struct D2InvRectStrc;

struct D2InventoryGridInfoStrc;

struct D2InvCompGridStrc;



extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl GAME_IsExitPending(); // 0x0044DA30

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

void __cdecl UI_CancelCursorItemUse(); // 0x00453EC0

void __fastcall UI_OpenGoldPanel(int nMode); // 0x00454150

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __cdecl sub_0045AE90(); // 0x0045AE90

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __fastcall sub_00468040(int nArg, int nArg2); // 0x00468040

void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

int __cdecl CURSOR_GetCursorItem(); // 0x004680A0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __cdecl sub_00468830(); // 0x00468830

void __fastcall MSG_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600

void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680

void __fastcall MSG_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

void __cdecl INV_LoadUiRecords(); // 0x004835B0

int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0

void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ClientTextDataStrc* pTextData); // 0x0049FF90

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230

void __cdecl sub_004B8CB0(); // 0x004B8CB0

void __fastcall sub_004B9070(int nArg); // 0x004B9070

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem); // 0x004C1E20

void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pItem); // 0x004C21F0

int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pItem); // 0x004C2240

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, int nInvPage, int bLoD); // 0x00621050

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem); // 0x00628C20

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem); // 0x00628C70

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nGridX, int nGridY, int* pX, int* pY, int nInventoryRecordId, unsigned char nPage); // 0x0063BD10

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __stdcall INV_DrawItemSockets(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6850

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0

int __stdcall ITEMS_CheckBodyLocation(D2UnitStrc* pItem, int nBodyLoc); // 0x0062ED50

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

int __stdcall sub_0063B9D0(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, int* pOutX, int* pOutY, unsigned char nPage); // 0x0063B9D0

int __stdcall INVENTORY_CanItemsBeExchanged(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nRecord, D2UnitStrc** ppOther, unsigned char nPage, int nArg8); // 0x0063BB20

unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern int gnScreenWidth; // 0x0071146C

extern int gnDialogState; // 0x00721E34

extern int gbHoverPlayerItem; // 0x00721E38

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gnButtonCount; // 0x00722160

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth; // 0x007A5220

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern D2NpcButtonStrc gaNpcButtons[4]; // 0x007BC9E0

extern D2InventoryGridInfoStrc gtTradePage2Grid; // 0x007BCA30

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern D2InventoryGridInfoStrc gtBigBankGrid; // 0x007BCA78

extern D2InvRectStrc gtPlayerInvRect; // 0x007BCAA0

extern D2InventoryGridInfoStrc gtTradePage1Grid; // 0x007BCB18

extern D2InventoryGridInfoStrc gtBankGrid; // 0x007BCB40

extern D2InventoryGridInfoStrc gtCubeGrid; // 0x007BCB70

extern D2InventoryGridInfoStrc gtPlayerInvGrid; // 0x007BCB88

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

void __stdcall sub_Z12_EmitUse(int nValue);

void __stdcall INV_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid);

int __fastcall INV_IsInNpcPanelRect(int nX, int nY); // 0x00486E10

void __cdecl INV_CloseCubePanel(); // 0x0048A050

static int gnInvMouseX; // 0x007BCA4C

D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58

D2InvRectStrc gtNpcInvRect; // 0x007BCBB0

static int gnInvMouseY; // 0x007BCBD8

static int gbHoverInGrid; // 0x007BCBE4

static int gbHoverInBodyLoc; // 0x007BCBE8

static int gnInvPanelMode; // 0x007BCBF0

static D2UnitStrc* gpHoverItem; // 0x007BCBF4

static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8

static unsigned char gnSelectedTab; // 0x007BCC04

static int gnHoverBodyLoc; // 0x007BCC20

static int gnSelectedShopButton; // 0x007BCC40

static int gnSelectedShopButtonKey; // 0x007BCC44

static int gbCubeItemClicked; // 0x007BCC50

static int gbTradeAccepted; // 0x007BCE18

static int gbTradeCancelClicked; // 0x007BCE1C

static int gbTradeAcceptButtonDown; // 0x007BCE20

static int gbTradeCancelButtonDown; // 0x007BCE24

static int gbGoldButtonDisabled; // 0x007BCE2C

static int gbInvGoldButtonDown; // 0x007BCE30

static int gbStashGoldButtonDown; // 0x007BCE34

static int gbStashButtonDown; // 0x007BCE38

static int gbStashButtonClicked; // 0x007BCE3C

static int gbPanelButtonDown; // 0x007BCE90

static int gnGlobal_007BCE94; // 0x007BCE94

static int gbPanelButtonClicked; // 0x007BCE9C

void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY); // 0x004839D0

void INV_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor); // 0x00483A70

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit);   // 0x004521C0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);   // 0x00483360

extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);   // 0x005267E0

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime);   // 0x0061C100

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);   // 0x006253B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);   // 0x00625480

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic);   // 0x00625820

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit);   // 0x006277F0

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType);   // 0x00627910

int __stdcall STATLIST_GetDefenseFromUnit(D2UnitStrc* pUnit); // 0x00626020



extern "C" const char gszCmnItemsH[];                                                               // 0x006D9B90

extern "C" const char gszInvCpp[];                                                                  // 0x006D9BC0

struct D2BodyLocRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    int unk0x10;
};

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny);                       // 0x00478F20

void __cdecl INV_ResetHover();                                                                     // 0x00487990

int __stdcall INV_IsCursorInRect(int nLeft, int nTop, int nRight, int nBottom);                    // 0x0048A790

extern D2BodyLocRectStrc gaBodyLocRects[11];                                                       // 0x007BCD38

int gbBuySellPressed;                                                                                      // 0x007BCEA0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

struct D2CelFileStrc* __fastcall GAME_LoadUiCelFile(const char* szPath);                          // 0x004520C0

int __fastcall D2Win_10127_SetFont(int nSize);                                                                     // 0x00502EF0

enum D2C_UIvars
{
    UI_GAME = 0x00,
    UI_INVENTORY = 0x01,
    UI_STATSCREEN = 0x02,
    UI_MINISKILL = 0x03,
    UI_SKILLTREE = 0x04,
    UI_CHATBOX = 0x05,
    UI_NEWSTATS = 0x06,
    UI_NEWSKILLS = 0x07,
    UI_NPCMENU = 0x08,
    UI_ESCMENU = 0x09,
    UI_AUTOMAP = 0x0A,
    UI_CONFIG = 0x0B,
    UI_NPCSHOP = 0x0C,
    UI_HOLDALT = 0x0D,
    UI_ANVIL = 0x0E,
    UI_QUESTSCREEN = 0x0F,
    UI_INISCROLL = 0x10,
    UI_QUESTLOG = 0x11,
    UI_UNKNOWN18 = 0x12,
    UI_HIRICONS = 0x13,
    UI_WAYPOINT = 0x14,
    UI_MINIPANEL = 0x15,
    UI_PARTYSCREEN = 0x16,
    UI_MPTRADE = 0x17,
    UI_MSGLOG = 0x18,
    UI_STASH = 0x19,
    UI_CUBE = 0x1A,
    UI_STEEGSTONE = 0x1B,
    UI_GUILDVAULT = 0x1C,
    UI_UNKNOWN29 = 0x1D,
    UI_UNKNOWN30 = 0x1E,
    UI_BELTROWS = 0x1F,
    UI_UNKNOWN32 = 0x20,
    UI_HELPSCREEN = 0x21,
    UI_HELPBUTTON = 0x22,
    UI_HIREICONS = 0x23,
    UI_MERCINV = 0x24,
    UI_RECIPESCROLL = 0x25
};

enum DrawMode
{
    DRAWMODE_TRANS25,
    DRAWMODE_TRANS50,
    DRAWMODE_TRANS75,
    DRAWMODE_MODULATE,
    DRAWMODE_BURN,
    DRAWMODE_NORMAL,
    DRAWMODE_TRANSHIGHLIGHT,
    DRAWMODE_HIGHLIGHT
};

int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, unsigned int nGamma, DrawMode eDrawMode, unsigned char* pPalette); // 0x004F6480

void __fastcall D2Win_10117_DrawText(const unsigned short* wszText, int nX, int nY, int nColor, int bCentered);   // 0x00502320

extern struct D2CelFileStrc* gpRecipeScrollCel;                                                  // 0x007BCE8C

extern int gnRecipeScrollColor_007BCEA4;                                                                    // 0x007BCEA4

extern unsigned short gwszRecipeScrollText_007BCEA8[];                                                      // 0x007BCEA8

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0

void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg);

static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory);

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg);

void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);

static void INV_SelectButtonByKey(int nKey);

void __cdecl INV_RestoreSelectedShopButton();

static int gbCubeButtonDown; // 0x007BCE40

static int gbCubeButtonClicked; // 0x007BCE44

static int gbCubeCloseButtonDown; // 0x007BCE48

static int gbCubeCloseClicked; // 0x007BCE4C

static int INV_IsOverTradeButtonLeft(int nX, int nY);

static int INV_IsOverTradeButtonRight(int nX, int nY);

void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg);

static int INV_IsOverCloseButton(int nX, int nY); // 0x00489920

static int INV_IsOverTransmuteButton(int nX, int nY); // 0x00489980

void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg);

void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg);

static void INV_AppendBookCharges(Unicode* pText);

// build: symbol ?INV_IsInPlayerInvRect@* 0x00483AB0
int __fastcall INV_IsInPlayerInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

static __declspec(noinline) int sub_00483AE0_IsInGrid7BCB18(int nX, int nY)
{
    if (nX > gtTradePage1Grid.nGridLeft && nX < gtTradePage1Grid.nGridRight && nY >= gtTradePage1Grid.nGridTop && nY <= gtTradePage1Grid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B10_IsInGrid7BCA30(int nX, int nY)
{
    if (nX > gtTradePage2Grid.nGridLeft && nX < gtTradePage2Grid.nGridRight && nY >= gtTradePage2Grid.nGridTop && nY <= gtTradePage2Grid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483B40_IsInCubeGrid(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nX > gtBigBankGrid.nGridLeft && nX <= gtBigBankGrid.nGridRight && nY >= gtBigBankGrid.nGridTop && nY <= gtBigBankGrid.nGridBottom)
        {
            return 1;
        }
        return 0;
    }
    if (nX > gtBankGrid.nGridLeft && nX <= gtBankGrid.nGridRight && nY >= gtBankGrid.nGridTop && nY <= gtBankGrid.nGridBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483BF0_IsInGrid7BCB70(int nX, int nY)
{
    if (nX >= gtCubeGrid.nGridLeft && nX < gtCubeGrid.nGridRight && nY >= gtCubeGrid.nGridTop && nY <= gtCubeGrid.nGridBottom)
    {
        return 1;
    }
    return 0;
}


static void __stdcall INV_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem); // 0x00483C50

static void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory);

void __stdcall INV_AppendDefense(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* pText); // 0x00485EE0

static void INV_AppendBookCharges(Unicode* pText); // 0x004865D0

struct D2ClientTextDataStrc;

struct D2InventoryStrc;

struct D2UnitStrc;

int __cdecl INV_GetPanelX()
{
    if (!GAME_IsExpansion())
    {
        return gnPanelOffsetX + 0x113;
    }
    return gnPanelOffsetX + 0x110;
}

// build: symbol ?INV_GetPanelY@* 0x00486B00
int __cdecl INV_GetPanelY()
{
    if (!GAME_IsExpansion())
    {
        return gnScreenHeight + gnPanelOffsetY - 0x41;
    }
    return gnPanelOffsetY + gnScreenHeight - 0x40;
}

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0

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

void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg); // 0x00486EF0

static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory); // 0x00487230

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg); // 0x004873A0

void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004889D0

static void INV_SelectButtonByKey(int nKey); // 0x00488E10

static void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY)
{
    for (int y = nY; y < nY + nHeight; ++y)
    {
        for (int x = nX; x < nX + nWidth; ++x)
        {
            const int nBoxWidth = pGrid->nGridBoxWidth;
            const int nPixelX = nBoxWidth * x + pGrid->nGridLeft;
            const int nBoxHeight = pGrid->nGridBoxHeight;
            const int nPixelY = nBoxHeight * y + pGrid->nGridTop;
            if (nPixelX >= 0 && nPixelX < gnAutomapWidth && nPixelY >= 0 && nPixelY < gnAutomapHeight_007A521C)
            {
                AUTOMAP_DrawFramedBox(nPixelX, nPixelY, nBoxWidth, nBoxHeight, gabColors_007BCAD8[nColor], 0);
            }
        }
    }
}

static void INV_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor)
{
    if (nColor == 2)
    {
        return;
    }
    const int nLeft = pCompGrid->rect.nLeft;
    const int nTop = pCompGrid->rect.nTop;
    if (nLeft >= 0 && nLeft < gnAutomapWidth && nTop >= 0 && nTop < gnAutomapHeight_007A521C)
    {
        AUTOMAP_DrawFramedBox(nLeft, nTop, pCompGrid->nWidth, pCompGrid->nHeight, gabColors_007BCAD8[nColor], 0);
    }
}

static void __stdcall INV_DrawCursorPlacement(D2InventoryStrc* pInventory, D2InventoryGridInfoStrc* pGrid, int nRecord, unsigned char nPage, D2UnitStrc* pCursorItem)
{
    if (nPage == 0xFF)
    {
        return;
    }
    D2UnitStrc* pOther = 0;
    if (!pCursorItem || !gbHoverInGrid)
    {
        return;
    }
    unsigned char nWidth;
    unsigned char nHeight;
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, gszCmnItemsH, 0x6DC);
    if (gnHoverCellX < 0 || gnHoverCellY < 0)
    {
        return;
    }
    if (gnInvPanelMode == 1 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    if (gnInvPanelMode == 0x13 && sub_00468730() < gnScreenWidth / 2)
    {
        return;
    }
    if (sub_00468740() >= gnScreenHeight - 0x27)
    {
        return;
    }
    int nOutX;
    int nOutY;
    if (sub_0063B9D0(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &nOutX, &nOutY, nPage))
    {
        INV_DrawGridCells(pGrid, gnHoverCellX, 1, nWidth, nHeight, gnHoverCellY);
        return;
    }
    if (!INVENTORY_CanItemsBeExchanged(pInventory, pCursorItem, gnHoverCellX, gnHoverCellY, nRecord, &pOther, nPage, 1)
        && (!pOther || DATATBLS_GetItemsTxtRecord(pOther->dwClassId)->dwCode != 0x20786F62))
    {
        INV_DrawGridCells(pGrid, gnHoverCellX, 0, nWidth, nHeight, gnHoverCellY);
        return;
    }
    unsigned char nOtherWidth;
    unsigned char nOtherHeight;
    ITEMS_GetDimensions(pOther, &nOtherWidth, &nOtherHeight, gszCmnItemsH, 0x6DC);
    INV_DrawGridCells(pGrid, CLIENTS_GetUnitX(pOther), 3, nOtherWidth, nOtherHeight, CLIENTS_GetUnitY(pOther));
}

int __cdecl INV_ResetNpcButtons()
{
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
    return 1;
}

// build: symbol ?INV_CanUseCursor@* 0x004888C0
int __cdecl INV_CanUseCursor()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 4 || gnInvPanelMode == 3)
    {
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        if (INVENTORY_GetCursorItem(pInventory))
        {
            return 0;
        }
        const int nMode = sub_00468830();
        if (nMode == 7 || nMode == 1 || nMode == 4)
        {
            return 1;
        }
    }
    return 0;
}

void __cdecl INV_RestoreSelectedShopButton(); // 0x00488F10

static int INV_IsOverTradeButtonLeft(int nX, int nY); // 0x00489430

static int INV_IsOverTradeButtonRight(int nX, int nY); // 0x00489480

void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489580

static int INV_IsOverCloseButton(int nX, int nY); // 0x00489920

static int INV_IsOverTransmuteButton(int nX, int nY); // 0x00489980

void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489A30

void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489AC0

static int INV_IsOverCubeButton(int nX, int nY); // 0x0048A000

void __stdcall INV_CubeClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x0048A190


static __forceinline int IsCursorInRectInline(int nLeft, int nTop, int nRight, int nBottom)
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom)
        return 1;
    return 0;
}

void __stdcall INV_MercPanelClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x0048B680

void __stdcall INV_MercPanelHoverMsg(SMSGHANDLER_PARAMS* pMsg); // 0x0048BA50

// 0x0048BC10
void __stdcall INV_DrawRecipeScroll()
{
    D2CelContextStrc tContext;

    if (!GAME_IsExpansion() || !GAME_GetUIVarState(UI_RECIPESCROLL))
    {
        return;
    }

    if (!gpRecipeScrollCel)
    {
        gpRecipeScrollCel = GAME_LoadUiCelFile("menu\\recipescroll");
        if (!gpRecipeScrollCel)
        {
            return;
        }
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpRecipeScrollCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 224, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 1;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 256, gnScreenHeight + gnPanelOffsetY - 224, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 2;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 48, -1, DRAWMODE_NORMAL, 0);
    tContext.nFrame = 3;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 256, gnScreenHeight + gnPanelOffsetY - 48, -1, DRAWMODE_NORMAL, 0);

    const int nOldSize = D2Win_10127_SetFont(4);
    D2Win_10117_DrawText(gwszRecipeScrollText_007BCEA8, gnPanelOffsetX + 80, 130 - gnPanelOffsetY, gnRecipeScrollColor_007BCEA4, 0);
    D2Win_10127_SetFont(nOldSize);
}

