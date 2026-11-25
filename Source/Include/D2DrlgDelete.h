#pragma once
// Dungeon: the pending unit deletion node (unit type and GUID) an active room keeps in pDrlgDelete.

#include "D2Check.h"

struct D2DrlgDeleteStrc
{
    int nUnitType; // 0x00
    int nUnitGUID; // 0x04
    D2DrlgDeleteStrc* pNext; // 0x08
};
