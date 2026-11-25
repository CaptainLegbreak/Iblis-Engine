#include "D2BNClient.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Primitives.h"

#include "D2ClientMenus.h"

#include "D2BnCryptTypes.h"

#include "D2NetTypes.h"

#include "D2Records.h"

#include "D2LevelTxt.h"

#include "D2StormSha1.h"

#include "D2SetsTxt.h"

#include "D2BnMessages.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PlayerDataStrc;

struct D2TextHeaderStrc;

struct D2BnSizedReplyStrc;

struct QServer;

struct D2CriticalSectionStrc;

struct D2BnRegistrationPacketStrc;

struct D2BnLogonRequestStrc;

struct D2BnCheckAdPacketStrc;

struct D2BnVersionPacketStrc;

struct D2BnLocalePacketStrc;

struct D2CommonChatIgnoreListStrc;

struct D2CommonIgnoreListStrc;

struct D2SetsTxt;

struct D2SetItemsTxt;

struct D2UniqueItemsTxt;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2HotkeyStrc;

struct D2BnGamesListPacketStrc;

struct D2BnAuthHashStrc;

struct D2BnLogonRealmPacketStrc;

struct D2Storm408ElemStrc;

struct D2StormArray408Strc;

struct D2BigLoginRecordStrc;

struct D2BigPowModStrc;

struct D2BigPairStrc;

struct D2BnAdClickStrc;

struct D2BnChangeProofStrc;

struct D2BnKeyValuePacketStrc;

struct D2BnReadUserDataReplyStrc;

struct FSafeSock;

struct D2SystemTimeStrc;

struct D2FileTimeStrc;

struct D2TimeZoneInformationStrc;

struct D2BnRegistrationPacketStrc
{
    unsigned long nLead;
    unsigned long nRegistrationVersion;
    unsigned long nRegistrationAuthority;
    unsigned long nClientId;
    unsigned long f_10;
    char szText[0x400];
};

struct D2BnLogonRequestStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    unsigned int dwUnk0x0C;
};

struct D2BnCheckAdPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    long nTime;
};

struct D2BnVersionPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    char szText[0x500];
};

struct D2BnLocalePacketStrc
{
    D2FileTimeStrc tSystemTime;
    D2FileTimeStrc tLocalTime;
    long f_10;
    unsigned long nSystemLcid;
    unsigned long nUserLcid;
    unsigned long nUserLangId;
    char szText[0x100];
};

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall SystemTimeToFileTime(const D2SystemTimeStrc* pSystemTime, D2FileTimeStrc* pFileTime); // 0x006CC26C

extern "C" __declspec(dllimport) unsigned long __stdcall GetSystemDefaultLCID(void); // 0x006CC39C

extern "C" __declspec(dllimport) long __stdcall InterlockedCompareExchange(long volatile* pDestination, long nExchange, long nComparand); // 0x006CC3A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern "C" unsigned int __cdecl strlen(const char* szString);

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6

int __fastcall EXCEPTIONS_ReadCrashDump(char* pBuffer, unsigned int* pnSize); // 0x0040D290

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __fastcall BNSEND_SendReportVersion(unsigned int dwExeVersion, unsigned int dwExeHash, const char* szExeInfo); // 0x0051A8F0

int __cdecl sub_0051BEC0_IsExpansion(); // 0x0051BEC0

int __fastcall BNSEND_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0

int __fastcall BNSEND_SplitPackets(unsigned char* pBuffer, int nLength); // 0x0051C760

int __fastcall BNSEND_DispatchPacket(unsigned char nId, const void* pData, int nSize);       // 0x00521B00

int __fastcall sub_0051E370_SetText(const char* szText, int nLength); // 0x0051E370

void __fastcall BNDOWNLOAD_SetStatus(int nStatus); // 0x0051EA40

int __fastcall BNDOWNLOAD_SetArchiveName(const char* szName); // 0x0051EA80

int __cdecl BNDOWNLOAD_HasArchiveName(); // 0x0051EAA0

int __fastcall BNDOWNLOAD_RunCheckRevision(int* pArg1, int* pArg2, char* szText); // 0x0051E6D0

int __fastcall BNMESSQUEUE_SetError(int nError); // 0x005204A0

extern "C" const char szEmpty_006DEF80[]; // 0x006DEF80

extern long volatile gnConnected; // 0x00881BF0

extern long volatile gnReceiveThreads; // 0x00881BF4

extern int gbReady; // 0x00881BF8

extern long volatile gnDnsDone; // 0x00881BFC

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SUniConvertUTF16to8(char* pDest, unsigned int nDestSize, const unsigned short* pSrc, unsigned int nSrcLength, unsigned int* pDestWritten, unsigned int* pSrcRead); // 0x006C7130

int __stdcall SUniConvertWinToUTF16(unsigned short* pDst, const char* szSrc, unsigned int nCount); // 0x006C7960

void* gpChannelList;                                                                               // 0x008818C8

char* gpAdUrlReply; // 0x008818DC

void __stdcall SMemCopy(void*, const void*, unsigned int); // 0x0041D2A0

struct D2CommonChatIgnoreListStrc
{
    virtual int IGNORELIST_AddName(const char* szName) = 0;                                                   // 0x00610EB0
    virtual int IGNORELIST_RemoveName(const char* szName) = 0;                                                // 0x0060FB20
    virtual int IGNORELIST_IsListed(const char* szName) = 0;                                              // 0x00610380
    virtual void sub_00610F90_VirtSlot3() = 0;                                                              // 0x00610F90
    virtual int IGNORELIST_RemoveAlias(const char* szName) = 0;                                           // 0x0060FBE0
    virtual void IGNORELIST_IsTextFiltered() = 0;                                                              // 0x0060FC40
    virtual void sub_00611320_VirtSlot6() = 0;                                                              // 0x00611320
    virtual void IGNORELIST_TranslateAlias(const char* szName, char* szOut, int nSize) = 0;                    // 0x0060F870
    virtual int IGNORELIST_IsEnabled() = 0;                                                               // 0x0060DDF0
    virtual void IGNORELIST_SetEnabled(int bEnabled) = 0;                                                 // 0x0060DE00
    virtual void IGNORELIST_ClearAccountAliases() = 0;                                                             // 0x0060F500
};

struct D2CommonIgnoreListStrc : D2CommonChatIgnoreListStrc
{
};

D2CommonIgnoreListStrc* IGNORELIST_GetOrCreateIgnoreList(); // 0x00611560

extern "C" int __fastcall BNDOWNLOAD_GetReplyValue(unsigned char nSlot); // 0x00520C20

enum
{
    NUM_HOTKEYS = 114,
};

typedef void (__cdecl* D2WheelCallbackFn)();

typedef int (__stdcall* D2FarProcFn)();

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(D2FarProcFn lpfn); // 0x006CC34C

void __fastcall DLIGHTMAP_ReleaseLight(void* pResource); // 0x004743D0

void __cdecl TEXT_ResetTextBox(); // 0x0049F960

void __stdcall TEXT_FreeTextHeader(D2TextHeaderStrc* pTextHeader); // 0x006612A0

int __stdcall SFileUnloadFile(void* pBuffer); // 0x00416710

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

unsigned char __stdcall PALETTE_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2WheelCallbackFn gpfnWheelUp; // 0x007A7404

extern D2WheelCallbackFn gpfnWheelDown; // 0x007A7408

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90

extern D2UnitStrc* gapAiTargets[]; // 0x007A7470

extern unsigned char gabColors_007BCAD8[5]; // 0x007BCAD8

extern int gnInvPanelMode; // 0x007BCBF0

extern int gbGoldButtonDisabled; // 0x007BCE2C

extern int gnDialogState; // 0x00721E34

extern int gnHoverTopX; // 0x00721E3C

extern int gnHoverTopY; // 0x00721E40

extern int gnHoverBottomX; // 0x00721E44

extern int gnHoverBottomY; // 0x00721E48

extern int gnHoverCellX; // 0x00721E4C

extern int gnHoverCellY; // 0x00721E50

extern int gbHoverInGrid; // 0x007BCBE4

extern int gbHoverInBodyLoc; // 0x007BCBE8

extern int gpHoverItem; // 0x007BCBF4

extern int gpLastHoverItem; // 0x007BCBF8

extern int gbTextPanelOpen; // 0x007BF1FA

extern D2TextHeaderStrc* gpTextHeader; // 0x007BF250

extern int gnTradeState; // 0x007C0E7C

extern unsigned char* gpDDrawDebugFontGlyphs; // 0x008815AC

void* gpReply_008818D0;                                                                                     // 0x008818D0

struct D2BnGamesListPacketStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
    int nCount;
    char szText[0x100];
};

struct D2BnAuthHashStrc
{
    int f_0;
    int f_4;
    unsigned char abPasswordHash[0x14];
};

struct D2BnLogonRealmPacketStrc
{
    int f_0;
    unsigned char abProof[0x14];
    char szRealmName[0x100];
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

int gdwGlobal_008818BC; // 0x008818BC

D2BnSizedReplyStrc* gpSizedReply;                                                                  // 0x008818D4

extern int gbDnsPending; // 0x008818E0

struct D2Storm408ElemStrc
{
    char unk0x00[0x408];
};

struct D2StormArray408Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2Storm408ElemStrc* m_data;
    unsigned int m_chunk;
};

struct D2BnAdClickStrc
{
    int nAdId;
    int bFlag;
};

struct D2BnChangeProofStrc
{
    unsigned char abProof[0x14];
    unsigned char abVerifier[0x40];
};

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pThreadAttributes, unsigned long nStackSize, unsigned long (__stdcall* pStartAddress)(void*), void* pParameter, unsigned long nCreationFlags, unsigned long* pThreadId); // 0x006CC250

extern "C" int __cdecl memcmp(const void* pBuffer1, const void* pBuffer2, unsigned int nSize);

void __cdecl BNDOWNLOAD_LogPrintf(const char* szFormat, ...); // 0x00518D40

int __cdecl CACHE_LoadCache(); // 0x005193E0

void __cdecl sub_0051A480_DebugLog(const char* szFormat, ...); // 0x0051A480

int __fastcall BNSEND_SendChangePasswordLegacy(const char* szAccountName, const char* szOldPassword, const char* szNewPassword); // 0x0051A7D0

int __cdecl sub_0051C470_CloseBNetConnection(); // 0x0051C470

unsigned long __cdecl BattleConnectFastest(void* pParameter); // 0x0051D0A0

void __cdecl BNNEWS_ReportNews(); // 0x0051D510

int __cdecl BNNEWS_LoadNews(); // 0x0051DA30

int __fastcall BNDOWNLOAD_ApplyPatches(int* pResult); // 0x0051ED00

int __cdecl BNDOWNLOAD_ResetReplies(); // 0x00520B30

void __cdecl sub_00521B50_ReseedLogin(); // 0x00521B50

int __fastcall BNSEND_SendAccountChange(const char* szAccountName, const char* szOldPassword, const char* szNewPassword); // 0x005221F0

void __fastcall CLIENT_ReadPacketFromBuffer(D2PacketBufferStrc* pBuffer, int nBufferSize); // 0x0052AEB0

int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize); // 0x0052B330

int __fastcall SERVER_GetClientPacketSize(D2PacketBufferStrc* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052BC20

int __fastcall QSERVER_CheckClientMask(void* pServer, int nClientId); // 0x006BF6C0

extern "C" const char gszNewsItemTypeName_0072FF8C[]; // 0x0072FF8C

extern int gbNewsActive; // 0x00881C24

extern int (__fastcall* gpfnNewsMessage)(unsigned int nStamp, const char* szText); // 0x00881C28

extern int (__cdecl* gpfnNewsRefresh)(); // 0x00881C2C

extern D2StormArray408Strc gtNewsItems; // 0x00881C30

extern unsigned int gnNewsFirstIndex; // 0x00881C40

extern unsigned int gnNewsNewest; // 0x00881C44

unsigned char gabNewVerifier[0x40];                                                                // 0x00882640

D2BigLoginRecordStrc gtLoginRecord;                                                                // 0x00882680

// build: symbol ??__EgtBigPair@@YAXXZ 0x006CAEF0
// build: symbol ??__FgtBigPair@@YAXXZ 0x006CB480
D2BigPairStrc gtBigPair;                                                                           // 0x0088273C

extern void* gpServer; // 0x00882D08

struct D2BnKeyValuePacketStrc
{
    int nType;
    unsigned int nCount;
    char szText[1];
};

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

struct D2BnReadUserDataReplyStrc
{
    unsigned int nAccounts;
    unsigned int nKeys;
    unsigned int nCookie;
    char aData[1];
};

void* gpReply40;                                                                                     // 0x008818CC

unsigned int gnVersion; // 0x0088252C

struct D2BnHashInputStrc;

struct D2BnLogonResponsePacketStrc;

struct D2BnCreateAccountPacketStrc;

struct D2BnChangePasswordPacketStrc;

struct D2BnReportVersionPacketStrc;

struct D2BnJoinChannelPacketStrc;

struct D2BnStartAdvexPacketStrc;

struct D2BnNotifyJoinPacketStrc;

struct D2BnReadUserDataPacketStrc;

struct D2BnHashInputStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char abDigest[20];
};

struct D2BnLogonResponsePacketStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char abProof[20];
    char szName[0x100];
};

struct D2BnCreateAccountPacketStrc
{
    unsigned char f_0[20];
    char szName[0x100];
};

struct D2BnChangePasswordPacketStrc
{
    unsigned int f_0;
    unsigned int f_4;
    unsigned char abOldProof[20];
    unsigned char abNewHash[20];
    char szName[0x100];
};

struct D2BnReportVersionPacketStrc
{
    unsigned int dwPlatform;
    unsigned int dwProduct;
    unsigned int dwVersion;
    unsigned int f_C;
    unsigned int f_10;
    char f_14[0x100];
};

struct D2BnJoinChannelPacketStrc
{
    unsigned int dwFlags;
    char szChannel[0x100];
};

struct D2BnStartAdvexPacketStrc
{
    unsigned int dwState;
    unsigned int dwUptime;
    unsigned int dwGameType;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    char aData[0x100];
};

struct D2BnNotifyJoinPacketStrc
{
    unsigned int dwProduct;
    unsigned int dwVersion;
    char aData[0x200];
};

struct D2BnReadUserDataPacketStrc
{
    unsigned int nAccounts;
    unsigned int nKeys;
    unsigned int nCookie;
    char aData[4];
};

extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

extern "C" unsigned short __stdcall ntohs(unsigned short nValue);                                           // 0x006B019E

static void* gpReadUserDataReply;                                                                                    // 0x008818D8

class BNGatewayAccess
{
public:
    const char* __stdcall DNS(int nGateway);                                                                 // 0x00518040
    void __stdcall Load();                                                                                   // 0x005186D0
    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
};

struct D2BnAuthInfoPacketStrc
{
    unsigned int nProtocol;
    unsigned int nPlatform;
    unsigned int f_8;
    unsigned int nVersion;
    unsigned int f_10;
    unsigned int f_14;
    int f_18;
    unsigned int nLcid;
    unsigned int nLangId;
    unsigned int nCountryAbbrev;
    char szCountry[0x100];
};

struct D2BnLogonPacketStrc
{
    unsigned char abPublic[0x20];
    char szName[0x100];
};

struct D2BnAuthAccountCreatePacketStrc
{
    unsigned char abSalt[0x20];
    unsigned char abVerifier[0x20];
    char szName[0x100];
};

struct D2BnUpgradeInputStrc
{
    unsigned int nTick;
    unsigned int f_4;
    unsigned char abDigest[0x14];
};

struct D2BnUpgradePacketStrc
{
    unsigned int nTick;
    unsigned char abProof[0x14];
    unsigned char abVerifier[0x40];
};

extern "C" __declspec(dllimport) unsigned short __stdcall GetSystemDefaultLangID(void);                    // 0x006CC354

char* __stdcall SStrUpper(char* szString);                                                      // 0x004141E0

int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50

int __fastcall sub_0051C9E0_GetSockName(void* pAddress, int* pnLength); // 0x0051C9E0

int __fastcall BNSEND_DecodeCDKey16(int* pProduct, int* pValue1, const char* szKey, int* pValue2);   // 0x0051DDD0

void __cdecl GRID_LockCDKeys();                                                                     // 0x005234D0

void __cdecl GRID_UnlockCDKeys();                                                                   // 0x005239C0

void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField);                                                 // 0x00525260

extern "C" const char gszKernel32[];                                                               // 0x006CD6E4

extern BNGatewayAccess gtBnGatewayAccess;                                                           // 0x00881838

extern int gnLoginRetryCount;                                                                              // 0x00882538

extern char gszAccountName[0x100];                                                                 // 0x00882540

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2BnDnsArgsStrc;

class BNGatewayAccess;

struct D2BnPacketHeaderStrc;

static long BNSEND_ExchangeConnected(long nComparand, long nExchange); // 0x0051BEB0

extern "C" int __cdecl isdigit(int c); // 0x00686F0F

extern "C" D2HostentStrc* __stdcall gethostbyname(const char* szName); // 0x006B0192

extern "C" void __cdecl srand(unsigned int nSeed); // 0x00687454

extern "C" int __cdecl rand(); // 0x00687461

extern "C" const char gszSemicolon[]; // 0x006CDA54

int __fastcall BNMESSQUEUE_QueueText(int nId, const char* szText); // 0x005202F0

int __fastcall BNSEND_SendLogonResponseEx(const char* szName, const char* szPassword); // 0x0051A660

int __fastcall BNSEND_SendCreateAccountEx(const char* szName, const char* szPassword); // 0x0051A740

int __cdecl BNSEND_SendLeaveChat(); // 0x0051AF20

int __cdecl GAME_GetCreateAccountResult(); // 0x00520B10

int __cdecl GAME_GetChangePasswordResult(); // 0x00520B20

int __fastcall BNSEND_SendAccountLogon(const char* szName, const char* szPassword); // 0x00521F60

int __fastcall BNSEND_SendAccountCreate(const char* szName, const char* szPassword); // 0x00522130

struct D2BnPacketHeaderStrc
{
    unsigned char f_0;
    unsigned char nId;
    unsigned short nLength;
};

typedef int (__fastcall* D2BnPacketHandler)(const void* pData, int nSize);

int __fastcall FOG_SOCKET_Send(FSafeSock* pSafeSock, char* pBuffer, int nBufferLength); // 0x0040DCC0

extern D2BnPacketHandler gapfnPacketHandlers[]; // 0x0072FFB0

extern int ganSlotArrayA[94]; // 0x00882128

extern "C" char* __cdecl strchr(const char* s, int c); // 0x00687740

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern D2CriticalSectionStrc gtMessageLock; // 0x00882004

extern int gnBnState; // 0x0088201C

int __fastcall FOG_SOCKET_WSAStartup(); // 0x0040D890

void __fastcall BNDOWNLOAD_ResolveHost(char* szResult, const char* szHost); // 0x0051C0E0

void __fastcall BNSEND_GetServerAddress(char* szText, int nSize); // 0x0051C190

int __stdcall sFastestConnect(char* szServerList); // 0x0051CA90

int __fastcall BNMESSQUEUE_SetState(int nState); // 0x00520520

int gnClientToken; // 0x008818C4

unsigned long __stdcall BNSEND_ReceiveThread(void* pParameter); // 0x0051C7E0

int gdwGlobal_00881C04; // 0x00881C04

unsigned long gnDnsAddr; // 0x00881C08

char* gapDnsAddrList[2]; // 0x00881C0C

D2HostentStrc gtDnsHostent; // 0x00881C14

char gData_00882028[256]; // 0x00882028

char gszBnetHost[0x100]; // 0x008818E8

char gszBnetAddress[0x100]; // 0x008819E8

long volatile gnSendBusy; // 0x00881C00

#define FD_ZERO(set) (((D2FdSetStrc*)(set))->fd_count = 0)

#define FD_SET(fd, set) do { \
    if (((D2FdSetStrc*)(set))->fd_count < 64) \
        ((D2FdSetStrc*)(set))->fd_array[((D2FdSetStrc*)(set))->fd_count++] = (fd); \
} while (0)

struct D2BnCheckAdReplyStrc;

struct D2BnStateStrc;

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" int __stdcall __WSAFDIsSet(unsigned int nSocket, D2FdSetStrc* pSet); // 0x006B0180

extern "C" int __stdcall select(int nCount, D2FdSetStrc* pRead, D2FdSetStrc* pWrite, D2FdSetStrc* pExcept, const D2TimevalStrc* pTimeout); // 0x006B0186

FSafeSock* __fastcall FOG_SOCKET_ConnectEx(char* szHostAddress, int nPortNumber, unsigned long (__stdcall* pThreadProc)(void* pParam), void* lpParameter, const char* szName, int bNonBlocking); // 0x0040D8E0

int __fastcall FOG_SOCKET_SetBlockingMode(FSafeSock* pSafeSock, int bNonBlocking); // 0x0040E1A0

int __fastcall BNMESSQUEUE_GetState(D2BnStateStrc* pState); // 0x005205F0

int __stdcall BNSEND_SendAuthInfo(); // 0x00521BF0

int __cdecl sub_00521DC0_SendAuthCheck();

// build: symbol ?CUNIT_MarkUnitDead@* 0x00464810
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x10000;
    }
}

// build: symbol ?CUNIT_IsDeadOrDying@* 0x00464820
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit)
{
    if (pUnit->dwFlags & 0x10000)
    {
        return 1;
    }

    const int nMode = pUnit->dwAnimMode;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (nMode == 0 || nMode == 0x11)
        {
            return 1;
        }
        break;

    case UNIT_MONSTER:
        if (nMode == 0 || nMode == 0x0C)
        {
            return 1;
        }
        break;
    }

    return 0;
}

// build: symbol ?CUNIT_FreeLight@* 0x00464930
void __fastcall CUNIT_FreeLight(D2UnitStrc* pUnit)
{
    if (pUnit->pLight)
    {
        DLIGHTMAP_ReleaseLight(pUnit->pLight);
        pUnit->pLight = 0;
    }
}

// build: symbol ?CUNIT_DispatchMouseWheel@* 0x004693B0
void __fastcall CUNIT_DispatchMouseWheel(int nSteps)
{
    if (nSteps > 0)
    {
        if (gpfnWheelUp)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelUp), 0x383);
            gpfnWheelUp();
        }
    }
    else if (nSteps < 0)
    {
        if (gpfnWheelDown)
        {
            D2_ASSERT(!IsBadCodePtr((D2FarProcFn)gpfnWheelDown), 0x38B);
            gpfnWheelDown();
        }
    }
}

// build: symbol ?CUNIT_GetHotkeyBinding@* 0x00469AA0
unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (gtHotkeys_007A6F90[i].nCommand == nA && gtHotkeys_007A6F90[i].nMode == nB)
        {
            return gtHotkeys_007A6F90[i].nKey;
        }
    }

    return 0xFFFF;
}

// build: symbol ?CUNIT_ClearHotkeyBinding@* 0x00469D70
void __fastcall CUNIT_ClearHotkeyBinding(int nId, int nB)
{
    for (int i = 0; i < NUM_HOTKEYS; ++i)
    {
        if (nId == gtHotkeys_007A6F90[i].nCommand && nB == gtHotkeys_007A6F90[i].nMode)
        {
            gtHotkeys_007A6F90[i].nKey = 0xFFFF;
        }
    }
}

// build: symbol ?CUNIT_HasHotkeyBinding@* 0x00469D90
int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB)
{
    return CUNIT_GetHotkeyBinding(nA, nB) != 0xFFFF;
}

// build: symbol ?CUNIT_ClearAiTargets@* 0x0046D750
void __cdecl CUNIT_ClearAiTargets()
{
    for (int i = 0; i < 8; ++i)
    {
        gapAiTargets[i] = 0;
    }
}

// build: symbol ?DATATBLS_GetSetsTxtRecord@* 0x00483410
D2SetsTxt* __fastcall DATATBLS_GetSetsTxtRecord(int nSetId)
{
    if (nSetId >= 0 && nSetId < sgptDataTables->nSetsTxtRecordCount)
    {
        return &sgptDataTables->pSetsTxt[nSetId];
    }

    return 0;
}

// build: symbol ?DATATBLS_GetSetItemsTxtRecord@* 0x00483440
D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nIndex];
    }

    return 0;
}

// build: symbol ?DATATBLS_GetUniqueItemsTxtRecord@* 0x00483470
D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex)
{
    if (nIndex >= 0 && nIndex < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nIndex];
    }

    return 0;
}

// build: symbol ?INV_InitColorTable@* 0x00483960
void __cdecl INV_InitColorTable()
{
    gabColors_007BCAD8[0] = PALETTE_FindPaletteIndex(0x80, 0, 0);
    gabColors_007BCAD8[1] = PALETTE_FindPaletteIndex(0, 0x80, 0);
    gabColors_007BCAD8[2] = PALETTE_FindPaletteIndex(0, 0, 0x80);
    gabColors_007BCAD8[3] = PALETTE_FindPaletteIndex(0x80, 0x80, 0);
    gabColors_007BCAD8[4] = PALETTE_FindPaletteIndex(0x80, 0x40, 0x40);
}

// build: symbol ?INV_IsInvPanelTradeMode@* 0x00489840
int __cdecl INV_IsInvPanelTradeMode()
{
    if (gnInvPanelMode == 1 || gnInvPanelMode == 2 || gnInvPanelMode == 3)
    {
        return 1;
    }

    return 0;
}

void __fastcall sub_004898A0(int nMode)
{
    gbGoldButtonDisabled = 1;
    if (gnInvPanelMode == 13)
    {
        gnInvPanelMode = 12;
    }

    UI_SetUIVar(5, 1, 0);
}

// build: symbol ?CUNIT_SetDialogState@* 0x004898D0
void __fastcall CUNIT_SetDialogState(int nState)
{
    gnDialogState = nState;
    if (nState == 0)
    {
        gnHoverTopX = -1;
        gnHoverTopY = -1;
        gnHoverBottomX = -1;
        gnHoverBottomY = -1;
        gnHoverCellX = -1;
        gnHoverCellY = -1;
        gbHoverInGrid = 0;
        gbHoverInBodyLoc = 0;
        gpHoverItem = 0;
        gpLastHoverItem = 0;
    }
}

// build: symbol ?TEXT_ClearTextPanel@* 0x004A1730
void __cdecl TEXT_ClearTextPanel()
{
    TEXT_ResetTextBox();
    gbTextPanelOpen = 0;
    if (gpTextHeader)
    {
        TEXT_FreeTextHeader(gpTextHeader);
        gpTextHeader = 0;
    }
}

// build: symbol ?CUNIT_IsTrading@* 0x004B8A10
int __cdecl CUNIT_IsTrading()
{
    if (gnTradeState == 1 || gnTradeState == 2)
    {
        return 1;
    }

    return 0;
}

// build: symbol ?DDDEBUGFONT_FreeDebugFont@* 0x005125B0
void __cdecl DDDEBUGFONT_FreeDebugFont()
{
    if (gpDDrawDebugFontGlyphs)
    {
        FOG_Free(gpDDrawDebugFontGlyphs, ".\\Src\\ddDebugFont.cpp", 0x5D, 0);
        gpDDrawDebugFontGlyphs = 0;
    }
}

// 0x0051A490
int __cdecl BNSEND_SendClientId()
{
    D2BnRegistrationPacketStrc tPacket;
// build: symbol ?gszConfiguration@* 0x006DEC7C
    SRegLoadValue(gszConfiguration, "Registration Version", 2, &tPacket.nRegistrationVersion);
    SRegLoadValue(gszConfiguration, "Registration Authority", 2, &tPacket.nRegistrationAuthority);
    SRegLoadValue(gszConfiguration, "Client ID", 2, &tPacket.nClientId);
    SRegLoadValue(gszConfiguration, "Client Token", 2, &tPacket.f_10);
    tPacket.nLead = 1;
    tPacket.szText[1] = tPacket.szText[0] = 0;
    BNSEND_SendPacket(0x1E, &tPacket, 0x16);
    return 1;
}

// 0x0051A580
int __fastcall BNSEND_SendLogonResponse(const char* szName, const char* szPassword)
{
    D2BnLogonResponsePacketStrc tPacket;
    D2BnHashInputStrc tInput;
    char szLower[0x100];
    sub_00520C00_ClearReply(0x29);
    SStrCopy(szLower, szPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tInput.f_0 = GetTickCount();
    tInput.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tInput.abDigest, szLower, nLength);
    tPacket.f_0 = tInput.f_0;
    tPacket.f_4 = tInput.f_4;
    sub_005209D0_HashData(tPacket.abProof, &tInput, sizeof(tInput));
    BNSEND_SendPacket(0x29, &tPacket, SStrCopy(tPacket.szName, szName, 0x100) + 0x1D);
    return 1;
}

// 0x0051A660
int __fastcall BNSEND_SendLogonResponseEx(const char* szName, const char* szPassword)
{
    D2BnLogonResponsePacketStrc tPacket;
    D2BnHashInputStrc tInput;
    char szLower[0x100];
    sub_00520C00_ClearReply(0x3A);
    SStrCopy(szLower, szPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tInput.f_0 = GetTickCount();
    tInput.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tInput.abDigest, szLower, nLength);
    tPacket.f_0 = tInput.f_0;
    tPacket.f_4 = tInput.f_4;
    sub_005209D0_HashData(tPacket.abProof, &tInput, sizeof(tInput));
    BNSEND_SendPacket(0x3A, &tPacket, SStrCopy(tPacket.szName, szName, 0x100) + 0x1D);
    return 1;
}

// 0x0051A740
int __fastcall BNSEND_SendCreateAccountEx(const char* szName, const char* szPassword)
{
    D2BnCreateAccountPacketStrc tPacket;
    char szLower[0x100];
    SStrCopy(szLower, szPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    sub_005209D0_HashData(tPacket.f_0, szLower, nLength);
    BNSEND_SendPacket(0x3D, &tPacket, SStrCopy(tPacket.szName, szName, 0x100) + 0x15);
    return 1;
}

// 0x0051A7D0
int __fastcall BNSEND_SendChangePasswordLegacy(const char* szAccountName, const char* szOldPassword, const char* szNewPassword)
{
    D2BnChangePasswordPacketStrc tPacket;
    D2BnHashInputStrc tInput;
    char szLower[0x100];
    SStrCopy(szLower, szOldPassword, 0x100);
    unsigned int nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tInput.f_0 = GetTickCount();
    tInput.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tInput.abDigest, szLower, nLength);
    SStrCopy(szLower, szNewPassword, 0x100);
    nLength = SStrLen(szLower);
    CharLowerBuffA(szLower, nLength);
    tPacket.f_0 = tInput.f_0;
    tPacket.f_4 = tInput.f_4;
    sub_005209D0_HashData(tPacket.abOldProof, &tInput, sizeof(tInput));
    sub_005209D0_HashData(tPacket.abNewHash, szLower, nLength);
    BNSEND_SendPacket(0x31, &tPacket, SStrCopy(tPacket.szName, szAccountName, 0x100) + 0x31);
    return 1;
}

// 0x0051A8F0
int __fastcall BNSEND_SendReportVersion(unsigned int dwExeVersion, unsigned int dwExeHash, const char* szExeInfo)
{
    D2BnReportVersionPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = 0xE;
    tPacket.f_C = dwExeVersion;
    tPacket.f_10 = dwExeHash;
    SStrCopy(tPacket.f_14, szExeInfo, 0x100);
    return BNSEND_SendPacket(7, &tPacket, strlen(tPacket.f_14) + 0x15) >= 0;
}

// 0x0051A9C0
int __cdecl BNSEND_SendStartVersioning()
{
    sub_00520C00_ClearReply(7);
    BNDOWNLOAD_SetArchiveName(&gszEmptyAssertText);
    D2BnLogonRequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.dwPlatform = 0x49583836;
    tRequest.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tRequest.dwVersion = 0x0E;
    sub_00520C00_ClearReply(6);
    if (BNSEND_SendPacket(6, &tRequest, sizeof(tRequest)) < 0)
        return 0;
    while (!BNDOWNLOAD_HasArchiveName())
    {
// build: symbol ?BNDOWNLOAD_IsReplyReceived@* 0x00520BF0
        if (BNDOWNLOAD_IsReplyReceived(7))
            break;
// build: symbol ?GAME_GetAbortFlag@* 0x00520AE0
        if (GAME_GetAbortFlag())
            return 0;
        Sleep(10);
    }
    BNDOWNLOAD_SetStatus(0x66);
    if (BNDOWNLOAD_IsReplyReceived(7))
        return 0;
    char szText[0x100] = { 0 };
    int nArg2;
    int nArg1;
    if (!BNDOWNLOAD_RunCheckRevision(&nArg1, &nArg2, szText))
    {
        BNMESSQUEUE_SetError(1);
        return 0;
    }
    sub_0051E370_SetText(szEmpty_006DEF80, 2);
    BNSEND_SendReportVersion(nArg1, nArg2, szText);
// build: symbol ?BNDOWNLOAD_WaitForReply@* 0x00520B70
    BNDOWNLOAD_WaitForReply(7);
    return 0;
}

// 0x0051AB30
void __fastcall BNSEND_SetAdUrlReply(const void* pData, unsigned int nSize)
{
    if (gpAdUrlReply)
        SMemFree(gpAdUrlReply, ".\\BnSend.cpp", 0x188, 0);
    gpAdUrlReply = (char*)SMemAlloc(nSize, ".\\BnSend.cpp", 0x189, 0);
    memcpy(gpAdUrlReply, pData, nSize);
}

// 0x0051AB80
void __cdecl BNSEND_FreeRealmList()
{
    if (gpReply40)
    {
        FOG_Free(gpReply40, ".\\BnSend.cpp", 410, 0);
    }
    gpReply40 = 0;
}

// 0x0051ABB0
char* __fastcall BNSEND_QueryAdUrl(int nAdId)
{
    sub_00520C00_ClearReply(0x41);
    if (BNSEND_SendPacket(0x41, &nAdId, 4) < 0)
    {
        return 0;
    }

    BNDOWNLOAD_WaitForReply(0x41);
    if (!gpAdUrlReply)
    {
        return 0;
    }

    return gpAdUrlReply + 4;
}

// 0x0051ABF0
void* __cdecl BNSEND_QueryRealms()
{
    sub_00520C00_ClearReply(0x40);
    if (BNSEND_SendPacket(0x40, 0, 0) < 0)
    {
        return 0;
    }
    BNDOWNLOAD_WaitForReply(0x40);
    return gpReply40;
}

// 0x0051AC20
void __cdecl BNSEND_FreeChannelList()
{
    if (gpChannelList)
    {
        FOG_Free((void*)gpChannelList, ".\\BnSend.cpp", 0x1EF, 0);
    }
    gpChannelList = 0;
}

// 0x0051AC50
int __fastcall BNSEND_GetChannelList(int bNoExpansion)
{
    unsigned int nFlags = 0;
    if (sub_0051BEC0_IsExpansion() && !bNoExpansion)
    {
        nFlags |= 1;
    }

    sub_00520C00_ClearReply(0x0B);
    BNSEND_SendPacket(0x0B, &nFlags, 4);
    BNDOWNLOAD_WaitForReply(0x0B);
    return (int)gpChannelList;
}

// 0x0051ACA0
int __fastcall BNSEND_JoinChannel(const char* szChannel, int bFlag, int bNoExpansion)
{
    D2BnJoinChannelPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    if (szChannel && *szChannel)
    {
        tPacket.dwFlags = bFlag ? 2 : 0;
        SStrCopy(tPacket.szChannel, szChannel, 0x100);
    }
    else
    {
        tPacket.dwFlags = 1;
        if (sub_0051BEC0_IsExpansion() && !bNoExpansion)
            tPacket.dwFlags |= 4;
        SStrCopy(tPacket.szChannel, "Diablo II", 0x100);
    }
    BNSEND_SendPacket(0xC, &tPacket, strlen(tPacket.szChannel) + 5);
    return 1;
}

// 0x0051AD70
int __fastcall BNSEND_EscapeBytes(unsigned char* data, unsigned int length)
{
 if(length>0) {
 unsigned int i=0;
 do {
  if(i==255)return 0;
  if(data[0]==0) {
   SMemCopy(data+2,data+1,256);
   ++length;
   data[1]=1;
   data[0]=255;
   ++data;
   ++i;
  } else if(data[0]==255) {
   SMemCopy(data+2,data+1,256);
   ++length;
   data[1]=255;
   data[0]=255;
   ++data;
   ++i;
  }
 ++i;
 ++data;
 } while(i<length);
 }
 return 1;
}

// 0x0051AE10
int __fastcall BNSEND_SendEnterChat(const char* szArg1, const char* szArg2, int nArg3)
{
    int nProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    BNSEND_SendPacket(0x0B, &nProduct, 4);

    char szBuffer[0x200] = { 0 };
    SStrCopy(szBuffer, szArg1, 0x100);
    SStrCopy(&szBuffer[strlen(szBuffer) + 1], szArg2, 0x100);
    return BNSEND_SendPacket(0x0A, szBuffer, strlen(szBuffer) + strlen(&szBuffer[strlen(szBuffer) + 1]) + 2) >= 0;
}

// 0x0051AF20
int __cdecl BNSEND_SendLeaveChat()
{
    return BNSEND_SendPacket(0x10, 0, 0) >= 0;
}

// 0x0051AF40
int __fastcall BNSEND_ChatCommand(const char* szText)
{
    if (!szText || !strlen(szText))
    {
        return 0;
    }

    unsigned short wszText[0x200];
    unsigned int nLength = SUniConvertWinToUTF16(wszText, szText, 0x1FF);
    if (!nLength)
    {
        return 0;
    }

    wszText[nLength] = 0;

    char szBuffer[0x200];
    if (SUniConvertUTF16to8(szBuffer, 0x1FF, wszText, 0x1FF, &nLength, 0))
    {
        return 0;
    }

    szBuffer[nLength] = 0;
    return BNSEND_SendPacket(0x0E, szBuffer, nLength) >= 0;
}

// 0x0051B010
int __cdecl BNSEND_CheckAd()
{
    D2BnCheckAdPacketStrc tPacket;
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = gnVersion;
    tPacket.nTime = _time32(0);
    BNSEND_SendPacket(0x15, &tPacket, sizeof(tPacket));
    return 1;
}

// 0x0051B060
int __cdecl BNSEND_SendDisplayAd()
{
    D2BnVersionPacketStrc tPacket;
    tPacket.dwPlatform = 0x49583836;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = gnVersion;
    tPacket.szText[1] = tPacket.szText[0] = 0;
    BNSEND_SendPacket(0x21, &tPacket, 0x0E);
    return 1;
}

// 0x0051B0E0
int __fastcall BNSEND_SendStartAdvex(const char* szGameName, const char* szPassword, const char* szStatstring, int nGameType)
{
    D2BnStartAdvexPacketStrc tPacket;
    tPacket.dwState = 0;
    tPacket.dwUptime = 0;
    tPacket.dwGameType = nGameType;
    tPacket.dwUnknown0C = 0;
    tPacket.f_10 = 0;
    if (!szGameName)
        szGameName = &gszEmptyAssertText;
    if (!szPassword)
        szPassword = &gszEmptyAssertText;
    if (!szStatstring)
        szStatstring = &gszEmptyAssertText;
    if (*szPassword)
        tPacket.dwState = 1;
    char* pText = tPacket.aData;
    pText += SStrCopy(pText, szGameName, 0x100) + 1;
    pText += SStrCopy(pText, szPassword, 0x100) + 1;
    unsigned int nLength = SStrCopy(pText, szStatstring, 0x100);
    nLength += (pText - tPacket.aData) + 0x15;
    BNSEND_SendPacket(0x1C, &tPacket, nLength);
    return 1;
}

// 0x0051B1B0
int __cdecl BNSEND_SendStopAdv()
{
    BNSEND_SendPacket(2, 0, 0);
    return 1;
}

// 0x0051B1D0
int __cdecl BNSEND_LeaveGame()
{
    IGNORELIST_GetOrCreateIgnoreList()->IGNORELIST_ClearAccountAliases();
    BNSEND_SendPacket(0x1F, 0, 0);
    return 1;
}

// 0x0051B1F0
int __fastcall BNSEND_GetStartAdvResult(int* pValue)
{
    *pValue = BNDOWNLOAD_GetReplyValue(0x1C);
    return BNDOWNLOAD_IsReplyReceived(0x1C);
}

// 0x0051B210
void __cdecl BNSEND_FreeGamesList()
{
    if (gpReply_008818D0)
    {
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    }

    gpReply_008818D0 = 0;
}

// 0x0051B240
void* __fastcall BNSEND_GetGamesList(const char* szGameName, const char* szGamePassword, int a3, int a4)
{
    D2BnGamesListPacketStrc tPacket;
    tPacket.unk0x00 = 0;
    tPacket.unk0x04 = 0;
    tPacket.unk0x08 = 0;
    tPacket.nCount = 0x19;

    char* pText = tPacket.szText;
    if (szGameName)
    {
        pText += SStrCopy(pText, szGameName, 0x100) + 1;
    }
    else
    {
        pText += SStrCopy(pText, &gszEmptyAssertText, 0x100) + 1;
    }

    if (szGamePassword)
    {
        pText += SStrCopy(pText, szGamePassword, 0x100) + 1;
    }
    else
    {
        pText += SStrCopy(pText, &gszEmptyAssertText, 0x100) + 1;
    }

    const int nLength = SStrCopy(pText, &gszEmptyAssertText, 0x100);
    const int nSize = (int)(pText - tPacket.szText) + nLength + 1 + 0x10;

    sub_00520C00_ClearReply(9);
    BNSEND_SendPacket(9, &tPacket, nSize);
    BNDOWNLOAD_WaitForReply(9);
    return gpReply_008818D0;
}

// 0x0051B320
int __fastcall BNSEND_SendNotifyJoin(const char* szGameName, const char* szPassword)
{
    D2BnNotifyJoinPacketStrc tPacket;
    tPacket.dwProduct = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.dwVersion = 0xE;
    char* pText = tPacket.aData;
    pText += SStrCopy(pText, szGameName, 0x100) + 1;
    unsigned int nLength = SStrCopy(pText, szPassword, 0x100);
    nLength += (pText - tPacket.aData) + 9;
    BNSEND_SendPacket(0x22, &tPacket, nLength);
    return 1;
}

// 0x0051B3B0
void __cdecl BNSEND_FreeRealmLogonReply()
{
    if (gpSizedReply)
    {
        FOG_Free(gpSizedReply, ".\\BnSend.cpp", 0x3B2, 0);
    }
    gpSizedReply = 0;
}

// 0x0051B3E0
void __fastcall BNSEND_SetRealmLogonReply(const void* pData, unsigned int nSize)
{
    if (gpSizedReply)
        FOG_Free(gpSizedReply, ".\\BnSend.cpp", 0x3B2, 0);
    gpSizedReply = 0;
    gpSizedReply = (D2BnSizedReplyStrc*)FOG_Alloc(nSize + 4, ".\\BnSend.cpp", 0x3BB, 0);
    gpSizedReply->nSize = nSize;
    memcpy(gpSizedReply->abData, pData, nSize);
    if (nSize != 8 && nSize >= 0x48)
    {
        unsigned int* pValue = &gpSizedReply->nValue;
        *pValue = ntohs(*pValue);
    }
}

// 0x0051B460
D2BnSizedReplyStrc* __fastcall BNSEND_LogonRealm(const char* szRealmName, const char* szRealmPassword)
{
    if (!szRealmName)
    {
        return 0;
    }

    D2BnAuthHashStrc tHash;
    gnClientToken += 1;
    tHash.f_0 = gnClientToken;
    tHash.f_4 = gdwGlobal_008818BC;
    sub_005209D0_HashData(tHash.abPasswordHash, szRealmPassword, strlen(szRealmPassword));

    D2BnLogonRealmPacketStrc tPacket;
    tPacket.f_0 = gnClientToken;
    sub_005209D0_HashData(tPacket.abProof, &tHash, 0x1C);
    const int nLength = SStrCopy(tPacket.szRealmName, szRealmName, 0x100) + 1;

    sub_00520C00_ClearReply(0x3E);
    if (BNSEND_SendPacket(0x3E, &tPacket, nLength + 0x18) < 0)
    {
        return 0;
    }

    BNDOWNLOAD_WaitForReply(0x3E);
    return gpSizedReply;
}

// 0x0051B540
void __cdecl BNSEND_SendLocaleInfo()
{
    D2TimeZoneInformationStrc tTimeZone;
    memset(&tTimeZone, 0, sizeof(tTimeZone));
    GetTimeZoneInformation(&tTimeZone);
    D2SystemTimeStrc tSystemTime;
    GetSystemTime(&tSystemTime);
    D2SystemTimeStrc tLocalTime;
    GetLocalTime(&tLocalTime);
    D2BnLocalePacketStrc tPacket;
    SystemTimeToFileTime(&tSystemTime, &tPacket.tSystemTime);
    SystemTimeToFileTime(&tLocalTime, &tPacket.tLocalTime);
    tPacket.f_10 = tTimeZone.f_0;
    tPacket.nSystemLcid = GetSystemDefaultLCID();
    tPacket.nUserLcid = GetUserDefaultLCID();
    tPacket.nUserLangId = GetUserDefaultLangID();
    tPacket.szText[0] = 0;
    GetLocaleInfoA(0x400, 3, tPacket.szText, 0x40);
    char* p = tPacket.szText + strlen(tPacket.szText) + 1;
    GetLocaleInfoA(0x400, 5, p, 0x40);
    p += strlen(p) + 1;
    GetLocaleInfoA(0x400, 7, p, 0x40);
    p += strlen(p) + 1;
    GetLocaleInfoA(0x400, 0x1002, p, 0x40);
    p += strlen(p) + 1;
    BNSEND_SendPacket(0x12, &tPacket, p - tPacket.szText + 0x20);
}

// 0x0051B6C0
int __fastcall BNSEND_SendAdClick(int nAdId, int bFlag)
{
    D2BnAdClickStrc tRecord;
    tRecord.nAdId = nAdId;
    tRecord.bFlag = bFlag != 0;
    BNSEND_SendPacket(0x16, &tRecord, sizeof(tRecord));
    return 1;
}

// 0x0051B6F0
int __fastcall BNSEND_SendWriteUserData(const char* szName, unsigned int nCount, const char** ppKeys, const char** ppValues)
{
    unsigned int nSize = SStrLen(szName) + 1;
    for (unsigned int i = 0; i < nCount; ++i)
    {
        nSize += SStrLen(ppKeys[i]) + 1;
        nSize += SStrLen(ppValues[i]) + 1;
    }

    D2BnKeyValuePacketStrc* pPacket = (D2BnKeyValuePacketStrc*)FOG_Alloc(nSize + 8, ".\\BnSend.cpp", 0x4C4, 0);
    pPacket->nType = 1;
    pPacket->nCount = nCount;

    char* pText = pPacket->szText;
    pText += SStrCopy(pText, szName, 0x7FFFFFFF) + 1;

    unsigned int i;
    for (i = 0; i < nCount; ++i)
    {
        pText += SStrCopy(pText, ppKeys[i], 0x7FFFFFFF) + 1;
    }

    for (i = 0; i < nCount; ++i)
    {
        pText += SStrCopy(pText, ppValues[i], 0x7FFFFFFF) + 1;
    }

    sub_00520C00_ClearReply(0x27);
    int bResult = BNSEND_SendPacket(0x27, pPacket, (unsigned int)(pText - (char*)pPacket)) >= 0;
    FOG_Free(pPacket, ".\\BnSend.cpp", 0x4E0, 0);
    return bResult;
}

// 0x0051B820
void __fastcall BNSEND_SetReadUserDataReply(const void* pData, unsigned int nSize)
{
    if (gpReadUserDataReply)
        FOG_Free(gpReadUserDataReply, ".\\BnSend.cpp", 0x4EC, 0);
    gpReadUserDataReply = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x4ED, 0);
    memcpy(gpReadUserDataReply, pData, nSize);
}

// 0x0051B870
int __fastcall BNSEND_SendReadUserData(const char* szAccount, unsigned int nKeys, unsigned int nCookie, const char* const* ppKeys)
{
    unsigned int nSize = SStrLen(szAccount) + 1;
    for (unsigned int i = 0; i < nKeys; ++i)
        nSize += SStrLen(ppKeys[i]) + 1;

    D2BnReadUserDataPacketStrc* pPacket = (D2BnReadUserDataPacketStrc*)FOG_Alloc(nSize + 0xC, ".\\BnSend.cpp", 0x506, 0);
    pPacket->nAccounts = 1;
    pPacket->nKeys = nKeys;
    pPacket->nCookie = nCookie;
    char* pText = pPacket->aData;
    pText += SStrCopy(pText, szAccount, 0x7FFFFFFF) + 1;
    for (unsigned int i = 0; i < nKeys; ++i)
        pText += SStrCopy(pText, ppKeys[i], 0x7FFFFFFF) + 1;

    sub_00520C00_ClearReply(0x26);
    int bResult = BNSEND_SendPacket(0x26, pPacket, pText - (char*)pPacket) >= 0;
    FOG_Free(pPacket, ".\\BnSend.cpp", 0x521, 0);
    return bResult != 0;
}

// 0x0051B960
int __fastcall BNSEND_GetReadUserDataReply(unsigned int nKeys, unsigned int nCookie, char** ppValues, const unsigned int* pSizes)
{
    if (!BNDOWNLOAD_IsReplyReceived(0x26))
        return 0;

    D2BnReadUserDataReplyStrc* pReply = (D2BnReadUserDataReplyStrc*)gpReadUserDataReply;
    if (!pReply || pReply->nAccounts != 1 || pReply->nKeys != nKeys || pReply->nCookie != nCookie)
        return 0;

    const char* pText = pReply->aData;
    for (unsigned int i = 0; i < nKeys; ++i)
    {
        if (*pText)
        {
            strncpy(ppValues[i], pText, pSizes[i]);
            const unsigned int nSize = pSizes[i];
            ppValues[i][nSize] = 0;
        }
        else
        {
            *ppValues[i] = 0;
        }
        pText += SStrLen(pText) + 1;
    }
    return 1;
}

// 0x0051BA00
int __fastcall BNSEND_SetEmail(const char* szEmail)
{
    char szBuffer[0x100];
    D2_ASSERT(szEmail, 0x55D);
    unsigned int nLength = SStrLen(szEmail);
    D2_ASSERT(nLength < 0x100, 0x565);
    memcpy(szBuffer, szEmail, nLength);
    szBuffer[nLength] = 0;
    return BNSEND_SendPacket(0x59, szBuffer, nLength + 1) >= 0;
}

// 0x0051BAA0
int __fastcall BNSEND_ResetPassword(const char* szAccountName, const char* szEmail)
{
    char szBuffer[0x200];
    D2_ASSERT(szAccountName, 0x578);
    D2_ASSERT(*szAccountName, 0x579);
    if (szEmail && *szEmail)
    {
        unsigned int nAccount = SStrLen(szAccountName) + 1;
        D2_ASSERT(nAccount <= 0x100, 0x581);
        memcpy(szBuffer, szAccountName, nAccount);
        unsigned int nEmail = SStrLen(szEmail) + 1;
        D2_ASSERT(nEmail <= 0x100, 0x588);
        memcpy(&szBuffer[nAccount], szEmail, nEmail);
        return BNSEND_SendPacket(0x5A, szBuffer, nEmail + nAccount) >= 0;
    }
    return 0;
}

// 0x0051BB90
int __fastcall BNSEND_ChangeEmail(const char* first,const char* second,const char* third)
{
 char buffer[768];
 D2_ASSERT(first,1433);
 D2_ASSERT(*first,1434);
 if(!second || !*second || !third || !*third) return 0;
 unsigned int firstSize=SStrLen(first)+1;
 D2_ASSERT(firstSize<=256,1444);
 memcpy(buffer,first,firstSize);
 char* cursor=buffer+firstSize;
 char** ppCursor=&cursor;
 unsigned int secondSize=SStrLen(second)+1;
 D2_ASSERT(secondSize<=256,1452);
 memcpy(*ppCursor,second,secondSize);
 *ppCursor+=secondSize;
 unsigned int thirdSize=SStrLen(third)+1;
 D2_ASSERT(thirdSize<=256,1460);
 memcpy(*ppCursor,third,thirdSize);
 return BNSEND_SendPacket(0x5B,buffer,thirdSize+secondSize+firstSize)>=0;
}

// 0x0051BCF0
int __cdecl BNSEND_SendCrashDump()
{
    unsigned int nSize = 0x5DC;
    char aBuffer[0x5DC];
    if (!EXCEPTIONS_ReadCrashDump(aBuffer, &nSize))
        return 0;
    return BNSEND_SendPacket(0x5D, aBuffer, nSize) >= 0;
}

// 0x0051BD60
void __fastcall BNSEND_SetRealmList(const void* pData, unsigned int nSize)
{
    if (gpReply40)
        FOG_Free(gpReply40, ".\\BnSend.cpp", 0x19A, 0);
    gpReply40 = 0;
    gpReply40 = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x16B, 0);
    memcpy(gpReply40, pData, nSize);
}

// 0x0051BDC0
void __fastcall BNSEND_SetChannelList(const void* pData, unsigned int nSize)
{
    if (gpChannelList)
        FOG_Free(gpChannelList, ".\\BnSend.cpp", 0x1EF, 0);
    gpChannelList = 0;
    gpChannelList = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x1E6, 0);
    memcpy(gpChannelList, pData, nSize);
}

// 0x0051BE20
void __fastcall BNSEND_SetGamesList(const void* pData, unsigned int nSize)
{
    if (gpReply_008818D0)
        FOG_Free(gpReply_008818D0, ".\\BnSend.cpp", 0x36A, 0);
    gpReply_008818D0 = 0;
    gpReply_008818D0 = FOG_Alloc(nSize, ".\\BnSend.cpp", 0x326, 0);
    memcpy(gpReply_008818D0, pData, nSize);
}

// 0x0051BEA0
long __cdecl BNSEND_IsConnected()
{
    return InterlockedCompareExchange(&gnConnected, 0, 0);
}

// 0x0051BEB0
static long BNSEND_ExchangeConnected(long nComparand, long nExchange)
{
    return InterlockedCompareExchange(&gnConnected, nExchange, nComparand);
}

// 0x0051BED0
void __fastcall BNSEND_SetDnsPending(int bPending)
{
    gbDnsPending = bPending;
    Sleep(10);
}

long __fastcall ExchangeConnectedContext(long nExchange, long nComparand)
{
    return BNSEND_ExchangeConnected(nComparand, nExchange);
}

// 0x0051BEE0
unsigned long __stdcall BNSEND_ResolveHostThread(void* pArguments)
{
    D2BnDnsArgsStrc* pArgs = (D2BnDnsArgsStrc*)pArguments;
    char* szOut = pArgs->szResult;
    const char* szHost = pArgs->f_4;
    D2HostentStrc* pHost;
    if (isdigit(*szHost))
    {
        const unsigned long nAddr = inet_addr(szHost);
        if (nAddr == 0xFFFFFFFF)
        {
            BNDOWNLOAD_LogPrintf("ERROR GetServersList: inet_addr failed to convert IP (%d)", WSAGetLastError());
            return 0;
        }
        gtDnsHostent.h_addr_list = gapDnsAddrList;
        gapDnsAddrList[0] = (char*)&gnDnsAddr;
        gapDnsAddrList[1] = 0;
        pHost = &gtDnsHostent;
        gnDnsAddr = nAddr;
    }
    else
    {
        pHost = gethostbyname(szHost);
        if (!pHost)
        {
            BNDOWNLOAD_LogPrintf("ERROR GetServersList: gethostbyname failed to get server list (%d)", WSAGetLastError());
            return 0;
        }
    }

    char** ppList = pHost->h_addr_list;
    int nCount = 0;
    sub_0051A480_DebugLog(&gszEmptyAssertText);
    sub_0051A480_DebugLog("Original servlist:");
    while (ppList[nCount])
    {
        sub_0051A480_DebugLog("%d --> %s", nCount, inet_ntoa(*(D2InAddrStrc*)ppList[nCount]));
        ++nCount;
    }
    sub_0051A480_DebugLog(&gszEmptyAssertText);
    sub_0051A480_DebugLog("Scrambled servlist:");

    srand(GetTickCount());
    for (int j = 0; j < nCount - 1; ++j)
    {
        const int k = rand() * (nCount - 1 - j) / 0x8000 + j;
        D2_ASSERT(j <= k, 0x1AD);
        sub_0051A480_DebugLog("%d <-> %d SWAP", j, k);
        const unsigned long nTemp = ((D2InAddrStrc*)ppList[j])->s_addr;
        ((D2InAddrStrc*)ppList[j])->s_addr = ((D2InAddrStrc*)ppList[k])->s_addr;
        ((D2InAddrStrc*)ppList[k])->s_addr = nTemp;
    }
    sub_0051A480_DebugLog(&gszEmptyAssertText);

    char* p = szOut;
    for (char** pp = pHost->h_addr_list; *pp; ++pp)
    {
        p += SStrCopy(p, inet_ntoa(*(D2InAddrStrc*)*pp), 0x7FFFFFFF);
        p += SStrCopy(p, gszSemicolon, 0x7FFFFFFF);
    }
    if (p > szOut)
        p[-1] = 0;
    return 1;
}

// 0x0051C170
int __cdecl BNSEND_RequestBnServerIni()
{
    return sub_0051E3D0_PostMessage("bnserver-D2DV.ini", 0x80000004);
}

// 0x0051C180
BNGatewayAccess* __cdecl BNSEND_GetGatewayAccess()
{
    gtBnGatewayAccess.Load();
    return &gtBnGatewayAccess;
}

// 0x0051C190
void __fastcall BNSEND_GetServerAddress(char* szText, int nSize)
{
    char szBuffer[0x100];
    *szText = 0;
    gtBnGatewayAccess.Load();
    SStrCopy(szText, gtBnGatewayAccess.DNS(gtBnGatewayAccess.m_nCurGateway), nSize);
    if (SRegLoadString("Diablo II", "BNETIP", 0, szBuffer, 0x100))
        SStrCopy(szText, szBuffer, nSize);
}

// 0x0051C210
void __fastcall BNSEND_GetDnsPending(int* pState)
{
    D2_ASSERT(pState, 0x280);
    *pState = gbDnsPending;
}

// 0x0051C240
int __fastcall BNSEND_Logon(const char* szName, const char* szPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x3A);
        BNSEND_SendLogonResponseEx(szName, szPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x54);
        return BNSEND_SendAccountLogon(szName, szPassword);
    }
    return 0;
}

// 0x0051C290
int __cdecl BNSEND_GetLogonResult()
{
    if (GAME_GetAbortFlag())
    {
        BNMESSQUEUE_SetError(0x12);
        return 0;
    }
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return BNDOWNLOAD_IsReplyReceived(0x3A);
    case 1:
        return BNDOWNLOAD_IsReplyReceived(0x54);
    }
    return 0;
}

// 0x0051C2D0
int __fastcall BNSEND_CreateAccount(const char* szName, const char* szPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x3D);
        BNSEND_SendCreateAccountEx(szName, szPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x52);
        return BNSEND_SendAccountCreate(szName, szPassword);
    }
    return 0;
}

// 0x0051C320
int __fastcall BNSEND_GetCreateAccountResult(int* pResult)
{
    *pResult = GAME_GetCreateAccountResult();
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return BNDOWNLOAD_IsReplyReceived(0x3D);
    case 1:
        return BNDOWNLOAD_IsReplyReceived(0x52);
    }
    return 0;
}

// 0x0051C350
int __fastcall BNSEND_ChangePassword(const char* szAccountName, const char* szOldPassword, const char* szNewPassword)
{
    switch (sub_0051A570_GetMode())
    {
    case 0:
        sub_00520C00_ClearReply(0x31);
        BNSEND_SendChangePasswordLegacy(szAccountName, szOldPassword, szNewPassword);
        return 1;
    case 1:
        sub_00520C00_ClearReply(0x56);
        return BNSEND_SendAccountChange(szAccountName, szOldPassword, szNewPassword);
    }
    return 0;
}

// 0x0051C3B0
int __fastcall BNSEND_GetChangePasswordResult(int* pResult)
{
    *pResult = GAME_GetChangePasswordResult();
    switch (sub_0051A570_GetMode())
    {
    case 0:
        return BNDOWNLOAD_IsReplyReceived(0x31);
    case 1:
        return BNDOWNLOAD_IsReplyReceived(0x56);
    }
    return 0;
}

extern long volatile gpSocket_00881BF0; // 0x00881BF0

extern const char gszLineEnd_006FFCB0[]; // 0x006FFCB0

// 0x0051C570
int __fastcall BNSEND_SendLine(const char* szLine)
{
    FSafeSock* pSocket = (FSafeSock*)InterlockedCompareExchange(&gpSocket_00881BF0, 0, 0);
    FOG_SOCKET_Send(pSocket, (char *)szLine, strlen(szLine));
    FOG_SOCKET_Send(pSocket, (char *)gszLineEnd_006FFCB0, 1);
    return 1;
}

// 0x0051C5C0
int __fastcall BNSEND_SendPacket(unsigned char nId, const void* pData, unsigned int nSize)
{
    D2BnPacketHeaderStrc tHeader;
    char aBuffer[0x2000];
    tHeader.f_0 = 0xFF;
    tHeader.nId = nId;
    tHeader.nLength = (unsigned short)(nSize + 4);
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    if (!pSafeSock || InterlockedCompareExchange(&gnDnsDone, 0, 0))
    {
        sub_00520AD0_SetDisconnected();
        return 0;
    }
    if (!pData)
        nSize = 0;
    unsigned int nTotal = nSize + 4;
    SMemCopy(aBuffer, &tHeader, 4);
    if (pData && nTotal < 0x2000)
        SMemCopy(aBuffer + 4, pData, nSize);
    return FOG_SOCKET_Send(pSafeSock, aBuffer, nTotal);
}

// 0x0051C6B0
int __fastcall BNSEND_QueueTextLine(const char* szText)
{
    return BNMESSQUEUE_QueueText(1, szText);
}

// 0x0051C6C0
void __fastcall BNSEND_QueueTextLines(const char* szText)
{
    char szLine[288];

    const char* pEnd = strchr(szText, '\r');
    while (pEnd)
    {
        const int nLength = D2_MIN(pEnd - szText, 287);
        memcpy(szLine, szText, nLength);
        szLine[nLength] = 0;
        BNMESSQUEUE_QueueText(1, szLine);
        szText = pEnd + 1;
        if (pEnd[1] == '\n')
            ++szText;
        pEnd = strchr(szText, '\r');
    }
}

long volatile gnReceiveThreads; // 0x00881BF4
long volatile gnDnsDone; // 0x00881BFC
long volatile gnConnected; // 0x00881BF0
int gbReady; // 0x00881BF8

// 0x0051C760
int __fastcall BNSEND_SplitPackets(unsigned char* pBuffer, int nLength)
{
    unsigned char* p = pBuffer;
    for (;;)
    {
        while (*p != 0xFF && p - pBuffer < nLength)
            ++p;
        const unsigned short nSize = *(unsigned short*)(p + 2);
        const int nLeft = pBuffer + nLength - p;
        if ((unsigned int)nLeft < 4 || nLeft < nSize)
            break;
        BNSEND_DispatchPacket(p[1], p + 4, nSize - 4);
        p += nSize;
    }
    const int nRemain = pBuffer + nLength - p;
    memcpy(pBuffer, p, nRemain);
    return nRemain;
}

// 0x0051C7E0
unsigned long __stdcall BNSEND_ReceiveThread(void* pParameter)
{
    char aBuffer[0x2000 + 1];
    int nResult = 1;
    if (InterlockedIncrement(&gnReceiveThreads) > 1)
    {
        InterlockedDecrement(&gnReceiveThreads);
        return 1;
    }
    while (!InterlockedCompareExchange(&gnDnsDone, 0, 0) && !gbReady)
        Sleep(10);
    unsigned long dwLastTick = GetTickCount();
    int nUsed = 0;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    while (pSafeSock && !pSafeSock->bStopping && !InterlockedCompareExchange(&gnDnsDone, 0, 0))
    {
        const int bReady = FOG_SOCKET_Select(pSafeSock);
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
        if (!pSafeSock || pSafeSock->bStopping || InterlockedCompareExchange(&gnDnsDone, 0, 0))
            break;
        if (bReady)
        {
            const int nReceived = FOG_SOCKET_Receive(pSafeSock, &aBuffer[nUsed], 0x2000 - nUsed);
            if (nReceived <= 0)
            {
                sub_00520AD0_SetDisconnected();
                nResult = 0;
                break;
            }
            nUsed = BNSEND_SplitPackets((unsigned char*)aBuffer, nReceived + nUsed);
        }
        const unsigned long dwTick = GetTickCount();
        if (dwTick - dwLastTick >= 180000)
        {
            BNSEND_SendPacket(0, 0, 0);
            dwLastTick = dwTick;
        }
        pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    }
    InterlockedDecrement(&gnReceiveThreads);
    return nResult;
}

// 0x0051CA20
char __cdecl BNSEND_GetGatewayLetter()
{
    return 'G';
}

// 0x0051CA80
void __fastcall BNSEND_SetEmailRequested(int nValue)
{
    gdwGlobal_00881C04 = nValue;
}

// build: symbol ?BNDOWNLOAD_IsReady@* 0x0051CA30
int __cdecl BNDOWNLOAD_IsReady()
{
    D2BnStateStrc tState;
    BNMESSQUEUE_GetState(&tState);
// build: symbol ?GAME_GetAbortFlag@* 0x00520AE0
    if (!GAME_GetAbortFlag() && tState.nState == 0 && InterlockedCompareExchange(&gnConnected, 0, 0))
        return 1;
    return 0;
}

// 0x0051CA90
int __stdcall sFastestConnect(char* szServerList)
{
    D2BnServerEntryStrc aServers[32];

    sub_0051A480_DebugLog("sFastestConnect()");
    memset(aServers, 0, sizeof(aServers));
    BNDOWNLOAD_SetStatus(0x66);
    if (!szServerList)
        return 1;

    gbReady = 0;
    gbDnsPending = 2;
    Sleep(10);
    BNDOWNLOAD_LogPrintf("searching for the fastest server");

    char* szToken = strtok(szServerList, " ,;");
    int nServers = 0;
    unsigned long dwLastTick = GetTickCount() - 5000;
    D2TimevalStrc tTimeout;
    tTimeout.tv_sec = 1;
    tTimeout.tv_usec = 0;
    int nRetries = 0;
    FSafeSock* pConnected = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    if (!pConnected)
    {
        D2BnServerEntryStrc* pEntry = aServers;
        do
        {
        if (InterlockedCompareExchange(&gnDnsDone, 0, 0))
            break;

        if (GetTickCount() - dwLastTick >= 5000)
        {
            dwLastTick = GetTickCount();
            if (szToken && *szToken && nServers < 32)
            {
                sub_0051A480_DebugLog("  Try to connect to %s", szToken);
                strcpy(pEntry->szAddress, szToken);
                pEntry->pSafeSock = FOG_SOCKET_ConnectEx(pEntry->szAddress, 6112, BNSEND_ReceiveThread, 0, "Client->BNet", 1);
                ++nServers;
                ++pEntry;
                szToken = strtok(0, " ,;");
            }
        }

        D2FdSetStrc tWrite;
        D2FdSetStrc tExcept;
        FD_ZERO(&tWrite);
        FD_ZERO(&tExcept);
        int nActive = 0;
        for (int i = 0; i < nServers; ++i)
        {
            if (aServers[i].pSafeSock)
            {
                unsigned int nSocket = aServers[i].pSafeSock->nSocket;
                FD_SET(nSocket, &tWrite);
                FD_SET(nSocket, &tExcept);
                ++nActive;
            }
        }

        if (!nActive)
        {
            if (!szToken || !*szToken)
                break;
            Sleep(10);
            continue;
        }

        int nResult = select(0x40, 0, &tWrite, &tExcept, &tTimeout);
        if (!nResult)
        {
            if (nRetries++ > 60)
                break;
        }
        else if (nResult == -1)
        {
            WSAGetLastError();
        }
        else
        {
            for (int i = 0; i < nServers; ++i)
            {
                if (aServers[i].pSafeSock && __WSAFDIsSet(aServers[i].pSafeSock->nSocket, &tExcept))
                {
                    FOG_SOCKET_Destroy(aServers[i].pSafeSock);
                    aServers[i].pSafeSock = 0;
                }
            }

            for (int i = 0; i < nServers; ++i)
            {
                if (aServers[i].pSafeSock && __WSAFDIsSet(aServers[i].pSafeSock->nSocket, &tWrite))
                {
                    if (!InterlockedCompareExchange(&gnConnected, (long)aServers[i].pSafeSock, 0))
                    {
                        pConnected = aServers[i].pSafeSock;
                        pConnected->bConnected = 1;
                        pConnected->bConnecting = 0;
                    }
                    break;
                }
            }

            if (pConnected)
                break;
        }
        } while (!(pConnected = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0)));
    }

    for (int i = 0; i < nServers; ++i)
    {
        if (aServers[i].pSafeSock && aServers[i].pSafeSock != pConnected)
        {
            FOG_SOCKET_Destroy(aServers[i].pSafeSock);
            aServers[i].pSafeSock = 0;
        }
    }

    if (!pConnected)
    {
        BNDOWNLOAD_LogPrintf("no servers found");
        return 0;
    }

    gbReady = 1;
    if (!BNDOWNLOAD_IsReady())
    {
        sub_0051A480_DebugLog("  Error, not connected.");
        return 0;
    }

    int nLength = 16;
    D2SockAddrInStrc tAddress;
    FSafeSock* pSafeSock = (FSafeSock*)InterlockedCompareExchange(&gnConnected, 0, 0);
    if (pSafeSock && FOG_SOCKET_GetPeerName(pSafeSock, &tAddress, &nLength))
        BNDOWNLOAD_LogPrintf("Connected to server %s", inet_ntoa(tAddress.sin_addr));

    gbDnsPending = 3;
    Sleep(10);
    BNDOWNLOAD_LogPrintf("accessing accounts");
    FOG_SOCKET_SetBlockingMode(pConnected, 0);
    char nByte = 1;
    if (FOG_SOCKET_Send(pConnected, &nByte, 1) <= 0)
    {
        sub_0051A480_DebugLog("  Failed send.");
        return 0;
    }

    sub_00520C00_ClearReply(0x50);
    BNSEND_SendAuthInfo();
// build: symbol ?BNDOWNLOAD_WaitForReply@* 0x00520B70
    if (!BNDOWNLOAD_WaitForReply(0x50) && !BNDOWNLOAD_IsReady())
    {
        FOG_SOCKET_Destroy(pConnected);
        InterlockedCompareExchange(&gnConnected, 0, (long)pConnected);
        return 0;
    }

    if (GAME_GetAbortFlag())
    {
        BNMESSQUEUE_SetState(0xB);
        return 1;
    }

    gbDnsPending = 4;
    Sleep(10);
    BNDOWNLOAD_LogPrintf("Checking for the latest version");
    BNDOWNLOAD_SetStatus(0x66);
    sub_00520C00_ClearReply(0x51);
    if (!sub_00521DC0_SendAuthCheck())
        return 0;
    if (!BNDOWNLOAD_WaitForReply(0x51))
        return 0;

    D2BnStateStrc tState;
    BNMESSQUEUE_GetState(&tState);
    if (!tState.nState && BNDOWNLOAD_GetReplyValue(0x51))
    {
        sub_0051E3D0_PostMessage("bnserver-D2DV.ini", 0x80000004);
        BNDOWNLOAD_LogPrintf("Connected to Battle.net");
    }
    return 1;
}

// 0x0051D0A0
unsigned long __cdecl BattleConnectFastest(void* pParameter)
{
    sub_0051A480_DebugLog("BattleConnectFastest()");
    if (InterlockedIncrement(&gnSendBusy) > 1)
    {
        InterlockedDecrement(&gnSendBusy);
        return 0;
    }

    BNDOWNLOAD_SetStatus(0x66);
    BNSEND_GetServerAddress(gszBnetHost, 0x100);
    sub_0051A480_DebugLog("   connect to: %s", gszBnetHost);
    sub_00518C70_LogIndent(2, 4);
    BNDOWNLOAD_LogPrintf("querying gateway %s", gszBnetHost);
    gszBnetAddress[0] = 0;
    if (FOG_SOCKET_WSAStartup())
        BNDOWNLOAD_ResolveHost(gszBnetAddress, gszBnetHost);

    if (!gszBnetAddress[0])
    {
        InterlockedDecrement(&gnSendBusy);
        BNMESSQUEUE_SetState(0xC);
        sub_0051A480_DebugLog("   failed to get server list");
        sub_00518C70_LogIndent(2, -4);
        return 0;
    }

    BNMESSQUEUE_SetState(0);
    sFastestConnect(gszBnetAddress);
    sub_00518C70_LogIndent(2, -4);
    if (!InterlockedCompareExchange(&gnConnected, 0, 0) && !InterlockedCompareExchange(&gnDnsDone, 0, 0))
        BNMESSQUEUE_SetState(0xC);

    InterlockedDecrement(&gnSendBusy);
    return 1;
}

// 0x0051D1C0
void* __cdecl BNSEND_OpenBNetConnection()
{
    unsigned long nThreadId;
    BNDOWNLOAD_LogPrintf("Connecting to Battle.net...");
    if (InterlockedCompareExchange(&gnConnected, 0, 0))
    {
        sub_0051A480_DebugLog("   already connected");
        return 0;
    }
    if (!sub_0051C470_CloseBNetConnection())
        return 0;
    InterlockedExchange(&gnDnsDone, 0);
    gbDnsPending = 0;
    Sleep(10);
    CACHE_LoadCache();
    BNDOWNLOAD_ResetReplies();
    sub_00521B50_ReseedLogin();
    gdwGlobal_00881C04 = 0;
    return CreateThread(0, 0, (unsigned long (__stdcall*)(void*))BattleConnectFastest, 0, 0, &nThreadId);
}

// 0x0051DBF0
int __fastcall BNSEND_LoadBNetNews(int (__fastcall* pfnMessage)(unsigned int nStamp, const char* szText), int (__cdecl* pfnRefresh)())
{
    gbNewsActive = 1;
    gpfnNewsMessage = pfnMessage;
    gpfnNewsRefresh = pfnRefresh;
    if (gtNewsItems.m_data)
        SMemFree(gtNewsItems.m_data, gszNewsItemTypeName_0072FF8C, -2, 0);
    gtNewsItems.m_alloc = 0;
    gtNewsItems.m_count = 0;
    gtNewsItems.m_data = 0;
    gnNewsNewest = 0;
    gnNewsFirstIndex = 0;
    if (BNNEWS_LoadNews())
        BNNEWS_ReportNews();
    unsigned int nStamp = gnNewsNewest;
    BNSEND_SendPacket(0x46, &nStamp, sizeof(nStamp));
    return 1;
}

#define NULL 0

extern "C" int __cdecl tolower(int nChar); // 0x0068523E

extern const char gacCDKeyMap[]; // 0x006DF238

extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

struct D2CDKeyInfoStrc
{
    unsigned int f_0;
    int f_4;
    int nValue1;
    int f_C;
    unsigned char abDigest[20];
};

struct D2CDKeyHash16Strc
{
    unsigned int f_0;
    unsigned int f_4;
    int f_8;
    int nValue1;
    int f_10;
    int nValue3;
};

struct D2CDKeyHash26Strc
{
    unsigned int f_0;
    unsigned int f_4;
    int f_8;
    int nValue1;
    unsigned char abPrivate[12];
};

struct D2AuthCheck2Strc
{
    unsigned int f_0;
    unsigned int nKeys;
    unsigned int f_8;
    D2CDKeyInfoStrc aKeys[2];
    char f_54[0x100];
};

struct D2AuthCheck1Strc
{
    unsigned int f_0;
    unsigned int nKeys;
    unsigned int f_8;
    D2CDKeyInfoStrc aKeys[1];
    char f_30[0x100];
};

int __cdecl BNCLIENT_GetServerToken(); // 0x0051A550

int __cdecl GAME_GetExeHash(); // 0x00523A00

const char* __cdecl GAME_GetExeInfo(); // 0x00523AA0

extern unsigned int gdwClientToken; // 0x00881C48

int __stdcall BNSEND_SendAuthCheck(); // 0x0051E0B0

unsigned int gdwClientToken; // 0x00881C48

// 0x0051DC70
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// 0x0051DC80
void __fastcall BNSEND_ComputeShaDigest(unsigned char* pDigest, const unsigned char* pData, unsigned int nLength)
{
    Sha1 tContext;
    tContext.Initialize();
    tContext.Append(pData, nLength);
    tContext.sub_00425F00_Final(pDigest);
}

static inline int CheckCDKeySlot(int nSlot, int* pProduct, int* pValue1, int* pValue2, char* pKeyBlock)
{
    const char* szKey = sub_00523AB0_GetCDKey(nSlot);
    unsigned int nLength = SStrLen(szKey);
    if (nLength != 0x10)
    {
        if (nLength != 0x1A)
            return 0;
        if (!szKey)
            return 0;
        sub_00522AE0_DecodeCDKey(szKey, pProduct, pValue1, pKeyBlock);
        return 1;
    }
    return BNSEND_DecodeCDKey16(pProduct, pValue1, szKey, pValue2);
}

// 0x0051DCD0
static void __stdcall BNSEND_EncodeChar(char* pChar, unsigned int* pBits, int nFlag)
{
    const char ch = (char)toupper(*pChar);
    *pChar = ch;
    if (ch <= 0x37)
    {
        *pChar = (char)((*pBits & 7) ^ ch);
        *pBits >>= 3;
    }
    else if (ch < 0x41)
    {
        *pChar = (char)((nFlag & 1) ^ ch);
    }
}

extern "C" void __stdcall sub_K08_EmitEncodeChar(char* pText, unsigned int* pBits, int nFlag)
{
    BNSEND_EncodeChar(pText, pBits, nFlag);
    BNSEND_EncodeChar(pText + 1, pBits, nFlag);
}

// 0x0051DD10
static unsigned int BNSEND_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

// 0x0051DD20
static int BNSEND_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// 0x0051DD40
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

// 0x0051DD50
static void BNSEND_DecodeKeyPairs(char* szKey, unsigned int* pValue)
{
    unsigned int nBit = 1;
    *pValue = 0;
    for (int i = 0; i < 16; i += 2, nBit <<= 1)
    {
        unsigned int nPair = gacCDKeyMap[(unsigned char)szKey[i]] * 24 + gacCDKeyMap[(unsigned char)szKey[i + 1]];
        if (nPair >= 0x100)
        {
            nPair -= 0x100;
            *pValue |= nBit;
        }

        unsigned int nHigh = (nPair >> 4) & 0xF;
        if (nHigh >= 10)
        {
            nHigh += 0x37;
        }
        else
        {
            nHigh += 0x30;
        }
        szKey[i] = nHigh;

        unsigned int nLow = nPair & 0xF;
        if (nLow >= 10)
        {
            nLow += 0x37;
        }
        else
        {
            nLow += 0x30;
        }
        szKey[i + 1] = nLow;
    }
}

// 0x0051DDD0
int __fastcall BNSEND_DecodeCDKey16(int* pProduct, int* pValue1, const char* szKey, int* pValue2)
{
    *pProduct = 0;
    *pValue1 = 0;
    *pValue2 = 0;
    if (!szKey)
    {
        return 0;
    }

    char szBuffer[0x20];
    SStrCopy(szBuffer, szKey, 0x20);

    unsigned int nValue;
    BNSEND_DecodeKeyPairs(szBuffer, &nValue);

    unsigned int nChecksum = 3;
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        const char c = tolower(szBuffer[i]);
        const int nDigit = c >= 0x61 ? c - 0x57 : c - 0x30;
        nChecksum += (nChecksum * 2) ^ nDigit;
    }

    if ((unsigned char)nChecksum != nValue)
    {
        return 0;
    }

    for (int i = 15; i >= 0; --i)
    {
        const int j = (i + 7) & 15;
        const char c = szBuffer[i];
        szBuffer[i] = szBuffer[j];
        szBuffer[j] = c;
    }

    nValue = 0x13AC9741;
    for (int i = 15; i >= 0; --i)
    {
        const char c = toupper(szBuffer[i]);
        szBuffer[i] = c;
        if (c <= 0x37)
        {
            szBuffer[i] = (nValue & 7) ^ c;
            nValue >>= 3;
        }
        else if (c < 0x41)
        {
            szBuffer[i] = (i & 1) ^ c;
        }
    }

    char szPart2[7];
    char szPart3[9];
    SStrCopy((char*)&nValue, szBuffer, 3);
    SStrCopy(szPart2, &szBuffer[2], 7);
    SStrCopy(szPart3, &szBuffer[8], 9);
    *pProduct = strtoul((char*)&nValue, NULL, 0x10);
    *pValue1 = strtoul(szPart2, NULL, 0x10);
    *pValue2 = strtoul(szPart3, NULL, 0x10);
    return 1;
}

// 0x0051DFC0
static int __stdcall BNSEND_BuildCDKeyInfo(D2CDKeyInfoStrc* pInfo, const char* szKey, unsigned int dwClientToken, unsigned int dwServerToken)
{
    D2CDKeyHash26Strc tHash26;
    int nValue1;
    D2CDKeyHash16Strc tHash16;
    switch (SStrLen(szKey))
    {
    case 0x10:
        tHash16.f_0 = dwClientToken;
        tHash16.f_4 = dwServerToken;
        if (!BNSEND_DecodeCDKey16(&tHash16.f_8, &nValue1, szKey, &tHash16.nValue3))
            return 0;

        tHash16.nValue1 = nValue1;
        tHash16.f_10 = 0;
        pInfo->f_0 = SStrLen(szKey);
        pInfo->f_4 = tHash16.f_8;
        pInfo->nValue1 = tHash16.nValue1;
        pInfo->f_C = tHash16.f_10;
        sub_005209D0_HashData(pInfo->abDigest, &tHash16, 0x18);
        return 1;

    case 0x1A:
        tHash26.f_0 = dwClientToken;
        tHash26.f_4 = dwServerToken;
        if (!szKey)
            return 0;

        sub_00522AE0_DecodeCDKey(szKey, &tHash26.f_8, &nValue1, tHash26.abPrivate);
        tHash26.nValue1 = nValue1;
        pInfo->f_0 = SStrLen(szKey);
        pInfo->f_4 = tHash26.f_8;
        pInfo->nValue1 = tHash26.nValue1;
        pInfo->f_C = 0;
        BNSEND_ComputeShaDigest(pInfo->abDigest, (const unsigned char*)&tHash26, 0x1A);
        return 1;
    }

    return 0;
}

// 0x0051E0B0
int __stdcall BNSEND_SendAuthCheck()
{
    const char* szExeInfo = GAME_GetExeInfo();
    const char* szKey0 = sub_00523AB0_GetCDKey(0);
    const char* szKey1 = sub_00523AB0_GetCDKey(1);
    const unsigned int dwExeHash = GAME_GetExeHash();
    gdwClientToken += _time32(0);
    gdwClientToken += GetTickCount();
    if (sub_0051BEC0_IsExpansion())
    {
        D2AuthCheck2Strc tPacket;
        if (!BNSEND_BuildCDKeyInfo(&tPacket.aKeys[0], szKey0, gdwClientToken, BNCLIENT_GetServerToken()))
            return 0;
        if (!BNSEND_BuildCDKeyInfo(&tPacket.aKeys[1], szKey1, gdwClientToken, BNCLIENT_GetServerToken()))
            return 0;

        tPacket.f_0 = gdwClientToken;
        tPacket.nKeys = 2;
        tPacket.f_8 = dwExeHash;
        if (BNSEND_SendPacket(0x42, &tPacket, SStrCopy(tPacket.f_54, szExeInfo, 0x100) + 0x55) < 0)
            return 0;
    }
    else
    {
        D2AuthCheck1Strc tPacket;
        tPacket.f_0 = gdwClientToken;
        tPacket.nKeys = 1;
        tPacket.f_8 = dwExeHash;
        if (!BNSEND_BuildCDKeyInfo(&tPacket.aKeys[0], szKey0, gdwClientToken, BNCLIENT_GetServerToken()))
            return 0;

        if (BNSEND_SendPacket(0x42, &tPacket, SStrCopy(tPacket.f_30, szExeInfo, 0x100) + 0x31) < 0)
            return 0;
    }

    return 1;
}

// 0x0051E240
int __cdecl BNSEND_CheckAuth()
{
    GRID_LockCDKeys();
    const int nResult = BNSEND_SendAuthCheck();
    GRID_UnlockCDKeys();
    if (!nResult)
        BNMESSQUEUE_SetState(3);
    return nResult;
}

// 0x0051E270
int __stdcall BNSEND_CheckCDKeys()
{
    int nProduct;
    int nValue1;
    int nValue2;
    char aKeyBlock[12];
    GRID_LockCDKeys();
    int bResult = CheckCDKeySlot(0, &nProduct, &nValue1, &nValue2, aKeyBlock);
    if (bResult && sub_0051BEC0_IsExpansion())
        bResult = CheckCDKeySlot(1, &nProduct, &nValue1, &nValue2, aKeyBlock);
    GRID_UnlockCDKeys();
    return bResult;
}

// 0x0051E340
int __fastcall sub_0051E340_BuildCDKeyInfoForSlot(D2CDKeyInfoStrc* pInfo, unsigned int dwClientToken, int nSlot)
{
    return BNSEND_BuildCDKeyInfo(pInfo, sub_00523AB0_GetCDKey(nSlot), dwClientToken, BNCLIENT_GetServerToken());
}

// 0x0051F2D0
int __fastcall BNSEND_GetPatchResult(int* pResult)
{
    int nState;
    BNDOWNLOAD_ApplyPatches(&nState);
    switch (nState)
    {
    case 0:
        return 1;
    case 1:
        return 1;
    case 2:
        *pResult = 1;
        break;
    }
    return 0;
}

// 0x005204D0
int __fastcall BNSEND_SetErrorText(int nError, const char* szText)
{
    EnterCriticalSection(&gtMessageLock);
    if (!gnBnState)
    {
        gnBnState = nError;
// build: symbol ?gszEmptyStateText@* 0x00881F80
        SStrCopy(gszEmptyStateText, szText, 0x80);
    }
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x00520630
int __fastcall BNSEND_SetInfoText(const char* szText)
{
    SStrCopy(gData_00882028, szText, 0x100);
    return 1;
}

// 0x00521B00
__declspec(noinline) int __fastcall BNSEND_DispatchPacket(unsigned char nId, const void* pData, int nSize)
{
    int nResult = 0;
    if (nId < 0x5E)
    {
        if (gapfnPacketHandlers[nId])
            nResult = gapfnPacketHandlers[nId](pData, nSize);
        ganSlotArrayA[nId] = 1;
    }
    return nResult;
}

static unsigned int GetUILanguageId()
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

// 0x00521BF0
int __stdcall BNSEND_SendAuthInfo()
{
    D2BnAuthInfoPacketStrc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.nProtocol = 0;
    tPacket.nPlatform = 0x49583836;
    tPacket.f_8 = sub_0051BEC0_IsExpansion() ? 0x44325850 : 0x44324456;
    tPacket.nVersion = 0xE;
    STRTABLE_GetLanguageInfoField(&tPacket.f_10, 3);

    D2SockAddrInStrc tAddress;
    int nLength = 0x10;
    tPacket.f_14 = sub_0051C9E0_GetSockName(&tAddress, &nLength) ? tAddress.sin_addr.s_addr : 0;

    D2FileTimeStrc tLocalFileTime;
    D2FileTimeStrc tSystemFileTime;
    D2SystemTimeStrc tSystemTime;
    D2SystemTimeStrc tLocalTime;
    GetSystemTime(&tSystemTime);
    GetLocalTime(&tLocalTime);
    SystemTimeToFileTime(&tSystemTime, &tSystemFileTime);
    SystemTimeToFileTime(&tLocalTime, &tLocalFileTime);
    tPacket.f_18 = (int)((*(__int64*)&tSystemFileTime - *(__int64*)&tLocalFileTime) / 600000000);
    tPacket.nLcid = GetUserDefaultLCID();
    tPacket.nLangId = GetUILanguageId();

    char szAbbrev[0x40];
    GetLocaleInfoA(0x400, 7, szAbbrev, sizeof(szAbbrev));
    szAbbrev[3] = 0;
    tPacket.nCountryAbbrev = *(unsigned int*)szAbbrev;
    GetLocaleInfoA(0x400, 0x1002, tPacket.szCountry, sizeof(tPacket.szCountry));
    BNSEND_SendPacket(0x50, &tPacket, SStrLen(tPacket.szCountry) + 0x29);
    return 1;
}

// 0x00521F60
int __fastcall BNSEND_SendAccountLogon(const char* szName, const char* szPassword)
{
    D2BnLogonPacketStrc tPacket;
    char szPasswordUpper[0x100];
    char szNameUpper[0x100];
    gnLoginRetryCount = 0;
    SStrCopy(gszAccountName, szName, 0x100);
    sub_0041D300_ZeroMemory(&gtLoginRecord, sizeof(gtLoginRecord));
    SStrCopy(szNameUpper, szName, 0x100);
    SStrUpper(szNameUpper);
    SStrCopy(szPasswordUpper, szPassword, 0x100);
    SStrUpper(szPasswordUpper);
    gtBigPair.sub_005286D0_InitLogin(&gtLoginRecord, szNameUpper, szPasswordUpper);
    sub_0041D2A0_MemCopy(tPacket.abPublic, gtLoginRecord.abPublic, sizeof(tPacket.abPublic));
    unsigned int nLength = SStrCopy(tPacket.szName, szName, 0x100);
    BNSEND_SendPacket(0x53, &tPacket, nLength + 0x21);
    return 1;
}

// 0x005220B0
int __fastcall BNSEND_SendAccountLogonProof(const unsigned char* pSalt, const unsigned char* pServerPublic)
{
    unsigned char abProof[0x14];
    const int bResult = gtBigPair.sub_00528760_ComputeLoginProof(&gtLoginRecord, pSalt, pServerPublic);
    sub_0041D300_ZeroMemory(gtLoginRecord.szPassword, sizeof(gtLoginRecord.szPassword));
    if (bResult)
    {
        sub_0041D2A0_MemCopy(abProof, gtLoginRecord.abProof, sizeof(abProof));
        BNSEND_SendPacket(0x54, abProof, sizeof(abProof));
        return 1;
    }
    return 0;
}

// 0x00522130
int __fastcall BNSEND_SendAccountCreate(const char* szName, const char* szPassword)
{
    D2BnAuthAccountCreatePacketStrc tPacket;
    char szPasswordUpper[0x100];
    char szNameUpper[0x100];
    SStrCopy(szNameUpper, szName, 0x100);
    SStrUpper(szNameUpper);
    SStrCopy(szPasswordUpper, szPassword, 0x100);
    SStrUpper(szPasswordUpper);
// build: symbol ?MakeVerifier@* 0x00528660
    gtBigPair.MakeVerifier(szNameUpper, szPasswordUpper, tPacket.abSalt, tPacket.abVerifier);
    unsigned int nLength = SStrCopy(tPacket.szName, szName, 0x7FFFFFFF);
    BNSEND_SendPacket(0x52, &tPacket, nLength + 0x41);
    return 1;
}

// 0x005221F0
int __fastcall BNSEND_SendAccountChange(const char* szAccountName, const char* szOldPassword, const char* szNewPassword)
{
    D2BnLogonPacketStrc tPacket;
    char szOldUpper[0x100];
    char szNewUpper[0x100];
    char szAccountUpper[0x100];
    gnLoginRetryCount = 0;
    sub_0041D300_ZeroMemory(&gtLoginRecord, sizeof(gtLoginRecord));
    SStrCopy(szAccountUpper, szAccountName, 0x100);
    SStrUpper(szAccountUpper);
    SStrCopy(szOldUpper, szOldPassword, 0x100);
    SStrUpper(szOldUpper);
    SStrCopy(szNewUpper, szNewPassword, 0x100);
    SStrUpper(szNewUpper);
    gtBigPair.MakeVerifier(szAccountUpper, szNewUpper, gabNewVerifier, &gabNewVerifier[0x20]);
    gtBigPair.sub_005286D0_InitLogin(&gtLoginRecord, szAccountUpper, szOldUpper);
    sub_0041D2A0_MemCopy(tPacket.abPublic, gtLoginRecord.abPublic, sizeof(tPacket.abPublic));
    unsigned int nLength = SStrCopy(tPacket.szName, szAccountName, 0x100);
    BNSEND_SendPacket(0x55, &tPacket, nLength + 0x21);
    return 0;
}

// 0x00522310
int __fastcall BNSEND_SendAccountChangeProof(const unsigned char* pSalt, const unsigned char* pServerPublic)
{
    D2BnChangeProofStrc tPacket;
    const int bResult = gtBigPair.sub_00528760_ComputeLoginProof(&gtLoginRecord, pSalt, pServerPublic);
    sub_0041D300_ZeroMemory(gtLoginRecord.szPassword, sizeof(gtLoginRecord.szPassword));
    if (bResult)
    {
        sub_0041D2A0_MemCopy(tPacket.abProof, gtLoginRecord.abProof, sizeof(tPacket.abProof));
        sub_0041D2A0_MemCopy(tPacket.abVerifier, gabNewVerifier, sizeof(tPacket.abVerifier));
        sub_0041D300_ZeroMemory(gabNewVerifier, sizeof(gabNewVerifier));
        BNSEND_SendPacket(0x56, &tPacket, sizeof(tPacket));
        return 1;
    }
    return 0;
}

// 0x005223F0
int __fastcall BNSEND_SendAccountUpgradeProof(unsigned int nServerToken)
{
    D2BnUpgradePacketStrc tPacket;
    D2BnUpgradeInputStrc tInput;
    char szPassword[0x100];
    tInput.nTick = GetTickCount();
    tInput.f_4 = nServerToken;
    CharLowerBuffA(szPassword, SStrCopy(szPassword, gtLoginRecord.szPassword, 0x100));
    sub_005209D0_HashData(tInput.abDigest, szPassword, SStrLen(szPassword));
    tPacket.nTick = tInput.nTick;
    sub_005209D0_HashData(tPacket.abProof, &tInput, sizeof(tInput));
    sub_0041D2A0_MemCopy(tPacket.abVerifier, gabNewVerifier, sizeof(tPacket.abVerifier));
    sub_0041D300_ZeroMemory(gabNewVerifier, sizeof(gabNewVerifier));
    BNSEND_SendPacket(0x58, &tPacket, sizeof(tPacket));
    return 0;
}

// 0x005224C0
int __fastcall BNSEND_CheckServerProof(const unsigned char* pServerProof)
{
    return gtBigPair.sub_00528890_CompareServerProof(&gtLoginRecord, pServerProof);
}

// 0x005224F0
void __cdecl BNSEND_ClearPassword()
{
    sub_0041D300_ZeroMemory(gtLoginRecord.szPassword, sizeof(gtLoginRecord.szPassword));
}

// 0x00528890
int D2BigPairStrc::sub_00528890_CompareServerProof(const D2BigLoginRecordStrc* pRecord, const unsigned char* pServerProof)
{
    unsigned char abProof[0x14];
    pState->sub_00528480_HashThreeBlocks(pRecord->abPublic, pRecord->abProof, pRecord->abKey, abProof);
    return memcmp(abProof, pServerProof, sizeof(abProof)) == 0;
}

#include "gen/data/Source/D2BNClient/BnSend.inc"
