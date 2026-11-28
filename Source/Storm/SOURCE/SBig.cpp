
#include "Storm.h"
#include "D2StormTypes.h"
#include "D2StormBigBuffer.h"
#include "StormApi.h"
#include "stpl.h"


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

// Storm's byte array, with the one-element Add whose Storm name isn't known.
struct D2StormArrayBStrc : TSGrowableArray<unsigned char>
{
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
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
int __stdcall sub_004212F0_Compare(const BigBuffer* pLeft, const BigBuffer* pRight);                      // 0x004212F0
int __stdcall sub_004242C0_BigOp(BigBuffer* pResult, BigBuffer* pA, BigBuffer* pB, BigStack* pStack); // 0x004242C0

unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue);                            // 0x00421470
extern const unsigned int gaSBigFermatBases[1];                                                         // 0x006CFF70
extern const unsigned int gaSBigSmallPrimes[171];                                                        // 0x006CFF78
static void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, const BigBuffer* pIn);                         // 0x00421CB0
static void __stdcall Rand(BigBuffer* pResult, BigBuffer* pModulus, BigBuffer* pSeed, BigStack* pStack); // 0x00424700
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

extern const unsigned char gabSBigRandMul[8] = { 0x50, 0x46, 0x00, 0x00, 0x69, 0x90, 0x00, 0x00 }; // 0x006CFF60
extern const unsigned char gabSBigRandSeed[8]; // 0x006CFF68

// The instances of Storm's array templates that SBig's object holds (0x420FD0-0x421F60).
template TSBaseArray<unsigned int>::TSBaseArray();
template TSBaseArray<unsigned char>::TSBaseArray();
template TSGrowableArray<unsigned int>::TSGrowableArray();
template void TSFixedArray<unsigned int>::ReallocData(unsigned int);
template void TSFixedArray<unsigned char>::ReallocData(unsigned int);
template void TSFixedArray<char>::ReallocData(unsigned int);
template TSFixedArray<unsigned int>& TSFixedArray<unsigned int>::operator=(const TSFixedArray<unsigned int>&);
template void TSGrowableArray<unsigned char>::SetCount(unsigned int);
template TSGrowableArray<unsigned int>& TSGrowableArray<unsigned int>::operator=(const TSGrowableArray<unsigned int>&);
template unsigned int& TSBaseArray<unsigned int>::operator[](unsigned int);
template char& TSBaseArray<char>::operator[](unsigned int);
template char* TSBaseArray<char>::Ptr();
template unsigned int* TSBaseArray<unsigned int>::Ptr();
template unsigned char* TSBaseArray<unsigned char>::Ptr();
template void __fastcall TSCD<unsigned char>::Construct(unsigned char*);
template void __fastcall TSCD<unsigned char>::CopyConstruct(unsigned char*, const unsigned char&);
template void __fastcall TSCD<unsigned char>::Destruct(unsigned char*);
template void __fastcall TSCD<char>::Construct(char*);
template void __fastcall TSCD<char>::CopyConstruct(char*, const char&);
template void __fastcall TSCD<char>::Destruct(char*);
template void __fastcall TSCD<unsigned int>::CopyConstruct(unsigned int*, const unsigned int&);
template void __fastcall TSCD<unsigned int>::Destruct(unsigned int*);
template unsigned int TSGrowableArray<unsigned int>::CalcChunkSize(unsigned int);
template unsigned int TSGrowableArray<unsigned int>::RoundUp(unsigned int, unsigned int);
template unsigned int TSGrowableArray<unsigned char>::CalcChunkSize(unsigned int);
template unsigned int TSGrowableArray<unsigned char>::RoundUp(unsigned int, unsigned int);
template unsigned int TSGrowableArray<char>::CalcChunkSize(unsigned int);
template unsigned int TSGrowableArray<char>::RoundUp(unsigned int, unsigned int);
template TSFixedArray<unsigned int>::~TSFixedArray();
template TSFixedArray<unsigned char>::~TSFixedArray();
template void TSFixedArray<unsigned int>::Set(unsigned int, const unsigned int*);
template void TSGrowableArray<unsigned char>::Reserve(unsigned int, int);
template void TSGrowableArray<unsigned char>::ReallocData(unsigned int);
template void TSGrowableArray<unsigned int>::ReallocData(unsigned int);
template void TSGrowableArray<char>::ReallocData(unsigned int);
template TSGrowableArray<unsigned int>::~TSGrowableArray();
template TSGrowableArray<unsigned char>::~TSGrowableArray();
template TSGrowableArray<unsigned char>::TSGrowableArray();
template unsigned int TSGrowableArray<unsigned char>::Add(unsigned int, const unsigned char*);
template unsigned char* TSGrowableArray<unsigned char>::New();
template void TSFixedArray<unsigned char>::Set(unsigned int, const unsigned char*);
template void TSFixedArray<char>::Set(unsigned int, const char*);
template void TSGrowableArray<unsigned int>::Reserve(unsigned int, int);
template void TSGrowableArray<char>::Reserve(unsigned int, int);
template void TSGrowableArray<unsigned int>::SetCount(unsigned int);
template unsigned int TSGrowableArray<char>::Add(unsigned int, const char*);

// 0x00420F80
static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength)
{
    *pnLength = 0;
    *pnOffset = 0;
    while (*pnOffset < nSize)
    {
        unsigned int nByte = pData[(*pnOffset)++];
        if (nByte == 0xFF)
            break;
        *pnLength = *pnLength * 0xFF + nByte;
    }
    *pnLength = *pnLength < nSize - *pnOffset ? *pnLength : nSize - *pnOffset;
}

// 0x00421100
D2UnitStrc* __fastcall sub_00421100_GetSelf(D2UnitStrc* pUnit)
{
    return pUnit;
}

// 0x004212C0
void __fastcall WARDENCLIENT_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

// 0x004212D0
unsigned int BigBuffer::sub_004212D0_Get(unsigned int nIndex)
{
    return IsUsed(nIndex) ? m_array.m_data[m_start + nIndex] : 0;
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

// The byte array's one-element Add keeps its own name: Storm's name for it isn't known.
// 0x004219D0
unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return Add(1, pData);
}

// 0x00421BD0
static void EncodeDataBytes(unsigned int nValue, D2StormArrayBStrc* pArray)
{
    while (nValue)
    {
        *pArray->New() = (unsigned char)(nValue % 255);
        nValue /= 255;
    }
    *pArray->New() = 0xFF;
}

// 0x00421CB0
static void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, const BigBuffer* pIn)
{
    for (unsigned int i = 0; i < 4 * pIn->Count(); ++i)
    {
        unsigned int nDigit = i / 4;
        unsigned int nByte = i % 4;
        unsigned int nValue = (*pIn)[nDigit] >> (8 * nByte);
        if (nValue || nDigit + 1 < pIn->Count())
            *pOut->New() = (unsigned char)nValue;
    }
}

// 0x00421D80
D2StormBigStrc::~D2StormBigStrc()
{
}

// 0x00421E10
D2StormBigStrc::D2StormBigStrc()
{
}

// 0x00421FE0
void BigBuffer::GrowToFit(int nIndex)
{
    unsigned int nPosition = m_start + nIndex;
    if (nPosition >= m_array.m_count)
    {
        unsigned int nNewCount = nPosition + 1;
        if (nNewCount > m_array.m_alloc)
        {
            unsigned int nChunk = m_array.m_chunk ? m_array.m_chunk : m_array.CalcChunkSize(nNewCount);
            m_array.ReallocData(m_array.RoundUp(nNewCount, nChunk));
        }
        SMemZero(&m_array.m_data[m_array.m_count], (nPosition - m_array.m_count + 1) * sizeof(unsigned int));
        m_array.m_count = nNewCount;
    }
}

// 0x004220D0
void BigBuffer::sub_004220D0_SetCount(unsigned int nCount)
{
    m_array.SetCount(m_start + nCount);
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
void __stdcall SBigRand(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    Rand(&pResult->tPrimary, &pA->tPrimary, &pB->tPrimary, &pResult->tStack);
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

// 0x00423380
static void __stdcall sub_00423380_FromBytes(BigBuffer* pThis, const unsigned char* pData, unsigned int nSize)
{
    pThis->SetCount(0);
    for (unsigned int i = 0; i < nSize; ++i)
    {
        unsigned int nIdx = i >> 2;
        unsigned int nShift = i & 3;
        unsigned int nByte = pData[i];
        unsigned int nCur = nShift ? pThis->Ref(nIdx) : 0;
        (*pThis)[nIdx] = (nByte << (nShift * 8)) + nCur;
    }
}

// 0x00423D60
void __stdcall SBigXor(D2StormBigStrc* pResult, D2StormBigStrc* pA, D2StormBigStrc* pB)
{
    BigXor(pResult->tPrimary, pA->tPrimary, pB->tPrimary);
}

// 0x00423D80
void BigStack::sub_00423D80_Release(BigBuffer* pResult, BigBuffer* pWork)
{
    if (pResult != pWork)
    {
        D2StormArrayViewStrc tView;
        tView.pData = pWork->m_array.m_data;
        tView.nCount = pWork->m_array.m_count;
        pResult->m_array.Set(tView.nCount, tView.pData);
        pResult->m_array.m_chunk = pWork->m_array.m_chunk;
        pResult->m_start = pWork->m_start;
        nUsed--;
    }
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

// 0x00422D00
static void __stdcall Shl(BigBuffer& a, const BigBuffer& b, unsigned int nShift)
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
            nValue = b[i - nWords] << nBits;
        if (i > nWords && nBits)
            nValue += b[i - nWords - 1] >> (32 - nBits);
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

// 0x00422FC0
static void __stdcall sub_00422FC0_SubUInt(BigBuffer& a, const BigBuffer& b, unsigned int c)
{
    unsigned __int64 nBorrow = ~(unsigned __int64)c + 1;
    unsigned int i = 0;
    unsigned int nCount;
    for (; nCount = b.m_array.m_count, b.m_start + i < nCount; i++)
    {
        nBorrow += b.m_start + i < nCount ? b.m_array.m_data[b.m_start + i] : 0;
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

// 0x004234F0
static void __stdcall FromStream(BigBuffer* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData)
{
    unsigned int nOffset;
    unsigned int nLength;
    sub_00420F80_DecodeLength(pData, nSize, &nOffset, &nLength);
    sub_00423380_FromBytes(pBuf, pData + nOffset, nLength);
    if (pnUsed)
        *pnUsed = nOffset + nLength;
}

// 0x00423540
static void __stdcall FromUnsigned(BigBuffer& a, unsigned int nValue)
{
    a[0u] = nValue;
    a.SetCount(1);
}

// 0x00423600
static void __stdcall ToStr(const BigBuffer& tNumber, D2StormArrayBStrc& tOutput, BigStack& tStack)
{
    BigBuffer& tBuffer = tStack.pRecords[tStack.nUsed++];
    tBuffer.CopyFrom(tNumber);
    tOutput.m_count = 0;
    do
    {
        unsigned int nDigit;
        sub_004225C0_DivUInt(&nDigit, tBuffer, 10, tBuffer);
        unsigned char nChar;
        unsigned char* pChar = &nChar;
        *pChar = (unsigned char)(nDigit + '0');
        tOutput.Add(1, pChar);
    } while (BigCompareUInt(tBuffer, 0));
    unsigned int nCount = tOutput.m_count;
    for (unsigned int i = 0; i < nCount / 2; i++)
    {
        unsigned char& nNear = tOutput.m_data[i];
        unsigned char& nFar = tOutput.m_data[nCount - i - 1];
        unsigned char nSwap = nNear;
        nNear = nFar;
        nFar = nSwap;
    }
    *tOutput.New() = 0;
    tStack.nUsed--;
}

// 0x00423800
void __stdcall SBigDec(D2StormBigStrc* pResult, D2StormBigStrc* pA)
{
    sub_00422FC0_SubUInt(pResult->tPrimary, pA->tPrimary, 1);
}

// 0x00423850
void __stdcall SBigFromBinary(D2StormBigStrc* pBig, const void* pData, unsigned int nSize)
{
    sub_00423380_FromBytes(&pBig->tPrimary, (const unsigned char*)pData, nSize);
}

// 0x00423870
void __stdcall SBigFromStr(D2StormBigStrc* pBig, const char* szString)
{
    FromStr(pBig->tPrimary, szString);
}

// 0x00423890
void __stdcall SBigFromStream(D2StormBigStrc* pBig, const void* pData, unsigned int nSize, unsigned int* pnUsed)
{
    FromStream(&pBig->tPrimary, pnUsed, nSize, (const unsigned char*)pData);
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
void __stdcall SBigToStrArray(D2StormBigStrc* pBig, TSGrowableArray<char>* pArray, int bAppend)
{
    ToStr(pBig->tPrimary, pBig->tOutput, pBig->tStack);
    if (bAppend)
        pArray->Add(pBig->tOutput.m_count, (const char*)pBig->tOutput.m_data);
    else
        pArray->Set(pBig->tOutput.m_count, (const char*)pBig->tOutput.m_data);
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

// 0x00423DC0
// 0x00423DC0
static void __stdcall Div(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigBuffer& d, BigStack& tStack)
{
    c.sub_00422140_Trim();
    d.sub_00422140_Trim();
    unsigned int nCCount = c.Count();
    unsigned int nDCount = d.Count();
    if (nDCount > nCCount)
    {
        b = c;
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

// 0x00424180
static void __stdcall Gcd(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack)
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
        pWork->m_array.Set(tView.nCount, tView.pData);
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

// 0x00424700
static void __stdcall Rand(BigBuffer* pResult, BigBuffer* pModulus, BigBuffer* pSeed, BigStack* pStack)
{
    BigBuffer& tMul = pStack->pRecords[pStack->nUsed++];
    BigBuffer& tTemp = pStack->pRecords[pStack->nUsed++];
    BigBuffer* pR; if (pResult) pR = pResult; else pR = pResult;
    BigBuffer* pS = pSeed;
    if (pR == pModulus || pR == pS)
        pR = &pStack->pRecords[pStack->nUsed++];
    if (pS == pModulus)
        pS = &pStack->pRecords[pStack->nUsed++];
    BigBuffer& r = *pR;
    BigBuffer& s = *pS;

    s.sub_00422140_Trim();
    int bReseed = s.Count() < 2;
    s.SetCount(2);
    if (bReseed)
    {
        for (unsigned int i = 0; i < 8; i++)
            ((unsigned char*)&s.Ref(0))[i] = gabSBigRandSeed[i];
    }

    tMul.SetCount(2);
    for (unsigned int i = 0; i < 8; i++)
        ((unsigned char*)&tMul.At(0))[i] = gabSBigRandMul[i];

    if (pSeed) pModulus->sub_00422140_Trim(); else pModulus->sub_00422140_Trim();
    r.SetCountInline(0);
    unsigned int nBits; if (pStack) nBits = pModulus->Count() * 32; else nBits = pModulus->Count() * 32;
    for (unsigned int k = 0; k < (nBits + 31) / 32; k++, nBits = pStack ? pModulus->Count() * 32 : pModulus->Count() * 32)
    {
        sub_004242C0_BigOp(&s, &s, &tMul, pStack);
        Shr(tTemp, s, 16);
        BigAdd(s, tTemp, s);
        s.SetCountInline(2);
        Shl(r, r, 32);
        BigAdd(r, r, s);
        Shr(tTemp, s, 32);
        BigAdd(r, r, tTemp);
    }
    Div(tTemp, r, r, *pModulus, *pStack);

    if (pSeed != &s)
    {
        pSeed->m_array.Set(s.m_array.m_count, s.m_array.m_data);
        pSeed->m_array.m_chunk = s.m_array.m_chunk;
        pSeed->m_start = s.m_start;
        pStack->nUsed--;
    }
    if (pResult != &r)
    {
        D2StormArrayViewStrc tView;
        tView.pData = r.m_array.m_data;
        tView.nCount = r.m_array.m_count;
        pResult->m_array.Set(tView.nCount, tView.pData);
        pResult->m_array.m_chunk = r.m_array.m_chunk;
        pResult->m_start = r.m_start;
        pStack->nUsed--;
    }
    pStack->nUsed -= 2;
}

// 0x00424F50
void __stdcall SBigPow(D2StormBigStrc* pResult, D2StormBigStrc* pBase, unsigned int nExp)
{
    Pow(&pResult->tPrimary, &pBase->tPrimary, nExp, &pResult->tStack);
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
                sub_00424B00_Square(&tWork, &tWork, &tStack);
                Div(tQuot, tWork, tWork, d, tStack);
                sub_00424B00_Square(&tWork, &tWork, &tStack);
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

// 0x004212F0
int __stdcall sub_004212F0_Compare(const BigBuffer* pLeft, const BigBuffer* pRight)
{
    int nResult = 0;
    for (unsigned int i = 0; pLeft->IsUsed(i) || pRight->IsUsed(i); ++i)
    {
        if ((*pLeft)[i] != (*pRight)[i])
            nResult = (*pLeft)[i] > (*pRight)[i] ? 1 : -1;
    }
    return nResult;
}

// 0x004213B0
unsigned int __stdcall BigHighBitIndex(BigBuffer* pQueue)
{
    unsigned int nCount = pQueue->m_array.m_count;
    unsigned int nStart = pQueue->m_start;
    unsigned int nWords = nCount - nStart;
    for (unsigned int i = nWords; i != 0; )
    {
        i--;
        if (nStart + i < nCount && pQueue->m_array.m_data[nStart + i])
        {
            unsigned int nMask = 0x80000000;
            for (unsigned int nBit = 32; nBit != 0; )
            {
                nBit--;
                if (pQueue->sub_004212D0_Get(i) & nMask)
                    return i * 32 + nBit;
                nMask >>= 1;
            }
        }
    }
    return 0;
}

// 0x00421440
static int BigIsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}

// 0x00421470
unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue)
{
    const unsigned int nStart = pQueue->m_start;
    unsigned int i = 0;
    const unsigned int nCount = pQueue->m_array.m_count - nStart;
    const unsigned int nUsed = pQueue->m_array.m_count;
    if (nCount)
    {
        unsigned int nPos = nStart;
        do
        {
            if (nPos < nUsed && pQueue->m_array.m_data[nStart + i])
            {
                unsigned int nMask = 1;
                for (unsigned int nBit = 0; nBit < 32; ++nBit, nMask <<= 1)
                {
                    if (pQueue->sub_004212D0_Get(i) & nMask)
                        return i * 32 + nBit;
                }
            }
            ++i;
            ++nPos;
        } while (i < nCount);
    }
    return 0;
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

// 0x00424FB0
static void __stdcall InvMod(BigBuffer& a, BigBuffer& b, BigBuffer& c, BigStack& tStack)
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

// 0x004235F0
static void ToBinary(D2StormArrayBStrc* pOut, BigBuffer* pIn)
{
    pOut->m_count = 0;
    sub_00421CB0_AppendDigits(pOut, pIn);
}

// 0x00423770
static void ToStream(D2StormArrayBStrc* pOut, BigBuffer* pIn)
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
        pArray->Add(pBig->tOutput.m_count, pBig->tOutput.m_data);
    else
        pArray->Set(pBig->tOutput.m_count, pBig->tOutput.m_data);
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
        pArray->Add(pBig->tOutput.m_count, pBig->tOutput.m_data);
    else
        pArray->Set(pBig->tOutput.m_count, pBig->tOutput.m_data);
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

extern "C" char gData_006F28F8[]; // 0x006F28F8

#pragma pack(push, 1)
struct d2data_00708874_t
{
    unsigned char b0[4];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00708880_t
{
    unsigned char b0[4];
    const void* p1;
    unsigned char b2[4];
};
#pragma pack(pop)

extern "C" struct d2data_00708874_t gData_00708874; // 0x00708874
extern "C" struct d2data_00708880_t gData_00708880; // 0x00708880
extern "C" const unsigned char gData_006CFF68[8]; // 0x006CFF68
extern "C" const unsigned int gData_006CFF70[1]; // 0x006CFF70
extern "C" const unsigned int gData_006CFF78[171]; // 0x006CFF78

extern "C" struct d2data_00708874_t gData_00708874 = {
    { 0x2E, 0x49 },
    (const void*)&gData_006F28F8,
    { 0x00 }
}; // 0x00708874
#pragma comment(linker, "/alternatename:?gszTypeNameUInt_00708874@@3PADA=_gData_00708874")

extern "C" struct d2data_00708880_t gData_00708880 = {
    { 0x2E, 0x45 },
    (const void*)&gData_006F28F8,
    { 0x00 }
}; // 0x00708880
#pragma comment(linker, "/alternatename:?gszTypeNameUChar_00708880@@3PADA=_gData_00708880")

extern char gszTypeNameChar_0070888C[4] = ".D"; // 0x0070888C

extern "C" const unsigned char gData_006CFF68[8] = { 0xB5, 0x3B, 0x12, 0x1F, 0xE5, 0x55, 0x9A, 0x15 }; // 0x006CFF68
#pragma comment(linker, "/alternatename:?gabSBigRandSeed_006CFF68@@3QBEB=_gData_006CFF68")

extern "C" const unsigned int gData_006CFF70[1] = { 2 }; // 0x006CFF70
#pragma comment(linker, "/alternatename:?gaSBigFermatBases@@3QBIB=_gData_006CFF70")

extern "C" const unsigned int gData_006CFF78[171] = {
    3, 5, 7, 0xB, 0xD, 0x11, 0x13, 0x17, 0x1D, 0x1F, 0x25, 0x29, 0x2B, 0x2F, 0x35, 0x3B,
    0x3D, 0x43, 0x47, 0x49, 0x4F, 0x53, 0x59, 0x61, 0x65, 0x67, 0x6B, 0x6D, 0x71, 0x7F, 0x83, 0x89,
    0x8B, 0x95, 0x97, 0x9D, 0xA3, 0xA7, 0xAD, 0xB3, 0xB5, 0xBF, 0xC1, 0xC5, 0xC7, 0xD3, 0xDF, 0xE3,
    0xE5, 0xE9, 0xEF, 0xF1, 0xFB, 0x101, 0x107, 0x10D, 0x10F, 0x115, 0x119, 0x11B, 0x125, 0x133, 0x137, 0x139,
    0x13D, 0x14B, 0x151, 0x15B, 0x15D, 0x161, 0x167, 0x16F, 0x175, 0x17B, 0x17F, 0x185, 0x18D, 0x191, 0x199, 0x1A3,
    0x1A5, 0x1AF, 0x1B1, 0x1B7, 0x1BB, 0x1C1, 0x1C9, 0x1CD, 0x1CF, 0x1D3, 0x1DF, 0x1E7, 0x1EB, 0x1F3, 0x1F7, 0x1FD,
    0x209, 0x20B, 0x21D, 0x223, 0x22D, 0x233, 0x239, 0x23B, 0x241, 0x24B, 0x251, 0x257, 0x259, 0x25F, 0x265, 0x269,
    0x26B, 0x277, 0x281, 0x283, 0x287, 0x28D, 0x293, 0x295, 0x2A1, 0x2A5, 0x2AB, 0x2B3, 0x2BD, 0x2C5, 0x2CF, 0x2D7,
    0x2DD, 0x2E3, 0x2E7, 0x2EF, 0x2F5, 0x2F9, 0x301, 0x305, 0x313, 0x31D, 0x329, 0x32B, 0x335, 0x337, 0x33B, 0x33D,
    0x347, 0x355, 0x359, 0x35B, 0x35F, 0x36D, 0x371, 0x373, 0x377, 0x38B, 0x38F, 0x397, 0x3A1, 0x3A9, 0x3AD, 0x3B3,
    0x3B9, 0x3C7, 0x3CB, 0x3D1, 0x3D7, 0x3DF, 0x3E5, 0x3F1, 0x3F5, 0x3FB, 0x3FD
}; // 0x006CFF78
#pragma comment(linker, "/alternatename:?gaSBigSmallPrimes@@3QBIB=_gData_006CFF78")
