#pragma once
// Data tables: the sets.txt record (set bonuses and the set's items).

#include "D2Check.h"
#include "D2Records.h"

struct D2SetsTxt
{
    unsigned short wSetId; // 0x00
    unsigned short wStringId; // 0x02
    unsigned short wVersion; // 0x04
    unsigned short pad0x06; // 0x06
    int unused0x08; // 0x08
    int nSetItems; // 0x0C
    D2PropertyStrc pBoni2[8]; // 0x10
    D2PropertyStrc pFBoni[8]; // 0x90
    D2SetItemsTxt* pSetItem[6]; // 0x110
};

D2_CHECK_SIZE(D2SetsTxt, 0x128);
