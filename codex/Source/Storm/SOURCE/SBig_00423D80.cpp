#include "Storm.h"
#include "D2StormTypes.h"

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

struct D2StormFixedArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;

    D2StormFixedArrayAStrc& operator=(const D2StormFixedArrayAStrc& tSource)
    {
        if (this != &tSource)
        {
            sub_004215C0_Set(tSource.m_count, tSource.m_data);
        }
        return *this;
    }
    void InlineReallocData(unsigned int nAlloc)
    {
        m_alloc = nAlloc;
        if (m_data || nAlloc)
            m_data = (unsigned int*)SMemReAlloc(m_data, nAlloc * sizeof(unsigned int), gszTypeNameUInt_00708874, -2, 0);
    }
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);
};

// 0x004215C0
void D2StormFixedArrayAStrc::sub_004215C0_Set(unsigned int nCount, const unsigned int* pData)
{
    InlineReallocData(nCount);
    for (unsigned int i = 0; i < nCount; i++, pData++)
        new (&m_data[i]) unsigned int(*pData);
    m_count = nCount;
}

#include "D2StormArrayA.h"

struct BigBuffer : D2StormArrayAStrc
{
    unsigned int m_start;
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;

    void sub_00423D80_Release(BigBuffer* pResult, BigBuffer* pWork);
};

// 0x00423D80
void BigStack::sub_00423D80_Release(BigBuffer* pResult, BigBuffer* pWork)
{
    if (pResult != pWork)
    {
        D2StormArrayViewStrc tView;
        tView.pData = pWork->m_data;
        tView.nCount = pWork->m_count;
        pResult->sub_004215C0_Set(tView.nCount, tView.pData);
        pResult->m_chunk = pWork->m_chunk;
        pResult->m_start = pWork->m_start;
        nUsed--;
    }
}
