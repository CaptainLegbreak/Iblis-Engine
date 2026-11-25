#pragma once
// Client graphics: a unit's state overlay node (its overlay, the overlay and state that follow it, the
// animation frame, the delay before it repeats, the light it holds) and the unit gfx data whose list
// starts at +0x2C.

#include "D2Check.h"

struct D2StateNodeStrc
{
    int dwType; // 0x00
    int unk0x04; // 0x04
    int nCurrent; // 0x08
    int nNextOverlay; // 0x0C
    int nNextState; // 0x10
    int nSpeed; // 0x14
    int nFrame; // 0x18
    int nFrames; // 0x1C
    char unk0x20[0x08]; // 0x20
    unsigned int dwDelay; // 0x28
    unsigned int dwStamp; // 0x2C
    unsigned int dwDelayStart; // 0x30
    char unk0x34[0x04]; // 0x34
    int nStateId; // 0x38
    int bSelected; // 0x3C
    void* pResource; // 0x40
    char unk0x44[0x60]; // 0x44
    D2StateNodeStrc* pNext; // 0xA4
};

struct D2StateOwnerStrc
{
    char unk0x00[0x2C]; // 0x00
    D2StateNodeStrc* pFirst; // 0x2C
};
