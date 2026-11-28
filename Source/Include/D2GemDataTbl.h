#pragma once
// gems.txt as D2Common keeps it loaded: record count, records.

struct D2GemsTxt;

struct D2GemDataTbl
{
    int nGemsTxtRecordCount; // 0x00
    D2GemsTxt* pGemsTxt; // 0x04
};
