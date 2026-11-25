#pragma once

#include "D2GfxTypes.h"
#include "D2D3DTypes.h"

struct D2CriticalSectionStrc;

extern "C" __declspec(dllimport) unsigned int __stdcall SmackDoFrame(D2SmackStrc* smack); // 0x006CC5FC
extern "C" __declspec(dllimport) unsigned int __stdcall SmackWait(D2SmackStrc* smack); // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* smack); // 0x006CC600
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern D2CriticalSectionStrc* gpLock_007C9134; // 0x007C9134
extern D2D3DDeviceStrc* gpD3DDevice_00970E78; // 0x00970E78
extern const char gszAssertExpr_006CC837[]; // 0x006CC837
extern const char gszFloorPoolSourceFile[]; // 0x006FC3E4
extern const char gszSubtilePoolSourceFile[]; // 0x006FC3A8
extern const char gszTexPoolSourceFile[]; // 0x006FC36C
extern const unsigned int gnRenderFlag; // 0x006CE290
extern int gaGlyphWidths_00970FC8[]; // 0x00970FC8
extern int gbRenderPaused; // 0x007C9144
extern int gnBytesPerPixel; // 0x00970E80
extern int gnFloorTextureWidth; // 0x0096F4DC
extern int gnFloorTextureHeight; // 0x009702B8
extern int gnHeight_007C913C; // 0x007C913C
extern int gnRenderHeight; // 0x007C913C
extern int gnRenderWidth; // 0x007C9138
extern int gnWidth_007C9138; // 0x007C9138
extern unsigned int gnRenderFlags_0096F3A8; // 0x0096F3A8
extern void* gapGlyphTextures_009712D0[]; // 0x009712D0
extern void* ghDDrawWindow_007C9140; // 0x007C9140
extern void* gpArray_009897EC[2]; // 0x009897EC
int __fastcall sub_006B58A0_CreateTexture(D2D3DObjStrc** ppTexture, D2D3DObjStrc** ppSurface, int nWidth, int nHeight); // 0x006B58A0
unsigned int __fastcall D3DCORE_GetColor(unsigned int index); // 0x006B1D50
void __cdecl D3DCORE_Flush(); // 0x006B3800
void __fastcall sub_006B1EA0_SetMode(int); // 0x006B1EA0
void __stdcall sub_006B9F00_PresentFrame(); // 0x006B9F00
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380


// Moved from Storm.h (used by D2Direct3D units).
struct D2FogSystemInfoStrc;
D2FogSystemInfoStrc* __cdecl FOG_GetSystemInfo(); // 0x00407360
__declspec(noreturn) void __cdecl sub_006B1A30_ThrowAtlException(long error); // 0x006B1A30
void __fastcall D3DCORE_LogDDrawError(const char*,long); // 0x006B20E0
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) int __stdcall lstrlenA(const char* sz); // 0x006CC154
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern const char gszEmptyString[]; // 0x006CC837
extern int gnHeight_009702B8; // 0x009702B8

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define LRU_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(gszAssertExpr_006CC837, sub_00408090(), line); exit(-1); }
#define RELEASE(p) if (p) { p->lpVtbl->Release(p); p = 0; }

struct D2CriticalSectionStrc { void* pDebugInfo; long nLockCount; long nRecursionCount; void* hOwningThread; void* hLockSemaphore; unsigned long nSpinCount; };

struct D2RectStrc
{
    int nLeft;
    int nTop;
    int nRight;
    int nBottom;
};

