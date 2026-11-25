#pragma once
// D2CMP: CelDataHash.cpp's name hash: 0x200 buckets of entries keyed by a name hash, each holding the
// name, the caller's value and the bucket's links.

#include "D2Check.h"

struct D2CelDataHashEntryStrc
{
    unsigned int nKey; // 0x00
    char szName[0x20]; // 0x04
    int nValue; // 0x24
    D2CelDataHashEntryStrc* pPrev; // 0x28
    D2CelDataHashEntryStrc* pNext; // 0x2C
};

struct D2CelDataHashStrc
{
    int nCheck[0x200]; // 0x0000
    D2CelDataHashEntryStrc* pBuckets[0x200]; // 0x0800
};
