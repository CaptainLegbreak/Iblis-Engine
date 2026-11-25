#include "D2Common.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2Win32Types.h"

struct D2StatStrc;
struct D2StatsArrayStrc;
struct D2ItemStatCostTxt;
struct D2StatesTxt;

typedef unsigned int size_t;

extern "C" int __cdecl SStrPrintf(char* szDest, unsigned int nMaxCount, const char* szFormat, ...); // 0x00413A40

extern D2DataTablesStrc* sgptDataTables;
extern unsigned int gdwBitMasks[];
extern unsigned int gdwInvBitMasks[];
D2StatesTxt* __fastcall DATATBLS_GetStatesTxtRecord(int nStateId);
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask);

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

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
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

void __stdcall STATLIST_ToggleState(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (pUnit)
    {
        D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
        if (pStatListEx && (pStatListEx->dwFlags & STATLIST_EXTENDED))
        {
            const unsigned int bWasSet = pStatListEx->StatFlags[nState >> 5] & gdwBitMasks[nState & 31];
            if (bSet)
                pStatListEx->StatFlags[nState >> 5] |= gdwBitMasks[nState & 31];
            else
                pStatListEx->StatFlags[nState >> 5] &= gdwInvBitMasks[nState & 31];

            if (!bWasSet)
            {
                if (!bSet)
                    return;
            }
            else
            {
                if (bSet)
                    return;
            }

            pStatListEx->StatFlags[(nState >> 5) + (sgptDataTables->nStatesTxtRecordCount + 31) / 32] |= gdwBitMasks[nState & 31];

            D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecord(nState);
            if (pStatesTxtRecord)
            {
                if (bSet)
                {
                    if (STATES_CHECKFLAG(pStatesTxtRecord, STATEMASK_DISGUISE))
                        pUnit->dwFlagEx |= UNITFLAGEX_ISSHAPESHIFTED;
                }
                else if (STATES_CHECKFLAG(pStatesTxtRecord, STATEMASK_DISGUISE) && !STATES_CheckStateMaskOnUnit(pUnit, STATEMASK_DISGUISE))
                {
                    pUnit->dwFlagEx &= ~UNITFLAGEX_ISSHAPESHIFTED;
                }
            }
        }
    }
}

#include "gen/data/Source/D2Common/Unknown_00624740.inc"
