#pragma once
// Game records: unit-find arguments, item save records, NPC trade records and network packet data, and the magic affix records.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Records.h"

struct D2InventoryStrc;
struct D2NpcEventStrc;
struct D2NpcGambleStrc;
struct D2NpcVendorChainStrc;
struct D2ItemCacheStrc;
struct D2MercDataStrc;
struct D2NpcItemProxyStrc;
struct D2NpcTradeDataStrc;
struct D2UnitStrc;
struct D2UnitFindArgStrc;
struct D2ItemSaveStrc;
struct D2NpcRecordStrc;
struct D2PacketDataStrc;
struct D2MagicAffixTxt;

struct D2UnitFindArgStrc
{
    int nFlags; // 0x00
    int unused0x04; // 0x04
    D2UnitStrc* pUnit; // 0x08
    int nX; // 0x0C
    int nY; // 0x10
    int nSize; // 0x14
    int nMaxArrayEntries; // 0x18
    int nIndex; // 0x1C
    void* pField; // 0x20
    void* pfnUnitTest; // 0x24
    int unused0x28[4]; // 0x28
};

struct D2ItemSaveStrc
{
    int nClassId; // 0x00
    unsigned short nX; // 0x04
    unsigned short nY; // 0x06
    unsigned char bMode; // 0x08
    unsigned char nPad09; // 0x09
    unsigned short nPad0A; // 0x0A
    unsigned int dwFlags; // 0x0C
    unsigned char nStorePage; // 0x10
    unsigned char nBodyloc; // 0x11
    unsigned short nPad12; // 0x12
    int nItemFileIndex; // 0x14
};

struct D2MercDataStrc
{
    unsigned short nMercName; // 0x00
    unsigned short pad0x02; // 0x02
    int dwSeed; // 0x04
    int bHired; // 0x08
    int bAvailable; // 0x0C
};

struct D2NpcItemProxyStrc
{
    D2ItemCacheStrc* pItemCache; // 0x00
    int nItems; // 0x04
    unsigned int* pPermCache; // 0x08
    int nPerms; // 0x0C
};

struct D2NpcTradeDataStrc
{
    unsigned char bVendorInit; // 0x00
    unsigned char bHireInit; // 0x01
    unsigned char nAct; // 0x02
    unsigned char bTrader; // 0x03
    unsigned char bRepair; // 0x04
    unsigned char bVendor; // 0x05
    unsigned char bForceVendor; // 0x06
    unsigned char bRefreshInventory; // 0x07
    unsigned int dwTicks; // 0x08
    D2NpcItemProxyStrc tProxy; // 0x0C
};

struct D2NpcRecordStrc
{
    int nNPC; // 0x00
    D2InventoryStrc* pInventory; // 0x04
    D2NpcGambleStrc* pGamble; // 0x08
    int bGambleInit; // 0x0C
    D2MercDataStrc* pMercData; // 0x10
    D2NpcEventStrc* pEvent; // 0x14
    D2NpcVendorChainStrc* pVendorChain; // 0x18
    int bTrading; // 0x1C
    union
    {
        struct
        {
            unsigned char bVendorInit; // 0x20
            unsigned char bInitialized; // 0x21
            unsigned char nAct; // 0x22
            unsigned char bTrader; // 0x23
            unsigned char bRepair; // 0x24
            unsigned char bVendor; // 0x25
            unsigned char bForceVendor; // 0x26
            unsigned char bRefreshInventory; // 0x27
            unsigned int dwTicks; // 0x28
            union
            {
                struct
                {
                    void* pItemCache; // 0x2C
                    int nPerms; // 0x30
                    union
                    {
                        void* pPermCache; // 0x34
                        int* pPermStoreItems; // 0x34
                    };
                    int nPermStoreItems; // 0x38
                };
                D2NpcItemProxyStrc tProxy; // 0x2C
            };
        };
        D2NpcTradeDataStrc tTrade; // 0x20
    };
    int unused0x3C; // 0x3C
    int dwNPCGUID; // 0x40
};

struct D2PacketDataStrc
{
    int nPacketSize; // 0x00
    unsigned char packetData[512]; // 0x04
    D2PacketDataStrc* pNext; // 0x204
};

struct D2MagicAffixTxt
{
    char szName[32]; // 0x00
    unsigned short wTblIndex; // 0x20
    unsigned short wVersion; // 0x22
    D2PropertyStrc pProperties[3]; // 0x24
    unsigned char bSpawnable; // 0x54
    unsigned char unused0x55; // 0x55
    unsigned char nTransformColor; // 0x56
    unsigned char pad0x57; // 0x57
    int nLevel; // 0x58
    int dwGroup; // 0x5C
    int nMaxLevel; // 0x60
    unsigned char bRare; // 0x64
    unsigned char levelReq; // 0x65
    unsigned char nClass; // 0x66
    unsigned char characterClass; // 0x67
    unsigned char classLevelReq; // 0x68
    unsigned char pad0x69; // 0x69
    short wIType[7]; // 0x6A
    short wEType[5]; // 0x78
    unsigned char nFrequency; // 0x82
    unsigned char pad0x83; // 0x83
    int dwDivide; // 0x84
    int dwMultiply; // 0x88
    int dwAdd; // 0x8C
};

D2_CHECK_SIZE(D2UnitFindArgStrc, 0x38);
D2_CHECK_SIZE(D2ItemSaveStrc, 0x18);
D2_CHECK_SIZE(D2MercDataStrc, 0x10);
D2_CHECK_SIZE(D2NpcItemProxyStrc, 0x10);
D2_CHECK_SIZE(D2NpcTradeDataStrc, 0x1C);
D2_CHECK_SIZE(D2NpcRecordStrc, 0x44);
D2_CHECK_SIZE(D2PacketDataStrc, 0x208);
D2_CHECK_SIZE(D2MagicAffixTxt, 0x90);
