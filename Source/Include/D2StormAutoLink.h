#pragma once
// Storm: the list link with a constructor and a destructor that unlinks it (the form Storm's list templates use
// for links they own). Include/D2StormLink.h has the plain link without them; a unit uses one or the other.

#include "D2Check.h"

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink;                            // 0x00
    char* m_next;                                           // 0x04

    D2StormLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormLinkStrc()
    {
        Unlink();
    }
    D2StormLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
            return (D2StormLinkStrc*)~(unsigned int)m_next;
        if (nLinkOffset < 0)
            nLinkOffset = (char*)this - m_prevlink->m_next;
        return (D2StormLinkStrc*)(m_next + nLinkOffset);
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
    D2StormLinkStrc* sub_0041E900_NextLink(int nLinkOffset); // 0x0041E900
    D2StormLinkStrc* sub_004203F0_NextLink(int nLinkOffset); // 0x004203F0
    void sub_00420610(); // 0x00420610
    void sub_00426BD0(); // 0x00426BD0
    D2StormLinkStrc* sub_00601BC0_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00601C30_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_00601D30_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0060E170_NextLink(int nLinkOffset);
    D2StormLinkStrc* sub_0060E1C0_NextLink(int nLinkOffset);
};

D2_CHECK_SIZE(D2StormLinkStrc, 0x8);
