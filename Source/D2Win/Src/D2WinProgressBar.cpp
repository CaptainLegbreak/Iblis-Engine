#include "D2Win.h"

#include "D2WinTypes.h"

#include "D2WinControls.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

enum D2ControlTypes
{
    D2WIN_PROGRESSBAR = 10,
};

struct D2WinProgressBarStrc
{
    D2WinControlStrc controlHeader;
    float fProgress;
};


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300

int __fastcall PROGRESSBAR_Draw(D2WinControlStrc* pControl); // 0x00507DC0

// 0x00507D70
int __stdcall PROGRESSBAR_SetProgress(D2WinProgressBarStrc* pProgressBar, float fProgress)
{
    D2_ASSERT(pProgressBar->controlHeader.eType == D2WIN_PROGRESSBAR, 0x3A);
    pProgressBar->fProgress = fProgress;
    return 1;
}

void __stdcall CONTROL_RemoveFromList(void* pArg); // 0x004F9310

// 0x00507DB0
void __fastcall PROGRESSBAR_Destroy(void* pArg)
{
    CONTROL_RemoveFromList(pArg);
}

// 0x00507DC0
int __fastcall PROGRESSBAR_Draw(D2WinControlStrc* pControl)
{
    D2WinProgressBarStrc* pProgressBar = (D2WinProgressBarStrc*)pControl;

    D2_ASSERT(pProgressBar->controlHeader.eType == D2WIN_PROGRESSBAR, 0x4F);

    if (!(pProgressBar->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pProgressBar->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned char nColor = D2Win_10034_MixRGB(0xFF, 0, 0);
    D2GFX_DrawBox(
        pProgressBar->controlHeader.nImageX,
        pProgressBar->controlHeader.nImageY,
        pProgressBar->controlHeader.nImageX + (int)(pProgressBar->controlHeader.nWidth * pProgressBar->fProgress),
        pProgressBar->controlHeader.nImageY + pProgressBar->controlHeader.nHeight,
        nColor,
        5);

    return 1;
}

// 0x00507E50
D2WinProgressBarStrc* __fastcall PROGRESSBAR_Create(int nX, int nY, int nWidth, int nHeight)
{
    D2WinProgressBarStrc* pProgressBar = (D2WinProgressBarStrc*)FOG_Alloc(sizeof(D2WinProgressBarStrc), ".\\Src\\D2WinProgressBar.cpp", 0x1A, 0);
    memset(pProgressBar, 0, sizeof(D2WinProgressBarStrc));
    pProgressBar->controlHeader.eType = D2WIN_PROGRESSBAR;
    pProgressBar->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pProgressBar->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pProgressBar->controlHeader.pCellFile = 0;
    pProgressBar->controlHeader.nImageX = nX;
    pProgressBar->controlHeader.nImageY = nY;
    pProgressBar->controlHeader.nWidth = nWidth;
    pProgressBar->controlHeader.nHeight = nHeight;
    pProgressBar->controlHeader.pfDraw = PROGRESSBAR_Draw;
    pProgressBar->controlHeader.pNext = 0;
    pProgressBar->controlHeader.pfHandleMouseDown = 0;
    pProgressBar->controlHeader.pfHandleMouseUp = 0;
    pProgressBar->controlHeader.pfHandleCharInput = 0;
    pProgressBar->controlHeader.pfHandleVirtualKeyInput = 0;
    pProgressBar->controlHeader.field_34 = 0;
    pProgressBar->fProgress = 0.0f;
    CONTROL_AppendToList(&pProgressBar->controlHeader);
    return pProgressBar;
}

extern "C" const char* gData_0072F088[15] = { // 0x0072F088
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
