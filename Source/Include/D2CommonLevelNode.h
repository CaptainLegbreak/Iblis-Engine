#pragma once
// D2Common: a node of the level tree the room activation and dungeon code walk (children, per-level counts).

#include "D2Check.h"

struct D2CommonLevelNodeStrc
{
    char unused0x00[0x8];
    D2CommonLevelNodeStrc** ppChildren;
    unsigned short wLevelCounts[16];
    int nChildren;
    char unused0x30[0x14];
    unsigned char nMaxLevel;
};
