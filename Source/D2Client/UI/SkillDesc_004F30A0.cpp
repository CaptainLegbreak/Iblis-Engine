#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2LevelTxt.h"
#include "D2Structs.h"
#include "D2GameTypes.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"

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

void __cdecl sub_005269D0_FormatText(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

void __fastcall NPCMENU_ClearUnicode(Unicode* pChar);                                                  // 0x0042F530

void __stdcall sub_00403040_VectorConstructor(void* pArray, unsigned int nSize, int nCount, void (__fastcall* pfnConstructor)(Unicode*)); // 0x00403040

void __fastcall INV_PrefixColorCode(Unicode* wszText, int nLevel);                                // 0x004521C0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor);                              // 0x00483360


int __cdecl GAME_GetLadderFlag();                                                                     // 0x0044DCA0










int __stdcall SKILLDESC_AddMonsterDamage(Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nBonusMin, int nBonusMax); // 0x004ECF50

int __stdcall SKILLDESC_AddSummonDamageBonus(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, int nSkillLevel); // 0x004ED150


static unsigned short SKILLDESC_GetETypeDamageStr(int nEType);

static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel); // 0x004EC6F0

#define MIN(a, b) ((a) < (b) ? (a) : (b))

#define MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2StaticPathStrc;

struct D2GfxLightStrc;

struct D2SkillsTxt;

union D2SeedStrc;

struct D2MissilesTxt;

struct D2MonStats2Txt;

struct D2MissileStrc;

extern const unsigned int gdwBitMasks[32]; // 0x006CE268



int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00



typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390


D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

static __forceinline int ApplyPercent(int nValue, int nPercent)
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

// build: symbol ?SKILLDESC_ApplyFireMasteryBonus@* 0x004E6EA0
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

// build: symbol ?SKILLDESC_ApplyLightningMasteryBonus@* 0x004E6F00
static void __stdcall SKILLDESC_ApplyLightningMasteryBonus(int* pValue1, int* pValue2, D2SkillsTxt* pSkillsTxt)
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

// build: symbol ?SKILLDESC_FormatSignedInt@* 0x004E73E0
static int __stdcall SKILLDESC_FormatSignedInt(Unicode* wszText, int bPrefixSign, int nValue)
{
    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

static int __stdcall SKILLDESC_FormatSignedDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction)
{
    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d.%d", nValue, nFraction);
    else
        wsprintfA(szText, "%d.%d", nValue, nFraction);
    sub_00526320_ToUnicode(wszText, szText, 32);
    return 1;
}

static int SKILLDESC_FormatIntOrDecimal(Unicode* wszText, int bPrefixSign, int nValue, int nFraction)
{
    if (!nValue && !nFraction)
        return 0;
    if (nFraction)
        return SKILLDESC_FormatSignedDecimal(wszText, bPrefixSign, nValue, nFraction);
    return SKILLDESC_FormatSignedInt(wszText, bPrefixSign, nValue);
}

// build: symbol ?SKILLDESC_AppendFrameRange@* 0x004E7650
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
        wsprintfA(szText, "%d.%d-%d.%d", nMin, nMinFraction, nMax, nMaxFraction);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0x10AC));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendScaledRange@* 0x004E77A0
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
        wsprintfA(szText, "%d.%d-%d.%d", nMin, nMinFraction, nMax, nMaxFraction);
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

// build: symbol ?SKILLDESC_AppendFormattedValue@* 0x004E7930
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

    sub_005269D0_FormatText(256, wszText, D2LANG_GetStringFromTblIndex(wStr), nValue);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszOut, wszText);
    return 1;
}

// build: symbol ?SKILLDESC_AppendLabelValue@* 0x004E79E0
static int __stdcall SKILLDESC_AppendLabelValue(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendScaledValue@* 0x004E7A90
static int __stdcall SKILLDESC_AppendScaledValue(unsigned short wStr1, unsigned short wStr2, int nMultiplier, Unicode* wszOut, int bPrefixSign, int nValue)
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

// build: symbol ?SKILLDESC_AppendValueLabel@* 0x004E7C30
static int __stdcall SKILLDESC_AppendValueLabel(Unicode* wszOut, unsigned short wStr, int nValue, int bPrefixSign)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendValueTwoLabels@* 0x004E7CE0
static int __stdcall SKILLDESC_AppendValueTwoLabels(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendValueCountLabel@* 0x004E7DB0
static int __stdcall SKILLDESC_AppendValueCountLabel(int nStr1, int nStr2, int bPrefixSign, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(nValue == 1 ? nStr1 : nStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendLabelValueLabel@* 0x004E7E70
static int __stdcall SKILLDESC_AppendLabelValueLabel(unsigned short wStr1, unsigned short wStr2, int bPrefixSign, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
    else
        wsprintfA(szText, gszFormatD, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendLabelRangeLabel@* 0x004E7F40
static int __stdcall SKILLDESC_AppendLabelRangeLabel(unsigned short wStr1, unsigned short wStr2, Unicode* wszOut, int bPrefixSign, int nMin, int nMax)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValueLabel(wStr1, wStr2, 0, wszOut, nMin);

    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMin, nMax);
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

// build: symbol ?SKILLDESC_AppendLabelsRange@* 0x004E8020
static int __stdcall SKILLDESC_AppendLabelsRange(Unicode* wszOut, int bPrefixSign, unsigned short wStr1, unsigned short wStr2, int nMin, int nMax)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValueLabel(wStr1, wStr2, 0, wszOut, nMin);

    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMin, nMax);
    else
        wsprintfA(szText, gszFmtRange, nMin, nMax);
    sub_00526320_ToUnicode(wszText, szText, 32);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr1));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr2));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendLabelRange@* 0x004E80F0
static int __stdcall SKILLDESC_AppendLabelRange(unsigned short wStr, Unicode* wszOut, int bSeparator, int nMin, int nMax, int bPrefixSign)
{
    if (nMin == nMax)
        return SKILLDESC_AppendLabelValue(wszOut, wStr, nMin, bPrefixSign);

    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign)
        wsprintfA(szText, "+%d-%d", nMin, nMax);
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

// build: symbol ?SKILLDESC_AppendLabelValueLabels@* 0x004E81C0
static int __stdcall SKILLDESC_AppendLabelValueLabels(unsigned short wStr1, unsigned short wStr2, unsigned short wStr3, int bPrefixSign, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    if (!nValue)
        return 0;

    int szText_[8]; char* const szText = (char*)szText_;
    if (bPrefixSign && nValue >= 0)
        wsprintfA(szText, "+%d", nValue);
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

// build: symbol ?SKILLDESC_AppendSecondsTwentieths@* 0x004E82A0
static int __stdcall SKILLDESC_AppendSecondsTwentieths(unsigned short wStr, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    const int nTenths = nValue * 20 / 3;
    int nWhole = nTenths / 10;
    const int nFraction = nTenths % 10;
    if (nWhole < 1)
        nWhole = 1;
    if (nWhole || nFraction)
    {
        int szText_[8]; char* const szText = (char*)szText_;
        if (nFraction)
            wsprintfA(szText, "%d.%d", nWhole, nFraction);
        else
            wsprintfA(szText, gszFormatD, nWhole);
        sub_00526320_ToUnicode(wszText, szText, 32);
    }
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(nWhole == 1 ? 0x10C0 : 0x10B6));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AppendSecondsTenths@* 0x004E83E0
static int __stdcall SKILLDESC_AppendSecondsTenths(unsigned short wStr, Unicode* wszOut, int nValue)
{
    int wszText_[16]; Unicode* const wszText = (Unicode*)wszText_;
    for (int i = 0; i < 32; ++i)
        wszText[i] = 0;

    const int nTenths = nValue * 10 / 3;
    int nWhole = nTenths / 10;
    const int nFraction = nTenths % 10;
    if (nWhole < 1)
        nWhole = 1;
    if (nWhole || nFraction)
    {
        int szText_[8]; char* const szText = (char*)szText_;
        if (nFraction)
            wsprintfA(szText, "%d.%d", nWhole, nFraction);
        else
            wsprintfA(szText, gszFormatD, nWhole);
        sub_00526320_ToUnicode(wszText, szText, 32);
    }
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(wStr));
    sub_00526700(wszOut, wszText);
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(nWhole == 1 ? 0x10C0 : 0x10B6));
    sub_00526700(wszOut, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AddSummonLife@* 0x004EC090
static void __stdcall SKILLDESC_AddSummonLife(Unicode* wszText, int nMonsterId, int nPercent, int nBonus)
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
        SKILLDESC_AppendLabelValue(wszText, 0x10C6, nLife, 0);
    }
}

// build: symbol ?SKILLDESC_AddElemRange@* 0x004EC140
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

// build: symbol ?SKILLDESC_AddSkillElemDamage@* 0x004EC220
static int __stdcall SKILLDESC_AddSkillElemDamage(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, unsigned short nString, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1);
    if (!nMin && !nMax)
    {
        return 0;
    }

    return SKILLDESC_AddElemRange(wszText, nMin >> 8, nString, nMax >> 8, pSkillsTxt->nEType);
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

    return SKILLDESC_AddElemRange(wszText, nMin, nString, nMax, MISSILE_GetElemTypeFromMissileId(nMissileId));
}

// build: symbol ?SKILLDESC_AddPhysDamage@* 0x004EC2E0
static int __stdcall SKILLDESC_AddPhysDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nBonus, int nSkillLevel, int nPercent)
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
        wsprintfA(szNumber, "+%d", nMin);
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

// build: symbol ?SKILLDESC_AddToHit@* 0x004EC510
static int SKILLDESC_AddToHit(Unicode* wszText, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (!nToHit)
    {
        return 0;
    }

    return SKILLDESC_AppendLabelValueLabel(0x10A6, 0x10B3, 1, wszText, nToHit);
}

// build: symbol ?SKILLDESC_AddElemRatePerSecond@* 0x004EC540
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

// build: symbol ?SKILLDESC_AddMissileElemRate@* 0x004EC620
static int __stdcall SKILLDESC_AddMissileElemRate(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nMissileId, int nSkillLevel)
{
    int nMin = MISSILE_GetMinElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int nMax = MISSILE_GetMaxElemDamage(0, pUnit, nMissileId, nSkillLevel) * 0x4B;
    int* const pMax = &nMax;
    SKILLDESC_ApplyFireMasteryBonus(&nMin, pSkillsTxt, pMax);
    SKILLDESC_ApplyLightningMasteryBonus(&nMin, pMax, pSkillsTxt);
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

static int __stdcall SKILLDESC_AddSkillElemRate(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel)
{
    const int nMin = SKILLS_GetMinElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    const int nMax = SKILLS_GetMaxElemDamage(pUnit, nSkillId, nSkillLevel, 1) * 0x4B >> 8;
    return SKILLDESC_AddElemRatePerSecond(0x10A1, wszText, nMin, nMax);
}

// build: symbol ?SKILLDESC_AddSkillElemRateByType@* 0x004EC740
static int __stdcall SKILLDESC_AddSkillElemRateByType(Unicode* wszText, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

// build: symbol ?SKILLDESC_AddValueLine@* 0x004EC7E0
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
        wsprintfA(szNumber, "+%d", nValue);
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

// build: symbol ?SKILLDESC_AddDecimalLine@* 0x004EC900
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

// build: symbol ?SKILLDESC_AddValueOverTime@* 0x004ECA00
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

// build: symbol ?SKILLDESC_AddTextPair@* 0x004ECB10
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

// build: symbol ?SKILLDESC_AddValueAfterText@* 0x004ECB80
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

// build: symbol ?SKILLDESC_AddFormattedText@* 0x004ECC80
static int __stdcall SKILLDESC_AddFormattedText(Unicode* wszText, int nValue, unsigned short nString)
{
    if (nString == 0x1506)
    {
        return 0;
    }

    int wszLine_[128]; Unicode* const wszLine = (Unicode*)wszLine_;
    for (int i = 0; i < 128; ++i)
        wszLine_[i] = 0;
    sub_005269D0_FormatText(0x100, wszLine, D2LANG_GetStringFromTblIndex(nString), nValue);
    sub_00526700(wszText, wszLine);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AddSummonDamage@* 0x004ECCF0
static int __stdcall SKILLDESC_AddSummonDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nSkillLevel, D2SkillsTxt* pSkillsTxt)
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
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxt->nPassiveStat[i] == 0x19)
        {
            nPercent += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxt->dwPassiveCalc[i], nSkillId, nSkillLevel);
        }
    }

    if (nPercent)
    {
        if (nPercent <= -90)
        {
            nPercent = -90;
        }
        nMin += ApplyPercent(nMin, nPercent);
        nMax += ApplyPercent(nMax, nPercent);
    }

    SKILLDESC_AddElemRange(wszText, nMin, 0x10A0, nMax, 0);
    return 1;
}

// build: symbol ?SKILLDESC_AddNextLevelParam@* 0x004ED0D0
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

// build: symbol ?SKILLDESC_AddSeconds@* 0x004EDB30
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

// build: symbol ?SKILLDESC_AddElemDuration@* 0x004EDC40
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


inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x004F30A0
int __fastcall SKILLDESC_CltDoTargetPrgOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nOverlay;
    int nSound;
    D2StatListStrc* pStatList;
    if ((pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7])
        && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
        && pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount
        && (pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState)) != 0)
    {
        const int nLevel = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        const int nBonus = MIN(MAX(nLevel, 1), 3) - 1;
        nOverlay = pSkillsTxtRecord->wPrgOverlay + nBonus;
        nSound = pSkillsTxtRecord->wPrgSound + nBonus;
    }
    else
    {
        nOverlay = pSkillsTxtRecord->wPrgOverlay;
        nSound = pSkillsTxtRecord->wPrgSound;
    }

    GFX_AddUnitOverlay(pTarget, nOverlay, 2, 0, 0, 0, 0, 0);
    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    return 1;
}

// 0x004F31A0
int __fastcall SKILLDESC_CltDoPrgOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nOverlay;
    int nSound;
    D2StatListStrc* pStatList;
    if ((pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7])
        && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount
        && pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount
        && (pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState)) != 0)
    {
        const int nLevel = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        const int nBonus = MIN(MAX(nLevel, 1), 3) - 1;
        nOverlay = pSkillsTxtRecord->wPrgOverlay + nBonus;
        nSound = pSkillsTxtRecord->wPrgSound + nBonus;
    }
    else
    {
        nOverlay = pSkillsTxtRecord->wPrgOverlay;
        nSound = pSkillsTxtRecord->wPrgSound;
    }

    GFX_AddUnitOverlay(pUnit, nOverlay, 2, 0, 0, 0, 0, 0);
    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    return 1;
}

// 0x004F3A60
int __fastcall SKILLDESC_CreateCorpseExplosionMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nMonsterId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (!nX)
    {
        return 0;
    }

    if (!nY)
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2021;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nTargetX = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) + nX - 1;
    tMissileParams.nTargetY = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 3) + nY - 1;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;

    if (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[2])
    {
        SKILLS_SpawnMissileRing(pUnit, &tMissileParams, 0, 1);
    }
    else if (pMonStats2TxtRecord->nFlags[1] & gdwBitMasks[3])
    {
        SKILLS_SpawnMissileRing(pUnit, &tMissileParams, 3, 3);
        const short nSubMissile = sub_0046ACE0_GetMissilesTxtRecord(nMissile)->wSubMissile[0];
        if (nSubMissile > 0 && nSubMissile < sgptDataTables->nMissilesTxtRecordCount)
        {
            tMissileParams.nMissile = nSubMissile;
            SKILLS_SpawnMissileRing(pUnit, &tMissileParams, 2, 4);
        }
    }
    else
    {
        SKILLS_SpawnMissileRing(pUnit, &tMissileParams, 2, 2);
        const short nSubMissile = sub_0046ACE0_GetMissilesTxtRecord(nMissile)->wSubMissile[1];
        if (nSubMissile > 0 && nSubMissile < sgptDataTables->nMissilesTxtRecordCount)
        {
            tMissileParams.nMissile = nSubMissile;
            SKILLS_SpawnMissileRing(pUnit, &tMissileParams, 1, 3);
        }
    }

    tMissileParams.nY = nY;
    tMissileParams.nX = nX;

    D2UnitStrc* pMissile = 0;
    const int nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB > 0 && nMissileB < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissileParams.nMissile = nMissileB;
        pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    }

    const int nMissileC = pSkillsTxtRecord->wCltMissileC;
    if (nMissileC > 0 && nMissileC < sgptDataTables->nMissilesTxtRecordCount)
    {
        tMissileParams.nSkillLevel = 2;
        tMissileParams.nMissile = nMissileC;
        MISSILE_CreateClientMissile(&tMissileParams);
    }

    if (!CUNIT_GetPathTargetUnit(pUnit) && pMissile)
    {
        const short nSound = pSkillsTxtRecord->wTgtSound;
        if (nSound > 0)
        {
            sub_004B9A00(nSound, pMissile, 0, 0, 0);
        }
    }

    return 1;
}
