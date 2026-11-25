#pragma once
// Client: the key configuration file (.key) the client saves and loads (tag, version, size, then the
// key table), and the button record of the key configuration screen.

#include "D2Check.h"

struct D2KeyConfigFileStrc
{
    unsigned short wTag; // 0x00
    unsigned short wVersion; // 0x02
    unsigned short wSize; // 0x04
    unsigned char aBody[0x474]; // 0x06
};

#pragma pack(push, 2)
struct D2KeyConfigButtonStrc
{
    unsigned short nString;
    unsigned char unk0x02[4];
    int nColor;
    int nX;
    unsigned char unk0x0E[0x0C];
};
#pragma pack(pop)
