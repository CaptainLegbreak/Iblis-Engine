#pragma once
// D2DDraw: DirectDraw object and surface interfaces with their surface descriptions and blit effects

#include "D2Check.h"
#include "D2Structs.h"

struct D2DDSurfaceDescStrc;
struct D2DDSurfaceDesc2Strc;
struct D2DDBltFxStrc;
struct D2DDrawSurfaceVtblStrc;
struct D2DDrawSurfaceStrc;
struct D2DDSurfaceVtbl;
struct D2DDSurfaceStrc;
struct D2DDrawObjectVtblStrc;
struct D2DDrawObjectStrc;

struct D2DDColorKeyStrc
{
    unsigned int dwColorSpaceLowValue; // 0x00
    unsigned int dwColorSpaceHighValue; // 0x04
};

struct D2DDPixelFormatStrc
{
    unsigned int dwSize; // 0x00
    unsigned int dwFlags; // 0x04
    unsigned int dwFourCC; // 0x08
    unsigned int dwRGBBitCount; // 0x0C
    unsigned int dwRBitMask; // 0x10
    unsigned int dwGBitMask; // 0x14
    unsigned int dwBBitMask; // 0x18
    unsigned int dwRGBAlphaBitMask; // 0x1C
};

struct D2DDSurfaceDescStrc
{
    unsigned int dwSize; // 0x00
    unsigned int dwFlags; // 0x04
    unsigned int dwHeight; // 0x08
    unsigned int dwWidth; // 0x0C
    int lPitch; // 0x10
    unsigned int dwBackBufferCount; // 0x14
    unsigned int dwRefreshRate; // 0x18
    unsigned int dwAlphaBitDepth; // 0x1C
    unsigned int dwReserved; // 0x20
    void* lpSurface; // 0x24
    D2DDColorKeyStrc ddckCKDestOverlay; // 0x28
    D2DDColorKeyStrc ddckCKDestBlt; // 0x30
    D2DDColorKeyStrc ddckCKSrcOverlay; // 0x38
    D2DDColorKeyStrc ddckCKSrcBlt; // 0x40
    D2DDPixelFormatStrc ddpfPixelFormat; // 0x48
    unsigned int dwCaps; // 0x68
};

struct D2DDSurfaceDesc2Strc
{
    unsigned int dwSize; // 0x00
    unsigned int dwFlags; // 0x04
    unsigned int dwHeight; // 0x08
    unsigned int dwWidth; // 0x0C
    int lPitch; // 0x10
    unsigned int dwBackBufferCount; // 0x14
    unsigned int dwMipMapCount; // 0x18
    unsigned int dwAlphaBitDepth; // 0x1C
    unsigned int dwReserved; // 0x20
    void* lpSurface; // 0x24
    D2DDColorKeyStrc ddckCKDestOverlay; // 0x28
    D2DDColorKeyStrc ddckCKDestBlt; // 0x30
    D2DDColorKeyStrc ddckCKSrcOverlay; // 0x38
    D2DDColorKeyStrc ddckCKSrcBlt; // 0x40
    D2DDPixelFormatStrc ddpfPixelFormat; // 0x48
    unsigned int dwCaps; // 0x68
    unsigned int dwCaps2; // 0x6C
    unsigned int dwCaps3; // 0x70
    unsigned int dwCaps4; // 0x74
    unsigned int dwTextureStage; // 0x78
};

struct D2DDBltFxStrc
{
    unsigned int dwSize; // 0x00
    unsigned int dwDDFX; // 0x04
    unsigned int dwROP; // 0x08
    unsigned int dwDDROP; // 0x0C
    unsigned int dwRotationAngle; // 0x10
    unsigned int dwZBufferOpCode; // 0x14
    unsigned int dwZBufferLow; // 0x18
    unsigned int dwZBufferHigh; // 0x1C
    unsigned int dwZBufferBaseDest; // 0x20
    unsigned int dwZDestConstBitDepth; // 0x24
    unsigned int dwZDestConst; // 0x28
    unsigned int dwZSrcConstBitDepth; // 0x2C
    unsigned int dwZSrcConst; // 0x30
    unsigned int dwAlphaEdgeBlendBitDepth; // 0x34
    unsigned int dwAlphaEdgeBlend; // 0x38
    unsigned int dwReserved; // 0x3C
    unsigned int dwAlphaDestConstBitDepth; // 0x40
    unsigned int dwAlphaDestConst; // 0x44
    unsigned int dwAlphaSrcConstBitDepth; // 0x48
    unsigned int dwAlphaSrcConst; // 0x4C
    unsigned int dwFillColor; // 0x50
    D2DDColorKeyStrc ddckDestColorkey; // 0x54
    D2DDColorKeyStrc ddckSrcColorkey; // 0x5C
};

struct D2DDrawSurfaceVtblStrc
{
    void* QueryInterface; // 0x00
    void* AddRef; // 0x04
    unsigned long (__stdcall* Release)(D2DDrawSurfaceStrc* pThis); // 0x08
    void* AddAttachedSurface; // 0x0C
    void* AddOverlayDirtyRect; // 0x10
    long (__stdcall* Blt)(D2DDrawSurfaceStrc* pThis, void* pDestRect, D2DDrawSurfaceStrc* pSrcSurface, void* pSrcRect, unsigned long dwFlags, D2DDBltFxStrc* pBltFx); // 0x14
    void* BltBatch; // 0x18
    long (__stdcall* BltFast)(D2DDrawSurfaceStrc* pThis, unsigned long dwX, unsigned long dwY, D2DDrawSurfaceStrc* pSrcSurface, void* pSrcRect, unsigned long dwTrans); // 0x1C
    void* DeleteAttachedSurface; // 0x20
    void* EnumAttachedSurfaces; // 0x24
    void* EnumOverlayZOrders; // 0x28
    long (__stdcall* Flip)(D2DDrawSurfaceStrc* pThis, D2DDrawSurfaceStrc* pTargetOverride, unsigned long dwFlags); // 0x2C
    void* GetAttachedSurface; // 0x30
    void* GetBltStatus; // 0x34
    void* GetCaps; // 0x38
    void* GetClipper; // 0x3C
    void* GetColorKey; // 0x40
    void* GetDC; // 0x44
    void* GetFlipStatus; // 0x48
    void* GetOverlayPosition; // 0x4C
    void* GetPalette; // 0x50
    void* GetPixelFormat; // 0x54
    void* GetSurfaceDesc; // 0x58
    void* Initialize; // 0x5C
    void* IsLost; // 0x60
    long (__stdcall* Lock)(D2DDrawSurfaceStrc* pThis, void* pDestRect, D2DDSurfaceDescStrc* pSurfaceDesc, unsigned long dwFlags, void* hEvent); // 0x64
    void* ReleaseDC; // 0x68
    void* Restore; // 0x6C
    void* SetClipper; // 0x70
    void* SetColorKey; // 0x74
    void* SetOverlayPosition; // 0x78
    void* SetPalette; // 0x7C
    long (__stdcall* Unlock)(D2DDrawSurfaceStrc* pThis, void* pRect); // 0x80
    void* UpdateOverlay; // 0x84
    void* UpdateOverlayDisplay; // 0x88
    void* UpdateOverlayZOrder; // 0x8C
};

struct D2DDrawSurfaceStrc
{
    D2DDrawSurfaceVtblStrc* lpVtbl; // 0x00
};

struct D2DDSurfaceVtbl
{
    void* QueryInterface; // 0x00
    void* AddRef; // 0x04
    unsigned long (__stdcall* Release)(D2DDSurfaceStrc* pThis); // 0x08
    void* AddAttachedSurface; // 0x0C
    void* AddOverlayDirtyRect; // 0x10
    void* Blt; // 0x14
    void* BltBatch; // 0x18
    void* BltFast; // 0x1C
    void* DeleteAttachedSurface; // 0x20
    void* EnumAttachedSurfaces; // 0x24
    void* EnumOverlayZOrders; // 0x28
    void* Flip; // 0x2C
    void* GetAttachedSurface; // 0x30
    void* GetBltStatus; // 0x34
    void* GetCaps; // 0x38
    void* GetClipper; // 0x3C
    void* GetColorKey; // 0x40
    void* GetDC; // 0x44
    void* GetFlipStatus; // 0x48
    void* GetOverlayPosition; // 0x4C
    void* GetPalette; // 0x50
    void* GetPixelFormat; // 0x54
    void* GetSurfaceDesc; // 0x58
    void* Initialize; // 0x5C
    void* IsLost; // 0x60
    long (__stdcall* Lock)(D2DDSurfaceStrc* pThis, void* pRect, D2DDSurfaceDesc2Strc* pDesc, unsigned long dwFlags, void* hEvent); // 0x64
    void* ReleaseDC; // 0x68
    void* Restore; // 0x6C
    void* SetClipper; // 0x70
    void* SetColorKey; // 0x74
    void* SetOverlayPosition; // 0x78
    void* SetPalette; // 0x7C
    long (__stdcall* Unlock)(D2DDSurfaceStrc* pThis, void* pRect); // 0x80
    void* UpdateOverlay; // 0x84
    void* UpdateOverlayDisplay; // 0x88
    void* UpdateOverlayZOrder; // 0x8C
    void* GetDDInterface; // 0x90
    void* PageLock; // 0x94
    void* PageUnlock; // 0x98
    void* SetSurfaceDesc; // 0x9C
    void* SetPrivateData; // 0xA0
    void* GetPrivateData; // 0xA4
    void* FreePrivateData; // 0xA8
    void* GetUniquenessValue; // 0xAC
    void* ChangeUniquenessValue; // 0xB0
};

struct D2DDSurfaceStrc
{
    D2DDSurfaceVtbl* lpVtbl; // 0x00
};

struct D2DDrawObjectVtblStrc
{
    void* QueryInterface; // 0x00
    void* AddRef; // 0x04
    unsigned long (__stdcall* Release)(D2DDrawObjectStrc* pThis); // 0x08
    void* Compact; // 0x0C
    void* CreateClipper; // 0x10
    void* CreatePalette; // 0x14
    void* CreateSurface; // 0x18
    void* DuplicateSurface; // 0x1C
    void* EnumDisplayModes; // 0x20
    void* EnumSurfaces; // 0x24
    void* FlipToGDISurface; // 0x28
    void* GetCaps; // 0x2C
    void* GetDisplayMode; // 0x30
    void* GetFourCCCodes; // 0x34
    void* GetGDISurface; // 0x38
    void* GetMonitorFrequency; // 0x3C
    void* GetScanLine; // 0x40
    void* GetVerticalBlankStatus; // 0x44
    void* Initialize; // 0x48
    void* RestoreDisplayMode; // 0x4C
    void* SetCooperativeLevel; // 0x50
    void* SetDisplayMode; // 0x54
    void* WaitForVerticalBlank; // 0x58
};

struct D2DDrawObjectStrc
{
    D2DDrawObjectVtblStrc* lpVtbl; // 0x00
};

D2_CHECK_SIZE(D2DDSurfaceDescStrc, 0x6C);
D2_CHECK_SIZE(D2DDSurfaceDesc2Strc, 0x7C);
D2_CHECK_SIZE(D2DDBltFxStrc, 0x64);
D2_CHECK_SIZE(D2DDrawSurfaceVtblStrc, 0x90);
D2_CHECK_SIZE(D2DDrawSurfaceStrc, 0x4);
D2_CHECK_SIZE(D2DDSurfaceVtbl, 0xB4);
D2_CHECK_SIZE(D2DDSurfaceStrc, 0x4);
D2_CHECK_SIZE(D2DDrawObjectVtblStrc, 0x5C);
D2_CHECK_SIZE(D2DDrawObjectStrc, 0x4);
