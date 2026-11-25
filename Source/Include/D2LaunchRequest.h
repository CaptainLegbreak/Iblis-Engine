#pragma once
// Launch: the game list request that WINMAIN_SendMcpGameListRequest sends to the realm (five data words and
// flags).

#include "D2Check.h"

struct D2LaunchRequestStrc
{
    int nData[5]; // 0x00
    unsigned int dwFlags; // 0x14
};
