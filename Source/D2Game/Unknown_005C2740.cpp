#include "D2StatIds.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2SetsTxt.h"
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc*); // 0x00650E50
void __fastcall SEED_InitLowSeed(D2SeedStrc*, unsigned int); // 0x00650E40
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, unsigned short); // 0x00625480
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, unsigned short); // 0x006253B0
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, unsigned short); // 0x00627260
void __stdcall ITEMS_SetFileIndex(D2UnitStrc*, unsigned int); // 0x00629DF0
void __stdcall ITEMS_SetItemFlag(D2UnitStrc*, unsigned int, int); // 0x006280D0
void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0

static inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0) return 0;
    if (nMax & (nMax - 1)) return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;
    return (nMax - 1) & (unsigned int)SEED_RollRandomNumberInline(pSeed);
}

static inline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInline(pSeed, nMax);
}

// 0x005C2740
int __stdcall sub_005C2740_RollLegacySetItem(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxt) return 0;
    const unsigned int nSavedSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(pItem));
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    const int nDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
    const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, STAT_MAXDURABILITY, 0);
    int nNew = 2 * nDurability;
    if (nNew >= 255) nNew = 255;
    STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nNew, 0);
    nNew = 2 * nMaxDurability;
    if (nNew >= 255) nNew = 255;
    STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, nNew, 0);
    D2SetsTxt* pSets = sgptDataTables->pSetsTxt;
    int i = 0;
    for (; i < sgptDataTables->nSetsTxtRecordCount; ++i)
    {
        if (pSets[i].wVersion >= 100) break;
    }
    const int nCount = i;
    const unsigned int nStart = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nCount);
    int nFileIndex = -1;
    for (i = 0; i < nCount; ++i)
    {
        D2SetsTxt* pSet = &pSets[(i + nStart) % nCount];
        if (pSet->wVersion < 100 || nFormat >= 100)
        {
            for (int j = 0; j < pSet->nSetItems; ++j)
            {
                if (pItemsTxt->dwCode == pSet->pSetItem[j]->dwItemCode)
                {
                    nFileIndex = pSet->pSetItem[j]->wSetItemId;
                    break;
                }
            }
        }
    }
    if (nFileIndex != -1)
    {
        ITEMS_SetFileIndex(pItem, nFileIndex);
        ITEMS_SetItemFlag(pItem, 0x10, 0);
        ITEMMODS_AssignProperty(4, 0, pItem, 0, 0, 0);
        return 1;
    }
    SEED_InitLowSeed(ITEMS_GetItemSeed(pItem), nSavedSeed);
    return 0;
}
