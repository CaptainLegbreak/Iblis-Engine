#include "D2Win.h"

#include "D2GameTypes.h"

#include "D2Win32Types.h"

#include "D2CelContext.h"

#include "D2WinTypes.h"

#include "D2StormTypes.h"

#include "D2WinControls.h"

#include "D2Unicode.h"

#include "D2GfxTypes.h"

#include "D2MultiTypes.h"
#include "D2WinPopupLine.h"
#include "D2WinListData.h"

typedef long (__stdcall* WNDPROC)(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam);

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CelFileStrc;

struct Control;

struct D2WinControlStrc;

struct D2WinButtonStrc;

struct D2CelContextStrc;

struct Point;

struct Obj004FA490;

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) int __stdcall GetWindowRect(void* hWnd, tagRECT* lpRect); // 0x006CC4BC

void* __cdecl WINDOW_GetWindow(); // 0x004F59A0

int __stdcall WINDOW_Create(int bWindowed, int nResolution); // 0x004F5610

int __stdcall WINDOW_Resize(int nResolution, int bForceResize); // 0x004F5AA0

void __stdcall WINDOW_EndCutScene(int nResolution); // 0x004F6080

int __stdcall D2GFX_StartDraw(int bClear, unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004F60F0

int __stdcall D2GFX_EndScene(); // 0x004F6190

void __stdcall D2GFX_DrawBoxAlpha(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6340

void __stdcall D2GFX_ClearScreen(int bPartial); // 0x004F63B0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall CONTROL_AppendToDeadList(D2WinControlStrc* pControl); // 0x004F9250

int __stdcall CONTROL_FreeDeadList(); // 0x004F9290

void __cdecl CURSOR_Draw(); // 0x004F97E0

void __cdecl CONTROL_DrawAllCompositeUnits(); // 0x004F9870

void __stdcall D2CMPSpriteCacheInit(void* pMemPool, unsigned int nMaxSize, int nArg, unsigned int nCacheSize); // 0x005FFD40

void __stdcall D2CMPSpriteCacheDestroy(int bFree); // 0x005FFE30

void* ghMainWindow; // 0x007D55AC

extern int gbWindowed; // 0x007D55B4

D2WinControlStrc* gpDeadControlList;                                                                           // 0x007D55C0

int gnWinCallbackDepth; // 0x007D55C4

D2WinEditBoxStrc* gpNextFocusedEditBox; // 0x007D55C8

D2WinControlStrc* gpActiveControlList; // 0x007D55D4

int gbSpriteCacheInitialized; // 0x007D55DC

int (__cdecl* gpfnQuitCallback)(); // 0x007D55EC

int __stdcall WINDOW_Destroy(); // 0x004F5900

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

D2CelFileStrc* gpCursorCellFile; // 0x007D5594

int gnCursorFrame; // 0x007D55A0

tagPOINT gtMousePosition; // 0x007D55A4

extern "C" __declspec(dllimport) void* __stdcall GetDesktopWindow(); // 0x006CC494

extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC

extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect); // 0x006CC4F8

extern "C" __declspec(dllimport) int __stdcall GetWindowPlacement(void* hWnd, tagWINDOWPLACEMENT* lpwndpl); // 0x006CC508

extern "C" __declspec(dllimport) int __stdcall GetMonitorInfoA(void* hMonitor, tagMONITORINFO* lpmi); // 0x006CC510

extern "C" __declspec(dllimport) void* __stdcall MonitorFromWindow(void* hWnd, unsigned long dwFlags); // 0x006CC514

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __cdecl D2GFX_IsFixedAspectRatio(); // 0x004F5180

void __stdcall WINDOW_GetResolutionSize(int nResolution, long* pWidth, long* pHeight); // 0x004F5570

int __stdcall WINDOW_IsFullScreen(); // 0x004F5A30

int __stdcall WINDOW_CenterWindow(int nResolution); // 0x004F5BC0

struct Point { int x, y; };

typedef int (__fastcall* ControlFn)(Control*);

struct Control {
    char prefix[0x0C];
    int x, y, width, height;
    char callbacks[0x1C];
    ControlFn shouldHandle;
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

D2WinControlStrc* gpControlList; // 0x007D55BC

void* gpEscapeButton; // 0x007D55D0

void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg); // 0x004F9BF0

static D2WinControlStrc* __stdcall CONTROL_PickClosestToMouse(D2WinControlStrc* pScrollBar, D2WinControlStrc* pControl); // 0x004FA200

int __fastcall BUTTON_OnMouseWheelScrolled(D2WinButtonStrc* pButton, int nMouseWheelIncrement); // 0x00500B50

void __fastcall BUTTON_SimulateClick(SMSGHANDLER_PARAMS* pMsg); // 0x00500AB0

int __fastcall SCROLLBAR_HandleMouseWheel(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* pScrollBar, int a3); // 0x00508030

int __stdcall POPUP_IsActive(); // 0x005085C0

struct Obj004FA490 { unsigned int dwValue00; };

tagRECT gtSavedWindowRect; // 0x007D5580

D2CelFileStrc* gpBackgroundCellFile; // 0x007D55B0

int gnResolution; // 0x007D55B8

D2WinEditBoxStrc* gpFocusedEditBox; // 0x007D55CC

WNDPROC gpfnWndProc; // 0x007D55D8

int dword_6F8FE278; // 0x007D55E8

struct D2WinEditBoxStrc;

struct D2WinTextBoxStrc;

struct D2WinControlInitStrc;

struct D2Palette256Strc;

struct Unicode;

struct D2WinTextBoxLineStrc;

struct D2WinImage2Strc;

struct D2WinListDataStrc;

struct D2WinListStrc;

struct D2WinAccountListDataStrc;

struct D2WinAccountListStrc;

struct D2WinPopUpLineStrc;

struct D2WinPopUpStrc;

enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};

struct D2Palette256Strc
{
    unsigned char data[0x100];
};

extern "C" __declspec(dllimport) int __stdcall PtInRect(const tagRECT* pRect, tagPOINT tPoint); // 0x006CC4B0

extern "C" __declspec(dllimport) int __stdcall SetCursorPos(int nX, int nY); // 0x006CC4B4

extern "C" __declspec(dllimport) int __stdcall TrackMouseEvent(tagTRACKMOUSEEVENT* pEventTrack); // 0x006CC520

int __cdecl FOG_IsHandlingError(); // 0x00407FF0

void __stdcall WINDOW_SetPaused(int bPaused); // 0x004F5990

int __stdcall WINDOW_GetDimensions(int* pWidth, int* pHeight); // 0x004F59B0

void __stdcall WINDOW_ShowCursor(int nArg); // 0x004F59F0

int __stdcall WINDOW_CheckCutScene(); // 0x004F5DD0

int __stdcall D2GFX_HardwareAcceleratedRenderMode(); // 0x004F6270

D2WinControlStrc* __fastcall D2Win_10042_TEXTBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CelFileStrc* pCellFile, int a8, int a9, int a10, int a11); // 0x004FC7A0

void __fastcall EDITBOX_ClearSelection(D2WinEditBoxStrc* pEditBox); // 0x004FDCC0

D2WinControlStrc* __fastcall IMAGE2_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7, int a8); // 0x004FD6C0

D2WinControlStrc* __fastcall IMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7); // 0x004FD770

D2WinControlStrc* __fastcall TIMER_Create(int nTimeout, int pfCallback); // 0x004FD9D0

D2WinControlStrc* __fastcall D2Win_10070_EDITBOX_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6, D2CelFileStrc* pCellFile, int a8, int a9, int a10, int a11); // 0x005001D0

D2WinControlStrc* __fastcall ANIMIMAGE_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int a6, int a7, int a8, int a9, int a10); // 0x00500850

D2WinControlStrc* __fastcall BUTTON_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int pCallback, int nVirtualKey, int nBaseFrame, int dwButtonFlags, int nStringId, int pUpdateHoverState); // 0x00501290

D2WinControlStrc* __fastcall SMACK_Create(int nX, int nY, int nWidth, int nHeight, int pfHandler); // 0x00506B70

D2WinControlStrc* __fastcall LIST_Create(int nX, int nY, int nWidth, int nHeight, int pInit, int pFont); // 0x005075E0

D2WinControlStrc* __fastcall ACCOUNTLIST_Create(int nX, int nY, int nWidth, int nHeight, int a5, int a6); // 0x00507CA0

D2WinControlStrc* __fastcall PROGRESSBAR_Create(int nX, int nY, int nWidth, int nHeight); // 0x00507E50

D2WinControlStrc* __fastcall SCROLLBAR_Create(int nX, int nY, int nWidth, int nHeight, D2CelFileStrc* pCellFile, int pfnHandler); // 0x005084F0

void __fastcall D2SOUND_10034(int nArg); // 0x005148F0

void __cdecl D2SOUND_FadeOutStreamChannel(); // 0x00514960

int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0

void __fastcall D2SOUND_10049(int nState); // 0x00514D00

int __cdecl D2SOUND_GetOptionsMusicOption(); // 0x00514D80

void __fastcall D2SOUND_10070(int nArg); // 0x00514D90

int __cdecl D2SOUNDFAST_AreWaveSlotsInitialized(); // 0x00515060

D2ArchiveHandleStrc* __fastcall sub_00517332_LoadMpqFile(const char* szFileName, void* hFile, void* pfShowMessage, int nPriority); // 0x00517332

extern "C" const char gszD2XVideoMpq[]; // 0x006DC788

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern int gbAppActive; // 0x0072DC44

extern D2ArchiveHandleStrc* gpD2VideoMPQ; // 0x007D5614




struct D2WinPopUpStrc
{
    D2WinControlStrc controlHeader;
    int nLines;
    D2WinPopUpLineStrc lines[8];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) int __stdcall GetMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax); // 0x006CC484

extern "C" __declspec(dllimport) long __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam); // 0x006CC488

extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode); // 0x006CC4A4

int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam, int* pUseResult, int* pResult); // 0x00420B00

int __stdcall D2GFX_Initialize(void* hInstance, WNDPROC pfWndProc, int nRenderMode, int bWindowed); // 0x004F52E0

void __stdcall D2Win_UpdateAndDraw(); // 0x004F98E0

void __stdcall D2Win_COMMANDS_MouseMove_6F8AD670(SMSGHANDLER_PARAMS* pMsg); // 0x004FA6B0

void __stdcall D2Win_10168_WINMAIN_CreateScreenshot(); // 0x004FA7A0

int __fastcall D2Win_10053(D2WinTextBoxStrc* pTextBox, int nLine); // 0x004FBA30

int __fastcall D2Win_10055(D2WinTextBoxStrc* pTextBox); // 0x004FBAB0

int __stdcall EDITBOX_PlaceMultiLineCaret(SMSGHANDLER_PARAMS* pMsg, int nX, int nY); // 0x004FE3B0

int __fastcall D2Win_10074(D2WinEditBoxStrc* pEditBox, char nChar); // 0x004FEAE0

int __fastcall EDITBOX_HandleKeyDown(D2WinEditBoxStrc* pEditBox, char nKey); // 0x004FF050

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

int __stdcall POPUP_Destroy(); // 0x005085A0

int __stdcall POPUP_HandleMouseButtonInput(SMSGHANDLER_PARAMS* pMsg); // 0x005086A0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __stdcall D2CMPSetNoCompress(int bCompress); // 0x005FE280

int gnRenderMode; // 0x007D5590

extern D2WinPopUpStrc* gpPopUp; // 0x0087E974

int gdwGlobal_007D55B4; // 0x007D55B4

int dword_6F8FE274; // 0x007D55E4

int gbMouseTracking; // 0x007D55F0

int gnSavedVolume; // 0x007D55F8

int gbDeactivated; // 0x007D55FC

unsigned char gabDarkenPalette[256]; // 0x0081E468

unsigned char gabRedPaletteMap[256]; // 0x0081E568

D2Palette256Strc gatShadowsLightGammaPalette[49]; // 0x0081EA68

unsigned char gabLuminancePalette[65536]; // 0x00821B68

unsigned char gabDarkBlendPalette[65536]; // 0x00831B68

struct D2CompositeUnitStrc;

struct D2WinCommandRegisterStrc
{
    int nType;
    int nId;
    void* pCallback;
};

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

int __fastcall D2Win_10177(unsigned char nAct);                                                             // 0x004FB480

int __fastcall D2Win_10043_TEXTBOX_Destroy(D2WinControlStrc* pControl);                                     // 0x004FC960

int __fastcall IMAGE_Destroy(void* pArg);                                                                    // 0x004FD0F0

int __fastcall IMAGE2_Destroy(void* pArg);                                                                    // 0x004FD100

int __fastcall TIMER_Destroy(void* pArg);                                                                    // 0x004FD820

int __fastcall D2Win_10071_EDITBOX_Destroy(D2WinControlStrc* pControl);                                     // 0x004FDAA0

int __fastcall ANIMIMAGE_Destroy(void* pArg);                                                                    // 0x00500300

int __fastcall BUTTON_Destroy(D2WinControlStrc* pControl);                                                  // 0x00500930

void __stdcall D2Win_10116(); // 0x005015F0

void __fastcall D2Win_10115_FONT();                                                                         // 0x00502C60

void __fastcall D2COMP_DrawCompositeShadow(D2CompositeUnitStrc* pCompositeUnit);                                          // 0x00503A50

int __fastcall D2COMP_DrawCompositeUnit(D2CompositeUnitStrc* pCompositeUnit, int nGamma); // 0x00503BA0

D2CompositeUnitStrc* __cdecl D2COMP_GetFirstCompositeUnit();                                                                // 0x00505150

D2CompositeUnitStrc* __stdcall D2Win_10148(D2CompositeUnitStrc* pCompositeUnit);                            // 0x00505160

void __cdecl D2Win_10157(); // 0x00505550

int __fastcall D2COMP_DrawCompositeLabel(D2CompositeUnitStrc* unit); // 0x00505810

int __fastcall D2COMP_DrawCompositeHover(D2CompositeUnitStrc* pCompositeUnit); // 0x00505A80

int __fastcall SMACK_Destroy(D2WinControlStrc* pControl);                                                   // 0x00506A40

void __fastcall WREGISTER_RegisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands); // 0x00506DA0

void __fastcall WREGISTER_UnregisterCommands(void* hWnd, D2WinCommandRegisterStrc* pCommandRegister, unsigned int nCommands); // 0x00506E00

int __fastcall LIST_Destroy(D2WinControlStrc* pControl);                                                    // 0x00506E60

void __stdcall LIST_LoadPentspinCellfile();                                                                 // 0x005070D0

void __stdcall LIST_UnloadPentspinCellfile();                                                               // 0x00507140

int __fastcall ACCOUNTLIST_Destroy(D2WinControlStrc* pControl);                                             // 0x00507AF0

int __fastcall PROGRESSBAR_Destroy(void* pArg);                                                                    // 0x00507DB0

int __fastcall SCROLLBAR_Destroy(void* pArg);                                                                    // 0x00507EE0

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile);                                           // 0x00601A50

extern D2WinCommandRegisterStrc gatCommandRegister[0x21];                                          // 0x0072DC48

struct JPEG_CORE_PROPERTIES;

struct JPEG_CORE_PROPERTIES
{
    int UseJPEGPROPERTIES;
    unsigned char* DIBBytes;
    int DIBWidth;
    int DIBHeight;
    int DIBPadBytes;
    int DIBChannels;
    int DIBColor;
    int DIBSubsampling;
    const char* JPGFile;
    unsigned char* JPGBytes;
    int JPGSizeBytes;
    int JPGWidth;
    int JPGHeight;
    int JPGChannels;
    int JPGColor;
    int JPGSubsampling;
    int JPGThumbWidth;
    int JPGThumbHeight;
    int cconversion_reqd;
    int upsampling_reqd;
    int jquality;
    int unk0x54[0x137B];
};

extern "C" __declspec(dllimport) int __stdcall ijlInit(JPEG_CORE_PROPERTIES* pProps); // 0x006CC5E0

extern "C" __declspec(dllimport) int __stdcall ijlWrite(JPEG_CORE_PROPERTIES* pProps, int nMode); // 0x006CC5E4

extern "C" __declspec(dllimport) int __stdcall ijlFree(JPEG_CORE_PROPERTIES* pProps); // 0x006CC5E8

extern int gnScreenshotIndex; // 0x0072DC40

void* __fastcall FOG_CreateFileA(const char* szFileName, unsigned long dwDesiredAccess, unsigned long dwShareMode, void* pSecurityAttributes, unsigned long dwCreationDisposition, unsigned long dwFlagsAndAttributes, void* hTemplateFile); // 0x00406960

int __fastcall FOG_CloseFile(void* hFile); // 0x004069A0

int __stdcall D2GFX_GetBackBuffer(unsigned char* pBuffer); // 0x004F6250

extern int gnMouseX_007D55A4; // 0x007D55A4

extern int gnMouseY; // 0x007D55A8

unsigned long gdwLastScreenshotTick; // 0x007D5600

struct D2ConfigStrc;

struct D2ComInterfaceStrc;

typedef void (__cdecl* D2LaunchDoneFn)();

void __cdecl CHARSEL_CreateBaseScreen(); // 0x0043C4F0

D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int nId); // 0x0042F430

D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0

void __fastcall sub_004FDAD0_SetKeyCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(D2WinControlStrc*, int, const char*)); // 0x004FDAD0

void __fastcall sub_004FDB00_SetEnterCallback(D2WinControlStrc* pControl, int (__stdcall* pfnCallback)(int)); // 0x004FDB00

void __fastcall sub_004FDD50_SetMaxLength(D2WinControlStrc* pControl, int nLength); // 0x004FDD50

int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10

int __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc* pEditBox); // 0x004F91C0

void __fastcall sub_004FDDD0_LinkTab(D2WinControlStrc* pControl, D2WinControlStrc* pNext); // 0x004FDDD0

void __fastcall MAINMENUS_ShowText(const Unicode* pText, D2LaunchDoneFn pfnDone); // 0x00433450

void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0

int __stdcall D2Win_10033(D2WinControlStrc* pControl, int nArg); // 0x004FA470

void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420

void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0

void __fastcall sub_0042E6B0(int nValue); // 0x0042E6B0

void __fastcall sub_0042E6A0(void (__cdecl* pfnCallback)()); // 0x0042E6A0

void __cdecl CHARSEL_SetCancelled(); // 0x0043B810

void __cdecl MAINMENUS_UpdateStatus(); // 0x00436AD0

int __cdecl sub_004F5D60(); // 0x004F5D60

int __stdcall MAINMENUS_FilterLoginChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FE70

int __stdcall MAINMENUS_FilterRestrictedChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FEF0

int __stdcall sub_0042FF00_FilterChar(D2WinControlStrc* pControl, int nUnused, const char* pChar); // 0x0042FF00

int __stdcall MAINMENUS_OnEditChange(int nArg); // 0x00436F20

int __stdcall sub_004372A0_OnEnter(int nArg); // 0x004372A0

void __cdecl MAINMENUS_UpdateEmailOk(); // 0x00436EB0

void __cdecl MAINMENUS_UpdatePasswordOk(); // 0x004371E0

extern D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0

extern D2ConfigStrc* gpLaunchRecord; // 0x007795D4

extern D2WinControlStrc* gpPasswordEdit; // 0x00779334

extern D2WinControlStrc* gpCreatePasswordEdit; // 0x00779340

extern D2WinControlStrc* gpAccountEdit; // 0x0077958C

extern D2WinControlStrc* gpCreatePasswordConfirmEdit; // 0x007795A8

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

extern D2WinControlStrc* gpEdit_007799DC; // 0x007799DC

extern D2WinControlStrc* gpEdit_007799E0; // 0x007799E0

extern D2WinControlStrc* gpButton_007799E4; // 0x007799E4

extern int gdwGlobal_007D55B8; // 0x007D55B8

void __stdcall WINDOW_ClearCaches(); // 0x004F5D50

int gnCursorDrawX; // 0x007D5598

int gnCursorDrawY; // 0x007D559C

int gbIsMouseButtonPressed; // 0x007D55E0

int gbCloseRequested; // 0x007D55F4

tagRECT gtWindowRect; // 0x007C9160

void __stdcall D2Win_COMMANDS_MouseWheel_6F8AE220(SMSGHANDLER_PARAMS* pMsg);

extern "C" __declspec(dllimport) int __stdcall MessageBoxA(void* hWnd, const char* szText, const char* szCaption, unsigned int nType); // 0x006CC464

void __fastcall ARCHIVE_UnloadMPQFile(D2ArchiveHandleStrc* pMPQHandle); // 0x005173AC

extern "C" const char gszExpansionMpq[]; // 0x006CD3A0

extern "C" const char gszPatchD2Mpq[]; // 0x006DC728

extern "C" const char gszD2SfxMpq[]; // 0x006DC764

extern "C" const char gszD2DataMpq[]; // 0x006DC770

extern D2ArchiveHandleStrc* gpD2CharMPQ; // 0x007D5610

extern D2ArchiveHandleStrc* gpD2XTalkMPQ; // 0x007D5618

extern D2ArchiveHandleStrc* gpD2MusicMPQ; // 0x007D5628

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0

extern int gbPaletteFlash; // 0x0072DE50

extern tagPALETTEENTRY gatRGBAPalette[]; // 0x0081E668

extern int gbTextBoxSmallGap; // 0x00841B70

int __cdecl ARCHIVE_ShowInsertExpansionDiscMessage(); // 0x004FAB00

int __cdecl ARCHIVE_ShowInsertPlayDiscMessage(); // 0x004FAB30

int __cdecl ARCHIVE_ShowInsertCinematicsDisc(); // 0x004FAB60

extern D2ArchiveHandleStrc* gpD2XMusicMPQ; // 0x007D5604

extern D2ArchiveHandleStrc* gpD2SfxMPQ; // 0x007D5608

extern D2ArchiveHandleStrc* gpD2DeltaMPQ; // 0x007D560C

extern D2ArchiveHandleStrc* gpD2DataMPQ; // 0x007D561C

extern D2ArchiveHandleStrc* gpD2kfixupMPQ; // 0x007D5620

extern D2ArchiveHandleStrc* gpD2SpeechMPQ; // 0x007D5624

extern D2ArchiveHandleStrc* gpD2PatchMPQ; // 0x007D5630

extern D2ArchiveHandleStrc* gpD2ExpMPQ; // 0x007D5634

int __cdecl ARCHIVE_LoadArchives(); // 0x004FAB90

void __fastcall D2Win_10178_CopyGammaTable(unsigned char (*pRows)[0x100]); // 0x004FB1C0

extern int gnPaletteFlashCount; // 0x007D5638

extern int gbPaletteFlashWaiting; // 0x00841B68

extern unsigned long gdwPaletteFlashTick; // 0x00841B6C

unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex); // 0x004FB0C0

void __stdcall D2Win_10179_UpdatePaletteFlash(); // 0x004FB0D0

void __fastcall D2Win_10176_StartPaletteFlash(int bTimed); // 0x004FB130

void __fastcall TEXTBOX_SetSmallGap(int nValue); // 0x004FB590

void* __stdcall D2Win_GetArchive(); // 0x004FAC80

struct D2ConfigStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0

int __fastcall FOG_GetInstallPath(char* szPath, unsigned int nSize); // 0x00406BA0

unsigned int __stdcall SStrPack(char* szDest, const char* szSource, unsigned int nDestSize); // 0x00413800

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

extern "C" const char gszD2CharMpq[]; // 0x006DC77C

typedef int (__cdecl* DiscCallback)();

void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70

extern void* ghXMusicMpq; // 0x007D5604

int __cdecl D2Win_10185_CheckCharMpq(); // 0x004FAC90

extern void* ghCharMpq; // 0x007D5610

extern void* ghMusicMpq; // 0x007D5628

extern void* ghXTalkMpq; // 0x007D5618

extern void* ghXVideoMpq; // 0x007D562C

// 0x004F8F10
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution)
{
    gbSpriteCacheInitialized = 1;

    if (!WINDOW_Create(bWindowed, nResolution))
    {
        return 0;
    }

    D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    ghMainWindow = WINDOW_GetWindow();
    gpBackgroundCellFile = 0;
    gpControlList = 0;
    gpDeadControlList = 0;
    gnWinCallbackDepth = 0;
    gpFocusedEditBox = 0;
    gpEscapeButton = 0;
    gpNextFocusedEditBox = 0;
    gpfnWndProc = 0;
    gpActiveControlList = 0;
    dword_6F8FE278 = 0;
    gnCursorFrame = 0;
    gpfnQuitCallback = 0;
    gnResolution = nResolution;
    gbWindowed = bWindowed;
    return 1;
}

// 0x004F8FC0
int __stdcall D2Win_10014_SetWndProc(WNDPROC wndProc)
{
    gpfnWndProc = wndProc;
    return 1;
}

// 0x004F8FE0
int __fastcall D2Win_10015()
{
    D2Win_10115_FONT();
    D2Win_10127_SetFont(1);
    LIST_LoadPentspinCellfile();
    D2Win_10157();
    gpfnWndProc = 0;
    WREGISTER_RegisterCommands(WINDOW_GetWindow(), gatCommandRegister, 0x21);
    D2Win_10177(0);
    gpfnQuitCallback = 0;
    return 1;
}

// 0x004F9030
int __stdcall D2Win_CloseSpriteCache()
{
    gbSpriteCacheInitialized = 0;
    ghMainWindow = 0;
    D2CMPSpriteCacheDestroy(1);
    WINDOW_Destroy();
    return 1;
}

// build: symbol ?MAINMENUS_CreateLoginScreen@* 0x00432100
void __cdecl MAINMENUS_CreateLoginScreen()
{
    CHARSEL_CreateBaseScreen();
    MAINMENUS_CreateControl(0x15);
    MAINMENUS_CreateControl(0x16);
    MAINMENUS_CreateControl(0x18);
    MAINMENUS_CreateControl(0x19);
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x1A);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    pControl = MAINMENUS_CreateControl(0x1B);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2C));
    pControl = MAINMENUS_CreateControl(0x1D);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2D));
    pControl = MAINMENUS_CreateControl(0x1E);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B2E));
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
        pControl = MAINMENUS_CreateControl(0x21);
    else
        pControl = MAINMENUS_CreateControl(0x1F);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B2B), 0x0, 0x0, 0x0);
    gpAccountEdit = MAINMENUS_CreateControl(0x59);
    sub_004FDAD0_SetKeyCallback(gpAccountEdit, MAINMENUS_FilterLoginChar);
    sub_004FDD50_SetMaxLength(gpAccountEdit, 0x10);
    D2Win_10076(gpAccountEdit, gpLaunchRecord->szAccount);
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

// build: symbol ?MAINMENUS_CreateEmailScreen@* 0x00436F30
void __cdecl MAINMENUS_CreateEmailScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x12B);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6A), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x12E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B5F), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x12F);
    pControl = MAINMENUS_CreateControl(0x130);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpEdit_007799DC = MAINMENUS_CreateControl(0x131);
    sub_004FDD50_SetMaxLength(gpEdit_007799DC, 0x10);
    sub_004FDAD0_SetKeyCallback(gpEdit_007799DC, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpEdit_007799DC, MAINMENUS_OnEditChange);
    MAINMENUS_CreateControl(0x132);
    pControl = MAINMENUS_CreateControl(0x133);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B57));
    gpEdit_007799E0 = MAINMENUS_CreateControl(0x134);
    sub_004FDB00_SetEnterCallback(gpEdit_007799E0, MAINMENUS_OnEditChange);
    D2Win_10076(gpEdit_007799DC, gpLaunchRecord->szAccount);
    CONTROL_SetFocusedEditBox(gpEdit_007799DC);
    sub_004FDDD0_LinkTab(gpEdit_007799DC, gpEdit_007799E0);
    sub_004FDDD0_LinkTab(gpEdit_007799E0, gpEdit_007799DC);
    gpButton_007799E4 = MAINMENUS_CreateControl(0x12C);
    MAINMENUS_CreateControl(0x12D);
    MAINMENUS_UpdateEmailOk();
}

// build: symbol ?MAINMENUS_CreateInfoScreen@* 0x004370C0
void __cdecl MAINMENUS_CreateInfoScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x135);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B65), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x136);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B66), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x137);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B67), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x138);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B68), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x139);
    MAINMENUS_CreateControl(0x13A);
    MAINMENUS_CreateControl(0x13B);
    MAINMENUS_CreateControl(0x13C);
}

// build: symbol ?MAINMENUS_CreatePasswordScreen@* 0x004372B0
void __cdecl MAINMENUS_CreatePasswordScreen()
{
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        MAINMENUS_ShowText(D2LANG_GetStringFromTblIndex(0x14E3), MAINMENUS_ShowMainMenu);
        return;
    }
    CHARSEL_CreateBaseScreen();
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(0x13D);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B6C), 0x0, 0x0, 0x0);
    pControl = MAINMENUS_CreateControl(0x13E);
    D2Win_10051(pControl, D2LANG_GetStringFromTblIndex(0x2B70), 0x0, 0x0, 0x0);
    MAINMENUS_CreateControl(0x13F);
    pControl = MAINMENUS_CreateControl(0x140);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x1468));
    gpChangePwAccountEdit = MAINMENUS_CreateControl(0x141);
    D2Win_10076(gpChangePwAccountEdit, gpLaunchRecord->szAccount);
    sub_004FDD50_SetMaxLength(gpChangePwAccountEdit, 0x10);
    sub_004FDAD0_SetKeyCallback(gpChangePwAccountEdit, MAINMENUS_FilterRestrictedChar);
    sub_004FDB00_SetEnterCallback(gpChangePwAccountEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x142);
    pControl = MAINMENUS_CreateControl(0x143);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6D));
    gpOldPasswordEdit = MAINMENUS_CreateControl(0x144);
    sub_004FDB00_SetEnterCallback(gpOldPasswordEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x145);
    pControl = MAINMENUS_CreateControl(0x146);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6E));
    gpNewPasswordEdit = MAINMENUS_CreateControl(0x147);
    sub_004FDB00_SetEnterCallback(gpNewPasswordEdit, sub_004372A0_OnEnter);
    MAINMENUS_CreateControl(0x148);
    pControl = MAINMENUS_CreateControl(0x149);
    D2Win_10044(pControl, D2LANG_GetStringFromTblIndex(0x2B6F));
    gpNewPasswordConfirmEdit = MAINMENUS_CreateControl(0x14A);
    sub_004FDB00_SetEnterCallback(gpNewPasswordConfirmEdit, sub_004372A0_OnEnter);
    gpPasswordOk = MAINMENUS_CreateControl(0x14B);
    MAINMENUS_CreateControl(0x14C);
    CONTROL_SetFocusedEditBox(gpChangePwAccountEdit);
    sub_004FDDD0_LinkTab(gpChangePwAccountEdit, gpOldPasswordEdit);
    sub_004FDDD0_LinkTab(gpOldPasswordEdit, gpNewPasswordEdit);
    sub_004FDDD0_LinkTab(gpNewPasswordEdit, gpNewPasswordConfirmEdit);
    sub_004FDDD0_LinkTab(gpNewPasswordConfirmEdit, gpChangePwAccountEdit);
    MAINMENUS_UpdatePasswordOk();
}

// build: symbol ?MAINMENUS_CreateStatusScreen@* 0x00437550
void __cdecl MAINMENUS_CreateStatusScreen()
{
    gdwStatusStart = GetTickCount();
    MAINMENUS_DestroyControls();
    sub_0042E6B0(0x1);
    D2WinControlStrc* pFrame = MAINMENUS_CreateFromTemplate(0xE2);
    D2Win_10033(pFrame, 0x0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 0x1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xE3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 0x1);
    D2WinControlStrc* pText = MAINMENUS_CreateFromTemplate(0xE4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pText, 0x1);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x1433), 0x0, 0x0, 0x0);
    gpStatusText = MAINMENUS_CreateFromTemplate(0xE5);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpStatusText, 0x1);
    gpCounterText = MAINMENUS_CreateFromTemplate(0xE6);
    D2Win_10030_CONTROL_ToggleFourthFlag(gpCounterText, 0x1);
    gnStatusStringId = -1;
    gnStatusDots = 0x0;
    sub_0042E6A0(CHARSEL_SetCancelled);
    MAINMENUS_UpdateStatus();
}

// 0x004F9050
int __cdecl D2Win_10003()
{
    gdwGlobal_007D55B8 = 0x0;
    return sub_004F5D60();
}

// 0x004F9060
void __stdcall D2Win_10004(int nResolution)
{
    gnResolution = nResolution;

    if (nResolution == 1)
    {
        D2CMPSpriteCacheDestroy(1);
    }

    WINDOW_EndCutScene(nResolution);

    if (nResolution == 1)
    {
        D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    }
}

// 0x004F90A0
int __stdcall D2Win_10005(int nResolution)
{
    if (!gnResolution && !gtSavedWindowRect.right)
    {
        void* hWnd = WINDOW_GetWindow();
        WINDOW_GetDimensions((int*)&gtSavedWindowRect.right, (int*)&gtSavedWindowRect.bottom);
        GetWindowRect(hWnd, &gtSavedWindowRect);
    }

    gnResolution = nResolution;
    D2CMPSpriteCacheDestroy(1);
    if (!WINDOW_Resize(nResolution, 0))
    {
        LOGMANAGER_WriteLogLine("Failed to resize window... this is fatal!");
        exit(-1);
    }

    D2Win_10176_StartPaletteFlash(0);
    D2CMPSpriteCacheInit(0, 0x800000, 0x7D000, 0);
    return 1;
}

// 0x004F9130
void __stdcall D2Win_10006_ClearDrawCaches()
{
    WINDOW_ClearCaches();
}

// 0x004F9140
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile)
{
    gpBackgroundCellFile = pCellFile;
    return 1;
}

// 0x004F9160
int __stdcall CURSOR_SetCellFile(D2CelFileStrc* pCellFile)
{
    gpCursorCellFile = pCellFile;
    return 1;
}

// 0x004F9180
void __stdcall D2Win_SetQuitCallback(int (__cdecl* a1)())
{
    gpfnQuitCallback = a1;
}

// 0x004F9190
int __fastcall D2Win_StopMessageLoop()
{
// build: symbol ?gbRunMessageLoop@* 0x0072DDD4
    gbRunMessageLoop = 0;
    return 1;
}

// 0x004F91A0
int __stdcall CONTROL_SetCellFile(D2WinControlStrc* pControl, D2CelFileStrc* pCellFile)
{
    pControl->pCellFile = pCellFile;
    return 1;
}

// 0x004F91C0
int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox)
{
    if (gpNextFocusedEditBox)
    {
        if (pEditBox != gpNextFocusedEditBox)
        {
            EDITBOX_ClearSelection(gpNextFocusedEditBox);
        }

        gpNextFocusedEditBox = pEditBox;
        return 1;
    }

    gpNextFocusedEditBox = pEditBox;
    return 1;
}

extern int gdwGlobal_007D55CC; // 0x007D55CC

// 0x004F9200
int __cdecl CONTROL_GetFocusedEditBox()
{
    return gdwGlobal_007D55CC;
}

// 0x004F9210
int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl)
{
    if (!gpControlList)
    {
        gpControlList = pControl;
        return 1;
    }

    D2WinControlStrc* pLast = gpControlList;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pControl;
    return 1;
}

// 0x004F9250
int __fastcall CONTROL_AppendToDeadList(D2WinControlStrc* pControl)
{
    pControl->pNext = 0;
    if (!gpDeadControlList)
    {
        gpDeadControlList = pControl;
        return 1;
    }

    D2WinControlStrc* pLast = gpDeadControlList;
    while (pLast->pNext)
    {
        pLast = pLast->pNext;
    }
    pLast->pNext = pControl;
    return 1;
}

// 0x004F9290
int __stdcall CONTROL_FreeDeadList()
{
    if (gnWinCallbackDepth_007D55C4 > 0)
    {
        return 1;
    }

    while (gpDeadControlList)
    {
        if (gpDeadControlList->dwFlags & gdwBitMasks[0])
        {
            break;
        }

        D2WinControlStrc* pNext = gpDeadControlList->pNext;
        FOG_Free(gpDeadControlList, ".\\Src\\D2WinMain.cpp", 0x25A, 0);
        gpDeadControlList = pNext;
    }

    while (gpDeadControlList)
    {
        if (gpDeadControlList->dwFlags & gdwBitMasks[1])
        {
            break;
        }

        D2WinControlStrc* pNext = gpDeadControlList->pNext;
        FOG_Free(gpDeadControlList, ".\\Src\\D2WinMain.cpp", 0x263, 0);
        gpDeadControlList = pNext;
    }

    return 1;
}

// 0x004F9310
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl)
{
    if ((D2WinControlStrc*)gpFocusedEditBox == pControl)
    {
        gpFocusedEditBox = 0;
    }

    if ((D2WinControlStrc*)gpNextFocusedEditBox == pControl)
    {
        gpNextFocusedEditBox = 0;
    }

    if (gpActiveControlList == pControl)
    {
        gpActiveControlList = 0;
        dword_6F8FE278 = 0;
    }

    if (gpEscapeButton == pControl)
    {
        gpEscapeButton = 0;
    }

    D2WinControlStrc* pPrevious = gpControlList;
    if (!pPrevious)
    {
        return 0;
    }

    if (pPrevious == pControl)
    {
        gpControlList = pControl->pNext;
        CONTROL_AppendToDeadList(pControl);
        return 1;
    }

    for (D2WinControlStrc* pCurrent = pPrevious->pNext; pCurrent; pCurrent = pCurrent->pNext)
    {
        if (pCurrent == pControl)
        {
            pPrevious->pNext = pCurrent->pNext;
            CONTROL_AppendToDeadList(pControl);
            return 1;
        }

        pPrevious = pCurrent;
    }

    return 1;
}

// 0x004F93C0
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit)
{
    D2CelFileStrc* pCellFile = pControlInit->ppCellFile ? *(D2CelFileStrc**)pControlInit->ppCellFile : 0;

    switch (pControlInit->nType)
    {
    case D2WIN_TEXTBOX:
        return D2Win_10042_TEXTBOX_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->nArg, pControlInit->nStringId, pCellFile, pControlInit->anArgs[0], pControlInit->anArgs[3], pControlInit->anArgs[2], pControlInit->anArgs[1]);

    case D2WIN_EDITBOX:
        return D2Win_10070_EDITBOX_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->nArg, pControlInit->nStringId, pCellFile, pControlInit->anArgs[1], pControlInit->anArgs[0], pControlInit->anArgs[3], pControlInit->anArgs[2]);

    case D2WIN_IMAGE:
        return IMAGE2_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->anArgs[0], pControlInit->anArgs[1], pControlInit->anArgs[2]);

    case D2WIN_ANIMIMAGE:
        return ANIMIMAGE_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->nArg, pControlInit->anArgs[0], pControlInit->anArgs[1], pControlInit->nStringId, pControlInit->anArgs[2]);

    case D2WIN_IMAGE2:
        return IMAGE_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->nArg, pControlInit->nStringId);

    case D2WIN_SCROLLBAR:
        return SCROLLBAR_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->anArgs[0]);

    case D2WIN_BUTTON:
        return BUTTON_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pCellFile, pControlInit->anArgs[0], pControlInit->nArg, pControlInit->anArgs[1], pControlInit->anArgs[3], pControlInit->nStringId, pControlInit->anArgs[2]);

    case D2WIN_LIST:
        return LIST_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->anArgs[1], pControlInit->anArgs[2]);

    case D2WIN_TIMER:
        return TIMER_Create(pControlInit->nX, pControlInit->anArgs[0]);

    case D2WIN_SMACK:
        return SMACK_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->anArgs[0]);

    case D2WIN_PROGRESSBAR:
        return PROGRESSBAR_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight);

    case D2WIN_ACCOUNTLIST:
        return ACCOUNTLIST_Create(pControlInit->nX, pControlInit->nY, pControlInit->nWidth, pControlInit->nHeight, pControlInit->anArgs[3], pControlInit->anArgs[2]);

    default:
        break;
    }

    return 0;
}

// 0x004F95C0
int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl)
{
    if (!ppControl)
    {
        return 0;
    }

    D2WinControlStrc* pControl = *ppControl;
    if (!pControl)
    {
        return 0;
    }

    int nResult;
    switch (pControl->eType)
    {
    case D2WIN_TEXTBOX:
        nResult = D2Win_10043_TEXTBOX_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_EDITBOX:
        nResult = D2Win_10071_EDITBOX_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_IMAGE:
        nResult = IMAGE_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_IMAGE2:
        nResult = IMAGE2_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_ANIMIMAGE:
        nResult = ANIMIMAGE_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_SCROLLBAR:
        nResult = SCROLLBAR_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_BUTTON:
        nResult = BUTTON_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_LIST:
        nResult = LIST_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_TIMER:
        nResult = TIMER_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_SMACK:
        nResult = SMACK_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_PROGRESSBAR:
        nResult = PROGRESSBAR_Destroy(pControl);
        *ppControl = 0;
        break;

    case D2WIN_ACCOUNTLIST:
        nResult = ACCOUNTLIST_Destroy(pControl);
        *ppControl = 0;
        break;

    default:
        nResult = 0;
        *ppControl = 0;
        break;
    }

    return nResult;
}

// 0x004F96F0
void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags)
{
    if (!pControl)
    {
        return;
    }

    if (nFlags)
    {
        pControl->dwFlags |= gdwBitMasks[0];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[0];
    }
}

// 0x004F9710
int __fastcall CONTROL_IsEnabled(D2WinControlStrc* pControl)
{
    D2_ASSERT(pControl, 0x33F);

    return pControl->dwFlags & gdwBitMasks[0];
}

// 0x004F9740
void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet)
{
    D2_ASSERT(pControl, 0x34C);

    if (bSet)
    {
        pControl->dwFlags |= gdwBitMasks[2];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[2];
    }
}

// 0x004F9780
int __fastcall CONTROL_IsVisible(D2WinControlStrc* pControl)
{
    D2_ASSERT(pControl, 0x35A);

    return pControl->dwFlags & gdwBitMasks[2];
}

// 0x004F97B0
int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect)
{
    return PtInRect(pRect, gtMousePosition);
}

extern int gdwGlobal_007D55E4; // 0x007D55E4

// 0x004F97D0
int __cdecl D2Win_IsCtrlKeyDown()
{
    return gdwGlobal_007D55E4;
}

// 0x004F97E0
void __cdecl CURSOR_Draw()
{
// build: symbol ?gbDrawCursor@* 0x0072DC3C
    if (gpCursorCellFile && gbDrawCursor)
    {
        int nX = gtMousePosition.x;
        int nY = gtMousePosition.y;
        gnCursorDrawX = nX;
        gnCursorDrawY = nY;

        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.nFrame = gnCursorFrame;
        tContext.pCellFile = gpCursorCellFile;
        tContext.nDirection = 0;
        sub_004F6480(&tContext, nX <= 0 ? 0 : nX, (nY <= 0 ? 0 : nY) - 1, -1, 5, 0);
    }
}

// 0x004F9870
void __cdecl CONTROL_DrawAllCompositeUnits()
{
    for (D2CompositeUnitStrc* p = D2COMP_GetFirstCompositeUnit(); p; p = D2Win_10148(p))
    {
        D2COMP_DrawCompositeShadow(p);
    }

    for (D2CompositeUnitStrc* p = D2COMP_GetFirstCompositeUnit(); p; p = D2Win_10148(p))
    {
        D2COMP_DrawCompositeUnit(p, -1);
    }

    for (D2CompositeUnitStrc* p = D2COMP_GetFirstCompositeUnit(); p; p = D2Win_10148(p))
    {
        D2COMP_DrawCompositeLabel(p);
        D2COMP_DrawCompositeHover(p);
    }
}

// 0x004F98E0
void __stdcall D2Win_UpdateAndDraw()
{
    if (WINDOW_GetState())
    {
        return;
    }

    for (D2WinControlStrc* i = gpControlList; i; i = i->pNext)
    {
        if (i->pfInitialize)
        {
            i->pfInitialize(i);
        }
    }

    if (gpfnWndProc)
    {
        return;
    }

    long nScreenWidth;
    long nScreenHeight;
    WINDOW_GetDimensions((int*)&nScreenWidth, (int*)&nScreenHeight);

    if (D2GFX_StartDraw(0, 0, 0, 0))
    {
        D2GFX_ClearScreen(0);

        if (gpBackgroundCellFile)
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            tContext.pCellFile = gpBackgroundCellFile;
            tContext.nDirection = 0;
            tContext.nFrame = 0;

            for (int y = 256; y < 768; y += 256)
            {
                for (int x = 0; x < 1024; x += 256)
                {
                    sub_004F6480(&tContext, x, y, -1, 5, 0);
                    ++tContext.nFrame;
                }
            }

            for (int x = 0; x < 1024; x += 256)
            {
                sub_004F6480(&tContext, x, nScreenHeight - 1, -1, 5, 0);
                ++tContext.nFrame;
            }
        }

        for (D2WinControlStrc* i = gpControlList; i; i = i->pNext)
        {
            if (i->pfDraw && !(i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        CONTROL_DrawAllCompositeUnits();

        if (dword_6F8FE278)
        {
            D2GFX_DrawBoxAlpha(0, 0, nScreenWidth, nScreenHeight, 0, 127);
        }

        for (D2WinControlStrc* i = gpControlList; i; i = i->pNext)
        {
            if (i->pfDraw && (i->dwFlags & gdwBitMasks_006CE268[3]))
            {
                i->pfDraw(i);
            }
        }

        CURSOR_Draw();
        D2GFX_EndScene();
    }

    CONTROL_FreeDeadList();
}

static inline int CONTROL_IsMouseInside_004FA860(D2WinControlStrc* pControl)
{
    const int nImageY = pControl->nImageY;
    return gtMousePosition.x >= pControl->nImageX && gtMousePosition.y >= nImageY - pControl->nHeight
        && gtMousePosition.x < pControl->nImageX + pControl->nWidth && gtMousePosition.y < nImageY;
}

// 0x004F9A80
long __stdcall D2Win_MAINWINDOW_WndProc_6F8AD9B0(void* hWnd, unsigned int uMsg, unsigned int wParam, long lParam)
{
    if (!gbSpriteCacheInitialized)
    {
        return 0;
    }

    if (gpfnWndProc)
    {
        return gpfnWndProc(hWnd, uMsg, wParam, lParam);
    }

    int bUseResult = 0;
    int lResult = 0;
    if (uMsg == 0x10)
    {
        gbCloseRequested = 1;
        PostQuitMessage(0);
        return 0;
    }

    if (SMsgDispatchMessage(hWnd, uMsg, wParam, lParam, &bUseResult, &lResult) && bUseResult)
    {
        return lResult;
    }

    return DefWindowProcA(hWnd, uMsg, wParam, lParam);
}

// 0x004F9B30
int __fastcall CONTROL_IsActiveListMember(D2WinControlStrc* pControl)
{
    if (gpActiveControlList)
    {
        for (D2WinControlStrc* p = gpActiveControlList; p; p = p->pNext)
        {
            if (p == pControl)
            {
                return 1;
            }
        }
        return 0;
    }
    return 1;
}

// 0x004F9B60
void __stdcall D2Win_COMMANDS_Char_6F8ADA80(SMSGHANDLER_PARAMS* pMsg)
{
    const int nChar = pMsg->wParam;
    if (gpFocusedEditBox)
    {
        if (gpActiveControlList)
        {
            for (D2WinControlStrc* i = gpActiveControlList; i; i = i->pNext)
            {
                if ((D2WinEditBoxStrc*)i == gpFocusedEditBox)
                {
                    goto check_edit_box;
                }
            }
            goto dispatch;
        }

check_edit_box:
        if (D2Win_10074(gpFocusedEditBox, nChar))
        {
            goto done;
        }
    }

dispatch:
    {
        D2WinControlStrc* pControl = gpActiveControlList;
        if (!pControl)
        {
            pControl = gpControlList;
        }

        while (pControl)
        {
            if (pControl->pfHandleCharInput)
            {
                pMsg->hWnd = pControl;
                ++gnWinCallbackDepth;
                const int nResult = pControl->pfHandleCharInput(pMsg);
                --gnWinCallbackDepth;
                if (nResult)
                {
                    break;
                }
            }
            pControl = pControl->pNext;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9BF0
void __stdcall D2Win_COMMANDS_VirtualKey_6F8ADB50(SMSGHANDLER_PARAMS* pMsg)
{
    const int nKey = pMsg->wParam;
    if (gpFocusedEditBox)
    {
        if (gpActiveControlList)
        {
            for (D2WinControlStrc* i = gpActiveControlList; i; i = i->pNext)
            {
                if ((D2WinEditBoxStrc*)i == gpFocusedEditBox)
                {
                    goto check_edit_box;
                }
            }
            goto dispatch;
        }

check_edit_box:
        if (EDITBOX_HandleKeyDown(gpFocusedEditBox, nKey))
        {
            goto done;
        }
    }

dispatch:
    {
        D2WinControlStrc* pControl = gpActiveControlList;
        if (!pControl)
        {
            pControl = gpControlList;
        }

        while (pControl)
        {
            if (pControl->pfHandleVirtualKeyInput)
            {
                pMsg->hWnd = pControl;
                ++gnWinCallbackDepth;
                const int nResult = pControl->pfHandleVirtualKeyInput(pMsg);
                --gnWinCallbackDepth;
                if (nResult)
                {
                    break;
                }
            }
            pControl = pControl->pNext;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9C80
void __stdcall D2Win_COMMANDS_ControlDown(SMSGHANDLER_PARAMS* pMsg)
{
    dword_6F8FE274 = 1;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9CA0
void __stdcall D2Win_COMMANDS_ControlUp(SMSGHANDLER_PARAMS* pMsg)
{
    dword_6F8FE274 = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004F9CC0
void __stdcall D2Win_COMMANDS_SysCommand(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned short nCommand = pMsg->wParamLow & 0xFFF0;
    if (nCommand == 0xF130 || nCommand == 0xF100 || (nCommand == 0xF010 && WINDOW_IsFullScreen()))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        return;
    }

    if (nCommand != 0xF030)
    {
        return;
    }

    if (WINDOW_IsFullScreen())
    {
        return;
    }

    void* hWnd = WINDOW_GetWindow();
    void* hMonitor = MonitorFromWindow(hWnd, 2);
    tagMONITORINFO tMonitorInfo;
    tMonitorInfo.cbSize = sizeof(tagMONITORINFO);
    GetMonitorInfoA(hMonitor, &tMonitorInfo);

    tagRECT tClientRect = {};
    GetClientRect(hWnd, &tClientRect);
    const int nClientWidth = tClientRect.right - tClientRect.left;
    const int nClientHeight = tClientRect.bottom - tClientRect.top;

    tagRECT tWorkArea = tMonitorInfo.rcWork;
    const int nWorkWidth = tWorkArea.right - tWorkArea.left;
    const int nWorkHeight = tWorkArea.bottom - tWorkArea.top;

    tagRECT tRect = {};
    const int nMode = D2GFX_GetResolutionMode();
    WINDOW_GetResolutionSize(nMode, &tRect.right, &tRect.bottom);

    tagRECT tDesktopRect;
    GetClientRect(GetDesktopWindow(), &tDesktopRect);

    if (nClientWidth == tRect.right && nClientHeight == tRect.bottom
        && tDesktopRect.right - tDesktopRect.left > tRect.right && tDesktopRect.bottom - tDesktopRect.top > tRect.bottom)
    {
        tRect.left = tWorkArea.left;
        tRect.top = tWorkArea.top;
        if (!D2GFX_IsFixedAspectRatio())
        {
            return;
        }

        tagWINDOWPLACEMENT tPlacement;
        GetWindowPlacement(hWnd, &tPlacement);
        if (tPlacement.showCmd != 3)
        {
            while (tRect.right < nWorkWidth && tRect.bottom < nWorkHeight)
            {
                tRect.right += 4;
                tRect.bottom += 3;
            }
            tRect.right -= 12;
            tRect.bottom -= 9;
            tRect.left = (nWorkWidth - tRect.right) / 2 + tWorkArea.left;
            tRect.top = (nWorkHeight - tRect.bottom) / 2 + tWorkArea.top;
            if (tRect.top < 0)
            {
                tRect.top = 0;
            }
            if (tRect.left < 0)
            {
                tRect.left = 0;
            }
            gtWindowRect = tPlacement.rcNormalPosition;
            SetWindowPos(hWnd, (void*)-2, tRect.left, tRect.top, tRect.right, tRect.bottom, 0x14);
        }
    }
    else if (tRect.bottom < tWorkArea.bottom && tRect.right < tWorkArea.right)
    {
        tagRECT tNewRect = { 0 };
        const int nResolution = D2GFX_GetResolutionMode();
        WINDOW_GetResolutionSize(nResolution, &tNewRect.right, &tNewRect.bottom);
        SetWindowPos(hWnd, (void*)-2, 0, 0, tNewRect.right, tNewRect.bottom, 0x14);
        WINDOW_CenterWindow(nResolution);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004F9F20
void __stdcall D2Win_COMMANDS_ActivateApp_6F8ADC40(SMSGHANDLER_PARAMS* pMsg)
{
    const unsigned int nActive = pMsg->wParam;
    gbAppActive = nActive != 0;
    if (nActive)
    {
        if (!FOG_IsHandlingError())
        {
            WINDOW_SetPaused(0);
            D2Win_10176_StartPaletteFlash(1);
        }

        D2SOUND_10049(gnSavedVolume);
        gbDeactivated = 0;
    }
    else
    {
        if (!gbDeactivated)
        {
            gnSavedVolume = D2SOUND_GetMusicVolumeOption();
        }

        gbDeactivated = 1;
        if (gdwGlobal_007D55B4 != 1)
        {
            WINDOW_SetPaused(1);
        }
    }

    if (WINDOW_CheckCutScene())
    {
        WINDOW_GetState();
    }

    pMsg->bReturn = 0;
}

// 0x004F9FB0
static void __stdcall D2Win_WriteScreenshotJpeg(unsigned char* pData, const char* szFile, int nWidth, int nHeight)
{
    char szName[256];
    JPEG_CORE_PROPERTIES tProps;
    while (1)
    {
        sprintf(szName, "Screenshot%03d.jpg", gnScreenshotIndex);
        ++gnScreenshotIndex;
        void* hFile = FOG_CreateFileA(szFile ? szFile : szName, 0x80000000, 0, 0, 3, 0x80, 0);
        if (hFile == (void*)-1)
        {
            break;
        }

        FOG_CloseFile(hFile);
        if (szFile)
        {
            return;
        }
    }

    memset(&tProps, 0, sizeof(tProps));
    ijlInit(&tProps);
    tProps.DIBWidth = nWidth;
    tProps.DIBHeight = nHeight;
    tProps.DIBBytes = pData;
    tProps.DIBColor = 1;
    tProps.DIBPadBytes = ((nWidth * 3 + 3) & ~3) - nWidth * 3;
    if (szFile)
    {
        tProps.JPGFile = szFile;
    }
    else
    {
        tProps.JPGFile = szName;
    }
    tProps.JPGWidth = nWidth;
    tProps.JPGHeight = nHeight;
    tProps.jquality = 100;
    ijlWrite(&tProps, 8);
    ijlFree(&tProps);
}

// 0x004FA0C0
void __fastcall D2Win_SaveScreenshotToFile(const char* szFile)
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick < 1000 && !szFile)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions((int*)&nWidth, (int*)&nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        D2Win_WriteScreenshotJpeg(pBuffer, szFile, nWidth, nHeight);
    }

    gdwLastScreenshotTick = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

// 0x004FA160
void __stdcall D2Win_COMMANDS_ToggleMusic(SMSGHANDLER_PARAMS* pMsg)
{
    if (!dword_6F8FE274 || !D2SOUNDFAST_AreWaveSlotsInitialized())
    {
        return;
    }

    if (D2SOUND_GetOptionsMusicOption())
    {
        D2SOUND_FadeOutStreamChannel();
        D2SOUND_10070(0);
    }
    else
    {
        D2SOUND_10034(1);
        D2SOUND_10070(1);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004FA1B0
static inline int CONTROL_IsPointInside(Control* control, const Point* point)
{
    if (control->shouldHandle)
        return control->shouldHandle(control);
    const int left = control->x;
    const int bottom = control->y;
    if (point->x >= left && point->y >= bottom - control->height
        && point->x < left + control->width && point->y < bottom)
        return 1;
    return 0;
}

// 0x004FA200
static D2WinControlStrc* __stdcall CONTROL_PickClosestToMouse(D2WinControlStrc* first, D2WinControlStrc* second)
{
    if (!first) return second;
    if (!second) return first;
    int mouseX = gnMouseX_007D55A4;
    int mouseY = gnMouseY;
    int dx1, dy1, dx2, dy2;
    if (mouseX < first->nImageX)
        dx1 = mouseX - first->nImageX;
    else if (mouseX > first->nWidth + first->nImageX)
        dx1 = mouseX - first->nWidth - first->nImageX;
    else
        dx1 = 0;
    if (mouseY < first->nImageY - first->nHeight)
        dy1 = first->nHeight - first->nImageY + mouseY;
    else if (mouseY > first->nImageY)
        dy1 = mouseY - first->nImageY;
    else
        dy1 = 0;

    if (mouseX < second->nImageX)
        dx2 = mouseX - second->nImageX;
    else if (mouseX > second->nWidth + second->nImageX)
        dx2 = mouseX - second->nWidth - second->nImageX;
    else
        dx2 = 0;
    if (mouseY < second->nImageY - second->nHeight)
        dy2 = second->nHeight - second->nImageY + mouseY;
    else if (mouseY > second->nImageY)
        dy2 = mouseY - second->nImageY;
    else
        dy2 = 0;
    int alignedFirst = dy1 == 0 && dx1 <= 0;
    int alignedSecond = dy2 == 0 && dx2 <= 0;
    if (alignedFirst && !alignedSecond)
        return first;
    if (!alignedFirst && alignedSecond)
        return second;
    if (alignedFirst && alignedSecond)
    {
        if (dx1 > dx2)
            return first;
        return second;
    }
    if (dy1 * dy1 + dx1 * dx1 < dy2 * dy2 + dx2 * dx2)
        return first;
    return second;
}

int __stdcall emit_hit_test_004FA1B0(Control* control, const Point* point) { return CONTROL_IsPointInside(control, point); }

inline int CONTROL_IsInActiveList(void* pControl)
{
    if (!gpActiveControlList)
    {
        return 1;
    }

    for (D2WinControlStrc* p = gpActiveControlList; p; p = p->pNext)
    {
        if (p == pControl)
        {
            return 1;
        }
    }

    return 0;
}

// 0x004FA340
void __stdcall D2Win_COMMANDS_MouseWheel_6F8AE220(SMSGHANDLER_PARAMS* pMsg)
{
    const int nIncrement = (int)(short)(pMsg->wParam >> 16) / 120;

    if (POPUP_IsActive())
    {
        return;
    }

    D2WinControlStrc* pScrollBar = 0;
    D2WinControlStrc* pFirst = gpActiveControlList ? gpActiveControlList : gpControlList;
    if (pFirst)
    {
        D2WinControlStrc* pControl = pFirst;
        do
        {
            if (pControl->eType == D2WIN_SCROLLBAR && pControl->dwFlags & gdwBitMasks[2] && pControl->dwFlags & gdwBitMasks[0] && SCROLLBAR_GetMaxSteps((D2WinScrollBarStrc*)pControl) > 0)
            {
                pScrollBar = CONTROL_PickClosestToMouse(pScrollBar, pControl);
            }

            pControl = pControl->pNext;
        }
        while (pControl);

        if (pScrollBar && SCROLLBAR_HandleMouseWheel(pMsg, (D2WinScrollBarStrc*)pScrollBar, nIncrement))
        {
            goto done;
        }
    }

    for (D2WinControlStrc* i = pFirst; i; i = i->pNext)
    {
        if (i->eType == D2WIN_BUTTON && BUTTON_OnMouseWheelScrolled((D2WinButtonStrc*)i, nIncrement))
        {
            break;
        }
    }

done:
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004FA410
void __stdcall D2Win_10029(int a1)
{
    gbDrawCursor = a1;
}

// 0x004FA420
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet)
{
    if (bSet)
    {
        pControl->dwFlags |= gdwBitMasks_006CE268[3];
    }
    else
    {
        pControl->dwFlags &= gdwInvBitMasks[3];
    }
}

// 0x004FA450
void __stdcall CONTROL_SetEscapeButton(void* a1)
{
    gpEscapeButton = a1;
}

extern int gdwGlobal_007D55D4; // 0x007D55D4

// 0x004FA460
int __cdecl D2Win_IsMouseButtonPressed()
{
    return gbIsMouseButtonPressed;
}

// 0x004FA470
int __stdcall D2Win_10033(D2WinControlStrc* a1, int a2)
{
    gpActiveControlList = a1;
    dword_6F8FE278 = a2;
    return 1;
}

// 0x004FA490
extern "C" __declspec(dllexport) unsigned int __stdcall CONTROL_GetType(Obj004FA490* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue00;
}

// 0x004FA4B0
int __cdecl CONTROL_GetActiveControlList()
{
    return gdwGlobal_007D55D4;
}

// 0x004FA4C0
void __stdcall D2Win_COMMANDS_NcMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam == 2)
    {
        gbDrawCursor = 0;
        WINDOW_ShowCursor(0);
    }
    else
    {
        gbDrawCursor = 0;
    }
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x004FA4F0
void __stdcall D2Win_COMMANDS_MouseLeave(SMSGHANDLER_PARAMS* pMsg)
{
    gbMouseTracking = 0;
    if (gnRenderMode != 4)
    {
        gbDrawCursor = 0;
    }
    WINDOW_ShowCursor(0);
    pMsg->bReturn = 0;
    pMsg->lResult = 0;
}

// 0x004FA520
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress)
{
    gnRenderMode = nRenderMode;
    D2CMPSetNoCompress(bCompress);
    return D2GFX_Initialize(hInstance, D2Win_MAINWINDOW_WndProc_6F8AD9B0, nRenderMode, bWindowed);
}

// 0x004FA550
int __fastcall D2Win_10016()
{
    gnWinCallbackDepth_007D55C4 = 0;
    CONTROL_FreeDeadList();
    LIST_UnloadPentspinCellfile();
    D2Win_10116();
    WREGISTER_UnregisterCommands(WINDOW_GetWindow(), gatCommandRegister, 0x21);
    return 1;
}

// 0x004FA590
int __stdcall D2Win_RunMessageLoop(void (__stdcall* pCallback)(unsigned long))
{
    unsigned long dwCounter = 0;
    unsigned long dwTickCount = GetTickCount();
    int nSleepMillis = 0;

    while (gbRunMessageLoop)
    {
        tagMSG tMsg;
        if (PeekMessageA(&tMsg, 0, 0, 0, 0))
        {
            gbRunMessageLoop = GetMessageA(&tMsg, 0, 0, 0);
            if (!gbRunMessageLoop && gpfnQuitCallback)
            {
                gpfnQuitCallback();
            }

            TranslateMessage(&tMsg);
            DispatchMessageA(&tMsg);
        }
        else
        {
            unsigned long dwTickDiff = GetTickCount() - dwTickCount;
            dwTickCount = GetTickCount();
            if (dwTickDiff > 1000)
            {
                dwTickDiff = 1000;
            }

            nSleepMillis -= dwTickDiff;
            if (nSleepMillis <= 0)
            {
                nSleepMillis += 40;
                if (nSleepMillis < -1000)
                {
                    nSleepMillis = 0;
                }

                if (pCallback)
                {
                    pCallback(dwCounter);
                    dwCounter += 1;
                }

                D2Win_UpdateAndDraw();
            }

            gpFocusedEditBox = gpNextFocusedEditBox;
            unsigned long dwSleepMillis = nSleepMillis;
            if (dwSleepMillis > 20)
            {
                dwSleepMillis = 20;
            }

            if (gbAppActive)
            {
                dwSleepMillis = 0;
            }

            Sleep(dwSleepMillis);
        }
    }

    D2Win_UpdateAndDraw();
    if (!gbCloseRequested)
    {
        gbRunMessageLoop = 1;
    }

    return 0;
}

// 0x004FA6B0
void __stdcall D2Win_COMMANDS_MouseMove_6F8AD670(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gbMouseTracking)
    {
        tagTRACKMOUSEEVENT tEventTrack;
        tEventTrack.cbSize = sizeof(tEventTrack);
        tEventTrack.dwFlags = 2;
        tEventTrack.hwndTrack = pMsg->hWnd;
        tEventTrack.dwHoverTime = 0;
        TrackMouseEvent(&tEventTrack);
        gbMouseTracking = 1;
    }

    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    gbDrawCursor = 1;
    WINDOW_ShowCursor(1);

    int nScreenWidth;
    int nScreenHeight;
    WINDOW_GetDimensions((int*)&nScreenWidth, (int*)&nScreenHeight);
    --nScreenWidth;
    --nScreenHeight;

    if (D2GFX_HardwareAcceleratedRenderMode())
    {
        int bSetCursorPos = 0;
        if (nX > nScreenWidth)
        {
            nX = nScreenWidth;
            bSetCursorPos = 1;
        }

        if (nY > nScreenHeight)
        {
            nY = nScreenHeight;
            bSetCursorPos = 1;
        }

        if (bSetCursorPos)
        {
            SetCursorPos(nX, nY);
        }
    }

    gtMousePosition.x = nX;
    gtMousePosition.y = nY;
}

// 0x004FA760
void __stdcall D2Win_COMMANDS_Escape_6F8ADB10(SMSGHANDLER_PARAMS* pMsg)
{
    if (gpEscapeButton && CONTROL_IsInActiveList(gpEscapeButton))
    {
        pMsg->hWnd = gpEscapeButton;
        BUTTON_SimulateClick(pMsg);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    D2Win_COMMANDS_VirtualKey_6F8ADB50(pMsg);
}

// 0x004FA7A0
void __stdcall D2Win_10168_WINMAIN_CreateScreenshot()
{
    const unsigned long dwTick = GetTickCount();
    if (dwTick - gdwLastScreenshotTick < 1000)
    {
        return;
    }

    int nWidth = 0;
    int nHeight = 0;
    WINDOW_GetDimensions((int*)&nWidth, (int*)&nHeight);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(nHeight * nWidth * 3, ".\\Src\\D2WinMain.cpp", 0x6A7, 0);
    if (D2GFX_GetBackBuffer(pBuffer))
    {
        D2Win_WriteScreenshotJpeg(pBuffer, 0, nWidth, nHeight);
    }

    gdwLastScreenshotTick = dwTick;
    FOG_Free(pBuffer, ".\\Src\\D2WinMain.cpp", 0x6B4, 0);
}

// 0x004FA840
void __stdcall D2Win_COMMANDS_Snapshot_6F8ADE70(SMSGHANDLER_PARAMS* pMsg)
{
    D2Win_10168_WINMAIN_CreateScreenshot();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x004FA860
void __stdcall D2Win_COMMANDS_MouseButton_6F8AE070(SMSGHANDLER_PARAMS* pMsg)
{
    D2Win_COMMANDS_MouseMove_6F8AD670(pMsg);
    if (POPUP_IsActive())
    {
        const int bInputHandled = POPUP_HandleMouseButtonInput(pMsg);
        POPUP_Destroy();
        if (bInputHandled)
        {
            return;
        }
    }

    D2WinControlStrc* pControl = gpActiveControlList;
    if (!pControl)
    {
        pControl = gpControlList;
    }

    switch (pMsg->uMessage)
    {
    case 0x201:
    case 0x204:
        gbIsMouseButtonPressed = 1;
        while (pControl)
        {
            if (pControl->pfShouldMouseInputBeHandled ? pControl->pfShouldMouseInputBeHandled(pControl) : CONTROL_IsMouseInside_004FA860(pControl))
            {
                pMsg->hWnd = pControl;
                if (pControl->pfHandleMouseDown)
                {
                    ++gnWinCallbackDepth;
                    const int nResult = pControl->pfHandleMouseDown(pMsg);
                    --gnWinCallbackDepth;
                    if (nResult)
                    {
                        break;
                    }
                }
            }
            pControl = pControl->pNext;
        }
        break;

    case 0x202:
    case 0x205:
        gbIsMouseButtonPressed = 0;
        while (pControl)
        {
            pMsg->hWnd = pControl;
            if (pControl->pfHandleMouseUp)
            {
                ++gnWinCallbackDepth;
                pControl->pfHandleMouseUp(pMsg);
                --gnWinCallbackDepth;
            }
            pControl = pControl->pNext;
        }
        break;
    }

    sub_00420290_BreakHandlerChain(pMsg);
}

int __fastcall SCROLLBAR_HandleMouseWheel(SMSGHANDLER_PARAMS* pMsg, D2WinScrollBarStrc* ptScrollbarData, int a3); // 0x00508030

#include "gen/data/Source/D2Win/Src/D2WinMain.inc"
