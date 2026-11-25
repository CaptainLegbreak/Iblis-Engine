#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Unicode.h"
#include "D2StateIds.h"
#include "D2Records.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2GameTypes.h"
#include "D2SkillIds.h"
#include "D2SoundEnvironTxt.h"
#include "D2MonTypeTxt.h"
#include "D2MonsterIds.h"
#include "D2MissileIds.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2TxtItems.h"
#include "D2ClientTypes.h"
#include "D2StormTypes.h"
#include "D2Primitives.h"
#include "D2ClientUi.h"
#include "D2CelContext.h"
#include "D2MsgRecord.h"
#include "D2ClientQuestLog.h"
#include "D2ClientStatButton.h"
#include "D2WinSplitText.h"
#include "D2TextIdEntry.h"
#include "D2ClientTextBox.h"
#include "D2ClientQuestText.h"
#include "D2ClientKeyConfig.h"
#include "D2ClientGame.h"
#include "D2Win32Types.h"
#include "D2ItemsWorld.h"
#include "D2MultiTypes.h"
#include "D2WaypointActRange.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2ClientGfx.h"
#include "D2LevelIds.h"




unsigned short __fastcall SKILLDESC_GetSkillDescStringId(int skillId, int stringIndex); // 0x004E6CE0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700
Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0
int __stdcall SKILLS_IsPlayerClassSkill(int nSkillId, int* pPlayerClass); // 0x00645080
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static inline D2CharStatsTxt* sub_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

extern D2CombinedStatIdStrc gaCombinedStatIds[]; // 0x0072CDD0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0

extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

D2MonTypeTxt* __fastcall SKILLDESC_GetMonTypeTxtRecord(int nMonType); // 0x004E4640

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

extern D2DrlgActStrc* gpAct; // 0x007A0634

struct D2MonTypeTxt;


extern const int gaSetMaskToBonusMappingTable[0x40]; // 0x006DBD90

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern D2FileIndexTextStrc gaFileIndexText[]; // 0x0072D6C0

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char gszEmptyAssertText; // 0x006CC837

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag); // 0x006257D0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __fastcall sub_00526800(const Unicode* wszText); // 0x00526800

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062A490

unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370

int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem); // 0x0062B3A0

extern int gaSetPartialCounts_006DBD90[]; // 0x006DBD90

struct D2SetItemsTxt;

inline D2SetItemsTxt* ITEMS_GetSetItemsTxtRecordInline(D2UnitStrc* pItem)
{
    int nFileIndex = ITEMS_GetFileIndex(pItem);
    if (nFileIndex >= 0 && nFileIndex < sgptDataTables->nSetItemsTxtRecordCount)
    {
        return &sgptDataTables->pSetItemsTxt[nFileIndex];
    }

    return 0;
}

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall ITEMMODS_AssignProperty(int nPass, int nArg1, D2UnitStrc* pItem, int nArg, int nArg2, int nArg5); // 0x0065FEC0

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

struct D2GemsTxt;

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530

// 0x004E4670
void __fastcall sub_004E4670_BuildSkillBonusText(D2UnitStrc* pUnit, Unicode* pBuffer, int a3, int a4, int nStatId)
{
    D2StatStrc tStats[128];
    unsigned short wszLine[128];
    unsigned short wszValue[128];
    char szNum[10];
    unsigned short wszNum[10];

    for (int j = 0; j < 128; ++j)
    {
        wszLine[j] = 0;
    }
    for (int j = 0; j < 128; ++j)
    {
        wszValue[j] = 0;
    }

    const Unicode* wszNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* wszPlus = D2LANG_GetStringFromTblIndex(0xFA2);
    const Unicode* wszTo = D2LANG_GetStringFromTblIndex(0xFA3);
    const Unicode* wszSpace = D2LANG_GetStringFromTblIndex(0xF9B);

    const int nCount = STATLIST_CopyStats(pUnit, nStatId, tStats, 128);
    for (int i = 0; i < nCount; ++i)
    {
        wszLine[0] = 0;
        wszValue[0] = 0;
        const int nSkillId = tStats[i].nLayer;
        const int nValue = tStats[i].nValue;

        const Unicode* wszSkillName = D2LANG_GetStringFromTblIndex(SKILLDESC_GetSkillDescStringId(nSkillId, 0));
        wszNum[0] = 0;
        wszNum[1] = 0;
        wszNum[2] = 0;
        wszNum[3] = 0;
        wszNum[4] = 0;
        wszNum[5] = 0;
        wszNum[6] = 0;
        wszNum[7] = 0;
        wszNum[8] = 0;
        wszNum[9] = 0;
        SStrPrintf(szNum, 10, "%i", nValue);
        sub_00526320_ToUnicode((Unicode*)wszNum, szNum, 9);

        if (nValue > 0)
        {
            sub_005267E0((Unicode*)wszValue, wszPlus);
            sub_00526700((Unicode*)wszValue, (Unicode*)wszNum);
        }
        else
        {
            sub_005267E0((Unicode*)wszValue, (Unicode*)wszNum);
        }

        sub_005267E0((Unicode*)wszLine, (Unicode*)wszValue);
        sub_00526700((Unicode*)wszLine, wszSpace);
        sub_00526700((Unicode*)wszLine, wszTo);
        sub_00526700((Unicode*)wszLine, wszSpace);
        sub_00526700((Unicode*)wszLine, wszSkillName);

        if (nStatId == 0x6B)
        {
            sub_00526700((Unicode*)wszLine, wszSpace);
            int nClass = 7;
            if (SKILLS_IsPlayerClassSkill(nSkillId, &nClass))
            {
                if (nClass < 0 || nClass >= 7)
                {
                    sub_00526700((Unicode*)wszLine, wszNewLine);
                    sub_00526700(pBuffer, (Unicode*)wszLine);
                    return;
                }

                D2CharStatsTxt* pCharStatsTxt = sub_GetCharStatsTxtRecord(nClass);
                if (!pCharStatsTxt)
                {
                    sub_00526700((Unicode*)wszLine, wszNewLine);
                    sub_00526700(pBuffer, (Unicode*)wszLine);
                    return;
                }

                sub_00526700((Unicode*)wszLine, D2LANG_GetStringFromTblIndex(pCharStatsTxt->wStrClassOnly));
            }
        }

        sub_00526700((Unicode*)wszLine, wszNewLine);
        sub_00526700(pBuffer, (Unicode*)wszLine);
    }
}

// 0x004E48B0
void __fastcall TEXT_AppendUndeadDamageBonus(D2UnitStrc* pUnused, Unicode* wszOut, int nUnused)
{
    Unicode wszText[0x80];
    const Unicode* wszA = D2LANG_GetStringFromTblIndex(0xFA2);
    const Unicode* wszB = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* wszC = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* wszD = D2LANG_GetStringFromTblIndex(0xFA1);
    Unicode wszNumber[10];
    char szNumber[10];
// build: symbol ?gszFormatI@* 0x006D6454
    SStrPrintf(szNumber, 10, gszFormatI, 0x32);
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszA);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszD);
    sub_00526700(wszText, wszC);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xDE2));
    sub_00526700(wszText, wszB);
    sub_00526700(wszOut, wszText);
}

// 0x004E49C0
static void __stdcall sub_004E49C0_CollectCombinedStats(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2CombinedStatsStrc* pCombined)
{
    memset(pCombined, 0, sizeof(D2CombinedStatsStrc));

// build: symbol ?gnCombinedStatCount@* 0x0072CDCC
    for (int i = 0; i < gnCombinedStatCount; ++i)
    {
        const int nStatId = gaCombinedStatIds[i].nStatId;
        if (nStatId == -1)
            continue;

        switch (nStatId)
        {
        case 48:
            pCombined->tFire.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 49:
            pCombined->tFire.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 50:
            pCombined->tLightning.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 51:
            pCombined->tLightning.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 52:
            pCombined->tMagic.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 53:
            pCombined->tMagic.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 54:
            pCombined->tCold.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 55:
            pCombined->tCold.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 57:
            pCombined->tPoison.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 58:
            pCombined->tPoison.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 59:
            pCombined->tPoison.nLength = STATLIST_GetStatValue(pStatList, nStatId, 0);
            pCombined->tPoison.nCount = STATLIST_UnitGetStatValue(pUnit, STAT_POISON_COUNT, 0);
            break;
        case 21:
            pCombined->tDamage.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            if (!pCombined->tDamage.nMin)
                pCombined->tDamage.nMin = STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MINDAMAGE, 0);
            break;
        case 22:
            pCombined->tDamage.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            if (!pCombined->tDamage.nMax)
                pCombined->tDamage.nMax = STATLIST_GetStatValue(pStatList, STAT_SECONDARY_MAXDAMAGE, 0);
            break;
        case 18:
            pCombined->tDamagePercent.nMin = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        case 17:
            pCombined->tDamagePercent.nMax = STATLIST_GetStatValue(pStatList, nStatId, 0);
            break;
        }
    }

    if (pCombined->tDamage.nMin > 0 && pCombined->tDamage.nMax > 0)
        pCombined->tDamage.bCombined = 1;
    if (pCombined->tDamagePercent.nMin > 0 && pCombined->tDamagePercent.nMax > 0)
        pCombined->tDamagePercent.bCombined = 1;
    if (pCombined->tCold.nMin > 0 && pCombined->tCold.nMax > 0)
        pCombined->tCold.bCombined = 1;
    if (pCombined->tLightning.nMin > 0 && pCombined->tLightning.nMax > 0)
        pCombined->tLightning.bCombined = 1;
    if (pCombined->tFire.nMin > 0 && pCombined->tFire.nMax > 0)
        pCombined->tFire.bCombined = 1;
    if (pCombined->tPoison.nMin > 0 && pCombined->tPoison.nMax > 0)
        pCombined->tPoison.bCombined = 1;
    if (pCombined->tMagic.nMin > 0 && pCombined->tMagic.nMax > 0)
        pCombined->tMagic.bCombined = 1;
}

// 0x004E4C50
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

// 0x004E4CE0
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

// 0x004E4D80
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
        if (gpAct)
            nPeriodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(gpAct, &nBaseTime);

        int nMin;
        int nMax;
        int nAmount = ITEMMODS_GetByTimeAdjustment(nDisplay, nPeriodOfDay, nBaseTime, &nPeriodOfDay, &nMin, &nMax);
        if (!gpAct)
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
    {
    int nCharClass;
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

        nCharClass = 7;
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

        D2SkillsTxt*& pSkillsTxt = (D2SkillsTxt*&)nCharClass;
        pSkillsTxt = sub_0045C4B0_GetSkillsTxtRecord(nLayer);
        if (!pSkillsTxt)
            break;

        D2UnitStrc* pPlayer = pUnit;
        if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
            pPlayer = sub_00463DD0_GetPlayerUnit();

        const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
        if (pSkillsTxt->nCharClass == nClass && nDisplay > 3)
            nDisplay = 3;

        const Unicode*& pTo = (const Unicode*&)nCharClass;
        pTo = D2LANG_GetStringFromTblIndex(0xFA3);
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

// 0x004E5A10
static int SKILLDESC_GetSetBonusCount(unsigned int nSetItemMask)
{
    if (nSetItemMask >= sizeof(gaSetMaskToBonusMappingTable) / sizeof(gaSetMaskToBonusMappingTable[0]))
        return 0;
    return gaSetMaskToBonusMappingTable[nSetItemMask];
}

void __fastcall sub_004E5A10_UseBonusCount(int nCount);

void __stdcall sub_004E5A10_Emit(int nUnused, unsigned int nSetItemMask)
{
    sub_004E5A10_UseBonusCount(SKILLDESC_GetSetBonusCount(nSetItemMask));
}


// 0x004E5A20
static int __stdcall sub_004E5A20_BuildCombinedStatText(int nStatId, Unicode* pOut, D2CombinedStatsStrc* pCombined)
{
    Unicode wszText[256];
    memset(wszText, 0, sizeof(wszText));

    int bAppend = 0;
    switch (nStatId)
    {
    case 49:
        return pCombined->tFire.bCombined;
    case 55:
        return pCombined->tCold.bCombined;
    case 51:
        return pCombined->tLightning.bCombined;
    case 53:
        return pCombined->tMagic.bCombined;
    case 58:
    case 59:
        return pCombined->tPoison.bCombined;
    case 17:
        return pCombined->tDamagePercent.bCombined;
    case 48:
        if (!pCombined->tFire.bCombined)
            return 0;
        if (pCombined->tFire.nMin >= pCombined->tFire.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1C), pCombined->tFire.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1D), pCombined->tFire.nMin, pCombined->tFire.nMax);
        bAppend = 1;
        break;
    case 54:
        if (!pCombined->tCold.bCombined)
            return 0;
        if (pCombined->tCold.nMin >= pCombined->tCold.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1E), pCombined->tCold.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE1F), pCombined->tCold.nMin, pCombined->tCold.nMax);
        bAppend = 1;
        break;
    case 50:
        if (!pCombined->tLightning.bCombined)
            return 0;
        if (pCombined->tLightning.nMin >= pCombined->tLightning.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE20), pCombined->tLightning.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE21), pCombined->tLightning.nMin, pCombined->tLightning.nMax);
        bAppend = 1;
        break;
    case 52:
        if (!pCombined->tMagic.bCombined)
            return 0;
        if (pCombined->tMagic.nMin >= pCombined->tMagic.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE22), pCombined->tMagic.nMax);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE23), pCombined->tMagic.nMin, pCombined->tMagic.nMax);
        bAppend = 1;
        break;
    case 57:
        if (!pCombined->tPoison.bCombined)
            return 0;
        if (pCombined->tPoison.nCount <= 0)
            pCombined->tPoison.nCount = 1;
        pCombined->tPoison.nLength /= pCombined->tPoison.nCount;
        pCombined->tPoison.nMin = (pCombined->tPoison.nMin * pCombined->tPoison.nLength + 0x80) >> 8;
        pCombined->tPoison.nMax = (pCombined->tPoison.nMax * pCombined->tPoison.nLength + 0x80) >> 8;
        if (pCombined->tPoison.nMin >= pCombined->tPoison.nMax)
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE24), pCombined->tPoison.nMax, pCombined->tPoison.nLength / 25);
        else
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE25), pCombined->tPoison.nMin, pCombined->tPoison.nMax, pCombined->tPoison.nLength / 25);
        bAppend = 1;
        break;
    case 24:
        if (pCombined->tDamage.bShown)
            return 1;
        return pCombined->tDamage.bCombined;
    case 21:
    case 22:
    case 23:
        if (!pCombined->tDamage.bShown)
        {
            if (!pCombined->tDamage.bCombined)
                return 0;
            if (pCombined->tDamage.nMin >= pCombined->tDamage.nMax)
            {
                pCombined->tDamage.bShown = 0;
                pCombined->tDamage.bCombined = 0;
                return 0;
            }
            pCombined->tDamage.bShown = 1;
            sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(0xE27), pCombined->tDamage.nMin, pCombined->tDamage.nMax);
        }
        bAppend = 1;
        break;
    case 18:
    {
        const Unicode* pPercent = D2LANG_GetStringFromTblIndex(0xFA1);
        const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
        const Unicode* pPlus = D2LANG_GetStringFromTblIndex(0xFA2);
        Unicode wszNumber[10];
        char szNumber[10];
        SStrPrintf(szNumber, 10, gszFormatI, pCombined->tDamagePercent.nMin);
        sub_00526320_ToUnicode(wszNumber, szNumber, 9);
        if (!pCombined->tDamagePercent.bCombined)
            return 0;

        sub_005267E0(wszText, pPlus);
        sub_00526700(wszText, wszNumber);
        sub_00526700(wszText, pPercent);
        sub_00526700(wszText, pSpace);
        sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x2727));
        bAppend = 1;
        break;
    }
    }

    if (bAppend)
        sub_00526700(pOut, wszText);

    return bAppend;
}

// 0x004E5E90
static void __stdcall SKILLDESC_BuildFileIndexStatText(D2UnitStrc* pUnit, Unicode* pOut, D2FileIndexTextStrc* pTable)
{
    struct
    {
        int nDelta;
        const Unicode* pPlus;
        const Unicode* pNewline;
        int nFileIndex;
        const Unicode* pSpace;
    } tLocals;
    struct
    {
        Unicode wszLine[128];
        Unicode wszValue[128];
    } tText;
    tLocals.pNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    tLocals.pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    tLocals.pPlus = D2LANG_GetStringFromTblIndex(0xFA2);
    tLocals.nFileIndex = ITEMS_GetFileIndex(pUnit);

    unsigned int i = 0;
// build: symbol ?gnFileIndexTextCount@* 0x0072D720
    if (i < gnFileIndexTextCount)
    {
        tLocals.nDelta = (char*)&gaFileIndexText[0].nPos - (char*)pTable;
        do
        {
            if (pTable->nFileIndex == tLocals.nFileIndex)
            {
                tText.wszLine[0] = 0;
                tText.wszValue[0] = 0;
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

                if (nValue)
                {
                    Unicode wszNumber[10];
                    char szNumber[10];
                    SStrPrintf(szNumber, 10, gszFormatI, nValue);
                    sub_00526320_ToUnicode(wszNumber, szNumber, 9);

                    switch (pTable->nMode)
                    {
                    case 1:
                        if (nValue > 0)
                        {
                            sub_005267E0(tText.wszValue, tLocals.pPlus);
                            sub_00526700(tText.wszValue, wszNumber);
                        }
                        else
                        {
                            sub_005267E0(tText.wszValue, wszNumber);
                        }

                        if (*(int*)((char*)pTable + tLocals.nDelta) == 2)
                        {
                            sub_005267E0(tText.wszLine, pText);
                            sub_00526700(tText.wszLine, tLocals.pSpace);
                            sub_00526700(tText.wszLine, tText.wszValue);
                            sub_00526700(tText.wszLine, tLocals.pNewline);
                            sub_00526700(pOut, tText.wszLine);
                        }
                        else
                        {
                            D2_ASSERT(0, 0x13D);
                        }
                        break;
                    default:
                        D2_ASSERT(0, 0x141);
                        break;
                    }
                }
            }
        }
        while (++pTable, ++i < gnFileIndexTextCount);
    }
}

// 0x004E60A0
void __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pUnit, Unicode* pOut, int nUnused, int bQuantity, int nState, int nState2, int nFlag, int bNewline)
{
    Unicode wszLine[128];
    Unicode wszQuantity[128];
    D2CombinedStatsStrc tCombined;
    D2StatStrc aStats[511];

    if (ITEMS_GetItemType(pUnit) == ITEMTYPE_ELIXIR)
    {
        SKILLDESC_BuildFileIndexStatText(pUnit, pOut, gaFileIndexText);
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, nState, nFlag);
    if (!pStatList)
        return;

    D2StatListStrc* pMerged = STATLIST_AllocStatList(!pUnit ? 0 : pUnit->pMemoryPool, 0, 0, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    STATLIST_MergeBaseStats(pMerged, pStatList);
    if (nState2)
    {
        D2StatListStrc* pExtra = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, nState2, nFlag);
        if (pExtra)
            STATLIST_MergeBaseStats(pMerged, pExtra);
    }

    if (pUnit && pUnit->dwUnitType == UNIT_ITEM && pUnit->pInventory)
    {
        D2UnitStrc* pSocketed = INVENTORY_GetFirstItem(pUnit->pInventory);
        while (pSocketed)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pSocketed);
            if (!pItem)
                break;

            pSocketed = INVENTORY_GetNextItem(pSocketed);
            D2StatListStrc* pItemStats = STATLIST_GetStatListFromUnitStateAndFlag(pItem, nState, nFlag);
            if (pItemStats)
                STATLIST_MergeBaseStats(pMerged, pItemStats);
        }
    }

    const Unicode* pNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* pSpace = D2LANG_GetStringFromTblIndex(0xF9B);
    const Unicode* pComma = D2LANG_GetStringFromTblIndex(0xF0C);

    if (bQuantity && ITEMSIsA(pUnit, 57) && !STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0))
    {
        TEXT_AppendUndeadDamageBonus(pUnit, wszQuantity, 128);
        sub_00526700(pOut, wszQuantity);
    }

    sub_004E49C0_CollectCombinedStats(pUnit, pMerged, &tCombined);

    int bAdded = 0;
    for (int i = 0; i < sgptDataTables->nStatsWithDescFunc; ++i)
    {
        const int nStatId = sgptDataTables->pStatsWithDescFunc[i];
        if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            continue;

        const int nCount = D2COMMON_11269_CopyStats(pMerged, nStatId, aStats, 511);
        for (int j = 0; j < nCount; ++j)
        {
            const int nValue = aStats[j].nValue;
            const int nLayer = aStats[j].nLayer;
            if (!nValue)
                continue;

            if (sub_004E5A20_BuildCombinedStatText(nStatId, pOut, &tCombined))
                continue;

            if (!SKILLDESC_BuildStatText(pUnit, pMerged, nStatId, nLayer, nValue, wszLine))
                continue;

            switch (nStatId)
            {
            case 23:
                if (STATLIST_GetStatValue(pMerged, STAT_MINDAMAGE, 0))
                    continue;
                break;
            case 24:
                if (STATLIST_GetStatValue(pMerged, STAT_MAXDAMAGE, 0))
                    continue;
                break;
            }

            if (bNewline)
                sub_00526700(wszLine, pNewline);

            if (bAdded && !bNewline)
            {
                sub_00526700(pOut, pComma);
                sub_00526700(pOut, pSpace);
            }

            bAdded = 1;
            sub_00526700(pOut, wszLine);
        }
    }

    if (pUnit && pUnit->dwUnitType == UNIT_ITEM)
    {
        const int nClassId = pUnit->dwClassId;
        D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nClassId);
        if (!pItemsTxt->nNoDurability && pItemsTxt->nDurability && STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_INDESCTRUCTIBLE, 0) <= 0 && !STATLIST_GetMaxDurabilityFromUnit(pUnit))
        {
            const Unicode* pIndestructible = D2LANG_GetStringFromTblIndex(0x52F8);
            if (bAdded && !bNewline)
            {
                sub_00526700(pOut, pComma);
                sub_00526700(pOut, pSpace);
            }

            sub_00526700(pOut, pIndestructible);
            if (bNewline)
                sub_00526700(pOut, pNewline);
        }
    }

    STATLIST_FreeStatList(pMerged);
}

// 0x004E6410
void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra)
{
    Unicode wszBuffer[1024];
    wszBuffer[0] = 0;
    sub_004E60A0_AddSetPropText(pItem, wszBuffer, 1024, 1, 0, 0xAB, 0x40, bFlag);
    if (!wszExtra)
    {
        sub_00526700(wszText, wszBuffer);
        return;
    }

    const int nLength = sub_00526800(wszBuffer);
    if (!nLength)
    {
        sub_00526700(wszText, wszBuffer);
        return;
    }

    int i = nLength - 2;
    while (i > 0)
    {
        if (wszBuffer[i].wChar == 10)
            break;
        --i;
    }

    if (i <= 0)
    {
        sub_00526700(wszText, wszExtra);
        sub_00526700(wszText, wszBuffer);
        return;
    }

    const Unicode* wszNewLine = D2LANG_GetStringFromTblIndex(0xF9E);
    const Unicode* wszSuffix = D2LANG_GetStringFromTblIndex(0xF0C);
    wszBuffer[i] = 0;
    sub_00526700(wszText, wszBuffer);
    sub_00526700(wszText, wszNewLine);
    sub_00526700(wszText, wszExtra);
    if (wszBuffer[nLength - 1].wChar == 10)
    {
        wszBuffer[nLength - 1] = 0;
    }
    sub_00526700(wszText, &wszBuffer[i + 1]);
    sub_00526700(wszText, wszSuffix);
    sub_00526700(wszText, wszNewLine);
}

// 0x004E6560
void __fastcall WARDENCLIENT_SetItemPropTexts(D2UnitStrc* pPlayer, D2UnitStrc* pItem, Unicode* nArg1, int nArg2)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_SET)
    {
        return;
    }

    D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordFromItem(pItem);
    if (!pSetItemsTxt)
    {
        return;
    }

    int nMember;
    unsigned int nMask;
    switch (pSetItemsTxt->nAddFunc)
    {
    case 1:
    {
        nMask = ITEMS_GetSetItemsMask(pPlayer, pItem, 0);
        nMember = ITEMS_GetNoOfSetItemsFromItem(pItem);
        for (int i = 0; i < 6; ++i)
        {
            int nIndex = i;
            if (i == nMember)
            {
                continue;
            }

            if (i > nMember)
            {
                nIndex = i - 1;
            }

            if (nMask & (1 << i))
            {
// build: symbol ?gaSetPropIds@* 0x006DBD70
                sub_004E60A0_AddSetPropText(pItem, nArg1, nArg2, 0, gaSetPropIds[nIndex], 0, 0, 1);
            }
        }
        break;
    }
    case 2:
    {
        const unsigned int nWorn = ITEMS_GetSetItemsMask(pPlayer, pItem, 1);
        const int nCount = (nWorn >= 0x40 ? 0 : gaSetPartialCounts_006DBD90[nWorn]) - 1;
        for (int i = 0; i < nCount; ++i)
        {
            sub_004E60A0_AddSetPropText(pItem, nArg1, nArg2, 0, gaSetPropIds[i], 0, 0, 1);
        }
        break;
    }
    }
}

// 0x004E6680
void __fastcall MISSILE_AddSetStatePropText(D2UnitStrc* pUnit, D2UnitStrc* pItem, Unicode* nArg1, int nArg2)
{
    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_SET)
    {
        return;
    }

    D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordInline(pItem);
    if (!pSetItemsTxt)
    {
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
// build: symbol ?gaSetPropIds@* 0x006DBD70
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, gaSetPropIds[i]);
        if (pStatList && pSetItemsTxt->nSetId == STATLIST_GetStatValue(pStatList, STAT_VALUE, 0))
        {
            sub_004E60A0_AddSetPropText(pUnit, nArg1, nArg2, 0, gaSetPropIds[i], 0, 0, 1);
            return;
        }
    }
}

// 0x004E6720
void __fastcall TEXT_BuildItemPropTextB(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, const Unicode* nArg4)
{
    ITEMMODS_AssignProperty(5, 0, pItem, nArg, nArg2, 0);
    Unicode wszBuffer[1024];
    wszBuffer[0].wChar = 0;
    sub_004E6410_BuildPropText(pItem, wszBuffer, nArg3, 1, nArg4);
    sub_00526700(wszText, wszBuffer);

    D2StatListStrc* pStatList = sub_00625790_UnitFindStatList(pItem, 0, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    if (wszText[sub_00526800(wszText) - 1].isNewline())
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
}

// 0x004E67D0
void __fastcall SKILLDESC_BuildItemPropText(D2UnitStrc* pItem, int nArg, int nArg2, Unicode* wszText, int nArg3, const Unicode* nArg4)
{
    ITEMMODS_AssignProperty(2, 0, pItem, nArg, nArg2, 0);
    sub_004E6410_BuildPropText(pItem, wszText, nArg3, 0, nArg4);

    D2StatListStrc* pStatList = sub_00625790_UnitFindStatList(pItem, 0, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    if (wszText[sub_00526800(wszText) - 1].isNewline())
    {
        wszText[sub_00526800(wszText) - 1].wChar = 0;
    }
}

// 0x004E6850
void __fastcall sub_004E6850_BuildSocketFillerText(D2UnitStrc* pItem, Unicode* pBuffer, int nSize)
{
    Unicode wszTemp[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszTemp[i].wChar = 0;

    D2_ASSERT(ITEMSIsA(pItem, 0x35), 0x21A);
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxt, 0x21C);
    pBuffer[0].wChar = 0;

    if (ITEMSIsA(pItem, 0x14))
    {
        D2GemsTxt* pGemsTxt = DATATBLS_GetGemsTxtRecord(pItemsTxt->dwGemOffset);
        D2_ASSERT(pGemsTxt, 0x223);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B42));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 2, pBuffer, nSize, wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B41));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 1, pBuffer, nSize, wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B44));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 1, pBuffer, nSize, wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B43));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        SKILLDESC_BuildItemPropText(pItem, (int)pGemsTxt, 0, pBuffer, nSize, wszTemp);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        D2GemsTxt* pGemsTxt = DATATBLS_GetGemsTxtRecord(pItemsTxt->dwGemOffset);
        D2_ASSERT(pGemsTxt, 0x245);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B42));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 2, pBuffer, nSize, wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B41));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 1, pBuffer, nSize, wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B44));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 1, pBuffer, nSize, wszTemp);
        sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
        wszTemp[0].wChar = 0;
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0x2B43));
        sub_00526700(wszTemp, D2LANG_GetStringFromTblIndex(0xF9B));
        TEXT_BuildItemPropTextB(pItem, (int)pGemsTxt, 0, pBuffer, nSize, wszTemp);
    }
    else
    {
        return;
    }

    sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(pBuffer, D2LANG_GetStringFromTblIndex(0xF9E));
}

#include "gen/data/Source/D2Client/Unknown_004E4670.inc"
