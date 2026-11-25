#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
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

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

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

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70

void __fastcall CUNIT_MarkUnitDead(D2UnitStrc* pUnit); // 0x00464810

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

D2UnitStrc* __fastcall MISSILE_SubmitOffsetRequest(D2UnitStrc* pUnit, int nArg0, int nOffsetX, int nOffsetY, int nTargetX, int nTargetY, int nArg3, int nArg4, int nRange); // 0x004CDC30

int __stdcall D2COMMON_11039_CheckWeaponIsMissileBased(D2UnitStrc* pUnit, int* pValue); // 0x00645F00

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __fastcall SKILLDESC_ToggleStateOffCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x004E3050

void __fastcall sub_004E3170_SetMissileFrames(D2UnitStrc* pMissile, int nDivisor); // 0x004E3170

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x00465C60

void __fastcall sub_004C53D0_ScaleDownDirection(int* pX, int* pY); // 0x004C53D0

int __fastcall SKILLS_ScanFindUnit(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, int nArg, int* pOut); // 0x004C5EB0

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

int __fastcall SKILLS_ScatterRequestsAroundTarget(D2UnitStrc* pMissile, int nMissile, int nCount, int nRange, int nSkill, int nSkillLevel); // 0x004C7700

int __fastcall SKILLS_IsTargetPosClear(D2UnitStrc* pUnit, int nMissile); // 0x004C7B20

int __stdcall GFXUTIL_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nSeedOffset); // 0x004E2ED0

int __fastcall SKILLDESC_CreateMissileVolley(D2UnitStrc* pUnit, int nCount, int nMissile, int nSkillId, int nSkillLevel, int nArg6, int nArg7, int nArg8); // 0x004F16F0

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

extern D2DrlgActStrc* gpAct; // 0x007A0634

typedef char check_scalar_width[(sizeof(unsigned int) == 4 && sizeof(int) == 4) ? 1 : -1];

extern "C" int __fastcall sub_004E40A0(int nRange); // 0x004E40A0

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

int __cdecl sub_004DF870(); // 0x004DF870

int __cdecl UNITMODE_GetPlayerLevelId(); // 0x00481780

D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920

void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

void __fastcall SOUNDINST_RefreshHintsInRangeA(int nGroupA, int nGroupB); // 0x004BA950

void __fastcall SOUNDINST_RefreshHintsInRangeB(int nGroupA, int nGroupB); // 0x004BA9D0

void __fastcall SOUNDINST_SetValue(int nKey, int nValue); // 0x004B9B50

int __fastcall sub_004B9B20(int nHandle); // 0x004B9B20

void __fastcall sub_004BA840(int nHandle); // 0x004BA840

extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100

struct D2MonTypeTxt
{
    int unk0x00[3];
};

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

extern const int gaSetMaskToBonusMappingTable[0x40]; // 0x006DBD90


void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall ITEMMODS_AssignProperty(int nPass, int nArg1, D2UnitStrc* pItem, int nArg, int nArg2, int nArg5); // 0x0065FEC0

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId); // 0x00656F90

typedef char chkSkillsTxt_M125[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char chkSkillDescTxt_M125[sizeof(D2SkillDescTxt) == 0x120 ? 1 : -1];

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

const wchar_t* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

wchar_t* __fastcall sub_00526700(wchar_t* pDest, const wchar_t* pSource); // 0x00526700

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

extern int gnTextOffset1; // 0x0072D8D4

extern int gnTextOffset2; // 0x0072D8D0

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern int gnGlobal_0072D844; // 0x0072D844

extern int gnGlobal_0072D88C; // 0x0072D88C

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall SKILLDESC_DrawSkillPanel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nSlot); // 0x004ED570

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

extern "C" const char szFmtD_006D57BC[];                                                                    // 0x006D57BC

extern "C" const char gszFmtRange[];                                                                // 0x006D9D70

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight);             // 0x00502520

void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                        // 0x004A89D0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);              // 0x00643CE0

int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery);            // 0x00644D50

int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery);            // 0x00644E40

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20

int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0

int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId);                          // 0x00626070

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340

int __cdecl SKILLDESC_SumProgressiveBonus();                                                             // 0x004E6FF0

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem);                                          // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem);                                         // 0x006298A0

int __stdcall STATES_CheckStateMaskDamBlueOnUnit(D2UnitStrc* pUnit);                                        // 0x0063A380

int __stdcall STATES_CheckStateMaskDamRedOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A3A0

int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0

char gbTextOffsetInit; // 0x007C8C9C

char gbSkillRefreshInit; // 0x007C8CA4

void __fastcall SKILLDESC_MissileScatter(D2UnitStrc* pUnit, int nSeed, int nMissile, int nX, int nY, int nCount, int nSkillId, int nSkillLevel); // 0x004F28A0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

void __fastcall SKILLDESC_DrawWeaponPhysElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight); // 0x004EAD60

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static int __stdcall SKILLDESC_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId); // 0x004E4C50


// 0x004E1FF0
int __fastcall SKILLDESC_CltDoMissileWall(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    const int nMissile = pSkillsTxt->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nDX = nTargetX - nX;
    int nDY = nTargetY - nY;
    if (!nDX && !nDY)
    {
        return 0;
    }

    int nStepX = 0;
    int nStepY = 0;

    if (nDX < 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = -2;
    }
    else if (nDX == 0 && nDY < 0)
    {
        nStepX = 2;
    }
    else if (nDX > 0 && nDY < 0)
    {
        nStepX = 2;
        nStepY = 2;
    }
    else if (nDX > 0 && nDY == 0)
    {
        nStepY = 2;
    }
    else if (nDX > 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = 2;
    }
    else if (nDX == 0 && nDY > 0)
    {
        nStepX = -2;
    }
    else if (nDX < 0 && nDY > 0)
    {
        nStepX = -2;
        nStepY = -2;
    }
    else if (nDX < 0 && nDY == 0)
    {
        nStepY = -2;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    nDX -= nCount / 2 * nStepX;
    nDY -= nCount / 2 * nStepY;

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 3;
    for (int i = 0; i < nCount; ++i)
    {
        tMissile.pOwner = pUnit;
        tMissile.nX = nX + nDX / 6;
        tMissile.nTargetX = nDX;
        tMissile.nTargetY = nDY;
        tMissile.nY = nY + nDY / 6;
        tMissile.nSkillLevel = nSkillLevel;
        tMissile.nMissile = nMissile;
        MISSILE_CreateClientMissile(&tMissile);
        nDX += nStepX;
        nDY += nStepY;
    }

    return 1;
}

// 0x004E2630
int __fastcall SKILLDESC_CltDoFrameSteps(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    const int nRepeats = SKILLS_GetParam1(pSkill);

    switch (pUnit->nSeqCurrentFramePrecise >> 8)
    {
    case SKILLDO_FRAME_A:
        UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_A_SET);
        pUnit->dwFrameCountPrecise = SKILLDO_FRAME_A_COUNT;
        break;

    case SKILLDO_FRAME_B:
        if (nRepeats >= SKILLDO_REPEATS)
        {
            UNITS_SetAnimationFrame(pUnit, SKILLDO_FRAME_B_SET);
            pUnit->dwFrameCountPrecise = SKILLDO_FRAME_B_COUNT;
        }
        else
        {
            SKILLS_SetParam1(pSkill, nRepeats + 1);
        }
        break;

    case SKILLDO_FRAME_C:
        UNITMODE_SetUnitMode(pUnit, SKILLDO_FRAME_C_STATE);
        CUNIT_MarkUnitDead(pUnit);
        break;
    }

    return 1;
}

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

    if (sub_0046ACE0(nMissile))
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
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
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
    if (nMissile < sgptDataTables->nMissilesTxtRecordCount && sub_0046ACE0(nMissile))
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
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
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
            sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
            return 1;
        }

        return 0;
    }

    const int nCltMissile = pSkillsTxtRecord->wCltMissileA;
    if (nCltMissile < 0 || nCltMissile >= sgptDataTables->nMissilesTxtRecordCount || !sub_0046ACE0(nCltMissile))
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[0] & gnBitMasks_006CE268[1])
    {
        MISSILE_SubmitOffsetRequest(pUnit, nCltMissile, 0, 0, 0, 0, nSkillId, nSkillLevel, 0);
    }
    else
    {
        sub_004C5420_CreateFirstMissile(pUnit, nCltMissile, nSkillId, nSkillLevel);
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

    return sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel) != 0;
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

    if (!(sub_0046ACE0(pMissileUnit->dwClassId)->nMissileFlags[1] & gnBitMasks_006CE268[1]))
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
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
void __cdecl sub_004E4030_Nothing()
{
}

// 0x004E4100
extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax)
{
    unsigned int width = (unsigned int)nMax - (unsigned int)nMin + 1u;
    return sub_004E40A0((int)width) + nMin;
}

// 0x004E4120
extern "C" int __fastcall SKILLDESC_RandomSpread(int nRange)
{
    const unsigned int uRange = (unsigned int)nRange;
    const unsigned int uWidth = 2u * uRange + 1u;
    const unsigned int uRoll = (unsigned int)sub_004E40A0((int)uWidth);
    return (int)(uRoll - uRange);
}

// 0x004E41E0
int __cdecl SKILLDESC_IsOutsideDayCycle()
{
    const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct);
    return nCycle < 1 || nCycle > 3;
}

// 0x004E4220
void __cdecl SKILLDESC_ClearEnvironSoundRefs()
{
    for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
    {
        sub_00482370(nId);
    }
}

// 0x004E4240
static void SKILLDESC_AddEnvironSoundRefs(int nIndex)
{
    int nId = nIndex * 4 + 0xA9C;
    for (int i = 3; i; --i)
    {
        sub_004822B0(nId, 1);
        sub_004822B0(nId + 0x18, 1);
        nId += 0x30;
    }
}

static inline float GetEnvironVolume_Inline()
{
    return sub_00473C40() ? sub_00473C80() : 0.0f;
}

void __fastcall GFXUTIL_ApplySoundEnviron(int nEnvironId); // 0x004DF6C0

void __fastcall SKILLDESC_UpdateEnvironSounds(unsigned int dwTick)
{
    if (!sub_004DF870())
        return;
    const int nLevelId = UNITMODE_GetPlayerLevelId();
    if (!nLevelId)
        return;
    int nSound = 0;
    int nAmbient = 0;
    int nVolume = 0;
    const int bNight = 2 < (unsigned int)(ENVIRONMENT_GetCycleIndexFromAct(gpAct) - 1);
    const int nEnviron = sub_004817A0_GetPlayerSoundEnviron();
    D2SoundEnvironTxtStrc* pEnv = SOUNDHDR_GetSoundEnvironTxtRecord(nEnviron);
    if (pEnv)
    {
        if (bNight)
        {
            nAmbient = pEnv->nNightEvent;
            nSound = pEnv->nNightAmbience;
        }
        else
        {
            nAmbient = pEnv->nDayEvent;
            nSound = pEnv->nDayAmbience;
        }
    }
    int nSecond = sub_00473C40() ? 0x40 : 0;
    if (GetEnvironVolume_Inline() != 0.0f)
    {
        const float fVolume = GetEnvironVolume_Inline();
        nVolume = (int)(fVolume * 255.0);
    }
    if (nSound != gnEnvironSoundId)
    {
        int bCross = 0;
        if (nSound == pEnv->nDayAmbience && gnEnvironSoundId == pEnv->nNightAmbience)
            bCross = 1;
        if (nSound == pEnv->nNightAmbience && gnEnvironSoundId == pEnv->nDayAmbience)
            bCross = 1;
        if (bCross)
        {
            SOUNDINST_ArmHint(gnEnvironSoundHandle, 0, 0, 0xFA);
        }
        else
        {
            SOUNDINST_RefreshHintsInRangeA(nSound, nSecond);
            SOUNDINST_RefreshHintsInRangeB(nAmbient, 0);
        }
        if (nSound != gnEnvironSoundId)
        {
            if (nSound)
            {
                gnEnvironSoundHandle = sub_004B9A00(nSound, 0, 0, 0, 0);
                if (bCross)
                {
                    SOUNDINST_SetValue(gnEnvironSoundHandle, 0);
                    SOUNDINST_ArmHint(gnEnvironSoundHandle, 0xFF, 0, 0xFA);
                }
                gnEnvironSoundId = nSound;
            }
            else
            {
                gnEnvironSoundHandle = 0;
                gnEnvironSoundId = 0;
            }
        }
    }
    if (nSecond)
    {
        if (nVolume && !gnWeatherSoundHandle)
        {
            gnWeatherSoundHandle = sub_004B9A00(gnWeatherSoundId, 0, 0, 0, 0);
            if (gnWeatherSoundHandle)
                SOUNDINST_SetValue(gnWeatherSoundHandle, nVolume);
        }
        if (gnWeatherSoundHandle)
        {
            const int nCurrent = sub_004B9B20(gnWeatherSoundHandle);
            int nNext;
            if (nVolume > nCurrent)
            {
                nNext = nCurrent + 6;
                if (nVolume < nNext)
                    nNext = nVolume;
            }
            else
            {
                nNext = nCurrent - 6;
                if (nVolume > nNext)
                    nNext = nVolume;
            }
            if (nNext)
            {
                SOUNDINST_SetValue(gnWeatherSoundHandle, nNext);
            }
            else
            {
                sub_004BA840(gnWeatherSoundHandle);
                gnWeatherSoundHandle = 0;
            }
        }
        gnWeatherSoundId = nSecond;
    }
    else
    {
        sub_004BA840(gnWeatherSoundHandle);
        gnWeatherSoundHandle = 0;
        gnWeatherSoundId = 0;
    }
    GFXUTIL_ApplySoundEnviron(nEnviron);
    if (nAmbient)
    {
        if (nAmbient != gnEnvironAmbientId)
        {
            gnAmbientDelay = sub_004E4120(pEnv->nEventDelay / 3) + pEnv->nEventDelay;
            gnAmbientTick = dwTick - sub_004E40A0(gnAmbientDelay);
            gnEnvironAmbientId = nAmbient;
        }
        if (dwTick - gnAmbientTick >= gnAmbientDelay)
        {
            const int nHandle = sub_004B9A00(nAmbient, 0, 0, 0, 0);
            if (nHandle)
            {
                const int nSign = sub_004E40A0(2) ? 1 : -1;
                const int nPan = SKILLDESC_RandomInRange(0x1C2, 0x2EE) * nSign;
                const int nPanVolume = sub_004E4120(0x64);
// build: symbol ?SOUNDINST_MoveSound@* 0x004B99A0
                SOUNDINST_MoveSound(nHandle, nPan, nPanVolume, 0);
                gnAmbientTick = dwTick;
                gnAmbientDelay = sub_004E4120(pEnv->nEventDelay / 3) + pEnv->nEventDelay;
            }
        }
    }
    if (nLevelId != gnEnvironLevelId)
    {
        const int nEntryA = pEnv->nMaterial1;
        const int nEntryB = pEnv->nMaterial2;
        for (int nId = 0xAA0; nId < 0xB3D; nId += 4)
            sub_00482370(nId);
        if (nEntryA)
            SKILLDESC_AddEnvironSoundRefs(nEntryA);
        if (nEntryB)
            SKILLDESC_AddEnvironSoundRefs(nEntryB);
        gnEnvironLevelId = nLevelId;
    }
}

// 0x004E4640
D2MonTypeTxt* __fastcall SKILLDESC_GetMonTypeTxtRecord(int nMonType)
{
    if (nMonType >= 0 && nMonType < sgptDataTables->nMonPropTxtRecordCount)
        return &sgptDataTables->pMonTypeTxt[nMonType];
    return sgptDataTables->pMonTypeTxt;
}

// 0x004E6C50
int __fastcall SKILLDESC_ValidateMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }
    return -1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004E6C70
int __fastcall SKILLDESC_GetSkillParamFive(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4];
}

// 0x004E6CA0
int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
}

static D2SkillsTxt* sub_H14_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static D2SkillDescTxt* sub_H14_GetSkillDescTxtRecord(int nSkillDesc)
{
    if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        return &sgptDataTables->pSkillDescTxt[nSkillDesc];
    return 0;
}

// 0x004E6D40
static unsigned short SKILLDESC_GetSkillDescStrName(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrName;
}

// 0x004E6D90
static unsigned short SKILLDESC_GetSkillDescStrShort(int nSkillId)
{
    D2SkillDescTxt* pSkillDescTxt = 0;
    D2SkillsTxt* pSkillsTxt = sub_H14_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
        pSkillDescTxt = sub_H14_GetSkillDescTxtRecord(pSkillsTxt->wSkillDesc);
    if (!pSkillDescTxt)
        return 0x1506;
    return pSkillDescTxt->wStrShort;
}

unsigned short __stdcall sub_M125_Emit_004E6D40(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return SKILLDESC_GetSkillDescStrName(nSkillId);
}

unsigned short __stdcall sub_M125_Emit_004E6D90(int nUnused1, int nUnused2, int nUnused3, int nSkillId)
{
    return SKILLDESC_GetSkillDescStrShort(nSkillId);
}

// 0x004E6E80
static int SKILLDESC_ApplyAiCurseDivisor(int nValue)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(GAME_GetDifficulty());
    const int nDivisor = pDifficultyLevelsTxt->dwAiCurseDivisor;
    if (nDivisor > 0)
        nValue /= nDivisor;
    return nValue;
}

// 0x004E6FF0
int __cdecl SKILLDESC_SumProgressiveBonus()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
    {
        return 0;
    }

    int nSum = 0;
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (!STATES_CheckState(pPlayer, sgptDataTables->pProgressiveStates[i]))
        {
            continue;
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, sgptDataTables->pProgressiveStates[i]);
        if (!pStatList)
        {
            continue;
        }

        const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
        {
            continue;
        }

        D2SkillsTxt* pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
        if (!pSkillsTxtRecord)
        {
            continue;
        }

        const int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
        if (nSkillLevel <= 0 || pSkillsTxtRecord->nPrgDamage != 1)
        {
            continue;
        }

        if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            continue;
        }

        const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        if (nValue > 0)
        {
            nSum += SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel) * nValue;
        }
    }

    return nSum;
}

int __stdcall sub_M125_Emit_004E6E80(int nUnused1, int nUnused2, int nUnused3, int nValue)
{
    return SKILLDESC_ApplyAiCurseDivisor(nValue);
}

// 0x004E7900
static int SKILLDESC_AppendStringLine(wchar_t* wszOut, unsigned short wStr)
{
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

void __stdcall sub_M24_Emit_004E7900(wchar_t* wszOut, unsigned short wStr, int nOther)
{
    if (nOther)
        SKILLDESC_AppendStringLine(wszOut, wStr);
}

// 0x004E9160
static int __stdcall SKILLDESC_GetAttackRateValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == ITEMTYPE_MISSILE_POTION)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = 0;
    if (STATES_CheckState(pUnit, STATE_THROWINGMASTERY))
        nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);

    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_TOHIT_PERCENT, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    *pValue1 += *pValue1 * nBonus / 100;

    *pValue2 = 0;
    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
}

// 0x004E9590
void __fastcall SKILLDESC_DescAttackRate(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    *pValue1 = 0;
    *pValue2 = 0;
    SKILLDESC_GetAttackRateValues(pUnit, 0, pValue1, pValue2, nLevel, pSkill);
}

// 0x004E9870
void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2)
{
    D2Win_10127_SetFont(6);
    if (!gbTextOffsetInit)
    {
        if (STRTABLE_GetLanguage() >= 6 && STRTABLE_GetLanguage() <= 9)
        {
            gnTextOffset1 = -7;
        }
        else
        {
            gnTextOffset1 = -6;
        }

        gbTextOffsetInit = 1;
    }

    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + gnTextOffset1 + nY - 480, gnPanelOffsetX + nRight, wszText1, nColor1);
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnTextOffset2 + gnScreenHeight + gnPanelOffsetY + nY - 480, gnPanelOffsetX + nRight, wszText2, nColor2);
}

static D2SkillsTxt* sub_I05_GetSkillsTxtRecord(int nSkillId)
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

// build: symbol ?SKILLDESC_GetElemDamage@* 0x004E72D0
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

// build: symbol ?SKILLDESC_GetETypeColor@* 0x004E6FB0
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

static int __stdcall sub_004E86F0_GetWeaponDamage(int* pMinDamage, int* pMaxDamage, int* pColor, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem, int bStatBonus, D2UnitStrc* pUnit, int nBonus)
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

// build: symbol ?SKILLDESC_AddScaledWeaponDamage@* 0x004E9660
static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, D2UnitStrc* pItem, int* pColor, D2SkillStrc* pSkill, int nRatio)
{
    if (!nRatio)
        return;

    int nMin = 0;
    int nMax = 0;
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, pColor, 0, pSkill, 128, pItem, 0, pUnit, 0);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, pColor, pSkill);
    *pMinDamage += nMin * nRatio / 128;
    *pMaxDamage += nMax * nRatio / 128;
}

// build: symbol ?SKILLDESC_AddElementalStatDamage@* 0x004E8D90
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

// build: symbol ?SKILLDESC_DrawDamageRange@* 0x004E96E0
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
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
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

void __fastcall SKILLDESC_DrawWeaponAndSkillDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nWeaponMin = 0;
    int nWeaponMax = 0;
    int nWeaponColor = 0;
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nWeaponMin, &nWeaponMax, 0, &nWeaponColor, pSkill, pSkillsTxt->nSrcDam);
    const int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    int nMin = SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    SKILLDESC_AddElementalStatDamage(pUnit, &nMin, &nMax, pSkillsTxt->nEType);

    if (!nWeaponMin && !nWeaponMax)
    {
        SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nWeaponColor, nY, nWeaponMin, nWeaponMax, nLeft, nRight);
        return;
    }

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
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
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

void __fastcall SKILLDESC_DrawSkillWeaponLine(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(pSkillsTxt->nSkillId);
    if (!pSkillDescTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
// build: symbol ?gszSkillDescFile@* 0x006DBF24
    const int nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98C), nSkillLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98D), nSkillLevel);
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, nAdd, pSkill, 0x80, 0, 0, pUnit, nBonus);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    if (pSkillsTxt->nSrcDam != 0x80)
    {
        const int nSrcDam = pSkillsTxt->nSrcDam;
        nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
        nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    }

    nMin += SKILLS_GetMinPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMax += SKILLS_GetMaxPhysDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// build: symbol ?SKILLDESC_DrawPhysWeaponElemDamage@* 0x004EAE70
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

void __fastcall SKILLDESC_DrawWeaponAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nWeaponMin = 0;
    int nWeaponMax = 0;
    int nWeaponColor = 0;
    sub_004E86F0_GetWeaponDamage(&nWeaponMin, &nWeaponMax, &nWeaponColor, 0, pSkill, 0x80, 0, 0, pUnit, 0);
    sub_004E89A0_GetElementalDamage(pUnit, &nWeaponMin, &nWeaponMax, &nWeaponColor, pSkill);

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nColor, pSkillsTxt, nSkillLevel);

    if (!nWeaponMin && !nWeaponMax)
    {
        SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nWeaponColor, nY, nWeaponMin, nWeaponMax, nLeft, nRight);
        return;
    }

    Unicode wszText1[32];
    char szText[32];
    if (nWeaponMin == nWeaponMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nWeaponMin);
    }
    else if (nWeaponMin < 10000 && nWeaponMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nWeaponMin, nWeaponMax);
    }
    else if (nWeaponMin >= 10000)
    {
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
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
        wsprintfA(szText, "%s%dK-%dK", &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, "%s%d-%dK", &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

void __fastcall SKILLDESC_DrawMasteryWeaponDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill)
    {
        return;
    }

    if (!pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = SKILLDESC_GetETypeColor(pSkillsTxt->nEType);
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nMin, &nMax, 0, &nColor, pSkill, pSkillsTxt->nSrcDam);

    int nWeaponMin;
    int nWeaponMax;
    if (D2Common_10434(pUnit, 1) && INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2)
    {
        nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
        nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MAXDAMAGE, 0);
    }
    else
    {
        nWeaponMin = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
        nWeaponMax = STATLIST_UnitGetStatValue(pUnit, STAT_MAXDAMAGE, 0);
    }

    nWeaponMin = nWeaponMin > 1 ? nWeaponMin : 1;
    nWeaponMax = nWeaponMax > 2 ? nWeaponMax : 2;
    if (nWeaponMax < nWeaponMin)
    {
        nWeaponMax = nWeaponMin;
    }

    const int nSkillId = pSkillsTxt->nSkillId;
    int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[1], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_COLD_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwCalc[2], nSkillId, nSkillLevel);
    if (nPercent)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nMastery)
        {
            nPercent += DATATBLS_ApplyRatio(nPercent, nMastery, 100);
        }
    }
    nMin += DATATBLS_ApplyRatio(nWeaponMin, nPercent, 100);
    nMax += DATATBLS_ApplyRatio(nWeaponMax, nPercent, 100);

    if (!nColor)
    {
        nColor = 3;
    }
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EB940
void __fastcall SKILLDESC_DrawWeaponDamageWithParam(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, 0, pSkill, 0, 0, 0, pUnit, 0);
    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0xD40);
    D2SkillsTxt* pRecord = sub_I05_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pRecord ? 0 : pRecord->dwParam[4];
    nMin += nParam * nMin / 100;
    nMax += nParam * nMax / 100;
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

// 0x004EDA20
void __fastcall SKILLDESC_RefreshSkills(D2UnitStrc* pUnit)
{
    if (!gbSkillRefreshInit)
    {
        if (STRTABLE_GetLanguage() >= 6 && STRTABLE_GetLanguage() <= 9)
        {
            gnGlobal_0072D844 -= 1;
            gnGlobal_0072D88C -= 1;
        }

        gbSkillRefreshInit = 1;
    }

    if (pUnit)
    {
        D2SkillStrc* pSkill = UNITS_GetLeftSkill(pUnit);
        SKILLDESC_DrawSkillPanel(pUnit, pSkill, 0);
        pSkill = UNITS_GetRightSkill(pUnit);
        SKILLDESC_DrawSkillPanel(pUnit, pSkill, 6);
    }
}

// 0x004EFC20
int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[1];
}

// 0x004EFC50
int __fastcall SKILLDESC_GetSkillParamThree(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[2];
}

// 0x004EFC80
int __fastcall SKILLDESC_GetSkillParamFour(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

// 0x004EFCB0
int __fastcall SKILLDESC_GetSummonLevel(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5];
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

// 0x004F29F0
int __fastcall SKILLDESC_CltDoMissileScatterAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nCount = sub_004F2260_GetSkillCount(pUnit, nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    int nX;
    int nY;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        nX = CLIENTS_GetUnitX(pTarget);
        nY = CLIENTS_GetUnitY(pTarget);
    }
    else if (!ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    SKILLDESC_MissileScatter(pUnit, nX, nMissile, nX, nY, nCount, nSkillId, nSkillLevel);
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


// 0x004EFCF0
int __fastcall SKILLDESC_CltDoTurnedMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 2;
    tMissileParams.nMissile = nMissile;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nTargetX = nX - CLIENTS_GetUnitX(pUnit);
    tMissileParams.nTargetY = nY - CLIENTS_GetUnitY(pUnit);
    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -tMissileParams.nTargetY);
    MISSILE_SetTargetY(pMissile, tMissileParams.nTargetX);
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
    sub_0063EE10_GetMonsterDirectionDelta(pUnit, &nDirX, &nDirY);
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
    sub_004C5390_ScaleUpDirection(&nStepX, &nStepY);
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

    D2UnitStrc* pMissile = sub_004C5420_CreateFirstMissile(pUnit, nMissile, nSkillId, nSkillLevel);
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

    if (pUnit == sub_00463DD0_GetPlayerUnit() && !D2COMMON_11021(pTarget))
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

#include "gen/data/Source/D2Client/UI/SkillDesc_004E1FF0.inc"
