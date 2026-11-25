#include "D2StormTypes.h"

#include "D2StormArrayA.h"

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
    BigBuffer& operator=(const BigBuffer& tSource)
    {
        if (this != &tSource)
        {
            D2StormArrayViewStrc tView;
            tView.pData = tSource.m_array.m_data;
            tView.nCount = tSource.m_array.m_count;
            m_array.sub_004215C0_Set(tView.nCount, tView.pData);
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
            m_array.sub_004215C0_Set(tView.nCount, tView.pData);
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
};

unsigned int __stdcall BigHighBitIndex(BigBuffer* pQueue);                              // 0x004213B0
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight);                      // 0x004212F0
int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack); // 0x004242C0
void __stdcall sub_00424B00_BigSquare(BigBuffer* pResult, BigBuffer* pA, BigStack* pStack); // 0x00424B00
unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue);                            // 0x00421470
extern const unsigned int gaSBigFermatBases[1];                                                         // 0x006CFF70
extern const unsigned int gaSBigSmallPrimes[171];                                                        // 0x006CFF78

inline unsigned __int64 MakeLarge(const unsigned int& nLow, const unsigned int& nHigh)
{
    return (unsigned __int64)nHigh * 0x100000000ui64 + nLow;
}

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

void __stdcall sub_004225C0_DivUInt(unsigned int* pRemainder, const BigBuffer& b, unsigned __int64 c, BigBuffer& a); // 0x004225C0

int IsZero(BigBuffer& a); // 0x00422780
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

// 0x00422C60
static void SetOne(BigBuffer& a)
{
    a.SetCount(1);
    a.GrowToFit(0);
    a.m_array.m_data[a.m_start] = 1;
}

void SetZero(BigBuffer& a); // 0x00422CC0
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

void __stdcall Shr(BigBuffer& a, const BigBuffer& b, unsigned int nShift); // 0x00422E70
void __stdcall sub_00423100_Sub(BigBuffer& a, const BigBuffer& b, const BigBuffer& c); // 0x00423100

static void __stdcall Div(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack) // 0x00423DC0
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
    BigBuffer& tRem = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tDiv = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tProduct = tStack.pRecords[tStack.nUsed++];
    unsigned int nShift = 31 - (BigHighBitIndex(&d) & 31);
    Shl(tRem, c, nShift);
    Shl(tDiv, d, nShift);
    unsigned int nTop = tDiv.Ref(nDCount - 1) + 1;
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
            a.Ref(0) = (unsigned int)(MakeLarge(tRem.Ref(nDCount - 1), tRem.Ref(nDCount)) / nTop);
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
    tStack.nUsed -= 3;
}

int IsOne(BigBuffer& a); // 0x00422750

void __stdcall sub_00422FC0_SubUInt(const BigBuffer* pSrc, BigBuffer* pDst, unsigned int nValue); // 0x00422FC0

void __stdcall FromUnsigned(BigBuffer& a, unsigned int nValue); // 0x00423540

// 0x004245F0
static void __stdcall BigMulMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    BigBuffer& tProduct = tStack.pRecords[tStack.nUsed++];
    sub_004242C0_BigOp(&tProduct, &b, &c, &tStack);
    Div(tProduct, a, tProduct, d, tStack);
    tStack.nUsed--;
}

// 0x00425150
static void __stdcall PowMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    c.sub_00422140_Trim();
    if (!c.Count())
    {
        SetOne(a);
        return;
    }
    BigBuffer& tQuot = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tSquare = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tCube = tStack.pRecords[tStack.nUsed++];
    int bDistinct = &a == &b || &a == &c || &a == &d;
    BigBuffer& tWork = bDistinct ? tStack.pRecords[tStack.nUsed++] : a;
    BigMulMod(tSquare, b, b, d, tStack);
    BigMulMod(tCube, tSquare, b, d, tStack);
    BigBuffer* aPowers[3] = { &b, &tSquare, &tCube };
    SetOne(tWork);
    const BigBuffer& tExp = c;

    unsigned int i = c.Count();
    if (c.Count())
    {
        do
        {
            --i;
            const unsigned int nEnd = tExp.m_array.m_count;
            unsigned int nDigit = tExp[i];
            unsigned int nBits = 32;
            if (i + 1 == nEnd - tExp.m_start)
            {
                while (!(nDigit & 0xC0000000))
                {
                    nDigit <<= 2;
                    nBits -= 2;
                }
            }
            for (; nBits > 0; nBits -= 2)
            {
                sub_00424B00_BigSquare(&tWork, &tWork, &tStack);
                Div(tQuot, tWork, tWork, d, tStack);
                sub_00424B00_BigSquare(&tWork, &tWork, &tStack);
                Div(tQuot, tWork, tWork, d, tStack);
                if (nDigit >> 30)
                    BigMulMod(tWork, tWork, *aPowers[(nDigit >> 30) - 1], d, tStack);
                nDigit <<= 2;
            }
        } while (i);
    }
    if (&a != &tWork)
    {
        a.CopyFrom(tWork);
        tStack.nUsed--;
    }
    tStack.nUsed -= 3;
}

static int __stdcall IsPrime(BigStack* pStack, BigBuffer& a) // 0x00425350
{
    BigBuffer& tMinusOne = pStack->pRecords[pStack->nUsed++];
    BigBuffer& tOdd = pStack->pRecords[pStack->nUsed++];
    BigBuffer& tWork = pStack->pRecords[pStack->nUsed++];
    BigBuffer& tBase = pStack->pRecords[pStack->nUsed++];
    int bPrime = 1;
    a.sub_00422140_Trim();
    const BigBuffer& tRead = a;
    if (IsZero(a) || !(tRead[0] & 1))
        bPrime = 0;
    for (unsigned int i = 0; bPrime && i < 171; i++)
    {
        unsigned __int64 nPrime = gaSBigSmallPrimes[i];
        int bZero;
        if (nPrime < 0x100000000ui64)
        {
            unsigned int nRemainder;
            sub_004225C0_DivUInt(&nRemainder, a, nPrime, tWork);
            bZero = !nRemainder;
        }
        else
        {
            FromUnsigned(tBase, (unsigned int)nPrime);
            Div(tWork, tOdd, a, tBase, *pStack);
            bZero = IsZero(tOdd);
        }
        if (bZero && !IsOne(tWork))
            bPrime = 0;
    }
    sub_00422FC0_SubUInt(&a, &tMinusOne, 1);
    tOdd.CopyFrom(tMinusOne);
    unsigned int nShift = sub_00421470_FindLowestSetBit(&tOdd);
    if (nShift)
        Shr(tOdd, tOdd, nShift);
    for (unsigned int i = 0; bPrime && i < 6; i++)
    {
        FromUnsigned(tBase, gaSBigSmallPrimes[i]);
        if (sub_004212F0_Compare(&tBase, &a) >= 0)
            break;
        PowMod(tWork, tBase, tOdd, a, *pStack);
        if (!IsOne(tWork) && sub_004212F0_Compare(&tWork, &tMinusOne))
        {
            unsigned int j = 0;
            do
            {
                if (++j == nShift)
                {
                    bPrime = 0;
                    break;
                }
                BigMulMod(tWork, tWork, tWork, a, *pStack);
                if (IsOne(tWork))
                {
                    bPrime = 0;
                    break;
                }
            } while (sub_004212F0_Compare(&tWork, &tMinusOne));
        }
    }
    for (unsigned int i = 0; bPrime && i < 1; i++)
    {
        FromUnsigned(tBase, gaSBigFermatBases[i]);
        PowMod(tWork, tBase, a, a, *pStack);
        if (sub_004212F0_Compare(&tWork, &tBase))
            bPrime = 0;
    }
    pStack->nUsed -= 4;
    return bPrime;
}

void __stdcall FindPrime(unsigned int nBits, BigBuffer& b, BigBuffer& c, BigStack* pStack, BigBuffer& a); // 0x004255E0

// 0x00425330
void __stdcall SBigPowMod(D2StormBigStrc* pResult, D2StormBigStrc* pBase, D2StormBigStrc* pExponent, D2StormBigStrc* pModulus)
{
    PowMod(pResult->tPrimary, pBase->tPrimary, pExponent->tPrimary, pModulus->tPrimary, pResult->tStack);
}

// 0x004255C0
int __stdcall SBigIsPrime(D2StormBigStrc* pBig)
{
    return IsPrime(&pBig->tStack, pBig->tPrimary);
}

// 0x00425700
void __stdcall SBigFindPrime(D2StormBigStrc* pResult, unsigned int nBits, D2StormBigStrc* pRandom, D2StormBigStrc* pExponent)
{
    FindPrime(nBits, pRandom->tPrimary, pExponent->tPrimary, &pResult->tStack, pResult->tPrimary);
}

void __stdcall InvMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack); // 0x00424FB0
// 0x00425310
void __stdcall SBigInvMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    InvMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}
