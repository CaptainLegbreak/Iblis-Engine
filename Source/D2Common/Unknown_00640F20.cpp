#include "D2Common.h"
#include "D2Records.h"

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0
extern void* gpObjgroupTxt;                                                                                 // 0x0096D478
extern int gnObjgroupTxtRecordCount;                                                                        // 0x0096D47C

// 0x00640F20
void __fastcall DATATBLS_LoadObjGroupTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "ID0", 2, 0, 0, 0 },
        { "DENSITY0", 4, 0, 32, 0 },
        { "PROB0", 4, 0, 40, 0 },
        { "ID1", 2, 0, 4, 0 },
        { "DENSITY1", 4, 0, 33, 0 },
        { "PROB1", 4, 0, 41, 0 },
        { "ID2", 2, 0, 8, 0 },
        { "DENSITY2", 4, 0, 34, 0 },
        { "PROB2", 4, 0, 42, 0 },
        { "ID3", 2, 0, 12, 0 },
        { "DENSITY3", 4, 0, 35, 0 },
        { "PROB3", 4, 0, 43, 0 },
        { "ID4", 2, 0, 16, 0 },
        { "DENSITY4", 4, 0, 36, 0 },
        { "PROB4", 4, 0, 44, 0 },
        { "ID5", 2, 0, 20, 0 },
        { "DENSITY5", 4, 0, 37, 0 },
        { "PROB5", 4, 0, 45, 0 },
        { "ID6", 2, 0, 24, 0 },
        { "DENSITY6", 4, 0, 38, 0 },
        { "PROB6", 4, 0, 46, 0 },
        { "ID7", 2, 0, 28, 0 },
        { "DENSITY7", 4, 0, 39, 0 },
        { "PROB7", 4, 0, 47, 0 },
        { "SHRINES", 4, 0, 48, 0 },
        { "WELLS", 4, 0, 49, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpObjgroupTxt = DATATBLS_CompileTxt(hArchive, "objgroup", pTbl, &gnObjgroupTxtRecordCount, 52);
}

#pragma pack(push, 1)
struct d2data_007456C0_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_007456C0_t gData_007456C0; // 0x007456C0

extern "C" struct d2data_007456C0_t gData_007456C0 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x007456C0
