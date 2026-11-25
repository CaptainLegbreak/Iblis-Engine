#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameAux.h"
#include "D2TxtItems.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2LevelTxt.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2ItemModes.h"
#include "D2LanguageNames.h"

#pragma intrinsic(_ReadWriteBarrier)

#define MONSTATSFLAGINDEX_NORATIO 2

#define MONSTATSFLAGINDEX_BOSS 6

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNITFLAG_INITSEEDSET 0x00000010

#define UNITFLAG_DOUPDATE 0x00000001

#define UNITFLAG_TARGETABLE 0x2

#define IFLAG_NEWITEM 0x1

#define IFLAG_TARGETING 0x4

#define IFLAG_IDENTIFIED 0x10

#define EVENTTYPE_AITHINK 2

#define EVENTTYPE_STATREGEN 3

#define IFLAG_QUANTITY 0x20

#define IFLAG_BROKEN 0x00000100

#define STAT_GOLD 14

#define UNITFLAG_ISRESURRECT 0x02000000

union D2SeedStrc;

struct D2TradeItemStrc;

struct D2SkillsTxt;

struct D2ItemsTxt;

struct D2ItemDataStrc;

struct D2PlayerTradeStrc;

struct D2PlayerDataStrc;

struct D2MonStatsTxt;

struct D2PetInfoStrc;

struct D2ItemModeArgStrc;

struct D2DifficultyLevelsTxt;

struct D2ItemCodeListStrc;

struct D2BooksTxt;

struct D2GameStrc;

struct D2UnitStrc;

struct D2CoordStrc;

struct D2HirelingTxt;

struct D2StatStrc;

struct D2DataTablesStrc;

struct D2RunesTxt;

struct D2StaticPathStrc;

struct D2EquipmentRefreshStateStrc;

struct D2ItemDropStrc;

struct D2ClientStrc;

struct D2ActiveRoomStrc;

struct D2InventoryStrc;

struct D2SkillStrc;

struct D2DynamicPathStrc;



void __fastcall ITEMMODE_RecalcEquippedItemStates(D2GameStrc* pGame, D2UnitStrc* pUnit, int nArg); // 0x0055DBC0

void __fastcall D2CMPTileCacheSetFreeCallback(void* pfnCallback); // 0x005FE000

extern void* gpServer; // 0x00882D08

int __stdcall FOG_10180(void* pObject); // 0x006BE450

void __stdcall FOG_10182_Return(void* pObject); // 0x006BF5F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

int __fastcall PLRSAVE_ReadItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize); // 0x005337F0

void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x005378E0

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0

void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130

void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D2E0

void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543DB0

void __fastcall SUNIT_InitSeed(D2UnitStrc* pUnit, D2SeedStrc* pSeed); // 0x00552DF0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00553180

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10

void __fastcall ITEMS_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090

void __fastcall ITEMMODE_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50

void __fastcall ITEMMODE_AddItemScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C270

void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0

void __fastcall ITEMMODE_RemoveItemScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C6E0

void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730

void __fastcall ITEMMODE_CompactBeltColumn(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX); // 0x0055EDC0

void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00566BF0

D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70

void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000

unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* ptUnit, char* szName); // 0x006220F0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0

int __stdcall D2COMMON_11079_Return0(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A360

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

void __stdcall sub_0063BE30_Return(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot); // 0x0063C4F0

void __stdcall D2COMMON_10267_Return(D2InventoryStrc* pInventory, int nX); // 0x0063C550

void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall INVENTORY_RemoveAllItems(D2InventoryStrc* pInventory); // 0x0063E0B0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810

int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0

int __fastcall D2GAME_SAVE_SerializeItem_6FC89AD0(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int a4, int a5, int a6); // 0x005316D0

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int a2); // 0x00537860

void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4); // 0x0053EC90

void __fastcall D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, int a4); // 0x0053ECF0

void __fastcall ITEMMODE_SendGroundItemToClient(D2UnitStrc* pItem, D2ClientStrc* pClient); // 0x0055BED0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall SUNITMSG_SendRemoveObject(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory); // 0x0063CD60

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc* pItem); // 0x006289C0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

int __stdcall ITEMS_CheckRequirements(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bEquipping, int* bStrength, int* bDexterity, int* bLevel); // 0x0062EAF0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall ITEMS_GetAmmoType(D2UnitStrc* pItem); // 0x0062E6F0

void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc* pItem, unsigned char* pBodyLoc1, unsigned char* pBodyLoc2); // 0x0062EA80

int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBeltSlot(D2InventoryStrc*, int); // 0x0063C7F0

struct D2ItemCodeListStrc
{
    unsigned char nCountA;
    char pad01[3];
    unsigned int dwCodesA[30];
    unsigned char nCountB;
    char pad7D[3];
    unsigned int dwCodesB[1];
};

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

void __stdcall sITEMSAddStatsList(D2UnitStrc* pItem, int nArg); // 0x0055C2C0

void __stdcall sub_0055A2A0(D2UnitStrc* pUnit, int nArg); // 0x0055A2A0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall ITEMMODS_UpdateItemWithSkillCharges(D2UnitStrc* pItem, int nSkillId, int nSkillLevel, int nCharges); // 0x0065C940

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

int __fastcall D2GAME_CheckHasFilledSockets(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590

void __fastcall PLRTRADE_RemoveItemFromTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00567400

extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

extern "C" char __stdcall ITEMS_GetInventoryPage(D2UnitStrc* pUnit); // 0x00628250

void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320

void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00568770

void __stdcall ITEMS_SetCellOverlap(D2UnitStrc* pItem, unsigned char nPage); // 0x006282D0

int __stdcall INVENTORY_PlaceItemAtInventoryPage(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nX, int nY, int nInventoryRecordId, int bClient, unsigned char nPage); // 0x0063BCC0

extern "C" const char szItemModeCpp[]; // 0x006E1164

void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520

int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nScrollGUID, int nBookGUID, int* pItemStatus); // 0x0055EF20

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930

int __stdcall ITEMS_AreStackablesEqual(D2UnitStrc* pItem1, D2UnitStrc* pItem2); // 0x0062C850

unsigned int __stdcall ITEMS_GetAutoStack(D2UnitStrc* pItem); // 0x0062E790

D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0

D2UnitStrc* __stdcall INVENTORY_FindBackPackItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C200

D2UnitStrc* __stdcall INVENTORY_FindEquippedItemForStack(D2InventoryStrc* pInventory, D2UnitStrc* pStackable, D2UnitStrc* pCheckItem); // 0x0063C2F0

D2UnitStrc* __stdcall INVENTORY_FindFillableBook(D2InventoryStrc* pInventory, D2UnitStrc* pScrolls, D2UnitStrc* pCheckItem); // 0x0063C3B0

int __stdcall SKILLS_GetQuantity(D2SkillStrc* pSkill); // 0x006450F0

void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity); // 0x00645120

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

static int ITEMMODE_PickupStackable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc*, D2UnitStrc*); // 0x00558530

void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc*, D2UnitStrc*); // 0x00558580

int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x0055FE80

void __stdcall D2Common_10525(D2UnitStrc*, D2UnitStrc*); // 0x006276C0

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc*); // 0x006299B0

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc*); // 0x0062BEB0

const D2RunesTxt* __stdcall ITEMS_GetRunesTxtRecordFromItem(D2UnitStrc*); // 0x0062BED0

D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void*, D2UnitStrc*); // 0x0063ABD0

int __stdcall ITEMMODS_UpdateRuneword(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused); // 0x006600A0

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

int __fastcall PARTY_ShareGoldDrop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nGold); // 0x00540900

void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00543D80

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pUnit); // 0x00554630

void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B030

void __fastcall ITEMS_DropGoldPileExt(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B030

int __fastcall ITEMMODE_CanPickUpItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055CC90

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x006272B0

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010


int __fastcall SKILLS_TryIncreaseSkillLevel(D2UnitStrc* pUnit, int nSkillId); // 0x00570080

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x006277F0

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0

static void __stdcall ITEMMODE_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2);

int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nInventoryRecordId, int bUnused, unsigned char nPage, const char* szFile, int nLine); // 0x0063B950

int __fastcall ITEMMODE_FindFreeBodyLocation(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710

int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x00562E00

int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C790

int __stdcall D2Common_10299(D2UnitStrc* pUnit, int nBodyLoc, D2UnitStrc* pItem, int bSkipRequirementCheck); // 0x0063DE60

int __fastcall ITEMMODE_CheckAndResolveBodySlotPair(D2UnitStrc*, D2UnitStrc*, D2UnitStrc**, D2UnitStrc**, int*); // 0x0055F2D0

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc* pItem, unsigned char nBodyLoc); // 0x00627D70

int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc*, D2UnitStrc*, int); // 0x0063BDB0

static int ITEMMODE_GetBookSkillId(D2UnitStrc* pItem); // 0x0055BFF0

static void __stdcall ITEMMODE_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C070

extern "C" void _ReadWriteBarrier(void);

#define D2_MAX(a,b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

#define UNIT_PLAYER 0

#define UNIT_ITEM 4

#define ITEMQUAL_UNIQUE 7

#define QUESTSTATEFLAG_A1Q4 4

#define QUESTSTATEFLAG_A2Q1 9

#define QUESTSTATEFLAG_A2Q2 10

#define QFLAG_REWARDGRANTED 0

#define QFLAG_CUSTOM1 5

#define QFLAG_CUSTOM3 7

#define QFLAG_CUSTOM4 8

struct D2GemsTxt;

struct D2CorpseStrc;

struct D2QuestItemPairStrc;

struct SwapEntry;

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int); // 0x0045C4B0

void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove); // 0x0053C4A0

D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc*); // 0x0055B7E0

void __fastcall SKILLS_UpdatePetLimitForSkill(D2GameStrc*, D2UnitStrc*, int); // 0x0056BD90

int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nStateId, int a3); // 0x0056C740

void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc*); // 0x0056DFA0

D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc*, D2UnitStrc*, int, int, int, int, int, int); // 0x0056E740

void __fastcall SKILLITEM_ActivateAura(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005BF510

void __fastcall SKILLITEM_DeactivateAura(D2GameStrc*, D2UnitStrc*, int, int); // 0x005BF5D0

void __fastcall SUNITEVENT_Unregister(D2GameStrc*, D2UnitStrc*, int, int); // 0x005C0B50

void __stdcall STATES_ToggleState(D2UnitStrc*, int, int); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc*, int); // 0x00639DF0

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc*, int, int); // 0x00639E30

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc*); // 0x0063EE90

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc*, D2SkillStrc*, int); // 0x006442A0

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc*, int*, int*, int*, const char*, int); // 0x00645270

void __stdcall SKILLS_RefreshSkill(D2UnitStrc*, int); // 0x00646D60

D2SkillStrc* __stdcall SKILLS_AddSkill(D2UnitStrc*, int); // 0x00647110

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

void __stdcall D2Common_10954(D2UnitStrc*, int, int, int, int, int); // 0x00647530

int __stdcall UNITS_CanDualWield(D2UnitStrc* pUnit); // 0x006235A0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __stdcall ITEMS_GetGemApplyType(D2UnitStrc* pItem); // 0x00629A40

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2GemsTxt* __stdcall DATATBLS_GetGemsTxtRecord(int nGemId); // 0x006372C0

void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0

void __stdcall sub_006275B0(D2UnitStrc*); // 0x006275B0

extern D2QuestItemPairStrc gaQuestItemPairs[4]; // 0x00731FEC

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00543520

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570

int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630

D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610

static int __stdcall ITEMMODE_HasConflictingQuestOrUniqueItem(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem); // 0x0055CA40

void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* pWeapon); // 0x006233A0

void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

void __stdcall INVENTORY_GetSecondWieldingWeapon(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, D2UnitStrc** ppItem, int nBodyLoc); // 0x0063E490

void __fastcall ITEMMODE_MoveExcessBeltItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x005608C0

static void __stdcall ITEMMODE_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit);

void __fastcall QUESTS_SendLogUpdate(D2UnitStrc*, int); // 0x005458E0

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc*, unsigned char, int, int); // 0x0053B3D0

int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc*, D2UnitStrc*, int); // 0x005678A0

int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005BF240

void __fastcall ACT5Q3_ApplyResistanceReward(D2GameStrc*, D2UnitStrc*); // 0x0058A0A0

void __fastcall SKILLS_ResetSkillsAndRefundPoints(D2GameStrc*, D2UnitStrc*); // 0x00570360

void __fastcall sub_00570C80_PLAYERSTATS_ResetToBaseStats(D2GameStrc*, D2UnitStrc*); // 0x00570C80

int __stdcall ITEMS_CheckIfUseable(D2UnitStrc*); // 0x00628C20

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc*, int, int); // 0x0065C360

void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc*, int, int); // 0x0065C3A0

int __fastcall ITEMMODE_GetOppositeBodyLoc(int); // 0x0055F240

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200

static void ITEMMODE_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon); // 0x0055C470

static int ITEMMODE_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C4D0

static void ITEMMODE_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft); // 0x0055C4F0

static int __stdcall ITEMMODE_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C560

static void ITEMMODE_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit); // 0x0055C5C0

int __fastcall ITEMMODE_MarkItemOnCursor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* hItem); // 0x0055FB10

int __stdcall INVENTORY_IsItemBodyLocFree(D2InventoryStrc*, D2UnitStrc*, int, int); // 0x0063CB00

int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc*, D2UnitStrc*, int, int, int, const char*, int); // 0x0063B950

unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc*); // 0x00539220

void __fastcall D2GAME_PACKETS_SendPacket0x97_6FC3FB60(D2ClientStrc*); // 0x0053E110

void __fastcall SUNITMSG_QueueSkillSelection(D2UnitStrc* pUnit, int bLeftSkill, short nSkillId, int nOwnerGUID); // 0x00571C60

void __stdcall UNITS_InitSwitchRightSkill(D2UnitStrc*); // 0x00622F80

void __stdcall UNITS_InitSwitchLeftSkill(D2UnitStrc*); // 0x00622FF0

void __stdcall UNITS_GetSwitchRightSkillDataResetRightSkill(D2UnitStrc*, int*, int*); // 0x00623120

void __stdcall UNITS_GetSwitchLeftSkillDataResetLeftSkill(D2UnitStrc*, int*, int*); // 0x006231A0

struct SwapEntry { int from; D2UnitStrc* item; int to; int mode; };

void __fastcall ITEMMODE_RemoveBeltItem(D2GameStrc*, D2UnitStrc*, D2UnitStrc*); // 0x00561E70

static void __stdcall ITEMMODE_RemoveItemAndNotify(D2GameStrc*, D2UnitStrc*, D2UnitStrc*);

static int ITEMMODE_GetBookOrScrollSkillId(D2UnitStrc*); // 0x0055E050

static void __stdcall sub_0055E0D0_DecrementBookScrollSkillQuantity(D2UnitStrc*, int);

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc*, D2UnitStrc*); // 0x0063C150

int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* pItemStatus); // 0x00560CD0

int __stdcall D2COMMON_10254_Return0(D2InventoryStrc*, int); // 0x0063BE30

#define ITEMACTION_FLAG_BELT 0x20

void __fastcall sub_6FC45930(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x005608C0

void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag); // 0x0053EED0

void __fastcall ITEMMODE_RemoveInventoryItemFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055ED30

void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0055FE00

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0

int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9); // 0x00562660

struct StaticPath
{
    unsigned char pad00[12];
    int x;
    int y;
};

struct Unit
{
    int type;
    int classId;
    unsigned char pad08[4];
    int id;
    int mode;
    unsigned char pad14[24];
    StaticPath* path;
    unsigned char pad30[48];
    void* inventory;
    unsigned char pad64[96];
    unsigned int flags;
};

struct Game
{
    unsigned char pad00[112];
    int expansion;
};

extern "C" void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(void*, Unit*, Unit*, unsigned int); // 0x0053D010

Unit* __fastcall SUNIT_GetServerUnit(Game*, int, int); // 0x00552F60

void* __fastcall sub_005531C0_Client(Unit*, const char*, int); // 0x005531C0

void* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(void*, Point*, Point*, int, unsigned char); // 0x00555DA0

void __fastcall D2GAME_DropItem_6FC52260(Game*, Unit*, Unit*, void*, int, int); // 0x00558AA0

void __fastcall ITEMMODE_ClearTargetingFlags(Unit*, const char*, int); // 0x0055BF50

void __fastcall ITEMMODE_AddItemScrollSkillQuantity(Unit*, Unit*); // 0x0055C270

void __fastcall sITEMSAddStatsList(Game*, Unit*, Unit*, int); // 0x0055C2C0

void __fastcall sub_0055DBC0_Refresh(Game*, Unit*, int); // 0x0055DBC0

void __fastcall PLRTRADE_AddItemToTrade(Game*, Unit*, Unit*); // 0x00568770

extern "C" int __stdcall sub_00621050_Grid(Unit*, unsigned char, int); // 0x00621050

extern "C" int __stdcall sub_006280A0_TestFlag(Unit*, unsigned int, int, const char*); // 0x006280A0

extern "C" void __stdcall ITEMS_SetItemFlag(Unit*, unsigned int, int); // 0x006280D0

extern "C" void __stdcall sub_00628170_CommandFlag(Unit*, unsigned int, int); // 0x00628170

extern "C" unsigned char __stdcall sub_00628250_Page(Unit*); // 0x00628250

extern "C" void __stdcall ITEMS_SetInvPage(Unit*, unsigned char); // 0x00628280

extern "C" void __stdcall ITEMS_SetItemCell(Unit*, unsigned char); // 0x00628320

extern "C" void __stdcall ITEMS_SetOrRemoveFlag(unsigned int*, unsigned int, int); // 0x006287B0

extern "C" int __stdcall INVENTORY_PlaceItemAtFreePosition(void*, Unit*, int, int, unsigned char, const char*, int); // 0x0063B950

extern "C" void __stdcall INVENTORY_Return(const char*, int, void*, int, int, int, int, unsigned char); // 0x0063BCF0

static void ITEMMODE_BuildEquipmentTraits(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ItemModeArgStrc* pItemModeArg);

static int ITEMMODE_AreEquipmentTraitsCompatible(D2ItemModeArgStrc* pArg1, D2ItemModeArgStrc* pArg2);

void __fastcall D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(D2ClientStrc* pClient, char nUnitType);                           // 0x0053C520

D2ClientStrc* __fastcall sub_005531C0_MakeQuantityPacket(D2UnitStrc* pUnit, const char* szFile, int nLine, int nUnitId, int nSkillId, int nQuantity); // 0x005531C0

static void __stdcall ITEMMODE_DecrementBookScrollSkillQuantity(D2UnitStrc* pUnit, int nSkillId);

static void __stdcall ITEMMODE_DropBackToGround(int nSoundId, D2UnitStrc* pItem, D2UnitStrc* pUnit);

struct D2InvRectStrc;

struct BeltRecord;

struct BeltRecord { char unknown00[4]; unsigned char nBoxes; unsigned char reserved5; unsigned short reserved6; D2InvRectStrc boxes[16]; };

extern "C" void __stdcall DATATBLS_GetBeltsTxtRecord(int, int, BeltRecord*); // 0x00660CB0

extern "C" int __stdcall UNITS_GetBeltType(Unit*); // 0x00621ED0

extern "C" Unit* __stdcall INVENTORY_GetItemFromBeltSlot(void*, int); // 0x0063C7F0

void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(void*, Unit*, Unit*, unsigned int); // 0x0053EED0

void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(Game*, Unit*, Unit*, int, int); // 0x0055C730

int __stdcall ITEMS_IsBodyItem(D2UnitStrc* pItem);                                                          // 0x0062FDF0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0

int __stdcall ITEMS_GetQuiverTypeFromItemType(int nItemType);                                               // 0x00628480

void __fastcall ITEMMODE_UpdateItemStatlist(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAllowBrokenItemStats);

static int ITEMMODE_GetBookSkillId(D2UnitStrc* pItem); // 0x0055BFF0

static int __stdcall ITEMMODE_UpdateBookScrollSkillQuantity(int bAddQuantity, D2UnitStrc* pUnit, D2UnitStrc* pItem);

static void ITEMMODE_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon); // 0x0055C470

static int ITEMMODE_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C4D0

static void ITEMMODE_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft); // 0x0055C4F0

static int __stdcall ITEMMODE_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x0055C560

static void ITEMMODE_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit); // 0x0055C5C0



static int ITEMMODE_AddScrollToFillableBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScroll);

static void __stdcall ITEMMODE_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit);

void __fastcall D2GAME_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190

void __stdcall UNITS_InitRightSkill(D2UnitStrc* pUnit);                                                     // 0x00622EA0

void __stdcall UNITS_InitLeftSkill(D2UnitStrc* pUnit);                                                      // 0x00622F10

void __stdcall UNITS_GetRightSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID);                  // 0x00623060

void __stdcall UNITS_GetLeftSkillData(D2UnitStrc* pUnit, int* pSkillId, int* pOwnerGUID);                   // 0x006230C0

int __stdcall ITEMS_CheckType(int nItemType, int nItemTypeToCheck);                                         // 0x00629B50

void __stdcall INVENTORY_UpdateWeaponGUIDOnInsert(D2InventoryStrc* pInventory, D2UnitStrc* pItem);              // 0x0063D1D0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill);                                            // 0x00643AD0

unsigned int __stdcall ITEMS_GetItemStartSeed(D2UnitStrc* pItem);                                           // 0x00627DF0

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3);        // 0x00558D90

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

int __fastcall ITEMMODE_CheckEquipRequirements(D2UnitStrc* pUnit,D2UnitStrc* pItem); // 0x0055DB00

void __fastcall D2GAME_SendPacket0x48_6FC3EF40(D2ClientStrc* pClient,D2UnitStrc* pUnit,int nArg); // 0x0053D3C0

void __fastcall D2GAME_RepairBrokenItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

static void __stdcall ITEMMODE_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

static int ITEMMODE_GetBookOrScrollSkillId(D2UnitStrc* pItem); // 0x0055E050

int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* pGame, D2UnitStrc* pUnit);

D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pFreeQuantity);

static int __stdcall ITEMMODE_AutoStackPickup(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

int __stdcall ITEMMODE_TryMergeBookQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);

static int __stdcall ITEMMODE_PlaceItemAtFreeInventoryPosition(D2GameStrc* pGame, int bRemove, int nPage, const char* szFile, int nLine, D2UnitStrc* pUnit, D2UnitStrc* pItem);

int gnHoradricCubeItemId; // 0x0088C6FC

bool gbHoradricCubeItemIdInitialized; // 0x0088C700

void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus);

static void ITEMMODE_SaveEquipmentRefreshState(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState);

static void ITEMMODE_RestoreSelectedSkills(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState);

static void __stdcall ITEMMODE_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2);

int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus);

static void __stdcall ITEMMODE_InitItemDropFromItem(int nId, D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);

void __fastcall D2GAME_UpdatePlayerVitals(D2GameStrc* pGame, D2UnitStrc* pUnit);

void __fastcall ITEMMODE_AddBookQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue);

static int __stdcall ITEMMODE_HasSameAffixes(D2UnitStrc* pBook, D2UnitStrc* pItem);

D2UnitStrc* __fastcall ITEMMODE_AddScrollToMatchingBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bCheckOnly);

void __fastcall ITEMMODE_ResetBookScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem);

void __fastcall ITEMMODE_RebuildBookScrollSkillQuantities(D2GameStrc* pGame, D2UnitStrc* pUnit);

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus);

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

enum D2C_UnitFlags
{
    UNITFLAG_ISVALIDTARGET = 0x00000008,
};

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame); // 0x00626D40

// 0x00555D20
void __fastcall ITEMMODE_InitializeItemUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int nUnitGUID, D2ActiveRoomStrc* pRoom)
{
    if (pUnit)
    {
        pUnit->dwUnitId = nUnitGUID;
        pUnit->dwFlags = pUnit->dwFlags & ~UNITFLAG_ISVALIDTARGET | UNITFLAG_TARGETABLE;
    }

    ITEMS_SetItemFlag(pUnit, IFLAG_IDENTIFIED, 1);
    STATLIST_AllocStatListEx(pUnit, 0, 0, 0);

    const unsigned char nQuest = DATATBLS_GetItemsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nQuest;
    if (nQuest)
    {
        QUESTS_CreateChainRecord(pGame, pUnit, nQuest - 1);
    }

    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pUnit);
}

// 0x00555DA0
D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms)
{
    const int nX = pCoords->nX + 2;
    const int nY = pCoords->nY + 3;

    if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
    {
        pReturnCoords->nX = nX;
        pReturnCoords->nY = nY;
    }
    else
    {
        pReturnCoords->nX = pCoords->nX;
        pReturnCoords->nY = pCoords->nY;
    }

    return COLLISION_GetFreeCoordinatesWithField(pRoom, pReturnCoords, pCoords, nUnitSize, 0x3E01, 0x801, bAllowNeighborRooms);
}

// 0x0055BFE0
void __fastcall ITEMMODE_ClearUnitTargetingFlags(D2UnitStrc* pUnit)
{
    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1E5);
}

// 0x0055C270
void __fastcall ITEMMODE_AddItemScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x24D);
    D2_ASSERT(pItem, 0x24E);

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        ITEMMODE_UpdateBookScrollSkillQuantity(1, pUnit, pItem);
    }
}

// 0x0055C460
void __fastcall ITEMMODE_UpdateItemStatlist(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAllowBrokenItemStats)
{
    sITEMSAddStatsList(pGame, pItem, pUnit, bAllowBrokenItemStats);
}

inline D2ItemStatCostTxt* GetStatCost(int nStat) {
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount) return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}

// 0x0055B800
void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOther, int nLayerStatId, int nPreviousValue, int nNewValue)
{
    if (!pGame || !pUnit) return;
    int nStat = (unsigned int)nLayerStatId >> 16;
    D2ItemStatCostTxt* pCost = GetStatCost(nStat);
    if (!pCost) return;
    int nItemGUID = 0;
    if (pOther) nItemGUID = pOther->dwUnitId;
    if (pCost->wItemEvent[0] > 0) {
        if (nNewValue) {
            if (!SUNITEVENT_GetEvent(pGame, pUnit, 2, nLayerStatId, nLayerStatId)) {
                SKILLS_RegisterUnitEvent(pGame, pUnit, pCost->wItemEvent[0], nLayerStatId, 0, pCost->wItemEventFunc[0], 2, nLayerStatId);
                short nSecondEvent = pCost->wItemEvent[1];
                if (nSecondEvent > 0) SKILLS_RegisterUnitEvent(pGame, pUnit, nSecondEvent, nLayerStatId, 0, pCost->wItemEventFunc[1], 2, nLayerStatId);
            }
        } else SUNITEVENT_Unregister(pGame, pUnit, 2, nLayerStatId);
    }
    switch (nStat) {
    case 7:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
                if (pUnit->dwUnitType == UNIT_MONSTER) {
                    D2MonStatsTxt* pMonStats = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
                    if (pMonStats && pMonStats->nDamageRegen) STATLIST_SetUnitStat(pUnit, STAT_HPREGEN, ((nNewValue >> 8) * pMonStats->nDamageRegen) >> 4, 0);
                }
            }
        }
        break;
    case 9:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, STAT_MANA, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
            }
        }
        break;
    case 11:
        if (nNewValue != nPreviousValue && nPreviousValue > 0) {
            int nCurrent = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0);
            if (nCurrent > 0) {
                if (nPreviousValue <= 256) nPreviousValue = 256;
                float fValue = (float)nNewValue / nPreviousValue * nCurrent;
                int nValue = (int)fValue;
                STATLIST_SetUnitStat(pUnit, STAT_STAMINA, D2_MIN(D2_MAX(nValue, 1), nNewValue), 0);
            }
        }
        break;
    case 97:
    case 107:
        {
            int nSkillId = (unsigned short)nLayerStatId;
            D2SkillsTxt* pSkills = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
            if (nSkillId && (nStat != 107 || pUnit->dwUnitType == UNIT_PLAYER && (!pUnit ? -1 : pUnit->dwClassId) == pSkills->nCharClass)) {
                D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                if (!pSkill) {
                    pSkill = SKILLS_AddSkill(pUnit, nSkillId);
                    SKILLS_AssignSkill(pUnit, nSkillId, 0, 0, ".\\ITEMS\\ItemMode.cpp", 249);
                    D2ClientStrc* pClient;
                    if (pUnit->dwUnitType == UNIT_PLAYER) pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 253);
                    else pClient = 0;
                    D2GAME_PACKETS_SendPacket0x21_UpdateSkills_6FC3DB50(pClient, pUnit, nSkillId, 0, 0);
                }
                SKILLS_RefreshSkill(pUnit, nSkillId);
                SKILLS_UpdatePetLimitForSkill(pGame, pUnit, nSkillId);
                if (nNewValue <= 0) {
                    nNewValue = 1;
                    if (SKILLS_GetSkillLevel(pUnit, pSkill, 0)) {
                        nNewValue = 0;
                        if (SKILLS_GetSkillLevel(pUnit, pSkill, 1)) return;
                    }
                    if (UNITS_GetLeftSkill(pUnit) == pSkill) D2GAME_AssignSkill_6FD13800(pUnit, 1, SKILL_ATTACK, -1);
                    if (UNITS_GetRightSkill(pUnit) == pSkill) D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_ATTACK, -1);
                    if (nNewValue) SKILLS_AssignSkill(pUnit, nSkillId, 0, 1, ".\\ITEMS\\ItemMode.cpp", 282);
                }
            }
        }
        break;
    case 83:
        if (pUnit->dwUnitType == UNIT_PLAYER && (!pUnit ? -1 : pUnit->dwClassId) == (unsigned short)nLayerStatId)
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else
        {
            int nType = pUnit->dwUnitType;
            int nClass = pUnit->dwClassId;
            int nMode = pUnit->dwAnimMode;
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ITEMS\\ItemMode.cpp", 304);
            if (nType == 0 && nClass == (unsigned short)nLayerStatId)
            {
                D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
            }
        }
        break;
    case 188:
        if (pUnit->dwUnitType == UNIT_PLAYER && (!pUnit ? -1 : pUnit->dwClassId) == ((unsigned short)nLayerStatId >> 3))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else if (MONSTERS_GetHirelingTypeId(pUnit))
        {
            D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        }
        else
        {
            int nType = pUnit->dwUnitType;
            int nClass = pUnit->dwClassId;
            int nMode = pUnit->dwAnimMode;
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\ITEMS\\ItemMode.cpp", 325);
            if (nType == 0 && nClass == ((unsigned short)nLayerStatId >> 3))
            {
                D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
            }
        }
        break;
    case 126:
    case 127:
        D2GAME_RefreshPassiveSkills_6FD14CC0(pUnit);
        break;
    case 151:
        {
            int nAuraSkill = (unsigned short)nLayerStatId;
            if (nNewValue) SKILLITEM_ActivateAura(pGame, pUnit, nItemGUID, nAuraSkill, nNewValue);
            else SKILLITEM_DeactivateAura(pGame, pUnit, nItemGUID, nAuraSkill);
        }
        break;
    case 204:
        if (pOther) {
            int nShift = sgptDataTables->nStuff;
            int nLevel = sgptDataTables->nShiftedStuff;
            int nLayer = (unsigned short)nLayerStatId;
            int nSkillId = nLayer >> nShift;
            nLevel &= nLayer;
            int nCharges = STATLIST_UnitGetStatValue(pOther, nStat, nLayer) & 255;
            if (nCharges > 0 && STATLIST_GetOwner(pOther, 0) == pUnit) {
                D2Common_10954(pUnit, nItemGUID, nSkillId, nLevel, nCharges, 0);
            } else {
                D2Common_10954(pUnit, nItemGUID, nSkillId, nLevel, 0, 1);
                SKILLS_UpdatePetLimitForSkill(pGame, pUnit, nSkillId);
            }
        }
        break;
    case 98:
        {
            int nState = (unsigned short)nLayerStatId;
            if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount) {
                int bState = STATES_CheckState(pUnit, nState);
                if (nNewValue) {
                    if (bState) return;
                    SKILLS_RemoveStatesInGroup(pUnit, nState, 0);
                    STATES_ToggleState(pUnit, nState, 1);
                } else {
                    if (!bState) return;
                    SKILLS_RemoveStatesInGroup(pUnit, nState, 1);
                    STATES_ToggleState(pUnit, nState, 0);
                }
                STATES_ToggleGfxStateFlag(pUnit, nState, 1);
            }
        }
        break;
    }
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x0055BED0
void __fastcall ITEMMODE_SendGroundItemToClient(D2UnitStrc* pItem, D2ClientStrc* pClient)
{
    if (!pItem || UNIT_HasFlag(pItem, UNITFLAG_INITSEEDSET) || pItem->dwAnimMode != IMODE_ONGROUND)
    {
        return;
    }

    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (UNIT_HasFlag(pItem, UNITFLAG_SENDREFRESHMSG))
    {
        D2GAME_SendP0x9C_ItemAction_DropToGround_6FC3E8E0(pClient, pPlayer, pItem, 0);
    }
    else
    {
        D2GAME_SendP0x9C_ItemAction_OnGround_6FC3E930(pClient, pPlayer, pItem, 0);
    }
}

// 0x0055BF30
void __fastcall ITEMMODE_SendUpdatedGroundItemToClient(D2UnitStrc* pItem, D2ClientStrc* pClient)
{
    if (pItem && UNIT_HasFlag(pItem, UNITFLAG_DOUPDATE))
    {
        ITEMMODE_SendGroundItemToClient(pItem, pClient);
    }
}

// 0x0055BF50
void __fastcall ITEMMODE_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine)
{
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMS_CheckItemFlag(pInvItem, IFLAG_TARGETING, 0x1D6, ".\\ITEMS\\ItemMode.cpp"))
        {
            ITEMS_SetItemFlag(pInvItem, IFLAG_TARGETING, 0);
            if (GAME_GetUnitTypeOrInvalid(pUnit) == UNIT_PLAYER)
            {
                D2GAME_PACKETS_SendPacket0x3F_6FC3EDC0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1DA), pInvItem, 0xFF, 1, 0, 0xFFFF);
            }
        }
    }
}

// 0x0055BFF0
static int ITEMMODE_GetBookSkillId(D2UnitStrc* pItem)
{
    D2_ASSERT(pItem, 0x1EC);

    if (ITEMSIsA(pItem, 0x16) || ITEMSIsA(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        if (pBooksTxtRecord)
        {
            if (ITEMSIsA(pItem, 0x16))
            {
                return pBooksTxtRecord->dwScrollSkillId;
            }

            if (ITEMSIsA(pItem, 0x12))
            {
                return pBooksTxtRecord->dwBookSkillId;
            }
        }
    }

    return -1;
}

// 0x0055C070
static void __stdcall ITEMMODE_AddBookScrollSkillQuantity(int nQuantityBonus, D2UnitStrc* pUnit, D2UnitStrc* hItem)
{
    D2_ASSERT(pUnit, 0x202);
    D2_ASSERT(hItem, 0x203);

    const int nSkillId = ITEMMODE_GetBookSkillId(hItem);
    if (nSkillId == -1)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        const int nQuantity = SKILLS_GetQuantity(pSkill) + nQuantityBonus;
        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitType = pUnit->dwUnitType;
        const int nUnitGUID = pUnit->dwUnitId;
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x20B), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
}

// 0x0055C110
static int __stdcall ITEMMODE_UpdateBookScrollSkillQuantity(int bAddQuantity, D2UnitStrc* pUnit, D2UnitStrc* hItem)
{
    int nSkillId = ITEMMODE_GetBookSkillId(hItem);
    if (nSkillId != -1)
    {
        int nQuantity = STATLIST_UnitGetStatValue(hItem, STAT_QUANTITY, 0);
        if (nQuantity || !ITEMSIsA(hItem, 0x12))
        {
            if (!nQuantity)
            {
                nQuantity = 1;
            }

            D2SkillStrc* hSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
            int nNewQuantity;
            if (bAddQuantity)
            {
                if (!hSkill)
                {
                    nNewQuantity = nQuantity;
                    STATLIST_AddUnitStat(pUnit, STAT_SKILLPTS, nNewQuantity, 0);
                    SKILLS_TryIncreaseSkillLevel(pUnit, nSkillId);
                    hSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
                    D2_ASSERT(hSkill, 0x225);
                }
                else
                {
                    nNewQuantity = SKILLS_GetQuantity(hSkill) + nQuantity;
                }
            }
            else
            {
                if (hSkill)
                {
                    nNewQuantity = SKILLS_GetQuantity(hSkill) - nQuantity;
                    if (nNewQuantity < 0)
                    {
                        nNewQuantity = 0;
                    }
                }
                else
                {
                    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x230);
                    exit(-1);
                }
            }

            SKILLS_SetQuantity(hSkill, nNewQuantity);

            int nUnitGUID;
            int nUnitType;
            if (!pUnit)
            {
                nUnitGUID = -1;
                nUnitType = 6;
            }
            else
            {
                nUnitGUID = pUnit->dwUnitId;
                nUnitType = pUnit->dwUnitType;
            }

            D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x234), nUnitType, nUnitGUID, nSkillId, nNewQuantity);

            if (!nNewQuantity)
            {
                if (UNITS_GetLeftSkill(pUnit) == hSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 1, SKILL_ATTACK, -1);
                }

                if (UNITS_GetRightSkill(pUnit) == hSkill)
                {
                    D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_ATTACK, -1);
                }
            }

            return 1;
        }
    }

    return 0;
}

// 0x0055C470
static void ITEMMODE_GetWeapons(D2UnitStrc* pUnit, D2UnitStrc** ppMainWeapon, D2UnitStrc** ppRightHandWeapon)
{
    *ppRightHandWeapon = 0;
    *ppMainWeapon = 0;

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        *ppMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRightHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pLeftHandWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (*ppMainWeapon == pRightHandWeapon)
        {
            *ppRightHandWeapon = pLeftHandWeapon;
        }
        else
        {
            *ppRightHandWeapon = pRightHandWeapon;
        }

        if (*ppRightHandWeapon && !ITEMSIsA(*ppRightHandWeapon, 0x2D))
        {
            *ppRightHandWeapon = 0;
        }
    }
}

// Out of line as in the original: it takes arguments in ecx and eax, a convention the compiler gives only a static whose callers are all in this object.
// 0x0055C4D0
static __declspec(noinline) int ITEMMODE_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return 0;
    }

    return 1;
}

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

static inline D2InventoryStrc* GetUnitInventory(D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }
    return pInventory;
}

// 0x0055C2C0
void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4)
{
    if (!pUnit || sub_0044BE50(pItem) != 4)
    {
        return;
    }

    const int v_dwUnitType_74 = *(int *)&pUnit->dwUnitType;
    if (v_dwUnitType_74 == 0 && STATES_CheckState(pUnit, STATE_PLAYERBODY))
    {
        return;
    }

    if (ITEMSIsA(pItem, 0x14))
    {
        if (pUnit->dwUnitType != UNIT_ITEM)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (!pItemsTxtRecord)
        {
            return;
        }

        const int v_dwGemOffset_93 = *(int *)&pItemsTxtRecord->dwGemOffset;
        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord(v_dwGemOffset_93);
        if (!pGemsTxtRecord)
        {
            return;
        }

        ITEMMODS_AssignProperty(2, 0, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMSIsA(pItem, 0x4A))
    {
        if (pUnit->dwUnitType != UNIT_ITEM)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
        if (!pItemsTxtRecord)
        {
            return;
        }

        D2GemsTxt* pGemsTxtRecord = DATATBLS_GetGemsTxtRecord((*(int *)&pItemsTxtRecord->dwGemOffset));
        if (!pGemsTxtRecord)
        {
            return;
        }

        ITEMMODS_AssignProperty(5, pUnit, pItem, pGemsTxtRecord, ITEMS_GetGemApplyType(pUnit), 0);
    }
    else if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
    {
        ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    }

    ITEMMODE_AddItemScrollSkillQuantity(pUnit, pItem);

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    D2UnitStrc* pLeftHandWeapon = 0;
    if (nUnitType == 0)
    {
        pLeftHandWeapon = INVENTORY_GetLeftHandWeapon(GetUnitInventory(pUnit));
    }

    int bType = 1;
    if (UNITS_CanDualWield(pUnit))
    {
        if (pItem != pLeftHandWeapon && ITEMSIsA(pItem, 0x2D))
        {
            bType = 0;
        }

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x2B8, szItemModeCpp) && !a4)
        {
            {
                if (pUnit->pDynamicPath)
                {
                    UnitUpdateAnimRateAndVel(pUnit, szItemModeCpp, 0x2CF);
                }
                return;
            }
        }
    }
    else
    {
        if (ITEMS_CheckItemFlag(pItem, 0x100, 0x2C1, szItemModeCpp) && !a4)
        {
            goto skip_merge;
        }
    }

    STATLIST_MergeStatLists(pUnit, pItem, bType);
skip_merge:

    if (pUnit->pDynamicPath)
    {
        UnitUpdateAnimRateAndVel(pUnit, szItemModeCpp, 0x2CF);
    }
}

// 0x0055C4F0
static void ITEMMODE_RestoreSkill(D2UnitStrc* pUnit, D2SkillStrc* pCurrentSkill, int bLeft)
{
    if (!pUnit || !pCurrentSkill)
    {
        return;
    }

    int nSkillId;
    int nOwnerGUID;
    if (bLeft)
    {
        UNITS_GetLeftSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }
    else
    {
        UNITS_GetRightSkillData(pUnit, &nSkillId, &nOwnerGUID);
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill || pSkill == pCurrentSkill)
    {
        return;
    }

    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 2:
    case 7:
        return;
    }

    D2GAME_AssignSkill_6FD13800(pUnit, bLeft, nSkillId, nOwnerGUID);
}

// 0x0055C560
static int __stdcall ITEMMODE_IsThrowSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    if (!pSkill)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || !ITEMS_CheckType(pSkillsTxtRecord->nITypeA[0], ITEMTYPE_THROWN_WEAPON) || pSkillsTxtRecord->nAuraTargetState != 2)
    {
        return 0;
    }

    return ITEMMODE_IsSkillUsable(pUnit, pSkill) != 0;
}

// 0x0055C5C0
static void ITEMMODE_RefreshSkillsForEquippedWeapons(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return;
    }

    D2UnitStrc* pRightHandWeapon;
    D2UnitStrc* pMainWeapon;
    ITEMMODE_GetWeapons(pUnit, &pMainWeapon, &pRightHandWeapon);
    if (!pMainWeapon)
    {
        return;
    }

    int bThrown = ITEMSIsA(pMainWeapon, 0x30) && !ITEMSIsA(pMainWeapon, 0x2E);
    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (bThrown && !ITEMMODE_IsThrowSkillUsable(pUnit, pLeftSkill))
    {
        UNITS_InitLeftSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 1, SKILL_THROW, -1);
        pLeftSkill = UNITS_GetLeftSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pLeftSkill))
    {
    case 2:
    case 7:
        ITEMMODE_RestoreSkill(pUnit, pLeftSkill, 1);
        break;
    }

    bThrown = pRightHandWeapon && ITEMSIsA(pRightHandWeapon, 0x30) && !ITEMSIsA(pRightHandWeapon, 0x2E);
    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (bThrown && !ITEMMODE_IsThrowSkillUsable(pUnit, pRightSkill))
    {
        UNITS_InitRightSkill(pUnit);
        D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_LEFTHANDTHROW, -1);
        pRightSkill = UNITS_GetRightSkill(pUnit);
    }

    switch (SKILLS_GetUseState(pUnit, pRightSkill))
    {
    case 2:
    case 7:
        ITEMMODE_RestoreSkill(pUnit, pRightSkill, 0);
        break;
    }
}

// 0x0055C6E0
void __fastcall ITEMMODE_RemoveItemScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pUnit, 0x394);
    D2_ASSERT(pItem, 0x395);

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        ITEMMODE_UpdateBookScrollSkillQuantity(0, pUnit, pItem);
    }
}

// 0x0055C730
void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals)
{
    if (!pTarget || !pItem || pItem->dwUnitType != UNIT_ITEM)
        return;
    if (pTarget->dwUnitType == UNIT_PLAYER && STATES_CheckState(pTarget, STATE_PLAYERBODY))
        return;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 9, pItem->dwUnitId);
    if (pTarget != STATLIST_GetOwner(pItem, 0))
        return;
    if (ITEMS_GetItemQuality(pItem) == ITEMQUAL_SET)
        ITEMS_UpdateSets(pTarget, pItem, 1, 0);
    const int nTargetType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    D2UnitStrc* pLeftWeapon = 0;
    if (nTargetType == 0)
        pLeftWeapon = INVENTORY_GetLeftHandWeapon(GetUnitInventory(pTarget));
    if (!ITEMS_CheckItemFlag(pItem, 0x100, 0x3D8, ".\\ITEMS\\ItemMode.cpp") || bUpdateStatList)
        STATLIST_ExpireUnitStatlist(pTarget, pItem);
    if (UNITS_CanDualWield(pTarget) && pLeftWeapon && ITEMSIsA(pItem, 0x2D) && pLeftWeapon != pItem)
    {
        if (!ITEMS_CheckItemFlag(pLeftWeapon, 0x100, 0x3E6, ".\\ITEMS\\ItemMode.cpp") || bUpdateStatList)
        {
            if (STATLIST_GetOwner(pLeftWeapon, 0))
                STATLIST_MergeStatLists(pTarget, pLeftWeapon, 1);
        }
    }
    ITEMMODE_RemoveItemScrollSkillQuantity(pTarget, pItem);
    if (bUpdateVitals)
        sub_006275B0(pTarget);
}

// 0x0055C850
static void __stdcall D2GAME_PickupGold(D2GameStrc* pGame, D2UnitStrc* pGoldPile, D2UnitStrc* pUnit)
{
    const int nInventoryLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const int nUnitGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    const int nPileGold = STATLIST_UnitGetStatValue(pGoldPile, STAT_GOLD, 0);
    int nRemainingGold = 0;
    int nPickedGold = nPileGold;
    if (nPileGold + nUnitGold > nInventoryLimit)
    {
        nPickedGold = nInventoryLimit - nUnitGold;
        nRemainingGold = nPileGold - nPickedGold;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pGoldPile);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        PLRTRADE_AddGold(pUnit, 0xE, nPickedGold);
    }
    else if (SUNIT_GetPartyId(pUnit) != -1)
    {
        nRemainingGold = PARTY_ShareGoldDrop(pGame, pUnit, nPileGold);
    }
    else if (pUnit)
    {
        const int nNewGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) + nPickedGold;
        if (nNewGold < 0)
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER && nNewGold > (int)UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else
        {
            STATLIST_AddUnitStat(pUnit, STAT_GOLD, nPickedGold, 0);
        }
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pGoldPile), !pGoldPile ? 6 : pGoldPile->dwUnitType, !pGoldPile ? -1 : pGoldPile->dwUnitId);
    UNITS_FreeCollisionPath(pGoldPile);
    UNITROOM_RemoveUnitFromRoom(pGoldPile);
    if (pGoldPile)
    {
        pGoldPile->dwFlags &= ~2;
    }

    ITEMS_RemoveFromAllPlayers(pGame, pGoldPile);

    if (nRemainingGold > 0)
    {
        ITEMS_DropGoldPileExt(pGame, pUnit, nRemainingGold);
        SUNIT_AttachSound(pUnit, 0x17, pUnit);
    }
}

// 0x0055C9A0
static void __stdcall ITEMMODE_DropBackToGround(int nSoundId, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
    ITEMS_SetInvPage(pItem, 0xFF);
    if (pItem)
    {
        pItem->dwFlags |= 0x1000;
    }

    UNITS_ChangeAnimMode(pItem, 3);
    SUNIT_AttachSound(pUnit, nSoundId, pUnit);
}

// 0x0055D370
int __stdcall ITEMMODE_TryMergeBookQuantity(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(ptGame, 0x622);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pInventory, pItem, 0);
    if (!pBook)
    {
        return 0;
    }

    const int nSrcValue = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);
    D2_ASSERT(nSrcValue >= 0, 0x62E);

    const int nDstValue = STATLIST_UnitGetStatValue(pBook, STAT_QUANTITY, 0);
    D2_ASSERT(nDstValue >= 0, 0x630);

    const int nDstMaxValue = ITEMS_GetTotalMaxStack(pBook);
    D2_ASSERT(nDstMaxValue >= 0, 0x632);

    const int nQuantity = nDstValue + nSrcValue;
    if (nQuantity > nDstMaxValue)
    {
        STATLIST_SetUnitStat(pBook, STAT_QUANTITY, nDstMaxValue, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x638), pBook, 1, 0x46, nDstMaxValue, 0);

        const int nRest = nDstValue - nDstMaxValue + nSrcValue;
        D2_ASSERT(nRest >= 0, 0x63A);

        STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nRest, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x63D), pItem, 1, 0x46, nRest, 0);
        ITEMMODE_AddBookScrollSkillQuantity(nDstMaxValue - nDstValue, pUnit, pBook);
        return 1;
    }

    D2_ASSERT(nQuantity >= 0, 0x645);

    STATLIST_SetUnitStat(pBook, STAT_QUANTITY, nQuantity, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x648), pBook, 1, 0x46, nQuantity, 0);
    ITEMMODE_AddBookScrollSkillQuantity(nSrcValue, pUnit, pBook);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    if (pRoom)
    {
        DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    if (pItem)
    {
        pItem->dwFlags &= ~2;
    }

    ITEMS_RemoveFromAllPlayers(ptGame, pItem);
    INVENTORY_SetCursorItem(pInventory, 0);
    return 1;
}

// 0x0055D560
static void ITEMMODE_BuildEquipmentTraits(D2UnitStrc* pUnit, D2UnitStrc* hItem, D2ItemModeArgStrc* pItemModeArg)
{
    D2_ASSERT(hItem, 0x675);
    D2_ASSERT(pUnit, 0x676);
    memset(pItemModeArg, 0, sizeof(D2ItemModeArgStrc));
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == 0 && pUnit->dwClassId == 4)
    {
        pItemModeArg->bCanUse2Weapons = 1;
    }
    const int nUnitType2 = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType2 == 0 && pUnit->dwClassId == 6 && ITEMSIsA(hItem, 0x43))
    {
        pItemModeArg->bCanUse2Weapons = 1;
    }
    if (ITEMSIsA(hItem, 0x1B))
    {
        pItemModeArg->bIsBow = 1;
    }
    if (ITEMSIsA(hItem, 0x23))
    {
        pItemModeArg->bIsCrossBow = 1;
    }
    if (ITEMSIsA(hItem, 5))
    {
        pItemModeArg->bIsBowQuiver = 1;
    }
    if (ITEMSIsA(hItem, 6))
    {
        pItemModeArg->bIsCrossBowQuiver = 1;
    }
    if (ITEMSIsA(hItem, 0x33))
    {
        pItemModeArg->bIsShield = 1;
    }
    if (ITEMS_CheckWeaponIfTwoHanded(hItem))
    {
        pItemModeArg->bIsTwoHanded = 1;
    }
    if (ITEMSIsA(hItem, 0x2D))
    {
        pItemModeArg->bIsWeapon = 1;
    }
    if (ITEMS_CheckIfThrowable(hItem) || STATLIST_UnitGetItemStatOrSkillStatValue(hItem, STAT_ITEM_THROWABLE, 0))
    {
        pItemModeArg->bIsThrowable = 1;
    }
    if (ITEMSIsA(hItem, 0x0A))
    {
        pItemModeArg->bIsRing = 1;
    }
}

// 0x0055D670
static int ITEMMODE_AreEquipmentTraitsCompatible(D2ItemModeArgStrc* pArg1, D2ItemModeArgStrc* pArg2)
{
    if (pArg1->bIsBow && pArg2->bIsBowQuiver || pArg1->bIsBowQuiver && pArg2->bIsBow)
    {
        return 1;
    }
    if (pArg1->bIsCrossBow && pArg2->bIsCrossBowQuiver || pArg1->bIsCrossBowQuiver && pArg2->bIsCrossBow)
    {
        return 1;
    }
    if (pArg1->bIsWeapon && !pArg1->bIsTwoHanded && pArg2->bIsShield || pArg2->bIsWeapon && !pArg2->bIsTwoHanded && pArg1->bIsShield)
    {
        return 1;
    }
    if (pArg1->bIsWeapon && !pArg1->bIsTwoHanded && pArg2->bIsWeapon && !pArg2->bIsTwoHanded && pArg1->bCanUse2Weapons && pArg2->bCanUse2Weapons)
    {
        return 1;
    }
    if (pArg1->bIsRing && pArg2->bIsRing)
    {
        return 1;
    }
    return 0;
}

// 0x0055CA00
int __fastcall OBJECTS_MatchFieldPair(D2ItemsTxt* pRecord1, D2ItemsTxt* pRecord2, int nValue1, int nValue2)
{
    if (pRecord1->dwCode == nValue1 && pRecord2->dwCode == nValue2)
    {
        return 1;
    }

    if (pRecord1->dwCode == nValue2 && pRecord2->dwCode == nValue1)
    {
        return 1;
    }

    return 0;
}

static inline int ITEMS_IsItemInline(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_ITEM;
}

static inline D2UniqueItemsTxt* DATATBLS_GetUniqueItemsTxtRecordInline(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }
    return 0;
}

static inline unsigned char GetQuestIndex(const D2ItemsTxt* pRecord)
{
    unsigned char nQuest = 0;
    if (pRecord)
    {
        nQuest = pRecord->nQuest;
    }
    return nQuest;
}

// 0x0055CA40
static int __stdcall ITEMMODE_HasConflictingQuestOrUniqueItem(D2UnitStrc* pItem, D2ItemsTxt* pItemsTxtRecordArg, D2UnitStrc* pPreviousItem)
{
    int nUniqueId = -1;
    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = DATATBLS_GetUniqueItemsTxtRecordInline(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7])
        {
            nUniqueId = pUniqueItemsTxtRecord->wId;
        }
    }

    while (pPreviousItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pPreviousItem);
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pPreviousItem);
        if (pCheckedItem == pItem)
        {
            break;
        }

        if (!ITEMS_IsItemInline(pCheckedItem))
        {
            pPreviousItem = pNext;
            continue;
        }

        if (nUniqueId >= 0 && ITEMS_GetInvPage(pCheckedItem) != 1 && ITEMS_GetItemQuality(pCheckedItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pCheckedItem) == nUniqueId)
        {
            return 1;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pCheckedItem->dwClassId);
        if (pItemsTxtRecord->nQuest && ITEMS_GetInvPage(pCheckedItem) != 1 && GetQuestIndex(pItemsTxtRecord) == pItemsTxtRecordArg->nQuest)
        {
            if (pItemsTxtRecordArg->dwCode == pItemsTxtRecord->dwCode
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 43j', ' 43g')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' skb', ' dkb')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 33d', ' 33g')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' fsm')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' tsh', ' piv')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' 1fq')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rhq')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' yeq')
                || OBJECTS_MatchFieldPair(pItemsTxtRecordArg, pItemsTxtRecord, ' 2fq', ' rbq'))
            {
                return 1;
            }
        }

        pPreviousItem = pNext;
    }

    return 0;
}


// 0x0055CC90
int __fastcall ITEMMODE_CanPickUpItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pPreviousItem = INVENTORY_GetFirstItem(pInventory);
    if (!pInventory)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) >= 0)
    {
        D2UniqueItemsTxt* pUniqueItemsTxtRecord = sub_00483470(ITEMS_GetFileIndex(pItem));
        if (pUniqueItemsTxtRecord && pUniqueItemsTxtRecord->nUniqueItemFlags[UNIQUEITEMSFLAGINDEX_CARRY1 >> 3] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_CARRY1 & 7] && ITEMMODE_HasConflictingQuestOrUniqueItem(pItem, pItemsTxtRecord, pPreviousItem))
        {
            return 0;
        }
    }

    if (!pItemsTxtRecord->nQuest)
    {
        return 1;
    }

    const unsigned int nItemCode = pItemsTxtRecord->dwCode;
    if (nItemCode == ' ssa')
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q1, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 43j')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_REWARDGRANTED))
        {
            return 0;
        }
    }
    else if (nItemCode == ' zyx')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q4, QFLAG_CUSTOM1))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 33g')
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A3Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }
    }
    else if (nItemCode == ' 2rt')
    {
        if (!QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM4))
        {
            return 0;
        }

        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A5Q3, QFLAG_CUSTOM3))
        {
            return 0;
        }
    }

    const int nQuest = pItemsTxtRecord->nQuest;
    if (nQuest - 1 == QUESTSTATEFLAG_A2Q1)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A2Q2, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' xob')
        {
            return 0;
        }
    }
    else if (nQuest - 1 == QUESTSTATEFLAG_A1Q4)
    {
        if (QUESTRECORD_GetQuestState(sub_00543520(pGame, pUnit), QUESTSTATEFLAG_A1Q4, QFLAG_REWARDGRANTED) && pItemsTxtRecord->dwCode != ' gel')
        {
            return 0;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 4; ++i)
        {
            if (pItemsTxtRecord->nQuest == gaQuestItemPairs[i].nItemQuest)
            {
                D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
                if (QUESTRECORD_GetQuestState(pQuestFlags, gaQuestItemPairs[i].nQuestFlag, QFLAG_REWARDGRANTED))
                {
                    return 0;
                }
            }
        }
    }

    if (ITEMMODE_HasConflictingQuestOrUniqueItem(pItem, pItemsTxtRecord, pPreviousItem))
    {
        return 0;
    }

    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pUnit->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        if (pPlayer && pPlayer->pInventory)
        {
            D2UnitStrc* pFirstItem = INVENTORY_GetFirstItem(pPlayer->pInventory);
            if (pFirstItem && ITEMMODE_HasConflictingQuestOrUniqueItem(pItem, pItemsTxtRecord, pFirstItem))
            {
                return 0;
            }
        }
    }

    return 1;
}

static inline void AddGoldToUnit(D2UnitStrc* pUnit, int nGold)
{
    if (pUnit)
    {
        const int nNewGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) + nGold;
        if (nNewGold < 0)
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER && nNewGold > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
        }
        else
        {
            STATLIST_AddUnitStat(pUnit, STAT_GOLD, nGold, 0);
        }
    }
}

// 0x0055CF50
void __fastcall D2GAME_PickupItemEx_6FC42B80(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int* pItemStatus)
{
    D2_ASSERT(ptGame, 1368);
    D2_ASSERT(hUnit, 1369);

    *pItemStatus = 0;

    D2InventoryStrc* hInventory = hUnit->pInventory;
    D2_ASSERT(hInventory, 1374);

    if (INVENTORY_GetCursorItem(hInventory) || PLAYER_IsBusy(hUnit))
    {
        return;
    }

    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 1390);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, UNIT_ITEM, nItemGUID);
    if (!pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    if (pItem->dwAnimMode != IMODE_ONGROUND)
    {
        *pItemStatus = 1;
        return;
    }

    if (!ITEMMODE_CanPickUpItem(ptGame, hUnit, pItem))
    {
        ITEMMODE_DropBackToGround(0x13, pItem, hUnit);
        return;
    }

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        D2GAME_PickupGold(ptGame, pItem, hUnit);
    }
    else
    {
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
        pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
        INVENTORY_SetCursorItem(hInventory, pItem);
        UNITS_ChangeAnimMode(pItem, IMODE_ONCURSOR);
        ITEMS_SetItemCMDFlag(pItem, 64, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        UNITS_RefreshInventory(hUnit, 1);
        pItem->dwFlags &= ~UNITFLAG_ISRESURRECT;
        INVENTORY_AddItemToTradeInventory(hInventory, pItem);
        QUESTS_ItemPickedUp(ptGame, hUnit, pItem);
    }

    SUNIT_AttachSound(hUnit, 1, hUnit);
}

// 0x0055D0D0
static int __stdcall ITEMMODE_AutoStackPickup(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pStackItem = 0;
    int nCounter = 0;
    int nQuantity1, nQuantity2;

    if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) <= 0) goto NotStacked;
    do
    {
        ++nCounter;

        if (ITEMS_GetAutoStack(pItem))
        {
            if (ITEMS_GetQuiverType(pItem))
            {
                pStackItem = INVENTORY_FindEquippedItemForStack(pInventory, pItem, pStackItem);
                if (!pStackItem)
                {
                    pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
                }
            }
            else
            {
                pStackItem = INVENTORY_FindBackPackItemForStack(pInventory, pItem, pStackItem);
            }
        }

        if (!pStackItem)
        {
            return 0;
        }

        if (ITEMS_AreStackablesEqual(pItem, pStackItem))
        {
            nQuantity1 = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);
            nQuantity2 = STATLIST_UnitGetStatValue(pStackItem, STAT_QUANTITY, 0);
            if (nQuantity1 + nQuantity2 > ITEMS_GetTotalMaxStack(pStackItem))
            {
                const int nMaxStack = ITEMS_GetTotalMaxStack(pStackItem);
                D2_ASSERT(nMaxStack >= 0, 0x5C7);

                STATLIST_SetUnitStat(pStackItem, STAT_QUANTITY, nMaxStack, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x5CA), pStackItem, 1, 0x46, nMaxStack, 0);

                const int nRest = nQuantity2 - nMaxStack + nQuantity1;
                D2_ASSERT(nRest >= 0, 0x5CC);

                STATLIST_SetUnitStat(pItem, STAT_QUANTITY, nRest, 0);

                if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && ITEMS_GetItemType(pStackItem) == ITEMTYPE_BOOK)
                {
                    ITEMMODE_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pStackItem) - nQuantity2, pUnit, pStackItem);
                }
            }
            else goto MergeStack;
        }
    } while (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) > 0);

    if (!nCounter)
    {
NotStacked:
        return 0;
    }

    D2_ASSERT(0, 0x606);
    return 0;
MergeStack:
    {
        const int nQuantity = nQuantity2 + nQuantity1;
        D2_ASSERT(nQuantity >= 0, 0x5D7);

        if (ITEMS_HasDurability(pItem))
        {
            const int nDurability = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
            if (nDurability < STATLIST_UnitGetStatValue(pStackItem, STAT_DURABILITY, 0))
            {
                STATLIST_SetUnitStat(pStackItem, STAT_DURABILITY, nDurability, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x5E4), pStackItem, 1, 0x48, nDurability, 0);
            }
        }

        STATLIST_SetUnitStat(pStackItem, STAT_QUANTITY, nQuantity, 0);
        STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 0, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, szItemModeCpp, 0x5ED), pStackItem, 1, 0x46, nQuantity, 0);

        if (ITEMS_GetItemType(pItem) == ITEMTYPE_BOOK && ITEMS_GetItemType(pStackItem) == ITEMTYPE_BOOK)
        {
            ITEMMODE_AddBookScrollSkillQuantity(nQuantity1, pUnit, pStackItem);
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
        if (pRoom)
        {
            DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
            UNITS_FreeCollisionPath(pItem);
            UNITROOM_RemoveUnitFromRoom(pItem);
        }

        if (pItem)
        {
            pItem->dwFlags &= ~2;
        }

        ITEMS_RemoveFromAllPlayers(pGame, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        return 1;
    }
}

// 0x0055D710
int __fastcall ITEMMODE_FindFreeBodyLocation(D2UnitStrc* pUnit, D2UnitStrc* hItem, int* pBodyLoc, int bSkipRequirementCheck)
{
    D2_ASSERT(pUnit, 0x6DC);
    D2_ASSERT(hItem, 0x6DD);
    if (bSkipRequirementCheck)
    {
        if (!ITEMS_IsBodyItem(hItem) || !sub_006280A0(hItem, 0x10, 0x6E2, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CanBeEquipped(hItem) || ITEMS_GetItemType(hItem) == ITEMTYPE_MISSILE_POTION)
        {
            return 0;
        }
    }
    else
    {
        if (!ITEMS_CheckRequirements(hItem, pUnit, 0, 0, 0, 0) || !ITEMS_IsBodyItem(hItem) || !sub_006280A0(hItem, 0x10, 0x6EB, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CanBeEquipped(hItem) || ITEMS_GetItemType(hItem) == ITEMTYPE_MISSILE_POTION)
        {
            return 0;
        }
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if (ITEMS_GetQuiverTypeFromItemType(ITEMS_GetItemType(hItem)))
    {
        if (!pRightArmItem || !ITEMSIsA(hItem, ITEMS_GetAmmoType(pRightArmItem)))
        {
            if (!pLeftArmItem || !ITEMSIsA(hItem, ITEMS_GetAmmoType(pLeftArmItem)))
            {
                return 0;
            }
        }
    }
    unsigned char nBodyLoc1;
    unsigned char nBodyLoc2;
    ITEMS_GetAllowedBodyLocations(hItem, &nBodyLoc1, &nBodyLoc2);
    if (nBodyLoc1 == nBodyLoc2)
    {
        if (!INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc1))
        {
            *pBodyLoc = nBodyLoc1;
            return 1;
        }
        return 0;
    }
    D2ItemModeArgStrc itemModeArg1;
    D2ItemModeArgStrc itemModeArg2;
    ITEMMODE_BuildEquipmentTraits(pUnit, hItem, &itemModeArg1);
    D2UnitStrc* pItem1 = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc1);
    D2UnitStrc* pItem2 = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc2);
    if (pItem1 && pItem2)
    {
        return 0;
    }
    if (!pItem1 && !pItem2)
    {
        *pBodyLoc = nBodyLoc1;
        return 1;
    }
    if (pItem1)
    {
        ITEMMODE_BuildEquipmentTraits(pUnit, pItem1, &itemModeArg2);
        if (!ITEMMODE_AreEquipmentTraitsCompatible(&itemModeArg1, &itemModeArg2))
        {
            return 0;
        }
        *pBodyLoc = nBodyLoc2;
        return 1;
    }
    ITEMMODE_BuildEquipmentTraits(pUnit, pItem2, &itemModeArg2);
    if (!ITEMMODE_AreEquipmentTraitsCompatible(&itemModeArg1, &itemModeArg2))
    {
        return 0;
    }
    *pBodyLoc = nBodyLoc1;
    return 1;
}

// 0x0055D920
void __stdcall sub_0055D920_Nop()
{
}

// 0x0055D930
void __stdcall sub_0055D930(int nUnused1)
{
}

// 0x0055D940
static void __stdcall ITEMMODE_DetachItemAndUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
    if (UNITS_GetAnimOrSeqMode(pItem) == IMODE_EQUIP)
    {
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 1, 1);
    }
}

// 0x0055D970
static void __stdcall ITEMMODE_UpdateEquippedItemStats(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    const unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == 0xB || nBodyLoc == 0xC)
    {
        return;
    }

    sub_0063D1D0_InventoryItemCall(pInventory, pItem);

    if (UNITS_GetAnimOrSeqMode(pItem) == 1)
    {
        sITEMSAddStatsList(pGame, pItem, pUnit, 1);
        return;
    }
    if (UNITS_GetAnimOrSeqMode(pItem) == 0 && ITEMS_IsCharmUsable(pItem, pUnit))
    {
        sITEMSAddStatsList(pGame, pItem, pUnit, 1);
    }
}

// 0x0055D9D0
static void ITEMMODE_SaveEquipmentRefreshState(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState)
{
    pRefreshState->nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    pRefreshState->nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    pRefreshState->nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pRefreshState->nLeftSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pRefreshState->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\ITEMS\\ItemMode.cpp", 0x9DF);
    }
    else
    {
        pRefreshState->nLeftSkillOwnerGUID = -1;
        pRefreshState->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pRefreshState->nRightSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pRefreshState->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\ITEMS\\ItemMode.cpp", 0x9EB);
    }
    else
    {
        pRefreshState->nRightSkillOwnerGUID = -1;
        pRefreshState->nRightSkillId = 0;
    }
}

// 0x0055DA70
static void ITEMMODE_RestoreSelectedSkills(D2UnitStrc* pUnit, D2EquipmentRefreshStateStrc* pRefreshState)
{
    if (pRefreshState->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pRefreshState->nLeftSkillId, pRefreshState->nLeftSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit))
        {
            switch (SKILLS_GetUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;

            default:
                D2GAME_AssignSkill_6FD13800(pUnit, 1, pRefreshState->nLeftSkillId, pRefreshState->nLeftSkillOwnerGUID);
                break;
            }
        }
    }

    if (pRefreshState->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pRefreshState->nRightSkillId, pRefreshState->nRightSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit))
        {
            switch (SKILLS_GetUseState(pUnit, pSkill))
            {
            case 2:
            case 7:
                break;

            default:
                D2GAME_AssignSkill_6FD13800(pUnit, 0, pRefreshState->nRightSkillId, pRefreshState->nRightSkillOwnerGUID);
                break;
            }
        }
    }
}

// 0x0055B060
void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue)
{
    const unsigned int nGoldLimit = UNITS_GetInventoryGoldLimit(pUnit);
    const unsigned int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    if (nGold == nGoldLimit)
    {
        ITEMS_DropGoldPile(pGame, pUnit, nValue);
    }
    else if (nGold + nValue > nGoldLimit)
    {
        PLRTRADE_AddGold(pUnit, 14, nGoldLimit - nGold);
        ITEMS_DropGoldPile(pGame, pUnit, nValue + nGold - nGoldLimit);
    }
    else
    {
        PLRTRADE_AddGold(pUnit, 14, nValue);
    }
}

// 0x0055AFA0
void __fastcall ITEMS_DropTreasureClassById(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, int nTCId, int nQuality, int nItemLevel, int a7, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems)
{
    int nLevel = 0;
    if (pGame->bExpansion && pGame->nDifficulty > 0 && pMonster && pMonster->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pMonster->dwClassId);
        if (pMonStatsTxtRecord && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NORATIO >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NORATIO & 7]) && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_BOSS >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_BOSS & 7]))
        {
            nLevel = STATLIST_UnitGetStatValue(pMonster, STAT_LEVEL, 0);
        }
    }

    D2TCExShortStrc* pTCRecord = DATATBLS_GetTreasureClassExRecordFromIdAndLevel(nTCId, nLevel);
    if (pTCRecord)
    {
        D2GAME_DropTC_6FC51360(pGame, pMonster, pPlayer, pTCRecord, nQuality, nItemLevel, a7, ppItems, pnItemsDropped, nMaxItems);
    }
}

// 0x0055B030
void __fastcall ITEMS_DropGoldPile(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue)
{
    D2UnitStrc* pGoldPiles[32];
    int nCount;
    ITEMS_DropGoldPiles(pGame, pUnit, nValue, pGoldPiles, &nCount, 32);
}

void __fastcall sub_K11_Emit0055D940(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    ITEMMODE_DetachItemAndUpdate(pGame, pUnit, pItem);
    ITEMMODE_DetachItemAndUpdate(pGame, pItem, pUnit);
}

// 0x0055FDE0
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    ITEMMODE_RecalcEquippedItemStates(pGame, pUnit, 0);
    if (a3)
    {
        UNITS_RefreshInventory(pUnit, 1);
    }
}

// 0x00562590
void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 0x1380, ".\\ITEMS\\ItemMode.cpp") || !pInventory)
    {
        return;
    }

    D2_ASSERT(!ITEMS_CheckItemCMDFlag(pItem, 0x100000), 0x1383);

    ITEMMODE_IdentifyItemAndApplyCharmProperties(pGame, pItem, pPlayer);
    ITEMS_SetItemFlag(pItem, IFLAG_NEWITEM, 1);

    if (ITEMS_CheckItemFlag(pItem, IFLAG_NOEQUIP, 0x1389, ".\\ITEMS\\ItemMode.cpp"))
    {
        ITEMS_SetItemFlag(pItem, IFLAG_NOEQUIP, 0);
    }

    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pPlayer, 1);
    SUNIT_AttachSound(pPlayer, 6, pPlayer);
}

static inline int sub_0055DBC0_GetUnitType(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static inline int sub_0055DBC0_UnitFlag9(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

// 0x0055FE00
void __fastcall ITEMMODE_IdentifyItemAndApplyCharmProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    ITEMS_SetItemFlag(pItem, IFLAG_IDENTIFIED, 1);

    if (pItem && pItem->dwAnimMode != IMODE_STORED)
    {
        return;
    }

    if (!ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        return;
    }

    sITEMSAddStatsList(pGame, pItem, pPlayer, 0);
    ITEMMODE_RecalcEquippedItemStates(pGame, pPlayer, 0);
    UNITS_RefreshInventory(pPlayer, 1);
}

// 0x0055FE60
void __stdcall D2GAME_ITEMS_UpdateStatList(D2UnitStrc* pItem)
{
    sITEMSAddStatsList(pItem, 0);
}

// 0x00560020
static int ITEMMODE_PickupStackable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(pGame, 0x65F);

    if (ITEMSIsA(pItem, 0x16))
    {
        return ITEMMODE_AddScrollToFillableBook(pGame, pUnit, pItem);
    }

    if (ITEMSIsA(pItem, 0x12))
    {
        return ITEMMODE_TryMergeBookQuantity(pGame, pUnit, pItem);
    }

    if (ITEMS_CheckIfStackable(pItem) && ITEMS_GetAutoStack(pItem))
    {
        return ITEMMODE_AutoStackPickup(pGame, pUnit, pItem);
    }

    return 0;
}

// 0x0055F590
int __fastcall D2GAME_CheckHasFilledSockets(D2UnitStrc* pItem, const char* szFile, int nLine)
{
    if (pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_CheckIfSocketable(pItem) && pItem->pInventory && INVENTORY_GetItemCount(pItem->pInventory) > 0)
    {
        return 1;
    }

    return 0;
}

// 0x0055F5D0
static int __stdcall ITEMMODE_HasSameAffixes(D2UnitStrc* pBook, D2UnitStrc* pItem)
{
    for (int i = 0; i < 3; i += 1)
    {
        if (ITEMS_GetPrefixId(pBook, i) != ITEMS_GetPrefixId(pItem, i))
        {
            return 0;
        }

        if (ITEMS_GetSuffixId(pBook, i) != ITEMS_GetSuffixId(pItem, i))
        {
            return 0;
        }
    }

    return ITEMS_GetAutoAffix(pBook) == ITEMS_GetAutoAffix(pItem);
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline int sub_0044BE50_Inline(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x0055FFA0
static int ITEMMODE_AddScrollToFillableBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pScroll)
{
    D2_ASSERT(pGame, 0x610);

    D2UnitStrc* pBook = INVENTORY_FindFillableBook(pUnit->pInventory, pScroll, 0);
    if (pBook)
    {
        int nItemStatus;
        const int nBookGUID = pBook->dwUnitId;
        return ITEMMODE_AddScrollToBook(pGame, pUnit, !pScroll ? -1 : pScroll->dwUnitId, nBookGUID, &nItemStatus);
    }

    return 0;
}

void __fastcall sub_BF69_Emit_0055E0D0(D2UnitStrc* pUnit, int nSkillId)
{
    if (pUnit && nSkillId)
    {
        ITEMMODE_DecrementBookScrollSkillQuantity(pUnit, nSkillId);
        ITEMMODE_DecrementBookScrollSkillQuantity(pUnit, nSkillId + 1);
    }
}

static void __stdcall sub_0055E0D0_DecrementBook(D2UnitStrc* player, int skillId)
{
    D2SkillStrc* skill = SKILLS_GetSkillById(player, skillId, -1);
    D2_ASSERT(skill, 0xFC4);
    int quantity = SKILLS_GetQuantity(skill) - 1;
    if (quantity <= 0) {
        if (UNITS_GetRightSkill(player) == skill) D2GAME_AssignSkill_6FD13800(player, 0, SKILL_ATTACK, -1);
        quantity = 0;
    }
    SKILLS_SetQuantity(skill, quantity);
    int id = !player ? -1 : player->dwUnitId;
    int type = !player ? 6 : player->dwUnitType;
    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(player, ".\\ITEMS\\ItemMode.cpp", 0xFC2), type, id, skillId, quantity);
}

static inline D2InventoryStrc* UNITS_GetInventory(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pInventory;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

// 0x005600A0
static int __stdcall ITEMMODE_PlaceItemAtFreeInventoryPosition(D2GameStrc* ptGame, int bRemove, int nPage, const char* szFile, int nLine, D2UnitStrc* pUnit, D2UnitStrc* hItem)
{
    D2_ASSERT(ptGame, 0x746);

    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 0x749);

    if (INVENTORY_PlaceItemAtFreePosition(hInventory, hItem, UNITS_GetInventoryRecordId(pUnit, nPage, ptGame->bExpansion), 0, 0, szFile, nLine))
    {
        if (bRemove)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(hItem);
            if (pRoom)
            {
                const int nUnitGUID = !hItem ? -1 : hItem->dwUnitId;
                const int nUnitType = !hItem ? 6 : hItem->dwUnitType;
                DUNGEON_AllocDrlgDelete(pRoom, nUnitType, nUnitGUID);
                UNITS_FreeCollisionPath(hItem);
                UNITROOM_RemoveUnitFromRoom(hItem);
            }
        }

        if (INVENTORY_PlaceItemInSocket(hInventory, hItem, 1))
        {
            INVENTORY_SetCursorItem(hInventory, 0);
            ITEMMODE_AddItemScrollSkillQuantity(pUnit, hItem);

            if (ITEMS_IsCharmUsable(hItem, pUnit))
            {
                sITEMSAddStatsList(ptGame, hItem, pUnit, 0);
            }

            if (hItem)
            {
                hItem->dwFlags &= ~2u;
            }

            UNITS_ChangeAnimMode(hItem, 0);
            ITEMS_SetItemCMDFlag(hItem, 0x80, 1);
            INVENTORY_AddItemToTradeInventory(hInventory, hItem);
            UNITS_RefreshInventory(pUnit, 1);

            if (hItem)
            {
                hItem->dwFlags &= ~0x02000000u;
            }

            ITEMS_SetInvPage(hItem, nPage);
            QUESTS_ItemPickedUp(ptGame, pUnit, hItem);

            if (ITEMS_IsCharmUsable(hItem, pUnit))
            {
                ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
                UNITS_RefreshInventory(pUnit, 1);
            }

            return 1;
        }

        D2_ASSERT(0, 0x76F);
    }

    return 0;
}

static inline int sub_E03_ItemGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int sub_E03_ItemGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00560200
int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int bAutoPosition, int bNotify, D2InventoryStrc* pInventory)
{
    if (!pGame || !pPlayer) return 0;
    ITEMMODE_ClearTargetingFlags(pPlayer, szItemModeCpp, 0x87B);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nUnitId);
    if (!pItem) return 0;
    if (pItem->dwUnitType != UNIT_ITEM) return 0;
    if (pItem->dwAnimMode != IMODE_ONCURSOR) return 0;
    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    if (!pInventory)
    {
        pInventory = pPlayer->pInventory;
        if (!pInventory) return 0;
    }
    int bTrade = 0;
    int bClearCursor = 1;
    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pPlayer, nPage, pGame->bExpansion);
    if (pPlayer->dwUnitType == UNIT_PLAYER)
    {
        switch (nPage)
        {
        case 1: bClearCursor = 0; break;
        case 2: bTrade = 1; break;
        }
    }
    if (bAutoPosition)
    {
        if (!INVENTORY_PlaceItemAtFreePosition(pInventory, pItem, nInventoryRecordId, 0, nPage, szFile, nLine)) goto failed;
    }
    else
    {
        if (nX < 0) nX = 0;
        if (nY < 0) nY = 0;
        if (!INVENTORY_PlaceItemAtInventoryPage(pInventory, pItem, nX, nY, nInventoryRecordId, 0, nPage)) goto failed;
    }
    if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, 1))
    {
    failed:
        return 0;
    }
    if (ITEMS_GetInvPage(pItem) != 4) ITEMMODE_AddItemScrollSkillQuantity(pPlayer, pItem);
    pItem->dwFlags &= ~2u;
    if (ITEMS_IsCharmUsable(pItem, pPlayer)) sITEMSAddStatsList(pGame, pItem, pPlayer, 0);
    if (bClearCursor) INVENTORY_SetCursorItem(pInventory, 0);
    UNITS_ChangeAnimMode(pItem, 0);
    if (bNotify)
    {
        ITEMS_SetItemCMDFlag(pItem, 2, 1);
        if (D2GAME_CheckHasFilledSockets(pItem, szItemModeCpp, 0x8EA)) ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x8EE, szItemModeCpp)) ITEMS_SetItemFlag(pItem, 0x4000, 0);
        UNITS_RefreshInventory(pPlayer, 1);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    }
    if (bTrade == 1) PLRTRADE_AddItemToTrade(pGame, pPlayer, pItem);
    if (ITEMS_IsCharmUsable(pItem, pPlayer))
    {
        ITEMMODE_RecalcEquippedItemStates(pGame, pPlayer, 0);
        UNITS_RefreshInventory(pPlayer, 1);
    }
    return 1;
}

// 0x00560420
int __fastcall ITEMMODE_RemoveStoredItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus, int nUpdateMode, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int bAllowOccupiedCursor)
{
    D2_ASSERT(ptGame, 0x906);
    D2_ASSERT(pUnit, 0x907);

    *pItemStatus = 0;

    D2InventoryStrc* hInventory = pUnit->pInventory;
    if (pInventoryArg)
    {
        hInventory = pInventoryArg;
    }

    D2_ASSERT(hInventory, 0x910);

    if (INVENTORY_GetCursorItem(hInventory) && !bAllowOccupiedCursor)
    {
        return 0;
    }

    D2UnitStrc* hItem = SUNIT_GetServerUnit(ptGame, UNIT_ITEM, nItemGUID);
    if (!hItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (hItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER && !PLAYER_IsBusy(pUnit) && ITEMS_GetInventoryPage(hItem))
    {
        *pItemStatus = 1;
        return 0;
    }

    if (hItem->dwAnimMode != IMODE_STORED)
    {
        *pItemStatus = 1;
        return 0;
    }

    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x936);

    hItem->dwFlags &= ~UNITFLAG_TARGETABLE;

    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(hInventory, hItem);
    D2_ASSERT(hRemove, 0x947);
    D2_ASSERT(hItem == hRemove, 0x948);

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, hItem, pUnit, 0, 1);

    if (ITEMS_IsCharmUsable(hItem, pUnit))
    {
        ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
        UNITS_RefreshInventory(pUnit, 1);
    }

    ITEMMODE_RemoveItemScrollSkillQuantity(pUnit, hItem);

    const unsigned char nInvPage = ITEMS_GetInventoryPage(hItem);
    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nInvPage, ptGame->bExpansion);

    int bTrade = 0;
    int bEquip = 1;

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nInvPage)
        {
        case INVPAGE_EQUIP:
            bEquip = 0;
            break;
        case INVPAGE_TRADE:
            bTrade = 1;
            break;
        }
    }
    else
    {
        bEquip = 0;
    }

    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0x965, hInventory, CLIENTS_GetUnitX(hItem), CLIENTS_GetUnitY(hItem), nInventoryRecordId, 0, nInvPage);

    ITEMS_SetItemCell(hItem, nInvPage);
    ITEMS_SetInvPage(hItem, INVPAGE_NULL);

    if (bEquip)
    {
        INVENTORY_SetCursorItem(hInventory, hItem);
    }

    UNITS_ChangeAnimMode(hItem, IMODE_ONCURSOR);

    if (nUpdateMode == 1)
    {
        if (bSetQuantityFlag)
        {
            ITEMS_SetItemFlag(hItem, IFLAG_QUANTITY, 1);
        }

        if (bTrade == 1)
        {
            PLRTRADE_RemoveItemFromTrade(ptGame, pUnit, hItem);
        }

        ITEMS_SetItemCMDFlag(hItem, 4, 1);

        if (D2GAME_CheckHasFilledSockets(hItem, ".\\ITEMS\\ItemMode.cpp", 0x975))
        {
            ITEMS_SetItemFlag(hItem, IFLAG_NEWITEM, 1);
        }

        if (sub_006280A0(hItem, IFLAG_NOEQUIP, 0x978, ".\\ITEMS\\ItemMode.cpp"))
        {
            ITEMS_SetItemFlag(hItem, IFLAG_NOEQUIP, 0);
        }

        INVENTORY_AddItemToTradeInventory(hInventory, hItem);
        UNITS_RefreshInventory(pUnit, 1);
    }

    return 1;
}

// 0x0055DB00
int __fastcall ITEMMODE_CheckEquipRequirements(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int bResult = ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0);
    if (bResult && ITEMS_GetQuiverType(pItem))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pOtherArmItem == pItem)
        {
            pOtherArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        }

        if (!pOtherArmItem || !ITEMSIsA(pOtherArmItem, ITEMS_GetQuiverType(pItem)))
        {
            bResult = 0;
        }
    }

    return bResult;
}

// 0x0055DB80
D2ClientStrc* __fastcall ITEMMODE_GetClientFromUnitOrOwner(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        return UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xA44);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
    {
        return UnitGetClient(pOwner, ".\\ITEMS\\ItemMode.cpp", 0xA49);
    }

    return 0;
}

// 0x0055DF00
void __fastcall D2GAME_ITEMS_UpdateInventoryItems(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused, int nArg)
{
    ITEMMODE_RecalcEquippedItemStates(pGame, pUnit, nArg);
}

// 0x005606B0
int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus)
{
    int bIsSwitchWeapon = 0;
    if (nBodyLoc == 0xB || nBodyLoc == 0xC)
    {
        bIsSwitchWeapon = 1;
    }

    D2_ASSERT(ptGame, 0xAEE);
    D2_ASSERT(hUnit, 0xAEF);

    if (pItemStatus)
    {
        *pItemStatus = 0;
    }

    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0xAF7);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        if (pItemStatus)
        {
            *pItemStatus = 1;
        }

        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_ONCURSOR)
    {
        if (pItemStatus)
        {
            *pItemStatus = 1;
        }

        return 0;
    }

    if (D2Common_10299(hUnit, nBodyLoc, pItem, bSkipRequirementCheck) != 1)
    {
        if (pItemStatus)
        {
            *pItemStatus = 0;
        }

        return 0;
    }

    if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, hUnit, 0, 0, 0, 0))
    {
        if (pItemStatus)
        {
            *pItemStatus = 1;
        }

        return 0;
    }

    D2InventoryStrc* pInventory = hUnit->pInventory;
    if (!bIsSwitchWeapon)
    {
        D2UnitStrc* pMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
        if (pMainWeapon)
        {
            UNITS_SetWeaponGUID(hUnit, pMainWeapon);
        }
    }

    if (sub_0063BDB0(pInventory, pItem, nBodyLoc))
    {
        int nPage = 3;
        if (bIsSwitchWeapon)
        {
            nPage = 4;
        }

        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
        {
            ITEMS_SetBodyLocation(pItem, nBodyLoc);

            if (!bIsSwitchWeapon)
            {
                sub_0063D1D0_InventoryItemCall(pInventory, pItem);
                sITEMSAddStatsList(ptGame, pItem, hUnit, 0);
            }

            INVENTORY_SetCursorItem(pInventory, 0);
            pItem->dwFlags &= ~2;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 0xFF);
            ITEMS_SetItemCMDFlag(pItem, 8, 1);
            ITEMS_SetItemFlag(pItem, 1, 1);
            if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xB4E, ".\\ITEMS\\ItemMode.cpp"))
            {
                ITEMS_SetItemFlag(pItem, 0x4000, 0);
            }

            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(hUnit, 1);
            ITEMMODE_RefreshSkillsForEquippedWeapons(hUnit);
            ITEMMODE_RecalcEquippedItemStates(ptGame, hUnit, 0);
        }
        else
        {
            if (pItemStatus)
            {
                *pItemStatus = 1;
            }

            return 0;
        }
    }

    return 1;
}

// 0x0055DF10
void __fastcall D2GAME_RemoveItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2UnitStrc* hItem, int bSendPacket)
{
    D2_ASSERT(ptGame, 0xF6F);
    D2_ASSERT(pUnit, 0xF70);

    if (hItem)
    {
        hItem->dwFlags &= ~UNITFLAG_TARGETABLE;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hItem);
    D2_ASSERT(hRemove, 0xF76);
    D2_ASSERT(hItem == hRemove, 0xF77);

    const unsigned char nPage = ITEMS_GetInvPage(hItem);
    const int nRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, ptGame->bExpansion);
    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0xF7B, pInventory, CLIENTS_GetUnitX(hItem), CLIENTS_GetUnitY(hItem), nRecordId, 0, nPage);
    ITEMS_SetInvPage(hItem, INVPAGE_NULL);

    if (bSendPacket)
    {
        SUNITMSG_SendRemoveObject(hItem, UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF7E));
    }

    ITEMS_RemoveFromAllPlayers(ptGame, hItem);
}

// 0x0055E000
static void __stdcall ITEMMODE_RemoveItemAndNotify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xF88);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pItem, nFlags);
    D2GAME_RemoveItem(pGame, pUnit, pItem, 0);
}

// 0x0055E050
static int ITEMMODE_GetBookOrScrollSkillId(D2UnitStrc* pItem)
{
    int nSkillId = -1;
    if (ITEMSIsA(pItem, 0x12))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFA4);
        nSkillId = pBooksTxtRecord->dwBookSkillId;
    }
    else if (ITEMSIsA(pItem, 0x16))
    {
        D2BooksTxt* pBooksTxtRecord = DATATBLS_GetBooksTxtRecord(ITEMS_GetSuffixId(pItem, 0));
        D2_ASSERT(pBooksTxtRecord, 0xFAB);
        nSkillId = pBooksTxtRecord->dwScrollSkillId;
    }

    return nSkillId;
}

// 0x0055E0D0
static void __stdcall ITEMMODE_DecrementBookScrollSkillQuantity(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        int nQuantity = SKILLS_GetQuantity(pSkill) - 1;
        if (nQuantity <= 0)
        {
            if (UNITS_GetRightSkill(pUnit) == pSkill)
            {
                D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_ATTACK, -1);
            }
            nQuantity = 0;
        }

        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitId = UNITS_GetUnitId(pUnit);
        const int nUnitType = sub_0044BE50_Inline(pUnit);
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(sub_005531C0_MakeQuantityPacket(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xFC2, nUnitId, nSkillId, nQuantity), nUnitType);
    }
    else
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xFC4);
        exit(-1);
    }
}

// 0x00561E70
void __fastcall ITEMMODE_RemoveBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 3988);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, ITEMACTION_FLAG_BELT, 1);
    D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(pClient, pUnit, pItem, nFlags);
    ITEMMODE_RemoveInventoryItemFromAllPlayers(pGame, pUnit, pItem);
}

// 0x0055E170
int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* ptGame, D2UnitStrc* hUnit, int itemId, int x, int y, int* status)
{
    D2_ASSERT(ptGame, 0x105A);
    D2_ASSERT(hUnit, 0x105B);
    *status = 0;
    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1060);
    D2UnitStrc* item = SUNIT_GetServerUnit(ptGame, 4, itemId);
    if (!item) { *status = 1; return 0; }
    if (item->dwUnitType != UNIT_ITEM || INVENTORY_GetCursorItem(UNITS_GetInventory(hUnit))) return 0;
    if (item->dwAnimMode || !ITEMS_CheckIfUseable(item)) { *status = 1; return 0; }
    if (ITEMS_GetItemType(item) == ITEMTYPE_BOOK && STATLIST_UnitGetStatValue(item, STAT_QUANTITY, 0) <= 0) return 0;
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(ptGame, hUnit, 1)) return 0;
    if (SKILLITEM_pSpell_Handler(ptGame, hUnit, item, item, x, y)) {
        if (ITEMS_GetItemType(item) == ITEMTYPE_BOOK) {
            int skillId = ITEMMODE_GetBookOrScrollSkillId(item);
            if (skillId != -1 && STATLIST_UnitGetStatValue(item, STAT_QUANTITY, 0) > 0) {
            STATLIST_AddUnitStat(item, STAT_QUANTITY, -1, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10B2), item, 1, 70, STATLIST_UnitGetStatValue(item, STAT_QUANTITY, 0), 0);
            int id = item->dwUnitId;
            int type = item->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10B3), 0x7C, type, id);
            sub_0055E0D0_DecrementBook(hUnit, skillId);
            return 1;
            }
        } else {
        int skillId = ITEMMODE_GetBookOrScrollSkillId(item);
        if (skillId != -1) {
            D2SkillStrc* skill = SKILLS_GetSkillById(hUnit, skillId, -1);
            if (skill) {
                int quantity = SKILLS_GetQuantity(skill) - 1;
                if (quantity <= 0) {
                    if (UNITS_GetRightSkill(hUnit) == skill) D2GAME_AssignSkill_6FD13800(hUnit, 0, SKILL_ATTACK, -1);
                    quantity = 0;
                }
                SKILLS_SetQuantity(skill, quantity);
                int id = hUnit->dwUnitId;
                int type = hUnit->dwUnitType;
                D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10C6), type, id, skillId, quantity);
            }
        }
        ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10C9);
        ITEMMODE_RemoveItemAndNotify(ptGame, hUnit, item);
        }
        return 1;
    }
    D2ItemsTxt* record = DATATBLS_GetItemsTxtRecord(UNITS_GetWeaponClass(item));
    D2BitBufferStrc* flags = sub_00543520(ptGame, hUnit);
    if (record->dwCode == 0x20737361) {
        ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10D5);
        if (QUESTRECORD_GetQuestState(flags, 9, 5)) {
            QUESTRECORD_ClearQuestState(flags, 9, 5);
            STATLIST_AddUnitStat(hUnit, STAT_SKILLPTS, 1, 0);
            QUESTS_SendLogUpdate(hUnit, 8);
            ITEMMODE_RemoveItemAndNotify(ptGame, hUnit, item);
            return 1;
        }
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 1;
    }
    if (record->dwCode == 0x207A7978) {
        ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10E5);
        if (QUESTRECORD_GetQuestState(flags, 20, 5)) {
            QUESTRECORD_ClearQuestState(flags, 20, 5);
            STATLIST_AddUnitStat(hUnit, STAT_MAXHP, 0x1400, 0);
            QUESTS_SendLogUpdate(hUnit, 18);
            ITEMMODE_RemoveItemAndNotify(ptGame, hUnit, item);
            return 1;
        }
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 1;
    }
    if (record->dwCode == 0x20327274) {
        ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x10F8);
        if (QUESTRECORD_GetQuestState(flags, 37, 8) && !QUESTRECORD_GetQuestState(flags, 37, 7)) {
            QUESTRECORD_SetQuestState(flags, 37, 7);
            ACT5Q3_ApplyResistanceReward(ptGame, hUnit);
            QUESTS_SendLogUpdate(hUnit, 33);
            ITEMMODE_RemoveItemAndNotify(ptGame, hUnit, item);
            return 1;
        }
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 1;
    }
    if (record->dwCode == 0x20616F74) {
        ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x110D);
        SKILLS_ResetSkillsAndRefundPoints(ptGame, hUnit);
        sub_00570C80_PLAYERSTATS_ResetToBaseStats(ptGame, hUnit);
        ITEMMODE_RemoveItemAndNotify(ptGame, hUnit, item);
        SUNIT_AttachSound(hUnit, 2, hUnit);
        return 1;
    }
    return 0;
}

// 0x0055E590
static void __stdcall ITEMMODE_MergeStacks(D2GameStrc* pGame, D2UnitStrc* pItem1, D2UnitStrc* pUnit, D2UnitStrc* pItem2)
{
    D2InventoryStrc* pInventory;
    int nSrcValue;
    int nDstValue;
    int nMaxStack;
    int nQuantity;
    int nRemaining;
    int bRemoveSource;

    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return;
    }

    pInventory = pUnit->pInventory;
    nSrcValue = STATLIST_UnitGetStatValue(pItem1, STAT_QUANTITY, 0);
    D2_ASSERT(nSrcValue >= 0, 0x114B);

    nDstValue = STATLIST_UnitGetStatValue(pItem2, STAT_QUANTITY, 0);
    D2_ASSERT(nDstValue >= 0, 0x114D);

    nMaxStack = ITEMS_GetTotalMaxStack(pItem2);
    D2_ASSERT(nMaxStack >= 0, 0x114F);

    nQuantity = nSrcValue + nDstValue;
    bRemoveSource = 1;
    if (nQuantity > nMaxStack)
    {
        STATLIST_SetUnitStat(pItem2, STAT_QUANTITY, nMaxStack, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1155), pItem2, 1, 0x46, nMaxStack, 0);

        nRemaining = nDstValue - nMaxStack + nSrcValue;
        bRemoveSource = 0;
        D2_ASSERT(nRemaining >= 0, 0x1158);

        STATLIST_SetUnitStat(pItem1, STAT_QUANTITY, nRemaining, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x115B), pItem1, 1, 0x46, nRemaining, 0);

        if (ITEMS_GetItemType(pItem1) == ITEMTYPE_BOOK && ITEMS_GetItemType(pItem2) == ITEMTYPE_BOOK)
        {
            ITEMMODE_AddBookScrollSkillQuantity(ITEMS_GetTotalMaxStack(pItem2) - nDstValue, pUnit, pItem2);
        }
    }
    else
    {
        if (ITEMS_HasDurability(pItem1))
        {
            const int nDurability = STATLIST_UnitGetStatValue(pItem1, STAT_DURABILITY, 0);
            if (nDurability < STATLIST_UnitGetStatValue(pItem2, STAT_DURABILITY, 0))
            {
                STATLIST_SetUnitStat(pItem2, STAT_DURABILITY, nDurability, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1170), pItem2, 1, 0x48, nDurability, 0);
            }
        }

        D2_ASSERT(nQuantity >= 0, 0x1176);

        STATLIST_SetUnitStat(pItem2, STAT_QUANTITY, nQuantity, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1179), pItem2, 1, 0x46, nQuantity, 0);

        if (ITEMS_GetItemType(pItem1) == ITEMTYPE_BOOK && ITEMS_GetItemType(pItem2) == ITEMTYPE_BOOK)
        {
            ITEMMODE_AddBookScrollSkillQuantity(nSrcValue, pUnit, pItem2);
        }
    }

    if (bRemoveSource)
    {
        INVENTORY_SetCursorItem(pInventory, 0);
        D2GAME_PACKETS_SendPacket0x42_6FC3EE40(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1184), pUnit);
        ITEMS_RemoveFromAllPlayers(pGame, pItem1);
    }
    else
    {
        ITEMS_SetItemFlag(pItem2, 8, 1);
    }
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x0055E7C0
int __fastcall ITEMMODE_MergeItemStacks(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID1, int nItemGUID2, int* pItemStatus)
{
    D2_ASSERT(pGame, 0x1192);
    D2_ASSERT(pUnit, 0x1193);

    *pItemStatus = 0;
    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1198);

    if (nItemGUID1 == nItemGUID2)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2UnitStrc* pItem1 = SUNIT_GetServerUnit(pGame, 4, nItemGUID1);
    if (!pItem1)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem1->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2UnitStrc* pItem2 = SUNIT_GetServerUnit(pGame, 4, nItemGUID2);
    if (!pItem2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem2->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (ITEMS_GetInvPage(pItem2) == 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (!ITEMS_AreStackablesEqual(pItem1, pItem2))
    {
        return 0;
    }

    const int nClassId1 = pItem1->dwClassId;
    _ReadWriteBarrier();
    const int nClassId2 = pItem2->dwClassId;
    _ReadWriteBarrier();
    if (nClassId1 != nClassId2)
    {
        return 1;
    }

    ITEMMODE_MergeStacks(pGame, pItem1, pUnit, pItem2);
    ITEMS_SetItemCMDFlag(pItem2, 0x100, 1);
    INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem2);
    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}

// 0x0055E8E0
static void __stdcall ITEMMODE_InitItemDropFromItem(int nId, D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    memset(pItemDrop, 0, sizeof(D2ItemDropStrc));
    pItemDrop->pGame = pGame;
    pItemDrop->nItemLvl = ITEMS_GetItemLevel(pItem);
    pItemDrop->wItemFormat = pGame->wItemFormat;
    pItemDrop->nId = nId;
    pItemDrop->nSpawnType = 4;
    pItemDrop->nX = sub_E03_ItemGetUnitX(pItem);
    pItemDrop->nY = sub_E03_ItemGetUnitY(pItem);
    pItemDrop->pSeed = &pItem->pSeed;
    pItemDrop->wUnitInitFlags = 1;
    pItemDrop->nQuality = 2;
    pItemDrop->dwSeed = pItem->dwInitSeed;
    const unsigned int nItemSeed = ITEMS_GetItemStartSeed(pItem);
    pItemDrop->nItemIndex = 2;
    pItemDrop->dwItemSeed = nItemSeed;
}

// 0x0055E9A0
int __stdcall sub_0055E9A0(int nUnused1, int nUnused2)
{
    return 0;
}

int __fastcall ITEMMODE_CheckAndResolveBodySlotPair(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc** ppPrimary, D2UnitStrc** ppOther, int* pBodyLoc)
{
    if (!pUnit || !pItem || GetUnitType(pItem) != 4) return 0;
    D2UnitStrc* pPrimary = *ppPrimary;
    if (pPrimary)
    {
        if (*ppOther) return 0;
    }
    else if (!*ppOther) return 1;
    int nOpposite = ITEMMODE_GetOppositeBodyLoc(*pBodyLoc);
    if (pPrimary)
    {
        *ppPrimary = *ppOther;
        *ppOther = pPrimary;
        *pBodyLoc = nOpposite;
    }
    switch (*pBodyLoc)
    {
    case 4: case 5: case 11: case 12:
        if (ITEMS_GetAmmoType(pItem) > 0)
        {
            if (!*ppOther) return 1;
            return ITEMSIsA(*ppOther, ITEMS_GetAmmoType(pItem)) != 0;
        }
        if (ITEMS_GetQuiverType(pItem))
        {
            if (!*ppOther) return 1;
            if (ITEMS_GetAmmoType(*ppOther) <= 0) return 0;
            return ITEMSIsA(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        }
        if (ITEMS_GetAmmoType(*ppOther) > 0) return ITEMSIsA(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        if (ITEMS_GetQuiverType(*ppOther) > 0) return ITEMSIsA(pItem, ITEMS_GetQuiverType(*ppOther)) != 0;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem) && !ITEMS_Is1Or2Handed(pUnit, pItem)) return 0;
        if (ITEMS_CheckWeaponIfTwoHanded(*ppOther) && !ITEMS_Is1Or2Handed(pUnit, *ppOther)) return 0;
        {
            int bItemWeapon = ITEMSIsA(pItem, 45);
            int bOtherWeapon = ITEMSIsA(*ppOther, 45);
            if (bItemWeapon)
            {
                if (bOtherWeapon)
                {
                    if (GetUnitType(pUnit) == 1) return 1;
                    switch (pUnit->dwClassId)
                    {
                    case 4: return 1;
                    case 6:
                        if (ITEMSIsA(pItem, 67) && ITEMSIsA(*ppOther, 67)) return 1;
                        return 0;
                    default: return 0;
                    }
                }
            }
            else if (!bOtherWeapon) return 0;
            return *ppPrimary == 0;
        }
    default: return *ppPrimary == 0;
    }
}

// 0x0055E9B0
int __fastcall ITEMMODE_PlaceCursorItemInBelt(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nBeltSlot, int bFindFreeSlot, int* a6)
{
    D2_ASSERT(ptGame, 0x11FB);
    D2_ASSERT(hUnit, 0x11FC);

    *a6 = 0;

    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1201);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        *a6 = 1;
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_ONCURSOR)
    {
        *a6 = 1;
        return 0;
    }

    do
    {
        if (!ITEMS_CheckIfBeltable(pItem))
        {
            break;
        }

        D2InventoryStrc* pInventory = hUnit->pInventory;
        if (bFindFreeSlot)
        {
            if (!INVENTORY_PlaceItemInFreeBeltSlot(pInventory, pItem))
            {
                break;
            }
        }
        else
        {
            unsigned char nWidth;
            unsigned char nHeight;
            ITEMS_GetDimensions(pItem, &nWidth, &nHeight, ".\\ITEMS\\ItemMode.cpp", 0x1222);

            if (!INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, nBeltSlot))
            {
                break;
            }

            ITEMS_SetInvPage(pItem, INVPAGE_NULL);
        }

        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 2))
        {
            INVENTORY_SetCursorItem(pInventory, 0);
            ITEMMODE_AddItemScrollSkillQuantity(hUnit, pItem);

            pItem->dwFlags &= ~UNITFLAG_TARGETABLE;

            if (ITEMS_IsCharmUsable(pItem, hUnit))
            {
                sITEMSAddStatsList(ptGame, pItem, hUnit, 0);
            }

            UNITS_ChangeAnimMode(pItem, IMODE_INBELT);
            ITEMS_SetInvPage(pItem, INVPAGE_NULL);
            ITEMS_SetItemCMDFlag(pItem, 0x400, 1);
            UNITS_RefreshInventory(hUnit, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            return 1;
        }

        *a6 = 1;
    }
    while (0);

    return 0;
}

// 0x0055EB30
int __fastcall ITEMMODE_SwapCursorAndBeltItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nBeltItemGUID, int* a5)
{
    D2_ASSERT(ptGame, 0x128A);
    D2_ASSERT(pUnit, 0x128B);

    *a5 = 0;

    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1290);

    D2UnitStrc* pCursorItem = SUNIT_GetServerUnit(ptGame, 4, nCursorItemGUID);
    if (!pCursorItem || pCursorItem->dwUnitType != UNIT_ITEM || pCursorItem->dwAnimMode != IMODE_ONCURSOR || !ITEMS_CheckIfBeltable(pCursorItem))
    {
        return 0;
    }

    D2UnitStrc* pBeltItem = SUNIT_GetServerUnit(ptGame, 4, nBeltItemGUID);
    if (!pBeltItem || pBeltItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    const int nBeltItemMode = pBeltItem ? pBeltItem->dwAnimMode : 0;
    if (nBeltItemMode != 2)
    {
        *a5 = 1;
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, pBeltItem);
    D2_ASSERT(hRemove, 0x12B8);
    D2_ASSERT(pBeltItem == hRemove, 0x12B9);

    D2COMMON_10267_Return(pInventory, CLIENTS_GetUnitX(pBeltItem));
    INVENTORY_SetCursorItem(pInventory, pBeltItem);
    ITEMMODE_RemoveItemScrollSkillQuantity(pUnit, pBeltItem);

    pBeltItem->dwFlags &= ~2;

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, pBeltItem, pUnit, 0, 1);
    UNITS_ChangeAnimMode(pBeltItem, 4);
    ITEMS_SetItemCMDFlag(pBeltItem, 0x1000, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pBeltItem);
    if (INVENTORY_PlaceItemInBeltSlot(pInventory, pCursorItem, CLIENTS_GetUnitX(pBeltItem)))
    {
        UNITS_SetXForStaticUnit(pCursorItem, CLIENTS_GetUnitX(pBeltItem));
        UNITS_SetYForStaticUnit(pCursorItem, 0);
        if (INVENTORY_PlaceItemInSocket(pInventory, pCursorItem, 2))
        {
            ITEMMODE_AddItemScrollSkillQuantity(pUnit, pCursorItem);

            pCursorItem->dwFlags &= ~2;

            if (ITEMS_IsCharmUsable(pCursorItem, pUnit))
            {
                sITEMSAddStatsList(ptGame, pCursorItem, pUnit, 0);
            }

            UNITS_ChangeAnimMode(pCursorItem, 2);
            ITEMS_SetInvPage(pCursorItem, 0xFF);
            ITEMS_SetItemCMDFlag(pCursorItem, 0x1000, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pCursorItem);
            ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
            return 1;
        }

        D2_ASSERT(0, 0x12D4);
    }

    D2_ASSERT(0, 0x12D8);
}

// 0x0055ED30
void __fastcall ITEMMODE_RemoveInventoryItemFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* hItem)
{
    if (hItem)
    {
        hItem->dwFlags &= ~UNITFLAG_TARGETABLE;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hItem);
    D2_ASSERT(hRemove, 4841);
    D2_ASSERT(hItem == hRemove, 4842);

    int nX;
    switch (hItem->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = hItem->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (hItem->pDynamicPath)
        {
            nX = PATH_GetXPosition(hItem->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }

    D2COMMON_10267_Return(pInventory, nX);
    ITEMS_RemoveFromAllPlayers(pGame, hItem);
}

// 0x0055EEA0
int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pItem || INVENTORY_GetCursorItem(pInventory) != pItem)
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\ITEMS\\ItemMode.cpp", 0x139A);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    D2GAME_PACKETS_SendPacket0x42_6FC3EE40(pClient, pPlayer);
    INVENTORY_SetCursorItem(pInventory, 0);
    ITEMS_RemoveFromAllPlayers(pGame, pItem);
    return 1;
}

// 0x0055EF20
int __fastcall ITEMMODE_AddScrollToBook(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nScrollGUID, int nBookGUID, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0x144E);
    D2_ASSERT(hUnit, 0x144F);

    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1452);

    *pItemStatus = 0;

    D2UnitStrc* pScroll = SUNIT_GetServerUnit(ptGame, 4, nScrollGUID);
    if (!pScroll)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pScroll->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pScroll->dwAnimMode != IMODE_ONGROUND && pScroll->dwAnimMode != IMODE_ONCURSOR || !ITEMSIsA(pScroll, 0x16))
    {
        *pItemStatus = 1;
        return 0;
    }

    D2UnitStrc* pBook = SUNIT_GetServerUnit(ptGame, 4, nBookGUID);
    if (!pBook)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pBook->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pBook->dwAnimMode != IMODE_STORED || ITEMS_GetItemType(pBook) != ITEMTYPE_BOOK)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2InventoryStrc* hInventory = hUnit->pInventory;
    D2_ASSERT(hInventory, 0x1481);

    if (ITEMS_GetSuffixId(pScroll, 0) == ITEMS_GetSuffixId(pBook, 0))
    {
        if (STATLIST_UnitGetStatValue(pBook, STAT_QUANTITY, 0) >= ITEMS_GetTotalMaxStack(pBook))
        {
            return 0;
        }

        if (!D2GAME_RemoveItemIfOnCursor_6FC49760(ptGame, hUnit, pScroll))
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pScroll);
            if (pRoom)
            {
                DUNGEON_AllocDrlgDelete(pRoom, pScroll->dwUnitType, pScroll->dwUnitId);
                UNITS_FreeCollisionPath(pScroll);
                UNITROOM_RemoveUnitFromRoom(pScroll);
            }

            pScroll->dwFlags &= ~2;
            ITEMS_RemoveFromAllPlayers(ptGame, pScroll);
            INVENTORY_SetCursorItem(hInventory, 0);
        }

        STATLIST_AddUnitStat(pBook, STAT_QUANTITY, 1, 0);
        D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1494), pBook, 1, 0x46, STATLIST_UnitGetStatValue(pBook, STAT_QUANTITY, 0), 0);
        ITEMMODE_AddBookScrollSkillQuantity(1, hUnit, pBook);
        return 1;
    }

    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x149C);
    exit(-1);
}

// 0x0055F120
void __cdecl ITEMMODE_EventFn4_Return()
{
}

// 0x0055F130
void __fastcall ITEMMODE_UpdateItemStatListExpiration(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}

// 0x00562C40
static int __stdcall ITEMMODE_ReplenishItemStat(D2GameStrc* pGame, D2UnitStrc* pItem, int nLengthStatId, int nValueStatId, int nMaxValue)
{
    const int nLength = STATLIST_UnitGetStatValue(pItem, nLengthStatId, 0);
    if (!nLength)
    {
        return 0;
    }

    const int nValue = STATLIST_UnitGetStatValue(pItem, nValueStatId, 0) + 1;
    if (nValue > nMaxValue)
    {
        return 1;
    }

    STATLIST_SetUnitStat(pItem, nValueStatId, nValue, 0);

    const int nOwnerGUID = ITEMS_GetOwnerId(pItem);
    if (nOwnerGUID != -1)
    {
        D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
        if (pOwner)
        {
            D2ClientStrc* pClient = UnitGetClient(pOwner, ".\\ITEMS\\ItemMode.cpp", 5504);
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(pClient, pItem, 1, nValueStatId, nValue, 0);
                if (nValue >= 1)
                {
                    if (ITEMS_CheckItemFlag(pItem, IFLAG_BROKEN, 5510, ".\\ITEMS\\ItemMode.cpp"))
                    {
                        D2GAME_RepairBrokenItem_6FC4B630(pGame, pOwner, pItem);
                    }
                }
            }
        }
    }

    int nDuration = 2500 / nLength + 1;
    if (nDuration < 125)
    {
        nDuration = 125;
    }

    EVENT_SetEvent(pGame, pItem, EVENTTYPE_STATREGEN, pGame->dwGameFrame + nDuration, 0, 0);

    return 1;
}

// 0x00562D30
void __fastcall ITEMMODE_ReplenishItem(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!ITEMS_CheckItemFlag(pUnit, IFLAG_BROKEN, 5542, ".\\ITEMS\\ItemMode.cpp") && ITEMS_HasDurability(pUnit) && ITEMMODE_ReplenishItemStat(pGame, pUnit, STAT_ITEM_REPLENISH_DURABILITY, STAT_DURABILITY, STATLIST_GetMaxDurabilityFromUnit(pUnit)))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pUnit))
    {
        ITEMMODE_ReplenishItemStat(pGame, pUnit, STAT_ITEM_REPLENISH_QUANTITY, STAT_QUANTITY, ITEMS_GetTotalMaxStack(pUnit));
    }
}

typedef int (__stdcall* FARPROC)();

typedef void (__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern EventCallbackFunction gpfnItemEventFunctions[15]; // 0x006E117C

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

// 0x00562DA0
void __fastcall D2GAME_Items_EventsHandler_6FC4A460(D2GameStrc* pGame, D2UnitStrc* pUnit, int eEventType)
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnItemEventFunctions[eEventType]), 5610);
    gpfnItemEventFunctions[eEventType](pGame, pUnit);
}

// 0x0055F140
int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* ptGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(ptGame, 0x15F3);
    D2_ASSERT(hUnit, 0x15F4);

    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x15F7);

    D2InventoryStrc* pInventory = hUnit->pInventory;
    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(i);
        if (ITEMSIsA(pItem, 0x29) && !ITEMS_GetInventoryPage(pItem))
        {
            if (STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) - 1 > 0)
            {
                STATLIST_AddUnitStat(pItem, STAT_QUANTITY, -1, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x1605), pItem, 1, 0x46, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0), 0);
            }
            else
            {
                ITEMMODE_RemoveItemAndNotify(ptGame, hUnit, pItem);
            }

            return 1;
        }
    }

    return 0;
}

// 0x0055F240
int __fastcall ITEMMODE_GetOppositeBodyLoc(int nBodyLoc)
{
    switch (nBodyLoc)
    {
    case 4:
        return 5;
    case 5:
        return 4;
    case 6:
        return 7;
    case 7:
        return 6;
    case 11:
        return 12;
    case 12:
        return 11;
    }

    return 0;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

// 0x0055F2A0
D2UnitStrc* __fastcall ITEMMODE_GetItemFromOppositeBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pDefault, int nBodyLoc)
{
    const int nOpposite = ITEMMODE_GetOppositeBodyLoc(nBodyLoc);
    if (!nOpposite)
    {
        return pDefault;
    }
    return INVENTORY_GetItemFromBodyLoc(pInventory, nOpposite);
}

// 0x00564CA0
extern "C" __declspec(dllexport) int __cdecl sub_00564CA0() {
    return 1;
}

void __fastcall MONSTER_DeleteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005738D0
// 0x00604A30
void __stdcall TileSetHardwareFreeCallback(void* pfnCallback)
{
    D2CMPTileCacheSetFreeCallback(pfnCallback);
}

// 0x0055F2D0
int __fastcall ITEMMODE_ResolveBodySlotPair(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc** ppPrimary, D2UnitStrc** ppOther, int* pBodyLoc)
{
    if (!pUnit || !pItem || GetUnitType(pItem) != 4) return 0;
    D2UnitStrc* pPrimary = *ppPrimary;
    if (pPrimary)
    {
        if (*ppOther) return 0;
    }
    else if (!*ppOther) return 1;
    int nOpposite = ITEMMODE_GetOppositeBodyLoc(*pBodyLoc);
    if (pPrimary)
    {
        *ppPrimary = *ppOther;
        *ppOther = pPrimary;
        *pBodyLoc = nOpposite;
    }
    switch (*pBodyLoc)
    {
    case 4: case 5: case 11: case 12:
        if (ITEMS_GetAmmoType(pItem) > 0)
        {
            if (!*ppOther) return 1;
            return ITEMSIsA(*ppOther, ITEMS_GetAmmoType(pItem)) != 0;
        }
        if (ITEMS_GetQuiverType(pItem))
        {
            if (!*ppOther) return 1;
            if (ITEMS_GetAmmoType(*ppOther) <= 0) return 0;
            return ITEMSIsA(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        }
        if (ITEMS_GetAmmoType(*ppOther) > 0) return ITEMSIsA(pItem, ITEMS_GetAmmoType(*ppOther)) != 0;
        if (ITEMS_GetQuiverType(*ppOther) > 0) return ITEMSIsA(pItem, ITEMS_GetQuiverType(*ppOther)) != 0;
        if (ITEMS_CheckWeaponIfTwoHanded(pItem) && !ITEMS_Is1Or2Handed(pUnit, pItem)) return 0;
        if (ITEMS_CheckWeaponIfTwoHanded(*ppOther) && !ITEMS_Is1Or2Handed(pUnit, *ppOther)) return 0;
        {
            int bItemWeapon = ITEMSIsA(pItem, 45);
            int bOtherWeapon = ITEMSIsA(*ppOther, 45);
            if (bItemWeapon)
            {
                if (bOtherWeapon)
                {
                    if (GetUnitType(pUnit) == 1) return 1;
                    switch (pUnit->dwClassId)
                    {
                    case 4: return 1;
                    case 6:
                        if (ITEMSIsA(pItem, 67) && ITEMSIsA(*ppOther, 67)) return 1;
                        return 0;
                    default: return 0;
                    }
                }
            }
            else if (!bOtherWeapon) return 0;
            return *ppPrimary == 0;
        }
    default: return *ppPrimary == 0;
    }
}

// 0x0055F4F0
void __stdcall sub_0055F4F0(int nUnused1)
{
}

static __forceinline int PlaceIntoInventory(Game* game, Unit* player, int itemId, int line)
{
        if (!game) return 0;
        {
            ITEMMODE_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x87B);
            Unit* placed = SUNIT_GetServerUnit(game, 4, itemId);
            if (!placed || placed->type != 4 || placed->mode != 4) return 0;
            {
                unsigned char targetPage = sub_00628250_Page(placed);
                void* targetInventory = player->inventory;
                if (!targetInventory) return 0;
                int special = 0;
                int clearCursor = 1;
                int targetGrid = sub_00621050_Grid(player, targetPage, game->expansion);
                if (player->type == 0) {
                    switch (targetPage) {
                    case 1: clearCursor = 0; break;
                    case 2: special = 1; break;
                    }
                }
                if (!INVENTORY_PlaceItemAtFreePosition(targetInventory, placed, targetGrid, 0, targetPage, ".\\ITEMS\\ItemMode.cpp", line)) return 0;
                if (!sub_0063B210_Add(targetInventory, placed, 1)) return 0;
                if (sub_00628250_Page(placed) != 4) ITEMMODE_AddItemScrollSkillQuantity(player, placed);
                placed->flags &= -3;
                if (sub_0062FF70_Check(placed, player)) sITEMSAddStatsList(game, placed, player, 0);
                if (clearCursor) sub_0063C180_Cursor(targetInventory, 0);
                sub_00624690_Mode(placed, 0);
                sub_00628170_CommandFlag(placed, 2, 1);
                if (D2GAME_CheckHasFilledSockets((D2UnitStrc*)placed, ".\\ITEMS\\ItemMode.cpp", 0x8EA)) ITEMS_SetItemFlag(placed, 1, 1);
                if (sub_006280A0_TestFlag(placed, 0x4000, 0x8EE, ".\\ITEMS\\ItemMode.cpp")) ITEMS_SetItemFlag(placed, 0x4000, 0);
                sub_00621000_SetFlag(player, 1);
                sub_0063CC70_Refresh(targetInventory, placed);
                if (special == 1) PLRTRADE_AddItemToTrade(game, player, placed);
                if (sub_0062FF70_Check(placed, player)) {
                    sub_0055DBC0_Refresh(game, player, 0);
                    sub_00621000_SetFlag(player, 1);
                }
                return 1;
            }
        }
}

// 0x00563840
static void __stdcall ITEMMODE_MoveCubeContentsToInventory(Game* game, Unit* box, Unit* player)
{
    int classId;
    if (!box) classId = -1;
    else classId = box->classId;
    ItemRecord* record = sub_006335F0_Record(classId);
    D2_ASSERT(record, 0x7FF);
    if (record->code != 0x20786F62) return;
    void* inventory = player->inventory;
    Unit* node = sub_0063B2C0_First(inventory);
    while (node) {
        Unit* item = sub_0063DFD0_Item(node);
        Unit* next = sub_0063DFA0_Next(node);
        if (sub_00628250_Page(item) == 3) {
            unsigned int flags = 0;
            ITEMS_SetOrRemoveFlag(&flags, 32, 1);
            ITEMS_SetItemCell(box, 3);
            D2GAME_UpdateClientItem_6FC3E9D0(sub_005531C0_Client(player, ".\\ITEMS\\ItemMode.cpp", 0x80D), player, item, flags);
            Unit* removed = sub_0063AD90_Remove(inventory, item);
            D2_ASSERT(removed, 0x80F);
            D2_ASSERT(item == removed, 0x810);
            unsigned char page = sub_00628250_Page(item);
            int grid = sub_00621050_Grid(player, page, game->expansion);
            int y;
            switch (item->type) {
            case 2: case 4: case 5: y = item->path->y; break;
            default: y = item->path ? sub_00648900_Y(item->path) : 0; break;
            }
            int x;
            switch (item->type) {
            case 2: case 4: case 5: x = item->path->x; break;
            default: x = item->path ? sub_006488C0_X(item->path) : 0; break;
            }
            INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0x813, inventory, x, y, grid, 0, page);
            sub_00624690_Mode(removed, 4);
            ITEMS_SetInvPage(item, 0);
            int itemId = item->id;
            ITEMMODE_ClearTargetingFlags(player, ".\\ITEMS\\ItemMode.cpp", 0x87B);
            Unit* placed = SUNIT_GetServerUnit(game, 4, itemId);
            if (!placed || placed->type != 4 || placed->mode != 4) goto dropFailure;
            {
                unsigned char targetPage = sub_00628250_Page(placed);
                void* targetInventory = player->inventory;
                if (!targetInventory) goto dropFailure;
                int special = 0;
                int clearCursor = 1;
                int targetGrid = sub_00621050_Grid(player, targetPage, game->expansion);
                if (player->type == 0) {
                    switch (targetPage) {
                    case 1: clearCursor = 0; break;
                    case 2: special = 1; break;
                    }
                }
                if (!INVENTORY_PlaceItemAtFreePosition(targetInventory, placed, targetGrid, 0, targetPage, ".\\ITEMS\\ItemMode.cpp", 0x817)) goto dropFailure;
                if (!sub_0063B210_Add(targetInventory, placed, 1)) goto dropFailure;
                if (sub_00628250_Page(placed) != 4) ITEMMODE_AddItemScrollSkillQuantity(player, placed);
                placed->flags &= -3;
                if (sub_0062FF70_Check(placed, player)) sITEMSAddStatsList(game, placed, player, 0);
                if (clearCursor) sub_0063C180_Cursor(targetInventory, 0);
                sub_00624690_Mode(placed, 0);
                sub_00628170_CommandFlag(placed, 2, 1);
                if (D2GAME_CheckHasFilledSockets((D2UnitStrc*)placed, ".\\ITEMS\\ItemMode.cpp", 0x8EA)) ITEMS_SetItemFlag(placed, 1, 1);
                if (sub_006280A0_TestFlag(placed, 0x4000, 0x8EE, ".\\ITEMS\\ItemMode.cpp")) ITEMS_SetItemFlag(placed, 0x4000, 0);
                sub_00621000_SetFlag(player, 1);
                sub_0063CC70_Refresh(targetInventory, placed);
                if (special == 1) PLRTRADE_AddItemToTrade(game, player, placed);
                if (sub_0062FF70_Check(placed, player)) {
                    sub_0055DBC0_Refresh(game, player, 0);
                    sub_00621000_SetFlag(player, 1);
                }
                goto nextItem;
            }
        dropFailure:
            ITEMS_SetInvPage(item, 255);
            Point playerPosition;
            Point dropPosition;
            sub_00620870_Position(player, &playerPosition);
            void* room = D2GAME_GetFreeSpaceEx_6FC4BF00(sub_00620BB0_Room(player), &playerPosition, &dropPosition, 1, 1);
            if (!room) continue;
            D2GAME_DropItem_6FC52260(game, player, item, room, dropPosition.x, dropPosition.y);
        }
    nextItem:
        node = next;
    }
}

// 0x00563C00
extern "C" void __fastcall ITEMMODE_DropCursorItem(Game* ptGame, Unit* hUnit, int itemId)
{
    D2_ASSERT(ptGame, 0x833);
    D2_ASSERT(hUnit, 0x834);
    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x837);
    Unit* item = SUNIT_GetServerUnit(ptGame, 4, itemId);
    if (!item || item->type != 4 || item->mode != 4) return;
    Point playerPosition;
    Point dropPosition;
    sub_00620870_Position(hUnit, &playerPosition);
    void* room = D2GAME_GetFreeSpaceEx_6FC4BF00(sub_00620BB0_Room(hUnit), &playerPosition, &dropPosition, 1, 1);
    if (!room) return;
    D2GAME_DropItem_6FC52260(ptGame, hUnit, item, room, dropPosition.x, dropPosition.y);
    sub_0063C180_Cursor(hUnit->inventory, 0);
    if (D2GAME_CheckHasFilledSockets((D2UnitStrc*)item, ".\\ITEMS\\ItemMode.cpp", 0x85B)) ITEMS_SetItemFlag(item, 1, 1);
    if (sub_006280A0_TestFlag(item, 0x4000, 0x85E, ".\\ITEMS\\ItemMode.cpp")) ITEMS_SetItemFlag(item, 0x4000, 0);
    ITEMMODE_MoveCubeContentsToInventory(ptGame, item, hUnit);
}

// 0x00560CD0
int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0xC44);
    D2_ASSERT(pUnit, 0xC45);

    *pItemStatus = 0;

    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 0xC4A);

    if (INVENTORY_GetCursorItem(hInventory))
    {
        return 0;
    }

    D2UnitStrc* hItem = INVENTORY_GetItemFromBodyLoc(hInventory, nBodyLoc);
    if (!hItem)
    {
        *pItemStatus = 0;
        return 0;
    }

    const int nItemType = hItem ? hItem->dwUnitType : UNIT_INVALID;
    if (nItemType != ITEMTYPE_GOLD)
    {
        return 0;
    }

    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xC64);

    const int nResult = D2Common_10299(pUnit, nBodyLoc, 0, 0);
    if (nResult != 3 && nResult != 4)
    {
        *pItemStatus = 1;
        return 0;
    }

    INVENTORY_GetSecondWieldingWeapon(pUnit, hInventory, &hItem, nBodyLoc);
    if (!hItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2COMMON_11079_Return0(pUnit, hItem);
    INVENTORY_UpdateWeaponGUIDOnRemoval(hInventory, hItem);
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(hInventory, hItem);

    D2_ASSERT(hRemove, 0xC76);
    D2_ASSERT(hItem == hRemove, 0xC77);

    sub_0063BE30(hInventory, nBodyLoc);

    if (ITEMS_GetItemType(hRemove) == ITEMTYPE_BELT)
    {
        sub_6FC45930(ptGame, pUnit, 0);
    }

    if (bSetQuantityFlag)
    {
        ITEMS_SetItemFlag(hItem, 0x20, 1);
    }
    else
    {
        INVENTORY_SetCursorItem(hInventory, hItem);
    }

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, hItem, pUnit, 0, 1);

    if (hItem)
    {
        hItem->dwFlags &= ~2;
    }

    UNITS_ChangeAnimMode(hItem, 4);
    ITEMS_SetItemCMDFlag(hItem, 0x10, 1);

    if (D2GAME_CheckHasFilledSockets(hItem, ".\\ITEMS\\ItemMode.cpp", 0xC8B))
    {
        ITEMS_SetItemFlag(hItem, 1, 1);
    }

    if (ITEMS_CheckItemFlag(hItem, 0x4000, 0xC8E, ".\\ITEMS\\ItemMode.cpp"))
    {
        ITEMS_SetItemFlag(hItem, 0x4000, 0);
    }

    INVENTORY_AddItemToTradeInventory(hInventory, hItem);
    UNITS_RefreshInventory(pUnit, 1);
    ITEMMODE_RefreshSkillsForEquippedWeapons(pUnit);
    ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
    return 1;
}

static inline int UNIT_GetMode(D2UnitStrc* pUnit) { return !pUnit ? 0 : pUnit->dwAnimMode; }

// 0x00562660
int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSocketFillerGUID, int nItemGUID, int* bPlaced, int bRefresh, int bResetCursorItem, int bCheckMode, int a9)
{
    D2_ASSERT(pGame, 0x13A9);
    *bPlaced = 0;
    if (pUnit) ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x13B0);
    D2UnitStrc* pFiller = SUNIT_GetServerUnit(pGame, 4, nSocketFillerGUID);
    if (!pFiller)
    {
        *bPlaced = 1;
        return 0;
    }
    if (pFiller->dwUnitType != UNIT_ITEM) return 0;
    if (pFiller->dwAnimMode != IMODE_ONCURSOR)
    {
        *bPlaced = 1;
        return 0;
    }
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        *bPlaced = 1;
        return 0;
    }
    if (pItem->dwUnitType != UNIT_ITEM) return 0;
    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x13DB, ".\\ITEMS\\ItemMode.cpp")) return 0;
    if (bCheckMode && pItem->dwAnimMode != IMODE_STORED && pItem->dwAnimMode != IMODE_EQUIP) return 0;
    if (pFiller->dwUnitType != UNIT_ITEM || pItem->dwUnitType != UNIT_ITEM || !ITEMS_IsSocketFiller(pFiller)
        || !ITEMS_CheckItemFlag(pFiller, 0x10, 0x13EA, ".\\ITEMS\\ItemMode.cpp")
        || !ITEMS_CheckItemFlag(pItem, 0x800, 0x13EB, ".\\ITEMS\\ItemMode.cpp") || !ITEMS_CheckIfSocketable(pItem)) return 0;
    D2InventoryStrc* pInventory = pItem->pInventory;
    if (!pInventory)
    {
        pInventory = INVENTORY_AllocInventory(0, pItem);
        if (!pInventory) return 0;
    }
    const unsigned int nSockets = ITEMS_GetSockets(pItem);
    if (INVENTORY_GetItemCount(pInventory) >= nSockets) return 0;
    if (INVENTORY_PlaceItemInSocket(pInventory, pFiller, 1))
    {
    pFiller->dwFlags &= ~2u;
    if (bResetCursorItem && pUnit) INVENTORY_SetCursorItem(pUnit->pInventory, 0);
    sITEMSAddStatsList(pGame, pFiller, pItem, 0);
    D2Common_10525(pFiller, pItem);
    UNITS_ChangeAnimMode(pFiller, 6);
    const D2RunesTxt* pRunesTxt = ITEMS_GetRunesTxtRecordFromItem(pItem);
    if (pRunesTxt && ((pRunesTxt->nServer && pGame->dwGameType) || !pRunesTxt->nServer))
    {
        ITEMMODS_UpdateRuneword(pItem, pFiller, 0);
        ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
        ITEMS_ScheduleQuantityReplenishment(pGame, pItem);
        if (a9) D2GAME_RechargeItem_6FC4BD50(pGame, pUnit, pItem);
        bRefresh = 1;
    }
    if (bRefresh)
    {
        ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0x143A, ".\\ITEMS\\ItemMode.cpp")) ITEMS_SetItemFlag(pItem, 0x4000, 0);
        if (pUnit)
        {
            UNITS_RefreshInventory(pUnit, 1);
            INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
        }
    }
    return 1;
    }
    else
    {
        D2_ASSERT(0, 0x1444);
    }
}

static inline int SkillUsable(D2UnitStrc* player, D2SkillStrc* skill)
{
    if (!skill) return 0;
    switch (SKILLS_GetUseState(player, skill)) { case 2: case 7: return 0; }
    return 1;
}

// 0x0055FE80
int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pGame || !pItem || pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    D2ClientStrc* pClient = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 6809);
    }

    D2StatStrc stats[64];
    const int nStats = STATLIST_CopyStats(pItem, STAT_ITEM_CHARGED_SKILL, stats, 64);
    int bRecharged = 0;
    for (int i = 0; i < nStats; ++i)
    {
        const int nLayer = stats[i].nLayer;
        const int nSkillId = nLayer >> sgptDataTables->nStuff;
        const int nSkillLevel = nLayer & sgptDataTables->nShiftedStuff;
        const int nValue = stats[i].nValue >> 8;
        if ((stats[i].nValue & 0xFF) < nValue)
        {
            ITEMMODS_UpdateItemWithSkillCharges(pItem, nSkillId, nSkillLevel, nValue);

            bRecharged = 1;
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(pClient, pItem, 1, STAT_ITEM_CHARGED_SKILL,
                    (nValue & 0xFF) + (nValue << 8),
                    (nSkillLevel & (unsigned short)sgptDataTables->nShiftedStuff) + (nSkillId << sgptDataTables->nStuff));
            }
        }
    }

    return bRecharged;
}

// 0x00563D20
int __fastcall ITEMMODE_ReplaceOppositeHandItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0xB7B);
    D2_ASSERT(pUnit, 0xB7C);

    *pItemStatus = 0;
    ITEMMODE_ClearTargetingFlags(pUnit, szItemModeCpp, 0xB81);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_ONCURSOR)
    {
        *pItemStatus = 1;
        return 0;
    }

    unsigned char nOtherBodyLoc;
    if (nBodyLoc != 5 && nBodyLoc != 4)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (nBodyLoc == 5)
    {
        nOtherBodyLoc = 4;
    }
    else
    {
        nOtherBodyLoc = 5;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* hOpposite = INVENTORY_GetItemFromBodyLoc(pInventory, nOtherBodyLoc);
    if (!hOpposite)
    {
        *pItemStatus = 1;
        return 0;
    }

    INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &hOpposite, nOtherBodyLoc);
    if (!hOpposite)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (D2Common_10299(pUnit, nBodyLoc, pItem, bSkipRequirementCheck) != 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, hOpposite, pUnit, 0, 1);

    if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
    {
        sITEMSAddStatsList(ptGame, hOpposite, pUnit, 0);
        SUNIT_AttachSound(pUnit, 0x14, 0);
        return 0;
    }

    D2UnitStrc* pMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    if (pMainWeapon)
    {
        UNITS_SetWeaponGUID(pUnit, pMainWeapon);
    }

    D2COMMON_11079_Return0(pUnit, hOpposite);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, hOpposite);

    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hOpposite);
    D2_ASSERT(hRemove, 0xBC8);
    D2_ASSERT(hOpposite == hRemove, 0xBC9);

    D2COMMON_10254_Return0(pInventory, nOtherBodyLoc);

    if (ITEMS_GetItemType(hRemove) == ITEMTYPE_BELT)
    {
        ITEMMODE_MoveExcessBeltItems(ptGame, pUnit, 0);
    }

    INVENTORY_SetCursorItem(pInventory, hOpposite);

    if (hOpposite)
    {
        hOpposite->dwFlags &= ~2;
    }

    UNITS_ChangeAnimMode(hOpposite, 4);

    if (INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
    {
        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
        {
            ITEMS_SetBodyLocation(pItem, nBodyLoc);
            sub_0063D1D0_InventoryItemCall(pInventory, pItem);
            sITEMSAddStatsList(ptGame, pItem, pUnit, 0);
            pItem->dwFlags &= ~2;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 255);
            ITEMS_SetItemCMDFlag(pItem, 0x10000, 1);
            ITEMS_SetItemFlag(pItem, 1, 1);

            if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xBE6, szItemModeCpp))
            {
                ITEMS_SetItemFlag(pItem, 0x4000, 0);
            }

            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            ITEMMODE_RefreshSkillsForEquippedWeapons(pUnit);
            ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
        }
        else
        {
            *pItemStatus = 1;
            return 0;
        }
    }

    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}

// 0x00563560
int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0x77A);
    D2_ASSERT(pUnit, 0x77B);

    *pItemStatus = 0;

    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 0x780);

    if (INVENTORY_GetCursorItem(hInventory))
    {
        return 0;
    }

    if (PLAYER_IsBusy(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType == UNIT_ITEM)
    {
        if (pItem->dwAnimMode != IMODE_ONGROUND)
        {
            *pItemStatus = 1;
            return 0;
        }

        ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x7A2);

        if (!ITEMMODE_CanPickUpItem(ptGame, pUnit, pItem))
        {
            ITEMMODE_DropBackToGround(0x13, pItem, pUnit);
            return 0;
        }

        SUNIT_AttachSound(pUnit, 1, pUnit);

        if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        {
            D2GAME_PickupGold(ptGame, pItem, pUnit);
            return 1;
        }

        if (!ITEMMODE_PickupStackable(ptGame, pUnit, pItem))
        {

            if (ITEMMODE_FindFreeBodyLocation(pUnit, pItem, &nItemGUID, 0))
            {
                if (D2Common_10299(pUnit, nItemGUID, pItem, 0) != 1)
                {
                    *pItemStatus = 1;
                    return 0;
                }

                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                if (pRoom)
                {
                    DUNGEON_AllocDrlgDelete(pRoom, !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (ITEMMODE_EquipItemAtResolvedBodyLocation(ptGame, pUnit, pItem, 0))
                {
                    QUESTS_ItemPickedUp(ptGame, pUnit, pItem);
                    return 1;
                }
            }
            else if (ITEMS_CheckIfBeltable(pItem) && ITEMS_CheckIfAutoBeltable(hInventory, pItem) && INVENTORY_PlaceItemInFreeBeltSlot(hInventory, pItem))
            {
                if (UNITS_GetRoom(pItem))
                {
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
                    UNITS_FreeCollisionPath(pItem);
                    UNITROOM_RemoveUnitFromRoom(pItem);
                }

                if (INVENTORY_PlaceItemInSocket(hInventory, pItem, 2))
                {
                    INVENTORY_SetCursorItem(hInventory, 0);
                    ITEMMODE_AddItemScrollSkillQuantity(pUnit, pItem);

                    if (ITEMS_IsCharmUsable(pItem, pUnit))
                    {
                        sITEMSAddStatsList(ptGame, pItem, pUnit, 0);
                    }

                    pItem->dwFlags &= ~2u;
                    UNITS_ChangeAnimMode(pItem, 2);
                    ITEMS_SetInvPage(pItem, 0xFF);
                    ITEMS_SetItemCMDFlag(pItem, 0x2000, 1);
                    pItem->dwFlags &= ~0x02000000u;
                    INVENTORY_AddItemToTradeInventory(hInventory, pItem);
                    UNITS_RefreshInventory(pUnit, 1);

                    if (ITEMS_IsCharmUsable(pItem, pUnit))
                    {
                        ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
                        UNITS_RefreshInventory(pUnit, 1);
                    }

                    return 1;
                }

                D2_ASSERT(0, 0x7ED);
            }
            else
            {
                if (ITEMMODE_PlaceItemAtFreeInventoryPosition(ptGame, 1, 0, ".\\ITEMS\\ItemMode.cpp", 0x7EF, pUnit, pItem))
                {
                    return 1;
                }

                ITEMMODE_DropBackToGround(0x17, pItem, pUnit);
            }
        }
    }

    return 0;
}

static void __stdcall sub_0055E0D0_DecrementBookScrollSkillQuantity(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        int nQuantity = SKILLS_GetQuantity(pSkill) - 1;
        if (nQuantity <= 0)
        {
            if (UNITS_GetRightSkill(pUnit) == pSkill)
                D2GAME_AssignSkill_6FD13800(pUnit, 0, SKILL_ATTACK, -1);
            nQuantity = 0;
        }
        SKILLS_SetQuantity(pSkill, nQuantity);
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, szItemModeCpp, 0xFC2), nUnitType, nUnitGUID, nSkillId, nQuantity);
    }
    else
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xFC4);
        exit(-1);
    }
}

// 0x0055DBC0
void __fastcall ITEMMODE_RecalcEquippedItemStates(D2GameStrc* pGame,D2UnitStrc* pUnit,int bRefresh)
{
    if (!pUnit)
        return;

    if (sub_0055DBC0_GetUnitType(pUnit) && !sub_0055DBC0_UnitFlag9(pUnit))
        return;

    D2EquipmentRefreshStateStrc refreshState;
    ITEMMODE_SaveEquipmentRefreshState(pUnit,&refreshState);
    D2InventoryStrc* pInventory=pUnit->pInventory;
    if(!pInventory) return;
    for(D2UnitStrc* pLink=INVENTORY_GetFirstItem(pInventory);pLink;pLink=INVENTORY_GetNextItem(pLink))
    {
        D2UnitStrc* pItem=INVENTORY_UnitIsItem(pLink);
        if(pItem && INVENTORY_GetItemNodePage(pLink)==1 && ITEMS_IsCharmUsable(pItem,pUnit) && !STATLIST_GetOwner(pItem,0) && ITEMMODE_CheckEquipRequirements(pUnit,pItem))
        {
            ITEMS_SetItemFlag(pItem,0x4000,0);
            ITEMMODE_UpdateEquippedItemStats(pGame,pItem,pUnit);
        }
    }
    for (int i = 1; i < 11; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
        if (!pItem)
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x100, 0xa85, szItemModeCpp) && !STATLIST_GetOwner(pItem, 0))
            continue;

        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xa8a, szItemModeCpp) && !STATLIST_GetOwner(pItem, 0))
            continue;

        if (ITEMMODE_CheckEquipRequirements(pUnit, pItem))
            continue;

        ITEMS_SetItemFlag(pItem, 0x4000, 1);
        INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
        const int nMode = UNITS_GetAnimOrSeqMode(pItem);
        if (nMode == 1)
            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, nMode, nMode);
    }
    int bContinue;
    do
    {
        bContinue=0;
        for (int i = 1; i < 11; ++i)
        {
            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, i);
            if (!pItem)
                continue;

            if (ITEMS_CheckItemFlag(pItem, 0x100, 0xaa4, szItemModeCpp))
                continue;

            if (!ITEMS_CheckItemFlag(pItem, 0x4000, 0xaa8, szItemModeCpp) && STATLIST_GetOwner(pItem, 0))
                continue;

            if (!ITEMMODE_CheckEquipRequirements(pUnit, pItem))
                continue;

            {
                ITEMS_SetItemFlag(pItem,0x4000,0);
                D2InventoryStrc* pCurrentInventory=pUnit->pInventory;
                if(pCurrentInventory)
                {
                    unsigned char nBodyLoc=ITEMS_GetBodyLocation(pItem);
                    if(nBodyLoc!=0xb && nBodyLoc!=0xc)
                    {
                        INVENTORY_UpdateWeaponGUIDOnInsert(pCurrentInventory,pItem);
                        if (UNITS_GetAnimOrSeqMode(pItem)==1)
                        {
                            sITEMSAddStatsList(pGame,pItem,pUnit,1);
                        }
                        else if (!UNITS_GetAnimOrSeqMode(pItem) && ITEMS_IsCharmUsable(pItem,pUnit))
                        {
                            sITEMSAddStatsList(pGame,pItem,pUnit,1);
                        }
                    }
                }
                bContinue=1;
            }
        }
    }while(bContinue);
    for(int i=1;i<11;++i)
    {
        D2UnitStrc* pItem=INVENTORY_GetItemFromBodyLoc(pInventory,i);
        if(pItem && ITEMS_GetItemQuality(pItem)==ITEMQUAL_SET && !ITEMS_CheckItemFlag(pItem,0x100,0xac2,szItemModeCpp) && !ITEMS_CheckItemFlag(pItem,0x4000,0xac3,szItemModeCpp))
        {
            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(*(D2GameStrc* *)&pGame,pItem,pUnit,1,1);
            sITEMSAddStatsList(pGame,pItem,pUnit,1);
        }
    }
    ITEMMODE_RestoreSelectedSkills(pUnit,&refreshState);
    UNITS_RefreshInventory(pUnit,1);
    if(bRefresh)
    {
        D2ClientStrc* pClient;
        if(pUnit->dwUnitType==UNIT_PLAYER) pClient=UnitGetClient(pUnit,szItemModeCpp,0xa44);
        else
        {
            D2UnitStrc* pOwner=AIGENERAL_GetMinionOwner(pUnit);
            if(!pOwner || pOwner->dwUnitType!=UNIT_PLAYER) return;
            pClient=UnitGetClient(pOwner,szItemModeCpp,0xa49);
        }
        if(pClient) D2GAME_SendPacket0x48_6FC3EF40(pClient,pUnit,0);
    }
}

// 0x005608C0
void __fastcall ITEMMODE_MoveExcessBeltItems(Game* game, Unit* player, Unit* belt)
{
    void* hInventory = player->inventory;
    D2_ASSERT(hInventory, 0xC0C);
    BeltRecord record;
    if (belt) DATATBLS_GetBeltsTxtRecord(UNITS_GetBeltType(belt), 0, &record);
    else DATATBLS_GetBeltsTxtRecord(2, 0, &record); // 0x00660CB0
    for (int index = 0; index < 16; ++index) {
        Unit* hItem = INVENTORY_GetItemFromBeltSlot(hInventory, index);
        if (index < record.nBoxes || !hItem) continue;
        unsigned int flags = 0;
        ITEMS_SetOrRemoveFlag(&flags, 32, 1);
        D2GAME_SendP0x9C_ItemAction_RemoveFromBelt_6FC3EBE0(sub_005531C0_Client(player, ".\\ITEMS\\ItemMode.cpp", 0xC1F), player, hItem, flags);
        Unit* removed = sub_0063AD90_Remove(hInventory, hItem);
        D2_ASSERT(removed, 0xC22);
        D2_ASSERT(hItem == removed, 0xC23);
        int x;
        switch (hItem->type) {
        case 2: case 4: case 5: x = hItem->path->x; break;
        default: x = hItem->path ? sub_006488C0_X(hItem->path) : 0; break;
        }
        D2COMMON_10267_Return((D2InventoryStrc*)hInventory, x);
        sub_00624690_Mode(removed, 4);
        ITEMMODE_RemoveItemScrollSkillQuantity((D2UnitStrc*)player, (D2UnitStrc*)hItem);
        ITEMS_SetInvPage(hItem, 0);
        if (PlaceIntoInventory(game, player, hItem->id, 0xC29)) continue;
        {
            Point playerPosition;
            Point dropPosition;
            sub_00620870_Position(player, &playerPosition);
            void* room = D2GAME_GetFreeSpaceEx_6FC4BF00(sub_00620BB0_Room(player), &playerPosition, &dropPosition, 1, 1);
            if (room) {
                D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(game, hItem, player, 0, 1);
                D2GAME_DropItem_6FC52260(game, player, hItem, room, dropPosition.x, dropPosition.y);
            }
        }
    }
}

// 0x00560F00
int __fastcall ITEMMODE_SwapCursorAndBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pFailed)
{
 D2_ASSERT(ptGame, 0xca7);
 D2_ASSERT(pUnit, 0xca8);
 if (nBodyLoc >= 11) return 0;
 *pFailed = 0;
 ITEMMODE_ClearTargetingFlags(pUnit, szItemModeCpp, 0xcb0);
 D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
 if (!pItem) { *pFailed = 0; return 0; }
 if (pItem->dwUnitType != UNIT_ITEM) return 0;
 if (pItem->dwAnimMode != IMODE_ONCURSOR) { *pFailed = 0; return 0; }
 const int nLoc = nBodyLoc;
 if (D2Common_10299(pUnit, nLoc, pItem, bSkipRequirementCheck) != 5) { *pFailed = 0; return 0; }
 D2InventoryStrc* pInventory = pUnit->pInventory;
 D2UnitStrc* pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
 if (pWeapon) UNITS_SetWeaponGUID(pUnit, pWeapon);
 D2UnitStrc* hBodyItem = INVENTORY_GetItemFromBodyLoc(pInventory, nLoc);
 INVENTORY_GetSecondWieldingWeapon(pUnit, pInventory, &hBodyItem, nLoc);
 if (!hBodyItem) goto fail;
 if (hBodyItem->dwAnimMode != IMODE_EQUIP)
 {
fail:
  *pFailed = 1;
  return 0;
 }
 D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, hBodyItem, pUnit, 0, 1);
 if (!bSkipRequirementCheck && !ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
 {
  sITEMSAddStatsList(ptGame, hBodyItem, pUnit, 0);
  SUNIT_AttachSound(pUnit, 20, 0);
  return 0;
 }
 if (ITEMS_GetItemType(pItem) == ITEMTYPE_BELT) ITEMMODE_MoveExcessBeltItems(ptGame, pUnit, pItem);
 D2COMMON_11079_Return0(pUnit, hBodyItem);
 INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, hBodyItem);
 D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, hBodyItem);
 D2_ASSERT(pRemoved, 0xcee);
 D2_ASSERT(hBodyItem == pRemoved, 0xcef);
 sub_0063BE30(pInventory, nLoc);
 INVENTORY_SetCursorItem(pInventory, hBodyItem);
 if (hBodyItem) hBodyItem->dwFlags &= ~2;
 UNITS_ChangeAnimMode(hBodyItem, 4);
 ITEMS_SetItemFlag(hBodyItem, 0x80, 1);
 ITEMS_SetItemCMDFlag(hBodyItem, 0x20, 1);
 ITEMS_SetItemFlag(hBodyItem, 1, 1);
 if (ITEMS_CheckItemFlag(hBodyItem, 0x4000, 0xcf7, szItemModeCpp)) ITEMS_SetItemFlag(hBodyItem, 0x4000, 0);
 INVENTORY_AddItemToTradeInventory(pInventory, hBodyItem);
 if (INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nLoc))
 {
  if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
  {
    ITEMS_SetBodyLocation(pItem, nBodyLoc);
    sub_0063D1D0_InventoryItemCall(pInventory, pItem);
    sITEMSAddStatsList(ptGame, pItem, pUnit, 0);
    pItem->dwFlags &= ~2;
    UNITS_ChangeAnimMode(pItem, 1);
    ITEMS_SetInvPage(pItem, 255);
    ITEMS_SetItemFlag(pItem, 0x40, 1);
    ITEMS_SetItemFlag(pItem, 1, 1);
    ITEMS_SetItemCMDFlag(pItem, 0x20, 1);
    ITEMS_SetItemFlag(pItem, 1, 1);
    if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xd12, szItemModeCpp)) ITEMS_SetItemFlag(pItem, 0x4000, 0);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    ITEMMODE_RefreshSkillsForEquippedWeapons(pUnit);
    ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
    return 1;
  }
  *pFailed = 1;
  return 0;
 }
 *pFailed = 1;
 return 0;
}

// 0x00561220
int __fastcall ITEMMODE_ReplaceHandItemsWithCursorItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int* pFailure)
{
    D2_ASSERT(ptGame, 0xD38);
    D2_ASSERT(pUnit, 0xD39);
    *pFailure = 0;
    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem || pItem->dwUnitType != UNIT_ITEM || pItem->dwAnimMode != IMODE_ONCURSOR)
        return 0;
    if (D2Common_10299(pUnit, nBodyLoc, pItem, 0) != 7)
        return 0;
    if (!ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
        return 0;
    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xD60);
    int nRecord = UNITS_GetInventoryRecordId(pUnit, 0, ptGame->bExpansion);
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pOther;
    int nOtherBodyLoc;
    if (nBodyLoc == 5)
    {
        pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        nOtherBodyLoc = 4;
    }
    else
    {
        pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        nOtherBodyLoc = 5;
    }
    if (!INVENTORY_IsItemBodyLocFree(pInventory, pItem, nOtherBodyLoc, nRecord))
    {
        *pFailure = 1;
        return 0;
    }
    D2_ASSERT(pOther, 0xD73);
    if (UNIT_GetMode(pOther) != 1)
    {
        *pFailure = 1;
        return 0;
    }
    D2COMMON_11079_Return0(pUnit, pOther);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pOther);
    D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pOther);
    D2_ASSERT(pRemoved, 0xD7D);
    D2_ASSERT(pOther == pRemoved, 0xD7E);
    sub_0063BE30(pInventory, nOtherBodyLoc);
    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, pRemoved, pUnit, 0, 1);
    if (INVENTORY_PlaceItemAtFreePosition(pInventory, pRemoved, nRecord, 0, 0, ".\\ITEMS\\ItemMode.cpp", 0xD86))
    {
        if (INVENTORY_PlaceItemInSocket(pInventory, pRemoved, 1))
        {
        ITEMS_SetInvPage(pRemoved, 0);
        pRemoved->dwFlags &= ~2;
        INVENTORY_SetCursorItem(pInventory, 0);
        UNITS_ChangeAnimMode(pRemoved, 0);
        if (D2GAME_CheckHasFilledSockets(pRemoved, ".\\ITEMS\\ItemMode.cpp", 0xD8D))
            ITEMS_SetItemFlag(pRemoved, 1, 1);
        if (ITEMS_CheckItemFlag(pRemoved, 0x4000, 0xD90, ".\\ITEMS\\ItemMode.cpp"))
            ITEMS_SetItemFlag(pRemoved, 0x4000, 0);
        ITEMS_SetItemCMDFlag(pRemoved, 0x4000, 1);
        ITEMS_SetItemFlag(pRemoved, 1, 1);
        INVENTORY_AddItemToTradeInventory(pInventory, pRemoved);
        }
        else
        {
            *pFailure = 1;
            return 0;
        }
    }
    D2UnitStrc* pEquipped = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
    D2_ASSERT(pEquipped, 0xD9F);
    if (pEquipped->dwAnimMode != 1)
    {
        *pFailure = 1;
        return 0;
    }
    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, pEquipped, pUnit, 0, 1);
    if (!ITEMS_CheckRequirements(pItem, pUnit, 0, 0, 0, 0))
    {
        sITEMSAddStatsList(ptGame, pEquipped, pUnit, 0);
        INVENTORY_SetCursorItem(pInventory, pItem);
        ITEMMODE_MarkItemOnCursor(ptGame, pUnit, pItem);
        SUNIT_AttachSound(pUnit, 20, 0);
        UNITS_RefreshInventory(pUnit, 1);
        return 0;
    }
    D2COMMON_11079_Return0(pUnit, pEquipped);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pEquipped);
    D2UnitStrc* pRemovedEquipped = INVENTORY_RemoveItemFromInventory(pInventory, pEquipped);
    D2_ASSERT(pRemovedEquipped, 0xDB6);
    D2_ASSERT(pEquipped == pRemovedEquipped, 0xDB7);
    sub_0063BE30(pInventory, nBodyLoc);
    INVENTORY_SetCursorItem(pInventory, pEquipped);
    pEquipped->dwFlags &= ~2;
    UNITS_ChangeAnimMode(pEquipped, 4);
    ITEMS_SetItemCMDFlag(pEquipped, 0x10, 1);
    ITEMS_SetItemFlag(pEquipped, 1, 1);
    if (ITEMS_CheckItemFlag(pEquipped, 0x4000, 0xDBE, ".\\ITEMS\\ItemMode.cpp"))
        ITEMS_SetItemFlag(pEquipped, 0x4000, 0);
    INVENTORY_AddItemToTradeInventory(pInventory, pEquipped);
    if (sub_0063BDB0(pInventory, pItem, nBodyLoc))
    {
        if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
        {
        ITEMS_SetBodyLocation(pItem, nBodyLoc);
        sub_0063D1D0_InventoryItemCall(pInventory, pItem);
        sITEMSAddStatsList(ptGame, pItem, pUnit, 0);
        pItem->dwFlags &= ~2;
        UNITS_ChangeAnimMode(pItem, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        ITEMS_SetItemFlag(pItem, 8, 1);
        ITEMS_SetItemCMDFlag(pItem, 8, 1);
        ITEMS_SetItemFlag(pItem, 1, 1);
        if (D2GAME_CheckHasFilledSockets(pItem, ".\\ITEMS\\ItemMode.cpp", 0xDD5))
            ITEMS_SetItemFlag(pItem, 1, 1);
        if (ITEMS_CheckItemFlag(pItem, 0x4000, 0xDD8, ".\\ITEMS\\ItemMode.cpp"))
            ITEMS_SetItemFlag(pItem, 0x4000, 0);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        ITEMMODE_RefreshSkillsForEquippedWeapons(pUnit);
        ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
        return 1;
        }
        *pFailure = 1;
        return 0;
    }
    *pFailure = 1;
    return 0;
}

// 0x005616A0
int __fastcall ITEMMODE_SwapWeaponSets(D2GameStrc* ptGame, D2UnitStrc* hUnit, int* status)
{
    int i;
    SwapEntry entries[4] = { {4,0,11,4}, {5,0,12,4}, {11,0,4,3}, {12,0,5,3} };
    D2_ASSERT(ptGame, 0xE1E);
    D2_ASSERT(hUnit, 0xE1F);
    *status = 0;
    ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0xE24);
    D2InventoryStrc* inventory = hUnit->pInventory;
    int leftId, leftOwner, rightId, rightOwner;
    UNITS_GetSwitchLeftSkillDataResetLeftSkill(hUnit, &leftId, &leftOwner);
    UNITS_GetSwitchRightSkillDataResetRightSkill(hUnit, &rightId, &rightOwner);
    UNITS_InitSwitchRightSkill(hUnit);
    UNITS_InitSwitchLeftSkill(hUnit);
    i=0;
    if (i<4)
    {
        do
        {
            entries[i].item = INVENTORY_GetItemFromBodyLoc(inventory, entries[i].from);
            if (entries[i].item) {
                INVENTORY_GetSecondWieldingWeapon(hUnit, inventory, &entries[i].item, entries[i].from);
                if (!entries[i].item || entries[i].item->dwAnimMode != IMODE_EQUIP) { *status=1; return 0; }
            }
            ++i;
        } while (i<4);
    }
    if (entries[0].item) D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, entries[0].item, hUnit, 0, 1);
    if (entries[1].item) D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, entries[1].item, hUnit, 0, 1);
    SwapEntry* entry = entries;
    for (i=0; i<4; ++i, ++entry) {
        D2UnitStrc* item = entry->item;
        if (!item) continue;
        if (i<2) INVENTORY_UpdateWeaponGUIDOnRemoval(inventory, item);
        D2UnitStrc* removed = INVENTORY_RemoveItemFromInventory(inventory, entry->item);
        if (!removed || removed != entry->item) { *status=1; return 0; }
        sub_0063BE30_Return(inventory, entry->from);
        ITEMS_SetInvPage(removed, 255);
        ITEMS_SetItemCMDFlag(removed, 0x200000, 1);
        ITEMS_SetItemFlag(removed, 1, 1);
        if (ITEMS_CheckItemFlag(removed, 0x4000, 0xE5B, szItemModeCpp)) ITEMS_SetItemFlag(removed, 0x4000, 0);
        INVENTORY_AddItemToTradeInventory(inventory, removed);
    }
    for (i=0; i<4; ++i) {
        D2UnitStrc* item = entries[i].item;
        if (item) {
            if (!INVENTORY_PlaceItemInBodyLoc(inventory, item, entries[i].to)) { *status=1; return 0; }
            if (!INVENTORY_PlaceItemInSocket(inventory, item, entries[i].mode)) { *status=1; return 0; }
            ITEMS_SetBodyLocation(item, entries[i].to);
            if (entries[i].to == 4 || entries[i].to == 5) {
                sub_0063D1D0_InventoryItemCall(inventory, item);
                sITEMSAddStatsList(ptGame, item, hUnit, 0);
                ITEMS_SetItemFlag(item, 64, 1);
            } else {
                ITEMS_SetItemFlag(item, 128, 1);
            }
            item->dwFlags &= ~2;
            UNITS_ChangeAnimMode(item, 1);
            ITEMS_SetItemFlag(item, 1, 1);
            ITEMS_SetItemCMDFlag(item, 0x200000, 1);
            ITEMS_SetItemFlag(item, 1, 1);
            if (i<2) ITEMMODE_RefreshSkillsForEquippedWeapons(hUnit);
        }
    }
    ITEMMODE_RecalcEquippedItemStates(ptGame, hUnit, 0);
    D2SkillStrc* leftSkill = SKILLS_GetSkillById(hUnit, leftId, leftOwner);
    D2SkillStrc* rightSkill = SKILLS_GetSkillById(hUnit, rightId, rightOwner);
    D2ClientStrc* hClient = UnitGetClient(hUnit, szItemModeCpp, 0xE93);
    D2_ASSERT(hClient, 0xE94);
    sub_00539230_SetWeaponSwitch(hClient, !CLIENTS_GetWeaponSwitch(hClient));
    D2GAME_PACKETS_SendPacket0x97_6FC3FB60(UnitGetClient(hUnit, szItemModeCpp, 0xE98));
    if (SkillUsable(hUnit, leftSkill)) {
        D2GAME_AssignSkill_6FD13800(hUnit, 1, leftId, leftOwner);
        SUNITMSG_QueueSkillSelection(hUnit, 1, leftId, leftOwner);
    } else {
        D2SkillStrc* skill = UNITS_GetLeftSkill(hUnit);
        int id, owner;
        if (skill) { id=SKILLS_GetSkillIdFromSkill(skill, szItemModeCpp, 0xEA2); owner=SKILLS_GetOwnerGUIDFromSkill(skill); }
        else { id=0; owner=-1; }
        SUNITMSG_QueueSkillSelection(hUnit, 1, id, owner);
    }
    if (SkillUsable(hUnit, rightSkill)) {
        D2GAME_AssignSkill_6FD13800(hUnit, 0, rightId, rightOwner);
        SUNITMSG_QueueSkillSelection(hUnit, 0, rightId, rightOwner);
    } else {
        D2SkillStrc* skill = UNITS_GetRightSkill(hUnit);
        int id, owner;
        if (skill) { id=SKILLS_GetSkillIdFromSkill(skill, szItemModeCpp, 0xEB0); owner=SKILLS_GetOwnerGUIDFromSkill(skill); }
        else { id=0; owner=-1; }
        SUNITMSG_QueueSkillSelection(hUnit, 0, id, owner);
    }
    return 1;
}

// 0x00561B00
int __fastcall ITEMMODE_SwapCursorAndStoredItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nGridItemGUID, int nX, int nY, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0xEC0);
    D2_ASSERT(pUnit, 0xEC1);

    *pItemStatus = 0;

    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0xEC6);

    D2UnitStrc* pCursorItem = SUNIT_GetServerUnit(ptGame, 4, nCursorItemGUID);
    if (!pCursorItem || pCursorItem->dwUnitType != UNIT_ITEM || pCursorItem->dwAnimMode != IMODE_ONCURSOR)
    {
        return 0;
    }

    D2UnitStrc* hGridItem = SUNIT_GetServerUnit(ptGame, 4, nGridItemGUID);
    if (!hGridItem || hGridItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    const char nInvPage = ITEMS_GetInventoryPage(hGridItem);
    if (nInvPage == 3)
    {
        if (!gbHoradricCubeItemIdInitialized)
        {
            if (!DATATBLS_GetItemRecordFromItemCode(0x20786F62, &gnHoradricCubeItemId))
            {
                return 0;
            }

            gbHoradricCubeItemIdInitialized = 1;
        }

        const int nClassId = (pCursorItem ? pCursorItem->dwClassId : -1);
        if (nClassId == gnHoradricCubeItemId)
        {
            return 0;
        }
    }
    else if (nInvPage == 2)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (hGridItem->dwAnimMode != IMODE_STORED)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hGridItem);
    D2_ASSERT(hRemove, 0xF12);
    D2_ASSERT(hGridItem == hRemove, 0xF13);

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, hGridItem, pUnit, 0, 1);
    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0xF15, pInventory, CLIENTS_GetUnitX(hGridItem), CLIENTS_GetUnitY(hGridItem), UNITS_GetInventoryRecordId(pUnit, nInvPage, ptGame->bExpansion), 0, nInvPage);

    ITEMS_SetInvPage(hGridItem, 0xFF);
    INVENTORY_SetCursorItem(pInventory, hGridItem);
    ITEMMODE_RemoveItemScrollSkillQuantity(pUnit, hGridItem);
    ITEMS_SetCellOverlap(hGridItem, nInvPage);
    hGridItem->dwFlags &= ~2u;
    UNITS_ChangeAnimMode(hGridItem, 4);
    ITEMS_SetItemCMDFlag(hGridItem, 0x40000, 1);

    if (D2GAME_CheckHasFilledSockets(hGridItem, ".\\ITEMS\\ItemMode.cpp", 0xF1F))
    {
        ITEMS_SetItemFlag(hGridItem, 1, 1);
    }

    if (sub_006280A0(hGridItem, 0x4000, 0xF22, ".\\ITEMS\\ItemMode.cpp"))
    {
        ITEMS_SetItemFlag(hGridItem, 0x4000, 0);
    }

    INVENTORY_AddItemToTradeInventory(pInventory, hGridItem);

    if (INVENTORY_PlaceItemAtInventoryPage(pInventory, pCursorItem, nX, nY, UNITS_GetInventoryRecordId(pUnit, nInvPage, ptGame->bExpansion), 0, nInvPage))
    {
        ITEMS_SetCellOverlap(pCursorItem, 0);
        ITEMS_SetInvPage(pCursorItem, nInvPage);
        UNITS_SetXForStaticUnit(pCursorItem, nX);
        UNITS_SetYForStaticUnit(pCursorItem, nY);

        if (INVENTORY_PlaceItemInSocket(pInventory, pCursorItem, 1))
        {
            pCursorItem->dwFlags &= ~2u;
            ITEMMODE_AddItemScrollSkillQuantity(pUnit, pCursorItem);

            if (ITEMS_IsCharmUsable(pCursorItem, pUnit))
            {
                sITEMSAddStatsList(ptGame, pCursorItem, pUnit, 0);
            }

            UNITS_ChangeAnimMode(pCursorItem, 0);

            if (D2GAME_CheckHasFilledSockets(pCursorItem, ".\\ITEMS\\ItemMode.cpp", 0xF48))
            {
                ITEMS_SetItemFlag(pCursorItem, 1, 1);
            }

            if (sub_006280A0(pCursorItem, 0x4000, 0xF4B, ".\\ITEMS\\ItemMode.cpp"))
            {
                ITEMS_SetItemFlag(pCursorItem, 0x4000, 0);
            }

            ITEMS_SetItemCMDFlag(pCursorItem, 0x40000, 1);
            INVENTORY_AddItemToTradeInventory(pInventory, pCursorItem);

            if (nInvPage == 2)
            {
                PLRTRADE_AddItemToTrade(ptGame, pUnit, pCursorItem);
            }

            UNITS_RefreshInventory(pUnit, 1);

            if (ITEMS_IsCharmUsable(hGridItem, pUnit))
            {
                ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
                UNITS_RefreshInventory(pUnit, 1);
            }

            return 1;
        }

        *pItemStatus = 1;
        return 0;
    }

    *pItemStatus = 1;
    return 0;
}

// 0x00561ED0
int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus)
{
    D2_ASSERT(ptGame, 0xFCF);
    D2_ASSERT(hUnit, 0xFD0);
    D2UnitStrc* pTargetItem = SUNIT_GetServerUnit(ptGame, 4, nTargetGUID);
    D2UnitStrc* pUseItem = SUNIT_GetServerUnit(ptGame, 4, nUseItemGUID);
    *pItemStatus = 0;
    if (!pUseItem)
    {
        *pItemStatus = 1;
        return 0;
    }
    if (!pTargetItem || pTargetItem == pUseItem)
    {
        ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0xFDD);
        return 0;
    }
    if ((!pUseItem ? 0 : pUseItem->dwAnimMode) == 2 && !ITEMSIsA(pUseItem, 0x16))
    {
        *pItemStatus = 1;
        return 0;
    }
    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(ptGame, hUnit, 1))
    {
        *pItemStatus = 0;
        return 0;
    }
    if ((!pTargetItem ? 6 : pTargetItem->dwUnitType) != 4 || pUseItem->dwUnitType != UNIT_ITEM)
        return 0;
    if ((!pTargetItem ? 6 : pTargetItem->dwUnitType) != (!pUseItem ? 6 : pUseItem->dwUnitType))
    {
        ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1004);
        return 0;
    }
    D2InventoryStrc* pInventory = hUnit->pInventory;
    if (INVENTORY_GetCursorItem(pInventory))
        return 0;
    const int nTargetAnimMode = pTargetItem->dwAnimMode;
    const int nUseItemAnimMode = pUseItem->dwAnimMode;
    if (nTargetAnimMode != 0 && nTargetAnimMode != 1)
    {
        if (nUseItemAnimMode == 2)
        {
            ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1010);
            ITEMMODE_RemoveBeltItem(ptGame, hUnit, pUseItem);
        }
        else if (nUseItemAnimMode == 0)
        {
            if (ITEMS_GetItemType(pUseItem) == ITEMTYPE_BOOK)
            {
                int nQuantity = STATLIST_UnitGetStatValue(pUseItem, STAT_QUANTITY, 0) - 1;
                if (nQuantity < 0)
                    nQuantity = 0;
                STATLIST_SetUnitStat(pUseItem, STAT_QUANTITY, nQuantity, 0);
                D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, szItemModeCpp, 0x1019), pUseItem, 1, 0x46, nQuantity, 0);
            }
        }
        else
        {
            *pItemStatus = 1;
        }
        return 0;
    }
    if (ITEMS_GetItemType(pUseItem) == ITEMTYPE_BOOK && STATLIST_UnitGetStatValue(pUseItem, STAT_QUANTITY, 0) <= 0)
    {
        ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1023);
        const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
        const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, szItemModeCpp, 0x1024), 0x7C, nUnitType, nUnitGUID);
        return 0;
    }
    if (!SKILLITEM_pSpell_Handler(ptGame, hUnit, pUseItem, pTargetItem, 0, 0))
        goto Success;
    if (nUseItemAnimMode == 2)
    {
        const int nSkillId = ITEMMODE_GetBookOrScrollSkillId(pUseItem);
        if (nSkillId != -1)
        {
            sub_0055E0D0_DecrementBookScrollSkillQuantity(hUnit, nSkillId);
            ITEMMODE_RemoveBeltItem(ptGame, hUnit, pUseItem);
            ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1034);
            goto Success;
        }
        const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
        const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, szItemModeCpp, 0x1032), 0x7C, nUnitType, nUnitGUID);
        ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1034);
        goto Success;
    }
    if (nUseItemAnimMode)
    {
        *pItemStatus = 1;
        return 0;
    }
    if (ITEMS_GetItemType(pUseItem) == ITEMTYPE_BOOK)
    {
        const int nSkillId = ITEMMODE_GetBookOrScrollSkillId(pUseItem);
        if (nSkillId != -1 && STATLIST_UnitGetStatValue(pUseItem, STAT_QUANTITY, 0) > 0)
        {
            STATLIST_AddUnitStat(pUseItem, STAT_QUANTITY, -1, 0);
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(hUnit, szItemModeCpp, 0x103C), pUseItem, 1, 0x46, STATLIST_UnitGetStatValue(pUseItem, STAT_QUANTITY, 0), 0);
            sub_0055E0D0_DecrementBookScrollSkillQuantity(hUnit, nSkillId);
            const int nUnitGUID = !pUseItem ? -1 : pUseItem->dwUnitId;
            const int nUnitType = !pUseItem ? 6 : pUseItem->dwUnitType;
            D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(hUnit, szItemModeCpp, 0x104A), 0x7C, nUnitType, nUnitGUID);
            ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x104C);
            return 1;
        }
    }
    else
    {
        const int nSkillId = ITEMMODE_GetBookOrScrollSkillId(pUseItem);
        if (nSkillId != -1)
            sub_0055E0D0_DecrementBookScrollSkillQuantity(hUnit, nSkillId);
    }
    ITEMMODE_RemoveItemAndNotify(ptGame, hUnit, pUseItem);
    ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x104C);
Success:
    return 1;
}

// 0x00562250
int __fastcall ITEMMODE_RemoveBeltItemToCursor(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int* a4)
{
    D2_ASSERT(ptGame, 0x1249);
    D2_ASSERT(hUnit, 0x124A);

    *a4 = 0;

    D2InventoryStrc* hInventory = hUnit->pInventory;
    D2_ASSERT(hInventory, 0x124F);

    if (INVENTORY_GetCursorItem(hInventory))
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        *a4 = 1;
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_INBELT)
    {
        *a4 = 1;
        return 0;
    }

    ITEMMODE_ClearTargetingFlags(hUnit, ".\\ITEMS\\ItemMode.cpp", 0x126D);

    const int nX = CLIENTS_GetUnitX(pItem);
    INVENTORY_RemoveItemFromInventory(hInventory, pItem);
    D2COMMON_10267_Return(hInventory, nX);
    INVENTORY_SetCursorItem(hInventory, pItem);
    ITEMMODE_RemoveItemScrollSkillQuantity(hUnit, pItem);

    pItem->dwFlags &= ~2;

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(ptGame, pItem, hUnit, 0, 1);
    UNITS_ChangeAnimMode(pItem, 4);
    ITEMS_SetItemCMDFlag(pItem, 0x800, 1);
    UNITS_RefreshInventory(hUnit, 1);
    INVENTORY_AddItemToTradeInventory(hInventory, pItem);
    ITEMMODE_CompactBeltColumn(ptGame, hUnit, nX);
    return 1;
}

// 0x0055EDC0
void __fastcall ITEMMODE_CompactBeltColumn(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    nX &= 3;
    int nDestinationRow = 0;
    nX = nX > 0 ? nX : 0;
    nX = nX < 3 ? nX : 3;
    for (int nRow = 0; nRow < 4; ++nRow)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nX + 4 * nRow);
        if (pItem)
        {
            if (nDestinationRow != nRow)
            {
                INVENTORY_PlaceItemInBeltSlot(pInventory, pItem, nX + 4 * nDestinationRow);
                ITEMS_SetItemFlag(pItem, 0x400, 1);
                ITEMS_SetItemFlag(pItem, 1, 1);
                if (ITEMS_CheckItemFlag(pItem, 0x4000, 4883, ".\\ITEMS\\ItemMode.cpp"))
                    ITEMS_SetItemFlag(pItem, 0x4000, 0);
                UNITS_RefreshInventory(pUnit, 1);
                INVENTORY_AddItemToTradeInventory(pInventory, pItem);
                D2COMMON_10267_Return(pInventory, nX + 4 * nRow);
            }
            ++nDestinationRow;
        }
    }
}

// 0x00562390
int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc)
{
    D2_ASSERT(ptGame, 0x1325);
    D2_ASSERT(hUnit, 0x1326);

    *pItemStatus = 0;
    ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x132B);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if ((!pItem ? 6 : pItem->dwUnitType) != 4 || INVENTORY_GetCursorItem(UNITS_GetInventory(hUnit)))
    {
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_INBELT || !ITEMS_CheckIfUseable(pItem))
    {
        *pItemStatus = 1;
        return 0;
    }

    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(ptGame, hUnit, 1))
    {
        return 0;
    }

    D2UnitStrc* pTarget = hUnit;
    if (bUseOnMerc && hUnit->dwUnitType == UNIT_PLAYER && ptGame->bExpansion)
    {
        if (!ITEMSIsA(pItem, 0x4C) && !ITEMSIsA(pItem, 0x51) && !ITEMSIsA(pItem, 0x50))
        {
            return 0;
        }

        D2UnitStrc* pPet = PLAYERPETS_GetFirstPetByType(ptGame, hUnit, 7, 0);
        if (pPet)
        {
            pTarget = pPet;
        }
    }

    if (!SKILLITEM_pSpell_Handler(ptGame, pTarget, pItem, pItem, nX, nY))
    {
        return 0;
    }

    const int nBeltX = CLIENTS_GetUnitX(pItem);
    const int nSkillId = ITEMMODE_GetBookOrScrollSkillId(pItem);
    if (nSkillId != -1)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(hUnit, nSkillId, -1);
        if (pSkill)
        {
            int nQuantity = SKILLS_GetQuantity(pSkill) - 1;
            if (nQuantity <= 0)
            {
                if (UNITS_GetRightSkill(hUnit) == pSkill)
                {
                    D2GAME_AssignSkill_6FD13800(hUnit, 0, SKILL_ATTACK, -1);
                }
                nQuantity = 0;
            }

            SKILLS_SetQuantity(pSkill, nQuantity);
            const int nUnitGUID = hUnit->dwUnitId;
            const int nUnitType = hUnit->dwUnitType;
            D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(hUnit, szItemModeCpp, 0x136D), nUnitType, nUnitGUID, nSkillId, nQuantity);
        }
    }

    ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 0x1370);
    ITEMMODE_RemoveBeltItem(ptGame, hUnit, pItem);
    ITEMMODE_CompactBeltColumn(ptGame, hUnit, nBeltX);
    return 1;
}

static inline D2UnitStrc* ITEMMODE_GetOtherBodyLocItem(D2InventoryStrc* pInventory, int nBodyLoc, D2UnitStrc* pItem)
{
    const int nOppositeBodyLoc = ITEMMODE_GetOppositeBodyLoc(nBodyLoc);
    if (!nOppositeBodyLoc)
    {
        return pItem;
    }

    return INVENTORY_GetItemFromBodyLoc(pInventory, nOppositeBodyLoc);
}

// 0x005628C0
int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nCubeGUID, int* pItemStatus)
{
    D2_ASSERT(ptGame, 5287);
    D2_ASSERT(hUnit, 5288);

    ITEMMODE_ClearTargetingFlags(hUnit, szItemModeCpp, 5291);

    *pItemStatus = 0;
    D2UnitStrc* pCube = SUNIT_GetServerUnit(ptGame, 4, nCubeGUID);
    if (!pCube)
    {
        *pItemStatus = 1;
        return 0;
    }
    if ((!pCube ? 0 : pCube->dwAnimMode) || ITEMS_GetBaseCode(pCube) != 0x20786F62)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (D2GAME_PLRTRADE_IsInteractingWithPlayer(ptGame, hUnit, 1) && ITEMS_GetInvPage(pCube))
    {
        SUNIT_AttachSound(hUnit, 19, hUnit);
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!pItem)
    {
        *pItemStatus = 1;
        return 0;
    }

    if (pItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pItem->dwAnimMode != IMODE_ONGROUND && pItem->dwAnimMode != IMODE_ONCURSOR)
    {
        *pItemStatus = 1;
        return 0;
    }

    if ((!pCube ? 6 : pCube->dwUnitType) == 4)
    {
        if (!pCube ? 0 : pCube->dwAnimMode)
        {
            *pItemStatus = 1;
            return 0;
        }

        ITEMS_SetInvPage(pItem, 3);
        D2GAME_PlaceItem_6FC44410(szItemModeCpp, 5356, ptGame, hUnit, !pItem ? -1 : pItem->dwUnitId, 0, 0, 1, 1, 0);
        return 1;
    }

    return 0;
}

static inline int sub_M70_ItemGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int sub_M70_ItemGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00562A30
int __fastcall ITEMMODE_EquipStoredItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc)
{
    D2_ASSERT(ptGame, 0x14F6);
    D2_ASSERT(pUnit, 0x14F7);

    ITEMMODE_ClearTargetingFlags(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x14FA);

    D2UnitStrc* hGridItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!hGridItem)
    {
        return 0;
    }

    if (hGridItem->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (hGridItem->dwAnimMode != IMODE_STORED)
    {
        return 0;
    }

    if (!ITEMS_CheckRequirements(hGridItem, pUnit, 0, 0, 0, 0))
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hGridItem);
    D2_ASSERT(hRemove, 0x1512);
    D2_ASSERT(hGridItem == hRemove, 0x1513);

    const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, 0, ptGame->bExpansion);
    INVENTORY_Return(".\\ITEMS\\ItemMode.cpp", 0x1515, pInventory, CLIENTS_GetUnitX(hGridItem), CLIENTS_GetUnitY(hGridItem), nInventoryRecordId, 0, 0);
    ITEMS_SetInvPage(hGridItem, 0xFF);

    if (sub_0063BDB0(pInventory, hGridItem, nBodyLoc))
    {
        if (INVENTORY_PlaceItemInSocket(pInventory, hGridItem, 3))
        {
            ITEMS_SetBodyLocation(hGridItem, nBodyLoc);
            sub_0063D1D0_InventoryItemCall(pInventory, hGridItem);
            INVENTORY_SetCursorItem(pInventory, 0);
            D2_ASSERT(!ITEMSIsA(hGridItem, 0x0D), 0x151D);

            sITEMSAddStatsList(ptGame, hGridItem, pUnit, 0);
            hGridItem->dwFlags &= ~2u;
            UNITS_ChangeAnimMode(hGridItem, 1);
            ITEMS_SetInvPage(hGridItem, 0xFF);
            ITEMS_SetItemCMDFlag(hGridItem, 0x8000, 1);

            if (D2GAME_CheckHasFilledSockets(hGridItem, ".\\ITEMS\\ItemMode.cpp", 0x1527))
            {
                ITEMS_SetItemFlag(hGridItem, 1, 1);
            }

            if (ITEMS_CheckItemFlag(hGridItem, 0x4000, 0x152A, ".\\ITEMS\\ItemMode.cpp"))
            {
                ITEMS_SetItemFlag(hGridItem, 0x4000, 0);
            }

            INVENTORY_AddItemToTradeInventory(pInventory, hGridItem);
            ITEMMODE_RefreshSkillsForEquippedWeapons(pUnit);
            UNITS_RefreshInventory(pUnit, 1);
            ITEMMODE_RecalcEquippedItemStates(ptGame, pUnit, 0);
            return 1;
        }

        sub_0063BE30(pInventory, nBodyLoc);
        D2_ASSERT(0, 0x1534);
    }

    D2_ASSERT(0, 0x1537);
    return 0;
}

static inline int UNIT_TypeOrInvalid(D2UnitStrc* pUnit)
{
    if (pUnit) return pUnit->dwUnitType;
    return 6;
}

// 0x00562E00
int __fastcall ITEMMODE_EquipItemAtResolvedBodyLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSkipRequirementCheck)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    int nBodyLoc;
    if (ITEMMODE_FindFreeBodyLocation(pUnit, pItem, &nBodyLoc, bSkipRequirementCheck))
    {
        if (INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
        {
            if (nBodyLoc != 0xB && nBodyLoc != 0xC)
            {
                if (INVENTORY_PlaceItemInSocket(pInventory, pItem, 3))
                {
                    ITEMS_SetBodyLocation(pItem, nBodyLoc);
                    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pItem);
                    INVENTORY_SetCursorItem(pInventory, 0);
                    sITEMSAddStatsList(pGame, pItem, pUnit, 0);
                    if (pItem)
                    {
                        pItem->dwFlags &= ~2;
                    }
                    UNITS_ChangeAnimMode(pItem, 1);
                    ITEMS_SetItemCMDFlag(pItem, 0x200, 1);
                    if (pItem)
                    {
                        pItem->dwFlags &= ~0x2000000;
                    }
                    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
                    UNITS_RefreshInventory(pUnit, 1);
                    ITEMS_SetInvPage(pItem, 0xFF);
                    ITEMMODE_RefreshSkillsForEquippedWeapons(pUnit);
                    return 1;
                }
                sub_0063BE30(pInventory, nBodyLoc);
                D2_ASSERT(0, 0x1671);
            }
            D2_ASSERT(0, 0x1656);
        }
        D2_ASSERT(0, 0x1674);
    }
    return 0;
}

// 0x00563FE0
int __fastcall D2GAME_Transmogrify_6FC4A660(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2_ASSERT(ptGame, 0x1619);
    D2_ASSERT(pUnit, 0x161A);
    D2_ASSERT(pItem, 0x161B);
    D2_ASSERT(pItem->dwUnitType == UNIT_ITEM, 0x161C);

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1622);

    if (pItemsTxtRecord->nTransmogrify)
    {
        int nItemId;
        D2_ASSERT(DATATBLS_GetItemRecordFromItemCode(pItemsTxtRecord->dwTransmogrifyType, &nItemId), 0x1627);

        if (pItem->dwAnimMode == IMODE_STORED)
        {
            D2ItemDropStrc itemDrop;
            ITEMMODE_InitItemDropFromItem(nItemId, ptGame, pItem, &itemDrop);
            ITEMMODE_RemoveItemAndNotify(ptGame, pUnit, pItem);

            D2UnitStrc* pNewItem = sub_00558D90_SpawnItem(ptGame, &itemDrop, 0);
            D2_ASSERT(pNewItem, 0x162D);

            if (pItemsTxtRecord->nTmogMin > 0 && pItemsTxtRecord->nTmogMax > 0)
            {
                const int nQuantity = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, pItemsTxtRecord->nTmogMax - pItemsTxtRecord->nTmogMin) + pItemsTxtRecord->nTmogMin;
                STATLIST_SetUnitStat(pNewItem, STAT_QUANTITY, nQuantity, 0);
            }
            else
            {
                STATLIST_SetUnitStat(pNewItem, STAT_QUANTITY, 0, 0);
            }

            ITEMS_SetInvPage(pNewItem, 0);

            const int nNewItemGUID = pNewItem->dwUnitId;
            if (D2GAME_PlaceItem_6FC44410(".\\ITEMS\\ItemMode.cpp", 0x163B, ptGame, pUnit, nNewItemGUID, itemDrop.nX, itemDrop.nY, 0, 1, 0))
            {
                return 1;
            }

            const int nRetryGUID = pNewItem->dwUnitId;
            if (D2GAME_PlaceItem_6FC44410(".\\ITEMS\\ItemMode.cpp", 0x163D, ptGame, pUnit, nRetryGUID, 0, 0, 1, 1, 0))
            {
                return 1;
            }

            const int nDropGUID = (pNewItem ? pNewItem->dwUnitId : -1);
            sub_6FC44030(ptGame, pUnit, nDropGUID);
            return 1;
        }
    }

    return 0;
}

// 0x00562F30
int __fastcall ITEMMODE_RecoverCorpseItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pCorpse)
{
    if (!pPlayer || !pCorpse)
    {
        return 0;
    }

    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    D2InventoryStrc* pCorpseInventory = pCorpse->pInventory;
    if (!pPlayerInventory || !pCorpseInventory)
    {
        return 0;
    }

    int bItemRemoved = 0;
    int nCounter = 0;
    do
    {
        bItemRemoved = 0;
        nCounter = 0;
        for (int i = 1; i < 13; ++i)
        {
            int nBodyLoc = i;
            D2UnitStrc* pCorpseItem = INVENTORY_GetItemFromBodyLoc(pCorpseInventory, i);
            if (pCorpseItem)
            {
                ++nCounter;

                if (ITEMS_CheckRequirements(pCorpseItem, pPlayer, 0, 0, 0, 0))
                {
                    D2UnitStrc* pPlayerItem = INVENTORY_GetItemFromBodyLoc(pPlayerInventory, i);
                    D2UnitStrc* pOtherPlayerItem = ITEMMODE_GetOtherBodyLocItem(pPlayerInventory, i, pPlayerItem);

                    int bMoved = 0;
                    if (!ITEMMODE_CheckAndResolveBodySlotPair(pPlayer, pCorpseItem, &pPlayerItem, &pOtherPlayerItem, &nBodyLoc))
                    {
                        if (ITEMMODE_PlaceItemAtFreeInventoryPosition(pGame, 0, 0, szItemModeCpp, 0x176B, pPlayer, pCorpseItem))
                        {
                            ITEMS_ScheduleDurabilityReplenishment(pGame, pCorpseItem);
                            ITEMS_ScheduleQuantityReplenishment(pGame, pCorpseItem);
                            bMoved = 1;
                        }
                    }
                    else
                    {
                        const int eLoc = nBodyLoc;
                        D2_ASSERT(!INVENTORY_GetItemFromBodyLoc(pPlayerInventory, eLoc), 0x1775);

                        if (INVENTORY_PlaceItemInBodyLoc(pPlayerInventory, pCorpseItem, eLoc))
                        {
                            int nSocketType = 3;
                            if (eLoc == 11 || eLoc == 12)
                            {
                                nSocketType = 4;
                            }

                            if (INVENTORY_PlaceItemInSocket(pPlayerInventory, pCorpseItem, nSocketType))
                            {
                                INVENTORY_SetCursorItem(pPlayerInventory, 0);
                                ITEMS_SetBodyLocation(pCorpseItem, eLoc);
                                pCorpseItem->dwFlags &= ~2u;
                                UNITS_ChangeAnimMode(pCorpseItem, 1);
                                ITEMS_SetItemCMDFlag(pCorpseItem, 8, 1);
                                INVENTORY_AddItemToTradeInventory(pPlayerInventory, pCorpseItem);
                                UNITS_RefreshInventory(pPlayer, 1);
                                pCorpseItem->dwFlags &= ~0x02000000u;
                                ITEMS_SetInvPage(pCorpseItem, 0xFF);

                                if (nSocketType == 3)
                                {
                                    sub_0063D1D0_InventoryItemCall(pPlayerInventory, pCorpseItem);
                                    sITEMSAddStatsList(pGame, pCorpseItem, pPlayer, 0);
                                    ITEMMODE_AddItemScrollSkillQuantity(pPlayer, pCorpseItem);
                                    ITEMMODE_RefreshSkillsForEquippedWeapons(pPlayer);
                                }

                                QUESTS_ItemPickedUp(pGame, pPlayer, pCorpseItem);
                                ITEMS_ScheduleDurabilityReplenishment(pGame, pCorpseItem);
                                ITEMS_ScheduleQuantityReplenishment(pGame, pCorpseItem);
                                bMoved = 1;
                            }
                            else
                            {
                                sub_0063BE30_Return(pPlayerInventory, eLoc);
                            }
                        }
                    }

                    if (bMoved)
                    {
                        ITEMS_SetItemFlag(pCorpseItem, 1, 1);
                        INVENTORY_RemoveItemFromInventory(pCorpseInventory, pCorpseItem);
                        sub_0063BE30_Return(pCorpseInventory, i);
                        bItemRemoved = 1;
                        --nCounter;
                    }
                }
            }
        }
    }
    while (nCounter && bItemRemoved);

    int bAllowInventoryFallback = 0;
    int nMoved;
    int nResult;
    while (1)
    {
        nMoved = 0;
        nResult = 1;
        D2UnitStrc* pCorpseItem = INVENTORY_GetFirstItem(pCorpseInventory);
        if (!pCorpseItem)
        {
            break;
        }

        do
        {
            D2UnitStrc* pNextItem = INVENTORY_GetNextItem(pCorpseItem);
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCorpseItem);
            if (!ITEMMODE_CanPickUpItem(pGame, pPlayer, pItem))
            {
                nResult = 0;
            }
            else
            {
                if (!ITEMMODE_EquipItemAtResolvedBodyLocation(pGame, pPlayer, pItem, 0))
                {
                    if (ITEMS_CheckIfBeltable(pItem) && INVENTORY_PlaceItemInFreeBeltSlot(pPlayerInventory, pItem))
                    {
                        if (!INVENTORY_PlaceItemInSocket(pPlayerInventory, pItem, 2))
                            goto NextLooseItem;
                        INVENTORY_SetCursorItem(pPlayerInventory, 0);

                        D2_ASSERT(pItem, 0x24E);
                        if (pPlayer->dwUnitType == UNIT_PLAYER)
                        {
                            ITEMMODE_UpdateBookScrollSkillQuantity(1, pPlayer, pItem);
                        }

                        pItem->dwFlags &= ~2u;
                        if (ITEMS_IsCharmUsable(pItem, pPlayer))
                        {
                            sITEMSAddStatsList(pGame, pItem, pPlayer, 0);
                        }

                        UNITS_ChangeAnimMode(pItem, 2);
                        pItem->dwFlags &= ~0x02000000u;
                        ITEMS_SetItemCMDFlag(pItem, 0x2000u, 1);
                        ITEMS_SetInvPage(pItem, 0xFF);
                        INVENTORY_AddItemToTradeInventory(pPlayerInventory, pItem);
                        UNITS_RefreshInventory(pPlayer, 1);
                    }
                    else if (!bAllowInventoryFallback)
                    {
                        goto NextLooseItem;
                    }
                    else if (!ITEMMODE_PlaceItemAtFreeInventoryPosition(pGame, 0, 0, szItemModeCpp, 0x17F1, pPlayer, pItem))
                    {
                        nResult = 0;
                        goto NextLooseItem;
                    }
                }
                ++nMoved;
                ITEMS_SetItemFlag(pItem, 1, 1);
            }
NextLooseItem:

            pCorpseItem = pNextItem;
        }
        while (pCorpseItem);

        if (!nMoved)
        {
            if (bAllowInventoryFallback)
            {
                break;
            }

            bAllowInventoryFallback = 1;
        }
    }
    ITEMMODE_RecalcEquippedItemStates(pGame, pPlayer, 0);
    return nResult;
}

// 0x0055F500
void __fastcall D2GAME_UpdatePlayerVitals(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2EquipmentRefreshStateStrc refreshState;
    ITEMMODE_SaveEquipmentRefreshState(pUnit, &refreshState);

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        int nStatNotDynamic = 0;
        if (pItem && pItem->dwUnitType == UNIT_ITEM && STATLIST_GetOwner(pItem, &nStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pItem);
            STATLIST_MergeStatLists(pUnit, pItem, nStatNotDynamic);
        }

        pCurrent = pNext;
    }

    ITEMMODE_RestoreSelectedSkills(pUnit, &refreshState);
}

// 0x00563350
int __fastcall ITEMMODE_DuplicateSocketFillers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pSocketable, int a5)
{
    if (ITEMS_CheckIfSocketable(pItem))
    {
        if (!pItem->pInventory)
        {
            return 0;
        }

        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(i);
            D2UnitStrc* pDupedItem = ITEMS_Duplicate(pGame, pCheckedItem, 0, 1);
            UNITS_ChangeAnimMode(pDupedItem, IMODE_ONCURSOR);
            UNITS_SetXForStaticUnit(pDupedItem, sub_M70_ItemGetUnitX(pCheckedItem));
            UNITS_SetYForStaticUnit(pDupedItem, sub_M70_ItemGetUnitY(pCheckedItem));

            int bPlaced;
            if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pUnit, !pDupedItem ? -1 : pDupedItem->dwUnitId, GAME_GetUnitGUID(pSocketable), &bPlaced, a5, 0, 1, 0))
            {
                return 0;
            }
        }
    }

    return 1;
}

// 0x0055F640
D2UnitStrc* __fastcall ITEMMODE_FindMatchingBookWithSpace(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int* pFreeQuantity)
{
    if (!ITEMSIsA(pItem, 0x16))
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pBook = INVENTORY_UnitIsItem(pCurrent);
        pCurrent = INVENTORY_GetNextItem(pCurrent);
        if (!pBook)
        {
            continue;
        }

        if (ITEMS_GetItemType(pBook) != ITEMTYPE_BOOK)
        {
            continue;
        }

        if (ITEMS_GetInvPage(pBook))
        {
            continue;
        }

        if (!ITEMMODE_HasSameAffixes(pBook, pItem))
        {
            continue;
        }

        int nQuantity = STATLIST_UnitGetStatValue(pBook, STAT_QUANTITY, 0);
        if (nQuantity < 0)
        {
            nQuantity = 0;
        }

        const int nMaxStack = ITEMS_GetTotalMaxStack(pBook);
        if (nQuantity >= nMaxStack)
        {
            continue;
        }

        *pFreeQuantity = nMaxStack - nQuantity;
        return pBook;
    }

    return 0;
}

// 0x0055F6E0
void __fastcall ITEMMODE_AddBookQuantity(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int nValue)
{
    STATLIST_AddUnitStat(pItem, STAT_QUANTITY, nValue, 0);
    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x18E0), pItem, 1, 0x46, STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0), 0);
    ITEMMODE_AddBookScrollSkillQuantity(nValue, pUnit, pItem);
}

// 0x0055F740
D2UnitStrc* __fastcall ITEMMODE_AddScrollToMatchingBook(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bCheckOnly)
{
    if (!ITEMSIsA(pItem, 0x16))
    {
        return 0;
    }

    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pCurrent)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pBook = INVENTORY_UnitIsItem(pCurrent);
        if (ITEMS_GetItemType(pBook) == ITEMTYPE_BOOK && !ITEMS_GetInvPage(pBook) && ITEMMODE_HasSameAffixes(pBook, pItem))
        {
            const int nAdded = 1 > STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0) ? 1 : STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);
            const int nQuantity = STATLIST_UnitGetStatValue(pBook, STAT_QUANTITY, 0);
            if (nQuantity + nAdded <= ITEMS_GetTotalMaxStack(pBook))
            {
                if (!bCheckOnly)
                {
                    STATLIST_SetUnitStat(pBook, STAT_QUANTITY, nQuantity + nAdded, 0);
                    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1905), pBook, 1, 0x46, nQuantity + nAdded, 0);
                    ITEMMODE_AddBookScrollSkillQuantity(nAdded, pUnit, pBook);
                }

                return pBook;
            }
        }

        pCurrent = pNext;
    }

    return 0;
}

// 0x0055F850
void __fastcall ITEMMODE_BreakItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    ITEMS_SetItemFlag(pItem, 0x100, 1);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pUnit->pInventory, pItem);
    if (UNITS_GetAnimOrSeqMode(pItem) == 1)
    {
        D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 1, 1);
    }

    ITEMMODE_RecalcEquippedItemStates(pGame, pUnit, 0);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pUnit, 1);
    STATLIST_SetUnitStat(pItem, STAT_DURABILITY, 0, 0);

    D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x191E), pItem, 1, 0x48, 0, 0);
    ITEMS_UpdateSets(pUnit, pItem, 1, 1);
    SUNIT_AttachSound(pUnit, 9, pUnit);
}

// 0x0055F900
void __fastcall D2GAME_RepairBrokenItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = 0;
    if (pUnit)
    {
        pInventory = pUnit->pInventory;
    }

    ITEMS_SetItemFlag(pItem, 0x200, 1);
    ITEMS_SetItemFlag(pItem, 0x100, 0);
    if (pInventory)
    {
        ITEMMODE_UpdateEquippedItemStats(pGame, pItem, pUnit);
        ITEMMODE_RecalcEquippedItemStates(pGame, pUnit, 0);
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
    }

    const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
    if (nMaxDurability > 0)
    {
        STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);
        if (pUnit)
        {
            D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x193C), pItem, 1, 0x48, nMaxDurability, 0);
        }
    }

    ITEMS_UpdateSets(pUnit, pItem, 0, 0);
    if (pUnit)
    {
        ITEMMODE_RefreshSkillsForEquippedWeapons(pUnit);
    }
}

// 0x0055F9C0
void __fastcall ITEMMODE_ResetBookScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    const int nSkillId = ITEMMODE_GetBookSkillId(pItem);
    if (nSkillId == -1)
    {
        return;
    }

    STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill)
    {
        SKILLS_GetQuantity(pSkill);
    }

    SKILLS_SetQuantity(pSkill, 0);

    int nUnitGUID;
    int nUnitType;
    if (!pUnit)
    {
        nUnitGUID = -1;
        nUnitType = 6;
    }
    else
    {
        nUnitGUID = pUnit->dwUnitId;
        nUnitType = pUnit->dwUnitType;
    }

    D2GAME_PACKETS_SendPacket0x22_6FC3DBE0(UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1962), nUnitType, nUnitGUID, nSkillId, 0);
}

// 0x0055FA40
void __fastcall ITEMMODE_RebuildBookScrollSkillQuantities(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pInventory);
    int nCounter = 0;

    D2UnitStrc* pNext;
    for (; pCurrent; pCurrent = pNext)
    {
        pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        if (!pItem || pItem->dwAnimMode == IMODE_STORED)
        {
            ITEMMODE_ResetBookScrollSkillQuantity(pUnit, pItem);
            if (!ITEMS_GetInvPage(pItem))
            {
                nCounter += 1;
            }
        }
    }

    if (!nCounter)
    {
        return;
    }

    for (pCurrent = INVENTORY_GetFirstItem(pInventory); pCurrent; pCurrent = pNext)
    {
        pNext = INVENTORY_GetNextItem(pCurrent);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        if ((!pItem || pItem->dwAnimMode == IMODE_STORED) && !ITEMS_GetInvPage(pItem))
        {
            ITEMMODE_UpdateBookScrollSkillQuantity(1, pUnit, pItem);
            nCounter -= 1;
            if (!nCounter)
            {
                return;
            }
        }
    }
}

// 0x0055FB10
int __fastcall ITEMMODE_MarkItemOnCursor(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* hItem)
{
    D2_ASSERT(pUnit, 0x19A0);
    D2_ASSERT(hItem, 0x19A1);

    UNITS_ChangeAnimMode(hItem, 4);
    ITEMS_SetItemCMDFlag(hItem, 0x100000, 1);
    INVENTORY_AddItemToTradeInventory(pUnit->pInventory, hItem);
    UNITS_RefreshInventory(pUnit, 1);
    return 1;
}

// 0x0055FB80
unsigned int __fastcall ITEMMODE_PickRandomItemCode(D2GameStrc* pGame, D2ItemCodeListStrc* pList, D2UnitStrc* pUnit, int bGood)
{
    D2SeedStrc* pSeed = &pUnit->pSeed;
    const int nIndex = SEED_RollLimitedRandomNumberInline(pSeed, pList->nCountA + pList->nCountB);
    unsigned int dwCode;
    if (nIndex < pList->nCountA)
    {
        dwCode = pList->dwCodesA[nIndex];
    }
    else
    {
        dwCode = pList->dwCodesB[nIndex - pList->nCountA];
    }

    int nItemId;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId);
    if (!pItemsTxt)
    {
        return dwCode;
    }

    D2_ASSERT(pItemsTxt->wVersion <= pGame->wItemFormat, 6601);

    if (pItemsTxt->dwUberCode == 0x20202030 || !pItemsTxt->dwUberCode)
    {
        return dwCode;
    }

    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (bGood ? pDifficultyLevelsTxtRecord->dwUberCodeOddsGood : pDifficultyLevelsTxtRecord->dwUberCodeOddsNorm))
    {
        dwCode = pItemsTxt->dwUberCode;
        if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < (bGood ? pDifficultyLevelsTxtRecord->dwUltraCodeOddsGood : pDifficultyLevelsTxtRecord->dwUltraCodeOddsNorm))
        {
            dwCode = pItemsTxt->dwUltraCode;
        }
    }

    return dwCode;
}

// 0x0055FCC0
void __fastcall ITEMMODE_RemoveInventoryItemProperties(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory);
    while (pNode)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pNode);
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pNode);
        D2_ASSERT(pItem, 0x19FD);

        if (INVENTORY_GetItemNodePage(pNode) == 3 || INVENTORY_GetItemNodePage(pNode) == 1 && ITEMS_IsCharmUsable(pItem, pUnit))
        {
            D2COMMON_11079_Return0(pUnit, pItem);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(hRemove, 0x1A0F);
            D2_ASSERT(pItem == hRemove, 0x1A10);

            if (INVENTORY_GetItemNodePage(pNode) == 3)
            {
                sub_0063BE30_Return(pInventory, INVENTORY_GetBodyLocFromEquippedItem(pInventory, pItem));
            }

            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, pItem, pUnit, 0, 1);
            ITEMMODE_RecalcEquippedItemStates(pGame, pUnit, 0);
        }

        pNode = pNext;
    }

    INVENTORY_RemoveAllItems(pInventory);
}

// 0x00563470
void __fastcall ITEMMODE_DetachItemFromOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    if (!pGame || !pUnit)
        return;
    if (UNIT_TypeOrInvalid(pItem) != 4)
        return;
    D2UnitStrc* pValidItem = pItem;
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
        return;
    switch (pValidItem->dwAnimMode)
    {
    case IMODE_STORED:
        ITEMS_SetItemCell(pValidItem, ITEMS_GetInvPage(pValidItem));
        if (UNIT_TypeOrInvalid(pUnit) == 0)
        {
            D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\ITEMS\\ItemMode.cpp", 0x1A75);
            if (pClient)
            {
                int nFlags = 0;
                ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
                D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pValidItem, nFlags);
            }
        }
        D2GAME_RemoveItem(pGame, pUnit, pValidItem, 0);
        break;
    case IMODE_EQUIP:
    {
        const int nBodyLoc = INVENTORY_GetItemsXPosition(pInventory, pValidItem);
        int nResult;
        ITEMMODE_UnequipBodyItem(pGame, pUnit, nBodyLoc, 1, &nResult);
        break;
    }
    case IMODE_ONCURSOR:
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pUnit, pValidItem);
        break;
    }
}

#include "gen/data/Source/D2Game/ITEMS/ItemMode.inc"
