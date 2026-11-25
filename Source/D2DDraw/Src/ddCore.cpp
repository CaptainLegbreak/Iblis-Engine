#include "D2DDraw.h"
#include "D2GameTypes.h"
#include "D2GfxTypes.h"
#include "D2Win32Base.h"
#include "D2DDrawTypes.h"
#include "D2GlideTypes.h"
#include "D2Win32Types.h"
#include "D2FogSystemInfo.h"

struct D2CriticalSectionStrc;

struct D2TileLibraryEntryStrc;

struct D2GfxLightExStrc;

class D2DDrawSurfaceClass;

class D2DDrawPaletteClass;

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName); // 0x006CC0E0

extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090

extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C

extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4

extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC

extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0

extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4

extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hdc, int x, int y); // 0x006CC0B8

extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hdc, unsigned int iFirst, unsigned int iLast, int* lpBuffer); // 0x006CC0D0

extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho); // 0x006CC0D4

extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534

extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink); // 0x006CC5BC

extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0

extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink); // 0x006CC5C4

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex); // 0x005093F0

void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0

void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500

void __cdecl sub_0050BE20_GlideDebugRefresh(); // 0x0050BE20

void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x0050DBC0

void __cdecl DDCORE_ReleaseSurfaces(); // 0x00511A80

int __fastcall DDCORE_CreateSurface(void* hWnd, int nResolutionMode); // 0x005115E0

void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710

int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int bAsync, int nFlags); // 0x005FDEA0

extern "C" const char gszCourier[]; // 0x006DD52C

extern unsigned long gdwDDrawDebugFontTextColor; // 0x0072F7F0

extern int (__stdcall* gpfnGrLfbLock)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC

extern int (__stdcall* gpfnGrLfbUnlock)(int nType, int nBuffer); // 0x0087EAD8

extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4

extern void (__stdcall* gpfnGrTexDownloadTable)(int nType, void* pData); // 0x0087EB40

extern void (__stdcall* gpfnGrBufferClear)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88

extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable); // 0x0087EB8C

extern unsigned int gaGlidePalette[256]; // 0x0087EBA0

extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0

extern int gbGlidePaletteTable_0087EFC8; // 0x0087EFC8

extern int gnGlideColorCombineState; // 0x0087EFD8

extern int gnGlideAlphaCombineMode; // 0x0087EFDC

extern int gnGlideTexFilterMode; // 0x0087EFE0

extern int gbGlideDrawing; // 0x0087EFE4

extern unsigned int gnGlideBinkX; // 0x00880C08

extern D2BinkStrc* gpGlideBink; // 0x00880C0C

extern int gbGlideBinkDone; // 0x00880C18

D2DDrawSurfaceClass* gpDDrawPrimarySurface;                                                               // 0x00881278

D2DDrawPaletteClass* gpDDrawPalette;                                                                // 0x00881290

extern int gaDDrawDebugFontCharWidths[96]; // 0x00881428

extern unsigned char* gpDDrawDebugFontGlyphs; // 0x008815AC

extern unsigned int gnDDrawBinkX; // 0x008816BC

extern D2BinkStrc* gpDDrawBink; // 0x008816C0

extern int gbDDrawBinkDone; // 0x008816CC

int __fastcall DDCORE_Close(); // 0x00511B80

D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134

unsigned int gaGlideDebugLight[0x400]; // 0x0087F0D0

int gnGlideDebugX; // 0x008800D0

int gnGlideDebugY; // 0x008800D4

void** gppGlideDebugBuffer; // 0x00880454

unsigned int gnGlideBinkY; // 0x00880C04

unsigned int gnGlideBinkFlags; // 0x00880C14

int gaDDrawDebugFontGlyphOffsets[96]; // 0x008812A8

unsigned long gdwDDrawDebugFontBkColor; // 0x008815A8

unsigned int gnDDrawBinkY; // 0x008816B8

unsigned int gnDDrawBinkFlags; // 0x008816C8

class D2DDrawSurfaceClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall AddAttachedSurface(D2DDrawSurfaceClass* pSurface);
    virtual long __stdcall AddOverlayDirtyRect(void* pRect);
    virtual long __stdcall Blt(void* pDestRect, D2DDrawSurfaceClass* pSrc, void* pSrcRect, unsigned long dwFlags, void* pFx);
    virtual long __stdcall BltBatch(void* pBatch, unsigned long dwCount, unsigned long dwFlags);
    virtual long __stdcall BltFast(unsigned long dwX, unsigned long dwY, D2DDrawSurfaceClass* pSrc, void* pSrcRect, unsigned long dwTrans);
    virtual long __stdcall DeleteAttachedSurface(unsigned long dwFlags, D2DDrawSurfaceClass* pSurface);
    virtual long __stdcall EnumAttachedSurfaces(void* pContext, void* pfCallback);
    virtual long __stdcall EnumOverlayZOrders(unsigned long dwFlags, void* pContext, void* pfCallback);
    virtual long __stdcall Flip(D2DDrawSurfaceClass* pTarget, unsigned long dwFlags);
    virtual long __stdcall GetAttachedSurface(unsigned int* pCaps, D2DDrawSurfaceClass** ppSurface);
    virtual long __stdcall GetBltStatus(unsigned long dwFlags);
    virtual long __stdcall GetCaps(unsigned int* pCaps);
    virtual long __stdcall GetClipper(void** ppClipper);
    virtual long __stdcall GetColorKey(unsigned long dwFlags, void* pColorKey);
    virtual long __stdcall GetDC(void** phDC);
    virtual long __stdcall GetFlipStatus(unsigned long dwFlags);
    virtual long __stdcall GetOverlayPosition(long* pX, long* pY);
    virtual long __stdcall GetPalette(D2DDrawPaletteClass** ppPalette);
    virtual long __stdcall GetPixelFormat(void* pPixelFormat);
    virtual long __stdcall GetSurfaceDesc(D2DDSurfaceDescStrc* pDesc);
    virtual long __stdcall Initialize(void* pDirectDraw, D2DDSurfaceDescStrc* pDesc);
    virtual long __stdcall IsLost();
    virtual long __stdcall Lock(void* pRect, D2DDSurfaceDescStrc* pDesc, unsigned long dwFlags, void* hEvent);
    virtual long __stdcall ReleaseDC(void* hDC);
    virtual long __stdcall Restore();
    virtual long __stdcall SetClipper(void* pClipper);
    virtual long __stdcall SetColorKey(unsigned long dwFlags, void* pColorKey);
    virtual long __stdcall SetOverlayPosition(long nX, long nY);
    virtual long __stdcall SetPalette(D2DDrawPaletteClass* pPalette);
    virtual long __stdcall Unlock(void* pRect);
};

class D2DirectDrawClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall Compact();
    virtual long __stdcall CreateClipper(unsigned long dwFlags, void** ppClipper, void* pUnkOuter);
    virtual long __stdcall CreatePalette(unsigned int dwFlags, tagPALETTEENTRY* pEntries, D2DDrawPaletteClass** ppPalette, void* pUnkOuter);
    virtual long __stdcall CreateSurface(D2DDSurfaceDescStrc* pDesc, D2DDrawSurfaceClass** ppSurface, void* pUnkOuter);
    virtual long __stdcall DuplicateSurface(D2DDrawSurfaceClass* pSurface, D2DDrawSurfaceClass** ppDuplicate);
    virtual long __stdcall EnumDisplayModes(unsigned long dwFlags, D2DDSurfaceDescStrc* pDesc, void* pContext, void* pfCallback);
    virtual long __stdcall EnumSurfaces(unsigned long dwFlags, D2DDSurfaceDescStrc* pDesc, void* pContext, void* pfCallback);
    virtual long __stdcall FlipToGDISurface();
    virtual long __stdcall GetCaps(void* pDriverCaps, void* pHelCaps);
    virtual long __stdcall GetDisplayMode(D2DDSurfaceDescStrc* pDesc);
    virtual long __stdcall GetFourCCCodes(unsigned long* pCount, unsigned long* pCodes);
    virtual long __stdcall GetGDISurface(D2DDrawSurfaceClass** ppSurface);
    virtual long __stdcall GetMonitorFrequency(unsigned long* pFrequency);
    virtual long __stdcall GetScanLine(unsigned long* pScanLine);
    virtual long __stdcall GetVerticalBlankStatus(int* pIsInVB);
    virtual long __stdcall Initialize(void* pGuid);
    virtual long __stdcall RestoreDisplayMode();
    virtual long __stdcall SetCooperativeLevel(void* hWnd, unsigned int dwFlags);
    virtual long __stdcall SetDisplayMode(unsigned int dwWidth, unsigned int dwHeight, unsigned int dwBpp);
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode);                                             // 0x00511DF0

int gbDDrawReady;                                                                                  // 0x00881264

int gbDDrawReady2;                                                                                 // 0x00881268

extern int gaDDrawModeWidth[4];                                                                    // 0x0072F7A8

extern int gaDDrawModeHeight[4];                                                                   // 0x0072F7B8

int gnDDrawBackBuffers;                                                                            // 0x00881294

D2DirectDrawClass* gpDirectDraw;                                                                   // 0x00881270

D2DDrawSurfaceClass* gpDDrawBackSurface;                                                      // 0x0088127C

D2DDrawSurfaceClass* gpDDrawOffscreenSurface;                                                              // 0x00881280

extern tagPALETTEENTRY gatGamePalette[256];                                                     // 0x007C8CC8

static int gnScreenWidth2;                                                                         // 0x00881258

static int gnScreenHeight2;                                                                        // 0x00881254

unsigned char gabPaletteEntries[1];                                                                  // 0x007C8CCC

static int gbPaletteDirty;                                                                         // 0x00881298

class D2DDrawPaletteClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
    virtual long __stdcall GetCaps(unsigned long* pCaps);
    virtual long __stdcall GetEntries(unsigned long dwFlags, unsigned long dwBase, unsigned long dwCount, void* pEntries);
    virtual long __stdcall Initialize(void* pDirectDraw, unsigned long dwFlags, void* pEntries);
    virtual long __stdcall SetEntries(unsigned long dwFlags, unsigned long dwStartingEntry, unsigned long dwCount, void* pEntries);
};

class D2DDrawObjectClass
{
public:
    virtual long __stdcall QueryInterface(const void* pIid, void** ppObject);
    virtual unsigned long __stdcall AddRef();
    virtual unsigned long __stdcall Release();
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210

extern "C" long __stdcall DirectDrawCreate(void* pGuid, D2DirectDrawClass** ppDirectDraw, void* pUnkOuter); // 0x006B1350

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)());                                                   // 0x00683824

int __cdecl DDCORE_SetDisplayMode();                                                                  // 0x005114D0

void __cdecl DDCORE_CloseAtExit();                                                               // 0x00511CD0

void __cdecl DDDEBUGFONT_CreateDebugFont();                                                           // 0x00512430

void __cdecl DDDEBUGFONT_FreeDebugFont();                                                             // 0x005125B0

extern "C" const char gszDirectDrawCreateFailed[];                                                  // 0x006DE1B4

unsigned char gabDDrawDeviceGuid[16];                                                              // 0x00881144

int gbDDrawInitialized;                                                                            // 0x00881260

D2DDrawObjectClass* gpDDrawObject;                                                                 // 0x00881274

int __fastcall DDCORE_Blit();                                                                     // 0x00511870

void __fastcall sub_00512ED0_ClearScreen(int bPartial);                                                     // 0x00512ED0

extern int gaDDrawCapsTypes[8];                                                                    // 0x0072F7D0

D2PaletteTableStrc* gpGfxPaletteView;                                                                      // 0x007C9150

void* gpDDrawSmackBuffer;                                                                          // 0x008816B0

int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, void* pBuffer, unsigned int nBufferSize, unsigned int* pnBytesRead); // 0x00414DE0

int gbDDrawPlatformFlag; // 0x0088125C

char gszDDrawDeviceName[256]; // 0x00881154

D2FogSystemInfoStrc* __cdecl FOG_GetSystemInfo(); // 0x00407360

void __fastcall GLCORE_SetPalette(const tagPALETTEENTRY* pPalette); // 0x00509300

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2FogSystemInfoStrc;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall EXCEL_BuildGammaTable(int nGamma, void* pTable, double dScale, int nArg, int nEntries, int nMask); // 0x006BE190

unsigned long gdwVideoFlags; // 0x00881140

tagPALETTEENTRY gaDDrawSavedPalette[256]; // 0x00880D40

void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x0050C0F0

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50

void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor);                     // 0x00512D90

void __fastcall DDSMACK_CloseSmacker(D2SmackRecordStrc* pRecord);                                      // 0x00513330

// 0x00510020
int __fastcall DDCORE_Detect(void* hInstance)
{
    D2FogSystemInfoStrc* pSystemInfo = FOG_GetSystemInfo();
    D2_ASSERT(pSystemInfo, 0x6F);

    if (pSystemInfo->nOsKind == 1)
    {
        gbDDrawPlatformFlag = 1;
    }

    char szKey[] = "Diablo II\\VideoConfig";
    if (SRegLoadString(szKey, "DeviceName", 0, gszDDrawDeviceName, sizeof(gszDDrawDeviceName))
// build: symbol ?gdwVideoFlags@* 0x00881140
        && SRegLoadValue(szKey, "dwFlags", 0, &gdwVideoFlags))
    {
        if (gdwVideoFlags & gdwBitMasks[0])
        {
            return 1;
        }

        unsigned int nSize = sizeof(gabDDrawDeviceGuid);
        if (SRegLoadData(szKey, "GUID", 0, gabDDrawDeviceGuid, sizeof(gabDDrawDeviceGuid), &nSize)
            && nSize == sizeof(gabDDrawDeviceGuid))
        {
            return 1;
        }
    }

    strcpy(gszDDrawDeviceName, "Fallback DirectDraw Device");
    gdwVideoFlags = gdwBitMasks[0];
    return 1;
}

// 0x00510160
void __fastcall DDCORE_SetPalette(tagPALETTEENTRY* pPalette)
{
    memcpy(gaDDrawSavedPalette, pPalette, sizeof(gaDDrawSavedPalette));

    unsigned char abGamma[256];
// build: symbol ?gnDDrawGammaScale@* 0x0072F7C8
// build: symbol ?gnDDrawGamma@* 0x0072F7CC
    EXCEL_BuildGammaTable(gnDDrawGamma, abGamma, gnDDrawGammaScale, 1, 256, 0xFF);
    for (int i = 0; i < 256; ++i)
    {
        gatGamePalette[i].peRed = abGamma[gaDDrawSavedPalette[i].peRed];
        gatGamePalette[i].peGreen = abGamma[gaDDrawSavedPalette[i].peGreen];
        gatGamePalette[i].peBlue = abGamma[gaDDrawSavedPalette[i].peBlue];
    }

    gbPaletteDirty = 1;
}

// 0x00511210
static int DDCORE_OpenSurfaces(int nResolutionMode)
{
    D2_ASSERT(!gbDDrawReady, 0x142);
    if (!nResolutionMode)
    {
// build: symbol ?gnRenderWidth@* 0x007C9138
        gnRenderWidth = 640;
// build: symbol ?gnRenderHeight@* 0x007C913C
        gnRenderHeight = 480;
    }
    else
    {
        gnRenderWidth = 800;
        gnRenderHeight = 600;
    }
    sub_00511DF0_DDrawSetMode(nResolutionMode);
    gnScreenWidth2 = gaDDrawModeWidth[nResolutionMode];
    gnScreenHeight2 = gaDDrawModeHeight[nResolutionMode];

    long hResult = gpDirectDraw->SetCooperativeLevel(ghDDrawWindow_007C9140, 0x11);
    if (hResult && hResult != 0x88760245)
    {
        sub_005103B0("SetCooperativeLevel failed!", hResult);
        return 0;
    }

    D2_ASSERT(gpDirectDraw, 0x1DA);
    const char* szError;
    hResult = gpDirectDraw->SetDisplayMode(gnScreenWidth2, gnScreenHeight2, 8);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    D2DDSurfaceDescStrc desc;
    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    desc.dwFlags = 0x21;
    desc.dwCaps = 0x4218;
    gnDDrawBackBuffers = desc.dwBackBufferCount = 2;
    if (gpDirectDraw->CreateSurface(&desc, &gpDDrawPrimarySurface, 0))
    {
        memset(&desc, 0, sizeof(desc));
        desc.dwSize = sizeof(desc);
        desc.dwFlags = 0x21;
        desc.dwCaps = 0x4218;
        gnDDrawBackBuffers = desc.dwBackBufferCount = 1;
        if (gpDirectDraw->CreateSurface(&desc, &gpDDrawPrimarySurface, 0))
        {
            memset(&desc, 0, sizeof(desc));
            desc.dwSize = sizeof(desc);
            desc.dwFlags = 1;
            desc.dwCaps = 0x4200;
            gnDDrawBackBuffers = 0;
            hResult = gpDirectDraw->CreateSurface(&desc, &gpDDrawPrimarySurface, 0);
            if (hResult)
            {
                szError = "CreateSurface (primary single buffered) failed!";
                goto fail;
            }
        }
    }

    if (gnDDrawBackBuffers)
    {
        unsigned int dwCaps = 4;
        hResult = gpDDrawPrimarySurface->GetAttachedSurface(&dwCaps, &gpDDrawBackSurface);
        if (hResult)
        {
            szError = "GetAttachedSurface (backbuffer) failed!";
            goto fail;
        }
    }

    memset(&desc, 0, sizeof(desc));
    desc.dwSize = sizeof(desc);
    hResult = gpDDrawPrimarySurface->GetSurfaceDesc(&desc);
    if (hResult)
    {
        szError = "GetSurfaceDesc (primary) failed!";
        goto fail;
    }

    desc.dwFlags = 7;
    desc.dwCaps = 0x840;
    hResult = gpDirectDraw->CreateSurface(&desc, &gpDDrawOffscreenSurface, 0);
    if (hResult)
    {
        szError = "CreateSurface (render) failed!";
        goto fail;
    }

    hResult = gpDDrawPrimarySurface->SetPalette(gpDDrawPalette);
    if (hResult)
    {
        szError = "SetPalette failed!";
        goto fail;
    }

    gbDDrawReady = 1;
    gbDDrawReady2 = 0;
    return 1;

fail:
    sub_005103B0(szError, hResult);
    LOGMANAGER_WriteLogLine("Opening DirectDraw window failed!");
    return 0;
}

// 0x005114D0
int __cdecl DDCORE_SetDisplayMode()
{
    D2_ASSERT(!gbDDrawReady, 0x26A);

    gnRenderWidth = 640;
    gnScreenWidth2 = 640;
    gnRenderHeight = 480;
    gnScreenHeight2 = 480;

    int nBpp = 16;
    if (gdwVideoFlags & gdwBitMasks[1])
    {
        nBpp = 32;
    }
    else if (gdwVideoFlags & gdwBitMasks[2])
    {
        nBpp = 24;
    }

    const char* szError;
    long hResult = gpDirectDraw->SetDisplayMode(640, 480, nBpp);
    if (hResult)
    {
        szError = "SetDisplayMode failed!";
        goto fail;
    }

    {
        D2DDSurfaceDescStrc tSurfaceDesc = { sizeof(D2DDSurfaceDescStrc) };
        tSurfaceDesc.dwFlags = 1;
        tSurfaceDesc.dwCaps = 0x4200;
        hResult = gpDirectDraw->CreateSurface(&tSurfaceDesc, &gpDDrawPrimarySurface, 0);
    }

    if (hResult)
    {
        szError = "Failed to create primary surface for cutscenes";
fail:
        sub_005103B0(szError, hResult);
        LOGMANAGER_WriteLogLine("Opening DirectDraw window for cutscenes failed!");
        return 0;
    }

    gbDDrawReady = 1;
    gbDDrawReady2 = 1;
    return 1;
}

// 0x005115E0
int __fastcall DDCORE_CreateSurface(void* hWnd, int nResolutionMode)
{
    ghDDrawWindow_007C9140 = hWnd;
    long hResult = gpDirectDraw->SetCooperativeLevel(hWnd, 0x11);
    if (hResult)
    {
        sub_005103B0("SetCooperativeLevel failed!", hResult);
        return 0;
    }
    memset(gatGamePalette, 0, sizeof(gatGamePalette));
    hResult = gpDirectDraw->CreatePalette(4, gatGamePalette, &gpDDrawPalette, 0);
    if (hResult)
    {
        sub_005103B0("CreatePalette failed!", hResult);
        return 0;
    }
    return DDCORE_OpenSurfaces(nResolutionMode);
}

int gbDDrawPlayingVideo; // 0x0088126C

void __fastcall DDCORE_DDrawLogError(const char* szWhere, int hResult); // 0x005103B0
void __fastcall DDCORE_PlayBinkMovie(const char* szFile, int nMode, void (__cdecl* pfCallback)()); // 0x005137E0

// 0x00511660
void __fastcall DDRAW_OpenSmackCutscene(const char* szFile, int nResolutionMode, void (__cdecl* pfFrame)())
{
    if (!gbRenderPaused)
    {
        gbDDrawPlayingVideo = 1;
        D2DDBltFxStrc tBltFx = { sizeof(tBltFx) };
        tBltFx.dwFillColor = 0;
// build: symbol ?gpDDrawPrimarySurface@* 0x00881278
        D2_ASSERT(gpDDrawPrimarySurface, 0x387);

        const long hResult = gpDDrawPrimarySurface->Blt(0, 0, 0, 0x400, &tBltFx);
        if (hResult)
        {
            DDCORE_DDrawLogError("Cutscene clearing blit failed!", hResult);
            return;
        }

        DDCORE_PlayBinkMovie(szFile, nResolutionMode, pfFrame);
        gbDDrawPlayingVideo = 0;
    }
}

// 0x00511720
int __fastcall DDCORE_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    if (gbRenderPaused)
        return 0;

    D2_ASSERT(gpRenderCriticalSection, 0x3BF);
    EnterCriticalSection(gpRenderCriticalSection);
    sub_00512ED0_ClearScreen(1);
    D2DDSurfaceDescStrc tDesc = { sizeof(tDesc) };
    long nResult = gpDDrawOffscreenSurface->Lock(0, &tDesc, 0x21, 0);
    if (nResult)
    {
        sub_005103B0("Lock failed!", nResult);
        LeaveCriticalSection(gpRenderCriticalSection);
        return 0;
    }
    gpScreenBuffer_007C9154 = (unsigned char*)tDesc.lpSurface;
    gnRenderWidth = tDesc.lPitch;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable((unsigned char*)tDesc.lpSurface, tDesc.lPitch, gnRenderHeight, 0);
    return 1;
}

// 0x005117F0
int __fastcall DDCORE_EndDraw()
{
    long hResult = gpDDrawOffscreenSurface->Unlock(0);
    if (hResult)
    {
        sub_005103B0("Unlock failed!", hResult);
        return 0;
    }

    gpScreenBuffer_007C9154 = 0;
    gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
    D2_ASSERT(gpRenderCriticalSection, 1036);
    LeaveCriticalSection(gpRenderCriticalSection);
    return 1;
}

// 0x00511870
int __fastcall DDCORE_Blit()
{
    if (gnDDrawBackBuffers)
    {
        if (gpDDrawOffscreenSurface && gpDDrawBackSurface && gpDDrawOffscreenSurface != gpDDrawBackSurface)
        {
            tagRECT tRect;
            tRect.left = 0;
            tRect.top = 0;
            tRect.right = gnRenderWidth;
            tRect.bottom = gnRenderHeight;
            const long hResult = gpDDrawBackSurface->BltFast(0, 0, gpDDrawOffscreenSurface, &tRect, 0x10);
            if (hResult)
            {
                sub_005103B0("BltFast failed!", hResult);
                return 0;
            }
        }

        gpDDrawPrimarySurface->Flip(0, 1);
    }
    else if (gpDDrawOffscreenSurface)
    {
        tagRECT tRect;
        tRect.left = 0;
        tRect.top = 0;
        tRect.right = gnRenderWidth;
        tRect.bottom = gnRenderHeight;
        const long hResult = gpDDrawPrimarySurface->BltFast(0, 0, gpDDrawOffscreenSurface, &tRect, 0x10);
        if (hResult)
        {
            sub_005103B0("BltFast failed!", hResult);
            return 0;
        }
    }

    if (gbPaletteDirty && gpDDrawPalette)
    {
        gbPaletteDirty = 0;
        const long hResult = gpDDrawPalette->SetEntries(0, 1, 0xFF, gabPaletteEntries);
        if (hResult)
        {
            sub_005103B0("SetEntries failed!", hResult);
            return 0;
        }
    }

    return 1;
}

// 0x00511970
int __fastcall DDRAW_GetBackBuffer(unsigned char* pBuffer)
{
    D2DDSurfaceDescStrc tDesc = { sizeof(tDesc) };
    if (!gpDDrawBackSurface)
    {
        return 0;
    }

    long hResult = gpDDrawBackSurface->Lock(0, &tDesc, 0x11, 0);
    if (hResult)
    {
        DDCORE_DDrawLogError("Lock failed!", hResult);
        return 0;
    }

    unsigned char* pDstRow = pBuffer;
    unsigned char* pSrcRow = (unsigned char*)tDesc.lpSurface;
    for (int y = 0; y < gnRenderHeight; ++y)
    {
        unsigned char* pSrc = pSrcRow;
        unsigned char* pDst = pDstRow;
        for (int x = 0; x < gnRenderWidth; ++x)
        {
            const tagPALETTEENTRY* pEntry = &gatGamePalette[*pSrc];
            *pDst = pEntry->peRed;
            ++pDst;
            *pDst = pEntry->peGreen;
            ++pDst;
            *pDst = pEntry->peBlue;
            ++pSrc;
            ++pDst;
        }

        pDstRow += 3 * gnRenderWidth;
        pSrcRow += tDesc.lPitch;
    }

    hResult = gpDDrawBackSurface->Unlock(0);
    if (hResult)
    {
        DDCORE_DDrawLogError("Unlock failed!", hResult);
        return 0;
    }

    return 1;
}

// 0x00511A80
void __cdecl DDCORE_ReleaseSurfaces()
{
    if (gbDDrawReady)
    {
        for (int i = 0; i < 3; ++i)
        {
            sub_00512ED0_ClearScreen(0);
            DDCORE_Blit();
        }
        if (gpDDrawOffscreenSurface)
        {
            gpDDrawOffscreenSurface->Release();
            gpDDrawOffscreenSurface = 0;
        }
        if (gpDDrawBackSurface)
        {
            gpDDrawBackSurface->Release();
            gpDDrawBackSurface = 0;
        }
        if (gpDDrawPrimarySurface)
        {
            gpDDrawPrimarySurface->Release();
            gpDDrawPrimarySurface = 0;
        }
        gpTileDrawFunctions_007C914C->pfFillYBufferTable(0, 0, 0, 0);
        gbDDrawReady = 0;
        gbDDrawReady2 = 0;
    }
}

// 0x00511B10
int __fastcall DDCORE_PlayCutscene()
{
    if (gbRenderPaused)
    {
        return 0;
    }

    DDCORE_ReleaseSurfaces();
    return DDCORE_SetDisplayMode();
}

// 0x00511B30
int __fastcall DDCORE_CloseSurface()
{
    DDCORE_ReleaseSurfaces();
    if (gpDDrawPalette)
    {
        gpDDrawPalette->Release();
        gpDDrawPalette = 0;
    }
    ghDDrawWindow_007C9140 = 0;
    return 1;
}

// 0x00511B60
int __fastcall DDCORE_ChangeRes(void* hWnd, int nResolutionMode)
{
    if (!gbRenderPaused)
    {
        DDCORE_ReleaseSurfaces();
        return DDCORE_OpenSurfaces(nResolutionMode);
    }
    return 1;
}

// 0x00511B80
int __fastcall DDCORE_Close()
{
    if (gbDDrawInitialized)
    {
        DDCORE_ReleaseSurfaces();
        if (gpDDrawPalette)
        {
            gpDDrawPalette->Release();
            gpDDrawPalette = 0;
        }
        ghDDrawWindow_007C9140 = 0;
        if (gpDDrawObject)
        {
            gpDDrawObject->Release();
            gpDDrawObject = 0;
        }
        if (gpDirectDraw)
        {
            gpDirectDraw->Release();
            gpDirectDraw = 0;
        }
        if (gpRenderCriticalSection)
        {
            DeleteCriticalSection(gpRenderCriticalSection);
            FOG_Free(gpRenderCriticalSection, ".\\Src\\ddCore.cpp", 293, 0);
            gpRenderCriticalSection = 0;
        }
        DDDEBUGFONT_FreeDebugFont();
        gbDDrawInitialized = 0;
    }
    return 1;
}

// 0x00511C20
void __fastcall DDCORE_PauseSurface(void* hWnd, int nResolutionMode, int nWindowState)
{
    D2_ASSERT(gpRenderCriticalSection, 0x2F7);
    EnterCriticalSection(gpRenderCriticalSection);
    if (nWindowState)
    {
        gbRenderPaused = 1;
        DDCORE_ReleaseSurfaces();
        if (gpDDrawPalette)
        {
            gpDDrawPalette->Release();
            gpDDrawPalette = 0;
        }
        gbSurfaceActive_007C9140 = 0;
    }
    else
    {
        gbRenderPaused = 0;
        DDCORE_CreateSurface(hWnd, nResolutionMode);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
}

// 0x00511CD0
void __cdecl DDCORE_CloseAtExit()
{
    DDCORE_Close();
}

// 0x00511CE0
int __fastcall DDCORE_Init(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pHelpers)
{
// build: symbol ?gpGfxSettings@* 0x007C9148
    gpGfxSettings = pSettings;
    gpTileDrawFunctions_007C914C = pHelpers;
    DDDEBUGFONT_CreateDebugFont();
    long hResult;
    if (gdwVideoFlags & gdwBitMasks[0])
    {
        hResult = DirectDrawCreate(0, &gpDirectDraw, 0);
    }
    else
    {
        hResult = DirectDrawCreate(gabDDrawDeviceGuid, &gpDirectDraw, 0);
    }

    if (hResult)
    {
        sub_005103B0(gszDirectDrawCreateFailed, hResult);
        return 0;
    }

    atexit(DDCORE_CloseAtExit);
    gbDDrawInitialized = 1;
    gpRenderCriticalSection = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\ddCore.cpp", 246, 0);
    InitializeCriticalSection(gpRenderCriticalSection);
    return 1;
}

// 0x00511D70
int __fastcall DDCORE_GetDrawModePalette(int nIndex, int* pType)
{
    *pType = gaDDrawCapsTypes[nIndex];
    switch (nIndex)
    {
    case 0:
        return (int)gpGfxPaletteView->pTransPalettes[2];
    case 1:
        return (int)gpGfxPaletteView->pTransPalettes[1];
    case 2:
        return (int)gpGfxPaletteView->pTransPalettes[0];
    case 3:
        return (int)gpGfxPaletteView->pScreenPalette;
    case 4:
        return (int)gpGfxPaletteView->pLuminancePalette;
    case 6:
        return (int)gpGfxPaletteView->pDarkBlendPalette;
    }
    return 0;
}

// 0x005126F0
void __stdcall DDRAW_DebugDraw(int nUnused1, int nUnused2)
{
}

// 0x00512700
int __cdecl DDCORE_GetBlendedShadows()
{
    return gpGfxSettings->bBlendedShadows;
}

// 0x005128B0
void __fastcall DDCORE_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha)
{
    int nDrawMode;
    if (nAlpha >= 0xC0)
        nDrawMode = 5;
    else if (nAlpha >= 0x80)
        nDrawMode = 2;
    else if (nAlpha >= 0x40)
        nDrawMode = 1;
    else if (nAlpha > 0)
        nDrawMode = 0;
    else
        return;
    sub_00512710_DDrawDrawBox(nXStart, nYStart, nXEnd, nYEnd, dwColor, nDrawMode);
}

// 0x00512900
void __fastcall DDCORE_SetPixel(int nX, int nY, unsigned char nColor)
{
    if (nX >= 0 && nX < gnRenderWidth && nY >= 0 && nY < gnRenderHeight)
        gpScreenBuffer_007C9154[gnRenderWidth * nY + nX] = nColor;
}

// 0x00512E80
void __fastcall DDCORE_UtilPoint(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex)
{
    if (nSize)
    {
        --nSize;
        tagRECT tRect;
        SetRect(&tRect, pPoint->x - nSize, pPoint->y - nSize, pPoint->x + nSize + 1, pPoint->y + nSize + 1);
        sub_00512D90_DDrawUtilFilledRect(&tRect, nPaletteIndex);
    }
}

// 0x005132C0
int __fastcall DDCORE_FloorTileDraw(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData)
{
    int nResult = D2CMPTileValidate(pTile, 1, 0);
    if (nResult)
    {
        nPosX -= 0x50;
        switch (nScreenPanels)
        {
        case 1:
            nPosX -= gnRenderWidth / 4;
            break;
        case 2:
            nPosX += gnRenderWidth / 4;
            break;
        }
        nResult = gpTileDrawFunctions_007C914C->pfDrawFloorTile(pTile, nPosX, nPosY, pLight);
    }
    return nResult;
}

// 0x005136F0
void __cdecl DDRAW_DrawVideoFrame()
{
    if (!gbSurfaceActive_007C9140)
        return;
    BinkDoFrame(gpDDrawBink);
    D2_ASSERT(gpRenderCriticalSection, 0x42);
    EnterCriticalSection(gpRenderCriticalSection);
    D2DDSurfaceDescStrc ddsd = { sizeof(D2DDSurfaceDescStrc) };
    if (gpDDrawPrimarySurface->Lock(0, &ddsd, 0x21, 0) == 0)
    {
        BinkCopyToBuffer(gpDDrawBink, ddsd.lpSurface, ddsd.lPitch, gpDDrawBink->nHeight, gnDDrawBinkX, gnDDrawBinkY, gnDDrawBinkFlags);
        gpDDrawPrimarySurface->Unlock(0);
    }
    LeaveCriticalSection(gpRenderCriticalSection);
    if (gpDDrawBink->nFrameNum == gpDDrawBink->nFrames)
    {
        gbDDrawBinkDone = 1;
        return;
    }
    BinkNextFrame(gpDDrawBink);
}

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const tagMSG* pMsg); // 0x006CC478
int __cdecl FOG_UseDirect(); // 0x00406D20
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax, unsigned int wRemoveMsg); // 0x006CC480
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const tagMSG* pMsg); // 0x006CC47C

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2DDrawSurfaceStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall GLCORE_SetTextureCombineMode(int nTmu); // 0x00509460

void __fastcall GLSUBTILECACHE_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex); // 0x0050F0F0

short __fastcall GLSUBTILECACHE_TileCacheAdd(D2GlideTileCacheStrc* pCache); // 0x0050F2B0

extern D2GrTexInfoStrc gtGlideTileTexInfo; // 0x0072F6A8

extern D2GlideTileCacheStrc gtGlideTileCache; // 0x0087EB48

extern int gnGlideTileTmu; // 0x00880BF8

extern unsigned char* gpGlideTileDecodeBuffer; // 0x00880BFC

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) D2BinkStrc* __stdcall BinkOpen(void* hFile, unsigned int nFlags); // 0x006CC5B8

extern "C" __declspec(dllimport) int __stdcall BinkWait(D2BinkStrc* pBink); // 0x006CC5C8

extern "C" __declspec(dllimport) void __stdcall BinkClose(D2BinkStrc* pBink); // 0x006CC5CC

extern "C" __declspec(dllimport) unsigned int __stdcall BinkDDSurfaceType(D2DDrawSurfaceClass* pSurface); // 0x006CC5D0

extern "C" __declspec(dllimport) int __stdcall BinkSetSoundSystem(void* pfOpen, unsigned long nParam); // 0x006CC5D4

extern "C" __declspec(dllimport) void* __stdcall BinkOpenDirectSound(unsigned long nParam); // 0x006CC5D8

int __stdcall SFileOpenFileEx(unsigned int hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0

void __cdecl GLIDE_DrawVideoFrame(); // 0x0050FD10

void __cdecl DDRAW_DrawVideoFrame(); // 0x005136F0

void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0

extern int gnRenderHeight; // 0x007C913C

extern unsigned int gnGlideBinkY; // 0x00880C04

extern unsigned int gnGlideBinkFlags; // 0x00880C14

extern unsigned int gnDDrawBinkY; // 0x008816B8

extern unsigned int gnDDrawBinkFlags; // 0x008816C8

void __fastcall DDCORE_SetPalette(tagPALETTEENTRY* pPalette); // 0x00510160

extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150

extern tagPALETTEENTRY gaDDrawSavedPalette[256]; // 0x00880D40

unsigned int gnDDrawBinkX; // 0x008816BC

D2BinkStrc* gpDDrawBink; // 0x008816C0

int gbDDrawBinkDone; // 0x008816CC

int gbDDrawBinkQuit; // 0x008816D0

unsigned long gdwDDrawBinkAbortTick; // 0x008816D4


// 0x00510140
int __cdecl DDRAW_CheckCutScene()
{
    return gbDDrawPlayingVideo;
}

// 0x00510320
void __stdcall DDRAW_SetAmbientColor(int nUnused1)
{
}

// 0x00510370
int __cdecl DDRAW_GetCacheResults()
{
    return 0;
}

// 0x00510380
int __cdecl DDRAW_ActivateWindow()
{
    return 0;
}

// 0x005137E0
void __fastcall DDCORE_PlayBinkMovie(const char* szFile, int nMode, void (__cdecl* pfCallback)())
{
    int bAbort = 0;
    gbDDrawBinkDone = 0;
    if (gpDDrawBink)
    {
        return;
    }
    if (gbRenderPaused)
    {
        return;
    }

    gnDDrawBinkFlags = BinkDDSurfaceType(gpDDrawPrimarySurface);
    BinkSetSoundSystem(BinkOpenDirectSound, 0);
    int nScope = 4;
    if (FOG_UseDirect())
    {
        nScope = 5;
    }

    void* hFile;
    SFileOpenFileEx(0, szFile, nScope, &hFile);
    if (!hFile)
    {
        goto OpenFailed;
    }

    unsigned int nFlags;
    nFlags = 0x800000;
    switch (nMode)
    {
    case 1:
        nFlags = 0x30800000;
        break;
    case 2:
        nFlags = 0x10800000;
        break;
    case 3:
        nFlags = 0x40800000;
        break;
    }
    gpDDrawBink = BinkOpen(hFile, nFlags);
    if (!gpDDrawBink)
    {
        CloseHandle(hFile);
OpenFailed:
        if (gpDDrawBink)
        {
            BinkClose(gpDDrawBink);
            gpDDrawBink = 0;
        }
        return;
    }

    gnDDrawBinkX = (gnRenderWidth - gpDDrawBink->nWidth) >> 1;
    if (gnDDrawBinkX & 3)
    {
        gnDDrawBinkX = (gnDDrawBinkX | 3) + 1;
    }
    gnDDrawBinkY = (gnRenderHeight - gpDDrawBink->nHeight) >> 1;
    {
        const unsigned long dwEnd = GetTickCount() + 500;
        for (;;)
        {
            if (gbDDrawBinkDone && GetTickCount() >= dwEnd)
            {
                break;
            }
            if (gbRenderPaused)
            {
                break;
            }
            if (pfCallback)
            {
                pfCallback();
            }
            if (bAbort)
            {
                break;
            }

            tagMSG tMsg;
            if (PeekMessageA(&tMsg, 0, 0, 0, 1))
            {
                switch (tMsg.message)
                {
                case 0x12:
                    gbDDrawBinkDone = 1;
                    gbDDrawBinkQuit = 1;
                    break;
                case 0x102:
                case 0x201:
                case 0x204:
                case 0x207:
                    bAbort = 1;
                    gdwDDrawBinkAbortTick = GetTickCount();
                    break;
                }
                TranslateMessage(&tMsg);
                DispatchMessageA(&tMsg);
            }
            else if (!BinkWait(gpDDrawBink))
            {
                DDRAW_DrawVideoFrame();
            }
            else
            {
                Sleep(1);
            }
        }
    }

    if (gpDDrawBink)
    {
        D2SOUNDSMP_SetMasterVolume(0);
        BinkClose(gpDDrawBink);
        CloseHandle(hFile);
        D2SOUNDSMP_SetMasterVolume(0xFF);
        gpDDrawBink = 0;
    }
    if (gbDDrawBinkQuit)
    {
        exit(-1);
    }
}

// 0x00510130
void __fastcall DDCORE_ClearCaches()
{
}

// 0x005102F0
void __fastcall DDCORE_SetGlobalScale()
{
}

// 0x00510330
void __fastcall DDCORE_UpdatePerspective()
{
}

// 0x00510340
void __fastcall DDCORE_PerspectiveTransform(int nPosX, int nPosY, int nBias, int* pXAdjust, int* pYAdjust)
{
}

// 0x00510350
void __fastcall DDCORE_PerspectiveTransformScale(int nPosX, int nPosY, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder)
{
}

// 0x00510360
void __fastcall DDCORE_PerspectiveClearScale()
{
}

D2PaletteTableStrc gtDDrawPaletteView; // 0x00880C20

// 0x00510150
void __fastcall DDCORE_GetDimensions(int* pWidth, int* pHeight)
{
    *pWidth = gnRenderWidth;
    *pHeight = gnRenderHeight;
}

// 0x005102D0
void __fastcall DDCORE_SetPaletteTables(D2PaletteTableStrc* pSource)
{
    gtDDrawPaletteView = *pSource;
    gpGfxPaletteView_007C9150 = &gtDDrawPaletteView;
}

// 0x00510300
void __fastcall DDCORE_SetGamma(int nGamma)
{
// build: symbol ?gnDDrawGamma@* 0x0072F7CC
    gnDDrawGamma = nGamma;
    DDCORE_SetPalette(gaDDrawSavedPalette);
}

// 0x00510390
int __fastcall DDCORE_SetOption(int nOption, int nValue)
{
    switch (nOption)
    {
    case 11:
// build: symbol ?gnDDrawGammaScale@* 0x0072F7C8
        gnDDrawGammaScale = nValue;
        return 1;
    }
    return 0;
}

// 0x005103B0
void __fastcall DDCORE_DDrawLogError(const char* szWhere, int hResult)
{
    if (hResult == (int)0x887601AE || hResult == (int)0x887601C2)
    {
        return;
    }

    const char* szError;
    switch (hResult)
    {
    case (int)0x80004005: szError = "DDERR_GENERIC"; break;
    case (int)0x80004001: szError = "DDERR_UNSUPPORTED"; break;
    case (int)0x800401F0: szError = "DDERR_NOTINITIALIZED"; break;
    case (int)0x80070057: szError = "DDERR_INVALIDPARAMS"; break;
    case (int)0x8007000E: szError = "DDERR_OUTOFMEMORY"; break;
    case (int)0x88760005: szError = "DDERR_ALREADYINITIALIZED"; break;
    case (int)0x8876000A: szError = "DDERR_CANNOTATTACHSURFACE"; break;
    case (int)0x88760014: szError = "DDERR_CANNOTDETACHSURFACE"; break;
    case (int)0x88760028: szError = "DDERR_CURRENTLYNOTAVAIL"; break;
    case (int)0x88760037: szError = "DDERR_EXCEPTION"; break;
    case (int)0x8876005A: szError = "DDERR_HEIGHTALIGN"; break;
    case (int)0x8876005F: szError = "DDERR_INCOMPATIBLEPRIMARY"; break;
    case (int)0x88760064: szError = "DDERR_INVALIDCAPS"; break;
    case (int)0x8876006E: szError = "DDERR_INVALIDCLIPLIST"; break;
    case (int)0x88760078: szError = "DDERR_INVALIDMODE"; break;
    case (int)0x88760082: szError = "DDERR_INVALIDOBJECT"; break;
    case (int)0x88760091: szError = "DDERR_INVALIDPIXELFORMAT"; break;
    case (int)0x88760096: szError = "DDERR_INVALIDRECT"; break;
    case (int)0x887600A0: szError = "DDERR_LOCKEDSURFACES"; break;
    case (int)0x887600AA: szError = "DDERR_NO3D"; break;
    case (int)0x887600B4: szError = "DDERR_NOALPHAHW"; break;
    case (int)0x887600CD: szError = "DDERR_NOCLIPLIST"; break;
    case (int)0x887600D2: szError = "DDERR_NOCOLORCONVHW"; break;
    case (int)0x887600D4: szError = "DDERR_NOCOOPERATIVELEVELSET"; break;
    case (int)0x887600D7: szError = "DDERR_NOCOLORKEY"; break;
    case (int)0x887600DC: szError = "DDERR_NOCOLORKEYHW"; break;
    case (int)0x887600DE: szError = "DDERR_NODIRECTDRAWSUPPORT"; break;
    case (int)0x887600E1: szError = "DDERR_NOEXCLUSIVEMODE"; break;
    case (int)0x887600E6: szError = "DDERR_NOFLIPHW"; break;
    case (int)0x887600F0: szError = "DDERR_NOGDI"; break;
    case (int)0x887600FA: szError = "DDERR_NOMIRRORHW"; break;
    case (int)0x887600FF: szError = "DDERR_NOTFOUND"; break;
    case (int)0x88760104: szError = "DDERR_NOOVERLAYHW"; break;
    case (int)0x88760118: szError = "DDERR_NORASTEROPHW"; break;
    case (int)0x88760122: szError = "DDERR_NOROTATIONHW"; break;
    case (int)0x88760136: szError = "DDERR_NOSTRETCHHW"; break;
    case (int)0x8876013C: szError = "DDERR_NOT4BITCOLOR"; break;
    case (int)0x8876013D: szError = "DDERR_NOT4BITCOLORINDEX"; break;
    case (int)0x88760140: szError = "DDERR_NOT8BITCOLOR"; break;
    case (int)0x8876014A: szError = "DDERR_NOTEXTUREHW"; break;
    case (int)0x8876014F: szError = "DDERR_NOVSYNCHW"; break;
    case (int)0x88760154: szError = "DDERR_NOZBUFFERHW"; break;
    case (int)0x8876015E: szError = "DDERR_NOZOVERLAYHW"; break;
    case (int)0x88760168: szError = "DDERR_OUTOFCAPS"; break;
    case (int)0x8876017C: szError = "DDERR_OUTOFVIDEOMEMORY"; break;
    case (int)0x8876017E: szError = "DDERR_OVERLAYCANTCLIP"; break;
    case (int)0x88760180: szError = "DDERR_OVERLAYCOLORKEYONLYONEACTIVE"; break;
    case (int)0x88760183: szError = "DDERR_PALETTEBUSY"; break;
    case (int)0x88760190: szError = "DDERR_COLORKEYNOTSET"; break;
    case (int)0x8876019A: szError = "DDERR_SURFACEALREADYATTACHED"; break;
    case (int)0x887601A4: szError = "DDERR_SURFACEALREADYDEPENDENT"; break;
    case (int)0x887601AE: szError = "DDERR_SURFACEBUSY"; break;
    case (int)0x887601B3: szError = "DDERR_CANTLOCKSURFACE"; break;
    case (int)0x887601B8: szError = "DDERR_SURFACEISOBSCURED"; break;
    case (int)0x887601C2: szError = "DDERR_SURFACELOST"; break;
    case (int)0x887601CC: szError = "DDERR_SURFACENOTATTACHED"; break;
    case (int)0x887601D6: szError = "DDERR_TOOBIGHEIGHT"; break;
    case (int)0x887601E0: szError = "DDERR_TOOBIGSIZE"; break;
    case (int)0x887601EA: szError = "DDERR_TOOBIGWIDTH"; break;
    case (int)0x887601FE: szError = "DDERR_UNSUPPORTEDFORMAT"; break;
    case (int)0x88760208: szError = "DDERR_UNSUPPORTEDMASK"; break;
    case (int)0x88760219: szError = "DDERR_VERTICALBLANKINPROGRESS"; break;
    case (int)0x8876021C: szError = "DDERR_WASSTILLDRAWING"; break;
    case (int)0x88760230: szError = "DDERR_XALIGN"; break;
    case (int)0x88760231: szError = "DDERR_INVALIDDIRECTDRAWGUID"; break;
    case (int)0x88760232: szError = "DDERR_DIRECTDRAWALREADYCREATED"; break;
    case (int)0x88760233: szError = "DDERR_NODIRECTDRAWHW"; break;
    case (int)0x88760234: szError = "DDERR_PRIMARYSURFACEALREADYEXISTS"; break;
    case (int)0x88760235: szError = "DDERR_NOEMULATION"; break;
    case (int)0x88760236: szError = "DDERR_REGIONTOOSMALL"; break;
    case (int)0x88760237: szError = "DDERR_CLIPPERISUSINGHWND"; break;
    case (int)0x88760238: szError = "DDERR_NOCLIPPERATTACHED"; break;
    case (int)0x88760239: szError = "DDERR_NOHWND"; break;
    case (int)0x8876023A: szError = "DDERR_HWNDSUBCLASSED"; break;
    case (int)0x8876023B: szError = "DDERR_HWNDALREADYSET"; break;
    case (int)0x8876023C: szError = "DDERR_NOPALETTEATTACHED"; break;
    case (int)0x8876023D: szError = "DDERR_NOPALETTEHW"; break;
    case (int)0x8876023E: szError = "DDERR_BLTFASTCANTCLIP"; break;
    case (int)0x8876023F: szError = "DDERR_NOBLTHW"; break;
    case (int)0x88760240: szError = "DDERR_NODDROPSHW"; break;
    case (int)0x88760241: szError = "DDERR_OVERLAYNOTVISIBLE"; break;
    case (int)0x88760242: szError = "DDERR_NOOVERLAYDEST"; break;
    case (int)0x88760243: szError = "DDERR_INVALIDPOSITION"; break;
    case (int)0x88760244: szError = "DDERR_NOTAOVERLAYSURFACE"; break;
    case (int)0x88760245: szError = "DDERR_EXCLUSIVEMODEALREADYSET"; break;
    case (int)0x88760246: szError = "DDERR_NOTFLIPPABLE"; break;
    case (int)0x88760247: szError = "DDERR_CANTDUPLICATE"; break;
    case (int)0x88760248: szError = "DDERR_NOTLOCKED"; break;
    case (int)0x88760249: szError = "DDERR_CANTCREATEDC"; break;
    case (int)0x8876024A: szError = "DDERR_NODC"; break;
    case (int)0x8876024B: szError = "DDERR_WRONGMODE"; break;
    case (int)0x8876024C: szError = "DDERR_IMPLICITLYCREATED"; break;
    case (int)0x8876024D: szError = "DDERR_NOTPALETTIZED"; break;
    case (int)0x8876024E: szError = "DDERR_UNSUPPORTEDMODE"; break;
    case (int)0x8876024F: szError = "DDERR_NOMIPMAPHW"; break;
    case (int)0x88760250: szError = "DDERR_INVALIDSURFACETYPE"; break;
    case (int)0x88760258: szError = "DDERR_NOOPTIMIZEHW"; break;
    case (int)0x88760259: szError = "DDERR_NOTLOADED"; break;
    case (int)0x8876026C: szError = "DDERR_DCALREADYCREATED"; break;
    case (int)0x88760276: szError = "DDERR_NONONLOCALVIDMEM"; break;
    case (int)0x88760280: szError = "DDERR_CANTPAGELOCK"; break;
    case (int)0x88760294: szError = "DDERR_CANTPAGEUNLOCK"; break;
    case (int)0x887602A8: szError = "DDERR_NOTPAGELOCKED"; break;
    case (int)0x887602B2: szError = "DDERR_MOREDATA"; break;
    case (int)0x887602B7: szError = "DDERR_VIDEONOTACTIVE"; break;
    case (int)0x887602BB: szError = "DDERR_DEVICEDOESNTOWNSURFACE"; break;
    case (int)0x00000000: szError = "DD_OK"; break;
    default: szError = "< unknown >"; break;
    }

    LOGMANAGER_WriteLogLine("***** DirectDraw error: %s - %s (0x%x)", szWhere, szError, hResult);
}

// 0x00510310
int __cdecl DDCORE_GammaCanBeControlled()
{
    return 1;
}

#include "gen/data/Source/D2DDraw/Src/ddCore.inc"
