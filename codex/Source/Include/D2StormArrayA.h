#pragma once
// Storm growable array of 32-bit limbs (the big-number buffer's storage).

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

struct D2StormArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            if (bRound)
            {
                unsigned int nChunk = m_chunk;
                if (!nChunk)
                    nChunk = sub_004210A0_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004216E0_ReallocData(nCount);
        }
    }
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
    unsigned int CalcChunkSizeInline(unsigned int nCount)
    {
        if (nCount < 0x40)
        {
            unsigned int nResult = nCount;
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        m_chunk = 0x40;
        return 0x40;
    }
    void GrowToFitInline(unsigned int nIndex)
    {
        if (nIndex < m_count)
            return;
        unsigned int nCount = nIndex + 1;
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : CalcChunkSizeInline(nCount);
            sub_004216E0_ReallocData(RoundUp(nCount, nChunk));
        }
        SMemZero(&m_data[m_count], (nIndex - m_count + 1) * sizeof(unsigned int));
        m_count = nIndex + 1;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
    unsigned int* sub_00420FE0_Top();                                                                       // 0x00420FE0
};
