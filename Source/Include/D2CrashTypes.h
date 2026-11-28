#pragma once
// Crash handler (Fog, Storm): the dbghelp records and lock, the module list of a crash report and memory region info.

#include "D2Check.h"
#include "CCritSect.h"

struct D2CrashGuidStrc;
struct D2CrashModuleStrc;
struct D2CrashModuleListStrc;
struct D2CvRsdsStrc;
struct D2MemoryBasicInfoStrc;
struct D2ImagehlpModule64Strc;
struct D2ImagehlpLine64Strc;
struct D2ImagehlpSymbol64Strc;
struct D2SymbolBufferStrc;
struct D2SymbolInfoStrc;
struct D2SymbolLockGuardStrc;
struct D2CriticalSectionStrc;

// The lock that serialises every dbghelp call.
// build: symbol ?gtSymbolLock@* 0x0098A6F0
extern D2CriticalSectionStrc gtSymbolLock;

struct D2CrashGuidStrc
{
    unsigned long Data1; // 0x00
    unsigned short Data2; // 0x04
    unsigned short Data3; // 0x06
    unsigned char Data4[8]; // 0x08
};

struct D2CrashModuleStrc
{
    void* pBase; // 0x00
    unsigned long nSize; // 0x04
    char szName[0x100]; // 0x08
    char szPath[0x100]; // 0x108
    unsigned long nTimeStamp; // 0x208
    D2CrashGuidStrc tGuid; // 0x20C
    unsigned long nAge; // 0x21C
    unsigned long nTimeDateStamp; // 0x220
    unsigned long nVersion; // 0x224
};

struct D2CrashModuleListStrc
{
    unsigned int nCount; // 0x00
    D2CrashModuleStrc aModules[0x100]; // 0x04
};

struct D2CvRsdsStrc
{
    unsigned long dwCvSignature; // 0x00
    D2CrashGuidStrc tGuid; // 0x04
    unsigned long dwAge; // 0x14
    char szPdbName[4]; // 0x18
};

#ifndef D2_MEMORY_BASIC_INFO_STRC
#define D2_MEMORY_BASIC_INFO_STRC
struct D2MemoryBasicInfoStrc
{
    void* BaseAddress; // 0x00
    void* AllocationBase; // 0x04
    unsigned long AllocationProtect; // 0x08
    unsigned long RegionSize; // 0x0C
    unsigned long State; // 0x10
    unsigned long Protect; // 0x14
    unsigned long Type; // 0x18
};
#endif

struct D2ImagehlpModule64Strc
{
    unsigned long SizeOfStruct; // 0x00
    unsigned long unk_004; // 0x04
    unsigned __int64 BaseOfImage; // 0x08
    unsigned long ImageSize; // 0x10
    unsigned long TimeDateStamp; // 0x14
    unsigned long CheckSum; // 0x18
    unsigned long NumSyms; // 0x1C
    unsigned long SymType; // 0x20
    char ModuleName[32]; // 0x24
    char ImageName[256]; // 0x44
    char LoadedImageName[256]; // 0x144
    char unk_244[0x680 - 0x244]; // 0x244
};

struct D2ImagehlpLine64Strc
{
    unsigned long SizeOfStruct; // 0x00
    void* Key; // 0x04
    unsigned long LineNumber; // 0x08
    char* FileName; // 0x0C
    unsigned __int64 Address; // 0x10
};

struct D2ImagehlpSymbol64Strc
{
    unsigned long SizeOfStruct; // 0x00
    unsigned long unk_04; // 0x04
    unsigned __int64 Address; // 0x08
    unsigned long Size; // 0x10
    unsigned long Flags; // 0x14
    unsigned long MaxNameLength; // 0x18
    char Name[1]; // 0x1C
};

struct D2SymbolBufferStrc
{
    D2ImagehlpSymbol64Strc tSymbol; // 0x00
    char szName[0x420 - 0x20]; // 0x20
};

struct D2SymbolInfoStrc
{
    char szName[512]; // 0x00
    unsigned long nOffset; // 0x200
    char szModule[64]; // 0x204
    char szSource[256]; // 0x244
    unsigned long nLine; // 0x344
};

// Holds the dbghelp lock for its scope.
struct D2SymbolLockGuardStrc
{
    D2SymbolLockGuardStrc() { EnterCriticalSection(&gtSymbolLock); }
    explicit D2SymbolLockGuardStrc(D2CriticalSectionStrc* pLock) { EnterCriticalSection(pLock); }
    ~D2SymbolLockGuardStrc() { LeaveCriticalSection(&gtSymbolLock); }
};

D2_CHECK_SIZE(D2CrashGuidStrc, 0x10);
D2_CHECK_SIZE(D2CrashModuleStrc, 0x228);
D2_CHECK_SIZE(D2CrashModuleListStrc, 0x22804);
D2_CHECK_SIZE(D2CvRsdsStrc, 0x1C);
D2_CHECK_SIZE(D2MemoryBasicInfoStrc, 0x1C);
D2_CHECK_SIZE(D2ImagehlpModule64Strc, 0x680);
D2_CHECK_SIZE(D2ImagehlpLine64Strc, 0x18);
D2_CHECK_SIZE(D2ImagehlpSymbol64Strc, 0x20);
D2_CHECK_SIZE(D2SymbolBufferStrc, 0x420);
D2_CHECK_SIZE(D2SymbolInfoStrc, 0x348);
