#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"
#include "D2LevelTxt.h"
#include "D2Txt.h"
#include "D2Constants.h"
#include "D2ItemsWorld.h"
#include "D2TxtTables.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00732904

struct D2ClientStrc;

struct D2ItemsTxt;

struct D2UnitStrc;

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define ITEMQUAL_UNIQUE 7

#define IFLAG_NEWITEM 0x00000001

#define IFLAG_BROKEN 0x00000100

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_MONSTER 1

#define STAT_HITPOINTS 6

#define STAT_MANA 8

#define STAT_STAMINA 10

#define STAT_GOLD 14

#define IFLAG_IDENTIFIED 0x00000010

#define NPC_CLASS_150 150

#define NPC_CLASS_515 515

#define NPC_CLASS_198 198

#define CHECK(p,line) if (!(p)) { FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),line); exit(-1); }

struct D2PlayerDataStrc;

struct D2MonsterItemCodeStrc;

struct D2StaticPathStrc;

struct D2NpcGambleStrc;

struct D2NpcRecordStrc;

union D2SeedStrc;


struct D2NpcVendorChainStrc;

struct D2MonsterItemCodeStrc
{
    unsigned int nItemCode;
    unsigned char nBodyLoc;
};

extern "C" const char gszNpcSourceFile[]; // 0x006E15F0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int a5, int* pUnused); // 0x005606B0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex); // 0x00483470

void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

int __fastcall D2GAME_CheckHasFilledSockets(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590

int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FE80

D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(int bExpansion, int nVendorId, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x006564D0

void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005761C0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc, int* pIndex); // 0x00535F10

bool __fastcall SUNITNPC_IsPermanentStoreItem(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem); // 0x00576ED0

void __fastcall SUNITNPC_AddGambleItem(D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit); // 0x00576650

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

typedef void (__fastcall* PetIterateCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

void __fastcall D2GAME_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType); // 0x0053D740

void __fastcall D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(D2ClientStrc* pClient, unsigned short nUnitGUID, int a3); // 0x0053E0E0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetIterateCallback pCallback, void* pArg); // 0x00574DE0

int __fastcall SUNITNPC_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost); // 0x00576D90

void __fastcall SUNITNPC_HireMercenaryFromRoster(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, unsigned short wName); // 0x005770E0

int __fastcall SUNITNPC_BuyItem(D2GameStrc* ptGame,D2UnitStrc* pPlayer,D2UnitStrc* pNpc,int nItemGuid,int nItemMode,unsigned short nTransaction,int nQuotedCost,int bMultibuy); // 0x00577830

int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit); // 0x00578C20

void __fastcall SUNITNPC_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg); // 0x00578CA0

void __fastcall SUNITNPC_ResurrectHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet); // 0x00579AA0

void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

unsigned int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_GetNoOfUnidItems(D2UnitStrc* pPlayer); // 0x0062A530

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

unsigned int __stdcall MONSTERS_GetHirelingResurrectionCost(D2UnitStrc* pHireling); // 0x006637B0

D2InventoryStrc* __fastcall SUNITPROXY_GetGambleInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536C50

int __fastcall ITEMMODE_RemoveStoredItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4, int a5, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int a8); // 0x00560420

void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

void __fastcall D2GAME_STORES_FillVendorCache(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bGamble); // 0x00578B30

void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc); // 0x00536D10

void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeDataStrc* pTrade); // 0x00576980

void __fastcall SUNITNPC_AddItemsToTrade(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory); // 0x00576C30

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc*, int); // 0x006439F0

int __stdcall SKILLS_GetQuantity(D2SkillStrc*); // 0x006450F0

void __stdcall SKILLS_SetQuantity(D2SkillStrc*, int); // 0x00645120

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc*); // 0x006201D0

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc*, int, int, int); // 0x005701B0

void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc*, unsigned char, int, int, int); // 0x0053C520

void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc*,D2UnitStrc*,unsigned int); // 0x0055B060

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

void __fastcall D2GAME_STORES_FillGamble_6FCCA9F0(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pUnit, D2NpcRecordStrc* pNpcRecord); // 0x00578790

void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc); // 0x00578D30

D2NpcRecordStrc* __fastcall SUNITPROXY_GetNpcRecordFromClassId(D2GameStrc* pGame, int nNpcClassId, int* pIndex); // 0x00535EA0

void __fastcall SUNITNPC_RefreshHirelingRoster(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord); // 0x00577010

void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

void __fastcall MONSTERAI_AssignHireling(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nId, D2MercDataStrc* pMercData, int bDead); // 0x00573270

struct D2NpcVendorChainStrc
{
    int dwGUID;
    unsigned char bGamble;
};

D2NpcVendorChainStrc* __fastcall SUNITPROXY_GetVendorChain(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pPlayer); // 0x00536CB0

#define SEND_GOLD(code,line,guid,kind) D2GAME_SendPacket0x2A(UnitGetClient(pPlayer,gszNpcSourceFile,line),0x2A,code,STATLIST_UnitGetStatValue(pPlayer,STAT_GOLD,0),guid,kind)

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9

D2SeedStrc* __fastcall SUNITPROXY_GetSeedFromNpcControl(D2GameStrc* pGame); // 0x00536B40

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

struct D2LowQualityItemsTxt
{
    char name[32];
};

D2LowQualityItemsTxt* __stdcall DATATBLS_GetLowQualityItemsTxtRecord(int nIndex); // 0x006375C0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590

unsigned char __stdcall ITEMS_GetStorePage(D2UnitStrc* pItem); // 0x0062E880

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall D2GAME_PlaceItem_6FC44410(const char*, int, D2GameStrc*, D2UnitStrc*, int, int, int, int, int, D2InventoryStrc*); // 0x00560200

void __fastcall SUNITPROXY_AllocNpcEvent(D2UnitStrc*, D2GameStrc*, D2UnitStrc*, int); // 0x00535F30

void __fastcall SUNITNPC_SetItemTradeFlags(D2UnitStrc*, D2UnitStrc*, D2GameStrc*, int, int); // 0x005762C0

extern int gnSpecialItem1; // 0x00883E9C

extern int gnSpecialItem2; // 0x00883EA0

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc*,D2UnitStrc*); // 0x00543520

int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc*,D2UnitStrc*,D2InventoryStrc*); // 0x00557FF0

D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055A2A0

int __fastcall ITEMMODE_PlaceCursorItemInBelt(D2GameStrc*,D2UnitStrc*,int,int,int,int*); // 0x0055E9B0

D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int*); // 0x0055F640

void __fastcall ITEMMODE_AddBookQuantity(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055F6E0

int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x00562E00

void __fastcall SUNITNPC_RemovePurchasedItemFromStore(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x00576F50

int __fastcall UNITS_GetWeaponClass(D2UnitStrc*); // 0x00623C60

int __stdcall ITEMSIsA(D2UnitStrc*,int); // 0x00629BB0

unsigned int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc*); // 0x0063BEF0

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850

D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200

D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0

int __fastcall SUNITNPC_CapStoreItemLevel(D2GameStrc* pGame, D2UnitStrc* pNpc, int nArg); // 0x00576890

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* game,D2UnitStrc* pet,int id,int type,int a,int b); // 0x0058F030

void __fastcall PLAYERPETS_RemovePet(D2GameStrc* game,D2UnitStrc* player,int id,int flags); // 0x005750E0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* unit); // 0x00620BB0

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* room,int type,int id); // 0x0061A270

int __fastcall PLAYERPETS_MarkPetAlive(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet); // 0x00574AB0

void __fastcall sub_005B1900_InitAi(D2GameStrc* game,D2UnitStrc* pet,int flag,int owner); // 0x005B1900

void __stdcall STATES_ToggleState(D2UnitStrc* unit,int state,int set); // 0x00639DB0

int __fastcall SUNITNPC_RelinkItemStatLists(D2UnitStrc* pUnit); // 0x00577470

void __fastcall PLAYERPETS_UpdatePetsForOwnerMove(D2GameStrc* game,D2UnitStrc* player,int x,int y); // 0x005754B0

void __fastcall MONSTERAI_SendMercStats(D2GameStrc* game,D2UnitStrc* player,int value); // 0x005726C0

int __fastcall SUNITNPC_GetHirelingNamesAndClass(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass); // 0x00575FF0

void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);          // 0x0053B320

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient);                                              // 0x005387C0

void __fastcall SUNITNPC_InitializeHirelingRoster(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord); // 0x00576070

void __fastcall D2GAME_SendPacket0x4E_6FC3F410(D2ClientStrc* pClient, D2GSPacketSrv4E* pPacket);           // 0x0053D7B0

struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2WaypointDataStrc;

#define STAT_LEVEL 12

#define ITEMQUAL_NORMAL 2

#define ITEMQUAL_MAGIC 4

#define STORE_LEVEL_BONUS 5

#define STORE_HIGH_LEVEL 25

#define ITEM_VERSION_EXPANSION 100

#define STORE_MAX_FAILED_ITEMS 32

#define ITEMCODE_CROSSBOW_BOLTS ' vqc'

#define ITEMCODE_ARROWS ' vqa'

#define FILLSTORE_ASSERT_LINE 713

#define IFLAG_SOCKETED 0x800

struct D2ItemCacheStrc;

struct D2UnitProxyStrc;

struct D2MonsterDataStrc;

struct D2MonStatsTxt;


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __fastcall OBJECTS_RollRandomNumber(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004BC500

int __stdcall ITEMS_CheckBitField1Flag1(int nItemId); // 0x00629C80

D2UnitStrc* __fastcall D2GAME_NPC_GenerateStoreItem_6FCC6A60(D2UnitStrc* pNpc, unsigned int dwCode, D2GameStrc* pGame, int bVendorItem, int nQuality, int nItemLevel, int nPlayerLevel); // 0x00576330

int __fastcall SUNITNPC_RollStoreItemQuality(D2SeedStrc* pSeed, unsigned int dwCode, int nItemLevel);

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80

void __fastcall D2GAME_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0

void __fastcall QUESTS_ActChange_HirelingChangeAct(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pVendor, unsigned int dwDestLvl, unsigned int nUnused); // 0x005467E0

D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00547F50

void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDestLevel, int nTileCalc); // 0x0054B830

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevel); // 0x00558200

void __fastcall ITEMS_FillItemDrop(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x00558270

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90

int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0

void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0055FE00

void __fastcall ITEMMODE_DropCursorItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID); // 0x00563C00

void __fastcall SKILLS_ResetSkillsAndRefundPoints(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00570360

void __fastcall sub_00570C80_PLAYERSTATS_ResetToBaseStats(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00570C80

void __fastcall MONSTERAI_SetInteractTrading(D2UnitStrc* pNpc, D2UnitStrc* pPlayer); // 0x00572EA0

void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bSingle); // 0x00576770

static int __stdcall SUNITNPC_IsCursorItem(unsigned int nItemGUID, D2UnitStrc* pUnit); // 0x00578610

void __fastcall D2GAME_STORES_CreateVendorCache(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bRefresh, int bGamble); // 0x00579430

void __fastcall ACT5Q1_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005877C0

void __fastcall ACT5Q4_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0058BC00

void __fastcall ACT1Q1_SetRespecRewardPending(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0058FD20

void __fastcall ACT1Q1_SetRespecRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0058FD50

void __fastcall ACT1Q3_SetRewardGranted(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00591790

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoords); // 0x00620870

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90

unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110

int __stdcall ITEMS_CheckIfFlagIsSet(unsigned int dwFlags, unsigned int dwMask); // 0x006287A0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets); // 0x0062BCB0

int __stdcall ITEMS_CanBeImbued(D2UnitStrc* pItem); // 0x0062C590

int __stdcall ITEMS_IsPersonalizable(D2UnitStrc* pItem); // 0x0062C6A0

int __stdcall ITEMS_IsSocketable(D2UnitStrc* pItem); // 0x0062C770

int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, int* pWaypointNo); // 0x00660E00

void __stdcall WAYPOINTS_ActivateWaypoint(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660EC0

#define D2_MIN(a,b) ((a)<(b)?(a):(b))

#define D2_MAX(a,b) ((a)>(b)?(a):(b))

struct D2DifficultyLevelsTxt;

void __fastcall FOG_FreeServerMemory(void*, void*, const char*, int, int); // 0x0040B480

D2GambleDataTbl* __fastcall DATATBLS_GetGambleDataTables(); // 0x00638CC0

struct D2DifficultyLevelsGambleStrc
{
    int nGambleRare;
    int nGambleSet;
    int nGambleUnique;
    int nGambleUber;
    int nGambleUltra;
};

#define DIFFICULTY_GAMBLE(pDifficulty) ((D2DifficultyLevelsGambleStrc*)((pDifficulty) + 1))

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int); // 0x00611D30

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int); // 0x006335F0

struct D2HirelingInitStrc;

struct D2HirelingInitStrc
{
    int nId;
    int nLevel;
    int nHitpoints;
    int nStrength;
    int nDexterity;
    int nGold;
    int nExperience;
    int nDefense;
    int nMinDamage;
    int nMaxDamage;
    int nShare;
    int nResist;
    int nHireDesc;
    int field_34;
    short nFlags;
    short unk0x3A;
};

int __fastcall MONSTERS_GetActFromHirelingTxt(int bExpansion, int nClassId, unsigned short nNameId); // 0x00663750

int __fastcall MONSTERS_HirelingInit(int bExpansion, D2UnitStrc* pMonster, int nLowSeed, int nAct, int nDifficulty, D2HirelingInitStrc* pHirelingInit); // 0x006637F0

int __fastcall MONSTERAI_HasInteractUnit(D2MonsterInteractStrc* pMonInteract); // 0x00572DC0

void __stdcall INVENTORY_RemoveInventoryItems(D2InventoryStrc* pInventory); // 0x0063CB70

void __stdcall D2COMMON_10251_Return(D2InventoryStrc* pInventory); // 0x0063BD00

unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient);                                           // 0x005382B0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

D2HirelingTxt* __stdcall DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(int bExpansion, int nAct, int nDifficulty, D2HirelingTxt* pOldRecord); // 0x00656580

void __fastcall SUNITNPC_FillGambleIfMissing(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2NpcRecordStrc* pNpcRecord); // 0x00578AE0

unsigned int __stdcall UNITS_GetHealingCost(D2UnitStrc* pUnit); // 0x00622DE0

struct D2InventoryStrc;

void __fastcall SUNITNPC_RepairItemCallback(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x005762B0

int __stdcall ITEMS_GetAllRepairCosts(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcId, int nDifficulty, D2BitBufferStrc* pQuestFlags, void (__fastcall* pfCallback)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*)); // 0x0062FE60

int __stdcall ITEMS_GetTransactionCost(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nDifficulty, D2BitBufferStrc* pQuestFlags, int nNpcId, int nMode); // 0x0062FDC0

int __stdcall ITEMS_IsRepairable(D2UnitStrc* pItem); // 0x0062E660

int __stdcall ITEMS_HasUsedCharges(D2UnitStrc* pItem, int* pHasChargedSkills); // 0x0062A840

#define SEND_0x2A(nResult, nLine, bSuccess) D2GAME_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, nLine), 0x2A, nResult, STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0), -1, bSuccess)

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc*,D2UnitStrc*,D2UnitStrc*,unsigned int); // 0x0053D010

void __fastcall D2GAME_RemoveItem(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int); // 0x0055DF10

int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc*,D2UnitStrc*,unsigned char,int,int*); // 0x00560CD0

int __fastcall SUNITNPC_IsUniqueCarryOneItem(D2UnitStrc*); // 0x00575FA0

void __fastcall SUNITNPC_DecreaseSkillQuantity(D2UnitStrc*,int,int); // 0x00576E40

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc*,int); // 0x00627F80

void __stdcall ITEMS_SetItemCell(D2UnitStrc*,unsigned char); // 0x00628320

void __stdcall ITEMS_SetOrRemoveFlag(int*,int,int); // 0x006287B0

int __stdcall ITEMS_IsNotQuestItem(D2UnitStrc*); // 0x0062A130

int __stdcall ITEMS_GetItemType(D2UnitStrc*); // 0x0062B400

D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int); // 0x006374B0

static inline int GetMode(D2UnitStrc* unit) { if (unit) return unit->dwAnimMode; return 0; }

#define SEND_ERROR(code,line) D2GAME_SendPacket0x2A(UnitGetClient(player,gszNpcSourceFile,line),0x2A,code,STATLIST_UnitGetStatValue(player,STAT_GOLD,0),-1,0)

int gnRingId; // 0x0088CACC

int gnAmuletId; // 0x0088CAC8

static int __stdcall SUNITNPC_RollGambleUpgrade(int nItemId, int nUberChance, int nUltraChance, D2GameStrc* pGame, int nItemLevel);

int gnNpcGUID; // 0x0088CAC4

inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

// 0x00575FA0
int __fastcall SUNITNPC_IsUniqueCarryOneItem(D2UnitStrc* pItem)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_UNIQUE)
    {
        return 0;
    }

    if (ITEMS_GetFileIndex(pItem) < 0)
    {
        return 0;
    }

    D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pItem));
    if (!pUniqueItemsTxtRecord)
    {
        return 0;
    }

    return (pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7]) != 0;
}

// 0x00575FF0
int __fastcall SUNITNPC_GetHirelingNamesAndClass(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(pGame->bExpansion, nHirelingId, 0, 0);
    if (!pHirelingTxtRecord)
    {
        *pNameFirst = 0;
        *pNameLast = 0;
        *pClass = 0;
        return -1;
    }

    *pNameFirst = pHirelingTxtRecord->wNameFirst;
    *pNameLast = pHirelingTxtRecord->wNameLast;
    if (pClass)
    {
        *pClass = pHirelingTxtRecord->dwClass;
    }

    const int nCount = *pNameLast - *pNameFirst + 1;
    D2_ASSERT(nCount != -1, 96);
    return nCount;
}

static inline int __fastcall SUNITNPC_GetHirelingNameRange(D2GameStrc* pGame, int nHirelingId, int* pNameFirst, int* pNameLast, int* pClass)
{
    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(pGame->bExpansion, nHirelingId, 0, 0);
    if (!pHirelingTxtRecord)
    {
        *pNameFirst = 0;
        *pNameLast = 0;
        *pClass = 0;
        return -1;
    }

    *pNameFirst = pHirelingTxtRecord->wNameFirst;
    *pNameLast = pHirelingTxtRecord->wNameLast;
    if (pClass)
    {
        *pClass = pHirelingTxtRecord->dwClass;
    }

    D2_ASSERT((*pNameLast - *pNameFirst + 1) != -1, 96);
    return (*pNameLast - *pNameFirst + 1);
}

inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00576070
void __fastcall SUNITNPC_InitializeHirelingRoster(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord)
{
    if (pNpcRecord->bInitialized)
    {
        return;
    }

    pNpcRecord->bInitialized = 1;
    if (pNpcRecord->pMercData)
    {
        return;
    }

    pNpcRecord->pMercData = (D2MercDataStrc*)FOG_AllocPool(pGame->pMemoryPool, 0x450, ".\\UNIT\\SUNITNPC.CPP", 0x6E, 0);
    memset(pNpcRecord->pMercData, 0, 0x450);

    D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
    D2MercDataStrc* pMercData = pNpcRecord->pMercData;

    int nMin;
    int nMax;
    const int nCount = SUNITNPC_GetHirelingNamesAndClass(pGame, nVendorId, &nMin, &nMax, 0);
    D2_ASSERT(nCount != -1, 0x7A);

    if (nMin <= nMax)
    {
        int i = 0;
        do
        {
            if (i >= nCount)
            {
                break;
            }

            pMercData[i].nMercName = nMin + i;
            pMercData[i].dwSeed = SEED_RollRandomNumber(pSeed);
            pMercData[i].bHired = 0;
            pMercData[i].bAvailable = 0;
            ++i;
        } while (nMin + i <= nMax);
    }

    for (nMin = 0; nMin < 10; ++nMin)
    {
        int nIndex = SEED_RollLimitedRandomNumber(pSeed, nCount);
        const int nStart = nIndex;
        for (;;)
        {
            if (!pMercData[nIndex].bAvailable && !pMercData[nIndex].bHired)
            {
                pMercData[nIndex].bAvailable = 1;
                break;
            }

            ++nIndex;
            if (nIndex >= nCount)
            {
                nIndex = 0;
            }

            if (nIndex == nStart)
            {
                return;
            }
        }
    }
}

// 0x005761C0
void __fastcall D2GAME_NPC_RepairItem_6FCC6970(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    if (ITEMS_IsRepairable(pItem))
    {
        if (ITEMS_CheckIfThrowable(pItem) && ITEMS_CheckIfStackable(pItem))
        {
            const int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nMaxStack, 0);

            if (pPlayer)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer, gszNpcSourceFile, 185), pItem, 1, STAT_QUANTITY, nMaxStack, 0);
            }
        }

        D2GAME_RechargeItem_6FC4BD50(pGame, pPlayer, pItem);

        if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 191, gszNpcSourceFile))
        {
            D2GAME_RepairBrokenItem_6FC4B630(pGame, pPlayer, pItem);
        }
        else
        {
            const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
            if (nMaxDurability > 0)
            {
                STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);

                if (pPlayer)
                {
                    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer, gszNpcSourceFile, 203), pItem, 1, STAT_DURABILITY, nMaxDurability, 0);
                }
            }
        }
    }
}

// 0x005762B0
void __fastcall SUNITNPC_RepairItemCallback(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2GAME_NPC_RepairItem_6FCC6970(pGame, pItem, pPlayer);
}

static inline D2BitBufferStrc* sub_00578460_GetQuestRecord(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005762C0
void __fastcall SUNITNPC_SetItemTradeFlags(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pUnused, int bAdd, int nUnused)
{
    ITEMS_SetItemFlag(pItem, IFLAG_IDENTIFIED, 1);
    if (bAdd)
    {
        if (pItem)
        {
            pItem->dwFlagEx |= 4;
        }

        if (D2GAME_CheckHasFilledSockets(pItem, gszNpcSourceFile, 233))
        {
            ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 1);
        }

        UNITS_RefreshInventory(pPlayer, 1);
        INVENTORY_AddItemToTradeInventory(pPlayer->pInventory, pItem);
    }
}

int __stdcall sub_0062E880(D2UnitStrc* pItem); // 0x0062E880

// 0x00576320
static inline int SUNITNPC_GetItemStorePage(D2UnitStrc* pItem)
{
    return sub_0062E880(pItem);
}

int __stdcall sub_M114_Emit_00576320(D2UnitStrc* pItem)
{
    return SUNITNPC_GetItemStorePage(pItem) + 1;
}

// 0x00576330
D2UnitStrc* __fastcall D2GAME_NPC_GenerateStoreItem_6FCC6A60(D2UnitStrc* hNPC, unsigned int dwCode, D2GameStrc* ptGame, int bVendorItem, int nQuality, int nItemLevel, int nPlayerLevel)
{
    D2_ASSERT(ptGame, 0x102);
    D2_ASSERT(hNPC, 0x103);
    int nItemId;
    D2ItemsTxt* pRecord = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    unsigned int dwNewCode = dwCode;
    if (ptGame->nDifficulty > 0 && nPlayerLevel > 25)
    {
        if (ptGame->nDifficulty == 1)
        {
            unsigned int nChance = ITEMS_RollLimitedRandomNumber(SUNITPROXY_GetSeedFromNpcControl(ptGame), 100000);
            if (nChance < (unsigned int)(64 * nItemLevel + 4000) && pRecord->dwUberCode && pRecord->dwUberCode != 0x20202020)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUberCode, &nItemId);
                dwNewCode = pRecord->dwUberCode;
            }
            else if (pRecord->dwNightmareUpgrade != 0x20787878)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwNightmareUpgrade, &nItemId);
                dwNewCode = pRecord->dwNightmareUpgrade;
            }
        }
        else
        {
            unsigned int nChance = ITEMS_RollLimitedRandomNumber(SUNITPROXY_GetSeedFromNpcControl(ptGame), 100000);
            if (ptGame->bExpansion && nChance < (unsigned int)(16 * nItemLevel + 1000) && pRecord->dwUltraCode && pRecord->dwUltraCode != 0x20202020)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUltraCode, &nItemId);
                dwNewCode = pRecord->dwUltraCode;
            }
            else if (nChance < (unsigned int)(128 * nItemLevel + 5000) && pRecord->dwUberCode != 0x20202020 && pRecord->dwUberCode)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwUberCode, &nItemId);
                dwNewCode = pRecord->dwUberCode;
            }
            if (pRecord->dwHellUpgrade != 0x20787878)
            {
                DATATBLS_GetItemRecordFromItemCode(pRecord->dwHellUpgrade, &nItemId);
                dwNewCode = pRecord->dwHellUpgrade;
            }
        }
    }
    D2UnitStrc* pItem;
    for (int i = 0; i < 2; ++i)
    {
        int bValid;
        int j = 0;
        do
        {
            bValid = 1;
            pItem = D2GAME_CreateItemUnit_6FC501A0(hNPC, nItemId, ptGame, 4, nQuality, 0, 1, nItemLevel, 0, 0, 0);
            if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_INFERIOR)
            {
                const char* szName = DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(pItem))->name;
                if (!_stricmp(szName, "Cracked"))
            {
                ITEMS_RemoveFromAllPlayers(ptGame, pItem);
                pItem = 0;
                bValid = 0;
                }
            }
            ++j;
        } while (!bValid && j < 5);
        if (!bValid) return 0;
        if (dwNewCode != ITEMS_GetBaseCode(pItem))
        {
            ITEMS_RemoveFromAllPlayers(ptGame, pItem);
            nQuality = 2;
            pItem = 0;
        }
        else
        {
            i = 2;
        }
    }
    if (pItem)
    {
        unsigned char nPage = ITEMS_GetStorePage(pItem);
        if (nPage == 0xFF)
        {
            ITEMS_RemoveFromAllPlayers(ptGame, pItem);
            return 0;
        }
        ITEMS_SetInvPage(pItem, nPage);
        D2GAME_NPC_RepairItem_6FCC6970(ptGame, pItem, 0);
        int nUnitId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0x16C, ptGame, hNPC, nUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 1, 1, 0))
        {
            if (nPage == 1)
            {
                ITEMS_SetInvPage(pItem, 2);
                int nRetryUnitId = pItem->dwUnitId;
                if (D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0x172, ptGame, hNPC, nRetryUnitId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 1, 1, 0))
                {
                    SUNITNPC_SetItemTradeFlags(hNPC, pItem, ptGame, bVendorItem, 0);
                    return pItem;
                }
            }
            SUNITPROXY_AllocNpcEvent(hNPC, ptGame, pItem, 0);
            return 0;
        }
        SUNITNPC_SetItemTradeFlags(hNPC, pItem, ptGame, bVendorItem, 0);
    }
    return pItem;
}

static inline int UNITS_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }

    return -1;
}

// 0x00576650
void __fastcall SUNITNPC_AddGambleItem(D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit)
{
    if (!pItem || !pNpc)
    {
        return;
    }

    D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNpc);
    if (!pGambleInventory)
    {
        return;
    }

    int nUnused;
    ITEMMODE_RemoveStoredItem(pGame, pNpc, UNITS_GetUnitGUIDInline(pItem), &nUnused, 0, 0, pGambleInventory, 0);
    if (bInit)
    {
        pItem->dwFlagEx |= 0x10;
        UNITS_RefreshInventory(pNpc, 1);
        INVENTORY_AddItemToTradeInventory(pGambleInventory, pItem);
        ITEMS_SetItemCMDFlag(pItem, 1, 1);
    }
    else
    {
        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
}

// 0x005766D0
void __fastcall SUNITNPC_RemoveStoreItem(D2UnitStrc* pNpc, D2UnitStrc* pItem, D2GameStrc* pGame, int bInit)
{
    CHECK(pGame, 423);
    CHECK(pNpc, 424);
    CHECK(pItem, 425);
    int nUnused;
    unsigned int nItemGUID = pItem ? pItem->dwUnitId : -1;
    ITEMMODE_RemoveStoredItem(pGame, pNpc, nItemGUID, &nUnused, 0, 0, 0, 0);
    if (bInit)
    {
        pItem->dwFlagEx |= 0x10;
        UNITS_RefreshInventory(pNpc, 1);
        INVENTORY_AddItemToTradeInventory(pNpc->pInventory, pItem);
        ITEMS_SetItemCMDFlag(pItem, 1, 1);
    }
    else
    {
        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
}

// 0x00576770
void __fastcall D2GAME_NPC_BuildHirelingList_6FCC6FF0(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pNpc, int bNoInteractInfo)
{
    if (!pNpc)
    {
        return;
    }

    if (pNpc->dwClassId != MONSTER_KASHYA && pNpc->dwClassId != MONSTER_GREIZ && pNpc->dwClassId != MONSTER_QUAL_KEHK && pNpc->dwClassId != MONSTER_ASHEARA)
    {
        return;
    }

    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0x4F);

    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(CLIENTS_GetGame(pClient), pNpc, &nIndex);
    if (!pNpcRecord)
    {
        return;
    }

    const int nNpcClassId = pNpc->dwClassId;
    if (!pNpcRecord->bInitialized)
    {
        SUNITNPC_InitializeHirelingRoster(CLIENTS_GetGame(pClient), nNpcClassId, pNpcRecord);
    }

    D2MercDataStrc* pMercData = pNpcRecord->pMercData;
    int nNameFirst;
    int nNameLast;
    const int nCount = SUNITNPC_GetHirelingNameRange(pGame, nNpcClassId, &nNameFirst, &nNameLast, 0);
    D2_ASSERT(nCount != -1, 0x1FB);

    for (int i = 0; i < nCount; ++i)
    {
        if (pMercData[i].bAvailable && !pMercData[i].bHired)
        {
            D2GSPacketSrv4E packet;
            packet.nHeader = 0x4E;
            packet.nMercName = pMercData[i].nMercName;
            packet.nSeed = pMercData[i].dwSeed;
            D2GAME_SendPacket0x4E_6FC3F410(pClient, &packet);
        }
    }
}

#define NPC_LEVEL_COUNT 5

// 0x00576890
int __fastcall SUNITNPC_CapStoreItemLevel(D2GameStrc* pGame, D2UnitStrc* pNpc, int nLevel)
{
    if (pGame->nDifficulty == DIFFMODE_NORMAL)
    {
        int nUnused;
        D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
        if (pNpcRecord)
        {
            const int npcLevels[NPC_LEVEL_COUNT] = { 12, 20, 28, 36, 45 };
            if (pNpcRecord->nAct < NPC_LEVEL_COUNT)
            {
                const int nCap = npcLevels[pNpcRecord->nAct];
                return nCap < nLevel ? nCap : nLevel;
            }
        }
    }

    return nLevel;
}

// 0x00576900
int __fastcall SUNITNPC_RollStoreItemQuality(D2SeedStrc* pSeed, unsigned int dwCode, int nItemLevel)
{
    int nQuality = ITEMQUAL_NORMAL;
    const unsigned int nRoll = (unsigned int)SEED_RollRandomNumber(pSeed) % 100;

    if (nItemLevel < 5)
    {
        if (nRoll > 90)
        {
            nQuality = ITEMQUAL_INFERIOR;
        }
    }
    else if (nItemLevel < 10)
    {
        if (nRoll > 85)
        {
            nQuality = ITEMQUAL_SUPERIOR;
        }
    }
    else if (nRoll >= 75)
    {
        nQuality = ITEMQUAL_SUPERIOR;
    }

    return nQuality;
}

// 0x00576980
void __fastcall D2GAME_NPC_FillStoreInventory_6FCC7100(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2NpcTradeDataStrc* pTrade)
{
    D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);

    pTrade->dwTicks = GetTickCount();

    int nNpcIndex;
    int nSpawnedItems = 0;
    int i;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nNpcIndex);
    if (pNpcRecord)
    {
    const int nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nItemLevel = SUNITNPC_CapStoreItemLevel(pGame, pNpc, nLevel + STORE_LEVEL_BONUS);

    for (i = 0; i < pNpcRecord->tProxy.nItems; ++i)
    {
        int nUnused;
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pTrade->tProxy.pItemCache[i].dwCode, &nUnused);
        if (pItemsTxtRecord->nLevel <= nItemLevel)
        {
            unsigned int nNormalItems;
            if (nItemLevel >= STORE_HIGH_LEVEL)
            {
                nNormalItems = 0;
            }
            else
            {
                nNormalItems = OBJECTS_RollRandomNumber(pSeed, pNpcRecord->tProxy.pItemCache[i].nMin, pNpcRecord->tProxy.pItemCache[i].nMax + 1);
            }

            if (pItemsTxtRecord->wVersion < ITEM_VERSION_EXPANSION || pGame->wItemFormat >= ITEM_VERSION_EXPANSION)
            {
                for (unsigned int j = 0; j < nNormalItems; ++j)
                {
                    const int nQuality = SUNITNPC_RollStoreItemQuality(pSeed, pNpcRecord->tProxy.pItemCache[i].dwCode, nItemLevel);
                    if (!D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->tProxy.pItemCache[i].dwCode, pGame, 1, nQuality, nItemLevel, nLevel))
                    {
                        ++nSpawnedItems;
                    }

                    if (nSpawnedItems > STORE_MAX_FAILED_ITEMS)
                    {
                        return;
                    }
                }

                int nItemId;
                DATATBLS_GetItemRecordFromItemCode(pTrade->tProxy.pItemCache[i].dwCode, &nItemId);
                if (ITEMS_CheckBitField1Flag1(nItemId) == 1 && pTrade->tProxy.pItemCache[i].nMagicLevel <= nItemLevel)
                {
                    int nMinItems = 1;
                    if (nItemLevel >= STORE_HIGH_LEVEL)
                    {
                        nMinItems = OBJECTS_RollRandomNumber(pSeed, 1, 3) + 1;
                    }

                    const unsigned int nMagicItems = OBJECTS_RollRandomNumber(pSeed, pNpcRecord->tProxy.pItemCache[i].nMagicMin, pNpcRecord->tProxy.pItemCache[i].nMagicMax + nMinItems);
                    for (unsigned int j = 0; j < nMagicItems; ++j)
                    {
                        if (!D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->tProxy.pItemCache[i].dwCode, pGame, 1, ITEMQUAL_MAGIC, nItemLevel, nLevel))
                        {
                            ++nSpawnedItems;
                        }
                    }
                }
            }
        }
    }

    for (i = 0; i < pNpcRecord->tProxy.nPerms; ++i)
    {
        D2UnitStrc* pStoreItem = D2GAME_NPC_GenerateStoreItem_6FCC6A60(pNpc, pNpcRecord->tProxy.pPermCache[i], pGame, 1, ITEMQUAL_NORMAL, nItemLevel, nLevel);
        if (pStoreItem)
        {
            int nUnused;
            const unsigned int nItemCode = DATATBLS_GetItemRecordFromItemCode(pTrade->tProxy.pPermCache[i], &nUnused)->dwCode;
            if (nItemCode == ITEMCODE_CROSSBOW_BOLTS || nItemCode == ITEMCODE_ARROWS)
            {
                STATLIST_SetUnitStat(pStoreItem, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pStoreItem), 0);
            }
        }
        else
        {
            ++nSpawnedItems;
        }

        if (nSpawnedItems > STORE_MAX_FAILED_ITEMS)
        {
            break;
        }
    }
    }
    else
    {
        D2_ASSERT(0, FILLSTORE_ASSERT_LINE);
    }
}

// 0x00576C30
void __fastcall SUNITNPC_AddItemsToTrade(D2UnitStrc* pPlayer, D2InventoryStrc* pInventory)
{
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pCurrent = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pCurrent)
        {
            pCurrent->dwFlagEx |= 4;
        }

        if (D2GAME_CheckHasFilledSockets(pCurrent, gszNpcSourceFile, 730))
        {
            ITEMS_SetItemFlag(pCurrent, IFLAG_NEWITEM, 1);
        }

        INVENTORY_AddItemToTradeInventory(pPlayer->pInventory, pCurrent);
    }
}

// 0x00576C90
int __fastcall SUNITNPC_RollTraderItemCode(D2GameStrc* pGame, D2UnitStrc* pNpc, D2SeedStrc* pSeed, int nUnused, unsigned int* pCode, int* pIndex)
{
    int nIndex = *pIndex;
    int nNpcIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nNpcIndex);
    if (pNpcRecord)
    {
        D2NpcTradeDataStrc* pTrade = &pNpcRecord->tTrade;
        if (pTrade && pTrade->bTrader && pTrade->tProxy.nItems && pTrade->tProxy.pItemCache)
        {
            int nItemId = ITEMS_RollLimitedRandomNumber(pSeed, pTrade->tProxy.nItems);
            pSeed->lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;

            const int nRand = nItemId;
            DATATBLS_GetItemRecordFromItemCode(pTrade->tProxy.pItemCache[nRand].dwCode, &nItemId);
            ITEMS_CheckBitField1Flag1(nItemId);
            *pCode = pTrade->tProxy.pItemCache[nRand].dwCode;
            *pIndex = nIndex;
            return 1;
        }

        D2_ASSERT(pTrade, 899);
        D2_ASSERT(pTrade->bTrader, 900);
    }

    D2_ASSERT(pNpcRecord, 905);
    *pCode = 0;
    return 0;
}

// 0x00576D90
int __fastcall SUNITNPC_SpendGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nCost)
{
    const int nGold = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0);
    if (nGold + STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDBANK, 0) < nCost)
    {
        return 0;
    }

    if (nCost <= nGold)
    {
        PLRTRADE_AddGold(pPlayer, 14, -nCost);
        return 1;
    }

    PLRTRADE_AddGold(pPlayer, 14, -nGold);

    const int nValue = nGold - nCost;
    if (pPlayer)
    {
        const int nNewValue = nValue + STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDBANK, 0);
        if (nNewValue < 0)
        {
            STATLIST_SetUnitStat(pPlayer, STAT_GOLDBANK, 0, 0);
            return 1;
        }

        if (pPlayer->dwUnitType == UNIT_PLAYER && nNewValue > UNITS_GetStashGoldLimit(pPlayer))
        {
            STATLIST_SetUnitStat(pPlayer, STAT_GOLDBANK, 0, 0);
            return 1;
        }

        STATLIST_AddUnitStat(pPlayer, STAT_GOLDBANK, nValue, 0);
    }

    return 1;
}

// 0x00576E40
void __fastcall SUNITNPC_DecreaseSkillQuantity(D2UnitStrc* unit, int skillId, int decrement)
{
    if (skillId < 0) return;
    D2SkillStrc* skill = SKILLS_GetHighestLevelSkillFromUnitAndId(unit, skillId);
    if (!skill) return;
    int quantity = SKILLS_GetQuantity(skill) - decrement;
    if (quantity <= 0) {
        if (UNITS_GetRightSkill(unit) == skill) D2GAME_AssignSkill_6FD13800(unit, 0, SKILL_ATTACK, -1);
        quantity = 0;
    }
    SKILLS_SetQuantity(skill, quantity);
    int id, type;
    if (!unit) { id = -1; type = 6; }
    else { id = unit->dwUnitId; type = unit->dwUnitType; }
    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(unit, gszNpcSourceFile, 0x40b), (unsigned char)type, id, skillId, quantity);
}

// 0x00576ED0
bool __fastcall SUNITNPC_IsPermanentStoreItem(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        return false;
    }

    const int nCode = ITEMS_GetBaseCode(pItem);
    if (pGame->nDifficulty > DIFFMODE_NORMAL)
    {

        if (nCode == 0x20347068 || nCode == 0x20357068 || nCode == 0x2034706D || nCode == 0x2035706D)
        {
            return true;
        }
    }

    for (int i = 0; i < pNpcRecord->nPermStoreItems; ++i)
    {
        if (nCode == pNpcRecord->pPermStoreItems[i])
        {
            return true;
        }
    }

    return false;
}

// 0x00576F40
void __fastcall SUNITNPC_HandleGoldTransaction(D2GameStrc* game,D2UnitStrc* unit,unsigned int value) {
 ITEMS_HandleGoldTransaction(game,unit,value);
}

// 0x00576F50
void __fastcall SUNITNPC_RemovePurchasedItemFromStore(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a5)
{
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (pNpcRecord->bGambleInit && a5 == 2)
    {
        D2NpcGambleStrc* pNpcGamble = pNpcRecord->pGamble;
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        while (pNpcGamble)
        {
            if (pNpcGamble->dwGUID == nUnitGUID)
            {
                break;
            }

            pNpcGamble = pNpcGamble->pNext;
        }

        if (pNpcGamble && pNpcGamble->pInventory)
        {
            D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pNpcGamble->pInventory);
            while (pCurrent)
            {
                D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pCurrent);
                D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
                if (pCheck == pItem)
                {
                    SUNITNPC_AddGambleItem(pUnit, pNpc, pItem, pGame, 1);
                    return;
                }

                pCurrent = pNext;
            }
        }
    }

    if (!SUNITNPC_IsPermanentStoreItem(pGame, pNpc, pItem))
    {
        SUNITNPC_RemoveStoreItem(pNpc, pItem, pGame, 1);
    }
}

// 0x00577010
void __fastcall SUNITNPC_RefreshHirelingRoster(D2GameStrc* pGame, int nVendorId, D2NpcRecordStrc* pNpcRecord)
{
    D2MercDataStrc* pMercData = pNpcRecord->pMercData;
    int nAvailable = 0;
    int nFirst, nLast;
    const int nCount = SUNITNPC_GetHirelingNameRange(pGame, nVendorId, &nFirst, &nLast, 0);
    D2_ASSERT(nCount != -1, 0x632);
    for (int i = 0; i < nCount; ++i)
    {
        if (pMercData[i].bAvailable && !pMercData[i].bHired) ++nAvailable;
    }
    if (!nAvailable)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pNpcRecord->pMercData, gszNpcSourceFile, 0x63D, 0);
        pNpcRecord->pMercData = 0;
        pNpcRecord->bInitialized = 0;
        SUNITNPC_InitializeHirelingRoster(pGame, nVendorId, pNpcRecord);
    }
}

// 0x005770E0
void __fastcall SUNITNPC_HireMercenaryFromRoster(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, unsigned short wName)
{
    int nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    nLevel = SUNITNPC_CapStoreItemLevel(pGame, pNpc, nLevel);
    UNITS_GetPlayerData(pPlayer);

    if (pNpc)
    {
        if (pNpc->dwClassId == MONSTER_QUAL_KEHK)
        {
            D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestRecord, 0x24, 0))
            {
                D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x654), 0x2A, 0x0B, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
                return;
            }
        }

        if (pNpc->dwClassId == MONSTER_KASHYA && nLevel < 8)
        {
            D2BitBufferStrc* pQuestRecord = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestRecord, 2, 0))
            {
                D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x65F), 0x2A, 0x0B, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
                return;
            }
        }
    }

    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x66C), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    int nVendorId;
    if (!pNpc)
    {
        nVendorId = -1;
    }
    else
    {
        nVendorId = pNpc->dwClassId;
    }

    int nNameFirst;
    int nNameLast;
    int nClass;
    SUNITNPC_GetHirelingNamesAndClass(pGame, nVendorId, &nNameFirst, &nNameLast, &nClass);

    if (wName < nNameFirst || wName > nNameLast)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x685), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    D2MercDataStrc* pMercData = &pNpcRecord->pMercData[wName - nNameFirst];
    if (pMercData->nMercName != wName)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x693), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    if (pMercData->bHired)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x69A), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    D2HirelingInitStrc hirelingInit;
    const int nAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, pMercData->nMercName);
    const int nDifficulty = pGame->nDifficulty;
    if (!MONSTERS_HirelingInit(pGame->bExpansion, pPlayer, pMercData->dwSeed, nAct, nDifficulty, &hirelingInit))
    {
        return;
    }

    if (!SUNITNPC_SpendGold(pGame, pPlayer, hirelingInit.nGold))
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x6AE), 0x2A, 0x0C, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    D2UnitStrc* pMerc = MONSTERSPAWN_SpawnAtUnit(pGame, pNpc, nClass, 1, 4, 0);
    if (!pMerc)
    {
        pMerc = MONSTERSPAWN_SpawnAtUnit(pGame, pPlayer, nClass, 1, 4, 0);
        if (!pMerc)
        {
            D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x6BA), 0x2A, 0x0F, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
            return;
        }
    }

    pMercData->bHired = 1;
    MONSTERAI_AssignHireling(pGame, pPlayer, pMerc, -1, pMercData, 0);
    D2GAME_NPC_BuildHirelingList_6FCC6FF0(pGame, UnitGetClient(pPlayer, gszNpcSourceFile, 0x6C5), pNpc, MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pNpc)) <= 1);
    D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 0x6C6), 0x2A, 5, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), !pMerc ? -1 : pMerc->dwUnitId, 0);
    SUNITNPC_RefreshHirelingRoster(pGame, nVendorId, pNpcRecord);
}

// 0x005773D0
void __fastcall SUNITNPC_UpdateHirelingPosition(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (PLAYERPETS_GetFirstPetByType(pGame, pPlayer, PETTYPE_HIREABLE, 0))
    {
        sub_6FC7E310(pGame, pPlayer, UNITS_GetUnitXPosition(pPlayer), UNITS_GetUnitYPosition(pPlayer));
    }
}

// 0x005774F0
D2UnitStrc* __fastcall D2GAME_MERCS_Create_6FCC8630(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short wName, int nSeed, unsigned short wVersion, int nBaseMonster, int bDead)
{
    const int nMercAct = MONSTERS_GetActFromHirelingTxt(pGame->bExpansion, 0, wName);
    int nAct = pPlayer->nAct;
    if (UnitGetClient(pPlayer, gszNpcSourceFile, 0x735))
    {
        nAct = CLIENTS_GetActNo(UnitGetClient(pPlayer, gszNpcSourceFile, 0x737));
    }

    if (!pGame->bExpansion && (nMercAct < 0 || nAct != nMercAct))
    {
        return 0;
    }

    D2HirelingTxt* pHirelingTxtRecord;
    if (wVersion != 0xFFFF)
    {
        pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, wVersion, 1);
    }
    else
    {
        pHirelingTxtRecord = DATATBLS_GetNextHirelingTxtRecordFromActAndDifficulty(pGame->bExpansion, nMercAct, pGame->nDifficulty, 0);
    }

    if (!pHirelingTxtRecord)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x744);
        exit(-1);
    }

    const unsigned short wNameFirst = pHirelingTxtRecord->wNameFirst;
    const int nSeller = pHirelingTxtRecord->dwSeller;
    const int nNameFirst = wNameFirst;
    int nClassId = nBaseMonster;
    if (!nBaseMonster)
    {
        nClassId = pHirelingTxtRecord->dwClass;
    }

    if (wName < wNameFirst || wName > pHirelingTxtRecord->wNameLast)
    {
        wName = wNameFirst;
    }

    int nUnused;
    D2MercDataStrc* pMercData = SUNITPROXY_GetNpcRecordFromClassId(pGame, nSeller, &nUnused)->pMercData;
    if (pMercData)
    {
        pMercData += wName - nNameFirst;
        if (!pMercData->bAvailable)
        {
            pMercData->bHired = 1;
        }
    }

    D2UnitStrc* pMerc = SUNIT_AllocUnitData(1, nClassId, 0, 0, pGame, 0, 1, bDead ? 12 : 1, 0);
    if (!pMerc)
    {
        return 0;
    }

    D2MercDataStrc mercData;
    mercData.dwSeed = nSeed;
    mercData.nMercName = wName;
    MONSTERAI_AssignHireling(pGame, pPlayer, pMerc, wVersion, &mercData, bDead);
    return pMerc;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00577670
D2UnitStrc* __fastcall SUNITNPC_FindInventoryItemByClassId(D2UnitStrc* pUnit, int nClassId)
{
    if (pUnit->pInventory)
    {
        D2UnitStrc* pNext;
        for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = pNext)
        {
            D2UnitStrc* pCheck = INVENTORY_UnitIsItem(pItem);
            pNext = INVENTORY_GetNextItem(pItem);
            if ((!pCheck ? -1 : pCheck->dwClassId) == nClassId && !UNIT_HasFlagEx(pCheck, UNITFLAGEX_ITEMINIT))
            {
                return pCheck;
            }
        }
    }

    return 0;
}

void __stdcall sub_0055A2A0(D2UnitStrc* pUnit, int nArg); // 0x0055A2A0

// 0x005776E0
void __stdcall sub_005776E0(D2UnitStrc* pUnit)
{
    sub_0055A2A0(pUnit, 1);
}

// 0x00577700
D2UnitStrc* __fastcall SUNITNPC_FindStackForStorePurchase(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* a4)
{
    *a4 = 1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    if (!ITEMS_CheckIfStackable(pItem) || !ITEMS_GetAutoStack(pItem))
    {
        return 0;
    }

    D2UnitStrc* pStackItem = 0;
    int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
    while (1)
    {
        pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    int nQuantity = 0;
    while (1)
    {
        pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    *a4 = nMaxStack;
    return 0;
}

// 0x00577F30
int __fastcall D2GAME_NPC_BuyItemHandler_6FCC92A0(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nNpcUnitId, int nItemId, int nItemMode, int nTransactionType, int nCost, int bMultibuy)
{
    D2_ASSERT(ptGame, 2372);

    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(ptGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(ptGame, UNIT_MONSTER, nNpcUnitId);
    if (pNpc && pInteractUnit == pNpc)
    {
        return SUNITNPC_BuyItem(ptGame, pPlayer, pNpc, nItemId, nItemMode, nTransactionType, nCost, bMultibuy);
    }

    D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2380), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
    return 1;
}

D2UnitStrc* __fastcall sub_00577700_FindStack(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* a4)
{
    *a4 = 1;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    if (!ITEMS_CheckIfStackable(pItem) || !ITEMS_GetAutoStack(pItem))
    {
        return 0;
    }

    D2UnitStrc* pStackItem = 0;
    int nMaxStack = ITEMS_GetTotalMaxStack(pItem);
    while (1)
    {
        pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            const int nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    int nQuantity = 0;
    while (1)
    {
        pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
        if (!pStackItem)
        {
            break;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            nQuantity = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
            if (nQuantity < nMaxStack)
            {
                *a4 = nMaxStack - nQuantity;
                return pStackItem;
            }
        }
    }

    *a4 = nMaxStack;
    return 0;
}

// 0x00577830
int __fastcall SUNITNPC_BuyItem(D2GameStrc* ptGame,D2UnitStrc* pPlayer,D2UnitStrc* pNpc,int nItemGuid,int nItemMode,unsigned short nTransaction,int nQuotedCost,int bMultibuy)
{
    if(!ptGame){FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),2010);exit(-1);}
    D2UnitStrc* pItem=SUNIT_GetServerUnit(ptGame,4,nItemGuid);
    D2UnitStrc* pVendorItem=pItem;
    if(pItem)
    {
    int nTransactionType=nTransaction;
    if(nTransactionType==0)
    {
        if(!ITEMS_IsInPlayersInventory(pNpc,pItem,0)){SEND_GOLD(7,2039,nItemGuid,0);return 1;}
    }
    else if(nTransactionType==2)
    {
        D2InventoryStrc* pTrade=SUNITPROXY_GetGambleInventory(ptGame,pPlayer,pNpc);
        if(pTrade)
        {
            if(ITEMS_IsInPlayersInventory(pNpc,pItem,pTrade)!=1){SEND_GOLD(7,2053,nItemGuid,0);return 1;}
        }
        else {SEND_GOLD(7,2059,nItemGuid,0);return 1;}
    }
    int nNpcClass=!pNpc ? -1:pNpc->dwClassId;
    int nDifficulty=ptGame->nDifficulty;
    D2BitBufferStrc* pQuestFlags=UNITS_GetPlayerData(pPlayer)->pQuestData[nDifficulty];
    int nCost=ITEMS_GetTransactionCost(pPlayer,pItem,nDifficulty,pQuestFlags,nNpcClass,nTransaction);
    int nGold=STATLIST_UnitGetStatValue(pPlayer,STAT_GOLD,0);
    int nStashGold=STATLIST_UnitGetStatValue(pPlayer,STAT_GOLDBANK,0);
    if(nCost>(nGold+nStashGold)){SEND_GOLD(12,2085,-1,0);return 0;}
    D2InventoryStrc* pInventory=pPlayer->pInventory;
    if(INVENTORY_GetCursorItem(pInventory)){SEND_GOLD(7,2129,-1,0);return 1;}
    if(!SUNITNPC_IsPermanentStoreItem(ptGame,pNpc,pItem))bMultibuy=0;
    if(ITEMSIsA(pItem,22))
    {
        int nFree;
        D2UnitStrc* pBook=ITEMMODE_FindMatchingBookWithSpace(ptGame,pPlayer,pItem,&nFree);
        if(pBook)
        {
            int nCount=1;
            if(bMultibuy)
            {
                nCount=(unsigned int)(nGold+nStashGold)/(unsigned int)nCost;
                if(nCount>nFree)nCount=nFree;
            }
            if(!SUNITNPC_SpendGold(ptGame,pPlayer,nCount*nCost)){SEND_GOLD(12,2162,-1,0);return 0;}
            ITEMMODE_AddBookQuantity(ptGame,pPlayer,pBook,nCount);
            SUNITNPC_RemovePurchasedItemFromStore(ptGame,pNpc,pItem,pPlayer,nTransaction);
            SEND_GOLD(0,2171,!pBook ? -1 : pBook->dwUnitId,5);return 0;
        }
    }
    int nQuantity=STATLIST_UnitGetStatValue(pItem,STAT_QUANTITY,0);
    if(bMultibuy && ITEMS_GetAutoStack(pItem))
    {
        int nFree;
        int nOldQuantity=STATLIST_UnitGetStatValue(pItem,STAT_QUANTITY,0);
        STATLIST_SetUnitStat(pItem,STAT_QUANTITY,1,0);
        nCost=ITEMS_GetTransactionCost(pPlayer,pItem,ptGame->nDifficulty,sub_00543520(ptGame,pPlayer),!pNpc ? -1:pNpc->dwClassId,0);
        STATLIST_SetUnitStat(pItem,STAT_QUANTITY,nOldQuantity,0);
        int nAffordable=(unsigned int)(nGold+nStashGold)/(unsigned int)nCost;
        D2UnitStrc* pStack=sub_00577700_FindStack(ptGame,pPlayer,pItem,&nFree);
        int nCount=nFree<nAffordable ? nFree:nAffordable;
        if(pStack)
        {
            nCount=nFree<nAffordable ? nFree:nAffordable;
            if(nCount<=0){SEND_GOLD(12,2202,-1,0);return 0;}
            if(!SUNITNPC_SpendGold(ptGame,pPlayer,nCount*nCost)){SEND_GOLD(12,2207,-1,0);return 0;}
            SUNITNPC_RemovePurchasedItemFromStore(ptGame,pNpc,pItem,pPlayer,nTransaction);
            STATLIST_AddUnitStat(pStack,STAT_QUANTITY,nCount,0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer,gszNpcSourceFile,2214),pStack,1,70,STATLIST_UnitGetStatValue(pStack,STAT_QUANTITY,0),0);
            int nGuid=pStack->dwUnitId;
            SEND_GOLD(0,2216,nGuid,5);return 0;
        }
        nQuantity=nCount;
        if(nQuantity<=1)nQuantity=1;
        nCost=nQuantity*nCost;
    }
    int bPlaced=0;
    int bBought=0;
    if(!ITEMS_CheckIfAutoBeltable(pInventory,pItem))bMultibuy=0;
    while(1)
    {
        if(bBought && !bMultibuy)return 0;
        nGold=STATLIST_UnitGetStatValue(pPlayer,STAT_GOLD,0);
        int nBank=STATLIST_UnitGetStatValue(pPlayer,STAT_GOLDBANK,0);
        pItem=ITEMS_Duplicate(ptGame,pItem,pNpc,1);
        if(!pItem){SEND_GOLD(9,2249,-1,0);return 1;}
        if(bMultibuy && ITEMS_CheckIfStackable(pItem) && nQuantity)STATLIST_SetUnitStat(pItem,STAT_QUANTITY,nQuantity,0);
        if(!SUNITNPC_SpendGold(ptGame,pPlayer,nCost)){SEND_GOLD(12,2260,-1,0);return 0;}
        D2PlayerDataStrc* pPlayerData=UNITS_GetPlayerData(pPlayer);
        pPlayerData->dwBoughtItemId=!pItem ? -1 : pItem->dwUnitId;
        UNITS_ChangeAnimMode(pItem,4);
        int nItemClass=pItem->dwClassId;
        if(ITEMS_CheckIfAutoBeltable(pInventory,pItem))
        {
            int nBeltSlot;
            bPlaced=ITEMMODE_PlaceCursorItemInBelt(ptGame,pPlayer,!pItem ? -1 : pItem->dwUnitId,0,1,&nBeltSlot);
            if(!bPlaced)bMultibuy=0;
        }
        if(!bPlaced)
        {
            unsigned char bAutoEquip=1;
            D2UnitStrc* pWeapon=INVENTORY_GetLeftHandWeapon(pInventory);
            int nPlayerClass=UNITS_GetWeaponClass(pPlayer);
            if(nItemClass==gnSpecialItem1 && pWeapon && nPlayerClass!=7)bAutoEquip=0;
            if(nItemClass==gnSpecialItem2 && pWeapon && nPlayerClass!=1)bAutoEquip=0;
            if((pWeapon && ITEMSIsA(pItem,45)) || (!pWeapon && (nItemClass==gnSpecialItem1 || nItemClass==gnSpecialItem2)))goto inventory;
            if(bAutoEquip)
            {
                bPlaced=ITEMMODE_EquipItemAtResolvedBodyLocation(ptGame,pPlayer,pItem,0);
                if(bPlaced)goto placed;
            }
inventory:
            if(bBought)goto failed;
            ITEMS_SetInvPage(pItem,0);
            bPlaced=D2GAME_PlaceItem_6FC44410(gszNpcSourceFile,2316,ptGame,pPlayer,!pItem ? -1 : pItem->dwUnitId,0,0,1,1,0);
            if(!bPlaced)goto failed;
        }
placed:
        SUNITNPC_RemovePurchasedItemFromStore(ptGame,pNpc,pVendorItem,pPlayer,nTransaction);
        ITEMS_SetItemFlag(pItem,2,1);
        {
            int nGuid=!pItem ? -1 : pItem->dwUnitId;
            SEND_GOLD(0,2354,nGuid,4);
        }
        pItem=pVendorItem;
        bBought=1;
        continue;
failed:
        if(nGold-STATLIST_UnitGetStatValue(pPlayer,STAT_GOLD,0))PLRTRADE_AddGold(pPlayer,14,nGold-STATLIST_UnitGetStatValue(pPlayer,STAT_GOLD,0));
        if(nBank-STATLIST_UnitGetStatValue(pPlayer,STAT_GOLDBANK,0))PLRTRADE_AddGold(pPlayer,15,nBank-STATLIST_UnitGetStatValue(pPlayer,STAT_GOLDBANK,0));
        ITEMS_RemoveFromAllPlayers(ptGame,pItem);
        if(!bBought){SEND_GOLD(10,2332,-1,0);return 0;}
        return 0;
    }
    }
    SEND_GOLD(7,2016,nItemGuid,0);
    return 1;
}

// 0x00579C00
void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcUnitId);
    if (!pNpc || pInteractUnit != pNpc)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2397), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    switch ((unsigned int)pNpc->dwClassId)
    {
    case 150:
    case 198:
    case 252:
    case 367:
    case 515:
        break;
    default:
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2412), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    D2UnitStrc* pHireling = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 1);
    if (!pHireling)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2419), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    if (!SUNITNPC_SpendGold(pGame, pPlayer, MONSTERS_GetHirelingResurrectionCost(pHireling)))
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2452), 0x2A, 12, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    pHireling->dwFlags &= 0xFFFEFFFF;
    UNITS_ChangeAnimMode(pHireling, 1);
    STATLIST_SetUnitStat(pHireling, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pHireling), 0);
    SUNITNPC_ResurrectHireling(pGame, pPlayer, pHireling);
    D2GAME_PACKETS_SendPacket0x9B_6FC3FB30(UnitGetClient(pPlayer, gszNpcSourceFile, 2461), 0xFFFF, 0);
    const int nHirelingGUID = pHireling->dwUnitId;
    D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2462), 0x2A, 5, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), nHirelingGUID, 0);
}

// 0x00577FE0
void __fastcall D2GAME_NPC_HireMerc_6FCC9540(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int a4)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcUnitId);
    if (pNpc && pInteractUnit == pNpc)
    {
        SUNITNPC_HireMercenaryFromRoster(pGame, pPlayer, pNpc, a4);
    }
    else
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2477), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
    }
}

// 0x00578050
int __fastcall D2GAME_NPC_Repair_6FCC95B0(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nNpcGUID, int nItemGUID, unsigned short nUnused, int nRepairFlags)
{
    D2_ASSERT(ptGame, 0x9BC);

    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(ptGame, pUnit);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(ptGame, 1, nNpcGUID);
    if (!pNpc || pInteractUnit != pNpc)
    {
        SEND_0x2A(9, 0x9C5, 0);
        return 1;
    }

    if (pNpc->dwClassId != MONSTER_HALBU && pNpc->dwClassId != MONSTER_CHARSI && pNpc->dwClassId != MONSTER_FARA && pNpc->dwClassId != MONSTER_LARZUK && pNpc->dwClassId != MONSTER_HRATLI)
    {
        SEND_0x2A(9, 0x9D2, 0);
        return 1;
    }

    if (nRepairFlags & 0x80000000)
    {
        const int nDifficulty = ptGame->nDifficulty;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[nDifficulty];
        const int nNpcId = pNpc->dwClassId;
        const int nRepairCosts = ITEMS_GetAllRepairCosts(ptGame, pUnit, nNpcId, nDifficulty, pQuestFlags, 0);
        if (!nRepairCosts)
        {
            SEND_0x2A(2, 0x9DD, 1);
            return 0;
        }

        if (!SUNITNPC_SpendGold(ptGame, pUnit, nRepairCosts))
        {
            SEND_0x2A(12, 0x9E4, 0);
            return 1;
        }

        const int nNpcClassId = pNpc->dwClassId;
        ITEMS_GetAllRepairCosts(ptGame, pUnit, nNpcClassId, ptGame->nDifficulty, sub_00543520(ptGame, pUnit), SUNITNPC_RepairItemCallback);
        SEND_0x2A(2, 0x9E8, 1);
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem || !ITEMS_IsInPlayersInventory(pUnit, pItem, 0))
    {
        SEND_0x2A(9, 0x9F0, 0);
        return 3;
    }

    const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
    const int nDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
    if (!ITEMS_IsRepairable(pItem))
    {
        SEND_0x2A(9, 0xA05, 0);
        return 1;
    }

    {
        int nQuantity;
        if (!ITEMS_CheckIfStackable(pItem) || !ITEMS_CheckIfThrowable(pItem) || ITEMS_IsEthereal(pItem) || (nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0)) >= ITEMS_GetTotalMaxStack(pItem))
        {
            int bHasChargedSkills;
            if (!ITEMS_HasUsedCharges(pItem, &bHasChargedSkills) || bHasChargedSkills)
            {
                if (!nMaxDurability)
                {
                    goto lNotRepairable;
                }

                if (nDurability >= nMaxDurability)
                {
lNotRepairable:
                    SEND_0x2A(9, 0xA21, 0);
                    return 1;
                }
            }
        }
    }

    const int nVendorId = pNpc->dwClassId;
    const int nTransactionCosts = ITEMS_GetTransactionCost(pUnit, pItem, ptGame->nDifficulty, sub_00543520(ptGame, pUnit), nVendorId, 3);
    if (!SUNITNPC_SpendGold(ptGame, pUnit, nTransactionCosts))
    {
        const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
        if (nMaxDurability > nDurability)
        {
            const int nDivisor = ((unsigned int)nTransactionCosts << 10) / (unsigned int)(nMaxDurability - nDurability);
            if (nGold > 0 && nDivisor < nGold << 10 && nDivisor > 0)
            {
                const int nRepairDurability = (nGold << 10) / nDivisor;
                if (!ITEMS_CheckItemFlag(pItem, 0x100, 0xA43, gszNpcSourceFile))
                {
                    if (SUNITNPC_SpendGold(ptGame, pUnit, nGold))
                    {
                        const int nNewDurability = D2_MIN(nMaxDurability, nDurability + nRepairDurability);

                        STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nNewDurability, 0);
                        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, gszNpcSourceFile, 0xA4A), pItem, 1, 72, nNewDurability, 0);
                        SEND_0x2A(2, 0xA4B, 1);
                        return 0;
                    }
                }
            }

            SEND_0x2A(12, 0xA50, 0);
            return 0;
        }

        SEND_0x2A(12, 0xA54, 0);
        return 0;
    }

    D2GAME_NPC_RepairItem_6FCC6970(ptGame, pItem, pUnit);
    SEND_0x2A(2, 0xA5C, 1);
    return 0;
}

// 0x00578460
void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pPlayer);
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcGUID);
    if (!pNpc || pInteractUnit != pNpc)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2669), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        return;
    }

    switch ((unsigned int)pNpc->dwClassId)
    {
    case 244:
    case 245:
    case 246:
    case 265:
    case 520:
    {
        const int nUnidentifiedItems = ITEMS_GetNoOfUnidItems(pPlayer);
        if (!nUnidentifiedItems)
        {
            D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2689), 0x2A, 9, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
            return;
        }

        if (QUESTRECORD_GetQuestState(sub_00578460_GetQuestRecord(pGame, pPlayer), 4, 0) != 1
            && QUESTRECORD_GetQuestState(sub_00578460_GetQuestRecord(pGame, pPlayer), 4, 1) != 1)
        {
            if (!SUNITNPC_SpendGold(pGame, pPlayer, 100 * nUnidentifiedItems))
            {
                D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2704), 0x2A, 12, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
                return;
            }
        }

        D2UnitStrc* pNext;
        for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pPlayer->pInventory); pNode; pNode = pNext)
        {
            pNext = INVENTORY_GetNextItem(pNode);
            const int nPage = INVENTORY_GetItemNodePage(pNode);
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
            if ((nPage == 1 && (ITEMS_GetInvPage(pItem) == 0 || ITEMS_GetInvPage(pItem) == 3)) || nPage == 3)
            {
                if (!ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 2721, gszNpcSourceFile))
                {
                    D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
                }
            }
        }

        D2GAME_SendPacket0x2A(UnitGetClient(pPlayer, gszNpcSourceFile, 2730), 0x2A, 3, STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0), -1, 0);
        break;
    }
    default:
        break;
    }
}

// 0x00578610
static int __stdcall SUNITNPC_IsCursorItem(unsigned int nItemGUID, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
        if (pItem)
        {
            const unsigned int nId = (pItem ? pItem->dwUnitId : -1);
            if (nId == nItemGUID)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00578640
void __fastcall D2GAME_NPC_IdentifyBoughtItem_6FCCA990(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    const int nGUID = nItemGUID;
    if (pPlayerData->dwBoughtItemId != nGUID)
    {
        return;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nGUID);
    if (!pItem || ITEMS_CheckItemFlag(pItem, 0x10, 0xD1F, gszNpcSourceFile))
    {
        return;
    }

    D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
}

// 0x005786A0
static int __stdcall SUNITNPC_RollGambleUpgrade(int nItemId, int nUberChance, int nUltraChance, D2GameStrc* pGame, int nItemLevel)
{
    if (!pGame->bExpansion)
    {
        return nItemId;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return nItemId;
    }

    D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
    const unsigned int dwUltraCode = pItemsTxtRecord->dwUltraCode;
    int nUltraItemId;
    if (pItemsTxtRecord->dwUberCode != 0x20202020 && pItemsTxtRecord->dwUberCode)
    {
        int nUberItemId;
        D2ItemsTxt* pUberItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemsTxtRecord->dwUberCode, &nUberItemId);
        if (pUberItemsTxtRecord)
        {
            const int nUberItemChance = (nItemLevel - pUberItemsTxtRecord->nLevel) * nUberChance + 1;
            if (nUberItemChance > 0)
            {
                if ((int)ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUberItemChance)
                {
                    return nUberItemId;
                }

                if (pItemsTxtRecord->dwUltraCode != 0x20202020 && pItemsTxtRecord->dwUltraCode)
                {
                    D2ItemsTxt* pUltraItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(dwUltraCode, &nUltraItemId);
                    if (pUltraItemsTxtRecord)
                    {
                        const int nUltraItemChance = (nItemLevel - pUltraItemsTxtRecord->nLevel) * nUltraChance + 1;
                        if (nUltraItemChance > 0 && (int)ITEMS_RollLimitedRandomNumber(pSeed, 10000) < nUltraItemChance)
                        {
                            return nUltraItemId;
                        }
                    }
                }
            }
        }
    }

    return nItemId;
}

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
 const unsigned __int64 n = pSeed->nHighSeed + 0x6AC690C5i64*pSeed->nLowSeed;
 pSeed->nHighSeed=(unsigned int)(n>>32); pSeed->nLowSeed=(unsigned int)n; return (unsigned int)n;
}

static inline unsigned int RollLimited(D2SeedStrc* pSeed,int nMax)
{
 if(nMax<=0) return 0;
 if(nMax & (nMax-1)) return RollSeed(pSeed)%(unsigned int)nMax;
 return RollSeed(pSeed)&(nMax-1);
}

static inline int UnitX(D2UnitStrc* pUnit)
{
 switch(pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; default: return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0; }
}

static inline int UnitY(D2UnitStrc* pUnit)
{
 switch(pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; default: return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0; }
}

// 0x00578790
void __fastcall D2GAME_STORES_FillGamble_6FCCA9F0(D2GameStrc* pGame,D2UnitStrc* pNpc,D2UnitStrc* pPlayer,D2NpcRecordStrc* pNpcRecord)
{
 D2GambleDataTbl* pGamble = DATATBLS_GetGambleDataTables();
 if(!pGamble) return;
 D2DifficultyLevelsTxt* pDifficulty = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
 if(!pDifficulty) return;
 int nQualityChance = DIFFICULTY_GAMBLE(pDifficulty)->nGambleRare+DIFFICULTY_GAMBLE(pDifficulty)->nGambleSet+DIFFICULTY_GAMBLE(pDifficulty)->nGambleUnique;
 if(!gnRingId) DATATBLS_GetItemRecordFromItemCode(0x206E6972,&gnRingId);
 if(!gnAmuletId) DATATBLS_GetItemRecordFromItemCode(0x20756D61,&gnAmuletId);
 D2NpcGambleStrc* pNpcGamble = (D2NpcGambleStrc*)FOG_AllocPool(pGame->pMemoryPool,sizeof(D2NpcGambleStrc),gszNpcSourceFile,0xD94,0);
 if(!pNpcGamble) return;
 pNpcGamble->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool,0);
 pNpcGamble->dwGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
 pNpcGamble->pNext = pNpcRecord->pGamble;
 pNpcRecord->pGamble = pNpcGamble;
 int nPlayerLevel = STATLIST_UnitGetStatValue(pPlayer,STAT_LEVEL,0);
 D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
 for(int nItems = 0; nItems < 14;)
 {
  int nItemLevel = (int)(RollSeed(pSeed)%10)+nPlayerLevel-5;
  nItemLevel=D2_MIN(D2_MAX(nItemLevel,5),99);
  int nItemId = pGamble->pGambleSelection[RollLimited(pSeed,pGamble->pGambleChooseLimit[nItemLevel])];
  if(!pGame->bExpansion)
  {
   D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nItemId);
   if(!pItemsTxt) return;
   if(pItemsTxt->wVersion>=100) continue;
  }
  if(nItems<2)
  {
   nItemId=gnRingId;
   if(nItems) nItemId=gnAmuletId;
  }
  nItemId = SUNITNPC_RollGambleUpgrade(nItemId,DIFFICULTY_GAMBLE(pDifficulty)->nGambleUber,DIFFICULTY_GAMBLE(pDifficulty)->nGambleUltra,pGame,nItemLevel);
  int nQuality = 4;
  if(nQualityChance>0)
  {
   int nRoll=(int)(RollSeed(pSeed)%100000);
   if(nRoll<nQualityChance)
   {
    if(nRoll<DIFFICULTY_GAMBLE(pDifficulty)->nGambleUnique) nQuality=7;
    else if(nRoll<DIFFICULTY_GAMBLE(pDifficulty)->nGambleUnique+DIFFICULTY_GAMBLE(pDifficulty)->nGambleSet) nQuality=5;
    else nQuality=6;
   }
  }
  ++nItems;
  D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pNpc,nItemId,pGame,4,nQuality,0,1,nItemLevel,0,0,0);
  if(!pItem) continue;
  {
   ITEMS_SetInvPage(pItem,0);
   D2GAME_NPC_RepairItem_6FCC6970(pGame,pItem,0);
   ITEMS_SetItemFlag(pItem,16,0);
   const int nY = UnitY(pItem);
   const int nX = UnitX(pItem);
   const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
   if(!sub_00560200_PlaceItem(gszNpcSourceFile,0xDE4,pGame,pNpc,nItemGUID,nX,nY,1,0,pNpcGamble->pInventory))
   {
    ITEMS_RemoveFromAllPlayers(pGame,pItem);
    return;
   }
  }
 }
}

// 0x00578C20
int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit)
{
    int bStateRemoved = 0;
    for (int nState = 0; nState < sgptDataTables->nStatesTxtRecordCount; ++nState)
    {
        if (STATES_CheckState(pUnit, nState) && STATES_CheckStateMaskCurableByStateId(nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
                bStateRemoved = 1;
            }
        }
    }

    return bStateRemoved;
}

// 0x00578CA0
void __fastcall SUNITNPC_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, void* a4)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nHitpoints < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
        *(unsigned char*)a4 = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pUnit))
    {
        *(unsigned char*)a4 = 1;
    }

    D2StatListStrc* pStatListPoison = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_POISON);
    if (pStatListPoison)
    {
        D2Common_10474(pUnit, pStatListPoison);
        STATLIST_FreeStatList(pStatListPoison);
        *(unsigned char*)a4 = 1;
    }

    D2StatListStrc* pStatListFreeze = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_FREEZE);
    if (pStatListFreeze)
    {
        D2Common_10474(pUnit, pStatListFreeze);
        STATLIST_FreeStatList(pStatListFreeze);
        *(unsigned char*)a4 = 1;
    }
}

// 0x00578D30
void __fastcall D2GAME_NPC_HealPlayer_6FCCB080(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc)
{
    if (SUNIT_GetInteractUnit(pGame, pUnit) != pNpc)
    {
        return;
    }

    int bPlaySound = 0;

    const unsigned int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_HITPOINTS, nMaxHp, pUnit);
        bPlaySound = 1;
    }

    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < nMaxMana)
    {
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_MANA, nMaxMana, pUnit);
        bPlaySound = 1;
    }

    const unsigned int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) < nMaxStamina)
    {
        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
        D2GAME_UpdateAttribute_6FC822D0(pUnit, STAT_STAMINA, nMaxStamina, pUnit);
        bPlaySound = 1;
    }

    D2StatListStrc* pStatListPoison = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_POISON);
    if (pStatListPoison)
    {
        D2Common_10474(pUnit, pStatListPoison);
        STATLIST_FreeStatList(pStatListPoison);
        bPlaySound = 1;
    }

    D2StatListStrc* pStatListFreeze = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_FREEZE);
    if (pStatListFreeze)
    {
        D2Common_10474(pUnit, pStatListFreeze);
        STATLIST_FreeStatList(pStatListFreeze);
        bPlaySound = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pUnit))
    {
        bPlaySound = 1;
    }

    PLAYERPETS_IteratePets(pGame, pUnit, SUNITNPC_PetIterate_Heal, &bPlaySound);

    if (bPlaySound == 1)
    {
        SUNIT_AttachSound(pNpc, 10, 0);
    }
}

// 0x00578E70
void __fastcall D2GAME_NPC_Heal_6FCCB220(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc)
{
    const int nGUID = !pNpc ? -1 : pNpc->dwUnitId;

    gnNpcGUID = nGUID;
    if (pNpc)
    {
        const int nClass = pNpc->dwClassId;
        if (nClass == 148 || nClass == 513 || nClass == 176 || nClass == 178 || nClass == 405 || nClass == 255)
        {
            D2GAME_NPC_HealPlayer_6FCCB080(pGame, pUnit, pNpc);
        }
    }
}

// 0x00578ED0
void __fastcall D2GAME_NPC_PurchaseHeal_6FCCB280(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID)
{
    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, 1, nNpcGUID);
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
    if (!pNpc || pInteractUnit != pNpc)
    {
        return;
    }

    int nStatRestored = 0;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) != nMaxHp)
    {
        nStatRestored = 1;
    }

    unsigned int nHealingCost = UNITS_GetHealingCost(pUnit);
    if (!nHealingCost)
    {
        nHealingCost = 1;
    }

    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) != nMaxMana)
    {
        nStatRestored = 1;
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) == nMaxStamina && !nStatRestored)
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3848), 0x2A, 14, STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0), -1, 0);
        return;
    }

    if (STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) + STATLIST_UnitGetStatValue(pUnit, STAT_GOLDBANK, 0) >= nHealingCost)
    {
        if (!SUNITNPC_SpendGold(pGame, pUnit, nHealingCost))
        {
            D2GAME_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3861), 0x2A, 9, STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0), -1, 0);
            return;
        }

        D2GAME_NPC_HealPlayer_6FCCB080(pGame, pUnit, pNpc);
        D2GAME_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3874), 0x2A, 6, STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0), -1, 0);
    }
    else
    {
        D2GAME_SendPacket0x2A(UnitGetClient(pUnit, gszNpcSourceFile, 3868), 0x2A, 12, STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0), -1, 0);
    }
}

// 0x00579030
int __fastcall SUNITNPC_RollTraderItems(D2GameStrc* pGame, D2UnitStrc* pNpc, int nArg, int nArg2)
{
    D2SeedStrc* pSeed = SUNITPROXY_GetSeedFromNpcControl(pGame);
    int i = 0;
    const int nStockLevel = SUNITNPC_CapStoreItemLevel(pGame, pNpc, nArg);
    unsigned int nItemCode;
    while ((i < 5 ? SUNITNPC_RollTraderItemCode(pGame, pNpc, pSeed, nStockLevel, &nItemCode, &nArg2) : 0) != 0)
        ++i;
    return 0;
}

// 0x00579180
void __fastcall D2GAME_NPC_AssignMercenary(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nVendorId)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, nVendorId, &nIndex);
    if (!pNpcRecord)
    {
        return;
    }

    D2MercDataStrc* pMercData = pNpcRecord->pMercData;
    if (!pMercData)
    {
        return;
    }

    if (pGame->bExpansion)
    {
        if (PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 1))
        {
            SUNITNPC_RefreshHirelingRoster(pGame, nVendorId, pNpcRecord);
            return;
        }
    }

    if (!pGame->bExpansion)
    {
        if (PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 0))
        {
            return;
        }
    }

    D2HirelingTxt* pHirelingTxt = DATATBLS_GetNextHirelingTxtRecordFromVendorIdAndDifficulty(pGame->bExpansion, nVendorId, pGame->nDifficulty, 0);
    if (!pHirelingTxt)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xFA2);
        exit(-1);
    }

    const int nNameLast = pHirelingTxt->wNameLast;
    const int nNameFirst = pHirelingTxt->wNameFirst;
    const int nClass = pHirelingTxt->dwClass;
    const int nCount = nNameLast - nNameFirst + 1;
    int nName = nNameFirst;
    while (nName <= nNameLast)
    {
        const int nIdx = nName - nNameFirst;
        if (nIdx >= nCount)
        {
            break;
        }

        if (pMercData[nIdx].bHired == 1)
        {
            ++nName;
            continue;
        }

        if (pMercData[nIdx].bAvailable == 1)
        {
            D2GSPacketSrv50 packet50;
            packet50.nHeader = 0x50;
            packet50.nQuestId = 2;
            packet50.nParams[0] = pMercData[nIdx].nMercName;
            pMercData[nIdx].bHired = 1;
            D2GAME_SendPacket0x50_6FC3F440(UnitGetClient(pPlayer, gszNpcSourceFile, 0xFC7), &packet50);

            D2UnitStrc* pUnit = MONSTERSPAWN_SpawnAtUnit(pGame, pPlayer, nClass, 1, 4, 0);
            if (!pUnit)
            {
                pUnit = MONSTERSPAWN_SpawnAtUnit(pGame, pPlayer, nClass, 1, 6, 0);
                if (!pUnit)
                {
                    pUnit = MONSTERSPAWN_SpawnAtUnit(pGame, pPlayer, nClass, 1, 0x0C, 0);
                    if (!pUnit)
                    {
                        return;
                    }
                }
            }

            MONSTERAI_AssignHireling(pGame, pPlayer, pUnit, -1, &pMercData[nIdx], 0);
            break;
        }

        ++nName;
    }

    SUNITNPC_RefreshHirelingRoster(pGame, nVendorId, pNpcRecord);
}

// 0x00579360
int __fastcall D2GAME_NPC_IsItemInNpcInventory_6FCCB7D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2UnitStrc* pItem, int a4)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nIndex);
    if (pNpcRecord)
    {
        D2NpcVendorChainStrc* pNpcVendorChain = SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer);
        const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
        if (pNpcVendorChain && pNpcVendorChain->bGamble)
        {
            if (!a4)
            {
                for (D2NpcGambleStrc* pGamble = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &a4)->pGamble; pGamble; pGamble = pGamble->pNext)
                {
                    if (pGamble->dwGUID == nPlayerGUID)
                    {
                        for (D2UnitStrc* pInventoryItem = INVENTORY_GetFirstItem(pGamble->pInventory); pInventoryItem; pInventoryItem = INVENTORY_GetNextItem(pInventoryItem))
                        {
                            if (INVENTORY_UnitIsItem(pInventoryItem) == pItem)
                            {
                                return 1;
                            }
                        }
                        break;
                    }
                }
                return 0;
            }
        }
        else if (!ITEMS_CheckItemFlag(pItem, 0x10, 4109, gszNpcSourceFile))
        {
            return 0;
        }
    }
    return 1;
}

static inline D2NpcTradeDataStrc* SUNITNPC_GetNpcTrade(D2NpcRecordStrc* pNpcRecord)
{
    if (pNpcRecord)
    {
        return &pNpcRecord->tTrade;
    }

    return 0;
}

// 0x00579430
void __fastcall D2GAME_STORES_CreateVendorCache(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC, int bRefreshInventory, int bGamble)
{
    if (!pNPC)
    {
        return;
    }

    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNPC, &nUnused);
    if (!pNpcRecord)
    {
        return;
    }

    pNpcRecord->bTrading = 1;
    pNpcRecord->dwNPCGUID = UNITS_GetUnitGUIDInline(pNPC);
    D2GAME_STORES_FillVendorCache(pGame, pPlayer, pNPC, bGamble);

    const int nClassId = pNPC->dwClassId;
    if (nClassId == NPC_CLASS_150 || nClassId == NPC_CLASS_515 || nClassId == NPC_CLASS_198)
    {
        return;
    }

    if (bRefreshInventory && !bGamble)
    {
        D2NpcTradeDataStrc* pTrade = &pNpcRecord->tTrade;
        if (pTrade->bRefreshInventory)
        {
            pTrade->bRefreshInventory = 0;
            SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, pNPC);
            D2GAME_NPC_FillStoreInventory_6FCC7100(pGame, pPlayer, pNPC, pTrade);
            pTrade->bVendorInit = 1;
        }
    }

    UNITS_RefreshInventory(pNPC, 1);
    if (!bGamble)
    {
        SUNITNPC_AddItemsToTrade(pNPC, pNPC->pInventory);
    }
    else
    {
        D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNPC);
        if (pGambleInventory)
        {
            SUNITNPC_AddItemsToTrade(pNPC, pGambleInventory);
        }
    }
}

// 0x00578B30
void __fastcall D2GAME_STORES_FillVendorCache(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, int bGamble)
{
    if (!pNpc)
    {
        return;
    }

    const int nNpcClassId = pNpc->dwClassId;
    int nUnused;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nUnused);
    if (!pNpcRecord)
    {
        return;
    }

    if (bGamble)
    {
        if (pNpcRecord->bGambleInit)
        {
            SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer)->bGamble = 1;
            SUNITNPC_FillGambleIfMissing(pGame, pNpc, pPlayer, pNpcRecord);
        }
    }
    else
    {
        D2NpcTradeDataStrc* pTrade = &pNpcRecord->tTrade;
        if (pTrade && pTrade->bTrader)
        {
            SUNITPROXY_GetVendorChain(pGame, pNpcRecord, pPlayer)->bGamble = 0;
            if (!pTrade->bVendorInit)
            {
                D2GAME_NPC_FillStoreInventory_6FCC7100(pGame, pPlayer, pNpc, pTrade);
                pTrade->bVendorInit = 1;
            }

            if (!pTrade->bHireInit)
            {
                if (nNpcClassId == MONSTER_KASHYA || nNpcClassId == MONSTER_QUAL_KEHK || nNpcClassId == MONSTER_GREIZ || nNpcClassId == MONSTER_ASHEARA)
                {
                    SUNITNPC_InitializeHirelingRoster(pGame, nNpcClassId, pNpcRecord);
                }
                pTrade->bHireInit = 1;
            }
        }
    }
}

// 0x00578AE0
void __fastcall SUNITNPC_FillGambleIfMissing(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2NpcRecordStrc* pNpcRecord)
{
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    int bHasGamble = 0;
    for (D2NpcGambleStrc* pNpcGamble = pNpcRecord->pGamble; pNpcGamble; pNpcGamble = pNpcGamble->pNext)
    {
        if (pNpcGamble->dwGUID == nPlayerGUID)
        {
            bHasGamble = 1;
        }
    }

    if (!bHasGamble)
    {
        D2GAME_STORES_FillGamble_6FCCA9F0(pGame, pNpc, pPlayer, pNpcRecord);
    }
}

// 0x00579090
void __fastcall SUNITNPC_RefillNpcStore(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (!gnNpcGUID)
    {
        return;
    }

    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, gnNpcGUID);
    if (!pNpc)
    {
        return;
    }

    int bHasInteractUnit;
    if (pNpc->dwUnitType == UNIT_MONSTER && pNpc->pMonsterData)
    {
        bHasInteractUnit = MONSTERAI_HasInteractUnit(pNpc->pMonsterData->pMonInteract);
    }
    else
    {
        bHasInteractUnit = MONSTERAI_HasInteractUnit(0);
    }

    if (bHasInteractUnit == 1)
    {
        return;
    }

    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromUnit(pGame, pNpc, &nIndex);
    D2InventoryStrc* pInventory = pNpc->pInventory;
    if (pInventory)
    {
        INVENTORY_RemoveInventoryItems(pInventory);
        D2COMMON_10251_Return(pInventory);
    }

    D2NpcTradeDataStrc* pTrade = SUNITNPC_GetNpcTrade(pNpcRecord);
    if (pTrade && pTrade->bTrader)
    {
        pTrade->bVendorInit = 0;
        // volatile only makes these two reloads come from the stack copies of the register parameters, as the original does
        D2UnitStrc* const pStorePlayer = *(D2UnitStrc* volatile*)&pPlayer;
        D2GameStrc* const pStoreGame = *(D2GameStrc* volatile*)&pGame;
        D2GAME_NPC_FillStoreInventory_6FCC7100(pStoreGame, pStorePlayer, pNpc, pTrade);
        pTrade->bVendorInit = 1;
    }
}

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract); // 0x00572E00

// 0x00579130
void __fastcall D2GAME_NPC_ResetInteract_6FCCB4D0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc)
{
    SUNIT_ResetInteractInfo(pPlayer);
    MONSTERAI_RemoveInteractInfoFor(pGame, pPlayer, (pNpc && pNpc->dwUnitType == UNIT_MONSTER && pNpc->pMonsterData) ? pNpc->pMonsterData->pMonInteract : 0);
}

static inline int GetId(D2UnitStrc* u){ if(u) return u->dwUnitId; return -1; }

// 0x00579510
int __fastcall D2GAME_STORES_SellItem_6FCC7680(D2GameStrc* ptGame,D2UnitStrc* player,int npcId,int itemId,unsigned short itemMode,int unused)
{
    if (!ptGame) { FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x4AE); exit(-1); }
    D2UnitStrc* interact=SUNIT_GetInteractUnit(ptGame,player);
    D2UnitStrc* npc=SUNIT_GetServerUnit(ptGame,1,npcId);
    D2UnitStrc* item=SUNIT_GetServerUnit(ptGame,4,itemId);
    if (!item) return 1;
    if (!npc || interact!=npc) { SEND_ERROR(9,0x4B9); return 1; }
    if (!ITEMS_IsInPlayersInventory(player,item,0)) { SEND_ERROR(11,0x4C2); return 3; }
    if (GetMode(item)==itemMode) {
    if (!ITEMS_IsNotQuestItem(item)) { SEND_ERROR(9,0x4DE); return 3; }
    const int vendorId=npc->dwClassId;
    int price=ITEMS_GetTransactionCost(player,item,ptGame->nDifficulty,sub_00543520(ptGame,player),vendorId,1);
    int keep=1;
    if (ITEMS_GetItemQuality(item)==ITEMQUAL_INFERIOR) { const char* name=DATATBLS_GetLowQualityItemsTxtRecord(ITEMS_GetFileIndex(item))->name; if (!_stricmp(name,"Cracked")) keep=0; }
    if (ITEMS_CheckItemFlag(item,0x100,0x505,gszNpcSourceFile)) keep=0;
    if (ITEMS_GetItemType(item)==ITEMTYPE_PLAYER_BODY_PART) keep=0;
    if (ITEMS_CheckItemFlag(item,0x1000000,0x50D,gszNpcSourceFile)) keep=0;
    if (ITEMS_CheckItemFlag(item,0x400000,0x511,gszNpcSourceFile)) keep=0;
    if (D2GAME_CheckHasFilledSockets(item,gszNpcSourceFile,0x513)) keep=0;
    if (SUNITNPC_IsUniqueCarryOneItem(item)) keep=0;
    int npcIndex;
    D2NpcRecordStrc* npcRecord=SUNITPROXY_GetNpcRecordFromUnit(ptGame,npc,&npcIndex);
    if (SUNITPROXY_GetVendorChain(ptGame,npcRecord,player)->bGamble) keep=0;
    D2UnitStrc* copy=0;
    if (keep && !SUNITNPC_IsPermanentStoreItem(ptGame,npc,item)) {
        copy=ITEMS_Duplicate(ptGame,item,npc,1);
        if (!copy) { SEND_ERROR(9,0x546); return 3; }
        UNITS_ChangeAnimMode(copy,4);
        unsigned char page=ITEMS_GetStorePage(copy);
        if (page==255) { ITEMS_RemoveFromAllPlayers(ptGame,copy); copy=0; }
        else {
            ITEMS_SetInvPage(copy,page);
            const int copyId=GetId(copy);
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile,0x558,ptGame,npc,copyId,CLIENTS_GetUnitX(copy),CLIENTS_GetUnitY(copy),1,1,0)) {
                if (page==1) {
                    ITEMS_SetInvPage(copy,2);
                    const int copyId=GetId(copy);
                    if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile,0x55E,ptGame,npc,copyId,CLIENTS_GetUnitX(copy),CLIENTS_GetUnitY(copy),1,1,0)) ITEMS_RemoveFromAllPlayers(ptGame,copy);
                    else {
                        SUNITNPC_SetItemTradeFlags(npc,copy,ptGame,1,1);
                        const int durability=STATLIST_GetMaxDurabilityFromUnit(copy);
                        STATLIST_SetUnitStat(copy,STAT_DURABILITY,durability,0);
                        const int quantity=ITEMS_GetTotalMaxStack(copy);
                        STATLIST_SetUnitStat(copy,STAT_QUANTITY,quantity,0);
                        const int vendorId=npc->dwClassId;
                        int newPrice=ITEMS_GetTransactionCost(player,copy,ptGame->nDifficulty,sub_00543520(ptGame,player),vendorId,1);
                        if (price>newPrice) price=newPrice;
                    }
                }
                else ITEMS_RemoveFromAllPlayers(ptGame,copy);
            }
            else {
                SUNITNPC_SetItemTradeFlags(npc,copy,ptGame,1,1);
                const int durability=STATLIST_GetMaxDurabilityFromUnit(copy);
                        STATLIST_SetUnitStat(copy,STAT_DURABILITY,durability,0);
                const int quantity=ITEMS_GetTotalMaxStack(copy);
                        STATLIST_SetUnitStat(copy,STAT_QUANTITY,quantity,0);
                const int vendorId=npc->dwClassId;
                        int newPrice=ITEMS_GetTransactionCost(player,copy,ptGame->nDifficulty,sub_00543520(ptGame,player),vendorId,1);
                if (price>newPrice) price=newPrice;
            }
        }
    }
    if (itemMode==0) {
        if (ITEMSIsA(item,22)) SUNITNPC_DecreaseSkillQuantity(player,DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(item,0))->dwScrollSkillId,1);
        else if (ITEMSIsA(item,18)) {
            int quantity=STATLIST_UnitGetStatValue(item,STAT_QUANTITY,0);
            if (quantity>=0) SUNITNPC_DecreaseSkillQuantity(player,DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(item,0))->dwBookSkillId,quantity);
        }
        D2ClientStrc* client=UnitGetClient(player,gszNpcSourceFile,0x594);
        int flags=0;
        ITEMS_SetOrRemoveFlag(&flags,0x20,1);
        ITEMS_SetItemCell(item,ITEMS_GetInvPage(item));
        D2GAME_UpdateClientItem_6FC3E9D0(client,player,item,flags);
        D2GAME_RemoveItem(ptGame,player,item,0);
    }
    else if (itemMode==4) {
        if (!D2GAME_RemoveItemIfOnCursor_6FC49760(ptGame,player,item)) { SEND_ERROR(9,0x59F); return 1; }
    }
    else {
        int flag;
        if (!ITEMMODE_UnequipBodyItem(ptGame,player,ITEMS_GetBodyLocation(item),1,&flag)) {
            if (copy) ITEMS_RemoveFromAllPlayers(ptGame,copy);
            return 1;
        }
    }
    ITEMS_HandleGoldTransaction(ptGame,player,price);
    D2GAME_SendPacket0x2A(UnitGetClient(player,gszNpcSourceFile,0x5BD),0x2A,1,STATLIST_UnitGetStatValue(player,STAT_GOLD,0),itemId,3);
    return 0;
    }
    SEND_ERROR(9,0x4C7);
    return 3;
}

static inline int GetX(D2UnitStrc* unit) {
 switch(unit->dwUnitType) { case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return unit->pStaticPath->nXPos; }
 return unit->pDynamicPath?PATH_GetXPosition(unit->pDynamicPath):0;
}

static inline int GetY(D2UnitStrc* unit) {
 switch(unit->dwUnitType) { case UNIT_OBJECT:case UNIT_ITEM:case UNIT_TILE:return unit->pStaticPath->nYPos; }
 return unit->pDynamicPath?PATH_GetYPosition(unit->pDynamicPath):0;
}

static __forceinline void RemoveExistingPet(D2GameStrc* game,D2UnitStrc* player)
{
 D2UnitStrc* old=PLAYERPETS_GetFirstPetByType(game,player,7,0);
 if(old) {
  AIGENERAL_SetOwnerData(game,old,-1,1,0,0);
  PLAYERPETS_RemovePet(game,player,GetId(old),0);
  DUNGEON_AllocDrlgDelete(UNITS_GetRoom(old),1,GetId(old));
  SUNIT_RemoveUnit(game,old);
 }
}

// 0x00579AA0
void __fastcall SUNITNPC_ResurrectHireling(D2GameStrc* game,D2UnitStrc* player,D2UnitStrc* pet)
{
 if(!pet || !player) return;
 RemoveExistingPet(game,player);
 UNITS_ChangeAnimMode(pet,1);
 STATLIST_SetUnitStat(pet,STAT_HITPOINTS,STATLIST_GetMaxLifeFromUnit(pet),0);
 PLAYERPETS_MarkPetAlive(game,player,pet);
 sub_005B1900_InitAi(game,pet,0,player->dwNodeIndex);
 STATES_ToggleState(pet,1,0);
 STATES_ToggleState(pet,107,0);
 STATES_ToggleState(pet,154,0);
 pet->dwFlags|=0x402000E;
 pet->dwFlagEx&=~0x40000;
 SUNITNPC_RelinkItemStatLists(pet);
 PLAYERPETS_UpdatePetsForOwnerMove(game,player,GetX(player),GetY(player));
 MONSTERAI_SendMercStats(game,player,0);
}

// 0x00577470
int __fastcall SUNITNPC_RelinkItemStatLists(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pNext;
    for (D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory); pCurrent; pCurrent = pNext)
    {
        pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        int bStatNotDynamic = 0;
        if (pItem && pItem->dwUnitType == UNIT_ITEM && STATLIST_GetOwner(pItem, &bStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            STATLIST_MergeStatLists(pUnit, pItem, bStatNotDynamic);
        }
    }

    return 1;
}

static inline int MONSTERS_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = 0;
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        pMonStatsTxtRecord = &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

// 0x00579D60
int __fastcall NPC_HandleDialogMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nType, int nNpcGUID, int nItemGUID)
{
    D2UnitStrc* pMonster = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, nNpcGUID);
    if (!pMonster || !pPlayer)
    {
        return 0;
    }

    const int nClassId = pMonster->dwClassId;
    if (!MONSTERS_CheckMonStatsFlag(nClassId, 9) || pMonster->dwUnitType != UNIT_MONSTER
        || !pMonster->pMonsterData || !pMonster->pMonsterData->pMonInteract)
    {
        return 0;
    }

    int nWpNo;
    int bRefreshInventory = 0;
    if (MONSTERAI_GetInteractUnitCount(pMonster->pMonsterData->pMonInteract) == 1)
    {
        bRefreshInventory = 1;
    }

    if (nType == 1)
    {
        switch ((unsigned int)pMonster->dwClassId)
        {
        case 0x93:
        case 0x94:
        case 0x9A:
        case 0xB1:
        case 0xB2:
        case 0xC7:
        case 0xCA:
        case 0xFC:
        case 0xFD:
        case 0xFE:
        case 0xFF:
        case 0x101:
        case 0x195:
        case 0x1FF:
        case 0x200:
        case 0x201:
            MONSTERAI_SetInteractTrading(pMonster, pPlayer);
            D2GAME_STORES_CreateVendorCache(pGame, pPlayer, pMonster, bRefreshInventory, 0);
            break;
        }
        return 0;
    }

    if (nType == 2)
    {
        switch ((unsigned int)pMonster->dwClassId)
        {
        case 0x93:
        case 0xC7:
        case 0xFE:
        case 0x195:
        case 0x200:
        case 0x202:
            MONSTERAI_SetInteractTrading(pMonster, pPlayer);
            D2GAME_STORES_CreateVendorCache(pGame, pPlayer, pMonster, bRefreshInventory, 1);
            break;
        }
        return 0;
    }

    if (nType == 3)
    {
        D2GAME_NPC_BuildHirelingList_6FCC6FF0(pGame, UnitGetClient(pPlayer, gszNpcSourceFile, 0xB50), pMonster,
            MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pMonster)) <= 1);
        return 0;
    }

    if (nClassId == 0x9A)
    {
        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        packet58.nUnitId = nNpcGUID;

        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszNpcSourceFile, 0xB59);
        if (!SUNITNPC_IsCursorItem(nItemGUID, pPlayer))
        {
            return 3;
        }

        D2UnitStrc* pInput = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 3, 1))
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (!pInput)
        {
            return 0;
        }

        if (!ITEMS_CanBeImbued(pInput))
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        D2ItemDropStrc itemDrop;
        ITEMS_FillItemDrop(pGame, &itemDrop, pInput);

        itemDrop.dwFlags2 |= 0x20 | (ITEMS_IsEthereal(pInput) != 0 ? 4 : 2);
        itemDrop.wItemFormat = pGame->wItemFormat;

        bool bInputIsPersonalized = false;
        char szName[100];
        if (ITEMS_CheckIfFlagIsSet(ITEMS_GetItemFlags(pInput), IFLAG_PERSONALIZED))
        {
            bInputIsPersonalized = true;
            strcpy(szName, ITEMS_GetEarName(pInput));
        }

        if (D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pInput))
        {
            itemDrop.nQuality = 6;
            int nItemLevel = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
            if (nItemLevel > 5)
            {
                nItemLevel += 4;
            }
            itemDrop.nItemLvl = nItemLevel;

            D2UnitStrc* pOutput = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
            if (!pOutput)
            {
                packet58.nAction = 7;
                D2GAME_SendPacket0x58(pClient, &packet58);
                return 0;
            }

            D2GAME_NPC_RepairItem_6FCC6970(pGame, pOutput, 0);
            ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pOutput, pPlayer);
            ITEMS_SetInvPage(pOutput, 0);

            if (bInputIsPersonalized)
            {
                ITEMS_SetItemFlag(pOutput, IFLAG_PERSONALIZED, 1);
                ITEMS_SetEarName(pOutput, szName);
            }

            const int nOutputGUID = pOutput->dwUnitId;
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0xBA9, pGame, pPlayer, nOutputGUID, 0, 0, 1, 1, 0))
            {
                UNITS_ChangeAnimMode(pOutput, 3);
                D2CoordStrc coords;
                UNITS_GetCoords(pPlayer, &coords);
                D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pPlayer);
                D2CoordStrc returnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pPlayerRoom, &coords, &returnCoords, 1, 1);
                D2GAME_DropItem_6FC52260(pGame, 0, pOutput, pRoom, returnCoords.nX, returnCoords.nY);
            }

            ACT1Q3_SetRewardGranted(pGame, pPlayer);
            packet58.nAction = 6;
            D2GAME_SendPacket0x58(pClient, &packet58);
            return 0;
        }

        packet58.nAction = 7;
        D2GAME_SendPacket0x58(pClient, &packet58);
        ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        return 0;
    }
    else if (nClassId == 0x94)
    {
        if (pGame->nDifficulty == 2
            && QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 1, 0) == 1
            && !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x29, 1)
            && !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x29, 0))
        {
            ACT1Q1_SetRespecRewardPending(pGame, pPlayer);
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x29, 1))
        {
            SKILLS_ResetSkillsAndRefundPoints(pGame, pPlayer);
            sub_00570C80_PLAYERSTATS_ResetToBaseStats(pGame, pPlayer);
            SUNIT_AttachSound(pPlayer, 2, pPlayer);
            ACT1Q1_SetRespecRewardGranted(pGame, pPlayer);
        }
        return 0;
    }
    else if (nClassId == 0x1FF)
    {
        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        packet58.nUnitId = nNpcGUID;

        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszNpcSourceFile, 0xBE2);
        if (!SUNITNPC_IsCursorItem(nItemGUID, pPlayer))
        {
            return 3;
        }

        D2UnitStrc* pInput = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x23, 1))
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (!pInput)
        {
            return 0;
        }

        if (!ITEMS_IsSocketable(pInput))
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        D2UnitStrc* pOutput = ITEMS_Duplicate(pGame, pInput, pPlayer, 1);
        if (!pOutput)
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pInput))
        {
            ITEMS_SetItemFlag(pOutput, IFLAG_SOCKETED, 1);

            int nSockets = ITEMS_GetMaxSockets(pOutput);
            switch (ITEMS_GetItemQuality(pOutput))
            {
            case ITEMQUAL_MAGIC:
                if (nSockets >= 2)
                {
                    nSockets = 2;
                }

                nSockets = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pOutput), nSockets) + 1;
                break;
            case ITEMQUAL_SET:
            case ITEMQUAL_RARE:
            case ITEMQUAL_UNIQUE:
            case ITEMQUAL_CRAFT:
            case ITEMQUAL_TEMPERED:
                if (nSockets >= 1)
                {
                    nSockets = 1;
                }
                break;
            }

            ITEMS_AddSockets(pOutput, nSockets);

            D2GAME_NPC_RepairItem_6FCC6970(pGame, pOutput, 0);
            ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pOutput, pPlayer);
            ITEMS_SetInvPage(pOutput, 0);

            const int nOutputGUID = pOutput->dwUnitId;
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0xC36, pGame, pPlayer, nOutputGUID, 0, 0, 1, 1, 0))
            {
                UNITS_ChangeAnimMode(pOutput, 3);
                D2CoordStrc coords;
                UNITS_GetCoords(pPlayer, &coords);
                D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pPlayer);
                D2CoordStrc returnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pPlayerRoom, &coords, &returnCoords, 1, 1);
                D2GAME_DropItem_6FC52260(pGame, 0, pOutput, pRoom, returnCoords.nX, returnCoords.nY);
            }

            ACT5Q1_SetRewardGranted(pGame, pPlayer);
            packet58.nAction = 6;
            D2GAME_SendPacket0x58(pClient, &packet58);
            return 0;
        }

        packet58.nAction = 7;
        D2GAME_SendPacket0x58(pClient, &packet58);
        ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        return 0;
    }
    else if (nClassId == 0x200)
    {
        D2GSPacketSrv58 packet58;
        packet58.nHeader = 0x58;
        packet58.nUnitId = nNpcGUID;

        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszNpcSourceFile, 0xC57);
        if (!SUNITNPC_IsCursorItem(nItemGUID, pPlayer))
        {
            return 3;
        }

        D2UnitStrc* pInput = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x26, 1))
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        if (!pInput)
        {
            return 0;
        }

        if (!ITEMS_IsPersonalizable(pInput))
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
            return 0;
        }

        D2UnitStrc* pOutput = ITEMS_Duplicate(pGame, pInput, pPlayer, 1);
        if (!pOutput)
        {
            packet58.nAction = 7;
            D2GAME_SendPacket0x58(pClient, &packet58);
            ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        }

        if (D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pInput))
        {
            D2GAME_NPC_RepairItem_6FCC6970(pGame, pOutput, 0);
            ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pOutput, pPlayer);
            ITEMS_SetInvPage(pOutput, 0);

            const int nOutputGUID = UNITS_GetUnitId(pOutput);
            if (!D2GAME_PlaceItem_6FC44410(gszNpcSourceFile, 0xC91, pGame, pPlayer, nOutputGUID, 0, 0, 1, 1, 0))
            {
                UNITS_ChangeAnimMode(pOutput, 3);
                D2CoordStrc coords;
                UNITS_GetCoords(pPlayer, &coords);
                D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pPlayer);
                D2CoordStrc returnCoords;
                D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pPlayerRoom, &coords, &returnCoords, 1, 1);
                D2GAME_DropItem_6FC52260(pGame, 0, pOutput, pRoom, returnCoords.nX, returnCoords.nY);
            }

            ITEMS_SetItemFlag(pOutput, IFLAG_PERSONALIZED, 1);
            ITEMS_SetEarName(pOutput, UNITS_GetPlayerData(pPlayer)->szName);
            ACT5Q4_SetRewardGranted(pGame, pPlayer);

            packet58.nAction = 6;
            D2GAME_SendPacket0x58(pClient, &packet58);
            return 0;
        }

        packet58.nAction = 7;
        D2GAME_SendPacket0x58(pClient, &packet58);
        ITEMMODE_DropCursorItem(pGame, pPlayer, nItemGUID);
        return 0;
    }
    else if (nClassId == 0x9B)
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 6, 0))
        {
            return 0;
        }

        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x28, 0);
        QUESTS_ActChange_HirelingChangeAct(pGame, pPlayer, pMonster, 0x28, 1);

        if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_LUTGHOLEIN, &nWpNo))
        {
            WAYPOINTS_ActivateWaypoint(sub_00547F50(pGame, pPlayer), nWpNo);
        }
        return 0;
    }
    else if (nClassId == 0xAF)
    {
        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 1, 5);
        return 0;
    }
    else if (nClassId == 0xD2)
    {
        if (nType || !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0xE, 0))
        {
            return 0;
        }

        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x4B, 0);
        QUESTS_ActChange_HirelingChangeAct(pGame, pPlayer, pMonster, 0x4B, 0x28);

        if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_KURASTDOCKTOWN, &nWpNo))
        {
            WAYPOINTS_ActivateWaypoint(sub_00547F50(pGame, pPlayer), nWpNo);
        }
        return 0;
    }
    else if (nClassId == 0x108)
    {
        if (!nType)
        {
            D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x28, 5);
        }
        return 0;
    }
    else if (nClassId == 0x16F)
    {
        if (nType || !pGame->bExpansion || !QUESTRECORD_GetQuestState(sub_00543520(pGame, pPlayer), 0x1A, 0))
        {
            return 0;
        }

        D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x6D, 0);
        QUESTS_ActChange_HirelingChangeAct(pGame, pPlayer, pMonster, 0x6D, 0x67);

        if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_HARROGATH, &nWpNo))
        {
            WAYPOINTS_ActivateWaypoint(sub_00547F50(pGame, pPlayer), nWpNo);
        }
        return 0;
    }
    else if (nClassId == 0x208)
    {
        if (!nType)
        {
            D2GAME_PlayerChangeAct_6FC867C0(pGame, pPlayer, 0x67, 5);
        }
        return 0;
    }

    return 0;
}

