#include "D2Client.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2CelContext.h"

struct D2CelFileStrc;


void __cdecl sub_00477DD0();                                                                                // 0x00477DD0
void __stdcall UI_DrawCelPair(int bFirst);                                                        // 0x0045FBC0
void __cdecl SCMD_DrawLoadingTexts();                                                               // 0x0045FC60
void __stdcall VIEW_DrawPanelCel(int nFrame);                                                       // 0x0045FD20
void __cdecl UI_DrawCenteredString();                                                             // 0x0045FD80
void __cdecl CURSOR_DrawCursor(); // 0x004684C0
void __cdecl SOUNDHDR_TickSound();                                                                           // 0x00482C20
void __fastcall sub_00460190_DrawFrame(int nUnused);                                                        // 0x00460190
D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType);                             // 0x004788B0
void __fastcall GAME_SetClientState(int nState);                                                    // 0x0044C930
int __cdecl WINDOW_GetWindow();                                                                                // 0x004F59A0
void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0
int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0
void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount);     // 0x00451E10
void __cdecl UI_FreeCels();                                                                       // 0x00460430

extern D2MsgHandlerEntryStrc gaPopupHandlers[];                                                      // 0x00711D40
extern D2MsgHandlerEntryStrc gaOkCancelHandlers[];                                                      // 0x00711D70
static D2CelFileStrc* gpPopupOkCelA;                                                                          // 0x007A523C
static D2CelFileStrc* gpOkCancelButtonCel;                                                                          // 0x007A5240
static D2CelFileStrc* gpPopupOkCelB;                                                                          // 0x007A5244
static int gbPopupOkPressed;                                                                               // 0x007A524C
static int gbPopupDismissed;                                                                                      // 0x007A5254
static int gbOkCancelAccepted;                                                                                      // 0x007A5258
static int gbOkCancelCancelled;                                                                                      // 0x007A525C

// 0x0045FB40
void __cdecl sub_0045FB40_LoadPopupCels()
{
    gpPopupOkCelA = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpPopupOkCelB = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpOkCancelButtonCel = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
}



struct Unicode;

struct D2CelContextStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __cdecl GAME_LoadLoadingPalette(); // 0x00454740

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern int gnScreenWidth; // 0x0071146C

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C




// 0x0045FBC0
void __stdcall UI_DrawCelPair(int bFirst)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (bFirst)
        tContext.pCellFile = gpPopupOkCelA;
    else
        tContext.pCellFile = gpPopupOkCelB;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + 0xBC, 0x148 - gnPanelOffsetY, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x1BC, 0x148 - gnPanelOffsetY, -1, 5, 0);
}



class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};



// 0x0045FC60
void __cdecl SCMD_DrawLoadingTexts()
{
    const int nOldFont = D2Win_10127_SetFont(1);
    TEXT_DrawCenteredText(gnScreenWidth / 2 - 0x84, 0xBE - gnPanelOffsetY, gnPanelOffsetX + 0x1C4, D2LANG_GetStringFromTblIndex(0x1430), 0);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        TEXT_DrawCenteredText(gnScreenWidth / 2 - 0x84, 0xCD - gnPanelOffsetY, gnPanelOffsetX + 0x1C4, D2LANG_GetStringFromTblIndex(0x5578), 0);
    else
        TEXT_DrawCenteredText(gnScreenWidth / 2 - 0x84, 0xCD - gnPanelOffsetY, gnPanelOffsetX + 0x1C4, D2LANG_GetStringFromTblIndex(0x1431), 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x0045FD20
void __stdcall VIEW_DrawPanelCel(int nFrame)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpOkCancelButtonCel;
    tContext.nFrame = nFrame;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x110, 0x13E - gnPanelOffsetY, -1, 5, 0);
}

// 0x0045FD80
void __cdecl UI_DrawCenteredString()
{
    const int nOldFont = D2Win_10127_SetFont(1);
    TEXT_DrawCenteredText(gnPanelOffsetX + 0x110, 0x136 - gnPanelOffsetY, gnPanelOffsetX + 0x170, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x0045FDD0
int __cdecl INV_IsPopupDismissed()
{
    return gbPopupDismissed != 0;
}

// 0x0045FDE0
void __cdecl sub_0045FDE0_DrawLoadingScreen()
{
    if (WINDOW_GetState())
        return;
    if (!D2GFX_StartDraw(1, 0, 0, 0))
        return;
    D2GFX_ClearScreen(0);
// build: symbol ?D2Win_10179_UpdatePaletteFlash@* 0x004FB0D0
    D2Win_10179_UpdatePaletteFlash();
    UI_DrawCelPair(1);
    SCMD_DrawLoadingTexts();
    VIEW_DrawPanelCel(gbPopupOkPressed);
    UI_DrawCenteredString();
    CURSOR_DrawCursor();
    D2GFX_EndScene();
}

static int gbCinematicExpansion; // 0x007A5238

struct SMSGHANDLER_PARAMS;


int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

static int gbPopupMouseDown; // 0x007A5248

static int gbPopupCancelPressed; // 0x007A5250

// 0x0045FE30
void __stdcall AUTOMAP_PopupButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nLeft = gnPanelOffsetX + 0x110;
    int nBottom = 0x136 - gnPanelOffsetY;
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gbPopupOkPressed = 1;
        gbPopupMouseDown = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0045FED0
void __stdcall ROSTERPETS_HandlePopupButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    gbPopupOkPressed = 0;
    if (gbPopupMouseDown)
    {
        int nLeft = gnPanelOffsetX + 0x110;
        int nBottom = 0x136 - gnPanelOffsetY;
        int nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gbPopupDismissed = 1;
            gbPopupMouseDown = 0;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0045FF70
void __stdcall SCMD_ConfirmPopup(SMSGHANDLER_PARAMS* pMsg)
{
    gbPopupDismissed = 1;
    gbPopupMouseDown = 0;
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0045FFB0
void __stdcall SCMD_HandlePopupEscape(SMSGHANDLER_PARAMS* pMsg)
{
    gbPopupDismissed = 0;
}

// 0x0045FFC0
void __cdecl UI_DrawCenteredStrings()
{
    const int nOldFont = D2Win_10127_SetFont(1);
    TEXT_DrawCenteredText(gnScreenWidth / 2 - 0x84, 0xBE - gnPanelOffsetY, gnPanelOffsetX + 0x1C4, D2LANG_GetStringFromTblIndex(0x1430), 0);
    unsigned short nString = 0x1432;
    if (gbCinematicExpansion)
        nString = 0x5578;
    TEXT_DrawCenteredText(gnScreenWidth / 2 - 0x84, 0xCD - gnPanelOffsetY, gnPanelOffsetX + 0x1C4, D2LANG_GetStringFromTblIndex(nString), 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x00460060
void __stdcall VIEW_DrawPanelCels(int nFrame1, int nFrame2)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpOkCancelButtonCel;
    tContext.nFrame = nFrame1;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + 0xCE, 0x13E - gnPanelOffsetY, -1, 5, 0);
    tContext.nFrame = nFrame2;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x152, 0x13E - gnPanelOffsetY, -1, 5, 0);
}

// 0x004600F0
void __cdecl UI_DrawCenteredStringPair()
{
    const int nOldFont = D2Win_10127_SetFont(1);
    TEXT_DrawCenteredText(gnPanelOffsetX + 0xCE, 0x136 - gnPanelOffsetY, gnPanelOffsetX + 0x12E, D2LANG_GetStringFromTblIndex(0x13EE), 0);
    TEXT_DrawCenteredText(gnPanelOffsetX + 0x152, 0x136 - gnPanelOffsetY, gnPanelOffsetX + 0x1B2, D2LANG_GetStringFromTblIndex(0x13EF), 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x00460170
int __cdecl PLAYER_IsOkCancelDone()
{
    if (gbOkCancelAccepted || gbOkCancelCancelled)
        return 1;
    return 0;
}

// 0x00460190
void __cdecl sub_00460190_DrawFrame()
{
    if (WINDOW_GetState())
        return;
    if (!D2GFX_StartDraw(1, 0, 0, 0))
        return;
    D2GFX_ClearScreen(0);
// build: symbol ?D2Win_10179_UpdatePaletteFlash@* 0x004FB0D0
    D2Win_10179_UpdatePaletteFlash();
    UI_DrawCelPair(0);
    UI_DrawCenteredStrings();
    VIEW_DrawPanelCels(gbPopupOkPressed, gbPopupCancelPressed);
    UI_DrawCenteredStringPair();
    CURSOR_DrawCursor();
    D2GFX_EndScene();
}

// 0x004601F0
void __stdcall AUTOMAP_PopupTwoButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nLeft = gnPanelOffsetX + 0xCE;
    int nBottom = 0x136 - gnPanelOffsetY;
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gbPopupOkPressed = 1;
        gbPopupMouseDown = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    nLeft = gnPanelOffsetX + 0x152;
    nBottom = 0x136 - gnPanelOffsetY;
    nX = sub_00468730();
    nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
    {
        gbPopupCancelPressed = 1;
        gbPopupMouseDown = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004602E0
void __stdcall AUTOMAP_PopupTwoButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gbPopupOkPressed = 0;
    gbPopupCancelPressed = 0;
    if (gbPopupMouseDown)
    {
        int nLeft = gnPanelOffsetX + 0xCE;
        int nBottom = 0x136 - gnPanelOffsetY;
        int nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gbOkCancelAccepted = 1;
            gbPopupMouseDown = 0;
        }
        nLeft = gnPanelOffsetX + 0x152;
        nBottom = 0x136 - gnPanelOffsetY;
        nX = sub_00468730();
        nY = sub_00468740();
        if (nX >= nLeft && nX <= nLeft + 0x60 && nY >= nBottom - 0x20 && nY <= nBottom)
        {
            gbOkCancelCancelled = 1;
            gbPopupMouseDown = 0;
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004603E0
void __stdcall SCMD_ConfirmOkCancelPopup(SMSGHANDLER_PARAMS* pMsg)
{
    gbOkCancelAccepted = 1;
    gbPopupMouseDown = 0;
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x00460420
void __stdcall sub_00460420_SetCancelFlag(int nArg)
{
    gbOkCancelCancelled = 1;
}

// 0x00460430
void __cdecl UI_FreeCels()
{
    if (gpPopupOkCelA)
    {
        ARCHIVE_FreeClientCellFile(gpPopupOkCelA);
        gpPopupOkCelA = 0;
    }
    if (gpPopupOkCelB)
    {
        ARCHIVE_FreeClientCellFile(gpPopupOkCelB);
        gpPopupOkCelB = 0;
    }
    if (gpOkCancelButtonCel)
    {
        ARCHIVE_FreeClientCellFile(gpOkCancelButtonCel);
        gpOkCancelButtonCel = 0;
    }
    GAME_LoadLoadingPalette();
}

// 0x00460480
void __fastcall PLAYER_SetCinematicExpansion(int bExpansion)
{
    gbCinematicExpansion = bExpansion;
}

// 0x00460490
int __stdcall sub_00460490_DrawPopup(int nArg)
{
    sub_00477DD0();
    if (!WINDOW_GetState() && D2GFX_StartDraw(1, 0, 0, 0))
    {
        D2GFX_ClearScreen(0);
// build: symbol ?D2Win_10179_UpdatePaletteFlash@* 0x004FB0D0
        D2Win_10179_UpdatePaletteFlash();
        UI_DrawCelPair(1);
        SCMD_DrawLoadingTexts();
        VIEW_DrawPanelCel(gbPopupOkPressed);
        UI_DrawCenteredString();
        CURSOR_DrawCursor();
        D2GFX_EndScene();
    }
    SOUNDHDR_TickSound();
    return gbPopupDismissed != 0;
}

// 0x00460500
int __cdecl sub_00460500_RunPopup()
{
    gbPopupDismissed = 0;
// build: symbol ?D2Win_10176_StartPaletteFlash@* 0x004FB130
    D2Win_10176_StartPaletteFlash(0);
    gpPopupOkCelA = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpPopupOkCelB = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpOkCancelButtonCel = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    GAME_SetClientState(1);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaPopupHandlers, 4);
    SCMD_RunMessageLoop(sub_00460490_DrawPopup);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaPopupHandlers, 4);
    GAME_SetClientState(0);
    UI_FreeCels();
    return 1;
}

// 0x004605A0
int __cdecl sub_004605A0_RunPopup()
{
    gbPopupDismissed = 0;
    D2Win_10176_StartPaletteFlash(0);
    gpPopupOkCelA = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpPopupOkCelB = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpOkCancelButtonCel = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    GAME_SetClientState(1);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaPopupHandlers, 4);
    SCMD_RunMessageLoop(sub_00460490_DrawPopup);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaPopupHandlers, 4);
    GAME_SetClientState(0);
    UI_FreeCels();
    return 1;
}

// 0x00460640
int __stdcall sub_00460640_PaintConfirmFrame(int nArg)
{
    sub_00477DD0();
    sub_00460190_DrawFrame(1);
    SOUNDHDR_TickSound();
    if (!gbOkCancelAccepted && !gbOkCancelCancelled)
        return 0;
    return 1;
}

// 0x00460680
int __cdecl sub_00460680_RunOkCancel()
{
    int nResult = 1;
    gbOkCancelCancelled = 0;
    gbOkCancelAccepted = 0;
    D2Win_10176_StartPaletteFlash(0);
    gpPopupOkCelA = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpPopupOkCelB = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Bigmenu\\popupok", 0);
    gpOkCancelButtonCel = ARCHIVE_LoadClientCellFile("Data\\Global\\UI\\Menu\\okcancelbtn", 0);
    sub_004FB480_SetActA(0);
    GAME_SetClientState(2);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaOkCancelHandlers, 4);
    SCMD_RunMessageLoop(sub_00460640_PaintConfirmFrame);
    if (gbOkCancelCancelled)
        nResult = 0;
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaOkCancelHandlers, 4);
    GAME_SetClientState(0);
    UI_FreeCels();
    return nResult;
}

#include "gen/data/Source/D2Client/Unknown_00460420.inc"
