#include "D2Client.h"
#include "D2Structs.h"
#include "D2CommonApi.h"


void __stdcall UNITS_InitializeStaticPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY);      // 0x00620AE0

// 0x00463BC0
static void __stdcall sub_00463BC0_PlaceUnitInRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    if (pUnit)
        pUnit->dwFlags |= 0x22;
    UNITS_InitializeStaticPath(pUnit, pRoom, nX, nY);
    UNITS_BlockCollisionPath(pUnit, pRoom, nX, nY);
    UNITROOM_AddUnitToRoom(pUnit, pRoom);
}

void __stdcall sub_G05_Emit_00463BC0(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    sub_00463BC0_PlaceUnitInRoom(pUnit, pRoom, nX, nY);
}
