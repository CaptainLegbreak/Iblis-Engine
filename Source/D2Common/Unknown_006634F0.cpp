#include "D2StatIds.h"
#include "D2DataTbls.h"

#include "D2CmpTileRecord.h"

#include "D2GameTypes.h"

#include "D2DrlgMaps.h"

#include "D2CmpTypes.h"

#include "D2LRUNode.h"

#include "D2Path.h"

#include "D2Records.h"

#include "D2ItemsWorld.h"

#include "D2Common.h"

#include "D2Structs.h"

#include "D2LevelTxt.h"

struct D2InventoryStrc;

union D2SeedStrc;

struct D2Rolled6634F0Strc;

struct D2Roll8Strc;

struct D2Roll16Strc;

struct D2Roll24Strc;

struct D2Roll20Strc;

struct D2Roll28Strc;

struct D2HirelingTxt;

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct D2Rolled6634F0Strc
{
    int nType;
    int n04;
    int n08;
    int n0C;
    int n10;
    int n14;
    int n18;
    int n1C;
    int n20;
    int n24;
    int n28;
    int n2C;
    int n30;
    int n34;
    unsigned short wFlags;
};

struct D2Roll8Strc { int a; int b; };

struct D2Roll16Strc { int a; int b; int c; int d; };

struct D2Roll24Strc { int a; int b; int c; int d; int e; int f; };

struct D2Roll20Strc { int a; int b; int c; int d; int e; };

struct D2Roll28Strc { int a; int b; int c; int d; int e; int f; int g; };

extern const int gnHirelingRollBase1[]; // 0x007484CC

extern const int gnHirelingRollCount1[]; // 0x007484DC

extern const int gnHirelingRollBase2[]; // 0x007484F0

extern const int gnHirelingRollCount2[]; // 0x00748500

extern const int gnHirelingRollBase3[]; // 0x00748514

extern const int gnHirelingRollCount3[]; // 0x00748524

extern const int gnHirelingRollBase4[]; // 0x00748538

extern const int gnHirelingRollCount4[]; // 0x00748548

extern const D2Roll8Strc gaHirelingRollStart[]; // 0x00748558

extern const D2Roll16Strc gaHirelingRoll1[]; // 0x00748578

extern const D2Roll16Strc gaHirelingRoll2[]; // 0x007485D8

extern const D2Roll24Strc gaHirelingRoll3[]; // 0x00748638

extern const D2Roll20Strc gaHirelingRoll4[]; // 0x007486C8

extern const D2Roll28Strc gaHirelingRollLevel[]; // 0x007487B8

typedef unsigned short Unicode;

extern "C" const unsigned short gnHirelingDescStringIds[9]; // 0x006EE410

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromClassId(int bExpansion, int nClassId, D2HirelingTxt* pOldRecord); // 0x00656440

D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromNameId(int bExpansion, unsigned short nNameId, D2HirelingTxt* pOldRecord); // 0x00656390

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

extern const int gnSetMaskToBonusMappingTable[0x40]; // 0x006EE440

void __fastcall sub_M102_UseBonusCount_00663A10(int nCount);

D2UnitStrc* __stdcall INVENTORY_IsItemInInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063E070

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370

int __fastcall sub_00663A20_SetItemBonusStates(D2UnitStrc* pItem, unsigned int nSetItemMask); // 0x00663A20

int __fastcall sub_00663B40_SetBonusStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3); // 0x00663B40

// 0x006634F0
int __fastcall sub_006634F0_RollSeededRecord(int nSeed, D2Rolled6634F0Strc* pOut, unsigned char nLevel)
{
    if (!nSeed)
        return 0;
    if (!pOut || nLevel > 2)
        return 0;

    const int nType = pOut->nType;
    if (nType < 0 || nType > 3)
        return 0;

    D2SeedStrc tSeed;
    pOut->wFlags = 0;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, nSeed);

    pOut->n34 = gaHirelingRollStart[nType].a;
    pOut->n20 = gaHirelingRollStart[nType].b;

    const int nRoll1 = ITEMS_RollLimitedRandomNumber(&tSeed, gnHirelingRollCount1[nType]) + gnHirelingRollBase1[nType];
    pOut->n04 = gaHirelingRoll1[nRoll1].a;
    pOut->n18 = gaHirelingRoll1[nRoll1].b;
    pOut->n20 += gaHirelingRoll1[nRoll1].d;
    pOut->n34 += gaHirelingRoll1[nRoll1].c;

    const int nRoll2 = ITEMS_RollLimitedRandomNumber(&tSeed, gnHirelingRollCount2[nType]) + gnHirelingRollBase2[nType];
    pOut->n08 = gaHirelingRoll2[nRoll2].a;
    pOut->n1C = gaHirelingRoll2[nRoll2].b;
    pOut->n20 += gaHirelingRoll2[nRoll2].d;
    pOut->n34 += gaHirelingRoll2[nRoll2].c;

    const int nRoll3 = ITEMS_RollLimitedRandomNumber(&tSeed, gnHirelingRollCount3[nType]) + gnHirelingRollBase3[nType];
    if (nType < 3)
    {
        pOut->n0C = gaHirelingRoll3[nRoll3].a;
        pOut->n14 = 0;
    }
    else
    {
        pOut->n0C = 0;
        pOut->n14 = gaHirelingRoll3[nRoll3].a;
    }
    pOut->n24 = gaHirelingRoll3[nRoll3].c;
    pOut->n28 = gaHirelingRoll3[nRoll3].d;
    if (!gaHirelingRoll3[nRoll3].b)
        pOut->wFlags |= 1;
    pOut->n20 += gaHirelingRoll3[nRoll3].f;
    pOut->n34 += gaHirelingRoll3[nRoll3].e;

    const int nRoll4 = ITEMS_RollLimitedRandomNumber(&tSeed, gnHirelingRollCount4[nType]) + gnHirelingRollBase4[nType];
    pOut->n2C = gaHirelingRoll4[nRoll4].a;
    pOut->n30 = gaHirelingRoll4[nRoll4].d;
    if (pOut->n2C >= 9 && pOut->n2C <= 0xB)
        pOut->n10 = 1;
    else
        pOut->n10 = 0;
    pOut->n20 += gaHirelingRoll4[nRoll4].c;
    pOut->n34 += gaHirelingRoll4[nRoll4].b;

    if (nLevel)
    {
        pOut->n18 += gaHirelingRollLevel[nLevel].a;
        pOut->n1C += gaHirelingRollLevel[nLevel].b;
        pOut->n20 += gaHirelingRollLevel[nLevel].c;
        pOut->n24 *= gaHirelingRollLevel[nLevel].d;
        pOut->n28 *= gaHirelingRollLevel[nLevel].e;
        pOut->n30 += gaHirelingRollLevel[nLevel].f;
        pOut->n34 *= gaHirelingRollLevel[nLevel].g;
    }
    return 1;
}

#include "gen/data/Source/D2Common/Unknown_006634F0.inc"

// 0x00663720
const Unicode* __fastcall MONSTERS_GetHirelingDescString(int nId)
{
    if (nId >= 0 && nId < sizeof(gnHirelingDescStringIds) / sizeof(gnHirelingDescStringIds[0]) && gnHirelingDescStringIds[nId])
    {
        return D2LANG_GetStringFromTblIndex(gnHirelingDescStringIds[nId]);
    }

    return 0;
}

// 0x00663740
void __stdcall sub_00663740(int nUnused1)
{
}

// 0x00663790
int __stdcall MONSTERS_GetHirelingExpForNextLevel(int nLevel, int nExpPerLevel)
{
    return nExpPerLevel * nLevel * nLevel * (nLevel + 1);
}

// 0x00663750
int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, int nNameId)
{
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromClassId(bExpansion, nClassId, 0);
    if (pHirelingTxtRecord)
    {
        return pHirelingTxtRecord->dwAct - 1;
    }

    pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromNameId(bExpansion, nNameId, 0);
    if (pHirelingTxtRecord)
    {
        return pHirelingTxtRecord->dwAct - 1;
    }

    return 0;
}

// 0x006637B0
unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling)
{
    const int nLevel = STATLIST_UnitGetStatValue(pHireling, STAT_LEVEL, 0);
    unsigned int nCost = 15 * (nLevel * nLevel / 2);
    if (nCost > 50000)
    {
        nCost = 50000;
    }

    return nCost;
}

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short unk0x3A;
};

D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x00656580

static inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return lSeed;
}

// 0x006637F0
int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit)
{
    D2HirelingTxt* pRecords[16];
    D2SeedStrc tSeed;

    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, nLowSeed);

    int nEntries = 0;
    D2HirelingTxt* pRecord = 0;
    pRecords[0] = 0;
    while (1)
    {
        pRecord = DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(bExpansion, nAct, nDifficulty, pRecord);
        if (!pRecord)
        {
            break;
        }
        pRecords[nEntries] = pRecord;
        ++nEntries;
    }

    if (!nEntries)
    {
        return 0;
    }

    D2HirelingTxt* pHirelingTxtRecord = pRecords[ITEMS_RollLimitedRandomNumber(&tSeed, nEntries)];
    pHirelingInit->nId = pHirelingTxtRecord->nId;

    const int nBaseLevel = STATLIST_UnitGetStatValue(pMonster, STAT_LEVEL, 0) - 5;
    int nLevel = nBaseLevel + (unsigned int)SEED_RollRandomNumber(&tSeed) % 5;
    if (nLevel < 2)
    {
        nLevel = 2;
    }

    const int nLevelUps = nLevel - pHirelingTxtRecord->nHirelingLevel;
    nLevel = pHirelingTxtRecord->nHirelingLevel + nLevelUps;
    pHirelingInit->nLevel = nLevel;

    pHirelingInit->nHitpoints = pHirelingTxtRecord->dwHitpoints + nLevelUps * pHirelingTxtRecord->dwHitpointsPerLvl;
    pHirelingInit->nHitpoints = D2_MAX(pHirelingInit->nHitpoints, 40);

    pHirelingInit->nStrength = pHirelingTxtRecord->nStr + (nLevelUps * pHirelingTxtRecord->nStrPerLvl >> 3);
    pHirelingInit->nStrength = D2_MAX(pHirelingInit->nStrength, 10);

    pHirelingInit->nDexterity = pHirelingTxtRecord->nDex + (nLevelUps * pHirelingTxtRecord->nDexPerLvl >> 3);
    pHirelingInit->nDexterity = D2_MAX(pHirelingInit->nDexterity, 10);

    pHirelingInit->nGold = pHirelingTxtRecord->nGold * (15 * nLevelUps + 100) / 100;
    pHirelingInit->nGold = D2_MAX(pHirelingTxtRecord->nGold, pHirelingInit->nGold);

    pHirelingInit->nExperience = (nLevel + 1) * pHirelingTxtRecord->dwExpPerLvl * nLevel * nLevel;
    pHirelingInit->nExperience = D2_MAX(pHirelingInit->nExperience, 0);

    pHirelingInit->nDefense = pHirelingTxtRecord->dwDefense + nLevelUps * pHirelingTxtRecord->dwDefensePerLvl;
    pHirelingInit->nDefense = D2_MAX(pHirelingInit->nDefense, 0);

    pHirelingInit->nMinDamage = pHirelingTxtRecord->nDmgMin + (nLevelUps * pHirelingTxtRecord->nDmgPerLvl >> 3);
    pHirelingInit->nMinDamage = D2_MAX(pHirelingInit->nMinDamage, 0);

    pHirelingInit->nMaxDamage = pHirelingTxtRecord->nDmgMax + (nLevelUps * pHirelingTxtRecord->nDmgPerLvl >> 3);
    pHirelingInit->nMaxDamage = D2_MAX(pHirelingInit->nMaxDamage, 1);

    pHirelingInit->nShare = pHirelingTxtRecord->dwShare;
    pHirelingInit->nShare = D2_MAX(pHirelingInit->nShare, 0);

    pHirelingInit->nResist = pHirelingTxtRecord->dwResist;
    pHirelingInit->nResist = D2_MAX(pHirelingInit->nResist, 0);

    pHirelingInit->nHireDesc = pHirelingTxtRecord->nHireDesc;
    pHirelingInit->field_34 = 1;
    pHirelingInit->nFlags = 0;
    return 1;
}

// 0x00663A10
static int sub_00663A10_GetSetBonusCount(unsigned int nSetItemMask)
{
    if (nSetItemMask >= sizeof(gnSetMaskToBonusMappingTable) / sizeof(gnSetMaskToBonusMappingTable[0]))
        return 0;
    return gnSetMaskToBonusMappingTable[nSetItemMask];
}

void __stdcall sub_M102_Emit_00663A10(int nUnused, unsigned int nSetItemMask)
{
    sub_M102_UseBonusCount_00663A10(sub_00663A10_GetSetBonusCount(nSetItemMask));
}

__forceinline unsigned int ITEMS_GetStoreSetItemsMaskInline(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2UnitStrc* pInventoryItem = INVENTORY_IsItemInInventory(pUnit->pInventory, pItem);
    if (!pInventoryItem)
    {
        return 0;
    }

    if (INVENTORY_GetItemNodePage(pInventoryItem) != 3)
    {
        return 0;
    }

    return ITEMS_GetSetItemsMask(pUnit, pItem, 1);
}

extern const int gnItemSetStates[]; // 0x006EE424

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062A490

int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem); // 0x0062B3A0

int __stdcall D2Common_10574(D2UnitStrc* pUnit, int nStateId, int bSet); // 0x006279A0

// 0x00663A20
int __fastcall sub_00663A20_SetItemBonusStates(D2UnitStrc* pItem, unsigned int nSetItemMask)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == 4 && ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        const D2SetItemsTxt* pSetItemsTxt = ITEMS_GetSetItemsTxtRecordFromItem(pItem);
        if (pSetItemsTxt)
        {
            switch (pSetItemsTxt->nAddFunc)
            {
            case 0:
                return 0;

            case 1:
            {
                const int nSetItems = ITEMS_GetNoOfSetItemsFromItem(pItem);
                for (int i = 0; i < 6; ++i)
                {
                    int nIndex = i;
                    if (i != nSetItems)
                    {
                        if (i > nSetItems)
                        {
                            nIndex -= 1;
                        }

                        if ((1 << i) & nSetItemMask)
                        {
                            D2Common_10574(pItem, gnItemSetStates[nIndex], 0);
                        }
                        else
                        {
                            D2Common_10574(pItem, gnItemSetStates[nIndex], 1);
                        }
                    }
                }
                break;
            }

            case 2:
            {
                const int nBonuses = (nSetItemMask >= 0x40 ? 0 : gnSetMaskToBonusMappingTable[nSetItemMask]) - 1;

                for (int i = 0; i < nBonuses; ++i)
                {
                    D2Common_10574(pItem, gnItemSetStates[i], 0);
                }

                if (nBonuses >= 5)
                {
                    return 1;
                }

                for (int i = nBonuses; i < 5; ++i)
                {
                    D2Common_10574(pItem, gnItemSetStates[i], 1);
                }
                break;
            }
            }

            return 1;
        }
    }

    return 0;
}

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFlags, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);             // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);        // 0x00625D00
void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                           // 0x00626CD0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATLIST_AddStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627030
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList);                                         // 0x00627340
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList);                               // 0x006277E0
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0
int __stdcall ITEMS_IsMagSetRarUniCrfOrTmp(D2UnitStrc* pItem);                                              // 0x0062A0F0
void __fastcall ITEMMODS_UpdateFullSetBoni(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nState);               // 0x00660120

// 0x00663B40
int __fastcall sub_00663B40_SetBonusStatList(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3)
{
    if (a3 > 1)
    {
        return 0;
    }

    if (!pUnit || !pItem || (!pItem ? 6 : pItem->dwUnitType) != 4 || ITEMS_GetItemQuality(pItem) != ITEMQUAL_SET)
    {
        return 0;
    }

    if ((!pUnit ? 6 : pUnit->dwUnitType) == 4 && ITEMS_IsMagSetRarUniCrfOrTmp(pUnit))
    {
        return 0;
    }

    D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
    if (!pSetItemsTxtRecord)
    {
        return 0;
    }

    const int nValue = pSetItemsTxtRecord->nSetId;
    if (nValue < 0 || nValue >= sgptDataTables->nSetsTxtRecordCount)
    {
        return 0;
    }

    int nIndex = -1;
    D2StatListStrc* pStatList;
    int nState;
    int i = 0;
    for (;;)
    {
        if (!(i < 6))
            break;
        nState = gnItemSetStates[i];
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList)
        {
            if (nValue == STATLIST_GetStatValue(pStatList, STAT_VALUE, 0))
            {
                if (a3 == 0)
                {
                    STATLIST_RemoveAllStats(pStatList);
                }
                goto update;
            }
        }
        else if (nIndex < 0)
        {
            nIndex = i;
        }
        ++i;
    }

    if (a3 == 1)
    {
        return 0;
    }
    if (nIndex < 0)
    {
        return 0;
    }

    nState = gnItemSetStates[nIndex];
    int const nItemId = pItem->dwUnitId;
    void* const pPool = pUnit->pMemoryPool;
    pStatList = STATLIST_AllocStatList(pPool, 0, 0, !pItem ? 6 : pItem->dwUnitType, nItemId);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATLIST_SetState(pStatList, nState);

update:
    switch (a3)
    {
    case 0:
        STATLIST_AddStat(pStatList, STAT_VALUE, nValue, 0);
        ITEMMODS_UpdateFullSetBoni(pUnit, pItem, nState);
        break;

    case 1:
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
        break;
    }

    return 1;
}

// 0x00663CC0
int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pItem || pItem->dwUnitType != UNIT_ITEM || !pUnit->pInventory)
    {
        return 0;
    }

    const unsigned int nSetItemMask = ITEMS_GetStoreSetItemsMaskInline(pUnit, pItem);

    if (a4 || !a3)
    {
        sub_00663A20_SetItemBonusStates(pItem, nSetItemMask);
    }

    sub_00663B40_SetBonusStatList(pUnit, pItem, a3);

    return 1;
}
