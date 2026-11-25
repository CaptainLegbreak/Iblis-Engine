#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2TxtItems.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Unicode.h"
#include "D2Txt.h"
#include "D2MonTypeTxt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2GemsTxt;
struct tagPALETTEENTRY;
union D2SeedStrc;
struct D2SkillsTxt;
struct D2StaticPathStrc;
struct D2MissileStrc;
struct Unicode;
struct D2ItemStatCostTxt;
struct D2CharStatsTxt;
struct D2MonStatsTxt;
struct D2MonTypeTxt;
struct D2CombinedStatStrc;
struct D2CombinedStatsStrc;
struct D2CombinedStatIdStrc;
struct D2FileIndexTextStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, int nLowSeed); // 0x00650E40
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
int __fastcall sub_0045C3E0(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
void __fastcall sub_004B9A00(int nId, D2UnitStrc* pUnit, int nArg3, int nArg4, int nArg5); // 0x004B9A00
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x00648810
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900






extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0
D2MonTypeTxt* __fastcall SKILLDESC_GetMonTypeTxtRecord(int nMonType); // 0x004E4640
void __fastcall TEXT_AppendUndeadDamageBonus(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused); // 0x004E48B0
unsigned short __fastcall SKILLDESC_GetSkillDescStringId(int nId, int nIndex); // 0x004E6CE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0
void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0
int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0
extern D2CombinedStatIdStrc gaCombinedStatIds[]; // 0x0072CDD0
extern D2FileIndexTextStrc gaFileIndexText[]; // 0x0072D6C0
extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634
void __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pUnit, Unicode* pOut, int nUnused, int bQuantity, int nState, int nState2, int nFlag, int bNewline); // 0x004E60A0
int __fastcall sub_00526800(const Unicode* wszText); // 0x00526800
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD
void __fastcall TEXT_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E6720
void __fastcall SKILLDESC_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, int nArg4); // 0x004E67D0
void __stdcall D2GFX_SetPalette(tagPALETTEENTRY* pPalette); // 0x004F63D0
int __stdcall PALETTE_LoadPaletteFiles(const char* szDatFileName, const char* szPL2FileName); // 0x004FB1E0
void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0
Unicode* __fastcall sub_00526E40_Utf8ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526E40
D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0
extern tagPALETTEENTRY gatRGBAPalette[]; // 0x0081E668

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
extern "C" const char szFmtD_006D57BC[]; // 0x006D57BC
extern "C" const char gszFmtRange[]; // 0x006D9D70
extern "C" const char gszFmtRangeKK[]; // 0x006DBEAC
extern "C" const char gszFmtRangeK[]; // 0x006DBEB8
extern int gnPanelOffsetX; // 0x007A2858
extern int gnPanelOffsetY; // 0x007A285C
extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
void __fastcall SKILLDESC_DrawTwoTexts(const Unicode* wszText1, const Unicode* wszText2, int nLeft, int nY, int nRight, int nColor1, int nColor2); // 0x004E9870
D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
int __cdecl SKILLDESC_SumProgressiveBonus(); // 0x004E6FF0
short __stdcall ITEMS_GetStrengthBonus(D2UnitStrc* pItem); // 0x00629860
short __stdcall ITEMS_GetDexBonus(D2UnitStrc* pItem); // 0x006298A0
int __stdcall STATES_CheckStateMaskDamBlueOnUnit(D2UnitStrc* pUnit); // 0x0063A380
int __stdcall STATES_CheckStateMaskDamRedOnUnit(D2UnitStrc* pUnit); // 0x0063A3A0
int __stdcall sub_004E89A0_GetElementalDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill); // 0x004E89A0
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId); // 0x00626070
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340
int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830
int __stdcall SKILLS_GetMinElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644D50
int __stdcall SKILLS_GetMaxElemDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyMastery); // 0x00644E40
int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20
static int __stdcall SKILLDESC_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill); // 0x004E8EC0

typedef int (__fastcall* SKILLWEAPONFN)(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem);

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0
unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40
D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem); // 0x0062A4E0
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
int __fastcall SKILLDESC_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem); // 0x004E8FE0

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static void __stdcall sub_004E49C0_CollectCombinedStats(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2CombinedStatsStrc* pCombined); // 0x004E49C0

static int __stdcall sub_004E5A20_BuildCombinedStatText(int nStatId, Unicode* pOut, D2CombinedStatsStrc* pCombined); // 0x004E5A20

// 0x004E2320
int __fastcall sub_004E2320_StartSkillRollParam(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

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

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, (!pUnit ? -1 : pUnit->dwUnitId) + (!pTarget ? -1 : pTarget->dwUnitId));

    const int nMin = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    const int nMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    int nValue = sub_0045C3E0(&tSeed, nMax - nMin) + nMin;
    if (nValue < 1)
    {
        nValue = 1;
    }

    SKILLS_SetParam1(pSkill, nValue);
    SKILLS_SetParam2(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    SKILLS_SetParam3(pSkill, pTarget->dwUnitType);
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

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
static int __stdcall SKILLDESC_GetStatDisplayValue(int nValue, D2ItemStatCostTxt* pRecord, D2UnitStrc* pUnit, int nStatId)
{
    if (pRecord->nOp >= 2 && pRecord->nOp <= 5)
    {
        const int nOpBase = pRecord->wOpBase;
        D2ItemStatCostTxt* pBase = (nOpBase >= 0 && nOpBase < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[nOpBase] : 0;
        if (!pBase)
            return 0;

        nValue = (STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), nOpBase, 0) >> pBase->nValShift) * nValue >> pRecord->nOpParam;
    }

    nValue >>= pRecord->nValShift;
    if (nStatId == 122 && pUnit && pUnit->dwUnitType == UNIT_ITEM && ITEMSIsA(pUnit, 57))
        nValue += 50;

    return nValue;
}

int __stdcall SKILLDESC_IsStatGroupUniform(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nValue, D2ItemStatCostTxt* pRecord, int* pIsSame)
{
    if (!pRecord->wDescGrp)
        return 0;

    for (int i = sgptDataTables->nItemStatCostTxtRecordCount - 1; i >= 0; --i)
    {
        D2ItemStatCostTxt* pOther = (i >= 0 && i < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[i] : 0;
        if (!pOther)
            return 0;

        if (pRecord->wDescGrp == pOther->wDescGrp)
        {
            *pIsSame = i == nStatId;
            const int nStat = STATLIST_GetStatValue(pStatList, i, 0);
            if (nValue != SKILLDESC_GetStatDisplayValue(nStat, pOther, pUnit, i))
                return 0;
        }
    }

    return 1;
}

// build: symbol ?SKILLDESC_BuildStatText@* 0x004E4D80
static int __stdcall SKILLDESC_BuildStatText(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nStatId, int nLayer, int nValue, Unicode* pOut)
{
    pOut[0] = 0;

    D2ItemStatCostTxt* pRecord = (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount) ? &sgptDataTables->pItemStatCostTxt[nStatId] : 0;
    if (!pRecord)
        return 0;

    int nDisplay = SKILLDESC_GetStatDisplayValue(nValue, pRecord, pUnit, nStatId);
    int bIsSame = 1;
    const int bUniform = SKILLDESC_IsStatGroupUniform(pUnit, pStatList, nStatId, nDisplay, pRecord, &bIsSame);
    if (bUniform && !bIsSame)
        return 0;

    int nDescFunc = pRecord->nDescFunc;
    int nDescVal = pRecord->nDescVal;
    unsigned short wDescStr2 = pRecord->wDescStr2;
    const Unicode* pText;
    if (bUniform)
    {
        nDescFunc = pRecord->nDescGrpFunc;
        nDescVal = pRecord->nDescGrpVal;
        wDescStr2 = pRecord->wDescGrpStr2;
        if (nDisplay >= 0)
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescGrpStrPos);
        else
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescGrpStrNeg);
    }
    else
    {
        if (nDisplay >= 0)
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescStrPos);
        else
            pText = D2LANG_GetStringFromTblIndex(pRecord->wDescStrNeg);
    }

    char szNumber[10];
// build: symbol ?gszFormatI@* 0x006D6454
    SStrPrintf(szNumber, 10, gszFormatI, nDisplay);
    Unicode wszNumber[10];
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);

    const Unicode* pPercent = D2LANG_GetStringFromTblIndex(0xFA1);
    const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pPlus = D2LANG_GetStringFromTblIndex(0xFA2);

    switch (nDescFunc)
    {
    case 1:
    case 6:
    case 12:
    {
        Unicode wszValue[256];
        wszValue[0] = 0;
        if (nDisplay > 0)
        {
            if (nDescFunc != 12 || nDisplay > 1)
            {
                sub_005267E0(wszValue, pPlus);
                sub_00526700(wszValue, wszNumber);
            }
        }
        else
        {
            sub_005267E0(wszValue, wszNumber);
        }

        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    case 4:
    case 8:
        if (nDescVal == 1)
        {
            if (nDisplay >= 0)
                sub_005267E0(pOut, pPlus);
            else
                pOut[0] = 0;
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            if (nDisplay >= 0)
                sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 20:
    case 21:
        nDisplay = -nDisplay;
        SStrPrintf(szNumber, 10, gszFormatI, nDisplay);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nDescVal == 1)
        {
            if (nDisplay >= 0)
                sub_005267E0(pOut, pPlus);
            else
                pOut[0] = 0;
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            if (nDisplay >= 0)
                sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 2:
    case 7:
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 3:
    case 9:
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 5:
    case 10:
        SStrPrintf(szNumber, 10, gszFormatI, nDisplay * 100 / 128);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }
        break;
    case 11:
        if (nDisplay > 0)
        {
            const int nRate = 2500 / nDisplay;
            if (nRate <= 30)
            {
                const Unicode* pFormat = D2LANG_GetStringFromTblIndex(0x52F9);
                sub_005269D0(128, pOut, pFormat, 1);
            }
            else
            {
                const Unicode* pFormat = D2LANG_GetStringFromTblIndex(0x52FA);
                sub_005269D0(128, pOut, pFormat, 1, (nRate + 12) / 25);
            }
        }
        else
        {
            const Unicode* pFormat = D2LANG_GetStringFromTblIndex(0x52F9);
            sub_005269D0(128, pOut, pFormat, 25);
        }
        break;
    case 13:
    {
        Unicode wszValue[256];
        wszValue[0] = 0;
        if (nDisplay > 0)
        {
            sub_005267E0(wszValue, pPlus);
            sub_00526700(wszValue, wszNumber);
        }
        else if (nDisplay < 0)
        {
            sub_005267E0(wszValue, wszNumber);
        }
        else
        {
            return 0;
        }

        D2CharStatsTxt* pCharStats = sub_004833E0_GetCharStatsTxtRecord(nLayer);
        if (!pCharStats)
            return 0;

        const Unicode* pAllSkills = D2LANG_GetStringFromTblIndex(pCharStats->wStrAllSkills);
        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pAllSkills);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pAllSkills);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    case 14:
    {
        const int nTab = nLayer & 7;
        D2CharStatsTxt* pCharStats = sub_004833E0_GetCharStatsTxtRecord(nLayer >> 3);
        if (!pCharStats)
            return 0;
        if (nTab < 0 || nTab > 2)
            return 0;

        sub_005269D0(256, pOut, D2LANG_GetStringFromTblIndex(pCharStats->wStrSkillTab[nTab]), nDisplay);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pCharStats->wStrClassOnly));
        break;
    }
    case 15:
    {
        const int nSkillId = nLayer >> sgptDataTables->nStuff;
        const int nLevel = nLayer & sgptDataTables->nShiftedStuff;
        if (nSkillId <= 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
            return 0;

        sub_005269D0(256, pOut, D2LANG_GetStringFromTblIndex(pRecord->wDescStrPos), nDisplay, 0, nLevel, D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStringId(nSkillId, 0)));
        break;
    }
    case 16:
    {
        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStringId(nLayer, 0));
        if (!pSkillName)
            return 0;

        sub_005269D0(256, pOut, pText, nDisplay, pSkillName);
        break;
    }
    case 17:
    case 18:
    {
        Unicode wszValue[256];
        wszValue[0] = 0;
        int nPeriodOfDay = 0;
        int nBaseTime = 0;
        if (gpGlobal_007A0634)
            nPeriodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(gpGlobal_007A0634, &nBaseTime);

        int nMin;
        int nMax;
        int nAmount = ITEMMODS_GetByTimeAdjustment(nDisplay, nPeriodOfDay, nBaseTime, &nPeriodOfDay, &nMin, &nMax);
        if (!gpGlobal_007A0634)
            nAmount = nMin;

        const int nPeriod = nPeriodOfDay > 0 ? nPeriodOfDay : 0;
        nPeriodOfDay = nPeriod < 3 ? nPeriod : 3;
// build: symbol ?gawPeriodOfDayStr@* 0x006DBD88
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(gawPeriodOfDayStr[nPeriodOfDay]));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9E));

        SStrPrintf(szNumber, 10, gszFormatI, nAmount);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nAmount >= 0)
        {
            sub_005267E0(wszValue, pPlus);
            sub_00526700(wszValue, wszNumber);
        }
        else if (nDisplay < 0)
        {
            sub_005267E0(wszValue, wszNumber);
        }

        if (nDescFunc == 18)
            sub_00526700(wszValue, pPercent);

        if (nDescVal == 1)
        {
            sub_00526700(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_00526700(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    case 19:
        sub_005269D0(256, pOut, pText, nDisplay);
        break;
    case 22:
    {
        if (nDescVal == 1)
        {
            if (nDisplay >= 0)
                sub_005267E0(pOut, pPlus);
            else
                pOut[0] = 0;
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            if (nDisplay >= 0)
                sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }

        D2MonTypeTxt* pMonType = SKILLDESC_GetMonTypeTxtRecord(nLayer);
        if (!pMonType)
            break;

        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9D));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pMonType->wStrPlur));
        break;
    }
    case 23:
    {
        D2MonStatsTxt* pMonStats = DATATBLS_GetMonStatsTxtRecord(nLayer);
        if (!pMonStats)
            return 0;

        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszNumber);
            sub_00526700(pOut, pPercent);
        }
        else
        {
            sub_005267E0(pOut, pText);
        }

        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xF9B));
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pMonStats->wNameStr));
        break;
    }
    case 24:
    {
        const int nSkillId = nLayer >> sgptDataTables->nStuff;
        const int nLevel = nLayer & sgptDataTables->nShiftedStuff;
        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStringId(nSkillId, 0));
        if (!pSkillName)
            break;

        Unicode wszValue[256];
        wszValue[0] = 0;
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0x5301));
        sub_00526700(pOut, pSpace);
        SStrPrintf(szNumber, 10, gszFormatI, nLevel);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        sub_00526700(pOut, wszNumber);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pSkillName);
        sub_00526700(pOut, pSpace);
        sub_005269D0(128, wszValue, pText, nDisplay & 0xFF, nDisplay >> 8);
        sub_00526700(pOut, wszValue);
        break;
    }
    case 25:
    case 26:
    {
        Unicode wszValue[256];
        nDisplay = -nDisplay;
        wszValue[0] = 0;
        if (nDisplay > 0)
        {
            sub_005267E0(wszValue, pPlus);
            sub_00526700(wszValue, wszNumber);
        }
        else
        {
            sub_005267E0(wszValue, wszNumber);
        }

        if (nDescVal == 1)
        {
            sub_005267E0(pOut, wszValue);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pText);
        }
        else if (nDescVal == 2)
        {
            sub_005267E0(pOut, pText);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, wszValue);
        }
        break;
    }
    case 27:
    {
        const Unicode* pTo = D2LANG_GetStringFromTblIndex(0xFA3);
        if (!pTo)
            break;
        if (!nDisplay)
            break;

        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStringId(nLayer, 0));
        if (!pSkillName)
            break;

        if (nDisplay > 0)
        {
            sub_00526700(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
        }
        else
        {
            sub_005267E0(pOut, wszNumber);
        }
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pTo);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pSkillName);
        sub_00526700(pOut, pSpace);

        int nCharClass = 7;
        if (!sub_00645080_GetSkillCharClass(nLayer, &nCharClass))
            break;
        if (nCharClass < 0 || nCharClass > 6)
            break;

        D2CharStatsTxt* pCharStats = sub_004833E0_GetCharStatsTxtRecord(nCharClass);
        if (!pCharStats)
            break;

        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(pCharStats->wStrClassOnly));
        break;
    }
    case 28:
    {
        if (!nDisplay)
            break;

        D2SkillsTxt* pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nLayer);
        if (!pSkillsTxt)
            break;

        D2UnitStrc* pPlayer = pUnit;
        if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
            pPlayer = sub_00463DD0_GetPlayerUnit();

        const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
        if (pSkillsTxt->nCharClass == nClass && nDisplay > 3)
            nDisplay = 3;

        const Unicode* pTo = D2LANG_GetStringFromTblIndex(0xFA3);
        if (!pTo)
            break;

        const Unicode* pSkillName = D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStringId(nLayer, 0));
        if (!pSkillName)
            break;

        SStrPrintf(szNumber, 10, gszFormatI, nDisplay);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (nDisplay > 0)
        {
            sub_005267E0(pOut, pPlus);
            sub_00526700(pOut, wszNumber);
        }
        else
        {
            sub_005267E0(pOut, wszNumber);
        }
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pTo);
        sub_00526700(pOut, pSpace);
        sub_00526700(pOut, pSkillName);
        break;
    }
    default:
        return 0;
    }

    if (nDescFunc >= 6 && (nDescFunc <= 10 || nDescFunc == 21))
    {
        if (wDescStr2 != 0x1506)
        {
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, D2LANG_GetStringFromTblIndex(wDescStr2));
        }
        else
        {
            const Unicode* pStr2 = D2LANG_GetStringFromTblIndex(0x2B53);
            sub_00526700(pOut, pSpace);
            sub_00526700(pOut, pStr2);
        }
    }

    return 1;
}

// build: symbol ?SKILLDESC_BuildFileIndexStatText@* 0x004E5E90
static void __stdcall SKILLDESC_BuildFileIndexStatText(D2UnitStrc* pUnit, Unicode* pOut, D2FileIndexTextStrc* pTable)
{
    Unicode wszLine[128];
    Unicode wszValue[128];
    const Unicode* pNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pPlus = D2LANG_GetStringFromTblIndex(0xFA2);
    const int nFileIndex = ITEMS_GetFileIndex(pUnit);

// build: symbol ?gnFileIndexTextCount@* 0x0072D720
    for (unsigned int i = 0; i < gnFileIndexTextCount; ++i, ++pTable)
    {
        if (pTable->nFileIndex != nFileIndex)
            continue;

        wszLine[0] = 0;
        wszValue[0] = 0;
        int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_VALUE, 0);
        const int nType = pTable->nFileIndex;
        if (nType == 8 || nType == 9)
            nValue >>= 8;
        if (nType == 6 || nType == 7)
            nValue >>= 8;
        if (nType == 10 || nType == 11)
            nValue >>= 8;

        const Unicode* pText = 0;
        if (nValue > 0)
            pText = D2LANG_GetStringFromTblIndex(pTable->wStrPos);
        else if (nValue < 0)
            pText = D2LANG_GetStringFromTblIndex(pTable->wStrNeg);

        if (!nValue)
            continue;

        Unicode wszNumber[10];
        char szNumber[10];
        SStrPrintf(szNumber, 10, gszFormatI, nValue);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);

        switch (pTable->nMode)
        {
        case 1:
            if (nValue > 0)
            {
                sub_005267E0(wszValue, pPlus);
                sub_00526700(wszValue, wszNumber);
            }
            else
            {
                sub_005267E0(wszValue, wszNumber);
            }

            switch (gaFileIndexText[i].nPos)
            {
            case 2:
                sub_005267E0(wszLine, pText);
                sub_00526700(wszLine, pSpace);
                sub_00526700(wszLine, wszValue);
                sub_00526700(wszLine, pNewline);
                sub_00526700(pOut, wszLine);
                break;
            default:
                D2_ASSERT(0, 0x13D);
                break;
            }
            break;
        default:
            D2_ASSERT(0, 0x141);
            break;
        }
    }
}


struct D2UnitStrc;

// 0x004FB480
int __fastcall D2Win_10177(unsigned char nAct)
{
    int nActNo = nAct + 1;
    if (nActNo < 1 || nActNo > 5)
        nActNo = 1;

    char szPL2Filename[260];
    char szDatFilename[260];
// build: symbol ?gszDataGlobal@* 0x006D4118
    sprintf(szDatFilename, "%s\\palette\\act%d\\%s", gszDataGlobal, nActNo, "pal.dat");
    sprintf(szPL2Filename, "%s\\palette\\act%d\\%s", gszDataGlobal, nActNo, "pal.pl2");
    const int nResult = PALETTE_LoadPaletteFiles(szDatFilename, szPL2Filename);
    D2GFX_SetPalette(gatRGBAPalette);
    return nResult;
}

// 0x004FCFF0
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nColor)
{
    Unicode wszText[1024];
    for (int i = 0; i < 1024; ++i)
        wszText[i].wChar = 0;

    D2_ASSERT(pTextBox, 0x11E);
    sub_00526E40_Utf8ToUnicode(wszText, szText, 1024);
    sub_004FC9B0_SetText(pTextBox, wszText, nColor, 0, 0);
}

// 0x004E6FB0
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

static inline int SDPHYS_TestFlag(const unsigned char* pFlags, int nBit)
{
    return pFlags[nBit >> 3] & gdwBitMasks_006CE268[nBit & 7];
}

// 0x004E86F0
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
        DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
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
    if (SDPHYS_TestFlag(pSkillsTxt->nFlags, 3))
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

// 0x004E9660
static void __stdcall SKILLDESC_AddScaledWeaponDamage(D2UnitStrc* pUnit, int* pMinDamage, int* pMaxDamage, int* pColor, D2SkillStrc* pSkill, D2UnitStrc* pItem, int nRatio)
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

// 0x004E8D90
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

// 0x004E96E0
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
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + nY - 480, gnPanelOffsetX + nRight, wszText, nColor);
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
    SKILLDESC_AddScaledWeaponDamage(pUnit, &nWeaponMin, &nWeaponMax, &nWeaponColor, pSkill, 0, pSkillsTxt->nSrcDam);
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
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nWeaponMin + 500) / 1000, (nWeaponMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nWeaponMin, (nWeaponMax + 500) / 1000);
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
        wsprintfA(szText, gszFmtRangeKK, &gszEmptyAssertText, (nMin + 500) / 1000, (nMax + 500) / 1000);
    }
    else
    {
        wsprintfA(szText, gszFmtRangeK, &gszEmptyAssertText, nMin, (nMax + 500) / 1000);
    }
    sub_00526320_ToUnicode(wszText2, szText, 32);
    SKILLDESC_DrawTwoTexts(wszText1, wszText2, nLeft, nY, nRight, nWeaponColor, nColor);
}

static int __stdcall SKILLDESC_GetAttackRatingValues(D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pValue1, int* pValue2, int nLevel, D2SkillStrc* pSkill)
{
    if (!pUnit || !pSkill)
        return 0;

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
        return 0;

    *pValue2 = 0;
    *pValue1 = UNITS_GetAttackRate(pUnit);
    if (!pItem && pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);

    if (pItem && ITEMS_GetItemType(pItem) == ITEMTYPE_MISSILE_POTION)
    {
        *pValue1 = 0;
        *pValue2 = 0;
    }

    int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pItem, pSkill, 0);
    nBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_TOHIT_PERCENT, 0);
    nBonus += SKILLS_GetToHitFactor(pUnit, pSkillsTxt->nSkillId, nLevel);
    if (pSkillsTxt->nFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        int nProgressive = STATLIST_UnitGetStatValue(pUnit, STAT_PROGRESSIVE_TOHIT, 0);
        if (nProgressive)
        {
            nBonus += nProgressive;
            *pValue2 = 3;
        }
    }
    *pValue1 += *pValue1 * nBonus / 100;

    if (STATES_CheckStateMaskAttBlueOnUnit(pUnit))
        *pValue2 = 3;
    if (STATES_CheckStateMaskAttRedOnUnit(pUnit))
        *pValue2 = 1;
    return 1;
}

int __fastcall SKILLDESC_AttackRatingCallback(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int nArg3, int nArg4, int nLevel, D2SkillStrc* pSkill, int nArg7, D2UnitStrc* pItem)
{
    return SKILLDESC_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}

// 0x004E9000
void __fastcall sub_004E9000_SkillDescAttackRatingMain(D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2SkillsTxt* pSkillsTxt, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    D2UnitStrc* pItem = 0;
    if (pUnit->pInventory)
        pItem = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    *pValue1 = 0;
    *pValue2 = 0;
    SKILLDESC_GetAttackRatingValues(pUnit, pItem, pValue1, pValue2, nLevel, pSkill);
}

// build: symbol ?SKILLDESC_MergeOtherHandWeapon@@YAPAUD2UnitStrc@@PAU1@@Z 0x004E9260
static D2UnitStrc* SKILLDESC_MergeOtherHandWeapon(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (!pOther || pOther == pWeapon)
        return 0;

    if (!ITEMSIsA(pOther, 45))
        return 0;

    if (!ITEMS_CanBeEquipped(pWeapon) || !ITEMS_CanBeEquipped(pOther))
        return 0;

    if (STATLIST_GetOwner(pWeapon, 0))
        STATLIST_MergeStatLists(pUnit, pWeapon, 0);
    if (STATLIST_GetOwner(pOther, 0))
        STATLIST_MergeStatLists(pUnit, pOther, 1);
    return pOther;
}

static __forceinline D2UnitStrc* sub_P03_MergeLeftWeaponOnly(D2UnitStrc* pUnit, D2UnitStrc* pWeapon)
{
    if (ITEMS_CanBeEquipped(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    return pWeapon;
}

// 0x004E9300
static D2UnitStrc* sub_004E9300_MergeWeaponPair(D2UnitStrc* pUnit)
{
    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (!pWeapon)
        return 0;

    int nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
    D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc == 4 ? 5 : 4);
    if (!pOther || pOther == pWeapon)
        return sub_P03_MergeLeftWeaponOnly(pUnit, pWeapon);

    if (!ITEMSIsA(pOther, 45))
        return sub_P03_MergeLeftWeaponOnly(pUnit, pWeapon);

    if (!ITEMS_CanBeEquipped(pWeapon) || !ITEMS_CanBeEquipped(pOther))
        return sub_P03_MergeLeftWeaponOnly(pUnit, pWeapon);

    STATLIST_MergeStatLists(pUnit, pOther, 0);
    STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    return pWeapon;
}

// build: symbol ?SKILLDESC_EvaluateForEachWeapon@* 0x004E93A0
static int __stdcall SKILLDESC_EvaluateForEachWeapon(int* pValue1, int* pValue2, int nArg3, int* pValue3, int* pValue4, int nArg6, D2SkillStrc* pSkill, SKILLWEAPONFN pfnEvaluate, int nArg9, D2UnitStrc* pUnit, int nLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return 0;

    if (!UNITS_CanDualWield(pUnit))
        return 0;

    D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    if (!ITEMS_CanBeEquipped(pRight) || ITEMSIsA(pRight, 0x26))
        pRight = 0;

    D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (!ITEMS_CanBeEquipped(pLeft) || ITEMSIsA(pLeft, 0x26))
        pLeft = 0;

    if (pRight && pLeft)
    {
        D2UnitStrc* pItem = SKILLDESC_MergeOtherHandWeapon(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue3, pValue4, nArg6, nArg9, nLevel, pSkill, 0, pItem);
        }
        else
        {
            *pValue3 = 0;
            *pValue4 = 0;
        }

        pItem = sub_004E9300_MergeWeaponPair(pUnit);
        if (pItem)
        {
            pfnEvaluate(pUnit, pValue1, pValue2, nArg3, nArg9, nLevel, pSkill, 0, pItem);
        }
        else
        {
            *pValue1 = 0;
            *pValue2 = 0;
        }
        return 1;
    }

    D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (pWeapon && ITEMS_CanBeEquipped(pWeapon))
        STATLIST_MergeStatLists(pUnit, pWeapon, 1);
    pfnEvaluate(pUnit, pValue1, pValue2, nArg3, nArg9, nLevel, pSkill, 0, 0);
    return 1;
}

static int __stdcall SKILLDESC_AttackRatingForEachWeapon(D2UnitStrc* pUnit, int* pValue1, int* pValue2, int* pValue3, int* pValue4, D2SkillStrc* pSkill, int nLevel)
{
    return SKILLDESC_EvaluateForEachWeapon(pValue1, pValue2, 0, pValue3, pValue4, 0, pSkill, SKILLDESC_AttackRatingCallback, 0, pUnit, nLevel);
}

void __fastcall sub_P03_Emit_004E9510(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nLevel, int* pValue1, int* pValue2, int* pValue3, int* pValue4)
{
    if (UNITS_CanDualWield(pUnit))
    {
        SKILLDESC_AttackRatingForEachWeapon(pUnit, pValue1, pValue2, pValue3, pValue4, pSkill, nLevel);
        return;
    }

    SKILLDESC_EvaluateForEachWeapon(pValue1, pValue2, 0, pValue3, pValue4, 0, pSkill, SKILLDESC_AttackRatingCallback, 0, pUnit, nLevel);
}

// 0x004E9940
static void __stdcall sub_004E9940_DrawNumberCentered(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    Unicode wszText[32];
    char szText[32];
    wsprintfA(szText, szFmtD_006D57BC, nValue);
    sub_00526320_ToUnicode(wszText, szText, 32);
    if (nValue < 1000)
    {
        D2Win_10127_SetFont(1);
    }
    else
    {
        D2Win_10127_SetFont(0);
    }
    TEXT_DrawCenteredText(gnPanelOffsetX + nLeft, gnScreenHeight + gnPanelOffsetY + nY - 480,
                            gnPanelOffsetX + nRight, wszText, nColor);
}

void sub_I08_Emit_004E9940(int nColor, int nLeft, int nY, int nRight, int nValue)
{
    sub_004E9940_DrawNumberCentered(nColor, nLeft, nY, nRight, nValue);
}
