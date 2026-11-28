#pragma once
// A launcher thread record with its size in front, as MainMenus.cpp and ChatDlg.cpp queue it.

#include "D2LaunchThreadRecord.h"

struct D2LaunchPayloadStrc
{
    unsigned int nSize; // 0x00
    D2LaunchThreadRecordStrc tRecord; // 0x04
};
