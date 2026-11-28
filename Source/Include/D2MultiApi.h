#pragma once
// D2Multi's exports that the other modules call; included only by the units that use it.

struct D2CelFileStrc;
struct D2ConfigStrc;
struct D2LaunchFuncsStrc;
struct D2LaunchGameRecStrc;
struct D2WinControlStrc;

int __fastcall CHATDLG_UpdateSaveFlags(const char* szName); // 0x0043CAA0
void __cdecl CHATDLG_DestroyDialogControls(); // 0x0043DB20
int __cdecl CHATDLG_PostClearMessage(); // 0x0043E570
void __cdecl CHATDLG_DestroyPopupControls(); // 0x0043EA20
int __stdcall CHATDLG_SetUserDataFlag(int nArg); // 0x0043F580
int __stdcall CHATDLG_GetUserDataReply(int nUnused); // 0x0043F590
void __cdecl CHATDLG_ResetLaunchState(); // 0x0043F8C0
void __cdecl CHATDLG_CreateChatScreen(); // 0x0043FC20
int __fastcall CHATDLG_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37); // 0x0043FFA0
void __fastcall CHATDLG_JoinChannel(const char* szText); // 0x004411E0
int __fastcall CHATDLG_SendChatText(char* szText, int bWhisper); // 0x004428D0
void __cdecl CHATDLG_DestroyJoinControls(); // 0x00443130
void __cdecl CHATDLG_DestroyCreateControls(); // 0x00443220
void __cdecl CHATDLG_UpdateCreateButton(); // 0x00443630
int __fastcall CHATDLG_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord); // 0x004438E0
void __cdecl CHATDLG_DestroyProfileControls(); // 0x00443E10
void __cdecl CHATDLG_FillGameList(); // 0x00444E70
void __cdecl CHARSEL_RequestGameList(); // 0x00445020
extern unsigned short gwRequestId; // 0x0070CD60
extern int gnHistoryIndex; // 0x0070CD74
extern D2WinControlStrc* gpCharSelectText; // 0x00779DD4
extern int gbFlag_00779DD8; // 0x00779DD8
extern D2WinControlStrc* gapControls[32]; // 0x0077ADA8
extern D2WinControlStrc* gapControls_0077B050[2]; // 0x0077B050
extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C
extern char gaszHistory[10][0x100]; // 0x0077B1D8
extern D2ConfigStrc* gpCharInfo; // 0x0077BBD8
extern unsigned short gwSavedRequestId; // 0x0077BBDC
extern int gnChatLaunchMode; // 0x0077BBE4
extern int gnControlCount; // 0x0077BBE8
extern unsigned long gdwConnectTime; // 0x0077BBF0
extern D2WinControlStrc* gpControl_0077BC40; // 0x0077BC40
extern D2WinControlStrc* gpControlMain; // 0x0077BC4C
extern D2CelFileStrc* gpRadioButtonGreyCelFile; // 0x0077BC6C
extern D2WinControlStrc* gpCreateJoinBckgImage; // 0x0077BCDC
extern D2WinControlStrc* gpChannelScreenTitle; // 0x0077BCE0
extern D2WinControlStrc* gpControl_0077BCE4; // 0x0077BCE4
extern D2WinControlStrc* gpControl_0077BCE8; // 0x0077BCE8
extern D2WinControlStrc* gpControl_0077BCF0; // 0x0077BCF0
extern D2WinControlStrc* gpChannelNameEdit; // 0x0077BCF4
extern D2WinControlStrc* gpChannelListBox; // 0x0077BCFC
extern D2WinControlStrc* gbSelectActive; // 0x0077BD00
extern D2WinControlStrc* gpChatEdit; // 0x0077BD94
extern D2WinControlStrc* gpJoinName; // 0x00798BD4
extern D2WinControlStrc* gpCreateButton; // 0x00798C28
extern D2WinControlStrc* gpCreateName; // 0x00798C2C
extern D2WinControlStrc* gpMaxPlayerControl; // 0x00798C38
extern D2WinControlStrc* gpSubmitEditA; // 0x00798C80
extern D2WinControlStrc* gpSubmitEditB; // 0x00798C84
extern D2WinControlStrc* gpSubmitEditC; // 0x00798C88
extern int gnSubmitMode; // 0x00798CAC
extern int gnGameCount; // 0x00798CCC
extern char gszChannelName[256]; // 0x00798D30
extern int gnResult; // 0x00798F58
extern char gszMcpText2[28]; // 0x00798F60
extern char gszMcpText1[4]; // 0x00799294
