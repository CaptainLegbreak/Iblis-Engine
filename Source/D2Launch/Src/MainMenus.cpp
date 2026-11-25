#include "D2Launch.h"

#include "D2Win32Types.h"

#include "D2MsgRecord.h"

#include "D2ClientTypes.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Drlg.h"

#include "D2LevelTxt.h"

#include "D2LaunchRequest.h"

#include "D2FogTypes.h"

#include "D2StormTypes.h"

#include "D2Unicode.h"

#include "D2MultiTypes.h"

#include "D2Win32System.h"
#include "D2Win32Message.h"
#include "D2CoordPair.h"

void __cdecl ERRORMANAGER_LogPoolError(const char* szFormat, ...); // 0x00409020

int __stdcall MAINMENUS_AskEmailRegistration(int nArg); // 0x00436C90

int __stdcall MAINMENUS_ConfirmText(int nArg); // 0x00437620

#pragma intrinsic(_ReadWriteBarrier)

#pragma intrinsic(strcmp)

#define _INTSIZEOF(n) ((sizeof(n) + sizeof(int) - 1) & ~(sizeof(int) - 1))

#define va_start(ap, v) (ap = (va_list)&v + _INTSIZEOF(v))

struct D2ServiceStatusStrc;

struct D2PoolSystemStrc;

struct D2MemoryStatusStrc;

struct D2MenuCallbackArgStrc;

struct D2SlotEntryStrc;

struct SMSGHANDLER_PARAMS;

struct D2WinMsgStrc;

struct D2CoordPairStrc;

struct D2ConfigStrc;

struct D2CriticalSectionStrc;

struct Unicode;

struct D2ComInterfaceStrc;

struct D2CompositeUnitStrc;

struct D2CelFileStrc;

struct D2LaunchThreadRecordStrc;

struct D2LaunchPayloadStrc;

typedef char* va_list;

struct D2MenuCallbackArgStrc
{
    int nUnk0x00;
    int nUnk0x04;
    int nUnk0x08;
    unsigned int nArg;
};

typedef int (__stdcall* D2GetDiskFreeSpaceExFn)(const char* szDirectory, unsigned __int64* pnFreeToCaller, unsigned __int64* pnTotal, unsigned __int64* pnTotalFree);

extern "C" __declspec(dllimport) void* __stdcall RegisterServiceCtrlHandlerA(const char* szServiceName, void (__stdcall* pfnHandler)(unsigned long dwCtrlCode)); // 0x006CC024

extern "C" __declspec(dllimport) int __stdcall SetServiceStatus(void* hServiceStatus, D2ServiceStatusStrc* pStatus); // 0x006CC048

extern "C" __declspec(dllimport) void* __stdcall LoadLibraryA(const char* szLibFileName); // 0x006CC144

extern "C" __declspec(dllimport) void* __stdcall GetProcAddress(void* hModule, const char* szProcName); // 0x006CC148

extern "C" __declspec(dllimport) int __stdcall FreeLibrary(void* hModule); // 0x006CC14C

extern "C" __declspec(dllimport) void __stdcall GlobalMemoryStatus(D2MemoryStatusStrc* pBuffer); // 0x006CC1F4

extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId(); // 0x006CC20C

extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode); // 0x006CC2E0

extern "C" int __cdecl vsprintf(char* szDest, const char* szFormat, va_list args); // 0x00682DA1

extern "C" void* __cdecl realloc(void* pMemory, size_t nSize); // 0x00683BA5

void __stdcall D2ServerServiceHandlerProc(unsigned long dwCtrlCode); // 0x00406410

void __fastcall LOGMANAGER_WriteLogV(const char* szPrefix, int nArg2, int nArg3, const char* szFormat, va_list args); // 0x00410340

void __cdecl LOGMANAGER_LogWritePrefixedLine(const char* szPrefix, const char* szFormat, ...); // 0x00410660

char* __fastcall Int64ToString(char* szBuffer, unsigned int nBufferSize, __int64 nValue); // 0x00411540

int __stdcall SFileEnableDirectAccess(int nFlags); // 0x00415F70

void __stdcall SFileEnableSeekOptimization(int nValue); // 0x00415F90

int __stdcall SFileSetBasePath(const char* szPath); // 0x004164B0

int __stdcall SFileSetIoErrorMode(int nValueA, int nValueB); // 0x004166B0

int __stdcall StormGetOption(unsigned int nOption, const void* pInput, unsigned int nSize); // 0x0041BFC0

void __cdecl LockErrorState(); // 0x0041C1A0

void __cdecl UnlockErrorState(); // 0x0041C1E0

int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0

void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300

int __stdcall SEvtPopState(unsigned long dwId, void* pContext); // 0x004269C0

int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0

int __stdcall MAINMENUS_ShowLevelScreen(int nArg); // 0x00431600

extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

extern "C" const char gszKernel32[]; // 0x006CD6E4

extern char gszServiceName[]; // 0x007065DC

extern D2ServiceStatusStrc gD2ServerServiceStatus; // 0x007065FC

extern void* ghD2ServerServiceStatus; // 0x0074C714

extern int gbRunningAsService; // 0x0074C720

extern int gnStormDirectFlags_0074C82C; // 0x0074C82C

extern void* gpStormOwnerB_007790C4; // 0x007790C4

extern unsigned long gdwStormOwnerThread_007790C8; // 0x007790C8

int gnFlag_007798D0; // 0x007798D0

struct D2SlotEntryStrc
{
    int unk0x00;
    int nField04;
};

static D2LaunchSlotStrc** gppSlots; // 0x00779988

extern int gnSlotCount; // 0x0077998C

void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80

extern D2WinControlStrc* gpList_0077995C; // 0x0077995C

extern D2WinControlStrc* gpList_00779960; // 0x00779960

extern int gdwGlobal_00779990; // 0x00779990

extern D2WinControlStrc* gpList_00779964; // 0x00779964

void __cdecl MAINMENUS_Reset(); // 0x0042F480

int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430

int __fastcall MAINMENUS_ShowCredits(int nUnused); // 0x00431050

int __fastcall D2Win_10053(D2WinControlStrc* pTextBox, int nLine); // 0x004FBA30

static unsigned char MAINMENUS_GetFlagIndex(unsigned char nFlags); // 0x004313A0



extern "C" int __cdecl abs(int nValue);

extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg); // 0x006CC478

extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg); // 0x006CC47C

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480

extern "C" __declspec(dllimport) int __stdcall GetCursorPos(D2CoordPairStrc* pPoint); // 0x006CC48C

int gnLastClickX; // 0x00779998

int gnLastClickY; // 0x0077999C

int gnLastClickTick; // 0x007799A0

void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0

int __cdecl CLIENT_GetConnectionStatus(); // 0x0052B050

D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

int __fastcall D2Win_10082(D2WinControlStrc* pEditBox); // 0x004FDD00

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590

void __cdecl MAINMENUS_CreateArchivePopup(); // 0x00431970

int gnLoaderFlag; // 0x007798E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

extern D2WinControlStrc* gpEdit_007799CC; // 0x007799CC

extern D2WinControlStrc* gpEdit_007799D0; // 0x007799D0

extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4

D2ConfigStrc* gpLaunchRecord; // 0x007795D4

void __cdecl D2SOUNDFAST_FadeOutWaves(); // 0x00515020

void __cdecl sub_0043B080();

void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100

void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0

int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0

void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0

void __cdecl CHARSEL_SetCancelled(); // 0x0043B810

void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0

int __stdcall MAINMENUS_FilterLoginChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FE70

int __stdcall MAINMENUS_FilterRestrictedChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0

int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20

int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0

void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0

void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0

D2WinControlStrc* gpCreatePasswordConfirmEdit; // 0x007795A8

extern D2WinControlStrc* gpPasswordOk; // 0x007799A4

D2WinControlStrc* gpStatusText; // 0x007799A8

D2WinControlStrc* gpCounterText; // 0x007799AC

int gnStatusStringId; // 0x007799B0

extern int gnStatusDots; // 0x007799B4

unsigned long gdwStatusStart; // 0x007799B8

extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

int __cdecl GAME_GetWaitHandle(); // 0x00449AC0

int __cdecl GAME_IsMcpCharDeleteReceived(); // 0x00449C50

int __cdecl GAME_IsMcpCharUpgradeReceived(); // 0x00449C70

void __stdcall CHATDLG_SetCharDeleteReceived(int nValue); // 0x00449C60

void __stdcall CHATDLG_SetCharUpgradeReceived(int nValue); // 0x00449C80

void __cdecl MAINMENUS_UpdateNameOk(); // 0x00430620

void __cdecl MAINMENUS_UpdateLoginOk(); // 0x004306C0

int gdwGlobal_00779974; // 0x00779974

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00433380

extern "C" void _ReadWriteBarrier(void);

void* __cdecl sub_00449AC0_GetHandle(); // 0x00449AC0

int __cdecl sub_00432350_GetStatus(); // 0x00432350

extern "C" int __cdecl strcmp(const char* szA, const char* szB);

struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};

struct D2LaunchPayloadStrc
{
    unsigned int nSize;
    D2LaunchThreadRecordStrc tRecord;
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

void __cdecl MAINMENUS_ShowConnectingPopup(); // 0x0042F6E0

int __stdcall MAINMENUS_OnWait(int nArg); // 0x00432450

void __stdcall CHATDLG_StartThread(D2LaunchThreadRecordStrc* pRecord); // 0x0044A130

struct D2LaunchControlTemplateStrc;

struct D2LaunchRecord3Strc;

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long nValue); // 0x004150E0

void __fastcall BUTTON_SetText(D2WinControlStrc* pControl, int nMode, unsigned short* pText, int nArg); // 0x005009D0

int __stdcall MAINMENUS_IsRestrictedChar(void* pControl, int nUnused, const char* pChar); // 0x0042FDE0

int __fastcall MAINMENUS_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg); // 0x00431A60

int __stdcall MAINMENUS_OnRealmSelected(SMSGHANDLER_PARAMS* pMsg); // 0x00434700

void __cdecl CHARSEL_RefreshCharEntry(); // 0x0043A650

int __stdcall CHARSEL_OnRealmChosen(SMSGHANDLER_PARAMS* pMsg); // 0x0043A950

void __fastcall CHARSEL_UseName(char* szName); // 0x0043ADB0

void __cdecl CHATDLG_DestroyPopupControls(); // 0x0043EA20

int __stdcall CHATDLG_SetUserDataFlag(int nArg); // 0x0043F580

int __stdcall CHATDLG_GetUserDataReply(int nUnused); // 0x0043F590

void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0

extern D2LaunchControlTemplateStrc gatControlTemplates[]; // 0x00708D10

extern int gnTextMode; // 0x00708D0C

extern char gKey_0070CD54; // 0x0070CD54

void __cdecl CHARSEL_InitCharSelectScreen(); // 0x0043B080

extern void (__cdecl* gpfnGatewayDone)(); // 0x007795BC

int __cdecl GAME_IsMcpCharCreateReceived(); // 0x00449C10

void __stdcall CHATDLG_SetCharCreateReceived(int nValue); // 0x00449C20

int __cdecl GAME_IsMcpCharLogonReceived(); // 0x00449C30

void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40

D2WinControlStrc* gpTextControl1; // 0x007795D8

D2WinControlStrc* gpTextControl2; // 0x007795DC

char gszEnteredName[256]; // 0x00779C88

int gbFlag_0077ADA4; // 0x0077ADA4

D2LaunchRecord3Strc gtRecord_0077B0A8; // 0x0077B0A8

struct D2WinTextBoxStrc;

int gbStopMainLoop;                                                                                     // 0x0077932C

D2WinControlStrc* gapControlsB[0x40];                                                              // 0x00779350

extern int gnControlCountB;                                                                        // 0x00779944

int __stdcall CONTROL_GetType(D2WinControlStrc* pControl);                                                  // 0x004FA490

int __fastcall D2Win_10054(D2WinTextBoxStrc* pTextBox);                                                     // 0x004FB950

void __cdecl MAINMENUS_CreateMultiplayerScreen();                                                                                // 0x004301A0

unsigned int __stdcall SStrHashHT(const char* szPath);                                           // 0x00414150

int __fastcall sub_00526590_Compare(const Unicode* pString1, const Unicode* pString2);                      // 0x00526590

int __fastcall CHARSEL_Connect(D2ConfigStrc* pRecord, int bFlag, int nMode);                    // 0x0043C180

int __cdecl MAINMENUS_HasSaveFiles();                                                                    // 0x00430BC0

void __cdecl MAINMENUS_ReturnToCharSelect();                                                                                // 0x0042FDD0

void __cdecl MAINMENUS_ShowLoginScreen();                                                                // 0x00435330

void __cdecl MAINMENUS_CreateScreen();                                                                   // 0x004325B0

char gszOldPassword[24];                                                                           // 0x00779550

int gbConnectCancelled; // 0x007795F4

typedef unsigned short U16;

struct U16Cell
{
    U16 value;

};

typedef char U16_is_two[(sizeof(U16)==2)?1:-1];

typedef char Cell_size[(sizeof(U16Cell)==2)?1:-1];

typedef char Cell_value_zero[((unsigned int)&((U16Cell*)0)->value==0)?1:-1];

struct UiControl;

extern "C" int __cdecl sub_00525150_Language();

extern "C" void __fastcall sub_004F9740_ControlFlag(UiControl* control,int value);

extern "C" int __fastcall sub_00526800_UnicodeLength(const U16* text);

extern "C" UiControl* gControl;

extern "C" const U16Cell gUpperTable[];

extern "C" int gLayout_00709C48; // 0x00709C48

extern "C" int gLayout_007091F8; // 0x007091F8

extern "C" int gLayout_00709228; // 0x00709228

extern "C" int gLayout_00709258; // 0x00709258

extern "C" int gLayout_007092E8; // 0x007092E8

extern "C" int gLayout_00709318; // 0x00709318

extern "C" int gLayout_00709EE8; // 0x00709EE8

extern "C" int gLayout_0070B2C8; // 0x0070B2C8

extern "C" int gLayout_0070B2F8; // 0x0070B2F8

extern "C" int gLayout_0070B088; // 0x0070B088

extern "C" int gLayout_0070B4A8; // 0x0070B4A8

extern "C" int gLayout_0070B0E8; // 0x0070B0E8

extern "C" int gLayout_0070B148; // 0x0070B148

extern "C" int gLayout_0070B1A8; // 0x0070B1A8

extern "C" int gLayout_0070BDA8; // 0x0070BDA8

extern "C" int gLayout_0070BF58; // 0x0070BF58

D2WinControlStrc* gpControl_00779968; // 0x00779968

int gnFlag_007798D4; // 0x007798D4

void* gpfnArchiveLoader; // 0x007798D8

int gbConnectResult; // 0x0077959C

D2WinControlStrc* gpControl_00779344; // 0x00779344

D2WinControlStrc* gpAddressEdit; // 0x00779958

char gszLastTcpIpAddress[255]; // 0x007795F8

int __stdcall MAINMENUS_OnCancel2(int nArg); // 0x00432040

int __stdcall MAINMENUS_OnLoginScreen(int nArg); // 0x00432300

D2WinControlStrc* gpCreatePasswordEdit; // 0x00779340

D2WinControlStrc* gpChangePwAccountEdit; // 0x007799BC

D2WinControlStrc* gpOldPasswordEdit; // 0x007799C0

D2WinControlStrc* gpNewPasswordConfirmEdit; // 0x007799C4

D2WinControlStrc* gpNewPasswordEdit; // 0x007799C8

D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

static int gnWaitDone; // 0x00779994

struct D2WinAnimImageStrc;

int __stdcall ANIMIMAGE_SetIsRunning(D2WinAnimImageStrc* pAnimImage, int bIsRunning); // 0x00500810

int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg);                                            // 0x004FA470

void __cdecl MAINMENUS_ShowLocalAddress();                                                               // 0x0042FF20

void __cdecl MAINMENUS_UpdateTwoEditOk(); // 0x00436CF0

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

#pragma intrinsic(strcpy)

extern D2ComInterfaceStrc* gpFuncTable_0077ABF0;                                                      // 0x0077ABF0

int gnLaunchMode;                                                                                  // 0x007795EC

const char* __fastcall FOG_GetHostIPAddress(); // 0x0040DF60

void __cdecl MAINMENUS_ShowMainMenu();                                                                                // 0x004336C0

void __cdecl MAINMENUS_CreateCharCreateScreen();                                                                                // 0x00435580

int gnControlCountA; // 0x00779948

D2WinControlStrc* __stdcall CONTROL_Create(D2LaunchControlTemplateStrc* pTemplate); // 0x004F93C0

D2WinControlStrc* gapControlsA[0x40]; // 0x00779450

int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9140

extern int gbPaletteBusy; // 0x00779970

extern "C" const char gszFeCharPalDat[]; // 0x006D39E8

void __cdecl CHARSEL_FreeCharList(); // 0x00438EA0

void __cdecl CHARSEL_FreeCache(); // 0x00437B90

int gbFeCharPalette; // 0x007795F0

D2CelFileStrc* gpPopUpWideCelFile;                                                                        // 0x007797A0

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

D2CelFileStrc* gpPopUpLargestCelFile;                                                                        // 0x007797A4

D2CelFileStrc* gpTileableDialogCelFile;                                                                        // 0x007797A8

D2CelFileStrc* gpPopUpOk2CelFile;                                                                        // 0x007797AC

D2CelFileStrc* gpPopUpOkCancelCelFile;                                                                        // 0x00779780

D2CelFileStrc* gpPopUpOkCancel2CelFile;                                                                        // 0x00779784

D2CelFileStrc* gpOkCancelButtonBlankCelFile;                                                                        // 0x007797B0

D2CelFileStrc* gpCancelButtonBlankCelFile;                                                                        // 0x007797B4

D2CelFileStrc* gpSelectCharArrowsCelFile;                                                                        // 0x00779788

D2CelFileStrc* gpRealmSelectCelFile;                                                                        // 0x0077978C

D2CelFileStrc* gpRealmSelectButtonThinCelFile;                                                                        // 0x00779790

D2CelFileStrc* gpPasswordCelFile;                                                                        // 0x007797B8

D2CelFileStrc* gpCreateNewCharImageCelFile;                                                                        // 0x00779794

extern D2CelFileStrc* gapCellFiles_00779808[5]; // 0x00779808

extern D2CelFileStrc* gapCellFiles_0077981C[5]; // 0x0077981C

extern D2CelFileStrc* gapCellFiles_007797E0[5]; // 0x007797E0

extern D2CelFileStrc* gapCellFiles_007797F4[5]; // 0x007797F4

extern D2CelFileStrc* gapCellFiles_00779830[5]; // 0x00779830

extern D2CelFileStrc* gapCellFiles_00779844[5]; // 0x00779844

extern D2CelFileStrc* gapCellFiles_00779858[5]; // 0x00779858

extern D2CelFileStrc* gapCellFiles_00779888[3]; // 0x00779888

extern D2CelFileStrc* gapCellFiles_0077989C[3]; // 0x0077989C

D2CelFileStrc* gpBlizNoCelFile;                                                                        // 0x007796F8

D2CelFileStrc* gpTrademarkCelFile;                                                                        // 0x007796FC

D2CelFileStrc* gpDiablo2LogoCelFile;                                                                        // 0x00779704

D2CelFileStrc* gpD2LogoBlackLeftCelFile;                                                                        // 0x00779708

D2CelFileStrc* gpD2LogoFireLeftCelFile;                                                                        // 0x0077970C

D2CelFileStrc* gpD2LogoBlackRightCelFile;                                                                        // 0x00779710

D2CelFileStrc* gpD2LogoFireRightCelFile;                                                                        // 0x00779714

D2CelFileStrc* gpTitleScreenCelFile;                                                                        // 0x00779718

D2CelFileStrc* gpCursorOHandCelFile;                                                                        // 0x0077971C

D2CelFileStrc* gpCreditsBckgCelFile;                                                                        // 0x00779720

D2CelFileStrc* gpRealmSelectButtonCelFile;                                                                        // 0x0077972C

D2CelFileStrc* gpTallButtonBlankCelFile;                                                                        // 0x00779730

D2CelFileStrc* gpCharacterSelectScreenExpCelFile;                                                                        // 0x00779734

D2CelFileStrc* gpWideButtonBlankCelFile;                                                                        // 0x00779738

D2CelFileStrc* gpMediumButtonBlankCelFile;                                                                        // 0x0077973C

D2CelFileStrc* gpShortButtonBlankCelFile;                                                                        // 0x00779740

D2CelFileStrc* gpTextBox2CelFile;                                                                        // 0x00779748

D2CelFileStrc* gp3WideButtonBlankCelFile;                                                                        // 0x0077974C

D2CelFileStrc* gpEditTextBoxWideCelFile;                                                                        // 0x00779750

D2CelFileStrc* gpWideButtonBlank02CelFile;                                                                        // 0x00779754

D2CelFileStrc* gpNarrowButtonBlankCelFile;                                                                        // 0x00779758

D2CelFileStrc* gpGWListBoxCelFile;                                                                        // 0x0077975C

D2CelFileStrc* gpTermsOfUseBckgCelFile;                                                                        // 0x00779764

D2CelFileStrc* gpCharSelectBckgCelFile;                                                                        // 0x00779768

D2CelFileStrc* gpDifficultyLevelsCelFile;                                                                        // 0x0077976C

D2CelFileStrc* gpCinematicsSelectionCelFile;                                                                        // 0x00779770

D2CelFileStrc* gpCinematicsSelectionExpCelFile;                                                                        // 0x00779774

D2CelFileStrc* gpCharSelectBoxCelFile;                                                                        // 0x00779778

D2CelFileStrc* gpCharSelectBoxGreyCelFile;                                                                        // 0x0077977C

D2CelFileStrc* gpPopUpOkCelFile;                                                                        // 0x00779798

D2CelFileStrc* gpPopUp340x224CelFile;                                                                        // 0x0077979C

D2CelFileStrc* gpRealmBckgCelFile;                                                                        // 0x007797C8

D2CelFileStrc* gpJoinGameScrollBarsCelFile;                                                                        // 0x007797CC

D2CelFileStrc* gpTcpIpBckgCelFile;                                                                        // 0x007797D0

D2CelFileStrc* gpIPAddressBoxCelFile;                                                                        // 0x007797D4

D2CelFileStrc* gpDownloadPatchBckgCelFile;                                                                        // 0x007797D8

D2CelFileStrc* gpDownloadPatchBall2CelFile;                                                                        // 0x007797DC

extern D2CelFileStrc* gpCellFile_00779700; // 0x00779700

extern D2CelFileStrc* gpFireCelFile; // 0x00779728

extern D2CelFileStrc* gpMediumSelButtonBlankCelFile; // 0x00779744

extern D2CelFileStrc* gpTextBoxCelFile; // 0x007797BC

extern D2CelFileStrc* gpClickBoxCelFile; // 0x007797C0

extern D2CelFileStrc* gpJoinGameClickBoxGreyCelFile; // 0x007797C4

extern D2CelFileStrc* gpBaFwSCelFile; // 0x007798B0

extern D2CelFileStrc* gpPaFwSCelFile; // 0x007798C4

extern D2CelFileStrc* gpCharacterCreateCelFile; // 0x00779724

extern int gnGatewayValue_007795BC; // 0x007795BC

void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall FOG_CloseFile(void* hFile);                                                         // 0x004069A0

void __cdecl MAINMENUS_FlushInput();                                                                     // 0x004317D0

void __cdecl sub_00430520();                                                                                // 0x00430520

void __stdcall MAINMENUS_CreateLevelScreen(int nLevel);                                                                    // 0x004313D0

void __cdecl MAINMENUS_ShowCurrentGateway();                                                                                // 0x00431AF0

void __cdecl MAINMENUS_CreateCharacter();                                                                                // 0x004365B0

void __cdecl CHARSEL_DisconnectBattleNet();                                                                                // 0x0043B9A0

void __fastcall sub_0043C6A0(int bSet);                                                                     // 0x0043C6A0

void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField);                                                 // 0x00525260

D2WinControlStrc* gpOkButton_00779330; // 0x00779330

D2WinControlStrc* gpControl_007795AC; // 0x007795AC

int gbFlag_00779984; // 0x00779984

D2CelFileStrc* gapAssassinCelFiles;                                                                        // 0x007797E0

D2CelFileStrc* gpAsNu2CelFile; // 0x007797E4

D2CelFileStrc* gpAsFwCelFile; // 0x007797E8

D2CelFileStrc* gpAsNu3CelFile; // 0x007797EC

D2CelFileStrc* gpAsBwCelFile; // 0x007797F0

D2CelFileStrc* gapDruidCelFiles;                                                                        // 0x007797F4

D2CelFileStrc* gpDzNu2CelFile; // 0x007797F8

D2CelFileStrc* gpDzFwCelFile; // 0x007797FC

D2CelFileStrc* gpDzNu3CelFile; // 0x00779800

D2CelFileStrc* gpDzBwCelFile; // 0x00779804

D2CelFileStrc* gapAmazonCelFiles;                                                                        // 0x00779808

D2CelFileStrc* gpAmNu2CelFile; // 0x0077980C

D2CelFileStrc* gpAmFwCelFile; // 0x00779810

D2CelFileStrc* gpAmNu3CelFile; // 0x00779814

D2CelFileStrc* gpAmBwCelFile; // 0x00779818

D2CelFileStrc* gapNecromancerCelFiles;                                                                        // 0x0077981C

D2CelFileStrc* gpNeNu2CelFile; // 0x00779820

D2CelFileStrc* gpNeFwCelFile; // 0x00779824

D2CelFileStrc* gpNeNu3CelFile; // 0x00779828

D2CelFileStrc* gpNeBwCelFile; // 0x0077982C

D2CelFileStrc* gapBarbarianCelFiles;                                                                        // 0x00779830

D2CelFileStrc* gpBaNu2CelFile; // 0x00779834

D2CelFileStrc* gpBaFwCelFile; // 0x00779838

D2CelFileStrc* gpBaNu3CelFile; // 0x0077983C

D2CelFileStrc* gpBaBwCelFile; // 0x00779840

D2CelFileStrc* gapSorceressCelFiles;                                                                        // 0x00779844

D2CelFileStrc* gpSoNu2CelFile; // 0x00779848

D2CelFileStrc* gpSoFwCelFile; // 0x0077984C

D2CelFileStrc* gpSoNu3CelFile; // 0x00779850

D2CelFileStrc* gpSoBwCelFile; // 0x00779854

D2CelFileStrc* gapPaladinCelFiles;                                                                        // 0x00779858

D2CelFileStrc* gpPaNu2CelFile; // 0x0077985C

D2CelFileStrc* gpPaFwCelFile; // 0x00779860

D2CelFileStrc* gpPaNu3CelFile; // 0x00779864

D2CelFileStrc* gpPaBwCelFile; // 0x00779868

D2CelFileStrc* gapNecromancerSCelFiles;                                                                        // 0x00779888

D2CelFileStrc* gpNeNu3SCelFile; // 0x0077988C

D2CelFileStrc* gpNeBwSCelFile; // 0x00779890

D2CelFileStrc* gapSorceressSCelFiles;                                                                        // 0x0077989C

D2CelFileStrc* gpSoNu3SCelFile; // 0x007798A0

D2CelFileStrc* gpSoBwSCelFile; // 0x007798A4

struct D2ConfigStrc;

struct D2FileTimeStrc;

struct D2LaunchSlotStrc;

struct D2MenuListStrc;

int __cdecl STRTABLE_GetLanguage(); // 0x00525150

int __cdecl D2Win_10003(); // 0x004F9050

void __stdcall D2Win_10004(int nResolution); // 0x004F9060

void __cdecl MAINMENUS_CreateVideoScreen(); // 0x0042FB20

void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70

int __fastcall ARCHIVE_LoadExpansionArchives(int (__cdecl* pfnPlayDisc)(), int (__cdecl* pfnExpansionDisc)(), int nUnused, D2ConfigStrc* pCfg); // 0x004FAEC0

int __cdecl MAINMENUS_ShowArchiveMessage(); // 0x00431A00

int __cdecl MAINMENUS_PromptPlayDisc(); // 0x00434220

int __cdecl MAINMENUS_PromptExpansionDisc(); // 0x004342E0

extern D2ConfigStrc* gpConfig_007795D4; // 0x007795D4

extern "C" const char gszMainMenusFile[]; // 0x006D41C0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0

int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0

int __fastcall FOG_FReadFile(void* hFile, void* pBuffer, int nToRead, int* pnRead, void* pOverlapped, int nArg7, int nArg6); // 0x00406900

int __fastcall FOG_FGetFileSize(void* hFile, unsigned int* pnSizeHigh); // 0x00406930

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall CHARSEL_SwapUnicodeBytes(Unicode* pText, int nLength); // 0x0042E5D0

Unicode* __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

extern "C" int __cdecl isalpha(int c); // 0x00686DA5

Unicode* __stdcall MAINMENUS_LoadCreditsText(int* pnLength); // 0x00430CD0

void __cdecl MAINMENUS_FillCreditsList(); // 0x00430C80

void __cdecl MAINMENUS_SyncCreditsLists(); // 0x00430EF0

extern "C" const char gszDiabloII[]; // 0x006CC8B8

extern "C" const char gszDottedQuadFormat[]; // 0x006CDEA4

extern "C" const char gszAuxBattleNet[]; // 0x006D4164

extern "C" const char gszLastTcpIp[]; // 0x006D4224

extern "C" const char gszDottedQuadLongFormat[]; // 0x006D4174

extern "C" const char gszEng[]; // 0x006D41A4

extern "C" const char gszAuxAddressFormat[]; // 0x006D4868

extern "C" const char gszIntroFormatEng[]; // 0x006D4878

extern "C" const char gszIntroFormat[]; // 0x006D4894

extern "C" const char gszVersionSuffix[]; // 0x006D48D0

extern "C" const char gszVersionFormat[]; // 0x006D48D4

extern "C" const char gszDotsFormat[]; // 0x006D4D9C

extern "C" const char gszDots[]; // 0x006D4DA4

extern "C" const char gszBlizNoCelPath[]; // 0x006D4100

extern "C" const char gszTrademarkScreenExpCelPath[]; // 0x006D40DC

extern "C" const char gszTrademarkCelPath[]; // 0x006D40C0

extern "C" const char gszCursorOHandCelPath[]; // 0x006D40AC

extern "C" const char gszDiablo2LogoCelPath[]; // 0x006D4094

extern "C" const char gszD2LogoBlackLeftCelPath[]; // 0x006D4074

extern "C" const char gszD2LogoFireLeftCelPath[]; // 0x006D4054

extern "C" const char gszD2LogoBlackRightCelPath[]; // 0x006D4034

extern "C" const char gszD2LogoFireRightCelPath[]; // 0x006D4014

extern "C" const char gszGameSelectScreenExpCelPath[]; // 0x006D3FF0

extern "C" const char gszTitleScreenCelPath[]; // 0x006D3FD4

extern "C" const char gszCreditsBckgExpandCelPath[]; // 0x006D3FB0

extern "C" const char gszCreditsBckgCelPath[]; // 0x006D3F90

extern "C" const char gszWideButtonBlankCelPath[]; // 0x006D3F70

extern "C" const char gszWideButtonBlank02CelPath[]; // 0x006D3F4C

extern "C" const char gszNarrowButtonBlankCelPath[]; // 0x006D3F28

extern "C" const char gszGWListBoxCelPath[]; // 0x006D3F0C

extern "C" const char gszRealmSelectButtonCelPath[]; // 0x006D3EE8

extern "C" const char gszTallButtonBlankCelPath[]; // 0x006D3EC4

extern "C" const char gszCharacterSelectScreenExpCelPath[]; // 0x006D3E98

extern "C" const char gszCinematicsSelectionExpCelPath[]; // 0x006D3E70

extern "C" const char gszMediumButtonBlankCelPath[]; // 0x006D3E4C

extern "C" const char gszShortButtonBlankCelPath[]; // 0x006D3E28

extern "C" const char gszTextBox2CelPath[]; // 0x006D3E10

extern "C" const char gsz3WideButtonBlankCelPath[]; // 0x006D3DF0

extern "C" const char gszTermsOfUseBckgCelPath[]; // 0x006D3DD0

extern "C" const char gszCharSelectBckgCelPath[]; // 0x006D3DB0

extern "C" const char gszDifficultyLevelsCelPath[]; // 0x006D3D8C

extern "C" const char gszCinematicsSelectionCelPath[]; // 0x006D3D68

extern "C" const char gszCharSelectBoxCelPath[]; // 0x006D3D48

extern "C" const char gszCharSelectBoxGreyCelPath[]; // 0x006D3D24

extern "C" const char gszCreateNewCharImageCelPath[]; // 0x006D3D00

extern "C" const char gszPopUpOkCelPath[]; // 0x006D3CE8

extern "C" const char gszPopUp340x224CelPath[]; // 0x006D3CC8

extern "C" const char gszPopUpWideCelPath[]; // 0x006D3CAC

extern "C" const char gszPopUpLargestCelPath[]; // 0x006D3C90

extern "C" const char gszTileableDialogCelPath[]; // 0x006D3C70

extern "C" const char gszPopUpOk2CelPath[]; // 0x006D3C58

extern "C" const char gszPopUpOkCancelCelPath[]; // 0x006D3C38

extern "C" const char gszPopUpOkCancel2CelPath[]; // 0x006D3C18

extern "C" const char gszOkCancelButtonBlankCelPath[]; // 0x006D3BF4

extern "C" const char gszCancelButtonBlankCelPath[]; // 0x006D3BD0

extern "C" const char gszSelectCharArrowsCelPath[]; // 0x006D3BAC

extern "C" const char gszRealmSelectCelPath[]; // 0x006D3B8C

extern "C" const char gszCurRealmCelPath[]; // 0x006D3B74

extern "C" const char gszRealmSelectButtonThinCelPath[]; // 0x006D3B4C

extern "C" const char gszNarrowButtonBlank02CelPath[]; // 0x006D3B28

extern "C" const char gszPasswordCelPath[]; // 0x006D3B0C

extern "C" const char gszRealmBckgCelPath[]; // 0x006D3AF0

extern "C" const char gszJoinGameScrollBarsCelPath[]; // 0x006D3ACC

extern "C" const char gszTcpIpScreenCelPath[]; // 0x006D3AB0

extern "C" const char gszTcpIpBckgCelPath[]; // 0x006D3A94

extern "C" const char gszIPAddressBoxCelPath[]; // 0x006D3A78

extern "C" const char gszDownloadPatchBckgCelPath[]; // 0x006D3A54

extern "C" const char gszDownloadPatchBall2CelPath[]; // 0x006D3A30

extern "C" const char gszEditTextBoxWideCelPath[]; // 0x006D3A10

extern "C" const char gszMediumSelButtonBlankCelPath[]; // 0x006D4844

extern "C" const char gszCharacterCreationScreenExpCelPath[]; // 0x006D4818

extern "C" const char gszCharacterCreateCelPath[]; // 0x006D47F8

extern "C" const char gszFireCelPath[]; // 0x006D47E4

extern "C" const char gszTextBoxCelPath[]; // 0x006D47CC

extern "C" const char gszClickBoxCelPath[]; // 0x006D47B4

extern "C" const char gszJoinGameClickBoxGreyCelPath[]; // 0x006D4790

extern "C" const char gszAsNu1CelPath[]; // 0x006D4770

extern "C" const char gszAsNu2CelPath[]; // 0x006D4750

extern "C" const char gszAsFwCelPath[]; // 0x006D4730

extern "C" const char gszAsNu3CelPath[]; // 0x006D4710

extern "C" const char gszAsBwCelPath[]; // 0x006D46F0

extern "C" const char gszDzNu1CelPath[]; // 0x006D46D4

extern "C" const char gszDzNu2CelPath[]; // 0x006D46B8

extern "C" const char gszDzFwCelPath[]; // 0x006D469C

extern "C" const char gszDzNu3CelPath[]; // 0x006D4680

extern "C" const char gszDzBwCelPath[]; // 0x006D4664

extern "C" const char gszAmNu1CelPath[]; // 0x006D4648

extern "C" const char gszAmNu2CelPath[]; // 0x006D462C

extern "C" const char gszAmFwCelPath[]; // 0x006D4610

extern "C" const char gszAmNu3CelPath[]; // 0x006D45F4

extern "C" const char gszAmBwCelPath[]; // 0x006D45D8

extern "C" const char gszNeNu1CelPath[]; // 0x006D45B4

extern "C" const char gszNeNu2CelPath[]; // 0x006D4590

extern "C" const char gszNeFwCelPath[]; // 0x006D4570

extern "C" const char gszNeNu3CelPath[]; // 0x006D454C

extern "C" const char gszNeBwCelPath[]; // 0x006D452C

extern "C" const char gszBaNu1CelPath[]; // 0x006D450C

extern "C" const char gszBaNu2CelPath[]; // 0x006D44EC

extern "C" const char gszBaFwCelPath[]; // 0x006D44CC

extern "C" const char gszBaNu3CelPath[]; // 0x006D44AC

extern "C" const char gszBaBwCelPath[]; // 0x006D448C

extern "C" const char gszSoNu1CelPath[]; // 0x006D446C

extern "C" const char gszSoNu2CelPath[]; // 0x006D444C

extern "C" const char gszSoFwCelPath[]; // 0x006D442C

extern "C" const char gszSoNu3CelPath[]; // 0x006D440C

extern "C" const char gszSoBwCelPath[]; // 0x006D43EC

extern "C" const char gszPaNu1CelPath[]; // 0x006D43CC

extern "C" const char gszPaNu2CelPath[]; // 0x006D43AC

extern "C" const char gszPaFwCelPath[]; // 0x006D4390

extern "C" const char gszPaNu3CelPath[]; // 0x006D4370

extern "C" const char gszPaBwCelPath[]; // 0x006D4354

extern "C" const char gszSoFwSCelPath[]; // 0x006D4334

extern "C" const char gszSoNu3SCelPath[]; // 0x006D4314

extern "C" const char gszSoBwSCelPath[]; // 0x006D42F4

extern "C" const char gszNeFwSCelPath[]; // 0x006D42D0

extern "C" const char gszNeNu3SCelPath[]; // 0x006D42AC

extern "C" const char gszNeBwSCelPath[]; // 0x006D4288

extern "C" const char gszBaFwSCelPath[]; // 0x006D4268

extern "C" const char gszPaFwSCelPath[]; // 0x006D4248

struct D2MenuListStrc
{
    int unk_00;
    int nCount;
};

extern "C" unsigned int __cdecl strlen(const char* szText);

extern "C" void __cdecl qsort(void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfnCompare)(const void*, const void*)); // 0x00685B50

int __stdcall MAINMENUS_StopLoop(int nArg); // 0x00431D10

int __cdecl MAINMENUS_CompareNames(const void* pEntry1, const void* pEntry2); // 0x00430B00

extern D2MenuListStrc* gpMenuList; // 0x007795C0

int __stdcall MAINMENUS_PollCharLogon(int nArg); // 0x00432FE0

int __cdecl sub_0043BF60(); // 0x0043BF60

int __cdecl MCPCONNECT_QueryAddress(); // 0x00449B30

int __cdecl GAME_GetConnectError(); // 0x00449C00

int __stdcall CHATDLG_RequestCharLogon(const char* szName); // 0x00449E10

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

extern char gaGlobal_007089C4[]; // 0x007089C4

extern void* gpGlobal_0070B738; // 0x0070B738

int gnLaunchState; // 0x007795E8

static void MAINMENUS_SetModeFlags(char nMode); // 0x00431E70

int __stdcall MAINMENUS_IsRestrictedChar(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FDE0

int __stdcall sub_0042FE60_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FE60

int __stdcall MAINMENUS_OnLoginChanged(int nArg); // 0x00433BE0

int __cdecl CHARSEL_IsBattleNetConnected(); // 0x0043B840

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00

void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50

void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0

int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10

extern int gnValue_00779980; // 0x00779980

int __stdcall MAINMENUS_FilterNameChar(D2WinControlStrc* pControl, int bAllowSep, const char* pChar); // 0x00430590

void __cdecl MAINMENUS_LoadCharCreateCells(); // 0x004326F0

int __stdcall MAINMENUS_OnNameChanged(int nArg); // 0x00433BD0

void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0

void __stdcall CONTROL_SetEscapeButton(void* a1); // 0x004FA450

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740

extern "C" const char gszFecharPalDat_006D39E8[]; // 0x006D39E8

extern int gnGlobal_00708D0C; // 0x00708D0C

extern int gnGlobal_0070CB80; // 0x0070CB80

extern D2WinControlStrc* gpOkButton; // 0x00779330

extern D2WinControlStrc* gpControl_00779348; // 0x00779348

extern D2WinControlStrc* gpControl_00779568; // 0x00779568

extern D2WinControlStrc* gpControl_00779598; // 0x00779598

extern D2WinControlStrc* gpControl_007795B4; // 0x007795B4

extern D2WinControlStrc* gpControl_007795C8; // 0x007795C8

extern D2WinControlStrc* gpControl_007795D8; // 0x007795D8

extern D2WinControlStrc* gpControl_007795DC; // 0x007795DC

const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinControlStrc*); // 0x004FDD90

D2WinControlStrc* gpPasswordEdit; // 0x00779334

D2WinControlStrc* gpAccountEdit; // 0x0077958C

D2WinControlStrc* gpControl_00779594; // 0x00779594

static int s_bGatewayFlag_00779954; // 0x00779954

D2WinControlStrc* gpControl_0077933C; // 0x0077933C

D2WinControlStrc* gpNameEdit; // 0x0077934C

D2WinControlStrc* gapClassImages; // 0x0077956C

D2WinControlStrc* gpControl_00779570; // 0x00779570

D2WinControlStrc* gpControl_00779574; // 0x00779574

D2WinControlStrc* gpControl_00779578; // 0x00779578

D2WinControlStrc* gpControl_0077957C; // 0x0077957C

D2WinControlStrc* gpControl_00779580; // 0x00779580

D2WinControlStrc* gpControl_00779584; // 0x00779584

D2WinControlStrc* gpControl_007795B0; // 0x007795B0

D2WinControlStrc* gpControl_007795B8; // 0x007795B8

D2WinControlStrc* gpControl_007795C4; // 0x007795C4

D2WinControlStrc* gpControl_007795CC; // 0x007795CC

int gnGlobal_00779DA4; // 0x00779DA4

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall GetDiskFreeSpaceA(const char* szRootPathName, unsigned long* pnSectorsPerCluster, unsigned long* pnBytesPerSector, unsigned long* pnFreeClusters, unsigned long* pnTotalClusters); // 0x006CC270

int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050

int __stdcall SRegSaveString(const char* szKeyName, const char* szValueName, unsigned int nFlags, const char* szString); // 0x00415070

int __cdecl MAINMENUS_ShowTerms(); // 0x00433810

int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl); // 0x004F95C0

const Unicode* __fastcall sub_004FDD90_GetEditText(D2WinControlStrc* pControl); // 0x004FDD90

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2); // 0x005264F0

void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540

extern "C" const unsigned char gabDefault[]; // 0x006D4D88

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

int __stdcall MAINMENUS_PollCharCreate(int nArg); // 0x00432FA0

char* __cdecl GAME_GetPreferredRealm(); // 0x00437D00

int __stdcall CHATDLG_RequestCharCreate(const char* szName, int nClass, int nFlags); // 0x00449DF0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __cdecl MAINMENUS_LoadFrontEndCells(); // 0x0042E6D0

int __cdecl MAINMENUS_InitAuxBattleNet(); // 0x0042FA40

int __cdecl MAINMENUS_GetAuxBattleNetFlag(); // 0x0042FAB0

int __cdecl MAINMENUS_SaveExists(); // 0x00431F70

void __cdecl MAINMENUS_PlayIntro(); // 0x004334E0

int __stdcall MAINMENUS_JoinTcpIp(int nUnused); // 0x00434790

int __stdcall MAINMENUS_OnCharCreateOk(int nUnused); // 0x004369F0

class BNGatewayAccess;

int __fastcall sub_004FB950_GetFirstVisible(D2WinControlStrc* pControl); // 0x004FB950

void __cdecl MAINMENUS_PlayIntroVideo(); // 0x00433640

int __stdcall MAINMENUS_LoopCallback(int nArg); // 0x00431950

void __fastcall MAINMENUS_CreateExpansionDiscPopup(int bFlag); // 0x00431570

class BNGatewayAccess
{
public:
    const char* __stdcall Name(int nGateway);

    char m_szEmpty[4];
    int m_bModified;
    int m_nNumGateways;
    int m_nCurGateway;
};

int __fastcall D2Win_10055(D2WinControlStrc* pTextBox); // 0x004FBAB0

void __fastcall sub_004FB9D0_Select(D2WinControlStrc* pControl, int nLine); // 0x004FB9D0

int __stdcall SFileOpenArchive(const char* szMpqName, int nPriority, unsigned int dwFlags, void** phMpq); // 0x0041BA60

int __stdcall SFileCloseArchive(void* hMpq); // 0x00419A80

void __fastcall AUTOMAP_InitCharSaveHeader(char* szName, char nClass, char* pData, int nFlags); // 0x0043C540

int __fastcall CHATDLG_WriteSaveHeader(const char* szName); // 0x0043C6B0

void __cdecl MAINMENUS_CreateRealmCharacter(); // 0x00435E10

void __cdecl MAINMENUS_SetDone(); // 0x0042F6C0

int gnListPos; // 0x0077996C

void* gpfnArchiveLoader2; // 0x007798DC

int gnValue_0077994C; // 0x0077994C

int gnValue_00779950; // 0x00779950

int gbGatewayFlag; // 0x00779954

int __cdecl MAINMENUS_FreeSlots();

D2WinControlStrc* gpGatewayList; // 0x00779590

static void MAINMENUS_StoreAccountTexts(D2WinControlStrc* pAccountEdit, D2WinControlStrc* pPasswordEdit);

int gdwGlobal_007799D8; // 0x007799D8

int __stdcall MAINMENUS_ChangePasswordOk(int nArg);

int __stdcall MAINMENUS_LoginOk(int nArg);

int __stdcall MAINMENUS_CreateAccountOk(int nArg);

static int MAINMENUS_IsArchiveFilePresent(const char* szFile); // 0x0042FCE0

static void MAINMENUS_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258

void __cdecl MAINMENUS_FreeFrontEndCells();                                                              // 0x0042EF50

int __cdecl sub_004309B0_ClearState();                                                                      // 0x004309B0

void __stdcall MAINMENUS_IdleLoopCallback(unsigned long nArg);                                               // 0x00430BB0

void __cdecl MAINMENUS_PlayIntroVideos();                                                                // 0x00435230

int __fastcall CHARSEL_InitFuncTable(D2ConfigStrc* pRecord);                                     // 0x0043B7A0

int __stdcall WINDOW_CenterWindow(int nResolution);                                                   // 0x004F5BC0

int __fastcall D2Win_10015();                                                                               // 0x004F8FE0

int __stdcall CURSOR_SetCellFile(D2CelFileStrc* pCellFile);                                                 // 0x004F9160

void __stdcall D2Win_SetQuitCallback(int (__cdecl* a1)());                                                            // 0x004F9180

int __stdcall D2Win_RunMessageLoop(void (__stdcall* pCallback)(unsigned long));                                      // 0x004FA590

void* __stdcall sub_004FAC80(int nArg);                                                                     // 0x004FAC80

void __cdecl D2SOUNDFAST_InitWaveSlots();                                                                                // 0x00514DB0

void __fastcall D2SOUNDFAST_PreloadWave(const char* szFile);                                                           // 0x00514E10

int __cdecl D2SOUNDFAST_IsAnyWavePlaying();                                                                // 0x00514FB0

void __cdecl D2SOUNDFAST_FreeWaveSlots();                                                                                // 0x00515070

void __stdcall D2Win_10029(int a1); // 0x004FA410

void __cdecl sub_0042F880_DestroyControls(); // 0x0042F880

extern D2WinControlStrc* gpControl_00779338; // 0x00779338

extern D2WinControlStrc* gpControl_00779588; // 0x00779588

extern D2WinControlStrc* gpControl_007795A0; // 0x007795A0

extern D2WinControlStrc* gpControl_007795A4; // 0x007795A4

void __cdecl sub_0042F800(); // 0x0042F800

void __cdecl sub_0042FA20(); // 0x0042FA20

// 0x00406870
void __fastcall MAINMENUS_InitStorm(int nDirectFlags, int nValue)
{
    SFileSetBasePath(".\\");
    SFileEnableDirectAccess(nDirectFlags);
    SFileSetIoErrorMode(0, 0);
    SFileEnableSeekOptimization(nValue);
    gnStormDirectFlags_0074C82C = nDirectFlags;
    int nChunkSize = 0x8000;
    StormGetOption(2, &nChunkSize, 4);
    int bEnable = 1;
    StormGetOption(1, &bEnable, 4);
    StormGetOption(3, &bEnable, 4);
}

// 0x0042E6A0
void __fastcall MAINMENUS_SetGatewayValue(int nValue)
{
    gnGatewayValue_007795BC = nValue;
}

// 0x0042E6B0
void __cdecl MAINMENUS_SetGatewayFlag()
{
    gbGatewayFlag = 1;
}

// 0x0042E6C0
int __cdecl MAINMENUS_GetGatewayFlag()
{
    return gbGatewayFlag;
}

// 0x0042E6D0
void __cdecl MAINMENUS_LoadFrontEndCells()
{
    char szPath[0x104];
// build: symbol ?gszDataGlobal@* 0x006D4118
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\blizno", gszDataGlobal);
    gpBlizNoCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademarkscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\trademark", gszDataGlobal);
    gpTrademarkCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\CURSOR\\ohand", gszDataGlobal);
    gpCursorOHandCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\Diablo2", gszDataGlobal);
    gpDiablo2LogoCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackLeft", gszDataGlobal);
    gpD2LogoBlackLeftCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireLeft", gszDataGlobal);
    gpD2LogoFireLeftCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoBlackRight", gszDataGlobal);
    gpD2LogoBlackRightCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\D2logoFireRight", gszDataGlobal);
    gpD2LogoFireRightCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\gameselectscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\TitleScreen", gszDataGlobal);
    gpTitleScreenCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckgexpand", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\CharSelect\\creditsbckg", gszDataGlobal);
    gpCreditsBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank", gszDataGlobal);
    gpWideButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\WideButtonBlank02", gszDataGlobal);
    gpWideButtonBlank02CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank", gszDataGlobal);
    gpNarrowButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\GWListBox", gszDataGlobal);
    gpGWListBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
    {
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselectbutton", gszDataGlobal);
        gpRealmSelectButtonCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\TallButtonBlank", gszDataGlobal);
        gpTallButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\CharSelect\\characterselectscreenEXP", gszDataGlobal);
        gpCharacterSelectScreenExpCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelectionEXP", gszDataGlobal);
        gpCinematicsSelectionExpCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumButtonBlank", gszDataGlobal);
    gpMediumButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\ShortButtonBlank", gszDataGlobal);
    gpShortButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox2", gszDataGlobal);
    gpTextBox2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\3WideButtonBlank", gszDataGlobal);
    gp3WideButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TermsofUseBckg", gszDataGlobal);
    gpTermsOfUseBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbckg", gszDataGlobal);
    gpCharSelectBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\DifficultyLevels", gszDataGlobal);
    gpDifficultyLevelsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CinematicsSelection", gszDataGlobal);
    gpCinematicsSelectionCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectbox", gszDataGlobal);
    gpCharSelectBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\charselectboxgrey", gszDataGlobal);
    gpCharSelectBoxGreyCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\CreateNewCharImage", gszDataGlobal);
    gpCreateNewCharImageCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK", gszDataGlobal);
    gpPopUpOkCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUp_340x224", gszDataGlobal);
    gpPopUp340x224CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpWide", gszDataGlobal);
    gpPopUpWideCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpLargest", gszDataGlobal);
    gpPopUpLargestCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\TileableDialog", gszDataGlobal);
    gpTileableDialogCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOK2", gszDataGlobal);
    gpPopUpOk2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel", gszDataGlobal);
    gpPopUpOkCancelCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\PopUpOKCancel2", gszDataGlobal);
    gpPopUpOkCancel2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\OkCancelButtonBlank", gszDataGlobal);
    gpOkCancelButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\CancelButtonBlank", gszDataGlobal);
    gpCancelButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\selectchararrows", gszDataGlobal);
    gpSelectCharArrowsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\Realmselect", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CurRealm", gszDataGlobal);
    gpRealmSelectCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\CharSelect\\RealmSelectbuttonthin", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\NarrowButtonBlank02", gszDataGlobal);
    gpRealmSelectButtonThinCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\CharSelect\\password", gszDataGlobal);
    gpPasswordCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\realmbckg", gszDataGlobal);
    gpRealmBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    sprintf(szPath, "%s\\UI\\FRONTEND\\joingamescrollbars", gszDataGlobal);
    gpJoinGameScrollBarsCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipscreen", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\UI\\FrontEnd\\tcpipbckg", gszDataGlobal);
    gpTcpIpBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\IPAddressBox", gszDataGlobal);
    gpIPAddressBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchbckg", gszDataGlobal);
    gpDownloadPatchBckgCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\downloadpatchball2", gszDataGlobal);
    gpDownloadPatchBall2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\EditTextBoxWide", gszDataGlobal);
    gpEditTextBoxWideCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x0042EF50
void __cdecl MAINMENUS_FreeFrontEndCells()
{
    ARCHIVE_FreeCellFile(gpBlizNoCelFile);
    ARCHIVE_FreeCellFile(gpTrademarkCelFile);
    ARCHIVE_FreeCellFile(gpCellFile_00779700);
    ARCHIVE_FreeCellFile(gpCursorOHandCelFile);
    ARCHIVE_FreeCellFile(gpDiablo2LogoCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoBlackLeftCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoFireLeftCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoBlackRightCelFile);
    ARCHIVE_FreeCellFile(gpD2LogoFireRightCelFile);
    ARCHIVE_FreeCellFile(gpTitleScreenCelFile);
    ARCHIVE_FreeCellFile(gpCreditsBckgCelFile);
    ARCHIVE_FreeCellFile(gpWideButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpWideButtonBlank02CelFile);
    ARCHIVE_FreeCellFile(gpNarrowButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpGWListBoxCelFile);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        ARCHIVE_FreeCellFile(gpRealmSelectButtonCelFile);
        ARCHIVE_FreeCellFile(gpTallButtonBlankCelFile);
        ARCHIVE_FreeCellFile(gpCharacterSelectScreenExpCelFile);
        ARCHIVE_FreeCellFile(gpCinematicsSelectionExpCelFile);
    }
    ARCHIVE_FreeCellFile(gpMediumButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpShortButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpTextBox2CelFile);
    ARCHIVE_FreeCellFile(gp3WideButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpTermsOfUseBckgCelFile);
    ARCHIVE_FreeCellFile(gpCharSelectBckgCelFile);
    ARCHIVE_FreeCellFile(gpDifficultyLevelsCelFile);
    ARCHIVE_FreeCellFile(gpCinematicsSelectionCelFile);
    ARCHIVE_FreeCellFile(gpCharSelectBoxCelFile);
    ARCHIVE_FreeCellFile(gpCharSelectBoxGreyCelFile);
    ARCHIVE_FreeCellFile(gpPopUpOkCelFile);
    ARCHIVE_FreeCellFile(gpPopUp340x224CelFile);
    ARCHIVE_FreeCellFile(gpPopUpWideCelFile);
    ARCHIVE_FreeCellFile(gpPopUpLargestCelFile);
    ARCHIVE_FreeCellFile(gpTileableDialogCelFile);
    ARCHIVE_FreeCellFile(gpPopUpOk2CelFile);
    ARCHIVE_FreeCellFile(gpPopUpOkCancelCelFile);
    ARCHIVE_FreeCellFile(gpPopUpOkCancel2CelFile);
    ARCHIVE_FreeCellFile(gpOkCancelButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpCancelButtonBlankCelFile);
    ARCHIVE_FreeCellFile(gpSelectCharArrowsCelFile);
    ARCHIVE_FreeCellFile(gpRealmSelectCelFile);
    ARCHIVE_FreeCellFile(gpRealmSelectButtonThinCelFile);
    ARCHIVE_FreeCellFile(gpPasswordCelFile);
    ARCHIVE_FreeCellFile(gpCreateNewCharImageCelFile);
    if (gpCharacterCreateCelFile)
    {
        ARCHIVE_FreeCellFile(gpCharacterCreateCelFile);
        gpCharacterCreateCelFile = 0;
        ARCHIVE_FreeCellFile(gpFireCelFile);
        ARCHIVE_FreeCellFile(gpMediumSelButtonBlankCelFile);
        ARCHIVE_FreeCellFile(gpTextBoxCelFile);
        ARCHIVE_FreeCellFile(gpClickBoxCelFile);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779808[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_0077981C[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779830[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779844[i]);
        for (int i = 0; i < 5; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779858[i]);
        for (int i = 0; i < 3; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_0077989C[i]);
        for (int i = 0; i < 3; ++i)
            ARCHIVE_FreeCellFile(gapCellFiles_00779888[i]);
        ARCHIVE_FreeCellFile(gpBaFwSCelFile);
        ARCHIVE_FreeCellFile(gpPaFwSCelFile);
        if (FOG_IsExpansion())
        {
            for (int i = 0; i < 5; ++i)
                ARCHIVE_FreeCellFile(gapCellFiles_007797E0[i]);
            for (int i = 0; i < 5; ++i)
                ARCHIVE_FreeCellFile(gapCellFiles_007797F4[i]);
            ARCHIVE_FreeCellFile(gpJoinGameClickBoxGreyCelFile);
        }
    }
    ARCHIVE_FreeCellFile(gpRealmBckgCelFile);
    ARCHIVE_FreeCellFile(gpJoinGameScrollBarsCelFile);
    ARCHIVE_FreeCellFile(gpTcpIpBckgCelFile);
    ARCHIVE_FreeCellFile(gpIPAddressBoxCelFile);
    ARCHIVE_FreeCellFile(gpDownloadPatchBckgCelFile);
    ARCHIVE_FreeCellFile(gpDownloadPatchBall2CelFile);
    ARCHIVE_FreeCellFile(gpEditTextBoxWideCelFile);
}

// 0x0042F2E0
int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2)
{
    char szPathA[0x104];
    char szPathB[0x104];
    gbPaletteBusy = 1;
    wsprintfA(szPathA, gszPathFormat_006D4124, gszDataGlobal, szFile1);
    wsprintfA(szPathB, gszPathFormat_006D4124, gszDataGlobal, szFile2);
    gbFeCharPalette = strcmp(szFile1, "palette\\fechar\\pal.dat") == 0;
    sub_004FB500(szPathA, szPathB);
    return 1;
}

// 0x0042F370
void __cdecl MAINMENUS_RestorePalette()
{
    if (gbPaletteBusy)
    {
        MAINMENUS_ReadPaletteFiles(gszFeCharPalDat, "palette\\fechar\\pal.pl2");
        gbPaletteBusy = 0;
    }
}

// 0x0042F3A0
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId)
{
    D2_ASSERT(gnControlCountA < 0x40, 0x610);
    D2WinControlStrc* pControl = CONTROL_Create(&gatControlTemplates[nTemplateId]);
    gapControlsA[gnControlCountA++] = pControl;
    return pControl;
}

// 0x0042F3F0
void __cdecl MAINMENUS_DestroyControls()
{
    for (int i = 0; i < gnControlCountA; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsA[i]);
    gnControlCountA = 0;
}

// 0x0042F430
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId)
{
    D2_ASSERT(gnControlCountB < 0x40, 0x627);
    D2WinControlStrc* pControl = CONTROL_Create(&gatControlTemplates[nId]);
    gapControlsB[gnControlCountB++] = pControl;
    return pControl;
}

// 0x0042F480
void __cdecl MAINMENUS_Reset()
{
    for (int i = 0; i < gnControlCountB; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsB[i]);
    gnValue_0077994C = 0;
    gnValue_00779950 = 0;
    gnControlCountB = 0;
    for (int i = 0; i < gnControlCountA; ++i)
        sub_004F95C0_ControlDestroy(&gapControlsA[i]);
    gnControlCountA = 0;
    BACKGROUND_SetCellFile(0);
    if (gbPaletteBusy)
    {
        MAINMENUS_ReadPaletteFiles(gszFeCharPalDat, "palette\\fechar\\pal.pl2");
        gbPaletteBusy = 0;
    }
    CHARSEL_FreeCharList();
    CHARSEL_FreeCache();
    D2Win_10029(1);
}

// 0x0042F540
void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2)
{
    D2_ASSERT(nButton1StringId, 0x746);
    int nButtons = 1;
    if (nButton2StringId)
        nButtons = 2;
    MAINMENUS_DestroyControls();
    switch (nButtons)
    {
    case 1:
    {
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xE7);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gatControlTemplates[0x11A].nStringId = nButton1StringId;
        if (bFlag2)
            gatControlTemplates[0x11A].nFlags = 0x1B;
        else
            gatControlTemplates[0x11A].nFlags = bFlag1 ? 0xD : 0;
        gatControlTemplates[0x11A].pfnCallback = pfnButton1;
        pControl = MAINMENUS_CreateFromTemplate(0x11A);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        break;
    }
    case 2:
    {
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0x119);
        D2Win_10033(pControl, 1);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gatControlTemplates[0x11B].nStringId = nButton1StringId;
        gatControlTemplates[0x11B].nFlags = bFlag1 ? 0xD : 0;
        gatControlTemplates[0x11B].pfnCallback = pfnButton1;
        pControl = MAINMENUS_CreateFromTemplate(0x11B);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        gatControlTemplates[0x11C].nStringId = nButton2StringId;
        gatControlTemplates[0x11C].nFlags = bFlag1 ? 0x1B : 0;
        gatControlTemplates[0x11C].pfnCallback = pfnButton2;
        pControl = MAINMENUS_CreateFromTemplate(0x11C);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        break;
    }
    }
    if (pTitle)
    {
        D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0x11D);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        sub_004FD060_SetText(pControl, pTitle);
    }
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(pTitle ? 0x11E : 0x11F);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FD060_SetText(pControl, pMessage);
}

// 0x0042F6C0
void __cdecl MAINMENUS_SetDone()
{
    gdwGlobal_00779974 = 1;
}

// 0x0042F6E0
void __cdecl MAINMENUS_ShowConnectingPopup()
{
    MAINMENUS_DestroyControls();
    gbGatewayFlag = 1;
    gdwGlobal_00779974 = 0;
    D2WinControlStrc* pControlA;
    D2WinControlStrc* pControlB;
    D2WinControlStrc* pControlC;
    if (gbFeCharPalette)
    {
        pControlA = MAINMENUS_CreateFromTemplate(0xF7);
        D2Win_10033(pControlA, 0);
        pControlB = MAINMENUS_CreateFromTemplate(0xFA);
        pControlC = MAINMENUS_CreateFromTemplate(0xF9);
    }
    else
    {
        pControlA = MAINMENUS_CreateFromTemplate(0xDE);
        D2Win_10033(pControlA, 0);
        pControlB = MAINMENUS_CreateFromTemplate(0xDF);
        pControlC = MAINMENUS_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlA, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlC, 1);
    sub_004FD060_SetText(pControlC, D2LANG_GetStringFromTblIndex(0x147B));
    gpfnGatewayDone = MAINMENUS_SetDone;
}

// 0x0042F790
int __stdcall MAINMENUS_ShowCantConnect(SMSGHANDLER_PARAMS* pMsg)
{
    gpfnGatewayDone = MAINMENUS_SetDone;
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControlB = MAINMENUS_CreateFromTemplate(0xFD);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xFE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FCF80_SetTextA(pControl, "Can't connect to Battle.Net. Try again later.");
    return 1;
}

// 0x0042F800
void __cdecl sub_0042F800()
{
    MAINMENUS_DestroyControls();
    gbGatewayFlag = 1;
    gdwGlobal_00779974 = 0;
// build: symbol ?MAINMENUS_CreateFromTemplate@* 0x0042F3A0
    D2WinControlStrc* pControlA = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControlA, 0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlA, 1);
    D2WinControlStrc* pControlB = MAINMENUS_CreateFromTemplate(0xFC);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlB, 1);
    D2WinControlStrc* pControlC = MAINMENUS_CreateFromTemplate(0xE0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControlC, 1);
    MAINMENUS_CreateFromTemplate(0xFB);
    sub_004FD060_SetText(pControlC, D2LANG_GetStringFromTblIndex(0x147B));
}

// 0x0042F880
void __cdecl sub_0042F880_DestroyControls()
{
    MAINMENUS_DestroyControls();
}

int __stdcall sub_004FD110_SetBarValue(D2WinControlStrc* pBar, int nValue); // 0x004FD110

int __stdcall sub_004FD170_SetBarMode(D2WinControlStrc* pBar, int nMode); // 0x004FD170

int __stdcall sub_004FD1B0_GetBarMax(D2WinControlStrc* pBar); // 0x004FD1B0

D2WinControlStrc* gpProgressText; // 0x00779978

D2WinControlStrc* gpProgressBar; // 0x0077997C

struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };

static inline int ProgressBarValue(int nPercent)
{
    return nPercent * sub_004FD1B0_GetBarMax(gpProgressBar) / 100;
}

// 0x0042F890
void __cdecl MAINMENUS_ShowProgressScreen()
{
    char szText[100];
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x116);
    gpProgressBar = MAINMENUS_CreateControl(0x117);
    sub_004FD170_SetBarMode(gpProgressBar, 3);
    gpProgressText = MAINMENUS_CreateControl(0x113);
    int nPercent = gpFuncTable_0077ABF0->pfnSlot4C();
    if (nPercent > 100)
        nPercent = 100;
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x114);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x143A), 0, 0, 0);
    pControl = MAINMENUS_CreateControl(0x112);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x143B), 0, 0, 0);
    MAINMENUS_CreateControl(0x118);
    sub_004FD110_SetBarValue(gpProgressBar, ProgressBarValue(nPercent));
    sprintf(szText, "%d%%", nPercent);
    sub_004FCFF0_SetTextA(gpProgressText, szText, 0);
}

// 0x0042F990
void __cdecl MAINMENUS_UpdateProgress()
{
    char szText[100];
    sub_004FB6A0_ClearText(gpProgressText);
    int nPercent = gpFuncTable_0077ABF0->pfnSlot4C();
    if (nPercent > 100)
        nPercent = 100;
    sub_004FD110_SetBarValue(gpProgressBar, ProgressBarValue(nPercent));
    sprintf(szText, "%d%%", nPercent);
    if (gpProgressText)
        sub_004FCFF0_SetTextA(gpProgressText, szText, 0);
}

// build: symbol ?MAINMENUS_CreateFromTemplate@* 0x0042F3A0

// 0x0042FA20
void __cdecl sub_0042FA20()
{
    gbStopMainLoop = 0;
}

// 0x0042FA40
int __cdecl MAINMENUS_InitAuxBattleNet()
{
    char szAddress[0x64];
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        return 1;
    sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, 0x22);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    return 0;
}

// 0x0042FAB0
int __cdecl MAINMENUS_GetAuxBattleNetFlag()
{
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d;
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        d = 0x22;
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
        unsigned char nLow = (unsigned char)d;
        if (nLow & 0x10)
            return (unsigned char)~nLow >> 7;
    }
    return 0;
}

// 0x0042FCE0
static int MAINMENUS_IsArchiveFilePresent(const char* szFile)
{
    void* hFile;
    if (!SFileOpenFileEx(0, szFile, 0, &hFile))
        return 0;
    SFileCloseFile(hFile);
    return 1;
}

// 0x0042FD10
static void MAINMENUS_BuildLocalizedVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    char szLang[4];
    STRTABLE_GetLanguageInfoField(szLang, 0);
// build: symbol ?gszDataLocal@* 0x006D41A8
    sprintf(szOut, szFormat, gszDataLocal, szLang, szFile);
    if (MAINMENUS_IsArchiveFilePresent(szOut))
        return;
    if (STRTABLE_GetLanguage())
    {
        sprintf(szOut, szFormat, gszDataLocal, "ENG", szFile);
        MAINMENUS_IsArchiveFilePresent(szOut);
    }
    else
    {
        sprintf(szOut, szFormat, gszDataLocal, "CHI", szFile);
        MAINMENUS_IsArchiveFilePresent(szOut);
    }
}

// 0x0042FDD0
void __cdecl MAINMENUS_ReturnToCharSelect()
{
    sub_00515020();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
}

// 0x0042FDE0
int __stdcall MAINMENUS_IsRestrictedChar(void* pControl, int nUnused, const char* pChar)
{
    char c = *pChar;
    switch (c)
    {
    case '"':
    case '#':
    case '%':
    case '*':
    case ',':
    case '/':
    case '<':
    case '>':
    case '?':
    case '\\':
        return 0;
    }
    if (c <= 0x20)
        return 0;
    return c < 0x7F;
}

// 0x0042FE60
int __stdcall sub_0042FE60_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    return 1;
}

// 0x0042FE70
int __stdcall MAINMENUS_FilterLoginChar(void* pControl, int nUnused, const char* pChar)
{
    char c = *pChar;
    switch (c)
    {
    case '"':
    case '#':
    case '%':
    case '*':
    case ',':
    case '/':
    case '<':
    case '>':
    case '?':
    case '\\':
        return 0;
    }
    if (c <= 0x20)
        return 0;
    return c < 0x7F;
}

// 0x0042FEF0
int __stdcall MAINMENUS_FilterRestrictedChar(void* pControl, int nUnused, const char* pChar)
{
    return MAINMENUS_IsRestrictedChar(pControl, nUnused, pChar);
}

// 0x0042FF00
int __stdcall sub_0042FF00_FilterChar(void* pControl, int nUnused, const char* pChar)
{
    return 1;
}

// 0x0042FF10
void __fastcall MAINMENUS_SetValue(int nValue)
{
    gnValue_00779980 = nValue;
}

// 0x0042FF20
void __cdecl MAINMENUS_ShowLocalAddress()
{
    const char* szAddress = FOG_GetHostIPAddress();
    sub_004FB6A0_ClearText(gpControl_00779588);
    if (!strcmp(szAddress, "127.0.0.1"))
    {
        sub_004FD060_SetText(gpControl_00779588, D2LANG_GetStringFromTblIndex(0x1404));
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpControl_007795A4, 0);
        CONTROL_SetEnabled(gpControl_007795A0, 0);
        CONTROL_SetEnabled(gpControl_00779338, 0);
    }
    else
    {
        D2Win_10045(gpControl_00779588, szAddress);
        CONTROL_SetEnabled(gpControl_007795A4, 1);
        CONTROL_SetEnabled(gpControl_007795A0, 1);
        CONTROL_SetEnabled(gpControl_00779338, 1);
    }
}

// 0x0042FFD0
int __stdcall MAINMENUS_ShowAddress(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowLocalAddress();
    return 1;
}

void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet); // 0x004F9740

D2WinControlStrc* gpControl_007795E0;                                                                       // 0x007795E0

extern D2WinControlStrc* gpControl_007795E4; // 0x007795E4

// 0x0042FFE0
void __cdecl CHARSEL_CreateTcpIpScreen()
{
    gbGatewayFlag = 1;
    CHARSEL_DisconnectBattleNet();
    MAINMENUS_Reset();
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateControl(0x102);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x103);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x13FD));
    gpControl_00779338 = MAINMENUS_CreateControl(0x104);
    sub_004FD060_SetText(gpControl_00779338, D2LANG_GetStringFromTblIndex(0x1401));
    gpControl_007795A4 = MAINMENUS_CreateControl(0x106);
    gpControl_007795A0 = MAINMENUS_CreateControl(0x107);
    gpControl_007795E0 = MAINMENUS_CreateControl(0x108);
    sub_004FD060_SetText(gpControl_007795E0, D2LANG_GetStringFromTblIndex(0x1402));
    gpControl_007795E4 = MAINMENUS_CreateControl(0x109);
    sub_004FD060_SetText(gpControl_007795E4, D2LANG_GetStringFromTblIndex(0x1403));
    sub_004F9740_ControlSetState(gpControl_007795E0, 0);
    sub_004F9740_ControlSetState(gpControl_007795E4, 0);
    sub_004FA450_SetActive(MAINMENUS_CreateControl(0x10A));
    gpControl_00779344 = MAINMENUS_CreateControl(0x10B);
    sub_004FD830(gpControl_00779344);
    sub_004FDA50(gpControl_00779344);
    gpControl_00779588 = MAINMENUS_CreateControl(0x105);
    MAINMENUS_ShowLocalAddress();
}

// 0x00430120
int __stdcall sub_00430120_OnToggle(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam)
        CONTROL_SetVisible(gpControl_007795E0, 1);
    else
        CONTROL_SetVisible(gpControl_007795E0, 0);
    return 1;
}

D2WinControlStrc* gpControl_007795E4;                                                                       // 0x007795E4

// 0x00430160
int __stdcall sub_00430160_OnToggle(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->lParam)
        CONTROL_SetVisible(gpControl_007795E4, 1);
    else
        CONTROL_SetVisible(gpControl_007795E4, 0);
    return 1;
}

// 0x004301A0
void __cdecl MAINMENUS_CreateMultiplayerScreen()
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    MAINMENUS_CreateControl(0x17);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1469));
    pControl = MAINMENUS_CreateControl(0x1C);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2A52));
    if (!FOG_IsExpansion())
    {
        pControl = MAINMENUS_CreateControl(0x1F);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1466), 0, 0, 0);
    }

    pControl = MAINMENUS_CreateControl(0x20);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1467), 0, 0, 0);

// build: symbol ?gpAccountEdit@* 0x0077958C
    gpAccountEdit = MAINMENUS_CreateControl(0x54);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, MAINMENUS_FilterLoginChar);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    sub_004FFE10_SetTextA(gpAccountEdit, gpLaunchRecord->szAccount);

// build: symbol ?gpPasswordEdit@* 0x00779334
    gpPasswordEdit = MAINMENUS_CreateControl(0x55);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpPasswordEdit, 0x0D);
    sub_004FFE10_SetTextA(gpPasswordEdit, gpLaunchRecord->szPassword);

    gpCreatePasswordConfirmEdit = MAINMENUS_CreateControl(0x56);
    sub_004FDD50_SetMaxLength(gpCreatePasswordConfirmEdit, 0x0D);

    if (gpLaunchRecord->szAccount[0])
    {
        if (gpLaunchRecord->szPassword[0])
        {
            CONTROL_SetFocusedEditBox(gpCreatePasswordConfirmEdit);
        }
        else
        {
            CONTROL_SetFocusedEditBox(gpPasswordEdit);
        }
    }
    else
    {
        CONTROL_SetFocusedEditBox(gpAccountEdit);
    }

    sub_004FDDD0_LinkTab(gpAccountEdit, gpPasswordEdit);
    sub_004FDDD0_LinkTab(gpPasswordEdit, gpCreatePasswordConfirmEdit);
    sub_004FDDD0_LinkTab(gpCreatePasswordConfirmEdit, gpAccountEdit);
    MAINMENUS_CreateControl(0x57);
    MAINMENUS_CreateControl(0x58);
}

// 0x00430390
void __cdecl MAINMENUS_CreateTermsControls()
{
    MAINMENUS_Reset();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(6);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    pControl = MAINMENUS_CreateControl(7);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    MAINMENUS_CreateControl(8);
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
}

// 0x004303E0
bool __stdcall MAINMENUS_IsLineBreak(Unicode wc)
{
    if (wc.wChar == 13 || wc.wChar == 10)
        return true;
    return false;
}

// 0x00430400
int __stdcall MAINMENUS_PollDownloadDone(int nArg)
{
    if (gpFuncTable_0077ABF0->pfnSlot4C() == 0x65 || gbStopMainLoop)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x00430430
int __stdcall MAINMENUS_OnBack(int nArg)
{
    MAINMENUS_CreateMultiplayerScreen();
    return 1;
}

// 0x00430440
int __stdcall MAINMENUS_ScrollUp(int nArg)
{
    D2WinControlStrc* pControl = 0;
    for (int i = 0; i <= gnControlCountB; ++i)
    {
        pControl = gapControlsB[i];
        if (CONTROL_GetType(pControl) == 4)
            break;
    }
    D2_ASSERT(pControl, 3304);
    const int nLines = D2Win_10054((D2WinTextBoxStrc*)pControl);
    if (nLines > 0)
        D2Win_10053(pControl, nLines - 1);
    return 1;
}

// 0x004304B0
int __stdcall MAINMENUS_ScrollDown(int nArg)
{
    D2WinControlStrc* pControl = 0;
    for (int i = 0; i <= gnControlCountB; ++i)
    {
        pControl = gapControlsB[i];
        if (CONTROL_GetType(pControl) == 4)
            break;
    }
    D2_ASSERT(pControl, 3327);
    const int nLines = D2Win_10054((D2WinTextBoxStrc*)pControl);
    D2Win_10053(pControl, nLines + 1);
    return 1;
}

// 0x00430520
void __cdecl sub_00430520()
{
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xCD);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0xCE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    D2WinControlStrc* pControl3 = MAINMENUS_CreateFromTemplate(0xCF);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl3, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x14B7), 0, 0, 0);
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

// 0x00430590
int __stdcall MAINMENUS_FilterNameChar(D2WinControlStrc* pControl, int bAllowSep, const char* pChar)
{
    const char c = *pChar;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || ((c == '-' || c == '_') && bAllowSep && FilterNoSeparator(pControl)))
        return 1;
    return 0;
}

// 0x00430600
static inline int MAINMENUS_CountNameSeparators(const char* szText, int nLength)
{
    int nCount = 0;
    for (int i = 0; i < nLength; ++i)
    {
        if (szText[i] == '-' || szText[i] == '_')
        {
            ++nCount;
        }
    }
    return nCount;
}

// 0x00430620
void __cdecl MAINMENUS_UpdateNameOk()
{
    char szText[0x20];
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    int bValid = 0;
    if (pText)
    {
        const int nLen = sub_00526800(pText);
        sub_005263E0(szText, pText, 0x20);
        if (nLen >= 2 && nLen <= 15)
        {
            const char cLast = szText[nLen - 1];
            const char cFirst = szText[0];
            if (cLast != '_' && cFirst != '_' && cLast != '-' && cFirst != '-')
            {
                int nCount = 0;
                for (int i = 0; i < nLen; i += 1)
                {
                    if (szText[i] == '-' || szText[i] == '_')
                        nCount += 1;
                }
                if (nCount < 2)
                    bValid = 1;
            }
        }
    }
    CONTROL_SetEnabled(gpOkButton_00779330, bValid);
}

// 0x004306C0
void __cdecl MAINMENUS_UpdateLoginOk()
{
// build: symbol ?gpAccountEdit@* 0x0077958C
    const Unicode* pName = sub_004FDD90_GetEditText(gpAccountEdit);
// build: symbol ?gpPasswordEdit@* 0x00779334
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    int bOk = 0;
    if (pName && pPassword)
    {
        int nNameLength = sub_00526800(pName);
        int nPasswordLength = sub_00526800(pPassword);
        if (nNameLength >= 1 && nNameLength <= 50 && nPasswordLength >= 1 && nPasswordLength <= 13)
            bOk = 1;
    }
    if (gpControl_00779594)
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(gpControl_00779594, bOk);
}

// 0x00430730
int __stdcall MAINMENUS_ToggleHardcore(int nArg)
{
    gpLaunchRecord->wFlags1EF ^= 4;
    return 1;
}

// 0x00430750
int __stdcall MAINMENUS_ToggleLadder(int nArg)
{
    gpLaunchRecord->wFlags1EF ^= 0x40;
    return 1;
}

// 0x00430770
int __stdcall MAINMENUS_ToggleExpansion(int nArg)
{
    if (!FOG_IsExpansion())
        return 0;
    gpLaunchRecord->wFlags1EF ^= 0x20;
    return 1;
}

// 0x004307A0
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2)
{
// build: symbol ?gnTextSentinel@* 0x0070CB80
    if (gnTextSentinel == -1)
    {
        if (nArg)
        {
            sub_004FB6A0_ClearText(gpTextControl1);
            sub_004FC9B0_SetText(gpTextControl1, D2LANG_GetStringFromTblIndex(nStringId1), 0, 0, 0);
            sub_004FB6A0_ClearText(gpTextControl2);
            sub_004FC9B0_SetText(gpTextControl2, D2LANG_GetStringFromTblIndex(nStringId2), 0, 0, 0);
            gnTextMode = nMode;
            return 1;
        }
        if (gnTextMode == nMode)
        {
            sub_004FB6A0_ClearText(gpTextControl1);
            sub_004FB6A0_ClearText(gpTextControl2);
        }
    }
    return 1;
}

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430840
int __stdcall MAINMENUS_OnHoverSorceress(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 1, 0xFAA, 0x140B);
    return 1;
}

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430870
int __stdcall MAINMENUS_OnHoverAmazon(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 0, 0xFAB, 0x1408);
    return 1;
}

// 0x004308A0
int __stdcall MAINMENUS_OnSelectAssassin(D2MenuCallbackArgStrc* pArg)
{
    if (!FOG_IsExpansion())
    {
        return 0;
    }
    MAINMENUS_ShowOptionDescription(pArg->nArg, 6, 0x2772, 0x57F7);
    return 1;
}

// 0x004308E0
int __stdcall MAINMENUS_OnSelectDruid(D2MenuCallbackArgStrc* pArg)
{
    if (!FOG_IsExpansion())
    {
        return 0;
    }
    MAINMENUS_ShowOptionDescription(pArg->nArg, 5, 0x2771, 0x57F6);
    return 1;
}

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430920
int __stdcall MAINMENUS_OnHoverNecromancer(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 2, 0xFA9, 0x1409);
    return 1;
}

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430950
int __stdcall MAINMENUS_OnHoverBarbarian(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 4, 0xFA7, 0x140A);
    return 1;
}

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430980
int __stdcall MAINMENUS_OnHoverPaladin(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 3, 0xFA8, 0x140C);
    return 1;
}

// 0x004309B0
void __cdecl MAINMENUS_ClearLaunchState()
{
// build: symbol ?gnLaunchState@* 0x007795E8
    gnLaunchState = 0;
}

// build: symbol @CHATDLG_SetMainControlState@* 0x0043DAD0
extern "C" int __fastcall CHATDLG_SetMainControlState(int value)
{
    sub_004F9740_ControlFlag(gControl, value);
    return 1;
}

int gnSlotCount;                                                                                     // 0x0077998C

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x004309C0
int __stdcall MAINMENUS_AddToSlots(void* pEntry)
{
    D2_ASSERT(gppSlots, 4383);
    for (int i = 0; i < gnSlotCount; i++)
    {
        if (!gppSlots[i])
        {
            gppSlots[i] = (D2LaunchSlotStrc*)pEntry;
            return 1;
        }
    }
    return 0;
}

// 0x00430A20
int __cdecl MAINMENUS_FreeSlots()
{
    if (!gppSlots)
        return 1;
    for (int i = 0; i < gnSlotCount; i++)
    {
        D2LaunchSlotStrc* pSlot = ((D2LaunchSlotStrc**)gppSlots)[i];
        if (pSlot)
        {
            D2_ASSERT(pSlot->pData, 0x1139);
            sub_0040B3C0(pSlot->pData, ".\\Src\\MainMenus.cpp", 0x113A, 0);
            D2_ASSERT(((D2LaunchSlotStrc**)gppSlots)[i]->szName, 0x113B);
            sub_0040B3C0(((D2LaunchSlotStrc**)gppSlots)[i]->szName, ".\\Src\\MainMenus.cpp", 0x113C, 0);
            sub_0040B3C0(gppSlots[i], ".\\Src\\MainMenus.cpp", 0x113E, 0);
        }
    }
    sub_0040B3C0(gppSlots, ".\\Src\\MainMenus.cpp", 0x1141, 0);
    gppSlots = 0;
    return 1;
}

int __stdcall sub_M121_Emit_00430600(const char* szText, int nLength) { return MAINMENUS_CountNameSeparators(szText, nLength); }

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430B00
int __cdecl MAINMENUS_CompareNames(const void* pEntry1, const void* pEntry2)
{
    return strcmp(**(const char* const* const*)pEntry1, **(const char* const* const*)pEntry2);
}

char* __fastcall MAINMENUS_GetSlotName(int nIndex); // 0x00430B50

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430B50
char* __fastcall MAINMENUS_GetSlotName(int nIndex)
{
    D2LaunchSlotStrc* pSlot = gppSlots[nIndex];
    D2_ASSERT(pSlot, 0x115C);
    return pSlot->szName;
}

// 0x00430B80
int __fastcall MAINMENUS_GetSlotValue(int nSlot)
{
    D2SlotEntryStrc* pSlot = (D2SlotEntryStrc*)gppSlots[nSlot];
    D2_ASSERT(pSlot, 0x1162);
    return pSlot->nField04;
}

// 0x00430BB0
int __stdcall MAINMENUS_IdleLoopCallback(int nArg)
{
    return 1;
}

// 0x00430BC0
int __cdecl MAINMENUS_HasSaveFiles()
{
    char szDir[0x400];
    char szPattern[0x400];
    D2FindDataStrc tFind;
    FOG_GetSavePath(szDir, 0x400);
// build: symbol ?gszSaveMask@* 0x006D41D4
    sprintf(szPattern, gszSaveMask, szDir);
    void* hFind = FindFirstFileA(szPattern, &tFind);
    if (hFind != (void*)-1)
    {
        FindClose(hFind);
        return 1;
    }
    return 0;
}

// 0x00430C30
int __stdcall sub_00430C30_OnCancel(int nArg)
{
    D2SOUNDFAST_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00430C50
int __stdcall MAINMENUS_OnCreate(int nArg)
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0xFF);
    MAINMENUS_CreateControl(0x100);
    MAINMENUS_CreateControl(0x101);
    return 1;
}

D2WinControlStrc* gpList_00779964;                                                                          // 0x00779964

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430C80
void __cdecl MAINMENUS_FillCreditsList()
{
    for (int i = 0; i < 50; i++)
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
    D2Win_10045(gpList_00779964, "The End");
    gnListPos = sub_004FB950_GetFirstVisible(gpList_00779964);
}

// 0x00430CD0
Unicode* __stdcall MAINMENUS_LoadCreditsText(int* pnLength)
{
    void* hFile;
    char szLanguage[4];
    STRTABLE_GetLanguageInfoField(szLanguage, 0);

    char szCredits[] = "Credits.txt";
    char szExpansionCredits[] = "ExpansionCredits.txt";
    char szPath[260];
    if (!FOG_IsExpansion())
        SStrPrintf(szPath, 260, "%s\\UI\\%s\\%s", "DATA\\LOCAL", szLanguage, szCredits);
    else
        SStrPrintf(szPath, 260, "%s\\UI\\%s\\%s", "DATA\\LOCAL", szLanguage, szExpansionCredits);

    if (!FOG_FOpenFile(szPath, &hFile))
        return 0;

    const int nSize = FOG_FGetFileSize(hFile, 0);
    char* pBuffer = (char*)FOG_Alloc(nSize, gszMainMenusFile, 0x138B, 0);
    D2_ASSERT(pBuffer, 0x138C);

    memset(pBuffer, 0, nSize);
    Unicode* pText = 0;
    FOG_FReadFile(hFile, pBuffer, nSize, 0, 0, 0, 0);
    FOG_FCloseFile(hFile);

    if (nSize <= 2)
    {
        *pnLength = 0;
    }
    else if (*(unsigned short*)pBuffer == 0xFEFF)
    {
        const int nLength = (nSize - 2) / 2;
        *pnLength = nLength;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLength, gszMainMenusFile, 0x13B8, 0);
        memcpy(pText, pBuffer + 2, sizeof(Unicode) * *pnLength);
    }
    else if (*(unsigned short*)pBuffer == 0xFFFE)
    {
        const int nLength = (nSize - 2) / 2;
        *pnLength = nLength;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLength, gszMainMenusFile, 0x13BF, 0);
        memcpy(pText, pBuffer + 2, sizeof(Unicode) * *pnLength);
        CHARSEL_SwapUnicodeBytes(pText, *pnLength);
    }
    else
    {
        *pnLength = nSize;
        pText = (Unicode*)FOG_Alloc(sizeof(Unicode) * nSize + 1, gszMainMenusFile, 0x13C8, 0);
        sub_00526F20_ToUnicode(pText, pBuffer, nSize);
    }

    FOG_Free(pBuffer, gszMainMenusFile, 0x13CC, 0);

    int i = 0;
    while (i < *pnLength)
    {
        if (pText[i].wChar != '\n' && pText[i].wChar != '\r')
        {
            ++i;
            continue;
        }
        pText[i].wChar = 0;
        ++i;
    }

    return pText;
}

D2WinControlStrc* gpList_0077995C;                                                                          // 0x0077995C

D2WinControlStrc* gpList_00779960;                                                                          // 0x00779960

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00430EF0
void __cdecl MAINMENUS_SyncCreditsLists()
{
    int nFirst = sub_004FB950_GetFirstVisible(gpList_00779964);
    int nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
    int nThird = sub_004FB950_GetFirstVisible(gpList_00779960);
    while (nSecond > nThird)
    {
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
        nThird = sub_004FB950_GetFirstVisible(gpList_00779960);
    }
    while (nSecond < nThird)
    {
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
    }
    while (nFirst > nSecond)
    {
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpList_0077995C);
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
    }
    while (nFirst < nSecond)
    {
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
        nFirst = sub_004FB950_GetFirstVisible(gpList_00779964);
    }
    D2Win_10045(gpList_00779964, &gszEmptyAssertText);
    D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
    D2Win_10045(gpList_00779960, &gszEmptyAssertText);
}

// 0x00431020
void __cdecl MAINMENUS_ClearCreditsLists()
{
    D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
    D2Win_10045(gpList_00779960, &gszEmptyAssertText);
}

// 0x00431040
void __cdecl MAINMENUS_ClearCreditsList() {
 D2Win_10045(gpList_00779964,&gszEmptyAssertText);
}

// 0x00431050
int __fastcall MAINMENUS_ShowCredits(int nUnused)
{
    int nLength = 0;
    Unicode* pText = MAINMENUS_LoadCreditsText(&nLength);
    Unicode wszLine[1024];
    D2_ASSERT(pText, 0x141B);

    for (int i = 0; i < 50; ++i)
    {
        D2Win_10045(gpList_00779964, &gszEmptyAssertText);
        D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
        D2Win_10045(gpList_00779960, &gszEmptyAssertText);
    }

    int nRemain = nLength;
    Unicode* pCursor = pText;
    while (nRemain)
    {
        if (pCursor->wChar == 0x2A)
        {
            D2Win_10045(gpList_0077995C, &gszEmptyAssertText);
            D2Win_10045(gpList_00779960, &gszEmptyAssertText);
            ++pCursor;
            if (sub_005267E0(wszLine, pCursor))
                sub_004FC9B0_SetText(gpList_00779964, wszLine, 1, 0, 0);
            else
                nRemain = 0;
            int nSkip = sub_00526800(wszLine) + 2;
            nRemain -= nSkip;
            pCursor += nSkip;
        }
        else
        {
            do
            {
                if (!nRemain)
                    break;
                Unicode wszLeft[256];
                Unicode wszRight[256];
                wszLeft[0].wChar = 0;
                wszRight[0].wChar = 0;
                if (pCursor->wChar < 0x80 && isalpha((char)pCursor->wChar) && sub_005267E0(wszLine, pCursor))
                {
                    sub_005267E0(wszLeft, wszLine);
                    int nSkip = sub_00526800(wszLine) + 2;
                    nRemain -= nSkip;
                    pCursor += nSkip;
                }
                else
                {
                    nRemain = 0;
                }

                if (nRemain && pCursor->wChar != 0x2A)
                {
                    if (sub_005267E0(wszLine, pCursor))
                    {
                        sub_005267E0(wszRight, wszLine);
                        int nSkip = sub_00526800(wszLine) + 2;
                        nRemain -= nSkip;
                        pCursor += nSkip;
                    }
                    else
                    {
                        nRemain = 0;
                    }
                }

                if (wszLeft[0].wChar && wszRight[0].wChar)
                {
                    sub_004FD060_SetText(gpList_0077995C, wszLeft);
                    sub_004FD060_SetText(gpList_00779960, wszRight);
                }
                else
                {
                    sub_004FD060_SetText(gpList_00779964, wszLeft);
                }
                D2Win_10045(gpList_00779964, &gszEmptyAssertText);
            } while (pCursor->wChar != 0x2A);
        }
        MAINMENUS_SyncCreditsLists();
    }

    MAINMENUS_FillCreditsList();
    FOG_Free(pText, ".\\Src\\MainMenus.cpp", 0x146F, 0);
    return 1;
}

// 0x004312C0
int __stdcall MAINMENUS_CreateCreditsScreen(int nUnused)
{
    MAINMENUS_Reset();
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateControl(0x29);
    MAINMENUS_CreateControl(0x2A);
    if (!FOG_IsExpansion())
    {
        gpList_0077995C = MAINMENUS_CreateControl(0x2B);
        gpList_00779960 = MAINMENUS_CreateControl(0x2C);
        gpList_00779964 = MAINMENUS_CreateControl(0x2D);
    }
    else
    {
        gpList_0077995C = MAINMENUS_CreateControl(0x2F);
        gpList_00779960 = MAINMENUS_CreateControl(0x30);
        gpList_00779964 = MAINMENUS_CreateControl(0x31);
    }
    gpControl_00779968 = MAINMENUS_CreateControl(0x2E);
    sub_004FD830(gpControl_00779968);
    sub_004FDA50(gpControl_00779968);
    MAINMENUS_ShowCredits(0);
    D2Win_10053(gpList_00779964, 20);
    D2Win_10053(gpList_0077995C, 20);
    D2Win_10053(gpList_00779960, 20);
    return 1;
}

// 0x004313A0
static unsigned char MAINMENUS_GetFlagIndex(unsigned char nFlags)
{
    if (nFlags & 0x01)
        return 7;
    if (nFlags & 0x80)
        return 6;
    if (nFlags & 0x10)
        return 5;
    if (nFlags & 0x08)
        return 4;
    if (nFlags & 0x40)
        return 3;
    if (nFlags & 0x04)
        return 2;
    return 1;
}

// 0x004313D0
void __stdcall MAINMENUS_CreateLevelScreen(int nLevel)
{
    MAINMENUS_Reset();
    MAINMENUS_DestroyControls();
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateControl(8);
    MAINMENUS_CreateControl(0x3D);
    D2WinControlStrc* pTitle = MAINMENUS_CreateControl(0x3E);
    sub_004FD060_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x13FA));
    MAINMENUS_CreateControl(0x3F);
    D2WinControlStrc* pField1 = MAINMENUS_CreateControl(0x40);
    D2WinControlStrc* pField2 = MAINMENUS_CreateControl(0x41);
    D2WinControlStrc* pField3 = MAINMENUS_CreateControl(0x42);
    D2WinControlStrc* pField4 = MAINMENUS_CreateControl(0x43);
    D2WinControlStrc* pField5 = MAINMENUS_CreateControl(0x44);
    D2WinControlStrc* pField6 = MAINMENUS_CreateControl(0x45);
    MAINMENUS_CreateControl(0x46);
    unsigned short wszEmpty[1] = { 0 };
    switch (nLevel)
    {
    default:
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
        CONTROL_SetEnabled(pField1, 0);
        BUTTON_SetText(pField1, 10, wszEmpty, 0);
    case 2:
        CONTROL_SetEnabled(pField2, 0);
        BUTTON_SetText(pField2, 10, wszEmpty, 0);
    case 3:
        CONTROL_SetEnabled(pField3, 0);
        BUTTON_SetText(pField3, 10, wszEmpty, 0);
    case 4:
        CONTROL_SetEnabled(pField4, 0);
        BUTTON_SetText(pField4, 10, wszEmpty, 0);
    case 5:
        CONTROL_SetEnabled(pField5, 0);
        BUTTON_SetText(pField5, 10, wszEmpty, 0);
    case 6:
        CONTROL_SetEnabled(pField6, 0);
        BUTTON_SetText(pField6, 10, wszEmpty, 0);
    case 7:
        break;
    }
}

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x00431570
void __fastcall MAINMENUS_CreateExpansionDiscPopup(int bFlag)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0x3C);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    if (bFlag)
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x5578), 0, 0, 0);
    else
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1431), 0, 0, 0);
}

// 0x00431600
int __stdcall MAINMENUS_ShowLevelScreen(int nUnused)
{
    char szAddress[0x64];
    unsigned char nLevel;
    sub_00515F50(0xB4);
// build: symbol ?D2SOUND_StopChannel@* 0x00514930
    D2SOUND_StopChannel();
// build: symbol ?D2SOUNDSMP_SetMasterVolume@* 0x00515CE0
    D2SOUNDSMP_SetMasterVolume(0xFF);
    CHARSEL_CreateBaseScreen();
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
    {
        int a;
        int b;
        int c;
        int d = 0x22;
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
        const unsigned char nLow = (unsigned char)d;
        if (nLow & 1)
            nLevel = 7;
        else if (nLow & 0x80)
            nLevel = 6;
        else if (nLow & 0x10)
            nLevel = 5;
        else if (nLow & 0x08)
            nLevel = 4;
        else if (nLow & 0x40)
            nLevel = 3;
        else
            nLevel = (nLow & 4) ? 2 : 1;
    }
    else
    {
        nLevel = 1;
        sprintf(szAddress, "%d.%d.%d.%d", 0xD8, 0x94, 0xF6, 0x22);
        SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
    }
    if (FOG_IsExpansion())
    {
        MAINMENUS_CreateLevelScreen(nLevel);
        return 1;
    }
    MAINMENUS_CreateControl(0x32);
    D2WinControlStrc* pTitle = MAINMENUS_CreateControl(0x33);
    sub_004FD060_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x13FA));
    MAINMENUS_CreateControl(0x34);
    D2WinControlStrc* pField1 = MAINMENUS_CreateControl(0x35);
    D2WinControlStrc* pField2 = MAINMENUS_CreateControl(0x36);
    D2WinControlStrc* pField3 = MAINMENUS_CreateControl(0x37);
    D2WinControlStrc* pField4 = MAINMENUS_CreateControl(0x38);
    switch (nLevel)
    {
    default:
        CONTROL_SetEnabled(pField1, 0);
    case 2:
        CONTROL_SetEnabled(pField2, 0);
    case 3:
        CONTROL_SetEnabled(pField3, 0);
    case 4:
        CONTROL_SetEnabled(pField4, 0);
    case 5:
    case 6:
    case 7:
        break;
    }
    MAINMENUS_CreateControl(0x39);
    return 1;
}

// calling-convention shim (not game code)
int __fastcall sub_004313A0_Shim(const unsigned char* pFlags, int nCount)
{
    int nSum = 0;
    for (int i = 0; i < nCount; ++i)
        nSum += MAINMENUS_GetFlagIndex(pFlags[i]);
    return nSum;
}

// 0x004317D0
void __cdecl MAINMENUS_FlushInput()
{
    D2WinMsgStrc tMsg;
    while (PeekMessageA(&tMsg, 0, 0, 0, 1))
    {
        switch (tMsg.uMessage)
        {
        case 0x12:
        case 0x102:
        case 0x201:
        case 0x202:
        case 0x204:
        case 0x205:
        case 0x207:
        case 0x208:
            break;
        default:
            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
            break;
        }
    }
}

// 0x00431870
static void __stdcall MAINMENUS_PlayVideo(int nArg, const char* szFormat)
{
    char szPath[0x104];
    char szSize[8];
    MAINMENUS_Reset();
    MAINMENUS_DestroyControls();
    MAINMENUS_FlushInput();
    if (D2Win_10003())
    {
        int nMode = 0;
        if (!sub_0040EB10())
        {
            strcpy(szSize, "640x292");
        }
        else
        {
            nMode = 2;
            strcpy(szSize, "640x146");
        }
        MAINMENUS_BuildLocalizedVideoPath(szPath, szFormat, szSize);
        sub_004F5D90_PlayVideo(szPath, nMode, 0);
        D2Win_10004(1);
    }
    MAINMENUS_FlushInput();
    MAINMENUS_ShowLevelScreen(nArg);
}

// 0x00431910
int __stdcall sub_00431910_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431920
int __stdcall sub_00431920_SetFlagD4(int nArg)
{
    gnFlag_007798D4 = 1;
    return 1;
}

// 0x00431930
int __stdcall MAINMENUS_ShowLevelAndStop(int nArg)
{
    MAINMENUS_ShowLevelScreen(nArg);
    gnFlag_007798D0 = 1;
    return 1;
}

// 0x00431950
int __stdcall MAINMENUS_LoopCallback(int nArg)
{
    if (gnFlag_007798D0 || gnFlag_007798D4)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x00431970
void __cdecl MAINMENUS_CreateArchivePopup()
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xD6);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0x3A);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0x3B);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1432), 0, 0, 0);
}

// 0x00431A00
int __cdecl MAINMENUS_ShowArchiveMessage()
{
    MAINMENUS_CreateArchivePopup();
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader = (void*)ARCHIVE_LoadVideoArchives;
    gnLoaderFlag = 1;
    sub_004FA590_RunLoop(MAINMENUS_LoopCallback);
    MAINMENUS_DestroyControls();
    return gnFlag_007798D4;
}

// 0x00431A40
int __stdcall MAINMENUS_OpenTcpIpScreen(int nArg)
{
    gnLaunchMode = 2;
// build: symbol ?CHARSEL_CreateTcpIpScreen@* 0x0042FFE0
    CHARSEL_CreateTcpIpScreen();
    return 1;
}

// 0x00431A60
int __fastcall MAINMENUS_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg)
{
    int bResult = 1;
    if (pMsg->uMessage != 0x201)
        bResult = 0;
    int nTick = GetTickCount();
    if (nTick - gnLastClickTick > 300)
        bResult = 0;
    D2CoordPairStrc tPoint;
    GetCursorPos(&tPoint);
    if (abs(tPoint.nY - gnLastClickY) + abs(tPoint.nX - gnLastClickX) > 4)
        bResult = 0;
    gnLastClickY = tPoint.nY;
    gnLastClickTick = nTick;
    gnLastClickX = tPoint.nX;
    return bResult;
}

// 0x00431C30
int __stdcall MAINMENUS_Leave(int nArg)
{
    gnLaunchState = 0;
    sub_00515F50(0xB4);
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00431C60
void __fastcall MAINMENUS_HandleCompressionMessage(unsigned char* pMsg, int nSize)
{
    if (nSize != -1)
    {
        switch (*pMsg)
        {
        case 0xAF:
            gdwGlobal_00779990 = 1;
            break;
        case 0xB0:
            gdwGlobal_00779990 = 0;
            break;
        }
    }
}

int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A8B0

int gdwGlobal_00779990; // 0x00779990

// 0x00431C90
int __stdcall MAINMENUS_PollSystemPacket(int nUnused)
{
    unsigned char pBuffer[0x200];
    if (CLIENT_DequeueSystemPacket(pBuffer, sizeof(pBuffer)) != -1)
    {
        switch (pBuffer[0])
        {
        case 0xAF:
            gdwGlobal_00779990 = 1;
            D2Win_StopMessageLoop();
            return 1;
        case 0xB0:
            gdwGlobal_00779990 = 0;
            break;
        }
    }

    if (gdwGlobal_00779990 || gdwGlobal_00779974)
        D2Win_StopMessageLoop();

    return 1;
}

// 0x00431D10
int __stdcall MAINMENUS_StopLoop(int nArg)
{
    D2Win_StopMessageLoop();
    return 1;
}

// 0x00431D20
int __stdcall MAINMENUS_CreateTcpIpScreen(int nArg)
{
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    sub_004F95C0_ControlDestroy(&gpControl_00779344);
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0x10F);
    D2Win_10033(pControl, 0);
    MAINMENUS_CreateFromTemplate(0x10E);
    pControl = MAINMENUS_CreateFromTemplate(0x10C);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B1F));
    gpAddressEdit = MAINMENUS_CreateFromTemplate(0x10D);
    if (!gszLastTcpIpAddress[0])
        SRegLoadString("Diablo II", "LastTcpIp", 0, gszLastTcpIpAddress, 0x100);
    sub_004FFE10_SetTextA(gpAddressEdit, gszLastTcpIpAddress);
    CONTROL_SetFocusedEditBox(gpAddressEdit);
    D2Win_10082(gpAddressEdit);
    sub_004FA450_SetActive(MAINMENUS_CreateFromTemplate(0x110));
    MAINMENUS_CreateFromTemplate(0x111);
    return 1;
}

// 0x00431E00
int __stdcall MAINMENUS_OnTcpIpJoin(int nArg)
{
    MAINMENUS_DestroyControls();
    gpControl_00779344 = MAINMENUS_CreateControl(0x10B);
    sub_004FD830(gpControl_00779344);
    sub_004FDA50(gpControl_00779344);
    return 1;
}

// 0x00431E30
int __stdcall MAINMENUS_PollConnection(int nArg)
{
    const int nStatus = CLIENT_GetConnectionStatus();
    if (!nStatus)
    {
        gbConnectResult = nStatus;
        D2Win_StopMessageLoop();
        return 1;
    }
    if (nStatus == 2)
    {
        gbConnectResult = 1;
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00431E70
static void MAINMENUS_SetModeFlags(char nMode)
{
    gpLaunchRecord->nMode = nMode;
    gpLaunchRecord->bAmazon = 0;
    gpLaunchRecord->bBarbarian = 0;
    gpLaunchRecord->bNecromancer = 0;
    gpLaunchRecord->bPaladin = 0;
    gpLaunchRecord->bSorceress = 0;
    gpLaunchRecord->bDruid = 0;
    gpLaunchRecord->bAssassin = 0;

    if (nMode == 0)
    {
        gpLaunchRecord->bAmazon = 1;
    }
    else if (nMode == 4)
    {
        gpLaunchRecord->bBarbarian = 1;
    }
    else if (nMode == 2)
    {
        gpLaunchRecord->bNecromancer = 1;
    }
    else if (nMode == 3)
    {
        gpLaunchRecord->bPaladin = 1;
    }
    else if (nMode == 1)
    {
        gpLaunchRecord->bSorceress = 1;
    }
    else if (nMode == 5)
    {
        gpLaunchRecord->bDruid = 1;
    }
    else if (nMode == 6)
    {
        gpLaunchRecord->bAssassin = 1;
    }
}

void __cdecl sub_I03_Emit_00431E70(char nMode)
{
    MAINMENUS_SetModeFlags(gnTextSentinel);
    MAINMENUS_SetModeFlags(nMode);
}

// 0x00431F50
int __stdcall sub_00431F50_OnCancel(int nArg)
{
    D2SOUNDFAST_FadeOutWaves();
    MAINMENUS_Reset();
    sub_0043B080();
    return 1;
}

// 0x00431F70
int __cdecl MAINMENUS_SaveExists()
{
    char szDir[0x400];
    char szUtf8[0x100];
    char szPath[0x104];
    char szName[0x100];
    FOG_GetSavePath(szDir, 0x400);
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szUtf8, pText, 0x100);
// build: symbol ?gszStringFormat@* 0x006FFC58
    sprintf(szName, gszStringFormat, szUtf8);
    sprintf(szPath, gszSavePathFormat_006D4230, szDir, szName);
    void* hFile = FOG_CreateFileA(szPath, 0x80000000, 0, 0, 3, 0x8000000, 0);
    if (hFile != (void*)-1)
    {
        FOG_CloseFile(hFile);
        return 1;
    }
    return 0;
}

// 0x00432020
int __stdcall sub_00432020_OnCancel(int nArg)
{
    D2SOUNDFAST_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00432040
int __stdcall MAINMENUS_OnCancel2(int nArg)
{
    D2SOUNDFAST_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00432060
int __stdcall MAINMENUS_CallGatewayDone(int nArg)
{
    if (gpfnGatewayDone)
        gpfnGatewayDone();
    return 1;
}

// 0x00432080
static void MAINMENUS_StoreAccountTexts(D2WinControlStrc* pAccountEdit, D2WinControlStrc* pPasswordEdit)
{
    if (pAccountEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pAccountEdit);
        sub_00526F70(gpLaunchRecord->szAccount, pText, 0x100);
    }
    if (pPasswordEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pPasswordEdit);
        sub_00526F70(gpLaunchRecord->szPassword, pText, 0x100);
        gpLaunchRecord->dwPasswordHash = SStrHashHT(gpLaunchRecord->szPassword);
        gpLaunchRecord->nPasswordLength = SStrLen(gpLaunchRecord->szPassword);
    }
}

// 0x00432100
void __cdecl MAINMENUS_CreateLoginScreen()
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    MAINMENUS_CreateControl(0x18);
    MAINMENUS_CreateControl(0x19);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2C));
    pControl = MAINMENUS_CreateControl(0x1D);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2D));
    pControl = MAINMENUS_CreateControl(0x1E);
    sub_004FD060_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B2E));
    if (FOG_IsExpansion())
        pControl = MAINMENUS_CreateControl(0x21);
    else
        pControl = MAINMENUS_CreateControl(0x1F);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B2B), 0x0, 0x0, 0x0);
    gpAccountEdit = MAINMENUS_CreateControl(0x59);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, MAINMENUS_FilterLoginChar);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    sub_004FFE10_SetTextA(gpAccountEdit, gpLaunchRecord->szAccount);
    gpPasswordEdit = MAINMENUS_CreateControl(0x5A);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit, sub_0042FF00_FilterChar);
    sub_004FDD50_SetMaxLength(gpPasswordEdit, 0xD);
    gpCreatePasswordEdit = MAINMENUS_CreateControl(0x5B);
    sub_004FDD50_SetMaxLength(gpCreatePasswordEdit, 0xD);
    gpCreatePasswordConfirmEdit = MAINMENUS_CreateControl(0x5C);
    sub_004FDD50_SetMaxLength(gpCreatePasswordConfirmEdit, 0xD);
    if (gpLaunchRecord->szAccount[0] != 0x0)
        CONTROL_SetFocusedEditBox(gpPasswordEdit);
    else
        CONTROL_SetFocusedEditBox(gpAccountEdit);
    sub_004FDDD0_LinkTab(gpAccountEdit, gpPasswordEdit);
    sub_004FDDD0_LinkTab(gpPasswordEdit, gpCreatePasswordEdit);
    sub_004FDDD0_LinkTab(gpCreatePasswordEdit, gpCreatePasswordConfirmEdit);
    sub_004FDDD0_LinkTab(gpCreatePasswordConfirmEdit, gpAccountEdit);
    MAINMENUS_CreateControl(0x5D);
    MAINMENUS_CreateControl(0x5E);
}

// 0x00432300
int __stdcall MAINMENUS_OnLoginScreen(int nArg)
{
    MAINMENUS_CreateLoginScreen();
    return 1;
}

// 0x00432310
int __stdcall MAINMENUS_StoreAccount(int nArg)
{
    const Unicode* pText = sub_004FDD90_GetEditText(gpAccountEdit);
    sub_00526F70(gpLaunchRecord->szAccount, pText, 0x100);
    sub_004370C0();
    return 1;
}

// 0x00432340
int __stdcall MAINMENUS_OpenInfoScreen(int nUnused)
{
    sub_004370C0();
    return 1;
}

// 0x00432350
static int MAINMENUS_IsListedCode(int nCode)
{
    switch (nCode)
    {
    case 2:
    case 10:
    case 11:
    case 12:
    case 13:
    case 126:
    case 127:
        return 1;
    }
    return 0;
}

// 0x00432400
int __cdecl MAINMENUS_PollStatus()
{
    if (gnWaitDone)
        return 1;
    if (!sub_00449AC0_GetHandle())
        return 2;
    switch (WaitForSingleObject(sub_00449AC0_GetHandle(), 0))
    {
    default:
        return 2;
    case 0x102:
        _ReadWriteBarrier();
        return 3;
    case 0:
// build: symbol ?GAME_GetConnectError@* 0x00449C00
        GAME_GetConnectError();
        return sub_00432350_GetStatus() ? 2 : 0;
    }
}

// 0x00432450
int __stdcall MAINMENUS_OnWait(int nArg)
{
    if (gdwGlobal_00779974)
        gnWaitDone = 1;
    if (sub_00432400_GetStatus() != 3)
        D2Win_StopMessageLoop();
    return 1;
}

// 0x00432480
int __fastcall MAINMENUS_ConnectToRealm(const char* szName, int bFlag)
{
    if (*szName && (&gpLaunchRecord->nByte22D)[0] && !strcmp(szName, (&gpLaunchRecord->nByte22D)) && MCPCONNECT_QueryAddress())
    {
        return 0;
    }

    if (!bFlag)
    {
        MAINMENUS_ShowConnectingPopup();
    }

    D2MCPClientCloseMCP();
    gnWaitDone = 0;

    if (!*szName)
    {
        (&gpLaunchRecord->nByte22D)[0] = 0;
        (gpLaunchRecord->szPassword + 0x30)[0] = 0;
        if (!bFlag)
        {
            MAINMENUS_DestroyControls();
        }

        return 0;
    }

    D2LaunchPayloadStrc* pPayload;
    if (!gpFuncTable_0077ABF0)
        goto fail;
    pPayload = gpFuncTable_0077ABF0->pfn0x44(szName, "password");
    if (!pPayload)
        goto fail;
    if (pPayload->nSize == 8)
    {
fail:
        if (!bFlag)
            MAINMENUS_DestroyControls();
        return 2;
    }
    SStrCopy((&gpLaunchRecord->nByte22D), szName, 0x100);
    SStrCopy((gpLaunchRecord->szPassword + 0x30), szName, 0x100);
    CHATDLG_StartThread(&pPayload->tRecord);
    int nResult = 3;
    if (!bFlag)
    {
        sub_004FA590_RunLoop(MAINMENUS_OnWait);
        nResult = sub_00432400_GetStatus();
        MAINMENUS_DestroyControls();
    }
    return nResult;
}

int __stdcall D2Win_10125();                                                                                // 0x00501A40

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

// build: symbol ?gpAccountEdit@* 0x0077958C
// build: symbol ?gpPasswordEdit@* 0x00779334
// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0

// 0x004325B0
void __cdecl MAINMENUS_CreateScreen()
{
    MAINMENUS_Reset();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(6);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    pControl = MAINMENUS_CreateControl(7);
    ANIMIMAGE_SetIsRunning((D2WinAnimImageStrc*)pControl, 0);
    MAINMENUS_CreateControl(8);
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    MAINMENUS_CreateFromTemplate(0x4D);
    MAINMENUS_CreateFromTemplate(0x63);
    MAINMENUS_CreateFromTemplate(0x64);
    pControl = MAINMENUS_CreateFromTemplate(0x5F);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146B), 0, 0, 0);
    D2WinControlStrc* pList = MAINMENUS_CreateFromTemplate(0x60);
    int nOld = D2Win_10127_SetFont(5);
    int nValue = D2Win_10125();
    D2Win_10127_SetFont(nOld);
    sub_004FC9B0_SetText(pList, D2LANG_GetStringFromTblIndex(0x146C), 0, 0, 0);
    sub_004FB740(pList, nValue / -10, 0);
    pControl = MAINMENUS_CreateFromTemplate(0x61);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x146D), 0, 0, 0);
    sub_004FB740(pControl, nValue / -10, 0);
    pControl = MAINMENUS_CreateFromTemplate(0x62);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x2B77), 0, 0, 0);
}

// 0x004326F0
void __cdecl MAINMENUS_LoadCharCreateCells()
{
    char szPath[0x104];
    if (gpCharacterCreateCelFile)
        return;
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\MediumSelButtonBlank", gszDataGlobal);
    gpMediumSelButtonBlankCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\charactercreationscreenEXP", gszDataGlobal);
    else
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\CharacterCreate", gszDataGlobal);
    gpCharacterCreateCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\fire", gszDataGlobal);
    gpFireCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\textbox", gszDataGlobal);
    gpTextBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\clickbox", gszDataGlobal);
    gpClickBoxCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    if (FOG_IsExpansion())
    {
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\joingameclickboxgrey", gszDataGlobal);
        gpJoinGameClickBoxGreyCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu1", gszDataGlobal);
        gapAssassinCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu2", gszDataGlobal);
        gpAsNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asfw", gszDataGlobal);
        gpAsFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asnu3", gszDataGlobal);
        gpAsNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\assassin\\asbw", gszDataGlobal);
        gpAsBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu1", gszDataGlobal);
        gapDruidCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu2", gszDataGlobal);
        gpDzNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzfw", gszDataGlobal);
        gpDzFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dznu3", gszDataGlobal);
        gpDzNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
        wsprintfA(szPath, "%s\\ui\\FrontEnd\\druid\\dzbw", gszDataGlobal);
        gpDzBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    }
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu1", gszDataGlobal);
    gapAmazonCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu2", gszDataGlobal);
    gpAmNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amfw", gszDataGlobal);
    gpAmFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\amnu3", gszDataGlobal);
    gpAmNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\amazon\\ambw", gszDataGlobal);
    gpAmBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu1", gszDataGlobal);
    gapNecromancerCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu2", gszDataGlobal);
    gpNeNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefw", gszDataGlobal);
    gpNeFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3", gszDataGlobal);
    gpNeNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebw", gszDataGlobal);
    gpNeBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu1", gszDataGlobal);
    gapBarbarianCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu2", gszDataGlobal);
    gpBaNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafw", gszDataGlobal);
    gpBaFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\banu3", gszDataGlobal);
    gpBaNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\babw", gszDataGlobal);
    gpBaBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu1", gszDataGlobal);
    gapSorceressCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu2", gszDataGlobal);
    gpSoNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofw", gszDataGlobal);
    gpSoFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3", gszDataGlobal);
    gpSoNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobw", gszDataGlobal);
    gpSoBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu1", gszDataGlobal);
    gapPaladinCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu2", gszDataGlobal);
    gpPaNu2CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafw", gszDataGlobal);
    gpPaFwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\panu3", gszDataGlobal);
    gpPaNu3CelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pabw", gszDataGlobal);
    gpPaBwCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sofws", gszDataGlobal);
    gapSorceressSCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sonu3s", gszDataGlobal);
    gpSoNu3SCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\sorceress\\sobws", gszDataGlobal);
    gpSoBwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nefws", gszDataGlobal);
    gapNecromancerSCelFiles = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nenu3s", gszDataGlobal);
    gpNeNu3SCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\necromancer\\nebws", gszDataGlobal);
    gpNeBwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\barbarian\\bafws", gszDataGlobal);
    gpBaFwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
    wsprintfA(szPath, "%s\\ui\\FrontEnd\\paladin\\pafws", gszDataGlobal);
    gpPaFwSCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
}

// 0x00432EE0
int __stdcall MAINMENUS_CloseBox(int nArg)
{
    MAINMENUS_DestroyControls();
    return 1;
}

// 0x00432EF0
extern "C" void __cdecl MAINMENUS_ConfigureLanguageLayout()
{
    if (sub_00525150_Language() == 9)
    {
        gLayout_00709C48 = 0x9B;
        gLayout_007091F8 = 0x14E;
        gLayout_00709228 = 0x184;
        gLayout_00709258 = 0x1BA;
        gLayout_007092E8 = 0xF0;
        gLayout_00709318 = 0x158;
        gLayout_00709EE8 = 0x9C;
        gLayout_0070B2C8 = 0x1FA;
        gLayout_0070B2F8 = 0x22B;
        gLayout_0070B088 = 0x23F;
        gLayout_0070B4A8 = 0x22B;
        gLayout_0070B0E8 = 0x22B;
        gLayout_0070B148 = 0x23F;
        gLayout_0070B1A8 = 0x253;
        gLayout_0070BDA8 = 0x46;
        gLayout_0070BF58 = 0xEE;
    }
}

// 0x00432FA0
int __stdcall MAINMENUS_PollCharCreate(int nArg)
{
    sub_00449B70_Receive();
    if (GAME_IsMcpCharCreateReceived() || !MCPCONNECT_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharCreateReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00432FE0
int __stdcall MAINMENUS_PollCharLogon(int nArg)
{
    sub_00449B70_Receive();
    if (GAME_IsMcpCharLogonReceived() || !MCPCONNECT_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharLogonReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

int __cdecl sub_00432400_GetWaitStatus()
{
    if (gnWaitDone)
        return 1;

    if (GAME_GetWaitHandle())
    {
        switch (WaitForSingleObject((void*)GAME_GetWaitHandle(), 0))
        {
        case 0:
            return MAINMENUS_IsListedCode(GAME_GetConnectError()) ? 2 : 0;
        case 0x102:
            return 3;
        }
    }

    return 2;
}

// 0x00433020
int __stdcall MAINMENUS_PollCharDelete(int nArg)
{
    sub_00449B70_Receive();
    if (GAME_IsMcpCharDeleteReceived() || !MCPCONNECT_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharDeleteReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00433060
int __stdcall MAINMENUS_PollCharUpgrade(int nArg)
{
    sub_00449B70_Receive();
    if (GAME_IsMcpCharUpgradeReceived() || !MCPCONNECT_QueryAddress() || gdwGlobal_00779974)
    {
        CHATDLG_SetCharUpgradeReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x00433440
void __fastcall MAINMENUS_ShowMessageNoArg(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_ShowMessage(pText, pfnDone, 0);
}

// 0x00433450
void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_ShowMessage(pText, pfnDone, 1);
}

// 0x004334D0
int __stdcall MAINMENUS_OnCloseBox(int nArg)
{
    MAINMENUS_DestroyControls();
    return 1;
}

// 0x004334E0
void __cdecl MAINMENUS_PlayIntro()
{
    char szPath[0x104];
    char szAddress[0x64];
    int a;
    int b;
    int c;
    int d;
    void* hFile;
    char szLanguage[4];
    char szSize[8];
    MAINMENUS_FlushInput();
    int nMode = 0;
    if (!sub_0040EB10())
    {
        strcpy(szSize, "640x292");
    }
    else
    {
        nMode = 2;
        strcpy(szSize, "640x146");
    }
    STRTABLE_GetLanguageInfoField(szLanguage, 0);
    sprintf(szPath, "%s\\video\\%s\\D2x_Intro_%s.bik", gszDataLocal, szLanguage, szSize);
    if (SFileOpenFileEx(0, szPath, 0, &hFile))
        SFileCloseFile(hFile);
    else
        sprintf(szPath, "%s\\video\\%s\\D2x_Intro%s.bik", gszDataLocal, "ENG", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    if (SRegLoadString("Diablo II", "Aux Battle.net", 0, szAddress, 0x64))
        sscanf(szAddress, "%ld.%ld.%ld.%ld", &a, &b, &c, &d);
    d |= 0x80;
    sprintf(szAddress, "%d.%d.%d.%ld", 0xD8, 0x94, 0xF6, d);
    SRegSaveString("Diablo II", "Aux Battle.net", 0, szAddress);
}

// 0x00433640
void __cdecl MAINMENUS_PlayIntroVideo()
{
    char szPath[0x104];
    char szSize[8];
    MAINMENUS_FlushInput();
    int nMode = 0;
    if (!sub_0040EB10())
    {
        strcpy(szSize, "640x292");
    }
    else
    {
        nMode = 2;
        strcpy(szSize, "640x146");
    }
    MAINMENUS_BuildLocalizedVideoPath(szPath, "%s\\video\\%s\\d2intro%s.bik", szSize);
    sub_004F5D90_PlayVideo(szPath, nMode, 0);
    MAINMENUS_CreateVideoScreen();
}

// 0x004336C0
void __cdecl MAINMENUS_ShowMainMenu()
{
    char szVersion[0x40];
    D2WinControlStrc* pFirst;
    D2WinControlStrc* pSecond;
    CHARSEL_DisconnectBattleNet();
    gpLaunchRecord->szServerIP[0] = 0;
    CHARSEL_CreateBaseScreen();
    if (FOG_IsExpansion())
    {
        gpControl_007795AC = MAINMENUS_CreateControl(0x12);
        MAINMENUS_ShowCurrentGateway();
        pFirst = MAINMENUS_CreateControl(0x11);
        pSecond = MAINMENUS_CreateControl(0x13);
        MAINMENUS_CreateControl(0x10);
    }
    else
    {
        pFirst = MAINMENUS_CreateControl(0x0A);
        gpControl_007795AC = MAINMENUS_CreateControl(0x0B);
        MAINMENUS_ShowCurrentGateway();
        MAINMENUS_CreateControl(0x09);
        pSecond = MAINMENUS_CreateControl(0x0C);
    }
// build: symbol ?D2Win_10185_CheckCharMpq@* 0x004FAC90
    if (D2Win_10185_CheckCharMpq())
    {
        CONTROL_SetEnabled(pFirst, 0);
        CONTROL_SetEnabled(pSecond, 0);
        CONTROL_SetEnabled(gpControl_007795AC, 0);
    }
    MAINMENUS_CreateControl(0x0D);
    MAINMENUS_CreateControl(0x0E);
    MAINMENUS_CreateControl(0x0F);
    D2WinControlStrc* pText = MAINMENUS_CreateControl(0x115);
    const int nLen = SStrPrintf(szVersion, 0x40, "v %d.%d%c", 1, 0x0E, 0x64);
    if (gpLaunchRecord->bFlag223)
        SStrPrintf(&szVersion[nLen], 0x40 - nLen, " %d", 0x47);
    sub_004FCFF0_SetTextA(pText, szVersion, 0);
// build: symbol ?D2SOUND_GetOptionsMusicOption@* 0x00514D80
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
}

// 0x00433BD0
int __stdcall MAINMENUS_OnNameChanged(int nArg)
{
    MAINMENUS_UpdateNameOk();
    return 1;
}

// 0x00433BE0
int __stdcall MAINMENUS_OnLoginChanged(int nArg)
{
    MAINMENUS_UpdateLoginOk();
    return 1;
}

// 0x00434060
void __cdecl MAINMENUS_BuildRealmList()
{
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(MAINMENUS_StopLoop);
    if (gpFuncTable_0077ABF0)
        gpMenuList = gpFuncTable_0077ABF0->pfnGetMenuList(0);
    MAINMENUS_DestroyControls();
    D2MenuListStrc* pList = gpMenuList;
    if (!pList)
    {
        gnSlotCount = -1;
        return;
    }
    gnSlotCount = pList->nCount;
    D2_ASSERT(gnSlotCount < 512, 4481);
    char* pText = (char*)(pList + 1);
    MAINMENUS_FreeSlots();
    int nCount = gnSlotCount;
    if (gnSlotCount)
    {
        const unsigned int nSize = gnSlotCount * sizeof(D2LaunchSlotStrc*);
        gppSlots = (D2LaunchSlotStrc**)FOG_Alloc(nSize, gszMainMenusFile, 4492, 0);
        memset(gppSlots, 0, nSize);
        for (int i = 0; i < nCount; ++i)
        {
            D2LaunchSlotStrc* pSlot = (D2LaunchSlotStrc*)FOG_Alloc(sizeof(D2LaunchSlotStrc), gszMainMenusFile, 4498, 0);
            pText += sizeof(int);
            unsigned int nLength = strlen(pText) + 1;
            pSlot->szName = (char*)FOG_Alloc(nLength, gszMainMenusFile, 4511, 0);
            SStrCopy(pSlot->szName, pText, nLength);
            pText += nLength;
            nLength = strlen(pText) + 1;
            pSlot->pData = FOG_Alloc(nLength, gszMainMenusFile, 4516, 0);
            SStrCopy((char*)pSlot->pData, pText, nLength);
            pText += nLength;
            MAINMENUS_AddToSlots(pSlot);
        }
        qsort(gppSlots, gnSlotCount, sizeof(D2LaunchSlotStrc*), MAINMENUS_CompareNames);
    }
}

// 0x004341F0
int __stdcall MAINMENUS_CheckCreditsEnd(int nArg)
{
    if (gnListPos <= sub_004FB950_GetFirstVisible(gpList_00779964) + 10)
        sub_004336C0();
    return 1;
}

// 0x00434220
int __cdecl MAINMENUS_PromptPlayDisc()
{
    MAINMENUS_DestroyControls();
// build: symbol ?MAINMENUS_CreateFromTemplate@* 0x0042F3A0
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pControl2 = MAINMENUS_CreateFromTemplate(0x3C);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl2, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xD9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1430), 0, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1431), 0, 0, 0);
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader2 = (void*)ARCHIVE_LoadExpansionArchives;
    gnLoaderFlag = 0;
    sub_004FA590_RunLoop(MAINMENUS_LoopCallback);
    MAINMENUS_DestroyControls();
    return gnFlag_007798D4;
}

// 0x004342E0
int __cdecl MAINMENUS_PromptExpansionDisc()
{
    MAINMENUS_CreateExpansionDiscPopup(1);
    gnFlag_007798D0 = 0;
    gnFlag_007798D4 = 0;
    gpfnArchiveLoader2 = (void*)ARCHIVE_LoadExpansionArchives;
    gnLoaderFlag = 0;
    sub_004FA590_RunLoop(MAINMENUS_LoopCallback);
    MAINMENUS_DestroyControls();
    return gnFlag_007798D4;
}

// 0x00434320
int __stdcall MAINMENUS_PlayClassicIntro(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\d2intro%s.bik");
    return 1;
}

// 0x00434380
int __stdcall MAINMENUS_PlayActTwoStart(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act02start%s.bik");
    return 1;
}

// 0x004343E0
int __stdcall MAINMENUS_PlayActThreeStart(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act03start%s.bik");
    return 1;
}

// 0x00434440
int __stdcall MAINMENUS_PlayActFourStart(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act04start%s.bik");
    return 1;
}

// 0x004344A0
int __stdcall MAINMENUS_PlayActFourEnd(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadVideoArchives((void*)MAINMENUS_ShowArchiveMessage, 0, 0))
    {
        ARCHIVE_UnloadExpansionArchives();
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
        return 0;
    }
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\Act04end%s.bik");
    return 1;
}

// 0x00434500
int __stdcall MAINMENUS_PlayExpansionIntro(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\D2x_Intro_%s.bik");
    return 1;
}

// 0x00434560
int __stdcall MAINMENUS_PlayExpansionOutro(int nArg)
{
    ARCHIVE_UnloadExpansionArchives();
    if (!ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4))
        ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
    MAINMENUS_PlayVideo(nArg, "%s\\video\\%s\\D2x_Out_%s.bik");
    return 1;
}

// 0x004345C0
int __stdcall MAINMENUS_ReloadAndLeave(int nArg)
{
    sub_004FAD70();
    ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
// build: symbol ?D2SOUND_GetOptionsMusicOption@* 0x00514D80
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
    sub_004336C0();
    return 1;
}

// build: symbol ?Name@BNGatewayAccess@@QAGPBDH@Z 0x005180A0
// 0x00434600
int __stdcall MAINMENUS_CreateGatewayScreen(int nUnused)
{
// build: symbol ?CHARSEL_CreateBaseScreen@* 0x0043C4F0
    CHARSEL_CreateBaseScreen();
// build: symbol ?MAINMENUS_CreateControl@* 0x0042F430
    MAINMENUS_CreateControl(0x47);
    D2Win_10044(MAINMENUS_CreateControl(0x48), D2LANG_GetStringFromTblIndex(0x2B2F));
    D2Win_10044(MAINMENUS_CreateControl(0x49), D2LANG_GetStringFromTblIndex(0x2B30));
    gpGatewayList = MAINMENUS_CreateControl(0x4A);
    MAINMENUS_CreateControl(0x4B);
    MAINMENUS_CreateControl(0x4C);
    BNGatewayAccess* pGateways = (BNGatewayAccess*)gpFuncTable_0077ABF0->pfnGetRecord();
    int nCur = pGateways->m_nCurGateway;
    for (int i = 1; i <= pGateways->m_nNumGateways; ++i)
    {
        sub_004FCF80_SetTextA(gpGatewayList, pGateways->Name(i));
    }
    int nFirst = sub_004FB950_GetFirstVisible(gpGatewayList);
    int nVisible = D2Win_10055(gpGatewayList);
    int nLine = nCur - 1;
    if (nLine < nFirst || nLine - nFirst > nVisible)
    {
        D2Win_10053(gpGatewayList, nLine);
        nLine = 0;
    }
    sub_004FB9D0_Select(gpGatewayList, nLine);
    MAINMENUS_ShowCurrentGateway();
    return 1;
}

int __fastcall sub_004FB990_GetSelection(D2WinControlStrc* pControl);                                       // 0x004FB990

int __stdcall SetCurGateway(D2FuncRecordStrc* pRecord, int nIndex);                                          // 0x00518150

struct D2ComInterfaceStrc;

extern D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0

// 0x00434700
int __stdcall MAINMENUS_OnRealmSelected(SMSGHANDLER_PARAMS* pMsg)
{
    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
    int nSelection = sub_004FB990_GetSelection(gpGatewayList);
    if (nSelection != -1)
    {
        nSelection += 1;
        SetCurGateway(pRecord, nSelection);
        SRegSaveString("Diablo II", "Preferred Realm", 0, sub_005180E0(pRecord, nSelection));
    }
    MAINMENUS_Reset();
    sub_004336C0();
    return 1;
}

// 0x00434760
int __stdcall MAINMENUS_ResetAndLeave(int nArg)
{
// build: symbol ?MAINMENUS_Reset@* 0x0042F480
    MAINMENUS_Reset();
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
    sub_004336C0();
    return 1;
}

// 0x00434790
int __stdcall MAINMENUS_JoinTcpIp(int nUnused)
{
    char szText[0x400];
    int a;
    int b;
    int c;
    int d;
    const Unicode* pText = sub_004FDD90_GetEditText(gpAddressEdit);
    sub_005263E0(szText, pText, 0x100);
    if (!szText[0])
        return 1;
    strncpy(gszLastTcpIpAddress, szText, 0xFF);
    gszLastTcpIpAddress[0xFF] = 0;
    SRegSaveString("Diablo II", "LastTcpIp", 0, gszLastTcpIpAddress);
    if (sscanf(szText, "%d.%d.%d.%d", &a, &b, &c, &d) != 4)
    {
        const char* szResolved = FOG_ResolveHostIPAddress(szText);
        if (szResolved)
        {
            strcpy(szText, szResolved);
        }
        else
        {
            sub_004FFE10_SetTextA(gpAddressEdit, &gszEmptyAssertText);
            return 1;
        }
    }
    strcpy(gpLaunchRecord->szServerIP, szText);
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(sub_00431D10);
    gbConnectResult = 0;
    sub_0052A750(0, szText);
    sub_004FA590_RunLoop(sub_00431E30);
    if (!gbConnectResult)
    {
        sub_0052A7E0();
        MAINMENUS_DestroyControls();
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x145B);
// build: symbol ?CHARSEL_CreateTcpIpScreen@* 0x0042FFE0
        MAINMENUS_ShowMessage(pMessage, CHARSEL_CreateTcpIpScreen, 1);
        return 1;
    }
    MAINMENUS_DestroyControls();
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(sub_00431C90);
    sub_0052A7E0();
    MAINMENUS_DestroyControls();
    if (!gdwGlobal_00779974)
    {
        gnLaunchMode = 2;
        gpLaunchRecord->dwGameType = 9;
        gpLaunchRecord->wJoinID = 1;
        sub_00515020();
        MAINMENUS_Reset();
        CHARSEL_InitCharSelectScreen();
    }
    return 1;
}

struct D2LaunchCharEntryStrc
{
    char szName[0x100];                                     // 0x000
    Unicode wszName[0x100];                                 // 0x100
    unsigned char aFlags[16];                               // 0x300
    unsigned char aColors[16];                              // 0x310
    unsigned char nType;                                    // 0x320
    unsigned char unk0x321;                                 // 0x321
    union
    {
        unsigned short nLevel;                              // 0x322
        short nWord322;
        char cLevel;
    };
    union
    {
        struct
        {
            union
            {
                unsigned short wFlags;                      // 0x324
                short nWord324;
            };
            short nWord326;                                 // 0x326
        };
        int nFlags;                                         // 0x324
    };
    short nWord328;                                         // 0x328
    char szCode32A[4];                                      // 0x32A
    union
    {
        unsigned char nByte32E;                             // 0x32E
        char cByte32E;
    };
    union
    {
        unsigned char nByte32F;                             // 0x32F
        char cByte32F;
    };
    union
    {
        unsigned char nByte330;                             // 0x330
        char cByte330;
    };
    char unk0x331[3];                                       // 0x331
    int nState;                                             // 0x334
    union
    {
        D2CompositeUnitStrc* pCompositeUnit;                // 0x338
        D2CelFileStrc* pCellFile;
        void* pAnim;
    };
    int unk0x33C;                                           // 0x33C
    unsigned int nKeyLow;                                   // 0x340
    unsigned int nKeyHigh;                                  // 0x344
    union
    {
        unsigned int nExpireTime;                           // 0x348
        int nFlag348;
    };
    D2LaunchCharEntryStrc* pNext;                           // 0x34C
};

void __fastcall WINMAIN_SendMcpCharDelete(const char* szName, unsigned short nArg);                                      // 0x0044A7A0

void __fastcall WINMAIN_SendMcpCharUpgrade(const char* szName);                                                           // 0x0044A810

int __fastcall MAINMENUS_DeleteCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x00434960

int __fastcall MAINMENUS_UpgradeCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName); // 0x004349B0

// 0x00434960
int __fastcall MAINMENUS_DeleteCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!MCPCONNECT_QueryAddress())
    {
        int nResult = MAINMENUS_ConnectToRealm(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    MAINMENUS_ShowConnectingPopup();
    WINMAIN_SendMcpCharDelete(pEntry->szName, 0);
    sub_004FA590_RunLoop(MAINMENUS_PollCharDelete);
    return 1;
}

// 0x004349B0
int __fastcall MAINMENUS_UpgradeCharacter(D2LaunchCharEntryStrc* pEntry, const char* szName)
{
    if (!MCPCONNECT_QueryAddress())
    {
// build: symbol ?MAINMENUS_ConnectToRealm@* 0x00432480
        int nResult = MAINMENUS_ConnectToRealm(szName, 0);
        if (nResult >= 1 && nResult <= 2)
        {
            D2MCPClientCloseMCP();
            return 0;
        }
    }
    MAINMENUS_ShowConnectingPopup();
    WINMAIN_SendMcpCharUpgrade(pEntry->szName);
    sub_004FA590_RunLoop(MAINMENUS_PollCharUpgrade);
// build: symbol ?GAME_GetConnectError@* 0x00449C00
    return GAME_GetConnectError() == 0;
}

// 0x00434A00
int __fastcall MAINMENUS_JoinGame(const char* szGameName, unsigned short wFlags, char nMode, const char* szPassword)
{
    int bPassword = szPassword[0] != 0;
    strcpy(gpLaunchRecord->szJoinGameName, szGameName);
    strcpy(gpLaunchRecord->szGamePassword, szPassword);
    gpLaunchRecord->wFlags1EF = wFlags;
    MAINMENUS_SetModeFlags(nMode);

    if (gnLaunchMode == 1 || gnLaunchMode == 3)
    {
        if (!gpFuncTable_0077ABF0->pfnSlot68())
        {
            CHARSEL_CreateBaseScreen();
            if (!sub_0043BF60())
                return 0;
            if (!CHARSEL_Connect(gpLaunchRecord, 0, 0))
                return 0;
        }
    }

    if (gnLaunchMode == 0)
    {
        gpLaunchRecord->nByte35E = 1;
        gnLaunchState = 1;
        gpLaunchRecord->dwGameType = 0;
        gpLaunchRecord->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord->dwFlags209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            gpLaunchRecord->dwFlags209 |= 0x100000;
        D2Win_StopMessageLoop();
        return 1;
    }

    if (gnLaunchMode == 2)
    {
        gpLaunchRecord->nByte35E = 3;
        gnLaunchState = 1;
        gpLaunchRecord->dwFlags209 = 4;
        if (wFlags & 4)
            gpLaunchRecord->dwFlags209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            gpLaunchRecord->dwFlags209 |= 0x100000;
        D2Win_StopMessageLoop();
        return 1;
    }
    {
        int bNewGame;
        if (bPassword)
        {
            switch (MAINMENUS_ConnectToRealm(szPassword, 0))
            {
            case 1:
                return 0;
            case 2:
            {
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x145B);
                MAINMENUS_ShowMessage(pText, MAINMENUS_ReturnToCharSelect, 1);
                return 1;
            }
            }

            if (GAME_GetConnectError())
            {
                D2MCPClientCloseMCP();
                int nString;
                switch (GAME_GetConnectError())
                {
                case 2:
                    nString = 0x145B;
                    break;
                case 0x47:
                    nString = 0x145C;
                    break;
                default:
                    nString = 0x145B;
                    break;
                }
                const Unicode* pText = D2LANG_GetStringFromTblIndex(nString);
                MAINMENUS_ShowMessage(pText, MAINMENUS_ReturnToCharSelect, 1);
                return 1;
            }

            CHATDLG_RequestCharLogon(gpLaunchRecord->szJoinGameName);
            MAINMENUS_ShowConnectingPopup();
            sub_004FA590_RunLoop(MAINMENUS_PollCharLogon);
            int nState = GAME_GetConnectError();
            if (nState == 0x46 || !MCPCONNECT_QueryAddress())
            {
                MAINMENUS_DestroyControls();
                const Unicode* pText = D2LANG_GetStringFromTblIndex(0x140D);
                MAINMENUS_ShowMessage(pText, MAINMENUS_ReturnToCharSelect, 1);
                return 0;
            }

            if (nState == 0x7B)
            {
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord->szJoinGameName, 256);
                D2MCPClientCloseMCP();
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszName);
                MAINMENUS_DestroyControls();
                void* pSaved = gpGlobal_0070B738;
                gpGlobal_0070B738 = gaGlobal_007089C4;
                MAINMENUS_ShowMessage(wszText, MAINMENUS_ReturnToCharSelect, 1);
                gpGlobal_0070B738 = pSaved;
                return 0;
            }

            if (gdwGlobal_00779974)
            {
                MAINMENUS_DestroyControls();
                return 0;
            }

            bNewGame = 0;
        }
        else
        {
            gpLaunchRecord->nByte22D = 0;
            gpLaunchRecord->szGamePassword[0] = 0;
            bNewGame = 1;
        }

        if (!bNewGame)
        {
            gpLaunchRecord->nByte35E = 2;
        }
        else
        {
            gpLaunchRecord->nByte35E = 4;
            gpLaunchRecord->dwFlags209 = 4;
            if (wFlags & 4)
                gpLaunchRecord->dwFlags209 = 0x804;
            if (gpLaunchRecord->wFlags1EF & 0x20)
                gpLaunchRecord->dwFlags209 |= 0x100000;
        }

        gnLaunchState = 3;
        MAINMENUS_ShowConnectingPopup();
        sub_004FA590_RunLoop(MAINMENUS_StopLoop);
        D2Win_StopMessageLoop();
        return 1;
    }
}

// 0x00434D90
int __stdcall MAINMENUS_PlayIntroAndLeave(int nArg)
{
// build: symbol ?D2Win_10003@* 0x004F9050
    if (D2Win_10003())
        MAINMENUS_PlayIntroVideo();
    D2Win_10004(1);
    MAINMENUS_CreateVideoScreen();
    return 1;
}

// 0x00434DC0
int __stdcall sub_00434DC0_Leave(int nArg)
{
    sub_004336C0();
    return 1;
}

// 0x00434DD0
int __stdcall MAINMENUS_DisconnectAndLeave(int nArg)
{
// build: symbol ?CHARSEL_DisconnectBattleNet@* 0x0043B9A0
    CHARSEL_DisconnectBattleNet();
    sub_004336C0();
    return 1;
}

// 0x00434DF0
int __stdcall sub_00434DF0_Leave(int nArg)
{
    sub_004336C0();
    return 1;
}

// build: symbol ?MAINMENUS_SetMultilineText@* 0x004330A0
static int __stdcall MAINMENUS_SetMultilineText(D2WinControlStrc* pControl, int nArg, const Unicode* pText, bool bWrapped)
{
    Unicode aBuffer[0x400];
    for (int i = 0; i < 0x400; ++i)
        aBuffer[i].wChar = 0;
    sub_00526790(aBuffer, pText, 0x400);
    Unicode* pChar = aBuffer;
    Unicode* pLine = pChar;
    while (pChar->wChar)
    {
        if (pChar->wChar == 0xA)
        {
            pChar->wChar = 0;
            D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
            pLine = pChar + 1;
        }
        ++pChar;
    }
    if (pLine < pChar)
        D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
    return 1;
}

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    D2WinControlStrc* pFrame;
    D2WinControlStrc* pButton;
    D2WinControlStrc* pTextBox;
    MAINMENUS_DestroyControls();
    if (gbFeCharPalette)
    {
        pFrame = MAINMENUS_CreateFromTemplate(0xF7);
        D2Win_10033(pFrame, 1);
        pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xF8 : 0xFA);
        pTextBox = MAINMENUS_CreateFromTemplate(0xF9);
    }
    else
    {
        pFrame = MAINMENUS_CreateFromTemplate(0xDE);
        D2Win_10033(pFrame, 1);
        pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
        pTextBox = MAINMENUS_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    MAINMENUS_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone = pfnDone;
}

// 0x00434E00
int __stdcall MAINMENUS_CheckFreeSpace(int nUnused)
{
    char szPath[0x400];
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpPasswordEdit);
    FOG_GetSavePath(szPath, 0x400);
    for (unsigned int i = 0; i < 0x400; i += 1)
    {
        if (szPath[i] == '\\')
        {
            szPath[i + 1] = 0;
            break;
        }
    }
    unsigned long nSectorsPerCluster = 0;
    unsigned long nBytesPerSector = 0;
    unsigned long nFreeClusters = 0;
    unsigned long nTotalClusters = 0;
    GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
    if (nFreeClusters * nBytesPerSector * nSectorsPerCluster < 5000)
    {
        MAINMENUS_ShowMessage(D2LANG_GetStringFromTblIndex(0x141D), MAINMENUS_ReturnToCharSelect, 1);
        return 1;
    }
    return MAINMENUS_ShowTerms();
}

// 0x00435020
int __stdcall MAINMENUS_Callback(int nUnused)
{
    sub_004336C0();
    return 1;
}

// 0x00435030
int __stdcall MAINMENUS_ChangePasswordOk(int nArg)
{
    if (!nArg)
    {
        sub_004370C0();
        return 1;
    }
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpCreatePasswordEdit);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpAccountEdit);
    const Unicode* pOldPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpCreatePasswordEdit);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpCreatePasswordConfirmEdit);
    sub_00526F70(gszOldPassword, pOldPassword, 0x100);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateLoginScreen, 1);
        return 1;
    }
    gbConnectCancelled = 0;
    if (!CHARSEL_Connect(gpLaunchRecord, 0, 1))
    {
        if (gbConnectCancelled)
        {
            MAINMENUS_CreateLoginScreen();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord->szAccount);
        MAINMENUS_DestroyControls();
        MAINMENUS_ReturnToCharSelect();
    }
    return 1;
}

// 0x00435200
int __stdcall MAINMENUS_CancelDownload(int nArg)
{
    gpFuncTable_0077ABF0->pfnSlot70();
    gbStopMainLoop = 1;
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00435230
void __cdecl MAINMENUS_PlayIntroVideos()
{
// build: symbol ?gpLaunchRecord@* 0x007795D4
    D2_ASSERT(!gpLaunchRecord->bIntroPlayed, 0x8D4);
    D2Win_10029(0);
    MAINMENUS_Reset();
    MAINMENUS_FlushInput();
    if (D2Win_10003())
    {
        if (!sub_0040EB10())
        {
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\New_BLIZ640x480.bik", 0, 0);
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\BlizNorth640x480.bik", 0, 0);
        }
        else
        {
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\New_BLIZ640x240.bik", 2, 0);
            WINDOW_OpenSmackCutscene("Data\\Local\\Video\\BlizNorth640x240.bik", 2, 0);
        }
        if (!MAINMENUS_InitAuxBattleNet())
        {
            void* hMpq = 0;
            SFileOpenArchive("d2video.mpq", 0x64, 0, &hMpq);
            if (hMpq)
            {
                MAINMENUS_PlayIntroVideo();
                SFileCloseArchive(hMpq);
            }
        }
        else
        {
// build: symbol ?FOG_IsExpansion@* 0x00408F20
            if (FOG_IsExpansion() && MAINMENUS_GetAuxBattleNetFlag())
                MAINMENUS_PlayIntro();
        }
    }
    D2Win_10004(1);
    MAINMENUS_CreateVideoScreen();
}

struct D2WinControlStrc;

// 0x00435330
void __cdecl MAINMENUS_ShowLoginScreen()
{
    char szAccount[0x400];
    s_bGatewayFlag_00779954 = 1;
    int bConnected = gpFuncTable_0077ABF0->pfnSlot68();
    if (bConnected && !CHARSEL_IsBattleNetConnected())
        goto create;
    if (bConnected)
        CHARSEL_DisconnectBattleNet();
    sub_004336C0();
    if (!sub_0043BF60())
        return;
create:
    gpAccountEdit = 0;
    gpPasswordEdit = 0;
// build: symbol ?gpCreatePasswordConfirmEdit@* 0x007795A8
    gpCreatePasswordConfirmEdit = 0;
    gpControl_00779594 = 0;
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1469));
    if (!FOG_IsExpansion())
    {
        pControl = MAINMENUS_CreateControl(0x1F);
        sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1454), 0, 0, 0);
    }
    pControl = MAINMENUS_CreateControl(0x20);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x1455), 0, 0, 0);
    gpAccountEdit = MAINMENUS_CreateControl(0x22);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    sub_004FDB00_SetEnterCallback(gpAccountEdit, MAINMENUS_OnLoginChanged);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, MAINMENUS_IsRestrictedChar);
    gpPasswordEdit = MAINMENUS_CreateControl(0x23);
    sub_004FDD50_SetMaxLength(gpPasswordEdit, 0xD);
    sub_004FDB00_SetEnterCallback(gpPasswordEdit, MAINMENUS_OnLoginChanged);
    sub_004FDAD0_SetKeyCallback(gpPasswordEdit, sub_0042FE60_KeyFilter);
    if (SRegLoadString("Diablo II", "Last BNet", 0, szAccount, 0x400))
    {
        D2Win_10076(gpAccountEdit, szAccount);
        CONTROL_SetFocusedEditBox(gpPasswordEdit);
    }
    else
        CONTROL_SetFocusedEditBox(gpAccountEdit);
    sub_004FDDD0_LinkTab(gpAccountEdit, gpPasswordEdit);
    sub_004FDDD0_LinkTab(gpPasswordEdit, gpAccountEdit);
    MAINMENUS_CreateControl(0x24);
    MAINMENUS_CreateControl(0x25);
    gpControl_00779594 = MAINMENUS_CreateControl(0x26);
    MAINMENUS_CreateControl(0x27);
    MAINMENUS_UpdateLoginOk();
    if (gnValue_00779980)
    {
        pControl = MAINMENUS_CreateControl(0x28);
        D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B62));
    }
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
}

// 0x00435580
void __cdecl MAINMENUS_CreateCharCreateScreen()
{
    MAINMENUS_LoadCharCreateCells();
    MAINMENUS_Reset();
    gnGlobal_00708D0C = -1;
    gnGlobal_0070CB80 = -1;
    gpLaunchRecord->wFlags1EF = 0;
    MAINMENUS_ReadPaletteFiles(gszFecharPalDat_006D39E8, "palette\\fechar\\pal.pl2");

    MAINMENUS_CreateControl(0xB1);
    gpControl_007795D8 = MAINMENUS_CreateControl(0xC5);
    gpControl_007795DC = MAINMENUS_CreateControl(0xC6);
    D2WinControlStrc* pTitle = MAINMENUS_CreateControl(0xAE);
    sub_004FC9B0_SetText(pTitle, D2LANG_GetStringFromTblIndex(0x1407), 0, 0, 0);

    if (gnLaunchMode == 1)
    {
        gpControl_0077933C = MAINMENUS_CreateControl(0xC7);
        sub_004FB740(gpControl_0077933C, -6, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B87), 1, 0, 0);
        sub_004FC9B0_SetText(gpControl_0077933C, D2LANG_GetStringFromTblIndex(0x2B88), 1, 0, 0);
    }

    CONTROL_SetEscapeButton(MAINMENUS_CreateControl(0xAF));
    gpControl_00779598 = MAINMENUS_CreateControl(0xC8);
    gpControl_007795CC = MAINMENUS_CreateControl(0xC9);
    sub_004FC9B0_SetText(gpControl_007795CC, D2LANG_GetStringFromTblIndex(0x1405), 4, 0, 0);
    gpNameEdit = MAINMENUS_CreateControl(0xCC);
    sub_004FDD50_SetMaxLength(gpNameEdit, 0x10);
    sub_004FDAD0_SetKeyCallback(gpNameEdit, MAINMENUS_FilterNameChar);
    sub_004FDB00_SetEnterCallback(gpNameEdit, MAINMENUS_OnNameChanged);

    if (FOG_IsExpansion())
    {
        gpControl_00779568 = MAINMENUS_CreateControl(0xD3);
        sub_004FC9B0_SetText(gpControl_00779568, D2LANG_GetStringFromTblIndex(0x58CB), 4, 0, 0);
        sub_004F9740_SetControlState(gpControl_00779568, 0);
        gpControl_007795C8 = MAINMENUS_CreateControl(0xD4);
        sub_004F9740_SetControlState(gpControl_007795C8, 0);
        gpControl_007795B4 = MAINMENUS_CreateControl(0xD5);
        sub_004F9740_SetControlState(gpControl_007795B4, 0);
        gpControl_007795B0 = MAINMENUS_CreateControl(0xBD);
        sub_004FC9B0_SetText(gpControl_007795B0, D2LANG_GetStringFromTblIndex(0x1406), 4, 0, 0);
        gpControl_007795C4 = MAINMENUS_CreateControl(0xBE);
        if (gnLaunchMode == 1)
        {
            if (gnGlobal_00779DA4)
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xC3);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC4);
            }
            else
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xC1);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC2);
            }
        }
    }
    else
    {
        gpControl_007795B0 = MAINMENUS_CreateControl(0xCA);
        sub_004FC9B0_SetText(gpControl_007795B0, D2LANG_GetStringFromTblIndex(0x1406), 4, 0, 0);
        gpControl_007795C4 = MAINMENUS_CreateControl(0xCB);
        if (gnLaunchMode == 1)
        {
            if (gnGlobal_00779DA4)
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xC1);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC2);
            }
            else
            {
                gpControl_007795B8 = MAINMENUS_CreateControl(0xBF);
                gpControl_00779348 = MAINMENUS_CreateControl(0xC0);
            }
        }
    }

    if (gnLaunchMode == 1)
    {
        sub_004FC9B0_SetText(gpControl_007795B8, D2LANG_GetStringFromTblIndex(0x2AAF), 4, 0, 0);
    }

    gpOkButton = MAINMENUS_CreateControl(0xB0);
    if (!gnGlobal_00779DA4)
    {
        CONTROL_SetEnabled(gpControl_007795C4, 0);
        CONTROL_SetEnabled(gpControl_007795B0, 0);
    }

    sub_004F9740_SetControlState(gpControl_00779598, 0);
    sub_004F9740_SetControlState(gpControl_007795CC, 0);
    sub_004F9740_SetControlState(gpControl_007795B0, 0);
    sub_004F9740_SetControlState(gpControl_007795C4, 0);
    sub_004F9740_SetControlState(gpNameEdit, 0);
    sub_004F9740_SetControlState(gpOkButton, 0);
    if (gnLaunchMode == 1)
    {
        sub_004F9740_SetControlState(gpControl_007795B8, 0);
        sub_004F9740_SetControlState(gpControl_00779348, 0);
    }

    gapClassImages = MAINMENUS_CreateControl(0xB6);
    if (FOG_IsExpansion())
    {
        gpControl_00779578 = MAINMENUS_CreateControl(0xBA);
        gpControl_0077957C = MAINMENUS_CreateControl(0xBB);
        gpControl_00779570 = MAINMENUS_CreateControl(0xB5);
        gpControl_00779584 = MAINMENUS_CreateControl(0xD1);
        gpControl_00779574 = MAINMENUS_CreateControl(0xBC);
        gpControl_00779580 = MAINMENUS_CreateControl(0xD2);
        MAINMENUS_CreateControl(0xB2);
    }
    else
    {
        gpControl_00779570 = MAINMENUS_CreateControl(0xB5);
        gpControl_00779578 = MAINMENUS_CreateControl(0xB7);
        gpControl_00779574 = MAINMENUS_CreateControl(0xB4);
        gpControl_0077957C = MAINMENUS_CreateControl(0xB8);
        MAINMENUS_CreateControl(0xB3);
    }

    MAINMENUS_UpdateNameOk();
}

// 0x004359D0
int __fastcall MAINMENUS_RunFrontEnd(D2ConfigStrc* pRecord)
{
// build: symbol ?gpLaunchRecord@* 0x007795D4
    gpLaunchRecord = pRecord;
    D2Win_10015();
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    D2_ASSERT(sub_005259C0(sub_004FAC80(FOG_IsExpansion()), 0), 0x125A);
    MAINMENUS_LoadFrontEndCells();
    CURSOR_SetCellFile(gpCursorOHandCelFile);
    gpLaunchRecord->szRealm0x361[0] = 0;
    gpLaunchRecord->szRealm0x381[0] = 0;
    gpLaunchRecord->szGameName[0] = 0;
    gpLaunchRecord->szText0x245[0] = 0;
    if (gnLaunchMode != 2)
        gpLaunchRecord->szServerIP[0] = 0;
    D2SOUNDFAST_InitWaveSlots();
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\button.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\amazon select.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\amazon deselect.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\barbarian select.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\barbarian deselect.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\paladin select.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\paladin deselect.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\necromancer select.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\necromancer deselect.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\sorceress select.wav");
    D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\sorceress deselect.wav");
    if (FOG_IsExpansion())
    {
        D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\druid select.wav");
        D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\druid deselect.wav");
        D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\assassin select.wav");
        D2SOUNDFAST_PreloadWave("data\\global\\sfx\\cursor\\intro\\assassin deselect.wav");
    }
    gpFuncTable_0077ABF0 = pRecord->pComInterface;
    const char nStartMode = gpLaunchRecord->nStartMode;
    if (nStartMode == 2)
    {
        if (gpFuncTable_0077ABF0->pfnSlot68())
        {
            gnLaunchMode = 1;
            sub_004F90A0(1);
            sub_0043B080();
        }
        else
        {
            gnLaunchMode = 1;
            sub_004F90A0(1);
            MAINMENUS_ShowLoginScreen();
        }
    }
    else if (nStartMode == 4)
    {
        if (gpFuncTable_0077ABF0->pfnSlot68())
        {
            gnLaunchMode = 3;
            sub_004F90A0(1);
            sub_0043B080();
        }
        else
        {
            gnLaunchMode = 3;
            sub_004F90A0(1);
            MAINMENUS_ShowLoginScreen();
        }
    }
    else if (nStartMode == 3)
    {
        CHARSEL_InitFuncTable(gpLaunchRecord);
        gnLaunchMode = 2;
        sub_004F90A0(1);
// build: symbol ?CHARSEL_CreateTcpIpScreen@* 0x0042FFE0
        CHARSEL_CreateTcpIpScreen();
    }
    else
    {
        CHARSEL_InitFuncTable(gpLaunchRecord);
        if (gpLaunchRecord->bRegistryMode)
        {
            unsigned long nValue = 0;
            SRegLoadValue("Diablo II", "Skip To Open", 0, &nValue);
            gpLaunchRecord->bRegistryMode = 0;
            gpLaunchRecord->bIntroPlayed = 1;
            sub_004F90A0(1);
            WINDOW_CenterWindow(1);
            gnLaunchMode = nValue ? 3 : 1;
            MAINMENUS_ShowLoginScreen();
        }
        else
        {
            if (!gpLaunchRecord->bIntroPlayed)
            {
                gnLaunchMode = 0;
                sub_004F90A0(1);
                WINDOW_CenterWindow(1);
                MAINMENUS_PlayIntroVideos();
                gpLaunchRecord->bIntroPlayed = 1;
            }
            else
            {
                gnLaunchMode = 0;
                sub_004F90A0(1);
                sub_004336C0();
            }
        }
    }
    D2Win_SetQuitCallback(sub_004309B0_ClearState);
    D2Win_RunMessageLoop(MAINMENUS_IdleLoopCallback);
    sub_00515020();
    while (D2SOUNDFAST_IsAnyWavePlaying())
        Sleep(0);
    D2SOUNDFAST_FreeWaveSlots();
// build: symbol ?MAINMENUS_Reset@* 0x0042F480
    MAINMENUS_Reset();
    MAINMENUS_FreeFrontEndCells();
    sub_00524E40();
    memset(gpLaunchRecord->adwSecret, 0, sizeof(gpLaunchRecord->adwSecret));
    sub_004FA550();
    return gnLaunchState;
}

// 0x00435CD0
int __stdcall MAINMENUS_OnSinglePlayer(int nArg)
{
    gnLaunchMode = 0;
    if (MAINMENUS_HasSaveFiles() == 1)
    {
        D2SOUNDFAST_FadeOutWaves();
        MAINMENUS_Reset();
        CHARSEL_InitCharSelectScreen();
        return 1;
    }

    MAINMENUS_CreateCharCreateScreen();
    return 1;
}

// 0x00435D10
int __stdcall MAINMENUS_OnOpenBattleNet(int nArg)
{
    gnLaunchMode = 3;
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x00435D30
int __stdcall MAINMENUS_OnBattleNet(int nArg)
{
    gnLaunchMode = 1;
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x00435D50
int __stdcall MAINMENUS_OnRealmDoubleClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (MAINMENUS_IsDoubleClick(pMsg))
        return MAINMENUS_OnRealmSelected(pMsg);
    return 1;
}

// 0x00435D80
int __stdcall MAINMENUS_OnTcpIpHost(int nArg)
{
    gpLaunchRecord->dwGameType = 8;
    strcpy(gpLaunchRecord->szServerIP, FOG_GetHostIPAddress());
    gnLaunchMode = 2;
    gpLaunchRecord->nValue209 = 4;
    if (!MAINMENUS_HasSaveFiles())
    {
        MAINMENUS_CreateCharCreateScreen();
        return 1;
    }

    D2SOUNDFAST_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
    return 1;
}

// 0x00435E00
int __stdcall MAINMENUS_Back(int nArg)
{
    sub_00435580();
    return 1;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00435E10
void __cdecl MAINMENUS_CreateRealmCharacter()
{
// build: symbol ?MAINMENUS_ConnectToRealm@* 0x00432480
    switch (MAINMENUS_ConnectToRealm(GAME_GetPreferredRealm(), 0))
    {
    case 1:
    case 2:
        sub_00435580();
        return;
    }

    if (!GAME_GetConnectError() && MCPCONNECT_QueryAddress())
    {
        if (MCPCONNECT_QueryAddress())
        {
            gpLaunchRecord->nLevel = 1;
            SMemCopy(gpLaunchRecord->szText0x3A1, gabDefault, 0x10);
            SMemZero(gpLaunchRecord->nComponentColors, 0x10);
            gpLaunchRecord->nByte3C2 = (gpLaunchRecord->wFlags1EF >> 6) & 1;
            gpLaunchRecord->wFlags3CB = gpLaunchRecord->wFlags1EF;
            CHATDLG_RequestCharCreate(gpLaunchRecord->szCharName, gpLaunchRecord->nClass, gpLaunchRecord->wFlags1EF);
            MAINMENUS_ShowConnectingPopup();
            sub_004FA590_RunLoop(MAINMENUS_PollCharCreate);
            if (gdwGlobal_00779974)
            {
                MAINMENUS_DestroyControls();
                return;
            }

            int nError = GAME_GetConnectError();
            if (nError)
            {
                if (nError != 20)
                {
                    Unicode wszName[100];
                    LOGMANAGER_WriteLogLine("Error from MCP trying to create '%s' (err=%d)", gpLaunchRecord->szCharName, GAME_GetConnectError());
                    D2MCPClientCloseMCP();
                    Unicode wszText[255];
                    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x145E));
                    Unicode wszTail[255];
                    sub_005267E0(wszTail, D2LANG_GetStringFromTblIndex(0x145F));
                    char szName[80];
                    sprintf(szName, "%s", gpLaunchRecord->szCharName);
                    sub_00526320_ToUnicode(wszName, szName, 100);
                    sub_00526700(wszText, wszName);
                    sub_00526700(wszText, wszTail);
                    MAINMENUS_ShowText(wszText, sub_00435580);
                    return;
                }

                D2MCPClientCloseMCP();
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord->szCharName, 256);
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0x2B33), wszName);
                MAINMENUS_ShowText(wszText, sub_00435580);
                return;
            }

            sub_0043C6A0(1);
            SStrCopy(gpLaunchRecord->szRealm, GAME_GetPreferredRealm(), 0x7FFFFFFF);
            gpLaunchRecord->wFlags1EF |= 2;
            gpLaunchRecord->nByte35E = 2;
            gnLaunchState = 3;
        }

        D2Win_StopMessageLoop();
        return;
    }

    D2MCPClientCloseMCP();
    int nString;
    switch (GAME_GetConnectError())
    {
    case 2:
        nString = 0x145B;
        break;

    case 10:
    case 11:
    case 12:
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x145D), sub_00435580);
        return;

    case 71:
        nString = 0x145C;
        break;

    default:
        nString = 0x145C;
        break;
    }

    MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(nString), MAINMENUS_ReturnToCharSelect);
}

// 0x004361B0
int __stdcall MAINMENUS_LoginOk(int nArg)
{
    if (!nArg)
    {
        sub_004336C0();
        return 1;
    }
    if (!sub_004F9710_TestFlag(gpControl_00779594))
        return 0;
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpPasswordEdit);
    if (CHARSEL_Connect(gpLaunchRecord, 0, 0))
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord->szAccount);
        if (gnLaunchMode == 1)
        {
            sub_00515020();
            MAINMENUS_Reset();
            CHARSEL_InitCharSelectScreen();
            return 1;
        }
        if (MAINMENUS_HasSaveFiles())
        {
            MAINMENUS_ReturnToCharSelect();
            return 1;
        }
        sub_00435580();
    }
    return 1;
}

// 0x00436270
int __stdcall MAINMENUS_OnShowLogin(int nArg)
{
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x00436280
int __stdcall MAINMENUS_ConnectOk(int nArg)
{
    gbConnectCancelled = 0;
    if (!CHARSEL_Connect(gpLaunchRecord, 1, 0))
    {
        if (gbConnectCancelled)
        {
            MAINMENUS_ShowLoginScreen();
            return 1;
        }
    }
    else
    {
        SRegSaveString("Diablo II", "Last BNet", 0, gpLaunchRecord->szAccount);
// build: symbol ?MAINMENUS_HasSaveFiles@* 0x00430BC0
        if (MAINMENUS_HasSaveFiles())
        {
            sub_00515020();
            MAINMENUS_Reset();
            sub_0043B080();
            return 1;
        }
        sub_00435580();
    }
    return 1;
}

// 0x00436300
int __stdcall MAINMENUS_BackToLogin(int nArg)
{
    MAINMENUS_DestroyControls();
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x00436320
int __stdcall MAINMENUS_GatewayOk(int nUnused)
{
    gbGatewayFlag = 1;
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x00436340
int __stdcall MAINMENUS_GatewayBack(int nUnused)
{
    gpfnGatewayDone = MAINMENUS_SetDone;
    MAINMENUS_DestroyControls();
    MAINMENUS_ShowLoginScreen();
    return 1;
}

// 0x00436360
int __stdcall MAINMENUS_SubmitCharacter(int nArg)
{
    if (gpLaunchRecord->nClass == 6 || gpLaunchRecord->nClass == 5)
        gpLaunchRecord->wFlags1EF |= 0x20;
    if (gnLaunchMode == 3)
    {
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader(gpLaunchRecord->szCharName, gpLaunchRecord->nClass, gpLaunchRecord->aDataED, gpLaunchRecord->wFlags1EF);
        CHATDLG_WriteSaveHeader(gpLaunchRecord->szCharName);
        gpLaunchRecord->nByte35E = 4;
        gnLaunchState = 3;
        *(int*)gpLaunchRecord->aState209 = 0x804;
        gpLaunchRecord->nByte22D = 0;
        gpLaunchRecord->szRealm[0] = 0;
        D2Win_StopMessageLoop();
        return 1;
    }
    if (gnLaunchMode == 0)
    {
        AUTOMAP_InitCharSaveHeader(gpLaunchRecord->szCharName, gpLaunchRecord->nClass, gpLaunchRecord->aDataED, gpLaunchRecord->wFlags1EF);
        CHATDLG_WriteSaveHeader(gpLaunchRecord->szCharName);
        gpLaunchRecord->nByte35E = 1;
        gpLaunchRecord->dwGameType = 0;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (gpLaunchRecord->wFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        gnLaunchState = 1;
        D2Win_StopMessageLoop();
        return 1;
    }
    if (gnLaunchMode == 2)
    {
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader(gpLaunchRecord->szCharName, gpLaunchRecord->nClass, gpLaunchRecord->aDataED, gpLaunchRecord->wFlags1EF);
        CHATDLG_WriteSaveHeader(gpLaunchRecord->szCharName);
        gpLaunchRecord->nByte35E = 3;
        gnLaunchState = 1;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (gpLaunchRecord->wFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
        return 1;
    }
    if (gnLaunchMode == 1)
        MAINMENUS_CreateRealmCharacter();
    return 1;
}

// 0x00436590
int __stdcall MAINMENUS_BackToCharCreate(int nArg)
{
    MAINMENUS_DestroyControls();
    sub_00435580();
    return 1;
}

// 0x004365B0
void __cdecl MAINMENUS_CreateCharacter()
{
    char szName[0x100];
    if (MAINMENUS_SaveExists() == 1 && gnLaunchMode != 1)
    {
        sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x142D), MAINMENUS_DestroyControls);
        return;
    }
    if (gpLaunchRecord->nMode == 6 || gpLaunchRecord->nMode == 5)
        gpLaunchRecord->wFlags1EF |= 0x20;
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit_0077934C);
    sub_005263E0(szName, pText, 0x100);
    sprintf((gpLaunchRecord->szPassword + 0x18), gszStringFormat, szName);
    gpLaunchRecord->szPassword[0x30] = 0;
    if (gpLaunchRecord->wFlags1EF & 0x20)
        gbFlag_00779984 = 1;
    if (gpLaunchRecord->wFlags1EF & 4)
    {
        sub_00430520();
        return;
    }
    if (gnLaunchMode == 0)
    {
        MAINMENUS_Reset();
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), gpLaunchRecord->wFlags1EF);
        sub_0043C6B0((gpLaunchRecord->szPassword + 0x18));
        gpLaunchRecord->nByte35E = 1;
        gpLaunchRecord->dwGameType = 0;
        gnLaunchState = 1;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (gpLaunchRecord->wFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode == 2)
    {
        MAINMENUS_Reset();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), gpLaunchRecord->wFlags1EF);
        sub_0043C6B0((gpLaunchRecord->szPassword + 0x18));
        gpLaunchRecord->nByte35E = 3;
        gnLaunchState = 1;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (gpLaunchRecord->wFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode == 3)
    {
        MAINMENUS_Reset();
        D2MCPClientCloseMCP();
        sub_0043C6A0(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), gpLaunchRecord->wFlags1EF);
        sub_0043C6B0((gpLaunchRecord->szPassword + 0x18));
        gpLaunchRecord->nLevel = 1;
        SMemCopy(gpLaunchRecord->szText0x3A1, gabDefault, 0x10);
        SMemZero(gpLaunchRecord->nComponentColors, 0x10);
        gpLaunchRecord->nByte3C2 = (gpLaunchRecord->wFlags1EF >> 6) & 1;
        gpLaunchRecord->wFlags3CB = gpLaunchRecord->wFlags1EF;
        gpLaunchRecord->nByte35E = 4;
        gpLaunchRecord->nByte22D = 0;
        gpLaunchRecord->szPassword[0x30] = 0;
        gnLaunchState = 3;
        *(int*)gpLaunchRecord->aState209 = 4;
        if (gpLaunchRecord->wFlags1EF & 4)
            *(int*)gpLaunchRecord->aState209 = 0x804;
        if (gpLaunchRecord->wFlags1EF & 0x20)
            *(int*)gpLaunchRecord->aState209 |= 0x100000;
        D2Win_StopMessageLoop();
    }
    else if (gnLaunchMode == 1)
    {
        MAINMENUS_CreateRealmCharacter();
    }
}

// 0x00436910
int __stdcall MAINMENUS_CreateAccountOk(int nArg)
{
    if (!nArg)
    {
        MAINMENUS_ShowLoginScreen();
        return 1;
    }
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpPasswordEdit);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpAccountEdit);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpCreatePasswordConfirmEdit);
    int nLength = sub_00526800(pAccount);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1460);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    if (nLength > 0xF)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1461);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    if (sub_00526590_Compare(pPassword, pConfirm))
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1462);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    nLength = sub_00526800(pPassword);
    if (nLength < 2)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1463);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    if (nLength > 0x14)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x1464);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_CreateMultiplayerScreen, 1);
        return 1;
    }
    MAINMENUS_CreateScreen();
    return 1;
}

// 0x004369F0
int __stdcall MAINMENUS_OnCharCreateOk(int nUnused)
{
    char szPath[0x400];
    if (sub_004F9710_TestFlags(gpOkButton_00779330))
    {
        FOG_GetSavePath(szPath, 0x400);
        for (unsigned int i = 0; i < 0x400; i += 1)
        {
            if (szPath[i] == '\\')
            {
                szPath[i + 1] = 0;
                break;
            }
        }
        unsigned long nSectorsPerCluster = 0;
        unsigned long nBytesPerSector = 0;
        unsigned long nFreeClusters = 0;
        unsigned long nTotalClusters = 0;
        GetDiskFreeSpaceA(szPath, &nSectorsPerCluster, &nBytesPerSector, &nFreeClusters, &nTotalClusters);
        if (nFreeClusters * nBytesPerSector * nSectorsPerCluster < 5000)
        {
            sub_00433460_ShowMessage(D2LANG_GetStringFromTblIndex(0x141D), MAINMENUS_ReturnToCharSelect);
            return 1;
        }
        CONTROL_SetEnabled(gpOkButton_00779330, 0);
        MAINMENUS_CreateCharacter();
    }
    return 1;
}

int __cdecl sub_0043B830(); // 0x0043B830

int gnStatusDots; // 0x007799B4

// 0x0043B4C0
int __stdcall MAINMENUS_OnRealmListClick(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gpNameControl@* 0x007799E8
    const Unicode* pText = sub_004FBB30_GetText(gpNameControl);
    sub_005263E0(gszEnteredName, pText, 0x100);
    CHARSEL_UseName(gszEnteredName);
    CHARSEL_RefreshCharEntry();
    if (MAINMENUS_IsDoubleClick(pMsg))
        return CHARSEL_OnRealmChosen(pMsg);
    return 1;
}

// build: symbol ?gszFormatD@* 0x006D57BC

void __fastcall sub_J02_EmitLaunchVideoPath(char* szOut, const char* szFormat, const char* szFile)
{
    MAINMENUS_BuildLocalizedVideoPath(szOut, szFormat, szFile);
    MAINMENUS_BuildLocalizedVideoPath(szOut + 1, szFormat, szFile);
}

#include "gen/data/Source/D2Launch/Src/MainMenus.inc"
