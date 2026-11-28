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

// Level 0: the bit buffer that saves, items and packets are written and read through, and the save checksum.
void CaseBitBuffer(const replay::Functions& f)
{
    unsigned int x = 0x2545F491;                    // the case's own generator, for the values written
    unsigned char data[256];
    D2BitBufferStrc buf;
    for (int run = 0; run < 8; ++run)
    {
        memset(data, 0, sizeof(data));
        const int nSize = run == 7 ? 16 : (int)sizeof(data);   // the last run writes past its end
        f.BITMANIP_Initialize(&buf, data, nSize);
        int values[200], bits[200], n = 0;
        while (n < 200)
        {
            x = x * 1103515245 + 12345;
            bits[n] = 1 + (x >> 16) % 32;
            x = x * 1103515245 + 12345;
            values[n] = (int)(x ^ (x << 7));
            f.BITMANIP_Write(&buf, values[n], bits[n]);
            if (n % 37 == 36)
                f.BITMANIP_GoToNextByte(&buf);
            ++n;
        }
        printf("bitbuf run %d size %d state %d %d %d %d\n", run, f.BITMANIP_GetSize(&buf), buf.nBits, buf.nPos,
               buf.nPosBits, buf.bFull);
        for (int i = 0; i < nSize; i += 32)
        {
            printf("bitbuf run %d bytes %03d", run, i);
            for (int k = i; k < i + 32 && k < nSize; ++k)
                printf(" %02X", data[k]);
            printf("\n");
        }
        f.BITMANIP_Initialize(&buf, data, nSize);
        for (int i = 0; i < n; ++i)
        {
            const unsigned int u = f.sub_00410F60_ReadBits(&buf, bits[i]);
            printf("bitbuf run %d read %d bits %d %08X", run, i, bits[i], u);
            if (i % 37 == 36)
                f.BITMANIP_GoToNextByte(&buf);
            printf(" state %d %d %d\n", buf.nPos, buf.nPosBits, buf.bFull);
        }
        f.BITMANIP_Initialize(&buf, data, nSize);
        for (int i = 0; i < 40; ++i)
            printf("bitbuf run %d signed %d %d\n", run, i, f.BITMANIP_ReadSigned(&buf, 1 + i % 31));
        printf("bitbuf run %d checksum %08X\n", run, f.FOG_ComputeChecksum(data, nSize));
    }
}

// Level 1: proves the oracle's startup (Game.exe's own C runtime) and that the cases still run after it.
void CaseStartup(const replay::Functions& f)
{
    printf("startup reached\n");
    CaseRng(f);
    CaseBitBuffer(f);
}

struct Case
{
    const char* szName;
    void (*pfn)(const replay::Functions&);
    int nLevel;
};

const Case kCases[] = {{"rng", CaseRng, 0}, {"bitbuf", CaseBitBuffer, 0}, {"startup", CaseStartup, 1}};

replay::Functions gFunctions;
const Case* gpCase;

void RunCase()
{
    gpCase->pfn(gFunctions);
}
}

int main(int argc, char** argv)
{
    const char* szCase = 0;
    for (int i = 1; i + 1 < argc; ++i)
        if (!strcmp(argv[i], "--case"))
            szCase = argv[i + 1];
    if (!szCase)
    {
        fprintf(stderr, "usage: %s [--game PATH\\Game.exe] --case NAME   (cases: rng, bitbuf, startup)\n", argv[0]);
        return 2;
    }
    if (!replay::Bind(&gFunctions, argc, argv))
        return 1;
    for (unsigned int i = 0; i < sizeof(kCases) / sizeof(kCases[0]); ++i)
        if (!strcmp(kCases[i].szName, szCase))
        {
            gpCase = &kCases[i];
            return replay::Start(kCases[i].nLevel, RunCase);
        }
    fprintf(stderr, "no case %s\n", szCase);
    return 2;
}
