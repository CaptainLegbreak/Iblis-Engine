#pragma once
// Storm big-number buffer: a growable array of 32-bit limbs plus a start offset.

#include "D2StormTypes.h"
#include "D2StormArrayA.h"
#include "stpl.h"

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    BigBuffer() : m_start(0)
    {
    }
    unsigned int Count() const
    {
        return m_array.Count() - m_start;
    }
    int IsUsed(unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.m_count;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.m_data[m_start + nIndex] : 0;
    }
    __forceinline unsigned int& operator[](unsigned int nIndex)
    {
        m_array.GrowToFit(m_start + nIndex, 1);
        return m_array.m_data[m_start + nIndex];
    }
    void SetCount(unsigned int nCount)
    {
        m_array.SetCount(m_start + nCount);
    }
    void SetCountInline(unsigned int nCount)
    {
        m_array.SetCountInline(m_start + nCount);
    }
    BigBuffer& operator=(const BigBuffer& tSource)
    {
        if (this != &tSource)
        {
            m_array.Set(tSource.m_array.m_count, tSource.m_array.m_data);
        }
        m_array.m_chunk = tSource.m_array.m_chunk;
        m_start = tSource.m_start;
        return *this;
    }
    void CopyFrom(const BigBuffer& tSource)
    {
        if (this != &tSource)
        {
            D2StormArrayViewStrc tView;
            tView.pData = tSource.m_array.m_data;
            tView.nCount = tSource.m_array.m_count;
            m_array.Set(tView.nCount, tView.pData);
        }
        m_array.m_chunk = tSource.m_array.m_chunk;
        m_start = tSource.m_start;
    }
    unsigned int& Ref(int nIndex)
    {
        GrowToFit(nIndex);
        return m_array.m_data[m_start + nIndex];
    }
    inline unsigned int& At(unsigned int nIndex)
    {
        m_array.GrowToFitInline(m_start + nIndex);
        return m_array.m_data[m_start + nIndex];
    }
    void SetStart(unsigned int nStart)
    {
        m_start = nStart;
        if (nStart)
            GrowToFit(-1);
    }
    void GrowToFit(int nIndex);                                                                // 0x00421FE0
    void sub_004220D0_SetCount(unsigned int nCount);                                                        // 0x004220D0
    void sub_00422140_Trim();                                                                               // 0x00422140
    unsigned int sub_004212D0_Get(unsigned int nIndex);                                                      // 0x004212D0
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;

    BigStack() : nUsed(0)
    {
    }

    void sub_00423D80_Release(BigBuffer* pResult, BigBuffer* pWork);                                        // 0x00423D80
};
