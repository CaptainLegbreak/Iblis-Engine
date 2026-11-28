#include "D2Win.h"
#include "D2GameTypes.h"

#include "D2SkillIds.h"

#include "D2StatIds.h"

#include "D2Win32Types.h"

#include "D2CelContext.h"

#include "D2CmpTypes.h"

#include "D2ClientTypes.h"

#include "D2WinTypes.h"

#include "D2Unicode.h"

#include "D2StormTypes.h"

#include "D2WinControls.h"
#include "FogApi.h"

enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};



extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210



#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __fastcall TIMER_UpdateDefault(D2WinControlStrc* pControl);                                                    // 0x004FD860

int __fastcall TIMER_UpdateRepeating(D2WinControlStrc* pControl);                                                    // 0x004FD8F0

void __stdcall CONTROL_RemoveFromList(void* pArg); // 0x004F9310

// 0x004FD820
void __fastcall TIMER_Destroy(void* pArg)
{
    CONTROL_RemoveFromList(pArg);
}

// 0x004FD830
void __fastcall TIMER_DisableSpaceKey(D2WinTimerStrc* ptTimerData)
{
    D2_ASSERT(ptTimerData->controlHeader.eType == D2WIN_TIMER, 0x3B);
    ptTimerData->controlHeader.pfHandleVirtualKeyInput = 0;
}

extern unsigned int gdwTimeoutTickCount; // 0x00841B74

// 0x004FD860
int __fastcall TIMER_UpdateDefault(D2WinControlStrc* pControl)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)pControl;

    D2_ASSERT(pTimer->controlHeader.eType == D2WIN_TIMER, 0x52);

    if (!(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned int dwNow = GetTickCount();
    const unsigned int dwStart = pTimer->dwTickCount / 1000;
    if (dwNow / 1000 - dwStart <= pTimer->nTimeout)
    {
        return 1;
    }

    SMSGHANDLER_PARAMS tMsg;
    tMsg.hWnd = pTimer;

    if (pTimer->controlHeader.field_34)
    {
        pTimer->controlHeader.field_34(&tMsg);
    }

    return 1;
}

// 0x004FD8F0
int __fastcall TIMER_UpdateRepeating(D2WinControlStrc* pControl)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)pControl;

    D2_ASSERT(pTimer->controlHeader.eType == D2WIN_TIMER, 0x6A);

    if (!(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTimer->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned int dwTickCount = GetTickCount();
    if (dwTickCount < gdwTimeoutTickCount)
    {
        return 1;
    }

    SMSGHANDLER_PARAMS tMsg;
    tMsg.hWnd = pTimer;

    if (pTimer->controlHeader.field_34)
    {
        pTimer->controlHeader.field_34(&tMsg);
    }

    gdwTimeoutTickCount = dwTickCount + pTimer->nTimeout;
    return 1;
}

// 0x004FD970
int __stdcall TIMER_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinControlStrc* pTimer = (D2WinControlStrc*)pMsg->hWnd;
    D2_ASSERT(pTimer->eType == 8, 0x82);
    if (pMsg->uMessage == 0x102 || pMsg->wParam != 0x20)
        return 0;
    if (pTimer->field_34)
        pTimer->field_34(pMsg);
    return 1;
}

// 0x004FD9D0
D2WinTimerStrc* __fastcall TIMER_Create(unsigned int nTimeout, D2WinMsgHandler pfCallback)
{
    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)FOG_Alloc(sizeof(D2WinTimerStrc), ".\\Src\\D2WinTimer.cpp", 0x1C, 0);
    memset(pTimer, 0, sizeof(D2WinTimerStrc));
    pTimer->controlHeader.eType = D2WIN_TIMER;
    pTimer->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pTimer->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pTimer->nTimeout = nTimeout;
    pTimer->dwTickCount = GetTickCount();
    pTimer->controlHeader.pfInitialize = TIMER_UpdateDefault;
    pTimer->controlHeader.pNext = 0;
    pTimer->controlHeader.field_34 = pfCallback;
    pTimer->controlHeader.pfHandleVirtualKeyInput = TIMER_HandleVirtualKeyInput;
    CONTROL_AppendToList(&pTimer->controlHeader);
    return pTimer;
}

// 0x004FDA50
void __fastcall TIMER_SetRepeating(D2WinTimerStrc* ptTimerData)
{
    D2_ASSERT(ptTimerData->controlHeader.eType == D2WIN_TIMER, 0x45);
    ptTimerData->controlHeader.pfInitialize = TIMER_UpdateRepeating;
}

extern "C" const char* gData_0072DED0[15] = { // 0x0072DED0
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};
