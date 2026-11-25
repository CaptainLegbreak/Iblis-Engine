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
    unsigned int sub_0041EBC0_DecodeOne(D2StormHuffInputStrc*);
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


extern unsigned char gaHuffDistribution_006CF3A0[][0x102]; // 0x006CF3A0
void __stdcall SMemZero(void*, unsigned int); // 0x0041D300

typedef unsigned int size_t;



static D2SLogStrc* __stdcall LockLog(unsigned long* pIndex, int bCreate, void* hLog);
static void UnlockLog(unsigned long nIndex); // 0x0041FCE0

// 0x0041EBC0
unsigned int CHuffman::sub_0041EBC0_DecodeOne(D2StormHuffInputStrc* input)
{
 unsigned int prefix=input->Peek7();
 D2StormHuffCacheStrc* entry=&cache[prefix];
 int cached=entry->generation==generation;
 HUFFNODE* node;
 if(cached) {
  if(entry->bits>7) { input->Skip(7); node=entry->node; }
  else { input->Skip(entry->bits); return entry->value; }
 } else node=First();
 unsigned int depth=0;
 HUFFNODE* seventh=0;
 do {
  node=node->child;
  if(input->GetBit()) node=node->prev;
  ++depth;
  if(depth==7) seventh=node;
 } while(node->child);
 if(!cached) {
  if(depth>7) {
   entry->generation=generation;
   entry->bits=depth;
   entry->node=seventh;
  } else {
   unsigned int index=prefix&(0xFFFFFFFF>>(32-depth));
   unsigned int step=1<<depth;
   do {
    D2StormHuffCacheStrc* e=&cache[index];
    e->generation=generation;
    e->bits=depth;
    e->value=node->value;
    index+=step;
   } while(index<=127);
  }
 }
 return node->value;
}

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
        if (!gaHuffDistribution_006CF3A0[nCmpType][nValue]) continue;
        pItem = AllocateItem(2);
        pItemsByValue[nValue] = pItem;
        pItem->nValue = nValue;
        pItem->nWeight = gaHuffDistribution_006CF3A0[nCmpType][nValue];
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

extern "C" const unsigned char gData_006CF3A0[9][0x102]; // 0x006CF3A0

extern "C" const unsigned char gData_006CF3A0[9][0x102] = {
    {
    0xA, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
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
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2
},
    {
    0x54, 0x16, 0x16, 0xD, 0xC, 8, 6, 5, 6, 5, 6, 3, 4, 4, 3, 5,
    0xE, 0xB, 0x14, 0x13, 0x13, 9, 0xB, 6, 5, 4, 3, 2, 3, 2, 2, 2,
    0xD, 7, 9, 6, 6, 4, 3, 2, 4, 3, 3, 3, 3, 3, 2, 2,
    9, 6, 4, 4, 4, 4, 3, 2, 3, 2, 2, 2, 2, 3, 2, 4,
    8, 3, 4, 7, 9, 5, 3, 3, 3, 3, 2, 2, 2, 3, 2, 2,
    3, 2, 2, 2, 2, 2, 2, 2, 2, 1, 1, 1, 2, 1, 2, 2,
    6, 0xA, 8, 8, 6, 7, 4, 3, 4, 4, 2, 2, 4, 2, 3, 3,
    4, 3, 7, 7, 9, 6, 4, 3, 3, 2, 1, 2, 2, 2, 2, 2,
    0xA, 2, 2, 3, 2, 2, 1, 1, 2, 2, 2, 6, 3, 5, 2, 3,
    2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 3, 1, 1, 1,
    2, 1, 1, 1, 1, 1, 1, 2, 4, 4, 4, 7, 9, 8, 0xC, 2,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 3,
    4, 1, 2, 4, 5, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1,
    4, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 1, 1, 1, 1, 1, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1,
    2, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 2, 2, 2, 6, 0x4B
},
    {
    0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0x27, 0, 0, 0x23, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xFF, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 6, 0xE, 0x10, 4,
    6, 8, 5, 4, 4, 3, 3, 2, 2, 3, 3, 1, 1, 2, 1, 1,
    1, 4, 2, 4, 2, 2, 2, 1, 1, 4, 1, 1, 2, 3, 3, 2,
    3, 1, 3, 6, 4, 1, 1, 1, 1, 1, 1, 2, 1, 2, 1, 1,
    1, 0x29, 7, 0x16, 0x12, 0x40, 0xA, 0xA, 0x11, 0x25, 1, 3, 0x17, 0x10, 0x26, 0x2A,
    0x10, 1, 0x23, 0x23, 0x2F, 0x10, 6, 7, 2, 9, 1, 1, 1, 1, 1
},
    {
    0xFF, 0xB, 7, 5, 0xB, 2, 2, 2, 6, 2, 2, 1, 4, 2, 1, 3,
    9, 1, 1, 1, 3, 4, 1, 1, 2, 1, 1, 1, 2, 1, 1, 1,
    5, 1, 1, 1, 0xD, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1,
    0xA, 4, 2, 1, 6, 3, 2, 1, 1, 1, 1, 1, 3, 1, 1, 1,
    5, 2, 3, 4, 3, 3, 3, 2, 1, 1, 1, 2, 1, 2, 3, 3,
    1, 3, 1, 1, 2, 5, 1, 1, 4, 3, 5, 1, 3, 1, 3, 3,
    2, 1, 4, 3, 0xA, 6, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    2, 2, 1, 0xA, 2, 5, 1, 1, 2, 7, 2, 0x17, 1, 5, 1, 1,
    0xE, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    6, 2, 1, 4, 5, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 7, 1, 1, 2, 1, 1, 1, 1,
    2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 0x11
},
    { 0xFF, 0xFB, 0x98, 0x9A, 0x84, 0x85, 0x63, 0x64, 0x3E, 0x3E, 0x22, 0x22, 0x13, 0x13, 0x18, 0x17 },
    {
    0xFF, 0xF1, 0x9D, 0x9E, 0x9A, 0x9B, 0x9A, 0x97, 0x93, 0x93, 0x8C, 0x8E, 0x86, 0x88, 0x80, 0x82,
    0x7C, 0x7C, 0x72, 0x73, 0x69, 0x6B, 0x5F, 0x60, 0x55, 0x56, 0x4A, 0x4B, 0x40, 0x41, 0x37, 0x37,
    0x2F, 0x2F, 0x27, 0x27, 0x21, 0x21, 0x1B, 0x1C, 0x17, 0x17, 0x13, 0x13, 0x10, 0x10, 0xD, 0xD,
    0xB, 0xB, 9, 9, 8, 8, 7, 7, 6, 5, 5, 4, 4, 4, 0x19, 0x18
},
    {
    0xC3, 0xCB, 0xF5, 0x41, 0xFF, 0x7B, 0xF7, 0x21, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xBF, 0xCC, 0xF2, 0x40, 0xFD, 0x7C, 0xF7, 0x22, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x7A, 0x46
},
    {
    0xC3, 0xD9, 0xEF, 0x3D, 0xF9, 0x7C, 0xE9, 0x1E, 0xFD, 0xAB, 0xF1, 0x2C, 0xFC, 0x5B, 0xFE, 0x17,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xBD, 0xD9, 0xEC, 0x3D, 0xF5, 0x7D, 0xE8, 0x1D, 0xFB, 0xAE, 0xF0, 0x2C, 0xFB, 0x5C, 0xFF, 0x18,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x70, 0x6C
},
    {
    0xBA, 0xC5, 0xDA, 0x33, 0xE3, 0x6D, 0xD8, 0x18, 0xE5, 0x94, 0xDA, 0x23, 0xDF, 0x4A, 0xD1, 0x10,
    0xEE, 0xAF, 0xE4, 0x2C, 0xEA, 0x5A, 0xDE, 0x15, 0xF4, 0x87, 0xE9, 0x21, 0xF6, 0x43, 0xFC, 0x12,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0xB0, 0xC7, 0xD8, 0x33, 0xE3, 0x6B, 0xD6, 0x18, 0xE7, 0x95, 0xD8, 0x23, 0xDB, 0x49, 0xD0, 0x11,
    0xE9, 0xB2, 0xE2, 0x2B, 0xE8, 0x5C, 0xDD, 0x15, 0xF1, 0x87, 0xE7, 0x20, 0xF7, 0x44, 0xFF, 0x13,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0x5F, 0x9E
}
}; // 0x006CF3A0
#pragma comment(linker, "/alternatename:?gaHuffDistribution_006CF3A0@@3PAY0BAC@EA=_gData_006CF3A0")
