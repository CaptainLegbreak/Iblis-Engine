#pragma once
// rareprefix.txt and raresuffix.txt, loaded as one table: record count, records, then where the suffixes and the prefixes start.

struct D2RareAffixTxt;

struct D2RareAffixDataTbl
{
    int nRareAffixTxtRecordCount; // 0x00
    D2RareAffixTxt* pRareAffixTxt; // 0x04
    D2RareAffixTxt* pRareSuffix; // 0x08
    D2RareAffixTxt* pRarePrefix; // 0x0C
};
