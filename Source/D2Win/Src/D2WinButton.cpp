#include "D2Win.h"

#include "D2CelContext.h"

#include "D2Win32Types.h"

#include "D2StormTypes.h"

#include "D2WinTypes.h"

#include "D2WinControls.h"

enum D2ControlTypes
{
    D2WIN_IMAGE = 2,
    D2WIN_TYPE_5 = 5,
    D2WIN_TYPE_6 = 6,
};

#define D2WIN_BUTTON 6

#define DRAWMODE_NORMAL 5

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

extern tagPOINT gtMousePosition;                                                                    // 0x007D55A4

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

int __stdcall D2Win_10125();                                                                                // 0x00501A40

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10118_DrawBlendedText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered, int eDrawMode); // 0x00502360

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

static int BUTTON_IsPointInside(D2WinButtonStrc* pButton, int nX, int nY); // 0x00500C20

static void __stdcall BUTTON_DrawText(int nOffsetY, D2WinButtonStrc* pButton); // 0x00500C50

int __stdcall CONTROL_AppendToList(D2WinButtonStrc* pControl);                                              // 0x004F9210

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton);                                                       // 0x00500DB0

int __stdcall BUTTON_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);                                             // 0x00501090

int __stdcall BUTTON_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg);                                               // 0x00501150

int __stdcall BUTTON_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg);                                       // 0x005011F0

void __fastcall D2SOUND_10039(const char* szFile);                                                          // 0x00514EC0

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

// 0x005009A0
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* ptBtnData, int bIsPressed)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == D2WIN_TYPE_6, 0x72);
    ptBtnData->bIsPressed = bIsPressed;
    ptBtnData->bIsCallbackPending = bIsPressed;
}

// 0x00500B20
extern "C" void __fastcall BUTTON_SetBaseFrame(D2WinButtonStrc* ptBtnData, int nValue)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == D2WIN_TYPE_6, 0xD6);
    ptBtnData->nBaseFrame = nValue;
}

// 0x00500C20
static __declspec(noinline) int BUTTON_IsPointInside(D2WinButtonStrc* pButton, int nX, int nY)
{
    const int nLeft = pButton->controlHeader.nImageX;
    const int nBottom = pButton->controlHeader.nImageY;
    return nX >= nLeft && nY >= nBottom - pButton->controlHeader.nHeight && nX < nLeft + pButton->controlHeader.nWidth && nY < nBottom;
}

// 0x00500C50
static void __stdcall BUTTON_DrawText(int nOffsetY, D2WinButtonStrc* pButton)
{
    D2Win_10127_SetFont(pButton->eFont);
    const int nTextHeight = D2Win_10125();
    int nOffsetX = (pButton->controlHeader.nWidth - D2Win_10121_GetTextWidth((const Unicode*)pButton->wszText)) / 2;
    if (nOffsetX < 0)
    {
        nOffsetX = 0;
    }

    int nX = pButton->controlHeader.nImageX + nOffsetX;
    int nY = pButton->controlHeader.nImageY - (pButton->controlHeader.nHeight - nTextHeight) / 2 + nOffsetY;
    if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
    {
        nX -= 2;
        nY += 2;
    }

    if (pButton->dwButtonFlags & BUTTONFLAG_SUBTITLE)
    {
        nOffsetX = (pButton->controlHeader.nWidth - D2Win_10121_GetTextWidth((const Unicode*)pButton->wszText)) / 2;
        if (nOffsetX < 0)
        {
            nOffsetX = 0;
        }

        nX = pButton->controlHeader.nImageX + nOffsetX;
        nY = pButton->controlHeader.nImageY - 2 * ((pButton->controlHeader.nHeight - nTextHeight) / 3);
        int nTextOffsetX = (pButton->controlHeader.nWidth - D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex((unsigned short)pButton->nStringId))) / 2;
        if (nTextOffsetX < 0)
        {
            nTextOffsetX = 0;
        }

        int nTextX = pButton->controlHeader.nImageX + nTextOffsetX;
        nY += nOffsetY;
        int nTextY = pButton->controlHeader.nImageY - (pButton->controlHeader.nHeight - nTextHeight) / 3 + nOffsetY;
        if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
        {
            nTextX -= 2;
            nX -= 2;
            nY += 2;
            nTextY += 2;
        }

        D2Win_10118_DrawBlendedText(D2LANG_GetStringFromTblIndex((unsigned short)pButton->nStringId), nTextX, nTextY, pButton->nTextColor, 0, DRAWMODE_BURN);
    }

    D2Win_10118_DrawBlendedText((const Unicode*)pButton->wszText, nX, nY, pButton->nTextColor, 0, DRAWMODE_BURN);
}

int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton);

// 0x00500DB0
int __fastcall BUTTON_Draw(D2WinButtonStrc* pButton)
{
    D2_ASSERT(pButton->controlHeader.eType == D2WIN_BUTTON, 0x14D);

    int nBaseFrame = pButton->nBaseFrame;
    if (!(pButton->controlHeader.dwFlags & gdwBitMasks[2]) || !(pButton->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        nBaseFrame += pButton->nDisabledFrameOffset;
    }
    else
    {
        if (pButton->bIsPressed)
        {
            if (pButton->dwButtonFlags & 3)
            {
                pButton->bIsCallbackPending = 1;
            }
            else
            {
                pButton->bIsCallbackPending = BUTTON_IsPointInside(pButton, gtMousePosition.x, gtMousePosition.y);
            }
        }

        if (pButton->bIsPressed && pButton->bIsCallbackPending || pButton->nActivationCounter)
        {
            nBaseFrame += pButton->nIsPressedFrameOffset;
        }
    }

    if (pButton->controlHeader.pCellFile && pButton->controlHeader.dwFlags & gdwBitMasks[2])
    {
        int nDrawMode;
        if (pButton->controlHeader.dwFlags & gdwBitMasks[0] || pButton->dwButtonFlags & BUTTONFLAG_HAS_DISABLED_FRAMES)
        {
            nDrawMode = DRAWMODE_NORMAL;
        }
        else
        {
            nDrawMode = DRAWMODE_TRANS50;
        }

        const int nImageX = pButton->controlHeader.nImageX;
        const int nBaseY = pButton->controlHeader.nImageY - pButton->controlHeader.nHeight + 1;
        const int nRows = ((pButton->controlHeader.nHeight + 0xFF) >> 8) - 1;
        const int nColumns = (pButton->controlHeader.nWidth + 0xFF) >> 8;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = pButton->controlHeader.pCellFile;
        tContext.nDirection = 0;

        for (int i = 0; i < nRows; ++i)
        {
            for (int j = 0; j < nColumns; ++j)
            {
                tContext.nFrame = nBaseFrame + j + 4 * i;
                sub_004F6480(&tContext, nImageX + 256 * j, nBaseY + 256 * (i + 1), -1, nDrawMode, 0);
            }
        }

        if (nRows >= 0)
        {
            for (int i = 0; i < nColumns; ++i)
            {
                tContext.nFrame = nBaseFrame + i + 4 * nRows;
                sub_004F6480(&tContext, nImageX + 256 * i, pButton->controlHeader.nImageY, -1, nDrawMode, 0);
            }
        }

        pButton->eFont = D2FONT_FONTRIDICULOUS;
        int nOffsetY;
        if (pButton->controlHeader.nHeight >= 35)
        {
            pButton->eFont = D2FONT_FONTEXOCET10;
            nOffsetY = 4;
        }
        else if (pButton->controlHeader.nHeight == 32)
        {
            nOffsetY = 3;
        }
        else
        {
            nOffsetY = (pButton->controlHeader.nHeight > 20) + 1;
        }

        pButton->nTextColor = 0;
        if (pButton->wszText[0])
        {
            BUTTON_DrawText(nOffsetY, pButton);
        }
    }

    if (pButton->nActivationCounter == 2)
    {
        pButton->nActivationCounter = 0;
        pButton->bIsCallbackPending = 1;
    }
    else if (pButton->nActivationCounter)
    {
        ++pButton->nActivationCounter;
    }

    if (pButton->pfUpdateHoverState)
    {
// build: symbol ?CONTROL_GetActiveControlList@* 0x004FA4B0
        if (CONTROL_GetActiveControlList())
        {
            pButton->isButtonHovered = 0;
        }
        else
        {
            const int nImageX = pButton->controlHeader.nImageX;
            const int nImageY = pButton->controlHeader.nImageY;
            pButton->isButtonHovered = gtMousePosition.x >= nImageX && gtMousePosition.y >= nImageY - pButton->controlHeader.nHeight
                && gtMousePosition.x < nImageX + pButton->controlHeader.nWidth && gtMousePosition.y < nImageY;
        }

        SMSGHANDLER_PARAMS tMsg;
        tMsg.hWnd = pButton;
        tMsg.lParam = pButton->isButtonHovered;
        ++gnWinCallbackDepth_007D55C4;
        pButton->pfUpdateHoverState(&tMsg);
        --gnWinCallbackDepth_007D55C4;
    }

    return 1;
}

// 0x00501290
D2WinButtonStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, void* pCallback, int nVirtualKey, int nBaseFrame, unsigned int dwButtonFlags, int nStringId, void* pUpdateHoverState)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)FOG_Alloc(sizeof(D2WinButtonStrc), ".\\Src\\D2WinButton.cpp", 36, 0);
    memset(pButton, 0, sizeof(D2WinButtonStrc));

    pButton->controlHeader.eType = D2WIN_BUTTON;
    pButton->controlHeader.dwFlags |= gdwBitMasks[0];
    pButton->controlHeader.dwFlags |= gdwBitMasks[2];
    pButton->controlHeader.pCellFile = pCellFile;
    pButton->controlHeader.nImageX = nX;
    pButton->controlHeader.nImageY = nY;
    pButton->controlHeader.nWidth = nWidth;
    pButton->controlHeader.nHeight = nHeight;
    pButton->controlHeader.pfDraw = (D2WinControlFn)BUTTON_Draw;
    pButton->controlHeader.pfHandleMouseDown = BUTTON_HandleMouseDown;
    pButton->controlHeader.pfHandleMouseUp = BUTTON_HandleMouseUp;
    pButton->controlHeader.pfHandleCharInput = 0;
    pButton->controlHeader.pfHandleVirtualKeyInput = nVirtualKey ? BUTTON_HandleVirtualKeyInput : 0;
    pButton->controlHeader.field_34 = (D2WinMsgHandler)pCallback;
    pButton->controlHeader.pNext = 0;
    pButton->dwButtonFlags = dwButtonFlags;
    pButton->bIsPressed = 0;
    pButton->bIsCallbackPending = 0;
    pButton->nActivationVirtualKey = nVirtualKey;
    pButton->nBaseFrame = nBaseFrame;

    if (nStringId)
    {
        sub_005267E0((Unicode*)pButton->wszText, D2LANG_GetStringFromTblIndex(nStringId));
    }

    struct { int nColumns; int nRows; } tCels;
    tCels.nColumns = (nWidth + 0xFF) >> 8;
    tCels.nRows = (nHeight + 0xFF) >> 8;
    pButton->nIsPressedFrameOffset = tCels.nRows * tCels.nColumns;
    pButton->nDisabledFrameOffset = (pButton->dwButtonFlags & BUTTONFLAG_HAS_DISABLED_FRAMES) ? 2 * pButton->nIsPressedFrameOffset : 0;

    pButton->pfUpdateHoverState = (D2WinMsgHandler)pUpdateHoverState;
    pButton->isButtonHovered = 0;
    pButton->nStringId = 0;
    CONTROL_AppendToList(pButton);
    return pButton;
}

// 0x00500B50
int __fastcall BUTTON_OnMouseWheelScrolled(D2WinButtonStrc* ptBtnData, int nMouseWheelIncrement)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == 6, 0xE2);

    if (!(ptBtnData->controlHeader.dwFlags & gdwBitMasks[0]) || !(ptBtnData->controlHeader.dwFlags & gdwBitMasks[2]) || ptBtnData->bIsPressed || ptBtnData->bIsCallbackPending)
    {
        return 0;
    }

    if ((nMouseWheelIncrement <= 0 || !(ptBtnData->dwButtonFlags & 8)) && (nMouseWheelIncrement >= 0 || !(ptBtnData->dwButtonFlags & 0x10)))
    {
        return 0;
    }

    SMSGHANDLER_PARAMS msg;
    memset(&msg.uMessage, 0, sizeof(msg) - sizeof(msg.hWnd));
    msg.hWnd = ptBtnData;

    if (ptBtnData->controlHeader.field_34)
    {
        ++gnWinCallbackDepth_007D55C4;
        ptBtnData->controlHeader.field_34(&msg);
        --gnWinCallbackDepth_007D55C4;
    }

    return 0;
}

// 0x00500960
int __fastcall BUTTON_IsPressed(D2WinButtonStrc* ptBtnData)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == D2WIN_BUTTON, 0x65);
    return ptBtnData->bIsPressed && ptBtnData->bIsCallbackPending ? 1 : 0;
}

// 0x00500AB0
void __fastcall BUTTON_SimulateClick(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* ptBtnData = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(ptBtnData->controlHeader.eType == D2WIN_BUTTON, 0xBC);
    if (ptBtnData->controlHeader.pfHandleMouseDown)
    {
        ptBtnData->nActivationCounter = 1;
        ptBtnData->controlHeader.pfHandleMouseDown(pMsg);
        if (ptBtnData->controlHeader.pfHandleMouseUp)
        {
            SMSGHANDLER_PARAMS tMsg;
            tMsg.hWnd = pMsg->hWnd;
            ++gnWinCallbackDepth_007D55C4;
            ptBtnData->controlHeader.pfHandleMouseUp(&tMsg);
            --gnWinCallbackDepth_007D55C4;
        }
    }
}

// 0x00500BF0
void __fastcall BUTTON_SetStringId(D2WinButtonStrc* pButton, int nStringId)
{
    D2_ASSERT(pButton->controlHeader.eType == D2WIN_BUTTON, 0x100);
    pButton->nStringId = nStringId;
}

// 0x005009D0
void __fastcall BUTTON_SetText(D2WinButtonStrc* pButton, int eFont, const Unicode* wszText, int nTextColor)
{
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x84);
    pButton->eFont = eFont;
    pButton->nTextColor = nTextColor;
    sub_005267E0((Unicode*)pButton->wszText, wszText);
}

// 0x00500A20
void __fastcall BUTTON_SetTextWithStringId(D2WinButtonStrc* ptBtnData, int eFont, unsigned short nStringId, int nTextColor)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == 6, 0x96);
    ptBtnData->eFont = eFont;
    ptBtnData->nTextColor = nTextColor;
    sub_005267E0((Unicode*)ptBtnData->wszText, D2LANG_GetStringFromTblIndex(nStringId));
}

// 0x00500A70
void __fastcall BUTTON_SetCoordinates(D2WinButtonStrc* ptBtnData, int nX, int nY, int nWidth, int nHeight)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == 6, 0xAB);
    ptBtnData->controlHeader.nImageX = nX;
    ptBtnData->controlHeader.nImageY = nY;
    ptBtnData->controlHeader.nWidth = nWidth;
    ptBtnData->controlHeader.nHeight = nHeight;
}

// 0x00501090
int __stdcall BUTTON_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x1FD);
    if (!(pButton->controlHeader.dwFlags & gdwBitMasks[2]) || !(pButton->controlHeader.dwFlags & gdwBitMasks[0]))
        return 0;
    if (pButton->dwButtonFlags & 2)
    {
        pButton->bIsPressed = pButton->bIsPressed == 0;
        pButton->bIsCallbackPending = pButton->bIsCallbackPending == 0;
    }
    else
    {
        if (pButton->bIsPressed && pButton->bIsCallbackPending)
            return 1;
        pButton->bIsPressed = 1;
        pButton->bIsCallbackPending = 1;
    }
    if (!(pButton->dwButtonFlags & 4))
        D2SOUND_10039("data\\global\\sfx\\cursor\\button.wav");
    if ((pButton->dwButtonFlags & 3) && pButton->controlHeader.field_34)
    {
        D2_ASSERT(gnWinCallbackDepth_007D55C4 > 0, 0x221);
        pButton->controlHeader.field_34(pMsg);
    }
    return 1;
}

// 0x00501150
int __stdcall BUTTON_HandleMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x232);
    int nResult = 0;
    pButton->controlHeader.dwFlags |= gdwBitMasks[1];
    if (!(pButton->controlHeader.dwFlags & gdwBitMasks[2]) || !(pButton->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        pButton->controlHeader.dwFlags &= gdwInvBitMasks[1];
        return 0;
    }
    if (!(pButton->dwButtonFlags & 3))
    {
        pButton->bIsPressed = 0;
        if (pButton->bIsCallbackPending && pButton->controlHeader.field_34)
        {
            D2_ASSERT(gnWinCallbackDepth_007D55C4 > 0, 0x243);
            nResult = pButton->controlHeader.field_34(pMsg);
        }
        pButton->bIsCallbackPending = 0;
    }
    pButton->controlHeader.dwFlags &= gdwInvBitMasks[1];
    return nResult;
}

// 0x005011F0
int __stdcall BUTTON_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinButtonStrc* pButton = (D2WinButtonStrc*)pMsg->hWnd;
    D2_ASSERT(pButton->controlHeader.eType == 6, 0x259);
    int nResult = 0;
    if (pMsg->uMessage != 0x102 && pButton->nActivationVirtualKey == pMsg->wParam && pButton->controlHeader.pfHandleMouseDown)
    {
        pButton->nActivationCounter = 1;
        D2_ASSERT(gnWinCallbackDepth_007D55C4 > 0, 0x263);
        nResult = pButton->controlHeader.pfHandleMouseDown(pMsg);
        if (pButton->controlHeader.pfHandleMouseUp)
        {
            SMSGHANDLER_PARAMS msg;
            msg.hWnd = pMsg->hWnd;
            ++gnWinCallbackDepth_007D55C4;
            pButton->controlHeader.pfHandleMouseUp(&msg);
            --gnWinCallbackDepth_007D55C4;
        }
    }
    return nResult;
}

// 0x00500930
int __fastcall BUTTON_Destroy(D2WinButtonStrc* ptBtnData)
{
    D2_ASSERT(ptBtnData->controlHeader.eType == D2WIN_BUTTON, 0x59);
    return CONTROL_RemoveFromList(&ptBtnData->controlHeader);
}

#include "gen/data/Source/D2Win/Src/D2WinButton.inc"
