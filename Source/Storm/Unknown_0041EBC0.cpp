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

#include "gen/data/Source/Storm/Unknown_0041EBC0.inc"
