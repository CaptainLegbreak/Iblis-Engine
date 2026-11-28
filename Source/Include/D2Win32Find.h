#pragma once
// Win32: the file search record FindFirstFileA and FindNextFileA fill (WIN32_FIND_DATAA).

#include "D2Win32Base.h"

struct D2FindDataStrc
{
    unsigned long dwFileAttributes; // 0x00
    D2FileTimeStrc ftCreationTime; // 0x04
    D2FileTimeStrc ftLastAccessTime; // 0x0C
    D2FileTimeStrc ftLastWriteTime; // 0x14
    unsigned long nFileSizeHigh; // 0x1C
    unsigned long nFileSizeLow; // 0x20
    unsigned long dwReserved0; // 0x24
    unsigned long dwReserved1; // 0x28
    char cFileName[260]; // 0x2C
    char cAlternateFileName[14]; // 0x130
};
