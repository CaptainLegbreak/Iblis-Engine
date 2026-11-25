#pragma once
// D2CMP tile library header (one per loaded tile library).

struct D2TileLibraryEntryStrc;

struct D2TileLibraryHeaderStrc
{
    int dwVersion; // 0x00
    int dwFlags; // 0x04
    char szLibraryName[260]; // 0x08
    int nTiles; // 0x10C
    D2TileLibraryEntryStrc* pFirst; // 0x110
};
