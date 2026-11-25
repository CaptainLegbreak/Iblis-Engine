#pragma once
// D2Win: a line of a popup menu (its text and the handler a click on it calls).

#include "D2Check.h"
#include "D2Unicode.h"

struct D2WinPopUpLineStrc
{
    Unicode wszText[64]; // 0x00
    void (__stdcall* pfHandleMouseInput)(); // 0x80
};
