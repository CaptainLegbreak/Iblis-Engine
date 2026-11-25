#include "D2Game.h"
#include "D2Structs.h"
#include "D2Txt.h"



D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem);                                                 // 0x00627D90
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex);                             // 0x00629DF0
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670
int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem);                                                    // 0x0062BA80
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId);                                              // 0x006335F0
void __stdcall ITEMMODS_AssignProperty(int nMode, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pProperty, int nSet, int nUnused);

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// build: symbol ?ITEMS_RollSuperiorItemRecord@* 0x005C2970
static int __stdcall ITEMS_RollSuperiorItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    D2QualityItemDataTbl* pQualityItemDataTbl = DATATBLS_GetQualityItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pQualityItemDataTbl)
    {
        return 0;
    }

    if (!pItemsTxtRecord)
    {
        return 0;
    }

    int nCount = pQualityItemDataTbl->nQualityItemsTxtRecordCount;
    unsigned char bRecordChecked[10] = {};
    if (ITEMS_CheckIfThrowable(pItem) || pItemsTxtRecord->nNoDurability)
    {
        nCount = 4;
    }

    while (1)
    {
        unsigned char* pChecked;
        unsigned int nFileIndex;
        do
        {
            nFileIndex = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nCount);
            pChecked = &bRecordChecked[nFileIndex];
        }
        while (*pChecked);

        D2QualityItemsTxt* pQualityItemsTxtRecord = DATATBLS_GetQualityItemsTxtRecord(nFileIndex);
        if (!pQualityItemsTxtRecord)
        {
            return 0;
        }

        if (ITEMMODS_CanItemBeHighQuality(pItem, pQualityItemsTxtRecord))
        {
            ITEMS_SetFileIndex(pItem, nFileIndex);
            ITEMMODS_AssignProperty(1, 0, pItem, pQualityItemsTxtRecord, 0, 0);
            ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
            return 1;
        }

        *pChecked = 1;
        if (nCount <= 0)
        {
            return 0;
        }

        int i = 0;
        do
        {
            if (!bRecordChecked[i])
            {
                goto LBL_NEXT;
            }
            ++i;
        }
        while (i < nCount);

        return 0;

LBL_NEXT:
        ;
    }
}

// 0x005C2AD0
int __fastcall ITEMS_RollSuperiorItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    ITEMS_GetItemFormat(pItem);
    return ITEMS_RollSuperiorItemRecord(pItemDrop, pItem);
}
