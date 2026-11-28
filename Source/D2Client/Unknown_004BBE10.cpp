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

extern "C" D2CelStrc* __stdcall CelGetHandle(D2GfxDataStrc* pContext);                                        // 0x00601840

extern "C" int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

extern "C" int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0






extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0






extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
































// 0x004BBE10
SpinnerImplementation::~SpinnerImplementation()
{
    ARCHIVE_FreeClientCellFile(pCellFile);
}

// 0x004BBE70
void SpinnerImplementation::Draw()
{
    if (bDownPressed || bUpPressed)
    {
        ++nUnk0x3CCalls;
        pfUnk0x3C();
    }

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = pCellFile;
    tContext.nFrame = 2 * bUpPressed;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nUpX, nUpY, -1, 5, 0);
    tContext.nFrame = 2 * bDownPressed + 1;
    sub_004F6480(&tContext, nDownX, nDownY, -1, 5, 0);
}

// 0x004BBEF0
int SpinnerImplementation::HitTestUpArrow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX <= nUpX || nMouseX >= nUpX + nArrowWidth || nMouseY <= nUpY - nArrowHeight || nMouseY > nUpY)
    {
        return 0;
    }
    return 1;
}

// 0x004BBF40
int SpinnerImplementation::HitTestDownArrow(SMSGHANDLER_PARAMS* pMsg)
{
    const int nMouseX = pMsg->nXpos;
    const int nMouseY = pMsg->nYpos;
    if (nMouseX <= nDownX || nMouseX >= nDownX + nArrowWidth || nMouseY <= nDownY - nArrowHeight || nMouseY >= nDownY)
    {
        return 0;
    }
    return 1;
}










int SpinnerImplementation::GetValue()
{
    if (bUpPressed)
        return 1;
    return bDownPressed ? 2 : 0;
}

// 0x004BBFB0
int SpinnerImplementation::sub_004BBFB0_GetRepeatStep()
{
    if (!bUpPressed && !bDownPressed)
        return 0;

    if (bWheelStep)
    {
        bUpPressed = 0;
        bDownPressed = 0;
        bWheelStep = 0;
        return 1;
    }

    unsigned long dwNow = GetTickCount();
    if (unk0x4C)
    {
        dwLastStepTick = dwNow;
        return 1;
    }

    unsigned long dwElapsed = dwNow - unk0x44;
    if (dwNow - dwLastStepTick < 0x46)
        return 0;

    dwLastStepTick = dwNow;
    if (dwElapsed > 0x1000)
        return (dwElapsed >> 11) * nUnk0x3CCalls;
    if (dwElapsed > 0xBB8)
        return nUnk0x3CCalls >> 2;
    if (dwElapsed > 0x7D0)
        return nUnk0x3CCalls >> 4;
    if (dwElapsed > 0x3E8)
        return nUnk0x3CCalls >> 5;
    return 1;
}

// 0x004BC050
int SpinnerImplementation::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    if ((short)pMsg->wParamHigh > 0)
    {
        bUpPressed = 1;
        bDownPressed = 0;
        bWheelStep = 1;
    }
    else if ((short)pMsg->wParamHigh < 0)
    {
        bUpPressed = 0;
        bDownPressed = 1;
        bWheelStep = 1;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    SMsgBreakHandlerChain(pMsg);
    return 1;
}
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

// 0x004BC0A0
int __fastcall EDITBOX_HandleSpinnerPress(D2ButtonPairStrc* pButtons, int nUnused, D2MouseMessageStrc* pMessage)
{
    pButtons->f_30 = 1;
    if (sub_004BC0A0_IsInFirst(pButtons, pMessage))
    {
        pButtons->nTick = GetTickCount();
        pButtons->bFirst = 1;
        pButtons->bInvoking = 1;
        pButtons->pCallback();
        pButtons->bInvoking = 0;
        return 1;
    }
    _ReadWriteBarrier();
    if (sub_004BC0A0_IsInSecond(pButtons, pMessage))
    {
        pButtons->nTick = GetTickCount();
        pButtons->bSecond = 1;
        pButtons->bInvoking = 1;
        pButtons->pCallback();
        pButtons->bInvoking = 0;
        return 1;
    }
    return 0;
}

// 0x004BC160
int SpinnerImplementation::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (!bMouseDown)
    {
        return 0;
    }

    nUnk0x3CCalls = 0;
    bMouseDown = 0;
    if (bUpPressed == 1)
    {
        bUpPressed = 0;
        return 1;
    }

    if (bDownPressed == 1)
    {
        bDownPressed = 0;
        return 1;
    }

    return 0;
}

// 0x004BC190
int SpinnerImplementation::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// 0x004BC1A0
int SpinnerImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// 0x004BC1B0
int SpinnerImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// 0x004BC1C0
int SpinnerImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// 0x004BC1D0
int SpinnerImplementation::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// 0x004BC1E0
int SpinnerImplementation::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}

// 0x004BC1F0
SpinnerWrapper::~SpinnerWrapper()
{
    delete pImpl;
}

// 0x004BC280
int SpinnerWrapper::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnMouseWheel(pMsg);
}

// 0x004BC290
int SpinnerWrapper::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonDown(pMsg);
}

// 0x004BC2A0
int SpinnerWrapper::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonUp(pMsg);
}

// 0x004BC2B0
int SpinnerWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// 0x004BC2C0
void SpinnerWrapper::Draw()
{
    pImpl->Draw();
}

// 0x004BC2D0
int SpinnerWrapper::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyDown(pMsg);
}

// 0x004BC2E0
int SpinnerWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// 0x004BC2F0
int SpinnerWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// 0x004BC300
int SpinnerWrapper::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyRight(pMsg);
}

// 0x004BC310
int SpinnerWrapper::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyLeft(pMsg);
}

// 0x004BC320
int SpinnerWrapper::GetValue()
{
    return pImpl->GetValue();
}

// 0x004BC330
int SpinnerWrapper::sub_004BC330_ForwardSlot30(int nArg)
{
    return pImpl->sub_004BBFB0_GetRepeatStep();
}

// 0x004BC340
SpinnerImplementation::SpinnerImplementation(int nX, int nY, int bHorizontal, int nArg0C)
{
    char szPath[260];
    sprintf(szPath, "%s\\ui\\menu\\spinner", gszDataGlobal);
    void* pFile = ARCHIVE_LoadClientCellFile(szPath, 0);
    pCellFile = pFile;
    this->nX = nX;
    this->nY = nY;
    pfUnk0x3C = (void (__cdecl*)())nArg0C;
    this->f_2C = bHorizontal;
    bUpPressed = 0;
    bDownPressed = 0;
    bMouseDown = 0;
    unk0x4C = 0;
    nUnk0x3CCalls = 0;
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = pFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    D2CelStrc* pCel = CelGetHandle(&tContext);
    nArrowHeight = CelGetHeight(pCel);
    nArrowWidth = CelGetWidth(pCel);
    nUpY = nY;
    if (this->f_2C)
    {
        nUpX = nX + 1;
        nDownX = nX + nArrowWidth;
        nDownY = nY;
    }
    else
    {
        nUpX = nX + 1;
        nDownX = nX + 1;
        nDownY = nY + nArrowHeight + 1;
    }
}
// 0x004BC480
SpinnerWrapper::SpinnerWrapper(int nX, int nY, int bHorizontal, int nArg0C)
{
    pImpl = new SpinnerImplementation(nX, nY, bHorizontal, nArg0C);
}

struct D2CelFileStrc;







