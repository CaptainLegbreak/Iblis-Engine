#include "D2Common.h"
#include "D2CommonInternal.h"
#include "D2DataTbls.h"
#include "D2Records.h"
#include "FogApi.h"
#include "D2HellApi.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
struct D2CubeMainTxt;



enum
{
    TXTFIELD_NONE = 0,
    TXTFIELD_DWORD = 2,
    TXTFIELD_WORD = 3,
    TXTFIELD_BYTE = 4,
    TXTFIELD_CODETOBYTE = 13,
    TXTFIELD_NAMETODWORD = 19,
    TXTFIELD_CUSTOMLINK = 23,
};
extern D2DataTablesStrc sgtDataTables;                                                                      // 0x0096BC30

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468
void __fastcall sub_00669080_CubeInputLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x00669080
void __fastcall DATATBLS_CubeMainOutputLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x006690B0
void __fastcall DATATBLS_CubeMainParamLinker(char* pSrc, void* pRecord, int nOffset, int nPosition, int nTxtRow, int nTxtColumn);// 0x006690E0

// 0x00669130
void __fastcall DATATBLS_LoadCubeMainTxt(void* hArchive)
{
    void* pFileHandle;
    char szPath[260];

    D2BinFieldStrc pTbl[] =
    {
        { "enabled", TXTFIELD_BYTE, 0, 0, 0 },
        { "ladder", TXTFIELD_BYTE, 0, 1, 0 },
        { "min diff", TXTFIELD_BYTE, 0, 2, 0 },
        { "op", TXTFIELD_BYTE, 0, 4, 0 },
        { "param", TXTFIELD_DWORD, 0, 8, (void*)DATATBLS_CubeMainParamLinker },
        { "value", TXTFIELD_DWORD, 0, 12, 0 },
        { "class", TXTFIELD_CODETOBYTE, 0, 3, &sgtDataTables.pPlayerClassLinker },
        { "numinputs", TXTFIELD_BYTE, 0, 16, 0 },
        { gszTxtField_version, TXTFIELD_WORD, 0, 18, 0 },
        { "input 1", TXTFIELD_CUSTOMLINK, 0, 0, (void*)sub_00669080_CubeInputLinker },
        { "input 2", TXTFIELD_CUSTOMLINK, 0, 1, (void*)sub_00669080_CubeInputLinker },
        { "input 3", TXTFIELD_CUSTOMLINK, 0, 2, (void*)sub_00669080_CubeInputLinker },
        { "input 4", TXTFIELD_CUSTOMLINK, 0, 3, (void*)sub_00669080_CubeInputLinker },
        { "input 5", TXTFIELD_CUSTOMLINK, 0, 4, (void*)sub_00669080_CubeInputLinker },
        { "input 6", TXTFIELD_CUSTOMLINK, 0, 5, (void*)sub_00669080_CubeInputLinker },
        { "input 7", TXTFIELD_CUSTOMLINK, 0, 6, (void*)sub_00669080_CubeInputLinker },
        { "output", TXTFIELD_CUSTOMLINK, 0, 0, (void*)DATATBLS_CubeMainOutputLinker },
        { "lvl", TXTFIELD_BYTE, 0, 85, 0 },
        { "plvl", TXTFIELD_BYTE, 0, 86, 0 },
        { "ilvl", TXTFIELD_BYTE, 0, 87, 0 },
        { "mod 1", TXTFIELD_NAMETODWORD, 0, 100, &sgtDataTables.pPropertiesLinker },
        { "mod 1 chance", TXTFIELD_BYTE, 0, 110, 0 },
        { "mod 1 param", TXTFIELD_WORD, 0, 104, 0 },
        { "mod 1 min", TXTFIELD_WORD, 0, 106, 0 },
        { "mod 1 max", TXTFIELD_WORD, 0, 108, 0 },
        { "mod 2", TXTFIELD_NAMETODWORD, 0, 112, &sgtDataTables.pPropertiesLinker },
        { "mod 2 chance", TXTFIELD_BYTE, 0, 122, 0 },
        { "mod 2 param", TXTFIELD_WORD, 0, 116, 0 },
        { "mod 2 min", TXTFIELD_WORD, 0, 118, 0 },
        { "mod 2 max", TXTFIELD_WORD, 0, 120, 0 },
        { "mod 3", TXTFIELD_NAMETODWORD, 0, 124, &sgtDataTables.pPropertiesLinker },
        { "mod 3 chance", TXTFIELD_BYTE, 0, 134, 0 },
        { "mod 3 param", TXTFIELD_WORD, 0, 128, 0 },
        { "mod 3 min", TXTFIELD_WORD, 0, 130, 0 },
        { "mod 3 max", TXTFIELD_WORD, 0, 132, 0 },
        { "mod 4", TXTFIELD_NAMETODWORD, 0, 136, &sgtDataTables.pPropertiesLinker },
        { "mod 4 chance", TXTFIELD_BYTE, 0, 146, 0 },
        { "mod 4 param", TXTFIELD_WORD, 0, 140, 0 },
        { "mod 4 min", TXTFIELD_WORD, 0, 142, 0 },
        { "mod 4 max", TXTFIELD_WORD, 0, 144, 0 },
        { "mod 5", TXTFIELD_NAMETODWORD, 0, 148, &sgtDataTables.pPropertiesLinker },
        { "mod 5 chance", TXTFIELD_BYTE, 0, 158, 0 },
        { "mod 5 param", TXTFIELD_WORD, 0, 152, 0 },
        { "mod 5 min", TXTFIELD_WORD, 0, 154, 0 },
        { "mod 5 max", TXTFIELD_WORD, 0, 156, 0 },
        { "output b", TXTFIELD_CUSTOMLINK, 0, 1, (void*)DATATBLS_CubeMainOutputLinker },
        { "b lvl", TXTFIELD_BYTE, 0, 169, 0 },
        { "b plvl", TXTFIELD_BYTE, 0, 170, 0 },
        { "b ilvl", TXTFIELD_BYTE, 0, 171, 0 },
        { "b mod 1", TXTFIELD_NAMETODWORD, 0, 184, &sgtDataTables.pPropertiesLinker },
        { "b mod 1 chance", TXTFIELD_BYTE, 0, 194, 0 },
        { "b mod 1 param", TXTFIELD_WORD, 0, 188, 0 },
        { "b mod 1 min", TXTFIELD_WORD, 0, 190, 0 },
        { "b mod 1 max", TXTFIELD_WORD, 0, 192, 0 },
        { "b mod 2", TXTFIELD_NAMETODWORD, 0, 196, &sgtDataTables.pPropertiesLinker },
        { "b mod 2 chance", TXTFIELD_BYTE, 0, 206, 0 },
        { "b mod 2 param", TXTFIELD_WORD, 0, 200, 0 },
        { "b mod 2 min", TXTFIELD_WORD, 0, 202, 0 },
        { "b mod 2 max", TXTFIELD_WORD, 0, 204, 0 },
        { "b mod 3", TXTFIELD_NAMETODWORD, 0, 208, &sgtDataTables.pPropertiesLinker },
        { "b mod 3 chance", TXTFIELD_BYTE, 0, 218, 0 },
        { "b mod 3 param", TXTFIELD_WORD, 0, 212, 0 },
        { "b mod 3 min", TXTFIELD_WORD, 0, 214, 0 },
        { "b mod 3 max", TXTFIELD_WORD, 0, 216, 0 },
        { "b mod 4", TXTFIELD_NAMETODWORD, 0, 220, &sgtDataTables.pPropertiesLinker },
        { "b mod 4 chance", TXTFIELD_BYTE, 0, 230, 0 },
        { "b mod 4 param", TXTFIELD_WORD, 0, 224, 0 },
        { "b mod 4 min", TXTFIELD_WORD, 0, 226, 0 },
        { "b mod 4 max", TXTFIELD_WORD, 0, 228, 0 },
        { "b mod 5", TXTFIELD_NAMETODWORD, 0, 232, &sgtDataTables.pPropertiesLinker },
        { "b mod 5 chance", TXTFIELD_BYTE, 0, 242, 0 },
        { "b mod 5 param", TXTFIELD_WORD, 0, 236, 0 },
        { "b mod 5 min", TXTFIELD_WORD, 0, 238, 0 },
        { "b mod 5 max", TXTFIELD_WORD, 0, 240, 0 },
        { "output c", TXTFIELD_CUSTOMLINK, 0, 2, (void*)DATATBLS_CubeMainOutputLinker },
        { "c lvl", TXTFIELD_BYTE, 0, 253, 0 },
        { "c plvl", TXTFIELD_BYTE, 0, 254, 0 },
        { "c ilvl", TXTFIELD_BYTE, 0, 255, 0 },
        { "c mod 1", TXTFIELD_NAMETODWORD, 0, 268, &sgtDataTables.pPropertiesLinker },
        { "c mod 1 chance", TXTFIELD_BYTE, 0, 278, 0 },
        { "c mod 1 param", TXTFIELD_WORD, 0, 272, 0 },
        { "c mod 1 min", TXTFIELD_WORD, 0, 274, 0 },
        { "c mod 1 max", TXTFIELD_WORD, 0, 276, 0 },
        { "c mod 2", TXTFIELD_NAMETODWORD, 0, 280, &sgtDataTables.pPropertiesLinker },
        { "c mod 2 chance", TXTFIELD_BYTE, 0, 290, 0 },
        { "c mod 2 param", TXTFIELD_WORD, 0, 284, 0 },
        { "c mod 2 min", TXTFIELD_WORD, 0, 286, 0 },
        { "c mod 2 max", TXTFIELD_WORD, 0, 288, 0 },
        { "c mod 3", TXTFIELD_NAMETODWORD, 0, 292, &sgtDataTables.pPropertiesLinker },
        { "c mod 3 chance", TXTFIELD_BYTE, 0, 302, 0 },
        { "c mod 3 param", TXTFIELD_WORD, 0, 296, 0 },
        { "c mod 3 min", TXTFIELD_WORD, 0, 298, 0 },
        { "c mod 3 max", TXTFIELD_WORD, 0, 300, 0 },
        { "c mod 4", TXTFIELD_NAMETODWORD, 0, 304, &sgtDataTables.pPropertiesLinker },
        { "c mod 4 chance", TXTFIELD_BYTE, 0, 314, 0 },
        { "c mod 4 param", TXTFIELD_WORD, 0, 308, 0 },
        { "c mod 4 min", TXTFIELD_WORD, 0, 310, 0 },
        { "c mod 4 max", TXTFIELD_WORD, 0, 312, 0 },
        { "c mod 5", TXTFIELD_NAMETODWORD, 0, 316, &sgtDataTables.pPropertiesLinker },
        { "c mod 5 chance", TXTFIELD_BYTE, 0, 326, 0 },
        { "c mod 5 param", TXTFIELD_WORD, 0, 320, 0 },
        { "c mod 5 min", TXTFIELD_WORD, 0, 322, 0 },
        { "c mod 5 max", TXTFIELD_WORD, 0, 324, 0 },
        { gszTxtField_end, TXTFIELD_NONE, 0, 0, 0 },
    };

    wsprintfA(szPath, gszPathFormat, gszExcelDirectory, "cubeserver.bin");
    D2_ASSERT(!ARCHIVE_OpenFile(hArchive, szPath, &pFileHandle, 1), 752);

    wsprintfA(szPath, gszPathFormat, gszExcelDirectory, "cubeserver.txt");
    D2_ASSERT(!ARCHIVE_OpenFile(hArchive, szPath, &pFileHandle, 1), 756);

    sgtDataTables.pCubeMainTxt = (D2CubeMainTxt*)DATATBLS_CompileTxt(hArchive, "cubemain", pTbl, &sgtDataTables.nCubeMainTxtRecordCount, 0x148);
}

#pragma pack(push, 1)
struct d2data_007496CC_t
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

extern "C" struct d2data_007496CC_t gData_007496CC; // 0x007496CC

extern "C" struct d2data_007496CC_t gData_007496CC = {
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
}; // 0x007496CC
