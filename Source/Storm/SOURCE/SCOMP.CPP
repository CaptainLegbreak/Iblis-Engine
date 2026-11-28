#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"
#include "stpl.h"
#include "SValidate.h"

struct D2StormHashBufferStrc;

struct D2CriticalSectionStrc;


struct D2StormMemSourceStrc;

struct D2StormMemSinkStrc;

struct D2StormCompParamStrc;

struct D2StormZArenaStrc;

struct HUFFNODE;

struct CHuffman;

struct D2AdpcmHeaderStrc;

struct D2SCompLinkStrc;

struct D2SCompListViewStrc;

struct D2SCompLinkNextAStrc;

struct D2SCompLinkPrevStrc;

struct D2SCompLinkRawAStrc;

struct D2SCompUnlinkAStrc;

struct D2SCompListTermStrc;

struct D2SCompListTailStrc;

struct D2SCompListInitStrc;

struct D2SCompTermLinkStrc;

struct D2StormMemSourceStrc
{
    int unk0x00[3];
    char* pBuffer;
    unsigned int nPos;
    unsigned int nSize;
};

struct D2StormMemSinkStrc
{
    char* pBuffer;
    unsigned int nPos;
    unsigned int nSize;
};

struct D2StormCompParamStrc
{
    char* pDst;
    unsigned int nDstPos;
    unsigned int nDstSize;
    char* pSrc;
    unsigned int nSrcPos;
    unsigned int nSrcSize;
};

struct HUFFNODE : TSLinkedNode<HUFFNODE>
{
    unsigned int nValue;                                    // 0x08
    unsigned int nWeight;                                   // 0x0C
    HUFFNODE* pParent;                                      // 0x10
    HUFFNODE* pChild;                                       // 0x14

    HUFFNODE();
    ~HUFFNODE();
};

// The Huffman coder's bit reader: little-endian, refilled 16 bits at a time when peeking and a dword at a time
// when reading single bits.
struct CBitInput
{
    unsigned char* pInput;                                  // 0x00
    unsigned int nBitBuffer;                                // 0x04
    unsigned int nBitCount;                                 // 0x08

    CBitInput(void* pInputBuffer);                                                          // 0x0041D880
    int sub_0041D8A0_ReadBit();                                                             // 0x0041D8A0
    unsigned int sub_0041D8D0_Peek(unsigned int nBits, unsigned int nMask);                 // 0x0041D8D0
    void sub_0041D900_Skip(unsigned int nBits);                                             // 0x0041D900
    unsigned int sub_0041E9E0_Get(unsigned int nBits, unsigned int nMask);                  // 0x0041E9E0

    unsigned int Peek(unsigned int nBits, unsigned int nMask)
    {
        if (nBitCount <= nBits)
        {
            nBitBuffer |= *(unsigned short*)pInput << nBitCount;
            nBitCount += 16;
            pInput += 2;
        }
        return nBitBuffer & nMask;
    }
    void Skip(unsigned int nBits)
    {
        nBitBuffer >>= nBits;
        nBitCount -= nBits;
    }
    unsigned int Peek7()
    {
        if (nBitCount <= 7)
        {
            nBitBuffer |= *(unsigned short*)pInput << nBitCount;
            nBitCount += 16;
            pInput += 2;
        }
        return nBitBuffer & 127;
    }
    unsigned int GetBit()
    {
        unsigned int nValue = nBitBuffer & 1;
        nBitBuffer >>= 1;
        if (!--nBitCount)
        {
            nBitBuffer = *(unsigned int*)pInput;
            pInput += 4;
            nBitCount = 32;
        }
        return nValue;
    }
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

#include "D2StormBitOutput.h"
#include "StormApi.h"

// The adaptive Huffman tree. tItemList keeps the nodes sorted by weight; nMinValidValue is bumped whenever
// the tree changes shape, which invalidates the decoder's prefix cache.
struct CHuffman
{
    int bIsCmp0;                                            // 0x0000
    unsigned int nMinValidValue;                            // 0x0004
    HUFFNODE aItems[0x203];                                 // 0x0008
    TSList<HUFFNODE> tFreeList;                             // 0x3050
    TSList<HUFFNODE> tItemList;                             // 0x305C
    unsigned int nItemsUsed;                                // 0x3068
    HUFFNODE* pItemsByValue[0x102];                         // 0x306C

    CHuffman();                                                                             // 0x0041F4A0
    ~CHuffman();                                                                            // 0x0041F6A0
    HUFFNODE* NewItem(unsigned int nLinkType);                                              // 0x0041EED0
    HUFFNODE* AllocateItem(unsigned int nLinkType)
    {
        HUFFNODE* pItem = tFreeList.m_terminator.Next();
        if (!pItem) pItem = &aItems[nItemsUsed++];
        tItemList.LinkNode(pItem, nLinkType, 0);
        pItem->pParent = 0;
        pItem->pChild = 0;
        return pItem;
    }
    HUFFNODE* Root()
    {
        return tItemList.m_terminator.Prev();
    }
    void BuildTree(unsigned char nCmpType);                                                 // 0x0041EF20
    void sub_0041F350_IncWeights(HUFFNODE* pItem);                                          // 0x0041F350
    void AddSymbol(unsigned int nValue);                                                    // 0x0041F510
    void sub_0041D9E0_EncodeOne(CBitOutput* pOutput, unsigned int nValue);                  // 0x0041D9E0
    unsigned int Compress(CBitOutput* pOutput, void* pvIn, int cbIn, unsigned char nCmpType); // 0x0041F850
};

struct CHuffmanEncoder : CHuffman
{
    CHuffmanEncoder();                                                                      // 0x0041F920
    ~CHuffmanEncoder();                                                                     // 0x0041F930
};

// One decoder prefix-cache slot: the tree generation it was filled in, the code length, and the value (codes
// of up to 7 bits) or the node reached after 7 bits.
struct HUFFCACHE
{
    unsigned int nGeneration;                               // 0x00
    unsigned int nBits;                                     // 0x04
    union
    {
        unsigned int nValue;
        HUFFNODE* pNode;
    };                                                      // 0x08
};

struct CHuffmanDecoder : CHuffman
{
    ~CHuffmanDecoder();                                                                     // 0x0041F940
};

// The tree HuffmanDecompress decodes with: the tree plus a 7-bit prefix cache.
struct CHuffmanCache : CHuffman
{
    HUFFCACHE aCache[0x80];                                 // 0x3474

    CHuffmanCache();                                                                        // 0x0041F950
    unsigned int sub_0041EBC0_DecodeOne(CBitInput* pInput);                                 // 0x0041EBC0
    unsigned int Decompress(void* pOutput, unsigned int nOutputSize, CBitInput* pInput);   // 0x0041F740
};


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650



extern "C" unsigned int __cdecl sub_006B01B0_Explode(unsigned int (__cdecl* pRead)(char*, unsigned int*, D2StormMemSourceStrc*), void (__cdecl* pWrite)(char*, unsigned int*, D2StormMemSinkStrc*), char* pWork, void* pParam); // 0x006B01B0

extern "C" unsigned int __cdecl sub_006B0870_Implode(unsigned int (__cdecl* pRead)(char*, unsigned int*, D2StormMemSourceStrc*), void (__cdecl* pWrite)(char*, unsigned int*, D2StormMemSinkStrc*), char* pWork, void* pParam, unsigned int* pType, unsigned int* pDictSize); // 0x006B0870

struct D2SCompListViewStrc
{
    int m_linkoffset;
    D2SCompLinkStrc m_terminator;
};

struct D2SCompLinkNextAStrc { D2SCompLinkStrc tLink; char* sub_0041E930_Next(); };

struct D2SCompLinkPrevStrc { D2SCompLinkStrc tLink; char* sub_0041E940_Prev(); };

struct D2SCompLinkRawAStrc { D2SCompLinkStrc tLink; char* sub_0041E960_RawNext(); };

struct D2SCompUnlinkAStrc { D2SCompLinkStrc tLink; void sub_0041E970_Unlink(); };

struct D2SCompListTermStrc { D2SCompListViewStrc tList; void sub_0041E9B0_InitializeTerminator(); };

struct D2SCompListTailStrc { D2SCompListViewStrc tList; char* sub_0041EAC0_Tail(); };

struct D2SCompListInitStrc { D2SCompListViewStrc tList; void sub_0041EB20_Init(); };

struct D2SCompTermLinkStrc
{
    D2SCompTermLinkStrc* m_prevlink;
    char* m_next;
    D2SCompTermLinkStrc() { m_prevlink = 0; m_next = 0; }
};

struct D2StormZArenaStrc
{
    char* pNext;
    unsigned int nSize;
    char* pBase;
};

struct z_stream
{
    unsigned char* next_in;
    unsigned int avail_in;
    unsigned int total_in;
    unsigned char* next_out;
    unsigned int avail_out;
    unsigned int total_out;
    char* msg;
    void* state;
    void* (__fastcall* zalloc)(void* opaque, unsigned int nItems, unsigned int nSize);
    void (__fastcall* zfree)(void* opaque, void* pAddress);
    void* opaque;
    int data_type;
    unsigned int adler;
    unsigned int reserved;
};

int __fastcall deflateInit_(z_stream* strm, int level, const char* version, int stream_size); // 0x004297F0

int __fastcall deflateEnd(z_stream* strm); // 0x004274A0

void* __fastcall ZArenaAlloc(void* pArena, unsigned int nItems, unsigned int nSize); // 0x0041E080

void __fastcall ZArenaFree(void* pArena, void* pAddress); // 0x0041E0D0

int __fastcall inflateInit_(z_stream* strm, const char* version, int stream_size); // 0x00429A10

int __fastcall inflate(z_stream* strm, int flush); // 0x00429BB0

int __fastcall inflateEnd(z_stream* strm); // 0x0042B170

struct SCompBufferState
{
    void* pMemory;
};

extern SCompBufferState gSCompBuffer_0077920C; // 0x0077920C


// 0x0041DEC0
unsigned int __cdecl PkwareBufferRead(char* pBuffer, unsigned int* pSize, D2StormMemSourceStrc* pSource)
{
    unsigned int nAvail = pSource->nSize - pSource->nPos;
    unsigned int nSize = *pSize < nAvail ? *pSize : nAvail;
    SMemCopy(pBuffer, pSource->pBuffer + pSource->nPos, nSize);
    pSource->nPos += nSize;
    return nSize;
}

// 0x0041DF00
void __cdecl PkwareBufferWrite(char* pBuffer, unsigned int* pSize, D2StormMemSinkStrc* pSink)
{
    unsigned int nAvail = pSink->nSize - pSink->nPos;
    unsigned int nSize = *pSize < nAvail ? *pSize : nAvail;
    SMemCopy(pSink->pBuffer + pSink->nPos, pBuffer, nSize);
    pSink->nPos += nSize;
}

// 0x0041DF40
void __fastcall PkwareCompress(char* pDst, unsigned int* pDstLen, char* pSrc, unsigned int nSrcLen, int* pType, int nLevel)
{
    char* pWork = (char*)SMemAlloc(0x8DD8, ".\\SOURCE\\SCOMP.CPP", 0x440, 0);
    D2StormCompParamStrc tParam;
    unsigned int nType;
    unsigned int nDictSize;
    tParam.pDst = pDst;
    tParam.nDstPos = 0;
    tParam.nDstSize = *pDstLen;
    tParam.pSrc = pSrc;
    tParam.nSrcPos = 0;
    tParam.nSrcSize = nSrcLen;
    nType = *pType == 2;
    if (nSrcLen >= 0xC00)
        nDictSize = 0x1000;
    else
        nDictSize = nSrcLen < 0x600 ? 0x400 : 0x800;
    sub_006B0870_Implode(PkwareBufferRead, PkwareBufferWrite, pWork, &tParam, &nType, &nDictSize);
    SMemFree(pWork, ".\\SOURCE\\SCOMP.CPP", 0x467, 0);
    *pDstLen = tParam.nDstPos;
    *pType = 0;
}

// 0x0041E000
void __fastcall PkwareDecompress(char* pDst, unsigned int* pDstLen, char* pSrc, unsigned int nSrcLen, int nUnused)
{
    char* pWork = (char*)SMemAlloc(0x3134, ".\\SOURCE\\SCOMP.CPP", 0x47B, 0);
    D2StormCompParamStrc tParam;
    tParam.pDst = pDst;
    tParam.nDstPos = 0;
    tParam.nDstSize = *pDstLen;
    tParam.pSrc = pSrc;
    tParam.nSrcPos = 0;
    tParam.nSrcSize = nSrcLen;
    sub_006B01B0_Explode(PkwareBufferRead, PkwareBufferWrite, pWork, &tParam);
    SMemFree(pWork, ".\\SOURCE\\SCOMP.CPP", 0x48D, 0);
    *pDstLen = tParam.nDstPos;
}

// 0x0041E080
void* __fastcall ZArenaAlloc(D2StormZArenaStrc* pArena, unsigned int nItems, unsigned int nSize)
{
    unsigned int nBytes = nItems * nSize;
    if (nBytes & 3)
        nBytes += 4 - (nBytes & 3);
    if (nBytes < (unsigned int)(pArena->pBase + pArena->nSize - pArena->pNext))
    {
        char* pResult = pArena->pNext;
        pArena->pNext += nBytes;
        return pResult;
    }
    return SMemAlloc(nBytes, ".\\SOURCE\\SCOMP.CPP", 0x4C4, 0);
}

// 0x0041E0D0
void __fastcall ZArenaFree(void* pArena, void* pAddress)
{
    D2StormZArenaStrc* pZArena = (D2StormZArenaStrc*)pArena;
    if ((char*)pAddress < pZArena->pBase || (char*)pAddress >= pZArena->pBase + pZArena->nSize)
        SMemFree(pAddress, ".\\SOURCE\\SCOMP.CPP", 0x4CC, 0);
}

// 0x0041E100
static int __stdcall CompressWithArena(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen, int level)
{
    char aBuffer[0x493E0];
    D2StormZArenaStrc tArena;
    z_stream stream;
    int err;
    stream.next_in = (unsigned char*)source;
    stream.avail_in = sourceLen;
    stream.next_out = dest;
    stream.avail_out = *destLen;
    tArena.pNext = aBuffer;
    tArena.nSize = sizeof(aBuffer);
    tArena.pBase = aBuffer;
    stream.zalloc = ZArenaAlloc;
    stream.zfree = ZArenaFree;
    stream.opaque = &tArena;
    err = deflateInit_(&stream, level, "1.1.3", sizeof(stream));
    if (err != 0)
    {
        return err;
    }
    err = deflate(&stream, 4);
    if (err != 1)
    {
        deflateEnd(&stream);
        return err == 0 ? -5 : err;
    }
    *destLen = stream.total_out;
    err = deflateEnd(&stream);
    return err;
}

// 0x0041E1F0
void __fastcall ZlibCompress(unsigned char* pOut, unsigned long* pOutSize, const unsigned char* pIn, unsigned long nInSize, int* pnResult, int nLevel)
{
    int nZLevel;
    switch (nLevel)
    {
    case 1:
        nZLevel = 9;
        break;
    case 2:
        nZLevel = 1;
        break;
    default:
        nZLevel = -1;
        break;
    }
    unsigned long nDestLen = *pOutSize;
    if (CompressWithArena(pOut, &nDestLen, pIn, nInSize, nZLevel) == 0)
    {
        *pOutSize = nDestLen;
    }
    *pnResult = 0;
}

// 0x0041E250
static int __stdcall UncompressWithArena(unsigned char* dest, unsigned long* destLen, const unsigned char* source, unsigned long sourceLen)
{
    char aBuffer[0xB798];
    D2StormZArenaStrc tArena;
    z_stream stream;
    int err;
    stream.next_in = (unsigned char*)source;
    stream.avail_in = sourceLen;
    stream.next_out = dest;
    stream.avail_out = *destLen;
    tArena.pNext = aBuffer;
    tArena.nSize = sizeof(aBuffer);
    tArena.pBase = aBuffer;
    stream.zalloc = ZArenaAlloc;
    stream.zfree = ZArenaFree;
    stream.opaque = &tArena;
    err = inflateInit_(&stream, "1.1.3", sizeof(stream));
    if (err != 0)
    {
        return err;
    }
    err = inflate(&stream, 4);
    if (err != 1)
    {
        inflateEnd(&stream);
        return err == 0 ? -5 : err;
    }
    *destLen = stream.total_out;
    err = inflateEnd(&stream);
    return err;
}

// 0x0041E340
int __fastcall ZlibDecompress(unsigned char* pOut, unsigned long* pOutSize, const unsigned char* pIn, unsigned long nInSize, int nUnused)
{
    return UncompressWithArena(pOut, pOutSize, pIn, nInSize);
}

// 0x0041D880
CBitInput::CBitInput(void* pInputBuffer)
{
    pInput = (unsigned char*)pInputBuffer;
    nBitBuffer = *(unsigned int*)pInput;
    pInput += 4;
    nBitCount = 32;
}

// 0x0041D8A0
int CBitInput::sub_0041D8A0_ReadBit()
{
    int nBit = nBitBuffer & 1;
    nBitBuffer >>= 1;
    if (!--nBitCount)
    {
        nBitBuffer = *(unsigned int*)pInput;
        pInput += 4;
        nBitCount = 32;
    }
    return nBit;
}

// 0x0041D8D0
unsigned int CBitInput::sub_0041D8D0_Peek(unsigned int nBits, unsigned int nMask)
{
    if (nBitCount <= nBits)
    {
        nBitBuffer |= *(unsigned short*)pInput << nBitCount;
        nBitCount += 16;
        pInput += 2;
    }
    return nBitBuffer & nMask;
}

// 0x0041D900
void CBitInput::sub_0041D900_Skip(unsigned int nBits)
{
    nBitBuffer >>= nBits;
    nBitCount -= nBits;
}

// 0x0041D920
CBitOutput::CBitOutput(void* pOutputBuffer, unsigned int nOutputSize)
{
    pOutput = (unsigned char*)pOutputBuffer;
    pOutputStart = (unsigned char*)pOutputBuffer;
    nBytesLeft = nOutputSize;
    nBitBuffer = 0;
    nBitCount = 0;
}

// 0x0041D940
unsigned int CBitOutput::sub_0041D940_GetSize()
{
    return pOutput - pOutputStart;
}

// 0x0041D950
void CBitOutput::sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits)
{
    nBitBuffer |= nValue << nBitCount;
    nBitCount += nBits;
    while (nBitCount >= 8)
    {
        if (nBytesLeft)
        {
            *pOutput++ = (unsigned char)nBitBuffer;
            nBytesLeft--;
        }
        nBitBuffer >>= 8;
        nBitCount -= 8;
    }
}

// 0x0041D9A0
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

// 0x0041D9E0
void CHuffman::sub_0041D9E0_EncodeOne(CBitOutput* pOutput, unsigned int nValue)
{
    HUFFNODE* pItem = pItemsByValue[nValue];
    unsigned int nCode = 0;
    unsigned int nBits = 0;
    for (HUFFNODE* pParent = pItem->pParent; pParent; pParent = pParent->pParent)
    {
        nCode = (nCode << 1) | (pParent->pChild != pItem);
        nBits++;
        pItem = pParent;
    }
    pOutput->sub_0041D950_PutBits(nCode, nBits);
}

extern "C" int __cdecl abs(int);

// 0x0041DA30
static void sub_0041DA30_GetCompressionLevel(unsigned int nCmpLevel, unsigned char* pnLevel, int* pCmpType)
{
    switch (nCmpLevel)
    {
    case 1:
    case 2:
        *pnLevel = 4;
        *pCmpType = 6;
        break;
    case 3:
        *pnLevel = 6;
        *pCmpType = 8;
        break;
    default:
        *pnLevel = 5;
        *pCmpType = 7;
        break;
    }
}

// 0x0041DA60
static int __stdcall ImaAdpcmCompress(int nOutSize, const short* pIn, int nInSize, unsigned int nChannels, unsigned char nLevel, unsigned char* pOut)
{
    unsigned char* pOutStart = pOut;
    if ((unsigned int)nOutSize < 2)
    {
        return 2;
    }
    D2AdpcmHeaderStrc tHeader;
    tHeader.nZero = 0;
    tHeader.nShift = nLevel - 1;
    *(D2AdpcmHeaderStrc*)pOut = tHeader;
    pOut += 2;
    if (pOut + nChannels * 2 - pOutStart > nOutSize)
    {
        return pOut + nChannels * 2 - pOutStart;
    }
    int aSample[2];
    int aPredicted[2];
    int aStepIndex[2];
    aStepIndex[0] = 0x2C;
    aStepIndex[1] = 0x2C;
    unsigned int i;
    for (i = 0; i < nChannels; i++)
    {
        aPredicted[i] = *pIn++;
        *(short*)pOut = (short)aPredicted[i];
        pOut += 2;
    }
    int nGrowLeft = (nInSize / 2 - (pOut - pOutStart) < 0) ? 0 : nInSize / 2 - (pOut - pOutStart);
    int nChannel = nChannels - 1;
    const unsigned int nWords = nInSize / sizeof(short);
    for (i = nChannels; i < nWords; i++)
    {
        if (pOut + 2 - pOutStart > nOutSize)
        {
            return pOut + 2 - pOutStart;
        }
        if (nChannels == 2)
        {
            nChannel = nChannel == 0;
        }
        aSample[nChannel] = *pIn++;
        const unsigned int nAbs = abs(aSample[nChannel] - aPredicted[nChannel]);
        const int nSignBit = aSample[nChannel] >= aPredicted[nChannel] ? 0 : 0x40;
        unsigned int nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
        if (nAbs < (nStepSize >> nLevel))
        {
            if (aStepIndex[nChannel])
            {
                aStepIndex[nChannel]--;
            }
            *pOut++ = 0x80;
            continue;
        }
        while (nAbs > nStepSize * 2 && aStepIndex[nChannel] < 0x58 && nGrowLeft)
        {
            aStepIndex[nChannel] += 8;
            if (aStepIndex[nChannel] > 0x58)
            {
                aStepIndex[nChannel] = 0x58;
            }
            nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
            *pOut++ = 0x81;
            nGrowLeft--;
        }
        unsigned int nMask = 0;
        unsigned int nTotal = 0;
        const unsigned int nStepRest = nStepSize >> tHeader.nShift;
        unsigned int nBit = 1;
        const unsigned int nMaxBit = ((unsigned int)(1 << (nLevel - 2)) > 0x20) ? 0x20 : (1 << (nLevel - 2));
        for (;;)
        {
            if (nTotal + nStepSize <= nAbs)
            {
                nMask |= nBit;
                nTotal += nStepSize;
            }
            if (nBit == nMaxBit)
            {
                break;
            }
            nStepSize >>= 1;
            nBit <<= 1;
        }
        nTotal += nStepRest;
        int nPredicted = aPredicted[nChannel];
        if (nSignBit)
        {
            nPredicted -= nTotal;
            if (nPredicted < -0x8000)
            {
                nPredicted = -0x8000;
            }
        }
        else
        {
            nPredicted += nTotal;
            if (nPredicted > 0x7FFF)
            {
                nPredicted = 0x7FFF;
            }
        }
        aPredicted[nChannel] = nPredicted;
        *pOut++ = (unsigned char)(nSignBit | nMask);
        aStepIndex[nChannel] += gaADPCMIndexTable_006CFCB8[nMask & 0x1F];
        if (aStepIndex[nChannel] < 0)
        {
            aStepIndex[nChannel] = 0;
        }
        else if (aStepIndex[nChannel] > 0x58)
        {
            aStepIndex[nChannel] = 0x58;
        }
    }
    return pOut - pOutStart;
}

// 0x0041E360
void __fastcall ImaAdpcmMonoCompress(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = ImaAdpcmCompress(*pcbOutBuffer, pvInBuffer, cbInBuffer, 1, nLevel, pvOutBuffer);
}

// 0x0041DCE0
static int __stdcall ImaAdpcmDecompress(short* pOut, unsigned int nOutSize, unsigned char* pIn, int nInLength, unsigned int nChannels)
{
    int aPredicted[2];
    int aStep[2];
    unsigned char* pHeader = pIn;
    short* pOutStart = pOut;
    aStep[0] = 0x2C;
    aStep[1] = 0x2C;
    unsigned char* pInEnd = pIn + nInLength;
    pIn += 2;
    for (unsigned int i = 0; i < nChannels; i++)
    {
        aPredicted[i] = *(short*)pIn;
        pIn += 2;
        if (nOutSize < 2)
        {
            return (char*)pOut - (char*)pOutStart;
        }
        nOutSize -= 2;
        *pOut = aPredicted[i];
        pOut++;
    }
    int nChannel = nChannels - 1;
    while (pIn < pInEnd)
    {
        if (nChannels == 2)
        {
            nChannel = (nChannel == 0);
        }
        const unsigned char nByte = *pIn++;
        if (nByte & 0x80)
        {
            int bSameChannel = 0;
            switch (nByte & 0x7F)
            {
            case 0:
                if (aStep[nChannel])
                {
                    aStep[nChannel]--;
                }
                if (nOutSize < 2)
                {
                    return (char*)pOut - (char*)pOutStart;
                }
                *pOut = aPredicted[nChannel];
                pOut++;
                nOutSize -= 2;
                break;
            case 1:
                aStep[nChannel] += 8;
                if (aStep[nChannel] > 0x58)
                {
                    aStep[nChannel] = 0x58;
                }
                bSameChannel = 1;
                break;
            case 2:
                aStep[nChannel] -= 8;
                if (aStep[nChannel] < 0)
                {
                    aStep[nChannel] = 0;
                }
                bSameChannel = 1;
                break;
            default:
                continue;
            }
            if (bSameChannel && nChannels == 2)
            {
                nChannel = (nChannel == 0);
            }
        }
        else
        {
            const unsigned int nStep = gaADPCMStepTable_006CFD38[aStep[nChannel]];
            unsigned int nDiff = nStep >> pHeader[1];
            if (nByte & 1)
                nDiff += nStep;
            if (nByte & 2)
                nDiff += nStep >> 1;
            if (nByte & 4)
                nDiff += nStep >> 2;
            if (nByte & 8)
                nDiff += nStep >> 3;
            if (nByte & 0x10)
                nDiff += nStep >> 4;
            if (nByte & 0x20)
                nDiff += nStep >> 5;
            int nValue = aPredicted[nChannel];
            if (nByte & 0x40)
            {
                nValue -= nDiff;
                if (nValue <= -0x8000)
                {
                    nValue = -0x8000;
                }
            }
            else
            {
                nValue += nDiff;
                if (nValue >= 0x7FFF)
                {
                    nValue = 0x7FFF;
                }
            }
            aPredicted[nChannel] = nValue;
            if (nOutSize < 2)
            {
                return (char*)pOut - (char*)pOutStart;
            }
            nOutSize -= 2;
            *pOut = aPredicted[nChannel];
            pOut++;
            aStep[nChannel] += gaADPCMIndexTable_006CFCB8[nByte & 0x1F];
            if (aStep[nChannel] < 0)
            {
                aStep[nChannel] = 0;
            }
            else if (aStep[nChannel] > 0x58)
            {
                aStep[nChannel] = 0x58;
            }
        }
    }
    return (char*)pOut - (char*)pOutStart;
}

// 0x0041E3A0
void __fastcall ImaAdpcmMonoDecompress(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused)
{
    *pOutSize = ImaAdpcmDecompress(pOut, *pOutSize, pIn, nInLength, 1);
}

// 0x0041E3C0
void __fastcall ImaAdpcmStereoCompress(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = ImaAdpcmCompress(*pcbOutBuffer, pvInBuffer, cbInBuffer, 2, nLevel, pvOutBuffer);
}

// 0x0041E400
void __fastcall ImaAdpcmStereoDecompress(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused)
{
    *pOutSize = ImaAdpcmDecompress(pOut, *pOutSize, pIn, nInLength, 2);
}

// 0x0041E420
static int DoRangesOverlap(const char* pA, const char* pB, unsigned int nSize)
{
    if (pA + nSize > pB && pB + nSize > pA)
        return 1;
    return 0;
}

static unsigned int gnWorkBufferSize_00779208; // 0x00779208

static void* gpWorkBuffer_0077920C; // 0x0077920C

static unsigned long gdwWorkBufferOwner_00779210; // 0x00779210

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

// A critical section for the whole run: initialized before main, deleted at exit.
struct CCritSect : D2CriticalSectionStrc
{
    CCritSect() { InitializeCriticalSection(this); }
    ~CCritSect() { DeleteCriticalSection(this); }
};

// build: symbol ??__EgtWorkBufferLock_00779214@@YAXXZ 0x006CA8C0
// build: symbol ??__FgtWorkBufferLock_00779214@@YAXXZ 0x006CB300
static CCritSect gtWorkBufferLock_00779214; // 0x00779214

// 0x0041E440
static void* s_AllocDecompressBuffer(unsigned int nSize, int* pbShared)
{
    EnterCriticalSection(&gtWorkBufferLock_00779214);
    const unsigned long dwThreadId = GetCurrentThreadId();
    if (!gpWorkBuffer_0077920C)
    {
        gnWorkBufferSize_00779208 = nSize;
        gpWorkBuffer_0077920C = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x620, 0);
        gdwWorkBufferOwner_00779210 = 0;
    }
    else if (gdwWorkBufferOwner_00779210)
    {
        void* pBuffer = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x626, 0);
        *pbShared = 0;
        LeaveCriticalSection(&gtWorkBufferLock_00779214);
        return pBuffer;
    }
    if (gnWorkBufferSize_00779208 < nSize)
    {
        SMemFree(gpWorkBuffer_0077920C, ".\\SOURCE\\SCOMP.CPP", 0x62F, 0);
        gnWorkBufferSize_00779208 = nSize;
        gpWorkBuffer_0077920C = SMemAlloc(nSize, ".\\SOURCE\\SCOMP.CPP", 0x631, 0);
    }
    *pbShared = 1;
    gdwWorkBufferOwner_00779210 = dwThreadId;
    void* pBuffer = gpWorkBuffer_0077920C;
    LeaveCriticalSection(&gtWorkBufferLock_00779214);
    return pBuffer;
}

// 0x0041E510
static void __stdcall FreeWorkBuffer(int bShared, void* pBuffer)
{
    if (!pBuffer)
    {
        return;
    }
    EnterCriticalSection(&gtWorkBufferLock_00779214);
    if (bShared)
    {
        gdwWorkBufferOwner_00779210 = 0;
        LeaveCriticalSection(&gtWorkBufferLock_00779214);
        return;
    }
    SMemFree(pBuffer, ".\\SOURCE\\SCOMP.CPP", 0x647, 0);
    LeaveCriticalSection(&gtWorkBufferLock_00779214);
}

#define OVERLAP(a, b, n) ((a) + (n) > (b) && (b) + (n) > (a))

typedef void (__fastcall* PFNSCOMPCOMPRESS)(void* pOut, unsigned int* pcbOut, void* pIn, unsigned int cbIn, int* pnCmpType, int nCmpLevel);
typedef void (__fastcall* PFNSCOMPDECOMPRESS)(void* pOut, unsigned int* pcbOut, void* pIn, unsigned int cbIn, int nExtra);

struct D2SCompCompStrc
{
    unsigned int dwMask;
    PFNSCOMPCOMPRESS pfnCompress;
};

struct D2SCompDecompStrc
{
    unsigned int dwMask;
    PFNSCOMPDECOMPRESS pfnDecompress;
};

void __stdcall sub_0041C340_SetLastError(unsigned long dwErrCode); // 0x0041C340
void __fastcall HuffmanCompress(void* pvOutBuffer, int* pcbOutBuffer, void* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel); // 0x0041F980
void __fastcall HuffmanDecompress(void* pOut, unsigned int* pcbOut, void* pIn, unsigned int cbIn, int nExtra); // 0x0041F9E0

// build: symbol _gtCompTable_006CFE9C 0x006CFE9C
static const D2SCompCompStrc gtCompTable_006CFE9C[5] = { { 0x40, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int*, int))&ImaAdpcmMonoCompress }, { 0x80, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int*, int))&ImaAdpcmStereoCompress }, { 1, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int*, int))&HuffmanCompress }, { 2, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int*, int))&ZlibCompress }, { 8, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int*, int))&PkwareCompress } }; // 0x006CFE9C

// build: symbol _gtDecompTable_006CFEC4 0x006CFEC4
static const D2SCompDecompStrc gtDecompTable_006CFEC4[5] = { { 0x40, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int))&ImaAdpcmMonoDecompress }, { 0x80, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int))&ImaAdpcmStereoDecompress }, { 1, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int))&HuffmanDecompress }, { 2, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int))&ZlibDecompress }, { 8, (void (__fastcall *)(void*, unsigned int*, void*, unsigned int, int))&PkwareDecompress } }; // 0x006CFEC4

// 0x0041E570
int __stdcall SCompCompress(unsigned char* pDest, unsigned int* pdwDestSize, unsigned char* pSrc, unsigned int dwSrcSize, unsigned int dwMask, int nCmpType, int nCmpLevel)
{
    VALIDATEBEGIN;
    VALIDATE(pDest);
    VALIDATE(pdwDestSize);
    VALIDATE(*pdwDestSize >= dwSrcSize);
    VALIDATE(pSrc);
    if (!nValid)
    {
        sub_0041C340_SetLastError(0x57);
        return 0;
    }

    unsigned int nCount = 0;
    unsigned int dwUnknown = dwMask;
    for (int i = 0; i < 5; ++i)
    {
        if (dwMask & gtCompTable_006CFE9C[i].dwMask)
            ++nCount;
        dwUnknown &= ~gtCompTable_006CFE9C[i].dwMask;
    }
    if (dwUnknown)
        return 0;

    int bShared = 0;
    unsigned char* pWork = 0;
    if (nCount >= 2 || (OVERLAP(pDest, pSrc, dwSrcSize) && nCount))
        pWork = (unsigned char*)s_AllocDecompressBuffer(dwSrcSize, &bShared);

    unsigned char* pIn = pSrc;
    unsigned int cbIn = dwSrcSize;
    for (int i = 0; i < 5; ++i)
    {
        if (gtCompTable_006CFE9C[i].dwMask & dwMask)
        {
            --nCount;
            unsigned char* pOut = (nCount & 1) ? pWork : pDest + 1;
            if (OVERLAP(pOut, pIn, cbIn))
                pOut = OVERLAP(pOut, pWork, cbIn) ? pDest + 1 : pWork;
            unsigned int cbOut = cbIn - 1;
            gtCompTable_006CFE9C[i].pfnCompress(pOut, &cbOut, pIn, cbIn, &nCmpType, nCmpLevel);
            if (cbOut + 1 < cbIn)
            {
                pIn = pOut;
                cbIn = cbOut;
            }
            else
            {
                dwMask &= ~gtCompTable_006CFE9C[i].dwMask;
            }
        }
    }

    if (pIn != pDest)
    {
        if (pIn == pDest + 1)
        {
            *pDest = (unsigned char)dwMask;
            ++cbIn;
        }
        else if (dwMask)
        {
            SMemCopy(pDest + 1, pIn, cbIn);
            *pDest = (unsigned char)dwMask;
            ++cbIn;
        }
        else
        {
            SMemCopy(pDest, pIn, cbIn);
        }
    }
    *pdwDestSize = cbIn;
    FreeWorkBuffer(bShared, pWork);
    return 1;
}

// 0x0041E720
int __stdcall SCompDecompress(void* pDest, unsigned int* pdwDestSize, unsigned char* pSrc, unsigned int dwSrcSize, int nExtra)
{
    unsigned int dwDestSize = *pdwDestSize;
    VALIDATEBEGIN;
    VALIDATE(pDest);
    VALIDATE(dwDestSize >= dwSrcSize);
    VALIDATE(pSrc);
    VALIDATE(dwSrcSize >= sizeof(unsigned char));
    VALIDATEEND;

    if (dwSrcSize == dwDestSize)
    {
        if (pDest != pSrc)
            SMemCopy(pDest, pSrc, dwSrcSize);
        return 1;
    }

    unsigned int dwTypes = *pSrc++;
    dwSrcSize--;
    unsigned int nCount = 0;
    unsigned int dwUnknown = dwTypes;
    for (int i = 4; i >= 0; --i)
    {
        if (dwTypes & gtDecompTable_006CFEC4[i].dwMask)
            ++nCount;
        dwUnknown &= ~gtDecompTable_006CFEC4[i].dwMask;
    }
    if (dwUnknown)
        return 0;

    int bShared = 0;
    unsigned char* pWork = 0;
    if (nCount >= 2 || (OVERLAP((unsigned char*)pDest, pSrc, dwSrcSize) && nCount))
        pWork = (unsigned char*)s_AllocDecompressBuffer(dwDestSize, &bShared);

    unsigned char* pIn = pSrc;
    unsigned int cbIn = dwSrcSize;
    for (int i = 4; i >= 0; --i)
    {
        if (dwTypes & gtDecompTable_006CFEC4[i].dwMask)
        {
            --nCount;
            unsigned char* pOut = (nCount & 1) ? pWork : (unsigned char*)pDest;
            if (OVERLAP(pOut, pIn, cbIn))
                pOut = OVERLAP(pOut, pWork, cbIn) ? (unsigned char*)pDest : pWork;
            unsigned int cbOut = dwDestSize;
            gtDecompTable_006CFEC4[i].pfnDecompress(pOut, &cbOut, pIn, cbIn, nExtra);
            cbIn = cbOut;
            pIn = pOut;
        }
    }

    if (pIn != pDest)
        SMemCopy(pDest, pIn, cbIn);
    *pdwDestSize = cbIn;
    FreeWorkBuffer(bShared, pWork);
    return 1;
}

// 0x0041E8C0
extern "C" int __cdecl SCompDestroy()
{
    if (gSCompBuffer_0077920C.pMemory)
    {
        SMemFree(gSCompBuffer_0077920C.pMemory, ".\\SOURCE\\SCOMP.CPP", 0x733, 0);
        gSCompBuffer_0077920C.pMemory = 0;
    }
    return 1;
}

int __stdcall sub_M107_Emit_0041E420(const char* pA, const char* pB, unsigned int nSize, int nCount)
{
    if (nCount >= 2 || DoRangesOverlap(pA, pB, nSize))
        return nCount + 1;
    return nCount;
}

// 0x0041E930
char* D2SCompLinkNextAStrc::sub_0041E930_Next() { return (int)tLink.m_next <= 0 ? 0 : tLink.m_next; }

// 0x0041E940
char* D2SCompLinkPrevStrc::sub_0041E940_Prev()
{
    D2SCompLinkStrc* pLink = tLink.m_prevlink->m_prevlink;
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

// 0x0041E960
char* D2SCompLinkRawAStrc::sub_0041E960_RawNext() { return tLink.m_next; }

// 0x0041E970
void D2SCompUnlinkAStrc::sub_0041E970_Unlink() { tLink.Unlink(); }

// 0x0041E9B0
void D2SCompListTermStrc::sub_0041E9B0_InitializeTerminator()
{
    tList.m_terminator.m_prevlink = &tList.m_terminator;
    tList.m_terminator.m_next = (char*)~(unsigned int)&tList.m_terminator;
}

// 0x0041E9D0
void __fastcall sub_0041E9D0_SwapDwords(int* pA, int* pB)
{
    int nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

// 0x0041EAC0
char* D2SCompListTailStrc::sub_0041EAC0_Tail()
{
    D2SCompLinkStrc* pLink = tList.m_terminator.m_prevlink->m_prevlink;
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

// 0x0041EB20
void D2SCompListInitStrc::sub_0041EB20_Init()
{
    tList.m_linkoffset = 0;
    tList.m_terminator.m_prevlink = &tList.m_terminator;
    tList.m_terminator.m_next = (char*)~(unsigned int)&tList.m_terminator;
}

// 0x0041EE80
HUFFNODE::HUFFNODE()
{
}

// 0x0041EE90
HUFFNODE::~HUFFNODE()
{
}

// List and bit-reader pieces of the run that no caller reaches, on placeholder types.
struct D2SCompPairStrc
{
    int nFirst;
    int nSecond;
};

struct D2SCompNextLinkStrc : D2StormLinkStrc
{
    D2StormLinkStrc* sub_0041E900_NextLink(int nLinkOffset);
};

// 0x0041E8F0
void __fastcall sub_0041E8F0(D2SCompPairStrc* pPair)
{
    pPair->nFirst = 0;
    pPair->nSecond = 0;
}

// 0x0041E900
D2StormLinkStrc* D2SCompNextLinkStrc::sub_0041E900_NextLink(int nLinkOffset)
{
    if ((int)m_next < 0)
        return (D2StormLinkStrc*)~(unsigned int)m_next;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)this - m_prevlink->m_next;
    return (D2StormLinkStrc*)(m_next + nLinkOffset);
}

// 0x0041E9C0
D2StormLinkStrc* __fastcall sub_0041E9C0_Identity(D2StormLinkStrc* pLink)
{
    return pLink;
}

// 0x0041E9E0
unsigned int CBitInput::sub_0041E9E0_Get(unsigned int nBits, unsigned int nMask)
{
    unsigned int nValue = Peek(nBits, nMask);
    Skip(nBits);
    return nValue;
}

// 0x0041EA20
int __stdcall sub_0041EA20_Forward(void* p1, unsigned int* p2, const void* p3, unsigned int n4)
{
    return SCompDecompress(p1, p2, (unsigned char*)p3, n4, 0);
}

// 0x0041EBC0
unsigned int CHuffmanCache::sub_0041EBC0_DecodeOne(CBitInput* input)
{
 unsigned int prefix=input->Peek7();
 HUFFCACHE* entry=&aCache[prefix];
 int cached=entry->nGeneration==nMinValidValue;
 HUFFNODE* node;
 if(cached) {
  if(entry->nBits>7) { input->Skip(7); node=entry->pNode; }
  else { input->Skip(entry->nBits); return entry->nValue; }
 } else node=Root();
 unsigned int depth=0;
 HUFFNODE* seventh=0;
 do {
  node=node->pChild;
  if(input->GetBit()) node=node->m_link.m_next;
  ++depth;
  if(depth==7) seventh=node;
 } while(node->pChild);
 if(!cached) {
  if(depth>7) {
   entry->nGeneration=nMinValidValue;
   entry->nBits=depth;
   entry->pNode=seventh;
  } else {
   unsigned int index=prefix&(0xFFFFFFFF>>(32-depth));
   unsigned int step=1<<depth;
   do {
    HUFFCACHE* e=&aCache[index];
    e->nGeneration=nMinValidValue;
    e->nBits=depth;
    e->nValue=node->nValue;
    index+=step;
   } while(index<=127);
  }
 }
 return node->nValue;
}

// build: symbol ?Next@?$TSLink@UHUFFNODE@@@@QAEPAUHUFFNODE@@XZ 0x0041EA40
// build: symbol ?RawNext@?$TSLink@UHUFFNODE@@@@QAEPAUHUFFNODE@@XZ 0x0041EA50
// build: symbol ??0?$TSLink@UHUFFNODE@@@@QAE@XZ 0x0041EA60
// build: symbol ?Unlink@?$TSLink@UHUFFNODE@@@@QAEXXZ 0x0041EA70
// build: symbol ?Head@?$TSList@UHUFFNODE@@U?$TSGetLink@UHUFFNODE@@@@@@QAEPAUHUFFNODE@@XZ 0x0041EAB0
// build: symbol ??1?$TSLink@UHUFFNODE@@@@QAE@XZ 0x0041EAE0
// build: symbol ?Link@?$TSList@UHUFFNODE@@U?$TSGetLink@UHUFFNODE@@@@@@QAEPAU?$TSLink@UHUFFNODE@@@@PBUHUFFNODE@@@Z 0x0041EB40
// build: symbol ?UnlinkNode@?$TSList@UHUFFNODE@@U?$TSGetLink@UHUFFNODE@@@@@@QAEXPAUHUFFNODE@@@Z 0x0041EB60
// build: symbol ??0?$TSLinkedNode@UHUFFNODE@@@@QAE@XZ 0x0041EBB0
// build: symbol ??1?$TSLinkedNode@UHUFFNODE@@@@QAE@XZ 0x0041ED30
// build: symbol ??0?$TSList@UHUFFNODE@@U?$TSGetLink@UHUFFNODE@@@@@@QAE@XZ 0x0041ED70
// build: symbol ?LinkNode@?$TSList@UHUFFNODE@@U?$TSGetLink@UHUFFNODE@@@@@@QAEXPAUHUFFNODE@@I0@Z 0x0041ED90
// build: symbol ?UnlinkAll@?$TSList@UHUFFNODE@@U?$TSGetLink@UHUFFNODE@@@@@@QAEXXZ 0x0041EE40
template HUFFNODE* TSLink<HUFFNODE>::Next();
template HUFFNODE* TSLink<HUFFNODE>::RawNext();
template TSLink<HUFFNODE>::TSLink();
template void TSLink<HUFFNODE>::Unlink();
template HUFFNODE* TSList<HUFFNODE>::Head();
template TSLink<HUFFNODE>::~TSLink();
template TSLink<HUFFNODE>* TSList<HUFFNODE>::Link(const HUFFNODE*);
template void TSList<HUFFNODE>::UnlinkNode(HUFFNODE*);
template TSList<HUFFNODE>::TSList();
template void TSList<HUFFNODE>::LinkNode(HUFFNODE*, unsigned int, HUFFNODE*);
template void TSList<HUFFNODE>::UnlinkAll();

// 0x0041EED0
HUFFNODE* CHuffman::NewItem(unsigned int nLinkType)
{
    HUFFNODE* pItem = tFreeList.Head();
    if (!pItem)
        pItem = &aItems[nItemsUsed++];
    tItemList.LinkNode(pItem, nLinkType, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    return pItem;
}

// 0x0041F350
void CHuffman::sub_0041F350_IncWeights(HUFFNODE* pItem)
{
    for (; pItem; pItem = pItem->pParent)
    {
        pItem->nWeight++;
        HUFFNODE* pCur = pItem;
        HUFFNODE* pNext;
        for (;;)
        {
            pNext = pCur->m_link.Next();
            if (!pNext || pNext->nWeight >= pItem->nWeight)
                break;
            pCur = pNext;
        }
        if (pCur == pItem)
            continue;
        tItemList.LinkNode(pCur, 2, pItem);
        tItemList.LinkNode(pItem, 2, pNext);
        HUFFNODE* pCurParentChild = pCur->pParent->pChild;
        if (pItem->pParent->pChild == pItem)
            pItem->pParent->pChild = pCur;
        if (pCurParentChild == pCur)
            pCur->pParent->pChild = pItem;
        HUFFNODE* pTemp = pItem->pParent;
        pItem->pParent = pCur->pParent;
        pCur->pParent = pTemp;
        nMinValidValue++;
    }
}

// build: symbol ??1?$TSList@UHUFFNODE@@U?$TSGetLink@UHUFFNODE@@@@@@QAE@XZ 0x0041F460
template TSList<HUFFNODE>::~TSList();

// 0x0041F4A0
CHuffman::CHuffman()
{
    nMinValidValue = 1;
    nItemsUsed = 0;
}

// 0x0041F510
void CHuffman::AddSymbol(unsigned int nValue)
{
    HUFFNODE* pFirst = tItemList.Head();
    HUFFNODE* pItem = tFreeList.Head();
    if (!pItem)
        pItem = &aItems[nItemsUsed++];
    tItemList.LinkNode(pItem, 1, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    pItem->nValue = pFirst->nValue;
    pItem->nWeight = pFirst->nWeight;
    pItem->pParent = pFirst;
    pItemsByValue[pItem->nValue] = pItem;
    pItem = tFreeList.Head();
    if (!pItem)
        pItem = &aItems[nItemsUsed++];
    tItemList.LinkNode(pItem, 1, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    pItem->nValue = nValue;
    pItem->nWeight = 0;
    pItem->pParent = pFirst;
    pItemsByValue[nValue] = pItem;
    pFirst->pChild = pItem;
    sub_0041F350_IncWeights(pItem);
}

// 0x0041F6A0
CHuffman::~CHuffman()
{
}

// 0x0041F740
unsigned int CHuffmanCache::Decompress(void* pOutput, unsigned int nOutputSize, CBitInput* pInput)
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

// 0x0041F950
CHuffmanCache::CHuffmanCache()
{
    for (int i = 0; i < 0x80; ++i)
        aCache[i].nGeneration = 0;
}

extern "C" const int gData_006CFCB8[32] = { // 0x006CFCB8
    -1, 0, -1, 4, -1, 2, -1, 6, -1, 1, -1, 5, -1, 3, -1, 7,
    -1, 1, -1, 5, -1, 3, -1, 7, -1, 2, -1, 4, -1, 6, -1, 8
};
#pragma comment(linker, "/alternatename:?gaADPCMIndexTable_006CFCB8@@3QBHB=_gData_006CFCB8")

extern "C" const int gData_006CFD38[89] = { // 0x006CFD38
    7, 8, 9, 10, 11, 12, 13, 14, 16, 17, 19, 21, 23, 25, 28, 31,
    34, 37, 41, 45, 50, 55, 60, 66, 73, 80, 88, 97, 107, 118, 130, 143,
    157, 173, 190, 209, 230, 253, 279, 307, 337, 371, 408, 449, 494, 544, 598, 658,
    724, 796, 876, 963, 1060, 1166, 1282, 1411, 1552, 1707, 1878, 2066, 2272, 2499, 2749, 3024,
    3327, 3660, 4026, 4428, 4871, 5358, 5894, 6484, 7132, 7845, 8630, 9493, 10442, 11487, 12635, 13899,
    15289, 16818, 18500, 20350, 22385, 24623, 27086, 29794, 32767
};
#pragma comment(linker, "/alternatename:?gaADPCMStepTable_006CFD38@@3QBHB=_gData_006CFD38")
