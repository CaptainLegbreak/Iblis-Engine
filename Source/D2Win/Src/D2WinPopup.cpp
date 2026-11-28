#include "D2Win.h"

#include "D2SkillIds.h"

#include "D2StatIds.h"

#include "D2StormTypes.h"

#include "D2CelContext.h"

#include "D2CmpTypes.h"

#include "D2WinControls.h"

#include "D2ClientTypes.h"

#include "D2WinTypes.h"

#include "D2Unicode.h"

#include "D2Win32Types.h"
#include "D2WinPopupLine.h"
#include "FogApi.h"
#include "D2GfxApi.h"

enum D2C_WinControlTypes
{
    D2WIN_POPUP = 11,
};

struct D2WinControlStrc;

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);


struct D2WinPopUpStrc
{
    D2WinControlStrc controlHeader;
    int nLines;
    D2WinPopUpLineStrc lines[8];
    int nCurrentLine;
};


extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern tagPOINT gtMousePosition;                                                                    // 0x007D55A4

D2WinPopUpStrc* gpPopUp;                                                                           // 0x0087E974

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210


extern "C" void* __cdecl memset(void* destination, int value, unsigned int size); // 0x00681EF0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

// 0x00508610
int __stdcall POPUP_AddLine(D2WinPopUpLineStrc* pPopUpLine)
{
    D2WinPopUpStrc* pPopUp = gpPopUp;

    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0x74);

    if (pPopUp->nLines >= 8)
    {
        return 0;
    }

    pPopUp->lines[pPopUp->nLines] = *pPopUpLine;
    D2Win_10127_SetFont(1);

    const int nTextWidth = D2Win_10121_GetTextWidth(pPopUpLine->wszText);
    pPopUp->controlHeader.nWidth = pPopUp->controlHeader.nWidth > nTextWidth ? pPopUp->controlHeader.nWidth : nTextWidth;
    ++pPopUp->nLines;
    pPopUp->controlHeader.nHeight = 20 * pPopUp->nLines;
    return 1;
}

// 0x00508710
int __fastcall POPUP_UpdateHoveredLine(D2WinControlStrc* pControl)
{
    D2WinPopUpStrc* pPopUp = (D2WinPopUpStrc*)pControl;

    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0xA6);

    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    pPopUp->nCurrentLine = -1;

    const int nX = gtMousePosition.x - pPopUp->controlHeader.nImageX;
    const int nY = pPopUp->controlHeader.nHeight - pPopUp->controlHeader.nImageY + gtMousePosition.y;

    if (nX >= 0 && nX <= pPopUp->controlHeader.nWidth && nY >= 0 && nY <= pPopUp->controlHeader.nHeight)
    {
        pPopUp->nCurrentLine = nY / 20;
    }

    return 1;
}

// 0x005085A0
int __stdcall POPUP_Destroy()
{
    int nResult = 0;
    if (gpPopUp)
    {
        nResult = CONTROL_RemoveFromList(&gpPopUp->controlHeader);
        gpPopUp = 0;
    }
    return nResult;
}

// 0x005085C0
int __stdcall POPUP_IsActive()
{
    D2WinPopUpStrc* pPopUp = gpPopUp;
    if (!pPopUp)
        return 0;
    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0x62);
    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
        return 0;
    return 1;
}

// 0x005086A0
int __stdcall POPUP_HandleMouseButtonInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinPopUpStrc* pPopUp = gpPopUp;
    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0x90);
    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
        return 0;
    const int nCurrentLine = pPopUp->nCurrentLine;
    if (nCurrentLine == -1)
        return 0;
    void (__stdcall* pfHandleMouseInput)() = pPopUp->lines[nCurrentLine].pfHandleMouseInput;
    if (!pfHandleMouseInput)
        return 0;
    pfHandleMouseInput();
    return 1;
}

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

// 0x005087A0
int __fastcall POPUP_Draw(D2WinControlStrc* pControl)
{
    D2WinPopUpStrc* pPopUp = (D2WinPopUpStrc*)pControl;

    D2_ASSERT(pPopUp->controlHeader.eType == D2WIN_POPUP, 0xC6);

    if (!(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pPopUp->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned char nColor = D2Win_10034_MixRGB(0x3F, 0x3F, 0x3F);

    tagRECT tRect = { pPopUp->controlHeader.nImageX - 5, pPopUp->controlHeader.nImageY - pPopUp->controlHeader.nHeight - 5, pPopUp->controlHeader.nImageX + pPopUp->controlHeader.nWidth + 5, pPopUp->controlHeader.nImageY + 5 };

    D2GFX_UtilRect(&tRect, 0xFF);
    D2GFX_DrawBox(tRect.left, tRect.bottom, tRect.right, tRect.top, nColor, 2);
    D2Win_10127_SetFont(1);

    for (int i = 0; i < pPopUp->nLines; ++i)
    {
        D2Win_10117_DrawText(pPopUp->lines[i].wszText, pPopUp->controlHeader.nImageX, pPopUp->controlHeader.nImageY + 20 * (i - pPopUp->nLines + 1), ((i != pPopUp->nCurrentLine) - 1) & 3, 0);
    }

    return 1;
}

// 0x005088C0
void __stdcall POPUP_Create()
{
    if (gpPopUp)
    {
        CONTROL_RemoveFromList(&gpPopUp->controlHeader);
        gpPopUp = 0;
    }
    D2WinPopUpStrc* pPopUp = (D2WinPopUpStrc*)FOG_Alloc(sizeof(D2WinPopUpStrc), ".\\Src\\D2WinPopup.cpp", 0x29, 0);
    memset(pPopUp, 0, sizeof(D2WinPopUpStrc));
    pPopUp->controlHeader.eType = D2WIN_POPUP;
    pPopUp->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pPopUp->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pPopUp->controlHeader.dwFlags |= gdwBitMasks_006CE268[3];
    pPopUp->controlHeader.nImageX = gtMousePosition.x;
    pPopUp->controlHeader.nImageY = gtMousePosition.y;
    pPopUp->controlHeader.pfDraw = POPUP_Draw;
    pPopUp->controlHeader.pfInitialize = POPUP_UpdateHoveredLine;
    pPopUp->controlHeader.pNext = 0;
    pPopUp->controlHeader.pfHandleMouseDown = 0;
    pPopUp->controlHeader.pfHandleMouseUp = 0;
    pPopUp->controlHeader.pfHandleCharInput = 0;
    pPopUp->controlHeader.pfHandleVirtualKeyInput = 0;
    pPopUp->controlHeader.field_34 = 0;
    pPopUp->nCurrentLine = -1;
    CONTROL_AppendToList(&pPopUp->controlHeader);
    gpPopUp = pPopUp;
}

extern "C" const char* gData_0072F100[15] = { // 0x0072F100
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
