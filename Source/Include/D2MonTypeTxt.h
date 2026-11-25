#pragma once
// Client: the part of a montype.txt record the client reads (the plural name string id at 0x0A).

#include "D2Check.h"

struct D2MonTypeTxt
{
    char unk0x00[0x0A];
    unsigned short wStrPlur;
};
