#include "Fog.h"
#include "D2GameTypes.h"

extern "C" __int64 __cdecl _time64(__int64* pTime);                                                        // 0x0068568B

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

extern void* gpfnSymCleanup;                                                                       // 0x0098A6B8

extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0

extern char gszLogDirectory[0x400];                                                                // 0x00992708

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryW(const wchar_t* szFileName); // 0x006CC294

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

void* gpfnSymGetOptions; // 0x0098A6AC

void* gpfnSymInitialize; // 0x0098A6A8

void* gpfnSymSetOptions; // 0x0098A6B4

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C

extern "C" __declspec(dllimport) unsigned long __stdcall GetProcessId(void* hProcess); // 0x006CC2A0

extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2

extern void* ghProcess; // 0x0074C6F0

void* ghDbgHelp; // 0x0098A680

typedef unsigned long (__stdcall* SymGetOptionsFn)();

typedef unsigned long (__stdcall* SymSetOptionsFn)(unsigned long dwOptions);

typedef int (__stdcall* SymInitializeFn)(void* hProcess, const char* szUserSearchPath, int bInvadeProcess);

void* gpfnEnumerateLoadedModules64; // 0x0098A6A4

void* gpfnStackWalk64; // 0x0098A6A0

void* gpfnSymFunctionTableAccess64; // 0x0098A698

void* gpfnSymGetLineFromAddr64; // 0x0098A6E8

void* gpfnSymGetModuleBase64; // 0x0098A69C

void* gpfnSymGetModuleInfo64; // 0x0098A684

void* gpfnSymGetSymFromAddr64; // 0x0098A68C

void* gpfnSymEnumerateModules64; // 0x0098A688

void* gpfnSymSetSearchPath; // 0x0098A690

void* gpfnSymFindFileInPath; // 0x0098A6EC

void* gpfnSymLoadModule64; // 0x0098A6DC

void* gpfnSymUnloadModule64; // 0x0098A694

void* gpfnMiniDumpWriteDump; // 0x0098A6E0

bool gbSymInitialized; // 0x0098A6B0

char gszSymSearchPath[32768]; // 0x0098A708

static inline size_t StrLCopy(char* szDest, const char* szSource, size_t nSize)
{
    const char* p = szSource;
    if (nSize)
    {
        size_t n = nSize - 1;
        if (n)
        {
            do
            {
                const char c = *p;
                *szDest = c;
                szDest++;
                p++;
                if (!c)
                {
                    break;
                }
            } while (--n);
        }
        if (!n)
        {
            *szDest = 0;
        }
        else
        {
            return p - szSource - 1;
        }
    }
    while (*p++)
    {
    }
    return p - szSource - 1;
}

// 0x00401010
__int64 __cdecl sub_00401010_GetTime64()
{
    return _time64(0);
}

// 0x00401020
static inline bool sub_00401020_SetLogDirectory(const char* szPath)
{
    return StrLCopy(gszLogDirectory, szPath, 0x400) < 0x400 ? true : false;
}

bool sub_M123_Emit_00401020(const char* szPath)
{
    return sub_00401020_SetLogDirectory(szPath);
}

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// 0x00401B00
bool __cdecl sub_00401B00_LoadDbgHelp()
{
    if (ghDbgHelp)
    {
        return true;
    }
    void* hModule = LoadLibraryW(L"DbgHelp.dll");
    if (!hModule)
    {
        return false;
    }
    if (!(gpfnEnumerateLoadedModules64 = GetProcAddress(hModule, "EnumerateLoadedModules64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnStackWalk64 = GetProcAddress(hModule, "StackWalk64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymFunctionTableAccess64 = GetProcAddress(hModule, "SymFunctionTableAccess64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetLineFromAddr64 = GetProcAddress(hModule, "SymGetLineFromAddr64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetModuleBase64 = GetProcAddress(hModule, "SymGetModuleBase64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetModuleInfo64 = GetProcAddress(hModule, "SymGetModuleInfo64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetOptions = GetProcAddress(hModule, "SymGetOptions")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymGetSymFromAddr64 = GetProcAddress(hModule, "SymGetSymFromAddr64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymInitialize = GetProcAddress(hModule, "SymInitialize")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymCleanup = GetProcAddress(hModule, "SymCleanup")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymSetOptions = GetProcAddress(hModule, "SymSetOptions")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymEnumerateModules64 = GetProcAddress(hModule, "SymEnumerateModules64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymSetSearchPath = GetProcAddress(hModule, "SymSetSearchPath")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymFindFileInPath = GetProcAddress(hModule, "SymFindFileInPath")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymLoadModule64 = GetProcAddress(hModule, "SymLoadModule64")))
    {
        CloseHandle(hModule);
        return false;
    }
    if (!(gpfnSymUnloadModule64 = GetProcAddress(hModule, "SymUnloadModule64")))
    {
        CloseHandle(hModule);
        return false;
    }
// build: symbol ?gszMiniDumpWriteDump@* 0x006FFB94
    gpfnMiniDumpWriteDump = GetProcAddress(hModule, gszMiniDumpWriteDump);
    ghDbgHelp = hModule;
    return true;
}

// 0x00401C80
void __cdecl sub_00401C80_FreeDbgHelp()
{
// build: symbol ?gbSymInitialized@* 0x0098A6B0
    if (gbSymInitialized)
    {
// build: symbol ?ghDbgHelp@* 0x0098A680
        if (ghDbgHelp)
        {
            FreeLibrary(ghDbgHelp);
            ghDbgHelp = 0;
        }
    }
}

// 0x00401CB0
bool __cdecl sub_00401CB0_InitSymbols()
{
    char szPath[0x8000];

    if (gbSymInitialized)
    {
        return true;
    }

    if (!ghDbgHelp)
    {
        return false;
    }

    if (!gpfnSymSetOptions)
    {
        return false;
    }

    if (!gpfnSymInitialize)
    {
        return false;
    }

    ((SymSetOptionsFn)gpfnSymSetOptions)(((SymGetOptionsFn)gpfnSymGetOptions)() | 0x214);

    if (!gszSymSearchPath[0])
    {
        GetModuleFileNameA(0, szPath, sizeof(szPath));
        szPath[sizeof(szPath) - 1] = 0;
        char* pSlash = strrchr(szPath, 0x5C);
        if (pSlash)
        {
            *pSlash = 0;
        }
    }
    else
    {
        strncpy_s(szPath, sizeof(szPath), gszSymSearchPath, (unsigned int)-1);
    }

    if (ghProcess == (void*)-1)
    {
        ghProcess = GetCurrentProcess();
    }

    if (!((SymInitializeFn)gpfnSymInitialize)(ghProcess, szPath, GetProcessId(ghProcess) != 0))
    {
        return false;
    }

    gbSymInitialized = true;
    return true;
}

// 0x00401DD0
void __cdecl sub_00401DD0_CleanupSymbols()
{
    if (gbSymInitialized)
    {
// build: symbol ?ghProcess@* 0x0074C6F0
        ((SymCleanupFn)gpfnSymCleanup)(ghProcess);
        gbSymInitialized = false;
    }
}

#include "gen/data/Source/Fog/Unknown_00401010.inc"
