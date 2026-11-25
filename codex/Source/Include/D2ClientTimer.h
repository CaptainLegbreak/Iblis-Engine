#pragma once
// Client: the game's simple timers (a start tick and a length), as GAME_IsTimerExpired and
// GAME_IsTimerRunning test them.

#include "D2Check.h"

struct D2LoadingTimerStrc
{
    unsigned long dwStart; // 0x00
    unsigned long dwLength; // 0x04
    D2LoadingTimerStrc() : dwStart(0), dwLength(0)
    {
    }
};

D2_CHECK_SIZE(D2LoadingTimerStrc, 0x8);
