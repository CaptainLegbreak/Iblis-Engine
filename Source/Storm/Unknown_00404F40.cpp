#include "Storm.h"
#include "D2MultiTypes.h"
#include "D2LanguageNames.h"

#include "D2CrashTypes.h"
#include "D2FogTypes.h"
#include "D2CmdArg.h"
#define CMD_BOOLEAN 0
#define CMD_INTEGER 1
#define CMD_STRING 2
struct D2ConfigStrc;
struct D2ImageDataDirStrc;
struct D2ImageOptionalHeader64Strc;
struct D2StackFrameStrc;
struct D2IniEntryStrc;
struct Character;
struct D2CmdArgStrc;

static void __stdcall sub_00404F60_GetDebugDirectory32(unsigned long* pSize, unsigned long* pRva, const D2ImageOptionalHeaderStrc* pHeader);

extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void* pAddress, D2MemoryBasicInfoStrc* pBuffer, unsigned long nLength); // 0x006CC244
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650
void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags); // 0x00413020
extern "C" const char gszNew[]; // 0x006CC82C
int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

struct D2IniEntryStrc
{
    char szSection[0x1B];
    char szKey[0x36];
    unsigned char nType;
    char pad0x52[2];
    int nOffset;
    int nDefault;
};

extern D2IniEntryStrc gaIniEntries_00705040[58]; // 0x00705040
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(dllimport) unsigned int __stdcall GetPrivateProfileIntA(const char* szAppName, const char* szKeyName, int nDefault, const char* szFileName); // 0x006CC150
extern "C" __declspec(dllimport) unsigned long __stdcall GetPrivateProfileStringA(const char* szAppName, const char* szKeyName, const char* szDefault, char* szReturned, unsigned long nSize, const char* szFileName); // 0x006CC420

struct Character { signed char value; };

enum { UPPER_FIRST = 65, UPPER_LAST = 90, CASE_DELTA = 32 };

extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


extern D2CmdArgStrc gaCmdArguments[58]; // 0x00705040
void __stdcall sub_00405450_LoadIniSettings(char* pSettings); // 0x00405450
void __cdecl IGNORELIST_CreateIgnoreList(); // 0x006114E0
int __fastcall sub_00405710_ParseCmdArgument(char* szCommandNameTestBuf, const char* pszCommand, char* szCommandValueBuf); // 0x00405710

void __cdecl operator delete(void* pMemory);
void* __cdecl operator new(size_t nSize);

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

// build: symbol ??3@YAXPAX@Z 0x004053F0
void __cdecl operator delete(void* pMemory)
{
    if (pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
}

// build: symbol ??2@YAPAXI@Z 0x00405410
void* __cdecl operator new(size_t nSize)
{
    return SMemAlloc(nSize, gszNew, -1, 0);
}

// 0x00405430
static inline void sub_00405430_GetIniPath(char* szPath)
{
    ERRORMANAGER_GetModuleDirectory(szPath, 0x104);
    SStrPack(szPath, "D2.ini", 0x104);
}

void __stdcall sub_M114_Emit_00405430(char* szPath)
{
    sub_00405430_GetIniPath(szPath);
}

// 0x00405450
void __stdcall sub_00405450_LoadIniSettings(char* pSettings)
{
    char szIni[0x104];
    ERRORMANAGER_GetModuleDirectory(szIni, 0x104);
    SStrPack(szIni, "D2.ini", 0x104);
    for (int i = 0; i < sizeof(gaIniEntries_00705040) / sizeof(gaIniEntries_00705040[0]); i++)
    {
        char* pDest = pSettings + gaIniEntries_00705040[i].nOffset;
        switch (gaIniEntries_00705040[i].nType)
        {
        case 0:
            *pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni) != 0;
            break;
        case 1:
            *(int*)pDest = GetPrivateProfileIntA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, gaIniEntries_00705040[i].nDefault, szIni);
            break;
        case 2:
            GetPrivateProfileStringA(gaIniEntries_00705040[i].szSection, gaIniEntries_00705040[i].szKey, &gszEmptyAssertText, pDest, 0x1B, szIni);
            break;
        }
    }
}

extern D2IniEntryStrc gaIniEntries_00705040[58] = {
    { "DEBUG", {
    67, 82, 65, 83, 72, 65, 80, 80, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 114, 97, 115, 104
}, 0, { 0 }, 4 },
    { "VIDEO", {
    87, 73, 78, 68, 79, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 119
}, 0, { 0 }, 8 },
    { "VIDEO", {
    87, 73, 78, 68, 79, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 119, 105, 110, 100, 111,
    119
}, 0, { 0 }, 8 },
    { "VIDEO", {
    87, 73, 78, 68, 79, 87, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 119, 105, 110, 100, 111,
    119, 101, 100
}, 0, { 0 }, 8 },
    { "VIDEO", {
    65, 83, 80, 69, 67, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 111, 102, 105, 120,
    97, 115, 112, 101, 99, 116
}, 0, { 0 }, 9 },
    { "VIDEO", {
    51, 68, 70, 88, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 51, 100, 102, 120
}, 0, { 0 }, 10 },
    { "VIDEO", {
    79, 80, 69, 78, 71, 76, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111, 112, 101, 110, 103,
    108
}, 0, { 0 }, 11 },
    { "VIDEO", {
    68, 51, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 51, 100
}, 0, { 0 }, 13 },
    { "VIDEO", {
    82, 65, 86, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 114, 97, 118, 101
}, 0, { 0 }, 12 },
    { "VIDEO", {
    80, 69, 82, 83, 80, 69, 67, 84, 73, 86, 69, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 101, 114
}, 0, { 0 }, 14 },
    { "VIDEO", {
    81, 85, 65, 76, 73, 84, 89, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 113
}, 0, { 0 }, 15 },
    { "VIDEO", {
    71, 65, 77, 77, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 103, 97, 109, 109, 97
}, 1, { 0 }, 16 },
    { "VIDEO", {
    86, 83, 89, 78, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 118, 115, 121, 110, 99
}, 0, { 0 }, 20 },
    { "VIDEO", {
    70, 82, 65, 77, 69, 82, 65, 84, 69, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 102, 114
}, 1, { 0 }, 21 },
    { "NETWORK", {
    83, 69, 82, 86, 69, 82, 73, 80, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115
}, 2, { 0 }, 55 },
    { "NETWORK", {
    71, 65, 77, 69, 84, 89, 80, 69, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 103, 97, 109, 101, 116,
    121, 112, 101
}, 1, { 0 }, 25 },
    { "NETWORK", {
    65, 82, 69, 78, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97, 114, 101, 110, 97
}, 1, { 0 }, 519 },
    { "NETWORK", {
    74, 79, 73, 78, 73, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 106, 111, 105, 110, 105,
    100
}, 1, { 0 }, 29 },
    { "NETWORK", {
    71, 65, 77, 69, 78, 65, 77, 69, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 103, 97, 109, 101, 110,
    97, 109, 101
}, 2, { 0 }, 31 },
    { "NETWORK", {
    66, 65, 84, 84, 76, 69, 78, 69, 84, 73, 80, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 110
}, 2, { 0 }, 79 },
    { "NETWORK", {
    77, 67, 80, 73, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 99, 112, 105, 112
}, 2, { 0 }, 103 },
    { "CHARACTER", {
    65, 77, 65, 90, 79, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97, 109, 97
}, 0, { 0 }, 133, 1 },
    { "CHARACTER", {
    80, 65, 76, 65, 68, 73, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 112, 97, 108
}, 0, { 0 }, 134 },
    { "CHARACTER", {
    83, 79, 82, 67, 69, 82, 69, 83, 83, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 111, 114
}, 0, { 0 }, 135 },
    { "CHARACTER", {
    78, 69, 67, 82, 79, 77, 65, 78, 67, 69, 82, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 101, 99
}, 0, { 0 }, 136 },
    { "CHARACTER", {
    66, 65, 82, 66, 65, 82, 73, 65, 78, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 97, 114
}, 0, { 0 }, 137 },
    { "CHARACTER", {
    73, 78, 86, 73, 78, 67, 73, 66, 76, 69, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 105
}, 0, { 0 }, 140 },
    { "CHARACTER", {
    78, 65, 77, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 97, 109, 101
}, 2, { 0 }, 189 },
    { "CHARACTER", {
    82, 69, 65, 76, 77, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 114, 101, 97, 108, 109
}, 2, { 0 }, 213 },
    { "CHARACTER", {
    67, 84, 69, 77, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 116, 101, 109, 112
}, 1, { 0 }, 493 },
    { "MONSTER", {
    78, 79, 77, 79, 78, 83, 84, 69, 82, 83, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 109
}, 0, { 0 }, 497 },
    { "MONSTER", {
    77, 79, 78, 83, 84, 69, 82, 67, 76, 65, 83, 83, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109
}, 1, { 0 }, 498 },
    { "MONSTER", {
    77, 79, 78, 83, 84, 69, 82, 73, 78, 70, 79, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 105, 110, 102, 111
}, 0, { 0 }, 502 },
    { "MONSTER", {
    77, 79, 78, 83, 84, 69, 82, 68, 69, 66, 85, 71, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 100
}, 1, { 0 }, 503 },
    { "ITEM", {
    82, 65, 82, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 114, 97, 114, 101
}, 0, { 0 }, 507 },
    { "ITEM", {
    85, 78, 73, 81, 85, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 117, 110, 105, 113, 117,
    101
}, 0, { 0 }, 508 },
    { "INTERFACE", {
    65, 67, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 97, 99, 116
}, 1, { 0 }, 511, 1 },
    { "DEBUG", {
    76, 79, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 111, 103
}, 0, { 0 }, 534 },
    { "DEBUG", {
    77, 83, 71, 76, 79, 71, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 109, 115, 103, 108, 111,
    103
}, 0, { 0 }, 535 },
    { "DEBUG", {
    83, 65, 70, 69, 77, 79, 68, 69, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 97, 102, 101
}, 0, { 0 }, 536 },
    { "DEBUG", {
    78, 79, 83, 65, 86, 69, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 111, 115, 97, 118,
    101
}, 0, { 0 }, 537 },
    { "DEBUG", {
    83, 69, 69, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 101, 101, 100
}, 1, { 0 }, 538 },
    { "NETWORK", {
    78, 79, 80, 75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 111, 112, 107
}, 0, { 0 }, 131 },
    { "DEBUG", {
    67, 72, 69, 65, 84, 83, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 104, 101, 97, 116,
    115
}, 0, { 0 }, 542 },
    { "DEBUG", {
    84, 69, 69, 78, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116, 101, 101, 110
}, 0, { 0 }, 543 },
    { "DEBUG", {
    78, 79, 83, 79, 85, 78, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 115
}, 0, { 0 }, 544 },
    { "FILEIO", {
    78, 79, 80, 82, 69, 68, 76, 79, 65, 68, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 112, 108
}, 0, { 0 }, 515 },
    { "FILEIO", {
    68, 73, 82, 69, 67, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 100, 105, 114, 101, 99,
    116
}, 0, { 0 }, 516 },
    { "FILEIO", {
    76, 79, 87, 69, 78, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 108, 101, 109
}, 0, { 0 }, 517 },
    { "DEBUG", {
    81, 117, 69, 115, 84, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 113, 117, 101, 115, 116,
    97, 108, 108
}, 0, { 0 }, 545 },
    { "NETWORK", {
    67, 79, 77, 73, 78, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 99, 111, 109, 105, 110,
    116
}, 1, { 0 }, 549 },
    { "NETWORK", {
    83, 75, 73, 80, 84, 79, 66, 78, 69, 84, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 107, 105, 112, 116,
    111, 98, 110, 101, 116
}, 0, { 0 }, 861 },
    { "NETWORK", {
    79, 80, 69, 78, 67, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 111, 112, 101, 110, 99
}, 0, { 0 }, 132 },
    { "FILEIO", {
    78, 79, 67, 79, 77, 80, 82, 69, 83, 83, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 111, 99, 111, 109,
    112, 114, 101, 115, 115
}, 0, { 0 }, 518 },
    { "TXT", {
    84, 88, 84, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 116, 120, 116
}, 0, { 0 }, 533 },
    { "BUILD", {
    66, 85, 73, 76, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 98, 117, 105, 108, 100
}, 0, { 0 }, 547 },
    { "DEBUG", {
    78, 79, 83, 79, 85, 78, 68, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 110, 111, 115, 111, 117,
    110, 100
}, 0, { 0 }, 544 },
    { "DEBUG", {
    83, 79, 85, 78, 68, 66, 75, 71, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 115, 110, 100, 98, 107,
    103
}, 0, { 0 }, 548 }
}; // 0x00705040

// 0x00405550
void __fastcall sub_00405550(Character* text)
{
    while(text->value) {
        if(text->value>=UPPER_FIRST && text->value<=UPPER_LAST)
            text->value+=CASE_DELTA;
        ++text;
    }
}

// build: symbol ?ERRORMANAGER_IsCmdSeparator@* 0x004055D0
static int ERRORMANAGER_IsCmdSeparator(char c)
{
    const char aSeparators[4] = { ' ', '\t', '\n', ':' };
    for (int i = 0; i < 4; i++)
    {
        if (aSeparators[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

static void __fastcall sub_00405550_stoLower_Inl(char* s)
{
    while (*s)
    {
        if (*s >= 'A' && *s <= 'Z')
        {
            *s += 'a' - 'A';
        }
        s++;
    }
}

// 0x00405610
static void ParseCmdValue(char* s)
{
    char szBuf[0x100];
    strcpy(szBuf, s);
    const int nLen = strlen(s);
    int i = 0;
    for (; i < nLen; i++)
    {
        if (!ERRORMANAGER_IsCmdSeparator(s[i]))
        {
            break;
        }
    }
    int nOut = 0;
    for (; i < nLen; i++)
    {
        if (ERRORMANAGER_IsCmdSeparator(szBuf[i]))
        {
            break;
        }
        s[nOut++] = szBuf[i];
    }
    s[nOut] = 0;
}

int __fastcall sub_00405710_ParseCmdArgument(char* szCommandNameTestBuf, const char* pszCommand, char* szCommandValueBuf)
{
    char szCommand[0x100];
    const int nRemainingLen = strlen(pszCommand);
    int nCommandIndex = -1;
    int i = 0;
    D2_ASSERT(nRemainingLen < 0x100, 259);
    while (i < nRemainingLen && pszCommand[i] != '-' && pszCommand[i] != '\0')
    {
        szCommand[i] = pszCommand[i];
        i++;
    }
    szCommand[i] = '\0';
    szCommand[i + 1] = '\0';
    strcpy(szCommandNameTestBuf, szCommand);
    const int nCommandLength = strlen(szCommandNameTestBuf);
    int bContinue = 1;
    sub_00405550_stoLower_Inl(szCommandNameTestBuf);
    for (int n = nCommandLength; n != 0 && bContinue; n--)
    {
        szCommandNameTestBuf[n] = '\0';
        nCommandIndex = GetCmdIndex(szCommandNameTestBuf);
        if (nCommandIndex != -1)
        {
            bContinue = 0;
        }
    }
    const int nCommandValueOffset = strlen(szCommandNameTestBuf);
    int nValueIdx = 0;
    for (; szCommand[nValueIdx]; nValueIdx++)
    {
        szCommandValueBuf[nValueIdx] = szCommand[nCommandValueOffset + nValueIdx];
    }
    szCommandValueBuf[nValueIdx] = '\0';
    ParseCmdValue(szCommandValueBuf);
    return nCommandIndex;
}

// 0x004058A0
static void __stdcall sub_004058A0_ParseCmdArgs(D2ConfigStrc* pCfg, const char* argv)
{
    char szCommandNameTestBuf[0x100];
    char szCommandValueBuf[0x100];

    const int nArgvLength = strlen(argv);
    for (int nCharIndex = 0; nCharIndex < nArgvLength; nCharIndex++)
    {
        if (argv[nCharIndex] != '-')
        {
            continue;
        }
        nCharIndex++;

        if (nCharIndex < nArgvLength)
        {
            const int nCommandIndex = sub_00405710_ParseCmdArgument(szCommandNameTestBuf, &argv[nCharIndex], szCommandValueBuf);
            if (nCommandIndex != -1)
            {
                void* pCfgMember = (char*)pCfg + gaCmdArguments[nCommandIndex].nIndex;

                switch (gaCmdArguments[nCommandIndex].nType)
                {
                case CMD_INTEGER:
                    *(int*)pCfgMember = atoi(szCommandValueBuf);
                    break;
                case CMD_STRING:
                    strcpy((char*)pCfgMember, szCommandValueBuf);
                    break;
                case CMD_BOOLEAN:
                    *(unsigned char*)pCfgMember = 1;
                    break;
                }
            }
        }
    }
}

// 0x004059A0
void __fastcall ParseCmdLine(D2ConfigStrc* pCfg, const char* argv)
{
    memset(pCfg, 0, 0x3CD);
    sub_00405450_LoadIniSettings((char*)pCfg);
    IGNORELIST_CreateIgnoreList();
    sub_004058A0_ParseCmdArgs(pCfg, argv);
}

// 0x0063A800
void __cdecl ITEMS_Nop()
{
}

// 0x004DF920
void __cdecl sub_004DF920_Nop()
{
}

// 0x004DF930
void __cdecl sub_004DF930_Nop()
{
}

// 0x00587830
void __cdecl OBJECTS_InitFunction70_Unused()
{
}
