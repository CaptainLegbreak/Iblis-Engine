#pragma once
// Objects and map AI: an object's data, the arguments of object operate functions, and a monster's map AI path.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Path.h"

struct D2CoordStrc;
struct D2GameStrc;
struct D2MapAIPathPositionStrc;
struct D2ObjectControlStrc;
struct D2ObjectsTxt;
struct D2ShrinesTxt;
struct D2ObjectDataStrc;
struct D2ObjOperateFnStrc;
struct D2MapAIStrc;

struct D2ObjectDataStrc
{
    D2ObjectsTxt* pObjectTxt; // 0x00
    unsigned char InteractType; // 0x04
    unsigned char nPortalFlags; // 0x05
    unsigned short pad0x06; // 0x06
    D2ShrinesTxt* pShrineTxt; // 0x08
    int dwOperateGUID; // 0x0C
    int bPermanent; // 0x10
    int unused0x14; // 0x14
    D2CoordStrc DestRoomCooords; // 0x18
    D2CoordStrc DestPortalCoords; // 0x20
    char szOwner[16]; // 0x28
};

struct D2ObjOperateFnStrc
{
    D2GameStrc* pGame; // 0x00
    D2UnitStrc* hObject; // 0x04
    D2UnitStrc* hPlayer; // 0x08
    D2ObjectControlStrc* pObjectregion; // 0x0C
    int nObjectIdx; // 0x10
};

struct D2MapAIStrc
{
    int nPathNodes; // 0x00
    D2MapAIPathPositionStrc* pPosition; // 0x04
};

D2_CHECK_SIZE(D2ObjectDataStrc, 0x38);
D2_CHECK_SIZE(D2ObjOperateFnStrc, 0x14);
D2_CHECK_SIZE(D2MapAIStrc, 0x8);
