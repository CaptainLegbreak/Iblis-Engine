// Functional replacement for the function at 0x0062B5B0, not the original code: only the ordinary build (tools/link.py) uses it.
// The other functions in this file are copies that give it its callees and their calling conventions; the build links their verified definitions instead.

struct D2InventoryStrc;
struct D2ItemDataStrc
{
    int dwQualityNo;
    unsigned char pad04[0x32];
    unsigned short wAutoAffix;
    unsigned short wMagicPrefix[3];
    unsigned short wMagicSuffix[3];
};
struct D2UnitStrc
{
    unsigned int dwUnitType;
    unsigned int dwClassId;
    unsigned char pad08[12];
    D2ItemDataStrc* pItemData;
    unsigned char pad18[0x48];
    D2InventoryStrc* pInventory;
};
struct D2MagicAffixTxt
{
    unsigned char pad00[0x65];
    unsigned char nLevelReq;
    unsigned char pad66;
    unsigned char nClass;
    unsigned char nClassLevelReq;
};
struct D2UniqueItemsTxt { unsigned char pad00[0x36]; short wLvlReq; };
struct D2SetItemsTxt { unsigned char pad00[0x32]; short wLvlReq; };
struct D2ItemsTxt { unsigned char pad00[0x13F]; unsigned char nLevelReq; };
struct D2StatStrc { unsigned short nLayer; unsigned short nStat; int nValue; };
struct D2SkillsTxt
{
    unsigned char pad00[12];
    signed char nCharClass;
    unsigned char pad0D[0x167];
    short wReqLevel;
    unsigned char pad176[0xC6];
};
struct D2DataTablesStrc
{
    unsigned char pad00[0xB98];
    D2SkillsTxt* pSkillsTxt;
    int unkB9C;
    int nSkillsTxtRecordCount;
};
extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nAffix); // 0x00633EE0
int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830
int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0
D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470
int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwFlag); // 0x00463720
unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem); // 0x0062A670
D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex); // 0x00483440
D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0
D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0
D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pUnit); // 0x0063DFD0
D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pUnit); // 0x0063DFA0
int __stdcall STATLIST_CopyStats(D2UnitStrc* pUnit, int nStat, D2StatStrc* pBuffer, int nBufferSize); // 0x006261D0
int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStat, unsigned short nLayer); // 0x00625480

#define UNIT_ITEM 4
#define ITEMQUAL_NORMAL 2
#define ITEMQUAL_MAGIC 4
#define ITEMQUAL_SET 5
#define ITEMQUAL_RARE 6
#define ITEMQUAL_UNIQUE 7
#define ITEMQUAL_CRAFT 8
#define ITEMS_MAX_MODS 3
#define STAT_ITEM_LEVELREQ 92
#define STAT_ITEM_NONCLASSSKILL 97
#define STAT_ITEM_SINGLESKILL 107
#define UNITFLAGEX_ISEXPANSION 0x2000000

inline D2ItemDataStrc* ITEMS_GetItemData(D2UnitStrc* pItem)
{
    return (pItem && pItem->dwUnitType == UNIT_ITEM && pItem->pItemData) ? pItem->pItemData : 0;
}

static __forceinline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x00627E70
int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->dwQualityNo;
    }

    return ITEMQUAL_NORMAL;
}

// 0x00627EC0
unsigned short __stdcall ITEMS_GetPrefixId(D2UnitStrc* pItem, int nPrefixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wMagicPrefix[nPrefixNo];
    }

    return 0;
}

// 0x00627F20
unsigned short __stdcall ITEMS_GetAutoAffix(D2UnitStrc* pItem)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wAutoAffix;
    }

    return 0;
}

// 0x00627F80
unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo)
{
    if (D2ItemDataStrc* pItemData = ITEMS_GetItemData(pItem))
    {
        return pItemData->wMagicSuffix[nSuffixNo];
    }

    return 0;
}

// 0x00628830
static int __fastcall ITEMS_ApplyAffixLevelRequirement(D2MagicAffixTxt* pAffix, D2UnitStrc* pPlayer, int nRequiredLevel)
{
    if (pAffix)
    {
        int nLevelRequirement;
        if (pAffix->nClass != 255 && pPlayer && pAffix->nClass == (int)pPlayer->dwClassId)
            nLevelRequirement = pAffix->nClassLevelReq;
        else
            nLevelRequirement = pAffix->nLevelReq;
        return nRequiredLevel <= nLevelRequirement ? nLevelRequirement : nRequiredLevel;
    }
    return nRequiredLevel;
}

// 0x0062B5B0
int __fastcall ITEMS_GetRequiredLevel(D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2StatStrc pStat[64];
    int nRequiredLevel;

    const int nQuality = ITEMS_GetItemQuality(pItem);
    nRequiredLevel = 0;
    switch (nQuality)
    {
    case ITEMQUAL_MAGIC:
    {
        D2MagicAffixTxt* pPrefixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, 0));
        D2MagicAffixTxt* pSuffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2MagicAffixTxt* pAutoAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix(pItem));
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pPrefixTxtRecord, pPlayer, nRequiredLevel);
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pSuffixTxtRecord, pPlayer, nRequiredLevel);
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pAutoAffixTxtRecord, pPlayer, nRequiredLevel);
        break;
    }
    case ITEMQUAL_RARE:
    {
        for (int i = 0; i < ITEMS_MAX_MODS; ++i)
        {
            D2MagicAffixTxt* pPrefixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
            D2MagicAffixTxt* pSuffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pPrefixTxtRecord, pPlayer, nRequiredLevel);
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pSuffixTxtRecord, pPlayer, nRequiredLevel);
        }

        D2MagicAffixTxt* pAutoAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetAutoAffix(pItem));
        nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pAutoAffixTxtRecord, pPlayer, nRequiredLevel);
        break;
    }
    case ITEMQUAL_CRAFT:
    {
        int nCraftBonus = 10;
        for (int i = 0; i < ITEMS_MAX_MODS; ++i)
        {
            D2MagicAffixTxt* pPrefixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
            D2MagicAffixTxt* pSuffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pPrefixTxtRecord, pPlayer, nRequiredLevel);
            nRequiredLevel = ITEMS_ApplyAffixLevelRequirement(pSuffixTxtRecord, pPlayer, nRequiredLevel);
            if (pPrefixTxtRecord)
            {
                nCraftBonus += 3;
            }
            if (pSuffixTxtRecord)
            {
                nCraftBonus += 3;
            }
        }

        nRequiredLevel += nCraftBonus;
        const int nMaxLevel = DATATBLS_GetMaxLevel(0) - 1;
        if (nRequiredLevel > nMaxLevel)
        {
            nRequiredLevel = nMaxLevel;
        }
        break;
    }
    case ITEMQUAL_UNIQUE:
        if (ITEMS_GetFileIndex(pItem) >= 0)
        {
            D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
            if (pUniqueItemsTxtRecord)
            {
                if (!pPlayer || sub_00463720_TestUnitFlagEx(pPlayer, UNITFLAGEX_ISEXPANSION) || ITEMS_GetItemFormat(pItem) >= 1)
                {
                    const int nLevelReq = pUniqueItemsTxtRecord->wLvlReq;
                    if (nLevelReq >= 0)
                    {
                        nRequiredLevel = nLevelReq;
                    }
                }
            }
        }
        break;
    case ITEMQUAL_SET:
    {
        D2SetItemsTxt* pSetItemsTxtRecord = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pItem));
        if (pSetItemsTxtRecord)
        {
            const int nLevelReq = pSetItemsTxtRecord->wLvlReq;
            if (nLevelReq >= 0)
            {
                nRequiredLevel = nLevelReq;
            }
        }
        break;
    }
    default:
        break;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (pItemsTxtRecord)
    {
        if (pItemsTxtRecord->nLevelReq > nRequiredLevel)
        {
            nRequiredLevel = pItemsTxtRecord->nLevelReq;
        }
    }

    if (pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketable = INVENTORY_UnitIsItem(i);
            if (!pSocketable)
            {
                break;
            }

            const int nRequiredLevelForSocketables = ITEMS_GetRequiredLevel(pSocketable, pPlayer);
            if (nRequiredLevel <= nRequiredLevelForSocketables)
            {
                nRequiredLevel = nRequiredLevelForSocketables;
            }
        }
    }

    int nCount = STATLIST_CopyStats(pItem, STAT_ITEM_SINGLESKILL, pStat, 64);
    for (int i = 0; i < nCount; ++i)
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(pStat[i].nLayer);
        if (pSkillsTxtRecord)
        {
            if (pSkillsTxtRecord->wReqLevel > nRequiredLevel)
            {
                nRequiredLevel = pSkillsTxtRecord->wReqLevel;
            }
        }
    }

    nCount = STATLIST_CopyStats(pItem, STAT_ITEM_NONCLASSSKILL, pStat, 64);
    for (int i = 0; i < nCount; ++i)
    {
        D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(pStat[i].nLayer);
        if (pSkillsTxtRecord)
        {
            int nRequiredLevelForSkill;
            signed char nCharClass;
            if (pPlayer && !GAME_GetUnitTypeOrInvalid(pPlayer) && (nCharClass = pSkillsTxtRecord->nCharClass) >= 0)
            {
                if (nCharClass < 7 && (unsigned char)GAME_GetUnitClassId(pPlayer) == nCharClass)
                {
                    nRequiredLevelForSkill = pSkillsTxtRecord->wReqLevel;
                }
                else
                {
                    nRequiredLevelForSkill = pSkillsTxtRecord->wReqLevel + 6;
                }
            }
            else
            {
                nRequiredLevelForSkill = pSkillsTxtRecord->wReqLevel + 6;
            }

            if (nRequiredLevelForSkill > nRequiredLevel)
            {
                nRequiredLevel = nRequiredLevelForSkill;
            }
        }
    }

    nRequiredLevel += STATLIST_UnitGetStatValue(pItem, STAT_ITEM_LEVELREQ, 0);
    return nRequiredLevel > 0 ? nRequiredLevel : 0;
}
