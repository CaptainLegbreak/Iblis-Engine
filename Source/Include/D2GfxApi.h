#pragma once
// D2Gfx's exports that the other modules call: the window, the renderer and the drawing calls.

struct D2GfxDataStrc;
struct D2GfxLightStrc;
struct D2TileLibraryEntryStrc;
struct tagRECT;

int __stdcall D2GFX_Release(); // 0x004F5050
int __cdecl D2GFX_GetDisplayType(); // 0x004F5140
int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160
int __cdecl D2GFX_CheckUnitPerspective(); // 0x004F5170
int __cdecl D2GFX_IsFixedAspectRatio(); // 0x004F5180
void __stdcall D2GFX_SetTownMode(int bTown); // 0x004F5190
int __cdecl D2GFX_IsHardwareRenderMode(); // 0x004F51C0
int __stdcall D2GFX_CheckPerspective(); // 0x004F51D0
void __stdcall D2GFX_SetPerspective(int bPerspective); // 0x004F51E0
void __stdcall D2GFX_SetBlendShadows(int bBlendedShadows); // 0x004F5200
int __cdecl D2GFX_CheckLowQuality(); // 0x004F5210
void __stdcall D2GFX_SetLowQuality(int bLowQuality); // 0x004F5220
int __stdcall D2GFX_SetGamma(int nGamma); // 0x004F5230
void __cdecl D2GFX_EnableVSync(); // 0x004F5270
void __cdecl D2GFX_DisableFixedAspectRatio(); // 0x004F5280
void __fastcall D2GFX_SetViewMatrixAdjust(int nOffset); // 0x004F52A0
int __fastcall D2GFX_SetOption(int nOption, int nValue); // 0x004F52B0
int __stdcall D2GFX_TogglePerspective(); // 0x004F54B0
int __stdcall D2GFX_ToggleBlendedShadows(); // 0x004F54D0
int __stdcall D2GFX_ToggleLowQuality(); // 0x004F54F0
void __stdcall WINDOW_GetResolutionSize(int nResolution, long* pWidth, long* pHeight); // 0x004F5570
int __stdcall WINDOW_Create(int bWindowed, int nResolution); // 0x004F5610
int __stdcall WINDOW_Destroy(); // 0x004F5900
void __stdcall WINDOW_SetPaused(int bPaused); // 0x004F5990
int __cdecl WINDOW_GetWindow(); // 0x004F59A0
int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight); // 0x004F59B0
void __stdcall WINDOW_ShowCursor(int bShow); // 0x004F59F0
int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30
int __stdcall WINDOW_Resize(int nResolution, int bForceResize); // 0x004F5AA0
int __stdcall WINDOW_CenterWindow(int nResolution); // 0x004F5BC0
void __stdcall WINDOW_ClearCaches(); // 0x004F5D50
void __stdcall WINDOW_PlayCutscene(); // 0x004F5D60
int __stdcall WINDOW_CheckCutScene(); // 0x004F5DD0
void __stdcall WINDOW_DecodeSmacker(const char* szSmacker, unsigned char* pBuffer, int nVersion); // 0x004F5E00
void __stdcall WINDOW_PlaySmacker(void* pContext); // 0x004F5E40
void __stdcall WINDOW_CloseSmacker(void* pContext); // 0x004F5E80
void __stdcall WINDOW_ShowAll(); // 0x004F5F60
void __stdcall WINDOW_EndCutScene(int nResolution); // 0x004F6080
int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004F60F0
int __stdcall D2GFX_EndScene(); // 0x004F6190
int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer); // 0x004F6250
int __stdcall D2GFX_HardwareAcceleratedRenderMode(); // 0x004F6270
void __stdcall D2GFX_UtilRect(tagRECT* pRect, unsigned char nPaletteIndex); // 0x004F62A0
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300
void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340
void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380
void __stdcall D2GFX_ClearScreen(int bPartial); // 0x004F63B0
void __stdcall D2GFX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x004F6430
void __stdcall TEXTURE_CelFlatSpriteDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nScreenMode, unsigned char* pPalette); // 0x004F6450
void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480
void __stdcall TEXTURE_CelDrawColor(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nGlobalPaletteShift); // 0x004F64B0
void __stdcall TEXTURE_CelDrawClipped(D2GfxDataStrc* pData, int nXPos, int nYPos, void* pCropRect, int eDrawMode); // 0x004F6510
void __stdcall TEXTURE_CelDrawShadow(D2GfxDataStrc* pData, int nXPos, int nYPos); // 0x004F6540
void __stdcall TEXTURE_CelDrawHilight(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned char nPaletteIndex); // 0x004F6570
void __stdcall D2GFX_DebugDraw(unsigned int* pLight, unsigned int* pPlayerLight, int nXPos, int nYPos); // 0x004F68B0
int __stdcall TILE_TileDrawLit(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels); // 0x004F6920
int __stdcall TILE_TileDrawTrans(D2TileLibraryEntryStrc* pTile, int nXPos, int nYPos, D2GfxLightStrc* pLight, int nScreenPanels, unsigned char nAlpha); // 0x004F6950
void __fastcall CMNSUBTILE_DrawIsoBlockFlat(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette); // 0x004F69B0
void __fastcall D2GFX_DrawLitSubtileRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep); // 0x004F6BB0
void __fastcall CMNSUBTILE_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift); // 0x004F71A0
void __fastcall CMNSUBTILE_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows); // 0x004F7580
void __fastcall CMNSUBTILE_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nShift); // 0x004F7850
extern "C" void __cdecl CMNSUBTILE_BuildGouraudCache(); // 0x004F7CC0
void __fastcall WINDOW_SetPanelCoords(int nWidth, int nHeight); // 0x004F7DA0
void __cdecl CMNSUBTILE_BuildLineOffsets(); // 0x004F7E70
void __fastcall CMNSUBTILE_DrawVisTile(unsigned char* pSrc, int nX, int nY); // 0x004F7EA0
void __fastcall CMNSUBTILE_DrawRleVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nLight); // 0x004F8050
