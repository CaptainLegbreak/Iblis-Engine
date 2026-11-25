#include "D2StormAutoLink.h"
struct HUFFNODE
{
    D2StormLinkStrc m_link;
    unsigned int nValue;
    unsigned int nWeight;
    HUFFNODE* pParent;
    HUFFNODE* pChild;

    HUFFNODE();                                                                                  // 0x0041EE80
    ~HUFFNODE();                                                                                 // 0x0041EE90
};

struct D2StormNodeListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
    D2StormNodeListStrc()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
        m_linkoffset = 0;
    }
};

class sub_0041F4A0_ConstructHuffTree
{
public:
    sub_0041F4A0_ConstructHuffTree();                                                                                        // 0x0041F4A0

    int bIsCmp0;
    unsigned int nMinValidValue;
    HUFFNODE aItems[0x203];
    D2StormNodeListStrc tFreeList;
    D2StormNodeListStrc tItemList;
    unsigned int nItemsUsed;
    char unk0x306C[0x408];
};

// 0x0041F4A0
sub_0041F4A0_ConstructHuffTree::sub_0041F4A0_ConstructHuffTree()
{
    nMinValidValue = 1;
    nItemsUsed = 0;
}
