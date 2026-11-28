#include "D2CMP.h"
#include "D2DrlgMaps.h"
#include "D2CmpCache.h"

struct D2TileLibraryEntryStrc;
struct D2TileLibraryHeaderStrc;
struct D2TileRecordStrc;

typedef void (__fastcall* TILEFN)(D2TileLibraryEntryStrc* pTile, void* pArg);

extern "C" const char gszPalShiftGrey[]; // 0x006DCDA0
extern "C" const char gszPalShiftGrey2[]; // 0x006DCD98
extern "C" const char gszTxtField_gold[]; // 0x006DCD90
extern "C" const char gszPalShiftBrown[]; // 0x006DCD88
extern "C" const char gszPalShiftGreyBrown[]; // 0x006DCD7C
extern "C" const char gszPalShiftInvGrey[]; // 0x006DCD74
extern "C" const char gszPalShiftInvGrey2[]; // 0x006DCD68
extern "C" const char gszPalShiftInvGreyBrown[]; // 0x006DCD58
void __fastcall D2CMP_LoadItemPalShift(const char* szName, int nIndex); // 0x006009C0

static D2TileRecordStrc* gpTileRecords; // 0x008ADBB4

// 0x006008D0
int __stdcall D2CMPIterateAllTiles(TILEFN pfnTile, void* pArg)
{
    D2TileRecordStrc* pRecord = gpTileRecords;
    int nCount = 0;
    if (!pfnTile)
    {
        return 0;
    }

    for (; pRecord; pRecord = pRecord->pPrev)
    {
        D2TileLibraryHeaderStrc* pLibrary = pRecord->pLibrary;
        for (int i = 0; i < pLibrary->nTiles; ++i)
        {
            pfnTile(&pLibrary->pFirst[i], pArg);
            ++nCount;
        }
    }

    return nCount;
}

// 0x00600B80
void __cdecl D2CMP_LoadItemPalShifts()
{
    D2CMP_LoadItemPalShift(gszPalShiftGrey, 1);
    D2CMP_LoadItemPalShift(gszPalShiftGrey2, 2);
    D2CMP_LoadItemPalShift(gszTxtField_gold, 3);
    D2CMP_LoadItemPalShift(gszPalShiftBrown, 4);
    D2CMP_LoadItemPalShift(gszPalShiftGreyBrown, 5);
    D2CMP_LoadItemPalShift(gszPalShiftInvGrey, 6);
    D2CMP_LoadItemPalShift(gszPalShiftInvGrey2, 7);
    D2CMP_LoadItemPalShift(gszPalShiftInvGreyBrown, 8);
}
