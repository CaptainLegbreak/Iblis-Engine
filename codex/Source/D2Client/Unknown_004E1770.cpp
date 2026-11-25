#include "D2Client.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2GameTypes.h"

#include "D2ClientUi.h"

#include "D2Txt.h"

#include "D2ClientSound.h"

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const int gaSkillRingOffsetX[16]; // 0x006DBAF8

extern const int gaSkillRingOffsetY[16]; // 0x006DBAB8

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

static inline D2SkillsTxt* GetSkillsRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x004E1770
int __fastcall sub_004E1770_SpawnSkillMissileRing(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missileParams;
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    int nMissile = pSkillsTxt->wCltMissileA;
    D2MissilesTxt* pMissilesTxt = 0;
    if (nMissile >= 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
        pMissilesTxt = &sgptDataTables->pMissilesTxt[nMissile];
    if (pMissilesTxt)
    {
    if (pUnit)
        pUnit->dwFlags |= 0x40;

    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x1F;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = nMissile;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    missileParams.nVelocity = pMissilesTxt->dwParam[0] << 6;
    int nStep = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    if (nStep < 1)
        nStep = 1;
    for (int i = 0; i < 16; i += 2)
    {
        missileParams.nTargetX = gaSkillRingOffsetX[i];
        missileParams.nTargetY = gaSkillRingOffsetY[i];
        MISSILE_CreateClientMissile(&missileParams);
    }
    missileParams.nVelocity = pMissilesTxt->dwParam[1] << 6;
    if (nStep > 1)
    {
        for (int i = 0; i < 15; i += nStep)
        {
            missileParams.nTargetX = gaSkillRingOffsetX[i + 1];
            missileParams.nTargetY = gaSkillRingOffsetY[i + 1];
            MISSILE_CreateClientMissile(&missileParams);
        }
    }
    return 1;
    }
    return 0;
}

#include "gen/data/Source/D2Client/Unknown_004E1770.inc"
