#include "D2Win.h"
#include "D2StormTypes.h"
#include "D2WinTypes.h"

#include "D2WinControls.h"
#include "FogApi.h"
#include "D2GfxApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinControlStrc;

struct D2WinSmackStrc;

int gbSmackKeepFile; // 0x0087E968

enum D2WinControlTypes
{
    D2WIN_SMACK = 9,
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion); // 0x00506910

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

int __fastcall SMACK_Draw(D2WinControlStrc* pControl); // 0x00506A90

int __stdcall SMACK_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00506B10

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl); // 0x004F9310


// 0x00506A80
void __stdcall D2Win_10184()
{
    gbSmackKeepFile = 1;
}

char gszSmackFileName[260]; // 0x0087E860

unsigned char gnSmackVersion; // 0x0087E964

// 0x00506A90
int __fastcall SMACK_Draw(D2WinControlStrc* pControl)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)pControl;

    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0xA4);

    if (!(pSmack->controlHeader.dwFlags & gdwBitMasks[2]) || !(pSmack->controlHeader.dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    if (gbSmackKeepFile)
    {
        if (gszSmackFileName[0])
        {
            SMACK_Decode(pSmack, gszSmackFileName, gnSmackVersion);
        }

        gbSmackKeepFile = 0;
    }

    WINDOW_PlaySmacker(&pSmack->field_140);
    return 1;
}

// 0x00506B10
int __stdcall SMACK_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)pMsg->hWnd;
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0xC0);
    if (!(pSmack->controlHeader.dwFlags & gdwBitMasks[2]) || !(pSmack->controlHeader.dwFlags & gdwBitMasks[0]) || !pSmack->controlHeader.field_34)
        return 0;
    return pSmack->controlHeader.field_34(pMsg);
}

// 0x00506B70
D2WinSmackStrc* __fastcall SMACK_Create(int nX, int nY, int nWidth, int nHeight, D2WinMsgHandler pfHandler)
{
    D2WinSmackStrc* pSmack = (D2WinSmackStrc*)FOG_Alloc(sizeof(D2WinSmackStrc), ".\\Src\\D2WinSmack.cpp", 0x23, 0);
    memset(pSmack, 0, sizeof(D2WinSmackStrc));
    pSmack->controlHeader.eType = 9;
    pSmack->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pSmack->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pSmack->controlHeader.nWidth = nWidth;
    pSmack->controlHeader.pNext = 0;
    memset(&pSmack->controlHeader.pfHandleMouseUp, 0, 3 * sizeof(D2WinMsgHandler));
    pSmack->controlHeader.nImageX = nX;
    pSmack->controlHeader.nImageY = nY;
    pSmack->controlHeader.nHeight = nHeight;
    pSmack->controlHeader.field_34 = pfHandler;
    pSmack->controlHeader.pfDraw = SMACK_Draw;
    pSmack->controlHeader.pfHandleMouseDown = SMACK_HandleMouseDown;
    pSmack->szFileName[0] = 0;
    memset(&pSmack->field_140, 0, 2 * sizeof(int));
    pSmack->nMovieX = (nWidth - 468) / 2 + nX;
    pSmack->nMovieY = (nHeight - 60) / 2 + nY;
    CONTROL_AppendToList(&pSmack->controlHeader);
    return pSmack;
}

// 0x00506A40
int __fastcall SMACK_Destroy(D2WinSmackStrc* pSmack)
{
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0x8C);
    SMACK_DeleteFile(pSmack);
    return CONTROL_RemoveFromList(&pSmack->controlHeader);
}

extern "C" const char* gData_0072EFD4[15] = { // 0x0072EFD4
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
