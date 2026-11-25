#pragma once
// D2Game items: gItemDataTables (0x0096CA58) as DATATBLS_GetItemDataTables returns
// it: the items.txt count and records, then the weapon, armor and misc records
// items.txt is compiled from.

#include "D2Check.h"

struct D2ItemsTxt;

struct D2ItemDataTbl
{
    int nItemsTxtRecordCount; // 0x00
    D2ItemsTxt* pItemsTxt; // 0x04
    D2ItemsTxt* pWeapons; // 0x08
    int nWeaponsTxtRecordCount; // 0x0C
    D2ItemsTxt* pArmor; // 0x10
    int nArmorTxtRecordCount; // 0x14
    D2ItemsTxt* pMisc; // 0x18
};
