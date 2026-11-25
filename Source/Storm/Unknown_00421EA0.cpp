#include "D2StormAutoLink.h"
#include "D2StormSha1.h"
#define DECODE_LENGTH sub_00420F80_DecodeLength
#define FROM_BINARY sub_00423380_FromBinary
#define FROM_LENGTH_PREFIXED FromStream

struct D2GameStrc;
struct D2StormArrayAStrc;
struct BigBuffer;
struct D2StormBigStrc;
struct BigStack;
struct D2StormArrayBStrc;
struct D2GameLinkStrc;
struct D2StormListAStrc;
struct D2StormGameArrayStrc;
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300

struct D2StormArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;
    unsigned int sub_004210A0_CalcChunkSize(unsigned int nCount);                                           // 0x004210A0
    void sub_004215C0_Set(unsigned int nCount, const unsigned int* pData);                                  // 0x004215C0
    void sub_004216E0_ReallocData(unsigned int nAlloc);                                                     // 0x004216E0
    void sub_00421EA0_GrowToFit(unsigned int nIndex, int bZero);
    void SetCount(unsigned int nCount);
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
    void SetCountReserve(unsigned int nCount)
    {
        if (nCount > m_count)
            Reserve(nCount - m_count, 1);
        m_count = nCount;
    }
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;
    void GrowToFit(int nIndex);                                                                // 0x00421FE0
    unsigned int* sub_00422050_At(unsigned int nIndex);
    void sub_00422120_SetStart(unsigned int nStart);
    BigBuffer& operator=(const BigBuffer& tSource);
    void sub_00422080_TrimToStart();
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
    void sub_00422140_Trim();                                                                               // 0x00422140
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

struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);                         // 0x004218B0
    void sub_004219F0_Set(unsigned int nCount, const unsigned char* pData);                                 // 0x004219F0

    void Reserve(unsigned int nCount)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk ? m_chunk : sub_00421160_CalcChunkSize(nCount);
            unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nCount += nChunk - nRemainder;
            sub_004211C0_ReallocData(nCount);
        }
    }
    unsigned char* New()
    {
        Reserve(1);
        unsigned char* pSlot = m_data + m_count;
        m_count += 1;
        return pSlot;
    }
    void Push(const unsigned char& nByte)
    {
        Reserve(1);
        m_data[m_count] = nByte;
        m_count += 1;
    }
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
};

struct D2StormBigStrc
{
    BigBuffer tQueue;
    BigStack tStack;
    D2StormArrayBStrc tBuffer;
    ~D2StormBigStrc();                                                                                      // 0x00421D80
    static void operator delete(void* pMemory);
};

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0
void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, BigBuffer* pIn); // 0x00421CB0
int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2GameLinkStrc
{
    D2GameLinkStrc* pPrevLink;
    D2GameStrc* pNext;
};

struct D2GameStrc
{
    unsigned int dwHashValue;
    D2GameLinkStrc tLinkToSlot;
    D2GameLinkStrc tLinkToFull;
    char unk0x14[0x1DE0];

    ~D2GameStrc();                                                                                          // 0x0044F820
    static void operator delete(void* pMemory);
};

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    ~D2StormListAStrc();
    void UnlinkAll();                                                                                       // 0x0044F8E0
    static void operator delete(void* pMemory);
};

struct D2StormGameArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2GameStrc* m_data;
    unsigned int m_chunk;

    ~D2StormGameArrayStrc();                                                                                // 0x0044FD80
};

static void __cdecl sub_00420F80_DecodeLength(const unsigned char* pData, unsigned int nSize, unsigned int* pnOffset, unsigned int* pnLength);
static void __stdcall sub_00423380_FromBinary(const unsigned char* pData, unsigned int nCount, BigBuffer* pBuf);
static void __stdcall FromStream(BigBuffer* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData);

// build: symbol ??4BigBuffer@@QAEAAU0@ABU0@@Z 0x004221B0
// 0x00421EA0
void D2StormArrayAStrc::sub_00421EA0_GrowToFit(unsigned int nIndex, int bZero)
{
    if (nIndex >= m_count)
    {
        unsigned int nCount = nIndex + 1;
        if (nCount > m_alloc)
        {
            unsigned int nChunk = m_chunk;
            if (!nChunk)
                nChunk = sub_004210A0_CalcChunkSize(nCount);
            unsigned int nAlloc = nCount;
            const unsigned int nRemainder = nCount % nChunk;
            if (nRemainder)
                nAlloc = nCount + nChunk - nRemainder;
            sub_004216E0_ReallocData(nAlloc);
        }
        if (bZero)
            SMemZero(&m_data[m_count], (nIndex - m_count + 1) * sizeof(unsigned int));
        m_count = nCount;
    }
}

// 0x00422050
unsigned int* BigBuffer::sub_00422050_At(unsigned int nIndex)
{
    GrowToFit(nIndex);
    return &m_array.m_data[m_start + nIndex];
}

// 0x00422120
void BigBuffer::sub_00422120_SetStart(unsigned int nStart)
{
    m_start = nStart;
    if (nStart)
        GrowToFit(-1);
}

// 0x004221B0
BigBuffer& BigBuffer::operator=(const BigBuffer& tSource)
{
    if (this != &tSource)
        m_array.sub_004215C0_Set(tSource.m_array.m_count, tSource.m_array.m_data);
    m_array.m_chunk = tSource.m_array.m_chunk;
    m_start = tSource.m_start;
    return *this;
}

// 0x00422080
void BigBuffer::sub_00422080_TrimToStart()
{
    m_array.SetCountReserve(m_start);
}

inline unsigned int D2StormArrayBStrc::sub_00421160_CalcChunkSize(unsigned int nCount)
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

unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
}

static void EncodeDataBytes(D2StormArrayBStrc* pArray, unsigned int nValue) // 0x00421BD0
{
    while (nValue)
    {
        unsigned char* pSlot = pArray->New();
        *pSlot = (unsigned char)(nValue % 255);
        nValue /= 255;
    }
    pArray->Push(0xFF);
}

static void ToBinary(D2StormArrayBStrc* pOut, BigBuffer* pIn) // 0x004235F0
{
    pOut->m_count = 0;
    sub_00421CB0_AppendDigits(pOut, pIn);
}

// 0x00423770
static void ToStream(D2StormArrayBStrc* pOut, BigBuffer* pIn)
{
    ToBinary(pOut, pIn);
    EncodeDataBytes(pOut, pOut->m_count);
    sub_00421CB0_AppendDigits(pOut, pIn);
}

void __stdcall SBigToBinaryArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    ToBinary(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
}

void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead)
{
    D2StormBigStrc* pBig = (D2StormBigStrc*)hBig;
    ToBinary(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.m_count < nSize ? pBig->tBuffer.m_count : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.m_data, nCopy);
    if (pRead)
        *pRead = nCopy;
}

void __stdcall SBigToBinaryPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    ToBinary(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.m_data;
    if (pSize)
        *pSize = pBig->tBuffer.m_count;
}

void __stdcall SBigToStreamArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    ToStream(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
}

void __stdcall SBigToStreamBuffer(D2StormBigStrc* pBig, void* pBuffer, unsigned int nSize, unsigned int* pWritten)
{
    ToStream(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.m_count < nSize ? pBig->tBuffer.m_count : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.m_data, nCopy);
    if (pWritten)
        *pWritten = nCopy;
}

void __stdcall SBigToStreamPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    ToStream(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.m_data;
    *pSize = pBig->tBuffer.m_count;
}

// build: symbol ??_GD2StormBigStrc@@QAEPAXI@Z 0x00423820
// 0x00423820
inline void D2StormBigStrc::operator delete(void* pMemory)
{
    if (pMemory)
        SMemFree(pMemory, "delete", -1, 0);
}

void sub_Emit_D2StormBigStrc(D2StormBigStrc* p)
{
    delete p;
}

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

static void __stdcall FromStream(BigBuffer* pBuf, unsigned int* pnUsed, unsigned int nSize, const unsigned char* pData) // 0x004234F0
{
    unsigned int nOffset;
    unsigned int nLength;
    DECODE_LENGTH(pData, nSize, &nOffset, &nLength);
    FROM_BINARY(pData + nOffset, nLength, pBuf);
    if (pnUsed)
        *pnUsed = nOffset + nLength;
}

// 0x00423890
void __stdcall SBigFromStream(void* hBig, const void* pData, unsigned int nSize, unsigned int* pnUsed)
{
    FROM_LENGTH_PREFIXED((BigBuffer*)hBig, pnUsed, nSize, (const unsigned char*)pData);
}

// 0x00426160
unsigned int __fastcall sub_00426160_GetTableSize(unsigned int nCount)
{
    unsigned int nSize = 1;
    const unsigned int nLimit = 2 * nCount + 2;
    while (nSize <= nLimit)
        nSize += nSize;
    return nSize;
}
