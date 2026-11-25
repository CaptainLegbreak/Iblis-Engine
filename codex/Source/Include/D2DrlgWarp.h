#pragma once
// D2Common: a level's warp list entry (D2DrlgStrc+0x90 is the head): the level id, the vis and warp
// ids, the next entry.

#include "D2Check.h"

struct D2DrlgWarpStrc
{
    int nLevel; // 0x00
    int nVis[8]; // 0x04
    int nWarp[8]; // 0x24
    D2DrlgWarpStrc* pNext; // 0x44
};
