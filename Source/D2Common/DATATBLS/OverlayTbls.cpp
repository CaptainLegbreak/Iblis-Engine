#include "D2Common.h"
#include "D2CommonInternal.h"
#include "D2Records.h"
#include "D2DataTbls.h"



extern "C" const char gszTxtField_Filename[];                                                               // 0x006D90F4
extern D2DataTablesStrc sgtDataTables;                                                                        // 0x0096BC30

// 0x00664150
void __fastcall DATATBLS_LoadOverlayTxt(void* hArchive)
{
    D2BinFieldStrc pTbl[] =
    {
        { "overlay", 17, 0, 0, &sgtDataTables.pOverlayLinker },
        { gszTxtField_Filename, 1, 64, 2, 0 },
        { gszTxtField_version, 3, 0, 66, 0 },
        { "Frames", 2, 0, 68, 0 },
        { "PreDraw", 4, 0, 72, 0 },
        { "1ofN", 2, 0, 76, 0 },
        { "Dir", 4, 0, 80, 0 },
        { "Open", 4, 0, 81, 0 },
        { "Beta", 4, 0, 82, 0 },
        { "Xoffset", 2, 0, 84, 0 },
        { "Yoffset", 2, 0, 88, 0 },
        { "Height1", 2, 0, 92, 0 },
        { "Height2", 2, 0, 96, 0 },
        { "Height3", 2, 0, 100, 0 },
        { "Height4", 2, 0, 104, 0 },
        { "AnimRate", 2, 0, 108, 0 },
        { "LoopWaitTime", 2, 0, 120, 0 },
        { "Trans", 4, 0, 124, 0 },
        { "InitRadius", 2, 0, 112, 0 },
        { "Radius", 2, 0, 116, 0 },
        { "Red", 4, 0, 125, 0 },
        { "Green", 4, 0, 126, 0 },
        { "Blue", 4, 0, 127, 0 },
        { "NumDirections", 4, 0, 128, 0 },
        { "LocalBlood", 4, 0, 129, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    sgtDataTables.pOverlayLinker = FOG_AllocLinker(".\\DATATBLS\\OverlayTbls.cpp", 56);
    sgtDataTables.pOverlayTxt = (D2OverlayTxt*)DATATBLS_CompileTxt(hArchive, "overlay", pTbl, &sgtDataTables.nOverlayTxtRecordCount, 0x84);
}

#pragma pack(push, 1)
struct d2data_00748848_t
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

extern "C" struct d2data_00748848_t gData_00748848; // 0x00748848

extern "C" const char gszTxtField_Filename[9] = "Filename"; // 0x006D90F4

extern "C" const char gszTxtField_version[8] = "version"; // 0x006DCCF0

extern "C" struct d2data_00748848_t gData_00748848 = {
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
}; // 0x00748848
