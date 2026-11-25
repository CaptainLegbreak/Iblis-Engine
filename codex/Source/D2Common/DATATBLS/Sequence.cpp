#include "D2Common.h"
#include "D2Structs.h"
#include "D2AnimData.h"

struct D2InventoryStrc;



struct D2PlayerWeaponSequencesStrc
{
    D2AnimSeqRecordStrc weaponRecords[14];
};

extern D2PlayerWeaponSequencesStrc* gPlayerWeaponsSequenceTable[];                                                           // 0x007483B8
extern const int gWeaponIndexToClassMap[14][2];                                                               // 0x00748418
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                                 // 0x00620250
int __fastcall SKILLS_GetSeqNumFromSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill);                                       // 0x00643D00
void* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId);                                                           // 0x00451F80
D2AnimSeqRecordStrc* __stdcall DATATBLS_GetMonSeqTableRecord(int nSequence);                                                // 0x00659E30
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClass, int nAnimMode, int bUseConvertedMode); // 0x0064F380
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09

#define SEQ_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x006632C0
static int DATATBLS_GetWeaponClassIndexFromUnit(D2UnitStrc* pUnit)
{
    int nWeaponClass;
    COMPOSIT_GetWeaponClassId(pUnit, pUnit->pInventory, &nWeaponClass, -1, 1);

    for (int i = 0; i < 14; ++i)
    {
        if (nWeaponClass == gWeaponIndexToClassMap[i][1])
        {
            return gWeaponIndexToClassMap[i][0];
        }
    }

    return -1;
}

// 0x00663310
static D2AnimSeqRecordStrc* DATATBLS_GetSeqRecordFromUnit(D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nSequenceNum = SKILLS_GetSeqNumFromSkill(pUnit, pSkill);
    if (nSequenceNum <= 0)
    {
        return 0;
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    D2AnimSeqRecordStrc* pSeqRecord = 0;
    if (nUnitType == 0)
    {
        D2PlayerWeaponSequencesStrc* pWeaponSequences = gPlayerWeaponsSequenceTable[nSequenceNum];
        int nWClassIndex = DATATBLS_GetWeaponClassIndexFromUnit(pUnit);
        SEQ_ASSERT(nWClassIndex != -1, 1331);
        pSeqRecord = &pWeaponSequences->weaponRecords[nWClassIndex];
    }
    else if (nUnitType == 1 && DATATBLS_GetMonStatsTxtRecord(pUnit == 0 ? -1 : pUnit->dwClassId))
    {
        pSeqRecord = DATATBLS_GetMonSeqTableRecord(nSequenceNum);
    }

    return pSeqRecord;
}

// 0x006633B0
D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit)
{
    D2AnimSeqRecordStrc* pSeqRecord = DATATBLS_GetSeqRecordFromUnit(pUnit);
    if (!pSeqRecord)
    {
        return 0;
    }

    return pSeqRecord->pAnimSeqTxtRecord;
}

// 0x006633D0
int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit)
{
    D2AnimSeqRecordStrc* pSeqRecord = DATATBLS_GetSeqRecordFromUnit(pUnit);
    if (!pSeqRecord)
    {
        return 0;
    }

    return pSeqRecord->nSeqFramesCount << 8;
}

// 0x006633F0
int __stdcall DATATBLS_GetSeqFrameCount(D2UnitStrc* pUnit)
{
    D2AnimSeqRecordStrc* pSeqRecord = DATATBLS_GetSeqRecordFromUnit(pUnit);
    if (!pSeqRecord)
    {
        return 0;
    }

    return pSeqRecord->nFramesCount;
}

// 0x00663410
void __stdcall DATATBLS_ComputeSequenceAnimation(D2AnimSeqTxt* pMonSeqTxt, int nTargetFramePoint, int nCurrentFramePoint, unsigned int* pMode, unsigned int* pFrame, int* pDirection, int* pEvent)
{
    if (!pMonSeqTxt)
    {
        *pMode = 0;
        *pFrame = 0;
        *pDirection = 0;
        *pEvent = 0;
        return;
    }

    const D2AnimSeqTxt* pMonSeqTxtRecord = &pMonSeqTxt[nTargetFramePoint >> 8];
    *pMode = pMonSeqTxtRecord->nMode;
    *pFrame = pMonSeqTxtRecord->nFrame;
    *pDirection = pMonSeqTxtRecord->nDir;

    if (nTargetFramePoint == nCurrentFramePoint)
    {
        *pEvent = pMonSeqTxtRecord->nEvent;
        return;
    }

    *pEvent = 0;
    const int nTargetFrame = nTargetFramePoint >> 8;
    int nFrame = (nCurrentFramePoint >> 8) + 1;
    const D2AnimSeqTxt* pRecord = &pMonSeqTxt[nFrame];
    for (; nFrame <= nTargetFrame; ++nFrame, ++pRecord)
    {
        if (pRecord->nEvent)
        {
            *pEvent = pRecord->nEvent;
        }
    }
}

// 0x006634C0
void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent)
{
    if (!pMonSeqTxt)
    {
        *pEvent = 0;
        return;
    }

    *pEvent = pMonSeqTxt[nSeqFramePoint >> 8].nEvent;
}

#include "gen/data/Source/D2Common/DATATBLS/Sequence.inc"
