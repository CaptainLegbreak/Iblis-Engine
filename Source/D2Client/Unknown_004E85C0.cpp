#include "D2StatIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
struct D2UnitStrc;

typedef wchar_t Unicode;







extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" const char gszFormatD[];                                                                // 0x006D57BC
extern "C" const char gszFmtRange[];                                                                // 0x006D9D70

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource);                                 // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
void __fastcall NPCMENU_ClearUnicode(Unicode* pChar);                                                  // 0x0042F530
void __stdcall sub_00403040_VectorConstructor(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnConstructor)(Unicode*)); // 0x00403040
void __fastcall INV_PrefixColorCode(Unicode* wszText, int nLevel);                                // 0x004521C0
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __cdecl GAME_GetLadderFlag();                                                                     // 0x0044DCA0
int __cdecl GAME_IsExpansion();                                                                                 // 0x0044DCC0
unsigned char __cdecl GAME_GetDifficulty();                                                         // 0x0044DCD0
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                          // 0x0046ACE0
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId);                                        // 0x004A89D0
int __fastcall sub_004A9A90_FindSkill(D2UnitStrc* pUnit, int nSkillId);                                     // 0x004A9A90
int __fastcall sub_004A9AE0_FindSkill(D2UnitStrc* pUnit, int nSkillId);                                     // 0x004A9AE0
int __fastcall sub_004A9B30_FindSkill(D2UnitStrc* pUnit, int nSkillId);                                     // 0x004A9B30
int __fastcall sub_004A9B80_FindSkill(D2UnitStrc* pUnit, int nSkillId);                                     // 0x004A9B80
void __stdcall TEXT_DrawHintText(int nArg1, int nStringIndex); // 0x004ED3F0
int __stdcall SKILLDESC_AddMonsterDamage(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nBonusMin, int nBonusMax); // 0x004ECF50
int __stdcall SKILLDESC_AddSummonDamageBonus(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel); // 0x004ED150
D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery);            // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery);            // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __stdcall SKILLS_EvaluateSkillDescFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646D00
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId);                                   // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0

static inline int ApplyPercent(int nValue, int nPercent)
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

static inline D2MonStatsTxt* MonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
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

static unsigned short SKILLDESC_GetETypeDamageStr(int nEType);
// 0x004E6F60
static unsigned short SKILLDESC_GetETypeDamageStr(int nEType)
{
    switch (nEType)
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

// 0x004E6EA0
static void __stdcall SKILLDESC_ApplyFireMasteryBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 1)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_FIRE_MASTERY, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

// 0x004E6F00
static void __stdcall SKILLDESC_ApplyLightningMasteryBonus(int* pValue1, D2SkillsTxt* pSkillsTxt, int* pValue2)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (pSkillsTxt && pSkillsTxt->nEType == 2)
    {
        int nBonus = STATLIST_UnitGetStatValue(pPlayer, STAT_PASSIVE_LTNG_MASTERY, 0);
        if (nBonus)
        {
            int nValue = *pValue1;
            *pValue1 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
            nValue = *pValue2;
            *pValue2 = nValue + DATATBLS_ApplyRatio(nValue, nBonus, 100);
        }
    }
}

void __stdcall SKILLDESC_GetElemDamage(D2UnitStrc* pUnit, int* pMin, int* pMax, int* pType, D2SkillsTxt* pSkillsTxt, int nSkillLevel); // 0x004E72D0

// 0x004E73E0
static int __stdcall SKILLDESC_FormatSignedInt(Unicode* wszText, int bPrefixSign, int nValue)
{
    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
// build: symbol ?gszFmtPlusD@* 0x006DBE90
        wsprintfA(szText, gszFmtPlusD, nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

// 0x004E7430
static __declspec(noinline) int __stdcall SKILLDESC_FormatSignedDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction)
{
    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
// build: symbol ?gszFmtPlusDecimal@* 0x006DBE9C
        wsprintfA(szText, gszFmtPlusDecimal, nValue, nFraction);
    else
// build: symbol ?gszFmtDecimal@* 0x006DBE94
        wsprintfA(szText, gszFmtDecimal, nValue, nFraction);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

// 0x004E7480
static int SKILLDESC_FormatIntOrDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction)
{
    if (!nValue && !nFraction)
        return 0;
    if (nFraction)
        return SKILLDESC_FormatSignedDecimal(wszText, bPrefixSign, nValue, nFraction);
    return SKILLDESC_FormatSignedInt(wszText, bPrefixSign, nValue);
}

// 0x004E7650
static int __stdcall SKILLDESC_AppendFrameRange(Unicode* wszOut, unsigned short wStr, int nMinFrames, int nMaxFrames)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int nMin = nMinFrames / 25;
    int nMinFraction = nMinFrames % 25 * 10 / 25;
    int nMax = nMaxFrames / 25;
    int nMaxFraction = nMaxFrames % 25 * 10 / 25;
    if (!nMin && !nMinFraction && !nMax)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (nMinFraction || nMaxFraction)
// build: symbol ?gszFmtDecRange@* 0x006DBEC8
        wsprintfA(szText, gszFmtDecRange, nMin, nMinFraction, nMax, nMaxFraction);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10AC));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E77A0
static int __stdcall SKILLDESC_AppendScaledRange(Unicode* wszOut, unsigned short wStr1, unsigned short wStr2, int nMaxValue, int nMultiplier, int nMinValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int nMin = nMinValue / 256;
    int nMinFraction = nMinValue % 256 * nMultiplier / 256;
    int nMax = nMaxValue / 256;
    int nMaxFraction = nMaxValue % 256 * nMultiplier / 256;
    if (!nMin && !nMax && !nMinFraction && !nMaxFraction)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (nMinFraction || nMaxFraction)
        wsprintfA(szText, gszFmtDecRange, nMin, nMinFraction, nMax, nMaxFraction);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7930
static int __stdcall SKILLDESC_AppendFormattedValue(Unicode* wszOut, int nValue, unsigned short wStr)
{
    int wszText_[128]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 256; ++i)
        wszText[i] = 0;

    if (wStr == 0x1506)
    {
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x1506));
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
        return 1;
    }

    sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(wStr), nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszOut, wszText);
    return 1;
}

// 0x004E79E0
static int __stdcall SKILLDESC_AppendLabelValue(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, gszFmtPlusD, nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7A90
static int __stdcall SKILLDESC_AppendScaledValue(Unicode* wszOut, int bPrefixSign, int nValue, unsigned short wStr1, unsigned short wStr2, int nMultiplier)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    SKILLDESC_FormatIntOrDecimal(wszText, bPrefixSign, nValue / 256, nValue % 256 * nMultiplier / 256);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7B90
static int __stdcall SKILLDESC_AppendLabelDecimal(unsigned short wStr, Unicode* wszOut, int bPrefixSign, int nValue, int nFraction)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue && nFraction <= 0)
        return 0;

    SKILLDESC_FormatIntOrDecimal(wszText, bPrefixSign, nValue, nFraction);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7C30
static int __stdcall SKILLDESC_AppendValueLabel(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, gszFmtPlusD, nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7CE0
static int __stdcall SKILLDESC_AppendValueTwoLabels(Unicode* wszOut, unsigned short wStr1, unsigned short wStr2, int bPrefixSign, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, gszFmtPlusD, nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7DB0
static int __stdcall SKILLDESC_AppendValueCountLabel(Unicode* wszOut, int nValue, int nStr1, int nStr2, int bPrefixSign)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, gszFmtPlusD, nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(nValue == 1 ? nStr1 : nStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7E70
static int __stdcall SKILLDESC_AppendLabelValueLabel(Unicode* wszOut, unsigned short wStr1, unsigned short wStr2, int bPrefixSign, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, gszFmtPlusD, nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E7F40
static int __stdcall SKILLDESC_AppendLabelRangeLabel(unsigned short wStr1, unsigned short wStr2, Unicode* wszOut, int bPrefixSign, int nMin, int nMax)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValueLabel(wszOut, wStr1, wStr2, 0, nMin);

    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign)
// build: symbol ?gszFmtPlusRange@* 0x006DBEA4
        wsprintfA(szText, gszFmtPlusRange, nMin, nMax);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (wStr1 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    if (wStr2 != 0x1506)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E8020
static int __stdcall SKILLDESC_AppendLabelsRange(unsigned short wStr1, unsigned short wStr2, Unicode* wszOut, int bPrefixSign, int nMin, int nMax)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValueLabel(wszOut, wStr1, wStr2, 0, nMin);

    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign)
        wsprintfA(szText, gszFmtPlusRange, nMin, nMax);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E80F0
static int __stdcall SKILLDESC_AppendLabelRange(unsigned short wStr, Unicode* wszOut, int bSeparator, int nMin, int nMax, int bPrefixSign)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValue(wszOut, wStr, nMin, bPrefixSign);

    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign)
        wsprintfA(szText, gszFmtPlusRange, nMin, nMax);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    if (bSeparator)
        sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9B));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E81C0
static int __stdcall SKILLDESC_AppendLabelValueLabels(Unicode* wszOut, unsigned short wStr1, unsigned short wStr2, unsigned short wStr3, int bPrefixSign, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, gszFmtPlusD, nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr3));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

int __stdcall SKILLDESC_AppendSecondsTwentieths(Unicode* wszOut, unsigned short wStr, int nValue); // 0x004E82A0

int __stdcall SKILLDESC_AppendSecondsTenths(Unicode* wszOut, unsigned short wStr, int nValue); // 0x004E83E0

// 0x004E84F0
static int __stdcall SKILLDESC_AppendManaValue(int nValue, Unicode* wszOut)
{
    const Unicode* wszStr1 = D2LANG_GetStringFromTblIndex(0x5300);
    const Unicode* wszStr2 = D2LANG_GetStringFromTblIndex(0x5304);
    const Unicode* wszStr3 = D2LANG_GetStringFromTblIndex(0x5305);
    const Unicode* wszStr4 = D2LANG_GetStringFromTblIndex(0xF9B);
    int wszText_[8]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 16; ++i)
        wszText[i] = 0;

    int szText_[8]; char* const szText = (char*)szText_;
    wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszStr2);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, wszStr4);
    sub_00526700(wszOut, wszStr1);
    sub_00526700(wszOut, wszStr3);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E85C0
static int __stdcall sub_004E85C0_AppendManaCost(Unicode* wszOut, int nSkillId, int nLevel, int nMultiplier, D2SkillsTxt* pSkillsTxt, int nValue)
{
    short nMana = pSkillsTxt->wMana;
    if (!nMana && !pSkillsTxt->wLevelMana)
        return 0;

    if (nValue)
        return SKILLDESC_AppendManaValue(nValue, wszOut);

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
        return 0;

    nSkillId = pSkillDescTxt->wStrMana;
    const int nLevelMana = pSkillsTxt->wLevelMana;
    const int nLevelCost = nLevelMana << pSkillsTxt->nManaShift;
    int nCost = ((nLevel - 1) * nLevelMana + nMana) << pSkillsTxt->nManaShift;
    const int nMinCost = pSkillsTxt->wMinMana << 8;
    if (nMinCost > nCost)
        nCost = nMinCost;

    if (pSkillsTxt->nManaShift == 8 || nLevelCost > 0x100 || nCost > 0x1900)
        return SKILLDESC_AppendLabelValue(wszOut, (unsigned short)nSkillId, nCost >> 8, 0);

    if (nMultiplier <= 10)
        return SKILLDESC_AppendLabelDecimal((unsigned short)nSkillId, wszOut, 0, nCost / 256, nCost % 256 * 10 / 256);

    return SKILLDESC_AppendScaledValue(wszOut, 0, nCost, (unsigned short)nSkillId, 0x1506, nMultiplier);
}

void __stdcall SKILLDESC_AddSummonLife(Unicode* wszText, int nMonsterId, int nPercent, int nBonus); // 0x004EC090

// 0x004EC140
static int __stdcall SKILLDESC_AddElemRange(Unicode* wszText, int nMin, unsigned short nString, int nMax, int nElemType)
{
    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    for (int i = 0; i < 16; ++i)
        wszNumber_[i] = 0;
    int szNumber_[8]; char* const szNumber = (char*)szNumber_;
    if (!nString)
    {
        nString = SKILLDESC_GetETypeDamageStr(nElemType);
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

// 0x004EC220
static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(wszText, nMin >> 8, nString, nMax >> 8, pSkillsTxt->nEType);
}

// 0x004EC280
static int __stdcall SKILLDESC_AddMissileElemDamage(D2UnitStrc* pUnit, Unicode* wszText, unsigned short nString, int nMissileId, int nSkillLevel)
{
    const int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    const int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) >> 8;
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(wszText, nMin, nString, nMax, MISSILE_GetElemTypeFromMissileId(nMissileId));
}

// 0x004EC2E0
static int __stdcall SKILLDESC_AddPhysDamage(int nPercent, D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, int nBonus)
{
    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    for (int i = 0; i < 16; ++i)
        wszNumber_[i] = 0;
    int szNumber_[8]; char* const szNumber = (char*)szNumber_;
    int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0) >> 8;
    nMin += ApplyPercent(nMin, nPercent) + nBonus;
    nMax += ApplyPercent(nMax, nPercent) + nBonus;
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
        wsprintfA(szNumber, gszFmtPlusD, nMin);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10A0));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EC510
static int SKILLDESC_AddToHit(Unicode* wszText, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (!nToHit)
    {
        return 0;
    }

    return SKILLDESC_AppendLabelValueLabel(wszText, 0x10A6, 0x10B3, 1, nToHit);
}

// 0x004EC540
static int __stdcall SKILLDESC_AddElemRatePerSecond(unsigned short nString, Unicode* wszText, int nMin, int nMax)
{
    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    for (int i = 0; i < 16; ++i)
        wszNumber_[i] = 0;
    int szNumber_[8]; char* const szNumber = (char*)szNumber_;
    if (!nMin && !nMax)
    {
        return 0;
    }

    if (nMin == nMax)
    {
        wsprintfA(szNumber, gszFormatD, nMin);
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

// 0x004EC620
static int __stdcall SKILLDESC_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel)
{
    int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int* const pMax = &nMax;
    SKILLDESC_ApplyFireMasteryBonus(&nMin, pSkillsTxt, pMax);
    SKILLDESC_ApplyLightningMasteryBonus(&nMin, pSkillsTxt, pMax);
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
        nString = 0x10A1;
        break;
    default:
        nString = 0x10A1;
        break;
    }

    return SKILLDESC_AddElemRatePerSecond(nString, wszText, nMinRate, nMaxRate);
}

static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, Unicode* wszText); // 0x004EC6F0
// 0x004EC6F0
static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, Unicode* wszText)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    return SKILLDESC_AddElemRatePerSecond(0x10A1, wszText, nMin, nMax);
}

// 0x004EC740
static int __stdcall SKILLDESC_AddSkillElemRateByType(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, Unicode* wszText, D2SkillsTxt* pSkillsTxt)
{
    int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    nMin = nMin * 0x19 >> 8;
    nMax = nMax * 0x19 >> 8;
    unsigned short nString;
    switch (pSkillsTxt->nEType)
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
        nString = 0x10A1;
        break;
    default:
        nString = 0x10A1;
        break;
    }

    return SKILLDESC_AddElemRatePerSecond(nString, wszText, nMin, nMax);
}

// 0x004EC7E0
static int __stdcall SKILLDESC_AddValueLine(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nValue)
{
    if (!nValue)
    {
        return 0;
    }

    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    for (int i = 0; i < 16; ++i)
        wszNumber_[i] = 0;
    int szNumber_[8]; char* const szNumber = (char*)szNumber_;
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szNumber, gszFmtPlusD, nValue);
    }
    else
    {
        wsprintfA(szNumber, gszFormatD, nValue);
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
static int __stdcall SKILLDESC_AddDecimalLine(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nWhole, int nFraction)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nWhole && !nFraction)
    {
        return 0;
    }

    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    for (int i = 0; i < 16; ++i)
        wszNumber_[i] = 0;
    SKILLDESC_FormatSignedDecimal(wszNumber, bPlus, nWhole, nFraction);
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
static int __stdcall SKILLDESC_AddValueOverTime(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int nValue, int bPlus, int nCount)
{
    if (nStringBefore != 0x1506 && nValue && nCount > 0)
    {
    int szNumber_[8]; char* const szNumber = (char*)szNumber_;
    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    sub_00403040_VectorConstructor(wszNumber, 2, 0x20, NPCMENU_ClearUnicode);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringBefore));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
    SKILLDESC_FormatSignedInt(wszNumber, bPlus, nValue);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
    wsprintfA(szNumber, gszFormatD, nCount);
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
static int SKILLDESC_AddTextPair(Unicode* wszText, unsigned short nString1, unsigned short nString2)
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
static int __stdcall SKILLDESC_AddValueAfterText(Unicode* wszText, unsigned short nStringBefore, unsigned short nStringAfter, int bPlus, int bPercent, int nValue)
{
    if (nStringBefore == 0x1506)
    {
        return 0;
    }

    if (!nValue)
    {
        return 0;
    }

    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    for (int i = 0; i < 16; ++i)
        wszNumber_[i] = 0;
    SKILLDESC_FormatSignedInt(wszNumber, bPlus, nValue);
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
static int __stdcall SKILLDESC_AddFormattedText(Unicode* wszText, int nValue, unsigned short nString)
{
    if (nString == 0x1506)
    {
        return 0;
    }

    int wszLine_[128]; Unicode* const wszLine = (Unicode*)wszLine_;
    for (int i = 0; i < 128; ++i)
        wszLine_[i] = 0;
    sub_005269D0(0x100, wszLine, D2LANG_GetStringFromTblIndex(nString), nValue);
    sub_00526700(wszText, wszLine);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

int __stdcall SKILLDESC_AddSummonDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, D2SkillsTxt* pSkillsTxt); // 0x004ECCF0

// 0x004ED0D0
static int SKILLDESC_AddNextLevelParam(int nSkillId, int nSkillLevel, Unicode* wszText)
{
    if (nSkillLevel > 1)
    {
        SKILLDESC_AppendValueLabel(wszText, 0x10D5, SkillParam_0D0(nSkillId, nSkillLevel - 1), 0);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x110D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }
    return 1;
}

// 0x004EDB30
static int __stdcall SKILLDESC_AddSeconds(int nFrames, unsigned short nString, int bPlus, Unicode* wszText)
{
    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    for (int i = 0; i < 16; ++i)
        wszNumber_[i] = 0;
    const int nSeconds = nFrames / 25;
    const int nTenths = nFrames % 25 * 10 / 25;
    if (!nSeconds && !nTenths)
    {
        return 0;
    }

    if (nTenths)
    {
        SKILLDESC_FormatSignedDecimal(wszNumber, bPlus, nSeconds, nTenths);
    }
    else
    {
        SKILLDESC_FormatSignedInt(wszNumber, bPlus, nSeconds);
    }
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nSeconds == 1 && !nTenths ? 0x10AB : 0x10AC));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004EDC40
static int __stdcall SKILLDESC_AddElemDuration(Unicode* wszText, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

        return SKILLDESC_AddSeconds(nLength, nString, 0, wszText);
    }

    return 0;
}

int __stdcall sub_004EDCA0_AddElemDamageOverTime(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel); // 0x004EDCA0

int __stdcall sub_004EDDD0_AddAttackInfo(Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillLevel); // 0x004EDDD0

static inline void AppendString(Unicode* wszText, unsigned short nString)
{
    if (nString != 0x1506)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    }
}

// 0x004EDEA0
int __fastcall SKILLDESC_AddSkillLine(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nManaValue, int nLine, int nLevelBonus)
{
    int nCalcA;
    int nCalcB;
    int nStringB;
    int nStringA;
    D2MissilesTxt* pMissilesTxt;
    int nMissileId;
    int nFrames;
    int szNumber_[8]; char* const szNumber = (char*)szNumber_;
    int wszNumber_[16]; Unicode* const wszNumber = (Unicode*)wszNumber_;
    int wszLine_[128]; Unicode* const wszLine = (Unicode*)wszLine_;
    int wszMessage_[50]; Unicode* const wszMessage = (Unicode*)wszMessage_;

    if (!pSkillsTxt)
    {
        return 0;
    }

    D2SkillDescTxt* pSkillDescTxt = sub_004A89D0_SkillDescRec(nSkillId);
    if (!pSkillDescTxt)
    {
        return 0;
    }

    nCalcA = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcA[nLine], nSkillId, nSkillLevel);
    nCalcB = SKILLS_EvaluateSkillDescFormula(pUnit, pSkillDescTxt->dwDescCalcB[nLine], nSkillId, nSkillLevel);
    nStringA = pSkillDescTxt->wDescTextA[nLine];
    nStringB = pSkillDescTxt->wDescTextB[nLine];
    switch (pSkillDescTxt->nDescLine[nLine])
    {
    case 1:
        sub_004E85C0_AppendManaCost(wszText, nSkillId, nSkillLevel, nCalcA, pSkillsTxt, nManaValue);
        break;

    case 2:
        SKILLDESC_AppendLabelValueLabel(wszText, nStringA, nStringB, 1, nCalcA);
        break;

    case 3:
        SKILLDESC_AppendLabelValueLabel(wszText, nStringA, nStringB, 0, nCalcA);
        break;

    case 4:
        SKILLDESC_AppendLabelValue(wszText, nStringA, nCalcA, 1);
        break;

    case 5:
        SKILLDESC_AppendLabelValue(wszText, nStringA, nCalcA, 0);
        break;

    case 6:
        SKILLDESC_AppendValueLabel(wszText, nStringA, nCalcA, 1);
        break;

    case 7:
        SKILLDESC_AppendValueLabel(wszText, nStringA, nCalcA, 0);
        break;

    case 8:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddToHit(wszText, pUnit, nSkillId, nSkillLevel);
        break;

    case 9:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddPhysDamage(nCalcA, pUnit, wszText, nSkillId, nSkillLevel, nCalcB);
        break;

    case 10:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemDamage(pUnit, nSkillId, nSkillLevel, wszText, pSkillsTxt, 0);
        break;

    case 11:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
        break;

    case 12:
        AppendString(wszText, nStringB);
        SKILLDESC_AddSeconds(nCalcA, nStringA, 0, wszText);
        break;

    case 13:
        SKILLDESC_AddSummonLife(wszText, pSkillsTxt->wSummon, nCalcA, nCalcB);
        break;

    case 14:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        sub_004EDCA0_AddElemDamageOverTime(pUnit, wszText, pSkillsTxt, nSkillId, nSkillLevel);
        break;

    case 15:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 16:
        SKILLDESC_AppendFrameRange(wszText, 0x10B0, nCalcA, nCalcB);
        break;

    case 17:
        AppendString(wszText, nStringB);
        SKILLDESC_AppendLabelRangeLabel(nStringA, 0x10BE, wszText, 0, nCalcA, nCalcB);
        break;

    case 18:
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(nStringA));
        {
            const int nLevel = nCalcA;
            if (nLevel > 0)
            {
                INV_PrefixColorCode(wszLine, nLevel);
            }
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 19:
        AppendString(wszText, nStringB);
        SKILLDESC_AppendSecondsTwentieths(wszText, nStringA, nCalcA);
        break;

    case 20:
        SKILLDESC_AppendLabelValueLabels(wszText, nStringA, 0x10B3, nStringB, 1, nCalcA);
        break;

    case 21:
        SKILLDESC_AppendLabelValueLabels(wszText, nStringA, 0x10B3, nStringB, 0, nCalcA);
        break;

    case 22:
        SKILLDESC_AddMissileElemRate(pUnit, wszText, pSkillsTxt, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        break;

    case 23:
        nMissileId = pSkillDescTxt->wDescMissile[0];
        pMissilesTxt = sub_0046ACE0(nMissileId);
        if (!pMissilesTxt)
        {
            return 0;
        }
        nFrames = pMissilesTxt->wLevRange * nSkillLevel + pMissilesTxt->wRange;
        SKILLDESC_AddSeconds(nFrames, nStringA, 0, wszText);
        break;

    case 24:
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemDamage(pUnit, nSkillId, nSkillLevel, wszText, pSkillsTxt, nStringA);
        break;

    case 25:
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(nStringA));
        if ((unsigned short)nStringB != 0x1506)
        {
            sub_00526700(wszLine, D2LANG_GetStringFromTblIndex(nStringB));
        }
        {
            const int nLevel = nCalcA;
            if (nLevel > 0)
            {
                INV_PrefixColorCode(wszLine, nLevel);
            }
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 26:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemRateByType(pUnit, nSkillId, nSkillLevel, wszText, pSkillsTxt);
        break;

    case 27:
        AppendString(wszText, nStringA);
        AppendString(wszText, nStringB);
        SKILLDESC_AddSkillElemRate(pUnit, nSkillId, nSkillLevel, wszText);
        break;

    case 28:
    {
        D2MissilesTxt* pMissilesTxt = sub_0046ACE0(pSkillDescTxt->wDescMissile[0]);
        if (!pMissilesTxt)
        {
            return 0;
        }
        SKILLDESC_AppendSecondsTwentieths(wszText, 0x10AE, pMissilesTxt->dwParam[0]);
        break;
    }

    case 29:
    {
        D2MissilesTxt* pMissilesTxt = sub_0046ACE0(pSkillDescTxt->wDescMissile[0]);
        if (!pMissilesTxt)
        {
            return 0;
        }
        SKILLDESC_AppendValueLabel(wszText, 0x10B6, (pMissilesTxt->wLevRange * (nSkillLevel - 1) + pMissilesTxt->wRange) * 2 / 3, 0);
        break;
    }

    case 30:
        pMissilesTxt = sub_0046ACE0(pSkillDescTxt->wDescMissile[0]);
        if (!pMissilesTxt)
        {
            return 0;
        }
        nMissileId = pMissilesTxt->wSubMissile[0];
        pMissilesTxt = sub_0046ACE0(nMissileId);
        if (!pMissilesTxt)
        {
            return 0;
        }
        nFrames = pMissilesTxt->wLevRange * nSkillLevel + pMissilesTxt->wRange;
        SKILLDESC_AddSeconds(nFrames, nStringA, 0, wszText);
        break;

    case 31:
    {
        D2DifficultyLevelsTxt* pDifficultyLevelsTxt = DATATBLS_GetDifficultyLevelsTxtRecord(GAME_GetDifficulty());
        const int nDivisor = pDifficultyLevelsTxt->dwAiCurseDivisor;
        SKILLDESC_AddSeconds(nDivisor > 0 ? nCalcA / nDivisor : nCalcA, nStringA, 0, wszText);
        break;
    }

    case 32:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        SKILLDESC_AppendLabelValueLabel(wszText, nStringB, 0x10B3, 1, nCalcA);
        break;

    case 33:
        if (nSkillLevel > 1)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringB));
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        }
        break;

    case 34:
        SKILLDESC_AddSummonDamageBonus(pUnit, wszText, nSkillId, pSkillsTxt, nSkillLevel);
        break;

    case 35:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00403040_VectorConstructor(wszNumber, 2, 0x20, NPCMENU_ClearUnicode);
        wsprintfA(szNumber, gszFmtRange, nCalcA, nCalcB);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 36:
        SKILLDESC_AppendValueCountLabel(wszText, nCalcA, nStringA, nStringB, 0);
        break;

    case 37:
        SKILLDESC_AppendSecondsTenths(wszText, nStringA, nCalcA);
        break;

    case 38:
        SKILLDESC_AppendLabelRangeLabel(nStringA, nStringB, wszText, 0, nCalcA, nCalcB);
        break;

    case 39:
        SKILLDESC_AddSummonDamage(pUnit, wszText, nSkillId, nSkillLevel, pSkillsTxt);
        break;

    case 40:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005269D0(0x100, wszLine, D2LANG_GetStringFromTblIndex(nStringA), D2LANG_GetStringFromTblIndex(nStringB));
        if (nCalcA > 0)
        {
            INV_PrefixColorCode(wszLine, nCalcA);
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 41:
        SKILLDESC_AddMonsterDamage(wszText, pSkillsTxt, nCalcA, nCalcB);
        break;

    case 42:
        SKILLDESC_AddDecimalLine(wszText, nStringA, nStringB, 1, 0, nCalcA, nCalcB);
        break;

    case 43:
        SKILLDESC_AppendScaledRange(wszText, nStringA, nStringB, nCalcB, 10, nCalcA);
        break;

    case 44:
        SKILLDESC_AppendScaledRange(wszText, nStringA, nStringB, nCalcB, 100, nCalcA);
        break;

    case 45:
        SKILLDESC_AddNextLevelParam(nSkillId, nSkillLevel, wszText);
        break;

    case 46:
        if (!nCalcB)
        {
            return 0;
        }
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszLine, 2, 0x100, NPCMENU_ClearUnicode);
        sub_005269D0(0x100, wszLine, D2LANG_GetStringFromTblIndex(nStringA), D2LANG_GetStringFromTblIndex(nStringB));
        if (nCalcA > 0)
        {
            INV_PrefixColorCode(wszLine, nCalcA);
        }
        sub_00526700(wszText, wszLine);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0xF9E));
        INV_PrefixColorCode(wszLine, nLevelBonus);
        sub_00526700(wszText, wszLine);
        break;

    case 47:
        SKILLDESC_AppendLabelRange(nStringA, wszText, 0, nCalcA, nCalcB, 0);
        break;

    case 48:
        sub_004EDDD0_AddAttackInfo(wszText, nSkillId, pSkillsTxt, pUnit, nSkillLevel);
        break;

    case 49:
    {
        const int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        const int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
        SKILLDESC_AppendLabelRange(nStringA, wszText, 1, nMin, nMax, 1);
        break;
    }

    case 50:
        SKILLDESC_AddMissileElemDamage(pUnit, wszText, nStringA, pSkillDescTxt->wDescMissile[0], nSkillLevel);
        break;

    case 51:
        SKILLDESC_AppendFormattedValue(wszText, nCalcA, nStringA);
        break;

    case 52:
        SKILLDESC_AppendLabelRangeLabel(nStringA, nStringB, wszText, 1, nCalcA, nCalcB);
        break;

    case 53:
        TEXT_DrawHintText(sub_004A9A90_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 54:
        TEXT_DrawHintText(sub_004A9AE0_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 55:
        TEXT_DrawHintText(sub_004A9B30_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 56:
        TEXT_DrawHintText(sub_004A9B80_FindSkill(pUnit, nSkillId), nStringA);
        break;

    case 57:
        SKILLDESC_AddSeconds(nCalcA, nStringA, 1, wszText);
        break;

    case 58:
        SKILLDESC_AppendLabelsRange(nStringA, nStringB, wszText, 1, nCalcA, nCalcB);
        break;

    case 59:
        AppendString(wszText, nStringB);
        SKILLDESC_AddElemRange(wszText, nCalcA, nStringA, nCalcB, pSkillsTxt->nEType);
        break;

    case 60:
        if (!nCalcB)
        {
            nCalcB = 10;
        }
        SKILLDESC_AppendScaledValue(wszText, 1, nCalcA, nStringA, nStringB, nCalcB);
        break;

    case 61:
        if (!nCalcB)
        {
            nCalcB = 10;
        }
        SKILLDESC_AppendScaledValue(wszText, 0, nCalcA, nStringA, nStringB, nCalcB);
        break;

    case 62:
        SKILLDESC_AppendLabelsRange(nStringA, nStringB, wszText, 0, nCalcA, nCalcB);
        break;

    case 63:
        SKILLDESC_AddValueLine(wszText, nStringA, nStringB, 1, 1, nCalcA);
        break;

    case 64:
        SKILLDESC_AddValueOverTime(wszText, nStringA, nStringB, nCalcA, 1, nCalcB);
        break;

    case 65:
        SKILLDESC_AddTextPair(wszText, nStringA, nStringB);
        break;

    case 66:
        SKILLDESC_AddFormattedText(wszText, nCalcA, nStringA);
        break;

    case 67:
        SKILLDESC_AddValueLine(wszText, nStringA, nStringB, 1, 0, nCalcA);
        break;

    case 68:
        SKILLDESC_AppendValueTwoLabels(wszText, nStringA, nStringB, 0, nCalcA);
        break;

    case 69:
        SKILLDESC_AddValueAfterText(wszText, nStringA, nStringB, 0, 0, nCalcA);
        break;

    case 70:
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        SKILLDESC_AppendLabelValue(wszText, nStringB, nCalcA, 1);
        break;

    case 71:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        if ((unsigned short)nStringB == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszMessage, 2, 0x64, NPCMENU_ClearUnicode);
        sub_005269D0(0x64, wszMessage, D2LANG_GetStringFromTblIndex(nStringB), nCalcA);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, wszMessage);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 72:
        if (!nCalcA)
        {
            return 0;
        }
        if (nCalcB <= 0)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszNumber, 2, 0x20, NPCMENU_ClearUnicode);
        SKILLDESC_FormatSignedInt(wszNumber, 1, nCalcA);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
        wsprintfA(szNumber, gszFormatD, nCalcB);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 73:
        if (!nCalcA)
        {
            return 0;
        }
        if (nCalcB <= 0)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszNumber, 2, 0x20, NPCMENU_ClearUnicode);
        wsprintfA(szNumber, gszFormatD, nCalcA);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xFA0));
        wsprintfA(szNumber, gszFormatD, nCalcB);
        sub_00526320_ToUnicode(wszNumber, szNumber, 0x20);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringA));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 74:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszMessage, 2, 0x64, NPCMENU_ClearUnicode);
        sub_005269D0(0x64, wszMessage, D2LANG_GetStringFromTblIndex(nStringA), nCalcA);
        sub_00526700(wszText, wszMessage);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    case 75:
        if ((unsigned short)nStringA == 0x1506)
        {
            return 0;
        }
        sub_00403040_VectorConstructor(wszMessage, 2, 0x64, NPCMENU_ClearUnicode);
        sub_005269D0(0x64, wszMessage, D2LANG_GetStringFromTblIndex(nStringA), nCalcA, nCalcB);
        sub_00526700(wszText, wszMessage);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        break;

    default:
        return 0;
    }

    return 1;
}
