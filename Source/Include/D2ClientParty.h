#pragma once
// Client: the party panel rows (one per roster player) and their five buttons.

#include "D2Check.h"

struct D2RosterSlotStrc
{
    int bFlag; // 0x00
    int nX; // 0x04
    int nY; // 0x08
    void* pCellFile; // 0x0C
    int nFrame; // 0x10
    int nType; // 0x14
    int nState; // 0x18
    int bActive; // 0x1C
};

#pragma pack(push, 1)
struct D2PartyRowStrc
{
    D2RosterSlotStrc aSlots[5]; // 0x00
    char szName[0x19]; // 0xA0
    int nClass; // 0xB9
    int nLevel; // 0xBD
    int nLevelId; // 0xC1
    int nId; // 0xC5
    int nY; // 0xC9
    D2PartyRowStrc* pNext; // 0xCD
};
#pragma pack(pop)

D2_CHECK_SIZE(D2RosterSlotStrc, 0x20);
D2_CHECK_SIZE(D2PartyRowStrc, 0xD1);
