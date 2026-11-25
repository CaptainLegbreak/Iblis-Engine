#pragma once
// D2CMP loaded tile library list: one record per library.

#include "D2CmpTileLib.h"

struct D2TileLibraryHashStrc;

struct D2TileRecordStrc
{
    char szLibraryName[260]; // 0x00
    D2TileLibraryHeaderStrc* pLibrary; // 0x104
    D2TileLibraryHashStrc* pHashBlock; // 0x108
    D2TileRecordStrc* pPrev; // 0x10C
};
