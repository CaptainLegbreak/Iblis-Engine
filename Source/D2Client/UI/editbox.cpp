#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinSplitText.h"

struct Unicode;
struct D2ButtonStringStrc;
// build: symbol ??_7EditBoxImplementation@@6B@ 0x006DA77C
// build: symbol ??_7EditBoxWrapper@@6B@ 0x006DA7CC

class UIWidget;
class ButtonImplementation;
class EditBoxImplementation;
class ButtonWrapper;
class EditBoxWrapper;
class SpinnerImplementation;

void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

// build: symbol ??1ButtonWrapper@@UAE@XZ 0x004BADD0
// build: symbol ??1EditBoxImplementation@@UAE@XZ 0x004BB170
// build: symbol ??1EditBoxWrapper@@UAE@XZ 0x004BB9F0
// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_GButtonImplementation@@UAEPAXI@Z 0x004BAFD0
// build: symbol ??_GButtonWrapper@@UAEPAXI@Z 0x004BAE30
// build: symbol ??_GEditBoxImplementation@@UAEPAXI@Z 0x004BBD50
// build: symbol ??_GEditBoxWrapper@@UAEPAXI@Z 0x004BBA50
// build: symbol ??_GSpinnerWrapper@@UAEPAXI@Z 0x004BC250

// build: symbol ??3UIWidget@@SAXPAX@Z 0x004053F0

#pragma pack(push, 2)

class UIWidget
{
public:
    static void* operator new(size_t nSize)
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

    int unk0x04;
};



// 0x004BB5D0
int __cdecl sub_004BB5D0()
{
    return 0;
}

// 0x004BBD50
class EditBoxImplementation : public UIWidget
{
public:
    EditBoxImplementation(int nX, int nY, int nTextWidth, int nHeight, int nArg10, unsigned short nMaxLength, int nArg18,
        int nFont);
    virtual ~EditBoxImplementation();
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
    virtual void sub_004BB5B0_Slot12(char* szBuffer);
    virtual void Slot13();
    virtual void sub_004BB530_Slot14(const char* szText);
    virtual void sub_004BB4D0_Slot15(int nValue);
    virtual void sub_004BB990_SetUnk18(int nValue);
    virtual void sub_004BB9A0_SetUnk24(int nValue);
    virtual void sub_004BB200_SetUnk20(int nValue);

    void sub_004BB980_SetUnk04(int nValue);

    int nX;
    int nY;
    int nTextX;
    int nTextY;
    int nTextWidth;
    int nHeight;
    int unk0x20;
    int unk0x24;
    Unicode* pText;
    Unicode* pTextCopy;
    int nMaxValue;
    unsigned short nMaxLength;
    int unk0x36;
    int unk0x3A;
    int unk0x3E;
    int unk0x42;
    unsigned int unk0x46;
    int unk0x4A;
    int nFont;
    void* pCellFile;
    int unk0x56;
};

// 0x004BBA50
class EditBoxWrapper : public UIWidget
{
public:
    EditBoxWrapper(int nX, int nY, int nTextWidth, int nHeight, int nArg10, unsigned short nMaxLength, int nArg18,
        int nFont);
    virtual ~EditBoxWrapper();
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
    virtual void sub_004BBB30_Slot12(int nValue);
    virtual void sub_004BBB50_Slot13(const char* szText);
    virtual void sub_004BBB40_Slot14(int nValue);
    virtual void sub_004BBB60_Slot15(char* szBuffer);
    virtual void sub_004BBB80_Forward(int nArg);
    virtual void sub_004BBB90_SetUnk24(int nValue);
    virtual void sub_004BBBA0_SetUnk20(int nValue);

    void sub_004BBB70_SetUnk04(int nValue);

    EditBoxImplementation* pImpl;
};

class SpinnerImplementation : public UIWidget
{
public:
    SpinnerImplementation(int nX, int nY, int bHorizontal, int nArg0C);
    virtual ~SpinnerImplementation();
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
    virtual int sub_004BBFB0();

    int HitTestUpArrow(SMSGHANDLER_PARAMS* pMsg);
    int HitTestDownArrow(SMSGHANDLER_PARAMS* pMsg);

    int nX;
    int nY;
    int nUpX;
    int nUpY;
    int nDownX;
    int nDownY;
    int unk0x20;
    int nArrowHeight;
    int nArrowWidth;
    int f_2C;
    int unk0x30;
    int unk0x34;
    int unk0x38;
    void (__cdecl* pfUnk0x3C)();
    unsigned int nUnk0x3CCalls;
    unsigned int unk0x44;
    unsigned int unk0x48;
    int unk0x4C;
    void* pCellFile;
};

class SpinnerWrapper : public UIWidget
{
public:
    SpinnerWrapper(int nX, int nY, int bHorizontal, int nArg0C);
    virtual ~SpinnerWrapper();
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
    virtual int sub_004BC330_ForwardSlot30(int nArg);

    SpinnerImplementation* pImpl;
};

#pragma pack(pop)



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
extern D2ButtonStringStrc gaButtonStrings[]; // 0x007275A8








int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

struct D2MouseMessageStrc
{
    char unk_00[0xC];
    unsigned short nX;
    unsigned short nY;
};

struct D2ButtonPairStrc
{
    char unk_00[0x10];
    int nFirstX;
    int nFirstY;
    int nSecondX;
    int nSecondY;
    int unk_20;
    int nHeight;
    int nWidth;
    int unk_2C;
    int f_30;
    int bFirst;
    int bSecond;
    void (__cdecl* pCallback)();
    int unk_40;
    unsigned long nTick;
    int unk_48;
    int bInvoking;
};

extern "C" void _ReadWriteBarrier(void);

#pragma intrinsic(_ReadWriteBarrier)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel);                                                                   // 0x00478A00

struct SMSGHANDLER_PARAMS;





















void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern "C" D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840

extern "C" int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

extern "C" int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0




// 0x004BB170
EditBoxImplementation::~EditBoxImplementation()
{
    if (pText)
    {
        FOG_Free(pText, ".\\UI\\editbox.cpp", 0x8E, 0);
        pText = 0;
    }
    if (pTextCopy)
    {
        FOG_Free(pTextCopy, ".\\UI\\editbox.cpp", 0x93, 0);
        pTextCopy = 0;
    }
    ARCHIVE_FreeClientCellFile(pCellFile);
}

// 0x004BB200
void EditBoxImplementation::sub_004BB200_SetUnk20(int nValue)
{
    unk0x20 = nValue;
}

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

// build: symbol ?Draw@EditBoxImplementation@@UAEXXZ 0x004BB210
// 0x004BB210
void EditBoxImplementation::Draw()
{
    ++unk0x46;
    if (unk0x56)
    {
        AUTOMAP_DrawFramedBox(nTextX - 10, nTextY - 0x10, nTextWidth, 0x12, 0, 2);
    }
    D2Win_10127_SetFont(nFont);

    Unicode wszBuffer[200];
    Unicode wszCursor[2];
    char szCursor[2];
    szCursor[1] = 0;
    szCursor[0] = '_';
    Unicode::win2Unicode(wszCursor, szCursor, 2);

    if ((unk0x4A && unk0x46 % 20 == 0) || (!unk0x4A && unk0x46 % 10 == 0))
    {
        unk0x4A = !unk0x4A;
    }

    if (nHeight == 1)
    {
        int nStart = 0;
        if (D2Win_10121_GetTextWidth(pText) > nTextWidth)
        {
            const int nLength = sub_00526800(pText);
            for (nStart = 0; nStart < nLength; ++nStart)
            {
                if (D2Win_10121_GetTextWidth(&pText[nStart]) <= nTextWidth)
                {
                    break;
                }
            }
        }

        D2Win_10117_DrawText(&pText[nStart], nTextX, nTextY, 0, 0);
        if (unk0x36 < nMaxLength && unk0x4A && unk0x36 <= unk0x3A)
        {
            if (sub_00526800(&pText[nStart]))
            {
                sub_005267E0(pTextCopy, pText);
                pTextCopy[unk0x36] = 0;
                D2Win_10117_DrawText(wszCursor, D2Win_10121_GetTextWidth(pTextCopy) + nTextX, nTextY, 0, 0);
            }
            else
            {
                D2Win_10117_DrawText(wszCursor, nTextX, nTextY, 0, 0);
            }
        }
        return;
    }

    int nLines;
    D2SplittedTextStrc* pLine = D2WINFONT_SplitText(pText, &nLines, nTextWidth);
    int nLine = 0;
    int nChars = 0;
    int bDone = 0;
    while (pLine)
    {
        D2Win_10117_DrawText(pLine->wszLine, nTextX, nTextY + 20 * nLine, 0, 0);
        const int nLength = sub_00526800(pLine->wszLine);
        D2SplittedTextStrc* pNext = pLine->pNextLine;
        nChars += nLength;
        ++nLine;
        if (unk0x36 < nMaxLength && unk0x4A && nChars >= unk0x36 && !bDone)
        {
            bDone = 1;
            int nColumn = unk0x36 - nChars + nLength;
            if (nColumn < 0)
            {
                nColumn = 0;
            }
            if (sub_00526800(pLine->wszLine))
            {
                if (sub_00526800(pLine->wszLine) > 199)
                {
                    return;
                }
                sub_005267E0(wszBuffer, pLine->wszLine);
                wszBuffer[nColumn] = 0;
                D2Win_10117_DrawText(wszCursor, D2Win_10121_GetTextWidth(wszBuffer) + nTextX, nTextY + 20 * (nLine - 1), 0, 0);
            }
            else
            {
                D2Win_10117_DrawText(wszCursor, nTextX, nTextY + 20 * (nLine - 1), 0, 0);
            }
        }
        FOG_Free(pLine->wszLine, ".\\UI\\editbox.cpp", 0x103, 0);
        FOG_Free(pLine, ".\\UI\\editbox.cpp", 0x104, 0);
        pLine = pNext;
    }
    if (!nLine && unk0x4A)
    {
        D2Win_10117_DrawText(wszCursor, nTextX, nTextY, 0, 0);
    }
}

// 0x004BB4D0
void EditBoxImplementation::sub_004BB4D0_Slot15(int nValue)
{
    char szBuffer[0x14];
    sprintf(szBuffer, szIntFormat_006D57BC, nValue);
    if (strlen(szBuffer) > nMaxLength)
    {
        szBuffer[nMaxLength - 1] = 0;
    }
    sub_00526F20_ToUnicode(pText, szBuffer, nMaxLength);
    const int nLength = sub_00526800(pText);
    unk0x36 = nLength;
    unk0x3A = nLength;
}

// 0x004BB530
void EditBoxImplementation::sub_004BB530_Slot14(const char* szText)
{
    sub_00526F20_ToUnicode(pText, szText, nMaxLength);
    const int nLength = sub_00526800(pText);
    unk0x36 = nLength;
    unk0x3A = nLength;
}

// build: symbol ?GetValue@EditBoxImplementation@@UAEHXZ 0x004BB560
// 0x004BB560
int EditBoxImplementation::GetValue()
{
    if (!sub_00526800(pText))
    {
        return 0;
    }
    char szBuffer[100];
    sub_005263E0(szBuffer, pText, nMaxLength);
    const int nValue = atoi(szBuffer);
    if (nValue > nMaxValue)
    {
        return 0;
    }
    return nValue;
}

// 0x004BB5B0
void EditBoxImplementation::sub_004BB5B0_Slot12(char* szBuffer)
{
    sub_005263E0(szBuffer, pText, nMaxLength);
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

// build: symbol ?OnLButtonDown@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB5E0
// 0x004BB5E0
int EditBoxImplementation::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    unk0x3E = 1;
    return 0;
}

// build: symbol ?OnLButtonUp@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB600
// 0x004BB600
int EditBoxImplementation::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x3E)
    {
        unk0x46 = 0;
        unk0x3E = 0;
    }
    return 0;
}

// build: symbol ?MsgSlot05@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB950
// 0x004BB950
int EditBoxImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?MsgSlot07@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB960
// 0x004BB960
int EditBoxImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?MsgSlot08@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB970
// 0x004BB970
int EditBoxImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BB980
void EditBoxImplementation::sub_004BB980_SetUnk04(int nValue)
{
    unk0x04 = nValue;
}

// 0x004BB990
void EditBoxImplementation::sub_004BB990_SetUnk18(int nValue)
{
    nTextWidth = nValue;
}

// 0x004BB9A0
void EditBoxImplementation::sub_004BB9A0_SetUnk24(int nValue)
{
    unk0x24 = nValue;
}

// build: symbol ?OnKeyRight@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB9B0
// 0x004BB9B0
int EditBoxImplementation::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x36 < unk0x3A)
        unk0x36 += 1;
    return 1;
}

// build: symbol ?OnKeyLeft@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB9D0
// 0x004BB9D0
int EditBoxImplementation::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x36 > 0)
        unk0x36 -= 1;
    return 1;
}

// 0x004BB9F0
EditBoxWrapper::~EditBoxWrapper()
{
    delete pImpl;
}

// build: symbol ?OnMouseWheel@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBA80
// 0x004BBA80
int EditBoxWrapper::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnMouseWheel(pMsg);
}

// build: symbol ?OnLButtonDown@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBA90
// 0x004BBA90
int EditBoxWrapper::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonDown(pMsg);
}

// build: symbol ?OnLButtonUp@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAA0
// 0x004BBAA0
int EditBoxWrapper::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonUp(pMsg);
}

// build: symbol ?MsgSlot05@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAB0
// 0x004BBAB0
int EditBoxWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// build: symbol ?Draw@EditBoxWrapper@@UAEXXZ 0x004BBAC0
// 0x004BBAC0
void EditBoxWrapper::Draw()
{
    pImpl->Draw();
}

// build: symbol ?GetValue@EditBoxWrapper@@UAEHXZ 0x004BBB20
int EditBoxWrapper::GetValue()
{
    return pImpl->GetValue();
}

// build: symbol ?OnKeyDown@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAD0
// 0x004BBAD0
int EditBoxWrapper::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyDown(pMsg);
}

// build: symbol ?MsgSlot08@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAE0
// 0x004BBAE0
int EditBoxWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// build: symbol ?MsgSlot07@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBAF0
// 0x004BBAF0
int EditBoxWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// build: symbol ?OnKeyRight@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBB00
// 0x004BBB00
int EditBoxWrapper::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyRight(pMsg);
}

// build: symbol ?OnKeyLeft@EditBoxWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BBB10
// 0x004BBB10
int EditBoxWrapper::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyLeft(pMsg);
}

// 0x004BBB30
void EditBoxWrapper::sub_004BBB30_Slot12(int nValue)
{
    pImpl->Slot13();
}

// 0x004BBB40
void EditBoxWrapper::sub_004BBB40_Slot14(int nValue)
{
    pImpl->sub_004BB4D0_Slot15(nValue);
}

// 0x004BBB50
void EditBoxWrapper::sub_004BBB50_Slot13(const char* szText)
{
    pImpl->sub_004BB530_Slot14(szText);
}

// 0x004BBB60
void EditBoxWrapper::sub_004BBB60_Slot15(char* szBuffer)
{
    pImpl->sub_004BB5B0_Slot12(szBuffer);
}

// 0x004BBB70
void EditBoxWrapper::sub_004BBB70_SetUnk04(int nValue)
{
    pImpl->sub_004BB980_SetUnk04(nValue);
}

// 0x004BBB90
void EditBoxWrapper::sub_004BBB90_SetUnk24(int nValue)
{
    pImpl->sub_004BB9A0_SetUnk24(nValue);
}

// 0x004BBBA0
void EditBoxWrapper::sub_004BBBA0_SetUnk20(int nValue)
{
    pImpl->sub_004BB200_SetUnk20(nValue);
}

// 0x004BBBB0
EditBoxImplementation::EditBoxImplementation(int nX, int nY, int nTextWidth, int nHeight, int nArg10,
    unsigned short nMaxLength, int nArg18, int nFont)
{
    char szPath[260];
// build: symbol ?gszDataGlobal@* 0x006D4118
    sprintf(szPath, "%s\\ui\\menu\\textslid", gszDataGlobal);
    pCellFile = ARCHIVE_LoadClientCellFile(szPath, 0);
    this->nX = nX;
    this->nY = nY;
    unk0x42 = nArg18;
    unk0x3E = 0;
    unk0x46 = 0;
    const int nSize = (nMaxLength + 1) * sizeof(Unicode);
    pText = (Unicode*)FOG_Alloc(nSize, ".\\UI\\editbox.cpp", 93, 0);
    pTextCopy = (Unicode*)FOG_Alloc(nSize, ".\\UI\\editbox.cpp", 94, 0);
    memset(pText, 0, nSize);
    memset(pTextCopy, 0, nSize);
    nMaxValue = nArg10;
    this->nMaxLength = nMaxLength;
    unk0x36 = 0;
    unk0x3A = 0;
    this->nFont = nFont;
    nTextX = nX + 1;
    nTextY = nY;
    unk0x20 = 1;
    unk0x4A = 1;
    char szDigits[11] = "0000000000";
    Unicode wszDigits[11];
    memset(wszDigits, 0, sizeof(wszDigits));
    D2Win_10127_SetFont(nFont);
    sub_00526F20_ToUnicode(wszDigits, szDigits, 11);
    if (nTextWidth <= 0)
    {
        this->nTextWidth = D2Win_10121_GetTextWidth(wszDigits) / 10 * (nMaxLength + 2);
    }
    else
    {
        this->nTextWidth = nTextWidth;
    }
    if (nHeight <= 0)
    {
        this->nHeight = 1;
        unk0x56 = 1;
    }
    else
    {
        this->nHeight = nHeight;
        unk0x56 = 0;
    }
    unk0x24 = 0;
    unk0x04 = 0;
}

// 0x004BBD80
EditBoxWrapper::EditBoxWrapper(int nX, int nY, int nTextWidth, int nHeight, int nArg10, unsigned short nMaxLength,
    int nArg18, int nFont)
{
    pImpl = new EditBoxImplementation(nX, nY, nTextWidth, nHeight, nArg10, nMaxLength, nArg18, nFont);
}








// build: symbol ?OnMouseWheel@EditBoxImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BB5F0
// 0x004BB5F0
int EditBoxImplementation::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}





// 0x004BBB80
void EditBoxWrapper::sub_004BBB80_Forward(int nArg)
{
    pImpl->sub_004BB990_SetUnk18(nArg);
}
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290



static inline int sub_004BC0A0_IsInFirst(D2ButtonPairStrc* pButtons, D2MouseMessageStrc* pMessage)
{
    const int nX = pMessage->nX;
    const int nY = pMessage->nY;
    return nX > pButtons->nFirstX && nX < pButtons->nFirstX + pButtons->nWidth
        && nY > pButtons->nFirstY - pButtons->nHeight && nY <= pButtons->nFirstY;
}

static inline int sub_004BC0A0_IsInSecond(D2ButtonPairStrc* pButtons, D2MouseMessageStrc* pMessage)
{
    const int nX = pMessage->nX;
    const int nY = pMessage->nY;
    return nX > pButtons->nSecondX && nX < pButtons->nSecondX + pButtons->nWidth
        && nY > pButtons->nSecondY - pButtons->nHeight && nY < pButtons->nSecondY;
}


















struct D2CelFileStrc;

#include "gen/data/Source/D2Client/UI/editbox.inc"





