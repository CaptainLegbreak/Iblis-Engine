#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2Win32Types.h"
#include "StormApi.h"

struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ItemStatCostTxt;
struct D2StatesTxt;

typedef unsigned int size_t;


extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
extern unsigned int gdwInvBitMasks[];
D2StatesTxt* __fastcall DATATBLS_GetStatesTxtRecord(int nStateId);

static inline D2ItemStatCostTxt* ITEMS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x00624B90
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

static D2StatStrc* STATLIST_FindStat(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = sub_00624B90_FindStatIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }
    return &pStatsArray->pStat[nIndex];
}

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

int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
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


#pragma pack(push, 1)
struct d2data_007445C4_t
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
};
#pragma pack(pop)

extern "C" struct d2data_007445C4_t gData_007445C4; // 0x007445C4

extern "C" struct d2data_007445C4_t gData_007445C4 = {
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
}; // 0x007445C4
