#pragma once
// Client and launcher: the drop-items packet SCMD_DropUnitItems reads (header, active flag, the unit id and the
// other unit id, as bytes).

#include "D2Check.h"

struct D2UnitDropItemsPacketStrc
{
    char nHeader; // 0x00
    char bActive; // 0x01
    char nUnitId[4]; // 0x02
    char nOtherUnitId[4]; // 0x06
};
