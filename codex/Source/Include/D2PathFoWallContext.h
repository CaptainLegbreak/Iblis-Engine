#pragma once
// D2Common pathfinding: the FoWall search's working state (pending and visited caches, the open list, the node
// storage and the point stack).

#include "D2Check.h"

struct D2PathFoWallContextStrc
{
    D2PathFoWallNodeStrc* aPendingCache[128];
    D2PathFoWallNodeStrc* aVisitedCache[128];
    D2PathFoWallNodeStrc* pSortedListByFScore;
    D2PathFoWallNodeStrc aNodesStorage[200];
    int nNodesCount;
    D2PathFoWallNodeStrc* aPointsStack[200];
    int nStackCount;
};
