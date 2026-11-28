#include "Storm.h"


extern int gnTextLeft; // 0x007BF278

extern "C" char gData_006F28F8[]; // 0x006F28F8

extern "C" const void* gData_0070886C[2] = { gData_006F28F8, 0 }; // 0x0070886C

const char* gpszCaption_007A0450; // 0x007A0450

// 0x006CAC10
void __cdecl sub_006CAC10_InitializeHorizontalPosition()
{
    gnTextLeft = (gnScreenWidth_0071146C - 325) / 2;
}
