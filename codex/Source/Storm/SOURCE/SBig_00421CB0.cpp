void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2A0

struct D2StormArrayAStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    unsigned int* m_data;
    unsigned int m_chunk;

    unsigned int Count() const
    {
        return m_count;
    }
};

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    unsigned int Count() const
    {
        return m_array.Count() - m_start;
    }
    unsigned int operator[](unsigned int nIndex) const
    {
        nIndex += m_start;
        return nIndex < m_array.Count() ? m_array.m_data[nIndex] : 0;
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

struct D2StormBigStrc
{
    BigBuffer tQueue;
    BigStack tStack;
    D2StormArrayBStrc tBuffer;
};

static void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, BigBuffer* pIn);

// 0x00421CB0
static void __stdcall sub_00421CB0_AppendDigits(D2StormArrayBStrc* pOut, BigBuffer* pIn)
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

// 0x004219D0
unsigned int D2StormArrayBStrc::sub_004219D0_AddOne(const unsigned char* pData)
{
    return sub_004218B0_Add(1, pData);
}

void EncodeDataBytes(unsigned int nValue, D2StormArrayBStrc* pArray); // 0x00421BD0
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
