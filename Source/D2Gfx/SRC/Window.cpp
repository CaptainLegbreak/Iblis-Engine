#include "D2Gfx.h"

#include "D2GameTypes.h"

#include "D2GfxTypes.h"
#include "FogApi.h"
#include "FogApi.h"
#include "D2DrlgMaps.h"
#include "D2WinApi.h"
#include "D2HellApi.h"

struct D2TileLibraryBlockStrc
{
    short nPosX;
    short nPosY;
    short nCacheIndex;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned char nFormat;
    unsigned char nFormatHigh;
    unsigned short nLength;
    int nReserved;
    unsigned char* pData;
};

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

extern int gnViewMatrixAdjust; // 0x007C8CC4

int __fastcall WINDOW_SetVideoMode(int nMode); // 0x004F4FF0

union D2LargeIntegerStrc;

struct D2GraphicsInterfaceStrc;

struct D2GfxSettingsStrc;

struct D2PaletteStrc;

struct _AppBarData;

struct D2WindowPlacementStrc;

struct D2DevModeStrc;

extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48

int gbIsWindowed; // 0x007C8CB4

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

void __cdecl WINDOW_HideSystemCursor(); // 0x004F5510

void __cdecl WINDOW_ShowSystemCursor(); // 0x004F5540

double __cdecl D2GFX_GetElapsedMs(); // 0x004F6130

void __fastcall CMNSUBTILE_SetPaletteTables(D2PaletteTableStrc* pPaletteTables); // 0x004F8E40

int gbPaused; // 0x007C933C

enum DisplayType
{
    DISPLAYTYPE_NONE = 0,
    DISPLAYTYPE_GDI = 1,
    DISPLAYTYPE_SOFTWARE = 2,
    DISPLAYTYPE_DDRAW = 3,
    DISPLAYTYPE_GLIDE = 4,
    DISPLAYTYPE_OPENGL = 5,
    DISPLAYTYPE_DIRECT3D = 6,
    DISPLAYTYPE_RAVE = 7,
};

struct D2PaletteStrc
{
    union
    {
        unsigned char colors[256];
        unsigned char remap[256];
    };
};

void __cdecl WINDOW_UpdatePauseState(); // 0x004F5FA0

extern int gbCursorDisplayed; // 0x0072DB38

void* ghWnd; // 0x007C8CBC

int gbWindowState; // 0x007C9340

unsigned char gabLightCube[32][32][32]; // 0x007CA320

D2PaletteStrc gatLightPalettes[49]; // 0x007D2348

int gnScreenPitch; // 0x007D544C

extern D2PaletteTableStrc* gpPaletteTables_007D5578; // 0x007D5578

void __stdcall WINDOW_ShowAll(); // 0x004F5F60

void __stdcall WINDOW_GetResolutionSize(int nResolution, long* pWidth, long* pHeight); // 0x004F5570

int gnResolutionMode; // 0x007C8CB8

struct _AppBarData
{
    unsigned long cbSize;
    void* hWnd;
    unsigned int uCallbackMessage;
    unsigned int uEdge;
    tagRECT rc;
    long lParam;
};

extern "C" __declspec(dllimport) unsigned int __stdcall SHAppBarMessage(unsigned long dwMessage, _AppBarData* pData); // 0x006CC434

extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hWnd, tagRECT* lpRect); // 0x006CC4BC

extern "C" __declspec(dllimport) int __stdcall SystemParametersInfoA(unsigned int uiAction, unsigned int uiParam, void* pvParam, unsigned int fWinIni); // 0x006CC504

extern "C" __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl); // 0x006CC508


int __stdcall WINDOW_Resize(int nResolution, int bForceResize); // 0x004F5AA0

void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0

extern tagRECT gtWindowRect; // 0x007C9160

D2WindowPlacementStrc gWindowPlacement[4]; // 0x007C9278

extern "C" __declspec(dllimport) int __stdcall IsIconic(void* hWnd); // 0x006CC50C

void __cdecl WINDOW_UpdatePlacement(); // 0x004F5EC0

struct D2DevModeStrc
{
    char dmDeviceName[0x20];
    unsigned short dmSpecVersion;
    unsigned short dmDriverVersion;
    unsigned short dmSize;
    unsigned short dmDriverExtra;
    unsigned int dmFields;
    short dmOrientation;
    short dmPaperSize;
    short dmPaperLength;
    short dmPaperWidth;
    short dmScale;
    short dmCopies;
    short dmDefaultSource;
    short dmPrintQuality;
    short dmColor;
    short dmDuplex;
    short dmYResolution;
    short dmTTOption;
    short dmCollate;
    char dmFormName[0x20];
    unsigned short dmLogPixels;
    unsigned int dmBitsPerPel;
    unsigned int dmPelsWidth;
    unsigned int dmPelsHeight;
    unsigned int dmDisplayFlags;
    unsigned int dmDisplayFrequency;
    unsigned int dmICMMethod;
    unsigned int dmICMIntent;
    unsigned int dmMediaType;
    unsigned int dmDitherType;
    unsigned int dmReserved1;
    unsigned int dmReserved2;
    unsigned int dmPanningWidth;
    unsigned int dmPanningHeight;
};


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) unsigned long __stdcall GdiSetBatchLimit(unsigned long dwLimit); // 0x006CC0DC

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494

extern "C" __declspec(dllimport) int __stdcall GetSystemMetrics(int nIndex); // 0x006CC4B8

extern "C" __declspec(dllimport) void* __stdcall SetFocus(void* hWnd); // 0x006CC4E4

extern "C" __declspec(dllimport) int __stdcall UpdateWindow(void* hWnd); // 0x006CC4E8

extern "C" __declspec(dllimport) void* __stdcall CreateWindowExA(unsigned long dwExStyle, const char* szClass, const char* szWindow, unsigned long dwStyle, int nX, int nY, int nWidth, int nHeight, void* hParent, void* hMenu, void* hInstance, void* pParam); // 0x006CC4F0

extern "C" __declspec(dllimport) void* __stdcall FindWindowA(const char* szClass, const char* szWindow); // 0x006CC500

int gnCaptionHeight; // 0x007C9270

extern int gbNoWindowCreated; // 0x007C9338

struct D2CacheStatsStrc;

extern int gfFixedAspectRatio; // 0x0072DA7C

extern int gnDisplayType; // 0x007C8CB0

extern int gnViewMatrixAdjust; // 0x007C8CC4

typedef long (__stdcall* WNDPROC)(void*, unsigned int, unsigned int, long);

extern "C" __declspec(dllimport) void* __stdcall LoadImageA(void*, const char*, unsigned int, int, int, unsigned int); // 0x006CC4D4

extern "C" __declspec(dllimport) void* __stdcall LoadCursorA(void*, const char*); // 0x006CC4D0

extern "C" __declspec(dllimport) void* __stdcall GetStockObject(int); // 0x006CC0E8

extern "C" __declspec(dllimport) unsigned short __stdcall RegisterClassA(const WNDCLASSA*); // 0x006CC4CC

int __fastcall FOG_IsExpansion(); // 0x00408F20

void __cdecl j_D2GFX_10040_ShowAllWindows(); // 0x004F5030

extern "C" int __cdecl atexit(void (__cdecl*)()); // 0x00683824

void __cdecl ERRORMANAGER_RaiseErrorReport(int, const char*, int, const char*, ...); // 0x00408900

extern WNDPROC gpfnGfxWndProc; // 0x007C8CAC

extern const char* gszWindowClassName; // 0x007C9158

extern D2GraphicsInterfaceStrc gtGdiGraphicsInterface; // 0x0074C4A8
extern D2GraphicsInterfaceStrc gtDDrawGraphicsInterface; // 0x0072F6D0
extern D2GraphicsInterfaceStrc gtGlideGraphicsInterface; // 0x0072F178
extern D2GraphicsInterfaceStrc gtD3DGraphicsInterface; // 0x0074BF28

// Static data, indexed by video mode: each entry points to one renderer's interface
// (GDI, DirectDraw, Glide, Direct3D); modes without a renderer are null.
extern D2GraphicsInterfaceStrc* gapGraphicsInterfaces[]; // 0x0072DA80

extern const unsigned char gabGraphicsHelpers[]; // 0x0072DA60


extern const char gszStringFormat[]; // 0x006FFC58

extern const char gszUnsupportedGraphics[]; // 0x0072DAF0

extern const char gszRetryUnsupportedGraphics[]; // 0x0072DAA8

D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0

double gdFrameRemainder; // 0x007C9360

tagPALETTEENTRY gatGfxPalette[256]; // 0x007C9378

int ganRowOffsets[732]; // 0x007C97A8

D2PaletteTableStrc gtPaletteTables; // 0x007D5458

extern const char* gszDefaultClass; // 0x0072DAA0
extern const char* gszDefaultWindow; // 0x0072DB3C
// build: symbol ??__EgszWindowClass@@YAXXZ 0x006CAE00
const char* gszWindowClass = gszDefaultWindow; // 0x007C9344

// build: symbol ??__EgszWindowTitle@@YAXXZ 0x006CAE10
const char* gszWindowTitle = gszDefaultWindow; // 0x007C9348

struct D2TileLibraryBlockStrc;

extern unsigned char* gpScreenBuffer; // 0x007D5448

unsigned char** gpPaletteTables; // 0x007D5578

void __fastcall CMNSUBTILE_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows); // 0x004F7580

static int gnInnerBlockTop; // 0x007C9780

int gnInnerRight; // 0x007C9784

int gnClipBottom; // 0x007C978C

int gnInnerBottom; // 0x007C9790

int gnClipLeft; // 0x007C9794

static int gnInnerBlockBottom; // 0x007C979C

static int gnRowClipBottom; // 0x007C97A0

static int gnInnerBlockLeft; // 0x007C97A4

static int gnColClipLeft; // 0x007CA318

int gnInnerTop; // 0x007CA31C

static int gnInnerBlockRight; // 0x007D2320

int gnClipRight; // 0x007D2324

int gnInnerLeft; // 0x007D2328

int gnClipTop; // 0x007D232C

static int gnRowClipTop; // 0x007D2334

static int gnColClipRight; // 0x007D233C

void __fastcall CMNSUBTILE_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg); // 0x004F7850

static int gnScreen_7C9788; // 0x007C9788

static int gnScreen_7C9798; // 0x007C9798

static int gnScreen_7D2330; // 0x007D2330

static int gnScreen_7D2338; // 0x007D2338

void __fastcall WINDOW_SetPanelCoords(int nWidth, int nHeight); // 0x004F7DA0

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(D2LargeIntegerStrc* pFrequency); // 0x006CC254

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount); // 0x006CC25C

typedef char* va_list;



extern int gnChangedScaleFactor; // 0x0072DB40

static int gnPerspectiveScaleX; // 0x007C977C

static int gnPerspectiveScaleY; // 0x007C9778

extern int ganSubtileRowSrcOffset[]; // 0x0072DBC0

extern int ganSubtileRowWidth[]; // 0x0072DB84

extern int ganSubtileRowXOffset[]; // 0x0072DB48

// 0x004F4FF0
int __fastcall WINDOW_SetVideoMode(int nMode)
{
    if (!gapGraphicsInterfaces[nMode])
    {
        LOGMANAGER_WriteLogLine("Unsupported video mode - %d", nMode);
        return 0;
    }
    gpGraphicsInterface = gapGraphicsInterfaces[nMode];
    return 1;
}

// 0x004F5020
int __stdcall D2GFX_ClearGraphicsInterface()
{
    gpGraphicsInterface = 0;
    return 1;
}

// 0x004F5030
void __cdecl j_D2GFX_10040_ShowAllWindows()
{
    WINDOW_ShowAll();
}

// 0x004F5040
int __stdcall D2GFX_ReturnFalse(int nArg1, int nArg2, int nArg3)
{
    return 0;
}

extern "C" __declspec(dllimport) int __stdcall UnregisterClassA(const char* lpClassName, void* hInstance);   // 0x006CC4C8

void* ghInstance;                                                                                  // 0x007C8CA8

// build: symbol ??__EgszWindowClassName@@YAXXZ 0x006CADF0
const char* gszWindowClassName = gszDefaultClass; // 0x007C9158

int gbNoWindowCreated;                                                                             // 0x007C9338

// 0x004F5050
int __stdcall D2GFX_Release()
{
    gpGraphicsInterface->pfClose();
    UnregisterClassA(gszWindowClassName, ghInstance);

    if (gbNoWindowCreated != 0)
    {
        char szCaption[256];
        char szText[256];
        sprintf(szCaption, "Diablo II Critical Error");
        switch (gnDisplayType)
        {
        case 1:
            sprintf(szText, "Error 21: A critical error has occurred while initializing windowed mode.");
            break;
        case 3:
            sprintf(szText, "Error 22: A critical error has occurred while initializing DirectDraw.");
            break;
        case 4:
            sprintf(szText, "Error 23: A critical error has occurred while initializing Glide.");
            break;
        case 5:
            sprintf(szText, "Error 24: A critical error has occurred while initializing OpenGL.");
            break;
        case 6:
            sprintf(szText, "Error 25: A critical error has occurred while initializing Direct3D.");
            break;
        }
        MessageBoxA(0, szText, szCaption, 0x30);
    }

    gpGraphicsInterface = 0;
    return 1;
}

extern int gnDisplayType; // 0x007C8CB0

extern int gbIsWindowed; // 0x007C8CB4

// 0x004F5140
int __cdecl D2GFX_GetDisplayType()
{
    return gnDisplayType;
}

// 0x004F5150
int __cdecl D2GFX_CheckWindowed()
{
    return gbIsWindowed;
}

// 0x004F5160
int __stdcall D2GFX_GetResolutionMode()
{
    return gnResolutionMode;
}

// 0x004F5170
int __cdecl D2GFX_CheckUnitPerspective()
{
    return gGfxSettings.bPerspectiveCapable;
}

// 0x004F5180
int __cdecl D2GFX_IsFixedAspectRatio()
{
    return gfFixedAspectRatio;
}

// 0x004F5190
void __stdcall D2GFX_SetTownMode(int bTown)
{
    if (gnDisplayType < 4)
        bTown = 0;
    gGfxSettings.bPerspectiveCapable = bTown;
}

// 0x004F51C0
int __cdecl D2GFX_IsHardwareRenderMode()
{
    return gnDisplayType >= 4;
}

// 0x004F51D0
int __stdcall D2GFX_CheckPerspective()
{
    return gGfxSettings.bPerspectiveCapable != 0 ? gGfxSettings.bPerspectiveEnabled : 0;
}

// 0x004F51E0
void __stdcall D2GFX_SetPerspective(int bPerspective)
{
    gGfxSettings.bPerspectiveEnabled = bPerspective;
}

// 0x004F51F0
int __cdecl D2GFX_CheckBlendedShadows()
{
    return gGfxSettings.bBlendedShadows;
}

// 0x004F5200
void __stdcall D2GFX_SetBlendShadows(int bBlendedShadows)
{
    gGfxSettings.bBlendedShadows = bBlendedShadows;
}

// 0x004F5210
int __cdecl D2GFX_CheckLowQuality()
{
    return gGfxSettings.bLowQuality;
}

// 0x004F5220
void __stdcall D2GFX_SetLowQuality(int bLowQuality)
{
    gGfxSettings.bLowQuality = bLowQuality;
}

// 0x004F5230
int __stdcall D2GFX_SetGamma(int nGamma)
{
    if (nGamma)
    {
        gGfxSettings.nGamma = nGamma;
    }

    return gpGraphicsInterface->pfSetGamma(gGfxSettings.nGamma);
}

// 0x004F5260
int __stdcall D2GFX_GammaCanBeControlled()
{
    return gpGraphicsInterface->pfGammaCanBeControlled();
}

// 0x004F5270
void __cdecl D2GFX_EnableVSync()
{
    gGfxSettings.bVSync = 1;
}

// 0x004F5280
void __cdecl D2GFX_DisableFixedAspectRatio()
{
    gfFixedAspectRatio = 0;
}

// 0x004F5290
D2CacheStatsStrc* __cdecl D2GFX_GetCacheResults()
{
    return gpGraphicsInterface->pfGetCacheResults();
}

// 0x004F52A0
void __fastcall D2GFX_SetViewMatrixAdjust(int nOffset)
{
    gnViewMatrixAdjust = nOffset;
}

// 0x004F52B0
int __fastcall D2GFX_SetOption(int nOption, int nValue)
{
    return gpGraphicsInterface->pfSetOption(nOption, nValue);
}

// build: symbol ?$S2@?1??D2GFX_EndScene@@YGHXZ@4IA 0x007C9370
// build: symbol ?sdLastFrame@?1??D2GFX_EndScene@@YGHXZ@4NA 0x007C9368
// 0x004F52C0
void __cdecl sub_004F52C0_Empty()
{
}

// 0x004F52D0
void __cdecl sub_004F52D0_Empty()
{
}

// 0x004F52E0
int __stdcall D2GFX_Initialize(void* hInstance, WNDPROC pfWndProc, int nRenderMode, int bWindowed)
{
// build: symbol ?ghInstance@* 0x007C8CA8
    ghInstance = hInstance;
    gpfnGfxWndProc = pfWndProc;
    WNDCLASSA windowClass;
    windowClass.style = nRenderMode == 5 ? 0x20 : 0;
    windowClass.lpfnWndProc = pfWndProc;
    windowClass.cbClsExtra = 0;
    windowClass.cbWndExtra = 0;
    windowClass.hInstance = hInstance;
    const int nIconId = FOG_IsExpansion() ? 103 : 102;
    windowClass.hIcon = LoadImageA(ghInstance, (const char*)(unsigned short)nIconId, 1, 0, 0, 0);
    windowClass.hCursor = LoadCursorA(0, (const char*)32512);
    windowClass.hbrBackground = GetStockObject(5);
    windowClass.lpszMenuName = 0;
    windowClass.lpszClassName = gszWindowClassName;
    if (!RegisterClassA(&windowClass))
    {
        sub_0051793E_FormatAndRaise(GetLastError());
        return 0;
    }
    sub_004F8DC0_InitLookupTable();
    atexit(j_D2GFX_10040_ShowAllWindows);
    gnDisplayType = nRenderMode;
    gbIsWindowed = bWindowed;
    if (!WINDOW_SetVideoMode(nRenderMode))
    {
        return 0;
    }
    gpGraphicsInterface->pfSetOption(8, bWindowed == 1);
    if (!gpGraphicsInterface->pfDetect(hInstance))
    {
        ERRORMANAGER_RaiseErrorReport(9, 0, 0, gszStringFormat, gszUnsupportedGraphics);
        return 0;
    }
    int bPerspectiveCapable = gGfxSettings.bPerspectiveCapable;
    if (!(gnDisplayType >= 4))
    {
        bPerspectiveCapable = 0;
    }
    gGfxSettings.bPerspectiveCapable = bPerspectiveCapable;
    int result = gpGraphicsInterface->pfInit(&gGfxSettings, gabGraphicsHelpers);
    if (!result)
    {
        if (!gpGraphicsInterface->pfDetect(hInstance))
        {
            ERRORMANAGER_RaiseErrorReport(9, 0, 0, gszStringFormat, gszRetryUnsupportedGraphics);
        }
        else
        {
            result = gpGraphicsInterface->pfInit(&gGfxSettings, gabGraphicsHelpers);
        }
    }
    return result;
}

// 0x004F54B0
int __stdcall D2GFX_TogglePerspective()
{
    gGfxSettings.bPerspectiveEnabled = gGfxSettings.bPerspectiveEnabled == 0;
    return gGfxSettings.bPerspectiveEnabled;
}

// 0x004F54D0
int __stdcall D2GFX_ToggleBlendedShadows()
{
    gGfxSettings.bBlendedShadows = gGfxSettings.bBlendedShadows == 0;
    return gGfxSettings.bBlendedShadows;
}

// 0x004F54F0
int __stdcall D2GFX_ToggleLowQuality()
{
    gGfxSettings.bLowQuality = gGfxSettings.bLowQuality == 0;
    return gGfxSettings.bLowQuality;
}

// 0x004F5510
void __cdecl WINDOW_HideSystemCursor()
{
    if (gbCursorDisplayed)
    {
        while (ShowCursor(0) >= 0);
        gbCursorDisplayed = 0;
    }
}

// 0x004F5540
void __cdecl WINDOW_ShowSystemCursor()
{
    if (!gbCursorDisplayed)
    {
        while (ShowCursor(1) < 0);
        gbCursorDisplayed = 1;
    }
}

// 0x004F5570
void __stdcall WINDOW_GetResolutionSize(int nResolution, long* pWidth, long* pHeight)
{
    switch (nResolution)
    {
    case 0:
        *pWidth = 640;
        *pHeight = 480;
        break;

    case 1:
    case 2:
        *pWidth = 800;
        *pHeight = 600;
        break;

    case 3:
        *pWidth = 1344;
        *pHeight = 700;
        break;

    default:
        *pWidth = 0;
        *pHeight = 0;
        D2_ASSERT(0, 109);
    }
}

// 0x004F5610
int __stdcall WINDOW_Create(int bWindowed, int nResolution)
{
    if (FindWindowA(gszWindowClass, 0))
    {
        char szCaption[256];
        char szText[256];
        sprintf(szCaption, "Diablo II Critical Error");
        sprintf(szText, "Only one copy of Diablo II may run at a time.");
        MessageBoxA(0, szText, szCaption, 0x30);
        return 0;
    }

    D2_ASSERT(gpGraphicsInterface, 0x90);
    D2_ASSERT(!ghWnd, 0x91);
    gbIsWindowed = bWindowed;
    gnResolutionMode = nResolution;
    tagRECT tRect;
    tRect.left = 0;
    tRect.top = 0;
    WINDOW_GetResolutionSize(nResolution, &tRect.right, &tRect.bottom);
    gnCaptionHeight = tRect.bottom;
    unsigned int dwStyle;
    if (gbIsWindowed == 1)
    {
        dwStyle = 0xCB0000;
    }
    else
    {
        dwStyle = 0x80080000;
        if (gnDisplayType == 5)
        {
            dwStyle = 0x86080000;
        }
    }

    AdjustWindowRectEx(&tRect, dwStyle, 0, 0x40000);
    int nWidth = tRect.right - tRect.left;
    int nHeight = tRect.bottom - tRect.top;
    gnCaptionHeight = nHeight - gnCaptionHeight;
    int nY = 0;
    int nX = 0;
    if (gbIsWindowed == 1)
    {
        tagRECT tDesktop;
        GetClientRect(GetDesktopWindow(), &tDesktop);
        nX = (tDesktop.right - nWidth) >> 1;
        if (nX < 0)
        {
            nX = 0;
        }
        nY = (tDesktop.bottom - nHeight) >> 1;
        if (nY < 0)
        {
            nY = 0;
        }
    }
    else if (gnDisplayType == 4)
    {
        nX = 0;
        nY = 0;
        nWidth = GetSystemMetrics(0) > 800 ? GetSystemMetrics(0) : 800;
        nHeight = GetSystemMetrics(1) > 600 ? GetSystemMetrics(1) : 600;
    }

    if (GetSystemMetrics(0) < 800)
    {
        D2DevModeStrc tDevMode;
        memset(&tDevMode, 0, sizeof(tDevMode));
        tDevMode.dmSize = sizeof(tDevMode);
        tDevMode.dmBitsPerPel = 8;
        tDevMode.dmPelsWidth = 800;
        tDevMode.dmPelsHeight = 600;
        tDevMode.dmFields = 0x1C0000;
        ChangeDisplaySettingsA(&tDevMode, 0);
    }

    ghWnd = CreateWindowExA(0x40008, gszWindowClass, gszWindowTitle, dwStyle, nX, nY, nWidth, nHeight, 0, 0, ghInstance, 0);
    if (!ghWnd)
    {
        sub_0051793E_FormatAndRaise(GetLastError());
        return 0;
    }

    ShowWindow(ghWnd, 1);
    UpdateWindow(ghWnd);
    SetFocus(ghWnd);
    GdiSetBatchLimit(1);
    WINDOW_HideSystemCursor();
    const int bResult = gpGraphicsInterface->pfCreateSurface(ghWnd, gnResolutionMode);
    if (!bResult)
    {
        gbNoWindowCreated = 1;
        WINDOW_ShowSystemCursor();
        if (ghWnd)
        {
            DestroyWindow(ghWnd);
            ghWnd = 0;
        }
    }

    WINDOW_LoadGammaSettings();
    SetWindowPos(ghWnd, (void*)-2, 0, 0, nWidth, nHeight, 2);
    return bResult;
}

// 0x004F5900
int __stdcall WINDOW_Destroy()
{
    int bWindowDestroyed = 1;
    D2_ASSERT(gpGraphicsInterface, 0x12C);

    if (!gbCursorDisplayed)
    {
        while (ShowCursor(1) < 0);
        gbCursorDisplayed = 1;
    }

    if (!gpGraphicsInterface->pfCloseSurface())
    {
        bWindowDestroyed = 0;
    }

    if (ghWnd)
    {
        if (!DestroyWindow(ghWnd))
        {
            bWindowDestroyed = 0;
        }
        ghWnd = 0;
    }

    ChangeDisplaySettingsA(0, 0);
    return bWindowDestroyed;
}

// 0x004F5990
void __stdcall WINDOW_SetPaused(int bPaused)
{
    gbPaused = bPaused;
}

extern int gdwGlobal_007C8CBC; // 0x007C8CBC

// 0x004F59A0
int __cdecl WINDOW_GetWindow()
{
    return gdwGlobal_007C8CBC;
}

// 0x004F59B0
int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight)
{
    D2_ASSERT(gpGraphicsInterface, 423);

    return gpGraphicsInterface->pfGetDimensions(pWidth, pHeight);
}

// 0x004F59F0
void __stdcall WINDOW_ShowCursor(int bShow)
{
    if (!gbIsWindowed || gnDisplayType == 4 || gnDisplayType == 5 || gnDisplayType == 6)
    {
        return;
    }

    if (bShow)
    {
        WINDOW_HideSystemCursor();
    }
    else
    {
        WINDOW_ShowSystemCursor();
    }
}

// 0x004F5A30
int __stdcall WINDOW_IsFullScreen()
{
    if (gpGraphicsInterface)
    {
        return gbIsWindowed == 0;
    }

    return 0;
}

// 0x004F5A50
int __stdcall WINDOW_Activate(int bActive)
{
    D2_ASSERT(gpGraphicsInterface, 471);

    gbIsWindowed = bActive == 0;
    return gpGraphicsInterface->pfActivateWindow(bActive, gbIsWindowed);
}

// 0x004F5AA0
int __stdcall WINDOW_Resize(int nResolution, int bForceResize)
{
    D2_ASSERT(gpGraphicsInterface, 485);

    if (!bForceResize && nResolution == gnResolutionMode)
    {
        return 1;
    }

    gnResolutionMode = nResolution;

    if (gbIsWindowed == 1)
    {
        tagRECT tClientRect = { 0 };
        GetClientRect(ghWnd, &tClientRect);
        if (tClientRect.right - tClientRect.left <= 800 && tClientRect.bottom - tClientRect.top <= 600)
        {
            tagRECT tRect;
            tRect.left = 0;
            tRect.top = 0;
            WINDOW_GetResolutionSize(nResolution, &tRect.right, &tRect.bottom);
            AdjustWindowRectEx(&tRect, 0xCB0000, 0, 0x40000);
            SetWindowPos(ghWnd, (void*)-2, 0, 0, tRect.right - tRect.left, tRect.bottom - tRect.top, 0x16);
        }
    }

    const int bResult = gpGraphicsInterface->pfChangeRes(ghWnd, nResolution);
    WINDOW_LoadGammaSettings();
    return bResult;
}

// 0x004F5BC0
int __stdcall WINDOW_CenterWindow(int nResolution)
{
    D2_ASSERT(gpGraphicsInterface, 562);

    gnResolutionMode = nResolution;

    if (gbIsWindowed == 1)
    {
        void* hWnd = ghWnd;
        tagRECT tClientRect = { 0 };
        GetClientRect(hWnd, &tClientRect);
        if (tClientRect.right - tClientRect.left <= 800 && tClientRect.bottom - tClientRect.top <= 600)
        {
            tagRECT tWorkArea = { 0 };
            SystemParametersInfoA(0x30, 0, &tWorkArea, 0);
            const int nWorkHeight = tWorkArea.bottom - tWorkArea.top;
            const int nWorkWidth = tWorkArea.right - tWorkArea.left;

            tagRECT tWindowRect = {};
            GetWindowRect(hWnd, &tWindowRect);

            tagRECT tRect = { 0 };
            WINDOW_GetResolutionSize(nResolution, &tRect.right, &tRect.bottom);
            gnCaptionHeight = tRect.bottom;
            AdjustWindowRectEx(&tRect, 0xCB0000, 0, 0x40000);
            const int nHeight = tRect.bottom - tRect.top;
            const int nWidth = tRect.right - tRect.left;
            gnCaptionHeight = nHeight - gnCaptionHeight;

            int nX = (nWorkWidth - nWidth) / 2 + tWorkArea.left;
            if (nX < 0)
            {
                nX = 0;
            }

            int nY = (nWorkHeight - nHeight) / 2 + tWorkArea.top;
            if (nY < 0)
            {
                nY = 0;
            }

            SetWindowPos(ghWnd, (void*)-2, nX, nY, nWidth, nHeight, 0x14);
            WINDOW_GetResolutionSize(nResolution, &gtWindowRect.right, &gtWindowRect.bottom);
            GetWindowRect(hWnd, &gtWindowRect);
        }
    }

    return 1;
}

// 0x004F5D50
void __stdcall WINDOW_ClearCaches()
{
    gpGraphicsInterface->pfClearCaches();
}

// 0x004F5D60
void __stdcall WINDOW_PlayCutscene()
{
    D2_ASSERT(gpGraphicsInterface, 0x2AD);
    gpGraphicsInterface->pfPlayCutscene();
}

// 0x004F5D90
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nResolution, void* pfFrame)
{
    D2_ASSERT(gpGraphicsInterface, 732);

    return gpGraphicsInterface->pfOpenSmackCutscene(szFile, nResolution, pfFrame);
}

// 0x004F5DD0
int __stdcall WINDOW_CheckCutScene()
{
    D2_ASSERT(gpGraphicsInterface, 0x2F6);

    return gpGraphicsInterface->pfCheckCutScene();
}

// 0x004F5E00
void __stdcall WINDOW_DecodeSmacker(const char* szSmacker, unsigned char* pBuffer, int nVersion)
{
    D2_ASSERT(gpGraphicsInterface, 770);

    return gpGraphicsInterface->pfDecodeSmacker(szSmacker, pBuffer, nVersion);
}

// 0x004F5E40
void __stdcall WINDOW_PlaySmacker(void* pContext)
{
    D2_ASSERT(gpGraphicsInterface, 782);

    return gpGraphicsInterface->pfPlaySmacker(pContext);
}

// 0x004F5E80
void __stdcall WINDOW_CloseSmacker(void* pContext)
{
    D2_ASSERT(gpGraphicsInterface, 794);

    return gpGraphicsInterface->pfCloseSmacker(pContext);
}

// 0x004F5EC0
void __cdecl WINDOW_UpdatePlacement()
{
    if (gbIsWindowed == 1)
    {
        return;
    }

    _AppBarData tData = {};
    tData.cbSize = sizeof(tData);
    tData.hWnd = ghWnd;

    for (int i = 0; i < 4; ++i)
    {
        tData.uEdge = i;

        D2WindowPlacementStrc* pWindowPlacement = &gWindowPlacement[i];
        pWindowPlacement->hWnd = (void*)SHAppBarMessage(7, &tData);
        if (pWindowPlacement->hWnd)
        {
            pWindowPlacement->windowPlacement.length = sizeof(tagWINDOWPLACEMENT);
            GetWindowPlacement(pWindowPlacement->hWnd, &pWindowPlacement->windowPlacement);
            ShowWindow(pWindowPlacement->hWnd, 0);
        }
    }
}

// 0x004F5F60
void __stdcall WINDOW_ShowAll()
{
    if (gbIsWindowed == 1)
    {
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        D2WindowPlacementStrc* pWindowPlacement = &gWindowPlacement[i];
        if (pWindowPlacement->hWnd)
        {
            ShowWindow(pWindowPlacement->hWnd, pWindowPlacement->windowPlacement.showCmd);
        }
    }
}

// 0x004F5FA0
void __cdecl WINDOW_UpdatePauseState()
{
    if (gbWindowState == gbPaused || !ghWnd)
    {
        return;
    }

    D2_ASSERT(gpGraphicsInterface, 361);

    int bPaused = gbPaused;
    if (!gbPaused)
    {
        if (IsIconic(ghWnd))
        {
            return;
        }
        bPaused = gbPaused;
    }

    gbWindowState = bPaused;
    if (bPaused)
    {
        ShowWindow(ghWnd, 6);
        WINDOW_ShowAll();
        while (ShowCursor(1) < 0);
    }
    else
    {
        WINDOW_UpdatePlacement();
        while (ShowCursor(0) >= 0);
    }

    gpGraphicsInterface->pfPauseSurface(ghWnd, gnResolutionMode, gbWindowState);

    if (!gbWindowState)
    {
        D2GFX_SetPalette(0);
        WINDOW_LoadGammaSettings();
    }
}

// 0x004F6070
int __stdcall WINDOW_GetState()
{
    WINDOW_UpdatePauseState();
    return gbWindowState;
}

// 0x004F6080
void __stdcall WINDOW_EndCutScene(int nResolution)
{
    D2_ASSERT(gpGraphicsInterface, 697);

    WINDOW_UpdatePauseState();

    if (gbWindowState)
    {
        gnResolutionMode = nResolution;
    }
    else if (!WINDOW_Resize(nResolution, 1))
    {
        LOGMANAGER_WriteLogLine("Failed to resize window after cutscenes... this is fatal!");
        exit(-1);
    }

    D2GFX_SetPalette(0);
}

// 0x004F60F0
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    return gpGraphicsInterface->pfStartDraw(bClear, nRed, nGreen, nBlue);
}

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TileLibraryEntryStrc;

struct D2GfxLightStrc;

struct D2GfxLightExStrc;

union D2LargeIntegerStrc;

struct D2PerfStartStrc;

union D2LargeIntegerStrc
{
    struct
    {
        unsigned long nLowPart;
        long nHighPart;
    };
    __int64 nQuadPart;
};

struct D2PerfStartStrc
{
    D2LargeIntegerStrc tStart;

    D2PerfStartStrc()
    {
        QueryPerformanceCounter(&tStart);
    }
};

// build: symbol ?$S1@?1??D2GFX_GetElapsedMs@@YANXZ@4IA 0x007C9358
// 0x004F6110
double __cdecl D2GFX_GetPerfFrequency()
{
    D2LargeIntegerStrc tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return (double)tFrequency.nQuadPart;
}

// 0x004F6130
double __cdecl D2GFX_GetElapsedMs()
{
    static D2PerfStartStrc stStart; // 0x007C9350

    D2LargeIntegerStrc tNow;
    QueryPerformanceCounter(&tNow);
    tNow.nQuadPart -= stStart.tStart.nQuadPart;
    const double dTicks = (double)tNow.nQuadPart;

    D2LargeIntegerStrc tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return dTicks / ((double)tFrequency.nQuadPart / 1000.0);
}

// 0x004F6190
int __stdcall D2GFX_EndScene()
{
    static double sdLastFrame = D2GFX_GetElapsedMs();

    const double dNow = D2GFX_GetElapsedMs();
    const double dElapsed = dNow - sdLastFrame;
    if (dElapsed <= 5.0)
    {
        const double dWait = 5.0 - dElapsed + gdFrameRemainder;
        const int nWait = (int)dWait;
        const double dWaitWhole = nWait;
        gdFrameRemainder = dWait - dWaitWhole;
        if (nWait > 0)
        {
            if (nWait <= 5)
            {
                Sleep(nWait);
                gdFrameRemainder = gdFrameRemainder - (D2GFX_GetElapsedMs() - dNow - dWaitWhole);
            }
            else
            {
                gdFrameRemainder = 0.0;
            }
        }
        else
        {
            gdFrameRemainder = 0.0;
        }
    }

    sdLastFrame = D2GFX_GetElapsedMs();
    gpGraphicsInterface->pfEndDraw();
    gpGraphicsInterface->pfBlit();
    return 1;
}

// 0x004F6250
int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer)
{
    return gpGraphicsInterface->pfGetBackBuffer(pBuffer);
}

// 0x004F6270
int __stdcall D2GFX_HardwareAcceleratedRenderMode()
{
    return gnDisplayType >= DISPLAYTYPE_GLIDE;
}

// 0x004F6280
void __stdcall D2GFX_UtilDiamond(tagRECT* pRect, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilDiamond(pRect, nPaletteIndex);
}

// 0x004F62A0
void __stdcall D2GFX_UtilRect(tagRECT* pRect, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilRect(pRect, nPaletteIndex);
}

// 0x004F62C0
void __stdcall D2GFX_UtilFilledRect(tagRECT* pRect, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilFilledRect(pRect, nPaletteIndex);
}

// 0x004F62E0
void __stdcall D2GFX_UtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfUtilPoint(pPoint, nSize, nPaletteIndex);
}

// 0x004F6300
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode)
{
    if (nXEnd >= nXStart && nYEnd >= nYStart)
    {
        gpGraphicsInterface->pfDrawBox(nXStart, nYStart, nXEnd, nYEnd, dwColor, eDrawMode);
    }
}

// 0x004F6340
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    if (nXEnd >= nXStart && nYEnd >= nYStart)
    {
        gpGraphicsInterface->pfDrawBoxAlpha(nXStart, nYStart, nXEnd, nYEnd, dwColor, nAlpha);
    }
}

// 0x004F6380
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    gpGraphicsInterface->pfDrawLine(nXStart, nYStart, nXEnd, nYEnd, dwColor, nAlpha);
}

// 0x004F63B0
void __stdcall D2GFX_ClearScreen(int bPartial)
{
    return gpGraphicsInterface->pfClearScreen(bPartial);
}

// Kept noinline: the original calls this out of line from its callers in this file; without it the compiler inlines it.
// 0x004F63D0
__declspec(noinline) void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette)
{
    if (pPalette)
    {
        memcpy(gatGfxPalette, pPalette, sizeof(gatGfxPalette));
        gpGraphicsInterface->pfSetPalette(pPalette);
    }
    else
    {
        gpGraphicsInterface->pfSetPalette(gatGfxPalette);
    }
}

// 0x004F6410
void __stdcall D2GFX_SetPaletteTables(D2PaletteTableStrc* pPaletteTables)
{
    gpGraphicsInterface->pfSetPaletteTables(pPaletteTables);
    CMNSUBTILE_SetPaletteTables(pPaletteTables);
}

// 0x004F6430
void __stdcall D2GFX_SetAmbientColor(int nRed, int nGreen, int nBlue)
{
    return gpGraphicsInterface->pfSetAmbientColor(nRed, nGreen, nBlue);
}

// 0x004F6450
void __stdcall TEXTURE_CelFlatSpriteDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette)
{
    return gpGraphicsInterface->pfCelFlatSpriteDraw(pData, nXPos, nYPos, dwGamma, eDrawMode, nScreenMode, pPalette);
}

// 0x004F6480
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette)
{
    return gpGraphicsInterface->pfCelDraw(pData, nXPos, nYPos, dwGamma, eDrawMode, pPalette);
}

// 0x004F64B0
void __stdcall TEXTURE_CelDrawColor(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift)
{
    return gpGraphicsInterface->pfCelDrawColor(pData, nXPos, nYPos, dwGamma, eDrawMode, nGlobalPaletteShift);
}

// 0x004F64E0
void __stdcall TEXTURE_CelDrawEx(D2GfxDataStrc* pData, int nXPos, int nYPos, int nSkipLines, int nDrawLines, int eDrawMode)
{
    if (nDrawLines)
    {
        return gpGraphicsInterface->pfCelDrawEx(pData, nXPos, nYPos, nSkipLines, nDrawLines, eDrawMode);
    }
}

// 0x004F6510
void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode)
{
    return gpGraphicsInterface->pfCelDrawClipped(pData, nXPos, nYPos, pCropRect, eDrawMode);
}

// 0x004F6540
void __stdcall TEXTURE_CelDrawShadow(D2GfxDataStrc* pData, int nXPos, int nYPos)
{
    return gpGraphicsInterface->pfCelDrawShadow(pData, nXPos + 2, nYPos);
}

// 0x004F6570
void __stdcall TEXTURE_CelDrawHilight(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned char nPaletteIndex)
{
    return gpGraphicsInterface->pfCelDrawHilight(pData, nXPos, nYPos, nPaletteIndex);
}

// 0x004F65A0
void __stdcall TEXTURE_DebugFillBackBuffer(int nXPos, int nYPos)
{
    return gpGraphicsInterface->pfDebugFillBackBuffer(nXPos, nYPos);
}

static int gnChangedScaleFactor = 256;                                                           // 0x0072DB40

static int gnScaleFactor = 256;                                                                  // 0x0072DB44

// 0x004F65C0
void __stdcall SCALE_UpdateFactor()
{
    gnScaleFactor = gnChangedScaleFactor;
    return gpGraphicsInterface->pfSetGlobalScale(gnScaleFactor);
}

extern int gnScaleFactor; // 0x0072DB44

// 0x004F65E0
int __cdecl SCALE_GetFactor()
{
    return gnScaleFactor;
}

// 0x004F65F0
void __stdcall SCALE_SetDefaultFactor()
{
    gnScaleFactor = 0x100;
    return gpGraphicsInterface->pfSetGlobalScale(gnScaleFactor);
}

// 0x004F6610
void __cdecl D2GFX_IncreaseScaleFactor()
{
    if (gnChangedScaleFactor < 0x200)
    {
        gnChangedScaleFactor += 0x20;
        if (gnChangedScaleFactor > 0x200)
        {
            gnChangedScaleFactor = 0x200;
        }
    }
}

// 0x004F6640
void __cdecl D2GFX_DecreaseScaleFactor()
{
    if (gnChangedScaleFactor > 0x100)
    {
        gnChangedScaleFactor -= 0x20;
        if (gnChangedScaleFactor < 0x100)
        {
            gnChangedScaleFactor = 0x100;
        }
    }
}

// 0x004F6670
void __stdcall SCALE_SetPerspectiveScale(int nXScale, int nYScale)
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0x61);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x62);
    gnPerspectiveScaleX = nXScale;
    gnPerspectiveScaleY = nYScale;
    return gpGraphicsInterface->pfUpdatePerspective(nXScale, nYScale);
}

// 0x004F66E0
int __stdcall SCALE_CheckPerspectivePosition(int nXPos, int nYPos)
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0x74);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x75);

    int nX = nXPos - gnPerspectiveScaleX;
    if (nX < 0)
    {
        nX = -nX;
    }
    if (nX > 0x320000)
    {
        return 0;
    }

    int nY = nYPos - gnPerspectiveScaleY;
    if (nY < 0)
    {
        nY = -nY;
    }
    return nY <= 0x320000;
}

// 0x004F6760
void __stdcall SCALE_AdjustPerspectivePosition(int nXPos, int nYPos, int nBias, int* pXAdjust, int* pYAdjust)
{
    D2_ASSERT(gnDisplayType >= DISPLAYTYPE_GLIDE, 0x8B);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x8C);

    return gpGraphicsInterface->pfPerspectiveTransform(nXPos, nYPos, nBias, pXAdjust, pYAdjust);
}

// 0x004F67C0
void __stdcall SCALE_ScalePerspectivePosition(int nXPos, int nYPos, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder)
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0x98);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0x99);

    return gpGraphicsInterface->pfPerspectiveTransformScale(nXPos, nYPos, 0, pXAdjust, pYAdjust, bOrder);
}

// 0x004F6830
void __stdcall SCALE_SetDefaultFactorPerspectiveFactor()
{
    D2_ASSERT(gnDisplayType == DISPLAYTYPE_GLIDE || gnDisplayType == DISPLAYTYPE_OPENGL || gnDisplayType == DISPLAYTYPE_RAVE || gnDisplayType == DISPLAYTYPE_DIRECT3D, 0xA8);
    D2_ASSERT(gGfxSettings.bPerspectiveEnabled, 0xA9);

    return gpGraphicsInterface->pfPerspectiveClearScale();
}

// 0x004F6890
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...)
{
    va_list va;

    va_start(va, szFormat);
    return gpGraphicsInterface->pfOutputString(nXPos, nYPos, szFormat, va);
}

// 0x004F68B0
void __stdcall D2GFX_DebugDraw(unsigned int* pLight, unsigned int* pPlayerLight, int nXPos, int nYPos)
{
    return gpGraphicsInterface->pfDebugDraw(pLight, pPlayerLight, nXPos, nYPos);
}

// 0x004F68E0
int __stdcall D2GFX_FloorTileDraw(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nXPos, int nYPos, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData)
{
    return gpGraphicsInterface->pfFloorTileDraw(pTile, pLight, nXPos, nYPos, nWorldXpos, nWorldYpos, nAlpha, nScreenPanels, pTileData);
}

// 0x004F6920
int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels)
{
    return gpGraphicsInterface->pfTileDrawLit(pTile, nXPos, nYPos, pLight, nScreenPanels);
}

// 0x004F6950
int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha)
{
    return gpGraphicsInterface->pfTileDrawTrans(pTile, nXPos, nYPos, pLight, nScreenPanels, nAlpha);
}

// 0x004F6980
int __stdcall TILE_ShadowTileDraw(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, int eDrawMode, int nScreenPanels)
{
    return gpGraphicsInterface->pfShadowTileDraw(pTile, nXPos, nYPos, eDrawMode, nScreenPanels);
}

// 0x004F69B0
void __fastcall CMNSUBTILE_DrawIsoBlockFlat(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette)
{
    unsigned char* pRow = pDst;
    for (int i = 0; i < 15; ++i)
    {
        unsigned char* d = &pRow[ganSubtileRowXOffset[i]];
        unsigned char* s = &pSrc[ganSubtileRowSrcOffset[i]];
        switch (ganSubtileRowWidth[i])
        {
        case 32:
            d[31] = pPalette[s[31]];
            d[30] = pPalette[s[30]];
            d[29] = pPalette[s[29]];
            d[28] = pPalette[s[28]];
        case 28:
            d[27] = pPalette[s[27]];
            d[26] = pPalette[s[26]];
            d[25] = pPalette[s[25]];
            d[24] = pPalette[s[24]];
        case 24:
            d[23] = pPalette[s[23]];
            d[22] = pPalette[s[22]];
            d[21] = pPalette[s[21]];
            d[20] = pPalette[s[20]];
        case 20:
            d[19] = pPalette[s[19]];
            d[18] = pPalette[s[18]];
            d[17] = pPalette[s[17]];
            d[16] = pPalette[s[16]];
        case 16:
            d[15] = pPalette[s[15]];
            d[14] = pPalette[s[14]];
            d[13] = pPalette[s[13]];
            d[12] = pPalette[s[12]];
        case 12:
            d[11] = pPalette[s[11]];
            d[10] = pPalette[s[10]];
            d[9] = pPalette[s[9]];
            d[8] = pPalette[s[8]];
        case 8:
            d[7] = pPalette[s[7]];
            d[6] = pPalette[s[6]];
            d[5] = pPalette[s[5]];
            d[4] = pPalette[s[4]];
        case 4:
            d[3] = pPalette[s[3]];
            d[2] = pPalette[s[2]];
            d[1] = pPalette[s[1]];
            d[0] = pPalette[s[0]];
        }
        pRow += gnScreenPitch;
    }
}

// 0x004F6BB0
void __fastcall D2GFX_DrawLitSubtileRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep)
{
    unsigned char* pRow = pDst;
    for (int i = 0; i < 15; ++i)
    {
        const int nOff = ganSubtileRowXOffset[i];
        unsigned char* v = &gabLightCube[nLightX >> 7][nLightY >> 7][nOff];
        unsigned char* s = &pSrc[ganSubtileRowSrcOffset[i]];
        switch (ganSubtileRowWidth[i])
        {
        case 32:
            pRow[nOff + 31] = gatLightPalettes[v[31]].colors[s[31]];
            pRow[nOff + 30] = gatLightPalettes[v[30]].colors[s[30]];
            pRow[nOff + 29] = gatLightPalettes[v[29]].colors[s[29]];
            pRow[nOff + 28] = gatLightPalettes[v[28]].colors[s[28]];
        case 28:
            pRow[nOff + 27] = gatLightPalettes[v[27]].colors[s[27]];
            pRow[nOff + 26] = gatLightPalettes[v[26]].colors[s[26]];
            pRow[nOff + 25] = gatLightPalettes[v[25]].colors[s[25]];
            pRow[nOff + 24] = gatLightPalettes[v[24]].colors[s[24]];
        case 24:
            pRow[nOff + 23] = gatLightPalettes[v[23]].colors[s[23]];
            pRow[nOff + 22] = gatLightPalettes[v[22]].colors[s[22]];
            pRow[nOff + 21] = gatLightPalettes[v[21]].colors[s[21]];
            pRow[nOff + 20] = gatLightPalettes[v[20]].colors[s[20]];
        case 20:
            pRow[nOff + 19] = gatLightPalettes[v[19]].colors[s[19]];
            pRow[nOff + 18] = gatLightPalettes[v[18]].colors[s[18]];
            pRow[nOff + 17] = gatLightPalettes[v[17]].colors[s[17]];
            pRow[nOff + 16] = gatLightPalettes[v[16]].colors[s[16]];
        case 16:
            pRow[nOff + 15] = gatLightPalettes[v[15]].colors[s[15]];
            pRow[nOff + 14] = gatLightPalettes[v[14]].colors[s[14]];
            pRow[nOff + 13] = gatLightPalettes[v[13]].colors[s[13]];
            pRow[nOff + 12] = gatLightPalettes[v[12]].colors[s[12]];
        case 12:
            pRow[nOff + 11] = gatLightPalettes[v[11]].colors[s[11]];
            pRow[nOff + 10] = gatLightPalettes[v[10]].colors[s[10]];
            pRow[nOff + 9] = gatLightPalettes[v[9]].colors[s[9]];
            pRow[nOff + 8] = gatLightPalettes[v[8]].colors[s[8]];
        case 8:
            pRow[nOff + 7] = gatLightPalettes[v[7]].colors[s[7]];
            pRow[nOff + 6] = gatLightPalettes[v[6]].colors[s[6]];
            pRow[nOff + 5] = gatLightPalettes[v[5]].colors[s[5]];
            pRow[nOff + 4] = gatLightPalettes[v[4]].colors[s[4]];
        case 4:
            pRow[nOff + 3] = gatLightPalettes[v[3]].colors[s[3]];
            pRow[nOff + 2] = gatLightPalettes[v[2]].colors[s[2]];
            pRow[nOff + 1] = gatLightPalettes[v[1]].colors[s[1]];
            pRow[nOff + 0] = gatLightPalettes[v[0]].colors[s[0]];
        }
        pRow += gnScreenPitch;
        nLightX += nLightXStep;
        nLightY += nLightYStep;
    }
}

// build: symbol ?ganRowOffsets@* 0x007C97A8
#define gnRowOffsets_007C9828 (ganRowOffsets + 32)

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

void __fastcall CMNSUBTILE_DrawIsoBlockFlat(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette); // 0x004F69B0

void __fastcall CMNSUBTILE_DrawRleVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nLight); // 0x004F8050

unsigned char* gpScreenBuffer; // 0x007D5448

int gnLightingOff; // 0x007D2340

// 0x004F6F60
void __fastcall CMNSUBTILE_DrawRleRows(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows)
{
    unsigned char* p = pDst;
    while (nRows)
    {
        int nSkip = *pSrc++;
        int nCount = *pSrc++;
        if (!nSkip && !nCount)
        {
            --nRows;
            pDst += gnScreenPitch;
            p = pDst;
        }
        else
        {
            p += nSkip;
            switch (nCount)
            {
            case 32: p[31] = pPalette[pSrc[31]];
            case 31: p[30] = pPalette[pSrc[30]];
            case 30: p[29] = pPalette[pSrc[29]];
            case 29: p[28] = pPalette[pSrc[28]];
            case 28: p[27] = pPalette[pSrc[27]];
            case 27: p[26] = pPalette[pSrc[26]];
            case 26: p[25] = pPalette[pSrc[25]];
            case 25: p[24] = pPalette[pSrc[24]];
            case 24: p[23] = pPalette[pSrc[23]];
            case 23: p[22] = pPalette[pSrc[22]];
            case 22: p[21] = pPalette[pSrc[21]];
            case 21: p[20] = pPalette[pSrc[20]];
            case 20: p[19] = pPalette[pSrc[19]];
            case 19: p[18] = pPalette[pSrc[18]];
            case 18: p[17] = pPalette[pSrc[17]];
            case 17: p[16] = pPalette[pSrc[16]];
            case 16: p[15] = pPalette[pSrc[15]];
            case 15: p[14] = pPalette[pSrc[14]];
            case 14: p[13] = pPalette[pSrc[13]];
            case 13: p[12] = pPalette[pSrc[12]];
            case 12: p[11] = pPalette[pSrc[11]];
            case 11: p[10] = pPalette[pSrc[10]];
            case 10: p[9] = pPalette[pSrc[9]];
            case 9: p[8] = pPalette[pSrc[8]];
            case 8: p[7] = pPalette[pSrc[7]];
            case 7: p[6] = pPalette[pSrc[6]];
            case 6: p[5] = pPalette[pSrc[5]];
            case 5: p[4] = pPalette[pSrc[4]];
            case 4: p[3] = pPalette[pSrc[3]];
            case 3: p[2] = pPalette[pSrc[2]];
            case 2: p[1] = pPalette[pSrc[1]];
            case 1: p[0] = pPalette[pSrc[0]];
            }
            p += nCount;
            pSrc += nCount;
        }
    }
}

// 0x004F71A0
void __fastcall CMNSUBTILE_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
    while (nRows) {
        int nSkip = *pSrc++;
        int nLength = *pSrc++;
        if (!nSkip && !nLength) {
            nLightX += nLightXStep;
            nLightY += nLightYStep;
            pDst += gnScreenPitch;
            --nRows;
            pRow = pDst;
            pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
        } else {
            pRow += nSkip;
            pLight += nSkip;
            switch (nLength) {
            case 32: pRow[31] = gatLightPalettes[pLight[31]].colors[pSrc[31]];
            case 31: pRow[30] = gatLightPalettes[pLight[30]].colors[pSrc[30]];
            case 30: pRow[29] = gatLightPalettes[pLight[29]].colors[pSrc[29]];
            case 29: pRow[28] = gatLightPalettes[pLight[28]].colors[pSrc[28]];
            case 28: pRow[27] = gatLightPalettes[pLight[27]].colors[pSrc[27]];
            case 27: pRow[26] = gatLightPalettes[pLight[26]].colors[pSrc[26]];
            case 26: pRow[25] = gatLightPalettes[pLight[25]].colors[pSrc[25]];
            case 25: pRow[24] = gatLightPalettes[pLight[24]].colors[pSrc[24]];
            case 24: pRow[23] = gatLightPalettes[pLight[23]].colors[pSrc[23]];
            case 23: pRow[22] = gatLightPalettes[pLight[22]].colors[pSrc[22]];
            case 22: pRow[21] = gatLightPalettes[pLight[21]].colors[pSrc[21]];
            case 21: pRow[20] = gatLightPalettes[pLight[20]].colors[pSrc[20]];
            case 20: pRow[19] = gatLightPalettes[pLight[19]].colors[pSrc[19]];
            case 19: pRow[18] = gatLightPalettes[pLight[18]].colors[pSrc[18]];
            case 18: pRow[17] = gatLightPalettes[pLight[17]].colors[pSrc[17]];
            case 17: pRow[16] = gatLightPalettes[pLight[16]].colors[pSrc[16]];
            case 16: pRow[15] = gatLightPalettes[pLight[15]].colors[pSrc[15]];
            case 15: pRow[14] = gatLightPalettes[pLight[14]].colors[pSrc[14]];
            case 14: pRow[13] = gatLightPalettes[pLight[13]].colors[pSrc[13]];
            case 13: pRow[12] = gatLightPalettes[pLight[12]].colors[pSrc[12]];
            case 12: pRow[11] = gatLightPalettes[pLight[11]].colors[pSrc[11]];
            case 11: pRow[10] = gatLightPalettes[pLight[10]].colors[pSrc[10]];
            case 10: pRow[9] = gatLightPalettes[pLight[9]].colors[pSrc[9]];
            case 9: pRow[8] = gatLightPalettes[pLight[8]].colors[pSrc[8]];
            case 8: pRow[7] = gatLightPalettes[pLight[7]].colors[pSrc[7]];
            case 7: pRow[6] = gatLightPalettes[pLight[6]].colors[pSrc[6]];
            case 6: pRow[5] = gatLightPalettes[pLight[5]].colors[pSrc[5]];
            case 5: pRow[4] = gatLightPalettes[pLight[4]].colors[pSrc[4]];
            case 4: pRow[3] = gatLightPalettes[pLight[3]].colors[pSrc[3]];
            case 3: pRow[2] = gatLightPalettes[pLight[2]].colors[pSrc[2]];
            case 2: pRow[1] = gatLightPalettes[pLight[1]].colors[pSrc[1]];
            case 1: pRow[0] = gatLightPalettes[pLight[0]].colors[pSrc[0]];
            }
            pRow += nLength;
            pSrc += nLength;
            pLight += nLength;
        }
    }
}

// 0x004F7580
void __fastcall CMNSUBTILE_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows)
{
    unsigned char* p = pDst;
    int i = 0;
    if (nRows > 0)
    {
    int nLeft = nY;
    do
    {
        int nSkip = *pSrc++;
        int nCount = *pSrc++;
        if (!nSkip && !nCount)
        {
            ++i;
            ++nLeft;
            pDst += gnScreenPitch;
            p = pDst;
        }
        else
        {
            if (nLeft >= gnRowClipBottom)
            {
                return;
            }

            p += nSkip;
            if (nLeft >= gnRowClipTop)
            {
                unsigned char* pNextSrc = pSrc + nCount;
                unsigned char* pNext = p + nCount;
                const int nPos = p - pDst + nX;
                int nStart = gnColClipLeft + (-nPos);
                nStart = nStart > 0 ? nStart : 0;
                int nEnd = gnColClipRight + (-nPos);
                nEnd = nEnd > 0 ? nEnd : 0;
                nEnd = nEnd < nCount ? nEnd : nCount;
                const int nLength = nEnd - nStart;
                if (nLength > 0)
                {
                    p += nStart;
                    pSrc += nStart;
                    switch (nLength)
                    {
                    case 32: p[31] = pPalette[pSrc[31]];
                    case 31: p[30] = pPalette[pSrc[30]];
                    case 30: p[29] = pPalette[pSrc[29]];
                    case 29: p[28] = pPalette[pSrc[28]];
                    case 28: p[27] = pPalette[pSrc[27]];
                    case 27: p[26] = pPalette[pSrc[26]];
                    case 26: p[25] = pPalette[pSrc[25]];
                    case 25: p[24] = pPalette[pSrc[24]];
                    case 24: p[23] = pPalette[pSrc[23]];
                    case 23: p[22] = pPalette[pSrc[22]];
                    case 22: p[21] = pPalette[pSrc[21]];
                    case 21: p[20] = pPalette[pSrc[20]];
                    case 20: p[19] = pPalette[pSrc[19]];
                    case 19: p[18] = pPalette[pSrc[18]];
                    case 18: p[17] = pPalette[pSrc[17]];
                    case 17: p[16] = pPalette[pSrc[16]];
                    case 16: p[15] = pPalette[pSrc[15]];
                    case 15: p[14] = pPalette[pSrc[14]];
                    case 14: p[13] = pPalette[pSrc[13]];
                    case 13: p[12] = pPalette[pSrc[12]];
                    case 12: p[11] = pPalette[pSrc[11]];
                    case 11: p[10] = pPalette[pSrc[10]];
                    case 10: p[9] = pPalette[pSrc[9]];
                    case 9: p[8] = pPalette[pSrc[8]];
                    case 8: p[7] = pPalette[pSrc[7]];
                    case 7: p[6] = pPalette[pSrc[6]];
                    case 6: p[5] = pPalette[pSrc[5]];
                    case 5: p[4] = pPalette[pSrc[4]];
                    case 4: p[3] = pPalette[pSrc[3]];
                    case 3: p[2] = pPalette[pSrc[2]];
                    case 2: p[1] = pPalette[pSrc[1]];
                    case 1: p[0] = pPalette[pSrc[0]];
                    }
                }

                pSrc = pNextSrc;
                p = pNext;
            }
            else
            {
                p += nCount;
                pSrc += nCount;
            }
        }
    } while (i < nRows);
    }
}

// 0x004F7850
void __fastcall CMNSUBTILE_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift)
{
    unsigned char* pRow = pDst;
    unsigned char* pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
    int nRow = 0;
    if (nRows > 0)
    {
        int nCurrentY = nY;
        do
        {
            int nSkip = *pSrc++;
            int nLength = *pSrc++;
            if (!nSkip && !nLength)
            {
                ++nRow; ++nCurrentY;
                pDst += gnScreenPitch;
                pRow = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pLight = gabLightCube[nLightX >> nShift][nLightY >> nShift];
            }
            else
            {
                if (nCurrentY >= gnRowClipBottom) return;
                pRow += nSkip;
                pLight += nSkip;
                if (nCurrentY >= gnRowClipTop)
                {
                    unsigned char* pSrcEnd = pSrc + nLength;
                    unsigned char* pDstEnd = pRow + nLength;
                    const int nPosX = pRow - pDst + nX;
                    int nStart = gnColClipLeft + (-nPosX);
                    nStart = nStart > 0 ? nStart : 0;
                    int nEnd = gnColClipRight + (-nPosX);
                    nEnd = nEnd > 0 ? nEnd : 0;
                    if (nEnd >= nLength) nEnd = nLength;
                    int nVisible = nEnd - nStart;
                    if (nVisible > 0)
                    {
                        pRow += nStart;
                        pSrc += nStart;
                        switch(nVisible)
                        {
                        case 32: pRow[31] = gatLightPalettes[pLight[31]].remap[pSrc[31]];
                        case 31: pRow[30] = gatLightPalettes[pLight[30]].remap[pSrc[30]];
                        case 30: pRow[29] = gatLightPalettes[pLight[29]].remap[pSrc[29]];
                        case 29: pRow[28] = gatLightPalettes[pLight[28]].remap[pSrc[28]];
                        case 28: pRow[27] = gatLightPalettes[pLight[27]].remap[pSrc[27]];
                        case 27: pRow[26] = gatLightPalettes[pLight[26]].remap[pSrc[26]];
                        case 26: pRow[25] = gatLightPalettes[pLight[25]].remap[pSrc[25]];
                        case 25: pRow[24] = gatLightPalettes[pLight[24]].remap[pSrc[24]];
                        case 24: pRow[23] = gatLightPalettes[pLight[23]].remap[pSrc[23]];
                        case 23: pRow[22] = gatLightPalettes[pLight[22]].remap[pSrc[22]];
                        case 22: pRow[21] = gatLightPalettes[pLight[21]].remap[pSrc[21]];
                        case 21: pRow[20] = gatLightPalettes[pLight[20]].remap[pSrc[20]];
                        case 20: pRow[19] = gatLightPalettes[pLight[19]].remap[pSrc[19]];
                        case 19: pRow[18] = gatLightPalettes[pLight[18]].remap[pSrc[18]];
                        case 18: pRow[17] = gatLightPalettes[pLight[17]].remap[pSrc[17]];
                        case 17: pRow[16] = gatLightPalettes[pLight[16]].remap[pSrc[16]];
                        case 16: pRow[15] = gatLightPalettes[pLight[15]].remap[pSrc[15]];
                        case 15: pRow[14] = gatLightPalettes[pLight[14]].remap[pSrc[14]];
                        case 14: pRow[13] = gatLightPalettes[pLight[13]].remap[pSrc[13]];
                        case 13: pRow[12] = gatLightPalettes[pLight[12]].remap[pSrc[12]];
                        case 12: pRow[11] = gatLightPalettes[pLight[11]].remap[pSrc[11]];
                        case 11: pRow[10] = gatLightPalettes[pLight[10]].remap[pSrc[10]];
                        case 10: pRow[9] = gatLightPalettes[pLight[9]].remap[pSrc[9]];
                        case 9: pRow[8] = gatLightPalettes[pLight[8]].remap[pSrc[8]];
                        case 8: pRow[7] = gatLightPalettes[pLight[7]].remap[pSrc[7]];
                        case 7: pRow[6] = gatLightPalettes[pLight[6]].remap[pSrc[6]];
                        case 6: pRow[5] = gatLightPalettes[pLight[5]].remap[pSrc[5]];
                        case 5: pRow[4] = gatLightPalettes[pLight[4]].remap[pSrc[4]];
                        case 4: pRow[3] = gatLightPalettes[pLight[3]].remap[pSrc[3]];
                        case 3: pRow[2] = gatLightPalettes[pLight[2]].remap[pSrc[2]];
                        case 2: pRow[1] = gatLightPalettes[pLight[1]].remap[pSrc[1]];
                        case 1: pRow[0] = gatLightPalettes[pLight[0]].remap[pSrc[0]];
                        }
                    }
                    pSrc = pSrcEnd;
                    pRow = pDstEnd;
                    pLight += nLength;
                }
                else
                {
                    pRow += nLength;
                    pLight += nLength;
                    pSrc += nLength;
                }
            }
        } while (nRow < nRows);
    }
}

// 0x004F7CC0
extern "C" void __cdecl CMNSUBTILE_BuildGouraudCache()
{
    for (int i = 0; i < 32; ++i)
    {
        for (int j = 0; j < 32; ++j)
        {
            int nValue = i << 24;
            const int nStep = ((j - i) << 24) >> 5;
            for (int k = 0; k < 32; ++k)
            {
                nValue = nValue > 0 ? nValue : 0;
                if (nValue >= 0x1F000000)
                {
                    nValue = 0x1F000000;
                }
                gabLightCube[i][j][k] = nValue >> 24;
                nValue += nStep;
            }

            D2_ASSERT((nValue >> 24) == j, 0x285);
        }
    }
}

// 0x004F7DA0
void __fastcall WINDOW_SetPanelCoords(int nWidth, int nHeight)
{
    int nLeft = 0;
    int nRight = nWidth;
    const int nBottom = nHeight - 0x2F;
    if (gnViewMatrixAdjust == 1)
    {
        nRight -= nWidth / 2;
    }
    else if (gnViewMatrixAdjust == 2)
    {
        nLeft = nWidth / 2;
    }
    gnScreen_7D2338 = nBottom;
    gnInnerBlockLeft = nLeft;
    gnInnerLeft = nLeft;
    gnColClipLeft = nLeft;
    gnScreen_7D2330 = -0x10;
    gnScreen_7C9788 = nLeft - 0x20;
    gnInnerBlockBottom = nBottom - 0x10;
    gnScreen_7C9798 = nRight;
    gnInnerBlockTop = 0;
    gnInnerBlockRight = nRight - 0x20;
    gnClipTop = -0x20;
    gnClipRight = nRight;
    gnClipBottom = nBottom;
    gnInnerTop = 0;
    gnClipLeft = nLeft - 0x20;
    gnInnerBottom = nBottom - 0x20;
    gnInnerRight = nRight - 0x20;
    gnRowClipTop = 0;
    gnColClipRight = nRight;
    gnRowClipBottom = nBottom;
}

// 0x004F7E70
void __cdecl CMNSUBTILE_BuildLineOffsets()
{
    int nValue = -32 * gnScreenPitch;
    for (int i = 0; i < 732; ++i)
    {
        ganRowOffsets[i] = nValue;
        nValue += gnScreenPitch;
    }
}

// 0x004F7EA0
void __fastcall CMNSUBTILE_DrawVisTile(unsigned char* pSrc, int nX, int nY)
{
    if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        return;

    D2_ASSERT(gpScreenBuffer, 0x2F4);
// build: symbol ?ganRowOffsets@* 0x007C97A8
    unsigned char* pDst = ganRowOffsets[nY + 32] + gpScreenBuffer + nX;
    unsigned char* p = pDst;
    if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch;
                p = pDst;
            }
            else
            {
                p += nSkip;
                memcpy(p, pSrc, nCount);
                p += nCount;
                pSrc += nCount;
            }
        }
    }
    else
    {
        int nRow = 0;
        int nRowY = nY;
        while (nRow < 0x20)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                ++nRow;
                ++nRowY;
                pDst += gnScreenPitch;
                p = pDst;
            }
            else
            {
                if (nRowY >= gnRowClipBottom)
                    return;

                p += nSkip;
                if (nRowY >= gnRowClipTop)
                {
                    const int nPosX = p - pDst + nX;
                    int nLeft = gnColClipLeft + (-nPosX);
                    nLeft = D2_MAX(nLeft, 0);
                    int nRight = gnColClipRight + (-nPosX);
                    nRight = D2_MAX(nRight, 0);
                    if (nRight >= nCount)
                        nRight = nCount;
                    const int nLength = nRight - nLeft;
                    if (nLength > 0)
                        memcpy(p + nLeft, pSrc + nLeft, nLength);

                    pSrc += nCount;
                    p += nCount;
                }
                else
                {
                    p += nCount;
                    pSrc += nCount;
                }
            }
        }
    }
}

// 0x004F8050
void __fastcall CMNSUBTILE_DrawRleVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nLight)
{
    if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        return;

    unsigned char* pPalette = gatLightPalettes[nLight >> 3].colors;
    unsigned char* pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer + nX;
    D2_ASSERT(gpScreenBuffer, 0x373);
    if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
        CMNSUBTILE_DrawRleRows(pSrc, pDst, pPalette, 0x20);
    else
        CMNSUBTILE_DrawRleRowsClipped(nX, nY, pSrc, pDst, pPalette, 0x20);
}

// 0x004F8120
void __fastcall CMNSUBTILE_DrawLitVisTile(unsigned char* pSrc, int nX, int nY, int* pLight)
{
    if (gnLightingOff)
    {
        const unsigned char nLight = *(unsigned char*)pLight;
        if ((nLight & 0xF8) == 0xF8)
        {
            CMNSUBTILE_DrawVisTile(pSrc, nX, nY);
            return;
        }

        CMNSUBTILE_DrawRleVisTile(pSrc, nX, nY, nLight);
        return;
    }

    const int nLightX = pLight[0] << 5;
    const int nLightXStep = pLight[3] - pLight[0];
    const int nLightY = pLight[1] << 5;
    const int nLightYStep = pLight[2] - pLight[1];
    const int nLightDelta = pLight[1] - pLight[0];
    const int nDiff1 = D2_ABS(nLightDelta);
    const int nDiff2 = D2_ABS(nLightXStep);
    const int nDiff3 = D2_ABS(nLightYStep);
    if (!gGfxSettings.bLowQuality && nDiff3 + nDiff2 + nDiff1 >= 10)
    {
        if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        {
            return;
        }

        D2_ASSERT(gpScreenBuffer, 958);
        unsigned char* pDst = gnRowOffsets_007C9828[nY] + gpScreenBuffer + nX;
        if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
        {
            CMNSUBTILE_DrawLitRleRows(pSrc, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 0x20, 8);
        }
        else
        {
            CMNSUBTILE_DrawLitRleRowsClipped(nX, nY, pSrc, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 0x20, 8);
        }

        return;
    }

    if ((nLightX >> 8) == 0x1F)
    {
        CMNSUBTILE_DrawVisTile(pSrc, nX, nY);
        return;
    }

    CMNSUBTILE_DrawRleVisTile(pSrc, nX, nY, *(unsigned char*)pLight);
}

// 0x004F82D0
void __fastcall CMNSUBTILE_DrawBlendVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nAlpha)
{
    unsigned char* pDst;
    unsigned char* p;
    unsigned char* pBlend;
    if (nAlpha >= 0xC0)
        pBlend = gpPaletteTables[0];
    else if (nAlpha >= 0x80)
        pBlend = gpPaletteTables[1];
    else if (nAlpha >= 0x40)
        pBlend = gpPaletteTables[2];
    else
        return;

    if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        return;

    D2_ASSERT(gpScreenBuffer, 0x3F8);
    pDst = ganRowOffsets[nY + 32] + gpScreenBuffer + nX;
    p = pDst;
    if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch;
                p = pDst;
            }
            else
            {
                unsigned char* pEnd = pSrc + nCount;
                p += nSkip;
                while (pSrc < pEnd)
                {
                    *p = pBlend[(*p << 8) + *pSrc++];
                    ++p;
                }
            }
        }
    }
    else
    {
        int nRow = 0;
        int nRowY = nY;
        while (nRow < 0x20)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                ++nRow;
                ++nRowY;
                pDst += gnScreenPitch;
                p = pDst;
            }
            else
            {
                if (nRowY >= gnRowClipBottom)
                    return;

                p += nSkip;
                if (nRowY >= gnRowClipTop)
                {
                    unsigned char* pNextSrc = pSrc + nCount;
                    int nPosX = p - pDst + nX;
                    unsigned char* pNextDst = p + nCount;
                    // stands for the original's register use in this draw loop (blend table kept in a stack slot); without it, plain forms reassign registers from the top of the function
                    __assume(nPosX != 0x80000000);
                    nPosX = -nPosX;
                    int nLeft = gnColClipLeft + nPosX;
                    nLeft = nLeft > 0 ? nLeft : 0;
                    int nRight = gnColClipRight + nPosX;
                    nRight = nRight > 0 ? nRight : 0;
                    if (nRight >= nCount)
                        nRight = nCount;
                    const int nLength = nRight - nLeft;
                    if (nLength > 0)
                    {
                        pSrc += nLeft;
                        unsigned char* pEnd = pSrc + nLength;
                        p += nLeft;
                        while (pSrc < pEnd)
                        {
                            *p = pBlend[(*p << 8) + *pSrc];
                            ++pSrc;
                            ++p;
                        }
                    }

                    pSrc = pNextSrc;
                    p = pNextDst;
                }
                else
                {
                    p += nCount;
                    pSrc += nCount;
                }
            }
        }
    }
}

// 0x004F84F0
void __fastcall CMNSUBTILE_DrawLitBlendVisTile(unsigned char* pSrc, int nX, int nY, int* pLight, unsigned char nAlpha)
{
    unsigned char* pBlend;
    if (nAlpha >= 0xC0)
        pBlend = gpPaletteTables[0];
    else if (nAlpha >= 0x80)
        pBlend = gpPaletteTables[1];
    else if (nAlpha >= 0x40)
        pBlend = gpPaletteTables[2];
    else
        return;

    int nLightX = pLight[0] << 5;
    const int nLightXStep = pLight[3] - pLight[0];
    int nLightY = pLight[1] << 5;
    const int nLightYStep = pLight[2] - pLight[1];

    if (nY < gnClipTop || nY >= gnClipBottom || nX < gnClipLeft || nX >= gnClipRight)
        return;

    unsigned char* pBuffer = gpScreenBuffer;
    D2_ASSERT(pBuffer, 0x48B);
    unsigned char* pDst = ganRowOffsets[nY + 32] + pBuffer + nX;
    unsigned char* p = pDst;
    unsigned char* pRamp = gabLightCube[nLightX >> 8][nLightY >> 8];
    if (nY >= gnInnerTop && nY < gnInnerBottom && nX >= gnInnerLeft && nX < gnInnerRight)
    {
        int nRows = 0x20;
        while (nRows)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                --nRows;
                pDst += gnScreenPitch;
                p = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pRamp = gabLightCube[nLightX >> 8][nLightY >> 8];
            }
            else
            {
                p += nSkip;
                pRamp += nSkip;
                unsigned char* pEnd = pSrc + nCount;
                while (pSrc < pEnd)
                {
                    const unsigned char nLit = gatLightPalettes[*pRamp].colors[*pSrc];
                    ++pSrc;
                    *p = pBlend[(nLit << 8) + *p];
                    ++pRamp;
                    ++p;
                }
            }
        }
    }
    else
    {
        int nRow = 0;
        int nRowY = nY;
        while (nRow < 0x20)
        {
            int nSkip = *pSrc++;
            int nCount = *pSrc++;
            if (!nSkip && !nCount)
            {
                ++nRow;
                ++nRowY;
                pDst += gnScreenPitch;
                p = pDst;
                nLightX += nLightXStep;
                nLightY += nLightYStep;
                pRamp = gabLightCube[nLightX >> 8][nLightY >> 8];
            }
            else
            {
                if (nRowY >= gnRowClipBottom)
                    return;

                p += nSkip;
                pRamp += nSkip;
                if (nRowY >= gnRowClipTop)
                {
                    unsigned char* pNextSrc = pSrc + nCount;
                    unsigned char* pNextDst = p + nCount;
                    unsigned char* pNextRamp = pRamp + nCount;
                    const int nPosX = p - pDst + nX;
                    int nLeft = gnColClipLeft + (-nPosX);
                    nLeft = nLeft > 0 ? nLeft : 0;
                    int nRight = gnColClipRight + (-nPosX);
                    nRight = nRight > 0 ? nRight : 0;
                    if (nRight >= nCount)
                        nRight = nCount;
                    const int nLength = nRight - nLeft;
                    if (nLength > 0)
                    {
                        pSrc += nLeft;
                        unsigned char* pEnd = pSrc + nLength;
                        p += nLeft;
                        while (pSrc < pEnd)
                        {
                            const unsigned char nLit = gatLightPalettes[*pRamp].colors[*pSrc];
                            ++pSrc;
                            *p = pBlend[(nLit << 8) + *p];
                            ++pRamp;
                            ++p;
                        }
                    }

                    pSrc = pNextSrc;
                    p = pNextDst;
                    pRamp = pNextRamp;
                }
                else
                {
                    p += nCount;
                    pRamp += nCount;
                    pSrc += nCount;
                }
            }
        }
    }
}

// 0x004F8810
void __fastcall CMNSUBTILE_DrawBlock(D2TileLibraryBlockStrc* pBlock, unsigned char* pDst, unsigned char nLight)
{
    unsigned char* pPalette = gatLightPalettes[nLight >> 3].colors;
    if (pBlock->nFormat & 4)
        CMNSUBTILE_DrawRleRows(pBlock->pData, pDst, pPalette, 0xF);
    else
        CMNSUBTILE_DrawIsoBlockFlat(pBlock->pData, pDst, pPalette);
}

// 0x004F8850
void __fastcall CMNSUBTILE_DrawLitBlock(D2TileLibraryBlockStrc* pBlock, unsigned char* pDst, int* pLight)
{
    const int nLightX = pLight[0] << 4;
    const int nLightXStep = pLight[3] - pLight[0];
    const int nLightY = pLight[1] << 4;
    const int nLightYStep = pLight[2] - pLight[1];
    if (pBlock->nFormat & 4)
        CMNSUBTILE_DrawLitRleRows(pBlock->pData, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 0xF, 7);
    else
        D2GFX_DrawLitSubtileRows(pBlock->pData, pDst, nLightX, nLightXStep, nLightY, nLightYStep);
}

// 0x004F88B0
void __fastcall CMNSUBTILE_DrawBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, unsigned char nLight)
{
    unsigned char* pPalette = gatLightPalettes[nLight >> 3].colors;
    if (pBlock->nFormat & 4)
    {
        CMNSUBTILE_DrawRleRowsClipped(nX, nY, pBlock->pData, pDst, pPalette, 0xF);
        return;
    }

    const int nStartRow = D2_MAX(gnRowClipTop - nY, 0);
    const int nEndRow = D2_MIN(gnRowClipBottom - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
// build: symbol ?ganSubtileRowXOffset@* 0x0072DB48
        const int nNegX = -(nX + ganSubtileRowXOffset[i]);
        unsigned char* d = pRow + ganSubtileRowXOffset[i];
// build: symbol ?ganSubtileRowSrcOffset@* 0x0072DBC0
        unsigned char* s = pBlock->pData + ganSubtileRowSrcOffset[i];
        const int nSkipValue = D2_MAX(gnColClipLeft + nNegX, 0);
        const int nClipRight = gnColClipRight;
        const int nRight = nNegX + nClipRight;
// build: symbol ?ganSubtileRowWidth@* 0x0072DB84
        const int nWidth = ganSubtileRowWidth[i];
        int nSkip;
        nSkip = nSkipValue;
        int nCount = D2_MAX(nRight, 0);
        nCount = D2_MIN(nCount, nWidth) - nSkip;
        if (nCount > 0)
        {
            s += nSkip;
            d += nSkip;
            for (unsigned char* pEnd = s + nCount; s < pEnd; ++s, ++d)
            {
                *d = pPalette[*s];
            }
        }

        pRow += gnScreenPitch;
    }
}

static inline int ClipRowSpan(int* pnSkip, int nWidth, int nRight, int nLeft)
{
    *pnSkip = nLeft;
    int nCount = D2_MAX(nRight, 0);
    return D2_MIN(nCount, nWidth) - *pnSkip;
}

// 0x004F89F0
void __fastcall CMNSUBTILE_DrawLitBlockClipped(D2TileLibraryBlockStrc* pBlock, int nX, int nY, unsigned char* pDst, int* pLight)
{
    int nLightX = pLight[0] << 4;
    const int nLightXStep = pLight[3] - pLight[0];
    int nLightY = pLight[1] << 4;
    const int nLightYStep = pLight[2] - pLight[1];
    if (pBlock->nFormat & 4)
    {
        CMNSUBTILE_DrawLitRleRowsClipped(nX, nY, pBlock->pData, pDst, nLightX, nLightXStep, nLightY, nLightYStep, 15, 7);
        return;
    }

    const int nStartRow = D2_MAX(gnRowClipTop - nY, 0);
    const int nEndRow = D2_MIN(gnRowClipBottom - nY, 15);
    unsigned char* pRow = pDst + gnScreenPitch * nStartRow;
    for (int i = nStartRow; i < nEndRow; ++i)
    {
        const int nNegX = -(nX + ganSubtileRowXOffset[i]);
        unsigned char* pLevels = &gabLightCube[nLightX >> 7][nLightY >> 7][ganSubtileRowXOffset[i]];
        unsigned char* d = pRow + ganSubtileRowXOffset[i];
        unsigned char* s = pBlock->pData + ganSubtileRowSrcOffset[i];
        int nSkip;
        int nCount = ClipRowSpan(&nSkip, ganSubtileRowWidth[i], gnColClipRight + nNegX, D2_MAX(gnColClipLeft + nNegX, 0));
        if (nCount > 0)
        {
            s += nSkip;
            d += nSkip;
            {
                unsigned char* pEnd = s + nCount;
                while (s < pEnd)
                {
                    *d = gatLightPalettes[*pLevels].colors[*s];
                    ++s, ++d, ++pLevels;
                }
            }
        }

        pRow += gnScreenPitch;
        nLightX += nLightXStep;
        nLightY += nLightYStep;
    }
}

struct D2GfxLightExStrc
{
    unsigned char nIntensity;
    unsigned char unk0x01[0x0B];
};

// 0x004F8B80
void __fastcall CMNSUBTILE_DrawFloorTile(D2TileLibraryEntryStrc* pTile, int nX, int nY, D2GfxLightExStrc* pLight)
{
    unsigned char* pScreen = gnScreenPitch * nY + gpScreenBuffer + nX;
    for (int i = 0; i < pTile->nBlocks; ++i)
    {
        D2TileLibraryBlockStrc* pBlock = &((D2TileLibraryBlockStrc*)pTile->pBlocks)[i];
        const int nPosX = pBlock->nPosX;
        unsigned char* pDst = pBlock->nPosY * gnScreenPitch + nPosX + pScreen;
        if (!(pBlock->nFormat & 1))
            continue;
        const int nBlockX = nPosX + nX;
        const int nBlockY = nY + pBlock->nPosY;
        if (nBlockY < gnScreen_7D2330 || nBlockY >= gnScreen_7D2338 || nBlockX < gnScreen_7C9788 || nBlockX >= gnScreen_7C9798)
            continue;

        int aLight[4];
        int bFlat = 0;
        unsigned char nLight = 0;
        if (gnLightingOff)
        {
            bFlat = 1;
            nLight = pLight[8 * (pBlock->nGridY + 1) + pBlock->nGridX + 1].nIntensity;
        }
        else
        {
            // The 4x4 cells around the block, eight to a grid row. Rows 1 and 2 go into locals; rows 0 and 3 are read in the sums.
            D2GfxLightExStrc* pCell = &pLight[8 * pBlock->nGridY + pBlock->nGridX];
            const int nL01 = pCell[8].nIntensity;
            const int nL11 = pCell[9].nIntensity;
            const int nL21 = pCell[10].nIntensity;
            const int nL31 = pCell[11].nIntensity;
            const int nL02 = pCell[16].nIntensity;
            const int nL12 = pCell[17].nIntensity;
            const int nL22 = pCell[18].nIntensity;
            const int nL32 = pCell[19].nIntensity;
            int nDelta = nL21 - nL11;
            const int nDiff1 = D2_ABS(nDelta);
            nDelta = nL12 - nL11;
            const int nDiff2 = D2_ABS(nDelta);
            nDelta = nL22 - nL21;
            const int nDiff3 = D2_ABS(nDelta);
            if (!gGfxSettings.bLowQuality && nDiff3 + nDiff2 + nDiff1 >= 10)
            {
                aLight[0] = (nL12 + nL02 + nL11 + nL01) >> 2;
                aLight[1] = (pCell[1].nIntensity + pCell[2].nIntensity + nL21 + nL11) >> 2;
                aLight[2] = (nL32 + nL12 + nL31 + nL21) >> 2;
                aLight[3] = (pCell[25].nIntensity + pCell[26].nIntensity + nL22 + nL12) >> 2;
            }
            else
            {
                bFlat = 1;
                nLight = nL11;
            }
        }

        if (nBlockY >= gnInnerBlockTop && nBlockY < gnInnerBlockBottom && nBlockX >= gnInnerBlockLeft && nBlockX < gnInnerBlockRight)
        {
            if (bFlat)
                CMNSUBTILE_DrawBlock(pBlock, pDst, nLight);
            else
                CMNSUBTILE_DrawLitBlock(pBlock, pDst, aLight);
        }
        else
        {
            if (bFlat)
                CMNSUBTILE_DrawBlockClipped(pBlock, nBlockX, nBlockY, pDst, nLight);
            else
                CMNSUBTILE_DrawLitBlockClipped(pBlock, nBlockX, nBlockY, pDst, aLight);
        }
    }
}

// 0x004F8E40
void __fastcall CMNSUBTILE_SetPaletteTables(D2PaletteTableStrc* pPaletteTables)
{
    gtPaletteTables = *pPaletteTables;
    gpPaletteTables_007D5578 = &gtPaletteTables;
    for (int i = 0; i < 49; ++i)
    {
        gatLightPalettes[i] = *(D2PaletteStrc*)gtPaletteTables.pShadowLightGammaPalettes[i];
    }
}

void __fastcall WINDOW_SetScreenBuffer(unsigned char* pBuffer, int nWidth, int nHeight, int nArg4); // 0x004F8DE0

#pragma pack(push, 1)
struct d2data_0072DA60_t
{
    void (__fastcall* p0)(unsigned char* pBuffer, int nWidth, int nHeight, int nArg4);
    void (__fastcall* p1)(unsigned char* pSrc, int nX, int nY);
    void (__fastcall* p2)(unsigned char* pSrc, int nX, int nY, unsigned char nLight);
    void (__fastcall* p3)(D2TileLibraryEntryStrc* pTile, int nX, int nY, D2GfxLightExStrc* pLight);
    void (__fastcall* p4)(unsigned char* pSrc, int nX, int nY, int* pLight);
    void (__fastcall* p5)(unsigned char* pSrc, int nX, int nY, unsigned char nAlpha);
    void (__fastcall* p6)(unsigned char* pSrc, int nX, int nY, int* pLight, unsigned char nAlpha);
};
#pragma pack(pop)

extern "C" const char* gData_0072DA0C[15] = { // 0x0072DA0C
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

extern "C" unsigned char gData_0072DA48[24] = { // 0x0072DA48
    0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9B, 0x00, 0x00, 0x00,
    0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00
};
#pragma comment(linker, "/alternatename:?gGfxSettings@@3UD2GfxSettingsStrc@@A=_gData_0072DA48")

extern "C" struct d2data_0072DA60_t gData_0072DA60 = { // 0x0072DA60
    &WINDOW_SetScreenBuffer,
    &CMNSUBTILE_DrawVisTile,
    &CMNSUBTILE_DrawRleVisTile,
    &CMNSUBTILE_DrawFloorTile,
    &CMNSUBTILE_DrawLitVisTile,
    &CMNSUBTILE_DrawBlendVisTile,
    &CMNSUBTILE_DrawLitBlendVisTile
};
#pragma comment(linker, "/alternatename:?gabGraphicsHelpers@@3QBEB=_gData_0072DA60")

int gdwGlobal_0072DA7C = 1; // 0x0072DA7C

D2GraphicsInterfaceStrc* gapGraphicsInterfaces[8] = { // 0x0072DA80
    0, &gtGdiGraphicsInterface, 0, &gtDDrawGraphicsInterface,
    &gtGlideGraphicsInterface, 0, &gtD3DGraphicsInterface, 0
};

extern const char* gszDefaultClass_0072DAA0 = "Diablo II"; // 0x0072DAA0

extern "C" const char gData_0072DAA8[72] = "Error 1: Diablo II is unable to proceed.  Unsupported graphics mode."; // 0x0072DAA8
#pragma comment(linker, "/alternatename:?gszRetryUnsupportedGraphics@@3QBDB=_gData_0072DAA8")

extern "C" const char gData_0072DAF0[72] = "Error 1: Diablo II is unable to proceed.  Unsupported graphics mode."; // 0x0072DAF0
#pragma comment(linker, "/alternatename:?gszUnsupportedGraphics@@3QBDB=_gData_0072DAF0")

int gbCursorDisplayed = 1; // 0x0072DB38

extern const char* gszDefaultWindow_0072DB3C = "Diablo II"; // 0x0072DB3C

int ganSubtileRowXOffset[15] = { 14, 12, 10, 8, 6, 4, 2, 0, 2, 4, 6, 8, 10, 12, 14 }; // 0x0072DB48

int ganSubtileRowWidth[15] = { 4, 8, 12, 16, 20, 24, 28, 32, 28, 24, 20, 16, 12, 8, 4 }; // 0x0072DB84

int ganSubtileRowSrcOffset[15] = { 0, 4, 12, 24, 40, 60, 84, 112, 144, 172, 196, 216, 232, 244, 252 }; // 0x0072DBC0
