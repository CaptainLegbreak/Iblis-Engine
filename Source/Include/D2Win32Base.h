#pragma once
// Win32: the point, rectangle and file time records the game modules declare for themselves.

struct tagPOINT
{
    long x; // 0x00
    long y; // 0x04
};

struct tagRECT
{
    long left; // 0x00
    long top; // 0x04
    long right; // 0x08
    long bottom; // 0x0C
};

struct D2FileTimeStrc
{
    unsigned long dwLowDateTime; // 0x00
    unsigned long dwHighDateTime; // 0x04
};
