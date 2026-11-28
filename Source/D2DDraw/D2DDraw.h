#pragma once

#include "D2GfxTypes.h"
#include "D2SysTypes.h"

struct D2CmpCelContextStrc;
struct D2GfxSettingsStrc;
struct D2TileDrawFunctionsStrc;

extern "C" __declspec(dllimport) void __stdcall SmackClose(void* hSmack); // 0x006CC608
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszDDSmackFile[]; // 0x006DE20C
extern D2GfxSettingsStrc* gpGfxSettings; // 0x007C9148
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C; // 0x007C914C
extern int gbRenderPaused; // 0x007C9144
extern int gbSurfaceActive_007C9140; // 0x007C9140
extern int gnRenderHeight; // 0x007C913C
extern int gnRenderWidth; // 0x007C9138
extern unsigned char* gpScreenBuffer_007C9154; // 0x007C9154
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned long gdwVideoFlags; // 0x00881140
extern void* ghDDrawWindow_007C9140; // 0x007C9140
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
unsigned char __stdcall GetClosestColor(const unsigned char* pPalette, unsigned int nCount, int nC0, int nC1, int nC2); // 0x00605210
void __fastcall DDCORE_DDrawLogError(const char* szText, long nResult); // 0x005103B0
void __stdcall CelDraw(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#include "D2Win32Types.h"

// Moved from D2Win.h (used by D2DDraw units).
extern int gnDDrawGammaScale; // 0x0072F7C8
extern int gnDDrawGamma; // 0x0072F7CC

struct D2SmackRecordStrc;

int __cdecl DDCORE_GetBlendedShadows(); // 0x00512700
void __fastcall DDSMACK_CloseSmacker(D2SmackRecordStrc* pRecord); // 0x00513330
int __fastcall DDCORE_GetDrawModePalette(int nIndex, int* pType); // 0x00511D70
void __fastcall sub_00511DF0_DDrawSetMode(int nResolutionMode); // 0x00511DF0
void __cdecl DDDEBUGFONT_CreateDebugFont(); // 0x00512430
void __cdecl DDDEBUGFONT_FreeDebugFont(); // 0x005125B0
void __fastcall sub_00512710_DDrawDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x00512710
void __fastcall sub_00512D90_DDrawUtilFilledRect(tagRECT* pRect, unsigned char nColor); // 0x00512D90
void __fastcall sub_00512ED0_ClearScreen(int bPartial); // 0x00512ED0
