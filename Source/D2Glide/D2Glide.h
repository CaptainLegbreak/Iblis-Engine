#pragma once

#include "D2DDrawTypes.h"
#include "D2GfxTypes.h"
#include "D2GlideTypes.h"

struct D2GfxDataStrc;
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
extern D2PaletteTableStrc* gpGfxPaletteView; // 0x007C9150
extern D2TileDrawFunctionsStrc* gpTileDrawFunctions_007C914C; // 0x007C914C
extern const char gszEmptyString[]; // 0x006CC837
extern int (__stdcall* gpfnGrLfbLock)(int nType, int nBuffer, int nWriteMode, int nOrigin, int bPixelPipeline, D2GrLfbInfoStrc* pInfo); // 0x0087EADC
extern int (__stdcall* gpfnGrLfbUnlock)(int nType, int nBuffer); // 0x0087EAD8
extern int gaGlideAspectLodTall[4]; // 0x0072F258
extern int gaGlideAspectLodWide[4]; // 0x0072F268
extern int gaGlideCrossOffsetX[8]; // 0x0072F2C8
extern int gaGlideCrossOffsetY[8]; // 0x0072F2E8
extern int gaGlideWallCorner[10][6][3]; // 0x0072F3A0
extern int gbGlidePaletteTable; // 0x0087EFC8
extern int gbSurfaceActive_007C9140; // 0x007C9140
extern int gnRenderHeight; // 0x007C913C
extern int gnRenderWidth; // 0x007C9138
extern int gnRenderHeight; // 0x007C913C
extern unsigned int gaGlideDebugLight[0x400]; // 0x0087F0D0
extern unsigned int gaGlideLightPalette[]; // 0x0072F308
extern void (__stdcall* gpfnGrDrawPoint)(const D2GlideSpriteVertexStrc* pVertex); // 0x0087EAA0
extern void* gapGlideTileStripA[10]; // 0x0072F350
extern void* gapGlideTileStripB[10]; // 0x0072F378
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650
int __stdcall D2CMPTileValidate(D2TileLibraryEntryStrc* pEntry, int nUnused1, int nUnused2); // 0x005FDEA0
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
void __cdecl sub_00509AA0_GlideSuspend(); // 0x00509AA0
void __fastcall GLVERTEX_SetVertexAmbientColor(D2GlideSpriteVertexStrc* pVertex, unsigned char nShade); // 0x0050DBE0
void __fastcall sub_0050FBD0_GlideBindTileTexture(D2GlideTileStrc* pTile); // 0x0050FBD0
void __stdcall CelDraw(D2GfxDataStrc* pContext, int nX, int nY, int nArg4, int nArg5, unsigned char* pBuffer, int nHeight, int nPitch, int nArg9, int nArg10, int nArg11); // 0x006014C0
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

struct D2GlideFloorCacheStrc;
struct D2GlideFloorCacheEntryStrc;
struct D2TileLibraryEntryStrc;
struct D2GlideSpriteVertexStrc;

unsigned int __fastcall GLCORE_GetPaletteColor(int nPaletteIndex); // 0x005093F0
void __fastcall GLCORE_SetAlphaBlendMode(int nMode); // 0x00509500
void __fastcall GLCORE_SetColorCombineMode(int nState); // 0x005094B0
void __fastcall GLCORE_SetTextureCombineMode(int nTmu); // 0x00509460
void __fastcall GLCORE_SetTextureFilterMode(int nMode); // 0x005095D0
void __fastcall GLFLOORCACHE_FloorCacheEvict(D2GlideFloorCacheStrc* pCache); // 0x0050F6D0
D2GlideFloorCacheEntryStrc* __fastcall GLFLOORCACHE_FloorCacheUnlink(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F570
void __stdcall GLVERTEX_DecodeTileBlocks(D2TileLibraryEntryStrc* pTile, unsigned char* pDst); // 0x0050F980
int __cdecl GLVERTEX_IsPerspective(); // 0x0050DD30
void __fastcall GLVERTEX_SetAmbientColor(int nRed, int nGreen, int nBlue); // 0x0050DBC0
void __fastcall GLVERTEX_SetVertexColor(D2GlideSpriteVertexStrc* pVertex, unsigned int dwColor); // 0x0050DC30
void __cdecl sub_0050BE20_GlideDebugRefresh(); // 0x0050BE20
void __fastcall sub_0050BF50_GlideDrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int nDrawMode); // 0x0050BF50
int __fastcall sub_0050C890_GlideTileDrawShaded(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, unsigned char nShade, int nScreenPanels); // 0x0050C890
int __fastcall sub_0050CA00_GlideShadowTileDrawPerspective(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, int eDrawMode, int nScreenPanels); // 0x0050CA00
int __cdecl GLCORE_GetFloorTilesFlag(); // 0x00509650
void __cdecl GLSPRITE_FreeSpriteBuffers(); // 0x0050A0C0
void __fastcall GLCORE_ReleaseTexSlots(void* pData); // 0x0050A110
void __cdecl GLSPRITE_InitSprites(); // 0x0050B7B0
int __fastcall GLDEBUGFONT_DownloadDebugFont(int nStartAddress, int nAlignment); // 0x0050B860
void __cdecl GLDEBUGFONT_CreateDebugFont(); // 0x0050B9E0
void __cdecl GLDEBUGFONT_FreeDebugFont(); // 0x0050BB70
int __cdecl sub_0050BF40_GlideGetBlendedShadows(); // 0x0050BF40
void __fastcall sub_0050C270_GlideDrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x0050C270
void __cdecl sub_0050C760_GlideInitVertices(); // 0x0050C760
void __cdecl sub_0050D540_GlideInitD(); // 0x0050D540
void __cdecl GLVERTEX_AllocBlendTable(); // 0x0050DB20
void __cdecl GLVERTEX_FreeBlendTable(); // 0x0050DB40
void __cdecl GLVERTEX_BuildBlendTable(); // 0x0050DB70
void __cdecl GLPERSPECTIVE_AllocPerspectiveTable(); // 0x0050DC80
void __cdecl GLPERSPECTIVE_FreePerspectiveTable(); // 0x0050DCA0
void __cdecl GLPERSPECTIVE_FillPerspectiveTable(); // 0x0050DCD0
void __cdecl GLSMACK_SmackInit(); // 0x0050DF10
void __cdecl GLSMACK_SmackFree(); // 0x0050DF70
int __fastcall GLSPRITE_SetSmackTexAddresses(int nBase, int nAlign); // 0x0050DFE0
void __cdecl GLSMACK_SmackFlush(); // 0x0050E030
void __cdecl GLSPRITE_UploadSmackTextures(); // 0x0050E330
int __fastcall GLTEXTURECACHE_TexCacheInit(D2GlideTexCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050E890
D2GlideTexCacheEntryStrc* __fastcall GLSMACK_TexCacheUnlink(D2GlideTexCacheStrc* pCache, int nIndex); // 0x0050EAE0
void __fastcall GLTEXTURECACHE_TexCacheTouch(D2GlideTexCacheStrc* pCache, int nId); // 0x0050EBE0
void __fastcall GLSMACK_TexCacheEvict(D2GlideTexCacheStrc* pCache); // 0x0050EC40
void __fastcall GLTEXTURECACHE_TexCacheDestroy(D2GlideTexCacheStrc* pCache, int bFree); // 0x0050ECB0
int __fastcall GLTEXTURECACHE_TexCacheAdd(D2GlideTexCacheStrc* pList); // 0x0050ED10
int __fastcall GLSUBTILECACHE_TileCacheInit(D2GlideTileCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050ED90
void __fastcall GLSUBTILECACHE_TileCacheTouch(D2GlideTileCacheStrc* pCache, int nIndex); // 0x0050F0F0
void __fastcall GLSUBTILECACHE_TileCacheRelease(D2GlideTileCacheStrc* pCache, int nIndex); // 0x0050F1B0
short __fastcall GLSUBTILECACHE_TileCacheAdd(D2GlideTileCacheStrc* pCache); // 0x0050F2B0
int __fastcall GLFLOORCACHE_FloorCacheInit(D2GlideFloorCacheStrc* pCache, unsigned int nStart, unsigned int nEnd, unsigned int nAlign); // 0x0050F320
void __fastcall GLFLOORCACHE_FloorCacheTouch(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F670
void __fastcall GLSMACK_FloorCacheRemove(D2GlideFloorCacheStrc* pCache, int nIndex); // 0x0050F750
short __fastcall GLFLOORCACHE_FloorCacheAdd(D2GlideFloorCacheStrc* pCache); // 0x0050F820
void __cdecl GLBLOCKS_InitBlockBuffers(); // 0x0050F870
void __cdecl GLBLOCKS_FreeBlockBuffers(); // 0x0050F8C0
int __fastcall GLTEXTURECACHE_BindFloorTexture(void* pTile); // 0x0050FAD0
void __stdcall GLFLOORCACHE_ReleaseTileCache(); // 0x0050FCB0
void __fastcall sub_0050FDF0_GlidePlaySmacker(const char* szFile, int nResolutionMode, void* pfFrame); // 0x0050FDF0
