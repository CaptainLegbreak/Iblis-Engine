#include "D2MCPClient.h"
#include "D2Unicode.h"
#include "D2McpPackets.h"
#include "D2LaunchRequest.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi2.h"
#include "StormApi2.h"
#include "D2NetApi.h"

typedef void (__fastcall* D2McpCallbackFn)(unsigned short wRequestId, unsigned char* pData);

typedef int (__fastcall* D2McpPacketHandler)(const unsigned char* pPacket, unsigned int nSize);



#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmdParamsStrc;

struct D2CmdArgStrc;

struct D2McpPacket02Strc;

struct D2McpPacket07Strc;

struct D2McpPacket04Strc;

struct D2McpPacket08Strc;

struct D2McpPacket09Strc;

struct D2McpPacket0BStrc;

struct D2McpPacket0CStrc;

struct D2McpPacket16Strc;

struct D2McpPacket05Strc;

struct D2LaunchRequestStrc;

struct D2McpPacket06Strc;

struct D2McpPacket0AStrc;

struct D2McpPacket18Strc;

struct D2McpPacket10Strc;

struct D2McpInfoStrc;

struct Unicode;

struct D2CmdParamsStrc
{
    char unk0x00[0x18];
    const char* szValue;
};

struct D2CmdArgStrc
{
    unsigned int dwFlags;
    unsigned int dwId;
    const char* szName;
    void* pfnHandler;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern "C" __declspec(dllimport) int __stdcall GetUserNameA(char* szBuffer, unsigned long* pSize); // 0x006CC000

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" int __cdecl tolower(int nChar); // 0x0068523E

extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);


void __fastcall GAME_CalcCdKeyChecksum(char* szKey, unsigned int* pChecksum); // 0x00449890

int __stdcall SCmdProcess(const char* szCmdLine, int bSkipProgName, int (__stdcall* pfnExtra)(const char*), int (__stdcall* pfnError)(const char*)); // 0x006C4FB0


int __fastcall GAME_RunInitHandlers(void* pArg); // 0x0044D9F0

int __stdcall WINMAIN_HandleExtraArgument(const char* szArgument); // 0x0044B5C0

int __stdcall WINMAIN_HandleArgumentError(const char* szArgument); // 0x0044B5D0

void __fastcall GAME_ShowLoadingMessage(int nError); // 0x0044E380

void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nLength); // 0x0045C850

void __fastcall SCMD_ProcessPackets(unsigned char* pPacket, int nLength); // 0x0045F7B0

extern void* gpMcpConnection; // 0x00798FB4

extern const char* gaszLaunchModeNames[7]; // 0x0070EE70

extern const D2CmdArgStrc gaCommandLineArgs[8]; // 0x006D5BE8

extern int (__cdecl* const gpfnLaunchInit[1])(); // 0x006D5BE0

extern char gszClientCharName[]; // 0x007A05C4





extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" unsigned int __cdecl strlen(const char* pString);

extern unsigned short gwMcpRequestId; // 0x00798F8C




struct D2McpInfoStrc
{
    unsigned short f_0;
    unsigned short unk0x02;
    int unk0x04;
    int nValue;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nByte0E;
    unsigned char unk0x0F;
    int nCount;
    int nToken;
    char unk0x18[0x10];
    char szName[0x20];
    unsigned short aFirst[16];
    unsigned short aSecond[16];
    char aNames[16][0x10];
};

void __stdcall sub_00449DD0_SetValue(int nValue); // 0x00449DD0


void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __stdcall GAME_StripColorCodes(Unicode* pText); // 0x0044B230


extern int gnMcpGameToken; // 0x00798FB0

extern int gdwMcpGameHash; // 0x00798F88

extern char gszMcpGameServerIP[]; // 0x007992CC

extern D2McpInfoStrc gtMcpInfo; // 0x0079910C

extern int gdwGlobal_00799108; // 0x00799108

int __stdcall WINMAIN_ShowCommandLineHelp(const D2CmdParamsStrc* pParams, int nUnused); // 0x0044B4E0

int __stdcall WINMAIN_SetLaunchMode(const D2CmdParamsStrc* pParams, int nUnused); // 0x0044B600

extern const char* gpszDefaultCaption_0070EE50; // 0x0070EE50





struct D2ClientCharRecordStrc;

struct D2GameDataTableStrc;

struct D2ClientInterfaceStrc;

typedef void (__fastcall* D2McpCallback)(int nId, unsigned int nSize, const unsigned char* pData);



void __stdcall sub_00449E30_SetValue(int nValue);                                                           // 0x00449E30


void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize);                                     // 0x00449E70



int __stdcall WINMAIN_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord);                   // 0x0044B8A0

void __cdecl RECORD_ToggleRecordPlayback();                                                                    // 0x004519A0

void __cdecl RECORD_StartPlayback();                                                                  // 0x004518E0

int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0

void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList);                  // 0x0052C0A0

int __stdcall WINMAIN_PollSystemPackets(int nUnused);                                                  // 0x0044BAD0

int __stdcall WINMAIN_PumpSystemPackets(int nUnused);                                                  // 0x0044BD20

int __cdecl WINMAIN_PopStateValue();                                                                        // 0x0044B480

void (__fastcall* gpfnMcpMotdCallback)(void* pArg);                                                       // 0x00799308

extern D2McpPacketHandler gpfnConnectPacketHandlers[];                                                       // 0x0070ED68


extern D2ClientInterfaceStrc gtClientInterface;                                                          // 0x0070EE0C

extern D2GameDataTableStrc gtGameDataTable;                                                        // 0x007A0690


extern char gszServerIP[];                                                                          // 0x0070EF20

struct D2McpPacket01Strc;

struct D2LaunchThreadRecordStrc;

struct D2McpPacket03Strc;

struct D2McpCreateGameStrc;




extern int gnGlobal_00798FB0; // 0x00798FB0


extern int gnRecordPos;                                                                              // 0x007A2784


void __cdecl RECORD_LoadRecordFile();                                                                 // 0x00451710

int __fastcall WINMAIN_SendMcpCharCreate(const char* szText, int nValue, unsigned short wValue);

int __fastcall WINMAIN_SendMcpCharLogon(const char* szText);

int __fastcall WINMAIN_SendMcpJoinGame(const char* szName, const char* szRealm, unsigned short wRequestId);

int __fastcall sub_0044A680_SendPacket08(const char* szText, unsigned short wRequestId);

int __fastcall sub_0044A710_SendPacket09(const char* szText, unsigned short wRequestId);

int __fastcall sub_0044A870_SendPacket0B(const char* szText1, const char* szText2);

int __fastcall sub_0044A900_SendPacket0C(const char* szText);

int __fastcall WINMAIN_SendMcpCharRank(const char* szName, int nB, int nC); // 0x0044AAE0


extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);

typedef void (__fastcall* PacketCallback)(int,int,int,unsigned char,const unsigned char*);

typedef void (__cdecl* CompletionCallback)();

extern PacketCallback gpfnChunkCallback; // 0x00799300

extern CompletionCallback gpfnChunkComplete; // 0x00799304

static int gnChunkPosition; // 0x0079930C

static int gnChunkExpected; // 0x00799310

extern unsigned char gabChunkBuffer[]; // 0x00799318

struct D2ClientPacket11Strc;

struct D2ClientPacket19Strc;


struct D2ClientPacket11Strc
{
    unsigned char nHeader;
    unsigned char nArg1;
    unsigned short nArg2;
};

struct D2ClientPacket19Strc
{
    unsigned char nHeader;
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_3;
    unsigned char nValue3;
};

extern void* gpMcpConnection; // 0x00798FB4


// 0x0044A980
void __cdecl sub_0044A980_SendPacket0D()
{
    unsigned char nHeader;
// build: symbol ?CHATDLG_SetMcpResult@* 0x00449BF0
    CHATDLG_SetMcpResult(0);
    nHeader = 0x0D;
// build: symbol ?D2QSSOCKET_SendPacket@* 0x006BC8A0
    D2QSSOCKET_SendPacket(gpMcpConnection, &nHeader, 1);
}

// 0x0044A9B0
void __cdecl sub_0044A9B0_SendPacket0F()
{
    unsigned char nHeader;
    CHATDLG_SetMcpResult(0);
    nHeader = 0x0F;
    D2QSSOCKET_SendPacket(gpMcpConnection, &nHeader, 1);
}

// 0x0044A9E0
void __cdecl sub_0044A9E0_SendPacket10()
{
    unsigned char nHeader;
    CHATDLG_SetMcpResult(0);
    nHeader = 0x10;
    D2QSSOCKET_SendPacket(gpMcpConnection, &nHeader, 1);
}

// 0x0044AA10
void __fastcall VIEW_SendMcpLadderRequest(unsigned char nArg1, unsigned short nArg2)
{
    D2ClientPacket11Strc tPacket;
    CHATDLG_SetMcpResult(0);
    tPacket.nHeader = 0x11;
    tPacket.nArg1 = nArg1;
    tPacket.nArg2 = nArg2;
    D2QSSOCKET_SendPacket(gpMcpConnection, (unsigned char*)&tPacket, 4);
}

// 0x0044AA50
void __cdecl VIEW_SendMcpMotdRequest()
{
    unsigned char nHeader;
    CHATDLG_SetMcpResult(0);
    nHeader = 0x12;
    D2QSSOCKET_SendPacket(gpMcpConnection, &nHeader, 1);
}

// 0x0044AA80
void __cdecl VIEW_SendMcpCancelGameCreate()
{
    unsigned char nHeader;
    CHATDLG_SetMcpResult(0);
    nHeader = 0x13;
    D2QSSOCKET_SendPacket(gpMcpConnection, &nHeader, 1);
}

// 0x0044AAB0
void __cdecl VIEW_SendMcpCharListRequest()
{
    D2ClientPacket19Strc tPacket;
    CHATDLG_SetMcpResult(0);
    tPacket.nHeader = 0x19;
    *(int*)&tPacket.nValue0 = 8;
    D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nHeader, 5);
}

// 0x0044AB70
int __fastcall sub_0044AB70_McpIncomingIgnore(void* pPacket, int nSize)
{
    return 1;
}









extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130


void __stdcall CHATDLG_SetCharDeleteReceived(int nValue);                                                           // 0x00449C60

void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue);                                                           // 0x00449C80

void __stdcall sub_00449C90_SetValue(int nValue);                                                           // 0x00449C90

void __stdcall sub_00449CC0_SetValue(int nValue);                                                           // 0x00449CC0

void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2);                // 0x00449D10

void __stdcall sub_00449D90_SetValue(int nValue);                                                           // 0x00449D90

void __stdcall sub_00449DB0_SetValue(int nValue);                                                           // 0x00449DB0

extern void* ghConnectEvent;                                                                       // 0x007992EC

extern unsigned short gwMcpReplyRequestId; // 0x00798F80

extern D2McpCallbackFn gpfnMcpPacket08Callback; // 0x007992F8

extern D2McpCallbackFn gpfnMcpPacket09Callback; // 0x007992FC

// 0x0044AB80
int __fastcall sub_0044AB80_McpIncoming1B(D2McpPacketValueStrc* pPacket, int nSize)
{
// build: symbol ?CHATDLG_SetMcpResult@* 0x00449BF0
    CHATDLG_SetMcpResult(pPacket->nValue);
    SetEvent(ghConnectEvent);
    return 1;
}

// 0x0044ABA0
int __fastcall sub_0044ABA0_McpIncoming02(D2McpPacketValueStrc* pPacket, int nSize)
{
    CHATDLG_SetMcpResult(pPacket->nValue);
// build: symbol ?CHATDLG_SetCharCreateReceived@* 0x00449C20
    CHATDLG_SetCharCreateReceived(1);
    return 1;
}

// 0x0044ABC0
int __fastcall sub_0044ABC0_McpIncoming07(D2McpPacketValueStrc* pPacket, int nSize)
{
    CHATDLG_SetMcpResult(pPacket->nValue);
    CHATDLG_SetCharLogonReceived(1);
    return 1;
}

// 0x0044ABE0
int __fastcall sub_0044ABE0_McpIncoming03(D2McpIncoming03Strc* pPacket, int nSize)
{
    const int nValueB0 = pPacket->nValueB0;
    if (pPacket->wRequestId == gwMcpRequestId)
    {
        CHATDLG_SetMcpResult(pPacket->nCode);
        gwMcpReplyRequestId = gwMcpRequestId;
        gnMcpGameToken = nValueB0;
    }
    return 1;
}

// 0x0044AC20
int __fastcall sub_0044AC20_McpIncoming04(D2McpIncoming04Strc* pPacket, int nSize)
{
    const int nValueB0 = pPacket->nValueB0;
    const int nAddress = pPacket->nAddress;
    const int nValue88 = pPacket->nValue88;
    const int nCode = pPacket->nCode;
    if (pPacket->wRequestId == gwMcpRequestId)
    {
        gwMcpReplyRequestId = gwMcpRequestId;
        gnMcpGameToken = nValueB0;
        gdwMcpGameHash = nValue88;
        if (!nAddress)
        {
            if (nCode)
            {
                CHATDLG_SetMcpResult(nCode);
                return 1;
            }
            CHATDLG_SetMcpResult(0x28);
            return 1;
        }
// build: symbol ?FOG_inet_ntoa@* 0x0040E080
        SStrCopy(gszMcpGameServerIP, FOG_inet_ntoa(nAddress), 0x12);
    }
    return 1;
}

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800



extern D2McpPacketHandler gpfnMcpPacketHandlers[]; // 0x0070ED00

extern "C" { unsigned int gSlotFirst; } // 0x00799300

extern "C" { unsigned int gSlotSecond; } // 0x00799304

struct D2McpGameInfoPacketStrc
{
    unsigned char f_0;
    unsigned char aRequestId[2];
    unsigned char aToken[4];
    unsigned char aValue[4];
    unsigned char nByte0B;
    unsigned char nByte0C;
    unsigned char nByte0D;
    unsigned char nCount;
    unsigned char aFirst[16];
    unsigned char aSecond[16];
    char szData[1];
};

// 0x0044ACA0
int __fastcall GAME_HandleMcpGameInfo(D2McpGameInfoPacketStrc* pPacket, int nSize)
{
    const int nToken = *(int*)pPacket->aToken;
    const int nValue = *(int*)pPacket->aValue;
    if (*(unsigned short*)pPacket->aRequestId != gwMcpRequestId)
        return 1;
    gtMcpInfo.f_0 = gwMcpRequestId;
    gtMcpInfo.nToken = nToken;
    gtMcpInfo.nCount = pPacket->nCount;
    gtMcpInfo.nValue = nValue;
    gtMcpInfo.nByte0C = pPacket->nByte0B;
    gtMcpInfo.nByte0D = pPacket->nByte0C;
    gtMcpInfo.nByte0E = pPacket->nByte0D;
    if (nToken == -1)
    {
// build: symbol ?CHATDLG_SetMcpResult@* 0x00449BF0
        CHATDLG_SetMcpResult(0x32);
        return 1;
    }
    if (nToken == -2)
    {
        CHATDLG_SetMcpResult(0x33);
        return 1;
    }
    const char* pString = pPacket->szData;
    const char* szName = pString;
    pString += strlen(pString) + 1;
    strcpy(gtMcpInfo.szName, szName);
    for (int i = 0; i < pPacket->nCount; i++)
    {
        gtMcpInfo.aFirst[i] = pPacket->aFirst[i];
        gtMcpInfo.aSecond[i] = pPacket->aSecond[i];
        const char* szEntry = pString;
        pString += strlen(pString) + 1;
        strcpy(gtMcpInfo.aNames[i], szEntry);
    }
    return 1;
}

// 0x0044ADF0
int __fastcall sub_0044ADF0_McpIncoming08(D2McpIncoming08Strc* pPacket, int nSize)
{
    if (gpfnMcpPacket08Callback)
        gpfnMcpPacket08Callback(pPacket->wRequestId, pPacket->aData);
    return 1;
}

// 0x0044AE10
int __fastcall sub_0044AE10_McpIncoming09(D2McpIncoming09Strc* pPacket, int nSize)
{
    if (gpfnMcpPacket09Callback)
        gpfnMcpPacket09Callback(pPacket->wRequestId, pPacket->aData);
    return 1;
}

// 0x0044AE30
int __fastcall sub_0044AE30_McpIncoming0A(D2McpIncoming0AStrc* pPacket, int nSize)
{
    if (pPacket->wRequestId == gwMcpRequestId)
    {
        CHATDLG_SetMcpResult(pPacket->nCode);
        CHATDLG_SetCharDeleteReceived(1);
    }
    return 1;
}

// 0x0044AE60
int __fastcall sub_0044AE60_McpIncoming18(D2McpPacketValueStrc* pPacket, int nSize)
{
    CHATDLG_SetMcpResult(pPacket->nValue);
    CHATDLG_SetCharUpgradeReceived(1);
    return 1;
}

// 0x0044AE80
int __fastcall sub_0044AE80_McpIncoming0B(D2McpPacketValueStrc* pPacket, int nSize)
{
    CHATDLG_SetMcpResult(pPacket->nValue);
    sub_00449C90_SetValue(1);
    return 1;
}

// 0x0044AEA0
int __fastcall sub_0044AEA0_McpIncoming0C(D2McpPacketValueStrc* pPacket, int nSize)
{
    CHATDLG_SetMcpResult(pPacket->nValue);
    sub_00449CC0_SetValue(1);
    return 1;
}

// 0x0044AEC0
int __fastcall sub_0044AEC0_McpIncoming0E(D2McpIncoming0EStrc* pPacket, int nSize)
{
    const char* szText = pPacket->szText;
    CHATDLG_SetMcpTexts(1, szText, szText + strlen(szText) + 1);
    return 1;
}

// 0x0044AEF0
int __fastcall sub_0044AEF0_McpIncoming0D(D2McpPacketValueStrc* pPacket, int nSize)
{
    CHATDLG_SetMcpResult(pPacket->nValue);
    sub_00449D90_SetValue(1);
    return 1;
}

// 0x0044AF10
int __fastcall sub_0044AF10_McpIncoming0F(D2McpPacketValueStrc* pPacket, int nSize)
{
    CHATDLG_SetMcpResult(pPacket->nValue);
    sub_00449DB0_SetValue(1);
    return 1;
}


// 0x0044AFC0
int __fastcall sub_0044AFC0_ReceiveChunk(const unsigned char* packet,unsigned int size)
{
 unsigned char* cursor=gabChunkBuffer;
 if(size<8)return 0;
 unsigned char subtype=packet[1];
 const unsigned short* pWords=(const unsigned short*)packet;
 unsigned short length=pWords[2];
 unsigned short total=pWords[1];
 unsigned short offset=pWords[3];
 if(!total&&!length&&!offset) {
  gpfnChunkCallback(0,0,0,0,0);
  gnChunkExpected=0;
  gnChunkPosition=0;
  return 1;
 }
 if(total<12)return 0;
 if(total!=gnChunkExpected)gnChunkExpected=total;
 gnChunkPosition=offset;
 int end=gnChunkPosition+length;
 if(end>total)return 0;
 memcpy(gabChunkBuffer+offset,packet+8,length);
 gnChunkPosition=end;
 if(end>=gnChunkExpected) {
  if(gpfnChunkComplete) {
   gpfnChunkComplete();
  }
  do {
   int id=*(int*)cursor;cursor+=4;
   int count=*(int*)cursor;cursor+=4;
   int extra=*(int*)cursor;cursor+=4;
   int payload=(extra+12)*count;
   gnChunkExpected-=12;
   if(count<0||extra<0||count>256||extra>16||payload>gnChunkExpected||id>2000)break;
   if(gpfnChunkCallback) {
    gpfnChunkCallback(id,count,extra,subtype,cursor);
   }
   gnChunkExpected-=(unsigned short)payload;
   cursor+=payload;
  } while(gnChunkExpected>0);
  gnChunkExpected=0;
 }
 return 1;
}




// 0x0044A170
static char* __stdcall WINMAIN_AppendPacketString(char* pDest, const char* szText, unsigned int nMax, unsigned int* pnSize)
{
    const unsigned int nLength = strlen(szText);
    *pnSize += nLength + 1;
    D2_ASSERT(*pnSize < nMax, 0x26);
    strcpy(pDest, szText);
    return pDest + nLength + 1;
}

// 0x0044A1D0
int __fastcall WINMAIN_SendMcpStartup(D2LaunchThreadRecordStrc* pRecord)
{
    D2McpPacket01Strc tPacket;
// build: symbol ?CHATDLG_SetMcpResult@* 0x00449BF0
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 1;
    tPacket.nValue01 = pRecord->nData[0];
    tPacket.nValue05 = pRecord->nData[1];
    tPacket.nValue09 = pRecord->nData[2];
    tPacket.nValue0D = pRecord->nData[3];
    tPacket.nValue11 = pRecord->nData[6];
    tPacket.nValue15 = pRecord->nData[7];
    tPacket.nValue19 = pRecord->nData[8];
    tPacket.nValue1D = pRecord->nData[9];
    tPacket.nValue21 = pRecord->nData[10];
    tPacket.nValue25 = pRecord->nData[11];
    tPacket.nValue29 = pRecord->nData[12];
    tPacket.nValue2D = pRecord->nData[13];
    tPacket.nValue31 = pRecord->nData[14];
    tPacket.nValue35 = pRecord->nData[15];
    tPacket.nValue39 = pRecord->nData[16];
    tPacket.nValue3D = pRecord->nData[17];
    WINMAIN_AppendPacketString(tPacket.szText, (const char*)&pRecord->nData[0x12], sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 0x41;
    D2_ASSERT(nTotal < 0xFFFF, 0x5C);
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044A2E0
int __fastcall WINMAIN_SendMcpCharCreate(const char* szText, int nValue, unsigned short wValue)
{
    D2McpPacket02Strc tPacket;
    CHATDLG_SetMcpResult(0);
// build: symbol ?CHATDLG_SetCharCreateReceived@* 0x00449C20
    CHATDLG_SetCharCreateReceived(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 2;
    tPacket.nValue = nValue;
    tPacket.wValue = wValue;
    WINMAIN_AppendPacketString(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 7;
    D2_ASSERT(nTotal < 0xFFFF, 0x7E);
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044A380
int __fastcall WINMAIN_SendMcpCharLogon(const char* szText)
{
    D2McpPacket07Strc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 7;
    WINMAIN_AppendPacketString(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x9A);
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044A400
int __fastcall WINMAIN_SendMcpCreateGame(D2McpCreateGameStrc* pRecord, unsigned short wRequestId)
{
    D2McpPacket03Strc tPacket;
    CHATDLG_SetMcpResult(0);
    tPacket.nValue = pRecord->nValue40;
    tPacket.wRequestId = wRequestId;
    tPacket.nByte07 = pRecord->nByte44;
    tPacket.nByte08 = pRecord->nByte45;
    unsigned int nSize = 0;
    tPacket.nPacketId = 3;
    tPacket.nByte09 = pRecord->nByte46;
    gwMcpRequestId = wRequestId;
    char* pText = WINMAIN_AppendPacketString(tPacket.szText, pRecord->szName, sizeof(tPacket.szText), &nSize);
    pText = WINMAIN_AppendPacketString(pText, pRecord->szPassword, sizeof(tPacket.szText), &nSize);
    WINMAIN_AppendPacketString(pText, pRecord->szDescription, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 10;
    D2_ASSERT(nTotal < 0xFFFF, 0xC1);
    gnGlobal_00798FB0 = 0;
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044A4E0
int __fastcall WINMAIN_SendMcpJoinGame(const char* szName, const char* szRealm, unsigned short wRequestId)
{
    D2McpPacket04Strc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 4;
    tPacket.wRequestId = wRequestId;
    gwMcpRequestId = wRequestId;
    char* pText = WINMAIN_AppendPacketString(tPacket.szText, szName, sizeof(tPacket.szText), &nSize);
    WINMAIN_AppendPacketString(pText, szRealm, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0xE9);
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044A590
void __fastcall WINMAIN_SendMcpGameListRequest(D2LaunchRequestStrc* pRequest, unsigned short wRequestId)
{
    D2McpPacket05Strc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 5;
    tPacket.wRequestId = wRequestId;
    tPacket.dwFlags = pRequest->dwFlags;
    gwMcpRequestId = wRequestId;
    WINMAIN_AppendPacketString(tPacket.szText, (const char*)pRequest->nData, sizeof(tPacket.szText), &nSize);
    nSize += 7;
    D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nSize);
}

// 0x0044A610
int __fastcall WINMAIN_SendMcpGameInfoRequest(char* szText, unsigned short wRequestId)
{
    D2McpPacket06Strc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 6;
    tPacket.wRequestId = wRequestId;
    gwMcpRequestId = wRequestId;
    WINMAIN_AppendPacketString(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    nSize += 3;
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nSize);
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0044A680
int __fastcall sub_0044A680_SendPacket08(const char* szText, unsigned short wRequestId)
{
    D2McpPacket08Strc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 8;
    tPacket.wRequestId = wRequestId;
    WINMAIN_AppendPacketString(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0x148);
    gwMcpRequestId = wRequestId;
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044A710
int __fastcall sub_0044A710_SendPacket09(const char* szText, unsigned short wRequestId)
{
    D2McpPacket09Strc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 9;
    tPacket.wRequestId = wRequestId;
    WINMAIN_AppendPacketString(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 3;
    D2_ASSERT(nTotal < 0xFFFF, 0x169);
    gwMcpRequestId = wRequestId;
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044A7A0
void __fastcall WINMAIN_SendMcpCharDelete(const char* szText, unsigned short wRequestId)
{
    D2McpPacket0AStrc tPacket;
    CHATDLG_SetMcpResult(0);
    gwMcpRequestId = wRequestId;
    tPacket.nPacketId = 0x0A;
    tPacket.wRequestId = wRequestId;
    SStrCopy(tPacket.szText, szText, sizeof(tPacket.szText));
    D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, SStrLen(tPacket.szText) + 4);
}

// 0x0044A810
void __fastcall WINMAIN_SendMcpCharUpgrade(const char* szText)
{
    D2McpPacket18Strc tPacket;
    CHATDLG_SetMcpResult(0);
    tPacket.nPacketId = 0x18;
    SStrCopy(tPacket.szText, szText, sizeof(tPacket.szText));
    D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, SStrLen(tPacket.szText) + 2);
}

// 0x0044A870
int __fastcall sub_0044A870_SendPacket0B(const char* szText1, const char* szText2)
{
    D2McpPacket0BStrc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 0x0B;
    char* pText = WINMAIN_AppendPacketString(tPacket.szText, szText1, sizeof(tPacket.szText), &nSize);
    WINMAIN_AppendPacketString(pText, szText2, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x1C2);
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044AF30
int __fastcall WINMAIN_HandleMcpServerAddress(D2McpPacket10Strc* pPacket, int nSize)
{
    const int nValueB0 = pPacket->nValueB0;
    const int nValue88 = pPacket->nValue88;
    const int nAddress = pPacket->nAddress;
    const int nCode = pPacket->nCode;
    CHATDLG_SetMcpResult(nCode);
    gnMcpGameToken = nValueB0;
    gdwMcpGameHash = nValue88;
    if (!nAddress)
    {
        if (nCode)
        {
            CHATDLG_SetMcpResult(nCode);
            sub_00449DD0_SetValue(1);
            return 1;
        }
        CHATDLG_SetMcpResult(0x28);
        sub_00449DD0_SetValue(1);
        return 1;
    }
// build: symbol ?FOG_inet_ntoa@* 0x0040E080
    SStrCopy(gszMcpGameServerIP, FOG_inet_ntoa(nAddress), 0x12);
    sub_00449DD0_SetValue(1);
    return 1;
}

// 0x0044B190
int __fastcall GAME_DispatchMcpPacket(const unsigned char* pPacket, unsigned int nSize)
{
    int nResult = 0;
    if (nSize <= 0)
        return nResult;
    const unsigned char nCmd = pPacket[0];
    if (nCmd >= 0x1A)
        return 0;
    D2McpPacketHandler pfnHandler = gpfnMcpPacketHandlers[nCmd];
    if (pfnHandler)
        nResult = pfnHandler(pPacket, nSize);
    return nResult;
}

// 0x0044B1F0
void __fastcall GAME_SetMcpCallbackA(D2McpCallbackFn pfnCallback)
{
    gpfnMcpPacket08Callback = pfnCallback;
}

// 0x0044B200
void __fastcall GAME_SetMcpCallbackB(D2McpCallbackFn pfnCallback)
{
    gpfnMcpPacket09Callback = pfnCallback;
}

// 0x0044B210
extern "C" void __fastcall sub_0044B210_StoreSlots(unsigned int first, unsigned int second)
{
    gSlotFirst = first;
    gSlotSecond = second;
}

// 0x0044B220
void __fastcall GAME_SetMcpChatCallback(void (__fastcall* pfnCallback)(void* pArg))
{
    gpfnMcpMotdCallback = pfnCallback;
}

// 0x0044B230
void __stdcall GAME_StripColorCodes(Unicode* pString)
{
    D2_ASSERT(UNICODE_StrLen(pString) < 500, 0x342);
    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    int nLength = UNICODE_StrLen(pPattern);
    for (Unicode* pFound = sub_00526940_FindSubstring(pString, pPattern); pFound && pFound[nLength].wChar; pFound = sub_00526940_FindSubstring(pString, pPattern))
    {
        memmove(pFound, &pFound[nLength + 1], (UNICODE_StrLen(pFound) - nLength) * sizeof(Unicode));
    }
}

// 0x0044B2D0
int __fastcall WINMAIN_HandleMcpGameList(D2McpPacket05Strc* pPacket, int nSize)
{
    const int nValue = pPacket->nValue;
    const int nToken = pPacket->nToken;
    if (pPacket->wRequestId != gwMcpRequestId)
        return 1;
    gtMcpInfo.f_0 = gwMcpRequestId;
    gtMcpInfo.unk0x04 = nValue;
    gtMcpInfo.nCount = pPacket->nCount;
    gtMcpInfo.nToken = nToken;
    if (nToken == -2)
    {
        CHATDLG_SetMcpResult(0x33);
        return 1;
    }
    if (nToken == -1)
    {
        CHATDLG_SetMcpResult(0x32);
        return 1;
    }
    const char* pString = pPacket->szData;
    const char* szFirst = pString;
    pString += strlen(pString) + 1;
    const char* szSecond = pString;
    const unsigned int nSecondLength = strlen(pString);
    Unicode wszText[0x240];
    sub_00526F20_ToUnicode(wszText, szFirst, 0x240);
    GAME_StripColorCodes(wszText);
    char szText[0x400];
    UNICODE_ToAscii(szText, wszText, 0x400);
    SStrCopy(gtMcpInfo.unk0x18, szText, 0x10);
    SStrCopy(gtMcpInfo.szName, szSecond, 0x10);
    gdwGlobal_00799108 = (unsigned int)(szSecond + nSecondLength + 1 - (const char*)pPacket) < (unsigned int)nSize;
    return 1;
}
















// 0x0044B150
int __fastcall WINMAIN_HandleMcpCreateQueue(const unsigned char* pPacket, unsigned int nSize)
{
    sub_00449E30_SetValue(*(const int*)(pPacket + 1));
    sub_00449E50_SetValue(1);
    return 1;
}

// 0x0044B170
int __fastcall WINMAIN_HandleMcpCharList(const unsigned char* pPacket, unsigned int nSize)
{
    MCPCONNECT_SetPacket((const char*)pPacket, nSize);
    return 1;
}

// 0x0044B180
int __fastcall WINMAIN_HandleMcpCharListExpanded(const unsigned char* pPacket, unsigned int nSize)
{
    MCPCONNECT_SetPacket((const char*)pPacket, nSize);
    return 1;
}

// 0x0044B1C0
int __fastcall WINMAIN_DispatchConnectPacket(const unsigned char* pPacket, unsigned int nSize, void* pArg)
{
    int nResult = 0;
    if (nSize <= 0)
        return nResult;
    const unsigned char nCmd = pPacket[0];
    if (nCmd >= 0x1A)
        return 0;
    D2McpPacketHandler pfnHandler = gpfnConnectPacketHandlers[nCmd];
    if (pfnHandler)
        nResult = pfnHandler(pPacket, nSize);
    return nResult;
}

// 0x0044A900
int __fastcall sub_0044A900_SendPacket0C(const char* szText)
{
    D2McpPacket0CStrc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 0x0C;
    WINMAIN_AppendPacketString(tPacket.szText, szText, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 1;
    D2_ASSERT(nTotal < 0xFFFF, 0x1DE);
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044AAE0
int __fastcall WINMAIN_SendMcpCharRank(const char* szName, int nB, int nC)
{
    D2McpPacket16Strc tPacket;
    CHATDLG_SetMcpResult(0);
    unsigned int nSize = 0;
    tPacket.nPacketId = 0x16;
    tPacket.nValue01 = nB;
    tPacket.nValue05 = nC;
    WINMAIN_AppendPacketString(tPacket.szText, szName, sizeof(tPacket.szText), &nSize);
    const unsigned int nTotal = nSize + 9;
    D2_ASSERT(nTotal < 0xFFFF, 0x27B);
    return D2QSSOCKET_SendPacket(gpMcpConnection, &tPacket.nPacketId, nTotal);
}

// 0x0044B120
int __fastcall WINMAIN_HandleMcpMotd(const unsigned char* pPacket, unsigned int nSize)
{
    if (nSize < 2)
        return 0;
    if (gpfnMcpMotdCallback)
        ((D2McpCallback)gpfnMcpMotdCallback)(pPacket[1], nSize - 2, pPacket + 2);
    return 1;
}
void __cdecl RECORD_StartPlayback(); // 0x004518E0

extern "C" void __cdecl sub_0044AFC0(); // 0x0044AFC0

extern "C" const char* gData_0070ECC0[15] = { // 0x0070ECC0
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};

D2McpPacketHandler gpfnMcpPacketHandlers[26] = { // 0x0070ED00
    (D2McpPacketHandler)&sub_0044AB70_McpIncomingIgnore,
    0,
    (D2McpPacketHandler)&sub_0044ABA0_McpIncoming02,
    (D2McpPacketHandler)&sub_0044ABE0_McpIncoming03,
    (D2McpPacketHandler)&sub_0044AC20_McpIncoming04,
    (D2McpPacketHandler)&WINMAIN_HandleMcpGameList,
    (D2McpPacketHandler)&GAME_HandleMcpGameInfo,
    (D2McpPacketHandler)&sub_0044ABC0_McpIncoming07,
    (D2McpPacketHandler)&sub_0044ADF0_McpIncoming08,
    (D2McpPacketHandler)&sub_0044AE10_McpIncoming09,
    (D2McpPacketHandler)&sub_0044AE30_McpIncoming0A,
    (D2McpPacketHandler)&sub_0044AE80_McpIncoming0B,
    (D2McpPacketHandler)&sub_0044AEA0_McpIncoming0C,
    (D2McpPacketHandler)&sub_0044AEF0_McpIncoming0D,
    (D2McpPacketHandler)&sub_0044AEC0_McpIncoming0E,
    (D2McpPacketHandler)&sub_0044AF10_McpIncoming0F,
    (D2McpPacketHandler)&WINMAIN_HandleMcpServerAddress,
    (D2McpPacketHandler)&sub_0044AFC0,
    (D2McpPacketHandler)&WINMAIN_HandleMcpMotd,
    0,
    (D2McpPacketHandler)&WINMAIN_HandleMcpCreateQueue,
    0,
    0,
    (D2McpPacketHandler)&WINMAIN_HandleMcpCharList,
    (D2McpPacketHandler)&sub_0044AE60_McpIncoming18,
    (D2McpPacketHandler)&WINMAIN_HandleMcpCharListExpanded
};

D2McpPacketHandler gpfnConnectPacketHandlers[26] = { 0, (D2McpPacketHandler)&sub_0044AB80_McpIncoming1B }; // 0x0070ED68
