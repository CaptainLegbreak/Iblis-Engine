// The 1.14d functions the replay cases call: their addresses in the stock Game.exe and their signatures.
// Facts about 1.14d (from Iblis Codex's build/functions.json, copied here), not bytes of it. The engine runner
// calls the same functions by name.
#pragma once

#include "../../Source/Include/D2Structs.h"

namespace replay
{
// A function of the game: its 1.14d address and its type, for both runners.
#define REPLAY_FUNCTIONS(X)                                                                                   \
    X(SEED_InitLowSeed, 0x00650E40, void(__fastcall*)(D2SeedStrc*, unsigned int))                             \
    X(SEED_RollRandomNumber, 0x0045C370, unsigned __int64(__fastcall*)(D2SeedStrc*))                          \
    X(SEED_RollLimitedRandomNumber, 0x0045C390, unsigned int(__fastcall*)(D2SeedStrc*, int))

template <class T> using Type = T;     // lets a function-pointer type be written before its name

struct Functions
{
#define REPLAY_MEMBER(name, va, type) Type<type> name;
    REPLAY_FUNCTIONS(REPLAY_MEMBER)
#undef REPLAY_MEMBER
};

// Fills f for the runner this is compiled into; returns false (with a message on stderr) if it can't.
bool Bind(Functions* f, int argc, char** argv);
}
