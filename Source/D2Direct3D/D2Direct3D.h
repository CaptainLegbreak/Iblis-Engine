#pragma once

#include "D2GfxTypes.h"
#include "D2D3DTypes.h"

struct D2CriticalSectionStrc;

extern "C" __declspec(dllimport) unsigned int __stdcall SmackDoFrame(D2SmackStrc* smack); // 0x006CC5FC
extern "C" __declspec(dllimport) unsigned int __stdcall SmackWait(D2SmackStrc* smack); // 0x006CC5F8
extern "C" __declspec(dllimport) void __stdcall SmackNextFrame(D2SmackStrc* smack); // 0x006CC600
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134
extern D2D3DDeviceStrc* gpD3DDevice_00970E78; // 0x00970E78
extern const char gszAssertExpr_006CC837[]; // 0x006CC837
extern const char gszFloorPoolSourceFile[]; // 0x006FC3E4
extern const char gszSubtilePoolSourceFile[]; // 0x006FC3A8
extern const char gszTexPoolSourceFile[]; // 0x006FC36C
extern const unsigned int gnRenderFlag; // 0x006CE290
extern int ganGlyphWidths[]; // 0x00970FC8
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
extern void* gapObjectsEC[2]; // 0x009897EC
int __fastcall sub_006B58A0_CreateTexture(D2D3DObjStrc** ppTexture, D2D3DObjStrc** ppSurface, int nWidth, int nHeight); // 0x006B58A0
unsigned int __fastcall D3DCORE_GetColor(unsigned int index); // 0x006B1D50
void __cdecl D3DCORE_Flush(); // 0x006B3800
void __fastcall D3DCORE_SetColorCombineMode(int); // 0x006B1EA0
void __stdcall sub_006B9F00_PresentFrame(); // 0x006B9F00


// Moved from Storm.h (used by D2Direct3D units).
struct D2FogSystemInfoStrc;
__declspec(noreturn) void __cdecl sub_006B1A30_ThrowAtlException(long error); // 0x006B1A30
void __fastcall D3DCORE_LogDDrawError(const char*,long); // 0x006B20E0
extern "C" __declspec(dllimport) long __stdcall RegSetValueExA(void* hKey, const char* szValueName, unsigned long nReserved, unsigned long dwType, const unsigned char* pData, unsigned long cbData); // 0x006CC034
extern "C" __declspec(dllimport) int __stdcall lstrlenA(const char* sz); // 0x006CC154
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
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

void __fastcall D3DCORE_BlitIndexedToHighColor(const unsigned char* pSrc, unsigned short* pDst, int nWidth, int nHeight, int nDstPitch, int nUnused); // 0x006B1DC0
void __fastcall D3DCORE_SetAlphaBlendMode(int nState); // 0x006B1F40
void __fastcall D3DCORE_SetColorCombineMode(int nState); // 0x006B1EA0
void __fastcall D3DCORE_SetTextureFilterMode(int nMode); // 0x006B2030
void __fastcall D3DCORE_ShowD3DError(const char* text,long result); // 0x006B39B0
int __cdecl sub_006B77A0_GetBlendedShadows(); // 0x006B77A0
int __cdecl sub_006B9830_GetPerspective(); // 0x006B9830
void __cdecl D3DSPRITE_ReleaseSprites(); // 0x006B5B10
void __cdecl D3DSPRITE_InitSprites(); // 0x006B7110
void __cdecl sub_006B7250_ReleaseAll(); // 0x006B7250
void __fastcall sub_006B9730_SetColor(D2TLVertexStrc* pVertex,unsigned char nIndex,unsigned char nAlpha); // 0x006B9730
void __fastcall sub_006B9730_SetQuadColor(D2TLVertexStrc*,unsigned char,int); // 0x006B9730
void __cdecl D3DSMACK_SmackInit(); // 0x006B9A10
char* __fastcall D3DSMACK_CreateSmackSurfaces(char*); // 0x006B9A50
extern "C" void __cdecl D3DSMACK_SmackFree(); // 0x006B9B00
void __cdecl D3DSMACK_ReleaseSmackSurfaces(); // 0x006B9B30
void __cdecl D3DFLOORCACHE_CreateTileSurfaces(); // 0x006BB5E0
void __cdecl D3DFLOORCACHE_ReleaseTileSurfaces(); // 0x006BB640
int __fastcall sub_006BB870_BindTileTexture(D2TileLibraryEntryStrc* pTile); // 0x006BB870
void __fastcall D3DFLOORCACHE_InvalidateTileCaches(D2TileLibraryEntryStrc* pTile); // 0x006BBB90
