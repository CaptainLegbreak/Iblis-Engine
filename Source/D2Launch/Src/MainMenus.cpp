#include "D2Launch.h"
#include "D2MultiCharSave.h"

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
#include "FogApi.h"
#include "StormApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi2.h"
#include "StormApi2.h"
#include "D2GfxApi.h"
#include "D2SoundApi.h"
#include "D2NetApi.h"
#include "D2MCPClientApi.h"
#include "D2MultiApi.h"

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
    D2WinControlStrc* pControl;
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


int __fastcall MAINMENUS_ShowOptionDescription(unsigned int nArg, int nMode, int nStringId1, int nStringId2); // 0x004307A0

int __stdcall MAINMENUS_ShowLevelScreen(int nArg); // 0x00431600

extern "C" const char gszPercentS_006FFC58[]; // 0x006FFC58

extern "C" const char gszKernel32[]; // 0x006CD6E4

extern char gszServiceName[32]; // 0x007065DC

extern D2ServiceStatusStrc gD2ServerServiceStatus; // 0x007065FC

extern void* ghD2ServerServiceStatus; // 0x0074C714

extern int gnLaunchDirectFlags; // 0x0074C82C

int gnFlag_007798D0; // 0x007798D0

struct D2SlotEntryStrc
{
    int unk0x00;
    int nField04;
};

static D2LaunchSlotStrc** gppSlots; // 0x00779988

extern int gnSlotCount; // 0x0077998C


extern D2WinControlStrc* gpCreditsLeftList; // 0x0077995C

extern D2WinControlStrc* gpCreditsRightList; // 0x00779960

extern int gdwGlobal_00779990; // 0x00779990

extern D2WinControlStrc* gpCreditsList; // 0x00779964


int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0


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



int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

int __fastcall D2Win_10082(D2WinControlStrc* pEditBox); // 0x004FDD00

int __fastcall D2Win_StopMessageLoop(); // 0x004F9190

void __stdcall sub_004FA590_RunLoop(D2LaunchCallback pfnCallback); // 0x004FA590

void __cdecl MAINMENUS_CreateArchivePopup(); // 0x00431970

int gnLoaderFlag; // 0x007798E0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800



extern D2WinControlStrc* gpControl_007799D4; // 0x007799D4

D2ConfigStrc* gpLaunchRecord; // 0x007795D4



void __cdecl MAINMENUS_CreateLoginScreen(); // 0x00432100


int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0

void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0

void __cdecl CHARSEL_SetCancelled(); // 0x0043B810


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

extern D2WinControlStrc* gpButton; // 0x007799E4

extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230

void __cdecl MAINMENUS_UpdateNameOk(); // 0x00430620

void __cdecl MAINMENUS_UpdateLoginOk(); // 0x004306C0

int gfMenusDone; // 0x00779974

void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg); // 0x00433380

extern "C" void _ReadWriteBarrier(void);

void* __cdecl sub_00449AC0_GetHandle(); // 0x00449AC0

int __cdecl MAINMENUS_IsListedCode(); // 0x00432350

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



int __stdcall MAINMENUS_OnWait(int nArg); // 0x00432450

struct D2LaunchControlTemplateStrc;

struct D2LaunchRecord3Strc;



void __fastcall BUTTON_SetText(D2WinControlStrc* pControl, int nMode, unsigned short* pText, int nArg); // 0x005009D0

int __stdcall MAINMENUS_IsRestrictedChar(void* pControl, int nUnused, const char* pChar); // 0x0042FDE0

int __fastcall MAINMENUS_IsDoubleClick(SMSGHANDLER_PARAMS* pMsg); // 0x00431A60

int __stdcall MAINMENUS_OnRealmSelected(SMSGHANDLER_PARAMS* pMsg); // 0x00434700

void __cdecl CHARSEL_RefreshCharEntry(); // 0x0043A650

int __stdcall CHARSEL_OnRealmChosen(SMSGHANDLER_PARAMS* pMsg); // 0x0043A950

void __fastcall CHARSEL_UseName(char* szName); // 0x0043ADB0

void __fastcall CHATDLG_ShowTimedMessage(const Unicode* pText, D2LaunchCallback pfnDone); // 0x004401C0

// The front end's control templates (333 entries), indexed by template id.
extern D2LaunchControlTemplateStrc gatControlTemplates[]; // 0x00708D10

extern int gnTextMode; // 0x00708D0C

extern char gKey_0070CD54; // 0x0070CD54


void (__cdecl* gpfnGatewayDone)(); // 0x007795BC

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



int __fastcall sub_00526590_Compare(const Unicode* pString1, const Unicode* pString2);                      // 0x00526590

int __fastcall CHARSEL_Connect(D2ConfigStrc* pRecord, int bFlag, int nMode);                    // 0x0043C180



void __cdecl MAINMENUS_ShowLoginScreen();                                                                // 0x00435330

void __cdecl MAINMENUS_CreateScreen();                                                                   // 0x004325B0

char gszOldPassword[24];                                                                           // 0x00779550

int gbConnectCancelled; // 0x007795F4

struct UiControl;

extern "C" int __cdecl sub_00525150_Language();

extern "C" void __fastcall sub_004F9740_ControlFlag(UiControl* control,int value);

extern "C" UiControl* gControl;

















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


void __cdecl MAINMENUS_ShowLocalAddress();                                                               // 0x0042FF20

void __cdecl MAINMENUS_UpdateTwoEditOk(); // 0x00436CF0

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

#pragma intrinsic(strcpy)


int gnLaunchMode;                                                                                  // 0x007795EC




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

extern D2CelFileStrc* gpCellFile; // 0x00779700

extern D2CelFileStrc* gpFireCelFile; // 0x00779728

extern D2CelFileStrc* gpMediumSelButtonBlankCelFile; // 0x00779744

extern D2CelFileStrc* gpTextBoxCelFile; // 0x007797BC

extern D2CelFileStrc* gpClickBoxCelFile; // 0x007797C0

extern D2CelFileStrc* gpJoinGameClickBoxGreyCelFile; // 0x007797C4

extern D2CelFileStrc* gpBaFwSCelFile; // 0x007798B0

extern D2CelFileStrc* gpPaFwSCelFile; // 0x007798C4

extern D2CelFileStrc* gpCharacterCreateCelFile; // 0x00779724

extern int gnGatewayValue_007795BC; // 0x007795BC



void __cdecl MAINMENUS_FlushInput();                                                                     // 0x004317D0

void __cdecl sub_00430520_CreateControls();                                                                                // 0x00430520

void __stdcall MAINMENUS_CreateLevelScreen(int nLevel);                                                                    // 0x004313D0

void __cdecl MAINMENUS_ShowCurrentGateway();                                                                                // 0x00431AF0

void __cdecl MAINMENUS_CreateCharacter();                                                                                // 0x004365B0




D2WinControlStrc* gpOkButton; // 0x00779330

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




void __cdecl MAINMENUS_CreateVideoScreen(); // 0x0042FB20



int __cdecl MAINMENUS_ShowArchiveMessage(); // 0x00431A00

int __cdecl MAINMENUS_PromptPlayDisc(); // 0x00434220

int __cdecl MAINMENUS_PromptExpansionDisc(); // 0x004342E0

extern D2ConfigStrc* gpConfig_007795D4; // 0x007795D4

extern "C" const char gszMainMenusFile[]; // 0x006D41C0



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


int __cdecl MAINMENUS_CompareNames(const void* pEntry1, const void* pEntry2); // 0x00430B00

extern D2MenuListStrc* gpMenuList; // 0x007795C0

int __stdcall MAINMENUS_PollCharLogon(int nArg); // 0x00432FE0

int __cdecl sub_0043BF60_ConnectToBattleNet(); // 0x0043BF60



int __stdcall CHATDLG_RequestCharLogon(const char* szName); // 0x00449E10


extern char gaGlobal_007089C4[]; // 0x007089C4


int gnLaunchState; // 0x007795E8

static void MAINMENUS_SetModeFlags(char nMode); // 0x00431E70

int __stdcall MAINMENUS_IsRestrictedChar(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FDE0

int __stdcall sub_0042FE60_KeyFilter(D2WinControlStrc* pControl, int nArg, const char* pChar); // 0x0042FE60

int __stdcall MAINMENUS_OnLoginChanged(int nArg); // 0x00433BE0

int __cdecl CHARSEL_IsBattleNetConnected(); // 0x0043B840


void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060





int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10

extern int gnValue_00779980; // 0x00779980

int __stdcall MAINMENUS_FilterNameChar(D2WinControlStrc* pControl, int bAllowSep, const char* pChar); // 0x00430590

void __cdecl MAINMENUS_LoadCharCreateCells(); // 0x004326F0

int __stdcall MAINMENUS_OnNameChanged(int nArg); // 0x00433BD0


void __stdcall CONTROL_SetEscapeButton(void* pButton); // 0x004FA450

void __fastcall sub_004FB740(D2WinControlStrc* pList, int nA, int nB); // 0x004FB740

extern "C" const char gszFeCharPalDat[]; // 0x006D39E8

extern int gnTextMode; // 0x00708D0C


extern D2WinControlStrc* gpOkButton; // 0x00779330

D2WinControlStrc* gpControl_00779348; // 0x00779348

D2WinControlStrc* gpControl_00779568; // 0x00779568

D2WinControlStrc* gpControl_00779598; // 0x00779598

D2WinControlStrc* gpControl_007795B4; // 0x007795B4

D2WinControlStrc* gpControl_007795C8; // 0x007795C8

extern D2WinControlStrc* gpTextControl1; // 0x007795D8

extern D2WinControlStrc* gpTextControl2; // 0x007795DC

const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinControlStrc*); // 0x004FDD90

D2WinControlStrc* gpPasswordEdit; // 0x00779334

D2WinControlStrc* gpAccountEdit; // 0x0077958C

D2WinControlStrc* gpControl_00779594; // 0x00779594

static int s_bGatewayFlag_00779954; // 0x00779954

D2WinControlStrc* gpControl_0077933C; // 0x0077933C

D2WinControlStrc* gpNameEdit; // 0x0077934C

D2WinControlStrc* gapClassImages[7]; // 0x0077956C







D2WinControlStrc* gpControl_007795B0; // 0x007795B0

D2WinControlStrc* gpControl_007795B8; // 0x007795B8

D2WinControlStrc* gpControl_007795C4; // 0x007795C4

D2WinControlStrc* gpControl_007795CC; // 0x007795CC

int gnGlobal_00779DA4; // 0x00779DA4

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }








int __cdecl MAINMENUS_ShowTerms(); // 0x00433810

int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl); // 0x004F95C0


Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790



int __fastcall sub_005264F0_Compare(const Unicode* pString1, const Unicode* pString2); // 0x005264F0

void __fastcall MAINMENUS_ShowMessageBox(const Unicode* pTitle, const Unicode* pMessage, int nButton1StringId, int nButton2StringId, D2LaunchCallback pfnButton1, D2LaunchCallback pfnButton2, int bFlag1, int bFlag2); // 0x0042F540



int __stdcall MAINMENUS_PollCharCreate(int nArg); // 0x00432FA0

char* __cdecl GAME_GetPreferredRealm(); // 0x00437D00

int __stdcall CHATDLG_RequestCharCreate(const char* szName, int nClass, int nFlags); // 0x00449DF0


Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700


void __cdecl MAINMENUS_LoadFrontEndCells(); // 0x0042E6D0

int __cdecl MAINMENUS_InitAuxBattleNet(); // 0x0042FA40

int __cdecl MAINMENUS_GetAuxBattleNetFlag(); // 0x0042FAB0

int __cdecl MAINMENUS_SaveExists(); // 0x00431F70

void __cdecl MAINMENUS_PlayIntro(); // 0x004334E0

int __stdcall MAINMENUS_JoinTcpIp(int nUnused); // 0x00434790

int __stdcall MAINMENUS_OnCharCreateOk(int nUnused); // 0x004369F0

class BNGatewayAccess;


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



int __fastcall CHATDLG_WriteSaveHeader(const char* szName); // 0x0043C6B0


void __cdecl MAINMENUS_SetDone(); // 0x0042F6C0

int gnListPos; // 0x0077996C

void* gpfnArchiveLoader2; // 0x007798DC

int gnValue_0077994C; // 0x0077994C

int gnValue_00779950; // 0x00779950

extern int gbGatewayFlag; // 0x00779954

int __cdecl MAINMENUS_FreeSlots();

D2WinControlStrc* gpGatewayList; // 0x00779590

static void MAINMENUS_StoreAccountTexts(D2WinControlStrc* pAccountEdit, D2WinControlStrc* pPasswordEdit);

int gfConnectCancelled; // 0x007799D8

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

int __fastcall D2Win_10015();                                                                               // 0x004F8FE0

int __stdcall CURSOR_SetCellFile(D2CelFileStrc* pCellFile);                                                 // 0x004F9160

void __stdcall D2Win_SetQuitCallback(int (__cdecl* pfnQuitCallback)());                                                            // 0x004F9180

int __stdcall D2Win_RunMessageLoop(void (__stdcall* pCallback)(unsigned long));                                      // 0x004FA590

void* __stdcall sub_004FAC80(int nArg);                                                                     // 0x004FAC80


void __cdecl sub_0042F880_DestroyControls(); // 0x0042F880

extern D2WinControlStrc* gpControl_00779338; // 0x00779338

extern D2WinControlStrc* gpControl_00779588; // 0x00779588

extern D2WinControlStrc* gpControl_007795A0; // 0x007795A0

extern D2WinControlStrc* gpControl_007795A4; // 0x007795A4

void __cdecl sub_0042F800_CreateControls(); // 0x0042F800

void __cdecl sub_0042FA20_ClearStopMainLoop(); // 0x0042FA20

int __fastcall WINMAIN_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue); // 0x00449920
extern D2WinControlStrc* gpControl_007795AC; // 0x007795AC
extern int gbFeCharPalette; // 0x007795F0
extern const char gszTextExt[]; // 0x006D48E0
extern const char gszTosPrefix[]; // 0x006D48E8
int __fastcall D2Win_10121_GetTextWidth(const Unicode*); // 0x00501820
extern D2WinControlStrc* gpControl_0077933C; // 0x0077933C
extern D2WinControlStrc* gpControl_007795B0; // 0x007795B0
extern D2WinControlStrc* gpControl_007795B8; // 0x007795B8
extern D2WinControlStrc* gpControl_007795C4; // 0x007795C4
extern D2WinControlStrc* gpControl_007795CC; // 0x007795CC
extern "C" int __fastcall D2Win_10106(D2WinControlStrc*); // 0x00500310
int __fastcall D2Win_10104(D2WinControlStrc*); // 0x00500340
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinControlStrc*, int); // 0x005009A0
const char* __stdcall Name(D2FuncRecordStrc* pRecord, int nIndex); // 0x005180A0
extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData); // 0x006CC1C8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void*, unsigned long*); // 0x006CC2F0
extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900

// 0x00406870
void __fastcall MAINMENUS_InitStorm(int nDirectFlags, int nValue)
{
    SFileSetBasePath(".\\");
    SFileEnableDirectAccess(nDirectFlags);
    SFileSetIoErrorMode(0, 0);
    SFileEnableSeekOptimization(nValue);
    gnLaunchDirectFlags = nDirectFlags;
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
    wsprintfA(szPath, "%s\\UI\\FrontEnd\\blizno", gszDataGlobal);
    gpBlizNoCelFile = sub_004FA9B0_LoadCellFile(szPath, 0);
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
    ARCHIVE_FreeCellFile(gpCellFile);
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
    wsprintfA(szPathA, gszPathFormat, gszDataGlobal, szFile1);
    wsprintfA(szPathB, gszPathFormat, gszDataGlobal, szFile2);
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
    gfMenusDone = 1;
}

// 0x0042F6E0
void __cdecl MAINMENUS_ShowConnectingPopup()
{
    MAINMENUS_DestroyControls();
    gbGatewayFlag = 1;
    gfMenusDone = 0;
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
void __cdecl sub_0042F800_CreateControls()
{
    MAINMENUS_DestroyControls();
    gbGatewayFlag = 1;
    gfMenusDone = 0;
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

int __stdcall IMAGE_SetFrame(D2WinControlStrc* pBar, int nValue); // 0x004FD110

int __stdcall IMAGE_ForceNormalDrawMode(D2WinControlStrc* pBar, int nMode); // 0x004FD170

int __stdcall IMAGE_GetFrameCount(D2WinControlStrc* pBar); // 0x004FD1B0

D2WinControlStrc* gpProgressText; // 0x00779978

D2WinControlStrc* gpProgressBar; // 0x0077997C

struct D2ChatMessageStrc { D2WinControlStrc* pControl; unsigned int nMessage; };

static inline int ProgressBarValue(int nPercent)
{
    return nPercent * IMAGE_GetFrameCount(gpProgressBar) / 100;
}

// 0x0042F890
void __cdecl MAINMENUS_ShowProgressScreen()
{
    char szText[100];
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x116);
    gpProgressBar = MAINMENUS_CreateControl(0x117);
    IMAGE_ForceNormalDrawMode(gpProgressBar, 3);
    gpProgressText = MAINMENUS_CreateControl(0x113);
    int nPercent = gpFuncTable->pfnGetPatchState();
    if (nPercent > 100)
        nPercent = 100;
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x114);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x143A), 0, 0, 0);
    pControl = MAINMENUS_CreateControl(0x112);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x143B), 0, 0, 0);
    MAINMENUS_CreateControl(0x118);
    IMAGE_SetFrame(gpProgressBar, ProgressBarValue(nPercent));
    sprintf(szText, "%d%%", nPercent);
    sub_004FCFF0_SetTextA(gpProgressText, szText, 0);
}

// 0x0042F990
void __cdecl MAINMENUS_UpdateProgress()
{
    char szText[100];
    sub_004FB6A0_ClearText(gpProgressText);
    int nPercent = gpFuncTable->pfnGetPatchState();
    if (nPercent > 100)
        nPercent = 100;
    IMAGE_SetFrame(gpProgressBar, ProgressBarValue(nPercent));
    sprintf(szText, "%d%%", nPercent);
    if (gpProgressText)
        sub_004FCFF0_SetTextA(gpProgressText, szText, 0);
}

// 0x0042FA20
void __cdecl sub_0042FA20_ClearStopMainLoop()
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

// 0x0042FB20
void __cdecl MAINMENUS_CreateVideoScreen()
{
    MAINMENUS_Reset();
    MAINMENUS_CreateControl(2);
    MAINMENUS_CreateControl(3);
    MAINMENUS_CreateControl(6);
    MAINMENUS_CreateControl(7);
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(4);
    char szTail[0x200] = { 0 };
    char szText[0x200] = { 0 };
    unsigned short wszText[0x200];
    wszText[0] = 0;
    for (int i = 1; i < 0x200; i++)
        wszText[i] = 0;
    const char* szKey;
    if (FOG_IsExpansion())
    {
        UNICODE_ToUtf8(szText, D2LANG_GetStringFromTblIndex(0x557A), 0x200);
        szKey = "2001";
    }
    else
    {
        UNICODE_ToUtf8(szText, D2LANG_GetStringFromTblIndex(0x13F0), 0x200);
        szKey = "2000";
    }
    int nKeyLen = SStrLen(szKey);
    char* pFound = strstr(szText, szKey);
    if (pFound)
    {
        SStrCopy(szTail, pFound + nKeyLen, 0x7FFFFFFF);
        SStrCopy(pFound, "2000 - 2016", 0x7FFFFFFF);
        SStrCopy(pFound + SStrLen("2000 - 2016"), szTail, 0x7FFFFFFF);
    }
    sub_00526320_ToUnicode((Unicode*)wszText, szText, 0x200);
    sub_004FC9B0_SetText(pControl, (Unicode*)wszText, 4, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x13F1), 4, 0, 0);
    D2Win_10029(0);
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
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
    D2SOUNDFAST_FadeOutWaves();
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

    gpAccountEdit = MAINMENUS_CreateControl(0x54);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, MAINMENUS_FilterLoginChar);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    sub_004FFE10_SetTextA(gpAccountEdit, gpLaunchRecord->szAccount);

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
    if (gpFuncTable->pfnGetPatchState() == 0x65 || gbStopMainLoop)
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
void __cdecl sub_00430520_CreateControls()
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
    UNICODE_ToUtf8(szText, pText, 0x20);
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
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit);
    int bValid = 0;
    if (pText)
    {
        const int nLen = UNICODE_StrLen(pText);
        UNICODE_ToUtf8(szText, pText, 0x20);
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
    CONTROL_SetEnabled(gpOkButton, bValid);
}

// 0x004306C0
void __cdecl MAINMENUS_UpdateLoginOk()
{
    const Unicode* pName = sub_004FDD90_GetEditText(gpAccountEdit);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    int bOk = 0;
    if (pName && pPassword)
    {
        int nNameLength = UNICODE_StrLen(pName);
        int nPasswordLength = UNICODE_StrLen(pPassword);
        if (nNameLength >= 1 && nNameLength <= 50 && nPasswordLength >= 1 && nPasswordLength <= 13)
            bOk = 1;
    }
    if (gpControl_00779594)
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

// 0x00430840
int __stdcall MAINMENUS_OnHoverSorceress(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 1, 0xFAA, 0x140B);
    return 1;
}

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

// 0x00430920
int __stdcall MAINMENUS_OnHoverNecromancer(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 2, 0xFA9, 0x1409);
    return 1;
}

// 0x00430950
int __stdcall MAINMENUS_OnHoverBarbarian(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 4, 0xFA7, 0x140A);
    return 1;
}

// 0x00430980
int __stdcall MAINMENUS_OnHoverPaladin(SMSGHANDLER_PARAMS* pMsg)
{
    MAINMENUS_ShowOptionDescription(pMsg->lParam, 3, 0xFA8, 0x140C);
    return 1;
}

// 0x004309B0
void __cdecl MAINMENUS_ClearLaunchState()
{
    gnLaunchState = 0;
}

extern "C" int __fastcall CHATDLG_SetMainControlState(int value)
{
    sub_004F9740_ControlFlag(gControl, value);
    return 1;
}

extern int gnSlotCount; // 0x0077998C

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

// 0x00430B00
int __cdecl MAINMENUS_CompareNames(const void* pEntry1, const void* pEntry2)
{
    return strcmp(**(const char* const* const*)pEntry1, **(const char* const* const*)pEntry2);
}


// 0x00430B40
int __cdecl GAME_GetSlotNameCount()
{
    return gnSlotCount;
}

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

D2WinControlStrc* gpCreditsList;                                                                          // 0x00779964

// 0x00430C80
void __cdecl MAINMENUS_FillCreditsList()
{
    for (int i = 0; i < 50; i++)
        D2Win_10045(gpCreditsList, &gszEmptyAssertText);
    D2Win_10045(gpCreditsList, "The End");
    gnListPos = sub_004FB950_GetFirstVisible(gpCreditsList);
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

D2WinControlStrc* gpCreditsLeftList;                                                                          // 0x0077995C

D2WinControlStrc* gpCreditsRightList;                                                                          // 0x00779960

// 0x00430EF0
void __cdecl MAINMENUS_SyncCreditsLists()
{
    int nFirst = sub_004FB950_GetFirstVisible(gpCreditsList);
    int nSecond = sub_004FB950_GetFirstVisible(gpCreditsLeftList);
    int nThird = sub_004FB950_GetFirstVisible(gpCreditsRightList);
    while (nSecond > nThird)
    {
        D2Win_10045(gpCreditsRightList, &gszEmptyAssertText);
        nThird = sub_004FB950_GetFirstVisible(gpCreditsRightList);
    }
    while (nSecond < nThird)
    {
        D2Win_10045(gpCreditsLeftList, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpCreditsLeftList);
    }
    while (nFirst > nSecond)
    {
        D2Win_10045(gpCreditsLeftList, &gszEmptyAssertText);
        nSecond = sub_004FB950_GetFirstVisible(gpCreditsLeftList);
        D2Win_10045(gpCreditsRightList, &gszEmptyAssertText);
    }
    while (nFirst < nSecond)
    {
        D2Win_10045(gpCreditsList, &gszEmptyAssertText);
        nFirst = sub_004FB950_GetFirstVisible(gpCreditsList);
    }
    D2Win_10045(gpCreditsList, &gszEmptyAssertText);
    D2Win_10045(gpCreditsLeftList, &gszEmptyAssertText);
    D2Win_10045(gpCreditsRightList, &gszEmptyAssertText);
}

// 0x00431020
void __cdecl MAINMENUS_ClearCreditsLists()
{
    D2Win_10045(gpCreditsLeftList, &gszEmptyAssertText);
    D2Win_10045(gpCreditsRightList, &gszEmptyAssertText);
}

// 0x00431040
void __cdecl MAINMENUS_ClearCreditsList() {
 D2Win_10045(gpCreditsList,&gszEmptyAssertText);
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
        D2Win_10045(gpCreditsList, &gszEmptyAssertText);
        D2Win_10045(gpCreditsLeftList, &gszEmptyAssertText);
        D2Win_10045(gpCreditsRightList, &gszEmptyAssertText);
    }

    int nRemain = nLength;
    Unicode* pCursor = pText;
    while (nRemain)
    {
        if (pCursor->wChar == 0x2A)
        {
            D2Win_10045(gpCreditsLeftList, &gszEmptyAssertText);
            D2Win_10045(gpCreditsRightList, &gszEmptyAssertText);
            ++pCursor;
            if (sub_005267E0(wszLine, pCursor))
                sub_004FC9B0_SetText(gpCreditsList, wszLine, 1, 0, 0);
            else
                nRemain = 0;
            int nSkip = UNICODE_StrLen(wszLine) + 2;
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
                    int nSkip = UNICODE_StrLen(wszLine) + 2;
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
                        int nSkip = UNICODE_StrLen(wszLine) + 2;
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
                    sub_004FD060_SetText(gpCreditsLeftList, wszLeft);
                    sub_004FD060_SetText(gpCreditsRightList, wszRight);
                }
                else
                {
                    sub_004FD060_SetText(gpCreditsList, wszLeft);
                }
                D2Win_10045(gpCreditsList, &gszEmptyAssertText);
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
        gpCreditsLeftList = MAINMENUS_CreateControl(0x2B);
        gpCreditsRightList = MAINMENUS_CreateControl(0x2C);
        gpCreditsList = MAINMENUS_CreateControl(0x2D);
    }
    else
    {
        gpCreditsLeftList = MAINMENUS_CreateControl(0x2F);
        gpCreditsRightList = MAINMENUS_CreateControl(0x30);
        gpCreditsList = MAINMENUS_CreateControl(0x31);
    }
    gpControl_00779968 = MAINMENUS_CreateControl(0x2E);
    sub_004FD830(gpControl_00779968);
    sub_004FDA50(gpControl_00779968);
    MAINMENUS_ShowCredits(0);
    D2Win_10053(gpCreditsList, 20);
    D2Win_10053(gpCreditsLeftList, 20);
    D2Win_10053(gpCreditsRightList, 20);
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
    D2SOUNDSMP_FadeOutMasterVolume(0xB4);
    D2SOUND_StopChannel();
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
        WINDOW_OpenSmackCutscene(szPath, nMode, 0);
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

// 0x00431AF0
void __cdecl MAINMENUS_ShowCurrentGateway()
{
    D2FuncRecordStrc* pRecord = gpFuncTable->pfnGetBnGatewayAccess();
    char szText[0x100];
    const int nIndex = pRecord->nIndex;
    SStrCopy(szText, Name(pRecord, nIndex), 0x100);

    Unicode wszText[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszText[i].wChar = 0;
    sub_00526320_ToUnicode(wszText, szText, 0x100);

    Unicode wszFormat[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszFormat[i].wChar = 0;
    sub_005267E0(wszFormat, D2LANG_GetStringFromTblIndex(0x2B29));

    Unicode wszOut[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszOut[i].wChar = 0;
    memset(wszOut, 0, 0x100);
    sub_005269D0_FormatText(0x100, wszOut, wszFormat, wszText);

    for (int i = 0; i < UNICODE_StrLen(wszOut); ++i)
    {
        const unsigned short wChar = wszOut[i].wChar;
        wszOut[i].wChar = wChar < 0x100 ? gawToUpperTable[wChar] : wChar;
    }

    BUTTON_SetText(gpControl_007795AC, 10, (unsigned short*)wszOut, 0);
}

// 0x00431C30
int __stdcall MAINMENUS_Leave(int nArg)
{
    gnLaunchState = 0;
    D2SOUNDSMP_FadeOutMasterVolume(0xB4);
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

    if (gdwGlobal_00779990 || gfMenusDone)
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

// 0x00431F50
int __stdcall sub_00431F50_OnCancel(int nArg)
{
    D2SOUNDFAST_FadeOutWaves();
    MAINMENUS_Reset();
    CHARSEL_InitCharSelectScreen();
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
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit);
    UNICODE_ToUtf8(szUtf8, pText, 0x100);
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
        UNICODE_ToAscii(gpLaunchRecord->szAccount, pText, 0x100);
    }
    if (pPasswordEdit)
    {
        const Unicode* pText = sub_004FDD90_GetEditText(pPasswordEdit);
        UNICODE_ToAscii(gpLaunchRecord->szPassword, pText, 0x100);
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
    UNICODE_ToAscii(gpLaunchRecord->szAccount, pText, 0x100);
    MAINMENUS_CreateInfoScreen();
    return 1;
}

// 0x00432340
int __stdcall MAINMENUS_OpenInfoScreen(int nUnused)
{
    MAINMENUS_CreateInfoScreen();
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
        GAME_GetConnectError();
        return MAINMENUS_IsListedCode() ? 2 : 0;
    }
}

// 0x00432450
int __stdcall MAINMENUS_OnWait(int nArg)
{
    if (gfMenusDone)
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
    if (!gpFuncTable)
        goto fail;
    pPayload = gpFuncTable->pfnLogonRealm(szName, "password");
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
        gatControlTemplates[0x51].nY = 0x9B;
        gatControlTemplates[0x1A].nY = 0x14E;
        gatControlTemplates[0x1B].nY = 0x184;
        gatControlTemplates[0x1C].nY = 0x1BA;
        gatControlTemplates[0x1F].nY = 0xF0;
        gatControlTemplates[0x20].nY = 0x158;
        gatControlTemplates[0x5F].nY = 0x9C;
        gatControlTemplates[0xC9].nY = 0x1FA;
        gatControlTemplates[0xCA].nY = 0x22B;
        gatControlTemplates[0xBD].nY = 0x23F;
        gatControlTemplates[0xD3].nY = 0x22B;
        gatControlTemplates[0xBF].nY = 0x22B;
        gatControlTemplates[0xC1].nY = 0x23F;
        gatControlTemplates[0xC3].nY = 0x253;
        gatControlTemplates[0x103].nY = 0x46;
        gatControlTemplates[0x10C].nY = 0xEE;
    }
}

// 0x00432FA0
int __stdcall MAINMENUS_PollCharCreate(int nArg)
{
    sub_00449B70_Receive();
    if (GAME_IsMcpCharCreateReceived() || !MCPCONNECT_QueryAddress() || gfMenusDone)
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
    if (GAME_IsMcpCharLogonReceived() || !MCPCONNECT_QueryAddress() || gfMenusDone)
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
    if (GAME_IsMcpCharDeleteReceived() || !MCPCONNECT_QueryAddress() || gfMenusDone)
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
    if (GAME_IsMcpCharUpgradeReceived() || !MCPCONNECT_QueryAddress() || gfMenusDone)
    {
        CHATDLG_SetCharUpgradeReceived(0);
        D2Win_StopMessageLoop();
    }
    return 1;
}

// 0x004330A0
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

// 0x00433130
void __fastcall MAINMENUS_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xE7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xE8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xE9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText1, false);
    pControl = MAINMENUS_CreateFromTemplate(0xEA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone = pfnDone;
}

// 0x004331C0
void __fastcall MAINMENUS_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xEB);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xEC);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xED);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText1, false);
    if (pText3 && pText3->wChar)
    {
        pControl = MAINMENUS_CreateFromTemplate(0xEF);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
        pControl = MAINMENUS_CreateFromTemplate(0xF0);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        MAINMENUS_SetMultilineText(pControl, 4, pText3, false);
        gpfnGatewayDone = pfnDone;
        return;
    }
    pControl = MAINMENUS_CreateFromTemplate(0xEE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone = pfnDone;
}

// 0x004332B0
void __fastcall MAINMENUS_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xF1);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xF2);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xF3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText1, false);
    pControl = MAINMENUS_CreateFromTemplate(0xF4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
    pControl = MAINMENUS_CreateFromTemplate(0xF5);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText3, false);
    pControl = MAINMENUS_CreateFromTemplate(0xF6);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 4, pText4, false);
    gpfnGatewayDone = pfnDone;
}

// 0x00433380
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

// 0x00433460
void __fastcall MAINMENUS_ShowTextBox(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xF7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xFA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xF9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText, false);
    gpfnGatewayDone = pfnDone;
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
    WINDOW_OpenSmackCutscene(szPath, nMode, 0);
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
    WINDOW_OpenSmackCutscene(szPath, nMode, 0);
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
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
}

// 0x00433810
int __cdecl MAINMENUS_ShowTerms()
{
    char szLanguage[128];
    unsigned short wszLine[200];
    char szFileName[128];
    gbStopMainLoop = 0;
    sub_0042F800_CreateControls();
    STRTABLE_GetLanguageInfoField(szLanguage, 2);
    SStrCopy(szFileName, gszTosPrefix, 128);
    SStrPack(szFileName, szLanguage, 128);
    SStrPack(szFileName, gszTextExt, 128);
    gpFuncTable->pfn0x50(szFileName, strlen(szFileName));
    sub_004FA590_RunLoop(MAINMENUS_PollDownloadDone);
    if (gbStopMainLoop) { MAINMENUS_DestroyControls(); return 0; }
    if (!gpFuncTable->pfnIsSocketConnected())
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x14E3);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_ShowMainMenu, 1);
        return 0;
    }
    MAINMENUS_DestroyControls();
    MAINMENUS_CreateTermsControls();
    MAINMENUS_CreateControl(0x4D);
    D2WinControlStrc* pText = MAINMENUS_CreateControl(0x4E);
    void* hFile = FOG_CreateFileA(szFileName, 0x80000000, 0, 0, 3, 0x08000000, 0);
    if (hFile == (void*)-1)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x14E3);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_ShowMainMenu, 1);
        return 0;
    }
    unsigned long nSize = GetFileSize(hFile, 0);
    void* pBuffer = FOG_Alloc(nSize, gszMainMenusFile, 0xC4D, 0);
    unsigned long nRead;
    FOG_ReadFile(hFile, pBuffer, nSize, &nRead, 0);
    FOG_CloseFile(hFile);
    FOG_DeleteFileA(szFileName);
    Unicode* pChars = 0;
    int nCount;
    if (nSize == nRead && nSize > 2)
    {
        if (*(unsigned short*)pBuffer == 0xFEFF)
        {
            pChars = (Unicode*)pBuffer + 1;
            nCount = (nSize - 2) / 2;
        }
        else if (*(unsigned short*)pBuffer == 0xFFFE)
        {
            pChars = (Unicode*)pBuffer + 1;
            nCount = (nSize - 2) / 2;
            CHARSEL_SwapUnicodeBytes(pChars, nCount);
        }
        else
        {
            pChars = (Unicode*)FOG_Alloc(2*nSize+1, gszMainMenusFile, 0xC6B, 0);
            sub_00526F20_ToUnicode(pChars, (const char*)pBuffer, nSize);
            FOG_Free(pBuffer, gszMainMenusFile, 0xC6D, 0);
            pBuffer = pChars;
            nCount = nSize;
        }
    }
    else nCount = 0;
    int nStart = 0;
    int i = 0;
    while (i < nCount)
    {
        memset(wszLine, 0, sizeof(wszLine));
        int nLine = 0;
        do
        {
            if (i >= nCount) break;
            const unsigned short nChar = pChars[i].wChar;
            if (nChar == '\r' || nChar == '\n') { wszLine[nLine] = ' '; nLine = 200; ++i; }
            else if (nChar != '\t') { wszLine[nLine++] = nChar; ++i; }
            else { ++i; wszLine[nLine++] = ' '; }
            if (D2Win_10121_GetTextWidth((const Unicode*)wszLine) > 540)
            {
                int nLength = UNICODE_StrLen((const Unicode*)wszLine);
                while (nLength > 1 && !sub_00526D30_IsLineBreak(pChars + nStart, nLength)) --nLength;
                i = nStart + nLength;
                wszLine[nLength] = 0;
                if (nLength && wszLine[nLength - 1] == ' ') wszLine[nLength - 1] = 0;
                break;
            }
        } while (nLine < 200);
        int nLength = UNICODE_StrLen((const Unicode*)wszLine);
        for (int j = 0; j < nLength; ++j)
        {
            if (wszLine[j] != ' ')
            {
                D2Win_10051(pText, (const Unicode*)wszLine, 0, 0, 0);
                break;
            }
        }
        nStart = i;
    }
    FOG_Free(pBuffer, gszMainMenusFile, 0xCB4, 0);
    D2Win_10053(pText, 0);
    MAINMENUS_CreateControl(0x4F);
    MAINMENUS_CreateControl(0x50);
    pText = MAINMENUS_CreateControl(0x51);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x143C), 0, 0, 0);
    MAINMENUS_CreateControl(0x52);
    MAINMENUS_CreateControl(0x53);
    return 1;
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

// 0x00433BF0
int __stdcall MAINMENUS_SelectCharacterClass(D2MenuCallbackArgStrc* pArg)
{
    int nImageState = D2Win_10106(pArg->pControl);
    if (FOG_IsExpansion())
    {
        for (int i = 0; i < 7; ++i)
            if (!D2Win_10104(gapClassImages[i])) return 0;
    }
    else
    {
        for (int i = 0; i < 5; ++i)
            if (!D2Win_10104(gapClassImages[i])) return 0;
    }
    int nPreviousClass = gnTextSentinel;
    int nClass = -1;
    gnTextSentinel = -1;
    if (nPreviousClass != -1)
    {
        D2SOUNDFAST_FadeOutWaves();
        switch (nPreviousClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon deselect.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian deselect.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin deselect.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer deselect.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress deselect.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid deselect.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin deselect.wav"); break;
        }
    }
    if (pArg->pControl == gapClassImages[0])
    {
        nClass = 4;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 4, 0xFA7, 0x140A);
    }
    else if (pArg->pControl == gapClassImages[1])
    {
        nClass = 2;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 2, 0xFA9, 0x1409);
    }
    else if (pArg->pControl == gapClassImages[2])
    {
        nClass = 0;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 0, 0xFAB, 0x1408);
    }
    else if (pArg->pControl == gapClassImages[3])
    {
        nClass = 1;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 1, 0xFAA, 0x140B);
    }
    else if (pArg->pControl == gapClassImages[4])
    {
        nClass = 3;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 3, 0xFA8, 0x140C);
    }
    else if (pArg->pControl == gapClassImages[5])
    {
        nClass = 5;
        MAINMENUS_OnSelectDruid(pArg);
    }
    else if (pArg->pControl == gapClassImages[6])
    {
        nClass = 6;
        MAINMENUS_OnSelectAssassin(pArg);
    }
    if (nClass != nPreviousClass && nImageState == 1)
    {
        switch (nClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon select.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian select.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin select.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer select.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress select.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin select.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid select.wav"); break;
        }
        gnTextSentinel = nClass;
    }
    else if (nImageState != 2 && nImageState != 3 && nImageState != 4)
        gnTextSentinel = nClass;
    MAINMENUS_SetModeFlags((char)gnTextSentinel);
    if (gnTextSentinel == -1 && nImageState != 1)
    {
        CONTROL_SetVisible(gpControl_00779598, 0);
        CONTROL_SetVisible(gpControl_007795CC, 0);
        CONTROL_SetVisible(gpControl_007795B0, 0);
        CONTROL_SetVisible(gpControl_007795C4, 0);
        CONTROL_SetVisible(gpNameEdit, 0);
        CONTROL_SetVisible(gpOkButton, 0);
        if (gnLaunchMode == 1)
        {
            CONTROL_SetVisible(gpControl_007795B8, 0);
            CONTROL_SetVisible(gpControl_00779348, 0);
        }
        if (FOG_IsExpansion())
        {
            CONTROL_SetVisible(gpControl_00779568, 0);
            CONTROL_SetVisible(gpControl_007795C8, 0);
            CONTROL_SetVisible(gpControl_007795B4, 0);
        }
        CONTROL_SetFocusedEditBox(0);
        if (gnLaunchMode == 1) CONTROL_SetVisible(gpControl_0077933C, 1);
    }
    else
    {
        CONTROL_SetVisible(gpControl_00779598, 1);
        CONTROL_SetVisible(gpControl_007795CC, 1);
        if (gfHasCharEntries)
        {
            CONTROL_SetVisible(gpControl_007795B0, 1);
            CONTROL_SetVisible(gpControl_007795C4, 1);
        }
        if (gnLaunchMode == 1)
        {
            CONTROL_SetVisible(gpControl_007795B8, 1);
            CONTROL_SetVisible(gpControl_00779348, 1);
        }
        CONTROL_SetVisible(gpNameEdit, 1);
        CONTROL_SetFocusedEditBox(gpNameEdit);
        CONTROL_SetVisible(gpOkButton, 1);
        if (gnLaunchMode == 1) CONTROL_SetVisible(gpControl_0077933C, 0);
    }
    if (FOG_IsExpansion())
    {
        if (gnTextSentinel == 6 || gnTextSentinel == 5)
        {
            CONTROL_SetVisible(gpControl_00779568, 1);
            CONTROL_SetVisible(gpControl_007795C8, 0);
            CONTROL_SetVisible(gpControl_007795B4, 1);
            gpLaunchRecord->wFlags1EF |= 0x20;
        }
        else if (gnTextSentinel != -1)
        {
            CONTROL_SetVisible(gpControl_00779568, 1);
            CONTROL_SetVisible(gpControl_007795C8, 1);
            CONTROL_SetVisible(gpControl_007795B4, 0);
            BUTTON_SetIsPressed(gpControl_007795C8, 1);
            gpLaunchRecord->wFlags1EF |= 0x20;
        }
    }
    if (gnLaunchMode == 1)
    {
        BUTTON_SetIsPressed(gpControl_00779348, 1);
        gpLaunchRecord->wFlags1EF |= 0x40;
    }
    return 1;
}

// 0x00434060
void __cdecl MAINMENUS_BuildRealmList()
{
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(MAINMENUS_StopLoop);
    if (gpFuncTable)
        gpMenuList = gpFuncTable->pfnSendRealmList(0);
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
    if (gnListPos <= sub_004FB950_GetFirstVisible(gpCreditsList) + 10)
        MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00434220
int __cdecl MAINMENUS_PromptPlayDisc()
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
    ARCHIVE_UnloadExpansionArchives();
    ARCHIVE_LoadExpansionArchives(MAINMENUS_PromptPlayDisc, MAINMENUS_PromptExpansionDisc, 0, gpConfig_007795D4);
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00434600
int __stdcall MAINMENUS_CreateGatewayScreen(int nUnused)
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x47);
    D2Win_10044(MAINMENUS_CreateControl(0x48), D2LANG_GetStringFromTblIndex(0x2B2F));
    D2Win_10044(MAINMENUS_CreateControl(0x49), D2LANG_GetStringFromTblIndex(0x2B30));
    gpGatewayList = MAINMENUS_CreateControl(0x4A);
    MAINMENUS_CreateControl(0x4B);
    MAINMENUS_CreateControl(0x4C);
    BNGatewayAccess* pGateways = (BNGatewayAccess*)gpFuncTable->pfnGetBnGatewayAccess();
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


// 0x00434700
int __stdcall MAINMENUS_OnRealmSelected(SMSGHANDLER_PARAMS* pMsg)
{
    D2FuncRecordStrc* pRecord = gpFuncTable->pfnGetBnGatewayAccess();
    int nSelection = sub_004FB990_GetSelection(gpGatewayList);
    if (nSelection != -1)
    {
        nSelection += 1;
        SetCurGateway(pRecord, nSelection);
        SRegSaveString("Diablo II", "Preferred Realm", 0, Realm(pRecord, nSelection));
    }
    MAINMENUS_Reset();
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00434760
int __stdcall MAINMENUS_ResetAndLeave(int nArg)
{
    MAINMENUS_Reset();
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
    MAINMENUS_ShowMainMenu();
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
    UNICODE_ToUtf8(szText, pText, 0x100);
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
    sub_004FA590_RunLoop(MAINMENUS_StopLoop);
    gbConnectResult = 0;
    CLIENT_Initialize(0, szText);
    sub_004FA590_RunLoop(MAINMENUS_PollConnection);
    if (!gbConnectResult)
    {
        CLIENT_Release();
        MAINMENUS_DestroyControls();
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x145B);
        MAINMENUS_ShowMessage(pMessage, CHARSEL_CreateTcpIpScreen, 1);
        return 1;
    }
    MAINMENUS_DestroyControls();
    MAINMENUS_ShowConnectingPopup();
    sub_004FA590_RunLoop(MAINMENUS_PollSystemPacket);
    CLIENT_Release();
    MAINMENUS_DestroyControls();
    if (!gfMenusDone)
    {
        gnLaunchMode = 2;
        gpLaunchRecord->dwGameType = 9;
        gpLaunchRecord->wJoinID = 1;
        D2SOUNDFAST_FadeOutWaves();
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
        if (!gpFuncTable->pfnIsSocketConnected())
        {
            CHARSEL_CreateBaseScreen();
            if (!sub_0043BF60_ConnectToBattleNet())
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
                sub_005269D0_FormatText(256, wszText, D2LANG_GetStringFromTblIndex(0x2B89), wszName);
                MAINMENUS_DestroyControls();
                void* pSaved = gatControlTemplates[0xE0].unk0x28;
                gatControlTemplates[0xE0].unk0x28 = gaGlobal_007089C4;
                MAINMENUS_ShowMessage(wszText, MAINMENUS_ReturnToCharSelect, 1);
                gatControlTemplates[0xE0].unk0x28 = pSaved;
                return 0;
            }

            if (gfMenusDone)
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
    if (D2Win_10003())
        MAINMENUS_PlayIntroVideo();
    D2Win_10004(1);
    MAINMENUS_CreateVideoScreen();
    return 1;
}

// 0x00434DC0
int __stdcall sub_00434DC0_Leave(int nArg)
{
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00434DD0
int __stdcall MAINMENUS_DisconnectAndLeave(int nArg)
{
    CHARSEL_DisconnectBattleNet();
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00434DF0
int __stdcall sub_00434DF0_Leave(int nArg)
{
    MAINMENUS_ShowMainMenu();
    return 1;
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
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00435030
int __stdcall MAINMENUS_ChangePasswordOk(int nArg)
{
    if (!nArg)
    {
        MAINMENUS_CreateInfoScreen();
        return 1;
    }
    MAINMENUS_StoreAccountTexts(gpAccountEdit, gpCreatePasswordEdit);
    const Unicode* pAccount = sub_004FDD90_GetEditText(gpAccountEdit);
    const Unicode* pOldPassword = sub_004FDD90_GetEditText(gpPasswordEdit);
    const Unicode* pPassword = sub_004FDD90_GetEditText(gpCreatePasswordEdit);
    const Unicode* pConfirm = sub_004FDD90_GetEditText(gpCreatePasswordConfirmEdit);
    UNICODE_ToAscii(gszOldPassword, pOldPassword, 0x100);
    int nLength = UNICODE_StrLen(pAccount);
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
    nLength = UNICODE_StrLen(pPassword);
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

// 0x00435180
void __fastcall MAINMENUS_ShowExpansionMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pFrame = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pFrame, 1);
    D2WinControlStrc* pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
    D2WinControlStrc* pTextBox = MAINMENUS_CreateFromTemplate(0xE0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    MAINMENUS_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone = pfnDone;
}

// 0x00435200
int __stdcall MAINMENUS_CancelDownload(int nArg)
{
    gpFuncTable->pfn0x70();
    gbStopMainLoop = 1;
    MAINMENUS_ShowMainMenu();
    return 1;
}

// 0x00435230
void __cdecl MAINMENUS_PlayIntroVideos()
{
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
    int bConnected = gpFuncTable->pfnIsSocketConnected();
    if (bConnected && !CHARSEL_IsBattleNetConnected())
        goto create;
    if (bConnected)
        CHARSEL_DisconnectBattleNet();
    MAINMENUS_ShowMainMenu();
    if (!sub_0043BF60_ConnectToBattleNet())
        return;
create:
    gpAccountEdit = 0;
    gpPasswordEdit = 0;
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
    gnTextMode = -1;
    gnTextSentinel = -1;
    gpLaunchRecord->wFlags1EF = 0;
    MAINMENUS_ReadPaletteFiles(gszFeCharPalDat, "palette\\fechar\\pal.pl2");

    MAINMENUS_CreateControl(0xB1);
    gpTextControl1 = MAINMENUS_CreateControl(0xC5);
    gpTextControl2 = MAINMENUS_CreateControl(0xC6);
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

    gapClassImages[0] = MAINMENUS_CreateControl(0xB6);
    if (FOG_IsExpansion())
    {
        gapClassImages[3] = MAINMENUS_CreateControl(0xBA);
        gapClassImages[4] = MAINMENUS_CreateControl(0xBB);
        gapClassImages[1] = MAINMENUS_CreateControl(0xB5);
        gapClassImages[6] = MAINMENUS_CreateControl(0xD1);
        gapClassImages[2] = MAINMENUS_CreateControl(0xBC);
        gapClassImages[5] = MAINMENUS_CreateControl(0xD2);
        MAINMENUS_CreateControl(0xB2);
    }
    else
    {
        gapClassImages[1] = MAINMENUS_CreateControl(0xB5);
        gapClassImages[3] = MAINMENUS_CreateControl(0xB7);
        gapClassImages[2] = MAINMENUS_CreateControl(0xB4);
        gapClassImages[4] = MAINMENUS_CreateControl(0xB8);
        MAINMENUS_CreateControl(0xB3);
    }

    MAINMENUS_UpdateNameOk();
}

// 0x004359D0
int __fastcall MAINMENUS_RunFrontEnd(D2ConfigStrc* pRecord)
{
    gpLaunchRecord = pRecord;
    D2Win_10015();
    D2_ASSERT(STRTABLE_LoadStringTables(sub_004FAC80(FOG_IsExpansion()), 0), 0x125A);
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
    gpFuncTable = pRecord->pComInterface;
    const char nStartMode = gpLaunchRecord->nStartMode;
    if (nStartMode == 2)
    {
        if (gpFuncTable->pfnIsSocketConnected())
        {
            gnLaunchMode = 1;
            sub_004F90A0(1);
            CHARSEL_InitCharSelectScreen();
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
        if (gpFuncTable->pfnIsSocketConnected())
        {
            gnLaunchMode = 3;
            sub_004F90A0(1);
            CHARSEL_InitCharSelectScreen();
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
                MAINMENUS_ShowMainMenu();
            }
        }
    }
    D2Win_SetQuitCallback(sub_004309B0_ClearState);
    D2Win_RunMessageLoop(MAINMENUS_IdleLoopCallback);
    D2SOUNDFAST_FadeOutWaves();
    while (D2SOUNDFAST_IsAnyWavePlaying())
        Sleep(0);
    D2SOUNDFAST_FreeWaveSlots();
    MAINMENUS_Reset();
    MAINMENUS_FreeFrontEndCells();
    STRTABLE_UnloadStringTables();
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
    MAINMENUS_CreateCharCreateScreen();
    return 1;
}

// 0x00435E10
void __cdecl MAINMENUS_CreateRealmCharacter()
{
    switch (MAINMENUS_ConnectToRealm(GAME_GetPreferredRealm(), 0))
    {
    case 1:
    case 2:
        MAINMENUS_CreateCharCreateScreen();
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
            if (gfMenusDone)
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
                    MAINMENUS_ShowText(wszText, MAINMENUS_CreateCharCreateScreen);
                    return;
                }

                D2MCPClientCloseMCP();
                Unicode wszText[256];
                Unicode wszName[256];
                sub_00526F20_ToUnicode(wszName, gpLaunchRecord->szCharName, 256);
                sub_005269D0_FormatText(256, wszText, D2LANG_GetStringFromTblIndex(0x2B33), wszName);
                MAINMENUS_ShowText(wszText, MAINMENUS_CreateCharCreateScreen);
                return;
            }

            CHARSEL_SetFlagBit2(1);
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
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x145D), MAINMENUS_CreateCharCreateScreen);
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
        MAINMENUS_ShowMainMenu();
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
            D2SOUNDFAST_FadeOutWaves();
            MAINMENUS_Reset();
            CHARSEL_InitCharSelectScreen();
            return 1;
        }
        if (MAINMENUS_HasSaveFiles())
        {
            MAINMENUS_ReturnToCharSelect();
            return 1;
        }
        MAINMENUS_CreateCharCreateScreen();
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
        if (MAINMENUS_HasSaveFiles())
        {
            D2SOUNDFAST_FadeOutWaves();
            MAINMENUS_Reset();
            CHARSEL_InitCharSelectScreen();
            return 1;
        }
        MAINMENUS_CreateCharCreateScreen();
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
        CHARSEL_SetFlagBit2(0);
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
        CHARSEL_SetFlagBit2(0);
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
    MAINMENUS_CreateCharCreateScreen();
    return 1;
}

// 0x004365B0
void __cdecl MAINMENUS_CreateCharacter()
{
    char szName[0x100];
    if (MAINMENUS_SaveExists() == 1 && gnLaunchMode != 1)
    {
        MAINMENUS_ShowTextBox(D2LANG_GetStringFromTblIndex(0x142D), MAINMENUS_DestroyControls);
        return;
    }
    if (gpLaunchRecord->nMode == 6 || gpLaunchRecord->nMode == 5)
        gpLaunchRecord->wFlags1EF |= 0x20;
    const Unicode* pText = sub_004FDD90_GetEditText(gpNameEdit);
    UNICODE_ToUtf8(szName, pText, 0x100);
    sprintf((gpLaunchRecord->szPassword + 0x18), gszStringFormat, szName);
    gpLaunchRecord->szPassword[0x30] = 0;
    if (gpLaunchRecord->wFlags1EF & 0x20)
        gbFlag_00779984 = 1;
    if (gpLaunchRecord->wFlags1EF & 4)
    {
        sub_00430520_CreateControls();
        return;
    }
    if (gnLaunchMode == 0)
    {
        MAINMENUS_Reset();
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), gpLaunchRecord->wFlags1EF);
        CHATDLG_WriteSaveHeader((gpLaunchRecord->szPassword + 0x18));
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
        CHARSEL_SetFlagBit2(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), gpLaunchRecord->wFlags1EF);
        CHATDLG_WriteSaveHeader((gpLaunchRecord->szPassword + 0x18));
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
        CHARSEL_SetFlagBit2(0);
        AUTOMAP_InitCharSaveHeader((gpLaunchRecord->szPassword + 0x18), gpLaunchRecord->nMode, (gpLaunchRecord->szPassword + 0x48), gpLaunchRecord->wFlags1EF);
        CHATDLG_WriteSaveHeader((gpLaunchRecord->szPassword + 0x18));
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
    int nLength = UNICODE_StrLen(pAccount);
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
    nLength = UNICODE_StrLen(pPassword);
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
    if (sub_004F9710_TestFlags(gpOkButton))
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
            MAINMENUS_ShowTextBox(D2LANG_GetStringFromTblIndex(0x141D), MAINMENUS_ReturnToCharSelect);
            return 1;
        }
        CONTROL_SetEnabled(gpOkButton, 0);
        MAINMENUS_CreateCharacter();
    }
    return 1;
}

int __cdecl sub_0043B830_IsCancelled(); // 0x0043B830

int gnStatusDots; // 0x007799B4

// 0x0043B4C0
int __stdcall MAINMENUS_OnRealmListClick(SMSGHANDLER_PARAMS* pMsg)
{
    const Unicode* pText = sub_004FBB30_GetText(gpNameControl);
    UNICODE_ToUtf8(gszEnteredName, pText, 0x100);
    CHARSEL_UseName(gszEnteredName);
    CHARSEL_RefreshCharEntry();
    if (MAINMENUS_IsDoubleClick(pMsg))
        return CHARSEL_OnRealmChosen(pMsg);
    return 1;
}


unsigned int __stdcall FOG_ComputeChecksum(const unsigned char* pData, unsigned int nSize); // 0x00411130
extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230
extern D2CharSaveHeaderStrc gtCharSaveHeader; // 0x0077AC10

// 0x0043C6B0
int __fastcall CHATDLG_WriteSaveHeader(const char* szName)
{
    char szDir[0x400];
    char szPath[0x1F4];
    unsigned long dwWritten;

    FOG_GetSavePath(szDir, 0x400);
    sprintf(szPath, gszSaveFormat_006D4230, szDir, szName);

    void* hFile = FOG_CreateFileA(szPath, 0x40000000, 0, 0, 2, 0x8000000, 0);
    if (!hFile)
        return 0;

    gtCharSaveHeader.dwChecksum = FOG_ComputeChecksum((const unsigned char*)&gtCharSaveHeader, 0x14F);
    FOG_WriteFile(hFile, &gtCharSaveHeader, 0x14F, &dwWritten, 0);
    FOG_CloseFile(hFile);
    return 1;
}

// 0x0043C750
void __fastcall MAINMENUS_DeleteCharFiles(const char* szCharName, const char* szSubdirectory)
{
    char szDir[0x104];
    D2FindDataStrc tFind;
    char szTemp[0x104];
    char szPath[500];
    char szMask[500];

    D2_ASSERT(szCharName[0], 0xAF);

    FOG_GetSavePath(szDir, 0x104);
    if (szSubdirectory && szSubdirectory[0])
    {
        SStrPrintf(szTemp, 0x104, "%s%s\\", szDir, szSubdirectory);
        FOG_CreatePathHierarchy(szTemp);
        SStrCopy(szDir, szTemp, 0x104);
    }

    sprintf(szMask, "%s%s.*", szDir, szCharName);
    void* hFind = FindFirstFileA(szMask, &tFind);
    while (hFind != (void*)-1)
    {
        sprintf(szPath, "%s%s", szDir, tFind.cFileName);
        if (GetFileAttributesA(szPath) & 0x10)
        {
            if (!FindNextFileA(hFind, &tFind))
                return;
        }
        else
        {
            if (!DeleteFileA(szPath))
                return;
            hFind = FindFirstFileA(szMask, &tFind);
        }
    }
}

extern "C" void __cdecl MAINMENUS_OnConnectCancel(); // 0x00436CD0
extern "C" void __cdecl sub_004371B0_OnLoginScreen(); // 0x004371B0
extern "C" void __cdecl MAINMENUS_OnEmailScreen(); // 0x004371C0
extern "C" void __cdecl sub_004371D0_OnShowLogin(); // 0x004371D0
extern "C" void __cdecl MAINMENUS_OnInfoScreen(); // 0x004374E0
extern "C" void __cdecl sub_00437710_OnInfoScreen(); // 0x00437710
extern "C" void __cdecl MAINMENUS_OnPasswordScreen(); // 0x00437720
extern "C" void __cdecl MAINMENUS_ChangePassword(); // 0x00437730
extern "C" void __cdecl CHARSEL_SubmitPasswordReset(); // 0x004378D0
extern "C" void __cdecl CHARSEL_OnNormalDifficulty(); // 0x00439B80
extern "C" void __cdecl CHARSEL_OnNightmareDifficulty(); // 0x00439BA0
extern "C" void __cdecl CHARSEL_OnHellDifficulty(); // 0x00439BC0
extern "C" void __cdecl CHARSEL_CreateExpansionControls(); // 0x00439BE0
extern "C" void __cdecl CHARSEL_DestroyIfExpansion(); // 0x00439CA0
extern "C" void __cdecl CHARSEL_OnClosePopup(); // 0x00439D40
extern "C" void __cdecl sub_00439D50_CreateControls(); // 0x00439D50
extern "C" void __cdecl CHARSEL_ScrollUp(); // 0x00439D60
extern "C" void __cdecl CHARSEL_ScrollDown(); // 0x00439DA0
extern "C" void __cdecl CHARSEL_OnScroll(); // 0x00439DF0
extern "C" void __cdecl CHARSEL_OnListKeyDown(); // 0x0043A0D0
extern "C" void __cdecl CHARSEL_CopyName(); // 0x0043A9A0
extern "C" void __cdecl CHARSEL_OnListClick(); // 0x0043A9D0
extern "C" void __cdecl CHARSEL_PollConnect(); // 0x0043AC00
extern "C" void __cdecl CHARSEL_OnName(); // 0x0043B490
extern "C" void __cdecl CHARSEL_OnCharSelect(); // 0x0043B520
extern "C" void __cdecl CHARSEL_JoinSelected(); // 0x0043B6B0
extern "C" void __cdecl CHARSEL_OnCharSelectOk(); // 0x00439840

#pragma pack(push, 1)
struct d2data_00708C30_t
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
struct d2data_00708C80_t
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
    unsigned char b14[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_0070CB84_t
{
    unsigned char b0[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089AC_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089B4_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089BC_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089C4_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089CC_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089D4_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089DC_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089E4_t
{
    unsigned char b0[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007089EC_t
{
    unsigned char b0[20];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708A00_t
{
    const void* p0;
    unsigned char b1[12];
    const void* p2;
    unsigned char b3[12];
    const void* p4;
    unsigned char b5[12];
    const void* p6;
    unsigned char b7[12];
    const void* p8;
    unsigned char b9[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708A50_t
{
    const void* p0;
    unsigned char b1[12];
    const void* p2;
    unsigned char b3[12];
    const void* p4;
    unsigned char b5[12];
    const void* p6;
    unsigned char b7[12];
    const void* p8;
    unsigned char b9[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708AA0_t
{
    const void* p0;
    unsigned char b1[12];
    const void* p2;
    unsigned char b3[12];
    const void* p4;
    unsigned char b5[12];
    const void* p6;
    unsigned char b7[12];
    const void* p8;
    unsigned char b9[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708AF0_t
{
    const void* p0;
    unsigned char b1[12];
    const void* p2;
    unsigned char b3[12];
    const void* p4;
    const void* p5;
    unsigned char b6[8];
    const void* p7;
    const void* p8;
    unsigned char b9[8];
    const void* p10;
    const void* p11;
    unsigned char b12[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708B40_t
{
    const void* p0;
    unsigned char b1[12];
    const void* p2;
    unsigned char b3[12];
    const void* p4;
    const void* p5;
    unsigned char b6[8];
    const void* p7;
    unsigned char b8[12];
    const void* p9;
    unsigned char b10[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708B90_t
{
    const void* p0;
    unsigned char b1[12];
    const void* p2;
    unsigned char b3[12];
    const void* p4;
    const void* p5;
    unsigned char b6[8];
    const void* p7;
    const void* p8;
    unsigned char b9[8];
    const void* p10;
    const void* p11;
    unsigned char b12[8];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708BE0_t
{
    const void* p0;
    unsigned char b1[12];
    const void* p2;
    unsigned char b3[12];
    const void* p4;
    const void* p5;
    unsigned char b6[8];
    const void* p7;
    unsigned char b8[12];
    const void* p9;
    unsigned char b10[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708CDC_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708CE8_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708CF4_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708D00_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708970_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00708C30_t gData_00708C30; // 0x00708C30
extern "C" struct d2data_00708C80_t gData_00708C80; // 0x00708C80
extern "C" D2LaunchControlTemplateStrc gData_00708D10[333]; // 0x00708D10
extern "C" const char gData_006D48E8[16]; // 0x006D48E8
extern "C" struct d2data_0070CB84_t gData_0070CB84; // 0x0070CB84
extern "C" struct d2data_007089AC_t gData_007089AC; // 0x007089AC
extern "C" struct d2data_007089B4_t gData_007089B4; // 0x007089B4
extern "C" struct d2data_007089BC_t gData_007089BC; // 0x007089BC
extern "C" struct d2data_007089C4_t gData_007089C4; // 0x007089C4
extern "C" struct d2data_007089CC_t gData_007089CC; // 0x007089CC
extern "C" struct d2data_007089D4_t gData_007089D4; // 0x007089D4
extern "C" struct d2data_007089DC_t gData_007089DC; // 0x007089DC
extern "C" struct d2data_007089E4_t gData_007089E4; // 0x007089E4
extern "C" struct d2data_007089EC_t gData_007089EC; // 0x007089EC
extern "C" struct d2data_00708A00_t gData_00708A00; // 0x00708A00
extern "C" struct d2data_00708A50_t gData_00708A50; // 0x00708A50
extern "C" struct d2data_00708AA0_t gData_00708AA0; // 0x00708AA0
extern "C" struct d2data_00708AF0_t gData_00708AF0; // 0x00708AF0
extern "C" struct d2data_00708B40_t gData_00708B40; // 0x00708B40
extern "C" struct d2data_00708B90_t gData_00708B90; // 0x00708B90
extern "C" struct d2data_00708BE0_t gData_00708BE0; // 0x00708BE0
extern "C" struct d2data_00708CDC_t gData_00708CDC; // 0x00708CDC
extern "C" struct d2data_00708CE8_t gData_00708CE8; // 0x00708CE8
extern "C" struct d2data_00708CF4_t gData_00708CF4; // 0x00708CF4
extern "C" struct d2data_00708D00_t gData_00708D00; // 0x00708D00
extern "C" const unsigned char gData_006D4D88[20]; // 0x006D4D88
extern "C" struct d2data_00708970_t gData_00708970; // 0x00708970

extern "C" struct d2data_00708C30_t gData_00708C30 = {
    (const void*)&gpD2LogoBlackLeftCelFile,
    (const void*)&gpD2LogoFireLeftCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackLeftCelFile,
    (const void*)&gpD2LogoFireLeftCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackLeftCelFile,
    (const void*)&gpD2LogoFireLeftCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackLeftCelFile,
    (const void*)&gpD2LogoFireLeftCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackLeftCelFile,
    (const void*)&gpD2LogoFireLeftCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708C30

extern "C" struct d2data_00708C80_t gData_00708C80 = {
    (const void*)&gpD2LogoBlackRightCelFile,
    (const void*)&gpD2LogoFireRightCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackRightCelFile,
    (const void*)&gpD2LogoFireRightCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackRightCelFile,
    (const void*)&gpD2LogoFireRightCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackRightCelFile,
    (const void*)&gpD2LogoFireRightCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpD2LogoBlackRightCelFile,
    (const void*)&gpD2LogoFireRightCelFile,
    {
        0x03, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x33, 0x00, 0x00, 0x00, 0xC8, 0x01, 0x00, 0x00,
        0x0E, 0x01
    }
}; // 0x00708C80

extern "C" D2LaunchControlTemplateStrc gData_00708D10[333] = {
    { 2, 0, 479, 640, 480, 0, 0, (void*)&gpBlizNoCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayIntroAndLeave },
    { 8, 8, 0, 0, 0, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayIntroAndLeave },
    { 2, 0, 599, 800, 600, 0, 0, (void*)&gpTrademarkCelFile, (D2LaunchCallback)(unsigned int)&sub_00434DC0_Leave, 0, (void*)(unsigned int)&sub_00434DC0_Leave },
    { 8, 9, 0, 0, 0, 0, 0, 0, (D2LaunchCallback)(unsigned int)&sub_00434DC0_Leave },
    { 4, 100, 580, 600, 80, 0, 0, 0, 0, 0, (void*)&gData_007089DC, 2 },
    { 2, 240, 120, 320, 151, 0, 0, (void*)&gpDiablo2LogoCelFile },
    { 3, 400, 120, 181, 170, 0, 0, 0, 0, (void*)&gData_00708C30 },
    { 3, 400, 120, 188, 177, 0, 0, 0, 0, (void*)&gData_00708C80 },
    { 2, 0, 599, 800, 600, 0, 0, (void*)&gpTitleScreenCelFile },
    { 6, 264, 224, 272, 35, 0, 5106, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnSinglePlayer },
    { 6, 264, 266, 272, 35, 0, 5107, (void*)&gpWideButtonBlank02CelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnBattleNet },
    { 6, 264, 291, 272, 25, 0, 0, (void*)&gpNarrowButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CreateGatewayScreen },
    { 6, 264, 333, 272, 35, 0, 5108, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnCreate },
    { 6, 264, 528, 135, 25, 0, 5110, (void*)&gpShortButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CreateCreditsScreen },
    { 6, 402, 528, 135, 25, 0, 5111, (void*)&gpShortButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ShowLevelScreen },
    { 6, 264, 568, 272, 35, 27, 5109, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_Leave },
    { 6, 264, 324, 272, 35, 0, 5106, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnSinglePlayer },
    { 6, 264, 366, 272, 35, 0, 5107, (void*)&gpWideButtonBlank02CelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnBattleNet },
    { 6, 264, 391, 272, 25, 0, 0, (void*)&gpNarrowButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CreateGatewayScreen },
    { 6, 264, 433, 272, 35, 0, 5108, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnCreate },
    { 4, 150, 300, 500, 100, 0, 0, 0, 0, 0, (void*)&gData_007089AC, 34 },
    { 2, 319, 347, 169, 26, 0, 0, (void*)&gpTextBox2CelFile },
    { 2, 319, 401, 169, 26, 0, 0, (void*)&gpTextBox2CelFile },
    { 2, 319, 455, 169, 26, 0, 0, (void*)&gpTextBox2CelFile },
    { 2, 319, 455, 169, 26, 0, 0, (void*)&gpTextBox2CelFile },
    { 2, 319, 509, 169, 26, 0, 0, (void*)&gpTextBox2CelFile },
    { 4, 321, 340, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 4, 321, 394, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 4, 321, 448, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 4, 321, 448, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 4, 321, 502, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 4, 0, 260, 800, 50, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 200, 350, 400, 100, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 4, 0, 310, 800, 50, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 1, 322, 342, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_LoginOk, (void*)&gData_007089DC },
    { 1, 322, 396, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_LoginOk, (void*)&gData_007089DC, 33 },
    { 6, 264, 572, 272, 35, 0, 5221, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CheckFreeSpace },
    { 6, 264, 528, 272, 35, 0, 11108, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_StoreAccount },
    { 6, 264, 484, 272, 35, 13, 5288, (void*)&gp3WideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_LoginOk, 0, 0, 32 },
    { 6, 33, 572, 128, 35, 27, 5101, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_Callback },
    { 4, 590, 545, 205, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 2, 0, 599, 800, 600, 0, 0, (void*)&gpCreditsBckgCelFile },
    { 6, 33, 578, 128, 35, 27, 5101, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_Callback },
    { 4, 560, 615, 250, 610, 0, 0, 0, 0, 0, (void*)&gData_007089D4, 144 },
    { 4, 570, 615, 250, 610, 0, 0, 0, 0, 0, (void*)&gData_007089D4, 128 },
    { 4, 440, 615, 250, 610, 0, 0, 0, 0, 0, (void*)&gData_007089D4, 130 },
    { 8, 50, 0, 0, 0, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_CheckCreditsEnd },
    { 4, 400, 615, 250, 610, 0, 0, 0, 0, 0, (void*)&gData_007089D4, 144 },
    { 4, 410, 615, 250, 610, 0, 0, 0, 0, 0, (void*)&gData_007089D4, 128 },
    { 4, 280, 615, 250, 610, 0, 0, 0, 0, 0, (void*)&gData_007089D4, 130 },
    { 2, 237, 555, 326, 341, 0, 0, (void*)&gpCinematicsSelectionCelFile },
    { 4, 262, 283, 272, 35, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 6, 262, 316, 272, 35, 0, 4137, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayClassicIntro },
    { 6, 262, 359, 272, 35, 0, 4138, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActTwoStart },
    { 6, 262, 402, 272, 35, 0, 4139, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActThreeStart },
    { 6, 262, 445, 272, 35, 0, 4140, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActFourStart },
    { 6, 262, 488, 272, 35, 0, 5113, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActFourEnd },
    { 6, 334, 538, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ReloadAndLeave },
    { 6, 281, 337, 96, 32, 27, 5103, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ShowLevelAndStop, 0, 0, 2 },
    { 6, 421, 337, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_00431920_SetFlagD4, 0, 0, 2 },
    { 6, 351, 337, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_00431910_SetFlagD4, 0, 0, 2 },
    { 2, 237, 505, 326, 427, 0, 0, (void*)&gpCinematicsSelectionExpCelFile },
    { 4, 262, 153, 272, 35, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 6, 262, 181, 272, 35, 0, 21797, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayClassicIntro },
    { 6, 262, 224, 272, 35, 0, 21798, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActTwoStart },
    { 6, 262, 268, 272, 35, 0, 21799, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActThreeStart },
    { 6, 262, 310, 272, 35, 0, 21800, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActFourStart },
    { 6, 262, 353, 272, 35, 0, 21801, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayActFourEnd },
    { 6, 262, 396, 272, 35, 0, 21802, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayExpansionIntro },
    { 6, 262, 439, 272, 35, 0, 21803, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_PlayExpansionOutro },
    { 6, 334, 488, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ReloadAndLeave },
    { 2, 237, 555, 340, 340, 0, 0, (void*)&gpGWListBoxCelFile },
    { 4, 237, 270, 340, 35, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 4, 257, 345, 320, 84, 0, 0, 0, 0, 0, (void*)&gData_007089CC },
    { 4, 257, 500, 292, 160, 0, 0, (void*)&gpJoinGameScrollBarsCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnRealmDoubleClick, (void*)&gData_00708CE8, (void*)&gData_007089DC, 13 },
    { 6, 281, 538, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnRealmSelected },
    { 6, 436, 538, 96, 32, 27, 5103, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ResetAndLeave },
    { 2, 103, 526, 593, 451, 0, 0, (void*)&gpTermsOfUseBckgCelFile },
    { 4, 120, 467, 560, 318, 0, 0, (void*)&gpJoinGameScrollBarsCelFile, 0, (void*)&gData_00708CDC, (void*)&gData_007089E4, 4 },
    { 6, 525, 513, 128, 35, 0, 5181, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnBack },
    { 6, 133, 513, 128, 35, 13, 5182, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnShowLogin },
    { 4, 103, 173, 570, 69, 0, 0, 0, 0, 0, (void*)&gData_007089AC, 2 },
    { 6, 900, 900, 128, 35, 38, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_ScrollUp, 0, 0, 6 },
    { 6, 900, 900, 128, 35, 40, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_ScrollDown, 0, 0, 6 },
    { 1, 322, 342, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_CreateAccountOk, (void*)&gData_007089DC },
    { 1, 322, 396, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_CreateAccountOk, (void*)&gData_007089DC, 33 },
    { 1, 322, 450, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_CreateAccountOk, (void*)&gData_007089DC, 33 },
    { 6, 627, 572, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CreateAccountOk },
    { 6, 33, 572, 128, 35, 27, 5101, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnShowLogin },
    { 1, 322, 342, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePasswordOk, (void*)&gData_007089DC },
    { 1, 322, 396, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePasswordOk, (void*)&gData_007089DC, 33 },
    { 1, 322, 450, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePasswordOk, (void*)&gData_007089DC, 33 },
    { 1, 322, 504, 162, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePasswordOk, (void*)&gData_007089DC, 33 },
    { 6, 627, 572, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ChangePasswordOk },
    { 6, 33, 572, 128, 35, 27, 5101, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OpenInfoScreen },
    { 4, 103, 173, 570, 69, 0, 0, 0, 0, 0, (void*)&gData_007089AC, 2 },
    { 4, 110, 480, 570, 318, 0, 0, 0, 0, 0, (void*)&gData_007089DC, 2 },
    { 4, 110, 610, 570, 318, 0, 0, 0, 0, 0, (void*)&gData_007089DC, 2 },
    { 4, 110, 700, 570, 318, 0, 0, 0, 0, 0, (void*)&gData_007089DC, 2 },
    { 6, 525, 513, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ConnectOk },
    { 6, 133, 513, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_BackToLogin },
    { 2, 513, 80, 272, 73, 0, 0, (void*)&gpRealmSelectCelFile },
    { 4, 559, 33, 183, 18, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 6, 513, 105, 272, 25, 0, 11057, (void*)&gpRealmSelectButtonThinCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_CopyName },
    { 4, 528, 96, 246, 47, 0, 0, 0, 0, 0, (void*)&gData_007089AC, 2 },
    { 2, 609, 83, 182, 71, 0, 0, (void*)&gpRealmSelectCelFile },
    { 4, 629, 44, 145, 21, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 6, 609, 113, 182, 30, 0, 11057, (void*)&gpRealmSelectButtonThinCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_CopyName },
    { 4, 626, 100, 151, 44, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 2, 451, 455, 340, 340, 0, 0, (void*)&gpGWListBoxCelFile },
    { 4, 451, 173, 340, 35, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 4, 461, 230, 320, 70, 0, 0, 0, 0, 0, (void*)&gData_007089CC },
    { 4, 471, 400, 292, 160, 0, 0, (void*)&gpJoinGameScrollBarsCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnRealmListClick, (void*)&gData_00708CF4, (void*)&gData_007089DC, 13 },
    { 6, 495, 438, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnRealmChosen },
    { 6, 650, 438, 96, 32, 27, 5103, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnName },
    { 2, 127, 455, 340, 340, 0, 0, (void*)&gpGWListBoxCelFile },
    { 4, 127, 173, 340, 35, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 4, 137, 230, 320, 70, 0, 0, 0, 0, 0, (void*)&gData_007089CC },
    { 4, 147, 400, 292, 160, 0, 0, (void*)&gpJoinGameScrollBarsCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnRealmListClick, (void*)&gData_00708CF4, (void*)&gData_007089DC, 13 },
    { 6, 171, 438, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnRealmChosen },
    { 6, 326, 438, 96, 32, 27, 5103, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnName },
    { 4, 33, 530, 448, 120, 0, 0, 0, 0, 0, (void*)&gData_007089E4 },
    { 8, 50, 0, 0, 0, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_PollConnect },
    { 6, 514, 572, 272, 35, 0, 5273, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_Back },
    { 6, 33, 572, 128, 35, 27, 5101, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_DisconnectAndLeave },
    { 6, 193, 572, 128, 35, 0, 5272, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_00439D50_CreateControls },
    { 6, 353, 572, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnCharSelectOk },
    { 4, 514, 153, 200, 92, 76, 5, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 514, 246, 200, 92, 76, 5, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 514, 339, 200, 92, 76, 5, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 514, 432, 200, 92, 76, 5, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 514, 525, 200, 92, 76, 5, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 37, 178, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 309, 178, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 37, 271, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 309, 271, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 37, 364, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 309, 364, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 37, 457, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 309, 457, 200, 92, 76, 3, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 237, 178, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 509, 178, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 237, 271, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 509, 271, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 237, 364, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 509, 364, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 237, 457, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 509, 457, 72, 93, 0, 0, 0, (D2LaunchCallback)(unsigned int)&CHARSEL_OnListClick, 0, (void*)&gData_007089C4, 32 },
    { 4, 45, 318, 531, 140, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 4, 37, 178, 547, 35, 0, 0, 0, 0, 0, (void*)&gData_007089E4, 2 },
    { 2, 514, 1000, 272, 93, 0, 0, (void*)&gpCharSelectBoxCelFile, 0, 0, (void*)(unsigned int)&CHARSEL_OnListKeyDown },
    { 2, 514, 1000, 272, 93, 0, 0, (void*)&gpCharSelectBoxGreyCelFile, 0, 0, (void*)(unsigned int)&CHARSEL_OnListKeyDown },
    { 4, 514, 385, 272, 93, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 6, 634, 50, 29, 20, 105, 0, (void*)&gpSelectCharArrowsCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_ScrollUp, 0, 0, 8 },
    { 6, 634, 555, 29, 20, 99, 0, (void*)&gpSelectCharArrowsCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_ScrollDown, (void*)0x2, 0, 16 },
    { 4, 70, 103, 450, 50, 0, 0, 0, 0, 0, (void*)&gData_007089AC, 34 },
    { 4, 85, 78, 466, 42, 0, 0, 0, 0, 0, (void*)&gData_007089AC, 34 },
    { 4, 86, 143, 400, 50, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 86, 178, 400, 50, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 2, 512, 150, 84, 86, 0, 0, (void*)&gpCreateNewCharImageCelFile, 0, 0, (void*)(unsigned int)&CHARSEL_OnListKeyDown },
    { 4, 86, 300, 400, 200, 0, 0, 0, 0, 0, (void*)&gData_007089EC, 2 },
    { 2, 0, 599, 800, 600, 0, 0, (void*)&gpCharacterSelectScreenExpCelFile },
    { 6, 627, 572, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnCharSelectOk },
    { 6, 33, 572, 128, 35, 27, 5101, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_DisconnectAndLeave },
    { 6, 33, 528, 168, 60, 0, 10832, (void*)&gpTallButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_Back, 0, 0, 64 },
    { 6, 233, 528, 168, 60, 0, 22732, (void*)&gpTallButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_CreateExpansionControls, 0, 0, 64 },
    { 6, 433, 528, 168, 60, 0, 5272, (void*)&gpTallButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_00439D50_CreateControls, 0, 0, 64 },
    { 4, 564, 457, 34, 371, 0, 0, (void*)&gpJoinGameScrollBarsCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnScroll, (void*)&gData_00708D00, (void*)&gData_007089DC, 5 },
    { 6, 264, 297, 272, 35, 82, 10018, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnNormalDifficulty },
    { 6, 264, 340, 272, 35, 78, 10017, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnNightmareDifficulty },
    { 6, 264, 383, 272, 35, 72, 10016, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnHellDifficulty },
    { 4, 264, 260, 272, 35, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 2, 237, 400, 326, 200, 0, 0, (void*)&gpDifficultyLevelsCelFile },
    { 6, 900, 900, 10, 10, 27, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_CloseBox },
    { 4, 0, 80, 800, 50, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 6, 33, 572, 128, 35, 27, 5101, (void*)&gpMediumSelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_00430C30_OnCancel },
    { 6, 627, 572, 128, 35, 13, 5102, (void*)&gpMediumSelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnCharCreateOk },
    { 2, 0, 599, 800, 600, 0, 0, (void*)&gpCharacterCreateCelFile },
    { 3, 345, 470, 110, 127, 1, 3, (void*)&gpFireCelFile },
    { 3, 345, 454, 110, 127, 1, 3, (void*)&gpFireCelFile },
    { 3, 195, 341, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708AA0, (void*)(unsigned int)&MAINMENUS_OnHoverAmazon },
    { 3, 301, 333, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708AF0, (void*)(unsigned int)&MAINMENUS_OnHoverNecromancer },
    { 3, 400, 330, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708B40, (void*)(unsigned int)&MAINMENUS_OnHoverBarbarian },
    { 3, 521, 344, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708B90, (void*)(unsigned int)&MAINMENUS_OnHoverSorceress },
    { 3, 610, 359, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708BE0, (void*)(unsigned int)&MAINMENUS_OnHoverPaladin },
    { 3, 217, 360, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708AF0, (void*)(unsigned int)&MAINMENUS_OnHoverNecromancer },
    { 3, 626, 353, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708B90, (void*)(unsigned int)&MAINMENUS_OnHoverSorceress },
    { 3, 521, 339, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708BE0, (void*)(unsigned int)&MAINMENUS_OnHoverPaladin },
    { 3, 100, 337, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708AA0, (void*)(unsigned int)&MAINMENUS_OnHoverAmazon },
    { 4, 339, 581, 100, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 6, 319, 560, 15, 16, 0, 0, (void*)&gpClickBoxCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ToggleHardcore, 0, 0, 2 },
    { 4, 339, 561, 200, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 6, 319, 540, 15, 16, 0, 0, (void*)&gpClickBoxCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ToggleLadder, 0, 0, 2 },
    { 4, 339, 581, 200, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 6, 319, 560, 15, 16, 0, 0, (void*)&gpClickBoxCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ToggleLadder, 0, 0, 2 },
    { 4, 339, 601, 200, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 6, 319, 580, 15, 16, 0, 0, (void*)&gpClickBoxCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ToggleLadder, 0, 0, 2 },
    { 4, 0, 180, 800, 100, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 250, 210, 300, 100, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 4, 210, 610, 430, 120, 0, 0, 0, 0, 0, (void*)&gData_007089CC },
    { 2, 319, 519, 169, 26, 0, 0, (void*)&gpTextBoxCelFile },
    { 4, 321, 512, 200, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 4, 339, 561, 100, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 6, 319, 540, 15, 16, 0, 0, (void*)&gpClickBoxCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ToggleHardcore, 0, 0, 2 },
    { 1, 318, 510, 157, 16, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_OnCharCreateOk, (void*)&gData_007089DC },
    { 2, 268, 350, 264, 176, 0, 0, (void*)&gpPopUpOkCancelCelFile },
    { 6, 281, 337, 96, 32, 0, 5103, (void*)&gpOkCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_BackToCharCreate, 0, 0, 2 },
    { 6, 421, 337, 96, 32, 0, 5102, (void*)&gpOkCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_SubmitCharacter, 0, 0, 2 },
    { 4, 268, 320, 264, 120, 10, 8, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 3, 232, 364, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708A00, (void*)(unsigned int)&MAINMENUS_OnSelectAssassin },
    { 3, 720, 370, 88, 184, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_SelectCharacterClass, (void*)&gData_00708A50, (void*)(unsigned int)&MAINMENUS_OnSelectDruid },
    { 4, 339, 561, 200, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 6, 319, 540, 15, 16, 0, 0, (void*)&gpClickBoxCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ToggleExpansion, 0, 0, 2 },
    { 2, 319, 540, 15, 16, 0, 0, (void*)&gpJoinGameClickBoxGreyCelFile },
    { 2, 268, 350, 264, 176, 0, 0, (void*)&gpPopUpOkCancel2CelFile },
    { 6, 281, 337, 96, 32, 27, 5167, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnClosePopup, 0, 0, 2 },
    { 6, 421, 337, 96, 32, 0, 5166, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_JoinSelected, 0, 0, 2 },
    { 4, 268, 320, 264, 120, 10, 8, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 2, 268, 350, 264, 176, 0, 0, (void*)&gpPopUpOkCancel2CelFile },
    { 6, 281, 337, 96, 32, 27, 5167, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_DestroyIfExpansion, 0, 0, 2 },
    { 6, 421, 337, 96, 32, 0, 5166, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_OnCharSelect, 0, 0, 2 },
    { 4, 268, 310, 264, 120, 9, 0, 0, 0, 0, (void*)&gData_007089CC, 2 },
    { 2, 268, 350, 264, 176, 0, 0, (void*)&gpPopUpOkCelFile },
    { 6, 351, 337, 96, 32, 27, 5103, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone, 0, 0, 2 },
    { 4, 268, 300, 264, 100, 10, 8, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 6, 351, 337, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone, 0, 0, 2 },
    { 2, 222, 426, 340, 224, 0, 0, (void*)&gpPopUp340x224CelFile },
    { 6, 330, 416, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone },
    { 4, 222, 280, 340, 60, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 222, 360, 340, 70, 10, 8, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 4, 222, 370, 340, 20, 10, 4, 0, 0, 0, (void*)&gData_007089DC, 2 },
    { 2, 195, 422, 410, 245, 0, 0, (void*)&gpPopUpWideCelFile },
    { 6, 335, 412, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone },
    { 4, 195, 237, 410, 40, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 199, 377, 402, 140, 10, 8, 0, 0, 0, (void*)&gData_007089BC },
    { 2, 158, 460, 485, 290, 0, 0, (void*)&gpPopUpLargestCelFile },
    { 6, 335, 450, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone },
    { 4, 158, 220, 485, 40, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 162, 420, 477, 200, 10, 0, 0, 0, 0, (void*)&gData_007089BC },
    { 4, 162, 320, 477, 100, 10, 0, 0, 0, 0, (void*)&gData_007089BC },
    { 4, 162, 420, 477, 100, 10, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 2, 158, 460, 485, 290, 0, 0, (void*)&gpPopUpLargestCelFile },
    { 6, 335, 450, 128, 35, 13, 5102, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone },
    { 4, 158, 220, 485, 40, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 162, 270, 477, 50, 10, 0, 0, 0, 0, (void*)&gData_007089BC },
    { 4, 158, 310, 485, 40, 0, 0, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 4, 162, 420, 477, 100, 10, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 2, 268, 350, 264, 176, 0, 0, (void*)&gpPopUpOk2CelFile },
    { 6, 351, 337, 96, 32, 13, 5102, (void*)&gpOkCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone, 0, 0, 2 },
    { 4, 268, 320, 264, 120, 10, 8, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 6, 351, 337, 96, 32, 27, 5103, (void*)&gpOkCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CallGatewayDone, 0, 0, 2 },
    { 8, 40, 0, 0, 0, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_ShowCantConnect },
    { 6, 351, 337, 96, 32, 27, 5103, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CancelDownload, 0, 0, 2 },
    { 6, 351, 337, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CancelDownload, 0, 0, 2 },
    { 4, 268, 337, 264, 120, 10, 8, 0, 0, 0, (void*)&gData_007089BC, 2 },
    { 6, 264, 310, 272, 35, 0, 5115, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnOpenBattleNet },
    { 6, 264, 350, 272, 35, 0, 5116, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OpenTcpIpScreen },
    { 6, 264, 568, 272, 35, 27, 5103, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_00434DF0_Leave },
    { 2, 0, 599, 800, 600, 0, 0, (void*)&gpTcpIpBckgCelFile },
    { 4, 100, 76, 600, 40, 0, 0, 0, 0, 0, (void*)&gData_007089AC, 2 },
    { 4, 270, 156, 272, 40, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 4, 265, 171, 272, 40, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 6, 265, 206, 272, 35, 0, 5118, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnTcpIpHost, 0, (void*)(unsigned int)&sub_00430120_OnToggle },
    { 6, 265, 264, 272, 35, 0, 5119, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CreateTcpIpScreen, 0, (void*)(unsigned int)&sub_00430160_OnToggle },
    { 4, 265, 520, 272, 210, 0, 0, 0, 0, 0, (void*)&gData_007089EC, 2 },
    { 4, 265, 520, 272, 210, 2, 0, 0, 0, 0, (void*)&gData_007089EC, 2 },
    { 6, 39, 571, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnCreate },
    { 8, 5000, 0, 0, 0, 0, 0, 0, (D2LaunchCallback)(unsigned int)&MAINMENUS_ShowAddress },
    { 4, 300, 250, 200, 50, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 1, 300, 268, 213, 20, 0, 0, 0, 0, (void*)(unsigned int)&MAINMENUS_JoinTcpIp, (void*)&gData_007089DC },
    { 2, 291, 270, 218, 26, 0, 0, (void*)&gpIPAddressBoxCelFile },
    { 2, 268, 350, 264, 176, 0, 0, (void*)&gpPopUpOkCancel2CelFile },
    { 6, 281, 337, 96, 32, 27, 5103, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnTcpIpJoin },
    { 6, 421, 337, 96, 32, 13, 5102, (void*)&gpCancelButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_JoinTcpIp },
    { 4, 0, 96, 800, 30, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 323, 134, 300, 30, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 16 },
    { 4, 351, 134, 425, 30, 0, 0, 0, 0, 0, (void*)&gData_007089B4 },
    { 4, 0, 599, 200, 40, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 2, 0, 599, 800, 600, 0, 0, (void*)&gpDownloadPatchBckgCelFile },
    { 2, 400, 300, 207, 172, 0, 0, (void*)&gpDownloadPatchBall2CelFile },
    { 6, 336, 540, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_CancelDownload },
    { 13, 195, 422, 410, 245, 4, 4, (void*)&gpTileableDialogCelFile },
    { 6, 335, 412, 128, 35, 0, 0, (void*)&gpMediumButtonBlankCelFile },
    { 6, 415, 412, 128, 35, 0, 0, (void*)&gpMediumButtonBlankCelFile },
    { 6, 255, 412, 128, 35, 0, 0, (void*)&gpMediumButtonBlankCelFile },
    { 4, 195, 237, 410, 40, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 199, 377, 402, 140, 10, 8, 0, 0, 0, (void*)&gData_007089BC },
    { 4, 199, 377, 402, 180, 10, 8, 0, 0, 0, (void*)&gData_007089BC },
    { 2, 250, 347, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 2, 250, 401, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 4, 200, 350, 400, 100, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 4, 200, 515, 400, 100, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 4, 252, 340, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 4, 252, 394, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 1, 253, 342, 293, 19, 8, 4, 0, 0, 0, (void*)&gData_007089DC },
    { 1, 253, 396, 293, 19, 8, 4, 0, 0, 0, (void*)&gData_007089DC },
    { 6, 265, 527, 272, 35, 13, 11097, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ConfirmText },
    { 6, 265, 572, 272, 35, 0, 11098, (void*)&gpWideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_AskEmailRegistration },
    { 6, 33, 572, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnConnectCancel },
    { 4, 0, 310, 800, 50, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 6, 627, 572, 128, 35, 0, 11062, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&CHARSEL_SubmitPasswordReset },
    { 6, 33, 572, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_00437710_OnInfoScreen },
    { 4, 158, 500, 480, 220, 10, 8, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 2, 248, 427, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 4, 250, 420, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 1, 251, 422, 293, 19, 8, 4, 0, 0, (void*)(unsigned int)&CHARSEL_SubmitPasswordReset, (void*)&gData_007089DC },
    { 2, 248, 477, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 4, 250, 470, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 1, 251, 472, 293, 19, 8, 4, 0, 0, (void*)(unsigned int)&CHARSEL_SubmitPasswordReset, (void*)&gData_007089DC },
    { 4, 0, 285, 800, 35, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 0, 300, 800, 16, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 4, 0, 385, 800, 16, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 4, 0, 470, 800, 16, 0, 0, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 6, 264, 335, 272, 35, 0, 11050, (void*)&gp3WideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_004371B0_OnLoginScreen },
    { 6, 264, 420, 272, 35, 0, 11113, (void*)&gp3WideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnEmailScreen },
    { 6, 264, 505, 272, 35, 0, 11115, (void*)&gp3WideButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnPasswordScreen },
    { 6, 33, 572, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&sub_004371D0_OnShowLogin },
    { 4, 0, 310, 800, 50, 0, 0, 0, 0, 0, (void*)&gData_007089B4, 2 },
    { 4, 158, 500, 480, 220, 10, 8, 0, 0, 0, (void*)&gData_007089C4, 2 },
    { 2, 248, 402, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 4, 250, 395, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 1, 251, 397, 293, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePassword, (void*)&gData_007089DC },
    { 2, 248, 452, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 4, 250, 445, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 1, 251, 447, 293, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePassword, (void*)&gData_007089DC },
    { 2, 248, 502, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 4, 250, 495, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 1, 251, 497, 293, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePassword, (void*)&gData_007089DC },
    { 2, 248, 552, 300, 26, 0, 0, (void*)&gpEditTextBoxWideCelFile },
    { 4, 250, 545, 300, 32, 0, 0, 0, 0, 0, (void*)&gData_007089C4 },
    { 1, 251, 547, 293, 19, 8, 4, 0, 0, (void*)(unsigned int)&MAINMENUS_ChangePassword, (void*)&gData_007089DC },
    { 6, 627, 572, 128, 35, 0, 11062, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_ChangePassword },
    { 6, 33, 572, 128, 35, 27, 5103, (void*)&gpMediumButtonBlankCelFile, (D2LaunchCallback)(unsigned int)&MAINMENUS_OnInfoScreen }
}; // 0x00708D10
#pragma comment(linker, "/alternatename:?gatControlTemplates@@3PAUD2LaunchControlTemplateStrc@@A=_gData_00708D10")

extern int gnTextMode = -1; // 0x00708D0C

extern "C" const char gData_006D48E8[16] = "tos-unicode_"; // 0x006D48E8
#pragma comment(linker, "/alternatename:?gszTosPrefix@@3QBDB=_gData_006D48E8")

extern int gnTextSentinel = -1; // 0x0070CB80

extern "C" struct d2data_0070CB84_t gData_0070CB84 = {
    { 0xFF, 0xFF, 0xFF, 0xFF }
}; // 0x0070CB84

extern "C" struct d2data_007089AC_t gData_007089AC = {
    { 0x03 }
}; // 0x007089AC

extern "C" struct d2data_007089B4_t gData_007089B4 = {
    { 0x02 }
}; // 0x007089B4

extern "C" struct d2data_007089BC_t gData_007089BC = {
    { 0x07 }
}; // 0x007089BC

extern "C" struct d2data_007089C4_t gData_007089C4 = {
    { 0x01 }
}; // 0x007089C4

extern "C" struct d2data_007089CC_t gData_007089CC = {
    { 0x00, 0x00, 0x00, 0x00, 0x04 }
}; // 0x007089CC

extern "C" struct d2data_007089D4_t gData_007089D4 = {
    { 0x04, 0x00, 0x00, 0x00, 0x01 }
}; // 0x007089D4

extern "C" struct d2data_007089DC_t gData_007089DC = {
    { 0x05 }
}; // 0x007089DC

extern "C" struct d2data_007089E4_t gData_007089E4 = {
    { 0x04 }
}; // 0x007089E4

extern "C" struct d2data_007089EC_t gData_007089EC = {
    {
        0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x00, 0x00, 0x00, 0xF5, 0x01, 0x00, 0x00,
        0x3F, 0x01
    }
}; // 0x007089EC

extern "C" struct d2data_00708A00_t gData_00708A00 = {
    (const void*)&gapAssassinCelFiles,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x03 },
    (const void*)&gpAsNu2CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x03 },
    (const void*)&gpAsFwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpAsNu3CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpAsBwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708A00

extern "C" struct d2data_00708A50_t gData_00708A50 = {
    (const void*)&gapDruidCelFiles,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpDzNu2CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpDzFwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpDzNu3CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpDzBwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708A50

extern "C" struct d2data_00708AA0_t gData_00708AA0 = {
    (const void*)&gapAmazonCelFiles,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x03 },
    (const void*)&gpAmNu2CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x03 },
    (const void*)&gpAmFwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpAmNu3CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpAmBwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708AA0

extern "C" struct d2data_00708AF0_t gData_00708AF0 = {
    (const void*)&gapNecromancerCelFiles,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x03 },
    (const void*)&gpNeNu2CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x03 },
    (const void*)&gpNeFwCelFile,
    (const void*)&gapNecromancerSCelFiles,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpNeNu3CelFile,
    (const void*)&gpNeNu3SCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpNeBwCelFile,
    (const void*)&gpNeBwSCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708AF0

extern "C" struct d2data_00708B40_t gData_00708B40 = {
    (const void*)&gapBarbarianCelFiles,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpBaNu2CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpBaFwCelFile,
    (const void*)&gpBaFwSCelFile,
    { 0x05, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpBaNu3CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpBaBwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708B40

extern "C" struct d2data_00708B90_t gData_00708B90 = {
    (const void*)&gapSorceressCelFiles,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpSoNu2CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpSoFwCelFile,
    (const void*)&gapSorceressSCelFiles,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpSoNu3CelFile,
    (const void*)&gpSoNu3SCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpSoBwCelFile,
    (const void*)&gpSoBwSCelFile,
    { 0x03, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708B90

extern "C" struct d2data_00708BE0_t gData_00708BE0 = {
    (const void*)&gapPaladinCelFiles,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpPaNu2CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpPaFwCelFile,
    (const void*)&gpPaFwSCelFile,
    { 0x05, 0x00, 0x00, 0x00, 0x01 },
    (const void*)&gpPaNu3CelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x02 },
    (const void*)&gpPaBwCelFile,
    { 0x00, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x01 }
}; // 0x00708BE0

extern "C" struct d2data_00708CDC_t gData_00708CDC = {
    { 0xA9, 0x02, 0x00, 0x00, 0xD3, 0x01, 0x00, 0x00, 0x43, 0x01 }
}; // 0x00708CDC

extern "C" struct d2data_00708CE8_t gData_00708CE8 = {
    { 0x25, 0x02, 0x00, 0x00, 0xEB, 0x01, 0x00, 0x00, 0x9A }
}; // 0x00708CE8

extern "C" struct d2data_00708CF4_t gData_00708CF4 = {
    { 0xB7, 0x01, 0x00, 0x00, 0x87, 0x01, 0x00, 0x00, 0x9A }
}; // 0x00708CF4

extern "C" struct d2data_00708D00_t gData_00708D00 = {
    { 0x49, 0x02, 0x00, 0x00, 0xC9, 0x01, 0x00, 0x00, 0x6B, 0x01 }
}; // 0x00708D00

extern "C" const unsigned char gData_006D4D88[20] = { 1, 1, 1, 1, 1, 0, 0, 0, 1, 1 }; // 0x006D4D88
#pragma comment(linker, "/alternatename:_gabDefault=_gData_006D4D88")

extern "C" struct d2data_00708970_t gData_00708970 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00708970
