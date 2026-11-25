#pragma once
// Win32: the system information GetSystemInfo fills (the page size, the address range, the processors
// and the allocation granularity), as the modules declare it for themselves.

#include "D2Check.h"

struct D2SystemInfoStrc
{
    unsigned long dwOemId; // 0x00
    unsigned long dwPageSize; // 0x04
    void* lpMinimumApplicationAddress; // 0x08
    void* lpMaximumApplicationAddress; // 0x0C
    unsigned long dwActiveProcessorMask; // 0x10
    unsigned long dwNumberOfProcessors; // 0x14
    unsigned long dwProcessorType; // 0x18
    unsigned long dwAllocationGranularity; // 0x1C
    unsigned short wProcessorLevel; // 0x20
    unsigned short wProcessorRevision; // 0x22
};
