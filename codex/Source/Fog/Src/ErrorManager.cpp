#include "Fog.h"
#include "D2FogTypes.h"
#include "D2NetTypes.h"
#include "D2Primitives.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"
#include "D2Win32System.h"
#include "D2CmdArg.h"
#include "D2FogSystemInfo.h"
#include "D2Win32SystemInfo.h"

typedef unsigned int size_t;

typedef char* va_list;

struct _iobuf;

struct tm
{
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
};

extern "C" __int64 __cdecl _time64(__int64* pTime);                                                         // 0x0068568B

extern "C" int __cdecl _localtime64_s(tm* pTm, const __int64* pTime);                                       // 0x006856E9

extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args);         // 0x00682F22

extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathW(unsigned long nBufferLength, wchar_t* wszBuffer); // 0x006CC2BC

extern "C" __declspec(dllimport) int __stdcall WideCharToMultiByte(unsigned int nCodePage, unsigned long dwFlags, const wchar_t* wszSource, int nSource, char* szDest, int nDest, const char* szDefaultChar, int* pbUsedDefaultChar); // 0x006CC194

bool __stdcall ERRORMANAGER_CreateDirectoryUtf8(const char* szPath);                                                // 0x004045F0

_iobuf* __stdcall ERRORMANAGER_OpenFileForWriteUtf8(const char* szPath);                                    // 0x004043C0

char gszLogDirectory[0x400];                                                                       // 0x00992708

namespace crashy
{
class Report
{
public:
    Report();                                                               // 0x00401070
    virtual ~Report();                                                      // 0x004010D0
    bool OpenReport(const char* szFileName);                         // 0x00401100
    bool sub_004011F0_Close();                                              // 0x004011F0
    bool sub_00401210_IsOpen();                                             // 0x00401210
    bool sub_00401220_AddFile(const char* szPath, bool bCopy);              // 0x00401220
    int sub_00401380(const char* szFormat, ...);                            // 0x00401380
    bool WriteInspectorHeader();                               // 0x00407A80

    _iobuf* m_pFile;
    char m_szText08[0x400];
    char m_szText408[0x400];
    int m_nLineCount;
    char m_aszLines[16][0x400];
};
}

extern "C" __declspec(dllimport) void __stdcall RtlCaptureContext(D2ThreadContextStrc* pContext);             // 0x006CC290

extern "C" __declspec(dllimport) void* __stdcall OpenThread(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwThreadId); // 0x006CC27C

extern "C" __declspec(dllimport) unsigned long __stdcall SuspendThread(void* hThread);                         // 0x006CC288

extern "C" __declspec(dllimport) unsigned long __stdcall ResumeThread(void* hThread);                          // 0x006CC28C

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HostentStrc;

struct D2ThreadNameInfoStrc;


struct D2ListEntryStrc;

struct D2LdrEntryStrc;

struct D2LdrDataStrc;


struct D2TebStrc;

struct D2ModeIfaceStrc;

struct D2ModeEntryStrc;

struct D2ServiceTableEntryStrc;

struct D2GuidStrc;

struct D2SidAuthorityStrc;

struct D2ProcessEntryStrc;

void __cdecl sub_00402980_StartDbgHelpWorker(); // 0x00402980

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

struct D2GuidStrc
{
    unsigned long Data1;
    unsigned short Data2;
    unsigned short Data3;
    unsigned char Data4[8];
};

typedef long (__stdcall* D2KnownFolderPathFn)(const D2GuidStrc* pFolderId, unsigned long dwFlags, void* hToken, wchar_t** pwszPath);

typedef int (__stdcall* D2AllocateAndInitializeSidFn)(D2SidAuthorityStrc* pAuthority, unsigned char nSubAuthorityCount, unsigned long dwSub0, unsigned long dwSub1, unsigned long dwSub2, unsigned long dwSub3, unsigned long dwSub4, unsigned long dwSub5, unsigned long dwSub6, unsigned long dwSub7, void** ppSid);

typedef int (__stdcall* D2InitializeAclFn)(void* pAcl, unsigned long nAclLength, unsigned long dwAclRevision);

typedef int (__stdcall* D2AddAccessDeniedAceFn)(void* pAcl, unsigned long dwAceRevision, unsigned long dwAccessMask, void* pSid);

typedef unsigned long (__stdcall* D2SetSecurityInfoFn)(void* hObject, int nObjectType, unsigned long dwSecurityInfo, void* pOwner, void* pGroup, void* pDacl, void* pSacl);

typedef void* HKEY;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

extern "C" double __cdecl floor(double x); // 0x00683080

extern "C" unsigned long __readfsdword(unsigned long nOffset);

extern "C" __declspec(dllimport) int __stdcall WSAStartup(unsigned short wVersionRequested, D2WSADataStrc* pData); // 0x006CC564

extern "C" __declspec(dllimport) D2HostentStrc* __stdcall gethostbyname(const char* szName); // 0x006CC57C

extern "C" __declspec(dllimport) int __stdcall WSACleanup(); // 0x006CC58C

extern "C" __declspec(dllimport) int __stdcall IsDebuggerPresent(); // 0x006CC284

extern "C" __declspec(dllimport) void __stdcall RaiseException(unsigned long dwCode, unsigned long dwFlags, unsigned long nArgs, const unsigned long* pArgs); // 0x006CC224

extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleW(const wchar_t* wszModuleName); // 0x006CC2DC

extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C

extern "C" __declspec(dllimport) void* __stdcall FreeSid(void* pSid); // 0x006CC044

extern "C" __declspec(dllimport) void __stdcall CoTaskMemFree(void* pMemory); // 0x006CC5F0

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryA(const char* szPathName, void* pSecurityAttributes); // 0x006CC1B8

extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4

extern "C" int __stdcall Process32First(void* hSnapshot, D2ProcessEntryStrc* pEntry); // 0x006B1440

extern "C" int __stdcall Process32Next(void* hSnapshot, D2ProcessEntryStrc* pEntry); // 0x006B143A

const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

bool __fastcall ERRORMANAGER_CreateDirectoryWide(wchar_t* wszPath); // 0x00404560

int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0

extern "C" const char gszInternalCheckHost[]; // 0x006FF994

extern "C" const D2GuidStrc gtKnownFolderId; // 0x006CCA6C

extern const double gdDaysPerYear; // 0x006CCC08

extern const double gdDaysPerMonth; // 0x006CCC10

struct D2FileTimeStrc;

struct D2FindDataStrc;

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0

int __stdcall SFileOpenFile(const char* szFileName, void** phFile); // 0x00419980

int __stdcall SFileReadFileEx2(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg6, int nArg7); // 0x0041AAD0

int __stdcall SFileGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370

struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C

extern "C" __declspec(dllimport) int __stdcall MoveFileA(const char* szExisting, const char* szNew); // 0x006CC1D0

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC

extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData); // 0x006CC1C8

extern "C" __declspec(dllimport) int __stdcall RemoveDirectoryA(const char* szPathName); // 0x006CC1C0

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

int __fastcall ERRORMANAGER_GetJulianDay(int nYear, int nMonth, int nDay); // 0x00407370

void __fastcall ERRORMANAGER_JulianDayToDate(long nJulian, int* pYear, int* pMonth, int* pDay); // 0x00407440

int __fastcall EXCEPTIONS_GetAppPath(char* szPath, unsigned int nSize); // 0x0040C220

const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60

void __stdcall ERRORMANAGER_WriteProcessorReport(); // 0x0040EA00

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

extern int gnOsKind; // 0x0074D890

extern float gfOsVersion; // 0x0074D894

void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...); // 0x004106B0

void __cdecl LOGMANAGER_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...); // 0x00410740

extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile); // 0x00408000

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660

int gbWritingCrashReport; // 0x0074F0C8

D2ModeIfaceStrc* gpModeIface; // 0x0074C700

int gbRunningAsService; // 0x0074C720

char szSRegReadBuf[260]; // 0x0074C728

unsigned long gdwTotalPhys; // 0x0074D898

#define OUTPUT_SIZE 0x80

extern "C" const char gszMainThread[];  // 0x006FF988

extern "C" int __cdecl strncpy_s(char*,unsigned int,const char*,unsigned int);  // 0x006859D2

struct D2PoolSystemStrc;

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void __cdecl FOG_AsyncDataDestroy();                                                                        // 0x0040A440

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem);                                        // 0x00409C80

int __cdecl EXCEPTIONS_UnloadImageHlp();                                                                  // 0x0040B500

void __cdecl LOGMANAGER_CloseLogFilesNow();                                                               // 0x0040F8A0

void __cdecl SYSTEM_DeleteTimeLock();                                                                 // 0x004107A0

void __cdecl LOGMANAGER_ShutdownLogSystem();                                                              // 0x0040FFD0

extern "C" const char gszStringFormat[];                                                           // 0x006FFC58

D2CriticalSectionStrc gtLock_0074C830;                                                                      // 0x0074C830

D2CriticalSectionStrc gtLock_0074D848;                                                                      // 0x0074D848

int gbErrorMgrInit;                                                                                // 0x0074F0D0

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, wchar_t* wszDest, int nDest); // 0x006CC29C

extern "C" __declspec(dllimport) int __stdcall CopyFileW(const wchar_t* wszExistingFile, const wchar_t* wszNewFile, int bFailIfExists); // 0x006CC2CC

static bool __stdcall ERRORMANAGER_CopyFileName(const char* szPath, char* szOut, size_t nSize); // 0x00404010

static bool __stdcall ERRORMANAGER_CopyFileUtf8(const char* szSource, const char* szDest); // 0x00404450

static size_t ERRORMANAGER_StrLCopy(char* szDest, const char* szSource, size_t nSize); // 0x00404110

static bool ERRORMANAGER_AppendPathSeparator(char* szPath); // 0x004040B0

static int ERRORMANAGER_FormatText(char* szDest, size_t nSize, const char* szFormat, ...); // 0x004041F0

static bool ERRORMANAGER_GetTempPathUtf8(char* szOut); // 0x004044F0

static bool __stdcall ERRORMANAGER_CopyPathIfHasDirectory(const char* szPath, char* szOut, size_t nSize); // 0x00403FA0

extern "C" __declspec(dllimport) int __stdcall AllocateAndInitializeSid(D2SidAuthorityStrc* pAuthority, unsigned char nSubAuthorityCount, unsigned long dwSub0, unsigned long dwSub1, unsigned long dwSub2, unsigned long dwSub3, unsigned long dwSub4, unsigned long dwSub5, unsigned long dwSub6, unsigned long dwSub7, void** ppSid); // 0x006CC014

extern "C" __declspec(dllimport) int __stdcall CheckTokenMembership(void* hToken, void* pSid, int* pbIsMember); // 0x006CC050

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentProcessId();                             // 0x006CC1EC

bool __fastcall ERRORMANAGER_GetProcessImageName(unsigned long dwProcessId, char* szName, unsigned long nSize); // 0x00407A20

unsigned long __fastcall ERRORMANAGER_FindParentProcessId(unsigned long dwProcessId);                         // 0x00407990

unsigned int __fastcall LOGMANAGER_GetLogFilePaths(char** apszFiles, unsigned int nCount);                     // 0x0040EB90

int __stdcall sub_00525150();                                                                       // 0x00525150

int __stdcall STRTABLE_GetSystemLanguage();                                                                   // 0x005251C0

D2InspectorInfoStrc gtInspectorInfo; // 0x0074D868

char gszProcessPath[2048];                                                                         // 0x0074E8C8

extern const char* const gaszLanguageNames[];                                                      // 0x00706618

extern "C" const char gszUnknownUpper[];                                                           // 0x006CCED8

extern "C" const char gszUnknownTitle[];// 0x006CCBE8

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

bool __stdcall ERRORMANAGER_GetKnownFolderPathA(char* szPath, int nSize);                                   // 0x004067D0

int __fastcall ERRORMANAGER_AppendBackslash(char* szPath, size_t nSize);                                // 0x00406B20

int __fastcall ERRORMANAGER_MoveDirectoryTree(const char* szPathA, const char* szPathB);                         // 0x00406DE0

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

struct D2ThreadContextStrc;

struct D2CrashSubmitInfoStrc
{
    const char* szName;
    const char* szLocale;
    const char* szFrom;
    unsigned int dwFlags;
    const char* apszLines[16];
    int nLines;
};

typedef void (__fastcall* D2CrashPrintFn)(void* pContext, const char* szText);

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend);              // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend);              // 0x006CC204

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();                               // 0x006CC20C

// The thread that started the game, recorded before main.
// build: symbol ??__EgdwMainThreadId@@YAXXZ 0x006CA6F0
// build: symbol ?gdwMainThreadId@@3HA 0x00992B1C
int gdwMainThreadId = GetCurrentThreadId(); // 0x00992B1C

void __fastcall ERRORMANAGER_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader, int nArg7); // 0x00403070

void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext); // 0x004032F0

void __fastcall ERRORMANAGER_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId); // 0x00403A20

void __fastcall ERRORMANAGER_ReportPrint(void* pContext, const char* szText);                               // 0x00407980

bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo);                // 0x00401790

struct D2StackFrameStrc;

void __fastcall sub_00403100_PrintFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, unsigned int nFrames, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader); // 0x00403100

unsigned long __cdecl ERRORMANAGER_GetCurrentThreadId(); // 0x00401690

void __fastcall ERRORMANAGER_TerminateCurrentProcess(unsigned int nCode); // 0x004013C0

int __stdcall SFileCloseFile(void* pArg);    // 0x004198D0

struct AsyncDataEventSlot;

struct D2CriticalSectionStrc;

struct D2MiniDumpRequestStrc;

struct D2FogSystemInfoStrc;

struct D2ProcessEntryWStrc;

struct D2StartupInfoWStrc;

struct D2ProcessInformationStrc;

struct D2OverlappedStrc;

struct AsyncDataLoadFileCallback;

struct AsyncData;

struct D2InspectorInfoStrc;

struct D2CrashSubmitInfoStrc;

typedef long (__stdcall* D2ExceptionFilterFn)(void* pExceptionPointers);

extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode); // 0x006CC274

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) D2ExceptionFilterFn __stdcall SetUnhandledExceptionFilter(D2ExceptionFilterFn pfnFilter); // 0x006CC2B4

extern "C" __declspec(dllimport) int __stdcall CreateDirectoryW(const wchar_t* szPath, void* pSecurityAttributes); // 0x006CC2C8

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesW(const wchar_t* szFileName); // 0x006CC2B8

extern "C" wchar_t* __cdecl wcsrchr(const wchar_t* szString, wchar_t nChar); // 0x00685DF7

const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0

long __stdcall sub_00403E90_UnhandledExceptionFilter(void* pExceptionPointers); // 0x00403E90

void __fastcall LOGMANAGER_SetLogPrefix(const char* szName); // 0x0040F5A0

extern D2CriticalSectionStrc gtSymbolLock; // 0x0098A6F0

extern void* gpfnCrashHandler; // 0x00992B10

extern D2FogSystemInfoStrc gtSystemInfo_0074D88C; // 0x0074D88C

extern "C" int __stdcall Process32FirstW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1524

extern "C" int __stdcall Process32NextW(void* hSnapshot, D2ProcessEntryWStrc* pEntry); // 0x006B1530

extern "C" __declspec(dllimport) int __stdcall CreateProcessW(const wchar_t* wszApplicationName, wchar_t* wszCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const wchar_t* wszCurrentDirectory, D2StartupInfoWStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC2C4

void __cdecl LOGMANAGER_CloseLogFiles(); // 0x0040F960

int __fastcall ERRORMANAGER_ReportNestedError(const char* szFile, int nLine, const char* szMessage); // 0x004088C0

bool __cdecl sub_004013A0_IsDebuggerAttached(); // 0x004013A0

struct AsyncData
{
    void* hFile;
    void* pMemPool;
    D2OverlappedStrc tOverlapped;
    AsyncDataLoadFileCallback pAsyncOpDesc;
    AsyncDataEventSlot* pEventSlot;
    void* ptBuffer;
    unsigned int nFileSize;
    unsigned int nPriority;
    unsigned int dwFlags;
    unsigned int nPreviousPriority;
    AsyncData* pNextPostponedPriorityChange;
};

struct AsyncDataEventSlot
{
    void* hEvent;
    unsigned long bSlotAvailable;
    AsyncData* pAsyncOp;
};

int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0

int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0

int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900

int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

int __fastcall FOG_FSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* lpSystemTime); // 0x006CC1D4

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C

extern "C" int __cdecl _snprintf(char* szDest, size_t nCount, const char* szFormat, ...); // 0x006831DB

extern long volatile gnCrashReportBusy; // 0x007076BC

bool __fastcall ERRORMANAGER_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag); // 0x00408660

char gszTextBuffer[0x400]; // 0x0098A280

void* gpCrashContext; // 0x00992B14

D2ExceptionFilterFn gpfnPreviousFilter; // 0x00992B18

int gnSourcePrefixLength; // 0x0074F0D4

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args);                          // 0x00682DA1

extern "C" void* __cdecl malloc(size_t nSize);                                                              // 0x00683EFD

extern "C" _iobuf* __cdecl _wfopen(const wchar_t* szFileName, const wchar_t* szMode);                       // 0x00685EED

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x006CC19C

extern "C" __declspec(dllimport) int __stdcall ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped); // 0x006CC1A4

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8

extern "C" __declspec(dllimport) unsigned long __stdcall SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x006CC1AC

extern "C" __declspec(dllimport) void* __stdcall OpenProcess(unsigned long dwDesiredAccess, int bInheritHandle, unsigned long dwProcessId); // 0x006CC1E8

extern "C" __declspec(dllimport) short __stdcall GetAsyncKeyState(int nVirtualKey);                         // 0x006CC460

extern "C" __declspec(dllimport) void* __stdcall GetCurrentThread();                                        // 0x006CC24C

extern "C" __declspec(dllimport) int __stdcall GetThreadPriority(void* hThread);                            // 0x006CC268

extern "C" __declspec(dllimport) int __stdcall SetThreadPriority(void* hThread, int nPriority);             // 0x006CC264

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(__int64* pCount);         // 0x006CC25C

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(__int64* pFrequency);   // 0x006CC254

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258

extern "C" void* __stdcall CreateToolhelp32Snapshot(unsigned long dwFlags, unsigned long dwProcessId);      // 0x006B1446

extern "C" int __stdcall Thread32First(void* hSnapshot, D2ThreadEntryStrc* pEntry);                        // 0x006B156C

extern "C" int __stdcall Thread32Next(void* hSnapshot, D2ThreadEntryStrc* pEntry);                         // 0x006B1572

extern "C" unsigned long __stdcall GetModuleFileNameExA(void* hProcess, void* hModule, char* szFileName, unsigned long nSize); // 0x006B13C2

void __cdecl ERRORMANAGER_LogPoolError(const char* szFormat, ...);

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pBuffer); // 0x006CC1F4

char* __fastcall Int64ToString(char* szBuffer, unsigned int nBufferSize, __int64 nValue); // 0x00411540

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

unsigned __int64 __cdecl AUTOMAP_ReadTimeStampCounter(); // 0x0040E850

extern "C" const char gszNewline[];                                                                // 0x006FFCB0

extern D2CmdArgStrc gaCmdArguments[58];                                                                     // 0x00705040

void* ghD2ServerServiceStatus;                                                                              // 0x0074C714

extern unsigned char gabHuffmanCodeLength[256];                                                    // 0x007076C0

unsigned char gabHuffmanCode[256];                                                                 // 0x0075B6A0

const unsigned char* gapHuffmanDecode[256];                                                        // 0x0075AFA0

extern unsigned int gadwHuffmanMask[32];                                                           // 0x007077C0

struct D2CrashInputStrc;

#define FOG_ASSERT(expr, line) if (!(expr)) { const char* szAssertFile = sub_00408090(); FOG_SOCKET_WSACleanup(); ERRORMANAGER_RaiseErrorReport(6, &gszEmptyAssertText, line, "Unrecoverable internal error %08x", szAssertFile); LOGMANAGER_CloseLogFiles(); exit(-1); }

void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

void __cdecl ERRORMANAGER_StartDbgHelpThread(); // 0x004016A0

void __fastcall ERRORMANAGER_SetReportText(const char* szText); // 0x00401740

void __fastcall ERRORMANAGER_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused); // 0x00403F60

int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60

void __cdecl ERRORMANAGER_LogSystemInfo(); // 0x004076B0

void __cdecl ERRORMANAGER_ExitHandler(); // 0x00407F20

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern D2PoolDirectoryStrc gtPoolManager; // 0x0074F0E8

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220

extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C

void* __fastcall ERRORMANAGER_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine); // 0x00409770

extern const unsigned int gadwLowBitMasks[]; // 0x006CD490

int __fastcall ERRORMANAGER_FindZeroBit(unsigned int nWord); // 0x00409220

static int ERRORMANAGER_GetPoolIndex(int nSize);

void* __fastcall ERRORMANAGER_PoolAlloc(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine); // 0x0040A080

static D2MemPoolBlockStrc* __stdcall ERRORMANAGER_FindPoolBlock(void* pMemory, D2PoolSystemStrc* pSystem); // 0x004099D0

static void ERRORMANAGER_MoveBlockToFront(D2MemPoolRecStrc* pPool, D2MemPoolBlockStrc* pBlock); // 0x00409A60

void __fastcall ERRORMANAGER_PoolFree(D2PoolSystemStrc* pSystem, void** ppMemory, const char* szFile, int nLine); // 0x00409AB0

// 0x00401000
static int __cdecl ERRORMANAGER_ConvertLocalTime(tm* pTm, const __int64* pTime)
{
    return _localtime64_s(pTm, pTime);
}

// calling-convention shim (not game code)
int __cdecl sub_M126_Emit_00401000(tm* pTm, const __int64* pTime)
{
    return ERRORMANAGER_ConvertLocalTime(pTm, pTime);
}

bool __stdcall sub_K01_Emit_00403FA0(const char* szPath, char* szOut, size_t nSize)
{
    return ERRORMANAGER_CopyPathIfHasDirectory(szPath, szOut, nSize);
}

// 0x00401100
bool crashy::Report::OpenReport(const char* szFileName)
{
    __int64 nTime = _time64(0);
    tm tTime;
    _localtime64_s(&tTime, &nTime);
    if (!gszLogDirectory[0])
    {
        if (!ERRORMANAGER_GetTempPathUtf8(gszLogDirectory))
        {
            return false;
        }
        if (!ERRORMANAGER_AppendPathSeparator(gszLogDirectory))
        {
            return false;
        }
    }
    if ((size_t)(ERRORMANAGER_FormatText(m_szText408, 0x400, "%s/%04d-%02d-%02d %02d.%02d.%02d", gszLogDirectory, tTime.tm_year + 0x76C, tTime.tm_mon + 1, tTime.tm_mday, tTime.tm_hour, tTime.tm_min, tTime.tm_sec) + 1) > 0x400)
    {
        return false;
    }
    if (!ERRORMANAGER_CreateDirectoryUtf8(m_szText408))
    {
        return false;
    }
    if ((size_t)(ERRORMANAGER_FormatText(m_szText08, 0x400, "%s/%s", m_szText408, szFileName) + 1) > 0x400)
    {
        return false;
    }
    m_pFile = ERRORMANAGER_OpenFileForWriteUtf8(m_szText08);
    return m_pFile != 0;
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

// 0x00401640
static bool __stdcall ERRORMANAGER_GetThreadName(int threadId,char* output) {
 if(gdwMainThreadId==threadId) strncpy_s(output,OUTPUT_SIZE,gszMainThread,(unsigned int)-1);
 else output[0]=0;
 return true;
}

bool __fastcall EmitThreadName(int threadId,char* output) {
 return ERRORMANAGER_GetThreadName(threadId,output);
}

// 0x00401680
int __cdecl ERRORMANAGER_GetMainThreadId()
{
    return gdwMainThreadId;
}

int D2ThreadContextStrc::sub_00405060_CaptureFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, int nSkipFrames)
{
    D2ThreadContextStrc tContext;
    void* hThread = 0;
    if (this)
    {
        tContext = *this;
    }
    else
    {
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
        for (unsigned int i = 0; i < 0x80; i++)
        {
            if (i >= (unsigned int)nSkipFrames)
            {
                pFrames[nCount].dwPc = dwPc;
                pFrames[nCount].dwStack = dwStack;
                pFrames[nCount].dwFrame = dwFrame;
                nCount++;
                if (nCount >= 0x80)
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
            dwStack = dwFrame + 4;
            dwPc = *(unsigned long*)dwStack;
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

// 0x004016A0
void __cdecl ERRORMANAGER_StartDbgHelpThread()
{
    sub_00402980_StartDbgHelpWorker();
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004016B0
void __cdecl sub_004016B0_Nothing()
{
}

// 0x004016C0
bool __cdecl ERRORMANAGER_IsInternalCheckLoopback()
{
    D2WSADataStrc tData;
    if (WSAStartup(0x202, &tData))
    {
        return false;
    }
    bool bResult = false;
    D2HostentStrc* pHost = gethostbyname(gszInternalCheckHost);
    if (pHost && pHost->h_addrtype == 2 && *(unsigned long*)pHost->h_addr_list[0] == 0x0100007F)
    {
        bResult = true;
    }
    WSACleanup();
    return bResult;
}

// 0x00401A70
void __cdecl ERRORMANAGER_SetMiniDumpThreadName()
{
    if (IsDebuggerPresent() == 1)
    {
        D2ThreadNameInfoStrc tInfo;
        tInfo.dwType = 0x1000;
        tInfo.szName = "MiniDump Thread";
        tInfo.dwThreadID = -1;
        tInfo.dwFlags = 0;
        __try
        {
            RaiseException(0x406D1388, 0, 4, (unsigned long*)&tInfo);
        }
        __except (-1)
        {
        }
    }
}

// 0x00403070
void __fastcall ERRORMANAGER_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader, int nArg7)
{
    D2StackFrameStrc aFrames[0x80];
    int nFrames = pThreadContext->sub_00405060_CaptureFrames(dwThreadId, aFrames, nArg7);
    if (nFrames > 0)
    {
        if (nFrames > 0x80)
        {
            nFrames = 0x80;
        }
        sub_00403100_PrintFrames(dwThreadId, aFrames, nFrames, pfnPrint, pContext, bSymbols, bHeader);
    }
}

// 0x00403FA0
static bool __stdcall ERRORMANAGER_CopyPathIfHasDirectory(const char* szPath, char* szOut, size_t nSize)
{
    const char* pSep = 0;
    const char* p = strrchr(szPath, '/');
    if (p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, '\\');
    if (p && p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, ':');
    if (p && p > pSep)
    {
        pSep = p;
    }
    if (!pSep)
    {
        *szOut = 0;
    }
    else if (ERRORMANAGER_StrLCopy(szOut, szPath, nSize) >= nSize)
    {
        return false;
    }
    return true;
}

static __forceinline size_t StrLCopy(char* szDest, const char* szSource, size_t nSize)
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

bool crashy::Report::sub_00401220_AddFile(const char* szPath, bool bCopy)
{
    if (m_nLineCount >= 16)
    {
        return false;
    }
    char szCopy[0x400];
    const char* szSource;
    if (bCopy)
    {
        if (!m_szText408[0])
        {
            return false;
        }
        const size_t nLength = StrLCopy(szCopy, m_szText408, 0x400);
        if (nLength >= 0x400)
        {
            return false;
        }
        char* pName = szCopy + nLength;
        *pName++ = '/';
        if (!ERRORMANAGER_CopyFileName(szPath, pName, szCopy + 0x400 - pName))
        {
            return false;
        }
        ERRORMANAGER_CopyFileUtf8(szPath, szCopy);
        szSource = szCopy;
    }
    else
    {
        if (strlen(szPath) >= 0x400)
        {
            return false;
        }
        szSource = szPath;
    }
    StrLCopy(m_aszLines[m_nLineCount], szSource, 0x400);
    m_nLineCount++;
    return true;
}

// 0x00404010
static bool __stdcall ERRORMANAGER_CopyFileName(const char* szPath, char* szOut, size_t nSize)
{
    const char* pSep = 0;
    const char* p = strrchr(szPath, '/');
    if (p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, '\\');
    if (p && p > pSep)
    {
        pSep = p;
    }
    p = strrchr(szPath, ':');
    if (p && p > pSep)
    {
        pSep = p;
    }
    if (pSep)
    {
        szPath = pSep + 1;
    }
    return StrLCopy(szOut, szPath, nSize) < nSize ? true : false;
}

// 0x004040B0
static bool ERRORMANAGER_AppendPathSeparator(char* szPath)
{
    char* pEnd = szPath + strlen(szPath);
    if (pEnd == szPath + 0x400)
    {
        return false;
    }
    if (pEnd != szPath && pEnd[-1] != '/' && pEnd[-1] != '\\')
    {
        *pEnd = '\\';
    }
    return ERRORMANAGER_StrLCopy(szPath, "BlizzardError", 0x400) < 0x400;
}

// 0x00404110
static __declspec(noinline) size_t ERRORMANAGER_StrLCopy(char* szDest, const char* szSource, size_t nSize)
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

// 0x004041F0
static int ERRORMANAGER_FormatText(char* szDest, size_t nSize, const char* szFormat, ...)
{
    const int nResult = _vsnprintf(szDest, nSize - 1, szFormat, (va_list)(&szFormat + 1));
    szDest[nSize - 1] = 0;
    return nResult;
}

// 0x00404450
static bool __stdcall ERRORMANAGER_CopyFileUtf8(const char* szSource, const char* szDest)
{
    wchar_t wszSource[0x104];
    wchar_t wszDest[0x104];
    if (!MultiByteToWideChar(0xFDE9, 0, szSource, -1, wszSource, 0x104))
    {
        return false;
    }
    if (!MultiByteToWideChar(0xFDE9, 0, szDest, -1, wszDest, 0x104))
    {
        return false;
    }
    return CopyFileW(wszSource, wszDest, 1) != 0;
}

// 0x004044F0
static bool ERRORMANAGER_GetTempPathUtf8(char* szOut)
{
    wchar_t wszPath[0x104];
    const unsigned long nLength = GetTempPathW(0x104, wszPath);
    if (!nLength)
    {
        return false;
    }
    return WideCharToMultiByte(0xFDE9, 0, wszPath, nLength + 1, szOut, 0x400, 0, 0) != 0;
}

// 0x004045F0
bool __stdcall ERRORMANAGER_CreateDirectoryUtf8(const char* szPath)
{
    wchar_t wszPath[0x104];
    if (!MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104))
    {
        return false;
    }
    return ERRORMANAGER_CreateDirectoryWide(wszPath);
}

inline D2TebStrc* D2_NtCurrentTeb()
{
    return (D2TebStrc*)__readfsdword(0x18);
}

// 0x00404E60
bool __fastcall ERRORMANAGER_EnumLoadedModules(void* pContext)
{
    if (!GetModuleHandleW(L"ntdll.dll"))
    {
        return false;
    }
    __try
    {
        D2LdrDataStrc* pLdr = D2_NtCurrentTeb()->ProcessEnvironmentBlock->Ldr;
        D2ListEntryStrc* pHead = &pLdr->InMemoryOrderModuleList;
        for (D2ListEntryStrc* pLink = pHead->Flink; pLink != pHead; pLink = pLink->Flink)
        {
            D2LdrEntryStrc* pEntry = (D2LdrEntryStrc*)((char*)pLink - 8);
            if (!pEntry->DllBase->sub_00404AB0_VisitModule(pContext, pEntry->FullDllName.Buffer, pEntry->FullDllName.Length))
            {
                break;
            }
        }
    }
    __except (1)
    {
    }
    return true;
}

// 0x004067C0
int __cdecl ERRORMANAGER_SetBasePathToCurrent()
{
    return SFileSetBasePath(".\\");
}

// 0x004067D0
bool __stdcall ERRORMANAGER_GetKnownFolderPathA(char* szPath, int nSize)
{
    void* hShell = GetModuleHandleA("Shell32.dll");
    D2KnownFolderPathFn pfnGet = (D2KnownFolderPathFn)GetProcAddress(hShell, "SHGetKnownFolderPath");
    if (!pfnGet)
    {
        return false;
    }
    wchar_t* wszPath;
    if (pfnGet(&gtKnownFolderId, 0x8000, 0, &wszPath) < 0)
    {
        return false;
    }
    int bUsedDefault = 0;
    const int nResult = WideCharToMultiByte(0, 0x400, wszPath, -1, szPath, nSize, 0, &bUsedDefault);
    CoTaskMemFree(wszPath);
    return nResult && !bUsedDefault;
}

// 0x004076B0
void __cdecl ERRORMANAGER_LogSystemInfo()
{
    D2SystemTimeStrc tTime;
    unsigned long nSize;
    char szPath[0x1000];
    char szOs[0x1000];
    char szComputer[0x40];

    LOGMANAGER_WriteLogLine("------------------------------------------------------");
    GetLocalTime(&tTime);
    LOGMANAGER_WriteLogLine("%04d-%02d-%02d %02d:%02d:%02d", tTime.wYear, tTime.wMonth, tTime.wDay, tTime.wHour, tTime.wMinute, tTime.wSecond);

    switch (gnOsKind)
    {
    case 1:
        memcpy(szOs, "Windows NT", sizeof("Windows NT"));
        break;
    case 2:
        memcpy(szOs, "Windows 2000", sizeof("Windows 2000"));
        break;
    case 3:
        memcpy(szOs, "Windows XP", sizeof("Windows XP"));
        break;
    case 4:
        memcpy(szOs, "Windows .Net", sizeof("Windows .Net"));
        break;
    case 9:
        memcpy(szOs, "MacOS", sizeof("MacOS"));
        break;
    case 10:
        memcpy(szOs, "MacOS X", sizeof("MacOS X"));
        break;
    default:
        memcpy(szOs, "unknown", sizeof("unknown"));
        break;
    }

    LOGMANAGER_WriteLogLine("%s running under %s (Version %.3f)", "Diablo II", szOs, gfOsVersion);
    ERRORMANAGER_WriteProcessorReport();
    LOGMANAGER_WriteLogLine("Total Physical Memory: %.2fMB", (float)gdwTotalPhys / 1048576.0);

    if (EXCEPTIONS_GetAppPath(szPath, sizeof(szPath)))
    {
        LOGMANAGER_WriteLogLine("Application Path: %s", szPath);
    }

    LOGMANAGER_WriteLogLine("Local IP: %s", FOG_GetHostIPAddress());

    nSize = sizeof(szComputer);
    if (!GetComputerNameA(szComputer, &nSize))
    {
        szComputer[0] = 0;
    }

    LOGMANAGER_WriteLogLine("Computer name: %s", szComputer);
    LOGMANAGER_WriteLogLine("------------------------------------------------------");
    LOGMANAGER_WriteLogLine(&gszEmptyAssertText);
}

// 0x00407970
void __cdecl ERRORMANAGER_ForceCrash()
{
    int* pNull = 0;
    *pNull = 0;
}

// 0x00407980
void __fastcall ERRORMANAGER_ReportPrint(void* pContext, const char* szText)
{
    ((crashy::Report*)pContext)->sub_00401380(gszStringFormat, szText);
}

// 0x00407990
unsigned long __fastcall ERRORMANAGER_FindParentProcessId(unsigned long dwProcessId)
{
    unsigned long dwParent = 0;
    void* hSnapshot = CreateToolhelp32Snapshot(2, 0);
    D2ProcessEntryStrc tEntry;
    tEntry.dwSize = sizeof(tEntry);
    if (Process32First(hSnapshot, &tEntry))
    {
        do
        {
            if (tEntry.th32ProcessID == dwProcessId)
            {
                break;
            }
        }
        while (Process32Next(hSnapshot, &tEntry));
    }
    if (tEntry.th32ProcessID == dwProcessId)
    {
        dwParent = tEntry.th32ParentProcessID;
    }
    CloseHandle(hSnapshot);
    return dwParent;
}

// 0x00407F20
void __cdecl ERRORMANAGER_ExitHandler()
{
    if (gbErrorMgrInit)
    {
        FOG_AsyncDataDestroy();
        FOG_DestroyMemoryPoolSystem(0);
        EXCEPTIONS_UnloadImageHlp();
        LOGMANAGER_CloseLogFilesNow();
        SYSTEM_DeleteTimeLock();
        LOGMANAGER_ShutdownLogSystem();
        gbErrorMgrInit = 0;
        DeleteCriticalSection(&gtLock_0074C830);
        DeleteCriticalSection(&gtLock_0074D848);
    }
}

static int __fastcall FOG_AppendBackslash(char* szPath, int nSize)
{
    if (!szPath || !nSize)
        return 0;
    unsigned int nLen = SStrLen(szPath);
    if (nLen <= 0 || szPath[nLen - 1] != '\\')
    {
        if (nLen + 1 == nSize)
            return 0;
        szPath[nLen] = '\\';
        szPath[nLen + 1] = 0;
    }
    return 1;
}

// 0x00407F70
void __fastcall ERRORMANAGER_LogText(void* pUnused, const char* szText)
{
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, szText);
}

// 0x00407F80
void __fastcall ERRORMANAGER_RegisterThread(unsigned int nId, void* hThread)
{
}

static bool AppendPathSeparator_Inl(char* szPath, size_t nSize)
{
    if (!nSize)
    {
        return false;
    }
    const size_t nLength = SStrLen(szPath);
    if (nLength > 0 && szPath[nLength - 1] == '\\')
    {
        return true;
    }
    if (nLength + 1 == nSize)
    {
        return false;
    }
    szPath[nLength] = '\\';
    szPath[nLength + 1] = 0;
    return true;
}

// 0x00407F90
void __fastcall ERRORMANAGER_UnregisterThread(unsigned int nId)
{
}

// 0x00407FC0
static void __stdcall ERRORMANAGER_LogPrefixedText(const char* szPrefix, const char* szText, int bFlag)
{
    if (bFlag)
    {
        LOGMANAGER_LogWritePrefixedNoNewline(szPrefix, gszPercentS_006FFC58, szText);
    }
    else
    {
        LOGMANAGER_LogWritePrefixed(szPrefix, gszPercentS_006FFC58, szText);
    }
}

inline unsigned int RoundUpInline(unsigned int nValue, unsigned int nAlign)
{
    unsigned int nRemainder = nValue % nAlign;
    if (nRemainder)
        nValue += nAlign - nRemainder;
    return nValue;
}

inline void D2StormArray408Strc::ReserveInline(unsigned int nCount, int bRound)
{
    nCount += m_count;
    if (nCount > m_alloc)
    {
        if (bRound)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_0051D2F0_CalcChunkSize(nCount);
            nCount = RoundUpInline(nCount, nChunk);
        }
        sub_0051D5D0_ReallocData(nCount);
    }
}

// build: symbol ?BNNEWS_CopyNewsItem@* 0x0051D350
void __fastcall BNNEWS_CopyNewsItem(D2Storm408ElemStrc* pDst, const D2Storm408ElemStrc* pSrc)
{
    if (pDst)
        *pDst = *pSrc;
}

// 0x00407A80
bool crashy::Report::WriteInspectorHeader()
{
    if (!sub_00401210_IsOpen())
    {
        return false;
    }

    sub_00401380("<Application>%s\n", gtInspectorInfo.szApplication);
    sub_00401380("<Inspector.ProjectId>%d\n", gtInspectorInfo.nProjectId);
    sub_00401380("<Inspector.Module>%s\n", gtInspectorInfo.szModule);
    sub_00401380("<Inspector.Milestone>%s\n", gtInspectorInfo.szMilestone);
    sub_00401380("<Inspector.BuildNumber>%s\n", gtInspectorInfo.szBuildNumber);
    sub_00401380("<Inspector.Platform>%s\n", gtInspectorInfo.szPlatform);
    sub_00401380("<Inspector.IssueType>%s\n", "Exception");
    sub_00401380("<Inspector.Priority>%s\n", "1 - Critical");
    sub_00401380("<Inspector.PrimaryAssignment>%s\n", gtInspectorInfo.szPrimaryAssignment);
    sub_00401380("<Inspector.Assignments>%s\n", gtInspectorInfo.szAssignments);

    int bIsAdmin = 0;
    D2SidAuthorityStrc tNtAuthority = { { 0, 0, 0, 0, 0, 5 } };
    void* pSid;
    if (AllocateAndInitializeSid(&tNtAuthority, 2, 0x20, 0x220, 0, 0, 0, 0, 0, 0, &pSid))
    {
        bIsAdmin = CheckTokenMembership(0, pSid, &bIsAdmin);
        sub_00401380("<Process.UserIsAdmin> %s\n", bIsAdmin ? "TRUE" : "FALSE");
        FreeSid(pSid);
    }
    sub_00401380("<Process.Elevated> %s\n", gszUnknownUpper);

    unsigned long dwProcessId = GetCurrentProcessId();
    bool bFound = ERRORMANAGER_GetProcessImageName(dwProcessId, gszProcessPath, 0x800);
    sub_00401380("<Process.Path> %s\n", bFound ? gszProcessPath : gszUnknownTitle);
    const char* szSlash = strrchr(gszProcessPath, '\\');
    const char* szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.Name> %s\n", (szName && bFound) ? szName : gszUnknownTitle);

    unsigned long dwParentId = ERRORMANAGER_FindParentProcessId(dwProcessId);
    bFound = ERRORMANAGER_GetProcessImageName(dwParentId, gszProcessPath, 0x800);
    sub_00401380("<Process.ParentProcessPath> %s\n", bFound ? gszProcessPath : gszUnknownTitle);
    szSlash = strrchr(gszProcessPath, '\\');
    szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.ParentProcessName> %s\n", (szName && bFound) ? szName : gszUnknownTitle);

    unsigned long dwGrandParentId = ERRORMANAGER_FindParentProcessId(dwParentId);
    bFound = ERRORMANAGER_GetProcessImageName(dwGrandParentId, gszProcessPath, 0x800);
    sub_00401380("<Process.GrandParentProcessPath> %s\n", bFound ? gszProcessPath : gszUnknownTitle);
    szSlash = strrchr(gszProcessPath, '\\');
    szName = szSlash ? szSlash + 1 : 0;
    sub_00401380("<Process.GrandParentProcessName> %s\n", (szName && bFound) ? szName : gszUnknownTitle);

    sub_00401380("<Locale.Game> %s\n", gaszLanguageNames[sub_00525150()]);
    sub_00401380("<Locale.System> %s\n", gaszLanguageNames[STRTABLE_GetSystemLanguage()]);
    sub_00401380("<Game.Type> %s\n", "Client");
    sub_00401380("<Game.Build> %s\n", "79b7ae8fe1e97d05d57ebdc4b65bf012d38c797e");

    char* apszFiles[0x15];
    memset(apszFiles, 0, sizeof(apszFiles));
    LOGMANAGER_GetLogFilePaths(apszFiles, 0x15);
    for (unsigned int i = 0; i < 0x15; ++i)
    {
        if (apszFiles[i] && *apszFiles[i])
        {
            sub_00401220_AddFile(apszFiles[i], true);
        }
    }
    return true;
}

// 0x004068E0
int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile)
{
    return SFileOpenFile(szFileName, phFile);
}

// 0x00406900
int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6)
{
    return SFileReadFileEx2(hFile, pBuffer, nToRead, pnRead, pOverlapped, nArg6, nArg7);
}

// 0x00406930
int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh)
{
    return SFileGetFileSize(hFile, pnSizeHigh);
}

// 0x00406940
int __fastcall FOG_FSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod)
{
    return SFileSetFilePointer(hFile, nOffset, pnOffsetHigh, nMethod);
}

// 0x00406A10
int __fastcall FOG_CreatePathHierarchy(const char* szPath)
{
    int bResult = 1;
    if (!szPath || !*szPath)
    {
        return 0;
    }
    char szDir[0x104];
    const char* pSep = SStrChr(szPath + 1, '\\');
    while (pSep)
    {
        const size_t nLen = pSep - szPath;
        if (nLen >= sizeof(szDir))
        {
            bResult = 0;
            break;
        }
        memcpy(szDir, szPath, nLen);
        szDir[nLen] = 0;
        if (!CreateDirectoryA(szDir, 0))
        {
            const unsigned long dwError = GetLastError();
            if (dwError != 0xB7 && dwError != 5 || !(GetFileAttributesA(szDir) & 0x10))
            {
                bResult = 0;
                break;
            }
        }
        pSep = SStrChr(pSep + 1, '\\');
    }
    return bResult;
}

// 0x00406C40
int __fastcall ERRORMANAGER_GetBlizzardDataPath(char* szOutPath, int nSize)
{
    char szPath[0x104];
    if (SHGetFolderPathA(0, 0x1C, 0, 0, szPath) < 0)
        return 0;
    SStrPack(szPath, "\\Blizzard Entertainment", 0x7FFFFFFF);
    if (!FOG_AppendBackslash(szPath, nSize))
        return 0;
    if (!FOG_CreatePathHierarchy(szPath))
        return 0;
    SStrCopy(szOutPath, szPath, nSize);
    return SStrLen(szOutPath) == SStrLen(szPath);
}

// 0x00406D30
static bool ERRORMANAGER_GetDefaultSavePath(char* szOutPath, unsigned int nMaxLen)
{
    char szPath[0x104];
    if (!nMaxLen)
    {
        return false;
    }
    D2_ASSERT(szOutPath, 68);
    if (ERRORMANAGER_GetKnownFolderPathA(szOutPath, nMaxLen))
    {
        ERRORMANAGER_AppendBackslash(szOutPath, nMaxLen);
        SStrPack(szOutPath, "Diablo II", nMaxLen);
    }
    else
    {
        if (SHGetFolderPathA(0, 5, 0, 0, szPath))
        {
            return false;
        }
        ERRORMANAGER_AppendBackslash(szOutPath, nMaxLen);
        SStrPack(szOutPath, "Diablo II\\Save", nMaxLen);
    }
    return true;
}

// 0x00406DE0
int __fastcall ERRORMANAGER_MoveDirectoryTree(const char* szSrc, const char* szDst)
{
    char szDir[0x104];
    SStrCopy(szDir, szDst, 0x7FFFFFFF);
    char* pCut = strrchr(szDir, '\\') + 1;
    char cSaved = *pCut;
    *pCut = 0;
    FOG_CreatePathHierarchy(szDir);
    *pCut = cSaved;
    if (MoveFileA(szSrc, szDst))
        return 2;
    unsigned long dwAttr = GetFileAttributesA(szSrc);
    if (dwAttr == (unsigned long)-1)
        return GetLastError() == 2 ? 2 : 1;
    if (!(dwAttr & 0x10))
        return 1;
    dwAttr = GetFileAttributesA(szDst);
    if (!(dwAttr & 0x10))
        return 1;
    if (dwAttr == (unsigned long)-1)
    {
        if (GetLastError() != 2)
            return 1;
        FOG_AppendBackslash(szDir, sizeof(szDir));
        FOG_CreatePathHierarchy(szDir);
    }
    char szSrcFind[0x104];
    char szDstFind[0x104];
    int nResult = 0;
    int nSrcLen = SStrPrintf(szSrcFind, 0x104, "%s\\*", szSrc) - 1;
    int nDstLen = SStrPrintf(szDstFind, 0x104, "%s\\", szDst);
    D2FindDataStrc tData;
    void* hFind = FindFirstFileA(szSrcFind, &tData);
    if (hFind != (void*)-1)
    {
        do
        {
            if (strcmp(tData.cFileName, ".") && strcmp(tData.cFileName, ".."))
            {
                SStrCopy(szSrcFind + nSrcLen, tData.cFileName, 0x104 - nSrcLen);
                SStrCopy(szDstFind + nDstLen, tData.cFileName, 0x104 - nDstLen);
                nResult |= ERRORMANAGER_MoveDirectoryTree(szSrcFind, szDstFind);
            }
        } while (FindNextFileA(hFind, &tData));
    }
    FindClose(hFind);
    RemoveDirectoryA(szSrc);
    return nResult;
}

// 0x00407050
int __fastcall FOG_GetSavePath(char* szPath, int nSize)
{
    char szSavePath[0x104];
    char szNewPath[0x104];
    szPath[0] = 0;
    if (!SRegLoadString("Diablo II", "NewSavePath", 1, szPath, nSize) && GetLastError() == 2
        && SRegLoadString("Diablo II", "Save Path", 0, szSavePath, 0x104))
    {
        const size_t nLength = strlen(szSavePath);
        if (szSavePath[nLength - 1] == '\\')
        {
            szSavePath[nLength - 1] = 0;
        }
        const unsigned long dwAttributes = GetFileAttributesA(szSavePath);
        if (dwAttributes != (unsigned long)-1 && (dwAttributes & 0x10))
        {
            if (ERRORMANAGER_GetDefaultSavePath(szNewPath, 0x104))
            {
                if (ERRORMANAGER_MoveDirectoryTree(szSavePath, szNewPath) == 1)
                {
                    SStrCopy(szPath, szSavePath, nSize);
                }
                else
                {
                    AppendPathSeparator_Inl(szNewPath, 0x104);
                    SRegSaveString("Diablo II", "NewSavePath", 1, szNewPath);
                    SStrCopy(szPath, szNewPath, nSize);
                }
            }
        }
    }
    if (GetFileAttributesA(szPath) == (unsigned long)-1)
    {
        szPath[0] = 0;
    }
    if (!szPath[0])
    {
        ERRORMANAGER_GetDefaultSavePath(szPath, nSize);
        AppendPathSeparator_Inl(szPath, nSize);
        SRegSaveString("Diablo II", "NewSavePath", 1, szPath);
    }
    if (!AppendPathSeparator_Inl(szPath, nSize))
    {
        return 0;
    }
    return FOG_CreatePathHierarchy(szPath);
}

// 0x00407260
D2StormArray408Strc* D2StormArray408Strc::sub_0051D690_Init()
{
    m_alloc = 0;
    m_count = 0;
    m_data = 0;
    m_chunk = 0;
    return this;
}

// 0x00407370
int __fastcall ERRORMANAGER_GetJulianDay(int nYear, int nMonth, int nDay)
{
    int nJulYear = nYear;
    if (nJulYear == 0)
    {
        return 0;
    }
    if (nJulYear < 0)
    {
        ++nJulYear;
    }
    int nJulMonth;
    if (nMonth > 2)
    {
        nJulMonth = nMonth + 1;
    }
    else
    {
        --nJulYear;
        nJulMonth = nMonth + 13;
    }
    int nJul = (int)(floor(gdDaysPerYear * nJulYear) + floor(gdDaysPerMonth * nJulMonth) + nDay + 1720995.0);
    if (nDay + 31 * (nMonth + 12 * nYear) >= 588829)
    {
        const int nAdjust = (int)(0.01 * nJulYear);
        nJul += 2 - nAdjust - (int)((-0.25) * nAdjust);
    }
    return nJul;
}

// 0x00407570
void __fastcall ERRORMANAGER_DeleteOldDatedLogs(const char* szPrefix)
{
    D2SystemTimeStrc tTime;
    char szDir[0x1000];
    char szFile[0x1000];
    GetLocalTime(&tTime);
    szDir[0] = 0;
    if (EXCEPTIONS_GetAppPath(szDir, 0x1000))
    {
        SStrPack(szDir, "\\", 0x1000);
        FOG_CreatePathHierarchy(szDir);
    }
    int nYear = tTime.wYear;
    int nMonth = tTime.wMonth;
    int nDay = tTime.wDay;
    int nJulianDay = ERRORMANAGER_GetJulianDay(nYear, nMonth, nDay) - 5;
    for (int i = 0; i < 10; i++)
    {
        ERRORMANAGER_JulianDayToDate(nJulianDay, &nYear, &nMonth, &nDay);
        SStrPrintf(szFile, 0x1000, "%s%s%02d%02d%02d.txt", szDir, szPrefix, nYear % 100, nMonth, nDay);
        DeleteFileA(szFile);
        nJulianDay--;
    }
}

void __stdcall sub_K01_Emit_00407FC0(const char* szPrefix, const char* szText, int bFlag)
{
    ERRORMANAGER_LogPrefixedText(szPrefix, szText, bFlag);
}

// 0x004013C0
void __fastcall ERRORMANAGER_TerminateCurrentProcess(unsigned int nExitCode)
{
    TerminateProcess(GetCurrentProcess(), nExitCode);
}

int sgfAsyncDataEnabled; // 0x0075AF94

// 0x004013D0
int __cdecl ERRORMANAGER_GetProcessThreadCount()
{
    const unsigned long dwProcessId = GetCurrentProcessId();
    void* hSnapshot = CreateToolhelp32Snapshot(0x0F, 0);
    D2ProcessEntryWStrc tEntry = { 0 };
    tEntry.dwSize = sizeof(tEntry);
    int bFound = Process32FirstW(hSnapshot, &tEntry);
    while (bFound && tEntry.th32ProcessID != dwProcessId)
    {
        bFound = Process32NextW(hSnapshot, &tEntry);
    }
    CloseHandle(hSnapshot);
    if (bFound)
    {
        return tEntry.cntThreads;
    }
    return -1;
}

// 0x00401690
unsigned long __cdecl ERRORMANAGER_GetCurrentThreadId()
{
    return GetCurrentThreadId();
}

// 0x00401740
void __fastcall ERRORMANAGER_SetReportText(const char* szText)
{
    char* pDest = gszTextBuffer;
    const char* pSource = szText;
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
    if ((size_t)(pSource - szText - 1) >= 0x400)
    {
        gszTextBuffer[0] = 0;
    }
}

// build: symbol ?strrchr@@YAPADPADH@Z 0x00401A30
char* __cdecl strrchr(char* szString, int nChar)
{
    return strrchr((const char*)szString, nChar);
}

// 0x00401A40
void* __stdcall ERRORMANAGER_LockSymbols(void* pArg)
{
    EnterCriticalSection(&gtSymbolLock);
    return pArg;
}

// 0x00402C10
int __cdecl ERRORMANAGER_CompareUInt(const void* p1, const void* p2)
{
    const unsigned int a = *(const unsigned int*)p1;
    const unsigned int b = *(const unsigned int*)p2;
    if (a > b)
    {
        return 1;
    }
    if (a < b)
    {
        return -1;
    }
    return 0;
}

// 0x00403A20
void __fastcall ERRORMANAGER_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId)
{
    D2ThreadEntryStrc tEntry = {};
    tEntry.dwSize = sizeof(tEntry);
    void* hSnapshot = CreateToolhelp32Snapshot(4, 0);
    if (hSnapshot == (void*)-1)
    {
        return;
    }
    const unsigned long dwProcessId = GetCurrentProcessId();
    if (Thread32First(hSnapshot, &tEntry))
    {
        do
        {
            if (tEntry.th32OwnerProcessID == dwProcessId && tEntry.th32ThreadID != dwSkipThreadId)
            {
                ERRORMANAGER_DumpThread(tEntry.th32ThreadID, 0, pfnPrint, pContext, 1, 1, 0);
                pfnPrint(pContext, gszNewline);
            }
        }
        while (Thread32Next(hSnapshot, &tEntry));
    }
    CloseHandle(hSnapshot);
}

// 0x00403F60
void __fastcall ERRORMANAGER_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused)
{
    gpfnCrashHandler = pfnHandler;
    gpCrashContext = pContext;
    if (!pfnHandler)
    {
        if (gpfnPreviousFilter)
        {
            SetUnhandledExceptionFilter(gpfnPreviousFilter);
            gpfnPreviousFilter = 0;
        }
    }
    else
    {
        gpfnPreviousFilter = SetUnhandledExceptionFilter(sub_00403E90_UnhandledExceptionFilter);
    }
}

// 0x00404210
bool __fastcall ERRORMANAGER_CreateProcessUtf8(const char* szApplicationName, const char* szCommandLine)
{
    wchar_t wszCmdLine[0x8000];
    wchar_t wszApp[0x400];
    if (!szCommandLine || MultiByteToWideChar(0xFDE9, 0, szCommandLine, -1, wszCmdLine, 0x8000))
    {
        if (!szApplicationName || MultiByteToWideChar(0xFDE9, 0, szApplicationName, -1, wszApp, 0x400))
        {
            D2ProcessInformationStrc tInfo;
            D2StartupInfoWStrc tStartup = { sizeof(tStartup) };
            memset(&tInfo, 0, sizeof(tInfo));
            if (CreateProcessW(szApplicationName ? wszApp : 0, szCommandLine ? wszCmdLine : 0, 0, 0, 0, 0, 0, 0, &tStartup, &tInfo))
            {
                CloseHandle(tInfo.hProcess);
                CloseHandle(tInfo.hThread);
                return true;
            }
        }
    }
    return false;
}

// 0x004043C0
_iobuf* __stdcall ERRORMANAGER_OpenFileForWriteUtf8(const char* szPath)
{
    wchar_t wszPath[0x104];
    wchar_t wszMode[0x20];
    if (!MultiByteToWideChar(0xFDE9, 0, szPath, -1, wszPath, 0x104))
    {
        return 0;
    }
    if (!MultiByteToWideChar(0xFDE9, 0, "w", -1, wszMode, 0x20))
    {
        return 0;
    }
    return _wfopen(wszPath, wszMode);
}

// 0x00404560
bool __fastcall ERRORMANAGER_CreateDirectoryWide(wchar_t* wszPath)
{
    if (CreateDirectoryW(wszPath, 0))
    {
        return true;
    }
    const unsigned long dwAttributes = GetFileAttributesW(wszPath);
    if (dwAttributes != (unsigned long)-1)
    {
        return (dwAttributes & 0x10) != 0;
    }
    wchar_t* pSeparator = wcsrchr(wszPath, L'\\');
    if (wcsrchr(wszPath, L'/') > pSeparator)
    {
        pSeparator = wcsrchr(wszPath, L'/');
    }
    if (!pSeparator)
    {
        return false;
    }
    *pSeparator = 0;
    if (!ERRORMANAGER_CreateDirectoryWide(wszPath))
    {
        return false;
    }
    *pSeparator = L'\\';
    return CreateDirectoryW(wszPath, 0) != 0;
}

// 0x00405570
int __stdcall GetCmdIndex(const char* s)
{
    for (size_t i = 0; i < ARRAY_SIZE(gaCmdArguments); i++)
    {
        if (0 == strcmp(gaCmdArguments[i].szCommand, s))
        {
            return (int)i;
        }
    }
    return -1;
}

// 0x004055D0
int __fastcall ERRORMANAGER_IsCmdSeparator(char c)
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

// 0x00407360
D2FogSystemInfoStrc* __cdecl FOG_GetSystemInfo()
{
    return gtSystemInfo_0074D88C.bCaptured ? &gtSystemInfo_0074D88C : 0;
}

// 0x00407440
void __fastcall ERRORMANAGER_JulianDayToDate(long nJulian, int* pYear, int* pMonth, int* pDay)
{
    long ja;
    if (nJulian >= 588829)
    {
        const long jalpha = (long)(((double)(nJulian - 1867216) - 0.25) / 36524.25);
        ja = nJulian + 1 + jalpha - (long)(0.25 * jalpha);
    }
    else
    {
        ja = nJulian;
    }
    const long jb = ja + 1524;
    const long jc = (long)(6680.0 + ((double)(jb - 2439870) - 122.1) / 365.25);
    const long jd = (long)(365 * jc + (0.25 * jc));
    const long je = (long)((jb - jd) / 30.6001);
    *pDay = jb - jd - (long)(30.6001 * je);
    *pMonth = je - 1;
    if (*pMonth > 12)
    {
        *pMonth -= 12;
    }
    *pYear = jc - 4715;
    if (*pMonth > 2)
    {
        *pYear -= 1;
    }
    if (*pYear <= 0)
    {
        *pYear -= 1;
    }
}

// 0x00407960
void __fastcall FOG_SetLogPrefix(const char* szLogPrefix)
{
    LOGMANAGER_SetLogPrefix(szLogPrefix);
}

// 0x00407A20
bool __fastcall ERRORMANAGER_GetProcessImageName(unsigned long dwProcessId, char* szName, unsigned long nSize)
{
    bool bResult;
    void* hProcess = OpenProcess(0x410, 0, dwProcessId);
    if (hProcess && GetModuleFileNameExA(hProcess, 0, szName, nSize))
    {
        bResult = true;
    }
    else
    {
        bResult = false;
    }
    CloseHandle(hProcess);
    return bResult;
}

// 0x00408050
void __cdecl sub_00408050_Empty()
{
}

// 0x00408060
void __cdecl sub_00408060_Empty()
{
}

// 0x00408070
void __cdecl sub_00408070_Empty()
{
}

// 0x00408080
void __cdecl sub_00408080_Empty()
{
}

static int sub_00406BA0_GetModuleDirectoryAndSave(char* szPath, unsigned int nSize)
{
    const unsigned long nLength = GetModuleFileNameA(0, szPath, nSize);
    if (nLength && nLength != nSize)
    {
        char* pSlash = (char*)SStrChrR(szPath, '\\');
        if (pSlash)
        {
            pSlash[1] = 0;
        }
        SRegSaveString("Diablo II", "InstallPath", 0, szPath);
        return 1;
    }
    return 0;
}

// 0x004080B0
static __declspec(noinline) void __stdcall ERRORMANAGER_DebugPrintV(unsigned int nFlags, const char* szFormat, va_list args)
{
    char szBuffer[0x1000];
    szBuffer[0] = 0;
    if (nFlags & 4)
    {
        D2SystemTimeStrc tTime;
        GetLocalTime(&tTime);
        _snprintf(szBuffer, 0x1000, "%02d:%02d:%02d.%03d    ", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
    }
    const size_t nLength = strlen(szBuffer);
    _vsnprintf(&szBuffer[nLength], 0x1000 - nLength, szFormat, args);
    szBuffer[0xFFF] = 0;
    if (!(nFlags & 2))
    {
        OutputDebugStringA(szBuffer);
    }
    if (nFlags & 1)
    {
// build: symbol ?LOGMANAGER_LogWritePrefixed@* 0x00410740
        LOGMANAGER_LogWritePrefixed("LOG", gszPercentS_006FFC58, szBuffer);
    }
    if (nFlags & 0x18)
    {
        GetKeyState(0x14);
    }
}

// 0x004081A0
void __cdecl ERRORMANAGER_DebugPrintf(const char* szFormat, ...)
{
    char szBuffer[0x1000];
    szBuffer[0] = 0;
    const size_t nLength = strlen(szBuffer);
    va_list args;
    va_start(args, szFormat);
    _vsnprintf(&szBuffer[nLength], sizeof(szBuffer) - nLength, szFormat, args);
    szBuffer[sizeof(szBuffer) - 1] = 0;
    OutputDebugStringA(szBuffer);
}

// 0x00408220
void __cdecl ERRORMANAGER_DebugPrintfIfCapsLock(const char* szFormat, ...)
{
    if (GetAsyncKeyState(0x14) & 1)
    {
        char szBuffer[0x1000];
        szBuffer[0] = 0;
        const size_t nLength = strlen(szBuffer);
        va_list args;
        va_start(args, szFormat);
        _vsnprintf(&szBuffer[nLength], sizeof(szBuffer) - nLength, szFormat, args);
        szBuffer[sizeof(szBuffer) - 1] = 0;
        OutputDebugStringA(szBuffer);
    }
}

// 0x004082A0
void __cdecl ERRORMANAGER_DebugPrintFlags(unsigned int nFlags, const char* szFormat, ...)
{
    ERRORMANAGER_DebugPrintV(nFlags, szFormat, (va_list)(&szFormat + 1));
}

// 0x004082C0
void __cdecl ERRORMANAGER_DebugPrintLog(const char* szFormat, ...)
{
    ERRORMANAGER_DebugPrintV(1, szFormat, (va_list)(&szFormat + 1));
}

// 0x00409770
void* __fastcall ERRORMANAGER_PoolAllocLarge(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine)
{
    int* pBlock = (int*)malloc(nSize + 4);
    if (!pBlock)
    {
        ERRORMANAGER_LogPoolError("(3) Pool Blocks overflowed at %d", pSystem->nPoolBlocks);
        D2_ASSERT(pBlock, 904);
    }
    const int nBucket = (int)pBlock % 1023;
    EnterCriticalSection(&pSystem->tLock);
    *pBlock = (int)pSystem->apLargeBlocks[nBucket];
    pSystem->apLargeBlocks[nBucket] = pBlock;
    LeaveCriticalSection(&pSystem->tLock);
    return pBlock + 1;
}

// 0x00409810
void __fastcall ERRORMANAGER_PoolFreeLarge(D2PoolSystemStrc* pSystem, int* pBlock, const char* szFile, int nLine)
{
    pBlock -= 1;
    const int nBucket = (int)pBlock % 1023;
    int* pPrev = 0;
    EnterCriticalSection(&pSystem->tLock);
    for (int* pEntry = pSystem->apLargeBlocks[nBucket]; pEntry; pEntry = (int*)*pEntry)
    {
        if (pEntry == pBlock)
        {
            if (!pPrev)
            {
                pSystem->apLargeBlocks[nBucket] = (int*)*pEntry;
            }
            else
            {
                *pPrev = *pEntry;
            }
            LeaveCriticalSection(&pSystem->tLock);
            free(pBlock);
            return;
        }
        pPrev = pEntry;
    }
    LeaveCriticalSection(&pSystem->tLock);
    free(pBlock);
}

void __cdecl ERRORMANAGER_ForceCrash(); // 0x00407970

// 0x0040ABF0
void __fastcall ERRORMANAGER_HeapSiftDown(int* pHeap, int nCount, int nIndex)
{
    int nValue = pHeap[nIndex];
    int nHalf = nCount / 2;
    nCount -= 1;
    while (nIndex < nHalf)
    {
        int nChild = 2 * nIndex + 1;
        if (nChild < nCount && pHeap[nChild] < pHeap[nChild + 1])
            nChild += 1;
        if (nValue > pHeap[nChild])
            break;
        pHeap[nIndex] = pHeap[nChild];
        nIndex = nChild;
    }
    pHeap[nIndex] = nValue;
}

// 0x0040AC60
void __fastcall ERRORMANAGER_HeapSort(int* pHeap, int nCount)
{
    for (int i = nCount / 2; i;)
    {
        --i;
        ERRORMANAGER_HeapSiftDown(pHeap, nCount, i);
    }
    while (--nCount)
    {
        const int nTop = pHeap[0];
        pHeap[0] = pHeap[nCount];
        pHeap[nCount] = nTop;
        ERRORMANAGER_HeapSiftDown(pHeap, nCount, 0);
    }
}

// 0x0040ACA0
void __fastcall ERRORMANAGER_CalcCodeLengths(int* pA, int nCount)
{
    int nRoot, nLeaf, nNext, nAvail, nUsed, nDepth;
    if (nCount == 0)
        return;
    if (nCount == 1)
    {
        pA[0] = 0;
        return;
    }
    pA[0] += pA[1];
    nRoot = 0;
    nLeaf = 2;
    for (nNext = 1; nNext < nCount - 1; nNext++)
    {
        if (nLeaf >= nCount || pA[nRoot] < pA[nLeaf])
        {
            pA[nNext] = pA[nRoot];
            pA[nRoot++] = nNext;
        }
        else
            pA[nNext] = pA[nLeaf++];
        if (nLeaf >= nCount || (nRoot < nNext && pA[nRoot] < pA[nLeaf]))
        {
            pA[nNext] += pA[nRoot];
            pA[nRoot++] = nNext;
        }
        else
            pA[nNext] += pA[nLeaf++];
    }
    pA[nCount - 2] = 0;
    for (nNext = nCount - 3; nNext >= 0; nNext--)
        pA[nNext] = pA[pA[nNext]] + 1;
    nAvail = 1;
    nUsed = nDepth = 0;
    nRoot = nCount - 2;
    nNext = nCount - 1;
    while (nAvail > 0)
    {
        while (nRoot >= 0 && pA[nRoot] == nDepth)
        {
            nUsed++;
            nRoot--;
        }
        while (nAvail > nUsed)
        {
            pA[nNext--] = nDepth;
            nAvail--;
        }
        nAvail = 2 * nUsed;
        nDepth++;
        nUsed = 0;
    }
}

// 0x0040ADA0
void __cdecl sub_0040ADA0_Nop()
{
}

typedef unsigned char Byte;

extern Byte gnSymbolCodes_0075B6A0[256]; // 0x0075B6A0
extern Byte* gpDecodeTable_0075AFA0[256]; // 0x0075AFA0
extern Byte gabDecodeStorage[768]; // 0x0075B3A0

static inline int IsValidCodeLength(Byte length)
{
    if (length <= 0)
        return 0;
    if (length >= 16)
        return 0;
    return 1;
}

// 0x0040ADB0
int __fastcall FOG_10219(Byte* lengths)
{
    int counts[16];
    Byte sortedSymbols[256];
    Byte sortedLengths[256];
    int i;
    for (i = 0; i < 16; ++i)
        counts[i] = 0;
    i = 0;
    for (; i < 256; ++i)
    {
        if (!IsValidCodeLength(lengths[i]))
            return 0;
        ++counts[lengths[i]];
    }
    for (int length = 15; length > 0; --length)
    {
        int count = counts[length];
        counts[length] = counts[0];
        counts[0] += count;
    }
    i = 0;
    for (; i < 256; ++i)
        sortedSymbols[counts[lengths[i]]++] = (Byte)i;
    i = 0;
    for (; i < 256; ++i)
    {
        sortedLengths[i] = lengths[sortedSymbols[i]];
        gabHuffmanCodeLength[i] = lengths[i];
    }
    gnSymbolCodes_0075B6A0[sortedSymbols[0]] = 0;
    for (i = 1; i < 256; ++i)
        gnSymbolCodes_0075B6A0[sortedSymbols[i]] =
            (Byte)((gnSymbolCodes_0075B6A0[sortedSymbols[i - 1]] + 1) >> (sortedLengths[i - 1] - sortedLengths[i]));
    Byte* storage = gabDecodeStorage;
    for (i = 255; i >= 0; --i)
    {
        Byte length = sortedLengths[i];
        if (length <= 8)
        {
            Byte symbol = sortedSymbols[i];
            int prefix = gnSymbolCodes_0075B6A0[symbol] << (8 - length);
            int count = 1u << (8 - length);
            Byte** ppEntry = &gpDecodeTable_0075AFA0[prefix];
            *ppEntry = storage;
            storage[0] = 0;
            (*ppEntry)[1] = symbol;
            storage += 2;
            for (int j = 0; j < count; ++j)
                gpDecodeTable_0075AFA0[prefix + j] = *ppEntry;
        }
        else
        {
            Byte* pSymbol = &sortedSymbols[i];
            unsigned int code = gnSymbolCodes_0075B6A0[*pSymbol];
            unsigned int prefix = code >> ((Byte)(length - 8));
            if ((code & ((1 << (length - 8)) - 1)) == 0)
            {
                int count = 1 << (length - 8);
                gpDecodeTable_0075AFA0[prefix] = storage;
                *storage++ = ((Byte)(length - 8));
                int j = 0;
                int n = 0;
                while (j < count)
                {
                    int repeat = 1 << (length - sortedLengths[i + j]);
                    if (repeat)
                    {
                        Byte value = pSymbol[n];
                        storage += repeat;
                        do
                        {
                            gpDecodeTable_0075AFA0[prefix][j + 1] = value;
                            ++j;
                        } while (--repeat);
                    }
                    ++n;
                }
            }
        }
    }
    return 1;
}

unsigned __int64 gaqHuffmanByteCounts[256];                                                        // 0x0075B7A0
unsigned __int64 gqHuffmanBytesIn;                                                                 // 0x0075BFA0
unsigned __int64 gqHuffmanBytesOut;                                                                // 0x0075BFA8
unsigned __int64 gqHuffmanHeaders;                                                                 // 0x0075BFB0

static inline void AddTotal(unsigned __int64* pTotal, unsigned __int64 nValue)
{
    *pTotal += nValue;
}

// 0x0040B0C0
void __cdecl FOG_10218()
{
    for (int i = 0; i < 256; i++)
        gaqHuffmanByteCounts[i] = 0;
    gqHuffmanBytesIn = 0;
    gqHuffmanBytesOut = 0;
    gqHuffmanHeaders = 0;
    FOG_10219(gabHuffmanCodeLength);
}

// 0x0040B110
void __cdecl sub_0040B110_Nop()
{
}

// 0x0040B120
void __cdecl sub_0040B120_Nop()
{
}

// 0x0040B130
void __fastcall FOG_10222(const unsigned char* pData, unsigned int nSize)
{
    unsigned int i = 0;
    unsigned int nBits = 0;
    for (; i < nSize; i++)
    {
        const unsigned char nByte = pData[i];
        ++gaqHuffmanByteCounts[nByte];
        nBits += gabHuffmanCodeLength[nByte];
    }
    unsigned int nHeader = 1;
    unsigned int nBytes = ((nBits + 7) >> 3) + nHeader;
    if (nBytes >= 0xF0)
    {
        nBytes += nHeader;
        nHeader = 2;
    }
    AddTotal(&gqHuffmanBytesIn, nSize);
    AddTotal(&gqHuffmanBytesOut, nBytes);
    AddTotal(&gqHuffmanHeaders, nHeader);
}

// 0x0040B1B0
int __fastcall FOG_CompressPacket(unsigned char* pOut, int nOutSize, const unsigned char* pIn, int nInSize)
{
    unsigned char* pStart = pOut;
    unsigned char nAcc = 0;
    int nFree = 8;
    while (nInSize)
    {
        const unsigned char c = *pIn;
        nInSize--;
        pIn++;
        int nBits = gabHuffmanCodeLength[c];
        const unsigned int nCode = gabHuffmanCode[c];
        while (nBits >= nFree)
        {
            nBits -= nFree;
            if (nOutSize-- == 0)
            {
                return 0;
            }
            *pOut++ = (unsigned char)(nCode >> nBits) | nAcc;
            nFree = 8;
            nAcc = 0;
        }
        if (nBits)
        {
            nFree -= nBits;
            nAcc |= (unsigned char)(nCode << nFree);
        }
    }
    if (nFree < 8)
    {
        if (nOutSize-- == 0)
        {
            return 0;
        }
        *pOut++ = nAcc;
    }
    return pOut - pStart;
}

// 0x0040B260
int __fastcall FOG_DecompressPacket(unsigned char* pOut, int nOutSize, const unsigned char* pIn, unsigned int nInSize)
{
    unsigned char* pStart = pOut;
    unsigned int nWindow = 0;
    int nEmpty = 32;
    for (;;)
    {
        while (nEmpty >= 8 && nInSize > 0)
        {
            nEmpty -= 8;
            nWindow |= *pIn << nEmpty;
            nInSize--;
            pIn++;
        }
        const unsigned char* pEntry = gapHuffmanDecode[nWindow >> 24];
        const unsigned int nLookup = pEntry[0];
        const unsigned char c = pEntry[((nWindow >> (24 - nLookup)) & gadwHuffmanMask[nLookup]) + 1];
        const int nLength = gabHuffmanCodeLength[c];
        nEmpty += nLength;
        if (nEmpty > 32)
        {
            return pOut - pStart;
        }
        if (nOutSize-- == 0)
        {
            return 0;
        }
        *pOut++ = c;
        nWindow <<= nLength;
    }
}

void* __fastcall ERRORMANAGER_PoolRealloc(D2PoolSystemStrc* pPool, void* pMemory, int nSize, const char* szFile, int nLine); // 0x0040A1F0

extern float gafSinTable[]; // 0x00707800

extern int gbUsePools; // 0x00708000

// 0x0040B320
void __cdecl FOG_10082_Noop()
{
}

// 0x0040B330
float __stdcall FOG_10083_Cos_LUT(int nAngle)
{
    return gafSinTable[(nAngle + 128) & 511];
}

// 0x0040B350
float __stdcall FOG_10084_Sin_LUT(int nAngle)
{
    return gafSinTable[nAngle & 511];
}

// 0x0040B370
void __fastcall ERRORMANAGER_SetUsePools(int bUsePools)
{
    gbUsePools = bUsePools;
}

// 0x0040B380
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0)
{
    void* pMemory = ERRORMANAGER_PoolAlloc(0, nSize, szFile, nLine);
    if (!pMemory)
    {
        ERRORMANAGER_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pMemory;
}

// 0x0040B3C0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0)
{
    ERRORMANAGER_PoolFree(0, &pFree, szFile, nLine);
    return 1;
}

// 0x0040B3F0
void* __fastcall FOG_Realloc(void* pMemory, int nSize, const char* szFile, int nLine, int n0)
{
    void* pNew = ERRORMANAGER_PoolRealloc(0, pMemory, nSize, szFile, nLine);
    if (!pNew)
    {
        ERRORMANAGER_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pNew;
}

// 0x0040B430
void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0)
{
    void* pMemory = ERRORMANAGER_PoolAlloc(gbUsePools ? pMemPool : 0, nSize, szFile, nLine);
    if (!pMemory)
    {
        ERRORMANAGER_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pMemory;
}

// 0x0040B480
int __fastcall FOG_FreePool(D2PoolSystemStrc* pMemPool, void* pFree, const char* szFile, int nLine, int n0)
{
    ERRORMANAGER_PoolFree(gbUsePools ? pMemPool : 0, &pFree, szFile, nLine);
    return 1;
}

// 0x0040B4B0
void* __fastcall FOG_ReallocPool(D2PoolSystemStrc* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0)
{
    void* pNew = ERRORMANAGER_PoolRealloc(gbUsePools ? pMemPool : 0, pMemory, nSize, szFile, nLine);
    if (!pNew)
    {
        ERRORMANAGER_RaiseErrorReport(2, szFile, nLine, &gszEmptyAssertText);
    }
    return pNew;
}

// 0x004068F0
int __fastcall FOG_FCloseFile(void* pArg)
{
    return SFileCloseFile(pArg);
}

// 0x00406960
void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile)
{
    return CreateFileA(szFileName, dwDesiredAccess, dwShareMode, pSecurityAttributes, dwCreationDisposition, dwFlagsAndAttributes, hTemplateFile);
}

// 0x00406990
int __fastcall FOG_DeleteFileA(const char* szFileName)
{
    return DeleteFileA(szFileName);
}

// 0x004069A0
int __fastcall FOG_CloseFile(void* hFile)
{
    return CloseHandle(hFile);
}

// 0x004069B0
int __fastcall FOG_ReadFile(void* hFile, void* pBuffer, unsigned long nToRead, unsigned long* pnRead, void* pOverlapped)
{
    return ReadFile(hFile, pBuffer, nToRead, pnRead, pOverlapped);
}

// 0x004069D0
int __fastcall FOG_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped)
{
    return WriteFile(hFile, pBuffer, nToWrite, pnWritten, pOverlapped);
}

// 0x004069F0
unsigned long __fastcall FOG_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod)
{
    return SetFilePointer(hFile, nDistance, pnDistanceHigh, dwMoveMethod);
}

// 0x00408900
void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...)
{
    char szMessage[0x1000];
    char szText[0x1000];
    const int nErrorType = nType;
    if (nErrorType == 10)
    {
        szFile = ".\\Src\\ErrorManager.cpp";
    }
    if (ERRORMANAGER_ReportNestedError(szFile, nLine, szFormat))
    {
        return;
    }
    gbWritingCrashReport = 1;
    if (!szFormat)
    {
        szFormat = "<no reason given>";
    }
    LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, gszStringFormat, "---finished error callback---\n");
    LOGMANAGER_CloseLogFiles();
    int bFatal = nErrorType == 5 || nErrorType == 6 || nErrorType == 2;
    if (!sub_004013A0_IsDebuggerAttached())
    {
        va_list args;
        va_start(args, szFormat);
        SStrPrintf(szMessage, sizeof(szMessage), szFormat, args);
// build: symbol ?gaszErrorTypeNames@* 0x00706654
        SStrPrintf(szText, sizeof(szText), "[%s] (%s) failed at %s(%i)", gaszErrorTypeNames[nErrorType], szMessage, ERRORMANAGER_StripSourcePath(szFile), nLine);
        ERRORMANAGER_ShowErrorReport(szText, szMessage, 0, 0, nLine, 0);
    }
    if (!bFatal)
    {
        gbWritingCrashReport = 0;
    }
}

// 0x00408000
const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile)
{
    if (gnSourcePrefixLength == 0)
    {
        const int nLength = SStrLen(".\\Src\\ErrorManager.cpp");
        gnSourcePrefixLength = nLength - SStrLen("Fog\\Src\\ErrorManager.cpp");
        if (gnSourcePrefixLength < 0)
        {
            gnSourcePrefixLength = 0;
        }
    }
    if (SStrLen(szFile) > (unsigned int)gnSourcePrefixLength)
    {
        return szFile + gnSourcePrefixLength;
    }
    return szFile;
}

// 0x00408660
bool __fastcall ERRORMANAGER_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag)
{
    crashy::Report tReport;
    const long nBusy = InterlockedIncrement(&gnCrashReportBusy);
    if (nBusy != 0)
    {
        gbWritingCrashReport = 0;
        InterlockedDecrement(&gnCrashReportBusy);
        return false;
    }

    gbWritingCrashReport = 1;
    if (!tReport.OpenReport("Crash.txt"))
    {
        gbWritingCrashReport = 0;
        InterlockedDecrement(&gnCrashReportBusy);
        return false;
    }

    tReport.WriteInspectorHeader();
    tReport.sub_00401380("<Inspector.Summary:>\n%s\n<:Inspector.Summary>\n", szSummary);
    if (nLine > 0)
    {
        tReport.sub_00401380("<Inspector.LineNumber>%u\n", nLine);
    }
    tReport.sub_00401380("<Inspector.Assertion:>\n");
    const unsigned long dwThreadId = GetCurrentThreadId();
    ERRORMANAGER_DumpThread(dwThreadId, 0, ERRORMANAGER_ReportPrint, &tReport, nBusy, 1, 4);
    tReport.sub_00401380("<:Inspector.Assertion>\n");
    tReport.sub_00401380("Registers:\n");
    sub_004032F0_DumpRegisters(dwThreadId, ERRORMANAGER_ReportPrint, &tReport);
    tReport.sub_00401380("Threads:\n");
    ERRORMANAGER_DumpOtherThreads(ERRORMANAGER_ReportPrint, &tReport, dwThreadId);

    const char** ppszEnd = ppszFiles + nFiles;
    for (const char** ppszFile = ppszFiles; ppszFile != ppszEnd; ++ppszFile)
    {
        tReport.sub_00401220_AddFile(*ppszFile, true);
    }
    tReport.sub_004011F0_Close();

    D2CrashSubmitInfoStrc tInfo;
    memset(&tInfo, 0, sizeof(tInfo));
    tInfo.szName = gtInspectorInfo.szUnused04;
    if (bFlag)
    {
        tInfo.dwFlags |= 1;
    }
    for (int i = 0; i < tReport.m_nLineCount; i++)
    {
        if (i < sizeof(tInfo.apszLines) / sizeof(tInfo.apszLines[0]))
        {
            tInfo.apszLines[i] = tReport.m_aszLines[i];
            tInfo.nLines++;
        }
    }

    const bool bResult = sub_00401790_SubmitReport(tReport.m_szText08, &tInfo);
    gbWritingCrashReport = 0;
    InterlockedDecrement(&gnCrashReportBusy);
    return bResult;
}

// 0x00406B20
int __fastcall ERRORMANAGER_AppendBackslash(char* szPath, unsigned int nSize)
{
    if (szPath && nSize)
    {
        const unsigned int nLength = SStrLen(szPath);
        if (nLength > 0 && szPath[nLength - 1] == '\\')
        {
            return 1;
        }
        if (nLength + 1 != nSize)
        {
            szPath[nLength] = '\\';
            szPath[nLength + 1] = 0;
            return 1;
        }
    }
    return 0;
}

// 0x00406B60
int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize)
{
    const unsigned long nLength = GetModuleFileNameA(0, szPath, nSize);
    if (nLength && nLength != nSize)
    {
        char* pSlash = (char*)SStrChrR(szPath, '\\');
        if (pSlash)
        {
            pSlash[1] = 0;
        }
        return 1;
    }
    return 0;
}

// 0x00406BA0
int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize)
{
    if (!SRegLoadString("Diablo II", "InstallPath", 0, szPath, nSize))
    {
        szPath[0] = 0;
    }
    if (GetFileAttributesA(szPath) == (unsigned long)-1)
    {
        szPath[0] = 0;
    }
    if ((szPath[0] || sub_00406BA0_GetModuleDirectoryAndSave(szPath, nSize)) && nSize)
    {
        const unsigned int nLength = SStrLen(szPath);
        if (nLength > 0 && szPath[nLength - 1] == '\\')
        {
            return 1;
        }
        if (nLength + 1 != nSize)
        {
            szPath[nLength] = '\\';
            szPath[nLength + 1] = 0;
            return 1;
        }
    }
    return 0;
}

// 0x00407310
char* __cdecl ERRORMANAGER_Sprintf(char* szDest, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    vsprintf(szDest, szFormat, args);
    return szDest;
}

// 0x00407330
char* __cdecl ERRORMANAGER_SprintfN(char* szDest, int nSize, const char* szFormat, ...)
{
    va_list args;
    va_start(args, szFormat);
    _vsnprintf(szDest, nSize, szFormat, args);
    szDest[nSize - 1] = 0;
    return szDest;
}

// 0x0040E250
int __cdecl ERRORMANAGER_GetCpuVendor()
{
    char szVendor[16];
    memset(szVendor, 0, sizeof(szVendor));
    __asm
    {
        mov eax, 0
        cpuid
        mov dword ptr szVendor[0], ebx
        mov dword ptr szVendor[4], edx
        mov dword ptr szVendor[8], ecx
    }
    if (!strcmp(szVendor, "GenuineIntel")) return 1;
    if (!strcmp(szVendor, "AuthenticAMD")) return 2;
    return !strcmp(szVendor, "CyrixInstead") ? 3 : 0;
}

// 0x0040E870
int __stdcall ERRORMANAGER_MeasureCpuMHz()
{
    int nPriority = GetThreadPriority(GetCurrentThread());
    if (nPriority != 0x7FFFFFFF)
    {
        SetThreadPriority(GetCurrentThread(), nPriority);
    }
    const unsigned long dwStart = GetTickCount();
    __int64 tCount1;
    QueryPerformanceCounter(&tCount1);
    const __int64 nTsc1 = AUTOMAP_ReadTimeStampCounter();
    while (GetTickCount() - dwStart < 10)
    {
        Sleep(0);
    }
    nPriority = GetThreadPriority(GetCurrentThread());
    if (nPriority != 0x7FFFFFFF)
    {
        SetThreadPriority(GetCurrentThread(), nPriority);
    }
    __int64 tCount2;
    QueryPerformanceCounter(&tCount2);
    const __int64 nTsc2 = AUTOMAP_ReadTimeStampCounter();
    GetTickCount();
    __int64 tFrequency;
    QueryPerformanceFrequency(&tFrequency);
    return (int)((nTsc2 - nTsc1) * tFrequency / (tCount2 - tCount1) / 1000000);
}

// 0x0040E960
__declspec(noinline) unsigned int __cdecl ERRORMANAGER_GetCpuSignature()
{
    unsigned int nSignature;
    __asm
    {
        mov eax, 1
        cpuid
        mov nSignature, eax
    }
    return nSignature;
}

// 0x0040E980
unsigned int __cdecl ERRORMANAGER_GetCpuBrandIndex()
{
    unsigned int nResult = 0;
    const unsigned int nSignature = ERRORMANAGER_GetCpuSignature();
    const unsigned int nFamily = (nSignature >> 8) & 0xF;
    if (ERRORMANAGER_GetCpuVendor() == 1 && (nFamily >= 7 || (nFamily == 6 && (nSignature & 0xF0) >= 0x80)))
    {
        __asm
        {
            mov eax, 1
            cpuid
            mov nResult, ebx
        }
    }
    return nResult;
}

// 0x0040E9E0
unsigned int __fastcall ERRORMANAGER_GetCpuidEdx(unsigned int nFunction)
{
    unsigned int nEdx;
    __asm
    {
        mov eax, nFunction
        cpuid
        mov nEdx, edx
    }
    return nEdx;
}

D2SystemInfoStrc gtSystemInfo; // 0x0074D8A0

// 0x0040E300
static void __stdcall ERRORMANAGER_GetCpuName(char* szBuf, int nVendor, int nFamily, unsigned int nModel, int nBrand, int nType)
{
    strcpy(szBuf, "{Unknown}");
    switch (nVendor)
    {
    case 1:
        if (nBrand == 1)
        {
            strcpy(szBuf, "Celeron");
        }
        else if (nBrand == 2)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nBrand == 3)
        {
            strcpy(szBuf, "Pentium III Xeon");
        }
        else if (nBrand == 4)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nBrand == 8)
        {
            strcpy(szBuf, "Pentium 4");
        }
        else if (nBrand == 14)
        {
            strcpy(szBuf, "Xeon");
        }
        else if (nType == 0 && nFamily == 5 && nModel < 4)
        {
            strcpy(szBuf, "Pentium");
        }
        else if (nType == 0 && nFamily == 5)
        {
            strcpy(szBuf, "Pentium MMX");
        }
        else if (nType == 1 && nFamily == 5 && nModel < 3)
        {
            strcpy(szBuf, "Pentium OD586");
        }
        else if (nType == 1 && nFamily == 5 && nModel == 3)
        {
            strcpy(szBuf, "Pentium OD486");
        }
        else if (nType == 1 && nFamily == 5 && nModel >= 4)
        {
            strcpy(szBuf, "Pentium MMX OD586");
        }
        else if (nType == 0 && nFamily == 6 && nModel < 3)
        {
            strcpy(szBuf, "Pentium Pro");
        }
        else if (nType == 1 && nFamily == 6)
        {
            strcpy(szBuf, "Pentium II OD");
        }
        else if (nType == 0 && nFamily == 6 && nModel < 5)
        {
            strcpy(szBuf, "Pentium II");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 5)
        {
            strcpy(szBuf, "Pentium II or Celeron");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 6)
        {
            strcpy(szBuf, "Celeron");
        }
        else if (nType == 0 && nFamily == 6 && nModel == 7)
        {
            strcpy(szBuf, "Pentium III");
        }
        else if (nType == 0 && nFamily == 6 && nModel >= 8)
        {
            strcpy(szBuf, "Pentium III (no brand)");
        }
        else if (nType == 0 && nFamily == 15)
        {
            strcpy(szBuf, "Pentium 4 (no brand)");
        }
        break;
    case 2:
        if (nFamily == 4)
        {
            strcpy(szBuf, "Am486DX4 or Am5x86");
        }
        else if (nFamily == 5)
        {
            if (nModel < 6)
            {
                strcpy(szBuf, "K5");
            }
            else if (nModel < 8)
            {
                strcpy(szBuf, "K6");
            }
            else if (nModel == 8)
            {
                strcpy(szBuf, "K6-II");
            }
            else if (nModel >= 9)
            {
                strcpy(szBuf, "K6-III");
            }
        }
        else if (nFamily == 6)
        {
            if (nModel < 3)
            {
                strcpy(szBuf, "Athlon");
            }
            else if (nModel == 3)
            {
                strcpy(szBuf, "Duron");
            }
            else if (nModel < 6)
            {
                strcpy(szBuf, "Athlon");
            }
            else if (nModel == 6)
            {
                strcpy(szBuf, "Athlon MP, XP, or Mobile");
            }
            else if (nModel == 7)
            {
                strcpy(szBuf, "Duron Mobile");
            }
        }
        break;
    case 3:
        if (nType == 0)
        {
            if (nFamily == 4)
            {
                strcpy(szBuf, "MediaGX");
            }
            else if (nFamily == 5)
            {
                if (nModel < 4)
                {
                    strcpy(szBuf, "6x86");
                }
                else
                {
                    strcpy(szBuf, "GXm");
                }
            }
            else if (nFamily == 6)
            {
                strcpy(szBuf, "6x86MX");
            }
        }
        break;
    }
}

// 0x0040EA00
void __stdcall ERRORMANAGER_WriteProcessorReport()
{
    char szName[0x100];

    switch (gwProcessorLevel_0074D8C0)
    {
    case 3:
        LOGMANAGER_WriteLogLine("Intel 386");
        break;

    case 4:
        LOGMANAGER_WriteLogLine("Intel 486");
        break;

    default:
    {
        int nVendor = ERRORMANAGER_GetCpuVendor();
        unsigned int dwSignature = ERRORMANAGER_GetCpuSignature();
        int nType = (dwSignature >> 12) & 3;
        int nFamily = (dwSignature >> 8) & 0xF;
        int nModel = (dwSignature >> 4) & 0xF;
        int nBrand = ERRORMANAGER_GetCpuBrandIndex() & 0xFF;
        ERRORMANAGER_GetCpuName(szName, nVendor, nFamily, nModel, nBrand, nType);
// build: symbol ?gaszCpuVendorNames@* 0x00708004
        LOGMANAGER_WriteLogLine("Vendor:  %s", gaszCpuVendorNames[nVendor]);
        LOGMANAGER_WriteLogLine("Version: %s (Type %X, Family %X, Model %X, Stepping %X, Brand %X)", szName, nType, nFamily, nModel, dwSignature & 0xF, nBrand);
        LOGMANAGER_WriteLogLine("Speed: Approx. %d MHz", ERRORMANAGER_MeasureCpuMHz());
        break;
    }
    }
}

// 0x00408B20
void __fastcall ERRORMANAGER_ShowErrorBox(int nType, const char* szFile, int nLine, const char* szFormat, va_list args)
{
    char szCaption[0x100];
    char szMessage[0x1000];
    char szText[0x1000];
    char szBoxText[0x1000];
    if (szFile)
    {
        SStrPrintf(szMessage, 0x1000, "--------  FILE: %s    LINE: %d  --------\n\n", ERRORMANAGER_StripSourcePath(szFile), nLine);
// build: symbol ?gszStringFormat@* 0x006FFC58
        LOGMANAGER_LogWritePrefixedNoNewline(&gszEmptyAssertText, gszStringFormat, szMessage);
    }
    FOG_ASSERT(szFormat, 0x8DE);
    _vsnprintf(szMessage, 0x1000, szFormat, args);
    szMessage[0xFFF] = 0;
    if (szFile)
    {
// build: symbol ?gaszErrorTypeNames@* 0x00706654
        SStrPrintf(szText, 0x1000, "%s\nLocation : %s, line #%d\nExpression : %s", gaszErrorTypeNames[nType], ERRORMANAGER_StripSourcePath(szFile), nLine, szMessage);
    }
    else
    {
        strcpy(szText, szMessage);
    }
    SStrPrintf(szCaption, 0x100, "%s Error", "Diablo II");
    strcpy(szBoxText, szText);
    strcat(szText, "\n");
// build: symbol ?LOGMANAGER_LogWritePrefixed@* 0x00410740
    LOGMANAGER_LogWritePrefixed(&gszEmptyAssertText, gszStringFormat, szText);
    LOGMANAGER_CloseLogFiles();
    MessageBoxA(0, szBoxText, szCaption, 0x30);
}

char gszVersion[4096]; // 0x0074C848

char gszInspectorVersion[4096]; // 0x0074D8C8

int gbIsPlatformNT; // 0x0074F0CC

unsigned long gdwRegValue; // 0x0074F0E0

static int gbExpansionChecked; // 0x0074F0DC

static int gbExpansionMpq; // 0x0074F0D8

static int FOG_FileExists(const char* szFile)
{
    return GetFileAttributesA(szFile) != (unsigned long)-1;
}

// 0x00408F20
int __cdecl FOG_IsExpansion()
{
    if (!gbExpansionChecked)
    {
        char szPath[0x104];
        gbExpansionChecked = 1;
        FOG_GetInstallPath(szPath, 0x104);
        SStrPack(szPath, gszExpansionMpq, 0x104);
        int bExists = FOG_FileExists(szPath);
        if (!bExists)
        {
            SStrCopy(szPath, gszExpansionMpq, 0x104);
            bExists = FOG_FileExists(szPath);
        }
        if (bExists)
            gbExpansionMpq = 1;
    }
    return gbExpansionMpq;
}

// 0x00409000
int __fastcall ERRORMANAGER_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

static inline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : ERRORMANAGER_GetBitWidth(nValue - 1);
}

// 0x00409020
void __cdecl ERRORMANAGER_LogPoolError(const char* szFormat, ...)
{
    char szText[0x1000];
    va_list args;
    va_start(args, szFormat);
    vsprintf(szText, szFormat, args);
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "--------------------------------------------------------");
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "ERROR: Out of memory!");
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, gszPercentS_006FFC58, szText);
    D2MemoryStatusStrc tStatus;
    GlobalMemoryStatus(&tStatus);
    char szNumber[0x20];
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "total physical:     %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwTotalPhys));
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "available physical: %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwAvailPhys));
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "total page:         %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwTotalPageFile));
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "available page:     %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwAvailPageFile));
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "total virtual:      %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwTotalVirtual));
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "available virtual:  %s", Int64ToString(szNumber, sizeof(szNumber), tStatus.dwAvailVirtual));
    LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, &gszEmptyAssertText);
}

// 0x004098B0
void* __fastcall ERRORMANAGER_PoolReallocLarge(D2PoolSystemStrc* pSystem, int* pBlock, int nSize, const char* szFile, int nLine)
{
    pBlock -= 1;
    const int nBucket = (int)pBlock % 1023;
    int* pPrevious = 0;
    EnterCriticalSection(&pSystem->tLock);
    int* pCurrent = pSystem->apLargeBlocks[nBucket];
    while (pCurrent)
    {
        if (pCurrent == pBlock)
        {
            if (!pPrevious)
            {
                pSystem->apLargeBlocks[nBucket] = (int*)*pCurrent;
            }
            else
            {
                *pPrevious = *pCurrent;
            }
            int* pNewBlock = (int*)realloc(pBlock, nSize + 4);
            if (!pNewBlock)
            {
                ERRORMANAGER_LogPoolError("Unable to allocate free block of %s", nSize);
                D2_ASSERT(pNewBlock, 1057);
            }
            const int nNewBucket = (int)pNewBlock % 1023;
            *pNewBlock = (int)pSystem->apLargeBlocks[nNewBucket];
            pSystem->apLargeBlocks[nNewBucket] = pNewBlock;
            LeaveCriticalSection(&pSystem->tLock);
            return pNewBlock + 1;
        }
        pPrevious = pCurrent;
        pCurrent = (int*)*pCurrent;
    }
    LeaveCriticalSection(&pSystem->tLock);
    return 0;
}

// 0x004091B0
static int ERRORMANAGER_GetPoolIndex(int nSize)
{
    if (nSize <= 0x10)
    {
        return 0;
    }
    return Log2Ceil(nSize) - 4;
}

int __fastcall sub_M289_Emit_004091B0(int nUnused, int nSize)
{
    return ERRORMANAGER_GetPoolIndex(nSize);
}

// 0x00409200
static int ERRORMANAGER_GetPoolBlockSize(int nIndex)
{
    if (!nIndex)
    {
        return 0x10;
    }
    return 1 << (nIndex + 4);
}

int __fastcall sub_M126_Emit_00409200(int a, int nIndex, int nUnused)
{
    return ERRORMANAGER_GetPoolBlockSize(nIndex) + a;
}

// 0x004099C0
static D2PoolSystemStrc* ERRORMANAGER_GetPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    return pSystem;
}

D2PoolSystemStrc* __fastcall sub_M126_Emit_004099C0(int a, D2PoolSystemStrc* pSystem, int nUnused)
{
    return ERRORMANAGER_GetPoolSystem(pSystem);
}

// 0x004095D0
void __cdecl sub_004095D0_Nop()
{
}

// 0x00409C70
void __cdecl sub_00409C70_Nop()
{
}

// 0x00408A90
void __cdecl FOG_DisplayWarning(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(7, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408AC0
void __cdecl ERRORMANAGER_DisplayDeadlock(unsigned long dwThreadId, int nTicks)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(10, (const char*)dwThreadId, 2175, "Deadlocked in thread %X for %d ticks", dwThreadId, nTicks);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408AF0
void __cdecl FOG_DisplayError(int nCategory, const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(nCategory, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408A30
void __cdecl FOG_DisplayAssert(const char* szMsg, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(5, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00409490
static void __stdcall ERRORMANAGER_RemoveBlockRecord(D2PoolSystemStrc* pSystem, D2MemPoolBlockStrc* pBlock)
{
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    EnterCriticalSection(pLock);
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
    void* pMemory = pBlock->pMemory;
    int nMid;
    while (nLow < nHigh)
    {
        nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory > pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else if (pMemory < pRecords[nMid].pMemory)
        {
            nHigh = nMid;
        }
        else
        {
            goto found;
        }
    }
    LeaveCriticalSection(pLock);
    D2_ASSERT(0, 0x2BF);
found:
    if (nMid < pSystem->nPoolBlocks - 1)
    {
        memmove(&pRecords[nMid], &pRecords[nMid + 1], (pSystem->nPoolBlocks - nMid - 1) * sizeof(D2PoolRecordStrc));
    }
    pSystem->nPoolBlocks--;
    D2MemPoolRecStrc* pPool = pBlock->pPool;
    pSystem->nCount = pSystem->nCount - pPool->nChunkSize - (((pPool->nBlocksPerChunk + 0x1F) >> 5) * 4 + sizeof(D2MemPoolBlockStrc));
    if (pSystem->nPoolBlocks + 0x40 < pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks -= 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
// build: symbol ?ERRORMANAGER_LogPoolError@* 0x00409020
            ERRORMANAGER_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x2B4);
        }
    }
    LeaveCriticalSection(pLock);
}

// 0x00409B80
void __cdecl ERRORMANAGER_FreeUnusedPoolBlocks(D2PoolSystemStrc* pArg)
{
    D2PoolSystemStrc* pSystem = pArg;
    if (!pArg)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!pSystem->nPools)
    {
        return;
    }
    EnterCriticalSection(&pSystem->tLock);
    for (int i = 0; i < pSystem->nPools; i++)
    {
        D2MemPoolRecStrc* pPool = &pSystem->aPools[i];
        EnterCriticalSection(&pPool->tLock);
        D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            D2MemPoolBlockStrc* pNext = pBlock->pNext;
            if (!pBlock->nUsed)
            {
                if (pBlock->pPrev)
                {
                    pBlock->pPrev->pNext = pNext;
                }
                if (pBlock->pNext)
                {
                    pBlock->pNext->pPrev = pBlock->pPrev;
                }
                if (pPool->pFirstBlock == pBlock)
                {
                    pPool->pFirstBlock = pBlock->pNext;
                }
                if (pPool->pLastBlock == pBlock)
                {
                    pPool->pLastBlock = pBlock->pPrev;
                }
                pPool->nBlocks--;
                ERRORMANAGER_RemoveBlockRecord(pSystem, pBlock);
                VirtualFree(pBlock->pMemory, 0, 0x8000);
                free(pBlock);
            }
            pBlock = pNext;
        }
        LeaveCriticalSection(&pPool->tLock);
    }
    LeaveCriticalSection(&pSystem->tLock);
}

// 0x004099D0
static D2MemPoolBlockStrc* __stdcall ERRORMANAGER_FindPoolBlock(void* pMemory, D2PoolSystemStrc* pSystem)
{
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    EnterCriticalSection(&pSystem->tLock);
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
    while (nLow < nHigh)
    {
        const int nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory >= pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else
        {
            nHigh = nMid;
        }
    }
    const int nIndex = nLow - 1;
    D2MemPoolBlockStrc* pBlock = (nIndex >= 0 && nIndex < pSystem->nPoolBlocks) ? pRecords[nIndex].pBlock : 0;
    LeaveCriticalSection(&pSystem->tLock);
    return pBlock;
}

// 0x00409A60
static void ERRORMANAGER_MoveBlockToFront(D2MemPoolRecStrc* pPool, D2MemPoolBlockStrc* pBlock)
{
    D2MemPoolBlockStrc* pPrev = pBlock->pPrev;
    if (pPrev && pPrev->nUsed >= pPool->nBlocksPerChunk)
    {
        pPrev->pNext = pBlock->pNext;
        if (pBlock->pNext)
        {
            pBlock->pNext->pPrev = pBlock->pPrev;
        }
        else
        {
            pPool->pLastBlock = pBlock->pPrev;
        }
        pBlock->pNext = pPool->pFirstBlock;
        pPool->pFirstBlock->pPrev = pBlock;
        pPool->pFirstBlock = pBlock;
        pBlock->pPrev = 0;
    }
}

// 0x00409AB0
void __fastcall ERRORMANAGER_PoolFree(D2PoolSystemStrc* pSystem, void** ppMemory, const char* szFile, int nLine)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!*ppMemory)
    {
        return;
    }
    D2MemPoolBlockStrc* pBlock = ERRORMANAGER_FindPoolBlock(*ppMemory, pSystem);
    if (pBlock && *ppMemory >= pBlock->pMemory)
    {
        D2MemPoolRecStrc* pPool = pBlock->pPool;
        const int nIndex = ((char*)*ppMemory - (char*)pBlock->pMemory) / pPool->nBlockSize;
        if (nIndex >= pPool->nBlocksPerChunk)
        {
            sub_00409810_FreeLarge(pSystem, *ppMemory, szFile, nLine);
            return;
        }
        EnterCriticalSection(&pPool->tLock);
        if (pBlock->pUsedBits[nIndex >> 5] & gdwBitMasks[nIndex & 31])
        {
            pBlock->pUsedBits[nIndex >> 5] &= gdwInvBitMasks[nIndex & 31];
            pBlock->nUsed--;
            ERRORMANAGER_MoveBlockToFront(pPool, pBlock);
        }
        LeaveCriticalSection(&pPool->tLock);
        return;
    }
    sub_00409810_FreeLarge(pSystem, *ppMemory, szFile, nLine);
}

void* __fastcall ERRORMANAGER_PoolRealloc(D2PoolSystemStrc* pPool, void* pMemory, int nSize, const char* szFile, int nLine); // 0x0040A1F0

// 0x00409220
int __fastcall ERRORMANAGER_FindZeroBit(unsigned int dwMask)
{
    __asm
    {
        mov ebx, dwMask
        not ebx
        bsf eax, ebx
        mov dwMask, eax
    }
    return dwMask;
}

// 0x00409240
static int ERRORMANAGER_FindFreeSlot(int nCount, const unsigned int* pBits)
{
    int nWords = nCount >> 5;
    int nBase = 0;
    for (;;)
    {
        switch (nWords)
        {
        default:
            if (pBits[7] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[7]) + nBase + 0xE0;
        case 7:
            if (pBits[6] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[6]) + nBase + 0xC0;
        case 6:
            if (pBits[5] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[5]) + nBase + 0xA0;
        case 5:
            if (pBits[4] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[4]) + nBase + 0x80;
        case 4:
            if (pBits[3] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[3]) + nBase + 0x60;
        case 3:
            if (pBits[2] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[2]) + nBase + 0x40;
        case 2:
            if (pBits[1] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[1]) + nBase + 0x20;
        case 1:
            if (pBits[0] != 0xFFFFFFFF)
                return ERRORMANAGER_FindZeroBit(pBits[0]) + nBase;
        case 0:
            break;
        }
        if (nWords <= 8)
        {
            break;
        }
        nWords -= 8;
        pBits += 8;
        nBase += 0x100;
    }
    const int nRest = nCount & 0x1F;
    if (nRest && pBits[nWords] != gadwLowBitMasks[nRest])
    {
        return ERRORMANAGER_FindZeroBit(pBits[nWords]) + nBase + nWords * 32;
    }
    return -1;
}

// 0x00409370
static void __stdcall ERRORMANAGER_InsertBlockRecord(D2MemPoolBlockStrc* pBlock, D2PoolSystemStrc* pSystem)
{
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    EnterCriticalSection(pLock);
    if (pSystem->nPoolBlocks >= pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks += 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
// build: symbol ?ERRORMANAGER_LogPoolError@* 0x00409020
            ERRORMANAGER_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x261);
        }
    }
    pSystem->nCount += pBlock->pPool->nChunkSize + ((pBlock->pPool->nBlocksPerChunk + 0x1F) >> 5) * 4 + sizeof(D2MemPoolBlockStrc);
    D2PoolRecordStrc* pRecords = pSystem->pRecords;
    void* pMemory = pBlock->pMemory;
    int nLow = 0;
    int nHigh = pSystem->nPoolBlocks;
    while (nLow < nHigh)
    {
        const int nMid = nLow + ((nHigh - nLow) >> 1);
        if (pMemory > pRecords[nMid].pMemory)
        {
            nLow = nMid + 1;
        }
        else
        {
            nHigh = nMid;
        }
    }
    if (nLow < pSystem->nPoolBlocks)
    {
        memmove(&pRecords[nLow + 1], &pRecords[nLow], (pSystem->nPoolBlocks - nLow) * sizeof(D2PoolRecordStrc));
    }
    pRecords[nLow].pBlock = pBlock;
    pRecords[nLow].pMemory = pBlock->pMemory;
    pSystem->nPoolBlocks++;
    LeaveCriticalSection(pLock);
}

// 0x004095E0
static D2MemPoolBlockStrc* __stdcall ERRORMANAGER_NewPoolBlock(D2MemPoolRecStrc* pPool, D2PoolSystemStrc* pSystem)
{
    if (pSystem->nPoolBlocks >= pSystem->nMaxPoolBlocks)
    {
        pSystem->nMaxPoolBlocks += 0x20;
        pSystem->pRecords = (D2PoolRecordStrc*)realloc(pSystem->pRecords, pSystem->nMaxPoolBlocks * sizeof(D2PoolRecordStrc));
        if (!pSystem->pRecords)
        {
            ERRORMANAGER_LogPoolError("(1) Pool Blocks overflowed at %d", pSystem->nMaxPoolBlocks);
            D2_ASSERT(0, 0x2FF);
        }
    }
    const int nBitsSize = ((pPool->nBlocksPerChunk + 0x1F) >> 5) * 4;
    D2MemPoolBlockStrc* pBlock = (D2MemPoolBlockStrc*)malloc(nBitsSize + sizeof(D2MemPoolBlockStrc));
    void* pMemory = VirtualAlloc(0, pPool->nChunkSize, 0x1000, 4);
    if (pBlock && pMemory)
    {
        memset(&pBlock->nUsed, 0, sizeof(pBlock->nUsed) + sizeof(pBlock->pPrev) + sizeof(pBlock->pNext));
        pBlock->pUsedBits = (unsigned int*)(pBlock + 1);
        memset(pBlock->pUsedBits, 0, nBitsSize);
        pBlock->pMemory = pMemory;
        pBlock->pPool = pPool;
        pPool->nBlocks++;
        ERRORMANAGER_InsertBlockRecord(pBlock, pSystem);
        return pBlock;
    }
    ERRORMANAGER_LogPoolError("(2) nPoolBlocks = %d/%d  nBlockSize = %d  nUsageTableSize = %d", pSystem->nPoolBlocks, pSystem->nMaxPoolBlocks, pPool->nChunkSize, nBitsSize);
    D2_ASSERT(0, 0x320);
    return 0;
}

// 0x00409700
static int __stdcall ERRORMANAGER_GetFreeSlot(D2MemPoolBlockStrc** ppBlock, D2MemPoolRecStrc* pPool, D2PoolSystemStrc* pSystem)
{
    D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
    if (!pBlock)
    {
        pBlock = ERRORMANAGER_NewPoolBlock(pPool, pSystem);
        if (pBlock)
        {
            pPool->pLastBlock = pBlock;
            pPool->pFirstBlock = pBlock;
        }
        *ppBlock = pBlock;
        return 0;
    }
    if (pBlock->nUsed < pPool->nBlocksPerChunk)
    {
        const int nSlot = ERRORMANAGER_FindFreeSlot(pPool->nBlocksPerChunk, pBlock->pUsedBits);
        if (nSlot >= 0)
        {
            *ppBlock = pBlock;
            return nSlot;
        }
    }
    pBlock = ERRORMANAGER_NewPoolBlock(pPool, pSystem);
    if (pBlock)
    {
        pBlock->pNext = pPool->pFirstBlock;
        pPool->pFirstBlock->pPrev = pBlock;
        pPool->pFirstBlock = pBlock;
    }
    *ppBlock = pBlock;
    return 0;
}

// 0x0040A080
void* __fastcall ERRORMANAGER_PoolAlloc(D2PoolSystemStrc* pSystem, int nSize, const char* szFile, int nLine)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!gtPoolManager.bInit)
    {
        FOG_CreateNewPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    }
    if (pSystem->bFreePoolAlloc)
    {
        return ERRORMANAGER_PoolAllocLarge(pSystem, nSize, szFile, nLine);
    }
    const int nIndex = ERRORMANAGER_GetPoolIndex(nSize);
    if (nIndex >= pSystem->nPools)
    {
        return ERRORMANAGER_PoolAllocLarge(pSystem, nSize, szFile, nLine);
    }
    D2MemPoolRecStrc* pPool = &pSystem->aPools[nIndex];
    EnterCriticalSection(&pPool->tLock);
    D2MemPoolBlockStrc* pBlock;
    const int nSlot = ERRORMANAGER_GetFreeSlot(&pBlock, pPool, pSystem);
    D2_ASSERT(nSlot < pPool->nBlocksPerChunk, 0x4F3);
    if (!pBlock)
    {
        LeaveCriticalSection(&pPool->tLock);
        D2_ASSERT(0, 0x4F8);
    }
    pBlock->nUsed++;
    D2_ASSERT(!(pBlock->pUsedBits[nSlot >> 5] & gdwBitMasks[nSlot & 31]), 0x4FF);
    pBlock->pUsedBits[nSlot >> 5] |= gdwBitMasks[nSlot & 31];
    if (pBlock->nUsed >= pPool->nBlocksPerChunk && pBlock->pNext && pBlock->pNext->nUsed < pPool->nBlocksPerChunk)
    {
        if (!pBlock->pPrev)
        {
            pPool->pFirstBlock = pBlock->pNext;
        }
        else
        {
            pBlock->pPrev->pNext = pBlock->pNext;
        }
        if (pBlock->pNext)
        {
            pBlock->pNext->pPrev = pBlock->pPrev;
        }
        D2_ASSERT(pPool->pLastBlock, 0x50D);
        pPool->pLastBlock->pNext = pBlock;
        pBlock->pPrev = pPool->pLastBlock;
        pPool->pLastBlock = pBlock;
        pBlock->pNext = 0;
    }
    void* pResult = (char*)pBlock->pMemory + pPool->nBlockSize * nSlot;
    LeaveCriticalSection(&pPool->tLock);
    return pResult;
}

// 0x0040A1F0
void* __fastcall ERRORMANAGER_PoolRealloc(D2PoolSystemStrc* pPool, void* pMemory, int nSize, const char* szFile, int nLine)
{
    D2PoolSystemStrc* pSystem = pPool;
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (!pMemory)
    {
        void* pNew = ERRORMANAGER_PoolAlloc(pPool, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x62D);
        return pNew;
    }
    D2MemPoolBlockStrc* pBlock = ERRORMANAGER_FindPoolBlock(pMemory, pSystem);
    if (!pBlock)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x635);
        return pNew;
    }
    if (pMemory < pBlock->pMemory)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x63C);
        return pNew;
    }
    D2MemPoolRecStrc* pBlockPool = pBlock->pPool;
    const int nIndex = ((char*)pMemory - (char*)pBlock->pMemory) / pBlockPool->nBlockSize;
    if (nIndex >= pBlockPool->nBlocksPerChunk)
    {
        void* pNew = sub_004098B0_ReallocLarge(pSystem, pMemory, nSize, szFile, nLine);
        D2_ASSERT(pNew, 0x648);
        return pNew;
    }
    EnterCriticalSection(&pBlockPool->tLock);
    if (pBlock->pUsedBits[nIndex >> 5] & gdwBitMasks[nIndex & 31])
    {
        void* pResult;
        const int nElementSize = pBlockPool->nBlockSize;
        if (nElementSize >= nSize)
        {
            pResult = pMemory;
            LeaveCriticalSection(&pBlockPool->tLock);
        }
        else
        {
            LeaveCriticalSection(&pBlockPool->tLock);
            pResult = ERRORMANAGER_PoolAlloc(pPool, nSize, szFile, nLine);
            D2_ASSERT(pResult, 0x68B);
            memcpy(pResult, pMemory, nElementSize);
            ERRORMANAGER_PoolFree(pPool, &pMemory, szFile, nLine);
        }
        return pResult;
    }
    LeaveCriticalSection(&pBlockPool->tLock);
    D2_ASSERT(0, 0x6A0);
    return 0;
}

// 0x00409FF0
void __cdecl FOG_SetMemoryPoolSystemMode(D2PoolSystemStrc* pSystem, int bFreePoolAlloc)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    if (pSystem->nPools)
    {
        EnterCriticalSection(&pSystem->tLock);
        pSystem->bFreePoolAlloc = bFreePoolAlloc;
        LeaveCriticalSection(&pSystem->tLock);
    }
}

// 0x0040A030
void __cdecl sub_0040A030_Nop()
{
}

// 0x0040A040
int __cdecl FOG_GetMemoryUsage(D2PoolSystemStrc* pSystem)
{
    if (!pSystem)
    {
        pSystem = &gtDefaultPoolSystem_0074F104;
    }
    EnterCriticalSection(&pSystem->tLock);
    int nCount = pSystem->nCount;
    LeaveCriticalSection(&pSystem->tLock);
    return nCount;
}

// 0x00409DD0
int __cdecl FOG_CreateNewPoolSystem(D2PoolSystemStrc** ppPoolSystem, const char* szName, int nSize, int nUnused)
{
    if (!ppPoolSystem)
    {
        memset(&gtPoolManager, 0, sizeof(gtPoolManager));
        InitializeCriticalSection(&gtPoolManager.tLock);
        gtPoolManager.bInit = 1;
    }
    EnterCriticalSection(&gtPoolManager.tLock);
    D2PoolSystemStrc* pSystem;
    if (gtPoolManager.nFreeCount)
    {
        --gtPoolManager.nFreeCount;
        pSystem = &gtPoolManager.aSystems[gtPoolManager.anFreeIndex[gtPoolManager.nFreeCount]];
    }
    else
    {
        if (gtPoolManager.nUsed >= 8)
        {
            LeaveCriticalSection(&gtPoolManager.tLock);
            ERRORMANAGER_LogPoolError("Insufficient pre-allocated pool systems");
            RaiseException(0xE0000001, 0, 0, 0);
            return 0;
        }
        pSystem = &gtPoolManager.aSystems[gtPoolManager.nUsed];
        ++gtPoolManager.nUsed;
    }
    LeaveCriticalSection(&gtPoolManager.tLock);

    memset(pSystem, 0, sizeof(*pSystem));
    if (ppPoolSystem)
    {
        *ppPoolSystem = pSystem;
    }
    D2CriticalSectionStrc* pLock = &pSystem->tLock;
    InitializeCriticalSection(pLock);
    EnterCriticalSection(pLock);
    if (szName)
    {
        SStrCopy(pSystem->szName, szName, sizeof(pSystem->szName));
        pSystem->szName[sizeof(pSystem->szName) - 1] = 0;
    }

    int nValue = ERRORMANAGER_GetPoolIndex(nSize);
    const int nPools = nValue + 1;
    D2_ASSERT(nPools <= 40, 0x866);
    pSystem->nPools = nPools;
    pSystem->pRecords = 0;
    for (int i = 0; i < nPools; ++i)
    {
        InitializeCriticalSection(&pSystem->aPools[i].tLock);
        int nBlockSize;
        if (i == 0)
        {
            nBlockSize = 0x10;
        }
        else
        {
            nBlockSize = 1 << (i + 4);
        }
        pSystem->aPools[i].nBlockSize = nBlockSize;
        if (nBlockSize > 1000000 || (nBlockSize << 8) >= 0x40000)
        {
            nValue = 0x80000 / nBlockSize;
        }
        else
        {
            nValue = 0x100;
            if ((nBlockSize << 8) < 0x10000)
            {
                nValue = 0x10000 / nBlockSize;
            }
        }
        pSystem->aPools[i].nBlocksPerChunk = nValue;
        pSystem->aPools[i].nChunkSize = nBlockSize * nValue;
    }
    memset(pSystem->apLargeBlocks, 0, sizeof(pSystem->apLargeBlocks));
    LeaveCriticalSection(pLock);
    return 0;
}

// 0x00409C80
void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem)
{
    if (!gtPoolManager.bInit)
    {
        return;
    }
    if (!pSystem)
    {
        pSystem = &gtPoolManager.aSystems[0];
    }
    if (!pSystem->nPools)
    {
        return;
    }
    for (int i = 0; i < pSystem->nPools; i++)
    {
        D2MemPoolRecStrc* pPool = &pSystem->aPools[i];
        D2MemPoolBlockStrc* pBlock = pPool->pFirstBlock;
        while (pBlock)
        {
            D2MemPoolBlockStrc* pNext = pBlock->pNext;
            VirtualFree(pBlock->pMemory, 0, 0x8000);
            free(pBlock);
            pBlock = pNext;
        }
        DeleteCriticalSection(&pPool->tLock);
    }
    free(pSystem->pRecords);
    for (int j = 0; j < 1023; j++)
    {
        int* pEntry = pSystem->apLargeBlocks[j];
        while (pEntry)
        {
            int* pNext = (int*)*pEntry;
            free(pEntry);
            pEntry = pNext;
        }
    }
    DeleteCriticalSection(&pSystem->tLock);
    memset(pSystem, 0, sizeof(D2PoolSystemStrc));
    EnterCriticalSection(&gtPoolManager.tLock);
    gtPoolManager.anFreeIndex[gtPoolManager.nFreeCount] = ((unsigned int)pSystem - (unsigned int)&gtPoolManager.aSystems[0]) / sizeof(D2PoolSystemStrc);
    gtPoolManager.nFreeCount++;
    LeaveCriticalSection(&gtPoolManager.tLock);
    if (pSystem == &gtPoolManager.aSystems[0])
    {
        gtPoolManager.bInit = 0;
        DeleteCriticalSection(&gtPoolManager.tLock);
    }
}

int gnStormDirectFlags; // 0x0074C82C

// 0x00406D20
int __cdecl FOG_UseDirect()
{
    return gnStormDirectFlags;
}

// 0x00407FF0
int __cdecl FOG_IsHandlingError()
{
// build: symbol ?gbWritingCrashReport@* 0x0074F0C8
    return gbWritingCrashReport;
}

// 0x004080A0
void __stdcall sub_004080A0(int nUnused1, int nUnused2)
{
}

// 0x0040A070
int __cdecl sub_0040A070()
{
    return 0;
}

#include "gen/data/Source/Fog/Src/ErrorManager.inc"
