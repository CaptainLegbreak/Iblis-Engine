#include "D2Launch.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId);                                           // 0x0042F430
void __cdecl MAINMENUS_Reset();                                                                          // 0x0042F480
void __cdecl MAINMENUS_ShowLocalAddress();                                                                                // 0x0042FF20
int __cdecl MAINMENUS_FreeSlots();                                                                       // 0x00430A20
void __cdecl MAINMENUS_UpdateTwoEditOk();                                                                                // 0x00436CF0
int __stdcall MAINMENUS_OnTwoEditChange(int nArg);                                                                       // 0x00436D40
void __cdecl CHARSEL_DisconnectBattleNet();                                                                                // 0x0043B9A0
void __cdecl CHARSEL_CreateBaseScreen();                                                                                // 0x0043C4F0
void __cdecl CHATDLG_DestroyDialogControls();                                                                // 0x0043DB20
void __cdecl CHATDLG_DestroyPopupControls();                                                                           // 0x0043EA20
void __cdecl CHATDLG_DestroyCreateControls();                                                                                // 0x00443220
int __cdecl CHATDLG_DestroyGameListControls();                                                                                 // 0x00444E20
int __stdcall CONTROL_SetFocusedEditBox(void* pEditBox);                                                                  // 0x004F91C0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern D2WinControlStrc* gpControl_00779338;                                                                // 0x00779338
extern D2WinControlStrc* gpControl_00779344;                                                                // 0x00779344
extern D2WinControlStrc* gpControl_00779588;                                                                // 0x00779588
extern D2WinControlStrc* gpControl_007795A0;                                                                // 0x007795A0
extern D2WinControlStrc* gpControl_007795A4;                                                                // 0x007795A4
extern D2WinControlStrc* gpControl_007795E0;                                                                       // 0x007795E0
extern D2WinControlStrc* gpControl_007795E4;                                                                       // 0x007795E4
extern int gbGatewayFlag;                                                                          // 0x00779954
extern D2WinControlStrc* gpEdit_007799CC;                                                                          // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0;                                                                          // 0x007799D0
extern D2WinControlStrc* gpControl_007799D4;                                                                       // 0x007799D4
extern int gdwGlobal_007799D8;                                                                              // 0x007799D8
extern D2CharSelCacheStrc* gpCharSelCache;                                                         // 0x00779DE8
extern D2WinControlStrc* gpControlMain_0077BC4C;                                                            // 0x0077BC4C
extern D2WinControlStrc* gbSelectActive;                                                                   // 0x0077BD00
extern D2WinControlStrc* gpControl_0077BD90;                                                                       // 0x0077BD90
extern D2WinControlStrc* gpWaitText_0077BD9C;                                                               // 0x0077BD9C
extern int gdwGlobal_00798CC0;                                                                              // 0x00798CC0
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2WinTextBoxStrc;
struct D2WinTimerStrc;
struct D2WinButtonStrc;
struct D2CelFileStrc;
struct D2CharSelCacheStrc;
class BNGatewayAccess;
void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
int __cdecl CHARSEL_Redraw(); // 0x00439210
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
void __cdecl CHARSEL_CreateCharListControls(); // 0x0043A800
extern int gnSelected; // 0x0070CC00
extern int gnSelectionA; // 0x0070CC04
extern D2WinControlStrc* gpControl_007799F8; // 0x007799F8
extern D2WinControlStrc* gpScrollUpButton; // 0x00779A1C
extern char gszPreferredRealm[256]; // 0x00779A40
extern D2WinControlStrc* gpScrollDownButton; // 0x00779B64
extern char gszEnteredName[]; // 0x00779C88
extern int gnCharEntryCount; // 0x00779DC4
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
void __cdecl CHARSEL_UpdateButtons(); // 0x0043A730
extern int gnLaunchMode; // 0x007795EC
extern int gbFlag_00779C6C; // 0x00779C6C
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
void __cdecl CHARSEL_FreeCharList(); // 0x00438EA0
int __stdcall CHARSEL_HandleCharList(const char* szName, int pPacket, int bFlag); // 0x0043AAB0
int __fastcall D2Win_10047(D2WinTextBoxStrc* pTextBox); // 0x004FB6A0
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nColor); // 0x004FCFF0
void __cdecl CHARSEL_RefreshCharList(); // 0x00438560
void __cdecl CHARSEL_ShowMessage(); // 0x0043A5D0
void __cdecl sub_00438F70();
extern D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern int gdwGlobal_00779DB8; // 0x00779DB8
extern int gnBusy; // 0x00779DAC
extern char* gpszName; // 0x00779DB0
extern int gbFlag_00779DD8; // 0x00779DD8
class BNGatewayAccess
{
public:
    const char* __stdcall Realm(int nGateway);                                                                 // 0x005180E0

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
};
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);
int __stdcall SStrCmpI(const char* szString1, const char* szString2, int nMaxChars);
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __cdecl GAME_GetSlotNameCount(); // 0x00430B40
void __cdecl sub_00434060();
void __cdecl CHARSEL_InitCharList(); // 0x0043AE30
void __fastcall CHARSEL_UseName(char* szName); // 0x0043ADB0
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9140
void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet); // 0x004F9740
void __fastcall TEXTBOX_SetSmallGap(int nArg); // 0x004FB590
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
void __fastcall TIMER_DisableSpaceKey(D2WinTimerStrc* pTimer); // 0x004FD830
void __fastcall TIMER_SetRepeating(D2WinTimerStrc* pTimer); // 0x004FDA50
void __fastcall BUTTON_SetCoordinates(D2WinButtonStrc* pButton, int nX, int nY, int nWidth, int nHeight); // 0x00500A70
extern D2CelFileStrc* gpCharSelectBckgCelFile; // 0x00779768
extern D2WinControlStrc* gpControl_00779D8C; // 0x00779D8C
extern int gnTopRow; // 0x00779DC8
extern D2WinControlStrc* gpCharSelectText; // 0x00779DD4
int __cdecl GAME_GetStopMainLoop(); // 0x0042FA30
void __cdecl MAINMENUS_UpdateProgress(); // 0x0042F990
int __cdecl sub_0042F6D0(); // 0x0042F6D0
int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
extern int gdwGlobal_0077AC04; // 0x0077AC04
void __cdecl sub_00518C20_DeleteQueueLock(); // 0x00518C20
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
void __fastcall CHARSEL_JoinSelectedWithDifficulty(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0
int __fastcall D2Win_10192(D2WinTextBoxStrc* ptTextData); // 0x004FC620
int __fastcall D2Win_10193(D2WinTextBoxStrc* ptTextData, int nCurrentStep); // 0x004FC660
extern void** gppSlots; // 0x00779988
extern D2WinControlStrc* gpControl_00779C84; // 0x00779C84
extern "C" long __cdecl _time32(long* pTime);
extern "C" int __cdecl tolower(int nChar);
// build: symbol ?gacCDKeyMap@* 0x006DF238
extern const char gacCDKeyMap[];
extern D2WinControlStrc* gpCharDescriptionText; // 0x007799F0
extern void* gapRowControls[1]; // 0x00779A20
extern D2WinControlStrc* gpControl_00779C70; // 0x00779C70
extern D2WinControlStrc* gpControl_00779C78; // 0x00779C78
extern D2WinControlStrc* gpControl_00779D98; // 0x00779D98
extern D2WinControlStrc* gpControl_00779DD0; // 0x00779DD0

void __cdecl CHARSEL_FreeCache(); // 0x00437B90
void __cdecl CHARSEL_UpdateButtons(); // 0x0043A730
void __cdecl CHARSEL_ResetRealmScreen(); // 0x0043A7E0
int __stdcall CHARSEL_CopyName(int nArg); // 0x0043A9A0
static inline void* CharSelCache_FindData(unsigned int dwHash, int nTick)
{
    for (D2CharSelCacheStrc* pEntry = gpCharSelCache; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwHash == dwHash && nTick <= (int)pEntry->dwExpireTick)
            return pEntry->pData;
    }
    return 0;
}
// 0x0043AD10
static void CHARSEL_RequestCharList(char* szName)
{
    CHARSEL_FreeCharList();
    gdwGlobal_00779DB8 = 0;
    CONTROL_SetEnabled(gpControl_00779D90, 1);
    const unsigned int dwHash = SStrHash(szName, 0, 0);
    const int nTick = GetTickCount();
    void* pData = CharSelCache_FindData(dwHash, nTick);
    if (!pData)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
            return;
        }
        gnBusy = 1;
        gpszName = szName;
        return;
    }
    CHARSEL_HandleCharList(szName, (int)pData, 0);
}
int __stdcall CHARSEL_OnName(SMSGHANDLER_PARAMS* pMsg); // 0x0043B490
// build: symbol ?CHARSEL_FindSlotByName@* 0x00437A20
static int CHARSEL_FindSlotByName(const char* szName)
{
    int i = 0;
    char* szSlot;
// build: symbol ?MAINMENUS_GetSlotName@* 0x00430B50
    while (i < GAME_GetSlotNameCount() && (szSlot = MAINMENUS_GetSlotName(i)) != 0)
    {
        if (!SStrCmpI(szName, szSlot, 0x7FFFFFFF))
            return 1;
        ++i;
    }
    return 0;
}
// 0x0043B080
void __cdecl CHARSEL_InitCharSelectScreen()
{
    if (FOG_IsExpansion())
    {
        CHARSEL_InitCharList();
        return;
    }

    MAINMENUS_Reset();
    BACKGROUND_SetCellFile(gpCharSelectBckgCelFile);
// build: symbol ?gapszSkyPalette@* 0x006D3A08
    MAINMENUS_ReadPaletteFiles(gapszSkyPalette[0], gapszSkyPalette[1]);

    if (gnLaunchMode == 1)
    {
        sub_00434060();
        const int nCount = GAME_GetSlotNameCount();
        if (nCount != -1)
        {
            if (nCount == 0)
            {
                CHARSEL_DisconnectBattleNet();
                MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14AA), MAINMENUS_ShowMainMenu);
                return;
            }
        }
        else
        {
            CHARSEL_DisconnectBattleNet();
            MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
            return;
        }
    }

    gdwGlobal_00779DA4 = 1;
    gnCharEntryCount = 0;
    gnTopRow = 0;
    gnSelected = 0;
    gbFlag_00779C6C = 0;
    gpCharSelectText = 0;
    gpControl_00779DD0 = 0;
    gnBusy = 0;

    D2WinTimerStrc* pTimer = (D2WinTimerStrc*)MAINMENUS_CreateControl(0x7A);
    TIMER_DisableSpaceKey(pTimer);
    TIMER_SetRepeating(pTimer);
// build: symbol ?gpLaunchRecord@* 0x007795D4
    gpLaunchRecord->nByte210 = 0;

    gpControl_007799F8 = MAINMENUS_CreateControl(0x7C);
    gpControl_007799F4 = MAINMENUS_CreateControl(0x7D);
    CONTROL_SetEnabled(gpControl_007799F4, 0);
    gpControl_00779C68 = MAINMENUS_CreateControl(0x7E);
    gpScrollUpButton = MAINMENUS_CreateControl(0x99);
    gpScrollDownButton = MAINMENUS_CreateControl(0x9A);
    CONTROL_SetVisible(gpScrollUpButton, 0);
    CONTROL_SetVisible(gpScrollDownButton, 0);
// build: symbol ?gpCharNameText@* 0x00779B60
    gpCharNameText = MAINMENUS_CreateControl(0x9B);
    gpCharDescriptionText = MAINMENUS_CreateControl(0x9D);
    gpControl_00779C70 = MAINMENUS_CreateControl(0x9E);
    gpControl_00779D90 = MAINMENUS_CreateControl(0x9F);
    memset(gapRowControls, 0, 0x20);

    if (gnLaunchMode == 1)
    {
// build: symbol ?gnVisibleRows@* 0x0070CC0C
        gnVisibleRows = 4;
        for (int i = 0; i < gnVisibleRows; ++i)
        {
            TEXTBOX_SetSmallGap(1);
            gapRowControls[i] = MAINMENUS_CreateControl(i + 0x80);
            TEXTBOX_SetSmallGap(0);
            ganRowValues_007799FC[i] = 0xF6 + 0x5D * i;
        }

        gpControl_00779DD0 = MAINMENUS_CreateControl(0x98);
        gpCharSelectText = MAINMENUS_CreateControl(0x79);
        BUTTON_SetCoordinates((D2WinButtonStrc*)gpScrollUpButton, 0x27A, 0x8F, 0x1D, 0x14);
        MAINMENUS_CreateControl(0x65);
        gpControl_00779D98 = MAINMENUS_CreateControl(0x67);
        gpControl_00779D8C = MAINMENUS_CreateControl(0x68);
        D2Win_10051(MAINMENUS_CreateControl(0x66), D2LANG_GetStringFromTblIndex(0x2B32), 4, 0, 0);

        int nFound = 0;
        if (SRegLoadString("Diablo II", "Preferred Realm", 0, gszPreferredRealm, 0x100))
            nFound = CHARSEL_FindSlotByName(gszPreferredRealm);
        if (nFound == 0)
        {
            BNGatewayAccess* pAccess = (BNGatewayAccess*)gpFuncTable_0077ABF0->pfnGetRecord();
            SStrCopy(gszPreferredRealm, pAccess->Realm(pAccess->m_nCurGateway), 0x7FFFFFFF);
            SRegSaveString("Diablo II", "Preferred Realm", 0, gszPreferredRealm);
            nFound = CHARSEL_FindSlotByName(gszPreferredRealm);
        }
        if (nFound == 0)
        {
            const char* szFirst = GAME_GetSlotNameCount() > 0 ? MAINMENUS_GetSlotName(0) : 0;
            SStrCopy(gszPreferredRealm, szFirst, 0x7FFFFFFF);
            SRegSaveString("Diablo II", "Preferred Realm", 0, gszPreferredRealm);
        }
    }
    else
    {
        gnVisibleRows = 5;
        for (int i = 0; i < gnVisibleRows; ++i)
        {
            TEXTBOX_SetSmallGap(1);
            gapRowControls[i] = MAINMENUS_CreateControl(i + 0x7F);
            TEXTBOX_SetSmallGap(0);
            ganRowValues_007799FC[i] = 0x99 + 0x5D * i;
        }
        BUTTON_SetCoordinates((D2WinButtonStrc*)gpScrollUpButton, 0x27A, 0x32, 0x1D, 0x14);
    }

    gpControl_00779D94 = MAINMENUS_CreateControl(0x96);
    gpControl_00779C78 = MAINMENUS_CreateControl(0x97);
    CONTROL_SetVisible(gpControl_00779C78, 0);
    CONTROL_SetEnabled(gpControl_007799F8, 0);
    CHARSEL_UseName(gszPreferredRealm);
// build: symbol ?D2SOUND_GetOptionsMusicOption@* 0x00514D80
    if (D2SOUND_GetOptionsMusicOption())
// build: symbol ?D2SOUND_10034@* 0x005148F0
        D2SOUND_10034(1);
    CONTROL_SetEnabled(gpControl_007799F8, 1);
}
// 0x0043ADB0
void __fastcall CHARSEL_UseName(char* szName)
{
    gbFlag_00779DD8 = 0;
    if (gnLaunchMode == 1)
    {
        D2Win_10047((D2WinTextBoxStrc*)gpControl_00779D8C);
        D2Win_10046(gpControl_00779D8C, szName, 0);
        CHARSEL_RequestCharList(szName);
    }
    else if (gnLaunchMode == 0 || gnLaunchMode == 3 || gnLaunchMode == 2)
    {
        CHARSEL_FreeCharList();
        if (!FOG_IsExpansion())
            CHARSEL_ShowMessage();
        sub_00438F70();
    }
    CHARSEL_Redraw();
    CHARSEL_RefreshCharList();
}
void __cdecl CHARSEL_ClearFuncTable(); // 0x0043B800
void __cdecl CHARSEL_SetCancelled(); // 0x0043B810
int __stdcall CHARSEL_OnDownloadTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B850
int __stdcall CHARSEL_OnLogonTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B890
int __stdcall CHARSEL_OnCreateAccountTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B8E0
int __stdcall CHARSEL_OnChangePasswordTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043B940
// 0x0043C530
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}
void __cdecl CHATDLG_ResetLaunchState(); // 0x0043F8C0
// build: symbol ?BNSEND_NibbleToHex@* 0x0051DD10
static unsigned int BNSEND_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}
// build: symbol ?BNSEND_HexToNibble@* 0x0051DD20
static int BNSEND_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}
// build: symbol ?BNSEND_MapKeyChar@* 0x0051DD40
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
