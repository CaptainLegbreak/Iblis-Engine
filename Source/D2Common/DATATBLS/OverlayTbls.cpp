#include "D2Common.h"
#include "D2Records.h"
#include "D2DataTbls.h"



extern "C" const char gszTxtField_Filename[];                                                               // 0x006D90F4
extern D2DataTablesStrc sgtDataTables;                                                                        // 0x0096BC30
void* __stdcall DATATBLS_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pTbl, int* pRecordCount, int nRecordSize);// 0x006122F0

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

#include "gen/data/Source/D2Common/DATATBLS/OverlayTbls.inc"
