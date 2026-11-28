#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0072D9D0

#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Unicode.h"
#include "D2StateIds.h"
#include "D2Records.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2SkillIds.h"
#include "D2SoundEnvironTxt.h"
#include "D2MonTypeTxt.h"
#include "D2MonsterIds.h"
#include "D2MissileIds.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2TxtItems.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
struct D2UnitStrc;




extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);              // 0x004B9A00
D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}



extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540


static D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInline_J03(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int MONSTERS_GetBaseIdInline_J03(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline_J03(nMonsterId);
    if (pMonStatsTxtRecord)
    {
        return pMonStatsTxtRecord->nBaseId;
    }
    return nMonsterId;
}





// 0x004F4C20
int __fastcall SKILLSAMA_CltDoRepeatAttack(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nTargetId = SKILLS_GetParam3(pSkill);
    D2UnitStrc* pTarget = CUNIT_FindClientUnit(nTargetId, SKILLS_GetParam2(pSkill));
    const int nRange = SKILLS_GetExtendedMeleeRange(pUnit);
    if (!pTarget || !UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 0x20003, nTargetId, 0);
        if (!pTarget)
        {
            return 0;
        }
    }

    const int nCount = SKILLS_GetParam1(pSkill) - 1;
    SKILLS_SetParam1(pSkill, nCount);
    if (nCount > 0)
    {
        pTarget = sub_004C5EB0_FindDestination(pUnit, 0, 0, nRange, 0x20003, !pTarget ? -1 : pTarget->dwUnitId, 0);
        if (!pTarget)
        {
            return 0;
        }

        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        SKILLS_SetParam2(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
        SKILLS_SetParam3(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
        SKILLS_ScaleFramePrecise(pUnit, SKILLDESC_GetSkillParamTwo(SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillsAma.cpp", 592)));
        const int nHitClass = UNITS_GetHitClass(pUnit);
        sub_004B9A00(UNITSND_GetDirectionRate(pUnit, nHitClass), pUnit, 0, 0, 0);
    }

    return 1;
}

// 0x004F4D90
int __fastcall SKILLDESC_CreateMissileAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    D2UnitStrc* pDestination = sub_004C5EB0_FindDestination(pUnit, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nRange, 3, !pTarget ? -1 : pTarget->dwUnitId, 0);
    if (!pDestination)
    {
        return 0;
    }

    const int nTargetX = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pTarget;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nTargetX = CLIENTS_GetUnitX(pDestination);
    tMissileParams.nTargetY = CLIENTS_GetUnitY(pDestination);
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, nTargetX);
    }

    return 1;
}

// 0x004F4EC0
int __fastcall SKILLDESC_GetSkillOverlay(D2UnitStrc* pUnit, int nSkillId, int nDefault, int nUnused)
{
    int nResult = nDefault;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nBaseId = MONSTERS_GetBaseIdInline_J03(pUnit->dwClassId);
        if (nBaseId >= 0 && nBaseId < sgptDataTables->nMonStatsTxtRecordCount && nBaseId == MONSTER_BLOODRAVEN && nSkillId == SKILL_NEST)
        {
            GFX_AddUnitOverlay(pUnit, 0x55, 2, 0, 0, 0, 0, 0);
            nResult = 0x54;
        }
    }

    return nResult;
}

// 0x004F4F40
int __fastcall SKILLDESC_GetMonSkillSound(D2UnitStrc* pUnit, int nSkillId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (pUnit)
    {
        const int nClassId = pUnit->dwClassId;
        if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
        {
            pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nClassId];
        }
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonSoundsTxt* pMonSoundsTxtRecord = DATATBLS_GetMonSoundsTxtRecordFromSoundId(pMonStatsTxtRecord->wMonSound);
    if (!pMonSoundsTxtRecord)
    {
        return 0;
    }

    int nSound = 0;
    for (int i = 0; i < 8; ++i)
    {
        if (pMonStatsTxtRecord->nSkill[i] == nSkillId)
        {
            switch (i)
            {
            case 0:
                nSound = pMonSoundsTxtRecord->dwSkill[0];
                break;

            case 1:
                nSound = pMonSoundsTxtRecord->dwSkill[1];
                break;

            case 2:
                nSound = pMonSoundsTxtRecord->dwSkill[2];
                break;

            case 3:
                nSound = pMonSoundsTxtRecord->dwSkill[3];
                break;
            }
        }
    }

    return nSound < 0 ? 0 : nSound;
}




