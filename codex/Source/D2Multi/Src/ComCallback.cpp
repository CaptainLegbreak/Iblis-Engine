#include "D2Multi.h"

#include "D2FogTypes.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Drlg.h"

#include "D2LevelTxt.h"

#include "D2Win32Types.h"

#include "D2Win32System.h"

#include "D2MultiTypes.h"

#include "D2Unicode.h"

#include "D2StormTypes.h"

#include "D2ClientTypes.h"

#include "D2MsgRecord.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CompositeUnitStrc;

struct D2WinEditBoxStrc;

struct Unicode;

struct D2LaunchNameNodeStrc;

struct D2ConfigStrc;

struct D2MultiChannelUserStrc;

struct D2LaunchFuncsStrc;

struct ComAdStrc;

struct D2LaunchNameNodeStrc
{
    char szName[0x204];
    D2LaunchNameNodeStrc* pNext;
};

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" char* __cdecl strncat(char* szDest, const char* szSource, size_t nCount); // 0x00687490

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430

void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

int __stdcall MAINMENUS_Back(int nArg); // 0x00435E00

void __fastcall CHARSEL_PickClass(int nClass, int bExpansion); // 0x00439780

void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0

int __fastcall CHATDLG_SetMainControlState(int bSet); // 0x0043DAD0

int __fastcall CHATDLG_PrintText(Unicode* pText, int nColor); // 0x0043E610

void __stdcall COMCALLBACK_RemoveTableString(Unicode* pText); // 0x00446A90

int __cdecl GAME_GetMcpCharLevel(); // 0x00449E20

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

int __stdcall sub_004FD110_SetBarValue(D2WinControlStrc* pBar, int nValue); // 0x004FD110

int __stdcall sub_004FD170_SetBarMode(D2WinControlStrc* pBar, int nMode); // 0x004FD170

int __stdcall sub_004FD1B0_GetBarMax(D2WinControlStrc* pBar); // 0x004FD1B0

const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

extern D2WinControlInitStrc gtBlankBckgImageInit; // 0x0070D300

extern D2WinControlInitStrc gtPanelTitleInit; // 0x0070EAA0

extern D2WinControlInitStrc gtPanelTextInit; // 0x0070EAD0

extern D2WinControlInitStrc gtPanelCancelButtonInit; // 0x0070EB30

extern D2WinControlInitStrc gtResetBuildPanelTimerInit; // 0x0070EB60

extern int gnLaunchMode; // 0x007795EC

extern D2WinControlStrc* gpControlMain_0077BC4C; // 0x0077BC4C

extern D2WinControlStrc* gpNamesButton; // 0x0077BD08

extern D2LaunchNameNodeStrc* gpNameList; // 0x0077BDB4

extern D2WinControlStrc* gpCreateButton; // 0x00798C28

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0

int __fastcall MAINMENUS_RequestProfile(const char* szName, char* szA, char* szB, char* szC); // 0x00440CA0

void __cdecl CHATDLG_CreateProfileControls(); // 0x00443D50

int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

const char* __fastcall COMCALLBACK_SkipNamePrefix(const char* szName); // 0x00446820

unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* pCompositeUnit); // 0x00505330

void __stdcall D2Win_10156(D2CompositeUnitStrc* pCompositeUnit, int nFlags); // 0x00505360

void __cdecl COMCALLBACK_RefreshChatButtons(); // 0x004477A0

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern D2WinControlInitStrc gtProfileEditBckgInit; // 0x0070E680

extern D2WinControlInitStrc gtControlInit_0070E6B0; // 0x0070E6B0

extern D2WinControlInitStrc gtSubmitEditAInit; // 0x0070E6E0

extern D2WinControlInitStrc gtSubmitEditBInit; // 0x0070E710

extern D2WinControlInitStrc gtSubmitEditCInit; // 0x0070E740

extern D2WinControlInitStrc gtProfileViewBckgInit; // 0x0070E770

extern D2WinControlInitStrc gtControlInit_0070E7A0; // 0x0070E7A0

extern D2WinControlInitStrc gtControlInit_0070E7D0; // 0x0070E7D0

extern D2WinControlInitStrc gtControlInit_0070E800; // 0x0070E800

extern D2WinControlInitStrc gtControlInit_0070E830; // 0x0070E830

extern D2WinControlInitStrc gtRefreshButtonInit; // 0x0070E920

extern D2WinControlInitStrc gtSubmitButtonInit; // 0x0070E950

extern D2WinControlInitStrc gtSelectButtonInit; // 0x0070E980

extern D2WinControlStrc* gpCreateScreenButton; // 0x0077B070

D2WinControlStrc* gpChatControl_0077B074;                                                                   // 0x0077B074

extern D2WinControlStrc* gpJoinScreenButton; // 0x0077B078

D2WinControlStrc* gpControlC_0077B07C;                                                                      // 0x0077B07C

extern D2ConfigStrc* gpCharInfo; // 0x0077BBD8

extern D2WinControlStrc* gpProfileViewBckg; // 0x00798C64

extern D2WinControlStrc* gpControl_00798C68; // 0x00798C68

extern D2WinControlStrc* gpControl_00798C6C; // 0x00798C6C

extern D2WinControlStrc* gpControl_00798C70; // 0x00798C70

extern D2WinControlStrc* gpProfileEditBckg; // 0x00798C78

extern D2WinControlStrc* gpControl_00798C7C; // 0x00798C7C

extern D2WinControlStrc* gpRefreshButton; // 0x00798C8C

extern int gnSubmitMode; // 0x00798CAC

extern char gszPendingEntryName[]; // 0x00798CD4

extern int gnPendingValueA; // 0x00798CE4

extern int gnPendingValueB; // 0x00798CE8

D2MultiChannelUserStrc* gpSelectedChannelUser; // 0x00798F48

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

char* __stdcall SStrChr(const char* szString, char nChar); // 0x00413490

const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinEditBoxStrc* pEditBox); // 0x004FDD90

int __fastcall EDITBOX_SetText(D2WinEditBoxStrc* pEditBox, const Unicode* pText); // 0x004FF5A0

int __fastcall CHATDLG_SendChatText(char* szText, int bWhisper); // 0x004428D0

void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140

void __cdecl COMCALLBACK_ClearSelectedUser(); // 0x00448050

extern D2WinEditBoxStrc* gpChatEditBox_0077BD94; // 0x0077BD94

extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

struct ComAdStrc
{
    void* pContext;
    int n04;
    char* szName;
    void* pData;
    void* pBuffer;
    unsigned long nSize;
};

void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall FOG_WriteFile(void* hFile, const void* pBuffer, unsigned long nToWrite, unsigned long* pnWritten, void* pOverlapped); // 0x004069D0

extern void* gpLaunchContext; // 0x0077B0A4

char gszTempFile[260]; // 0x00798E30

extern "C" __declspec(dllimport) unsigned long __stdcall GetTempPathA(unsigned long nBufferLength, char* lpBuffer); // 0x006CC344

extern "C" __declspec(dllimport) unsigned int __stdcall GetTempFileNameA(const char* lpPathName, const char* lpPrefixString, unsigned int uUnique, char* lpTempFileName); // 0x006CC340

void __fastcall COMCALLBACK_SplitName(const char* szName, char* szTitle, char* szOut); // 0x00447560

D2WinControlStrc* gpProgressText; // 0x00779978

D2WinControlStrc* gpProgressBar; // 0x0077997C

D2WinControlStrc* gpCharSelectText; // 0x00779DD4

int gbFlag_00779DD8; // 0x00779DD8

int gnCounter_00779DDC; // 0x00779DDC

D2WinControlStrc* gpPanelBackground; // 0x00798BEC

D2WinControlStrc* gpPanelTitle; // 0x00798BF0

D2WinControlStrc* gpPanelText; // 0x00798BF4

D2WinControlStrc* gpPanelCancelButton; // 0x00798C48

#define AWAY_TEXT_SIZE 0x100

#define AWAY_COMMAND_DELAY 1000

#define AWAY_ERROR_STRING 0x14E7

typedef int (__stdcall* D2LaunchCallback)(int nArg);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);                                    // 0x006823FD

int __stdcall sub_0043E6C0_OnError(int nArg);                                                               // 0x0043E6C0

int gbCheck; // 0x0077BD58

D2WinControlStrc* gpControl_00798C74; // 0x00798C74

D2WinControlStrc* gpSubmitEditA; // 0x00798C80

D2WinControlStrc* gpSubmitEditB; // 0x00798C84

D2WinControlStrc* gpSubmitEditC; // 0x00798C88

D2WinControlStrc* gpSubmitButton; // 0x00798CA0

D2WinControlStrc* gpSelectButton; // 0x00798CA4

static unsigned long gdwLastCommandTick; // 0x00798F50

D2WinSmackStrc* gpSmack; // 0x0077B098

extern "C" int __cdecl strcmp(const char* szLeft, const char* szRight);

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

void __fastcall COMCALLBACK_PrependNumberText(Unicode* pText, int nValue); // 0x00447940

void __fastcall COMCALLBACK_AppendNumberText(Unicode* pText, int nValue); // 0x00447870

D2MultiChannelUserStrc* gpChannelUsers;                                                                 // 0x00798F34

char gszLastWhisperer[256]; // 0x0077B0D0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern "C" int __cdecl rand();                                                                              // 0x00687461

int __fastcall CHATDLG_ShowChannelText(Unicode* pText);                                                // 0x0043E630

void __fastcall COMCALLBACK_SetNamedValue(const char* szName, const char* szValue);                        // 0x00447400

void __fastcall CHATDLG_UpdateScroll(int nDelta);                                                      // 0x00448BD0

void __stdcall sub_00504270_SetCompositeText(D2CompositeStrc* pComposite, Unicode* wszName, Unicode* wszAccount, Unicode* wszS97, Unicode* wszRealm, int nLevel, unsigned int dwCode); // 0x00504270

D2CompositeStrc* __stdcall sub_005066C0(int nA, int nMode, unsigned char* pComponents, unsigned char* pColors); // 0x005066C0

char gszChannelName[256]; // 0x00798D30

int gnChannelUserCount;                                                                                // 0x00798F40

int gbRandSeeded;                                                                                  // 0x00798F54

static unsigned char COMCALLBACK_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const unsigned char* pStat); // 0x00446D90

struct D2LaunchMsgStrc;

typedef int (__fastcall* D2LaunchMsgHandler)(int nArg, char* pArg, const char* szText, const char* szNext);

extern D2WinSmackStrc* gpSmack_0077B098; // 0x0077B098

extern int gnVideoId_0077B0A4; // 0x0077B0A4

char gszText_00798CF8[56]; // 0x00798CF8

extern D2LaunchMsgHandler gapfnMsgHandlers[]; // 0x0070EC20

extern "C" const char gszLaunchFile[]; // 0x006D5810

extern "C" const char gszChannelCountFormat[]; // 0x006D5994

static void COMCALLBACK_UpdateUserText(D2MultiChannelUserStrc* pUser); // 0x004471B0

static void __stdcall COMCALLBACK_UpdateUser(D2MultiChannelUserStrc* pUser, const unsigned char* pStat, unsigned int nFlags, const char* szName); // 0x00447FD0

struct D2ChannelEntryStrc;

D2MultiChannelUserStrc* __stdcall COMCALLBACK_AddChannelUser(const char* szName, const unsigned char* pStat, unsigned int nFlags); // 0x00449050

int __stdcall sub_005041B0_Destroy(D2CompositeStrc* pComposite, int nFlag); // 0x005041B0

extern D2WinControlStrc* gapChatButtons[]; // 0x0077AD78

extern D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44

extern int gnChannelScroll; // 0x00798F44

int gbShowJoinLeave; // 0x0077BD54

extern "C" void _ReadWriteBarrier();

#pragma intrinsic(_ReadWriteBarrier)

union D2ChannelFlagsStrc
{
    unsigned int dwFlags;
    unsigned char nFlags;
    struct
    {
        unsigned int bFlag01 : 1;
        unsigned int bFlag02 : 1;
        unsigned int bFlag04 : 1;
        unsigned int bFlag08 : 1;
        unsigned int bFlag10 : 1;
        unsigned int bFlag20 : 1;
    };
};

struct D2ChatChannelMemberStrc
{
    int nUnk0x00;
    char szName[0x32];
    char szText[0x50];
    unsigned char nClass;
    char unk0x87[0x3];
    union
    {
        unsigned short wFlags8A;
        struct
        {
            unsigned short nLow8A : 5;
            unsigned short bExp8A : 1;
            unsigned short nMid8A : 2;
            unsigned short nLevel8A : 5;
        };
    };
    char unk0x8C[0x4];
    D2ChannelFlagsStrc tFlags90;
    char nValue94;
    char unk0x95[0x7];
    D2CompositeUnitStrc* pComposite;
    int nValue0xA0;
    int unk0xA4;
    int nValue0xA8;
    int unk0xAC;
    D2ChatChannelMemberStrc* pNext;
};

void __stdcall D2Win_10152(D2CompositeUnitStrc* pCompositeUnit, int nY);                                    // 0x005052B0

#define CHAN_SETBIT(x, n, cond) if (cond) x |= gdwBitMasks[n]; else x &= gdwInvBitMasks[n]

#pragma intrinsic(strcmp)

#define D2_STACKARG(x) (x)

int __fastcall COMCALLBACK_OnUserUpdate(unsigned int nFlags, int nUnused, const char* szName, const unsigned char* pStat); // 0x004480D0

D2ChannelEntryStrc* gpChannelEntries; // 0x00798F38

int gnChannelEntries_00798F3C; // 0x00798F3C

void __fastcall COMCALLBACK_PrintOwnLine(const char* szText);

static void __stdcall COMCALLBACK_PrintChannelLine(const char* szText, int nPrefix, const char* szName, int nColor);

static void __stdcall COMCALLBACK_PrintNamedLine(const char* szText, int nPrefix, const char* szName, int nColor);

int __stdcall COMCALLBACK_OnChannelTalk(const char* szSender, const char* szMessage); // 0x00448370

struct D2WinButtonStrc;

struct SMSGHANDLER_PARAMS;

struct D2MsgRecordStrc;

struct D2MsgRecordChunkStrc;

struct D2MsgHandlerEntryStrc;

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);

extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, int lParam); // 0x006CC488

extern "C" int __cdecl SStrPrintf(char* szBuffer, unsigned int nSize, const char* szFormat, ...); // 0x00413A40

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam, int* pUseResult, int* pResult); // 0x00420B00

int __fastcall D2Win_10076(D2WinEditBoxStrc* pEditBox, const char* szText); // 0x004FFE10

unsigned int __stdcall sub_00505330_GetCompositeFlags(D2CompositeStrc* pComposite); // 0x00505330

const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nRank, int bSoftCore); // 0x00505640

void __cdecl CHATDLG_UpdateLevelControls(); // 0x004451C0

void __stdcall COMCALLBACK_RemoveChannelUser(const char* szName); // 0x004493E0

int __stdcall SErrGetErrorStr(unsigned long error, char* buffer, unsigned long size); // 0x0041C430

void __cdecl RECORD_AddRecordChunk(); // 0x00451400

int __cdecl sub_0044DA90(); // 0x0044DA90

int __cdecl RECORD_IsReplayActive(); // 0x00451990

void __fastcall RECORD_RecordInputMessage(unsigned int uMessage, unsigned int wParam, int lParam); // 0x004514B0

void __fastcall SCMD_RegisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451C70

extern const char gszFormatInt_006D57BC[]; // 0x006D57BC

extern const unsigned int gdwTitleMaskA; // 0x006CE280

extern const unsigned int gdwBitMask7; // 0x006CE284

extern D2WinEditBoxStrc* gpEditBox_00798C3C; // 0x00798C3C

extern int gbStringsLoaded_007A070C; // 0x007A070C

extern D2MsgRecordChunkStrc* gpMsgRecordChunk_0070F7A0; // 0x0070F7A0

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0

static int COMCALLBACK_GetUserRank(D2MultiChannelUserStrc* pUser); // 0x00446D30

void __cdecl CHATDLG_ActivateChatEdit(); // 0x0043D990

extern const unsigned char gabCdKeyMap[256]; // 0x006D59F0

D2WinButtonStrc* gpLevelDiffCheck; // 0x00798C40

void __cdecl CHATDLG_CreateJoinScreen();                                                               // 0x00445DF0

void __cdecl COMCALLBACK_BuildCreateScreen();                                                              // 0x00445FF0

extern int gnChatLaunchMode;                                                                           // 0x0077BBE4

extern "C" char* __cdecl strchr(const char* szString, int nChar);                                           // 0x00687740

#pragma intrinsic(strcmp)

struct D2NamedValueStrc;

struct D2NamedValueStrc
{
    char szName[0x32];
    char szValue[0x12];
    D2NamedValueStrc* pNext;
};

extern D2WinControlStrc* gpChatEdit; // 0x0077BD94

static D2NamedValueStrc* s_pNamedValues_00798F38; // 0x00798F38

static int gnChannelEntries; // 0x00798F3C

struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };

extern int gnChannelUserCount_00798F40; // 0x00798F40

extern int gnChannelUserOffset_00798F44; // 0x00798F44

extern unsigned int gdwSelectionTick; // 0x00798F4C

void __cdecl CHATDLG_DestroyProfileControls(); // 0x00443E10

void __fastcall CHATDLG_ShowProfileDialog(const char*,int,int); // 0x00445A80

void __fastcall CHATDLG_ShowUserInfoDialog(const char*,const char*,int,int); // 0x00445C70

D2WinControlStrc* gapChatDlgControls; // 0x0077B058

D2WinControlStrc* gpChatControl_0077B05C; // 0x0077B05C

D2WinControlStrc* gpChatControl_0077B064; // 0x0077B064

D2WinControlStrc* gpChatControl_0077B068; // 0x0077B068

D2WinControlStrc* gpChatControl_0077B06C; // 0x0077B06C

void __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone);                      // 0x0043FB50

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00

int __stdcall CHATDLG_JoinNameKey(D2WinControlStrc* pControl, int nArg, const char* pChar);            // 0x004450A0

int __stdcall CHATDLG_JoinNameEnter(int nArg);                                                         // 0x004450C0

int __stdcall CHATDLG_IsPrintableChar(D2WinControlStrc* pControl, int nArg, const char* pChar);        // 0x00443600

extern D2WinControlInitStrc gtJoinGameBckgImageInit;                                                         // 0x0070D630

extern D2WinControlInitStrc gtJoinGameTitleInit;                                                         // 0x0070D660

extern D2WinControlInitStrc gtJoinNameLabelInit;                                                         // 0x0070D690

extern D2WinControlInitStrc gtJoinPasswordLabelInit;                                                         // 0x0070D6C0

extern D2WinControlInitStrc gtControlInit_0070D6F0;                                                         // 0x0070D6F0

extern D2WinControlInitStrc gtJoinNameInit;                                                         // 0x0070D720

extern D2WinControlInitStrc gtJoinPasswordInit;                                                         // 0x0070D750

extern D2WinControlInitStrc gtGameListInit;                                                         // 0x0070D780

extern D2WinControlInitStrc gtJoinButtonInit;                                                         // 0x0070D7B0

extern D2WinControlInitStrc gtGameInfoTextInit;                                                         // 0x0070D8A0

extern D2WinControlInitStrc gtControlInit_0070E110;                                                         // 0x0070E110

extern D2WinControlStrc* gpJoinGameBckgImage;                                                                // 0x00798BC8

extern D2WinControlStrc* gpControl_00798BD0;                                                                // 0x00798BD0

D2WinControlStrc* gpJoinName;                                                                      // 0x00798BD4

D2WinControlStrc* gpJoinPassword;                                                                       // 0x00798BD8

D2WinControlStrc* gpJoinGameTitle;                                                                       // 0x00798BDC

D2WinControlStrc* gpJoinNameLabel;                                                                       // 0x00798BE0

D2WinControlStrc* gpJoinPasswordLabel;                                                                       // 0x00798BE4

D2WinControlStrc* gpControl_00798BE8;                                                                       // 0x00798BE8

unsigned long gdwLastRefresh;                                                                      // 0x00798CF0

static inline int ProgressBarValue(int nPercent)
{
    return nPercent * sub_004FD1B0_GetBarMax(gpProgressBar) / 100;
}

static __forceinline int FilterNoSeparator(D2WinControlStrc* pControl)
{
    char szText[0x20];
    const Unicode* pText = sub_004FDD90_GetEditText(pControl);
    sub_005263E0(szText, pText, 0x20);
    for (int i = 0; szText[i]; i += 1)
    {
        if (szText[i] == '-' || szText[i] == '_')
            return 0;
    }
    return 1;
}

// build: symbol ?gbCharSelBusy@* 0x00779DA0
// build: symbol ?gpCharList@* 0x00779DBC
// build: symbol ?FOG_IsExpansion@* 0x00408F20
// build: symbol ?MAINMENUS_DestroyControls@* 0x0042F3F0
// build: symbol ?MAINMENUS_JoinGame@* 0x00434A00

void __cdecl CHATDLG_LoadLevelRestriction(); // 0x00445300

// build: symbol ?gszSpace@* 0x006FFC44
// build: symbol ?gszFormatD@* 0x006D57BC
void __cdecl COMCALLBACK_BuildCreateGamePanel(); // 0x004453B0

void __fastcall CHATDLG_ShowProfileDialog(const char* szText, int nA, int nB); // 0x00445A80

void __fastcall CHATDLG_ShowUserInfoDialog(const char* szUser, const char* szText, int nA, int nB); // 0x00445C70

// build: symbol ?gpGameList@* 0x00798BC0
// build: symbol ?CHARSEL_RequestGameList@* 0x00445020
// build: symbol ?gnLastGameCount@* 0x00798CC8
// build: symbol ?CHATDLG_UpdateJoinButtonState@* 0x004437E0

D2WinControlStrc* gpCreatePasswordLabel;                                                                       // 0x00798BF8

D2WinControlStrc* gpCreateDescLabel;                                                                       // 0x00798BFC

D2WinControlStrc* gpMaxPlayersLabel;                                                                       // 0x00798C00

D2WinControlStrc* gpLevelDiffLabel;                                                                       // 0x00798C04

D2WinControlStrc* gpControl_00798C08;                                                                       // 0x00798C08

D2WinControlStrc* gpMaxPlayersBoxImage;                                                                       // 0x00798C0C

D2WinControlStrc* gpControl_00798C10;                                                                       // 0x00798C10

D2WinControlStrc* gpMaxPlayersUpButton;                                                                       // 0x00798C14

D2WinControlStrc* gpMaxPlayersDownButton;                                                                       // 0x00798C18

extern D2WinControlStrc* gpLevelDiffUpButton;                                                                // 0x00798C1C

extern D2WinControlStrc* gpLevelDiffDownButton;                                                                // 0x00798C20

D2WinControlStrc* gpLevelDiffGreyArrows;                                                                       // 0x00798C24

D2WinControlStrc* gpCreateName;                                                                    // 0x00798C2C

D2WinControlStrc* gpCreatePassword;                                                                       // 0x00798C30

D2WinControlStrc* gpCreateDesc;                                                                       // 0x00798C34

D2WinControlStrc* gpMaxPlayerControl;                                                                       // 0x00798C38

D2WinControlStrc* gpLevelDiffEdit;                                                                       // 0x00798C3C

D2WinControlStrc* gpLevelDiffBoxImage;                                                                       // 0x00798C44

extern D2WinControlStrc* gpNormalRadio;                                                                // 0x00798C4C

extern D2WinControlStrc* gpNightmareRadio;                                                                // 0x00798C50

extern D2WinControlStrc* gpHellRadio;                                                                // 0x00798C54

D2WinControlStrc* gpNormalLabel;                                                                       // 0x00798C58

D2WinControlStrc* gpNightmareLabel;                                                                       // 0x00798C5C

D2WinControlStrc* gpHellLabel;                                                                       // 0x00798C60

extern D2WinControlInitStrc gtCreateGameBckgImageInit;                                                         // 0x0070DA50

extern D2WinControlInitStrc gtCreateGameTitleInit;                                                         // 0x0070DA80

extern D2WinControlInitStrc gtCreateNameLabelInit;                                                         // 0x0070DAB0

extern D2WinControlInitStrc gtCreatePasswordLabelInit;                                                         // 0x0070DAE0

extern D2WinControlInitStrc gtCreateDescLabelInit;                                                         // 0x0070DB10

extern D2WinControlInitStrc gtMaxPlayersLabelInit;                                                         // 0x0070DB40

extern D2WinControlInitStrc gtCreateButtonInit;                                                         // 0x0070DCC0

extern D2WinControlInitStrc gtCreateNameInit;                                                         // 0x0070DBD0

extern D2WinControlInitStrc gtCreatePasswordInit;                                                         // 0x0070DC00

extern D2WinControlInitStrc gtCreateDescInit;                                                         // 0x0070DC30

extern D2WinControlInitStrc gtMaxPlayersEditInit;                                                         // 0x0070DC60

extern D2WinControlInitStrc gtLevelDiffCheckInit;                                                         // 0x0070DCF0

extern D2WinControlInitStrc gtLevelDiffBoxImageInit;                                                         // 0x0070DD20

extern D2WinControlInitStrc gtLevelDiffEditInit;                                                         // 0x0070DC90

extern D2WinControlInitStrc gtLevelDiffLabelInit;                                                         // 0x0070DB70

extern D2WinControlInitStrc gtControlInit_0070DBA0;                                                         // 0x0070DBA0

extern D2WinControlInitStrc gtMaxPlayersUpInit;                                                         // 0x0070DE70

extern D2WinControlInitStrc gtMaxPlayersDownInit;                                                         // 0x0070DEA0

extern D2WinControlInitStrc gtLevelDiffUpInit;                                                         // 0x0070DED0

extern D2WinControlInitStrc gtLevelDiffDownInit;                                                         // 0x0070DF00

extern D2WinControlInitStrc gtLevelDiffGreyArrowsInit;                                                         // 0x0070DF30

extern D2WinControlInitStrc gtMaxPlayersBoxImageInit;                                                         // 0x0070DF60

extern D2WinControlInitStrc gtControlInit_0070DF90;                                                         // 0x0070DF90

extern D2WinControlInitStrc gtHellRadioInit;                                                         // 0x0070DDB0

extern D2WinControlInitStrc gtHellLabelInit;                                                         // 0x0070DE40

extern D2WinControlInitStrc gtNightmareRadioInit;                                                         // 0x0070DD80

extern D2WinControlInitStrc gtNightmareLabelInit;                                                         // 0x0070DE10

extern D2WinControlInitStrc gtNormalLabelInit;                                                         // 0x0070DDE0

extern D2WinControlInitStrc gtNormalRadioInit;                                                         // 0x0070DD50

extern int gnDiffSelect;                                                                           // 0x00798CD0

void __stdcall CONTROL_SetEscapeButton(void* a1); // 0x004FA450

void __cdecl MAINMENUS_LoadMaxPlayers();                                                                                // 0x004431B0

void __fastcall CHATDLG_DisableControl(D2WinControlStrc* pControl);                                           // 0x0043F560

int __stdcall CHATDLG_OnLevelRestrictToggle(int nArg); // 0x00445550

int __stdcall CHATDLG_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x00443540

int __stdcall sub_004456A0_OnEnter(int nArg);                                                               // 0x004456A0

int __stdcall sub_004435D0_IsTextChar(D2WinControlStrc* pControl, int nArg, const char* pChar);             // 0x004435D0

int __stdcall sub_004FE770_IsDigitChar(D2WinControlStrc* pControl, int nArg, const char* pChar);            // 0x004FE770

int __stdcall sub_004456B0_OnEnter(int nArg);                                                               // 0x004456B0

int __stdcall sub_004456C0_OnEnter(int nArg);                                                               // 0x004456C0

// 0x00445FF0
void __cdecl COMCALLBACK_BuildCreateScreen()
{
// build: symbol ?CHATDLG_GetConnectStatus@* 0x0043DC30
    if (CHATDLG_GetConnectStatus() == -1)
    {
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }
// build: symbol ?GAME_IsMcpCreateQueued@* 0x00449E40
    if (GAME_IsMcpCreateQueued())
    {
        COMCALLBACK_BuildCreateGamePanel();
        return;
    }
    gpCharInfo->nByte210 = 0;
    gpPanelBackground = CONTROL_Create(&gtCreateGameBckgImageInit);
    gpControl_00798BF0 = CONTROL_Create(&gtCreateGameTitleInit);
    D2Win_10044(gpControl_00798BF0, D2LANG_GetStringFromTblIndex(0x141E));
    gpControl_00798BF4 = CONTROL_Create(&gtCreateNameLabelInit);
    D2Win_10044(gpControl_00798BF4, D2LANG_GetStringFromTblIndex(0x149A));
    gpCreatePasswordLabel = CONTROL_Create(&gtCreatePasswordLabelInit);
    D2Win_10044(gpCreatePasswordLabel, D2LANG_GetStringFromTblIndex(0x1488));
    gpCreateDescLabel = CONTROL_Create(&gtCreateDescLabelInit);
    D2Win_10044(gpCreateDescLabel, D2LANG_GetStringFromTblIndex(0x1489));
// build: symbol ?MCPCONNECT_QueryAddress@* 0x00449B30
    if (MCPCONNECT_QueryAddress())
    {
        gpMaxPlayersLabel = CONTROL_Create(&gtMaxPlayersLabelInit);
        D2Win_10044(gpMaxPlayersLabel, D2LANG_GetStringFromTblIndex(0x148A));
    }
    gpControl_00798C28 = CONTROL_Create(&gtCreateButtonInit);
    gpControl_00798C48 = CONTROL_Create(&gtControlInit_0070E110);
    CONTROL_SetEscapeButton(gpControl_00798C48);
    gpCreateName = CONTROL_Create(&gtCreateNameInit);
    sub_004FDD50_SetMaxLength(gpCreateName, 0x10);
    sub_004FDAD0_SetKeyCallback(gpCreateName, CHATDLG_IsNameChar);
    sub_004FDB00_SetEnterCallback(gpCreateName, sub_004456A0_OnEnter);
    gpCreatePassword = CONTROL_Create(&gtCreatePasswordInit);
    sub_004FDD50_SetMaxLength(gpCreatePassword, 0x10);
    sub_004FDAD0_SetKeyCallback(gpCreatePassword, CHATDLG_IsPrintableChar);
    gpCreateDesc = CONTROL_Create(&gtCreateDescInit);
    sub_004FDD50_SetMaxLength(gpCreateDesc, 0x20);
    sub_004FDAD0_SetKeyCallback(gpCreateDesc, sub_004435D0_IsTextChar);
// build: symbol ?gszLevelDiffText@* 0x0070EBD0
    sprintf(gszLevelDiffText, gszFormatInt_006D57BC, 4);
// build: symbol ?gszMaxPlayersText@* 0x0070EBD4
    sprintf(gszMaxPlayersText, gszFormatInt_006D57BC, 4);
    if (MCPCONNECT_QueryAddress())
    {
        gpMaxPlayerControl = CONTROL_Create(&gtMaxPlayersEditInit);
        sub_004FFE10_SetTextA(gpMaxPlayerControl, gszMaxPlayersText);
        sub_004FDD50_SetMaxLength(gpMaxPlayerControl, 3);
        sub_004FDAD0_SetKeyCallback(gpMaxPlayerControl, sub_004FE770_IsDigitChar);
        sub_004FDB00_SetEnterCallback(gpMaxPlayerControl, sub_004456B0_OnEnter);
        gpLevelDiffCheck = (D2WinButtonStrc *)CONTROL_Create(&gtLevelDiffCheckInit);
        BUTTON_SetIsPressed((D2WinControlStrc *)(D2WinButtonStrc*)gpLevelDiffCheck, 1);
        gpLevelDiffBoxImage = CONTROL_Create(&gtLevelDiffBoxImageInit);
        gpLevelDiffEdit = CONTROL_Create(&gtLevelDiffEditInit);
        sub_004FFE10_SetTextA(gpLevelDiffEdit, gszLevelDiffText);
        sub_004FDD50_SetMaxLength(gpLevelDiffEdit, 3);
        sub_004FDAD0_SetKeyCallback(gpLevelDiffEdit, sub_004FE770_IsDigitChar);
        sub_004FDB00_SetEnterCallback(gpLevelDiffEdit, sub_004456C0_OnEnter);
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpLevelDiffEdit, 0);
        gpLevelDiffLabel = CONTROL_Create(&gtLevelDiffLabelInit);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        gpControl_00798C08 = CONTROL_Create(&gtControlInit_0070DBA0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
        gpMaxPlayersUpButton = CONTROL_Create(&gtMaxPlayersUpInit);
        gpMaxPlayersDownButton = CONTROL_Create(&gtMaxPlayersDownInit);
        gpLevelDiffUpButton = CONTROL_Create(&gtLevelDiffUpInit);
        gpLevelDiffDownButton = CONTROL_Create(&gtLevelDiffDownInit);
        gpLevelDiffGreyArrows = CONTROL_Create(&gtLevelDiffGreyArrowsInit);
        sub_00500B20_SetValue(gpMaxPlayersDownButton, 2);
        sub_00500B20_SetValue(gpLevelDiffDownButton, 2);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        CONTROL_SetEnabled(gpLevelDiffGreyArrows, 0);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 0);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 0);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 0);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 0);
        sub_004FDDD0_LinkTab(gpCreateName, gpCreatePassword);
        sub_004FDDD0_LinkTab(gpCreatePassword, gpCreateDesc);
        sub_004FDDD0_LinkTab(gpCreateDesc, gpMaxPlayerControl);
        sub_004FDDD0_LinkTab(gpMaxPlayerControl, gpLevelDiffEdit);
        sub_004FDDD0_LinkTab(gpLevelDiffEdit, gpCreateName);
        CHATDLG_LoadLevelRestriction();
        MAINMENUS_LoadMaxPlayers();
    }
    else
    {
        sub_004FDDD0_LinkTab(gpCreateName, gpCreatePassword);
        sub_004FDDD0_LinkTab(gpCreatePassword, gpCreateDesc);
        sub_004FDDD0_LinkTab(gpCreateDesc, gpCreateName);
        gpMaxPlayersLabel = CONTROL_Create(&gtMaxPlayersLabelInit);
        sub_004FC9B0_SetText(gpMaxPlayersLabel, D2LANG_GetStringFromTblIndex(0x148A), 5, 0, 0);
        gpLevelDiffLabel = CONTROL_Create(&gtLevelDiffLabelInit);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        gpControl_00798C08 = CONTROL_Create(&gtControlInit_0070DBA0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
        gpLevelDiffBoxImage = CONTROL_Create(&gtLevelDiffBoxImageInit);
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 1);
        gpLevelDiffGreyArrows = CONTROL_Create(&gtLevelDiffGreyArrowsInit);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        CONTROL_SetEnabled(gpLevelDiffGreyArrows, 0);
        gpMaxPlayersBoxImage = CONTROL_Create(&gtMaxPlayersBoxImageInit);
        sub_004F9740_SetControlState(gpMaxPlayersBoxImage, 1);
        gpControl_00798C10 = CONTROL_Create(&gtControlInit_0070DF90);
        sub_004F9740_SetControlState(gpControl_00798C10, 1);
        CONTROL_SetEnabled(gpControl_00798C10, 0);
    }
    int bSelected = 0;
    unsigned long dwDifficulty = 0;
    if (!SRegLoadValue("Diablo II", "DIFF_LEVEL", 0, &dwDifficulty))
        SRegSaveValue("Diablo II", "DIFF_LEVEL", 0, 0);
    int nLevel = gpCharInfo->aFlags1EF[1] & 0x1F;
    gpHellRadio = CONTROL_Create(&gtHellRadioInit);
    gpHellLabel = CONTROL_Create(&gtHellLabelInit);
    gpNightmareRadio = CONTROL_Create(&gtNightmareRadioInit);
    gpNightmareLabel = CONTROL_Create(&gtNightmareLabelInit);
    int bExpansion = gpCharInfo->aFlags1EF[0] & 0x20;
    if ((!bExpansion && nLevel >= 8) || nLevel >= 10)
    {
        sub_004FC9B0_SetText(gpHellLabel, D2LANG_GetStringFromTblIndex(0x2720), 4, 0, 0);
        if (dwDifficulty == 2)
        {
            BUTTON_SetIsPressed((D2WinControlStrc *)(D2WinButtonStrc*)gpHellRadio, 1);
            gnDiffSelect = 2;
            gpCharInfo->nByte210 = 2;
            bSelected = 1;
        }
    }
    else
    {
        sub_004FC9B0_SetText(gpHellLabel, D2LANG_GetStringFromTblIndex(0x2720), 5, 0, 0);
        CHATDLG_DisableControl(gpHellRadio);
    }
    if ((!bExpansion && nLevel >= 4) || nLevel >= 5)
    {
        sub_004FC9B0_SetText(gpNightmareLabel, D2LANG_GetStringFromTblIndex(0x2721), 4, 0, 0);
        if (dwDifficulty == 1)
        {
            BUTTON_SetIsPressed((D2WinControlStrc *)(D2WinButtonStrc*)gpNightmareRadio, 1);
            gnDiffSelect = 1;
            gpCharInfo->nByte210 = 1;
            bSelected = 1;
        }
    }
    else
    {
        sub_004FC9B0_SetText(gpNightmareLabel, D2LANG_GetStringFromTblIndex(0x2721), 5, 0, 0);
        CHATDLG_DisableControl(gpNightmareRadio);
    }
    gpNormalLabel = CONTROL_Create(&gtNormalLabelInit);
    sub_004FC9B0_SetText(gpNormalLabel, D2LANG_GetStringFromTblIndex(0x2722), 4, 0, 0);
    gpNormalRadio = CONTROL_Create(&gtNormalRadioInit);
    if (!bSelected)
    {
        BUTTON_SetIsPressed((D2WinControlStrc *)(D2WinButtonStrc*)gpNormalRadio, 1);
        gnDiffSelect = 0;
    }
    CONTROL_SetFocusedEditBox((D2WinControlStrc *)(D2WinEditBoxStrc*)gpCreateName);
    if (MCPCONNECT_QueryAddress())
        CHATDLG_OnLevelRestrictToggle(0);
}

// 0x00446780
int __stdcall COMCALLBACK_OpenJoinScreen(int nArg)
{
// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
    CHATDLG_ResetLaunchState();
    gnChatLaunchMode = 3;
    CHATDLG_CreateJoinScreen();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpCreateScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    return 1;
}

// 0x004467D0
int __stdcall COMCALLBACK_OpenCreateScreen(int nArg)
{
    CHATDLG_ResetLaunchState();
    COMCALLBACK_BuildCreateScreen();
    BUTTON_SetIsPressed(gpChatControl_0077B074, 0);
    BUTTON_SetIsPressed(gpJoinScreenButton, 0);
    BUTTON_SetIsPressed(gpControlC_0077B07C, 0);
    return 1;
}

Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pPattern); // 0x00526940

void __fastcall COMCALLBACK_CopyNamePrefix(const char* szName, char* szOut);                               // 0x00446840

// 0x00446810
char* __cdecl COMCALLBACK_StrChr(const char* szString, int nChar)
{
    return strchr(szString, nChar);
}

// 0x00446820
const char* __fastcall COMCALLBACK_SkipNamePrefix(const char* szName)
{
    const char* pFound = SStrChr(szName, '*');
    if (pFound)
    {
        pFound += 1;
        if (*pFound != 0)
            return pFound;
    }
    return szName;
}

// 0x00446840
void __fastcall COMCALLBACK_CopyNamePrefix(const char* szName, char* szOut)
{
    if (*szName != '*')
    {
        const char* pFound = SStrChr(szName, '*');
        if (pFound)
        {
            memcpy(szOut, szName, pFound - szName);
            szOut[pFound - szName] = 0;
            return;
        }
    }
    SStrCopy(szOut, szName, 0x7FFFFFFF);
}

// 0x00446880
int __stdcall SKILLS_Return0(int nUnused)
{
    return 0;
}

// 0x004468F0
int __stdcall COMCALLBACK_SendChatLine(int nUnused)
{
    char szText[0x100];
    const Unicode* wszText = D2Win_10077_EDITBOX_GetText(gpChatEditBox_0077BD94);
    if (!wszText || !sub_00526800(wszText))
    {
        return 1;
    }

    sub_00526F70(szText, wszText, sizeof(szText));
    return CHATDLG_SendChatText(szText, 1);
}

// 0x00446950
int __stdcall COMCALLBACK_OnChatPanelClick(int nArg)
{
    sub_00444020();
    sub_0043D990();
    return 1;
}

// 0x00446970
int __stdcall COMCALLBACK_SendEmoteLine(int nUnused)
{
    char szText[0x12C];
    char szLine[0x12C];
    const Unicode* wszText = D2Win_10077_EDITBOX_GetText(gpChatEditBox_0077BD94);
    if (wszText && sub_00526800(wszText))
    {
        sub_00526F70(szText, wszText, sizeof(szText));
        if (szText[0] != '/')
        {
            const unsigned long dwTick = GetTickCount();
            if (dwTick >= gdwLastCommandTick + 1000)
            {
                gdwLastCommandTick = dwTick;
                sprintf(szLine, "/me %s", szText);
                CHATDLG_SendChatText(szLine, 0);
            }
        }
    }
    return 1;
}

// 0x00446A00
int __stdcall COMCALLBACK_SendAwayCommand(int nUnused)
{
    char szText[AWAY_TEXT_SIZE];
    const unsigned long dwTick = GetTickCount();
    if (dwTick >= gdwLastCommandTick + AWAY_COMMAND_DELAY)
    {
        gdwLastCommandTick = dwTick;
        sprintf(szText, "/away Away from the keyboard.");
        if (!gpLaunchFuncs->pfnIsSocketConnected())
        {
            CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(AWAY_ERROR_STRING), sub_0043E6C0_OnError);
            return 0;
        }
        gpLaunchFuncs->pfnChatCommand(szText);
        EDITBOX_SetText(gpChatEditBox_0077BD94, 0);
    }
    return 1;
}

// 0x00446A90
void __stdcall COMCALLBACK_RemoveTableString(Unicode* pText)
{
    D2_ASSERT(sub_00526800(pText) < 500, 0x300);
    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    const int nPatternLength = sub_00526800(pPattern);
    Unicode* pFound = sub_00526940_FindSubstring(pText, pPattern);
    while (pFound && pFound[nPatternLength].wChar)
    {
        memmove(pFound, &pFound[nPatternLength + 1], (sub_00526800(pFound) - nPatternLength) * sizeof(Unicode));
        pFound = sub_00526940_FindSubstring(pText, pPattern);
    }
}

// 0x00446B30
int __fastcall COMCALLBACK_ShowText(int nArg, const char* szText)
{
    Unicode wszText[0x240];
    for (int i = 0; i < 0x240; i++)
        wszText[i].wChar = 0;
    Unicode::win2Unicode(wszText, szText, 0x240);
    CHATDLG_ShowChannelText(wszText);
    return 1;
}

// 0x00446B70
static int COMCALLBACK_PlayAd(ComAdStrc* pAd)
{
    char szTempFile[260];
    char szTempPath[260];
    unsigned long nWritten;

    SMACK_DeleteFile(gpSmack);
    if (!GetTempPathA(260, szTempPath))
    {
        *(unsigned short*)szTempPath = '.';
    }
    if (GetTempFileNameA(szTempPath, "BNetAd", 0, szTempFile) > 0)
    {
        DeleteFileA(gszTempFile);
        void* hFile = FOG_CreateFileA(szTempFile, 0x40000000, 0, 0, 4, 0x8000000, 0);
        if (hFile != (void*)-1)
        {
            FOG_WriteFile(hFile, pAd->pBuffer, pAd->nSize, &nWritten, 0);
// build: symbol ?FOG_CloseFile@* 0x004069A0
            FOG_CloseFile(hFile);
        }
        char* pExt = strrchr(pAd->szName, '.');
        pExt++;
        int ch = *pExt;
        int n = tolower(ch);
        SMACK_Decode(gpSmack, szTempFile, n);
        int i = 0;
        char c;
        do
        {
            c = szTempFile[i];
            gszTempFile[i] = c;
            i++;
        } while (c);
    }
    gpLaunchContext = pAd->pContext;
    FOG_Free(pAd->szName, ".\\Src\\ComCallback.cpp", 0x386, 0);
    FOG_Free(pAd->pData, ".\\Src\\ComCallback.cpp", 0x387, 0);
    return 1;
}

// 0x00446CA0
int __cdecl COMCALLBACK_PlayTempSmack()
{
    if (gszTempFile[0] && GetFileAttributesA(gszTempFile) != (unsigned long)-1)
    {
        const char* pExt = strrchr(gszTempFile, '.') + 1;
        SMACK_Decode((D2WinSmackStrc*)gpSmack, gszTempFile, tolower(*pExt));
        return 1;
    }
    return 0;
}

// 0x00446D00
static inline int COMCALLBACK_SetText(const char* szText)
{
    SStrCopy(gszText_00798CF8, szText, 0x32);
    return 1;
}

// 0x00446D20
int __stdcall COMCALLBACK_IgnoreChatEvent(int nArg1, int nArg2)
{
    return 1;
}

int __stdcall sub_M121_Emit_00446D00(const char* szText) { return COMCALLBACK_SetText(szText); }

// 0x00446D30
static int COMCALLBACK_GetUserRank(D2MultiChannelUserStrc* pUser)
{
    const unsigned int dwFlags = pUser->dwFlags;
    if (dwFlags & 2)
        return 4;
    if (dwFlags & 8)
        return 3;
    if (dwFlags & 1)
        return 2;
    if (dwFlags & 4)
        return 1;
    return 0;
}

// 0x00446D60
static int COMCALLBACK_Classify(int code) {
 switch(code) {
 case 0:
 case 1:
 case 6:
 case 9:
  return 0;
 default:
  return 1;
 }
}

static int CHANNEL_IsMaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    case 2:
    case 3:
    case 4:
    case 5:
    case 7:
    case 8:
        return 1;
    }

    return 1;
}

// 0x00446D90
static unsigned char COMCALLBACK_ParseStatString(D2MultiChannelUserStrc* pUser, unsigned int nFlags, const unsigned char* pStat)
{
    unsigned char nResult = 7;
    int bValid = 0;
    int nLength = strlen((const char*)pStat);
    pUser->wFlags = 0;

    if (nFlags & 2)
    {
        nResult = 0x13;
    }
    else if (nFlags & 8)
    {
        nResult = 0x14;
        goto default_look;
    }
    else if (nFlags & 1)
    {
        nResult = 0x12;
        goto default_look;
    }
    else if (nFlags & 4)
    {
        nResult = 0x17;
        goto default_look;
    }
    else if (nFlags & 0x101000)
    {
        nResult = 0x15;
        goto default_look;
    }
    else if (nLength < 4)
    {
        nResult = 7;
        goto default_look;
    }
    else
    {
        bValid = 1;
    }

    if (nLength >= 4)
    {
        pUser->dwCode = *(const unsigned int*)pStat;
        nLength -= 4;
        pStat += 4;

        switch (pUser->dwCode)
        {
        case 0x44324456:
        case 0x44325354:
        case 0x44325850:
        {
            if (!*pStat)
            {
                if (nResult == 7)
                {
                    nResult = 0x18;
                }

                pUser->dwCode = 0x554E4B4E;
                strcpy(pUser->szText, pUser->szName);
                break;
            }

            D2_ASSERT(nLength > 0, 0x579);

            char* pDst = pUser->szRealm;
            while (*pStat != ',')
            {
                *pDst++ = *pStat++;
            }
            ++pStat;
            *pDst = 0;

            pDst = pUser->szText;
            while (*pStat != ',')
            {
                *pDst++ = *pStat++;
            }
            ++pStat;
            *pDst = 0;

            FOG_Decode14BitsFromString(pStat);
            pStat += 2;

            int i;
            for (i = 0; i < 11; ++i)
            {
                pUser->aComponents[i] = *pStat++;
            }
            for (; i < 16; ++i)
            {
                pUser->aComponents[i] = 0xFF;
            }

            if (!pUser->aComponents[0])
            {
                goto unknown_code;
            }

            pUser->nClass = *pStat++ - 1;

            for (i = 0; i < 11; ++i)
            {
                pUser->aColors[i] = *pStat++;
            }
            for (; i < 16; ++i)
            {
                pUser->aColors[i] = 0xFF;
            }

            pUser->wLevel = *pStat++;

            pUser->wFlags = FOG_Decode14BitsFromString(pStat);
            unsigned int wFlags = pUser->wFlags;
            pUser->bFlagA0 = (wFlags >> 2) & 1;
            pUser->bFlagA4 = (wFlags >> 3) & 1;
            pUser->bFlagA8 = (wFlags >> 5) & 1;
            pUser->bFlagAC = (wFlags >> 6) & 1;
            pStat += 2;

            if (bValid)
            {
                if (pUser->bFlagA0 && pUser->bFlagA4)
                {
                    nResult = CHANNEL_IsMaleClass(pUser->nClass) ? 8 : 9;
                }
                else
                {
                    nResult = pUser->nClass;
                }
            }

            pUser->wW8C = FOG_Decode14BitsFromString(pStat);
            pStat += 2;

            pUser->nB94 = *pStat++;
            pUser->nB94 = pUser->nB94 == 0xFF ? 0 : pUser->nB94;
            pUser->nB95 = *pStat++;
            pUser->nB95 = pUser->nB95 == 0xFF ? 0 : pUser->nB95;
            pUser->nB96 = *pStat;
            pUser->nB96 = pUser->nB96 == 0xFF ? 0 : pUser->nB96;

            if (bValid)
            {
                return nResult;
            }
            break;
        }

        case 0x43484154:
            if (bValid)
            {
                nResult = 0x16;
            }
            break;

        case 0x4452544C:
        case 0x44534852:
        case 0x44545354:
            if (bValid)
            {
                nResult = 0xA;
            }
            break;

        case 0x53544152:
        case 0x4A535452:
        case 0x53534852:
            if (bValid)
            {
                nResult = 0xD;
            }
            break;

        case 0x53455850:
            if (bValid)
            {
                nResult = 0xE;
            }
            break;

        case 0x5732424E:
            if (bValid)
            {
                nResult = 0xF;
            }
            break;

        case 0x57415233:
        case 0x57335850:
            if (bValid)
            {
                nResult = 0x10;
            }
            break;

        default:
unknown_code:
            if (bValid)
            {
                pUser->dwCode = 0x554E4B4E;
                nResult = 7;
                strcpy(pUser->szText, pUser->szName);
            }
            break;
        }
    }

default_look:
    for (int i = 0; i < 16; ++i)
    {
        if (i == 1)
        {
            pUser->aComponents[i] = 1;
        }
        else
        {
            pUser->aComponents[i] = 0;
        }
        pUser->aColors[i] = 0xFF;
    }

    return nResult;
}

// 0x004471B0
static void COMCALLBACK_UpdateUserText(D2MultiChannelUserStrc* pUser)
{
    Unicode wszName[51];
    Unicode wszAccount[17];
    Unicode wszS97[51];
    Unicode wszRealm[32];

    if (pUser->szName[0] == '*')
    {
        Unicode::win2Unicode(wszName, pUser->szName, 50);
        wszAccount[0] = 0;
    }
    else
    {
        char szAccount[50] = { 0 };
        Unicode wszCharName[50];

        const char* szName = pUser->szName;
        if (*szName == '*')
        {
            SStrCopy(szAccount, szName, 0x7FFFFFFF);
        }
        else
        {
            const char* pStar = SStrChr(szName, '*');
            if (pStar)
            {
                memcpy(szAccount, szName, pStar - szName);
                szAccount[pStar - szName] = 0;
            }
            else
            {
                SStrCopy(szAccount, szName, 0x7FFFFFFF);
            }
        }

        const char* szCharName = SStrChr(szName, '*');
        if (!szCharName || !*++szCharName)
        {
            szCharName = szName;
        }

        Unicode::win2Unicode(wszCharName, szCharName, 50);
// build: symbol ?gszStar@* 0x006D5830
        Unicode::win2Unicode(wszName, gszStar, 50);
        Unicode::strncat(wszName, wszCharName, 50);
        Unicode::win2Unicode(wszAccount, szAccount, 16);
    }

    Unicode::win2Unicode(wszS97, pUser->szS97, 50);
    Unicode::win2Unicode(wszRealm, pUser->szRealm, 32);

    const unsigned int dwCode = pUser->dwCode;
    unsigned short nLevel = 0;
    if (dwCode == 0x44324456 || dwCode == 0x44325354 || dwCode == 0x44325850)
    {
        nLevel = pUser->wLevel;
    }

    sub_00504270_SetCompositeText(pUser->pComposite, wszName, wszAccount, wszS97, wszRealm, nLevel, dwCode);
}

int __fastcall EmitClassify(int code) { return COMCALLBACK_Classify(code); }

// 0x00447390
static int COMCALLBACK_CompareNames(const char* szNameA, const char* szNameB)
{
    const char* szA = strchr(szNameA, '*');
    if (!szA)
        szA = szNameA;
    else
        szA += 1;
    const char* szB = strchr(szNameB, '*');
    if (!szB)
        szB = szNameB;
    else
        szB += 1;
    return strcmp(szA, szB);
}

static inline const char* sub_SkipStarPrefix(const char* szName)
{
    const char* pFound = SStrChr(szName, '*');
    if (pFound && *++pFound)
        return pFound;
    return szName;
}

// 0x00447400
void __fastcall COMCALLBACK_SetNamedValue(const char* szName, const char* szValue)
{
    D2NamedValueStrc* pNode = s_pNamedValues_00798F38;
    D2NamedValueStrc* pPrevious = 0;
    const char* szKey = sub_SkipStarPrefix(szName);
    for (; pNode; pNode = pNode->pNext)
    {
        if (!strcmp(sub_SkipStarPrefix(pNode->szName), szKey))
            break;
        pPrevious = pNode;
    }
    if (pNode)
    {
        strcpy(pNode->szValue, szValue);
        return;
    }
    if (gnChannelEntries >= 0x400)
    {
        pNode = s_pNamedValues_00798F38;
        s_pNamedValues_00798F38 = s_pNamedValues_00798F38->pNext;
        FOG_Free(pNode, ".\\Src\\ComCallback.cpp", 0x936, 0);
        --gnChannelEntries;
    }
    D2NamedValueStrc* pNew = (D2NamedValueStrc*)FOG_Alloc(sizeof(D2NamedValueStrc), ".\\Src\\ComCallback.cpp", 0x93A, 0);
    strcpy(pNew->szName, szName);
    strcpy(pNew->szValue, szValue);
    pNew->pNext = 0;
    if (pPrevious)
        pPrevious->pNext = pNew;
    else
        s_pNamedValues_00798F38 = pNew;
    ++gnChannelEntries;
}

// 0x00447560
void __fastcall COMCALLBACK_SplitName(const char* szName, char* szTitle, char* szOut)
{
    *szOut = 0;
    *szTitle = 0;
    if (*szName == '*')
    {
        SStrCopy(szOut, szName, 0x7FFFFFFF);
        return;
    }
    char* pAt = SStrChr(szName, '@');
    char* pStar = SStrChr(szName, '*');
    if (pAt && pStar && pAt < pStar)
    {
        SStrCopy(szOut, szName, 0x7FFFFFFF);
        *SStrChr(szOut, '*') = 0;
        return;
    }
    D2ChannelEntryStrc* pEntry = gpChannelEntries;
    while (pEntry)
    {
        if (!_stricmp(pEntry->szName, szName))
            break;
        pEntry = pEntry->pNext;
    }
    if (pEntry)
    {
        D2MultiChannelUserStrc* pUser = gpChannelUsers;
        while (pUser)
        {
            if (!_stricmp(pUser->szName, szName))
                break;
            pUser = pUser->pNext;
        }
        if (pUser)
        {
            const unsigned int nFlags = sub_00505330_GetCompositeFlags(pUser->pComposite);
            if ((nFlags & gdwTitleMaskA) || (nFlags & gdwBitMask7))
            {
                SStrCopy(szTitle, D2Win_10160_GetPlayerTitle(pUser->nClass, 3 * ((nFlags >> 5) & 1) + 2 * ((nFlags >> 7) & 1) + ((nFlags >> 6) & 1), (nFlags >> 12) & 1), 0x7FFFFFFF);
            }
        }
        SStrCopy(szOut, pEntry->szAccount, 0x7FFFFFFF);
    }
    if (*szName != '*')
    {
        char* pEnd = SStrChr(szName, '*');
        if (pEnd)
        {
            memcpy(szOut, szName, pEnd - szName);
            szOut[pEnd - szName] = 0;
            return;
        }
    }
    SStrCopy(szOut, szName, 0x7FFFFFFF);
}

D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C
void __cdecl CHATDLG_RefreshChatScreen(); // 0x0043FBD0
__declspec(noinline) void __cdecl CHATDLG_RefreshChatScreen(); // 0x0043FBD0

// 0x00447700
int __fastcall CHATDLG_OnChannelDoesNotExist(int nA, int nB, const char* szText, int nLength)
{
    gpLaunchFuncs->pfnJoinChannel(nLength, 1, 0);
    CHATDLG_RefreshChatScreen();
    return 1;
}

// 0x00447740
static int COMCALLBACK_DispatchMessage(D2LaunchMsgStrc* pMsg)
{
    int nArg = pMsg->nArg;
    char* pArg = pMsg->szName;
    unsigned int nIndex = pMsg->nType;
    const char* szText = pMsg->szText;
    int nLength = strlen(szText);
    if (nIndex < 0x18)
    {
        D2LaunchMsgHandler pfnHandler = gapfnMsgHandlers[nIndex];
        if (pfnHandler)
        {
            int nResult = pfnHandler(nArg, pArg, szText, szText + nLength + 1);
            if (nResult)
                return nResult;
        }
    }
    return 1;
}

// 0x004477A0
void __cdecl COMCALLBACK_RefreshChatButtons()
{
    const Unicode* pText = sub_004FDD90_GetEditText(gpChatEdit);
    int bHasText = 0;
    if (pText && sub_00526800(pText))
        bHasText = 1;

// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
    CONTROL_SetEnabled(gpChatControl_0077B06C, bHasText);
    CONTROL_SetEnabled(gapChatDlgControls, bHasText);
    CONTROL_SetEnabled(gpChatControl_0077B05C, gpSelectedChannelUser && bHasText);

    unsigned int nFlags = 0;
    if (gpSelectedChannelUser && gpSelectedChannelUser->pComposite)
    {
        const unsigned int nComposite = D2Win_10155((D2CompositeUnitStrc*)gpSelectedChannelUser->pComposite);
        nFlags = gdwBitMasks[9] & nComposite;
    }

    CONTROL_SetEnabled(gpChatControl_0077B064, gpSelectedChannelUser && !nFlags);
    CONTROL_SetEnabled(gpChatControl_0077B068, gpSelectedChannelUser && nFlags);
}

// 0x00447870
void __fastcall COMCALLBACK_AppendNumberText(Unicode* pText, int nValue)
{
    char szNumber[4];

    Unicode wszBuffer[0x200];
    Unicode wszNumber[3];
    sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
    wsprintfA(szNumber, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszNumber, szNumber, 2);
    sub_00526700(wszBuffer, wszNumber);

    if (!pText[0].wChar)
    {
        sub_005267E0(pText, wszBuffer);
    }
    else
    {
        D2_ASSERT(sub_00526800(pText) < 500, 0xB7D);
        sub_00526700(pText, wszBuffer);
    }
}

// 0x00447940
void __fastcall COMCALLBACK_PrependNumberText(Unicode* pText, int nValue)
{
    char szNumber[4];

    Unicode wszBuffer[0x200];
    Unicode wszNumber[3];
    sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
    wsprintfA(szNumber, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszNumber, szNumber, 2);
    sub_00526700(wszBuffer, wszNumber);

    if (!pText[0].wChar)
    {
        sub_005267E0(pText, wszBuffer);
    }
    else
    {
        D2_ASSERT(sub_00526800(pText) < 500, 0xB9B);
        sub_00526700(wszBuffer, pText);
        sub_005267E0(pText, wszBuffer);
    }
}

// 0x00447A10
int __cdecl COMCALLBACK_PumpMessages()
{
    int nType;
    D2LaunchMsgStrc tMsg;
    if (!gpLaunchFuncs->pfnGetMessage(&nType, &tMsg))
        return 0;

    switch (nType)
    {
    case 0:
        COMCALLBACK_DispatchMessage(&tMsg);
        break;
    case 2:
        SStrCopy(gszText_00798CF8, (char*)&tMsg, 0x32);
        break;
    case 3:
        COMCALLBACK_PlayAd((ComAdStrc*)&tMsg);
        break;
    }
    return 1;
}

// 0x00447A90
int __stdcall COMCALLBACK_OnActivate(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00444020();
    CHATDLG_ActivateChatEdit();
    return 1;
}

// 0x00447AB0
static int __stdcall COMCALLBACK_AddChatLine(const char* szText, int nColor)
{
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, nColor);
    return 1;
}

// 0x00447B00
static void __stdcall COMCALLBACK_PrintChannelLine(const char* szText, int nPrefix, const char* szName, int nColor)
{
    Unicode wszName[0x240];
    Unicode wszText[0x240];
    Unicode::win2Unicode(wszName, szName, 0x240);
    Unicode::win2Unicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszName);
    COMCALLBACK_RemoveTableString(wszText);
    COMCALLBACK_PrependNumberText(wszName, nPrefix);
    COMCALLBACK_AppendNumberText(wszName, nColor);
    sub_00526700(wszName, wszText);
    CHATDLG_PrintText(wszName, nColor);
}

static inline int CHAN_GetRank(const D2ChannelFlagsStrc* pFlags)
{
    const D2ChannelFlagsStrc tFlags = *pFlags;
    if (tFlags.dwFlags & 2)
        return 4;
    if (tFlags.dwFlags & 8)
        return 3;
    if (tFlags.dwFlags & 1)
        return 2;
    if (tFlags.nFlags & 4)
        return 1;
    return 0;
}

static inline int CHAN_GetLevelClass(D2ChatChannelMemberStrc* pUser)
{
    const int nLevel = pUser->nLevel8A;
    if (pUser->bExp8A)
    {
        if (nLevel >= 15)
            return 3;
        if (nLevel >= 10)
            return 2;
        return nLevel >= 5;
    }
    if (nLevel >= 12)
        return 3;
    if (nLevel >= 8)
        return 2;
    return nLevel >= 4;
}

// 0x00447BB0
void __cdecl COMCALLBACK_RefreshChannelList()
{
    int n;
    if (gpChannelUsers)
    {
        D2ChatChannelMemberStrc* pSorted = (D2ChatChannelMemberStrc*)gpChannelUsers;
        D2ChatChannelMemberStrc** ppNext = (D2ChatChannelMemberStrc**)&gpChannelUsers->pNext;
        D2ChatChannelMemberStrc* pList = *ppNext;
        _ReadWriteBarrier();
        *ppNext = 0;
        while (pList)
        {
            n = CHAN_GetRank(&pList->tFlags90);
            D2ChatChannelMemberStrc* pPrev = 0;
            int bInserted = 0;
            D2ChatChannelMemberStrc* pCur = pSorted;
            while (pCur && !bInserted)
            {
                if (n > CHAN_GetRank(&pCur->tFlags90))
                {
                    D2ChatChannelMemberStrc* pInsert = pList;
                    pList = pInsert->pNext;
                    pInsert->pNext = pCur;
                    if (pPrev)
                    {
                        pPrev->pNext = pInsert;
                        bInserted = 1;
                    }
                    else
                    {
                        pSorted = pInsert;
                        bInserted = 1;
                    }
                }
                else
                {
                    pPrev = pCur;
                    pCur = pCur->pNext;
                }
            }

            if (!bInserted)
            {
                pPrev->pNext = pList;
                D2ChatChannelMemberStrc* pLast = pList;
                pList = pLast->pNext;
                pLast->pNext = 0;
            }
        }
        gpChannelUsers = (D2MultiChannelUserStrc*)pSorted;
    }

    D2ChatChannelMemberStrc* pUser = (D2ChatChannelMemberStrc*)gpChannelUsers;
    int nY = 0x46;
    n = 0;
    if (gpChannelUsers)
    do
    {
        unsigned int nState;
        D2ChannelFlagsStrc tFlags;
        if (n >= gnChannelScroll && n < gnChannelScroll + 11)
        {
            D2Win_10152(pUser->pComposite, nY);
            nState = 0xF;
            CHAN_SETBIT(nState, 11, pUser->tFlags90.dwFlags & 9);
            const unsigned short wFlags = pUser->wFlags8A;
            CHAN_SETBIT(nState, 4, wFlags & 8);
            CHAN_SETBIT(nState, 5, wFlags & 4);
            CHAN_SETBIT(nState, 12, wFlags & 0x20);
            const int nLevelClass = CHAN_GetLevelClass(pUser);
            CHAN_SETBIT(nState, 6, nLevelClass & 1);
            CHAN_SETBIT(nState, 7, nLevelClass & 2);
            if (n & 1)
                nState |= gdwBitMasks[8];
            CHAN_SETBIT(nState, 9, pUser->tFlags90.nFlags & 0x20);
            CHAN_SETBIT(nState, 10, pUser == (D2ChatChannelMemberStrc*)gpSelectedChannelUser);
            nY += 0x3C;
        }
        else
        {
            tFlags = pUser->tFlags90;
            nState = 0;
            CHAN_SETBIT(nState, 11, tFlags.dwFlags & 9);
            const unsigned short wFlags = pUser->wFlags8A;
            CHAN_SETBIT(nState, 4, wFlags & 8);
            CHAN_SETBIT(nState, 5, wFlags & 4);
            CHAN_SETBIT(nState, 12, wFlags & 0x20);
            int bDiffers = gpCharInfo->nByte3C2 != pUser->nValue94;
            const unsigned short wCharFlags = *(const unsigned short*)gpCharInfo->aFlags1EF;
            bDiffers |= (wCharFlags & 4) && !pUser->nValue0xA0;
            bDiffers |= !(wCharFlags & 4) && pUser->nValue0xA0;
            bDiffers |= (wCharFlags & 0x20) && !pUser->nValue0xA8;
            bDiffers |= !(wCharFlags & 0x20) && pUser->nValue0xA8;
            CHAN_SETBIT(nState, 13, bDiffers);
            const int nLevelClass = CHAN_GetLevelClass(pUser);
            CHAN_SETBIT(nState, 6, nLevelClass & 1);
            CHAN_SETBIT(nState, 7, nLevelClass & 2);
            CHAN_SETBIT(nState, 9, tFlags.dwFlags & 0x20);
            CHAN_SETBIT(nState, 10, pUser == (D2ChatChannelMemberStrc*)gpSelectedChannelUser);
        }
        D2Win_10156(pUser->pComposite, nState);
        n++;
        pUser = pUser->pNext;
    } while (pUser);
}

// 0x00447FD0
static void __stdcall COMCALLBACK_UpdateUser(D2MultiChannelUserStrc* pUser, const unsigned char* pStat, unsigned int nFlags, const char* szName)
{
    pUser->dwFlags = nFlags;
    const unsigned char nResult = COMCALLBACK_ParseStatString(pUser, nFlags, pStat);
    SStrCopy(pUser->szName, szName, 0x7FFFFFFF);

    int nMode = 5;
    if ((pUser->wFlags & 4) && !(pUser->wFlags & 8) && (FOG_IsExpansion() || nResult < 5))
    {
        nMode = 1;
    }

    sub_00504F80_UpdateComposite(pUser->pComposite, nResult, nMode, pUser->aComponents, pUser->aColors);
    COMCALLBACK_UpdateUserText(pUser);
    COMCALLBACK_RefreshChannelList();
}

// 0x00448050
void __cdecl COMCALLBACK_ClearSelectedUser()
{
    if (gpSelectedChannelUser)
    {
        D2_ASSERT((D2CompositeUnitStrc*)gpSelectedChannelUser->pComposite, 0x85A);
        const unsigned int nFlags = D2Win_10155((D2CompositeUnitStrc*)gpSelectedChannelUser->pComposite);
        D2Win_10156((D2CompositeUnitStrc*)gpSelectedChannelUser->pComposite, nFlags & gdwInvBitMasks[10]);
        gpSelectedChannelUser = 0;
// build: symbol ?gnSelectedLine@* 0x0070EC1C
        gnSelectedLine = -1;
    }

// build: symbol ?GAME_IsLaunchExpansion@* 0x0043DB10
    if (!GAME_IsLaunchExpansion())
    {
        COMCALLBACK_RefreshChatButtons();
    }
}

// 0x004480D0
int __fastcall COMCALLBACK_OnUserUpdate(unsigned int nFlags, int nUnused, const char* szName, const unsigned char* pStat)
{
    D2MultiChannelUserStrc* pUser = gpChannelUsers;
    if (gpChannelUsers)
    {
        do
        {
            if (!strcmp(pUser->szName, szName))
            {
                COMCALLBACK_UpdateUser(pUser, pStat, nFlags, szName);
                return 1;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }

    return 0;
}

// 0x00448150
int __stdcall COMCALLBACK_PrintNormalText(int nUnused, const char* szText)
{
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 0);
    return 1;
}

static const char* SkipStarPrefix_Inl(const char* szName)
{
    const char* p = SStrChr(szName, '*');
    if (p)
    {
        p++;
        if (*p)
        {
            return p;
        }
    }
    return szName;
}

// 0x004481B0
static void __stdcall COMCALLBACK_PrintNamedLine(const char* szText, int nPrefix, const char* szName, int nColor)
{
    char szBuffer[0x100];
    sprintf(szBuffer, "<%s> ", szName);
    COMCALLBACK_PrintChannelLine(szText, nPrefix, szBuffer, nColor);
}

// 0x004481F0
void __fastcall COMCALLBACK_PrintOwnLine(const char* szText)
{
    char szName[0x100];
    char szOut[0x100];
    char szPlain[0x100];
    char szTitle[0x100];
    SStrCopy(szName, gpLaunchFuncs->pfnGetUserName(), 0x7FFFFFFF);
    int nPrefix = 4;
    int nColor = 0;
    D2MultiChannelUserStrc* pUser = gpChannelUsers;
    if (gpChannelUsers)
    {
        do
        {
            if (!strcmp(SkipStarPrefix_Inl(pUser->szName), szName))
            {
                SStrCopy(szName, pUser->szName, 0x7FFFFFFF);
                if (pUser->dwFlags & 2)
                    nPrefix = 0;
                else if (pUser->dwFlags & 1)
                    nPrefix = nColor = 3;
                else if (pUser->dwFlags & 8)
                    nPrefix = nColor = 3;
                break;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }
    COMCALLBACK_SplitName(szName, szTitle, szPlain);
    if (strlen(szPlain))
    {
        if (strlen(szTitle))
            sprintf(szOut, "<%s%s> ", szTitle, szPlain);
        else
            sprintf(szOut, "<%s> ", szPlain);
    }
    else
    {
        sprintf(szOut, "<%s> ", szName);
    }
    COMCALLBACK_PrintChannelLine(szText, nPrefix, szOut, nColor);
}

// 0x00448370
int __stdcall COMCALLBACK_OnChannelTalk(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szOut[0x100];
    COMCALLBACK_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
        return 1;

    int nPrefix = 4;
    int nColor = 0;
    D2MultiChannelUserStrc* pUser = gpChannelUsers;
    if (gpChannelUsers)
    {
        do
        {
            if (!strcmp(pUser->szName, szSender))
            {
                if (pUser->dwFlags & 2)
                    nPrefix = 0;
                else if (pUser->dwFlags & 1)
                    nPrefix = nColor = 3;
                else if (pUser->dwFlags & 8)
                    nPrefix = nColor = 3;
                break;
            }
            pUser = pUser->pNext;
        }
        while (pUser);
    }
    if (strlen(szName))
    {
        if (strlen(szTitle))
            sprintf(szOut, "%s%s", szTitle, szName);
        else
            strcpy(szOut, szName);
        COMCALLBACK_PrintNamedLine(szMessage, nPrefix, szOut, nColor);
    }
    else
    {
        COMCALLBACK_PrintNamedLine(szMessage, nPrefix, szSender, nColor);
    }
    return 1;
}

// 0x004484E0
int __stdcall COMCALLBACK_PrintInfoText(int nUnused, const char* szText)
{
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 3);
    return 1;
}

// 0x00448540
int __stdcall COMCALLBACK_PrintErrorText(int nUnused, const char* szText)
{
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 1);
    return 1;
}

// 0x004485A0
int __stdcall COMCALLBACK_OnChannelFull(int nUnused, const char* szText)
{
    char szBuffer[0x1F4];
    sprintf(szBuffer, "The channel \"%s\" is full. If you are having problems using Battle.net commands, please click the Help button.", szText);
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szBuffer, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 1);
    return 1;
}

// 0x00448610
int __stdcall COMCALLBACK_OnChannelRestricted(int nUnused, const char* szText)
{
    char szBuffer[0x1F4];
    sprintf(szBuffer, "The channel \"%s\" is restricted. If you are having problems using Battle.net commands, please click the Help button.", szText);
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szBuffer, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 1);
    return 1;
}

// 0x00448680
static void COMCALLBACK_PrintEmote(const char* szName, const char* szMessage)
{
    char szText[0x1F4];
    sprintf(szText, "*%s %s*", szName, szMessage);
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 5);
}

// 0x004486F0
int __stdcall COMCALLBACK_OnEmote(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szOut[0x100];
    COMCALLBACK_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
    {
        return 1;
    }
    if (strlen(szName))
    {
        if (strlen(szTitle))
        {
            sprintf(szOut, "%s%s", szTitle, szName);
        }
        else
        {
            strcpy(szOut, szName);
        }
        COMCALLBACK_PrintEmote(szOut, szMessage);
    }
    else
    {
        COMCALLBACK_PrintEmote(szSender, szMessage);
    }
    return 1;
}

// 0x00448810
static void __stdcall COMCALLBACK_PrintWhisper(const char* szSender, const char* szAccount, const char* szMessage)
{
    char szText[0x1F4];
    strcpy(gszLastWhisperer, szSender);
    if (*szAccount && (*szAccount != '*' || strcmp(SkipStarPrefix_Inl(szAccount), SkipStarPrefix_Inl(szSender))))
    {
        sprintf(szText, "%s (*%s) whispers: %s", szAccount, szSender, szMessage);
    }
    else
    {
        sprintf(szText, "%s whispers: %s", szAccount, szMessage);
    }
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 2);
}

// 0x00448920
int __stdcall COMCALLBACK_OnWhisper(const char* szSender, const char* szMessage)
{
    char szName[0x100];
    char szTitle[0x100];
    char szAccount[0x100];
    COMCALLBACK_SplitName(szSender, szTitle, szName);
    if (sub_00611560_GetSquelchList()->IsSquelched(szSender) || sub_00611560_GetSquelchList()->IsFiltered(szMessage))
    {
        return 1;
    }
    if (strlen(szName))
    {
        if (strlen(szTitle))
        {
            sprintf(szAccount, "%s%s", szTitle, szName);
        }
        else
        {
            strcpy(szAccount, szName);
        }
        COMCALLBACK_PrintWhisper(SkipStarPrefix_Inl(szSender), szAccount, szMessage);
    }
    else
    {
        COMCALLBACK_PrintWhisper(SkipStarPrefix_Inl(szSender), 0, szMessage);
    }
    return 1;
}

// 0x00448A60
static void COMCALLBACK_PrintWhisperSent(const char* szName, const char* szText)
{
    char szLine[0x1F4];
    sprintf(szLine, "You whisper to %s: %s", szName, szText);
    Unicode wszLine[0x240];
    sub_00526E40_Utf8ToUnicode(wszLine, szLine, 0x240);
    COMCALLBACK_RemoveTableString(wszLine);
    CHATDLG_PrintText(wszLine, 2);
}

// 0x00448AD0
int __stdcall COMCALLBACK_OnWhisperSent(const char* szTarget, const char* szText)
{
    char szName[0x100];
    char szTitle[0x100];
    char szAccount[0x100];
    COMCALLBACK_SplitName(szTarget, szTitle, szName);
    if (strlen(szName))
    {
        if (strlen(szTitle))
        {
            sprintf(szAccount, "%s%s", szTitle, szName);
        }
        else
        {
            strcpy(szAccount, szName);
        }
        COMCALLBACK_PrintWhisperSent(szAccount, szText);
    }
    else
    {
        COMCALLBACK_PrintWhisperSent(SkipStarPrefix_Inl(szTarget), szText);
    }
    return 1;
}

// calling-convention shim (not game code)
int __fastcall sub_00446D30_Shim(D2MultiChannelUserStrc* pLeft, D2MultiChannelUserStrc* pRight)
{
    return COMCALLBACK_GetUserRank(pRight) - COMCALLBACK_GetUserRank(pLeft);
}

// 0x00448C70
int __stdcall COMCALLBACK_ButtonCallback(D2ChatMessageStrc* pMsg)
{
    int nButton;
    nButton = 0;
    for (;;)
    {
        if (!(nButton < 11))
            break;
        if (pMsg->pControl == gapChatButtons[nButton])
            goto found;
        ++nButton;
    }
    return 0;
found:
    const int nLine = gnChannelUserOffset_00798F44 + nButton;
    if (pMsg->nMessage == 0x205)
    {
        D2MultiChannelUserStrc* pUser = gpChannelUsers;
        for (int n = 0; pUser; ++n, pUser = pUser->pNext)
        {
            if (n == nLine)
            {
                CHATDLG_DestroyProfileControls();
                const char* szName = pUser->szName;
                const char* szCompare = SStrChr(szName, '*');
                if (szCompare && szCompare[1])
                    ++szCompare;
                else
                    szCompare = szName;
                if (!strcmp(szCompare, gpCharInfo->szAccount))
                {
                    CHATDLG_ShowProfileDialog(pUser->szText, pUser->bFlagA0, pUser->bFlagA8);
                    return 1;
                }
                CHATDLG_ShowUserInfoDialog(szName, pUser->szText, pUser->bFlagA0, pUser->bFlagA8);
                return 1;
            }
        }
        return 1;
    }
    const unsigned int nTick = GetTickCount();
    if (nLine == gnSelectedLine)
    {
        COMCALLBACK_ClearSelectedUser();
        return 1;
    }
    if (nLine < gnChannelUserCount_00798F40)
    {
        COMCALLBACK_ClearSelectedUser();
        D2MultiChannelUserStrc* pUser = gpChannelUsers;
        for (int n = 0; pUser; ++n, pUser = pUser->pNext)
        {
            if (n == nLine)
            {
                D2_ASSERT(pUser->pComposite,0x135);
                const unsigned int nFlags = D2Win_10155((D2CompositeUnitStrc*)pUser->pComposite);
                D2Win_10156((D2CompositeUnitStrc*)pUser->pComposite, gdwBitMasks[10] | nFlags);
                gpSelectedChannelUser = pUser;
                gnSelectedLine = nLine;
                gdwSelectionTick = nTick;
                COMCALLBACK_RefreshChatButtons();
            }
        }
    }
    return 1;
}

// 0x00448E30
int __stdcall COMCALLBACK_SquelchSelectedUser(int nUnused)
{
    char szName[0x100];
    char szText[0x100];
    if (!gpSelectedChannelUser)
    {
        return 1;
    }

    strcpy(szName, gpSelectedChannelUser->szName);
    const unsigned long dwTick = GetTickCount();
    if (dwTick < gdwLastCommandTick + 1000)
    {
        return 1;
    }

    gdwLastCommandTick = dwTick;
    char* pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    sprintf(szText, "/squelch *%s", pName);
    COMCALLBACK_ClearSelectedUser();
    if (!gpLaunchFuncs->pfnIsSocketConnected())
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 0;
    }

    gpLaunchFuncs->pfnChatCommand(szText);
    EDITBOX_SetText(gpChatEditBox_0077BD94, 0);
    pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    if (SStrCmpI(pName, gpCharInfo->szAccount, 0x7FFFFFFF))
    {
        sub_00611560_GetSquelchList()->Squelch(szName);
    }
    return 1;
}

// 0x00448F60
int __stdcall COMCALLBACK_UnsquelchSelectedUser(int nUnused)
{
    char szName[0x100];
    char szText[0x100];
    if (!gpSelectedChannelUser)
    {
        return 1;
    }

    strcpy(szName, gpSelectedChannelUser->szName);
    const unsigned long dwTick = GetTickCount();
    if (dwTick < gdwLastCommandTick + 1000)
    {
        return 1;
    }

    gdwLastCommandTick = dwTick;
    char* pName = SStrChr(szName, '*');
    if (!pName || !*++pName)
    {
        pName = szName;
    }
    sprintf(szText, "/unsquelch *%s", pName);
    COMCALLBACK_ClearSelectedUser();
    if (!gpLaunchFuncs->pfnIsSocketConnected())
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 0;
    }

    gpLaunchFuncs->pfnChatCommand(szText);
    EDITBOX_SetText(gpChatEditBox_0077BD94, 0);
    sub_00611560_GetSquelchList()->Unsquelch(szName);
    return 1;
}

// 0x00449050
D2MultiChannelUserStrc* __stdcall COMCALLBACK_AddChannelUser(const char* szName, const unsigned char* pStat, unsigned int nFlags)
{
    D2MultiChannelUserStrc* pUser = gpChannelUsers;
    if (gpChannelUsers)
    {
        while (pUser)
        {
            const char* szUserName = strchr(pUser->szName, '*');
            szUserName = !szUserName ? pUser->szName : szUserName + 1;
            const char* szNewName = strchr(szName, '*');
            szNewName = !szNewName ? szName : szNewName + 1;
            if (!strcmp(szUserName, szNewName))
            {
                COMCALLBACK_UpdateUser(pUser, pStat, nFlags, szName);
                return pUser;
            }
            pUser = pUser->pNext;
        }
    }

    pUser = (D2MultiChannelUserStrc*)FOG_Alloc(sizeof(D2MultiChannelUserStrc), ".\\Src\\ComCallback.cpp", 0x6D4, 0);
    memset(pUser, 0, sizeof(D2MultiChannelUserStrc));
    strcpy(pUser->szName, szName);
    pUser->dwFlags = nFlags;

    const unsigned char nResult = COMCALLBACK_ParseStatString(pUser, nFlags, pStat);
    int nMode = 5;
    if ((pUser->wFlags & 4) && !(pUser->wFlags & 8) && !(pUser->dwFlags & 2) && (FOG_IsExpansion() || nResult < 5))
    {
        nMode = 1;
    }

    pUser->pComposite = sub_005066C0(nResult, nMode, pUser->aComponents, pUser->aColors);
    if (!pUser->pComposite)
    {
        pUser->nClass = 7;
        for (int i = 0; i < 16; ++i)
        {
            if (i == 1)
            {
                pUser->aComponents[i] = 1;
            }
            else
            {
                pUser->aComponents[i] = 0;
            }
            pUser->aColors[i] = 0xFF;
        }

        pUser->pComposite = sub_005066C0(pUser->nClass, 5, pUser->aComponents, pUser->aColors);
    }

    D2_ASSERT(pUser->pComposite, 0x708);
    sub_005052F0(pUser->pComposite, 0x23B);
    sub_005051A0(pUser->pComposite, 0);

    if (!gbRandSeeded)
    {
        srand(GetTickCount());
        gbRandSeeded = 1;
    }

    const int nFrames = D2Win_10169(pUser->pComposite) << 8;
    sub_00505260(pUser->pComposite, rand() % nFrames);
    COMCALLBACK_UpdateUserText(pUser);

    if (gpChannelUsers)
    {
        D2MultiChannelUserStrc* pLast = gpChannelUsers;
        D2MultiChannelUserStrc** ppNext = &gpChannelUsers->pNext;
        while (pLast->pNext)
        {
            pLast = *ppNext;
            ppNext = &pLast->pNext;
        }
        pLast->pNext = pUser;
    }
    else
    {
        gpChannelUsers = pUser;
    }

    COMCALLBACK_SetNamedValue(pUser->szName, pUser->szText);

    char szText[0x100];
    ++gnChannelUserCount;
    sprintf(szText, "%s (%d)", gszChannelName, gnChannelUserCount);

    Unicode wszText[0x240];
    Unicode::win2Unicode(wszText, szText, 0x240);
    CHATDLG_ShowChannelText(wszText);
    CHATDLG_UpdateScroll(0);
    COMCALLBACK_RefreshChannelList();
    return pUser;
}

int __cdecl sub_M133_Emit_00447390(const char* szNameA, const char* szNameB)
{
    return COMCALLBACK_CompareNames(szNameA, szNameB);
}

// 0x00449320
static inline void* COMCALLBACK_AddEntry(const char* szName, const unsigned char* pStat, unsigned int nFlags)
{
    return COMCALLBACK_AddChannelUser(szName, pStat, nFlags);
}

// 0x00449350
static void COMCALLBACK_ShowUserJoined(const char* szName, const unsigned char* pStat, unsigned int nFlags)
{
    D2MultiChannelUserStrc* pUser = COMCALLBACK_AddChannelUser(szName, pStat, nFlags);
    if (!gbShowJoinLeave)
    {
        return;
    }

    char szText[500];
    if (strlen(pUser->szText))
    {
        sprintf(szText, "%s has joined the channel.", pUser->szText);
    }
    else
    {
        sprintf(szText, "%s has joined the channel.", szName);
    }
    COMCALLBACK_AddChatLine(szText, 5);
}

// 0x004493C0
int __fastcall COMCALLBACK_OnUserJoin(unsigned int nFlags, int nUnused, const char* szName, const unsigned char* pStat)
{
    COMCALLBACK_ShowUserJoined(szName, pStat, nFlags);
    return 1;
}

// 0x004493E0
void __stdcall COMCALLBACK_RemoveChannelUser(const char* szName)
{
    D2MultiChannelUserStrc* pPrev = 0;
    D2MultiChannelUserStrc* pUser = gpChannelUsers;
    if (gpChannelUsers)
    {
    while (pUser)
    {
        const char* szA = strchr(pUser->szName, '*');
        if (!szA)
        {
            szA = pUser->szName;
        }
        else
        {
            szA += 1;
        }
        const char* szB = strchr(szName, '*');
        if (!szB)
        {
            szB = szName;
        }
        else
        {
            szB += 1;
        }
        if (!strcmp(szA, szB))
        {
            break;
        }
        pPrev = pUser;
        pUser = pUser->pNext;
    }

    if (pUser)
    {
        if (gbShowJoinLeave)
        {
            char szText[500];
            if (pUser->szText && strlen(pUser->szText))
            {
                sprintf(szText, "%s has left the channel.", pUser->szText);
            }
            else
            {
                sprintf(szText, "%s has left the channel.", pUser->szName);
            }
            COMCALLBACK_AddChatLine(szText, 5);
        }

        if (pPrev)
        {
            pPrev->pNext = pUser->pNext;
        }
        else
        {
            gpChannelUsers = pUser->pNext;
        }

        if (gpSelectedChannelUser == pUser)
        {
            COMCALLBACK_ClearSelectedUser();
        }

        sub_005041B0_Destroy(pUser->pComposite, 1);
        pUser->pComposite = 0;
        FOG_Free(pUser, ".\\Src\\ComCallback.cpp", 0x7FE, 0);
    }
    }

    gnChannelUserCount -= 1;
    char szCount[0x100];
    sprintf(szCount, "%s (%d)", gszChannelName, gnChannelUserCount);
    Unicode wszCount[0x240];
    sub_00526F20_ToUnicode(wszCount, szCount, 0x240);
    CHATDLG_ShowChannelText(wszCount);
    CHATDLG_UpdateScroll(0);
    COMCALLBACK_RefreshChannelList();
}


// 0x004495A0
void __cdecl COMCALLBACK_ClearChannel()
{
    char szText[0x100];
    COMCALLBACK_ClearSelectedUser();
    D2MultiChannelUserStrc* pUser = gpChannelUsers;
    while (pUser)
    {
        D2MultiChannelUserStrc* pNext = pUser->pNext;
        sub_005041B0_Destroy(pUser->pComposite, 1);
        pUser->pComposite = 0;
        FOG_Free(pUser, ".\\Src\\ComCallback.cpp", 0x822, 0);
        pUser = pNext;
    }
    gpChannelUsers = 0;
    D2ChannelEntryStrc* pEntry = gpChannelEntries;
    while (pEntry)
    {
        D2ChannelEntryStrc* pNext = pEntry->pNext;
        FOG_Free(pEntry, ".\\Src\\ComCallback.cpp", 0x82A, 0);
        pEntry = pNext;
    }
    gpChannelEntries = 0;
    gnChannelEntries_00798F3C = 0;
    gnChannelUserCount = 0;
    sprintf(szText, "%s (%d)", gszChannelName, 0);
    Unicode wszText[0x240];
    sub_00526F20_ToUnicode(wszText, szText, 0x240);
    CHATDLG_ShowChannelText(wszText);
    gnChannelScroll = 0;
    CHATDLG_UpdateScroll(0);
}

// 0x00449690
int __fastcall COMCALLBACK_OnUserLeave(int nA, int nB, const char* szText, int nLength)
{
    COMCALLBACK_RemoveChannelUser(szText);
    return 1;
}

// 0x004496B0
int __fastcall COMCALLBACK_OnJoinChannel(int nA, int nB, int nC, const char* szChannel)
{
    char szText[500];
    sprintf(szText, "You have joined channel: %s", szChannel);
    Unicode wszText[0x240];
    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x240);
    COMCALLBACK_RemoveTableString(wszText);
    CHATDLG_PrintText(wszText, 5);
    strcpy(gszChannelName, szChannel);
    strcpy(gpCharInfo->szRealm0x361, gszChannelName);
    if (!gpCharInfo->szRealm0x381[0])
    {
        strcpy(gpCharInfo->szRealm0x381, gszChannelName);
    }
    for (int i = 0; i < 11; i++)
    {
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gapChatButtons[i], 1);
    }
    sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
    COMCALLBACK_ClearChannel();
    return 1;
}

// 0x004497C0
int __fastcall COMCALLBACK_MapKeyChar(unsigned char cChar)
{
    return (char)gabCdKeyMap[cChar];
}

// 0x004497D0
int __fastcall COMCALLBACK_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// 0x00449840
unsigned int __fastcall COMCALLBACK_NibbleToHex(unsigned int nValue)
{
    unsigned int nResult = nValue & 0xF;
    if (nResult >= 10)
        nResult += 0x37;
    else
        nResult += 0x30;
    return nResult;
}

// 0x00449860
int __fastcall COMCALLBACK_IsValidKeyText(const char* szKey)
{
    while (*szKey)
    {
        if (gabCdKeyMap[(unsigned char)*szKey++] > 0x17)
        {
            return 0;
        }
    }
    return 1;
}

void* __fastcall sub_M109_Emit_00449320(const char* szName, const unsigned char* pStat)
{
    return COMCALLBACK_AddEntry(szName, pStat, 7);
}

#include "gen/data/Source/D2Multi/Src/ComCallback.inc"
