#pragma once
// Client: an act's waypoint range (first and last level id, first and last waypoint).

#include "D2Check.h"

struct D2WaypointActRangeStrc
{
    char bInit;
    char nFirstLevelId[4];
    char nLastLevelId[4];
    unsigned char nMinWaypoint;
    unsigned char nMaxWaypoint;
};
