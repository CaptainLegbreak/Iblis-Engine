#include "D2Client.h"
#include "D2Path.h"
#include "D2StormTypes.h"

union D2SeedStrc;

inline unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5ui64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x004BC500
int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax)
{
    if (nMax <= nMin)
    {
        return nMin;
    }

    const int nRange = nMax - nMin;
    if ((nRange - 1) & nRange)
    {
        return (unsigned int)SEED_RollRandomNumber(pSeed) % nRange + nMin;
    }

    return (SEED_RollRandomNumber(pSeed) & (nRange - 1)) + nMin;
}
