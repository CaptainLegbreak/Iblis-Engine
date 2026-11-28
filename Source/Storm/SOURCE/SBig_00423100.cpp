// This piece stays apart from SBig.cpp (a declaration difference). sub_00423100_Sub reads each buffer's
// limb count through a copy of a one-member count struct (BigBuffer::IsUsed below), and that copy is what
// keeps one of the counts in a stack slot as the original does. SBig.cpp's types (Source/Include
// D2StormArrayA.h, D2StormBigBuffer.h) hold the count as a plain unsigned int, which every function in
// SBig.cpp needs; with them this function comes out 324 bytes for the original's 330.
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

struct D2StormCountStrc
{
    unsigned int n;
};

struct D2StormArrayAStrc
{
    unsigned int m_alloc;
    D2StormCountStrc m_count;
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
        nCount += m_count.n;
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
        if (nCount > m_count.n)
            Reserve(nCount - m_count.n, 1);
        m_count.n = nCount;
    }
    void GrowToFit(unsigned int nIndex, int bZero)
    {
        if (nIndex < m_count.n)
            return;
        Reserve(nIndex - m_count.n + 1, 1);
        if (bZero)
            SMemZero(&m_data[m_count.n], (nIndex - m_count.n + 1) * sizeof(unsigned int));
        m_count.n = nIndex + 1;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int IsUsed(unsigned int nIndex) const
    {
        const D2StormCountStrc tCount = m_array.m_count;
        return nIndex + m_start < tCount.n;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.m_count.n ? m_array.m_data[m_start + nIndex] : 0;
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
};

struct D2StormBigStrc
{
    BigBuffer tPrimary;
    char unk0x14[0x154];
};

inline unsigned int ExtractLowPartSx(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    if (nValue >= 0x80000000)
        nValue |= 0xFFFFFFFF00000000ui64;
    return nLow;
}

// 0x00423100
static void __stdcall sub_00423100_Sub(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned __int64 nBorrow = 0;
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        nBorrow += (unsigned __int64)b[i] - c[i];
        a[i] = ExtractLowPartSx(nBorrow);
    }
    a.SetCount(i);
}

// 0x00423AC0
void __stdcall SBigSub(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00423100_Sub(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}
