#include "D2Common.h"
#include "D2Records.h"

struct D2BinFieldStrc;

void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize); // 0x006122F0

struct D2TokRecord { char unk[0x34]; };

D2TokRecord* gpCompositTxt;                                                                                 // 0x0096D4EC

void* gpMonmodeTxt; // 0x0096D4BC

void* gpMonmodeTxtAlias1; // 0x0096D4C0

void* gpMonmodeTxtAlias2; // 0x0096D4C4

int gnMonmodeTxtRecordCount; // 0x0096D4B8

struct D2ObjModeTypeTxt
{
    char szName[32];
    unsigned int dwToken;
    char unk0x24[16];
};

extern "C" const char gszTxtField_end[];                                                                    // 0x006D9060

int gnObjModeTypeTxtRecordCount;                                                                            // 0x0096D4C8

D2ObjModeTypeTxt* gpObjModeTypeTxt;                                                                         // 0x0096D4CC

D2ObjModeTypeTxt* gpObjType;                                                                                // 0x0096D4D0

D2ObjModeTypeTxt* gpObjMode;                                                                                // 0x0096D4D4

void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                          // 0x006125C0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                          // 0x006829C0

#pragma function(memcpy)

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define TBL_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PlrModeDataTbl { unsigned int nPlrModeTypeTxtRecordCount; void* pPlrModeTypeTxt; D2TokRecord* pPlayerType; D2TokRecord* pPlayerMode; };

struct D2MonModeDataTbl { unsigned int nMonModeTxtRecordCount; void* pMonModeTxt; D2TokRecord* pMonMode[2]; };

struct D2ObjModeDataTbl { unsigned int nObjModeTypeTxtRecordCount; void* pObjModeTypeTxt; D2TokRecord* pObjType; D2TokRecord* pObjMode; };

extern D2MonModeDataTbl gMonModeDataTables;                                                                 // 0x0096D4B8

extern D2ObjModeDataTbl gObjModeDataTables;                                                                 // 0x0096D4C8

D2PlrModeDataTbl gPlrModeDataTables;                                                                        // 0x0096D4D8

D2TokRecord* gpArmTypeTxt;                                                                                  // 0x0096D4E8

void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

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

    gpMonmodeTxt = DATATBLS_CompileTxt(hArchive, "monmode", pTbl, &nRecordCount, 52);
    gnMonmodeTxtRecordCount = nRecordCount;
    gpMonmodeTxtAlias1 = gpMonmodeTxt;
    gpMonmodeTxtAlias2 = gpMonmodeTxt;
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

    D2ObjModeTypeTxt* pType = (D2ObjModeTypeTxt*)DATATBLS_CompileTxt(hArchive, "objtype", pTbl, &nTypeRecords, sizeof(D2ObjModeTypeTxt));
    D2ObjModeTypeTxt* pModeSrc = (D2ObjModeTypeTxt*)DATATBLS_CompileTxt(hArchive, "objmode", pTbl, &nModeRecords, sizeof(D2ObjModeTypeTxt));

    int nTotal = nModeRecords + nTypeRecords;
    D2ObjModeTypeTxt* pTxt = (D2ObjModeTypeTxt*)FOG_AllocPool(0, sizeof(D2ObjModeTypeTxt) * nTotal, ".\\DATATBLS\\TokTbls.cpp", 148, 0);
    TBL_ASSERT(pTxt, 149);

    memcpy(pTxt, pType, sizeof(D2ObjModeTypeTxt) * nTypeRecords);
    D2ObjModeTypeTxt* pMode = pTxt + nTypeRecords;
    memcpy(pMode, pModeSrc, sizeof(D2ObjModeTypeTxt) * nModeRecords);

    DATATBLS_UnloadBin(pType);
    DATATBLS_UnloadBin(pModeSrc);

    gpObjMode = pMode;
    gpObjModeTypeTxt = pTxt;
    gpObjType = pTxt;
    gnObjModeTypeTxtRecordCount = nTotal;
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

#include "gen/data/Source/D2Common/DATATBLS/TokTbls.inc"
