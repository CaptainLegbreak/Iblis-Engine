#pragma once
// monitempercent.txt: record count, records.

struct D2MonItemPercentTxt;

struct D2MonItemPercentDataTbl
{
    int nMonItemPercentTxtRecordCount; // 0x00
    D2MonItemPercentTxt* pMonItemPercentTxt; // 0x04
};
