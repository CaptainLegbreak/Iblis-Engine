#include "D2Common.h"

#include "D2Structs.h"

#include "D2Path.h"




// 0x0064FAA0
static inline void PATHMISC_SetRoom(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pNewRoom)
{
    D2UnitStrc* pUnit = pPath->pUnit;
    pPath->pPreviousRoom = pPath->pRoom;
    if (pPath->pRoom)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }

    pPath->dwFlags |= 2;
    pPath->pRoom = pNewRoom;
    if (pNewRoom)
    {
        UNITROOM_AddUnitToRoom(pUnit, pNewRoom);
        UNITROOM_RefreshUnit(pUnit);
    }
}

void __stdcall sub_M130_Emit_0064FAA0(D2DynamicPathStrc* pPath, D2ActiveRoomStrc* pRoom)
{
    PATHMISC_SetRoom(pPath, pRoom);
}

#pragma pack(push, 1)
struct d2data_00745920_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
};
#pragma pack(pop)

extern "C" struct d2data_00745920_t gData_00745920; // 0x00745920

extern "C" struct d2data_00745920_t gData_00745920 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00745920
