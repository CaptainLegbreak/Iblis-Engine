#pragma once
// plrmode.txt and plrtype.txt: record count, records, and the token lookups for types and modes.

struct D2TokRecord;

struct D2PlrModeDataTbl
{
    unsigned int nPlrModeTypeTxtRecordCount; // 0x00
    void* pPlrModeTypeTxt; // 0x04
    D2TokRecord* pPlayerType; // 0x08
    D2TokRecord* pPlayerMode; // 0x0C
};
