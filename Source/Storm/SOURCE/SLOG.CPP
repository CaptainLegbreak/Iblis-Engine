#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "StormApi.h"

D2CriticalSectionStrc gaSLogLocks[4]; // 0x00779238

D2SLogStrc* gapSLogBuckets[4]; // 0x00779298

static unsigned long gnSLogTimeLength; // 0x007792A8

static char gszSLogTime[0x40]; // 0x007792B0

static unsigned long gdwSLogLastTick; // 0x007792F0

int gbSLogDebugOutput; // 0x007790AC

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, size_t nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C

extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, size_t nSize, unsigned long dwFreeType); // 0x006CC220

extern "C" __declspec(dllimport) int __stdcall WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x006CC1A8

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340

extern "C" __declspec(dllimport) void* __stdcall CreateFileA(const char* szFileName, unsigned long dwAccess, unsigned long dwShare, void* pSecurity, unsigned long dwCreation, unsigned long dwFlags, void* hTemplate); // 0x006CC19C

void __stdcall SLogClose(void* hLog);                                                                       // 0x0041FD00

void __cdecl SLogFlushAll();                                                                                // 0x0041FFF0

void __stdcall SErrReportResourceLeak(const char* szName);                                           // 0x0041D1E0

static unsigned long gnSLogLastHandle; // 0x00779230

// 0x0041FA40
static void FlushLog(D2SLogStrc* pLog)
{
    unsigned long dwWritten;
    if (pLog->nUsed)
    {
        WriteFile(pLog->hFile, pLog->szBuffer, pLog->nUsed, &dwWritten, 0);
        FlushFileBuffers(pLog->hFile);
        pLog->nUsed = 0;
        pLog->nPended = 0;
    }
}

// 0x0041FA80
static D2SLogStrc* __stdcall LockLog(unsigned long* pIndex, int bCreate, void* hLog)
{
    if (!hLog)
    {
        *pIndex = (unsigned long)-1;
        return 0;
    }
    unsigned long nIndex = (unsigned long)hLog & 3;
    EnterCriticalSection(&gaSLogLocks[nIndex]);
    *pIndex = nIndex;
    D2SLogStrc** ppNext = &gapSLogBuckets[nIndex];
    for (D2SLogStrc* p = *ppNext; p; p = *ppNext)
    {
        if (p->hLog == hLog)
            return p;
        ppNext = &p->pNext;
    }
    if (!bCreate)
    {
        LeaveCriticalSection(&gaSLogLocks[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    D2SLogStrc* pLog = (D2SLogStrc*)VirtualAlloc(0, sizeof(D2SLogStrc), 0x1000, 4);
    *ppNext = pLog;
    if (!pLog)
    {
        LeaveCriticalSection(&gaSLogLocks[nIndex]);
        *pIndex = (unsigned long)-1;
        return 0;
    }
    pLog->hLog = hLog;
    pLog->pNext = 0;
    pLog->hFile = (void*)-1;
    pLog->nUsed = 0;
    pLog->nPended = 0;
    return pLog;
}

// 0x0041FB40
static void AppendIndent(D2SLogStrc* pLog)
{
    int nIndent = pLog->indent;
    if (nIndent > 0)
    {
        if (nIndent >= 0x80)
            nIndent = 0x80;
        memset(pLog->szBuffer + pLog->nUsed, ' ', nIndent);
        pLog->szBuffer[pLog->nUsed + nIndent] = 0;
        pLog->nUsed += nIndent;
    }
}

// 0x0041FB80
static void AppendNewline(D2SLogStrc* pLog)
{
    SMemCopy(pLog->szBuffer + pLog->nUsed, gszSLogNewline, 3);
    pLog->nUsed += 2;
}

// 0x0041FBA0
static void __stdcall AppendTimestamp(int bText, D2SLogStrc* pLog)
{
    if (!pLog->bTimestamp)
        return;
    unsigned long dwTick = GetTickCount();
    if (dwTick != gdwSLogLastTick)
    {
        gdwSLogLastTick = dwTick;
        D2SystemTimeStrc tTime;
        GetLocalTime(&tTime);
        wsprintfA(gszSLogTime, "%u/%u %02u:%02u:%02u.%03u  ", tTime.wMonth, tTime.wDay, tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
        gnSLogTimeLength = SStrLen(gszSLogTime);
    }
    if (bText)
    {
        SMemCopy(pLog->szBuffer + pLog->nUsed, gszSLogTime, gnSLogTimeLength + 1);
    }
    else
    {
        SMemFill(pLog->szBuffer + pLog->nUsed, gnSLogTimeLength, ' ');
        pLog->szBuffer[pLog->nUsed + gnSLogTimeLength] = 0;
    }
    pLog->nUsed += gnSLogTimeLength;
    AppendIndent(pLog);
}

// 0x0041FC80
static void FreeLog(D2SLogStrc* pLog, unsigned long nIndex)
{
    D2SLogStrc** ppNext = &gapSLogBuckets[nIndex];
    for (D2SLogStrc* p = *ppNext; p; p = *ppNext)
    {
        if (p == pLog)
        {
            *ppNext = p->pNext;
            VirtualFree(p, 0, 0x8000);
            break;
        }
        ppNext = &p->pNext;
    }
    LeaveCriticalSection(&gaSLogLocks[nIndex]);
}

// 0x0041FCE0
static void UnlockLog(unsigned long nIndex)
{
    LeaveCriticalSection(&gaSLogLocks[nIndex]);
}

// 0x0041FD00
void __stdcall SLogClose(void* hLog)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        FlushLog(pLog);
        CloseHandle(pLog->hFile);
        FreeLog(pLog, nIndex);
    }
}

// 0x0041FD40
int __stdcall SLogCreate(const char* szFileName, unsigned long dwFlags, void** phLog)
{
    VALIDATEBEGIN;
    VALIDATE(szFileName);
    VALIDATEKEEP(*szFileName);
    if (!phLog)
        nValid = 0;
    if (phLog)
        *phLog = 0;
    VALIDATEEND;
    void* hFile = CreateFileA(szFileName, 0x40000000, 3, 0, 2, 0x80, 0);
    if (hFile == (void*)-1)
        return 0;
    void* hLog = (void*)++gnSLogLastHandle;
    *phLog = hLog;
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 1, hLog);
    if (!pLog)
    {
        *phLog = 0;
        return 0;
    }
    pLog->hFile = hFile;
    pLog->bTimestamp = 1;
    pLog->indent = 0;
    UnlockLog(nIndex);
    return 1;
}

// 0x0041FDF0
void __stdcall SLogDump(void* hLog, const void* pData, unsigned long nSize)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    for (unsigned long nOffset = 0; nOffset < nSize; nOffset += 8)
    {
        AppendTimestamp(0, pLog);
        wsprintfA(pLog->szBuffer + pLog->nUsed, "%04x: ", nOffset);
        pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
        for (unsigned long i = nOffset; i < nOffset + 8; ++i)
        {
            if (i < nSize)
            {
                wsprintfA(pLog->szBuffer + pLog->nUsed, "%02x ", ((const unsigned char*)pData)[i]);
                pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
            }
            else
            {
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, "   ", 0x7FFFFFFF);
            }
            if ((i & 3) == 3)
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, "  ", 0x7FFFFFFF);
        }
        for (unsigned long i = nOffset; i < nOffset + 8; ++i)
        {
            char c = (i < nSize) ? ((const char*)pData)[i] : 0;
            if (c >= ' ' && c <= '~')
            {
                wsprintfA(pLog->szBuffer + pLog->nUsed, "%c", c);
                pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
            }
            else
            {
// build: symbol ?gszSpace@* 0x006FFC44
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, c ? gszDot : gszSpace, 0x7FFFFFFF);
            }
            if ((i & 7) == 3)
                pLog->nUsed += SStrCopy(pLog->szBuffer + pLog->nUsed, gszSpace, 0x7FFFFFFF);
        }
        AppendNewline(pLog);
    }
    if (gbSLogDebugOutput)
        OutputDebugStringA(pLog->szBuffer + pLog->nPended);
    pLog->nPended = pLog->nUsed;
    if (pLog->nUsed >= 0xC000)
        FlushLog(pLog);
    UnlockLog(nIndex);
}

// 0x0041FFC0
void __stdcall SLogFlush(void* hLog)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        FlushLog(pLog);
        UnlockLog(nIndex);
    }
}

// 0x0041FFF0
void __cdecl SLogFlushAll()
{
    for (unsigned int i = 0; i < 4; ++i)
    {
        EnterCriticalSection(&gaSLogLocks[i]);
        for (D2SLogStrc* p = gapSLogBuckets[i]; p; p = p->pNext)
            FlushLog(p);
        LeaveCriticalSection(&gaSLogLocks[i]);
    }
}

// 0x00420040
void __cdecl SLogInitialize()
{
    D2CriticalSectionStrc* pLock = gaSLogLocks;
    int n = 4;
    do
    {
        InitializeCriticalSection(pLock);
        ++pLock;
    }
    while (--n);
}

// 0x00420070
void __cdecl SLogPend(void* hLog, const char* szFormat, ...)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    pLog->nUsed = pLog->nPended;
    AppendTimestamp(1, pLog);
    va_list args;
    va_start(args, szFormat);
    vsprintf(pLog->szBuffer + pLog->nUsed, szFormat, args);
    pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
    AppendNewline(pLog);
    UnlockLog(nIndex);
}

// 0x004200E0
int __stdcall SLogSetAbsIndent(void* hLog, int nIndent)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return 0;
    int nOld = pLog->indent;
    pLog->indent = nIndent;
    UnlockLog(nIndex);
    return nOld;
}

// 0x00420120
int __stdcall SLogSetIndent(void* hLog, int nDelta)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return 0;
    int nOld = pLog->indent;
    pLog->indent = nOld + nDelta;
    UnlockLog(nIndex);
    return nOld;
}

// 0x00420160
void __stdcall SLogSetTimestamp(void* hLog, int bTimestamp)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (pLog)
    {
        pLog->bTimestamp = bTimestamp;
        UnlockLog(nIndex);
    }
}

// 0x00420190
void __cdecl SLogWrite(void* hLog, const char* szFormat, ...)
{
    unsigned long nIndex;
    D2SLogStrc* pLog = LockLog(&nIndex, 0, hLog);
    if (!pLog)
        return;
    AppendTimestamp(1, pLog);
    va_list args;
    va_start(args, szFormat);
    vsprintf(pLog->szBuffer + pLog->nUsed, szFormat, args);
    pLog->nUsed += SStrLen(pLog->szBuffer + pLog->nUsed);
    AppendNewline(pLog);
    if (gbSLogDebugOutput)
        OutputDebugStringA(pLog->szBuffer + pLog->nPended);
    pLog->nPended = pLog->nUsed;
    if (pLog->nUsed >= 0xC000)
        FlushLog(pLog);
    UnlockLog(nIndex);
}

// 0x00420220
void __cdecl SLogDestroy()
{
    SLogFlushAll();
    D2CriticalSectionStrc* pLock = gaSLogLocks;
    D2SLogStrc** ppBucket = gapSLogBuckets;
    for (int n = 4; n; --n)
    {
        EnterCriticalSection(pLock);
        while (*ppBucket)
        {
            SLogClose((*ppBucket)->hLog);
            SErrReportResourceLeak("HSLOG");
        }
        LeaveCriticalSection(pLock);
        ++ppBucket;
        ++pLock;
    }
    pLock = gaSLogLocks;
    for (int n = 4; n; --n)
    {
        DeleteCriticalSection(pLock);
        ++pLock;
    }
}
