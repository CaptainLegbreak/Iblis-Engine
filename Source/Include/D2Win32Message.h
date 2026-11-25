#pragma once
// Win32: the message record GetMessage and PeekMessage fill (window, message, the two parameters, the time
// and the cursor point), as the modules declare it for themselves.

#include "D2Check.h"

struct D2WinMsgStrc
{
    void* hWnd; // 0x00
    unsigned int uMessage; // 0x04
    unsigned int wParam; // 0x08
    int lParam; // 0x0C
    unsigned int dwTime; // 0x10
    int nPointX; // 0x14
    int nPointY; // 0x18
};
