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
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc*, int, int, int, int, int, int); // 0x004C5EB0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int skillId)
{
    if (skillId >= 0 && skillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[skillId];
    return 0;
}
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

// 0x004F4450
int __fastcall sub_004F4450_InitializeSkillTarget(D2UnitStrc* unit, int skillId, int skillLevel)
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
    if (!target)
    {
        target = sub_004C5EB0_FindDestination(unit, 0, 0, range, 0x20003, -1, 0);
        if (!target)
        {
            SKILLS_SetParam1(skill, 0);
            return 1;
        }
    }
    SKILLS_SetParam1(skill, SKILLS_EvaluateSkillFormula(unit, record->dwCalc[0], skillId, skillLevel));
    int posY = UNITS_GetYPosition(target);
    D2Common_10216(unit->pDynamicPath, UNITS_GetXPosition(target), posY, 0);
    SKILLS_SetParam2(skill, !target ? 6 : target->dwUnitType);
    SKILLS_SetParam3(skill, !target ? -1 : target->dwUnitId);
    return 1;
}
