#pragma once
// Client graphics: a unit's state overlay node (its overlay, the overlay and state that follow it, the
// animation frame, the delay before it repeats, the light it holds) and the unit gfx data whose list
// starts at +0x2C.

#include "D2Check.h"

struct D2StateNodeStrc
{
    int dwType; // 0x00
    int unused0x04; // 0x04
    int nCurrent; // 0x08
    int nNextOverlay; // 0x0C
    int nNextState; // 0x10
    int nSpeed; // 0x14
    int nFrame; // 0x18
    int nFrames; // 0x1C
    char unused0x20[8]; // 0x20
    unsigned int dwDelay; // 0x28
    unsigned int dwStamp; // 0x2C
    unsigned int dwDelayStart; // 0x30
    char unused0x34[4]; // 0x34
    int nStateId; // 0x38
    int bSelected; // 0x3C
    void* pResource; // 0x40
    char unused0x44[96]; // 0x44
    D2StateNodeStrc* pNext; // 0xA4
};

struct D2StateOwnerStrc
{
    char unused0x00[44]; // 0x00
    D2StateNodeStrc* pFirst; // 0x2C
};
