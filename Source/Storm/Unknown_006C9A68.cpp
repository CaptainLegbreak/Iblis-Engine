#include "Storm.h"

struct D2Block006CAB30Strc;
struct D2Block006CAB90Strc;

struct D2Block006CAB30Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int n2C;
    int n30;
    int n34;
    int n38;
    int n3C;
};

struct D2Block006CAB90Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int n2C;
    int n30;
    int n34;
    int n38;
    int n3C;
};

extern int gnTextLeft; // 0x007BF278

extern "C" char gData_006F28F8[]; // 0x006F28F8

#pragma pack(push, 1)
struct d2data_0070886C_t
{
    const void* p0;
    unsigned char b1[4];
};
#pragma pack(pop)

extern "C" struct d2data_0070886C_t gData_0070886C; // 0x0070886C

extern "C" struct d2data_0070886C_t gData_0070886C = {
    (const void*)&gData_006F28F8,
    { 0x00 }
}; // 0x0070886C

const char* gpszCaption_007A0450; // 0x007A0450

// 0x006CAC10
void __cdecl sub_006CAC10_InitializeHorizontalPosition()
{
    gnTextLeft = (gnScreenWidth_0071146C - 325) / 2;
}
