#include "D2LanguageNames.h"

extern char gaTable_0070896C[]; // 0x0070896C

void* gpOwner_00779324; // 0x00779324

// 0x0042E590
void* __fastcall sub_0042E590_SetOwner(void* pOwner)
{
    gpOwner_00779324 = pOwner;
    return gaTable_0070896C;
}

// 0x0042E5A0
void __cdecl sub_0042E5A0_Nop()
{
}

extern "C" void __cdecl MAINMENUS_RunFrontEnd(); // 0x004359D0

#pragma pack(push, 1)
struct d2data_0070896C_t
{
    const void* p0;
};
#pragma pack(pop)

extern "C" struct d2data_0070896C_t gData_0070896C; // 0x0070896C

extern "C" struct d2data_0070896C_t gData_0070896C = {
    (const void*)(unsigned int)&MAINMENUS_RunFrontEnd
}; // 0x0070896C
#pragma comment(linker, "/alternatename:?gaTable_0070896C@@3PADA=_gData_0070896C")
