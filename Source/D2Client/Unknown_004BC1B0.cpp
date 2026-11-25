#include "D2Client.h"
#include "D2Unicode.h"
#include "D2CelContext.h"
#include "D2StormTypes.h"
#include "D2ListBoxLine.h"
#include "D2ClientTextPanel.h"

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

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

struct ListBoxView
{
    void* pVtable;
    int unk0x04;
    char aLines[0x180700];
    int nRectX;
    int nRectY;
    int nRectWidth;
    int nRectHeight;
    int nLineHeight;
    int bMouseDown;
    int bTopPressed;
    int bBottomPressed;
    int bRowsPressed;
    int nPressY;
    int nTopIndex;
    int nCallbackRow;
    int nSelectedIndex;
    int nTextCount;
    int nArg14;
    int nArg18;
    unsigned short nEntryCount;
    int pfnCallback;
    int nVisibleRows;
    int nThumbStart;
    int nThumbEnd;
    int nX;
    int nY;

    void sub_004BE8D0_Refresh();                                                                            // 0x004BE8D0
    int ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg);
};

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

// build: symbol ??_7UIWidget@@6B@ 0x006DA6C0
// build: symbol ??_7ListBoxImplementation@@6B@ 0x006DAAEC
// build: symbol ??_7ListBoxWrapper@@6B@ 0x006DAAA4
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// build: symbol ??0D2ListBoxLineStrc@@QAE@XZ 0x004BEE30
// build: symbol ??3UIWidget@@SAXPAX@Z 0x004053F0
// 0x004BE080
UIWidget::~UIWidget()
{
}

// build: symbol ??_GListBoxImplementation@@UAEPAXI@Z 0x004BF8C0
// build: symbol ??_GListBoxWrapper@@UAEPAXI@Z 0x004BED10


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
    int HitTestScrollDown(SMSGHANDLER_PARAMS* pMsg); // 0x004BE770
    int HitTestScrollTrack(SMSGHANDLER_PARAMS* pMsg); // 0x004BE7C0
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

typedef char check_line_size[(sizeof(D2ListBoxLineStrc) == 0x300E) ? 1 : -1];

typedef char check_listbox_size[(sizeof(ListBoxImplementation) == 0x180776) ? 1 : -1];

void __stdcall sub_00646010_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460C0_Empty(int nUnused)
{
}

void __stdcall sub_006460D0_Empty(int nUnused1, int nUnused2, int nUnused3)
{
}

void __stdcall sub_006460E0_Empty(int nUnused)
{
}

// 0x004BE020
void __cdecl TEXT_LoadTextSliderCel()
{
    char szPath[0x104];
    sprintf(szPath, "%s\\ui\\menu\\textslid", gszDataGlobal);
    gpListBoxSliderCel = ARCHIVE_LoadClientCellFile(szPath, 0);
}

// 0x004BE060
void __cdecl sub_004BE060()
{
    if (gpListBoxSliderCel)
    {
        ARCHIVE_FreeClientCellFile(gpListBoxSliderCel);
        gpListBoxSliderCel = 0;
    }
}


// 0x004BE090
ListBoxImplementation::~ListBoxImplementation()
{
}

// 0x004BE0A0
int ListBoxImplementation::sub_004BE0A0_GetLineCount()
{
    return nEntryCount;
}

// 0x004BE0B0
void ListBoxImplementation::sub_004BE0B0_Clear()
{
    for (int i = 0; i < nEntryCount; ++i)
    {
        aLines[i].wszText0[0].wChar = 0;
        aLines[i].wszText1[0].wChar = 0;
        aLines[i].wszText2[0].wChar = 0;
        aLines[i].wszText3[0].wChar = 0;
        aLines[i].wszText4[0].wChar = 0;
        aLines[i].wszText5[0].wChar = 0;
    }
    nEntryCount = 0;
}

// 0x004BE110
void ListBoxImplementation::sub_004BE110_UpdateScrollBar()
{
    const int nEntries = nEntryCount;
    int nHeight = 0;
    unk0x180752 = 0;
    unk0x180756 = 0;
    f_18074E = 0;
    for (int i = f_180730; i < nEntryCount; ++i)
    {
        if (aLines[i].wszText0[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].wszText1[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].wszText2[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].wszText3[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].wszText4[0].wChar)
        {
            nHeight += nScrollStep;
        }
        if (aLines[i].wszText5[0].wChar)
        {
            nHeight += nScrollStep;
        }
        nHeight += nArg10;
        if (nHeight < nRectHeight - 20)
        {
            ++f_18074E;
        }
    }

    if (nEntries <= f_18074E)
    {
        return;
    }

    const int nRatio = (f_18074E << 7) / nEntries;
    int nStart;
    int nEnd;
    if (!f_180730)
    {
        nStart = 0;
        nEnd = (unsigned int)(nLineHeight * nRatio) >> 7;
    }
    else if (f_180730 >= nEntries - f_18074E)
    {
        nStart = nLineHeight - ((unsigned int)(nLineHeight * nRatio) >> 7);
        nStart = nLineHeight < nStart ? nLineHeight : nStart;
        nEnd = nLineHeight;
    }
    else
    {
        const int nThumb = (unsigned int)(nLineHeight * nRatio) >> 7;
        nStart = nLineHeight * f_180730 / nEntries;
        nStart = nStart < 0 ? 0 : nStart;
        nEnd = nLineHeight < nThumb + nStart ? nLineHeight : nThumb + nStart;
    }

    const int nTop = tBar.nY + 13;
    const int nLeft = tBar.nX - 1;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpListBoxSliderCel;
    tContext.nDirection = 0;
    tContext.nFrame = 16;
    sub_004F6480(&tContext, nLeft, nTop + 12 * nStart, -1, 5, 0);
    tContext.nFrame = 14;
    int nRow = nStart;
    for (; nRow < nEnd; ++nRow)
    {
        sub_004F6480(&tContext, nLeft, nTop + 12 * (nRow + 1), -1, 5, 0);
    }
    tContext.nFrame = 15;
    sub_004F6480(&tContext, nLeft, nTop + 12 * (nRow + 1), -1, 5, 0);
    unk0x180752 = nStart;
    unk0x180756 = nEnd;
}

// 0x004BE340
int __fastcall PANEL_CountLinesInView(D2TextPanelStrc* pPanel)
{
    const int nLineCount = pPanel->nLineCount;
    int nTotal = 0;
    for (int i = 0; i < nLineCount; ++i)
    {
        if (i >= pPanel->nFirstLine && i < nLineCount)
        {
            for (int k = 0; k < 6; ++k)
            {
                if (pPanel->pLines[i].wszText[k][0].wChar)
                {
                    nTotal += *(int*)pPanel->nLineStep;
                }
            }
            nTotal += *(int*)pPanel->nLineGap;
        }

        if (nTotal > pPanel->nHeight - 20)
        {
            i -= pPanel->nFirstLine;
            if (i < 1)
            {
                i = 1;
            }
            return i;
        }
    }

    return nLineCount;
}


// 0x004BE410
void ListBoxImplementation::DrawClippedText(const Unicode* wszSource, int nX, int nY, int nColor)
{
    Unicode wszText[1024];
    sub_005267E0(wszText, wszSource);
    if (D2Win_10123(wszText, sub_00526800(wszText)) < nRectWidth - 0x32)
    {
        D2Win_10117_DrawText(wszText, nX, nY, nColor, 0);
        return;
    }

    while (D2Win_10123(wszText, sub_00526800(wszText)) > nRectWidth - 0x32)
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
    D2Win_10117_DrawText(wszText, nX, nY, nColor, 0);
}

// 0x004BE500
void ListBoxImplementation::sub_004BE500_AddLine(const Unicode* wszText0, const Unicode* wszText1, const Unicode* wszText2,
    const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5, int nArg20, int nData, int bUseDefault,
    int nArg2C)
{
    if (nEntryCount >= 0x80)
    {
        return;
    }

    aLines[nEntryCount].unk0x3002 = nArg20;
    if (nSelectedIndex == -1)
    {
        nSelectedIndex = 0;
    }
    if (wszText0)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText0, wszText0, 0x3FF);
        aLines[nEntryCount].wszText0[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText1)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText1, wszText1, 0x3FF);
        aLines[nEntryCount].wszText1[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText2)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText2, wszText2, 0x3FF);
        aLines[nEntryCount].wszText2[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText3)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText3, wszText3, 0x3FF);
        aLines[nEntryCount].wszText3[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText4)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText4, wszText4, 0x3FF);
        aLines[nEntryCount].wszText4[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (wszText5)
    {
        Unicode::strncpy(aLines[nEntryCount].wszText5, wszText5, 0x3FF);
        aLines[nEntryCount].wszText5[0x3FF].wChar = 0;
        ++nTextCount;
    }
    if (bUseDefault)
    {
        aLines[nEntryCount].nData = nArg14;
    }
    else
    {
        aLines[nEntryCount].nData = nData;
    }
    aLines[nEntryCount].nFont = nArg2C;
    ++nEntryCount;
}

// 0x004BE720
int ListBoxImplementation::HitTestScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > tBar.nX && nMouseX < tBar.nX + 0x10 && nMouseY > tBar.nY - 12 && nMouseY < tBar.nY)
    {
        return 1;
    }
    return 0;
}

// 0x004BE810
int ListBoxImplementation::sub_004BE810_HitTestRect(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX > f_180708 && nMouseX < f_180708 + nRectWidth && nMouseY > f_18070C && nMouseY < f_18070C + nRectHeight)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?OnMouseWheel@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BE860
// 0x004BE860
int ListBoxImplementation::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    if ((short)pMsg->wParamHigh > 0)
    {
        nSelectedIndex = f_180730;
        MsgSlot07(pMsg);
    }
    else if ((short)pMsg->wParamHigh < 0)
    {
        nSelectedIndex = f_180730 + f_18074E - 1;
        MsgSlot08(pMsg);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    return 1;
}

// 0x004BE8D0
void ListBoxImplementation::sub_004BE8D0_ClampTopToSelection()
{
    if (nSelectedIndex < f_180730)
    {
        f_180730 = nSelectedIndex;
    }
    if (nSelectedIndex >= f_180730 + f_18074E)
    {
        f_180730 = f_180730 + 1;
    }
}

// build: symbol ?MsgSlot07@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BE910
// 0x004BE910
int ListBoxImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    if (!pfnCallback)
        nSelectedIndex = f_180730;
    if (nSelectedIndex > 0)
    {
        --nSelectedIndex;
        sub_004B9A00(1, 0, 0, 0, 0);
        if (nSelectedIndex < f_180730)
            f_180730 = nSelectedIndex;
        if (nSelectedIndex >= f_180730 + f_18074E)
            ++f_180730;
    }
    return 1;
}

// build: symbol ?MsgSlot08@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BE990
// 0x004BE990
int ListBoxImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    if (!pfnCallback)
    {
        nSelectedIndex = f_180730 + f_18074E - 1;
        if (nSelectedIndex >= nEntryCount)
            nSelectedIndex = nEntryCount - 1;
    }
    if (nSelectedIndex < nEntryCount - 1)
    {
        ++nSelectedIndex;
        sub_004B9A00(1, 0, 0, 0, 0);
        if (nSelectedIndex < f_180730)
            f_180730 = nSelectedIndex;
        if (nSelectedIndex >= f_180730 + f_18074E)
            ++f_180730;
    }
    return 1;
}

// build: symbol ?OnKeyLeft@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BEA30
// 0x004BEA30
int ListBoxImplementation::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?OnKeyRight@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BEA40
// 0x004BEA40
int ListBoxImplementation::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BEA50
int ListBoxImplementation::sub_004BEA50_HitTestEntry(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->nXpos <= tBar.nX - 0xF && pfnCallback)
    {
        const int nMouseY = pMsg->nYpos;
        int nOffset = 0;
        for (int i = f_180730; i < nEntryCount; i++)
        {
            const int nStart = nOffset;
            if (aLines[i].wszText0[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].wszText1[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].wszText2[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].wszText3[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].wszText4[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (aLines[i].wszText5[0].wChar)
            {
                nOffset += nScrollStep;
            }
            if (nMouseY > f_18070C + nStart + 0xC && nMouseY < f_18070C + nOffset + 0xC)
            {
                nSelectedIndex = i;
                return i;
            }
            nOffset += nArg10;
        }
        nSelectedIndex = -1;
        return -1;
    }
    return -1;
}

// build: symbol ?MsgSlot05@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BEB70
// 0x004BEB70
int ListBoxImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    if (sub_004BE810_HitTestRect(pMsg))
    {
        sub_004BEA50_HitTestEntry(pMsg);
    }
    return 0;
}

// build: symbol ?OnKeyDown@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BEBC0
// 0x004BEBC0
int ListBoxImplementation::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (pfnCallback)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        if ((unsigned int)nState < 2)
        {
            return 0;
        }
        if (nSelectedIndex != -1 && pMsg->wParam == 0xD)
        {
            pfnCallback();
        }
        return 1;
    }
    return 0;
}

// build: symbol ?GetValue@ListBoxImplementation@@UAEHXZ 0x004BEC30
// 0x004BEC30
int ListBoxImplementation::GetValue()
{
    return nSelectedIndex;
}

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x004BEC40
int ListBoxImplementation::GetListEntryData(int nIndex)
{
    if (nIndex >= 0 && nIndex < nEntryCount && nIndex < 0x80)
    {
        return aLines[nIndex].unk0x3002;
    }
    D2_ASSERT(nEntryCount < 0x80, 0x46C);
    D2_ASSERT(nEntryCount < nIndex, 0x46D);
    D2_ASSERT(nIndex >= 0, 0x46E);
    return 0;
}

// 0x004BECC0
ListBoxWrapper::~ListBoxWrapper()
{
    delete pImpl;
}

// build: symbol ?MsgSlot08@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BED40
// 0x004BED40
int ListBoxWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// build: symbol ?MsgSlot07@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BED50
// 0x004BED50
int ListBoxWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// build: symbol ?OnKeyRight@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BED60
// 0x004BED60
int ListBoxWrapper::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyRight(pMsg);
}

// build: symbol ?OnKeyLeft@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BED70
// 0x004BED70
int ListBoxWrapper::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyLeft(pMsg);
}

// build: symbol ?OnLButtonDown@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BED80
// 0x004BED80
int ListBoxWrapper::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonDown(pMsg);
}

// build: symbol ?OnLButtonUp@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BED90
// 0x004BED90
int ListBoxWrapper::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonUp(pMsg);
}

// build: symbol ?MsgSlot05@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BEDA0
// 0x004BEDA0
int ListBoxWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// build: symbol ?OnKeyDown@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BEDB0
// 0x004BEDB0
int ListBoxWrapper::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyDown(pMsg);
}

// build: symbol ?GetValue@ListBoxWrapper@@UAEHXZ 0x004BEDC0
// 0x004BEDC0
int ListBoxWrapper::GetValue()
{
    return pImpl->GetValue();
}

// build: symbol ?Draw@ListBoxWrapper@@UAEXXZ 0x004BEDD0
// 0x004BEDD0
void ListBoxWrapper::Draw()
{
    pImpl->Draw();
}

// 0x004BEDE0
void ListBoxWrapper::sub_004BEDE0_ForwardSlot3C(const Unicode* wszText0, const Unicode* wszText1,
    const Unicode* wszText2, const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5,
    int nArg20, int nData, int bUseDefault, int nArg2C)
{
    pImpl->sub_004BE500_AddLine(wszText0, wszText1, wszText2, wszText3, wszText4, wszText5, nArg20, nData,
        bUseDefault, nArg2C);
}

// 0x004BEDF0
int ListBoxWrapper::sub_004BEDF0_ForwardGetEntryData(int nIndex)
{
    return pImpl->GetListEntryData(nIndex);
}

__forceinline int D2ListScrollStrc::DrawRows(D2CelContextStrc* pContext)
{
    int i;
    for (i = 0; i < nRows; ++i)
    {
        pContext->nFrame = 13;
        sub_004F6480(pContext, nX, nY + 12 * (i + 1), -1, 5, 0);
    }
    return i;
}

// 0x004BEE00
int ListBoxWrapper::sub_004BEE00_Slot14()
{
    return pImpl->sub_004BE0A0_GetLineCount();
}

// 0x004BEE10
void ListBoxWrapper::sub_004BEE10_Slot15()
{
    pImpl->sub_004BE0B0_Clear();
}

// build: symbol ?OnMouseWheel@ListBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BEE20
// 0x004BEE20
int ListBoxWrapper::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnMouseWheel(pMsg);
}

// build: symbol ?Draw@ListBoxImplementation@@UAEXXZ 0x004BEE90
// 0x004BEE90
void ListBoxImplementation::Draw()
{
    D2RectStrc tRect;
    tRect.nTop = f_18070C;
    tRect.nLeft = f_180708;
    tRect.nRight = f_180708 + nRectWidth - 1;
    tRect.nBottom = f_18070C + nRectHeight - 1;
    UI_DrawRectangleBorder(&tRect);

    const int nOldFont = D2Win_10127_SetFont(nArg18);

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpListBoxSliderCel;
    tContext.nFrame = bTopPressed ? 11 : 9;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, tBar.nX, tBar.nY, -1, 5, 0);

    const int i = tBar.DrawRows(&tContext);

    tContext.nFrame = bBottomPressed ? 10 : 8;
    sub_004F6480(&tContext, tBar.nX, tBar.nY + 12 * i, -1, 5, 0);

    int nDrawn = 0;
    const int nLines = PANEL_CountLinesInView(this);
    int nRow = 0;
    for (int nLine = f_180730; nLine < f_180730 + nLines && nLine < 0x80; ++nLine)
    {
        int nColor;
        if (nSelectedIndex == nLine && pfnCallback)
        {
            nColor = 3;
        }
        else
        {
            nColor = aLines[nLine].nData;
        }

        D2Win_10127_SetFont(aLines[nLine].nFont != 14 ? aLines[nLine].nFont : nArg18);

        if (aLines[nLine].wszText0[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText0, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText1[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText1, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText2[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText2, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText3[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText3, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText4[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText4, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        if (aLines[nLine].wszText5[0].wChar)
        {
            DrawClippedText(aLines[nLine].wszText5, f_180708 + 0x20, f_18070C + 0x19 + nArg10 * nRow + nScrollStep * nDrawn, nColor);
            ++nDrawn;
        }
        ++nRow;
    }

    sub_004BE110_UpdateScrollBar();
    ++nState;

    SMSGHANDLER_PARAMS tMsg;
    tMsg.lParam = (unsigned short)sub_00468730() | ((unsigned int)(unsigned short)sub_00468740() << 16);
    const int nMouseX = (unsigned short)tMsg.lParam;
    const int nMouseY = tMsg.lParam >> 16;

    if (nMouseX > tBar.nX && nMouseX < tBar.nX + 16 && nMouseY > tBar.nY - 12 && nMouseY < tBar.nY && bTopPressed == 1)
    {
        if (++nRepeatTicks && nRepeatTicks % 10)
        {
            MsgSlot07(&tMsg);
        }
    }
    else if (nMouseX > tBar.nX && nMouseX < tBar.nX + 16 && nMouseY > tBar.nY + 12 * tBar.nRows - 12 && nMouseY < tBar.nY + 12 * tBar.nRows
        && bBottomPressed == 1)
    {
        if (++nRepeatTicks && nRepeatTicks % 10)
        {
            MsgSlot08(&tMsg);
        }
    }

    D2Win_10127_SetFont(nOldFont);
}

// 0x004BF2F0
int ListBoxView::ClickScrollTrack(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseY = pMsg->nYpos;
    const unsigned short nCount = nEntryCount;
    const int nTop = nY;

    if (nCount && nVisibleRows <= nCount && nMouseY - nTop > 0)
    {
        if (nThumbStart != nThumbEnd)
        {
            if (nMouseY < nTop + 12 * nThumbStart + 13)
            {
                if (nSelectedIndex - nVisibleRows > 0)
                    nSelectedIndex = nSelectedIndex - nVisibleRows;
                else
                    nSelectedIndex = 0;
            }
            else
            {
                if (nMouseY <= nY + 12 * nThumbEnd + 13)
                {
                    return 0;
                }

                if (nSelectedIndex + nVisibleRows >= nCount)
                    nSelectedIndex = nCount - 1;
                else
                    nSelectedIndex = nSelectedIndex + nVisibleRows;
                if (nCount - nSelectedIndex < nVisibleRows)
                {
                    if (nCount >= nVisibleRows)
                    {
                        nSelectedIndex = nCount - nVisibleRows;
                    }
                    else
                    {
                        nSelectedIndex = 0;
                    }
                }
            }

            if (nSelectedIndex >= 0x80)
            {
                nSelectedIndex = D2_MAX(0, nCount - 1);
            }

            nTopIndex = nSelectedIndex;
            sub_004B9A00(1, 0, 0, 0, 0);
            sub_004BE8D0_Refresh();
            return 1;
        }

        return 0;
    }

    return 0;
}


// build: symbol ?OnLButtonDown@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BF430
// 0x004BF430
int ListBoxImplementation::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (!sub_004BE810_HitTestRect(pMsg))
    {
        return 0;
    }

    f_18071C = 1;
    if (HitTestScrollUp(pMsg) == 1)
    {
        bTopPressed = 1;
        nRepeatTicks = 0;
        return 1;
    }

    if (HitTestScrollDown(pMsg) == 1)
    {
        bBottomPressed = 1;
        nRepeatTicks = 0;
        return 1;
    }

    if (HitTestScrollTrack(pMsg) == 1)
    {
        nPressY = pMsg->nYpos;
        bRowsPressed = 1;
        return 1;
    }

    if (pfnCallback)
    {
        nCallbackRow = sub_004BEA50_HitTestEntry(pMsg);
    }
    return 1;
}

// build: symbol ?OnLButtonUp@ListBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BF530
// 0x004BF530
int ListBoxImplementation::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (!f_18071C)
    {
        nCallbackRow = -1;
        return 1;
    }
    f_18071C = 0;
    if (bTopPressed == 1)
    {
        bTopPressed = 0;
        if (HitTestScrollUp(pMsg) == 1)
            MsgSlot07(pMsg);
        nCallbackRow = -1;
        return 0;
    }
    if (bBottomPressed == 1)
    {
        bBottomPressed = 0;
        if (HitTestScrollDown(pMsg) == 1)
            MsgSlot08(pMsg);
        nCallbackRow = -1;
        return 0;
    }
    if (bRowsPressed == 1)
    {
        bRowsPressed = 0;
        if (HitTestScrollTrack(pMsg) == 1)
            ClickScrollTrack(pMsg);
        nCallbackRow = -1;
        return 0;
    }
    if (pfnCallback)
    {
        const int nHit = sub_004BEA50_HitTestEntry(pMsg);
        if (nCallbackRow == nHit && nCallbackRow != -1)
        {
            nCallbackRow = -1;
            pfnCallback();
            return 1;
        }
    }
    return 0;
}

// 0x004BF650
ListBoxImplementation::ListBoxImplementation(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14,
    int nArg18, int nCallback, bool bLargeFont)
{
    f_180708 = nX;
    f_18070C = nY;
    nRectWidth = nWidth;
    nRectHeight = nHeight;
    nCallbackRow = -1;
    nSelectedIndex = -1;
    this->nArg14 = nArg14;
    this->nArg18 = nArg18;
    f_18071C = 0;
    bRowsPressed = 0;
    bTopPressed = 0;
    bBottomPressed = 0;
    nState = 0;
    f_180730 = 0;
    nEntryCount = 0;
    for (int n = 0; n < 0x80; n++)
    {
        aLines[n].wszText0[0].wChar = 0;
        aLines[n].wszText1[0].wChar = 0;
        aLines[n].wszText2[0].wChar = 0;
        aLines[n].wszText3[0].wChar = 0;
        aLines[n].wszText4[0].wChar = 0;
        aLines[n].wszText5[0].wChar = 0;
        aLines[n].nFlags = 0;
        aLines[n].nData = 0;
        aLines[n].nFont = 1;
        aLines[n].unk0x3002 = 0;
    }
    pfnCallback = (void (__cdecl*)())nCallback;
    this->nArg10 = nArg10;
    tBar.nX = f_180708 + nRectWidth - 0x12;
    tBar.nY = f_18070C + 0x10;
    nScrollStep = 0xE;
    if (nRectHeight < 0x20)
    {
        tBar.nRows = 1;
    }
    else
    {
        tBar.nRows = (nRectHeight - 0x10) / 12 - 1;
    }
    f_18074E = 1;
    if (D2GFX_GetResolutionMode() == 2)
    {
        nLineHeight = bLargeFont ? 0x1C : 0x12;
    }
    else
    {
        nLineHeight = 0x12;
    }
}

// 0x004BF8F0
ListBoxWrapper::ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18,
    int nCallback, bool bLargeFont)
{
    pImpl = new ListBoxImplementation(nX, nY, nWidth, nHeight, nArg10, nArg14, nArg18, nCallback, bLargeFont);
}

#include "gen/data/Source/D2Client/Unknown_004BC1B0.inc"
