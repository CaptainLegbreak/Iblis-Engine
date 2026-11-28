#pragma once
// lowqualityitems.txt: record count, records.

struct D2LowQualityItemsTxt;

struct D2LowQualityItemDataTbl
{
    int nLowQualityItemsTxtRecordCount; // 0x00
    D2LowQualityItemsTxt* pLowQualityItemsTxt; // 0x04
};
