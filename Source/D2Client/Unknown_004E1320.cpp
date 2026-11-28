#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CommonApi.h"
#define UNIT_FLAG 0x40
#define COUNT_BIAS 6
#define MIN_COUNT 1
#define BURST_MULT 1
struct D2DynamicPathStrc;
struct D2StaticPathStrc;
struct D2InventoryStrc;
struct D2GfxLightStrc;
struct D2MissilesTxt;
extern D2DataTablesStrc* sgptDataTables;  // 0x00744304
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0
void __fastcall MISSILE_CreateBurstAt(D2UnitStrc* pMissile, int nX, int nY, int nCount, int nMissile, int nSkill, int nLevel, int nPerStep, int nMult); // 0x004CED60
static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}
// 0x004E1320
int __fastcall sub_004E1320_CastMissileBurst(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxt)
        return 0;
    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= UNIT_FLAG;
    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        return 0;
    int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraRangeCalc, nSkillId, nSkillLevel) - COUNT_BIAS;
    if (nCount < MIN_COUNT)
        nCount = MIN_COUNT;
    int nPerStep = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCltCalc[0], nSkillId, nSkillLevel);
    MISSILE_CreateBurstAt(pUnit, nTargetX, nTargetY, nCount, nMissile, nSkillId, nSkillLevel, nPerStep, BURST_MULT);
    return 1;
}
