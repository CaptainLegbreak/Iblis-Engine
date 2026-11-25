#pragma once
// Storm growable array of list heads: a hash table's slot lists (TSHashTable::m_slotlistarray), capacity, count,
// elements, chunk.

#include "D2Check.h"

struct D2StormListAStrc;

struct D2StormListArrayStrc
{
    unsigned int m_alloc; // 0x00
    unsigned int m_count; // 0x04
    D2StormListAStrc* m_data; // 0x08
    unsigned int m_chunk; // 0x0C
};
