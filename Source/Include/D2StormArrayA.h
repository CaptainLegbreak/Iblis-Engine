#pragma once
// Storm growable array of 32-bit limbs (the big-number buffer's storage): TSGrowableArray<unsigned int> with the
// big-number code's own count and grow helpers, whose inline forms its callers need.

void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
#include "stpl.h"

struct D2StormArrayAStrc : TSGrowableArray<unsigned int>
{
    void SetCount(unsigned int nCount)
    {
        if (nCount > m_count)
            Reserve(nCount - m_count, 1);
        m_count = nCount;
    }
    void GrowToFit(unsigned int nIndex, int bZero)
    {
        if (nIndex < m_count)
            return;
        Reserve(nIndex - m_count + 1, 1);
        if (bZero)
            SMemZero(&m_data[m_count], (nIndex - m_count + 1) * sizeof(unsigned int));
        m_count = nIndex + 1;
    }
    void ReserveInline(unsigned int nCount)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : CalcChunkSize(nCount);
            ReallocData(RoundUp(nCount, nChunk));
        }
    }
    void SetCountInline(unsigned int nCount)
    {
        if (nCount > m_count)
            ReserveInline(nCount - m_count);
        m_count = nCount;
    }
    void GrowToFitInline(unsigned int nIndex)
    {
        if (nIndex < m_count)
            return;
        unsigned int nCount = nIndex + 1;
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : CalcChunkSize(nCount);
            ReallocData(RoundUp(nCount, nChunk));
        }
        SMemZero(&m_data[m_count], (nIndex - m_count + 1) * sizeof(unsigned int));
        m_count = nIndex + 1;
    }
    unsigned int* sub_00420FE0_Top();                                                                       // 0x00420FE0
};
