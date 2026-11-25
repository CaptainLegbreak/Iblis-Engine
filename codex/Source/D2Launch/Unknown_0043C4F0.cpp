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

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2);                          // 0x0042F2E0
void __cdecl MAINMENUS_Reset();                                                                          // 0x0042F480
void __cdecl MAINMENUS_ShowConnectingPopup();                                                                                // 0x0042F6E0
extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout(); // 0x00432EF0
extern "C" const char* const gapszSkyPalette[2];                                                   // 0x006D3A08
void __cdecl CHARSEL_CreateBaseScreen();                                                                                // 0x0043C4F0

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

#include "gen/data/Source/D2Launch/Unknown_0043C4F0.inc"
