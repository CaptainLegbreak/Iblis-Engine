#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"



void __fastcall sub_004B9A00(int nSound, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4); // 0x004B9A00

static inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTable->nSkillsTxtRecordCount)
    {
        return &sgptDataTable->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004F4590
int __fastcall sub_004F4590_DoSkillSound(D2UnitStrc* pUnit, int nSkillId, int nUnused)
{
    if (pUnit->nActionFrame == 3)
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 0;
        }

        if ((!pUnit ? 6 : pUnit->dwUnitType) == 0 && pSkillsTxtRecord->wDoSoundA > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wDoSoundA, pUnit, 0, 0, 0);
        }

        if ((!pUnit ? 6 : pUnit->dwUnitType) == 1 && pSkillsTxtRecord->wDoSoundB > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wDoSoundB, pUnit, 0, 0, 0);
        }
    }
    return 1;
}
