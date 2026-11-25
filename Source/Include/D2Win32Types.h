#pragma once
// Win32: the window, message, palette and time records the game modules declare for themselves.

#include "D2Win32Base.h"

struct tagPALETTEENTRY;
struct tagMSG;
struct WNDCLASSA;
struct tagWINDOWPLACEMENT;
struct tagTRACKMOUSEEVENT;
struct tagMONITORINFO;
struct _FILETIME;
struct D2SystemTimeStrc;

struct tagPALETTEENTRY
{
    unsigned char peRed; // 0x00
    unsigned char peGreen; // 0x01
    unsigned char peBlue; // 0x02
    unsigned char peFlags; // 0x03
};

struct tagMSG
{
    void* hwnd; // 0x00
    unsigned int message; // 0x04
    unsigned int wParam; // 0x08
    long lParam; // 0x0C
    unsigned long time; // 0x10
    tagPOINT pt; // 0x14
};

struct WNDCLASSA
{
    unsigned int style; // 0x00
    long (__stdcall* lpfnWndProc)(void*, unsigned int, unsigned int, long); // 0x04
    int cbClsExtra; // 0x08
    int cbWndExtra; // 0x0C
    void* hInstance; // 0x10
    void* hIcon; // 0x14
    void* hCursor; // 0x18
    void* hbrBackground; // 0x1C
    const char* lpszMenuName; // 0x20
    const char* lpszClassName; // 0x24
};

struct tagWINDOWPLACEMENT
{
    unsigned int length; // 0x00
    unsigned int flags; // 0x04
    unsigned int showCmd; // 0x08
    tagPOINT ptMinPosition; // 0x0C
    tagPOINT ptMaxPosition; // 0x14
    tagRECT rcNormalPosition; // 0x1C
};

struct tagTRACKMOUSEEVENT
{
    unsigned long cbSize; // 0x00
    unsigned long dwFlags; // 0x04
    void* hwndTrack; // 0x08
    unsigned long dwHoverTime; // 0x0C
};

struct tagMONITORINFO
{
    unsigned long cbSize; // 0x00
    tagRECT rcMonitor; // 0x04
    tagRECT rcWork; // 0x14
    unsigned long dwFlags; // 0x24
};

struct _FILETIME
{
    unsigned long dwLowDateTime; // 0x00
    unsigned long dwHighDateTime; // 0x04
};

struct D2SystemTimeStrc
{
    unsigned short wYear; // 0x00
    unsigned short wMonth; // 0x02
    unsigned short wDayOfWeek; // 0x04
    unsigned short wDay; // 0x06
    unsigned short wHour; // 0x08
    unsigned short wMinute; // 0x0A
    unsigned short wSecond; // 0x0C
    unsigned short wMilliseconds; // 0x0E
};
