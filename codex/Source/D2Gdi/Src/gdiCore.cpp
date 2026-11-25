#include "D2Gdi.h"

#include "D2SysTypes.h"

#include "D2Win32Base.h"

#include "D2GfxTypes.h"
#include "D2CelContext.h"
#include "D2Win32RgbQuad.h"

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern void* gpArg1_007C9148; // 0x007C9148

extern void* gpArg2_007C914C; // 0x007C914C

extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection);

struct D2Callbacks006C7CF0Strc;

struct D2CriticalSectionStrc;


struct D2RgbQuad006C7FA0Strc;

struct D2Callbacks006C7CF0Strc
{
    void (__fastcall* pfnCallback00)(int a, int b, int c, int d);
};

extern void* ghObject_0098A164; // 0x0098A164

extern D2Callbacks006C7CF0Strc* gpCallbacks_007C914C; // 0x007C914C

void __fastcall sub_006C9280_Apply(int enabled, unsigned char unusedRegister, int unusedA, int unusedB); // 0x006C9280


extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hDC);

extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hDC, void* hObject);

extern "C" __declspec(dllimport) unsigned int __stdcall SetDIBColorTable(void* hDC, unsigned int nStart, unsigned int nCount, const D2RgbQuad006C7FA0Strc* pColors);

extern "C" __declspec(dllimport) void* __stdcall SelectPalette(void* hDC, void* hPalette, int bForceBackground);

extern "C" __declspec(dllimport) unsigned int __stdcall RealizePalette(void* hDC);

extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* pRect);

extern "C" __declspec(dllimport) int __stdcall StretchBlt(void* hDest, int nX, int nY, int nWidth, int nHeight, void* hSrc, int nSrcX, int nSrcY, int nSrcWidth, int nSrcHeight, unsigned long nRop);

extern "C" __declspec(dllimport) int __stdcall GdiFlush();

extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hDC);

void* __stdcall WINDOW_GetWindow(); // 0x004F59A0

extern int gnRenderHeight; // 0x007C913C


extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern const char gszEmptyAssertText; // 0x006CC837

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd); // 0x006CC44C

extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC); // 0x006CC448

static void GDICORE_CreateBackBuffer(int nResolution); // 0x006C7B00

extern "C" __declspec(dllimport) void* __stdcall CreatePalette(const D2LogPalette006C7C10Strc* pLogPalette);

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho);

extern D2PaletteEntry006C7C10Strc gaPalette_007C8CC8[256]; // 0x007C8CC8

void* gpSurfaceBits; // 0x007C9154

void* ghBufferBitmap; // 0x0098A164

void* ghPalette; // 0x0098A160

void __cdecl GDICORE_DeleteGraphicObject();                                                                    // 0x006C8960

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern int gnValue_007C9144;                                                                                        // 0x007C9144

extern "C" __declspec(dllimport) unsigned int __stdcall SetPaletteEntries(void* hPalette, unsigned int nStart, unsigned int nEntries, const D2PaletteEntry006C7C10Strc* pEntries);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern D2RgbQuad006C7FA0Strc gatGdiColors[256];                                                                // 0x00989C40

extern void* ghRenderWindow; // 0x007C9140

extern D2PaletteTableStrc gtPaletteView; // 0x0098A040

void __fastcall GDICORE_SetPaletteView(const D2PaletteTableStrc* source); // 0x006C8000

void __cdecl GDICORE_SetGlobalScale(); // 0x006C8030

void __cdecl GDICORE_SetGamma(); // 0x006C8040

void __cdecl GDICORE_UpdatePerspective(); // 0x006C8070

void __stdcall GDICORE_PerspectiveTransform(int unused1, int unused2, int unused3); // 0x006C8080

void __stdcall GDICORE_PerspectiveTransformScale(int unused1, int unused2, int unused3, int unused4); // 0x006C8090

void __cdecl GDICORE_PerspectiveClearScale(); // 0x006C80A0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }


extern int gnValue_007C913C; // 0x007C913C

extern int gnValue_007C9138; // 0x007C9138

struct D2CelStrc;

int __stdcall CelGetWidth(D2CelStrc* pCel);                                                                 // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel);                                                                // 0x006018F0

int __stdcall CelGetOffsetX(D2CelStrc* pCel);                                                               // 0x00601920

int __stdcall CelGetOffsetY(D2CelStrc* pCel);                                                               // 0x00601950

int __fastcall GDICORE_GetSetting(unsigned int nSelector, int* pValue); // 0x006C8250

extern D2PaletteTableStrc* gpGfxPaletteView;                                                               // 0x007C9150

void __stdcall CelDrawEx(D2CelContextStrc* pContext, int nX, int nY, int nOriginX, int nModeWidth, unsigned char* pBuffer, int nHeight, int nWidth, int nArg9, unsigned char* pCaps, int nSkipTop, int nDrawHeight, int nArg13); // 0x00601650

void __stdcall CelDrawShadow(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, unsigned char* pShadowTable, int nArg10); // 0x00601730

int __cdecl sub_006C8A50_GetBlendedShadows(); // 0x006C8A50

extern const char gszAssertExpr_006CC837[]; // 0x006CC837

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2CelStrc;
struct D2ClipRectStrc;
struct D2ClipResultStrc;
extern int gnWideWidth_0098A16C; // 0x0098A16C
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
extern int gnRenderHeight; // 0x007C913C

struct D2ClipRectStrc { int left, right, top, bottom; };

struct D2ClipResultStrc { int left, right, skipRows, rowCount; };
extern const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
__declspec(noreturn) void __cdecl exit(int code); // 0x00681E09

int __fastcall GDICORE_GetSetting(unsigned int nSelector, int* pValue); // 0x006C8250
extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150
int __stdcall CmpDoLensEffect(unsigned char* pPixel, int nStride); // 0x00608C00
int __fastcall GDICORE_DrawImage(void* context, int second, int third, int fourth, int fifth, int last); // 0x006C84B0
extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int height, int width, int escapement, int orientation, int weight, unsigned long italic, unsigned long underline, unsigned long strikeout, unsigned long charset, unsigned long outPrecision, unsigned long clipPrecision, unsigned long quality, unsigned long pitchAndFamily, const char* face); // 0x006CC0E0
extern const char gszCourier[]; // 0x006DD52C
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* object); // 0x006CC0D4
extern void* ghGdiDebugFont; // 0x0098A170

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, char* args); // 0x006CC4AC
extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd); // 0x006CC44C
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC); // 0x006CC448
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hdc); // 0x006CC0A0
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8
void* __cdecl sub_006C8020(); // 0x006C8020
extern unsigned long gdwGdiDebugTextColor; // 0x0074C5C0
extern void* ghGdiDebugFont_0098A170; // 0x0098A170

extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148
void __fastcall sub_006C8A60_Draw(int nX1, int nY1, int nX2, int nY2, unsigned char nColor, int nLevel); // 0x006C8A60

int __fastcall GDICORE_Init(void* pArg1, void* pArg2); // 0x006C7A70
int __cdecl GDICORE_Close(); // 0x006C7AB0
int __fastcall GDICORE_CreateSurface(int nValue, int nArg); // 0x006C7C10
int __cdecl GDICORE_CloseSurface(); // 0x006C7CF0
void __stdcall GDICORE_PauseSurface(int nValue); // 0x006C7D30
int __fastcall GDICORE_LockAndSend(void* pObject, char nKey, int a, int b); // 0x006C7D80
int __cdecl GDICORE_EndDraw(); // 0x006C7DF0
int __cdecl GDICORE_BlitWindow(); // 0x006C7E30
int __fastcall GDICORE_ChangeRes(int nUnused, int nMode); // 0x006C80B0
void __fastcall GDICORE_GetScreenSize(int* width, int* height); // 0x006C7F90
void __fastcall GDICORE_SetPalette(D2PaletteEntry006C7C10Strc* pEntries); // 0x006C7FA0
int __fastcall GDICORE_ForwardDraw(void* context, int second, int third, int fourth, int fifth, int unused, int last); // 0x006C8910
int __fastcall GDICORE_CelDrawColor(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nPalette); // 0x006C85A0
void __fastcall GDICORE_DrawImageRows(D2CelContextStrc* pContext, int nX, int nY, int nSkipTop, int nDrawHeight, int nDrawMode); // 0x006C86A0
void __fastcall GDICORE_DrawShadow(void* pData, int nX, int nY); // 0x006C87E0
void __fastcall GDICORE_DrawCelClipped(D2CelContextStrc* pContext, int nX, int nY, const D2ClipRectStrc* pClip, int nDrawMode); // 0x006C8750
void __fastcall GDICORE_DrawAlpha(int nArg1, int nArg2, int a, int b, int c, unsigned char nAlpha); // 0x006C8C00
void __fastcall GDICORE_GdiDebugPrintf(int nX, int nY, const char* szFormat, char* args); // 0x006C8970
int __fastcall GDICORE_DrawAt(int nX, int nY); // 0x006C88B0
void __cdecl GDICORE_ClearCaches(); // 0x006C7AF0

extern int gpTileDrawFunctions; // 0x007C914C
int __cdecl GDICORE_Detect(); // 0x006C7A60
int __cdecl GDICORE_PlayCutscene(); // 0x006C7CC0
void __stdcall GDICORE_OpenSmackCutscene(int nUnused1); // 0x006C7CD0
int __cdecl GDICORE_CheckCutScene(); // 0x006C7CE0
int __cdecl GDICORE_GammaCanBeControlled(); // 0x006C8050
void __stdcall GDICORE_SetAmbientColor(int nUnused1); // 0x006C8060
int __cdecl GDICORE_ActivateWindow(); // 0x006C80F0
int __cdecl GDICORE_SetOption(); // 0x006C8100
int __cdecl GDICORE_GetCacheResults(); // 0x006C8190
int __cdecl sub_006C8240(); // 0x006C8240
void __stdcall GDICORE_CelDrawHilight(int nUnused1, int nUnused2); // 0x006C88A0
void __stdcall GDICORE_DebugDraw(int nUnused1, int nUnused2); // 0x006C8A40


extern int gnWidth_007C9138; // 0x007C9138
extern unsigned char* gpPixels_007C9154; // 0x007C9154


// 0x006C7EF0
int __fastcall GDICORE_ConvertPalette(unsigned char* buffer)
{
    unsigned char* row = gpPixels_007C9154;
    for (int y = 0; y < gnHeight_007C913C; ++y) {
        unsigned char* source = row;
        unsigned char* destination = buffer;
        for (int x = 0; x < gnWidth_007C9138; ++x) {
            D2RgbQuad006C7FA0Strc* color = &gatGdiColors[*source];
            *destination++ = color->rgbRed;
            *destination++ = color->rgbGreen;
            *destination = color->rgbBlue;
            ++source;
            ++destination;
        }
        row += gnWidth_007C9138;
        buffer += 3 * gnWidth_007C9138;
    }
    return 1;
}

D2RgbQuad006C7FA0Strc gatGdiColors[256]; // 0x00989C40

// 0x006C8110
unsigned char __fastcall GDICORE_FindNearestColor(int nRed, int nBlue, int nGreen)
{
    unsigned char nIndex = 0;
    int nBest = 10000;
    for (int i = 1; i < 256; ++i)
    {
        int nDiff = gatGdiColors[i].rgbRed - nRed;
        if (nDiff < 0)
            nDiff = -nDiff;
        const int nRedDiff = nDiff;
        nDiff = gatGdiColors[i].rgbGreen - nGreen;
        if (nDiff < 0)
            nDiff = -nDiff;
        const int nGreenDiff = nDiff;
        nDiff = gatGdiColors[i].rgbBlue - nBlue;
        if (nDiff < 0)
            nDiff = -nDiff;
        nDiff += nGreenDiff;
        if (nDiff + nRedDiff < nBest)
        {
            nBest = nDiff + nRedDiff;
            nIndex = (unsigned char)i;
        }
    }
    return nIndex;
}

struct D2Callbacks006C7CF0Strc;
struct D2CriticalSectionStrc;
struct D2RgbQuad006C7FA0Strc;

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* hObject);


void __cdecl GDICORE_DeleteGraphicObject(); // 0x006C8960
extern void* ghObject_0098A164; // 0x0098A164
extern D2Callbacks006C7CF0Strc* gpCallbacks_007C914C; // 0x007C914C


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134
extern int gnValue_007C9144; // 0x007C9144
void __fastcall sub_006C9280_Apply(int enabled, unsigned char unusedRegister, int unusedA, int unusedB); // 0x006C9280


extern "C" __declspec(dllimport) void* __stdcall GetDC(void* hWnd);
extern "C" __declspec(dllimport) int __stdcall ReleaseDC(void* hWnd, void* hDC);
extern "C" __declspec(dllimport) void* __stdcall CreateCompatibleDC(void* hDC);
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hDC, void* hObject);
extern "C" __declspec(dllimport) void* __stdcall SelectPalette(void* hDC, void* hPalette, int bForceBackground);
extern "C" __declspec(dllimport) unsigned int __stdcall RealizePalette(void* hDC);
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* pRect);
extern "C" __declspec(dllimport) int __stdcall StretchBlt(void* hDest, int nX, int nY, int nWidth, int nHeight, void* hSrc, int nSrcX, int nSrcY, int nSrcWidth, int nSrcHeight, unsigned long nRop);
extern "C" __declspec(dllimport) int __stdcall GdiFlush();
extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hDC);
void* __stdcall WINDOW_GetWindow(); // 0x004F59A0
extern int gnRenderHeight; // 0x007C913C
extern void* ghPalette; // 0x0098A160


extern "C" __declspec(dllimport) unsigned int __stdcall SetPaletteEntries(void* hPalette, unsigned int nStart, unsigned int nEntries, const D2PaletteEntry006C7C10Strc* pEntries);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern D2RgbQuad006C7FA0Strc gatGdiColors[256]; // 0x00989C40
extern D2PaletteEntry006C7C10Strc gaPalette_007C8CC8[256]; // 0x007C8CC8

extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150



void* ghRenderWindow; // 0x007C9140

D2PaletteTableStrc gtPaletteView; // 0x0098A040

// 0x006C8000
void __fastcall GDICORE_SetPaletteView(const D2PaletteTableStrc* source)
{
    gtPaletteView = *source;
    gpGfxPaletteView_007C9150 = &gtPaletteView;
}

// 0x006C8030
void __cdecl GDICORE_SetGlobalScale()
{
}

// 0x006C8040
void __cdecl GDICORE_SetGamma()
{
}

// 0x006C8070
void __cdecl GDICORE_UpdatePerspective()
{
}

// 0x006C8080
void __stdcall GDICORE_PerspectiveTransform(int unused1, int unused2, int unused3)
{
}

// 0x006C8090
void __stdcall GDICORE_PerspectiveTransformScale(int unused1, int unused2, int unused3, int unused4)
{
}

// 0x006C80A0
void __cdecl GDICORE_PerspectiveClearScale()
{
}

#include "gen/data/Source/D2Gdi/Src/gdiCore.inc"

// 0x006C7A60
int __cdecl GDICORE_Detect()
{
    return 1;
}

// 0x006C7A70
int __fastcall GDICORE_Init(void* pArg1, void* pArg2)
{
    gpArg1_007C9148 = pArg1;
    gpArg2_007C914C = pArg2;
    gpLock_007C9134 = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\gdiCore.cpp", 0x4B, 0);
    InitializeCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006C7AB0
int __cdecl GDICORE_Close()
{
    if (gpLock_007C9134)
    {
        DeleteCriticalSection(gpLock_007C9134);
        FOG_Free(gpLock_007C9134, ".\\Src\\gdiCore.cpp", 0x59, 0);
        gpLock_007C9134 = 0;
    }
    return 1;
}

struct D2PaletteEntry006C7C10Strc;

struct D2LogPalette006C7C10Strc;

// 0x006C7AF0
void __cdecl GDICORE_ClearCaches()
{
}

// 0x006C7B00
static void GDICORE_CreateBackBuffer(int nResolution)
{
    D2_ASSERT(!gpSurfaceBits, 111);

    int nWidth;
    int nHeight;
    switch (nResolution)
    {
    case 0:
        nWidth = 640;
        nHeight = 480;
        break;

    case 3:
        nWidth = 1344;
        nHeight = 700;
        break;

    default:
        nWidth = 800;
        nHeight = 600;
        break;
    }

    gnBufferWidth_007C9138 = nWidth;
    gnBufferHeight_007C913C = nHeight;

    D2BitmapInfoStrc tBitmapInfo;
    memset(&tBitmapInfo, 0, sizeof(tBitmapInfo));
    tBitmapInfo.biSize = 40;
    tBitmapInfo.biWidth = nWidth;
    tBitmapInfo.biHeight = -nHeight;
    tBitmapInfo.biPlanes = 1;
    tBitmapInfo.biBitCount = 8;
    tBitmapInfo.biCompression = 0;

    void* hDC = GetDC(0);
    ghBufferBitmap = CreateDIBSection(hDC, &tBitmapInfo, 0, &gpSurfaceBits, 0, 0);
    ReleaseDC(0, hDC);

    gpBufferFuncs_007C914C->pfnSetBuffer(gpSurfaceBits, gnBufferWidth_007C9138, gnBufferHeight_007C913C, 0);
}

// 0x006C7C10
int __fastcall GDICORE_CreateSurface(int nValue, int nArg)
{
    gnValue_007C9140 = nValue;
    GDICORE_CreateBackBuffer(nArg);
    memset(gaPalette_007C8CC8, 0, sizeof(gaPalette_007C8CC8));
    D2LogPalette006C7C10Strc tLogPalette;
    tLogPalette.palVersion = 0x300;
    tLogPalette.palNumEntries = 0x100;
    memset(tLogPalette.palPalEntry, 0, sizeof(tLogPalette.palPalEntry));
    ghPalette = CreatePalette(&tLogPalette);
    sub_006C8930_Init();
    sub_006C82D0_Apply(nArg);
    return 1;
}

// 0x006C7C90
void __cdecl sub_006C7C90_Release()
{
    DeleteObject(ghObject_0098A164);
    gnValue_007C9154 = 0;
    gpCallbacks_007C914C->pfnCallback00(0, 0, 0, 0);
}

// 0x006C7CC0
int __cdecl GDICORE_PlayCutscene()
{
    return 0;
}

// 0x006C7CD0
void __stdcall GDICORE_OpenSmackCutscene(int nUnused1)
{
}

// 0x006C7CE0
int __cdecl GDICORE_CheckCutScene()
{
    return 0;
}

// 0x006C7CF0
int __cdecl GDICORE_CloseSurface()
{
    GDICORE_DeleteGraphicObject();
    DeleteObject(ghBufferBitmap);
    gpSurfaceBits = 0;
    gpBufferFuncs_007C914C->pfnSetBuffer(0, 0, 0, 0);
    return 1;
}

// 0x006C7D30
void __stdcall GDICORE_PauseSurface(int nValue)
{
    D2_ASSERT(gpLock_007C9134, 0xF9);
    EnterCriticalSection(gpLock_007C9134);
    gnValue_007C9144 = nValue;
    LeaveCriticalSection(gpLock_007C9134);
}

// 0x006C7D80
int __fastcall GDICORE_LockAndSend(void* pObject, char nKey, int a, int b)
{
    if (gnValue_007C9144)
    {
        return 0;
    }
    D2_ASSERT(gpLock_007C9134, 0x10D);
    EnterCriticalSection(gpLock_007C9134);
    if (pObject)
    {
        sub_006C9280_Apply(1, nKey, a, b);
    }
    return 1;
}

// 0x006C7DF0
int __cdecl GDICORE_EndDraw()
{
    D2_ASSERT(gpLock_007C9134, 0x11D);
    LeaveCriticalSection(gpLock_007C9134);
    return 1;
}

// 0x006C7E30
int __cdecl GDICORE_BlitWindow()
{
    void* hDC = GetDC(ghRenderWindow);
    void* hMemoryDC = CreateCompatibleDC(hDC);
    SelectObject(hMemoryDC, ghObject_0098A164);
    SetDIBColorTable(hMemoryDC, 0, 256, gatGdiColors);
    SelectPalette(hDC, ghPalette, 0);
    RealizePalette(hDC);
    tagRECT tRect;
    GetClientRect(WINDOW_GetWindow(), &tRect);
    StretchBlt(hDC, 0, 0, tRect.right - tRect.left, tRect.bottom - tRect.top,
// build: symbol ?gnRenderWidth@* 0x007C9138
        hMemoryDC, 0, 0, gnRenderWidth, gnRenderHeight, 0xCC0020);
    GdiFlush();
    DeleteDC(hMemoryDC);
    ReleaseDC(ghRenderWindow, hDC);
    return 1;
}

// 0x006C7F90
void __fastcall GDICORE_GetScreenSize(int* width, int* height)
{
    *width = gnRenderWidth;
    *height = gnRenderHeight;
}

// 0x006C7FA0
void __fastcall GDICORE_SetPalette(D2PaletteEntry006C7C10Strc* pEntries)
{
    for (int i = 0; i < 256; ++i)
    {
        gatGdiColors[i].rgbRed = pEntries[i].peRed;
        gatGdiColors[i].rgbGreen = pEntries[i].peGreen;
        gatGdiColors[i].rgbBlue = pEntries[i].peBlue;
    }
    SetPaletteEntries(ghPalette, 0, 256, pEntries);
    memcpy(gaPalette_007C8CC8, pEntries, sizeof(gaPalette_007C8CC8));
}

// 0x006C8020
void* __cdecl sub_006C8020()
{
    return ghBufferBitmap;
}

// 0x006C8050
int __cdecl GDICORE_GammaCanBeControlled()
{
    return 0;
}

// 0x006C8060
void __stdcall GDICORE_SetAmbientColor(int nUnused1)
{
}

// 0x006C80B0
int __fastcall GDICORE_ChangeRes(int nUnused, int nMode)
{
    DeleteObject(ghBufferBitmap);
    gpSurfaceBits = 0;
    gpBufferFuncs_007C914C->pfnSetBuffer(0, 0, 0, 0);
    GDICORE_CreateBackBuffer(nMode);
    sub_006C82D0_Apply(nMode);
    return 1;
}

// 0x006C80F0
int __cdecl GDICORE_ActivateWindow()
{
    return 0;
}

// 0x006C8100
int __cdecl GDICORE_SetOption()
{
    return 0;
}

// 0x006C8190
int __cdecl GDICORE_GetCacheResults()
{
    return 0;
}

// 0x006C81A0
void __fastcall GDICORE_GetPalette(void** phPalette, D2RgbQuad006C7FA0Strc** ppEntries)
{
    D2_ASSERT(phPalette, 546);
    D2_ASSERT(ppEntries, 547);
    *phPalette = ghPalette;
    *ppEntries = gatGdiColors;
}

// 0x006C81E0
void __fastcall GDICORE_GetValues(int* pA, int* pB, int* pC)
{
    D2_ASSERT(pA, 0x230);
    D2_ASSERT(pB, 0x231);
    D2_ASSERT(pC, 0x232);
    *pA = gnValue_007C9154;
    *pB = gnValue_007C913C;
    *pC = gnValue_007C9138;
}

// 0x006C8240
int __cdecl sub_006C8240()
{
    return gpTileDrawFunctions;
}

// 0x006C8250
int __fastcall GDICORE_GetSetting(unsigned int nSelector, int* pValue)
{
// build: symbol ?gaSelectorValues@* 0x0074C5A0
    *pValue = gaSelectorValues[nSelector];
    switch (nSelector)
    {
    case 0:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[2];
    case 1:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[1];
    case 2:
        return (int)gpGfxPaletteView_007C9150->pTransPalettes[0];
    case 3:
        return (int)gpGfxPaletteView_007C9150->pScreenPalette;
    case 4:
        return (int)gpGfxPaletteView_007C9150->pLuminancePalette;
    case 6:
        return (int)gpGfxPaletteView_007C9150->pDarkBlendPalette;
    }
    return 0;
}

int gnGdiOriginX; // 0x0098A168

int gnModeWidth; // 0x0098A16C

// 0x006C82D0
void __fastcall GDICORE_SetResolution(int nMode)
{
    if (nMode != 0)
    {
        gnGdiOriginX = 0;
        if (nMode != 3)
            gnModeWidth = 800;
        else
            gnWideWidth_0098A16C = 1344;
    }
    else
    {
        gnGdiOriginX = 0;
        gnModeWidth = 640;
    }
}

// 0x006C8310
static int __stdcall GDICORE_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += CelGetOffsetX(pCel);
// build: symbol ?gnRenderWidth@* 0x007C9138
    if (nX < gnRenderWidth && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
        if (nY >= 0 && nY - nHeight < gnRenderHeight)
            return 0;
    }

    return 1;
}

extern "C" int __stdcall sub_006C8310_EmitCelClip(D2CelStrc* pCel, int nX, int nY)
{
    return GDICORE_IsCelOffScreen(pCel, nX, nY, 0) + 9;
}

static
// 0x006C8380
int __stdcall GDICORE_ClipCel(D2CelStrc* cel, int x, int y, const D2ClipRectStrc* clip, D2ClipResultStrc* result)
{
    int width = CelGetWidth(cel);
    int height = CelGetHeight(cel);
    int left = clip->left > 0 ? clip->left : 0;
    int right = clip->right < gnSurfaceWidth_007C9138 ? clip->right : gnSurfaceWidth_007C9138;
    if (left > right)
        return 1;
    x += CelGetOffsetX(cel);
    if (x >= right || x + width < left)
        return 1;
    int top = clip->top > 0 ? clip->top : 0;
    int bottom = clip->bottom < gnSurfaceHeight_007C913C ? clip->bottom : gnSurfaceHeight_007C913C;
    if (top > bottom)
        return 1;
    y += CelGetOffsetY(cel);
    if (y < top || y - height > bottom)
        return 1;
    result->left = left;
    result->right = right;
    if (y <= bottom)
        result->skipRows = 0;
    else
        result->skipRows = y - bottom - 1;
    if (y - height >= top)
        result->rowCount = height - result->skipRows;
    else
        result->rowCount = y - result->skipRows - top + 1;
    if (result->rowCount <= 0)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 209);
        exit(-1);
    }
    return 0;
}

static inline int __stdcall sub_00511E10_IsCelOffScreen(D2CelStrc* pCel, int nX, int nY, int bCenter)
{
    int nWidth = CelGetWidth(pCel);
    int nHeight = CelGetHeight(pCel);
    if (bCenter)
    {
        nX -= nHeight;
        nWidth += nHeight;
        nHeight >>= 1;
    }

    nX += CelGetOffsetX(pCel);
// build: symbol ?gnRenderWidth@* 0x007C9138
    if (nX < gnRenderWidth && nWidth + nX >= 0)
    {
        nY += CelGetOffsetY(pCel);
        if (nY >= 0 && nY - nHeight < gnRenderHeight)
            return 0;
    }

    return 1;
}

// 0x006C84B0
int __fastcall GDICORE_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    const int nGamma = (unsigned char)dwGamma;
    unsigned char* pGammaTable = 0;
    const int nCaps = GDICORE_GetSetting(nDrawMode, (int*)&dwGamma);
    if (nGamma != 0xFF)
        pGammaTable = gpGfxPaletteView->pShadowLightGammaPalettes[nGamma >> 3];
    if (nDrawMode == 7)
        pGammaTable = gpGfxPaletteView->pRemap;

    CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
        gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPalette);
    return 1;
}

// 0x006C85A0
int __fastcall GDICORE_CelDrawColor(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nPalette)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return 0;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return 0;

    {
        unsigned char* pGammaTable = 0;
        unsigned char* pPaletteTable = 0;
        int nType;
        const int nCaps = GDICORE_GetSetting(nDrawMode, &nType);
        const int nGamma = (unsigned char)dwGamma;
        if (nGamma != 0xFF)
            pGammaTable = gpGfxPaletteView_007C9150->pShadowLightGammaPalettes[nGamma >> 3];
        if (nDrawMode == 7)
            pGammaTable = gpGfxPaletteView_007C9150->pRemap;
        if (nPalette)
            pPaletteTable = gpGfxPaletteView_007C9150->pStandardShiftPalettes[nPalette];

        CelDraw((D2CmpCelContextStrc*)pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
            gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, (int)pGammaTable, nCaps, (int)pPaletteTable);
    }
    return 1;
}

// 0x006C86A0
void __fastcall GDICORE_DrawImageRows(D2CelContextStrc* pContext, int nX, int nY, int nSkipTop, int nDrawHeight, int nDrawMode)
{
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 0))
        return;

    CelDrawEx(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C, gpScreenBuffer_007C9154,
        gnRenderHeight, gnRenderWidth, 0, (unsigned char*)GDICORE_GetSetting(nDrawMode, &nDrawHeight),
        nSkipTop, nDrawHeight, 0);
}

// 0x006C87E0
void __fastcall GDICORE_DrawShadow(void* pData, int nX, int nY)
{
    D2CelContextStrc* pContext = (D2CelContextStrc*)pData;
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (sub_00511E10_IsCelOffScreen(pContext->pCel, nX, nY, 1))
        return;

    unsigned char* pShadowTable = 0;
    if (sub_006C8A50_GetBlendedShadows())
        pShadowTable = gpGfxPaletteView_007C9150->pTransPalettes[0];

    CelDrawShadow(pContext, nX, nY, gnOriginX_0098A168, gnModeWidth_0098A16C,
        gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, pShadowTable, 0);
}

// 0x006C8750
void __fastcall GDICORE_DrawCelClipped(D2CelContextStrc* pContext, int nX, int nY, const D2ClipRectStrc* pClip, int nDrawMode)
{
    D2ClipResultStrc tClip = {};
    if (!sub_006001F0(pContext, 0, 1))
        return;

    if (GDICORE_ClipCel(pContext->pCel, nX, nY, pClip, &tClip))
        return;

    CelDrawEx(pContext, nX, nY, tClip.left, tClip.right, gpScreenBuffer_007C9154, gnRenderHeight, gnRenderWidth, 0,
        (unsigned char*)GDICORE_GetSetting(nDrawMode, (int*)&pClip), tClip.skipRows, tClip.rowCount, 0);
}
// 0x006C88A0
void __stdcall GDICORE_CelDrawHilight(int nUnused1, int nUnused2)
{
}

// 0x006C88B0
int __fastcall GDICORE_DrawAt(int nX, int nY)
{
    D2_ASSERT(nX > 0 && nX < gnStride_007C9138 - 80, 0x1AB);
    D2_ASSERT(nY > 0 && nY < gnHeight_007C913C - 80, 0x1AC);
    return CmpDoLensEffect(gpBuffer_007C9154 + nY * gnStride_007C9138 + nX, gnStride_007C9138);
}

// 0x006C8910
int __fastcall GDICORE_ForwardDraw(void* context, int second, int third, int fourth, int fifth, int unused, int last)
{
    return GDICORE_DrawImage(context, second, third, fourth, fifth, last);
}

void* ghGdiDebugFont; // 0x0098A170

// 0x006C8930
void __cdecl GDICORE_CreateGraphicFont()
{
    ghGdiDebugFont = CreateFontA(10, 0, 0, 0, 400, 0, 0, 0, 0, 0, 0, 0, 1, gszCourier);
}

// 0x006C8960
void __cdecl GDICORE_DeleteGraphicObject()
{
    DeleteObject(ghGdiDebugFont);
}

unsigned long gdwGdiDebugBkColor; // 0x0098A174

// 0x006C8970
void __fastcall GDICORE_GdiDebugPrintf(int nX, int nY, const char* szFormat, char* args)
{
    int anText[0x200 / sizeof(int)];
    wvsprintfA((char*)anText, szFormat, args);
    void* hScreenDC = GetDC(0);
    void* hDC = CreateCompatibleDC(hScreenDC);
    SelectObject(hDC, sub_006C8020());
    SelectObject(hDC, ghGdiDebugFont_0098A170);
    SetTextColor(hDC, gdwGdiDebugTextColor);
    SetBkColor(hDC, gdwGdiDebugBkColor);
    SetBkMode(hDC, 1);
    tagRECT tRect;
    SetRect(&tRect, nX, nY, gnRenderWidth - nX, gnRenderHeight - nY);
    DrawTextA(hDC, (char*)anText, -1, &tRect, 0);
    DeleteDC(hDC);
    ReleaseDC(0, hScreenDC);
}

// 0x006C8A40
void __stdcall GDICORE_DebugDraw(int nUnused1, int nUnused2)
{
}

// 0x006C8C00
void __fastcall GDICORE_DrawAlpha(int nArg1, int nArg2, int a, int b, int c, unsigned char nAlpha)
{
    int nLevel;
    if (nAlpha >= 0xC0)
        nLevel = 5;
    else if (nAlpha >= 0x80)
        nLevel = 2;
    else if (nAlpha >= 0x40)
        nLevel = 1;
    else if (nAlpha > 0)
        nLevel = 0;
    else
        return;
    sub_006C8A60_Draw(nArg1, nArg2, a, b, c, nLevel);
}

