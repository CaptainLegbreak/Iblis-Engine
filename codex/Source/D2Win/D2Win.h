#pragma once

struct D2ArchiveHandleStrc;
struct D2CelFileStrc;
struct D2CelStrc;
struct D2GfxDataStrc;
struct D2GrTexInfoStrc;
struct D2GraphicsInterfaceStrc;
struct D2PaletteTableStrc;
struct D2TxtLinkStrc;
struct D2WinScrollBarStrc;
struct SMSGHANDLER_PARAMS;
struct tagMSG;

D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine); // 0x006BD040
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
extern "C" __declspec(dllimport) int __stdcall PeekMessageA(tagMSG* pMsg, void* hWnd, unsigned int uMsgFilterMin, unsigned int uMsgFilterMax, unsigned int wRemoveMsg); // 0x006CC480
extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const tagMSG* pMsg); // 0x006CC47C
extern "C" __declspec(dllimport) long __stdcall DispatchMessageA(const tagMSG* pMsg); // 0x006CC478
extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C
extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
extern "C" const char gszCharsDir[]; // 0x006DCC34
extern "C" const char gszCofPathFormat[]; // 0x006D6C94
extern "C" const char gszD2CompSourceFile[]; // 0x006DCC20
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char gszMonstersDir[]; // 0x006D6CAC
extern "C" const char gszDataGlobal[]; // 0x006D4118
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" int __cdecl isspace(int c); // 0x00687006
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
extern "C" int __cdecl sub_00517ABB_BitScanForward1(unsigned int nValue); // 0x00517ABB
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __fastcall __security_check_cookie(unsigned int nCookie); // 0x00681A48
extern D2ArchiveHandleStrc* gpD2XVideoMPQ; // 0x007D562C
extern D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0
extern int gbDrawCursor; // 0x0072DC3C
extern int gbRunMessageLoop; // 0x0072DDD4
extern int gbRenderPaused; // 0x007C9144
extern int gnCurrentFont; // 0x0072DFFC
extern int gnDDrawGammaScale; // 0x0072F7C8
extern int gnDDrawGamma; // 0x0072F7CC
extern int gnResolutionMode_007C8CC4; // 0x007C8CC4
extern int ganRowOffsets[732]; // 0x007C97A8
extern int gnRenderWidth; // 0x007C9138
extern int ganSubtileRowSrcOffset[]; // 0x0072DBC0
extern int ganSubtileRowWidth[]; // 0x0072DB84
extern int ganSubtileRowXOffset[]; // 0x0072DB48
extern int gnTextBoxLineGap; // 0x0072DE90
extern int gnWinCallbackDepth_007D55C4; // 0x007D55C4
extern unsigned char gaDirectionIndex[][64]; // 0x006DCA60
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
extern unsigned int gadwComponentTokens[]; // 0x0072E108
extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern unsigned int gadwModeTokens[]; // 0x0072E0B8
extern unsigned int gadwUnitTokens[]; // 0x0072E050
extern unsigned int gadwWClassTokens[]; // 0x0072E15C
extern unsigned int gnModeTokens; // 0x0072E0B4
extern unsigned int gnUnitTokens; // 0x0072E04C
extern unsigned int gnWClassTokens; // 0x0072E198
extern void (__stdcall* gpfnGrTexDownloadMipMap)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EAB8
extern void (__stdcall* gpfnGrTexSource)(int nTmu, int nStartAddress, int nEvenOdd, D2GrTexInfoStrc* pInfo); // 0x0087EB98
int __cdecl FOG_UseDirect(); // 0x00406D20
int __cdecl FOG_IsExpansion(); // 0x00408F20
int __cdecl CONTROL_GetFocusedEditBox(); // 0x004F9200
int __cdecl D2Win_IsMouseButtonPressed(); // 0x004FA460
int __cdecl CONTROL_GetActiveControlList(); // 0x004FA4B0
int __cdecl sub_00525150(); // 0x00525150
int __fastcall SCROLLBAR_GetCurrentStep(D2WinScrollBarStrc* pScrollBar); // 0x00507FA0
int __fastcall SCROLLBAR_GetMaxSteps(D2WinScrollBarStrc* pScrollBar); // 0x00507EF0
int __fastcall FOG_FOpenFile(const char* szFileName, void** phFile); // 0x004068E0
int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650
int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10
int __stdcall WINDOW_GetState(); // 0x004F6070
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __stdcall sub_004FE710_EditBoxMouseDownAlt(SMSGHANDLER_PARAMS* pMsg); // 0x004FE710
int __stdcall sub_00504A20_CheckItemType(int nItemType, int nCheckType); // 0x00504A20
int __stdcall sub_006001F0(D2GfxDataStrc* pContext, int nArg2, int nArg3); // 0x006001F0
int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0
int __stdcall CelGetOffsetX(D2CelStrc* pCel); // 0x00601920
int __stdcall CelGetOffsetY(D2CelStrc* pCel); // 0x00601950
unsigned char __stdcall D2Win_10034_MixRGB(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
unsigned char* __fastcall D2COMP_GetComponentPalette(int nColor); // 0x005038D0
void __cdecl LOGMANAGER_WriteLogLine(const char* szFormat, ...); // 0x00410610
void __fastcall FOG_FCloseFile(void* hFile); // 0x004068F0
void __fastcall sub_004FAAE0_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0
void __fastcall D2Win_10176_StartPaletteFlash(int bActive); // 0x004FB130
void __stdcall D2GFX_SetPaletteTables(D2PaletteTableStrc* pPaletteTables); // 0x004F6410
void __stdcall sub_004F6540(D2GfxDataStrc* pContext, int nX, int nY); // 0x004F6540
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
void* __fastcall sub_00517079_LoadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020
void* __stdcall sub_004FAC80(); // 0x004FAC80

#define BUTTONFLAG_HAS_DISABLED_FRAMES 0x20
#define BUTTONFLAG_SUBTITLE 0x40
#define D2FONT_FONTEXOCET10 9
#define D2FONT_FONTRIDICULOUS 10
#define D2WIN_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2WIN_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))
#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define DRAWMODE_BURN 4
#define DRAWMODE_TRANS50 1

struct D2CropRectStrc
{
    int nX0;
    int nX1;
    int nY0;
    int nY1;
};

struct D2TileLibraryBlockStrc
{
    short nPosX;
    short nPosY;
    short unk0x04;
    unsigned char nGridX;
    unsigned char nGridY;
    unsigned char nFormat;
    char unk0x09[0x07];
    unsigned char* pData;
};

struct D2WinAccountListDataStrc
{
    char szText[50];
    short field_32;
    D2WinAccountListDataStrc* pNext;
};

#include "D2Win32Base.h"
