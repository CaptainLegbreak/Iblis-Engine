#include "D2Common.h"

#include "D2StormLink.h"

#include "D2Structs.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_NEUTRAL 1

extern "C" long __cdecl _time32(long* pTime);


struct Pair00650E60 { unsigned int dwFirst; unsigned int dwSecond; };

struct Pair00650E70 { unsigned int dwFirst; unsigned int dwSecond; };

// 0x00650D70
int __stdcall STATLIST_AreUnitsAligned(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    if (pUnit1 && pUnit2)
    {
        if (pUnit1 == pUnit2)
        {
            return TRUE;
        }

        const int nAlignment1 = STATLIST_GetUnitAlignment(pUnit1);
        const int nAlignment2 = STATLIST_GetUnitAlignment(pUnit2);

        switch (nAlignment1)
        {
        case UNIT_ALIGNMENT_EVIL:
            if (nAlignment2 == UNIT_ALIGNMENT_GOOD || nAlignment2 == UNIT_ALIGNMENT_NEUTRAL)
            {
                return FALSE;
            }

            if (nAlignment2 == UNIT_ALIGNMENT_EVIL)
            {
                return TRUE;
            }
            break;

        case UNIT_ALIGNMENT_NEUTRAL:
            return FALSE;

        case UNIT_ALIGNMENT_GOOD:
            if (nAlignment2 == UNIT_ALIGNMENT_GOOD)
            {
                return TRUE;
            }
            break;
        }
    }

    return FALSE;
}
// 0x00650DD0
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}
long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}
static inline void SEED_Step(unsigned int* pSeed)
{
    *pSeed = *pSeed * 0x19660D + 0x3C6EF35F;
}

// 0x00650DE0
int __fastcall SEED_GetRandomValue(int nValue)
{
    unsigned int nSeed = _time32(0);
    nSeed += GetTickCount();
    nSeed += nValue;
    SEED_Step(&nSeed);
    SEED_Step(&nSeed);
    SEED_Step(&nSeed);
    return nSeed & 0x7FFFFFFF;
}
// 0x00650E30
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed)
{
    pSeed->nLowSeed = 1;
    pSeed->nHighSeed = 666;
}
// 0x00650E40
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed)
{
    pSeed->nLowSeed = nLowSeed;
    pSeed->nHighSeed = 666;
}
// 0x00650E50
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed)
{
    return pSeed->nLowSeed;
}
// 0x00650E60
extern "C" __declspec(dllexport) void __fastcall sub_00650E60(Pair00650E60* pPair, unsigned int dwFirst, unsigned int dwSecond) {
    pPair->dwFirst = dwFirst;
    pPair->dwSecond = dwSecond;
}
// 0x00650E70
extern "C" __declspec(dllexport) void __fastcall sub_00650E70(Pair00650E70* pPair, unsigned int* pFirst, unsigned int* pSecond) {
    *pFirst = pPair->dwFirst;
    *pSecond = pPair->dwSecond;
}
// 0x00650E90
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}
// 0x00650EA0
void __cdecl sub_00650EA0_Nop()
{
}

#include "gen/data/Source/D2Common/Unknown_00650D70.inc"
