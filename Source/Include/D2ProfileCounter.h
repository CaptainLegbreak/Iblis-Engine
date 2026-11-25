#pragma once
// D2Common logging: a named profiling counter (name, total, count), the record of ProfCore's gaProfEntries.

#include "D2Check.h"

struct D2ProfileCounterStrc
{
    char szName[0x68]; // 0x00
    __int64 nTotal; // 0x68
    int nCount; // 0x70
    int f_74; // 0x74
};
