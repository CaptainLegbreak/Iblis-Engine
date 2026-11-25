#include "D2StateIds.h"

#include "D2Path.h"

#include "D2Records.h"

#include "D2TxtItems.h"

#include "D2TxtTables.h"

#include "D2Unicode.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Txt.h"

#include "D2LevelTxt.h"

#include "D2Skills.h"

#define STATLIST_SET 0x2000

struct D2GameStrc;

struct D2DrlgActStrc;

struct D2StatStrc;

struct D2StatsArrayStrc;

struct D2ModStatsArrayStrc;

struct D2OpStatDataStrc;

struct D2ItemStatCostTxt;

struct D2CharStatsTxt;

struct Obj00625250;

struct Obj006252B0;

struct Obj006252D0;

struct Obj006252F0;

struct Obj00625330;

struct Obj00625CE0;

struct Obj00626090;

struct Obj006260B0;

struct D2StatListStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

typedef void (__fastcall* StatListUnitCallback)(D2UnitStrc* pUnit1, int nStatId, int nValue, D2UnitStrc* pUnit2);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0

D2ItemStatCostTxt* __fastcall PLAYER_GetItemStatCostTxtRecord(int nStatId); // 0x0045C4F0

extern "C" D2CharStatsTxt* __fastcall sub_004833E0_GetCharStatsTxtRecord(int nClass); // 0x004833E0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

int __stdcall ITEMMODS_GetByTimeAdjustment(int nAmount, int nPeriodOfDay, int nBaseTime, int* pItemModPeriodOfDay, int* pItemModMin, int* pItemModMax); // 0x0065CA30

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker); // 0x00622560

static inline int STATLIST_GetTotalStatValue_Inl(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);

int __fastcall STATLIST_GetStatFromLayer(D2StatListStrc* pStatListEx, int nLayer_StatId);

int __fastcall STATLIST_UpdateStatOps(D2StatListStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit);

struct Obj00625250 { unsigned int dwUnknown00; unsigned int dwUnknown04; unsigned int dwValue08; };

struct Obj006252B0 { unsigned char bUnknown00[0x0C]; unsigned int dwValue0C; };

struct Obj006252D0 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; };

struct Obj006252F0 { unsigned char bUnknown00[0x14]; unsigned int dwValue14; };

struct Obj00625330 { unsigned char bUnknown00[0x18]; unsigned int dwValue18; };

int __stdcall STATLIST_GetStatValueWithPercent(D2StatListStrc* pStatList, int nStatId, int nPercentStatId, int bAddBonus); // 0x006255A0

D2StatListStrc* __stdcall STATLIST_FindStatListByFlag(D2StatListStrc* pStatList, int nFlag); // 0x006256E0

extern void* gpItemsCalcFunctions[]; // 0x0074463C

extern int gnItemsCalcFunctions; // 0x0074465C

int __fastcall ITEMMODS_GetCalcParamValue_Return0(int nParam, void* pUserData); // 0x00627B40

struct Obj00625CE0 { unsigned char bUnknown00[0x38]; unsigned int dwValue38; };

int __stdcall STATLIST_GetBaseStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625350

struct Obj00626090 { unsigned char bUnknown00[0x18]; unsigned int dwValue18; };

struct Obj006260B0 { unsigned char bUnknown00[0x10]; unsigned int dwFlags10; unsigned int dwUnknown14; int nValue18; };

void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList); // 0x00626C00

int __stdcall STATLIST_CopyStatsOfId(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize);

extern "C" const char gszStatListSourceFile[];

void __fastcall STATLIST_UpdateStatValue(D2StatListStrc* pStatListEx, int nLayer_StatId, int nValue, D2UnitStrc* pUnit); // 0x00626920

int __stdcall STATLIST_GetBaseStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord);

int __stdcall STATLIST_GetTotalStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord); // 0x00624F60

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList);                                 // 0x006269F0

#define MOVED_PREFIX

#define MOVE_ID(x) (x)

#define STATLIST_EXTENDED 0x80000000

#define ISC_FLAG_FMIN 10

#define STAT_SHIFT 16

#define STAT_MAKE(nStatId, nLayer) (((nStatId) << STAT_SHIFT) + (nLayer))

#define ITEMSTATCOST_HASFLAG(pRecord, nFlag) ((pRecord)->nItemStatFlags[(nFlag) >> 3] & gdwBitMasks[(nFlag) & 7])

#define UNITS_IsType(pUnit, nType) ((pUnit) && (pUnit)->dwUnitType == (nType))

static D2StatsArrayStrc* STATLIST_GetStatsArray(D2StatListExStrc* pStatList);                           // 0x00624F40

struct D2SkillListStrc;

struct D2PlayerDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030

int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0

struct D2StatListExStrc;

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

int __stdcall STATLIST_SetBaseStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer, D2UnitStrc* pUnit); // 0x00627170

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit);

#define STATLIST_NEWLENGTH 0x00000002

#define STATLIST_UNK_0x100 0x00000100

struct D2StatesTxt;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern unsigned int gdwInvBitMasks[]; // 0x006CE2E8

extern "C" D2StatesTxt* __fastcall GAME_GetStatesTxtRecord(int nStateId); // 0x00452040

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0

int __stdcall STATLIST_GetTotalStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625420

D2StatListStrc* __stdcall D2Common_GetStateFromStatListEx_6FDB8190(D2StatListStrc* pStatListEx, int nStateId); // 0x00625650

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList); // 0x00627340

int __stdcall STATES_CheckStateMaskStayDeathOnUnitByStateId(D2UnitStrc* pUnit, int nState); // 0x0063A4A0

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __stdcall D2Common_11274(D2UnitStrc* pTarget, D2UnitStrc* pUnit); // 0x00627860

int __stdcall D2Common_11275(D2UnitStrc* pTarget, D2UnitStrc* pUnit); // 0x00627A40

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0

inline int STATLIST_IsExtended(D2StatListStrc* pStatList);

typedef void (__fastcall* StatListValueChangeFunc)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue);

static int STATLIST_FindStatInsertIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId);

static int __stdcall STATLIST_FindFirstStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId);

static D2StatStrc* __stdcall STATLIST_InsertStatOrFail(void* pMemPool, D2StatsArrayStrc* pStatsArray, int nLayer_StatId);

static void __stdcall STATLIST_RemoveStat(void* pMemPool, D2StatsArrayStrc* pStatsArray, D2StatStrc* pStat);

static int STATLIST_FindModStatInsertIndex(D2ModStatsArrayStrc* pStatsArray, int nLayer_StatId);

static void __stdcall STATLIST_InsertStatModOrFail(D2StatListExStrc* pStatListEx, int nLayer_StatId);

static int __stdcall STATLIST_GetStatWithChildLists(D2StatListExStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord);

static int __stdcall STATLIST_AddFullStatValue(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit);

static void __stdcall STATLIST_UpdateUnitStat(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nNewValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit);

void __stdcall D2Common_10512(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nStatId, StatListUnitCallback pfCallback);

void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, StatListUnitCallback pfCallback);

int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize);

int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize);

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);

void __stdcall D2Common_10525(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);

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
    int nMin = 0;
    int nMax = pStatsArray->nStatCount;
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

// 0x00624BD0
static int STATLIST_FindStatInsertIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
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
            return -1;
        }
    }
    return nMin;
}

// 0x00624C10
static int __stdcall STATLIST_FindFirstStatIndex(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    D2StatStrc* pStat = pStatsArray->pStat;
    int nMin = 0;
    int nMax = pStatsArray->nStatCount;
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
    if (nMin >= pStatsArray->nStatCount)
    {
        return -1;
    }
    return nMin;
}

// 0x00624C60
static D2StatStrc* STATLIST_FindStat(D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = sub_00624B90_FindStatIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }
    return &pStatsArray->pStat[nIndex];
}

// 0x00624C80
static D2StatStrc* __stdcall STATLIST_InsertStatOrFail(void* pMemPool, D2StatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    const int nIndex = STATLIST_FindStatInsertIndex(pStatsArray, nLayer_StatId);
    if (nIndex < 0)
    {
        return 0;
    }

    if (pStatsArray->nStatCount >= pStatsArray->nCapacity)
    {
        pStatsArray->nCapacity += STATS_GROWTH;
        pStatsArray->pStat = (D2StatStrc*)FOG_ReallocPool(pMemPool, pStatsArray->pStat, pStatsArray->nCapacity * sizeof(D2StatStrc), ".\\Stats\\StatsEx.cpp", 0xE8, 0);
    }

    if (nIndex < pStatsArray->nStatCount)
    {
        memmove(&pStatsArray->pStat[nIndex + 1], &pStatsArray->pStat[nIndex], (pStatsArray->nStatCount - nIndex) * sizeof(D2StatStrc));
    }

    D2StatStrc* pStat = &pStatsArray->pStat[nIndex];
    pStat->nPackedValue = nLayer_StatId;
    pStat->nValue = 0;
    ++pStatsArray->nStatCount;
    return pStat;
}

// 0x00624D10
static void __stdcall STATLIST_RemoveStat(void* pMemPool, D2StatsArrayStrc* pStatsArray, D2StatStrc* pStat)
{
    const int nIndex = pStat - pStatsArray->pStat;
    if (nIndex < pStatsArray->nStatCount)
    {
        if (nIndex < pStatsArray->nStatCount - 1)
        {
            memmove(pStat, pStat + 1, (pStatsArray->nStatCount - (nIndex + 1)) * sizeof(D2StatStrc));
        }

        --pStatsArray->nStatCount;

        if (pStatsArray->nCapacity - pStatsArray->nStatCount > STATS_SHRINK)
        {
            pStatsArray->nCapacity -= STATS_GROWTH;
            pStatsArray->pStat = (D2StatStrc*)FOG_ReallocPool(pMemPool, pStatsArray->pStat, pStatsArray->nCapacity * sizeof(D2StatStrc), ".\\Stats\\StatsEx.cpp", 0x110, 0);
        }
    }
}

// 0x00624D90
static int STATLIST_FindModStatInsertIndex(D2ModStatsArrayStrc* pStatsArray, int nLayer_StatId)
{
    int* pStat = pStatsArray->pStat;
    int nMax = pStatsArray->nStatCount;
    int nMin = 0;
    while (nMin < nMax)
    {
        const int nMid = nMin + (nMax - nMin) / 2;
        const int nPackedValue = pStat[nMid];
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
            return -1;
        }
    }
    return nMin;
}

// 0x00624DD0
static void __stdcall STATLIST_InsertStatModOrFail(D2StatListExStrc* pStatListEx, int nLayer_StatId)
{
    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    const int nStatId = STAT_GETID(nLayer_StatId);
    switch (nStatId)
    {
    case 6:
    case 8:
    case 10:
    case 13:
    case 14:
        return;
    default:
        break;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord || !ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_SAVED))
    {
        return;
    }

    const int nIndex = STATLIST_FindModStatInsertIndex(&pStatListEx->ModStats, nLayer_StatId);
    if (nIndex < 0)
    {
        return;
    }

    if (pStatListEx->ModStats.nStatCount >= pStatListEx->ModStats.nCapacity)
    {
        pStatListEx->ModStats.nCapacity += STATS_GROWTH;
        pStatListEx->ModStats.pStat = (int*)FOG_ReallocPool(pStatListEx->pMemPool, pStatListEx->ModStats.pStat, pStatListEx->ModStats.nCapacity * sizeof(int), ".\\Stats\\StatsEx.cpp", 0x162, 0);
    }

    if (nIndex < pStatListEx->ModStats.nStatCount)
    {
        memmove(&pStatListEx->ModStats.pStat[nIndex + 1], &pStatListEx->ModStats.pStat[nIndex], (pStatListEx->ModStats.nStatCount - nIndex) * sizeof(int));
    }

    pStatListEx->ModStats.pStat[nIndex] = nLayer_StatId;
    ++pStatListEx->ModStats.nStatCount;
}

// 0x00624ED0
static int __stdcall STATLIST_GetBaseStat(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    D2StatStrc* pStat = STATLIST_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        return 0;
    }

    int nValue = pStat->nValue;
    if (pItemStatCostTxtRecord && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FMIN) && (pStatList->dwFlags & STATLIST_EXTENDED)
        && (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

// 0x00624F40
static __declspec(noinline) D2StatsArrayStrc* STATLIST_GetStatsArray(D2StatListExStrc* pStatList)
{
    if (pStatList->dwFlags & 0x80000000)
        return &pStatList->FullStats;
    return &pStatList->Stats;
}

// 0x00624F60
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
        && (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER)))
    {
        if (nValue < pItemStatCostTxtRecord->dwMinAccr)
        {
            nValue = pItemStatCostTxtRecord->dwMinAccr << pItemStatCostTxtRecord->nValShift;
        }
    }
    return nValue;
}

// 0x00624FE0
static int __stdcall STATLIST_GetStatWithChildLists(D2StatListExStrc* pStatListEx, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord)
{
    int nValue = STATLIST_GetBaseStat(pStatListEx, nLayer_StatId, 0);

    const unsigned int bDamageRelated = ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_DAMAGERELATED);
    if (pStatListEx->dwFlags & STATLIST_EXTENDED)
    {
        for (D2StatListStrc* i = pStatListEx->pMyLastList; i; i = i->pPrevLink)
        {
            if (!bDamageRelated || !(i->dwFlags & STATLIST_DYNAMIC))
            {
                nValue += STATLIST_GetTotalStat(i, nLayer_StatId, 0);
            }
        }
    }
    return nValue;
}

static inline void STATLIST_NotifyUnitOfStatValueChange(D2ItemStatCostTxt* pItemStatCostTxtRecord, D2StatListExStrc* pStatListEx, D2UnitStrc* pUnit, int nLayer_StatId, int nPreviousValue, int nNewValue)
{
    if (pStatListEx->pfOnValueChanged && ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_FCALLBACK))
    {
        pStatListEx->pfOnValueChanged(pStatListEx->pGame, pStatListEx->pOwner, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    }
}

// 0x006250B0
static int __stdcall STATLIST_AddFullStatValue(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatStrc* pStat = STATLIST_FindStat(&pStatListEx->FullStats, nLayer_StatId);
    if (!pStat)
    {
        pStat = STATLIST_InsertStatOrFail(pStatListEx->pMemPool, &pStatListEx->FullStats, nLayer_StatId);
    }

    const int nPreviousValue = pStat->nValue;
    const int nNewValue = nPreviousValue + nValue;
    pStat->nValue = nNewValue;
    if (nNewValue > 0 && pItemStatCostTxtRecord->bHasOpApplyingToItem)
    {
        pStatListEx->dwFlags |= STATLIST_PERMANENT;
    }

    if (pStat->nValue == 0 && !pItemStatCostTxtRecord->nKeepZero)
    {
        STATLIST_RemoveStat(pStatListEx->pMemPool, &pStatListEx->FullStats, pStat);
    }

    STATLIST_NotifyUnitOfStatValueChange(pItemStatCostTxtRecord, pStatListEx, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    return nNewValue;
}

// 0x00625150
static void __stdcall STATLIST_UpdateUnitStat(D2StatListExStrc* pStatListEx, int nLayer_StatId, int nNewValue, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatStrc* pStat = STATLIST_FindStat(&pStatListEx->FullStats, nLayer_StatId);
    if (!pStat)
    {
        if (!nNewValue)
        {
            return;
        }
        pStat = STATLIST_InsertStatOrFail(pStatListEx->pMemPool, &pStatListEx->FullStats, nLayer_StatId);
    }

    const int nPreviousValue = pStat->nValue;
    if (nNewValue || pItemStatCostTxtRecord->nKeepZero)
    {
        pStat->nValue = nNewValue;
        if (pItemStatCostTxtRecord->bHasOpApplyingToItem)
        {
            pStatListEx->dwFlags |= STATLIST_PERMANENT;
        }
    }
    else
    {
        STATLIST_RemoveStat(pStatListEx->pMemPool, &pStatListEx->FullStats, pStat);
    }

    if (nPreviousValue != nNewValue)
    {
        STATLIST_NotifyUnitOfStatValueChange(pItemStatCostTxtRecord, pStatListEx, pUnit, nLayer_StatId, nPreviousValue, nNewValue);
    }
}

// 0x006251F0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID)
{
    D2StatListStrc* pStatList = (D2StatListStrc*)sub_0040B430(pMemPool, 0x3C, ".\\Stats\\StatsEx.cpp", 1386, 0);
    memset(pStatList, 0x00, 0x3C);

    pStatList->dwOwnerType = nUnitType;
    pStatList->dwOwnerId = nUnitGUID;
    pStatList->pMemPool = pMemPool;
    pStatList->dwFlags = fFilter;
    pStatList->dwExpireFrame = dwTimeout;

    return pStatList;
}

// 0x00625250
extern "C" __declspec(dllexport) unsigned int __stdcall STATLIST_GetOwnerType(Obj00625250* pObj) {
    if (!pObj) {
        return 6;
    }
    return pObj->dwValue08;
}

// 0x00625270
int __stdcall STATLIST_GetBaseStatsCount(D2StatListStrc* pStatList)
{
    return !pStatList ? 0 : pStatList->Stats.nStatCount;
}

// 0x00625290
int __stdcall STATLIST_GetFullStatsCountFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pStatListEx)
    {
        return 0;
    }

    return pUnit->pStatListEx->FullStats.nStatCount;
}

// 0x006252B0
extern "C" __declspec(dllexport) unsigned int __stdcall STATLIST_GetOwnerGUID(Obj006252B0* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue0C;
}

inline D2SkillsTxt* __fastcall DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x006252D0
extern "C" __declspec(dllexport) void __stdcall STATLIST_SetState(Obj006252D0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValue14 = dwValue;
    }
}

// 0x006252F0
extern "C" __declspec(dllexport) unsigned int __stdcall STATLIST_GetState(Obj006252F0* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue14;
}

// 0x00625310
void __stdcall STATLIST_SetExpireFrame(D2StatListStrc* pStatList, int nExpireFrame)
{
    if (pStatList)
    {
        if (nExpireFrame > 0)
        {
            pStatList->dwFlags |= STATLIST_NEWLENGTH;
        }

        pStatList->dwExpireFrame = nExpireFrame;
    }
}

// 0x00625330
extern "C" __declspec(dllexport) unsigned int __stdcall STATLIST_GetExpireFrame(Obj00625330* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}

// 0x00625350
int __stdcall STATLIST_GetBaseStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
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

    return STATLIST_GetBaseStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x006253B0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    if (!pUnit)
    {
        return 0;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
    {
        return 0;
    }

    return STATLIST_GetBaseStat(pStatList, STAT_MAKE(nStatId, nLayer), pItemStatCostTxtRecord);
}

// 0x00625420
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

// 0x00625480
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

// 0x006254E0
int __stdcall STATLIST_GetBaseStatValueByLayer(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetBaseStatValue(pStatList, nStatId, nLayer);
}

// 0x006254F0
int __stdcall STATLIST_GetTotalStatValueStub(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer);
}

// 0x00625500
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetTotalStatValue(pUnit->pStatListEx, nStatId, nLayer);
}

// 0x00625520
int __stdcall STATLIST_GetStatBonus(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    if (!pStatList)
    {
        return 0;
    }

    return STATLIST_GetTotalStatValue(pStatList, nStatId, nLayer) - STATLIST_GetBaseStatValue(pStatList, nStatId, nLayer);
}

// 0x006255A0
int __stdcall STATLIST_GetStatValueWithPercent(D2StatListStrc* pStatList, int nStatId, int nPercentStatId, int bAddBonus)
{
    if (!pStatList)
    {
        return 0;
    }
    const int nPercent = STATLIST_GetTotalStatValue(pStatList, nPercentStatId, 0);
    const int nBase = STATLIST_GetBaseStatValue(pStatList, nStatId, 0);
    int nBonus = 0;
    if (bAddBonus)
    {
        nBonus = STATLIST_GetTotalStatValue(pStatList, nStatId, 0) - nBase;
    }
    return DATATBLS_ApplyRatio(nBase, nPercent, 100) + nBonus + nBase;
}

// 0x00625600
int __stdcall STATLIST_UnitGetStatValueWithPercent(D2UnitStrc* pUnit, int nStatId, int nPercentStatId, int bAddBonus)
{
    return STATLIST_GetStatValueWithPercent(pUnit->pStatListEx, nStatId, nPercentStatId, bAddBonus);
}

// 0x00625620
int __stdcall STATLIST_GetBaseStatValueByIndex(D2StatListStrc* pStatList, int nIndex)
{
    if (!pStatList)
    {
        return 0;
    }

    if (nIndex >= pStatList->Stats.nStatCount)
    {
        return 0;
    }

    return pStatList->Stats.pStat[nIndex].nValue;
}

// 0x00625650
D2StatListStrc* __stdcall D2Common_GetStateFromStatListEx_6FDB8190(D2StatListStrc* pStatList, int nStateId)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    if (!pStatListEx)
    {
        return 0;
    }

    if (!nStateId)
    {
        return 0;
    }

    D2StatListStrc* pState = (pStatListEx->dwFlags & 0x80000000) ? pStatListEx->pMyLastList : 0;
    while (pState && pState->dwStateNo != nStateId)
    {
        pState = pState->pPrevLink;
    }

    if (pState)
    {
        return pState;
    }

    pState = (pStatListEx->dwFlags & 0x80000000) ? pStatListEx->pMyStats : 0;
    while (pState)
    {
        if (pState->dwStateNo == nStateId)
        {
            return pState;
        }
        pState = pState->pPrevLink;
    }

    return 0;
}

// 0x006256B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & 0x80000000))
    {
        return 0;
    }
    return D2Common_GetStateFromStatListEx_6FDB8190(pStatListEx, nState);
}

// 0x006256E0
D2StatListStrc* __stdcall STATLIST_FindStatListByFlag(D2StatListStrc* pStatList, int nFlag)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    if (pStatList)
    {
        if (pStatList->dwFlags & STATLIST_EXTENDED)
        {
            pStatList = nFlag & STATLIST_SET ? pStatListEx->pMyStats : pStatListEx->pMyLastList;
        }
        nFlag &= ~STATLIST_SET;

        while (pStatList)
        {
            if (nFlag & pStatList->dwFlags)
            {
                return pStatList;
            }
            pStatList = pStatList->pPrevLink;
        }
    }

    return 0;
}

// 0x00625730
D2StatListStrc* __stdcall STATLIST_GetStatListFromFlag(D2StatListStrc* pStatList, int nFlag)
{
    if (pStatList)
    {
        for (pStatList = pStatList->pPrevLink; pStatList; pStatList = pStatList->pPrevLink)
        {
            if (nFlag & pStatList->dwFlags)
            {
                return pStatList;
            }
        }
    }

    return 0;
}

// 0x00625760
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return 0;
    }

    return STATLIST_FindStatListByFlag(pStatListEx, nFlag);
}

// 0x00625790
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateOrFlag(D2UnitStrc* pUnit, int nState, int nFlag)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & 0x80000000))
    {
        return 0;
    }
    if (nState)
    {
        return D2Common_GetStateFromStatListEx_6FDB8190(pStatListEx, nState);
    }
    return STATLIST_FindStatListByFlag(pStatListEx, nFlag);
}

// 0x006257D0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc* pUnit, int nState, int nFlag)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (pStatListEx && pStatListEx->dwFlags & STATLIST_EXTENDED)
    {
        D2StatListStrc* pStatList = pStatListEx->pMyLastList;
        if (nFlag & STATLIST_SET)
        {
            pStatList = pStatListEx->pMyStats;
            nFlag &= ~STATLIST_SET;
        }

        while (pStatList)
        {
            if (pStatList->dwStateNo == nState && (!nFlag || nFlag & pStatList->dwFlags))
            {
                return pStatList;
            }
            pStatList = pStatList->pPrevLink;
        }
    }

    return 0;
}

// 0x00625820
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic)
{
    if (!pUnit)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    D2StatListExStrc* pParent = pStatListEx->pParent;
    if (!pParent)
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    if (!(pParent->dwFlags & STATLIST_EXTENDED))
    {
        if (pStatNotDynamic)
            *pStatNotDynamic = 0;
        return 0;
    }

    if (pStatNotDynamic)
        *pStatNotDynamic = !(pStatListEx->dwFlags & STATLIST_DYNAMIC);

    return pParent->pOwner;
}

// 0x00625870
void __stdcall D2Common_10512(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nStatId, StatListUnitCallback pfCallback)
{
    if (!pUnit1)
    {
        return;
    }

    D2StatListExStrc* pStatListEx = pUnit1->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    const int nLayer_StatId = nStatId << STAT_SHIFT;
    if (STATLIST_FindModStatInsertIndex(&pStatListEx->ModStats, nLayer_StatId) != -1)
    {
        return;
    }

    D2StatStrc* pStat = STATLIST_FindStat(&pStatListEx->Stats, nLayer_StatId);
    if (pStat)
    {
        pfCallback(pUnit1, nStatId, pStat->nValue, pUnit2);
    }
}

// 0x006258D0
void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, StatListUnitCallback pfCallback)
{
    if (!pUnit1 || (!pUnit2 && pfCallback))
    {
        return;
    }

    D2StatListExStrc* pStatListEx = pUnit1->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    for (int i = 0; i < pStatListEx->ModStats.nStatCount; ++i)
    {
        const int nLayer_StatId = pStatListEx->ModStats.pStat[i];
        D2StatStrc* pStat = STATLIST_FindStat(&pStatListEx->Stats, nLayer_StatId);
        if (!pStat)
        {
            pfCallback(pUnit1, STAT_GETID(nLayer_StatId), 0, pUnit2);
        }
        else
        {
            pfCallback(pUnit1, pStat->nStat, pStat->nValue, pUnit2);
        }
    }
}

// 0x00625960
void __stdcall STATLIST_FreeModStats(D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = pUnit ? pUnit->pStatListEx : 0;
    if (pStatListEx && pStatListEx->dwFlags & STATLIST_EXTENDED)
    {
        if (pStatListEx->ModStats.pStat)
        {
            FOG_FreeServerMemory(pStatListEx->pMemPool, pStatListEx->ModStats.pStat, ".\\Stats\\StatsEx.cpp", 2590, 0);
            pStatListEx->ModStats.pStat = 0;
        }

        pStatListEx->ModStats.nCapacity = 0;
        pStatListEx->ModStats.nStatCount = 0;
    }
}

// 0x006259B0
int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;
    if (!pUnit->pStatListEx)
        return 0;
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
    case UNIT_MONSTER:
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_ALIGNMENT);
        if (!pStatList)
            return 0;
        return STATLIST_GetTotalStatValue(pStatList, 0xAC, 0);
    }
    default:
        return 2;
    }
}

// 0x00625A00
void __stdcall D2Common_10534(D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = pUnit ? pUnit->pStatListEx : 0;
    if (pStatListEx)
    {
        pStatListEx->dwFlags |= STATLIST_UNK_0x100;
    }
}

static inline int STATLIST_GetTotalStatValue_Inl(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
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

// 0x00625A20
int __stdcall D2COMMON_10530_D2CheckStatlistFlagDMGRed(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }

    return (pStatListEx->dwFlags & STATLIST_UNK_0x100) != 0;
}

// 0x00625A50
int __stdcall STATLIST_GetTotalStatValue_Layer0(D2StatListStrc* pStatListEx, int nStatId)
{
    return STATLIST_GetTotalStatValue(pStatListEx, nStatId, 0);
}

// 0x00625A70
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

            D2StatesTxt* pStatesTxtRecord = GAME_GetStatesTxtRecord(nState);
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

// 0x00625B70
int __stdcall STATLIST_CheckState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return 0;

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return pStatListEx->StatFlags[nState >> 5] & gdwBitMasks[nState & 31];
}

// 0x00625BB0
unsigned int* __stdcall D2COMMON_STATES_GetStatFlags_6FDB8A90(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return pStatListEx->StatFlags;
}

// 0x00625BE0
unsigned int* __stdcall D2COMMON_STATES_GetListGfxFlags_6FDB8AC0(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 0;

    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return &pStatListEx->StatFlags[(sgptDataTables->nStatesTxtRecordCount + 31) / 32];
}

// 0x00625C30
int __stdcall STATLIST_GetFullStatsDataFromUnit(D2UnitStrc* pUnit, D2StatStrc* pOutStatBuffer, int nBufferSize)
{
    if (!pUnit)
    {
        return 0;
    }
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & 0x80000000))
    {
        return 0;
    }
    int nStatCount = pStatListEx->FullStats.nStatCount;
    if (nStatCount >= nBufferSize)
    {
        nStatCount = nBufferSize;
    }
    D2StatStrc* pStat = pStatListEx->FullStats.pStat;
    D2StatStrc* pEnd = &pStat[nStatCount];
    for (; pStat < pEnd; ++pStat)
    {
        *pOutStatBuffer = *pStat;
        ++pOutStatBuffer;
    }
    return nStatCount;
}

// 0x00625C90
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc* pStatList, D2StatStrc* pOutStatBuffer, int nBufferSize)
{
    if (!pStatList)
    {
        return 0;
    }
    int nStatCount = pStatList->Stats.nStatCount;
    if (nStatCount >= nBufferSize)
    {
        nStatCount = nBufferSize;
    }
    D2StatStrc* pStat = pStatList->Stats.pStat;
    D2StatStrc* pEnd = &pStat[nStatCount];
    for (; pStat < pEnd; ++pStat)
    {
        *pOutStatBuffer = *pStat;
        ++pOutStatBuffer;
    }
    return nStatCount;
}

// 0x00625CE0
extern "C" __declspec(dllexport) void __stdcall STATLIST_SetStatRemoveCallback(Obj00625CE0* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValue38 = dwValue;
    }
}

// 0x00625D00
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer)
{
    return STATLIST_GetBaseStatValue(pStatList, nStatId, nLayer);
}

// 0x00625D10
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(7);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(7, 0), pItemStatCostTxtRecord);
}

// 0x00625D60
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(9);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(9, 0), pItemStatCostTxtRecord);
}

// 0x00625DB0
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(11);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(11, 0), pItemStatCostTxtRecord);
}

// 0x00625E00
int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit)
{
    if (!STATLIST_GetUnitBaseStat(pUnit, STAT_MAXDURABILITY, 0))
    {
        return 0;
    }
    return STATLIST_GetTotalStatValue_Inl(pUnit->pStatListEx, STAT_MAXDURABILITY, 0);
}

// 0x00625E60
int __stdcall STATLIST_GetMaxDamageFromUnit(D2UnitStrc* pUnit, int b2Handed)
{
    if (b2Handed)
    {
        if (!pUnit)
        {
            return 0;
        }

        D2StatListStrc* pStatList = pUnit->pStatListEx;
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (pStatList)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(24);
        }

        if (!pItemStatCostTxtRecord)
        {
            return 0;
        }

        return STATLIST_GetTotalStat(pStatList, STAT_MAKE(24, 0), pItemStatCostTxtRecord);
    }

    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(22);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(22, 0), pItemStatCostTxtRecord);
}

// 0x00625EF0
int __stdcall STATLIST_GetMinDamageFromUnit(D2UnitStrc* pUnit, int b2Handed)
{
    if (b2Handed)
    {
        if (!pUnit)
        {
            return 0;
        }

        D2StatListStrc* pStatList = pUnit->pStatListEx;
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (pStatList)
        {
            pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(MOVE_ID(23));
        }

        if (!pItemStatCostTxtRecord)
        {
            return 0;
        }

        return STATLIST_GetTotalStat(pStatList, STAT_MAKE(MOVE_ID(23), 0), pItemStatCostTxtRecord);
    }

    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(MOVE_ID(21));
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(MOVE_ID(21), 0), pItemStatCostTxtRecord);
}

// 0x00625F80
int __stdcall STATLIST_GetMaxThrowDamageFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(160);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(160, 0), pItemStatCostTxtRecord);
}

// 0x00625FD0
int __stdcall STATLIST_GetMinThrowDamageFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(MOVE_ID(159));
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(MOVE_ID(159), 0), pItemStatCostTxtRecord);
}

// 0x00626020
int __stdcall STATLIST_GetDefenseFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    D2StatListStrc* pStatList = pUnit->pStatListEx;
    D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
    if (pStatList)
    {
        pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(31);
    }

    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    return STATLIST_GetTotalStat(pStatList, STAT_MAKE(31, 0), pItemStatCostTxtRecord);
}

// 0x00626070
int __stdcall D2Common_11248(D2UnitStrc* pUnused, D2UnitStrc* pUnit, int nStatId)
{
    return STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
}

// 0x00626090
extern "C" __declspec(dllexport) unsigned int __stdcall STATLIST_GetListExpireFrame(Obj00626090* pObj) {
    if (!pObj) {
        return 0;
    }
    return pObj->dwValue18;
}

// 0x006260B0
extern "C" __declspec(dllexport) void __stdcall STATLIST_SetListExpireFrame(Obj006260B0* pObj, int nValue) {
    if (pObj) {
        if (nValue > 0) {
            pObj->dwFlags10 |= 2;
        }
        pObj->nValue18 = nValue;
    }
}

// 0x006260D0
void __stdcall STATLIST_SetSkillId(D2StatListStrc* pStatList, int nSkillId)
{
    pStatList->dwSkillNo = nSkillId;
}

// 0x006260E0
D2SkillStrc* __stdcall STATLIST_GetSkillId(D2StatListStrc* pStatList)
{
    return pStatList->pSkill;
}

// 0x006260F0
void __stdcall STATLIST_SetSkillLevel(D2StatListStrc* pStatList, int nSkillLevel)
{
    pStatList->dwSLvl = nSkillLevel;
}

// 0x00626100
int __stdcall STATLIST_GetSkillLevel(D2StatListStrc* pStatList)
{
    return pStatList->dwSLvl;
}

// 0x00626110
static int __stdcall STATLIST_CopyStatsOfId(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    if (!pStatList)
    {
        return 0;
    }

    D2StatsArrayStrc* pStatsArray = (pStatList->dwFlags & STATLIST_EXTENDED) ? &pStatListEx->FullStats : &pStatList->Stats;
    int nIndex = STATLIST_FindFirstStatIndex(pStatsArray, nStatId << STAT_SHIFT);
    if (nIndex < 0)
    {
        return 0;
    }

    int nCopied = 0;
    D2StatStrc* pStat = &pStatsArray->pStat[nIndex];
    while (nIndex < pStatsArray->nStatCount)
    {
        const int nPackedValue = pStat->nPackedValue;
        if (STAT_GETID(nPackedValue) != nStatId)
        {
            return nCopied;
        }
        if (nCopied >= nBufferSize)
        {
            return nCopied;
        }
        pBuffer->nPackedValue = nPackedValue;
        pBuffer->nValue = pStat->nValue;
        ++nCopied;
        ++nIndex;
        ++pStat;
        ++pBuffer;
    }
    return nCopied;
}

// 0x006261B0
int __stdcall D2COMMON_11269_CopyStats(D2StatListStrc* pStatList, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    return STATLIST_CopyStatsOfId(pStatListEx, nStatId, pBuffer, nBufferSize);
}

// 0x006261D0
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStatId, D2StatStrc* pBuffer, int nBufferSize)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return 0;
    }
    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
    {
        return 0;
    }
    return STATLIST_CopyStatsOfId(pStatListEx, nStatId, pBuffer, nBufferSize);
}

// 0x00626200
int __fastcall STATLIST_GetStatFromLayer(D2StatListStrc* pStatList, int nLayer_StatId)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    const int nStatId = STAT_GETID(nLayer_StatId);

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
    if (!pItemStatCostTxtRecord)
    {
        return 0;
    }

    int nPreviousOpStatValue = STATLIST_GetStatWithChildLists(pStatListEx, nLayer_StatId, pItemStatCostTxtRecord);
    int nAccumulatedValue = nPreviousOpStatValue;

    if (!pItemStatCostTxtRecord->bHasOpStatData)
    {
        return nAccumulatedValue;
    }

    for (int i = 0; i < OPDATA_COUNT; ++i)
    {
        D2OpStatDataStrc* pOpStatData = &pItemStatCostTxtRecord->pOpStatData[i];
        int nBaseTime;
        int nBaseTime2;
        if (!pOpStatData->nOp)
        {
            break;
        }

        switch (pOpStatData->nOp)
        {
        case 1:
            if (pStatListEx->pOwner)
            {
                if (pStatListEx->pOwner->dwUnitType == UNIT_ITEM)
                {
                    nPreviousOpStatValue = STATLIST_GetUnitBaseStat(pStatListEx->pOwner, nStatId, 0);
                }

                if (nPreviousOpStatValue)
                {
                    const int nOpStatValue = STATLIST_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT);
                    if (nOpStatValue)
                    {
                        nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, nOpStatValue, 100);
                    }
                }
            }
            break;

        case 2:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        const int nShiftedVal = STATLIST_GetTotalStat(pStatListEx, nOpBase << STAT_SHIFT, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = STATLIST_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam;
                            }
                        }
                    }
                }
            }
            break;

        case 3:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        const int nShiftedVal = STATLIST_GetTotalStat(pStatListEx, nOpBase << STAT_SHIFT, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = STATLIST_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam, 100);
                            }
                        }
                    }
                }
            }
            break;

        case 4:
            if (pStatListEx->pUnit && (pStatListEx->pUnit->dwUnitType == UNIT_PLAYER || pStatListEx->pUnit->dwUnitType == UNIT_MONSTER))
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        D2UnitStrc* const pUnit = pStatListEx->pUnit;
                        const int nShiftedVal = STATLIST_UnitGetStatValue(pUnit, nOpBase, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = STATLIST_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam;
                            }
                        }
                    }
                }
            }
            break;

        case 5:
            if (pStatListEx->pUnit && (pStatListEx->pUnit->dwUnitType == UNIT_PLAYER || pStatListEx->pUnit->dwUnitType == UNIT_MONSTER))
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE)
                {
                    D2ItemStatCostTxt* pOpBaseItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nOpBase);
                    if (pOpBaseItemStatCostTxtRecord)
                    {
                        D2UnitStrc* const pUnit = pStatListEx->pUnit;
                        const int nShiftedVal = STATLIST_UnitGetStatValue(pUnit, nOpBase, 0) >> pOpBaseItemStatCostTxtRecord->nValShift;
                        if (nShiftedVal > 0)
                        {
                            const int nOpLayer_StatId = pOpStatData->nStat << STAT_SHIFT;
                            const int nRecursiveValue = STATLIST_GetStatFromLayer(pStatListEx, nOpLayer_StatId);
                            if (nRecursiveValue)
                            {
                                nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, (nShiftedVal * nRecursiveValue) >> pOpStatData->nOpParam, 100);
                            }
                        }
                    }
                }
            }
            break;

        case 6:
            if (pStatListEx->pOwner)
            {
                if (D2DrlgActStrc* pAct = pStatListEx->pOwner->pDrlgAct)
                {
                    if (const int nTmp = STATLIST_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT))
                    {
                        nBaseTime = 0;
                        const int nPeriodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(pAct, &nBaseTime);
                        nAccumulatedValue += ITEMMODS_GetByTimeAdjustment(nTmp, nPeriodOfDay, nBaseTime, 0, 0, 0);
                    }
                }
            }
            break;

        case 7:
            if (pStatListEx->pOwner)
            {
                if (D2DrlgActStrc* pAct = pStatListEx->pOwner->pDrlgAct)
                {
                    if (const int nTmp = STATLIST_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT))
                    {
                        nBaseTime2 = 0;
                        const int nPeriodOfDay = ENVIRONMENT_GetPeriodOfDayFromAct(pAct, &nBaseTime2);
                        nAccumulatedValue += DATATBLS_ApplyRatio(nAccumulatedValue, ITEMMODS_GetByTimeAdjustment(nTmp, nPeriodOfDay, nBaseTime2, 0, 0, 0), 100);
                    }
                }
            }
            break;

        case 8:
            if (pStatListEx->pOwner && pStatListEx->pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (D2CharStatsTxt* pCharStatsTxtRecord = sub_004833E0_GetCharStatsTxtRecord(pStatListEx->pOwner->dwClassId))
                {
                    const int nIndex = sub_00624B90_FindStatIndex(&pStatListEx->Stats, pOpStatData->nStat << STAT_SHIFT);
                    D2StatStrc* pStat = nIndex < 0 ? 0 : &pStatListEx->Stats.pStat[nIndex];
                    const int nTemp = !pStat ? 0 : pStat->nValue;

                    const int nBaseValue = STATLIST_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT) - nTemp;
                    if (nBaseValue)
                    {
                        nAccumulatedValue += nBaseValue * pCharStatsTxtRecord->nManaPerMagic << 6;
                    }
                }
            }
            break;

        case 9:
            if (pStatListEx->pOwner && pStatListEx->pOwner->dwUnitType == UNIT_PLAYER)
            {
                if (D2CharStatsTxt* pCharStatsTxtRecord = sub_004833E0_GetCharStatsTxtRecord(pStatListEx->pOwner->dwClassId))
                {
                    const int nIndex = sub_00624B90_FindStatIndex(&pStatListEx->Stats, pOpStatData->nStat << STAT_SHIFT);
                    D2StatStrc* pStat = nIndex < 0 ? 0 : &pStatListEx->Stats.pStat[nIndex];
                    const int nBaseStatValue = !pStat ? 0 : pStat->nValue;

                    const int nBonusValue = STATLIST_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT) - nBaseStatValue;
                    if (nBonusValue)
                    {
                        if (nStatId == STAT_MAXSTAMINA)
                        {
                            nAccumulatedValue += nBonusValue * pCharStatsTxtRecord->nStaminaPerVitality << 6;
                        }
                        else
                        {
                            nAccumulatedValue += nBonusValue * pCharStatsTxtRecord->nLifePerVitality << 6;
                        }
                    }
                }
            }
            break;

        case 11:
            if (nPreviousOpStatValue)
            {
                if (UNITS_IsType(pStatListEx->pOwner, UNIT_PLAYER) || UNITS_IsType(pStatListEx->pOwner, UNIT_MONSTER))
                {
                    const int nOpStatValue = STATLIST_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT);
                    if (nOpStatValue)
                    {
                        nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, nOpStatValue, 100);
                    }
                }
            }
            break;

        case 13:
            if (pStatListEx->pOwner && pStatListEx->pOwner->dwUnitType == UNIT_ITEM)
            {
                nPreviousOpStatValue = STATLIST_GetUnitBaseStat(pStatListEx->pOwner, nStatId, 0);
                if (nPreviousOpStatValue)
                {
                    const int nOpStatValue = STATLIST_GetStatFromLayer(pStatListEx, pOpStatData->nStat << STAT_SHIFT);
                    if (nOpStatValue)
                    {
                        nAccumulatedValue += DATATBLS_ApplyRatio(nPreviousOpStatValue, nOpStatValue, 100);
                    }
                }
            }
            break;

        default:
            break;
        }
    }

    return nAccumulatedValue;
}

// 0x006266C0
int __fastcall STATLIST_UpdateStatOps(D2StatListStrc* pStatList, int nLayer_StatId, D2ItemStatCostTxt* pItemStatCostTxtRecord, D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    const int nNewValue = STATLIST_GetStatFromLayer(pStatListEx, nLayer_StatId);
    if (!pItemStatCostTxtRecord->bIsBaseOfOtherStatOp)
    {
        STATLIST_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);
        return nNewValue;
    }

    if (!nNewValue)
    {
        STATLIST_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);
    }

    int bUpdate = 1;
    for (int nCounter = 0; nCounter < OPSTAT_COUNT; ++nCounter)
    {
        const unsigned short nOpStat = pItemStatCostTxtRecord->wOpStat[nCounter];
        if (nOpStat == STAT_NONE)
        {
            break;
        }

        D2OpStatDataStrc* pOpStatData = &pItemStatCostTxtRecord->pOpStatData[nCounter];
        D2ItemStatCostTxt* pOpItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nOpStat);
        const int nOpStatLayer_StatId = nOpStat << STAT_SHIFT;
        const int nOpStatNewValue = STATLIST_UpdateStatOps(pStatListEx, nOpStatLayer_StatId, pOpItemStatCostTxtRecord, pUnit);
        STATLIST_UpdateUnitStat(pStatListEx, nOpStatLayer_StatId, nOpStatNewValue, pOpItemStatCostTxtRecord, pUnit);
        if (!nOpStatNewValue)
        {
            continue;
        }

        switch (pItemStatCostTxtRecord->nOp)
        {
        case 2:
        case 3:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE && STATLIST_GetTotalStat(pStatListEx, nOpBase << STAT_SHIFT, 0) > 0)
                {
                    bUpdate = 0;
                }
            }
            break;

        case 4:
        case 5:
            if (pStatListEx->pUnit && (pStatListEx->pUnit->dwUnitType == UNIT_PLAYER || pStatListEx->pUnit->dwUnitType == UNIT_MONSTER))
            {
                const unsigned short nOpBase = pOpStatData->nOpBase;
                if (nOpBase != STAT_NONE && STATLIST_UnitGetStatValue(pStatListEx->pUnit, nOpBase, 0) > 0)
                {
                    bUpdate = 0;
                }
            }
            break;

        case 6:
        case 7:
            if (pStatListEx->dwOwnerType == UNIT_PLAYER || pStatListEx->dwOwnerType == UNIT_MONSTER)
            {
                bUpdate = 0;
            }
            break;

        case 13:
            if (pStatListEx->dwOwnerType == UNIT_ITEM)
            {
                bUpdate = 0;
            }
            break;

        case 0:
        case 8:
        case 9:
        case 10:
        case 11:
            break;

        default:
            bUpdate = 0;
            break;
        }
    }

    if (bUpdate && nNewValue)
    {
        STATLIST_UpdateUnitStat(pStatListEx, nLayer_StatId, nNewValue, pItemStatCostTxtRecord, pUnit);

        for (int i = 0; i < AFFECTED_COUNT; ++i)
        {
            const unsigned short nStatId = pItemStatCostTxtRecord->wStatsAffected[i];
            if (nStatId == STAT_NONE)
            {
                break;
            }

            D2ItemStatCostTxt* pAffectedRecord = ITEMS_GetItemStatCostTxtRecord(nStatId);
            const int nAffectedLayer_StatId = nStatId << STAT_SHIFT;
            const int nAffectedNewValue = STATLIST_UpdateStatOps(pStatListEx, nAffectedLayer_StatId, pAffectedRecord, pUnit);
            STATLIST_UpdateUnitStat(pStatListEx, nAffectedLayer_StatId, nAffectedNewValue, pAffectedRecord, pUnit);
        }
    }

    return nNewValue;
}

// 0x00626920
void __fastcall STATLIST_UpdateStatValue(D2StatListStrc* pStatList, int nLayer_StatId, int nValue, D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
    if (!nValue)
    {
        return;
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(STAT_GETID(nLayer_StatId));
    if (!pItemStatCostTxtRecord || (pStatListEx->dwFlags & STATLIST_SET))
    {
        return;
    }

    const unsigned int bDamageRelated = ITEMSTATCOST_HASFLAG(pItemStatCostTxtRecord, ISC_FLAG_DAMAGERELATED);
    D2StatListExStrc* pParent = (pStatListEx->dwFlags & STATLIST_EXTENDED) ? pStatListEx : pStatListEx->pParent;
    while (pParent)
    {
        if (pItemStatCostTxtRecord->bIsBaseOfOtherStatOp || pItemStatCostTxtRecord->bHasOpStatData)
        {
            STATLIST_UpdateStatOps(pParent, nLayer_StatId, pItemStatCostTxtRecord, pUnit);
        }
        else
        {
            STATLIST_AddFullStatValue(pParent, nLayer_StatId, nValue, pItemStatCostTxtRecord, pUnit);
        }

        D2StatListStrc* pCurrent = pParent;
        pParent = pParent->pParent;
        if ((pCurrent->dwFlags & STATLIST_SET) || (bDamageRelated && (pCurrent->dwFlags & STATLIST_DYNAMIC)))
        {
            break;
        }
    }
}

// 0x006269F0
void __stdcall D2Common_ExpireStatList_6FDB6E30(D2StatListStrc* pStatList)
{
    int anStats[16];

    if (!pStatList)
    {
        return;
    }

    D2StatListExStrc* pParent = pStatList->pParent;
    if (pParent)
    {
        if (pParent->dwFlags & 0x80000000)
        {
            if (pParent->pMyLastList == pStatList)
            {
                pParent->pMyLastList = pStatList->pPrevLink;
            }
            if (pParent->pMyStats == pStatList)
            {
                pParent->pMyStats = pStatList->pPrevLink;
            }
        }
        pStatList->pParent = 0;
    }

    if (pStatList->pNextLink)
    {
        pStatList->pNextLink->pPrevLink = pStatList->pPrevLink;
    }
    if (pStatList->pPrevLink)
    {
        pStatList->pPrevLink->pNextLink = pStatList->pNextLink;
    }

    pStatList->pPrevLink = 0;
    pStatList->pNextLink = 0;
    D2UnitStrc* pUnit = pStatList->pUnit;
    pStatList->pUnit = 0;

    if (pStatList->dwFlags & 0x2000)
    {
        return;
    }

    D2UnitStrc* pOwner = 0;
    if (pStatList->dwFlags & 0x80000000)
    {
        pOwner = ((D2StatListExStrc*)pStatList)->pOwner;
    }

    if ((pStatList->dwFlags & 0x80000000) && (pStatList->dwFlags & 0x20000000))
    {
        int nCount = 0;
        D2StatStrc* pStat = ((D2StatListExStrc*)pStatList)->FullStats.pStat;
        D2StatStrc* pStatEnd = &pStat[((D2StatListExStrc*)pStatList)->FullStats.nStatCount];
        for (; pStat < pStatEnd; ++pStat)
        {
            D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(STAT_GETID(pStat->nPackedValue));
            if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->bHasOpApplyingToItem)
            {
                anStats[nCount] = pStat->nPackedValue;
                ++nCount;
            }
        }

        for (int i = 0; i < nCount; ++i)
        {
            D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord((anStats[i] >> 16) & 0xFFFF);
            if (pItemStatCostTxtRecord)
            {
                STATLIST_UpdateStatOps(pStatList, anStats[i], pItemStatCostTxtRecord, 0);
            }
        }
    }

    if (pParent)
    {
        int bDamage = pStatList->dwFlags & 0x40000000;
        D2StatsArrayStrc* pStatsArray = (pStatList->dwFlags & 0x80000000) ? &((D2StatListExStrc*)pStatList)->FullStats : &pStatList->Stats;
        D2StatStrc* pStat = pStatsArray->pStat;
        D2StatStrc* pEnd = &pStat[pStatsArray->nStatCount];

        if (bDamage)
        {
            for (; pStat < pEnd; ++pStat)
            {
                D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(STAT_GETID(pStat->nPackedValue));
                if (pItemStatCostTxtRecord && !(pItemStatCostTxtRecord->nItemStatFlags[0] & gdwBitMasks[2]))
                {
                    STATLIST_UpdateStatValue(pParent, pStat->nPackedValue, -pStat->nValue, pOwner);
                }
            }
        }
        else
        {
            for (; pStat < pEnd; ++pStat)
            {
                STATLIST_UpdateStatValue(pParent, pStat->nPackedValue, -pStat->nValue, pOwner);
            }
        }
    }

    if (pUnit && pStatList->fpStatRemove)
    {
        pStatList->fpStatRemove(pUnit, pStatList->dwStateNo, pStatList);
    }
}

// 0x00626C00
void __fastcall D2Common_STATLIST_FreeStatListImpl_6FDB7050(D2StatListStrc* pStatList)
{
    D2Common_ExpireStatList_6FDB6E30(pStatList);

    if (((void*)pStatList->Stats.pStat))
        FOG_FreePool(pStatList->pMemPool, ((void*)pStatList->Stats.pStat), ".\\Stats\\StatsEx.cpp", 0x4D8, 0);

    if (pStatList->dwFlags & STATLIST_EXTENDED)
    {
        D2StatListExStrc* pStatListEx = (D2StatListExStrc*)pStatList;
        D2StatListStrc* pPrevious;
        for (D2StatListStrc* pCurrent = pStatListEx->pMyLastList; pCurrent; pCurrent = pPrevious)
        {
            pPrevious = pCurrent->pPrevLink;
            pCurrent->pParent = 0;
            pCurrent->pUnit = 0;
            if (pCurrent->dwFlags & STATLIST_EXTENDED)
                continue;

            if (pStatListEx->pMyLastList == pCurrent)
                pStatListEx->pMyLastList = pPrevious;

            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);

            pPrevious = pStatListEx->pMyLastList;
        }

        if (((void*)pStatListEx->FullStats.pStat))
            FOG_FreePool(pStatListEx->pMemPool, ((void*)pStatListEx->FullStats.pStat), ".\\Stats\\StatsEx.cpp", 0x4F3, 0);

        if (((void*)pStatListEx->ModStats.pStat))
            FOG_FreePool(pStatListEx->pMemPool, ((void*)pStatListEx->ModStats.pStat), ".\\Stats\\StatsEx.cpp", 0x4F7, 0);

        FOG_FreePool(pStatListEx->pMemPool, pStatListEx->StatFlags, ".\\Stats\\StatsEx.cpp", 0x4FA, 0);
    }

    FOG_FreePool(pStatList->pMemPool, pStatList, ".\\Stats\\StatsEx.cpp", 0x502, 0);
}

// 0x00626CD0
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList)
{
    if (pStatList && !STATLIST_IsExtended(pStatList))
    {
        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pStatList);
    }
}

// 0x00626CF0
void __fastcall STATLIST_FreeExtendedStatList(D2StatListStrc* pStatList)
{
    if (pStatList && STATLIST_IsExtended(pStatList))
    {
        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pStatList);
    }
}

// 0x00626D10
void __stdcall STATLIST_FreeStatListEx(D2UnitStrc* pUnit)
{
    if (pUnit->pStatListEx)
    {
        if (STATLIST_IsExtended(pUnit->pStatListEx))
        {
            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pUnit->pStatListEx);
        }

        pUnit->pStatListEx = 0;
    }
}

inline int STATLIST_IsExtended(D2StatListStrc* pStatList)
{
    return pStatList->dwFlags & STATLIST_EXTENDED;
}

// 0x00626D40
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallbackFunc, void* pGame)
{
    if (pUnit->pStatListEx)
    {
        if (pUnit->pStatListEx->dwFlags & 0x80000000)
        {
            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pUnit->pStatListEx);
        }
        pUnit->pStatListEx = 0;
    }

    D2StatListExStrc* pStatListEx = (D2StatListExStrc*)sub_0040B430(pUnit->pMemoryPool, sizeof(D2StatListExStrc), ".\\Stats\\StatsEx.cpp", 0x586, 0);
    memset(pStatListEx, 0, sizeof(D2StatListExStrc));
    pStatListEx->pMemPool = pUnit->pMemoryPool;
    pStatListEx->dwOwnerType = !pUnit ? 6 : pUnit->dwUnitType;
    pStatListEx->dwOwnerId = !pUnit ? -1 : pUnit->dwUnitId;
    pStatListEx->dwFlags = nFlags & 1 | 0x80000000;
    pStatListEx->pfOnValueChanged = (StatListValueChangeFunc)pCallbackFunc;
    pStatListEx->pGame = (D2GameStrc*)pGame;
    pStatListEx->pOwner = pUnit;
    const int nSize = sizeof(unsigned int) * 2 * ((sgptDataTables->nStatesTxtRecordCount + 31) / 32);
    pStatListEx->StatFlags = (unsigned int*)sub_0040B430(pUnit->pMemoryPool, nSize, ".\\Stats\\StatsEx.cpp", 0x593, 0);
    memset(pStatListEx->StatFlags, 0, nSize);
    pUnit->pStatListEx = pStatListEx;
}

// 0x00626E10
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListExStrc* pStatList, int bResetFlag)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 0x80000000))
        return;

    D2Common_ExpireStatList_6FDB6E30(pStatList);

    for (D2StatListStrc* pParent = pStatListEx; pParent; pParent = pParent->pParent)
    {
        if (pStatList == pParent)
            return;
    }

    if (pStatList->dwFlags & 4)
        pStatListEx->dwFlags |= 2;

    if (pStatList->dwFlags & 0x2000)
    {
        pStatList->pPrevLink = pStatListEx->pMyStats;
        if (pStatListEx->pMyStats)
            pStatListEx->pMyStats->pNextLink = pStatList;
        pStatList->pNextLink = 0;
        pStatListEx->pMyStats = pStatList;
        pStatList->pParent = pStatListEx;
        pStatList->pUnit = pUnit;
        return;
    }

    D2StatListStrc* pLastList = pStatListEx->pMyLastList;
    pStatList->pPrevLink = pLastList;
    if (pLastList)
        pLastList->pNextLink = pStatList;
    pStatList->pParent = pStatListEx;
    pStatListEx->pMyLastList = pStatList;
    pStatList->pUnit = pUnit;

    D2UnitStrc* pOwner = 0;
    if (STATLIST_IsExtended(pStatList))
        pOwner = pStatList->pOwner;

    if (STATLIST_IsExtended(pStatList) && (pStatList->dwFlags & 0x20000000))
    {
        int aStats[16];
        D2StatsArrayStrc* pStatsArray = STATLIST_GetStatsArray(pStatList);
        D2StatStrc* pStat = pStatsArray->pStat;
        D2StatStrc* pEnd = &pStat[pStatsArray->nStatCount];
        int nCount = 0;
        for (; pStat < pEnd; ++pStat)
        {
            const int nPacked = pStat->nPackedValue;
            D2ItemStatCostTxt* pRecord = ITEMS_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
            if (pRecord && pRecord->bHasOpApplyingToItem)
                aStats[nCount++] = nPacked;
        }

        for (int i = 0; i < nCount; ++i)
        {
            const int nPacked = aStats[i];
            D2ItemStatCostTxt* pRecord = PLAYER_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
            if (pRecord)
                STATLIST_UpdateStatOps(pStatList, nPacked, pRecord, 0);
        }
    }

    const unsigned int dwListFlags = pStatList->dwFlags;
    D2StatsArrayStrc* pStatsArray = (dwListFlags & 0x80000000) ? &pStatList->FullStats : &pStatList->Stats;
    D2StatStrc* pStat = pStatsArray->pStat;
    D2StatStrc* pEnd = &pStat[pStatsArray->nStatCount];
    if (bResetFlag)
    {
        pStatList->dwFlags = dwListFlags & ~0x40000000;
        for (; pStat < pEnd; ++pStat)
            STATLIST_UpdateStatValue(pStatListEx, pStat->nPackedValue, pStat->nValue, pOwner);
    }
    else
    {
        pStatList->dwFlags = dwListFlags | 0x40000000;
        for (; pStat < pEnd; ++pStat)
        {
            const int nPacked = pStat->nPackedValue;
            D2ItemStatCostTxt* pRecord = ITEMS_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
            if (pRecord && !(pRecord->nItemStatFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7]))
                STATLIST_UpdateStatValue(pStatListEx, nPacked, pStat->nValue, pOwner);
        }
    }
}

// 0x00627030
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
{
    if (!pStatList || !nValue)
    {
        return;
    }

    const int nLayer_StatId = STAT_MAKE(nStatId, nLayer);
    D2StatStrc* pStat = STATLIST_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        pStat = STATLIST_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    pStat->nValue += nValue;
    if (!pStat->nValue)
    {
        STATLIST_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }

    STATLIST_UpdateStatValue(pStatList, nLayer_StatId, nValue, 0);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
}

// 0x006270B0
int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
{
    if (!pStatList)
    {
        return 0;
    }

    const int nLayer_StatId = STAT_MAKE(nStatId, nLayer);
    D2StatStrc* pStat = STATLIST_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        if (!nValue)
        {
            return 0;
        }
        pStat = STATLIST_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    const int nDiffValue = nValue - pStat->nValue;
    if (!nDiffValue)
    {
        return 0;
    }

    if (!nValue)
    {
        STATLIST_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }
    else
    {
        pStat->nValue = nValue;
    }

    STATLIST_UpdateStatValue(pStatList, nLayer_StatId, nDiffValue, 0);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
    return 1;
}

// 0x00627150
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer)
{
    if (pStatList)
    {
        STATLIST_SetStatValue(pStatList, nStatId, nValue, nLayer);
    }
}

// 0x00627170
int __stdcall STATLIST_SetBaseStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer, D2UnitStrc* pUnit)
{
    if (!pStatList)
    {
        return 0;
    }

    const int nLayer_StatId = STAT_MAKE(nStatId, nLayer);
    D2StatStrc* pStat = STATLIST_FindStat(&pStatList->Stats, nLayer_StatId);
    if (!pStat)
    {
        if (!nValue)
        {
            return 0;
        }
        pStat = STATLIST_InsertStatOrFail(pStatList->pMemPool, &pStatList->Stats, nLayer_StatId);
    }

    const int nDiffValue = nValue - pStat->nValue;
    if (!nDiffValue)
    {
        return 0;
    }

    if (!nValue)
    {
        STATLIST_RemoveStat(pStatList->pMemPool, &pStatList->Stats, pStat);
    }
    else
    {
        pStat->nValue = nValue;
    }

    STATLIST_UpdateStatValue(pStatList, nLayer_StatId, nDiffValue, pUnit);
    if ((pStatList->dwFlags & STATLIST_EXTENDED) && pStatList->dwOwnerType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail((D2StatListExStrc*)pStatList, nLayer_StatId);
    }
    return 1;
}

// 0x00627220
void __stdcall STATLIST_SetBaseStat2(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer, D2UnitStrc* pUnit)
{
    if (pStatList)
    {
        STATLIST_SetBaseStat(pStatList, nStatId, nValue, nLayer, pUnit);
    }
}

// 0x00627250
int __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer)
{
    return STATLIST_SetStatValue(pStatList, nStatId, nValue, nLayer);
}

// 0x00627260
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer)
{
    if (STATLIST_SetStatValue(pUnit->pStatListEx, nStatId, nValue, nLayer) && pUnit->dwUnitType == UNIT_PLAYER)
    {
        STATLIST_InsertStatModOrFail(pUnit->pStatListEx, STAT_MAKE(nStatId, nLayer));
    }
}

// 0x006272A0
void __stdcall sub_006272A0_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer)
{
    STATLIST_AddStat(pStatList, nStatId, nValue, nLayer);
}

// 0x006272B0
void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer)
{
    if (nValue)
    {
        STATLIST_AddStat(pUnit->pStatListEx, nStatId, nValue, nLayer);
    }
}

// 0x006272E0
void __stdcall STATLIST_DeactivateTemporaryStates(D2UnitStrc* pUnit)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 2))
    {
        return;
    }

    D2StatListStrc* pPrevious;
    for (D2StatListStrc* pCurrent = pStatListEx->pMyLastList; pCurrent; pCurrent = pPrevious)
    {
        pPrevious = pCurrent->pPrevLink;
        if (!(pCurrent->dwFlags & 4))
        {
            continue;
        }
        if (pCurrent->dwStateNo)
        {
            STATES_ToggleState(pUnit, pCurrent->dwStateNo, 0);
        }
        if (!(pCurrent->dwFlags & 0x80000000))
        {
            D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
        }
        pPrevious = pStatListEx->pMyLastList;
    }
    pStatListEx->dwFlags &= ~2;
}

static inline const D2StatStrc* STATLIST_GetFirstStat_Inline(const D2StatsArrayStrc* pStats)
{
    return pStats->pStat;
}

// 0x00627340
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList)
{
    if (!pStatList)
    {
        return;
    }

    while (pStatList->Stats.nStatCount > 0)
    {
        STATLIST_SetStatValue(pStatList, (!pStatList ? 0 : pStatList->Stats.pStat)->nStat, 0, (!pStatList ? 0 : pStatList->Stats.pStat)->nLayer);
    }
}

// 0x00627410
void __stdcall STATLIST_RemoveAllStatsFromOverlay(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
        if (pStatListEx)
        {
            pStatListEx->dwFlags &= ~0x100;
            if (pUnit->pStatListEx && (pUnit->pStatListEx->dwFlags & 0x80000000))
            {
                if (D2StatListStrc* pStatList = STATLIST_FindStatListByFlag(pUnit->pStatListEx, 0x80))
                {
                    STATLIST_RemoveAllStats(pStatList);
                }
            }
        }
    }
}

// 0x00627460
void __stdcall STATLIST_UpdateStatListsExpiration(D2UnitStrc* pUnit, int nFrame)
{
    if (!pUnit)
    {
        return;
    }
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 0x80000000))
    {
        return;
    }

    D2StatListStrc* pCurrent = pStatListEx->pMyLastList;
    D2StatListStrc* pPrevious;
    if (nFrame)
    {
        for (; pCurrent; pCurrent = pPrevious)
        {
            pPrevious = pCurrent->pPrevLink;
            if ((pCurrent->dwFlags & 2) && pCurrent->dwExpireFrame <= nFrame)
            {
                if (!(pCurrent->dwFlags & 0x80000000))
                {
                    D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
                }
                pPrevious = pStatListEx->pMyLastList;
            }
        }
    }
    else
    {
        for (; pCurrent; pCurrent = pPrevious)
        {
            pPrevious = pCurrent->pPrevLink;
            if (pCurrent->dwFlags & 2)
            {
                --pCurrent->dwExpireFrame;
                if (pCurrent->dwExpireFrame <= nFrame)
                {
                    if (!(pCurrent->dwFlags & 0x80000000))
                    {
                        D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
                    }
                    pPrevious = pStatListEx->pMyLastList;
                }
            }
        }
    }
}

// 0x006274F0
void __stdcall STATLIST_MergeBaseStats(D2StatListStrc* pTargetStatList, D2StatListStrc* pSourceStatlist)
{
    if (pTargetStatList && pSourceStatlist)
    {
        D2StatStrc* pStat = pSourceStatlist->Stats.pStat;
        D2StatStrc* pEnd = &pStat[pSourceStatlist->Stats.nStatCount];
        for (; pStat < pEnd; ++pStat)
        {
            STATLIST_AddStat(pTargetStatList, pStat->nStat, pStat->nValue, pStat->nLayer);
        }
    }
}

// 0x00627540
void __stdcall D2Common_10469(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx || !(pStatListEx->dwFlags & 0x80000000))
    {
        return;
    }
    D2StatListStrc* pCurrent = pStatListEx->pMyLastList;
    if (!pCurrent)
    {
        return;
    }
    D2StatListStrc* pPrevious;
    do
    {
        pPrevious = pCurrent->pPrevLink;
        if (pCurrent->dwOwnerType != 4 && !(pCurrent->dwFlags & 0x181) && !STATES_CheckStateMaskStayDeathOnUnitByStateId(pUnit, pCurrent->dwStateNo))
        {
            if (!(pCurrent->dwFlags & 0x80000000))
            {
                D2Common_STATLIST_FreeStatListImpl_6FDB7050(pCurrent);
            }
            pPrevious = pStatListEx->pMyLastList;
        }
        pCurrent = pPrevious;
    }
    while (pPrevious);
}

// 0x006276C0
void __stdcall D2Common_10525(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    if (!pUnit1 || !pUnit2 || !(pUnit1->dwUnitType == UNIT_PLAYER || pUnit1->dwUnitType == UNIT_MONSTER))
    {
        return;
    }

    D2StatListExStrc* pStatListEx2 = pUnit2->pStatListEx;
    if (!pStatListEx2 || !(pStatListEx2->dwFlags & STATLIST_EXTENDED))
    {
        return;
    }

    for (D2StatStrc* j = pStatListEx2->FullStats.pStat, *pEnd = &pStatListEx2->FullStats.pStat[pStatListEx2->FullStats.nStatCount]; j < pEnd; ++j)
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(j->nStat);
        switch (pItemStatCostTxtRecord->nOp)
        {
        case 6:
        case 7:
            for (int i = 0; i < OPSTAT_COUNT; ++i)
            {
                const unsigned short nOpStat = pItemStatCostTxtRecord->wOpStat[i];
                if (nOpStat == STAT_NONE)
                {
                    break;
                }

                D2ItemStatCostTxt* pOpItemStatCostTxtRecord = ITEMS_GetItemStatCostTxtRecord(nOpStat);
                const int nOpLayer_StatId = nOpStat << STAT_SHIFT;
                const int nOpStatValue = STATLIST_GetStatFromLayer(pUnit1->pStatListEx, nOpLayer_StatId);
                STATLIST_UpdateUnitStat(pUnit1->pStatListEx, nOpLayer_StatId, nOpStatValue, pOpItemStatCostTxtRecord, pUnit1);
            }
            break;
        }
    }
}

// 0x006277E0
void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList)
{
    D2Common_ExpireStatList_6FDB6E30(pStatList);
}

// 0x006277F0
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->pStatListEx)
    {
        D2Common_ExpireStatList_6FDB6E30(pUnit->pStatListEx);
    }
}

// 0x00627810
int __stdcall D2Common_10531_SetStatInStatListLayer0(D2StatListStrc* pStatList, int nStatId, int nValue, int nUnused)
{
    return STATLIST_SetStatValue(pStatList, nStatId, nValue, 0);
}

// 0x00627830
int __stdcall STATLIST_GetStatAccumulated(D2UnitStrc* pUnit, int nStatId)
{
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
        return 0;

    if (!(pStatListEx->dwFlags & STATLIST_EXTENDED))
        return 0;

    return STATLIST_GetStatFromLayer(pStatListEx, nStatId << 16);
}

// 0x00627860
int __stdcall D2Common_11274(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pTarget || !pUnit)
        return 0;

    D2StatListExStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
        return 0;

    if (pStatList->pUnit != pTarget)
    {
        STATLIST_MergeStatLists(pTarget, pUnit, 1);
        return 0;
    }

    D2StatListExStrc* pTargetStatListEx = pTarget->pStatListEx;
    if (!pTargetStatListEx || !(pTargetStatListEx->dwFlags & 0x80000000))
        return 0;

    const unsigned int dwFlags = pStatList->dwFlags;
    if (!(dwFlags & 0x40000000))
        return 0;
    pStatList->dwFlags = dwFlags & ~0x40000000;

    D2StatsArrayStrc* pStatsArray = STATLIST_GetStatsArray(pStatList);
    D2StatStrc* pEnd = &pStatsArray->pStat[pStatsArray->nStatCount];
    for (D2StatStrc* i = pStatsArray->pStat; i < pEnd; ++i)
    {
        const int nPacked = i->nPackedValue;
        D2ItemStatCostTxt* pRecord = PLAYER_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
        if (pRecord && (pRecord->nItemStatFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7]))
            STATLIST_UpdateStatValue(pTargetStatListEx, nPacked, i->nValue, pUnit);
    }
    return 1;
}

// 0x00627910
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType)
{
    if (!pTarget || !pUnit)
    {
        return;
    }
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (!pStatListEx)
    {
        return;
    }
    if (pUnit->dwUnitType == UNIT_ITEM)
    {
        const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pUnit);
        if (nBodyLoc == 11 || nBodyLoc == 12)
        {
            D2Common_ExpireStatList_6FDB6E30(pStatListEx);
            return;
        }
    }
    if (pStatListEx->pUnit == pTarget)
    {
        if (bType)
        {
            if (pStatListEx->dwFlags & 0x40000000)
            {
                D2Common_11274(pTarget, pUnit);
            }
        }
        else if (!(pStatListEx->dwFlags & 0x40000000))
        {
            D2Common_11275(pTarget, pUnit);
        }
    }
    else
    {
        D2COMMON_10475_PostStatToStatList(pTarget, pStatListEx, bType);
        pStatListEx->pUnit = pTarget;
    }
}

// 0x006279A0
int __stdcall D2Common_10574(D2UnitStrc* pUnit, int nStateId, int bSet)
{
    if (!nStateId)
    {
        return 0;
    }
    D2StatListExStrc* pStatListEx = pUnit->pStatListEx;
    if (pStatListEx && (pStatListEx->dwFlags & 0x80000000))
    {
        if (D2StatListStrc* pStatList = D2Common_GetStateFromStatListEx_6FDB8190(pStatListEx, nStateId))
        {
            if (bSet)
            {
                if (!(pStatList->dwFlags & 0x2000))
                {
                    D2Common_ExpireStatList_6FDB6E30(pStatList);
                    pStatList->dwFlags |= 0x2000;
                    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                    return 1;
                }
            }
            else if (pStatList->dwFlags & 0x2000)
            {
                D2Common_ExpireStatList_6FDB6E30(pStatList);
                pStatList->dwFlags &= ~0x2000;
                D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                return 1;
            }
        }
    }
    return 0;
}

// 0x00627A40
int __stdcall D2Common_11275(D2UnitStrc* pTarget, D2UnitStrc* pUnit)
{
    if (!pTarget || !pUnit)
        return 0;

    D2StatListExStrc* pStatList = pUnit->pStatListEx;
    if (!pStatList)
        return 0;

    if (pStatList->pUnit != pTarget)
    {
        STATLIST_MergeStatLists(pTarget, pUnit, 0);
        return 0;
    }

    D2StatListExStrc* pTargetStatListEx = pTarget->pStatListEx;
    if (!pTargetStatListEx || !(pTargetStatListEx->dwFlags & 0x80000000))
        return 0;

    const unsigned int dwFlags = pStatList->dwFlags;
    if (dwFlags & 0x40000000)
        return 0;
    pStatList->dwFlags = dwFlags | 0x40000000;

    D2StatsArrayStrc* pStatsArray = STATLIST_GetStatsArray(pStatList);
    D2StatStrc* pEnd = &pStatsArray->pStat[pStatsArray->nStatCount];
    for (D2StatStrc* i = pStatsArray->pStat; i < pEnd; ++i)
    {
        const int nPacked = i->nPackedValue;
        D2ItemStatCostTxt* pRecord = PLAYER_GetItemStatCostTxtRecord((nPacked >> 16) & 0xFFFF);
        if (pRecord && (pRecord->nItemStatFlags[2 >> 3] & gdwBitMasks_006CE268[2 & 7]))
            STATLIST_UpdateStatValue(pTargetStatListEx, nPacked, -i->nValue, pUnit);
    }
    return 1;
}

// 0x00627AF0
int __fastcall STATLIST_HasSkillDesc(int nSkillId)
{
    if (D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId))
    {
        int nSkillDesc = pSkillsTxtRecord->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
            return 1;
    }
    return 0;
}

// 0x00627B30
int __cdecl STATLIST_GetItemTypesTxtRecordCount()
{
    return sgptDataTables->nItemTypesTxtRecordCount;
}

// 0x00627B40
int __cdecl STATLIST_ReturnZero()
{
    return 0;
}

// 0x00627B50
int __fastcall STATLIST_GetMinimum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA < nB ? nA : nB;
}

// 0x00627B60
int __fastcall STATLIST_GetMaximum(int nA, int nB, int nUnused1, int nUnused2)
{
    return nA > nB ? nA : nB;
}

// 0x00627B70
int __fastcall DUNGEON_ItemCalcGetRandomNumberInRange(int nMin, int nMax, int nUnused, void* pUserData)
{
    D2ItemCalcStrc* pItemCalc = (D2ItemCalcStrc*)pUserData;
    if (!pItemCalc)
    {
        return 0;
    }
    D2SeedStrc* pSeed = &pItemCalc->pUnit->pSeed;
    if (nMin >= nMax)
    {
        return nMin;
    }
    return nMin + ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin + 1);
}

// 0x00627BB0
int __fastcall STATLIST_ItemCalcGetStatValue(int nStatId, int nType, int nUnused, void* pUserData)
{
    int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
    int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
    D2ItemCalcStrc* pItemCalc = (D2ItemCalcStrc*)pUserData;
    if (pItemCalc && pItemCalc->pUnit && nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        if (nStatId == 19)
        {
            return UNITS_GetAttackRate(pItemCalc->pUnit);
        }
        switch (nType)
        {
        case 1:
            return STATLIST_GetUnitBaseStat(pItemCalc->pUnit, nStatId, 0);
        case 2:
            return STATLIST_UnitGetItemStatOrSkillStatValue(pItemCalc->pUnit, nStatId, 0);
        default:
            return STATLIST_UnitGetStatValue(pItemCalc->pUnit, nStatId, 0);
        }
    }
    return 0;
}

// 0x00627C20
int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc)
{
    if (!sgptDataTables->pItemsCode)
        return 0;

    if (nCalc >= sgptDataTables->nItemsCodeSize)
        return 0;

    D2ItemCalcStrc pItemCalc;
    pItemCalc.pUnit = pUnit;
    pItemCalc.pItem = pItem;
    return DATATBLS_CalcEvaluateExpression(&sgptDataTables->pItemsCode[nCalc], sgptDataTables->nItemsCodeSize - nCalc, ITEMMODS_GetCalcParamValue_Return0, gpItemsCalcFunctions, gnItemsCalcFunctions, &pItemCalc);
}

#include "gen/data/Source/D2Common/Stats/StatsEx.inc"
