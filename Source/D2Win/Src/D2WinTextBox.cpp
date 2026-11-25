#include "D2Win.h"
#include "D2GameTypes.h"

#include "D2CelContext.h"

#include "D2GfxTypes.h"

#include "D2MultiTypes.h"

#include "D2Win32Types.h"

#include "D2StormTypes.h"

#include "D2WinControls.h"

#include "D2Structs.h"

#include "D2Txt.h"

#include "D2ClientTypes.h"

#include "D2WinTypes.h"

#include "D2Unicode.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// build: symbol ?gnMouseY@* 0x007D55A8
#define gnMouseY (gtMousePosition.y)

struct D2CelFileStrc;

struct D2WinControlStrc;

struct D2WinTextBoxStrc;

struct D2WinListEntry004FBB30Strc;

struct D2WinControl004FBB30Strc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0

void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet); // 0x004F9740

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern tagPOINT gtMousePosition; // 0x007D55A4

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

int __stdcall D2Win_10125(); // 0x00501A40

int __stdcall CONTROL_AppendToList(D2WinTextBoxStrc* pControl); // 0x004F9210

D2WinScrollBarStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int pfnHandler); // 0x005084F0

int __fastcall SCROLLBAR_SetTextBox(D2WinScrollBarStrc* pScrollBar, D2WinTextBoxStrc* pTextBox); // 0x00507FD0

extern "C" void __fastcall D2Win_10202(D2WinScrollBarStrc* pScrollBar, int nValue); // 0x005080C0

int __fastcall TEXTBOX_Draw(D2WinTextBoxStrc* pTextBox); // 0x004FBF30

int __stdcall TEXTBOX_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg); // 0x004FC3F0

int __stdcall TEXTBOX_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg);

struct D2WinListEntry004FBB30Strc
{
    void* pData;
    unsigned char f_4[0x18];
    D2WinListEntry004FBB30Strc* pNext1C;
};

struct D2WinControl004FBB30Strc
{
    int eType;
    unsigned char f_4[0x44];
    D2WinListEntry004FBB30Strc* pFirstEntry48;
    unsigned char unk_4C[0x10];
    unsigned int dwFlags5C;
    int nSelected60;
};

int gbTextBoxSmallGap; // 0x00841B70

tagPALETTEENTRY gaPalette_0081E668[256]; // 0x0081E668

struct D2WinTextBoxLineStrc;

struct Unicode;

struct D2WinImageClickRectStrc;

struct D2WinImageStrc;

struct D2CropRectStrc;

struct D2CelContextStrc;

struct D2CharStrc;

struct D2FontStrc;

struct D2FontCacheStrc;

struct D2GemsTxt;

struct D2UnitStrc;

struct D2ItemsTxt;

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

enum D2WinControlType
{
    D2WIN_TEXTBOX = 4,
};

enum TextBoxFlags
{
    TEXTBOXFLAG_NO_WORD_WRAP = 0x20,
};

int __fastcall SCROLLBAR_SetMaxSteps(D2WinScrollBarStrc* pScrollBar, int nMaxSteps); // 0x00507F20

int __fastcall SCROLLBAR_SetCurrentStep(D2WinScrollBarStrc* pScrollBar, int nCurrentStep); // 0x00507F60

extern "C" int __fastcall SCROLLBAR_GetScrollBarField4C(D2WinScrollBarStrc* pScrollBar); // 0x00507FA0

int __fastcall SCROLLBAR_SetScrollCallback(D2WinScrollBarStrc* pScrollBar, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*)); // 0x00508000

extern "C" int __fastcall D2Win_10201(D2WinScrollBarStrc* pScrollBar); // 0x005080F0

typedef int (__stdcall* D2WinMsgHandler)(struct SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

enum D2ControlTypes
{
    D2WIN_IMAGE = 2,
};

enum DrawMode
{
    DRAWMODE_NORMAL = 5,
};

void __stdcall TEXTURE_CelDrawClipped(D2CelContextStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510

int __fastcall D2Win_10058_0(D2WinControlStrc* pControl, const Unicode* pText, int nLineNum, int nColumn); // 0x004FB790

int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox); // 0x004FBAB0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern D2FontCacheStrc gatFontCache[]; // 0x00841DA8

void __fastcall TEXT_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E6720

void __fastcall SKILLDESC_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E67D0

int __stdcall PALETTE_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName); // 0x004FB1E0

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

extern tagPALETTEENTRY gatRGBAPalette[]; // 0x0081E668

extern "C" const char gszD2WinTextBoxCpp[]; // 0x006DC840

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0

int __fastcall D2Win_10051(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

int __fastcall EDITBOX_SetText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

struct D2WinScrollBarStrc;

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" int __fastcall SCROLLBAR_GetScrollBarField48(D2WinScrollBarStrc* ptScrollbarData); // 0x00507EF0

extern "C" int __cdecl isspace(int c);                                                                      // 0x00687006

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags);                  // 0x00412650

int __fastcall TEXTBOX_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent); // 0x004FCDA0

static int TEXTBOX_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox); // 0x004FBE90

int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl);                                           // 0x004F9310

void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl);                                         // 0x004FB6A0

void __fastcall SCROLLBAR_Destroy(void* pArg);                                                                   // 0x00507EE0

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

void __fastcall FONT_DrawTextWithBackground(const Unicode* wszText, int nX, int nY, int nWidth, int nColor, int eDrawMode, int nTextColor); // 0x005025C0

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

void __fastcall D2WINFONT_DrawTickerText(const Unicode* wszText, int nX, int nY, int nColor, int nScroll, int nWidth); // 0x00501FE0

static void TEXTBOX_SetLineGapForFont(int nFont); // 0x004FB5A0

extern "C" const char gszPathFormat_006D4124[];                                                             // 0x006D4124

extern "C" const char gszPalDat[];                                                                  // 0x006DC7FC

void __fastcall D2COMP_InitEmblemColorTables();                                                                // 0x005055D0

struct D2Palette256Strc;

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332

void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pMPQHandle); // 0x005173AC

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern "C" const char gszPatchD2Mpq[]; // 0x006DC728

extern "C" const char gszD2SfxMpq[]; // 0x006DC764

extern "C" const char gszD2DataMpq[]; // 0x006DC770

extern D2ArchiveHandleStrc* gpD2CharMPQ; // 0x007D5610

extern D2ArchiveHandleStrc* gpD2XTalkMPQ; // 0x007D5618

extern D2ArchiveHandleStrc* gpD2MusicMPQ; // 0x007D5628

struct D2Palette256Strc
{
    unsigned char data[0x100];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern int gbPaletteFlash; // 0x0072DE50

extern D2Palette256Strc gatShadowsLightGammaPalette[49]; // 0x0081EA68

int __cdecl ARCHIVE_ShowInsertExpansionDiscMessage(); // 0x004FAB00

int __cdecl ARCHIVE_ShowInsertPlayDiscMessage(); // 0x004FAB30

int __cdecl ARCHIVE_ShowInsertCinematicsDisc(); // 0x004FAB60

extern D2ArchiveHandleStrc* gpD2XMusicMPQ; // 0x007D5604

extern D2ArchiveHandleStrc* gpD2SfxMPQ; // 0x007D5608

extern D2ArchiveHandleStrc* gpD2DeltaMPQ; // 0x007D560C

extern D2ArchiveHandleStrc* gpD2VideoMPQ; // 0x007D5614

extern D2ArchiveHandleStrc* gpD2DataMPQ; // 0x007D561C

extern D2ArchiveHandleStrc* gpD2kfixupMPQ; // 0x007D5620

extern D2ArchiveHandleStrc* gpD2SpeechMPQ; // 0x007D5624

extern D2ArchiveHandleStrc* gpD2PatchMPQ; // 0x007D5630

extern D2ArchiveHandleStrc* gpD2ExpMPQ; // 0x007D5634

int __cdecl ARCHIVE_LoadArchives(); // 0x004FAB90

void __fastcall D2Win_10178_CopyGammaTable(unsigned char (*pRows)[0x100]); // 0x004FB1C0

extern int gnPaletteFlashCount; // 0x007D5638

extern unsigned char gabStatesPalette[128][0x100]; // 0x007D6468

extern int gbPaletteFlashWaiting; // 0x00841B68

extern unsigned long gdwPaletteFlashTick; // 0x00841B6C

unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex); // 0x004FB0C0

void __stdcall D2Win_10179_UpdatePaletteFlash(); // 0x004FB0D0

void __fastcall D2Win_10176_StartPaletteFlash(int bTimed); // 0x004FB130

void* __stdcall D2Win_GetArchive(); // 0x004FAC80

void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pBuffer, int nSize)
{
    Unicode wszTemp[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszTemp[i].wChar = 0;

    D2_ASSERT(ITEMSIsA(pItem, 0x35), 0x21A);
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0x21C);
    pBuffer[0].wChar = 0;

    if (ITEMSIsA(pItem, 0x14))
    {
        D2GemsTxt* pGemsTxt = DATATBLS_GetGemsTxtRecord(pItemsTxt->dwGemOffset);
        D2_ASSERT(pGemsTxt, 0x223);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B42));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 2, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B41));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B44));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B43));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 0, pBuffer, nSize, (int)wszTemp);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        D2GemsTxt* pGemsTxt = DATATBLS_GetGemsTxtRecord(pItemsTxt->dwGemOffset);
        D2_ASSERT(pGemsTxt, 0x245);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B42));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 2, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B41));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B44));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 1, pBuffer, nSize, (int)wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B43));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 0, pBuffer, nSize, (int)wszTemp);
    }
    else
    {
        return;
    }

    sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
}

// 0x004FB480
int __fastcall D2Win_10177(unsigned char nAct)
{
    int nActNo = nAct + 1;
    if (nActNo < 1 || nActNo > 5)
        nActNo = 1;

    char szPL2Filename[260];
    char szDatFilename[260];
// build: symbol ?gszDataGlobal@* 0x006D4118
    sprintf(szDatFilename, "%s\\palette\\act%d\\%s", gszDataGlobal, nActNo, "pal.dat");
    sprintf(szPL2Filename, "%s\\palette\\act%d\\%s", gszDataGlobal, nActNo, "pal.pl2");
    const int nResult = PALETTE_LoadPaletteFiles(szDatFilename, szPL2Filename);
    D2GFX_SetPalette(gatRGBAPalette);
    return nResult;
}

// 0x004FB500
int __stdcall D2Win_10028(const char* pszPalDatFilename, const char* pszPalPL2Filename)
{
    if (!pszPalDatFilename)
    {
        char szPalDatFilename[260];
        char szPalPL2Filename[260];
// build: symbol ?gszDataGlobal@* 0x006D4118
        wsprintfA(szPalDatFilename, gszPathFormat_006D4124, gszDataGlobal, gszPalDat);
        wsprintfA(szPalPL2Filename, gszPathFormat_006D4124, gszDataGlobal, "palette\\act1\\pal.pl2");
        PALETTE_LoadPaletteFiles(szPalDatFilename, szPalPL2Filename);
    }
    else
    {
        PALETTE_LoadPaletteFiles(pszPalDatFilename, pszPalPL2Filename);
    }

    D2COMP_InitEmblemColorTables();
    return 1;
}

// 0x004FB590
void __fastcall TEXTBOX_SetSmallGap(int nValue)
{
    gbTextBoxSmallGap = nValue;
}

// 0x004FB5A0
static void TEXTBOX_SetLineGapForFont(int nFont)
{
    if (sub_00525150() == 7)
    {
        const int nOldFont = D2Win_10127_SetFont(nFont);
        if (D2Win_10125() > 13)
        {
// build: symbol ?gnTextBoxLineGap@* 0x0072DE90
            gnTextBoxLineGap = 8;
        }
        else
        {
            gnTextBoxLineGap = (D2Win_10125() > 7) + 6;
        }
        D2Win_10127_SetFont(nOldFont);
    }
    else if (sub_00525150() == 9)
    {
        const int nOldFont = D2Win_10127_SetFont(nFont);
        if (D2Win_10125() > 13)
        {
            gnTextBoxLineGap = 8;
        }
        else
        {
            gnTextBoxLineGap = (D2Win_10125() > 7) + 6;
        }
        if (gbTextBoxSmallGap)
        {
            gnTextBoxLineGap = 3;
        }
        D2Win_10127_SetFont(nOldFont);
    }
    else if (sub_00525150() == 6)
    {
        gnTextBoxLineGap = gbTextBoxSmallGap != 0 ? 0 : 4;
    }
    else if (sub_00525150() == 10)
    {
        gnTextBoxLineGap = gbTextBoxSmallGap != 0 ? 0 : 4;
    }
    else
    {
        gnTextBoxLineGap = 4;
    }
}

// 0x004FB6A0
int __fastcall D2Win_10047(D2WinTextBoxStrc* ptTextData)
{
    if (!ptTextData)
        return 0;

    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0xDE);

    D2WinTextBoxLineStrc* pNext = 0;
    for (D2WinTextBoxLineStrc* pLine = ptTextData->pFirstLine; pLine; pLine = pNext)
    {
        pNext = pLine->pNext;
        for (int i = 0; i < 5; ++i)
        {
            if (pLine->pColumns[i])
                FOG_Free(pLine->pColumns[i], ".\\Src\\D2WinTextBox.cpp", 0xE7, 0);
        }
        FOG_Free(pLine, ".\\Src\\D2WinTextBox.cpp", 0xE9, 0);
    }

    ptTextData->pCurrentLine = 0;
    ptTextData->pFirstLine = 0;
    ptTextData->pLastLine = 0;
    ptTextData->nNumLines = 0;
    ptTextData->nLine = 0;
    return 1;
}

// 0x004FB740
int __fastcall D2Win_10062(D2WinTextBoxStrc* ptTextData, int nWrappedLineGap, int nLineGap)
{
    D2_ASSERT(ptTextData, 0xFA);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0xFB);

    ptTextData->nWrappedLineGap = nWrappedLineGap;
    ptTextData->nLineGap = nLineGap;
    return 1;
}

// 0x004FB790
int __fastcall D2Win_10058_0(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int nLineNum, int nColumn)
{
    D2_ASSERT(pTextBox, 0x1F9);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x1FA);
    D2_ASSERT(pTextBox->nNumColumns > nColumn, 0x1FB);

    Unicode wszText[1024];
    sub_005267E0(wszText, pText);

    D2WinTextBoxLineStrc* ptLine = pTextBox->pFirstLine;
    for (int i = 0; i < nLineNum; ++i)
    {
        if (!ptLine)
            return 1;

        ptLine = ptLine->pNext;
    }

    if (ptLine)
    {
        D2_ASSERT(ptLine->pColumns[nColumn] == 0, 0x20F);
        ptLine->pColumns[nColumn] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(wszText) + 1), ".\\Src\\D2WinTextBox.cpp", 0x210, 0);
        sub_005267E0(ptLine->pColumns[nColumn], wszText);
    }

    return 1;
}

// 0x004FB870
void __fastcall D2Win_10197(D2WinTextBoxStrc* pTextBox, int nLineNum)
{
    D2_ASSERT(pTextBox, 0x21D);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x21E);
    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x21F);

    D2WinTextBoxLineStrc* ptLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!ptLine->pNext)
        {
            break;
        }
        ptLine = ptLine->pNext;
        ++i;
    }

    D2_ASSERT(ptLine, 0x229);
    D2_ASSERT(i == nLineNum, 0x22A);

    for (int j = 0; j < 5; ++j)
    {
        if (ptLine->pColumns[j])
        {
            FOG_Free(ptLine->pColumns[j], ".\\Src\\D2WinTextBox.cpp", 0x231, 0);
            ptLine->pColumns[j] = 0;
        }
    }
}

// 0x004FB910
int __fastcall D2Win_10052_TEXTBOX_GetNumLines(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x23E);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x23F);

    return ptTextData->nNumLines;
}

// 0x004FB950
int __fastcall D2Win_10054(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x24A);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x24B);

    return ptTextData->nLine;
}

// 0x004FB990
int __fastcall D2Win_10049(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x256);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x257);

    return ptTextData->nCurrentLine;
}

// 0x004FB9D0
void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* ptTextData, int nLine)
{
    D2_ASSERT(ptTextData, 0x262);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x263);

    ptTextData->nCurrentLine = D2_MIN(D2_MAX(nLine, -1), ptTextData->nNumLines - 1);
}

// 0x004FBA30
int __fastcall D2Win_10053(D2WinTextBoxStrc* ptTextData, int nLine)
{
    D2_ASSERT(ptTextData, 0x271);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x272);

    nLine = nLine < ptTextData->nNumLines ? nLine : ptTextData->nNumLines;

    D2WinTextBoxLineStrc* pLine = ptTextData->pFirstLine;
    for (int i = 0; i < nLine; ++i)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
    }

    if (pLine)
    {
        ptTextData->pCurrentLine = pLine;
        ptTextData->nLine = nLine;
    }

    if (ptTextData->pScrollBar)
    {
        SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, nLine);
    }

    return 1;
}

// 0x004FBAB0
int __fastcall D2Win_10055(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x290);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x291);

    D2Win_10127_SetFont(ptTextData->eFont);
    const int nHeight = ptTextData->controlHeader.nHeight - 2 * ptTextData->nTextInsetY;
    TEXTBOX_SetLineGapForFont(ptTextData->eFont);
    const int nLineHeight = D2Win_10125() + ptTextData->nLineSpacing;
    return (nHeight - nLineHeight) / (nLineHeight + ptTextData->nLineGap) + 1;
}

// 0x004FBB30
void* __fastcall D2Win_10048(D2WinControl004FBB30Strc* pControl)
{
    D2_ASSERT(pControl, 0x2A6);
    D2_ASSERT(pControl->eType == 4, 0x2A7);
    if (pControl->nSelected60 != -1 && (pControl->dwFlags5C & 1))
    {
        D2WinListEntry004FBB30Strc* pEntry;
        int nIndex;
        for (pEntry = pControl->pFirstEntry48, nIndex = 0; pEntry; pEntry = pEntry->pNext1C, ++nIndex)
        {
            if (pControl->nSelected60 == nIndex)
            {
                return pEntry->pData;
            }
        }
    }
    return 0;
}

// 0x004FBB90
Unicode* __fastcall D2Win_10196(D2WinTextBoxStrc* pTextBox, int nLineNum, int nColumnNum)
{
    D2_ASSERT(pTextBox, 0x2C2);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x2C3);
    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x2C4);
    D2_ASSERT(nColumnNum < 5, 0x2C5);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
        ++i;
    }

    D2_ASSERT(pLine, 0x2CF);
    D2_ASSERT(i == nLineNum, 0x2D0);

    return pLine->pColumns[nColumnNum];
}

// 0x004FBC20
void __fastcall D2Win_10056(D2WinTextBoxStrc* pTextBox, int nNumColumns)
{
    D2_ASSERT(pTextBox, 0x2DD);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x2DE);
    D2_ASSERT((nNumColumns > 0) && (nNumColumns <= 5), 0x2E0);
    D2_ASSERT(pTextBox->nNumColumns <= nNumColumns, 0x2E2);

    pTextBox->nNumColumns = nNumColumns;

    if (nNumColumns > 1)
    {
        pTextBox->dwTextBoxFlags |= TEXTBOXFLAG_NO_WORD_WRAP;
    }
}

// 0x004FBC80
void __fastcall D2Win_10059(D2WinTextBoxStrc* pTextBox, int nColumn, int nOffset)
{
    D2_ASSERT(pTextBox, 0x2EF);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x2F0);
    D2_ASSERT((nColumn >= 0) && (nColumn < pTextBox->nNumColumns), 0x2F2);
    pTextBox->nColumnOffsets[nColumn] = nOffset;
}

// 0x004FBCD0
void __fastcall D2Win_10060(D2WinTextBoxStrc* ptTextData, int nColumn, int nAlignFlags)
{
    D2_ASSERT(ptTextData, 0x2FC);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x2FD);
    D2_ASSERT(nColumn >= 0, 0x2FF);
    ptTextData->nColumnAlignFlags[nColumn] = nAlignFlags;
}

// 0x004FBD20
int __fastcall D2Win_10061(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x309);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x30A);

    int nLineCount = 0;
    for (D2WinTextBoxLineStrc* pLine = ptTextData->pFirstLine; pLine; pLine = pLine->pNext)
    {
        if (!pLine->pNext)
        {
            break;
        }

        ++nLineCount;
    }

    return nLineCount;
}

// 0x004FBD70
void __fastcall D2Win_10187(D2WinControlStrc* pControl, int bSet)
{
    CONTROL_SetVisible(pControl, bSet);
    D2_ASSERT(pControl, 0x320);
    D2_ASSERT(pControl->eType == 4, 0x321);
    D2WinScrollBarStrc* pScrollBar = ((D2WinTextBoxStrc*)pControl)->pScrollBar;
    if (pScrollBar)
    {
        CONTROL_SetVisible((D2WinControlStrc*)pScrollBar, bSet);
    }
}

// 0x004FBDC0
void __cdecl TEXTBOX_AssertUnsupported()
{
    D2_ASSERT(0, 0x32E);
}

// 0x004FBDE0
int __fastcall D2Win_10188(D2WinTextBoxStrc* pTextBox, int nLineNum, int nColor)
{
    D2_ASSERT(pTextBox, 0x368);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x369);

    if (nLineNum == -1)
    {
        for (D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine; pLine; pLine = pLine->pNext)
        {
            pLine->nColor = nColor;
        }

        return 1;
    }

    D2_ASSERT(nLineNum <= pTextBox->nNumLines, 0x378);

    D2WinTextBoxLineStrc* pLine = pTextBox->pFirstLine;
    int i = 0;
    while (i < nLineNum)
    {
        if (!pLine->pNext)
        {
            break;
        }

        pLine = pLine->pNext;
        ++i;
    }

    D2_ASSERT(pLine, 0x382);
    D2_ASSERT(i == nLineNum, 0x383);

    pLine->nColor = nColor;
    return 1;
}

// 0x004FBE90
static int TEXTBOX_CountLinesFromCurrent(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x393);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x394);

    D2WinTextBoxLineStrc* pLine = pTextBox->pCurrentLine;
    int nCount = 0;
    while (pLine)
    {
        pLine = pLine->pNext;
        ++nCount;
    }

    return nCount;
}

// 0x004FBEE0
static int __stdcall TEXTBOX_TruncateTextToWidth(int nWidth, Unicode* wszText)
{
    int i = 0;
    const int nLength = sub_00526800(wszText);
    while (i < nLength)
    {
        if (D2Win_10122(wszText, i + 1) >= nWidth)
        {
            break;
        }
        ++i;
    }

    wszText[i].wChar = 0;
    return i;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FBF30
int __fastcall TEXTBOX_Draw(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x3BC);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x3BD);

    if (!(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[0]))
    {
        return 0;
    }

    const unsigned char nColor = D2Win_10034_MixRGB(0x40, 0x40, 0x40);

    D2CelFileStrc* pCellFile = pTextBox->controlHeader.pCellFile;
    if (pCellFile)
    {
        D2CelContextStrc tGfxData;
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.pCellFile = pCellFile;
        tGfxData.nDirection = 0;
        tGfxData.nFrame = 0;
        TEXTURE_CelDraw(&tGfxData, pTextBox->controlHeader.nImageX, pTextBox->controlHeader.nImageY - 1, -1, 5, 0);
    }

    TEXTBOX_SetLineGapForFont(pTextBox->eFont);
    D2Win_10127_SetFont(pTextBox->eFont);

    const int v51 = pTextBox->controlHeader.nImageX + pTextBox->nTextInsetX;
    int nY = D2Win_10125() + (pTextBox->controlHeader.nImageY - pTextBox->controlHeader.nHeight) + pTextBox->nTextInsetY;

    TEXTBOX_SetLineGapForFont(pTextBox->eFont);

    const int v8 = D2Win_10125() + pTextBox->nLineSpacing;
    int v49 = pTextBox->controlHeader.nHeight - 2 * pTextBox->nTextInsetY;
    const int nBoxWidth = pTextBox->controlHeader.nWidth - 2 * pTextBox->nTextInsetX;

    if (pTextBox->dwTextBoxFlags & 0x40)
    {
        D2WinTextBoxLineStrc* pCurrentLine = pTextBox->pCurrentLine;
        if (pCurrentLine)
        {
            pTextBox->nScrollOffset -= 2;
            if (pTextBox->nScrollOffset < -D2Win_10121_GetTextWidth(pCurrentLine->pColumns[0]))
            {
                pTextBox->nScrollOffset = nBoxWidth;
            }
        }
    }

    if (pTextBox->dwTextBoxFlags & 0x80)
    {
        D2WinTextBoxLineStrc* pCurrentLine = pTextBox->pCurrentLine;
        if (pCurrentLine)
        {
            pTextBox->nScrollOffset -= 2;
            if (pTextBox->nScrollOffset < -v8)
            {
                pTextBox->nScrollOffset = 0;
                pTextBox->pCurrentLine = pCurrentLine->pNext;
            }
        }
    }

    D2WinTextBoxLineStrc* pLine = pTextBox->pCurrentLine;
    int nCounter = 0;
    if (pLine)
    {
        do
        {
            for (int i = 0; i < pTextBox->nNumColumns; ++i)
            {
                const Unicode* wszColumn = pLine->pColumns[i];
                if (!wszColumn)
                {
                    break;
                }

                int v48 = pTextBox->controlHeader.nWidth;
                if (i < pTextBox->nNumColumns - 1)
                {
                    v48 = pTextBox->nColumnOffsets[i + 1];
                }

                const int v16 = pTextBox->nColumnOffsets[i];
                int nX;
                if (v16)
                {
                    nX = v16 + v51;

                    int v18;
                    if (i + 1 < pTextBox->nNumColumns)
                    {
                        v18 = pTextBox->nColumnOffsets[i + 1] - v16;
                        v48 = v18;
                    }
                    else
                    {
                        v48 = pTextBox->controlHeader.nWidth - v16;
                        v18 = v48;
                    }

                    if (pTextBox->nColumnAlignFlags[i] & 2)
                    {
                        // the original keeps the column pointer in a stack slot and reloads it here; a plain read is taken again from pLine->pColumns[i]
                        int nOffset = (v18 - D2Win_10121_GetTextWidth(*(const Unicode* volatile*)&wszColumn)) / 2;
                        if (nOffset < 0)
                        {
                            nOffset = 0;
                        }
                        nX += nOffset;
                    }
                    else if (pTextBox->nColumnAlignFlags[i] & 0x10)
                    {
                        int nTextWidth = D2Win_10121_GetTextWidth(wszColumn);
                        if (nTextWidth < 0)
                        {
                            nTextWidth = 0;
                        }
                        nX += v48 - nTextWidth;
                    }
                }
                else if (pTextBox->dwTextBoxFlags & 2)
                {
                    int nOffset = (pTextBox->controlHeader.nWidth - D2Win_10121_GetTextWidth(pLine->pColumns[0])) / 2;
                    if (nOffset < 0)
                    {
                        nOffset = 0;
                    }
                    nX = pTextBox->controlHeader.nImageX + nOffset;
                }
                else if (pTextBox->dwTextBoxFlags & 0x10)
                {
                    int nTextWidth = D2Win_10121_GetTextWidth(pLine->pColumns[0]);
                    if (nTextWidth < 0)
                    {
                        nTextWidth = 0;
                    }
                    nX = pTextBox->controlHeader.nImageX - nTextWidth;
                }
                else
                {
                    nX = v51;
                }

                Unicode wszText[1024];
                for (int j = 0; j < 1024; ++j)
                {
                    wszText[j].wChar = 0;
                }
                sub_005267E0(wszText, pLine->pColumns[i]);
                TEXTBOX_TruncateTextToWidth(v48, wszText);

                if (pTextBox->nCurrentLine == nCounter + pTextBox->nLine && (pTextBox->dwTextBoxFlags & 1))
                {
                    const int nLineColor = pLine->nColor != 4 ? pLine->nColor : 0;
                    if (!i)
                    {
                        FONT_DrawTextWithBackground(wszText, nX, nY, nBoxWidth, nColor, 5, nLineColor);
                    }
                    else
                    {
                        D2Win_10117_DrawText(wszText, nX, nY, nLineColor, 0);
                    }
                }
                else if (pTextBox->dwTextBoxFlags & 0x40)
                {
                    D2WINFONT_DrawTickerText(pLine->pColumns[i], nX, nY, pLine->nColor, pTextBox->nScrollOffset, nBoxWidth);
                }
                else if (pTextBox->dwTextBoxFlags & 0x80)
                {
                    D2Win_10117_DrawText(wszText, nX, nY + pTextBox->nScrollOffset, pLine->nColor, 0);
                }
                else
                {
                    D2Win_10117_DrawText(wszText, nX, nY, pLine->nColor, 0);
                }
            }

            const int v34 = (!pLine->bWrappedSegment ? pTextBox->nLineGap : pTextBox->nWrappedLineGap) + v8;
            ++nCounter;
            nY += v34;
            v49 -= v34;
            pLine = pLine->pNext;
        }
        while (pLine && v49 >= (!pLine->bWrappedSegment ? pTextBox->nLineGap : pTextBox->nWrappedLineGap) + v8);
    }

    D2Win_10127_SetFont(1);
    return 1;
}

// 0x004FC2F0
int __stdcall TEXTBOX_HandleMouseDown(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)pMsg->hWnd;
    D2_ASSERT(pTextBox, 0x4D0);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x4D1);

    if (!(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[0]) || pTextBox->nNumLines < 1)
    {
        return 0;
    }

    if (pTextBox->dwTextBoxFlags & 1)
    {
        const int nY = pTextBox->controlHeader.nHeight - pTextBox->controlHeader.nImageY + gnMouseY;
        D2Win_10127_SetFont(pTextBox->eFont);
        TEXTBOX_SetLineGapForFont(pTextBox->eFont);
        pTextBox->nCurrentLine = pTextBox->nLine + (nY - pTextBox->nTextInsetY) / (D2Win_10125() + pTextBox->nLineSpacing);
        if (pTextBox->dwTextBoxFlags & 8)
        {
            pTextBox->nCurrentLine = D2_MIN(D2_MAX(pTextBox->nCurrentLine, 0), pTextBox->nNumLines - 1);
        }
        else if (pTextBox->nCurrentLine < 0 || pTextBox->nCurrentLine >= pTextBox->nNumLines)
        {
            pTextBox->nCurrentLine = -1;
        }
    }

    if (pTextBox->controlHeader.field_34)
    {
        return pTextBox->controlHeader.field_34(pMsg);
    }
    return 0;
}

// 0x004FC3F0
int __stdcall TEXTBOX_HandleVirtualKeyInput(SMSGHANDLER_PARAMS* pMsg)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)pMsg->hWnd;

    D2_ASSERT(pTextBox, 0x501);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x502);

    if (!(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[2]) || !(pTextBox->controlHeader.dwFlags & gdwBitMasks_006CE268[0])
// build: symbol ?CONTROL_GetFocusedEditBox@* 0x004F9200
        || pTextBox->nNumLines < 1 || pTextBox->nCurrentLine == -1 || CONTROL_GetFocusedEditBox())
    {
        return 0;
    }

    const int nNumLines = pTextBox->nNumLines;
    int nLine = pTextBox->nLine;
    int nCurrentLine = pTextBox->nCurrentLine;
    const int nVisibleLines = D2Win_10055((D2WinTextBoxStrc*)pMsg->hWnd);

    switch (pMsg->wParam)
    {
    case 0x21:
        if (nCurrentLine > nLine)
        {
            nCurrentLine = nLine;
        }
        else if (nLine > 0)
        {
            nLine = D2WIN_MAX(nLine - nVisibleLines + 1, 0);
            nCurrentLine = nLine;
        }
        break;

    case 0x22:
    {
        const int nLastVisible = nVisibleLines + nLine - 1;
        if (nCurrentLine < nLastVisible)
        {
            nCurrentLine = D2WIN_MIN(nLastVisible, nNumLines - 1);
        }
        else if (nLine < nNumLines - nVisibleLines)
        {
            nLine = D2WIN_MIN(nLastVisible, nNumLines - nVisibleLines);
            nCurrentLine = D2WIN_MIN(nVisibleLines + nLine - 1, nNumLines - 1);
        }
        break;
    }

    case 0x26:
        if (nCurrentLine > 0)
        {
            --nCurrentLine;
            if (nCurrentLine < nLine)
            {
                nLine = nCurrentLine;
            }
            else if (nCurrentLine > nVisibleLines + nLine - 1)
            {
                nLine = nCurrentLine - nVisibleLines + 1;
            }
        }
        break;

    case 0x28:
        if (nCurrentLine < nNumLines - 1)
        {
            ++nCurrentLine;
            if (nCurrentLine < nLine)
            {
                nLine = nCurrentLine;
            }
            else if (nCurrentLine > nVisibleLines + nLine - 1)
            {
                nLine = nCurrentLine - nVisibleLines + 1;
            }
        }
        break;

    case 0x24:
        nCurrentLine = 0;
        nLine = 0;
        break;

    case 0x23:
        nCurrentLine = nNumLines - 1;
        nLine = nNumLines - nVisibleLines;
        break;
    }

    const int bHasChanged = nCurrentLine != pTextBox->nCurrentLine;
    pTextBox->nCurrentLine = nCurrentLine;

    if (nNumLines > nVisibleLines && nLine != pTextBox->nLine)
    {
        D2Win_10053((D2WinTextBoxStrc*)pMsg->hWnd, nLine);
    }

    if (bHasChanged && pTextBox->controlHeader.field_34)
    {
        pTextBox->controlHeader.field_34(pMsg);
    }

    return 0;
}

// 0x004FC5A0
extern "C" int __fastcall D2Win_10190(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x578);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x579);
    return SCROLLBAR_GetScrollBarField48(ptTextData->pScrollBar);
}

// 0x004FC5E0
int __fastcall D2Win_10191(D2WinTextBoxStrc* ptTextData, int nMaxSteps)
{
    D2_ASSERT(ptTextData, 0x582);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x583);

    return SCROLLBAR_SetMaxSteps(ptTextData->pScrollBar, nMaxSteps);
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FC620
int __fastcall D2Win_10192(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0x58C);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x58D);

    return SCROLLBAR_GetScrollBarField4C(ptTextData->pScrollBar);
}

// 0x004FC660
int __fastcall D2Win_10193(D2WinTextBoxStrc* ptTextData, int nCurrentStep)
{
    D2_ASSERT(ptTextData, 0x596);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x597);

    return SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, nCurrentStep);
}

// 0x004FC6A0
int __fastcall D2Win_10194(D2WinTextBoxStrc* ptTextData, D2WinTextBoxStrc* pLinkedTextBox)
{
    D2_ASSERT(ptTextData, 0x5A0);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x5A1);

    return SCROLLBAR_SetTextBox(ptTextData->pScrollBar, pLinkedTextBox);
}

// 0x004FC6E0
int __fastcall D2Win_10195(D2WinTextBoxStrc* pTextBox, void(__stdcall* pfScrollCallback)(SMSGHANDLER_PARAMS*))
{
    D2_ASSERT(pTextBox, 0x5AA);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x5AB);

    return SCROLLBAR_SetScrollCallback(pTextBox->pScrollBar, pfScrollCallback);
}

// 0x004FC720
void __fastcall D2Win_10204(D2WinTextBoxStrc* ptTextData, int nPosition)
{
    D2_ASSERT(ptTextData, 0x5B4);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0x5B5);

    D2Win_10202(ptTextData->pScrollBar, nPosition);
}

// 0x004FC760
int __fastcall D2Win_10203_TEXTBOX(D2WinTextBoxStrc* pTextBox)
{
    D2_ASSERT(pTextBox, 0x5BE);
    D2_ASSERT(pTextBox->controlHeader.eType == D2WIN_TEXTBOX, 0x5BF);

    return D2Win_10201(pTextBox->pScrollBar);
}

static inline int sub_B03_AddLineRecord(D2WinTextBoxStrc* pTextBox, const Unicode* pText, int nColor, char bIsWrapped, int nIndent)
{
    D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), ".\\Src\\D2WinTextBox.cpp", 0x15D, 0);
    Unicode* pDest;
    if (nIndent == 2)
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 6), ".\\Src\\D2WinTextBox.cpp", 0x161, 0);
        pLine->pColumns[0][4].wChar = 0x20;
        pLine->pColumns[0][3].wChar = pLine->pColumns[0][4].wChar;
        pLine->pColumns[0][2].wChar = pLine->pColumns[0][3].wChar;
        pLine->pColumns[0][1].wChar = pLine->pColumns[0][2].wChar;
        pLine->pColumns[0][0].wChar = pLine->pColumns[0][1].wChar;
        pDest = pLine->pColumns[0] + 5;
    }
    else
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 1), ".\\Src\\D2WinTextBox.cpp", 0x167, 0);
        pDest = pLine->pColumns[0];
    }
    sub_005267E0(pDest, pText);

    pLine->pColumns[1] = 0;
    pLine->pColumns[2] = 0;
    pLine->pColumns[3] = 0;
    pLine->pColumns[4] = 0;
    pLine->nColor = nColor;
    pLine->bWrappedSegment = bIsWrapped;
    pLine->pNext = 0;

    int bScrolled = 0;
    if (!pTextBox->pFirstLine)
    {
        ++pTextBox->nNumLines;
        pTextBox->pFirstLine = pLine;
        pTextBox->pLastLine = pLine;
        pTextBox->pCurrentLine = pLine;
    }
    else
    {
        pTextBox->pLastLine->pNext = pLine;
        ++pTextBox->nNumLines;
        pTextBox->pLastLine = pLine;

        const int nVisible = D2Win_10055(pTextBox);
        if (TEXTBOX_CountLinesFromCurrent(pTextBox) > nVisible)
        {
            D2WinScrollBarStrc* pScrollBar = pTextBox->pScrollBar;
            if (!pScrollBar || SCROLLBAR_GetMaxSteps(pScrollBar) == SCROLLBAR_GetCurrentStep(pScrollBar))
            {
                bScrolled = 1;
                pTextBox->pCurrentLine = pTextBox->pCurrentLine->pNext;
                ++pTextBox->nLine;
            }
        }
    }

    if (pTextBox->pScrollBar)
    {
        const int nStep = SCROLLBAR_GetCurrentStep(pTextBox->pScrollBar);
        SCROLLBAR_SetMaxSteps(pTextBox->pScrollBar, pTextBox->nNumLines - D2Win_10055(pTextBox));
        if (bScrolled)
            SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, pTextBox->nLine);
        else
            SCROLLBAR_SetCurrentStep(pTextBox->pScrollBar, nStep);
    }

    return 1;
}

// 0x004FC7A0
D2WinTextBoxStrc* __fastcall D2Win_10042_TEXTBOX_Create(int nX, int nY, int nWidth, int nHeight, int nInsetX, int nInsetY, D2CelFileStrc* pCellFile, int (__stdcall* pfCallback)(SMSGHANDLER_PARAMS*), unsigned int dwTextBoxFlags, int* pFontInfo, int* pScrollBarRect)
{
    D2WinTextBoxStrc* pTextBox = (D2WinTextBoxStrc*)FOG_Alloc(0xAC, ".\\Src\\D2WinTextBox.cpp", 0x63, 0);
    memset(pTextBox, 0, 0xAC);

    if ((dwTextBoxFlags & 4) && !pScrollBarRect)
    {
        nWidth -= 0x1A;
    }
    if (dwTextBoxFlags & 1)
    {
        dwTextBoxFlags |= 0x20;
    }

    pTextBox->controlHeader.eType = 4;
    pTextBox->controlHeader.dwFlags |= gdwBitMasks_006CE268[0];
    pTextBox->controlHeader.dwFlags |= gdwBitMasks_006CE268[2];
    pTextBox->controlHeader.pCellFile = pCellFile;
    pTextBox->controlHeader.nImageX = nX;
    pTextBox->controlHeader.nImageY = nY;
    pTextBox->controlHeader.nWidth = nWidth;
    pTextBox->controlHeader.nHeight = nHeight;
    pTextBox->dwTextBoxFlags = dwTextBoxFlags;
    pTextBox->nTextInsetX = nInsetX;
    pTextBox->nTextInsetY = nInsetY;
    pTextBox->controlHeader.pfDraw = (D2WinControlFn)TEXTBOX_Draw;
    pTextBox->controlHeader.pfHandleMouseDown = TEXTBOX_HandleMouseDown;
    pTextBox->controlHeader.pfHandleMouseUp = 0;
    pTextBox->controlHeader.pfHandleCharInput = 0;
    const bool bVirtualKey = (dwTextBoxFlags & 1) != 0;
    pTextBox->controlHeader.pfHandleVirtualKeyInput = bVirtualKey ? TEXTBOX_HandleVirtualKeyInput : 0;
    pTextBox->controlHeader.field_34 = pfCallback;
    pTextBox->nCurrentLine = -1;
    pTextBox->controlHeader.pNext = 0;
    pTextBox->pCurrentLine = 0;
    pTextBox->pFirstLine = 0;
    pTextBox->pLastLine = 0;
    pTextBox->nNumLines = 0;
    pTextBox->nLine = 0;
    pTextBox->nNumColumns = 1;

    if (pFontInfo)
    {
        pTextBox->eFont = pFontInfo[0];
        pTextBox->unk0x98 = pFontInfo[1];
    }
    else
    {
        pTextBox->eFont = 1;
        pTextBox->unk0x98 = 0;
    }

    TEXTBOX_SetLineGapForFont(pTextBox->eFont);
    pTextBox->nLineSpacing = gnTextBoxLineGap;

    if (dwTextBoxFlags & 4)
    {
        pTextBox->controlHeader.pCellFile = 0;
        int nScrollX;
        if (pScrollBarRect)
        {
            nScrollX = pScrollBarRect[0];
            nY = pScrollBarRect[1];
            nHeight = pScrollBarRect[2];
        }
        else
        {
            nScrollX = nX + nWidth + 8;
            nY -= 2;
            nHeight -= 0x10;
        }
        pTextBox->pScrollBar = SCROLLBAR_Create(nScrollX, nY, 10, nHeight, pCellFile, 0);
        SCROLLBAR_SetTextBox(pTextBox->pScrollBar, pTextBox);
        int nPosition = D2Win_10055(pTextBox) - 1;
        if (nPosition <= 0)
        {
            nPosition = 1;
        }
        D2Win_10202(pTextBox->pScrollBar, nPosition);
    }
    else
    {
        pTextBox->pScrollBar = 0;
    }

    CONTROL_AppendToList(pTextBox);
    return pTextBox;
}

// 0x004FC960
int __fastcall D2Win_10043_TEXTBOX_Destroy(D2WinTextBoxStrc* ptTextData)
{
    D2_ASSERT(ptTextData, 0xCB);
    D2_ASSERT(ptTextData->controlHeader.eType == D2WIN_TEXTBOX, 0xCC);
    if (ptTextData->pScrollBar)
        SCROLLBAR_Destroy(ptTextData->pScrollBar);
    sub_004FB6A0_ClearText(&ptTextData->controlHeader);
    return CONTROL_RemoveFromList(&ptTextData->controlHeader);
}

// 0x004FC9B0
int __fastcall D2Win_10051(D2WinTextBoxStrc* ptTextData, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent)
{
    D2_ASSERT(ptTextData, 0x132);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x133);

    Unicode wszBuffer[0x400];
    sub_005267E0(wszBuffer, wszText);

    const Unicode* pText = wszBuffer;
    while (pText->wChar)
    {
        if (pText->wChar >= 0x100 || !isspace(pText->wChar))
            break;

        ++pText;
    }

    D2Win_10127_SetFont(ptTextData->eFont);

    if (!(ptTextData->dwTextBoxFlags & 0x20))
    {
        int nMaxWidth = ptTextData->controlHeader.nWidth - 2 * ptTextData->nTextInsetX;
        if (nIndent == 2)
        {
            Unicode wszSpaces[6];
            wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
            wszSpaces[5].wChar = 0;
            nMaxWidth -= D2Win_10121_GetTextWidth(wszSpaces);
        }

        if (D2Win_10122(pText, 0xFF) >= nMaxWidth)
            return TEXTBOX_AddWrappedText(ptTextData, pText, nColor, nIndent);
    }

    D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), gszD2WinTextBoxCpp, 0x15D, 0);
    if (nIndent == 2)
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 6), gszD2WinTextBoxCpp, 0x161, 0);
        pLine->pColumns[0][4].wChar = 0x20;
        pLine->pColumns[0][3].wChar = pLine->pColumns[0][4].wChar;
        pLine->pColumns[0][2].wChar = pLine->pColumns[0][3].wChar;
        pLine->pColumns[0][1].wChar = pLine->pColumns[0][2].wChar;
        pLine->pColumns[0][0].wChar = pLine->pColumns[0][1].wChar;
        sub_005267E0(pLine->pColumns[0] + 5, pText);
    }
    else
    {
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(sizeof(Unicode) * (sub_00526800(pText) + 1), gszD2WinTextBoxCpp, 0x167, 0);
        sub_005267E0(pLine->pColumns[0], pText);
    }

    pLine->pColumns[1] = 0;
    pLine->pColumns[2] = 0;
    pLine->pColumns[3] = 0;
    pLine->pColumns[4] = 0;
    pLine->nColor = nColor;
    pLine->bWrappedSegment = bIsWrapped;
    pLine->pNext = 0;
    int bScrolled = 0;

    if (!ptTextData->pFirstLine)
    {
        ++ptTextData->nNumLines;
        ptTextData->pFirstLine = pLine;
        ptTextData->pLastLine = pLine;
        ptTextData->pCurrentLine = pLine;
    }
    else
    {
        ptTextData->pLastLine->pNext = pLine;
        ++ptTextData->nNumLines;
        ptTextData->pLastLine = pLine;

        const int nVisible = D2Win_10055(ptTextData);
        if (TEXTBOX_CountLinesFromCurrent(ptTextData) > nVisible)
        {
            D2WinScrollBarStrc* pScrollBar = ptTextData->pScrollBar;
            if (!pScrollBar || SCROLLBAR_GetScrollBarField4C(pScrollBar) == SCROLLBAR_GetScrollBarField48(ptTextData->pScrollBar))
            {
                bScrolled = 1;
                ptTextData->pCurrentLine = ptTextData->pCurrentLine->pNext;
                ++ptTextData->nLine;
            }
        }
    }

    if (ptTextData->pScrollBar)
    {
        const int nStep = SCROLLBAR_GetScrollBarField4C(ptTextData->pScrollBar);
        SCROLLBAR_SetMaxSteps(ptTextData->pScrollBar, ptTextData->nNumLines - D2Win_10055(ptTextData));
        if (bScrolled)
            SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, ptTextData->nLine);
        else
            SCROLLBAR_SetCurrentStep(ptTextData->pScrollBar, nStep);
    }

    return 1;
}

// 0x004FCC40
int __fastcall D2Win_10198(D2WinTextBoxStrc* ptTextData, const Unicode* pText, int nCount, int nValue, char nFlag)
{
    D2_ASSERT(ptTextData, 0x1A7);
    D2_ASSERT(ptTextData->controlHeader.eType == 4, 0x1A8);

    const int nSize = sizeof(Unicode) * (sub_00526800(pText) + 1);
    for (int i = 0; i < nCount; ++i)
    {
        D2WinTextBoxLineStrc* pLine = (D2WinTextBoxLineStrc*)FOG_Alloc(sizeof(D2WinTextBoxLineStrc), ".\\Src\\D2WinTextBox.cpp", 0x1AF, 0);
        pLine->pColumns[0] = (Unicode*)FOG_Alloc(nSize, ".\\Src\\D2WinTextBox.cpp", 0x1B0, 0);
        sub_005267E0(pLine->pColumns[0], pText);
        for (int j = 1; j < 5; ++j)
        {
            pLine->pColumns[j] = 0;
        }

        pLine->nColor = nValue;
        pLine->bWrappedSegment = nFlag;
        pLine->pNext = 0;

        if (!ptTextData->pFirstLine)
        {
            ptTextData->pFirstLine = pLine;
        }
        else
        {
            ptTextData->pLastLine->pNext = pLine;
        }

        ptTextData->pLastLine = pLine;
        ++ptTextData->nNumLines;
    }

    if (ptTextData->pScrollBar)
    {
        SCROLLBAR_SetMaxSteps(ptTextData->pScrollBar, ptTextData->nNumLines - D2Win_10055(ptTextData));
    }

    return 1;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004FCD40
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int nLineNum, int nColumn)
{
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    return D2Win_10058_0(pControl, wszText, nLineNum, nColumn);
}

// 0x004FCD90
int __fastcall D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int nLineNum, int nColumn)
{
    return D2Win_10058_0(pControl, pText, nLineNum, nColumn);
}

// 0x004FCDA0
int __fastcall TEXTBOX_AddWrappedText(D2WinTextBoxStrc* pTextBox, const Unicode* wszText, int nColor, int nIndent)
{
    D2_ASSERT(pTextBox, 0x482);
    D2_ASSERT(pTextBox->controlHeader.eType == 4, 0x483);

    int nMaxWidth = pTextBox->controlHeader.nWidth - 2 * pTextBox->nTextInsetX;
    if (nIndent == 2)
    {
        Unicode wszSpaces[6];
        wszSpaces[0].wChar = wszSpaces[1].wChar = wszSpaces[2].wChar = wszSpaces[3].wChar = wszSpaces[4].wChar = 0x20;
        wszSpaces[5].wChar = 0;
        nMaxWidth -= D2Win_10121_GetTextWidth(wszSpaces);
    }

    Unicode* pBuffer = (Unicode*)SMemAlloc(0x800, gszD2WinTextBoxCpp, 0x497, 0);
    Unicode* pText = pBuffer;
    sub_005267E0(pText, wszText);

    int nSplit = 0;
    const int nLength = sub_00526800(pText);
    Unicode* pChar = pText;
    Unicode* pSpace = 0;
    while (nSplit < nLength)
    {
        if (pChar->wChar == 0x20)
            pSpace = pChar;

        const int nNext = nSplit + 1;
        if (D2Win_10122(wszText, nNext) >= nMaxWidth)
        {
            if (pSpace)
            {
                nSplit = pSpace - pText;
                pChar = pSpace;
            }
            break;
        }

        ++pChar;
        ++nSplit;
    }

    Unicode* pFirst = (Unicode*)SMemAlloc(0x800, gszD2WinTextBoxCpp, 0x4B7, 0);
    pText = (Unicode*)SMemAlloc(0x800, gszD2WinTextBoxCpp, 0x4B8, 0);
    sub_00526790(pFirst, pBuffer, nSplit);
    pFirst[nSplit].wChar = 0;
    sub_00526790(pText, pChar, nLength - nSplit);
    pText[nLength - nSplit].wChar = 0;
    SMemFree(pBuffer, gszD2WinTextBoxCpp, 0x4BF, 0);

    D2Win_10051(pTextBox, pFirst, nColor, 1, nIndent);
    D2Win_10051(pTextBox, pText, nColor, 0, nIndent == 1 ? 2 : nIndent);

    SMemFree(pFirst, gszD2WinTextBoxCpp, 0x4C4, 0);
    SMemFree(pText, gszD2WinTextBoxCpp, 0x4C5, 0);
    return 1;
}

// 0x004FCF80
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText)
{
    D2_ASSERT(pControl, 0x109);
    Unicode wszText[1024];
    sub_00526F20_ToUnicode(wszText, szText, 1024);
    sub_004FC9B0_SetText(pControl, wszText, 4, 0, 0);
}

// 0x004FCFF0
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nColor)
{
    Unicode wszText[1024];
    for (int i = 0; i < 1024; ++i)
        wszText[i].wChar = 0;

    D2_ASSERT(pTextBox, 0x11E);
    sub_00526E40_Utf8ToUnicode(wszText, szText, 1024);
    sub_004FC9B0_SetText(pTextBox, wszText, nColor, 0, 0);
}

// 0x004FD060
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText)
{
    sub_004FC9B0_SetText(pControl, pText, 4, 0, 0);
}

// build: symbol ?IMAGE_DrawTiled@* 0x004FD340

// 0x004FFE10
int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText)
{
    Unicode wszText[256];
    sub_00526F20_ToUnicode(wszText, szText, 256);
    return EDITBOX_SetText(pControl, wszText);
}

#include "gen/data/Source/D2Win/Src/D2WinTextBox.inc"
