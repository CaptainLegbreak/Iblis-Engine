#include "Storm.h"
inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

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
                unsigned int nChunk = m_chunk ? m_chunk : sub_004210A0_CalcChunkSize(nCount);
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
            while (nCount & (nCount - 1))
                nCount &= nCount - 1;
            return nCount < 1 ? 1 : nCount;
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
    unsigned int CalcChunkSize(unsigned int nCount)
    {
        if (nCount < 0x100)
        {
            unsigned int nResult = nCount;
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        m_chunk = 0x100;
        return 0x100;
    }
    void Reserve(unsigned int nCount, int bRound)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            if (bRound)
            {
                unsigned int nChunk = m_chunk ? m_chunk : CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004211C0_ReallocData(nCount);
        }
    }
    void Add(unsigned int nCount, const unsigned char* pData)
    {
        Reserve(nCount, 1);
        for (unsigned int i = 0; i < nCount; i++, pData++)
            new (&m_data[m_count + i]) unsigned char(*pData);
        m_count += nCount;
    }
    unsigned char* New()
    {
        Reserve(1, 1);
        return &m_data[m_count++];
    }
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

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
            m_array.sub_004215C0_Set(tSource.m_array.m_count, tSource.m_array.m_data);
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
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;
};

struct D2StormBigStrc
{
    BigBuffer tPrimary;
    BigStack tStack;
    D2StormArrayBStrc tOutput;
};

unsigned int __stdcall BigHighBitIndex(BigBuffer* pQueue);                              // 0x004213B0
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight);                      // 0x004212F0

inline unsigned int ExtractLowPart(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    return nLow;
}

inline unsigned int ExtractLowPartSx(unsigned __int64& nValue)
{
    unsigned int nLow = (unsigned int)nValue;
    nValue >>= 32;
    if (nValue >= 0x80000000)
        nValue |= 0xFFFFFFFF00000000ui64;
    return nLow;
}

// 0x004225C0
static void __stdcall sub_004225C0_DivUInt(unsigned int* pRemainder, const BigBuffer& b, unsigned __int64 c, BigBuffer& a)
{
    a.m_array.SetCount((int)a.m_start - (int)b.m_start + b.m_array.m_count);
    unsigned __int64 nData = 0;
    unsigned int i = b.Count();
    while (i)
    {
        --i;
        nData = nData * 0x100000000ui64 + b[i];
        a[i] = (unsigned int)(nData / c);
        nData %= c;
    }
    a.sub_00422140_Trim();
    *pRemainder = (unsigned int)nData;
}

// 0x004227A0
static void __stdcall BigMulUInt(BigBuffer& a, const BigBuffer& b, unsigned __int64 c)
{
    unsigned __int64 nCarry = 0;
    unsigned int i = 0;
    for (; nCarry || b.IsUsed(i); i++)
    {
        nCarry += b[i] * c;
        a[i] = ExtractLowPart(nCarry);
    }
    a.SetCount(i);
}

static void SetZero(BigBuffer& a);
// 0x00422CC0
static void SetZero(BigBuffer& a)
{
    a.SetCount(0);
}

static void __stdcall Shl(BigBuffer& a, const BigBuffer& b, unsigned int nShift) // 0x00422D00
{
    unsigned int nWords = nShift / 32;
    unsigned int nBits = nShift % 32;
    unsigned int nCount = b.Count() + nWords + 1;
    unsigned int i = nCount;
    while (i)
    {
        --i;
        unsigned int nValue = 0;
        if (i >= nWords)
        {
            nValue = b[i - nWords] << nBits;
            if (i > nWords && nBits)
                nValue += b[i - nWords - 1] >> (32 - nBits);
        }
        a[i] = nValue;
    }
    a.SetCount(nCount);
    a.sub_00422140_Trim();
}

// 0x00422E70
static void __stdcall Shr(BigBuffer& a, const BigBuffer& b, unsigned int nShift)
{
    unsigned int nWords = nShift / 32;
    unsigned int nBits = nShift % 32;
    unsigned int i = 0;
    for (; b.IsUsed(i + nWords); i++)
    {
        unsigned int nValue = b[i + nWords] >> nBits;
        if (nBits)
            nValue += b[i + nWords + 1] << (32 - nBits);
        a[i] = nValue;
    }
    a.SetCount(i);
}

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

static void __stdcall Div(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack); // 0x00423DC0
// 0x00423DC0
static void __stdcall Div(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    c.sub_00422140_Trim();
    d.sub_00422140_Trim();
    unsigned int nCCount = c.Count();
    unsigned int nDCount = d.Count();
    if (nDCount > nCCount)
    {
        b.CopyFrom(c);
        SetZero(a);
        return;
    }
    if (nDCount <= 1)
    {
        const BigBuffer& tD = d;
        sub_004225C0_DivUInt(&b.Ref(0), c, tD[0], a);
        b.sub_004220D0_SetCount(1);
        return;
    }
    // the work stack holds 16 buffers
    SASSERT(tStack.nUsed < 16);
    BigBuffer& tRem = tStack.pRecords[tStack.nUsed++];
    SASSERT(tStack.nUsed < 16);
    BigBuffer& tDiv = tStack.pRecords[tStack.nUsed++];
    SASSERT(tStack.nUsed < 16);
    BigBuffer& tProduct = tStack.pRecords[tStack.nUsed++];
    unsigned int nShift = 31 - (BigHighBitIndex(&d) & 31);
    Shl(tRem, c, nShift);
    Shl(tDiv, d, nShift);
    unsigned int nLastDigit = nDCount - 1;
    unsigned int nTop = tDiv.Ref(nLastDigit) + 1;
    unsigned int i = nCCount - nDCount + 1;
    a.sub_004220D0_SetCount(i);
    while (i)
    {
        --i;
        a.SetStart(i);
        tRem.SetStart(i);
        if (!nTop)
            a.Ref(0) = tRem.Ref(nDCount);
        else
            {
            const unsigned int& nHigh = tRem.Ref(nDCount);
            const unsigned int& nLow = tRem.Ref(nLastDigit);
            unsigned __int64 nWide = (unsigned __int64)nHigh * 0x100000000ui64;
            nWide += nLow;
            a.Ref(0) = (unsigned int)(nWide / nTop);
        }
        if (a.Ref(0))
        {
            BigMulUInt(tProduct, tDiv, a.Ref(0));
            sub_00423100_Sub(tRem, tRem, tProduct);
        }
        while (tRem.At(nDCount) || sub_004212F0_Compare(&tRem, &tDiv) >= 0)
        {
            a.At(0)++;
            sub_00423100_Sub(tRem, tRem, tDiv);
        }
    }
    Shr(b, tRem, nShift);
    b.sub_00422140_Trim();
    SASSERT(3 <= tStack.nUsed);
    tStack.nUsed -= 3;
}

// 0x00424E70
void __stdcall SBigDiv(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigStack& tStack = pResult->tStack;
    BigBuffer& tRem = tStack.pRecords[tStack.nUsed++];
    Div(pResult->tPrimary, tRem, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424ED0
void __stdcall SBigMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigStack& tStack = pResult->tStack;
    BigBuffer& tQuotient = tStack.pRecords[tStack.nUsed++];
    Div(tQuotient, pResult->tPrimary, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}
