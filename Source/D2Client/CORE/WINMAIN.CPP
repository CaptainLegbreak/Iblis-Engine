#include "D2Client.h"
#include "D2Unicode.h"
#include "D2McpPackets.h"
#include "D2LaunchRequest.h"
#include "D2MultiTypes.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi2.h"
#include "D2GfxApi.h"
#include "D2WinApi.h"
#include "D2NetApi.h"
#include "D2MCPClientApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CmdParamsStrc;

union D2CdKeyWordStrc;

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

union D2CdKeyWordStrc
{
    unsigned int nValue;
    char szText[4];
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

int __stdcall SCmdRegisterArgList(const D2CmdArgStrc* pArgList, unsigned int nCount); // 0x006C4E50

int __stdcall SCmdProcess(const char* szCmdLine, int bSkipProgName, int (__stdcall* pfnExtra)(const char*), int (__stdcall* pfnError)(const char*)); // 0x006C4FB0

int __fastcall GAME_DispatchMcpPacket(const char* pPacket, unsigned int nSize); // 0x0044B190

int __fastcall GAME_RunInitHandlers(void* pArg); // 0x0044D9F0

int __stdcall WINMAIN_HandleExtraArgument(const char* szArgument); // 0x0044B5C0

int __stdcall WINMAIN_HandleArgumentError(const char* szArgument); // 0x0044B5D0

void __fastcall GAME_ShowLoadingMessage(int nError); // 0x0044E380

void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nLength); // 0x0045C850

void __fastcall SCMD_ProcessPackets(unsigned char* pPacket, int nLength); // 0x0045F7B0

void* gpMcpConnection; // 0x00798FB4

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

// build: symbol ??__EgpszHelpCaption@@YAXXZ 0x006CA9A0
const char* gpszHelpCaption = gpszDefaultCaption_0070EE50; // 0x007A0454

// build: symbol ??__EgpszCaption_007A0450@@YAXXZ 0x006CA9B0
const char* gpszCaption_007A0450 = gpszDefaultCaption_0070EE50; // 0x007A0450


static int s_bHelpChecked; // 0x007A0448

struct D2ClientCharRecordStrc;

struct D2GameDataTableStrc;

struct D2ClientInterfaceStrc;

typedef void (__fastcall* D2McpCallback)(int nId, unsigned int nSize, const unsigned char* pData);





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

int __fastcall WINMAIN_SendMcpJoinGame(const char* szName, const char* szRealm, unsigned short wRequestId);

int __fastcall sub_0044A680_SendPacket08(const char* szText, unsigned short wRequestId);

int __fastcall sub_0044A710_SendPacket09(const char* szText, unsigned short wRequestId);

int __fastcall sub_0044A870_SendPacket0B(const char* szText1, const char* szText2);

int __fastcall sub_0044A900_SendPacket0C(const char* szText);

// 0x00449920
int __fastcall WINMAIN_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue)
{
    D2CdKeyWordStrc tWord;
    char szValue[8];
    char szKey[20];
    *pProduct = 0;
    *pValue = 0;
    strcpy(szKey, szCdKey);
    const char* p = szKey;
    while (*p)
    {
// build: symbol ?gabCdKeyMap@* 0x006D59F0
        if (gabCdKeyMap[(unsigned char)*p++] > 0x17)
        {
            return 0;
        }
    }

    GAME_CalcCdKeyChecksum(szKey, &tWord.nValue);
    unsigned int nHash = 3;
    for (unsigned int i = 0; i < 16; ++i)
    {
        const char c = tolower(szKey[i]);
        int nDigit;
        if (c >= 'a')
        {
            nDigit = c - 0x57;
        }
        else
        {
            nDigit = c - '0';
        }
        nHash += (2 * nHash) ^ nDigit;
    }

    if ((unsigned char)nHash != tWord.nValue)
    {
        return 0;
    }

    for (int i = 15; i >= 0; --i)
    {
        const int j = (i + 7) & 0xF;
        const char c = szKey[i];
        szKey[i] = szKey[j];
        szKey[j] = c;
    }

    tWord.nValue = 0x13AC9741;
    for (int i = 15; i >= 0; --i)
    {
        szKey[i] = toupper(szKey[i]);
        if (szKey[i] <= '7')
        {
            szKey[i] ^= tWord.nValue & 7;
            tWord.nValue >>= 3;
        }
        else if (szKey[i] < 'A')
        {
            szKey[i] ^= i & 1;
        }
    }

    SStrCopy(tWord.szText, szKey, 3);
    SStrCopy(szValue, &szKey[2], 7);
    *pProduct = strtoul(tWord.szText, 0, 16);
    *pValue = strtoul(szValue, 0, 16);
    return 1;
}

extern "C" void* __cdecl memcpy(void*,const void*,unsigned int);

typedef void (__fastcall* PacketCallback)(int,int,int,unsigned char,const unsigned char*);

typedef void (__cdecl* CompletionCallback)();

extern PacketCallback gpfnChunkCallback; // 0x00799300

extern CompletionCallback gpfnChunkComplete; // 0x00799304



extern unsigned char gabChunkBuffer[]; // 0x00799318










extern "C" __declspec(dllimport) int __stdcall SetEvent(void* hEvent);                                      // 0x006CC130

extern void* ghConnectEvent;                                                                       // 0x007992EC





















int gaStateStack[4]; // 0x007A0424

extern int gnStateStackCount; // 0x007A044C


// 0x0044B440
void __fastcall WINMAIN_PushStateValue(int nValue)
{
    D2_ASSERT(gnStateStackCount < 5, 0xAA);
    gaStateStack[gnStateStackCount] = nValue;
    gnStateStackCount += 1;
}

// 0x0044B480
int __cdecl WINMAIN_PopStateValue()
{
    D2_ASSERT(gnStateStackCount, 0xB4);
    int nValue = gaStateStack[0];
    --gnStateStackCount;
    for (int i = 0; i < 3; ++i)
        gaStateStack[i] = gaStateStack[i + 1];
    return nValue;
}

struct D2CmdLineArgStrc;

struct D2CmdLineArgStrc
{
    char unk0x00[0x18];
    const char* szValue;
};


// 0x0044B5E0
int __stdcall WINMAIN_SaveDefaultCmdLine(D2CmdLineArgStrc* pArg, int nUnused)
{
    return SRegSaveString("Diablo II", "Default Command Line", 0, pArg->szValue);
}

// 0x0044B780
void __cdecl WINMAIN_RaiseGameWindow()
{
    void* hWnd = (void*)WINDOW_GetWindow();
    if (hWnd)
        SendMessageA(hWnd, 0x1C, 0, 0);
    WINDOW_ShowAll();
}

struct D2ConfigStrc;

extern D2ConfigStrc* gpClientConfig; // 0x007A0438

// 0x0044B7A0
D2ConfigStrc* __cdecl WINMAIN_GetClientInfo()
{
    return gpClientConfig;
}

struct D2ClientNotifyStrc;

// 0x0044B7B0
D2ClientNotifyStrc* __cdecl WINMAIN_GetClientNotify()
{
    return (D2ClientNotifyStrc*)gpClientConfig->pComInterface;
}

// 0x0044B7C0
const char* __cdecl WINMAIN_GetGameName()
{
    if (gpClientConfig && strlen(gpClientConfig->szGameName) >= 1)
        return gpClientConfig->szGameName;
    return 0;
}

// 0x0044B7F0
const char* __cdecl WINMAIN_GetGameDescription()
{
    if (gpClientConfig && strlen(gpClientConfig->szText0x245) >= 1)
        return gpClientConfig->szText0x245;
    return 0;
}

// 0x0044B820
const char* __cdecl WINMAIN_GetGamePassword()
{
    if (gpClientConfig && strlen(gpClientConfig->szServerIP) >= 1)
        return gpClientConfig->szServerIP;
    return 0;
}

// 0x0044B850
int __cdecl WINMAIN_IsHardcore()
{
    return gpClientConfig->aFlags1EF[0] & 4;
}

// 0x0044B860
void __cdecl WINMAIN_SetCharDiedFlag()
{
    gpClientConfig->wFlags1EF |= 8;
}

// 0x0044B870
void __cdecl WINMAIN_SetLaunchStateOne()
{
// build: symbol ?gnClientLaunchState@* 0x0070EE4C
    gnClientLaunchState = 1;
}

#pragma pack(push, 1)
#pragma pack(pop)

// 0x0044B880
void __fastcall WINMAIN_SetExitApplication(int nValue)
{
// build: symbol ?gbExitApplication@* 0x0070EE8C
    gbExitApplication = nValue;
}

// 0x0044B890
int __cdecl WINMAIN_GetExitApplication()
{
// build: symbol ?gbExitApplication@* 0x0070EE8C
    return gbExitApplication;
}

struct D2PoolSystemStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetModuleFileNameA(void* hModule, char* szFileName, unsigned long nSize); // 0x006CC1BC

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

int __cdecl GAME_LoadLngModule(); // 0x00451330

int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc); // 0x004F8FC0

int __stdcall SCMD_WindowProc(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam); // 0x00451B30

void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80

void __stdcall DATATBLS_LoadAllTxts(void* pArg, int bArg); // 0x00619300


void __cdecl GAME_FreeLngModule(); // 0x00451290


extern "C" int __cdecl GAME_ShutdownIfActive(); // 0x0044BB80

extern void* ghLaunchInstance; // 0x007A043C

extern char gszModulePath[260]; // 0x007A0320

extern int gnLaunchResult; // 0x007A0440


// 0x0044C6E0
void __cdecl WINMAIN_DrainPacketQueues()
{
    unsigned char pBuffer[0x200];
    int nLength;
    do
    {
        nLength = CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer));
        SCMD_HandleSystemPacket(pBuffer, nLength);
        Sleep(0);
    }
    while (nLength != -1);

    do
    {
        nLength = CLIENT_DequeueGamePacket(pBuffer, sizeof(pBuffer));
        SCMD_ProcessPackets(pBuffer, nLength);
        Sleep(0);
    }
    while (nLength != -1);
}

// 0x0044B4E0
int __stdcall WINMAIN_ShowCommandLineHelp(const D2CmdParamsStrc* pParams, int nUnused)
{
    if (!s_bHelpChecked)
    {
        s_bHelpChecked = 1;
        unsigned long nSize = 0xF;
        char szUser[0x10];
        GetUserNameA(szUser, &nSize);
        if (SStrCmp(szUser, "rseis", 0x7FFFFFFF))
        {
            MessageBoxA(0, "Available command line options:\n  -set[default command line]\t\tSet new default command line string\n  -lng[lngfile]\t\t\tUse \"lngfile\" for language resources\n", gpszHelpCaption, 0);
        }
    }
    return 0;
}

// 0x0044B550
int __stdcall WINMAIN_RunMemoryTest(const D2CmdParamsStrc* pParams, int nUnused)
{
    char* pMemory = (char*)FOG_Alloc(0x6000000, ".\\CORE\\WINMAIN.CPP", 0x121, 0);
    for (char* p = pMemory; p < pMemory + 0x6000000; p += 0x1000)
        *p = 0;
    FOG_Free(pMemory, ".\\CORE\\WINMAIN.CPP", 0x124, 0);
    return 1;
}

// 0x0044B5A0
int __stdcall WINMAIN_HandleToggleFlagsOption(const D2CmdParamsStrc* pParams, int nUnused)
{
    RECORD_ToggleRecordPlayback();
    return 1;
}

// 0x0044B5B0
int __stdcall WINMAIN_HandlePlaybackOption(const D2CmdParamsStrc* pParams, int nUnused)
{
    RECORD_StartPlayback();
    return 1;
}

// 0x0044B5C0
int __stdcall WINMAIN_HandleExtraArgument(int nArg)
{
    WINMAIN_ShowCommandLineHelp(0, 0);
    return 0;
}

// 0x0044B5D0
int __stdcall WINMAIN_HandleArgumentError(int nArg)
{
    return WINMAIN_ShowCommandLineHelp(0, 0);
}

// 0x0044B600
int __stdcall WINMAIN_SetLaunchMode(const D2CmdParamsStrc* pParams, int nUnused)
{
    for (unsigned int i = 0; i < 7; ++i)
    {
        if (gaszLaunchModeNames[i] && !_stricmp(gaszLaunchModeNames[i], pParams->szValue))
        {
// build: symbol ?gnClientLaunchState@* 0x0070EE4C
            gnClientLaunchState = i;
            return 1;
        }
    }
    return WINMAIN_ShowCommandLineHelp(pParams, nUnused);
}

// 0x0044B6B0
int __stdcall WINMAIN_ProcessCommandLine(void* pArg)
{
    char szCmdLine[0x104];
    SCmdRegisterArgList(gaCommandLineArgs, 8);
    for (unsigned int i = 0; i < sizeof(gpfnLaunchInit) / sizeof(gpfnLaunchInit[0]); ++i)
    {
        if (!gpfnLaunchInit[i]())
        {
            return 0;
        }
    }

    if (!GAME_RunInitHandlers(pArg))
    {
        return 0;
    }

    if (SRegLoadString("Diablo II", "Default Command Line", 0, szCmdLine, sizeof(szCmdLine)))
    {
        SCmdProcess(szCmdLine, 0, WINMAIN_HandleExtraArgument, WINMAIN_HandleArgumentError);
    }

    {
        unsigned long nSize = 0xF;
        if (!gszClientCharName[0] && !GetUserNameA(gszClientCharName, &nSize))
        {
// build: symbol ?gszStringFormat@* 0x006FFC58
            wsprintfA(gszClientCharName, gszStringFormat, "noname");
        }
    }
    return 1;
}

extern int (__cdecl* gpfnLaunchStates[])(); // 0x0070EE54

// 0x0044B8A0
int __stdcall WINMAIN_LauncherRun(void* hInstance, D2ConfigStrc* pRecord)
{
    gpClientConfig = pRecord;
// build: symbol ?ERRORMANAGER_FreeUnusedPoolBlocks@* 0x00409B80
    ERRORMANAGER_FreeUnusedPoolBlocks(0);
    FOG_SetMemoryPoolSystemMode(0, 1);
    ghLaunchInstance = hInstance;
    GetModuleFileNameA(hInstance, gszModulePath, 0x104);
    if (!WINMAIN_ProcessCommandLine(pRecord))
        return 0;
    if (!GAME_LoadLngModule())
        return 0;
    D2Win_10015();
    D2Win_10014_SetWndProc((WNDPROC)SCMD_WindowProc);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (!STRTABLE_LoadStringTables(sub_004FAC80(FOG_IsExpansion()), 0))
        return 0;
    int nLanguage;
// build: symbol ?STRTABLE_GetLanguageInfoField@* 0x00525260
    STRTABLE_GetLanguageInfoField(&nLanguage, 0);
    DATATBLS_LoadAllTxts(sub_004FAC80(0), pRecord->dwGameType == 6);
// build: symbol ?gnClientLaunchState@* 0x0070EE4C
    gnClientLaunchState = 3;
// build: symbol ?gbExitApplication@* 0x0070EE8C
    gbExitApplication = 1;
    while (gnClientLaunchState != 1)
    {
        gnClientLaunchState = gpfnLaunchStates[gnClientLaunchState]();
        D2_ASSERT(gnClientLaunchState < 7, 0x28E);
        D2_ASSERT(gnClientLaunchState > 0, 0x28F);
    }
    sub_004FA550();
    DATATBLS_UnloadAllBins();
// build: symbol ?STRTABLE_UnloadStringTables@* 0x00524E40
    STRTABLE_UnloadStringTables();
    GAME_FreeLngModule();
    PROFCORE_WriteProfileCounters();
    GAME_ShutdownIfActive();
    int nResult;
    if (gbExitApplication)
    {
        nResult = 0;
    }
    else
    {
        switch (pRecord->dwGameType)
        {
        case 0:
        case 8:
        case 9:
            nResult = 4;
            break;
        case 2:
        case 3:
        case 6:
        case 7:
            nResult = 3;
            break;
        default:
            gnLaunchResult = 4;
            return 4;
        }
    }
    gnLaunchResult = nResult;
    return nResult;
}












void __cdecl RECORD_StartPlayback(); // 0x004518E0

extern "C" void __cdecl RECORD_RegisterLngArgument(); // 0x00451260
extern "C" void __cdecl GAME_RunGameSession(); // 0x0044F360
extern "C" void __cdecl GAME_PushState(); // 0x0044D080
extern "C" void __cdecl GAME_ShutdownClient(); // 0x0044D550
extern "C" void __cdecl WINMAIN_StartSession(); // 0x0044BC30
extern "C" void __cdecl WINMAIN_StopSession(); // 0x0044BD90

#pragma pack(push, 1)
struct d2data_006D5BE0_t
{
    const void* p0;
    const void* p1;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EE54_t
{
    unsigned char b0[8];
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EE10_t
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

extern "C" const struct d2data_006D5BE0_t gData_006D5BE0; // 0x006D5BE0
extern "C" struct d2data_0070EE54_t gData_0070EE54; // 0x0070EE54
extern "C" struct d2data_0070EE10_t gData_0070EE10; // 0x0070EE10

extern "C" const struct d2data_006D5BE0_t gData_006D5BE0 = {
    (const void*)(unsigned int)&RECORD_RegisterLngArgument,
    (const void*)"Available command line options:\n  -set[default command line]\t\tSet new default command line string\n  -lng[lngfile]\t\t\tUse \"lngfile\" for language resources\n"
}; // 0x006D5BE0

extern const D2CmdArgStrc gaCommandLineArgs[8] = {
    { 0, 0xFFFFFFFF, (const char *)"?", (void*)(unsigned int)&WINMAIN_ShowCommandLineHelp },
    { 0, 0xFFFFFFFF, (const char *)"h", (void*)(unsigned int)&WINMAIN_ShowCommandLineHelp },
    { 0, 0xFFFFFFFF, (const char *)"help", (void*)(unsigned int)&WINMAIN_ShowCommandLineHelp },
    { 0x20000, 0xFFFFFFFF, (const char *)"set", (void*)(unsigned int)&WINMAIN_SaveDefaultCmdLine },
    { 0x20000, 0xFFFFFFFF, (const char *)"mode", (void*)(unsigned int)&WINMAIN_SetLaunchMode },
    { 0, 0xFFFFFFFF, (const char *)"c", (void*)(unsigned int)&WINMAIN_RunMemoryTest },
    { 0, 0xFFFFFFFF, (const char *)"r", (void*)(unsigned int)&WINMAIN_HandleToggleFlagsOption },
    { 0, 0xFFFFFFFF, (const char *)"p", (void*)(unsigned int)&WINMAIN_HandlePlaybackOption }
}; // 0x006D5BE8

extern const char* gaszLaunchModeNames[7] = { 0, 0, "Game" }; // 0x0070EE70

extern char gszServerIP[260] = "207.82.87.243"; // 0x0070EF20

extern char gszBattleNetIP[264] = {
    50, 48, 55, 46, 56, 50, 46, 56, 55, 46, 49, 51, 57, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1
}; // 0x0070F028

extern int gnClientLaunchState = 3; // 0x0070EE4C

extern "C" struct d2data_0070EE54_t gData_0070EE54 = {
    { 0x00 },
    (const void*)(unsigned int)&GAME_RunGameSession,
    (const void*)(unsigned int)&GAME_PushState,
    (const void*)(unsigned int)&GAME_ShutdownClient,
    (const void*)(unsigned int)&WINMAIN_StartSession,
    (const void*)(unsigned int)&WINMAIN_StopSession
}; // 0x0070EE54

extern int gbExitApplication = 1; // 0x0070EE8C

extern const char* gpszDefaultCaption_0070EE50 = "Diablo II"; // 0x0070EE50

extern "C" struct d2data_0070EE10_t gData_0070EE10 = {
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
}; // 0x0070EE10
