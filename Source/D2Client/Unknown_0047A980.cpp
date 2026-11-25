#include "D2Client.h"

struct D2ClientFlagsLowStrc
{
    unsigned char bFlag0 : 1;
    unsigned char bNumberDisplay : 1;
    unsigned char bFlags2 : 6;
};

struct D2ClientFlagsStrc
{
    unsigned int bFlags0 : 8;
    unsigned int bClassOverride : 1;
    unsigned int bFlags9 : 23;
};

extern D2ClientFlagsLowStrc gtClientFlagsLow_00712EFC; // 0x00712EFC

extern D2ClientFlagsStrc gtClientFlags_00712EFC; // 0x00712EFC

extern int gdwGlobal_00712F04; // 0x00712F04

#pragma pack(push, 1)
struct d2data_00712EC0_t
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

extern "C" struct d2data_00712EC0_t gData_00712EC0; // 0x00712EC0

extern "C" struct d2data_00712EC0_t gData_00712EC0 = {
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
}; // 0x00712EC0

extern int gdwClientFlags = 4; // 0x00712EFC

extern int gnCTemp = 1; // 0x00712F00

extern int gdwGlobal_00712F04 = 3; // 0x00712F04

// 0x0047A980
int __cdecl CHAT_IsNumberDisplayEnabled()
{
    return gtClientFlagsLow_00712EFC.bNumberDisplay;
}

// 0x0047A990
int __cdecl DLIGHTMAP_GetClientFlags()
{
// build: symbol ?gdwClientFlags@* 0x00712EFC
    return gdwClientFlags;
}

// 0x0047A9A0
void __fastcall CHAT_SetClientFlags(int nFlags)
{
// build: symbol ?gdwClientFlags@* 0x00712EFC
    gdwClientFlags = nFlags;
}

// 0x0047A9B0
void __fastcall ROSTER_SetPrimaryClientFlag(int bClear)
{
    if (bClear)
    {
// build: symbol ?gdwClientFlags@* 0x00712EFC
        gdwClientFlags &= ~1;
    }
    else
    {
        gdwClientFlags |= 1;
    }
}

// 0x0047A9D0
int __cdecl sub_0047A9D0()
{
    return gdwGlobal_00712F04;
}

// 0x0047A9E0
int __cdecl sub_0047A9E0_GetClientFlag40()
{
    return gdwClientFlags & 0x40;
}

// 0x0047A9F0
int __cdecl sub_0047A9F0_GetClientFlag80()
{
    return gdwClientFlags & 0x80;
}

// 0x0047AA00
int __cdecl sub_0047AA00_GetClientFlag200()
{
    return gdwClientFlags & 0x200;
}

// 0x0047AA10
void __fastcall ROSTER_SetCTemp(int nValue)
{
// build: symbol ?gnCTemp@* 0x00712F00
    gnCTemp = nValue;
}

// 0x0047AA20
int __cdecl DLIGHTMAP_GetCTemp()
{
// build: symbol ?gnCTemp@* 0x00712F00
    return gnCTemp;
}

// 0x0047AA30
int __cdecl CHAT_HasClassOverride()
{
    return gtClientFlags_00712EFC.bClassOverride;
}
