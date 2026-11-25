#include "D2CrashTypes.h"
#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
typedef int (__stdcall* SymUnloadModule64Fn)(void* hProcess, unsigned __int64 qwBaseOfDll);
extern void* ghProcess;                                                                            // 0x0074C6F0
extern void* ghDbgHelp;                                                                            // 0x0098A680
extern SymUnloadModule64Fn gpfnSymUnloadModule64;                                                  // 0x0098A694
extern bool gbSymInitialized;                                                                      // 0x0098A6B0
extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0
bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00402530
int __stdcall sub_00402530_UnloadModule(unsigned __int64 qwBaseOfDll)
{
    D2SymbolLockGuardStrc tGuard;
    if ((ghDbgHelp || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized || sub_00401CB0_InitSymbols())
        && gpfnSymUnloadModule64)
        return gpfnSymUnloadModule64(ghProcess, qwBaseOfDll) != 0;
    return 0;
}
