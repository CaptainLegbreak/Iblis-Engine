#pragma once
// Animation data records: frame count, speed and per-frame event flags of a unit animation

#include "D2Check.h"
#include "D2Structs.h"

struct D2AnimDataRecordStrc;

struct D2AnimDataRecordStrc
{
    char szAnimDataName[8]; // 0x00
    unsigned int dwFrames; // 0x08
    unsigned int dwAnimSpeed; // 0x0C
    unsigned char pFrameFlags[144]; // 0x10
};

struct D2AnimSeqTxt
{
    short wSequence; // 0x00
    unsigned char nMode; // 0x02
    unsigned char nFrame; // 0x03
    unsigned char nDir; // 0x04
    unsigned char nEvent; // 0x05
};

D2_CHECK_SIZE(D2AnimDataRecordStrc, 0xA0);

struct D2AnimSeqTxt;

struct D2AnimSeqRecordStrc
{
    D2AnimSeqTxt* pAnimSeqTxtRecord; // 0x00
    int nSeqFramesCount; // 0x04
    int nFramesCount; // 0x08
};

D2_CHECK_SIZE(D2AnimSeqRecordStrc, 0xC);
