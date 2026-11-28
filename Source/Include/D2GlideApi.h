#pragma once
// D2Glide's exports that the other modules call; included only by the units that use it.

struct D2BinkStrc;
struct D2CriticalSectionStrc;
struct D2GfxSettingsStrc;
struct D2GlideTileCacheStrc;
struct tagPALETTEENTRY;

void __fastcall SCROLLBAR_Destroy(void* pArg); // 0x00507EE0
void __fastcall GLCORE_SetPalette(const tagPALETTEENTRY* pPalette); // 0x00509300
unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex); // 0x005093F0
void __fastcall GLCORE_SetTextureCombineMode(int nTmu); // 0x00509460
void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500
void __cdecl sub_0050BE20_GlideDebugRefresh(); // 0x0050BE20
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50
void __fastcall sub_0050C0F0_GlideDrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x0050C0F0
void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x0050DBC0
void __fastcall GLSUBTILECACHE_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex); // 0x0050F0F0
short __fastcall GLSUBTILECACHE_TileCacheAdd(D2GlideTileCacheStrc* pCache); // 0x0050F2B0
void __cdecl GLIDE_DrawVideoFrame(); // 0x0050FD10
int __cdecl BNCLIENT_GetLogonType(); // 0x0051A570
int __cdecl sub_0051CA10_Return14(); // 0x0051CA10
int __cdecl BNCLIENT_IsSetEmailRequested(); // 0x0051CA70
extern int gnSceneScaleFactor; // 0x007B57E4
extern char gnFloorCacheSize[12]; // 0x007C90C8
extern D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134
extern int gnRenderWidth; // 0x007C9138
extern int gbRenderPaused; // 0x007C9144
extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148
extern unsigned int gaGlidePalette[256]; // 0x0087EBA0
extern int gbGlidePaletteTable; // 0x0087EFC8
extern int gnGlideColorCombineState; // 0x0087EFD8
extern int gnGlideAlphaCombineMode; // 0x0087EFDC
extern int gnGlideTexFilterMode; // 0x0087EFE0
extern int gbGlideDrawing; // 0x0087EFE4
extern int gnGlideTileTmu; // 0x00880BF8
extern unsigned char* gpGlideTileDecodeBuffer; // 0x00880BFC
extern unsigned int gnGlideBinkX; // 0x00880C08
extern D2BinkStrc* gpGlideBink; // 0x00880C0C
extern int gbGlideBinkDone; // 0x00880C18
extern int gfSoundExpansion; // 0x00881790
