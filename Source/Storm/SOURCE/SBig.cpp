
#include "Storm.h"
#include "D2StormTypes.h"
#include "D2StormBigBuffer.h"
#include "D2StormArrayC.h"

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);          // 0x00413020
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags);                // 0x00412650

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

inline void operator delete(void*, void*) throw()
{
}
inline void operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

// build: symbol ??0BigBuffer@@QAE@XZ 0x00421B50
// build: symbol ??1BigBuffer@@QAE@XZ 0x00421810
// build: symbol ??1BigStack@@QAE@XZ 0x00421830
// build: symbol ??0BigStack@@QAE@XZ 0x00421B70

struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    D2StormArrayBStrc() : m_alloc(0), m_count(0), m_data(0), m_chunk(0)
    {
    }
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
    void Push(unsigned char nByte)
    {
        Reserve(1, 1);
        m_data[m_count] = nByte;
        m_count += 1;
    }
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);                         // 0x004218B0
    void sub_004219F0_Set(unsigned int nCount, const unsigned char* pData);                                 // 0x004219F0
};



struct D2StormBigStrc
{
    BigBuffer tPrimary;
    BigStack tStack;
    D2StormArrayBStrc tOutput;

    D2StormBigStrc();
    ~D2StormBigStrc();                                                                                      // 0x00421D80
};

unsigned int __stdcall BigHighBitIndex(BigBuffer* pQueue);                              // 0x004213B0
int __stdcall sub_004212F0_Compare(BigBuffer* pLeft, BigBuffer* pRight);                      // 0x004212F0
int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack); // 0x004242C0

unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue);                            // 0x00421470
extern const unsigned int gaSBigFermatBases[1];                                                         // 0x006CFF70
extern const unsigned int gaSBigSmallPrimes[171];                                                        // 0x006CFF78
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                            // 0x0041D2A0
void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, BigBuffer* pIn);                         // 0x00421CB0
int __stdcall Rand(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack); // 0x00424700
int __stdcall sub_00424B00_Square(BigBuffer* pResult, BigBuffer* pA, BigStack* pStack); // 0x00424B00

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

// 0x00421510
static void __cdecl BigToUnsigned(unsigned int* pnResult, const BigBuffer& tBuffer)
{
    *pnResult = 0;
    *pnResult = tBuffer[0];
}

// 0x00421530
int __stdcall SBigCompare(D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return sub_004212F0_Compare(&pA->tPrimary, &pB->tPrimary);
}

// 0x00421550
void __stdcall SBigToUnsigned(D2StormBigStrc* pBig, unsigned int* pnResult)
{
    BigToUnsigned(pnResult, pBig->tPrimary);
}

// build: symbol ??3@YAXPAX0@Z 0x0040EB30
// 0x00421E10
D2StormBigStrc::D2StormBigStrc()
{
}

// 0x00423950
void __stdcall SBigNew(D2StormBigStrc** ppBig)
{
    *ppBig = new (SMemAlloc(sizeof(D2StormBigStrc), ".\\SOURCE\\SBig.cpp", 0x521, 0)) D2StormBigStrc;
}

// 0x00424E40
void __stdcall SBigDel(D2StormBigStrc* pBig)
{
    delete pBig;
}

// 0x00424F10
int __stdcall SBigMul(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return sub_004242C0_BigOp(&pResult->tPrimary, &pA->tPrimary, &pB->tPrimary, &pResult->tStack);
}

// 0x00424F70
int __stdcall SBigRand(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    return Rand(&pResult->tPrimary, &pA->tPrimary, &pB->tPrimary, &pResult->tStack);
}

// 0x00424F90
int __stdcall SBigSquare(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    return sub_00424B00_Square(&pResult->tPrimary, &pA->tPrimary, &pResult->tStack);
}

// 0x004228C0
static void __stdcall BigNot(BigBuffer& a, const BigBuffer& b)
{
    unsigned int i = 0;
    for (; b.IsUsed(i); i++)
    {
        a[i] = ~b[i];
    }
    a.SetCount(i);
}

// 0x004239E0
void __stdcall SBigNot(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    BigNot(pResult->tPrimary, pA->tPrimary);
}

// 0x00422300
static void __stdcall BigAdd(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned __int64 nCarry = 0;
    unsigned int i = 0;
    for (; nCarry || b.IsUsed(i) || c.IsUsed(i); i++)
    {
        nCarry += (unsigned __int64)b[i] + c[i];
        a[i] = ExtractLowPart(nCarry);
    }
    a.SetCount(i);
}

// 0x00423790
void __stdcall SBigAdd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigAdd(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00422440
static void __stdcall BigAnd(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] & c[i];
    }
    a.SetCount(i);
}

// 0x004237B0
void __stdcall SBigAnd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigAnd(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x004229D0
static void __stdcall BigOr(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] | c[i];
    }
    a.SetCount(i);
}

// 0x00423A00
void __stdcall SBigOr(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigOr(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00423250
static void __stdcall BigXor(BigBuffer& a, const BigBuffer& b, const BigBuffer& c)
{
    unsigned int i = 0;
    for (; b.IsUsed(i) || c.IsUsed(i); i++)
    {
        a[i] = b[i] ^ c[i];
    }
    a.SetCount(i);
}

// 0x00423D60
void __stdcall SBigXor(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigXor(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x004221F0
static void __stdcall BigAddUInt(BigBuffer& a, const BigBuffer& b, unsigned int c)
{
    unsigned __int64 nCarry = c;
    unsigned int i = 0;
    for (; nCarry || b.IsUsed(i); i++)
    {
        nCarry += b[i];
        a[i] = ExtractLowPart(nCarry);
    }
    a.SetCount(i);
}

// 0x00422570
static int __stdcall BigCompareUInt(BigBuffer& a, unsigned int b)
{
    a.sub_00422140_Trim();
    if (a.Count() > 1)
        return 1;
    const BigBuffer& tRead = a;
    unsigned int nDigit = tRead[0];
    if (nDigit)
        return nDigit > b ? 1 : -1;
    return 0;
}

void __stdcall sub_004225C0_DivUInt(BigBuffer& a, unsigned int* pRemainder, const BigBuffer& b, unsigned __int64 c); // 0x004225C0

// 0x00422750
static int IsOne(BigBuffer& a)
{
    a.sub_00422140_Trim();
    const BigBuffer& tRead = a;
    return tRead.Count() == 1 && tRead[0] == 1;
}

// 0x00422780
static int IsZero(BigBuffer& a)
{
    a.sub_00422140_Trim();
    return a.Count() == 0;
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

// 0x00422B00
static void __stdcall Set2Exp(BigBuffer& a, unsigned int nExponent)
{
    unsigned int i = 0;
    for (; i < nExponent / 32; i++)
        a[i] = 0;
    a[i] = 1 << (nExponent % 32);
    a.SetCount(i + 1);
}

// 0x00422C60
static void SetOne(BigBuffer& a)
{
    a.SetCount(1);
    a.GrowToFit(0);
    a.m_array.m_data[a.m_start] = 1;
}

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

static void __stdcall sub_00422FC0_SubUInt(BigBuffer& a, const BigBuffer& b, unsigned int c)
{
    unsigned __int64 nBorrow = ~(unsigned __int64)c + 1;
    unsigned int i = 0;
    for (; b.IsUsed(i); i++)
    {
        nBorrow += b[i];
        a[i] = ExtractLowPartSx(nBorrow);
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

// 0x004234B0
static void FromStr(BigBuffer& a, const char* szString)
{
    SetZero(a);
    while (*szString)
    {
        BigMulUInt(a, a, 10);
        BigAddUInt(a, a, *szString - '0');
        szString++;
    }
}

// 0x00423540
static void __stdcall FromUnsigned(BigBuffer& a, unsigned int nValue)
{
    a[0u] = nValue;
    a.SetCount(1);
}

static void __stdcall ToStr(const BigBuffer& tNumber, D2StormArrayBStrc& tOutput, BigStack& tStack) // 0x00423600
{
    BigBuffer& tBuffer = tStack.pRecords[tStack.nUsed++];
    tBuffer.CopyFrom(tNumber);
    tOutput.m_count = 0;
    do
    {
        unsigned int nDigit;
        sub_004225C0_DivUInt(tBuffer, &nDigit, tBuffer, 10);
        unsigned char nChar = (unsigned char)(nDigit + '0');
        tOutput.Add(1, &nChar);
    } while (BigCompareUInt(tBuffer, 0));
    unsigned int nCount = tOutput.m_count;
    for (unsigned int i = 0; i < nCount / 2; i++)
    {
        unsigned char nSwap = tOutput.m_data[i];
        tOutput.m_data[i] = tOutput.m_data[nCount - 1 - i];
        tOutput.m_data[nCount - 1 - i] = nSwap;
    }
    *tOutput.New() = 0;
    tStack.nUsed--;
}

// 0x00423800
void __stdcall SBigDec(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    sub_00422FC0_SubUInt(pResult->tPrimary, pA->tPrimary, 1);
}

// 0x00423870
void __stdcall SBigFromStr(D2StormBigStrc* pBig, const char* szString)
{
    FromStr(pBig->tPrimary, szString);
}

// 0x004238B0
void __stdcall SBigFromUnsigned(D2StormBigStrc* pBig, unsigned int nValue)
{
    FromUnsigned(pBig->tPrimary, nValue);
}

// 0x004238D0
void __stdcall SBigInc(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    BigAddUInt(pResult->tPrimary, pA->tPrimary, 1);
}

// 0x00423910
int __stdcall SBigIsOne(D2StormBigStrc* pBig)
{
    return IsOne(pBig->tPrimary);
}

// 0x00423930
int __stdcall SBigIsZero(D2StormBigStrc* pBig)
{
    return IsZero(pBig->tPrimary);
}

// 0x00423A20
void __stdcall SBigSet2Exp(D2StormBigStrc* pBig, unsigned int nExponent)
{
    Set2Exp(pBig->tPrimary, nExponent);
}

// 0x00423A40
void __stdcall SBigSetOne(D2StormBigStrc* pBig)
{
    SetOne(pBig->tPrimary);
}

// 0x00423A60
void __stdcall SBigSetZero(D2StormBigStrc* pBig)
{
    SetZero(pBig->tPrimary);
}

// 0x00423A80
void __stdcall SBigShl(D2StormBigStrc* pResult, D2StormBigStrc* pA, unsigned int nShift)
{
    Shl(pResult->tPrimary, pA->tPrimary, nShift);
}

// 0x00423AA0
void __stdcall SBigShr(D2StormBigStrc* pResult, D2StormBigStrc* pA, unsigned int nShift)
{
    Shr(pResult->tPrimary, pA->tPrimary, nShift);
}

// 0x00423AC0
void __stdcall SBigSub(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    sub_00423100_Sub(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00423BC0
void __stdcall SBigToStrArray(D2StormBigStrc* pBig, D2StormArrayCStrc* pArray, int bAppend)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    if (bAppend)
        pArray->sub_00421F60_Add(pBig->tOutput.m_count, (const char*)pBig->tOutput.m_data);
    else
        pArray->sub_00421A50_Set(pBig->tOutput.m_count, (const char*)pBig->tOutput.m_data);
}

// 0x00423C20
void __stdcall SBigToStrBuffer(D2StormBigStrc* pBig, char* szBuffer, unsigned int nSize)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    SStrCopy(szBuffer, (const char*)pBig->tOutput.m_data, nSize);
}

// 0x00423C60
void __stdcall SBigToStrPtr(D2StormBigStrc* pBig, const char** pszString)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    *pszString = (const char*)pBig->tOutput.m_data;
}

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
        sub_004225C0_DivUInt(a, &b.Ref(0), c, tD[0]);
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

static void __stdcall Gcd(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack) // 0x00424180
{
    BigBuffer& tRem = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tNext = tStack.pRecords[tStack.nUsed++];
    if (sub_004212F0_Compare(&b, &c) > 0)
    {
        a.CopyFrom(b);
        tNext.CopyFrom(c);
    }
    else
    {
        a.CopyFrom(c);
        tNext.CopyFrom(b);
    }
    while (!IsZero(tNext))
    {
        Div(a, tRem, a, tNext, tStack);
        a.CopyFrom(tNext);
        tNext.CopyFrom(tRem);
    }
    tStack.nUsed -= 2;
}

// 0x004245F0
static void __stdcall BigMulMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    BigBuffer& tProduct = tStack.pRecords[tStack.nUsed++];
    sub_004242C0_BigOp(&tProduct, &b, &c, &tStack);
    Div(tProduct, a, tProduct, d, tStack);
    tStack.nUsed--;
}

// 0x00424E70
void __stdcall SBigDiv(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigStack& tStack = pResult->tStack;
    BigBuffer& tRem = tStack.pRecords[tStack.nUsed++];
    Div(pResult->tPrimary, tRem, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424EB0
void __stdcall SBigGcd(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    Gcd(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}

// 0x00424ED0
void __stdcall SBigMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigStack& tStack = pResult->tStack;
    BigBuffer& tQuotient = tStack.pRecords[tStack.nUsed++];
    Div(tQuotient, pResult->tPrimary, pA->tPrimary, pB->tPrimary, tStack);
    tStack.nUsed--;
}

// 0x00424F30
void __stdcall SBigMulMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB, D2StormBigStrc* pC)
{
    BigMulMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pC->tPrimary, pResult->tStack);
}

// 0x00424640
static void __stdcall Pow(BigBuffer* pResult, BigBuffer* pBase, unsigned int nExp, BigStack* pStack)
{
    unsigned int nBit = nExp;
    while (nBit & (nBit - 1))
    {
        nBit &= nBit - 1;
    }
    BigBuffer* pWork = (pResult == pBase) ? &pStack->pRecords[pStack->nUsed++] : pResult;
    if (pWork != pBase)
    {
        D2StormArrayViewStrc tView;
        tView.pData = pBase->m_array.m_data;
        tView.nCount = pBase->m_array.m_count;
        pWork->m_array.sub_004215C0_Set(tView.nCount, tView.pData);
    }
    pWork->m_array.m_chunk = pBase->m_array.m_chunk;
    pWork->m_start = pBase->m_start;
    while (nBit > 1)
    {
        sub_004242C0_BigOp(pWork, pWork, pWork, pStack);
        nBit >>= 1;
        if (nExp & nBit)
        {
            sub_004242C0_BigOp(pWork, pWork, pBase, pStack);
        }
    }
    if (pResult != pWork)
    {
        *pResult = *pWork;
        pStack->nUsed--;
    }
}

// 0x00424F50
void __stdcall SBigPow(D2StormBigStrc* pResult, D2StormBigStrc* pBase, unsigned int nExp)
{
    Pow(&pResult->tPrimary, &pBase->tPrimary, nExp, &pResult->tStack);
}

static void __stdcall PowMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack) // 0x00425150
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
    BigBuffer& tWork = (&a == &b || &a == &c || &a == &d) ? tStack.pRecords[tStack.nUsed++] : a;
    BigMulMod(tSquare, b, b, d, tStack);
    BigMulMod(tCube, tSquare, b, d, tStack);
    BigBuffer* aPowers[3] = { &b, &tSquare, &tCube };
    SetOne(tWork);
    const BigBuffer& tExp = c;
    for (unsigned int i = c.Count(); i; i--)
    {
        unsigned int nDigit = tExp[i - 1];
        unsigned int nBits = 32;
        if (i == c.Count())
        {
            while (!(nDigit & 0xC0000000))
            {
                nDigit <<= 2;
                nBits -= 2;
            }
        }
        for (; nBits; nBits -= 2)
        {
            sub_00424B00_Square(&tWork, &tWork, &tStack);
            Div(tQuot, tWork, tWork, d, tStack);
            sub_00424B00_Square(&tWork, &tWork, &tStack);
            Div(tQuot, tWork, tWork, d, tStack);
            if (nDigit >> 30)
                BigMulMod(tWork, tWork, *aPowers[(nDigit >> 30) - 1], d, tStack);
            nDigit <<= 2;
        }
    }
    if (&tWork != &a)
    {
        a.CopyFrom(tWork);
        tStack.nUsed--;
    }
    tStack.nUsed -= 3;
}

static int __stdcall IsPrime(BigStack* pStack, BigBuffer& a) // 0x00425350
{
    const unsigned int nUsed = pStack->nUsed;
    BigBuffer& tMinusOne = pStack->pRecords[nUsed];
    BigBuffer& tOdd = pStack->pRecords[nUsed + 1];
    BigBuffer& tWork = pStack->pRecords[nUsed + 2];
    BigBuffer& tBase = pStack->pRecords[nUsed + 3];
    pStack->nUsed = nUsed + 4;
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
            sub_004225C0_DivUInt(tWork, &nRemainder, a, nPrime);
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
    sub_00422FC0_SubUInt(tMinusOne, a, 1);
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

// 0x00421440
static int BigIsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}

// 0x004255E0
static void __stdcall FindPrime(unsigned int nBits, BigBuffer& b, BigBuffer& c, BigStack* pStack, BigBuffer& a)
{
    BigBuffer& tLow = pStack->pRecords[pStack->nUsed++];
    BigBuffer& tHigh = pStack->pRecords[pStack->nUsed++];
    BigBuffer& tWork = pStack->pRecords[pStack->nUsed++];
    Set2Exp(tLow, nBits - 2);
    Set2Exp(tHigh, nBits - 1);
    BigAdd(tHigh, tHigh, tLow);
    Div(tWork, a, b, tLow, *pStack);
    BigAdd(a, a, tHigh);
    if (BigIsEven(a))
        BigAddUInt(a, a, 1);
    BigAdd(tHigh, tHigh, tLow);
    sub_00422FC0_SubUInt(tHigh, tHigh, 2);
    for (;;)
    {
        if (IsPrime(pStack, a))
        {
            if (IsOne(c))
                break;
            sub_00422FC0_SubUInt(tWork, a, 1);
            Gcd(tWork, tWork, c, *pStack);
            if (IsOne(tWork))
                break;
        }
        BigAddUInt(a, a, 2);
        if (sub_004212F0_Compare(&a, &tHigh) > 0)
            sub_00423100_Sub(a, a, tLow);
    }
    pStack->nUsed -= 3;
}

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

static void __stdcall InvMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack) // 0x00424FB0
{
    BigBuffer& tPrev = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tNum = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tDen = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tQuot = tStack.pRecords[tStack.nUsed++];
    BigBuffer& tRem = tStack.pRecords[tStack.nUsed++];
    tNum.CopyFrom(b);
    tDen.CopyFrom(c);
    SetOne(a);
    SetZero(tPrev);
    int nSign = 1;
    while (!IsZero(tDen))
    {
        Div(tQuot, tRem, tNum, tDen, tStack);
        sub_004242C0_BigOp(&tQuot, &tQuot, &tPrev, &tStack);
        BigAdd(tQuot, a, tQuot);
        a.CopyFrom(tPrev);
        tPrev.CopyFrom(tQuot);
        tNum.CopyFrom(tDen);
        tDen.CopyFrom(tRem);
        nSign = -nSign;
    }
    if (nSign < 0)
        sub_00423100_Sub(a, c, a);
    tStack.nUsed -= 5;
}

// 0x00425310
void __stdcall SBigInvMod(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    InvMod(pResult->tPrimary, pA->tPrimary, pB->tPrimary, pResult->tStack);
}

static void EncodeDataBytes(unsigned int nValue, D2StormArrayBStrc* pArray) // 0x00421BD0
{
    while (nValue)
    {
        pArray->Push((unsigned char)(nValue % 255));
        nValue /= 255;
    }
    pArray->Push(0xFF);
}

// 0x004235F0
static void ToBinary(D2StormArrayBStrc* pOut, BigBuffer* pIn)
{
    pOut->m_count = 0;
    sub_00421CB0_AppendDigits(pOut, pIn);
}

static void ToStream(D2StormArrayBStrc* pOut, BigBuffer* pIn) // 0x00423770
{
    ToBinary(pOut, pIn);
    EncodeDataBytes(pOut->m_count, pOut);
    sub_00421CB0_AppendDigits(pOut, pIn);
}

// 0x00423AE0
void __stdcall SBigToBinaryArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    ToBinary(&pBig->tOutput, &pBig->tPrimary);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tOutput.m_count, pBig->tOutput.m_data);
    else
        pArray->sub_004219F0_Set(pBig->tOutput.m_count, pBig->tOutput.m_data);
}

// 0x00423B30
void __stdcall SBigToBinaryBuffer(D2StormBigStrc* pBig, void* pBuffer, unsigned int nSize, unsigned int* pRead)
{
    ToBinary(&pBig->tOutput, &pBig->tPrimary);
    unsigned int nCopy = pBig->tOutput.m_count < nSize ? pBig->tOutput.m_count : nSize;
    SMemCopy(pBuffer, pBig->tOutput.m_data, nCopy);
    if (pRead)
        *pRead = nCopy;
}

// 0x00423B80
void __stdcall SBigToBinaryPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    ToBinary(&pBig->tOutput, &pBig->tPrimary);
    *ppData = pBig->tOutput.m_data;
    if (pSize)
        *pSize = pBig->tOutput.m_count;
}

// 0x00423C90
void __stdcall SBigToStreamArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    ToStream(&pBig->tOutput, &pBig->tPrimary);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tOutput.m_count, pBig->tOutput.m_data);
    else
        pArray->sub_004219F0_Set(pBig->tOutput.m_count, pBig->tOutput.m_data);
}

// 0x00423CE0
void __stdcall SBigToStreamBuffer(D2StormBigStrc* pBig, void* pBuffer, unsigned int nSize, unsigned int* pWritten)
{
    ToStream(&pBig->tOutput, &pBig->tPrimary);
    unsigned int nCopy = pBig->tOutput.m_count < nSize ? pBig->tOutput.m_count : nSize;
    SMemCopy(pBuffer, pBig->tOutput.m_data, nCopy);
    if (pWritten)
        *pWritten = nCopy;
}

// 0x00423D30
void __stdcall SBigToStreamPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    ToStream(&pBig->tOutput, &pBig->tPrimary);
    *ppData = pBig->tOutput.m_data;
    *pSize = pBig->tOutput.m_count;
}

// 0x00422710
static int IsOdd(BigBuffer* pQueue)
{
    pQueue->sub_00422140_Trim();
    const BigBuffer& tQueue = *pQueue;
    if (tQueue.Count() >= 1 && (tQueue[0] & 1))
    {
        return 1;
    }
    return 0;
}

// 0x004238F0
int __stdcall SBigIsOdd(D2StormBigStrc* pBig)
{
    return IsOdd(&pBig->tPrimary);
}

// 0x00421540
int __stdcall SBigIsEven(D2StormBigStrc* pBig)
{
    return BigIsEven(pBig->tPrimary);
}

// 0x004237D0
void __stdcall SBigCopy(D2StormBigStrc* pDest, D2StormBigStrc* pSource)
{
    pDest->tPrimary = pSource->tPrimary;
}

#include "gen/data/Source/Storm/SOURCE/SBig.inc"
