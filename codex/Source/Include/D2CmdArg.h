#pragma once
// The game's command-line table entry behind gaCmdArguments: the .ini section and key, the switch, the
// argument type, where the value goes and its default.

#include "D2Check.h"

struct D2CmdArgStrc
{
    char szSection[0x1B]; // 0x00
    char szKey[0x1B]; // 0x1B
    char szCommand[0x1B]; // 0x36
    unsigned char nType; // 0x51
    int nIndex; // 0x54
    int nDefault; // 0x58
};
