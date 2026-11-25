#include "Storm.h"
#include "D2StormLink.h"

struct BigNum;
struct CBitInput;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct HUFFNODE;
struct CHuffman;
struct D2AdpcmHeaderStrc;

void __stdcall SBigNew(void** phBig); // 0x00423950
void __stdcall SBigDel(void* hBig); // 0x00424E40

struct BigNum
{
    void* hHandle;

    BigNum();
    ~BigNum();
};

struct CBitInput
{
    unsigned int* pData;
    unsigned int dwBits;
    int nBitsLeft;

    CBitInput(void* pInputBuffer);
    int sub_0041D8A0_ReadBit();
};

#include "D2StormBitOutput.h"

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting)
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
};

struct HUFFNODE
{
    D2StormLinkStrc tLink;
    unsigned int nValue;
    unsigned int nWeight;
    HUFFNODE* pParent;
    HUFFNODE* pChild;
};

struct CHuffman
{
    int bIsCmp0;
    unsigned int nMinValidValue;
    HUFFNODE aItems[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    HUFFNODE* pItemsByValue[0x102];

    void sub_0041D9E0_EncodeOne(CBitOutput* pOutput, unsigned int nValue);
    void sub_0041F350_IncWeights(HUFFNODE* pItem);
};

// 0x0041D880
CBitInput::CBitInput(void* pInputBuffer)
{
    pData = (unsigned int*)pInputBuffer;
    dwBits = *pData++;
    nBitsLeft = 32;
}

// 0x0041D320
BigNum::BigNum()
{
    SBigNew(&hHandle);
}

// 0x0041D330
BigNum::~BigNum()
{
    SBigDel(hHandle);
}

// 0x0041D8A0
int CBitInput::sub_0041D8A0_ReadBit()
{
    int nBit = dwBits & 1;
    dwBits >>= 1;
    if (!--nBitsLeft)
    {
        dwBits = *pData++;
        nBitsLeft = 32;
    }
    return nBit;
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
            pNext = (HUFFNODE*)pCur->tLink.Next();
            if (!pNext || pNext->nWeight >= pItem->nWeight)
                break;
            pCur = pNext;
        }
        if (pCur == pItem)
            continue;
        tItemList.LinkNode((char*)pCur, 2, (char*)pItem);
        tItemList.LinkNode((char*)pItem, 2, (char*)pNext);
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
        const short nSample = *pIn++;
        aPredicted[i] = nSample;
        *(short*)pOut = nSample;
        pOut += 2;
    }
    int nGrowLeft = nInSize / 2 - (pOut - pOutStart);
    if (nGrowLeft < 0)
    {
        nGrowLeft = 0;
    }
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
            unsigned int nBit = 1;
            if (nMaxBit <= 0x20)
            {
                nLimit = nMaxBit;
            }
            for (;;)
            {
                if (nTotal + nStepSize <= nAbs)
                {
                    nTotal += nStepSize;
                    nMask |= nBit;
                }
                if (nBit == nLimit)
                {
                    break;
                }
                nStepSize >>= 1;
                nBit <<= 1;
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

void __fastcall ImaAdpcmMonoCompress(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = ImaAdpcmCompress(*pcbOutBuffer, pvInBuffer, cbInBuffer, 1, nLevel, pvOutBuffer);
}

void __fastcall ImaAdpcmStereoCompress(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = ImaAdpcmCompress(*pcbOutBuffer, pvInBuffer, cbInBuffer, 2, nLevel, pvOutBuffer);
}
