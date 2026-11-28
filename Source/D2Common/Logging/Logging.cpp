#include "D2Common.h"
#include "D2CmpTileRecord.h"
#include "D2DrlgMaps.h"
#include "D2CmpTypes.h"
#include "D2LRUNode.h"

#include "D2GameTypes.h"

#include "D2Win32Types.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2LevelTxt.h"
#include "StormApi.h"

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock);    // 0x006CC210

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock);        // 0x006CC1FC

extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode);                               // 0x0068239A

extern "C" int __cdecl fclose(_iobuf* pFile);                                                               // 0x00681FDC


D2CriticalSectionStrc gLogLock;                                                                    // 0x0096CA30

_iobuf* gpLogFile;                                                                                 // 0x0096CA48

int gbLogEnabled;                                                                                  // 0x0096CA4C

int gnLogValue;                                                                                    // 0x0096CA50

struct D2StatStrc;

struct D2StatsArrayStrc;

struct D2ItemStatCostTxt;

struct D2StatesTxt;

typedef unsigned int size_t;

extern D2DataTablesStrc* sgptDataTables;

extern unsigned int gdwBitMasks[];

extern unsigned int gdwInvBitMasks[];

D2StatesTxt* __fastcall DATATBLS_GetStatesTxtRecord(int nStateId);


typedef char* va_list;


extern "C" int __cdecl SStrVPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, va_list va); // 0x00413A80

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" unsigned int __cdecl strlen(const char* sz);

// 0x00624700
void __fastcall LOGGING_SetLogValue(int nValue)
{
    gnLogValue = nValue;
}

// 0x00624710
_iobuf* __cdecl sub_00624710_GetLogFile()
{
    return gpLogFile;
}

// 0x00624720
static _iobuf* LOGGING_OpenLogFile(const char* szFileName)
{
    return fopen(szFileName, "wt");
}

// 0x00624730
static void LOGGING_CloseLogFile(_iobuf* pFile)
{
    fclose(pFile);
}

// 0x00624740
void __stdcall LOGGING_FormatLocalTime(char* szBuffer, size_t nSize)
{
    D2SystemTimeStrc tTime;
    GetLocalTime(&tTime);
    SStrPrintf(szBuffer, nSize, "%02u:%02u:%02u.%03u\t", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
}

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&(v) + _INTSIZEOF(v))

// 0x00624780
static void __stdcall StoreLogging(_iobuf* pFile, int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, va_list va)
{
    if (!gbLogEnabled)
        return;

    D2SystemTimeStrc tTime;
    char szBuffer[500];
    GetLocalTime(&tTime);
    const int nTime = SStrPrintf(szBuffer, 500, "%02u:%02u:%02u.%03u\t", tTime.wHour, tTime.wMinute, tTime.wSecond, tTime.wMilliseconds);
    char* pCursor = &szBuffer[nTime];
    int nRemaining = 500 - nTime;
    const int nFields = SStrPrintf(pCursor, nRemaining, "%01lu\t%01lu\t%01lu\t%02lu\t%.50s\t%.5lu\t", nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence);
    nRemaining -= nFields;
    pCursor += nFields;
    const int nLength = SStrVPrintf(pCursor, nRemaining, szFormat, va);
    strcat(pCursor + nLength, "\n");
    fwrite(szBuffer, strlen(szBuffer), 1, pFile);
    fflush(pFile);
}

// 0x006248B0
void __cdecl LOGGING_WriteLogEntry(_iobuf* pFile, int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...)
{
    va_list va;
    va_start(va, szFormat);
    StoreLogging(pFile, nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence, szFormat, va);
}

// 0x006248E0
void __cdecl LOG_11100(int nThreadId, int nLogLevel, int nComponent, int nSubsystem, const char* szContext, int nSequence, const char* szFormat, ...)
{
    if (!gpLogFile)
        return;

    EnterCriticalSection(&gLogLock);
    va_list va;
    va_start(va, szFormat);
    StoreLogging(gpLogFile, nThreadId, nLogLevel, nComponent, nSubsystem, szContext, nSequence, szFormat, va);
    LeaveCriticalSection(&gLogLock);
}

// 0x00624930
void __cdecl LOGGING_WriteGameLogLine(int nGame, int nFrame, int nClient, int nType, int nSize, const char* szFormat, ...)
{
    if (!gpLogFile)
    {
        return;
    }
    if (!gbLogEnabled)
    {
        return;
    }

    EnterCriticalSection(&gLogLock);

    char szBuffer[500];
    SStrPrintf(szBuffer, 500, "Game:%02d\tFrame:%d\tClient:%02d\t", nGame, nFrame, nClient);
    if (nType == 1)
    {
        strcat(szBuffer, "Type:System\t");
    }
    else
    {
        strcat(szBuffer, "Type:Game\t");
    }

    const int nLength = strlen(szBuffer);
    char* pCursor = &szBuffer[nLength];
    int nRemaining = 500 - nLength;
    const int nWritten = SStrPrintf(pCursor, nRemaining, "Size:%d\n", nSize);
    nRemaining -= nWritten;
    pCursor += nWritten;

    va_list va;
    va_start(va, szFormat);
    SStrVPrintf(pCursor, nRemaining, szFormat, va);
    strcat(pCursor, "\n\n");

    fwrite(szBuffer, strlen(szBuffer), 1, gpLogFile);
    fflush(gpLogFile);
    LeaveCriticalSection(&gLogLock);
}

// 0x00624AC0
int __fastcall LOGGING_OpenLog(const char* szFileName)
{
    if (!gpLogFile)
    {
        gpLogFile = LOGGING_OpenLogFile(szFileName);
        if (!gpLogFile)
            return 0;
        InitializeCriticalSection(&gLogLock);
        LOG_11100(1, 8, 2, 0x80000, ".\\Logging\\Logging.cpp", 249, "Log Started");
    }
    return 1;
}

// 0x00624B20
void __cdecl LOGGING_CloseLog()
{
    if (gpLogFile)
    {
        LOGGING_CloseLogFile(gpLogFile);
        DeleteCriticalSection(&gLogLock);
        gpLogFile = 0;
    }
}

// 0x00624B50
void __fastcall LOGGING_SetLoggingEnabled(int bEnable)
{
    gbLogEnabled = bEnable;
    if (bEnable)
    {
        LOGGING_OpenLog("d2log.txt");
        return;
    }
    LOGGING_CloseLog();
}

// build: symbol ?sub_00624B90_FindStatIndex@* 0x00624B90
static int sub_00624B90_FindStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    D2StatStrc* pStat = pStatsArray->pStat;
    int nMax = pStatsArray->nStatCount;
    int nMin = 0;
    while (nMin < nMax)
    {
        const int nMid = nMin + (nMax - nMin) / 2;
        const int nPackedValue = pStat[nMid].nPackedValue;
        if (nLayer_StatId > nPackedValue)
        {
            nMin = nMid + 1;
        }
        else if (nLayer_StatId < nPackedValue)
        {
            nMax = nMid;
        }
        else
        {
            return nMid;
        }
    }
    return -1;
}

// build: symbol ?STATLIST_FindStat@* 0x00624C60
static D2StatStrc* STATLIST_FindStat(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = sub_00624B90_FindStatIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }
    return &pStatsArray->pStat[nIndex];
}

// build: symbol ?STATLIST_GetTotalStat@* 0x00624F60
static int __stdcall STATLIST_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    D2StatStrc* pStat = STATLIST_FindStat((pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatListEx->FullStats : &pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && pStatListEx->pOwner && (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

#pragma pack(push, 1)
struct d2data_00744588_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00744588_t gData_00744588; // 0x00744588

extern "C" struct d2data_00744588_t gData_00744588 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00744588
