#pragma once
// Win32: the process information CreateProcess fills and the memory status GlobalMemoryStatus fills, as the
// modules declare them for themselves.

#include "D2Check.h"

struct D2ProcessInformationStrc
{
    void* hProcess; // 0x00
    void* hThread; // 0x04
    unsigned long dwProcessId; // 0x08
    unsigned long dwThreadId; // 0x0C
};

struct D2MemoryStatusStrc
{
    unsigned long dwLength; // 0x00
    unsigned long dwMemoryLoad; // 0x04
    unsigned long dwTotalPhys; // 0x08
    unsigned long dwAvailPhys; // 0x0C
    unsigned long dwTotalPageFile; // 0x10
    unsigned long dwAvailPageFile; // 0x14
    unsigned long dwTotalVirtual; // 0x18
    unsigned long dwAvailVirtual; // 0x1C
};
