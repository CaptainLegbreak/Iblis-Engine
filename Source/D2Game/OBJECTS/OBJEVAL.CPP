#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00741CC0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0
#define MAX(a, b) ((a) > (b) ? (a) : (b))

enum D2C_M96ObjEvalConstants
{
    STAT_DEXTERITY = 2,
    STAT_HITPOINTS = 6,
    STAT_LEVEL = 12,
    STAT_ARMORCLASS = 31,
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
    DAMAGERESULTFLAG_SUCCESSFULHIT = 1,
    DAMAGERESULTFLAG_GETHIT = 4,
};


D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00
int __stdcall UNITS_TestCollisionBetweenInteractingUnits(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, unsigned int nCollisionMask); // 0x00622B50
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0
void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005DF990
static int OBJEVAL_RollTrapDamage(D2UnitStrc* pSrcUnit, unsigned int nMinDamage, unsigned int nMaxDamage)
{
    D2_ASSERT(nMinDamage <= nMaxDamage, 20);

    const int nValue = ITEMS_RollLimitedRandomNumber(&pSrcUnit->pSeed, nMaxDamage - nMinDamage + 256) + nMinDamage;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pSrcUnit ? -1 : pSrcUnit->dwClassId);
    const int nDamage = nValue * (unsigned int)pObjectsTxtRecord->nDamage / 100;
    D2_ASSERT(pObjectsTxtRecord->nDamage, 27);
    return nDamage;
}

// 0x005DFA00
void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType)
{
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pTargetUnit);
    DUNGEON_GetLevelIdFromRoom(pTargetRoom);
    if (DUNGEON_IsRoomInTown(pTargetRoom) || UNITS_TestCollisionBetweenInteractingUnits(pTargetUnit, pSrcUnit, COLLIDE_MASK_PLAYER_FLYING))
    {
        return;
    }

    D2SeedStrc* pSeed = &pSrcUnit->pSeed;
    D2_ASSERT(pTargetUnit, 63);

    const int nHitpoints = STATLIST_UnitGetStatValue(pTargetUnit, STAT_HITPOINTS, 0);
    const unsigned int nMinDamage = MAX(nHitpoints >> 5, 1);
    const unsigned int nMaxDamage = MAX(nHitpoints >> 3, nMinDamage + 1);

    const int nLevel = STATLIST_UnitGetStatValue(pTargetUnit, STAT_LEVEL, 0);
    const unsigned char nRolledLevel = (unsigned char)(nLevel + (unsigned char)ITEMS_RollLimitedRandomNumber(pSeed, nLevel >> 2));
    const int nParam = 2 * (nRolledLevel - 5 * (STATLIST_UnitGetStatValue(pTargetUnit, STAT_DEXTERITY, 0) >> 1) - nLevel);

    int nChanceToHit = nParam - STATLIST_UnitGetStatValue(pTargetUnit, STAT_ARMORCLASS, 0) + 125;
    if (nChanceToHit < 65)
    {
        nChanceToHit = 65;
    }

    if ((int)(ITEMS_RollRandomNumber(pSeed) % 100) >= nChanceToHit)
    {
        return;
    }

    const int nDamage = OBJEVAL_RollTrapDamage(pSrcUnit, nMinDamage, nMaxDamage);
    if (!nDamage)
    {
        return;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    switch (nDamageType)
    {
    case 1:
        damage.dwFireDamage = nDamage;
        damage.dwHitClass = 0x20;
        break;

    case 2:
        damage.dwLtngDamage = nDamage;
        damage.dwHitClass = 0x40;
        break;

    case 3:
        damage.dwColdDamage = nDamage;
        damage.dwHitClass = 0x30;
        break;

    default:
        damage.dwPhysDamage = nDamage;
        break;
    }

    damage.wResultFlags = DAMAGERESULTFLAG_SUCCESSFULHIT;

    if (!STATES_CheckState(pTargetUnit, STATE_UNINTERRUPTABLE))
    {
        damage.wResultFlags |= DAMAGERESULTFLAG_GETHIT;
    }

    SUNITDMG_CalculateTotalDamage(pGame, pSrcUnit, pTargetUnit, &damage);
    SUNITDMG_ExecuteEvents(pGame, pSrcUnit, pTargetUnit, 0, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pSrcUnit, pTargetUnit, &damage);
}

