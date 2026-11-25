#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormBitOutput.h"
#define DECODE_LENGTH sub_00420F80_DecodeLength
#define FROM_BINARY sub_00423380_FromBinary
#define FROM_LENGTH_PREFIXED FromStream

struct HUFFNODE;
struct UiContext;
struct D2StormLinkStrc;
struct D2IdentityView;
struct D2StormNodeListStrc;
class THuffmannTree;
class CHuffmanEncoder;
class CHuffmanDecoder;
struct D2StormHuffInputStrc;
struct CHuffman;
struct D2CriticalSectionStrc;
struct Entry;
struct SlotArray;
struct D2Field14Strc;
struct D2UnitStrc;
struct BigBuffer;
struct BigStack;
struct LimbCell;
struct SequenceView;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;
    char* m_next;
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
    }
    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
    D2StormLinkStrc();
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2IdentityView {
 D2StormLinkStrc link;
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    void sub_0041EE40_UnlinkAll();
    void sub_0041F460_Destroy();
};

class THuffmannTree
{
public:
    THuffmannTree();
    ~THuffmannTree();

    unsigned int adwData[0x3474 / 4];
};

class CHuffmanEncoder : public THuffmannTree
{
public:
    CHuffmanEncoder();
    ~CHuffmanEncoder();
};

class CHuffmanDecoder : public THuffmannTree
{
public:
    ~CHuffmanDecoder();
};

struct D2StormHuffInputStrc
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    unsigned int Get8Bits()
    {
        if (nBitCount <= 8)
        {
            nBitBuffer |= *(unsigned short*)pInput << nBitCount;
            nBitCount += 16;
            pInput += 2;
        }
        unsigned int nValue = nBitBuffer & 0xFF;
        nBitBuffer >>= 8;
        nBitCount -= 8;
        return nValue;
    }
};

struct CHuffman
{
    int bIsCmp0;
    int unk0x04;
    unsigned int unk0x08[0xC19];
    HUFFNODE* pItemsByValue[0x102];
    void BuildTree(unsigned char nCmpType);                                                    // 0x0041EF20
    unsigned int sub_0041EBC0_DecodeOne(D2StormHuffInputStrc* pInput);                                      // 0x0041EBC0
    void AddSymbol(unsigned int nValue);                                                    // 0x0041F510
    void sub_0041F350_IncWeights(HUFFNODE* pItem);                                               // 0x0041F350
    unsigned int Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput); // 0x0041F740
    void sub_0041D9E0_EncodeOne(CBitOutput* pOutput, unsigned int nValue);                       // 0x0041D9E0
    unsigned int Compress(CBitOutput* pOutput, void* pvIn, int cbIn, unsigned char nCmpType); // 0x0041F850
};

struct Entry { unsigned char data[20]; };

enum { KEEP_EXISTING = 0 };

struct SlotArray {
    Entry slots[16];
    int count;
    Entry* sub_00420E10(Entry* existing,int mode);
};

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

#include "D2StormArrayA.h"

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;
    void GrowToFit(int nIndex);                                                                // 0x00421FE0

    unsigned int sub_004212D0_Get(unsigned int nIndex);                                                      // 0x004212D0

    unsigned int GetInline(unsigned int nIndex)
    {
        const unsigned int nPosition = m_start + nIndex;
        return nPosition < m_array.m_count ? m_array.m_data[nPosition] : 0;
    }
    void SetCountInline(unsigned int nCount)
    {
        if (nCount > m_array.m_count && nCount > m_array.m_alloc)
        {
            unsigned int nChunk = m_array.m_chunk;
            if (!nChunk)
                nChunk = m_array.sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            m_array.sub_004216E0_ReallocData(nAlloc);
        }
        m_array.m_count = nCount;
    }
    unsigned int ChunkSizeInline(unsigned int nCount)
    {
        if (nCount < 0x40)
        {
            unsigned int nResult = nCount;
            while (nResult & (nResult - 1))
                nResult &= nResult - 1;
            return nResult < 1 ? 1 : nResult;
        }
        m_array.m_chunk = 0x40;
        return 0x40;
    }
    void GrowToFitInline(unsigned int nIndex)
    {
        const unsigned int nPosition = m_start + nIndex;
        if (nPosition >= m_array.m_count)
        {
            const unsigned int nNewCount = nPosition + 1;
            if (nNewCount > m_array.m_alloc)
            {
                const unsigned int nChunk = m_array.m_chunk ? m_array.m_chunk : ChunkSizeInline(nNewCount);
                unsigned int nAlloc = nNewCount;
                const unsigned int nRemainder = nNewCount % nChunk;
                if (nRemainder)
                    nAlloc = nNewCount + nChunk - nRemainder;
                m_array.sub_004216E0_ReallocData(nAlloc);
            }
            SMemZero(&m_array.m_data[m_array.m_count], (nPosition - m_array.m_count + 1) * sizeof(unsigned int));
            m_array.m_count = nNewCount;
        }
    }
    unsigned int& AtInline(unsigned int nIndex)
    {
        GrowToFitInline(nIndex);
        return m_array.m_data[m_start + nIndex];
    }
    static unsigned int __stdcall RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void InlineSetCount(unsigned int nCount)
    {
        if (nCount > m_array.m_count && nCount > m_array.m_alloc)
        {
            unsigned int nChunk = m_array.m_chunk;
            if (!nChunk)
                nChunk = m_array.sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            m_array.sub_004216E0_ReallocData(nAlloc);
        }
        m_array.m_count = nCount;
    }
    void InlineGrowToFit(int nIndex)
    {
        unsigned int nPosition = m_start + nIndex;
        if (nPosition >= m_array.m_count)
        {
            unsigned int nNewCount = nPosition + 1;
            if (nNewCount > m_array.m_alloc)
            {
                unsigned int nChunk = m_array.m_chunk ? m_array.m_chunk : m_array.sub_004210A0_CalcChunkSize(nNewCount);
                m_array.sub_004216E0_ReallocData(RoundUp(nNewCount, nChunk));
            }
            SMemZero(&m_array.m_data[m_array.m_count], (nPosition - m_array.m_count + 1) * sizeof(unsigned int));
            m_array.m_count = nNewCount;
        }
    }
    unsigned int& Get(unsigned int nIndex)
    {
        GrowToFit(nIndex);
        return m_array.m_data[m_start + nIndex];
    }
    unsigned int& At(unsigned int nIndex)
    {
        InlineGrowToFit(nIndex);
        return m_array.m_data[m_start + nIndex];
    }
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;
};

struct LimbCell
{
    unsigned int value;
};

struct SequenceView
{
    char prefix[0x4];
    unsigned int count;
    LimbCell* values;
    char gap[0x4];
    unsigned int cursor;
};

static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength);
static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, BigBuffer* pBuf);
static void __stdcall FromStream(BigBuffer* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData); // 0x004234F0

// build: symbol ??0THuffmannTree@@QAE@XZ 0x0041F4A0
// build: symbol ??1THuffmannTree@@QAE@XZ 0x0041F6A0
// 0x0041F460
void D2StormNodeListStrc::sub_0041F460_Destroy()
{
    sub_0041EE40_UnlinkAll();
    m_terminator.Unlink();
}

// 0x0041F920
CHuffmanEncoder::CHuffmanEncoder()
{
}

// 0x0041F930
CHuffmanEncoder::~CHuffmanEncoder()
{
}

// 0x0041F940
CHuffmanDecoder::~CHuffmanDecoder()
{
}

// 0x0041F740
unsigned int CHuffman::Decompress(void* pOutput, unsigned int nOutputSize, D2StormHuffInputStrc* pInput)
{
    if (!nOutputSize)
    {
        return 0;
    }
    unsigned char nType = pInput->Get8Bits();
    BuildTree(nType);
    bIsCmp0 = nType == 0;
    unsigned char* pbOut = (unsigned char*)pOutput;
    for (;;)
    {
        unsigned int nValue = sub_0041EBC0_DecodeOne(pInput);
        if (nValue == 0x101)
        {
            nValue = pInput->Get8Bits();
            AddSymbol(nValue);
            if (!bIsCmp0)
            {
                sub_0041F350_IncWeights(pItemsByValue[nValue]);
            }
        }
        if (nValue == 0x100)
        {
            return (unsigned int)(pbOut - (unsigned char*)pOutput);
        }
        *pbOut++ = (unsigned char)nValue;
        if (--nOutputSize == 0)
        {
            return (unsigned int)(pbOut - (unsigned char*)pOutput);
        }
        if (bIsCmp0)
        {
            sub_0041F350_IncWeights(pItemsByValue[nValue]);
        }
    }
}

// build: symbol ?Flush@* 0x0041D9A0
void CBitOutput::Flush()
{
    while (nBitCount)
    {
        if (nBytesLeft)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            nBytesLeft--;
        }
        nBitBuffer >>= 8;
        nBitCount -= nBitCount > 8 ? 8 : nBitCount;
    }
}

// 0x0041F850
unsigned int CHuffman::Compress(CBitOutput* pOutput, void* pvIn, int cbIn, unsigned char nCmpType)
{
    BuildTree(nCmpType);
    bIsCmp0 = nCmpType == 0;
    pOutput->sub_0041D950_PutBits(nCmpType, 8);
    unsigned char* pbIn = (unsigned char*)pvIn;
    while (cbIn != 0)
    {
        unsigned int nValue = *pbIn++;
        cbIn--;
        if (pItemsByValue[nValue] == 0)
        {
            sub_0041D9E0_EncodeOne(pOutput, 0x101);
            pOutput->sub_0041D950_PutBits(nValue, 8);
            AddSymbol(nValue);
            if (!bIsCmp0)
            {
                sub_0041F350_IncWeights(pItemsByValue[nValue]);
            }
        }
        else
        {
            sub_0041D9E0_EncodeOne(pOutput, nValue);
        }
        if (bIsCmp0)
        {
            sub_0041F350_IncWeights(pItemsByValue[nValue]);
        }
    }
    sub_0041D9E0_EncodeOne(pOutput, 0x100);
    pOutput->Flush();
    return pOutput->sub_0041D940_GetSize();
}

// 0x00420E10
Entry* SlotArray::sub_00420E10(Entry* existing,int mode)
{
    if(mode != KEEP_EXISTING) return &slots[count++];
    return existing;
}

// 0x00420E40
D2StormLinkStrc* __fastcall sub_00420E40_Identity(D2IdentityView* value) {return &value->link;}

// 0x00420E50
extern "C" void* __fastcall sub_00420E50(void* value) { return value; }

// 0x00420E60
int* __fastcall MONSTERMODE_GetTargetTimerPtr(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

static inline int MONSTERMODE_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

void __fastcall sub_M111_Emit_005A64F0(D2UnitStrc* pUnit, int* pResult)
{
    *pResult = MONSTERMODE_IsActionFrame(pUnit) + 1;
}

// 0x00420EB0
static unsigned int __stdcall sub_00420EB0_Accumulate64(unsigned __int64 nValue, unsigned __int64* pAccumulator)
{
    *pAccumulator += nValue;
    const unsigned __int64 nCarry = *pAccumulator < nValue ? 1ui64 : 0ui64;
    const unsigned int nLow = (unsigned int)*pAccumulator;
    *pAccumulator >>= 32;
    *pAccumulator += nCarry * 0x100000000ui64;
    return nLow;
}

void __stdcall sub_00424B00_BigSquare(BigBuffer* pResult, BigBuffer* pA, BigStack* pStack)
{
    BigBuffer* pWork;
    if (pResult == pA)
        pWork = &pStack->pRecords[pStack->nUsed++];
    else
        pWork = pResult;

    pWork->SetCountInline(pWork->m_start);

    for (unsigned int i = 0; pA->m_start + i < pA->m_array.m_count; i++)
    {
        unsigned __int64 nCarry = 0;
        unsigned int j;
        for (j = 0; j <= i; j++)
        {
            const unsigned int nDigit = pA->GetInline(j);
            const unsigned __int64 nProduct = (unsigned __int64)pA->sub_004212D0_Get(i) * nDigit;
            const unsigned int k = j + i;
            const unsigned __int64 nSum = pWork->AtInline(k) + nProduct;
            if (j < i)
                nCarry += nProduct;
            unsigned int& rDigit = pWork->AtInline(k);
            rDigit = sub_00420EB0_Accumulate64(nSum, &nCarry);
        }
        pWork->AtInline(j + i) = (unsigned int)nCarry;
    }

    if (pResult != pWork)
    {
        pResult->m_array.sub_004215C0_Set(pWork->m_array.m_count, pWork->m_array.m_data);
        pResult->m_array.m_chunk = pWork->m_array.m_chunk;
        pResult->m_start = pWork->m_start;
        pStack->nUsed--;
    }
}

// 0x00420F30
static void __stdcall sub_00420F30_BigMulAddDigit(unsigned __int64* pAcc, unsigned int nDigit)
{
    *pAcc = *pAcc * 0x100000000ui64 + nDigit;
}

void __stdcall sub_K01_Emit_00420F30(unsigned __int64* pAcc, unsigned int nDigit)
{
    sub_00420F30_BigMulAddDigit(pAcc, nDigit);
}

// 0x00420F60
static unsigned __int64 __stdcall sub_00420F60_BigJoinDigits(unsigned int nHigh, unsigned int nLow)
{
    return (unsigned __int64)nHigh * 0x100000000ui64 + nLow;
}

unsigned __int64 __stdcall sub_K01_Emit_00420F60(unsigned int nHigh, unsigned int nLow)
{
    return sub_00420F60_BigJoinDigits(nHigh, nLow);
}

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

static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, BigBuffer* pBuf)
{
    pBuf->InlineSetCount(pBuf->m_start);
    for (unsigned int i = 0; i < nCount; i++)
    {
        unsigned int nByte = pData[i];
        unsigned int nWord = i >> 2;
        unsigned int nShift = i & 3;
        pBuf->At(nWord) = (nByte << (nShift * 8)) + (nShift ? pBuf->Get(nWord) : 0);
    }
}

// 0x004234F0
static void __stdcall FromStream(BigBuffer* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData)
{
    unsigned int nOffset;
    unsigned int nLength;
    DECODE_LENGTH(pData, nSize, &nOffset, &nLength);
    FROM_BINARY(pData + nOffset, nLength, pBuf);
    if (pnUsed)
        *pnUsed = nOffset + nLength;
}

// 0x00423850
void __stdcall sub_00423850(void* hBig, const void* pData, unsigned int nSize)
{
    FROM_BINARY((const unsigned char*)pData, nSize, (BigBuffer*)hBig);
}

void __stdcall SBigFromStream(void* hBig, const void* pData, unsigned int nSize, unsigned int* pnUsed)
{
    FROM_LENGTH_PREFIXED((BigBuffer*)hBig, pnUsed, nSize, (const unsigned char*)pData);
}

// 0x00420FE0
extern "C" LimbCell* __fastcall sub_00420FE0_LastCell(SequenceView* sequence)
{
    unsigned int count = sequence->count;
    if (count)
        return sequence->values + count - 1;
    return 0;
}
