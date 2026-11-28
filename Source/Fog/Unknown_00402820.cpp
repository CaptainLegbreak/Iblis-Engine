#include "Fog.h"

#include "D2GameTypes.h"
#include "D2FogTypes.h"
#include "D2ExceptionPointers.h"

struct D2CriticalSectionStrc;
struct D2MiniDumpRequestStrc;
struct D2CrashGuidStrc;
struct D2CrashModuleStrc;
struct D2CrashModuleListStrc;
struct D2CrashRecord24Strc;
union D2WordArgStrc;
struct D2ExceptionRecordStrc;
struct D2ExceptionPointersStrc;
struct D2CrashHandlerInfoStrc;
struct D2CrashSubmitInfoStrc;
struct D2ImageDosHeaderStrc;
struct D2ImageOptionalHeaderStrc;
struct D2ImageOptionalHeader64Strc;
struct D2ImageNtHeadersStrc;
struct D2ImageDebugDirStrc;
struct D2CvNb10Strc;
struct D2CvRsdsStrc;
struct D2ModuleStrc;


extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent(); // 0x006CC284
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall CreateFileW(const wchar_t* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC298
extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent); // 0x006CC130
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
bool __cdecl sub_00401B00_LoadDbgHelp(); // 0x00401B00
extern bool gbMiniDumpEnabled; // 0x0098A6B1
extern D2CriticalSectionStrc gtDbgHelpRequestLock; // 0x0098A6C4
extern void* ghDbgHelpWorkEvent; // 0x0098A6C0
extern void* ghDbgHelpDoneEvent; // 0x0098A6BC
extern D2MiniDumpRequestStrc* gpMiniDumpRequest; // 0x0098A6E4

struct D2CrashGuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned long Data4[2];
};

struct D2CrashModuleStrc
{
    void* pBase;
    unsigned long nSize;
    char szName[0x100];
    char szPath[0x100];
    unsigned long nTimeStamp;
    D2CrashGuidStrc tGuid;
    unsigned long nAge;
    unsigned long nTimeDateStamp;
    unsigned long nVersion;
    D2CrashModuleStrc();
};

struct D2CrashModuleListStrc
{
    unsigned int nCount;
    D2CrashModuleStrc aModules[0x100];
};

struct D2CrashRecord24Strc
{
    int n00;
    int n04;
    int n08;
    int n0C;
    char b10;
    int n14;
    int n18;
    int n1C;
    int n20;

    D2CrashRecord24Strc();
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) void* __stdcall CreateEventW(void* pAttributes, int bManualReset, int bInitialState, const wchar_t* szName); // 0x006CC2A4
extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pThreadId); // 0x006CC250
unsigned long __stdcall LOGMANAGER_DbgHelpThreadProc(void* pParam); // 0x004027C0
void __stdcall sub_M127_EmitSink(D2CrashGuidStrc* pGuid);
extern D2CriticalSectionStrc gtSymbolLock; // 0x0098A6F0

extern int gbRightClickConsumed; // 0x007A0670
extern int gbPopupDismissed; // 0x007A5254
extern int gdwGlobal_007BC974; // 0x007BC974
extern int gpHoverItem; // 0x007BCBF4

extern "C" int __stdcall GetModuleInformation(void* hProcess, void* hModule, D2PsapiModuleInfoStrc* pInfo, unsigned long cb); // 0x006B13C8
void __stdcall sub_M452_EmitSink(D2CrashModuleListStrc* pList);

#pragma pack(push, 1)
#pragma pack(pop)
union D2WordArgStrc
{
    unsigned int dwValue;
    unsigned short wValue;
};
extern "C" const char gszNewline[]; // 0x006FFCB0
extern "C" const char gszNewLine2[]; // 0x006FFCD8

struct D2ExceptionRecordStrc
{
    unsigned long ExceptionCode;
};

struct D2CrashHandlerInfoStrc
{
    const char* szName;
    char* szText;
    int nUnk08;
    int nUnk0C;
    int nUnk10;
    unsigned long dwThreadId;
    D2ExceptionPointersStrc* pPointers;
    char szBuffer[0x200];
};

typedef int (__fastcall* D2CrashHandlerFn)(D2CrashHandlerInfoStrc* pReport, void* pContext);

extern "C" int __cdecl strncpy_s(char* szDest, size_t nDestSize, const char* szSource, size_t nCount); // 0x006859D2
extern "C" __declspec(dllimport) unsigned long __stdcall FormatMessageA(unsigned long dwFlags, const void* pSource, unsigned long dwMessageId, unsigned long dwLanguageId, char* pBuffer, unsigned long nSize, void* pArguments); // 0x006CC2B0
extern void* gpCrashContext; // 0x00992B14

struct D2CrashSubmitInfoStrc
{
    const char* szName;
    const char* szLocale;
    const char* szFrom;
    unsigned int dwFlags;
    const char* apszLines[16];
    unsigned int nLines;
};

extern "C" size_t __cdecl strlen(const char* szString);
extern char gszTextBuffer[0x400]; // 0x0098A280
bool __stdcall sub_00404330_FileExistsUtf8(const char* szPath); // 0x00404330
bool __fastcall ERRORMANAGER_CreateProcessUtf8(const char* szApplicationName, const char* szCommandLine); // 0x00404210
static size_t __stdcall sub_00404150_StrlCat(const char* szSource, char* szDest, size_t nSize);

struct D2CvRsdsStrc
{
    unsigned long dwCvSignature;
    D2CrashGuidStrc tGuid;
    unsigned long dwAge;
    char szPdbName[4];
};
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);
BOOLEAN __stdcall AUTOMAP_IsDebugDirectorySizeValid(unsigned int nValue);
static bool __stdcall sub_004049A0_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage);
static bool sub_00404F80_ReadNb10(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv);
static bool sub_00404FF0_ReadRsds(const D2CvRsdsStrc* pCv, D2CrashModuleStrc* pModule);

D2CriticalSectionStrc gtSymbolLock; // 0x0098A6F0

// 0x004013A0
int __cdecl sub_004013A0_IsDebuggerAttached()
{
    return !(IsDebuggerPresent() - 1);
}

// 0x00402820
bool __fastcall sub_00402820_WriteMiniDump(const char* szPath, const char* szComment, void* pExceptionPointers, unsigned long dwThreadId)
{
    wchar_t wszPath[0x104];
    if (!gbMiniDumpEnabled)
    {
        return false;
    }
    EnterCriticalSection(&gtSymbolLock);
// build: symbol ?ghDbgHelp@* 0x0098A680
    if (!ghDbgHelp && !sub_00401B00_LoadDbgHelp())
    {
        LeaveCriticalSection(&gtSymbolLock);
        return false;
    }
    LeaveCriticalSection(&gtSymbolLock);
    if (MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104) <= 0)
    {
        return false;
    }
    void* hFile = CreateFileW(wszPath, 0x40000000, 3, 0, 2, 0x80, 0);
    if (hFile == (void*)-1)
    {
        return false;
    }
    EnterCriticalSection(&gtDbgHelpRequestLock);
    D2MiniDumpRequestStrc tRequest;
    tRequest.hFile = hFile;
    tRequest.tInfo.dwThreadId = dwThreadId ? dwThreadId : GetCurrentThreadId();
    tRequest.tInfo.szComment = szComment;
    tRequest.tInfo.pExceptionPointers = pExceptionPointers;
    tRequest.bResult = false;
    gpMiniDumpRequest = &tRequest;
    SetEvent(ghDbgHelpWorkEvent);
    WaitForSingleObject(ghDbgHelpDoneEvent, (unsigned long)-1);
    gpMiniDumpRequest = 0;
    LeaveCriticalSection(&gtDbgHelpRequestLock);
    CloseHandle(hFile);
    return tRequest.bResult;
}

bool gbMiniDumpEnabled; // 0x0098A6B1

void* gpfnSymCleanup; // 0x0098A6B8

void* ghDbgHelpDoneEvent; // 0x0098A6BC

void* ghDbgHelpWorkEvent; // 0x0098A6C0

D2CriticalSectionStrc gtDbgHelpRequestLock; // 0x0098A6C4

void* ghDbgHelpThread; // 0x00992B08

unsigned long gdwDbgHelpThreadId; // 0x00992B0C

// 0x00402980
void __cdecl sub_00402980_StartDbgHelpWorker()
{
    InitializeCriticalSection(&gtSymbolLock);
    InitializeCriticalSection(&gtDbgHelpRequestLock);
    ghDbgHelpWorkEvent = CreateEventW(0, 0, 0, 0);
    ghDbgHelpDoneEvent = CreateEventW(0, 0, 0, 0);
    ghDbgHelpThread = CreateThread(0, 0x40000, LOGMANAGER_DbgHelpThreadProc, 0, 0x10000, &gdwDbgHelpThreadId);
    gbMiniDumpEnabled = IsDebuggerPresent() != 1;
}

// 0x004029F0
void __cdecl sub_004029F0_StopDbgHelpWorker()
{
    SetEvent(ghDbgHelpWorkEvent);
    WaitForSingleObject(ghDbgHelpThread, 0xFFFFFFFF);
    CloseHandle(ghDbgHelpThread);
    ghDbgHelpThread = 0;
    gdwDbgHelpThreadId = 0;
    CloseHandle(ghDbgHelpDoneEvent);
    CloseHandle(ghDbgHelpWorkEvent);
    DeleteCriticalSection(&gtDbgHelpRequestLock);
    DeleteCriticalSection(&gtSymbolLock);
// build: symbol ?gbSymInitialized@* 0x0098A6B0
    if (gbSymInitialized)
    {
// build: symbol ?ghProcess@* 0x0074C6F0
        ((SymCleanupFn)gpfnSymCleanup)(ghProcess);
        gbSymInitialized = false;
    }
}

// 0x00402B50
static inline void sub_00402B50_SetProcessHandle(void* hProcess)
{
    ghProcess = hProcess;
}

// 0x00402B60
D2CrashRecord24Strc::D2CrashRecord24Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
    n0C = 0;
    b10 = 0;
    n14 = 0;
    n18 = 0;
    n1C = 0;
    n20 = 0;
}

// 0x00402B80
static inline void sub_00402B80_ClearGuid(D2CrashGuidStrc* pGuid)
{
    pGuid->Data1 = 0;
    pGuid->Data2 = 0;
    pGuid->Data3 = 0;
    pGuid->Data4[0] = 0;
    pGuid->Data4[1] = 0;
}

// 0x00402BA0
static inline void sub_00402BA0_ClearGuidB(D2CrashGuidStrc* pGuid)
{
    pGuid->Data1 = 0;
    pGuid->Data2 = 0;
    pGuid->Data3 = 0;
    pGuid->Data4[0] = 0;
    pGuid->Data4[1] = 0;
}

// 0x00402BC0
D2CrashModuleStrc::D2CrashModuleStrc()
{
    pBase = 0;
    nSize = 0;
    nTimeStamp = 0;
    tGuid.Data1 = 0;
    tGuid.Data2 = 0;
    tGuid.Data3 = 0;
    tGuid.Data4[0] = 0;
    tGuid.Data4[1] = 0;
    nAge = 0;
    nTimeDateStamp = 0;
    nVersion = 0;
    szName[0] = 0;
    szPath[0] = 0;
}

// 0x00402C30
bool __fastcall sub_00402C30_AddModule(const D2CrashModuleStrc* pModule, D2CrashModuleListStrc* pList)
{
    if (!pList)
    {
        return false;
    }
    pList->aModules[pList->nCount] = *pModule;
    ++pList->nCount;
    return pList->nCount < 0x100;
}

void __fastcall sub_M127_Emit_00402B50(void* hProcess, D2CrashGuidStrc* pGuid)
{
    sub_00402B50_SetProcessHandle(hProcess);
    sub_00402B80_ClearGuid(pGuid);
    sub_M127_EmitSink(pGuid);
    sub_00402BA0_ClearGuidB(pGuid + 1);
    sub_M127_EmitSink(pGuid + 1);
}

// 0x00402A80
int __cdecl sub_00402A80_IsDbgHelpLoaded()
{
    return ghDbgHelp != 0;
}

// 0x0044BFF0
int __cdecl INV_IsRightClickConsumed()
{
    return gbRightClickConsumed != 0;
}

// 0x0045FDD0
int __cdecl INV_IsPopupDismissed()
{
    return gbPopupDismissed != 0;
}

// 0x0047EC40
int __cdecl sub_0047EC40_IsSet()
{
    return gdwGlobal_007BC974 != 0;
}

// 0x0048A690
int __cdecl INV_HasHoverItem()
{
    return gpHoverItem != 0;
}

// 0x00402A90
bool __stdcall sub_00402A90_GetDbgHelpModuleRange(void** ppBase, unsigned long* pSize)
{
    D2PsapiModuleInfoStrc tInfo;
    if (!ghDbgHelp)
        return false;
    if (!GetModuleInformation(GetCurrentProcess(), ghDbgHelp, &tInfo, sizeof(tInfo)))
        return false;
    *ppBase = tInfo.lpBaseOfDll;
    // the size's out pointer is read through the address of the parameter before it (as the image reads it,
    // after the first store; written as *pSize the compiler loads both out pointers first)
    **(unsigned long**)(&ppBase + 1) = tInfo.SizeOfImage;
    return true;
}

// 0x00402FE0
static D2CrashModuleListStrc* sub_00402FE0_InitModuleList(D2CrashModuleListStrc* pList)
{
    D2CrashModuleStrc* pModule = pList->aModules;
    int nLeft = 0x100 - 1;
    do
    {
        pModule->pBase = 0; pModule->nSize = 0; pModule->nTimeStamp = 0;
        D2CrashGuidStrc* const pGuid = &pModule->tGuid;
        pGuid->Data1 = 0; pGuid->Data2 = 0; pGuid->Data3 = 0; pGuid->Data4[0] = 0; pGuid->Data4[1] = 0;
        pModule->nAge = 0; pModule->nTimeDateStamp = 0; pModule->nVersion = 0; pModule->szName[0] = 0; pModule->szPath[0] = 0;
        ++pModule;
    }
    while (--nLeft >= 0);
    return pList;
}

void __fastcall sub_M452_Emit_00402FE0(int nArg, int nArg2)
{
    D2CrashModuleListStrc tList;
    sub_M452_EmitSink(sub_00402FE0_InitModuleList(&tList));
    tList.nCount = nArg2 - nArg;
    sub_M452_EmitSink(&tList);
}

// 0x00404660
static unsigned char sub_00404660_GetThreadContext(unsigned long dwThreadId, D2ThreadContextStrc* pContext)
{
    pContext->ContextFlags = 0x1003F;
    if (GetCurrentThreadId() == dwThreadId)
    {
        RtlCaptureContext(pContext);
        return 1;
    }
    void* hThread = OpenThread(0x4A, 0, dwThreadId);
    if (!hThread)
        return 0;
    if (SuspendThread(hThread) == -1)
    {
        CloseHandle(hThread);
        return 0;
    }
    int bResult = GetThreadContext(hThread, pContext);
    ResumeThread(hThread);
    CloseHandle(hThread);
    return bResult != 0;
}

// 0x004032F0
void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext)
{
    D2ThreadContextStrc tContext;
    char szText[0x400];
    if (!sub_00404660_GetThreadContext(dwThreadId, &tContext))
        return;
    if (tContext.ContextFlags & 0x10002)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "EAX", tContext.Eax);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EBX", tContext.Ebx);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ECX", tContext.Ecx);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EDX", tContext.Edx);
        n += _snprintf_s(szText + n, 0x400 - n, -1, gszNewline);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ESI", tContext.Esi);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EDI", tContext.Edi);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine2);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10001)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "EBP", tContext.Ebp);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ESP", tContext.Esp);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "EIP", tContext.Eip);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "FLG", tContext.EFlags);
        n += _snprintf_s(szText + n, 0x400 - n, -1, gszNewline);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "CS", tContext.SegCs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "SS", tContext.SegSs);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine2);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10004)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "DS", tContext.SegDs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "ES", tContext.SegEs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "FS", tContext.SegFs);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "GS", tContext.SegGs);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewLine2);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10008)
    {
        int n = _snprintf_s(szText, 0x400, -1, "%6s:0x%08x", "CTRL", tContext.FloatSave.ControlWord);
        n += _snprintf_s(szText + n, 0x400 - n, -1, "%6s:0x%08x", "STAT", tContext.FloatSave.StatusWord);
        _snprintf_s(szText + n, 0x400 - n, -1, gszNewline);
        pfnPrint(pContext, szText);
        for (unsigned int i = 0; i < 8; i++)
        {
            const unsigned int dwLow = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 10];
            const unsigned int dwHigh = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 10 + 4];
            D2WordArgStrc tExponent;
            tExponent.dwValue = 0;
            tExponent.wValue = *(unsigned short*)&tContext.FloatSave.RegisterArea[i * 10 + 8];
            int n = _snprintf_s(szText, 0x400, -1, "%5s%d:0x%08x 0x%08x 0x%08x", "ST", i, dwLow, dwHigh, tExponent.dwValue);
            i++;
            const unsigned int dwLow2 = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 10];
            const unsigned int dwHigh2 = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 10 + 4];
            tExponent.wValue = *(unsigned short*)&tContext.FloatSave.RegisterArea[i * 10 + 8];
            n += _snprintf_s(szText + n, 0x400 - n, -1, "%5s%d:0x%08x 0x%08x 0x%08x", "ST", i, dwLow2, dwHigh2, tExponent.dwValue);
            _snprintf_s(szText + n, 0x400 - n, -1, gszNewline);
            pfnPrint(pContext, szText);
        }
        _snprintf_s(szText, 0x400, -1, gszNewline);
        pfnPrint(pContext, szText);
    }
    if (tContext.ContextFlags & 0x10020)
    {
        for (unsigned int i = 0; i < 8; i++)
        {
            const unsigned int dwWord0 = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16];
            const unsigned int dwWord1 = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16 + 4];
            const unsigned int dwWord2 = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16 + 8];
            const unsigned int dwWord3 = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16 + 12];
            int n = _snprintf_s(szText, 0x400, -1, "%5s%d:0x%08x 0x%08x 0x%08x 0x%08x", "XMM", i, dwWord0, dwWord1, dwWord2, dwWord3);
            i++;
            const unsigned int dwWord0b = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16];
            const unsigned int dwWord1b = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16 + 4];
            const unsigned int dwWord2b = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16 + 8];
            const unsigned int dwWord3b = *(unsigned int*)&tContext.FloatSave.RegisterArea[i * 16 + 12];
            n += _snprintf_s(szText + n, 0x400 - n, -1, "%5s%d:0x%08x 0x%08x 0x%08x 0x%08x", "XMM", i, dwWord0b, dwWord1b, dwWord2b, dwWord3b);
            _snprintf_s(szText + n, 0x400 - n, -1, gszNewline);
            pfnPrint(pContext, szText);
        }
        _snprintf_s(szText, 0x400, -1, gszNewline);
        pfnPrint(pContext, szText);
    }
}

D2CrashHandlerFn gpfnCrashHandler; // 0x00992B10

// 0x00403AC0
static void sub_00403AC0_GetExceptionName(char* szBuffer, unsigned long dwCode)
{
    const char* szName;
    switch (dwCode)
    {
    case 0xC0000005: szName = "ACCESS_VIOLATION"; break;
    case 0x80000002: szName = "DATATYPE_MISALIGNMENT"; break;
    case 0x80000003: szName = "BREAKPOINT"; break;
    case 0x80000004: szName = "SINGLE_STEP"; break;
    case 0xC000008C: szName = "ARRAY_BOUNDS_EXCEEDED"; break;
    case 0xC000008D: szName = "FLT_DENORMAL_OPERAND"; break;
    case 0xC000008E: szName = "FLT_DIVIDE_BY_ZERO"; break;
    case 0xC000008F: szName = "FLT_INEXACT_RESULT"; break;
    case 0xC0000090: szName = "FLT_INVALID_OPERATION"; break;
    case 0xC0000091: szName = "FLT_OVERFLOW"; break;
    case 0xC0000092: szName = "FLT_STACK_CHECK"; break;
    case 0xC0000093: szName = "FLT_UNDERFLOW"; break;
    case 0xC0000094: szName = "INT_DIVIDE_BY_ZERO"; break;
    case 0xC0000095: szName = "INT_OVERFLOW"; break;
    case 0xC0000096: szName = "PRIV_INSTRUCTION"; break;
    case 0xC0000006: szName = "IN_PAGE_ERROR"; break;
    case 0xC000001D: szName = "ILLEGAL_INSTRUCTION"; break;
    case 0xC0000025: szName = "NONCONTINUABLE_EXCEPTION"; break;
    case 0xC00000FD: szName = "STACK_OVERFLOW"; break;
    case 0xC0000026: szName = "INVALID_DISPOSITION"; break;
    case 0x80000001: szName = "GUARD_PAGE"; break;
    case 0xC0000008: szName = "INVALID_HANDLE"; break;
    default:
    {
        void* hNtdll = GetModuleHandleA("ntdll.dll");
        if (!hNtdll || FormatMessageA(0xA00, hNtdll, dwCode, 0x400, szBuffer, 0x100, 0) <= 0)
        {
            strncpy_s(szBuffer, 0x100, "unknown exception", -1);
        }
        return;
    }
    }
    strncpy_s(szBuffer, 0x100, szName, -1);
}

// 0x00403E90
long __stdcall sub_00403E90_UnhandledExceptionFilter(void* pExceptionPointers)
{
    if (!gpfnCrashHandler)
        return 0;
    D2ExceptionPointersStrc* pPointers = (D2ExceptionPointersStrc*)pExceptionPointers;
    char szName[0x100];
    sub_00403AC0_GetExceptionName(szName, pPointers->pExceptionRecord->ExceptionCode);
    D2CrashHandlerInfoStrc tReport;
    tReport.szBuffer[0] = 0;
    tReport.szName = szName;
    tReport.szText = tReport.szBuffer;
    tReport.dwThreadId = GetCurrentThreadId();
    tReport.pPointers = pPointers;
    tReport.nUnk08 = 0;
    tReport.nUnk0C = 0;
    tReport.nUnk10 = 0;
    const int nResult = gpfnCrashHandler(&tReport, gpCrashContext);
    if (!nResult)
        return 0;
    return nResult == 1 ? -1 : 1;
}

// 0x00403F50
void __cdecl sub_00403F50_Nop()
{
}

// 0x00648370
void __cdecl sub_00648370_Nop()
{
}

// 0x00648380
void __cdecl sub_00648380_Nop()
{
}

// 0x00648430
void __cdecl sub_00648430_Nop()
{
}

// 0x00648440
void __cdecl sub_00648440_Nop()
{
}

// 0x00648450
void __cdecl sub_00648450_Nop()
{
}

// 0x00401790
bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo)
{
    char szPath[0x400];
    char* pDest = szPath;
    const char* pSource = gszTextBuffer;
    size_t nLeft = 0x400;
    if (nLeft != 0 && --nLeft != 0)
    {
        do
        {
            if ((*pDest++ = *pSource++) == 0)
            {
                break;
            }
        }
        while (--nLeft != 0);
    }
    if (nLeft == 0)
    {
        *pDest = 0;
        while (*pSource++)
        {
        }
    }
    const size_t nLength = pSource - gszTextBuffer - 1;
    if (nLength >= 0x400)
        return false;
    if (szPath[nLength - 1] != '/' && szPath[nLength - 1] != '\\')
        sub_00404150_StrlCat("\\", szPath, 0x400);
    sub_00404150_StrlCat("BlizzardError.exe", szPath, 0x400);
    if (!sub_00404330_FileExistsUtf8(szPath))
        return false;
    char szCommand[0x1000] = "";
    if (pInfo->dwFlags & 1)
        sub_00404150_StrlCat(" -auto", szCommand, 0x1000);
    if (pInfo->dwFlags & 2)
        sub_00404150_StrlCat(" -nocancel", szCommand, 0x1000);
    if (pInfo->dwFlags & 4)
        sub_00404150_StrlCat(" -simple", szCommand, 0x1000);
    if (pInfo->szFrom)
    {
        sub_00404150_StrlCat(" -from ", szCommand, 0x1000);
        sub_00404150_StrlCat(pInfo->szFrom, szCommand, 0x1000);
    }
    if (pInfo->szLocale)
    {
        sub_00404150_StrlCat(" -locale ", szCommand, 0x1000);
        sub_00404150_StrlCat(pInfo->szLocale, szCommand, 0x1000);
    }
    if (pInfo->szName)
    {
        sub_00404150_StrlCat(" -product \"", szCommand, 0x1000);
        sub_00404150_StrlCat(pInfo->szName, szCommand, 0x1000);
        sub_00404150_StrlCat("\"", szCommand, 0x1000);
    }
    for (unsigned int i = 0; i < pInfo->nLines; i++)
    {
        if (pInfo->apszLines[i] && *pInfo->apszLines[i])
        {
            sub_00404150_StrlCat(" -attachment \"", szCommand, 0x1000);
            sub_00404150_StrlCat(pInfo->apszLines[i], szCommand, 0x1000);
            sub_00404150_StrlCat("\"", szCommand, 0x1000);
        }
    }
    sub_00404150_StrlCat(" \"", szCommand, 0x1000);
    sub_00404150_StrlCat(szText, szCommand, 0x1000);
    sub_00404150_StrlCat("\"", szCommand, 0x1000);
    return ERRORMANAGER_CreateProcessUtf8(szPath, szCommand);
}

// 0x00404150
static size_t __stdcall sub_00404150_StrlCat(const char* szSource, char* szDest, size_t nSize)
{
    char* pDest = szDest;
    const char* pSource = szSource;
    size_t nLeft = nSize;
    while (*pDest != 0 && nLeft-- != 0)
        pDest++;
    const size_t nDestLength = pDest - szDest;
    nLeft = nSize - nDestLength;
    if (nLeft == 0)
    {
        return nDestLength + strlen(pSource);
    }
    while (*pSource != 0)
    {
        if (nLeft != 1)
        {
            *pDest++ = *pSource;
            nLeft--;
        }
        pSource++;
    }
    *pDest = 0;
    return nDestLength + (pSource - szSource);
}

// 0x00404730
static int sub_00404730_GetImageKind(const D2ImageOptionalHeaderStrc* pHeader)
{
    if (pHeader->Magic == 0x10B)
    {
        return 1;
    }
    if (pHeader->Magic == 0x20B)
    {
        return 2;
    }
    return 0;
}

// 0x00404760
static bool sub_00404760_IsDosHeaderValid(const D2ImageDosHeaderStrc* pImage)
{
    if (IsBadReadPtr(pImage, 0x40))
    {
        return false;
    }
    if (pImage->e_magic != 0x5A4D)
    {
        return false;
    }
    return true;
}

// 0x00404780
static inline bool sub_00404780_IsNtHeaderValid(const D2ImageNtHeadersStrc* pNt)
{
    if (IsBadReadPtr(pNt, 4))
    {
        return false;
    }
    if (pNt->Signature != 0x4550)
    {
        return false;
    }
    if (IsBadReadPtr(&pNt->FileHeader, 0x14))
    {
        return false;
    }
    if (IsBadReadPtr(&pNt->OptionalHeader, pNt->FileHeader.SizeOfOptionalHeader))
    {
        return false;
    }
    if (!sub_00404730_GetImageKind(&pNt->OptionalHeader))
    {
        return false;
    }
    return true;
}

static bool sub_004047D0_GetDebugDirectory(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeaderStrc* pHeader)
{
    const int nKind = sub_00404730_GetImageKind(pHeader);
    if (!nKind)
    {
        return false;
    }
    *pRva = 0;
    *pSize = -1;
    unsigned long nRva;
    unsigned long nSize;
    if (nKind == 2)
    {
        const D2ImageOptionalHeader64Strc* pHeader64 = (const D2ImageOptionalHeader64Strc*)pHeader;
        if (pHeader64->NumberOfRvaAndSizes <= 6)
        {
            return false;
        }
        nRva = pHeader64->DataDirectory[6].VirtualAddress;
        nSize = pHeader64->DataDirectory[6].Size;
    }
    else
    {
        if (pHeader->NumberOfRvaAndSizes <= 6)
        {
            return false;
        }
        nRva = pHeader->DataDirectory[6].VirtualAddress;
        nSize = pHeader->DataDirectory[6].Size;
    }
    *pSize = nSize;
    *pRva = nRva;
    return (!nRva && !nSize) || (nRva && AUTOMAP_IsDebugDirectorySizeValid(*pSize));
}

// 0x00404850
BOOLEAN __stdcall AUTOMAP_IsDebugDirectorySizeValid(unsigned int nValue)
{
    return nValue >= 0x1C;
}

// 0x00404860
static void sub_00404860_SetNb10Info(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv)
{
    pModule->nTimeStamp = pCv->dwSignature;
    memset(&pModule->tGuid, 0, sizeof(pModule->tGuid));
}

// 0x00404890
static void sub_00404890_CopyRsdsGuid(D2CrashModuleStrc* pModule, const D2CvRsdsStrc* pCv)
{
    pModule->tGuid = pCv->tGuid;
}

// 0x004048C0
static bool sub_004048C0_ReadCodeView(const unsigned long* pCv, D2CrashModuleStrc* pModule, unsigned int nSize)
{
    if (nSize < 4)
    {
        return false;
    }
    if (IsBadReadPtr(pCv, nSize))
    {
        return false;
    }
    if (*pCv == 0x3031424E)
    {
        return sub_00404F80_ReadNb10(pModule, (const D2CvNb10Strc*)pCv);
    }
    if (*pCv == 0x53445352)
    {
        return sub_00404FF0_ReadRsds((const D2CvRsdsStrc*)pCv, pModule);
    }
    return false;
}

// 0x00404900
static bool __stdcall sub_00404900_FindCodeView(const D2ImageDosHeaderStrc* pImage, const D2ImageDebugDirStrc* pDirs, D2CrashModuleStrc* pModule, unsigned long nSize)
{
    const unsigned int nCount = nSize / sizeof(D2ImageDebugDirStrc);
    for (unsigned int i = 0; i < nCount; i++)
    {
        const unsigned long* pData = (const unsigned long*)((const char*)pImage + pDirs[i].AddressOfRawData);
        if (pDirs[i].Type == 2 && sub_004048C0_ReadCodeView(pData, pModule, pDirs[i].SizeOfData))
        {
            return true;
        }
    }
    return false;
}

static bool __stdcall sub_004049A0_ReadImageInfo(D2CrashModuleStrc* pModule, const D2ImageDosHeaderStrc* pImage)
{
    pModule->pBase = (void*)pImage;
    if (!sub_00404760_IsDosHeaderValid(pImage))
    {
        return false;
    }
    const D2ImageNtHeadersStrc* pNt = (const D2ImageNtHeadersStrc*)((const char*)pImage + pImage->e_lfanew);
    if (!sub_00404780_IsNtHeaderValid(pNt))
    {
        return false;
    }
    pModule->nSize = pNt->OptionalHeader.SizeOfImage;
    pModule->nTimeDateStamp = pNt->FileHeader.TimeDateStamp;
    if (pImage->e_res2[2] == 0xB74F && pImage->e_res2[3] == 0x2D98)
    {
        pModule->nVersion = (pImage->e_res2[1] << 16) + pImage->e_res2[0];
        if (pModule->nVersion)
        {
            pModule->nVersion *= 0xFDCA75BB;
        }
    }
    unsigned long nRva = 0;
    unsigned long nSize = 0;
    if (sub_004047D0_GetDebugDirectory(&nSize, &nRva, &pNt->OptionalHeader) && nRva && nSize)
    {
        const D2ImageDebugDirStrc* pDirs = (const D2ImageDebugDirStrc*)((const char*)pImage + nRva);
        if (!IsBadReadPtr(pDirs, nSize) && AUTOMAP_IsDebugDirectorySizeValid(nSize))
        {
            sub_00404900_FindCodeView(pImage, pDirs, pModule, nSize);
        }
    }
    return true;
}

bool D2ModuleStrc::sub_00404AB0_VisitModule(void* pContext, const wchar_t* wszName, int nNameLength)
{
    D2CrashModuleStrc tModule;
    tModule.pBase = 0;
    tModule.nSize = 0;
    tModule.nTimeStamp = 0;
    memset(&tModule.tGuid, 0, sizeof(tModule.tGuid));
    tModule.nAge = 0;
    tModule.nTimeDateStamp = 0;
    tModule.nVersion = 0;
    tModule.szName[0] = 0;
    tModule.szPath[0] = 0;
    const int nLength = WideCharToMultiByte(0xFDE9, 0, wszName, nNameLength, tModule.szName, sizeof(tModule.szName), 0, 0);
    if (nLength < 0)
    {
        tModule.szName[0] = 0;
    }
    else if (nLength > sizeof(tModule.szName) - 1)
    {
        tModule.szName[sizeof(tModule.szName) - 1] = 0;
    }
    else
    {
        tModule.szName[nLength] = 0;
    }
    char* pName = 0;
    char* pSep = strrchr(tModule.szName, '/');
    if (pSep > pName)
    {
        pName = pSep;
    }
    pSep = strrchr(tModule.szName, '\\');
    if (pSep && pSep > pName)
    {
        pName = pSep;
    }
    pSep = strrchr(tModule.szName, ':');
    if (pSep && pSep > pName)
    {
        pName = pSep;
    }
    pName = pName ? pName + 1 : tModule.szName;
    memcpy(tModule.szName, pName, sizeof(tModule.szName));
    if (!sub_004049A0_ReadImageInfo(&tModule, (const D2ImageDosHeaderStrc*)this))
    {
        return true;
    }
    D2CrashModuleListStrc* pList = (D2CrashModuleListStrc*)pContext;
    if (!pList)
    {
        return false;
    }
    pList->aModules[pList->nCount] = tModule;
    ++pList->nCount;
    return pList->nCount < 0x100;
}

// 0x00404F80
static bool sub_00404F80_ReadNb10(D2CrashModuleStrc* pModule, const D2CvNb10Strc* pCv)
{
    if (IsBadReadPtr(pCv, 0x14))
    {
        return false;
    }
    if (IsBadStringPtrA(pCv->szPdbName, 0x104))
    {
        return false;
    }
    strncpy_s(pModule->szPath, sizeof(pModule->szPath), pCv->szPdbName, -1);
    pModule->nAge = pCv->dwAge;
    sub_00404860_SetNb10Info(pModule, pCv);
    return true;
}

// 0x00404FF0
static bool sub_00404FF0_ReadRsds(const D2CvRsdsStrc* pCv, D2CrashModuleStrc* pModule)
{
    if (IsBadReadPtr(pCv, 0x1C))
    {
        return false;
    }
    if (IsBadStringPtrA(pCv->szPdbName, 0x104))
    {
        return false;
    }
    strncpy_s(pModule->szPath, sizeof(pModule->szPath), pCv->szPdbName, -1);
    pModule->nAge = pCv->dwAge;
    sub_00404890_CopyRsdsGuid(pModule, pCv);
    return true;
}

extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void* pAddress, D2MemoryBasicInfoStrc* pBuffer, unsigned long nLength); // 0x006CC244

// 0x00404F40
static void __stdcall sub_00404F40_GetDebugDirectory64(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeader64Strc* pHeader)
{
    if (pHeader->NumberOfRvaAndSizes > 6)
    {
        const D2ImageDataDirStrc tDir = pHeader->DataDirectory[6];
        *pRva = tDir.VirtualAddress;
        *pSize = tDir.Size;
    }
}

void __fastcall sub_G02_Emit_00404F40(const D2ImageOptionalHeader64Strc* pHeader, unsigned long* pOut)
{
    sub_00404F40_GetDebugDirectory64(&pOut[1], &pOut[0], pHeader);
    sub_00404F40_GetDebugDirectory64(&pOut[3], &pOut[2], pHeader + 1);
}

// 0x00404F60
static void __stdcall sub_00404F60_GetDebugDirectory32(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeaderStrc* pHeader)
{
    if (pHeader->NumberOfRvaAndSizes > 6)
    {
        const D2ImageDataDirStrc tDir = pHeader->DataDirectory[6];
        *pRva = tDir.VirtualAddress;
        *pSize = tDir.Size;
    }
}

void __fastcall DebugDirectory32Context(const D2ImageOptionalHeaderStrc* pHeader, unsigned long* pOut)
{
    sub_00404F60_GetDebugDirectory32(&pOut[1], &pOut[0], pHeader);
    sub_00404F60_GetDebugDirectory32(&pOut[3], &pOut[2], pHeader + 1);
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

// 0x00405060
int D2ThreadContextStrc::sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames)
{
    D2StackFrameStrc* pOut = pFrames;
    unsigned int nMaxFrames = 0x80;
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    if (this)
    {
        tContext = *this;
    }
    else
    {
        if (GetCurrentThreadId() == dwThreadId)
        {
            tContext.ContextFlags = 0x10001;
            RtlCaptureContext(&tContext);
        }
        else
        {
            tContext.ContextFlags = 0x10001;
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
    }
    unsigned int nCount = 0;
    unsigned long dwPc = tContext.Eip;
    unsigned long dwFrame = tContext.Ebp;
    unsigned long dwStack = tContext.Esp;
    unsigned long dwStackTop;
    unsigned long dwStackSize;
    unsigned long dwStackPointer;
    if (!ERRORMANAGER_GetThreadStack(&dwStackSize, dwThreadId, &dwStackTop, &dwStackPointer))
    {
        if (hThread)
        {
            ResumeThread(hThread);
            CloseHandle(hThread);
        }
        return 0;
    }
    __try
    {
        for (unsigned int i = 0; i < nMaxFrames; i++)
        {
            if (i >= (unsigned int)nSkipFrames)
            {
                pOut[nCount].dwPc = dwPc;
                pOut[nCount].dwStack = dwStack;
                pOut[nCount].dwFrame = dwFrame;
                nCount++;
                if (nCount >= nMaxFrames)
                    break;
            }
            if (dwFrame <= dwStack)
                break;
            if (dwFrame + 8 > dwStackTop)
                break;
            unsigned long dwNext = *(unsigned long*)dwFrame;
            if (dwNext & 3)
                break;
            if (dwNext <= dwFrame)
                break;
            dwPc = *(unsigned long*)(dwFrame + 4);
            dwStack = dwFrame + 4;
            dwFrame = dwNext;
        }
    }
    __except (1)
    {
    }
    if (hThread)
    {
        ResumeThread(hThread);
        CloseHandle(hThread);
    }
    return nCount;
}
