#pragma once
// Fog's Safesock connection record (FOG_SafeSock*): Fog owns it, D2BNClient and D2MCPClient hold one.

#include "D2SysTypes.h"

struct FSafeSock
{
    int bConnected; // 0x00
    int bConnecting; // 0x04
    unsigned int nSocket; // 0x08
    D2CriticalSectionStrc tCriticalSection; // 0x0C
    void* hThread; // 0x24
    unsigned long nThreadId; // 0x28
    int bStopping; // 0x2C
    unsigned long nFogErrorCode; // 0x30
    unsigned long nWSALastError; // 0x34
    char szName[64]; // 0x38
};
