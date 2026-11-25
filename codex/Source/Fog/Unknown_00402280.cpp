#include "D2CrashTypes.h"
#include "D2SysTypes.h"
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);       // 0x006CC214
extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2
typedef int (__stdcall* SymSetSearchPathFn)(void* hProcess, const char* szSearchPath);
extern void* ghProcess;                                                                            // 0x0074C6F0
extern void* ghDbgHelp;                                                                            // 0x0098A680
extern SymSetSearchPathFn gpfnSymSetSearchPath;                                                    // 0x0098A690
extern bool gbSymInitialized;                                                                      // 0x0098A6B0
extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0
extern char gszSymSearchPath[];                                                                    // 0x0098A708
bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00
bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00402280
int __fastcall sub_00402280_SetSearchPath(const char* szSearchPath)
{
    D2SymbolLockGuardStrc tGuard;
    strncpy_s(gszSymSearchPath, 0x8000, szSearchPath, (unsigned int)-1);
    if (!gbSymInitialized)
        return 1;
    if ((ghDbgHelp || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized || sub_00401CB0_InitSymbols())
        && gpfnSymSetSearchPath)
        return gpfnSymSetSearchPath(ghProcess, szSearchPath);
    return 0;
}
