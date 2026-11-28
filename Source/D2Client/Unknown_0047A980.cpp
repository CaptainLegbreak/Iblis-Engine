#include "D2LanguageNames.h"

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

extern int gdwGlobal_00712F04 = 3; // 0x00712F04

extern int gdwClientFlags = 4; // 0x00712EFC

extern int gnCTemp = 1; // 0x00712F00

// 0x0047A980
int __cdecl CHAT_IsNumberDisplayEnabled()
{
    return gtClientFlagsLow_00712EFC.bNumberDisplay;
}

// 0x0047A990
int __cdecl DLIGHTMAP_GetClientFlags()
{
    return gdwClientFlags;
}

// 0x0047A9A0
void __fastcall CHAT_SetClientFlags(int nFlags)
{
    gdwClientFlags = nFlags;
}

// 0x0047A9B0
void __fastcall ROSTER_SetPrimaryClientFlag(int bClear)
{
    if (bClear)
    {
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
int __cdecl CHAT_GetClientFlag40()
{
    return gdwClientFlags & 0x40;
}

// 0x0047A9F0
int __cdecl CHAT_GetClientFlag80()
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
    gnCTemp = nValue;
}

// 0x0047AA20
int __cdecl DLIGHTMAP_GetCTemp()
{
    return gnCTemp;
}

// 0x0047AA30
int __cdecl CHAT_HasClassOverride()
{
    return gtClientFlags_00712EFC.bClassOverride;
}
