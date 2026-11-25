#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2Unicode.h"

struct Unicode;
struct D2SkillsTxt;
struct D2SkillDescTxt;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char gszFormatD[]; // 0x006D57BC
extern "C" const char gszFmtRange[]; // 0x006D9D70
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700


int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644E40
unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0
int __stdcall MISSILE_GetMinElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B100
int __stdcall MISSILE_GetMaxElemDamage(D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nLevel); // 0x0064B1D0



extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __fastcall SKILLDESC_AddSkillLine(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nArg3, int nArg4, int nLine, int nArg5); // 0x004EDEA0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

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

// 0x004EC140
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

static int __stdcall sub_004E73E0_FormatValue(Unicode* pDest, int bPlus, int nValue)
{
    char szText[32];
    if (bPlus && nValue >= 0)
    {
        wsprintfA(szText, "+%d", nValue);
    }
    else
    {
        wsprintfA(szText, gszFormatD, nValue);
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

// build: symbol ?SKILLDESC_AddSeconds@* 0x004EDB30
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

        return SKILLDESC_AddSeconds(nString, 0, nLength, wszText);
    }

    return 0;
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

    return SKILLDESC_AddElemRange(nMin >> 8, nString, nMax >> 8, wszText, pSkillsTxt->nEType);
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

// 0x004E7E70
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
        wsprintfA(szNumber, gszFormatD, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString1));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString2));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E79E0
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
        wsprintfA(szNumber, gszFormatD, nValue);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nString));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// 0x004E80F0
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

// 0x004EC2E0
static int __stdcall SKILLDESC_AddPhysDamage(D2UnitStrc* pUnit, Unicode* wszText, int nSkillId, int nBonus, int nSkillLevel, int nPercent)
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
        wsprintfA(szNumber, gszFormatD, nMin);
    }
    sub_00526320_ToUnicode(wszNumber, szNumber, 32);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x10A0));
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    return 1;
}

// build: symbol ?SKILLDESC_AddToHit@* 0x004EC510
static int SKILLDESC_AddToHit(int nSkillLevel, int nSkillId, D2UnitStrc* pUnit, Unicode* wszText)
{
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    if (!nToHit)
    {
        return 0;
    }

    return sub_004E7E70_AddValueTwoTexts(0x10A6, 0x10B3, 1, nToHit, wszText);
}

// 0x004EDDD0
static int __stdcall sub_004EDDD0_AddAttackInfo(Unicode* wszText, int nSkillId, D2SkillsTxt* pSkillsTxt, D2UnitStrc* pUnit, int nSkillLevel)
{
    if (GAME_IsExpansion())
    {
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, 0, nSkillId, nSkillLevel);
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, 0, nSkillLevel, 0);
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

int __fastcall sub_H14_Emit_004EDEA0(D2UnitStrc* pUnit, Unicode* wszText, D2SkillsTxt* pSkillsTxt, int nSkillId, int nSkillLevel, int nLine, int nCalcA, int nCalcB, unsigned short nStringA)
{
    switch (nLine)
    {
    case 1:
        sub_004EDDD0_AddAttackInfo(wszText, nSkillId, pSkillsTxt, pUnit, nSkillLevel);
        return 1;
    case 2:
        SKILLDESC_AddElemDuration(wszText, pSkillsTxt, pUnit, nSkillId, nSkillLevel);
        return 1;
    case 3:
        SKILLDESC_AddSeconds(nStringA, 0, nCalcA, wszText);
        return 1;
    case 4:
        SKILLDESC_AddElemRange(nCalcA, nStringA, nCalcB, wszText, pSkillsTxt->nEType);
        return 1;
    case 5:
        SKILLDESC_AddSkillElemDamage(pUnit, wszText, pSkillsTxt, nStringA, nSkillId, nSkillLevel);
        return 1;
    case 6:
        SKILLDESC_AddPhysDamage(pUnit, wszText, nSkillId, nCalcA, nSkillLevel, nCalcB);
        return 1;
    case 7:
        SKILLDESC_AddToHit(nSkillLevel, nSkillId, pUnit, wszText);
        return 1;
    case 8:
        sub_004E80F0_AddRangeText(wszText, nCalcA, nCalcB, nSkillLevel, nStringA, 0);
        return 1;
    }
    return 0;
}

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
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

// 0x004EF990
void __fastcall sub_004EF990_SetSkillPopUpText(D2UnitStrc* pUnit, int nSkillId, int nArg3, int nArg4, int nArg5, int nX, int nY)
{
    int bFound;
    int nHeight;
    int nWidth;
    char szNumber[32];

    if (!pUnit)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
    {
        return;
    }

    Unicode wszText[1024];
    Unicode wszNumber[32];

    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x109C));

    bFound = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (SKILLDESC_AddSkillLine(pUnit, wszText, pSkillsTxt, nSkillId, nArg3, nArg4, i, nArg5))
        {
            bFound = 1;
        }
    }

    if (bFound)
    {
        wsprintfA(szNumber, gszFormatD, nArg3);
        sub_00526320_ToUnicode(wszNumber, szNumber, 32);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x109E));
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    }

    if (!nSkillId && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwClassId == 6)
    {
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x5722));
    }

    D2SkillDescTxt* pSkillDescTxt = CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pSkillDescTxt ? 0x1506 : pSkillDescTxt->wStrShort));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));

    pSkillDescTxt = CLIENT_GetSkillDescTxtRecord(nSkillId);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(!pSkillDescTxt ? 0x1506 : pSkillDescTxt->wStrName));

    D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
    D2Win_10129_DrawFramedText(wszText, nX, nHeight + nY + 3, nArg5, 0);
}
