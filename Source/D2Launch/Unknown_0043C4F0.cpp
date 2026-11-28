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

extern "C" const char* gData_0070CC50[15] = { // 0x0070CC50
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};
