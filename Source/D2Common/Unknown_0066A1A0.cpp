#include "D2DataTbls.h"
#include "D2TxtItems.h"

extern D2DataTablesStrc sgtDataTables;                                                                       // 0x0096BC30
void __stdcall DATATBLS_UnloadBin(void* pBinFile);                                                               // 0x006125C0
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09

#define CUBE_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0066A1A0
void __fastcall DATATBLS_UnloadCubeMainTxt()
{
    DATATBLS_UnloadBin(sgtDataTables.pCubeMainTxt);
}

// 0x0066A1B0
D2CubeMainTxt* __stdcall DATATBLS_GetCubemainTxtRecord(int nIndex)
{
    CUBE_ASSERT(sgtDataTables.pCubeMainTxt, 846);
    CUBE_ASSERT(nIndex < sgtDataTables.nCubeMainTxtRecordCount, 847);

    return &sgtDataTables.pCubeMainTxt[nIndex];
}

// 0x0066A200
int __fastcall DATATBLS_GetCubemainTxtRecordCount()
{
    return sgtDataTables.nCubeMainTxtRecordCount;
}

void __stdcall DATATBLS_EmptyStub_0066A220(int a1, int a2)
{
}

void __stdcall DATATBLS_EmptyStub_0066A250(int a1)
{
}

// 0x0066A260
void __fastcall sub_0066A260_PlayerDataFreeHook(D2UnitStrc* pUnit)
{
}

// 0x0066A270
void __fastcall sub_0066A270(void* hArchive)
{
}

// build: symbol ?D2COMMON_10916_Return@* 0x0066A280
void __fastcall D2COMMON_10916_Return()
{
}

#include "gen/data/Source/D2Common/Unknown_0066A1A0.inc"
