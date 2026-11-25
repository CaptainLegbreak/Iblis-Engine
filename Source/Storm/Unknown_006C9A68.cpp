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

#include "gen/data/Source/Storm/Unknown_006C9A68.inc"

const char* gpszCaption_007A0450; // 0x007A0450

// 0x006CAC10
void __cdecl sub_006CAC10_InitializeHorizontalPosition()
{
    gnTextLeft = (gnScreenWidth_0071146C - 325) / 2;
}
