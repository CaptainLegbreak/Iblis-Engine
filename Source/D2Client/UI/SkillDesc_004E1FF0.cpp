#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2TxtItems.h"
#include "D2Path.h"
#include "D2SoundEnvironTxt.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"
#include "D2WinApi2.h"

#define UNIT_ITEM 4

struct D2StaticPathStrc;

struct D2GfxLightStrc;

struct D2SkillDescTxt;

struct D2MissilesTxt;

struct Unicode;

struct D2SkillsTxt;

struct D2MissileStrc;

union D2SeedStrc;

struct D2MonsterDataStrc;

struct D2SoundEnvironTxtStrc;

struct D2MonTypeTxt;

struct D2ItemStatCostTxt;

struct D2MonStatsTxt;

struct D2MonSoundsTxt;

struct D2DifficultyLevelsTxt;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304




D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540


enum
{
    SKILLDO_FRAME_A = 6,
    SKILLDO_FRAME_A_SET = 7,
    SKILLDO_FRAME_A_COUNT = 0x3200,
    SKILLDO_FRAME_B = 22,
    SKILLDO_REPEATS = 4,
    SKILLDO_FRAME_B_SET = 40,
    SKILLDO_FRAME_B_COUNT = 0x1100,
    SKILLDO_FRAME_C = 30,
    SKILLDO_FRAME_C_STATE = 12,
    PATHINIT_MAX_FRAMES = 78,
    PATHINIT_CAP_FRAMES = 77,
    PATHTYPE_CHARGEDBOLT = 10,
};








int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00


void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10


void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0



unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2SkillsTxt* __fastcall SCMD_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0





int __fastcall SKILLS_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, int nArg, int* pOut); // 0x004C5EB0

















typedef char check_scalar_width[(sizeof(unsigned int) == 4 && sizeof(int) == 4) ? 1 : -1];

extern "C" int __fastcall SKILLDESC_RollPlayerSeed(int nRange); // 0x004E40A0

typedef char check_int_width[sizeof(int)==4?1:-1];

typedef char check_uint_width[sizeof(unsigned int)==4?1:-1];

extern int gnEnvironLevelId; // 0x007C8C7C

extern int gnEnvironSoundHandle; // 0x007C8C80

extern int gnWeatherSoundHandle; // 0x007C8C84

extern int gnEnvironSoundId; // 0x007C8C88

extern int gnWeatherSoundId; // 0x007C8C8C

extern int gnEnvironAmbientId; // 0x007C8C90

extern unsigned int gnAmbientDelay; // 0x007C8C94

extern unsigned int gnAmbientTick; // 0x007C8C98




void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0





void __fastcall SOUNDINST_StopSound(int nHandle); // 0x004BA840

extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100

struct D2MonTypeTxt
{
    int unk0x00[3];
};


extern const int gaSetMaskToBonusMappingTable[0x40]; // 0x006DBD90


void __fastcall SKILLDESC_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800


extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268


typedef char chkSkillsTxt_M125[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char chkSkillDescTxt_M125[sizeof(D2SkillDescTxt) == 0x120 ? 1 : -1];



extern int gnTextOffset1; // 0x0072D8D4

extern int gnTextOffset2; // 0x0072D8D0





void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080



extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC

extern "C" const char gszFmtRange[];                                                                // 0x006D9D70

void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870


int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360













char gbTextOffsetInit; // 0x007C8C9C

char gbSkillRefreshInit; // 0x007C8CA4





static int __stdcall SKILLDESC_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId); // 0x004E4C50


inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline unsigned char MONSTER_GetComponent10(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[10];
    }

    return 0;
}

inline unsigned char MONSTER_GetComponent11(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[11];
    }

    return 0;
}

// 0x004E2A40
int __fastcall SKILLDESC_CltDoComponentMissileA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    nMissile += MONSTER_GetComponent10(pUnit);
    if (nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (VIEW_GetMissilesTxtRecord(nMissile))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x40;
        }

        if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
        {
            MISSILE_SubmitOffsetRequest(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
        }
        else
        {
            AUTOMAP_RequestAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

// 0x004E2B30
int __fastcall SKILLDESC_CltDoComponentMissileB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    nMissile += MONSTER_GetComponent11(pUnit);
    if (nMissile < sgptDataTables->nMissilesTxtRecordCount && VIEW_GetMissilesTxtRecord(nMissile))
    {
        if (pUnit)
        {
            pUnit->dwFlags |= 0x40;
        }

        if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
        {
            MISSILE_SubmitOffsetRequest(pUnit, nMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
        }
        else
        {
            AUTOMAP_RequestAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
        }

        return 1;
    }

    return 0;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_J03(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline_J03(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x004E2C20
int __fastcall SKILLDESC_CltDoWeaponOrSkillMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_J03(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissile = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
    if (nMissile && nMissile != MISSILE_BOLT)
    {
        if (DATATBLS_GetMissilesTxtRecordInline_J03(nMissile))
        {
            AUTOMAP_RequestAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
            return 1;
        }

        return 0;
    }

    const int nCltMissile = pSkillsTxtRecord->wCltMissileA;
    if (nCltMissile < 0 || nCltMissile >= sgptDataTables->nMissilesTxtRecordCount || !VIEW_GetMissilesTxtRecord(nCltMissile))
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
    {
        MISSILE_SubmitOffsetRequest(pUnit, nCltMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
    }
    else
    {
        AUTOMAP_RequestAtTarget(pUnit, nCltMissile, nSkillId, nSkillLevel);
    }

    return 1;
}

// 0x004E2ED0
void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= PATHINIT_MAX_FRAMES)
    {
        nFrames = PATHINIT_CAP_FRAMES;
        MISSILE_SetTotalFrames(pMissile, nFrames);
        MISSILE_SetCurrentFrame(pMissile, nFrames);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, D2COMMON_10175_PathGetFirstPointX(pPath) + nSeedOffset);
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nFrames);
    D2Common_10142(pPath, pMissile, 0);
}

// 0x004E3050
void __fastcall SKILLDESC_ToggleStateOffCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

// 0x004E3060
int __fastcall SKILLDESC_CltDoPrgState(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        if (pSkillsTxtRecord->wPrgOverlay > 0 && pSkillsTxtRecord->wPrgOverlay < sgptDataTables->nOverlayTxtRecordCount)
        {
            GFX_AddUnitOverlay(pUnit, pSkillsTxtRecord->wPrgOverlay, 2, 0, 0, 0, 0, 0);
        }
        if (pSkillsTxtRecord->wPrgSound > 0)
        {
            sub_004B9A00(pSkillsTxtRecord->wPrgSound, 0, 0, 0, 0);
        }
    }
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_INFERNO);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(0, 2, 0x15, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return 0;
        }
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLDESC_ToggleStateOffCallback);
        STATLIST_SetState(pStatList, STATE_INFERNO);
        STATES_ToggleState(pUnit, 12, 1);
        return 1;
    }
    UNITS_SetAnimationFrame(pUnit, 8);
    pUnit->dwFrameCountPrecise = 0x500;
    D2COMMON_10476(pStatList, 7);
    return 1;
}

// 0x004E31C0
D2UnitStrc* __fastcall SKILLDESC_CltDoRandomMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
        return 0;

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
        return 0;

    int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB < 0 || nMissileB >= sgptDataTables->nMissilesTxtRecordCount)
        nMissileB = -1;

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
        return 0;

    if (nMissileB >= 0 && SEED_RollLimitedRandomNumber(&pUnit->pSeed, 2))
        nMissile = nMissileB;

    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nRange < 1)
        nRange = 1;

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 0x8020;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nTargetX = nX;
    tMissileParams.nTargetY = nY;
    tMissileParams.nRange = nRange;

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
        sub_004E3170_SetMissileFrames(pMissile, nRange);

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        if (pUnit->pAnimSeq)
        {
            UNITS_SetAnimationFrame(pUnit, 8);
            pUnit->dwFrameCountPrecise = 0x500;
        }
        else
        {
            pUnit->nSeqCurrentFramePrecise = (pUnit->nSeqCurrentFramePrecise & 0xFFFFFF00) - 0x200;
        }
    }

    return pMissile;
}

// 0x004E37C0
int __fastcall SKILLDESC_CltDoMissileAtTargetOffset(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nOffsetX = 0;
    int nOffsetY = 0;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        nOffsetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        nOffsetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x21;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit) + nOffsetX;
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    if (!ITEM_GetTargetPosition(pUnit, &tMissileParams.nTargetX, &tMissileParams.nTargetY))
    {
        return 0;
    }

    if (!tMissileParams.nTargetX || !tMissileParams.nTargetY)
    {
        return 0;
    }

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nValue);
    return 1;
}

// 0x004E3910
int __fastcall SKILLDESC_CltDoMissileIfCollision(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    if (!SKILLS_IsTargetPosClear(pUnit, nMissile))
    {
        return 0;
    }

    return sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel) != 0;
}

// 0x004E3A30
int __fastcall SKILLDESC_CltDoFirstMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return AUTOMAP_RequestAtTarget(pUnit, nMissile, nSkillId, nSkillLevel) != 0;
}

// 0x004E3D70
int __fastcall SKILLDESC_OwnerMissileEvent(int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pMissileUnit, int nUnused, int nSkillId, int nSkillLevel)
{
    if (nEvent)
    {
        return 0;
    }

    if (!pUnit || !pMissileUnit)
    {
        return 0;
    }

    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissileUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (!CUNIT_IsHostileTo(pUnit, pOwner))
    {
        return 0;
    }

    if (!(VIEW_GetMissilesTxtRecord(pMissileUnit->dwClassId)->nMissileFlags[1] & gnBitMasks_006CE268[1]))
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SCMD_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nSkill = nSkillId;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nTargetX = CLIENTS_GetUnitX(pOwner);
    tMissileParams.nTargetY = CLIENTS_GetUnitY(pOwner);
    MISSILE_CreateClientMissile(&tMissileParams);

    const short nOverlay = pSkillsTxtRecord->wCltOverlayA;
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    }

    return 1;
}

struct D2StatListStrc;

struct D2UnitStrc;

// 0x004E3EB0
int __fastcall SKILLDESC_CltDoScatterMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nFrequency = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nFrequency <= 0)
    {
        return 0;
    }

    const int nSpread = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel);
    if (nSpread <= 0)
    {
        return 0;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[2], nSkillId, nSkillLevel);
    if (nRange <= 0)
    {
        return 0;
    }

    const int nCounter = SKILLS_GetParam1(pSkill);
    SKILLS_SetParam1(pSkill, nCounter + 1);
    if (!(nCounter % nFrequency))
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        if (!pSeed)
        {
            return 0;
        }

        int nX = SEED_RollLimitedRandomNumber(pSeed, 2 * nSpread + 1) - nSpread;
        nX += CLIENTS_GetUnitX(pUnit);
        int nY = SEED_RollLimitedRandomNumber(pSeed, 2 * nSpread + 1) - nSpread;
        nY += CLIENTS_GetUnitY(pUnit);
        MISSILE_SubmitOffsetRequest(pUnit, nMissile, 0, 0, nX, nY, nSkillId, nSkillLevel, SEED_RollLimitedRandomNumber(pSeed, nRange));
    }

    return 1;
}

// 0x004E4030
void __cdecl SKILLDESC_Nothing()
{
}

// 0x004E4100
extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax)
{
    unsigned int width = (unsigned int)nMax - (unsigned int)nMin + 1u;
    return SKILLDESC_RollPlayerSeed((int)width) + nMin;
}

// 0x004E4120
extern "C" int __fastcall SKILLDESC_RandomSpread(int nRange)
{
    const unsigned int uRange = (unsigned int)nRange;
    const unsigned int uWidth = 2u * uRange + 1u;
    const unsigned int uRoll = (unsigned int)SKILLDESC_RollPlayerSeed((int)uWidth);
    return (int)(uRoll - uRange);
}

// 0x004E4640
D2MonTypeTxt* __fastcall SKILLDESC_GetMonTypeTxtRecord(int nMonType)
{
    if (nMonType >= 0 && nMonType < sgptDataTables->nMonPropTxtRecordCount)
        return &sgptDataTables->pMonTypeTxt[nMonType];
    return sgptDataTables->pMonTypeTxt;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int sub_I05_ETypeColor(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 1;
    case 2:
        return 9;
    case 3:
    case 4:
        return 3;
    case 5:
        return 2;
    }
    return 0;
}

static void __stdcall SKILLDESC_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    int nMin;
    int nMax;
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        *pType = 2;
        nMin = nLength * SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }

    if (pType)
    {
        const int nColor = sub_I05_ETypeColor(pSkillsTxt->nEType);
        if (nColor)
        {
            *pType = nColor;
        }
    }

    *pMin += nMin;
    *pMax += nMax;
}

static int SKILLDESC_GetETypeColor(int nEType)
{
    switch (nEType)
    {
    case 1:
        return 1;
    case 2:
        return 9;
    case 3:
    case 4:
        return 3;
    case 5:
        return 2;
    }
    return 0;
}

static int __stdcall SKILLDESC_GetWeaponDamage(int* pMinDamage, int* pMaxDamage, int* pColor, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem, int bStatBonus, D2UnitStrc* pUnit, int nBonus)
{
    if (!pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!pItem)
        pItem = INVENTORY_GetLeftHandWeapon(pInventory);

    int nMin;
    int nMax;
    if (pItem)
    {
        DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (bStatBonus)
        {
            nMin = D2Common_11248(pUnit, pItem, 0x15);
            nMax = D2Common_11248(pUnit, pItem, 0x16);
        }
        else if (INVENTORY_GetWieldType(pUnit, pInventory) != 2)
        {
            nMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
        }
        else
        {
            nMin = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
            nMax = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
        }
    }
    else
    {
        nMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0) + 1;
        nMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0) + 2;
    }

    if (!nSrcDam)
        nSrcDam = pSkillsTxt->nSrcDam;

    if (nSrcDam != 128)
    {
        nMin = nMin * nSrcDam / 128;
        nMax = nMax * nSrcDam / 128;
    }

    if (nSrcDam)
    {
        if (nMin < 1)
            nMin = 1;
        *pMinDamage += nMin;
        if (nMax < 2)
            nMax = 2;
        *pMaxDamage += nMax;
    }

    nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DAMAGEPERCENT, 0);
    nBonus += SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 1);
    int nMinPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MINDAMAGE_PERCENT, 0);
    int nMaxPercent = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_MAXDAMAGE_PERCENT, 0);
    if (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        int nProgressive = SKILLDESC_SumProgressiveBonus();
        if (nProgressive)
        {
            nBonus += nProgressive;
            *pColor = 3;
        }
    }

    int nDamage = 0;
    if (pItem)
    {
        int nFactor = ITEMS_GetStrengthBonus(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0) * nFactor / 100;
        nFactor = ITEMS_GetDexBonus(pItem);
        if (nFactor)
            nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_DEXTERITY, 0) * nFactor / 100;
        nDamage = STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_NORMALDAMAGE, 0);
    }
    else
    {
        nBonus += STATLIST_UnitGetStatValue(pUnit, STAT_STRENGTH, 0);
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
        *pColor = 3;
    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
        *pColor = 1;

    if (nBonus <= -90)
        nBonus = -90;

    *pMinDamage = (nMinPercent + nBonus + 100) * *pMinDamage / 100 + nDamage + nAdd;
    *pMaxDamage = (nMaxPercent + nBonus + 100) * *pMaxDamage / 100 + nDamage + nAdd;
    return 1;
}

static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, D2UnitStrc* pItem, int* pColor, D2SkillStrc* pSkill, int nRatio)
{
    if (!nRatio)
        return;

    int nMin = 0;
    int nMax = 0;
    SKILLDESC_GetWeaponDamage(&nMin, &nMax, pColor, 0, pSkill, 128, pItem, 0, pUnit, 0);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, pColor, pSkill);
    *pMinDamage += nMin * nRatio / 128;
    *pMaxDamage += nMax * nRatio / 128;
}

static void SKILLDESC_AddElementalStatDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, unsigned char nType)
{
    switch (nType)
    {
    case 1:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_FIREMAXDAM, 0);
        break;
    case 2:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_LIGHTMAXDAM, 0);
        break;
    case 4:
    case 12:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_COLDMAXDAM, 0);
        break;
    case 3:
        *pMinDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMINDAM, 0);
        *pMaxDamage += STATLIST_UnitGetStatValue(pUnit, STAT_MAGICMAXDAM, 0);
        break;
    case 5:
    {
        int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (nCount <= 1)
                nCount = 1;
            nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
        }
        int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
        *pMinDamage += nMin * nLength >> 8;
        *pMaxDamage += nMax * nLength >> 8;
        break;
    }
    }
}

static void __stdcall SKILLDESC_DrawDamageRange(int nColor, int nY, int nMin, int nMax, int nLeft, int nRight)
{
    if (nMin >= nMax)
    {
        nMax = nMin + 1;
    }

    Unicode wszText[32];
    char szText[32];
    if (nMin == nMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nMin);
    }
    else if (nMin < 10000 && nMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", "", (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", "", nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText, szText, 32);
    int nWidth = 0;
    int nHeight = 0;
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    nWidth = nWidth * 11 / 7;
    if (nWidth > nRight - nLeft)
    {
        D2Win_10127_SetFont(6);
        --nY;
    }
    else
    {
        D2Win_10127_SetFont(1);
    }
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnPanelOffsetY + gnScreenHeight + nY - 480, gnPanelOffsetX + nRight, wszText, nColor);
}

void __fastcall SKILLDESC_DrawPhysWeaponElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    int nMin = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, 0, &nColor, pSkill, nSrcDam);
    if (pSkillsTxt->nEType == 5)
    {
        const int nLength = SKILLS_GetElementalLength(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1);
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004F47B0
int __fastcall SKILLDESC_CltDoTargetedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nTargetX = nX;
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.pTarget = pTarget;
    tMissileParams.nTargetY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    if (!pTarget)
    {
        tMissileParams.dwFlags = 0x420;
    }

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
    {
        if (pTarget)
        {
            MISSILE_SetTargetX(pMissile, 1);
        }
        else
        {
            MISSILE_SetTargetX(pMissile, 2);
        }

        const short nOffsetX = nX - CLIENTS_GetUnitX(pUnit);
        const short nOffsetY = nY - CLIENTS_GetUnitY(pUnit);
        MISSILE_SetTargetY(pMissile, (nOffsetY << 16) + nOffsetX);
    }

    return 1;
}

// 0x004F48F0
int __fastcall SKILLDESC_CltDoMirrorMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nMirrorX = 2 * nTargetX - CLIENTS_GetUnitX(pUnit);
    const int nMirrorY = 2 * nTargetY - CLIENTS_GetUnitY(pUnit);
    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nTargetX = nMirrorX;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nX = nTargetX;
    tMissileParams.nY = nTargetY;
    tMissileParams.dwFlags = 0x21;
    tMissileParams.nTargetY = nMirrorY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pInitFunc = SKILLDESC_InitCappedChargedPath;
    for (int i = 0; i < nCount; i += 1)
    {
        tMissileParams.nInitArg = i;
        MISSILE_CreateClientMissile(&tMissileParams);
    }

    return 1;
}

// 0x004F2340
int __fastcall SKILLDESC_CltDoMissileRows(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    const int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    const int nRows = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_ScatterRequestsAroundTarget(pUnit, nMissile, nCount, nRows, nSkillId, nSkillLevel);
    return 1;
}

// 0x004F25A0
int __fastcall SKILLDESC_CltDoRepeatMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags &= ~0x40;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nParam = SKILLS_GetParam1(pSkill);
    if (nParam <= 0)
    {
        D2MissileStrc tMissileParams;
        memset(&tMissileParams, 0, sizeof(tMissileParams));
        tMissileParams.dwFlags = 0x20;
        tMissileParams.pOwner = pUnit;
        tMissileParams.pOrigin = pUnit;
        tMissileParams.nMissile = nMissile;
        tMissileParams.nSkill = nSkillId;
        tMissileParams.nSkillLevel = nSkillLevel;
        tMissileParams.nTargetX = nX;
        tMissileParams.nTargetY = nY;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            GFXUTIL_SetMotionVectorA(pMissile, 0, 0, 15);
        }

        SKILLS_SetParam1(pSkill, nCount);
    }
    else
    {
        SKILLS_SetParam1(pSkill, nParam - 1);
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->nSeqInput - 1);
        pUnit->dwFrameCountPrecise = 0x800;
    }

    return 1;
}

// 0x004F2720
int __fastcall SKILLDESC_CltDoTargetMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!CUNIT_GetPathTargetUnit(pUnit))
    {
        return 0;
    }

    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    return 1;
}

// 0x004F2E90
int __fastcall SKILLDESC_CltDoUnitEffect(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SKILLS_StartUnitEffect(pUnit, pTarget, nMissile, -1, nSkillId, nSkillLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(nMissile, nSkillLevel));
    return 1;
}

// 0x004F33B0
int __fastcall SKILLDESC_CltDoPositionMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    return 1;
}


// 0x004F0160
int __fastcall SKILLDESC_CltDoSoundMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const short nSound = pSkillsTxtRecord->wPrgSound;
    if (nSound > 0)
    {
        sub_004B9A00(nSound, 0, 0, 0, 0);
    }

    sub_004C5470_CreateMissileToTarget(pUnit, MISSILE_BAAL_TAUNT_CONTROL, nSkillId, nSkillLevel);
    return 1;
}

// 0x004F01F0
int __fastcall SKILLDESC_CltDoDirectionMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nDirX = 0;
    int nDirY = 0;
    MONSTERS_GetChainDirectionDelta(pUnit, &nDirX, &nDirY);
    if (!nDirX && !nDirY)
    {
        return 0;
    }

    D2UnitStrc* pMissile = sub_004C5470_CreateMissileToTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    int nRange = pMissilesTxtRecord->wRange;
    if (nRange < 1)
    {
        nRange = 1;
    }

    const int nSpeed = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    int nStartX = -(nRange * nDirX);
    int nStartY = -(nRange * nDirY);
    DUNGEON_GameSubtileToClientCoords(&nStartX, &nStartY);
    int nStepX = nDirX;
    int nStepY = nDirY;
    DUNGEON_GameSubtileToClientCoords(&nStepX, &nStepY);
    GFXUTIL_SetMotionVectorA(pMissile, nStartX, nStartY, nSpeed * nRange);
    GFXUTIL_SetMotionVectorB(pMissile, nStepX, nStepY, -nSpeed, 1);
    GFXUTIL_UpdateMotion(pMissile);
    return 1;
}

// 0x004F11D0
int __fastcall SKILLDESC_CltDoMissileLine(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    int nStepX = nX - CLIENTS_GetUnitX(pUnit);
    int nStepY = nY - CLIENTS_GetUnitY(pUnit);
    SKILLS_ScaleUpDirection(&nStepX, &nStepY);
    sub_004C53D0_ScaleDownDirection(&nStepX, &nStepY);
    nX += -(nStepX * nCount / 2);
    nY += -(nStepY * nCount / 2);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x20;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nRange = nRange;
    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetY = nY;
        tMissileParams.nTargetX = nX;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            sub_004E3170_SetMissileFrames(pMissile, MISSILE_GetTotalFrames(pMissile));
        }

        nX += nStepX;
        nY += nStepY;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        UNITS_SetAnimationFrame(pUnit, 8);
        pUnit->dwFrameCountPrecise = 0x600;
    }

    return 1;
}

// 0x004F1370
int __fastcall SKILLDESC_CltDoFirstMissileTurned(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    D2UnitStrc* pMissile = AUTOMAP_RequestAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    const int nOffsetX = nX - CLIENTS_GetUnitX(pUnit);
    const int nOffsetY = nY - CLIENTS_GetUnitY(pUnit);
    MISSILE_SetTargetX(pMissile, -nOffsetY);
    MISSILE_SetTargetY(pMissile, nOffsetX);
    return 1;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004F3680
static int __stdcall SKILLDESC_SpawnMissileTowardTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId)
{
    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
        return 0;

    const int nDeltaX = nTargetX - UNITS_GetUnitXPosition(pUnit);
    const int nDeltaY = nTargetY - UNITS_GetUnitYPosition(pUnit);
    int nDistance = UNITS_GetDistanceToCoordinates(pUnit, nTargetX, nTargetY);
    if (nDistance <= 1)
        nDistance = 1;

    const int nX = UNITS_GetUnitXPosition(pUnit) + 2 * nDeltaX / nDistance;
    const int nY = UNITS_GetUnitYPosition(pUnit) + 2 * nDeltaY / nDistance;

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nTargetX = 5 * nDeltaX;
    missileParams.nTargetY = 5 * nDeltaY;

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&missileParams);
    if (!pMissile)
        return 0;

    D2COMMON_10160_PathUpdateDirection(pMissile->pDynamicPath, UNITS_GetDirectionToCoords(pUnit, nTargetX, nTargetY));
    return 1;
}

// 0x004F3810
int __fastcall SKILLDESC_CltStartMissileC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        D2SkillsTxt* pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
        if (pSkillsTxt)
        {
            const int nMissileId = pSkillsTxt->wCltMissileC;
            if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
                return SKILLDESC_SpawnMissileTowardTarget(pUnit, nSkillId, nSkillLevel, nMissileId);
        }
    }

    return 0;
}

// 0x004F1850
int __fastcall SKILLDESC_CltDoMissileFanA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    return SKILLDESC_CreateMissileVolley(pUnit, nCount, nMissile, nSkillId, nSkillLevel, 0x200, 1, 0);
}

// 0x004F18F0
int __fastcall SKILLDESC_CltDoMissileFanB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    return SKILLDESC_CreateMissileVolley(pUnit, nCount, nMissile, nSkillId, nSkillLevel, 0x100, 0, 1);
}

// 0x004F1990
int __fastcall SKILLDESC_CltDoMissileFanC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    return SKILLDESC_CreateMissileVolley(pUnit, nCount, nMissile, nSkillId, nSkillLevel, 0x200, 0, 1);
}

// 0x004F38D0
int __fastcall SKILLDESC_CltDoParamMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissile = SKILLDESC_GetCltMissileId(pUnit, nSkillId);
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2001;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nX = SKILLS_GetParam1(pSkill);
    tMissileParams.nY = SKILLS_GetParam2(pSkill);
    MISSILE_CreateClientMissile(&tMissileParams);
    SKILLS_SetParam1(pSkill, 0);
    SKILLS_SetParam2(pSkill, 0);
    return 1;
}

// 0x004F39A0
int __fastcall SKILLDESC_CltStartSetTargetParams(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pUnit == CUNIT_GetPlayerUnit() && !D2COMMON_11021(pTarget))
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, UNITS_GetUnitXPosition(pTarget));
    SKILLS_SetParam2(pSkill, UNITS_GetUnitYPosition(pTarget));
    SKILLS_SetParam3(pSkill, !pTarget ? -1 : pTarget->dwClassId);
    return 1;
}

// 0x004F4110
int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[5];
}

#pragma pack(push, 1)
struct d2data_0072D8D8_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
    const void* p15;
    const void* p16;
    const void* p17;
    const void* p18;
    const void* p19;
    const void* p20;
    const void* p21;
    const void* p22;
    const void* p23;
    const void* p24;
    const void* p25;
    const void* p26;
    const void* p27;
    const void* p28;
    const void* p29;
    const void* p30;
    const void* p31;
    const void* p32;
    const void* p33;
    const void* p34;
    const void* p35;
    const void* p36;
    const void* p37;
    const void* p38;
    const void* p39;
    const void* p40;
    const void* p41;
    const void* p42;
    const void* p43;
    const void* p44;
};
#pragma pack(pop)

extern "C" struct d2data_0072D8D8_t gData_0072D8D8; // 0x0072D8D8

extern const int gaSetMaskToBonusMappingTable[0x40] = {
    0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
    2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6
}; // 0x006DBD90

extern int gnTextOffset2 = 2; // 0x0072D8D0

extern int gnTextOffset1 = -6; // 0x0072D8D4

extern "C" struct d2data_0072D8D8_t gData_0072D8D8 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14",
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14",
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x0072D8D8
