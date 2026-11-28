#pragma once
// Game: the argument records the server passes through its unit-iteration callbacks (the roster walk and the
// door search of the AI).

#include "D2Check.h"

struct D2UnitStrc;

struct D2RosterIterateStrc
{
    int bFlag; // 0x00
    D2UnitStrc* pUnit; // 0x04
};

struct D2DoorObjectAiCallbackArgStrc
{
    D2UnitStrc* pDoor; // 0x00
    int nDistance; // 0x04
    int unused0x08[8]; // 0x08
};
