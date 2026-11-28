#include "D2Launch.h"
#include "D2Unicode.h"
#include "D2MultiTypes.h"
#include "D2StormTypes.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2LangApi.h"
#include "D2WinApi.h"
#include "StormApi2.h"
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0
void __cdecl MAINMENUS_ShowLocalAddress();                                                                                // 0x0042FF20
int __cdecl MAINMENUS_FreeSlots();                                                                       // 0x00430A20
void __cdecl MAINMENUS_UpdateTwoEditOk();                                                                                // 0x00436CF0
int __stdcall MAINMENUS_OnTwoEditChange(int nArg);                                                                       // 0x00436D40
void __cdecl CHATDLG_DestroyDialogControls();                                                                // 0x0043DB20
void __cdecl CHATDLG_DestroyPopupControls();                                                                           // 0x0043EA20
void __cdecl CHATDLG_DestroyCreateControls();                                                                                // 0x00443220
int __cdecl CHATDLG_DestroyGameListControls();                                                                                 // 0x00444E20
extern D2WinControlStrc* gpControl_00779338;                                                                // 0x00779338
extern D2WinControlStrc* gpControl_00779344;                                                                // 0x00779344
extern D2WinControlStrc* gpControl_00779588;                                                                // 0x00779588
extern D2WinControlStrc* gpControl_007795A0;                                                                // 0x007795A0
extern D2WinControlStrc* gpControl_007795A4;                                                                // 0x007795A4
extern D2WinControlStrc* gpControl_007795E0;                                                                       // 0x007795E0
extern D2WinControlStrc* gpControl_007795E4;                                                                       // 0x007795E4
extern int gbGatewayFlag;                                                                          // 0x00779954
extern D2WinControlStrc* gpControl_007799D4;                                                                       // 0x007799D4
extern int gfConnectCancelled;                                                                              // 0x007799D8
extern D2CharSelCacheStrc* gpCharSelCache;                                                         // 0x00779DE8
extern D2WinControlStrc* gpControlMain;                                                            // 0x0077BC4C
extern D2WinControlStrc* gbSelectActive;                                                                   // 0x0077BD00
extern D2WinControlStrc* gpControl_0077BD90;                                                                       // 0x0077BD90
extern D2WinControlStrc* gpWaitText_0077BD9C;                                                               // 0x0077BD9C
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct Unicode;
struct D2WinTextBoxStrc;
struct D2WinTimerStrc;
struct D2WinButtonStrc;
struct D2CelFileStrc;
struct D2CharSelCacheStrc;
class BNGatewayAccess;
void __cdecl CHARSEL_CreateCharListControls(); // 0x0043A800
extern int gnSelectionA; // 0x0070CC04
extern D2WinControlStrc* gpControl_007799F8; // 0x007799F8
extern D2WinControlStrc* gpScrollUpButton; // 0x00779A1C
extern char gszPreferredRealm[256]; // 0x00779A40
extern D2WinControlStrc* gpScrollDownButton; // 0x00779B64
extern char gszEnteredName[]; // 0x00779C88
extern int gnCharEntryCount; // 0x00779DC4
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
void __cdecl CHARSEL_UpdateButtons(); // 0x0043A730
extern int gbFlag_00779C6C; // 0x00779C6C
void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450
void __cdecl CHARSEL_FreeCharList(); // 0x00438EA0
void __cdecl CHARSEL_ShowMessage(); // 0x0043A5D0
void __cdecl sub_00438F70();
extern int gnBusy; // 0x00779DAC
extern char* gpszName; // 0x00779DB0
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
void __cdecl CHARSEL_InitCharList(); // 0x0043AE30
void __fastcall CHARSEL_UseName(char* szName); // 0x0043ADB0
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
extern D2CelFileStrc* gpCharSelectBckgCelFile; // 0x00779768
extern int gnTopRow; // 0x00779DC8
int __cdecl GAME_GetStopMainLoop(); // 0x0042FA30
void __cdecl MAINMENUS_UpdateProgress(); // 0x0042F990
int __cdecl sub_0042F6D0_GetMenusDone(); // 0x0042F6D0
void __cdecl sub_00518C20_DeleteQueueLock(); // 0x00518C20
extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0
void __fastcall CHARSEL_JoinSelectedWithDifficulty(SMSGHANDLER_PARAMS* pMsg, int nMode); // 0x00439AF0
extern void** gppSlots; // 0x00779988
extern "C" long __cdecl _time32(long* pTime);
extern "C" int __cdecl tolower(int nChar);
extern D2WinControlStrc* gpCharDescriptionText; // 0x007799F0
extern void* gapRowControls[8]; // 0x00779A20
extern D2WinControlStrc* gpControl_00779C70; // 0x00779C70
extern D2WinControlStrc* gpControl_00779C78; // 0x00779C78

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
// This piece stays apart from CharSel.cpp. It has its own out-of-line copy of the CRT's static inline time()
// at 0x43C530, and CharSel.cpp has another at 0x4379C0. A static inline gets one copy in each unit that
// calls it out of line, so the two copies mean two objects.
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
        MAINMENUS_BuildRealmList();
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

    gfHasCharEntries = 1;
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
            BNGatewayAccess* pAccess = (BNGatewayAccess*)gpFuncTable->pfnGetRecord();
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
long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}
