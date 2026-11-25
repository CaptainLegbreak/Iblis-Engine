#pragma once
// D2CMP: FindTiles.cpp's tile lookup hash entry: three keys, its list of tile nodes, the next entry.

#include "D2Check.h"

struct D2FindTileNodeStrc;

struct D2FindTileEntryStrc
{
    int nKey2;
    int nKey3;
    int nKey1;
    D2FindTileNodeStrc* pTileList;
    D2FindTileEntryStrc* pNext;
};
