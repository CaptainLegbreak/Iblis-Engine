#include "D2Multi.h"

struct D2ModuleInterfaceStrc;
struct D2ConfigStrc;

int __fastcall CHATDLG_StartChat(D2ConfigStrc* pInfo); // 0x00442150

extern D2ModuleInterfaceStrc gtInterface; // 0x0070CD14
extern void* gpInstance; // 0x0077AD68

// 0x0043CBE0
D2ModuleInterfaceStrc* __fastcall CHATDLG_GetModuleInterface(void* hInstance)
{
    gpInstance = hInstance;
    return &gtInterface;
}

extern "C" const char* gData_0070CCD8[15] = { // 0x0070CCD8
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

extern "C" int (__fastcall* gData_0070CD14[1])(D2ConfigStrc* pInfo) = { &CHATDLG_StartChat }; // 0x0070CD14
#pragma comment(linker, "/alternatename:?gtInterface@@3UD2ModuleInterfaceStrc@@A=_gData_0070CD14")
