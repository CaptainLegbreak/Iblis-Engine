#pragma once
// The interface table the launcher hands the game in D2ConfigStrc::pComInterface (0x225).
// D2Launch fills and calls it, the client keeps the pointer at 0x007A05F4, Storm calls it on shutdown.

#include "D2Check.h"

struct D2BnetChatPacketStrc;
struct D2ConfigStrc;
struct D2FuncRecordStrc;
struct D2LaunchPayloadStrc;
struct D2MenuListStrc;
struct D2StatusStrc;

typedef int (__fastcall* D2BnNewsCallback)(unsigned long, unsigned long);

struct D2ComInterfaceStrc
{
    int (__fastcall* pfnInitialize)(D2ConfigStrc*); // 0x00
    void* (__fastcall* pfnOpenBNetConnection)(void); // 0x04
    void (__fastcall* pfnLogon)(char*, char*); // 0x08
    int (__fastcall* pfnGetLogonInfo)(void); // 0x0C
    union
    {
        void (__fastcall* pfnCloseBNetConnection)(void); // 0x10
        int (__fastcall* pfnCloseBNetConnectionResult)(void);
    };
    void (__fastcall* pfnChatCommand)(const char*); // 0x14
    char* (__stdcall* pfnGetUniqueName)(void); // 0x18
    int (__fastcall* pfnJoinChannel)(const char* szChannel, int bForce, int bOpen); // 0x1C
    const void* (__fastcall* pfnGetChannelList)(int bOpen); // 0x20
    int (__fastcall* pfnBnMessQueueRead)(int*, D2BnetChatPacketStrc*); // 0x24
    int (__fastcall* pfnBnMessageQueueGetLastError)(D2StatusStrc*); // 0x28
    int (__fastcall* pfn0x2C)(const char* szFileName, unsigned int nRequestId); // 0x2C
    int (__stdcall* pfnCheckAd)(void); // 0x30
    void (__fastcall* pfnRefreshGame)(char*, char*, char*, int); // 0x34
    void* (__fastcall* pfnGetGamesList)(const char* szGameName, const char* szGamePassword, int nUnused1, int nUnused2); // 0x38
    int (__fastcall* pfnNotifyJoinedGame)(const char* szGameName, const char* szGamePassword); // 0x3C
    D2MenuListStrc* (__fastcall* pfnSendRealmList)(int); // 0x40
    D2LaunchPayloadStrc* (__fastcall* pfnLogonRealm)(const char*, const char*); // 0x44
    int (__fastcall* pfn0x48)(int*); // 0x48
    int (__fastcall* pfnGetPatchState)(void); // 0x4C
    void (__fastcall* pfn0x50)(const char*, int); // 0x50
    int (__fastcall* pfnEnterChat)(const char* szName, const char* szStats, int nUnused, const char* szChannel, char nFlags); // 0x54
    int (__stdcall* pfnLeaveChat)(void); // 0x58
    int (__stdcall* pfnGetVersion)(void); // 0x5C
    void (__fastcall* pfnCreateAccount)(char*, char*); // 0x60
    int (__fastcall* pfnGetCreateAccountResult)(int*); // 0x64
    int (__fastcall* pfnIsSocketConnected)(void); // 0x68
    int (__fastcall* pfnOnAdClick)(unsigned int nAdId, int nFlags); // 0x6C
    int (__fastcall* pfn0x70)(void); // 0x70
    int (__fastcall* pfnBattleWriteUserData)(const char* szAccount, unsigned int nKeys, const char* const* ppKeys, const char* const* ppValues); // 0x74
    int (__fastcall* pfnBattleRequestReadUserData)(const char* szAccount, unsigned int nKeys, unsigned int nCookie, const char* const* ppKeys); // 0x78
    int (__fastcall* pfnGetBattleReadUserData)(unsigned int nKeys, unsigned int nCookie, char* const* ppValues, const unsigned int* pLengths); // 0x7C
    void (__fastcall* pfnGetConnectionState)(int*); // 0x80
    void (__cdecl* pfnLogWrite)(const char* szFormat, ...); // 0x84
    int (__cdecl* pfnStartLogging)(int nArg1, int nArg2); // 0x88
    int (__fastcall* pfnGetCreateGameResult)(int* pResult); // 0x8C
    void (__cdecl* pfnSendKeepAlivePacket)(void); // 0x90
    int (__stdcall* pfn0x94)(void); // 0x94
    union
    {
        D2FuncRecordStrc* (__cdecl* pfnGetBnGatewayAccess)(void); // 0x98
        int (__fastcall* pfnGetBnGatewayAccessResult)(void);
    };
    void (__fastcall* pfnChangePassword)(char*, char*, char*); // 0x9C
    int (__fastcall* pfnGetChangePasswordResult)(int*); // 0xA0
    const char* (__fastcall* pfnQueryAdUrl)(unsigned int nAdId); // 0xA4
    int (__fastcall* pfnLoadBNetNews)(D2BnNewsCallback pfnOnNews, int (__cdecl* pfnOnDone)(void)); // 0xA8
    int (__stdcall* pfnFreeBNetNews)(void); // 0xAC
    char (__stdcall* pfnGetBuild)(void); // 0xB0
    int (__fastcall* pfn0xB4)(void); // 0xB4
    void (__fastcall* pfnSetEmail)(char*); // 0xB8
    int (__fastcall* pfnResetPassword)(char*, char*); // 0xBC
    int (__fastcall* pfnChangeEmail)(char*, char*, char*); // 0xC0
    void (__stdcall* pfnLeaveGame)(void); // 0xC4
};

D2_CHECK_SIZE(D2ComInterfaceStrc, 0xC8);
D2_CHECK_OFFSET(D2ComInterfaceStrc, pfnIsSocketConnected, 0x68);
D2_CHECK_OFFSET(D2ComInterfaceStrc, pfnGetBnGatewayAccess, 0x98);
