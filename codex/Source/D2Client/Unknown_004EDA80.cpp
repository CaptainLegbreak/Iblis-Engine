#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Records.h"

struct D2SkillsTxt;
struct D2SkillDescTxt;
union D2SeedStrc;
struct D2StaticPathStrc;
struct D2MissileStrc;



typedef void (__fastcall* SKILLDESCFN)(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4);

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0



D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190
D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
extern SKILLDESCFN gpfnSkillDescFuncs[]; // 0x0072D7F8



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2UnitStrc* __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __fastcall GFX_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY); // 0x004706E0
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


typedef int (__fastcall* D2UnitFindCallback)(D2UnitStrc* pUnit, void* pArg);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0
int __fastcall SKILLDESC_IsVineBeastMissile(D2UnitStrc* pUnit, void* pArg); // 0x004F0F10
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection); // 0x006488A0
void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitFindCallback pCallback, void* pArg, int nSize); // 0x00641CB0
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60
void __fastcall SKILLS_ScaleFramePrecise(D2UnitStrc* pUnit, int nPercent); // 0x004C76D0
void __fastcall SKILLS_ApplyClientSkillCalc(D2UnitStrc* pUnit, int nValue); // 0x004C7BE0
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0
void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70
int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0
void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40


#include "gen/data/Source/D2Client/Unknown_004EDA80.inc"
struct D2UnitStrc;

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004F03C0
int __fastcall sub_004F03C0_CltMissileRequest(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileB;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 1;
    }

    return MISSILE_SubmitMissileRequest(pUnit, nMissile, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nSkillId, 1) != 0;
}

static inline D2SkillsTxt* GetSkill(int nSkill)
{
    if (nSkill < 0 || nSkill >= sgptDataTables->nSkillsTxtRecordCount)
        return 0;
    return &sgptDataTables->pSkillsTxt[nSkill];
}

// 0x004F0430
int __fastcall sub_004F0430_CreateTargetMissile(D2UnitStrc* pUnit, int nSkill, int nUnused)
{
    D2SkillsTxt* pSkill = GetSkill(nSkill);
    if (!pSkill)
        return 0;
    int nMissile = pSkill->wCltMissileB;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 1;
    {
        D2UnitStrc* pMissile = sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkill, 1);
        if (!pMissile)
            return 0;
        D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
        if (pTarget)
        {
            PARTICLE_ResetGfxMotion(pMissile);
            int nX, nY;
            GFX_GetUnitCelOffsets(pTarget, 14, &nX, &nY);
            GFXUTIL_SetMotionVectorA(pMissile, nX, 0, -nY);
        }
    }
    return 1;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
    {
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > 3 && pUnit->dwUnitType <= 5))
    {
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static void MISSILE_SetPathDirectionInline(D2UnitStrc* pMissile, unsigned char nDirection)
{
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    PATH_SetDirection(pPath, nDirection);
    D2COMMON_10203_PATH_SetRotateFlag(pPath, 0);
}

// 0x004F04F0
static int __stdcall SKILLSEMON_CreateMissileFan(int nMissile, int nSkillId, int nSkillLevel, int nCount, D2UnitStrc* pUnit)
{
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.dwFlags = 3;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pInitFunc = SKILLDESC_InitCappedChargedPath;
    if (!ITEM_GetTargetPosition(pUnit, &tMissileParams.nX, &tMissileParams.nY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
// build: symbol ?gaFanOffsetX@* 0x006DBF50
        tMissileParams.nTargetX = gaFanOffsetX[i & 7];
// build: symbol ?gaFanOffsetY@* 0x006DBF70
        tMissileParams.nTargetY = gaFanOffsetY[i & 7];
        tMissileParams.nInitArg = i;
        MISSILE_CreateClientMissile(&tMissileParams);
    }
    return 1;
}

// 0x004F0590
static int __stdcall SKILLSEMON_CreateMissileRequest(int nMissile, int nSkillId, int nSkillLevel, int bNotify, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMissile = MISSILE_SubmitMissileRequest(pUnit, nMissile, UNITS_GetXPositionInline(pUnit), UNITS_GetYPositionInline(pUnit), nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetPathDirectionInline(pMissile, UNITS_GetDirection(pUnit));
    if (bNotify)
    {
        CUNIT_MarkUnitDead(pMissile);
    }
    return 1;
}

int __fastcall sub_004F0650_CltSkillMissileFan(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0 && nMissileA < sgptDataTables->nMissilesTxtRecordCount)
    {
        SKILLSEMON_CreateMissileRequest(nMissileA, nSkillId, nSkillLevel, 0, pUnit);
    }

    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
        SKILLSEMON_CreateMissileFan(nMissileB, nSkillId, nSkillLevel, nCount, pUnit);
    }
    return 1;
}

// build: symbol ?SKILLSEMON_CltSkillMonMissile@* 0x004F0F30
int __fastcall SKILLSEMON_CltSkillMonMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_VINEATTACK);
    if (!pSkill)
    {
// build: symbol ?gszSkillsEMonCpp@* 0x006DBF90
        SKILLS_AssignSkill(pUnit, SKILL_VINEATTACK, 1, 0, gszSkillsEMonCpp, 0x35C);
        pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_VINEATTACK);
        if (!pSkill)
        {
            return 0;
        }
    }

    const int nSkill = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillsEMonCpp, 0x364);
    nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    int nValue = SKILLS_GetParam1(pSkill);
    SKILLS_SetParam1(pSkill, nValue + 1);
    const int nX = SKILLS_GetParam2(pSkill);
    const int nY = SKILLS_GetParam3(pSkill);
    int bFire = 0;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(nSkill);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nValue >= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkill, nSkillLevel))
    {
        bFire = 1;
    }

    nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkill, nSkillLevel);
    if (UNITS_GetDistanceToCoordinates(pUnit, nX, nY) >= nValue)
    {
        bFire = 1;
    }

    int nMissile;
    switch (pUnit->dwAnimMode)
    {
    case 1:
        if (bFire)
        {
            D2UnitStrc* pTarget = D2Common_10407(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), SKILLDESC_IsVineBeastMissile, 0, 1);
            if (pTarget)
            {
// build: symbol ?MISSILE_CltMissileHit@* 0x004D2D70
                MISSILE_CltMissileHit(pTarget, 0, 0);
            }
        }
        nMissile = pSkillsTxtRecord->wCltMissileD;
        break;

    case 2:
        nMissile = pSkillsTxtRecord->wCltMissileC + SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2);
        break;

    default:
        return 1;
    }

    if (bFire && nMissile > 0)
    {
        SKILLS_SetParam1(pSkill, 0);
        SKILLS_SetParam2(pSkill, CLIENTS_GetUnitX(pUnit));
        SKILLS_SetParam3(pSkill, CLIENTS_GetUnitY(pUnit));
        SKILLSEMON_CreateMissileRequest(nMissile, nSkill, nSkillLevel, 1, pUnit);
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

// 0x004F0EF0
int __fastcall sub_004F0EF0_UpdateRiderPath(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    D2Common_10235_PATH_UpdateRiderPath(pUnit, pOwner);
    return 1;
}





// 0x004F26D0
int __fastcall sub_004F26D0_ApplyCltCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    SKILLS_ApplyClientSkillCalc(pUnit, !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[3]);
    return 1;
}


