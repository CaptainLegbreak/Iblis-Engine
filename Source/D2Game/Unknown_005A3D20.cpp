#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2MonModes.h"
#include "D2UnitData.h"
#include "D2Txt.h"

#define EVENTTYPE_MONUMOD 7
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MonStatsTxt;
struct D2MonsterDataStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
int __fastcall SUNITDMG_SetMissileDamageFlagsForNearbyUnits(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nSize, D2DamageStrc* pDamage, int a7, int a8, int(__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*), int a10); // 0x0057E090

typedef void(__fastcall* MONUMODFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique);

extern MONUMODFUNC gpfnSrvUModCallbacks[][6]; // 0x0073C0B8
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLevelVariantAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0
void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag); // 0x005A0180

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

static inline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nX;
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
        return pUnit->pStaticPath->tGameCoords.nY;
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005A3D20
void __fastcall MONSTERUNIQUE_ApplyCorpseFireDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit);
    const int nFireDamage = (ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pMonStatsTxtRecord->nElMaxD[0][0] - pMonStatsTxtRecord->nElMinD[0][0]) + pMonStatsTxtRecord->nElMinD[0][0]) << 8;
    const int nSize = pMonStatsTxtRecord->wAiParam[2][pGame->nDifficulty] * STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwFireDamage = nFireDamage;

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    SUNITDMG_SetMissileDamageFlagsForNearbyUnits(pGame, pUnit, nX, nY, nSize, &damage, 0, 0, 0, 0);
}

// 0x005A4200
void __fastcall MONSTERUNIQUE_CreatePainWorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (!pUnit || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        MONSTERSPAWN_SpawnLevelVariantAtUnit(pGame, pUnit, MONSTER_PAINWORM1, MONMODE_NEUTRAL, 1, 0);
        STATES_ToggleState(pUnit, STATE_CORPSE_NODRAW, 1);
    }
}

// 0x005A4230
void __fastcall MONSTERUNIQUE_UpdateAiAndScheduleUModEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    if (SUNIT_IsDead(pUnit))
    {
        return;
    }

    MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MONUMOD, pGame->dwGameFrame + 75, 0, 0);
}

// 0x005A0120
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = (pUnit && pUnit->dwUnitType == UNIT_MONSTER) ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
    {
        return 0;
    }
    return pMonsterData->nMonUmod;
}


void __stdcall MONSTERUNIQUE_ExecuteUModCallbacks(D2GameStrc* pGame, D2UnitStrc* pMissile, int nCallbackIndex, D2UnitStrc* pUnit); // 0x005A4270
void __fastcall MONSTERUNIQUE_ExecuteUModModeStartCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 0, pUnit);
}

void __fastcall MONSTERUNIQUE_ExecuteUModModeChangeCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 1, pUnit);
}

// 0x005A4370
void __fastcall MONSTERUNIQUE_EventExecuteUModCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 2, pUnit);
}

void __fastcall MONSTERUNIQUE_ExecuteUModSuccessfulHitCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 3, pUnit);
}

// build: symbol ?MONSTERUNIQUE_ExecuteUModDamagedCallbacks@* 0x005A43A0
void __fastcall MONSTERUNIQUE_ExecuteUModDamagedCallbacks(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    MONSTERUNIQUE_ExecuteUModCallbacks(pGame, 0, 4, pUnit);
}

// build: symbol ?MONSTERUNIQUE_OwnerMissileHook@* 0x005A43B0
void __fastcall MONSTERUNIQUE_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMissile)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pMissile)
    {
        MONSTERUNIQUE_ExecuteUModCallbacks(pGame, pMissile, 5, pUnit);
    }
}
