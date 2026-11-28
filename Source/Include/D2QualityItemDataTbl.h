#pragma once
// qualityitems.txt: record count, records.

struct D2QualityItemsTxt;

struct D2QualityItemDataTbl
{
    int nQualityItemsTxtRecordCount; // 0x00
    D2QualityItemsTxt* pQualityItemsTxt; // 0x04
};
