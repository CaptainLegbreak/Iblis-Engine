#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"

struct UiContext;
struct D2StormLinkStrc;
struct D2IdentityView;
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

struct Entry { unsigned char data[20]; };

enum { KEEP_EXISTING = 0 };

struct SlotArray {
    Entry slots[16];
    int count;
    Entry* sub_00420E10(Entry* existing,int mode);
};

void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

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
                nChunk = m_array.CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            m_array.ReallocData(nAlloc);
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
                m_array.ReallocData(nAlloc);
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
                nChunk = m_array.CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            m_array.ReallocData(nAlloc);
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
                unsigned int nChunk = m_array.m_chunk ? m_array.m_chunk : m_array.CalcChunkSize(nNewCount);
                m_array.ReallocData(RoundUp(nNewCount, nChunk));
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

struct D2Strc00420E80
{
    char pad0x00[0x158];
    char tField158;
    void* sub_00420E80_GetField158();
};

// 0x00420E80
void* D2Strc00420E80::sub_00420E80_GetField158()
{
    return &tField158;
}

// 0x00420E90
static inline unsigned int sub_00420E90_TakeLow32(unsigned __int64* pValue)
{
    const unsigned int nLow = (unsigned int)*pValue;
    *pValue >>= 32;
    return nLow;
}

// 0x00420F00
static inline unsigned int sub_00420F00_TakeLow32Ext(unsigned __int64* pValue)
{
    const unsigned int nLow = (unsigned int)*pValue;
    *pValue >>= 32;
    if (*pValue >= 0x80000000)
    {
        *pValue |= 0xFFFFFFFF00000000ull;
    }
    return nLow;
}

unsigned int __fastcall sub_M119_Emit_00420E90(unsigned __int64* pValue, int nOther)
{
    return sub_00420E90_TakeLow32(pValue) + sub_00420F00_TakeLow32Ext((unsigned __int64*)nOther);
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
        pResult->m_array.Set(pWork->m_array.m_count, pWork->m_array.m_data);
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

// 0x00420FE0
extern "C" LimbCell* __fastcall sub_00420FE0_LastCell(SequenceView* sequence)
{
    unsigned int count = sequence->count;
    if (count)
        return sequence->values + count - 1;
    return 0;
}
