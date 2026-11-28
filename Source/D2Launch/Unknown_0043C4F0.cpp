#include "D2Launch.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2MultiTypes.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"
#include "D2LaunchRequest.h"

int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0
extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout(); // 0x00432EF0

// build: symbol ?MAINMENUS_ShowConnectingPopup@* 0x0042F6E0
// build: symbol ?gszOldPassword@* 0x00779550

// 0x0043C4F0
void __cdecl CHARSEL_CreateBaseScreen()
{
    MAINMENUS_Reset();
    MAINMENUS_CreateControl(8);
    MAINMENUS_CreateControl(6);
    MAINMENUS_CreateControl(7);
    MAINMENUS_ReadPaletteFiles(gapszSkyPalette[0], gapszSkyPalette[1]);
    MAINMENUS_ConfigureLanguageLayout();
}

#pragma pack(push, 1)
struct d2data_0070CC50_t
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

extern "C" struct d2data_0070CC50_t gData_0070CC50; // 0x0070CC50

extern "C" struct d2data_0070CC50_t gData_0070CC50 = {
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
}; // 0x0070CC50
