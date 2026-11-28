#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc*, int, int, int, int, int, int*); // 0x004C5EB0

static inline int UNITS_GetXPosition(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return unit->pStaticPath->nXPos;
    }
    return unit->pDynamicPath ? PATH_GetXPosition(unit->pDynamicPath) : 0;
}
static inline int UNITS_GetYPosition(D2UnitStrc* unit)
{
    switch (unit->dwUnitType)
    {
    case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return unit->pStaticPath->nYPos;
    }
    return unit->pDynamicPath ? PATH_GetYPosition(unit->pDynamicPath) : 0;
}

// 0x004F42E0
int __fastcall sub_004F42E0_SkillStartMeleeTarget(D2UnitStrc* unit, int skillId, int skillLevel)
{
    D2SkillsTxt* record = 0;
    if (skillId >= 0 && skillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        record = &sgptDataTables->pSkillsTxt[skillId];
    }
    if (!record) return 0;
    D2SkillStrc* skill = UNITS_GetUsedSkill(unit);
    if (!skill) return 0;
    int range = SKILLS_GetExtendedMeleeRange(unit);
    D2UnitStrc* target = CUNIT_GetPathTargetUnit(unit);
    int count = 0;
    if (!target)
    {
        target = sub_004C5EB0_FindDestination(unit, 0, 0, range, 0x20003, -1, &count);
        if (!target)
        {
            SKILLS_SetParam1(skill, 0);
            return 1;
        }
    }
    else
    {
        count = SKILLS_ScanCount(unit, 0, 0, range, 0x20003);
    }
    int max = SKILLS_EvaluateSkillFormula(unit, record->dwCalc[0], skillId, skillLevel);
    if (count >= max)
    {
        count = max;
    }
    SKILLS_SetParam1(skill, count);
    int posY = UNITS_GetYPosition(target);
    D2Common_10216(unit->pDynamicPath, UNITS_GetXPosition(target), posY, 0);
    int targetType = target ? target->dwUnitType : UNIT_INVALID;
    SKILLS_SetParam2(skill, targetType);
    range = target ? target->dwUnitId : -1;
    SKILLS_SetParam3(skill, range);
    return 1;
}
