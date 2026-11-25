#pragma once

#include "D2SysTypes.h"

struct D2BnMessageStrc;
struct D2FileTimeStrc;
struct D2InAddrStrc;
struct D2SystemTimeStrc;
struct D2TimeZoneInformationStrc;
struct FSafeSock;

bool __fastcall sub_00516DE1_CanRunSurvey(const char* szExePath); // 0x00516DE1
const char* __fastcall sub_00523AB0_GetCDKey(int nSlot); // 0x00523AB0
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C
extern "C" __declspec(dllimport) int __stdcall GetLocaleInfoA(unsigned long nLocale, unsigned long nLCType, char* pData, int nData); // 0x006CC394
extern "C" __declspec(dllimport) long __stdcall InterlockedExchange(long volatile* pTarget, long nValue); // 0x006CC3A4
extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend); // 0x006CC208
extern "C" __declspec(dllimport) struct HINSTANCE__* __stdcall ShellExecuteA(struct HWND__* hWnd, const char* szOperation, const char* szFile, const char* szParameters, const char* szDirectory, int nShowCmd); // 0x006CC438
extern "C" __declspec(dllimport) unsigned long __stdcall CharLowerBuffA(char* pString, unsigned long nLength); // 0x006CC518
extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC
extern "C" __declspec(dllimport) unsigned long __stdcall GetTimeZoneInformation(D2TimeZoneInformationStrc* pTimeZoneInformation); // 0x006CC388
extern "C" __declspec(dllimport) unsigned long __stdcall GetUserDefaultLCID(void); // 0x006CC398
extern "C" __declspec(dllimport) unsigned short __stdcall GetUserDefaultLangID(void); // 0x006CC384
extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime); // 0x006CC1D4
extern "C" __declspec(dllimport) void __stdcall GetSystemTime(D2SystemTimeStrc* pSystemTime); // 0x006CC38C
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148
extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144
extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" char* __stdcall inet_ntoa(D2InAddrStrc tAddress); // 0x006B013E
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszConfiguration[]; // 0x006DEC7C
extern "C" const char gszDiabloGateways[]; // 0x006DEC8C
extern "C" const char gszOverrideGateways[]; // 0x006DECAC
extern "C" const char gszWritingDefaultGateways[]; // 0x006DED24
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" int __cdecl _strnicmp(const char* szString1, const char* szString2, unsigned int nCount); // 0x00686040
extern "C" int __cdecl _vsnprintf(char* szDest, unsigned int nCount, const char* szFormat, char* pArgs); // 0x00682F22
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl toupper(int nChar); // 0x00685385
extern "C" int __stdcall WSAGetLastError(); // 0x006B0168
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" unsigned long __stdcall inet_addr(const char* szAddress); // 0x006B0150
extern D2BnMessageStrc* gpMessageHead; // 0x00882020
extern D2BnMessageStrc* gpMessageTail; // 0x00882024
extern char gszEmptyStateText[]; // 0x00881F80
extern const char* gpszNewsName_0072FF80; // 0x0072FF80
extern int gnCacheValue_00881890; // 0x00881890
extern unsigned int gadwCacheCrcTable[]; // 0x0072FB80
void __cdecl SLogWrite(void* hLog, const char* szFormat, ...); // 0x00420190
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __cdecl sub_0051A570_GetMode(); // 0x0051A570
int __cdecl GAME_GetAbortFlag(); // 0x00520AE0
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
int __fastcall FOG_SOCKET_GetPeerName(FSafeSock* pSafeSock, void* pAddress, int* pnLength); // 0x0040DEE0
int __fastcall FOG_SOCKET_Receive(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength); // 0x0040DC60
int __fastcall FOG_SOCKET_Select(FSafeSock* pSafeSock); // 0x0040DDF0
int __fastcall sub_0051E3D0_PostMessage(const char* szText, int nCode); // 0x0051E3D0
void __fastcall BNDOWNLOAD_RequestDownload(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910
int __fastcall BNDOWNLOAD_WaitForReply(unsigned char nReply); // 0x00520B70
int __fastcall BNDOWNLOAD_IsReplyReceived(unsigned char nReply); // 0x00520BF0
int __fastcall sub_00522AE0_DecodeCDKey(const char* szKey, void* pArg2, void* pArg3, void* pArg4); // 0x00522AE0
int __stdcall SFileAuthenticateArchive(void* hArchive, unsigned int* pnResult); // 0x004172F0
int __stdcall SFileCloseArchive(void* hMpq); // 0x00419A80
int __stdcall SFileLoadFile(const char* szFileName, void** ppBuffer, unsigned int* pSize, unsigned int nExtraSize, void* pOverlapped); // 0x0041B650
int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq); // 0x0041BA60
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, int nSearchScope, void** phFile); // 0x004192F0
int __stdcall SLogCreate(const char* szFileName, unsigned long dwFlags, void** phLog); // 0x0041FD40
int __stdcall SRegLoadData(const char* szKeyName, const char* szValueName, unsigned int nFlags, void* pBuffer, unsigned int nBufferSize, unsigned int* pnBytesRead); // 0x00414DE0
unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800
void __cdecl sub_00518C70_LogIndent(int nChannel, int nDelta); // 0x00518C70
void __cdecl sub_00520AD0_SetDisconnected(); // 0x00520AD0
void __fastcall FOG_SOCKET_Destroy(FSafeSock* pSafeSock); // 0x0040DBD0
void __fastcall sub_005209D0_HashData(unsigned char* pDigest, const void* pData, unsigned int nLength); // 0x005209D0
void __fastcall sub_00520C00_ClearReply(unsigned char nReply); // 0x00520C00
void __stdcall SLogClose(void* hLog); // 0x0041FD00
void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0
void __stdcall sub_0041D300_ZeroMemory(void* pDest, unsigned int nSize); // 0x0041D300
void __stdcall sub_00420120_LogAdjust(void* hLog, int nValue); // 0x00420120
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

#define CACHE_CRC32(dwCrc, pBytes, nCount) \
    dwCrc = 0xFFFFFFFF; \
    for (; nCount; --nCount, ++pBytes) \
        dwCrc = (dwCrc >> 8) ^ gadwCacheCrcTable[(*pBytes ^ dwCrc) & 0xFF]; \
    dwCrc = ~dwCrc
#include "SValidate.h"

struct D2BigLoginRecordStrc
{
    char szName[0x20];
    char szPassword[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abProof[0x14];
};

struct D2BnDnsArgsStrc
{
    char* szResult;
    const char* f_4;
};

struct D2BnMessageStrc
{
    int nId;
    char szText[0x120];
    unsigned int nLength;
    D2BnMessageStrc* pNext;
};

struct D2BnSizedReplyStrc
{
    unsigned int nSize;
    unsigned char abData[0x14];
    unsigned int nValue;
};

struct D2BnStateStrc
{
    int nState;
    void* pArg;
};

struct D2CacheHashEntryStrc
{
    unsigned int dwNameA;
    unsigned int dwNameB;
    unsigned int dwLocale;
    unsigned int dwBlockIndex;
};

#include "D2NetTypes.h"

#include "D2Win32Types.h"

struct D2TimeZoneInformationStrc
{
    long f_0;
    unsigned short wszStandardName[32];
    D2SystemTimeStrc tStandardDate;
    long nStandardBias;
    unsigned short wszDaylightName[32];
    D2SystemTimeStrc tDaylightDate;
    long nDaylightBias;
};

struct FSafeSock
{
    int bConnected;
    int bConnecting;
    unsigned int nSocket;
    D2CriticalSectionStrc tCriticalSection;
    void* hThread;
    unsigned long nThreadId;
    int bStopping;
    unsigned long nFogErrorCode;
    unsigned long nWSALastError;
    char szName[64];
};

typedef unsigned int size_t;
