#pragma once
// D2CMP tile-pool LRU node (the pool hands one out per loaded block).

#include "D2Check.h"

struct D2LRUNodeStrc
{
    void* pData; // 0x00
    unsigned int nSize; // 0x04
    unsigned int nCost; // 0x08
    D2LRUNodeStrc* pNext; // 0x0C
    D2LRUNodeStrc* pPrev; // 0x10
};

D2_CHECK_SIZE(D2LRUNodeStrc, 0x14);
