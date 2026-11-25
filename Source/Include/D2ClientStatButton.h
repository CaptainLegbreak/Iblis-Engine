#pragma once
// Client: one of the four buttons in gaStatButtons (position, active flag and a 16-bit value).

#include "D2Check.h"

#pragma pack(push, 2)
struct D2BeltSlotStrc
{
    int nX; // 0x00
    int nY; // 0x04
    int bActive; // 0x08
    unsigned short wCode; // 0x0C
};
#pragma pack(pop)
