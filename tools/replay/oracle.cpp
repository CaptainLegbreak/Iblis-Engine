// The oracle runner: binds the replay functions to their 1.14d addresses in the player's own stock Game.exe,
// mapped by oracle_image.cpp. See docs/REPLAY.md.
#include "entry_points.h"
#include "oracle_image.h"

#include <stdio.h>
#include <string.h>

namespace
{
unsigned char* gpBase;
}

bool replay::Bind(Functions* f, int argc, char** argv)
{
    const char* szGame = 0;
    for (int i = 1; i + 1 < argc; ++i)
        if (!strcmp(argv[i], "--game"))
            szGame = argv[i + 1];
    if (!szGame)
    {
        fprintf(stderr, "replay_oracle: --game PATH\\Game.exe is needed (the player's own 1.14d)\n");
        return false;
    }
    gpBase = oracle::MapImage(szGame);
    if (!gpBase)
        return false;
#define REPLAY_BIND(name, va, type) f->name = (Type<type>)(gpBase + ((va) - oracle::kImageBase));
    REPLAY_FUNCTIONS(REPLAY_BIND)
#undef REPLAY_BIND
    return true;
}

int replay::Start(int nLevel, void (*pfnCase)())
{
    if (nLevel <= 0)
    {
        pfnCase();
        return 0;
    }
    return oracle::StartGame(gpBase, kWinMain, pfnCase);
}
