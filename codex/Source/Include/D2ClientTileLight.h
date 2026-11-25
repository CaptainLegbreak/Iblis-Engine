#pragma once
// Client: a tile light list node (position, the tile it lights, the next node).

#include "D2Check.h"

struct D2TileLightNodeStrc
{
    int unk0x00;
    int nX;
    int nY;
    D2DrlgTileDataStrc* pTileData;
    D2TileLightNodeStrc* pNext;
};
