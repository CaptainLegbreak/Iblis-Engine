#include "D2Common.h"
#include "D2Records.h"

struct D2PoolSystemStrc;
struct D2BinFieldStrc;

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

// A record of the token tables (composit, armtype, plrtype, monmode, objtype, objmode): a name and its code.
// Only monmode.txt fills the sixteen direction counts.
struct D2TokRecord
{
    char szName[32];
    unsigned int dwToken;
    unsigned char nDTDir;
    unsigned char nNUDir;
    unsigned char nWLDir;
    unsigned char nGHDir;
    unsigned char nA1Dir;
    unsigned char nA2Dir;
    unsigned char nBLDir;
    unsigned char nSCDir;
    unsigned char nS1Dir;
    unsigned char nS2Dir;
    unsigned char nS3Dir;
    unsigned char nS4Dir;
    unsigned char nDDDir;
    unsigned char nKBDir;
    unsigned char nSQDir;
    unsigned char nRNDir;
};

D2TokRecord* gpCompositTxt;                                                                                 // 0x0096D4EC


void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

#pragma function(memcpy)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TBL_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#include "D2PlrModeDataTbl.h"

#include "D2MonModeDataTbl.h"

#include "D2ObjModeDataTbl.h"

D2MonModeDataTbl gMonModeDataTables;                                                                 // 0x0096D4B8

D2ObjModeDataTbl gObjModeDataTables;                                                                 // 0x0096D4C8

D2PlrModeDataTbl gPlrModeDataTables;                                                                        // 0x0096D4D8

D2TokRecord* gpArmTypeTxt;                                                                                  // 0x0096D4E8

void __fastcall sub_0040B480(D2PoolSystemStrc* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

#define TOK_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0065AEF0
void __fastcall DATATBLS_LoadMonModeTxt(void* hArchive)
{
    int nRecordCount;
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { "DT_Dir", 6, 0, 36, 0 },
        { "NU_Dir", 6, 0, 37, 0 },
        { "WL_Dir", 6, 0, 38, 0 },
        { "GH_Dir", 6, 0, 39, 0 },
        { "A1_Dir", 6, 0, 40, 0 },
        { "A2_Dir", 6, 0, 41, 0 },
        { "BL_Dir", 6, 0, 42, 0 },
        { "SC_Dir", 6, 0, 43, 0 },
        { "S1_Dir", 6, 0, 44, 0 },
        { "S2_Dir", 6, 0, 45, 0 },
        { "S3_Dir", 6, 0, 46, 0 },
        { "S4_Dir", 6, 0, 47, 0 },
        { "DD_Dir", 6, 0, 48, 0 },
        { "KB_Dir", 6, 0, 49, 0 },
        { "SQ_Dir", 6, 0, 50, 0 },
        { "RN_Dir", 6, 0, 51, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gMonModeDataTables.pMonModeTxt = (D2TokRecord*)DATATBLS_CompileTxt(hArchive, "monmode", pTbl, &nRecordCount, 52);
    gMonModeDataTables.nMonModeTxtRecordCount = nRecordCount;
    gMonModeDataTables.pMonMode[0] = gMonModeDataTables.pMonModeTxt;
    gMonModeDataTables.pMonMode[1] = gMonModeDataTables.pMonModeTxt;
}

// 0x0065B1B0
void __fastcall DATATBLS_LoadObjType_ModeTxt(void* hArchive)
{
    int nTypeRecords;
    int nModeRecords;
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2TokRecord* pType = (D2TokRecord*)DATATBLS_CompileTxt(hArchive, "objtype", pTbl, &nTypeRecords, sizeof(D2TokRecord));
    D2TokRecord* pModeSrc = (D2TokRecord*)DATATBLS_CompileTxt(hArchive, "objmode", pTbl, &nModeRecords, sizeof(D2TokRecord));

    int nTotal = nModeRecords + nTypeRecords;
    D2TokRecord* pTxt = (D2TokRecord*)FOG_AllocPool(0, sizeof(D2TokRecord) * nTotal, ".\\DATATBLS\\TokTbls.cpp", 148, 0);
    TBL_ASSERT(pTxt, 149);

    memcpy(pTxt, pType, sizeof(D2TokRecord) * nTypeRecords);
    D2TokRecord* pMode = pTxt + nTypeRecords;
    memcpy(pMode, pModeSrc, sizeof(D2TokRecord) * nModeRecords);

    DATATBLS_UnloadBin(pType);
    DATATBLS_UnloadBin(pModeSrc);

    gObjModeDataTables.pObjMode = pMode;
    gObjModeDataTables.pObjModeTypeTxt = pTxt;
    gObjModeDataTables.pObjType = pTxt;
    gObjModeDataTables.nObjModeTypeTxtRecordCount = nTotal;
}

// 0x0065ADC0
void __fastcall DATATBLS_LoadPlrType_ModeTxt(void* hArchive)
{
    int nTypeRecords;
    int nModeRecords;
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2TokRecord* pType = (D2TokRecord*)DATATBLS_CompileTxt(hArchive, "plrtype", pTbl, &nTypeRecords, sizeof(D2TokRecord));
    D2TokRecord* pModeSrc = (D2TokRecord*)DATATBLS_CompileTxt(hArchive, "plrmode", pTbl, &nModeRecords, sizeof(D2TokRecord));

    int nTotal = nModeRecords + nTypeRecords;
    D2TokRecord* pTxt = (D2TokRecord*)FOG_AllocPool(0, sizeof(D2TokRecord) * nTotal, ".\\DATATBLS\\TokTbls.cpp", 55, 0);
    TBL_ASSERT(pTxt, 56);

    memcpy(pTxt, pType, sizeof(D2TokRecord) * nTypeRecords);
    D2TokRecord* pMode = pTxt + nTypeRecords;
    memcpy(pMode, pModeSrc, sizeof(D2TokRecord) * nModeRecords);

    DATATBLS_UnloadBin(pType);
    DATATBLS_UnloadBin(pModeSrc);

    gPlrModeDataTables.pPlayerMode = pMode;
    gPlrModeDataTables.pPlrModeTypeTxt = pTxt;
    gPlrModeDataTables.pPlayerType = pTxt;
    gPlrModeDataTables.nPlrModeTypeTxtRecordCount = nTotal;
}

// 0x0065B2E0
void __fastcall DATATBLS_LoadCompositTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpCompositTxt = (D2TokRecord*)DATATBLS_CompileTxt(hArchive, "composit", pTbl, 0, 52);
}

// 0x0065B350
void __fastcall DATATBLS_LoadArmTypeTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "name", 1, 31, 0, 0 },
        { "token", 9, 0, 32, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpArmTypeTxt = (D2TokRecord*)DATATBLS_CompileTxt(hArchive, "armtype", pTbl, 0, 52);
}

// 0x0065B3C0
void __fastcall DATATBLS_UnloadPlrMode_Type_MonMode_ObjMode_Type_Composit_ArmtypeTxt()
{
    if (gPlrModeDataTables.pPlrModeTypeTxt)
    {
        sub_0040B480(0, gPlrModeDataTables.pPlrModeTypeTxt, ".\\DATATBLS\\TokTbls.cpp", 214, 0);
    }
    gPlrModeDataTables.pPlrModeTypeTxt = 0;

    if (gMonModeDataTables.pMonModeTxt)
    {
        DATATBLS_UnloadBin(gMonModeDataTables.pMonModeTxt);
    }
    gMonModeDataTables.pMonModeTxt = 0;

    if (gObjModeDataTables.pObjModeTypeTxt)
    {
        sub_0040B480(0, gObjModeDataTables.pObjModeTypeTxt, ".\\DATATBLS\\TokTbls.cpp", 226, 0);
    }
    gObjModeDataTables.pObjModeTypeTxt = 0;

    if (gpCompositTxt)
    {
        DATATBLS_UnloadBin(gpCompositTxt);
    }
    gpCompositTxt = 0;

    if (gpArmTypeTxt)
    {
        DATATBLS_UnloadBin(gpArmTypeTxt);
    }
    gpArmTypeTxt = 0;
}

// 0x0065B450
D2PlrModeDataTbl* __fastcall DATATBLS_GetPlrMode_TypeDataTables()
{
    return &gPlrModeDataTables;
}

// 0x0065B460
D2MonModeDataTbl* __fastcall DATATBLS_GetMonModeDataTables()
{
    return &gMonModeDataTables;
}

// 0x0065B470
D2ObjModeDataTbl* __fastcall DATATBLS_GetObjMode_TypeDataTables()
{
    return &gObjModeDataTables;
}

// 0x0065B480
D2TokRecord* __stdcall DATATBLS_GetPlrModeTypeTxtRecord(unsigned int nIndex, int bGetMode)
{
    if (nIndex >= gPlrModeDataTables.nPlrModeTypeTxtRecordCount)
    {
        return 0;
    }

    TOK_ASSERT(gPlrModeDataTables.pPlrModeTypeTxt, 272);

    switch (bGetMode)
    {
    case 0:
        TOK_ASSERT(&gPlrModeDataTables.pPlayerType[nIndex], 275);
        return &gPlrModeDataTables.pPlayerType[nIndex];

    case 1:
        TOK_ASSERT(&gPlrModeDataTables.pPlayerMode[nIndex], 278);
        return &gPlrModeDataTables.pPlayerMode[nIndex];

    default:
        return 0;
    }
}

// 0x0065B500
D2TokRecord* __stdcall DATATBLS_GetMonModeTxtRecord(unsigned int nIndex, int bGetMode)
{
    if (nIndex >= gMonModeDataTables.nMonModeTxtRecordCount)
    {
        return 0;
    }

    switch (bGetMode)
    {
    case 0:
        TOK_ASSERT(&gMonModeDataTables.pMonMode[0][nIndex], 294);
        return &gMonModeDataTables.pMonMode[0][nIndex];

    case 1:
        TOK_ASSERT(&gMonModeDataTables.pMonMode[1][nIndex], 297);
        return &gMonModeDataTables.pMonMode[1][nIndex];

    default:
        return 0;
    }
}

// 0x0065B570
D2TokRecord* __stdcall DATATBLS_GetObjModeTypeTxtRecord(unsigned int nIndex, int bGetMode)
{
    if (nIndex >= gObjModeDataTables.nObjModeTypeTxtRecordCount)
    {
        return 0;
    }

    switch (bGetMode)
    {
    case 0:
        TOK_ASSERT(&gObjModeDataTables.pObjType[nIndex], 313);
        return &gObjModeDataTables.pObjType[nIndex];

    case 1:
        TOK_ASSERT(&gObjModeDataTables.pObjMode[nIndex], 316);
        return &gObjModeDataTables.pObjMode[nIndex];

    default:
        return 0;
    }
}

// 0x0065B5E0
D2TokRecord* __stdcall DATATBLS_GetCompositTxtRecord(int nComposit)
{
    TOK_ASSERT(&gpCompositTxt[nComposit], 327);

    return &gpCompositTxt[nComposit];
}

// 0x0065B620
D2TokRecord* __stdcall DATATBLS_GetArmTypeTxtRecord(int nId)
{
    TOK_ASSERT(&gpArmTypeTxt[nId], 336);
    return &gpArmTypeTxt[nId];
}

#pragma pack(push, 1)
struct d2data_00745A64_t
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

extern "C" struct d2data_00745A64_t gData_00745A64; // 0x00745A64

extern "C" struct d2data_00745A64_t gData_00745A64 = {
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
}; // 0x00745A64
