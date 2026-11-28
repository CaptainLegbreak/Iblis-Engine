#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2CommonApi.h"

struct Sub004BDFD0;



// 0x004BF990
D2UnitStrc* __cdecl sub_004BF990_GetPlayerCursorItem()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (pPlayer)
    {
        return INVENTORY_GetCursorItem(pPlayer->pInventory);
    }
    return 0;
}
