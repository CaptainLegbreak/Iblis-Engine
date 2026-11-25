#pragma once
// D2Game: an event queued on an NPC's record (the unit involved, the action and its parameter, the next event).

#include "D2Check.h"

struct D2NpcEventStrc
{
    D2UnitStrc* pUnit;
    int nAction;
    int nParam;
    int field_C;
    D2NpcEventStrc* pNext;
};
