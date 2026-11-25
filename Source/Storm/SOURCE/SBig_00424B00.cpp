#include "Storm.h"
#include "D2StormTypes.h"
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                    // 0x0041D300

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

    unsigned int Count() const
    {
        return m_count.n;
    }
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                            // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                   // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                      // 0x004216E0
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int sub_004212D0_Get(unsigned int nIndex);                                                      // 0x004212D0

    int IsUsed(unsigned int nIndex) const
    {
        const D2StormCountStrc tCount = m_array.m_count;
        return nIndex + m_start < tCount.n;
    }
    unsigned int GetInline(unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.m_data[m_start + nIndex] : 0;
    }
    void SetCountInline(unsigned int nCount)
    {
        if (nCount > m_array.m_count.n && nCount > m_array.m_alloc)
        {
            unsigned int nChunk = m_array.m_chunk;
            if (!nChunk)
                nChunk = m_array.sub_004210A0_CalcChunkSize(nCount);
            m_array.sub_004216E0_ReallocData(D2StormArrayAStrc::RoundUp(nCount, nChunk));
        }
        m_array.m_count.n = nCount;
    }
    unsigned int ChunkSizeInline(unsigned int nCount)
    {
        unsigned int nResult = nCount;
        if (nCount < 0x40)
        {
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        m_array.m_chunk = 0x40;
        return 0x40;
    }
    void GrowToFitInline(unsigned int nPosition)
    {
        if (nPosition < m_array.m_count.n)
            return;
        const unsigned int nNewCount = nPosition + 1;
        if (nNewCount > m_array.m_alloc)
        {
            const unsigned int nChunk = m_array.m_chunk ? m_array.m_chunk : ChunkSizeInline(nNewCount);
            m_array.sub_004216E0_ReallocData(D2StormArrayAStrc::RoundUp(nNewCount, nChunk));
        }
        SMemZero(&m_array.m_data[m_array.m_count.n], (nPosition - m_array.m_count.n + 1) * sizeof(unsigned int));
        m_array.m_count.n = nPosition + 1;
    }
    inline unsigned int& AtInline(unsigned int nIndex)
    {
        GrowToFitInline(m_start + nIndex);
        return m_array.m_data[m_start + nIndex];
    }
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;
};

// 0x00420EB0
static unsigned int __stdcall sub_00420EB0_AddWithCarry(unsigned __int64 nValue, unsigned __int64* pAccumulator)
{
    *pAccumulator += nValue;
    const unsigned __int64 nCarry = *pAccumulator < nValue ? 1ui64 : 0ui64;
    const unsigned int nLow = (unsigned int)*pAccumulator;
    *pAccumulator >>= 32;
    *pAccumulator += nCarry * 0x100000000ui64;
    return nLow;
}

// 0x00424B00
void __stdcall sub_00424B00_BigSquare(BigBuffer* pResult, BigBuffer* pA, BigStack* pStack)
{
    BigBuffer* pWork;
    if (pResult == pA)
    {
        // the work stack holds 16 buffers
        SASSERT(pStack->nUsed < 16);
        pWork = &pStack->pRecords[pStack->nUsed++];
    }
    else
        pWork = pResult;

    pWork->SetCountInline(pWork->m_start);

    for (unsigned int i = 0; pA->IsUsed(i); i++)
    {
        unsigned __int64 nCarry = 0;
        unsigned int j;
        for (j = 0; j <= i; j++)
        {
            const unsigned int nDigit = pA->GetInline(j);
            const unsigned __int64 nProduct = (unsigned __int64)pA->sub_004212D0_Get(i) * nDigit;
            const unsigned int k = i + j;
            const unsigned __int64 nSum = pWork->AtInline(i + j) + nProduct;
            if (j < i)
                nCarry += nProduct;
            pWork->AtInline(k) = sub_00420EB0_AddWithCarry(nSum, &nCarry);
        }
        pWork->AtInline(j + i) = (unsigned int)nCarry;
    }

    if (pResult != pWork)
    {
        pResult->m_array.sub_004215C0_Set(pWork->m_array.m_count.n, pWork->m_array.m_data);
        pResult->m_array.m_chunk = pWork->m_array.m_chunk;
        pResult->m_start = pWork->m_start;
        SASSERT(1 <= pStack->nUsed);
        pStack->nUsed--;
    }
}
