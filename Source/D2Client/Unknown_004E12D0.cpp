#include "D2Client.h"

#include "D2Path.h"

#include "D2ClientUi.h"

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0

void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// 0x004E12D0
int __fastcall sub_004E12D0_SkillClearTargetFlags(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~0xEu;
    }
    return 1;
}

// 0x004E1720
int __fastcall sub_004E1720_SkillSetTargetFlags(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0xEu;
    }
    return 1;
}

// 0x004E1740
int __fastcall sub_004E1740_SkillNeedTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!CUNIT_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlagEx &= ~0x40000u;
    }
    return 1;
}

// 0x004E1C80
void __fastcall sub_004E1C80_CltMissileInitDiabWall(D2UnitStrc* pMissile, int nInitSeed)
{
    if (pMissile)
    {
        int nFrames = MISSILE_GetTotalFrames(pMissile);
        if (nFrames >= 78)
        {
            nFrames = 77;
            MISSILE_SetTotalFrames(pMissile, 77);
            MISSILE_SetCurrentFrame(pMissile, 77);
        }

        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        SEED_InitLowSeed(&pMissile->pSeed, nInitSeed + D2COMMON_10175_PathGetFirstPointX(pPath));

        if ((int)(SEED_RollRandomNumber(&pMissile->pSeed) % 100) >= 20)
        {
            PATH_SetType(pPath, 10);
            PATH_SetNewDistance(pPath, nFrames);
            D2Common_10142(pPath, pMissile, 0);
        }
    }
}

