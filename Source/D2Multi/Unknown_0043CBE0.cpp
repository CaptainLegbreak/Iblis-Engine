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

#pragma pack(push, 1)
struct d2data_0070CCD8_t
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

#pragma pack(push, 1)
struct d2data_0070CD14_t
{
    const void* p0;
};
#pragma pack(pop)

extern "C" struct d2data_0070CCD8_t gData_0070CCD8; // 0x0070CCD8
extern "C" struct d2data_0070CD14_t gData_0070CD14; // 0x0070CD14

extern "C" struct d2data_0070CCD8_t gData_0070CCD8 = {
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
}; // 0x0070CCD8

extern "C" struct d2data_0070CD14_t gData_0070CD14 = {
    (const void*)(unsigned int)&CHATDLG_StartChat
}; // 0x0070CD14
#pragma comment(linker, "/alternatename:?gtInterface@@3UD2ModuleInterfaceStrc@@A=_gData_0070CD14")
