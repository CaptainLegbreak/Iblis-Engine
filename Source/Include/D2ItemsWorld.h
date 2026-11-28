#pragma once
struct D2PoolSystemStrc;
// Items and the world: an item's data and drop parameters, preset units, object control and monster regions, unit-finding data, curses and pets.

#include "D2Check.h"
#include "D2Structs.h"

struct D2ActiveRoomStrc;
struct D2GameStrc;
struct D2InventoryStrc;
struct D2MapAIStrc;
struct D2ObjectRegionStrc;
struct D2ObjectRoomCoordStrc;
struct D2UnitFindArgStrc;
struct D2UnitStrc;
struct D2ItemExtraDataStrc;
struct D2MonRegDataStrc;
struct D2ItemDataStrc;
struct D2ItemDropStrc;
struct D2PresetUnitStrc;
struct D2ObjectControlStrc;
struct D2MonsterRegionStrc;
struct D2UnitFindDataStrc;
struct D2CurseStrc;
struct D2PetInfoStrc;

struct D2ItemExtraDataStrc
{
    D2InventoryStrc* pParentInv; // 0x00
    D2UnitStrc* pPreviousItem; // 0x04
    D2UnitStrc* pNextItem; // 0x08
    unsigned char nNodePos; // 0x0C
    unsigned char nNodePosOther; // 0x0D
    unsigned short pad0x0E; // 0x0E
    D2UnitStrc* pPreviousGridItem; // 0x10
    D2UnitStrc* pNextGridItem; // 0x14
};

struct D2MonRegDataStrc
{
    short nMonHcIdx; // 0x00
    unsigned char nRarity; // 0x02
    unsigned char nComponentVariantsMax; // 0x03
    unsigned char nComponentVariants[3][16]; // 0x04
};

// Item qualities: the value of D2ItemDataStrc::dwQualityNo.
enum D2C_ItemQualities
{
    ITEMQUAL_INFERIOR = 1,
    ITEMQUAL_NORMAL = 2,
    ITEMQUAL_SUPERIOR = 3,
    ITEMQUAL_MAGIC = 4,
    ITEMQUAL_SET = 5,
    ITEMQUAL_RARE = 6,
    ITEMQUAL_UNIQUE = 7,
    ITEMQUAL_CRAFT = 8,
    ITEMQUAL_TEMPERED = 9,
};

struct D2ItemDataStrc
{
    int dwQualityNo; // 0x00
    D2SeedStrc pSeed; // 0x04
    int dwOwnerGUID; // 0x0C
    unsigned int dwInitSeed; // 0x10
    unsigned int dwCommandFlags; // 0x14
    unsigned int dwItemFlags; // 0x18
    int dwRealmData[2]; // 0x1C
    int dwActionStamp; // 0x24
    int dwFileIndex; // 0x28
    int dwItemLevel; // 0x2C
    unsigned short wItemFormat; // 0x30
    unsigned short wRarePrefix; // 0x32
    unsigned short wRareSuffix; // 0x34
    unsigned short wAutoAffix; // 0x36
    unsigned short wMagicPrefix[3]; // 0x38
    unsigned short wMagicSuffix[3]; // 0x3E
    unsigned char nBodyLoc; // 0x44
    char nInvPage; // 0x45
    unsigned char nCellOverlap; // 0x46
    unsigned char nItemCell; // 0x47
    unsigned char nEarLvl; // 0x48
    unsigned char nInvGfxIdx; // 0x49
    char szPlayerName[16]; // 0x4A
    unsigned short pad0x5A; // 0x5A
    D2ItemExtraDataStrc pExtraData; // 0x5C
};

struct D2ItemDropStrc
{
    D2UnitStrc* pUnit; // 0x00
    D2SeedStrc* pSeed; // 0x04
    D2GameStrc* pGame; // 0x08
    int nItemLvl; // 0x0C
    int unused0x10; // 0x10
    int nId; // 0x14
    int nSpawnType; // 0x18
    int nX; // 0x1C
    int nY; // 0x20
    D2ActiveRoomStrc* pRoom; // 0x24
    unsigned short wUnitInitFlags; // 0x28
    unsigned short wItemFormat; // 0x2A
    int bForce; // 0x2C
    int nQuality; // 0x30
    int nQuantity; // 0x34
    int nMinDur; // 0x38
    int nMaxDur; // 0x3C
    int nItemIndex; // 0x40
    unsigned int dwFlags1; // 0x44
    unsigned int dwSeed; // 0x48
    unsigned int dwItemSeed; // 0x4C
    int eEarLvl; // 0x50
    int nQtyOverride; // 0x54
    char szName[16]; // 0x58
    int nPrefix[3]; // 0x68
    int nSuffix[3]; // 0x74
    unsigned int dwFlags2; // 0x80
};

struct D2PresetUnitStrc
{
    int nMode; // 0x00
    int nIndex; // 0x04
    int nXpos; // 0x08
    D2PresetUnitStrc* pNext; // 0x0C
    D2MapAIStrc* pMapAI; // 0x10
    int nUnitType; // 0x14
    int nYpos; // 0x18
    int bSpawned; // 0x1C
};

struct D2ObjectControlStrc
{
    D2SeedStrc pSeed; // 0x00
    int nShrineCounts[8]; // 0x08
    int* pShrineSubTypeIds[8]; // 0x28
    D2ObjectRegionStrc* pObjectRegion[1024]; // 0x48
    unsigned short wGroupCount[97]; // 0x1048
    unsigned short wRoomsTried; // 0x110A
    unsigned short wRoomsNoGroup; // 0x110C
    unsigned short pad0x110E; // 0x110E
    D2ObjectRoomCoordStrc* pObjectRoomCoord; // 0x1110
};

struct D2MonsterRegionStrc
{
    unsigned char nAct; // 0x00
    unsigned char pad0x01; // 0x01
    unsigned short pad0x02; // 0x02
    int nCount; // 0x04
    int nPopulated; // 0x08
    int nMonsterRegionLevel; // 0x0C
    unsigned char nMonCount; // 0x10
    unsigned char nTotalRarity; // 0x11
    unsigned char nSpawnCount; // 0x12
    unsigned char pad0x13; // 0x13
    D2MonRegDataStrc pMonData[13]; // 0x14
    int nMonsterCount; // 0x2B8
    unsigned char nBossMin; // 0x2BC
    unsigned char nBossMax; // 0x2BD
    unsigned char nMonWander; // 0x2BE
    unsigned char pad0x2BF; // 0x2BF
    int dwlevel; // 0x2C0
    int nWanderingCount; // 0x2C4
    unsigned int dwUniqueCount; // 0x2C8
    unsigned int dwMonSpawnCount; // 0x2CC
    unsigned int dwMonKillCount; // 0x2D0
    int nTrapVariant; // 0x2D4
    unsigned char nQuest; // 0x2D8
    unsigned char pad0x2D9; // 0x2D9
    unsigned short pad0x2DA; // 0x2DA
    int nDungeonLevel; // 0x2DC
    int nDungeonLevelEx; // 0x2E0
};

struct D2UnitFindDataStrc
{
    D2PoolSystemStrc* pMemPool; // 0x00
    D2UnitStrc** pUnitsArray; // 0x04
    D2ActiveRoomStrc* pRoom; // 0x08
    void* pfnUnitTest; // 0x0C
    D2UnitFindArgStrc* pUnitFindArg; // 0x10
    int nFlags; // 0x14
    int nIndex; // 0x18
    int nMaxArrayEntries; // 0x1C
    int nX; // 0x20
    int nY; // 0x24
    int nSize; // 0x28
};

struct D2CurseStrc
{
    D2UnitStrc* pUnit; // 0x00
    D2UnitStrc* pTarget; // 0x04
    int nSkill; // 0x08
    int nSkillLevel; // 0x0C
    int nDuration; // 0x10
    int nStat; // 0x14
    int nStatValue; // 0x18
    int nState; // 0x1C
    StatListRemoveFunc pStateRemoveCallback; // 0x20
};

struct D2PetInfoStrc
{
    unsigned int nSeed; // 0x00
    int nName; // 0x04
    int nHirelingId; // 0x08
};

D2_CHECK_SIZE(D2ItemExtraDataStrc, 0x18);
D2_CHECK_SIZE(D2MonRegDataStrc, 0x34);
D2_CHECK_SIZE(D2ItemDataStrc, 0x74);
D2_CHECK_SIZE(D2ItemDropStrc, 0x84);
D2_CHECK_SIZE(D2PresetUnitStrc, 0x20);
D2_CHECK_SIZE(D2ObjectControlStrc, 0x1114);
D2_CHECK_SIZE(D2MonsterRegionStrc, 0x2E4);
D2_CHECK_SIZE(D2UnitFindDataStrc, 0x2C);
D2_CHECK_SIZE(D2CurseStrc, 0x24);
D2_CHECK_SIZE(D2PetInfoStrc, 0xC);
