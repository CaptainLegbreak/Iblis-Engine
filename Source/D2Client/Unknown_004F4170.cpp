#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"




extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit);                                       // 0x004648F0
int __fastcall SKILLS_CanThrow(D2UnitStrc* pUnit);                                                 // 0x004C54F0
int __fastcall SKILLS_ScanCount(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags);           // 0x004C5E30
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int* pCount); // 0x004C5EB0
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections);                            // 0x00649EF0

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x004F4170
int __fastcall sub_004F4170_SkillStartMultiTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_CanThrow(pUnit))
    {
        return 0;
    }

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

    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    int nCount = 0;
    if (!pTarget)
    {
        pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 3, -1, &nCount);
    }
    else
    {
        nCount = SKILLS_ScanCount(pUnit, 0, 0, nRange, 3);
    }

    int nMin = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
    int nMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nMin > nMax)
    {
        nMin = nMax;
    }

    nCount = D2_MIN(D2_MAX(nCount, nMin), nMax);
    SKILLS_SetParam1(pSkill, nCount);

    if (pTarget)
    {
        SKILLS_SetParam2(pSkill, sub_0044BE50(pTarget));
        SKILLS_SetParam3(pSkill, UNITS_GetUnitId(pTarget));
    }
    else
    {
        SKILLS_SetParam2(pSkill, 1);
        SKILLS_SetParam3(pSkill, -1);
    }

    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
    }

    return 1;
}
