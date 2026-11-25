#include "D2Win.h"

#include "D2GfxTypes.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// build: symbol ?ganRowOffsets@* 0x007C97A8
#define gnRowOffsets_007C9828 (ganRowOffsets + 32)

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

#define DISPLAYTYPE_GLIDE 4

struct D2PaletteStrc;

struct D2TileLibraryBlockStrc;

struct D2PaletteStrc
{
    unsigned char unk0x00[0x100];
};

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall CMNSUBTILE_DrawIsoBlockFlat(unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette); // 0x004F69B0

void __fastcall D2GFX_DrawLitSubtileRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep); // 0x004F6BB0

void __fastcall CMNSUBTILE_DrawLitRleRows(unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg); // 0x004F71A0

void __fastcall CMNSUBTILE_DrawRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, unsigned char* pPalette, int nRows); // 0x004F7580

extern int gnClipBottom; // 0x007C978C

extern int gnClipLeft; // 0x007C9794

extern int gnInnerRight; // 0x007C9784

extern int gnInnerBottom; // 0x007C9790

extern int gnInnerTop; // 0x007CA31C

extern int gnClipRight; // 0x007D2324

extern int gnInnerLeft; // 0x007D2328

extern int gnClipTop; // 0x007D232C

extern D2PaletteStrc gatLightPalettes[]; // 0x007D2348

extern unsigned char* gpScreenBuffer; // 0x007D5448

extern int gnScreenPitch; // 0x007D544C

void __fastcall CMNSUBTILE_DrawLitRleRowsClipped(int nX, int nY, unsigned char* pSrc, unsigned char* pDst, int nLightX, int nLightXStep, int nLightY, int nLightYStep, int nRows, int nArg); // 0x004F7850

void __fastcall CMNSUBTILE_DrawVisTile(unsigned char* pSrc, int nX, int nY); // 0x004F7EA0

void __fastcall CMNSUBTILE_DrawRleVisTile(unsigned char* pSrc, int nX, int nY, unsigned char nLight); // 0x004F8050

extern "C" int gnFlag_007788DC;

extern "C" int gnBufferBase_007D5448; // 0x007D5448

extern "C" int gnSoundFlag_007C545C;

// build: symbol _gnSoundSerial 0x007C5460
extern "C" int gnSoundSerial;

// build: symbol _gnSubsystemActive 0x007A0458
extern "C" int gnSubsystemActive;

void __cdecl InitPowTable(); // 0x004142A0

extern "C" void __cdecl CMNSUBTILE_BuildGouraudCache(); // 0x004F7CC0

extern "C" void __cdecl sub_004E4280(); // 0x004E4280

int __stdcall GAME_Shutdown(); // 0x0052C030

extern D2PaletteTableStrc gtPaletteTables; // 0x007D5458

extern int gnViewMatrixAdjustDefault; // 0x0072DBFC

extern int gnDisplayType; // 0x007C8CB0

extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48

int __stdcall D2GFX_SetGamma(int nGamma); // 0x004F5230

int __fastcall D2GFX_SetOption(int nOption, int nValue); // 0x004F52B0

void __fastcall WINDOW_SetPanelCoords(int nPitch, int nHeight); // 0x004F7DA0

void __cdecl CMNSUBTILE_BuildLineOffsets(); // 0x004F7E70

unsigned char* gpScreenBuffer; // 0x007D5448

int gnLightingOff; // 0x007D2340

extern "C" void __cdecl SStrInitialize(); // 0x00414360

// 0x004F8DC0
extern "C" void __cdecl sub_004F8DC0_InitLookupTable()
{
    CMNSUBTILE_BuildGouraudCache();
    gnBufferBase_007D5448 = 0;
}

extern "C" void __cdecl SOUNDINST_ResetSoundState(); // 0x004B9D00

extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80

// 0x004F8DD0
void __cdecl sub_004F8DD0_Empty()
{
}

// 0x004F8E90
void __cdecl sub_004F8E90_SetDefaultPalettes()
{
    D2GFX_SetPaletteTables(&gtPaletteTables);
}

int gnYBufferArg3; // 0x007D5450

int gnYBufferArg4; // 0x007D5454

int gnYBufferPitch; // 0x007D557C

int gnViewMatrixAdjust; // 0x007C8CC4

// 0x004F8DE0
void __fastcall sub_004F8DE0(unsigned char* a1, int a2, int a3, int a4)
{
    gpScreenBuffer = a1;
    gnScreenPitch = a2;
    gnYBufferArg3 = a3;
    gnYBufferArg4 = a4;

    if (a2 != gnYBufferPitch)
    {
        gnScreenPitch = a2;
        gnYBufferPitch = a2;
        CMNSUBTILE_BuildLineOffsets();
    }

    if (gnViewMatrixAdjust != gnViewMatrixAdjustDefault)
    {
        WINDOW_SetPanelCoords(a2, a3);
    }
}

// 0x004F8EA0
void __cdecl sub_004F8EA0()
{
    unsigned long nContrast = gnDisplayType != DISPLAYTYPE_GLIDE ? 100 : 0;
    SRegLoadValue("Diablo II", "Contrast", 0, &nContrast);
    D2GFX_SetOption(11, nContrast);

    unsigned long nGamma = 155;
    SRegLoadValue("Diablo II", "Gamma", 0, &nGamma);
    gGfxSettings.nGamma = nGamma;
    D2GFX_SetGamma(nGamma);
}

#include "gen/data/Source/D2Win/Unknown_004F6F60.inc"
