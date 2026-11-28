#pragma once

// One row of the waypoint panel (gaLayouts, 9 rows): where its cel and its
// level name are drawn, and the top left of the 0x118 x 0x1E box that takes
// its clicks.
struct D2WaypointLayoutStrc
{
    int nCellX;
    int nCellY;
    int nTextX;
    int nTextY;
    int nRowX;
    int nRowY;
};
