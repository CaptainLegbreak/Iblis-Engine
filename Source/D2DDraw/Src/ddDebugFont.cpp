#include "D2DDraw.h"
#include "D2DDrawTypes.h"
#include "D2GlideTypes.h"
#include "D2DrlgMaps.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2LevelTxt.h"

#include "D2ClientMenus.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "StormApi.h"
#include "D2WinApi.h"

struct D2PlayerDataStrc;

struct D2TextHeaderStrc;
enum
{
    NUM_HOTKEYS = 114,
};

typedef void (__cdecl* D2WheelCallbackFn)();

typedef int (__stdcall* D2FarProcFn)();



extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn);                              // 0x006CC34C

void __fastcall DLIGHTMAP_ReleaseLight(void* pResource);                                       // 0x004743D0

void __cdecl TEXT_ResetTextBox();                                                                   // 0x0049F960



int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern D2WheelCallbackFn gpfnWheelUp;                                                              // 0x007A7404

extern D2WheelCallbackFn gpfnWheelDown;                                                            // 0x007A7408

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS];                                                        // 0x007A6F90

extern D2UnitStrc* gapAiTargets[];                                                                  // 0x007A7470

extern unsigned char gabColors_007BCAD8[5];                                                                 // 0x007BCAD8

extern int gnInvPanelMode;                                                                              // 0x007BCBF0

extern int gbGoldButtonDisabled;                                                                               // 0x007BCE2C

extern int gnDialogState;                                                                               // 0x00721E34

extern int gnHoverTopX;                                                                               // 0x00721E3C

extern int gnHoverTopY;                                                                               // 0x00721E40

extern int gnHoverBottomX;                                                                               // 0x00721E44

extern int gnHoverBottomY;                                                                               // 0x00721E48

extern int gnHoverCellX;                                                                               // 0x00721E4C

extern int gnHoverCellY;                                                                               // 0x00721E50

extern int gbHoverInGrid;                                                                              // 0x007BCBE4

extern int gbHoverInBodyLoc;                                                                              // 0x007BCBE8

extern int gpHoverItem;                                                                              // 0x007BCBF4

extern int gpLastHoverItem;                                                                              // 0x007BCBF8

extern int gbTextPanelOpen;                                                                               // 0x007BF1FA

extern D2TextHeaderStrc* gpTextHeader;                                                             // 0x007BF250

extern int gnTradeState;                                                                               // 0x007C0E7C

unsigned char* gpDDrawDebugFontGlyphs;                                                             // 0x008815AC

extern void* gpReply;                                                                              // 0x008818D0

extern "C" void* gpGidFileData;                                                                    // 0x00882744

extern "C" void* gpClhFileData;                                                                    // 0x00882750

extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090

extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4

extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho); // 0x006CC0D4

extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534

extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hdc, int x, int y); // 0x006CC0B8

extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C

extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern int gaDDrawDebugFontCharWidths[96]; // 0x00881428

extern int gaDDrawDebugFontGlyphOffsets[96]; // 0x008812A8

extern unsigned long gdwDDrawDebugFontBkColor; // 0x008815A8

extern unsigned long gdwDDrawDebugFontTextColor; // 0x0072F7F0

extern "C" const char gszCourier[]; // 0x006DD52C

extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName); // 0x006CC0E0

extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hdc, unsigned int iFirst, unsigned int iLast, int* lpBuffer); // 0x006CC0D0

extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0

extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC

// 0x005125B0
void __cdecl DDDEBUGFONT_FreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs)
    {
        FOG_Free(gpDDrawDebugFontGlyphs, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs = 0;
    }
}

// 0x00512430
void __cdecl DDDEBUGFONT_CreateDebugFont()
{
    void* hDC = CreateDCA("DISPLAY", 0, 0, 0);
    void* hFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier);
    void* hBitmap = CreateBitmap(8, 16, 1, 8, 0);
    SelectObject(hDC, hFont);
    SelectObject(hDC, hBitmap);
    SetTextColor(hDC, gdwDDrawDebugFontTextColor);
    SetBkColor(hDC, gdwDDrawDebugFontBkColor);
    SetBkMode(hDC, 2);
    tagRECT rect;
    SetRect(&rect, 0, 0, 8, 16);
    gpDDrawDebugFontGlyphs = (unsigned char*)FOG_Alloc(0x3000, ".\\Src\\ddDebugFont.cpp", 0x3A, 0);
    unsigned char* pMask = gpDDrawDebugFontGlyphs;
    int nOffset = 0;
    for (int nChar = 0x20; nChar <= 0x7F; ++nChar)
    {
        char cChar = nChar;
        DrawTextA(hDC, &cChar, 1, &rect, 0);
        for (int y = 0; y < 16; ++y)
        {
            for (int x = 0; x < 8; ++x)
            {
                if (GetPixel(hDC, x, y) == gdwDDrawDebugFontTextColor)
                    *pMask++ = 0xFF;
                else
                    *pMask++ = 0;
            }
        }
        gaDDrawDebugFontGlyphOffsets[nChar - 0x20] = nOffset;
        nOffset += 0x80;
    }
    GetCharWidthA(hDC, 0x20, 0x7F, gaDDrawDebugFontCharWidths);
    DeleteObject(hBitmap);
    DeleteObject(hFont);
    DeleteDC(hDC);
}

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
int gaDDrawDebugFontCharWidths[96]; // 0x00881428

// 0x005125E0
static int __stdcall DDDEBUGFONT_DebugDrawChar(int nY, int nX, char ch)
{
    if (nX > 640)
        return 0;

    if (nX < 0)
        return gaDDrawDebugFontCharWidths[ch];

    const unsigned char n = ch - 0x20;
    if (n <= 0x5F)
    {
        const unsigned char* pBits = gpDDrawDebugFontGlyphs + gaDDrawDebugFontGlyphOffsets[(char)n];
// build: symbol ?gnRenderWidth@* 0x007C9138
        unsigned char* pDst = gpScreenBuffer_007C9154 + gnRenderWidth * nY + nX;
        for (int nRow = 16; nRow; --nRow)
        {
            for (int nCol = 8; nCol; --nCol)
            {
                if (*pBits++)
                    *pDst = 0xFF;
                ++pDst;
            }
            pDst += gnRenderWidth - 8;
        }
        return gaDDrawDebugFontCharWidths[(char)n];
    }

    return gaDDrawDebugFontCharWidths[0];
}

// 0x00512680
void __fastcall DDDEBUGFONT_DebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    char szText[0x200];
    const int nLength = wvsprintfA(szText, szFormat, args);
    const int nStartX = nX;

    for (int i = 0; i < nLength; ++i)
    {
        nX += DDDEBUGFONT_DebugDrawChar(nY, nX, szText[i]);
        if (szText[i] == '\n')
        {
            nX = nStartX;
            nY += 0x0C;
        }
    }
}
