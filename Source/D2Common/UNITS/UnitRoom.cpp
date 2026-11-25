#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Drlg.h"
struct D2CoordStrc;
struct D2StaticPathStrc;
struct D2DrlgCoordsStrc;






extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730
void __stdcall DUNGEON_IncreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619EE0
D2UnitStrc** __fastcall DUNGEON_GetUnitListFromRoom(D2ActiveRoomStrc* pRoom); // 0x00619F60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
D2UnitStrc** __fastcall DUNGEON_GetUnitUpdateListFromRoom(D2ActiveRoomStrc* pRoom, int bUpdate); // 0x00619F90
int __stdcall D2Common_10084(D2ActiveRoomStrc* pRoom); // 0x0061AB60
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370
void __stdcall PATH_ResetDynamicPathRoom(D2DynamicPathStrc* pDynamicPath); // 0x0064FC20
void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619F20
void __stdcall UNITS_ResetRoom(D2UnitStrc* pUnit); // 0x00620B50
void __stdcall UNITROOM_RemoveUnitFromUpdateQueue(D2UnitStrc* pUnit); // 0x0064C1B0

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x0064BF60
static int __stdcall UNITROOM_CanAddUnitToRoom(int bAssertIfPresent, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    D2DrlgCoordsStrc tRoomCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);

    const int nX = UNITS_GetXPositionInline(pUnit);
    const int nY = UNITS_GetYPositionInline(pUnit);
    D2_ASSERT(pRoom && nX >= pRoom->tCoords.nSubtileX && nX < pRoom->tCoords.nSubtileX + pRoom->tCoords.nSubtileWidth
        && nY >= pRoom->tCoords.nSubtileY && nY < pRoom->tCoords.nSubtileY + pRoom->tCoords.nSubtileHeight, 46);

    for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->ptRoomNext)
    {
        if (pUnit == i)
        {
            if (!bAssertIfPresent)
            {
                return FALSE;
            }
            D2_ASSERT(pUnit != i, 60);
        }
    }
    return TRUE;
}

// 0x0064C2C0
int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* hRoom, int nUnused)
{
    D2_ASSERT(pUnit, 72);
    D2_ASSERT(hRoom, 73);
    D2_ASSERT(UNITROOM_CanAddUnitToRoom(TRUE, pUnit, hRoom), 82);

    D2UnitStrc** ppUnitFirst = DUNGEON_GetUnitListFromRoom(hRoom);
    D2_ASSERT(ppUnitFirst, 87);
    pUnit->ptRoomNext = *ppUnitFirst;
    *ppUnitFirst = pUnit;

    UNITROOM_RefreshUnit(pUnit);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        DUNGEON_IncreaseAlliedCountOfRoom(hRoom);
        break;
    case UNIT_MONSTER:
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_GOOD)
        {
            DUNGEON_IncreaseAlliedCountOfRoom(hRoom);
        }
        break;
    }
    return TRUE;
}

// 0x0064C040
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 123);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && !D2Common_10084(pRoom) && !(pUnit->dwFlags & 0x2000))
    {
        pUnit->dwFlags |= 0x2000;

        D2UnitStrc** ppUnitFirst = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 1);
        D2_ASSERT(ppUnitFirst, 142);

        pUnit->pChangeNextUnit = *ppUnitFirst;
        *ppUnitFirst = pUnit;
    }
}

// 0x0064C0C0
void __stdcall UNITROOM_SortUnitListByTargetY(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc** ppUnitFirst = 0;
    D2UnitStrc** ppUnit = 0;
    D2UnitStrc* pNextUnit = 0;
    D2UnitStrc* pUnit = 0;
    int bContinue = 0;

    ppUnit = DUNGEON_GetUnitListFromRoom(pRoom);
    pUnit = *ppUnit;
    ppUnitFirst = ppUnit;
    D2UnitStrc* pPreviousUnit = 0;

    if (pUnit)
    {
        pNextUnit = pUnit->ptRoomNext;
        do
        {
            bContinue = 0;

            while (pNextUnit)
            {
                int nY = UNITS_GetClientCoordY(pUnit);
                if (nY > UNITS_GetClientCoordY(pNextUnit))
                {
                    if (pPreviousUnit)
                    {
                        pPreviousUnit->ptRoomNext = pNextUnit;
                    }
                    else
                    {
                        *ppUnitFirst = pNextUnit;
                    }

                    pUnit->ptRoomNext = pNextUnit->ptRoomNext;
                    pNextUnit->ptRoomNext = pUnit;
                    pPreviousUnit = pNextUnit;
                    pNextUnit = pUnit->ptRoomNext;
                    bContinue = 1;
                }
                else
                {
                    pPreviousUnit = pUnit;
                    pUnit = pNextUnit;
                    pNextUnit = pNextUnit->ptRoomNext;
                }
            }
        }
        while (bContinue);
    }
}

// 0x0064C350
int __stdcall UNITROOM_AddUnitToRoom(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    return UNITROOM_AddUnitToRoomEx(pUnit, pRoom, 1);
}

// 0x0064C450
void __stdcall UNITROOM_UpdatePath(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 210);

    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
    {
        D2StaticPathStrc* pStaticPath = pUnit->pStaticPath;
        if (pStaticPath->pRoom)
        {
            UNITROOM_RemoveUnitFromRoom(pUnit);
        }
        pStaticPath->pRoom = 0;
        break;
    }

    default:
        PATH_ResetDynamicPathRoom(pUnit->pDynamicPath);
        break;
    }
}

// 0x0064C370
void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* hUnit)
{
    int bReset = 0;

    D2_ASSERT(hUnit, 245);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(hUnit);
    if (!pRoom)
    {
        D2_ASSERT(!hUnit->ptRoomNext, 253);
        return;
    }

    D2UnitStrc** ppRoomUnit = DUNGEON_GetUnitListFromRoom(pRoom);
    D2UnitStrc* pRoomUnit = *ppRoomUnit;
    D2UnitStrc* pPreviousUnit = 0;
    for (; pRoomUnit; pRoomUnit = pRoomUnit->ptRoomNext)
    {
        if (pRoomUnit == hUnit)
        {
            break;
        }

        pPreviousUnit = pRoomUnit;
    }

    if (pRoomUnit)
    {
        bReset = 1;
        if (!pPreviousUnit)
        {
            *ppRoomUnit = pRoomUnit->ptRoomNext;
        }
        else
        {
            pPreviousUnit->ptRoomNext = pRoomUnit->ptRoomNext;
        }

        pRoomUnit->ptRoomNext = 0;

        switch (hUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
            break;

        case UNIT_MONSTER:
            if (STATLIST_GetUnitAlignment(hUnit) == 2)
            {
                DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
            }
            break;
        }
    }

    UNITROOM_RemoveUnitFromUpdateQueue(hUnit);
    hUnit->dwFlags &= ~0x2000;
    if (bReset)
    {
        UNITS_ResetRoom(hUnit);
    }
}

// 0x0064C1B0
void __stdcall UNITROOM_RemoveUnitFromUpdateQueue(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 301);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(hUnit);
    if (!pRoom)
    {
        D2_ASSERT(!hUnit->pChangeNextUnit, 312);
        return;
    }

    D2UnitStrc** ppChangeUnit = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 0);
    D2UnitStrc* pChangeUnit = *ppChangeUnit;
    D2UnitStrc* pPreviousChangeUnit = 0;
    for (; pChangeUnit; pChangeUnit = pChangeUnit->pChangeNextUnit)
    {
        if (pChangeUnit == hUnit)
        {
            break;
        }

        pPreviousChangeUnit = pChangeUnit;
    }

    if (pChangeUnit)
    {
        if (!pPreviousChangeUnit)
        {
            *ppChangeUnit = pChangeUnit->pChangeNextUnit;
            pChangeUnit->pChangeNextUnit = 0;
        }
        else
        {
            pPreviousChangeUnit->pChangeNextUnit = pChangeUnit->pChangeNextUnit;
            pChangeUnit->pChangeNextUnit = 0;
        }
    }
}

// 0x0064C160
void __stdcall UNITROOM_ClearUpdateQueue(D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc** ppChangeUnit = DUNGEON_GetUnitUpdateListFromRoom(pRoom, 0);
    D2UnitStrc* pChangeUnit = *ppChangeUnit;
    while (pChangeUnit)
    {
        D2UnitStrc* pNextChangeUnit = pChangeUnit->pChangeNextUnit;
        pChangeUnit->dwFlags &= ~0x2000;
        pChangeUnit->pChangeNextUnit = 0;
        pChangeUnit = pNextChangeUnit;
    }

    *ppChangeUnit = 0;
}

// 0x0064C260
int __stdcall UNITROOM_IsUnitInRoom(D2ActiveRoomStrc* pRoom, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 340);

    if (!pRoom)
    {
        return 0;
    }

    D2UnitStrc* pRoomUnit = *DUNGEON_GetUnitListFromRoom(pRoom);
    while (pRoomUnit != hUnit)
    {
        pRoomUnit = pRoomUnit->ptRoomNext;
        if (!pRoomUnit)
        {
            return 0;
        }
    }

    return 1;
}

#include "gen/data/Source/D2Common/UNITS/UnitRoom.inc"
