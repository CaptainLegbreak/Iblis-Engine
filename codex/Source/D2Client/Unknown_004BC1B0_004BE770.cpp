#include "D2Client.h"
#include "D2Unicode.h"
#include "D2CelContext.h"
#include "D2StormTypes.h"
#include "D2ListBoxLine.h"

class UIWidget;
class ListBoxImplementation;
class ListBoxWrapper;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

int __fastcall PANEL_CountLinesInView(ListBoxImplementation* pListBox); // 0x004BE340

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern void* gpListBoxSliderCel; // 0x007C546C

#pragma pack(push, 2)

class UIWidget
{
public:
    virtual ~UIWidget() = 0;
    virtual void Draw() = 0;
    virtual int OnMouseWheel(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyDown(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyRight(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyLeft(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int GetValue() = 0;

    static void* operator new(unsigned int nSize)
    {
// build: symbol ?gszNew@* 0x006CC82C
        return SMemAlloc(nSize, gszNew, -1, 0);
    }

    static void operator delete(void* pMemory)
    {
        if (pMemory)
        {
            SMemFree(pMemory, "delete", -1, 0);
        }
    }

    int unk0x04;
};




struct D2ListScrollStrc
{
    int nX;
    int nY;
    int nRows;

    int DrawRows(D2CelContextStrc* pContext);
};

// 0x004BF8C0
class ListBoxImplementation : public UIWidget
{
public:
    ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
        int nCallback, bool bLargeFont);

    virtual ~ListBoxImplementation();
    virtual void Draw();
    virtual int OnMouseWheel(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyRight(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyLeft(SMSGHANDLER_PARAMS* pMsg);
    virtual int GetValue();
    virtual void sub_004BE110_UpdateScrollBar();
    virtual int sub_004BE0A0_GetLineCount();
    virtual void sub_004BE0B0_Clear();
    virtual void sub_004BE500_AddLine(const Unicode* wszText0, const Unicode* wszText1, const Unicode* wszText2,
        const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5, int nArg20, int nData,
        int bUseDefault, int nArg2C);

    void DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor);
    int HitTestScrollDown(SMSGHANDLER_PARAMS* pMsg);
    int HitTestScrollTrack(SMSGHANDLER_PARAMS* pMsg);
    int HitTestScrollUp(SMSGHANDLER_PARAMS* pMsg);
    int sub_004BE810_HitTestRect(SMSGHANDLER_PARAMS* pMsg);
    void sub_004BE8D0_ClampTopToSelection();
    int ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg); // 0x004BF2F0
    int sub_004BEA50_HitTestEntry(SMSGHANDLER_PARAMS* pMsg);
    int GetListEntryData(int nIndex);

    D2ListBoxLineStrc aLines[0x80];
    int f_180708;
    int f_18070C;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int f_18071C;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int f_180730;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    void (__cdecl* pfnCallback)();
    int f_18074E;
    int unk0x180752;
    int unk0x180756;
    D2ListScrollStrc tBar;
    int nScrollStep;
    int nArg10;
    unsigned int nRepeatTicks;
    int nState;
};

// 0x004BED10
class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18, int nCallback,
        bool bLargeFont);
    virtual ~ListBoxWrapper();

    virtual void Draw();
    virtual int OnMouseWheel(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyRight(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyLeft(SMSGHANDLER_PARAMS* pMsg);
    virtual int GetValue();
    virtual void sub_004BEDE0_ForwardSlot3C(const Unicode* wszText0, const Unicode* wszText1,
        const Unicode* wszText2, const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5,
        int nArg20, int nData, int bUseDefault, int nArg2C);
    virtual int sub_004BEDF0_ForwardGetEntryData(int nIndex);
    virtual int sub_004BEE00_Slot14();
    virtual void sub_004BEE10_Slot15();

    ListBoxImplementation* pImpl;
};

#pragma pack(pop)

// 0x004BE770
int ListBoxImplementation::HitTestScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > tBar.nX && nMouseX < tBar.nX + 0x10)
    {
        const int nBottom = tBar.nY + tBar.nRows * 12;
        if (nMouseY > nBottom - 12 && nMouseY < nBottom)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004BE7C0
int ListBoxImplementation::HitTestScrollTrack(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > tBar.nX && nMouseX < tBar.nX + 0x10 && nMouseY < tBar.nY + tBar.nRows * 12 - 12 && nMouseY > tBar.nY)
    {
        return 1;
    }
    return 0;
}
