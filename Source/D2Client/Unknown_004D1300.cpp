#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2ClientGame.h"
#include "D2Records.h"
#include "D2Path.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2Drlg.h"
#include "D2Constants.h"
#include "D2DrlgMaps.h"
#include "D2ClientUi.h"
#include "D2TxtItems.h"
#include "D2ClientGfx.h"
#include "D2ClientTypes.h"
#include "D2LevelIds.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2MissilesTxt;

struct D2MissileStrc;

union D2SeedStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile); // 0x004CD390

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile); // 0x004D30C0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall MISSILE_CltDoRandomTrail(D2UnitStrc* pMissile); // 0x004D3630

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

enum
{
    CLTDO_TIMING_FRAME = 150,
    CLTDO_TIMING_ARG = 25,
    CLTDO_TIMING_LENGTH = 4000,
    CLTDO_SOUND_FRAME = 50,
    CLTDO_SOUND_ID = 0x121E,
    CLTDO_SLOW_FRAME = 8,
    CLTDO_FAST_FRAME = 0x23,
    CLTDO_SLOW_FLAG = 0x100,
};

typedef char cc_M439_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

typedef char cc_M338_D2MissilesTxt_size[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

void __fastcall GFXUTIL_ClearMotionFlagTwo(D2UnitStrc* pMissile);                                                         // 0x004DA340

void __fastcall GFXUTIL_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames);                      // 0x004DA5B0

void __fastcall MISSILE_CltDoFallingSpawn(D2UnitStrc* pMissile); // 0x004D66E0

static void __stdcall MISSILE_SpawnScattered(int nRange, int nMissile, D2UnitStrc* pMissile); // 0x004D1300

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecordChecked(int nMissileId)
{
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pMissilesTxt[nMissileId];
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
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

struct D2StormPhaseStrc { int nFrameLimit,nPeriod,bSpawn; };

static int MISSILE_UseCharge(D2UnitStrc* pMissile);                                            // 0x004CD310

static int MISSILE_UseCharge(D2UnitStrc* pMissile); // 0x004CD310

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static inline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

inline D2MissilesTxt* MISSILE_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        {
            return &sgptDataTables->pMissilesTxt[nMissileId];
        }
    }
    return 0;
}

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

#define UNIT_INVALID 6

#define TEST_OFFSET 0

#define LIGHT_LIMIT 60

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);

#define SPAWN_FLAGS 0x2001

#define COLLISION_MASK 0x45

// 0x004D3630
void __fastcall MISSILE_CltDoRandomTrail(D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->wCltSubMissile[0] < 0)
        {
            MISSILE_CltDoDefault(pMissile);
            return;
        }

        const int nX = CLIENTS_GetUnitX(pMissile);
        D2MissileStrc tParams;
        memset(&tParams, 0, sizeof(tParams));
        tParams.dwFlags = 0x21;
        tParams.pOwner = pOwner;
        tParams.nX = nX;
        tParams.nY = CLIENTS_GetUnitY(pMissile);
        tParams.nSkill = MISSILE_GetSkill(pMissile);
        tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[0];
        D2MissilesTxt* pSubMissileTxtRecord = SKILLS_GetMissilesTxtRecord(tParams.nMissile);
        if (!pSubMissileTxtRecord)
        {
            MISSILE_CltDoDefault(pMissile);
            return;
        }

        const short nRange = pSubMissileTxtRecord->wRange;
        if (nRange)
        {
            tParams.dwFlags = 0x8021;
            tParams.nRange = nRange;
        }

        if (pMissilesTxtRecord->wCltSubMissile[1] >= 0)
        {
            if (pMissilesTxtRecord->wCltSubMissile[2] >= 0)
            {
                switch (SEED_RollLimitedRandomNumber(&pMissile->pSeed, 3))
                {
                case 0:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
                    break;
                case 1:
                    tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[2];
                    break;
                }
            }
            else if (!SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2))
            {
                tParams.nMissile = pMissilesTxtRecord->wCltSubMissile[1];
            }
        }

        const int nChance = pMissilesTxtRecord->dwCltParam[0];
        if (!nChance || SEED_RollLimitedRandomNumber(&pMissile->pSeed, nChance))
            tParams.dwFlags |= 0x4000;

        tParams.nTargetX = CLIENTS_GetUnitX(pMissile);
        tParams.nTargetY = CLIENTS_GetUnitY(pMissile);
        D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
        if (pNew)
        {
            const int nPrecisionX = UNITS_GetPrecisionX(pMissile);
            const int nPrecisionY = UNITS_GetPrecisionY(pMissile);
            D2DynamicPathStrc* pPath = pNew->pDynamicPath;
            PATH_SetPrecisionX(pPath, nPrecisionX);
            PATH_SetPrecisionY(pPath, nPrecisionY);
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

// 0x004D1300
static void __stdcall MISSILE_SpawnScattered(int nRange, int nMissile, D2UnitStrc* pMissile)
{
    const int nOffsetX = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    const int nOffsetY = SEED_RollLimitedRandomNumberInline(&pMissile->pSeed, 2 * nRange) - nRange;
    D2MissileStrc tParams;
    memset(&tParams, 0, sizeof(tParams));
    tParams.dwFlags = 0x21;
    tParams.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tParams.nX = UNITS_GetUnitXPosition(pMissile);
    tParams.nY = UNITS_GetUnitYPosition(pMissile);
    tParams.nTargetX = UNITS_GetUnitXPosition(pMissile) + nOffsetX;
    tParams.nTargetY = UNITS_GetUnitYPosition(pMissile) + nOffsetY;
    tParams.nSkill = MISSILE_GetSkill(pMissile);
    tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    tParams.nMissile = nMissile;
    MISSILE_CreateClientMissile(&tParams);
}

// 0x004D66E0
void __fastcall MISSILE_CltDoFallingSpawn(D2UnitStrc* pMissile)
{
    const int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordChecked(MISSILE_IZUAL_CONTROL);
    MISSILE_SpawnScattered(10, MISSILE_IZUAL_MIST_LOOP, pMissile);
    if (nRemaining < pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[0] && nRemaining > pMissilesTxtRecord->wRange - pMissilesTxtRecord->dwParam[1])
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
        D2SeedStrc* pSeed = &pMissile->pSeed;
        if (pOwner)
        {
            const int nTargetX = CLIENTS_GetUnitX(pOwner) + SEED_RollLimitedRandomNumber(pSeed, 10) - 5;
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.nTargetX = nTargetX;
            tParams.dwFlags = 0x20;
            tParams.pOwner = pOwner;
            tParams.pOrigin = pMissile;
            tParams.nTargetY = SEED_RollLimitedRandomNumber(pSeed, 10) - 5 + CLIENTS_GetUnitY(pOwner);
            tParams.nSkill = MISSILE_GetSkill(pMissile);
            tParams.nSkillLevel = MISSILE_GetLevel(pMissile);
            tParams.nMissile = MISSILE_IZUAL_LIGHTNING;
            D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tParams);
            if (pNew)
            {
                int nRoll = SEED_RollLimitedRandomNumber(pSeed, 3);
                nRoll += 3;
                sub_004DA250(pNew, 0, 0, -nRoll, 1);
                GFXUTIL_SetBallistic(pNew, 0, 0xF);
                GFXUTIL_ClearMotionFlagTwo(pNew);
            }
        }
    }

    MISSILE_CltDoCommon(pMissile);
}

struct D2DynamicPathStrc;

static inline int UNITS_GetXPositionForceInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static __forceinline unsigned int SEED_RollLimitedRandomNumberForceInl(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumberInline(pSeed) % nMax;
    }

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}

// 0x004D6130
void __fastcall sub_004D6130_CltDoRandomSubMissile3(D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        MISSILE_CltDoDefault(pMissile);
        return;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nCount = 0;
    do
    {
        if (pMissilesTxtRecord->wCltSubMissile[nCount] < 0 || pMissilesTxtRecord->dwCltParam[nCount + 1] <= 0)
        {
            break;
        }

        ++nCount;
    }
    while (nCount < 3);

    if (nCount <= 0)
    {
// build: symbol ?MISSILE_CltMissileHit@* 0x004D2D70
        MISSILE_CltMissileHit(pMissile, 0, 0);
        return;
    }

    if (nFrames < pMissilesTxtRecord->dwCltParam[0])
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    SEED_InitLowSeed(&pMissile->pSeed, UNITS_GetXPositionForceInl(pMissile));

    const int nIndex = SEED_RollLimitedRandomNumberForceInl(&pMissile->pSeed, nCount);
    if (nFrames % pMissilesTxtRecord->dwCltParam[nIndex + 1])
    {
        MISSILE_CltDoCommon(pMissile);
        return;
    }

    D2MissileStrc tMissile = {};
    tMissile.pOwner = CUNIT_GetOwnerUnit(pMissile);
    tMissile.pOrigin = pMissile;
    tMissile.nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    tMissile.nMissile = pMissilesTxtRecord->wCltSubMissile[nIndex];
    tMissile.nSkillLevel = nSkillLevel;

    D2UnitStrc* pNew = MISSILE_CreateClientMissile(&tMissile);
    if (pNew)
    {
        MISSILE_CltMissileHit(pNew, 0, 1);
    }

    MISSILE_CltDoCommon(pMissile);
}

