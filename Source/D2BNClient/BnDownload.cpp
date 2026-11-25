#include "D2BNClient.h"

#include "D2GfxTypes.h"

#include "D2Win32Base.h"

#include "D2DDrawTypes.h"

#include "D2GlideTypes.h"

#include "D2GameTypes.h"

#include "D2Primitives.h"

#include "D2BnCryptTypes.h"
#include "D2BnMessages.h"

static int BNDOWNLOAD_CheckStringBlock(const char* pBuffer, unsigned int nPos, unsigned int nCount, unsigned int nSize); // 0x00520A80

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct D2BnStateStrc;

struct D2BnDnsArgsStrc;

struct D2BnLogStrc;

struct D2BnExtraWorkPacketStrc;

struct D2BnAdInfoStrc;

class BNGatewayAccess;

struct D2BnDownloadRecordStrc;

struct D2BnDownloadReplyStrc;

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long* pDestination, long nExchange, long nComparand); // 0x006CC3A0

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

unsigned long __stdcall BNSEND_ResolveHostThread(void* pArguments); // 0x0051BEE0

void __fastcall BNNEWS_SelectNewsFile(int bAlternate); // 0x0051D260

void __fastcall BNSEND_SendEnterChat(const char* szArg1, const char* szArg2, int nArg3); // 0x0051AE10

void __fastcall BNSEND_JoinChannel(const char* szText, int nArg2, int nArg3); // 0x0051ACA0

int __fastcall BNMESSQUEUE_SetError(int nError); // 0x005204A0

int __fastcall BNMESSQUEUE_SetState(int nState); // 0x00520520

int __fastcall BNMESSQUEUE_GetState(D2BnStateStrc* pState); // 0x005205F0

struct D2BnLogStrc
{
    void* hLog;

    D2BnLogStrc()
    {
        SLogCreate("BnetLog.txt", 0, &hLog);
    }

    ~D2BnLogStrc()
    {
        SLogClose(hLog);
    }

    void Write(const char* szText); // 0x00518BA0
};

extern int gbDnsPending; // 0x008818E0

extern long gnConnected; // 0x00881BF0

extern long gnDnsDone; // 0x00881BFC

unsigned int gnPercent;                                                                            // 0x00881C50

extern D2CriticalSectionStrc gtMessageLock; // 0x00882004

extern "C" const char gszBnMessQueueFile[]; // 0x006DF78C

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

int gbStopDownload;                                                                                // 0x00881C54

char gszDownloadArchive[260]; // 0x00881C58

char gszCheckRevisionValue[260]; // 0x00881E60

struct D2BnExtraWorkPacketStrc
{
    unsigned short wType;
    unsigned short wSize;
    unsigned int dwLocale;
    unsigned char pData[0xFFC];
};

struct D2BnAdInfoStrc
{
    unsigned int nArg1;
    unsigned int nArg2;
    char* szText1;
    char* szText2;
    void* pData;
    unsigned int nDataSize;
};

class BNGatewayAccess
{
public:
    void __stdcall UpdateGatewaysFromIni(char* szText);                                                     // 0x00518850
    void __stdcall Unload();                                                                         // 0x00517ED0

private:
    int unk0x00[9];
};

typedef int (__stdcall* D2CheckRevisionFn)(const char* szFile1, const char* szFile2, const char* szFile3, const char* szValue, int* pVersion, int* pChecksum, char* szExeInfo);

typedef int (__fastcall* D2ExtraWorkFn)(D2BnExtraWorkPacketStrc* pPacket);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* szBuffer); // 0x006CC344

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void* __stdcall GetModuleHandleA(const char* szModuleName); // 0x006CC198

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9

void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610

void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

int __stdcall SFileGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00416370

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

int __stdcall SFileReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped); // 0x0041B050

int __stdcall SFileCloseFile(void* pArg); // 0x004198D0

int __stdcall SFileOpenFile(const char* szFileName, void** phFile); // 0x00419980

void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall FOG_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0

int __fastcall FOG_CloseFile(void* hFile); // 0x004069A0

void __fastcall BNDOWNLOAD_SetStatus(int nStatus); // 0x0051EA40

int __fastcall BNSEND_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0

void __fastcall sub_0051B060_SetAdText(const char* szText1, const char* szText2); // 0x0051B060

void __fastcall sub_005202F0_PostText(int nType, const char* szText); // 0x005202F0

void __fastcall sub_00520210_PostData(int nType, const void* pData, unsigned int nSize); // 0x00520210

extern "C" const char gszBnDownloadFile[]; // 0x006DF338

char gszAdList[1]; // 0x00881D60

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

// A critical section for the whole run: initialized before main, deleted at exit.
struct CCritSect : D2CriticalSectionStrc
{
    CCritSect() { InitializeCriticalSection(this); }
    ~CCritSect() { DeleteCriticalSection(this); }
};

// build: symbol ??__EgtDownloadLock@@YAXXZ 0x006CAED0
// build: symbol ??__FgtDownloadLock@@YAXXZ 0x006CB470
CCritSect gtDownloadLock; // 0x00881F64

BNGatewayAccess gtBnGatewayAccess; // 0x00881838

typedef char check_int_width[(sizeof(int) == 4) ? 1 : -1];

typedef char check_long_width[(sizeof(long) == 4) ? 1 : -1];

typedef char check_uchar_width[(sizeof(unsigned char) == 1) ? 1 : -1];

extern "C" { long gnPendingCount; }                                                                // 0x00881D5C

extern "C" int gnFlag_00882528; // 0x00882528

int ganSlotArrayA[94]; // 0x00882128

extern "C" int ganSlotArrayB[94]; // 0x008822A8

extern "C" int gnValue_0088CB0C;

extern "C" int gnValue_0088CB10;

extern "C" __declspec(dllimport) int __stdcall GetFileTime(void* hFile, __int64* pCreation, __int64* pAccess, __int64* pWrite); // 0x006CC2F4

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void* hFile, unsigned long* pHigh); // 0x006CC2F0

struct D2BnDownloadRecordStrc
{
    unsigned short nSize;
    char nUnk0x02;
    char nUnk0x03;
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int nArg1;
    unsigned int nArg2;
    unsigned int nOffset;
    D2FileTimeStrc tFileTime;
    char szFile[0x104];
    char szLink[0x104];
    int nType;
    int nSubType;
};

struct D2BnDownloadReplyStrc
{
    unsigned int nSize;
    unsigned int nTotal;
    unsigned int nArg1;
    unsigned int nArg2;
    D2FileTimeStrc tFileTime;
    char szFile[1];
};

extern "C" __declspec(dllimport) int __stdcall SetFileTime(void* hFile, const D2FileTimeStrc* pCreation, const D2FileTimeStrc* pAccess, const D2FileTimeStrc* pWrite); // 0x006CC3A8

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pValue); // 0x006CC204

extern "C" int __stdcall connect(unsigned int nSocket, const D2SockAddrInStrc* pName, int nLength); // 0x006B014A

extern "C" unsigned short __stdcall htons(unsigned short nValue); // 0x006B0156

extern "C" int __stdcall setsockopt(unsigned int nSocket, int nLevel, int nName, const char* pValue, int nLength); // 0x006B0162

extern "C" unsigned int __stdcall socket(int nFamily, int nType, int nProtocol); // 0x006B016E

extern "C" int __stdcall recv(unsigned int nSocket, char* pBuffer, int nLength, int nFlags); // 0x006B0174

extern "C" int __stdcall send(unsigned int nSocket, const char* pBuffer, int nLength, int nFlags); // 0x006B017A

unsigned long __fastcall FOG_SetFilePointer(void* hFile, long nDistance, long* pnDistanceHigh, unsigned long dwMoveMethod); // 0x004069F0

int __fastcall FOG_SOCKET_CloseSocket(unsigned int s); // 0x0040D880

void __fastcall sub_00519DB0_HandOnDownload(const char* szFile, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, int nArg5, int nArg6); // 0x00519DB0

void __fastcall BNDOWNLOAD_ResolveHost(char* szResult, const char* szHost); // 0x0051C0E0

void __fastcall BNSEND_GetServerAddress(char* szText, int nSize); // 0x0051C190

int __fastcall sub_0051C9B0_GetPeerName(void* pAddress, int* pnLength); // 0x0051C9B0

void __fastcall BNDOWNLOAD_HandleDownloadEvent(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2, const void* pData, unsigned int nDataSize, int bFlag); // 0x0051FAB0

extern "C" const char gszRecvToBufferFailed[]; // 0x006DF380

static void __stdcall BNDOWNLOAD_WriteFileWithTime(const void* pData, unsigned int nSize, const char* szFile, const D2FileTimeStrc* pFileTime); // 0x0051E440

static int __stdcall BNDOWNLOAD_RecvAll(unsigned int nSocket, char* pBuffer, unsigned int nSize); // 0x0051E5F0

static unsigned long BNDOWNLOAD_GetFileSizeIfTimeMatches(const char* szFile, const __int64* pFileTime); // 0x0051E640

static int __stdcall BNDOWNLOAD_RecvToBuffer(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, int nFlags, char** ppBuffer, unsigned int nSize); // 0x0051EAB0

static int __stdcall BNDOWNLOAD_RecvToFile(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, unsigned int nOffset, unsigned int nTotal, int nType); // 0x0051EBB0

D2BnDnsArgsStrc gtDnsArgs; // 0x00881BE8

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                        // 0x006CC258

extern "C" __declspec(dllimport) int __stdcall CompareFileTime(const D2FileTimeStrc* pTime1, const D2FileTimeStrc* pTime2); // 0x006CC390

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pValue);                // 0x006CC208

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject);                                  // 0x006CC134

extern "C" unsigned int __cdecl _beginthreadex(void* pSecurity, unsigned int nStackSize, unsigned int (__stdcall* pfnStart)(void*), void* pArg, unsigned int nFlags, unsigned int* pThreadId); // 0x00688103

int __fastcall CACHE_WriteCachedFile(const char* szName, const void* pData, unsigned int nSize, const D2FileTimeStrc* pFileTime, unsigned int nSeconds1, unsigned int nSeconds2); // 0x00519DB0

int __fastcall FOG_SOCKET_WSAStartup();                                                                     // 0x0040D890

int __stdcall SRegSaveData(const char* szKeyName, const char* szValueName, unsigned int nFlags, const void* pData, unsigned long nSize); // 0x00415000

int __fastcall CACHE_LoadCachedFile(const char* szFile, D2FileTimeStrc* pFileTime, void** ppData, unsigned int* pnSize); // 0x00519920

int __fastcall CACHE_FreeCachedFile(void* pData, unsigned int nSize); // 0x005193C0

unsigned int __stdcall BNDOWNLOAD_DownloadThread(void* pArg);                                             // 0x0051F310

extern "C" const char gszAdListRegKey[];                                                           // 0x006DF45C

extern "C" const char gszAdListRegValue[];                                                         // 0x006DF464

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

int __stdcall sub_004192F0_OpenArchiveFile(void*, const char*, unsigned int, void**); // 0x004192F0

void* __stdcall sub_00413020_Alloc(unsigned int, const char*, int, unsigned int); // 0x00413020

static void __fastcall BNDOWNLOAD_ExtractFile(const char* member, void* archive, const char* destination); // 0x0051E920

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468

char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

static int BNDOWNLOAD_RunProgramList(const char* szList, const char* szDirectory); // 0x0051E9D0

struct D2BnPacket33HeaderStrc
{
    int nValue;
    int nZero;
};

int __cdecl BNSEND_SendCrashDump(); // 0x0051BCF0

int __fastcall sub_0051E370_SetText(const char* szText, int nLength); // 0x0051E370

int __fastcall BNMESSQUEUE_SetStateArg(void* pArg); // 0x00520550

#define HASH_ROL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

struct D2BnetHashContextStrc;

struct D2VersionReplyStrc;

struct D2BnReplyStrc;

struct D2BnetHashContextStrc
{
    unsigned int state[5];
    union
    {
        unsigned int block[16];
        unsigned char f_14[64];
    };
};

void __fastcall BNDOWNLOAD_HashTransform(D2BnetHashContextStrc* pContext); // 0x005206B0

struct D2VersionReplyStrc
{
    unsigned int nResult;
    char szText[1];
};

void __cdecl BNDOWNLOAD_LogPrintf(const char* szFormat, ...); // 0x00518D40

extern int gnUpdateState; // 0x008822C4

struct D2BnReplyStrc
{
    unsigned int nResult;
    char szText[0x100];
};

extern char gszReplyText_00882428[0x100]; // 0x00882428

int gnReplyReady; // 0x008823B0

unsigned int gnReplyResult; // 0x00882420

// build: symbol ??__EgtBnLogLock@@YAXXZ 0x006CAE80
// build: symbol ??__FgtBnLogLock@@YAXXZ 0x006CB420
CCritSect gtBnLogLock;                                                                  // 0x00881860

extern "C" void __cdecl D2CMPResetTileCacheHits(); // 0x005FE060

extern unsigned int gnVersion; // 0x0088252C

typedef unsigned int size_t;

#pragma intrinsic(strlen)

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl BNDOWNLOAD_ConfigureLog(int nMode, int nValue);                                               // 0x00518C70

void __fastcall sub_0051A540_SetValue(int nValue);                                                          // 0x0051A540

int __fastcall BNDOWNLOAD_SetCheckRevisionValue(const char* szValue);                                    // 0x0051E3B0

void __fastcall BNDOWNLOAD_RequestDownload(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910

int __fastcall BNMESSQUEUE_QueueMessage(int nId, const void* pData, unsigned int nLength);                // 0x00520210

extern "C" const char gszConfiguration[];                                                           // 0x006DEC7C

extern int gnLastStatus;                                                                              // 0x0072FFA8

int gnChangePasswordResult; // 0x008822A0

int gnCreateAccountResult; // 0x008822A4

int gdwGlobal_00882318;                                                                                     // 0x00882318

int gdwGlobal_00882350;                                                                                     // 0x00882350

int gbChangePasswordReplied;                                                                                     // 0x0088236C

int gbCreateAccountReplied;                                                                                     // 0x0088239C

extern "C" int __cdecl rand(); // 0x00687461

extern "C" void __cdecl srand(unsigned int nSeed); // 0x00687454

#define CHECK(p,line) if(!(p)){FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}

struct D2BigPowModStrc;

struct D2BnReportStrc;

struct D2BnTokenReplyStrc;

struct D2BnAuthInfoStrc;

struct D2BigLoginRecordStrc;

struct D2BnAccountLogonStrc;

struct D2BigPairStrc;

struct D2IdeaUserKeyStrc;

struct D2CipherKeyView;

struct D2BnReportStrc
{
    int nResult;
    int unk0x04;
    D2FileTimeStrc tFileTime;
    char szText[1];
};

void __fastcall BNSEND_SetChannelList(const void* pData, unsigned int nSize); // 0x0051BDC0

void __fastcall BNSEND_SetGamesList(const void* pData, unsigned int nSize); // 0x0051BE20

void __fastcall BNSEND_SetRealmList(const void* pData, unsigned int nSize); // 0x0051BD60

int __fastcall BNMESSQUEUE_QueueText(int nId, const char* szText); // 0x005202F0

int __fastcall BNSEND_SetInfoText(const char* szText); // 0x00520630

struct D2BnTokenReplyStrc
{
    int nResult;
    unsigned int nToken;
};

int __fastcall BNSEND_CheckServerProof(const unsigned char* pServerProof); // 0x005224C0

void __cdecl BNSEND_ClearPassword(); // 0x005224F0

int __fastcall BNSEND_SendAccountUpgradeProof(unsigned int nServerToken); // 0x005223F0

int __cdecl GAME_GetLoginRetryCount(); // 0x005224E0

int __fastcall sub_005223A0(int bFlag); // 0x005223A0

int __fastcall BNSEND_SendAccountChangeProof(const unsigned char* pSalt, const unsigned char* pServerKey); // 0x00522310

int __cdecl BNDOWNLOAD_ResendAccountLogon(); // 0x00522050

void __fastcall BNSEND_SetAdUrlReply(const void* pData, unsigned int nSize); // 0x0051AB30

void __fastcall BNSEND_SetRealmLogonReply(const void* pData, unsigned int nSize); // 0x0051B3E0

void __fastcall BNSEND_SetReadUserDataReply(const void* pData, unsigned int nSize); // 0x0051B820

void __fastcall BNSEND_SetEmailRequested(int nValue); // 0x0051CA80

int __fastcall BNDOWNLOAD_SendGetFileTime(const char* szText, int nCode); // 0x0051E3D0

int __fastcall BNNEWS_ParseNewsInfo(const void* pData); // 0x0051D860

void __fastcall sub_0051A560_SetValue(int nValue); // 0x0051A560

int __fastcall BNDOWNLOAD_SetArchiveName(const char* szName); // 0x0051EA80

extern int gnGlobal_008823B0; // 0x008823B0

int __fastcall BNSEND_SendAccountLogonProof(const unsigned char* pSalt, const unsigned char* pServerKey); // 0x005220B0

extern "C" long __cdecl _time32(long* pTime);

extern "C" int __cdecl tolower(int nChar);

// build: symbol ?gacCDKeyMap@* 0x006DF238
extern const char gacCDKeyMap[];

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144

extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C

extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID(void); // 0x006CC354

extern "C" const char gszKernel32[]; // 0x006CD6E4

struct D2BnAccountLogonStrc
{
    unsigned char abPublic[0x20];
    char szAccountName[0x100];
};

extern D2BigLoginRecordStrc gtLoginRecord; // 0x00882680

void __stdcall sub_0041D2A0_MemCopy(void* pDst, const void* pSrc, unsigned int nSize); // 0x0041D2A0

void __cdecl sub_00524740_ClearKeySchedules(); // 0x00524740

void __cdecl sub_005241A0_ClearHashContexts(); // 0x005241A0

extern unsigned char gabNewVerifier[0x40]; // 0x00882640

extern D2BigPairStrc gtBigPair; // 0x0088273C

extern unsigned char gaSubstitutionBox[30][16]; // 0x006DFF20

extern unsigned char gaCdKeyCharMap[256]; // 0x006E0100

unsigned int __fastcall BNDOWNLOAD_MulAddWords(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry); // 0x005225E0

void __fastcall BNDOWNLOAD_DecodeKeyDigits(const char* szKey, unsigned char* pOut); // 0x00522650

void __stdcall BNDOWNLOAD_SubstituteKeyNibbles(unsigned int* pKey); // 0x00522980

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

void __fastcall sub_00524280_InitHashContext(int nIndex); // 0x00524280

void __fastcall sub_00524200_HashBlock(int nIndex, const void* pBlock, unsigned int* pDigest); // 0x00524200

void __fastcall sub_00524780_SetKey(int nIndex, int bEncrypt, const D2IdeaUserKeyStrc* pUserKey); // 0x00524780

extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

struct D2CipherKeyView {
 void Init(int); // 0x00522C30
};

void __fastcall sub_005241C0_GetDigest(int,void*); // 0x005241C0

void __fastcall sub_00524760_CipherBlock(int,const unsigned short*,unsigned short*); // 0x00524760

static unsigned int BNDOWNLOAD_CountTerminatedBytes(unsigned int maxLength, unsigned int length, const unsigned char* data); // 0x00523280

int gdwGlobal_00882528; // 0x00882528

int gdwGlobal_008823F0; // 0x008823F0

int gdwGlobal_008823FC; // 0x008823FC

char gszReplyText[256]; // 0x00882428

int gnGlobal_008823EC; // 0x008823EC

char gszAccountName[0x100]; // 0x00882540

int gnLoginRetryCount; // 0x00882538

unsigned int __fastcall BNDOWNLOAD_GetKeyBit(const unsigned int* pKey, unsigned int nIndex); // 0x00522570

void __fastcall BNDOWNLOAD_SetKeyBit(unsigned int* pKey, unsigned int nIndex, unsigned char nValue); // 0x005225A0

extern unsigned int* gpCacheTable_00881888; // 0x00881888
static void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey);
unsigned int __stdcall sub_00518FA0_HashString(unsigned int nHashType, const char* szString); // 0x00518FA0

// calling-convention shim (not game code)

void __cdecl sub_00518EC0_Shim(unsigned int* pData, unsigned int nSize)
{
    sub_00518EC0_EncryptBlock(pData, nSize, sub_00518FA0_HashString(3, "x"));
}

// 0x00518BA0
void D2BnLogStrc::Write(const char* szText)
{
    SLogWrite(hLog, szText);
}

// build: symbol ?$S1@?1??BNDOWNLOAD_GetLog@@YAAAUD2BnLogStrc@@XZ@4IA 0x0088187C
// build: symbol ??__FtLog_00881878@?1??BNDOWNLOAD_GetLog@@YAAAUD2BnLogStrc@@XZ@YAXXZ 0x006CB430
// 0x00518C30
static D2BnLogStrc& BNDOWNLOAD_GetLog()
{
    static D2BnLogStrc tLog_00881878; // 0x00881878
    return tLog_00881878;
}

// build: symbol ?$S1@?1??BNDOWNLOAD_GetLog@@YAAAUD2BnLogStrc@@XZ@4IA 0x0088187C
// build: symbol ??__FtLog_00881878@?1??BNDOWNLOAD_GetLog@@YAAAUD2BnLogStrc@@XZ@YAXXZ 0x006CB430
// 0x00518C70
int __cdecl BNDOWNLOAD_ConfigureLog(int nMode, int nValue)
{
    int nResult = 0;
    EnterCriticalSection(&gtBnLogLock);
    if (nMode == 1)
    {
        SLogClose(BNDOWNLOAD_GetLog().hLog);
        SLogCreate("BnetLog.txt", 0, &BNDOWNLOAD_GetLog().hLog);
        nResult = 1;
    }
    else if (nMode == 2)
    {
        sub_00420120_LogAdjust(BNDOWNLOAD_GetLog().hLog, nValue);
    }
    LeaveCriticalSection(&gtBnLogLock);
    return nResult;
}

// 0x00518D40
void __cdecl BNDOWNLOAD_LogPrintf(const char* szFormat, ...)
{
    char szBuffer[0x200];
    EnterCriticalSection(&gtBnLogLock);
    _vsnprintf(szBuffer, sizeof(szBuffer), szFormat, (char*)(&szFormat + 1));
    szBuffer[sizeof(szBuffer) - 1] = 0;
    SLogWrite(BNDOWNLOAD_GetLog().hLog, szBuffer);
    LeaveCriticalSection(&gtBnLogLock);
}

// 0x00518EC0
static void sub_00518EC0_EncryptBlock(unsigned int* pData, unsigned int nLength, unsigned int dwKey)
{
    unsigned int dwSeed = 0xEEEEEEEE;
    unsigned int nCount = nLength >> 2;
    if (nCount != 0)
    {
        const unsigned int* pTable = gpCacheTable_00881888;
        do
        {
            --nCount;
            unsigned int ch = *pData;
            dwSeed += pTable[0x400 + (dwKey & 0xFF)];
            *pData = ch ^ (dwKey + dwSeed);
            dwSeed = ch + dwSeed + (dwSeed << 5) + 3;
            dwKey = ((~dwKey << 0x15) + 0x11111111) | (dwKey >> 0x0B);
            ++pData;
        } while (nCount != 0);
    }
}

// 0x00519000
void __cdecl sub_00519000_InitCryptTable()
{
    unsigned int* pTable = gpCacheTable_00881888;
    if (!pTable)
    {
        return;
    }

    unsigned int dwSeed = 0x00100001;
    for (unsigned int i = 0; i < 0x100; ++i)
    {
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x100];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x200];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x300];
            *pEntry = dwValue;
        }
        {
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwHigh = dwSeed & 0xFFFF;
            dwSeed = (dwSeed * 125 + 3) % 0x2AAAAB;
            unsigned int dwValue = dwHigh << 16;
            dwValue |= dwSeed & 0xFFFF;
            unsigned int* pEntry = &pTable[i + 0x400];
            *pEntry = dwValue;
        }
    }
}

// 0x0051BE80
long __cdecl BNDOWNLOAD_CompareExchange(long* pDestination, long nExchange, long nComparand)
{
    return InterlockedCompareExchange(pDestination, nExchange, nComparand);
}

// 0x0051C0E0
void __fastcall BNDOWNLOAD_ResolveHost(char* szResult, const char* szHost)
{
    gbDnsPending = 1;
    Sleep(10);
    *szResult = 0;
    unsigned long dwThreadId = 0;
    gtDnsArgs.szResult = szResult;
    gtDnsArgs.f_4 = szHost;
    void* hThread = CreateThread(0, 0, BNSEND_ResolveHostThread, &gtDnsArgs, 0, &dwThreadId);
    while (!InterlockedCompareExchange(&gnDnsDone, 0, 0))
    {
        if (WaitForSingleObject(hThread, 0) == 0)
            break;
        Sleep(10);
    }
}

// 0x0051C3E0
int __fastcall BNDOWNLOAD_EnterChat(const char* szArg1, const char* szArg2, int nArg3, const char* szText, int nFlags)
{
    const int bAlternate = nFlags & 1;
    BNNEWS_SelectNewsFile(bAlternate);
    sub_00520C00_ClearReply(10);
    BNSEND_SendEnterChat(szArg1, szArg2, nArg3);
    if (nFlags & 2)
        BNSEND_JoinChannel(szText, 1, bAlternate);
    BNDOWNLOAD_WaitForReply(10);
// build: symbol ?GAME_GetAbortFlag@* 0x00520AE0
    if (GAME_GetAbortFlag())
    {
        BNMESSQUEUE_SetError(0xE);
        return 1;
    }
    BNMESSQUEUE_SetState(0);
    return 1;
}

// 0x0051CA30
int __cdecl BNDOWNLOAD_IsReady()
{
    D2BnStateStrc tState;
    BNMESSQUEUE_GetState(&tState);
    if (!GAME_GetAbortFlag() && tState.nState == 0 && InterlockedCompareExchange(&gnConnected, 0, 0))
        return 1;
    return 0;
}

// 0x0051E370
int __fastcall BNDOWNLOAD_SetDownloadText(const void* pSource, unsigned int nSize)
{
    EnterCriticalSection(&gtDownloadLock);
    SMemCopy(gszAdList, pSource, nSize);
    gnPercent = 0;
    LeaveCriticalSection(&gtDownloadLock);
    return 1;
}

// 0x0051E3B0
int __fastcall BNDOWNLOAD_SetCheckRevisionValue(const char* szValue)
{
    SStrCopy(gszCheckRevisionValue, szValue, 0x104);
    return 1;
}

// 0x0051E3D0
int __fastcall BNDOWNLOAD_SendGetFileTime(const char* szText, int nValue)
{
    D2BnPacket33HeaderStrc tHeader;
    char szPacketText[0x104];
    tHeader.nValue = nValue;
    tHeader.nZero = 0;
    char* pText = szPacketText;
    pText += SStrCopy(pText, szText, sizeof(szPacketText)) + 1;
    BNSEND_SendPacket(0x33, &tHeader, (unsigned int)(pText - (char*)&tHeader));
    return 1;
}

// 0x0051E440
static void __stdcall BNDOWNLOAD_WriteFileWithTime(const void* pData, unsigned int nSize, const char* szFile, const D2FileTimeStrc* pFileTime)
{
    unsigned long nWritten;
    void* hFile = FOG_CreateFileA(szFile, 0x40000000, 0, 0, 2, 0x80, 0);
    if (hFile != (void*)-1)
    {
        FOG_WriteFile(hFile, pData, nSize, &nWritten, 0);
        SetFileTime(hFile, pFileTime, pFileTime, pFileTime);
        FOG_CloseFile(hFile);
    }
}

// 0x0051E490
static int __stdcall BNDOWNLOAD_ExtractArchiveDll(void* hArchive, char* szPath, const char* szFile)
{
    int bResult = 0;
    void* hFile = 0;
    unsigned int nLength = GetTempPathA(0x104 - strlen(szFile), szPath);
    if (!nLength)
    {
        LOGMANAGER_WriteLogLine("Failed to create temp file!");
    }
    else
    {
        SStrPack(szPath, szFile, 0x104);
        char* pExtension = strrchr(szPath, '.');
        if (pExtension)
            *pExtension = 0;
        SStrPack(szPath, ".dll", 0x104);
        if (SFileOpenFileEx(hArchive, szPath + nLength, 0, &hFile))
        {
            unsigned int nSize = SFileGetFileSize(hFile, 0);
            void* pBuffer = SMemAlloc(nSize, gszBnDownloadFile, 0xF7, 0);
            if (pBuffer)
            {
                SFileReadFile(hFile, pBuffer, nSize, 0, 0);
                void* hOut = FOG_CreateFileA(szPath, 0x40000000, 0, 0, 2, 0x80, 0);
                if (hOut != (void*)-1)
                {
                    unsigned long nWritten;
                    FOG_WriteFile(hOut, pBuffer, nSize, &nWritten, 0);
                    FOG_CloseFile(hOut);
                    bResult = 1;
                }
                SMemFree(pBuffer, gszBnDownloadFile, 0x111, 0);
            }
        }
    }
    if (hFile)
        SFileCloseFile(hFile);
    return bResult;
}

// 0x0051E5D0
void __cdecl BNDOWNLOAD_StopDownloads()
{
    gbStopDownload = 1;
}

// 0x0051E5E0
extern "C" int __cdecl BNDOWNLOAD_HasPendingDownloads()
{
    return gnPendingCount > 0;
}

// 0x0051E5F0
static int __stdcall BNDOWNLOAD_RecvAll(unsigned int nSocket, char* pBuffer, unsigned int nSize)
{
    for (unsigned int nRead = 0; nSize > nRead; )
    {
        const int nResult = recv(nSocket, pBuffer + nRead, nSize - nRead, 0);
        if (nResult == -1 || nResult <= 0)
            return 0;
        nRead += nResult;
    }
    return 1;
}

unsigned long __fastcall sub_H04_Emit_0051E640(const char* szFile, const __int64* pFileTime)
{
    return BNDOWNLOAD_GetFileSizeIfTimeMatches(szFile, pFileTime);
}

// 0x0051E640
static unsigned long BNDOWNLOAD_GetFileSizeIfTimeMatches(const char* szFile, const __int64* pFileTime)
{
    void* hFile = FOG_CreateFileA(szFile, 0x80000000, 3, 0, 3, 0x8000000, 0);
    if (hFile == (void*)-1)
        return 0;

    __int64 nWriteTime;
    GetFileTime(hFile, 0, 0, &nWriteTime);
    __int64 nDiff = nWriteTime - *pFileTime;
    if (nDiff < 0)
        nDiff = -nDiff;
    const unsigned __int64 nAbs = nDiff;

    if (!(unsigned long)(nAbs >> 32) && (unsigned long)nAbs <= 40000000)
    {
        const unsigned long nFileSize = GetFileSize(hFile, 0);
        FOG_CloseFile(hFile);
        return nFileSize;
    }

    FOG_CloseFile(hFile);
    return 0;
}

// 0x0051E6D0
int __fastcall BNDOWNLOAD_RunCheckRevision(int* pVersion, int* pChecksum, char* szExeInfo)
{
    if (pVersion)
        *pVersion = 0;
    if (pChecksum)
        *pChecksum = 0;
    if (szExeInfo)
        *szExeInfo = 0;

    void* hArchive = 0;
    char szDll[0x104] = { 0 };
    int nResult = 0;
    unsigned long dwStart = GetTickCount();
    do
    {
        if (gszDownloadArchive[0])
        {
    if (!SFileOpenArchive(gszDownloadArchive, 0, 0, &hArchive))
        return 0;

    unsigned int nAuth;
    SFileAuthenticateArchive(hArchive, &nAuth);
    if (!nAuth || nAuth >= 5)
    {
        if (BNDOWNLOAD_ExtractArchiveDll(hArchive, szDll, gszDownloadArchive) && sub_00516DE1_CanRunSurvey(szDll))
        {
            void* hDll = LoadLibraryA(szDll);
            if (hDll)
            {
                D2CheckRevisionFn pfnCheckRevision = (D2CheckRevisionFn)GetProcAddress(hDll, "CheckRevision");
                if (pfnCheckRevision)
                {
                    char szFile1[0x104] = { 0 };
                    char szFile2[0x104] = { 0 };
                    char szFile3[0x104] = { 0 };
                    GetModuleFileNameA(GetModuleHandleA(0), szFile1, 0x104);
                    nResult = pfnCheckRevision(szFile1, szFile2, szFile3, gszCheckRevisionValue, pVersion, pChecksum, szExeInfo);
                }
                FreeLibrary(hDll);
            }
        }
    }

    if (hArchive)
        SFileCloseArchive(hArchive);
    Sleep(50);
    DeleteFileA(gszDownloadArchive);
    if (szDll[0])
        DeleteFileA(szDll);
    return nResult;
        }
        Sleep(10);
    }
    while (GetTickCount() - dwStart <= 20000);
    return 1;
}

// 0x0051E920
static void __fastcall BNDOWNLOAD_ExtractFile(const char* member, void* archive, const char* destination)
{
    void* output;
    void* source;
    if (!sub_004192F0_OpenArchiveFile(archive, member, 0, &source)) return;
    unsigned int size = SFileGetFileSize(source, 0);
    void* data = sub_00413020_Alloc(size, gszBnDownloadFile, 0x583, 0);
    if (SFileReadFile(source, data, size, 0, 0)) {
        output = FOG_CreateFileA(destination, 0x40000000, 3, 0, 2, 0x80, 0);
        if (output != (void*)-1) {
            unsigned long written;
            FOG_WriteFile(output, data, size, &written, 0);
            FOG_CloseFile(output);
        }
    }
    SMemFree(data, gszBnDownloadFile, 0x592, 0);
    SFileCloseFile(source);
}

// 0x0051E9D0
static int BNDOWNLOAD_RunProgramList(const char* szList, const char* szDirectory)
{
    while (*szList)
    {
        if (!sub_00516DE1_CanRunSurvey(szList))
            return 0;

        if ((int)ShellExecuteA(0, 0, szList, 0, szDirectory, 1) <= 0x20)
            return 0;

        szList += SStrLen(szList) + 1;
    }

    return 1;
}

// 0x0051EA20
void __fastcall BNDOWNLOAD_SetPercent(int nUnused, unsigned int nCurrent, unsigned int nTotal)
{
    gnPercent = nCurrent * 100 / nTotal;
}

// 0x0051EA40
void __fastcall BNDOWNLOAD_SetStatus(int nStatus)
{
    EnterCriticalSection(&gtDownloadLock);
    gszAdList[0] = 0;
    gszAdList[1] = 0;
    gnPercent = nStatus;
    LeaveCriticalSection(&gtDownloadLock);
}

extern int gdwGlobal_00881C50; // 0x00881C50

// 0x0051EA70
int __cdecl BNCLIENT_GetDownloadPercent()
{
    return gdwGlobal_00881C50;
}

// 0x0051EA80
int __fastcall BNDOWNLOAD_SetArchiveName(const char* szName)
{
    SStrCopy(gszDownloadArchive, szName, 0x7FFFFFFF);
    return 1;
}

int __cdecl sub_B03_Emit_0051E9D0(const char* szList, const char* szDirectory)
{
    return BNDOWNLOAD_RunProgramList(szList, szDirectory);
}

// 0x0051EAA0
int __cdecl BNDOWNLOAD_HasArchiveName()
{
    return gszDownloadArchive[0] != 0;
}

// 0x0051EAB0
static int __stdcall BNDOWNLOAD_RecvToBuffer(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, int nFlags, char** ppBuffer, unsigned int nSize)
{
    *ppBuffer = (char*)SMemAlloc(nSize, gszBnDownloadFile, 0x385, 8);
    for (unsigned int nRead = 0; nRead < nSize; )
    {
        unsigned int nChunk = nSize - nRead;
        if (nChunk > 0x5B4)
            nChunk = 0x5B4;

        const int nResult = recv(nSocket, *ppBuffer + nRead, nChunk, 0);
        if (nResult == -1 || nResult <= 0 || gbStopDownload)
        {
            SMemFree(*ppBuffer, gszBnDownloadFile, 0x38F, 0);
            *ppBuffer = 0;
            sub_0051A480_DebugLog("<ERROR: Failed to recv file  %s in DOWNLOADTOANY, filebytes = %ld, currpos = %ld, bytes = %d", szFile, nSize, nRead, nResult);
            return 0;
        }

        nRead += nResult;
        if (nType == 0x80000002)
            gnPercent = nRead * 100 / nSize;
    }

    if (nFlags & 1)
        CACHE_WriteCachedFile(szFile, *ppBuffer, nSize, pFileTime, 0x13C680, 0x278D00);

    if (nFlags & 2)
        BNDOWNLOAD_WriteFileWithTime(*ppBuffer, nSize, szFile, pFileTime);

    return 1;
}

// 0x0051EBB0
static int __stdcall BNDOWNLOAD_RecvToFile(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, unsigned int nOffset, unsigned int nTotal, int nType)
{
    char szBuffer[0x5B4];
    unsigned long nWritten;

    void* hFile = FOG_CreateFileA(szFile, 0x40000000, 0, 0, 4, 0x80, 0);
    if (hFile == (void*)-1)
        return 0;

    if (nOffset)
        FOG_SetFilePointer(hFile, nOffset, 0, 0);

    if (nType == 0x80000002)
    {
        gnPercent = nOffset * 100 / nTotal;
        Sleep(0);
    }

    while (nOffset < nTotal)
    {
        unsigned int nChunk = nTotal - nOffset;
        if (nChunk > 0x5B4)
            nChunk = 0x5B4;

        const int nResult = recv(nSocket, szBuffer, nChunk, 0);
        if (nResult == -1 || nResult <= 0 || gbStopDownload)
        {
            FOG_CloseFile(hFile);
            return 0;
        }

        FOG_WriteFile(hFile, szBuffer, nResult, &nWritten, 0);
        SetFileTime(hFile, pFileTime, pFileTime, pFileTime);
        nOffset += nResult;
        if (nType == 0x80000002)
            gnPercent = nOffset * 100 / nTotal;
    }

    FOG_CloseFile(hFile);
    return 1;
}

// 0x0051ED00
int __fastcall BNDOWNLOAD_ApplyPatches(int* pResult)
{
    D2_ASSERT(pResult, 1205);

    char szModuleDir[260] = { 0 };
    GetModuleFileNameA(0, szModuleDir, sizeof(szModuleDir));
    szModuleDir[259] = 0;

    char* pSlash = szModuleDir;
    while (*pSlash && SStrChr(pSlash + 1, '\\'))
    {
        pSlash = SStrChr(pSlash + 1, '\\');
    }
    *pSlash = 0;

    char szPatches[1024] = { 0 };
    if (!SRegLoadData("Patch", "Patches", 2, szPatches, 1022, 0) || !szPatches[0])
    {
        *pResult = 0;
        return 0;
    }

    char szRunList[1024] = { 0 };
    char* pRun = szRunList;
    char* szPatch = szPatches;
    while (*szPatch)
    {
        void* hArchive;
        if (!SFileOpenArchive(szPatch, 0, 0, &hArchive))
        {
            DeleteFileA(szPatch);
            *pResult = -1;
            return 0;
        }

        unsigned int nAuth;
        SFileAuthenticateArchive(hArchive, &nAuth);
        if (nAuth && nAuth < 5)
        {
            SFileCloseArchive(hArchive);
            DeleteFileA(szPatch);
            *pResult = -1;
            return 0;
        }

        void* hFile;
        if (SFileOpenFileEx(hArchive, "Prepatch.lst", 0, &hFile))
        {
            unsigned int nSize = SFileGetFileSize(hFile, 0);
            char* pBuffer = (char*)SMemAlloc(nSize, ".\\BnDownload.cpp", 1267, 0);
            if (SFileReadFile(hFile, pBuffer, nSize, 0, 0))
            {
                char* pCur = pBuffer;
                while ((unsigned int)(pCur - pBuffer) < nSize)
                {
                    char szLine[256] = { 0 };
                    char* pOut = szLine;
                    while ((unsigned int)(pCur - pBuffer) < nSize && pOut - szLine < 255 && *pCur && *pCur != '\r' && *pCur != '\n')
                    {
                        *pOut++ = *pCur++;
                        *pOut = 0;
                    }

                    while ((unsigned int)(pCur - pBuffer) < nSize && (*pCur == '\r' || *pCur == '\n'))
                    {
                        ++pCur;
                    }

                    char szMember[260] = { 0 };
                    char szDest[260] = { 0 };
                    if (SStrChr(szLine, ' '))
                    {
                        pSlash = SStrChr(szLine, ' ') + 1;
                        while (*pSlash == ' ')
                        {
                            ++pSlash;
                        }
                        SStrCopy(szMember, pSlash, sizeof(szMember));
                        wsprintfA(szDest, "%s\\%s", szModuleDir, pSlash);
                    }

                    if (!_strnicmp(szLine, "delete ", 7))
                    {
                        DeleteFileA(szDest);
                    }
                    else if (!_strnicmp(szLine, "extract ", 8))
                    {
                        BNDOWNLOAD_ExtractFile(szMember, hArchive, szDest);
                    }
                    else if (!_strnicmp(szLine, "execute ", 8))
                    {
                        pRun += SStrCopy(pRun, szDest, 0x7FFFFFFF) + 1;
                    }
                }
            }
            SMemFree(pBuffer, ".\\BnDownload.cpp", 1320, 0);
            SFileCloseFile(hFile);
        }
        SFileCloseArchive(hArchive);

        szPatch += SStrLen(szPatch) + 1;
    }

    char szValue[900];
    pSlash = szValue;
    sprintf(pSlash, "%s\\Game.exe", szModuleDir);
    SRegSaveString("Patch", "Launcher", 2, pSlash);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        pSlash += sprintf(pSlash, "%s\\%s;", szModuleDir, "d2exp.mpq");
    }
    sprintf(pSlash, "%s\\%s;%s\\%s", szModuleDir, "d2data.mpq", szModuleDir, "d2sfx.mpq");
    SRegSaveString("Patch", "SrcData", 2, szValue);
    sprintf(szValue, "%s\\%s", szModuleDir, "patch_d2.mpq");
    SRegSaveString("Patch", "DstData", 2, szValue);

    if (pRun == szRunList)
    {
        wsprintfA(pRun, "%s\\bnupdate.exe", szModuleDir);
        pRun += SStrLen(pRun) + 1;
    }
    *pRun = 0;

    gtBnGatewayAccess.Unload();

    if (!BNDOWNLOAD_RunProgramList(szRunList, szModuleDir))
    {
        *pResult = -1;
        return 0;
    }

    *pResult = 2;
    return 1;
}

// 0x0051F310
unsigned int __stdcall BNDOWNLOAD_DownloadThread(void* pArg)
{
    D2BnDownloadRecordStrc* pRecord = (D2BnDownloadRecordStrc*)pArg;
    char* pBuffer = 0;
    D2BnDownloadReplyStrc* pReply = 0;
    char* szToken = 0;
    int nRetry = 0;
    int bRetryFailed = 0;
    char szHost[0x200];
    char szIp[0x100];
    D2SockAddrInStrc tAddr;
    int nAddrLen;
    unsigned int nSocket;
    int nKeepAlive;
    int nTimeout;
    char nCommand;
    D2BnDownloadRecordStrc tRecord;
    unsigned int nSize;
    unsigned int nFileSize;

    szHost[0] = 0;
    gbStopDownload = 0;
    nAddrLen = sizeof(tAddr);
    if (!sub_0051C9B0_GetPeerName(&tAddr, &nAddrLen))
    {
        BNSEND_GetServerAddress(szIp, sizeof(szIp));
        BNDOWNLOAD_ResolveHost(szHost, szIp);
        szToken = strtok(szHost, " ,;");
        memset(&tAddr, 0, sizeof(tAddr));
        tAddr.sin_family = 2;
        tAddr.sin_port = htons(6112);
        tAddr.sin_addr.s_addr = inet_addr(szToken);
    }
    else
    {
        tAddr.sin_port = htons(6112);
        memset(tAddr.sin_zero, 0, sizeof(tAddr.sin_zero));
    }

    nSocket = socket(2, 1, 0);
    if (nSocket != (unsigned int)-1)
    for (;;)
    {
        if (connect(nSocket, &tAddr, sizeof(tAddr)) == -1)
        {
            if (gbStopDownload || pRecord->nType != 0x80000002)
            {
                sub_0051A480_DebugLog("Canceled download.");
                break;
            }

            FOG_SOCKET_CloseSocket(nSocket);
            nSocket = (unsigned int)-1;
            if (++nRetry > 3)
            {
                bRetryFailed = 1;
                goto next;
            }

            sub_0051A480_DebugLog("WARNING: Failed to connect to download port. Retrying...");
            Sleep(1000);
            if (szHost[0])
            {
                if (!szToken)
                    szToken = strtok(szHost, " ,;");
                else
                    szToken = strtok(0, " ,;");
            }

            if (!szToken)
                break;

            tAddr.sin_addr.s_addr = inet_addr(szToken);
            goto next;
        }

        nKeepAlive = 1;
        setsockopt(nSocket, 0xFFFF, 8, (const char*)&nKeepAlive, sizeof(nKeepAlive));
        nTimeout = 15000;
        setsockopt(nSocket, 0xFFFF, 0x1006, (const char*)&nTimeout, sizeof(nTimeout));

        nCommand = 2;
        if (send(nSocket, &nCommand, 1, 0) != 1)
        {
            sub_0051A480_DebugLog("ERROR: Failed send to BNET for download.");
            break;
        }

        tRecord = *pRecord;
        if (send(nSocket, (const char*)&tRecord, pRecord->nSize, 0) != pRecord->nSize)
        {
            sub_0051A480_DebugLog("ERROR: Failed send to BNET for download.");
            break;
        }

        nSize = 0;
        for (unsigned int nRead = 0; nRead < 4; )
        {
            const int nResult = recv(nSocket, (char*)&nSize + nRead, 4 - nRead, 0);
            if (nResult == -1 || nResult <= 0)
            {
                sub_0051A480_DebugLog("ERROR: Failed send to BNET for download.");
                goto done;
            }
            nRead += nResult;
        }

        D2_ASSERT(nSize < 0x100, 750);
        pReply = (D2BnDownloadReplyStrc*)SMemAlloc(nSize, gszBnDownloadFile, 751, 0);
        if (!pReply)
            break;

        if (!BNDOWNLOAD_RecvAll(nSocket, (char*)pReply + 4, nSize - 4))
        {
            sub_0051A480_DebugLog("ERROR: Failed recv from BNET for download.");
            break;
        }

        if (gbStopDownload)
        {
            sub_0051A480_DebugLog("Canceled download(2).");
            break;
        }

        if (pRecord->nSubType == 2)
        {
            nFileSize = BNDOWNLOAD_GetFileSizeIfTimeMatches(pReply->szFile, (const __int64*)&pReply->tFileTime);
            if (nFileSize != pRecord->nOffset)
            {
                pRecord->nOffset = nFileSize;
                FOG_SOCKET_CloseSocket(nSocket);
                SMemFree(pReply, gszBnDownloadFile, 785, 0);
                pReply = 0;
                goto next;
            }

            if (gbStopDownload)
            {
                sub_0051A480_DebugLog("Canceled download(3).");
                break;
            }
        }

        if (pRecord->nSubType == 2)
        {
            if (!BNDOWNLOAD_RecvToFile(nSocket, pReply->szFile, &pReply->tFileTime, pRecord->nOffset, pReply->nTotal, pRecord->nType))
            {
                if (gbStopDownload)
                {
                    sub_0051A480_DebugLog("ERROR: Cancelled download.");
                    break;
                }

                FOG_SOCKET_CloseSocket(nSocket);
                SMemFree(pReply, gszBnDownloadFile, 817, 0);
                pReply = 0;
                sub_0051A480_DebugLog("WARNING: Failed to save to disk.");
                goto next;
            }
        }
        else
        {
            if (!BNDOWNLOAD_RecvToBuffer(nSocket, pReply->szFile, &pReply->tFileTime, pRecord->nType, pRecord->nSubType, &pBuffer, pReply->nTotal))
            {
                if (gbStopDownload)
                {
                    sub_0051A480_DebugLog("ERROR: Cancelled download(2).");
                    break;
                }

                FOG_SOCKET_CloseSocket(nSocket);
                SMemFree(pReply, gszBnDownloadFile, 844, 0);
                pReply = 0;
                sub_0051A480_DebugLog("ERROR: Failed to copy file.");
                goto next;
            }
        }

        BNDOWNLOAD_HandleDownloadEvent(pRecord->nType, pRecord->nSubType, pReply->nArg1, pReply->nArg2, &pReply->tFileTime, pReply->szFile, pRecord->szLink, pBuffer, pReply->nTotal, 0);
        break;

next:
        if (bRetryFailed)
        {
            sub_0051A480_DebugLog("ERROR: Failed recv from BNET for download.");
            break;
        }

        nSocket = socket(2, 1, 0);
        if (nSocket == (unsigned int)-1)
            break;
    }

done:
    const int nFinalType = pRecord->nType;
    if (nSocket != (unsigned int)-1)
        FOG_SOCKET_CloseSocket(nSocket);

    if (pBuffer)
        SMemFree(pBuffer, gszBnDownloadFile, 870, 0);

    if (pReply)
        SMemFree(pReply, gszBnDownloadFile, 871, 0);

    SMemFree(pRecord, gszBnDownloadFile, 872, 0);
    if (nFinalType == 0x80000002 && gnPercent < 100)
    {
        EnterCriticalSection(&gtDownloadLock);
        gszAdList[0] = 0;
        gszAdList[1] = 0;
        gnPercent = 101;
        LeaveCriticalSection(&gtDownloadLock);
    }

    InterlockedDecrement(&gnPendingCount);
    return 0;
}

// 0x0051F910
void __fastcall BNDOWNLOAD_RequestDownload(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink)
{
    if (!szFile || !*szFile)
        return;

    if (!szLink)
        szLink = &gszEmptyAssertText;

    D2FileTimeStrc tCachedTime;
    void* pData;
    unsigned int nSize;
    if (CACHE_LoadCachedFile(szFile, &tCachedTime, &pData, &nSize))
    {
        if (!CompareFileTime(pFileTime, &tCachedTime))
        {
            if (nSubType & 2)
                BNDOWNLOAD_WriteFileWithTime(pData, nSize, szFile, pFileTime);

            BNDOWNLOAD_HandleDownloadEvent(nType, nSubType, nArg1, nArg2, pFileTime, szFile, szLink, pData, nSize, 1);
            CACHE_FreeCachedFile(pData, nSize);
            return;
        }
        CACHE_FreeCachedFile(pData, nSize);
    }

    D2BnDownloadRecordStrc* pRecord = (D2BnDownloadRecordStrc*)SMemAlloc(0x230, gszBnDownloadFile, 0xA6, 0);
    if (!pRecord)
        return;

    memset(pRecord, 0, 0x230);
    pRecord->nSize = (unsigned short)(strlen(szFile) + 0x21);
    pRecord->nUnk0x02 = 0;
    pRecord->nUnk0x03 = 1;
    pRecord->dwPlatform = 0x49583836;
    pRecord->dwProduct = 0x44324456;
    pRecord->nArg1 = nArg1;
    pRecord->nArg2 = nArg2;
    pRecord->nOffset = 0;
    pRecord->nType = nType;
    pRecord->nSubType = nSubType;
    pRecord->tFileTime = *pFileTime;
    SStrCopy(pRecord->szFile, szFile, 0x104);
    SStrCopy(pRecord->szLink, szLink, 0x104);
    InterlockedIncrement(&gnPendingCount);

    unsigned int nThreadId;
    void* hThread = (void*)_beginthreadex(0, 0, BNDOWNLOAD_DownloadThread, pRecord, 0, &nThreadId);
    if (hThread)
        CloseHandle(hThread);
}

int __fastcall sub_A12_Emit_0051E5F0(unsigned int nSocket, char* pBuffer, unsigned int nSize)
{
    return BNDOWNLOAD_RecvAll(nSocket, pBuffer, nSize);
}

int __fastcall sub_A12_Emit_0051EAB0(unsigned int nSocket, const char* szFile, const D2FileTimeStrc* pFileTime, int nType, int nFlags, char** ppBuffer, unsigned int nSize)
{
    return BNDOWNLOAD_RecvToBuffer(nSocket, szFile, pFileTime, nType, nFlags, ppBuffer, nSize);
}

int __fastcall sub_A12_Emit_0051EBB0(unsigned int nSocket, unsigned int nOffset, unsigned int nTotal, int nType, const char* szFile, const D2FileTimeStrc* pFileTime)
{
    return BNDOWNLOAD_RecvToFile(nSocket, szFile, pFileTime, nOffset, nTotal, nType);
}

// 0x0051FAB0
void __fastcall BNDOWNLOAD_HandleDownloadEvent(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szText1, const char* szText2, const void* pData, unsigned int nDataSize, int bFlag)
{
    switch (nType)
    {
    case 0x80000003:
    {
        D2BnAdInfoStrc info;
        info.nArg1 = nArg1;
        info.nArg2 = nArg2;
        char* szCopy1;
        if (szText1 && strlen(szText1))
        {
            szCopy1 = (char*)FOG_Alloc(strlen(szText1) + 1, gszBnDownloadFile, 0x179, 0);
            strcpy(szCopy1, szText1);
        }
        else
        {
            szCopy1 = 0;
        }
        info.szText1 = szCopy1;
        char* szCopy2;
        if (szText2 && strlen(szText2))
        {
            szCopy2 = (char*)FOG_Alloc(strlen(szText2) + 1, gszBnDownloadFile, 0x182, 0);
            strcpy(szCopy2, szText2);
        }
        else
        {
            szCopy2 = 0;
        }
        info.szText2 = szCopy2;
        void* pCopy;
        if (nDataSize && pData)
        {
            pCopy = FOG_Alloc(nDataSize, gszBnDownloadFile, 0x18B, 0);
            memcpy(pCopy, pData, nDataSize);
        }
        else
        {
            pCopy = 0;
        }
        info.pData = pCopy;
        info.nDataSize = nDataSize;
        sub_0051B060_SetAdText(szText1, szText2);
        char szMessage[0x200];
        sprintf(szMessage, "<Received Ad: %s, %s>\n", info.szText1, info.szText2);
        sub_005202F0_PostText(1, szMessage);
        sub_00520210_PostData(3, &info, sizeof(info));
        break;
    }
    case 0x80000002:
    {
        EnterCriticalSection(&gtDownloadLock);
        const char* pEntry = gszAdList;
        while (*pEntry)
        {
            if (!_stricmp(pEntry, szText1))
                break;
            pEntry += strlen(pEntry) + 1;
        }
        if (!*pEntry || !pEntry[strlen(pEntry) + 1])
        {
            BNDOWNLOAD_SetStatus(0x65);
        }
        else
        {
            const char* szValue = pEntry + strlen(pEntry) + 1;
            D2FileTimeStrc fileTime = { 0, 0 };
            BNDOWNLOAD_RequestDownload(0x80000002, 2, 0, 0, &fileTime, szValue, 0);
        }
        LeaveCriticalSection(&gtDownloadLock);
        break;
    }
    case 0x80000001:
        sub_0051A480_DebugLog("Processing Version file");
        strcpy(gszDownloadArchive, szText1);
        break;
    case 0x80000005:
        if (bFlag)
        {
            DeleteFileA(szText1);
            break;
        }
    case 0x80000006:
    {
        void* hArchive = 0;
        void* hFile = 0;
        void* hDll = 0;
        char szDll[0x104] = { 0 };
        sub_0051A480_DebugLog("Processing ExtraWork file");
        if (!SFileOpenArchive(szText1, 0, 0, &hArchive))
            break;

        unsigned int nAuth;
        SFileAuthenticateArchive(hArchive, &nAuth);
        if (nAuth && nAuth < 5)
        {
            sub_0051A480_DebugLog("<ERROR: Failed ExtraWork archive authentication!>");
        }
        else if (!BNDOWNLOAD_ExtractArchiveDll(hArchive, szDll, szText1))
        {
            sub_0051A480_DebugLog("<ERROR: Failed to extract ExtraWork DLL!>");
        }
        else
        {
            hDll = LoadLibraryA(szDll);
            D2ExtraWorkFn pfnExtraWork;
            unsigned char nLocale;
            int nRead;
            if (!hDll)
                sub_0051A480_DebugLog("<ERROR: Failed to load ExtraWork DLL!>");
            else if (!(pfnExtraWork = (D2ExtraWorkFn)GetProcAddress(hDll, "ExtraWork")))
                sub_0051A480_DebugLog("<ERROR: Failed to get address of ExtraWork function!>");
            else if (!SFileOpenFile("data\\local\\use", &hFile))
                sub_0051A480_DebugLog("<ERROR: Failed to open game locale file!>");
            else if (!SFileReadFile(hFile, &nLocale, 1, &nRead, 0))
                sub_0051A480_DebugLog("<ERROR: Failed to read game locale file!>");
            else if (nRead != 1)
                sub_0051A480_DebugLog("<ERROR: Failed to read game locale file!>");
            else
            {
                SFileCloseFile(hFile);
                D2BnExtraWorkPacketStrc packet;
                memset(&packet, 0, sizeof(packet));
                packet.wType = 1;
                packet.wSize = 4;
                packet.dwLocale = nLocale;
                if (pfnExtraWork(&packet))
                    BNSEND_SendPacket(0x4B, &packet, packet.wSize + 4);
                else
                    sub_0051A480_DebugLog("<ERROR: ExtraWork DLL indicated failure!>");
            }
        }
        if (hDll)
            FreeLibrary(hDll);

        if (hArchive)
            SFileCloseArchive(hArchive);
        Sleep(50);
        DeleteFileA(szText1);
        if (szDll[0])
            DeleteFileA(szDll);
        break;
    }
    case 0x80000004:
    {
        sub_0051A480_DebugLog("Processing Bnserver.ini file");
        unsigned int nLength = SStrLen((const char*)pData);
        char* szText = (char*)SMemAlloc(nLength + 1, gszBnDownloadFile, 0x23F, 0);
        SStrCopy(szText, (const char*)pData, nLength + 1);
        gtBnGatewayAccess.UpdateGatewaysFromIni(szText);
        SMemFree(szText, gszBnDownloadFile, 0x245, 0);
        gtBnGatewayAccess.Unload();
        break;
    }
    }
}

// 0x00520020
int __fastcall BNDOWNLOAD_RequestNamedFile(const char* szText, int nLen)
{
    if (!FOG_SOCKET_WSAStartup())
        return 0;

    gnPercent = 0;
    EnterCriticalSection(&gtDownloadLock);
    SMemCopy(gszAdList, szText, nLen);
    gnPercent = 0;
    LeaveCriticalSection(&gtDownloadLock);
    SRegSaveData(gszAdListRegKey, gszAdListRegValue, 0x82, szText, nLen + 1);

    D2FileTimeStrc tCachedTime;
    D2FileTimeStrc tFileTime;
    unsigned int nThreadId;
    void* pData;
    unsigned int nSize;
    tFileTime.dwLowDateTime = 0;
    tFileTime.dwHighDateTime = 0;
    if (!szText || !*szText)
        return 0;

    if (CACHE_LoadCachedFile(szText, &tCachedTime, &pData, &nSize))
    {
        if (!CompareFileTime(&tFileTime, &tCachedTime))
        {
            BNDOWNLOAD_WriteFileWithTime(pData, nSize, szText, &tFileTime);
            BNDOWNLOAD_HandleDownloadEvent(0x80000002, 2, 0, 0, &tFileTime, szText, 0, pData, nSize, 1);
            CACHE_FreeCachedFile(pData, nSize);
            return 0;
        }
        CACHE_FreeCachedFile(pData, nSize);
    }

    D2BnDownloadRecordStrc* pRecord = (D2BnDownloadRecordStrc*)SMemAlloc(0x230, gszBnDownloadFile, 0x698, 0);
    if (!pRecord)
        return 0;

    memset(pRecord, 0, 0x230);
    pRecord->nSize = (unsigned short)(strlen(szText) + 0x21);
    pRecord->nUnk0x02 = 0;
    pRecord->nUnk0x03 = 1;
    pRecord->dwPlatform = 0x49583836;
    pRecord->dwProduct = 0x44324456;
    pRecord->nArg1 = 0;
    pRecord->nArg2 = 0;
    pRecord->nOffset = 0;
    pRecord->nType = 0x80000002;
    pRecord->nSubType = 2;
    pRecord->tFileTime = tFileTime;
    SStrCopy(pRecord->szFile, szText, 0x104);
    SStrCopy(pRecord->szLink, &gszEmptyAssertText, 0x104);
    InterlockedIncrement(&gnPendingCount);
    return _beginthreadex(0, 0, BNDOWNLOAD_DownloadThread, pRecord, 0, &nThreadId);
}

// 0x00520660
int __fastcall BNDOWNLOAD_HandleChatEvent(const void* pData, unsigned int nSize)
{
    BNMESSQUEUE_QueueMessage(0, pData, nSize);
    return 1;
}

struct FindSignatureTag;

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

struct FindSignatureTag
{
    unsigned int dwState[5];
};

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

void* gpBnStateArg; // 0x00882000

D2CriticalSectionStrc gtMessageLock; // 0x00882004

int gnBnState; // 0x0088201C

void __cdecl BNMESSQUEUE_InitMessageQueue(); // 0x005201E0

int __fastcall BNMESSQUEUE_GetState(D2BnStateStrc* pState); // 0x005205F0

void __cdecl BNMESSQUEUE_DeleteQueueLock(); // 0x00520200

void __fastcall BNMESSQUEUE_SetSlot(unsigned char nIndex, int nValue); // 0x00520C30

int __fastcall sub_M119_Emit_00520A80(int nPos, int nCount, int nSize)
{
    return BNDOWNLOAD_CheckStringBlock((const char*)nSize, nPos, nCount, nSize + 3);
}

// 0x00520680
void __fastcall BNDOWNLOAD_InitSha1Context(FindSignatureTag* pContext)
{
    pContext->dwState[0] = 0x67452301;
    pContext->dwState[1] = 0xEFCDAB89;
    pContext->dwState[2] = 0x98BADCFE;
    pContext->dwState[3] = 0x10325476;
    pContext->dwState[4] = 0xC3D2E1F0;
}

// 0x005206B0
void __fastcall BNDOWNLOAD_HashTransform(D2BnetHashContextStrc* context)
{
    unsigned int words[80];
    int i;
    for (i = 0; i < 16; ++i)
        words[i] = context->block[i];
    i = 16;
    do
    {
        const int nShift = (words[i - 3] ^ words[i - 8] ^ words[i - 16] ^ words[i - 14]) & 31;
        words[i] = HASH_ROL(1, nShift);
        ++i;
    } while (i < 80);
    unsigned int a = context->state[0];
    unsigned int b = context->state[1];
    unsigned int c = context->state[2];
    unsigned int d = context->state[3];
    unsigned int e = context->state[4];
    unsigned int t;
    unsigned int n = 0;
    for (; n < 20; ++n)
    {
        t = HASH_ROL(a, 5) + ((~b & d) | (c & b)) + words[n] + e + 0x5A827999;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 40; ++n)
    {
        t = HASH_ROL(a, 5) + (d ^ c ^ b) + words[n] + e + 0x6ED9EBA1;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 60; ++n)
    {
        t = HASH_ROL(a, 5) + (((c | b) & d) | (c & b)) + words[n] + e + 0x8F1BBCDC;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    for (; n < 80; ++n)
    {
        t = HASH_ROL(a, 5) + (d ^ c ^ b) + words[n] + e + 0xCA62C1D6;
        e = d; d = c; c = HASH_ROL(b, 30); b = a; a = t;
    }
    context->state[0] += a;
    context->state[1] += b;
    context->state[2] += c;
    context->state[3] += d;
    context->state[4] += e;
}

// 0x005209D0
void __fastcall BNDOWNLOAD_HashBuffer(unsigned int* pOut, const void* pData, unsigned int nSize)
{
    D2BnetHashContextStrc tContext;
    tContext.state[0] = 0x67452301;
    tContext.state[1] = 0xEFCDAB89;
    tContext.state[2] = 0x98BADCFE;
    tContext.state[3] = 0x10325476;
    tContext.state[4] = 0xC3D2E1F0;
    for (unsigned int i = 0; i < nSize; i += 64)
    {
        unsigned int nLength = nSize - i;
        if (nLength > 64)
            nLength = 64;
        memcpy(tContext.f_14, pData, nLength);
        if (nLength < 64)
            memset(&tContext.f_14[nLength], 0, 64 - nLength);
        BNDOWNLOAD_HashTransform(&tContext);
    }
    pOut[0] = tContext.state[0];
    pOut[1] = tContext.state[1];
    pOut[2] = tContext.state[2];
    pOut[3] = tContext.state[3];
    pOut[4] = tContext.state[4];
}

// 0x00520A80
static inline int BNDOWNLOAD_CheckStringBlock(const char* pBuffer, unsigned int nPos, unsigned int nCount, unsigned int nSize)
{
    if (nSize < nPos + nCount)
    {
        return 0;
    }
    if (!nCount)
    {
        return 1;
    }
    if (pBuffer[nSize - 1])
    {
        return 0;
    }
    const unsigned int nEnd = nSize - 1;
    unsigned int nFound = 0;
    for (unsigned int i = nPos; i < nEnd; ++i)
    {
        if (!pBuffer[i])
        {
            ++nFound;
        }
    }
    return nFound == nCount - 1;
}

// 0x00520AD0
extern "C" int __cdecl BNDOWNLOAD_SetDisconnected()
{
    return gnFlag_00882528 = 1;
}

// 0x00520B30
int __cdecl BNDOWNLOAD_ResetReplies()
{
    for (int i = 0; i < 94; ++i)
        ganSlotArrayB[i] = 0;
    for (int i = 0; i < 94; ++i)
        ganSlotArrayA[i] = 0;
    gnLastStatus = 0xFF;
    gnFlag_00882528 = 0;
    BNMESSQUEUE_SetState(0);
    return 1;
}

// 0x00520B70
int __fastcall BNDOWNLOAD_WaitForReply(unsigned char nReply)
{
    const unsigned long dwStart = GetTickCount();
    while (!ganSlotArrayA[nReply])
    {
        if (gdwGlobal_00882528)
        {
            BNMESSQUEUE_SetError(0x12);
            return 0;
        }
        if (GetTickCount() - dwStart > 45000)
        {
            BNMESSQUEUE_SetError(0x11);
            return 0;
        }
        Sleep(10);
    }
    return 1;
}

// 0x00520BF0
int __fastcall BNDOWNLOAD_IsReplyReceived(unsigned char nReply)
{
    return ganSlotArrayA[nReply];
}

// 0x00520C00
extern "C" void __fastcall BNDOWNLOAD_ClearReply(unsigned char nSlot)
{
    ganSlotArrayA[nSlot] = 0;
    ganSlotArrayB[nSlot] = 0;
}

// 0x00520C20
extern "C" int __fastcall BNDOWNLOAD_GetReplyValue(unsigned char nSlot)
{
    return ganSlotArrayB[nSlot];
}

// 0x00520C50
int __fastcall BNDOWNLOAD_HandleCreateAccount(const int* pData, unsigned int nSize)
{
    gdwGlobal_00882350 = pData[0];
    return 1;
}

// 0x00520C60
int __fastcall BNDOWNLOAD_HandleCreateAccountEx(const int* pData, unsigned int nSize)
{
    gnCreateAccountResult = pData[0];
    gbCreateAccountReplied = 1;
    return 1;
}

// 0x00520C80
int __fastcall BNDOWNLOAD_HandleChangePassword(const int* pData, unsigned int nSize)
{
    gnChangePasswordResult = pData[0];
    gbChangePasswordReplied = 1;
    if (!gnChangePasswordResult)
        BNMESSQUEUE_SetError(0xE);
    return 1;
}

// 0x00520D50
int __fastcall BNDOWNLOAD_HandleLogonChallenge(const int* pData, unsigned int nSize)
{
    sub_0051A540_SetValue(pData[0]);
    return 1;
}

// 0x00520D60
int __fastcall BNDOWNLOAD_HandleStartAdvex(const int* pData, unsigned int nSize)
{
    if (!pData[0])
        gdwGlobal_00882318 = 1;
    return 1;
}

// 0x00520DA0
int __fastcall BNDOWNLOAD_HandleLogonResponse(const int* pData, unsigned int nSize)
{
    gnLastStatus = pData[0] == 0;
    return 1;
}

extern int gnLastStatus_0072FFA8; // 0x0072FFA8

int __fastcall BNSEND_SetErrorText(int nError, const char* szText); // 0x005204D0

struct D2BnReply00520DC0Strc
{
    int nStatus;
    char szText[1];
};

// 0x00520DC0
int __fastcall BNDOWNLOAD_HandleStatus(D2BnReply00520DC0Strc* pReply)
{
    const int nStatus = pReply->nStatus;
    gnLastStatus_0072FFA8 = nStatus;
    switch (nStatus)
    {
    case 0:
        break;
    case 1:
        BNMESSQUEUE_SetError(0xD);
        break;
    case 2:
        BNMESSQUEUE_SetError(0xE);
        break;
    case 3:
        BNMESSQUEUE_SetError(0xF);
        break;
    case 6:
        BNSEND_SetErrorText(0x1B, pReply->szText);
        break;
    default:
        BNMESSQUEUE_SetError(0x12);
        break;
    }
    return 1;
}

// 0x00520E50
int __fastcall BNDOWNLOAD_HandleReportVersion(D2VersionReplyStrc* pReply, int nSize)
{
    const unsigned int nResult = pReply->nResult;
    switch (nResult)
    {
    case 1:
    case 2:
    case 3:
        BNSEND_SendCrashDump();
        break;
    }

    SRegSaveData("Patch", "Patches", 0x82, &gszEmptyAssertText, 1);

    if (nResult == 1)
    {
        const char* szText = pReply->szText;
        const int nLength = nSize - 4;
        sub_0051E370_SetText(szText, nLength);
        SRegSaveData("Patch", "Patches", 0x82, szText, nLength);
        D2FileTimeStrc tFileTime = { 0 };
        BNDOWNLOAD_RequestDownload(0x80000002, 2, 0, 0, &tFileTime, szText, 0);
        gnUpdateState = 0;
        BNDOWNLOAD_LogPrintf("downloading upgrade");
        return 1;
    }

    if (nResult == 2)
    {
        gnUpdateState = 1;
        BNDOWNLOAD_LogPrintf("user has latest version");
        return 1;
    }

    BNMESSQUEUE_SetError(1);
    if (nResult == 3)
    {
        gnUpdateState = 0;
        BNDOWNLOAD_LogPrintf("User must reinstall and patch");
        return 1;
    }

    gnUpdateState = 0;
    BNDOWNLOAD_LogPrintf("user has unknown version");
    return 1;
}

// 0x00520FC0
int __fastcall BNDOWNLOAD_HandlePing(const void* pData, unsigned int nSize)
{
    BNSEND_SendPacket(0x25, pData, nSize);
    return 1;
}

// 0x00520FE0
int __fastcall BNDOWNLOAD_HandleCdKeyReply(D2BnReplyStrc* pReply)
{
    const unsigned int nResult = pReply->nResult;
    gnReplyResult = nResult;
    gszReplyText_00882428[0] = 0;
    gnReplyReady = 0;
    switch (nResult)
    {
    case 0:
        gnReplyReady = 1;
        break;
    case 3:
        BNMESSQUEUE_SetState(3);
        break;
    case 6:
        BNMESSQUEUE_SetState(5);
        break;
    case 5:
        BNMESSQUEUE_SetState(4);
        break;
    case 4:
        BNMESSQUEUE_SetState(6);
        SStrCopy(gszReplyText_00882428, pReply->szText, 0x100);
        BNMESSQUEUE_SetStateArg(gszReplyText_00882428);
        break;
    }
    return 1;
}

// 0x005210A0
int __fastcall BNDOWNLOAD_HandleServerList(const void* pData, unsigned int nSize)
{
    SRegSaveString(gszConfiguration, "Server List", 2, (const char*)pData + 4);
    return 1;
}

// 0x005210C0
int __fastcall BNDOWNLOAD_HandleGetChannelList(const void* pData, unsigned int nSize)
{
    BNSEND_SetChannelList(pData, nSize);
    return 1;
}

// 0x005210D0
int __fastcall BNDOWNLOAD_HandleGetAdvListEx(const void* pData, unsigned int nSize)
{
    BNSEND_SetGamesList(pData, nSize);
    return 1;
}

// 0x005210F0
int __fastcall BNDOWNLOAD_HandleEnterChat(const void* pData, unsigned int nSize)
{
    BNMESSQUEUE_QueueText(2, (const char*)pData);
    BNSEND_SetInfoText((const char*)pData);
    return 1;
}

// 0x00521110
int __fastcall BNDOWNLOAD_HandleGetFileTime(const void* pData, unsigned int nSize)
{
    const D2BnReportStrc* pReport = (const D2BnReportStrc*)pData;
    const int nResult = pReport->nResult;
    const D2FileTimeStrc* pFileTime = &pReport->tFileTime;
    const char* szText = (const char*)(pFileTime + 1);
    const int nSubType = (nResult == 0x80000005 || nResult == 0x80000006) ? 2 : 4;
    BNDOWNLOAD_RequestDownload(nResult, nSubType | 1, 0, 0, pFileTime, szText, 0);
    return 1;
}

// 0x00521150
int __fastcall BNDOWNLOAD_HandleCheckAd(const D2BnCheckAdReplyStrc* pPacket, unsigned int nSize)
{
    const unsigned int nAdId = pPacket->nAdId;
    if (nSize >= 0x11 && nAdId != gnVersion)
    {
        const unsigned char* pData = pPacket->pData;
        const char* szFileName = (const char*)(pData + sizeof(D2FileTimeStrc));
        gnVersion = nAdId;
        const char* szLink = szFileName + strlen(szFileName) + 1;
        if (*szFileName && *szLink)
            BNDOWNLOAD_RequestDownload(0x80000003, 5, nAdId, pPacket->nExtension, (const D2FileTimeStrc*)pData, szFileName, szLink);
    }
    return 1;
}

// 0x005211D0
int __fastcall BNDOWNLOAD_HandleQueryRealms(const void* pData, unsigned int nSize)
{
    BNSEND_SetRealmList(pData, nSize);
    return 1;
}

// 0x005211E0
int __fastcall BNDOWNLOAD_HandleQueryAdUrl(const void* pData, unsigned int nSize)
{
    BNSEND_SetAdUrlReply(pData, nSize);
    return 1;
}

// 0x005211F0
int __fastcall BNDOWNLOAD_HandleLogonRealmEx(const void* pData, unsigned int nSize)
{
    BNSEND_SetRealmLogonReply(pData, nSize);
    return 1;
}

// 0x00521200
int __fastcall BNDOWNLOAD_HandleReadUserData(const void* pData, unsigned int nSize)
{
    BNSEND_SetReadUserDataReply(pData, nSize);
    return 1;
}

// 0x00521210
int __fastcall BNDOWNLOAD_HandleNewsInfo(const void* pData, unsigned int nSize)
{
    return BNNEWS_ParseNewsInfo(pData);
}

static int BNAUTH_IsValidAuthInfo(const unsigned char* pData, unsigned int nSize)
{
    if (nSize < 0x16)
        return 0;
    if (pData[nSize - 1])
        return 0;
    unsigned int nCount = 0;
    for (unsigned int i = 0x14; i < nSize - 1; ++i)
    {
        if (!pData[i])
            ++nCount;
    }
    if (nCount != 1)
        return 0;
    return 1;
}

static int BNAUTH_IsValidAuthCheck(const unsigned char* pData, unsigned int nSize)
{
    if (nSize < 5)
        return 0;
    if (pData[nSize - 1])
        return 0;
    unsigned int nCount = 0;
    for (unsigned int i = 4; i < nSize - 1; ++i)
    {
        if (!pData[i])
            ++nCount;
    }
    if (nCount != 0)
        return 0;
    return 1;
}

// 0x005212D0
int __fastcall BNDOWNLOAD_HandleAuthCheck(const unsigned char* pData, unsigned int nSize)
{
    if (!BNAUTH_IsValidAuthCheck(pData, nSize))
    {
        sub_0051A480_DebugLog("INVALID: AuthCheck");
        return 0;
    }

    unsigned int nResult = *(const unsigned int*)pData;
    unsigned int nCode = nResult & 0xFF0F;
    const char* szInfo = (const char*)pData + 4;

    switch (nCode)
    {
    case 0:
    case 0x100:
    case 0x102:
        BNSEND_SendCrashDump();
        break;
    }

    gszReplyText[0] = 0;
    gnGlobal_008823B0 = 0;
    SRegSaveData("Patch", "Patches", 0x82, &gszEmptyAssertText, 1);

    switch (nCode)
    {
    case 0x100:
    {
        char szPatches[0x100];
        unsigned int nLength = SStrCopy(szPatches, szInfo, 0xFE) + 1;
        szPatches[nLength] = 0;
        ++nLength;
        sub_0051E370_SetText(szPatches, nLength);
        SRegSaveData("Patch", "Patches", 0x82, szPatches, nLength);
        D2FileTimeStrc tFileTime;
        tFileTime.dwLowDateTime = 0;
        tFileTime.dwHighDateTime = 0;
        BNDOWNLOAD_RequestDownload(0x80000002, 2, 0, 0, &tFileTime, szPatches, 0);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("Downloading Upgrade");
        break;
    }
    case 0:
        gnGlobal_008823B0 = 1;
        gnGlobal_008823EC = 1;
        sub_0051A480_DebugLog("User has latest version and a valid cdkey");
        break;
    case 0x101:
        BNMESSQUEUE_SetError(1);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("User has unknown version");
        break;
    case 0x102:
        BNMESSQUEUE_SetError(1);
        gnGlobal_008823EC = 0;
        sub_0051A480_DebugLog("User must revert to an older version");
        break;
    case 0x200:
    {
        BNMESSQUEUE_SetState(((nResult >> 4) & 0xF) ? 7 : 3);
        sub_0051A480_DebugLog("User has an invalid cdkey (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x203:
    {
        BNMESSQUEUE_SetState(((nResult >> 4) & 0xF) ? 9 : 5);
        sub_0051A480_DebugLog("CD Key is for another product (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x202:
    {
        BNMESSQUEUE_SetState(((nResult >> 4) & 0xF) ? 8 : 4);
        sub_0051A480_DebugLog("CD Key is disabled (%ld)", (nResult >> 4) & 0xF);
        break;
    }
    case 0x201:
    {
        BNMESSQUEUE_SetState(((nResult >> 4) & 0xF) ? 10 : 6);
        SStrCopy(gszReplyText, szInfo, 0x100);
        BNMESSQUEUE_SetStateArg(gszReplyText);
        sub_0051A480_DebugLog("CD Key is in use by %s (%ld)", gszReplyText, (nResult >> 4) & 0xF);
        break;
    }
    }
    return 1;
}

// 0x005215B0
int __fastcall BNDOWNLOAD_HandleAuthAccountCreate(const void* pData, unsigned int nSize)
{
    if (nSize < 4)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountCreate");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        gnCreateAccountResult = 0;
        sub_0051A480_DebugLog("Account created");
        break;
    case 4:
        gnCreateAccountResult = 4;
        sub_0051A480_DebugLog("Create failed: Name is in use");
        break;
    case 7:
        gnCreateAccountResult = 1;
        sub_0051A480_DebugLog("Create failed: Name blank");
        break;
    case 8:
        gnCreateAccountResult = 2;
        sub_0051A480_DebugLog("Create failed: Name contains bad characters");
        break;
    case 9:
        gnCreateAccountResult = 3;
        sub_0051A480_DebugLog("Create failed: Name contains bad words");
        break;
    case 10:
        gnCreateAccountResult = 6;
        sub_0051A480_DebugLog("Create failed: Name doesn't have alpha characters");
        break;
    case 11:
        gnCreateAccountResult = 7;
        sub_0051A480_DebugLog("Create failed: Name contains adjacent punctuation");
        break;
    case 12:
        gnCreateAccountResult = 8;
        sub_0051A480_DebugLog("Create failed: Name contains too much punctuation");
        break;
    default:
        gnCreateAccountResult = 4;
        sub_0051A480_DebugLog("Create failed: unknown result");
        break;
    }
    gdwGlobal_008823F0 = 1;
    return 1;
}

// 0x005216B0
int __fastcall BNDOWNLOAD_HandleAuthAccountLogon(const void* pData, unsigned int nSize)
{
    if (nSize < 0x44)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountLogon");
        return 0;
    }

    switch (*(const int*)pData)
    {
    case 0:
        sub_0051A480_DebugLog("Logon requires proof");
        return BNSEND_SendAccountLogonProof((const unsigned char*)pData + 4, (const unsigned char*)pData + 0x24);
    case 1:
        sub_0051A480_DebugLog("Logon failed: Account unknown");
        BNMESSQUEUE_SetError(0x0D);
        gnLastStatus = 1;
        return 1;
    case 5:
        sub_0051A480_DebugLog("Logon requires upgrade");
        if (!sub_005223A0(1))
        {
            BNMESSQUEUE_SetError(0x12);
            return 0;
        }
        return 1;
    default:
        sub_0051A480_DebugLog("Logon failed: Unknown result");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    }
}

// 0x00521760
int __fastcall BNDOWNLOAD_HandleAuthAccountLogonProof(const void* pData, unsigned int nSize)
{
    if (nSize < 0x18)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountLogonProof");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        if (BNSEND_CheckServerProof((const unsigned char*)pData + 4))
        {
            sub_0051A480_DebugLog("Logon Proof success");
            gnLastStatus = 0;
            return 1;
        }
        sub_0051A480_DebugLog("Logon Proof failed: Server didn't know our password but told us it did!");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    case 2:
        sub_0051A480_DebugLog("Logon Proof failed: Invalid password");
        BNMESSQUEUE_SetError(0x0E);
        gnLastStatus = 2;
        return 1;
    default:
        sub_0051A480_DebugLog("Logon Proof failed: Unknown result");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    }
}

// 0x00521800
int __fastcall BNDOWNLOAD_HandleAuthAccountChange(const void* pData, unsigned int nSize)
{
    if (nSize < 0x44)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountChange");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        sub_0051A480_DebugLog("Change requires proof");
        return BNSEND_SendAccountChangeProof((const unsigned char*)pData + 4, (const unsigned char*)pData + 0x24);
    case 1:
        sub_0051A480_DebugLog("Change failed: Account unknown");
        BNMESSQUEUE_SetError(0x0D);
        return 1;
    case 5:
        sub_0051A480_DebugLog("Change requires upgrade");
        return sub_005223A0(0);
    default:
        sub_0051A480_DebugLog("Change failed: Unknown result");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    }
}

// 0x005218A0
int __fastcall BNDOWNLOAD_HandleAuthAccountChangeProof(const void* pData, unsigned int nSize)
{
    if (nSize < 0x18)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountChangeProof");
        return 0;
    }
    const int nResult = *(const int*)pData;
    BNSEND_ClearPassword();
    switch (nResult)
    {
    case 0:
        if (BNSEND_CheckServerProof((const unsigned char*)pData + 4))
        {
            sub_0051A480_DebugLog("Change Proof success");
            gdwGlobal_008823FC = 1;
            return 1;
        }
        sub_0051A480_DebugLog("Change Proof failed: Server didn't know our password but told us it did!");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    case 2:
        sub_0051A480_DebugLog("Change Proof failed: Invalid password");
        gdwGlobal_008823FC = 1;
        BNMESSQUEUE_SetError(0x0E);
        return 1;
    default:
        sub_0051A480_DebugLog("Change Proof failed: Unknown result");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    }
}

// 0x00521950
int __fastcall BNDOWNLOAD_HandleAuthAccountUpgrade(const void* pData, unsigned int nSize)
{
    if (nSize < 8)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountUpgrade");
        return 0;
    }
    const D2BnTokenReplyStrc* pReply = (const D2BnTokenReplyStrc*)pData;
    const unsigned int nToken = pReply->nToken;
    if (pReply->nResult)
    {
        sub_0051A480_DebugLog("Upgrade Failed: Unknown result");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    }
    sub_0051A480_DebugLog("Upgrade requires proof");
    BNSEND_SendAccountUpgradeProof(nToken);
    return 1;
}

// 0x005219B0
int __fastcall BNDOWNLOAD_HandleAuthAccountUpgradeProof(const void* pData, unsigned int nSize)
{
    if (nSize < 4)
    {
        sub_0051A480_DebugLog("INVALID: AuthAccountUpgradeProof");
        return 0;
    }
    switch (*(const int*)pData)
    {
    case 0:
        if (GAME_GetLoginRetryCount())
        {
            sub_0051A480_DebugLog("Upgrade Proof success, logging in");
            return BNDOWNLOAD_ResendAccountLogon();
        }
        sub_0051A480_DebugLog("Upgrade Proof success, password changed");
        BNSEND_ClearPassword();
        gnChangePasswordResult = 0;
        gdwGlobal_008823FC = 1;
        return 1;
    case 2:
        if (GAME_GetLoginRetryCount())
        {
            sub_0051A480_DebugLog("Upgrade Proof Failed: Invalid password during logon");
            BNSEND_ClearPassword();
            gnLastStatus = 2;
            BNMESSQUEUE_SetError(0x0E);
            return 1;
        }
        sub_0051A480_DebugLog("Upgrade Proof Failed: Invalid password during change");
        BNSEND_ClearPassword();
        gnChangePasswordResult = 2;
        gdwGlobal_008823FC = 1;
        BNMESSQUEUE_SetError(0x0E);
        return 1;
    default:
        sub_0051A480_DebugLog("Upgrade Proof failed: Unknown Result");
        BNMESSQUEUE_SetError(0x12);
        return 0;
    }
}

// 0x00521AB0
int __fastcall BNDOWNLOAD_HandleSetEmail(const void* pData, unsigned int nSize)
{
    BNSEND_SetEmailRequested(1);
    return 1;
}

// 0x00521AC0
int __fastcall BNDOWNLOAD_HandleOptionalWork(const void* pData, unsigned int nSize)
{
    if (pData && *(const char*)pData && nSize)
        BNDOWNLOAD_SendGetFileTime((const char*)pData, 0x80000005);
    return 1;
}

// 0x00521AE0
int __fastcall BNDOWNLOAD_HandleRequiredWork(const void* pData, unsigned int nSize)
{
    if (pData && *(const char*)pData && nSize)
        BNDOWNLOAD_SendGetFileTime((const char*)pData, 0x80000006);
    return 1;
}

// 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// build: symbol ?BNSEND_NibbleToHex@* 0x0051DD10
static unsigned int BNSEND_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

// build: symbol ?BNSEND_HexToNibble@* 0x0051DD20
static int BNSEND_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// build: symbol ?BNSEND_MapKeyChar@* 0x0051DD40
static int BNSEND_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return BNSEND_NibbleToHex(tolower(n)) + BNSEND_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return BNSEND_HexToNibble((char)tolower(n)) * 16 + BNSEND_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return BNSEND_MapKeyChar((unsigned char)tolower(n)) * 24 + BNSEND_MapKeyChar((unsigned char)tolower(n + 1));
}

// 0x00521BA0
unsigned int __cdecl BNDOWNLOAD_GetUILanguageId()
{
    void* hKernel = LoadLibraryA(gszKernel32);
    if (hKernel)
    {
        unsigned short (__stdcall* pfnGetUILanguage)() = (unsigned short (__stdcall*)())GetProcAddress(hKernel, "GetSystemDefaultUILanguage");
        if (pfnGetUILanguage)
        {
            unsigned short nLangId = pfnGetUILanguage();
            FreeLibrary(hKernel);
            return nLangId;
        }
        FreeLibrary(hKernel);
    }
    return GetSystemDefaultLangID();
}

// 0x00522050
int __cdecl BNDOWNLOAD_ResendAccountLogon()
{
    D2BnAccountLogonStrc tPacket;
    sub_0041D2A0_MemCopy(tPacket.abPublic, gtLoginRecord.abPublic, sizeof(tPacket.abPublic));
    const unsigned int nLength = SStrCopy(tPacket.szAccountName, gszAccountName, sizeof(tPacket.szAccountName));
    BNSEND_SendPacket(0x53, &tPacket, sizeof(tPacket.abPublic) + nLength + 1);
    return 1;
}

// 0x005223A0
int __fastcall BNDOWNLOAD_SendAccountUpgrade(int bRetry)
{
    if (bRetry && (unsigned int)++gnLoginRetryCount > 1)
        return 0;

// build: symbol ?MakeVerifier@* 0x00528660
    gtBigPair.MakeVerifier(gtLoginRecord.szName, gtLoginRecord.szPassword, gabNewVerifier, gabNewVerifier + 0x20);
    BNSEND_SendPacket(0x57, 0, 0);
    return 1;
}

// 0x00522500
unsigned int __fastcall BNDOWNLOAD_GetKeyNibble(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = (nIndex & 7) * 4;
    return (pKey[3 - (nIndex >> 3)] & (0xF << nShift)) >> nShift;
}

inline unsigned int GetNibble(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    return (pKey[nWord] & (0xF << nShift)) >> nShift;
}

inline void SetNibble(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    pKey[nWord] = (pKey[nWord] & ~(0xF << nShift)) | ((nValue & 0xF) << nShift);
}

// 0x00522530
void __fastcall BNDOWNLOAD_SetKeyNibble(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = (nIndex & 7) * 4;
    const unsigned int nWord = 3 - (nIndex >> 3);
    pKey[nWord] = (pKey[nWord] & ~(0xF << nShift)) | ((nValue & 0xF) << nShift);
}

// 0x00522570
unsigned int __fastcall BNDOWNLOAD_GetKeyBit(const unsigned int* pKey, unsigned int nIndex)
{
    const int nShift = nIndex & 0x1F;
    return (pKey[3 - (nIndex >> 5)] & (1 << nShift)) >> nShift;
}

// 0x005225A0
void __fastcall BNDOWNLOAD_SetKeyBit(unsigned int* pKey, unsigned int nIndex, unsigned char nValue)
{
    const int nShift = nIndex & 0x1F;
    const unsigned int nWord = 3 - (nIndex >> 5);
    pKey[nWord] = (pKey[nWord] & ~(1 << nShift)) | ((nValue & 1) << nShift);
}

// 0x005225E0
unsigned int __fastcall BNDOWNLOAD_MulAddWords(unsigned int nWords, unsigned int nMultiplier, const unsigned int* pSource, unsigned int* pDest, unsigned int nCarry)
{
    pSource += nWords;
    pDest += nWords;
    while (nWords > 0)
    {
        --nWords;
        const unsigned __int64 nResult = (unsigned __int64)*--pSource * nMultiplier + nCarry;
        *--pDest = (unsigned int)nResult;
        nCarry = (unsigned int)(nResult >> 32);
    }
    return nCarry;
}

// 0x00522650
void __fastcall BNDOWNLOAD_DecodeKeyDigits(const char* szKey, unsigned char* pOut)
{
    int nBase = 5;
    unsigned int nPosition = 0x21;
    for (unsigned int i = 0; i < 26; ++i)
    {
        const unsigned int nFirst = (nPosition + 0x7B5) % 0x34;
        nPosition = (nFirst + 0x7B5) % 0x34;
        const int nValue = gaCdKeyCharMap[(unsigned char)szKey[i]];
        pOut[nFirst] = nValue / nBase;
        pOut[nPosition] = nValue % nBase;
    }
}

// 0x00522980
void __stdcall BNDOWNLOAD_SubstituteKeyNibbles(unsigned int* pKey)
{
    for (int i = 29; i >= 0; --i)
    {
        unsigned char nValue = (unsigned char)GetNibble(pKey, i);
        for (int j = 29; j > i; --j)
            nValue = gaSubstitutionBox[i][(unsigned char)GetNibble(pKey, j) ^ gaSubstitutionBox[i][nValue]];
        for (int j = i - 1; j >= 0; --j)
            nValue = gaSubstitutionBox[i][(unsigned char)GetNibble(pKey, j) ^ gaSubstitutionBox[i][nValue]];
        SetNibble(pKey, i, gaSubstitutionBox[i][nValue]);
    }
}

// 0x00522BC0
void __fastcall BNDOWNLOAD_FillRandomBytes(char* szBuffer, int nSize)
{
    srand(0x150B);
    for (int i = 0; i < nSize - 1; )
    {
        const char c = (char)rand();
        if (c)
        {
            szBuffer[i] = c;
            i += 1;
        }
    }
    srand(_time32(0));
    szBuffer[nSize - 1] = 0;
}

// 0x00522C20
void __cdecl BNDOWNLOAD_ClearCryptState()
{
    sub_00524740_ClearKeySchedules();
    sub_005241A0_ClearHashContexts();
}

// bEncrypt: the original reloads it from its stack slot on each SetKey call and frees ebx before that loop; a plain parameter stays in ebx.
// 0x00522C30
void __fastcall BNDOWNLOAD_InitCipherKeys(const char* szKey, int nUnused, volatile int bEncrypt)
{
    unsigned char abRandom[0x70];
    unsigned char abBlock[0x40];
    unsigned char abDigest[20];

    D2_ASSERT(szKey, 0x4E);

    srand(0x4FA7);
    unsigned char* pRandom = abRandom;
    int nCount = 0x70;
    while (nCount--)
    {
        *pRandom++ = (unsigned char)rand();
    }
    srand(_time32(0));

    int j = 0;
    for (int i = 0; i < 0x40; ++i)
    {
        if (!szKey[j])
        {
            j = 0;
        }
        abBlock[i] = szKey[j];
        ++j;
    }

    sub_00524280_InitHashContext(0);
    sub_00524200_HashBlock(0, abBlock, (unsigned int*)abDigest);
    sub_005241A0_ClearHashContexts();

    for (unsigned int i = 0; i < 0x70; ++i)
    {
        abRandom[i] ^= abDigest[i % 20];
    }

    for (int i = 0; i < 3; ++i)
    {
        sub_00524780_SetKey(i, bEncrypt, (const D2IdeaUserKeyStrc*)&abRandom[i * 16]);
        sub_00524280_InitHashContext(i);
        sub_00524200_HashBlock(i, &abRandom[0x30], 0);
    }
}

// 0x00522E10
unsigned int __fastcall BNDOWNLOAD_DecryptData(unsigned char* data,unsigned int size,unsigned int key)
{
 struct { unsigned char input[64],output[64]; } buffers;
 unsigned char digest[20];
 CHECK(data,0x91);
 const unsigned int& keyValue=key;
 const char* checkedKey=(const char*)keyValue;
 CHECK(checkedKey,0x92);
 ((D2CipherKeyView*)checkedKey)->Init(0);
 if(size<=8)return 0;
 size-=8;
 if(size&63)return 0;
 unsigned int remaining=size;
 int blockIndex=0;
 while(remaining){
  memcpy(buffers.input,data,64);
  sub_005241C0_GetDigest(0,digest);
  if(!(blockIndex&7)){
   for(int i=0;i<64;i+=8)sub_00524760_CipherBlock(0,(const unsigned short*)&buffers.input[i],(unsigned short*)&buffers.output[i]);
  }else memcpy(buffers.output,buffers.input,64);
  for(int i=0;i<64;++i)buffers.input[i]=buffers.output[i]-digest[(63-i)%20];
  if(!(blockIndex&15))sub_00524200_HashBlock(0,buffers.input,0);
  ++blockIndex;
  memcpy(data,buffers.input,64);
  remaining-=64;
  data+=64;
 }
 if(data[4]>0){
  sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return 0;
 }
 sub_005241C0_GetDigest(0,digest);
 if(*(unsigned int*)data!=*(unsigned int*)digest){
  sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return 0;
 }
 size+=data[5];
 size-=64;
 sub_00524740_ClearKeySchedules();sub_005241A0_ClearHashContexts();return size;
}

struct D2CDKeyInfoStrc;

struct D2CipherKeyStringView;


struct D2CDKeyInfoStrc
{
    unsigned int dwKeyLength;
    unsigned int dwProductValue;
    unsigned int f_8;
    unsigned int f_C;
    unsigned int dwHash[5];
};

int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0

int __fastcall sub_0051E340_BuildCDKeyInfoForSlot(D2CDKeyInfoStrc* pInfo, unsigned int dwClientToken, int nSlot); // 0x0051E340

int __cdecl GAME_GetAbortFlag(); // 0x00520AE0

void __cdecl GRID_LockCDKeys(); // 0x005234D0

void __cdecl GRID_UnlockCDKeys(); // 0x005239C0

const char* __cdecl GAME_GetExeInfo(); // 0x00523AA0

struct D2CipherKeyStringView
{
    void __thiscall BNDOWNLOAD_InitCipherKeys(int bEncrypt); // 0x00522C30
};


unsigned int __fastcall sub_00523020_GetAlignedData(unsigned int nSize); // 0x00523020

unsigned int gdwBnClientToken; // 0x00882530

int __cdecl sub_00521DC0_SendAuthCheck(); // 0x00521DC0

// 0x00523060
void __fastcall BNDOWNLOAD_EncodeData(unsigned char* pData, unsigned int nSize, unsigned int nBufferSize, unsigned int nKey)
{
    unsigned char abDigest[20];
    unsigned char aaBlocks[2][64];
    unsigned char abFinalDigest[20];

    D2_ASSERT(pData, 0x105);
    const unsigned int& nKeyValue = nKey;
    const char* szKey = (const char*)nKeyValue;
    D2_ASSERT(szKey, 0x106);
    D2_ASSERT(nBufferSize == sub_00523020_GetAlignedData(nSize), 0x108);

    ((D2CipherKeyStringView*)szKey)->BNDOWNLOAD_InitCipherKeys(1);

    unsigned int nBlock = 0;
    unsigned int nChunk = 0;
    while (nSize)
    {
        nChunk = nSize;
        if (nChunk >= 0x40)
            nChunk = 0x40;

        memcpy(aaBlocks[0], pData, nChunk);
        if (nChunk < 0x40)
            memset(&aaBlocks[0][nChunk], 0, 0x40 - nChunk);

        sub_005241C0_GetDigest(0, (unsigned int*)abDigest);
        if (!(nBlock & 0xF))
            sub_00524200_HashBlock(0, aaBlocks[0], 0);

        for (int i = 0; i < 0x40; ++i)
            aaBlocks[1][i] = abDigest[(unsigned int)(0x3F - i) % 20] + aaBlocks[0][i];

        if (!(nBlock & 7))
        {
            for (int i = 0; i < 0x40; i += 8)
                sub_00524760_CipherBlock(0, (unsigned short*)&aaBlocks[1][i], (unsigned short*)&aaBlocks[0][i]);
        }
        else
        {
            memcpy(aaBlocks[0], aaBlocks[1], 0x40);
        }

        memcpy(pData, aaBlocks[0], 0x40);
        nSize -= nChunk;
        pData += 0x40;
        ++nBlock;
    }

    sub_005241C0_GetDigest(0, (unsigned int*)abFinalDigest);
    D2EncodedTrailerStrc* pTrailer = (D2EncodedTrailerStrc*)pData;
    pTrailer->nDigest = *(unsigned int*)abFinalDigest;
    pTrailer->nReserved = 0;
    pTrailer->nLastBlockSize = (unsigned char)nChunk;
    pTrailer->wReserved = 0;

    sub_00524740_ClearKeySchedules();
    sub_005241A0_ClearHashContexts();
}

// 0x00523280
static unsigned int BNDOWNLOAD_CountTerminatedBytes(unsigned int maxLength, unsigned int length, const unsigned char* data)
{
    unsigned int count = 0;
    if (length >= maxLength)
        length = maxLength;
    if (!length)
        return 0;
    do
    {
        --length;
        ++count;
        if (!(*data++))
            return count;
    } while (length);
    return 0;
}

unsigned int __fastcall CountTerminatedBytesContext(unsigned int length, const unsigned char* data, unsigned int maxLength)
{
    return BNDOWNLOAD_CountTerminatedBytes(maxLength, length, data);
}

#include "gen/data/Source/D2BNClient/BnDownload.inc"
