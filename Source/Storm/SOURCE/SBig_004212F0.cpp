#include "Storm.h"
#include "D2StormArrayA.h"

struct D2StormArrayAStrc;
struct D2StormArrayCStrc;
struct BigBuffer;
struct D2StormFixedArrayAStrc;
struct D2StormArrayBStrc;

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct D2StormArrayCStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    char* m_data;
    unsigned int m_chunk;

    void sub_00421770_ReallocData(unsigned int nAlloc);
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;
    void GrowToFit(int nIndex); // 0x00421FE0

    unsigned int Count() const
    {
        return m_array.m_count - m_start;
    }
    int IsUsed(unsigned int nIndex) const
    {
        return nIndex + m_start < m_array.m_count;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        return IsUsed(nIndex) ? m_array.m_data[m_start + nIndex] : 0;
    }
    void sub_00422140_Trim();
};

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

struct D2StormFixedArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;

    void InlineReallocData(unsigned int nAlloc)
    {
        m_alloc = nAlloc;
        if (m_data || nAlloc)
            m_data = (unsigned int*)SMemReAlloc(m_data, nAlloc * sizeof(unsigned int), gszTypeNameUInt_00708874, -2, 0);
    }
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);
};

struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    void InlineReserve(unsigned int nCount, int bRound)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            if (bRound)
            {
                unsigned int nChunk = m_chunk ? m_chunk : sub_00421160_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004211C0_ReallocData(nCount);
        }
    }
    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);
};

inline void* operator new(unsigned int, void* pWhere) throw();

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

// 0x004212F0
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight)
{
    int nResult = 0;
    for (unsigned int i = 0; pLeft->IsUsed(i) || pRight->IsUsed(i); ++i)
    {
        if ((*pLeft)[i] != (*pRight)[i])
            nResult = (*pLeft)[i] > (*pRight)[i] ? 1 : -1;
    }
    return nResult;
}

// 0x00422140
void BigBuffer::sub_00422140_Trim()
{
    while (Count())
    {
        if (*m_array.sub_00420FE0_Top())
            break;
        m_array.SetCount(m_array.m_count - 1);
    }
}

#include "gen/data/Source/Storm/SOURCE/SBig_004212F0.inc"

// 0x00421FE0
void BigBuffer::GrowToFit(int nIndex)
{
    unsigned int nPosition = m_start + nIndex;
    if (nPosition >= m_array.m_count)
    {
        unsigned int nNewCount = nPosition + 1;
        if (nNewCount > m_array.m_alloc)
        {
            unsigned int nChunk = m_array.m_chunk ? m_array.m_chunk : m_array.sub_004210A0_CalcChunkSize(nNewCount);
            m_array.sub_004216E0_ReallocData(D2StormArrayAStrc::RoundUp(nNewCount, nChunk));
        }
        SMemZero(&m_array.m_data[m_array.m_count], (nPosition - m_array.m_count + 1) * sizeof(unsigned int));
        m_array.m_count = nNewCount;
    }
}
