#pragma once
// Storm's intrusive lists and growable arrays as the cel loader (CelCmp*.cpp) uses them: the list kinds
// (slot, node, E, A lists) and the slot and entry arrays.

struct D2StormEntry38Strc;
struct D2StormHashChunkStrc;
struct D2CelEntryStrc;

extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags); // 0x00412650
#include "D2StormAutoLink.h"

struct D2StormNodeStrc
{
    D2StormLinkStrc f_0;                                    // 0x00
};

struct D2StormSlotLinkStrc
{
    D2StormSlotLinkStrc* m_prevlink;                        // 0x00
    char* m_next;                                           // 0x04

    D2StormSlotLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormSlotLinkStrc()
    {
        Unlink();
    }
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
    D2StormSlotLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormSlotLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormSlotLinkStrc*)(m_next + nLinkOffset);
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
    char* Next()
    {
        return (int)m_next <= 0 ? 0 : m_next;
    }
};

struct D2StormSlotListStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormSlotLinkStrc m_terminator;                       // 0x04

    D2StormSlotListStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    D2StormSlotListStrc(const D2StormSlotListStrc& source)
    {
        m_linkoffset = source.m_linkoffset;
        InitializeTerminator();
    }
    ~D2StormSlotListStrc()
    {
        UnlinkAll();
    }
    static void operator delete(void* pMemory)
    {
        if (pMemory)
            SMemFree(pMemory, "delete", -1, 0);
    }
    D2StormSlotLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormSlotLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void LinkToTail(char* pNode)
    {
        D2StormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormSlotLinkStrc* pExistingLink = Link(0);
        D2StormSlotLinkStrc* pPrevLink = pExistingLink->m_prevlink;
        pLink->m_prevlink = pPrevLink;
        pLink->m_next = pPrevLink->m_next;
        pPrevLink->m_next = pNode;
        pExistingLink->m_prevlink = pLink;
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormSlotLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormSlotLinkStrc* pExistingLink = Link(pExistingNode);
        D2StormSlotLinkStrc* pPrevLink;
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    void sub_006C4290(char* pNode)
    {
        Link(pNode)->Unlink();
    }
    void UnlinkAll() throw();                               // 0x00602640
    void CelReuseListLinkNode(char* pNode, int nLinkType, char* pExistingNode);                            // 0x006024E0
    void CelReuseListDeleteAll();                                                                          // 0x00602D20
    char* CelReuseListDeleteNode(char* pNode);
    D2StormEntry38Strc* CelReuseListNewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    char* CelSlotListRawNext(char* pNode);
    void CelSlotListChangeLinkOffset(int nLinkOffset);
};

struct D2StormNodeListStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormLinkStrc m_terminator;                           // 0x04

    D2StormNodeListStrc()
    {
        m_linkoffset = 0;
        InitializeTerminator();
    }
    D2StormNodeListStrc(const D2StormNodeListStrc& source);                                                 // 0x00603F90
    ~D2StormNodeListStrc()
    {
        UnlinkAll();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    D2StormLinkStrc* Link(D2StormNodeStrc* pNode)
    {
        return pNode ? &pNode->f_0 : &m_terminator;
    }
    D2StormNodeStrc* Head()
    {
        return (int)m_terminator.m_next > 0 ? (D2StormNodeStrc*)m_terminator.m_next : 0;
    }
    void LinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        D2StormLinkStrc* pPrevLink;
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = (char*)pNode;
            break;
        default:
            pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = (char*)pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    D2CelEntryStrc* NewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
// build: symbol ?UnlinkAll@D2StormNodeListStrc@@QAEXXZ 0x006025E0
    void UnlinkAll();
    D2StormLinkStrc* CelEntryListLink(D2StormNodeStrc* pNode);
    void CelEntryListLinkNode(D2StormNodeStrc* pNode, int nLinkType, D2StormNodeStrc* pExistingNode);      // 0x00601FC0
    char* CelEntryListNext(D2StormNodeStrc* pNode);
    void CelEntryListUnlinkNode(D2StormNodeStrc* pNode);
    void CelEntryListDeleteAll();                                                                          // 0x00602BF0
    D2CelEntryStrc* CelEntryListNewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    D2CelEntryStrc* CelEntryListDeleteNode(D2CelEntryStrc* pNode);
};

struct D2StormListEStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormLinkStrc m_terminator;                           // 0x04

    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return (int)m_terminator.m_next > 0 ? m_terminator.m_next : 0;
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
// build: symbol ?UnlinkAll@D2StormListEStrc@@QAEXXZ 0x00602690
    void UnlinkAll();
    D2StormLinkStrc* sub_00602110_Link(char* pNode);
    D2StormLinkStrc* sub_00602280_Link(char* pNode);
    void sub_006022A0_UnlinkNode(char* pNode);
    void sub_006022F0_InitLinkField(int nLinkOffset);
    char* sub_00602310_Next(char* pNode);
    void sub_00602350_InitLinkField(int nLinkOffset);
    void sub_00602590_UnlinkNode(char* pNode);
    void CelChunkListDeleteAll();                                                                          // 0x00603B60
    void sub_00603F50_CopyLinkOffset(const D2StormListEStrc* pSource);
    void CelChunkListLinkNode(char* pNode, int nLinkType, char* pExistingNode);                            // 0x00603FC0
    D2StormHashChunkStrc* CelChunkListNewNode(int nLinkType, unsigned int nExtraBytes, unsigned int nFlags);
    void sub_0060E370_CopyLinkOffset(const D2StormListEStrc* pSource);
    void sub_0060E390_CopyLinkOffset(const D2StormListEStrc* pSource);
};

// The hash table's chunk list: a list E that unlinks its nodes when it goes.
struct D2StormHashChunkListStrc : D2StormListEStrc
{
    ~D2StormHashChunkListStrc()
    {
        UnlinkAll();
    }
};

struct D2StormListAStrc
{
    int m_linkoffset;                                       // 0x00
    D2StormLinkStrc m_terminator;                           // 0x04

    ~D2StormListAStrc();
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
    void UnlinkAll();
};

struct D2StormSlotArrayStrc
{
    unsigned int m_alloc;                                       // 0x00
    unsigned int m_count;                                       // 0x04
    D2StormSlotListStrc* m_data;                               // 0x08
    unsigned int m_chunk;                                       // 0x0C

    D2StormSlotArrayStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
    ~D2StormSlotArrayStrc() throw();                                                                        // 0x00603060
    void Clear()
    {
        this->~D2StormSlotArrayStrc();
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
    }
    unsigned int CelSlotArrayCalcChunkSize(unsigned int nCount);
    void CelSlotArrayReallocData(unsigned int nAlloc);                                                     // 0x00602F10
    void CelSlotArrayReserve(unsigned int nCount, int bRound);
    void CelSlotArraySetCount(unsigned int nCount);                                                        // 0x00603300
    void CelSlotArrayClear();
    void sub_00603850_SetCount(unsigned int nCount);
};

struct D2StormSlotGrowArrayStrc : D2StormSlotArrayStrc
{

// build: symbol ??1D2StormSlotGrowArrayStrc@@QAE@XZ 0x00603240
    ~D2StormSlotGrowArrayStrc() throw();
};

struct D2StormEntryArrayStrc
{
    unsigned int m_alloc;                                       // 0x00
    unsigned int m_count;                                       // 0x04
    D2StormEntry38Strc* m_data;                                // 0x08
    unsigned int m_chunk;                                       // 0x0C

    D2StormEntryArrayStrc()
    {
        m_alloc = 0;
        m_count = 0;
        m_data = 0;
        m_chunk = 0;
    }
    ~D2StormEntryArrayStrc();                                                                               // 0x00603140
    unsigned int CelListArrayCalcChunkSize(unsigned int nCount);
    void sub_006041B0_ReallocData(unsigned int nAlloc);                                                     // 0x006041B0
    D2StormEntryArrayStrc* sub_006043A0_Init();                                                             // 0x006043A0
    D2StormEntry38Strc* sub_006043B0_New();                                                                 // 0x006043B0
    void CelListArrayReserve(unsigned int nCount, int bRound);
    void CelListArrayGrow(unsigned int nCount);
};
