#pragma once

#include "D2SysTypes.h"
#include "D2Win32Base.h"

struct D2CelFileStrc;
struct D2CriticalSectionStrc;
struct D2FindDataStrc;
struct D2FuncRecordStrc;
struct D2ComInterfaceStrc;
struct D2ConfigStrc;
struct D2LaunchFuncsStrc;
struct D2WinControlStrc;
struct Unicode;
struct D2ConfigStrc;
struct D2ConfigStrc;
struct SMSGHANDLER_PARAMS;
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430
char* __fastcall MAINMENUS_GetSlotName(int nIndex); // 0x00430B50
const char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490
extern "C" __declspec(dllimport) void* __stdcall GetCurrentProcess(); // 0x006CC13C
extern "C" const char gszSpace[]; // 0x006FFC44
extern "C" const char* const gapszSkyPalette[2]; // 0x006D3A08
extern D2ConfigStrc* gpLaunchRecord; // 0x007795D4
extern D2WinControlStrc* gpControl_007799F4; // 0x007799F4
extern D2WinControlStrc* gpCharNameText; // 0x00779B60
extern D2WinControlStrc* gpControl_00779C68; // 0x00779C68
extern D2WinControlStrc* gpControl_00779C80; // 0x00779C80
extern D2WinControlStrc* gpControl_00779D90; // 0x00779D90
extern D2WinControlStrc* gpControl_00779D94; // 0x00779D94
extern D2WinControlStrc* gpCreatePasswordConfirmEdit; // 0x007795A8
extern D2WinControlStrc* gpEdit_007799CC; // 0x007799CC
extern D2WinControlStrc* gpEdit_007799D0; // 0x007799D0
extern D2WinControlStrc* gpChangePwAccountEdit; // 0x007799BC
extern D2WinControlStrc* gpOldPasswordEdit; // 0x007799C0
extern D2WinControlStrc* gpNewPasswordConfirmEdit; // 0x007799C4
extern D2WinControlStrc* gpNewPasswordEdit; // 0x007799C8
extern char gszOldPassword[]; // 0x00779550
extern int ganRowValues_007799FC[]; // 0x007799FC
extern int gfMenusDone; // 0x00779974
int __cdecl STRTABLE_GetLanguage(); // 0x00525150
int __cdecl MAINMENUS_HasSaveFiles(); // 0x00430BC0
int __cdecl D2Win_10003(); // 0x004F9050
int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0
int __fastcall STRTABLE_LoadStringTables(void* pArg, int nArg); // 0x005259C0
int __stdcall SStrCmp(const char* szString1, const char* szString2, int nMaxChars); // 0x00413550
int __stdcall MAINMENUS_OnCloseBox(int nArg); // 0x004334D0
void __cdecl MAINMENUS_Reset(); // 0x0042F480
void __cdecl MAINMENUS_ShowConnectingPopup(); // 0x0042F6E0
void __cdecl MAINMENUS_ReturnToCharSelect(); // 0x0042FDD0
void __cdecl MAINMENUS_CreateMultiplayerScreen(); // 0x004301A0
void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0
void __cdecl CHARSEL_InitCharSelectScreen(); // 0x0043B080
void __cdecl CHARSEL_ClearCancelled(); // 0x0043B820
void __cdecl CHARSEL_DisconnectBattleNet(); // 0x0043B9A0
void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0
void __cdecl sub_004FA550(); // 0x004FA550
void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70
void __cdecl STRTABLE_UnloadStringTables(); // 0x00524E40
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
void __fastcall CHARSEL_SetFlagBit2(int bSet); // 0x0043C6A0
void __fastcall sub_004F9740_SetControlState(D2WinControlStrc* pControl, int bSet); // 0x004F9740
void __fastcall sub_004FCF80_SetTextA(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
void __fastcall D2SOUND_10034(int nValue); // 0x005148F0
void __stdcall D2Win_10004(int nResolution); // 0x004F9060
void __stdcall D2Win_10029(int bDrawCursor); // 0x004FA410
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nResolution, void* pfFrame); // 0x004F5D90
void __stdcall sub_004F90A0(int nResolution); // 0x004F90A0
struct D2StatusStrc
{
    int nCode;
    int nArg;
};

D2CelFileStrc* __fastcall sub_004FA9B0_LoadCellFile(const char* szFile, int nType); // 0x004FA9B0
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
char* __fastcall UNICODE_ToAscii(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70
const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl); // 0x004FBB30
const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90
const char* __fastcall FOG_ResolveHostIPAddress(const char* szHostName); // 0x0040E0D0
const char* __stdcall Realm(D2FuncRecordStrc* pRecord, int nIndex); // 0x005180E0
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall FindClose(void* hFindFile); // 0x006CC1C4
extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void* __stdcall FindFirstFileA(const char* szFileName, D2FindDataStrc* pFindData); // 0x006CC1CC
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
extern "C" const char gszDataLocal[]; // 0x006D41A8
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszFormatD[]; // 0x006D57BC
extern "C" const char gszPathFormat[]; // 0x006D4124
extern "C" const char gszSaveMask[]; // 0x006D41D4
extern "C" const char gszSavePathFormat_006D4230[]; // 0x006D4230
extern "C" const char gszStringFormat[]; // 0x006FFC58
extern "C" const char gszDataGlobal[]; // 0x006D4118
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" const unsigned char gabDefault[]; // 0x006D4D88
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl sscanf(const char* szSource, const char* szFormat, ...); // 0x00684BD5
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern D2ComInterfaceStrc* gpFuncTable; // 0x0077ABF0
extern D2ConfigStrc* gpCharInfo; // 0x0077BBD8
extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C
extern D2WinControlStrc* gpCharSelectText; // 0x00779DD4
extern D2WinControlStrc* gpChatEdit; // 0x0077BD94
extern D2WinControlStrc* gpControl_00779594; // 0x00779594
extern D2WinControlStrc* gpControl_00779C84; // 0x00779C84
extern D2WinControlStrc* gpControl_00779D8C; // 0x00779D8C
extern D2WinControlStrc* gpControl_00779D98; // 0x00779D98
extern D2WinControlStrc* gpControl_00779DD0; // 0x00779DD0
extern D2WinControlStrc* gpPasswordEdit; // 0x00779334
extern D2WinControlStrc* gpAccountEdit; // 0x0077958C
extern D2WinControlStrc* gpChannelNameEdit; // 0x0077BCF4
extern D2WinControlStrc* gpMaxPlayerControl; // 0x00798C38
extern D2WinControlStrc* gpNameControl; // 0x007799E8
extern D2WinControlStrc* gpNameEdit; // 0x0077934C
extern char gszPreferredRealm[]; // 0x00779A40
extern int gbFlag_00779DD8; // 0x00779DD8
extern int gfHasCharEntries; // 0x00779DA4
extern int gfConnectError; // 0x00779DB8
extern int gfCharSelCancelled; // 0x0077AC04
extern int gnHistoryIndex; // 0x0070CD74
extern int gnLaunchMode; // 0x007795EC
extern int gnChatLaunchMode; // 0x0077BBE4
extern int gnLaunchState; // 0x007795E8
extern int gnSelected; // 0x0070CC00
extern int gnTextSentinel; // 0x0070CB80
extern int gnGameCount; // 0x00798CCC
extern int gnVisibleRows; // 0x0070CC0C
extern int gnWaitDone; // 0x00779994
extern unsigned short gawToUpperTable[0x100]; // 0x00730578
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __cdecl sub_0040EB10(); // 0x0040EB10
int __cdecl GAME_GetSlotNameCount(); // 0x00430B40
int __cdecl sub_00432400_GetStatus(); // 0x00432400
int __cdecl MCPCONNECT_QueryAddress(); // 0x00449B30
int __cdecl sub_00449B70_Receive(); // 0x00449B70
int __cdecl GAME_GetConnectError(); // 0x00449C00
int __cdecl sub_00449E60_GetPacket(); // 0x00449E60
int __cdecl VIEW_SendMcpCharListRequest(); // 0x0044AAB0
int __cdecl D2Win_10185_CheckCharMpq(); // 0x004FAC90
int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion); // 0x004FAD10
int __fastcall D2Win_10188(D2WinControlStrc* pTextBox, int nLineNum, int nColor); // 0x004FBDE0
int __fastcall MAINMENUS_ConnectToRealm(const char* szName, int bFlag); // 0x00432480
int __fastcall sub_004F9710_TestFlag(D2WinControlStrc* pControl); // 0x004F9710
int __fastcall sub_004F9710_TestFlags(D2WinControlStrc* pControl); // 0x004F9710
int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl); // 0x004FB950
int __fastcall sub_004FC620_GetValue(D2WinControlStrc* pControl); // 0x004FC620
int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470
int __stdcall SFileOpenFileEx(void* hMpq, const char* szFileName, unsigned int dwFlags, void** phFile); // 0x004192F0
int __stdcall SRegLoadString(const char* szKeyName, const char* szValueName, unsigned int nFlags, char* szBuffer, unsigned long nBufferSize); // 0x00414E50
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
unsigned int __stdcall SStrLen(const char* szString); // 0x00413750
int __stdcall SFileCloseFile(void* hFile); // 0x004198D0
int __stdcall sub_0042FF00_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FF00
void __cdecl CHARSEL_CreateTcpIpScreen(); // 0x0042FFE0
int __stdcall MAINMENUS_PollSystemPacket(int nArg); // 0x00431C90
int __stdcall MAINMENUS_StopLoop(int nArg); // 0x00431D10
int __stdcall MAINMENUS_PollConnection(int nArg); // 0x00431E30
int __stdcall CHARSEL_HandleCharList(const char* szName, int pPacket, int bFlag); // 0x0043AAB0
int __stdcall sub_004F95C0_ControlDestroy(D2WinControlStrc** ppControl); // 0x004F95C0
int __stdcall sub_004FB500(const char* szPath1, const char* szPath2); // 0x004FB500
void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
void __cdecl MAINMENUS_BuildRealmList(); // 0x00434060
void __cdecl MAINMENUS_CreateCharCreateScreen(); // 0x00435580
void __cdecl MAINMENUS_CreateRealmCharacter(); // 0x00435E10
void __cdecl MAINMENUS_CreateInfoScreen(); // 0x004370C0
void __cdecl CHARSEL_RefreshCharList(); // 0x00438560
int __cdecl CHARSEL_Redraw(); // 0x00439210
void __cdecl CHATDLG_DestroyJoinControls(); // 0x00443130
void __cdecl CHATDLG_DestroyProfileControls(); // 0x00443E10
void __cdecl D2SOUND_StopChannel(); // 0x00514930
void __cdecl D2SOUNDFAST_FadeOutWaves(); // 0x00515020
void __cdecl CLIENT_Release(); // 0x0052A7E0
void __fastcall D2SOUND_10034(int nArg); // 0x005148F0
int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050
void __fastcall sub_0040B3C0(void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall MAINMENUS_ShowTextBox(const Unicode* pText, void (__cdecl* pfnDone)()); // 0x00433460
void __fastcall AUTOMAP_InitCharSaveHeader(char* szName, char nClass, char* pData, int nFlags); // 0x0043C540
void __fastcall CHATDLG_WriteSaveHeader(char* szName); // 0x0043C6B0
void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
void __fastcall sub_004F9740_ControlSetState(D2WinControlStrc* pControl, int nFlags); // 0x004F9740
void __fastcall sub_004FB6A0_ClearText(D2WinControlStrc* pControl); // 0x004FB6A0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
void __fastcall sub_004FCFF0_SetTextA(D2WinControlStrc* pControl, const char* szText, int nArg); // 0x004FCFF0
void __fastcall sub_004FD060_SetText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
void __fastcall sub_004FD830(D2WinControlStrc* pControl); // 0x004FD830
void __fastcall sub_004FDA50(D2WinControlStrc* pControl); // 0x004FDA50
void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0
void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00
void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50
void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0
void __fastcall sub_004FFE10_SetTextA(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10
void __fastcall D2SOUNDSMP_SetMasterVolume(int nVolume); // 0x00515CE0
void __fastcall D2SOUNDSMP_FadeOutMasterVolume(int nArg); // 0x00515F50
char* __fastcall UNICODE_ToUtf8(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420
void __stdcall MCPCONNECT_SetPacket(const char* pData, int nSize); // 0x00449E70
void __stdcall WINDOW_OpenSmackCutscene(const char* szFile, int nMode, int nArg); // 0x004F5D90
void __stdcall sub_004FA450_SetActive(D2WinControlStrc* pControl); // 0x004FA450
void __stdcall CLIENT_Initialize(int nArg, const char* szAddress); // 0x0052A750

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CharSelCacheStrc
{
    unsigned int dwHash;
    void* pData;
    unsigned int dwExpireTick;
    D2CharSelCacheStrc* pNext;
};

struct D2FindDataStrc
{
    unsigned long dwFileAttributes;
    D2FileTimeStrc ftCreationTime;
    D2FileTimeStrc ftLastAccessTime;
    D2FileTimeStrc ftLastWriteTime;
    unsigned long nFileSizeHigh;
    unsigned long nFileSizeLow;
    unsigned long dwReserved0;
    unsigned long dwReserved1;
    char cFileName[260];
    char cAlternateFileName[14];
};

struct D2FuncRecordStrc
{
    char unk0x00[0x0C];
    int nIndex;
};

typedef int (__stdcall* D2LaunchCallback)(int nArg);

// One entry of gatControlTemplates: what CONTROL_Create builds a front-end control from.
struct D2LaunchControlTemplateStrc
{
    int nType; // 0x00
    int nX; // 0x04
    int nY; // 0x08
    int nWidth; // 0x0C
    int nHeight; // 0x10
    int nFlags; // 0x14
    int nStringId; // 0x18
    void* ppCellFile; // 0x1C
    D2LaunchCallback pfnCallback; // 0x20
    void* unk0x24; // 0x24
    void* unk0x28; // 0x28
    int unk0x2C; // 0x2C
};

typedef void (__cdecl* D2LaunchDoneFn)();

struct D2LaunchSlotStrc
{
    char* szName;
    void* pData;
};

typedef unsigned int size_t;
