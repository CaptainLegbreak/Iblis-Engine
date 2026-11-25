#pragma once

#include "D2DDrawTypes.h"
#include "D2GfxTypes.h"
#include "D2GlideTypes.h"

struct D2CelContextStrc;
struct D2CelStrc;
struct D2CriticalSectionStrc;
struct D2PaletteTableStrc;
struct D2GlideTileStrc;
struct D2TileDrawFunctionsStrc;
struct D2TileLibraryEntryStrc;
struct tagRECT;

extern "C" __declspec(dllimport) int __stdcall DeleteDC(void* hdc); // 0x006CC0D8
extern "C" __declspec(dllimport) int __stdcall DeleteObject(void* ho); // 0x006CC0D4
extern "C" __declspec(dllimport) int __stdcall DrawTextA(void* hdc, const char* lpchText, int cchText, tagRECT* lprc, unsigned int format); // 0x006CC534
extern "C" __declspec(dllimport) int __stdcall GetCharWidthA(void* hdc, unsigned int iFirst, unsigned int iLast, int* lpBuffer); // 0x006CC0D0
extern "C" __declspec(dllimport) int __stdcall SetBkMode(void* hdc, int mode); // 0x006CC0B4
extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498
extern "C" __declspec(dllimport) unsigned long __stdcall GetPixel(void* hdc, int x, int y); // 0x006CC0B8
extern "C" __declspec(dllimport) unsigned long __stdcall SetBkColor(void* hdc, unsigned long color); // 0x006CC0B0
extern "C" __declspec(dllimport) unsigned long __stdcall SetTextColor(void* hdc, unsigned long color); // 0x006CC0AC
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC218
extern "C" __declspec(dllimport) void* __stdcall CreateFontA(int cHeight, int cWidth, int cEscapement, int cOrientation, int cWeight, unsigned long bItalic, unsigned long bUnderline, unsigned long bStrikeOut, unsigned long iCharSet, unsigned long iOutPrecision, unsigned long iClipPrecision, unsigned long iQuality, unsigned long iPitchAndFamily, const char* pszFaceName); // 0x006CC0E0
extern "C" __declspec(dllimport) void* __stdcall SelectObject(void* hdc, void* h); // 0x006CC09C
extern "C" const char gszCourier[]; // 0x006DD52C
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern D2CriticalSectionStrc* gpRenderCriticalSection; // 0x007C9134
extern D2DDrawSurfaceStrc* gpDDrawPrimarySurface; // 0x00881278
extern D2PaletteTableStrc* gpGfxPaletteView_007C9150; // 0x007C9150
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C; // 0x007C914C
extern const char gszEmptyString[]; // 0x006CC837
extern int (__stdcall* gpfnGrLfbLock)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC
extern int (__stdcall* gpfnGrLfbUnlock)(int nType, int nBuffer); // 0x0087EAD8
extern int gaGlideAspectLodTall[4]; // 0x0072F258
extern int gaGlideAspectLodWide[4]; // 0x0072F268
extern int gaGlideCrossOffsetX[8]; // 0x0072F2C8
extern int gaGlideCrossOffsetY[8]; // 0x0072F2E8
extern int gaGlideWallCorner[10][6][3]; // 0x0072F3A0
extern int gbGlidePaletteTable_0087EFC8; // 0x0087EFC8
extern int gbSurfaceActive_007C9140; // 0x007C9140
extern int gnRenderHeight_007C913C; // 0x007C913C
extern int gnRenderWidth_007C9138; // 0x007C9138
extern int gnRenderHeight; // 0x007C913C
extern unsigned int gaGlideDebugLight[0x400]; // 0x0087F0D0
extern unsigned int gaGlideLightPalette[]; // 0x0072F308
extern void (__stdcall* gpfnGrDrawPoint)(const D2GlideSpriteVertexStrc* pVertex); // 0x0087EAA0
extern void* gapGlideTileStripA[10]; // 0x0072F350
extern void* gapGlideTileStripB[10]; // 0x0072F378
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pTile, int bAsync, int nFlags); // 0x005FDEA0
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __cdecl sub_00509AA0_GlideSuspend(); // 0x00509AA0
void __fastcall sub_0050DBE0_GlideSetVertexShade(D2GlideSpriteVertexStrc* pVertex, unsigned char nShade); // 0x0050DBE0
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile); // 0x0050FBD0
void __stdcall CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define GLIDE_VERTEX_IN_RECT(v, r) ((v).x >= (r).left && (v).x < (r).right && (v).y >= (r).top && (v).y < (r).bottom)

struct D2GfxLightStrc
{
    unsigned int aColor[8];
};

struct D2GlideDebugCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nAlpha;
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

struct D2GlideTexDimsStrc
{
    int nWidth;
    int nHeight;
};

#include "D2Win32Types.h"
