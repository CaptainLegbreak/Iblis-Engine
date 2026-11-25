#pragma once
// The interface table the launcher hands the game in D2ConfigStrc::pComInterface (0x225).
// D2Launch fills and calls it, the client keeps the pointer at 0x007A05F4, Storm calls it on shutdown.

#include "D2Check.h"

struct D2BnetChatPacketStrc;
struct D2ConfigStrc;
struct D2FuncRecordStrc;
struct D2LaunchPayloadStrc;
struct D2MenuListStrc;
struct D2StatusStrc;

struct D2ComInterfaceStrc
{
    int (__fastcall* pfnInit)(D2ConfigStrc*); // 0x00
    void* (__fastcall* pfnSlot04)(void); // 0x04
    void (__fastcall* pfnSlot08)(char*, char*); // 0x08
    int (__fastcall* pfnSlot0C)(void); // 0x0C
    union
    {
        void (__fastcall* pfnSlot10)(void); // 0x10
        int (__fastcall* pfnSlot10Result)(void);
    };
    void (__fastcall* pfnResign)(const char*); // 0x14
    int unk0x18; // 0x18
    int unk0x1C; // 0x1C
    int unk0x20; // 0x20
    int (__fastcall* pfnGetMessage)(int*, D2BnetChatPacketStrc*); // 0x24
    int (__fastcall* pfnSlot28)(D2StatusStrc*); // 0x28
    int unk0x2C[2]; // 0x2C
    void (__fastcall* pfnCharUpdate)(char*, char*, char*, int); // 0x34
    int unk0x38[2]; // 0x38
    D2MenuListStrc* (__fastcall* pfnGetMenuList)(int); // 0x40
    D2LaunchPayloadStrc* (__fastcall* pfn0x44)(const char*, const char*); // 0x44
    int (__fastcall* pfnSlot48)(int*); // 0x48
    int (__fastcall* pfnSlot4C)(void); // 0x4C
    void (__fastcall* pfnRequest)(const char*, int); // 0x50
    int unk0x54[3]; // 0x54
    void (__fastcall* pfnSlot60)(char*, char*); // 0x60
    int (__fastcall* pfnSlot64)(int*); // 0x64
    int (__fastcall* pfnSlot68)(void); // 0x68
    int unk0x6C; // 0x6C
    int (__fastcall* pfnSlot70)(void); // 0x70
    int unk0x74[3]; // 0x74
    void (__fastcall* pfnSlot80)(int*); // 0x80
    int unk0x84[3]; // 0x84
    void (__cdecl* pfnNotify)(void); // 0x90
    int unk0x94; // 0x94
    union
    {
        D2FuncRecordStrc* (__cdecl* pfnGetRecord)(void); // 0x98
        int (__fastcall* pfnSlot98)(void);
    };
    void (__fastcall* pfnSlot9C)(char*, char*, char*); // 0x9C
    int (__fastcall* pfnSlotA0)(int*); // 0xA0
    int unk0xA4[4]; // 0xA4
    int (__fastcall* pfnSlotB4)(void); // 0xB4
    void (__fastcall* pfnSlotB8)(char*); // 0xB8
    int (__fastcall* pfnSlotBC)(char*, char*); // 0xBC
    int (__fastcall* pfnSlotC0)(char*, char*, char*); // 0xC0
    void (__stdcall* pfnClose)(void); // 0xC4
};

D2_CHECK_SIZE(D2ComInterfaceStrc, 0xC8);
