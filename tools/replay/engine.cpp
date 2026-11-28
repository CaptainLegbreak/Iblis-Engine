// The engine runner: binds the replay functions to the engine's own definitions. See docs/REPLAY.md.
#include "entry_points.h"

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);
unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed);
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);

bool replay::Bind(Functions* f, int, char**)
{
#define REPLAY_BIND(name, va, type) f->name = &::name;
    REPLAY_FUNCTIONS(REPLAY_BIND)
#undef REPLAY_BIND
    return true;
}
