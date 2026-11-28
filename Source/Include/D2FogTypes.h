#pragma once
// Fog: the memory pool system, the thread context and stack frame records of the crash handler, its minidump
// request and the dbghelp records it fills, the service status it sets, the thread, process and loader records it walks
// for the module list, the toolhelp process and thread entries and startup info it uses, the crash report
// input, the debugger thread-name record, the service table entry and the run-mode table, and the imagehlp
// stack-walk, symbol and module records, the toolhelp module entry and the module list of the exception reporter.

#include "D2Check.h"
#include "D2SysTypes.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

struct D2ConfigStrc;
struct D2MemPoolBlockStrc;
struct D2MemPoolRecStrc;
struct D2PoolRecordStrc;
struct D2PoolSystemStrc;
struct D2PoolDirectoryStrc;
struct D2FloatSaveStrc;
struct D2ThreadContextStrc;
struct D2StackFrameStrc;
struct D2ModuleStrc;
struct D2ExceptionPointersStrc;

struct D2MemPoolBlockStrc
{
    void* pMemory; // 0x00
    unsigned int* pUsedBits; // 0x04
    int nUsed; // 0x08
    D2MemPoolBlockStrc* pPrev; // 0x0C
    D2MemPoolBlockStrc* pNext; // 0x10
    D2MemPoolRecStrc* pPool; // 0x14
};

struct D2MemPoolRecStrc
{
    D2CriticalSectionStrc tLock; // 0x00
    int nBlockSize; // 0x18
    int nBlocksPerChunk; // 0x1C
    int nChunkSize; // 0x20
    int nBlocks; // 0x24
    D2MemPoolBlockStrc* pFirstBlock; // 0x28
    D2MemPoolBlockStrc* pLastBlock; // 0x2C
};

struct D2PoolRecordStrc
{
    D2MemPoolBlockStrc* pBlock; // 0x00
    void* pMemory; // 0x04
};

struct D2PoolSystemStrc
{
    int bFreePoolAlloc; // 0x00
    D2CriticalSectionStrc tLock; // 0x04
    int nPools; // 0x1C
    D2MemPoolRecStrc aPools[40]; // 0x20
    int nPoolBlocks; // 0x7A0
    int nMaxPoolBlocks; // 0x7A4
    D2PoolRecordStrc* pRecords; // 0x7A8
    int* apLargeBlocks[1023]; // 0x7AC
    int nCount; // 0x17A8
    char szName[32]; // 0x17AC
};

struct D2PoolDirectoryStrc
{
    int bInit; // 0x00
    D2CriticalSectionStrc tLock; // 0x04
    D2PoolSystemStrc aSystems[8]; // 0x1C
    int nUsed; // 0xBE7C
    unsigned int anFreeIndex[8]; // 0xBE80
    int nFreeCount; // 0xBEA0
};

struct D2FloatSaveStrc
{
    unsigned long ControlWord; // 0x00
    unsigned long StatusWord; // 0x04
    unsigned long TagWord; // 0x08
    unsigned long ErrorOffset; // 0x0C
    unsigned long ErrorSelector; // 0x10
    unsigned long DataOffset; // 0x14
    unsigned long DataSelector; // 0x18
    unsigned char RegisterArea[80]; // 0x1C
    unsigned long Cr0NpxState; // 0x6C
};

struct D2ThreadContextStrc
{
    unsigned long ContextFlags; // 0x00
    unsigned long Dr0; // 0x04
    unsigned long Dr1; // 0x08
    unsigned long Dr2; // 0x0C
    unsigned long Dr3; // 0x10
    unsigned long Dr6; // 0x14
    unsigned long Dr7; // 0x18
    D2FloatSaveStrc FloatSave; // 0x1C
    unsigned long SegGs; // 0x8C
    unsigned long SegFs; // 0x90
    unsigned long SegEs; // 0x94
    unsigned long SegDs; // 0x98
    unsigned long Edi; // 0x9C
    unsigned long Esi; // 0xA0
    unsigned long Ebx; // 0xA4
    unsigned long Edx; // 0xA8
    unsigned long Ecx; // 0xAC
    unsigned long Eax; // 0xB0
    unsigned long Ebp; // 0xB4
    unsigned long Eip; // 0xB8
    unsigned long SegCs; // 0xBC
    unsigned long EFlags; // 0xC0
    unsigned long Esp; // 0xC4
    unsigned long SegSs; // 0xC8
    unsigned char ExtendedRegisters[512]; // 0xCC

    int CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames); // 0x00405060
};

struct D2StackFrameStrc
{
    unsigned long dwPc; // 0x00
    unsigned long dwFrame; // 0x04
    unsigned long dwStack; // 0x08
    unsigned long dwReturn; // 0x0C
    unsigned char bHasArgs; // 0x10
    void* apArgs[4]; // 0x14

    D2StackFrameStrc() : dwPc(0), dwFrame(0), dwStack(0), dwReturn(0), bHasArgs(0)
    {
        memset(apArgs, 0, sizeof(apArgs));
    }
};

struct D2ServiceStatusStrc
{
    unsigned long dwServiceType; // 0x00
    unsigned long dwCurrentState; // 0x04
    unsigned long dwControlsAccepted; // 0x08
    unsigned long dwWin32ExitCode; // 0x0C
    unsigned long dwServiceExitCode; // 0x10
    unsigned long dwCheckPoint; // 0x14
    unsigned long dwWaitHint; // 0x18
};


struct D2ProcessEntryWStrc
{
    unsigned long dwSize; // 0x00
    unsigned long cntUsage; // 0x04
    unsigned long th32ProcessID; // 0x08
    unsigned long th32DefaultHeapID; // 0x0C
    unsigned long th32ModuleID; // 0x10
    unsigned long cntThreads; // 0x14
    unsigned long th32ParentProcessID; // 0x18
    long pcPriClassBase; // 0x1C
    unsigned long dwFlags; // 0x20
    wchar_t szExeFile[260]; // 0x24
};

struct D2StartupInfoWStrc
{
    unsigned long cb; // 0x00
    wchar_t* lpReserved; // 0x04
    wchar_t* lpDesktop; // 0x08
    wchar_t* lpTitle; // 0x0C
    unsigned long dwX; // 0x10
    unsigned long dwY; // 0x14
    unsigned long dwXSize; // 0x18
    unsigned long dwYSize; // 0x1C
    unsigned long dwXCountChars; // 0x20
    unsigned long dwYCountChars; // 0x24
    unsigned long dwFillAttribute; // 0x28
    unsigned long dwFlags; // 0x2C
    unsigned short wShowWindow; // 0x30
    unsigned short cbReserved2; // 0x32
    unsigned char* lpReserved2; // 0x34
    void* hStdInput; // 0x38
    void* hStdOutput; // 0x3C
    void* hStdError; // 0x40
};

struct D2ThreadEntryStrc
{
    unsigned long dwSize; // 0x00
    unsigned long cntUsage; // 0x04
    unsigned long th32ThreadID; // 0x08
    unsigned long th32OwnerProcessID; // 0x0C
    long tpBasePri; // 0x10
    long tpDeltaPri; // 0x14
    unsigned long dwFlags; // 0x18
};

struct D2MiniDumpExceptionInfoStrc
{
    unsigned long dwThreadId; // 0x00
    void* pExceptionPointers; // 0x04
    int bClientPointers; // 0x08
};

struct D2MiniDumpUserStreamStrc
{
    unsigned long dwType; // 0x00
    unsigned long dwBufferSize; // 0x04
    void* pBuffer; // 0x08
};

struct D2MiniDumpUserStreamInfoStrc
{
    unsigned long dwUserStreamCount; // 0x00
    D2MiniDumpUserStreamStrc* pUserStreamArray; // 0x04
};

struct D2MiniDumpRequestInfoStrc
{
    void* pExceptionPointers; // 0x00
    unsigned long dwThreadId; // 0x04
    const char* szComment; // 0x08
};

struct D2MiniDumpRequestStrc
{
    void* hFile; // 0x00
    D2MiniDumpRequestInfoStrc tInfo; // 0x04
    bool bResult; // 0x10
};

struct D2ListEntryStrc
{
    D2ListEntryStrc* Flink; // 0x00
    D2ListEntryStrc* Blink; // 0x04
};

struct D2UnicodeStringStrc
{
    unsigned short Length; // 0x00
    unsigned short MaximumLength; // 0x02
    wchar_t* Buffer; // 0x04
};

struct D2LdrEntryStrc
{
    D2ListEntryStrc InLoadOrderLinks; // 0x00
    D2ListEntryStrc InMemoryOrderLinks; // 0x08
    D2ListEntryStrc InInitializationOrderLinks; // 0x10
    D2ModuleStrc* DllBase; // 0x18
    void* EntryPoint; // 0x1C
    unsigned long SizeOfImage; // 0x20
    D2UnicodeStringStrc FullDllName; // 0x24
};

struct D2LdrDataStrc
{
    unsigned char Reserved1[8]; // 0x00
    void* Reserved2[3]; // 0x08
    D2ListEntryStrc InMemoryOrderModuleList; // 0x14
};

struct D2PebStrc
{
    unsigned char Reserved1[2]; // 0x00
    unsigned char BeingDebugged; // 0x02
    unsigned char Reserved2[1]; // 0x03
    void* Reserved3[2]; // 0x04
    D2LdrDataStrc* Ldr; // 0x0C
};

struct D2TebStrc
{
    void* Reserved1[12]; // 0x00
    D2PebStrc* ProcessEnvironmentBlock; // 0x30
};

struct D2ThreadNameInfoStrc
{
    unsigned long dwType; // 0x00
    const char* szName; // 0x04
    unsigned long dwThreadID; // 0x08
    unsigned long dwFlags; // 0x0C
};

struct D2ModeIfaceStrc
{
    int (__fastcall* pfnRun)(D2ConfigStrc* pCfg); // 0x00
};

struct D2ModeEntryStrc
{
    D2ModeIfaceStrc* (__fastcall* pfnCreate)(void* pContext); // 0x00
    void (__cdecl* pfnRelease)(); // 0x04
};

struct D2ServiceTableEntryStrc
{
    char* szServiceName; // 0x00
    void (__stdcall* pfnServiceProc)(unsigned long dwArgc, char** argv); // 0x04
};

struct D2SidAuthorityStrc
{
    unsigned char Value[6]; // 0x00
};

struct D2ProcessEntryStrc
{
    unsigned long dwSize; // 0x00
    unsigned long cntUsage; // 0x04
    unsigned long th32ProcessID; // 0x08
    unsigned long th32DefaultHeapID; // 0x0C
    unsigned long th32ModuleID; // 0x10
    unsigned long cntThreads; // 0x14
    unsigned long th32ParentProcessID; // 0x18
    long pcPriClassBase; // 0x1C
    unsigned long dwFlags; // 0x20
    char szExeFile[260]; // 0x24
};

struct D2CrashInputStrc
{
    const char* szSummary; // 0x00
    const char* szDetail; // 0x04
    D2StackFrameStrc* pFrames; // 0x08
    int nFrames; // 0x0C
    int nSkip; // 0x10
    unsigned long dwThreadId; // 0x14
    D2ExceptionPointersStrc* pException; // 0x18
};

D2_CHECK_SIZE(D2MemPoolBlockStrc, 0x18);
D2_CHECK_SIZE(D2MemPoolRecStrc, 0x30);
D2_CHECK_SIZE(D2PoolRecordStrc, 0x8);
D2_CHECK_SIZE(D2PoolSystemStrc, 0x17CC);
D2_CHECK_SIZE(D2PoolDirectoryStrc, 0xBEA4);
D2_CHECK_SIZE(D2FloatSaveStrc, 0x70);
D2_CHECK_SIZE(D2ThreadContextStrc, 0x2CC);
D2_CHECK_SIZE(D2StackFrameStrc, 0x24);
D2_CHECK_SIZE(D2ServiceStatusStrc, 0x1C);
D2_CHECK_SIZE(D2ListEntryStrc, 0x8);
D2_CHECK_SIZE(D2UnicodeStringStrc, 0x8);
D2_CHECK_SIZE(D2LdrEntryStrc, 0x2C);
D2_CHECK_SIZE(D2LdrDataStrc, 0x1C);
D2_CHECK_SIZE(D2PebStrc, 0x10);
D2_CHECK_SIZE(D2TebStrc, 0x34);
D2_CHECK_SIZE(D2ProcessEntryWStrc, 0x22C);
D2_CHECK_SIZE(D2StartupInfoWStrc, 0x44);
D2_CHECK_SIZE(D2ThreadEntryStrc, 0x1C);
D2_CHECK_SIZE(D2MiniDumpExceptionInfoStrc, 0xC);
D2_CHECK_SIZE(D2MiniDumpUserStreamStrc, 0xC);
D2_CHECK_SIZE(D2MiniDumpUserStreamInfoStrc, 0x8);
D2_CHECK_SIZE(D2MiniDumpRequestInfoStrc, 0xC);
D2_CHECK_SIZE(D2MiniDumpRequestStrc, 0x14);
D2_CHECK_SIZE(D2ThreadNameInfoStrc, 0x10);
D2_CHECK_SIZE(D2ModeIfaceStrc, 0x4);
D2_CHECK_SIZE(D2ModeEntryStrc, 0x8);
D2_CHECK_SIZE(D2ServiceTableEntryStrc, 0x8);
D2_CHECK_SIZE(D2SidAuthorityStrc, 0x6);
D2_CHECK_SIZE(D2ProcessEntryStrc, 0x128);
D2_CHECK_SIZE(D2CrashInputStrc, 0x1C);

struct D2ImageHlpAddressStrc
{
    unsigned long dwOffset;
    unsigned short wSegment;
    int nMode;
};

struct D2ImageHlpStackFrameStrc
{
    D2ImageHlpAddressStrc tAddrPC;
    D2ImageHlpAddressStrc tAddrReturn;
    D2ImageHlpAddressStrc tAddrFrame;
    D2ImageHlpAddressStrc tAddrStack;
    void* pFuncTableEntry;
    unsigned long dwParams[4];
    int bFar;
    int bVirtual;
    unsigned long dwReserved[3];
    unsigned long dwKdHelp[19];
};

struct D2ImageHlpSymbolStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwAddress;
    unsigned long dwSize;
    unsigned long dwFlags;
    unsigned long dwMaxNameLength;
    char szName[1];
};

struct D2ImageHlpModuleStrc
{
    unsigned long dwSizeOfStruct;
    unsigned long dwBaseOfImage;
    unsigned long dwImageSize;
    unsigned long dwTimeDateStamp;
    unsigned long dwCheckSum;
    unsigned long dwNumSyms;
    int nSymType;
    char szModuleName[32];
    char szImageName[256];
    char szLoadedImageName[256];
};

struct D2ToolhelpModuleEntryStrc
{
    unsigned long dwSize;
    unsigned long th32ModuleID;
    unsigned long th32ProcessID;
    unsigned long GlblcntUsage;
    unsigned long ProccntUsage;
    unsigned int modBaseAddr;
    unsigned int modBaseSize;
    void* hModule;
    char szModule[0x100];
    char szExePath[0x104];
};

struct D2ImageHlpSymbolBufferStrc
{
    D2ImageHlpSymbolStrc tSymbol;
    char szNameBuffer[0x100];
};

struct D2FpoDataStrc
{
    unsigned long dwOffStart;
    unsigned long dwProcSize;
    unsigned long dwLocals;
    unsigned short wParams;
    unsigned short cbProlog : 8;
    unsigned short cbRegs : 3;
    unsigned short fHasSEH : 1;
    unsigned short fUseBP : 1;
    unsigned short reserved : 1;
    unsigned short cbFrame : 2;
};

struct D2ModuleInfoStrc
{
    char szPath[0x104];
    char szName[0x100];
    unsigned long dwBase;
    unsigned long dwSize;
    D2ModuleInfoStrc* pNext;
};

#pragma pack(push, 1)
struct D2CrashDumpEntryStrc
{
    unsigned short nHits;
    unsigned long dwHeader0;
    unsigned long dwHeader1;
    unsigned long dwType;
    unsigned char nCount;
    unsigned long adwData[8];
};
#pragma pack(pop)
