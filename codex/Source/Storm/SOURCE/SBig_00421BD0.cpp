#include "D2StormSha1.h"
struct BigStack;
struct D2StormArrayBStrc;
struct D2StormBigStrc;

void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

#include "D2StormBigBuffer.h"


struct D2StormArrayBStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned char* m_data;
    unsigned int m_chunk;

    unsigned int sub_00421160_CalcChunkSize(unsigned int nCount);                                           // 0x00421160
    void sub_004211C0_ReallocData(unsigned int nAlloc);                                                     // 0x004211C0
    unsigned int sub_004218B0_Add(unsigned int nCount, const unsigned char* pData);                         // 0x004218B0
    void sub_004219F0_Set(unsigned int nCount, const unsigned char* pData);                                 // 0x004219F0

    unsigned int RoundUp(unsigned int nValue, unsigned int nAlign)
    {
        unsigned int nRemainder = nValue % nAlign;
        if (nRemainder)
            nValue += nAlign - nRemainder;
        return nValue;
    }
    void InlineReserve(unsigned int nCount, int bRound)
    {
        nCount += m_count;
        if (nCount > m_alloc)
        {
            if (bRound)
            {
                unsigned int nChunk = m_chunk;
                if (!nChunk)
                    nChunk = sub_00421160_CalcChunkSize(nCount);
                nCount = RoundUp(nCount, nChunk);
            }
            sub_004211C0_ReallocData(nCount);
        }
    }
    unsigned char* New()
    {
        InlineReserve(1, 1);
        return &m_data[m_count++];
    }
    unsigned int sub_004219D0_AddOne(const unsigned char* pData);
};

struct D2StormBigStrc
{
    BigBuffer tQueue;
    BigStack tStack;
    D2StormArrayBStrc tBuffer;
};


void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, BigBuffer* pIn); // 0x00421CB0
void __stdcall SMemZero(void* pLocation, unsigned int nLength); // 0x0041D300
extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);



// 0x00421160
inline unsigned int D2StormArrayBStrc::sub_00421160_CalcChunkSize(unsigned int nCount)
{
    if (nCount < 0x100)
    {
        while (nCount & (nCount - 1))
            nCount &= nCount - 1;
        return nCount < 1 ? 1 : nCount;
    }
    m_chunk = 0x100;
    return 0x100;
}

// 0x004219D0
unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
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

void ToBinary(D2StormArrayBStrc* pOut, BigBuffer* pIn); // 0x004235F0
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
    ToBinary(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
}

// 0x00423B30
void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead)
{
    D2StormBigStrc* pBig = (D2StormBigStrc*)hBig;
    ToBinary(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.m_count < nSize ? pBig->tBuffer.m_count : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.m_data, nCopy);
    if (pRead)
        *pRead = nCopy;
}

// 0x00423B80
void __stdcall SBigToBinaryPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    ToBinary(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.m_data;
    if (pSize)
        *pSize = pBig->tBuffer.m_count;
}

// 0x00423C90
void __stdcall SBigToStreamArray(D2StormBigStrc* pBig, D2StormArrayBStrc* pArray, int bAppend)
{
    ToStream(&pBig->tBuffer, &pBig->tQueue);
    if (bAppend)
        pArray->sub_004218B0_Add(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
    else
        pArray->sub_004219F0_Set(pBig->tBuffer.m_count, pBig->tBuffer.m_data);
}

// 0x00423CE0
void __stdcall SBigToStreamBuffer(D2StormBigStrc* pBig, void* pBuffer, unsigned int nSize, unsigned int* pWritten)
{
    ToStream(&pBig->tBuffer, &pBig->tQueue);
    unsigned int nCopy = pBig->tBuffer.m_count < nSize ? pBig->tBuffer.m_count : nSize;
    SMemCopy(pBuffer, pBig->tBuffer.m_data, nCopy);
    if (pWritten)
        *pWritten = nCopy;
}

// 0x00423D30
void __stdcall SBigToStreamPtr(D2StormBigStrc* pBig, unsigned char** ppData, unsigned int* pSize)
{
    ToStream(&pBig->tBuffer, &pBig->tQueue);
    *ppData = pBig->tBuffer.m_data;
    *pSize = pBig->tBuffer.m_count;
}

static inline void ReserveCount(D2StormArrayAStrc* pArray, unsigned int nCount)
{
    if (nCount > pArray->m_alloc)
    {
        unsigned int nChunk = pArray->m_chunk;
        if (!nChunk)
        {
            nChunk = pArray->sub_004210A0_CalcChunkSize(nCount);
        }
        unsigned int nNew = nCount;
        unsigned int nRem = nCount % nChunk;
        if (nRem)
        {
            nNew = nCount + (nChunk - nRem);
        }
        pArray->sub_004216E0_ReallocData(nNew);
    }
}

// 0x00423380
static void __stdcall sub_00423380_FromBytes(BigBuffer* pThis, const unsigned char* pData, unsigned int nSize)
{
    unsigned int nStart = pThis->m_start;
    if (nStart > pThis->m_array.m_count)
    {
        ReserveCount(&pThis->m_array, nStart);
    }
    pThis->m_array.m_count = nStart;

    for (unsigned int i = 0; i < nSize; ++i)
    {
        unsigned int nIdx = i >> 2;
        unsigned int nShift = i & 3;
        unsigned int nByte = pData[i];
        unsigned int nCur;
        if (nShift)
        {
            pThis->GrowToFit(nIdx);
            nCur = pThis->m_array.m_data[pThis->m_start + nIdx];
        }
        else
        {
            nCur = 0;
        }
        unsigned int nPos = pThis->m_start + nIdx;
        if (nPos >= pThis->m_array.m_count)
        {
            unsigned int nNewCount = nPos + 1;
            ReserveCount(&pThis->m_array, nNewCount);
            SMemZero(&pThis->m_array.m_data[pThis->m_array.m_count], (nPos - pThis->m_array.m_count) * 4 + 4);
            pThis->m_array.m_count = nNewCount;
        }
        pThis->m_array.m_data[pThis->m_start + nIdx] = (nByte << (nShift * 8)) + nCur;
    }
}

// 0x00423850
void __stdcall sub_00423850(BigBuffer* pThis, const unsigned char* pData, unsigned int nSize)
{
    sub_00423380_FromBytes(pThis, pData, nSize);
}

// 0x00425720
inline unsigned int __fastcall sub_00425720_Rotl(unsigned int nValue, int nShift)
{
    return _rotl(nValue, nShift);
}

// 0x00425730
inline void __fastcall sub_00425730_Sha1Round0(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + ((*b & c) | (~*b & d)) + *w + 0x5A827999;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x00425770
inline void __fastcall sub_00425770_Sha1Round1(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + (*b ^ c ^ d) + *w + 0x6ED9EBA1;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x004257B0
inline void __fastcall sub_004257B0_Sha1Round2(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + ((*b & c) | (*b & d) | (c & d)) + *w + 0x8F1BBCDC;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x004257F0
inline void __fastcall sub_004257F0_Sha1Round3(unsigned int a, unsigned int* b, unsigned int c, unsigned int d, unsigned int* e, unsigned int* w)
{
    *e += sub_00425720_Rotl(a, 5) + (*b ^ c ^ d) + *w + 0xCA62C1D6;
    *b = sub_00425720_Rotl(*b, 30);
    *w = 0;
}

// 0x00425830
inline void __fastcall sub_00425830_LoadBE32(unsigned int* pOut, const unsigned char* pIn)
{
    *pOut = ((((pIn[0] << 8) | pIn[1]) << 8 | pIn[2]) << 8) | pIn[3];
}

void __fastcall sub_00425850_Sha1Transform(unsigned int* pState, const unsigned char* pBlock); // 0x00425850

// 0x00425DD0
void Sha1::Append(const unsigned char* pData, unsigned int nLen)
{
    unsigned int nUsed = (unsigned int)nBitCount >> 3 & 0x3F;
    nBitCount += (unsigned __int64)nLen * 8;
    if (nUsed)
    {
        nLen += nUsed;
        pData -= nUsed;
        if (nLen >= 64)
        {
            for (; nUsed < 64; nUsed++)
                aBlock[nUsed] = pData[nUsed];
            sub_00425850_Sha1Transform(aState, aBlock);
            nLen -= 64;
            pData += 64;
            nUsed = 0;
        }
    }
    while (nLen >= 64)
    {
        sub_00425850_Sha1Transform(aState, pData);
        nLen -= 64;
        pData += 64;
    }
    for (; nUsed < nLen; nUsed++)
        aBlock[nUsed] = pData[nUsed];
}

// 0x00425E80
void __fastcall sub_00425E80_PutBE64(unsigned char* pOut, unsigned __int64 nValue)
{
    pOut[7] = (unsigned char)nValue; nValue >>= 8;
    pOut[6] = (unsigned char)nValue; nValue >>= 8;
    pOut[5] = (unsigned char)nValue; nValue >>= 8;
    pOut[4] = (unsigned char)nValue; nValue >>= 8;
    pOut[3] = (unsigned char)nValue; nValue >>= 8;
    pOut[2] = (unsigned char)nValue; nValue >>= 8;
    pOut[1] = (unsigned char)nValue; nValue >>= 8;
    pOut[0] = (unsigned char)nValue;
}
