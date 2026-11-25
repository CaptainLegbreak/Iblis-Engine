#include "Fog.h"
#include "D2GameTypes.h"
#include "D2NetTypes.h"
#include "D2FogTypes.h"
#include "D2FogTypes.h"
#include "D2ExceptionPointers.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct D2ImageHlpLineStrc;

struct D2PeDosHeaderStrc;

struct D2PeNtHeadersStrc;

struct D2PeSectionStrc;


struct D2ImageHlpStackFrameStrc;

struct D2ImageHlpSymbolStrc;

struct D2ImageHlpModuleStrc;

struct D2CrashDumpRecordStrc;

struct D2CrashDumpEntryStrc;

struct D2SystemTimeStrc;

struct D2ModuleInfoStrc;

struct D2MemoryBasicInfoStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0


extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

int __fastcall EXCEPTIONS_GetAppPath(char* szPath, unsigned int nSize); // 0x0040C220

D2ModuleInfoStrc* __stdcall EXCEPTIONS_GetModuleListToolhelp(unsigned long dwPid); // 0x0040B690

int (__stdcall* gpfnImageHlpSymCleanup)(void* hProcess); // 0x0075CFDC

unsigned long (__stdcall* gpfnImageHlpSymGetOptions)(); // 0x0075CFF0

int (__stdcall* gpfnImageHlpSymInitialize)(void* hProcess, const char* szSearchPath, int bInvadeProcess); // 0x0075CFF8

unsigned long (__stdcall* gpfnSymLoadModule)(void* hProcess, void* hFile, const char* szImageName, const char* szModuleName, unsigned long dwBase, unsigned long dwSize); // 0x0075CFFC

unsigned long (__stdcall* gpfnImageHlpSymSetOptions)(unsigned long dwOptions); // 0x0075D004

int gbImageHlpLoaded; // 0x0075D014

extern "C" const char gszExceptionsCppFile[]; // 0x006CD628





typedef int (__stdcall* StackWalkFn)(unsigned long dwMachine, void* hProcess, void* hThread, D2ImageHlpStackFrameStrc* pFrame, void* pContext, void* pfnReadMemory, void* pfnFunctionTableAccess, void* pfnGetModuleBase, void* pfnTranslateAddress);

typedef int (__stdcall* SymGetSymFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpSymbolStrc* pSymbol);

typedef int (__stdcall* SymGetModuleInfoFn)(void* hProcess, unsigned long dwAddress, D2ImageHlpModuleStrc* pModuleInfo);

typedef int (__stdcall* SymGetLineFromAddrFn)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" const char gszEmptyString_006FFC44[]; // 0x006FFC44

const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szPath); // 0x00408000

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

int __cdecl s_DoSymInitialize(); // 0x0040C620

int __fastcall EXCEPTIONS_ReleaseSymbols(int all); // 0x0040C720

int (__stdcall* gpfnSymGetLineFromAddr)(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine); // 0x0075CFE4

void* gpfnSymFunctionTableAccess; // 0x0075CFE0

void* gpfnSymGetModuleBase; // 0x0075CFE8

SymGetModuleInfoFn gpfnSymGetModuleInfo; // 0x0075CFEC

SymGetSymFromAddrFn gpfnSymGetSymFromAddr; // 0x0075CFF4

StackWalkFn gpfnStackWalk; // 0x0075D008

extern unsigned int gnStackWalkDepth; // 0x0075D018

struct D2CrashDumpRecordStrc
{
    unsigned long dwHeader0;
    unsigned long dwHeader1;
    unsigned long dwType;
    int nCount;
    unsigned long adwData[8];
};

void __fastcall LOGMANAGER_GetLogDirectory(char* szDirectory, int nSize); // 0x0040F000

void __stdcall SMemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0


extern "C" unsigned int __cdecl fread(void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684782

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize); // 0x0041D200

extern "C" const char gszReadBinary_006CDC90[]; // 0x006CDC90

D2CriticalSectionStrc gtImageHlpLock; // 0x0075CFBC

int gnSymInitCount; // 0x0075CFD4

static void __stdcall EXCEPTIONS_GetLogicalAddress(char* szModule, unsigned long* pnSection, unsigned long* pnOffset, void* pAddress, unsigned int nSize); // 0x0040C520


int gnLogQueueCount; // 0x0075E870

struct D2ToolhelpModuleEntryStrc;


typedef void* (__stdcall* CreateToolhelp32SnapshotFn)(unsigned long dwFlags, unsigned long dwProcessId);

typedef int (__stdcall* Module32Fn)(void* hSnapshot, D2ToolhelpModuleEntryStrc* pEntry);

typedef int (__stdcall* EnumProcessModulesFn)(void* hProcess, void** phModules, unsigned long nSize, unsigned long* pnNeeded);

typedef unsigned long (__stdcall* GetModuleNameFn)(void* hProcess, void* hModule, char* szName, unsigned long nSize);

typedef int (__stdcall* GetModuleInformationFn)(void* hProcess, void* hModule, D2PsapiModuleInfoStrc* pInfo, unsigned long nSize);

extern "C" const char gszExceptionsCpp_006CD628[]; // 0x006CD628


extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* lp, unsigned int ucb); // 0x006CC238

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9

#pragma intrinsic(strlen)

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

void __cdecl LOGMANAGER_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410740

char* __fastcall sub_004113E0_EscapeString(char* szDst, const char* szSrc, int nSize, char cQuote); // 0x004113E0

D2ModuleInfoStrc* __fastcall EXCEPTIONS_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList); // 0x0040BCB0

extern const char gszStackEipLine[]; // 0x006CD938

extern const char gszLogLineFormat[]; // 0x006CD90C

extern const char gszStackStringLine[]; // 0x006CD8C8

extern const char gszStackSymbolLine[]; // 0x006CD890

extern const char gszStackPad_006FFC44[]; // 0x006FFC44

static int __stdcall EXCEPTIONS_GetLineFromAddrRetry(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine); // 0x0040B600

static D2ModuleInfoStrc* __stdcall EXCEPTIONS_GetModuleList(void* hProcess, unsigned long dwPid); // 0x0040BC50

static D2ModuleInfoStrc* __stdcall EXCEPTIONS_LoadModuleSymbols(unsigned long dwPid, void* hProcess); // 0x0040C0F0

static char* EXCEPTIONS_ComposeSymbolPath(char* szPath); // 0x0040C290

void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...);               // 0x004106B0

void __cdecl LOGMANAGER_CloseLogFiles();                                                                  // 0x0040F960

extern "C" void __fastcall EXCEPTIONS_FreeModuleList(D2ModuleInfoStrc* pList);                                  // 0x0040B660

void __fastcall EXCEPTIONS_DumpAnnotatedStack(void* hProcess, D2ThreadContextStrc* pContext, D2ModuleInfoStrc* pModules); // 0x0040BCF0


char gszImageHlpSymSearchPath[4096]; // 0x0075BFB8

int gbSymQuiet; // 0x0075CFB8

void* ghImageHlp; // 0x0075CFD8

void* gpfnSymUnloadModule; // 0x0075D000

void* gpfnUnDecorateSymbolName; // 0x0075D00C

void* gpfnImageHlpMiniDumpWriteDump; // 0x0075D010

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hLibModule);

extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();

extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext);

extern "C" __declspec(dllimport) int __stdcall DuplicateHandle(void* hSourceProcess, void* hSource, void* hTargetProcess, void** phTarget, unsigned long dwAccess, int bInherit, unsigned long dwOptions);

typedef void (__cdecl* D2SETranslatorFn)(unsigned int, D2ExceptionPointersStrc*);

extern "C" D2SETranslatorFn __cdecl _set_se_translator(D2SETranslatorFn pfnTranslator); // 0x00684AF3

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

void __cdecl LOGMANAGER_LogMemoryDump(const char* szPrefix, const char* szTitle, unsigned long dwAddress, unsigned int nSize, int nArg5, int nArg6, int nArg7); // 0x00410040

int __fastcall QuickStackWalk(const char* szPrefix, void* hThread, D2ThreadContextStrc* pContext); // 0x0040C7A0

int __fastcall sShowStack(void* hThread, D2ThreadContextStrc* pContext); // 0x0040CC10

void __cdecl EXCEPTIONS_SETranslator(unsigned int nCode, D2ExceptionPointersStrc* pExceptionInfo); // 0x0040D540

// 0x0040B500
int __cdecl EXCEPTIONS_UnloadImageHlp()
{
    gbImageHlpLoaded = 0;
    if (ghImageHlp)
    {
        FreeLibrary(ghImageHlp);
        ghImageHlp = 0;
    }
    DeleteCriticalSection(&gtImageHlpLock);
    return 1;
}

// 0x0040B540
void __fastcall EXCEPTIONS_DumpThreadStackAndCode(void* hThread)
{
    D2ThreadContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.ContextFlags = 0x10007;
    GetThreadContext(hThread, &tContext);
// build: symbol ?LOGMANAGER_LogWritePrefixed@* 0x00410740
    LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "Stack bytes:\n");
    LOGMANAGER_LogMemoryDump("ERR", &gszEmptyAssertText, tContext.Esp, 0x1000, 0, 1, 0);
    LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "Code bytes:\n");
    LOGMANAGER_LogMemoryDump("ERR", &gszEmptyAssertText, tContext.Eip, 0x20, 0, 1, 0);
}

// 0x0040B600
static int __stdcall EXCEPTIONS_GetLineFromAddrRetry(void* hProcess, unsigned long dwAddress, unsigned long* pdwDisplacement, D2ImageHlpLineStrc* pLine)
{
    if (!gpfnSymGetLineFromAddr)
    {
        return 0;
    }

    unsigned long nBack = 0;
    while (!gpfnSymGetLineFromAddr(hProcess, dwAddress - nBack, pdwDisplacement, pLine))
    {
        if (++nBack == 100)
        {
            return 0;
        }
    }

    if (nBack)
    {
        *pdwDisplacement = nBack;
    }

    return 1;
}

// 0x0040B660
extern "C" void __fastcall EXCEPTIONS_FreeModuleList(D2ModuleInfoStrc* pList)
{
    while (pList)
    {
        D2ModuleInfoStrc* pNext = pList->pNext;
        FOG_Free(pList, gszExceptionsCppFile, 0x1F7, 0);
        pList = pNext;
    }
}

// 0x0040B690
D2ModuleInfoStrc* __stdcall EXCEPTIONS_GetModuleListToolhelp(unsigned long dwPid)
{
    D2ToolhelpModuleEntryStrc tModuleEntry;
    D2ModuleInfoStrc* pList = 0;
    CreateToolhelp32SnapshotFn pfnCreateToolhelp32Snapshot = 0;
    Module32Fn pfnModule32First = 0;
    Module32Fn pfnModule32Next = 0;
    void* hLibrary;
    const char* aszLibraries[2];
    aszLibraries[0] = "kernel32.dll";
    aszLibraries[1] = "tlhelp32.dll";

    for (int i = 0; i < 2; ++i)
    {
        hLibrary = LoadLibraryA(aszLibraries[i]);
        if (hLibrary)
        {
            pfnCreateToolhelp32Snapshot = (CreateToolhelp32SnapshotFn)GetProcAddress(hLibrary, "CreateToolhelp32Snapshot");
            pfnModule32First = (Module32Fn)GetProcAddress(hLibrary, "Module32First");
            pfnModule32Next = (Module32Fn)GetProcAddress(hLibrary, "Module32Next");
            if (pfnCreateToolhelp32Snapshot && pfnModule32First && pfnModule32Next)
            {
                break;
            }

            FreeLibrary(hLibrary);
            hLibrary = 0;
        }
    }

    if (!hLibrary)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Unable to load toolhelp library");
        return 0;
    }

    void* hSnapshot = pfnCreateToolhelp32Snapshot(8, dwPid);
    if (hSnapshot == (void*)-1)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Unable to get toolhelp snapshot");
        return 0;
    }

    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Enumerate modules...");
    for (int bFound = pfnModule32First(hSnapshot, &tModuleEntry); bFound; bFound = pfnModule32Next(hSnapshot, &tModuleEntry))
    {
        D2ModuleInfoStrc* pEntry = (D2ModuleInfoStrc*)FOG_Alloc(sizeof(D2ModuleInfoStrc), ".\\Src\\Exceptions.cpp", 0x253, 0);
        memset(pEntry, 0, sizeof(D2ModuleInfoStrc));
        strcpy(pEntry->szPath, tModuleEntry.szExePath);
        strcpy(pEntry->szName, tModuleEntry.szModule);
        pEntry->dwBase = tModuleEntry.modBaseAddr;
        pEntry->dwSize = tModuleEntry.modBaseSize;
        pEntry->pNext = pList;
        pList = pEntry;
        D2ModuleInfoStrc* pPrevious = 0;
        for (D2ModuleInfoStrc* pCurrent = pEntry; pCurrent; pCurrent = pPrevious->pNext)
        {
            D2ModuleInfoStrc* pNext = pCurrent->pNext;
            if (!pNext || pCurrent->dwBase <= pNext->dwBase)
            {
                break;
            }
            if (pCurrent == pList)
            {
                pList = pNext;
            }
            else
            {
                pPrevious->pNext = pNext;
            }
            pCurrent->pNext = pNext->pNext;
            pNext->pNext = pCurrent;
            pPrevious = pNext;
        }
    }

    CloseHandle(hSnapshot);
    FreeLibrary(hLibrary);
    return pList;
}

// 0x0040B920
D2ModuleInfoStrc* __stdcall EXCEPTIONS_GetModuleListPsapi(void* hProcess)
{
    void* ahModules[0x100];
    char szFileName[0x104];
    char szBaseName[0x100];
    unsigned long nNeeded;
    D2PsapiModuleInfoStrc tInfo;
    D2ModuleInfoStrc* pList = 0;
    void* hPsapi = LoadLibraryA("psapi.dll");
    if (!hPsapi)
    {
        return 0;
    }
    EnumProcessModulesFn pfnEnumProcessModules = (EnumProcessModulesFn)GetProcAddress(hPsapi, "EnumProcessModules");
    GetModuleNameFn pfnGetModuleFileNameEx = (GetModuleNameFn)GetProcAddress(hPsapi, "GetModuleFileNameExA");
    GetModuleNameFn pfnGetModuleBaseName = (GetModuleNameFn)GetProcAddress(hPsapi, "GetModuleBaseNameA");
    GetModuleInformationFn pfnGetModuleInformation = (GetModuleInformationFn)GetProcAddress(hPsapi, "GetModuleInformation");
    if (!pfnEnumProcessModules || !pfnGetModuleFileNameEx || !pfnGetModuleBaseName || !pfnGetModuleInformation)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Unable to load psapi library");
        goto failed;
    }
    if (!pfnEnumProcessModules(hProcess, ahModules, sizeof(ahModules), &nNeeded))
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Error enumerating modules using PSAPI:  error(%d)", GetLastError());
        goto failed;
    }
    {
        const int nModules = nNeeded / sizeof(void*);
        if (nModules > 0x100)
        {
            LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "PSAPI EnumProcessModules returned invalid number of modules");
            goto failed;
        }
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "\nEnumerate modules...");
        for (int i = 0; i < nModules; ++i)
        {
            if (!pfnGetModuleInformation(hProcess, ahModules[i], &tInfo, sizeof(tInfo)))
            {
                LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "ERROR: PSAPI GetModuleInformation (%d)", GetLastError());
                goto failed;
            }
            if (!pfnGetModuleFileNameEx(hProcess, ahModules[i], szFileName, sizeof(szFileName)))
            {
                LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "ERROR: PSAPI GetModuleFileNameExA (%d)", GetLastError());
                goto failed;
            }
            if (!pfnGetModuleBaseName(hProcess, ahModules[i], szBaseName, sizeof(szBaseName) - 1))
            {
                LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "ERROR: PSAPI GetModuleBaseNameA (%d)", GetLastError());
                goto failed;
            }
            D2ModuleInfoStrc* pEntry = (D2ModuleInfoStrc*)FOG_Alloc(sizeof(D2ModuleInfoStrc), gszExceptionsCpp_006CD628, 0x2D3, 0);
            memset(pEntry, 0, sizeof(D2ModuleInfoStrc));
            strcpy(pEntry->szPath, szFileName);
            strcpy(pEntry->szName, szBaseName);
            pEntry->dwBase = tInfo.nBase;
            pEntry->dwSize = tInfo.nSize;
            pEntry->pNext = pList;
            pList = pEntry;
            D2ModuleInfoStrc* pPrevious = 0;
            for (D2ModuleInfoStrc* pCurrent = pEntry; pCurrent; pCurrent = pPrevious->pNext)
            {
                D2ModuleInfoStrc* pNext = pCurrent->pNext;
                if (!pNext || pCurrent->dwBase <= pNext->dwBase)
                {
                    break;
                }
                if (pCurrent == pList)
                {
                    pList = pNext;
                }
                else
                {
                    pPrevious->pNext = pNext;
                }
                pCurrent->pNext = pNext->pNext;
                pNext->pNext = pCurrent;
                pPrevious = pNext;
            }
        }
    }
    FreeLibrary(hPsapi);
    return pList;

failed:
    FreeLibrary(hPsapi);
    EXCEPTIONS_FreeModuleList(pList);
    return 0;
}

// 0x0040BC50
static D2ModuleInfoStrc* __stdcall EXCEPTIONS_GetModuleList(void* hProcess, unsigned long dwPid)
{
    D2ModuleInfoStrc* pList = EXCEPTIONS_GetModuleListToolhelp(dwPid);
    if (!pList)
    {
        pList = sub_0040B920_GetModuleListPsapi(hProcess);
    }

    for (D2ModuleInfoStrc* pModule = pList; pModule; pModule = pModule->pNext)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "    Base:%08lXh  Size:%7lXh  Name:%-15.15s  Path:%s", pModule->dwBase, pModule->dwSize, pModule->szName, pModule->szPath);
    }

    return pList;
}

// 0x0040BCB0
D2ModuleInfoStrc* __fastcall EXCEPTIONS_FindModuleByAddress(unsigned long dwAddress, D2ModuleInfoStrc* pList)
{
    for (D2ModuleInfoStrc* pModule = pList; pModule; pModule = pModule->pNext)
    {
        if (dwAddress >= pModule->dwBase && dwAddress < pModule->dwBase + pModule->dwSize)
            return pModule;
    }
    return 0;
}

// 0x0040BCF0
void __fastcall EXCEPTIONS_DumpAnnotatedStack(void* hProcess, D2ThreadContextStrc* pContext, D2ModuleInfoStrc* pModules)
{
    D2ImageHlpSymbolBufferStrc tSymbol;
    char szEscaped[0x50];
    char szLine[0x100];

    unsigned char* pStack = (unsigned char*)pContext->Esp;
    tSymbol.tSymbol.dwSizeOfStruct = 0x18;
    tSymbol.tSymbol.dwMaxNameLength = 0x100;
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, &gszEmptyAssertText);
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Annotated stack dump");

    {
        unsigned long dwDisplacement;
        unsigned long dwEip = pContext->Eip;
        D2ModuleInfoStrc* pModule = EXCEPTIONS_FindModuleByAddress(dwEip, pModules);
        const char* szSymbol = gpfnSymGetSymFromAddr(hProcess, dwEip, &dwDisplacement, &tSymbol.tSymbol) ? tSymbol.tSymbol.szName : gszUnknown;
        const char* szModule = pModule ? pModule->szName : gszUnknown;
        LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, gszStackEipLine, dwEip, szModule, szSymbol, dwDisplacement);
    }

    int nLines = 0;
    unsigned int nRemaining = 0x1000;
    while (nRemaining > 0)
    {
        if (nLines >= 400)
            break;
        LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "              %08X:", pStack);
        int nCount = nRemaining < 16 ? nRemaining : 16;
        szLine[0] = 0;
        int bFound = 0;
        if (IsBadReadPtr(pStack, nCount))
        {
            SStrCopy(szLine, "<unreadable>", 0x7FFFFFFF);
            break;
        }

        int i;
        for (i = 0; i < nCount; i += 4)
        {
            int nLen = strlen(szLine);
            SStrPrintf(&szLine[nLen], 0x100 - nLen, " %02X%02X%02X%02X", pStack[i], pStack[i + 1], pStack[i + 2], pStack[i + 3]);
            if (EXCEPTIONS_FindModuleByAddress(*(unsigned long*)&pStack[i], pModules))
            {
                bFound = 1;
                i += 4;
                break;
            }
        }

        int nBytes = i;
        for (i = (unsigned int)((16 - i) * 9) / 4 + 2; i > 0; i--)
            SStrPack(szLine, gszStackPad_006FFC44, 0x100);

        int nLen = strlen(szLine);
        int j = nLen;
        for (i = 0; i < nBytes; i++)
        {
            unsigned char c = pStack[i];
            szLine[j++] = (c & 0x7F) < 0x20 ? '.' : c;
        }
        szLine[nLen + i] = 0;
        LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, gszLogLineFormat, szLine);

        if (bFound)
        {
            unsigned long dwValue = *(unsigned long*)&pStack[nBytes - 4];
            D2ModuleInfoStrc* pValueModule = EXCEPTIONS_FindModuleByAddress(dwValue, pModules);
            D2_ASSERT(pValueModule, 0x3A5);
            unsigned long dwValueDisplacement;
            const char* szName = gpfnSymGetSymFromAddr(hProcess, dwValue, &dwValueDisplacement, &tSymbol.tSymbol) ? tSymbol.tSymbol.szName : gszUnknown;
            if (!_stricmp(szName, "`string'") && !dwValueDisplacement)
                LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, gszStackStringLine, dwValue, pValueModule->szName, szName, sub_004113E0_EscapeString(szEscaped, (const char*)dwValue, 0x50, 0));
            else
                LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, gszStackSymbolLine, dwValue, pValueModule->szName, szName, dwValueDisplacement);
            nLines += 3;
        }

        nLines++;
        nRemaining -= nBytes;
        pStack += nBytes;
    }
}

// 0x0040C0F0
static D2ModuleInfoStrc* __stdcall EXCEPTIONS_LoadModuleSymbols(unsigned long dwPid, void* hProcess)
{
    char szImageName[0x104];
    char szModuleName[0x100];

    D2ModuleInfoStrc* pList = EXCEPTIONS_GetModuleList(hProcess, dwPid);
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, &gszEmptyAssertText);
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Load symbols...");

    D2ModuleInfoStrc* pModule = pList;
    while (pModule)
    {
        D2ModuleInfoStrc* pNext = pModule->pNext;
        strcpy(szImageName, pModule->szPath);
        strcpy(szModuleName, pModule->szName);
        const unsigned long dwLoaded = gpfnSymLoadModule(hProcess, 0, szImageName, szModuleName, pModule->dwBase, pModule->dwSize);
        if (!gbSymQuiet)
        {
            if (!dwLoaded)
            {
                LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Error (%d) loading symbols for '%s'", GetLastError(), szModuleName);
            }
            else
            {
                LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Symbols Loaded for '%s'", szModuleName);
            }
        }

        pModule = pNext;
    }

    return pList;
}

// 0x0040C220
int __fastcall EXCEPTIONS_GetAppPath(char* szPath, unsigned int nSize)
{
    szPath[0] = 0;
    if (!GetModuleFileNameA(0, szPath, nSize))
    {
        return 0;
    }
    int i;
    for (i = (int)strlen(szPath) - 1; i > 0; i--)
    {
        if (szPath[i] == '\\' || szPath[i] == '/' || szPath[i] == ':')
        {
            break;
        }
    }
    if (i <= 0)
    {
        return 0;
    }
    if (szPath[i] == ':')
    {
        i += 1;
    }
    szPath[i] = 0;
    return 1;
}

// 0x0040C290
static char* EXCEPTIONS_ComposeSymbolPath(char* szPath)
{
    char szCurrentDir[0x200];
    char szBuffer[0x200];

    *szPath = 0;
    if (!EXCEPTIONS_GetAppPath(szBuffer, 0x200))
    {
        szBuffer[0] = 0;
    }
    else
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetCurrentDirectoryA(0x200, szCurrentDir))
    {
        if (!szBuffer[0] || _stricmp(szBuffer, szCurrentDir))
        {
            strcat(szPath, szCurrentDir);
            strcat(szPath, ";");
        }
    }

    if (GetEnvironmentVariableA("_NT_SYMBOL_PATH", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetEnvironmentVariableA("_NT_ALTERNATE_SYMBOL_PATH", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    if (GetEnvironmentVariableA("SYSTEMROOT", szBuffer, 0x200))
    {
        strcat(szPath, szBuffer);
        strcat(szPath, ";");
    }

    const size_t nLength = strlen(szPath);
    if (nLength)
    {
        szPath[nLength - 1] = 0;
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "User defined symbols path: %s", szPath);
    }
    else
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Unable to generate symbols search path");
    }

    return *szPath ? szPath : 0;
}

// 0x0040C520
static void __stdcall EXCEPTIONS_GetLogicalAddress(char* szModule, unsigned long* pnSection, unsigned long* pnOffset, void* pAddress, unsigned int nSize)
{
    D2MemoryBasicInfoStrc tInfo;

    SStrCopy(szModule, gszUnknown, nSize);
    *pnSection = 0;
    *pnOffset = 0;
    if (!VirtualQuery(pAddress, &tInfo, sizeof(tInfo)))
    {
        return;
    }

    void* hModule = tInfo.AllocationBase;
    if (!hModule)
    {
        hModule = GetModuleHandleA(0);
    }

    if (!GetModuleFileNameA(hModule, szModule, nSize))
    {
        SStrCopy(szModule, gszUnknown, nSize);
        return;
    }

    D2PeDosHeaderStrc* pDosHeader = (D2PeDosHeaderStrc*)hModule;
    if (!pDosHeader || pDosHeader->wMagic != 0x5A4D || !pDosHeader->nNtHeadersOffset)
    {
        return;
    }

    D2PeNtHeadersStrc* pNtHeaders = (D2PeNtHeadersStrc*)((char*)pDosHeader + pDosHeader->nNtHeadersOffset);
    if (pNtHeaders->dwSignature != 0x4550)
    {
        return;
    }

    D2PeSectionStrc* pSection = (D2PeSectionStrc*)(pNtHeaders->aOptionalHeader + pNtHeaders->wSizeOfOptionalHeader);
    const unsigned long dwRva = (char*)pAddress - (char*)hModule;
    for (unsigned int i = 0; i < pNtHeaders->wNumberOfSections; ++i, ++pSection)
    {
        const unsigned long dwStart = pSection->dwVirtualAddress;
        const unsigned long dwLength = pSection->dwSizeOfRawData > pSection->dwVirtualSize ? pSection->dwSizeOfRawData : pSection->dwVirtualSize;
        if (dwRva >= dwStart && dwRva <= dwStart + dwLength)
        {
            *pnSection = i + 1;
            *pnOffset = dwRva - dwStart;
            return;
        }
    }
}

// 0x0040C620
int __cdecl s_DoSymInitialize()
{
    int bResult = 0;
    EnterCriticalSection(&gtImageHlpLock);
    if (gbImageHlpLoaded)
    {
        bResult = 1;
        if (gnSymInitCount++ <= 0)
        {
            if (!gszImageHlpSymSearchPath[0])
            {
                EXCEPTIONS_ComposeSymbolPath(gszImageHlpSymSearchPath);
            }

            void* hProcess = GetCurrentProcess();
            if (!gpfnImageHlpSymInitialize(hProcess, gszImageHlpSymSearchPath, 0))
            {
                LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "s_DoSymInitialize(): err = %lu", GetLastError());
                gpfnImageHlpSymCleanup(hProcess);
                bResult = 0;
                gnSymInitCount = 0;
            }
            else
            {
                ++gnSymInitCount;
                gpfnImageHlpSymSetOptions(gpfnImageHlpSymGetOptions() | 0x10);
                D2ModuleInfoStrc* pModule = EXCEPTIONS_LoadModuleSymbols(GetCurrentProcessId(), hProcess);
                if (pModule)
                {
                    do
                    {
                        D2ModuleInfoStrc* pNext = pModule->pNext;
                        FOG_Free(pModule, gszExceptionsCppFile_006CD628, 0x1F7, 0);
                        pModule = pNext;
                    }
                    while (pModule);
                }
            }
        }
    }

    LeaveCriticalSection(&gtImageHlpLock);
    return bResult;
}

// 0x0040C720
int __fastcall EXCEPTIONS_ReleaseSymbols(int all)
{
    int result = 0;
    if (!gbImageHlpLoaded)
    {
        return 0;
    }
    EnterCriticalSection(&gtImageHlpLock);
    int nCount = gnSymInitCount;
    do
    {
        if (!nCount)
        {
            break;
        }
        gnSymInitCount = --nCount;
        if (nCount)
        {
            result = 1;
            break;
        }
        gpfnImageHlpSymCleanup(GetCurrentProcess());
        if (!all)
        {
            break;
        }
        nCount = gnSymInitCount;
    } while (nCount);
    LeaveCriticalSection(&gtImageHlpLock);
    return result;
}

// 0x0040C7A0
int __fastcall QuickStackWalk(const char* szPrefix, void* hThread, D2ThreadContextStrc* pContext)
{
    if (gnStackWalkDepth > 0)
    {
        return 0;
    }

    ++gnStackWalkDepth;

    __int64 aTotals[4] = {};
    __int64 aStart[4] = {};
    __int64 aEnd[4] = {};

    void* hProcess = GetCurrentProcess();
    if (!s_DoSymInitialize())
    {
        --gnStackWalkDepth;
        return 0;
    }
    aTotals[3] += aEnd[3] - aStart[3];

    D2ImageHlpStackFrameStrc tFrame;
    memset(&tFrame, 0, sizeof(tFrame));
    tFrame.tAddrPC.dwOffset = pContext->Eip;
    tFrame.tAddrPC.nMode = 3;
    tFrame.tAddrStack.dwOffset = pContext->Esp;
    tFrame.tAddrStack.nMode = 3;
    tFrame.tAddrFrame.dwOffset = pContext->Ebp;
    tFrame.tAddrFrame.nMode = 3;

    char aSymbolBuffer[sizeof(D2ImageHlpSymbolStrc) + 0x100];
    D2ImageHlpSymbolStrc* pSymbol = (D2ImageHlpSymbolStrc*)aSymbolBuffer;
    pSymbol->dwSizeOfStruct = sizeof(D2ImageHlpSymbolStrc);
    pSymbol->dwMaxNameLength = 0x100;

    unsigned long aStack[64];
    int nFailures = 0;
    int nEntries;
    for (nEntries = 0; nEntries < 16; ++nEntries)
    {
        if (nFailures >= 3)
        {
            break;
        }

        if (!gpfnStackWalk(0x14C, hProcess, hThread, &tFrame, pContext, 0, gpfnSymFunctionTableAccess, gpfnSymGetModuleBase, 0))
        {
            aTotals[0] += aEnd[0] - aStart[0];
            break;
        }
        aTotals[0] += aEnd[0] - aStart[0];

        if (nEntries >= 1)
        {
            aStack[nEntries] = tFrame.tAddrPC.dwOffset;
            const char* szSymbol;
            unsigned long dwDisplacement = 0;
            D2ImageHlpLineStrc tLine;
            memset(&tLine, 0, sizeof(tLine));
            tLine.dwSizeOfStruct = sizeof(tLine);
            if (gpfnSymGetSymFromAddr(hProcess, tFrame.tAddrPC.dwOffset, &dwDisplacement, pSymbol))
            {
                szSymbol = pSymbol->szName;
                unsigned long dwLineDisplacement = dwDisplacement;
                if (!EXCEPTIONS_GetLineFromAddrRetry(hProcess, tFrame.tAddrPC.dwOffset, &dwLineDisplacement, &tLine))
                {
                    tLine.dwLineNumber = 0;
                }
            }
            else
            {
                ++nFailures;
                szSymbol = gszUnknown;
            }
            aTotals[1] += aEnd[1] - aStart[1];

            D2ImageHlpModuleStrc tModule;
            memset(&tModule, 0, sizeof(tModule));
            tModule.dwSizeOfStruct = sizeof(tModule);
            if (!gpfnSymGetModuleInfo(hProcess, tFrame.tAddrPC.dwOffset, &tModule))
            {
                GetLastError();
                tModule.szModuleName[0] = 0;
            }
            aTotals[2] += aEnd[2] - aStart[2];

            if (tLine.dwLineNumber)
            {
                const char* szFile = ERRORMANAGER_StripSourcePath(tLine.szFileName);
                int nPad = 40 - SStrLen(tModule.szModuleName) - SStrLen(szSymbol);
                if (nPad < 1)
                {
                    nPad = 1;
                }
                LOGMANAGER_LogWritePrefixedLine(szPrefix, "    %08X  %s!%s+%04X  %*s%s,%d", tFrame.tAddrPC.dwOffset, tModule.szModuleName, szSymbol, dwDisplacement, nPad, gszEmptyString_006FFC44, szFile, tLine.dwLineNumber);
            }
            else
            {
                LOGMANAGER_LogWritePrefixedLine(szPrefix, "    %08X  %s!%s+%04X", tFrame.tAddrPC.dwOffset, tModule.szModuleName, szSymbol, dwDisplacement);
            }
        }
    }

    EXCEPTIONS_ReleaseSymbols(0);
    LOGMANAGER_LogWritePrefixedLine(szPrefix, "QuickStackWalk: %d entries, %I64d+%I64d+%I64d+%I64d cycles, %I64d avg", nEntries, aTotals[0], aTotals[1], aTotals[2], aTotals[3], (aTotals[0] + aTotals[1] + aTotals[2] + aTotals[3]) / nEntries);
    --gnStackWalkDepth;
    return 1;
}

// 0x0040CC10
int __fastcall sShowStack(void* hThread, D2ThreadContextStrc* pContext)
{
    unsigned long dwNoStackDump = 0;
    SRegLoadValue("Diablo II", "NoStackDump", 0, &dwNoStackDump);
    if (dwNoStackDump)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "sShowStack: Stack dump turned off in registry");
        return 0;
    }

    if (!gbImageHlpLoaded)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "sShowStack: imagehlp.dll not loaded");
        return 0;
    }

    void* hProcess = 0;
    DuplicateHandle(GetCurrentProcess(), GetCurrentProcess(), GetCurrentProcess(), &hProcess, 0, 0, 2);

    char szSearchPath[0x1000];
    const char* szPath = EXCEPTIONS_ComposeSymbolPath(szSearchPath);
    if (!gpfnImageHlpSymInitialize(hProcess, szPath, 0))
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "SymInitialize(): gle = %lu", GetLastError());
        gpfnImageHlpSymCleanup(hProcess);
        CloseHandle(hProcess);
        return 0;
    }

    gpfnImageHlpSymSetOptions(gpfnImageHlpSymGetOptions() | 0x10);
    const unsigned long dwProcessId = GetCurrentProcessId();
    D2ModuleInfoStrc* pModules = EXCEPTIONS_LoadModuleSymbols(dwProcessId, hProcess);
    EXCEPTIONS_DumpAnnotatedStack(hProcess, pContext, pModules);
    EXCEPTIONS_FreeModuleList(pModules);
    LOGMANAGER_CloseLogFiles();

    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, &gszEmptyAssertText);
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Stack Crawl:");
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Address  Frame    Module       Return    Stack");

    D2ImageHlpStackFrameStrc tFrame;
    memset(&tFrame, 0, sizeof(tFrame));
    tFrame.tAddrPC.dwOffset = pContext->Eip;
    tFrame.tAddrPC.nMode = 3;
    tFrame.tAddrStack.dwOffset = pContext->Esp;
    tFrame.tAddrStack.nMode = 3;
    tFrame.tAddrFrame.dwOffset = pContext->Ebp;
    tFrame.tAddrFrame.nMode = 3;

    D2ImageHlpSymbolBufferStrc tSymbol;
    D2ImageHlpSymbolStrc* pSymbol = &tSymbol.tSymbol;
    pSymbol->dwSizeOfStruct = 0x18;
    pSymbol->dwMaxNameLength = 0x100;

    D2ImageHlpModuleStrc tModule;
    char szModule[0x104];
    int nUnknown = 0;
    int nFrames;
    for (nFrames = 0; nFrames < 0x40; ++nFrames)
    {
        if (nUnknown >= 3)
        {
            break;
        }

        if (!gpfnStackWalk(0x14C, hProcess, hThread, &tFrame, pContext, 0, gpfnSymFunctionTableAccess, gpfnSymGetModuleBase, 0))
        {
            LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "Stack walk error: %d", GetLastError());
            break;
        }

        unsigned long dwSymDisplacement = 0;
        D2ImageHlpLineStrc tLine;
        memset(&tLine, 0, sizeof(tLine));
        const char* szSymbol;
        if (gpfnSymGetSymFromAddr(hProcess, tFrame.tAddrPC.dwOffset, &dwSymDisplacement, pSymbol))
        {
            szSymbol = pSymbol->szName;
            unsigned long dwLineDisplacement = dwSymDisplacement;
            tLine.dwSizeOfStruct = 0x14;
            if (!EXCEPTIONS_GetLineFromAddrRetry(hProcess, tFrame.tAddrPC.dwOffset, &dwLineDisplacement, &tLine))
            {
                tLine.dwLineNumber = 0;
            }
        }
        else
        {
            ++nUnknown;
            szSymbol = gszUnknown;
        }

        unsigned long nSection;
        unsigned long dwOffset;
        EXCEPTIONS_GetLogicalAddress(szModule, &nSection, &dwOffset, (void*)tFrame.tAddrPC.dwOffset, sizeof(szModule));
        const char* szModuleName = strrchr(szModule, '\\');
        LOGMANAGER_LogWritePrefixedNoNewline(&gszEmptyAssertText, "%08x %08x %-12s ", tFrame.tAddrPC.dwOffset, tFrame.tAddrFrame.dwOffset, szModuleName ? szModuleName + 1 : szModule);

        tModule.dwSizeOfStruct = 0x23C;
        if (gpfnSymGetModuleInfo(hProcess, tFrame.tAddrPC.dwOffset, &tModule))
        {
            LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "%s!", tModule.szModuleName);
        }

        LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "%s+%04X ", szSymbol, dwSymDisplacement);
        if (pSymbol->dwFlags & 3)
        {
            LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "[omap] ");
        }

        if (tFrame.pFuncTableEntry)
        {
            D2FpoDataStrc* pFpo = (D2FpoDataStrc*)tFrame.pFuncTableEntry;
            switch (pFpo->cbFrame)
            {
            case 0:
                if (pFpo->fHasSEH)
                {
                    LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "(FPO: [SEH])");
                }
                else
                {
                    LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, " (FPO:");
                    if (pFpo->fUseBP)
                    {
                        LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, " [EBP 0x%08x]", tFrame.dwReserved[0]);
                    }

                    LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, " [%d, %d, %d])", pFpo->wParams, pFpo->dwLocals, pFpo->cbRegs);
                }
                break;

            case 3:
                LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "(FPO: Non-FPO [%d, %d, %d])", pFpo->wParams, pFpo->dwLocals, pFpo->cbRegs);
                break;

            default:
                LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "(UNKNOWN FPO TYPE)");
                break;
            }
        }

        if (tLine.dwLineNumber)
        {
            const char* szFile = strrchr(tLine.szFileName, '\\');
            szFile = szFile ? szFile + 1 : tLine.szFileName;
            int nPad = 0x18 - SStrLen(szSymbol);
            if (nPad < 1)
            {
                nPad = 1;
            }

// build: symbol ?gszSpace@* 0x006FFC44
            LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, "%*s %s, %d", nPad, gszSpace, szFile, tLine.dwLineNumber);
        }

// build: symbol ?gszNewline@* 0x006FFCB0
        LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, gszNewline);
    }

    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "%d frames dumped", nFrames);
    LOGMANAGER_CloseLogFiles();
    gpfnImageHlpSymCleanup(hProcess);
    CloseHandle(hProcess);
    return 1;
}

// 0x0040D1C0
void __fastcall EXCEPTIONS_AppendCrashDump(unsigned long dwHeader0, unsigned long dwHeader1, unsigned long dwType, int nCount, const void* pData)
{
    char szPath[0x104];
    D2CrashDumpRecordStrc tRecord;
    LOGMANAGER_GetLogDirectory(szPath, 0x104);
    SStrPack(szPath, "Crashdump", 0x104);
    _iobuf* pFile = fopen(szPath, "ab");
    if (pFile)
    {
        tRecord.dwHeader0 = dwHeader0;
        tRecord.dwHeader1 = dwHeader1;
        tRecord.dwType = dwType;
        tRecord.nCount = nCount;
        SMemCopy(tRecord.adwData, pData, nCount * 4);
        fwrite(&tRecord, nCount * 4 + 0x10, 1, pFile);
        fclose(pFile);
    }
}

// 0x0040D290
int __fastcall EXCEPTIONS_ReadCrashDump(char* pBuffer, unsigned int* pnSize)
{
    char szPath[0x104];
    unsigned long adwData[8];

    LOGMANAGER_GetLogDirectory(szPath, 0x104);
    SStrPack(szPath, "Crashdump", 0x104);
    if (GetFileAttributesA(szPath) == 0xFFFFFFFF)
    {
        return 0;
    }

    const unsigned int nMaxSize = *pnSize;
    _iobuf* pFile = fopen(szPath, gszReadBinary_006CDC90);
    if (!pFile)
    {
        return 0;
    }

    if (fseek(pFile, 0, 2))
    {
        fclose(pFile);
        return 0;
    }

    const long nFileSize = ftell(pFile);
    fseek(pFile, 0, 0);
    char* pData = (char*)FOG_Alloc(nFileSize, gszExceptionsCppFile, 0x75B, 0);
    fread(pData, 1, nFileSize, pFile);
    fclose(pFile);
    DeleteFileA(szPath);

    *pnSize = 1;
    int nEntries = 0;
    const unsigned long* pEnd = (const unsigned long*)(pData + nFileSize);
    const unsigned long* pRecord = (const unsigned long*)pData;
    if (pRecord < pEnd)
    {
        const char* pLimit = pBuffer + nMaxSize;
        do
        {
            const unsigned long dwHeader0 = *pRecord++;
            const unsigned long dwHeader1 = *pRecord++;
            const unsigned long dwType = *pRecord++;
            const int nCount = *pRecord++;
            const unsigned int nDataSize = nCount * 4;
            SMemCopy(adwData, pRecord, nDataSize);
            pRecord = (const unsigned long*)((const char*)pRecord + nDataSize);

            D2CrashDumpEntryStrc* pEntry = (D2CrashDumpEntryStrc*)(pBuffer + 1);
            int i;
            for (i = 0; i < nEntries; ++i)
            {
                if (pEntry->dwHeader0 == dwHeader0 && pEntry->dwHeader1 == dwHeader1 && pEntry->dwType == dwType
                    && pEntry->nCount == (unsigned char)nCount && !SMemCmp(pEntry->adwData, adwData, nDataSize))
                {
                    ++pEntry->nHits;
                    break;
                }
                pEntry = (D2CrashDumpEntryStrc*)((char*)pEntry + nDataSize + 0xF);
            }

            if (i == nEntries)
            {
                if ((char*)(pEntry + 1) >= pLimit)
                {
                    break;
                }

                pEntry->nHits = 1;
                pEntry->dwHeader0 = dwHeader0;
                pEntry->dwHeader1 = dwHeader1;
                pEntry->dwType = dwType;
                pEntry->nCount = (unsigned char)nCount;
                SMemCopy(pEntry->adwData, adwData, nDataSize);
                ++nEntries;
                *pnSize += nDataSize + 0xF;
            }
        }
        while (pRecord < pEnd);
    }

    *pBuffer = (char)nEntries;
    return 1;
}


// 0x0040D530
int __cdecl EXCEPTIONS_ReleaseAllSymbols()
{
    return EXCEPTIONS_ReleaseSymbols(1);
}

// 0x0040D540
void __cdecl EXCEPTIONS_SETranslator(unsigned int nCode, D2ExceptionPointersStrc* pExceptionInfo)
{
    if (!gbImageHlpLoaded)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "ExceptionHandler: imagehlp.dll not loaded");
        return;
    }
    void* hThread;
    DuplicateHandle(GetCurrentProcess(), GetCurrentThread(), GetCurrentProcess(), &hThread, 0, 0, 2);
    sShowStack(hThread, pExceptionInfo->pContextRecord);
    CloseHandle(hThread);
}

// 0x0040D5B0
int __cdecl EXCEPTIONS_LoadImageHlp()
{
    if (gbImageHlpLoaded)
    {
        return 1;
    }
    InitializeCriticalSection(&gtImageHlpLock);
    _set_se_translator(EXCEPTIONS_SETranslator);
    ghImageHlp = LoadLibraryA(".\\dbghelp.dll");
    if (!ghImageHlp)
    {
        ghImageHlp = LoadLibraryA("dbghelp.dll");
        if (!ghImageHlp)
        {
            ghImageHlp = LoadLibraryA("imagehlp.dll");
            if (!ghImageHlp)
            {
                LOGMANAGER_WriteLogLine("Missing imagehlp.dll.  Can't generate better stack crawls!");
                return 0;
            }
        }
    }
    gpfnImageHlpSymCleanup = (int (__stdcall*)(void*))GetProcAddress(ghImageHlp, "SymCleanup");
    gpfnSymFunctionTableAccess = GetProcAddress(ghImageHlp, "SymFunctionTableAccess");
    gpfnSymGetLineFromAddr = (int (__stdcall*)(void*, unsigned long, unsigned long*, D2ImageHlpLineStrc*))GetProcAddress(ghImageHlp, "SymGetLineFromAddr");
    gpfnSymGetModuleBase = GetProcAddress(ghImageHlp, "SymGetModuleBase");
    gpfnSymGetModuleInfo = (SymGetModuleInfoFn)GetProcAddress(ghImageHlp, "SymGetModuleInfo");
    gpfnImageHlpSymGetOptions = (unsigned long (__stdcall*)())GetProcAddress(ghImageHlp, "SymGetOptions");
    gpfnSymGetSymFromAddr = (SymGetSymFromAddrFn)GetProcAddress(ghImageHlp, "SymGetSymFromAddr");
    gpfnImageHlpSymInitialize = (int (__stdcall*)(void*, const char*, int))GetProcAddress(ghImageHlp, "SymInitialize");
    gpfnImageHlpSymSetOptions = (unsigned long (__stdcall*)(unsigned long))GetProcAddress(ghImageHlp, "SymSetOptions");
    gpfnSymLoadModule = (unsigned long (__stdcall*)(void*, void*, const char*, const char*, unsigned long, unsigned long))GetProcAddress(ghImageHlp, "SymLoadModule");
    gpfnSymUnloadModule = GetProcAddress(ghImageHlp, "SymUnloadModule");
    gpfnStackWalk = (StackWalkFn)GetProcAddress(ghImageHlp, "StackWalk");
    gpfnUnDecorateSymbolName = GetProcAddress(ghImageHlp, "UnDecorateSymbolName");
// build: symbol ?gszMiniDumpWriteDump@* 0x006FFB94
    gpfnImageHlpMiniDumpWriteDump = GetProcAddress(ghImageHlp, gszMiniDumpWriteDump);
    if (gpfnImageHlpSymCleanup && gpfnSymFunctionTableAccess && gpfnSymGetModuleBase
        && gpfnSymGetModuleInfo && gpfnImageHlpSymGetOptions && gpfnSymGetSymFromAddr
        && gpfnImageHlpSymInitialize && gpfnImageHlpSymSetOptions && gpfnStackWalk
        && gpfnUnDecorateSymbolName && gpfnSymLoadModule && gpfnSymUnloadModule)
    {
        gbImageHlpLoaded = 1;
        LOGMANAGER_WriteLogLine("imagehlp.dll loaded for better stack crawls.");
        return 1;
    }
    LOGMANAGER_WriteLogLine("Missing functions in imagehlp.dll.  Can't generate better stack crawls!");
    return 0;
}

// 0x0040D7D0
void __fastcall EXCEPTIONS_WalkCurrentStack(const char* szPrefix)
{
    void* hThread;
    {
        D2ThreadContextStrc tContext;
        unsigned long dwEip;
        unsigned long dwEsp;
        unsigned long dwEbp;

        memset(&tContext, 0, sizeof(tContext));
        tContext.ContextFlags = 0x10007;
        __asm
        {
            call next
        next:
            pop dwEip
            push esp
            pop dwEsp
            push ebp
            pop dwEbp
        }
        tContext.Eip = dwEip;
        tContext.Esp = dwEsp;
        tContext.Ebp = dwEbp;
        hThread = GetCurrentThread();
        QuickStackWalk(szPrefix, hThread, &tContext);
    }
}

#include "gen/data/Source/Fog/Src/Exceptions.inc"
