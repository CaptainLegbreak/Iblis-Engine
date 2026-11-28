#include "D2Win.h"
#include "D2CelContext.h"
#include "D2Win32Types.h"

#include "D2Records.h"

#include "D2CmpTypes.h"

#include "D2ItemTypes.h"

#include "D2Txt.h"

#include "D2StormTypes.h"

#include "D2TxtTables.h"

#include "D2WinTypes.h"

#include "D2WinControls.h"

#include "D2Unicode.h"

#include "D2WinControls.h"
#include "D2WinListData.h"
#include "FogApi.h"
#include "D2LangApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinControlStrc;

struct D2UnitStrc;

struct Unicode;

struct D2WinListDataStrc;

struct D2WinListStrc;

struct D2WinAccountListDataStrc;

struct D2WinAccountListStrc;

struct D2WinListInitStrc;

enum D2ControlTypes
{
    D2WIN_LIST = 7,
    D2WIN_ACCOUNTLIST = 12,
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern unsigned char gabBeltHotkey[]; // 0x007BEFB0

extern int gnBeltBox; // 0x0072235C

extern int gnBeltRectX; // 0x00722360

extern int gnBeltRectY; // 0x00722364

extern int gnBeltHover; // 0x007BEF94

extern D2UnitStrc* gpBeltItemA; // 0x007BEFA8

extern int gpBeltItemB; // 0x007BEFAC

extern int gnPetIconPopupState; // 0x007BEECC

extern unsigned char gnLifeColorHigh; // 0x007BEED0

extern unsigned char gnLifeColorMid; // 0x007BEED1

extern unsigned char gnLifeColorLow; // 0x007BEED2

extern unsigned char gbLifeColorsInit; // 0x007BEED3

extern unsigned char gnTextColorRed; // 0x007BEFBA

extern unsigned char gabBeltColors[4]; // 0x007BEF6C

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gbHoverInGrid; // 0x007BCBE4

extern int gbHoverInBodyLoc; // 0x007BCBE8

extern int gnInvPanelMode; // 0x007BCBF0

extern D2UnitStrc* gpHoverItem; // 0x007BCBF4

extern int gpLastHoverItem; // 0x007BCBF8

enum D2FontTypes
{
    D2FONT_FONT16 = 1,
};

struct D2WinListInitStrc
{
    int nStringId;
    char nFlag;
    char pad0x05[3];
    int nValue;
    D2WinMsgHandler f_C;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

int __fastcall LIST_Draw(D2WinControlStrc* pControl); // 0x00507160

int __stdcall LIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg); // 0x005072F0

int __stdcall LIST_HandleCharInput(SMSGHANDLER_PARAMS* pMsg); // 0x005073B0

int __stdcall LIST_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg); // 0x00507420


Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

extern int ganListFontHeight[]; // 0x006DD024

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310


void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                   // 0x00526F20

extern D2CelFileStrc* sghPentagram; // 0x0087E96C

// 0x00507000
int __fastcall LIST_GetSelectedDataIndex(D2WinListStrc* ptListData)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_LIST, 0xD2);
    int nIndex = 0;
    D2WinListDataStrc* pData = ptListData->pDataList;
    while (pData)
    {
        if (ptListData->pSelectedDataEntry == pData)
        {
            break;
        }
        pData = pData->pNext;
        ++nIndex;
    }
    if (pData)
    {
        return nIndex;
    }
    return -1;
}

// 0x00507050
D2WinListDataStrc* __fastcall LIST_GetDataFromIndex(D2WinListStrc* ptListData, int nIndex)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_LIST, 0xE5);
    int nCounter = 0;
    D2WinListDataStrc* pData = ptListData->pDataList;
    while (pData)
    {
        if (nCounter == nIndex)
        {
            break;
        }
        pData = pData->pNext;
        ++nCounter;
    }
    if (pData)
    {
        return pData;
    }
    return 0;
}

// 0x005070A0
int __fastcall D2Win_10141(D2WinListStrc* ptListData)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_LIST, 0xF8);
    return ptListData->field_50;
}

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern tagPOINT gtMousePosition; // 0x007D55A4

extern unsigned long gdwListLastClickTick; // 0x0087E970


int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox); // 0x004F91C0

// 0x005070D0
void __stdcall LIST_LoadPentspinCellfile()
{
    D2_ASSERT(sghPentagram == 0, 0x103);

    char szFile[260];
    wsprintfA(szFile, "%s\\UI\\CURSOR\\Pentspin", gszDataGlobal);
    sghPentagram = ARCHIVE_LoadCellFile(szFile, 0);
}

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

// 0x00507160
int __fastcall LIST_Draw(D2WinControlStrc* pControl)
{
    D2WinListStrc* pList = (D2WinListStrc*)pControl;

    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x119);

    D2Win_10127_SetFont(pList->eFont);

    int nTextY = pList->controlHeader.nImageY - pList->controlHeader.nHeight + pList->field_48 + pList->field_44;

    D2WinListDataStrc* pData = pList->pDataList;
    for (int i = 0; i < pList->field_4C; ++i)
    {
        if (pData)
        {
            pData = pData->pNext;
        }
    }

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = sghPentagram;
    tContext.nDirection = 0;
    tContext.nFrame = pList->field_5C;

    while (pData)
    {
        if (nTextY >= pList->controlHeader.nImageY)
        {
            break;
        }

        const int nTextX = pList->controlHeader.nImageX + ((pList->controlHeader.nWidth - pData->field_200) >> 1);

        if (pData == pList->pSelectedDataEntry)
        {
            int nImageY = nTextY + 3;
            if (pList->eFont == 2)
            {
                nImageY += 6;
            }

            const int nOffsetX = (pList->controlHeader.nWidth - pList->nWidestEntry) >> 2;
            const int nImageX1 = pList->controlHeader.nImageX + nOffsetX - 25;
            const int nImageX2 = pList->controlHeader.nImageX - nOffsetX + pList->controlHeader.nWidth - 25;
            sub_004F6480(&tContext, nImageX1, nImageY, -1, 5, 0);
            sub_004F6480(&tContext, nImageX2, nImageY, -1, 5, 0);
        }

        D2Win_10117_DrawText(pData->wszText, nTextX, nTextY, 0, 0);

        pData->field_208 = pList->controlHeader.nImageX;
        pData->field_20C = pData->field_208 + pList->controlHeader.nWidth;
        pData->field_210 = nTextY - pList->field_44 - pList->field_48;
        pData->field_214 = nTextY + pList->field_48;

        nTextY += pList->field_44 + 2 * pList->field_48;

        pData = pData->pNext;
    }

    ++pList->field_5C;
    if (pList->field_5C >= 8)
    {
        pList->field_5C = 0;
    }

    D2Win_10127_SetFont(1);

    return 1;
}

// 0x005072F0
int __stdcall LIST_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinListStrc* pList = (D2WinListStrc*)pMsg->hWnd;
    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x154);
    const int nX = gtMousePosition.x;
    const int nY = gtMousePosition.y;
    const unsigned long dwTickCount = GetTickCount();
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pData->pNext)
    {
        if (nX > pData->field_208 && nX < pData->field_20C && nY > pData->field_210 && nY < pData->field_214)
        {
            if (pData != pList->pSelectedDataEntry || dwTickCount - gdwListLastClickTick >= 300)
                pList->pSelectedDataEntry = pData;
            else if (pData->field_204)
                return pData->field_204(pMsg);
        }
    }
    gdwListLastClickTick = dwTickCount;
    if (pList->controlHeader.field_34)
        return pList->controlHeader.field_34(pMsg);
    return 0;
}

// 0x005073B0
int __stdcall LIST_HandleCharInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinListStrc* pList = (D2WinListStrc*)pMsg->hWnd;
    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x179);
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pData->pNext)
    {
        if (pData->field_218 == (char)pMsg->wParam && pData->field_204)
            return pData->field_204(pMsg);
    }
    return 0;
}

D2CelFileStrc* sghPentagram; // 0x0087E96C

// 0x00507420
int __stdcall LIST_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinListStrc* pList = (D2WinListStrc*)pMsg->hWnd;
    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x18F);
    if (pMsg->uMessage == 0x102)
        return 0;
    switch (pMsg->wParam)
    {
    case 0x0D:
        CONTROL_SetFocusedEditBox(0);
        if (pList->pSelectedDataEntry->field_204)
            return pList->pSelectedDataEntry->field_204(pMsg);
        break;
    case 0x26:
    {
        D2WinListDataStrc* pTemp = pList->pDataList;
        if (pList->pDataList == pList->pSelectedDataEntry)
        {
            while (pTemp->pNext)
                pTemp = pTemp->pNext;
        }
        else
        {
            while (pTemp->pNext != pList->pSelectedDataEntry)
                pTemp = pTemp->pNext;
        }
        pList->pSelectedDataEntry = pTemp;
        pList->field_54 = 0;
        for (D2WinListDataStrc* pData = pList->pDataList; pData != pTemp; pData = pData->pNext)
            ++pList->field_54;
        const int nIndex = pList->field_54;
        if (pList->field_4C > nIndex)
            pList->field_4C = nIndex;
        else
            for (int n = nIndex - pList->field_4C; n > pList->field_58; --n)
                ++pList->field_4C;
        CONTROL_SetFocusedEditBox(0);
        return 1;
    }
    case 0x28:
    {
        D2WinListDataStrc* pNext = pList->pSelectedDataEntry->pNext;
        if (!pNext)
            pNext = pList->pDataList;
        pList->pSelectedDataEntry = pNext;
        pList->field_54 = 0;
        for (D2WinListDataStrc* pData = pList->pDataList; pData != pNext; pData = pData->pNext)
            ++pList->field_54;
        const int nIndex = pList->field_54;
        if (pList->field_4C > nIndex)
            pList->field_4C = nIndex;
        else
            for (int n = nIndex - pList->field_4C; n > pList->field_58; --n)
                ++pList->field_4C;
        CONTROL_SetFocusedEditBox(0);
        return 1;
    }
    }
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pData->pNext)
    {
        if ((unsigned short)pData->field_21C == pMsg->wParam && pData->field_204)
            return pData->field_204(pMsg);
    }
    return 0;
}

// 0x005075E0
D2WinListStrc* __fastcall LIST_Create(int nX, int nY, int nWidth, int nHeight, D2WinListInitStrc* pInit, int* pFont)
{
    D2WinListStrc* pList = (D2WinListStrc*)FOG_Alloc(sizeof(D2WinListStrc), ".\\Src\\D2WinList.cpp", 0x2E, 0);
    memset(pList, 0, sizeof(D2WinListStrc));
    pList->controlHeader.eType = D2WIN_LIST;
    pList->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pList->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pList->controlHeader.nImageX = nX;
    pList->controlHeader.nImageY = nY;
    pList->controlHeader.nWidth = nWidth;
    pList->controlHeader.nHeight = nHeight;
    pList->controlHeader.pCellFile = 0;
    pList->controlHeader.pfDraw = LIST_Draw;
    pList->controlHeader.pfHandleMouseDown = LIST_HandleMouseDown;
    pList->controlHeader.pfHandleMouseUp = 0;
    pList->controlHeader.pfHandleCharInput = LIST_HandleCharInput;
    pList->controlHeader.pfHandleVirtualKeyInput = LIST_HandleVirtualKeyInput;
    pList->controlHeader.field_34 = 0;
    pList->controlHeader.pNext = 0;
    pList->field_5C = 0;
    pList->pDataList = 0;
    pList->eFont = *pFont;
    pList->field_44 = ganListFontHeight[pList->eFont];
    pList->field_48 = ganListFontHeight[pList->eFont] >> 2;
    pList->nWidestEntry = 0;
    pList->field_4C = 0;
    pList->field_50 = 0;
    pList->field_54 = -1;
    pList->field_58 = nHeight / (pList->field_44 + 2 * pList->field_48) - 1;

    D2Win_10127_SetFont(*pFont);

    for (D2WinListInitStrc* pEntry = pInit; pEntry->nStringId; ++pEntry)
    {
        D2WinListDataStrc* pData = (D2WinListDataStrc*)FOG_Alloc(sizeof(D2WinListDataStrc), ".\\Src\\D2WinList.cpp", 0x56, 0);
        const Unicode* pText = D2LANG_GetStringFromTblIndex((unsigned short)pEntry->nStringId);
        D2_ASSERT(UNICODE_StrLen(pText) < 256, 0x58);
        sub_005267E0(pData->wszText, pText);

        int nTextWidth;
        int nTextHeight;
        D2Win_10131_GetTextDimensions(pText, &nTextWidth, &nTextHeight);
        nTextWidth += 8;
        if (nTextWidth > pList->nWidestEntry)
        {
            pList->nWidestEntry = nTextWidth;
        }

        pData->field_200 = nTextWidth;
        pData->field_204 = pEntry->f_C;
        pData->field_208 = 0;
        pData->field_20C = 0;
        pData->field_210 = 0;
        pData->field_214 = 0;
        pData->field_218 = pEntry->nFlag;
        pData->field_21C = pEntry->nValue;
        pData->pNext = 0;

        if (pList->pDataList)
        {
            D2WinListDataStrc* pLast = pList->pDataList;
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }
            pLast->pNext = pData;
        }
        else
        {
            pList->pDataList = pData;
        }

        ++pList->field_50;
    }

    D2Win_10127_SetFont(D2FONT_FONT16);
    pList->pSelectedDataEntry = pList->pDataList;
    CONTROL_AppendToList(&pList->controlHeader);
    return pList;
}

// 0x00506E60
int __fastcall LIST_Destroy(D2WinListStrc* pList)
{
    D2_ASSERT(pList->controlHeader.eType == D2WIN_LIST, 0x80);
    D2WinListDataStrc* pNext = 0;
    for (D2WinListDataStrc* pData = pList->pDataList; pData; pData = pNext)
    {
        pNext = pData->pNext;
        FOG_Free(pData, ".\\Src\\D2WinList.cpp", 0x85, 0);
    }
    return CONTROL_RemoveFromList(&pList->controlHeader);
}

// 0x00506EC0
void __fastcall D2Win_10137(D2WinListStrc* ptListData, const Unicode* wszText, D2WinMsgHandler pfnHandler, char cHotkey, int nVirtualKey, int bPrepend, int bSelect)
{
    D2_ASSERT(ptListData->controlHeader.eType == D2WIN_LIST, 0xA1);

    D2Win_10127_SetFont(ptListData->eFont);

    D2WinListDataStrc* pNewData = (D2WinListDataStrc*)FOG_Alloc(sizeof(D2WinListDataStrc), ".\\Src\\D2WinList.cpp", 0xA5, 0);
    D2_ASSERT(UNICODE_StrLen(wszText) < 256, 0xA6);

    sub_005267E0(pNewData->wszText, wszText);

    int nTextWidth;
    int nTextHeight;
    D2Win_10131_GetTextDimensions(wszText, &nTextWidth, &nTextHeight);
    nTextWidth += 8;
    if (nTextWidth > ptListData->nWidestEntry)
    {
        ptListData->nWidestEntry = nTextWidth;
    }

    pNewData->field_200 = nTextWidth;
    pNewData->field_204 = pfnHandler;
    pNewData->field_208 = 0;
    pNewData->field_20C = 0;
    pNewData->field_210 = 0;
    pNewData->field_214 = 0;
    pNewData->field_218 = cHotkey;
    pNewData->field_21C = nVirtualKey;

    if (!bPrepend)
    {
        D2WinListDataStrc* pLast = ptListData->pDataList;
        if (pLast)
        {
            while (pLast->pNext)
            {
                pLast = pLast->pNext;
            }

            pLast->pNext = pNewData;
            pNewData->pNext = 0;
        }
        else
        {
            ptListData->pDataList = pNewData;
            pNewData->pNext = 0;
        }
    }
    else
    {
        pNewData->pNext = ptListData->pDataList;
        ptListData->pDataList = pNewData;
    }

    ++ptListData->field_50;
    D2Win_10127_SetFont(1);

    if (bSelect)
    {
        ptListData->pSelectedDataEntry = pNewData;
        ptListData->field_54 = ptListData->field_50 - 1;
    }
}

// 0x005077F0
void __fastcall D2Win_10138(D2WinListStrc* pList, const char* szText, D2WinMsgHandler pfnHandler, char cHotkey, int nVirtualKey, int bPrepend, int bSelect)
{
    Unicode wszText[256];
    for (int i = 0; i < 256; i++)
        wszText[i].wChar = 0;
    sub_00526F20_ToUnicode(wszText, szText, 256);
    D2Win_10137(pList, wszText, pfnHandler, cHotkey, nVirtualKey, bPrepend, bSelect);
}

// 0x00507140
void __stdcall LIST_UnloadPentspinCellfile()
{
    ARCHIVE_FreeCellFile(sghPentagram);
    sghPentagram = 0;
}

#pragma pack(push, 1)
struct d2data_0072F010_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" const int gData_006DD024[14]; // 0x006DD024
extern "C" struct d2data_0072F010_t gData_0072F010; // 0x0072F010

extern "C" const int gData_006DD024[14] = { 8, 16, 30, 42 }; // 0x006DD024
#pragma comment(linker, "/alternatename:?ganListFontHeight@@3PAHA=_gData_006DD024")

extern "C" struct d2data_0072F010_t gData_0072F010 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x0072F010
