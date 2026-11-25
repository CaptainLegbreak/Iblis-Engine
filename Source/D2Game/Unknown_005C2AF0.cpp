#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2LowQualityItemsTxt;
union D2SeedStrc;
struct D2MagicAffixTxt;
struct D2RareAffixIndexAndPtrStrc;
struct D2ItemsTxt;
struct D2LowQualityItemDataTbl;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280

short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0
D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90
void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80
void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix); // 0x00628010
void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400
D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0
void __stdcall ITEMMODS_AssignProperty(int nMode, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nSet, int nUnused); // 0x0065FEC0
extern const int gnRareAffixCounts[]; // 0x006E3014
static int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1E80

struct D2LowQualityItemDataTbl
{
    int nLowQualityItemsTxtRecordCount;
    D2LowQualityItemsTxt* pLowQualityItemsTxt;
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260
int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930
int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2LowQualityItemDataTbl* __fastcall DATATBLS_GetLowQualityItemDataTables(); // 0x006375B0

static inline unsigned int sub_RareSeedRoll(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int sub_RareSeedRollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax > 0)
    {
        if ((nMax - 1) & nMax)
        {
            return sub_RareSeedRoll(pSeed) % nMax;
        }
        else
        {
            return sub_RareSeedRoll(pSeed) & (nMax - 1);
        }
    }

    return 0;
}

// build: symbol ?SKILLITEM_RollRareAffixLegacy@* 0x005C19A0
static unsigned short __stdcall SKILLITEM_RollRareAffixLegacy(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].nIndex = nAffixIndex + i;
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

// build: symbol ?SKILLITEM_RollRareAffix@* 0x005C1AB0
static unsigned short __stdcall SKILLITEM_RollRareAffix(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].nIndex = nAffixIndex + i;
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

static inline unsigned short D2GAME_RollRareAffixInline(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return SKILLITEM_RollRareAffix(pItem, bPrefix);
    }

    return SKILLITEM_RollRareAffixLegacy(pItem, bPrefix);
}

static __forceinline bool ITEMS_HasAffixOrGroupInline(D2UnitStrc* pItem, unsigned short nAffix, int bPrefix)
{
    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        const unsigned short nSlotAffix = bPrefix ? ITEMS_GetPrefixId(pItem, nAffixSlot) : ITEMS_GetSuffixId(pItem, nAffixSlot);
        if (D2MagicAffixTxt* pSlotRecord = DATATBLS_GetMagicAffixTxtRecord(nSlotAffix))
        {
            D2MagicAffixTxt* pAffixRecord = DATATBLS_GetMagicAffixTxtRecord(nAffix);
            if (nAffix == nSlotAffix || pAffixRecord->dwGroup == pSlotRecord->dwGroup)
            {
                return true;
            }
        }
    }

    return false;
}

static inline short ITEMS_RollMagicAffixesInline(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

static __forceinline void ITEMS_ApplyRareAffixesInline(D2UnitStrc* pItem)
{
    ITEMS_SetItemFlag(pItem, 0x10, 0);

    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        if (D2MagicAffixTxt* pPrefixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pPrefixRecord, 0, 0);
        }

        if (D2MagicAffixTxt* pSuffixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pSuffixRecord, 0, 0);
        }
    }
}

int __stdcall sub_005C1BF0_RollRareItemNew(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1BF0

int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1E80

// Out of line as in the original: it takes an argument in eax, a convention the compiler gives only a static whose callers are all in this object.
// build: symbol ?SKILLITEM_PercentWithMinimum@* 0x005C0D40
static __declspec(noinline) int __stdcall SKILLITEM_PercentWithMinimum(int nValue, int nPercent, int nMin)
{
    const int nResult = nValue * nPercent / 100;
    if (nResult < nMin)
    {
        return nMin;
    }
    return nResult;
}

// 0x005C2AF0
int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            unsigned int nMaxDurability = pTxt->nDurability / 3;
            if (!nMaxDurability)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nDurability, 0);
            STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, nMaxDurability, 0);
        }
    }

    if (ITEMSIsA(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MAXDAMAGE, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_MAXDAMAGE, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MINDAMAGE, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_MINDAMAGE, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MAXDAMAGE, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MAXDAMAGE, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MINDAMAGE, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MINDAMAGE, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MINDAMAGE, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MINDAMAGE, nMinThrowDamage, 0);

            const int nMaxThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MAXDAMAGE, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMSIsA(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_ARMORCLASS, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_ARMORCLASS, nArmorClass, 0);
        nResult = 1;
    }

    return nResult;
}

// 0x005C2D40
int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    D2LowQualityItemDataTbl* pLowQualityItemDataTbl = DATATBLS_GetLowQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pLowQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetFileIndex(pItem, SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), pLowQualityItemDataTbl->nLowQualityItemsTxtRecordCount));

    int nResult = 0;
    if (ITEMS_HasDurability(pItem))
    {
        if (D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId))
        {
            int nMaxDurability = 33 * pTxt->nDurability / 100;
            if (nMaxDurability < 1)
            {
                nMaxDurability = 1;
            }

            const unsigned int nHalf = (unsigned int)nMaxDurability / 2;
            unsigned int nDurability = ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nHalf) + nHalf;
            if (!nDurability)
            {
                nDurability = 1;
            }

            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nDurability, 0);
            STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, nMaxDurability, 0);
        }
    }

    if (ITEMSIsA(pItem, 0x2D))
    {
        int nMaxDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MAXDAMAGE, 0) / 100;
        if (nMaxDamage < 2)
        {
            nMaxDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_MAXDAMAGE, nMaxDamage, 0);

        int nMinDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_MINDAMAGE, 0) / 100;
        if (nMinDamage < 1)
        {
            nMinDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_MINDAMAGE, nMinDamage, 0);

        int nMaxSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MAXDAMAGE, 0) / 100;
        if (nMaxSecondaryDamage < 2)
        {
            nMaxSecondaryDamage = 2;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MAXDAMAGE, nMaxSecondaryDamage, 0);

        int nMinSecondaryDamage = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_SECONDARY_MINDAMAGE, 0) / 100;
        if (nMinSecondaryDamage < 1)
        {
            nMinSecondaryDamage = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MINDAMAGE, nMinSecondaryDamage, 0);

        if (ITEMS_CheckIfThrowable(pItem))
        {
            const int nMinThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MINDAMAGE, 0), 75, 2);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MINDAMAGE, nMinThrowDamage, 0);

            const int nMaxThrowDamage = SKILLITEM_PercentWithMinimum(STATLIST_UnitGetItemStatOrSkillStatValue(pItem, STAT_ITEM_THROW_MAXDAMAGE, 0), 75, 1);
            STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MAXDAMAGE, nMaxThrowDamage, 0);
        }
        nResult = 1;
    }
    else if (ITEMSIsA(pItem, 0x32))
    {
        int nArmorClass = 75 * STATLIST_GetUnitBaseStat(pItem, STAT_ARMORCLASS, 0) / 100;
        if (nArmorClass <= 0)
        {
            nArmorClass = 1;
        }
        STATLIST_SetUnitStat(pItem, STAT_ARMORCLASS, nArmorClass, 0);
        nResult = 1;
    }

    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return nResult;
}
