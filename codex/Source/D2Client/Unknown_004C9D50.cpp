#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Records.h"
#include "D2AnimData.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

#pragma pack(push, 1)

#pragma pack(pop)

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __fastcall MISSILE_DoSkillWithTempTarget(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x004CA060

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

extern int gaLevelVisited[]; // 0x007C78B8

extern int gnGlobal_007C88B8; // 0x007C88B8

extern int gnGlobal_007C88BC; // 0x007C88BC

extern int gnGlobal_007C88C0; // 0x007C88C0

extern int gnGlobal_007C88C4; // 0x007C88C4

extern int gnGlobal_007C88C8; // 0x007C88C8

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

int __fastcall SKILLS_DoClientSkill(D2UnitStrc* pUnit, int nSkillId, int nArg, int nMode); // 0x004C6680

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

D2UnitStrc* __fastcall sub_004C5EB0_FindDestination(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0

#define SKILLSFLAGINDEX_LOB 1

#define SKILLSFLAGINDEX_PRGSTACK 7

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

int __cdecl sub_0044DA90(); // 0x0044DA90

int __fastcall SKILLS_CallStartSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nOwnerGUID); // 0x004C6660

void __fastcall UNITSND_PlayAttackSound(D2UnitStrc* pUnit, int nMode, int nArg); // 0x004CB6A0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

D2UnitStrc* __fastcall SKILLS_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nArg5, int nUnitId, int nArg7); // 0x004C5EB0

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

int __fastcall CUNIT_ValidateMonsterId(int nMonsterId); // 0x00463900

unsigned int gdwNextTick; // 0x007C78B0

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

// 0x004C9D50
static inline D2UnitStrc* sub_004C9D50_FindDestinationById(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C5EB0_FindDestination(pUnit, 0, 0, 3, 3, nUnitId, 0);
}

// 0x004C9D70
int __fastcall SKILLS_FindEventFrame(D2UnitStrc* pUnit)
{
    D2AnimSeqTxt* pAnimSeqTxt = DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit);
    if (pAnimSeqTxt)
    {
        int nFrames = DATATBLS_GetSeqFrameCount(pUnit);
        for (int i = 0; i < nFrames; i += 1)
        {
            if (!pAnimSeqTxt->nEvent)
                return i - 1;
        }
    }
    return 7;
}

static inline int sub_GetUnitTypeChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }
    return 6;
}

static inline int sub_GetUnitGUIDChecked(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }
    return -1;
}

// 0x004C9DB0
int __fastcall SKILLS_CltDoCharge(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nFlags = SKILLS_GetFlags(pSkill);
    int nFrameCount = 15;
    if (DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit))
    {
        nFrameCount = DATATBLS_GetSeqFrameCount(pUnit);
    }

    const int nEventFrame = SKILLS_FindEventFrame(pUnit);
    if (pUnit && (pUnit->dwUnitType == UNIT_PLAYER || pUnit->dwUnitType == UNIT_MONSTER) && pUnit->nActionFrame == 3)
    {
        UNITSND_PlayAttackSound(pUnit, pUnit->dwAnimMode, 0);
        return 0;
    }

    D2UnitStrc* pTarget = 0;
    const int nTargetType = SKILLS_GetParam1(pSkill);
    const int nTargetId = SKILLS_GetParam2(pSkill);
    if (nTargetType != 6)
    {
        pTarget = CUNIT_FindClientUnit(nTargetId, nTargetType);
    }

    if (nFlags & 1)
    {
        if (pTarget && UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        {
            SKILLS_SetFlags(pSkill, 0);
            UNITS_SetAnimationFrame(pUnit, nEventFrame + 1);
            pUnit->dwFrameCountPrecise = nFrameCount << 8;
            return 1;
        }

        if (nFlags & 2)
        {
            D2UnitStrc* pFound = SKILLS_ScanFindUnit(pUnit, 0, 0, 3, 3, nTargetId, 0);
            if (pFound && UNITS_IsInMeleeRange(pUnit, pFound, 0))
            {
                SKILLS_SetFlags(pSkill, 0);
                SKILLS_SetParam1(pSkill, sub_GetUnitTypeChecked(pFound));
                SKILLS_SetParam2(pSkill, sub_GetUnitGUIDChecked(pFound));
                return 1;
            }

            SKILLS_SetFlags(pSkill, 0);
            if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
            {
                switch (CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit)))
                {
                case 0x1B4:
                case 0x1B9:
                    return 1;
                }
            }

            pUnit->dwFrameCountPrecise = 0x100;
            return 1;
        }

        if ((pUnit->dwSeqFrame >> 8) >= nEventFrame)
        {
            UNITS_SetAnimationFrame(pUnit, 0);
            pUnit->dwFrameCountPrecise = nFrameCount << 8;
            SKILLS_SetFlags(pSkill, 1);
        }

        pUnit->dwFlags &= ~0x40;
        int nState = SKILLS_GetParam3(pSkill);
        if (nState < 2)
        {
            ++nState;
        }
        SKILLS_SetParam3(pSkill, nState);
        return 1;
    }

    SKILLS_SetFlags(pSkill, 0);
    SKILLS_SetParam1(pSkill, 0);
    SKILLS_SetParam2(pSkill, 0);
    pUnit->dwFrameCountPrecise = (nFrameCount - (pUnit->dwSeqFrame >> 8)) << 8;
    if (!pTarget)
    {
        pTarget = SKILLS_ScanFindUnit(pUnit, 0, 0, 3, 3, -1, 0);
        if (!pTarget)
        {
            return 0;
        }
    }

    D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
    return 1;
}

// 0x004CA000
void __fastcall SKILLS_EndCharge(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    int nFlags = SKILLS_GetFlags(pSkill);
    if (nFlags & 1)
        SKILLS_SetFlags(pSkill, nFlags | 2);
    STATES_ToggleState(pUnit, 0x36, 0);
}

// 0x004CA030
int __fastcall sub_004CA030_TickEvent(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nTick = sub_0044DA90();
    if (nTick > gdwNextTick)
    {
        gdwNextTick = nTick + 5;
        sub_004AF890(pUnit, 1, 0);
    }
    return 1;
}

// 0x004CA060
int __fastcall MISSILE_DoSkillWithTempTarget(D2UnitStrc* pUnit, int nSkillId, int nArg, D2UnitStrc* pTarget, int nX, int nY, unsigned short nMode)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pOldTarget = CUNIT_GetPathTargetUnit(pUnit);
    int nOldX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    int nOldY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    int bFlag = (pUnit->dwFlags >> 6) & 1;
    if (pTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    }

    int nResult = 0;
    if (pSkillsTxtRecord->nFlags[4] & gnBitMasks_006CE268[2])
    {
        int bToggled = 0;
        if (pTarget && CUNIT_IsDeadOrDying(pTarget) && STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
        {
            bToggled = 1;
            STATES_ToggleState(pTarget, 0x76, 0);
        }

        if (!SKILLS_CallStartSkill(pUnit, nSkillId, nArg, -1))
        {
            goto restore;
        }

        if (bToggled)
        {
            STATES_ToggleState(pTarget, 0x76, 1);
        }
    }

    if (pSkillsTxtRecord->wItemStartSound >= 0)
    {
        sub_004B9A00(pSkillsTxtRecord->wItemStartSound, pUnit, 0, 0, 0);
    }

    if (pSkillsTxtRecord->wItemCastOverlay >= 0 && pSkillsTxtRecord->wItemCastOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        GFX_AddUnitOverlay(pUnit, pSkillsTxtRecord->wItemCastOverlay, 2, 0, 0, 0, 0, 0);
    }

    nResult = SKILLS_DoClientSkill(pUnit, nSkillId, nArg, nMode);

restore:
    if (pOldTarget)
    {
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nOldX, nOldY);
    }

    if (bFlag)
    {
        pUnit->dwFlags |= 0x40;
    }
    else
    {
        pUnit->dwFlags &= ~0x40;
    }

    return nResult;
}

D2UnitStrc* __fastcall sub_M109_Emit_004C9D50(D2UnitStrc* pUnit, int nUnitId)
{
    return sub_004C9D50_FindDestinationById(pUnit, nUnitId + 1);
}

// 0x004CA200
int __fastcall SKILLS_TriggerSkillOnUnit(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5)
{
    if (pArg1 && nArg4)
    {
        return MISSILE_DoSkillWithTempTarget(pArg1, nArg2, nArg3, nArg4, 0, 0, nArg5);
    }
    return 0;
}

// 0x004CA230
int __fastcall SKILLS_DoSkillAtPosition(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6)
{
    if (pArg1 && nArg4 && nArg5)
    {
        return MISSILE_DoSkillWithTempTarget(pArg1, nArg2, nArg3, 0, nArg4, nArg5, nArg6);
    }
    return 0;
}

// 0x004CA270
int __cdecl SKILLS_GetLevelsTxtRecordCount()
{
    return sgptDataTables->nLevelsTxtRecordCount;
}

// 0x004CA280
void __cdecl SKILLS_ResetLevelSpeech()
{
    gnGlobal_007C88B8 = 0;
    gnGlobal_007C88BC = 0;
    gnGlobal_007C88C0 = 0x5A;
    gnGlobal_007C88C4 = 0;
    gnGlobal_007C88C8 = 0;
    memset(gaLevelVisited, 0, 0x1000);
}

#include "gen/data/Source/D2Client/Unknown_004C9D50.inc"
