#include "Fog.h"
#include "D2FogTypes.h"
#include "D2NetTypes.h"
#include "D2Primitives.h"
#include "D2GameTypes.h"
#include "D2Win32Types.h"
#include "D2Win32System.h"
#include "D2CmdArg.h"
#include "D2FogSystemInfo.h"

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

extern "C" char* __cdecl strrchr(const char* szString, int nChar);                                          // 0x00682990

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

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HostentStrc;







struct D2TebStrc;

struct D2ModeIfaceStrc;

struct D2ModeEntryStrc;

struct D2ServiceTableEntryStrc;

struct D2GuidStrc;

struct D2SidAuthorityStrc;

struct D2ProcessEntryStrc;

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

extern "C" unsigned long __readfsdword(unsigned long nOffset);

struct D2FileTimeStrc;

struct D2FindDataStrc;

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

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

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

const char* __fastcall ERRORMANAGER_StripSourcePath(const char* szFile); // 0x00408000

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660

int gbWritingCrashReport; // 0x0074F0C8

D2ModeIfaceStrc* gpModeIface; // 0x0074C700

int gbRunningAsService; // 0x0074C720

char szSRegReadBuf[260]; // 0x0074C728

unsigned long gdwTotalPhys; // 0x0074D898

#define OUTPUT_SIZE 0x80

struct D2PoolSystemStrc;

D2CriticalSectionStrc gtLock_0074C830;                                                                      // 0x0074C830

D2CriticalSectionStrc gtLock_0074D848;                                                                      // 0x0074D848

int gbErrorMgrInit;                                                                                // 0x0074F0D0

static bool __stdcall ERRORMANAGER_CopyFileName(const char* szPath, char* szOut, size_t nSize); // 0x00404010

static bool __stdcall ERRORMANAGER_CopyFileUtf8(const char* szSource, const char* szDest); // 0x00404450

static size_t ERRORMANAGER_StrLCopy(char* szDest, const char* szSource, size_t nSize); // 0x00404110

static bool ERRORMANAGER_AppendPathSeparator(char* szPath); // 0x004040B0

static int ERRORMANAGER_FormatText(char* szDest, size_t nSize, const char* szFormat, ...); // 0x004041F0

static bool ERRORMANAGER_GetTempPathUtf8(char* szOut); // 0x004044F0

static bool __stdcall ERRORMANAGER_CopyPathIfHasDirectory(const char* szPath, char* szOut, size_t nSize); // 0x00403FA0

D2InspectorInfoStrc gtInspectorInfo; // 0x0074D868

char gszProcessPath[2048];                                                                         // 0x0074E8C8

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

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

void __fastcall ERRORMANAGER_DumpThread(unsigned long dwThreadId, D2ThreadContextStrc* pThreadContext, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader, int nArg7); // 0x00403070

void __fastcall sub_004032F0_DumpRegisters(unsigned long dwThreadId, D2CrashPrintFn pfnPrint, void* pContext); // 0x004032F0

void __fastcall ERRORMANAGER_DumpOtherThreads(D2CrashPrintFn pfnPrint, void* pContext, unsigned long dwSkipThreadId); // 0x00403A20

void __fastcall ERRORMANAGER_ReportPrint(void* pContext, const char* szText);                               // 0x00407980

bool __fastcall sub_00401790_SubmitReport(const char* szText, D2CrashSubmitInfoStrc* pInfo);                // 0x00401790

extern long volatile gnReportBusy;                                                                 // 0x007076B8

extern "C" const char gszCrashFile[];                                                              // 0x006CD1C0

extern "C" const char gszAssertionBegin[];                                                         // 0x006CD170

extern "C" const char gszAssertionEnd[];                                                           // 0x006CD158

extern "C" const char gszRegisters[];                                                              // 0x006CD14C

extern "C" const char gszThreads[];                                                                // 0x006CD140

struct D2StackFrameStrc;

struct D2ExceptionPointersStrc { void* pRecord; D2ThreadContextStrc* pContext; };

void __fastcall sub_00403100_PrintFrames(unsigned long dwThreadId, D2StackFrameStrc* pFrames, unsigned int nFrames, D2CrashPrintFn pfnPrint, void* pContext, bool bSymbols, bool bHeader); // 0x00403100

void __fastcall sub_00402EE0_DumpModules(D2CrashPrintFn pfnPrint,void* pContext); // 0x00402EE0

unsigned long __cdecl ERRORMANAGER_GetCurrentThreadId(); // 0x00401690

void __fastcall ERRORMANAGER_TerminateCurrentProcess(unsigned int nCode); // 0x004013C0

bool __fastcall sub_00402820_WriteMiniDump(const char* szPath,const char* szComment,void* pExceptionPointers,unsigned long dwThreadId); // 0x00402820

extern const char gszCrashSummary[]; // 0x006CD1A8

extern const char gszCrashDetail[]; // 0x006CD1A0

extern const char gszCrashNewline[]; // 0x006CD188

extern const char gszModules[]; // 0x006CD124

extern const char gszMore1[]; // 0x006CD108

extern const char gszMore2[]; // 0x006CD0F0

extern const char gszMore3[]; // 0x006CD0D4

extern const char gszMore4[]; // 0x006CD0C4

extern const char gszMinidump[]; // 0x006CD0B4

extern const char gszMore5[]; // 0x006CD09C

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

const char* __stdcall SStrChrR(const char* szString, char nChar); // 0x004134D0

void __cdecl LOGMANAGER_CloseLogFiles(); // 0x0040F960

int __fastcall ERRORMANAGER_ReportNestedError(const char* szFile, int nLine, const char* szMessage); // 0x004088C0

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

bool __fastcall ERRORMANAGER_ShowErrorReport(const char* szSummary, const char* szUnused, const char** ppszFiles, int nFiles, unsigned int nLine, bool bFlag); // 0x00408660

char gszTextBuffer[0x400]; // 0x0098A280

void* gpCrashContext; // 0x00992B14

D2ExceptionFilterFn gpfnPreviousFilter; // 0x00992B18

int gnSourcePrefixLength; // 0x0074F0D4

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

#define ARRAY_SIZE(a) (sizeof(a) / sizeof(a[0]))

void* ghD2ServerServiceStatus;                                                                              // 0x0074C714

unsigned char gabHuffmanCode[256];                                                                 // 0x0075B6A0

const unsigned char* gapHuffmanDecode[256];                                                        // 0x0075AFA0

struct D2CrashInputStrc;

#define FOG_ASSERT(expr, line) if (!(expr)) { const char* szAssertFile = sub_00408090(); FOG_SOCKET_WSACleanup(); ERRORMANAGER_RaiseErrorReport(6, &gszEmptyAssertText, line, "Unrecoverable internal error %08x", szAssertFile); LOGMANAGER_CloseLogFiles(); exit(-1); }

void __cdecl ERRORMANAGER_RaiseErrorReport(int nType, const char* szFile, int nLine, const char* szFormat, ...); // 0x00408900

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" int __cdecl atexit(void (__cdecl* pfnExit)()); // 0x00683824

void __cdecl ERRORMANAGER_StartDbgHelpThread(); // 0x004016A0

void __fastcall ERRORMANAGER_SetReportText(const char* szText); // 0x00401740

void __fastcall ERRORMANAGER_SetCrashHandler(void* pfnHandler, void* pContext, int nUnused); // 0x00403F60

int __fastcall ERRORMANAGER_GetModuleDirectory(char* szPath, unsigned int nSize); // 0x00406B60

void __cdecl ERRORMANAGER_LogSystemInfo(); // 0x004076B0

void __cdecl AUTOMAP_CaptureSystemInfo(); // 0x00407DE0

void __cdecl ERRORMANAGER_ExitHandler(); // 0x00407F20

int __fastcall ERRORMANAGER_CrashHandler(D2CrashInputStrc* pInput); // 0x004082E0

int __cdecl EXCEPTIONS_LoadImageHlp(); // 0x0040D5B0

void __cdecl LOGMANAGER_InitLogSystem(); // 0x00410540

int __cdecl SYSTEM_IsPlatformNT(); // 0x00410960

void __cdecl SYSTEM_InitTimeBase(); // 0x004109D0

void __cdecl sub_00411210_InitTimer(); // 0x00411210

void __fastcall SetErrorReportCallback(void* pfnHandler); // 0x0041C0E0

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

static D2MemPoolBlockStrc* __stdcall ERRORMANAGER_FindPoolBlock(void* pMemory, D2PoolSystemStrc* pSystem); // 0x004099D0

static void ERRORMANAGER_MoveBlockToFront(D2MemPoolRecStrc* pPool, D2MemPoolBlockStrc* pBlock); // 0x00409A60

inline D2TebStrc* D2_NtCurrentTeb()
{
    return (D2TebStrc*)__readfsdword(0x18);
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

// 0x004082E0
int __fastcall ERRORMANAGER_CrashHandler(D2CrashInputStrc* pInput)
{
    D2ThreadContextStrc* pThread = pInput->pException->pContext;
    const long nBusy = InterlockedIncrement(&gnReportBusy);
    if (nBusy == 0)
    {
        gbWritingCrashReport = 1;
        crashy::Report report;
        if (!report.OpenReport(gszCrashFile))
        {
            gbWritingCrashReport = 0;
        }
        else
        {
            report.WriteInspectorHeader();
            report.sub_00401380(gszCrashSummary,pInput->szSummary);
            if (pInput->szDetail[0]) report.sub_00401380(gszCrashDetail,pInput->szDetail);
            report.sub_00401380(gszCrashNewline);
            report.sub_00401380(gszAssertionBegin);
            int nSkip = 0;
            if (!pThread && !pInput->pFrames)
            {
                nSkip = pInput->nSkip;
                if (pInput->dwThreadId == ERRORMANAGER_GetCurrentThreadId()) nSkip += 2;
            }
            if (pInput->pFrames)
                sub_00403100_PrintFrames(pInput->dwThreadId,pInput->pFrames,pInput->nFrames,ERRORMANAGER_ReportPrint,&report,0,1);
            else
                ERRORMANAGER_DumpThread(pInput->dwThreadId,pThread,ERRORMANAGER_ReportPrint,&report,0,1,nSkip);
            report.sub_00401380(gszAssertionEnd);
            report.sub_00401380(gszRegisters);
            sub_004032F0_DumpRegisters(pInput->dwThreadId,ERRORMANAGER_ReportPrint,&report);
            report.sub_00401380(gszThreads);
            ERRORMANAGER_DumpOtherThreads(ERRORMANAGER_ReportPrint,&report,pInput->dwThreadId);
            report.sub_00401380(gszModules);
            sub_00402EE0_DumpModules(ERRORMANAGER_ReportPrint,&report);
            report.sub_00401380(gszMore1);
            report.sub_00401380(gszMore2);
            report.sub_00401380(gszMore3);
            if (pInput->pFrames)
                sub_00403100_PrintFrames(pInput->dwThreadId,pInput->pFrames,pInput->nFrames,ERRORMANAGER_ReportPrint,&report,0,0);
            else
                ERRORMANAGER_DumpThread(pInput->dwThreadId,pThread,ERRORMANAGER_ReportPrint,&report,0,0,nSkip);
            report.sub_00401380(gszMore4);
            SStrCopy(gszProcessPath,report.m_szText408,0x800);
            SStrPack(gszProcessPath,gszMinidump,0x800);
            if (sub_00402820_WriteMiniDump(gszProcessPath,&gszEmptyAssertText,pInput->pException,0))
                report.sub_00401220_AddFile(gszProcessPath,false);
            report.sub_00401380(gszMore5);
            report.sub_004011F0_Close();
            D2CrashSubmitInfoStrc info;
            memset(&info,0,sizeof(info));
            info.szName=gtInspectorInfo.szUnused04;
            for (int i=0;i<report.m_nLineCount;++i)
            {
                if (i < sizeof(info.apszLines)/sizeof(info.apszLines[0]))
                {
                    info.apszLines[i]=report.m_aszLines[i];
                    ++info.nLines;
                }
            }
            sub_00401790_SubmitReport(report.m_szText08,&info);
            gbWritingCrashReport=0;
        }
        InterlockedDecrement(&gnReportBusy);
        ERRORMANAGER_TerminateCurrentProcess(-1);
    }
    return 2;
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

int sgfAsyncDataEnabled; // 0x0075AF94

// build: symbol ?strrchr@@YAPADPADH@Z 0x00401A30
char* __cdecl strrchr(char* szString, int nChar)
{
    return strrchr((const char*)szString, nChar);
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

// 0x004088C0
int __fastcall ERRORMANAGER_ReportNestedError(const char* szFile, int nLine, const char* szMessage)
{
    if (gbWritingCrashReport)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "\n***** ENCOUNTERED ERROR DURING ERROR HANDLING!!!\n%s,%d\n%s\n*****", ERRORMANAGER_StripSourcePath(szFile), nLine, szMessage);
        return 1;
    }
    return 0;
}

// 0x00408A60
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine)
{
    FOG_SOCKET_WSACleanup();
    ERRORMANAGER_RaiseErrorReport(6, &gszEmptyAssertText, nLine, "Unrecoverable internal error %08x", szFile);
    LOGMANAGER_CloseLogFiles();
}

// 0x00408CE0
void __fastcall FOG_InitErrorMgr(const char* szProgramName, const char* szVersion, int bLogToFile)
{
    char szPath[0x1000];
    if (gbErrorMgrInit)
    {
        if (bLogToFile)
        {
            ERRORMANAGER_LogSystemInfo();
        }
        return;
    }
    ERRORMANAGER_StartDbgHelpThread();
    ERRORMANAGER_SetCrashHandler(ERRORMANAGER_CrashHandler, 0, 0);
    if (ERRORMANAGER_GetModuleDirectory(szPath, 0x1000))
    {
        ERRORMANAGER_SetReportText(szPath);
    }
    gtInspectorInfo.nProjectId = 0x108;
    gtInspectorInfo.szUnused04 = "Diablo II";
    gtInspectorInfo.szApplication = "Diablo II";
    gtInspectorInfo.szModule = "Diablo II";
    sprintf(gszInspectorVersion, "D2 %i.%i%c", 1, 14, 'd');
    gtInspectorInfo.szMilestone = gszInspectorVersion;
    gtInspectorInfo.szBuildNumber = "77";
    gtInspectorInfo.szPlatform = "Windows";
    gtInspectorInfo.szPrimaryAssignment = ".ClassicErrorReporter";
    gtInspectorInfo.szAssignments = ".ClassicErrorReporter";
    if (szVersion)
    {
        SStrCopy(gszVersion, szVersion, 0x1000);
    }
    gbIsPlatformNT = SYSTEM_IsPlatformNT();
    InitializeCriticalSection(&gtLock_0074C830);
    InitializeCriticalSection(&gtLock_0074D848);
    gbErrorMgrInit = 1;
    SYSTEM_InitTimeBase();
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "TraceUnfreedMemory", 0, &dwValue);
    gdwRegValue = dwValue;
// build: symbol ?FOG_CreateNewPoolSystem@* 0x00409DD0
    FOG_CreateNewPoolSystem(0, "Global Pool System", 0x40000, 0x8000);
    sub_00411210_InitTimer();
    for (int i = 0; i < 0x20; ++i)
    {
        const unsigned int nMask = 1 << i;
        FOG_ASSERT(gdwBitMasks_006CE268[i] == nMask, 0x576);
        FOG_ASSERT(gdwInvBitMasks[i] == ~nMask, 0x577);
    }
    AUTOMAP_CaptureSystemInfo();
    LOGMANAGER_InitLogSystem();
    if (bLogToFile)
    {
        ERRORMANAGER_LogSystemInfo();
    }
    atexit(ERRORMANAGER_ExitHandler);
    EXCEPTIONS_LoadImageHlp();
// build: symbol ?ERRORMANAGER_ShowErrorReport@* 0x00408660
    SetErrorReportCallback(ERRORMANAGER_ShowErrorReport);
}
