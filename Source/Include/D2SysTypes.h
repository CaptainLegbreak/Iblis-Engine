#pragma once
// Win32 system records mirrored by several modules: the critical section

#include "D2Check.h"

struct D2CriticalSectionStrc
{
    void* pDebugInfo; // 0x00
    long nLockCount; // 0x04
    long nRecursionCount; // 0x08
    void* hOwningThread; // 0x0C
    void* hLockSemaphore; // 0x10
    unsigned long nSpinCount; // 0x14
};

D2_CHECK_SIZE(D2CriticalSectionStrc, 0x18);
