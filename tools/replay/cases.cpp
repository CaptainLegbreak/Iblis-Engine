// The replay cases, shared by both runners: each calls the game's functions through replay::Functions and
// prints what they computed, one fact per line.
#include "entry_points.h"

#include <stdio.h>
#include <string.h>

namespace
{
// Level 0: the random number generator every roll goes through.
void CaseRng(const replay::Functions& f)
{
    static const unsigned int kSeeds[] = {0, 1, 2, 666, 0x7FFFFFFF, 0x80000000, 0xFFFFFFFF, 0x12345678, 1234567};
    static const int kLimits[] = {1, 2, 3, 7, 8, 100, 1000, 1024, 0x7FFFFFFF, 0, -5};
    for (unsigned int s = 0; s < sizeof(kSeeds) / sizeof(kSeeds[0]); ++s)
    {
        D2SeedStrc seed;
        f.SEED_InitLowSeed(&seed, kSeeds[s]);
        printf("seed %08X init %08X %08X\n", kSeeds[s], seed.nLowSeed, seed.nHighSeed);
        for (int i = 0; i < 64; ++i)
        {
            const unsigned __int64 r = f.SEED_RollRandomNumber(&seed);
            printf("seed %08X roll %d %016llX\n", kSeeds[s], i, (unsigned long long)r);
        }
        for (unsigned int k = 0; k < sizeof(kLimits) / sizeof(kLimits[0]); ++k)
            for (int i = 0; i < 16; ++i)
            {
                const unsigned int r = f.SEED_RollLimitedRandomNumber(&seed, kLimits[k]);
                printf("seed %08X limit %d roll %d %u state %08X %08X\n", kSeeds[s], kLimits[k], i, r, seed.nLowSeed,
                       seed.nHighSeed);
            }
    }
}

struct Case
{
    const char* szName;
    void (*pfn)(const replay::Functions&);
};

const Case kCases[] = {{"rng", CaseRng}};
}

int main(int argc, char** argv)
{
    const char* szCase = 0;
    for (int i = 1; i + 1 < argc; ++i)
        if (!strcmp(argv[i], "--case"))
            szCase = argv[i + 1];
    if (!szCase)
    {
        fprintf(stderr, "usage: %s [--game PATH\\Game.exe] --case NAME   (cases: rng)\n", argv[0]);
        return 2;
    }
    replay::Functions f;
    if (!replay::Bind(&f, argc, argv))
        return 1;
    for (unsigned int i = 0; i < sizeof(kCases) / sizeof(kCases[0]); ++i)
        if (!strcmp(kCases[i].szName, szCase))
        {
            kCases[i].pfn(f);
            return 0;
        }
    fprintf(stderr, "no case %s\n", szCase);
    return 2;
}
