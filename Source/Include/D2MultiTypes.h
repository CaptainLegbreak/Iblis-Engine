#pragma once
// D2Multi: launch character records, the launch function tables and control init records.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2ComInterface.h"

struct D2FuncRecordStrc;
struct D2LaunchGameListStrc;
struct D2LaunchMsgStrc;
struct D2LaunchPayloadStrc;
struct D2LaunchRecord3Strc;
struct D2MenuListStrc;
struct D2StatusStrc;
struct Unicode;
struct SMSGHANDLER_PARAMS;
struct D2LaunchFuncsStrc;
struct D2WinControlInitStrc;
struct D2ConfigStrc;
struct D2CompositeStrc;
struct D2MultiChannelUserStrc;
struct D2LaunchGameRecStrc;

struct D2LaunchFuncsStrc
{
    void (__fastcall* pfnInitialize)(D2ConfigStrc* pConfig); // 0x00
    void* (__stdcall* pfnOpenBNetConnection)(void); // 0x04
    int (__fastcall* pfnLogon)(const char*, const char*); // 0x08
    int (__stdcall* pfnGetLogonInfo)(void); // 0x0C
    void (__fastcall* pfnCloseBNetConnection)(void); // 0x10
    int (__fastcall* pfnChatCommand)(void*); // 0x14
    const char* (__cdecl* pfnGetUserName)(void); // 0x18
    int (__fastcall* pfnJoinChannel)(int, int, int); // 0x1C
    const char* (__fastcall* pfnGetChannelList)(int); // 0x20
    int (__fastcall* pfnGetMessage)(int*, D2LaunchMsgStrc*); // 0x24
    int (__fastcall* pfnBnMessageQueueGetLastError)(unsigned long* pErrorInfo); // 0x28
    int (__fastcall* pfn0x2C)(const char*, unsigned int); // 0x2C
    void (__fastcall* pfnCheckAd)(void); // 0x30
    int (__fastcall* pfnRefreshGame)(char*, char*, const char*, int); // 0x34
    D2LaunchGameListStrc* (__fastcall* pfQueryGames)(const char*, const char*, int, int); // 0x38
    int (__fastcall* pfnNotifyJoinedGame)(char*, char*); // 0x3C
    int pfnSendRealmList; // 0x40
    D2LaunchPayloadStrc* (__fastcall* pfnLogonRealm)(char*, const char*); // 0x44
    int (__fastcall* pfn0x48)(unsigned long* pValue); // 0x48
    int (__stdcall* pfnGetPatchState)(void); // 0x4C
    unsigned int (__fastcall* pfn0x50)(const char*, unsigned int); // 0x50
    void (__fastcall* pfnEnterChat)(char*, char*, int, char*, int); // 0x54
    void (__fastcall* pfnLeaveChat)(void); // 0x58
    int (__stdcall* pfnGetVersion)(void); // 0x5C
    int (__fastcall* pfnCreateAccount)(const char*, const char*); // 0x60
    int (__fastcall* pfnGetCreateAccountResult)(unsigned long* pResult); // 0x64
    int (__fastcall* pfnIsSocketConnected)(void); // 0x68
    void (__fastcall* pfnOnAdClick)(void*, int); // 0x6C
    void (__stdcall* pfn0x70)(void); // 0x70
    int (__fastcall* pfnBattleWriteUserData)(int, int, void*, D2LaunchRecord3Strc*); // 0x74
    int (__fastcall* pfnBattleRequestReadUserData)(int, int, int, void*); // 0x78
    int (__fastcall* pfnGetBattleReadUserData)(int, int, void*, D2LaunchRecord3Strc*); // 0x7C
    int (__fastcall* pfnGetConnectionState)(unsigned long* pState); // 0x80
    void (__cdecl* pfnLogWrite)(const char*, ...); // 0x84
    int (__cdecl* pfnStartLogging)(int, int); // 0x88
    int (__fastcall* pfnGetCreateGameResult)(int*); // 0x8C
    int (__stdcall* pfnSendKeepAlivePacket)(void); // 0x90
    int (__stdcall* pfn0x94)(void); // 0x94
    void* (__stdcall* pfnGetBnGatewayAccess)(void); // 0x98
    int (__fastcall* pfnChangePassword)(const char*, const char*, const char*); // 0x9C
    int (__fastcall* pfnGetChangePasswordResult)(int* pResult); // 0xA0
    const char* (__fastcall* pfnQueryAdUrl)(void*); // 0xA4
    void (__fastcall* pfnLoadBNetNews)(void (__fastcall*)(void*, void*), void (__cdecl*)(void)); // 0xA8
    void (__fastcall* pfnFreeBNetNews)(void); // 0xAC
};

struct D2WinControlInitStrc
{
    int nType; // 0x00
    int nX; // 0x04
    int nY; // 0x08
    int nWidth; // 0x0C
    int nHeight; // 0x10
    int nArg; // 0x14
    int nStringId; // 0x18
    void* ppCellFile; // 0x1C
    int anArgs[4]; // 0x20
};

#pragma pack(push, 1)
struct D2ConfigStrc
{
    int bIsExpansion; // 0x00
    int bCrashApp; // 0x04
    unsigned char bWindow; // 0x08
    unsigned char bNoFixedAspect; // 0x09
    unsigned char b3DFX; // 0x0A
    unsigned char bOpenGL; // 0x0B
    unsigned char bRave; // 0x0C
    unsigned char bD3D; // 0x0D
    unsigned char bPerspective; // 0x0E
    unsigned char bQuality; // 0x0F
    int dwGamma; // 0x10
    unsigned char bVSync; // 0x14
    int dwFramerate; // 0x15
    int dwGameType; // 0x19
    unsigned short wJoinID; // 0x1D
    char szGameName[24]; // 0x1F
    char szServerIP[24]; // 0x37
    char szBattleNetIP[24]; // 0x4F
    char szMCPIP[24]; // 0x67
    unsigned char unused0x7F[4]; // 0x7F
    unsigned char bNoPK; // 0x83
    unsigned char bOpenC; // 0x84
    unsigned char bAmazon; // 0x85
    unsigned char bPaladin; // 0x86
    unsigned char bSorceress; // 0x87
    unsigned char bNecromancer; // 0x88
    unsigned char bBarbarian; // 0x89
    unsigned char bDruid; // 0x8A
    unsigned char bAssassin; // 0x8B
    unsigned char bInvincible; // 0x8C
    char szAccount[24]; // 0x8D
    union
    {
        struct
        {
            char szPassword[256]; // 0xA5
            unsigned char unused0x1A5; // 0x1A5
            unsigned short unused0x1A6; // 0x1A6
            int unused0x1A8[17]; // 0x1A8
            unsigned char unused0x1EC; // 0x1EC
        };
        struct
        {
            unsigned int adwSecret[6]; // 0xA5
            union
            {
                char szCharName[24]; // 0xBD
                char szJoinGameName[24];
            };
            union
            {
                char szRealm[24]; // 0xD5
                char szGamePassword[24];
            };
            char aDataED[0x100]; // 0xED
        };
    };
    unsigned char nCTemp; // 0x1ED
    union
    {
        char nMode; // 0x1EE
        unsigned char nClass;
    };
    union
    {
        char aFlags1EF[2]; // 0x1EF
        unsigned short wFlags1EF;
    };
    unsigned char bNoMonsters; // 0x1F1
    int dwMonsterClass; // 0x1F2
    unsigned char bMonsterInfo; // 0x1F6
    int dwMonsterDebug; // 0x1F7
    unsigned char bRare; // 0x1FB
    unsigned char bUnique; // 0x1FC
    unsigned char unused0x1FD[2]; // 0x1FD
    int dwAct; // 0x1FF
    unsigned char bNoPreload; // 0x203
    unsigned char bDirect; // 0x204
    unsigned char bLowEnd; // 0x205
    unsigned char bNoCompress; // 0x206
    unsigned char aWord207[2]; // 0x207
    union
    {
        char aState209[4]; // 0x209
        unsigned int dwFlags209;
        int nValue209;
    };
    unsigned char nArenaTemplate; // 0x20D
    unsigned char unk0x20E; // 0x20E
    unsigned char unk0x20F; // 0x20F
    char nByte210; // 0x210
    int (__cdecl* pfnAllowExpansion)(); // 0x211
    unsigned char bTxt; // 0x215
    unsigned char bLog; // 0x216
    unsigned char bMsgLog; // 0x217
    unsigned char bSafeMode; // 0x218
    char bFlag219; // 0x219
    int dwSeed; // 0x21A
    unsigned char bCheats; // 0x21E
    unsigned char bTeen; // 0x21F
    unsigned char bNoSound; // 0x220
    unsigned char bQuests; // 0x221
    unsigned char unused0x222; // 0x222
    char bFlag223; // 0x223
    unsigned char bSoundBackground; // 0x224
    D2ComInterfaceStrc* pComInterface; // 0x225
    int dwGameHash; // 0x229
    union
    {
        struct
        {
            char nByte22D; // 0x22D
            unsigned short unused0x22E; // 0x22E
            int unused0x230[5]; // 0x230
            unsigned char unused0x244; // 0x244
        };
        char szRealm0x22D[0x18]; // 0x22D
    };
    char szText0x245[16]; // 0x245
    unsigned char unused0x255; // 0x255
    unsigned short unused0x256; // 0x256
    int unused0x258; // 0x258
    unsigned char unused0x25C; // 0x25C
    char szText0x25D[16]; // 0x25D
    unsigned char unused0x26D; // 0x26D
    unsigned short unused0x26E; // 0x26E
    int unused0x270[59]; // 0x270
    unsigned char unused0x35C; // 0x35C
    char bRegistryMode; // 0x35D
    union
    {
        char nByte35E; // 0x35E
        char nStartMode;
    };
    char bIntroPlayed; // 0x35F
    unsigned char unused0x360; // 0x360
    char szRealm0x361[32]; // 0x361
    char szRealm0x381[32]; // 0x381
    char szText0x3A1[16]; // 0x3A1
    unsigned char nComponentColors[16]; // 0x3B1
    unsigned char nLevel; // 0x3C1
    char nByte3C2; // 0x3C2
    unsigned int dwPasswordHash; // 0x3C3
    int nPasswordLength; // 0x3C7
    union
    {
        unsigned char aFlags3CB[2]; // 0x3CB
        unsigned short wFlags3CB;
    };
};
#pragma pack(pop)


struct D2MultiChannelUserStrc
{
    unsigned int dwCode; // 0x00
    char szName[50]; // 0x04
    char szText[16]; // 0x36
    char szRealm[32]; // 0x46
    unsigned char aComponents[16]; // 0x66
    unsigned char aColors[16]; // 0x76
    unsigned char nClass; // 0x86
    unsigned char pad0x87; // 0x87
    unsigned short wLevel; // 0x88
    unsigned short wFlags; // 0x8A
    unsigned short wW8C; // 0x8C
    unsigned short pad0x8E; // 0x8E
    unsigned int dwFlags; // 0x90
    unsigned char nB94; // 0x94
    unsigned char nB95; // 0x95
    unsigned char nB96; // 0x96
    char szS97[5]; // 0x97
    D2CompositeStrc* pComposite; // 0x9C
    int bFlagA0; // 0xA0
    int bFlagA4; // 0xA4
    int bFlagA8; // 0xA8
    int bFlagAC; // 0xAC
    D2MultiChannelUserStrc* pNext; // 0xB0
};

struct D2LaunchGameRecStrc
{
    unsigned char unused0x00; // 0x00
    union
    {
        char szName[48]; // 0x01
        struct
        {
            char szShortName[16]; // 0x01
            char szDesc[32]; // 0x11
        };
    };
    char wValue0x31[2]; // 0x31
    char wValue0x33[2]; // 0x33
    unsigned char unused0x35; // 0x35
    unsigned char unused0x36; // 0x36
    char nAddress0x37[4]; // 0x37
};

struct D2LaunchRecord3Strc
{
    int nValue0; // 0x00
    int nValue1; // 0x04
    int nValue2; // 0x08
};

struct D2LaunchMsgStrc
{
    int nType; // 0x00
    int nArg; // 0x04
    char* szName; // 0x08
    void* pExtra; // 0x0C
    void* pData; // 0x10
    unsigned long nSize; // 0x14
    char szText[0x108]; // 0x18
};

struct D2LaunchGameEntryStrc
{
    int nAddress; // 0x00
    char unused0x04[0x10]; // 0x04
    char szName[1]; // 0x14
};

struct D2LaunchGameListStrc
{
    int nCount; // 0x00
    char unused0x04[0x0C]; // 0x04
    D2LaunchGameEntryStrc tFirst; // 0x10
};

D2_CHECK_SIZE(D2MultiChannelUserStrc, 0xB4);
D2_CHECK_SIZE(D2LaunchGameRecStrc, 0x3B);
D2_CHECK_SIZE(D2LaunchFuncsStrc, 0xB0);
D2_CHECK_SIZE(D2LaunchRecord3Strc, 0xC);
D2_CHECK_SIZE(D2LaunchMsgStrc, 0x120);
D2_CHECK_SIZE(D2WinControlInitStrc, 0x30);
D2_CHECK_SIZE(D2ConfigStrc, 0x3CD);
