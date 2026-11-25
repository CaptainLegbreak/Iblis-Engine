#pragma once
// Client: the scrolling text panel (up to 128 lines of six 1024-character strings) and its line.

#include "D2Check.h"
#include "D2Unicode.h"

struct D2TextPanelLineStrc
{
    unsigned short unk0x00[4];
    Unicode wszText[6][0x400];
    unsigned short unk0x3008[3];
};

struct D2TextPanelStrc
{
    D2TextPanelLineStrc pLines[128];
    int unk0x180700[5];
    int nHeight;
    int unk0x180718[6];
    int nFirstLine;
    int unk0x180734[5];
    unsigned short nLineCount;
    unsigned short unk0x18074A[14];
    unsigned char nLineStep[4];
    unsigned char nLineGap[4];
};
