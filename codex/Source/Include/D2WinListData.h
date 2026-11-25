#pragma once
// D2Win: a list control's line (its text, handler and fields, the next line).

#include "D2Check.h"

struct D2WinListDataStrc
{
    Unicode wszText[256];
    int field_200;
    D2WinMsgHandler field_204;
    int field_208;
    int field_20C;
    int field_210;
    int field_214;
    char field_218;
    char field_219;
    char field_21A;
    char field_21B;
    int field_21C;
    D2WinListDataStrc* pNext;
};
