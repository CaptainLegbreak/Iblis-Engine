#include "Fog.h"
#include "D2GameTypes.h"
#include "D2FogTypes.h"
#include "D2StormLink.h"
#include "stpl.h"
#include "FogApi.h"
#include "StormApi.h"

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

extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC

extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData);  // 0x006CC1C8

unsigned long gdwLastLogSweep;                                                                     // 0x0075E874

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

namespace LogManager { struct Message; }

struct D2StormLinkStrc;

struct D2ChatStormLinkStrc;

struct D2ChatStormListAStrc;

struct sub_0040F7D0;

struct D2SystemTimeStrc;

struct D2FileTimeStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" size_t __cdecl fread(void* pBuffer, size_t nSize, size_t nCount, _iobuf* pFile); // 0x00684782

_iobuf* __fastcall LOGMANAGER_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize); // 0x0040EBD0

void __fastcall LOGMANAGER_GetLogDirectory(char* szDirectory, int nSize); // 0x0040F000

void __fastcall LOGMANAGER_CloseNamedLog(const char* szName); // 0x0040F470

void __cdecl LOGMANAGER_LogMemoryDump(const char* szPrefix, const char* szTitle, unsigned long dwAddress, unsigned int nSize, int nArg5, int nArg6, int nArg7); // 0x00410040

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5

extern "C" __declspec(dllimport) long __stdcall SHGetFolderPathA(void* hWnd, int nFolder, void* hToken, unsigned long dwFlags, char* szPath); // 0x006CC43C

int __fastcall ERRORMANAGER_AppendBackslash(char* szPath, unsigned int nSize); // 0x00406B20

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern int gbLogInitialized; // 0x0075D2EC


extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

// A critical section for the whole run: initialized before main, deleted at exit.
struct CCritSect : D2CriticalSectionStrc
{
    CCritSect() { InitializeCriticalSection(this); }
    ~CCritSect() { DeleteCriticalSection(this); }
    void Enter();
    void Leave();
};

// build: symbol ??0CCritSect@@QAE@XZ 0x0040EB50
// build: symbol ??1CCritSect@@QAE@XZ 0x0040EB60

// 0x0040EB70
void CCritSect::Enter()
{
    EnterCriticalSection(this);
}

// 0x0040EB80
void CCritSect::Leave()
{
    LeaveCriticalSection(this);
}

// build: symbol ??__EgtLogQueueLock@@YAXXZ 0x006CA700
// build: symbol ??__FgtLogQueueLock@@YAXXZ 0x006CB070
CCritSect gtLogQueueLock; // 0x0075E838

_iobuf* __fastcall LOGMANAGER_GetLogFile(const char* szName, int* pnSlot); // 0x0040EDE0

// build: symbol _SMemAlloc@16 0x00413020
// build: symbol ??3Message@LogManager@@SAXPAX0@Z 0x0040EB30
// build: symbol _SMemFree@16 0x00412650


struct D2ChatStormLinkStrc
{
    D2ChatStormLinkStrc* m_prevlink;
    char* m_next;
};

struct D2ChatStormListAStrc
{
    int m_linkoffset;
    D2ChatStormLinkStrc m_terminator;

    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void IGNORELIST_ResetStringList();
};

struct sub_0040F7D0
{
    D2StormLinkStrc tLink;
    ~sub_0040F7D0();
};

namespace LogManager
{
struct Message;
}

namespace LogManager
{
struct Message : TSLinkedNode<Message>
{
    unsigned int nSize;
    int nType;
    int bTimeStamp;
    D2SystemTimeStrc tTimeStamp;

    Message();
    ~Message();
    char* GetName() { return (char*)(this + 1); }
    static void operator delete(void* pMemory);
    static void operator delete(void*, void*) {}
};
}

// build: symbol ??2@YAPAXIPAX@Z 0x0040EB20
inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

// 0x0040EB40
char* __fastcall sub_0040EB40_GetMessageData(LogManager::Message* pMessage)
{
    return (char*)&pMessage->nSize;
}

// build: symbol ??__EgtLogLock@@YAXXZ 0x006CA720
// build: symbol ??__FgtLogLock@@YAXXZ 0x006CB080
CCritSect gtLogLock; // 0x0075E850

D2MiniDumpRequestStrc* gpMiniDumpRequest; // 0x0098A6E4

struct D2LogMemoryInfoStrc
{
    const void* pAddress;
    unsigned int nSize;
    int nArg5;
    int bBadPointer;
    int bArg7;
};

extern "C" __declspec(dllimport) int __stdcall IsBadReadPtr(const void* pAddress, unsigned int nSize); // 0x006CC238

int gnLogQueuedBytes; // 0x0075D144

int gnLogQueued; // 0x0075D140

// build: symbol ??__EgtLogMsgQueue_0075E868@@YAXXZ 0x006CA740
// build: symbol ??__FgtLogMsgQueue_0075E868@@YAXXZ 0x006CB090
TSList<LogManager::Message> gtLogMsgQueue_0075E868; // 0x0075E868
// build: symbol ?Next@?$TSLink@UMessage@LogManager@@@@QAEPAUMessage@LogManager@@XZ 0x0040F520
// build: symbol ?Unlink@?$TSLink@UMessage@LogManager@@@@QAEXXZ 0x0040F530
// build: symbol ?InitializeTerminator@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEXXZ 0x0040F580
// build: symbol ?Head@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEPAUMessage@LogManager@@XZ 0x0040F7C0
// build: symbol ??0?$TSLink@UMessage@LogManager@@@@QAE@XZ 0x0040F810
// build: symbol ?NextLink@?$TSLink@UMessage@LogManager@@@@QAEPAU1@H@Z 0x0040F4F0
// build: symbol ??1?$TSLink@UMessage@LogManager@@@@QAE@XZ 0x0040F820
// build: symbol ?Link@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEPAU?$TSLink@UMessage@LogManager@@@@PBUMessage@LogManager@@@Z 0x0040F880
// build: symbol ??1?$TSLinkedNode@UMessage@LogManager@@@@QAE@XZ 0x0040FAA0
// build: symbol ??0?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAE@XZ 0x0040FB50
// build: symbol ?LinkNode@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEXPAUMessage@LogManager@@I0@Z 0x0040FBB0
// build: symbol ?UnlinkNode@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEXPAUMessage@LogManager@@@Z 0x0040FC60
// build: symbol ??0?$TSLinkedNode@UMessage@LogManager@@@@QAE@XZ 0x0040FCB0
// build: symbol ?UnlinkAll@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEXXZ 0x0040FD00
// build: symbol ??1?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAE@XZ 0x0040FD90
// build: symbol ?Clear@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEXXZ 0x0040FED0
// build: symbol ?NewNode@?$TSList@UMessage@LogManager@@U?$TSGetLink@UMessage@LogManager@@@@@@QAEPAUMessage@LogManager@@III@Z 0x0040FF40
// build: symbol ??_R0?AUMessage@LogManager@@@8 0x0070811C
template LogManager::Message* TSLink<LogManager::Message>::Next();
template void TSLink<LogManager::Message>::Unlink();
template void TSList<LogManager::Message>::InitializeTerminator();
template LogManager::Message* TSList<LogManager::Message>::Head();
template TSLink<LogManager::Message>::TSLink();
template TSLink<LogManager::Message>* TSLink<LogManager::Message>::NextLink(int);
template TSLink<LogManager::Message>::~TSLink();
template TSLink<LogManager::Message>* TSList<LogManager::Message>::Link(const LogManager::Message*);
template void TSList<LogManager::Message>::UnlinkNode(LogManager::Message*);

extern "C" void* __cdecl memcpy(void* pDest, const void* pSource, unsigned int nSize); // 0x006829C0

void __fastcall LOGMANAGER_WriteLogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

struct D2LogDumpStrc;


struct D2LogDumpStrc
{
    const unsigned char* pAddress;
    unsigned int nSize;
    int bShortAddress;
    int bIndirect;
    int bShowAscii;
    char szLabel[1];
};

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" int __cdecl strcmp(const char* szA, const char* szB);

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" int __cdecl fprintf(_iobuf* pFile, const char* szFormat, ...); // 0x00684C94

extern D2SystemTimeStrc gLogStartTime_0075D288; // 0x0075D288

// 0x0040ECC0
void __fastcall LOGMANAGER_WriteDateBanner(_iobuf* pFile, const D2SystemTimeStrc* pTime)
{
    char szComputerName[0x40];
    unsigned long nSize = sizeof(szComputerName);
    if (!GetComputerNameA(szComputerName, &nSize))
        szComputerName[0] = 0;
    fprintf(pFile, "---------------------------------------------------------------\n");
    fprintf(pFile, "%s %04d-%02d-%02d\n", szComputerName, pTime->wYear, pTime->wMonth, pTime->wDay);
    fprintf(pFile, "---------------------------------------------------------------\n");
}

// 0x0040ED40
void __fastcall LOGMANAGER_WriteStartupBanner(_iobuf* pFile)
{
    char szComputerName[0x40];
    unsigned long nSize = sizeof(szComputerName);
    if (!GetComputerNameA(szComputerName, &nSize))
        szComputerName[0] = 0;
    fprintf(pFile, "---------------------------------------------------------------\n");
    fprintf(pFile, "%s Realm startup at %04d-%02d-%02d %02d:%02d:%02d.%03u\n", szComputerName, gLogStartTime_0075D288.wYear,
        gLogStartTime_0075D288.wMonth, gLogStartTime_0075D288.wDay, gLogStartTime_0075D288.wHour,
        gLogStartTime_0075D288.wMinute, gLogStartTime_0075D288.wSecond, gLogStartTime_0075D288.wMilliseconds);
    fprintf(pFile, "---------------------------------------------------------------\n");
}

extern int ganLogNewFile[20]; // 0x0075D298

extern char gaszLogFilePaths[20][0x104]; // 0x0075D340

// 0x0040EB90
unsigned int __fastcall LOGMANAGER_GetLogFilePaths(char** apszFiles, unsigned int nCount)
{
    unsigned int i;
    for (i = 0; i < nCount; i++)
    {
        if (i >= 20)
        {
            break;
        }
        apszFiles[i] = gaszLogFilePaths[i];
    }
    return i;
}

unsigned long gadwLogOpenTick[20]; // 0x0075E7E0

extern "C" const char gszLogTimeStampFormat[]; // 0x006CE1DC

extern "C" const char gszLogBlankStamp[]; // 0x006CE1CC

extern "C" const char gszLogDumpAddress16[]; // 0x006CE1C0

extern "C" const char gszLogDumpAddress32[]; // 0x006CE1B4

extern "C" const char gszLogUnreadable[]; // 0x006CD880

extern "C" const char gszLogDumpByte[]; // 0x006CE1AC

extern "C" const char gszLogDumpByteSpaced[]; // 0x006CE1A4

extern "C" const char gszLogLineFormat_006CD90C[]; // 0x006CD90C

// 0x0040EBD0
_iobuf* __fastcall LOGMANAGER_OpenDatedLogFile(const char* szName, D2SystemTimeStrc* pTime, const char* szMode, int* pbNew, char* szPathOut, unsigned int nPathOutSize)
{
    char szPath[0x104];
    GetLocalTime(pTime);
// build: symbol ?gszLogPrefix@* 0x00708018
    SStrPrintf(szPath, sizeof(szPath), "%s%s%02d%02d%02d.txt", gszLogPrefix, szName, pTime->wYear % 100, pTime->wMonth, pTime->wDay);
    if (szPathOut)
    {
        SStrCopy(szPathOut, szPath, nPathOutSize);
    }
    if (pbNew)
    {
        *pbNew = 1;
        if (*szMode == 'a')
        {
            _iobuf* pFile = fopen(szPath, "r");
            if (pFile)
            {
                fclose(pFile);
                *pbNew = 0;
            }
        }
    }
    return fopen(szPath, szMode);
}

// 0x0040F000
void __fastcall LOGMANAGER_GetLogDirectory(char* szDirectory, int nSize)
{
    char szPath[0x104];
    *szDirectory = 0;
    if (SHGetFolderPathA(0, 5, 0, 0, szPath) >= 0)
    {
        SStrCopy(szDirectory, szPath, nSize);
        ERRORMANAGER_AppendBackslash(szDirectory, nSize);
        SStrPack(szDirectory, "Diablo II\\GameLogs\\", nSize);
        FOG_CreatePathHierarchy(szDirectory);
    }
}

// 0x0040F3D0
void __fastcall LOGMANAGER_SweepLogFile(const D2FileTimeStrc* pNow, const char* szFile)
{
    int nOffset = SStrLen(szFile) - 10;
    if (nOffset > 0)
    {
        int nYear, nMonth, nDay;
        sscanf(szFile + nOffset, "%2d%2d%2d", &nYear, &nMonth, &nDay);
        D2SystemTimeStrc tTime;
        memset(&tTime, 0, sizeof(tTime));
        tTime.wYear = nYear > 90 ? nYear + 1900 : nYear + 2000;
        tTime.wMonth = nMonth;
        tTime.wDay = nDay;
        D2FileTimeStrc tFileTime;
        SystemTimeToFileTime(&tTime, &tFileTime);
        if (pNow->dwHighDateTime >= tFileTime.dwHighDateTime && pNow->dwHighDateTime - tFileTime.dwHighDateTime >= 0x4B7)
            DeleteFileA(szFile);
    }
}

// 0x0040F5A0
void __fastcall LOGMANAGER_SetLogPrefix(const char* szName)
{
    char szDirectory[0x104];
    LOGMANAGER_GetLogDirectory(szDirectory, 0x104);
// build: symbol ?gszLogPrefix@* 0x00708018
    SStrPrintf(gszLogPrefix, 0x104, "%s%s", szDirectory, szName);
}

// 0x0040F600
long __fastcall LOGMANAGER_MeasureLogFile(const char* szName)
{
    D2SystemTimeStrc tTime;
    EnterCriticalSection(&gtLogLock);
    LOGMANAGER_CloseNamedLog(szName);
    long nSize = 0;
    _iobuf* pFile = LOGMANAGER_OpenDatedLogFile(szName, &tTime, "r", 0, 0, 0);
    if (pFile)
    {
        fseek(pFile, 0, 2);
        nSize = ftell(pFile);
        fclose(pFile);
    }
    LeaveCriticalSection(&gtLogLock);
    return nSize;
}

// 0x0040F670
char* __fastcall LOGMANAGER_ReadLogRange(const char* szName, long nStart, long nEnd)
{
    D2SystemTimeStrc tTime;
    long nLength = nEnd - nStart;
    char* pBuffer = (char*)FOG_Alloc(nLength + 1, ".\\Src\\LogManager.cpp", 0x10A, 0);
    memset(pBuffer, 0, nLength + 1);
    EnterCriticalSection(&gtLogLock);
    LOGMANAGER_CloseNamedLog(szName);
    _iobuf* pFile = LOGMANAGER_OpenDatedLogFile(szName, &tTime, "r", 0, 0, 0);
    if (pFile)
    {
        if (!fseek(pFile, nStart, 0))
            fread(pBuffer, 1, nLength, pFile);
        fclose(pFile);
    }
    LeaveCriticalSection(&gtLogLock);
    return pBuffer;
}

// 0x0040F8A0
void __cdecl LOGMANAGER_CloseLogFilesNow()
{
    D2_ASSERT(gbLogInitialized, 456);
    const unsigned long dwStart = GetTickCount();
    while (GetTickCount() - dwStart < 1000)
    {
        EnterCriticalSection(&gtLogQueueLock);
        LogManager::Message* pQueued = gtLogMsgQueue_0075E868.Head();
        LeaveCriticalSection(&gtLogQueueLock);
        if (!pQueued)
        {
            break;
        }
        Sleep(10);
    }
    for (int i = 0; i < 20; i++)
    {
        EnterCriticalSection(&gtLogLock);
// build: symbol ?gapLogFiles@* 0x0075E790
        if (gapLogFiles[i])
        {
            fclose(gapLogFiles[i]);
            gapLogFiles[i] = 0;
        }
        LeaveCriticalSection(&gtLogLock);
    }
}

// 0x0040F960
void __cdecl LOGMANAGER_CloseLogFiles()
{
    LOGMANAGER_CloseLogFilesNow();
}

// build: symbol ??_GMessage@LogManager@@QAEPAXI@Z 0x0040FE60
inline void LogManager::Message::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

// 0x0040FE10
LogManager::Message::Message()
{
}

// 0x0040FD40
LogManager::Message::~Message()
{
}

extern void* ghLogThread; // 0x0075D2E8

extern int gbLogThreadStop; // 0x0075E830

extern unsigned long gnLogThreadId; // 0x0075E834

// 0x0040FFD0
void __cdecl LOGMANAGER_ShutdownLogSystem()
{
    gbLogThreadStop = 1;
    WaitForSingleObject(ghLogThread, 30000);
    CloseHandle(ghLogThread);
    EnterCriticalSection(&gtLogQueueLock);
    gtLogMsgQueue_0075E868.Clear();
    gnLogQueued = 0;
    gnLogQueuedBytes = 0;
    ghLogThread = 0;
    gnLogThreadId = 0;
    gbLogInitialized = 0;
    gbLogThreadStop = 0;
    LeaveCriticalSection(&gtLogQueueLock);
}

// 0x00410040
void __cdecl LOGMANAGER_LogMemoryDump(const char* szPrefix, const char* szTitle, unsigned long dwAddress, unsigned int nSize, int nArg5, int bBadPointer, int nArg7)
{
// build: symbol ?gbLogThreadStop@* 0x0075E830
    if (gbLogThreadStop || !gbLogInitialized)
        return;
    if (!bBadPointer && IsBadReadPtr((const void*)dwAddress, nSize))
        bBadPointer = 1;
    unsigned int nExtraBytes = SStrLen(szPrefix) + 1 + sizeof(D2LogMemoryInfoStrc);
    nExtraBytes += SStrLen(szTitle) + 1;
    if (!bBadPointer)
        nExtraBytes += nSize;
    EnterCriticalSection(&gtLogQueueLock);
    LogManager::Message* pMessage = gtLogMsgQueue_0075E868.NewNode(0, nExtraBytes, 0);
    LeaveCriticalSection(&gtLogQueueLock);
    pMessage->nSize = nExtraBytes + 0x24;
    pMessage->nType = 2;
    pMessage->bTimeStamp = 1;
    GetLocalTime(&pMessage->tTimeStamp);
    char* pText = pMessage->GetName();
    pText += SStrCopy(pText, szPrefix, 0x7FFFFFFF) + 1;
    D2LogMemoryInfoStrc* pInfo = (D2LogMemoryInfoStrc*)pText;
    pInfo->pAddress = (const void*)dwAddress;
    pInfo->nSize = nSize;
    pInfo->nArg5 = nArg5;
    pInfo->bBadPointer = bBadPointer;
    pInfo->bArg7 = !nArg7;
    pText = (char*)(pInfo + 1);
    pText += SStrCopy(pText, szTitle, 0x7FFFFFFF) + 1;
    if (!bBadPointer)
        memcpy(pText, (const void*)dwAddress, nSize);
    EnterCriticalSection(&gtLogQueueLock);
    gtLogMsgQueue_0075E868.LinkNode(pMessage, 2, 0);
    ++gnLogQueued;
    gnLogQueuedBytes += pMessage->nSize;
    LeaveCriticalSection(&gtLogQueueLock);
}

extern "C" int __cdecl _vsnprintf(char* szDest, size_t nCount, const char* szFormat, va_list args); // 0x00682F22
extern "C" int __cdecl _snprintf(char* szDest, size_t nCount, const char* szFormat, ...); // 0x006831DB
// 0x00410340
void __fastcall LOGMANAGER_WriteLogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args)
{
// build: symbol ?gbLogThreadStop@* 0x0075E830
    if (gbLogThreadStop || !gbLogInitialized)
    {
        return;
    }

    char szBuffer[0x1000];
    __try
    {
        _vsnprintf(szBuffer, sizeof(szBuffer), szFormat, args);
        szBuffer[sizeof(szBuffer) - 1] = 0;
    }
    __except (1)
    {
        _snprintf(szBuffer, sizeof(szBuffer), "Bad message: format string is '%s'", szFormat);
    }

    if (nArg3 == 1)
    {
        SStrPack(szBuffer, gszNewline, sizeof(szBuffer));
    }

    unsigned int nExtraBytes = SStrLen(szPrefix) + 1;
    nExtraBytes += SStrLen(szBuffer) + 1;

    EnterCriticalSection(&gtLogQueueLock);
    LogManager::Message* pMessage = gtLogMsgQueue_0075E868.NewNode(0, nExtraBytes, 0);
    LeaveCriticalSection(&gtLogQueueLock);

    pMessage->nSize = nExtraBytes + 0x24;
    pMessage->nType = 1;
    pMessage->bTimeStamp = nArg2 == 1;
    GetLocalTime(&pMessage->tTimeStamp);

    char* pText = pMessage->GetName();
    SStrCopy(pText, szPrefix, nExtraBytes);
    pText += SStrLen(pText) + 1;
    SStrCopy(pText, szBuffer, nExtraBytes);

    EnterCriticalSection(&gtLogQueueLock);
    gtLogMsgQueue_0075E868.LinkNode(pMessage, 2, 0);
    ++gnLogQueued;
    gnLogQueuedBytes += pMessage->nSize;
    LeaveCriticalSection(&gtLogQueueLock);
}

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void* pParam), void* pParam, unsigned long dwFlags, unsigned long* pnThreadId); // 0x006CC250
extern D2SystemTimeStrc gLogStartTime_0075D288; // 0x0075D288

void __fastcall LOGMANAGER_WriteMessage(LogManager::Message* pMessage); // 0x0040F720
void __fastcall LOGMANAGER_WriteDumpMessage(LogManager::Message* pMessage); // 0x0040F070
void __cdecl LOGMANAGER_CloseStaleLogs(); // 0x0040F350
void __cdecl LOGMANAGER_SweepOldLogFiles(); // 0x0040F970

// The queue's first message, or 0 when the terminator's link carries the complemented list address.
static inline LogManager::Message* LOGMANAGER_QueuedNode(LogManager::Message* pNext)
{
    if ((int)pNext > 0)
        return pNext;
    return 0;
}

static inline LogManager::Message* LOGMANAGER_QueueHead(TSList<LogManager::Message>* pQueue)
{
    return LOGMANAGER_QueuedNode(pQueue->m_terminator.m_next);
}

// 0x004101C0
unsigned long __stdcall LOGMANAGER_LogThreadProc(void* pParam)
{
    unsigned long dwStopTime = 0;
    for (;;)
    {
        EnterCriticalSection(&gtLogQueueLock);
        LogManager::Message* pMessage = LOGMANAGER_QueueHead(&gtLogMsgQueue_0075E868);
        if (pMessage)
        {
            gtLogMsgQueue_0075E868.m_terminator.m_next->m_link.Unlink();
            --gnLogQueued;
            gnLogQueuedBytes -= pMessage->nSize;
        }
        LeaveCriticalSection(&gtLogQueueLock);

// build: symbol ?gbLogThreadStop@* 0x0075E830
        if (gbLogThreadStop)
        {
            if (!dwStopTime)
                dwStopTime = GetTickCount();
            if (!pMessage || GetTickCount() - dwStopTime >= 15000)
                return 1;
        }

        unsigned long dwSleep = 0;
        if (!pMessage)
        {
            dwSleep = 50;
        }
        else
        {
            EnterCriticalSection(&gtLogLock);
            switch (pMessage->nType)
            {
            case 1:
                LOGMANAGER_WriteMessage(pMessage);
                break;
            case 2:
                LOGMANAGER_WriteDumpMessage(pMessage);
                break;
            }
            LeaveCriticalSection(&gtLogLock);
            delete pMessage;
        }

        if (!gbLogThreadStop)
        {
            Sleep(dwSleep);
            EnterCriticalSection(&gtLogLock);
            LOGMANAGER_CloseStaleLogs();
            LOGMANAGER_SweepOldLogFiles();
            LeaveCriticalSection(&gtLogLock);
        }
    }
}

// 0x00410540
void __cdecl LOGMANAGER_InitLogSystem()
{
// build: symbol ?gbLogThreadStop@* 0x0075E830
    gbLogThreadStop = 0;
    ghLogThread = CreateThread(0, 0, LOGMANAGER_LogThreadProc, 0, 0, &gnLogThreadId);
    gbLogInitialized = 1;
    GetLocalTime(&gLogStartTime_0075D288);
    for (unsigned int i = 0; i < 20; i++)
    {
        ganLogNewFile[i] = 1;
    }
    for (unsigned int i = 0; i < 20; i++)
    {
        gaszLogFilePaths[i][0] = 0;
    }
}

// 0x00410610
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 299);
    va_list args;
    va_start(args, szFormat);
    LOGMANAGER_WriteLogV(&gszEmptyAssertText, 1, 1, szFormat, args);
}

// 0x00410660
void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 316);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    LOGMANAGER_WriteLogV(szPrefix, 1, 1, szFormat, args);
}

// 0x004106B0
void __cdecl LOGMANAGER_LogWritePrefixedNoNewline(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 335);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    LOGMANAGER_WriteLogV(szPrefix, 1, 0, szFormat, args);
}

// 0x00410700
void __cdecl LOGMANAGER_LogWrite(const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 354);
    va_list args;
    va_start(args, szFormat);
    LOGMANAGER_WriteLogV(&gszEmptyAssertText, 0, 0, szFormat, args);
}

// 0x00410740
void __cdecl LOGMANAGER_LogWritePrefixed(const char* szPrefix, const char* szFormat, ...)
{
    D2_ASSERT(szFormat, 371);
    if (!szPrefix)
    {
        szPrefix = &gszEmptyAssertText;
    }
    va_list args;
    va_start(args, szFormat);
    LOGMANAGER_WriteLogV(szPrefix, 0, 0, szFormat, args);
}

// 0x0040F720
void __fastcall LOGMANAGER_WriteMessage(LogManager::Message* pMessage)
{
    D2_ASSERT(pMessage->nType == 1, 0x2A1);
    char* szName = pMessage->GetName();
    char* szText = szName + SStrLen(szName) + 1;
    int nSlot;
    _iobuf* pFile = LOGMANAGER_GetLogFile(szName, &nSlot);
    if (pFile)
    {
        if (pMessage->bTimeStamp)
            fprintf(pFile, "%02d:%02d:%02d.%03d  ", pMessage->tTimeStamp.wHour, pMessage->tTimeStamp.wMinute, pMessage->tTimeStamp.wSecond, pMessage->tTimeStamp.wMilliseconds);
        fwrite(szText, SStrLen(szText), 1, pFile);
// build: symbol ?gadwLogWriteTick@* 0x0075D2F0
        gadwLogWriteTick[nSlot] = GetTickCount();
    }
}

// 0x0040F7D0
sub_0040F7D0::~sub_0040F7D0()
{
    tLink.Unlink();
}

// 0x0040F860
void D2ChatStormListAStrc::IGNORELIST_ResetStringList()
{
    m_linkoffset = 0;
    InitializeTerminator();
}

// 0x0040F970
void __cdecl LOGMANAGER_SweepOldLogFiles()
{
    if (gdwLastLogSweep && GetTickCount() - gdwLastLogSweep < 86400000)
    {
        return;
    }
    gdwLastLogSweep = GetTickCount();
    LeaveCriticalSection(&gtLogLock);
    LOGMANAGER_CloseLogFilesNow();
    EnterCriticalSection(&gtLogLock);
    D2SystemTimeStrc tNow;
    GetLocalTime(&tNow);
    D2FileTimeStrc ftNow;
    SystemTimeToFileTime(&tNow, &ftNow);
    char szDirectory[0x104];
    LOGMANAGER_GetLogDirectory(szDirectory, sizeof(szDirectory));
    char szPattern[0x104];
    SStrPrintf(szPattern, sizeof(szPattern), "%sd2*.txt", szDirectory);
    D2FindDataStrc tFind;
    void* hFind = FindFirstFileA(szPattern, &tFind);
    if (hFind != (void*)-1)
    {
        do
        {
            char szFile[0x104];
            SStrPrintf(szFile, sizeof(szFile), "%s%s", szDirectory, tFind.cFileName);
            LOGMANAGER_SweepLogFile(&ftNow, szFile);
        }
        while (FindNextFileA(hFind, &tFind));
        FindClose(hFind);
    }
}

// 0x0040F590
extern "C" void* __fastcall sub_0040F590(void* value) { return value; }

char gaszLogNames[20][0x10]; // 0x0075D148

unsigned long gadwLogWriteTick[20]; // 0x0075D2F0

_iobuf* gapLogFiles[20]; // 0x0075E790

// 0x0040F470
void __fastcall LOGMANAGER_CloseNamedLog(const char* szName)
{
    for (int i = 0; i < 20; i++)
    {
        if (gapLogFiles[i] && !strcmp(gaszLogNames[i], szName))
        {
            if (gapLogFiles[i])
            {
                fclose(gapLogFiles[i]);
                gapLogFiles[i] = 0;
            }
            return;
        }
    }
}

// 0x0040EDE0
_iobuf* __fastcall LOGMANAGER_GetLogFile(const char* szName, int* pnSlot)
{
    const unsigned long dwTick = GetTickCount();
    int nEmpty = -1;
    int nFree = -1;
    int nOldest;
    int nSlot = -1;
    _iobuf* pFile;

    int i = szName[0] != 0;
    nOldest = 1;
    for (; i < 20; ++i)
    {
// build: symbol ?gaszLogNames@* 0x0075D148
        if (!strcmp(gaszLogNames[i], szName))
        {
            nSlot = i;
// build: symbol ?gapLogFiles@* 0x0075E790
            pFile = gapLogFiles[i];
            if (pFile)
            {
                goto done;
            }
            break;
        }

        if (!gaszLogNames[i][0])
        {
            if (nEmpty < 0)
            {
                nEmpty = i;
            }
        }
        else if (!gapLogFiles[i])
        {
            if (nFree < 0)
            {
                nFree = i;
            }
// build: symbol ?gadwLogWriteTick@* 0x0075D2F0
            else if (dwTick - gadwLogWriteTick[i] > gadwLogWriteTick[nFree])
            {
                nFree = i;
            }
        }
        else if (dwTick - gadwLogWriteTick[i] > dwTick - gadwLogWriteTick[nOldest])
        {
            nOldest = i;
        }
    }

    if (nSlot < 0)
    {
        if (nEmpty >= 0)
        {
            nSlot = nEmpty;
        }
        else
        {
            if (nFree >= 0)
            {
                nOldest = nFree;
            }

            if (gapLogFiles[nOldest])
            {
                fclose(gapLogFiles[nOldest]);
                gapLogFiles[nOldest] = 0;
            }

            nSlot = nOldest;
        }
    }

    {
        D2_ASSERT(SStrLen(szName) < 16, 0x34C);
        strcpy(gaszLogNames[nSlot], szName);

        D2SystemTimeStrc tTime;
        int bNew;
        _iobuf* pNewFile = LOGMANAGER_OpenDatedLogFile(szName, &tTime, "a", &bNew, gaszLogFilePaths[nSlot], 0x104);
        gapLogFiles[nSlot] = pNewFile;
        gadwLogOpenTick[nSlot] = dwTick;
        gadwLogWriteTick[nSlot] = dwTick;
        if (ganLogNewFile[nSlot] && pNewFile)
        {
            LOGMANAGER_WriteStartupBanner(pNewFile);
            ganLogNewFile[nSlot] = 0;
        }
        else if (bNew)
        {
            LOGMANAGER_WriteDateBanner(pNewFile, &tTime);
        }
    }

    pFile = gapLogFiles[nSlot];

done:
    if (pFile && pnSlot)
    {
        *pnSlot = nSlot;
    }

    return pFile;
}

// 0x0040F070
void __fastcall LOGMANAGER_WriteDumpMessage(LogManager::Message* pMessage)
{
    D2SystemTimeStrc* const pStamp = &pMessage->tTimeStamp;
    D2_ASSERT(pMessage->nType == 2, 0x389);
    char* szName = pMessage->GetName();
    D2LogDumpStrc* pDump = (D2LogDumpStrc*)(szName + SStrLen(szName) + 1);
    const unsigned char* pData;
    char* const szLabel = pDump->szLabel;
    if (pDump->bIndirect)
    {
        pData = pDump->pAddress;
    }
    else
    {
        pData = (const unsigned char*)(szLabel + SStrLen(szLabel) + 1);
    }

    int nSlot;
    _iobuf* pFile = LOGMANAGER_GetLogFile(szName, &nSlot);
    if (!pFile)
    {
        return;
    }

    char szTime[32];
    SStrPrintf(szTime, sizeof(szTime), gszLogTimeStampFormat, pStamp->wHour, pStamp->wMinute, pStamp->wSecond, pStamp->wMilliseconds);
    char szWhite[32];
    SStrCopy(szWhite, gszLogBlankStamp, sizeof(szWhite));

    const unsigned char* pCur = pData;
    unsigned int nRemain = pDump->nSize;
    int bFirst = 1;
    while (nRemain > 0)
    {
        const unsigned int nOffset = pCur - pData;
        fprintf(pFile, pDump->bShortAddress ? gszLogDumpAddress16 : gszLogDumpAddress32, bFirst ? szTime : szWhite, szLabel, pDump->bShortAddress ? nOffset : (unsigned int)pDump->pAddress + nOffset);
        bFirst = 0;
        unsigned int nLine = nRemain < 16 ? nRemain : 16;

        char szLine[0x100];
        szLine[0] = 0;
        if (IsBadReadPtr(pCur, nLine))
        {
            SStrCopy(szLine, gszLogUnreadable, 0x7FFFFFFF);
        }
        else
        {
            unsigned int i;
            for (i = 0; i < nLine; ++i)
            {
                const unsigned int nLen = strlen(szLine);
                SStrPrintf(&szLine[nLen], sizeof(szLine) - nLen, (i & 3) ? gszLogDumpByte : gszLogDumpByteSpaced, pCur[i]);
            }

            if (pDump->bShowAscii)
            {
                for (i = (16 - nLine) * 9 / 4 + 2; i; --i)
                {
// build: symbol ?gszSpace@* 0x006FFC44
                    SStrPack(szLine, gszSpace, sizeof(szLine));
                }

                const int nLen = strlen(szLine);
                int j = nLen;
                for (i = 0; i < nLine; ++i)
                {
                    unsigned char c = pCur[i];
                    szLine[j++] = (c & 0x7F) < 0x20 ? '.' : c;
                }
                szLine[nLen + i] = 0;
            }
        }

        fprintf(pFile, gszLogLineFormat_006CD90C, szLine);
        pCur += nLine;
        nRemain -= nLine;
    }
}

// 0x0040F350
void __cdecl LOGMANAGER_CloseStaleLogs()
{
    char szPath[0x104];
    int bLog = 0;
    szPath[0] = 0;
    unsigned long nNow = GetTickCount();
    for (int i = 0; i < 20; ++i)
    {
        if (gapLogFiles[i])
        {
            if (nNow - gadwLogOpenTick[i] > 15000 || nNow - gadwLogWriteTick[i] > 5000)
            {
                if (bLog)
                {
                    OutputDebugStringA(szPath);
                }
                fclose(gapLogFiles[i]);
                gapLogFiles[i] = 0;
            }
        }
    }
}

struct PairStrc_0040F570
{
    int nFirst;
    int nSecond;
};

// 0x0040F570
void __fastcall sub_0040F570(PairStrc_0040F570* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

extern "C" const char gData_006CE1A4[8] = " %02X"; // 0x006CE1A4
#pragma comment(linker, "/alternatename:_gszLogDumpByteSpaced=_gData_006CE1A4")

extern "C" const char gData_006CE1AC[8] = "%02X"; // 0x006CE1AC
#pragma comment(linker, "/alternatename:_gszLogDumpByte=_gData_006CE1AC")

extern "C" const char gData_006CE1B4[12] = "%s%s%08X:"; // 0x006CE1B4
#pragma comment(linker, "/alternatename:_gszLogDumpAddress32=_gData_006CE1B4")

extern "C" const char gData_006CE1C0[12] = "%s%s%04X:"; // 0x006CE1C0
#pragma comment(linker, "/alternatename:_gszLogDumpAddress16=_gData_006CE1C0")

extern "C" const char gData_006CE1CC[16] = "              "; // 0x006CE1CC
#pragma comment(linker, "/alternatename:_gszLogBlankStamp=_gData_006CE1CC")
