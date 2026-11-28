#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0070EE90

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
#include "D2GfxApi.h"
#include "D2NetApi.h"
#include "D2MCPClientApi.h"

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



int __stdcall SCmdProcess(const char* szCmdLine, int bSkipProgName, int (__stdcall* pfnExtra)(const char*), int (__stdcall* pfnError)(const char*)); // 0x006C4FB0



int __stdcall WINMAIN_HandleExtraArgument(const char* szArgument); // 0x0044B5C0

int __stdcall WINMAIN_HandleArgumentError(const char* szArgument); // 0x0044B5D0



void __fastcall SCMD_ProcessPackets(unsigned char* pPacket, int nLength); // 0x0045F7B0


extern const char* gaszLaunchModeNames[7]; // 0x0070EE70

extern const D2CmdArgStrc gaCommandLineArgs[8]; // 0x006D5BE8

extern int (__cdecl* const gpfnLaunchInit[1])(); // 0x006D5BE0

extern char gszClientCharName[]; // 0x007A05C4

int gbConnectFailed;                                                                                     // 0x007A0460

unsigned long gdwStartSessionTick;                                                                             // 0x007A0464

unsigned long gdwStopSessionTick;                                                                             // 0x007A045C


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
};



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



int gbGameServerReady; // 0x007A0618


struct D2ClientCharRecordStrc;

struct D2GameDataTableStrc;

struct D2ClientInterfaceStrc;

typedef void (__fastcall* D2McpCallback)(int nId, unsigned int nSize, const unsigned char* pData);








int __stdcall WINMAIN_LauncherRun(void* hInstance, D2ClientCharRecordStrc* pRecord);                   // 0x0044B8A0




void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList);                  // 0x0052C0A0



int __cdecl WINMAIN_PopStateValue();                                                                        // 0x0044B480

void (__fastcall* gpfnMcpMotdCallback)(void* pArg);                                                       // 0x00799308

extern D2McpPacketHandler gpfnConnectPacketHandlers[];                                                       // 0x0070ED68


extern D2ClientInterfaceStrc gtClientInterface;                                                          // 0x0070EE0C

extern D2GameDataTableStrc gtGameDataTable;                                                        // 0x007A0690

char gtGameList[4];                                                                                // 0x007A0630

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



extern unsigned char gabChunkBuffer[]; // 0x00799318










extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130









extern void* ghConnectEvent;                                                                       // 0x007992EC






















































void __fastcall UI_ToggleListDialog(int nResolution); // 0x004549B0

extern int gnSavedScreenWidth; // 0x00711474

extern int gnBeltUiRecordRow; // 0x007A5218


// 0x0044BA20
void __fastcall GAME_SetResolution(int nResolution)
{
    if (nResolution == D2GFX_GetResolutionMode())
        return;
    switch (nResolution)
    {
    case 0:
        gnScreenWidth = 640;
        gnScreenHeight = 480;
        gnBeltUiRecordRow = 0;
        break;
    case 2:
        gnScreenWidth = 800;
        gnScreenHeight = 600;
        gnBeltUiRecordRow = 1;
        break;
    }
    gnAutomapWidth = gnScreenWidth;
    gnAutomapHeight_007A521C = gnScreenHeight - 40;
    gnSavedScreenWidth = gnScreenWidth;
    sub_004F90A0(nResolution);
    PLAYER_SetPanelSlide(sub_0045AE90_GetPanelSlideMode());
    AUTOMAP_ResetBaseOffset(1);
    sub_00457440_Nop(nResolution);
    UI_ToggleListDialog(nResolution);
}

// 0x0044BAD0
int __stdcall WINMAIN_PollSystemPackets(int nUnused)
{
    unsigned char pBuffer[0x200];
    if ((gnGameType != 0 && gnGameType != 1) || !WINDOW_GetState())
    {
        if (GetTickCount() - gdwStartSessionTick > 10000)
        {
            GAME_ShowLoadingMessage(6);
            gbConnectFailed = 1;
            gbGameServerReady = 0;
            return 1;
        }

// build: symbol ?CLIENT_IsConnected@* 0x0052A640
        if (!CLIENT_IsConnected())
        {
            return 1;
        }
    }

    const int nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
    SCMD_HandleSystemPacket(pBuffer, nLength);
    return gbGameServerReady != 0;
}

// 0x0044BB70
int __stdcall GAME_StartSubsystem()
{
// build: symbol ?gnSubsystemActive@* 0x007A0458
    gnSubsystemActive = 1;
    return GAME_Initialize();
}

int __stdcall GAME_Shutdown(); // 0x0052C030

// 0x0044BB80
extern "C" int __cdecl GAME_ShutdownIfActive()
{
    if (gnSubsystemActive == 0)
        return 0;
    gnSubsystemActive = 0;
    return GAME_Shutdown();
}


// 0x0044BBA0
int __cdecl GAME_GetConnectFailed()
{
    return gbConnectFailed;
}

// 0x0044BBB0
int __stdcall WINMAIN_WaitConnect(int nUnused)
{
    if ((gnGameType != 0 && gnGameType != 1) || !WINDOW_GetState())
    {
        const int nStatus = CLIENT_GetConnectionStatus();
        if (nStatus == 0)
        {
            GAME_ShowLoadingMessage(6);
            gbConnectFailed = 1;
            gbGameServerReady = 0;
            return 1;
        }
        return nStatus == 2;
    }
    return 0;
}

// 0x0044BC10
int __fastcall GAME_RunClient(int nArg, const char* szAddress)
{
    CLIENT_Initialize(nArg, szAddress);
    SCMD_RunMessageLoop(WINMAIN_WaitConnect);
    return 1;
}

// 0x0044BC30
int __cdecl WINMAIN_StartSession()
{
    gbGameServerReady = 0;
    if (gnGameType == 0)
    {
        SERVER_Initialize(1, 1);
        CLIENT_Initialize(1, 0);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
        SERVER_SetHackListEnabled(0);
        GAME_InitGameDataTable(&gtGameDataTable, gtGameList);
// build: symbol ?gnSubsystemActive@* 0x007A0458
        gnSubsystemActive = 1;
        GAME_Initialize();
    }
    else if (gnGameType == 1)
    {
        SERVER_Initialize(2, 1);
        CLIENT_Initialize(2, 0);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
        SERVER_SetHackListEnabled(0);
        GAME_InitGameDataTable(&gtGameDataTable, gtGameList);
        gnSubsystemActive = 1;
        GAME_Initialize();
    }
    else if (gnGameType == 4)
    {
// build: symbol ?gszBattleNetIP@* 0x0070F028
        CLIENT_Initialize(0, gszBattleNetIP);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
    }
    else if (gnGameType == 6 || gnGameType == 8)
    {
        SERVER_Initialize(0, 1);
        SERVER_SetMaxClientsPerGame(8);
        SERVER_SetHackListEnabled(0);
        CLIENT_Initialize(0, gszServerIP);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
        GAME_InitGameDataTable(&gtGameDataTable, gtGameList);
        gnSubsystemActive = 1;
        GAME_Initialize();
    }
    else
    {
        CLIENT_Initialize(0, gszServerIP);
        SCMD_RunMessageLoop(WINMAIN_WaitConnect);
    }

    gdwStartSessionTick = GetTickCount();
    gbConnectFailed = 0;
    SCMD_RunMessageLoop(WINMAIN_PollSystemPackets);
    return WINMAIN_PopStateValue();
}

// 0x0044BD20
int __stdcall WINMAIN_PumpSystemPackets(int nUnused)
{
    unsigned char pBuffer[0x200];
    WINDOW_GetState();
    if (gnGameType == 0 || gnGameType == 1)
    {
// build: symbol ?GAME_ProcessNetworkMessages@* 0x0052CFE0
        GAME_ProcessNetworkMessages();
    }

    const int nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
    SCMD_HandleSystemPacket(pBuffer, nLength);
    if (GetTickCount() - gdwStopSessionTick > 10000)
    {
        return 1;
    }
    return gbGameServerReady == 0;
}

// 0x0044BD90
int __cdecl WINMAIN_StopSession()
{
    gdwStopSessionTick = GetTickCount();
    SCMD_RunMessageLoop(WINMAIN_PumpSystemPackets);
    CLIENT_Release();
    if (gnGameType == 0 || gnGameType == 1 || gnGameType == 6 || gnGameType == 8)
        SERVER_Release();
    return WINMAIN_PopStateValue();
}








