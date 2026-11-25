#include "D2MCPClient.h"

#include "D2GameTypes.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                    // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                               // 0x0040B380

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

char* gpMcpPacket; // 0x007992F4

extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __fastcall WINMAIN_SendMcpCharCreate(int nA, int nB, int nC); // 0x0044A2E0

int __fastcall WINMAIN_SendMcpCharLogon(int nA); // 0x0044A380

void* ghThread;                                                                                    // 0x007992A4

int gnResult_00798F58; // 0x00798F58

char gszText_00798F60[28]; // 0x00798F60

char gszText_00799294[4]; // 0x00799294

unsigned short __cdecl CHATDLG_GetRequestId();                                                         // 0x00449BD0

void __cdecl CHATDLG_ClearReply();                                                                     // 0x00449D60

void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50

void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0

void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40

int __stdcall CHATDLG_RequestCharLogon(const char* szName);                                                    // 0x00449E10

void __stdcall D2QSSOCKET_DestroyRecord(void* pConnection);                                                             // 0x006BC780

extern unsigned short gwMcpReplyRequestId;                                                                 // 0x00798F80

extern char gszMcpGameServerIP[]; // 0x007992CC

extern int gnMcpGameToken; // 0x00798FB0

extern int gdwMcpGameHash; // 0x00798F88

int gbMcpCharCreateReceived; // 0x007992E8

int gbMcpCharLogonReceived; // 0x007992E0

int gbMcpCharDeleteReceived; // 0x00799298

int gbMcpCharUpgradeReceived; // 0x007992F0

int gbMcpPacket0BReceived; // 0x00799100

int gbMcpPacket0CReceived; // 0x007992A0

char gabMcpReply[4]; // 0x00799108

int gbMcpPacket0DReceived; // 0x007992A8

int gbMcpPacket0FReceived; // 0x00798F5C

int gbMcpServerAddressReceived; // 0x00798F84

int gnMcpCreateQueuePosition; // 0x00799104

int gbMcpCreateQueued; // 0x00798F7C

void* gpMcpConnection; // 0x00798FB4

struct D2QSSOCKET_SetPacketFormat;

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

typedef int (__fastcall* D2LaunchPacketHandler)(const unsigned char* pData, unsigned int nSize, int nArg);

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long nMilliseconds); // 0x006CC230

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds);                         // 0x006CC258

extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* pAttributes, unsigned long nStackSize, unsigned long (__stdcall* pfnStart)(void*), void* pParameter, unsigned long nFlags, unsigned long* pThreadId); // 0x006CC250

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __fastcall FOG_SOCKET_GetPeerName(FSafeSock* pSafeSock, void* pAddress, int* pnLength); // 0x0040DEE0

int __fastcall FOG_SOCKET_GetError(FSafeSock* pSafeSock, unsigned long* pFogError, unsigned long* pWSALastError); // 0x0040E0B0

int __fastcall WINMAIN_SendMcpStartup(D2LaunchThreadRecordStrc* pRecord);                                // 0x0044A1D0

int __fastcall WINMAIN_DispatchConnectPacket(const unsigned char* pData, unsigned int nSize, int nArg);         // 0x0044B1C0

void __stdcall D2QSSOCKET_SetPacketHandler(void* pConnection, D2LaunchPacketHandler pfnHandler, int nArg);      // 0x006BC010

int __stdcall FOG_ConnectionSend(void* pConnection, const char* pData, int nSize);                           // 0x006BC0B0

void __stdcall D2QSSOCKET_ConnectAndWait(void* pConnection);                                                       // 0x006BC5A0

void __stdcall D2QSSOCKET_Close(void* pConnection);                                                       // 0x006BC680

D2QSSOCKET_SetPacketFormat* __stdcall D2QSSOCKET_CreateRecord(const char* szName, int nValue, const char* szLabel); // 0x006BC6A0

FSafeSock* __stdcall D2QSSOCKET_GetSafeSock(void* pConnection);                                          // 0x006BC810

D2LaunchThreadRecordStrc gtThreadRecord;                                                           // 0x00798FB8

#define gnServerAddress_00798FC8 (gtThreadRecord.nData[4])

#define gnServerPort_00798FCC (gtThreadRecord.nData[5])

int gnValue_0079929C;                                                                                       // 0x0079929C

void* ghConnectEvent;                                                                              // 0x007992EC

// 0x00449AC0
int __cdecl GAME_GetWaitHandle()
{
    return (int)ghThread;
}

// 0x00449AD0
void __cdecl D2MCPClientCloseMCP()
{
    if (gpMcpConnection)
    {
        D2QSSOCKET_DestroyRecord(gpMcpConnection);
        gpMcpConnection = 0;
    }
    if (ghThread)
    {
        WaitForSingleObject(ghThread, 0xFFFFFFFF);
        CloseHandle(ghThread);
        ghThread = 0;
    }
    if (ghConnectEvent)
    {
        CloseHandle(ghConnectEvent);
        ghConnectEvent = 0;
    }
}

// 0x00449B30
int __cdecl MCPCONNECT_QueryAddress()
{
    FSafeSock* pSafeSock = D2QSSOCKET_GetSafeSock(gpMcpConnection);
    if (!pSafeSock)
        return 0;
    D2LaunchAddressStrc tAddress;
    int nSize = sizeof(tAddress);
    return FOG_SOCKET_GetPeerName(pSafeSock, &tAddress, &nSize);
}

unsigned short __stdcall FOG_ConnectionReceive(void* pConnection, char* pBuffer, int nSize); // 0x006BC120
int __fastcall GAME_DispatchMcpPacket(const char* pPacket, unsigned int nSize); // 0x0044B190
extern int (__cdecl* const gpfnLaunchInit[1])(); // 0x006D5BE0
extern int (__cdecl* gpfnLaunchStates[])(); // 0x0070EE54

// 0x00449B70
int __cdecl WINMAIN_PollMcpConnection()
{
    char szBuffer[0x400];
    if (!gpMcpConnection)
    {
        return 0;
    }

    const unsigned short nLength = FOG_ConnectionReceive(gpMcpConnection, szBuffer, sizeof(szBuffer));
    if (nLength)
    {
        GAME_DispatchMcpPacket(szBuffer, nLength);
    }
    return 1;
}

// 0x00449BC0
void* __cdecl GAME_GetMcpGameServerIP()
{
    return gszMcpGameServerIP;
}

// 0x00449BD0
unsigned short __cdecl CHATDLG_GetRequestId()
{
    return gwMcpReplyRequestId;
}

// 0x00449BE0
int __cdecl GAME_GetMcpGameToken()
{
    return gnMcpGameToken;
}

// 0x00449BF0
void __stdcall CHATDLG_SetMcpResult(int nValue)
{
    gnValue_0079929C = nValue;
}

// 0x00449C00
int __cdecl GAME_GetConnectError()
{
    return gnValue_0079929C;
}

// 0x00449C10
int __cdecl GAME_IsMcpCharCreateReceived()
{
    return gbMcpCharCreateReceived;
}

// 0x00449C20
void __stdcall CHATDLG_SetCharCreateReceived(int nValue)
{
    gbMcpCharCreateReceived = nValue;
}

// 0x00449C30
int __cdecl GAME_IsMcpCharLogonReceived()
{
    return gbMcpCharLogonReceived;
}

// 0x00449C40
void __stdcall CHATDLG_SetCharLogonReceived(int nValue)
{
    gbMcpCharLogonReceived = nValue;
}

// 0x00449C50
int __cdecl GAME_IsMcpCharDeleteReceived()
{
    return gbMcpCharDeleteReceived;
}

// 0x00449C60
void __stdcall CHATDLG_SetCharDeleteReceived(int nValue)
{
    gbMcpCharDeleteReceived = nValue;
}

// 0x00449C70
int __cdecl GAME_IsMcpCharUpgradeReceived()
{
    return gbMcpCharUpgradeReceived;
}

// 0x00449C80
void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue)
{
    gbMcpCharUpgradeReceived = nValue;
}

// 0x00449C90
void __stdcall sub_00449C90_SetValue(int nValue)
{
    gbMcpPacket0BReceived = nValue;
}

// 0x00449CA0
int __cdecl sub_00449CA0()
{
    return gbMcpPacket0BReceived;
}

// 0x00449CB0
int __cdecl sub_00449CB0()
{
    return gbMcpPacket0CReceived;
}

// 0x00449CC0
void __stdcall sub_00449CC0_SetValue(int nValue)
{
    gbMcpPacket0CReceived = nValue;
}

// 0x00449CD0
int __stdcall CHATDLG_GetMcpTexts(char* szText1, char* szText2)
{
    strcpy(szText1, gszText_00799294);
    strcpy(szText2, gszText_00798F60);
    return gnResult_00798F58;
}

// 0x00449D10
void __stdcall CHATDLG_SetMcpTexts(int nResult, const char* szText1, const char* szText2)
{
    strcpy(gszText_00799294, szText1);
    strcpy(gszText_00798F60, szText2);
    gnResult_00798F58 = nResult;
}

// 0x00449D50
void* __cdecl GAME_GetMcpReply()
{
    return gabMcpReply;
}

// 0x00449D60
void __cdecl CHATDLG_ClearReply()
{
    memset(gabMcpReply, 0, 0x18C);
}

// 0x00449D80
int __cdecl sub_00449D80()
{
    return gbMcpPacket0DReceived;
}

// 0x00449D90
void __stdcall sub_00449D90_SetValue(int nValue)
{
    gbMcpPacket0DReceived = nValue;
}

// 0x00449DA0
int __cdecl sub_00449DA0()
{
    return gbMcpPacket0FReceived;
}

// 0x00449DB0
void __stdcall sub_00449DB0_SetValue(int nValue)
{
    gbMcpPacket0FReceived = nValue;
}

// 0x00449DC0
int __cdecl GAME_IsMcpServerAddressReceived()
{
    return gbMcpServerAddressReceived;
}

// 0x00449DD0
void __stdcall sub_00449DD0_SetValue(int nValue)
{
    gbMcpServerAddressReceived = nValue;
}

// 0x00449DE0
int __cdecl GAME_GetMcpGameHash()
{
    return gdwMcpGameHash;
}

// 0x00449DF0
int __stdcall CHATDLG_RequestCharCreate(int nA, int nB, int nC)
{
    return WINMAIN_SendMcpCharCreate(nA, nB, nC);
}

// 0x00449E10
int __stdcall CHATDLG_RequestCharLogon(int nA)
{
    return WINMAIN_SendMcpCharLogon(nA);
}

// 0x00449E20
int __cdecl GAME_GetMcpCharLevel()
{
    return gnMcpCreateQueuePosition;
}

// 0x00449E30
void __stdcall sub_00449E30_SetValue(int nValue)
{
    gnMcpCreateQueuePosition = nValue;
}

// 0x00449E40
int __cdecl GAME_IsMcpCreateQueued()
{
    return gbMcpCreateQueued;
}

// 0x00449E50
void __stdcall sub_00449E50_SetValue(int nValue)
{
    gbMcpCreateQueued = nValue;
}

// 0x00449E60
int __cdecl sub_00449E60()
{
    return (int)gpMcpPacket;
}

// 0x00449E70
void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize)
{
    if (gpMcpPacket)
    {
        FOG_Free(gpMcpPacket, ".\\Src\\McpConnect.cpp", 0x21E, 0);
        gpMcpPacket = 0;
    }
    if (!nSize)
        return;
    gpMcpPacket = (char*)FOG_Alloc(nSize, ".\\Src\\McpConnect.cpp", 0x227, 0);
    memcpy(gpMcpPacket, pData, nSize);
    if (*pData == 0x17)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 1) < 0x100, 0x233);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 3) < 0x100, 0x234);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 5) < 0x100, 0x235);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 7) < 0x100, 0x236);
    }
    else if (*pData == 0x19)
    {
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 1) < 0x100, 0x242);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 3) < 0x100, 0x243);
        D2_ASSERT(*(unsigned short*)(gpMcpPacket + 5) < 0x100, 0x244);
        const unsigned short nCount = *(unsigned short*)(gpMcpPacket + 7);
        D2_ASSERT(nCount < 0x100, 0x245);
        const char* p = gpMcpPacket + 9;
        for (int i = 0; i < nCount; i++)
        {
            p += 4;
            while (*p++);
            while (*p++);
        }
    }
    else
    {
        D2_ASSERT(0, 0x254);
    }
}

// 0x00449FB0
void __stdcall MCPCONNECT_WaitConnect(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghConnectEvent)
        ghConnectEvent = CreateEventA(0, 0, 0, 0);
    if (WINMAIN_SendMcpStartup(pRecord) == -1)
    {
        gnValue_0079929C = 0xB;
        return;
    }
    const unsigned long dwEndTick = GetTickCount() + 60000;
    for (;;)
    {
        if (!MCPCONNECT_QueryAddress())
            break;
        if (GetTickCount() >= dwEndTick)
            break;
        const unsigned long dwResult = WaitForSingleObject(ghConnectEvent, 0);
        if (dwResult == 0)
            return;
        if (dwResult != 0x102)
            break;
        Sleep(10);
    }
    gnValue_0079929C = 2;
}

// 0x0044A070
int __cdecl MCPCONNECT_ConnectThread()
{
// build: symbol ?FOG_inet_ntoa@* 0x0040E080
    const char* szAddress = FOG_inet_ntoa(gnServerAddress_00798FC8);
    gnValue_0079929C = 0;
    void* pConnection = D2QSSOCKET_CreateRecord(szAddress, gnServerPort_00798FCC, "clt->mcp");
    gpMcpConnection = pConnection;
    D2QSSOCKET_SetPacketHandler(pConnection, WINMAIN_DispatchConnectPacket, 0);
    D2QSSOCKET_ConnectAndWait(pConnection);
    unsigned long nFogError = 0;
    unsigned long nWSALastError;
    FSafeSock* pSafeSock = D2QSSOCKET_GetSafeSock(pConnection);
    if (pSafeSock)
    {
        FOG_SOCKET_GetError(pSafeSock, &nFogError, &nWSALastError);
        if (nFogError == 0)
        {
            if (pConnection != gpMcpConnection)
            {
                D2QSSOCKET_Close(pConnection);
                return 0;
            }
            char nValue = 1;
            FOG_ConnectionSend(pConnection, &nValue, 1);
            MCPCONNECT_WaitConnect(&gtThreadRecord);
            return gnValue_0079929C == 0;
        }
    }
    gnValue_0079929C = 2;
    return 0;
}

// 0x0044A130
void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord)
{
    if (!ghThread)
    {
        gtThreadRecord = *pRecord;
        unsigned long nThreadId;
        ghThread = CreateThread(0, 0, (unsigned long (__stdcall*)(void*))MCPCONNECT_ConnectThread, 0, 0, &nThreadId);
    }
}

#include "gen/data/Source/D2MCPClient/Src/McpConnect.inc"
