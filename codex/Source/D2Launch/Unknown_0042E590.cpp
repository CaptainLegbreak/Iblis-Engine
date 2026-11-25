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

#include "gen/data/Source/D2Launch/Unknown_0042E590.inc"
