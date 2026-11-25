#pragma once

#include "D2Win32Base.h"

struct D2MemoryBasicInfoStrc;
struct D2ModuleInfoStrc;
struct D2PoolSystemStrc;
struct D2QClientStrc;
struct D2SockAddrInStrc;
struct D2SystemTimeStrc;
struct D2ThreadContextStrc;
struct D2QueueServerStrc;
struct _iobuf;

D2ModuleInfoStrc* __stdcall sub_0040B920_GetModuleListPsapi(void* hProcess); // 0x0040B920
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" __declspec(dllimport) int __stdcall DuplicateHandle(void* hSourceProcess, void* hSource, void* hTargetProcess, void** phTarget, unsigned long dwAccess, int bInherit, unsigned long dwOptions); // 0x006CC248
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall GetThreadContext(void* hThread, D2ThreadContextStrc* pContext); // 0x006CC234
extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C
extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentDirectoryA(unsigned long nSize, char* szBuffer); // 0x006CC240
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId(); // 0x006CC1EC
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(); // 0x006CC20C
extern "C" __declspec(dllimport) unsigned long __stdcall GetEnvironmentVariableA(const char* szName, char* szBuffer, unsigned long nSize); // 0x006CC23C
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
extern "C" __declspec(dllimport) unsigned long __stdcall VirtualQuery(const void* pAddress, D2MemoryBasicInfoStrc* pBuffer, unsigned long nLength); // 0x006CC244
extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread(); // 0x006CC24C
extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A
extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990
extern "C" const char gszExceptionsCppFile_006CD628[]; // 0x006CD628
extern "C" const char gszMiniDumpWriteDump[]; // 0x006FFB94
extern "C" const char gszNewline[]; // 0x006FFCB0
extern "C" const char gszQServerCppFile[]; // 0x006FC460
extern "C" const char gszQServerNTFile[]; // 0x006FC8A0
extern "C" const char gszSpace[]; // 0x006FFC44
extern "C" const char gszStringFormat[]; // 0x006FFC58
extern "C" const char gszUnknown[]; // 0x006CD5FC
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" const unsigned char gaASTOperatorPrecedence[]; // 0x006FC874
extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9
extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC
extern "C" int __cdecl fprintf(_iobuf* pFile, const char* szFormat, ...); // 0x00684C94
extern "C" int __cdecl fseek(_iobuf* pFile, long nOffset, int nOrigin); // 0x00684A2A
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __stdcall connect(unsigned int nSocket, const D2SockAddrInStrc* pName, int nNameLength); // 0x006B014A
extern "C" int __stdcall getsockname(unsigned int nSocket, D2SockAddrInStrc* pName, int* pnNameLength); // 0x006B0144
extern "C" long __cdecl ftell(_iobuf* pFile); // 0x00684935
extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile); // 0x00684449
extern "C" unsigned int __stdcall accept(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen); // 0x006C9B6A
extern "C" unsigned long __stdcall inet_addr(const char* szAddress); // 0x006B0150
extern "C" void __cdecl free(void* pMemory); // 0x00683FC0
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
extern "C" void* __stdcall CreateToolhelp32Snapshot(unsigned long dwFlags, unsigned long dwProcessId); // 0x006B1446
extern _iobuf* gapLogFiles[20]; // 0x0075E790
extern char gaszLogNames[20][0x10]; // 0x0075D148
extern char gszLogPrefix[]; // 0x00708018
extern const char gszQServerNT_006FC8A0[]; // 0x006FC8A0
extern const char gszServerFile_006FC460[]; // 0x006FC460
extern const char* gaszErrorTypeNames[]; // 0x00706654
extern int gbLogThreadStop; // 0x0075E830
extern int gbWritingCrashReport; // 0x0074F0C8
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern unsigned long gadwLogWriteTick[20]; // 0x0075D2F0
extern void* ghDbgHelpDoneEvent; // 0x0098A6BC
extern void* ghDbgHelpWorkEvent; // 0x0098A6C0
int __fastcall FOG_SOCKET_WSACleanup(); // 0x0040D8D0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned int nBufferSize); // 0x00414E50
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars); // 0x00413590
int __stdcall sub_006B0144_GetSockAddr(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen); // 0x006B0144
int __stdcall sub_006B018C_GetSockAddr(unsigned int s, D2SockAddrInStrc* pAddr, int* pAddrLen); // 0x006B018C
unsigned int __cdecl sub_00410A80_GetTime(); // 0x00410A80
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
unsigned short __stdcall sub_006B019E(unsigned short nValue); // 0x006B019E
void __cdecl ERRORMANAGER_LogPoolError(const char* szFormat, ...); // 0x00409020
void __cdecl FOG_CreateNewPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize); // 0x00409DD0
void __cdecl LOGMANAGER_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410740
void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
bool __fastcall ERRORMANAGER_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag); // 0x00408660
void __fastcall sub_00409810_FreeLarge(D2PoolSystemStrc* pSystem, void* pMemory, const char* szFile, int nLine); // 0x00409810
void __fastcall QSERVER_ProcessReceived(D2QueueServerStrc* pServer, D2QClientStrc* pClient); // 0x006C08A0
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
void* __fastcall sub_004098B0_ReallocLarge(D2PoolSystemStrc* pSystem, void* pMemory, int nSize, const char* szFile, int nLine); // 0x004098B0

#define QS_IS_READ(f) (((f) & 1) == 1)
#define QS_IS_WRITE(f) (((f) & 3) == 2)
// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define S_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText_006CC837, sub_00408090(), line); exit(-1); }
#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

// the default of a switch whose every value is a listed case: the compiler is told it cannot be reached
#define DEFAULT_UNREACHABLE __assume(0)
// build: symbol ?gtPoolManager@* 0x0074F0E8
#define gtDefaultPoolSystem_0074F104 (gtPoolManager.aSystems[0])
#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

typedef char* va_list;

typedef unsigned int size_t;

struct AsyncDataLoadFileCallback
{
    unsigned long (__stdcall* callback)(void* pFileData, size_t nDataLength, AsyncDataLoadFileCallback* pCallbackData);
    unsigned long userData[4];
    void* pData;
    size_t nFileSize;
};

typedef int BOOL;

typedef struct _RTL_CRITICAL_SECTION CRITICAL_SECTION;

typedef int(__fastcall* CalcFogCallBack2_t)(int, void*);

typedef int(__fastcall* CalcFogCallBack_t)(int, int, int, void*);

typedef int(__fastcall* CalcGetFunctionParameterCount_t)(int nFunctionIndex);

typedef int(__fastcall* CalcGetKeyWordToNumber_t)(char* szKey);

typedef int(__fastcall* CalcGetLinkerIndex_t)(char* szText, BOOL* pOutHasResolvedToConstant, int nAST, int nKeywordNumber);

typedef int(__fastcall* CalcProcessCache_t)(int nIndex);

struct D2CalcCallbackInfoStrc
{
	CalcFogCallBack_t fpCallBack;
	int nParameters;
};

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

struct D2ImageHlpLineStrc
{
    unsigned long dwSizeOfStruct;
    void* pKey;
    unsigned long dwLineNumber;
    char* szFileName;
    unsigned long dwAddress;
};

struct D2InspectorInfoStrc
{
    int nProjectId;
    const char* szUnused04;
    const char* szApplication;
    const char* szModule;
    const char* szMilestone;
    const char* szBuildNumber;
    const char* szPlatform;
    const char* szPrimaryAssignment;
    const char* szAssignments;
};

struct D2LargeIntegerStrc
{
    unsigned int LowPart;
    int HighPart;
};

#ifndef D2_MEMORY_BASIC_INFO_STRC
#define D2_MEMORY_BASIC_INFO_STRC
struct D2MemoryBasicInfoStrc
{
    void* BaseAddress;
    void* AllocationBase;
    unsigned long AllocationProtect;
    unsigned long RegionSize;
    unsigned long State;
    unsigned long Protect;
    unsigned long Type;
};
#endif

struct D2OverlappedStrc
{
    unsigned long Internal;
    unsigned long InternalHigh;
    unsigned long Offset;
    unsigned long OffsetHigh;
    void* hEvent;
};

struct D2PeDosHeaderStrc
{
    unsigned short wMagic;
    char unk0x02[0x3A];
    long nNtHeadersOffset;
};

struct D2PeNtHeadersStrc
{
    unsigned long dwSignature;
    unsigned short wMachine;
    unsigned short wNumberOfSections;
    unsigned long dwTimeDateStamp;
    unsigned long dwPointerToSymbolTable;
    unsigned long dwNumberOfSymbols;
    unsigned short wSizeOfOptionalHeader;
    unsigned short wCharacteristics;
    char aOptionalHeader[4];
};

struct D2PeSectionStrc
{
    char szName[0x08];
    unsigned long dwVirtualSize;
    unsigned long dwVirtualAddress;
    unsigned long dwSizeOfRawData;
    unsigned long dwPointerToRawData;
    unsigned long dwPointerToRelocations;
    unsigned long dwPointerToLinenumbers;
    unsigned short wNumberOfRelocations;
    unsigned short wNumberOfLinenumbers;
    unsigned long dwCharacteristics;
};

struct D2QOverlappedStrc
{
    unsigned long nInternal;
    unsigned long nInternalHigh;
    unsigned long nOffset;
    unsigned long nOffsetHigh;
    void* hEvent;
    unsigned int nFlags;
};

struct D2QServerConfigStrc
{
    int nClientCapacity;
    int nValue04;
    int nValue08;
    int nValue0C;
};

struct D2QWriteNodeStrc
{
    unsigned int nSize;
    D2QWriteNodeStrc* pNext;
    unsigned char pData[1];
};

struct D2BinFieldStrc;

struct D2SNameNodeStrc
{
    D2SNameNodeStrc* pNext;
    unsigned int nHash;
    D2BinFieldStrc* pEntry;
};

#include "D2Win32Types.h"

// System, CPU and symbol-helper declarations of the Fog system units.
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile); // 0x006CC1C4
extern "C" __declspec(dllimport) int __stdcall GetComputerNameA(char* szBuffer, unsigned long* pnSize); // 0x006CC1D8
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime); // 0x006CC1D4
extern bool gbSymInitialized; // 0x0098A6B0
extern const char* gaszCpuVendorNames[]; // 0x00708004
extern void* ghDbgHelp; // 0x0098A680
extern void* ghProcess; // 0x0074C6F0
int __cdecl ERRORMANAGER_GetCpuVendor(); // 0x0040E250
int __fastcall FOG_CreatePathHierarchy(const char* szPath); // 0x00406A10
unsigned int __cdecl ERRORMANAGER_GetCpuSignature(); // 0x0040E960
unsigned int __cdecl ERRORMANAGER_GetCpuBrandIndex(); // 0x0040E980
extern "C" int __cdecl _snprintf_s(char* szBuffer, unsigned int nSizeOfBuffer, unsigned int nCount, const char* szFormat, ...); // 0x006824CB
unsigned long __stdcall SFileSetFilePointer(void* hFile, long lDistanceToMove, long* plDistanceToMoveHigh, unsigned long dwMoveMethod); // 0x004165A0
// build: symbol ?gtSystemInfo@* 0x0074D8A0
#define gwProcessorLevel_0074D8C0 (gtSystemInfo.wProcessorLevel)
typedef int (__stdcall* SymCleanupFn)(void* hProcess);

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* lp, unsigned int ucb); // 0x006CC238
extern "C" __declspec(dllimport) int __stdcall IsBadStringPtrA(const char* lpsz, unsigned int ucchMax); // 0x006CC2D0
extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int nCodePage, unsigned long dwFlags, const wchar_t* wszSource, int nSource, char* szDest, int nDest, const char* szDefaultChar, int* pbUsedDefaultChar); // 0x006CC194
extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread); // 0x006CC28C
extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread); // 0x006CC288
extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext); // 0x006CC290
extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C
typedef unsigned char BOOLEAN;

struct D2ImageDataDirStrc
{
    unsigned long VirtualAddress;
    unsigned long Size;
};

struct D2ImageFileHeaderStrc
{
    unsigned short Machine;
    unsigned short NumberOfSections;
    unsigned long TimeDateStamp;
    unsigned long PointerToSymbolTable;
    unsigned long NumberOfSymbols;
    unsigned short SizeOfOptionalHeader;
    unsigned short Characteristics;
};

struct D2ImageOptionalHeaderStrc
{
    unsigned short Magic;
    unsigned char MajorLinkerVersion;
    unsigned char MinorLinkerVersion;
    unsigned long SizeOfCode;
    unsigned long SizeOfInitializedData;
    unsigned long SizeOfUninitializedData;
    unsigned long AddressOfEntryPoint;
    unsigned long BaseOfCode;
    unsigned long BaseOfData;
    unsigned long ImageBase;
    unsigned long SectionAlignment;
    unsigned long FileAlignment;
    unsigned short MajorOperatingSystemVersion;
    unsigned short MinorOperatingSystemVersion;
    unsigned short MajorImageVersion;
    unsigned short MinorImageVersion;
    unsigned short MajorSubsystemVersion;
    unsigned short MinorSubsystemVersion;
    unsigned long Win32VersionValue;
    unsigned long SizeOfImage;
    unsigned long SizeOfHeaders;
    unsigned long CheckSum;
    unsigned short Subsystem;
    unsigned short DllCharacteristics;
    unsigned long SizeOfStackReserve;
    unsigned long SizeOfStackCommit;
    unsigned long SizeOfHeapReserve;
    unsigned long SizeOfHeapCommit;
    unsigned long LoaderFlags;
    unsigned long NumberOfRvaAndSizes;
    D2ImageDataDirStrc DataDirectory[16];
};

struct D2ImageOptionalHeader64Strc
{
    unsigned short Magic;
    unsigned char MajorLinkerVersion;
    unsigned char MinorLinkerVersion;
    unsigned long SizeOfCode;
    unsigned long SizeOfInitializedData;
    unsigned long SizeOfUninitializedData;
    unsigned long AddressOfEntryPoint;
    unsigned long BaseOfCode;
    unsigned __int64 ImageBase;
    unsigned long SectionAlignment;
    unsigned long FileAlignment;
    unsigned short MajorOperatingSystemVersion;
    unsigned short MinorOperatingSystemVersion;
    unsigned short MajorImageVersion;
    unsigned short MinorImageVersion;
    unsigned short MajorSubsystemVersion;
    unsigned short MinorSubsystemVersion;
    unsigned long Win32VersionValue;
    unsigned long SizeOfImage;
    unsigned long SizeOfHeaders;
    unsigned long CheckSum;
    unsigned short Subsystem;
    unsigned short DllCharacteristics;
    unsigned __int64 SizeOfStackReserve;
    unsigned __int64 SizeOfStackCommit;
    unsigned __int64 SizeOfHeapReserve;
    unsigned __int64 SizeOfHeapCommit;
    unsigned long LoaderFlags;
    unsigned long NumberOfRvaAndSizes;
    D2ImageDataDirStrc DataDirectory[16];
};

struct D2ImageNtHeadersStrc
{
    unsigned long Signature;
    D2ImageFileHeaderStrc FileHeader;
    D2ImageOptionalHeaderStrc OptionalHeader;
};

struct D2ImageDosHeaderStrc
{
    unsigned short e_magic;
    unsigned short e_unk02[25];
    unsigned short e_res2[4];
    long e_lfanew;
};

struct D2ImageDebugDirStrc
{
    unsigned long Characteristics;
    unsigned long TimeDateStamp;
    unsigned short MajorVersion;
    unsigned short MinorVersion;
    unsigned long Type;
    unsigned long SizeOfData;
    unsigned long AddressOfRawData;
    unsigned long PointerToRawData;
};

struct D2CvNb10Strc
{
    unsigned long dwCvSignature;
    unsigned long dwOffset;
    unsigned long dwSignature;
    unsigned long dwAge;
    char szPdbName[4];
};

struct D2ModuleStrc
{
    bool sub_00404AB0_VisitModule(void* pContext, const wchar_t* wszName, int nNameLength);                 // 0x00404AB0
};
struct D2ModuleEntry32Strc
{
    unsigned long dwSize;
    unsigned long th32ModuleID;
    unsigned long th32ProcessID;
    unsigned long GlblcntUsage;
    unsigned long ProccntUsage;
    D2ModuleStrc* modBaseAddr;
    unsigned long modBaseSize;
    void* hModule;
    wchar_t szModule[256];
    wchar_t szExePath[260];
};
struct D2PsapiModuleInfoStrc
{
    union
    {
        D2ModuleStrc* lpBaseOfDll;
        unsigned int nBase;
    };
    union
    {
        unsigned long SizeOfImage;
        unsigned int nSize;
    };
    union
    {
        void* EntryPoint;
        void* pEntryPoint;
    };
};

bool __fastcall ERRORMANAGER_EnumLoadedModules(void* pContext); // 0x00404E60
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryW(const wchar_t* szFileName); // 0x006CC294
extern "C" int __stdcall Module32FirstW(void* hSnapshot, D2ModuleEntry32Strc* pEntry); // 0x006B15AE
extern "C" int __stdcall Module32NextW(void* hSnapshot, D2ModuleEntry32Strc* pEntry); // 0x006B15B4
typedef int (__stdcall* EnumProcessModulesFn)(void* hProcess, void** phModules, unsigned long nSize, unsigned long* pnNeeded);
typedef unsigned long (__stdcall* GetModuleBaseNameWFn)(void* hProcess, void* hModule, wchar_t* wszName, unsigned long nSize);
typedef int (__stdcall* GetModuleInformationFn)(void* hProcess, void* hModule, D2PsapiModuleInfoStrc* pInfo, unsigned long nSize);

struct D2StormArray408Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2Storm408ElemStrc* m_data;
    unsigned int m_chunk;

    D2StormArray408Strc* sub_0051D2C0_InitBase();
    unsigned int sub_0051D2F0_CalcChunkSize(unsigned int nCount);
    void sub_0051D570_FreeData();
    void sub_0051D5D0_ReallocData(unsigned int nCount);
    void sub_0051D670_FreeData();
    D2StormArray408Strc* sub_0051D690_Init();
    void sub_0051D6A0_Clear();
    D2StormArray408Strc* sub_0051D720_Init();
    void sub_0051D730_FreeData();
    D2Storm408ElemStrc* sub_0051D7A0_New();
    void ReserveInline(unsigned int nCount, int bRound);
};

typedef unsigned char FOGASTType;

typedef unsigned char FOGCalcExpressionParserTokenType;
