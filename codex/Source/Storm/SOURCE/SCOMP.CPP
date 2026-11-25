#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"
#include "SValidate.h"

struct D2StormHashBufferStrc;

struct D2CriticalSectionStrc;

struct D2FogBlockStrc;

struct D2StormMemSourceStrc;

struct D2StormMemSinkStrc;

struct D2StormCompParamStrc;

struct D2StormZArenaStrc;

struct D2StormNodeListAStrc;

struct HUFFNODE;

struct CHuffman;

struct D2AdpcmHeaderStrc;

struct D2SCompLinkStrc;

struct D2SCompListViewStrc;

struct D2SCompLinkNextAStrc;

struct D2SCompLinkNextBStrc;

struct D2SCompLinkPrevStrc;

struct D2SCompLinkRawAStrc;

struct D2SCompLinkRawBStrc;

struct D2SCompUnlinkAStrc;

struct D2SCompUnlinkBStrc;

struct D2SCompUnlinkCStrc;

struct D2SCompUnlinkDStrc;

struct D2SCompListTermStrc;

struct D2SCompLinkCtorAStrc;

struct D2SCompLinkCtorBStrc;

struct D2SCompListHeadStrc;

struct D2SCompListTailStrc;

struct D2SCompListInitStrc;

struct D2SCompTermLinkStrc;

struct D2SCompListStrc;

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[2];
    int bReportLeak;
    int bInUse;
};

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

struct D2StormNodeListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    D2StormLinkStrc* sub_0041EB40_Link(char* pNode);
    void sub_0041EB60_UnlinkNode(char* pNode);
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);                       // 0x0041ED90
};

struct HUFFNODE
{
    D2StormLinkStrc tLink;
    unsigned int nValue;
    unsigned int nWeight;
    HUFFNODE* pParent;
    HUFFNODE* pChild;

    HUFFNODE();
    ~HUFFNODE();
};

struct CHuffman
{
    int unk0x00[2];
    HUFFNODE aItems[0x203];
    D2StormNodeListAStrc tFreeList;
    D2StormNodeListAStrc tItemList;
    unsigned int nItemsUsed;

    HUFFNODE* NewItem(unsigned int nLinkType); // 0x0041EED0
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

struct D2SCompLinkNextBStrc { D2SCompLinkStrc tLink; char* sub_0041EA40_Next(); };

struct D2SCompLinkPrevStrc { D2SCompLinkStrc tLink; char* sub_0041E940_Prev(); };

struct D2SCompLinkRawAStrc { D2SCompLinkStrc tLink; char* sub_0041E960_RawNext(); };

struct D2SCompLinkRawBStrc { D2SCompLinkStrc tLink; char* sub_0041EA50_RawNext(); };

struct D2SCompUnlinkAStrc { D2SCompLinkStrc tLink; void sub_0041E970_Unlink(); };

struct D2SCompUnlinkBStrc { D2SCompLinkStrc tLink; void sub_0041EA70_Unlink(); };

struct D2SCompUnlinkCStrc { D2SCompLinkStrc tLink; void sub_0041EAE0_Unlink(); };

struct D2SCompUnlinkDStrc { D2SCompLinkStrc tLink; void sub_0041ED30_Unlink(); };

struct D2SCompListTermStrc { D2SCompListViewStrc tList; void sub_0041E9B0_InitializeTerminator(); };

struct D2SCompLinkCtorAStrc { D2SCompLinkStrc* m_prevlink; char* m_next; D2SCompLinkCtorAStrc(); };

struct D2SCompLinkCtorBStrc { D2SCompLinkStrc* m_prevlink; char* m_next; D2SCompLinkCtorBStrc(); };

struct D2SCompListHeadStrc { D2SCompListViewStrc tList; char* sub_0041EAB0_Head(); };

struct D2SCompListTailStrc { D2SCompListViewStrc tList; char* sub_0041EAC0_Tail(); };

struct D2SCompListInitStrc { D2SCompListViewStrc tList; void sub_0041EB20_Init(); };

struct D2SCompTermLinkStrc
{
    D2SCompTermLinkStrc* m_prevlink;
    char* m_next;
    D2SCompTermLinkStrc() { m_prevlink = 0; m_next = 0; }
};

struct D2SCompListStrc
{
    int m_linkoffset;
    D2SCompTermLinkStrc m_terminator;
    D2SCompListStrc();
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

SCompBufferState gSCompBuffer_0077920C;         // 0x0077920C


void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize); // 0x0041D2A0

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

static int __stdcall ImaAdpcmCompress(int nOutSize, const short* pIn, int nInSize, unsigned int nChannels, unsigned char nLevel, unsigned char* pOut) // 0x0041DA60
{
    unsigned char* pOutStart = pOut;
    if ((unsigned int)nOutSize < 2)
    {
        return 2;
    }
    D2AdpcmHeaderStrc tHeader;
    tHeader.nShift = nLevel - 1;
    tHeader.nZero = 0;
    *(D2AdpcmHeaderStrc*)pOut = tHeader;
    pOut += 2;
    const int nHeader = nChannels * 2 + (pOut - pOutStart);
    if (nHeader > nOutSize)
    {
        return nHeader;
    }
    int aPredicted[2];
    int aStepIndex[2];
    aStepIndex[0] = 0x2C;
    aStepIndex[1] = 0x2C;
    for (unsigned int i = 0; i < nChannels; i++)
    {
        const int nSample = *pIn++;
        aPredicted[i] = nSample;
        *(short*)pOut = nSample;
        pOut += 2;
    }
    int nGrowLeft = nInSize / 2 - (pOut - pOutStart);
    nGrowLeft = nGrowLeft < 0 ? 0 : nGrowLeft;
    unsigned int nIndex = nChannels;
    const unsigned int nWords = (unsigned int)nInSize >> 1;
    int nChannel = nChannels - 1;
    if (nIndex >= nWords)
    {
        return pOut - pOutStart;
    }
    do
    {
        if ((pOut - pOutStart) + 2 > nOutSize)
        {
            return (pOut - pOutStart) + 2;
        }
        if (nChannels == 2)
        {
            nChannel = nChannel == 0;
        }
        const int nSample = *pIn++;
        int nDifference = nSample - aPredicted[nChannel];
        const unsigned int nAbs = nDifference < 0 ? -nDifference : nDifference;
        const unsigned char nSignBit = nSample >= aPredicted[nChannel] ? 0 : 0x40;
        unsigned int nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
        if (nAbs < (nStepSize >> nLevel))
        {
            if (aStepIndex[nChannel])
            {
                aStepIndex[nChannel]--;
            }
            *pOut++ = 0x80;
        }
        else
        {
            while (nAbs > nStepSize * 2 && aStepIndex[nChannel] < 0x58 && nGrowLeft)
            {
                aStepIndex[nChannel] += 8;
                if (aStepIndex[nChannel] > 0x58)
                {
                    aStepIndex[nChannel] = 0x58;
                }
                nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
                nGrowLeft--;
                *pOut++ = 0x81;
            }
            const unsigned int nStepRest = nStepSize >> tHeader.nShift;
            const unsigned int nMaxBit = 1 << (nLevel - 2);
            unsigned int nTotal = 0;
            unsigned int nMask = 0;
            unsigned int nLimit = 0x20;
            nInSize = 1;
            if (nMaxBit <= 0x20)
            {
                nLimit = nMaxBit;
            }
            for (;;)
            {
                if (nTotal + nStepSize <= nAbs)
                {
                    nTotal += nStepSize;
                    nMask |= nInSize;
                }
                if (nInSize == nLimit)
                {
                    break;
                }
                nStepSize >>= 1;
                nInSize <<= 1;
            }
            const int nDelta = nTotal + nStepRest;
            int nPredicted = aPredicted[nChannel];
            if (nSignBit)
            {
                nPredicted -= nDelta;
                if (nPredicted < -0x8000)
                {
                    nPredicted = -0x8000;
                }
            }
            else
            {
                nPredicted += nDelta;
                if (nPredicted > 0x7FFF)
                {
                    nPredicted = 0x7FFF;
                }
            }
            *pOut++ = nSignBit | (unsigned char)nMask;
            aStepIndex[nChannel] += gaADPCMIndexTable_006CFCB8[nMask & 0x1F];
            aPredicted[nChannel] = nPredicted;
            if (aStepIndex[nChannel] < 0)
            {
                aStepIndex[nChannel] = 0;
            }
            else if (aStepIndex[nChannel] > 0x58)
            {
                aStepIndex[nChannel] = 0x58;
            }
        }
        nIndex++;
    } while (nIndex < nWords);
    return pOut - pOutStart;
}

// 0x0041E360
void __fastcall ImaAdpcmMonoCompress(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = ImaAdpcmCompress(*pcbOutBuffer, pvInBuffer, cbInBuffer, 1, nLevel, pvOutBuffer);
}

static int __stdcall ImaAdpcmDecompress(short* pOut, int nInLength, unsigned int nOutSize, unsigned char* pIn, unsigned int nChannels) // 0x0041DCE0
{
    int aPredicted[2];
    int aStep[2];
    aStep[0] = 0x2C;
    aStep[1] = 0x2C;
    unsigned char* pHeader = pIn;
    unsigned char* pInEnd = pIn + nInLength;
    short* pOutStart = pOut;
    pIn += 2;
    for (unsigned int i = 0; i < nChannels; i++)
    {
        const int nSample = *(short*)pIn;
        pIn += 2;
        aPredicted[i] = nSample;
        if (nOutSize < 2)
        {
            return (char*)pOut - (char*)pOutStart;
        }
        nOutSize -= 2;
        *pOut = nSample;
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
                continue;
            case 1:
                aStep[nChannel] += 8;
                if (aStep[nChannel] > 0x58)
                {
                    aStep[nChannel] = 0x58;
                }
                break;
            case 2:
                aStep[nChannel] -= 8;
                if (aStep[nChannel] < 0)
                {
                    aStep[nChannel] = 0;
                }
                break;
            default:
                continue;
            }
            if (nChannels == 2)
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
    *pOutSize = ImaAdpcmDecompress(pOut, nInLength, *pOutSize, pIn, 1);
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
    *pOutSize = ImaAdpcmDecompress(pOut, nInLength, *pOutSize, pIn, 2);
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
#include "gen/data/Source/Storm/SOURCE/SCOMP.static/gtCompTable_006CFE9C.inc"

// build: symbol _gtDecompTable_006CFEC4 0x006CFEC4
#include "gen/data/Source/Storm/SOURCE/SCOMP.static/gtDecompTable_006CFEC4.inc"

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

// 0x0041EA40
char* D2SCompLinkNextBStrc::sub_0041EA40_Next() { return (int)tLink.m_next <= 0 ? 0 : tLink.m_next; }

// 0x0041EA50
char* D2SCompLinkRawBStrc::sub_0041EA50_RawNext() { return tLink.m_next; }

// 0x0041EA60
D2SCompLinkCtorAStrc::D2SCompLinkCtorAStrc() { m_prevlink = 0; m_next = 0; }

// 0x0041EA70
void D2SCompUnlinkBStrc::sub_0041EA70_Unlink() { tLink.Unlink(); }

// 0x0041EAB0
char* D2SCompListHeadStrc::sub_0041EAB0_Head() { return (int)tList.m_terminator.m_next <= 0 ? 0 : tList.m_terminator.m_next; }

// 0x0041EAC0
char* D2SCompListTailStrc::sub_0041EAC0_Tail()
{
    D2SCompLinkStrc* pLink = tList.m_terminator.m_prevlink->m_prevlink;
    return (int)pLink->m_next <= 0 ? 0 : pLink->m_next;
}

// 0x0041EAE0
void D2SCompUnlinkCStrc::sub_0041EAE0_Unlink() { tLink.Unlink(); }

// 0x0041EB20
void D2SCompListInitStrc::sub_0041EB20_Init()
{
    tList.m_linkoffset = 0;
    tList.m_terminator.m_prevlink = &tList.m_terminator;
    tList.m_terminator.m_next = (char*)~(unsigned int)&tList.m_terminator;
}

// 0x0041EBB0
D2SCompLinkCtorBStrc::D2SCompLinkCtorBStrc() { m_prevlink = 0; m_next = 0; }

// 0x0041ED30
void D2SCompUnlinkDStrc::sub_0041ED30_Unlink() { tLink.Unlink(); }

// 0x0041ED70
D2SCompListStrc::D2SCompListStrc()
{
    m_linkoffset = 0;
    m_terminator.m_prevlink = &m_terminator;
    m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
}

// 0x0041EE80
HUFFNODE::HUFFNODE()
{
    tLink.m_prevlink = 0;
    tLink.m_next = 0;
}

// 0x0041EE90
HUFFNODE::~HUFFNODE()
{
    tLink.Unlink();
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

struct D2SCompBitInputStrc
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

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
    unsigned int sub_0041E9E0_Get(unsigned int nBits, unsigned int nMask);
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    char* Head()
    {
        return m_terminator.Next();
    }
    void sub_0041EE40_UnlinkAll();
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
unsigned int D2SCompBitInputStrc::sub_0041E9E0_Get(unsigned int nBits, unsigned int nMask)
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

// 0x0041EB40
D2StormLinkStrc* D2StormNodeListAStrc::sub_0041EB40_Link(char* pNode)
{
    return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
}

// 0x0041EB60
void D2StormNodeListAStrc::sub_0041EB60_UnlinkNode(char* pNode)
{
    Link(pNode)->Unlink();
}

// 0x0041ED90
void D2StormNodeListAStrc::LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
{
    D2StormLinkStrc* pLink = Link(pNode);
    pLink->Unlink();
    D2StormLinkStrc* pExistingLink = Link(pExisting);
    switch (nLinkType)
    {
    case 1:
        pLink->m_prevlink = pExistingLink;
        pLink->m_next = pExistingLink->m_next;
        pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
        pExistingLink->m_next = pNode;
        break;
    default:
        {
            D2StormLinkStrc* pPrev = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrev;
            pLink->m_next = pPrev->m_next;
            pPrev->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
        }
        break;
    }
}

// 0x0041EE40
void D2StormNodeListStrc::sub_0041EE40_UnlinkAll()
{
    while (char* pNode = Head())
        ((D2StormLinkStrc*)pNode)->Unlink();
}

// 0x0041EED0
HUFFNODE* CHuffman::NewItem(unsigned int nLinkType)
{
    HUFFNODE* pItem = (HUFFNODE*)tFreeList.Head();
    if (!pItem)
        pItem = &aItems[nItemsUsed++];
    tItemList.LinkNode((char*)pItem, nLinkType, 0);
    pItem->pParent = 0;
    pItem->pChild = 0;
    return pItem;
}

#include "gen/data/Source/Storm/SOURCE/SCOMP.inc"
