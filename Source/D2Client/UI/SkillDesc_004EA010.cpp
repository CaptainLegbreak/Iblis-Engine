#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2Unicode.h"
#include "D2GameTypes.h"

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SkillsTxt;

struct D2SkillDescTxt;

struct Unicode;

struct D2ElemDamageStatsStrc;

struct D2MonStatsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC

extern "C" const char gszFmtRange[]; // 0x006D9D70

extern "C" const char gszFmtRangeKK[]; // 0x006DBEAC

extern "C" const char gszFmtRangeK[]; // 0x006DBEB8

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870

D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId); // 0x004A89D0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644D50

int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644E40

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId); // 0x00626070

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __cdecl SKILLDESC_SumProgressiveBonus(); // 0x004E6FF0

short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860

short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

int __stdcall STATES_CheckStateMaskDamBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A380

int __stdcall STATES_CheckStateMaskDamRedOnUnit(D2UnitStrc* pUnit); // 0x0063A3A0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

extern const D2ElemDamageStatsStrc gaElemDamageStats[4]; // 0x006DBEF4

int __stdcall ITEMS_GetMissileType(D2UnitStrc*); // 0x006288A0

int __stdcall ITEMSIsA(D2UnitStrc*,int); // 0x00629BB0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80

int __stdcall MISSILE_GetMinDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064AF20

int __stdcall MISSILE_GetMaxDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064AFF0

unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int); // 0x0064B0C0

int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064B100

int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc*,D2UnitStrc*,int,int); // 0x0064B1D0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc*); // 0x0063BEF0

void __fastcall SKILLDESC_ThrowDamageCallback(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem);

union D2SeedStrc;

struct D2MissilesTxt;

struct D2MissileStrc;

extern "C" const char gszFormatD[]; // 0x006D57BC

int __fastcall SKILLDESC_AddSkillLine(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nArg3, int nArg4, int nLine, int nArg5); // 0x004EDEA0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc*,int,int); // 0x006439B0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*,D2SkillStrc*,int); // 0x006442A0

int __fastcall SPELLSEL_GetSkillMaxLevel(int); // 0x004AA8B0

void __fastcall sub_004521C0_SetTextColor(Unicode*,int); // 0x004521C0

int __stdcall SKILLDESC_HasClassSkill(D2UnitStrc*); // 0x004ED480

Unicode* __fastcall INV_PrefixColorCode(Unicode*, int); // 0x004521C0

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

void* __cdecl sub_00681EF0_Memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern const int gaLobVelocityBonus[5]; // 0x006DBF38

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

void __fastcall CUNIT_SetPathTargetToTargetUnit(D2UnitStrc* pUnit, int nArg); // 0x00465BF0

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

int __stdcall GFXUTIL_GetMotionAZ(D2UnitStrc* pUnit); // 0x004DA150

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200

void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* pUnit); // 0x004DA350

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x004F21B0

static int __stdcall SKILLDESC_AddSeconds(unsigned short nString, int bPlus, int nFrames, Unicode* wszText); // 0x004EDB30

int __stdcall SKILLDESC_AddElemRange(int nElemType, unsigned short nString, int nMax, int nMin, Unicode* wszText); // 0x004EC140

int __stdcall SKILLDESC_AddSkillElemRateByType(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, D2UnitStrc* pUnit, int nSkillLevel); // 0x004EC740

int __stdcall SKILLDESC_AddSummonDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, D2SkillsTxt* pSkillsTxt); // 0x004ECCF0

static int __stdcall SKILLDESC_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId, D2UnitStrc* pUnit); // 0x004EDC40

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
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
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

int __stdcall SKILLDESC_AddProgressiveDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor)
{
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
            if (pStatList)
            {
                int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
                    if (pSkillsTxt)
                    {
                        int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
                        if (nSkillLevel > 0)
                        {
                            short nStatId = pSkillsTxt->wAuraStat[0];
                            if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
                            {
                                int nCharges = STATLIST_GetStatValue(pStatList, nStatId, 0);
                                if (nCharges > 0)
                                {
                                    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
                                    if (!pSkillDescTxt)
                                    {
                                        *pMinDamage += SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
                                        *pMaxDamage += SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
                                    }
                                    else
                                    {
                                        const int nIndex = D2_MIN(D2_MAX(nCharges, 1), 3);

                                        *pMinDamage += SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMin[nIndex - 1], nSkillId, nSkillLevel);
                                        *pMaxDamage += SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwProgDmgMax[nIndex - 1], nSkillId, nSkillLevel);
                                        const unsigned char* pElem = pSkillDescTxt->nPrgDamElem;
                                        if (pElem[nIndex - 1] > 0 && pElem[nIndex - 1] < 13)
                                            *pColor = SKILLDESC_GetETypeColor(pElem[nIndex - 1]);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 1;
}

static inline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

static inline void AddPoisonDamage_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
{
    int nMin = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMINDAM, 0);
    int nMax = STATLIST_UnitGetStatValue(pUnit, STAT_POISONMAXDAM, 0);
    if (nMax)
    {
        int nMastery = STATLIST_UnitGetStatValue(pUnit, STAT_PASSIVE_POIS_MASTERY, 0);
        if (nMastery)
        {
            nMin += ApplyRatio_Inline(nMin, nMastery, 100);
            nMax += ApplyRatio_Inline(nMax, nMastery, 100);
        }

        int nLength = STATLIST_UnitGetStatValue(pUnit, STAT_SKILL_POISON_OVERRIDE_LENGTH, 0);
        if (nLength <= 0)
        {
            int nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            if (nCount <= 1)
            {
                nCount = 1;
            }
            nLength = STATLIST_UnitGetStatValue(pUnit, STAT_POISONLENGTH, 0) / nCount;
        }

        nMax = nLength * nMax >> 8;
        nMin = nLength * nMin >> 8;
        *pColor = 2;
        *pMinDamage += nMin;
        *pMaxDamage += nMax;
    }
    else
    {
    }
}

static inline void AddPoisonDamageAndClamp_Inline(D2UnitStrc* pUnit, int* pMaxDamage, int* pMinDamage, int* pColor)
{
    AddPoisonDamage_Inline(pUnit, pMaxDamage, pMinDamage, pColor);

    if (*pMaxDamage > 0)
    {
        *pMinDamage = *pMinDamage < 1 ? 1 : *pMinDamage;
        *pMaxDamage = D2_MAX(*pMinDamage + 1, *pMaxDamage);
    }
}

int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill)
{
    for (int i = 0; i < 4; ++i)
    {
        int nMin = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMinStat, 0);
        int nMax = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMaxStat, 0);
        if (gaElemDamageStats[i].nMasteryStat != -1)
        {
            int nMastery = STATLIST_UnitGetStatValue(pUnit, gaElemDamageStats[i].nMasteryStat, 0);
            if (nMastery)
            {
                nMin += ApplyRatio_Inline(nMin, nMastery, 100);
                nMax += ApplyRatio_Inline(nMax, nMastery, 100);
            }
        }

        if (nMin >= nMax)
        {
            nMin = nMax;
        }

        *pMinDamage += nMin;
        *pMaxDamage += nMax;
        if (nMin || nMax)
        {
// build: symbol ?gaElemDamageColors@* 0x006DBEE4
            *pColor = gaElemDamageColors[i];
        }
    }

    AddPoisonDamageAndClamp_Inline(pUnit, pMaxDamage, pMinDamage, pColor);

    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7]))
        {
            SKILLDESC_AddProgressiveDamage(pUnit, pMinDamage, pMaxDamage, pColor);
        }
    }

    if (STATES_CheckStateMaskDamBlueOnUnit(pUnit))
    {
        *pColor = 3;
    }

    if (STATES_CheckStateMaskDamRedOnUnit(pUnit))
    {
        *pColor = 1;
    }

    return 1;
}

// 0x004EA010
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
    const int nLevel = nSkillLevel;
    int& nBonus = nSkillLevel;
// build: symbol ?gszSkillDescFile@* 0x006DBF24
    nBonus = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[0], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98C), nLevel);
    const int nAdd = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDamCalc[1], SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDescFile, 0x98D), nLevel);
    sub_004E86F0_GetWeaponDamage(&nMin, &nMax, &nColor, nAdd, pSkill, 0x80, 0, 0, pUnit, nBonus);
    sub_004E89A0_GetElementalDamage(pUnit, &nMin, &nMax, &nColor, pSkill);
    D2SkillsTxt* const pTxt = pSkillsTxt;
    if (pTxt->nSrcDam != 0x80)
    {
        int& nSrcDam = *(int*)&pSkillsTxt;
        nSrcDam = pTxt->nSrcDam;
        nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 0x80);
        nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 0x80);
    }

    nMin += SKILLS_GetMinPhysDamage(pUnit, pTxt->nSkillId, nLevel, 0) >> 8;
    nMax += SKILLS_GetMaxPhysDamage(pUnit, pTxt->nSkillId, nLevel, 0) >> 8;
    nMin += SKILLS_GetMinElemDamage(pUnit, pTxt->nSkillId, nLevel, 1) >> 8;
    nMax += SKILLS_GetMaxElemDamage(pUnit, pTxt->nSkillId, nLevel, 1) >> 8;
    SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
}

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x004EA4A0
void __fastcall SKILLDESC_ThrowDamageCallback(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pColor, int nBonus, int nAdd, D2SkillStrc* pSkill, int nSrcDam, D2UnitStrc* pItem)
{
    *pMin=0;
    *pMax=0;
    if (!pSkill) return;
    if (!pItem) {
        if (!pUnit->pInventory) return;
        pItem=INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
        if (!pItem) return;
    }
    if (!ITEMS_CheckIfThrowable(pItem)) return;
    if (ITEMSIsA(pItem,38)) {
        int nMissile=ITEMS_GetMissileType(pItem);
        *pColor=0;
        int nMin=MISSILE_GetMinDamage(0,pUnit,nMissile,1);
        nMin+=MISSILE_GetMinElemDamage(0,pUnit,nMissile,1);
        int nMax=MISSILE_GetMaxDamage(0,pUnit,nMissile,1);
        nMax+=MISSILE_GetMaxElemDamage(0,pUnit,nMissile,1);
        switch (MISSILE_GetElemTypeFromMissileId(nMissile)) {
        case 5: {
            *pColor=2;
// build: symbol ?MISSILE_GetElementalLength@* 0x0064B2A0
            int nLength=MISSILE_GetElementalLength(0,pUnit,nMissile,1)/25;
            if(nLength<=0)nLength=1;
            nMin/=nLength;
            nMax/=nLength;
            break;
        }
        case 4: *pColor=3; break;
        case 1: *pColor=1; break;
        case 2: *pColor=4; break;
        }
        nMin>>=8;
        nMax>>=8;
        if(nMax<=nMin)nMax=nMin;
        *pMin=nMin;
        *pMax=nMax;
        return;
    }
    int nStatBonus=0;
    int nFactor=ITEMS_GetStrengthBonus(pItem);
    if(nFactor)nStatBonus=STATLIST_UnitGetStatValue(pUnit,STAT_STRENGTH,0)*nFactor/100;
    nFactor=ITEMS_GetDexBonus(pItem);
    if(nFactor)nStatBonus+=STATLIST_UnitGetStatValue(pUnit,STAT_DEXTERITY,0)*nFactor/100;
    *pMin=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_THROW_MINDAMAGE,0);
    *pMax=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_THROW_MAXDAMAGE,0);
    nStatBonus+=STATLIST_UnitGetStatValue(pUnit,STAT_DAMAGEPERCENT,0);
    int nMinPercent=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_MINDAMAGE_PERCENT,0);
    int nMaxPercent=STATLIST_UnitGetStatValue(pUnit,STAT_ITEM_MAXDAMAGE_PERCENT,0);
    if(nStatBonus<=-90)nStatBonus=-90;
    *pMin+=*pMin*(nMinPercent+nStatBonus)/100;
    *pMax+=*pMax*(nMaxPercent+nStatBonus)/100;
    int nSkillBonus=nBonus;
    if(STATES_CheckState(pUnit,STATE_THROWINGMASTERY))nSkillBonus+=SKILLS_GetWeaponMasteryBonus(pUnit,pItem,pSkill,1);
    *pMin+=DATATBLS_ApplyRatio(*pMin,nSkillBonus,100);
    *pMax+=DATATBLS_ApplyRatio(*pMax,nSkillBonus,100);
    if(*pMax<*pMin)*pMax=*pMin;
    {
        int nElemMin=0;
        int nElemMax=0;
        sub_004E89A0(pUnit,&nElemMin,&nElemMax,pColor,pSkill);
        if(nElemMax<nElemMin)nElemMax=nElemMin;
        *pMin+=nElemMin;
        *pMax+=nElemMax;
    }
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
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) * nLength >> 8;
    }
    else
    {
        nMin = SKILLS_GetMinElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
        nMax = SKILLS_GetMaxElemDamage(pUnit, pSkillsTxt->nSkillId, nSkillLevel, 1) >> 8;
    }

    if (pType)
    {
        switch (pSkillsTxt->nEType)
        {
        case 1:
            *pType = 1;
            break;
        case 2:
            *pType = 9;
            break;
        case 3:
        case 4:
            *pType = 3;
            break;
        case 5:
            *pType = 2;
            break;
        }
    }

    *pMin += nMin;
    *pMax += nMax;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004EAAA0
void __fastcall SKILLDESC_DrawThrowAndElemDamage(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nLeft, int nY, int nRight)
{
    if (!pSkill || !pSkillsTxt)
    {
        return;
    }

    const int nSrcDam = pSkillsTxt->nSrcDam;
    int nElemMin;
    int nElemMax;
    int nElemColor;
    int nMin = 0;
    int nMax = 0;
    int nColor = 0;
    SKILLDESC_ThrowDamageCallback(pUnit, &nMin, &nMax, &nColor, 0, 0, pSkill, 0, 0);
    nMin = DATATBLS_ApplyRatio(nMin, nSrcDam, 128);
    nMax = DATATBLS_ApplyRatio(nMax, nSrcDam, 128);

    nElemMin = 0;
    nElemMax = 0;
    nElemColor = 0;
    SKILLDESC_GetElemDamage(pUnit, &nElemMin, &nElemMax, &nElemColor, pSkillsTxt, nSkillLevel);

    if (!nMin && !nMax)
    {
        SKILLDESC_DrawDamageRange(nElemColor, nY, nElemMin, nElemMax, nLeft, nRight);
        return;
    }

    if (!nElemMin && !nElemMax)
    {
        SKILLDESC_DrawDamageRange(nColor, nY, nMin, nMax, nLeft, nRight);
        return;
    }

    Unicode wszText1[32];
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
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText1, szText, 32);

    Unicode wszText2[32];
    if (nElemMin == nElemMax)
    {
        wsprintfA(szText, szFmtD_006D57BC, nElemMin);
    }
    else if (nElemMin < 10000 && nElemMax < 10000)
    {
        wsprintfA(szText, gszFmtRange, nElemMin, nElemMax);
    }
    else if (nElemMin >= 10000)
    {
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nElemMin + 500) / 1000, (nElemMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nElemMin, (nElemMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nColor, nElemColor);
}

static __forceinline int ApplyPercent_2E0(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}


static inline int ApplyPercent_150(int nValue, int nPercent)
{
    if (nValue > 0x100000)
    {
        if (100 > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nPercent * (nValue / 100);
    }

    if (nPercent > 0x10000)
    {
        if (100 > (nPercent >> 4))
        {
            return (int)(nValue * (__int64)nPercent / 100);
        }
        return nValue * (nPercent / 100);
    }

    return nPercent * nValue / 100;
}

static inline int IsSingleValue(int nMin, int nMax)
{
    if (!nMin)
    {
        return !nMax;
    }
    return nMin == nMax;
}

static inline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static unsigned short sub_004E6F60_GetElemDamageText(int nElemType)
{
    switch (nElemType)
    {
    case 1:
        return 0x10A1;
    case 2:
        return 0x10A3;
    case 4:
        return 0x10A2;
    case 3:
        return 0x10C3;
    case 5:
        return 0x10A4;
    case 6:
        return 0xDC4;
    }
    return 0;
}

static void __stdcall sub_004E6EA0_ApplyFireMastery(int* pMin, int* pMax, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 1)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nMastery)
        {
            const int nMin = *pMin;
            *pMin = DATATBLS_ApplyRatio(nMin, nMastery, 100) + nMin;
            const int nMax = *pMax;
            *pMax = DATATBLS_ApplyRatio(nMax, nMastery, 100) + nMax;
        }
    }
}

static void __stdcall sub_004E6F00_ApplyLightningMastery(int* pMin, int* pMax, D2SkillsTxt* pSkillsTxt)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 2)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nMastery)
        {
            const int nMin = *pMin;
            *pMin = DATATBLS_ApplyRatio(nMin, nMastery, 100) + nMin;
            const int nMax = *pMax;
            *pMax = DATATBLS_ApplyRatio(nMax, nMastery, 100) + nMax;
        }
    }
}


static int __stdcall sub_004E73E0_FormatValue(Unicode* pDest, int bPlus, int nValue)
{
    char szText[32];
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szText, "+%d", nValue);
    }
    else
    {
        wsprintfA(szText, szFmtD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

static int __stdcall sub_004E7430_FormatDecimal(Unicode* pDest, int bPlus, int nWhole, int nFraction)
{
    char szText[32];
    if (bPlus && nWhole >= 0)
    {
        wsprintfA(szText, "+%d.%d", nWhole, nFraction);
    }
    else
    {
        wsprintfA(szText, "%d.%d", nWhole, nFraction);
    }
    sub_00526320_ToUnicode(pDest, szText, 32);
    return 1;
}

// build: symbol ?SKILLDESC_AppendLabelValue@* 0x004E79E0
static int __stdcall SKILLDESC_AppendLabelValue(unsigned short nString, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, "+%d", nValue);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E7C30_AddValueTextAfter(unsigned short nString, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, "+%d", nValue);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E7E70_AddValueTwoTexts(unsigned short nString1, unsigned short nString2, int bPlus, int nValue, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nValue)
    {
        return 0;
    }

    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, "+%d", nValue);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString1));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004E80F0_AddRangeText(Unicode* wszText, int bSeparator, int nMin, int nMax, unsigned short nString, int bPlus)
{
    if (nMin == nMax)
    {
        return SKILLDESC_AppendLabelValue(nString, bPlus, nMin, wszText);
    }

    Unicode wszNumber[32];
    char szNumber[32];
    if (bPlus)
    {
        wsprintfA(szNumber, "+%d-%d", nMin, nMax);
    }
    else
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    if (bSeparator)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    }
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004EC090
static void __stdcall SKILLDESC_AddSummonLife(Unicode* wszText, int nPercent, int nBonus, int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxt = &sgptDataTables->pMonStatsTxt[nMonsterId];
    if (!pMonStatsTxt)
    {
        return;
    }

    const int nDifficulty = GAME_GetDifficulty();
    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    if (!DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxt->nLevel[nDifficulty], 1, &monStatsInit))
    {
        return;
    }

    int nLife = (monStatsInit.nMinHP + monStatsInit.nMaxHP) / 2;
    nLife += nLife * nPercent / 100 + nBonus;
    if (nLife)
    {
        SKILLDESC_AppendLabelValue(0x10C6, 0, nLife, wszText);
    }
}

// build: symbol ?SKILLDESC_AddSkillElemDamage@* 0x004EC220
static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(pSkillsTxt->nEType, nString, nMax >> 8, nMin >> 8, wszText);
}

// build: symbol ?SKILLDESC_AddMissileElemDamage@* 0x004EC280
static int __stdcall SKILLDESC_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel)
{
    const int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    const int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(MISSILE_GetElemTypeFromMissileId(nMissileId), nString, nMax, nMin, wszText);
}

// 0x004EC2E0
static int __stdcall SKILLDESC_AddPhysDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nBonus, int nPercent, int nSkillLevel)
{
    Unicode wszNumber[32];
    char szNumber[32];
    int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    nMin += ApplyPercent_2E0(nMin, nPercent) + nBonus;
    nMax += ApplyPercent_2E0(nMax, nPercent) + nBonus;
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin != nMax)
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    else if (nMin >= 0)
    {
        wsprintfA(szNumber, "+%d", nMin);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10A0));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC510
static int SKILLDESC_AddToHit(int nSkillLevel, int nSkillId, D2UnitStrc* pUnit, Unicode* wszText)
{
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (!nToHit)
    {
        return 0;
    }

    return sub_004E7E70_AddValueTwoTexts(0x10A6, 0x10B3, 1, nToHit, wszText);
}

// 0x004EC540
static int __stdcall SKILLDESC_AddElemRatePerSecond(unsigned short nString, int nMin, int nMax, Unicode* wszText)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin == nMax)
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nMin);
    }
    else
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10E2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10BE));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AddMissileElemRate@* 0x004EC620
static int __stdcall SKILLDESC_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel)
{
    int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    sub_004E6EA0_ApplyFireMastery(&nMin, &nMax, pSkillsTxt);
    sub_004E6F00_ApplyLightningMastery(&nMin, &nMax, pSkillsTxt);
    const int nMinRate = nMin >> 8;
    const int nMaxRate = nMax >> 8;
    unsigned short nString;
    switch (MISSILE_GetElemTypeFromMissileId(nMissileId))
    {
    case 2:
        nString = 0x10A3;
        break;
    case 4:
        nString = 0x10A2;
        break;
    case 3:
        nString = 0x10C3;
        break;
    case 5:
        nString = 0x10A4;
        break;
    case 6:
        nString = 0xDC4;
        break;
    case 1:
    default:
        nString = 0x10A1;
        break;
    }

    return SKILLDESC_AddElemRatePerSecond(nString, nMinRate, nMaxRate, wszText);
}

// build: symbol ?SKILLDESC_AddSkillElemRate@* 0x004EC6F0
static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    return SKILLDESC_AddElemRatePerSecond(0x10A1, nMin, nMax, wszText);
}

// 0x004EC7E0
static int __stdcall SKILLDESC_AddValueLine(unsigned short nStringAfter, int bPlus, int bPercent, int nValue, unsigned short nStringBefore, Unicode* wszText)
{
    if (!nValue)
    {
        return 0;
    }

    Unicode wszNumber[32];
    char szNumber[32];
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, "+%d", nValue);
    }
    else
    {
        wsprintfA(szNumber, szFmtD_006D57BC, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    if (nStringBefore != 0x1506)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    }
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC900
static int __stdcall SKILLDESC_AddDecimalLine(unsigned short nStringAfter, int bPlus, int bPercent, int nWhole, int nFraction, unsigned short nStringBefore, Unicode* wszText)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nWhole && !nFraction)
    {
        return 0;
    }

    Unicode wszNumber[32];
    sub_004E7430_FormatDecimal(wszNumber, bPlus, nWhole, nFraction);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004ECA00
static int __stdcall SKILLDESC_AddValueOverTime(unsigned short nStringAfter, int nValue, int bPlus, int nCount, unsigned short nStringBefore, Unicode* wszText)
{
    if (nStringBefore != 0x1506 && nValue && nCount > 0)
    {
    char szNumber[32];
    Unicode wszNumber[32];
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_004E73E0_FormatValue(wszNumber, bPlus, nValue);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
    wsprintfA(szNumber, szFmtD_006D57BC, nCount);
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
    }

    return 0;
}

// 0x004ECB10
static int SKILLDESC_AddTextPair(unsigned short nString1, unsigned short nString2, Unicode* wszText)
{
    if (nString1 != 0x1506 && nString2 != 0x1506)
    {
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString1));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
    }

    return 0;
}

// 0x004ECB80
static int __stdcall SKILLDESC_AddValueAfterText(unsigned short nStringAfter, int bPlus, int bPercent, int nValue, unsigned short nStringBefore, Unicode* wszText)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nValue)
    {
        return 0;
    }

    Unicode wszNumber[32];
    sub_004E73E0_FormatValue(wszNumber, bPlus, nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringAfter));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszText, wszNumber);
    if (bPercent)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA1));
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004ECC80
static int __stdcall SKILLDESC_AddFormattedText(int nValue, unsigned short nString, Unicode* wszText)
{
    if (nString == 0x1506)
    {
        return 0;
    }

    Unicode wszLine[0x100];
    sub_005269D0(0x100, wszLine, D2LANG_GetStringFromTblIndex(nString), nValue);
    sub_00526700(wszText, wszLine);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

int __stdcall SKILLDESC_AddMonsterDamage(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nBonusMin, int nBonusMax)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    const int nDifficulty = GAME_GetDifficulty();
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    const int nMonsterId = sgptDataTables->nMonStatsTxtRecordCount > 0x124 ? 0x124 : -1;
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxt->nLevel[nDifficulty], 8, &monStatsInit);
    const int nMin = monStatsInit.nA1MinD + nBonusMin;
    const int nMax = monStatsInit.nA1MaxD + nBonusMax;
    Unicode wszNumber[32];
    char szNumber[32];
    const unsigned short nString = sub_004E6F60_GetElemDamageText(pSkillsTxt->nEType);
    if (nString)
    {
        if (IsSingleValue(nMin, nMax))
        {
            wsprintfA(szNumber, szFmtD_006D57BC, nMin);
        }
        else
        {
            wsprintfA(szNumber, gszFmtRange, nMin, nMax);
        }
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

static inline D2SkillsTxt* SkillsTxtRecord_0D0(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline int SkillParam_0D0(int nSkillId, int nLevel)
{
    D2SkillsTxt* pSkillsTxt = SkillsTxtRecord_0D0(nSkillId);
    if (!pSkillsTxt)
    {
        return 0;
    }

    if (nLevel <= 0)
    {
        return 0;
    }
    return pSkillsTxt->dwParam[0] + (nLevel - 1) * pSkillsTxt->dwParam[1];
}

// 0x004ED0D0
static int SKILLDESC_AddNextLevelParam(int nSkillLevel, int nSkillId, Unicode* wszText)
{
    if (nSkillLevel > 1)
    {
        sub_004E7C30_AddValueTextAfter(0x10D5, 0, SkillParam_0D0(nSkillId, nSkillLevel - 1), wszText);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x110D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

// build: symbol ?SKILLDESC_AddSummonDamageBonus@* 0x004ED150
int __stdcall SKILLDESC_AddSummonDamageBonus(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel)
{
    D2MonStatsTxt* pMonStatsTxt = MonStatsTxtRecord(pSkillsTxt->wSummon);
    if (!pMonStatsTxt)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(pSkillsTxt->wSummon, GAME_GetLadderFlag(), GAME_GetDifficulty(), pMonStatsTxt->nLevel[GAME_GetDifficulty()], 8, &monStatsInit);
    int nMin = monStatsInit.nA1MinD;
    int nMax = monStatsInit.nA1MaxD;
    int nPercent = 0;
    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxt->wAuraStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
        if (pSkillsTxt->wAuraStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            nMin += nDamage;
            nMax += nDamage;
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxt->nPassiveStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
        if (pSkillsTxt->nPassiveStat[i] == 0x6F)
        {
            const int nDamage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
            nMin += nDamage;
            nMax += nDamage;
        }
    }

    if (nPercent)
    {
        if (nPercent <= -90)
        {
            nPercent = -90;
        }
        nMin += ApplyPercent_150(nMin, nPercent);
        nMax += ApplyPercent_150(nMax, nPercent);
    }

    SKILLDESC_AddElemRange(0, 0x10A0, nMax, nMin, wszText);
    return 1;
}

// 0x004EDB30
static int __stdcall SKILLDESC_AddSeconds(unsigned short nString, int bPlus, int nFrames, Unicode* wszText)
{
    Unicode wszNumber[32];
    const int nSeconds = nFrames / 25;
    const int nTenths = nFrames % 25 * 10 / 25;
    if (!nSeconds && !nTenths)
    {
        return 0;
    }

    if (nTenths)
    {
        sub_004E7430_FormatDecimal(wszNumber, bPlus, nSeconds, nTenths);
    }
    else
    {
        sub_004E73E0_FormatValue(wszNumber, bPlus, nSeconds);
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nSeconds == 1 && !nTenths ? 0x10AB : 0x10AC));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

static int __stdcall sub_004EDCA0_AddElemDamageOverTime(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * nLength >> 8;
    SKILLDESC_AddSeconds(0x2B0E, 0, nLength, wszText);
    Unicode wszNumber[32];
    char szNumber[32];
    const unsigned short nString = sub_004E6F60_GetElemDamageText(pSkillsTxt->nEType);
    if (nString)
    {
        if (IsSingleValue(nMin, nMax))
        {
            wsprintfA(szNumber, szFmtD_006D57BC, nMin);
        }
        else
        {
            wsprintfA(szNumber, gszFmtRange, nMin, nMax);
        }
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

static int __stdcall sub_004EDDD0_AddAttackInfo(Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel, D2UnitStrc* pUnit)
{
    if (GAME_IsExpansion())
    {
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, 0, 0, nSkillLevel);
        SKILLDESC_AddToHit(nSkillLevel, nSkillId, pUnit, wszText);
        return 1;
    }

    int nMin = 0;
    int nMax = 0;
    int nType;
    SKILLDESC_GetElemDamage(pUnit, &nMin, &nMax, &nType, pSkillsTxt, nSkillLevel);
    sub_004E80F0_AddRangeText(wszText, 0, nMin, nMax, 0x10A0, 0);
    return 1;
}

int __fastcall sub_D06_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nArg4, int nLine, int nArg5)
{
    if (!pSkillsTxt)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
    {
        return 0;
    }

    const int nCalcA = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcA[nLine], nSkillId, nSkillLevel);
    const int nCalcB = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcB[nLine], nSkillId, nSkillLevel);
    const unsigned short nStringA = pSkillDescTxt->wDescTextA[nLine];
    const unsigned short nStringB = pSkillDescTxt->wDescTextB[nLine];
    switch (pSkillDescTxt->nDescLine[nLine])
    {
    case 1:
        SKILLDESC_AddSummonLife(wszText, nCalcA, nCalcB, pSkillsTxt->wSummon);
        return 1;
    case 2:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddElemRange(pSkillsTxt->nEType, nStringA, nCalcB, nCalcA, wszText);
        return 1;
    case 3:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        return 1;
    case 4:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        return 1;
    case 5:
        SKILLDESC_AddMissileElemDamage(pUnit, wszText, nStringA, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        return 1;
    case 6:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, nCalcB, nCalcA, nSkillLevel);
        return 1;
    case 7:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddToHit(nSkillLevel, nSkillId, pUnit, wszText);
        return 1;
    case 8:
        SKILLDESC_AddMissileElemRate(pUnit, wszText, pSkillsTxt, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        return 1;
    case 9:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemRate(pUnit, wszText, nSkillId, nSkillLevel);
        return 1;
    case 10:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSkillElemRateByType(wszText, pSkillsTxt, nSkillId, pUnit, nSkillLevel);
        return 1;
    case 11:
        SKILLDESC_AddValueLine(nStringB, 1, 1, nCalcA, nStringA, wszText);
        return 1;
    case 12:
        SKILLDESC_AddValueLine(nStringB, 1, 0, nCalcA, nStringA, wszText);
        return 1;
    case 13:
        SKILLDESC_AddDecimalLine(nStringB, 1, 0, nCalcA, nCalcB, nStringA, wszText);
        return 1;
    case 14:
        SKILLDESC_AddValueOverTime(nStringB, nCalcA, 1, nCalcB, nStringA, wszText);
        return 1;
    case 15:
        SKILLDESC_AddTextPair(nStringA, nStringB, wszText);
        return 1;
    case 16:
        SKILLDESC_AddValueAfterText(nStringB, 0, 0, nCalcA, nStringA, wszText);
        return 1;
    case 17:
        SKILLDESC_AddFormattedText(nCalcA, nStringA, wszText);
        return 1;
    case 18:
        SKILLDESC_AddSummonDamage(pUnit, wszText, nSkillId, nSkillLevel, pSkillsTxt);
        return 1;
    case 19:
        SKILLDESC_AddMonsterDamage(wszText, pSkillsTxt, nCalcA, nCalcB);
        return 1;
    case 20:
        SKILLDESC_AddNextLevelParam(nSkillLevel, nSkillId, wszText);
        return 1;
    case 21:
        SKILLDESC_AddSummonDamageBonus(pUnit, wszText, nSkillId, pSkillsTxt, nSkillLevel);
        return 1;
    case 22:
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddSeconds(nStringA, 0, nCalcA, wszText);
        return 1;
    case 23:
        SKILLDESC_AddSeconds(nStringA, 1, nCalcA, wszText);
        return 1;
    case 24:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        return 1;
    case 25:
        if (nStringA != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        }
        if (nStringB != 0x1506)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        }
        sub_004EDCA0_AddElemDamageOverTime(pUnit, wszText, pSkillsTxt, nSkillLevel, nSkillId);
        return 1;
    case 26:
        sub_004EDDD0_AddAttackInfo(wszText, nSkillId, pSkillsTxt, nSkillLevel, pUnit);
        return 1;
    case 27:
        sub_004E7E70_AddValueTwoTexts(nStringA, nStringB, 1, nCalcA, wszText);
        return 1;
    case 28:
        SKILLDESC_AppendLabelValue(nStringA, 1, nCalcA, wszText);
        return 1;
    case 29:
        sub_004E7C30_AddValueTextAfter(nStringA, 1, nCalcA, wszText);
        return 1;
    case 30:
        sub_004E80F0_AddRangeText(wszText, 1, nCalcA, nCalcB, nStringA, 1);
        return 1;
    }
    return 0;
}


// 0x004EDC30
static int SKILLDESC_AddSecondsPlus(unsigned short nString, int nFrames, Unicode* wszText)
{
    return SKILLDESC_AddSeconds(nString, 1, nFrames, wszText);
}

int __fastcall sub_M214_Emit_004EDEA0(Unicode* wszText, unsigned short nString, int nFrames)
{
    return SKILLDESC_AddSecondsPlus(nString, nFrames, wszText);
}

static int __stdcall SKILLDESC_AddElemRange(int nMin, unsigned short nString, int nMax, Unicode* wszText, int nElemType)
{
    Unicode wszNumber[32];
    char szNumber[32];
    if (!nString)
    {
        nString = sub_004E6F60_GetElemDamageText(nElemType);
        if (!nString)
        {
            return 0;
        }
    }

    if ((nMin || nMax) && nMin != nMax)
    {
        wsprintfA(szNumber, gszFmtRange, nMin, nMax);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EDC40
static int __stdcall SKILLDESC_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillLevel, int nSkillId, D2UnitStrc* pUnit)
{
    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 0);
    if (nLength)
    {
        unsigned short nString;
        switch (pSkillsTxt->nEType)
        {
        case 5:
            nString = 0x10AA;
            break;
        case 4:
            nString = 0x10A9;
            break;
        default:
            return 0;
        }

        return SKILLDESC_AddSeconds(nString, 0, nLength, wszText);
    }

    return 0;
}


int __fastcall sub_H14_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nLine, int nCalcA, int nCalcB, unsigned short nStringA)
{
    switch (nLine)
    {
    case 1:
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, nSkillLevel, nSkillId, pUnit);
        return 1;
    case 2:
        sub_004EDCA0_AddElemDamageOverTime(pUnit, wszText, pSkillsTxt, nSkillLevel, nSkillId);
        return 1;
    case 3:
        SKILLDESC_AddSeconds(nStringA, 0, nCalcA, wszText);
        return 1;
    case 4:
        SKILLDESC_AddElemRange(nCalcA, nStringA, nCalcB, wszText, pSkillsTxt->nEType);
        return 1;
    }
    return 0;
}

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    D2SkillsTxt* pRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return pRecord;
}

static inline D2SkillDescTxt* CLIENT_GetSkillDescTxtRecord(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}

// 0x004EEF00
void __fastcall SKILLDESC_ShowSkillPopup(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int nHeight;
    int nWidth;
    char szNumber[32];
    if(!pUnit)return;
    D2SkillsTxt* pSkillsTxt=CLIENT_GetSkillsTxtRecord(nSkillId);
    if(!pSkillsTxt)return;
    D2SkillStrc* pBonusSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bGranted;
    if(pBonusSkill){
        if(SKILLS_GetSkillLevel(pUnit,pBonusSkill,1) && !SKILLS_GetSkillLevel(pUnit,pBonusSkill,0))bGranted=1;
        else bGranted=0;
    } else bGranted=0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText,D2LANG_GetStringFromTblIndex(0x109C));
    D2SkillStrc* pSkill=SKILLS_GetSkillById(pUnit,nSkillId,-1);
    int bMaxed;
    if(pSkill && SKILLS_GetSkillLevel(pUnit,pSkill,0)>=SPELLSEL_GetSkillMaxLevel(nSkillId))bMaxed=1;
    else bMaxed=0;
    int bFound=0;
    for(int i=16;i>=10;--i)
        if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bFound=1;
    if(bFound)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    if(!bMaxed)
    {
        int bNext=0;
        for(int i=0;i<6;++i)
            if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bNext=1;
        if(bNext)
        {
            int nPrefixId=0x109D;
            if(!nSkillLevel)nPrefixId=0x10AD;
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(nPrefixId));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    if(nSkillLevel>0)
    {
        int bCurrent=0;
        for(int i=0;i<6;++i)
            if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel,nArg,i,0))bCurrent=1;
        if(bCurrent)
        {
            wsprintfA(szNumber,gszFormatD,nSkillLevel);
            sub_00526320_ToUnicode(wszNumber,szNumber,32);
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x109E));
            sub_00526700(wszText,wszNumber);
            if(bGranted)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1112));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        }
    }
    int bSynergy=0;
    for(int i=6;i<10;++i)
        if(SKILLDESC_AddSkillLine(pUnit,wszText,pSkillsTxt,nSkillId,nSkillLevel+1,nArg,i,0))bSynergy=1;
    if(bSynergy)sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    D2SkillDescTxt* pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrLong));
    sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
    Unicode wszName[1024];
    pSkillDescTxt=CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_005267E0(wszName,D2LANG_GetStringFromTblIndex(!pSkillDescTxt?0x1506:pSkillDescTxt->wStrName));
    sub_004521C0_SetTextColor(wszName,2);
    sub_00526700(wszText,wszName);
    if(bGranted)
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1113));
    }
    if(!SKILLDESC_HasClassSkill(pUnit))
    {
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText,D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText,&nWidth,&nHeight);
    D2Win_10129_DrawFramedText(wszText,nX-24,nHeight+nY+3,0,0);
}

static inline D2SkillsTxt* GetSkillsRecord(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline D2SkillDescTxt* GetSkillDescription(int nSkillId) {
    D2SkillsTxt* pRecord = GetSkillsRecord(nSkillId);
    if (pRecord) {
        int nDesc = pRecord->wSkillDesc;
        if (nDesc >= 0 && nDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return &sgptDataTables->pSkillDescTxt[nDesc];
    }
    return 0;
}

static inline int GetMaximumSkillLevel(int nSkillId) {
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) {
        int nLevel = sgptDataTables->pSkillsTxt[nSkillId].nMaxLevel;
        if (nLevel > 0) return nLevel;
    }
    return 20;
}

// 0x004EF410
void __fastcall SKILLDESC_ShowSkillPopupB(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nArg, int nX, int nY)
{
    int bFound;
    int nHeight;
    int nWidth;
    char szNumber[32];
    if (!pUnit) return;
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt) return;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    D2SkillStrc* pBonusSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    int bBonusOnly;
    if (pBonusSkill) {
        if (SKILLS_GetSkillLevel(pUnit, pBonusSkill, 1) && !SKILLS_GetSkillLevel(pUnit, pBonusSkill, 0))
            bBonusOnly = 1;
        else bBonusOnly = 0;
    } else bBonusOnly = 0;
    Unicode wszText[1024];
    Unicode wszNumber[32];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x109c));
    bFound = 0;
    for (int i = 16; i >= 10; --i) {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel + 1, nArg, i, 1))
            bFound = 1;
    }
    if (bFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    int bCurrentFound = 0;
    for (int i = 0; i < 6; ++i) {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bCurrentFound = 1;
    }
    if (bCurrentFound) {
        if (nSkillLevel <= 0) {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10ad));
        } else {
            wsprintfA(szNumber, gszFormatD, nSkillLevel);
            sub_00526320_ToUnicode(wszNumber, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x109e));
            sub_00526700(wszText, wszNumber);
        }
        if (bBonusOnly) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1112));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    }
    int bRemainingFound = 0;
    for (int i = 6; i < 10; ++i) {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel > 0 ? nSkillLevel : 1, nArg, i, 1))
            bRemainingFound = 1;
    }
    if (bRemainingFound) sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0) >= GetMaximumSkillLevel(nSkillId)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1111));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    } else {
        int nRequired = pSkillsTxt->wReqLevel + nSkillLevel;
        Unicode wszRequired[32];
        if (nRequired) {
            wsprintfA(szNumber, gszFormatD, nRequired);
            sub_00526320_ToUnicode(wszRequired, szNumber, 32);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105b));
            sub_00526700(wszText, wszRequired);
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        }
    }
    D2SkillDescTxt* pDescription = GetSkillDescription(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrLong));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
    Unicode wszName[256];
    pDescription = GetSkillDescription(nSkillId);
    sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(!pDescription ? 0x1506 : pDescription->wStrName));
    INV_PrefixColorCode(wszName, 2);
    sub_00526700(wszText, wszName);
    if (bBonusOnly) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1113));
    }
    if (!SKILLDESC_HasClassSkill(pUnit)) {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xf9e));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x1114));
    }
    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    D2Win_10129_DrawFramedText(wszText, nX, nHeight + nY + 3, 1, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x004EFDF0
int __fastcall SKILLDESC_CltDoLobMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2MissileStrc tMissileParams;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        const int nMissile = pSkillsTxtRecord->wCltMissileA;
        D2MissilesTxt* pMissilesTxtRecord;
        int nMissilesCount;
        if (nMissile >= 0 && nMissile < (nMissilesCount = sgptDataTables->nMissilesTxtRecordCount)
            && (pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile]) != 0)
        {
            int nAltMissile = pSkillsTxtRecord->wCltMissileB;
            if (nAltMissile < 0 || nAltMissile >= nMissilesCount)
            {
                nAltMissile = -1;
            }

            D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
            if (pTarget)
            {
                D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
                CUNIT_SetPathTargetToTargetUnit(pUnit, 1);
            }

            int nTargetX;
            int nTargetY;
            if (ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
            {
                if (!pTarget)
                {
                    UNITS_UpdateDirectionAndSpeed(pUnit, nTargetX, nTargetY);
                }

                sub_00681EF0_Memset(&tMissileParams, 0, sizeof(tMissileParams));
                tMissileParams.dwFlags = 0x25;
                tMissileParams.pOwner = pUnit;
                tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
                tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
                tMissileParams.nSkill = nSkillId;
                tMissileParams.nSkillLevel = nSkillLevel;
                tMissileParams.nTargetX = nTargetX;
                tMissileParams.nTargetY = nTargetY;

                const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel) + GFXUTIL_GetMotionAZ(pUnit);
                const int nFrames = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + pMissilesTxtRecord->dwParam[1];
                int nSpeed = pMissilesTxtRecord->nAnimLen << 8;
                int nFall = -2 * nHeight;
                if (nFrames)
                {
                    nSpeed /= nFrames;
                    nFall /= nFrames;
                }

                D2SeedStrc* pSeed = &pUnit->pSeed;
                tMissileParams.nMissile = nMissile;
                if (nAltMissile > 0 && SEED_RollLimitedRandomNumber(pSeed, 2))
                {
                    tMissileParams.nMissile = nAltMissile;
                }

                tMissileParams.nVelocity = pMissilesTxtRecord->nVel + gaLobVelocityBonus[SEED_RollRandomNumber(pSeed) % 5];

                D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
                if (pMissile)
                {
                    PATH_SetNewDistance(pMissile->pDynamicPath, nFrames);
                    UNITS_SetAnimationSpeed(pMissile, nSpeed);
                    MISSILE_SetTotalFrames(pMissile, nFrames);
                    MISSILE_SetCurrentFrame(pMissile, nFrames);
                    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nHeight);
                    GFXUTIL_UpdateMotion(pMissile);
                    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, nFall, 1);
                }

                return 1;
            }
        }
    }

    return 0;
}

static inline void sub_004F0050_LaunchMotion(D2UnitStrc* pMissile, int nHeight, int nVelocity)
{
    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nHeight);
    GFXUTIL_SetMotionVectorB(pMissile, 0, 0, nVelocity, 1);
    GFXUTIL_UpdateMotion(pMissile);
}

// 0x004F0050
int __fastcall SKILLDESC_CltDoLaunchMissileAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pMissile = sub_004CDD10_CreateMissileAtTarget(pUnit, nMissile, nSkillId, nSkillLevel);
    if (!pMissile)
    {
        return 0;
    }

    const int nFrames = MISSILE_GetTotalFrames(pMissile);
    const int nHeight = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel) + GFXUTIL_GetMotionAZ(pUnit);
    sub_004F0050_LaunchMotion(pMissile, nHeight, nFrames ? -(nHeight / nFrames) : -(nHeight / 2));
    return 1;
}

static inline int GetUnitType(D2UnitStrc* unit)
{
    return !unit ? 6 : unit->dwUnitType;
}

static inline int GetUnitClass(D2UnitStrc* unit)
{
    return !unit ? -1 : unit->dwClassId;
}

// 0x004F0F10
int __fastcall SKILLDESC_IsVineBeastMissile(D2UnitStrc* unit, void* unused)
{
    if (GetUnitType(unit) != 3)
        return 0;
    return GetUnitClass(unit) == 468;
}

#include "gen/data/Source/D2Client/UI/SkillDesc_004EA010.inc"
