#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
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
#include "D2MCPClientApi.h"
#include "D2MCPClientApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

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

struct Unicode;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258

extern "C" __declspec(dllimport) int __stdcall GetUserNameA(char* szBuffer, unsigned long* pSize); // 0x006CC000

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" int __cdecl tolower(int nChar); // 0x0068523E

extern "C" unsigned long __cdecl strtoul(const char* szString, char** ppEnd, int nRadix); // 0x006867B2

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);



int __stdcall SCmdProcess(const char* szCmdLine, int bSkipProgName, int (__stdcall* pfnExtra)(const char*), int (__stdcall* pfnError)(const char*)); // 0x006C4FB0



int __stdcall WINMAIN_HandleExtraArgument(const char* szArgument); // 0x0044B5C0

int __stdcall WINMAIN_HandleArgumentError(const char* szArgument); // 0x0044B5D0



void __fastcall SCMD_ProcessPackets(unsigned char* pPacket, int nLength); // 0x0045F7B0


extern const char* gaszLaunchModeNames[7]; // 0x0070EE70

extern int (__cdecl* const gpfnLaunchInit[1])(); // 0x006D5BE0

extern char gszClientCharName[]; // 0x007A05C4





extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" unsigned int __cdecl strlen(const char* pString);

extern unsigned short gwMcpRequestId; // 0x00798F8C






void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

extern int gnMcpGameToken; // 0x00798FB0

extern int gdwMcpGameHash; // 0x00798F88

extern char gszMcpGameServerIP[]; // 0x007992CC

extern int gdwGlobal_00799108; // 0x00799108

extern const char* gpszDefaultCaption_0070EE50; // 0x0070EE50





struct D2ClientCharRecordStrc;

struct D2GameDataTableStrc;

struct D2ClientInterfaceStrc;

typedef void (__fastcall* D2McpCallback)(int nId, unsigned int nSize, const unsigned char* pData);








int __stdcall WINMAIN_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord);                   // 0x0044B8A0




void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList);                  // 0x0052C0A0



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








extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);

typedef void (__fastcall* PacketCallback)(int,int,int,unsigned char,const unsigned char*);

typedef void (__cdecl* CompletionCallback)();

extern PacketCallback gpfnChunkCallback; // 0x00799300

extern CompletionCallback gpfnChunkComplete; // 0x00799304

static int gnChunkPosition; // 0x0079930C

static int gnChunkExpected; // 0x00799310

extern unsigned char gabChunkBuffer[]; // 0x00799318










extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130









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





















extern "C" void __cdecl RECORD_RegisterLngArgument(); // 0x00451260
extern "C" void __cdecl WINMAIN_SaveDefaultCmdLine(); // 0x0044B5E0

#pragma pack(push, 1)
struct d2data_0070EE0C_t
{
    const void* p0;
};
#pragma pack(pop)

extern "C" struct d2data_0070EE0C_t gData_0070EE0C; // 0x0070EE0C

extern "C" struct d2data_0070EE0C_t gData_0070EE0C = {
    (const void*)(unsigned int)&WINMAIN_RunLauncher
}; // 0x0070EE0C
#pragma comment(linker, "/alternatename:?gtClientInterface@@3UD2ClientInterfaceStrc@@A=_gData_0070EE0C")
