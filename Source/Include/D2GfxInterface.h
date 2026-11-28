#pragma once

#include "D2Check.h"
#include "D2GfxTypes.h"

struct tagRECT;
struct tagPOINT;
struct tagPALETTEENTRY;
struct D2PaletteTableStrc;
struct D2CacheStatsStrc;
struct D2TileLibraryEntryStrc;
struct D2GfxLightStrc;
struct D2GfxLightExStrc;
struct D2GfxDataStrc;

// A renderer's entry points. Each renderer (GDI, DirectDraw, Glide, Direct3D) defines one of these as
// static data, and D2Gfx's gapGraphicsInterfaces table points to them by video mode.
struct D2GraphicsInterfaceStrc
{
    int (__fastcall* pfDetect)(void* hInstance);
    int (__fastcall* pfInit)(D2GfxSettingsStrc* pSettings, const void* pHelpers);
    int (__fastcall* pfClose)();
    int (__fastcall* pfCreateSurface)(void* hWnd, int nResolutionMode);
    int (__fastcall* pfCloseSurface)();
    void (__fastcall* pfPauseSurface)(void* hWnd, int nResolutionMode, int nWindowState);
    int (__fastcall* pfStartDraw)(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue);
    int (__fastcall* pfEndDraw)();
    int (__fastcall* pfBlit)();
    int (__fastcall* pfChangeRes)(void* hWnd, int nResolutionMode);
    int (__fastcall* pfGetBackBuffer)(unsigned char* pBuffer);
    int (__fastcall* pfActivateWindow)(int bActive, int bWindowed);
    int (__fastcall* pfSetOption)(int nOption, int nValue);
    int (__fastcall* pfPlayCutscene)();
    void (__fastcall* pfOpenSmackCutscene)(const char* szFile, int nResolutionMode, void* pfFrame);
    int (__fastcall* pfCheckCutScene)();
    void (__fastcall* pfDecodeSmacker)(const char* szSmacker, unsigned char* pBuffer, int nVersion);
    void (__fastcall* pfPlaySmacker)(void* pContext);
    void (__fastcall* pfCloseSmacker)(void* pContext);
    D2CacheStatsStrc* (__fastcall* pfGetCacheResults)();
    int (__fastcall* pfGetDimensions)(int* pWidth, int* pHeight);
    void (__fastcall* pfSetGlobalScale)(int nScaleFactor);
    int (__fastcall* pfSetGamma)(int nGamma);
    int (__fastcall* pfGammaCanBeControlled)();
    void (__fastcall* pfUpdatePerspective)(int nScaleX, int nScaleY);
    void (__fastcall* pfPerspectiveTransform)(int nPosX, int nPosY, int nBias, int* pXAdjust, int* pYAdjust);
    void (__fastcall* pfPerspectiveTransformScale)(int nPosX, int nPosY, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder);
    void (__fastcall* pfPerspectiveClearScale)();
    void (__fastcall* pfSetPalette)(tagPALETTEENTRY* pPalette);
    void (__fastcall* pfSetPaletteTables)(D2PaletteTableStrc* pPaletteTables);
    void (__fastcall* pfSetAmbientColor)(int nRed, int nGreen, int nBlue);
    int (__fastcall* pfFloorTileDraw)(D2TileLibraryEntryStrc* pTile, D2GfxLightExStrc* pLight, int nPosX, int nPosY, int nWorldXpos, int nWorldYpos, unsigned char nAlpha, int nScreenPanels, void* pTileData);
    void (__fastcall* pfCelFlatSpriteDraw)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette);
    void (__fastcall* pfCelDraw)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette);
    void (__fastcall* pfCelDrawColor)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift);
    void (__fastcall* pfCelDrawEx)(D2GfxDataStrc* pData, int nPosX, int nPosY, int nSkipLines, int nDrawLines, int eDrawMode);
    void (__fastcall* pfCelDrawShadow)(D2GfxDataStrc* pData, int nPosX, int nPosY);
    void (__fastcall* pfCelDrawHilight)(D2GfxDataStrc* pData, int nPosX, int nPosY, unsigned char nPaletteIndex);
    void (__fastcall* pfCelDrawClipped)(D2GfxDataStrc* pData, int nPosX, int nPosY, void* pCropRect, int eDrawMode);
    int (__fastcall* pfTileDrawLit)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels);
    int (__fastcall* pfTileDrawTrans)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha);
    int (__fastcall* pfShadowTileDraw)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels);
    void (__fastcall* pfUtilDiamond)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilRect)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilFilledRect)(tagRECT* pRect, unsigned char nPaletteIndex);
    void (__fastcall* pfUtilPoint)(tagPOINT* pPoint, unsigned char nSize, unsigned char nPaletteIndex);
    void (__fastcall* pfDrawBox)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode);
    void (__fastcall* pfDrawBoxAlpha)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha);
    void (__fastcall* pfDrawLine)(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha);
    void (__fastcall* pfClearScreen)(int bPartial);
    void (__fastcall* pfOutputString)(int nPosX, int nPosY, const char* szFormat, char* va);
    void (__fastcall* pfDebugDraw)(unsigned int* pLight, unsigned int* pPlayerLight, int nPosX, int nPosY);
    void (__fastcall* pfDebugFillBackBuffer)(int nPosX, int nPosY);
    void (__fastcall* pfClearCaches)();
};

D2_CHECK_SIZE(D2GraphicsInterfaceStrc, 0xD8);
