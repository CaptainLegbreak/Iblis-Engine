#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2Unicode.h"
#include "D2McpPackets.h"
#include "D2LaunchRequest.h"

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

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

void __fastcall GAME_CalcCdKeyChecksum(char* szKey, unsigned int* pChecksum); // 0x00449890

int __stdcall SCmdRegisterArgList(const D2CmdArgStrc* pArgList, unsigned int nCount); // 0x006C4E50

int __stdcall SCmdProcess(const char* szCmdLine, int bSkipProgName, int (__stdcall* pfnExtra)(const char*), int (__stdcall* pfnError)(const char*)); // 0x006C4FB0

unsigned short __stdcall FOG_ConnectionReceive(void* pConnection, char* pBuffer, int nSize); // 0x006BC120

int __fastcall GAME_DispatchMcpPacket(const char* pPacket, unsigned int nSize); // 0x0044B190

int __fastcall GAME_RunInitHandlers(void* pArg); // 0x0044D9F0

int __stdcall WINMAIN_HandleExtraArgument(const char* szArgument); // 0x0044B5C0

int __stdcall WINMAIN_HandleArgumentError(const char* szArgument); // 0x0044B5D0

void __fastcall GAME_ShowLoadingMessage(int nError); // 0x0044E380

int __stdcall CLIENT_DequeueGamePacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A890

int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A8B0

void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nLength); // 0x0045C850

void __fastcall SCMD_ProcessPackets(unsigned char* pPacket, int nLength); // 0x0045F7B0


extern const char* gaszLaunchModeNames[7]; // 0x0070EE70

extern const D2CmdArgStrc gaCommandLineArgs[8]; // 0x006D5BE8

extern int (__cdecl* const gpfnLaunchInit[1])(); // 0x006D5BE0

extern char gszClientCharName[]; // 0x007A05C4





extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

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
};

void __stdcall sub_00449DD0_SetValue(int nValue); // 0x00449DD0

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __stdcall GAME_StripColorCodes(Unicode* pText); // 0x0044B230

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

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

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

void __stdcall sub_00449E30_SetValue(int nValue);                                                           // 0x00449E30

void __stdcall sub_00449E50_SetValue(int nValue);                                                           // 0x00449E50

void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize);                                     // 0x00449E70

void __cdecl sub_006115F0_Empty();                                                                          // 0x006115F0

void __cdecl sub_0052BDA0_Empty();                                                                          // 0x0052BDA0

void __cdecl sub_0052BDB0_Empty();                                                                          // 0x0052BDB0

void __cdecl PROFCORE_CloseLog();                                                                                // 0x00611600

int __stdcall WINMAIN_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord);                   // 0x0044B8A0

void __cdecl RECORD_ToggleRecordPlayback();                                                                    // 0x004519A0

void __cdecl RECORD_StartPlayback();                                                                  // 0x004518E0

int __cdecl CLIENT_GetConnectionStatus();                                                                   // 0x0052B050

int __fastcall SCMD_RunMessageLoop(int (__stdcall* pfnIdle)(int));                                     // 0x00451BB0

void __stdcall SERVER_Initialize(int a1, int a2);                                                           // 0x0052B7A0

void __stdcall CLIENT_Initialize(int nArg, const char* szAddress);                                               // 0x0052A750

void __stdcall SERVER_SetMaxClientsPerGame(int nArg1);                                                   // 0x0052B250

int __stdcall SERVER_SetHackListEnabled(int nArg1);                                                    // 0x0052B280

void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList);                  // 0x0052C0A0

int __stdcall WINMAIN_PollSystemPackets(int nUnused);                                                  // 0x0044BAD0

int __stdcall WINMAIN_PumpSystemPackets(int nUnused);                                                  // 0x0044BD20

void __cdecl CLIENT_Release();                                                                                // 0x0052A7E0

void __cdecl SERVER_Release();                                                              // 0x0052B2A0

int __cdecl WINMAIN_PopStateValue();                                                                        // 0x0044B480

void (__fastcall* gpfnMcpMotdCallback)(void* pArg);                                                       // 0x00799308

extern D2McpPacketHandler gpfnConnectPacketHandlers[];                                                       // 0x0070ED68

void* ghClientInstance;                                                                                  // 0x007A0318

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










extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130

void __stdcall CHATDLG_SetCharLogonReceived(int nValue);                                                           // 0x00449C40

void __stdcall CHATDLG_SetCharDeleteReceived(int nValue);                                                           // 0x00449C60

void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue);                                                           // 0x00449C80

void __stdcall sub_00449C90_SetValue(int nValue);                                                           // 0x00449C90

void __stdcall sub_00449CC0_SetValue(int nValue);                                                           // 0x00449CC0

void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2);                // 0x00449D10

void __stdcall sub_00449D90_SetValue(int nValue);                                                           // 0x00449D90

void __stdcall sub_00449DB0_SetValue(int nValue);                                                           // 0x00449DB0

extern void* ghConnectEvent;                                                                       // 0x007992EC

unsigned short gwMcpReplyRequestId;                                                                        // 0x00798F80

D2McpCallbackFn gpfnMcpPacket08Callback;                                                                   // 0x007992F8

D2McpCallbackFn gpfnMcpPacket09Callback;                                                                   // 0x007992FC

















// 0x0044B420
void __cdecl WINMAIN_ShutdownInterface()
{
    sub_0052BDB0_Empty();
    PROFCORE_CloseLog();
}


















// 0x0044B400
D2ClientInterfaceStrc* __fastcall WINMAIN_InitInterface(void* hInstance)
{
    sub_006115F0_Empty();
    sub_0052BDA0_Empty();
    ghClientInstance = hInstance;
    return &gtClientInterface;
}

// 0x0044B430
int __fastcall WINMAIN_RunLauncher(D2ClientCharRecordStrc* pRecord)
{
    return WINMAIN_LauncherRun(ghClientInstance, pRecord);
}




















void __cdecl RECORD_StartPlayback(); // 0x004518E0

#include "gen/data/Source/D2Client/Unknown_0044B400.inc"
