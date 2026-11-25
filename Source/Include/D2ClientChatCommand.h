#pragma once
// Client: an entry of gaChatCommands, the typed chat commands (name, code, takes an argument, always allowed).

#include "D2Check.h"

#pragma pack(push, 2)
struct D2ChatCommandStrc
{
    const char* szName;
    short nCode;
    int bArgument;
    int bAlways;
};
#pragma pack(pop)
