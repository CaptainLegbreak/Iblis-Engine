#pragma once
// D2Gfx's exports that the other modules call; included only by the units that use it.

struct D2CacheStatsStrc;
struct D2GraphicsInterfaceStrc;
struct D2PaletteTableStrc;
struct tagRECT;

int __stdcall D2GFX_GammaCanBeControlled(); // 0x004F5260
D2CacheStatsStrc* __cdecl D2GFX_GetCacheResults(); // 0x004F5290
int __stdcall WINDOW_GetState(); // 0x004F6070
void __stdcall D2GFX_UtilDiamond(tagRECT* pRect, unsigned char nPaletteIndex); // 0x004F6280
void __stdcall D2GFX_SetPaletteTables(D2PaletteTableStrc* pPaletteTables); // 0x004F6410
void __stdcall SCALE_UpdateFactor(); // 0x004F65C0
int __cdecl SCALE_GetFactor(); // 0x004F65E0
void __stdcall SCALE_SetDefaultFactor(); // 0x004F65F0
void __stdcall SCALE_ScalePerspectivePosition(int nXPos, int nYPos, int nAngle, int* pXAdjust, int* pYAdjust, int bOrder); // 0x004F67C0
void __cdecl D2GFX_OutputString(int nXPos, int nYPos, const char* szFormat, ...); // 0x004F6890
extern int gbIsWindowed; // 0x007C8CB4
extern D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0
extern int gnInnerRight; // 0x007C9784
extern int gnClipBottom; // 0x007C978C
extern int gnInnerBottom; // 0x007C9790
extern int gnClipLeft; // 0x007C9794
extern int ganRowOffsets[732]; // 0x007C97A8
extern int gnInnerTop; // 0x007CA31C
extern int gnClipRight; // 0x007D2324
extern int gnInnerLeft; // 0x007D2328
extern int gnClipTop; // 0x007D232C
extern unsigned char* gpScreenBuffer; // 0x007D5448
extern int gnScreenPitch; // 0x007D544C
