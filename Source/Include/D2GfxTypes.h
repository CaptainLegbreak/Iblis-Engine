#pragma once
// D2Gfx: renderer settings, palette view, RGB triple and Smacker movie layouts shared by the render modules

#include "D2Check.h"
#include "D2Structs.h"

struct D2TileLibraryEntryStrc;
struct D2GfxLightExStrc;
struct D2TileLightStrc;
struct D2RgbColorStrc;
struct D2GfxSettingsStrc;
struct D2PaletteTableStrc;
struct D2SmackStrc;
struct D2BinkStrc;
struct D2SmackRecordStrc;
struct D2BoundsStrc;
struct D2ClipStrc;
struct D2GlideRectViewStrc;
struct D2TileDrawFunctionsStrc;

struct D2RgbColorStrc
{
    unsigned char nRed; // 0x00
    unsigned char nGreen; // 0x01
    unsigned char nBlue; // 0x02
};

struct D2GfxSettingsStrc
{
    int bPerspectiveEnabled; // 0x00
    int bPerspectiveCapable; // 0x04
    int bLowQuality; // 0x08
    int nGamma; // 0x0C
    int bVSync; // 0x10
    int bBlendedShadows; // 0x14
};

struct D2PaletteTableStrc
{
    unsigned char* pTransPalettes[3]; // 0x00
    unsigned char* pShadowLightGammaPalettes[49]; // 0x0C
    unsigned char* pStandardShiftPalettes[13]; // 0xD0 (the draw code indexes up to 18 here, into the slots that follow)
    unsigned char* pScreenPalette; // 0x104
    unsigned char* pLuminancePalette; // 0x108
    unsigned char* pDarkBlendPalette; // 0x10C
    unsigned char* pDarkenPalette; // 0x110
    unsigned char* pStandardColorsPalette; // 0x114
    unsigned char* pRemap; // 0x118
    unsigned char* pRedPaletteMap; // 0x11C
};

struct D2SmackStrc
{
    int nVersion; // 0x00
    int nWidth; // 0x04
    int nHeight; // 0x08
    int nFrames; // 0x0C
    int unk0x10[22]; // 0x10
    int bNewPalette; // 0x68
    D2RgbColorStrc aPalette[256]; // 0x6C
    int unk0x36C[2]; // 0x36C
    int nFrameNum; // 0x374
};

struct D2SmackRecordStrc
{
    union
    {
        void* hSmack; // 0x00
        D2SmackStrc* pSmack;
    };
    unsigned char nType; // 0x04
    int nX; // 0x08
    int nY; // 0x0C
};

struct D2BinkStrc
{
    unsigned int nWidth; // 0x00
    unsigned int nHeight; // 0x04
    unsigned int nFrames; // 0x08
    unsigned int nFrameNum; // 0x0C
};

struct D2BoundsStrc
{
    int nLeft; // 0x00
    int nRight; // 0x04
    int nTop; // 0x08
    int nBottom; // 0x0C
};

struct D2ClipStrc
{
    int nLeft; // 0x00
    int nWidth; // 0x04
    int nTop; // 0x08
    int nHeight; // 0x0C
};

struct D2GlideRectViewStrc
{
    int unk0x00; // 0x00
    int nLeft; // 0x04
    int nTop; // 0x08
    int nOffsetX; // 0x0C
    int nOffsetY; // 0x10
};

struct D2TileDrawFunctionsStrc
{
    void (__fastcall* pfFillYBufferTable)(unsigned char* pBits, int nWidth, int nHeight, int); // 0x00
    void (__fastcall* pfDrawWallBlock)(void* pData, int nX, int nY); // 0x04
    void* unk0x08; // 0x08
    int (__fastcall* pfDrawFloorTile)(D2TileLibraryEntryStrc* pTile, int nPosX, int nPosY, D2GfxLightExStrc* pLight); // 0x0C
    void (__fastcall* pfDrawBlock)(unsigned char* pData, int nX, int nY, D2TileLightStrc* pLight); // 0x10
    void (__fastcall* pfDrawShadowBlock)(void* pData, int nX, int nY, int nAlpha); // 0x14
    void (__fastcall* pfDrawLitBlock)(unsigned char* pData, int nX, int nY, D2TileLightStrc* pLight, int nArg); // 0x18
};

D2_CHECK_SIZE(D2RgbColorStrc, 0x3);
D2_CHECK_SIZE(D2GfxSettingsStrc, 0x18);
D2_CHECK_SIZE(D2PaletteTableStrc, 0x120);
D2_CHECK_SIZE(D2SmackStrc, 0x378);
D2_CHECK_SIZE(D2SmackRecordStrc, 0x10);
D2_CHECK_SIZE(D2BinkStrc, 0x10);
D2_CHECK_SIZE(D2BoundsStrc, 0x10);
D2_CHECK_SIZE(D2ClipStrc, 0x10);
D2_CHECK_SIZE(D2GlideRectViewStrc, 0x14);
D2_CHECK_SIZE(D2TileDrawFunctionsStrc, 0x1C);
