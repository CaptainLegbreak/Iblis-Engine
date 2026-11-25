#pragma once
// Storm: the link node of Storm's intrusive lists.

#include "D2Check.h"
#include "D2Structs.h"

struct D2StormLinkStrc;

struct D2StormLinkStrc
{
    D2StormLinkStrc* m_prevlink; // 0x00
    char* m_next; // 0x04

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
        return (int)m_next <= 0 ? 0 : m_next;
    }
    char* Prev()
    {
        return m_prevlink->m_prevlink->Next();
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
    D2StormLinkStrc* LOGMANAGER_NextLink(int nLinkOffset); // 0x0040F4F0
    D2StormLinkStrc* sub_00416770_NextLink(int nLinkOffset); // 0x00416770
    D2StormLinkStrc* sub_004168C0_NextLink(int nLinkOffset); // 0x004168C0
    D2StormLinkStrc* sub_00416930_NextLink(int nLinkOffset); // 0x00416930
    D2StormLinkStrc* sub_00416970_NextLink(int nLinkOffset); // 0x00416970
    D2StormLinkStrc* sub_004169B0_NextLink(int nLinkOffset); // 0x004169B0
    D2StormLinkStrc* sub_0041C3A0_NextLink(int nLinkOffset); // 0x0041C3A0
    void sub_00417E50(); // 0x00417E50
    void sub_0041C650(); // 0x0041C650
    D2StormLinkStrc* sub_00426930_NextLink(int nLinkOffset); // 0x00426930
    int sub_005174AA_Next(); // 0x005174AA
    int sub_005174B4_RawNext(); // 0x005174B4
    void sub_005174B8_Clear(); // 0x005174B8
    D2StormLinkStrc* __thiscall sub_005174C0(int nLinkOffset); // 0x005174C0
    void __thiscall sub_005174E2_Unlink(); // 0x005174E2
    void __thiscall sub_0051752A_ForwardUnlink(); // 0x0051752A
};

D2_CHECK_SIZE(D2StormLinkStrc, 0x8);
