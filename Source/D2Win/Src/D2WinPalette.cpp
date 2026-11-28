#include "D2Win.h"

#include "D2GfxTypes.h"

#include "D2Win32Types.h"
#include "FogApi.h"
#include "D2CMPApi.h"

struct D2Palette256Strc
{
    unsigned char data[256];
};

struct D2TransPaletteStrc
{
    unsigned char data[65536];
};

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize); // 0x006829C0


void __cdecl PALETTE_ApplyPaletteTables(); // 0x004FB010

void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0


extern const char gszD2WinPaletteSourceFile[]; // 0x006DC828

unsigned char gabStandardColorsPalette[39]; // 0x007D563C

extern unsigned char gabDarkenPalette[256]; // 0x0081E468

extern unsigned char gabRedPaletteMap[256]; // 0x0081E568

extern tagPALETTEENTRY gatRGBAPalette[256]; // 0x0081E668

extern D2Palette256Strc gatShadowsLightGammaPalette[49]; // 0x0081EA68



extern unsigned char gabLuminancePalette[65536]; // 0x00821B68

extern unsigned char gabDarkBlendPalette[65536]; // 0x00831B68

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern int gbPaletteFlash; // 0x0072DE50

int gnPaletteFlashCount; // 0x007D5638

unsigned char gabStatesPalette[128][0x100]; // 0x007D6468

int gbPaletteFlashWaiting; // 0x00841B68

unsigned long gdwPaletteFlashTick; // 0x00841B6C

D2Palette256Strc gatStandardShiftsPalette[13]; // 0x007D5668
unsigned char gabPaletteRemap[256]; // 0x007D6368
unsigned char gabScreenPalette[65536]; // 0x007DE468
D2TransPaletteStrc gatTransPalette[3]; // 0x007EE468
extern unsigned char gabDarkenPalette[256]; // 0x0081E468
extern unsigned char gabRedPaletteMap[256]; // 0x0081E568
extern D2Palette256Strc gatShadowsLightGammaPalette[49]; // 0x0081EA68
extern unsigned char gabLuminancePalette[65536]; // 0x00821B68
extern unsigned char gabDarkBlendPalette[65536]; // 0x00831B68

// 0x004FB010
void __cdecl PALETTE_ApplyPaletteTables()
{
    D2PaletteTableStrc tPaletteTable;

    for (int i = 0; i < 3; ++i)
    {
        tPaletteTable.pTransPalettes[i] = gatTransPalette[i].data;
    }

    for (int i = 0; i < 49; ++i)
    {
        tPaletteTable.pShadowLightGammaPalettes[i] = gatShadowsLightGammaPalette[i].data;
    }

    for (int i = 0; i < 13; ++i)
    {
        tPaletteTable.pStandardShiftPalettes[i] = gatStandardShiftsPalette[i].data;
    }

    tPaletteTable.pScreenPalette = gabScreenPalette;
    tPaletteTable.pLuminancePalette = gabLuminancePalette;
    tPaletteTable.pDarkBlendPalette = gabDarkBlendPalette;
    tPaletteTable.pDarkenPalette = gabDarkenPalette;
    tPaletteTable.pStandardColorsPalette = gabStandardColorsPalette;
    tPaletteTable.pRemap = gabPaletteRemap;
    tPaletteTable.pRedPaletteMap = gabRedPaletteMap;
    D2GFX_SetPaletteTables(&tPaletteTable);
}

// 0x004FB0C0
unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex)
{
    return gabStatesPalette[nIndex];
}

// 0x004FB0D0
void __stdcall D2Win_10179_UpdatePaletteFlash()
{
    if (!gbPaletteFlash)
    {
        return;
    }

    if (gbPaletteFlashWaiting)
    {
        if (GetTickCount() - gdwPaletteFlashTick <= 2000)
        {
            return;
        }

        gdwPaletteFlashTick = GetTickCount();

        --gnPaletteFlashCount;
        if (gnPaletteFlashCount > 0)
        {
            D2GFX_SetPalette(gatRGBAPalette);
            return;
        }

        gbPaletteFlashWaiting = 0;
    }

    gbPaletteFlash = 0;
    D2GFX_SetPalette(gatRGBAPalette);
}

// 0x004FB130
void __fastcall D2Win_10176_StartPaletteFlash(int bTimed)
{
    if (bTimed)
    {
        gbPaletteFlashWaiting = 1;
        gdwPaletteFlashTick = GetTickCount();
        gnPaletteFlashCount = 2;
        gbPaletteFlash = 1;
        D2GFX_SetPalette(gatRGBAPalette);
    }
    else
    {
        gbPaletteFlashWaiting = 0;
        gbPaletteFlash = 0;
        D2GFX_SetPalette(gatRGBAPalette);
    }
}

// 0x004FB180
unsigned char __stdcall PALETTE_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue)
{
    return GetClosestColor((const unsigned char*)gatRGBAPalette, 0x100, nRed, nGreen, nBlue);
}

extern tagPALETTEENTRY gatRGBAPalette[256]; // 0x0081E668

// 0x004FB1B0
void __cdecl PALETTE_ApplyScreenPalette()
{
    D2GFX_SetPalette(gatRGBAPalette);
}

// 0x004FB1C0
void __fastcall D2Win_10178_CopyGammaTable(unsigned char (*pRows)[0x100])
{
    memcpy(pRows, gatShadowsLightGammaPalette, sizeof(gatShadowsLightGammaPalette));
}

// 0x004FB1E0
int __stdcall PALETTE_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName)
{
    tagPALETTEENTRY tPalette[256];
    unsigned char* pDat = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szDatFileName, 0, gszD2WinPaletteSourceFile, 99);
    unsigned char* pColor = pDat;
    for (unsigned int i = 0; i < 256; ++i)
    {
        tPalette[i].peRed = *pColor++;
        tPalette[i].peGreen = *pColor++;
        tPalette[i].peBlue = *pColor++;
        tPalette[i].peFlags = 0;
    }

    unsigned char* pTables = (unsigned char*)sub_00517079_LoadFile(D2Win_GetArchive(), szPL2FileName, 0, gszD2WinPaletteSourceFile, 114);
    memcpy(gatRGBAPalette, pTables, sizeof(gatRGBAPalette));
    memcpy(gatTransPalette, pTables + 0x3500, sizeof(gatTransPalette));
    memcpy(gatShadowsLightGammaPalette, pTables + 0x400, sizeof(gatShadowsLightGammaPalette));
    memcpy(gabLuminancePalette, pTables + 0x43500, sizeof(gabLuminancePalette));
    memcpy(gabScreenPalette, pTables + 0x33500, sizeof(gabScreenPalette));
    memcpy(&gatShadowsLightGammaPalette[32], pTables + 0x2400, 16 * sizeof(D2Palette256Strc));
    memcpy(&gatShadowsLightGammaPalette[48], pTables + 0x3400, sizeof(D2Palette256Strc));
    memcpy(gabStatesPalette, pTables + 0x53500, sizeof(gabStatesPalette));
    memcpy(gabDarkBlendPalette, pTables + 0x5B500, sizeof(gabDarkBlendPalette));
    memcpy(gabDarkenPalette, pTables + 0x6B500, sizeof(gabDarkenPalette));
    memcpy(gabStandardColorsPalette, pTables + 0x6B600, sizeof(gabStandardColorsPalette));
    memcpy(gatStandardShiftsPalette, pTables + 0x6B627, sizeof(gatStandardShiftsPalette));

    for (unsigned int i = 0; i < 256; ++i)
        gatRGBAPalette[i].peFlags = 5;

    tagPALETTEENTRY* pEntry = gatRGBAPalette;
    for (unsigned int i = 0; i < 256; ++i)
    {
        const int nScaledRed = 170 * pEntry->peRed / 100;
        const int nRed = D2_MIN(255, nScaledRed);
        const int nScaledGreen = 170 * pEntry->peGreen / 100;
        const int nGreen = D2_MIN(255, nScaledGreen);
        const int nBlue = D2_MIN(255, 170 * pEntry->peBlue / 100);
        gabPaletteRemap[i] = PALETTE_FindPaletteIndex(nRed, nGreen, nBlue);
        gabRedPaletteMap[i] = PALETTE_FindPaletteIndex(pEntry->peRed, 0, 0);
        ++pEntry;
    }

    PALETTE_ApplyPaletteTables();
    D2GFX_SetPalette(gatRGBAPalette);
    FOG_Free(pDat, gszD2WinPaletteSourceFile, 150, 0);
    FOG_Free(pTables, gszD2WinPaletteSourceFile, 153, 0);
    return 1;
}

#pragma pack(push, 1)
struct d2data_0072DE14_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" const char gData_006DC828[24]; // 0x006DC828
extern "C" struct d2data_0072DE14_t gData_0072DE14; // 0x0072DE14

extern int gbPaletteFlash = 1; // 0x0072DE50

extern "C" const char gData_006DC828[24] = ".\\Src\\D2WinPalette.cpp"; // 0x006DC828
#pragma comment(linker, "/alternatename:?gszD2WinPaletteSourceFile@@3QBDB=_gData_006DC828")

extern "C" struct d2data_0072DE14_t gData_0072DE14 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x0072DE14
