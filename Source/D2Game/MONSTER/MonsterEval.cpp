#include "D2StatIds.h"
#include "D2MissileIds.h"
#include "D2GameClient.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2MonModes.h"
#include "D2ItemModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2UnitData.h"
#include "D2GameAux.h"
#include "D2LanguageNames.h"
#include "D2MonStatsInit.h"
#include "FogApi.h"
#include "D2CommonApi.h"
// build: symbol _gaszLanguageNames 0x0073C4C0


union D2SeedStrc;

struct D2StaticPathStrc;

struct D2MonStatsTxt;


struct D2MonsterDataStrc;


struct StatValue;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0



int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, int nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0


typedef void(__fastcall* MONUMODFUNC)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique);

extern MONUMODFUNC gpfnSrvUModCallbacks[][6]; // 0x0073C0B8


struct StatValue
{
    int value;
};

enum { RANGE_OVERRIDE = 0 };

#define UNITFLAG_TARGETABLE 0x00000002

#define UNITFLAG_ISVALIDTARGET 0x00000008


#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_GOOD 2

#define EVENTTYPE_AITHINK 2

#define EVENTTYPE_MONUMOD 7

#define MONTYPEFLAG_RESURRECTED 8

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNITFLAG_NOXP 0x04000000

#define PARTYSCREENTYPE_HOSTILE 3

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2ModeChangeStrc;

struct D2UnitStrc;

struct D2DamageStrc;

struct D2MissileStrc;

struct D2GameStrc;

struct D2CoordStrc;

struct D2DataTablesStrc;

struct D2ClientStrc;

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc*, int);


#include "D2GameFuncs.h"
#include "D2CommonApi2.h"



extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09



D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540





typedef void(__fastcall* PartyCommandFunc)(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int nParam, int* pFailure);

typedef int(__stdcall* FARPROC)();


extern PartyCommandFunc gpfnPartyCommands[10]; // 0x006E2218




void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0





struct D2MissilesTxt;


extern const unsigned int gdwBitMasks[]; // 0x006CE268





#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillsTxt;

typedef void(__fastcall* CurseCallbackFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel);





static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[pUnit->dwClassId];
    }
    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005A4EE0
extern "C" __declspec(dllexport) int __fastcall MONSTERMODE_IsMonster(D2UnitStrc* pUnit) {
    if (pUnit) {
        int nType = pUnit->dwUnitType;
        if (nType == 1) {
            return nType;
        }
    }
    return 0;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005A4EF0
void __fastcall MONSTERMODE_DistributeExperienceIfEligible(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2GameStrc* pGame)
{
    if (pAttacker && pDefender && !UNIT_HasFlag(pDefender, UNITFLAG_NOXP))
    {
        SUNITDMG_DistributeExperience(pGame, pAttacker, pDefender);
    }
}

// 0x005A5470
unsigned short __fastcall MONSTERMODE_GetAttackResultFlags(Game* game,Unit* attacker,Unit* defender,StatValue stat,int ignoredRange)
{
    return SUNITDMG_GetResultFlags(game,attacker,defender,stat.value,RANGE_OVERRIDE);
}

// 0x005A5490
void __fastcall MONSTERMODE_AllocateTargetCombat(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2DamageStrc damage = {};
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, 0, 0);
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    }
}

static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static int D2GAME_GetMonsterBaseId(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }

        return pUnit->dwClassId;
    }

    return -1;
}

// 0x005A54F0
void __fastcall MONSTERMODE_AddSandLeaperKnockback(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pDamage->wResultFlags & 4)
    {
        const int nBaseId = D2GAME_GetMonsterBaseId(pUnit);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_SANDLEAPER1 && !STATES_CheckState(pUnit, STATE_FREEZE))
        {
            pDamage->wResultFlags |= 8;
        }
    }
}

enum D2C_J10MonModeConstants
{
    HITCLASS_CRITICAL = 0x10,
    OVERLAY_CRITICAL = 54,
};

int __fastcall SUNITDMG_SetHitClass(D2DamageStrc* pDamage, unsigned int nHitClass); // 0x00554650

// 0x005A5560
void __fastcall D2GAME_MONSTER_ApplyCriticalDamage(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (pAttacker && pAttacker->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pAttacker->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nCrit && (unsigned char)(SEED_RollRandomNumber(&pAttacker->pSeed) % 100) < pMonStatsTxtRecord->nCrit)
        {
            pDamage->dwPhysDamage *= 2;
            pDamage->dwFireDamage *= 2;
            pDamage->dwLtngDamage *= 2;
            pDamage->dwMagDamage *= 2;
            pDamage->dwColdDamage *= 2;
            pDamage->dwPoisDamage *= 2;

            if (pDefender && !SUNITDMG_SetHitClass(pDamage, HITCLASS_CRITICAL))
            {
                UNITS_SetOverlay(pDefender, OVERLAY_CRITICAL, 0);
            }
        }
    }
}


unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650

// 0x005A5650
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0x80;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nMaxHp > 0 && nHitpoints < nMaxHp)
    {
        return (nHitpoints << 7) / nMaxHp;
    }

    return 0x80;
}


void __fastcall SKILLS_FillMinionSkillDamage(D2UnitStrc* pUnit, int nUnused, D2MonSkillInfoStrc* pMonSkillInfo); // 0x0056E050
int __fastcall SUNITPROXY_GetDifficultyScaledBonus(D2GameStrc* pGame, int nCount); // 0x005A4F20

static inline int MONSTEREVAL_GetUnitType(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static inline D2MonStatsTxt* MONSTEREVAL_GetMonStatsTxt(D2UnitStrc* pUnit)
{
    if (pUnit && MONSTEREVAL_GetUnitType(pUnit) == 1 && pUnit->pMonsterData)
    {
        return (D2MonStatsTxt*)pUnit->pMonsterData->pMonstatsTxt;
    }
    return 0;
}

// 0x005A4F50
void __fastcall MONSTERMODE_UpdateModeAttackStats(D2UnitStrc* pUnit, int nMode)
{
    D2MonStatsTxt* pRecord = MONSTEREVAL_GetMonStatsTxt(pUnit);
    if (!pRecord) return;
    D2MonSkillInfoStrc skill = {};
    SKILLS_FillMinionSkillDamage(pUnit, nMode, &skill);
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 1);
    if (!pStatList) return;
    STATLIST_RemoveAllStats(pStatList);
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    int difficulty = pGame->nDifficulty;
    int gameType = pGame->nGameType != 0 || pGame->dwGameType != 0;
    int bonus = 0;
    if (!STATLIST_GetUnitAlignment(pUnit)) {
        int players = STATLIST_UnitGetStatValue(pUnit, STAT_MONSTER_PLAYERCOUNT, 0);
        if (players < 1) players = 1;
        bonus = SUNITPROXY_GetDifficultyScaledBonus(pGame, players);
    }
    int minDamage, maxDamage, toHit;
    switch (nMode) {
    default:
    {
        D2MonStatsInitStrc init;
        memset(&init, 0, sizeof(init));
        const int classId = pUnit->dwClassId;
        DATATBLS_CalculateMonsterStatsByLevel(classId, gameType, difficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 8, &init);
        minDamage = init.nA1MinD + skill.nMinDamage;
        maxDamage = init.nA1MaxD + skill.nMaxDamage;
        toHit = init.nTH + skill.nToHit;
        break;
    }
    case 7:
    case 8:
    {
        D2MonStatsInitStrc init;
        memset(&init, 0, sizeof(init));
        const int classId = pUnit->dwClassId;
        DATATBLS_CalculateMonsterStatsByLevel(classId, gameType, difficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 32, &init);
        minDamage = skill.nMinDamage + init.nS1MinD;
        maxDamage = skill.nMaxDamage + init.nS1MaxD;
        toHit = skill.nToHit + init.nTH;
        break;
    }
    case 5:
    {
        D2MonStatsInitStrc init;
        memset(&init, 0, sizeof(init));
        const int classId = pUnit->dwClassId;
        DATATBLS_CalculateMonsterStatsByLevel(classId, gameType, difficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 16, &init);
        minDamage = init.nA2MinD + skill.nMinDamage;
        maxDamage = init.nA2MaxD + skill.nMaxDamage;
        toHit = init.nTH + skill.nToHit;
        break;
    }
    }
    if (!pGame->bExpansion && pGame->nDifficulty && pRecord->nAlign != 1) {
        minDamage = 10 * minDamage / 12;
        maxDamage = 10 * maxDamage / 12;
        toHit = 10 * toHit / 15;
    }
    if (pGame->bExpansion && bonus) {
        minDamage += minDamage * bonus / 128;
        maxDamage += maxDamage * bonus / 128;
        toHit += toHit * bonus / 128;
    }
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MINDAMAGE, minDamage, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MAXDAMAGE, maxDamage, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_TOHIT, toHit, 0);
    for (int i = 0; i < 3; ++i) {
        if (pRecord->nElMode[i] > 0 && nMode == pRecord->nElMode[i]) {
            if (pRecord->nElPct[i][difficulty] > 0 && (pRecord->nElPct[i][difficulty] >= 100 || (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < pRecord->nElPct[i][difficulty])) {
            D2MonStatsInitStrc init;
            memset(&init, 0, sizeof(init));
            DATATBLS_CalculateMonsterStatsByLevel(GAME_GetUnitClassId(pUnit), gameType, difficulty, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 64 + i, &init);
            int minElement = init.nElMinD;
            int maxElement = init.nElMaxD;
            int duration = init.nElDur;
            if (pGame->bExpansion && bonus) {
                minElement += minElement * bonus / 128;
                maxElement += maxElement * bonus / 128;
                duration += duration * bonus / 128;
            }
            unsigned char element = pRecord->nElType[i];
            if (element == 10) {
                element = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 5) + 1;
                if (!duration) duration = 25;
            }
            switch (element) {
            case 1:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMINDAM, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_FIREMAXDAM, maxElement, 0);
                break;
            case 2:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMINDAM, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_LIGHTMAXDAM, maxElement, 0);
                break;
            case 3:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_MAGICMINDAM, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_MAGICMAXDAM, maxElement, 0);
                break;
            case 4:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_COLDMINDAM, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_COLDMAXDAM, maxElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_COLDLENGTH, duration, 0);
                break;
            case 5:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMINDAM, 10 * minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONMAXDAM, 10 * maxElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_POISONLENGTH, 2 * duration, 0);
                break;
            case 6:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_LIFEDRAINMINDAM, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_LIFEDRAINMAXDAM, maxElement, 0);
                break;
            case 7:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_MANADRAINMINDAM, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_MANADRAINMAXDAM, maxElement, 0);
                break;
            case 8:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_STAMDRAINMINDAM, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_STAMDRAINMAXDAM, maxElement, 0);
                break;
            case 9:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_STUNLENGTH, duration, 0);
                break;
            case 11:
                STATLIST_SetStatIfListIsValid(pStatList, STAT_BURNINGMIN, minElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_BURNINGMAX, maxElement, 0);
                STATLIST_SetStatIfListIsValid(pStatList, STAT_FIRELENGTH, duration, 0);
                break;
            }
        }
        }
    }
}
