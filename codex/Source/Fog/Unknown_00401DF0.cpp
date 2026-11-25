#include "D2GameTypes.h"
#include "D2CrashTypes.h"
#include "D2FogTypes.h"
#include "D2SysTypes.h"

typedef int (__stdcall* SymGetModuleInfo64Fn)(void* hProcess, unsigned __int64 qwAddr, D2ImagehlpModule64Strc* pModuleInfo);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214

extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName);                // 0x006CC198

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);                               // 0x00681EF0

extern "C" int __cdecl strncpy_s(char* szDest, unsigned int nDestSize, const char* szSource, unsigned int nCount); // 0x006859D2

bool __cdecl sub_00401B00_LoadDbgHelp();                                                                    // 0x00401B00

bool __cdecl sub_00401CB0_InitSymbols();                                                                    // 0x00401CB0

extern void* ghProcess;                                                                            // 0x0074C6F0

extern void* ghDbgHelp;                                                                            // 0x0098A680

extern SymGetModuleInfo64Fn gpfnSymGetModuleInfo64;                                                // 0x0098A684

extern bool gbSymInitialized;                                                                      // 0x0098A6B0

extern D2CriticalSectionStrc gtSymbolLock;                                                         // 0x0098A6F0

static bool __stdcall sub_00401DF0_GetModuleFromAddr(unsigned long dwAddress, char* szModule, unsigned long* pdwBase);

extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void* pAddress, D2MemoryBasicInfoStrc* pBuffer, unsigned long nLength); // 0x006CC244

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C

extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext);             // 0x006CC290

extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C

extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread);                         // 0x006CC288

extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext); // 0x006CC234

extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);                          // 0x006CC28C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

typedef int (__stdcall* SymGetSymFromAddr64Fn)(void* hProcess, unsigned __int64 qwAddr, unsigned __int64* pqwDisplacement, D2ImagehlpSymbol64Strc* pSymbol);

typedef int (__stdcall* SymGetLineFromAddr64Fn)(void* hProcess, unsigned __int64 qwAddr, unsigned long* pdwDisplacement, D2ImagehlpLine64Strc* pLine);

extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990

extern SymGetModuleInfo64Fn gpfnSymGetModuleInfo64B_0098A684; // 0x0098A684

extern SymGetSymFromAddr64Fn gpfnSymGetSymFromAddr64;                                              // 0x0098A68C

extern SymGetLineFromAddr64Fn gpfnSymGetLineFromAddr64;                                            // 0x0098A6E8

extern D2CriticalSectionStrc gtSymbolLockB_0098A6F0; // 0x0098A6F0


static bool __stdcall sub_00401F10_GetSymbolFromAddr(char* szName, unsigned long dwAddress, unsigned long* pdwDisplacement);

static bool __stdcall sub_004020D0_GetLineFromAddr(unsigned long dwAddress, char* szFile, unsigned long* pLineNumber);

typedef int (__stdcall* EnumerateLoadedModules64Fn)(void* hProcess, void* pfnCallback, void* pContext);

extern EnumerateLoadedModules64Fn gpfnEnumerateLoadedModules64;                                    // 0x0098A6A4

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






typedef int (__stdcall* D2MiniDumpWriteDumpFn)(void* hProcess, unsigned long dwProcessId, void* hFile, int nDumpType, D2MiniDumpExceptionInfoStrc* pExceptionParam, D2MiniDumpUserStreamInfoStrc* pUserStreamParam, void* pCallbackParam);

typedef int (__stdcall* SymCleanupFn)(void* hProcess);

bool __stdcall sub_00405250_DescribeAddress(unsigned long dwAddress, D2SymbolInfoStrc* pInfo); // 0x00405250

extern "C" int __cdecl _snprintf_s(char* szBuffer, unsigned int nSizeOfBuffer, unsigned int nCount, const char* szFormat, ...); // 0x006824CB

extern "C" unsigned int __cdecl strlen(const char* szString);

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern unsigned long gdwMainThreadId_00992B1C;                                                              // 0x00992B1C

extern "C" const char gszNewline[];                                                                // 0x006FFCB0

void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output); // 0x00402D60

// 0x00401A60
void __cdecl sub_00401A60_UnlockSymbols()
{
    LeaveCriticalSection(&gtSymbolLock);
}

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x00401DF0
static bool __stdcall sub_00401DF0_GetModuleFromAddr(unsigned long dwAddress, char* szModule, unsigned long* pdwBase)
{
    szModule[0] = 0;
    *pdwBase = 0;
    D2SymbolLockGuardStrc tLock;

    if ((ghDbgHelp || sub_00401B00_LoadDbgHelp()) && (gbSymInitialized || sub_00401CB0_InitSymbols()))
    {
        SymGetModuleInfo64Fn pfnGetModuleInfo = gpfnSymGetModuleInfo64;
        if (pfnGetModuleInfo)
        {
            D2ImagehlpModule64Strc tInfo;
            memset(&tInfo, 0, sizeof(tInfo));
            tInfo.SizeOfStruct = sizeof(D2ImagehlpModule64Strc);
            if (pfnGetModuleInfo(ghProcess, dwAddress, &tInfo))
            {
                if (GetModuleHandleA(tInfo.LoadedImageName))
                    *pdwBase = (unsigned long)tInfo.BaseOfImage;
                strncpy_s(szModule, 0x100, tInfo.ImageName, (unsigned int)-1);
                return true;
            }
        }
    }
    return false;
}


// 0x00401480
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

// 0x00401540
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

// 0x00401F10
static bool __stdcall sub_00401F10_GetSymbolFromAddr(char* szName, unsigned long dwAddress, unsigned long* pdwDisplacement)
{
    szName[0] = 0;
    *pdwDisplacement = 0;
    D2SymbolLockGuardStrc tLock(&gtSymbolLockB_0098A6F0);

    if ((ghDbgHelp || sub_00401B00_LoadDbgHelp()) && (gbSymInitialized || sub_00401CB0_InitSymbols()))
    {
        if (gpfnSymGetSymFromAddr64)
        {
            D2SymbolBufferStrc tBuffer;
            memset(&tBuffer, 0, sizeof(tBuffer));
            tBuffer.tSymbol.SizeOfStruct = sizeof(D2ImagehlpSymbol64Strc);
            tBuffer.tSymbol.Address = dwAddress;
            tBuffer.tSymbol.MaxNameLength = 0x400;
            unsigned __int64 qwDisplacement = 0;

            if (gpfnSymGetSymFromAddr64(ghProcess, dwAddress, &qwDisplacement, &tBuffer.tSymbol))
            {
                if (gpfnSymGetModuleInfo64)
                {
                    D2ImagehlpModule64Strc tModule;
                    memset(&tModule, 0, sizeof(tModule));
                    tModule.SizeOfStruct = sizeof(D2ImagehlpModule64Strc);
                    if (gpfnSymGetModuleInfo64B_0098A684(ghProcess, dwAddress, &tModule)
                        && tModule.SymType != 0 && tModule.SymType != 4 && tModule.SymType != 5)
                    {
                        strncpy_s(szName, 0x200, tBuffer.tSymbol.Name, (unsigned int)-1);
                        *pdwDisplacement = (unsigned long)qwDisplacement;
                        return true;
                    }
                }
            }
        }
    }
    return false;
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

// 0x00405250
static bool __stdcall sub_00405250_DescribeAddress(unsigned long dwAddress, D2SymbolInfoStrc* pInfo)
{
    char szName[0x100];
    unsigned long dwBase;

    pInfo->nOffset = 0;
    pInfo->szSource[0] = 0;
    pInfo->nLine = 0;
    pInfo->szName[0] = 0;
    pInfo->szModule[0] = 0;
    dwBase = 0;
    if (sub_00401DF0_GetModuleFromAddr(dwAddress, szName, &dwBase))
        strncpy_s(pInfo->szModule, 0x40, CRASH_GetFileName(szName), (unsigned int)-1);
    else
        pInfo->szModule[0] = 0;

    sub_00401F10_GetSymbolFromAddr(pInfo->szName, dwAddress, &pInfo->nOffset);
    sub_004020D0_GetLineFromAddr(dwAddress, szName, &pInfo->nLine);
    strncpy_s(pInfo->szSource, 0x100, CRASH_GetFileName(szName), (unsigned int)-1);
    return true;
}

// 0x00402D60
static void __fastcall sub_00402D60_FormatStackFrame(const D2StackFrameStrc* frame,const D2SymbolInfoStrc* symbol,char* output)
{
 char args[80];
 output[0]=0;
 args[0]=0;
 if(frame->bHasArgs)
  _snprintf_s(args,80,(unsigned int)-1," (%p,%p,%p,%p)",frame->apArgs[0],frame->apArgs[1],frame->apArgs[2],frame->apArgs[3]);
 if(!symbol->szName[0]) {
  _snprintf_s(output,1024,(unsigned int)-1,"DBG-ADDR<%p>(\"%s\")%s",frame->dwPc,symbol->szModule,args);
  return;
 }
 int length=_snprintf_s(output,1024,(unsigned int)-1,"%p %s",frame->dwPc,symbol->szModule);
 int padding=21-length;
 if(padding>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,"%*s",padding," ");
 if(symbol->szName[0] || symbol->nOffset>0)
  length+=_snprintf_s(output+length,1024-length,(unsigned int)-1," %s+%llu",symbol->szName,(unsigned __int64)symbol->nOffset);
 length+=_snprintf_s(output+length,1024-length,(unsigned int)-1,"%s",args);
 if(symbol->szSource[0] || symbol->nLine>0)
  _snprintf_s(output+length,1024-length,(unsigned int)-1," (%s,%u)",symbol->szSource,symbol->nLine);
}

// 0x00403100
void __fastcall sub_00403100_PrintFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, unsigned int nFrames, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader)
{
    char szName[0x80];
    char szLine[0x400];
    if (bHeader)
    {
        if (gdwMainThreadId_00992B1C == dwThreadId)
        {
            strncpy_s(szName, 0x80, "Main Thread", (unsigned int)-1);
        }
        else
        {
            szName[0] = 0;
        }

        unsigned long dwStackSize;
        unsigned long dwStackTop;
        unsigned long dwStackPointer;
        unsigned char bStack = ERRORMANAGER_GetThreadStack(&dwStackSize, dwThreadId, &dwStackTop, &dwStackPointer);
        int nLength = _snprintf_s(szLine, 0x400, (unsigned int)-1, "Thread 0x%08x", dwThreadId);
        if (szName[0])
        {
            nLength += _snprintf_s(szLine + nLength, 0x400 - nLength, (unsigned int)-1, " \"%s\"", szName);
        }
        if (bStack)
        {
            nLength += _snprintf_s(szLine + nLength, 0x400 - nLength, (unsigned int)-1, " [Stack Base: 0x%p Used Space: %llu/%llu bytes]", dwStackTop, (unsigned __int64)(dwStackTop - dwStackPointer), (unsigned __int64)dwStackSize);
        }
        _snprintf_s(szLine + nLength, 0x400 - nLength, (unsigned int)-1, gszNewline);
        pfnPrint(pContext, szLine);
    }

    for (unsigned int i = 0; i < nFrames; ++i)
    {
        D2SymbolInfoStrc tSymbol;
        sub_00405250_DescribeAddress(pFrames[i].dwPc, &tSymbol);
        if (!bSymbols)
        {
            tSymbol.szName[0] = 0;
        }
        sub_00402D60_FormatStackFrame(&pFrames[i], &tSymbol, szLine);
        const unsigned int nLineLength = strlen(szLine);
        if (nLineLength >= 0x3FF)
        {
            szLine[0x3FE] = '\n';
            szLine[0x3FF] = 0;
        }
        else
        {
            szLine[nLineLength] = '\n';
            szLine[nLineLength + 1] = 0;
        }
        pfnPrint(pContext, szLine);
    }
}

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004020D0
static bool __stdcall sub_004020D0_GetLineFromAddr(unsigned long dwAddress, char* szFile, unsigned long* pLineNumber)
{
    unsigned long dwDisplacement;
    szFile[0] = 0;
    *pLineNumber = 0;
    D2SymbolLockGuardStrc tLock;

    if (sub_EnsureSymbolEngine())
    {
        SymGetLineFromAddr64Fn pfnGetLine = gpfnSymGetLineFromAddr64;
        if (pfnGetLine)
        {
            D2ImagehlpLine64Strc tLine;
            memset(&tLine, 0, sizeof(tLine));
            tLine.SizeOfStruct = sizeof(D2ImagehlpLine64Strc);
            if (pfnGetLine(ghProcess, dwAddress, &dwDisplacement, &tLine))
            {
                strncpy_s(szFile, 0x100, tLine.FileName, (unsigned int)-1);
                *pLineNumber = tLine.LineNumber;
                return true;
            }
        }
    }
    return false;
}


// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// 0x004021D0
bool __stdcall sub_004021D0_EnumerateModules(void* pfnCallback, void* pContext)
{
    D2SymbolLockGuardStrc tGuard;
    if (!ghDbgHelp && !sub_00401B00_LoadDbgHelp())
        return false;
    if (!gpfnEnumerateLoadedModules64)
        return false;
    return gpfnEnumerateLoadedModules64(ghProcess, pfnCallback, pContext) != 0;
}

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

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc

// build: ltcg-noroot D2SymbolLockGuardStrc::D2SymbolLockGuardStrc
// build: ltcg-noroot D2SymbolLockGuardStrc::~D2SymbolLockGuardStrc
