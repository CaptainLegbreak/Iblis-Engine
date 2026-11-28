#pragma once
// objmode.txt and objtype.txt: record count, records, and the token lookups for types and modes.

struct D2TokRecord;

struct D2ObjModeDataTbl
{
    unsigned int nObjModeTypeTxtRecordCount; // 0x00
    void* pObjModeTypeTxt; // 0x04
    D2TokRecord* pObjType; // 0x08
    D2TokRecord* pObjMode; // 0x0C
};
