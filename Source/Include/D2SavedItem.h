#pragma once
// An item as the character save reader and writer pass it around (PLRSAVE_ functions, Clients.cpp).

struct D2SavedItemStrc
{
    unsigned char nBodyLoc; // 0x00
    unsigned char nSocketedItems; // 0x01
    int nItemLevel; // 0x04
    int nItemId; // 0x08
    unsigned char nSpawnType; // 0x0C
    unsigned char nItemQuality; // 0x0D
    int nQuantity; // 0x10
    int nMinDurability; // 0x14
    int nMaxDurability; // 0x18
    int nX; // 0x1C
    int nY; // 0x20
    int nItemIndex; // 0x24
    unsigned int nItemFlags; // 0x28
    unsigned int nSeed; // 0x2C
    unsigned int nItemSeed; // 0x30
    unsigned char nInvPage; // 0x34
    unsigned char nEarLevel; // 0x35
    char szName[16]; // 0x36
    unsigned short nItemFormat; // 0x46
    unsigned int nItemCode; // 0x48
};
