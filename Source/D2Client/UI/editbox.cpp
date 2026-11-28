#include "D2LanguageNames.h"

#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinSplitText.h"
#include "FogApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2WinApi.h"
#include "D2CMPApi.h"
#include "StormApi2.h"

struct Unicode;
struct D2ButtonStringStrc;

class UIWidget;
class ButtonImplementation;
class EditBoxImplementation;
class ButtonWrapper;
class EditBoxWrapper;
class SpinnerImplementation;

typedef int (__fastcall* EDITBOX_FILTER)(EditBoxImplementation* pEditBox, SMSGHANDLER_PARAMS* pMsg);
typedef void (*EDITBOX_CALLBACK)();

#pragma pack(push, 2)

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
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
int __cdecl sub_004BB5D0_Return0()
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
    int bNumeric;
    int bAllowRepeat;
    Unicode* pText;
    Unicode* pTextCopy;
    int nMaxValue;
    unsigned short nMaxLength;
    int nCaret;
    int nTextLength;
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
    virtual int sub_004BBFB0_GetRepeatStep();

    int HitTestUpArrow(SMSGHANDLER_PARAMS* pMsg);
    int HitTestDownArrow(SMSGHANDLER_PARAMS* pMsg);

    int nX;
    int nY;
    int nUpX;
    int nUpY;
    int nDownX;
    int nDownY;
    int bWheelStep;
    int nArrowHeight;
    int nArrowWidth;
    int f_2C;
    int bMouseDown;
    int bUpPressed;
    int bDownPressed;
    void (__cdecl* pfUnk0x3C)();
    unsigned int nUnk0x3CCalls;
    unsigned int unk0x44;
    unsigned int dwLastStepTick;
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
int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00
int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
extern D2ButtonStringStrc gaButtonStrings[]; // 0x007275A8








int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

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


void __fastcall ARCHIVE_FreeClientCellFile(void* pCel);                                                                   // 0x00478A00

struct SMSGHANDLER_PARAMS;






















D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0




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
    bNumeric = nValue;
}

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

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
            const int nLength = UNICODE_StrLen(pText);
            for (nStart = 0; nStart < nLength; ++nStart)
            {
                if (D2Win_10121_GetTextWidth(&pText[nStart]) <= nTextWidth)
                {
                    break;
                }
            }
        }

        D2Win_10117_DrawText(&pText[nStart], nTextX, nTextY, 0, 0);
        if (nCaret < nMaxLength && unk0x4A && nCaret <= nTextLength)
        {
            if (UNICODE_StrLen(&pText[nStart]))
            {
                sub_005267E0(pTextCopy, pText);
                pTextCopy[nCaret] = 0;
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
        const int nLength = UNICODE_StrLen(pLine->wszLine);
        D2SplittedTextStrc* pNext = pLine->pNextLine;
        nChars += nLength;
        ++nLine;
        if (nCaret < nMaxLength && unk0x4A && nChars >= nCaret && !bDone)
        {
            bDone = 1;
            int nColumn = nCaret - nChars + nLength;
            if (nColumn < 0)
            {
                nColumn = 0;
            }
            if (UNICODE_StrLen(pLine->wszLine))
            {
                if (UNICODE_StrLen(pLine->wszLine) > 199)
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
    const int nLength = UNICODE_StrLen(pText);
    nCaret = nLength;
    nTextLength = nLength;
}

// 0x004BB530
void EditBoxImplementation::sub_004BB530_Slot14(const char* szText)
{
    sub_00526F20_ToUnicode(pText, szText, nMaxLength);
    const int nLength = UNICODE_StrLen(pText);
    nCaret = nLength;
    nTextLength = nLength;
}

// 0x004BB560
int EditBoxImplementation::GetValue()
{
    if (!UNICODE_StrLen(pText))
    {
        return 0;
    }
    char szBuffer[100];
    UNICODE_ToUtf8(szBuffer, pText, nMaxLength);
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
    UNICODE_ToUtf8(szBuffer, pText, nMaxLength);
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

// 0x004BB5E0
int EditBoxImplementation::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    unk0x3E = 1;
    return 0;
}

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

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);    // 0x00526F20
extern "C" const char gszFmtDecimal_006D57BC[];                                                             // 0x006D57BC

// 0x004BB620
int EditBoxImplementation::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (!bAllowRepeat && (pMsg->lParam & 0x40000000))
        return 1;

    if (pMsg->wParam > 0x7F)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }

    const char nChar = (char)pMsg->wParam;
    int bAccepted;
    if (unk0x04)
    {
        bAccepted = ((EDITBOX_FILTER)unk0x04)(this, pMsg);
    }
    else if (bNumeric)
    {
        bAccepted = isdigit(nChar);
    }
    else
    {
        bAccepted = D2Win_10128(nChar);
        if (nChar == '\r' || nChar == 0x1B)
        {
            ((EDITBOX_CALLBACK)unk0x42)();
            pMsg->lResult = 0;
            pMsg->bReturn = 1;
            sub_00420290_BreakHandlerChain(pMsg);
            return 1;
        }
    }

    if (nChar == 8)
    {
        if (nTextLength > 0)
        {
            if (nCaret != nTextLength && nCaret != 0)
            {
                for (int i = nCaret - 1; i < D2_MIN(nTextLength, nMaxLength) - 1; ++i)
                    pText[i] = pText[i + 1];
            }

            pText[nTextLength - 1] = 0;
            --nTextLength;
        }

        if (nCaret)
            --nCaret;

        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }

    if (nChar == 0x2E)
    {
        if (nTextLength > 0 && nCaret != nTextLength)
        {
            for (int i = nCaret; i < D2_MIN(nTextLength, nMaxLength); ++i)
                pText[i] = pText[i + 1];

            pText[nTextLength - 1] = 0;
            --nTextLength;
        }

        pMsg->lResult = 0;
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }

    if (bAccepted)
    {
        if (nTextLength < nMaxLength - 1)
        {
            if (nCaret == nTextLength)
            {
                pText[nCaret] = nChar;
                ++nCaret;
                pText[nCaret] = 0;
                ++nTextLength;
            }
            else
            {
                for (int i = D2_MIN(nTextLength, nMaxLength); i >= nCaret; --i)
                    pText[i] = pText[i - 1];

                if (nTextLength < nMaxLength)
                    ++nTextLength;

                pText[nTextLength] = 0;
                pText[nCaret] = nChar;
            }
        }

        if (nTextLength)
        {
            D2Win_10127_SetFont(nFont);
            int nLines;
            D2SplittedTextStrc* pLine = D2WINFONT_SplitText(pText, &nLines, nTextWidth);
            while (pLine)
            {
                D2SplittedTextStrc* pNext = pLine->pNextLine;
                FOG_Free(pLine->wszLine, ".\\UI\\editbox.cpp", 0x203, 0);
                FOG_Free(pLine, ".\\UI\\editbox.cpp", 0x204, 0);
                pLine = pNext;
            }

            if (nLines > nHeight)
            {
                --nTextLength;
                --nCaret;
                pText[nTextLength] = 0;
            }
        }

        if (!unk0x04 && UNICODE_StrLen(pText))
        {
            if (bNumeric)
            {
                char szValue[0x800];
                UNICODE_ToUtf8(szValue, pText, nMaxLength);
                const unsigned int nMax = nMaxValue;
                if (atoi(szValue) > nMax)
                {
                    sprintf(szValue, gszFmtDecimal_006D57BC, nMax);
                    memset(pText, 0, nMaxLength * 2);
                    sub_00526F20(pText, szValue, nMaxLength);
                    const int nNewLength = UNICODE_StrLen(pText);
                    nCaret = nNewLength;
                    nTextLength = nNewLength;
                }
            }
            else
            {
                nTextLength = UNICODE_StrLen(pText);
            }
        }
    }
    else if (nChar == ' ' || nChar == 0x1B || nChar == '\r')
    {
        return 0;
    }

    pMsg->lResult = 0;
    pMsg->bReturn = 1;
    sub_00420290_BreakHandlerChain(pMsg);
    return 1;
}

// 0x004BB950
int EditBoxImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BB960
int EditBoxImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

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
    bAllowRepeat = nValue;
}

// 0x004BB9B0
int EditBoxImplementation::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    if (nCaret < nTextLength)
        nCaret += 1;
    return 1;
}

// 0x004BB9D0
int EditBoxImplementation::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    if (nCaret > 0)
        nCaret -= 1;
    return 1;
}

// 0x004BB9F0
EditBoxWrapper::~EditBoxWrapper()
{
    delete pImpl;
}

// 0x004BBA80
int EditBoxWrapper::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnMouseWheel(pMsg);
}

// 0x004BBA90
int EditBoxWrapper::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonDown(pMsg);
}

// 0x004BBAA0
int EditBoxWrapper::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonUp(pMsg);
}

// 0x004BBAB0
int EditBoxWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// 0x004BBAC0
void EditBoxWrapper::Draw()
{
    pImpl->Draw();
}

int EditBoxWrapper::GetValue()
{
    return pImpl->GetValue();
}

// 0x004BBAD0
int EditBoxWrapper::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyDown(pMsg);
}

// 0x004BBAE0
int EditBoxWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// 0x004BBAF0
int EditBoxWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// 0x004BBB00
int EditBoxWrapper::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyRight(pMsg);
}

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
    nCaret = 0;
    nTextLength = 0;
    this->nFont = nFont;
    nTextX = nX + 1;
    nTextY = nY;
    bNumeric = 1;
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
    bAllowRepeat = 0;
    unk0x04 = 0;
}

// 0x004BBD80
EditBoxWrapper::EditBoxWrapper(int nX, int nY, int nTextWidth, int nHeight, int nArg10, unsigned short nMaxLength,
    int nArg18, int nFont)
{
    pImpl = new EditBoxImplementation(nX, nY, nTextWidth, nHeight, nArg10, nMaxLength, nArg18, nFont);
}








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




















struct D2CelFileStrc;







