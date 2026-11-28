#include "D2Win.h"

#include "D2GfxTypes.h"
#include "FogApi.h"
#include "StormApi2.h"
#include "D2GfxApi.h"
#include "D2ClientApi.h"
#include "D2GfxApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#define gnRowOffsets_007C9828 (ganRowOffsets + 32)

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))

#define DISPLAYTYPE_GLIDE 4

struct D2PaletteStrc;

struct D2TileLibraryBlockStrc;

struct D2PaletteStrc
{
    unsigned char unk0x00[0x100];
};


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2PaletteStrc gatLightPalettes[]; // 0x007D2348

extern "C" int gfSStrInitialized;


extern "C" int gbClientSoundReady;

extern "C" int gnSoundSerial;

extern "C" int gnSubsystemActive;

int __stdcall GAME_Shutdown(); // 0x0052C030

extern D2PaletteTableStrc gtPaletteTables; // 0x007D5458

extern int gnViewMatrixAdjustDefault; // 0x0072DBFC

extern int gnDisplayType; // 0x007C8CB0

extern D2GfxSettingsStrc gGfxSettings; // 0x0072DA48

int gnLightingOff; // 0x007D2340

// 0x004F8DC0
extern "C" void __cdecl sub_004F8DC0_InitLookupTable()
{
    CMNSUBTILE_BuildGouraudCache();
    gpScreenBuffer = 0;
}

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
void __fastcall WINDOW_SetScreenBuffer(unsigned char* pBuffer, int nWidth, int nHeight, int nArg4)
{
    gpScreenBuffer = pBuffer;
    gnScreenPitch = nWidth;
    gnYBufferArg3 = nHeight;
    gnYBufferArg4 = nArg4;

    if (nWidth != gnYBufferPitch)
    {
        gnScreenPitch = nWidth;
        gnYBufferPitch = nWidth;
        CMNSUBTILE_BuildLineOffsets();
    }

    if (gnViewMatrixAdjust != gnViewMatrixAdjustDefault)
    {
        WINDOW_SetPanelCoords(nWidth, nHeight);
    }
}

// 0x004F8EA0
void __cdecl WINDOW_LoadGammaSettings()
{
    unsigned long nContrast = gnDisplayType != DISPLAYTYPE_GLIDE ? 100 : 0;
    SRegLoadValue("Diablo II", "Contrast", 0, &nContrast);
    D2GFX_SetOption(11, nContrast);

    unsigned long nGamma = 155;
    SRegLoadValue("Diablo II", "Gamma", 0, &nGamma);
    gGfxSettings.nGamma = nGamma;
    D2GFX_SetGamma(nGamma);
}

int gnViewMatrixAdjustDefault = -1; // 0x0072DBFC
