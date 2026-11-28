#pragma once
// D2Game: a skill bound to a hotkey (the client record and the save file keep sixteen).

#include "D2Check.h"

struct D2HotkeySkillStrc
{
    short nSkill; // 0x00
    unsigned char nHand; // 0x02
    unsigned char pad0x03; // 0x03
    int nItemGUID; // 0x04
};

D2_CHECK_SIZE(D2HotkeySkillStrc, 0x8);
