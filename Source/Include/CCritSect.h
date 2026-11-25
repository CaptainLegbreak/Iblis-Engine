#pragma once
// Storm's lock wrapper: a critical section that is initialised and deleted with its owner. The export tables
// (stplhash.h's TSExportTableSync) take it as their TSYNC.

#include "D2SysTypes.h"

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

class CCritSect
{
public:
    D2CriticalSectionStrc m_critsect;

    CCritSect()
    {
        InitializeCriticalSection(&m_critsect);
    }
    ~CCritSect()
    {
        DeleteCriticalSection(&m_critsect);
    }
    void Enter()
    {
        EnterCriticalSection(&m_critsect);
    }
    void Leave()
    {
        LeaveCriticalSection(&m_critsect);
    }
};
