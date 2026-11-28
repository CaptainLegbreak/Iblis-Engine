#include "D2GameTypes.h"
#include "D2CrashTypes.h"
#include "D2FogTypes.h"
#include "D2SysTypes.h"

typedef int (__stdcall* SymGetModuleInfo64Fn)(void* hProcess, unsigned __int64 qwAddr, D2ImagehlpModule64Strc* pModuleInfo);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00

bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

extern void* ghProcess;                                                                            // 0x0074C6F0

extern void* ghDbgHelp;                                                                            // 0x0098A680

extern bool gbSymInitialized;                                                                      // 0x0098A6B0

extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0

extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void* pAddress, D2MemoryBasicInfoStrc* pBuffer, unsigned long nLength); // 0x006CC244

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C

extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext);             // 0x006CC290

extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C

extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread);                         // 0x006CC288

extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext); // 0x006CC234

extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);                          // 0x006CC28C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent(); // 0x006CC284
extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwCode, unsigned long dwFlags, unsigned long nArgs, const unsigned long* pArgs); // 0x006CC224

typedef int (__stdcall* SymGetSymFromAddr64Fn)(void* hProcess, unsigned __int64 qwAddr, unsigned __int64* pqwDisplacement, D2ImagehlpSymbol64Strc* pSymbol);

typedef int (__stdcall* SymGetLineFromAddr64Fn)(void* hProcess, unsigned __int64 qwAddr, unsigned long* pdwDisplacement, D2ImagehlpLine64Strc* pLine);

extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990


typedef int (__stdcall* EnumerateLoadedModules64Fn)(void* hProcess, void* pfnCallback, void* pContext);

typedef int (__stdcall* SymSetSearchPathFn)(void* hProcess, const char* szSearchPath);

typedef int (__stdcall* FindFileInPathCallbackFn)(int nUnused1, int nUnused2);

typedef int (__stdcall* SymFindFileInPathFn)(void* hProcess, const char* szSearchPath, const char* szFileName,
    void* pId, unsigned int nTwo, unsigned int nThree, unsigned int nFlags, char* szFoundFile,
    FindFileInPathCallbackFn pfnCallback, void* pContext);

typedef unsigned __int64 (__stdcall* SymLoadModule64Fn)(void* hProcess, void* hFile, const char* szImageName,
    const char* szModuleName, unsigned __int64 qwBaseOfDll, unsigned long dwSizeOfDll);

typedef int (__stdcall* SymUnloadModule64Fn)(void* hProcess, unsigned __int64 qwBaseOfDll);

typedef int (__stdcall* StackWalk64Fn)(unsigned long dwMachineType, void* hProcess, void* hThread, void* pStackFrame,
    void* pContextRecord, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase,
    void* pfnTranslateAddress);

extern void* gpfnSymFunctionTableAccess64;                                                         // 0x0098A698

extern void* gpfnSymGetModuleBase64;                                                               // 0x0098A69C

extern StackWalk64Fn gpfnStackWalk64;                                                              // 0x0098A6A0






typedef int (__stdcall* D2MiniDumpWriteDumpFn)(void* hProcess, unsigned long dwProcessId, void* hFile, int nDumpType, D2MiniDumpExceptionInfoStrc* pExceptionParam, D2MiniDumpUserStreamInfoStrc* pUserStreamParam, void* pCallbackParam);

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId(); // 0x006CC1EC

extern D2MiniDumpWriteDumpFn gpfnMiniDumpWriteDump; // 0x0098A6E0

extern D2MiniDumpRequestStrc* gpMiniDumpRequest; // 0x0098A6E4
extern void* ghDbgHelpWorkEvent; // 0x0098A6C0
extern void* ghDbgHelpDoneEvent; // 0x0098A6BC

typedef int (__stdcall* SymCleanupFn)(void* hProcess);

extern SymCleanupFn gpfnSymCleanup;                                                                // 0x0098A6B8

extern "C" int __cdecl _snprintf_s(char* szBuffer, unsigned int nSizeOfBuffer, unsigned int nCount, const char* szFormat, ...); // 0x006824CB

extern "C" unsigned int __cdecl strlen(const char* szString);

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern const char gszArgsFormat[]; // 0x006FFC14

extern const char gszUnresolvedFormat[]; // 0x006FFC24

extern const char gszAddressFormat[]; // 0x006FFC3C

extern const char gszEmpty[]; // 0x006FFC44

extern const char gszPaddingFormat[]; // 0x006FFC48

extern const char gszSymbolFormat[]; // 0x006FFC4C

extern const char gszStringFormat[]; // 0x006FFC58

extern const char gszSourceFormat[]; // 0x006FFC5C

void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output); // 0x00402D60

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// 0x00401A70
static void ERRORMANAGER_SetMiniDumpThreadName(unsigned long dwThreadID, const char* szThreadName)
{
    if (IsDebuggerPresent() == 1)
    {
        D2ThreadNameInfoStrc tInfo;
        tInfo.dwType = 0x1000;
        tInfo.szName = szThreadName;
        tInfo.dwThreadID = dwThreadID;
        tInfo.dwFlags = 0;
        __try
        {
            RaiseException(0x406D1388, 0, sizeof(tInfo) / sizeof(unsigned long), (unsigned long*)&tInfo);
        }
        __except (-1)
        {
        }
    }
}

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc


static unsigned char __stdcall ERRORMANAGER_GetStackRange(void** ppBase, unsigned long* pEnd, const void* pAddress)
{
    D2MemoryBasicInfoStrc tInfo;
    if (!VirtualQuery(pAddress, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.State != 0x1000)
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.Protect != 4)
        return 0;
    *pEnd = (unsigned long)tInfo.BaseAddress + tInfo.RegionSize;
    if (*pEnd <= (unsigned long)pAddress)
        return 0;
    *ppBase = tInfo.AllocationBase;
    if (!VirtualQuery(tInfo.AllocationBase, &tInfo, sizeof(tInfo)))
        return 0;
    if (tInfo.Type != 0x20000)
        return 0;
    if (tInfo.BaseAddress != *ppBase)
        return 0;
    unsigned long dwEnd = (unsigned long)*ppBase + tInfo.RegionSize;
    if (tInfo.State == 0x1000)
    {
        if (dwEnd != *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    if (tInfo.State == 0x2000)
    {
        if (dwEnd >= *pEnd)
            return 0;
        *ppBase = tInfo.AllocationBase;
        return 1;
    }
    return 0;
}

static unsigned char __stdcall ERRORMANAGER_GetThreadStack(unsigned long* pStackSize, unsigned long dwThreadId, unsigned long* pStackTop, unsigned long* pStackPointer)
{
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    tContext.ContextFlags = 0x10001;
    if (GetCurrentThreadId() == dwThreadId)
    {
        RtlCaptureContext(&tContext);
    }
    else
    {
        hThread = OpenThread(0x4A, 0, dwThreadId);
        if (!hThread)
            return 0;
        if (SuspendThread(hThread) == -1)
            return 0;
        if (!GetThreadContext(hThread, &tContext))
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
            return 0;
        }
    }
    *pStackPointer = tContext.Esp;
    void* pBase;
    unsigned long dwEnd;
    unsigned char bResult = ERRORMANAGER_GetStackRange(&pBase, &dwEnd, (const void*)tContext.Esp);
    if (bResult)
    {
        *pStackTop = dwEnd;
        *pStackSize = dwEnd - (unsigned long)pBase;
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return bResult;
}

static inline bool sub_EnsureSymbolEngine()
{
    if (!ghDbgHelp && !sub_00401B00_LoadDbgHelp())
        return false;
    if (!gbSymInitialized && !sub_00401CB0_InitSymbols())
        return false;
    return true;
}

static inline const char* CRASH_GetFileName(const char* szPath)
{
    const char* pLast = 0;
    const char* pFound = strrchr(szPath, '/');
    if (pFound && pFound > pLast)
        pLast = pFound;
    pFound = strrchr(szPath, '\\');
    if (pFound && pFound > pLast)
        pLast = pFound;
    pFound = strrchr(szPath, ':');
    if (pFound && pFound > pLast)
        pLast = pFound;
    return pLast ? pLast + 1 : szPath;
}


static void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output)
{
 char args[80];
 output[0]=0;
 args[0]=0;
 if(frame->bHasArgs)
  _snprintf_s(args,80,(unsigned int)-1,gszArgsFormat,frame->apArgs[0],frame->apArgs[1],frame->apArgs[2],frame->apArgs[3]);
 if(!symbol->szName[0]) {
  _snprintf_s(output,1024,(unsigned int)-1,gszUnresolvedFormat,frame->dwPc,symbol->szModule,args);
  return;
 }
 int length=_snprintf_s(output,1024,(unsigned int)-1,gszAddressFormat,frame->dwPc,symbol->szModule);
 int padding=21-length;
 if(padding>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,gszPaddingFormat,padding,gszEmpty);
 if(symbol->szName[0] || symbol->nOffset>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,gszSymbolFormat,symbol->szName,(unsigned __int64)symbol->nOffset);
 length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,gszStringFormat,args);
 if(symbol->szSource[0] || symbol->nLine>0)
  _snprintf_s(output+length,1024-length,(unsigned int)-1,gszSourceFormat,symbol->szSource,symbol->nLine);
}


// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc


// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

unsigned __int64 __stdcall sub_00402460_LoadModule(void* hFile, const char* szImageName,
    const char* szModuleName, unsigned __int64 qwBaseOfDll, unsigned long dwSizeOfDll); // 0x00402460


// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004025F0
bool __stdcall sub_004025F0_StackWalk(void* hThread, void* pStackFrame, void* pContextRecord)
{
    D2SymbolLockGuardStrc tGuard;
    if ((ghDbgHelp || sub_00401B00_LoadDbgHelp())
        && (gbSymInitialized || sub_00401CB0_InitSymbols())
        && gpfnStackWalk64 && gpfnSymFunctionTableAccess64 && gpfnSymGetModuleBase64)
        return gpfnStackWalk64(0x14C, ghProcess, hThread, pStackFrame, pContextRecord, 0,
            gpfnSymFunctionTableAccess64, gpfnSymGetModuleBase64, 0) != 0;
    return false;
}

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004026D0
void __cdecl sub_004026D0_WriteMiniDump()
{
    D2MiniDumpRequestStrc* pRequest = gpMiniDumpRequest;
    D2MiniDumpRequestInfoStrc* pInfo = &gpMiniDumpRequest->tInfo;
    D2MiniDumpExceptionInfoStrc tExceptionInfo;
    tExceptionInfo.dwThreadId = gpMiniDumpRequest->tInfo.dwThreadId;
    tExceptionInfo.pExceptionPointers = gpMiniDumpRequest->tInfo.pExceptionPointers;

    D2MiniDumpUserStreamStrc tStream;
    D2MiniDumpUserStreamInfoStrc tStreamInfo;
    unsigned long dwCount = 0;
    tExceptionInfo.bClientPointers = 0;
    const char* szComment = gpMiniDumpRequest->tInfo.szComment;
    if (szComment)
    {
        tStream.dwType = 0x1000;
        tStream.dwBufferSize = strlen(szComment) + 1;
        tStream.pBuffer = (void*)szComment;
        dwCount = 1;
    }
    tStreamInfo.dwUserStreamCount = dwCount;
    tStreamInfo.pUserStreamArray = &tStream;

    D2SymbolLockGuardStrc tLock;
    if (!gpfnMiniDumpWriteDump)
    {
        pRequest->bResult = false;
    }
    else
    {
        pRequest->bResult = gpfnMiniDumpWriteDump(ghProcess, GetCurrentProcessId(), pRequest->hFile, 0x40,
            pInfo->pExceptionPointers ? &tExceptionInfo : 0, &tStreamInfo, 0) != 0;
    }
}

// 0x004027C0
unsigned long __stdcall LOGMANAGER_DbgHelpThreadProc(void* pParam)
{
    // the original's own: it stores 0 to this stack local and reads it back unused, which only a volatile read keeps
    volatile int nDummy = 0;
    nDummy;
    ERRORMANAGER_SetMiniDumpThreadName((unsigned long)-1, "MiniDump Thread");
    WaitForSingleObject(ghDbgHelpWorkEvent, 0xFFFFFFFF);
    while (gpMiniDumpRequest)
    {
        sub_004026D0_WriteMiniDump();
        SetEvent(ghDbgHelpDoneEvent);
        WaitForSingleObject(ghDbgHelpWorkEvent, 0xFFFFFFFF);
    }
    return 0;
}

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00402AE0
void __cdecl sub_00402AE0_ShutdownSymbols()
{
    D2SymbolLockGuardStrc tGuard;
    if (gbSymInitialized)
    {
        gpfnSymCleanup(ghProcess);
        gbSymInitialized = false;
    }
}
