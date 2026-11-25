#pragma once
// D2Win: one line of a text split to a width, as D2Win_AllocateSplitText allocates it and D2Win_10200
// frees the list (the line's text, the next line).

#include "D2Check.h"

struct Unicode;

struct D2SplittedTextStrc
{
    Unicode* wszLine; // 0x00
    D2SplittedTextStrc* pNextLine; // 0x04
};
