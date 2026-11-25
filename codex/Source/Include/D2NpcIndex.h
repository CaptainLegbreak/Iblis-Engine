#pragma once
// Client: an NPC menu entry (the NPC, its choice count, their string ids and handlers, the enabled flag).

#include "D2Check.h"

#pragma pack(push, 1)
struct D2NpcIndexStrc
{
    int nId;
    int nCount;
    unsigned short awIds[5];
    int (__cdecl* apfHandlers[5])();
    char bEnabled;
};
#pragma pack(pop)
