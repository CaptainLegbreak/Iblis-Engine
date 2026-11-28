#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#define STAT_HITPOINTS 6
#define STAT_MANA 8
#define STAT_STAMINA 10
struct D2GameStrc;
struct D2DrlgActStrc;
struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ModStatsArrayStrc;
struct D2OpStatDataStrc;
struct D2ItemStatCostTxt;







typedef void (__fastcall* StatListUnitCallback)(D2UnitStrc* pUnit1, int nStatId, int nValue, D2UnitStrc* pUnit2);





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

static int sub_00624B90_FindStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    D2StatStrc* pStat = pStatsArray->pStat;
    int nMax = pStatsArray->nStatCount;
    int nMin = 0;
    while (nMin < nMax)
    {
        const int nMid = nMin + (nMax - nMin) / 2;
        const int nPackedValue = pStat[nMid].nPackedValue;
        if (nLayer_StatId > nPackedValue)
        {
            nMin = nMid + 1;
        }
        else if (nLayer_StatId < nPackedValue)
        {
            nMax = nMid;
        }
        else
        {
            return nMid;
        }
    }
    return -1;
}

// build: symbol ?STATLIST_FindStat@* 0x00624C60
static D2StatStrc* STATLIST_FindStat(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = sub_00624B90_FindStatIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }
    return &pStatsArray->pStat[nIndex];
}

// build: symbol ?STATLIST_GetTotalStat@* 0x00624F60
static int __stdcall STATLIST_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    D2StatStrc* pStat = STATLIST_FindStat((pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatListEx->FullStats : &pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && pStatListEx->pOwner && (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

static int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
    {
        return 0;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x006275B0
void __stdcall STATLIST_ClampStaminaManaHP(D2UnitStrc* pUnit)
{
    if (!pUnit || !pUnit->pStatListEx)
    {
        return;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0);
    int nMaxValue = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (nValue > nMaxValue)
    {
        const int nDiff = nMaxValue - nValue;
        if (nDiff)
        {
            STATLIST_AddStat(pStatList, STAT_STAMINA, nDiff, 0);
        }
    }

    pStatList = pUnit->pStatListEx;
    nValue = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    nMaxValue = STATLIST_GetMaxManaFromUnit(pUnit);
    if (nValue > nMaxValue)
    {
        const int nDiff = nMaxValue - nValue;
        if (nDiff)
        {
            STATLIST_AddStat(pStatList, STAT_MANA, nDiff, 0);
        }
    }

    pStatList = pUnit->pStatListEx;
    nValue = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    nMaxValue = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nValue > nMaxValue)
    {
        const int nDiff = nMaxValue - nValue;
        if (nDiff)
        {
            STATLIST_AddStat(pStatList, STAT_HITPOINTS, nDiff, 0);
        }
    }
}
