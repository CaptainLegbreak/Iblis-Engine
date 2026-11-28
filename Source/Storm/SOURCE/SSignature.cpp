#include "Storm.h"
#include "D2StormAutoLink.h"
#include "D2StormTypes.h"
#include "D2StormSha1.h"
#include "StormApi.h"
#include "stpl.h"

struct D2StormNodeListStrc;

struct D2StormHashBufferStrc;

namespace Crypt { struct RSA; }

struct CBitInput;

struct HUFFNODE;

struct D2StormHuffLinkSlotStrc;

struct CHuffman;



struct BigBuffer;

struct BigStack;


extern "C" void* __cdecl _alloca(unsigned int nSize);

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x00413020

int __stdcall SMemFree(void* pLocation, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

void* __stdcall SMemReAlloc(void* pLocation, unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags); // 0x004133D0

int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize); // 0x0041D200

void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith); // 0x0041D2C0

extern unsigned int gaCrc32Table[256]; // 0x00708448

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
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

struct D2StormHashBufferStrc
{
    unsigned int nSignSize;
    int nModulusSize;
    unsigned int nUsed;
    unsigned int nWindow;
    char* pBuffer;
    int unk0x14;
    Sha1 tHash;

    static void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, gszNew, -1, 0);
    }
    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
};

namespace Crypt
{

struct RSA
{
    void* hExponent;
    void* hModulus;

    RSA();                                                                                                  // 0x0041D4D0
    ~RSA();                                                                                                 // 0x0041D530
    void Prepare(const void* pExponent, unsigned int nExponentSize, const void* pModulus, int nModulusSize); // 0x00426070
    void Process(unsigned char* pData, unsigned int nSize);                                    // 0x004260A0
};

}

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
    int unk0x00[2];
    HUFFNODE aItems[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    HUFFNODE* pItemsByValue[0x102];
    D2StormHuffLinkSlotStrc aQuickLinks[0x80];

    CHuffman();                                                                                  // 0x0041F950
    ~CHuffman();                                                                                 // 0x0041F6A0
    void sub_0041F350_IncWeights(HUFFNODE* pItem);                                               // 0x0041F350
    unsigned int Decompress(void* pOutput, unsigned int nOutputSize, CBitInput* pInput); // 0x0041F740
    void AddSymbol(unsigned int nValue);
};

#include "D2StormArrayA.h"

struct BigBuffer
{
    D2StormArrayAStrc m_array;
    unsigned int m_start;

    int sub_004212D0_Get(unsigned int nIndex);                                                              // 0x004212D0
    void sub_004220D0_SetCount(unsigned int nCount);
    int InRange(unsigned int nIndex)
    {
        return m_start + nIndex < m_array.m_count;
    }
    int sub_00420DB0_InRange(unsigned int nIndex);
};

struct BigStack
{
    BigBuffer pRecords[16];
    unsigned int nUsed;

    BigBuffer* Push(int* pCounter); // 0x00420DD0
    void Drop(unsigned int nCount); // 0x00420E00
};

inline void* operator new(unsigned int, void* pPlace) throw();

void __stdcall SMemMove(void* pDest, const void* pSource, unsigned int nSize);                             // 0x0041D2E0

struct CBitInput
{
    unsigned char* pInput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    CBitInput(void* pInputBuffer);                                                                          // 0x0041D880
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
    unsigned int sub_0041D8D0_Peek(unsigned int nBits, unsigned int nMask);
    void sub_0041D900_Skip(unsigned int nBits);
};

struct D2StormNodeListAStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)pNode : &m_terminator;
    }
    void LinkNode(char* pNode, unsigned int nLinkType, char* pExisting);
};

inline void* operator new(unsigned int, void* pPlace) throw()
{
    return pPlace;
}

struct D2StormBigStrc;
void __stdcall SBigNew(D2StormBigStrc** ppBig);                                                             // 0x00423950
void __stdcall SBigDel(D2StormBigStrc* pBig);                                                               // 0x00424E40

// A big number handle that owns its SBig.
struct BigNum
{
    D2StormBigStrc* hHandle;

    BigNum();
    ~BigNum();
};

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

// 0x0041D340
static int __stdcall FindSignatureTag(const char* pData, unsigned int nSize, unsigned int nSignSize, unsigned int* pOffset)
{
    *pOffset = nSize - nSignSize - 4;
    if (nSize >= nSignSize + 4 && *(const int*)(pData + *pOffset) == 0x5349474E)
        return 1;
    return 0;
}

// 0x0041D370
static void __stdcall HashSignatureData(unsigned int nLen, const unsigned char* pData, unsigned char* pDigest)
{
    Sha1 tHash;
    tHash.Initialize();
    tHash.Append(pData, nLen);
    tHash.sub_00425F00_Final(pDigest);
}

// 0x0041D3B0
void __fastcall SSignatureVerifyStream_Begin(D2StormHashBufferStrc** ppBuffer, unsigned int nSignSize, int nModulusSize)
{
    *ppBuffer = new D2StormHashBufferStrc;
    (*ppBuffer)->nSignSize = nSignSize;
    (*ppBuffer)->nModulusSize = nModulusSize;
    (*ppBuffer)->nUsed = 0;
    (*ppBuffer)->nWindow = nSignSize + 4;
    (*ppBuffer)->pBuffer = (char*)SMemAlloc((*ppBuffer)->nWindow, ".\\SOURCE\\SSignature.cpp", 0x57, 8);
    (*ppBuffer)->tHash.Initialize();
}

// 0x0041D410
unsigned int __fastcall GetHashWindowSize(D2StormHashBufferStrc* pBuffer)
{
    return pBuffer->nWindow;
}

// 0x0041D420
void __fastcall HashBufferedData(D2StormHashBufferStrc* pBuffer, const char* pData, int nSize)
{
    int nExtra = nSize - pBuffer->nWindow;
    if (nExtra >= 0)
    {
        if (pBuffer->nUsed > 0)
            pBuffer->tHash.Append((const unsigned char*)pBuffer->pBuffer, pBuffer->nUsed);
        if (nExtra > 0)
            pBuffer->tHash.Append((const unsigned char*)pData, nExtra);
        SMemCopy(pBuffer->pBuffer, pData + nExtra, pBuffer->nWindow);
        pBuffer->nUsed = pBuffer->nWindow;
    }
    else
    {
        int nOver = pBuffer->nUsed - pBuffer->nWindow + nSize;
        if (nOver > 0)
        {
            pBuffer->tHash.Append((const unsigned char*)pBuffer->pBuffer, nOver);
            pBuffer->nUsed -= nOver;
            SMemMove(pBuffer->pBuffer, pBuffer->pBuffer + nOver, pBuffer->nUsed);
        }
        SMemCopy(pBuffer->pBuffer + pBuffer->nUsed, pData, nSize);
        pBuffer->nUsed += nSize;
    }
}

// 0x0041D590
int __fastcall SSignatureGenerate(char* pData, unsigned int* pnSize, const void* pExponent, unsigned int nSignSize, const void* pModulus1, int nModulusSize1, const void* pModulus2, int nModulusSize2)
{
    unsigned int nOffset;
    if (!FindSignatureTag(pData, *pnSize, nSignSize, &nOffset))
        nOffset = *pnSize;
    unsigned char* pDigest = (unsigned char*)_alloca(nSignSize);
    SMemFill(pDigest, nSignSize, 0xBB);
    pDigest[nSignSize - 1] = 0x0B;
    HashSignatureData(nOffset, (const unsigned char*)pData, pDigest);
    unsigned char* pSign = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pSign, pDigest, nSignSize);
    Crypt::RSA tKey1;
    tKey1.Prepare(pExponent, nSignSize, pModulus1, nModulusSize1);
    tKey1.Process(pSign, nSignSize);
    unsigned char* pCheck = (unsigned char*)_alloca(nSignSize);
    SMemCopy(pCheck, pSign, nSignSize);
    Crypt::RSA tKey2;
    tKey2.Prepare(pExponent, nSignSize, pModulus2, nModulusSize2);
    tKey2.Process(pCheck, nSignSize);
    if (SMemCmp(pCheck, pDigest, nSignSize))
        return 0;
    *(int*)(pData + nOffset) = 0x5349474E;
    SMemCopy(pData + nOffset + 4, pSign, nSignSize);
    *pnSize = nOffset + nSignSize + 4;
    return 1;
}

// 0x0041D6D0
int __fastcall SSignatureVerifyStream_Finish(D2StormHashBufferStrc* pBuffer, const void* pExponent, const void* pModulus)
{
    int bResult = 0;
    if (pBuffer->nUsed == pBuffer->nWindow && *(int*)pBuffer->pBuffer == 0x5349474E)
    {
        unsigned int nSize = pBuffer->nSignSize;
        unsigned char* pDigest = (unsigned char*)_alloca(nSize);
        SMemFill(pDigest, nSize, 0xBB);
        pDigest[pBuffer->nSignSize - 1] = 0x0B;
        pBuffer->tHash.sub_00425F00_Final(pDigest);
        unsigned char* pSign = (unsigned char*)_alloca(pBuffer->nSignSize);
        SMemCopy(pSign, pBuffer->pBuffer + 4, pBuffer->nSignSize);
        Crypt::RSA tKey;
        tKey.Prepare(pExponent, pBuffer->nSignSize, pModulus, pBuffer->nModulusSize);
        tKey.Process(pSign, pBuffer->nSignSize);
        bResult = !SMemCmp(pSign, pDigest, pBuffer->nSignSize);
    }
    SMemFree(pBuffer->pBuffer, ".\\SOURCE\\SSignature.cpp", 0xD0, 0);
    delete pBuffer;
    return bResult;
}

// 0x0041D7D0
int __fastcall SSignatureVerify(const void* pData, int nSize, const void* pExponent, unsigned int nSignSize, const void* pModulus, int nModulusSize)
{
    D2StormHashBufferStrc* pBuffer;
    SSignatureVerifyStream_Begin(&pBuffer, nSignSize, nModulusSize);
    HashBufferedData(pBuffer, (const char*)pData, nSize);
    return SSignatureVerifyStream_Finish(pBuffer, pExponent, pModulus);
}

// 0x0041D810
void __fastcall CrcBuffer(const unsigned char* pData, unsigned int nSize, unsigned int* pCrc, unsigned char nFlags)
{
    unsigned int nCrc = 0;
    if (pCrc)
        nCrc = *pCrc;
    if (nFlags & 1)
        nCrc = 0xFFFFFFFF;
    if (nFlags & 2)
    {
        while (nSize)
        {
            nCrc = (nCrc >> 8) ^ gaCrc32Table[(*pData ^ nCrc) & 0xFF];
            nSize--;
            pData++;
        }
    }
    if (nFlags & 4)
        nCrc = ~nCrc;
    if (pCrc)
        *pCrc = nCrc;
}

// 0x0041F9E0
void __fastcall HuffmanDecompress(void* pOutput, unsigned int* pOutputSize, void* pInput, unsigned int nInputSize, int nUnused)
{
    CBitInput tInput(pInput);
    CHuffman tTree;
    *pOutputSize = tTree.Decompress(pOutput, *pOutputSize, &tInput);
}

// 0x00420DB0
int BigBuffer::sub_00420DB0_InRange(unsigned int nIndex)
{
    return m_start + nIndex < m_array.m_count;
}

// 0x00420DD0
BigBuffer* BigStack::Push(int* pCounter)
{
    if (pCounter)
        ++*pCounter;
    return &pRecords[nUsed++];
}

// 0x00420E00
void BigStack::Drop(unsigned int nCount)
{
    nUsed -= nCount;
}

extern "C" const char gData_006D0224[20]; // 0x006D0224

extern "C" const char gData_006D0224[20] = ".\\SOURCE\\SEVT.CPP"; // 0x006D0224
#pragma comment(linker, "/alternatename:_gszSEvtCpp=_gData_006D0224")

extern unsigned int gaCrc32Table_00708448[256] = {
    0, 0x77073096, 0xEE0E612C, 0x990951BA, 0x76DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3, 0xEDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988, 0x9B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
    0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE, 0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7, 0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC, 0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
    0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172, 0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B, 0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940, 0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
    0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116, 0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F, 0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924, 0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
    0x76DC4190, 0x1DB7106, 0x98D220BC, 0xEFD5102A, 0x71B18589, 0x6B6B51F, 0x9FBFE4A5, 0xE8B8D433, 0x7807C9A2, 0xF00F934, 0x9609A88E, 0xE10E9818, 0x7F6A0DBB, 0x86D3D2D, 0x91646C97, 0xE6635C01,
    0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E, 0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457, 0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C, 0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
    0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2, 0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB, 0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0, 0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
    0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086, 0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F, 0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4, 0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
    0xEDB88320, 0x9ABFB3B6, 0x3B6E20C, 0x74B1D29A, 0xEAD54739, 0x9DD277AF, 0x4DB2615, 0x73DC1683, 0xE3630B12, 0x94643B84, 0xD6D6A3E, 0x7A6A5AA8, 0xE40ECF0B, 0x9309FF9D, 0xA00AE27, 0x7D079EB1,
    0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE, 0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7, 0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC, 0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
    0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252, 0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B, 0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60, 0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
    0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236, 0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F, 0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04, 0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
    0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x26D930A, 0x9C0906A9, 0xEB0E363F, 0x72076785, 0x5005713, 0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0xCB61B38, 0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0xBDBDF21,
    0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E, 0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777, 0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C, 0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
    0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2, 0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB, 0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0, 0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
    0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6, 0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF, 0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94, 0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
}; // 0x00708448
