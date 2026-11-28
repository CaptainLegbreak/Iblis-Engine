#pragma once
// monmode.txt: record count, records, and the token lookups for its two columns.

struct D2TokRecord;

struct D2MonModeDataTbl
{
    unsigned int nMonModeTxtRecordCount; // 0x00
    void* pMonModeTxt; // 0x04
    D2TokRecord* pMonMode[2]; // 0x08
};
