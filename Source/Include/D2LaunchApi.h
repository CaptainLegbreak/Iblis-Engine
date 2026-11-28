#pragma once
// D2Launch's exports that the other modules call; included only by the units that use it.

struct D2ComInterfaceStrc;
struct D2ConfigStrc;
struct D2LaunchCharEntryStrc;
struct D2WinControlStrc;

void __fastcall MAINMENUS_InitStorm(int nDirectFlags, int nValue); // 0x00406870
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430
void __cdecl MAINMENUS_Reset(); // 0x0042F480
void __cdecl MAINMENUS_ShowConnectingPopup(); // 0x0042F6E0
void __cdecl MAINMENUS_ReturnToCharSelect(); // 0x0042FDD0
int __stdcall MAINMENUS_FilterLoginChar(void* pControl, int nUnused, const char* pChar); // 0x0042FE70
int __stdcall MAINMENUS_FilterRestrictedChar(void* pControl, int nUnused, const char* pChar); // 0x0042FEF0
int __stdcall sub_0042FF00_FilterChar(void* pControl, int nUnused, const char* pChar); // 0x0042FF00
void __cdecl MAINMENUS_CreateMultiplayerScreen(); // 0x004301A0
char* __fastcall MAINMENUS_GetSlotName(int nIndex); // 0x00430B50
int __cdecl MAINMENUS_HasSaveFiles(); // 0x00430BC0
int __fastcall MAINMENUS_ConnectToRealm(const char* szName, int bFlag); // 0x00432480
int __stdcall MAINMENUS_OnCloseBox(int nArg); // 0x004334D0
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
void __cdecl MAINMENUS_CreateCharCreateScreen(); // 0x00435580
int __stdcall MAINMENUS_Back(int nArg); // 0x00435E00
void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0
void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0
int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20
void __cdecl MAINMENUS_CreateInfoScreen(); // 0x004370C0
void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0
int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0
void __fastcall CHARSEL_PickClass(int nClass, int bExpansion); // 0x00439780
void __cdecl CHARSEL_InitCharSelectScreen(); // 0x0043B080
void __cdecl CHARSEL_SetCancelled(); // 0x0043B810
void __cdecl CHARSEL_ClearCancelled(); // 0x0043B820
void __cdecl CHARSEL_DisconnectBattleNet(); // 0x0043B9A0
void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0
void __fastcall CHARSEL_SetFlagBit2(int bSet); // 0x0043C6A0
int __stdcall CHARSEL_SendChatLine(int nArg); // 0x00446890
extern int gbStopMainLoop; // 0x0077932C
extern D2WinControlStrc* gpPasswordEdit; // 0x00779334
extern D2WinControlStrc* gpCreatePasswordEdit; // 0x00779340
extern D2WinControlStrc* gpAccountEdit; // 0x0077958C
extern D2WinControlStrc* gpCreatePasswordConfirmEdit; // 0x007795A8
extern D2ConfigStrc* gpLaunchRecord; // 0x007795D4
extern int gnLaunchMode; // 0x007795EC
extern int gfMenusDone; // 0x00779974
extern int gnSlotCount; // 0x0077998C
extern D2WinControlStrc* gpPasswordOk; // 0x007799A4
extern D2WinControlStrc* gpStatusText; // 0x007799A8
extern D2WinControlStrc* gpCounterText; // 0x007799AC
extern int gnStatusStringId; // 0x007799B0
extern int gnStatusDots; // 0x007799B4
extern unsigned long gdwStatusStart; // 0x007799B8
extern D2WinControlStrc* gpChangePwAccountEdit; // 0x007799BC
extern D2WinControlStrc* gpOldPasswordEdit; // 0x007799C0
extern D2WinControlStrc* gpNewPasswordConfirmEdit; // 0x007799C4
extern D2WinControlStrc* gpNewPasswordEdit; // 0x007799C8
extern D2WinControlStrc* gpEdit_007799CC; // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0; // 0x007799D0
extern int gfConnectCancelled; // 0x007799D8
extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC
extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0
extern D2WinControlStrc* gpControl_007799F4; // 0x007799F4
extern char gszPreferredRealm[256]; // 0x00779A40
extern D2WinControlStrc* gpCharNameText; // 0x00779B60
extern D2WinControlStrc* gpControl_00779C68; // 0x00779C68
extern D2WinControlStrc* gpControl_00779C80; // 0x00779C80
extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90
extern D2WinControlStrc* gpControl_00779D94; // 0x00779D94
extern int gbCharSelBusy; // 0x00779DA0
extern D2LaunchCharEntryStrc* gpCharList; // 0x00779DBC
extern D2ComInterfaceStrc* gpFuncTable; // 0x0077ABF0
extern int gbFlag_0077ADA4; // 0x0077ADA4
extern D2WinControlStrc* gpChannelOkButton; // 0x0077BCEC
extern D2WinControlStrc* gpControl_0077BD90; // 0x0077BD90
extern D2WinControlStrc* gpGameList; // 0x00798BC0
extern D2WinControlStrc* gpJoinButton; // 0x00798BCC
extern int gnLastGameCount; // 0x00798CC8
extern int gbOverlaysEnabled; // 0x007A289C
extern int gnOverlayStep; // 0x007A3138
extern int gnCellOriginX; // 0x007B0A54
extern int gnCellOriginY; // 0x007B0A58
