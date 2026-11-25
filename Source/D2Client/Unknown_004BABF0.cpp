#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinSplitText.h"

struct Unicode;
struct D2ButtonStringStrc;
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
// build: symbol ??_7ButtonImplementation@@6B@ 0x006DA6F4
// build: symbol ??_7ButtonWrapper@@6B@ 0x006DA72C
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

    UIWidget();
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

// 0x004BAFD0
class ButtonImplementation : public UIWidget
{
public:
    ButtonImplementation(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)());
    virtual ~ButtonImplementation();
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
    virtual void sub_004BAC60_SetUnk24(int nValue);

    int HitTestButton(SMSGHANDLER_PARAMS* pMsg);

    int nX;
    int nY;
    int unk0x10[2];
    int nHeight;
    int nWidth;
    int f_20;
    int unk0x24;
    int (__cdecl* pfnCallback)();
    int unk0x2C;
    unsigned short nBaseFrame;
    int nStringSlot;
};

// 0x004BAE30
class ButtonWrapper : public UIWidget
{
public:
    ButtonWrapper(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)());
    virtual ~ButtonWrapper();
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
    virtual void sub_004BAF10_SetUnk24(int nValue);

    ButtonImplementation* pImpl;
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

// build: symbol ??1ButtonImplementation@@UAE@XZ 0x004BABF0
// 0x004BABF0
ButtonImplementation::~ButtonImplementation()
{
}

// 0x004BAC00
int ButtonImplementation::HitTestButton(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX < nX || nMouseX > nX + nWidth || nMouseY < nY - nHeight || nMouseY > nY)
    {
        return 0;
    }
    return 1;
}

// build: symbol ?GetValue@ButtonImplementation@@UAEHXZ 0x004BAC50
// 0x004BAC50
int ButtonImplementation::GetValue()
{
    return 0;
}

// 0x004BAC60
void ButtonImplementation::sub_004BAC60_SetUnk24(int nValue)
{
    unk0x24 = nValue;
}

// build: symbol ?OnLButtonDown@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAC70
// 0x004BAC70
int ButtonImplementation::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (HitTestButton(pMsg))
    {
        f_20 = 1;
        sub_004B9A00(4, 0, 0, 0, 0);
        return 1;
    }
    return 0;
}

// build: symbol ?OnLButtonUp@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BACD0
// 0x004BACD0
int ButtonImplementation::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (!f_20)
    {
        return 0;
    }
    if (HitTestButton(pMsg))
    {
        f_20 = 0;
        return pfnCallback();
    }
    unk0x2C = 0;
    f_20 = 0;
    return 0;
}


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

// build: symbol ?OnKeyDown@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAD40
// 0x004BAD40
int ButtonImplementation::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x24 && !(pMsg->lParam & 0x40000000) && pMsg->wParam == 0x0D)
    {
        return pfnCallback();
    }

    return 0;
}

// build: symbol ?MsgSlot05@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAD70
// 0x004BAD70
int ButtonImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?MsgSlot07@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAD80
// 0x004BAD80
int ButtonImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?MsgSlot08@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAD90
// 0x004BAD90
int ButtonImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?OnKeyRight@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BADA0
// 0x004BADA0
int ButtonImplementation::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?OnKeyLeft@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BADB0
// 0x004BADB0
int ButtonImplementation::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ?OnMouseWheel@ButtonImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BADC0
// 0x004BADC0
int ButtonImplementation::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// 0x004BADD0
ButtonWrapper::~ButtonWrapper()
{
    delete pImpl;
}

// build: symbol ?OnMouseWheel@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE60
// 0x004BAE60
int ButtonWrapper::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnMouseWheel(pMsg);
}

// build: symbol ?OnLButtonDown@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE70
// 0x004BAE70
int ButtonWrapper::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonDown(pMsg);
}

// build: symbol ?OnLButtonUp@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE80
// 0x004BAE80
int ButtonWrapper::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonUp(pMsg);
}

// build: symbol ?MsgSlot05@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAE90
// 0x004BAE90
int ButtonWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// build: symbol ?Draw@ButtonWrapper@@UAEXXZ 0x004BAEA0
// 0x004BAEA0
void ButtonWrapper::Draw()
{
    pImpl->Draw();
}

// build: symbol ?OnKeyDown@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEB0
// 0x004BAEB0
int ButtonWrapper::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyDown(pMsg);
}

// build: symbol ?MsgSlot08@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEC0
// 0x004BAEC0
int ButtonWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// build: symbol ?MsgSlot07@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAED0
// 0x004BAED0
int ButtonWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// build: symbol ?OnKeyRight@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEE0
// 0x004BAEE0
int ButtonWrapper::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyRight(pMsg);
}

// build: symbol ?OnKeyLeft@ButtonWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BAEF0
// 0x004BAEF0
int ButtonWrapper::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyLeft(pMsg);
}

// build: symbol ?GetValue@ButtonWrapper@@UAEHXZ 0x004BAF00
// 0x004BAF00
int ButtonWrapper::GetValue()
{
    return pImpl->GetValue();
}

// 0x004BAF10
void ButtonWrapper::sub_004BAF10_SetUnk24(int nValue)
{
    pImpl->sub_004BAC60_SetUnk24(nValue);
}

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern "C" D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext);                                        // 0x00601840

extern "C" int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

extern "C" int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// 0x004BAF20
ButtonImplementation::ButtonImplementation(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)())
{
    nBaseFrame = gaButtonStrings[nStringSlot].nCelFrame;
    this->nStringSlot = nStringSlot;
    this->pfnCallback = pfnCallback;
    f_20 = 0;
    unk0x2C = 0;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nDirection = 0;
    tContext.nFrame = nBaseFrame;
    D2CelStrc* pCel = CelGetHandle(&tContext);
    this->nX = nX;
    this->nY = nY;
    unk0x24 = 0;
    nHeight = CelGetHeight(pCel);
    nWidth = CelGetWidth(pCel);
}

// build: symbol ?Draw@ButtonImplementation@@UAEXXZ 0x004BB000
// 0x004BB000
void ButtonImplementation::Draw()
{
    D2CelContextStrc tCelContext;
    memset(&tCelContext, 0, sizeof(tCelContext));
    tCelContext.pCellFile = sub_00454600();
    tCelContext.nFrame = f_20 + nBaseFrame;
    tCelContext.nDirection = 0;
    sub_004F6480(&tCelContext, nX, nY, -1, 5, 0);

    const int nMouseX = sub_00468730();
    const unsigned int dwMousePos = ((unsigned short)sub_00468740() << 16) | (unsigned short)nMouseX;
    const int nPosX = (unsigned short)dwMousePos;
    const int nPosY = dwMousePos >> 16;
    if (nPosX >= nX && nPosX <= nX + nWidth && nPosY >= nY - nHeight && nPosY <= nY)
    {
        const int nOldFont = D2Win_10127_SetFont(1);
        const Unicode* wszText = D2LANG_GetStringFromTblIndex(gaButtonStrings[nStringSlot].nStringIndex);
        const int nTextWidth = D2Win_10121_GetTextWidth(wszText);
        D2Win_10117_DrawText(wszText, nX + (nWidth - nTextWidth) / 2, nY - nHeight - 5, 0, 0);
        D2Win_10127_SetFont(nOldFont);
    }
}

// 0x004BB0F0
ButtonWrapper::ButtonWrapper(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)())
{
    pImpl = new ButtonImplementation(nX, nY, nStringSlot, pfnCallback);
}



extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0






extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260












































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

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// build: symbol ??_7UIWidget@@6B@ 0x006DA6C0
// 0x004BABE0
UIWidget::UIWidget()
{
}


#include "gen/data/Source/D2Client/Unknown_004BABF0.inc"





