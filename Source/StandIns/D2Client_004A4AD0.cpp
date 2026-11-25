// Functional replacement for the function at 0x004A4AD0, not the original code: only the ordinary build (tools/link.py) uses it.
// The other functions in this file are copies that give it its callees and their calling conventions; the build links their verified definitions instead.

#pragma pack(push, 2)
struct D2SliderButtonStrc
{
    unsigned short nStringId;
    void (__cdecl* pfnClick)();
    int unk0x06;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2ClientListEntryStrc
{
    int nId;
    unsigned char unk0x04[6];
};
#pragma pack(pop)

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
int __cdecl TEXT_GetMaxFirstEntry(); // 0x004A44C0
int __stdcall TEXT_IsAbovePanelLine(int nX); // 0x004A4780

extern int gnScreenWidth; // 0x0071146C
extern D2ClientListEntryStrc* gpListEntries; // 0x00724264
extern int gnKeyConfigColumn; // 0x007246D4
extern D2SliderButtonStrc gaKeyConfigButtons[3]; // 0x007246D8
extern int gnAutomapHeight_007A521C; // 0x007A521C
static int gnKeyConfigEntryCount; // 0x007C0274
extern int gnKeyConfigThumbScale; // 0x007C0278
extern int gnThumbRange; // 0x007C027C
extern int gbRedraw; // 0x007C0280
extern int gbKeyConfigPressRepeat; // 0x007C0284
extern int gaPressed[7]; // 0x007C0288
extern int gnDragThumbY; // 0x007C02A4
extern int gnDragMouseY; // 0x007C02A8
static int gnKeyConfigFirstVisible; // 0x007C02AC
static int gnKeyConfigSelected; // 0x007C02B0
extern int gnPressedButton_007C02B4; // 0x007C02B4
extern unsigned long gdwKeyConfigRepeatTick; // 0x007C02C0
static int gnKeyConfigThumbY; // 0x007C02CC

static __forceinline int sub_F08_ListTop()
{
    return (gnAutomapHeight_007A521C - 0x1A4) / 2;
}

static __forceinline int sub_F08_PanelLeft()
{
    return (gnScreenWidth - 0x26C) / 2;
}

static __forceinline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnScreenWidth - sub_F08_PanelLeft() * 2);
}

static __forceinline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static __forceinline int sub_F08_TrackBottom()
{
    return sub_F08_ListTop() + 0x125;
}

static __forceinline int sub_F08_ThumbHeight()
{
    return gnKeyConfigThumbScale * 12;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_F08_TrackBottom() - sub_F08_TrackTop() - sub_F08_ThumbHeight();
}

static __forceinline int sub_F08_LinesTop()
{
    return sub_F08_ListTop() + 0x28;
}

static __forceinline int sub_F08_LinesBottom()
{
    return sub_F08_ListTop() + 0x136;
}

static __forceinline int sub_F08_VisibleLines()
{
    return (sub_F08_LinesBottom() - sub_F08_LinesTop()) / 0x12;
}

// 0x004A44C0
int __cdecl TEXT_GetMaxFirstEntry()
{
    int nCount = gnKeyConfigEntryCount;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

static __forceinline int sub_F08_NoOtherPressed(int nIndex)
{
    for (int i = 0; i < 7; ++i)
    {
        if (gaPressed[i] && i != nIndex)
            return 0;
    }
    return 1;
}

// 0x004A4500
void __fastcall TEXT_ScrollKeyConfigList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_ScrollKeyConfigList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_ScrollKeyConfigList(1);
        return;
    }

    const int nMax = TEXT_GetMaxFirstEntry();
    if (nStep < 0)
    {
        const int nPrev = gnKeyConfigFirstVisible <= 0 ? gnKeyConfigFirstVisible : gnKeyConfigFirstVisible - 1;
        if (nPrev >= 0)
            gnKeyConfigFirstVisible = nPrev;
    }
    else if (nStep > 0)
    {
        const int nNext = gnKeyConfigFirstVisible >= nMax ? gnKeyConfigFirstVisible : gnKeyConfigFirstVisible + 1;
        if (nNext <= nMax)
            gnKeyConfigFirstVisible = nNext;
    }
    gnKeyConfigThumbY = sub_F08_TrackSpan() * gnKeyConfigFirstVisible / nMax + sub_F08_TrackTop();
}

// 0x004A45C0
void __fastcall TEXT_MoveKeyConfigSelection(int nStep)
{
    if (!nStep)
        return;
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_MoveKeyConfigSelection(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_MoveKeyConfigSelection(1);
        return;
    }

    const int nCount = gnKeyConfigEntryCount;
    if (nStep < 0)
    {
        const int nOld = gnKeyConfigSelected;
        const int nNew = nOld <= 0 ? nOld : nOld - 1;
        if (nNew >= 0)
            gnKeyConfigSelected = nNew;
    }
    else if (nStep > 0 && gnKeyConfigSelected < nCount)
    {
        const int nNew = gnKeyConfigSelected + 1;
        if (nNew < nCount)
            gnKeyConfigSelected = nNew;
    }

    const int nSelected = gnKeyConfigSelected;
    int nFirst = gnKeyConfigFirstVisible;
    if (nSelected < nFirst)
    {
        const int nTrackTop = sub_F08_TrackTop();
        gnKeyConfigFirstVisible = nSelected;
        gnKeyConfigThumbY = nSelected * sub_F08_TrackSpan() / TEXT_GetMaxFirstEntry() + nTrackTop;
        return;
    }

    for (;;)
    {
        int nLast = nFirst;
        for (int nLine = 0; nLast < nCount && nLine < 0x0F; ++nLine)
            ++nLast;
        if (gnKeyConfigSelected < nLast)
            break;

        const int nMax = TEXT_GetMaxFirstEntry();
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
            nFirst = nNew;
        gnKeyConfigThumbY = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
    }
    gnKeyConfigFirstVisible = nFirst;
}

// 0x004A4720
static int TEXT_GetKeyConfigLineAt(int nY)
{
    int nIndex = gnKeyConfigFirstVisible;
    const int nCount = gnKeyConfigEntryCount;
    int nLine = 0;
    if (nIndex < nCount)
    {
        int nLineY = (gnAutomapHeight_007A521C - 0x1A4) / 2 + 0x3A;
        do
        {
            if (nLine >= 0x0F)
                break;
            if (nY <= nLineY)
                return nIndex;
            ++nIndex;
            ++nLine;
            nLineY += 0x12;
        }
        while (nIndex < nCount);
        if (nIndex < nCount)
            return nIndex;
    }
    return nCount < 0 ? nCount : nCount - 1;
}

static __declspec(noinline) int TEXT_GetKeyConfigButtonAt(int nX, int nY);
// 0x004A47C0
static int TEXT_GetKeyConfigButtonAt(int nX, int nY)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        if (nX >= gaKeyConfigButtons[i].nLeft && nX <= gaKeyConfigButtons[i].nRight
            && nY >= gaKeyConfigButtons[i].nTop && nY <= gaKeyConfigButtons[i].nBottom)
            break;
    }
    return i;
}

// 0x004A47F0
static int TEXT_IsInKeyConfigList(int nX, int nY)
{
    const int nHalf = (gnScreenWidth - 0x26C) / 2;
    const int nLeft = nHalf + 0x12;
    const int nRight = nHalf + (gnScreenWidth - nHalf * 2 - 0x31) / 3 * 3 + 0x12;
    if (nX >= nLeft && nX <= nRight)
    {
        const int nTop = (gnAutomapHeight_007A521C - 0x1A4) / 2;
        if (nY >= nTop + 0x28 && nY <= nTop + 0x136)
            return 1;
    }
    return 0;
}

static __declspec(noinline) int TEXT_IsOnUpArrow(int nX, int nY);
// 0x004A4860
static int TEXT_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

static __declspec(noinline) int TEXT_IsOnDownArrow(int nX, int nY);
// 0x004A48B0
static int TEXT_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

static __declspec(noinline) int TEXT_IsAboveThumb(int nX, int nY);
// 0x004A4900
static int TEXT_IsAboveThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY > sub_F08_ListTop() + 0x2F && nY < gnKeyConfigThumbY)
            return 1;
    }
    return 0;
}

static __declspec(noinline) int TEXT_IsOnThumb(int nX, int nY);
// 0x004A4950
static int TEXT_IsOnThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY >= gnKeyConfigThumbY && nY <= gnKeyConfigThumbY + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

static __declspec(noinline) int TEXT_IsBelowThumb(int nX, int nY);
// 0x004A49A0
static int TEXT_IsBelowThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY < sub_F08_ListTop() + 0x125 && nY > gnKeyConfigThumbY + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A4AD0
void __stdcall sub_004A4AD0_Press(int nX, int nY)
{
    gnPressedButton_007C02B4 = 3;
    if (gbKeyConfigPressRepeat)
        return;

    const int bInList = TEXT_IsInKeyConfigList(nX, nY);
    const int bUp = TEXT_IsOnUpArrow(nX, nY);
    const int bDown = TEXT_IsOnDownArrow(nX, nY);
    const int bPageUp = TEXT_IsAboveThumb(nX, nY);
    const int bThumb = TEXT_IsOnThumb(nX, nY);
    const int bPageDown = TEXT_IsBelowThumb(nX, nY);
    const int bButton = TEXT_GetKeyConfigButtonAt(nX, nY) != 3;

    if (sub_F08_NoOtherPressed(7) && !bInList && !bUp && !bDown && !bPageUp && !bThumb && !bPageDown && !bButton)
    {
        gbKeyConfigPressRepeat = gbRedraw;
        return;
    }

    if (sub_F08_NoOtherPressed(0) && (bInList || gaPressed[0]))
    {
        gaPressed[0] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            if (nY < nTop + 0x28)
                TEXT_MoveKeyConfigSelection(-1);
            if (nY > nTop + 0x136)
                TEXT_MoveKeyConfigSelection(1);

            const int nOldD4 = gnKeyConfigColumn;
            const int nOldSelected = gnKeyConfigSelected;
            const int nLine = TEXT_GetKeyConfigLineAt(nY);
            gnKeyConfigSelected = nLine;
            gnKeyConfigColumn = TEXT_IsAbovePanelLine(nX);
            if (gpListEntries[nLine].nId == 0x39)
            {
                gnKeyConfigColumn = nOldD4;
                gnKeyConfigSelected = nOldSelected;
            }
        }
    }

    if (sub_F08_NoOtherPressed(1) && bUp)
    {
        gaPressed[1] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(-1);
        }
    }

    if (sub_F08_NoOtherPressed(2) && bDown)
    {
        gaPressed[2] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1);
        }
    }

    if (sub_F08_NoOtherPressed(3) && bPageUp)
    {
        gaPressed[3] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1 - sub_F08_VisibleLines());
        }
    }

    if (sub_F08_NoOtherPressed(4) && (bThumb || gaPressed[4]))
    {
        if (bThumb && !gaPressed[4] && gbRedraw)
        {
            gnDragThumbY = gnKeyConfigThumbY;
            gnDragMouseY = nY;
        }
        gaPressed[4] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            TEXT_ScrollKeyConfigList((gnDragThumbY - nTop - gnDragMouseY + nY - 0x2F)
                * (gnThumbRange + 1) / sub_F08_TrackSpan() - gnKeyConfigFirstVisible);
        }
    }

    if (sub_F08_NoOtherPressed(5) && bPageDown)
    {
        gaPressed[5] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(sub_F08_VisibleLines() - 1);
        }
    }

    if (sub_F08_NoOtherPressed(6) && bButton)
    {
        gaPressed[6] = gbRedraw;
        gnPressedButton_007C02B4 = TEXT_GetKeyConfigButtonAt(nX, nY);
    }
}
