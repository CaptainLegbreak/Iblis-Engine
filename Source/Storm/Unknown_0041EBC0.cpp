#include "D2GameTypes.h"
#include "Storm.h"

struct D2StormHuffInputStrc;
struct HUFFNODE;
struct D2StormHuffCacheStrc;
struct CHuffman;
struct D2StormLinkStrc;
struct D2StormNodeListStrc;
struct D2CriticalSectionStrc;
struct D2SLogStrc;

struct D2StormHuffInputStrc {
 unsigned char* input; unsigned int bits,count;
 unsigned int Peek7() {
  if(count<=7) { bits|=*(unsigned short*)input<<count; count+=16; input+=2; }
  return bits&127;
 }
 unsigned int GetBit() {
  unsigned int value=bits&1;
  bits>>=1;
  if(!--count) { bits=*(unsigned int*)input; input+=4; count=32; }
  return value;
 }
 void Skip(unsigned int n) { bits>>=n; count-=n; }
};

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
    char* Next()
    {
        return (int)m_next > 0 ? m_next : 0;
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
};

struct HUFFNODE
{
    union
    {
        struct
        {
            D2StormLinkStrc tLink;
        };
        struct
        {
            HUFFNODE* next;
            HUFFNODE* prev;
        };
    };
    union
    {
        unsigned int value;
        unsigned int nValue;
    };
    unsigned int nWeight;
    HUFFNODE* pParent;
    union
    {
        HUFFNODE* child;
        HUFFNODE* pChild;
    };
};

struct D2StormHuffCacheStrc { unsigned int generation,bits; union { unsigned int value; HUFFNODE* node; }; };

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

struct CHuffman
{
    int isCmp0;
    union
    {
        unsigned int generation;
        unsigned int nMinValidValue;
    };
    HUFFNODE aItems[0x203];
    D2StormNodeListStrc tFreeList;
    union
    {
        struct
        {
            D2StormNodeListStrc tItemList;
        };
        struct
        {
            unsigned char unk_305C[0x4];
            HUFFNODE* head;
        };
    };
    unsigned int nItemsUsed;
    HUFFNODE* pItemsByValue[0x102];
    D2StormHuffCacheStrc cache[128];
    unsigned int DecodeOne(D2StormHuffInputStrc*); // 0x0041EBC0
    HUFFNODE* First() {
  HUFFNODE* item=head->next->prev;
  return (int)item>0?item:0;
 }
    void BuildTree(unsigned char nCmpType);
    HUFFNODE* AllocateItem(unsigned int nLinkType)
    {
        HUFFNODE* pItem = (HUFFNODE*)tFreeList.m_terminator.Next();
        if (!pItem) pItem = &aItems[nItemsUsed++];
        tItemList.LinkNode((char*)pItem, nLinkType, 0);
        pItem->pParent = 0;
        pItem->pChild = 0;
        return pItem;
    }
};

#include "D2StormBitOutput.h"


extern unsigned char gaHuffDistribution[][0x102]; // 0x006CF3A0
void __stdcall SMemZero(void*, unsigned int); // 0x0041D300

typedef unsigned int size_t;



static D2SLogStrc* __stdcall LockLog(unsigned long* pIndex, int bCreate, void* hLog);
static void UnlockLog(unsigned long nIndex); // 0x0041FCE0

// 0x0041EF20
void CHuffman::BuildTree(unsigned char nCmpType)
{
    HUFFNODE* pItem;
    while ((pItem = (HUFFNODE*)tItemList.m_terminator.Next()) != 0)
        tFreeList.LinkNode((char*)pItem, 1, 0);
    SMemZero(pItemsByValue, sizeof(pItemsByValue));
    unsigned int nMaxWeight = 0;
    int nValue;
    for (nValue = 0; nValue < 256; ++nValue)
    {
        if (!gaHuffDistribution[nCmpType][nValue]) continue;
        pItem = AllocateItem(2);
        pItemsByValue[nValue] = pItem;
        pItem->nValue = nValue;
        pItem->nWeight = gaHuffDistribution[nCmpType][nValue];
        if (pItem->nWeight >= nMaxWeight) nMaxWeight = pItem->nWeight;
        else
        {
            HUFFNODE* pNext = (HUFFNODE*)tItemList.m_terminator.Next();
            while (pNext && pNext->nWeight < pItem->nWeight)
                pNext = (HUFFNODE*)pNext->tLink.Next();
            tItemList.LinkNode((char*)pItem, 2, (char*)pNext);
        }
    }
    for (; nValue < 258; ++nValue)
    {
        pItem = AllocateItem(1);
        pItemsByValue[nValue] = pItem;
        pItem->nValue = nValue;
        pItem->nWeight = 1;
    }
    HUFFNODE* pLow = (HUFFNODE*)tItemList.m_terminator.Next();
    while (pLow)
    {
        HUFFNODE* pNext = (HUFFNODE*)pLow->tLink.Next();
        if (!pNext)
            break;
        pItem = AllocateItem(2);
        pItem->nWeight = pLow->nWeight + pNext->nWeight;
        pItem->pChild = pLow;
        pLow->pParent = pItem;
        pNext->pParent = pItem;
        if (pItem->nWeight >= nMaxWeight) nMaxWeight = pItem->nWeight;
        else
        {
            HUFFNODE* pInsert = (HUFFNODE*)pNext->tLink.Next();
            while (pInsert && pInsert->nWeight < pItem->nWeight)
                pInsert = (HUFFNODE*)pInsert->tLink.Next();
            tItemList.LinkNode((char*)pItem, 2, (char*)pInsert);
        }
        pLow = (HUFFNODE*)pNext->tLink.Next();
    }
    nMinValidValue = 1;
}

extern "C" const unsigned char gData_006CF3A0[9][0x102] = { // 0x006CF3A0
    {
        10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2,
        0, 0
    },
    {
        84, 22, 22, 13, 12, 8, 6, 5, 6, 5, 6, 3, 4, 4, 3, 5,
        14, 11, 20, 19, 19, 9, 11, 6, 5, 4, 3, 2, 3, 2, 2, 2,
        13, 7, 9, 6, 6, 4, 3, 2, 4, 3, 3, 3, 3, 3, 2, 2,
        9, 6, 4, 4, 4, 4, 3, 2, 3, 2, 2, 2, 2, 3, 2, 4,
        8, 3, 4, 7, 9, 5, 3, 3, 3, 3, 2, 2, 2, 3, 2, 2,
        3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2,
        6, 10, 8, 8, 6, 7, 4, 3, 4, 4, 2, 2, 4, 2, 3, 3,
        4, 3, 7, 7, 9, 6, 4, 3, 3, 2, 1, 2, 2, 2, 2, 2,
        10, 2, 2, 3, 2, 2, 1, 1, 2, 2, 2, 6, 3, 5, 2, 3,
        2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1,
        2, 1, 1, 1, 1, 1, 1, 2, 4, 4, 4, 7, 9, 8, 12, 2,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 3,
        4, 1, 2, 4, 5, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1,
        4, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1,
        2, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 6, 75,
        0, 0
    },
    {
        0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 39, 0, 0, 35, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        255, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 6, 14, 16, 4,
        6, 8, 5, 4, 4, 3, 3, 2, 2, 3, 3, 1, 1, 2, 1, 1,
        1, 4, 2, 4, 2, 2, 2, 1, 1, 4, 1, 1, 2, 3, 3, 2,
        3, 1, 3, 6, 4, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1,
        1, 41, 7, 22, 18, 64, 10, 10, 17, 37, 1, 3, 23, 16, 38, 42,
        16, 1, 35, 35, 47, 16, 6, 7, 2, 9, 1, 1, 1, 1, 1
    },
    {
        255, 11, 7, 5, 11, 2, 2, 2, 6, 2, 2, 1, 4, 2, 1, 3,
        9, 1, 1, 1, 3, 4, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1,
        5, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
        10, 4, 2, 1, 6, 3, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1,
        5, 2, 3, 4, 3, 3, 3, 2, 1, 1, 1, 2, 1, 2, 3, 3,
        1, 3, 1, 1, 2, 5, 1, 1, 4, 3, 5, 1, 3, 1, 3, 3,
        2, 1, 4, 3, 10, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        2, 2, 1, 10, 2, 5, 1, 1, 2, 7, 2, 23, 1, 5, 1, 1,
        14, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        6, 2, 1, 4, 5, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 2, 1, 1, 1, 1,
        2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 17,
        0, 0
    },
    { 255, 251, 152, 154, 132, 133, 99, 100, 62, 62, 34, 34, 19, 19, 24, 23 },
    {
        255, 241, 157, 158, 154, 155, 154, 151, 147, 147, 140, 142, 134, 136, 128, 130,
        124, 124, 114, 115, 105, 107, 95, 96, 85, 86, 74, 75, 64, 65, 55, 55,
        47, 47, 39, 39, 33, 33, 27, 28, 23, 23, 19, 19, 16, 16, 13, 13,
        11, 11, 9, 9, 8, 8, 7, 7, 6, 5, 5, 4, 4, 4, 25, 24
    },
    {
        195, 203, 245, 65, 255, 123, 247, 33, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        191, 204, 242, 64, 253, 124, 247, 34, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        122, 70
    },
    {
        195, 217, 239, 61, 249, 124, 233, 30, 253, 171, 241, 44, 252, 91, 254, 23,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        189, 217, 236, 61, 245, 125, 232, 29, 251, 174, 240, 44, 251, 92, 255, 24,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        112, 108
    },
    {
        186, 197, 218, 51, 227, 109, 216, 24, 229, 148, 218, 35, 223, 74, 209, 16,
        238, 175, 228, 44, 234, 90, 222, 21, 244, 135, 233, 33, 246, 67, 252, 18,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        176, 199, 216, 51, 227, 107, 214, 24, 231, 149, 216, 35, 219, 73, 208, 17,
        233, 178, 226, 43, 232, 92, 221, 21, 241, 135, 231, 32, 247, 68, 255, 19,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
        95, 158
    }
};
#pragma comment(linker, "/alternatename:?gaHuffDistribution_006CF3A0@@3PAY0BAC@EA=_gData_006CF3A0")
