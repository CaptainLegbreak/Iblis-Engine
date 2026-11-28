#pragma once
// Win32: the GUID record (interface and property-set identifiers).

struct D2GuidStrc
{
    unsigned long Data1; // 0x00
    unsigned short Data2; // 0x04
    unsigned short Data3; // 0x06
    unsigned char Data4[8]; // 0x08
};
