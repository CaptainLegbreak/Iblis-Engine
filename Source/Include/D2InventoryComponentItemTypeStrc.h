#pragma once
// One row of the table that maps a composite armor or weapon code to its item type.

struct D2InventoryComponentItemTypeStrc
{
    int dwCode; // 0x00
    int nItemType; // 0x04
};
