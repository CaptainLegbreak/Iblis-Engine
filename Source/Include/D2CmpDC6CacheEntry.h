#pragma once
// D2CMP: a DC6 cache entry (its header at 0x20).

#include "D2Check.h"

struct D2CmpDC6CacheEntryStrc
{
    char unk0x00[0x20];
    D2CmpDC6HeaderStrc tHeader;
};
