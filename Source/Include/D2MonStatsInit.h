#pragma once
// D2Common's monster stats for one level, as DATATBLS_CalculateMonsterStatsByLevel
// (0x006538A0) fills them: hit points, armor, to-hit, experience and damage.

#include "D2Check.h"

struct D2MonStatsInitStrc
{
    int nMinHP; // 0x00
    int nMaxHP; // 0x04
    int nAC; // 0x08
    int nTH; // 0x0C
    int nExp; // 0x10
    int nA1MinD; // 0x14
    int nA1MaxD; // 0x18
    int nA2MinD; // 0x1C
    int nA2MaxD; // 0x20
    int nS1MinD; // 0x24
    int nS1MaxD; // 0x28
    int nElMinD; // 0x2C
    int nElMaxD; // 0x30
    int nElDur; // 0x34
};
D2_CHECK_SIZE(D2MonStatsInitStrc, 0x38);
