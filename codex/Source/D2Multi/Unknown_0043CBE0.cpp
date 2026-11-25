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

#include "gen/data/Source/D2Multi/Unknown_0043CBE0.inc"
