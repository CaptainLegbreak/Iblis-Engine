#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2WinSplitText.h"

struct Unicode;
struct D2ButtonStringStrc;
// build: symbol ??_7SpinnerWrapper@@6B@ 0x006DA874

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
// build: symbol ??_7SpinnerImplementation@@6B@ 0x006DA83C
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






extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0






extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260
































// 0x004BBE10
SpinnerImplementation::~SpinnerImplementation()
{
    ARCHIVE_FreeClientCellFile(pCellFile);
}

// build: symbol ?Draw@SpinnerImplementation@@UAEXXZ 0x004BBE70
// 0x004BBE70
void SpinnerImplementation::Draw()
{
    if (unk0x38 || unk0x34)
    {
        ++nUnk0x3CCalls;
        pfUnk0x3C();
    }

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nFrame = 2 * unk0x34;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, nUpX, nUpY, -1, 5, 0);
    tContext.nFrame = 2 * unk0x38 + 1;
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









int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

// build: symbol ?GetValue@SpinnerImplementation@@UAEHXZ 0x004BBF90
int SpinnerImplementation::GetValue()
{
    if (unk0x34)
        return 1;
    return unk0x38 ? 2 : 0;
}

// 0x004BBFB0
int SpinnerImplementation::sub_004BBFB0()
{
    if (!unk0x34 && !unk0x38)
        return 0;

    if (unk0x20)
    {
        unk0x34 = 0;
        unk0x38 = 0;
        unk0x20 = 0;
        return 1;
    }

    unsigned long dwNow = GetTickCount();
    if (unk0x4C)
    {
        unk0x48 = dwNow;
        return 1;
    }

    unsigned long dwElapsed = dwNow - unk0x44;
    if (dwNow - unk0x48 < 0x46)
        return 0;

    unk0x48 = dwNow;
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

// build: symbol ?OnMouseWheel@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC050
// 0x004BC050
int SpinnerImplementation::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    if ((short)pMsg->wParamHigh > 0)
    {
        unk0x34 = 1;
        unk0x38 = 0;
        unk0x20 = 1;
    }
    else if ((short)pMsg->wParamHigh < 0)
    {
        unk0x34 = 0;
        unk0x38 = 1;
        unk0x20 = 1;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
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

// build: symbol ?OnLButtonUp@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC160
// 0x004BC160
int SpinnerImplementation::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    if (!unk0x30)
    {
        return 0;
    }

    nUnk0x3CCalls = 0;
    unk0x30 = 0;
    if (unk0x34 == 1)
    {
        unk0x34 = 0;
        return 1;
    }

    if (unk0x38 == 1)
    {
        unk0x38 = 0;
        return 1;
    }

    return 0;
}

// build: symbol ?OnKeyDown@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC190
// 0x004BC190
int SpinnerImplementation::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// build: symbol ?MsgSlot05@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC1A0
// 0x004BC1A0
int SpinnerImplementation::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// build: symbol ?MsgSlot07@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC1B0
// 0x004BC1B0
int SpinnerImplementation::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// build: symbol ?MsgSlot08@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC1C0
// 0x004BC1C0
int SpinnerImplementation::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// build: symbol ?OnKeyRight@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC1D0
// 0x004BC1D0
int SpinnerImplementation::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return 0;
}
// build: symbol ?OnKeyLeft@SpinnerImplementation@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC1E0
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

// build: symbol ?OnMouseWheel@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC280
// 0x004BC280
int SpinnerWrapper::OnMouseWheel(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnMouseWheel(pMsg);
}

// build: symbol ?OnLButtonDown@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC290
// 0x004BC290
int SpinnerWrapper::OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonDown(pMsg);
}

// build: symbol ?OnLButtonUp@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC2A0
// 0x004BC2A0
int SpinnerWrapper::OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnLButtonUp(pMsg);
}

// build: symbol ?MsgSlot05@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC2B0
// 0x004BC2B0
int SpinnerWrapper::MsgSlot05(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot05(pMsg);
}

// build: symbol ?Draw@SpinnerWrapper@@UAEXXZ 0x004BC2C0
// 0x004BC2C0
void SpinnerWrapper::Draw()
{
    pImpl->Draw();
}

// build: symbol ?OnKeyDown@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC2D0
// 0x004BC2D0
int SpinnerWrapper::OnKeyDown(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyDown(pMsg);
}

// build: symbol ?MsgSlot08@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC2E0
// 0x004BC2E0
int SpinnerWrapper::MsgSlot08(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot08(pMsg);
}

// build: symbol ?MsgSlot07@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC2F0
// 0x004BC2F0
int SpinnerWrapper::MsgSlot07(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->MsgSlot07(pMsg);
}

// build: symbol ?OnKeyRight@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC300
// 0x004BC300
int SpinnerWrapper::OnKeyRight(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyRight(pMsg);
}

// build: symbol ?OnKeyLeft@SpinnerWrapper@@UAEHPAUSMSGHANDLER_PARAMS@@@Z 0x004BC310
// 0x004BC310
int SpinnerWrapper::OnKeyLeft(SMSGHANDLER_PARAMS* pMsg)
{
    return pImpl->OnKeyLeft(pMsg);
}

// build: symbol ?GetValue@SpinnerWrapper@@UAEHXZ 0x004BC320
// 0x004BC320
int SpinnerWrapper::GetValue()
{
    return pImpl->GetValue();
}

// 0x004BC330
int SpinnerWrapper::sub_004BC330_ForwardSlot30(int nArg)
{
    return pImpl->sub_004BBFB0();
}

// build: symbol ??_GSpinnerImplementation@@UAEPAXI@Z 0x004BC450
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
    unk0x34 = 0;
    unk0x38 = 0;
    unk0x30 = 0;
    unk0x4C = 0;
    nUnk0x3CCalls = 0;
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pFile;
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

#include "gen/data/Source/D2Client/Unknown_004BBE10.inc"





