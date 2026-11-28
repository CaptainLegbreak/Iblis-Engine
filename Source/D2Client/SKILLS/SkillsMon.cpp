// Built /GS-: the buffer in 0x004E2D40 has no security cookie.
#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2ItemTypes.h"
#include "D2SkillIds.h"
#include "D2TxtItems.h"
#include "D2Path.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2WinSplitText.h"
#include "D2CommonApi.h"
#include "D2CommonApi3.h"

struct D2UnitStrc;

struct D2StaticPathStrc;

struct D2GfxLightStrc;

struct D2SkillDescTxt;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

extern "C" unsigned int __cdecl sub_0044DA90_GetTick();                                                     // 0x0044DA90



D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740





D2GfxLightStrc* __fastcall DLIGHTMAP_MakeLightEntry(D2UnitStrc* pUnit, int nArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x00474160

void __fastcall sub_00474290(D2GfxLightStrc* pLight, int nRadius);                           // 0x00474290

void __fastcall SCMD_StartTimedEffect(int nParam0, int nTime1, int nTime2, int nTime3);                     // 0x00476A80

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360


int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00





D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540

D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40









void __fastcall SKILLDESC_DrawSkillWeaponLine(D2UnitStrc* pUnit, void* pArg, D2SkillsTxt* pSkillsTxtRecord, int nArg3, int nArg4, int nArg5, int nArg6); // 0x004EA010

void __fastcall SKILLDESC_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);       // 0x004F2440


int __fastcall SKILLSMON_CreateSkillMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nParam1, int nParam2, int nParam3); // 0x004F3CE0





int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit);                                              // 0x00623C60


void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10






void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660



void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690



void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0



void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections);                            // 0x00649EF0

void __stdcall MISSILE_SetStreamMissile(D2UnitStrc* pMissile, int nStreamMissile);                          // 0x0064A4E0

void __stdcall MISSILE_SetStreamRange(D2UnitStrc* pMissile, short nStreamRange);                            // 0x0064A540



struct D2MissileStrc;


unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0


int __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x00648810



static const int gaMonRingOffsetX[64] =                                                               // 0x006DBB68
{
    30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
    0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
    -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
    0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
};

static const int gaMonRingOffsetY[64] =                                                               // 0x006DBC68
{
    0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
    30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
    0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
    -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
};

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline int SKILLS_GetSkillParamInline(int nSkillId, int nIndex)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    return !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[nIndex];
}

// 0x004E1D30
int __fastcall SKILLSMON_FireVolley(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pInitFunc = sub_004E1C80_CltMissileInitDiabWall;
    if (!ITEM_GetTargetPosition(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nInitArg = i;
        MISSILE_CreateClientMissile(&tMissileParams);
    }
    return 1;
}

// 0x004E1E30
int __fastcall SKILLSMON_ClearUsedSkillFlags(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0);
    return 1;
}


// 0x004E1E50
int __fastcall SKILLSMON_ChargeFrames(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (nFrame > pSkillsTxtRecord->dwParam[3])
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2UnitStrc* pTarget = PATH_GetTargetUnit(pPath);
    if (pTarget && D2Common_10399(pTarget, pUnit) <= 1)
    {
        SKILLS_SetFlags(pSkill, 0);
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[0] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[1]);
        return 1;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[0] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[1]);
        return 1;
    }

    if (nFrame == pSkillsTxtRecord->dwParam[2])
    {
        int nVelocity = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) << 8;
        if (nVelocity <= 0x100)
        {
            nVelocity = 0x100;
        }

        const int nRate = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
        PATH_SetVelocity(pPath, DATATBLS_ApplyRatio(nVelocity, nRate, 100), ".\\SKILLS\\SkillsMon.cpp", 0x466);
        PATH_SetType(pPath, 1);
        D2Common_10142(pPath, pUnit, 0);
        SKILLS_SetFlags(pSkill, 1);
        return 1;
    }

    if (nFrame == pSkillsTxtRecord->dwParam[3])
    {
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[4] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[5]);
    }
    return 1;
}

enum
{
    SKILLDO_FRAME_A = 6,
    SKILLDO_FRAME_A_SET = 7,
    SKILLDO_FRAME_A_COUNT = 0x3200,
    SKILLDO_FRAME_B = 22,
    SKILLDO_REPEATS = 4,
    SKILLDO_FRAME_B_SET = 40,
    SKILLDO_FRAME_B_COUNT = 0x1100,
    SKILLDO_FRAME_C = 30,
    SKILLDO_FRAME_C_STATE = 12,
};

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

// 0x004E1FF0
int __fastcall SKILLDESC_CltDoMissileWall(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nDX = nTargetX - nX;
    int nDY = nTargetY - nY;
    if (!nDX && !nDY)
    {
        return 0;
    }

    int nStepX = 0;
    int nStepY = 0;

    if (nDX < 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = -2;
    }
    else if (nDX == 0 && nDY < 0)
    {
        nStepX = 2;
    }
    else if (nDX > 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = 2;
    }
    else if (nDX > 0 && nDY == 0)
    {
        nStepY = 2;
    }
    else if (nDX > 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = 2;
    }
    else if (nDX == 0 && nDY > 0)
    {
        nStepX = -2;
    }
    else if (nDX < 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = -2;
    }
    else if (nDX < 0 && nDY == 0)
    {
        nStepY = -2;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    nDX -= nCount / 2 * nStepX;
    nDY -= nCount / 2 * nStepY;

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    for (int i = 0; i < nCount; ++i)
    {
        tMissile.pOwner = pUnit;
        tMissile.nX = nX + nDX / 6;
        tMissile.nTargetX = nDX;
        tMissile.nTargetY = nDY;
        tMissile.nY = nY + nDY / 6;
        tMissile.nSkillLevel = nSkillLevel;
        tMissile.nMissile = nMissile;
        MISSILE_CreateClientMissile(&tMissile);
        nDX += nStepX;
        nDY += nStepY;
    }

    return 1;
}

// 0x004E21D0
int __fastcall SKILLSMON_MissileRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!CUNIT_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    const int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissile, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 3;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.dwFlags |= 4;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nVelocity = nVelocity;
    for (int i = 0; i < 64; ++i)
    {
        tMissileParams.nTargetX = gaMonRingOffsetX[i];
        tMissileParams.nTargetY = gaMonRingOffsetY[i];
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            GFXUTIL_ReplaceMotionFlag1With8(pMissile);
            GFXUTIL_SetMotionFlagMask(pMissile, 0);
            GFXUTIL_SetMotionVectorB(pMissile, 0, 0, -6, 1);
            GFXUTIL_SetMotionVectorC(pMissile, 0, 0, 0, 0);
            GFXUTIL_SetMotionVectorA(pMissile, 0, 0, 0x78);
        }
    }
    return 1;
}

// 0x004E2320
int __fastcall sub_004E2320_StartSkillRollParam(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, (!pUnit ? -1 : pUnit->dwUnitId) + (!pTarget ? -1 : pTarget->dwUnitId));

    const int nMin = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    const int nMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    int nValue = ITEMS_RollLimitedRandomNumber(&tSeed, nMax - nMin) + nMin;
    if (nValue < 1)
    {
        nValue = 1;
    }

    SKILLS_SetParam1(pSkill, nValue);
    SKILLS_SetParam2(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
    return 1;
}

// 0x004E2410
int __fastcall SKILLSMON_RepeatOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_FindClientUnit(SKILLS_GetParam2(pSkill), SKILLS_GetParam3(pSkill));
    if (!pTarget)
    {
        SKILLS_SetParam1(pSkill, 0);
        return 0;
    }

    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }

    const int nCount = SKILLS_GetParam1(pSkill) - 1;
    if (nCount <= 0)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, nCount);
    UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[0]);
    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    return 1;
}

// 0x004E2530
int __fastcall SKILLSMON_SpreadTwoMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2021;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = nSkillId;
    SKILLS_SpawnMissileRing(pUnit, &tMissileParams, 2, 1);

    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissileParams.nMissile = nMissileB;
        SKILLS_SpawnMissileRing(pUnit, &tMissileParams, 4, 5);
    }
    return 1;
}

// 0x004E2630
int __fastcall SKILLDESC_CltDoFrameSteps(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    const int nRepeats = SKILLS_GetParam1(pSkill);

    switch (pUnit->nSeqCurrentFramePrecise >> 8)
    {
    case SKILLDO_FRAME_A:
        UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_A_SET);
        pUnit->dwFrameCountPrecise = SKILLDO_FRAME_A_COUNT;
        break;

    case SKILLDO_FRAME_B:
        if (nRepeats >= SKILLDO_REPEATS)
        {
            UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_B_SET);
            pUnit->dwFrameCountPrecise = SKILLDO_FRAME_B_COUNT;
        }
        else
        {
            SKILLS_SetParam1(pSkill, nRepeats + 1);
        }
        break;

    case SKILLDO_FRAME_C:
        UNITMODE_SetUnitMode(pUnit, SKILLDO_FRAME_C_STATE);
        CUNIT_MarkUnitDead(pUnit);
        break;
    }

    return 1;
}

// 0x004E26C0
int __fastcall SKILLSMON_StreamAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nStreamMissile = pSkillsTxtRecord->wCltMissileB;
    if (nStreamMissile < 0 || nStreamMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nStreamRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nTargetX;
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nY = nTargetY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = MISSILE_CURSECENTER;
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetStreamMissile(pMissile, nStreamMissile);
    MISSILE_SetStreamRange(pMissile, nStreamRange);
    return 1;
}

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

// 0x004E2D40
D2UnitStrc* __fastcall SKILLSMON_UpdateSpiderLay(D2UnitStrc* pUnit)
{
    int nX;
    int nY;
    D2UnitStrc* pMissile = 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pPath && PATH_HasEnteredNewSubtile(pPath))
    {
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_SPIDERLAY), 1);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        nX = UNITS_GetUnitXPosition(pUnit);
        nY = UNITS_GetUnitYPosition(pUnit);

        unsigned char aDirections[8];
        aDirections[0] = 10;
        aDirections[1] = 8;
        aDirections[2] = 22;
        aDirections[3] = 20;
        aDirections[4] = 18;
        aDirections[5] = 16;
        aDirections[6] = 14;
        aDirections[7] = 12;
        const unsigned char nDirection = aDirections[INVENTORY_GetEightWayDirection(PATH_GetDirection(pPath))];

        int nDeltaX;
        int nDeltaY;
        INVENTORY_GetDirectionDelta(nDirection, &nDeltaX, &nDeltaY);
        const int nSpawnX = nX + nDeltaX;
        const int nSpawnY = nY + nDeltaY;
        if (!DUNGEON_IsRoomInTown(sub_00463740_FindRoomAtPoint(pRoom, nSpawnX, nSpawnY)))
        {
            D2MissileStrc tParams;
            memset(&tParams, 0, sizeof(tParams));
            tParams.dwFlags = 0x25;
            tParams.pOwner = pUnit;
            tParams.nX = nSpawnX;
            tParams.nY = nSpawnY;
            tParams.nTargetX = nSpawnX + 2 * nDeltaX;
            tParams.nTargetY = nSpawnY + 2 * nDeltaY;
            tParams.nVelocity = 3;
            tParams.nSkillLevel = nSkillLevel;
            tParams.nMissile = MISSILE_SPIDERGOOLAY;
            pMissile = MISSILE_CreateClientMissile(&tParams);
            sub_004B9A00(0x726, pUnit, 0, 0, 0);
        }
    }

    return pMissile;
}

// 0x004E3590
int __fastcall SKILLSMON_FlankTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecordInline(nMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    const int nSubMissile = pMissilesTxtRecord->wSubMissile[0];
    if (nSubMissile < 0 || nSubMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    if (!SKILLS_IsTargetPosClear(pUnit, nMissile))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    const int nDx = CLIENTS_GetUnitX(pUnit) - nX;
    const int nDy = CLIENTS_GetUnitY(pUnit) - nY;
    tMissileParams.nTargetX = nX - nDy;
    tMissileParams.nTargetY = nY + nDx;
    MISSILE_CreateClientMissile(&tMissileParams);
    tMissileParams.nTargetX = nX + nDy;
    tMissileParams.nTargetY = nY - nDx;
    MISSILE_CreateClientMissile(&tMissileParams);
    tMissileParams.nTargetX = 0;
    tMissileParams.nTargetY = 0;
    tMissileParams.dwFlags = 1;
    tMissileParams.nMissile = nSubMissile;
    MISSILE_CreateClientMissile(&tMissileParams);
    return 1;
}

#define SKILL_FLAG 0x40



// 0x004E3720
int __fastcall SKILLSMON_CreateTargetMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= SKILL_FLAG;
    const int nTarget = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2UnitStrc* pMissile = AUTOMAP_RequestAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
        return 0;
    MISSILE_SetTargetX(pMissile, nTarget);
    return 1;
}

// 0x004E39A0
int __fastcall sub_004E39A0_CheckTargetRoom(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }
    return 1;
}

// 0x004EC040
void __fastcall SKILLSMON_DescIfRecord(D2UnitStrc* pUnit, void* pArg, D2SkillsTxt* pSkillsTxtRecord, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (pArg && pSkillsTxtRecord && sub_004A89D0_SkillDescRec(pSkillsTxtRecord->nSkillId))
    {
        SKILLDESC_DrawSkillWeaponLine(pUnit, pArg, pSkillsTxtRecord, nArg3, nArg4, nArg5, nArg6);
    }
}

// 0x004F0350
int __fastcall SKILLSMON_RequestMissile(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        MISSILE_SubmitMissileRequest(pUnit, nMissile, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nSkillId, nArg);
    }
    return 1;
}

// 0x004F0710
int __fastcall SKILLSMON_SetParamTimes(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nParam0 = SKILLS_GetSkillParamInline(nSkillId, 0);
    const int nTime1 = SKILLS_GetSkillParamInline(nSkillId, 1) * 1000 / 25;
    const int nTime2 = SKILLS_GetSkillParamInline(nSkillId, 2) * 1000 / 25;
    const int nTime3 = SKILLS_GetSkillParamInline(nSkillId, 3) * 1000 / 25;
    SCMD_StartTimedEffect(nParam0, nTime1, nTime2, nTime3);
    return 1;
}

struct Unit0064A300;

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

extern "C" int __stdcall sub_0064A300(Unit0064A300* pUnit); // 0x0064A300

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// 0x004F0830
int __fastcall SKILLSMON_CreateTimedMissileLine(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;
    const int nMissileId = pSkillsTxtRecord->wCltMissileB;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord)
        return 0;
    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        return 0;
// build: symbol ?DRLG_GetDistanceToXY@* 0x006417F0
    int nDistance = DRLG_GetDistanceToXY(pUnit, nTargetX, nTargetY);
    if (nDistance < 1)
        nDistance = 1;
    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    const int nDeltaX = 100 * (nTargetX - nX) / nDistance;
    const int nDeltaY = 100 * (nTargetY - nY) / nDistance;
    const int nStep = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    const int nFrameStep = pMissilesTxtRecord->dwParam[1] < 1 ? 1 : pMissilesTxtRecord->dwParam[1];
    int nPos = nStep;
    int nCount = 0;
    while (nPos < nDistance)
    {
        D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, nMissileId, nX + nPos * nDeltaX / 100, nY + nPos * nDeltaY / 100, nSkillId, nSkillLevel);
        if (pMissile)
        {
            D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, UNITS_GetDirection(pUnit));
            const int nFrames = sub_0064A300((Unit0064A300*)pMissile);
            MISSILE_SetTotalFrames(pMissile, nFrames + nCount * nFrameStep);
            MISSILE_SetCurrentFrame(pMissile, nFrames + nCount * nFrameStep);
            MISSILE_SetActivateFrame(pMissile, nFrames - nCount * nFrameStep);
            pMissile->dwFlagEx |= 0x40000;
        }
        nPos += nStep;
        ++nCount;
    }
    const int nTargetMissile = pSkillsTxtRecord->wCltMissileA;
    if (nTargetMissile >= 0 && nTargetMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2UnitStrc* pMissile = sub_004C5470_CreateMissileToTarget(pUnit, nTargetMissile, nSkillId, nSkillLevel);
        if (!pMissile)
            return 0;

        const int nSpeed = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (nSpeed > 0)
            UNITS_SetAnimationSpeed(pMissile, nSpeed);

        const int nFrames = sub_0064A300((Unit0064A300*)pMissile);
        MISSILE_SetTotalFrames(pMissile, nFrames + nCount * nFrameStep);
        MISSILE_SetCurrentFrame(pMissile, nFrames + nCount * nFrameStep);
        MISSILE_SetActivateFrame(pMissile, nFrames - nCount * nFrameStep);
        pMissile->dwFlagEx |= 0x40000;
    }
    return 1;
}


// 0x004F0AB0
int __fastcall SKILLSMON_StartTimedState(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nArg);
    if (nDelay < 1)
    {
        nDelay = 1;
    }

    SKILLS_SetParam1(pSkill, sub_0044DA90_GetTick() + nDelay);
    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, 0xC, 1);
    }
    return 1;
}

// 0x004F0B50
int __fastcall SKILLSMON_TimedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (sub_0044DA90_GetTick() > SKILLS_GetParam1(pSkill))
    {
        STATES_ToggleState(pUnit, 0xC, 0);
        return 0;
    }

    D2UnitStrc* pMissile = SKILLDESC_CltDoRandomMissile(pUnit, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    PARTICLE_ResetGfxMotion(pMissile);
    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel));
    GFXUTIL_SetMotionFlagMask(pMissile, 1);
    if (pUnit)
    {
        pUnit->dwFlags &= ~0x40;
    }
    return 1;
}


static inline int __fastcall UNITS_GetXPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int __fastcall UNITS_GetYPositionInl(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int UNITS_GetClassIdInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x004F0C20
int __fastcall sub_004F0C20_StoreTargetPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, UNITS_GetXPositionInl(pTarget));
    SKILLS_SetParam2(pSkill, UNITS_GetYPositionInl(pTarget));
    return 1;
}

// 0x004F0CD0
int __fastcall SKILLSMON_RequestAtSkillPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    const int nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0 && nMissileA < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, nMissileA, nX, nY, nSkillId, nSkillLevel);
        if (!pMissile)
        {
            return 0;
        }

        const short nSound = pSkillsTxtRecord->wPrgSound;
        if (nSound > 0)
        {
            sub_004B9A00(nSound, pMissile, 0, 0, 0);
        }
    }

    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        MISSILE_SubmitMissileRequest(pUnit, nMissileB, nX, nY, nSkillId, nSkillLevel);
    }
    return 1;
}

// 0x004F0DD0
int __fastcall sub_004F0DD0_StoreTargetInfo(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
        if (pTarget && D2COMMON_11018(pTarget))
        {
            SKILLS_SetParam1(pSkill, CLIENTS_GetUnitX(pTarget));
            SKILLS_SetParam2(pSkill, CLIENTS_GetUnitY(pTarget));
            SKILLS_SetParam3(pSkill, UNITS_GetClassIdInl(pTarget));
            return 1;
        }
    }

    return 0;
}

// 0x004F0E30
int __fastcall SKILLSMON_MoveToSkillPos(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        return 0;
    }

    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        MISSILE_SubmitMissileRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    }
    return 1;
}

// 0x004F1120
int __fastcall SKILLSMON_MissileFromTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wCltMissileB < 0 || pSkillsTxtRecord->wCltMissileB >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    MONSTER_SpawnBloodMissiles(pTarget, 3, 0);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = pSkillsTxtRecord->wCltMissileB;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.pOwner = pTarget;
    tMissileParams.pOrigin = pTarget;
    MISSILE_CreateClientMissile(&tMissileParams);
    return 1;
}

// 0x004F2450
int __fastcall SKILLSMON_StartStateList(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        const short nOverlay = pSkillsTxtRecord->wPrgOverlay;
        if (nOverlay > 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
        }

        const short nSound = pSkillsTxtRecord->wPrgSound;
        if (nSound > 0)
        {
            sub_004B9A00(nSound, 0, 0, 0, 0);
        }
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_INFERNO);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 2, 0x14, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return 0;
        }

        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
        if (!pSkill)
        {
            return 0;
        }

        SKILLS_SetParam1(pSkill, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLDESC_ToggleStateOff);
        STATLIST_SetState(pStatList, STATE_INFERNO);
        STATES_ToggleState(pUnit, 0xC, 1);
        return 1;
    }

    UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->nSeqInput - 1);
    pUnit->dwFrameCountPrecise = 0x800;
    D2COMMON_10476(pStatList, 7);
    return 1;
}

// 0x004F2790
int __fastcall SKILLSMON_StreamFromTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wCltMissileB < 0)
    {
        return 0;
    }

    const int nStreamRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetStreamMissile(pMissile, pSkillsTxtRecord->wCltMissileB);
        MISSILE_SetStreamRange(pMissile, nStreamRange);
    }
    return 1;
}

// 0x004F3530
int __fastcall SKILLSMON_LightAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    int nRadius = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel) - 3;
    if (nRadius < 2)
    {
        nRadius = 2;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 1;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = MISSILE_CURSECENTER;
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    CUNIT_FreeLight(pMissile);
    D2GfxLightStrc* pLight = DLIGHTMAP_MakeLightEntry(pMissile, 1, 1, 0xFF, 0xFF, 0, 0);
    if (pLight)
    {
        sub_00474290(pLight, nRadius);
        pMissile->pLight = pLight;
    }

    MISSILE_SetStreamMissile(pMissile, nMissile);
    MISSILE_SetStreamRange(pMissile, nRadius);
    return 1;
}

// 0x004F3C80
int __fastcall SKILLSMON_UseSkillParamsA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nParam1 = SKILLS_GetParam1(pSkill);
    const int nParam2 = SKILLS_GetParam2(pSkill);
    const int nParam3 = SKILLS_GetParam3(pSkill);
    return SKILLDESC_CreateCorpseExplosionMissiles(pUnit, nSkillId, nSkillLevel, nParam1, nParam2, nParam3);
}

struct Unicode;

struct D2MonStatsTxt;

struct D2RequestStrc;

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    int unk0x08[2];
    int nMissile;
    int nX;
    int nY;
    int unk0x1C[4];
    int nSkill;
    int nSkillLevel;
    int unk0x34[10];
};

D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540


class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};

static D2MonStatsTxt* MONSTATS_GetTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x004F3CE0
int __fastcall SKILLSMON_CreateSkillMissiles(D2UnitStrc* pUnit, int nSkillId, int nArg4, int nX, int nY, int nMonsterId)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (!MONSTATS_GetTxtRecord(nMonsterId))
    {
        return 0;
    }

    if (!nX || !nY)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2RequestStrc tRequest;
    memset(&tRequest, 0, sizeof(tRequest));
    tRequest.nType = 0x2001;
    tRequest.pUnit = pUnit;
    tRequest.nX = nX;
    tRequest.nY = nY;
    tRequest.nSkill = nSkillId;
    tRequest.nSkillLevel = nArg4;
    tRequest.nMissile = nMissile;
    D2UnitStrc* pMissile = sub_004CD540_HandleRequest(&tRequest);

    const int nMissileC = pSkillsTxt->wCltMissileC;
    if (nMissileC > 0 && nMissileC < sgptDataTables->nMissilesTxtRecordCount)
    {
        tRequest.nSkillLevel = 2;
        tRequest.nMissile = nMissileC;
        sub_004CD540_HandleRequest(&tRequest);
    }

    const int nMissileB = pSkillsTxt->wCltMissileB;
    if (pMissile)
    {
        if (nMissileB > 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
        {
            MISSILE_AddMissileEffect(pMissile, nMissileB, 0, 2, 0);
        }

        if (!CUNIT_GetPathTargetUnit(pUnit) && pSkillsTxt->wTgtSound > 0)
        {
            sub_004B9A00(pSkillsTxt->wTgtSound, pMissile, 0, 0, 0);
        }
    }

    return 1;
}

// 0x004F3E50
int __fastcall SKILLSMON_UseSkillParamsB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nParam1 = SKILLS_GetParam1(pSkill);
    const int nParam2 = SKILLS_GetParam2(pSkill);
    const int nParam3 = SKILLS_GetParam3(pSkill);
    return SKILLSMON_CreateSkillMissiles(pUnit, nSkillId, nSkillLevel, nParam1, nParam2, nParam3);
}

// 0x004F3EB0
int __fastcall sub_004F3EB0_CheckTargetRoom(D2UnitStrc* pUnit, int nSkillId, int nArg)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gnBitMasks_006CE268[0]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }
    return 1;
}


// 0x004F3FB0
D2UnitStrc* __fastcall SKILLSMON_GetTargetMonster(D2UnitStrc* pUnit)
{
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    if (!MONSTERREGION_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }
// build: symbol ?MONSTER_IsConvertible@* 0x004B11F0
    return MONSTER_IsConvertible(pTarget) ? pTarget : 0;
}


// 0x004F4610
int __fastcall SKILLSMON_MissileLine(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (UNITS_GetWeaponClass(pUnit) != 1)
    {
        const short nMissileB = pSkillsTxtRecord->wCltMissileB;
        if (nMissileB >= 0)
        {
            nMissile = nMissileB;
        }
    }

    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    int nDx = nX - CLIENTS_GetUnitX(pUnit);
    int nDy = nY - CLIENTS_GetUnitY(pUnit);
// build: symbol ?SKILLS_ScaleUpDirection@* 0x004C5390
    SKILLS_ScaleUpDirection(&nDx, &nDy);
    sub_004C53D0_ScaleDownDirection(&nDx, &nDy);
    nX -= nDx * nCount / 2;
    nY -= nDy * nCount / 2;

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x820;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nActivateFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetX = nX;
        tMissileParams.nTargetY = nY;
        MISSILE_CreateClientMissile(&tMissileParams);
        nX += nDx;
        nY += nDy;
    }
    return 1;
}
