#pragma once
// Win32: the version information GetVersionExA fills (OSVERSIONINFOA), as the modules declare it for themselves.

#include "D2Check.h"

struct D2OsVersionInfoStrc
{
    unsigned long dwOSVersionInfoSize;
    unsigned long dwMajorVersion;
    unsigned long dwMinorVersion;
    unsigned long dwBuildNumber;
    unsigned long dwPlatformId;
    char szCSDVersion[128];
};
