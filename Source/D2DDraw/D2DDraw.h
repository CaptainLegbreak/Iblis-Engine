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
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __fastcall sub_005103B0(const char* szText, long nResult); // 0x005103B0
void __stdcall CelDraw(D2CmpCelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#include "D2Win32Types.h"

// Moved from D2Win.h (used by D2DDraw units).
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
extern int gnDDrawGammaScale; // 0x0072F7C8
extern int gnDDrawGamma; // 0x0072F7CC
