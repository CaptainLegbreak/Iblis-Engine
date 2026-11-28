#pragma once
// itemratio.txt: record count, records.

struct D2ItemRatioTxt;

struct D2ItemRatioDataTbl
{
    int nItemRatioTxtRecordCount; // 0x00
    D2ItemRatioTxt* pItemRatioTxt; // 0x04
};
