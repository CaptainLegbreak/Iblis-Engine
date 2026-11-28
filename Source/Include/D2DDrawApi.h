#pragma once
// D2DDraw's exports that the other modules call; included only by the units that use it.

struct D2BinkStrc;
struct D2DDrawPaletteClass;
struct D2PaletteTableStrc;
struct tagPALETTEENTRY;
struct tagRECT;

void __fastcall DDCORE_SetPalette(tagPALETTEENTRY* pPalette); // 0x00510160
int __fastcall DDCORE_CreateSurface(void* hWnd, int nResolutionMode); // 0x005115E0
void __cdecl DDCORE_ReleaseSurfaces(); // 0x00511A80
int __fastcall sub_00511FB0_DrawImage(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, void* pPalette); // 0x00511FB0
int __fastcall GLVERTEX_CelFlatSpriteDraw(void* pData, int nX, int nY, unsigned int dwGamma, int nDrawMode, int nScreenMode, void* pPalette); // 0x00512410
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710
void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor); // 0x00512D90
void __cdecl DDRAW_DrawVideoFrame(); // 0x005136F0
extern int gnDDrawGammaScale; // 0x0072F7C8
extern int gnDDrawGamma; // 0x0072F7CC
extern unsigned long gdwDDrawDebugFontTextColor; // 0x0072F7F0
extern D2PaletteTableStrc* gpGfxPaletteView; // 0x007C9150
extern unsigned int gaGlideDebugLight[0x400]; // 0x0087F0D0
extern int gnGlideDebugX; // 0x008800D0
extern int gnGlideDebugY; // 0x008800D4
extern void** gppGlideDebugBuffer; // 0x00880454
extern unsigned int gnGlideBinkY; // 0x00880C04
extern unsigned int gnGlideBinkFlags; // 0x00880C14
extern int gbDDrawPlayingVideo; // 0x0088126C
extern D2DDrawPaletteClass* gpDDrawPalette; // 0x00881290
extern int gaDDrawDebugFontGlyphOffsets[96]; // 0x008812A8
extern unsigned long gdwDDrawDebugFontBkColor; // 0x008815A8
extern unsigned char* gpDDrawDebugFontGlyphs; // 0x008815AC
extern unsigned int gnDDrawBinkY; // 0x008816B8
extern unsigned int gnDDrawBinkX; // 0x008816BC
extern D2BinkStrc* gpDDrawBink; // 0x008816C0
extern unsigned int gnDDrawBinkFlags; // 0x008816C8
extern int gbDDrawBinkDone; // 0x008816CC
