#include "D2Multi.h"

#include "D2LaunchRequest.h"

#include "D2MsgRecord.h"

#include "D2ClientTypes.h"

#include "D2FogTypes.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Drlg.h"

#include "D2LevelTxt.h"

#include "D2StormTypes.h"

#include "D2Unicode.h"

#include "D2MultiTypes.h"
#include "D2ChatControls.h"

#include "D2Win32Types.h"

#include "D2Win32System.h"
#include "D2Win32StartupInfo.h"
#include "D2MultiCharSave.h"
#include "FogApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi2.h"
#include "StormApi2.h"
#include "D2GfxApi.h"
#include "D2SoundApi.h"
#include "D2LangApi2.h"

static int CHATDLG_ReplyCommand(const char* szText, const char* szCommand); // 0x00442180

struct D2WinButtonStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CharSaveHeaderStrc;

struct D2CharSaveFileStrc;

struct D2ConfigStrc;

struct Unicode;

struct D2ChatMessageStrc;

struct D2LaunchFuncsStrc;

struct SMSGHANDLER_PARAMS;








D2CelFileStrc* __fastcall sub_004FA9B0_LoadCellFile(const char* szFile, int nType); // 0x004FA9B0

void __stdcall sub_00504D30(D2CelFileStrc* pCellFileA, D2CelFileStrc* pCellFileB); // 0x00504D30

int __stdcall sub_005041B0_Destroy(D2CelFileStrc* pCellFile, int nFlag); // 0x005041B0

int __stdcall CONTROL_SetFocusedEditBox(void* pEditBox); // 0x004F91C0

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00

void __cdecl CHATDLG_ResetChatControls(); // 0x0043E130


int __stdcall COMCALLBACK_ButtonCallback(D2ChatMessageStrc* pMsg); // 0x00448C70

extern "C" const char gszDataGlobal[]; // 0x006D4118

extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230


D2WinControlStrc* gapChatButtons[11]; // 0x0077AD78

D2ConfigStrc* gpCharInfo;                                                                  // 0x0077BBD8

int gbGemToggle; // 0x0077BBEC

D2CelFileStrc* gpChatCellFile; // 0x0077BBFC

D2WinControlStrc* gpChatControl_0077BC44; // 0x0077BC44

D2WinControlStrc* gpGemButton; // 0x0077BC48

D2WinControlStrc* gpChatEdit; // 0x0077BD94


extern D2CelFileStrc* gpWaitingRoomBkgdCelFile; // 0x0077BC08

extern D2CelFileStrc* gpPopUpLargest2CelFile; // 0x0077BC0C

extern D2CelFileStrc* gpMediumButtonBlank2CelFile; // 0x0077BC10

extern D2CelFileStrc* gpBnetCursorOHandCelFile; // 0x0077BC14

extern D2CelFileStrc* gpCursorLRotateCelFile; // 0x0077BC18

extern D2CelFileStrc* gpScrollBarCelFile; // 0x0077BC1C

extern D2CelFileStrc* gpBnetJoinGameScrollBarsCelFile; // 0x0077BC20

extern D2CelFileStrc* gpChatLeftButtonsCelFile; // 0x0077BC28

extern D2CelFileStrc* gpChatLeftButtons1CelFile; // 0x0077BC2C

extern D2CelFileStrc* gpChatLeftButtons2CelFile; // 0x0077BC30

extern D2CelFileStrc* gpChatRightButtonsCelFile; // 0x0077BC34

extern D2CelFileStrc* gpChatRightTopButtonsCelFile; // 0x0077BC38

extern D2CelFileStrc* gpChatArrowsCelFile; // 0x0077BC3C

extern D2CelFileStrc* gpJoinGameBckgCelFile; // 0x0077BC50

extern D2CelFileStrc* gpBlankBckg2CelFile; // 0x0077BC54

extern D2CelFileStrc* gpGemButtonCelFile; // 0x0077BC58

extern D2CelFileStrc* gpGameButtonBlankCelFile; // 0x0077BC5C

extern D2CelFileStrc* gpJoinGameClickBoxCelFile; // 0x0077BC60

extern D2CelFileStrc* gpGreyLevelBoxCelFile; // 0x0077BC64

extern D2CelFileStrc* gpRadioButtonCelFile; // 0x0077BC68

extern D2CelFileStrc* gpRadioButtonGreyCelFile; // 0x0077BC6C

extern D2CelFileStrc* gpBnetPopUpOkCelFile; // 0x0077BC70

extern D2CelFileStrc* gpBnetCancelButtonBlankCelFileA; // 0x0077BC74

extern D2CelFileStrc* gpOverallTabCelFile; // 0x0077BC78

extern D2CelFileStrc* gpAmazonTabCelFile; // 0x0077BC7C

extern D2CelFileStrc* gpSorceressTabCelFile; // 0x0077BC80

extern D2CelFileStrc* gpNecromancerTabCelFile; // 0x0077BC84

extern D2CelFileStrc* gpPaladinTabCelFile; // 0x0077BC88

extern D2CelFileStrc* gpBarbarianTabCelFile; // 0x0077BC8C

extern D2CelFileStrc* gpDruidTabCelFile; // 0x0077BC90

extern D2CelFileStrc* gpAssassinTabCelFile; // 0x0077BC94

extern D2CelFileStrc* gpSquelchAuraCelFile; // 0x0077BCB8

extern D2CelFileStrc* gpSelectAuraCelFile; // 0x0077BCBC

extern D2CelFileStrc* gpNumberArrowsCelFileA; // 0x0077BCC0

extern D2CelFileStrc* gpNumberArrowsCelFileB; // 0x0077BCC4

extern D2CelFileStrc* gpNumberArrowsCelFileC; // 0x0077BCC8

extern D2CelFileStrc* gpNumberArrowsCelFileD; // 0x0077BCCC

extern D2CelFileStrc* gpNumberGreyArrowsCelFile; // 0x0077BCD0

extern D2CelFileStrc* gpCreateJoinBckgCelFile; // 0x0077BCD4

extern D2CelFileStrc* gpOkayButtonCelFile; // 0x0077BCD8

extern D2CelFileStrc* gpCreateGameBckgCelFile; // 0x0077BD0C

extern D2CelFileStrc* gpCreateGameButtonCelFile; // 0x0077BD10

extern D2CelFileStrc* gpBnetWideButtonBlankCelFile; // 0x0077BD18

extern D2CelFileStrc* gpBnetCancelButtonBlankCelFileB; // 0x0077BD2C

extern D2CelFileStrc* gpYesNoButtonBlankCelFile; // 0x0077BD30

extern D2CelFileStrc* gpLadderChoiceExpCelFile; // 0x0077BD34

extern D2CelFileStrc* gpHardcoreLadderBckgCelFile; // 0x0077BD38

extern D2CelFileStrc* gpPlayerProfileBckgCelFileA; // 0x0077BD3C

extern D2CelFileStrc* gpPlayerProfileBckgCelFileB; // 0x0077BD40

extern D2CelFileStrc* gpHelpBckgCelFile; // 0x0077BD44

extern D2CelFileStrc* gpD2LogoBlackBnetCelFile; // 0x0077BD48

extern D2CelFileStrc* gpD2LogoBnetCelFile; // 0x0077BD4C


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2ChatMessageStrc
{
    char* szText;
    int nColor;
    int bClear;
    D2ChatMessageStrc* pNext;
};


extern "C" __declspec(dllimport) unsigned int __stdcall GetACP(); // 0x006CC32C

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, unsigned short* wszDest, int nDest); // 0x006CC29C

extern "C" __declspec(dllimport) int __stdcall GetDateFormatA(unsigned long nLocale, unsigned long dwFlags, const D2SystemTimeStrc* pDate, const char* szFormat, char* szDate, int nDate); // 0x006CC330

extern "C" __declspec(dllimport) int __stdcall FileTimeToSystemTime(const _FILETIME* pFileTime, D2SystemTimeStrc* pSystemTime); // 0x006CC334

extern "C" __declspec(dllimport) int __stdcall FileTimeToLocalFileTime(const _FILETIME* pFileTime, _FILETIME* pLocalFileTime); // 0x006CC338


class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int GetPersist();
    virtual void SetPersist(int bPersist);
};

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" size_t __cdecl strlen(const char* szString);


void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0


void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone); // 0x00440140


int __fastcall CHATDLG_PrintMessage(const Unicode* pText, int nColor); // 0x0043E5F0


Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

char gaszHistory[10][0x100]; // 0x0077B1D8

int gnHistoryCount; // 0x0077BD50

extern int gbShowJoinLeave; // 0x0077BD54

unsigned char gab_0077BD64[16]; // 0x0077BD64

unsigned char gab_0077BD74[16]; // 0x0077BD74

D2WinControlStrc* gpChatTextBox; // 0x0077BD8C

extern char gszLastWhisperer[]; // 0x0077B0D0

extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

extern unsigned char gnSelectModeA; // 0x0070CD62

int gnLadderPageSize;                                                                                      // 0x0077B0A0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" int __cdecl strcmp(const char*, const char*);

void __fastcall EDITBOX_SetText(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FF5A0

int __cdecl CHATDLG_ResetControls(); // 0x0043EBA0

void __cdecl CHATDLG_CreateControls(); // 0x0043EB30

void __fastcall BUTTON_SetIsPressed(D2WinControlStrc* pButton, int bIsPressed); // 0x005009A0

Unicode* __fastcall D2Win_10196(D2WinControlStrc* pTextBox, int nLineNum, int nColumnNum); // 0x004FBB90


void __fastcall VIEW_SendMcpLadderRequest(unsigned char nArg1, unsigned short nArg2); // 0x0044AA10

D2WinControlStrc* gbSelectActive; // 0x0077BD00

int gnColor; // 0x0077AD74

extern int gnSelectLine; // 0x0070CD68

extern int gnSelectLinePrev; // 0x0070CD64

int gnSelection;                                                                                   // 0x0077BBF4

D2CharSaveHeaderStrc gtCharSaveHeader; // 0x0077AC10

extern int gbChatSetup; // 0x0077BBF8

struct D2LaunchRecord3Strc;

struct D2LaunchThreadRecordStrc;

struct D2LaunchNameNodeStrc;

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800


int __fastcall D2Win_StopMessageLoop(); // 0x004F9190


int __fastcall WINMAIN_SendMcpCharRank(const char* szName, int nB, int nC); // 0x0044AAE0

int __fastcall WINMAIN_SendMcpCharCreate(int nA, int nB, int nC); // 0x0044A2E0

int __fastcall WINMAIN_SendMcpCharLogon(int nA); // 0x0044A380

int __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone); // 0x0043FB50

void* __stdcall COMCALLBACK_AddChannelUser(const char* szText, int nLength, int nA); // 0x00449050

extern char gKey_0070CD54; // 0x0070CD54

char gszSelectName[16];                                                                            // 0x0077B040

extern char gKey_0077B0A8; // 0x0077B0A8

unsigned short gwSavedRequestId;                                                                   // 0x0077BBDC

int gnChatLaunchMode;                                                                                  // 0x0077BBE4

extern int gbCheck; // 0x0077BD58

extern int gbSelectActive_0077BD00; // 0x0077BD00

static int gbDone;                                                                                 // 0x0077BDA0

extern int gbMcpPacket0FReceived; // 0x00798F5C

extern int gbMcpCreateQueued; // 0x00798F7C

extern int gbMcpServerAddressReceived; // 0x00798F84

extern int gbMcpPacket0BReceived; // 0x00799100

extern int gnMcpCreateQueuePosition; // 0x00799104

extern int gbMcpCharDeleteReceived; // 0x00799298

extern int gnConnectError; // 0x0079929C

extern int gbMcpPacket0CReceived; // 0x007992A0

extern int gbMcpPacket0DReceived; // 0x007992A8

extern int gbMcpCharLogonReceived; // 0x007992E0

extern int gbMcpCharCreateReceived; // 0x007992E8

extern int gbMcpCharUpgradeReceived; // 0x007992F0

D2WinControlStrc* gpControl_0077BD98; // 0x0077BD98

void __fastcall CHATDLG_RunCommand(char* szText); // 0x004423B0

void __fastcall COMCALLBACK_PrintOwnLine(const char* szText); // 0x004481F0

int __fastcall D2Win_10052_TEXTBOX_GetNumLines(D2WinControlStrc* pTextBox); // 0x004FB910

D2WinButtonStrc* gapClassButtons[8]; // 0x0077BC98

static int gbExpansionClasses; // 0x0070CD70

extern char gszChatBuffer[0x200]; // 0x0077AE40

int gnLadderMaxEntries;                                                                                      // 0x0077AD70


extern unsigned char gnSelectModeB; // 0x0070CD63

extern unsigned char gnSelectModeA; // 0x0070CD62

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall sub_004FCC40_AddLine(D2WinControlStrc* pControl, const Unicode* pText, int nColor, int nA, int nB); // 0x004FCC40

extern "C" const char gszDash[]; // 0x006CCA2C

struct D2LaunchNameNodeStrc
{
    char szName[0x200];
    int nId;
    D2LaunchNameNodeStrc* pNext;
};

D2LaunchNameNodeStrc* gpNameList; // 0x0077BDB4

void __cdecl CHATDLG_UpdateNameListText(); // 0x0043F730

D2WinControlStrc* gpControlMain; // 0x0077BC4C

int gpWaitText; // 0x0077BD9C

D2LaunchCallback gpfnLaunchCallback; // 0x0077BDA4

int gnResult; // 0x00798F58

char gszMcpText2[28]; // 0x00798F60

char gszMcpText1[4]; // 0x00799294


extern "C" int __cdecl isalnum(int c);                                                                      // 0x006870FB




void __fastcall CHATDLG_ShowMessage(const Unicode* pTitle, const Unicode* pText);                      // 0x0043EA70

int __stdcall MAINMENUS_FindCdKeyInText(const char* szText);                                             // 0x0043E900

int __cdecl CHATDLG_SendChatBuffer();                                                                  // 0x00442810

extern D2MultiChannelUserStrc* gpSelectedChannelUser;                                                   // 0x00798F48

struct D2WinTextBoxStrc;

struct UnicodeChar;

int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470

int __fastcall D2Win_10051(D2WinTextBoxStrc* ptTextData, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060


void __fastcall sub_004FC720(D2WinControlStrc* pList, int nValue); // 0x004FC720

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740

void __fastcall sub_004FBCD0(D2WinControlStrc* pList, int nColumn, int nValue); // 0x004FBCD0

void __cdecl CHATDLG_ClearLadderList(); // 0x0043F0E0

void __fastcall sub_004FD830(D2WinControlStrc* pControl); // 0x004FD830

void __fastcall sub_004FDA50(D2WinControlStrc* pControl); // 0x004FDA50

void __fastcall CHATDLG_FillLadderList(int nA, int nB); // 0x004403F0

void __cdecl CHATDLG_ClearLadderState(); // 0x0043ED50

int __stdcall sub_0043EB00_OnErrorDone(int nArg); // 0x0043EB00


unsigned long gdwConnectTime;                                                                      // 0x0077BBF0

struct UnicodeChar : Unicode
{
    UnicodeChar();
};

extern "C" void __fastcall BUTTON_SetBaseFrame(D2WinButtonStrc* pButton, int nValue); // 0x00500B20

extern "C" int __cdecl rand();

D2WinControlStrc* gapControls[32]; // 0x0077ADA8

int gnControlCount; // 0x0077BBE8

struct D2WinMsgStrc;

void __cdecl CHATDLG_ReleaseClassButtons();                                                            // 0x0043F060

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount);                  // 0x00687330


const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl);                             // 0x004FDD90

Unicode* __fastcall sub_00526F20(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

void __cdecl CHATDLG_CreateClassScreen();                                                              // 0x004406F0

void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone);              // 0x004401C0

static D2WinControlStrc* CHATDLG_CreateControl(int nIndex); // 0x0043E9D0

struct D2LadderEntryStrc
{
    int nA;
    int nB;
    int dwFlags;
    char szName[1];
};

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __fastcall CHATDLG_CopyName(char* szName);                                                   // 0x00443F50

void __fastcall sub_004FB870_InsertRow(D2WinControlStrc* pControl, int nRow);                                // 0x004FB870

int __fastcall D2Win_10188(D2WinControlStrc* pTextBox, int nLineNum, int nColor);                               // 0x004FBDE0

int __fastcall D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int nLineNum, int nColumn); // 0x004FCD90

const char* __stdcall D2Win_10161(int nA, int nB, int nC, int nD);                                         // 0x005068A0

void __stdcall STR_GroupUint64DigitsWithSuffix(Unicode* wszOut, int nA, int nB, int nMaxLength);                   // 0x005255C0

extern "C" const char* const gaszClassNames[];                                                     // 0x006D5524

static D2CriticalSectionStrc gtChatLock; // 0x0077AE28

static D2ChatMessageStrc* gpChatQueueHead; // 0x0077BDAC

static D2ChatMessageStrc* gpChatQueueTail; // 0x0077BDB0

void __cdecl CHATDLG_OpenStandardLadder(); // 0x004408B0

void __cdecl CHATDLG_OpenHardcoreLadder(); // 0x00440980

void __cdecl CHATDLG_OpenExpansionLadder(); // 0x00440A50

void __cdecl CHATDLG_OpenExpansionHardcoreLadder(); // 0x00440B30

unsigned long gdwSelectTime; // 0x0077BD5C


struct D2LaunchReplyStrc
{
    int nStatus;
    unsigned short wRequestId;
    char unk0x06[0x02];
    unsigned short wGameId;
    char unk0x0A[0x0A];
    unsigned short wValue;
    char unk0x16[0x06];
    char szName[0x10];
    char szDesc[0x20];
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect);                                                // 0x004F97B0

void __stdcall CHATDLG_EnableConnection(int bEnable);                                                            // 0x004413E0

void __cdecl CHATDLG_FlushChatMessages();                                                                   // 0x0043E3A0

void __fastcall CHATDLG_HandleGameListReply(D2LaunchReplyStrc* pReply);                                        // 0x00442B90

void __cdecl CHATDLG_SendPendingText();                                                                           // 0x00442E00

void __fastcall CHATDLG_ShowGameDetails(D2LaunchReplyStrc* pReply);                                        // 0x00442EB0

void __cdecl CHATDLG_DestroyJoinControls();                                                                          // 0x00443130

int __cdecl COMCALLBACK_PumpMessages();                                                                            // 0x00447A10

void* __cdecl GAME_GetMcpGameServerIP();                                                                               // 0x00449BC0

unsigned short __cdecl CHATDLG_GetRequestId();                                                         // 0x00449BD0

void* __cdecl GAME_GetMcpReply();                                                                               // 0x00449D50

void __cdecl CHATDLG_ClearReply();                                                                     // 0x00449D60

int __cdecl GAME_GetMcpGameHash();                                                                                 // 0x00449DE0

unsigned short gwOtherRequestId;                                                                   // 0x0077BBE0

static int gnLoopValueOut_0077BC14; // 0x0077BC14

extern int gnLoopValueIn_0077BC18;                                                                          // 0x0077BC18

extern int gfRealmConnectCancelled; // 0x0077BD60

struct D2StartupInfoAStrc;

struct D2ProcessInformationStrc;


extern "C" __declspec(dllimport) long __stdcall RegOpenKeyExA(void* hKey, const char* szSubKey, unsigned long ulOptions, unsigned long samDesired, void** phkResult); // 0x006CC010

extern "C" __declspec(dllimport) long __stdcall RegQueryValueExA(void* hKey, const char* szValueName, unsigned long* lpReserved, unsigned long* lpType, unsigned char* lpData, unsigned long* lpcbData); // 0x006CC00C

extern "C" __declspec(dllimport) long __stdcall RegCloseKey(void* hKey); // 0x006CC030

extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494

extern "C" __declspec(dllimport) int __stdcall SetForegroundWindow(void* hWnd); // 0x006CC490

extern "C" __declspec(dllimport) int __stdcall CreateProcessA(const char* szApplicationName, char* szCommandLine, void* pProcessAttributes, void* pThreadAttributes, int bInheritHandles, unsigned long dwCreationFlags, void* pEnvironment, const char* szCurrentDirectory, D2StartupInfoAStrc* pStartupInfo, D2ProcessInformationStrc* pProcessInformation); // 0x006CC33C


void* __stdcall sub_004FAC80(int nArg); // 0x004FAC80

int __fastcall STRTABLE_LoadStringTables(void* pArg, int nArg); // 0x005259C0

void __cdecl CHATDLG_LoadFrontEndCels(); // 0x0043CC30

void __cdecl CHATDLG_CreateCharControls(); // 0x0043DDD0

void __cdecl CHATDLG_ClearHistory(); // 0x0043F4D0

void __fastcall GAME_SetMcpChatCallback(void (__fastcall* pfnCallback)(void* pArg)); // 0x0044B220

void __cdecl VIEW_SendMcpMotdRequest(); // 0x0044AA50

int __cdecl CHATDLG_ConnectRealm(); // 0x00441A90

void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590

void __cdecl VIEW_SendMcpCancelGameCreate(); // 0x0044AA80

void __cdecl D2MCPClientCloseMCP(); // 0x00449AD0

void __cdecl COMCALLBACK_ClearChannel(); // 0x004495A0

void __stdcall D2Win_10146(); // 0x00505100

void __cdecl CHATDLG_FreeNameList(); // 0x0043F800

void __cdecl CHATDLG_FreeCellFiles(); // 0x0043D510

void* __stdcall sub_005066C0(int nA, int nMode, char* szA, char* szB); // 0x005066C0

void __stdcall sub_005052B0(void* pObject, int nValue); // 0x005052B0

void __fastcall CHATDLG_SetPlayerName(void* pArg); // 0x00440D10

void __fastcall CHATDLG_OnChatTime(void* pA, void* pB); // 0x0043E4C0

int __stdcall CHATDLG_OnTick(int nUnused); // 0x00441500


extern D2WinControlInitStrc gatChatControlInits[CHATINIT_COUNT]; // 0x0070CE50

D2WinControlStrc* gapChatDlgControls[CHATINIT_COUNT]; // 0x0077B058

extern D2WinControlInitStrc gtControlInit_0070D2A0; // 0x0070D2A0

extern D2WinControlInitStrc gtChatTextBoxInit; // 0x0070D240

extern D2WinControlInitStrc gtChatEditInit; // 0x0070D270

extern D2WinControlInitStrc gtControlInit_0070D210; // 0x0070D210

extern D2WinControlInitStrc gtGemButtonInit; // 0x0070D390

extern D2WinControlInitStrc gtControlInit_0070D2D0; // 0x0070D2D0

extern D2WinControlInitStrc gtBlankBckgImageInit; // 0x0070D300

extern D2WinControlInitStrc gtControlInit_0070D330; // 0x0070D330

extern D2WinControlInitStrc gtControlInit_0070D360; // 0x0070D360

void* gpLaunchContext; // 0x0077B0A4

struct _FILETIME;

void __stdcall sub_A09_Use(const char* szText);

int __cdecl CHATDLG_DestroyGameListControls(); // 0x00444E20

void __cdecl CHATDLG_CreateGatewayControls(); // 0x00440FC0

int __fastcall D2Win_10015(); // 0x004F8FE0

int __stdcall D2Win_10005(int nResolution); // 0x004F90A0

int __fastcall CHATDLG_RunChat(D2ConfigStrc* pInfo); // 0x00441B70

int __fastcall D2Win_10016(); // 0x004FA550

extern D2WinControlInitStrc gtWaitInit; // 0x0070D3C0

extern D2WinControlStrc* gpWaitText_0077BD9C; // 0x0077BD9C

static int gdwGlobal_0077BBF8; // 0x0077BBF8

D2WinControlStrc* gpNamesButton; // 0x0077BD08

char gszText_0077B1D0[8]; // 0x0077B1D0

char gszText_0077B0B4[28]; // 0x0077B0B4

D2WinControlStrc* gapControls_0077B050[2]; // 0x0077B050

D2WinControlStrc* gpControl_0077BC40; // 0x0077BC40

static D2ChatMessageStrc* CHATDLG_PopChatMessage();

static void CHATDLG_FreeChatMessage(D2ChatMessageStrc* pMessage);

static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand);

static void CHATDLG_PushHistory(const char* szText);

static void __stdcall CHATDLG_GetArgument(int nSize, const char* szText, char* szDest);

struct D2WinEditBoxStrc;

struct D2LaunchGameRecStrc;

struct D2GameDetailsStrc;

const Unicode* __fastcall sub_004FBB30_GetText(D2WinControlStrc* pControl); // 0x004FBB30



extern D2LaunchGameRecStrc gaNewGames[]; // 0x0077BDC8

extern D2WinControlStrc* gpJoinName; // 0x00798BD4

extern unsigned long gdwGameListLastClickTick; // 0x00798CEC

struct D2GameDetailsStrc
{
    char unk0x00[0x0C];
    unsigned int dwElapsed;
    unsigned char nLevel;
    unsigned char nLevelDiff;
    unsigned char nMaxPlayers;
    char unk0x13;
    int nPlayers;
    char unk0x18[0x14];
    char szDescription[0x20];
    unsigned short wClass[16];
    unsigned short wLevel[16];
    char szNames[16][16];
};

extern "C" const char gszEmptyString_006CC837[]; // 0x006CC837

D2WinControlStrc* gpGameInfoText; // 0x00798BC4

struct D2ModuleInterfaceStrc;

struct D2CelFileStrc;

extern D2ModuleInterfaceStrc gtInterface; // 0x0070CD14

void* __cdecl sub_0044DA90_GetTickCounter(); // 0x0044DA90

struct D2WinMsgStrc
{
    void* hWnd;
    unsigned int uMsg;
    unsigned int wParam;
    int lParam;
};

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

int __cdecl GAME_GetWaitHandle(); // 0x00449AC0

int __cdecl GAME_IsMcpCharLogonReceived(); // 0x00449C30

void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40

extern D2WinControlStrc* gpChannelListBox; // 0x0077BCFC

extern void* gpInstance; // 0x0077AD68

extern D2CelFileStrc* gpCellFile_0077BC24; // 0x0077BC24

int __stdcall CHATDLG_ClearSelection(int nArg1, int nArg2, int nArg3); // 0x0043DBA0

int __stdcall CHATDLG_OnWaitTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043DBC0

int __stdcall CHATDLG_OnReceiveTick(SMSGHANDLER_PARAMS* pMsg); // 0x0043DBF0

struct D2CompositeUnitStrc;

void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0

void __cdecl CHATDLG_FreeChatCellFile(); // 0x0043DCE0

struct Character;

struct Character { signed char value; };

enum { FIRST_PRINTABLE = 32, AFTER_PRINTABLE = 128 };

void __fastcall CHATDLG_SetFlagBits12(unsigned int* pFlags, int nValue); // 0x00442A70

int __fastcall CHATDLG_IsNightmareOpen(unsigned int nFlags); // 0x00442A80

int __fastcall CHATDLG_IsHellOpen(unsigned int nFlags); // 0x00442AB0


int __stdcall sub_004435D0_IsPrintableChar(void* unused1,void* unused2,const Character* text); // 0x004435D0

extern int gfCreateGameCancelled;                                                                                     // 0x00798CC4

extern D2WinControlStrc* gpNormalRadio;                                                                       // 0x00798C4C

extern D2WinControlStrc* gpNightmareRadio;                                                                       // 0x00798C50

extern D2WinControlStrc* gpHellRadio;                                                                       // 0x00798C54

extern int gnDiffSelect;                                                                                  // 0x00798CD0

extern char gszPendingEntryName[16];                                                                                  // 0x00798CD4

extern int gnPendingValueA;                                                                               // 0x00798CE4

extern int gnPendingValueB;                                                                               // 0x00798CE8

int __cdecl WINMAIN_PollMcpConnection();                                                               // 0x00449B70



void __fastcall CHATDLG_SelectEntry(const char* szName, int nValueA, int nValueB);                    // 0x0043EC60



int __stdcall sub_004438C0_OnCancel(int nArg); // 0x004438C0

int __stdcall CHATDLG_SelectNormal(int nArg); // 0x00443C20

int __stdcall CHATDLG_SelectNightmare(int nArg); // 0x00443C70

int __stdcall CHATDLG_SelectHell(int nArg); // 0x00443CC0

int __stdcall CHATDLG_OnRefresh(int nArg); // 0x00443F70

struct D2LaunchPayloadStrc
{
    unsigned int nSize;
    D2LaunchThreadRecordStrc tRecord;
};

struct D2LaunchLoginStrc
{
    char szText0x00[0x10];
    char szText0x10[0x10];
    char szText0x20[0x20];
    int nValue0x40;
    char nValue0x44;
    char nValue0x45;
    char nValue0x46;
};

#pragma pack(push, 1)

struct D2LaunchReplyEntryStrc
{
    char szName[0x10];
    char szDesc[0x20];
    unsigned short wValue;
    unsigned short wGameId;
    char unk0x34[0x02];
    int nValue;
    char unk0x3A[0x01];
};

#pragma pack(pop)

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize);                                // 0x006829C0

int __stdcall CHATDLG_OnRealmConnectCancel(int nArg);                                                                       // 0x0043D9A0

int __stdcall sub_0043DBC0(int nArg);                                                                       // 0x0043DBC0

int __stdcall sub_0043DBF0(int nArg);                                                                       // 0x0043DBF0


int __stdcall CHATDLG_RequestCharLogon(const char* szName);                                                    // 0x00449E10

void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord);                                 // 0x0044A130

int __fastcall WINMAIN_SendMcpCreateGame(D2LaunchLoginStrc* pLogin, unsigned short wRequestId);                // 0x0044A400

int __fastcall WINMAIN_SendMcpGameInfoRequest(char* szText, unsigned short wRequestId);                              // 0x0044A610

extern "C" const char gszPassword[];                                                               // 0x006D423C

extern int gnRequestId_0070CD60;                                                                            // 0x0070CD60

extern int gnPendingId;                                                                            // 0x0070EBD8

extern D2WinControlInitStrc gtControlInit_0070E860;                                                         // 0x0070E860

extern D2WinControlInitStrc gtControlInit_0070E890;                                                         // 0x0070E890

extern D2WinControlInitStrc gtControlInit_0070E8C0;                                                         // 0x0070E8C0

extern D2WinControlInitStrc gtControlInit_0070E8F0;                                                         // 0x0070E8F0

extern D2WinControlInitStrc gtControlInit_0070E9B0;                                                         // 0x0070E9B0

extern D2LaunchReplyEntryStrc gatReplyEntries[];                                                    // 0x0077BDC9

char gszPendingText[264];                                                                          // 0x00798AB8


D2WinControlStrc* gpJoinGameBckgImage;                                                                       // 0x00798BC8

D2WinControlStrc* gpControl_00798BD0;                                                                       // 0x00798BD0

extern D2WinControlStrc* gpJoinName;                                                                // 0x00798BD4

extern D2WinControlStrc* gpJoinPassword;                                                                // 0x00798BD8

extern D2WinControlStrc* gpJoinGameTitle;                                                                // 0x00798BDC

extern D2WinControlStrc* gpJoinNameLabel;                                                                // 0x00798BE0

extern D2WinControlStrc* gpJoinPasswordLabel;                                                                // 0x00798BE4

extern D2WinControlStrc* gpControl_00798BE8;                                                                // 0x00798BE8

extern D2WinControlStrc* gpPanelBackground;                                                                // 0x00798BEC

extern D2WinControlStrc* gpCreatePasswordLabel;                                                                // 0x00798BF8

extern D2WinControlStrc* gpCreateDescLabel;                                                                // 0x00798BFC

extern D2WinControlStrc* gpMaxPlayersLabel;                                                                // 0x00798C00

extern D2WinControlStrc* gpLevelDiffLabel;                                                                // 0x00798C04

extern D2WinControlStrc* gpControl_00798C08;                                                                // 0x00798C08

extern D2WinControlStrc* gpMaxPlayersBoxImage;                                                                // 0x00798C0C

extern D2WinControlStrc* gpControl_00798C10;                                                                // 0x00798C10

extern D2WinControlStrc* gpMaxPlayersUpButton;                                                                // 0x00798C14

extern D2WinControlStrc* gpMaxPlayersDownButton;                                                                // 0x00798C18

D2WinControlStrc* gpLevelDiffUpButton;                                                                       // 0x00798C1C

D2WinControlStrc* gpLevelDiffDownButton;                                                                       // 0x00798C20

extern D2WinControlStrc* gpLevelDiffGreyArrows;                                                                // 0x00798C24

extern D2WinControlStrc* gpCreateName;                                                                // 0x00798C2C

extern D2WinControlStrc* gpCreatePassword;                                                                // 0x00798C30

extern D2WinControlStrc* gpCreateDesc;                                                                // 0x00798C34


extern D2WinControlStrc* gpLevelDiffEdit;                                                                // 0x00798C3C

extern D2WinControlStrc* gpLevelDiffCheck;                                                                 // 0x00798C40

extern D2WinControlStrc* gpLevelDiffBoxImage;                                                                // 0x00798C44

extern D2WinControlStrc* gpNormalLabel;                                                                // 0x00798C58

extern D2WinControlStrc* gpNightmareLabel;                                                                // 0x00798C5C

extern D2WinControlStrc* gpHellLabel;                                                                // 0x00798C60

D2WinControlStrc* gpProfileViewBckg;                                                                       // 0x00798C64

D2WinControlStrc* gpControl_00798C68;                                                                       // 0x00798C68

D2WinControlStrc* gpControl_00798C6C;                                                                       // 0x00798C6C

D2WinControlStrc* gpControl_00798C70;                                                                       // 0x00798C70

extern D2WinControlStrc* gpControl_00798C74;                                                                // 0x00798C74

D2WinControlStrc* gpProfileEditBckg;                                                                       // 0x00798C78

D2WinControlStrc* gpControl_00798C7C;                                                                       // 0x00798C7C

extern D2WinControlStrc* gpSubmitEditA;                                                            // 0x00798C80

extern D2WinControlStrc* gpSubmitEditB;                                                            // 0x00798C84

extern D2WinControlStrc* gpSubmitEditC;                                                            // 0x00798C88

D2WinControlStrc* gpRefreshButton;                                                                       // 0x00798C8C

D2WinControlStrc* gpControl_00798C90;                                                                       // 0x00798C90

D2WinControlStrc* gpControl_00798C94;                                                                       // 0x00798C94

D2WinControlStrc* gpControl_00798C98;                                                                       // 0x00798C98

D2WinControlStrc* gpControl_00798C9C;                                                                       // 0x00798C9C

extern D2WinControlStrc* gpSubmitButton;                                                                // 0x00798CA0

extern D2WinControlStrc* gpSelectButton;                                                                // 0x00798CA4

D2WinControlStrc* gpControl_00798CA8;                                                                       // 0x00798CA8

int gnSubmitMode;                                                                                  // 0x00798CAC

extern D2WinControlStrc* gpControl_00798CB0;                                                                // 0x00798CB0

extern D2WinControlStrc* gpControl_00798CB4;                                                                // 0x00798CB4

extern D2WinControlStrc* gpControl_00798CB8;                                                                // 0x00798CB8

extern D2WinControlStrc* gpHelpBckgImage;                                                                // 0x00798CBC

extern int gfGameListControlsCreated;                                                                                // 0x00798CC0

extern int gnChannelUserCount;                                                                         // 0x00798F40

int gnChannelScroll;                                                                               // 0x00798F44

extern unsigned short gwMcpReplyRequestId;                                                                 // 0x00798F80

extern void* gpMcpConnection;                                                                         // 0x00798FB4

extern char gabMcpReply[];                                                                               // 0x00799108

extern void* ghConnectEvent;                                                                       // 0x007992EC

static __forceinline int CONSOLE_FindSecondTokenInline(const char* szText, char* szCopy, const char** ppArg)
{
    strcpy(szCopy, szText);
    char szDelim[2] = " ";
    char* pToken = strtok(szCopy, szDelim);
    int nCount = 0;
    while (pToken)
    {
        if (++nCount == 2)
        {
            *ppArg = szText + (pToken - szCopy);
            return 1;
        }
        pToken = strtok(0, szDelim);
    }
    return 0;
}

// build: symbol ?FOG_CloseFile@* 0x004069A0

// 0x0043CBF0
void __cdecl sub_0043CBF0_Nop()
{
}

// 0x0043CC00
const char* __fastcall CHATDLG_StrChr(const char* szString, char nChar, int bReverse)
{
    if (bReverse)
        return SStrChrR(szString, nChar);
    return SStrChr(szString, nChar);
}

// 0x0043CC20
int __fastcall CHATDLG_TestBit2(int nValue)
{
    return nValue & 4;
}

// 0x0043CC30
void __cdecl CHATDLG_LoadFrontEndCels()
{
    char szPath[0x104];

    sprintf(szPath, "%s\\UI\\FrontEnd\\PopUpLargest2", gszDataGlobal);
    gpPopUpLargest2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FrontEnd\\MediumButtonBlank2", gszDataGlobal);
    gpMediumButtonBlank2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\bnet", gszDataGlobal);
    gpChatBackground = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\waitingroombkgd", gszDataGlobal);
    gpWaitingRoomBkgdCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\ohand", gszDataGlobal);
    gpBnetCursorOHandCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\CURSOR\\lrotate", gszDataGlobal);
    gpCursorLRotateCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\scrollbar", gszDataGlobal);
    gpScrollBarCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", gszDataGlobal);
    gpBnetJoinGameScrollBarsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons", gszDataGlobal);
    gpChatLeftButtonsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons1", gszDataGlobal);
    gpChatLeftButtons1CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatleftbuttons2", gszDataGlobal);
    gpChatLeftButtons2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrightbuttons", gszDataGlobal);
    gpChatRightButtonsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatrighttopbuttons", gszDataGlobal);
    gpChatRightTopButtonsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\chatarrows", gszDataGlobal);
    gpChatArrowsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingamebckg", gszDataGlobal);
    gpJoinGameBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GameButtonBlank", gszDataGlobal);
    gpGameButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\joingameclickbox", gszDataGlobal);
    gpJoinGameClickBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileA = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileB = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileC = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numberarrows", gszDataGlobal);
    gpNumberArrowsCelFileD = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\numbergreyarrows", gszDataGlobal);
    gpNumberGreyArrowsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\GreyLevelBox", gszDataGlobal);
    gpGreyLevelBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\createjoinbckg", gszDataGlobal);
    gpCreateJoinBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\okaybutton", gszDataGlobal);
    gpOkayButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebckg", gszDataGlobal);
    gpCreateGameBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\creategamebutton", gszDataGlobal);
    gpCreateGameButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\widebuttonblank", gszDataGlobal);
    gpBnetWideButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\CancelButtonBlank", gszDataGlobal);
    gpBnetCancelButtonBlankCelFileB = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\yesnobuttonblank", gszDataGlobal);
    gpYesNoButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBlackBnet", gszDataGlobal);
    gpD2LogoBlackBnetCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\D2logoBnet", gszDataGlobal);
    gpD2LogoBnetCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\blankbckg2", gszDataGlobal);
    gpBlankBckg2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\gembutton", gszDataGlobal);
    gpGemButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\LadderChoiceEXP", gszDataGlobal);
    gpLadderChoiceExpCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HardcoreLadderBckg", gszDataGlobal);
    gpHardcoreLadderBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", gszDataGlobal);
    gpPlayerProfileBckgCelFileB = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\PlayerProfileBckg", gszDataGlobal);
    gpPlayerProfileBckgCelFileA = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\HelpBckg", gszDataGlobal);
    gpHelpBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobutton", gszDataGlobal);
    gpRadioButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\BIGMENU\\radiobuttonGrey", gszDataGlobal);
    gpRadioButtonGreyCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\PopUpOK", gszDataGlobal);
    gpBnetPopUpOkCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\CancelButtonBlank", gszDataGlobal);
    gpBnetCancelButtonBlankCelFileA = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\overalltab", gszDataGlobal);
    gpOverallTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\amazontab", gszDataGlobal);
    gpAmazonTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\sorceresstab", gszDataGlobal);
    gpSorceressTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\necromancertab", gszDataGlobal);
    gpNecromancerTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\paladintab", gszDataGlobal);
    gpPaladinTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\barbariantab", gszDataGlobal);
    gpBarbarianTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\druidtab", gszDataGlobal);
    gpDruidTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\BIGMENU\\assassintab", gszDataGlobal);
    gpAssassinTabCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SquelchAura", gszDataGlobal);
    gpSquelchAuraCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UncompOverlays\\SelectAura", gszDataGlobal);
    gpSelectAuraCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sub_00504D30(gpSquelchAuraCelFile, gpSelectAuraCelFile);
}

D2CelFileStrc* gpChatBackground; // 0x0077BC04

D2CelFileStrc* gpWaitingRoomBkgdCelFile; // 0x0077BC08

D2CelFileStrc* gpPopUpLargest2CelFile; // 0x0077BC0C

D2CelFileStrc* gpMediumButtonBlank2CelFile; // 0x0077BC10

extern D2CelFileStrc* gpBnetCursorOHandCelFile; // 0x0077BC14

D2CelFileStrc* gpCursorLRotateCelFile; // 0x0077BC18

D2CelFileStrc* gpScrollBarCelFile; // 0x0077BC1C

D2CelFileStrc* gpBnetJoinGameScrollBarsCelFile; // 0x0077BC20

D2CelFileStrc* gpCellFile_0077BC24; // 0x0077BC24

D2CelFileStrc* gpChatLeftButtonsCelFile; // 0x0077BC28

D2CelFileStrc* gpChatLeftButtons1CelFile; // 0x0077BC2C

D2CelFileStrc* gpChatLeftButtons2CelFile; // 0x0077BC30

D2CelFileStrc* gpChatRightButtonsCelFile; // 0x0077BC34

D2CelFileStrc* gpChatRightTopButtonsCelFile; // 0x0077BC38

D2CelFileStrc* gpChatArrowsCelFile; // 0x0077BC3C

D2CelFileStrc* gpJoinGameBckgCelFile; // 0x0077BC50

D2CelFileStrc* gpBlankBckg2CelFile; // 0x0077BC54

D2CelFileStrc* gpGemButtonCelFile; // 0x0077BC58

D2CelFileStrc* gpGameButtonBlankCelFile; // 0x0077BC5C

D2CelFileStrc* gpJoinGameClickBoxCelFile; // 0x0077BC60

D2CelFileStrc* gpGreyLevelBoxCelFile; // 0x0077BC64

D2CelFileStrc* gpRadioButtonCelFile; // 0x0077BC68

D2CelFileStrc* gpRadioButtonGreyCelFile; // 0x0077BC6C

D2CelFileStrc* gpBnetPopUpOkCelFile; // 0x0077BC70

D2CelFileStrc* gpBnetCancelButtonBlankCelFileA; // 0x0077BC74

D2CelFileStrc* gpOverallTabCelFile; // 0x0077BC78

D2CelFileStrc* gpAmazonTabCelFile; // 0x0077BC7C

D2CelFileStrc* gpSorceressTabCelFile; // 0x0077BC80

D2CelFileStrc* gpNecromancerTabCelFile; // 0x0077BC84

D2CelFileStrc* gpPaladinTabCelFile; // 0x0077BC88

D2CelFileStrc* gpBarbarianTabCelFile; // 0x0077BC8C

D2CelFileStrc* gpDruidTabCelFile; // 0x0077BC90

D2CelFileStrc* gpAssassinTabCelFile; // 0x0077BC94

D2CelFileStrc* gpSquelchAuraCelFile; // 0x0077BCB8

D2CelFileStrc* gpSelectAuraCelFile; // 0x0077BCBC

D2CelFileStrc* gpNumberArrowsCelFileA; // 0x0077BCC0

D2CelFileStrc* gpNumberArrowsCelFileB; // 0x0077BCC4

D2CelFileStrc* gpNumberArrowsCelFileC; // 0x0077BCC8

D2CelFileStrc* gpNumberArrowsCelFileD; // 0x0077BCCC

D2CelFileStrc* gpNumberGreyArrowsCelFile; // 0x0077BCD0

D2CelFileStrc* gpCreateJoinBckgCelFile; // 0x0077BCD4

D2CelFileStrc* gpOkayButtonCelFile; // 0x0077BCD8

D2CelFileStrc* gpCreateGameBckgCelFile; // 0x0077BD0C

D2CelFileStrc* gpCreateGameButtonCelFile; // 0x0077BD10

D2CelFileStrc* gpBnetWideButtonBlankCelFile; // 0x0077BD18

D2CelFileStrc* gpBnetCancelButtonBlankCelFileB; // 0x0077BD2C

D2CelFileStrc* gpYesNoButtonBlankCelFile; // 0x0077BD30

D2CelFileStrc* gpLadderChoiceExpCelFile; // 0x0077BD34

D2CelFileStrc* gpHardcoreLadderBckgCelFile; // 0x0077BD38

D2CelFileStrc* gpPlayerProfileBckgCelFileA; // 0x0077BD3C

D2CelFileStrc* gpPlayerProfileBckgCelFileB; // 0x0077BD40

D2CelFileStrc* gpHelpBckgCelFile; // 0x0077BD44

D2CelFileStrc* gpD2LogoBlackBnetCelFile; // 0x0077BD48

D2CelFileStrc* gpD2LogoBnetCelFile; // 0x0077BD4C

int gfRealmConnectCancelled; // 0x0077BD60

// 0x0043D510
void __cdecl CHATDLG_FreeCellFiles()
{
    if (gpPopUpLargest2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPopUpLargest2CelFile);
        gpPopUpLargest2CelFile = 0;
    }

    if (gpMediumButtonBlank2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpMediumButtonBlank2CelFile);
        gpMediumButtonBlank2CelFile = 0;
    }

    if (gpChatBackground)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatBackground);
        gpChatBackground = 0;
    }

    if (gpWaitingRoomBkgdCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpWaitingRoomBkgdCelFile);
        gpWaitingRoomBkgdCelFile = 0;
    }

    if (gpBnetCursorOHandCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetCursorOHandCelFile);
        gpBnetCursorOHandCelFile = 0;
    }

    if (gpCursorLRotateCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCursorLRotateCelFile);
        gpCursorLRotateCelFile = 0;
    }

    if (gpScrollBarCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpScrollBarCelFile);
        gpScrollBarCelFile = 0;
    }

    if (gpBnetJoinGameScrollBarsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetJoinGameScrollBarsCelFile);
        gpBnetJoinGameScrollBarsCelFile = 0;
    }

    if (gpChatLeftButtonsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatLeftButtonsCelFile);
        gpChatLeftButtonsCelFile = 0;
    }

    if (gpChatLeftButtons1CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatLeftButtons1CelFile);
        gpChatLeftButtons1CelFile = 0;
    }

    if (gpChatLeftButtons2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatLeftButtons2CelFile);
        gpChatLeftButtons2CelFile = 0;
    }

    if (gpChatRightButtonsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatRightButtonsCelFile);
        gpChatRightButtonsCelFile = 0;
    }

    if (gpChatRightTopButtonsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatRightTopButtonsCelFile);
        gpChatRightTopButtonsCelFile = 0;
    }

    if (gpChatArrowsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpChatArrowsCelFile);
        gpChatArrowsCelFile = 0;
    }

    if (gpJoinGameBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpJoinGameBckgCelFile);
        gpJoinGameBckgCelFile = 0;
    }

    if (gpGameButtonBlankCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpGameButtonBlankCelFile);
        gpGameButtonBlankCelFile = 0;
    }

    if (gpJoinGameClickBoxCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpJoinGameClickBoxCelFile);
        gpJoinGameClickBoxCelFile = 0;
    }

    if (gpNumberArrowsCelFileA)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileA);
        gpNumberArrowsCelFileA = 0;
    }

    if (gpNumberArrowsCelFileB)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileB);
        gpNumberArrowsCelFileB = 0;
    }

    if (gpNumberArrowsCelFileC)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileC);
        gpNumberArrowsCelFileC = 0;
    }

    if (gpNumberArrowsCelFileD)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberArrowsCelFileD);
        gpNumberArrowsCelFileD = 0;
    }

    if (gpNumberGreyArrowsCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNumberGreyArrowsCelFile);
        gpNumberGreyArrowsCelFile = 0;
    }

    if (gpGreyLevelBoxCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpGreyLevelBoxCelFile);
        gpGreyLevelBoxCelFile = 0;
    }

    if (gpCreateJoinBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCreateJoinBckgCelFile);
        gpCreateJoinBckgCelFile = 0;
    }

    if (gpOkayButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpOkayButtonCelFile);
        gpOkayButtonCelFile = 0;
    }

    if (gpCreateGameBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCreateGameBckgCelFile);
        gpCreateGameBckgCelFile = 0;
    }

    if (gpCreateGameButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCreateGameButtonCelFile);
        gpCreateGameButtonCelFile = 0;
    }

    if (gpCellFile_0077BC24)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpCellFile_0077BC24);
        gpCellFile_0077BC24 = 0;
    }

    if (gpBnetWideButtonBlankCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetWideButtonBlankCelFile);
        gpBnetWideButtonBlankCelFile = 0;
    }

    if (gpBnetCancelButtonBlankCelFileB)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetCancelButtonBlankCelFileB);
        gpBnetCancelButtonBlankCelFileB = 0;
    }

    if (gpYesNoButtonBlankCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpYesNoButtonBlankCelFile);
        gpYesNoButtonBlankCelFile = 0;
    }

    if (gpD2LogoBlackBnetCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpD2LogoBlackBnetCelFile);
        gpD2LogoBlackBnetCelFile = 0;
    }

    if (gpD2LogoBnetCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpD2LogoBnetCelFile);
        gpD2LogoBnetCelFile = 0;
    }

    if (gpBlankBckg2CelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBlankBckg2CelFile);
        gpBlankBckg2CelFile = 0;
    }

    if (gpGemButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpGemButtonCelFile);
        gpGemButtonCelFile = 0;
    }

    if (gpLadderChoiceExpCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpLadderChoiceExpCelFile);
        gpLadderChoiceExpCelFile = 0;
    }

    if (gpHardcoreLadderBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpHardcoreLadderBckgCelFile);
        gpHardcoreLadderBckgCelFile = 0;
    }

    if (gpPlayerProfileBckgCelFileA)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPlayerProfileBckgCelFileA);
        gpPlayerProfileBckgCelFileA = 0;
    }

    if (gpHelpBckgCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpHelpBckgCelFile);
        gpHelpBckgCelFile = 0;
    }

    if (gpPlayerProfileBckgCelFileB)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPlayerProfileBckgCelFileB);
        gpPlayerProfileBckgCelFileB = 0;
    }

    if (gpRadioButtonCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpRadioButtonCelFile);
        gpRadioButtonCelFile = 0;
    }

    if (gpRadioButtonGreyCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpRadioButtonGreyCelFile);
        gpRadioButtonCelFile = 0;
    }

    if (gpBnetPopUpOkCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetPopUpOkCelFile);
        gpBnetPopUpOkCelFile = 0;
    }

    if (gpBnetCancelButtonBlankCelFileA)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBnetCancelButtonBlankCelFileA);
        gpBnetCancelButtonBlankCelFileA = 0;
    }

    if (gpOverallTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpOverallTabCelFile);
        gpOverallTabCelFile = 0;
    }

    if (gpAmazonTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpAmazonTabCelFile);
        gpAmazonTabCelFile = 0;
    }

    if (gpSorceressTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpSorceressTabCelFile);
        gpSorceressTabCelFile = 0;
    }

    if (gpNecromancerTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpNecromancerTabCelFile);
        gpNecromancerTabCelFile = 0;
    }

    if (gpPaladinTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpPaladinTabCelFile);
        gpPaladinTabCelFile = 0;
    }

    if (gpBarbarianTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpBarbarianTabCelFile);
        gpBarbarianTabCelFile = 0;
    }

    if (gpDruidTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpDruidTabCelFile);
        gpDruidTabCelFile = 0;
    }

    if (gpAssassinTabCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpAssassinTabCelFile);
        gpAssassinTabCelFile = 0;
    }

    if (gpSquelchAuraCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpSquelchAuraCelFile);
        gpSquelchAuraCelFile = 0;
    }

    if (gpSelectAuraCelFile)
    {
        ARCHIVE_FreeCellFile((D2CelFileStrc*)gpSelectAuraCelFile);
        gpSelectAuraCelFile = 0;
    }
}

// 0x0043D990
void __cdecl CHATDLG_ActivateChatEdit()
{
// build: symbol ?gpChatEdit@* 0x0077BD94
    if (gpChatEdit)
        CONTROL_SetFocusedEditBox(gpChatEdit);
}

// 0x0043D9A0
int __stdcall CHATDLG_OnRealmConnectCancel(SMSGHANDLER_PARAMS* pMsg)
{
    gfRealmConnectCancelled = 1;
    return 1;
}

// 0x0043D9B0
int __stdcall CHATDLG_NextRequestCallback(int nArg)
{
// build: symbol ?gwRequestId@* 0x0070CD60
    while (++gwRequestId == 0)
    {
    }
    gpfnLaunchCallback(nArg);
    return 1;
}

// 0x0043D9E0
int __stdcall CHATDLG_ScrollPageUp(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(-10);
    return 1;
}

// 0x0043DA00
int __stdcall CHATDLG_OnScrollPageDown(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(10);
    return 1;
}

// 0x0043DA20
int __stdcall CHATDLG_OnScrollUp(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(-1);
    return 1;
}

// 0x0043DA30
int __stdcall CHATDLG_OnScrollDown(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_UpdateScroll(1);
    return 1;
}

// 0x0043DA50
static int __stdcall CHATDLG_ReadRegValueHKLM(const char* szSubKey, const char* szValueName, unsigned char* pData, unsigned long nSize, unsigned long* pcbData)
{
    void* hKey;
    unsigned long dwType;
    *pcbData = 0;
    if (RegOpenKeyExA((void*)0x80000002, szSubKey, 0, 0x20019, &hKey))
    {
        return 0;
    }
    *pcbData = nSize;
    if (RegQueryValueExA(hKey, szValueName, 0, &dwType, pData, pcbData))
    {
        RegCloseKey(hKey);
        return 0;
    }
    return RegCloseKey(hKey) == 0;
}

// Kept noinline: COMCALLBACK_BuildCreateGamePanel (0x4453B0) calls this out of line in the image; without it the compiler inlines it there.
// 0x0043DAD0
__declspec(noinline) int __fastcall CHATDLG_SetMainControlState(int bSet)
{
    sub_004F9740_SetControlState(gpControlMain, bSet);
    return 1;
}

// 0x0043DAF0
int __stdcall sub_0043DAF0_OnConnect(int nArg)
{
    sub_004F9740_SetControlState(gpControlMain, 1);
    return 1;
}

extern D2WinControlStrc* gpCreateJoinBckgImage; // 0x0077BCDC

extern D2WinControlStrc* gpChannelScreenTitle; // 0x0077BCE0

extern D2WinControlStrc* gpControl_0077BCE4; // 0x0077BCE4

extern D2WinControlStrc* gpControl_0077BCE8; // 0x0077BCE8

extern D2WinControlStrc* gpChannelOkButton; // 0x0077BCEC

extern D2WinControlStrc* gpControl_0077BCF0; // 0x0077BCF0

// 0x0043DB20
void __cdecl CHATDLG_DestroyDialogControls()
{
    sub_004F95C0_ControlDestroy(&gpCreateJoinBckgImage);
    sub_004F95C0_ControlDestroy(&gpChannelScreenTitle);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCE4);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCE8);
    sub_004F95C0_ControlDestroy(&gpChannelOkButton);
    sub_004F95C0_ControlDestroy(&gpControl_0077BCF0);
    sub_004F95C0_ControlDestroy(&gpChannelNameEdit);
    sub_004F95C0_ControlDestroy(&gpChannelListBox);
    sub_004FA450_SetActive(gapChatDlgControls[CHATINIT_QUITBUTTON]);
    if (gpChatEdit)
        CONTROL_SetFocusedEditBox(gpChatEdit);
}

// 0x0043DB90
int __stdcall CHATDLG_OnChatEditEnter(int nArg)
{
    COMCALLBACK_RefreshChatButtons();
    return 1;
}

// 0x0043DBA0
int __stdcall CHATDLG_ClearSelection(int nArg1, int nArg2, int nArg3)
{
    sub_004FB9D0_Select(gpChannelListBox, -1);
    return 1;
}

// 0x0043DBC0
int __stdcall CHATDLG_OnWaitTick(SMSGHANDLER_PARAMS* pMsg)
{
    if (!WaitForSingleObject((void*)GAME_GetWaitHandle(), 0) || gfRealmConnectCancelled)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x0043DBF0
int __stdcall CHATDLG_OnReceiveTick(SMSGHANDLER_PARAMS* pMsg)
{
    sub_00449B70_Receive();
// build: symbol ?MCPCONNECT_QueryAddress@* 0x00449B30
    if (GAME_IsMcpCharLogonReceived() || !MCPCONNECT_QueryAddress() || gfRealmConnectCancelled)
    {
        CHATDLG_SetCharLogonReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// Kept noinline: CHATDLG_CreateJoinScreen (0x445DF0) calls this out of line in the image; without it the compiler inlines it there.
// 0x0043DC30
__declspec(noinline) int __cdecl CHATDLG_GetConnectStatus()
{
// build: symbol ?gpCharInfo@* 0x0077BBD8
    if (gpCharInfo->nByte22D && !MCPCONNECT_QueryAddress())
        return -1;
    return 0;
}

static void __cdecl CHATDLG_CreateChatCellFile(D2ConfigStrc* pInfo); // 0x0043DC50

#define CREATE_CELL_FILE CHATDLG_CreateChatCellFile

static int __stdcall CHATDLG_FindHashedWord(char* szText, unsigned int nHash, int nLength); // 0x0043E860

// 0x0043DC50
static void __cdecl CHATDLG_CreateChatCellFile(D2ConfigStrc* pInfo)
{
    int nMode = 5;
    const unsigned short wFlags = pInfo->wFlags3CB;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if ((wFlags & 4) && !(wFlags & 8) && (FOG_IsExpansion() || pInfo->nClass < 5))
        nMode = 1;
    gpChatCellFile = (D2CelFileStrc*)sub_005066C0(pInfo->nClass, nMode, pInfo->szText0x3A1, (char*)pInfo->nComponentColors);
    if (gpChatCellFile)
    {
        sub_005052B0(gpChatCellFile, 0x42);
        sub_005052F0(gpChatCellFile, 0x23B);
        sub_005051A0(gpChatCellFile, 0);
        sub_00505260(gpChatCellFile, 0);
    }
}

// 0x0043DCE0
void __cdecl CHATDLG_FreeChatCellFile()
{
    if (gpChatCellFile)
        D2Win_10142_CompUnitDestroy((D2CompositeUnitStrc*)gpChatCellFile, 1);
    gpChatCellFile = 0;
}

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0










extern D2WinControlInitStrc gatControlInits[2];                                                    // 0x0070D180

extern D2WinControlInitStrc gtControlInit_0070D1E0;                                                         // 0x0070D1E0

extern "C" const char gszLevelFormat[];                                                            // 0x006D4E24

static void __cdecl CHATDLG_GetClassName(int nClass, Unicode* pDest); // 0x0043DD00

#define GET_CLASS_NAME CHATDLG_GetClassName

// 0x0043DD00
static void __cdecl CHATDLG_GetClassName(int nClass, Unicode* pDest)
{
    switch (nClass)
    {
    case 0:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFAB));
        break;
    case 1:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFAA));
        break;
    case 2:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFA9));
        break;
    case 3:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFA8));
        break;
    case 4:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0xFA7));
        break;
    case 5:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0x2771));
        break;
    case 6:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0x2772));
        break;
    default:
        sub_005267E0(pDest, D2LANG_GetStringFromTblIndex(0x1507));
        break;
    }
}

// 0x0043DDD0
void __cdecl CHATDLG_CreateCharControls()
{
    for (int i = 0; i < 17; i++)
        gapChatDlgControls[i] = 0;
    gapChatDlgControls[CHATINIT_CREATESCREENBUTTON] = CONTROL_Create(&gatChatControlInits[CHATINIT_CREATESCREENBUTTON]);
    gapChatDlgControls[CHATINIT_CONTROL_7] = CONTROL_Create(&gatChatControlInits[CHATINIT_CONTROL_7]);
    gapChatDlgControls[CHATINIT_JOINSCREENBUTTON] = CONTROL_Create(&gatChatControlInits[CHATINIT_JOINSCREENBUTTON]);
    gapChatDlgControls[CHATINIT_CONTROL_C] = CONTROL_Create(&gatChatControlInits[CHATINIT_CONTROL_C]);
    gapChatDlgControls[CHATINIT_QUITBUTTON] = CONTROL_Create(&gatChatControlInits[CHATINIT_QUITBUTTON]);
    gapChatDlgControls[CHATINIT_ADIMAGE] = CONTROL_Create(&gatChatControlInits[CHATINIT_ADIMAGE]);
    gapChatDlgControls[CHATINIT_ADSMACK] = CONTROL_Create(&gatChatControlInits[CHATINIT_ADSMACK]);
    CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    D2WinControlInitStrc* pInit = gatControlInits;
    for (int j = 0; j <= 1; j++)
    {
        gapControls_0077B050[j] = CONTROL_Create(pInit);
        ++pInit;
    }
    gpControl_0077BC40 = CONTROL_Create(&gtControlInit_0070D1E0);

    D2ConfigStrc* pInfo = gpCharInfo;
    Unicode wszClass[100];
    char szText[100];
    szText[0] = 0;
    const int nMask20 = pInfo->wFlags1EF & 0x20;
    const int nMask4 = pInfo->wFlags1EF & 4;
    const int nLevel = (pInfo->wFlags1EF >> 8) & 0x1F;
    const char* szRealm = D2Win_10161(pInfo->nClass, nLevel, nMask4, nMask20);
    if (szRealm)
        strcat(szText, szRealm);
    strcat(szText, gpCharInfo->szCharName);
    D2Win_10046(gpControl_0077BC40, szText, (gpCharInfo->aFlags3CB[0] >> 2) & 1);
    GET_CLASS_NAME(gpCharInfo->nClass, wszClass);

    Unicode wszLine[100];
    Unicode wszLevel[10];
    sprintf(szText, gszLevelFormat, gpCharInfo->nLevel ? gpCharInfo->nLevel : 1);
    sub_00526F20_ToUnicode(wszLevel, szText, 9);
    sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xFD9));
    sub_00526700(wszLine, wszLevel);
    sub_00526700(wszLine, wszClass);
    sub_004FC9B0_SetText(gpControl_0077BC40, wszLine, 0, 0, 0);
    sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x2B74), 0, 0, 0);

    switch (((gpCharInfo->wFlags1EF >> 8) & 0x1F) / ((gpCharInfo->wFlags1EF & 0x20) ? 5 : 4))
    {
    case 0:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x2B75), 0, 0, 0);
        break;
    case 1:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x1424), 0, 0, 0);
        break;
    case 2:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x1423), 0, 0, 0);
        break;
    default:
        sub_004FC9B0_SetText(gpControl_0077BC40, D2LANG_GetStringFromTblIndex(0x1422), 0, 0, 0);
        break;
    }

    gpControl_0077BD98 = CONTROL_Create(&gtControlInit_0070D2A0);
    if (gpControl_0077BD98)
        sub_004FC9B0_SetText(gpControl_0077BD98, D2LANG_GetStringFromTblIndex(0x2B73), 3, 0, 0);
}

// 0x0043E130
void __cdecl CHATDLG_ResetChatControls()
{
    for (int i = 0; i <= 1; i++)
    {
        if (gapControls_0077B050[i])
        {
            sub_004F95C0_ControlDestroy(&gapControls_0077B050[i]);
            gapControls_0077B050[i] = 0;
        }
    }
    if (gpControl_0077BC40)
    {
        sub_004F95C0_ControlDestroy(&gpControl_0077BC40);
        gpControl_0077BC40 = 0;
    }
}

// 0x0043E180
static inline void CHATDLG_UnixTimeToFileTime(unsigned int nTime, _FILETIME* pFileTime)
{
    const unsigned __int64 nFileTime = ((unsigned __int64)nTime + 0x2B6109100ull) * 10000000;
    pFileTime->dwLowDateTime = (unsigned long)nFileTime;
    pFileTime->dwHighDateTime = (unsigned long)(nFileTime >> 32);
}

// 0x0043E1A0
static void __stdcall CHATDLG_AddTextLines(D2WinControlStrc* pControl, int bBlankLine, char* szText, int nColor)
{
    char* pText = szText;
    const int nLength = strlen(szText);
    if (nLength > 0)
    {
        while (*pText)
        {
            char* pBreak = 0;
            char* pLine = pText;
            while (*pText != '\n' && *pText)
            {
                pText++;
            }
            if (*pText == '\n')
            {
                pBreak = pText;
                *pText = 0;
                pText++;
            }
            sub_004FCFF0_SetTextA(pControl, pLine, nColor);
            if (bBlankLine)
            {
                sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
            }
            if (pBreak)
            {
                *pBreak = '\n';
            }
        }
    }
    else
    {
        sub_004FCFF0_SetTextA(pControl, &gszEmptyAssertText, nColor);
    }
}

// 0x0043E230
void __cdecl CHATDLG_InitChatLock()
{
    InitializeCriticalSection(&gtChatLock);
}

// 0x0043E240
void __cdecl CHATDLG_DeleteChatLock()
{
    DeleteCriticalSection(&gtChatLock);
}

// 0x0043E250
static D2ChatMessageStrc* __stdcall CHATDLG_CreateChatMessage(const char* szText, int nColor, int bClear)
{
    D2ChatMessageStrc* pMessage = (D2ChatMessageStrc*)FOG_Alloc(sizeof(D2ChatMessageStrc), ".\\Src\\ChatDlg.cpp", 0xC1D, 0);
    memset(pMessage, 0, sizeof(D2ChatMessageStrc));
    if (pMessage)
    {
        if (!szText)
        {
            pMessage->szText = 0;
        }
        else
        {
            const int nLength = SStrLen(szText);
            pMessage->szText = (char*)FOG_Alloc(nLength + 1, ".\\Src\\ChatDlg.cpp", 0xC28, 0);
            if (pMessage->szText)
            {
                SStrCopy(pMessage->szText, szText, 0x7FFFFFFF);
            }
        }
        pMessage->nColor = nColor;
        pMessage->bClear = bClear;
    }
    return pMessage;
}

// 0x0043E2E0
static inline void CHATDLG_FreeChatMessage(D2ChatMessageStrc* pMessage)
{
    if (pMessage)
    {
        if (pMessage->szText)
        {
            FOG_Free(pMessage->szText, ".\\Src\\ChatDlg.cpp", 0xC38, 0);
        }
        FOG_Free(pMessage, ".\\Src\\ChatDlg.cpp", 0xC39, 0);
    }
}

// 0x0043E310
static void CHATDLG_PostChatMessage(const char* szText, int nColor, int bClear)
{
    D2ChatMessageStrc* pMessage = CHATDLG_CreateChatMessage(szText, nColor, bClear);
    if (!pMessage)
    {
        return;
    }
    EnterCriticalSection(&gtChatLock);
    if (gpChatQueueHead)
    {
        gpChatQueueTail->pNext = pMessage;
        gpChatQueueTail = pMessage;
    }
    else
    {
        gpChatQueueHead = pMessage;
        gpChatQueueTail = pMessage;
    }
    LeaveCriticalSection(&gtChatLock);
}

// 0x0043E370
D2ChatMessageStrc* __cdecl CHATDLG_PopChatMessage()
{
    D2ChatMessageStrc* pMessage = 0;
    EnterCriticalSection(&gtChatLock);
    if (gpChatQueueHead)
    {
        pMessage = gpChatQueueHead;
        gpChatQueueHead = gpChatQueueHead->pNext;
    }
    LeaveCriticalSection(&gtChatLock);
    return pMessage;
}

// 0x0043E3A0
void __cdecl CHATDLG_FlushChatMessages()
{
    for (;;)
    {
        D2ChatMessageStrc* pMessage = CHATDLG_PopChatMessage();
        if (!pMessage)
        {
            return;
        }
        if (pMessage->bClear)
        {
            sub_004FB6A0_ClearText(gpChatTextBox);
        }
        if (pMessage->szText)
        {
            CHATDLG_AddTextLines(gpChatTextBox, 0, pMessage->szText, pMessage->nColor);
        }
        CHATDLG_FreeChatMessage(pMessage);
        D2Win_10053(gpChatTextBox, 0);
    }
}

// 0x0043E450
static void __stdcall CHATDLG_FileTimeToText(char* szDate, int nSize, const _FILETIME* pFileTime)
{
    unsigned short wszDate[0x100];
    for (int i = 0; i < 0x100; i++)
        wszDate[i] = 0;
    D2SystemTimeStrc tSystemTime;
    FileTimeToSystemTime(pFileTime, &tSystemTime);
    GetDateFormatA(0x400, 2, &tSystemTime, 0, szDate, nSize);
    MultiByteToWideChar(GetACP(), 1, szDate, -1, wszDate, 0x100);
    UNICODE_ToUtf8(szDate, (Unicode*)wszDate, nSize);
}

// 0x0043E4C0
int __fastcall CHATDLG_OnChatTime(unsigned int nTime, const char* szText)
{
    D2_ASSERT(szText, 0xCA4);
    if (nTime)
    {
        const unsigned __int64 nFileTime = ((unsigned __int64)nTime + 0x2B6109100ull) * 10000000;
        _FILETIME tFileTime;
        tFileTime.dwLowDateTime = (unsigned long)nFileTime;
        tFileTime.dwHighDateTime = (unsigned long)(nFileTime >> 32);
        _FILETIME tLocalTime;
        FileTimeToLocalFileTime(&tFileTime, &tLocalTime);
        char szDate[0x40];
        CHATDLG_FileTimeToText(szDate, 0x40, &tLocalTime);
        CHATDLG_PostChatMessage(szDate, 0, 0);
        CHATDLG_PostChatMessage(szText, 4, 0);
        CHATDLG_PostChatMessage(&gszEmptyAssertText, 0, 0);
    }
    return 1;
}

struct D2WinControlStrc;

// 0x0043E570
int __cdecl CHATDLG_PostClearMessage()
{
    D2ChatMessageStrc* pMessage = (D2ChatMessageStrc*)FOG_Alloc(sizeof(D2ChatMessageStrc), ".\\Src\\ChatDlg.cpp", 0xC1D, 0);
    memset(pMessage, 0, sizeof(D2ChatMessageStrc));
    if (pMessage)
    {
        pMessage->szText = 0;
        pMessage->nColor = 0;
        pMessage->bClear = 1;
        EnterCriticalSection(&gtChatLock);
        if (gpChatQueueHead)
            gpChatQueueTail->pNext = pMessage;
        else
            gpChatQueueHead = pMessage;
        gpChatQueueTail = pMessage;
        LeaveCriticalSection(&gtChatLock);
    }
    return 1;
}

// 0x0043E5F0
int __fastcall CHATDLG_PrintMessage(const Unicode* pText, int nColor)
{
    if (gpChatTextBox)
    {
        sub_004FC9B0_SetText(gpChatTextBox, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E610
int __fastcall CHATDLG_PrintText(Unicode* pText, int nColor)
{
    if (gpChatTextBox)
    {
        sub_004FC9B0_SetText(gpChatTextBox, pText, nColor, 0, 1);
    }

    return 1;
}

// 0x0043E630
int __fastcall CHATDLG_ShowChannelText(Unicode* pText)
{
    if (gpControl_0077BD98)
    {
        sub_004FB6A0_ClearText(gpControl_0077BD98);
        sub_004FC9B0_SetText(gpControl_0077BD98, pText, 3, 0, 0);
    }

    return 1;
}

int __fastcall sub_M110_Emit_0043E180(unsigned int nTime, _FILETIME* pFileTime)
{
    CHATDLG_UnixTimeToFileTime(nTime, pFileTime);
    CHATDLG_FreeChatMessage((D2ChatMessageStrc*)pFileTime->dwHighDateTime);
    return 1;
}


extern D2WinControlStrc* gpChannelOkButton; // 0x0077BCEC

// 0x0043E660
void __cdecl CHATDLG_UpdateOkEnabled()
{
    char szText[0x20];

    const Unicode* pText = sub_004FDD90_GetEditText(gpChannelNameEdit);
    int bEnable = 0;
    if (pText)
    {
        UNICODE_ToAscii(szText, pText, 0x1F);
        if (strlen(szText) >= 1)
            bEnable = 1;
    }
    CONTROL_SetEnabled(gpChannelOkButton, bEnable);
}

// 0x0043E6C0
int __stdcall CHATDLG_OnCancel(SMSGHANDLER_PARAMS* pMsg)
{
    gbDone = 4;
    D2Win_StopMessageLoop();
    return 1;
}

// 0x0043E6E0
static int __stdcall CHATDLG_CompareCommand(const char* szText, const char* szCommand)
{
    if (strlen(szText) < strlen(szCommand))
        return -1;

    unsigned int nLength = strlen(szCommand);
    while (nLength--)
    {
        const int nDiff = toupper(*szText) - toupper(*szCommand);
        if (nDiff)
            return nDiff > 0 ? 1 : -1;
        ++szText;
        ++szCommand;
    }
    return 0;
}

// 0x0043E780
static int CHATDLG_NotifyCommand(const char* szText, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!CHATDLG_CompareCommand(szText, szCommand) && (szText[nLength] == ' ' || !szText[nLength]))
    {
        if (!CHATDLG_CompareCommand(szText, szCommand))
        {
            char szMessage[0x100];
            unsigned short wszMessage[0x100];
            gbShowJoinLeave = !gbShowJoinLeave;
            for (int i = 0; i < 0x100; ++i)
                wszMessage[i] = 0;
            if (gbShowJoinLeave)
                strcpy(szMessage, "Player entering/leaving notifications are enabled.");
            else
                strcpy(szMessage, "Player entering/leaving notifications are disabled.");
            sub_00526320_ToUnicode((Unicode*)wszMessage, szMessage, 0x200);
            if (gpChatTextBox)
                sub_004FC9B0_SetText(gpChatTextBox, (Unicode*)wszMessage, 3, 0, 1);
        }
        return 1;
    }
    return 0;
}

int __fastcall WINMAIN_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue); // 0x00449920

// 0x0043E860
static int __stdcall CHATDLG_FindHashedWord(char* szText, unsigned int nHash, int nLength)
{
    if (!nLength)
        return 0;

    const int nTextLength = SStrLen(szText);
    for (int i = 0; i <= nTextLength - nLength; ++i)
    {
        if (i > 0 && isalnum(szText[i - 1]))
            continue;

        if (i < nTextLength - nLength && isalnum((szText + i)[nLength]))
            continue;

        const unsigned char c = (szText + i)[nLength];
        (szText + i)[nLength] = 0;
        const unsigned int nValue = SStrHashHT(szText + i);
        (szText + i)[nLength] = c;
        if (nValue == nHash)
            return 1;
    }

    return 0;
}

// 0x0043E900
int __stdcall MAINMENUS_FindCdKeyInText(const char* szText)
{
    char szKey[0x400];
    int nCount = 0;
    const int nLength = SStrLen(szText);
    for (int i = 0; i < nLength; ++i)
    {
        if (nLength - i < 16 - nCount)
            return 0;

        const char c = szText[i];
        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            szKey[nCount++] = c;
        }
        else if (c != '-' && c != ' ')
        {
            nCount = 0;
            continue;
        }

        if (nCount == 16)
        {
            unsigned int nProduct;
            unsigned int nValue;
            szKey[16] = 0;
            if (WINMAIN_DecodeCdKey(szKey, &nProduct, &nValue)
                && (nProduct == 6 || nProduct == 7 || nProduct == 10 || nProduct == 12))
                return 1;
            nCount = 0;
        }
    }
    return 0;
}

// 0x0043E9D0
static D2WinControlStrc* CHATDLG_CreateControl(int nIndex)
{
    D2_ASSERT(gnControlCount < 0x20, 0x1475);
    D2WinControlStrc* pControl = CONTROL_Create(&gatChatControlInits[nIndex]);
    gapControls[gnControlCount++] = pControl;
    return pControl;
}

// 0x0043EA20
void __cdecl CHATDLG_DestroyPopupControls()
{
    for (int i = 0; i < gnControlCount; i++)
        sub_004F95C0_ControlDestroy(&gapControls[i]);
    gnControlCount = 0;
    sub_004FA450_SetActive(gapChatDlgControls[CHATINIT_QUITBUTTON]);
    gdwConnectTime = 0;
}

// 0x0043EA70
void __fastcall CHATDLG_ShowMessage(const Unicode* pTitle, const Unicode* pText)
{
// build: symbol ?CHATDLG_DestroyPopupControls@* 0x0043EA20
    CHATDLG_DestroyPopupControls();
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x25);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x27);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x28);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pTitle, 0, 0, 0);
    pControl = CHATDLG_CreateControl(0x29);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pText, 0, 0, 0);
}

// 0x0043EB00
int __stdcall CHATDLG_OnWait(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?CHATDLG_DestroyPopupControls@* 0x0043EA20
    CHATDLG_DestroyPopupControls();
    return 1;
}

// 0x0043EB10
int __stdcall CHATDLG_RunCallback(int nArg)
{
    if (gpfnLaunchCallback)
        gpfnLaunchCallback(nArg);
    return 1;
}

// 0x0043EB30
void __cdecl CHATDLG_CreateControls()
{
    D2WinControlStrc* pControl;
    CHATDLG_CreateControl(0x5D);
    pControl = CHATDLG_CreateControl(0x5E);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C5));
    CHATDLG_CreateControl(0x5F);
    CHATDLG_CreateControl(0x61);
    CHATDLG_CreateControl(0x62);
    CHATDLG_CreateControl(0x63);
    sub_004FA450_SetActive(CHATDLG_CreateControl(0x64));
}

// 0x0043EBA0
int __cdecl CHATDLG_ResetControls()
{
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    const unsigned short wFlags = gpCharInfo->wFlags1EF;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 1);
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 1);
    }
    if (gpCharInfo->szRealm0x361[0])
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CONTROL_7], 1);
    else
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CONTROL_7], gbChatSetup == 0);
    CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CONTROL_C], gbCheck == 0);
    return 1;
}

// 0x0043EC50
void __fastcall CHATDLG_SetLadderSelection(unsigned char nMode, int nId)
{
    gnSelectModeA = nMode;
    gnSelectIdA = nId;
}

// 0x0043EC60
void __fastcall CHATDLG_SelectEntry(const char* szName, int nB, int nC)
{
    if (!gbSelectActive_0077BD00)
        return;
    SStrCopy(gszSelectName, szName, 0x7FFFFFFF);
    char nMode;
    if (nC)
        nMode = nB ? 0x13 : 0x1B;
    else
        nMode = nB ? 0 : 9;
    gnSelectModeA = nMode;
    gnSelectModeB_0070CD63 = nMode;
    gnSelectIdA = -1;
// build: symbol ?gnSelectIdB@* 0x0070CD80
    gnSelectIdB = -1;
    WINMAIN_SendMcpCharRank(szName, nB, nC);
    gdwSelectTime = GetTickCount() + 1000;
}

// 0x0043ECE0
int __stdcall CHATDLG_ScrollLadderUp(int a)
{
    gnSelectIdA -= gnLadderPageSize;
    unsigned char m = gnSelectModeB_0070CD63;
    gnSelectIdA &= (gnSelectIdA <= 0) - 1;
    gnSelectModeA = m;
    return 1;
}

// 0x0043ED10
int __stdcall CHATDLG_ScrollLadderDown(int nUnused)
{
    int nBase = gnLadderPageSize;
    int nOther = gnLadderMaxEntries;
    int nCurrent = gnSelectIdA;
    int nDifference = nOther - nBase;
    int nCombined = nBase + nCurrent;
    if (nCombined < nDifference)
        nDifference = nCombined;
    gnSelectModeA = gnSelectModeB;
    gnSelectIdA = nDifference;
    return 1;
}

// 0x0043ED50
void __cdecl CHATDLG_ClearLadderState()
{
}

// 0x0043ED60
void __cdecl CHATDLG_CreateClassButtons()
{
    D2WinControlStrc* pControl;
    Unicode szText0[0x10];
    Unicode szText1[0x10];
    Unicode szText2[0x10];
    Unicode szText3[0x10];
    Unicode szText4[0x10];
    Unicode szText5[0x10];
    Unicode szText6[0x10];
    sub_00526F20_ToUnicode(szText0, "AMA", 0x10);
    sub_00526F20_ToUnicode(szText1, "SOR", 0x10);
    sub_00526F20_ToUnicode(szText2, "NEC", 0x10);
    sub_00526F20_ToUnicode(szText3, "PAL", 0x10);
    sub_00526F20_ToUnicode(szText4, "BAR", 0x10);
    sub_00526F20_ToUnicode(szText5, "DRU", 0x10);
    sub_00526F20_ToUnicode(szText6, "ASN", 0x10);
    gapClassButtons[0] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x6E);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[0], 1);
    pControl = CHATDLG_CreateControl(0x76);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14CE));
    gapClassButtons[1] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x6F);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[1], 0);
    D2Win_10044(CHATDLG_CreateControl(0x77), szText0);
    gapClassButtons[2] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x70);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[2], 0);
    D2Win_10044(CHATDLG_CreateControl(0x78), szText1);
    gapClassButtons[3] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x71);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[3], 0);
    D2Win_10044(CHATDLG_CreateControl(0x79), szText2);
    gapClassButtons[4] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x72);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[4], 0);
    D2Win_10044(CHATDLG_CreateControl(0x7A), szText3);
    gapClassButtons[5] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x73);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[5], 0);
    D2Win_10044(CHATDLG_CreateControl(0x7B), szText4);
    if (gbExpansionClasses)
    {
        gapClassButtons[6] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x74);
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[6], 0);
        D2Win_10044(CHATDLG_CreateControl(0x7C), szText5);
        gapClassButtons[7] = (D2WinButtonStrc*)CHATDLG_CreateControl(0x75);
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[7], 0);
        D2Win_10044(CHATDLG_CreateControl(0x7D), szText6);
    }
}

// 0x0043F060
void __cdecl CHATDLG_ReleaseClassButtons()
{
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[0], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[1], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[2], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[3], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[4], 0);
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[5], 0);
    if (gbExpansionClasses)
    {
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[6], 0);
        BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[7], 0);
    }
}

// 0x0043F0E0
void __cdecl CHATDLG_ClearLadderList()
{
    sub_004FB6A0_ClearText(gbSelectActive);
    char szText[2];
    Unicode wszText[2] = { Unicode(0), Unicode(0) };
    sprintf(szText, gszDash);
    sub_00526F20_ToUnicode(wszText, szText, 2);
    sub_004FCC40_AddLine(gbSelectActive, wszText, gnColor, 4, 0);
    D2Win_10053(gbSelectActive, 0);
    gnSelection = -2;
}

// 0x0043F150
static int __stdcall CHATDLG_GetClassSlot(int nBase, int nMode)
{
    int nOffset;
    if (nMode >= 9 && nMode <= 16)
    {
        nOffset = 9;
    }
    else if (nMode >= 0 && nMode <= 7)
    {
        nOffset = 0;
    }
    else if (nMode >= 0x13 && nMode <= 0x1A)
    {
        nOffset = 0x13;
    }
    else if (nMode >= 0x1B && nMode <= 0x22)
    {
        nOffset = 0x1B;
    }
    else
    {
        D2_ASSERT(0, 0x1A23);
    }
    return nBase + nOffset;
}

// 0x0043F1D0
int __stdcall CHATDLG_OnOverallLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[0], 1);
    if (gnSelectModeA != 9 && gnSelectModeA != 0)
    {
        gnColor = 0x3E8;
        CHATDLG_ClearLadderList();
// build: symbol ?gnSelectFlag@* 0x0070CD6C
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(0, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

// 0x0043F230
int __stdcall CHATDLG_OnAmazonLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[1], 1);
    if (gnSelectModeA != 10 && gnSelectModeA != 1)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(1, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

// 0x0043F290
int __stdcall CHATDLG_OnSorceressLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[2], 1);
    if (gnSelectModeA != 11 && gnSelectModeA != 2)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(2, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

// 0x0043F2F0
int __stdcall CHATDLG_OnNecromancerLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[3], 1);
    if (gnSelectModeA != 12 && gnSelectModeA != 3)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(3, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

// 0x0043F350
int __stdcall CHATDLG_OnPaladinLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[4], 1);
    if (gnSelectModeA != 13 && gnSelectModeA != 4)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(4, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

// 0x0043F3B0
int __stdcall CHATDLG_OnBarbarianLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[5], 1);
    if (gnSelectModeA != 14 && gnSelectModeA != 5)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(5, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

// 0x0043F410
int __stdcall CHATDLG_OnDruidLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[6], 1);
    if (gnSelectModeA != 15 && gnSelectModeA != 6)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(6, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

// 0x0043F470
int __stdcall CHATDLG_OnAssassinLadderButton(D2WinMsgStrc* pMsg)
{
    CHATDLG_ReleaseClassButtons();
    BUTTON_SetIsPressed((D2WinControlStrc*)gapClassButtons[7], 1);
    if (gnSelectModeA != 16 && gnSelectModeA != 7)
    {
        gnColor = 0xC8;
        CHATDLG_ClearLadderList();
        gnSelectFlag = 1;
        gnSelectModeA = (unsigned char)CHATDLG_GetClassSlot(7, gnSelectModeA);
        gnSelectIdA = 0;
    }
    return 1;
}

extern int gnHistoryCount;                                                                              // 0x0077BD50

// 0x0043F4D0
void __cdecl CHATDLG_ClearHistory()
{
    for (int i = 0; i < 10; i++)
        gaszHistory[i][0] = 0;
// build: symbol ?gnHistoryIndex@* 0x0070CD74
    gnHistoryIndex = -1;
    gnHistoryCount = 0;
}

// 0x0043F510
static void CHATDLG_PushHistory(const char* szText)
{
    memmove(gaszHistory[1], gaszHistory[0], 0x900);
    strcpy(gaszHistory[0], szText);
    if (++gnHistoryCount >= 10)
        gnHistoryCount = 10;
}

int __stdcall CONTROL_SetCellFile(D2WinControlStrc* pControl, D2CelFileStrc* pCellFile);                          // 0x004F91A0

// 0x0043F560
void __fastcall CHATDLG_DisableControl(D2WinControlStrc* pControl)
{
    CONTROL_SetCellFile(pControl, gpRadioButtonGreyCelFile);
    CONTROL_SetEnabled(pControl, 0);
}

// 0x0043F580
int __stdcall CHATDLG_SetUserDataFlag(int nArg)
{
    gbFlag_0077ADA4 = 1;
    return 1;
}

// 0x0043F590
int __stdcall CHATDLG_GetUserDataReply(int nUnused)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = 8;
    tRecord.nValue1 = 0x28;
    tRecord.nValue2 = 0xC8;
    if (gpLaunchFuncs->pfnGetBattleReadUserData(3, 1, &gKey_0077B0A8, &tRecord) || gbFlag_0077ADA4)
        D2Win_StopMessageLoop();
    return 1;
}

// Kept noinline: CHARSEL_SubmitProfile (0x443F80) calls this out of line in the image; without it the compiler inlines it there.
// 0x0043F5F0
__declspec(noinline) int __fastcall CHATDLG_WriteUserData(int nA, int nB, int nC, int nD)
{
    D2LaunchRecord3Strc tRecord;
    tRecord.nValue0 = nB;
    tRecord.nValue1 = nC;
    tRecord.nValue2 = nD;
    return gpLaunchFuncs->pfnBattleWriteUserData(nA, 3, &gKey_0070CD54, &tRecord);
}

static void PrintTextBox(const Unicode* pText, int nColor)
{
    if (gpChatTextBox)
        D2Win_10051((D2WinTextBoxStrc*)gpChatTextBox, pText, nColor, 0, 1);
}

// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0043F630
int __stdcall CHATDLG_OnToggleButton(int nArg)
{
    if (gbGemToggle)
    {
        BUTTON_SetBaseFrame((D2WinButtonStrc*)gpGemButton, 0);
        gbGemToggle = 0;
        PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D7), 0x0B);
    }
    else
    {
        BUTTON_SetBaseFrame((D2WinButtonStrc*)gpGemButton, 2);
        gbGemToggle = 1;
        if (rand() % 1000 == 0)
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D8), 0x0B);
        }
        else if (rand() % 1000 == 0 && rand() % 1000 == 0)
        {
            UnicodeChar wszText[20];
            sub_00526320_ToUnicode(wszText, "Moooooooo!", 12);
            PrintTextBox(wszText, 9);
        }
        else
        {
            PrintTextBox(D2LANG_GetStringFromTblIndex(0x14D6), 0x0B);
        }
    }
    return 1;
}

extern "C" char* __cdecl strncat(char* szDest, const char* szSource, size_t nCount); // 0x00687490


// 0x0043F720
int __stdcall CHATDLG_OnProfileClose(int nArg)
{
    CHATDLG_DestroyGameListControls();
    return 1;
}

// build: symbol ?gbCharSelBusy@* 0x00779DA0
// build: symbol ?gpCharList@* 0x00779DBC
// build: symbol ?FOG_IsExpansion@* 0x00408F20
// build: symbol ?MAINMENUS_DestroyControls@* 0x0042F3F0
// build: symbol ?MAINMENUS_JoinGame@* 0x00434A00

// 0x0043F730
void __cdecl CHATDLG_UpdateNameListText()
{
    char szText[0x200];

    Unicode wszText[0x200];

    if (!gpControlMain)
        return;

    szText[0] = 0;
    int nLen = 0;
    for (D2LaunchNameNodeStrc* pNode = gpNameList; pNode; pNode = pNode->pNext)
    {
        if (nLen >= 0x200)
            break;
        strncat(szText, pNode->szName, 0x200 - nLen);
        nLen = strlen(szText);
    }

    if (!szText[0])
        sub_004F9740_SetControlState(gpNamesButton, 1);
    else
        sub_004F9740_SetControlState(gpNamesButton, 0);

    sub_00526E40_Utf8ToUnicode(wszText, szText, 0x200);
    sub_004FC9B0_SetText(gpControlMain, wszText, 1, 0, 0);
}

// 0x0043F800
void __cdecl CHATDLG_FreeNameList()
{
    D2LaunchNameNodeStrc* pNode = gpNameList;
    while (pNode)
    {
        D2LaunchNameNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\Src\\ChatDlg.cpp", 0x1C01, 0);
        pNode = pNext;
    }
    gpNameList = 0;
}

// 0x0043F840
int __cdecl sub_0043F840_AlwaysOne()
{
    return 1;
}

// Kept noinline: sub_004438C0_OnCancel (0x4438C0) calls this out of line in the image; without it the compiler inlines it there.
// 0x0043F850
__declspec(noinline) int __cdecl CHARSEL_CancelGameCreate()
{
    VIEW_SendMcpCancelGameCreate();
    sub_00449E50_SetValue(0);
    return 1;
}

// 0x0043F870
static void __stdcall CHATDLG_GetArgument(int nSize, const char* szText, char* szDest)
{
    const char* pArg = SStrChr(szText, ' ');
    if (pArg)
        SStrCopy(szDest, pArg + 1, nSize);
    else
        *szDest = 0;
}

// 0x0043F8A0
static inline void CHATDLG_SaveDefaultChannel(const char* szChannel)
{
    SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
}

void __cdecl CHATDLG_DestroyDialogControls();                                                                // 0x0043DB20

extern D2WinControlStrc* gpControl_0077BD90; // 0x0077BD90

extern int gdwGlobal_00798CC0;                                                                              // 0x00798CC0

void __cdecl CHATDLG_DestroyDialogControls(); // 0x0043DB20

// 0x0043F8C0
void __cdecl CHATDLG_ResetLaunchState()
{
    CHATDLG_DestroyCreateControls();
// build: symbol ?CHATDLG_DestroyJoinControls@* 0x00443130
    CHATDLG_DestroyJoinControls();
    CHATDLG_DestroyDialogControls();
    CHATDLG_DestroyPopupControls();
// build: symbol ?CHATDLG_DestroyProfileControls@* 0x00443E10
    CHATDLG_DestroyProfileControls();
    gbSelectActive = 0;
    sub_004F95C0_ControlDestroy(&gpWaitText_0077BD9C);
    sub_004F95C0_ControlDestroy(&gpControl_0077BD90);
    if (gdwGlobal_00798CC0 == 1)
        CHATDLG_DestroyGameListControls();
// build: symbol ?gnChatLaunchMode@* 0x0077BBE4
    if (gnChatLaunchMode == 3)
        gnChatLaunchMode = 0;
    if (gpControlMain)
        sub_004F9740_ControlSetState(gpControlMain, 1);
}

// 0x0043F930
int __stdcall CHATDLG_SetCallback(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
    CHATDLG_ResetLaunchState();
    gpfnLaunchCallback = pfnCallback;
    return 1;
}

// 0x0043F970
int __stdcall CHATDLG_ReleaseAndRecreate(int nArg)
{
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
    CHATDLG_ResetLaunchState();
    CHATDLG_CreateControls();
    return 1;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

// 0x0043F9B0
int __stdcall CHATDLG_ChatEditKeyCallback(void* pArg, int nCursor, const char* pKey)
{
    if (*pKey == 0x0E)
    {
        char szText[0x100];
        char szName[0x100];
        char szLeft[0x100];
        char szRight[0x100];

        const Unicode* pEditText = sub_004FDD90_GetEditText(gpChatEdit);
        if (pEditText && gpSelectedChannelUser)
        {
            COMCALLBACK_CopyNamePrefix(gpSelectedChannelUser->szName, szName);
            Unicode wszText[0x100];
            UNICODE_ToAscii(szText, pEditText, 0x100);
            const int nTextLength = strlen(szText);
            if ((int)strlen(szName) + nTextLength > 0xFF)
            {
                return 0;
            }

            strncpy(szLeft, szText, nCursor);
            szLeft[nCursor] = 0;
            strncpy(szRight, &szText[nCursor], nTextLength - nCursor);
            szRight[nTextLength - nCursor] = 0;
            sprintf(szText, "%s%s%s", szLeft, szName, szRight);
            sub_00526F20(wszText, szText, 0x100);
            EDITBOX_SetText(gpChatEdit, wszText);
        }
        return 0;
    }

    if (*pKey == 9)
    {
        if (gnHistoryCount)
        {
// build: symbol ?gnHistoryIndex@* 0x0070CD74
            ++gnHistoryIndex;
            if (gnHistoryIndex >= gnHistoryCount)
            {
                gnHistoryIndex = 0;
            }
            sub_004FFE10_SetTextA(gpChatEdit, gaszHistory[gnHistoryIndex]);
        }
        return 0;
    }

    return 1;
}

// 0x0043FB50
int __fastcall CHATDLG_ShowWait(const Unicode* pText, D2LaunchCallback pfnDone)
{
    CHATDLG_ResetLaunchState();
    if (gpControlMain)
        sub_004F9740_ControlSetState(gpControlMain, 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    gpWaitText_0077BD9C = CONTROL_Create(&gtWaitInit);
    D2Win_10044(gpWaitText_0077BD9C, pText);
    gpfnLaunchCallback = pfnDone;
    return 1;
}

// 0x0043FBD0
void __cdecl CHATDLG_RefreshChatScreen()
{
    CHATDLG_ResetLaunchState();
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    gnChatLaunchMode = 0;
}

// 0x0043FC20
void __cdecl CHATDLG_CreateChatScreen()
{
    char szText[0x100];

    if (!gbChatSetup)
        return;

    gbChatSetup = 0;
    sprintf(szText, "%s,%s", gpCharInfo->szRealm0x22D, gpCharInfo->szCharName);
    CHATDLG_ResetChatControls();

    if (gpChatCellFile)
        sub_005041B0_Destroy(gpChatCellFile, 1);
    gpChatCellFile = 0;

    BACKGROUND_SetCellFile(gpChatBackground);
    gapChatDlgControls[0] = CONTROL_Create(&gatChatControlInits[0]);
    gapChatDlgControls[1] = CONTROL_Create(&gatChatControlInits[1]);
    gapChatDlgControls[2] = CONTROL_Create(&gatChatControlInits[2]);
    gapChatDlgControls[3] = CONTROL_Create(&gatChatControlInits[3]);
    gapChatDlgControls[4] = CONTROL_Create(&gatChatControlInits[4]);
    gapChatDlgControls[5] = CONTROL_Create(&gatChatControlInits[5]);
    gapChatDlgControls[CHATINIT_UPBUTTON_A] = CONTROL_Create(&gatChatControlInits[CHATINIT_UPBUTTON_A]);
    gapChatDlgControls[CHATINIT_DOWNBUTTON_A] = CONTROL_Create(&gatChatControlInits[CHATINIT_DOWNBUTTON_A]);
    gapChatDlgControls[CHATINIT_UPBUTTON_B] = CONTROL_Create(&gatChatControlInits[CHATINIT_UPBUTTON_B]);
    gapChatDlgControls[CHATINIT_DOWNBUTTON_B] = CONTROL_Create(&gatChatControlInits[CHATINIT_DOWNBUTTON_B]);
    CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CONTROL_7], 1);

    gpChatEdit = CONTROL_Create(&gtChatEditInit);
    sub_004FDAD0_SetKeyCallback(gpChatEdit, sub_0043F9B0_EditKey);
    sub_004FDB00_SetEnterCallback(gpChatEdit, CHATDLG_OnChatEditEnter);
    CONTROL_SetFocusedEditBox(gpChatEdit);
    sub_004FDD50_SetMaxLength(gpChatEdit, 0xC8);
    COMCALLBACK_RefreshChatButtons();

    D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_UPBUTTON_A], 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_DOWNBUTTON_A], 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_UPBUTTON_B], 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_DOWNBUTTON_B], 1);

    D2WinControlStrc** ppButton = gapChatButtons;
    for (int nX = 0x28; nX < 0x2BC; nX += 0x3C)
    {
        *ppButton++ = BUTTON_Create(nX, 0x24F, 0x3C, 0x64, 0, (int)COMCALLBACK_ButtonCallback, 0, 0, 4, 0, 0);
    }

    gpChatControl_0077BC44 = CONTROL_Create(&gtControlInit_0070D210);
    sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
    gpGemButton = CONTROL_Create(&gtGemButtonInit);
    if (gbGemToggle)
        sub_00500B20_SetValue(gpGemButton, 2);
}

static inline int LAUNCH_SetCallback_inl(int nUnused, D2LaunchCallback pfnCallback)
{
    D2_ASSERT(pfnCallback, 0x559);
// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
    CHATDLG_ResetLaunchState();
    gpfnLaunchCallback = pfnCallback;
    return 1;
}

// 0x0043FE40
int __fastcall CHATDLG_SetupLogin(D2LaunchLoginStrc* pLogin, const char* szText0x37)
{
    LAUNCH_SetCallback_inl(0, sub_0043DAF0_OnConnect);
    strcpy(gpCharInfo->szGameName, pLogin->szText0x00);
    strcpy(gpCharInfo->szText0x245, pLogin->szText0x10);
    strcpy(gpCharInfo->szText0x25D, pLogin->szText0x20);
    gnChatLaunchMode = 1;
    if (gpCharInfo->szRealm0x22D[0])
    {
        if (MCPCONNECT_QueryAddress())
        {
            gpCharInfo->dwGameType = 2;
            while (++*(unsigned short*)&gnRequestId_0070CD60 == 0)
            {
            }
            sub_00449E50_SetValue(0);
            WINMAIN_SendMcpCreateGame(pLogin, gnRequestId_0070CD60);
            gwSavedRequestId = gnRequestId_0070CD60;
            return 1;
        }
        gnChatLaunchMode = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        return 0;
    }
    gpCharInfo->dwGameType = 6;
    strcpy(gpCharInfo->szServerIP, szText0x37);
    gbDone = 1;
    sub_004F9160_SetLoopValue(0);
    D2Win_StopMessageLoop();
    return 1;
}

// 0x0043FFA0
int __fastcall CHATDLG_SetupCharacter(unsigned short wValue, const char* szText0x1F, const char* szText0x245, const char* szText0x37)
{
    gnChatLaunchMode = 2;
    CHATDLG_SetCallback(0, sub_0043DAF0_OnConnect);
    gpCharInfo->wJoinID = wValue;
    strcpy(gpCharInfo->szGameName, szText0x1F);
    strcpy(gpCharInfo->szText0x245, szText0x245);
    if (gpCharInfo->nByte22D)
    {
        if (MCPCONNECT_QueryAddress())
        {
            gpCharInfo->dwGameType = 3;
            while (++gwRequestId == 0)
            {
            }
// build: symbol ?WINMAIN_SendMcpJoinGame@* 0x0044A4E0
            WINMAIN_SendMcpJoinGame(szText0x1F, szText0x245, gwRequestId);
            gwSavedRequestId = gwRequestId;
            sub_004F9740_ControlSetState(gpControlMain, 1);
            return 1;
        }
        gnChatLaunchMode = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
        return 0;
    }
    gpCharInfo->dwGameType = 7;
    strcpy(gpCharInfo->szServerIP, szText0x37);
    gbDone = 1;
    sub_004F9160_SetLoopValue(0);
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00440110
int __stdcall CHATDLG_OnEditChange(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?CHATDLG_UpdateOkEnabled@* 0x0043E660
    CHATDLG_UpdateOkEnabled();
    return 1;
}

// 0x00440120
int __stdcall CHATDLG_OnClearEdit(SMSGHANDLER_PARAMS* pMsg)
{
    EDITBOX_SetText(gpChatEdit, 0);
    CHATDLG_DestroyPopupControls();
    return 1;
}

// 0x00440140
void __fastcall CHATDLG_ShowError(const Unicode* pText, D2LaunchCallback pfnDone)
{
    CHATDLG_DestroyPopupControls();
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x21);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x22);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x24);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pText, 0, 0, 0);
    gpfnLaunchCallback = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
}

// 0x004401C0
void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone)
{
    CHATDLG_DestroyPopupControls();
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x21);
    D2Win_10033(pControl, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x23);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = CHATDLG_CreateControl(0x24);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2Win_10051((D2WinTextBoxStrc*)pControl, pText, 0, 0, 0);
    gpfnLaunchCallback = pfnDone ? pfnDone : sub_0043EB00_OnErrorDone;
    gdwConnectTime = GetTickCount();
}

// 0x00440240
int __stdcall CHATDLG_OnReset(SMSGHANDLER_PARAMS* pMsg)
{
    CHATDLG_ResetControls();
    CHATDLG_ResetLaunchState();
    return 1;
}

// 0x00440260
int __stdcall CHATDLG_OnBack(SMSGHANDLER_PARAMS* pMsg)
{
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    CHATDLG_ResetLaunchState();
    CHATDLG_CreateControls();
    return 1;
}

// 0x004402A0
int __cdecl CHATDLG_FindDashLine()
{
    char szText[0x100];
    int nLine = sub_004FB950_GetFirstVisible(gbSelectActive);
    const int nCount = D2Win_10055(gbSelectActive);
    const int nEnd = (nLine + nCount < gnColor) ? nLine + nCount : gnColor;

    for (; nLine < nEnd; ++nLine)
    {
        const Unicode* pText = D2Win_10196(gbSelectActive, nLine, 0);
        UNICODE_ToAscii(szText, pText, 0x100);
        if (!strcmp(szText, "-"))
        {
            gnSelectIdA = gnSelectLine = nLine / 16 * 16;
            return 1;
        }
    }
    return 0;
}

// 0x00440350
int __stdcall CHATDLG_OnIdle(SMSGHANDLER_PARAMS* pMsg)
{
    if (GetTickCount() > gdwSelectTime && gbSelectActive
        && (CHATDLG_FindDashLine() || gnSelectFlag)
        && (gnSelection != gnSelectIdA || gnSelectLine != gnSelectLinePrev))
    {
        gnSelectModeB_0070CD63 = gnSelectModeA;
        gnSelectIdB = gnSelectIdA;
        VIEW_SendMcpLadderRequest(gnSelectModeA, gnSelectLine);
        gdwSelectTime = GetTickCount() + 1000;
        gnSelection = gnSelectIdB;
        gnSelectLinePrev = gnSelectLine;
    }
    return 1;
}

static inline void ResetClassSelectState(int bExpansionClasses)
{
    gbExpansionClasses = bExpansionClasses;
    gapClassButtons[0] = 0;
    gapClassButtons[1] = 0;
    gapClassButtons[2] = 0;
    gapClassButtons[3] = 0;
    gapClassButtons[4] = 0;
    gapClassButtons[5] = 0;
    gapClassButtons[6] = 0;
    gapClassButtons[7] = 0;
    gbSelectActive = 0;
    gnColor = 1000;
}

// 0x004403E0
int __stdcall CHATDLG_OnResetCallback(int nArg)
{
    CHATDLG_ResetLaunchState();
    return 1;
}

// 0x004403F0
void __fastcall CHATDLG_FillLadderList(int nStart, int nCount, int nNameLength, unsigned char nMode, D2LadderEntryStrc* pEntries)
{
    if (!gbSelectActive)
    {
        return;
    }

    char szTitle[256];
    char szNumber[256];
    if (!nCount)
    {
        Unicode wszText[256];
        {
            Unicode wszFormat[256];
            Unicode wszName[256];
            char szName[256];
            CHATDLG_CopyName(szName);
            sub_00526F20_ToUnicode(wszFormat, "Player '%s' is not on the ladder.", 0x100);
            sub_00526F20_ToUnicode(wszName, szName, 0x100);
            sub_005269D0_FormatText(0x100, wszText, wszFormat, wszName);
        }

        CHATDLG_ShowWait(wszText, 0);
        return;
    }

    if (nMode != gnSelectModeA)
    {
        return;
    }

    if (gnSelectIdA == -1)
    {
        D2Win_10053(gbSelectActive, nStart);
        gnSelectIdB = nStart;
        gnSelection = nStart;
        gnSelectIdA = nStart;
    }

    int nEnd = nStart + nCount;
    if (nEnd > gnColor)
    {
        nEnd = gnColor;
    }

    D2LadderEntryStrc* pEntry = pEntries;
    for (int i = nStart; i < nEnd; ++i)
    {
        const int dwFlags = pEntry->dwFlags;
        const int nClass = dwFlags & 0xF;
        const int nLevel = (dwFlags >> 16) & 0xFF;
        const int nColor = !strcmp(pEntry->szName, gszSelectName) ? 0 : ((dwFlags & 0x10) ? 5 : 4);

        sub_004FB870_InsertRow(gbSelectActive, i);
        D2Win_10188(gbSelectActive, i, nColor);

        _itoa(i + 1, szNumber, 10);
        sub_004FCD40_SetCell(gbSelectActive, szNumber, i, 0);

        szTitle[0] = '\0';
        const char* szPrefix = D2Win_10161(nClass, ((unsigned int)dwFlags >> 8) & 0x1F, dwFlags & 0x20, dwFlags & 0x40);
        if (szPrefix)
        {
            strcat(szTitle, szPrefix);
        }

        strcat(szTitle, pEntry->szName);
        sub_004FCD40_SetCell(gbSelectActive, szTitle, i, 1);
        sub_004FCD40_SetCell(gbSelectActive, gaszClassNames[nClass], i, 2);
        _itoa(nLevel, szNumber, 10);
        sub_004FCD40_SetCell(gbSelectActive, szNumber, i, 3);

        Unicode wszDate[256];
        STR_GroupUint64DigitsWithSuffix(wszDate, pEntry->nA, pEntry->nB, 0xFF);
        D2Win_10058(gbSelectActive, wszDate, i, 4);

        pEntry = (D2LadderEntryStrc*)((char*)pEntry + nNameLength + 0xC);
    }
}

// 0x004406F0
void __cdecl CHATDLG_CreateClassScreen()
{
    CHATDLG_CreateClassButtons();
    sub_004FA450_SetActive(CHATDLG_CreateControl(0x6D));
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x67);
    D2Win_10044(pControl, STRTABLE_GetLanguage() == 3 ? D2LANG_GetStringFromTblIndex(0x2B54) : D2LANG_GetStringFromTblIndex(0x14C8));
    pControl = CHATDLG_CreateControl(0x68);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C9));
    pControl = CHATDLG_CreateControl(0x69);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14CA));
    pControl = CHATDLG_CreateControl(0x6B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14CC));
    pControl = CHATDLG_CreateControl(0x6A);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0xFD9));
    gbSelectActive = CHATDLG_CreateControl(0x6C);
    sub_004FC720(gbSelectActive, 0x10);
    sub_004FBC20(gbSelectActive, 5);
    sub_004FB740(gbSelectActive, 0, -6);
    sub_004FBC80(gbSelectActive, 0, 0);
    sub_004FBCD0(gbSelectActive, 0, 0x10);
    sub_004FBC80(gbSelectActive, 1, 0x23);
    sub_004FBC80(gbSelectActive, 2, 0xA5);
    sub_004FBC80(gbSelectActive, 3, 0xC3);
    sub_004FBCD0(gbSelectActive, 3, 0x10);
    sub_004FBC80(gbSelectActive, 4, 0xDC);
    sub_004FBCD0(gbSelectActive, 4, 0x10);
    CHATDLG_ClearLadderList();
    pControl = CHATDLG_CreateControl(0x80);
    sub_004FD830(pControl);
    sub_004FDA50(pControl);
    gszSelectName[0] = 0;
}

// 0x004408B0
void __cdecl CHATDLG_OpenStandardLadder()
{
    if (gpCharInfo->nByte22D)
    {
        ResetClassSelectState(0);
        if (!MCPCONNECT_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(0);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C5));
    CHATDLG_CreateClassScreen();
    gnSelection = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnLadderPageSize = 0x10;
    gnLadderMaxEntries = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440980
void __cdecl CHATDLG_OpenHardcoreLadder()
{
    if (gpCharInfo->nByte22D)
    {
        ResetClassSelectState(0);
        if (!MCPCONNECT_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(0);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x14C6));
    CHATDLG_CreateClassScreen();
    gnSelection = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnLadderPageSize = 0x10;
    gnLadderMaxEntries = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440A50
void __cdecl CHATDLG_OpenExpansionLadder()
{
    if (gpCharInfo->nByte22D)
    {
        ResetClassSelectState(1);
        if (!MCPCONNECT_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(1);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x276A));
    CHATDLG_CreateClassScreen();
    gnSelection = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnLadderPageSize = 0x10;
    gnLadderMaxEntries = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440B30
void __cdecl CHATDLG_OpenExpansionHardcoreLadder()
{
    if (gpCharInfo->nByte22D)
    {
        ResetClassSelectState(1);
        if (!MCPCONNECT_QueryAddress())
        {
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
            return;
        }
    }
    else
    {
        ResetClassSelectState(1);
    }

    CHATDLG_CreateControl(0x65);
    D2WinControlStrc* pControl = CHATDLG_CreateControl(0x66);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x276B));
    CHATDLG_CreateClassScreen();
    gnSelection = -2;
    gnSelectModeB_0070CD63 = 0x23;
    gnLadderPageSize = 0x10;
    gnLadderMaxEntries = 1000;
    sub_0044B210_SetHandlers(CHATDLG_FillLadderList, CHATDLG_ClearLadderState);
}

// 0x00440C10
int __stdcall CHATDLG_ShowStandardLadder(int nArg)
{
    CHATDLG_ResetLaunchState();
    CHATDLG_OpenStandardLadder();
    gnSelectModeA = 9;
    gnSelectIdA = 0;
    return 1;
}

// 0x00440C40
int __stdcall CHATDLG_ShowExpansionLadder(int nArg)
{
    CHATDLG_ResetLaunchState();
    CHATDLG_OpenExpansionLadder();
    gnSelectModeA = 0x1B;
    gnSelectIdA = 0;
    return 1;
}

// 0x00440C70
int __stdcall CHATDLG_ShowExpansionHardcoreLadder(int nArg)
{
    CHATDLG_ResetLaunchState();
    CHATDLG_OpenExpansionHardcoreLadder();
    gnSelectModeA = 0x13;
    gnSelectIdA = 0;
    return 1;
}


extern int gbFlag_0077ADA4; // 0x0077ADA4

extern D2LaunchRecord3Strc gtRecord_0077B0A8; // 0x0077B0A8

// 0x00440CA0
int __fastcall MAINMENUS_RequestProfile(int nA, int nB, int nC, int nD)
{
    gtRecord_0077B0A8.nValue0 = nB;
    gtRecord_0077B0A8.nValue1 = nC;
    gtRecord_0077B0A8.nValue2 = nD;
// build: symbol ?gpLaunchFuncs@* 0x0077B09C
    gpLaunchFuncs->pfnBattleRequestReadUserData(nA, 3, 1, &gKey_0070CD54);
    gbFlag_0077ADA4 = 0;
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), CHATDLG_SetUserDataFlag);
    sub_004FA590_RunLoop(CHATDLG_GetUserDataReply);
    CHATDLG_DestroyPopupControls();
    return gbFlag_0077ADA4 == 0;
}

// 0x00440D10
void __fastcall CHATDLG_SetPlayerName(int nPlayerId, int nDataLength, const char* szName)
{
    D2LaunchNameNodeStrc* pNode;
    for (pNode = gpNameList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nPlayerId)
            break;
    }

    if (!pNode)
    {
        pNode = (D2LaunchNameNodeStrc*)FOG_Alloc(sizeof(D2LaunchNameNodeStrc), ".\\Src\\ChatDlg.cpp", 0x1BAE, 0);
        D2LaunchNameNodeStrc* pCur = gpNameList;
        pNode->nId = nPlayerId;
        if (!pCur || pCur->nId > nPlayerId)
        {
            pNode->pNext = pCur;
            gpNameList = pNode;
        }
        else
        {
            D2LaunchNameNodeStrc* pPrev = pCur;
            do
            {
                if (pCur->nId >= nPlayerId)
                    break;
                pPrev = pCur;
                pCur = pCur->pNext;
            }
            while (pCur);
            pNode->pNext = pCur;
            pPrev->pNext = pNode;
        }
    }

    SStrCopy(pNode->szName, szName, sizeof(pNode->szName));
    CHATDLG_UpdateNameListText();
}

void __stdcall sub_M113_Emit_0043F8A0(const char* szFirst, const char* szSecond)
{
    CHATDLG_SaveDefaultChannel(szFirst);
    CHATDLG_SaveDefaultChannel(szSecond);
}

// 0x00440DB0
int __stdcall CHATDLG_OnQuitMessage(int nArg)
{
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
    gbDone = 4;
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00440DE0
int __stdcall CHATDLG_OpenAdUrl(int nUnused)
{
    const char* szURL = gpLaunchFuncs->pfnQueryAdUrl(gpLaunchContext);
    if (!szURL)
    {
        return 1;
    }
    char szCommand[0x800] = { 0 };
    int bOk = 0;
    SetForegroundWindow(GetDesktopWindow());
    char szKey[0x400];
    sprintf(szKey, "%s\\.html", "SOFTWARE\\Classes");
    unsigned long cbData;
    if (CHATDLG_ReadRegValueHKLM(szKey, 0, (unsigned char*)szCommand, 0x400, &cbData))
    {
        char szOpenKey[0x400];
        sprintf(szOpenKey, "%s\\%s\\shell\\open\\command", "SOFTWARE\\Classes", szCommand);
        char szPath[0x400] = { 0 };
        if (CHATDLG_ReadRegValueHKLM(szOpenKey, 0, (unsigned char*)szPath, 0x400, &cbData))
        {
            strcat(szPath, " ");
            strcat(szPath, szURL);
            D2StartupInfoAStrc si;
            D2ProcessInformationStrc pi;
            SMemZero(&si, sizeof(si));
            si.cb = sizeof(si);
            if (CreateProcessA(0, szPath, 0, 0, 0, 0x20, 0, 0, &si, &pi))
            {
                CloseHandle(pi.hThread);
                CloseHandle(pi.hProcess);
                bOk = 1;
            }
        }
    }
    if (!bOk)
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14DC), 0);
    }
    gpLaunchFuncs->pfnOnAdClick(gpLaunchContext, bOk == 0);
    return 1;
}

struct D2LaunchGameEntryStrc;

struct D2LaunchGameListStrc;

void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80

void* __cdecl GAME_GetChannelName(); // 0x00446CF0

extern D2WinControlInitStrc gtCreateJoinBckgImageInit; // 0x0070D8D0

extern D2WinControlInitStrc gtChannelScreenTitleInit; // 0x0070D900

extern D2WinControlInitStrc gtControlInit_0070D930; // 0x0070D930

extern D2WinControlInitStrc gtControlInit_0070D960; // 0x0070D960

extern D2WinControlInitStrc gtChannelNameEditInit; // 0x0070D990

extern D2WinControlInitStrc gtChannelListInit; // 0x0070D9F0

extern D2WinControlInitStrc gtChannelOkButtonInit; // 0x0070DA20

extern D2WinControlInitStrc gtControlInit_0070E110; // 0x0070E110

extern D2WinControlStrc* gpChannelOkButton; // 0x0077BCEC

D2WinControlStrc* gpCreateJoinBckgImage; // 0x0077BCDC

D2WinControlStrc* gpChannelScreenTitle; // 0x0077BCE0

D2WinControlStrc* gpControl_0077BCE4; // 0x0077BCE4

D2WinControlStrc* gpControl_0077BCE8; // 0x0077BCE8

D2WinControlStrc* gpControl_0077BCF0; // 0x0077BCF0

D2WinControlStrc* gpChannelNameEdit; // 0x0077BCF4

D2WinControlStrc* gpChannelListBox; // 0x0077BCFC

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040

int __fastcall CHATDLG_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord); // 0x004438E0

// 0x00440FC0
void __cdecl CHATDLG_CreateGatewayControls()
{
    gpCreateJoinBckgImage = CONTROL_Create(&gtCreateJoinBckgImageInit);

    gpChannelScreenTitle = CONTROL_Create(&gtChannelScreenTitleInit);
    D2Win_10044(gpChannelScreenTitle, D2LANG_GetStringFromTblIndex(0x148D));

    gpControl_0077BCE4 = CONTROL_Create(&gtControlInit_0070D930);
    D2Win_10044(gpControl_0077BCE4, D2LANG_GetStringFromTblIndex(0x148E));

    gpControl_0077BCE8 = CONTROL_Create(&gtControlInit_0070D960);
    D2Win_10044(gpControl_0077BCE8, D2LANG_GetStringFromTblIndex(0x148F));

    gpChannelOkButton = CONTROL_Create(&gtChannelOkButtonInit);

    gpControl_0077BCF0 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450_SetActive(gpControl_0077BCF0);

    gpChannelNameEdit = CONTROL_Create(&gtChannelNameEditInit);
    sub_004FDD50_SetMaxLength(gpChannelNameEdit, 0x20);
    sub_004FDAD0_SetKeyCallback(gpChannelNameEdit, (int (__stdcall *)(D2WinControlStrc *,int,const char *))CHATDLG_ClearSelection);
    sub_004FDB00_SetEnterCallback(gpChannelNameEdit, (int (__stdcall *)(int))CHATDLG_OnEditChange);

    gpChannelListBox = CONTROL_Create(&gtChannelListInit);

    const char* szList = gpLaunchFuncs->pfnGetChannelList(gpCharInfo->aFlags1EF[0] & 0x20);

    if (gpCharInfo->szRealm0x381[0])
    {
        D2Win_10045(gpChannelListBox, gpCharInfo->szRealm0x381);
    }

    if (gpCharInfo->szRealm0x361[0] && strcmp(gpCharInfo->szRealm0x381, gpCharInfo->szRealm0x361))
    {
        D2Win_10045(gpChannelListBox, gpCharInfo->szRealm0x361);
    }

    while (*szList)
    {
        if (!gpCharInfo->szRealm0x361[0] || strcmp(szList, gpCharInfo->szRealm0x361))
        {
            D2Win_10045(gpChannelListBox, szList);
        }

        while (*szList)
        {
            ++szList;
        }
        ++szList;
    }

    sub_004FFE10_SetTextA(gpChannelNameEdit, (const char*)GAME_GetChannelName());
    CONTROL_SetFocusedEditBox(gpChannelNameEdit);
    D2Win_10082(gpChannelNameEdit);
    D2Win_10053(gpChannelListBox, 0);
// build: symbol ?CHATDLG_UpdateOkEnabled@* 0x0043E660
    CHATDLG_UpdateOkEnabled();
}

// 0x004411E0
void __fastcall CHATDLG_JoinChannel(const char* szText)
{
    gpLaunchFuncs->pfnJoinChannel((int)szText, 0, 0);
    CHATDLG_ResetLaunchState();
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    gnChatLaunchMode = 0;
}

struct D2ListMessage00441320Strc
{
    void* hWnd;
    unsigned int uMessage;
};

extern int gnChannelListLastSelection; // 0x0070EB90

extern unsigned long gdwChannelListLastClickTick; // 0x0077BDA8

static __forceinline int DoubleClick()
{
    int aText[0x40];
    const Unicode* pEditText = sub_004FDD90_GetEditText(gpChannelNameEdit);
    if (!pEditText)
    {
        return 0;
    }
    UNICODE_ToAscii((char*)aText, pEditText, 0x100);
    CHATDLG_JoinChannel((const char*)aText);
    return 0;
}

// build: symbol ?gnChatLaunchMode@* 0x0077BBE4

// 0x00441240
int __stdcall CHATDLG_UseEditText(int nArg)
{
    char szText[0x100];

    if (!sub_004F9710_TestFlag(gpChannelOkButton))
        return 0;

    const Unicode* pText = sub_004FDD90_GetEditText(gpChannelNameEdit);
    if (pText)
    {
        UNICODE_ToAscii(szText, pText, 0x100);
        CHATDLG_JoinChannel(szText);
    }
    return 1;
}



// build: symbol ?gnChatLaunchMode@* 0x0077BBE4

// 0x004412A0
int __stdcall CHATDLG_UseRegistryChannel(int nArg)
{
    char szText[0x20];

// build: symbol ?gpLaunchFuncs@* 0x0077B09C
    if (!gpLaunchFuncs->pfnIsSocketConnected())
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return 1;
    }

    gpLaunchFuncs->pfnFreeBNetNews();
    CHATDLG_PostClearMessage();
    CHATDLG_CreateChatScreen();
    CHATDLG_JoinChannel(SRegLoadString("Diablo II", "Default Channel", 0, szText, 0x20) ? szText : &gszEmptyAssertText);
    return 1;
}

// 0x00441320
int __stdcall CHATDLG_ListClick(D2ListMessage00441320Strc* pMsg)
{
    const int nSelection = sub_004FB990_GetSelection(gpChannelListBox);
    if (nSelection == -1)
    {
        return 0;
    }

    switch (pMsg->uMessage)
    {
    case 0x201:
        {
            const unsigned long dwTick = GetTickCount();
            const int bDoubleClick = nSelection == gnChannelListLastSelection && dwTick - gdwChannelListLastClickTick <= 500;
            if (!bDoubleClick)
            {
                gnChannelListLastSelection = nSelection;
                gdwChannelListLastClickTick = dwTick;
            }
            if (bDoubleClick)
            {
                return DoubleClick();
            }
        }
        break;
    }

    const Unicode* pText = sub_004FBB30_GetText(gpChannelListBox);
    if (!pText)
    {
        return 0;
    }
    EDITBOX_SetText(gpChannelNameEdit, pText);
    CONTROL_SetFocusedEditBox(0);
    return 0;
}

// 0x004413E0
void __stdcall CHATDLG_EnableConnection(int bEnable)
{
    if (bEnable)
    {
        if (!MCPCONNECT_QueryAddress())
        {
            CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return;
        }
        gnChatLaunchMode = 0;
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2B0C), sub_0043DAF0_OnConnect);
        if (gpControlMain)
            sub_004F9740_ControlSetState(gpControlMain, 0);
        return;
    }
    if (!gnChatLaunchMode && gpWaitText)
        CHATDLG_ResetLaunchState();
    const unsigned short wFlags = gpCharInfo->wFlags1EF;
    if (!(wFlags & 8) || !(wFlags & 4))
    {
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 1);
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 1);
    }
    CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CONTROL_C], gbCheck == 0);
    if (gpControlMain)
        sub_004F9740_ControlSetState(gpControlMain, 1);
}

// 0x004414C0
void __cdecl CHATDLG_UpdateEnable()
{
    if (((gpCharInfo->wFlags1EF) & 8) && ((gpCharInfo->wFlags1EF) & 4))
    {
        return;
    }

    int bEnable = 0;
    if (gpCharInfo->nByte22D && !MCPCONNECT_QueryAddress())
    {
        bEnable = 1;
    }

    CHATDLG_EnableConnection(bEnable);
}

// 0x00441500
int __stdcall CHATDLG_OnTick(int nUnused)
{
    static unsigned long s_dwTimer_0077BDC0; // 0x0077BDC0
    static unsigned long s_dwTimer_0077BDBC; // 0x0077BDBC
    static unsigned long s_dwTimer_0077BDB8; // 0x0077BDB8
    tagRECT tRect;
    SetRect(&tRect, 0x91, 0xB, 0x28F, 0x47);
    if (CONTROL_MouseInsideRect(&tRect))
        sub_004F9160_SetLoopValue(gnLoopValueIn_0077BC18);
    else
        sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);

    if (gnChatLaunchMode == 2 && gdwConnectTime > 0)
    {
        if (GetTickCount() - gdwConnectTime > 30000)
        {
            gnChatLaunchMode = 0;
            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1415), 0);
            gdwConnectTime = 0;
        }
    }

    int bPending;
    do
    {
        bPending = COMCALLBACK_PumpMessages() | sub_00449B70_Receive();

        switch (gnChatLaunchMode)
        {
        case 3:
            if (MCPCONNECT_QueryAddress())
            {
                D2LaunchReplyStrc* pReply = (D2LaunchReplyStrc*)GAME_GetMcpReply();
                const unsigned short wId = pReply->wRequestId;
                if (wId != 0)
                {
                    if (wId == gwSavedRequestId)
                    {
// build: symbol ?GAME_GetConnectError@* 0x00449C00
                        const int nResult = GAME_GetConnectError();
                        if (nResult == 0x33)
                        {
// build: symbol ?CHATDLG_FillGameListControl@* 0x00442C20
                            CHATDLG_FillGameListControl();
                            CHATDLG_ClearReply();
                        }
                        else if (nResult == 0x32)
                        {
                            CHATDLG_DestroyJoinControls();
                            CHATDLG_EnableConnection(1);
                            CHATDLG_ClearReply();
                        }
                        else if (pReply->nStatus)
                        {
                            CHATDLG_FillGameListControl();
                            CHATDLG_ClearReply();
                        }
                        else
                        {
                            CHATDLG_HandleGameListReply(pReply);
                            CHATDLG_ClearReply();
                        }
                    }
                    else
                    {
                        if (wId == gwOtherRequestId)
                            CHATDLG_ShowGameDetails(pReply);
                        CHATDLG_ClearReply();
                    }
                }
            }
            break;

        case 2:
            if (MCPCONNECT_QueryAddress())
            {
                const int nId = CHATDLG_GetRequestId();
                if (nId != 0 && nId == gwSavedRequestId)
                {
                    switch (GAME_GetConnectError())
                    {
                    case 0:
                    {
                        gpCharInfo->dwGameType = 3;
// build: symbol ?GAME_GetMcpGameToken@* 0x00449BE0
                        gpCharInfo->wJoinID = (unsigned short)GAME_GetMcpGameToken();
                        gpCharInfo->dwGameHash = GAME_GetMcpGameHash();
                        const char* szSource = (const char*)GAME_GetMcpGameServerIP();
                        char* szDest = gpCharInfo->szServerIP;
                        char c;
                        do
                        {
                            c = *szSource;
                            *szDest = c;
                            szSource++;
                            szDest++;
                        }
                        while (c != 0);
                        gbDone = 1;
                        gpLaunchFuncs->pfnNotifyJoinedGame(gpCharInfo->szGameName, gpCharInfo->szText0x245);
                        sub_004F9160_SetLoopValue(0);
                        D2Win_StopMessageLoop();
                        return 1;
                    }
                    case 42:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1427), sub_0043DAF0_OnConnect);
                        break;
                    case 41:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1428), sub_0043DAF0_OnConnect);
                        break;
                    case 43:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1429), sub_0043DAF0_OnConnect);
                        break;
                    case 44:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x142A), sub_0043DAF0_OnConnect);
                        break;
                    case 115:
                        gnChatLaunchMode = 0;
                        if (gpCharInfo->wFlags1EF & 0x20)
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x5522), sub_0043DAF0_OnConnect);
                        else
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x14F4), sub_0043DAF0_OnConnect);
                        break;
                    case 116:
                        gnChatLaunchMode = 0;
                        if (gpCharInfo->wFlags1EF & 0x20)
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x5521), sub_0043DAF0_OnConnect);
                        else
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x14F3), sub_0043DAF0_OnConnect);
                        break;
                    case 125:
                        gnChatLaunchMode = 0;
                        if (gpCharInfo->nByte3C2)
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2AB1), sub_0043DAF0_OnConnect);
                        else
                            CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2AB2), sub_0043DAF0_OnConnect);
                        break;
                    case 113:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1426), sub_0043DAF0_OnConnect);
                        break;
                    case 120:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2775), sub_0043DAF0_OnConnect);
                        break;
                    case 121:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x2776), sub_0043DAF0_OnConnect);
                        break;
                    default:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1415), sub_0043DAF0_OnConnect);
                        break;
                    }
                }
            }
            break;

        case 1:
            if (MCPCONNECT_QueryAddress())
            {
                const int nId = CHATDLG_GetRequestId();
                if (nId != 0 && nId == gwSavedRequestId)
                {
                    switch (GAME_GetConnectError())
                    {
                    case 0:
                        gnChatLaunchMode = 2;
                        while (++gwRequestId == 0)
                        {
                        }
                        WINMAIN_SendMcpJoinGame(gpCharInfo->szGameName, gpCharInfo->szText0x245, gwRequestId);
                        gwSavedRequestId = gwRequestId;
                        gpLaunchFuncs->pfnRefreshGame(gpCharInfo->szGameName, gpCharInfo->szText0x245, &gszEmptyAssertText, 0);
                        break;
                    case 30:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1411), sub_0043DAF0_OnConnect);
                        break;
                    case 31:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1412), sub_0043DAF0_OnConnect);
                        break;
                    case 32:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), sub_0043DAF0_OnConnect);
                        break;
                    default:
                        gnChatLaunchMode = 0;
                        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1414), sub_0043DAF0_OnConnect);
                        break;
                    }
                }
            }
            break;
        }

        int bUpdated = 0;
        unsigned long dwElapsed = GetTickCount() - s_dwTimer_0077BDC0;
        if (dwElapsed >= 15000)
        {
            s_dwTimer_0077BDC0 += dwElapsed;
            bUpdated = 1;
            gpLaunchFuncs->pfnCheckAd();
            const unsigned short wFlags = gpCharInfo->wFlags1EF;
            if (!(wFlags & 8) || !(wFlags & 4))
            {
                int bEnable = 0;
                if (gpCharInfo->nByte22D && !MCPCONNECT_QueryAddress())
                    bEnable = 1;
                CHATDLG_EnableConnection(bEnable);
            }
        }
        if (gnChatLaunchMode == 3)
        {
            dwElapsed = GetTickCount() - s_dwTimer_0077BDBC;
            if (dwElapsed >= 15000)
            {
                s_dwTimer_0077BDBC += dwElapsed;
                bUpdated = 1;
// build: symbol ?CHARSEL_RequestGameList@* 0x00445020
                CHARSEL_RequestGameList();
            }
        }
        dwElapsed = GetTickCount() - s_dwTimer_0077BDB8;
        if (dwElapsed >= 1000)
        {
            s_dwTimer_0077BDB8 += dwElapsed;
            bUpdated = 1;
            CHATDLG_SendPendingText();
        }
        CHATDLG_FlushChatMessages();
        if (!bUpdated)
            return 0;
    }
    while (bPending);
    return 1;
}

// 0x00441A90
int __cdecl CHATDLG_ConnectRealm()
{
    if (!gpCharInfo->szRealm0x22D[0])
        return 1;
    if (!gpLaunchFuncs)
        return 0;
    if (!gpLaunchFuncs->pfnIsSocketConnected())
        return 0;
    if (MCPCONNECT_QueryAddress())
        return 1;
    gfRealmConnectCancelled = 0;
    CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), CHATDLG_OnRealmConnectCancel);
    D2LaunchPayloadStrc* pPayload = gpLaunchFuncs->pfnLogonRealm(gpCharInfo->szRealm0x22D, gszPassword);
    if (!pPayload)
        return 0;
    if (pPayload->nSize <= 8)
        return 0;
    CHATDLG_StartThread(&pPayload->tRecord);
    sub_004FA590_RunLoop(sub_0043DBC0);
// build: symbol ?CHATDLG_DestroyPopupControls@* 0x0043EA20
    CHATDLG_DestroyPopupControls();
// build: symbol ?GAME_GetConnectError@* 0x00449C00
    if (gfRealmConnectCancelled || !MCPCONNECT_QueryAddress() || GAME_GetConnectError())
    {
        CHATDLG_DestroyPopupControls();
        return 0;
    }
    CHATDLG_RequestCharLogon(gpCharInfo->szCharName);
    sub_004FA590_RunLoop(sub_0043DBF0);
    CHATDLG_DestroyPopupControls();
    return GAME_GetConnectError() == 0;
}

// 0x00441B70
int __fastcall CHATDLG_RunChat(D2ConfigStrc* pInfo)
{
    char szTitle[256];
    D2WinControlStrc* pControl8;
    D2WinControlStrc* pControl4;

    GetTickCount();
    if (!STRTABLE_LoadStringTables(sub_004FAC80(FOG_IsExpansion()), 0))
        return 1;

    gnChatLaunchMode = 0;
    gbDone = 0;
    gdwGlobal_0077BBF8 = 1;
    gpLaunchFuncs = *(D2LaunchFuncsStrc**)((char*)pInfo + 0x225);
    D2_ASSERT(gpLaunchFuncs, 3303);
    if (!gpLaunchFuncs->pfnIsSocketConnected())
        gbDone = 4;
    else
    {
    CHATDLG_LoadFrontEndCels();
    sub_004F9160_SetLoopValue(gnLoopValueOut_0077BC14);
    gpChatTextBox = 0;
    if (gpCharInfo->szRealm0x361[0])
        BACKGROUND_SetCellFile(gpChatBackground);
    else
        BACKGROUND_SetCellFile(gpWaitingRoomBkgdCelFile);
    if (gpCharInfo->szRealm0x361[0])
    {
        for (int i = 0; i < CHATINIT_COUNT; i++)
            gapChatDlgControls[i] = CONTROL_Create(&gatChatControlInits[i]);
        gpControl_0077BD98 = CONTROL_Create(&gtControlInit_0070D2A0);
    }
    else
    {
        CHATDLG_CreateCharControls();
        CREATE_CELL_FILE(pInfo);
    }
    gpChatTextBox = CONTROL_Create(&gtChatTextBoxInit);
    if (gpCharInfo->szRealm0x361[0])
    {
        gpChatEdit = CONTROL_Create(&gtChatEditInit);
        sub_004FDAD0_SetKeyCallback(gpChatEdit, sub_0043F9B0_EditKey);
        sub_004FDB00_SetEnterCallback(gpChatEdit, CHATDLG_OnChatEditEnter);
        CONTROL_SetFocusedEditBox(gpChatEdit);
        sub_004FDD50_SetMaxLength(gpChatEdit, 200);
        COMCALLBACK_RefreshChatButtons();
        D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_UPBUTTON_A], 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_DOWNBUTTON_A], 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_UPBUTTON_B], 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(gapChatDlgControls[CHATINIT_DOWNBUTTON_B], 1);
        D2WinControlStrc** ppButton = gapChatButtons;
        for (int nX = 40; nX < 700; nX += 60, ppButton++)
            *ppButton = BUTTON_Create(nX, 591, 60, 100, 0, (int)COMCALLBACK_ButtonCallback, 0, 0, 4, 0, 0);
        gpChatControl_0077BC44 = CONTROL_Create(&gtControlInit_0070D210);
        sub_004F9740_SetControlState(gpChatControl_0077BC44, 0);
        gpGemButton = CONTROL_Create(&gtGemButtonInit);
        if (gbGemToggle)
            sub_00500B20_SetValue(gpGemButton, 2);
    }
    CHATDLG_ClearHistory();
// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
    CHATDLG_ResetLaunchState();
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    gnChatLaunchMode = 0;
    pControl8 = CONTROL_Create(&gtControlInit_0070D2D0);
    gpNamesButton = CONTROL_Create(&gtBlankBckgImageInit);
    gpControlMain = CONTROL_Create(&gtControlInit_0070D330);
    GAME_SetMcpChatCallback(CHATDLG_SetPlayerName);
    VIEW_SendMcpMotdRequest();
    CHATDLG_UpdateNameListText();
    pControl4 = CONTROL_Create(&gtControlInit_0070D360);
    const unsigned short wFlags = gpCharInfo->wFlags1EF;
    if ((wFlags & 8) && (wFlags & 4))
    {
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
        CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    }
    sub_004FA450_SetActive(gapChatDlgControls[CHATINIT_QUITBUTTON]);
    gszText_0077B1D0[0] = 0;
    gszText_0077B0B4[0] = 0;
    D2SOUNDFAST_InitWaveSlots();
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\button.wav");
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
    gbCheck = gpCharInfo->nStartMode == 4;
    CONTROL_SetEnabled(gapChatDlgControls[CHATINIT_CONTROL_C], gbCheck == 0);
    if (CHATDLG_ConnectRealm())
    {
        sprintf(szTitle, "%s,%s", pInfo->szRealm0x22D, pInfo->szCharName);
        int nFlags = 0;
        if (pInfo->wFlags1EF & 0x20)
            nFlags = 1;
        if (gpCharInfo->szRealm0x361[0])
            nFlags |= 2;
        gpLaunchFuncs->pfnEnterChat(pInfo->szCharName, szTitle, 0x25, pInfo->szRealm0x361, nFlags);
    }
    else
    {
        LOGMANAGER_WriteLogLine("[D2MULTI]  Could not restore MCP connection.");
        gpLaunchFuncs->pfnCloseBNetConnection();
    }
    if (gpLaunchFuncs->pfnIsSocketConnected())
    {
        sub_00449E50_SetValue(0);
        InitializeCriticalSection(&gtChatLock);
        if (!gpCharInfo->szRealm0x361[0])
// build: symbol ?CHATDLG_PostClearMessage@* 0x0043E570
            gpLaunchFuncs->pfnLoadBNetNews(CHATDLG_OnChatTime, (void (__cdecl*)())CHATDLG_PostClearMessage);
        sub_004FA590_RunLoop(CHATDLG_OnTick);
// build: symbol ?GAME_IsMcpCreateQueued@* 0x00449E40
        if (GAME_IsMcpCreateQueued())
        {
            VIEW_SendMcpCancelGameCreate();
            sub_00449E50_SetValue(0);
        }
        if (!gpCharInfo->szRealm0x361[0])
            gpLaunchFuncs->pfnFreeBNetNews();
        DeleteCriticalSection(&gtChatLock);
        gpLaunchFuncs->pfnLeaveChat();
        if (gbDone != 4)
            D2MCPClientCloseMCP();
    }
    else
        gbDone = 4;

    GetTickCount();
    D2SOUNDFAST_FreeWaveSlots();
    COMCALLBACK_ClearChannel();
    D2Win_10146();
    CHATDLG_ResetLaunchState();
    CHATDLG_FreeNameList();
    sub_004F95C0_ControlDestroy(&gpChatTextBox);
    if (gpControl_0077BD98)
        sub_004F95C0_ControlDestroy(&gpControl_0077BD98);
    sub_004F95C0_ControlDestroy(&pControl8);
    sub_004F95C0_ControlDestroy(&pControl4);
    sub_004F95C0_ControlDestroy(&gpNamesButton);
    sub_004F95C0_ControlDestroy(&gpControlMain);
    if (gpGemButton)
        sub_004F95C0_ControlDestroy(&gpGemButton);
    if (gpChatEdit)
        sub_004F95C0_ControlDestroy(&gpChatEdit);
    for (int j = 0; j < 11; j++)
    {
        if (gapChatButtons[j])
            sub_004F95C0_ControlDestroy(&gapChatButtons[j]);
        gapChatButtons[j] = 0;
    }
    sub_004F95C0_ControlDestroy(&gpChatControl_0077BC44);
    for (int k = 0; k < 17; k++)
    {
        if (gapChatDlgControls[k])
            sub_004F95C0_ControlDestroy(&gapChatDlgControls[k]);
        gapChatDlgControls[k] = 0;
    }
    if (!gpCharInfo->szRealm0x361[0])
    {
        for (int m = 0; m <= 1; m++)
        {
            if (gapControls_0077B050[m])
            {
                sub_004F95C0_ControlDestroy(&gapControls_0077B050[m]);
                gapControls_0077B050[m] = 0;
            }
        }
        if (gpControl_0077BC40)
        {
            sub_004F95C0_ControlDestroy(&gpControl_0077BC40);
            gpControl_0077BC40 = 0;
        }
    }
    BACKGROUND_SetCellFile(0);
    sub_004F9160_SetLoopValue(0);
    CHATDLG_FreeCellFiles();
    }
    STRTABLE_UnloadStringTables();
    return 1;
}

// 0x00442150
int __fastcall CHATDLG_StartChat(D2ConfigStrc* pInfo)
{
    gpCharInfo = pInfo;
    D2Win_10015();
    D2Win_10005(1);
    CHATDLG_RunChat(pInfo);
    D2Win_10016();
    return gbDone;
}

// 0x00442180
static int CHATDLG_ReplyCommand(const char* szText, const char* szCommand)
{
    const size_t nLength = strlen(szCommand);
    if (!CHATDLG_CompareCommand(szText, szCommand))
    {
        if (szText[nLength] == ' ' || !szText[nLength])
        {
            char szMessage[260];
            if (!strlen(gszLastWhisperer))
            {
                Unicode wszMessage[0x100] = {};
// build: symbol ?gszNobodyToReply@* 0x006D561C
                sprintf(szMessage, gszNobodyToReply);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox)
                    sub_004FC9B0_SetText(gpChatTextBox, wszMessage, 1, 0, 1);
                return 1;
            }

            char szPrefix[0x100];
// build: symbol ?gszCommandSpace@* 0x006D5618
            sprintf(szPrefix, gszCommandSpace, szCommand);
            char szCopy[0x100];
            const char* pMessage;
            if (!CONSOLE_FindSecondTokenInline(szText, szCopy, &pMessage))
            {
                Unicode wszMessage[0x100];
// build: symbol ?gszCorrectUsage@* 0x006D55F8
                sprintf(szMessage, gszCorrectUsage, szCommand);
                sub_00526320_ToUnicode(wszMessage, szMessage, 0x100);
                if (gpChatTextBox)
                    sub_004FC9B0_SetText(gpChatTextBox, wszMessage, 1, 0, 1);
                return 1;
            }
            if (!gpLaunchFuncs->pfnIsSocketConnected())
            {
                CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
                return 1;
            }

// build: symbol ?gszReplyFormat@* 0x006D55EC
            sprintf(szMessage, gszReplyFormat, gszLastWhisperer, pMessage);
            gpLaunchFuncs->pfnChatCommand(szMessage);
            return 1;
        }
    }
    return 0;
}

// 0x00442350
int __stdcall CHATDLG_OpenLadderScreen(int nArg)
{
    CHATDLG_ResetLaunchState();
    CHATDLG_OpenHardcoreLadder();
    gnSelectModeA = 0;
    gnSelectIdA = 0;
    return 1;
}

// 0x00442370
int __stdcall CHATDLG_ReleaseAndCreate(int nArg)
{
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    CHATDLG_ResetLaunchState();
    CHATDLG_CreateGatewayControls();
    return 1;
}

// 0x004423B0
void __fastcall CHATDLG_RunCommand(char* szText)
{
    CHATDLG_PushHistory(szText);
// build: symbol ?gszCmdR@* 0x006D56D4
    if (CHATDLG_ReplyCommand(szText, gszCmdR))
        return;

// build: symbol ?gszCmdReply@* 0x006D56CC
    if (CHATDLG_ReplyCommand(szText, gszCmdReply))
        return;

// build: symbol ?gszCmdD2Notify@* 0x006D56C0
    if (CHATDLG_NotifyCommand(szText, gszCmdD2Notify))
        return;

    if (!CHATDLG_CompareCommand(szText, "/ignorepersist"))
    {
        sub_00611560_GetSquelchList()->SetPersist(!sub_00611560_GetSquelchList()->GetPersist());
        if (sub_00611560_GetSquelchList()->GetPersist())
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA1), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA2), 3);
        return;
    }

// build: symbol ?gszCmdSquelch@* 0x006D5698
    if (!CHATDLG_CompareCommand(szText, "/ignore ") || !CHATDLG_CompareCommand(szText, gszCmdSquelch))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        CHATDLG_GetArgument(0x11, szText, szName);
        if (!SStrCmpI(&szName[1], gpCharInfo->szAccount, 0x7FFFFFFF))
            return;

        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Squelch(szName))
            sub_005269D0_FormatText(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA3), wszName);
        else
            sub_005269D0_FormatText(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA4), wszName);
        sub_00526700(wszMessage, wszFormat);
        CHATDLG_PrintMessage(wszMessage, 3);
        return;
    }

// build: symbol ?gszCmdUnsquelch@* 0x006D5680
    if (!CHATDLG_CompareCommand(szText, "/unignore ") || !CHATDLG_CompareCommand(szText, gszCmdUnsquelch))
    {
        Unicode wszFormat[0x208];
        Unicode wszMessage[0x208];
        Unicode wszName[0x22];
        char szName[0x11];
        CHATDLG_GetArgument(0x11, szText, szName);
        sub_00526320_ToUnicode(wszName, szName, 0x22);
        if (sub_00611560_GetSquelchList()->Unsquelch(szName))
            sub_005269D0_FormatText(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA5), wszName);
        else
            sub_005269D0_FormatText(0x208, wszFormat, D2LANG_GetStringFromTblIndex(0x2BA6), wszName);
        sub_00526700(wszMessage, wszFormat);
        CHATDLG_PrintMessage(wszMessage, 3);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, "/filtermsg "))
    {
        char szFilter[0x104];
        CHATDLG_GetArgument(0x104, szText, szFilter);
        if (sub_00611560_GetSquelchList()->AddFilter(szFilter))
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA7), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA8), 3);
        return;
    }

    if (!CHATDLG_CompareCommand(szText, "/unfiltermsg "))
    {
        char szFilter[0x104];
        CHATDLG_GetArgument(0x104, szText, szFilter);
        if (sub_00611560_GetSquelchList()->RemoveFilter(szFilter))
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BA9), 3);
        else
            CHATDLG_PrintMessage(D2LANG_GetStringFromTblIndex(0x2BAA), 3);
        return;
    }

// build: symbol ?gszCmdHomeSpace@* 0x006D5638
// build: symbol ?gszCmdDefaultChannel@* 0x006D5640
// build: symbol ?gszCmdHomeChannel@* 0x006D5654
    if (!CHATDLG_CompareCommand(szText, gszCmdHomeChannel) || !CHATDLG_CompareCommand(szText, gszCmdDefaultChannel) || !CHATDLG_CompareCommand(szText, gszCmdHomeSpace))
    {
        char szChannel[0x20];
        CHATDLG_GetArgument(0x20, szText, szChannel);
        SRegSaveString("Diablo II", "Default Channel", 0, szChannel);
        return;
    }

// build: symbol ?gszCmdHome@* 0x006D5630
    if (!CHATDLG_CompareCommand(szText, gszCmdHome))
    {
        char szChannel[0x20];
        if (SRegLoadString("Diablo II", "Default Channel", 0, szChannel, 0x20))
            CHATDLG_JoinChannel(szChannel);
        return;
    }

    if (!gpLaunchFuncs->pfnIsSocketConnected())
    {
        CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
        return;
    }

    gpLaunchFuncs->pfnChatCommand(szText);
}

// 0x00442810
int __cdecl CHATDLG_SendChatBuffer()
{
    if (gszChatBuffer[0] == '/')
    {
        CHATDLG_RunCommand(gszChatBuffer);
    }
    else
    {
        if (!gpLaunchFuncs->pfnIsSocketConnected())
        {
            CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x14E7), sub_0043E6C0_OnError);
            return 1;
        }
        gpLaunchFuncs->pfnChatCommand(gszChatBuffer);
        COMCALLBACK_PrintOwnLine(gszChatBuffer);
    }
    EDITBOX_SetText(gpChatEdit, 0);
    const int nFirst = D2Win_10055(gpChatTextBox);
    const int nCount = D2Win_10052_TEXTBOX_GetNumLines(gpChatTextBox);
    if (nCount > nFirst)
        D2Win_10053(gpChatTextBox, nCount - nFirst);
    return 1;
}

// 0x004428B0
int __stdcall CHATDLG_SendChat(int nArg)
{
    CHATDLG_SendChatBuffer();
    CHATDLG_DestroyPopupControls();
    return 1;
}



// 0x004428D0
int __fastcall CHATDLG_SendChatText(char* szText, int bWhisper)
{
    const int bCommand = szText[0] == '/';
    SMemZero(gszChatBuffer, sizeof(gszChatBuffer));
    if (bWhisper && !bCommand && gpSelectedChannelUser)
        sprintf(gszChatBuffer, "/whisper *%s %s", COMCALLBACK_SkipNamePrefix(gpSelectedChannelUser->szName), szText);
    else
        strcpy(gszChatBuffer, szText);

    if (CHATDLG_FindHashedWord(szText, gpCharInfo->dwPasswordHash, gpCharInfo->nPasswordLength))
    {
        CHATDLG_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B37), D2LANG_GetStringFromTblIndex(0x2B38));
        gszChatBuffer[0] = 0;
        return 0;
    }

    if (MAINMENUS_FindCdKeyInText(szText))
    {
        CHATDLG_ShowMessage(D2LANG_GetStringFromTblIndex(0x2B7A), D2LANG_GetStringFromTblIndex(0x2B7B));
        gszChatBuffer[0] = 0;
        return 0;
    }

    return CHATDLG_SendChatBuffer();
}

// build: symbol ?gnChatLaunchMode@* 0x0077BBE4
// build: symbol ?gpLaunchFuncs@* 0x0077B09C

// 0x004429A0
int __stdcall CHATDLG_OnChatLine(const Unicode* pText)
{
    char szCopy[0x100];
    char szText[0x100];

// build: symbol ?gnHistoryIndex@* 0x0070CD74
    gnHistoryIndex = -1;
    if (!UNICODE_StrLen(pText))
        return 0;

    D2_ASSERT(gpLaunchFuncs, 0x12C2);

    szText[0] = 0;
    UNICODE_ToAscii(szText, pText, 0x100);
    strcpy(szCopy, szText);

    char szDelim[2] = " ";
    if (!strtok(szCopy, szDelim))
    {
// build: symbol ?gpChatEdit@* 0x0077BD94
        EDITBOX_SetText(gpChatEdit, 0);
        return 1;
    }
    return CHATDLG_SendChatText(szText, 0);
}

// 0x00442A70
void __fastcall CHATDLG_SetFlagBits12(unsigned int* pFlags, int nValue)
{
    *pFlags = (*pFlags & 0xFFFF8FFF) | (nValue << 12);
}

// 0x00442A80
int __fastcall CHATDLG_IsNightmareOpen(unsigned int nFlags)
{
    if (nFlags & 0x20)
        return (nFlags & 0x1F00) >= 0x500;
    return (nFlags & 0x1F00) >= 0x400;
}

// 0x00442AB0
int __fastcall CHATDLG_IsHellOpen(unsigned int nFlags)
{
    if (nFlags & 0x20)
        return (nFlags & 0x1F00) >= 0xA00;
    return (nFlags & 0x1F00) >= 0x800;
}

// 0x00442AE0
const char* __fastcall CHATDLG_SkipString(const char* szText)
{
    D2_ASSERT(szText, 0xAD);
    while (*szText != 0)
        szText += 1;
    return szText + 1;
}

// 0x00442B20
int __fastcall CHATDLG_IsCharOverLimit(const unsigned char* pChar)
{
    unsigned char nChar = *pChar;
    const unsigned short wFlags = gpCharInfo->wFlags1EF;
    const int nLimit = ((wFlags >> 8) & 0x1F) / 5 + 1;
    if (wFlags & 4)
    {
        if (nChar - '3' > nLimit || nChar < '3')
            return 1;
        return 0;
    }
    return nChar - '0' > nLimit;
}

// 0x00442B90
void __fastcall CHATDLG_HandleGameListReply(D2LaunchReplyStrc* pReply)
{
    const int nCount = gnGameCount;
    for (int i = 0; i < nCount; ++i)
    {
        if (gatReplyEntries[i].wGameId == pReply->wGameId)
            return;
    }
    gatReplyEntries[nCount].wGameId = pReply->wGameId;
    gatReplyEntries[nCount].nValue = 0;
    gatReplyEntries[nCount].wValue = pReply->wValue;
    strcpy(gatReplyEntries[nCount].szName, pReply->szName);
    strcpy(gatReplyEntries[nCount].szDesc, pReply->szDesc);
    gnGameCount = nCount + 1;
}


int __fastcall sub_004FBD20_GetLastRow(D2WinControlStrc* pControl); // 0x004FBD20

int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int nLineNum, int nColumn); // 0x004FCD40



extern D2LaunchGameRecStrc gaGames[]; // 0x0078A440


extern D2WinControlStrc* gpGameList; // 0x00798BC0

extern int gnLastGameCount; // 0x00798CC8


// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00442C20
void __cdecl CHATDLG_FillGameListControl()
{
    char szSel[0x100];
    char szNumber[0x10];

    if (!gpGameList)
        return;

    const Unicode* pSel = sub_004FBB30_GetText(gpGameList);
    int bHaveSel = 0;
    if (pSel)
    {
        UNICODE_ToAscii(szSel, pSel, 0x100);
        bHaveSel = 1;
    }

    int nTop = sub_004FB950_GetFirstVisible(gpGameList);
    sub_004FB6A0_ClearText(gpGameList);
    sub_004FB6A0_ClearText(gpGameInfoText);
    gnLastGameCount = gnGameCount;
    if (!gnLastGameCount)
        return;

    int bNoNumbers = !MCPCONNECT_QueryAddress();
    memcpy(gaGames, gaNewGames, gnGameCount * sizeof(D2LaunchGameRecStrc));
    for (int i = 0; i < gnLastGameCount; ++i)
    {
        D2Win_10045(gpGameList, gaGames[i].szName);
        int nRow = sub_004FBD20_GetLastRow(gpGameList);
        if (!bNoNumbers)
        {
            _itoa(*(unsigned short*)gaGames[i].wValue0x31, szNumber, 10);
            D2Win_10057(gpGameList, szNumber, nRow, 1);
        }
    }

    if (bHaveSel)
    {
        for (int i = 0; i < gnLastGameCount; ++i)
        {
            if (!strcmp(szSel, gaGames[i].szName))
            {
                sub_004FB9D0_Select(gpGameList, i);
                break;
            }
        }
        D2Win_10053(gpGameList, nTop);
    }
    else
    {
        D2Win_10053(gpGameList, 0);
    }
}

// 0x00442DD0
void __fastcall CHATDLG_SetPendingText(const char* szText, unsigned short wRequestId)
{
    strncpy(gszPendingText, szText, 0x100);
    gnPendingId = wRequestId;
}

// Kept noinline: CHATDLG_OnTick (0x441500) calls this out of line in the image; without it the compiler inlines it there.
// 0x00442E00
__declspec(noinline) void __cdecl CHATDLG_SendPendingText()
{
    if (gnPendingId != -1)
    {
        WINMAIN_SendMcpGameInfoRequest(gszPendingText, gnPendingId);
        gwOtherRequestId = gnPendingId;
        gnPendingId = -1;
    }
}

// 0x00442E30
static void CHATDLG_ShowGameInfo(int nIndex)
{
    if (!gpGameInfoText)
        return;

    D2LaunchGameRecStrc* pGame = &gaNewGames[nIndex];
    sub_004FB6A0_ClearText(gpGameInfoText);
    if (strlen(&pGame->szName[0x10]))
    {
        sub_004FCF80_SetTextA(gpGameInfoText, &pGame->szName[0x10]);
        sub_004FCF80_SetTextA(gpGameInfoText, &gszEmptyAssertText);
    }
    D2Win_10053(gpGameInfoText, 0);
    if (pGame->szName)
    {
        sub_004FFE10_SetTextA(gpJoinName, pGame->szName);
        CONTROL_SetFocusedEditBox(0);
    }
}

int __stdcall sub_004450D0_OnGameListEvent(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gpGameList@* 0x00798BC0
    const int nSelection = sub_004FB990_GetSelection(gpGameList);
    sub_004FB6A0_ClearText(gpGameInfoText);
    if (nSelection != -1)
    {
        if (pMsg->uMessage == 0x201)
        {
            const unsigned long dwTick = GetTickCount();
// build: symbol ?gnGameListLastSelection@* 0x0070EBDC
            if (nSelection == gnGameListLastSelection && dwTick - gdwGameListLastClickTick <= 500)
            {
                CHATDLG_JoinByName(0);
                return 0;
            }
            gnGameListLastSelection = nSelection;
            gdwGameListLastClickTick = dwTick;
        }

        if (MCPCONNECT_QueryAddress())
        {
            const Unicode* pText = sub_004FBB30_GetText(gpGameList);
            if (pText)
            {
                char szText[0x100];
                UNICODE_ToAscii(szText, pText, 0x100);
// build: symbol ?gwRequestId@* 0x0070CD60
                while (++gwRequestId == 0)
                {
                }
                CHATDLG_SetPendingText(szText, gwRequestId);
                EDITBOX_SetText(gpJoinName, pText);
                CONTROL_SetFocusedEditBox(0);
            }
        }
        else
        {
            CHATDLG_ShowGameInfo(nSelection);
        }
    }
    return 0;
}

// 0x00442EB0
void __fastcall CHATDLG_ShowGameDetails(D2GameDetailsStrc* pDetails)
{
    char szLine[0x100];

    if (!gpGameInfoText)
        return;

    sub_004FB6A0_ClearText(gpGameInfoText);
    if (strlen(pDetails->szDescription))
    {
        sub_004FCF80_SetTextA(gpGameInfoText, pDetails->szDescription);
        sub_004FCF80_SetTextA(gpGameInfoText, gszEmptyString_006CC837);
    }

    unsigned int nSecondsPerHour = 3600;
    unsigned int nSecondsPerMinute = 60;
    unsigned int dwElapsed = pDetails->dwElapsed;
    unsigned int nHours = dwElapsed / nSecondsPerHour;
    unsigned int nRest = dwElapsed % nSecondsPerHour;
    sprintf(szLine, "Elapsed Time: %d:%02d:%02d", nHours, nRest / 60, dwElapsed % nSecondsPerMinute);
    sub_004FCF80_SetTextA(gpGameInfoText, szLine);

    unsigned char nLevelDiff = pDetails->nLevelDiff;
    if (nLevelDiff < 100)
    {
        if (nLevelDiff)
        {
            int nDiff = nLevelDiff;
            int nLevel = pDetails->nLevel;
            int nMin = nLevel - nDiff;
            if (nMin <= 1)
                nMin = 1;
            int nMax = nDiff + nLevel;
            if (nMax >= 99)
                nMax = 99;
            sprintf(szLine, "Level %d to %d", nMin, nMax);
        }
        else
        {
            sprintf(szLine, "Level %d", pDetails->nLevel);
        }
        sub_004FCF80_SetTextA(gpGameInfoText, szLine);
    }

    if (pDetails->nMaxPlayers > 0 && pDetails->nMaxPlayers < 8)
    {
        sprintf(szLine, "Up to %d Players", pDetails->nMaxPlayers);
        sub_004FCF80_SetTextA(gpGameInfoText, szLine);
    }

    sub_004FCF80_SetTextA(gpGameInfoText, gszEmptyString_006CC837);

    for (int i = 0; i < pDetails->nPlayers; ++i)
    {
        if (pDetails->szNames[i][0])
        {
            sub_004FCF80_SetTextA(gpGameInfoText, pDetails->szNames[i]);
            switch (pDetails->wClass[i])
            {
            case 0:
                sprintf(szLine, "Level %d Amazon", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 1:
                sprintf(szLine, "Level %d Sorceress", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 2:
                sprintf(szLine, "Level %d Necromancer", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 3:
                sprintf(szLine, "Level %d Paladin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 4:
                sprintf(szLine, "Level %d Barbarian", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 5:
                sprintf(szLine, "Level %d Druid", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            case 6:
                sprintf(szLine, "Level %d Assassin", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            default:
                sprintf(szLine, "Level %d", pDetails->wLevel[i]);
                D2Win_10046(gpGameInfoText, szLine, 5);
                break;
            }
        }
    }

    D2Win_10053(gpGameInfoText, 0);
}

// 0x00443130
void __cdecl CHATDLG_DestroyJoinControls()
{
    sub_004F95C0_ControlDestroy(&gpJoinGameBckgImage);
    sub_004F95C0_ControlDestroy(&gpJoinName);
    sub_004F95C0_ControlDestroy(&gpJoinPassword);
    sub_004F95C0_ControlDestroy(&gpGameList);
    sub_004F95C0_ControlDestroy(&gpControl_00798BC4);
    sub_004F95C0_ControlDestroy(&gpJoinButton);
    sub_004F95C0_ControlDestroy(&gpControl_00798BD0);
    sub_004F95C0_ControlDestroy(&gpJoinGameTitle);
    sub_004F95C0_ControlDestroy(&gpJoinNameLabel);
    sub_004F95C0_ControlDestroy(&gpJoinPasswordLabel);
    sub_004F95C0_ControlDestroy(&gpControl_00798BE8);
    sub_004FA450_SetActive(gapChatDlgControls[CHATINIT_QUITBUTTON]);
}


// 0x004431B0
void __cdecl MAINMENUS_LoadMaxPlayers()
{
    unsigned long nValue = 4;
    if (!SRegLoadValue("Diablo II", "MAX_PLAYER", 0, &nValue))
        SRegSaveValue("Diablo II", "MAX_PLAYER", 0, nValue);
    char szText[2] = "4";
    int nPlayers = nValue;
    if (nPlayers < 9 && nPlayers > 0)
    {
// build: symbol ?gszFormatD@* 0x006D57BC
        sprintf(szText, gszFormatD, nPlayers);
        sub_004FFE10_SetTextA(gpMaxPlayerControl, szText);
    }
}

// 0x00443220
void __cdecl CHATDLG_DestroyCreateControls()
{
    sub_004F95C0_ControlDestroy(&gpPanelBackground);
    sub_004F95C0_ControlDestroy(&gpPanelTitle);
    sub_004F95C0_ControlDestroy(&gpPanelText);
    sub_004F95C0_ControlDestroy(&gpCreatePasswordLabel);
    sub_004F95C0_ControlDestroy(&gpCreateDescLabel);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersLabel);
    sub_004F95C0_ControlDestroy(&gpLevelDiffLabel);
    sub_004F95C0_ControlDestroy(&gpControl_00798C08);
    sub_004F95C0_ControlDestroy(&gpCreateName);
    sub_004F95C0_ControlDestroy(&gpCreatePassword);
    sub_004F95C0_ControlDestroy(&gpCreateDesc);
    sub_004F95C0_ControlDestroy(&gpMaxPlayerControl);
    sub_004F95C0_ControlDestroy(&gpLevelDiffEdit);
    sub_004F95C0_ControlDestroy(&gpCreateButton);
    sub_004F95C0_ControlDestroy(&gpPanelCancelButton);
    sub_004F95C0_ControlDestroy(&gpLevelDiffCheck);
    sub_004F95C0_ControlDestroy(&gpNormalRadio);
    sub_004F95C0_ControlDestroy(&gpNightmareRadio);
    sub_004F95C0_ControlDestroy(&gpHellRadio);
    sub_004F95C0_ControlDestroy(&gpNormalLabel);
    sub_004F95C0_ControlDestroy(&gpNightmareLabel);
    sub_004F95C0_ControlDestroy(&gpHellLabel);
    sub_004F95C0_ControlDestroy(&gpLevelDiffBoxImage);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersUpButton);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersDownButton);
    sub_004F95C0_ControlDestroy(&gpLevelDiffUpButton);
    sub_004F95C0_ControlDestroy(&gpLevelDiffDownButton);
    sub_004F95C0_ControlDestroy(&gpLevelDiffGreyArrows);
    sub_004F95C0_ControlDestroy(&gpMaxPlayersBoxImage);
    sub_004F95C0_ControlDestroy(&gpControl_00798C10);
    sub_004FA450_SetActive(gapChatDlgControls[CHATINIT_QUITBUTTON]);
    sub_0043D990();
}



// build: symbol ?gnChatLaunchMode@* 0x0077BBE4
// build: symbol ?gpLaunchFuncs@* 0x0077B09C
// build: symbol ?gnHistoryIndex@* 0x0070CD74
// build: symbol ?gpChatEdit@* 0x0077BD94

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB

extern D2WinControlStrc* gpEditBox_00798C3C; // 0x00798C3C

// 0x00443360
int __cdecl CHATDLG_GetMaxPlayers()
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl);
    UNICODE_ToUtf8(szText, pText, 5);
    return atoi(szText);
}

// 0x00443390
int __cdecl CHATDLG_GetLevelRange()
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    UNICODE_ToUtf8(szText, pText, 5);
    return atoi(szText);
}

// 0x004433C0
int __stdcall CHATDLG_IncrementMaxPlayers(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl);
    UNICODE_ToUtf8(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue < 8)
        ++nValue;
// build: symbol ?gszFormatD@* 0x006D57BC
    sprintf(gszMaxPlayersText, gszFormatD, nValue);
    sub_004FFE10_SetTextA(gpMaxPlayerControl, gszMaxPlayersText);
    return 1;
}

// 0x00443420
int __stdcall CHATDLG_DecrementMaxPlayers(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpMaxPlayerControl);
    UNICODE_ToUtf8(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue > 1)
        --nValue;
    sprintf(gszMaxPlayersText, gszFormatD, nValue);
    sub_004FFE10_SetTextA(gpMaxPlayerControl, gszMaxPlayersText);
    return 1;
}

// 0x00443480
int __stdcall CHATDLG_IncrementLevelRange(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    UNICODE_ToUtf8(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue < 0x63)
        ++nValue;
    sprintf(gszLevelDiffText, gszFormatD, nValue);
    sub_004FFE10_SetTextA(gpEditBox_00798C3C, gszLevelDiffText);
    return 1;
}

// 0x004434E0
int __stdcall CHATDLG_DecrementLevelRange(int nArg)
{
    char szText[5];
    const Unicode* pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
    UNICODE_ToUtf8(szText, pText, 5);
    int nValue = atoi(szText);
    if (nValue > 0)
        --nValue;
    sprintf(gszLevelDiffText, gszFormatD, nValue);
    sub_004FFE10_SetTextA(gpEditBox_00798C3C, gszLevelDiffText);
    return 1;
}

// 0x00443540
int __stdcall CHATDLG_IsNameChar(D2WinControlStrc* pControl, int nArg, const char* pChar)
{
    switch (*pChar)
    {
    case ' ':
    case '\'':
    case '-':
    case '_':
        return 1;
    }
    if (*pChar >= '0' && *pChar <= '9')
        return 1;
    if (*pChar >= 'A' && *pChar <= 'Z')
        return 1;
    if (*pChar >= 'a' && *pChar <= 'z')
        return 1;
    return 0;
}

// 0x004435D0
int __stdcall sub_004435D0_IsPrintableChar(void* unused1,void* unused2,const Character* text)
{
    return text->value>=FIRST_PRINTABLE && text->value<AFTER_PRINTABLE;
}

// 0x00443600
int __stdcall CHATDLG_IsPrintableChar(int nA, int nB, const char* pChar)
{
    const char nChar = *pChar;
    if (nChar >= 0x20 && nChar < 0x80)
        return 1;
    return 0;
}

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

D2WinControlStrc* gpCreateButton;                                                                  // 0x00798C28

extern D2WinControlStrc* gpCreateName;                                                             // 0x00798C2C

extern D2WinControlStrc* gpEditBox_00798C3C;                                                                // 0x00798C3C

// 0x00443630
void __cdecl CHATDLG_UpdateCreateButton()
{
    char szText[0x100];
    int bName = 0;
    int bPlayers = 0;
    int bLevel = 0;

    const Unicode* pText = sub_004FDD90_GetEditText(gpCreateName);
    if (pText)
    {
        UNICODE_ToAscii(szText, pText, 0x10);
        int nLen = strlen(szText);
        if (szText[0] != ' ' && nLen >= 1 && szText[nLen - 1] != ' ')
            bName = 1;
    }

    if (MCPCONNECT_QueryAddress())
    {
        pText = sub_004FDD90_GetEditText(gpMaxPlayerControl);
        if (pText)
        {
            UNICODE_ToAscii(szText, pText, 3);
            if (strlen(szText))
            {
                bPlayers = 1;
                int nPlayers = atoi(szText);
                if (nPlayers < 1 || nPlayers > 8)
                {
                    nPlayers = D2_MIN(D2_MAX(nPlayers, 1), 8);
// build: symbol ?gszFormatD@* 0x006D57BC
                    sprintf(szText, gszFormatD, nPlayers);
                    sub_004FFE10_SetTextA(gpMaxPlayerControl, szText);
                }
            }
        }

        if (sub_00500960_IsPressed(gpLevelDiffCheck))
        {
            pText = sub_004FDD90_GetEditText(gpEditBox_00798C3C);
            UNICODE_ToAscii(szText, pText, 3);
            if (strlen(szText) && atoi(szText) >= 0)
                bLevel = 1;
        }
        else
        {
            bLevel = 1;
        }
    }
    else
    {
        bPlayers = 1;
        bLevel = 1;
    }

    if (bName && bPlayers && bLevel)
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpCreateButton, 1);
    else
        CONTROL_SetEnabled(gpCreateButton, 0);
}

extern D2WinControlStrc* gpJoinButton; // 0x00798BCC

// 0x004437E0
void __cdecl CHATDLG_UpdateJoinButtonState()
{
    char szText[0x100];

    const Unicode* pText = sub_004FDD90_GetEditText(gpJoinName);
    int bEnable = 0;
    if (pText)
    {
        UNICODE_ToAscii(szText, pText, 0xFF);
        if (strlen(szText) >= 1)
            bEnable = 1;
    }
    CONTROL_SetEnabled(gpJoinButton, bEnable);
}

// 0x00443840
int __stdcall CHATDLG_CheckStartAdvResult(int nUnused)
{
    int nOut;
    if (gpLaunchFuncs->pfnGetCreateGameResult(&nOut))
        D2Win_StopMessageLoop();
    return 1;
}

int gfCreateGameCancelled;                                                                                     // 0x00798CC4

D2WinControlStrc* gpNormalRadio;                                                                       // 0x00798C4C

D2WinControlStrc* gpNightmareRadio;                                                                       // 0x00798C50

D2WinControlStrc* gpHellRadio;                                                                       // 0x00798C54

int gnDiffSelect;                                                                                  // 0x00798CD0

// 0x00443870
int __stdcall CHATDLG_SetCancel(int nArg)
{
    gfCreateGameCancelled = 1;
    return 1;
}

// 0x00443880
int __stdcall CHATDLG_PollMcp(int nArg)
{
    WINMAIN_PollMcpConnection();
// build: symbol ?GAME_GetConnectError@* 0x00449C00
// build: symbol ?GAME_GetMcpGameToken@* 0x00449BE0
// build: symbol ?GAME_IsMcpCreateQueued@* 0x00449E40
    if (GAME_IsMcpCreateQueued() || GAME_GetMcpGameToken() || GAME_GetConnectError() || gfCreateGameCancelled)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x004438C0
int __stdcall sub_004438C0_OnCancel(int nArg)
{
    CHATDLG_ResetControls();
// build: symbol ?CHARSEL_CancelGameCreate@* 0x0043F850
    CHARSEL_CancelGameCreate();
    CHATDLG_DestroyCreateControls();
    return 1;
}

static inline int sub_004438E0_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

// 0x004438E0
int __fastcall CHATDLG_Lookup(const char* szName, const char* szPassword, D2LaunchGameRecStrc* pRecord)
{
    int nFilterA = 0;
    int nFilterB = 0;
    if ((gpCharInfo->wFlags1EF) & 4)
    {
        nFilterA = 4;
        nFilterB = 4;
    }
    if ((gpCharInfo->wFlags1EF) & 0x20)
    {
        nFilterA |= 8;
        nFilterB |= 8;
    }
    if (!sub_004438E0_HasProgress(gpCharInfo->wFlags1EF, 0x800, 0xA00))
    {
        if (sub_004438E0_HasProgress(gpCharInfo->wFlags1EF, 0x400, 0x500))
            nFilterB |= 2;
        else
            nFilterB |= 3;
    }

    const char* p = (const char*)gpLaunchFuncs->pfQueryGames(szName, szPassword, nFilterA, nFilterB);
    if (p)
    {
        const int nCount = *(const int*)p;
        if (nCount >= 1)
        {
            p += 0x10;
            *(unsigned short*)pRecord->wValue0x33 = 1;
            *(int*)pRecord->nAddress0x37 = *(const int*)p;
            p += 0x14;
            strcpy(pRecord->szName, p);
            p = CHATDLG_SkipString(p);
            p = CHATDLG_SkipString(p);
            if (!CHATDLG_IsCharOverLimit((const unsigned char*)p))
            {
                strcpy(pRecord->szDesc, p);
                CHATDLG_SkipString(p);
                return nCount;
            }
        }
    }

    return 0;
}



extern D2WinControlStrc* gpJoinPassword; // 0x00798BD8

// 0x004439F0
int __stdcall CHATDLG_JoinByName(int nArg)
{
    char szPassword[0x100];
    char szName[0x100];
    D2LaunchGameRecStrc tRecord;

    if (!sub_004F9710_TestFlag(gpJoinButton))
        return 0;

    const Unicode* pName = sub_004FDD90_GetEditText(gpJoinName);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpJoinPassword);
    if (pName)
    {
        UNICODE_ToAscii(szName, pName, 0x100);
        UNICODE_ToAscii(szPassword, pPassword, 0x100);
        sub_00411320_CapitalizeWords(szName);
        sub_00411320_CapitalizeWords(szPassword);

        if (MCPCONNECT_QueryAddress())
        {
            CHATDLG_SetupCharacter(0, szName, szPassword, 0);
// build: symbol ?CHATDLG_DestroyJoinControls@* 0x00443130
            CHATDLG_DestroyJoinControls();
            CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
            return 1;
        }

        for (int i = 0; i < gnGameCount; ++i)
        {
            if (!strcmp(gaGames[i].szName, szName))
            {
                CHATDLG_SetupCharacter(*(unsigned short*)gaGames[i].wValue0x33, szName, szPassword, FOG_inet_ntoa(*(int*)gaGames[i].nAddress0x37));
                CHATDLG_DestroyJoinControls();
                CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
                return 1;
            }
        }

        if (CHATDLG_Lookup(szName, szPassword, &tRecord))
        {
            if (!strcmp(tRecord.szName, szName))
            {
                CHATDLG_SetupCharacter(*(unsigned short*)tRecord.wValue0x33, szName, szPassword, FOG_inet_ntoa(*(int*)tRecord.nAddress0x37));
                CHATDLG_DestroyJoinControls();
                CHATDLG_ShowTimedMessage(D2LANG_GetStringFromTblIndex(0x147B), 0);
                return 1;
            }
        }
        else
        {
            CHATDLG_ShowError(D2LANG_GetStringFromTblIndex(0x1411), 0);
        }
    }

    return 0;
}

// build: symbol ?gszFormatD@* 0x006D57BC

// 0x00443C10
int __stdcall sub_00443C10_AlwaysOne(int nArg)
{
    return 1;
}

// 0x00443C20
int __stdcall CHATDLG_SelectNormal(int nArg)
{
    BUTTON_SetIsPressed(gpNormalRadio, 1);
    BUTTON_SetIsPressed(gpNightmareRadio, 0);
    BUTTON_SetIsPressed(gpHellRadio, 0);
    gnDiffSelect = 0;
    gpCharInfo->nByte210 = 0;
    return 1;
}

// 0x00443C70
int __stdcall CHATDLG_SelectNightmare(int nArg)
{
    BUTTON_SetIsPressed(gpNormalRadio, 0);
    BUTTON_SetIsPressed(gpNightmareRadio, 1);
    BUTTON_SetIsPressed(gpHellRadio, 0);
    gpCharInfo->nByte210 = 1;
    gnDiffSelect = 1;
    return 1;
}

// 0x00443CC0
int __stdcall CHATDLG_SelectHell(int nArg)
{
    BUTTON_SetIsPressed(gpNormalRadio, 0);
    BUTTON_SetIsPressed(gpNightmareRadio, 0);
    BUTTON_SetIsPressed(gpHellRadio, 1);
    gnDiffSelect = 2;
    gpCharInfo->nByte210 = 2;
    return 1;
}

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

extern int gbCheck; // 0x0077BD58

extern D2WinControlStrc* gpControl_00798C74; // 0x00798C74

extern D2WinControlStrc* gpSubmitEditA; // 0x00798C80

extern D2WinControlStrc* gpSubmitEditB; // 0x00798C84

extern D2WinControlStrc* gpSubmitEditC; // 0x00798C88

extern D2WinControlStrc* gpSubmitButton; // 0x00798CA0

extern D2WinControlStrc* gpSelectButton; // 0x00798CA4

void __fastcall CHATDLG_ShowProfileDialog(const char*,int,int); // 0x00445A80

void __fastcall CHATDLG_ShowUserInfoDialog(const char*,const char*,int,int); // 0x00445C70


// build: symbol ?gbCharSelBusy@* 0x00779DA0
// build: symbol ?gpCharList@* 0x00779DBC
// build: symbol ?FOG_IsExpansion@* 0x00408F20
// build: symbol ?MAINMENUS_DestroyControls@* 0x0042F3F0
// build: symbol ?MAINMENUS_JoinGame@* 0x00434A00

// 0x00443D10
static void __stdcall CHATDLG_SetPendingName(int nA, int nB, const char* szText)
{
    strcpy(gszPendingEntryName, szText);
    gnPendingValueA = nA;
    gnPendingValueB = nB;
}

// 0x00443D50
void __cdecl CHATDLG_CreateProfileControls()
{
    gpControl_00798C90 = CONTROL_Create(&gtControlInit_0070E860);
    D2Win_10044(gpControl_00798C90, D2LANG_GetStringFromTblIndex(0x1493));
    gpControl_00798C94 = CONTROL_Create(&gtControlInit_0070E890);
    D2Win_10044(gpControl_00798C94, D2LANG_GetStringFromTblIndex(0x1494));
    gpControl_00798C98 = CONTROL_Create(&gtControlInit_0070E8C0);
    D2Win_10044(gpControl_00798C98, D2LANG_GetStringFromTblIndex(0x1496));
    gpControl_00798C9C = CONTROL_Create(&gtControlInit_0070E8F0);
    D2Win_10044(gpControl_00798C9C, D2LANG_GetStringFromTblIndex(0x1497));
    gpControl_00798CA8 = CONTROL_Create(&gtControlInit_0070E9B0);
    D2Win_10044(gpControl_00798CA8, D2LANG_GetStringFromTblIndex(0x1492));
}

// 0x00443E10
void __cdecl CHATDLG_DestroyProfileControls()
{
    if (gnSubmitMode)
    {
        if (gnSubmitMode == 1)
        {
            sub_004F95C0_ControlDestroy(&gpProfileViewBckg);
            sub_004F95C0_ControlDestroy(&gpControl_00798C68);
            sub_004F95C0_ControlDestroy(&gpControl_00798C6C);
            sub_004F95C0_ControlDestroy(&gpControl_00798C70);
            sub_004F95C0_ControlDestroy(&gpControl_00798C74);
        }
        else
        {
            sub_004F95C0_ControlDestroy(&gpProfileEditBckg);
            sub_004F95C0_ControlDestroy(&gpControl_00798C7C);
            sub_004F95C0_ControlDestroy(&gpSubmitEditA);
            sub_004F95C0_ControlDestroy(&gpSubmitEditB);
            sub_004F95C0_ControlDestroy(&gpSubmitEditC);
            sub_004F95C0_ControlDestroy(&gpRefreshButton);
        }
        gnSubmitMode = 0;
        sub_004F95C0_ControlDestroy(&gpControl_00798C90);
        sub_004F95C0_ControlDestroy(&gpControl_00798C94);
        sub_004F95C0_ControlDestroy(&gpControl_00798C98);
        sub_004F95C0_ControlDestroy(&gpControl_00798C9C);
        sub_004F95C0_ControlDestroy(&gpSubmitButton);
        sub_004F95C0_ControlDestroy(&gpSelectButton);
        sub_004F95C0_ControlDestroy(&gpControl_00798CA8);
    }
    sub_004FA450_SetActive(gapChatDlgControls[CHATINIT_QUITBUTTON]);
    sub_0043D990();
}

// 0x00443EF0
int __stdcall CHATDLG_OnLadderSelect(int nArg)
{
    CHATDLG_DestroyProfileControls();
    if (gnPendingValueB)
    {
        if (gnPendingValueA)
            CHATDLG_OpenExpansionHardcoreLadder();
        else
            CHATDLG_OpenExpansionLadder();
    }
    else
    {
        if (gnPendingValueA)
            CHATDLG_OpenHardcoreLadder();
        else
            CHATDLG_OpenStandardLadder();
    }
    CHATDLG_SelectEntry(gszPendingEntryName, gnPendingValueA, gnPendingValueB);
    return 1;
}

// Kept noinline: CHATDLG_FillLadderList (0x4403F0) calls this out of line in the image; without it the compiler inlines it there.
// 0x00443F50
__declspec(noinline) void __fastcall CHATDLG_CopyName(char* szDest)
{
    SStrCopy(szDest, gszPendingEntryName, 0x7FFFFFFF);
}

// 0x00443F70
int __stdcall CHATDLG_OnRefresh(int nArg)
{
    CHATDLG_DestroyProfileControls();
    return 1;
}

extern D2WinControlInitStrc gtHelpBckgImageInit; // 0x0070E9E0

extern D2WinControlInitStrc gtControlInit_0070EA10; // 0x0070EA10

extern D2WinControlInitStrc gtControlInit_0070EA40; // 0x0070EA40

extern D2WinControlInitStrc gtControlInit_0070EA70; // 0x0070EA70

#pragma pack(push, 1)

struct D2GameListRecordStrc
{
    char szName[0x10];
    char szDesc[0x22];
    unsigned short wType;
    char unk0x34[2];
    unsigned int f_36;
    char unk0x3A;
};

#pragma pack(pop)

extern D2GameListRecordStrc gtGameList_0077BDC9[]; // 0x0077BDC9

void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FB9D0


D2WinControlStrc* gpControl_00798CB0; // 0x00798CB0

D2WinControlStrc* gpControl_00798CB4; // 0x00798CB4

D2WinControlStrc* gpControl_00798CB8; // 0x00798CB8

D2WinControlStrc* gpHelpBckgImage; // 0x00798CBC

int gfGameListControlsCreated; // 0x00798CC0

int gnGameCount; // 0x00798CCC

static inline int sub_00444E70_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

static inline char* sub_00444E70_NextString(char* p)
{
    D2_ASSERT(p, 0xAD);
    while (*p)
        ++p;
    return p + 1;
}

// build: symbol ?gnChatLaunchMode@* 0x0077BBE4
// build: symbol ?gpLaunchFuncs@* 0x0077B09C
// build: symbol ?gnHistoryIndex@* 0x0070CD74
// build: symbol ?gpChatEdit@* 0x0077BD94

// build: symbol ?gszFormatD@* 0x006D57BC

// build: symbol ?CHATDLG_DestroyJoinControls@* 0x00443130

// 0x00443F80
int __stdcall CHARSEL_SubmitProfile(int nArg)
{
    if (gnSubmitMode == 2)
    {
        char szA[0x8 + 1];
        char szB[0x28 + 1];
        char szC[0xC8 + 1];

        const Unicode* pTextA = sub_004FDD90_GetEditText(gpSubmitEditA);
        const Unicode* pTextB = sub_004FDD90_GetEditText(gpSubmitEditB);
        const Unicode* pTextC = sub_004FDD90_GetEditText(gpSubmitEditC);
// build: symbol ?gpCharInfo@* 0x0077BBD8
        char* szName = gpCharInfo->szAccount;
        UNICODE_ToAscii(szA, pTextA, 0x8);
        UNICODE_ToAscii(szB, pTextB, 0x28);
        UNICODE_ToAscii(szC, pTextC, 0xC8);
        if (!CHATDLG_WriteUserData((int)szName, (int)szA, (int)szB, (int)szC))
            return 1;
    }

// build: symbol ?CHATDLG_DestroyProfileControls@* 0x00443E10
    CHATDLG_DestroyProfileControls();
    return 1;
}

// 0x00444020
int __cdecl sub_00444020_CreateControls()
{
// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
    CHATDLG_ResetLaunchState();
// build: symbol ?GAME_IsLaunchExpansion@* 0x0043DB10
    int bExpansion = GAME_IsLaunchExpansion();
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    gpHelpBckgImage = CONTROL_Create(&gtHelpBckgImageInit);
    gpControl_00798CB0 = CONTROL_Create(&gtControlInit_0070EA10);
    D2Win_10044(gpControl_00798CB0, D2LANG_GetStringFromTblIndex(bExpansion ? 0x14BC : 0x2AE));
    gpControl_00798CB4 = CONTROL_Create(&gtControlInit_0070EA40);
    if (!bExpansion)
    {
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2AF));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B0));
// build: symbol ?gszSpace@* 0x006FFC44
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B1));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B2));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B3));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B4));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B5));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B6));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B7));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B8));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B34));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B9));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BA));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BB));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B35));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BD));
        D2Win_10046(gpControl_00798CB4, gszSpace, bExpansion);
    }
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BE));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2BF));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C0));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C1));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C2));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C3));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C4));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C5));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C6));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C7));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C8));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2C9));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CA));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CB));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CC));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CD));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CE));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2CF));
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D0));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D1));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D2));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x276C));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x276D));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D3));
    D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    if (!bExpansion)
    {
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2D4));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B26));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B27));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B28));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2714));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2715));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DA));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B21));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B22));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DB));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DC));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2716));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2717));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2DF));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2718));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2719));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E2));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E3));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E4));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E5));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E6));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E7));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E8));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2E9));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EA));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271A));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EC));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2ED));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2EE));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271B));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F0));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271C));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F2));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F3));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F4));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271D));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271E));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F7));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F8));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2F9));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FA));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FB));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FC));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FD));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FE));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2FF));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x300));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x301));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x271F));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x303));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x304));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x305));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x306));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x307));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x2B23));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x309));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30A));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30B));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30C));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30D));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30E));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x30F));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x310));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x311));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x312));
        D2Win_10044(gpControl_00798CB4, D2LANG_GetStringFromTblIndex(0x313));
        D2Win_10046(gpControl_00798CB4, gszSpace, 0);
    }
    gpControl_00798CB8 = CONTROL_Create(&gtControlInit_0070EA70);
    sub_004FA450_SetActive(gpControl_00798CB8);
    gfGameListControlsCreated = 1;
    D2Win_10053(gpControl_00798CB4, 0);
    return 1;
}

// Kept noinline: CHATDLG_OnProfileClose (0x43F720), CHATDLG_ResetLaunchState (0x43F8C0) call this out of line in the image; without it the compiler inlines it there.
// 0x00444E20
__declspec(noinline) int __cdecl CHATDLG_DestroyGameListControls()
{
    sub_004F95C0_ControlDestroy(&gpHelpBckgImage);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB0);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB4);
    sub_004F95C0_ControlDestroy(&gpControl_00798CB8);
    gfGameListControlsCreated = 0;
    sub_004FA450_SetActive(gapChatDlgControls[CHATINIT_QUITBUTTON]);
    return 1;
}

// 0x00444E70
void __cdecl CHATDLG_FillGameList()
{
    int nFlags = 0;
    int nDifficulties = 0;
    if ((gpCharInfo->wFlags1EF) & 4)
    {
        nFlags = 4;
        nDifficulties = 4;
    }
    if ((gpCharInfo->wFlags1EF) & 0x20)
    {
        nFlags |= 8;
        nDifficulties |= 8;
    }
    if (!sub_00444E70_HasProgress(gpCharInfo->wFlags1EF, 0x800, 0xA00))
    {
        if (sub_00444E70_HasProgress(gpCharInfo->wFlags1EF, 0x400, 0x500))
            nDifficulties |= 2;
        else
            nDifficulties |= 3;
    }

    char* p = (char*)gpLaunchFuncs->pfQueryGames(0, 0, nFlags, nDifficulties);
    if (p)
    {
        gnGameCount = *(int*)p;
        p += 4;
        int i = 0;
        while (i < gnGameCount)
        {
            p += 0xC;
            gtGameList_0077BDC9[i].wType = 1;
            gtGameList_0077BDC9[i].f_36 = *(unsigned int*)p;
            p += 0x14;
            strcpy(gtGameList_0077BDC9[i].szName, p);
// build: symbol ?gpGameList@* 0x00798BC0
            if (gpGameList)
                sub_004FCF80_SetTextA(gpGameList, p);
            p = sub_00444E70_NextString(p);
            p = sub_00444E70_NextString(p);
            if (CHATDLG_IsCharOverLimit((const unsigned char*)p))
            {
                --gnGameCount;
            }
            else
            {
                strcpy(gtGameList_0077BDC9[i].szDesc, p + 1);
                ++i;
            }
            p = sub_00444E70_NextString(p);
        }
    }

// build: symbol ?CHATDLG_FillGameListControl@* 0x00442C20
    CHATDLG_FillGameListControl();
}

// 0x004450A0
int __stdcall CHATDLG_JoinNameKey(D2WinControlStrc* pControl, int nArg, const char* pChar)
{
    D2Win_10050_TEXTBOX_SetLine((D2WinTextBoxStrc*)gpGameList, -1);
    return CHATDLG_IsNameChar(pControl, nArg, pChar);
}

// 0x004450C0
int __stdcall CHATDLG_JoinNameEnter(int nArg)
{
// build: symbol ?CHATDLG_UpdateJoinButtonState@* 0x004437E0
    CHATDLG_UpdateJoinButtonState();
    return 1;
}

// 0x004451C0
void __cdecl CHATDLG_UpdateLevelControls()
{
    if (sub_00500960_IsPressed(gpLevelDiffCheck))
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 0);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 0);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 1);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 1);
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpLevelDiffEdit, 1);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 1);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 1);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 4, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 4, 0, 0);
    }
    else
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 1);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 0);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 0);
        CONTROL_SetEnabled(gpLevelDiffEdit, 0);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 0);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 0);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
    }
    CHATDLG_UpdateCreateButton();
}

int __fastcall D2Win_10076(D2WinEditBoxStrc* pEditBox, const char* szText); // 0x004FFE10

extern const char gszFormatInt_006D57BC[]; // 0x006D57BC

D2WinControlStrc* gpLevelDiffCheck; // 0x00798C40

// 0x00445300
void __cdecl CHATDLG_LoadLevelRestriction()
{
    unsigned long nValue = 4;
    if (!SRegLoadValue("Diablo II", "LVL_REST", 0, &nValue))
    {
        SRegSaveValue("Diablo II", "LVL_REST", 0, nValue);
        return;
    }
    char szText[4] = "4";
    if (nValue == 666)
    {
        BUTTON_SetIsPressed((D2WinControlStrc*)gpLevelDiffCheck, 0);
        CHATDLG_UpdateLevelControls();
        return;
    }
    SStrPrintf(szText, 4, gszFormatInt_006D57BC, nValue);
    D2Win_10076((D2WinEditBoxStrc*)gpEditBox_00798C3C, szText);
    BUTTON_SetIsPressed((D2WinControlStrc*)gpLevelDiffCheck, 1);
    CHATDLG_UpdateLevelControls();
}

int __cdecl GAME_GetMcpCharLevel(); // 0x00449E20

extern D2WinControlInitStrc gtPanelTitleInit; // 0x0070EAA0

extern D2WinControlInitStrc gtPanelTextInit; // 0x0070EAD0

extern D2WinControlInitStrc gtPanelCancelButtonInit; // 0x0070EB30

extern D2WinControlInitStrc gtResetBuildPanelTimerInit; // 0x0070EB60

extern D2WinControlStrc* gpPanelBackground; // 0x00798BEC

extern D2WinControlStrc* gpPanelTitle; // 0x00798BF0

extern D2WinControlStrc* gpPanelText; // 0x00798BF4

extern D2WinControlStrc* gpPanelCancelButton; // 0x00798C48

// 0x004453B0
void __cdecl COMCALLBACK_BuildCreateGamePanel()
{
    char szNumber[4];
    char szLevel[100];

    gpPanelBackground = CONTROL_Create(&gtBlankBckgImageInit);
    gpPanelTitle = CONTROL_Create(&gtPanelTitleInit);
    D2Win_10044(gpPanelTitle, D2LANG_GetStringFromTblIndex(0x141E));
    gpPanelText = CONTROL_Create(&gtPanelTextInit);
    D2Win_10044(gpPanelText, D2LANG_GetStringFromTblIndex(0x2B0F));
// build: symbol ?gszSpace@* 0x006FFC44
    sub_004FCFF0_SetTextA(gpPanelText, gszSpace, 0);

    Unicode wszText[0xC8];
    Unicode wszLevel[0x64];

    sprintf(szLevel, "%d ", GAME_GetMcpCharLevel());
    sub_00526320_ToUnicode(wszLevel, szLevel, 0x32);
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x2B12));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9A));
    Unicode wszNumber[3];
// build: symbol ?gszFormatD@* 0x006D57BC
    wsprintfA(szNumber, gszFormatD, 0);
    sub_00526F20_ToUnicode(wszNumber, szNumber, 2);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszLevel);
    D2Win_10044(gpPanelText, wszText);

    gpPanelCancelButton = CONTROL_Create(&gtPanelCancelButtonInit);
    sub_004FA450_SetActive(gpPanelCancelButton);
    gpCreateButton = CONTROL_Create(&gtResetBuildPanelTimerInit);
    CHATDLG_SetMainControlState(0);
}

// 0x00445530
int __stdcall CHATDLG_ResetBuildPanel(int nArg)
{
    CHATDLG_ResetLaunchState();
    COMCALLBACK_BuildCreateGamePanel();
    return 1;
}

// 0x00445550
int __stdcall CHATDLG_OnLevelRestrictToggle(int nArg)
{
    if (sub_00500960_IsPressed(gpLevelDiffCheck))
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 0);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 0);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 1);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 1);
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpLevelDiffEdit, 1);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 1);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 1);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 4, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 4, 0, 0);
    }
    else
    {
        sub_004F9740_SetControlState(gpLevelDiffBoxImage, 1);
        sub_004F9740_SetControlState(gpLevelDiffGreyArrows, 1);
        sub_004F9740_SetControlState(gpLevelDiffUpButton, 0);
        sub_004F9740_SetControlState(gpLevelDiffDownButton, 0);
        CONTROL_SetEnabled(gpLevelDiffEdit, 0);
        CONTROL_SetEnabled(gpLevelDiffUpButton, 0);
        CONTROL_SetEnabled(gpLevelDiffDownButton, 0);
        sub_004FC9B0_SetText(gpLevelDiffLabel, D2LANG_GetStringFromTblIndex(0x148B), 5, 0, 0);
        sub_004FC9B0_SetText(gpControl_00798C08, D2LANG_GetStringFromTblIndex(0x148C), 5, 0, 0);
    }
    CHATDLG_UpdateCreateButton();
    return 1;
}

// 0x004456A0
int __stdcall sub_004456A0_OnEnter(int nArg)
{
    CHATDLG_UpdateCreateButton();
    return 1;
}

// 0x004456B0
int __stdcall sub_004456B0_OnEnter(int nArg)
{
    CHATDLG_UpdateCreateButton();
    return 1;
}

// 0x004456C0
int __stdcall sub_004456C0_OnEnter(int nArg)
{
    CHATDLG_UpdateCreateButton();
    return 1;
}

// 0x00445A80
void __fastcall CHATDLG_ShowProfileDialog(const char* szText, int nA, int nB)
{
    const char* szName = gpCharInfo->szAccount;
    char szA[12];
    char szB[44];
    char szC[204];

    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    if (!MAINMENUS_RequestProfile((int)szName, (int)szA, (int)szB, (int)szC))
    {
        return;
    }

// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
    CHATDLG_ResetLaunchState();
    gnSubmitMode = 2;
    gpProfileEditBckg = CONTROL_Create(&gtProfileEditBckgInit);
    gpControl_00798C7C = CONTROL_Create(&gtControlInit_0070E6B0);
    sub_004FCF80_SetTextA(gpControl_00798C7C, szName);
    gpSubmitEditA = CONTROL_Create(&gtSubmitEditAInit);
    sub_004FFE10_SetTextA(gpSubmitEditA, szA);
    sub_004FDD50_SetMaxLength(gpSubmitEditA, 8);
    gpSubmitEditB = CONTROL_Create(&gtSubmitEditBInit);
    sub_004FFE10_SetTextA(gpSubmitEditB, szB);
    sub_004FDD50_SetMaxLength(gpSubmitEditB, 0x28);
    gpSubmitEditC = CONTROL_Create(&gtSubmitEditCInit);
    sub_004FFE10_SetTextA(gpSubmitEditC, szC);
    sub_004FDD50_SetMaxLength(gpSubmitEditC, 0xC8);
    gpRefreshButton = CONTROL_Create(&gtRefreshButtonInit);
    sub_004FA450_SetActive(gpRefreshButton);
    gpSubmitButton = CONTROL_Create(&gtSubmitButtonInit);
    if (!gbCheck)
    {
        gpSelectButton = CONTROL_Create(&gtSelectButtonInit);
    }
    CHATDLG_CreateProfileControls();
    sub_004FDDD0_LinkTab(gpSubmitEditC, gpSubmitEditA);
    sub_004FDDD0_LinkTab(gpSubmitEditA, gpSubmitEditB);
    sub_004FDDD0_LinkTab(gpSubmitEditB, gpSubmitEditC);
    if (!szA[0] && !szB[0] && !szC[0])
    {
        CONTROL_SetFocusedEditBox(gpSubmitEditA);
    }
    else
    {
        CONTROL_SetFocusedEditBox(gpSubmitEditC);
        D2Win_10082(gpSubmitEditC);
    }
    CHATDLG_SetPendingName(nA, nB, szText);
}

// 0x00445C70
void __fastcall CHATDLG_ShowUserInfoDialog(const char* szUser, const char* szText, int nA, int nB)
{
    const char* szName = COMCALLBACK_SkipNamePrefix(szUser);
    char szA[12];
    char szB[44];
    char szC[204];

    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_7], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CREATESCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_JOINSCREENBUTTON], 0);
    BUTTON_SetIsPressed(gapChatDlgControls[CHATINIT_CONTROL_C], 0);
    if (!MAINMENUS_RequestProfile((int)szName, (int)szA, (int)szB, (int)szC))
    {
        return;
    }

    CHATDLG_ResetLaunchState();
    gnSubmitMode = 1;
    gpProfileViewBckg = CONTROL_Create(&gtProfileViewBckgInit);
    gpControl_00798C68 = CONTROL_Create(&gtControlInit_0070E7A0);
    sub_004FCF80_SetTextA(gpControl_00798C68, szName);
    gpControl_00798C6C = CONTROL_Create(&gtControlInit_0070E7D0);
    sub_004FCF80_SetTextA(gpControl_00798C6C, szA);
    gpControl_00798C70 = CONTROL_Create(&gtControlInit_0070E800);
    sub_004FCF80_SetTextA(gpControl_00798C70, szB);
    gpControl_00798C74 = CONTROL_Create(&gtControlInit_0070E830);
    char szDelim[] = "\r\n";
    char* szLine = strtok(szC, szDelim);
    while (szLine)
    {
        sub_004FCF80_SetTextA(gpControl_00798C74, szLine);
        szLine = strtok(0, szDelim);
    }
    gpSubmitButton = CONTROL_Create(&gtSubmitButtonInit);
    sub_004FA450_SetActive(gpSubmitButton);
    if (!gbCheck)
    {
        gpSelectButton = CONTROL_Create(&gtSelectButtonInit);
    }
    CHATDLG_CreateProfileControls();
    sub_0043D990();
    CHATDLG_SetPendingName(nA, nB, szText);
}


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

extern D2WinControlStrc* gpJoinName; // 0x00798BD4

extern D2WinControlStrc* gpJoinPassword; // 0x00798BD8

extern D2WinControlStrc* gpJoinGameTitle; // 0x00798BDC

extern D2WinControlStrc* gpJoinNameLabel; // 0x00798BE0

extern D2WinControlStrc* gpJoinPasswordLabel; // 0x00798BE4

extern D2WinControlStrc* gpControl_00798BE8; // 0x00798BE8

extern unsigned long gdwLastRefresh; // 0x00798CF0

// 0x00445DF0
void __cdecl CHATDLG_CreateJoinScreen()
{
// build: symbol ?CHATDLG_GetConnectStatus@* 0x0043DC30
    if (CHATDLG_GetConnectStatus() == -1)
    {
        CHATDLG_ShowWait(D2LANG_GetStringFromTblIndex(0x1413), 0);
        return;
    }
    gpJoinGameBckgImage = CONTROL_Create(&gtJoinGameBckgImageInit);
    gpJoinGameTitle = CONTROL_Create(&gtJoinGameTitleInit);
    D2Win_10044(gpJoinGameTitle, D2LANG_GetStringFromTblIndex(0x141F));
    gpJoinNameLabel = CONTROL_Create(&gtJoinNameLabelInit);
    D2Win_10044(gpJoinNameLabel, D2LANG_GetStringFromTblIndex(0x149A));
    gpJoinPasswordLabel = CONTROL_Create(&gtJoinPasswordLabelInit);
    D2Win_10044(gpJoinPasswordLabel, D2LANG_GetStringFromTblIndex(0x1469));
    gpControl_00798BE8 = CONTROL_Create(&gtControlInit_0070D6F0);
    D2Win_10044(gpControl_00798BE8, D2LANG_GetStringFromTblIndex(0x149B));
    gpJoinButton = CONTROL_Create(&gtJoinButtonInit);
    gpControl_00798BD0 = CONTROL_Create(&gtControlInit_0070E110);
    sub_004FA450_SetActive(gpControl_00798BD0);
    gpJoinName = CONTROL_Create(&gtJoinNameInit);
    sub_004FDD50_SetMaxLength(gpJoinName, 0x10);
    sub_004FDAD0_SetKeyCallback(gpJoinName, CHATDLG_JoinNameKey);
    sub_004FDB00_SetEnterCallback(gpJoinName, CHATDLG_JoinNameEnter);
    gpJoinPassword = CONTROL_Create(&gtJoinPasswordInit);
    sub_004FDD50_SetMaxLength(gpJoinPassword, 0x10);
    sub_004FDAD0_SetKeyCallback(gpJoinPassword, (int (__stdcall*)(D2WinControlStrc*, int, const char*))CHATDLG_IsPrintableChar);
    sub_004FDDD0_LinkTab(gpJoinName, gpJoinPassword);
    sub_004FDDD0_LinkTab(gpJoinPassword, gpJoinName);
// build: symbol ?gpGameList@* 0x00798BC0
    gpGameList = CONTROL_Create(&gtGameListInit);
    if (MCPCONNECT_QueryAddress())
    {
        sub_004FBC20(gpGameList, 2);
        sub_004FBC80(gpGameList, 1, 0x87);
    }
    gpControl_00798BC4 = CONTROL_Create(&gtGameInfoTextInit);
    const unsigned long dwElapsed = GetTickCount() - gdwLastRefresh;
    if (dwElapsed >= 0x1388)
    {
        gdwLastRefresh += dwElapsed;
// build: symbol ?CHARSEL_RequestGameList@* 0x00445020
        CHARSEL_RequestGameList();
    }
    CONTROL_SetFocusedEditBox(gpJoinName);
// build: symbol ?gnLastGameCount@* 0x00798CC8
    gnLastGameCount = 0;
    gnGameCount = 0;
// build: symbol ?CHATDLG_UpdateJoinButtonState@* 0x004437E0
    CHATDLG_UpdateJoinButtonState();
}

// 0x004497F0
void __fastcall CHATDLG_MixChar(char* pChar, int nBits, unsigned int* pPool)
{
    *pChar = (char)toupper(*pChar);
    if (*pChar <= '7')
    {
        *pChar ^= *pPool & 7;
        *pPool >>= 3;
    }
    else if (*pChar < 'A')
    {
        *pChar ^= nBits & 1;
    }
}

int __stdcall CHATDLG_RequestCharLogon(int nA); // 0x00449E10

extern "C" void __cdecl CHARSEL_SendChatLine(); // 0x00446890
extern "C" void __cdecl COMCALLBACK_SendChatLine(); // 0x004468F0
extern "C" void __cdecl COMCALLBACK_OnChatPanelClick(); // 0x00446950
extern "C" void __cdecl COMCALLBACK_SendEmoteLine(); // 0x00446970
extern "C" void __cdecl COMCALLBACK_SquelchSelectedUser(); // 0x00448E30
extern "C" void __cdecl COMCALLBACK_UnsquelchSelectedUser(); // 0x00448F60
extern "C" void __cdecl sub_00441320(); // 0x00441320
extern "C" void __cdecl COMCALLBACK_OpenJoinScreen(); // 0x00446780
extern "C" void __cdecl COMCALLBACK_OpenCreateScreen(); // 0x004467D0
extern "C" void __cdecl COMCALLBACK_OnActivate(); // 0x00447A90
extern "C" char gData_0077BD84[]; // 0x0077BD84
extern "C" void __cdecl sub_004456D0(); // 0x004456D0

#pragma pack(push, 1)
struct d2data_0070CE00_t
{
    const void* p0;
    const void* p1;
    unsigned char b2[8];
    const void* p3;
    const void* p4;
    unsigned char b5[8];
    const void* p6;
    const void* p7;
    unsigned char b8[8];
    const void* p9;
    const void* p10;
    unsigned char b11[8];
    const void* p12;
    const void* p13;
    unsigned char b14[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D3C0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D7E0_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[40];
    const void* p4;
    int (__stdcall* p5)(int nArg);
    unsigned char b6[40];
    const void* p7;
    int (__stdcall* p8)(int nArg);
    unsigned char b9[40];
    const void* p10;
    int (__stdcall* p11)(int nArg);
    unsigned char b12[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D8D0_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[16];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D900_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D930_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D960_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D990_t
{
    unsigned char b0[36];
    int (__stdcall* p1)(int nArg);
    const void* p2;
    unsigned char b3[44];
    const void* p4;
    unsigned char b5[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070D9F0_t
{
    unsigned char b0[28];
    const void* p1;
    void (__cdecl* p2)(void);
    const void* p3;
    const void* p4;
    unsigned char b5[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DA20_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DA50_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[16];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DA80_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DAB0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DAE0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DB10_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DB40_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DB70_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DBA0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DBD0_t
{
    unsigned char b0[36];
    void (__cdecl* p1)(void);
    const void* p2;
    unsigned char b3[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DC00_t
{
    unsigned char b0[36];
    void (__cdecl* p1)(void);
    const void* p2;
    unsigned char b3[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DC30_t
{
    unsigned char b0[36];
    void (__cdecl* p1)(void);
    const void* p2;
    unsigned char b3[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DC60_t
{
    unsigned char b0[36];
    void (__cdecl* p1)(void);
    const void* p2;
    unsigned char b3[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DC90_t
{
    unsigned char b0[36];
    void (__cdecl* p1)(void);
    const void* p2;
    unsigned char b3[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DCC0_t
{
    unsigned char b0[28];
    const void* p1;
    void (__cdecl* p2)(void);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DCF0_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DD20_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[16];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DD50_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DD80_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DDB0_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DDE0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DE10_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DE40_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DE70_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DEA0_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DED0_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DF00_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DF30_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[16];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DF60_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[16];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070DF90_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[44];
    const void* p3;
    unsigned char b4[56];
    const void* p5;
    unsigned char b6[32];
    const void* p7;
    int (__stdcall* p8)(int nArg);
    unsigned char b9[40];
    const void* p10;
    int (__stdcall* p11)(int nArg);
    unsigned char b12[40];
    const void* p13;
    int (__stdcall* p14)(int nArg);
    unsigned char b15[40];
    const void* p16;
    int (__stdcall* p17)(int nArg);
    unsigned char b18[40];
    const void* p19;
    int (__stdcall* p20)(int nArg);
    unsigned char b21[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E110_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(SMSGHANDLER_PARAMS* pMsg);
    unsigned char b3[40];
    const void* p4;
    unsigned char b5[56];
    const void* p6;
    unsigned char b7[44];
    const void* p8;
    unsigned char b9[44];
    const void* p10;
    unsigned char b11[44];
    const void* p12;
    unsigned char b13[44];
    const void* p14;
    unsigned char b15[44];
    const void* p16;
    unsigned char b17[32];
    const void* p18;
    unsigned char b19[4];
    const void* p20;
    const void* p21;
    unsigned char b22[32];
    const void* p23;
    int (__stdcall* p24)(SMSGHANDLER_PARAMS* pMsg);
    unsigned char b25[40];
    const void* p26;
    int (__stdcall* p27)(D2WinMsgStrc* pMsg);
    unsigned char b28[40];
    const void* p29;
    int (__stdcall* p30)(D2WinMsgStrc* pMsg);
    unsigned char b31[40];
    const void* p32;
    int (__stdcall* p33)(D2WinMsgStrc* pMsg);
    unsigned char b34[40];
    const void* p35;
    int (__stdcall* p36)(D2WinMsgStrc* pMsg);
    unsigned char b37[40];
    const void* p38;
    int (__stdcall* p39)(D2WinMsgStrc* pMsg);
    unsigned char b40[40];
    const void* p41;
    int (__stdcall* p42)(D2WinMsgStrc* pMsg);
    unsigned char b43[40];
    const void* p44;
    int (__stdcall* p45)(D2WinMsgStrc* pMsg);
    unsigned char b46[40];
    const void* p47;
    int (__stdcall* p48)(D2WinMsgStrc* pMsg);
    unsigned char b49[52];
    const void* p50;
    unsigned char b51[44];
    const void* p52;
    unsigned char b53[44];
    const void* p54;
    unsigned char b55[44];
    const void* p56;
    unsigned char b57[44];
    const void* p58;
    unsigned char b59[44];
    const void* p60;
    unsigned char b61[44];
    const void* p62;
    unsigned char b63[44];
    const void* p64;
    unsigned char b65[32];
    const void* p66;
    int (__stdcall* p67)(int a);
    unsigned char b68[40];
    const void* p69;
    int (__stdcall* p70)(int nUnused);
    unsigned char b71[44];
    int (__stdcall* p72)(SMSGHANDLER_PARAMS* pMsg);
    unsigned char b73[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E680_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[16];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E6B0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E6E0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E710_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E740_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E770_t
{
    unsigned char b0[28];
    const void* p1;
    unsigned char b2[16];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E7A0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E7D0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E800_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E830_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E920_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E950_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070E980_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EAA0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EAD0_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EB00_t
{
    unsigned char b0[40];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EB30_t
{
    unsigned char b0[28];
    const void* p1;
    int (__stdcall* p2)(int nArg);
    unsigned char b3[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070EB60_t
{
    unsigned char b0[32];
    int (__stdcall* p1)(int nArg);
    unsigned char b2[12];
};
#pragma pack(pop)

extern "C" const char gszData_006D5564[4]; // 0x006D5564
extern "C" const char gszData_006D5568[4]; // 0x006D5568
extern "C" const char gszData_006D556C[4]; // 0x006D556C
extern "C" const char gszData_006D5570[4]; // 0x006D5570
extern "C" const char gszData_006D5574[4]; // 0x006D5574

extern "C" const char* const gData_006D5524[7] = { // 0x006D5524
    gszData_006D5564,
    gszData_006D5568,
    gszData_006D556C,
    gszData_006D5570,
    gszData_006D5574,
    "dru",
    "asn"
};
#pragma comment(linker, "/alternatename:_gaszClassNames=_gData_006D5524")

extern "C" const char gszData_006D5564[4] = "ama"; // 0x006D5564

extern "C" const char gszData_006D5568[4] = "sor"; // 0x006D5568

extern "C" const char gszData_006D556C[4] = "nec"; // 0x006D556C

extern "C" const char gszData_006D5570[4] = "pal"; // 0x006D5570

extern "C" const char gszData_006D5574[4] = "bar"; // 0x006D5574

extern "C" const char gData_006D55EC[12] = "/w *%s %s"; // 0x006D55EC
#pragma comment(linker, "/alternatename:_gszReplyFormat=_gData_006D55EC")

extern "C" const char gData_006D55F8[32] = "Correct usage is: %s (message)"; // 0x006D55F8
#pragma comment(linker, "/alternatename:_gszCorrectUsage=_gData_006D55F8")

extern "C" const char gData_006D5618[4] = "%s "; // 0x006D5618
#pragma comment(linker, "/alternatename:_gszCommandSpace=_gData_006D5618")

extern "C" const char gData_006D561C[20] = "Nobody to reply to!"; // 0x006D561C
#pragma comment(linker, "/alternatename:_gszNobodyToReply=_gData_006D561C")

extern "C" const char gData_006D5630[8] = "/home"; // 0x006D5630
#pragma comment(linker, "/alternatename:_gszCmdHome=_gData_006D5630")

extern "C" const char gData_006D5638[8] = "/home "; // 0x006D5638
#pragma comment(linker, "/alternatename:_gszCmdHomeSpace=_gData_006D5638")

extern "C" const char gData_006D5640[20] = "/defaultchannel "; // 0x006D5640
#pragma comment(linker, "/alternatename:_gszCmdDefaultChannel=_gData_006D5640")

extern "C" const char gData_006D5654[16] = "/homechannel "; // 0x006D5654
#pragma comment(linker, "/alternatename:_gszCmdHomeChannel=_gData_006D5654")

extern "C" const char gData_006D56C0[12] = "/d2notify"; // 0x006D56C0
#pragma comment(linker, "/alternatename:_gszCmdD2Notify=_gData_006D56C0")

extern "C" const char gData_006D56CC[8] = "/reply"; // 0x006D56CC
#pragma comment(linker, "/alternatename:_gszCmdReply=_gData_006D56CC")

extern "C" const char gData_006D56D4[4] = "/r"; // 0x006D56D4
#pragma comment(linker, "/alternatename:_gszCmdR=_gData_006D56D4")

extern "C" const char* gData_0070CD18[15] = { // 0x0070CD18
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};

extern "C" const char* gData_0070CD54[3] = { "profile\\sex", "profile\\location", "profile\\description" }; // 0x0070CD54
#pragma comment(linker, "/alternatename:?gKey_0070CD54@@3DA=_gData_0070CD54")

unsigned short gwRequestId = 1; // 0x0070CD60

unsigned char gnSelectModeA = 255; // 0x0070CD62

char gnSelectModeB_0070CD63 = -1; // 0x0070CD63

int gnSelectLinePrev = -1; // 0x0070CD64

int gnSelectLine = -1; // 0x0070CD68

int gnSelectFlag = 0x1; // 0x0070CD6C

extern int gbExpansionClasses = 1; // 0x0070CD70

int gnHistoryIndex = -1; // 0x0070CD74

extern "C" unsigned char gData_0070CD78[4] = { 0xFF, 0xFF, 0xFF, 0xFF }; // 0x0070CD78

int gnSelectIdA_0070CD7C = -1; // 0x0070CD7C

int gnSelectIdB = -1; // 0x0070CD80

extern "C" unsigned char gData_0070CD84[16] = { // 0x0070CD84
    0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};

extern "C" unsigned char gData_0070CD94[8] = { 0x02, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 0x0070CD94

extern "C" unsigned char gData_0070CD9C[8] = { 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 0x0070CD9C

extern "C" unsigned char gData_0070CDA4[8] = { 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }; // 0x0070CDA4

extern "C" unsigned char gData_0070CDAC[12] = { 0x90, 0x01, 0x00, 0x00, 0x86, 0x01, 0x00, 0x00, 0x3A, 0x01, 0x00, 0x00 }; // 0x0070CDAC

extern "C" unsigned char gData_0070CDB8[12] = { 0x50, 0x02, 0x00, 0x00, 0x89, 0x01, 0x00, 0x00, 0xAD, 0x00, 0x00, 0x00 }; // 0x0070CDB8

extern "C" unsigned char gData_0070CDC4[12] = { 0xF1, 0x02, 0x00, 0x00, 0x8A, 0x01, 0x00, 0x00, 0xC4, 0x00, 0x00, 0x00 }; // 0x0070CDC4

extern "C" unsigned char gData_0070CDD0[12] = { 0xF1, 0x02, 0x00, 0x00, 0x89, 0x01, 0x00, 0x00, 0xC5, 0x00, 0x00, 0x00 }; // 0x0070CDD0

extern "C" unsigned char gData_0070CDDC[24] = { // 0x0070CDDC
    0xF4, 0x02, 0x00, 0x00, 0x87, 0x01, 0x00, 0x00, 0xEE, 0x00, 0x00, 0x00, 0xF4, 0x02, 0x00, 0x00,
    0x87, 0x01, 0x00, 0x00, 0x0A, 0x01, 0x00, 0x00
};

extern "C" unsigned char gData_0070CDF4[12] = { 0xF1, 0x02, 0x00, 0x00, 0x87, 0x01, 0x00, 0x00, 0x0A, 0x01, 0x00, 0x00 }; // 0x0070CDF4

extern "C" struct d2data_0070CE00_t gData_0070CE00 = { // 0x0070CE00
    &gpD2LogoBlackBnetCelFile,
    &gpD2LogoBnetCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 },
    &gpD2LogoBlackBnetCelFile,
    &gpD2LogoBnetCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 },
    &gpD2LogoBlackBnetCelFile,
    &gpD2LogoBnetCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 },
    &gpD2LogoBlackBnetCelFile,
    &gpD2LogoBnetCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 },
    &gpD2LogoBlackBnetCelFile,
    &gpD2LogoBnetCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00 }
};

extern "C" D2WinControlInitStrc gData_0070CE50[17] = { // 0x0070CE50
    { 6, 27, 470, 80, 20, 0, 5305, &gpChatLeftButtonsCelFile, (int)(unsigned int)&CHARSEL_SendChatLine, 0, 0, 0 },
    { 6, 107, 470, 80, 20, 0, 5306, &gpChatLeftButtonsCelFile, (int)(unsigned int)&COMCALLBACK_SendChatLine, 0, 0, 0 },
    { 6, 187, 470, 80, 20, 0, 5308, &gpChatLeftButtonsCelFile, (int)(unsigned int)&COMCALLBACK_OnChatPanelClick, 0, 0, 0 },
    { 6, 27, 490, 72, 20, 0, 5307, &gpChatLeftButtons1CelFile, (int)(unsigned int)&COMCALLBACK_SquelchSelectedUser, 0, 0, 0 },
    { 6, 99, 490, 96, 20, 0, 5310, &gpChatLeftButtons2CelFile, (int)(unsigned int)&COMCALLBACK_UnsquelchSelectedUser, 0, 0, 0 },
    { 6, 195, 490, 72, 20, 0, 5309, &gpChatLeftButtons1CelFile, (int)(unsigned int)&COMCALLBACK_SendEmoteLine, 0, 0, 0 },
    { 6, 533, 469, 120, 20, 0, 5312, &gpChatRightTopButtonsCelFile, (int)(unsigned int)&COMCALLBACK_OpenCreateScreen, 0, 0, 1 },
    { 6, 535, 490, 80, 20, 0, 5314, &gpChatRightButtonsCelFile, (int)(unsigned int)&CHATDLG_ReleaseAndCreate, 0, 0, 1 },
    { 6, 652, 469, 120, 20, 0, 5313, &gpChatRightTopButtonsCelFile, (int)(unsigned int)&COMCALLBACK_OpenJoinScreen, 0, 0, 1 },
    { 6, 614, 490, 80, 20, 0, 5315, &gpChatRightButtonsCelFile, (int)(unsigned int)&CHATDLG_ReleaseAndRecreate, 0, 0, 1 },
    { 6, 693, 490, 80, 20, 0, 5316, &gpChatRightButtonsCelFile, (int)(unsigned int)&CHATDLG_OnQuitMessage, 0, 0, 0 },
    { 6, 725, 583, 25, 30, 0, 0, &gpChatArrowsCelFile, (int)(unsigned int)&CHATDLG_ScrollPageUp, 0, 0, 0 },
    { 6, 751, 583, 25, 30, 0, 0, &gpChatArrowsCelFile, (int)(unsigned int)&CHATDLG_OnScrollPageDown, 2, 0, 0 },
    { 6, 725, 528, 25, 30, 0, 0, &gpChatArrowsCelFile, (int)(unsigned int)&CHATDLG_OnScrollUp, 4, 0, 0 },
    { 6, 751, 528, 25, 30, 0, 0, &gpChatArrowsCelFile, (int)(unsigned int)&CHATDLG_OnScrollDown, 6, 0, 0 },
    { 2, 145, 69, 510, 60, 0, 0, 0, 0, 0, 0, 0 },
    { 9, 145, 69, 510, 60, 0, 0, 0, (int)(unsigned int)&CHATDLG_OpenAdUrl, 0, 0, 0 }
};
#pragma comment(linker, "/alternatename:?gatChatControlInits@@3PAUD2WinControlInitStrc@@A=_gData_0070CE50")

D2WinControlInitStrc gatControlInits[2] = { // 0x0070D180
    { 6, 27, 480, 120, 20, 13, 11126, &gpChatRightTopButtonsCelFile, (int)(unsigned int)&CHATDLG_UseRegistryChannel, 0, 0, 0 },
    { 6, 146, 480, 120, 20, 0, 5308, &gpChatRightTopButtonsCelFile, (int)(unsigned int)&COMCALLBACK_OnActivate, 0, 0, 0 }
};

D2WinControlInitStrc gtControlInit_0070D1E0 = { 4, 143, 588, 230, 87, 0, 0, 0, 0, 0, (int)&gData_0070CD84, 0 }; // 0x0070D1E0

D2WinControlInitStrc gtControlInit_0070D210 = { 12, 40, 591, 720, 75, 0, 0, 0, 0, 0, 0, 0 }; // 0x0070D210

D2WinControlInitStrc gtChatTextBoxInit = { // 0x0070D240
    4, 28, 410, 354,
    298, 0, 0, &gpScrollBarCelFile,
    0, (int)&gData_0070CDAC, (int)&gData_0070CD84, 4
};

D2WinControlInitStrc gtChatEditInit = { // 0x0070D270
    1, 28, 450, 335,
    32, 0, 0, 0,
    0, (int)(unsigned int)&CHATDLG_OnChatLine, (int)&gData_0070CD84, 22
};

D2WinControlInitStrc gtControlInit_0070D2A0 = { 4, 28, 138, 354, 60, 0, 0, 0, 0, 0, (int)&gData_0070CD84, 2 }; // 0x0070D2A0

D2WinControlInitStrc gtControlInit_0070D2D0 = { 3, 84, 52, 147, 68, 0, 0, 0, 0, (int)&gData_0070CE00, 0, 0 }; // 0x0070D2D0

D2WinControlInitStrc gtBlankBckgImageInit = { 2, 415, 447, 373, 373, 0, 0, &gpBlankBckg2CelFile, 0, 0, 0, 0 }; // 0x0070D300

D2WinControlInitStrc gtControlInit_0070D330 = { 4, 447, 398, 290, 269, 0, 0, 0, 0, 0, (int)&gData_0070CD84, 2 }; // 0x0070D330

D2WinControlInitStrc gtControlInit_0070D360 = { 3, 726, 52, 147, 68, 0, 0, 0, 0, (int)&gData_0070CE00, 0, 0 }; // 0x0070D360

D2WinControlInitStrc gtGemButtonInit = { // 0x0070D390
    6, 398, 474, 12,
    13, 0, 0, &gpGemButtonCelFile,
    (int)(unsigned int)&CHATDLG_OnToggleButton, 0, 0, 4
};

extern "C" struct d2data_0070D3C0_t gData_0070D3C0 = { // 0x0070D3C0
    { 0x04, 0x00, 0x00, 0x00, 0xB6, 0x01, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x46, 0x01, 0x00, 0x00, 0x96 },
    &gData_0070CD94,
    { 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtWaitInit@@3UD2WinControlInitStrc@@A=_gData_0070D3C0")

D2WinControlInitStrc gtControlInit_0070D3F0 = { // 0x0070D3F0
    7, 438, 240, 326,
    50, 0, 0, 0,
    0, (int)&gab_0077BD64, (int)&gData_0070CD94, 2
};

D2WinControlInitStrc gtControlInit_0070D420 = { 4, 438, 200, 326, 50, 0, 0, 0, 0, 0, (int)&gData_0070CD94, 2 }; // 0x0070D420

D2WinControlInitStrc gtControlInit_0070D450 = { // 0x0070D450
    7, 438, 240, 326,
    50, 0, 0, 0,
    0, (int)&gab_0077BD74, (int)&gData_0070CD94, 2
};

D2WinControlInitStrc gtControlInit_0070D480 = { 2, 268, 350, 264, 176, 0, 0, &gpBnetPopUpOkCelFile, 0, 0, 0, 0 }; // 0x0070D480

D2WinControlInitStrc gtControlInit_0070D4B0 = { // 0x0070D4B0
    6, 351, 337, 96,
    32, 13, 5102, &gpBnetCancelButtonBlankCelFileA,
    (int)(unsigned int)&CHATDLG_RunCallback, 0, 0, 2
};

D2WinControlInitStrc gtControlInit_0070D4E0 = { // 0x0070D4E0
    6, 351, 337, 96,
    32, 13, 5103, &gpBnetCancelButtonBlankCelFileA,
    (int)(unsigned int)&CHATDLG_RunCallback, 0, 0, 2
};

D2WinControlInitStrc gtControlInit_0070D510 = { 4, 268, 320, 264, 120, 10, 8, 0, 0, 0, (int)&gData_0070CDA4, 2 }; // 0x0070D510

D2WinControlInitStrc gtControlInit_0070D540 = { 2, 158, 460, 485, 290, 0, 0, &gpPopUpLargest2CelFile, 0, 0, 0, 0 }; // 0x0070D540

D2WinControlInitStrc gtControlInit_0070D570 = { // 0x0070D570
    6, 205, 440, 128,
    35, 13, 5103, &gpMediumButtonBlank2CelFile,
    (int)(unsigned int)&CHATDLG_OnClearEdit, 0, 0, 0
};

D2WinControlInitStrc gtControlInit_0070D5A0 = { // 0x0070D5A0
    6, 336, 454, 128,
    35, 0, 5102, &gpMediumButtonBlank2CelFile,
    (int)(unsigned int)&CHATDLG_SendChat, 0, 0, 0
};

D2WinControlInitStrc gtControlInit_0070D5D0 = { 4, 158, 240, 485, 40, 0, 0, 0, 0, 0, (int)&gData_0070CD94, 2 }; // 0x0070D5D0

D2WinControlInitStrc gtControlInit_0070D600 = { 4, 172, 420, 457, 180, 10, 0, 0, 0, 0, (int)&gData_0070CDA4, 0 }; // 0x0070D600

D2WinControlInitStrc gtJoinGameBckgImageInit = { 2, 415, 447, 373, 373, 0, 0, &gpJoinGameBckgCelFile, 0, 0, 0, 0 }; // 0x0070D630

D2WinControlInitStrc gtJoinGameTitleInit = { 4, 496, 106, 200, 22, 0, 0, 0, 0, 0, (int)&gData_0070CD94, 2 }; // 0x0070D660

D2WinControlInitStrc gtJoinNameLabelInit = { 4, 428, 121, 150, 12, 0, 0, 0, 0, 0, (int)&gData_0070CD9C, 0 }; // 0x0070D690

D2WinControlInitStrc gtJoinPasswordLabelInit = { 4, 602, 121, 150, 12, 0, 0, 0, 0, 0, (int)&gData_0070CD9C, 0 }; // 0x0070D6C0

D2WinControlInitStrc gtControlInit_0070D6F0 = { 4, 431, 212, 200, 12, 0, 0, 0, 0, 0, (int)&gData_0070CD9C, 0 }; // 0x0070D6F0

D2WinControlInitStrc gtJoinNameInit = { // 0x0070D720
    1, 432, 148, 155,
    20, 0, 0, 0,
    0, (int)(unsigned int)&CHATDLG_JoinByName, (int)&gData_0070CD84, 0
};

D2WinControlInitStrc gtJoinPasswordInit = { // 0x0070D750
    1, 606, 148, 155,
    20, 0, 0, 0,
    0, (int)(unsigned int)&CHATDLG_JoinByName, (int)&gData_0070CD84, 1
};

D2WinControlInitStrc gtGameListInit = { // 0x0070D780
    4, 432, 393, 160,
    173, 0, 0, &gpBnetJoinGameScrollBarsCelFile,
    (int)(unsigned int)&sub_004450D0_OnGameListEvent, (int)&gData_0070CDB8, (int)&gData_0070CD84, 5
};

D2WinControlInitStrc gtJoinButtonInit = { // 0x0070D7B0
    6, 594, 433, 172,
    32, 13, 5151, &gpGameButtonBlankCelFile,
    (int)(unsigned int)&CHATDLG_JoinByName, 0, 0, 0
};

extern "C" struct d2data_0070D7E0_t gData_0070D7E0 = { // 0x0070D7E0
    { 0x06, 0x00, 0x00, 0x00, 0xD7, 0x01, 0x00, 0x00, 0xB9, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x10 },
    &gpJoinGameClickBoxCelFile,
    &sub_00443C10_AlwaysOne,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x2A, 0x02, 0x00, 0x00, 0xB9, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x10
    },
    &gpJoinGameClickBoxCelFile,
    &sub_00443C10_AlwaysOne,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x6E, 0x02, 0x00, 0x00, 0xB9, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x10
    },
    &gpJoinGameClickBoxCelFile,
    &sub_00443C10_AlwaysOne,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xC9, 0x02, 0x00, 0x00, 0xB9, 0x00, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x10
    },
    &gpJoinGameClickBoxCelFile,
    &sub_00443C10_AlwaysOne,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00 }
};

D2WinControlInitStrc gtGameInfoTextInit = { // 0x0070D8A0
    4, 609, 393, 143,
    194, 0, 0, &gpBnetJoinGameScrollBarsCelFile,
    0, (int)&gData_0070CDC4, (int)&gData_0077BD84, 6
};

extern "C" struct d2data_0070D8D0_t gData_0070D8D0 = { // 0x0070D8D0
    { 0x02, 0x00, 0x00, 0x00, 0x9F, 0x01, 0x00, 0x00, 0xBF, 0x01, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00, 0x75, 0x01 },
    &gpCreateJoinBckgCelFile,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtCreateJoinBckgImageInit@@3UD2WinControlInitStrc@@A=_gData_0070D8D0")

extern "C" struct d2data_0070D900_t gData_0070D900 = { // 0x0070D900
    { 0x04, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x72, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x16 },
    &gData_0070CD94,
    { 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtChannelScreenTitleInit@@3UD2WinControlInitStrc@@A=_gData_0070D900")

extern "C" struct d2data_0070D930_t gData_0070D930 = { { 0x04, 0x00, 0x00, 0x00, 0xAB, 0x01, 0x00, 0x00, 0x87, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070D930
#pragma comment(linker, "/alternatename:?gtControlInit_0070D930@@3UD2WinControlInitStrc@@A=_gData_0070D930")

extern "C" struct d2data_0070D960_t gData_0070D960 = { { 0x04, 0x00, 0x00, 0x00, 0xAB, 0x01, 0x00, 0x00, 0xBB, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070D960
#pragma comment(linker, "/alternatename:?gtControlInit_0070D960@@3UD2WinControlInitStrc@@A=_gData_0070D960")

extern "C" struct d2data_0070D990_t gData_0070D990 = { // 0x0070D990
    { 0x01, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0x9B, 0x00, 0x00, 0x00, 0x14 },
    &CHATDLG_UseEditText,
    &gData_0070CD84,
    { 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x5E, 0x02, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0x9E, 0x00, 0x00, 0x00, 0x14 },
    &gData_0070CD84,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtChannelNameEditInit@@3UD2WinControlInitStrc@@A=_gData_0070D990")

extern "C" struct d2data_0070D9F0_t gData_0070D9F0 = { // 0x0070D9F0
    { 0x04, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0x8D, 0x01, 0x00, 0x00, 0x41, 0x01, 0x00, 0x00, 0xC8 },
    &gpBnetJoinGameScrollBarsCelFile,
    &sub_00441320,
    &gData_0070CDD0,
    &gData_0070CD84,
    { 0x05, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtChannelListInit@@3UD2WinControlInitStrc@@A=_gData_0070D9F0")

extern "C" struct d2data_0070DA20_t gData_0070DA20 = { // 0x0070DA20
    {
        0x06, 0x00, 0x00, 0x00, 0x9F, 0x02, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0xEE, 0x13, 0x00, 0x00
    },
    &gpBnetCancelButtonBlankCelFileB,
    &CHATDLG_UseEditText,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtChannelOkButtonInit@@3UD2WinControlInitStrc@@A=_gData_0070DA20")

extern "C" struct d2data_0070DA50_t gData_0070DA50 = { // 0x0070DA50
    { 0x02, 0x00, 0x00, 0x00, 0x9F, 0x01, 0x00, 0x00, 0xBF, 0x01, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00, 0x75, 0x01 },
    &gpCreateGameBckgCelFile,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtCreateGameBckgImageInit@@3UD2WinControlInitStrc@@A=_gData_0070DA50")

extern "C" struct d2data_0070DA80_t gData_0070DA80 = { // 0x0070DA80
    { 0x04, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x6F, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x16 },
    &gData_0070CD94,
    { 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtCreateGameTitleInit@@3UD2WinControlInitStrc@@A=_gData_0070DA80")

extern "C" struct d2data_0070DAB0_t gData_0070DAB0 = { { 0x04, 0x00, 0x00, 0x00, 0xAB, 0x01, 0x00, 0x00, 0x86, 0x00, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070DAB0
#pragma comment(linker, "/alternatename:?gtCreateNameLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DAB0")

extern "C" struct d2data_0070DAE0_t gData_0070DAE0 = { { 0x04, 0x00, 0x00, 0x00, 0xAB, 0x01, 0x00, 0x00, 0xBC, 0x00, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070DAE0
#pragma comment(linker, "/alternatename:?gtCreatePasswordLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DAE0")

extern "C" struct d2data_0070DB10_t gData_0070DB10 = { { 0x04, 0x00, 0x00, 0x00, 0xAB, 0x01, 0x00, 0x00, 0xF3, 0x00, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070DB10
#pragma comment(linker, "/alternatename:?gtCreateDescLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DB10")

extern "C" struct d2data_0070DB40_t gData_0070DB40 = { // 0x0070DB40
    { 0x04, 0x00, 0x00, 0x00, 0x78, 0x02, 0x00, 0x00, 0x32, 0x01, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x0C },
    &gData_0070CD9C,
    { 0x10, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtMaxPlayersLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DB40")

extern "C" struct d2data_0070DB70_t gData_0070DB70 = { // 0x0070DB70
    { 0x04, 0x00, 0x00, 0x00, 0x78, 0x02, 0x00, 0x00, 0x56, 0x01, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x0C },
    &gData_0070CD9C,
    { 0x10, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtLevelDiffLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DB70")

extern "C" struct d2data_0070DBA0_t gData_0070DBA0 = { { 0x04, 0x00, 0x00, 0x00, 0xC1, 0x02, 0x00, 0x00, 0x56, 0x01, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070DBA0
#pragma comment(linker, "/alternatename:?gtControlInit_0070DBA0@@3UD2WinControlInitStrc@@A=_gData_0070DBA0")

extern "C" struct d2data_0070DBD0_t gData_0070DBD0 = { // 0x0070DBD0
    { 0x01, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0x9E, 0x00, 0x00, 0x00, 0x14 },
    &sub_004456D0,
    &gData_0070CD84,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtCreateNameInit@@3UD2WinControlInitStrc@@A=_gData_0070DBD0")

extern "C" struct d2data_0070DC00_t gData_0070DC00 = { // 0x0070DC00
    { 0x01, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0xD9, 0x00, 0x00, 0x00, 0x9E, 0x00, 0x00, 0x00, 0x14 },
    &sub_004456D0,
    &gData_0070CD84,
    { 0x01, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtCreatePasswordInit@@3UD2WinControlInitStrc@@A=_gData_0070DC00")

extern "C" struct d2data_0070DC30_t gData_0070DC30 = { // 0x0070DC30
    { 0x01, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0x0C, 0x01, 0x00, 0x00, 0x4D, 0x01, 0x00, 0x00, 0x14 },
    &sub_004456D0,
    &gData_0070CD84,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtCreateDescInit@@3UD2WinControlInitStrc@@A=_gData_0070DC30")

extern "C" struct d2data_0070DC60_t gData_0070DC60 = { // 0x0070DC60
    { 0x01, 0x00, 0x00, 0x00, 0x91, 0x02, 0x00, 0x00, 0x34, 0x01, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x14 },
    &sub_004456D0,
    &gData_0070CD84,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtMaxPlayersEditInit@@3UD2WinControlInitStrc@@A=_gData_0070DC60")

extern "C" struct d2data_0070DC90_t gData_0070DC90 = { // 0x0070DC90
    { 0x01, 0x00, 0x00, 0x00, 0x91, 0x02, 0x00, 0x00, 0x56, 0x01, 0x00, 0x00, 0x1B, 0x00, 0x00, 0x00, 0x14 },
    &sub_004456D0,
    &gData_0070CD84,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtLevelDiffEditInit@@3UD2WinControlInitStrc@@A=_gData_0070DC90")

extern "C" struct d2data_0070DCC0_t gData_0070DCC0 = { // 0x0070DCC0
    {
        0x06, 0x00, 0x00, 0x00, 0x52, 0x02, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0xAC, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0x1E, 0x14, 0x00, 0x00
    },
    &gpGameButtonBlankCelFile,
    &sub_004456D0,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtCreateButtonInit@@3UD2WinControlInitStrc@@A=_gData_0070DCC0")

extern "C" struct d2data_0070DCF0_t gData_0070DCF0 = { // 0x0070DCF0
    { 0x06, 0x00, 0x00, 0x00, 0xAF, 0x01, 0x00, 0x00, 0x55, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x10 },
    &gpJoinGameClickBoxCelFile,
    &CHATDLG_OnLevelRestrictToggle,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtLevelDiffCheckInit@@3UD2WinControlInitStrc@@A=_gData_0070DCF0")

extern "C" struct d2data_0070DD20_t gData_0070DD20 = { { 0x02, 0x00, 0x00, 0x00, 0x87, 0x02, 0x00, 0x00, 0x5A, 0x01, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x1A }, &gpGreyLevelBoxCelFile, { 0 } }; // 0x0070DD20
#pragma comment(linker, "/alternatename:?gtLevelDiffBoxImageInit@@3UD2WinControlInitStrc@@A=_gData_0070DD20")

extern "C" struct d2data_0070DD50_t gData_0070DD50 = { // 0x0070DD50
    { 0x06, 0x00, 0x00, 0x00, 0xAE, 0x01, 0x00, 0x00, 0x7D, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10 },
    &gpRadioButtonCelFile,
    &CHATDLG_SelectNormal,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtNormalRadioInit@@3UD2WinControlInitStrc@@A=_gData_0070DD50")

extern "C" struct d2data_0070DD80_t gData_0070DD80 = { // 0x0070DD80
    { 0x06, 0x00, 0x00, 0x00, 0x2B, 0x02, 0x00, 0x00, 0x7D, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10 },
    &gpRadioButtonCelFile,
    &CHATDLG_SelectNightmare,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtNightmareRadioInit@@3UD2WinControlInitStrc@@A=_gData_0070DD80")

extern "C" struct d2data_0070DDB0_t gData_0070DDB0 = { // 0x0070DDB0
    { 0x06, 0x00, 0x00, 0x00, 0xBA, 0x02, 0x00, 0x00, 0x7D, 0x01, 0x00, 0x00, 0x10, 0x00, 0x00, 0x00, 0x10 },
    &gpRadioButtonCelFile,
    &CHATDLG_SelectHell,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtHellRadioInit@@3UD2WinControlInitStrc@@A=_gData_0070DDB0")

extern "C" struct d2data_0070DDE0_t gData_0070DDE0 = { { 0x04, 0x00, 0x00, 0x00, 0xCB, 0x01, 0x00, 0x00, 0x7C, 0x01, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070DDE0
#pragma comment(linker, "/alternatename:?gtNormalLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DDE0")

extern "C" struct d2data_0070DE10_t gData_0070DE10 = { { 0x04, 0x00, 0x00, 0x00, 0x43, 0x02, 0x00, 0x00, 0x7C, 0x01, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070DE10
#pragma comment(linker, "/alternatename:?gtNightmareLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DE10")

extern "C" struct d2data_0070DE40_t gData_0070DE40 = { { 0x04, 0x00, 0x00, 0x00, 0xD3, 0x02, 0x00, 0x00, 0x7C, 0x01, 0x00, 0x00, 0x96, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD9C, { 0 } }; // 0x0070DE40
#pragma comment(linker, "/alternatename:?gtHellLabelInit@@3UD2WinControlInitStrc@@A=_gData_0070DE40")

extern "C" struct d2data_0070DE70_t gData_0070DE70 = { // 0x0070DE70
    { 0x06, 0x00, 0x00, 0x00, 0xA9, 0x02, 0x00, 0x00, 0x28, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0C },
    &gpNumberArrowsCelFileC,
    &CHATDLG_IncrementMaxPlayers,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtMaxPlayersUpInit@@3UD2WinControlInitStrc@@A=_gData_0070DE70")

extern "C" struct d2data_0070DEA0_t gData_0070DEA0 = { // 0x0070DEA0
    { 0x06, 0x00, 0x00, 0x00, 0xA9, 0x02, 0x00, 0x00, 0x36, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0C },
    &gpNumberArrowsCelFileD,
    &CHATDLG_DecrementMaxPlayers,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtMaxPlayersDownInit@@3UD2WinControlInitStrc@@A=_gData_0070DEA0")

extern "C" struct d2data_0070DED0_t gData_0070DED0 = { // 0x0070DED0
    { 0x06, 0x00, 0x00, 0x00, 0xA9, 0x02, 0x00, 0x00, 0x4C, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0C },
    &gpNumberArrowsCelFileA,
    &CHATDLG_IncrementLevelRange,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtLevelDiffUpInit@@3UD2WinControlInitStrc@@A=_gData_0070DED0")

extern "C" struct d2data_0070DF00_t gData_0070DF00 = { // 0x0070DF00
    { 0x06, 0x00, 0x00, 0x00, 0xA9, 0x02, 0x00, 0x00, 0x5A, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x0C },
    &gpNumberArrowsCelFileB,
    &CHATDLG_DecrementLevelRange,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtLevelDiffDownInit@@3UD2WinControlInitStrc@@A=_gData_0070DF00")

extern "C" struct d2data_0070DF30_t gData_0070DF30 = { // 0x0070DF30
    { 0x06, 0x00, 0x00, 0x00, 0xA9, 0x02, 0x00, 0x00, 0x5A, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x1A },
    &gpNumberGreyArrowsCelFile,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtLevelDiffGreyArrowsInit@@3UD2WinControlInitStrc@@A=_gData_0070DF30")

extern "C" struct d2data_0070DF60_t gData_0070DF60 = { { 0x02, 0x00, 0x00, 0x00, 0x87, 0x02, 0x00, 0x00, 0x37, 0x01, 0x00, 0x00, 0x21, 0x00, 0x00, 0x00, 0x1A }, &gpGreyLevelBoxCelFile, { 0 } }; // 0x0070DF60
#pragma comment(linker, "/alternatename:?gtMaxPlayersBoxImageInit@@3UD2WinControlInitStrc@@A=_gData_0070DF60")

extern "C" struct d2data_0070DF90_t gData_0070DF90 = { // 0x0070DF90
    { 0x06, 0x00, 0x00, 0x00, 0xA9, 0x02, 0x00, 0x00, 0x37, 0x01, 0x00, 0x00, 0x0F, 0x00, 0x00, 0x00, 0x1A },
    &gpNumberGreyArrowsCelFile,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x02, 0x00, 0x00, 0x00, 0x9F, 0x01, 0x00, 0x00, 0xBF, 0x01, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00,
        0x75, 0x01
    },
    &gpLadderChoiceExpCelFile,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x70, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00,
        0x16
    },
    &gData_0070CD94,
    {
        0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0xCF, 0x01, 0x00, 0x00, 0xEE, 0x00, 0x00, 0x00,
        0x10, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC6, 0x14, 0x00, 0x00
    },
    &gpBnetWideButtonBlankCelFile,
    &CHATDLG_OpenLadderScreen,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xCF, 0x01, 0x00, 0x00, 0xEE, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x23, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x78, 0x06, 0x00, 0x00
    },
    &gpBnetWideButtonBlankCelFile,
    &CHATDLG_OnResetCallback,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xCF, 0x01, 0x00, 0x00, 0xBC, 0x00, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0xC5, 0x14, 0x00, 0x00
    },
    &gpBnetWideButtonBlankCelFile,
    &CHATDLG_ShowStandardLadder,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xCF, 0x01, 0x00, 0x00, 0x52, 0x01, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x6B, 0x27, 0x00, 0x00
    },
    &gpBnetWideButtonBlankCelFile,
    &CHATDLG_ShowExpansionHardcoreLadder,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xCF, 0x01, 0x00, 0x00, 0x20, 0x01, 0x00, 0x00, 0x10, 0x01, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x6A, 0x27, 0x00, 0x00
    },
    &gpBnetWideButtonBlankCelFile,
    &CHATDLG_ShowExpansionLadder,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtControlInit_0070DF90@@3UD2WinControlInitStrc@@A=_gData_0070DF90")

extern "C" struct d2data_0070E110_t gData_0070E110 = { // 0x0070E110
    {
        0x06, 0x00, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF, 0x13, 0x00, 0x00
    },
    &gpBnetCancelButtonBlankCelFileB,
    &CHATDLG_OnReset,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x9F, 0x01, 0x00, 0x00, 0xBF, 0x01, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00, 0x75, 0x01
    },
    &gpHardcoreLadderBckgCelFile,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x04, 0x00, 0x00, 0x00, 0xA5, 0x01, 0x00, 0x00, 0x88, 0x00, 0x00, 0x00, 0x5E, 0x01, 0x00, 0x00,
        0x32
    },
    &gData_0070CDA4,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xB2, 0x01, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0xD9, 0x00, 0x00, 0x00, 0x0C },
    &gData_0070CD84,
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xD4, 0x01, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0xD9, 0x00, 0x00, 0x00, 0x0C },
    &gData_0070CD84,
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x54, 0x02, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0xD9, 0x00, 0x00, 0x00, 0x0C },
    &gData_0070CD84,
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x80, 0x02, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0xD9, 0x00, 0x00, 0x00, 0x0C },
    &gData_0070CD84,
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xBF, 0x02, 0x00, 0x00, 0xA2, 0x00, 0x00, 0x00, 0xD9, 0x00, 0x00, 0x00, 0x0C },
    &gData_0070CD84,
    { 0x00, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xB2, 0x01, 0x00, 0x00, 0x87, 0x01, 0x00, 0x00, 0x39, 0x01, 0x00, 0x00, 0xDA },
    &gpBnetJoinGameScrollBarsCelFile,
    { 0 },
    &gData_0070CDDC,
    &gData_0070CD84,
    {
        0x04, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00,
        0x60, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF, 0x13, 0x00, 0x00
    },
    &gpBnetCancelButtonBlankCelFileB,
    &CHATDLG_OnBack,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xAB, 0x01, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x1D
    },
    &gpOverallTabCelFile,
    &CHATDLG_OnOverallLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x01, 0x02, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D
    },
    &gpAmazonTabCelFile,
    &CHATDLG_OnAmazonLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x26, 0x02, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D
    },
    &gpSorceressTabCelFile,
    &CHATDLG_OnSorceressLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x4B, 0x02, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D
    },
    &gpNecromancerTabCelFile,
    &CHATDLG_OnNecromancerLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x70, 0x02, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D
    },
    &gpPaladinTabCelFile,
    &CHATDLG_OnPaladinLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0x95, 0x02, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D
    },
    &gpBarbarianTabCelFile,
    &CHATDLG_OnBarbarianLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xBA, 0x02, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D
    },
    &gpDruidTabCelFile,
    &CHATDLG_OnDruidLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xDF, 0x02, 0x00, 0x00, 0x95, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D
    },
    &gpAssassinTabCelFile,
    &CHATDLG_OnAssassinLadderButton,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00,
        0xAB, 0x01, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x55, 0x00, 0x00, 0x00, 0x1D
    },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x01, 0x02, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x26, 0x02, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x4B, 0x02, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x70, 0x02, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x95, 0x02, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xBA, 0x02, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xDF, 0x02, 0x00, 0x00, 0x9D, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x1D },
    gData_0077BD84,
    { 0x02, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00, 0x77, 0x02, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x20 },
    &gpYesNoButtonBlankCelFile,
    &CHATDLG_ScrollLadderUp,
    {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x06, 0x00, 0x00, 0x00,
        0xBD, 0x02, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x46, 0x00, 0x00, 0x00, 0x20
    },
    &gpYesNoButtonBlankCelFile,
    &CHATDLG_ScrollLadderDown,
    { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x64 },
    &CHATDLG_OnIdle,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtControlInit_0070E110@@3UD2WinControlInitStrc@@A=_gData_0070E110")

extern "C" struct d2data_0070E680_t gData_0070E680 = { // 0x0070E680
    { 0x02, 0x00, 0x00, 0x00, 0x9F, 0x01, 0x00, 0x00, 0xBF, 0x01, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00, 0x75, 0x01 },
    &gpPlayerProfileBckgCelFileB,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtProfileEditBckgInit@@3UD2WinControlInitStrc@@A=_gData_0070E680")

extern "C" struct d2data_0070E6B0_t gData_0070E6B0 = { { 0x04, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0x93, 0x00, 0x00, 0x00, 0x9B, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD84, { 0 } }; // 0x0070E6B0
#pragma comment(linker, "/alternatename:?gtControlInit_0070E6B0@@3UD2WinControlInitStrc@@A=_gData_0070E6B0")

extern "C" struct d2data_0070E6E0_t gData_0070E6E0 = { { 0x01, 0x00, 0x00, 0x00, 0xC3, 0x02, 0x00, 0x00, 0x9B, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x14 }, &gData_0070CD84, { 0 } }; // 0x0070E6E0
#pragma comment(linker, "/alternatename:?gtSubmitEditAInit@@3UD2WinControlInitStrc@@A=_gData_0070E6E0")

extern "C" struct d2data_0070E710_t gData_0070E710 = { { 0x01, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0xCF, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x14 }, &gData_0070CD84, { 0 } }; // 0x0070E710
#pragma comment(linker, "/alternatename:?gtSubmitEditBInit@@3UD2WinControlInitStrc@@A=_gData_0070E710")

extern "C" struct d2data_0070E740_t gData_0070E740 = { // 0x0070E740
    { 0x01, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0x83, 0x01, 0x00, 0x00, 0x47, 0x01, 0x00, 0x00, 0x96 },
    &gData_0070CD84,
    { 0x08, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtSubmitEditCInit@@3UD2WinControlInitStrc@@A=_gData_0070E740")

extern "C" struct d2data_0070E770_t gData_0070E770 = { // 0x0070E770
    { 0x02, 0x00, 0x00, 0x00, 0x9F, 0x01, 0x00, 0x00, 0xBF, 0x01, 0x00, 0x00, 0x75, 0x01, 0x00, 0x00, 0x75, 0x01 },
    &gpPlayerProfileBckgCelFileA,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtProfileViewBckgInit@@3UD2WinControlInitStrc@@A=_gData_0070E770")

extern "C" struct d2data_0070E7A0_t gData_0070E7A0 = { { 0x04, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0x93, 0x00, 0x00, 0x00, 0x9B, 0x00, 0x00, 0x00, 0x0C }, &gData_0070CD84, { 0 } }; // 0x0070E7A0
#pragma comment(linker, "/alternatename:?gtControlInit_0070E7A0@@3UD2WinControlInitStrc@@A=_gData_0070E7A0")

extern "C" struct d2data_0070E7D0_t gData_0070E7D0 = { // 0x0070E7D0
    { 0x04, 0x00, 0x00, 0x00, 0xC3, 0x02, 0x00, 0x00, 0x93, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x0C },
    &gData_0070CD84,
    { 0x22, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtControlInit_0070E7D0@@3UD2WinControlInitStrc@@A=_gData_0070E7D0")

extern "C" struct d2data_0070E800_t gData_0070E800 = { // 0x0070E800
    { 0x04, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0xC7, 0x00, 0x00, 0x00, 0x03, 0x01, 0x00, 0x00, 0x0C },
    &gData_0070CD84,
    { 0x20, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtControlInit_0070E800@@3UD2WinControlInitStrc@@A=_gData_0070E800")

extern "C" struct d2data_0070E830_t gData_0070E830 = { { 0x04, 0x00, 0x00, 0x00, 0xB0, 0x01, 0x00, 0x00, 0x83, 0x01, 0x00, 0x00, 0x47, 0x01, 0x00, 0x00, 0x96 }, &gData_0070CD84, { 0 } }; // 0x0070E830
#pragma comment(linker, "/alternatename:?gtControlInit_0070E830@@3UD2WinControlInitStrc@@A=_gData_0070E830")

D2WinControlInitStrc gtControlInit_0070E860 = { 4, 425, 129, 217, 12, 0, 0, 0, 0, 0, (int)&gData_0070CD9C, 0 }; // 0x0070E860

D2WinControlInitStrc gtControlInit_0070E890 = { 4, 700, 129, 217, 12, 0, 0, 0, 0, 0, (int)&gData_0070CD9C, 0 }; // 0x0070E890

D2WinControlInitStrc gtControlInit_0070E8C0 = { 4, 425, 180, 217, 12, 0, 0, 0, 0, 0, (int)&gData_0070CD9C, 0 }; // 0x0070E8C0

D2WinControlInitStrc gtControlInit_0070E8F0 = { 4, 425, 230, 217, 12, 0, 0, 0, 0, 0, (int)&gData_0070CD9C, 0 }; // 0x0070E8F0

extern "C" struct d2data_0070E920_t gData_0070E920 = { // 0x0070E920
    {
        0x06, 0x00, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEF, 0x13, 0x00, 0x00
    },
    &gpBnetCancelButtonBlankCelFileB,
    &CHATDLG_OnRefresh,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtRefreshButtonInit@@3UD2WinControlInitStrc@@A=_gData_0070E920")

extern "C" struct d2data_0070E950_t gData_0070E950 = { // 0x0070E950
    {
        0x06, 0x00, 0x00, 0x00, 0x9F, 0x02, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xEE, 0x13, 0x00, 0x00
    },
    &gpBnetCancelButtonBlankCelFileB,
    &CHARSEL_SubmitProfile,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtSubmitButtonInit@@3UD2WinControlInitStrc@@A=_gData_0070E950")

extern "C" struct d2data_0070E980_t gData_0070E980 = { // 0x0070E980
    {
        0x06, 0x00, 0x00, 0x00, 0x28, 0x02, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xC3, 0x14, 0x00, 0x00
    },
    &gpBnetCancelButtonBlankCelFileB,
    &CHATDLG_OnLadderSelect,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtSelectButtonInit@@3UD2WinControlInitStrc@@A=_gData_0070E980")

D2WinControlInitStrc gtControlInit_0070E9B0 = { 4, 400, 112, 400, 22, 0, 0, 0, 0, 0, (int)&gData_0070CD94, 2 }; // 0x0070E9B0

D2WinControlInitStrc gtHelpBckgImageInit = { 2, 415, 447, 373, 373, 0, 0, &gpHelpBckgCelFile, 0, 0, 0, 0 }; // 0x0070E9E0

D2WinControlInitStrc gtControlInit_0070EA10 = { 4, 400, 112, 400, 22, 0, 0, 0, 0, 0, (int)&gData_0070CD94, 2 }; // 0x0070EA10

D2WinControlInitStrc gtControlInit_0070EA40 = { // 0x0070EA40
    4, 447, 398, 290,
    269, 0, 0, &gpBnetJoinGameScrollBarsCelFile,
    0, (int)&gData_0070CDF4, (int)&gData_0070CD84, 4
};

D2WinControlInitStrc gtControlInit_0070EA70 = { // 0x0070EA70
    6, 671, 433, 96,
    32, 13, 5102, &gpBnetCancelButtonBlankCelFileB,
    (int)(unsigned int)&CHATDLG_OnProfileClose, 0, 0, 0
};

extern "C" struct d2data_0070EAA0_t gData_0070EAA0 = { // 0x0070EAA0
    { 0x04, 0x00, 0x00, 0x00, 0xF0, 0x01, 0x00, 0x00, 0x79, 0x00, 0x00, 0x00, 0xC8, 0x00, 0x00, 0x00, 0x16 },
    &gData_0070CD94,
    { 0x02, 0x00, 0x00, 0x00 }
};
#pragma comment(linker, "/alternatename:?gtPanelTitleInit@@3UD2WinControlInitStrc@@A=_gData_0070EAA0")

extern "C" struct d2data_0070EAD0_t gData_0070EAD0 = { { 0x04, 0x00, 0x00, 0x00, 0xAB, 0x01, 0x00, 0x00, 0xEA, 0x00, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x64 }, &gData_0070CD9C, { 0 } }; // 0x0070EAD0
#pragma comment(linker, "/alternatename:?gtPanelTextInit@@3UD2WinControlInitStrc@@A=_gData_0070EAD0")

extern "C" struct d2data_0070EB00_t gData_0070EB00 = { { 0x04, 0x00, 0x00, 0x00, 0xAB, 0x01, 0x00, 0x00, 0xF3, 0x00, 0x00, 0x00, 0x2C, 0x01, 0x00, 0x00, 0x46 }, &gData_0070CD9C, { 0 } }; // 0x0070EB00

extern "C" struct d2data_0070EB30_t gData_0070EB30 = { // 0x0070EB30
    {
        0x06, 0x00, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0xB1, 0x01, 0x00, 0x00, 0x60, 0x00, 0x00, 0x00,
        0x20, 0x00, 0x00, 0x00, 0x0D, 0x00, 0x00, 0x00, 0xEF, 0x13, 0x00, 0x00
    },
    &gpBnetCancelButtonBlankCelFileB,
    &sub_004438C0_OnCancel,
    { 0 }
};
#pragma comment(linker, "/alternatename:?gtPanelCancelButtonInit@@3UD2WinControlInitStrc@@A=_gData_0070EB30")

extern "C" struct d2data_0070EB60_t gData_0070EB60 = { { 0x08, 0x00, 0x00, 0x00, 0x02 }, &CHATDLG_ResetBuildPanel, { 0 } }; // 0x0070EB60
#pragma comment(linker, "/alternatename:?gtResetBuildPanelTimerInit@@3UD2WinControlInitStrc@@A=_gData_0070EB60")

int gnChannelListLastSelection = -2; // 0x0070EB90

extern "C" const char* gData_0070EB94[15] = { // 0x0070EB94
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};

int gnPendingId = -1; // 0x0070EBD8
