#include "D2Common.h"

#include "D2StormLink.h"

#include "D2Structs.h"

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_NEUTRAL 1

extern "C" long __cdecl _time32(long* pTime);


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
void __fastcall SEED_SetSeeds(D2SeedStrc* pSeed, unsigned int nLowSeed, unsigned int nHighSeed)
{
    pSeed->nLowSeed = nLowSeed;
    pSeed->nHighSeed = nHighSeed;
}
// 0x00650E70
void __fastcall SEED_GetSeeds(D2SeedStrc* pSeed, unsigned int* pLowSeed, unsigned int* pHighSeed)
{
    *pLowSeed = pSeed->nLowSeed;
    *pHighSeed = pSeed->nHighSeed;
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

#pragma pack(push, 1)
struct d2data_00745998_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00745998_t gData_00745998; // 0x00745998

extern "C" struct d2data_00745998_t gData_00745998 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00745998
