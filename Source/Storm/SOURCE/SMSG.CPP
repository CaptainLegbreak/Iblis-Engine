#include "D2StormTypes.h"
#include "Storm.h"
#include "D2GameTypes.h"
#include "stpl.h"
#include "D2Win32Message.h"
#include "StormApi.h"

struct HWND__;

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

struct SMSGHANDLER_PARAMS;

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode);

struct WNDREC : TSLinkedNode<WNDREC>
{
    void* hWnd;                                             // 0x08

    ~WNDREC()
    {
    }
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, gszDelete_006CC824, -1, 0);
    }
};


typedef int (__stdcall* SMSGIDLEPROC)(int nCount);

extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x006CC488
extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg);                  // 0x006CC478
extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg);                  // 0x006CC47C

int __stdcall SEvtBreakHandlerChain(void* pData); // 0x00426E80
int __stdcall SEvtDispatch(unsigned int nType, void* hWnd, unsigned int nId, SMSGHANDLER_PARAMS* pParams); // 0x00426F90
int __stdcall SEvtPushState(unsigned int nType, unsigned int nSubtype); // 0x00426370
int __stdcall SEvtRegisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, int nFlags, SMSGHANDLER pHandler); // 0x00426420
int __stdcall SEvtUnregisterHandler(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler); // 0x00426720
int __stdcall SEvtUnregisterType(unsigned int nType, void* hWnd); // 0x00426810
int __stdcall SEvtPopState(unsigned long dwId, void* pContext); // 0x004269C0

int __stdcall SMsgRegisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);
int __stdcall SMsgRegisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);
int __stdcall SMsgRegisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);
int __stdcall SMsgRegisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

static int __stdcall InternalRegister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler);

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

// build: symbol ??__EgWndRecList_00708860@@YAXXZ 0x006CA8E0
// build: symbol ??__FgWndRecList_00708860@@YAXXZ 0x006CB310
TSList<WNDREC> gWndRecList_00708860; // 0x00708860

void* gdwGlobal_007792F4; // 0x007792F4

// build: symbol ??_R0?AUWNDREC@@@8 0x00708848
// build: symbol _SMemAlloc@16 0x00413020
// build: symbol _SMemFree@16 0x00412650
// build: symbol ?Next@?$TSLink@UWNDREC@@@@QAEPAUWNDREC@@XZ 0x004203C0
// build: symbol ?RawNext@?$TSLink@UWNDREC@@@@QAEPAUWNDREC@@XZ 0x004203D0
// build: symbol ?NextLink@?$TSLink@UWNDREC@@@@QAEPAU1@H@Z 0x004203F0
// build: symbol ?Unlink@?$TSLink@UWNDREC@@@@QAEXXZ 0x00420430
// build: symbol ?InitializeTerminator@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXXZ 0x00420470
// build: symbol ?Head@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@XZ 0x00420490
// build: symbol ??0?$TSLink@UWNDREC@@@@QAE@XZ 0x004204A0
// build: symbol ??0?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAE@XZ 0x004206A0
// build: symbol ?Link@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAU?$TSLink@UWNDREC@@@@PBUWNDREC@@@Z 0x00420520
// build: symbol ?LinkNode@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXPAUWNDREC@@I0@Z 0x00420540
// build: symbol ?Next@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@PBU2@@Z 0x004205F0
// build: symbol ??1?$TSLink@UWNDREC@@@@QAE@XZ 0x00420610
// build: symbol ?UnlinkNode@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXPAUWNDREC@@@Z 0x00420650
// build: symbol ?IsEmpty@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEHXZ 0x004206C0
// build: symbol ?RawNext@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@PBU2@@Z 0x004206E0
// build: symbol ??0?$TSLinkedNode@UWNDREC@@@@QAE@XZ 0x00420700
// build: symbol ??1?$TSLinkedNode@UWNDREC@@@@QAE@XZ 0x00420710
// build: symbol ?UnlinkAll@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEXXZ 0x00420750
// build: symbol ??1?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAE@XZ 0x00420790
// build: symbol ??0WNDREC@@QAE@XZ 0x004207D0
// build: symbol ??1WNDREC@@QAE@XZ 0x004207E0
// build: symbol ?NewNode@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@III@Z 0x00420820
// build: symbol ??_GWNDREC@@QAEPAXI@Z 0x00420880
// build: symbol ?DeleteNode@?$TSList@UWNDREC@@U?$TSGetLink@UWNDREC@@@@@@QAEPAUWNDREC@@PAU2@@Z 0x00420970
template WNDREC* TSLink<WNDREC>::Next();
template WNDREC* TSLink<WNDREC>::RawNext();
template TSLink<WNDREC>* TSLink<WNDREC>::NextLink(int);
template void TSLink<WNDREC>::Unlink();
template void TSList<WNDREC>::InitializeTerminator();
template WNDREC* TSList<WNDREC>::Head();
template TSLink<WNDREC>::TSLink();
template TSLink<WNDREC>::~TSLink();
template TSList<WNDREC>::TSList();
template TSLink<WNDREC>* TSList<WNDREC>::Link(const WNDREC*);
template void TSList<WNDREC>::LinkNode(WNDREC*, unsigned int, WNDREC*);
template WNDREC* TSList<WNDREC>::Next(const WNDREC*);
template void TSList<WNDREC>::UnlinkNode(WNDREC*);
template int TSList<WNDREC>::IsEmpty();
template WNDREC* TSList<WNDREC>::RawNext(const WNDREC*);
template void TSList<WNDREC>::UnlinkAll();
template TSList<WNDREC>::~TSList();
template WNDREC* TSList<WNDREC>::NewNode(unsigned int, unsigned int, unsigned int);
template WNDREC* TSList<WNDREC>::DeleteNode(WNDREC*);

// The run's list pieces that match no stpl.h member, on a link without a destructor.
struct D2SMsgLinkStrc
{
    D2SMsgLinkStrc* m_prevlink;                             // 0x00
    char* m_next;                                           // 0x04

    D2SMsgLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    D2SMsgLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2SMsgLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2SMsgLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2SMsgListStrc
{
    int m_linkoffset;                                       // 0x00
    D2SMsgLinkStrc m_terminator;                            // 0x04

    void sub_0060E5F0_Reset();
};

struct D2SMsgPairStrc
{
    int nFirst;                                             // 0x00
    int nSecond;                                            // 0x04
};

struct sub_004204B0
{
    D2SMsgLinkStrc tLink;                                   // 0x00

    ~sub_004204B0();
};

struct D2Strc00420D80
{
    int f_0;
    int f_4;
    int f_8;
    void Clear(); // 0x00420D80
};

struct D2Strc00420DA0
{
    int f_0;
    int nEnd;
    int f_8;
    int nFieldC;
    int nStart;
    int GetSpan(); // 0x00420DA0
};

// 0x004203E0
void __fastcall sub_004203E0(D2SMsgPairStrc* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x00420420
D2SMsgLinkStrc* __fastcall sub_00420420_Identity(D2SMsgLinkStrc* pLink)
{
    return pLink;
}

// 0x00420480
D2SMsgLinkStrc* __fastcall sub_00420480_Identity(D2SMsgLinkStrc* pLink)
{
    return pLink;
}

// 0x004204B0
sub_004204B0::~sub_004204B0()
{
    tLink.Unlink();
}

// 0x004204F0
char* __fastcall sub_00601B60_LinkNext(D2SMsgLinkStrc* pLink)
{
    return (int)pLink->m_next > 0 ? pLink->m_next : 0;
}

// 0x00420500
void D2SMsgListStrc::sub_0060E5F0_Reset()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x00420D80
void D2Strc00420D80::Clear()
{
    f_0 = 0;
    f_4 = 0;
    f_8 = 0;
}

// 0x00420DA0
int D2Strc00420DA0::GetSpan()
{
    return nEnd - nStart;
}

// 0x00420290
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg)
{
    return SEvtBreakHandlerChain(pMsg);
}

// 0x004202A0
unsigned int __stdcall SMsgDoMessageLoop(SMSGIDLEPROC pfIdle, int bCleanUponQuit)
{
    D2WinMsgStrc tMsg;
    int nCount = 0;
    for (;;)
    {
        if (PeekMessageA(&tMsg, 0, 0, 0, 0) || !pfIdle || !pfIdle(nCount++))
        {
            nCount = 0;
            if (!GetMessageA(&tMsg, 0, 0, 0))
            {
                break;
            }
            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
        }
    }
    return tMsg.wParam;
}

// 0x00420310
void* __cdecl SMsgGetDefaultWindow()
{
    return gdwGlobal_007792F4;
}

// 0x00420320
int __stdcall SMsgPopRegisterState(void* pContext)
{
    SEvtPopState(0x534D5348, pContext);
    SEvtPopState(0x534D5349, pContext);
    SEvtPopState(0x534D534A, pContext);
    SEvtPopState(0x534D5347, pContext);
    return 1;
}

// 0x00420360
int __stdcall SMsgPushRegisterState(int nType)
{
    SEvtPushState('SMSH', nType);
    SEvtPushState('SMSI', nType);
    SEvtPushState('SMSJ', nType);
    SEvtPushState('SMSG', nType);
    return 1;
}

// 0x004203A0
int __stdcall SMsgSetDefaultWindow(void* hWnd)
{
    gdwGlobal_007792F4 = hWnd;
    return 1;
}

// 0x004208E0
void __stdcall AddWindow(void* hWnd)
{
    WNDREC* pNode = gWndRecList_00708860.NewNode(2, 0, 0);
    pNode->hWnd = hWnd;
}

// 0x004209E0
static WNDREC* FindWindow(void* hWnd)
{
    for (WNDREC* pNode = gWndRecList_00708860.Head(); _ReadWriteBarrier(), (int)pNode > 0; pNode = pNode->m_link.m_next)
    {
        if (pNode->hWnd == hWnd)
            return pNode;
    }
    return 0;
}

// 0x00420A10
static void DeleteWindow(void* hWnd)
{
    if (hWnd == gdwGlobal_007792F4)
    {
        gdwGlobal_007792F4 = 0;
    }
    WNDREC* pRec = FindWindow(hWnd);
    if (pRec)
    {
        SEvtUnregisterType(0x534D5347, hWnd);
        SEvtUnregisterType(0x534D5348, hWnd);
        SEvtUnregisterType(0x534D534A, hWnd);
        SEvtUnregisterType(0x534D5349, hWnd);
        gWndRecList_00708860.DeleteNode(pRec);
    }
}

// 0x00420A70
static int __stdcall InternalRegister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    VALIDATEBEGIN;
    VALIDATE(pHandler);
    VALIDATEEND;
    if (!FindWindow(hWnd))
    {
        AddWindow(hWnd);
    }
    return nValid ? SEvtRegisterHandler(nType, hWnd, nId, 0, pHandler) : 0;
}

// 0x00420AB0
static int __stdcall InternalUnregister(unsigned int nType, HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    if (!FindWindow(hWnd))
    {
        AddWindow(hWnd);
    }
    return SEvtUnregisterHandler(nType, hWnd, nId, pHandler);
}

// 0x00420AE0
int DeleteAllWindows()
{
    while (WNDREC* pRec = gWndRecList_00708860.Head())
    {
        DeleteWindow(pRec->hWnd);
    }
    return 1;
}

// 0x00420B00
int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam, int* pbUseResult, int* plResult)
{
    if (pbUseResult)
    {
        *pbUseResult = 0;
    }
    if (plResult)
    {
        *plResult = 0;
    }
    SMSGHANDLER_PARAMS tParams;
    tParams.hWnd = hWnd;
    tParams.uMessage = uMsg;
    tParams.wParam = wParam;
    tParams.lParam = lParam;
    if (uMsg == 0x111)
    {
        tParams.dwCommandSource = wParam >> 0x10;
    }
    else
    {
        tParams.dwCommandSource = 0;
    }
    tParams.bReturn = 0;
    tParams.lResult = 0;
    void* hTarget = hWnd;
    for (;;)
    {
        SEvtDispatch(0x534D5347, hTarget, uMsg, &tParams);
        if (uMsg == 0x111)
        {
            SEvtDispatch(0x534D5348, hTarget, (unsigned short)wParam, &tParams);
        }
        else if (uMsg == 0x100)
        {
            SEvtDispatch(0x534D5349, hTarget, wParam, &tParams);
        }
        else if (uMsg == 0x101)
        {
            SEvtDispatch(0x534D534A, hTarget, wParam, &tParams);
        }
        if (!hTarget || hTarget != gdwGlobal_007792F4)
        {
            break;
        }
        hTarget = 0;
    }
    if (uMsg == 0x82)
    {
        DeleteWindow(hWnd);
    }
    if (pbUseResult)
    {
        *pbUseResult = tParams.bReturn;
    }
    if (plResult)
    {
        *plResult = tParams.lResult;
    }
    return 1;
}

// 0x00420BF0
int __stdcall SMsgRegisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D5348, hWnd, nId, pHandler);
}

// 0x00420C10
int __stdcall SMsgRegisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D5349, hWnd, nId, pHandler);
}

// 0x00420C30
int __stdcall SMsgRegisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D534A, hWnd, nId, pHandler);
}

// 0x00420C50
int __stdcall SMsgRegisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalRegister(0x534D5347, hWnd, nId, pHandler);
}

// 0x00420C70
int __stdcall SMsgUnregisterCommand(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D5348, hWnd, nId, pHandler);
}

// 0x00420C90
int __stdcall SMsgUnregisterKeyDown(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D5349, hWnd, nId, pHandler);
}

// 0x00420CB0
int __stdcall SMsgUnregisterKeyUp(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D534A, hWnd, nId, pHandler);
}

// 0x00420CD0
int __stdcall SMsgUnregisterMessage(HWND__* hWnd, unsigned int nId, SMSGHANDLER pHandler)
{
    return InternalUnregister(0x534D5347, hWnd, nId, pHandler);
}

// 0x00420CF0
int __stdcall DispatcherWindowProc(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam)
{
    int bUseResult = 0;
    int lResult = 0;
    if (SMsgDispatchMessage(hWnd, uMsg, wParam, lParam, &bUseResult, &lResult) && bUseResult)
        return lResult;
    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// 0x00420D50
int __stdcall SMsgGetDispatcher(int a1)
{
    VALIDATEBEGIN;
    VALIDATE(!a1);
    VALIDATEEND;
    return nValid ? (int)&DispatcherWindowProc : 0;
}

// 0x00420D90
WNDREC* __fastcall DRLGPRESET_GetLinkRawNext(TSLink<WNDREC>* pLink)
{
    return pLink->m_next;
}
