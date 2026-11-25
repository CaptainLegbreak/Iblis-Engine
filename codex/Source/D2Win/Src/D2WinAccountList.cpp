#include "D2Win.h"
#include "D2Win32Types.h"
#include "D2CelContext.h"
#include "D2StormTypes.h"
#include "D2GfxTypes.h"
#include "D2MultiTypes.h"

#include "D2WinTypes.h"

#include "D2WinControls.h"

#include "D2Unicode.h"

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __stdcall D2Win_10125();                                                                                // 0x00501A40

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

extern const unsigned int gdwBitMasks[32];                                                                  // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

int __stdcall ACCOUNTLIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x00507A10

struct D2WinAccountListFontStrc
{
    int eFont;
    int field_04;
};

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

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

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern "C" int __cdecl strcmp(const char* szString1, const char* szString2);

// 0x005079C0
int __fastcall ACCOUNTLIST_GetTextFromSelectedEntry(D2WinAccountListStrc* ptListData, char* szBuffer)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0xB9);
    const char* szText = ptListData->pSelectedDataEntry->szText;
    if (szText)
    {
        char c;
        do
        {
            c = *szText;
            *szBuffer = c;
            ++szText;
            ++szBuffer;
        }
        while (c);
        return 1;
    }
    return 0;
}

tagPOINT gtMousePosition; // 0x007D55A4
struct Point { int x, y; };

// 0x00507A10
int __stdcall ACCOUNTLIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinAccountListStrc* pAccountList = (D2WinAccountListStrc*)pMsg->hWnd;

    D2_ASSERT(pAccountList->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x10D);

    if (!(pAccountList->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pAccountList->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    if (!pAccountList->pDataList)
    {
        return 0;
    }

    const int nIndex = (gtMousePosition.x - pAccountList->controlHeader.nImageX) / 120
        + 6 * ((pAccountList->controlHeader.nHeight - pAccountList->controlHeader.nImageY + gtMousePosition.y + 4) / 20);
    D2WinAccountListDataStrc* pData = pAccountList->pDataList;
    for (int nCounter = 0; pData; ++nCounter)
    {
        if (nCounter == nIndex)
        {
            pAccountList->pSelectedDataEntry = pData;
            return 1;
        }
        pData = pData->pNext;
    }

    pAccountList->pSelectedDataEntry = 0;
    return 1;
}

// 0x00507B30
int __fastcall ACCOUNTLIST_Draw(D2WinControlStrc* pControl)
{
    D2WinAccountListStrc* pAccountList = (D2WinAccountListStrc*)pControl;

    D2_ASSERT(pAccountList->controlHeader.eType == 0x0C, 0xD0);

    if (!(pAccountList->controlHeader.dwFlags & gdwBitMasks[2]) || !(pAccountList->controlHeader.dwFlags & gdwBitMasks[0]) || !pAccountList->pDataList)
    {
        return 0;
    }

    D2Win_10127_SetFont(pAccountList->eFont);

    Unicode wszText[256];

    int nCounter = 0;
    const int nBaseX = pAccountList->controlHeader.nImageX;
    D2WinAccountListDataStrc* pData = pAccountList->pDataList;
    const int nBaseY = pAccountList->controlHeader.nImageY - pAccountList->controlHeader.nHeight + D2Win_10125();

    for (; pData; pData = pData->pNext)
    {
        if (nCounter >= pAccountList->nFirstDrawnEntry && nCounter < pAccountList->nFirstDrawnEntry + 24)
        {
            const int nX = nBaseX + 120 * (nCounter % 6);
            const int nY = nBaseY + 20 * (nCounter / 6);
            D2GFX_DrawBox(nX, nY - 14, nX + 28, nY, 0x55, 5);

            sub_00526F20_ToUnicode(wszText, pData->szText, 256);
            D2Win_10117_DrawText(wszText, nX + 32, nY, 0, 0);

            if (pData == pAccountList->pSelectedDataEntry)
            {
                D2GFX_DrawBox(nX - 1, nY - 16, nX + 118, nY + 1, 0xFF, 1);
            }
        }

        ++nCounter;
    }

    return 1;
}

// 0x00507850
void __fastcall ACCOUNTLIST_FreeData(D2WinAccountListStrc* ptListData)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x5D);
    D2WinAccountListDataStrc* pNext = 0;
    for (D2WinAccountListDataStrc* pData = ptListData->pDataList; pData; pData = pNext)
    {
        pNext = pData->pNext;
        FOG_Free(pData, ".\\Src\\D2WinAccountList.cpp", 0x63, 0);
    }
}

// 0x00507AF0
int __fastcall ACCOUNTLIST_Destroy(D2WinAccountListStrc* ptListData)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x50);
    ACCOUNTLIST_FreeData(ptListData);
    return CONTROL_RemoveFromList(&ptListData->controlHeader);
}

// 0x00507900
int __fastcall ACCOUNTLIST_RemoveEntry(D2WinAccountListStrc* ptListData, const char* szText)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x90);

    D2WinAccountListDataStrc* pPrevious = 0;
    for (D2WinAccountListDataStrc* pData = ptListData->pDataList; pData; pData = pData->pNext)
    {
        if (!strcmp(pData->szText, szText))
        {
            if (ptListData->pSelectedDataEntry == pData)
            {
                ptListData->pSelectedDataEntry = 0;
            }

            if (pPrevious)
            {
                pPrevious->pNext = pData->pNext;
            }
            else
            {
                ptListData->pDataList = pData->pNext;
            }

            FOG_Free(pData, ".\\Src\\D2WinAccountList.cpp", 0xA7, 0);
            return 1;
        }

        pPrevious = pData;
    }

    return 0;
}

// 0x005078A0
void __fastcall ACCOUNTLIST_AllocData(D2WinAccountListStrc* ptListData, const char* szText)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_ACCOUNTLIST, 0x72);
    D2WinAccountListDataStrc* pData = (D2WinAccountListDataStrc*)FOG_Alloc(sizeof(D2WinAccountListDataStrc), ".\\Src\\D2WinAccountList.cpp", 0x77, 0);
    strncpy(pData->szText, szText, sizeof(pData->szText));
    pData->pNext = ptListData->pDataList;
    ptListData->pDataList = pData;
}

// 0x00507CA0
D2WinAccountListStrc* __fastcall ACCOUNTLIST_Create(int nX, int nY, int nWidth, int nHeight, int a5, D2WinAccountListFontStrc* pFont)
{
    D2WinAccountListStrc* pAccountList = (D2WinAccountListStrc*)FOG_Alloc(sizeof(D2WinAccountListStrc), ".\\Src\\D2WinAccountList.cpp", 0x24, 0);
    memset(pAccountList, 0, sizeof(D2WinAccountListStrc));
    pAccountList->controlHeader.eType = D2WIN_ACCOUNTLIST;
    pAccountList->controlHeader.dwFlags |= gdwBitMasks[0];
    pAccountList->controlHeader.dwFlags |= gdwBitMasks[2];
    pAccountList->unk0x4C = a5;
    pAccountList->controlHeader.nImageX = nX;
    pAccountList->controlHeader.nImageY = nY;
    pAccountList->controlHeader.nWidth = nWidth;
    pAccountList->controlHeader.nHeight = nHeight;
    pAccountList->controlHeader.pfDraw = ACCOUNTLIST_Draw;
    pAccountList->controlHeader.pfHandleMouseDown = ACCOUNTLIST_HandleMouseDown;
    pAccountList->controlHeader.pfHandleMouseUp = 0;
    pAccountList->controlHeader.pfHandleCharInput = 0;
    pAccountList->controlHeader.pfHandleVirtualKeyInput = 0;
    pAccountList->controlHeader.field_34 = 0;
    pAccountList->pDataList = 0;
    pAccountList->pSelectedDataEntry = 0;
    pAccountList->nFirstDrawnEntry = 0;
    pAccountList->controlHeader.pNext = 0;
    if (pFont)
    {
        pAccountList->eFont = pFont->eFont;
        pAccountList->unk0x54 = pFont->field_04;
    }
    else
    {
        pAccountList->eFont = 1;
        pAccountList->unk0x54 = 0;
    }
    CONTROL_AppendToList(&pAccountList->controlHeader);
    return pAccountList;
}

#include "gen/data/Source/D2Win/Src/D2WinAccountList.inc"
