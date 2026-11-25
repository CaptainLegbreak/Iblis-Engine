#pragma once
// Client: the window messages the input recorder saves and plays back, in chunks of 500.

#include "D2Check.h"

struct D2MsgRecordStrc
{
    int nTick; // 0x00
    unsigned int uMessage; // 0x04
    unsigned int wParam; // 0x08
    int lParam; // 0x0C
};

struct D2MsgRecordChunkStrc
{
    D2MsgRecordStrc tRecords[500]; // 0x0000
    int nCount; // 0x1F40
    int nIndex; // 0x1F44
    D2MsgRecordChunkStrc* pNext; // 0x1F48
};

D2_CHECK_SIZE(D2MsgRecordStrc, 0x10);
D2_CHECK_SIZE(D2MsgRecordChunkStrc, 0x1F4C);
