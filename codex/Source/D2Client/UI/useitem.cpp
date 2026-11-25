#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2Path.h"

struct D2SelectionRectStrc;

struct Unicode;

struct D2HotspotStrc;

struct D2MsgHandlerEntryStrc;

int gnUseItemDialogState;                                                                                      // 0x007C5474

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280

int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg); // 0x00498DC0

int __stdcall INV_InvRectClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00489060

#pragma pack(push, 2)

struct D2HotspotStrc
{
    unsigned short textIndex;
    int tooltipX, tooltipY;
    int x, y, left, right, top, bottom, frame;
    char hovered, pressed;
};

#pragma pack(pop)

void* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

extern D2HotspotStrc gaUseItemHotspots[]; // 0x00727900

int gnGlobal_007C5478; // 0x007C5478

int gnAnvilObjectId; // 0x007C547C

unsigned long gdwUseItemClickTick; // 0x007C5488

int gnAnvilItemId;                                                                                      // 0x007C5480

int gnUseItemPanelMode; // 0x007C5470

struct D2ClientDialogStrc* gpUseItemConfirmDialog;                                                                                  // 0x007C5484

extern D2MsgHandlerEntryStrc gaUseItemHandlers[]; // 0x00727950

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

void __fastcall CURSOR_SetCursorItemState(D2UnitStrc* pItem); // 0x00468070

int __fastcall ITEM_GetDropSound(D2UnitStrc* pItem); // 0x004C1D60

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __stdcall WARDENCLIENT_HandlePanelAreaClick(SMSGHANDLER_PARAMS* pMsg); // 0x004922A0

void __fastcall USEITEM_HitTestHotspots(int nX, int nY); // 0x004BFBC0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __cdecl NPCMENU_GetUseItemMode(); // 0x004B1670

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __fastcall SELECT_SetSelectionRect(const D2SelectionRectStrc* pRect); // 0x00467430

void __cdecl USEITEM_OpenPanel(); // 0x004C0380

void __fastcall MSG_SendFourDwords(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3); // 0x00478700

void __cdecl sub_004B3FE0(); // 0x004B3FE0

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10

void __fastcall sub_00467430(void* pRect);                                                                  // 0x00467430

struct D2CelFileStrc;

static void USEITEM_ToggleUseMode(D2UnitStrc* pItem);

struct Unicode { unsigned short value; };

struct D2SplittedTextStrc { Unicode* text; D2SplittedTextStrc* next; };

struct D2CelContextStrc { int frame; int unk04[12]; void* cellFile; int unk38[2]; int direction; int unk44; };

extern const char gszUseItemCpp[]; // 0x006DAB50

extern "C" void* __cdecl memset(void*,int,unsigned int);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

D2CelFileStrc* __cdecl GAME_GetBuySellButtonCells(); // 0x00454600

void __fastcall AUTOMAP_DrawFramedBox(int,int,int,int,int,int); // 0x0046EFD0

void __fastcall sub_004B8100_DrawControl(void*); // 0x004B8100

int __stdcall sub_004F6480(D2CelContextStrc*,int,int,int,int,int); // 0x004F6480

int __fastcall D2Win_10121_GetTextWidth(const Unicode*); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode*,int,int,int,int); // 0x00502320

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode*,int*,int); // 0x00502970

int __fastcall D2Win_10127_SetFont(int); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short); // 0x00524A30

void* gpUpgradeCel; // 0x007C5494

void* gpHoradricBackCel; // 0x007C5498

void __stdcall USEITEM_ClickMsg(SMSGHANDLER_PARAMS* pMsg);

struct D2RectStrc;

void __cdecl USEITEM_CloseUseItemPanel(); // 0x004C0090

typedef void(__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

int __fastcall UI_CloseUIVars(int bArg1, int nArg2); // 0x00456300

void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

void __cdecl INV_SetNpcStateTrade(); // 0x00487B80

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2PacketRecord7Strc;

#pragma pack(push, 1)
struct D2PacketRecord7Strc
{
    unsigned char nHeader;
    int nValue;
    unsigned char nType;
    unsigned char bFlag;
};

void __cdecl NPCMENU_CloseNpc2(); // 0x004B3FB0

static int gnFlag_007C5470; // 0x007C5470

static int gnValue_007C547C; // 0x007C547C

// 0x004BF9D0
void __cdecl USEITEM_InitUseItemPanel()
{
    gnUseItemDialogState = 0;
    gnAnvilObjectId = 0;
    gnGlobal_007C5478 = 0;
    gdwUseItemClickTick = 0;
    gpUpgradeCel = GAME_LoadUiCelFile("menu\\upgrade");
    gpHoradricBackCel = GAME_LoadUiCelFile("menu\\horadricback");
// build: symbol ?gnHotspotCount@* 0x007278FC
    for (int i = 0; i < gnHotspotCount; i++)
    {
        gaUseItemHotspots[i].pressed = 0;
        gaUseItemHotspots[i].hovered = 0;
    }
}

struct D2ClientDialogStrc;

D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int, int, int (__cdecl*)(), int (__cdecl*)(), int, int, int, int, int, int, int); // 0x004B7EB0

void __fastcall sub_004B8370_SetField5C(D2ClientDialogStrc*, int); // 0x004B8370

void __fastcall NPCMENU_SendNpcAction(int); // 0x004B2370

int __cdecl sub_004BF9B0(); // 0x004BF9B0

void __fastcall DIALOG_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nHeight, int nArg4, int nType, int nFont, int (__cdecl* pfnCallback)(), int bEnabled); // 0x004B85F0

// 0x004BFAF0
int __cdecl USEITEM_ShowConfirmation()
{
    if (gnUseItemDialogState == 2)
    {
    sub_004B9A00(2, 0, 0, 0, 0);
    gpUseItemConfirmDialog = DIALOG_CreateDialog(0x96, 0x82, sub_004BF9B0, 0, 1, 0, 1, 0, 0, 0, 1);
    sub_004B8370_SetField5C(gpUseItemConfirmDialog, 0);
    DIALOG_AddTextLine(gpUseItemConfirmDialog, D2LANG_GetStringFromTblIndex(0xD19), 15, 0, 0, 1, 0, 0);
    gnUseItemDialogState = 3;
    if (!gnUseItemPanelMode)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
        MSG_SendFourDwords(0x44, nUnitId, gnAnvilObjectId, gnAnvilItemId, 3);
    }
    else
    {
        NPCMENU_SendNpcAction(gnAnvilItemId);
    }
    return 1;
    }
    return 0;
}

// 0x004BFBC0
void __fastcall USEITEM_HitTestHotspots(int nX, int nY)
{
// build: symbol ?gnHotspotCount@* 0x007278FC
    for (int i = 0; i < gnHotspotCount; i++)
    {
        gaUseItemHotspots[i].pressed = 0;
        gaUseItemHotspots[i].hovered = 0;
    }

    for (int i = 0; i < gnHotspotCount; i++)
    {
        if (nX >= gaUseItemHotspots[i].left && nX <= gaUseItemHotspots[i].right && nY >= gaUseItemHotspots[i].top && nY <= gaUseItemHotspots[i].bottom)
        {
            sub_004B9A00(1, 0, 0, 0, 0);
            gaUseItemHotspots[i].pressed = 1;
            gaUseItemHotspots[i].hovered = 1;
        }
    }
}

// 0x004C0100
void __cdecl USEITEM_FreeUseItemPanel()
{
    if (gnUseItemDialogState)
    {
        sub_004C0090();
    }

    if (gpUpgradeCel)
    {
        ARCHIVE_FreeClientCellFile(gpUpgradeCel);
        gpUpgradeCel = 0;
    }

    if (gpHoradricBackCel)
    {
        ARCHIVE_FreeClientCellFile(gpHoradricBackCel);
        gpHoradricBackCel = 0;
    }
}

// 0x004BFA30
void __stdcall USEITEM_MouseMoveMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2Win_10129_DrawFramedText(0, -1, -1, 0, 0);
    AUTOMAP_IsCursorOverMiniPanelButton(pMsg);
    if (gnUseItemDialogState == 1)
    {
        INV_InvRectClickMsg(pMsg);
    }
}

static D2UnitStrc* GetCursorItem_Inline()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    return INVENTORY_GetCursorItem(pInventory);
}

// 0x004BFA70
static void USEITEM_ToggleUseMode(D2UnitStrc* pItem)
{
    if (gnUseItemDialogState == 1)
    {
        gnUseItemDialogState = 2;
        CURSOR_SetCursorItemState(0);
        if (!pItem)
            return;
        gnAnvilItemId = pItem->dwUnitId;
        sub_004B9A00(ITEM_GetDropSound(pItem), 0, 0, 0, 0);
        return;
    }
    if (gnUseItemDialogState == 2)
    {
        gnUseItemDialogState = 1;
        gnAnvilItemId = 0;
        if (pItem)
            CURSOR_SetCursorItemState(pItem);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
}

struct D2PanelGfxStrc;

struct D2CellNodeStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

struct D2PanelGfxStrc
{
    int unk0x00[15];
    int f_3C;
    int unk0x40[2];
};

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

int __fastcall GFX_DrawItemCel(D2UnitStrc* pItem, int nX, int nY); // 0x0046EE80

int __fastcall sub_004DBB50(D2PanelGfxStrc* pGfx, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5, int* pOut, int nArg7, int nArg8); // 0x004DBB50

void __fastcall sub_004DBEA0(D2UnitStrc* pUnit, int nArg2, int nArg3, unsigned int* pWidth, unsigned int* pHeight); // 0x004DBEA0

int __stdcall sub_006001F0(D2PanelGfxStrc* pGfx, int nArg2, int nArg3); // 0x006001F0

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

// 0x004BFDD0
void __cdecl USEITEM_DrawUseItemPanel()
{
 int oldFont=D2Win_10127_SetFont(1);
 int mode=gnUseItemPanelMode;
 if(mode==1 || mode==0){
  D2CelContextStrc context;
  memset(&context,0,sizeof(context));
  context.direction=0;
  if(mode==0)context.cellFile=gpHoradricBackCel;
  else context.cellFile=gpUpgradeCel;
  context.frame=0;
  sub_004F6480(&context,105,270,-1,5,0);
  context.cellFile=GAME_GetBuySellButtonCells();
  for(int i=0;i<gnHotspotCount;++i){
   const int drawY=gaUseItemHotspots[i].y;
   const int drawX=gaUseItemHotspots[i].x;
   context.frame=gaUseItemHotspots[i].frame+(gaUseItemHotspots[i].hovered!=0);
   sub_004F6480(&context,drawX,drawY,-1,5,0);
  }
  int mouseX=sub_00468730_GetMouseX();
  int mouseY=sub_00468740_GetMouseY();
  if(mouseX<320 && mouseY<gnScreenHeight-48){
   for(int i=0;i<gnHotspotCount;++i){
    D2HotspotStrc* spot=&gaUseItemHotspots[i];
    if(mouseX>=spot->left && mouseX<=spot->right && mouseY>=spot->top && mouseY<=spot->bottom){
     unsigned short textIndex=spot->textIndex;
     if(textIndex==4017){
      if(gnUseItemPanelMode==0)textIndex=3401;
      if(NPCMENU_GetUseItemMode()==511)textIndex=22748;
      else if(NPCMENU_GetUseItemMode()==512)textIndex=22749;
     }
     const Unicode* text=D2LANG_GetStringFromTblIndex(textIndex);
     int width=D2Win_10121_GetTextWidth(text);
     AUTOMAP_DrawFramedBox(spot->tooltipX-(width/2)+10,spot->tooltipY-D2Win_10125()-42,width+12,D2Win_10125()+6,0,2);
     D2Win_10117_DrawText(text,spot->tooltipX-(width/2)+16,spot->tooltipY-38,0,0);
    }
   }
  }
  if(gnUseItemPanelMode==1){
   unsigned short textIndex=10076;
   if(NPCMENU_GetUseItemMode()==511)textIndex=22750;
   else if(NPCMENU_GetUseItemMode()==512)textIndex=22747;
   const Unicode* panelText=D2LANG_GetStringFromTblIndex(textIndex);
   int lineCount;
   D2SplittedTextStrc* line=D2WINFONT_SplitText(panelText,&lineCount,300);
   if(line){
    int y=30;
    do {
    int lineWidth=D2Win_10121_GetTextWidth(line->text);
    D2Win_10117_DrawText(line->text,160-lineWidth/2,y,4,0);
    D2SplittedTextStrc* next=line->next;
    FOG_Free(line->text,gszUseItemCpp,707,0);
    FOG_Free(line,gszUseItemCpp,708,0);
    y+=20;line=next;
    } while(line);
   }
  }
 }
 if(gpUseItemConfirmDialog)sub_004B8100_DrawControl(gpUseItemConfirmDialog);
 D2Win_10127_SetFont(oldFont);
}

// 0x004C01E0
void __cdecl USEITEM_DrawPanelUnit()
{
    if (gnUseItemDialogState)
    {
        if (CUNIT_IsPlayerDeadOrMissing())
        {
            sub_004C0090();
            return;
        }

        USEITEM_DrawUseItemPanel();
        if (gnUseItemDialogState == 2)
        {
            D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnAnvilItemId, 4);
            if (pUnit)
            {
                D2PanelGfxStrc tGfx;
                int nOut;
                memset(&tGfx, 0, sizeof(tGfx));
                if (sub_004DBB50(&tGfx, pUnit, 0, 0, 0, &nOut, 1, -1) && sub_006001F0(&tGfx, 0, 1) && tGfx.f_3C)
                {
                    unsigned int nWidth;
                    unsigned int nHeight;
                    sub_004DBEA0(pUnit, 0, 0, &nWidth, &nHeight);
                    UNITS_ChangeAnimMode(pUnit, 0);
                    int nOffsetY = 0;
                    if (nHeight < 0x70)
                    {
                        nOffsetY = (0x72 - nHeight) >> 1;
                    }
                    GFX_DrawItemCel(pUnit, 0xA7 - (nWidth >> 1), nOffsetY + 0x6A);
                    UNITS_ChangeAnimMode(pUnit, 4);
                }
            }
        }
    }
    else
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x31D);
        exit(-1);
    }
}

// 0x004C02F0
int __cdecl USEITEM_ClosePanel()
{
    int mode = gnUseItemDialogState;
    if (mode == 3) return 0;
    if (mode == 2) {
        D2UnitStrc* player = sub_00463DD0_GetPlayerUnit();
        D2InventoryStrc* inventory = player ? player->pInventory : 0;
        CURSOR_SetCursorItemState(player ? INVENTORY_GetCursorItem(inventory) : 0);
    }
    sub_004B9A00(1, 0, 0, 0, 0);
    if (!gnUseItemPanelMode) {
        D2UnitStrc* player = sub_00463DD0_GetPlayerUnit();
        int id = !player ? -1 : player->dwUnitId;
        int value = gnAnvilObjectId;
        MSG_SendFourDwords(0x44, id, value, 0, 2);
        USEITEM_CloseUseItemPanel();
    } else {
        sub_004B3FE0();
        USEITEM_CloseUseItemPanel();
    }
    return 1;
}

// 0x004BFC50
void __stdcall USEITEM_ClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    const int nY = pMsg->nYpos;
    const int nX = pMsg->nXpos;
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    if (GetTickCount() - gdwUseItemClickTick < 0x190)
        return;
    gdwUseItemClickTick = GetTickCount();
    int bHandled;
    if (gnUseItemDialogState == 1)
    {
        bHandled = WARDENCLIENT_HandlePanelAreaClick(pMsg);
    }
    else if (gnUseItemDialogState == 2)
    {
        bHandled = sub_00489190(pMsg);
    }
    else
    {
        goto check_item;
    }
    if (bHandled)
        return;
    USEITEM_HitTestHotspots(nX, nY);
check_item:
    D2UnitStrc* pItem = GetCursorItem_Inline();
    if (!pItem)
        return;
    if (nX < 0x7B || nX > 0x7B + 0x58 || nY < 0x6A || nY > 0x6A + 0x72)
        return;
    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pTxt)
        return;
    if (ITEMS_CheckItemFlag(pItem, 0x10, 0x210, ".\\UI\\UseItem.cpp"))
    {
        if (gnUseItemPanelMode == 1)
        {
            if (NPCMENU_GetUseItemMode() == 0x9A && ITEMS_CanBeImbued(pItem))
                goto use_item;
            if (NPCMENU_GetUseItemMode() == 0x1FF && sub_0062C770(pItem))
                goto use_item;
            if (NPCMENU_GetUseItemMode() == 0x200 && sub_0062C6A0(pItem))
                goto use_item;
        }
        else if (!gnUseItemPanelMode && pTxt->dwCode == 0x20747368)
        {
            goto use_item;
        }
    }
    sub_004B9A00(3, 0, 0, 0, 0);
    return;
use_item:
    USEITEM_ToggleUseMode(pItem);
}

// 0x004BFDB0
void __stdcall USEITEM_EatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004C0080
void __cdecl sub_004C0080_Return()
{
}

// 0x004C0090
void __cdecl USEITEM_CloseUseItemPanel()
{
    gnUseItemDialogState = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    USEITEM_ToggleUseMode(pPlayer ? INVENTORY_GetCursorItem(pPlayer->pInventory) : 0);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaUseItemHandlers, 8);
    if (gpUseItemConfirmDialog)
    {
        DIALOG_DestroyDialog(gpUseItemConfirmDialog);
        gpUseItemConfirmDialog = 0;
    }
    UI_SetUIVar(0xE, 1, 0);
    sub_00467430(0);
}

// 0x004C0150
void __stdcall USEITEM_OnPanelCloseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    const int nMode = gnUseItemDialogState;
    if (nMode != 1)
    {
        if (nMode != 2)
        {
            return;
        }

        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        D2InventoryStrc* pInventory = pPlayer ? pPlayer->pInventory : 0;
        CURSOR_SetCursorItemState(pPlayer ? INVENTORY_GetCursorItem(pInventory) : 0);
    }

    if (!gnUseItemPanelMode)
    {
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        const int nUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
        const int nValue = gnAnvilObjectId;
        MSG_SendFourDwords(0x44, nUnitId, nValue, 0, 2);
        sub_004C0090();
    }
    else
    {
        sub_004B3FE0();
        sub_004C0090();
    }
}

// 0x004C0380
void __cdecl USEITEM_OpenPanel()
{
    UI_CloseUIVars(0, 0);
    gnUseItemDialogState = 1;
    gdwUseItemClickTick = GetTickCount();
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaUseItemHandlers, 8);
    INV_SetNpcStateTrade();
    if (!UI_SetUIVar(14, 0, 0))
    {
        if (!gnUseItemPanelMode)
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            MSG_SendFourDwords(0x44, !pPlayer ? -1 : pPlayer->dwUnitId, gnAnvilObjectId, 0, 2);
            sub_004C0090();
        }
        else
        {
            sub_004B3FE0();
            sub_004C0090();
        }
        return;
    }

    GAME_ResetMouseState();
    D2RectStrc tRect;
    tRect.nTop = 0x5B;
    tRect.nLeft = 0x6B;
    tRect.nBottom = 0x116;
    tRect.nRight = 0xDE;
    sub_00467430(&tRect);
}

int __stdcall ROSTERPETS_HandleRectClick(SMSGHANDLER_PARAMS* pMsg); // 0x004890B0

static int USEITEM_ClickHotspots(int nX, int nY); // 0x004C0450

// 0x004C0440
int __cdecl sub_004C0440_Thunk()
{
    return USEITEM_ClosePanel();
}

// 0x004C0450
static int USEITEM_ClickHotspots(int nX, int nY)
{
    int bHit = 0;
// build: symbol ?gnHotspotCount@* 0x007278FC
    for (int i = 0; i < gnHotspotCount; i++)
    {
        if (gaUseItemHotspots[i].pressed && nX >= gaUseItemHotspots[i].left && nX <= gaUseItemHotspots[i].right && nY >= gaUseItemHotspots[i].top && nY <= gaUseItemHotspots[i].bottom)
        {
            sub_004B9A00(1, 0, 0, 0, 0);
            if (i == 0)
            {
                USEITEM_ShowConfirmation();
                bHit = 1;
            }
            else
            {
                USEITEM_ClosePanel();
                bHit = 1;
            }
        }
    }
    for (int i = 0; i < gnHotspotCount; i++)
    {
        gaUseItemHotspots[i].pressed = 0;
        gaUseItemHotspots[i].hovered = 0;
    }
    return bHit;
}

// 0x004C04E0
void __stdcall USEITEM_OnHotspotClick(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if (gnUseItemDialogState == 2)
    {
        if (USEITEM_ClickHotspots(nX, nY))
            return;
        if (sub_00489190(pMsg))
            USEITEM_ClosePanel();
        return;
    }
    if (ROSTERPETS_HandleRectClick(pMsg))
        return;
    USEITEM_ClickHotspots(nX, nY);
}

// 0x004C0550
void __fastcall sub_004C0550(D2PacketRecord7Strc* pPacket)
{
    switch (pPacket->nType)
    {
    case 0:
        gnFlag_007C5470 = 0;
        gnValue_007C547C = pPacket->nValue;
        USEITEM_OpenPanel();
        return;

    case 1:
        sub_004C0090();
        return;

    case 4:
        gnUseItemDialogState = 2;
        if (gpUseItemConfirmDialog)
        {
            DIALOG_DestroyDialog(gpUseItemConfirmDialog);
            gpUseItemConfirmDialog = 0;
        }
        return;

    case 5:
    {
        D2InventoryStrc* pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
        INVENTORY_SetCursorItem(pInventory, 0);
    }
        if (pPacket->bFlag)
        {
            sub_004B9A00(5, 0, 0, 0, 0);
        }
        else
        {
            sub_004B9A00(3, 0, 0, 0, 0);
        }
        sub_004C0090();
        return;

    case 6:
    case 7:
        sub_004C0090();
        NPCMENU_CloseNpc2();
        return;

    default:
        D2_ASSERT(0, 0x354);
    }
}

// 0x004C0620
void __fastcall USEITEM_OpenNpcItemPanel(int nValue)
{
    gnUseItemPanelMode = 1;
    gnGlobal_007C5478 = nValue;
    USEITEM_OpenPanel();
}

#include "gen/data/Source/D2Client/UI/useitem.inc"
