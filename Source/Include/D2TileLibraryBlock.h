#pragma once
// One block of a tile in a DT1 tile library: its place in the tile, format and pixel data (D2Gfx's subtile drawers).

struct D2TileLibraryBlockStrc
{
    short nPosX; // 0x00
    short nPosY; // 0x02
    short nCacheIndex; // 0x04
    unsigned char nGridX; // 0x06
    unsigned char nGridY; // 0x07
    unsigned char nFormat; // 0x08
    unsigned char nFormatHigh; // 0x09
    unsigned short nLength; // 0x0A
    int nReserved; // 0x0C
    unsigned char* pData; // 0x10
};
