#include "Storm.h"

void __cdecl sub_006CB400_Nop(); // 0x006CB400
int __cdecl sub_00683824_RegisterExit(void (__cdecl* callback)()); // 0x00683824

// 0x006CADE0
void __cdecl sub_006CADE0_RegisterCleanup()
{
    sub_00683824_RegisterExit(sub_006CB400_Nop);
}

#include "gen/data/Source/Storm/Unknown_006CACE0.inc"

