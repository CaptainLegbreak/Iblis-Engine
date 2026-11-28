#include "D2LanguageNames.h"

#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2Drlg.h"
#include "D2CommonApi.h"

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

typedef int (__fastcall* UNITCALLBACKFN)(D2UnitStrc* pUnit, D2UnitStrc* pOther, void* pArg1, void* pArg2);



void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790


// 0x0046C570
int __fastcall GFXUTIL_ForEachUnitInAdjacentRooms(D2UnitStrc* pUnit, void* pArg1, void* pArg2, UNITCALLBACKFN pfnCallback)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pOther = ppRoomList[i]->pUnitFirst; pOther; pOther = pOther->ptRoomNext)
        {
            int nResult = pfnCallback(pUnit, pOther, pArg1, pArg2);
            if (nResult)
            {
                return nResult;
            }
        }
    }

    return 0;
}

// 0x0046C600
int __fastcall GFXUTIL_FindNearestUnitCallback(D2UnitStrc* pUnit, D2UnitStrc* pOther, D2UnitStrc** ppNearest, int* pnDistance)
{
    if (pUnit != pOther && pOther)
    {
        if (pOther->dwUnitType == UNIT_PLAYER
            || pOther->dwUnitType == UNIT_MONSTER && pOther->dwClassId != 149 && pOther->dwClassId != 556)
        {
            if (!CUNIT_IsDeadOrDying(pUnit))
            {
                int nDistance = DRLG_UnitEdgeDistance(pUnit, pOther);
                if (nDistance < *pnDistance)
                {
                    *ppNearest = pOther;
                    *pnDistance = nDistance;
                }
            }
        }
    }

    return 0;
}


