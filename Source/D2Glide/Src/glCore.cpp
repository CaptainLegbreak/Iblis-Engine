#include "D2Glide.h"

#include "D2GfxTypes.h"

#include "D2Win32Base.h"

#include "D2DDrawTypes.h"

#include "D2GlideTypes.h"

#include "D2GameTypes.h"

extern int gbGlideDrawing; // 0x0087EFE4

extern int gnGlideAlphaCombineMode; // 0x0087EFDC

extern int gnGlideColorCombineState; // 0x0087EFD8

extern int gnGlideTexFilterMode; // 0x0087EFE0

struct D2GlideHwQueryStrc;

extern int gdwGlobal_007C8CB0; // 0x007C8CB0

extern int gdwGlobal_007C8CB4; // 0x007C8CB4

extern int gdwGlobal_0072DA7C; // 0x0072DA7C

extern int gdwGlobal_007C8CBC; // 0x007C8CBC

extern int gnScaleFactor; // 0x0072DB44

extern int gdwGlobal_007D55CC; // 0x007D55CC

extern int gdwGlobal_007D55E4; // 0x007D55E4

extern int gbIsMouseButtonPressed; // 0x007D55E0

extern int gdwGlobal_007D55D4; // 0x007D55D4

void __stdcall CONTROL_RemoveFromList(void* pArg); // 0x004F9310

extern int gdwGlobal_0087E838; // 0x0087E838

extern int gdwGlobal_0087EFD0; // 0x0087EFD0

int gbFloorTiles; // 0x0087EFE8

extern int gdwGlobal_0088126C; // 0x0088126C

extern int gdwGlobal_00881768; // 0x00881768

extern int gdwGlobal_0088176C; // 0x0088176C

extern int gdwGlobal_00881770; // 0x00881770

extern int gdwGlobal_00881774; // 0x00881774

extern int gdwGlobal_00881778; // 0x00881778

extern int gdwGlobal_0072F830; // 0x0072F830

extern int gdwGlobal_00881798; // 0x00881798

extern int gdwGlobal_008817AC; // 0x008817AC

extern int gnMasterVolume; // 0x008817B0

extern int gdwGlobal_008817B4; // 0x008817B4

extern int gnPositionalBias; // 0x008817B8

extern int gnNpcSpeech; // 0x008817BC

extern int gdwGlobal_008817C0; // 0x008817C0

extern int gdwGlobal_008817FC; // 0x008817FC

extern char gData_0072FAA0[]; // 0x0072FAA0

extern int gdwGlobal_008818BC; // 0x008818BC

extern int gdwGlobal_008818C0; // 0x008818C0

extern int gdwGlobal_00881C04; // 0x00881C04

extern int gdwGlobal_00881C50; // 0x00881C50

int __cdecl GLCORE_Close(); // 0x00509E10

D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148

void (__stdcall* gpfnGrBufferClear)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88

void (__stdcall* gpfnGrBufferSwap)(int nSwapInterval); // 0x0087EB90

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C

int __fastcall GLCORE_ChangeRes(void* hWnd, int nResolution); // 0x00509F70

void __fastcall GLCORE_SetGamma(int nGamma); // 0x005090B0

void __cdecl GLSMACK_SmackFree(); // 0x0050DF70

void __cdecl GLBLOCKS_FreeBlockBuffers(); // 0x0050F8C0

void __cdecl GLPERSPECTIVE_FreePerspectiveTable(); // 0x0050DCA0

void __cdecl GLVERTEX_FreeBlendTable(); // 0x0050DB40

int gnRenderWidth;                                                                                 // 0x007C9138

extern void* ghDDrawWindow_007C9140; // 0x007C9140

int gbRenderPaused;                                                                                // 0x007C9144

extern void* ghGlideLibrary; // 0x0087EFA8

int gnGlideGammaTableSize;                                                                         // 0x0087EFD4

extern int gnGlideTmuState; // 0x0072F254

void (__stdcall* gpfnGrTexCombine)(int nTmu, int nRgbFunction, int nRgbFactor, int nAlphaFunction, int nAlphaFactor, int bRgbInvert, int bAlphaInvert); // 0x0087EAD0

unsigned int gaGlidePalette[256];                                                                  // 0x0087EBA0

int gnGlideTmuCount; // 0x0087EFB4

struct D2GlideHwQueryStrc
{
    int nParamB;
    int nParamA;
    int nParamE;
    int bResult;
    int nUnits;
};

extern void* gnGlideHandle; // 0x0087EB94

extern int gdwGlobal_0072F250; // 0x0072F250

extern int gdwGlobal_0087EFB8; // 0x0087EFB8

extern void* (__stdcall* gpfnGrSstWinOpen)(void* hWnd, int nRes, int nRefresh, int nFormat, int nOrigin, int nBuffers, int nAux); // 0x0087EAF4

extern void (__stdcall* gpfnGrCoordinateSpace)(int nMode); // 0x0087EB38

extern void (__stdcall* gpfnGrDepthMask)(int bMask); // 0x0087E97C

extern void (__stdcall* gpfnGrColorMask)(int bRgb, int bAlpha); // 0x0087EB30

void (__stdcall* gpfnGrTexFilterMode)(int nTmu, int nMinFilterMode, int nMagFilterMode); // 0x0087EAFC

extern void (__stdcall* gpfnGrChromakeyValue)(int nValue); // 0x0087EB34

void (__stdcall* gpfnGrGlideShutdown)(); // 0x0087EAB0

void (__stdcall* gpfnGrGlideInit)(); // 0x0087EB04

void (__stdcall* gpfnGrSstSelect)(int nSst); // 0x0087EB3C

void __cdecl GLDEBUGFONT_CreateDebugFont(); // 0x0050B9E0

int __cdecl GLCORE_InitTextureMemory(); // 0x00509670

int gnGlideRefresh640; // 0x0087EFAC

int gnGlideRefresh800; // 0x0087EFB0

int gbGlideHasMultiTmu; // 0x0087EFC0

int gdwGlobal_0087EFBC; // 0x0087EFBC

int (__stdcall* gpfnGrGet)(int nName, int nSize, int* pParams); // 0x0087EB1C

void (__stdcall* gpfnGrVertexLayout)(int nParam, int nOffset, int nMode); // 0x0087EB9C

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

int gbGlideInit; // 0x0087EFCC

void __cdecl GLCORE_CloseAtExit(); // 0x00509FD0

void __cdecl sub_0050C760_GlideInitVertices(); // 0x0050C760

void __cdecl sub_0050D540_GlideInitD(); // 0x0050D540

void __cdecl GLVERTEX_AllocBlendTable(); // 0x0050DB20

void __cdecl GLVERTEX_BuildBlendTable(); // 0x0050DB70

void __cdecl GLPERSPECTIVE_AllocPerspectiveTable(); // 0x0050DC80

void __cdecl GLPERSPECTIVE_FillPerspectiveTable(); // 0x0050DCD0

void __cdecl GLSMACK_SmackInit(); // 0x0050DF10

void __cdecl GLBLOCKS_InitBlockBuffers(); // 0x0050F870

char gnFloorCacheSize[12]; // 0x007C90C8

int gdwGlobal_00881790; // 0x00881790

struct D2TileLibraryEntryStrc;

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020

void __fastcall GLCORE_SetColorCombineMode(int nState);                                                      // 0x005094B0

void __fastcall GLCORE_SetAlphaBlendMode(int nMode);                                                     // 0x00509500

void __fastcall GLCORE_SetTextureFilterMode(int nMode);                                                       // 0x005095D0

int __fastcall GLCORE_CreateSurface(void* hWnd, int nResolution); // 0x00509E90

int __cdecl sub_0050BF40_GlideGetBlendedShadows();                                                                    // 0x0050BF40

void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50

void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x0050C270

int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels); // 0x0050C890

int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels); // 0x0050CA00

int __cdecl GLVERTEX_IsPerspective();                                                               // 0x0050DD30

void __fastcall sub_0050FDF0_GlidePlaySmacker(const char* szFile, int nResolutionMode, void* pfFrame);      // 0x0050FDF0


void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor);                     // 0x00512D90


void __fastcall EXCEL_BuildGammaTable(int gamma,void* table,double scale,int entrySize,int entries,int mask); // 0x006BE190

extern const double gdGlideGammaScale;                                                             // 0x006CD038

extern tagPALETTEENTRY gatGamePalette[256];                                                     // 0x007C8CC8

extern void (__stdcall* gpfnGuGammaCorrectionRGB)(float fRed, float fGreen, float fBlue);       // 0x0087EABC

extern void (__stdcall* gpfnGrLoadGammaTable)(int nEntries, unsigned int* pRed, unsigned int* pGreen, unsigned int* pBlue); // 0x0087EAE0

extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor);                              // 0x0087EFA0

int gbGlidePlayingVideo;                                                                           // 0x0087EFD0



struct D2GfxLightExStrc;

extern "C" __declspec(dllimport) void* __stdcall CreateBitmap(int nWidth, int nHeight, unsigned int nPlanes, unsigned int nBitCount, const void* lpBits); // 0x006CC090

extern "C" __declspec(dllimport) void* __stdcall CreateDCA(const char* pszDriver, const char* pszDevice, const char* pszPort, const void* pdm); // 0x006CC0A4

extern "C" __declspec(dllimport) void __stdcall BinkNextFrame(D2BinkStrc* pBink);                            // 0x006CC5BC

extern "C" __declspec(dllimport) int __stdcall BinkCopyToBuffer(D2BinkStrc* pBink, void* pDest, int nDestPitch, unsigned int nDestHeight, unsigned int nDestX, unsigned int nDestY, unsigned int nFlags); // 0x006CC5C0

extern "C" __declspec(dllimport) int __stdcall BinkDoFrame(D2BinkStrc* pBink);                               // 0x006CC5C4

unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex);                                   // 0x005093F0

void __cdecl sub_0050BE20_GlideDebugRefresh();                                                               // 0x0050BE20

void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue);                         // 0x0050DBC0

void __cdecl DDCORE_ReleaseSurfaces();                                                           // 0x00511A80

int __fastcall DDCORE_CreateSurface(void* hWnd, int nResolutionMode);                           // 0x005115E0

void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710

extern "C" const char gszDisplay[];                                                                // 0x006DE1E8

extern "C" const char gszDdDebugFontSourceFile[];                                                  // 0x006DE1D0

extern unsigned long gdwDDrawDebugFontTextColor;                                                    // 0x0072F7F0

extern unsigned char* gpScreenBuffer_007C9154;                                                              // 0x007C9154

void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride);        // 0x0087EAC4

extern void (__stdcall* gpfnGrTexDownloadTable)(int nType, void* pData);                         // 0x0087EB40

void (__stdcall* gpfnGrChromakeyMode)(int bEnable);                                                       // 0x0087EB8C

extern int gnGlideDebugX;                                                                          // 0x008800D0

extern int gnGlideDebugY;                                                                          // 0x008800D4

extern void** gppGlideDebugBuffer;                                                                 // 0x00880454

extern unsigned int gnGlideBinkY;                                                                  // 0x00880C04

extern unsigned int gnGlideBinkX;                                                                  // 0x00880C08

extern D2BinkStrc* gpGlideBink;                                                                    // 0x00880C0C

extern unsigned int gnGlideBinkFlags;                                                              // 0x00880C14

extern int gbGlideBinkDone;                                                                        // 0x00880C18

extern D2DDrawObjectStrc* gpDDrawObject_00881290;                                                           // 0x00881290

extern int gaDDrawDebugFontGlyphOffsets[96];                                                       // 0x008812A8

extern int gaDDrawDebugFontCharWidths[96];                                                         // 0x00881428

extern unsigned long gdwDDrawDebugFontBkColor;                                                     // 0x008815A8

extern unsigned char* gpDDrawDebugFontGlyphs;                                                      // 0x008815AC

extern unsigned int gnDDrawBinkY;                                                                  // 0x008816B8

extern unsigned int gnDDrawBinkX;                                                                  // 0x008816BC

extern D2BinkStrc* gpDDrawBink;                                                                    // 0x008816C0

extern unsigned int gnDDrawBinkFlags;                                                              // 0x008816C8

extern int gbDDrawBinkDone;                                                                        // 0x008816CC

int __fastcall GLDEBUGFONT_DownloadDebugFont(int nStartAddress, int nAlignment); // 0x0050B860

int __fastcall GLSPRITE_SetSmackTexAddresses(int nBase, int nAlign); // 0x0050DFE0

D2GlideTexCacheStrc gaGlideTexCaches[4]; // 0x0087F048

int __fastcall GLTEXTURECACHE_TexCacheInit(D2GlideTexCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050E890

int __fastcall GLSUBTILECACHE_TileCacheInit(D2GlideTileCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050ED90

int __fastcall GLFLOORCACHE_FloorCacheInit(D2GlideFloorCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050F320

void __cdecl GLSPRITE_InitSprites(); // 0x0050B7B0

void __stdcall GLFLOORCACHE_ReleaseTileCache(); // 0x0050FCB0

void __stdcall TileSetHardwareFreeCallback(void* pfnCallback); // 0x00604A30

extern unsigned int (__stdcall* gpfnGrTexMinAddress_0087EB24)(int nTmu); // 0x0087EB24

extern unsigned int (__stdcall* gpfnGrTexMaxAddress_0087EB44)(int nTmu); // 0x0087EB44

extern unsigned int gadwTmuMinAddress[]; // 0x0087EAA4

extern unsigned int gadwTmuMaxAddress[]; // 0x0087EAE4

extern int gnTmuCount_0087EFB4; // 0x0087EFB4

extern unsigned int gnTexAlign; // 0x0087EFBC

extern int gbFloorTiles_0087EFE8; // 0x0087EFE8

extern D2GlideTileCacheStrc gTileCache_0087EB48; // 0x0087EB48

extern D2GlideFloorCacheStrc gFloorCache_0087EB68; // 0x0087EB68

extern unsigned int gnFloorCacheSize_007C90C8; // 0x007C90C8

extern unsigned int gnTileCacheSize; // 0x007C90D4

extern unsigned int gnTexCacheSize1; // 0x007C90E0

extern unsigned int gnTexCacheSize2; // 0x007C90E4

extern unsigned int gnTexCacheSize3; // 0x007C90E8

extern const char gszInsufficientTextureMemory[]; // 0x006DD480

void __fastcall GLFLOORCACHE_FloorCacheDestroy(D2GlideTexCacheStrc* pCache, int bFree); // 0x0050F7C0

void __fastcall GLSUBTILECACHE_TileCacheDestroy(D2GlideTexCacheStrc* pCache, int bFree); // 0x0050F210

void __cdecl GLSMACK_SmackFlush(); // 0x0050E030

void __fastcall GLTEXTURECACHE_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFree); // 0x0050ECB0

void __cdecl GLSPRITE_FreeSpriteBuffers(); // 0x0050A0C0

void __cdecl GLDEBUGFONT_FreeDebugFont(); // 0x0050BB70

typedef void (__stdcall* D2GlideFinishFn)();

typedef int (__stdcall* D2GlideIdleFn)(int nHandle);

extern D2GlideTexCacheStrc gTexCacheA_0087EB68; // 0x0087EB68

extern D2GlideTexCacheStrc gTexCacheB_0087EB48; // 0x0087EB48

extern int gnGlideState_007C9140; // 0x007C9140

extern void (__stdcall* gpfnGrTexDownloadMipMap)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EAB8
extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define GLIDE_GETPROC(pfn, szName, nLine) *(void**)&pfn = GetProcAddress(ghGlideLibrary, szName); D2_ASSERT(pfn, nLine)

struct D2GrLfbInfoStrc;
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName);
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName);
extern void (__stdcall* gpfnGrVertexLayout)(int nParam, int nOffset, int nMode); // 0x0087EB9C
extern void (__stdcall* gpfnGrDrawVertexArrayContiguous)(int nMode, int nCount, void* pVertices, int nStride); // 0x0087EAC4
extern void (__stdcall* gpfnGrBufferClear)(unsigned int dwColor, unsigned int nAlpha, unsigned int nDepth); // 0x0087EB88
extern void (__stdcall* gpfnGrBufferSwap)(int nSwapInterval); // 0x0087EB90
extern void* gpfGlideFinish_0087EB14; // 0x0087EB14
extern void* gpfGlideSstWinClose_0087EFA4; // 0x0087EFA4
extern void (__stdcall* gpfnGrSstSelect)(int nSst); // 0x0087EB3C
extern void (__stdcall* gpfnGrAlphaBlendFunction)(int nRgbSrcFactor, int nRgbDstFactor, int nAlphaSrcFactor, int nAlphaDstFactor); // 0x0087EACC
extern void (__stdcall* gpfnGrAlphaCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EAF0
extern void (__stdcall* gpfnGrChromakeyMode)(int bEnable); // 0x0087EB8C
extern void (__stdcall* gpfnGrColorCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C
extern void (__stdcall* gpfnGrConstantColorValue)(unsigned int dwColor); // 0x0087EFA0
extern void (__stdcall* gpfnGrDitherMode)(int nFunction); // 0x0087EAB4
extern int (__stdcall* gpfnGrGet)(int nName, int nSize, int* pParams); // 0x0087EB1C
extern void (__stdcall* gpfnGrTexCombine)(int nTmu, int nRgbFunction, int nRgbFactor, int nAlphaFunction, int nAlphaFactor, int bRgbInvert, int bAlphaInvert); // 0x0087EAD0
extern void (__stdcall* gpfnGrTexFilterMode)(int nTmu, int nMinFilterMode, int nMagFilterMode); // 0x0087EAFC
extern void (__stdcall* gpfnGrGlideInit)(); // 0x0087EB04
extern void (__stdcall* gpfnGrGlideShutdown)(); // 0x0087EAB0

int __cdecl GLCORE_GlideLoadLibrary(); // 0x00508970
void __fastcall GLTEXTURECACHE_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush); // 0x0050ECB0
void __fastcall GLSUBTILECACHE_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush); // 0x0050F210
void __fastcall GLFLOORCACHE_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush); // 0x0050F7C0
extern D2GlideTileCacheStrc gtGlideTileCache; // 0x0087EB48
extern D2GlideFloorCacheStrc gtGlideFloorCache; // 0x0087EB68
extern D2GlideTexCacheStrc gaGlideTexCaches[4]; // 0x0087F048

void* ghGlideLibrary; // 0x0087EFA8

void (__stdcall* gpfnGuGammaCorrectionRGB)(float fRed, float fGreen, float fBlue); // 0x0087EABC

void (__stdcall* gpfnGrDrawPoint)(const D2GlideSpriteVertexStrc* pVertex); // 0x0087EAA0

void (__stdcall* gpfnGrDrawLine)(const D2GlideSpriteVertexStrc* pStart, const D2GlideSpriteVertexStrc* pEnd); // 0x0087E978

void* gpfnGrDrawTriangle; // 0x0087EB0C

void (__stdcall* gpfnGrDrawVertexArray)(int nMode, int nCount, void** ppVertices); // 0x0087EB18

void* (__stdcall* gpfnGrSstWinOpen)(void* hWnd, int nRes, int nRefresh, int nFormat, int nOrigin, int nBuffers, int nAux); // 0x0087EAF4

void (__stdcall* gpfnGrChromakeyValue)(int nValue); // 0x0087EB34

void* gpfnGrClipWindow; // 0x0087EB10

void (__stdcall* gpfnGrColorMask)(int bRgb, int bAlpha); // 0x0087EB30

void* gpfnGrDepthBufferFunction; // 0x0087EB28

void* gpfnGrDepthBufferMode; // 0x0087EB20

void (__stdcall* gpfnGrDepthMask)(int bMask); // 0x0087E97C

void (__stdcall* gpfnGrLoadGammaTable)(int nEntries, unsigned int* pRed, unsigned int* pGreen, unsigned int* pBlue); // 0x0087EAE0

void* gpfnGrGetString; // 0x0087EAC8

void* gpfnGrGetProcAddress; // 0x0087EB08

void* gpfnGrEnable; // 0x0087EAC0

void* gpfnGrDisable; // 0x0087EAF8

void (__stdcall* gpfnGrCoordinateSpace)(int nMode); // 0x0087EB38

void* gpfnGrTexTextureMemRequired; // 0x0087EB00

void* gpfnGrTexMinAddress; // 0x0087EB24

void* gpfnGrTexMaxAddress; // 0x0087EB44

void (__stdcall* gpfnGrTexDownloadTable)(int nType, void* pData); // 0x0087EB40

void* gpfnGrTexMipMapMode; // 0x0087EAD4

int (__stdcall* gpfnGrLfbLock)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC

int (__stdcall* gpfnGrLfbUnlock)(int nType, int nBuffer); // 0x0087EAD8

// 0x00507EE0
void __fastcall SCROLLBAR_Destroy(void* pArg)
{
    CONTROL_RemoveFromList(pArg);
}

void __fastcall GLTEXTURECACHE_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFlush);                     // 0x0050ECB0

void __fastcall GLSUBTILECACHE_TileCacheDestroy(D2GlideTileCacheStrc* pCache, int bFlush);                    // 0x0050F210

void __fastcall GLFLOORCACHE_FloorCacheDestroy(D2GlideFloorCacheStrc* pCache, int bFlush);                  // 0x0050F7C0

extern D2GlideTileCacheStrc gtGlideTileCache;                                                       // 0x0087EB48

extern D2GlideFloorCacheStrc gtGlideFloorCache;                                                     // 0x0087EB68

// 0x00508970
int __cdecl GLCORE_GlideLoadLibrary()
{
    ghGlideLibrary = LoadLibraryA("glide3x.dll");
    if (!ghGlideLibrary)
    {
        return 0;
    }

    GLIDE_GETPROC(gpfnGuGammaCorrectionRGB, "_guGammaCorrectionRGB@12", 0x9E);
    GLIDE_GETPROC(gpfnGrDrawPoint, "_grDrawPoint@4", 0xA1);
    GLIDE_GETPROC(gpfnGrDrawLine, "_grDrawLine@8", 0xA2);
    GLIDE_GETPROC(gpfnGrDrawTriangle, "_grDrawTriangle@12", 0xA3);
    GLIDE_GETPROC(gpfnGrVertexLayout, "_grVertexLayout@12", 0xA4);
    GLIDE_GETPROC(gpfnGrDrawVertexArray, "_grDrawVertexArray@12", 0xA5);
    GLIDE_GETPROC(gpfnGrDrawVertexArrayContiguous, "_grDrawVertexArrayContiguous@16", 0xA6);
    GLIDE_GETPROC(gpfnGrBufferClear, "_grBufferClear@12", 0xA8);
    GLIDE_GETPROC(gpfnGrBufferSwap, "_grBufferSwap@4", 0xA9);
    GLIDE_GETPROC(gpfGlideFinish_0087EB14, "_grFinish@0", 0xAA);
    GLIDE_GETPROC(gpfnGrSstWinOpen, "_grSstWinOpen@28", 0xAB);
    GLIDE_GETPROC(gpfGlideSstWinClose_0087EFA4, "_grSstWinClose@4", 0xAC);
    GLIDE_GETPROC(gpfnGrSstSelect, "_grSstSelect@4", 0xAD);
    GLIDE_GETPROC(gpfnGrAlphaBlendFunction, "_grAlphaBlendFunction@16", 0xAE);
    GLIDE_GETPROC(gpfnGrAlphaCombine, "_grAlphaCombine@20", 0xAF);
    GLIDE_GETPROC(gpfnGrChromakeyMode, "_grChromakeyMode@4", 0xB0);
    GLIDE_GETPROC(gpfnGrChromakeyValue, "_grChromakeyValue@4", 0xB1);
    GLIDE_GETPROC(gpfnGrClipWindow, "_grClipWindow@16", 0xB2);
    GLIDE_GETPROC(gpfnGrColorCombine, "_grColorCombine@20", 0xB3);
    GLIDE_GETPROC(gpfnGrColorMask, "_grColorMask@8", 0xB4);
    GLIDE_GETPROC(gpfnGrConstantColorValue, "_grConstantColorValue@4", 0xB5);
    GLIDE_GETPROC(gpfnGrDepthBufferFunction, "_grDepthBufferFunction@4", 0xB6);
    GLIDE_GETPROC(gpfnGrDepthBufferMode, "_grDepthBufferMode@4", 0xB7);
    GLIDE_GETPROC(gpfnGrDepthMask, "_grDepthMask@4", 0xB8);
    GLIDE_GETPROC(gpfnGrDitherMode, "_grDitherMode@4", 0xB9);
    GLIDE_GETPROC(gpfnGrLoadGammaTable, "_grLoadGammaTable@16", 0xBA);
    GLIDE_GETPROC(gpfnGrGet, "_grGet@12", 0xBB);
    GLIDE_GETPROC(gpfnGrGetString, "_grGetString@4", 0xBC);
    GLIDE_GETPROC(gpfnGrGetProcAddress, "_grGetProcAddress@4", 0xBD);
    GLIDE_GETPROC(gpfnGrEnable, "_grEnable@4", 0xBE);
    GLIDE_GETPROC(gpfnGrDisable, "_grDisable@4", 0xBF);
    GLIDE_GETPROC(gpfnGrCoordinateSpace, "_grCoordinateSpace@4", 0xC0);
    GLIDE_GETPROC(gpfnGrTexTextureMemRequired, "_grTexTextureMemRequired@8", 0xC1);
    GLIDE_GETPROC(gpfnGrTexMinAddress, "_grTexMinAddress@4", 0xC2);
    GLIDE_GETPROC(gpfnGrTexMaxAddress, "_grTexMaxAddress@4", 0xC3);
// build: symbol ?gpfnGrTexSource@* 0x0087EB98
    GLIDE_GETPROC(gpfnGrTexSource, "_grTexSource@16", 0xC4);
    GLIDE_GETPROC(gpfnGrTexCombine, "_grTexCombine@28", 0xC5);
    GLIDE_GETPROC(gpfnGrTexFilterMode, "_grTexFilterMode@12", 0xC6);
// build: symbol ?gpfnGrTexDownloadMipMap@* 0x0087EAB8
    GLIDE_GETPROC(gpfnGrTexDownloadMipMap, "_grTexDownloadMipMap@16", 0xC7);
    GLIDE_GETPROC(gpfnGrTexDownloadTable, "_grTexDownloadTable@8", 0xC8);
    GLIDE_GETPROC(gpfnGrTexMipMapMode, "_grTexMipMapMode@12", 0xC9);
    GLIDE_GETPROC(gpfnGrLfbLock, "_grLfbLock@24", 0xCA);
    GLIDE_GETPROC(gpfnGrLfbUnlock, "_grLfbUnlock@8", 0xCB);
    GLIDE_GETPROC(gpfnGrGlideInit, "_grGlideInit@0", 0xCC);
    GLIDE_GETPROC(gpfnGrGlideShutdown, "_grGlideShutdown@0", 0xCD);

    return 1;
}

int gnGlideNumBoards; // 0x0087EFC4

// 0x00508F60
int __cdecl GLCORE_Detect()
{
    if (!GLCORE_GlideLoadLibrary())
    {
        return 0;
    }

    gpfnGrGet(0xF, 4, &gnGlideNumBoards);
    return gnGlideNumBoards > 0;
}

// 0x00508F90
void __cdecl GLCORE_ClearCaches()
{
    GLFLOORCACHE_FloorCacheDestroy(&gtGlideFloorCache, 0);
    GLSUBTILECACHE_TileCacheDestroy(&gtGlideTileCache, 0);
    GLTEXTURECACHE_TexCacheDestroy(&gaGlideTexCaches[1], 0);
    GLTEXTURECACHE_TexCacheDestroy(&gaGlideTexCaches[2], 0);
    GLTEXTURECACHE_TexCacheDestroy(&gaGlideTexCaches[3], 0);
}

// 0x00508FD0
int __cdecl GLCORE_CheckCutScene()
{
    return gdwGlobal_0087EFD0;
}

int gdwGlobal_007B57E4; // 0x007B57E4

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218

D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134

// 0x00508FE0
int __fastcall GLCORE_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
// build: symbol ?gbRenderPaused@* 0x007C9144
    if (gbRenderPaused)
        return 0;
    gbGlideDrawing = 1;
    D2_ASSERT(gpRenderCriticalSection, 0x401);
    EnterCriticalSection(gpRenderCriticalSection);
    if (bClear)
        gpfnGrBufferClear((((nRed << 4) | nGreen) << 4 | nBlue) << 4, 0, 0);
    gnGlideColorCombineState = 0;
    gnGlideAlphaCombineMode = 0;
    gnGlideTexFilterMode = 0;
    gpfnGrChromakeyMode(1);
    GLVERTEX_SetAmbientColor(0xFF, 0xFF, 0xFF);
    return 1;
}

// 0x005090A0
void __fastcall GLCORE_SetGlobalScale(int nValue)
{
    gdwGlobal_007B57E4 = nValue;
}

// 0x005090B0
void __fastcall GLCORE_SetGamma(int nGamma)
{
    if (gnGlideGammaTableSize > 0)
    {
        int nEntries;
        int nBits;
        if (!gpfnGrGet(5, 4, &nEntries))
        {
            return;
        }

        if (!gpfnGrGet(0x2A, 4, &nBits))
        {
            return;
        }

        unsigned int* pTable = (unsigned int*)SMemAlloc(nEntries * 4, ".\\Src\\glCore.cpp", 0x42F, 0);
        EXCEL_BuildGammaTable(nGamma, pTable, gnGlideGammaTableSize, 4, nEntries, (1 << nBits) - 1);
        gpfnGrLoadGammaTable(nEntries, pTable, pTable, pTable);
        SMemFree(pTable, ".\\Src\\glCore.cpp", 0x43A, 0);
    }
    else
    {
        const float fGamma = nGamma / gdGlideGammaScale;
        gpfnGuGammaCorrectionRGB(fGamma, fGamma, fGamma);
    }
}

// 0x00509190
int __cdecl GLCORE_GammaCanBeControlled()
{
    return 1;
}

D2PaletteTableStrc gtGfxPaletteView; // 0x0087E980

int gbGlideDrawing; // 0x0087EFE4

// 0x005091A0
int __cdecl GLCORE_EndDraw()
{
// build: symbol ?gpRenderCriticalSection@* 0x007C9134
    D2_ASSERT(gpRenderCriticalSection, 0x47A);
    LeaveCriticalSection(gpRenderCriticalSection);
    gbGlideDrawing = 0;
    return 1;
}

// 0x005091E0
int __cdecl GLCORE_Blit()
{
    if (gpGfxSettings->bVSync)
    {
        gpfnGrBufferSwap(1);
        return 1;
    }

    gpfnGrBufferSwap(0);
    return 1;
}

// 0x00509210
int __fastcall GLIDE_GetBackBuffer(unsigned char* pBuffer)
{
    D2GrLfbInfoStrc tInfo;
    tInfo.size = sizeof(tInfo);
// build: symbol ?gpfnGrLfbLock@* 0x0087EADC
    if (!gpfnGrLfbLock(0, 1, 0xFF, 0, 0, &tInfo))
    {
        return 0;
    }

    unsigned char* pDstRow = pBuffer;
    unsigned short* pSrcRow = (unsigned short*)tInfo.lfbPtr;
// build: symbol ?gnRenderHeight@* 0x007C913C
    for (int y = 0; y < gnRenderHeight; ++y)
    {
        unsigned short* pSrc = pSrcRow;
        unsigned char* pDst = pDstRow;
        for (int x = 0; x < gnRenderWidth; ++x)
        {
            const unsigned short nPixel = *pSrc;
            const unsigned char nRed = nPixel >> 11;
            const unsigned char nGreen = nPixel >> 5;
            const unsigned char nBlue = (unsigned char)nPixel;
            *pDst = nRed << 3;
            ++pDst;
            *pDst = nGreen << 2;
            ++pDst;
            *pDst = nBlue << 3;
            ++pSrc;
            ++pDst;
        }

        pDstRow += 3 * gnRenderWidth;
        pSrcRow = (unsigned short*)((unsigned char*)pSrcRow + tInfo.strideInBytes);
    }

// build: symbol ?gpfnGrLfbUnlock@* 0x0087EAD8
    gpfnGrLfbUnlock(0, 1);
    return 1;
}

// 0x005092F0
void __fastcall GLCORE_GetDimensions(int* pWidth, int* pHeight)
{
    *pWidth = gnRenderWidth;
    *pHeight = gnRenderHeight;
}

// 0x00509300
void __fastcall GLCORE_SetPalette(const tagPALETTEENTRY* pPalette)
{
    if (gbGlidePaletteTable_0087EFC8)
    {
        for (int i = 0; i < 256; ++i)
        {
            unsigned int dwColor = 0xFF;
            dwColor = (dwColor << 8) + pPalette[i].peRed;
            dwColor = (dwColor << 8) + pPalette[i].peGreen;
            dwColor = (dwColor << 8) + pPalette[i].peBlue;
            gaGlidePalette[i] = dwColor;
        }
        gpfnGrTexDownloadTable(2, gaGlidePalette);
    }
}

void (__stdcall* gpfnGrAlphaBlendFunction)(int nRgbSrcFactor, int nRgbDstFactor, int nAlphaSrcFactor, int nAlphaDstFactor); // 0x0087EACC

void (__stdcall* gpfnGrAlphaCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EAF0

void (__stdcall* gpfnGrColorCombine)(int nFunction, int nFactor, int nLocal, int nOther, int bInvert); // 0x0087EB2C

int gnGlideColorCombineState; // 0x0087EFD8

int gnGlideAlphaCombineMode; // 0x0087EFDC

int gnGlideTexFilterMode; // 0x0087EFE0

// 0x005093F0
unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex)
{
    return gaGlidePalette[nPaletteIndex] << 8;
}

// 0x00509400
void __fastcall GLCORE_SetPaletteTables(D2PaletteTableStrc* pSource)
{
    gtGfxPaletteView = *pSource;
    gpGfxPaletteView_007C9150 = &gtGfxPaletteView;
}

// 0x00509420
int __cdecl GLCORE_ActivateWindow()
{
    return 0;
}

// 0x00509430
int __fastcall GLCORE_SetOption(int nOption, int nValue)
{
    switch (nOption)
    {
    case 10:
        *(int*)nValue = gbGlideDrawing;
        return 1;
    case 11:
        gnGlideGammaTableSize = nValue;
        return 1;
    }
    return 0;
}

// 0x00509460
void __fastcall GLCORE_SetTextureCombineMode(int nTmu)
{
    if (nTmu == gnGlideTmuState)
        return;
    if (nTmu == 1)
        gpfnGrTexCombine(0, 3, 8, 3, 8, 0, 0);
    else if (nTmu == 0)
        gpfnGrTexCombine(0, 1, 0, 1, 0, 0, 0);
    gnGlideTmuState = nTmu;
}

// 0x005094B0
void __fastcall GLCORE_SetColorCombineMode(int nState)
{
    if (gnGlideColorCombineState && nState == gnGlideColorCombineState)
        return;
    switch (nState)
    {
    case 1:
        gpfnGrColorCombine(3, 1, 0, 1, 0);
        break;
    case 2:
        gpfnGrColorCombine(1, 0, 1, 2, 0);
        break;
    }
    gnGlideColorCombineState = nState;
}

// 0x00509500
void __fastcall GLCORE_SetAlphaBlendMode(int nMode)
{
    if (gnGlideAlphaCombineMode && nMode == gnGlideAlphaCombineMode)
        return;
    switch (nMode)
    {
    case 1:
        gpfnGrAlphaCombine(0, 0, 1, 2, 0);
        gpfnGrAlphaBlendFunction(4, 0, 0, 0);
        break;
    case 2:
        gpfnGrAlphaCombine(1, 0, 1, 2, 0);
        gpfnGrAlphaBlendFunction(4, 4, 0, 0);
        break;
    case 3:
        gpfnGrAlphaCombine(1, 0, 1, 2, 0);
        gpfnGrAlphaBlendFunction(0, 2, 0, 0);
        break;
    case 4:
        gpfnGrAlphaCombine(1, 0, 1, 2, 0);
        gpfnGrAlphaBlendFunction(1, 5, 0, 0);
        break;
    }
    gnGlideAlphaCombineMode = nMode;
}

// 0x005095D0
void __fastcall GLCORE_SetTextureFilterMode(int nMode)
{
    if (gnGlideTexFilterMode && nMode == gnGlideTexFilterMode)
        return;
    switch (nMode)
    {
    case 1:
        gpfnGrTexFilterMode(0, 0, 0);
        if (gnGlideTmuCount > 1)
            gpfnGrTexFilterMode(1, 0, 0);
        break;
    case 2:
        gpfnGrTexFilterMode(0, 1, 1);
        if (gnGlideTmuCount > 1)
            gpfnGrTexFilterMode(1, 1, 1);
        break;
    }
    gnGlideTexFilterMode = nMode;
}

// 0x00509640
void* __cdecl GLCORE_GetCacheResults()
{
    return gnFloorCacheSize;
}

// 0x00509650
int __cdecl GLCORE_GetFloorTilesFlag()
{
    return gbFloorTiles;
}

// 0x00509660
void __fastcall GLCORE_SetFloorTilesFlag(int nValue)
{
    gbFloorTiles = nValue;
}

// 0x00509670
int __cdecl GLCORE_InitTextureMemory()
{
	const unsigned int nMask = gnTexAlign - 1;
	unsigned int nTotal = 0;
	unsigned int nAlign64K = 0x10000;
	unsigned int nAlign16K = 0x4000;
	unsigned int nAlign4K = 0x1000;
	if (nMask & 0x10000)
	{
		nAlign64K = (nMask | 0x10000) + 1;
	}
	if (nMask & 0x4000)
	{
		nAlign16K = (nMask | 0x4000) + 1;
	}
	if (nMask & 0x1000)
	{
		nAlign4K = (nMask | 0x1000) + 1;
	}

	for (int i = 0; i < gnTmuCount_0087EFB4; ++i)
	{
		gadwTmuMinAddress[i] = gpfnGrTexMinAddress_0087EB24(i);
		gadwTmuMaxAddress[i] = gpfnGrTexMaxAddress_0087EB44(i);
		nTotal += gadwTmuMaxAddress[i] - gadwTmuMinAddress[i];
	}

	if ((float)nTotal < 3.5 * 1024 * 1024)
	{
		LOGMANAGER_WriteLogLine(gszInsufficientTextureMemory);
		return 0;
	}

	unsigned int nAddress = gadwTmuMinAddress[0];
	int nTmu = 0;
	if (gbFloorTiles_0087EFE8)
	{
		const unsigned int nMask2 = gnTexAlign - 1;
		unsigned int nAlign1K = 0x400;
		if (nMask2 & 0x400)
		{
			nAlign1K = (nMask2 | 0x400) + 1;
		}
		unsigned int nAlign32K = 0x8000;
		if (nMask2 & 0x8000)
		{
			nAlign32K = (nMask2 | 0x8000) + 1;
		}

		nAddress += GLDEBUGFONT_DownloadDebugFont(nAddress, gnTexAlign);
		unsigned int nFree = gadwTmuMaxAddress[0] - nAddress;
		unsigned int nEnd;
		if (gnTmuCount_0087EFB4 > 1)
		{
			unsigned int nFloorSize = 3 * nFree / 4;
			if (nFloorSize < 0x1CCCCC)
			{
				nFloorSize = 0x1CCCCC;
			}
			gnFloorCacheSize_007C90C8 = nFloorSize;
			nEnd = GLFLOORCACHE_FloorCacheInit(&gFloorCache_0087EB68, nAddress, nFloorSize + nAddress, nAlign32K);
			gnTileCacheSize = gadwTmuMaxAddress[0] - nEnd;
			nEnd = GLSUBTILECACHE_TileCacheInit(&gTileCache_0087EB48, nEnd, gadwTmuMaxAddress[0], nAlign1K);
		}
		else
		{
			unsigned int nFloorSize = nFree / 2;
			if (nFree / 2 >= 0x300000)
			{
				nFloorSize = 0x300000;
			}
			unsigned int nTileSize = nFree / 4;
			if (nFree / 4 >= 0x100000)
			{
				nTileSize = 0x100000;
			}
			gnFloorCacheSize_007C90C8 = nFloorSize;
			nEnd = GLFLOORCACHE_FloorCacheInit(&gFloorCache_0087EB68, nAddress, nFloorSize + nAddress, nAlign32K);
			gnTileCacheSize = nTileSize;
			nEnd = GLSUBTILECACHE_TileCacheInit(&gTileCache_0087EB48, nEnd, nTileSize + nEnd, nAlign1K);
		}

		if (gnTmuCount_0087EFB4 > 1)
		{
			nEnd = gadwTmuMinAddress[1];
			nTmu = 1;
		}

		const unsigned int nStart = nEnd;
		const unsigned int nSize = gadwTmuMaxAddress[nTmu] - nStart;
		nEnd = GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[1], nStart, nStart + 25 * nSize / 100, nAlign64K);
		gnTexCacheSize1 = gaGlideTexCaches[1].nCount * nAlign64K;
		nEnd = GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[2], nEnd, nStart + 65 * nSize / 100, nAlign16K);
		gnTexCacheSize2 = gaGlideTexCaches[2].nCount * nAlign16K;
		GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[3], nEnd, gadwTmuMaxAddress[nTmu], nAlign4K);
		gnTexCacheSize3 = gaGlideTexCaches[3].nCount * nAlign4K;
	}
	else if (gnRenderWidth == 800 && gnRenderHeight == 600)
	{
		nAddress += GLSPRITE_SetSmackTexAddresses(nAddress, gnTexAlign);
		const unsigned int nFree = gadwTmuMaxAddress[0] - nAddress;
		if (gnTmuCount_0087EFB4 > 1)
		{
			int nEnd = GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[2], nAddress, nAddress + 50 * nFree / 100, nAlign16K);
			gnTexCacheSize2 = gaGlideTexCaches[2].nCount * nAlign16K;
			GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[3], nEnd, gadwTmuMaxAddress[0], nAlign4K);
			gnTexCacheSize3 = gaGlideTexCaches[3].nCount * nAlign4K;
			GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[1], gadwTmuMinAddress[1], gadwTmuMaxAddress[1], nAlign64K);
			gnTexCacheSize1 = gaGlideTexCaches[1].nCount * nAlign64K;
		}
		else
		{
			int nEnd = GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[1], nAddress, nAddress + 50 * nFree / 100, nAlign64K);
			gnTexCacheSize1 = gaGlideTexCaches[1].nCount * nAlign64K;
			nEnd = GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[2], nEnd, nAddress + 75 * nFree / 100, nAlign16K);
			gnTexCacheSize2 = gaGlideTexCaches[2].nCount * nAlign16K;
			GLTEXTURECACHE_TexCacheInit(&gaGlideTexCaches[3], nEnd, gadwTmuMaxAddress[0], nAlign4K);
			gnTexCacheSize3 = gaGlideTexCaches[3].nCount * nAlign4K;
		}
	}

	GLSPRITE_InitSprites();
	TileSetHardwareFreeCallback(GLFLOORCACHE_ReleaseTileCache);
	return 1;
}

// 0x00509A70
void __cdecl GLCORE_ClearAndSwap()
{
    gpfnGrBufferClear(0, 0, 0);
    if (gpGfxSettings->bVSync)
    {
        gpfnGrBufferSwap(1);
    }
    else
    {
        gpfnGrBufferSwap(0);
    }
}

int gbGlidePaletteTable; // 0x0087EFC8

D2GlideFinishFn gpfnGrFinish; // 0x0087EB14

D2GlideIdleFn gpfnGrSstWinClose; // 0x0087EFA4

int gnGlideHandle_0087EB94; // 0x0087EB94

// 0x00509AA0
int __cdecl GLCORE_CloseSurface()
{
    if (gbGlidePaletteTable)
    {
        gbGlidePaletteTable = 0;
        gpfnGrFinish();
        if (gbFloorTiles_0087EFE8)
        {
            GLFLOORCACHE_FloorCacheDestroy(&gTexCacheA_0087EB68, 1);
            GLSUBTILECACHE_TileCacheDestroy(&gTexCacheB_0087EB48, 1);
        }
        else
        {
            GLSMACK_SmackFlush();
        }
        GLTEXTURECACHE_TexCacheDestroy(&gaGlideTexCaches[1], 1);
        GLTEXTURECACHE_TexCacheDestroy(&gaGlideTexCaches[2], 1);
        GLTEXTURECACHE_TexCacheDestroy(&gaGlideTexCaches[3], 1);
        GLSPRITE_FreeSpriteBuffers();
        for (int i = 0; ; ++i)
        {
            int nIdle = i < 100 ? gpfnGrSstWinClose(gnGlideHandle_0087EB94) : 1;
            if (nIdle == 1)
            {
                break;
            }
        }
        GLDEBUGFONT_FreeDebugFont();
        gnGlideState_007C9140 = 0;
    }
    return 1;
}

// 0x00509B60
void __fastcall GLIDE_OpenSmackCutscene(const char* szFile, int nResolutionMode, void* pfFrame)
{
    if (!gbRenderPaused)
    {
        gpfnGrBufferClear(0, 0, 0);
        if (gpGfxSettings->bVSync)
        {
            gpfnGrBufferSwap(1);
        }
        else
        {
            gpfnGrBufferSwap(0);
        }

        gbGlidePlayingVideo = 1;
        sub_0050FDF0_GlidePlaySmacker(szFile, nResolutionMode, pfFrame);
        gbGlidePlayingVideo = 0;
    }
}

// 0x00509BC0
static int GLCORE_OpenDevice(int nResolution, void* hWnd)
{
    D2GlideHwQueryStrc tQuery;
    D2_ASSERT(!gbGlidePaletteTable_0087EFC8, 0x143);
    GLDEBUGFONT_CreateDebugFont();
    tQuery.bResult = 0;
    int nRefresh;
    int nGrRes;
    if (!nResolution)
    {
        nGrRes = 7;
        nRefresh = gnGlideRefresh640;
        gnRenderWidth = 640;
        gnRenderHeight = 480;
    }
    else
    {
        nGrRes = 8;
        nRefresh = gnGlideRefresh800;
        gnRenderWidth = 800;
        gnRenderHeight = 600;
    }

    switch (nResolution)
    {
    case 0:
    case 2:
        gbFloorTiles = 1;
        break;

    default:
        gbFloorTiles = 0;
        break;
    }

    ghDDrawWindow_007C9140 = hWnd;
    gnGlideHandle = gpfnGrSstWinOpen(hWnd, nGrRes, nRefresh, 2, 0, 2, 0);
    if (gnGlideHandle)
    {
        gbGlidePaletteTable_0087EFC8 = 1;
        if (gdwGlobal_0072F250)
        {
            tQuery.nUnits = 0;
            gdwGlobal_0072F250 = 0;
            gpfnGrGet(0xA, 4, &tQuery.nParamA);
            gpfnGrGet(0xB, 4, &tQuery.nParamB);
            gpfnGrGet(0x11, 4, &tQuery.nUnits);
            gbGlideHasMultiTmu = tQuery.nUnits > 1;
            gpfnGrGet(0x13, 4, &gnGlideTmuCount);
            if (gnGlideTmuCount >= 3)
            {
                gnGlideTmuCount = 3;
            }
            gpfnGrGet(0x24, 4, &gdwGlobal_0087EFBC);
            gpfnGrGet(0xE, 4, &tQuery.nParamE);
            gdwGlobal_0087EFB8 = tQuery.nParamE != 0;
            if (!gnGlideTmuCount)
            {
                return 0;
            }
        }

        gpfnGrCoordinateSpace(0);
        gpfnGrVertexLayout(1, 0, 1);
        gpfnGrVertexLayout(0x50, 0xC, 1);
        gpfnGrVertexLayout(0x40, 0x10, 1);
        if (gnGlideTmuCount > 1)
        {
            gpfnGrVertexLayout(0x51, 0xC, 1);
            gpfnGrVertexLayout(0x41, 0x10, 1);
        }
        gpfnGrVertexLayout(0x30, 8, 1);
        gpfnGrDepthMask(0);
        gpfnGrColorMask(1, 0);
        if (gnGlideTmuState)
        {
            gpfnGrTexCombine(0, 1, 0, 1, 0, 0, 0);
            gnGlideTmuState = 0;
        }
        gpfnGrTexFilterMode(0, 0, 0);
        gpfnGrTexCombine(0, 1, 0, 1, 0, 0, 0);
        if (gnGlideTmuCount > 1)
        {
            gpfnGrTexFilterMode(1, 0, 0);
            gpfnGrTexCombine(1, 1, 0, 1, 0, 0, 0);
        }
        gpfnGrChromakeyValue(0xFF);
        if (GLCORE_InitTextureMemory())
        {
            tQuery.bResult = 1;
        }
    }
    else
    {
        LOGMANAGER_WriteLogLine("Opening Glide window failed!");
    }

    return tQuery.bResult;
}

// 0x00509E10
int __cdecl GLCORE_Close()
{
    if (gbGlideInit)
    {
        GLSMACK_SmackFree();
        sub_00509AA0_GlideSuspend();
        gpfnGrGlideShutdown();
        GLBLOCKS_FreeBlockBuffers();
        GLPERSPECTIVE_FreePerspectiveTable();
        GLVERTEX_FreeBlendTable();
        gbGlideInit = 0;
    }

    if (gpRenderCriticalSection)
    {
        DeleteCriticalSection(gpRenderCriticalSection);
        FOG_Free(gpRenderCriticalSection, ".\\Src\\glCore.cpp", 0x30D, 0);
        gpRenderCriticalSection = 0;
    }

    if (ghGlideLibrary)
    {
        FreeLibrary(ghGlideLibrary);
    }

    return 1;
}

// 0x00509E90
int __fastcall GLCORE_CreateSurface(void* hWnd, int nResolution)
{
    if (gbGlidePaletteTable_0087EFC8)
    {
        return 1;
    }

    if (!GLCORE_OpenDevice(nResolution, hWnd))
    {
        return 0;
    }

    gpfnGrBufferClear(0, 0, 0);
    if (gpGfxSettings->bVSync)
    {
        gpfnGrBufferSwap(1);
        return 1;
    }

    gpfnGrBufferSwap(0);
    return 1;
}

// 0x00509EE0
void __fastcall GLCORE_PauseSurface(void* hWnd, int nResolutionMode, int nWindowState)
{
    D2_ASSERT(gpRenderCriticalSection, 0x3A3);

    EnterCriticalSection(gpRenderCriticalSection);
    if (nWindowState)
    {
        sub_00509AA0_GlideSuspend();
        gbRenderPaused = 1;
    }
    else
    {
        GLCORE_CreateSurface(hWnd, nResolutionMode);
        gbRenderPaused = 0;
    }
    LeaveCriticalSection(gpRenderCriticalSection);
}

// 0x00509F70
int __fastcall GLCORE_ChangeRes(void* hWnd, int nResolution)
{
    sub_00509AA0_GlideSuspend();
    gpfnGrGlideShutdown();
    gpfnGrGlideInit();
    gpfnGrSstSelect(0);
    if (!GLCORE_OpenDevice(nResolution, hWnd))
    {
        return 0;
    }

    gpfnGrBufferClear(0, 0, 0);
    if (gpGfxSettings->bVSync)
    {
        gpfnGrBufferSwap(1);
        return 1;
    }

    gpfnGrBufferSwap(0);
    return 1;
}

// 0x00509FD0
void __cdecl GLCORE_CloseAtExit()
{
    GLCORE_Close();
}

// 0x00509FE0
int __cdecl GLCORE_PlayCutscene()
{
    if (!gbRenderPaused && GLCORE_ChangeRes(ghDDrawWindow_007C9140, 0))
    {
        GLCORE_SetGamma(0x64);
        return 1;
    }

    return 0;
}

// 0x0050A010
int __fastcall GLCORE_Init(D2GfxSettingsStrc* pSettings, D2TileDrawFunctionsStrc* pTileDrawFunctions)
{
    D2_ASSERT(!gbGlideInit, 0x2A6);

    gpGfxSettings = pSettings;
    gpTileDrawFunctions_007C914C = pTileDrawFunctions;
    GLBLOCKS_InitBlockBuffers();
    GLPERSPECTIVE_AllocPerspectiveTable();
    GLVERTEX_AllocBlendTable();
    gpfnGrGlideInit();
    gbGlideInit = 1;
    gpfnGrSstSelect(0);
    atexit(GLCORE_CloseAtExit);
    GLVERTEX_BuildBlendTable();
    GLPERSPECTIVE_FillPerspectiveTable();
    sub_0050C760_GlideInitVertices();
    sub_0050D540_GlideInitD();
    GLSMACK_SmackInit();
    gpRenderCriticalSection = (D2CriticalSectionStrc*)FOG_Alloc(sizeof(D2CriticalSectionStrc), ".\\Src\\glCore.cpp", 0x2D5, 0);
    InitializeCriticalSection(gpRenderCriticalSection);
    return 1;
}

// 0x0050A110
void __fastcall GLCORE_ReleaseTexSlots(D2GlideTexSlotStrc* pSlots)
{
    for (int i = 0; i < 5; ++i)
    {
        const int nCache = pSlots[i].nCache - 1;
        if (nCache >= 0)
        {
            const int nId = pSlots[i].nId - 1;
            if (nId >= 0)
            {
                gaGlideTexCaches[nCache + 1].pEntries[nId].pOwner = 0;
            }
        }
    }
}

// 0x00518C10
void* __cdecl BNCLIENT_GetInterfaceTable()
{
    return gData_0072FAA0;
}

// 0x0051A570
int __cdecl BNCLIENT_GetLogonType()
{
    return gdwGlobal_008818C0;
}

// 0x0051CA10
int __cdecl sub_0051CA10()
{
    return 14;
}

// 0x0051CA70
int __cdecl BNCLIENT_IsSetEmailRequested()
{
    return gdwGlobal_00881C04;
}

#include "gen/data/Source/D2Glide/Src/glCore.inc"
