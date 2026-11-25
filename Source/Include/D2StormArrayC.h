#pragma once
// Storm growable array of bytes (the big-number code's byte buffer): capacity, count, elements, chunk.

#include "D2Check.h"

struct D2StormArrayCStrc
{
    unsigned int m_alloc; // 0x00
    unsigned int m_count; // 0x04
    char* m_data; // 0x08
    unsigned int m_chunk; // 0x0C

    void sub_00421A50_Set(unsigned int nCount, const char* pData);                                          // 0x00421A50
    unsigned int sub_00421F60_Add(unsigned int nCount, const char* pData);                                  // 0x00421F60
};
