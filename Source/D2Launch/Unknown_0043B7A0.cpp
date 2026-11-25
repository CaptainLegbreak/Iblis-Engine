#include "D2Launch.h"

#include "D2ClientTypes.h"

#include "D2StormTypes.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Drlg.h"

#include "D2MultiTypes.h"

#include "D2LevelTxt.h"

#include "D2Unicode.h"

#include "D2LaunchRequest.h"

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

int __cdecl sub_0042F6D0(); // 0x0042F6D0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __cdecl CHARSEL_DisconnectBattleNet(); // 0x0043B9A0

int __stdcall CHARSEL_OnCreateAccountTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B8E0

int __stdcall CHARSEL_OnChangePasswordTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B940

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200

void __cdecl MAINMENUS_ShowConnectingPopup();                                                                                // 0x0042F6E0

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback);                                          // 0x004FA590

D2ComInterfaceStrc* __cdecl sub_00518C00();                                                           // 0x00518C00

extern D2ConfigStrc* gpLaunchRecord;                                                         // 0x007795D4

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern int gnLaunchMode; // 0x007795EC

extern D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0

int __cdecl GAME_GetStopMainLoop(); // 0x0042FA30

void __cdecl MAINMENUS_UpdateProgress(); // 0x0042F990

extern int gdwGlobal_0077AC04; // 0x0077AC04

void __cdecl sub_00518C20_DeleteQueueLock(); // 0x00518C20

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern int gdwGlobal_00779DA4;                                                                              // 0x00779DA4

void __fastcall MAINMENUS_SetValue(int nValue); // 0x0042FF10

D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0

int gdwGlobal_0077AC04; // 0x0077AC04

static int gbBattleNetConnected; // 0x0077AC08

static int gbConnecting; // 0x0077AC0C

void __cdecl sub_0042F880_DestroyControls(); // 0x0042F880

void __cdecl CHARSEL_CreateConnectScreen(); // 0x00436D50

int __stdcall sub_00436E90_AlwaysOne(int nArg); // 0x00436E90

int __cdecl sub_00436EA0(); // 0x00436EA0

int __stdcall CHARSEL_OnLogonTick(int nArg); // 0x0043B890

int __stdcall CHARSEL_OnCreateAccountTick(int nArg); // 0x0043B8E0

int __stdcall CHARSEL_OnChangePasswordTick(int nArg); // 0x0043B940

int __fastcall CHARSEL_HandleStatus(D2StatusStrc* pStatus); // 0x0043B9F0

extern "C" __declspec(dllimport) int __stdcall TerminateProcess(void* hProcess, unsigned int nExitCode); // 0x006CC274

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

void __cdecl MAINMENUS_ShowProgressScreen(); // 0x0042F890

void __cdecl sub_0042FA20(); // 0x0042FA20

int __stdcall sub_004374F0_UpdateStatusWait(int nArg); // 0x004374F0

void __cdecl MAINMENUS_CreateStatusScreen(); // 0x00437550

int __stdcall CHARSEL_OnDownloadTick(int nArg); // 0x0043B850

int __stdcall D2Win_CloseSpriteCache(); // 0x004F9030

void __stdcall Unload(int nValue); // 0x00517ED0

extern int gbConnectCancelled; // 0x007795F4

// 0x0043B7A0
int __fastcall CHARSEL_InitFuncTable(D2ConfigStrc* pRecord)
{
    if (!pRecord->pComInterface)
    {
        gpFuncTable_0077ABF0 = sub_00518C00();
        D2_ASSERT(gpFuncTable_0077ABF0, 0x94);
        pRecord->pComInterface = gpFuncTable_0077ABF0;
        gpFuncTable_0077ABF0->pfnInit(pRecord);
    }
    return 1;
}

// 0x0043B800
void __cdecl CHARSEL_ClearFuncTable()
{
    gpFuncTable_0077ABF0 = 0;
    sub_00518C20_DeleteQueueLock();
}

// 0x0043B810
void __cdecl CHARSEL_SetCancelled()
{
    gdwGlobal_0077AC04 = 1;
}

// 0x0043B820
void __cdecl CHARSEL_ClearCancelled()
{
    gdwGlobal_0077AC04 = 0;
}

// 0x0043B830
int __cdecl sub_0043B830()
{
    return gdwGlobal_0077AC04;
}

// 0x0043B840
int __cdecl CHARSEL_IsBattleNetConnected()
{
    return gbBattleNetConnected;
}

// 0x0043B850
int __stdcall CHARSEL_OnDownloadTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gpFuncTable_0077ABF0->pfnSlot4C() != 0x65 && !GAME_GetStopMainLoop())
    {
        MAINMENUS_UpdateProgress();
        return 1;
    }
    D2Win_StopMessageLoop();
    return 1;
}

// 0x0043B890
int __stdcall CHARSEL_OnLogonTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (gpFuncTable_0077ABF0->pfnSlot0C())
        D2Win_StopMessageLoop();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
        D2Win_StopMessageLoop();
    return 1;
}

// 0x0043B8E0
int __stdcall CHARSEL_OnCreateAccountTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlot64(&nValue))
        D2Win_StopMessageLoop();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x0043B940
int __stdcall CHARSEL_OnChangePasswordTick(SMSGHANDLER_PARAMS* pMsg)
{
    int nValue;
    if (gpFuncTable_0077ABF0->pfnSlotA0(&nValue))
        D2Win_StopMessageLoop();
    if (gdwGlobal_0077AC04 || !gpFuncTable_0077ABF0->pfnSlot68() || sub_0042F6D0())
    {
        gpFuncTable_0077ABF0->pfnSlot10();
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x0043B9A0
void __cdecl CHARSEL_DisconnectBattleNet()
{
    if (gpFuncTable_0077ABF0)
    {
        gdwGlobal_00779DA4 = 1;
        gpLaunchRecord->szRealm0x361[0] = 0;
        gpLaunchRecord->szRealm0x381[0] = 0;
        OutputDebugStringA("Disconnect from BNET\n");
        D2MCPClientCloseMCP();
        gpFuncTable_0077ABF0->pfnSlot10();
    }
}

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0
// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
struct UnicodeChar : Unicode
{
    UnicodeChar();
};
void __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);
void __fastcall MAINMENUS_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone); // 0x00433130
void __fastcall MAINMENUS_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone); // 0x004331C0
void __fastcall MAINMENUS_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone); // 0x004332B0
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
void __cdecl MAINMENUS_ShowLoginScreen(); // 0x00435330
extern int gnLogonRetries; // 0x0070CC4C
extern char gszLastAccount[16]; // 0x0077ABF4

// build: symbol ?strncpy@Unicode@@SIPAU1@PAU1@PBU1@H@Z 0x00526790
// build: symbol ?win2Unicode@Unicode@@SIPAU1@PAU1@PBDH@Z 0x00526F20
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// build: symbol ?SStrCmp@@YGHPBD0H@Z 0x00413550
// build: symbol ?D2MCPClientCloseMCP@@YAXXZ 0x00449AD0
// 0x0043B9F0
int __fastcall CHARSEL_HandleStatus(D2StatusStrc* pStatus)
{
    Unicode wszText[0x200];
    Unicode wszText3[0x200];
    Unicode wszTitle[0x200];

    int nTitle;
    int nText;
    int nMode;
    D2LaunchDoneFn pfnDone;
    int bClose;
    int nText3;
    bClose = 1;
    pfnDone = MAINMENUS_ShowMainMenu;
    nText3 = -1;
    wszTitle[0].wChar = 0;
    wszText3[0].wChar = 0;

    switch (pStatus->nCode)
    {
    case 1:
        nTitle = 0x147D;
        nText = 0x1443;
        nText3 = 0x1444;
        nMode = 2;
        break;

    case 2:
        nTitle = 0x147E;
        nText = 0x143F;
        nMode = 1;
        break;

    case 3:
    case 7:
        nTitle = 0x147F;
        nText = (pStatus->nCode == 3) ? 0x1442 : 0x2AA0;
        nText3 = 0x144A;
        nMode = 2;
        break;

    case 4:
    case 8:
        nTitle = 0x147F;
        nText = (pStatus->nCode == 4) ? 0x144F : 0x2AA1;
        nMode = 1;
        break;

    case 5:
    case 9:
        nTitle = 0x147F;
        nText = 0x1452;
        nMode = 1;
        break;

    case 6:
    case 10:
    {
        UnicodeChar wszArg[0x200];
        D2_ASSERT(pStatus->nArg, 685);
        Unicode::win2Unicode(wszArg, (const char*)pStatus->nArg, 0x200);
        Unicode::strncpy(wszTitle, D2LANG_GetStringFromTblIndex(0x147F), 0x200);
        Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex((pStatus->nCode == 6) ? 0x1450 : 0x2AA2), 0x200);
        Unicode::strncpy(wszText3, D2LANG_GetStringFromTblIndex(0x1451), 0x200);
        MAINMENUS_ShowFourTexts(wszTitle, wszText, wszArg, wszText3, MAINMENUS_ShowMainMenu);
        return 0;
    }

    case 11:
        nTitle = 0x147F;
        nText = 0x14EC;
        nMode = 1;
        break;

    case 12:
        nTitle = 0x147F;
        nText = 0x1445;
        nText3 = 0x1446;
        nMode = 2;
        break;

    case 19:
        nTitle = 0x1481;
        nText = 0x146F;
        nMode = 1;
// build: symbol ?MAINMENUS_CreateMultiplayerScreen@* 0x004301A0
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 20:
        nTitle = 0x1481;
        nText = 0x1470;
        nMode = 1;
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 21:
        nTitle = 0x1481;
        nText = 0x1471;
        nMode = 1;
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 22:
        nTitle = 0x1481;
        nText = 0x1477;
        nMode = 1;
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 23:
        nTitle = 0x1481;
        nText = 0x1472;
        nMode = 1;
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 24:
        nTitle = 0x1481;
        nText = 0x1473;
        nMode = 1;
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 25:
        nTitle = 0x1481;
        nText = 0x1474;
        nMode = 1;
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 26:
        nTitle = 0x1481;
        nText = 0x1475;
        nMode = 1;
        pfnDone = MAINMENUS_CreateMultiplayerScreen;
        bClose = 0;
        break;

    case 13:
        nTitle = 0x147C;
        nText = 0x1458;
        nMode = 1;
        bClose = 0;
        pfnDone = MAINMENUS_ShowLoginScreen;
        break;

    case 14:
// build: symbol ?gpLaunchRecord@* 0x007795D4
        if (!SStrCmp(gszLastAccount, gpLaunchRecord->szAccount, 0x7FFFFFFF))
        {
            ++gnLogonRetries;
        }
        else
        {
            gnLogonRetries = 1;
            SStrCopy(gszLastAccount, gpLaunchRecord->szAccount, 0x10);
        }
        nTitle = 0x147C;
        nMode = 1;
        bClose = 0;
        pfnDone = MAINMENUS_ShowLoginScreen;
        if (gnLogonRetries >= 2)
        {
            nText = 0x2B63;
            MAINMENUS_SetValue(1);
        }
        else
        {
            nText = 0x1457;
        }
        break;

    case 15:
        nTitle = 0x147C;
        nText = 0x1459;
        nMode = 1;
        bClose = 0;
        pfnDone = MAINMENUS_ShowLoginScreen;
        break;

    case 16:
        nTitle = 0x1480;
        nText = 0x14E5;
        nMode = 1;
        break;

    case 17:
        nTitle = 0x1480;
        nText = 0x14EA;
        nMode = 1;
        break;

    case 18:
        nTitle = 0x1480;
        nText = 0x14E3;
        nMode = 1;
        break;

    case 27:
        sub_00526E40_Utf8ToUnicode(wszText, (const char*)pStatus->nArg, 0x200);
        Unicode::strncpy(wszTitle, D2LANG_GetStringFromTblIndex(0x147C), 0x200);
        MAINMENUS_ShowTwoTexts(wszTitle, wszText, MAINMENUS_ShowLoginScreen);
        return 0;

    default:
        nTitle = 0x1480;
        nText = 0x1445;
        nText3 = 0x1446;
        nMode = 2;
        break;
    }

    Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(nText), 0x200);
    if (nText3 != -1)
        Unicode::strncpy(wszText3, D2LANG_GetStringFromTblIndex(nText3), 0x200);
    if (nTitle != -1)
        Unicode::strncpy(wszTitle, D2LANG_GetStringFromTblIndex(nTitle), 0x200);

    if (nMode == 0)
        MAINMENUS_ShowText(wszText, pfnDone);
    else if (nMode == 1)
        MAINMENUS_ShowTwoTexts(wszTitle, wszText, pfnDone);
    else
        MAINMENUS_ShowThreeTexts(wszTitle, wszText, wszText3, pfnDone);

    if (bClose)
    {
        D2MCPClientCloseMCP();
        gpFuncTable_0077ABF0->pfnSlot10();
    }
    return 0;
}

// 0x0043BF40
static __declspec(noinline) void CHARSEL_ReportStatus(int nCode, int nArg)
{
    D2StatusStrc tStatus;
    tStatus.nCode = nCode;
    tStatus.nArg = nArg;
    CHARSEL_HandleStatus(&tStatus);
}

// 0x0043BF60
int __cdecl sub_0043BF60()
{
    if (!gpFuncTable_0077ABF0)
    {
        return 0;
    }

    D2_ASSERT(!gbConnecting, 296);
    gbConnecting = 1;
    gdwGlobal_00779DA4 = 1;
    sub_0042FA20();
    OutputDebugStringA("------------------\nConnect to Battle.net\n------------------\n");
    D2MCPClientCloseMCP();

    if (!gpFuncTable_0077ABF0->pfnSlot10Result())
    {
        D2StatusStrc tStatus;
        gbConnecting = 0;
        tStatus.nCode = 0;
        tStatus.nArg = 0;
        return CHARSEL_HandleStatus(&tStatus);
    }

    gbBattleNetConnected = 0;
    MAINMENUS_CreateStatusScreen();
    sub_004FA590_RunLoop(sub_004374F0_UpdateStatusWait);

    if (gdwGlobal_0077AC04)
    {
        gbConnectCancelled = 1;
        sub_0042F880_DestroyControls();
        gpFuncTable_0077ABF0->pfnSlot10Result();
        gbConnecting = 0;
        return 0;
    }

    if (gpFuncTable_0077ABF0->pfnSlot4C() != 0x66)
    {
        MAINMENUS_ShowProgressScreen();
        sub_004FA590_RunLoop(CHARSEL_OnDownloadTick);

        if (!GAME_GetStopMainLoop() && gpFuncTable_0077ABF0->pfnSlot4C() == 0x65)
        {
            int nValue = 0;
            const int nResult = gpFuncTable_0077ABF0->pfnSlot48(&nValue);
            if (nValue)
            {
                int bSkipToOpen = 0;
                if (gnLaunchMode == 3)
                {
                    bSkipToOpen = 1;
                }
                SRegSaveValue("Diablo II", "UseCmdLine", 0, 1);
                SRegSaveValue("Diablo II", "Skip To Open", 0, bSkipToOpen);
                D2Win_CloseSpriteCache();
                gpFuncTable_0077ABF0->pfnSlot10Result();
                gbConnecting = 0;
                Unload(gpFuncTable_0077ABF0->pfnSlot98());
                TerminateProcess(GetCurrentProcess(), 0);
                return 0;
            }

            if (!nResult)
            {
                D2StatusStrc tStatus;
                gbConnecting = 0;
                tStatus.nCode = 0x12;
                tStatus.nArg = 0;
                return CHARSEL_HandleStatus(&tStatus);
            }
        }
        else
        {
            gpFuncTable_0077ABF0->pfnSlot10Result();
            gbConnecting = 0;
            sub_004336C0();
            return 0;
        }
    }

    sub_0042F880_DestroyControls();
    D2StatusStrc tResult;
    gpFuncTable_0077ABF0->pfnSlot28(&tResult);
    gbConnecting = 0;
    if (tResult.nCode)
    {
        return CHARSEL_HandleStatus(&tResult);
    }

    return gpFuncTable_0077ABF0->pfnSlot68() != 0;
}

// 0x0043C180
int __fastcall CHARSEL_Connect(D2ConfigStrc* pRecord, int bFlag, int nMode)
{
    D2StatusStrc tStatus;

    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), sub_004336C0);
        return 0;
    }

    if (gbBattleNetConnected)
    {
        return 1;
    }

// build: symbol ?MAINMENUS_ShowConnectingPopup@* 0x0042F6E0
    MAINMENUS_ShowConnectingPopup();
    gpFuncTable_0077ABF0->pfnSlot28(&tStatus);
    if (bFlag && !tStatus.nCode)
    {
        gpFuncTable_0077ABF0->pfnSlot60(pRecord->szAccount, pRecord->szPassword);
        sub_004FA590_RunLoop(CHARSEL_OnCreateAccountTick);
        if (gdwGlobal_0077AC04)
        {
            sub_0042F880_DestroyControls();
            return 0;
        }

        gpFuncTable_0077ABF0->pfnSlot64(&nMode);
        if (nMode && gpFuncTable_0077ABF0->pfnSlot68())
        {
            int nCode;
            switch (nMode)
            {
            case 2:
                nCode = 0x14;
                break;
            case 3:
                nCode = 0x15;
                break;
            case 4:
                nCode = 0x16;
                break;
            case 5:
                nCode = 0x17;
                break;
            case 6:
                nCode = 0x18;
                break;
            case 7:
                nCode = 0x19;
                break;
            case 8:
                nCode = 0x1A;
                break;
            default:
                nCode = 0x13;
                break;
            }

            CHARSEL_ReportStatus(nCode, 0);
            return 0;
        }
    }
    else if (nMode && !tStatus.nCode)
    {
// build: symbol ?gszOldPassword@* 0x00779550
        gpFuncTable_0077ABF0->pfnSlot9C(pRecord->szAccount, gszOldPassword, pRecord->szPassword);
        sub_004FA590_RunLoop(CHARSEL_OnChangePasswordTick);
        if (gdwGlobal_0077AC04)
        {
            sub_0042F880_DestroyControls();
            return 0;
        }

        gpFuncTable_0077ABF0->pfnSlotA0(&nMode);
        if (nMode != 1 && gpFuncTable_0077ABF0->pfnSlot68())
        {
            CHARSEL_ReportStatus(0xE, 0);
            return 0;
        }
    }

    if (gpFuncTable_0077ABF0->pfnSlot68() && !tStatus.nCode)
    {
        gpFuncTable_0077ABF0->pfnSlot08(pRecord->szAccount, pRecord->szPassword);
        memset(pRecord->szPassword, 0, 0x18);
        sub_004FA590_RunLoop(CHARSEL_OnLogonTick);
        if (gdwGlobal_0077AC04 || sub_0042F6D0())
        {
            sub_0042F880_DestroyControls();
            return 0;
        }
    }

    gpFuncTable_0077ABF0->pfnSlot28(&tStatus);
    sub_0042F880_DestroyControls();
    if (tStatus.nCode)
    {
        return CHARSEL_HandleStatus(&tStatus);
    }

    gbBattleNetConnected = 1;
    int bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    if (bConnected && gpFuncTable_0077ABF0->pfnSlotB4())
    {
        CHARSEL_CreateConnectScreen();
        sub_004FA590_RunLoop(sub_00436E90_AlwaysOne);
        sub_0042F880_DestroyControls();
        if (sub_00436EA0())
        {
            D2MCPClientCloseMCP();
            gpFuncTable_0077ABF0->pfnSlot10Result();
            sub_004336C0();
            return 0;
        }

        bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    }

    if (bConnected)
    {
        MAINMENUS_SetValue(0);
        return 1;
    }

    D2StatusStrc tError;
    tError.nCode = 0x12;
    tError.nArg = 0;
    CHARSEL_HandleStatus(&tError);
    return 0;
}

#include "gen/data/Source/D2Launch/Unknown_0043B7A0.inc"
