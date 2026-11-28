#pragma once

#include "D2SysTypes.h"

class D2SquelchListStrc;
struct D2CelFileStrc;
struct D2CompositeStrc;
struct D2CriticalSectionStrc;
struct D2ComInterfaceStrc;
struct D2LaunchCharEntryStrc;
struct D2LaunchCharSelectStrc;
struct D2WinControlInitStrc;
struct D2WinControlStrc;
struct D2WinSmackStrc;

D2SquelchListStrc* __cdecl sub_00611560_GetSquelchList(); // 0x00611560
D2WinControlStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int pCallback, int nVirtualKey, int nBaseFrame, int dwButtonFlags, int nStringId, int pUpdateHoverState); // 0x00501290
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit); // 0x004F93C0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix); // 0x00687605
extern "C" char* __cdecl strchr(const char* szString, int nChar); // 0x00687740
extern "C" char* __cdecl strrchr(const char* szString, int nChar); // 0x00682990
extern "C" char* __cdecl strtok(char* szText, const char* szDelim); // 0x0068264F
extern "C" const char gszCmdD2Notify[]; // 0x006D56C0
extern "C" const char gszCmdDefaultChannel[]; // 0x006D5640
extern "C" const char gszCmdHomeChannel[]; // 0x006D5654
extern "C" const char gszCmdHomeSpace[]; // 0x006D5638
extern "C" const char gszCmdHome[]; // 0x006D5630
extern "C" const char gszCmdR[]; // 0x006D56D4
extern "C" const char gszCmdReply[]; // 0x006D56CC
extern "C" const char gszCmdSquelch[]; // 0x006D5698
extern "C" const char gszCmdUnsquelch[]; // 0x006D5680
extern "C" const char gszCommandSpace[]; // 0x006D5618
extern "C" const char gszCorrectUsage[]; // 0x006D55F8
extern "C" const char gszDefaultChannel[]; // 0x006D5504
extern "C" const char gszDiabloII[]; // 0x006CC8B8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszFormatD[]; // 0x006D57BC
extern "C" const char gszNobodyToReply[]; // 0x006D561C
extern "C" const char gszReplyFormat[]; // 0x006D55EC
extern "C" const char gszSpace[]; // 0x006FFC44
extern "C" const char gszStar[]; // 0x006D5830
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl tolower(int nChar); // 0x0068523E
extern "C" int __cdecl toupper(int nChar); // 0x00685385
extern "C" void __cdecl srand(unsigned int nSeed); // 0x00687454
extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840
extern D2CelFileStrc* gpChatBackground; // 0x0077BC04
extern D2ComInterfaceStrc* gpFuncTable; // 0x0077ABF0
extern D2LaunchCharEntryStrc* gpCharList; // 0x00779DBC
extern D2LaunchCharSelectStrc* gpCharSelect_007795D4; // 0x007795D4
extern D2WinControlStrc* gpControl_00798BC4; // 0x00798BC4
extern D2WinControlStrc* gpJoinButton; // 0x00798BCC
extern D2WinControlStrc* gpPanelTitle; // 0x00798BF0
extern D2WinControlStrc* gpPanelText; // 0x00798BF4
extern D2WinControlStrc* gpCreateButton; // 0x00798C28
extern D2WinControlStrc* gpPanelCancelButton; // 0x00798C48
extern D2WinControlStrc* gpChannelNameEdit; // 0x0077BCF4
extern D2WinControlStrc* gpGameList; // 0x00798BC0
extern D2WinControlStrc* gpGameInfoText; // 0x00798BC4
extern D2WinControlStrc* gpMaxPlayerControl; // 0x00798C38
extern char gnSelectModeB_0070CD63; // 0x0070CD63
extern char gszLevelDiffText[]; // 0x0070EBD0
extern char gszMaxPlayersText[]; // 0x0070EBD4
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
extern int gbCharSelBusy; // 0x00779DA0
extern int gbFlag_0077ADA4; // 0x0077ADA4
extern int gnLastGameCount; // 0x00798CC8
extern int gnHistoryIndex; // 0x0070CD74
extern int gnGameListLastSelection; // 0x0070EBDC
extern int gnSelectFlag; // 0x0070CD6C
extern int gnSelectIdA; // 0x0070CD7C
extern int gnSelectIdB; // 0x0070CD80
extern int gnSelectedLine; // 0x0070EC1C
extern int gnGameCount; // 0x00798CCC
extern unsigned short gwRequestId; // 0x0070CD60
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __cdecl GAME_IsLaunchExpansion(); // 0x0043DB10
int __cdecl CHATDLG_GetConnectStatus(); // 0x0043DC30
int __cdecl CHARSEL_CancelGameCreate(); // 0x0043F850
int __cdecl MCPCONNECT_QueryAddress(); // 0x00449B30
int __cdecl sub_00449B70_Receive(); // 0x00449B70
int __cdecl GAME_GetMcpGameToken(); // 0x00449BE0
int __cdecl GAME_GetConnectError(); // 0x00449C00
int __cdecl GAME_IsMcpCreateQueued(); // 0x00449E40
int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30
int __fastcall D2Win_10055(D2WinControlStrc* pTextBox); // 0x004FBAB0
int __fastcall D2Win_10082(D2WinControlStrc* pEditBox); // 0x004FDD00
int __fastcall WINMAIN_SendMcpJoinGame(const char* szName, const char* szRealm, unsigned short wRequestId); // 0x0044A4E0
int __fastcall sub_004F9710_TestFlag(D2WinControlStrc* pControl); // 0x004F9710
int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl); // 0x004FB950
int __fastcall sub_004FB990_GetSelection(D2WinControlStrc* pControl); // 0x004FB990
int __fastcall sub_00500960_IsPressed(D2WinControlStrc* pButton); // 0x00500960
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9140
int __stdcall D2Win_10169(D2CompositeStrc* pCompositeUnit); // 0x00505230
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion); // 0x00506910
int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack); // 0x00506990
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
int __stdcall sub_0043DAF0_OnConnect(int nArg); // 0x0043DAF0
int __stdcall CHATDLG_OnChatEditEnter(int nArg); // 0x0043DB90
int __stdcall sub_0043E6C0_OnError(int nArg); // 0x0043E6C0
int __stdcall sub_0043F9B0_EditKey(D2WinControlStrc* pControl, int nPos, const char* pKey); // 0x0043F9B0
int __stdcall sub_004F95C0_ControlDestroy(D2WinControlStrc** ppControl); // 0x004F95C0
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __stdcall FOG_Decode14BitsFromString(const unsigned char* pBuffer); // 0x006BBF20
void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
void __cdecl sub_0043D990(); // 0x0043D990
int __cdecl CHATDLG_PostClearMessage(); // 0x0043E570
void __cdecl CHATDLG_UpdateOkEnabled(); // 0x0043E660
void __cdecl CHATDLG_DestroyPopupControls(); // 0x0043EA20
void __cdecl CHATDLG_ResetLaunchState(); // 0x0043F8C0
void __cdecl CHATDLG_FillGameListControl(); // 0x00442C20
void __cdecl CHATDLG_UpdateJoinButtonState(); // 0x004437E0
void __cdecl sub_00444020(); // 0x00444020
void __cdecl CHARSEL_RequestGameList(); // 0x00445020
void __cdecl COMCALLBACK_RefreshChannelList(); // 0x00447BB0
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nArg); // 0x004FCFF0
void __fastcall MAINMENUS_JoinGame(D2LaunchCharEntryStrc* pEntry, unsigned short wFlags, int nType, char* szName); // 0x00434A00
void __fastcall sub_0044B210_SetHandlers(void (__fastcall* pfnA)(int, int), void (__cdecl* pfnB)()); // 0x0044B210
void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
void __fastcall sub_004F9740_ControlSetState(D2WinControlStrc* pControl, int nFlags); // 0x004F9740
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet); // 0x004F9740
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl); // 0x004FB6A0
void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0
void __fastcall sub_004FBC20(D2WinControlStrc* pList, int nValue); // 0x004FBC20
void __fastcall sub_004FBC80(D2WinControlStrc* pList, int nColumn, int nWidth); // 0x004FBC80
void __fastcall sub_004FCD40_SetCell(D2WinControlStrc* pControl, const char* szText, int nRow, int nColumn); // 0x004FCD40
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
void __fastcall sub_004FCFF0_SetTextA(D2WinControlStrc* pControl, const char* szText, int nArg); // 0x004FCFF0
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50
void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10
void __fastcall sub_00500B20_SetValue(D2WinControlStrc* pControl, int nValue); // 0x00500B20
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
void __stdcall sub_004F9160_SetLoopValue(int nValue); // 0x004F9160
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl); // 0x004FA450
void __stdcall sub_00504F80_UpdateComposite(D2CompositeStrc* pComposite, int nToken, int nMode, unsigned char* pComponents, unsigned char* pColors); // 0x00504F80
void __stdcall sub_005051A0(void* pObject, int nValue); // 0x005051A0
void __stdcall sub_00505260(void* pObject, int nValue); // 0x00505260
void __stdcall sub_005052F0(void* pObject, int nValue); // 0x005052F0

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2ChannelEntryStrc
{
    char szName[0x32];
    char szAccount[0x12];
    D2ChannelEntryStrc* pNext;
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

typedef void (__cdecl* D2LaunchDoneFn)();

struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};

#include "D2Win32Types.h"

typedef unsigned int size_t;


void __cdecl CHATDLG_RefreshChatScreen(); // 0x0043FBD0
void __fastcall CHATDLG_JoinChannel(const char* szText); // 0x004411E0
int __fastcall CHATDLG_SendChatText(char* szText, int bWhisper); // 0x004428D0
void __fastcall CHATDLG_SetPendingText(const char* szText, unsigned short wRequestId); // 0x00442DD0
void __cdecl CHATDLG_DestroyCreateControls(); // 0x00443220
int __stdcall CHATDLG_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x00443540
void __cdecl CHATDLG_UpdateCreateButton(); // 0x00443630
int __stdcall CHATDLG_SetCancel(int nArg); // 0x00443870
int __stdcall CHATDLG_PollMcp(int nArg); // 0x00443880
int __stdcall CHATDLG_JoinByName(int nArg); // 0x004439F0
void __cdecl CHATDLG_DestroyProfileControls(); // 0x00443E10
void __cdecl COMCALLBACK_BuildCreateGamePanel(); // 0x004453B0
void __cdecl CHATDLG_CreateJoinScreen(); // 0x00445DF0
const char* __fastcall COMCALLBACK_SkipNamePrefix(const char* szName); // 0x00446820
void __fastcall COMCALLBACK_CopyNamePrefix(const char* szName, char* szOut); // 0x00446840
void __cdecl COMCALLBACK_RefreshChatButtons(); // 0x004477A0
void __fastcall CHATDLG_UpdateScroll(int nDelta); // 0x00448BD0
