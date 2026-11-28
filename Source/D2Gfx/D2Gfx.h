#pragma once

#include "D2GfxTypes.h"

struct tagRECT;

extern "C" __declspec(dllimport) int __stdcall AdjustWindowRectEx(tagRECT* lpRect, unsigned long dwStyle, int bMenu, unsigned long dwExStyle); // 0x006CC4FC
extern "C" __declspec(dllimport) int __stdcall DestroyWindow(void* hWnd); // 0x006CC4E0
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void* hWnd, tagRECT* lpRect); // 0x006CC4F8
extern "C" __declspec(dllimport) int __stdcall SetWindowPos(void* hWnd, void* hWndInsertAfter, int X, int Y, int cx, int cy, unsigned int uFlags); // 0x006CC4DC
extern "C" __declspec(dllimport) int __stdcall ShowCursor(int bShow); // 0x006CC4D8
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void* hWnd, int nCmdShow); // 0x006CC4EC
extern "C" __declspec(dllimport) long __stdcall ChangeDisplaySettingsA(void* lpDevMode, unsigned long dwFlags); // 0x006CC4F4
extern "C" __declspec(dllimport) unsigned long __stdcall GetLastError(); // 0x006CC1B4
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern int gnDisplayType; // 0x007C8CB0
extern void* ghInstance; // 0x007C8CA8
void __cdecl WINDOW_LoadGammaSettings(); // 0x004F8EA0

#include "D2GfxInterface.h"

extern D2GraphicsInterfaceStrc* gpGraphicsInterface; // 0x007C8CC0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#include "D2Win32Types.h"

struct D2WindowPlacementStrc
{
    void* hWnd;
    tagWINDOWPLACEMENT windowPlacement;
};

// Moved from D2Win.h (used by D2Gfx units).
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
