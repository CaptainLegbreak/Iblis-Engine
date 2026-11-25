#include "D2Structs.h"
#include "D2CelContext.h"
#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2StormTypes.h"
#include "D2ClientUi.h"
#include "D2Records.h"
#include "D2ItemsWorld.h"
#include "D2DataTbls.h"
#include "D2ClientUiRecords.h"

struct D2CelFileStrc;

struct D2UnitStrc;

typedef unsigned int size_t;

struct Unicode;

struct D2InventoryStrc;


#pragma pack(push, 1)

struct D2PanelTabStrc
{
    int nX;
    int nY;
    unsigned short nString;
    int bSelected;
    int bEnabled;
};

#pragma pack(pop)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                     // 0x00681EF0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                 // 0x0063C1E0

void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem);                                         // 0x00468070

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId);                                                // 0x004B3230

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __stdcall INV_DrawUnitInventory(D2UnitStrc* pUnit);                                           // 0x00483FF0

D2CelFileStrc* __cdecl GAME_GetBuySellButtonCells(); // 0x00454600

int __fastcall D2Win_10127_SetFont(int nFont);                                                                     // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

int __cdecl NPCMENU_IsGambleShop();                                                                                 // 0x004B3500

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

extern int gbNpcTradeClicked;                                                                               // 0x007BCBEC

static int gnInvPanelMode; // 0x007BCBF0

extern D2PanelButtonStrc gaPanelButtons_007BC9E0[];                                                         // 0x007BC9E0

extern void* gpBuySellCel;                                                                            // 0x007C0DC8

extern void* gpBuySellTabsCel;                                                                           // 0x007BCC24

extern int gnPanelOffsetX;                                                                               // 0x007A2858

extern int gnPanelOffsetY;                                                                               // 0x007A285C

// kept: the unit builds equal only with this second declaration of 0x00711470 in scope (0x488B00)
extern int gnScreenHeight_00711470; // 0x00711470

extern int gnButtonCount;                                                                          // 0x00722160

extern int gnButtonRow;                                                                            // 0x0072215C

extern int gaNpcButtonX[][4];                                                                        // 0x00722168

extern int gnNpcTabCount;                                                                               // 0x00722158

extern D2PanelTabStrc gaNpcTabs[];                                                                    // 0x00722110

extern int gpCursorItem;                                                                              // 0x007A6ABC

extern int gnCursorAnim;                                                                               // 0x007A6ADC

extern int gdwGlobal_007A6AE0;                                                                              // 0x007A6AE0

extern int gdwGlobal_007A6AF0;                                                                              // 0x007A6AF0


static int gnInvMouseX; // 0x007BCA4C

static int gnInvMouseY; // 0x007BCBD8

D2InvRectStrc gtNpcInvRect; // 0x007BCBB0

#define gnGlobal_007BCBB0 (gtNpcInvRect.nLeft)

#define gnGlobal_007BCBB4 (gtNpcInvRect.nRight)

#define gnGlobal_007BCBBC (gtNpcInvRect.nBottom)

D2UnitStrc* __cdecl NPCMENU_GetInteractNpc();                                                          // 0x004B1620

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags();                                                                        // 0x004B32D0

unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0

int __stdcall ITEMS_GetAllRepairCosts(void* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void* pfCallback); // 0x0062FE60

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

extern D2InventoryGridInfoStrc gtBigBankGrid;                                                              // 0x007BCA78

extern D2InventoryGridInfoStrc gtBankGrid;                                                              // 0x007BCB40

extern D2InventoryGridInfoStrc gtPlayerInvGrid;                                                              // 0x007BCB88

// build: symbol ?gbHoverInGrid@* 0x007BCBE4
static int gbHoverInGrid;

static int gbCubeItemClicked; // 0x007BCC50

int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

void __fastcall MSG_SendDword(char nHeader, int nArg);                                          // 0x00478680

void __fastcall MSG_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9); // 0x004786D0

int __cdecl INV_CheckTradeClickDelay();                                                                      // 0x00486D10

void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ItemsTxt* pTxt);                            // 0x0049FF90

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4);                  // 0x004B9A00

int __fastcall ITEM_GetItemUseSound(D2UnitStrc* pItem);                                                            // 0x004C1E20

void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pItem);                                                           // 0x004C21F0

int __fastcall ITEM_IsItemActionBlocked(D2UnitStrc* pItem);                                                            // 0x004C2240

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc* pItem);                                                             // 0x00628C20

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc* pItem);                                                             // 0x00628C70

unsigned int __stdcall ITEMS_GetTransmogrify(D2UnitStrc* pItem); // 0x0062A0A0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                             // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetItemFromInventoryPage(D2InventoryStrc* pInventory, int nX, int nY, int* pOutX, int* pOutY, int nRecord, unsigned char nPage); // 0x0063BD10

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath);                                                 // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath);                                                 // 0x00648900

extern D2InvRectStrc gtPlayerInvRect;                                                                     // 0x007BCAA0

#define gnGlobal_007BCAA0 (gtPlayerInvRect.nLeft)

#define gnGlobal_007BCAA4 (gtPlayerInvRect.nRight)

#define gnGlobal_007BCAA8 (gtPlayerInvRect.nTop)

#define gnGlobal_007BCAAC (gtPlayerInvRect.nBottom)

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl GAME_IsExitPending();                                                                                 // 0x0044DA30

void __cdecl UI_CancelCursorItemUse();                                                                                // 0x00453EC0

int __cdecl CUNIT_IsPlayerDeadOrMissing();                                                                                 // 0x00463DF0

int __cdecl sub_00468830();                                                                                 // 0x00468830

void __cdecl INV_LoadUiRecords();                                                                                // 0x004835B0

int __cdecl INV_ResetNpcButtons();                                                                    // 0x00487BE0

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg);                                         // 0x00498DC0

struct D2InvRectStrc;

int __cdecl sub_0045AE90();

D2UnitStrc* __cdecl sub_00463DD0();

int __fastcall INV_IsInPlayerInvRect(int nX, int nY); // 0x00483AB0

void __stdcall INV_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg); // 0x004912A0

int __cdecl HIREABLES_AreBeltRowsShown(); // 0x004979E0

int __stdcall D2GFX_GetResolutionMode();

extern int gnScreenWidth; // 0x0071146C

extern int gnGlobal_007BCA68;

extern int gnGlobal_007BCA6C;

extern int gnGlobal_007BCA74;

extern int gnGlobal_007BCA7C;

extern int gnGlobal_007BCA80;

extern int gnGlobal_007BCA84;

extern int gnGlobal_007BCA88;

extern int gnGlobal_007BCAF4;

extern int gnGlobal_007BCAF8;

extern int gnGlobal_007BCB00;

extern int gnGlobal_007BCB44;

extern int gnGlobal_007BCB48;

extern int gnGlobal_007BCB4C;

extern int gnGlobal_007BCB50;

int __cdecl CURSOR_GetCursorItem(); // 0x004680A0

int __fastcall INV_IsInNpcPanelRect(int nX, int nY); // 0x00486E10

extern D2InvRectStrc gtCubeRect; // 0x007BCB30

extern int gnGlobal_007BCB74;

extern int gnGlobal_007BCB78;

extern int gnGlobal_007BCB7C;

extern int gnGlobal_007BCB80;

// build: symbol ?gbHoverInBodyLoc@* 0x007BCBE8
static int gbHoverInBodyLoc;

static int gbTradeAccepted; // 0x007BCE18

static int gbTradeAcceptButtonDown; // 0x007BCE20

static int gbInvGoldButtonDown; // 0x007BCE30

static int gbStashGoldButtonDown; // 0x007BCE34

static int gbStashButtonDown; // 0x007BCE38

static int gbStashButtonClicked; // 0x007BCE3C

static int gbPanelButtonDown; // 0x007BCE90

static int gbPanelButtonClicked; // 0x007BCE9C

static int gbCubeButtonDown; // 0x007BCE40

static int gbCubeButtonClicked; // 0x007BCE44

static int gbCubeCloseButtonDown; // 0x007BCE48

static int gbCubeCloseClicked; // 0x007BCE4C

struct D2ClientTextDataStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define va_arg(ap, t) (*(t*)((ap += _INTSIZEOF(t)) - _INTSIZEOF(t)))

struct D2DynamicPathStrc;

struct D2SkillStrc;

struct D2BitBufferStrc;

struct D2StaticPathStrc;

struct SMSGHANDLER_PARAMS;

struct D2ItemsTxt;

struct D2SetItemsTxt;

struct D2DataTablesStrc;

struct D2InventoryGridInfoStrc;

struct D2InvCompGridStrc;




extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

void __fastcall UI_OpenGoldPanel(int nMode); // 0x00454150

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall sub_00468040(int nArg, int nArg2); // 0x00468040

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __fastcall MSG_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600


void __cdecl sub_004B8CB0(); // 0x004B8CB0

void __fastcall sub_004B9070(int nArg); // 0x004B9070

extern "C" void __cdecl sub_004B90B0_SendState(); // 0x004B90B0

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

void __stdcall ITEMS_GetDimensions(D2UnitStrc* pItem, unsigned char* pWidth, unsigned char* pHeight, const char* szFile, int nLine); // 0x006286C0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

void __stdcall INV_DrawItemSockets(D2UnitStrc* pItem, D2InventoryGridInfoStrc* pGrid, int nX, int nY); // 0x00483E40

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x004E6850

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

int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

extern int gnDialogState; // 0x00721E34

extern int gbHoverPlayerItem; // 0x00721E38

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gnAutomapHeight_007A521C; // 0x007A521C

extern int gnAutomapWidth; // 0x007A5220

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2NpcButtonStrc gaNpcButtons[4]; // 0x007BC9E0

extern D2InventoryGridInfoStrc gtTradePage2Grid; // 0x007BCA30

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern D2InventoryGridInfoStrc gtTradePage1Grid; // 0x007BCB18

extern D2InventoryGridInfoStrc gtCubeGrid; // 0x007BCB70

extern D2InvCompGridStrc gaCompGrids[11]; // 0x007BCC58

void __cdecl INV_ResetHover(); // 0x00487990

int __fastcall NPCMENU_HandleTradeClick(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int nMode, int nX, int nY, int nArg, int bCheckTick, int bRepairAll); // 0x004B3870

void __cdecl NPCMENU_CloseNpcShop(); // 0x004B3ED0

extern int gnGlobal_0072215C; // 0x0072215C

extern int gaButtonY_00722168[][4]; // 0x00722168

extern unsigned char gnGlobal_007BCC05; // 0x007BCC05

typedef char* va_list;

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __fastcall INV_CutBracketToken(Unicode* pString, const Unicode* pToken); // 0x0048BE00

void __fastcall INV_ReplaceToken(Unicode* pString, int nIndex, const Unicode* pInsert); // 0x004834E0

D2InventoryGridInfoStrc gtNpcInvGrid; // 0x007BCB58

static D2UnitStrc* gpHoverItem; // 0x007BCBF4

static D2UnitStrc* gpLastHoverItem; // 0x007BCBF8

static unsigned char gnSelectedTab; // 0x007BCC04

static int gnHoverBodyLoc; // 0x007BCC20

static int gnSelectedShopButton; // 0x007BCC40

static int gnSelectedShopButtonKey; // 0x007BCC44

static int gbTradeCancelClicked; // 0x007BCE1C

static int gbTradeCancelButtonDown; // 0x007BCE24

static int gbGoldButtonDisabled; // 0x007BCE2C

static int gnGlobal_007BCE94; // 0x007BCE94

void __stdcall INV_DrawGridCells(D2InventoryGridInfoStrc* pGrid, int nX, int nColor, unsigned char nWidth, unsigned char nHeight, int nY); // 0x004839D0

void INV_DrawSlotFrame(D2InvCompGridStrc* pCompGrid, int nColor); // 0x00483A70

void INV_DrawBodyLocPlacement(D2InventoryStrc* pInventory); // 0x004844A0

void __stdcall INV_UpdateGridHover(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, D2UnitStrc* pCursorItem, unsigned int nX, unsigned int nY, int nPage, D2InventoryGridInfoStrc* pGrid); // 0x00487000

void __cdecl INV_RestoreSelectedShopButton(); // 0x00488F10

void __stdcall sub_E05_Emit_004844A0(D2InventoryStrc* pInventory, Unicode* pText, int nSetItemId); // 0x004844A0

static int gbNpcButtonHandled; // 0x007BCC48

static void __stdcall INV_ClickOutsidePanel(int nY, SMSGHANDLER_PARAMS* pMsg, int nX); // 0x00486E60

static int INV_IsOverTransmuteButton(int nX, int nY); // 0x00489980

static int INV_IsOverCloseButton(int nX, int nY); // 0x00489920

static int INV_IsOverGoldButton(int nX, int nY); // 0x00486DA0

// 0x00488400
void __cdecl INV_DrawNpcShopPanel()
{
    if (gbNpcTradeClicked == 1)
    {
        gaPanelButtons_007BC9E0[0].nValue = 0;
        gaPanelButtons_007BC9E0[1].nValue = 0;
        gaPanelButtons_007BC9E0[2].nValue = 0;
        gaPanelButtons_007BC9E0[3].nValue = 0;
        gnInvPanelMode = 1;
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pInventory));
        gbNpcTradeClicked = 0;
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpBuySellCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);

    int nUnitId;
    if (NPCMENU_GetInteractNpcId(&nUnitId))
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
        if (pUnit)
        {
            INV_DrawUnitInventory(pUnit);
        }
    }

    tContext.pCellFile = GAME_GetBuySellButtonCells();
    for (int i = 0; i < gnButtonCount; ++i)
    {
        tContext.nFrame = gaPanelButtons_007BC9E0[i].nValue + gaPanelButtons_007BC9E0[i].nFrame;
        sub_004F6480(&tContext, gaNpcButtonX[gnButtonRow][i] + gnPanelOffsetX - 1,
            gnScreenHeight + gnPanelOffsetY - 0x3F, -1, 5, 0);
    }

    const int nOldFont = D2Win_10127_SetFont(1);
    for (int i = 0; i < gnNpcTabCount; ++i)
    {
        int nColor = 0;
        if (gaNpcTabs[i].bSelected)
        {
            nColor = 4;
        }
        if (gaNpcTabs[i].bEnabled)
        {
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(gaNpcTabs[i].nString);
            const int nWidth = D2Win_10121_GetTextWidth(wszText);
            tContext.pCellFile = gpBuySellTabsCel;
            if (nColor == 4)
            {
                tContext.nFrame = i;
            }
            else if (nColor == 0)
            {
                tContext.nFrame = i + 4;
            }
            sub_004F6480(&tContext, i * 0x50 + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x1C1, -1, 5, 0);
            if (!NPCMENU_IsGambleShop())
            {
                D2Win_10117_DrawText(wszText, gaNpcTabs[i].nX - nWidth / 2 + gnPanelOffsetX,
                    gaNpcTabs[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0, nColor, 0);
            }
        }
    }
    D2Win_10127_SetFont(nOldFont);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004886C0
void __cdecl INV_DrawButtonHoverText()
{
    if (gnInvMouseX < gnGlobal_007BCBB0 || gnInvMouseX > gnGlobal_007BCBB4)
    {
        return;
    }
    const int nTop = gnScreenHeight + gnPanelOffsetY - 0x6D;
    if (gnInvMouseY < nTop || gnInvMouseY > gnGlobal_007BCBBC)
    {
        return;
    }
    for (int i = 0; i < gnButtonCount; ++i)
    {
        if (gaPanelButtons_007BC9E0[i].bActive == 1
            && gnInvMouseX > gaNpcButtonX[gnButtonRow][i] + gnPanelOffsetX
            && gnInvMouseX < gaNpcButtonX[gnButtonRow][i] + gnPanelOffsetX + 0x2D
            && gnInvMouseY > gnScreenHeight + gnPanelOffsetY - 0x6D
            && gnInvMouseY < gnScreenHeight + gnPanelOffsetY - 0x41)
        {
            if (gaPanelButtons_007BC9E0[i].nString == 0x276F)
            {
                Unicode wszText[0x100];
                D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
                D2UnitStrc* pNpc = NPCMENU_GetInteractNpc();
                if (pPlayer && pNpc)
                {
                    const int nNpcClass = pNpc->dwClassId;
                    sub_005269D0(0x100, wszText, D2LANG_GetStringFromTblIndex(0x276F),
                        ITEMS_GetAllRepairCosts(0, pPlayer, nNpcClass, GAME_GetDifficulty(), MONSTER_GetQuestFlags(), 0));
                    D2Win_10129_DrawFramedText(wszText, gaNpcButtonX[gnButtonRow][i] + gnPanelOffsetX,
                        gnScreenHeight + gnPanelOffsetY - 0x64, 0, 0);
                }
            }
            else
            {
                D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(gaPanelButtons_007BC9E0[i].nString),
                    gaNpcButtonX[gnButtonRow][i] + gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x64, 0, 0);
            }
            return;
        }
    }
}

int __fastcall INV_IsInPlayerInvRect(int nX, int nY)
{
    if (nX >= gtPlayerInvRect.nLeft && nX < gtPlayerInvRect.nRight && nY >= gtPlayerInvRect.nTop && nY <= gtPlayerInvRect.nBottom)
    {
        return 1;
    }
    return 0;
}

static int sub_00483AE0_IsInGrid7BCB18(int nX, int nY)
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

// build: symbol ?INV_DrawCursorPlacement@* 0x00483C50
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
    ITEMS_GetDimensions(pCursorItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
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
    ITEMS_GetDimensions(pOther, &nOtherWidth, &nOtherHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
    INV_DrawGridCells(pGrid, CLIENTS_GetUnitX(pOther), 3, nOtherWidth, nOtherHeight, CLIENTS_GetUnitY(pOther));
}

// build: symbol ?INV_IsUnusableQuestBook@* 0x00483F80
static int INV_IsUnusableQuestBook(D2ItemsTxt* pItemsTxt)
{
    const int nCode = pItemsTxt->dwCode;
    if (nCode == 0x20737361)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 9, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x207A7978)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x14, 5))
        {
            return 1;
        }
    }
    else if (nCode == 0x20327274)
    {
        if (!QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 8) || QUESTRECORD_GetQuestState(MONSTER_GetQuestFlags(), 0x25, 7))
        {
            return 1;
        }
    }
    return 0;
}

void __stdcall INV_DrawUnitInventory(D2UnitStrc* pUnit)
{
    INV_LoadUiRecords();
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2InventoryGridInfoStrc* pGrid;
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    switch (nType)
    {
    case 1:
        pGrid = &gtNpcInvGrid;
        break;
    case 0:
        switch (gnSelectedTab)
        {
        case 1:
            pGrid = &gtTradePage1Grid;
            break;
        case 2:
            pGrid = &gtTradePage2Grid;
            break;
        case 4:
            pGrid = GAME_IsExpansion() ? &gtBigBankGrid : &gtBankGrid;
            break;
        case 3:
            pGrid = &gtCubeGrid;
            break;
        default:
            pGrid = &gtPlayerInvGrid;
            break;
        }
        break;
    default:
        return;
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }
    const int nRecord = UNITS_GetInventoryRecordId(pUnit, gnSelectedTab, GAME_IsExpansion());
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (!pItem || INVENTORY_GetItemNodePage(pNode) != 1)
        {
            continue;
        }
        int nX;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pItem->pStaticPath->nXPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nX = PATH_GetXPosition(pItem->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        int nY;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pItem->pStaticPath->nYPos;
            break;
        default:
            if (pItem->pDynamicPath)
            {
                nY = PATH_GetYPosition(pItem->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, "d:\\diablo2\\Diablo2\\Source\\D2Common/CmnItems.h", 0x6DC);
        if (ITEMS_GetInvPage(pItem) != gnSelectedTab)
        {
            continue;
        }
        if (pItem == gpHoverItem && gbHoverInGrid)
        {
            if (sub_00468830() == 8 && !ITEMS_GetTransmogrify(gpHoverItem))
            {
                INV_DrawGridCells(pGrid, nX, 0, nWidth, nHeight, nY);
            }
            else
            {
                INV_DrawGridCells(pGrid, nX, 1, nWidth, nHeight, nY);
            }
            GFX_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            if (ITEMS_CheckIfSocketable(pItem) && ITEMS_GetMaxSockets(pItem) > 0 && ITEMS_CheckItemFlag(pItem, 0x800, 0x51C, ".\\UI\\inv.cpp"))
            {
                INV_DrawItemSockets(pItem, pGrid, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
            }
            continue;
        }
        int nColor = 0;
        if (ITEMS_CheckRequirements(pItem, pPlayer, 0, 0, 0, 0) && !ITEMS_CheckItemFlag(pItem, 4, 0x53D, ".\\UI\\inv.cpp")
            && !ITEM_IsItemActionBlocked(pItem) && ITEMS_CanBeEquipped(pItem))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x541, ".\\UI\\inv.cpp"))
            {
                nColor = 4;
            }
            else
            {
                nColor = 2;
                D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
                if (pItemsTxt->nQuest && INV_IsUnusableQuestBook(pItemsTxt))
                {
                    nColor = 0;
                }
            }
        }
        INV_DrawGridCells(pGrid, nX, nColor, nWidth, nHeight, nY);
        GFX_DrawItemCel(pItem, pGrid->nGridBoxWidth * nX + pGrid->nGridLeft, pGrid->nGridBoxHeight * nY + pGrid->nGridTop);
    }
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        return;
    }
    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pPlayer->pInventory);
    if (!pCursorItem)
    {
        return;
    }
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    switch (gnInvPanelMode)
    {
    case 0xB:
        if (gnSelectedTab == 1)
        {
            return;
        }
        if (gnSelectedTab == 2)
        {
            if (!sub_00483B10_IsInGrid7BCA30(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!INV_IsInPlayerInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xC:
    case 0xD:
        if (gnSelectedTab == 4)
        {
            if (!sub_00483B40_IsInCubeGrid(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!INV_IsInPlayerInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    case 0xE:
        if (gnSelectedTab == 3)
        {
            if (!sub_00483BF0_IsInGrid7BCB70(nMouseX, nMouseY))
            {
                return;
            }
        }
        else if (!INV_IsInPlayerInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    default:
        if (!INV_IsInPlayerInvRect(nMouseX, nMouseY))
        {
            return;
        }
        break;
    }
    INV_DrawCursorPlacement(pInventory, pGrid, nRecord, gnSelectedTab, pCursorItem);
}

// build: symbol ?INV_CanSocketInto@* 0x004843E0
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
    if (!ITEMS_CheckItemFlag(pItem, 0x800, 0x5CC, ".\\UI\\inv.cpp"))
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
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x5D2, ".\\UI\\inv.cpp"))
    {
        return 0;
    }
    if (ITEMS_CheckItemFlag(pItem, 0x100, 0x5D4, ".\\UI\\inv.cpp"))
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

// build: symbol ?INV_IsOverWeaponSwapTab@* 0x00486860
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

void __stdcall sub_E05_Emit_00486E60(SMSGHANDLER_PARAMS* pMsg)
{
    INV_ClickOutsidePanel(pMsg->nYpos, pMsg, pMsg->nXpos);
}

void __stdcall INV_NpcPanelMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        if (INV_IsInNpcPanelRect(nX, nY))
        {
            UI_SetUIVar(1, 1, 0);
            return;
        }
        INVENTORY_GetCursorItem(pInventory);
    }
    if (gbInvGoldButtonDown && !gnInvPanelMode)
    {
        gbInvGoldButtonDown = 0;
        if (INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(1);
        }
    }
    GAME_ResetMouseButtons();
    if (INV_IsInPlayerInvRect(nX, nY) && !AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

static void __stdcall INV_UpdateBodyLocHover(int nBodyLoc, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    if (INVENTORY_GetCursorItem(pInventory))
    {
        gnHoverCellX = -1;
        gnHoverCellY = -1;
        gnHoverBodyLoc = nBodyLoc;
        gbHoverInBodyLoc = 1;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        return;
    }
    const int bTwoHanded = INVENTORY_GetWieldType(pPlayer, pInventory) == 2;
    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, nBodyLoc);
    if ((nBodyLoc == 4 || nBodyLoc == 5) && bTwoHanded)
    {
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!pOther)
        {
            pOther = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 5);
        }
        if (pOther && pItem && !ITEMSIsA(pOther, 0x23) && !ITEMSIsA(pItem, 0x23)
            && !ITEMSIsA(pOther, 0x1B) && !ITEMSIsA(pItem, 0x1B))
        {
            pItem = pOther;
        }
        if (pOther && !pItem && gnInvPanelMode == 4)
        {
            pItem = pOther;
        }
    }
    if (pItem)
    {
        gbHoverInBodyLoc = 1;
        if (pItem == gpLastHoverItem)
        {
            return;
        }
        const int nLeft = (gaCompGrids[nBodyLoc].rect.nRight + gaCompGrids[nBodyLoc].rect.nLeft) / 2;
        gnHoverTopX = nLeft;
        gnHoverBottomX = nLeft;
        gpHoverItem = pItem;
        gpLastHoverItem = pItem;
        gnHoverTopY = gaCompGrids[nBodyLoc].rect.nTop;
        gnHoverBottomY = gaCompGrids[nBodyLoc].rect.nBottom;
        return;
    }
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

void __stdcall INV_UpdateInventoryHover(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        pMsg->bReturn = 0;
        return;
    }
    if (!gnDialogState)
    {
        pMsg->bReturn = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    int bHandled = 0;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && INV_IsInPlayerInvRect(nX, nY))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        int nBodyLoc = 0;
        if (nX >= gtPlayerInvGrid.nGridLeft && nX <= gtPlayerInvGrid.nGridRight && nY >= gtPlayerInvGrid.nGridTop && nY <= gtPlayerInvGrid.nGridBottom)
        {
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 0, &gtPlayerInvGrid);
            gnHoverBodyLoc = 0;
            gbHoverPlayerItem = 1;
            return;
        }
        for (; nBodyLoc < 11; ++nBodyLoc)
        {
            if (nX >= gaCompGrids[nBodyLoc].rect.nLeft && nX <= gaCompGrids[nBodyLoc].rect.nRight && nY >= gaCompGrids[nBodyLoc].rect.nTop && nY <= gaCompGrids[nBodyLoc].rect.nBottom)
            {
                INV_UpdateBodyLocHover(nBodyLoc, pPlayer, pInventory);
                gbHoverPlayerItem = 1;
                return;
            }
        }
        gnHoverBodyLoc = 0;
        pMsg->bReturn = 0;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xB)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483AE0_IsInGrid7BCB18(nX, nY))
        {
            gnSelectedTab = 1;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 1, &gtTradePage1Grid);
            bHandled = 1;
        }
        else if (sub_00483B10_IsInGrid7BCA30(nX, nY))
        {
            gnSelectedTab = 2;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 2, &gtTradePage2Grid);
            bHandled = 1;
        }
        gnSelectedTab = nOldTab;
        if (!bHandled)
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xC)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483B40_IsInCubeGrid(nX, nY))
        {
            gnSelectedTab = 4;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            if (GAME_IsExpansion())
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBigBankGrid);
            }
            else
            {
                INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 4, &gtBankGrid);
            }
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (gnInvPanelMode == 0xE)
    {
        const unsigned char nOldTab = gnSelectedTab;
        if (sub_00483BF0_IsInGrid7BCB70(nX, nY))
        {
            gnSelectedTab = 3;
            D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
            INV_UpdateGridHover(pPlayer, pInventory, pCursorItem, nX, nY, 3, &gtCubeGrid);
        }
        else
        {
            pMsg->bReturn = 0;
            gbHoverInGrid = 0;
            gbHoverInBodyLoc = 0;
            gpHoverItem = 0;
            gpLastHoverItem = 0;
        }
        gnSelectedTab = nOldTab;
        gbHoverPlayerItem = 1;
        return;
    }
    if (GAME_GetUIVarState(0x24))
    {
        pMsg->bReturn = 0;
        return;
    }
    pMsg->bReturn = 0;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
    gbHoverPlayerItem = 0;
}

int __cdecl INV_ResetNpcButtons()
{
    gaNpcButtons[0].bActive = 0;
    gaNpcButtons[1].bActive = 0;
    gaNpcButtons[2].bActive = 0;
    gaNpcButtons[3].bActive = 0;
    gnInvPanelMode = 1;
    CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory));
    return 1;
}

// build: symbol ?INV_CanUseCursor@* 0x004888C0
int __cdecl INV_CanUseCursor()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 4 || gnInvPanelMode == 3)
    {
        if (INVENTORY_GetCursorItem(sub_00463DD0_GetPlayerUnit()->pInventory))
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

void __stdcall INV_NpcShopMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0 || gnInvPanelMode == 1 || gnInvPanelMode == 3 || gnInvPanelMode == 2 || gnInvPanelMode == 4)
    {
        const int nY = pMsg->nYpos;
        const int nX = pMsg->nXpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (CURSOR_GetCursorItem() && nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
        {
            return;
        }
        int nUnitId;
        if (gnInvPanelMode && NPCMENU_GetInteractNpcId(&nUnitId))
        {
            D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 1);
            if (pUnit)
            {
                D2InventoryStrc* pInventory = pUnit->pInventory;
                if (nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight && nY >= gtNpcInvRect.nTop && nY <= gtNpcInvRect.nBottom)
                {
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    if (nX >= gtNpcInvGrid.nGridLeft && nX <= gtNpcInvGrid.nGridRight && nY >= gtNpcInvGrid.nGridTop && nY <= gtNpcInvGrid.nGridBottom)
                    {
                        INV_UpdateGridHover(pUnit, pInventory, 0, nX, nY, gnSelectedTab, &gtNpcInvGrid);
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        gbHoverPlayerItem = 0;
                        return;
                    }
                }
            }
        }
        INV_UpdateInventoryHover(pMsg);
    }
}

static void INV_SelectButtonByKey(int nKey)
{
    gaNpcButtons[0].bActive = gaNpcButtons[0].nKey == nKey;
    gaNpcButtons[1].bActive = gaNpcButtons[1].nKey == nKey;
    gaNpcButtons[2].bActive = gaNpcButtons[2].nKey == nKey;
    gaNpcButtons[3].bActive = gaNpcButtons[3].nKey == nKey;
}

static int INV_IsOverTradeButtonLeft(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0xDF && nX < gnPanelOffsetX + 0xFF
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverTradeButtonRight(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x133
        && nY > gnScreenHeight + gnPanelOffsetY - 0x60 && nY < gnScreenHeight + gnPanelOffsetY - 0x40)
    {
        return 1;
    }
    return 0;
}

void __stdcall INV_TradePanelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xB)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        sub_004B8CB0();
        return;
    }
    if (!sub_00483B10_IsInGrid7BCA30(nX, nY))
    {
        if (INV_IsOverTradeButtonLeft(nX, nY))
        {
            if (gbTradeAccepted && gbTradeAcceptButtonDown)
            {
                sub_004B9070(0);
            }
            gbPanelButtonClicked = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (INV_IsOverTradeButtonRight(nX, nY))
        {
            if (gbTradeCancelClicked && gbTradeCancelButtonDown)
            {
                sub_004B8CB0();
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbPanelButtonClicked = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
        if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
        {
            gbTradeAcceptButtonDown = 0;
            gbTradeAccepted = 0;
            gbPanelButtonClicked = 0;
            gbTradeCancelClicked = 0;
            return;
        }
        if (INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
        {
            UI_OpenGoldPanel(2);
        }
        if (gbPanelButtonClicked)
        {
            const int bFlag = gbTradeAcceptButtonDown;
            gbPanelButtonClicked = 0;
            if (bFlag)
            {
                if (gbTradeAccepted == 1)
                {
                    gbTradeAccepted = 0;
                    sub_004B90B0_SendState();
                }
            }
            else if (gbTradeCancelButtonDown && gbTradeCancelClicked)
            {
                gbTradeCancelClicked = 0;
            }
            gbTradeCancelButtonDown = 0;
            gbTradeAcceptButtonDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (gbTradeAccepted)
    {
        sub_004B90B0_SendState();
    }
    gbPanelButtonClicked = 0;
    gbTradeCancelClicked = 0;
    gbTradeAccepted = 0;
}

void __stdcall INV_StashMouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode == 0xC || gnInvPanelMode == 0xD)
    {
        const int nX = pMsg->nXpos;
        const int nY = pMsg->nYpos;
        gnInvMouseX = nX;
        gnInvMouseY = nY;
        if (INV_IsInPlayerInvRect(nX, nY) || sub_00483B40_IsInCubeGrid(nX, nY))
        {
            INV_UpdateInventoryHover(pMsg);
            return;
        }
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
        D2Win_10129_DrawFramedText(0, -1, -1, 0, 0);
    }
}

void __stdcall INV_StashClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xC && gnInvPanelMode != 0xD)
    {
        gbPanelButtonClicked = 0;
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if ((!HIREABLES_AreBeltRowsShown() || !AUTOMAP_IsCursorOverMiniPanelButton(pMsg)) && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        UI_SetUIVar(0x19, 1, 0);
        return;
    }
    if (INV_IsOverTransmuteButton(nX, nY))
    {
        if (gbStashButtonDown)
        {
            gbStashButtonDown = 0;
            UI_SetUIVar(0x19, 1, 0);
            MSG_SendShorts(0x4F, 0x12, 0, 0);
        }
        gbStashButtonClicked = 0;
        gbPanelButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    gbStashButtonDown = 0;
    gbStashButtonClicked = 0;
    if (!HIREABLES_AreBeltRowsShown() && INV_IsOverGoldButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(3);
    }
    if (INV_IsOverCloseButton(nX, nY) && !gbGoldButtonDisabled)
    {
        UI_OpenGoldPanel(4);
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    gbStashGoldButtonDown = 0;
    gbInvGoldButtonDown = 0;
    if (gbPanelButtonClicked)
    {
        const int bFlag = gbTradeAcceptButtonDown;
        gbPanelButtonClicked = 0;
        if (bFlag)
        {
            if (gbTradeAccepted == 1)
            {
                gbTradeAccepted = 0;
            }
        }
        else if (gbStashButtonClicked && gbStashButtonDown)
        {
            gbStashButtonDown = 0;
        }
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    gbPanelButtonClicked = 0;
    gbStashButtonDown = 0;
    gbTradeAccepted = 0;
}

static void INV_AppendBookCharges(Unicode* pText)
{
    const Unicode* pColorEnd = D2LANG_GetStringFromTblIndex(0xF9E);
    D2_ASSERT(ITEMSIsA(gpHoverItem, 0x35), 0xC43);
    sub_004E6850_BuildSocketFillerText(gpHoverItem, pText, 0x200);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0x2B48));
    sub_00526700(pText, pColorEnd);
}

// build: symbol ?INV_FindSetItem@* 0x00486770
static D2UnitStrc* INV_FindSetItem(D2InventoryStrc* pInventory, int nSetItemId)
{
    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET && ITEMS_CheckItemFlag(pItem, 0x10, 0xCA1, ".\\UI\\inv.cpp"))
        {
            const unsigned char nPage = ITEMS_GetInvPage(pItem);
            if (nPage == 0 || nPage == 3 || nPage == 4 || nPage == 0xFF)
            {
                const int nNodePage = INVENTORY_GetItemNodePage(pNode);
                if (nNodePage == 1 || nNodePage == 3 || nNodePage == 4)
                {
                    const int nFileIndex = ITEMS_GetFileIndex(pItem);
                    D2SetItemsTxt* pSetItemsTxt = (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount) ? &sgptDataTables->pSetItemsTxt[nFileIndex] : 0;
                    if (pSetItemsTxt && pSetItemsTxt->wSetItemId == nSetItemId)
                    {
                        return pItem;
                    }
                }
            }
        }
    }
    return 0;
}

void __cdecl INV_ResetHover()
{
    gnHoverTopX = -1;
    gnHoverTopY = -1;
    gnHoverBottomX = -1;
    gnHoverBottomY = -1;
    gnHoverCellX = -1;
    gnHoverCellY = -1;
    gbHoverInGrid = 0;
    gbHoverInBodyLoc = 0;
    gpHoverItem = 0;
    gpLastHoverItem = 0;
}

static inline int sub_00488B00_PanelTop()
{
    return gnScreenHeight + gnPanelOffsetY - 0x6D;
}

// 0x00488B00
void __stdcall INV_NpcPanelButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    gbPanelButtonDown = 0;
    gnGlobal_007BCE94 = 0;
    if (CURSOR_GetCursorItem())
    {
        pMsg->bReturn = 0;
        return;
    }

    if (gbPanelButtonClicked == 1)
    {
        int bClicked = 0;
        if (nX >= gtNpcInvRect.nLeft && nX <= gtNpcInvRect.nRight
            && nY >= sub_00488B00_PanelTop() && nY <= gtNpcInvRect.nBottom)
        {
            for (int i = 0; i < gnButtonCount; ++i)
            {
                D2NpcButtonStrc* pButton = &gaNpcButtons[i];
                if (pButton->nId != 1)
                {
                    continue;
                }

                if (gnInvMouseX > gnPanelOffsetX + gaButtonY_00722168[gnGlobal_0072215C][i]
                    && gnInvMouseX < gnPanelOffsetX + gaButtonY_00722168[gnGlobal_0072215C][i] + 0x2D
                    && gnInvMouseY > sub_00488B00_PanelTop()
                    && gnInvMouseY < sub_00488B00_PanelTop() + 0x2C
                    && pButton->bActive == 1)
                {
                    if (pButton->nMode == 9)
                    {
                        pMsg->bReturn = 1;
                        pMsg->lResult = 0;
                        sub_00420290_BreakHandlerChain(pMsg);
                        gbPanelButtonClicked = 0;
                        D2InventoryStrc* const pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
                        if (!INVENTORY_GetCursorItem(pPlayerInventory))
                        {
                            CURSOR_SetCursorItemState(0);
                        }
                        NPCMENU_CloseNpcShop();
                        gnInvMouseX = 0;
                        gnInvMouseY = 0;
                        return;
                    }

                    gnInvPanelMode = pButton->nMode;
                    D2_ASSERT(gnGlobal_007BCC05 < 5, 0x22E0);
                    const unsigned short nKey = pButton->nKey;
                    if (nKey == 0x0E)
                    {
                        INV_ResetHover();
                        bClicked = 0;
                    }
                    else if (nKey == 0x0C)
                    {
                        INV_ResetHover();
                        bClicked = 0;
                    }
                    else
                    {
                        bClicked = 1;
                        if (nKey == 0x12)
                        {
                            gbNpcButtonHandled = 1;
                            NPCMENU_HandleTradeClick(sub_00463DD0_GetPlayerUnit(), 0, 1, nX, nY, 0, 1, 1);
                            gbNpcButtonHandled = 0;
                        }
                        else
                        {
                            sub_00468040(pButton->nArg, 0);
                            gnSelectedShopButton = i;
                            gnSelectedShopButtonKey = pButton->nKey;
                        }
                    }
                }
            }
        }

        if (!bClicked)
        {
            if (INV_CanUseCursor())
            {
                D2InventoryStrc* const pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
                CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pPlayerInventory));
            }

            for (int i = 0; i < gnButtonCount; ++i)
            {
                if (gaNpcButtons[i].bActive == 1)
                {
                    gaNpcButtons[i].bActive = 0;
                }
            }
        }

        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gbPanelButtonClicked = 0;
    }

    D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && !INVENTORY_GetCursorItem(pInventory) && INV_IsInNpcPanelRect(nX, nY))
    {
        D2InventoryStrc* const pPlayerInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        CURSOR_SetCursorItemState(INVENTORY_GetCursorItem(pPlayerInventory));
        NPCMENU_CloseNpcShop();
    }
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0048BE80
void __cdecl INV_FormatArgs(Unicode* pDest, const Unicode* pFormat, ...)
{
    if (pFormat)
    {
        int nCount;
        Unicode aArgs[10][200];
        nCount = 0;
        va_list args;
        va_start(args, pFormat);
        const Unicode* pArg = va_arg(args, const Unicode*);
        while (pArg)
        {
            sub_005267E0(aArgs[nCount], pArg);
            ++nCount;
            pArg = va_arg(args, const Unicode*);
        }

        const Unicode* pSource;
        Unicode* pColon = Unicode::strchr(pFormat, Unicode(':'));
        if (pColon)
        {
            Unicode wszMs[5] = { '[', 'm', 's', ']', 0 };
            int nA = -1;
            const Unicode* pMark = Unicode::strchr(pFormat, Unicode('a'));
            if (pMark && pMark < pColon)
            {
                nA = pMark[1].wChar - '0';
            }
            int nN = -1;
            pMark = Unicode::strchr(pFormat, Unicode('n'));
            if (pMark && pMark < pColon)
            {
                nN = pMark[1].wChar - '0';
            }

            if (nA != -1)
            {
                if (nN != -1)
                {
                    Unicode wszTemp[5];
                    if (aArgs[nN][0].wChar == '[')
                    {
                        Unicode::strncpy(wszTemp, aArgs[nN], 4);
                        sub_005267E0(aArgs[nN], &aArgs[nN][4]);
                    }
                    else
                    {
                        sub_005267E0(wszTemp, wszMs);
                    }
                    if (aArgs[nA][0].wChar == '[')
                    {
                        INV_CutBracketToken(aArgs[nA], wszTemp);
                    }
                }
                else
                {
                    INV_CutBracketToken(aArgs[nA], wszMs);
                }
            }
            else if (nN != -1)
            {
                sub_005267E0(aArgs[nN], &aArgs[nN][4]);
            }
            pSource = pColon + 1;
        }
        else
        {
            pSource = pFormat;
        }
        sub_005267E0(pDest, pSource);

        for (int i = 0; i < nCount; ++i)
        {
            INV_ReplaceToken(pDest, i, aArgs[i]);
        }
    }
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// build: symbol ?INV_ClickGridItem@* 0x00487740
static int __stdcall INV_ClickGridItem(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, unsigned int nX, unsigned int nY, char nPage)
{
    int nOutX;
    int nOutY;
    const int nRecord = UNITS_GetInventoryRecordId(pPlayer, nPage, GAME_IsExpansion());
    unsigned int nGridX;
    unsigned int nGridY;
    if (!nPage)
    {
        nGridX = (nX - gtPlayerInvGrid.nGridLeft) / gtPlayerInvGrid.nGridBoxWidth;
        nGridY = (nY - gtPlayerInvGrid.nGridTop) / gtPlayerInvGrid.nGridBoxHeight;
    }
    else if (GAME_IsExpansion())
    {
        nGridX = (nX - gtBigBankGrid.nGridLeft) / gtBigBankGrid.nGridBoxWidth;
        nGridY = (nY - gtBigBankGrid.nGridTop) / gtBigBankGrid.nGridBoxHeight;
    }
    else
    {
        nGridX = (nX - gtBankGrid.nGridLeft) / gtBankGrid.nGridBoxWidth;
        nGridY = (nY - gtBankGrid.nGridTop) / gtBankGrid.nGridBoxHeight;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromInventoryPage(pInventory, nGridX, nGridY, &nOutX, &nOutY, nRecord, nPage);
    if (pItem)
    {
        if (!INVENTORY_GetCursorItem(pInventory) && ITEMS_GetTransmogrify(pItem))
        {
            if (!ITEM_IsItemActionBlocked(pItem))
            {
                MSG_SendDword(0x4C, pItem->dwUnitId);
                ITEM_SetUninterruptableState(pItem);
                return 1;
            }
        }
        else if (ITEMS_CheckIfUseable(pItem))
        {
            const int nUnitX = UNITS_GetXPositionInline(pPlayer);
            const int nUnitY = UNITS_GetYPositionInline(pPlayer);
            if (!ITEM_IsItemActionBlocked(pItem) && INV_CheckTradeClickDelay())
            {
                if (GAME_GetUIVarState(0x19) && ITEMS_GetBaseCode(pItem) == 0x20786F62)
                {
                    gbCubeItemClicked = 1;
                }

                MSG_SendDwords3(0x20, pItem->dwUnitId, nUnitX, nUnitY);
                ITEM_SetUninterruptableState(pItem);
                sub_004B9A00(ITEM_GetItemUseSound(pItem), 0, 0, 0, 0);
                gbHoverInGrid = 0;
                return 1;
            }
        }
        else if (ITEMS_GetUniqueColumnFromItemsTxt(pItem))
        {
            D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            const int nCode = pTxt->dwCode;
            if (nCode == 0x20737274 || nCode == 0x20736B62 || nCode == 0x20646B62)
            {
                TEXT_OpenTextData(pItem, pTxt);
            }
            return 1;
        }
    }

    return 0;
}

// 0x004917C0
void __stdcall INV_GridClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        pMsg->bReturn = 0;
        return;
    }

    D2UnitStrc* pPlayer;
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    pPlayer = sub_00463DD0_GetPlayerUnit();
    INV_LoadUiRecords();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) || nX < gnGlobal_007BCAA0 || nX >= gnGlobal_007BCAA4 || nY < gnGlobal_007BCAA8 || nY > gnGlobal_007BCAAC)
    {
        return;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    if (nX >= gtPlayerInvGrid.nGridLeft && nX <= gtPlayerInvGrid.nGridRight && nY >= gtPlayerInvGrid.nGridTop && nY <= gtPlayerInvGrid.nGridBottom)
    {
        if (INV_ClickGridItem(pPlayer, pInventory, nX, nY, 0))
        {
            if (gnInvPanelMode >= 2 && gnInvPanelMode <= 4)
            {
                INV_ResetNpcButtons();
            }
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        pMsg->bReturn = 0;
    }

    if (gnInvPanelMode)
    {
        if (sub_00468830() == 6)
        {
            UI_CancelCursorItemUse();
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if (sub_00468830() == 8)
        {
            MSG_SendDword(0x4C, -1);
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if ((unsigned int)(gnInvPanelMode - 2) <= 2)
        {
            INV_ResetNpcButtons();
        }
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        if (sub_00468830() == 6)
        {
            UI_CancelCursorItemUse();
            return;
        }

        if (sub_00468830() == 8)
        {
            MSG_SendDword(0x4C, -1);
        }
    }
}

static int sub_00483B40_IsInRect(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nX > gnGlobal_007BCA7C && nX <= gnGlobal_007BCA80 && nY >= gnGlobal_007BCA84 && nY <= gnGlobal_007BCA88)
        {
            return 1;
        }
        return 0;
    }

    if (nX > gnGlobal_007BCB44 && nX <= gnGlobal_007BCB48 && nY >= gnGlobal_007BCB4C && nY <= gnGlobal_007BCB50)
    {
        return 1;
    }
    return 0;
}

static int sub_00483BA0_IsInRect(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nX >= gnGlobal_007BCAF4 && nX < gnGlobal_007BCAF8 && nY >= 0 && nY <= gnGlobal_007BCB00)
        {
            return 1;
        }
        return 0;
    }

    if (nX >= gnGlobal_007BCA68 && nX < gnGlobal_007BCA6C && nY >= 0 && nY <= gnGlobal_007BCA74)
    {
        return 1;
    }
    return 0;
}

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

static int INV_IsOverGoldButton(int nX, int nY)
{
    if (INVENTORY_GetCursorItem(sub_00463DD0()->pInventory))
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

static int INV_IsOverCloseButton(int nX, int nY)
{
    if (GAME_IsExpansion())
    {
        if (nY >= gnScreenHeight + gnPanelOffsetY - 0x1C7 && nY <= gnScreenHeight + gnPanelOffsetY - 0x1B6
            && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
        {
            return 1;
        }
    }
    else if (nY >= gnScreenHeight + gnPanelOffsetY - 0x103 && nY <= gnScreenHeight + gnPanelOffsetY - 0xF2
        && nX >= gnPanelOffsetX + 0x49 && nX <= gnPanelOffsetX + 0x96)
    {
        return 1;
    }
    return 0;
}

static int INV_IsOverTransmuteButton(int nX, int nY)
{
    if (nX > INV_GetPanelX() && nX < INV_GetPanelX() + 0x28
        && nY > INV_GetPanelY() - 0x23 && nY < INV_GetPanelY() + 5)
    {
        return 1;
    }
    return 0;
}

// 0x00492510
void __stdcall INV_StashButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xC && gnInvPanelMode != 0xD)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if ((!HIREABLES_AreBeltRowsShown() || !AUTOMAP_IsCursorOverMiniPanelButton(pMsg)) && INV_IsInNpcPanelRect(nX, nY))
    {
        gbPanelButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverCloseButton(nX, nY))
    {
        gbStashGoldButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverTransmuteButton(nX, nY))
    {
        gbStashButtonClicked = 1;
        gbStashButtonDown = 1;
        gbPanelButtonClicked = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbStashGoldButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbStashButtonDown = 0;
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    if (INV_IsInPlayerInvRect(nX, nY))
    {
        INV_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    if (sub_00483B40_IsInRect(nX, nY))
    {
        INV_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    if (INV_IsOverGoldButton(nX, nY))
    {
        gbInvGoldButtonDown = 1;
        gbTradeAcceptButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbStashButtonDown = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gbTradeAcceptButtonDown = 0;
        gbStashButtonClicked = 0;
        return;
    }
    if (INV_IsOverCloseButton(nX, nY))
    {
        gbStashGoldButtonDown = 1;
        gbTradeAcceptButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbStashButtonDown = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        gbStashButtonClicked = 0;
        return;
    }
    if (sub_00483BA0_IsInRect(nX, nY))
    {
        gbStashGoldButtonDown = 0;
        gbTradeAcceptButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbStashButtonDown = 0;
        gbStashButtonClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    INV_ClickOutsidePanel(nY, pMsg, nX);
    gbTradeAcceptButtonDown = 0;
    gbStashButtonClicked = 0;
}

static __declspec(noinline) int sub_00483BF0_IsInRect(int nX, int nY)
{
    if (nX >= gnGlobal_007BCB74 && nX < gnGlobal_007BCB78 && nY >= gnGlobal_007BCB7C && nY <= gnGlobal_007BCB80)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?INV_IsOverButtonC@* 0x00489FB0
static int INV_IsOverButtonC(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x113 && nX < gnPanelOffsetX + 0x13B
        && nY > gnScreenHeight + gnPanelOffsetY - 0x64 && nY < gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?INV_IsOverCubeButton@* 0x0048A000
static int INV_IsOverCubeButton(int nX, int nY)
{
    if (nX > gnPanelOffsetX + 0x90 && nX < gnPanelOffsetX + 0xB8
        && nY > gnScreenHeight + gnPanelOffsetY - 0xDF && nY < gnScreenHeight + gnPanelOffsetY - 0xB7)
    {
        return 1;
    }
    return 0;
}

// 0x004927C0
void __stdcall INV_CubeButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnInvPanelMode != 0xE)
    {
        return;
    }
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    gnInvMouseX = nX;
    gnInvMouseY = nY;
    if (!AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && INV_IsInNpcPanelRect(nX, nY))
    {
        gbPanelButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverButtonC(nX, nY))
    {
        gbCubeButtonClicked = 1;
        gbCubeButtonDown = 1;
        gbCubeCloseClicked = 0;
        gbCubeCloseButtonDown = 0;
        gbPanelButtonClicked = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (INV_IsOverCubeButton(nX, nY))
    {
        gbCubeButtonClicked = 0;
        gbCubeButtonDown = 0;
        if (!CURSOR_GetCursorItem())
        {
            gbCubeCloseClicked = 1;
            gbCubeCloseButtonDown = 1;
            gbPanelButtonClicked = 1;
            pMsg->bReturn = 1;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg) == 1)
    {
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbCubeButtonDown = 0;
        gbCubeCloseButtonDown = 0;
        gbTradeAcceptButtonDown = 0;
        gbCubeButtonClicked = 0;
        gbCubeCloseClicked = 0;
        return;
    }
    if (INV_IsInPlayerInvRect(nX, nY) || sub_00483BF0_IsInRect(nX, nY))
    {
        INV_HandlePanelClick(pMsg);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else if (INV_IsOverGoldButton(nX, nY))
    {
        gbInvGoldButtonDown = 1;
        gbTradeAcceptButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbCubeButtonDown = 0;
        gbCubeCloseButtonDown = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else if (nX >= gnGlobal_007BCB30 && nX < gnGlobal_007BCB34 && nY >= 0 && nY <= gnGlobal_007BCB3C)
    {
        gbTradeAcceptButtonDown = 0;
        gbTradeAccepted = 0;
        gbPanelButtonClicked = 0;
        gbCubeButtonDown = 0;
        gbCubeButtonClicked = 0;
        gbCubeCloseButtonDown = 0;
        gbCubeCloseClicked = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!pMsg->bReturn)
    {
        INV_ClickOutsidePanel(nY, pMsg, nX);
    }
    gbTradeAcceptButtonDown = 0;
    gbCubeButtonClicked = 0;
    gbCubeCloseClicked = 0;
}

#include "gen/data/Source/D2Client/UI/inv_004886C0.inc"
