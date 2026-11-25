#pragma once
// Fog: the system information it captures at start (0x0074D88C) and FOG_GetSystemInfo returns once it is
// captured: the OS kind (1: NT 4 or older, 2: NT 5.0, 3: NT 5.1, 4: NT 5.2 or later, 0: anything else),
// the OS version and the physical memory.

#include "D2Check.h"

struct D2FogSystemInfoStrc
{
    int bCaptured; // 0x00
    int nOsKind; // 0x04
    float fOsVersion; // 0x08
    unsigned int dwTotalPhys; // 0x0C
};
