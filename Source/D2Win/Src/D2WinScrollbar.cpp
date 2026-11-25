#include "D2Win.h"
#include "D2GfxTypes.h"

#include "D2MultiTypes.h"

#include "D2CelContext.h"

#include "D2WinTypes.h"

#include "D2Unicode.h"

#include "D2WinControls.h"

#include "D2Win32Types.h"

#include "D2StormTypes.h"
#include "D2WinPopupLine.h"

#define WM_LBUTTONDOWN 0x201

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinControlStrc;

struct D2WinTextBoxStrc;

struct D2CelContextStrc;

struct SMSGHANDLER_PARAMS;

struct D2WinScrollBarStrc;

struct Unicode;

struct D2WinPopUpLineStrc;

struct D2WinPopUpStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern tagPOINT gtMousePosition; // 0x007D55A4

int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FBA30

extern "C" void* __cdecl memset(void* destination, int value, unsigned int size); // 0x00681EF0

int __stdcall SCROLLBAR_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00508120

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

enum D2C_WinControlTypes
{
    D2WIN_SCROLLBAR = 5,
    D2WIN_POPUP = 11,
};


struct D2WinPopUpStrc
{
    D2WinControlStrc controlHeader;
    int nLines;
    D2WinPopUpLineStrc lines[8];
    int nCurrentLine;
};

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl); // 0x004F9310

int __fastcall POPUP_UpdateHoveredLine(D2WinControlStrc* pControl); // 0x00508710

int __fastcall POPUP_Draw(D2WinControlStrc* pControl); // 0x005087A0

extern D2WinPopUpStrc* gpPopUp; // 0x0087E974

// 0x00507EF0
extern "C" int __fastcall SCROLLBAR_GetScrollBarField48(D2WinScrollBarStrc* ptScrollbarData)
{
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0x4B);
    return ptScrollbarData->nMaxSteps;
}

// 0x00507FA0
extern "C" int __fastcall SCROLLBAR_GetScrollBarField4C(D2WinScrollBarStrc* ptScrollbarData)
{
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0x74);
    return ptScrollbarData->nCurrentStep;
}

// 0x00508000
extern "C" int __fastcall SCROLLBAR_SetScrollCallback(D2WinScrollBarStrc* pScrollBar, D2WinMsgHandler pfHandler)
{
    D2_ASSERT(pScrollBar->controlHeader.eType == D2WIN_SCROLLBAR, 0x8B);
    pScrollBar->field_5C = pfHandler;
    return 1;
}

int __fastcall SCROLLBAR_HandleMouseWheel(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* pScrollBar, int a3); // 0x00508030

// 0x00508030
int __fastcall SCROLLBAR_HandleMouseWheel(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* ptScrollbarData, int a3)
{
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0x99);

    if (!ptScrollbarData->bIsStepIndicatorDragged)
    {
        if (a3 > 0)
        {
            --ptScrollbarData->nCurrentStep;
            ptScrollbarData->bIsUpperArrowPressed = 1;
        }
        else if (a3 < 0)
        {
            ++ptScrollbarData->nCurrentStep;
            ptScrollbarData->bIsLowerArrowPressed = 1;
        }

        if (ptScrollbarData->nCurrentStep < 0)
        {
            ptScrollbarData->nCurrentStep = 0;
        }
        else if (ptScrollbarData->nCurrentStep > ptScrollbarData->nMaxSteps)
        {
            ptScrollbarData->nCurrentStep = ptScrollbarData->nMaxSteps;
        }

        if (ptScrollbarData->pTextBox)
        {
            D2Win_10053(ptScrollbarData->pTextBox, ptScrollbarData->nCurrentStep);
        }

        if (ptScrollbarData->field_5C)
        {
            ptScrollbarData->field_5C(pMsg);
        }
    }

    return 0;
}

// 0x005080C0
extern "C" void __fastcall D2Win_10202(D2WinScrollBarStrc* ptScrollbarData, int nValue)
{
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0xCA);
    ptScrollbarData->nPageStep = nValue;
}

// 0x005080F0
extern "C" int __fastcall D2Win_10201(D2WinScrollBarStrc* pScrollBar)
{
    D2_ASSERT(pScrollBar->controlHeader.eType == D2WIN_SCROLLBAR, 0xD2);
    return pScrollBar->nPageStep;
}

// 0x00508370
int __fastcall SCROLLBAR_Draw(D2WinControlStrc* pControl)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)pControl;
    D2_ASSERT(pScrollBar, 0xE7);
    D2_ASSERT(pScrollBar->controlHeader.eType == 5, 0xE8);
    if (!(pScrollBar->controlHeader.dwFlags & gdwBitMasks[2]) ||
        !(pScrollBar->controlHeader.dwFlags & gdwBitMasks[0]))
        return 0;

    D2CelFileStrc* pCellFile = pScrollBar->controlHeader.pCellFile;
    int nX = pScrollBar->controlHeader.nImageX;
    int nY = pScrollBar->controlHeader.nImageY - 1;
    if (pScrollBar->nMaxSteps)
    {
// build: symbol ?D2Win_IsMouseButtonPressed@* 0x004FA460
        if (!D2Win_IsMouseButtonPressed())
            pScrollBar->bIsStepIndicatorDragged = 0;
        if (pScrollBar->bIsStepIndicatorDragged)
        {
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pScrollBar;
            msg.uMessage = 0x201;
            SCROLLBAR_HandleMouseDown(&msg);
        }

        D2CelContextStrc context;
        memset(&context, 0, sizeof(context));
        context.pCellFile = pCellFile;
        context.nDirection = 0;
        context.nFrame = pScrollBar->bIsLowerArrowPressed ? 3 : 1;
        sub_004F6480(&context, nX, nY, -1, 5, 0);
        context.nFrame = 5;
        if (pScrollBar->controlHeader.nHeight - 10 > 10)
        {
            int nOffset = 10;
            do
            {
                nOffset += 10;
                nY -= 10;
                sub_004F6480(&context, nX, nY, -1, 5, 0);
            } while (nOffset < pScrollBar->controlHeader.nHeight - 10);
        }
        context.nFrame = pScrollBar->bIsUpperArrowPressed != 0 ? 2 : 0;
        sub_004F6480(&context, nX,
            pScrollBar->controlHeader.nImageY - pScrollBar->controlHeader.nHeight + 9,
            -1, 5, 0);
        context.nFrame = 4;
        sub_004F6480(&context, nX,
            (pScrollBar->controlHeader.nHeight - 30) * pScrollBar->nCurrentStep / pScrollBar->nMaxSteps
                - pScrollBar->controlHeader.nHeight + pScrollBar->controlHeader.nImageY + 19,
            -1, 5, 0);
    }
    return 1;
}

// 0x00508120
int __stdcall SCROLLBAR_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinScrollBarStrc* ptScrollbarData = (D2WinScrollBarStrc*)pMsg->hWnd;
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0x12F);

    if (pMsg->uMessage != WM_LBUTTONDOWN)
    {
        return 1;
    }

    if (!(ptScrollbarData->controlHeader.dwFlags & gdwBitMasks[2]) || !(ptScrollbarData->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 1;
    }

    const int nMaxSteps = ptScrollbarData->nMaxSteps;
    if (!nMaxSteps)
    {
        return 1;
    }

    const int nX = gtMousePosition.x - ptScrollbarData->controlHeader.nImageX;
    const int nY = ptScrollbarData->controlHeader.nHeight - ptScrollbarData->controlHeader.nImageY + gtMousePosition.y;
    if (nX < 0 || nX > ptScrollbarData->controlHeader.nWidth)
    {
        return 0;
    }

    int nValue = ptScrollbarData->controlHeader.nHeight - 10;
    const int nRange = ptScrollbarData->controlHeader.nHeight - 30;

    const int nCurrentStep = ptScrollbarData->nCurrentStep;
    const int nIndicatorY = nCurrentStep * nRange / nMaxSteps + 10;
    if (nY >= nIndicatorY && nY <= nIndicatorY + 10)
    {
        ptScrollbarData->bIsStepIndicatorDragged = 1;
    }

    if (nY < 11 && !ptScrollbarData->bIsLowerArrowPressed && !ptScrollbarData->bIsStepIndicatorDragged)
    {
        ptScrollbarData->bIsUpperArrowPressed = 1;
        ptScrollbarData->nCurrentStep = nCurrentStep - 1;
    }
    else if (nY > nValue && !ptScrollbarData->bIsUpperArrowPressed && !ptScrollbarData->bIsStepIndicatorDragged)
    {
        ptScrollbarData->bIsLowerArrowPressed = 1;
        ptScrollbarData->nCurrentStep = nCurrentStep + 1;
    }
    else if (!ptScrollbarData->bIsLowerArrowPressed && !ptScrollbarData->bIsUpperArrowPressed)
    {
        if (ptScrollbarData->bIsStepIndicatorDragged)
        {
            ptScrollbarData->nCurrentStep = (nY - 11) * nMaxSteps / nRange;
        }
        else
        {
            nValue = ptScrollbarData->nPageStep;
            if (!nValue)
            {
                int nPages = nRange / 10;
                if (!nPages)
                {
                    nPages = 1;
                }

                nValue = ptScrollbarData->nMaxSteps / nPages;
                if (!nValue)
                {
                    nValue = 1;
                }
            }

            const int nStepY = ptScrollbarData->nCurrentStep * nRange / ptScrollbarData->nMaxSteps + 10;
            if (nY < nStepY)
            {
                ptScrollbarData->nCurrentStep = nCurrentStep - nValue;
            }
            else if (nY > nStepY + 10)
            {
                ptScrollbarData->nCurrentStep = nCurrentStep + nValue;
            }
        }
    }

    if (ptScrollbarData->nCurrentStep < 0)
    {
        ptScrollbarData->nCurrentStep = 0;
    }
    else if (ptScrollbarData->nCurrentStep > ptScrollbarData->nMaxSteps)
    {
        ptScrollbarData->nCurrentStep = ptScrollbarData->nMaxSteps;
    }

    if (ptScrollbarData->pTextBox && pMsg->uMessage == WM_LBUTTONDOWN)
    {
        D2Win_10053(ptScrollbarData->pTextBox, ptScrollbarData->nCurrentStep);
    }

    if (ptScrollbarData->field_5C)
    {
        ptScrollbarData->field_5C(pMsg);
    }

    if (ptScrollbarData->controlHeader.field_34)
    {
        return ptScrollbarData->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x00507F20
int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* ptScrollbarData, int nMaxSteps)
{
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0x56);
    ptScrollbarData->nMaxSteps = nMaxSteps > 0 ? nMaxSteps : 0;
    return 1;
}

// 0x00507F60
int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* ptScrollbarData, int nCurrentStep)
{
    D2_ASSERT(ptScrollbarData->controlHeader.eType == D2WIN_SCROLLBAR, 0x65);
    if (nCurrentStep > ptScrollbarData->nMaxSteps)
        nCurrentStep = ptScrollbarData->nMaxSteps;
    ptScrollbarData->nCurrentStep = nCurrentStep;
    return 1;
}

// 0x00507FD0
int __fastcall SCROLLBAR_SetTextBox(D2WinScrollBarStrc* pScrollBar, D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pScrollBar->controlHeader.eType == D2WIN_SCROLLBAR, 0x7F);
    pScrollBar->pTextBox = pTextBox;
    return 1;
}

// 0x00508310
int __stdcall SCROLLBAR_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)pMsg->hWnd;
    D2_ASSERT(pScrollBar->controlHeader.eType == D2WIN_SCROLLBAR, 0x1B0);
    if (pScrollBar->bIsUpperArrowPressed || pScrollBar->bIsLowerArrowPressed || pScrollBar->bIsStepIndicatorDragged)
    {
        pScrollBar->bIsUpperArrowPressed = 0;
        pScrollBar->bIsLowerArrowPressed = 0;
        pScrollBar->bIsStepIndicatorDragged = 0;
        return 1;
    }
    return 0;
}

// 0x005084F0
D2WinScrollBarStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, D2WinMsgHandler pfnHandler)
{
    D2WinScrollBarStrc* pScrollBar = (D2WinScrollBarStrc*)FOG_Alloc(sizeof(D2WinScrollBarStrc), ".\\Src\\D2WinScrollbar.cpp", 0x1C, 0);
    memset(pScrollBar, 0, sizeof(D2WinScrollBarStrc));
    pScrollBar->controlHeader.eType = D2WIN_SCROLLBAR;
    pScrollBar->controlHeader.dwFlags |= gdwBitMasks[0];
    pScrollBar->controlHeader.dwFlags |= gdwBitMasks[2];
    pScrollBar->controlHeader.pCellFile = pCellFile;
    pScrollBar->controlHeader.nImageX = nX;
    pScrollBar->controlHeader.nImageY = nY;
    pScrollBar->controlHeader.nWidth = nWidth;
    pScrollBar->controlHeader.nHeight = nHeight;
    pScrollBar->controlHeader.pfDraw = SCROLLBAR_Draw;
    pScrollBar->controlHeader.pNext = 0;
    pScrollBar->controlHeader.pfHandleMouseDown = SCROLLBAR_HandleMouseDown;
    pScrollBar->controlHeader.pfHandleMouseUp = SCROLLBAR_HandleMouseUp;
    pScrollBar->controlHeader.pfHandleCharInput = 0;
    pScrollBar->controlHeader.pfHandleVirtualKeyInput = 0;
    pScrollBar->controlHeader.field_34 = pfnHandler;
    pScrollBar->bIsUpperArrowPressed = 0;
    pScrollBar->bIsLowerArrowPressed = 0;
    pScrollBar->nMaxSteps = 0;
    pScrollBar->nCurrentStep = 0;
    pScrollBar->pTextBox = 0;
    pScrollBar->field_5C = 0;
    pScrollBar->nPageStep = 0;
    CONTROL_AppendToList(&pScrollBar->controlHeader);
    return pScrollBar;
}

#include "gen/data/Source/D2Win/Src/D2WinScrollbar.inc"
