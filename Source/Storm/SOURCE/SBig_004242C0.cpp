// This piece stays apart from SBig.cpp (a declaration difference). Mul (0x4242C0) reads each buffer's
// limb count through a copy of a one-member count struct (BigBuffer::IsUsed below); read directly, as
// SBig.cpp's shared types (Source/Include D2StormArrayA.h, D2StormBigBuffer.h) hold it, as a plain
// unsigned int, the function no longer matches, here or in SBig.cpp. Every function in SBig.cpp is
// built with the plain count.
#include "D2StormTypes.h"
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
                unsigned int nChunk = m_chunk ? m_chunk : sub_004210A0_CalcChunkSize(nCount);
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
    unsigned int Count() const
    {
        return m_count.n;
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
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int sub_00420DB0_InRange(unsigned int nIndex) const;
    int IsUsed(unsigned int nIndex) const
    {
        const D2StormCountStrc tCount = m_array.m_count;
        return nIndex + m_start < tCount.n;
    }                                                    // 0x00420DB0
    unsigned int operator[](unsigned int nIndex) const
    {
        return sub_00420DB0_InRange(nIndex) ? m_array.m_data[m_start + nIndex] : 0;
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
    void CopyFrom(const BigBuffer& tSource)
    {
        if (this != &tSource)
            m_array.sub_004215C0_Set(tSource.m_array.m_count.n, tSource.m_array.m_data);
        m_array.m_chunk = tSource.m_array.m_chunk;
        m_start = tSource.m_start;
    }
    unsigned int sub_004212D0_Get(unsigned int nIndex) const;                                               // 0x004212D0
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;

    BigBuffer& Alloc()
    {
        return pRecords[nUsed++];
    }
    void Free()
    {
        nUsed--;
    }
    BigBuffer& MakeDistinct(BigBuffer& tOrig, int bRequired)
    {
        return bRequired ? Alloc() : tOrig;
    }
    void UnmakeDistinct(BigBuffer& tOrig, BigBuffer& tDistinct)
    {
        if (&tOrig != &tDistinct)
        {
            tOrig.CopyFrom(tDistinct);
            Free();
        }
    }
};

// 0x004210A0
inline unsigned int D2StormArrayAStrc::sub_004210A0_CalcChunkSize(unsigned int nCount)
{
    unsigned int nResult = nCount;
    if (nCount < 0x40)
    {
        while (nResult & (nResult - 1))
            nResult &= nResult - 1;
        return nResult < 1 ? 1 : nResult;
    }
    m_chunk = 0x40;
    return 0x40;
}

// 0x00420DB0
inline int BigBuffer::sub_00420DB0_InRange(unsigned int nIndex) const
{
    return m_start + nIndex < m_array.m_count.n;
}

// 0x004212D0
inline unsigned int BigBuffer::sub_004212D0_Get(unsigned int nIndex) const
{
    return sub_00420DB0_InRange(nIndex) ? m_array.m_data[m_start + nIndex] : 0;
}

inline unsigned int ExtractLowPart(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    return nLow;
}

// 0x004242C0
void __stdcall Mul(BigBuffer* pResult, const BigBuffer* pB, const BigBuffer* pC, BigStack* pStack)
{
    BigBuffer& a = *pResult;
    const BigBuffer& b = *pB;
    const BigBuffer& c = *pC;
    BigBuffer& aa = pStack->MakeDistinct(a, &a == &b || &a == &c);

    aa.SetCount(0);

    int i = 0;
    for (; b.IsUsed(i); i++)
    {
        unsigned __int64 nData = 0;
        int j = 0;
        for (; c.IsUsed(j); j++)
        {
            nData += (unsigned __int64)b.sub_004212D0_Get(i) * c[j] + aa[i + j];
            aa[i + j] = ExtractLowPart(nData);
        }
        aa[i + j] = ExtractLowPart(nData);
    }

    if (&a != &aa)
    {
        D2StormArrayViewStrc tView;
        tView.pData = aa.m_array.m_data;
        tView.nCount = aa.m_array.m_count.n;
        a.m_array.sub_004215C0_Set(tView.nCount, tView.pData);
        a.m_array.m_chunk = aa.m_array.m_chunk;
        a.m_start = aa.m_start;
        pStack->nUsed--;
    }
}
