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
#include "D2CMPApi.h"
#include "StormApi2.h"
#include "D2WinApi2.h"

struct Unicode;
struct D2ButtonStringStrc;
class UIWidget;
class ButtonImplementation;
class EditBoxImplementation;
class ButtonWrapper;
class EditBoxWrapper;
class SpinnerImplementation;

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
extern D2ButtonStringStrc gaButtonStrings[]; // 0x007275A8

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

// 0x004BAD40
int ButtonImplementation::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    if (unk0x24 && !(pMsg->lParam & 0x40000000) && pMsg->wParam == 0x0D)
    {
        return pfnCallback();
    }

    return 0;
}

// 0x004BAD70
int ButtonImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BAD80
int ButtonImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BAD90
int ButtonImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BADA0
int ButtonImplementation::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BADB0
int ButtonImplementation::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BADC0
int ButtonImplementation::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BADD0
ButtonWrapper::~ButtonWrapper()
{
    delete pImpl;
}

// 0x004BAE60
int ButtonWrapper::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnMouseWheel(pMsg);
}

// 0x004BAE70
int ButtonWrapper::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonDown(pMsg);
}

// 0x004BAE80
int ButtonWrapper::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonUp(pMsg);
}

// 0x004BAE90
int ButtonWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// 0x004BAEA0
void ButtonWrapper::Draw()
{
    pImpl->Draw();
}

// 0x004BAEB0
int ButtonWrapper::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyDown(pMsg);
}

// 0x004BAEC0
int ButtonWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// 0x004BAED0
int ButtonWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// 0x004BAEE0
int ButtonWrapper::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyRight(pMsg);
}

// 0x004BAEF0
int ButtonWrapper::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyLeft(pMsg);
}

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


D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern "C" D2CelStrc* __stdcall CelGetHandle(D2GfxDataStrc* pContext);                                        // 0x00601840

// 0x004BAF20
ButtonImplementation::ButtonImplementation(int nX, int nY, int nStringSlot, int (__cdecl* pfnCallback)())
{
    nBaseFrame = gaButtonStrings[nStringSlot].nCelFrame;
    this->nStringSlot = nStringSlot;
    this->pfnCallback = pfnCallback;
    f_20 = 0;
    unk0x2C = 0;
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = sub_00454600();
    tContext.nDirection = 0;
    tContext.nFrame = nBaseFrame;
    D2CelStrc* pCel = CelGetHandle(&tContext);
    this->nX = nX;
    this->nY = nY;
    unk0x24 = 0;
    nHeight = CelGetHeight(pCel);
    nWidth = CelGetWidth(pCel);
}

// 0x004BB000
void ButtonImplementation::Draw()
{
    D2GfxDataStrc tCelContext;
    memset(&tCelContext, 0, sizeof(tCelContext));
    tCelContext.pCelFile = sub_00454600();
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

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0






extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
































































struct D2CelFileStrc;

// 0x004BABE0
UIWidget::UIWidget()
{
}


extern D2ButtonStringStrc gaButtonStrings[2] = {
    { 0x10, 0xD49 },
    { 0xA, 0x102E }
}; // 0x007275A8





