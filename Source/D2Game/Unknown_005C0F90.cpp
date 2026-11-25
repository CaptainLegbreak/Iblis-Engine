#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Records.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2TxtTables.h"
#include "D2BookDataTbl.h"
struct D2UnitStrc;

union D2SeedStrc;
struct D2SkillsTxt;
struct D2ItemsTxt;
struct D2BooksTxt;
struct D2BookDataTbl;
struct D2SetItemsTxt;

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90
int __fastcall GAME_GetUnitGUID(D2UnitStrc*); // 0x00451F50
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc*); // 0x004DC0B0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10
void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150

struct D2SkillsTxt { char pad0[0x18]; short nItemType; char pad1[0x23C-0x1A]; };

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670
int __stdcall ITEMS_GetItemQuality(D2UnitStrc*); // 0x00627E70
int __stdcall ITEMSIsA(D2UnitStrc*, int); // 0x00629BB0

struct D2ItemsTxt
{
    char unk0x00[0x80];
    int dwCode;
};


D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables(); // 0x006374A0
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

struct D2ItemDropStrc
{
    char unk0x00[0x40];
    unsigned int nItemIndex;
    char unk0x44[0x3C];
    unsigned int dwFlags2;
};

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
int __stdcall sub_005C2740_RollLegacySetItem(D2UnitStrc* pItem); // 0x005C2740
void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0
int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0
void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0
void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0
static int __stdcall sub_005C25C0_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem);

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

static inline D2SkillsTxt* GetSkillsRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}

// 0x005C25C0
static int __stdcall sub_005C25C0_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int nLegibleSets = 0;
    int nAccumulatedRarity = 0;
    int nIndex = -1;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const unsigned short nItemFormat = ITEMS_GetItemFormat(pItem);
    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    const int nItemLevel = ITEMS_GetItemLevel(pItem);
    int rarityData[512];

    D2SetItemsTxt* pSetItemsTxtRecord = sgptDataTables->pSetItemsTxt;
    const int nCount = sgptDataTables->nSetItemsTxtRecordCount;
    int i = 0;
    if (nCount <= 0)
    {
        return 0;
    }

    do
    {
        if ((pSetItemsTxtRecord->wVersion < 100 || nItemFormat >= 100) && pSetItemsTxtRecord->wLvl <= nItemLevel
            && dwCode == pSetItemsTxtRecord->dwItemCode
            && (pSetItemsTxtRecord->nSetId != 29 || pItemDrop->dwFlags2 & 1))
        {
            if (pItemDrop->nItemIndex > 0 && pItemDrop->nItemIndex - 1 == i)
            {
                nIndex = i;
            }

            rarityData[2 * nLegibleSets] = i;
            rarityData[2 * nLegibleSets + 1] = pSetItemsTxtRecord->dwRarity;
            if (!pSetItemsTxtRecord->dwRarity)
            {
                rarityData[2 * nLegibleSets + 1] = 1;
            }

            nAccumulatedRarity += rarityData[2 * nLegibleSets + 1];
            ++nLegibleSets;
        }
        ++i;
        ++pSetItemsTxtRecord;
    }
    while (i < nCount);

    int nFileIndex = nIndex;
    if (nIndex < 0)
    {
        if (!nAccumulatedRarity)
        {
            return 0;
        }

        int nChance = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nAccumulatedRarity);
        int nCounter = 0;
        while (nCounter < nLegibleSets)
        {
            if (nChance < rarityData[2 * nCounter + 1])
            {
                if (nCounter < 0)
                {
                    return 0;
                }

                nFileIndex = rarityData[2 * nCounter];
                goto LBL_SET;
            }

            nChance -= rarityData[2 * nCounter + 1];
            ++nCounter;
        }

        return 0;
    }

LBL_SET:
    ITEMS_SetFileIndex(pItem, nFileIndex);
    ITEMS_SetItemFlag(pItem, 0x10, 0);
    ITEMMODS_AssignProperty(4, 0, pItem, 0, 0, 0);
    return 1;
}

int __fastcall ITEMS_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C25C0_RollSetItemRecord(pItemDrop, pItem);
    }

    return sub_005C2740_RollLegacySetItem(pItem);
}
