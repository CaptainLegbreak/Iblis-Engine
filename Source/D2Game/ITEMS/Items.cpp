#include "D2ItemTypes.h"
#include "D2LevelIds.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2ItemModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2TxtTables.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
#include "D2SaveHeader.h"
#include "D2LanguageNames.h"
#include "D2BookDataTbl.h"
#include "D2ItemDataTbl.h"

struct D2ItemUnkStrc
{
    int nIndex;
    D2ItemsTxt* pItemsTxtRecord;
};

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId);                                              // 0x006427F0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                         // 0x0045C3E0

struct D2ClientStrc;

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MIN(a,b) ((a)<(b)?(a):(b))

#define SEND(stat,value,line) D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(UnitGetClient(pPlayer,".\\ITEMS\\Items.cpp",line),pItem,1,stat,value,0)

union D2SeedStrc;

struct D2StatListExStrc;

struct D2ItemsTxt;

struct D2UniqueSelection;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __fastcall sub_00472280(D2SeedStrc* pSeed, int nOffset, int nRange); // 0x00472280

int __fastcall ITEMMODE_SelectRandomArmorItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555E70

int __fastcall ITEMMODE_SelectRandomWeaponItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity); // 0x00555FB0

int __fastcall ITEMMODE_SelectRandomMiscItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts); // 0x005560F0

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinatesWithField(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, D2CoordStrc* pFieldCoord, int nUnitSize, unsigned int nMask, unsigned int nFieldMask, int bAllowNeighborRooms); // 0x0064E810

static int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts); // 0x00556240

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

int __fastcall ITEMS_IsUniqueAlreadyDropped(D2GameStrc* pGame, D2UnitStrc* pItem); // 0x005564D0

struct D2UniqueSelection
{
    int nIndex,nRarity;
};

extern D2UniqueSelection gUniqueSelections[]; // 0x008846F8

unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc*); // 0x0062A670

int __stdcall ITEMS_HasDurability(D2UnitStrc*); // 0x00629930

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260

void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMMODS_AssignProperty(int nType, D2UnitStrc* a2, D2UnitStrc* pItem, const void* pMods, int nPropSet, int nApplyType); // 0x0065FEC0

int __stdcall ITEMS_GetItemLevel(D2UnitStrc*); // 0x006281E0

int __stdcall ITEMS_GetUniqueColumnFromItemsTxt(D2UnitStrc*); // 0x00628C70

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall ITEMMODE_AssignItemQualityAndProperties(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop); // 0x00557450

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc* pItem); // 0x006295B0

int __stdcall ITEMS_GetSpawnStack(D2UnitStrc* pItem); // 0x00629660

int __stdcall ITEMS_GetMinStack(D2UnitStrc* pItem); // 0x006296F0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

int __stdcall ITEMS_GetQuiverType(D2UnitStrc* pItem); // 0x0062E740

unsigned char __stdcall ITEMS_GetVarInvGfxCount(D2UnitStrc* pItem); // 0x0062E8D0

void __stdcall ITEMMODS_SetRandomElixirFileIndex(D2UnitStrc* pItem); // 0x0065E8E0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc*); // 0x00625E00

void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc*,D2UnitStrc*); // 0x00558530

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x3E_6FC3EC20(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short a6); // 0x0053D130

int __stdcall sub_006280A0(D2UnitStrc*,int,int,const char*); // 0x006280A0

void __fastcall ITEMMODE_BreakItem(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055F850

void __fastcall PLRMODE_HandleDepletedWeapons(D2GameStrc*,D2UnitStrc*); // 0x00580310






#define ITEMDROPFLAG_SUPERIOR 0x40

#define UNITFLAG_TARGETABLE 2

struct D2ItemRatioTxt;

struct D2QualityModsStrc;

struct D2ItemTypesTxt;

struct D2SaveHeaderStrc;

struct D2PlayerDataStrc;

int __stdcall ITEMS_RollUniqueItem(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005566B0

int __stdcall ITEMS_RollItemQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x00556F60

unsigned short __fastcall ITEMS_RollTemperedItemAffix(D2UnitStrc* pItem, int bPrefix); // 0x005C1BC0

int __fastcall D2GAME_RollRareItem_6FC53360(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21A0

int __fastcall ITEMS_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C21D0

int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll); // 0x005C2540

int __fastcall ITEMS_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2940

int __fastcall ITEMS_RollSuperiorItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2AD0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

void __stdcall ITEMS_SetItemQuality(D2UnitStrc* pItem, int nQuality); // 0x00627EA0

void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0

void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix); // 0x00628010

void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* hItem); // 0x00628590

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

void __stdcall ITEMS_AddSockets(D2UnitStrc* pItem, int nSockets); // 0x0062BCB0

D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0

unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed); // 0x00650E50

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

static void __stdcall ITEMS_AssignLegacySpecialProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x00556D80

static void D2GAME_ITEMS_AssignSpecial_6FC4DB60(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x00556E80

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc*); // 0x00554010

D2ItemRatioTxt* __stdcall DATATBLS_GetItemRatioTxtRecord(int, unsigned char, unsigned short); // 0x00637910

extern const int gnQualityOrder[6]; // 0x006E1138

void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555AE0

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180

typedef void(__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x00557FA0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

int __fastcall ITEMS_GetDiminishedMagicFind(int nMagicFind, int nFactor, int nFactor2); // 0x00558610


D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned short wUnitInitFlags, int nMode, unsigned int a9); // 0x00555230

int __stdcall ITEMS_DecodeItemFromBitstream(D2UnitStrc* pItem, unsigned char* pBitstream, int nSize, int bCheckForHeader, int* pSocketedItemCount, unsigned int dwVersion, int* pFail); // 0x0062E430

void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558580

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall ITEMMODE_ClearTargetingFlags(D2UnitStrc* pUnit, const char* szFile, int nLine); // 0x0055BF50

void __fastcall ITEMMODE_AddItemScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055C270

void __fastcall sITEMSAddStatsList(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int a4); // 0x0055C2C0

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210

int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot); // 0x0063C4F0

int __stdcall INVENTORY_PlaceItemInFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C790

void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

static void __stdcall ITEMS_RollDropSockets(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);

static void __stdcall ITEMS_ResetToNormalQuality(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int nLowSeed);

static int ITEMS_ResetToSuperiorQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed);

static int __stdcall ITEMS_ResetToMagicQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed);

static int ITEMS_ResetToRareQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed);

static void __stdcall ITEMS_AssignSpecialPropertiesForFormat(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);

static int __stdcall ITEMS_AssignDropMagicAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem);

static int __stdcall ITEMS_AssignCharmAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem);

static void ITEMS_MakeEthereal(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop);

static void ITEMS_ClearAffixesAndFileIndex(D2UnitStrc** ppItem);



#define ITEMDROPFLAG_NEVERETH 0x2

#define ITEMDROPFLAG_NOSOCKETS 0x8


#define EVENTTYPE_STATREGEN 3

#define IFLAG_RUNEWORD 0x4000000

struct D2StaticPathStrc;

struct D2ItemDataStrc;

struct D2ActiveRoomStrcView;

extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110

unsigned char __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem); // 0x006283A0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

extern int gdwDropHealthPotionCodes[4]; // 0x00731F4C

extern unsigned int gnDropHealthPotionCodeCount; // 0x00731F5C

extern int gdwDropManaPotionCodes[4]; // 0x00731F60

extern unsigned int gnDropManaPotionCodeCount; // 0x00731F70

struct D2ActiveRoomStrcView
{
    char unk0x00[0x6C];
    D2SeedStrc pSeed;
};

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_ABS(a) ((a) < 0 ? -(a) : (a))

#define D2_SEED_ROLL(pUnit, nOut) \
    { \
        const unsigned __int64 lSeedRoll = (pUnit)->pSeed.nHighSeed + 0x6AC690C5i64 * (pUnit)->pSeed.nLowSeed; \
        (pUnit)->pSeed.nHighSeed = (unsigned int)(lSeedRoll >> 32); \
        (pUnit)->pSeed.nLowSeed = (unsigned int)lSeedRoll; \
        nOut = (unsigned int)lSeedRoll; \
    }

struct D2TCModsStrc;

struct D2TCExInfoStrc;

struct D2TCArrayStrc;

struct D2QualityModsStrc
{
    unsigned short f_0;
    unsigned short wRare;
    unsigned short wSet;
    unsigned short wUnique;
    unsigned short wSuperior;
    unsigned short wNormal;
};

struct D2TCModsStrc
{
    unsigned short nMods[6];
};

struct D2TCExInfoStrc
{
    int nClassic;
    int nProb;
    unsigned short nItemId;
    unsigned short nTxtRow;
    unsigned char nFlags;
    char unk0x0D[1];
    D2TCModsStrc tMods;
    unsigned short unk0x1A;
};

struct D2TCExShortStrc
{
    short nGroup;
    short nLevel;
    int nTypes;
    int nClassic;
    int nProb;
    int nPicks;
    int nNoDrop;
    short unk0x18;
    D2TCModsStrc tMods;
    short unk0x26;
    D2TCExInfoStrc* pInfo;
};

struct D2TCArrayStrc
{
    D2TCExShortStrc* pTC;
    int nPicks;
    D2TCModsStrc tMods;
};

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

void __fastcall D2GAME_SetStatOrResetGold_6FC7CA70(D2UnitStrc* pUnit, int nStat, int nValue); // 0x00530EA0

int __fastcall PLAYER_GetPlayerCount(D2GameStrc* pGame); // 0x00535790

int __fastcall PARTY_GetLivingPartyMemberCountInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005408E0

int __stdcall ITEMS_CheckItemTypeIfThrowable(int nItemType); // 0x00628860

int __stdcall ITEMS_IsSocketFiller(D2UnitStrc* pItem); // 0x0062BEB0

int __fastcall GAME_GetUnitGUID(D2UnitStrc*); // 0x00451F50

D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc*, D2ActiveRoomStrc*, unsigned char*, unsigned int, int, D2ItemSaveStrc*, unsigned int*, unsigned int); // 0x00558CB0

int __fastcall D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(D2GameStrc*, D2UnitStrc*, int, int, int*, int, int, int, int); // 0x00562660

void __fastcall D2GAME_ResetSomeItemFlags_6FC415F0(D2GameStrc*, D2UnitStrc*); // 0x005979B0

int __stdcall ITEMS_GetCompactItemDataFromBitstreamDefault(unsigned char* pBitstream, unsigned int nSize, int bCheckForHeader, void* pItemSave); // 0x0062E410

int __stdcall ITEMS_SerializeItemToBitstream(D2UnitStrc*, unsigned char*, int, int, int, int); // 0x006313E0

static int ITEMS_GetMagicFindBonus(D2UnitStrc* pPlayer);

static int __stdcall ITEMS_RollDropQuality(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer, D2QualityModsStrc* pMods, int nItemLevel, int nItemId);

static D2UnitStrc* __stdcall ITEMS_CreateDropAtUnit(D2GameStrc* pGame, int nQuality, int nItemIndex, int nFlags, int nItemId, D2UnitStrc* pUnit);

int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int a4); // 0x00557AB0

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag); // 0x00538670

void __stdcall ITEMS_SetItemLevel(D2UnitStrc* pItem, int nItemLevel);                                       // 0x00628220

void __stdcall ITEMS_SetItemFormat(D2UnitStrc* pItem, unsigned short nItemFormat);                          // 0x0062A6C0

D2UnitStrc* __fastcall ITEMS_DropRandomItemNearCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDropOut);

static unsigned int ITEMS_HasUniqueBeenDroppedAlready(D2GameStrc* pGame, int nUniqueItemId);

static int __stdcall ITEMS_CanUniqueItemBeDropped(D2GameStrc* pGame, D2UnitStrc* pItem);

static void ITEMS_RollArmorClass(D2UnitStrc* pItem);

static void ITEMS_SetWeaponDamage(D2UnitStrc* pItem);

static void ITEMS_RollVarInvGfx(D2UnitStrc* pItem);

static int gnGoldItemId; // 0x0088C6F8

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId);

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber_00555E00(D2SeedStrc* pSeed, int nMax)
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

// 0x00555E00
static int __stdcall ITEMS_CanSelectRandomItem(D2SeedStrc* pSeed, int bIgnoreRarity, D2ItemsTxt* pItemsTxtRecord, int nItemType, int nLevelId)
{
    if (nLevelId <= 0)
    {
        nLevelId = LEVEL_ROGUEENCAMPMENT;
    }

    if (pItemsTxtRecord->nSpawnable > 0 && !pItemsTxtRecord->nQuest && pItemsTxtRecord->nLevel <= nLevelId)
    {
        if (!bIgnoreRarity)
        {
            const int nChance = pItemsTxtRecord->nRarity - DRLG_GetActNoFromLevelId(nLevelId);
            if (nChance > 0 && ITEMS_RollLimitedRandomNumber(pSeed, nChance))
            {
                return 0;
            }
        }

        if (nItemType == -1 || pItemsTxtRecord->wType[0] == nItemType)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00555E70
int __fastcall ITEMMODE_SelectRandomArmorItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = pItemDataTbl->pArmor;
    const int nBase = pItemsTxtRecord - pItemDataTbl->pItemsTxt;
    const int nCount = pItemDataTbl->pMisc - pItemsTxtRecord;
    int nMax = 0;
    if (!pItemsTxtRecord)
    {
        return -1;
    }

    D2ItemUnkStrc data[1024];
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMS_CanSelectRandomItem(pSeed, bIgnoreRarity, &pItemsTxtRecord[i], nItemType, nLevelId)
            && (pGame->bExpansion || pItemsTxtRecord[i].wVersion < 100) && nMax < 1023)
        {
            data[nMax].pItemsTxtRecord = &pItemsTxtRecord[i];
            data[nMax].nIndex = nBase + i;
            ++nMax;
        }
    }

    const int nIndex = SEED_RollLimitedRandomNumber_00555E00(pSeed, nMax);
    if (nIndex > nMax)
    {
        return -1;
    }

    D2ItemUnkStrc* pData = &data[nIndex];
    if (!pData)
    {
        return -1;
    }

    return pData->nIndex;
}

// 0x00555FB0
int __fastcall ITEMMODE_SelectRandomWeaponItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    D2ItemsTxt* pItemsTxtRecord = pItemDataTbl->pWeapons;
    const int nBase = pItemsTxtRecord - pItemDataTbl->pItemsTxt;
    const int nCount = pItemDataTbl->pArmor - pItemsTxtRecord;
    int nMax = 0;
    if (!pItemsTxtRecord)
    {
        return -1;
    }

    D2ItemUnkStrc data[1024];
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMS_CanSelectRandomItem(pSeed, bIgnoreRarity, &pItemsTxtRecord[i], nItemType, nLevelId)
            && (pGame->bExpansion || pItemsTxtRecord[i].wVersion < 100) && nMax < 1023)
        {
            data[nMax].pItemsTxtRecord = &pItemsTxtRecord[i];
            data[nMax].nIndex = nBase + i;
            ++nMax;
        }
    }

    const int nIndex = SEED_RollLimitedRandomNumber_00555E00(pSeed, nMax);
    if (nIndex > nMax)
    {
        return -1;
    }

    D2ItemUnkStrc* pData = &data[nIndex];
    if (!pData)
    {
        return -1;
    }

    return pData->nIndex;
}

// 0x005560F0
int __fastcall ITEMMODE_SelectRandomMiscItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts)
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    const int nBase = pItemDataTbl->pMisc - pItemDataTbl->pItemsTxt;
    const int nCount = &pItemDataTbl->pItemsTxt[pItemDataTbl->nItemsTxtRecordCount] - pItemDataTbl->pMisc;

    D2ItemsTxt* pItemsTxtRecord = pItemDataTbl->pMisc;
    int nMax = 0;
    if (!pItemsTxtRecord)
    {
        return -1;
    }

    D2ItemUnkStrc data[1024];
    for (int i = 0; i < nCount; ++i)
    {
        if (bAllowBodyParts || pItemsTxtRecord[i].wType[0] != ITEMTYPE_BODY_PART)
        {
            if (ITEMS_CanSelectRandomItem(pSeed, bIgnoreRarity, &pItemsTxtRecord[i], nItemType, nLevelId)
                && (pGame->bExpansion || pItemsTxtRecord[i].wVersion < 100) && nMax < 1023)
            {
                data[nMax].pItemsTxtRecord = &pItemsTxtRecord[i];
                data[nMax].nIndex = nBase + i;
                ++nMax;
            }
        }
    }

    const int nIndex = SEED_RollLimitedRandomNumber_00555E00(pSeed, nMax);
    if (nIndex > nMax)
    {
        return -1;
    }

    D2ItemUnkStrc* pData = &data[nIndex];
    if (!pData)
    {
        return -1;
    }

    return pData->nIndex;
}

// build: symbol ?$S1@?1??ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PATD2SeedStrc@@HHHH@Z@4IA 0x008846F0
// build: symbol ?s_nGoldItemId@?1??ITEMS_SelectRandomDropItemId@@YGHPAUD2GameStrc@@PATD2SeedStrc@@HHHH@Z@4HA 0x008846EC
// 0x00556240
static int __stdcall ITEMS_SelectRandomDropItemId(D2GameStrc* pGame, D2SeedStrc* pSeed, int nLevelId, int nItemType, int bIgnoreRarity, int bAllowBodyParts)
{
    static int s_nGoldItemId = DATATBLS_GetItemIdFromItemCode(' dlg');

    D2_ASSERT(s_nGoldItemId != -1, 0x17C);
    D2_ASSERT(s_nGoldItemId != 0, 0x17F);
    D2_ASSERT(nLevelId <= 65, 0x180);

    const int nDiff = 65 - nLevelId;
    const int nBaseLayer = nLevelId >> 1;

    int nAdd = nBaseLayer + 10;
    if (nLevelId % 2)
    {
        nAdd += 1;
    }

    const int nBaseLayerChance = nBaseLayer + nDiff + 5;
    int nWeaponChance;
    int& nWeaponChanceRef = nWeaponChance;
    nWeaponChanceRef = nBaseLayerChance + nAdd;

    const int nRand = sub_00472280(pSeed, 0, 100);
    if (nRand < nDiff)
    {
        return s_nGoldItemId;
    }

    if (nRand < nBaseLayerChance)
    {
        return ITEMMODE_SelectRandomArmorItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < nWeaponChance)
    {
        return ITEMMODE_SelectRandomWeaponItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity);
    }

    if (nRand < 100)
    {
        return ITEMMODE_SelectRandomMiscItemId(pGame, pSeed, nLevelId, nItemType, bIgnoreRarity, bAllowBodyParts);
    }

    D2_ASSERT(0, 0x1BA);
}

// 0x00556360
static void ITEMS_RollArmorClass(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1C9);

    const unsigned int nMinAc = pItemsTxtRecord->dwMinAc;
    const unsigned int nMaxAc = pItemsTxtRecord->dwMaxAc;
    const unsigned int nACValue = sub_00472280(&pItem->pSeed, nMinAc, nMaxAc - nMinAc + 1);
    D2_ASSERT(nACValue <= nMaxAc, 0x1CE);
    STATLIST_SetUnitStat(pItem, STAT_ARMORCLASS, nACValue, 0);
}

// 0x005563D0
static void ITEMS_SetWeaponDamage(D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pItemsTxtRecord, 0x1DB);

    if (pItemsTxtRecord->nMaxDam)
    {
        STATLIST_SetUnitStat(pItem, STAT_MAXDAMAGE, pItemsTxtRecord->nMaxDam, 0);
    }

    if (pItemsTxtRecord->nMinDam)
    {
        STATLIST_SetUnitStat(pItem, STAT_MINDAMAGE, pItemsTxtRecord->nMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMinDam)
    {
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MINDAMAGE, pItemsTxtRecord->n2HandMinDam, 0);
    }

    if (pItemsTxtRecord->n2HandMaxDam)
    {
        STATLIST_SetUnitStat(pItem, STAT_SECONDARY_MAXDAMAGE, pItemsTxtRecord->n2HandMaxDam, 0);
    }

    if (pItemsTxtRecord->nMaxMisDam)
    {
        STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MINDAMAGE, pItemsTxtRecord->nMinMisDam, 0);
        STATLIST_SetUnitStat(pItem, STAT_ITEM_THROW_MAXDAMAGE, pItemsTxtRecord->nMaxMisDam, 0);
    }
}

// 0x005564A0
static unsigned int ITEMS_HasUniqueBeenDroppedAlready(D2GameStrc* pGame, int nUniqueItemId)
{
    if (!pGame)
    {
        return 0;
    }

    if (nUniqueItemId < 0 || nUniqueItemId > 4096)
    {
        return 1;
    }

    return pGame->dwUniqueFlags[nUniqueItemId >> 5] & gdwBitMasks[nUniqueItemId & 0x1F];
}

static unsigned int ITEMS_HasUniqueBeenDroppedAlready_Inlined(D2GameStrc* pGame, int nUniqueItemId)
{
    if (!pGame)
    {
        return 0;
    }

    if (nUniqueItemId < 0 || nUniqueItemId > 4096)
    {
        return 1;
    }

    return pGame->dwUniqueFlags[nUniqueItemId >> 5] & gdwBitMasks[nUniqueItemId & 0x1F];
}

// 0x005564D0
int __fastcall ITEMS_IsUniqueAlreadyDropped(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (ITEMS_GetItemQuality(pItem) != ITEMQUAL_UNIQUE)
    {
        return 0;
    }

    return ITEMS_HasUniqueBeenDroppedAlready_Inlined(pGame, ITEMS_GetFileIndex(pItem));
}

static unsigned int ITEMS_HasUniqueBeenDroppedAlready_Inline(D2GameStrc* pGame, int nUniqueItemId)
{
    if (!pGame)
    {
        return 0;
    }

    if (nUniqueItemId < 0 || nUniqueItemId > 4096)
    {
        return 1;
    }

    return pGame->dwUniqueFlags[nUniqueItemId >> 5] & gdwBitMasks[nUniqueItemId & 0x1F];
}

inline D2UniqueItemsTxt* ITEMS_GetUniqueItemsTxtRecord(int nUniqueItemId)
{
    if (nUniqueItemId >= 0 && nUniqueItemId < sgptDataTables->nUniqueItemsTxtRecordCount)
    {
        return &sgptDataTables->pUniqueItemsTxt[nUniqueItemId];
    }

    return 0;
}

// 0x00556530
static int __stdcall ITEMS_CanUniqueItemBeDropped(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nFileIndex = ITEMS_GetFileIndex(pItem);
    D2UniqueItemsTxt* pUniqueItemsTxtRecord = ITEMS_GetUniqueItemsTxtRecord(nFileIndex);
    if (!pUniqueItemsTxtRecord)
    {
        return 0;
    }

    if (pUniqueItemsTxtRecord->nUniqueItemFlags[0] & gdwBitMasks[UNIQUEITEMSFLAGINDEX_NOLIMIT])
    {
        return 1;
    }

    if ((pItemsTxtRecord->nQuest || !ITEMS_IsUniqueAlreadyDropped(pGame, pItem)) && nFileIndex <= 4096)
    {
        pGame->dwUniqueFlags[nFileIndex >> 5] |= gdwBitMasks[nFileIndex & 0x1F];
        return 1;
    }

    return 0;
}

int __fastcall sub_K11_Emit005564A0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (ITEMS_CanUniqueItemBeDropped(pGame, pItem))
    {
        return ITEMS_HasUniqueBeenDroppedAlready(pGame, ITEMS_GetFileIndex(pItem));
    }

    return 0;
}

// 0x005565E0
static int __stdcall ITEMS_AssignDropMagicAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem)
{
    const int nPrefixId = pItemDrop->nPrefix[0];
    int bForceSuffixRoll = 0;
    int bForcePrefixRoll = 0;
    unsigned short nPrefix = 0;
    unsigned short nSuffix = 0;
    if (nPrefixId < 0)
    {
        bForceSuffixRoll = 1;
    }
    else
    {
        if (nPrefixId > 0)
        {
            bForcePrefixRoll = 1;
        }

        nPrefix = ITEMS_RollMagicAffixes(*ppItem, 1, bForcePrefixRoll, 1, 1, nPrefixId);
        ITEMS_AssignPrefix(*ppItem, nPrefix, 0);
        if (!nPrefix)
        {
            bForceSuffixRoll = 1;
        }
    }

    if (bForceSuffixRoll || pItemDrop->nSuffix[0] >= 0)
    {
        if (pItemDrop->nSuffix[0] > 0)
        {
            bForceSuffixRoll = 1;
        }

        nSuffix = ITEMS_RollMagicAffixes(*ppItem, 1, bForceSuffixRoll, 1, 0, pItemDrop->nSuffix[0]);
        ITEMS_AssignSuffix(*ppItem, nSuffix, 0);
    }

    if (!nPrefix && !nSuffix)
    {
        return 0;
    }

    ITEMS_SetItemFlag(*ppItem, 0x10, 0);
    ITEMS_AssignStaffModsForFormat(*ppItem, pItemDrop);
    return 1;
}

// 0x005566B0
int __stdcall ITEMS_RollUniqueItem(D2GameStrc* pGame,D2UnitStrc* pItem,D2ItemDropStrc* pItemDrop)
{
 unsigned char* const pnGameType = &pGame->nGameType;
 D2ItemsTxt* pItemsTxtRecord=DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
 if(!pItemsTxtRecord) return 0;
 unsigned short nFormat=ITEMS_GetItemFormat(pItem);
 if(ITEMS_HasDurability(pItem) && !nFormat)
 {
  int nDur=STATLIST_UnitGetStatValue(pItem,STAT_DURABILITY,0);
  int nMaxDur=sub_006253B0_GetBaseStat(pItem,73,0);
  STATLIST_SetUnitStat(pItem,STAT_DURABILITY,D2_MIN(5*nDur,255),0);
  STATLIST_SetUnitStat(pItem,STAT_MAXDURABILITY,D2_MIN(5*nMaxDur,255),0);
 }
 if(pItemDrop->bForce)
 {
  D2UniqueItemsTxt* pUnique=ITEMS_GetUniqueItemsTxtRecord(pItemDrop->nItemIndex);
  if(!pUnique) return 0;
  ITEMS_SetFileIndex(pItem,pItemDrop->nItemIndex);
  if(pUnique->dwCode!=pItemsTxtRecord->dwCode) return 1;
  ITEMS_SetItemFlag(pItem,16,0);
  ITEMMODS_AssignProperty(3,0,pItem,0,0,0);
  return 1;
 }
 D2UniqueItemsTxt* pUnique=sgptDataTables->pUniqueItemsTxt;
 if(!nFormat)
 {
  for(int i=0;i<sgptDataTables->nUniqueItemsTxtRecordCount;++i)
  {
   D2UniqueItemsTxt* pRecord=&sgptDataTables->pUniqueItemsTxt[i];
   if(*(unsigned short*)&pRecord->nVersion<100)
   {
    if(pRecord->nUniqueItemFlags[0]&gdwBitMasks[0])
    {
     if(*pnGameType || pGame->dwGameType || !(pRecord->nUniqueItemFlags[0]&gdwBitMasks[3]))
     {
      if(pItemsTxtRecord->dwCode==pRecord->dwCode)
      {
       if(!ITEMS_HasUniqueBeenDroppedAlready(pGame,i) || pItemsTxtRecord->nQuest)
       {
        ITEMS_SetFileIndex(pItem,i);
        ITEMS_SetItemFlag(pItem,16,0);
  ITEMMODS_AssignProperty(3,0,pItem,0,0,0);
  return 1;
       }
      }
     }
    }
   }
  }
  return 0;
 }
 int nCount=0;
 int nTotalRarity=0;
 int nSelected=-1;
 for(int i=0;i<sgptDataTables->nUniqueItemsTxtRecordCount;++i,++pUnique)
 {
  if(*(unsigned short*)&pUnique->nVersion>=100 && nFormat<100) continue;
  if(!(pUnique->nUniqueItemFlags[0]&gdwBitMasks[0]) || pItemsTxtRecord->dwCode!=pUnique->dwCode) continue;
  if(!*pnGameType && !pGame->dwGameType && (pUnique->nUniqueItemFlags[0]&gdwBitMasks[3])) continue;
  if(*(short*)&pUnique->nLevel>ITEMS_GetItemLevel(pItem)) continue;
  if((unsigned int)pItemDrop->nItemIndex>0 && pItemDrop->nItemIndex-1==i) nSelected=i;
  gUniqueSelections[nCount].nIndex=i;
  gUniqueSelections[nCount].nRarity=nTotalRarity;
  ++nCount;
  nTotalRarity+=pUnique->nRarity<1?1:pUnique->nRarity;
 }
 if(nCount<=0)
 {
  if(ITEMS_GetUniqueColumnFromItemsTxt(pItem)) return 1;
  ITEMS_SetFileIndex(pItem,-1);
  return 0;
 }
 int nUniqueItemId;
 if(nSelected<0)
 {
  int nRoll=sub_00472280(ITEMS_GetItemSeed(pItem),0,nTotalRarity);
  int i=1;
  while(i<nCount && nRoll>=gUniqueSelections[i].nRarity) ++i;
  nUniqueItemId=gUniqueSelections[i-1].nIndex;
 }
 else
 {
  nUniqueItemId=nSelected;
 }
 if(!pItemsTxtRecord->nQuest && ITEMS_HasUniqueBeenDroppedAlready_Inline(pGame,nUniqueItemId))
 {
  goto FailedUnique;
 }
 pUnique=ITEMS_GetUniqueItemsTxtRecord(nUniqueItemId);
 if(!pUnique || pItemsTxtRecord->dwCode!=pUnique->dwCode) return 0;
 ITEMS_SetFileIndex(pItem,nUniqueItemId);
 if(ITEMS_CanUniqueItemBeDropped(pGame,pItem))
 {
  ITEMS_SetItemFlag(pItem,16,0);
  ITEMMODS_AssignProperty(3,0,pItem,0,0,0);
  return 1;
 }
FailedUnique:
 ITEMS_SetFileIndex(pItem,-1);return 0;
}

inline D2ItemsTxt* ITEMMODE_GetItemsTxtRecordOfItem_H10(D2UnitStrc* pItem)
{
    const int nType = pItem ? pItem->dwUnitType : UNIT_INVALID;
    if (nType == 4)
    {
        return DATATBLS_GetItemsTxtRecord(pItem->dwClassId);
    }

    return 0;
}

// 0x00556A60
static int __stdcall ITEMS_AssignCharmAffixes(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    unsigned short wPrefix = 0;
    unsigned short wSuffix = 0;
    int nRand = 0;
    if (pItemDrop->nPrefix[0] > 0)
    {
        wPrefix = ITEMS_RollMagicAffixes(pItem, 1, 1, 1, 1, pItemDrop->nPrefix[0]);
        ITEMS_AssignPrefix(pItem, wPrefix, 0);
    }
    else if (pItemDrop->nSuffix[0] <= 0)
    {
        wSuffix = ITEMS_RollMagicAffixes(pItem, 1, 0, 1, 1, pItemDrop->nSuffix[0]);
        ITEMS_AssignPrefix(pItem, wSuffix, 0);
        if (!wSuffix)
        {
            nRand = 1;
        }
    }

    if (pItemDrop->nSuffix[0] > 0)
    {
        wSuffix = ITEMS_RollMagicAffixes(pItem, 1, 1, 1, 0, pItemDrop->nSuffix[0]);
        ITEMS_AssignSuffix(pItem, wSuffix, 0);
    }
    else if (pItemDrop->nPrefix[0] <= 0)
    {
        wPrefix = ITEMS_RollMagicAffixes(pItem, 1, nRand, 1, 0, pItemDrop->nPrefix[0]);
        ITEMS_AssignSuffix(pItem, wPrefix, 0);
    }

    if (!wPrefix && !wSuffix)
    {
        ITEMS_GetBaseCode(pItem);
        D2_ASSERT(0, 0x372);
    }

    ITEMS_SetItemFlag(pItem, 0x10, 0);
    return 1;
}

// 0x00556B60
static void __stdcall ITEMS_RollDropSockets(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemQuality(pItem) < ITEMQUAL_NORMAL)
    {
        return;
    }

    if (!ITEMS_CheckIfSocketable(pItem))
    {
        return;
    }

    if (ITEMS_CheckIfStackable(pItem))
    {
        return;
    }

    if (!ITEMS_GetMaxSockets(pItem))
    {
        return;
    }

    int nMaxSockets = ITEMS_GetMaxSockets(pItem);
    switch (pGame->nDifficulty)
    {
    case 0:
        if (nMaxSockets >= 3)
        {
            nMaxSockets = 3;
        }
        break;
    case 1:
        if (nMaxSockets >= 4)
        {
            nMaxSockets = 4;
        }
        break;
    case 2:
        if (nMaxSockets >= 6)
        {
            nMaxSockets = 6;
        }
        break;
    }

    if (nMaxSockets <= 0)
    {
        return;
    }

    if (ITEMS_GetItemFormat(pItem) >= 100 || !ITEMSIsA(pItem, 3))
    {
        int nChance = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), 100);
        if (pItemDrop->dwFlags2 & 8)
        {
            return;
        }

        if (pItemDrop->dwFlags2 & 0x10)
        {
            nChance = 0;
        }

        if ((pItemDrop->dwFlags1 & 0x800) || nChance < 33)
        {
            ITEMS_SetItemFlag(pItem, 0x800, 1);
            int nSockets;
            if (ITEMS_GetItemFormat(pItem) >= 1)
            {
                nSockets = ITEMS_GetItemStartSeed(pItem) % nMaxSockets + 1;
            }
            else
            {
                if (nMaxSockets > 3)
                {
                    nMaxSockets = 3;
                }

                if (ITEMSIsA(pItem, 0x25) && nMaxSockets > 2)
                {
                    nMaxSockets = 2;
                }

                nSockets = nMaxSockets;
            }

            ITEMS_AddSockets(pItem, nSockets);
        }
    }
}

// 0x00556CA0
static void ITEMS_MakeEthereal(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (pItemDrop->dwFlags2 & 2)
    {
        return;
    }

    if (!ITEMSIsA(pItem, 0x2D) && !ITEMSIsA(pItem, 0x32))
    {
        return;
    }

    if (!ITEMS_HasDurability(pItem))
    {
        return;
    }

    switch (ITEMS_GetItemQuality(pItem))
    {
    case ITEMQUAL_INFERIOR:
    case ITEMQUAL_SET:
        return;
    }

    if (ITEMS_IsQuestItem(pItem))
    {
        return;
    }

    int bApplyEthereality = 0;
    const int nRoll = SEED_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), 100);
    if (nRoll < 5)
    {
        bApplyEthereality = 1;
    }

    if (pItemDrop->dwFlags1 & 0x400000)
    {
        bApplyEthereality = 1;
    }

    if ((pItemDrop->dwFlags2 & 4) || bApplyEthereality)
    {
        ITEMMODS_ApplyEthereality(pItem);
        if (ITEMS_HasDurability(pItem))
        {
            const int nMaxDurability = STATLIST_GetUnitBaseStat(pItem, STAT_MAXDURABILITY, 0) / 2 + 1;
            STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, nMaxDurability, 0);
            const int nDurability = STATLIST_UnitGetStatValue(pItem, STAT_MAXDURABILITY, 0);
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nDurability, 0);
        }
    }
}

// 0x00556D80
static void __stdcall ITEMS_AssignLegacySpecialProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    switch (ITEMS_GetItemType(pItem))
    {
    case ITEMTYPE_CHARM:
        ITEMS_AssignCharmAffixes(pItemDrop, pItem);
        break;
    case ITEMTYPE_BODY_PART:
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        break;
    }
    case ITEMTYPE_PLAYER_BODY_PART:
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        ITEMS_SetItemFlag(pItem, 0x10000, 1);
        break;
    }
    case ITEMTYPE_SCROLL:
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 1), 0);
        break;
    case ITEMTYPE_BOOK:
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 0), 0);
        break;
    default:
        ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
        ITEMS_RollDropSockets(pGame, pItem, pItemDrop);
        break;
    }
}

// 0x00556E80
static void D2GAME_ITEMS_AssignSpecial_6FC4DB60(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMSIsA(pItem, 13))
    {
        ITEMS_AssignCharmAffixes(pItemDrop, pItem);
    }

    if (ITEMSIsA(pItem, 40))
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
    }

    if (ITEMSIsA(pItem, 7))
    {
        int nItemIndex = pItemDrop->nItemIndex;
        if (pItemDrop->pUnit)
        {
            nItemIndex = pItemDrop->pUnit->dwClassId;
        }

        ITEMS_SetFileIndex(pItem, nItemIndex);
        ITEMS_SetItemFlag(pItem, 0x10000, 1);
    }

    if (ITEMSIsA(pItem, 22))
    {
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 1), 0);
    }

    if (ITEMSIsA(pItem, 18))
    {
        ITEMS_AssignSuffix(pItem, ITEMS_FindBookRecordIndex(pItem, 0), 0);
    }

    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
}

// 0x00556F30
static void __stdcall ITEMS_AssignSpecialPropertiesForFormat(D2GameStrc* pGame, D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (!ITEMS_GetItemFormat(pItem))
    {
        ITEMS_AssignLegacySpecialProperties(pGame, pItem, pItemDrop);
    }
    else
    {
        D2GAME_ITEMS_AssignSpecial_6FC4DB60(pItem, pItemDrop);
    }
}

// 0x00557450
int __fastcall ITEMMODE_AssignItemQualityAndProperties(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop)
{
    D2UnitStrc* pItem = *ppItem;
    if (!pItem || (!pItem ? 6 : pItem->dwUnitType) != 4)
    {
        return 0;
    }

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    ITEMS_SetAutoAffix(*ppItem, 0);
    for (int i = 0; i < 3; ++i)
    {
        ITEMS_AssignPrefix(*ppItem, 0, i);
        ITEMS_AssignSuffix(*ppItem, 0, i);
    }

    ITEMS_AssignRarePrefix(*ppItem, 0);
    ITEMS_AssignRareSuffix(*ppItem, 0);

    int nQuality = ITEMS_RollItemQuality(*ppItem, pItemDrop);
    if (pItemDrop->nQuality)
    {
        nQuality = pItemDrop->nQuality;
    }
    ITEMS_SetItemQuality(*ppItem, nQuality);

    if (ITEMS_CanBeMagic(*ppItem))
    {
        if (ITEMS_IsQuestItem(*ppItem))
        {
            ITEMS_SetItemQuality(*ppItem, 7);
        }
        else if (!ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem))
        {
            ITEMS_SetItemQuality(*ppItem, 4);
        }
    }

    if (!ITEMS_CanBeRare(*ppItem) && ITEMS_GetItemQuality(*ppItem) == ITEMQUAL_RARE)
    {
        ITEMS_SetItemQuality(*ppItem, 4);
    }

    if (sub_00628C70(*ppItem))
    {
        ITEMS_SetItemQuality(*ppItem, 7);
    }

    if (ITEMS_CanBeNormal(*ppItem))
    {
        ITEMS_SetItemQuality(*ppItem, 2);
    }

    unsigned int nSeed;
    switch (ITEMS_GetItemQuality(*ppItem))
    {
    case ITEMQUAL_INFERIOR:
    {
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!sub_005C2FB0_ApplyLowQuality(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case ITEMQUAL_NORMAL:
        ITEMS_AssignSpecialPropertiesForFormat(pGame, *ppItem, pItemDrop);
        break;

    case ITEMQUAL_SUPERIOR:
    {
        ITEMS_SetFileIndex(*ppItem, -1);
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_RollSuperiorItem(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case ITEMQUAL_RARE:
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!D2GAME_RollRareItem_6FC53360(*ppItem, pItemDrop))
        {
            if (!ITEMS_ResetToMagicQuality(pItemDrop, ppItem, &nSeed) && !ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    case ITEMQUAL_MAGIC:
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_AssignDropMagicAffixes(pItemDrop, ppItem))
        {
            if (!ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    case ITEMQUAL_UNIQUE:
        ITEMS_SetFileIndex(*ppItem, -1);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_RollUniqueItem(pGame, *ppItem, pItemDrop))
        {
            if (ITEMS_HasDurability(*ppItem) && ITEMS_GetItemFormat(*ppItem) >= 1)
            {
                const int nDurability = STATLIST_UnitGetStatValue(*ppItem, STAT_DURABILITY, 0);
                const int nMaxDurability = STATLIST_GetUnitBaseStat(*ppItem, STAT_MAXDURABILITY, 0);
                STATLIST_SetUnitStat(*ppItem, STAT_DURABILITY, D2_MIN(3 * nDurability, 255), 0);
                STATLIST_SetUnitStat(*ppItem, STAT_MAXDURABILITY, D2_MIN(3 * nMaxDurability, 255), 0);
            }

            if (!ITEMS_ResetToRareQuality(pItemDrop, ppItem, &nSeed) && !ITEMS_ResetToMagicQuality(pItemDrop, ppItem, &nSeed) && !ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    case ITEMQUAL_CRAFT:
    {
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        const unsigned int nLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_RollCraftedItem(*ppItem, pItemDrop))
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nLowSeed);
        }
        break;
    }
    case ITEMQUAL_TEMPERED:
    {
        ITEMS_AssignRarePrefix(*ppItem, 0);
        ITEMS_AssignRareSuffix(*ppItem, 0);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        const unsigned short nPrefix = ITEMS_RollTemperedItemAffix(*ppItem, 1);
        const unsigned short nSuffix = ITEMS_RollTemperedItemAffix(*ppItem, 0);
        if (nPrefix && nSuffix)
        {
            ITEMS_AssignRarePrefix(*ppItem, nPrefix);
            ITEMS_AssignRareSuffix(*ppItem, nSuffix);
        }
        else
        {
            ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
        }
        break;
    }
    case ITEMQUAL_SET:
        ITEMS_SetFileIndex(*ppItem, -1);
        nSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
        if (!ITEMS_RollSetItem(*ppItem, pItemDrop))
        {
            if (ITEMS_HasDurability(*ppItem) && ITEMS_GetItemFormat(*ppItem) >= 1)
            {
                const int nDurability = STATLIST_UnitGetStatValue(*ppItem, STAT_DURABILITY, 0);
                const int nMaxDurability = STATLIST_GetUnitBaseStat(*ppItem, STAT_MAXDURABILITY, 0);
                STATLIST_SetUnitStat(*ppItem, STAT_DURABILITY, D2_MIN(2 * nDurability, 255), 0);
                STATLIST_SetUnitStat(*ppItem, STAT_MAXDURABILITY, D2_MIN(2 * nMaxDurability, 255), 0);
            }

            if (!ITEMS_ResetToMagicQuality(pItemDrop, ppItem, &nSeed) && !ITEMS_ResetToSuperiorQuality(pItemDrop, ppItem, &nSeed))
            {
                ITEMS_ResetToNormalQuality(pGame, pItemDrop, ppItem, nSeed);
            }
        }
        break;

    default:
        return 0;
    }

    if (ITEMS_GetItemQuality(*ppItem) <= 0 || ITEMS_GetItemQuality(*ppItem) >= 10)
    {
        return 0;
    }

    if (ITEMS_GetItemFormat(*ppItem) >= 100)
    {
        ITEMS_MakeEthereal(*ppItem, pItemDrop);
    }

    switch (ITEMS_GetItemQuality(*ppItem))
    {
    case ITEMQUAL_INFERIOR:
    case ITEMQUAL_NORMAL:
    case ITEMQUAL_SUPERIOR:
        ITEMS_RollDropSockets(pGame, *ppItem, pItemDrop);
        break;
    }

    if (ITEMS_GetItemFormat(*ppItem) >= 100)
    {
        switch (ITEMS_GetItemQuality(*ppItem))
        {
        case ITEMQUAL_INFERIOR:
        case ITEMQUAL_NORMAL:
        case ITEMQUAL_SUPERIOR:
        case ITEMQUAL_MAGIC:
        case ITEMQUAL_RARE:
        case ITEMQUAL_CRAFT:
        case ITEMQUAL_TEMPERED:
        {
            const int nAutoPrefix = pItemsTxtRecord->wAutoPrefix;
            if (nAutoPrefix)
            {
                const unsigned short nAutoAffix = sub_005C1940_RollAutoAffix(*ppItem, 0, 1, 0, 1, 0, nAutoPrefix);
                if (nAutoAffix > 0)
                {
                    ITEMS_SetAutoAffix(*ppItem, nAutoAffix);
                    void* pAffixTxtRecord = DATATBLS_GetMagicAffixTxtRecord(nAutoAffix);
                    ITEMMODS_AssignProperty(0, 0, *ppItem, pAffixTxtRecord, 0, 0);
                }
            }
        }
            break;
        }
    }

    return 1;
}

// 0x00556F60
int __stdcall ITEMS_RollItemQuality(D2UnitStrc* pItem, D2ItemDropStrc* pDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1 && pDrop->nQuality)
        return pDrop->nQuality;
    D2GameStrc* ptGame = SUNIT_GetGameFromUnit(pItem);
    D2_ASSERT(ptGame, 0x482);
    const unsigned short nVersion = ITEMS_GetItemFormat(pItem) >= 1 ? 100 : 0;
    D2ItemRatioTxt* pRatio = DATATBLS_GetItemRatioTxtRecord(!pItem ? -1 : pItem->dwClassId, ptGame->nDifficulty, nVersion);
    D2_ASSERT(pRatio, 0x486);
    D2ItemsTxt* pRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    D2_ASSERT(pRecord, 0x489);
    if (pRecord->nQuest)
        return 2;
    int nItemLevel = pDrop->nItemLvl;
    int nChance = 0;
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        if (ITEMSIsA(pItem, 0x34))
            nItemLevel = 1;
        else
        {
            nItemLevel -= pRecord->nLevel;
            if (nItemLevel < 1)
                nItemLevel = 1;
        }
    }
    int nQuality = 1;
    if (ITEMS_GetItemFormat(pItem) >= 1)
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            switch (gnQualityOrder[i])
            {
            case 7: nChance = pRatio->dwUnique - nItemLevel / pRatio->dwUniqueDivisor; nQuality = 7; break;
            case 6: nChance = pRatio->dwRare - nItemLevel / pRatio->dwRareDivisor; nQuality = 6; break;
            case 5: nChance = pRatio->dwSet - nItemLevel / pRatio->dwSetDivisor; nQuality = 5; break;
            case 4: nChance = pRatio->dwMagic - nItemLevel / pRatio->dwMagicDivisor; nQuality = 4; break;
            case 3: nChance = pRatio->dwHiQuality - nItemLevel / pRatio->dwHiQualityDivisor; nQuality = 3; break;
            case 2: nChance = pRatio->dwNormal - nItemLevel / pRatio->dwNormalDivisor; nQuality = 2; break;
            }
            if (nChance <= 0 || !ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nChance))
                return nQuality;
        }
    }
    else
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            switch (gnQualityOrder[i])
            {
            case 7: nChance = pRatio->dwUnique - nItemLevel; nQuality = 7; break;
            case 6: nChance = pRatio->dwRare - nItemLevel; nQuality = 6; break;
            case 5: nChance = pRatio->dwSet - nItemLevel; nQuality = 5; break;
            case 4: nChance = pRatio->dwMagic - nItemLevel / pRatio->dwMagicDivisor; nQuality = 4; break;
            case 3: nChance = pRatio->dwHiQuality - nItemLevel / pRatio->dwHiQualityDivisor; nQuality = 3; break;
            case 2: nChance = pRatio->dwNormal - nItemLevel / pRatio->dwNormalDivisor; nQuality = 2; break;
            }
            if (nChance <= 0)
                nChance = 1;
            if (!ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nChance))
                return nQuality;
        }
    }
    return (((unsigned char)pDrop->dwFlags2 & 0x40) | 0x20) >> 5;
}

// 0x00557250
static void ITEMS_ClearAffixesAndFileIndex(D2UnitStrc** ppItem)
{
    for (int i = 0; i < 3; i += 1)
    {
        ITEMS_AssignPrefix(*ppItem, 0, i);
        ITEMS_AssignSuffix(*ppItem, 0, i);
    }

    ITEMS_AssignRarePrefix(*ppItem, 0);
    ITEMS_AssignRareSuffix(*ppItem, 0);
    ITEMS_SetFileIndex(*ppItem, -1);
}

// 0x005572A0
static void __stdcall ITEMS_ResetToNormalQuality(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int nLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, nLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), nLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 2);
    pItemDrop->nQuality = 2;
    ITEMS_AssignSpecialPropertiesForFormat(pGame, *ppItem, pItemDrop);
}

// 0x00557320
static int ITEMS_ResetToSuperiorQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 3);
    pItemDrop->nQuality = 3;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return ITEMS_RollSuperiorItem(*ppItem, pItemDrop);
}

// 0x00557380
static int __stdcall ITEMS_ResetToMagicQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 4);
    pItemDrop->nQuality = 4;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return ITEMS_AssignDropMagicAffixes(pItemDrop, ppItem);
}

// 0x005573F0
static int ITEMS_ResetToRareQuality(D2ItemDropStrc* pItemDrop, D2UnitStrc** ppItem, unsigned int* pLowSeed)
{
    ITEMS_ClearAffixesAndFileIndex(ppItem);
    ITEMS_SetItemStartSeed(*ppItem, *pLowSeed);
    SEED_InitLowSeed(ITEMS_GetItemSeed(*ppItem), *pLowSeed);
    ITEMS_RollItemQuality(*ppItem, pItemDrop);
    ITEMS_SetItemQuality(*ppItem, 6);
    pItemDrop->nQuality = 6;
    *pLowSeed = SEED_GetLowSeed(ITEMS_GetItemSeed(*ppItem));
    return D2GAME_RollRareItem_6FC53360(*ppItem, pItemDrop);
}

struct D2CoordStrc;

struct D2MagicAffixTxt;

// 0x00557A70
static void ITEMS_RollVarInvGfx(D2UnitStrc* pItem)
{
    if (ITEMS_GetVarInvGfxCount(pItem))
    {
        const unsigned char nIndex = sub_00472280(&pItem->pSeed, 0, ITEMS_GetVarInvGfxCount(pItem));
        ITEMS_SetVarGfxIndex(pItem, nIndex);
    }
}

static inline unsigned int D2_MinU(unsigned int a, unsigned int b) { return a < b ? a : b; }

static inline void ITEMS_SetGoldStat(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
        {
            STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
            return;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x00557AB0
int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int bQuestItem)
{
    if (ITEMS_GetItemType(*ppItem) == ITEMTYPE_GOLD)
    {
        int nQuantity = 1;
        if (pItemDrop)
        {
            const int nItemLevel = pItemDrop->nItemLvl;
            nQuantity = SEED_RollLimitedRandomNumber(&(*ppItem)->pSeed, 5 * nItemLevel) + nItemLevel;
            if (nQuantity <= 0)
            {
                nQuantity = 1;
            }

            if (pItemDrop->nQtyOverride > 0)
            {
                nQuantity = pItemDrop->nQtyOverride;
            }
        }

        ITEMS_SetGoldStat(*ppItem, 14, nQuantity);
    }
    else if (ITEMS_GetQuiverType(*ppItem))
    {
        const int nMinStack = ITEMS_GetMinStack(*ppItem);
        int nQuantity = nMinStack + ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, ITEMS_GetTotalMaxStack(*ppItem) - nMinStack);
        if (nQuantity < 1)
        {
            nQuantity = 1;
        }

        if (pItemDrop && pItemDrop->nQtyOverride > 0)
        {
            nQuantity = pItemDrop->nQtyOverride;
        }

        STATLIST_SetUnitStat(*ppItem, STAT_QUANTITY, nQuantity, 0);
    }
    else
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!*ppItem ? -1 : (*ppItem)->dwClassId);
        D2_ASSERT(pItemsTxtRecord, 0x686);

        if (ITEMSIsA(*ppItem, 50))
        {
            STATLIST_SetUnitStat(*ppItem, STAT_TOBLOCK, pItemsTxtRecord->nBlock, 0);
            STATLIST_SetUnitStat(*ppItem, STAT_VELOCITYPERCENT, -pItemsTxtRecord->dwSpeed, 0);
            const unsigned int nMaxDurability = pItemsTxtRecord->nDurability;
            const unsigned int nDurability = nMaxDurability >> 1;
            unsigned int nValue = ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nDurability) + nDurability;
            if (nValue >= 255)
            {
                nValue = 255;
            }
            STATLIST_SetUnitStat(*ppItem, STAT_DURABILITY, nValue, 0);
            STATLIST_SetUnitStat(*ppItem, STAT_MAXDURABILITY, nMaxDurability >= 255 ? 255 : nMaxDurability, 0);
            ITEMS_RollArmorClass(*ppItem);
        }
        else if (ITEMSIsA(*ppItem, 45))
        {
            if (ITEMS_CheckIfStackable(*ppItem))
            {
                const int nMinStack = ITEMS_GetMinStack(*ppItem);
                const int nMaxStack = ITEMS_GetTotalMaxStack(*ppItem);
                unsigned int nQuantity = ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nMaxStack - nMinStack) + nMinStack;
                if (pItemDrop && pItemDrop->nQtyOverride > 0)
                {
                    nQuantity = pItemDrop->nQtyOverride;
                }

                if (nQuantity < 1)
                {
                    nQuantity = 1;
                }

                if (ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem))
                {
                    nQuantity = 1;
                }

                STATLIST_SetUnitStat(*ppItem, STAT_QUANTITY, nQuantity, 0);
            }

            const unsigned int nDurability = pItemsTxtRecord->nDurability;
            STATLIST_SetUnitStat(*ppItem, STAT_DURABILITY, D2_MinU(ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nDurability >> 1) + (nDurability >> 1), 255), 0);
            STATLIST_SetUnitStat(*ppItem, STAT_MAXDURABILITY, D2_MinU(nDurability, 255), 0);
            ITEMS_SetWeaponDamage(*ppItem);
            STATLIST_SetUnitStat(*ppItem, STAT_ATTACKRATE, -pItemsTxtRecord->dwSpeed, 0);
        }
        else
        {
            if (ITEMS_CheckIfStackable(*ppItem))
            {
                const int nMinStack = ITEMS_GetMinStack(*ppItem);
                const int nMaxStack = ITEMS_GetTotalMaxStack(*ppItem);
                int nSpawnStack = ITEMS_GetSpawnStack(*ppItem);
                if (nSpawnStack < nMinStack || !nSpawnStack)
                {
                    nSpawnStack = nMinStack > nMaxStack ? nMinStack : nMaxStack;
                }

                unsigned int nQuantity = ITEMS_RollLimitedRandomNumber(&(*ppItem)->pSeed, nSpawnStack - nMinStack) + nMinStack;
                if (pItemDrop && pItemDrop->nQtyOverride > 0)
                {
                    nQuantity = pItemDrop->nQtyOverride;
                }

                if (ITEMS_IsMagSetRarUniCrfOrTmp(*ppItem) || nQuantity < 1)
                {
                    nQuantity = 1;
                }

                STATLIST_SetUnitStat(*ppItem, STAT_QUANTITY, nQuantity, 0);
            }

            if (ITEMS_GetItemType(*ppItem) == ITEMTYPE_ELIXIR)
            {
                ITEMMODS_SetRandomElixirFileIndex(*ppItem);
            }
        }
    }

    ITEMS_RollVarInvGfx(*ppItem);

    int nResult = 1;
    if (bQuestItem && pItemDrop)
    {
        nResult = ITEMMODE_AssignItemQualityAndProperties(pGame, ppItem, pItemDrop);

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!*ppItem ? -1 : (*ppItem)->dwClassId);
        if (pItemsTxtRecord && pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(*ppItem, 0, 0x40);
            if (!pStatList)
            {
                pStatList = STATLIST_AllocStatList(!*ppItem ? 0 : (*ppItem)->pMemoryPool, 0x40, 0, 4, !*ppItem ? -1 : (*ppItem)->dwUnitId);
                D2COMMON_10475_PostStatToStatList(*ppItem, pStatList, 1);
            }

            STATLIST_SetStatIfListIsValid(pStatList, STAT_QUESTITEMDIFFICULTY, pGame->nDifficulty, 0);
            ITEMS_SetItemFlag(*ppItem, 0x10, 1);
        }
    }

    return nResult;
}

// 0x00557EE0
void __fastcall ITEMS_FreeSocketInventoryAndTimers(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (ITEMS_CheckIfSocketable(pItem))
    {
        SUNIT_RemoveAllItemsFromInventory(pGame, pItem);
        INVENTORY_FreeInventory(pItem->pInventory);
    }

    EVENT_FreeUnitTimers(pGame, pItem);
}

// 0x00557F10
void __fastcall ITEMS_RemoveAll(D2GameStrc* pGame)
{
    D2UnitStrc** ppUnit = pGame->pUnitList[3];
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pUnit = *ppUnit;
        while (pUnit)
        {
            if (pUnit->dwItemMode != IMODE_SOCKETED)
            {
                SUNIT_RemoveUnit(pGame, pUnit);
                pUnit = *ppUnit;
            }
            else
            {
                pUnit = SUNIT_GetNextUnitFromList(pUnit);
            }
        }
        ++ppUnit;
    }
}

// 0x00557F50
static void ITEMS_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem)
{
    for (D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory); i; i = INVENTORY_GetNextItem(i))
    {
        if (INVENTORY_UnitIsItem(i) == pItem)
        {
            INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            return;
        }
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem && pCursorItem == pItem)
    {
        INVENTORY_SetCursorItem(pInventory, 0);
    }
}

// 0x00557FA0
void __fastcall ITEMS_PlayerIterateCallback_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    ITEMS_RemoveItemFromInventory(pUnit->pInventory, (D2UnitStrc*)pArg);
}

// 0x00557FC0
static inline void ITEMS_RemoveItemFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
}

void __fastcall sub_M110_Emit_00557FC0(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (pItem)
        ITEMS_RemoveItemFromAllPlayers(pGame, pItem);
}

// 0x00557FD0
void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pUnit);
    SUNIT_RemoveUnit(pGame, pUnit);
}

// 0x00557FF0
int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2InventoryStrc* pOtherInventory)
{
    D2InventoryStrc* hInventory = pUnit->pInventory;
    D2_ASSERT(hInventory, 2740);

    if (pOtherInventory)
    {
        hInventory = pOtherInventory;
    }

    if (pItem == INVENTORY_GetCursorItem(hInventory))
    {
        return 1;
    }

    for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(hInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
    {
        if (pItem == INVENTORY_UnitIsItem(pNode))
        {
            return 1;
        }
    }

    return 0;
}

static inline int ITEMS_IsUniqueWithFileIndex(D2UnitStrc* pItem, int nFileIndex)
{
    return pItem && pItem->dwUnitType == UNIT_ITEM && ITEMS_GetItemQuality(pItem) == ITEMQUAL_UNIQUE && ITEMS_GetFileIndex(pItem) == nFileIndex;
}

// 0x00558070
D2UnitStrc* __fastcall ITEMS_FindUniqueItem(D2UnitStrc* pUnit, int nFileIndex)
{
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (ITEMS_IsUniqueWithFileIndex(pCursorItem, nFileIndex))
    {
        return pCursorItem;
    }

    for (D2UnitStrc* pIt = INVENTORY_GetFirstItem(pInventory); pIt; pIt = INVENTORY_GetNextItem(pIt))
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pIt);
        if (ITEMS_IsUniqueWithFileIndex(pItem, nFileIndex) && ITEMS_GetInvPage(pItem) != 1)
        {
            return pItem;
        }
    }

    return 0;
}

// 0x00558110
D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem && dwItemCode == ITEMS_GetBaseCode(pCursorItem))
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pCursorItem->dwClassId);
        if (!pItemsTxtRecord || !pItemsTxtRecord->nQuest || pGame->nDifficulty <= STATLIST_UnitGetStatValue(pCursorItem, STAT_QUESTITEMDIFFICULTY, 0))
        {
            return pCursorItem;
        }
    }

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckItem = INVENTORY_UnitIsItem(pItem);
        if (dwItemCode == ITEMS_GetBaseCode(pCheckItem) && ITEMS_GetInvPage(pCheckItem) != INVPAGE_EQUIP)
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pCheckItem ? -1 : pCheckItem->dwClassId);
            if (!pItemsTxtRecord || !pItemsTxtRecord->nQuest || !pItemsTxtRecord->nQuestDiffCheck || pGame->nDifficulty <= STATLIST_UnitGetStatValue(pCheckItem, STAT_QUESTITEMDIFFICULTY, 0))
            {
                return pCheckItem;
            }
        }
    }

    return 0;
}

// 0x00558200
int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
            return nLevel > 1 ? nLevel : 1;
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const int nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
            return nLevel > 1 ? nLevel : 1;
        }

        nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    }
    else if (!nLevelId)
    {
        return 1;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    const int nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    return nLevel > 1 ? nLevel : 1;
}

inline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
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

// 0x00558270
void __fastcall ITEMS_FillItemDrop(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    memset(pItemDrop, 0, sizeof(D2ItemDropStrc));

    pItemDrop->pGame = pGame;
    pItemDrop->wItemFormat = ITEMS_GetItemFormat(pItem);
    pItemDrop->nItemLvl = ITEMS_GetItemLevel(pItem);
    if (pItemDrop->nItemLvl <= 0)
    {
        pItemDrop->nItemLvl = 1;
    }

    pItemDrop->nId = !pItem ? -1 : pItem->dwClassId;
    pItemDrop->nSpawnType = !pItem ? 0 : pItem->dwAnimMode;
    pItemDrop->nQuality = ITEMS_GetItemQuality(pItem);
    pItemDrop->nX = CLIENTS_GetUnitX(pItem);
    pItemDrop->nY = CLIENTS_GetUnitY(pItem);

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        pItemDrop->nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
    }
    else if (ITEMS_CheckIfStackable(pItem))
    {
        const int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);

        D2_ASSERT(nQuantity >= 0, 3241);

        pItemDrop->nQuantity = nQuantity;
    }

    pItemDrop->pSeed = &pItem->pSeed;
    pItemDrop->wUnitInitFlags = 1;
    pItemDrop->dwSeed = pItem->dwInitSeed;
    pItemDrop->dwItemSeed = ITEMS_GetItemStartSeed(pItem);
    pItemDrop->nItemIndex = ITEMS_GetFileIndex(pItem);
    pItemDrop->dwFlags1 = ITEMS_GetItemFlags(pItem);
    pItemDrop->nMinDur = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0);
    pItemDrop->nMaxDur = STATLIST_GetUnitBaseStat(pItem, STAT_MAXDURABILITY, 0);
    pItemDrop->nItemIndex = ITEMS_GetFileIndex(pItem);
    pItemDrop->bForce = 0;

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_PLAYER_BODY_PART)
    {
        strcpy(pItemDrop->szName, ITEMS_GetEarName(pItem));
        *(unsigned char*)&pItemDrop->eEarLvl = ITEMS_GetEarLevel(pItem);
    }
    else if (ITEMS_CheckItemFlag(pItem, IFLAG_PERSONALIZED, 3265, ".\\ITEMS\\Items.cpp"))
    {
        strcpy(pItemDrop->szName, ITEMS_GetEarName(pItem));
    }
}

// 0x00558450
int __fastcall ITEMS_GetHealthPotionDropCode(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(hRoom, 0xD5E);

    unsigned char nIndex = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(hRoom));
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (pGame && pGame->nDifficulty > DIFFMODE_NORMAL)
    {
        nIndex += 2;
    }

    if (nIndex >= gnDropHealthPotionCodeCount)
    {
        return gdwDropHealthPotionCodes[3];
    }

    return gdwDropHealthPotionCodes[nIndex];
}

// 0x005584C0
int __fastcall ITEMS_GetManaPotionDropCode(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* hRoom = UNITS_GetRoom(pUnit);
    D2_ASSERT(hRoom, 0xD7D);

    unsigned char nIndex = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(hRoom));
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (pGame && pGame->nDifficulty > DIFFMODE_NORMAL)
    {
        nIndex += 2;
    }

    if (nIndex >= gnDropManaPotionCodeCount)
    {
        return gdwDropManaPotionCodes[3];
    }

    return gdwDropManaPotionCodes[nIndex];
}

// 0x00558530
void __fastcall ITEMS_ScheduleDurabilityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nReplenishDurability = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_REPLENISH_DURABILITY, 0);
    if (nReplenishDurability && !EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_STATREGEN))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, 2500 / nReplenishDurability + pGame->dwGameFrame + 1, 0, 0);
    }
}

// 0x00558580
void __fastcall ITEMS_ScheduleQuantityReplenishment(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nReplenishQuantity = STATLIST_UnitGetStatValue(pUnit, STAT_ITEM_REPLENISH_QUANTITY, 0);
    if (nReplenishQuantity && !EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_STATREGEN))
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_STATREGEN, 2500 / nReplenishQuantity + pGame->dwGameFrame + 1, 0, 0);
    }
}

// 0x005585D0
static int ITEMS_GetMagicFindBonus(D2UnitStrc* pPlayer)
{
    if (pPlayer && (unsigned int)pPlayer->dwUnitType <= UNIT_MONSTER)
    {
        int nMagicBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, STAT_ITEM_MAGICBONUS, 0);
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pPlayer);
        if (pOwner)
        {
            nMagicBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_MAGICBONUS, 0);
        }
        return nMagicBonus;
    }
    return 0;
}

// 0x00558610
int __fastcall ITEMS_GetDiminishedMagicFind(int nMagicFind, int nFactor, int nFactor2)
{
    if (nMagicFind <= 110) return nMagicFind;
    nMagicFind -= 100;
    nFactor2 *= nMagicFind;
    nMagicFind += nFactor;
    return nFactor2 / nMagicFind + 100;
}

static inline D2ItemTypesTxt* sub_C03_GetItemTypesTxtRecord(int nItemType)
{
    if (nItemType >= 0 && nItemType < sgptDataTables->nItemTypesTxtRecordCount)
    {
        return &sgptDataTables->pItemTypesTxt[nItemType];
    }

    return 0;
}

// 0x00558640
static int __stdcall ITEMS_RollDropQuality(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer, D2QualityModsStrc* pMods, int nItemLevel, int nItemId)
{
    int bMagicFind = 0;
    int nChance;

    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    D2ItemTypesTxt* pItemTypesTxtRecord = sub_C03_GetItemTypesTxtRecord(ITEMS_GetItemTypeFromItemId(nItemId));
    if (!pItemTypesTxtRecord)
    {
        return 0;
    }

    if (pItemTypesTxtRecord->nNormal)
    {
        return 2;
    }

    if (pItemsTxtRecord->nUnique)
    {
        return 7;
    }

    if (pItemTypesTxtRecord->nMagic && pItemsTxtRecord->nQuest)
    {
        return 7;
    }

    D2ItemRatioTxt* pItemRatioTxtRecord = DATATBLS_GetItemRatioTxtRecord(nItemId, pGame->nDifficulty, 100);
    D2_ASSERT(pItemRatioTxtRecord, 0xE8D);

    const int nLevel = nItemLevel - pItemsTxtRecord->nLevel;
    int nMagicFind = ITEMS_GetMagicFindBonus(pPlayer);
    if (nMagicFind)
    {
        if (nMagicFind <= -100)
        {
            goto Superior;
        }

        bMagicFind = 1;
    }

    nMagicFind += 100;

    nChance = (pItemRatioTxtRecord->dwUnique - nLevel / pItemRatioTxtRecord->dwUniqueDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = ITEMS_GetDiminishedMagicFind(nMagicFind, 250, 250);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwUniqueMin)
    {
        nChance = pItemRatioTxtRecord->dwUniqueMin;
    }

    nChance -= nChance * pMods->wUnique / 1024;
    if (nChance <= 0)
    {
        return 7;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 7;
    }

    nChance = (pItemRatioTxtRecord->dwSet - nLevel / pItemRatioTxtRecord->dwSetDivisor) * 128;
    if (bMagicFind)
    {
        const int nDiminished = ITEMS_GetDiminishedMagicFind(nMagicFind, 500, 500);
        if (nDiminished)
        {
            nChance = nChance * 100 / nDiminished;
        }
    }

    if (nChance <= pItemRatioTxtRecord->dwSetMin)
    {
        nChance = pItemRatioTxtRecord->dwSetMin;
    }

    nChance -= nChance * pMods->wSet / 1024;
    if (nChance <= 0)
    {
        return 5;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 5;
    }

    if (pItemTypesTxtRecord->nRare)
    {
        nChance = (pItemRatioTxtRecord->dwRare - nLevel / pItemRatioTxtRecord->dwRareDivisor) * 128;
        if (bMagicFind)
        {
            const int nDiminished = ITEMS_GetDiminishedMagicFind(nMagicFind, 600, 600);
            if (nDiminished)
            {
                nChance = nChance * 100 / nDiminished;
            }
        }

        if (nChance <= pItemRatioTxtRecord->dwRareMin)
        {
            nChance = pItemRatioTxtRecord->dwRareMin;
        }

        nChance -= nChance * pMods->wRare / 1024;
        if (nChance <= 0)
        {
            return 6;
        }

        if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
        {
            return 6;
        }
    }

    if (pItemTypesTxtRecord->nMagic)
    {
        return 4;
    }

    nChance = (pItemRatioTxtRecord->dwMagic - nLevel / pItemRatioTxtRecord->dwMagicDivisor) * 128;
    if (bMagicFind)
    {
        nChance = nChance * 100 / nMagicFind;
    }

    if (nChance <= pItemRatioTxtRecord->dwMagicMin)
    {
        nChance = pItemRatioTxtRecord->dwMagicMin;
    }

    nChance -= nChance * pMods->f_0 / 1024;
    if (nChance <= 0)
    {
        return 4;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 4;
    }

Superior:
    nChance = (pItemRatioTxtRecord->dwHiQuality - nLevel / pItemRatioTxtRecord->dwHiQualityDivisor) * 128;
    if (nChance <= 0)
    {
        return 3;
    }

    if (ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128)
    {
        return 3;
    }

    nChance = (pItemRatioTxtRecord->dwNormal - nLevel / pItemRatioTxtRecord->dwNormalDivisor) * 128;
    if (nChance <= 0)
    {
        return 2;
    }

    return ITEMS_RollLimitedRandomNumber(&pItem->pSeed, nChance) < 128 ? 2 : 1;
}

// 0x00558990
void __cdecl sub_00558990_Nop()
{
}

// 0x005589A0
static void ITEMS_ApplyGoldFind(D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    if (pPlayer && pItem && ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
    {
        int nGoldBonus = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, STAT_ITEM_GOLDBONUS, 0) + 100;
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pPlayer);
        if (pOwner)
        {
            nGoldBonus += STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_GOLDBONUS, 0);
        }

        const int nGold = STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0);
        D2GAME_SetStatOrResetGold_6FC7CA70(pItem, 0xE, nGold * nGoldBonus / 100);
    }
}

void __fastcall D2GAME_DropTC_6FC51360(D2GameStrc* pGame, D2UnitStrc* pMonster, D2UnitStrc* pPlayer, D2TCExShortStrc* pTCTxtRecord, int nQuality, int nLvl, int bIgnoreNoDrop, D2UnitStrc** ppItems, int* pnItemsDropped, int nMaxItems)
{
    const int bExpansion = pGame->bExpansion;
    int nThrowableCounter = 0;

    D2_ASSERT(pTCTxtRecord, 0xF3A);

    int nItemsDropped;
    if (!pnItemsDropped)
    {
        pnItemsDropped = &nItemsDropped;
    }
    *pnItemsDropped = 0;

    if (!ppItems)
    {
        if (nMaxItems <= 0)
        {
            nMaxItems = 6;
        }
    }
    else
    {
        D2_ASSERT(nMaxItems, 0xF44);
    }

    D2TCArrayStrc tcArray[64];
    tcArray[0].pTC = pTCTxtRecord;
    tcArray[0].nPicks = D2_ABS(pTCTxtRecord->nPicks);
    tcArray[0].nPicks = D2_MAX(tcArray[0].nPicks, 1);
    tcArray[0].tMods = pTCTxtRecord->tMods;

    int nCounter = 1;
    while (nCounter)
    {
        --nCounter;

        if (!tcArray[nCounter].pTC)
        {
            continue;
        }

        if (!(bExpansion ? tcArray[nCounter].pTC->nProb : tcArray[nCounter].pTC->nClassic))
        {
            continue;
        }

        while (tcArray[nCounter].nPicks)
        {
            D2TCExShortStrc* pTC = tcArray[nCounter].pTC;
            const int nChance = bExpansion ? pTC->nProb : pTC->nClassic;
            if (!nChance)
            {
                break;
            }

            int nRand;
            if (pTC->nPicks >= 0)
            {
                nRand = nChance;
                int nNoDrop = pTC->nNoDrop;
                if (nNoDrop)
                {
                    int nPlayerCount = 1;
                    if (pPlayer)
                    {
                        D2UnitStrc* pOwner = pPlayer;
                        if (pPlayer->dwUnitType != UNIT_PLAYER)
                        {
                            pOwner = AIGENERAL_GetMinionOwner(pPlayer);
                        }

                        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
                        {
                            const int nLiving = PARTY_GetLivingPartyMemberCountInSameLevel(pGame, pOwner);
                            nPlayerCount = D2_MIN(D2_MAX(nLiving, 1), 8);
                        }
                    }

                    nPlayerCount += (PLAYER_GetPlayerCount(pGame) - nPlayerCount) / 2;
                    if (pMonster && GAME_GetUnitTypeOrInvalid(pMonster) == 1)
                    {
                        int nMonsterPlayers = STATLIST_UnitGetStatValue(pMonster, STAT_MONSTER_PLAYERCOUNT, 0);
                        nMonsterPlayers = D2_MAX(1, nMonsterPlayers);
                        nPlayerCount = D2_MIN(nPlayerCount, nMonsterPlayers);
                    }

                    if (nPlayerCount > 1)
                    {
                        const double dBaseRatio = (double)nNoDrop / (double)(nNoDrop + nChance);
                        double dNoDropRatio = dBaseRatio;
                        for (int i = 1; i < nPlayerCount; ++i)
                        {
                            dNoDropRatio *= dBaseRatio;
                        }

                        const double dInverseRatio = 1.0 - dNoDropRatio;
                        if (dInverseRatio != 0.0)
                        {
                            nNoDrop = (int)((1.0 - dInverseRatio) * nChance / dInverseRatio);
                        }
                        else
                        {
                            nNoDrop = 0;
                        }
                    }
                }

                if (!bIgnoreNoDrop)
                {
                    nRand = nNoDrop + nChance;
                }

                if (nRand <= 0)
                {
                    nRand = 0;
                }
                else if ((nRand - 1) & nRand)
                {
                    unsigned int nRoll;
                    D2_SEED_ROLL(pMonster, nRoll);
                    nRand = nRoll % nRand;
                }
                else
                {
                    unsigned int nRoll;
                    D2_SEED_ROLL(pMonster, nRoll);
                    nRand = nRoll & (nRand - 1);
                }

                if (!bIgnoreNoDrop)
                {
                    if (nRand < nNoDrop)
                    {
                        --tcArray[nCounter].nPicks;
                        continue;
                    }

                    nRand -= nNoDrop;
                }
            }
            else
            {
                nRand = D2_ABS(pTC->nPicks) - tcArray[nCounter].nPicks;
                if (nRand >= nChance)
                {
                    break;
                }
            }

            --tcArray[nCounter].nPicks;

            int nIndex;
            if (bExpansion)
            {
                int nLowerBound = 0;
                int nUpperBound = pTC->nTypes;
                while (nLowerBound < nUpperBound)
                {
                    nIndex = nLowerBound + (nUpperBound - nLowerBound) / 2;
                    if (nRand > pTC->pInfo[nIndex].nProb)
                    {
                        nLowerBound = nIndex + 1;
                    }
                    else if (nRand < pTC->pInfo[nIndex].nProb)
                    {
                        nUpperBound = nIndex;
                    }
                    else
                    {
                        break;
                    }
                }

                if (nLowerBound >= nUpperBound)
                {
                    nIndex = D2_MAX(0, nLowerBound - 1);
                }
            }
            else
            {
                nIndex = 0;
                while (nIndex < pTC->nTypes)
                {
                    if (!(pTC->pInfo[nIndex].nFlags & 0x10) && (nIndex >= pTC->nTypes - 1 || pTC->pInfo[nIndex + 1].nClassic > nRand))
                    {
                        break;
                    }

                    ++nIndex;
                }
            }

            if (nIndex >= pTC->nTypes)
            {
                continue;
            }

            if (pTC->pInfo[nIndex].nFlags & 4)
            {
                D2TCExShortStrc* pSubTC = DATATBLS_GetTreasureClassExRecordFromIdAndLevel(pTC->pInfo[nIndex].nItemId, 0);
                const int nOldCounter = nCounter;
                if (tcArray[nCounter].nPicks > 0)
                {
                    ++nCounter;
                }

                D2_ASSERT(nCounter < 0x40, 0xFEA);

                tcArray[nCounter].pTC = pSubTC;
                tcArray[nCounter].nPicks = D2_ABS(pSubTC->nPicks);
                tcArray[nCounter].nPicks = D2_MAX(tcArray[nCounter].nPicks, 1);

                for (int i = 0; i < 6; ++i)
                {
                    if (!tcArray[nOldCounter].tMods.nMods[i])
                    {
                        tcArray[nCounter].tMods.nMods[i] = pSubTC->tMods.nMods[i];
                    }
                    else if (pSubTC->tMods.nMods[i] > tcArray[nOldCounter].tMods.nMods[i])
                    {
                        tcArray[nCounter].tMods.nMods[i] = pSubTC->tMods.nMods[i];
                    }
                    else
                    {
                        tcArray[nCounter].tMods.nMods[i] = tcArray[nOldCounter].tMods.nMods[i];
                    }
                }
                continue;
            }

            unsigned short nItemId = pTC->pInfo[nIndex].nItemId;
            if (nItemId == 0xFFFF)
            {
                continue;
            }

            if (!bExpansion)
            {
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
                if (!pItemsTxtRecord || pItemsTxtRecord->wVersion >= 100)
                {
                    continue;
                }

                for (int i = 0; i < 6; ++i)
                {
                    if (pTC->pInfo[nIndex].tMods.nMods[i] > tcArray[nCounter].tMods.nMods[i])
                    {
                        tcArray[nCounter].tMods.nMods[i] = pTC->pInfo[nIndex].tMods.nMods[i];
                    }
                }
            }

            int nItemQuality;
            int nItemIndex = 0;
            if (pTC->pInfo[nIndex].nFlags & 1)
            {
                nItemQuality = 7;
                nItemIndex = pTC->pInfo[nIndex].nTxtRow + 1;
            }
            else if (pTC->pInfo[nIndex].nFlags & 2)
            {
                nItemQuality = 5;
                nItemIndex = pTC->pInfo[nIndex].nTxtRow + 1;
            }
            else
            {
                nItemQuality = nQuality;
                if (!nItemQuality)
                {
                    nItemQuality = ITEMS_RollDropQuality(pGame, pMonster, pPlayer, (D2QualityModsStrc*)&tcArray[nCounter].tMods, nLvl, nItemId);
                }
            }

            int nFlags = 0;
            if (tcArray[nCounter].tMods.nMods[4] > 0)
            {
                unsigned int nRoll;
                D2_SEED_ROLL(pMonster, nRoll);
                if ((nRoll & 0x3FF) < tcArray[nCounter].tMods.nMods[4])
                {
                    nFlags = 4;
                }
            }

            const unsigned short wNormal = tcArray[nCounter].tMods.nMods[5];
            if (wNormal > 0)
            {
                unsigned int nRoll;
                D2_SEED_ROLL(pMonster, nRoll);
                if ((nRoll & 0x3FF) < wNormal)
                {
                    nFlags |= 0x10;
                }
            }

            if (!pGame->bExpansion && ITEMS_CheckItemTypeIfThrowable(ITEMS_GetItemTypeFromItemId(nItemId)))
            {
                if (nThrowableCounter++ < 0xA)
                {
                    ++tcArray[nCounter].nPicks;
                    continue;
                }

                nItemId = DATATBLS_GetItemIdFromItemCode(0x2064736C);
            }

            D2UnitStrc* pItem = ITEMS_CreateDropAtUnit(pGame, nItemQuality, nItemIndex, nFlags, nItemId, pMonster);
            if (!pItem)
            {
                continue;
            }

            if (ITEMSIsA(pItem, 4) && pTC->pInfo[nIndex].nTxtRow)
            {
                D2GAME_SetStatOrResetGold_6FC7CA70(pItem, 0xE, STATLIST_UnitGetStatValue(pItem, STAT_GOLD, 0) * pTC->pInfo[nIndex].nTxtRow >> 8);
            }

            if (ppItems)
            {
                ppItems[*pnItemsDropped] = pItem;
            }

            ++*pnItemsDropped;
            if (*pnItemsDropped >= nMaxItems)
            {
                return;
            }

            ITEMS_ApplyGoldFind(pPlayer, pItem);
        }
    }
}

// 0x00559130
D2UnitStrc* __fastcall ITEMS_DropRandomItemNearCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDropOut)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    if (nItemLevel >= 65)
    {
        nItemLevel = 64;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    const int nItemId = ITEMS_SelectRandomDropItemId(pGame, pSeed, nItemLevel, -1, 0, 0);

    D2CoordStrc coords1;
    D2CoordStrc coords2 = *pCoords;

    const int nX = coords2.nX + 2;
    const int nY = coords2.nY + 3;
    if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
    {
        coords1.nX = nX;
        coords1.nY = nY;
    }
    else
    {
        coords1.nX = coords2.nX;
        coords1.nY = coords2.nY;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, COLLIDE_MASK_SPAWN, 0x801, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop;
        memset(&itemDrop, 0, sizeof(itemDrop));

        itemDrop.pUnit = 0;
        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.pGame = pGame;
        itemDrop.nId = nItemId;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        if (pItemDropOut)
        {
            *pItemDropOut = itemDrop;
        }
        return pItem;
    }

    return 0;
}

// 0x00559300
D2UnitStrc* __fastcall ITEMS_DropGoldAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    if (!gnGoldItemId)
    {
        DATATBLS_GetItemRecordFromItemCode(' dlg', &gnGoldItemId);
    }

    D2CoordStrc coords1;
    D2CoordStrc coords2;
    coords2.nX = pCoords->nX;
    coords2.nY = pCoords->nY;

    const int nX = coords2.nX + 2;
    const int nY = coords2.nY + 3;
    if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
    {
        coords1.nX = nX;
        coords1.nY = nY;
    }
    else
    {
        coords1.nX = coords2.nX;
        coords1.nY = coords2.nY;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, COLLIDE_MASK_SPAWN, 0x801, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop;
        memset(&itemDrop, 0, sizeof(itemDrop));

        itemDrop.pUnit = 0;
        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.pGame = pGame;
        itemDrop.nId = gnGoldItemId;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        if (pItem)
        {
            ITEMS_SetItemFlag(pItem, IFLAG_INSTORE, 0);
        }

        return pItem;
    }

    return 0;
}

// 0x005594C0
D2UnitStrc* __fastcall D2GAME_DropArmor_6FC4F830(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    const int nItemId = ITEMMODE_SelectRandomArmorItemId(pGame, pSeed, nItemLevel, a4, a5);
    D2CoordStrc coords1;
    D2CoordStrc coords2;
    if (nItemId >= 0)
    {
        coords2.nX = pCoords->nX;
        coords2.nY = pCoords->nY;

        D2ActiveRoomStrc* pTargetRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(pRoom, &coords2, &coords1, 1, 1);
        if (!pTargetRoom)
        {
            return 0;
        }

        D2ItemDropStrc itemDrop;
        memset(&itemDrop, 0, sizeof(itemDrop));

        itemDrop.pUnit = pUnit;
        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.dwFlags2 |= ITEMDROPFLAG_SUPERIOR;
        itemDrop.pGame = pGame;
        itemDrop.nId = nItemId;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
    }

    return 0;
}

// 0x00559630
D2UnitStrc* __fastcall D2GAME_DropWeapon_6FC4FA50(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    int nItemId = -1;
    for (int i = 0; i < 6; ++i)
    {
        nItemId = ITEMMODE_SelectRandomWeaponItemId(pGame, pSeed, nItemLevel, a4, a5);
        if (nItemId >= 0 && ITEMS_IsMetalItem(nItemId))
        {
            break;
        }
    }

    D2CoordStrc coords1;
    D2CoordStrc coords2;
    if (nItemId >= 0)
    {
        coords2.nX = pCoords->nX;
        coords2.nY = pCoords->nY;

        const int nX = coords2.nX + 2;
        const int nY = coords2.nY + 3;
        if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
        {
            coords1.nX = nX;
            coords1.nY = nY;
        }
        else
        {
            coords1.nX = coords2.nX;
            coords1.nY = coords2.nY;
        }

        D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, COLLIDE_MASK_SPAWN, 0x801, 1);
        if (pTargetRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));

            itemDrop.pUnit = pUnit;
            itemDrop.pSeed = pSeed;
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.dwFlags2 |= ITEMDROPFLAG_SUPERIOR;
            itemDrop.pGame = pGame;
            itemDrop.nId = nItemId;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.nX = coords1.nX;
            itemDrop.nY = coords1.nY;
            itemDrop.pRoom = pTargetRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 0;
            itemDrop.nItemLvl = nItemLevel;

            return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        }
    }

    return 0;
}

static int ITEMS_GetItemsTxtRecordCount()
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (!pItemDataTbl)
    {
        return 0;
    }

    return pItemDataTbl->nItemsTxtRecordCount;
}

// 0x00558CB0
D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion)
{
    if (!pGame)
    {
        return 0;
    }

    if (pItemSave->nClassId < 0 || pItemSave->nClassId >= ITEMS_GetItemsTxtRecordCount())
    {
        *pSize = 0;
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_AllocUnitData(4, pItemSave->nClassId, pItemSave->nX, pItemSave->nY, pGame, pRoom, 1, pItemSave->bMode, 0);
    if (!pItem)
    {
        return 0;
    }

    int bFail;
    *pSize = ITEMS_DecodeItemFromBitstream(pItem, pBitstream, nBufferSize, bCheckForHeader, 0, dwVersion, &bFail);
    if (!*pSize || bFail)
    {
        SUNIT_RemoveUnit(pGame, pItem);
        return 0;
    }

    ITEMS_SetItemFlag(pItem, 0x80000, 1);
    ITEMS_SetItemFlag(pItem, 0x2000, 0);
    ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
    ITEMS_ScheduleQuantityReplenishment(pGame, pItem);
    return pItem;
}

// 0x00558D90
D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed)
{
    if (!pGame->bExpansion)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItemDrop->nId);
        if (!pItemsTxtRecord)
        {
            return 0;
        }

        if (pItemsTxtRecord->wVersion >= 100)
        {
            return 0;
        }
    }

    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    D2_ASSERT(pItemDataTbl, 0x7F0);

    const int nItemId = pItemDrop->nId;
    if (nItemId < 0 || nItemId >= pItemDataTbl->nItemsTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pItem = SUNIT_AllocUnitData(4, nItemId, pItemDrop->nX, pItemDrop->nY, pItemDrop->pGame, pItemDrop->pRoom, pItemDrop->wUnitInitFlags, pItemDrop->nSpawnType, 0);
    D2UnitStrc* pInitItem = pItem;
    D2_ASSERT(pItem, 0x809);

    ITEMS_SetItemFlag(pItem, 0x80000, 1);
    ITEMS_SetItemFormat(pItem, pItemDrop->wItemFormat);

    if (bUseSeed || pItemDrop->bForce)
    {
        pItem->dwInitSeed = pItemDrop->dwSeed;
        SEED_InitLowSeed(&pItem->pSeed, pItemDrop->dwSeed);
        ITEMS_SetItemStartSeed(pItem, pItemDrop->dwItemSeed);
        SEED_InitLowSeed(ITEMS_GetItemSeed(pItem), pItemDrop->dwItemSeed);
    }

    if (pItemDrop->nItemLvl <= 0)
    {
        pItemDrop->nItemLvl = 1;
    }
    ITEMS_SetItemLevel(pItem, pItemDrop->nItemLvl);

    if (!pItemDrop->bForce)
    {
        ITEMS_SetItemFlag(pItem, 0x2000, 1);
    }

    ITEMS_SetInvPage(pItem, 0xFF);

    if (!D2GAME_InitItemStats_6FC4E520(pGame, &pInitItem, pItemDrop, 1))
    {
        SUNIT_RemoveUnit(pGame, pItem);
        return 0;
    }

    if (pItemDrop->bForce)
    {
        ITEMS_SetItemFlag(pItem, 0x10, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x10));
        ITEMS_SetItemFlag(pItem, 0x1000, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x1000));

        if (!ITEMS_GetItemFormat(pItem) && !ITEMSIsA(pItem, 3) && sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x800) && !sub_006287A0_TestFlags(ITEMS_GetItemFlags(pItem), 0x800))
        {
            if (ITEMS_GetMaxSockets(pItem))
            {
                ITEMS_AddSockets(pItem, ITEMS_GetItemStartSeed(pItem) % ITEMS_GetMaxSockets(pItem) + 1);
            }
            else
            {
                ITEMS_SetItemFlag(pItem, 0x800, 0);
            }
        }

        ITEMS_SetItemFlag(pItem, 0x800, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x800));
        ITEMS_SetItemFlag(pItem, 0x100, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x100));
        ITEMS_SetItemFlag(pItem, 0x20000, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x20000));

        if (ITEMS_GetItemType(pItem) == ITEMTYPE_GOLD)
        {
            D2GAME_SetStatOrResetGold_6FC7CA70(pItem, 14, pItemDrop->nQuantity);
        }
        else
        {
            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, pItemDrop->nQuantity, 0);
        }

        pItemDrop->nMaxDur = D2_MIN((unsigned int)pItemDrop->nMaxDur, 0xFFu);
        pItemDrop->nMinDur = D2_MIN((unsigned int)pItemDrop->nMinDur, (unsigned int)pItemDrop->nMaxDur);
        STATLIST_SetUnitStat(pItem, STAT_DURABILITY, pItemDrop->nMinDur, 0);
        STATLIST_SetUnitStat(pItem, STAT_MAXDURABILITY, pItemDrop->nMaxDur, 0);
    }

    if (ITEMS_GetItemType(pItem) == ITEMTYPE_PLAYER_BODY_PART)
    {
        if (pItemDrop->bForce)
        {
            ITEMS_SetEarName(pItem, pItemDrop->szName);
            ITEMS_SetEarLevel(pItem, *(unsigned char*)&pItemDrop->eEarLvl);
            ITEMS_SetItemFlag(pItem, 0x8000, sub_006287A0_TestFlags(pItemDrop->dwFlags1, 0x8000));
        }
        else
        {
            if (!pItemDrop->pUnit || pItemDrop->pUnit->dwUnitType != UNIT_PLAYER)
            {
                SUNIT_RemoveUnit(pGame, pItem);
                return 0;
            }

            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pItemDrop->pUnit);
            if (!pPlayerData)
            {
                SUNIT_RemoveUnit(pGame, pItem);
                return 0;
            }

            ITEMS_SetEarName(pItem, pPlayerData->szName);
            ITEMS_SetEarLevel(pItem, STATLIST_UnitGetStatValue(pItemDrop->pUnit, STAT_LEVEL, 0));

            D2ClientStrc* pClient = UnitGetClient(pItemDrop->pUnit, ".\\ITEMS\\Items.cpp", 0x880);
            if (pClient)
            {
                ITEMS_SetItemFlag(pItem, 0x8000, CLIENTS_CheckFlag(pClient, 4));
            }
        }
    }

    if (sub_006287A0_TestFlags(ITEMS_GetItemFlags(pItem), 0x1000000))
    {
        if (pItemDrop->bForce)
        {
            ITEMS_SetEarName(pItem, pItemDrop->szName);
        }
        else
        {
            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pItemDrop->pUnit);
            D2_ASSERT(pPlayerData, 0x892);
            ITEMS_SetEarName(pItem, pPlayerData->szName);
        }
    }

    ITEMS_ScheduleDurabilityReplenishment(pGame, pItem);
    ITEMS_ScheduleQuantityReplenishment(pGame, pItem);

    return pItem;
}

// 0x00559830
D2UnitStrc* __fastcall ITEMS_DropMiscItemAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel;
    if (nLevelId && !DUNGEON_IsRoomInTown(pRoom))
    {
        nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
        if (nItemLevel > 1)
        {
            nItemLevel -= 1;
        }
    }
    else
    {
        nItemLevel = 1;
    }

    D2SeedStrc* pSeed = pRoom ? &pRoom->pSeed : 0;

    int bIsMonster = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        bIsMonster = 1;
    }

    const int nItemId = ITEMMODE_SelectRandomMiscItemId(pGame, pSeed, nItemLevel, a4, a5, bIsMonster);

    D2CoordStrc coords1;
    D2CoordStrc coords2;
    coords2.nX = pCoords->nX;
    coords2.nY = pCoords->nY;

    const int nX = coords2.nX + 2;
    const int nY = coords2.nY + 3;
    if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
    {
        coords1.nX = nX;
        coords1.nY = nY;
    }
    else
    {
        coords1.nX = coords2.nX;
        coords1.nY = coords2.nY;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, COLLIDE_MASK_SPAWN, 0x801, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop;
        memset(&itemDrop, 0, sizeof(itemDrop));

        itemDrop.pUnit = pUnit;
        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.pGame = pGame;
        itemDrop.nId = nItemId;
        itemDrop.nSpawnType = ITEMSPAWN_GROUND;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
    }

    return 0;
}

// 0x0055A200
void __fastcall ITEMS_DropPlayerEar(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = 0;
    int nItemId;
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER || !DATATBLS_GetItemRecordFromItemCode(' rae', &nItemId))
    {
        return;
    }

    D2CoordStrc unitCoords;
    D2CoordStrc coords;

    UNITS_GetCoords(pUnit, &unitCoords);

    pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &unitCoords, &coords, 1, 1);
    if (!pRoom)
    {
        return;
    }

    D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pUnit, nItemId, pGame, 4, 2, 1, 1, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), 0, 0, 0);
    if (pItem)
    {
        D2GAME_DropItem_6FC52260(pGame, 0, pItem, pRoom, coords.nX, coords.nY);
    }
}

// 0x0055A2A0
D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame)
{
    unsigned char aBuffer[1024];
    D2ItemSaveStrc itemSave;
    unsigned int nRead;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    unsigned int nSize = ITEMS_SerializeItemToBitstream(pItem, aBuffer, 1024, 1, 1, 0);
    ITEMS_GetCompactItemDataFromBitstreamDefault(aBuffer, nSize, 1, &itemSave);
    D2UnitStrc* pNewItem = ITEMS_CreateItemFromBitstream(pGame, pRoom, aBuffer, nSize, 1, &itemSave, &nRead, 96);
    if (!pNewItem)
        return 0;
    unsigned char* pBitstream = aBuffer + nRead;
    nSize -= nRead;
    ITEMS_SetItemFlag(pNewItem, 0x80000, 1);
    ITEMS_SetItemFlag(pNewItem, 0x2000, 0);
    if (bAddToGame && itemSave.nItemFileIndex)
    {
        const int nSocketCount = itemSave.nItemFileIndex;
        for (int i = 0; i < nSocketCount; ++i)
        {
            ITEMS_GetCompactItemDataFromBitstreamDefault(pBitstream, nSize, 1, &itemSave);

            D2UnitStrc* __restrict pFiller = ITEMS_CreateItemFromBitstream(pGame, 0, pBitstream, nSize, 1, &itemSave, &nRead, 96);
            if (!pFiller)
                return 0;
            pBitstream += nRead;
            nSize -= nRead;
            UNITS_ChangeAnimMode(pFiller, 4);
            int bPlaced;
            if (!D2GAME_ITEMSOCKET_PlaceItem_6FC497E0(pGame, pNewItem, !pFiller ? -1 : pFiller->dwUnitId, GAME_GetUnitGUID(pNewItem), &bPlaced, 0, 1, 0, 0))
            {
                FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xDD4);
                exit(-1);
            }
            ITEMS_SetItemFlag(pFiller, 0x80000, 1);
            ITEMS_SetItemFlag(pFiller, 0x2000, 0);
            ITEMS_SetItemCMDFlag(pFiller, 1, 0);
        }
    }
    ITEMS_SetItemFlag(pItem, 0x8000000, 1);
    const int nReplenishDurability = STATLIST_UnitGetStatValue(pNewItem, STAT_ITEM_REPLENISH_DURABILITY, 0);
    if (nReplenishDurability && !EVENT_GetEventFrame(pGame, pNewItem, 3))
        EVENT_SetEvent(pGame, pNewItem, 3, pGame->dwGameFrame + 2500 / nReplenishDurability + 1, 0, 0);
    const int nReplenishQuantity = STATLIST_UnitGetStatValue(pNewItem, STAT_ITEM_REPLENISH_QUANTITY, 0);
    if (nReplenishQuantity && !EVENT_GetEventFrame(pGame, pNewItem, 3))
        EVENT_SetEvent(pGame, pNewItem, 3, pGame->dwGameFrame + 2500 / nReplenishQuantity + 1, 0, 0);
    D2GAME_ResetSomeItemFlags_6FC415F0(pGame, pNewItem);
    ITEMS_SetItemCMDFlag(pNewItem, 1, 0);
    return pNewItem;
}

D2UnitStrc* __fastcall ITEMS_DropRandomItemAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2ItemDropStrc* pItemDrop)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pGame->nDifficulty, pGame->bExpansion);
    if (nItemLevel > 1)
    {
        nItemLevel -= 1;
    }

    if (nItemLevel >= 65)
    {
        nItemLevel = 64;
    }

    D2SeedStrc* pSeed;
    if (pRoom)
    {
        pSeed = &((D2ActiveRoomStrcView*)pRoom)->pSeed;
    }
    else
    {
        pSeed = 0;
    }

    const int nItemId = ITEMS_SelectRandomDropItemId(pGame, pSeed, nItemLevel, -1, 0, 0);

    D2CoordStrc coords1;
    D2CoordStrc coords2;

    coords2.nX = pCoords->nX;
    coords2.nY = pCoords->nY;

    if (sub_00463740_FindRoomAtPoint(pRoom, coords2.nX + 2, coords2.nY + 3))
    {
        coords1.nX = coords2.nX + 2;
        coords1.nY = coords2.nY + 3;
    }
    else
    {
        coords1.nX = coords2.nX;
        coords1.nY = coords2.nY;
    }

    D2ActiveRoomStrc* pTargetRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &coords1, &coords2, 1, 0x3E01, 0x801, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop = {};

        itemDrop.pSeed = pSeed;
        itemDrop.wItemFormat = pGame->wItemFormat;
        itemDrop.nId = nItemId;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pUnit = 0;
        itemDrop.pGame = pGame;
        itemDrop.nSpawnType = 3;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.wUnitInitFlags = 1;
        itemDrop.nQuality = 0;
        itemDrop.nItemLvl = nItemLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);

        if (pItemDrop)
        {
            *pItemDrop = itemDrop;
        }

        return pItem;
    }

    return 0;
}

// 0x00559A30
D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* ptGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int nItemType, int bIgnoreRarity)
{
    D2_ASSERT(ptGame, 0x9C7);

    D2SeedStrc* pSeed = &pUnit->pSeed;

    int bIsMonster = 0;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        bIsMonster = 1;
    }

    int nLevel;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            nLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
        }
        else
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            D2GameStrc* pUnitGame = SUNIT_GetGameFromUnit(pUnit);
            nLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pUnitGame->nDifficulty, pUnitGame->bExpansion);
        }

        if (nLevel <= 1)
        {
            nLevel = 1;
        }
    }
    else
    {
        nLevel = 1;
    }
    *pItemLevel = nLevel;

    int nItemId = -1;
    if (!pUnit->dwDropItemCode)
    {
        nItemId = ITEMS_SelectRandomDropItemId(ptGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity, bIsMonster);
        if (nQuality == 4)
        {
            int nCounter = 0;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
            while (!pItemsTxtRecord || !(pItemsTxtRecord->dwBitField1 & 1))
            {
                if (nCounter > 10)
                {
                    nItemId = ITEMMODE_SelectRandomWeaponItemId(ptGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity);
                }
                else
                {
                    nItemId = ITEMS_SelectRandomDropItemId(ptGame, pSeed, *pItemLevel, nItemType, bIgnoreRarity, bIsMonster);
                }

                pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemId);
                nCounter += 1;
            }
        }
    }
    else
    {
        nItemId = DATATBLS_GetItemIdFromItemCode(pUnit->dwDropItemCode);
        D2_ASSERT(nItemId != -1, 0x9EA);
    }

    D2CoordStrc coords1;
    D2CoordStrc unitCoords;

    UNITS_GetCoords(pUnit, &unitCoords);

    D2ActiveRoomStrc* pTargetRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &unitCoords, &coords1, 1, 1);
    if (pTargetRoom)
    {
        D2ItemDropStrc itemDrop = {};

        itemDrop.wItemFormat = ptGame->wItemFormat;
        itemDrop.nX = coords1.nX;
        itemDrop.nY = coords1.nY;
        itemDrop.pRoom = pTargetRoom;
        itemDrop.nQuality = nQuality;
        itemDrop.nItemLvl = *pItemLevel;
        itemDrop.pUnit = pUnit;
        itemDrop.pSeed = 0;
        itemDrop.pGame = ptGame;
        itemDrop.nId = nItemId;
        itemDrop.nSpawnType = 3;
        itemDrop.wUnitInitFlags = 1;

        D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(ptGame, &itemDrop, 0);

        if (pItemDrop)
        {
            *pItemDrop = itemDrop;
        }

        return pItem;
    }

    return 0;
}

inline unsigned __int64 Roll(D2UnitStrc* pUnit) {
 unsigned __int64 seed=pUnit->pSeed.nHighSeed+0x6AC690C5i64*pUnit->pSeed.nLowSeed;
 pUnit->pSeed.nHighSeed=(unsigned)(seed>>32);pUnit->pSeed.nLowSeed=(unsigned)seed;return seed;
}

// 0x00559E30
void __fastcall ITEMS_UpdateDurability(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem) {
 int bWeapon=ITEMSIsA(pItem,50);
 int bStack=ITEMSIsA(pItem,45);
 if ((!bWeapon && !bStack) || !ITEMS_HasDurability(pItem)) return;
 int chance=4;
 if (bWeapon) chance=10;
 else if (ITEMS_CheckIfThrowable(pItem)) { if (!pGame->bExpansion) return; chance=10; }
 if ((int)((unsigned)Roll(pPlayer)%100)>=chance) return;
 int durability=STATLIST_UnitGetStatValue(pItem,STAT_DURABILITY,0)-1;
 if (durability>0) {
  if(durability>=STATLIST_GetMaxDurabilityFromUnit(pItem)) durability=STATLIST_GetMaxDurabilityFromUnit(pItem);
  ITEMS_ScheduleDurabilityReplenishment(pGame,pItem);
  STATLIST_SetUnitStat(pItem,STAT_DURABILITY,durability,0);
  SEND(72,durability,0xc5a);
 } else {
  if(!bStack && !sub_006280A0(pItem,0x100,0xc5f,".\\ITEMS\\Items.cpp")) {ITEMMODE_BreakItem(pGame,pPlayer,pItem);return;}
  if(ITEMS_GetItemFormat(pItem)>=1) {
   int quantity=STATLIST_UnitGetStatValue(pItem,STAT_QUANTITY,0);
   if(quantity>1) {
    --quantity;STATLIST_SetUnitStat(pItem,STAT_QUANTITY,quantity,0);SEND(70,quantity,0xc70);
    durability=STATLIST_GetMaxDurabilityFromUnit(pItem);
    STATLIST_SetUnitStat(pItem,STAT_DURABILITY,durability,0);SEND(72,durability,0xc73);
   } else {
    STATLIST_SetUnitStat(pItem,STAT_DURABILITY,0,0);SEND(72,0,0xc78);
    STATLIST_SetUnitStat(pItem,STAT_QUANTITY,0,0);SEND(70,quantity,0xc7b);
    PLRMODE_HandleDepletedWeapons(pGame,pPlayer);
   }
   if(ITEMS_GetTotalMaxStack(pItem)>0) ITEMS_ScheduleDurabilityReplenishment(pGame,pItem);
  } else {STATLIST_SetUnitStat(pItem,STAT_DURABILITY,0,0);SEND(72,0,0xc87);}
 }
}

#define GOLD_PILE_MAX 2000000000

static inline void D2GAME_SetStatOrResetGold_Inline(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case STAT_GOLDBANK:
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}

// 0x0055A090
void __fastcall ITEMS_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount)
{
    *pCount = 0;

    int nItemId;
    if (!DATATBLS_GetItemRecordFromItemCode(' dlg', &nItemId))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    unsigned int nDropped = 0;
    const unsigned int nTotal = nAmount;
    while (nDropped < nTotal)
    {
        if (*pCount >= nMaxCount)
        {
            return;
        }

        const unsigned int nPile = nAmount > GOLD_PILE_MAX ? GOLD_PILE_MAX : nAmount;
        nDropped += nPile;
        nAmount -= nPile;

        D2CoordStrc tCoord;
        UNITS_GetCoords(pUnit, &tCoord);

        const int nX = tCoord.nX + 2;
        const int nY = tCoord.nY + 3;
        D2CoordStrc tSpawn;
        if (sub_00463740_FindRoomAtPoint(pRoom, nX, nY))
        {
            tSpawn.nX = nX;
            tSpawn.nY = nY;
        }
        else
        {
            tSpawn = tCoord;
        }

        pRoom = COLLISION_GetFreeCoordinatesWithField(pRoom, &tSpawn, &tCoord, 1, 0x3E01, 0x801, 0);
        if (!pRoom)
        {
            return;
        }

        D2UnitStrc* pGold = D2GAME_CreateItemUnit_6FC501A0(pUnit, nItemId, pGame, 4, 2, 1, 1, 1, 0, 0, 0);
        if (pGold)
        {
            D2GAME_SetStatOrResetGold_Inline(pGold, STAT_GOLD, nPile);
            D2GAME_DropItem_6FC52260(pGame, pUnit, pGold, pRoom, tSpawn.nX, tSpawn.nY);
            ppGold[*pCount] = pGold;
            *pCount += 1;
        }
    }
}

// 0x0055A550
static D2UnitStrc* __stdcall ITEMS_CreateDropAtUnit(D2GameStrc* pGame, int nQuality, int nItemIndex, int nFlags, int nItemId, D2UnitStrc* pUnit)
{
    if (nItemId < 0)
    {
        return 0;
    }

    D2CoordStrc tCoords;
    UNITS_GetCoords(pUnit, &tCoords);

    D2CoordStrc tItemCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &tCoords, &tItemCoords, 1, 1);
    if (!pRoom)
    {
        return 0;
    }

    D2ItemDropStrc tItemDrop;
    memset(&tItemDrop, 0, sizeof(tItemDrop));
    tItemDrop.pGame = pGame;
    tItemDrop.wItemFormat = pGame->wItemFormat;
    tItemDrop.nId = nItemId;
    tItemDrop.pUnit = pUnit;
    tItemDrop.pSeed = 0;
    tItemDrop.nSpawnType = 3;
    tItemDrop.nX = tItemCoords.nX;
    tItemDrop.nY = tItemCoords.nY;
    tItemDrop.pRoom = pRoom;
    tItemDrop.wUnitInitFlags = 1;
    tItemDrop.nQuality = nQuality;

    int nItemLevel = 0;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            nItemLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        }
        else if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            nItemLevel = STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0);
        }
        else
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            D2GameStrc* pUnitGame = SUNIT_GetGameFromUnit(pUnit);
            nItemLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, pUnitGame->nDifficulty, pUnitGame->bExpansion);
        }
    }
    nItemLevel = D2_MAX(nItemLevel, 1);
    tItemDrop.nItemLvl = nItemLevel;
    tItemDrop.nItemIndex = nItemIndex;

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwClassId == 0x187)
    {
        tItemDrop.dwFlags2 = 1;
    }
    tItemDrop.dwFlags2 |= nFlags;

    return D2GAME_CreateItemEx_6FC4ED80(pGame, &tItemDrop, 0);
}

void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc*); // 0x004DC0B0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 nSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(nSeed >> 32);
    pSeed->nLowSeed = (unsigned int)nSeed;
    return (unsigned int)nSeed;
}

static inline D2SkillsTxt* GetSkillsRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}

struct D2BooksTxt;

struct D2BookDataTbl;


D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables(); // 0x006374A0

int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll); // 0x005C2540
// 0x00558A10
int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (ITEMS_IsQuestItem(pUnit))
    {
        return 0;
    }

    const int nItemQuality = ITEMS_GetItemQuality(pUnit);
    if (nItemQuality != ITEMQUAL_MAGIC)
    {
        if (nItemQuality > ITEMQUAL_MAGIC && nItemQuality <= ITEMQUAL_TEMPERED)
        {
            return pGame->dwGameFrame + 45000;
        }

        if (ITEMS_GetItemType(pUnit) == ITEMTYPE_GOLD)
        {
            if (STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0) > 10000)
            {
                return pGame->dwGameFrame + 45000;
            }

            return pGame->dwGameFrame + 15000;
        }

        if (ITEMS_IsSocketFiller(pUnit))
        {
            return pGame->dwGameFrame + 30000;
        }

        return pGame->dwGameFrame + 15000;
    }

    return pGame->dwGameFrame + 30000;
}

void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00543DB0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70

// 0x00558AA0
void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    if (!pRoom)
    {
        return;
    }

    UNITS_InitializeStaticPath(pItem, pRoom, nX, nY);
    UNITS_BlockCollisionPath(pItem, pRoom, nX, nY);
    UNITROOM_AddUnitToRoom(pItem, pRoom);

    if (pItem)
    {
        pItem->dwFlags |= 0x1002;
    }

    UNITS_ChangeAnimMode(pItem, 3);
    ITEMS_SetInvPage(pItem, 0xFF);

    if (pItem)
    {
        pItem->dwFlags |= 0x2000000;
    }

    pItem->pItemData->dwActionStamp = ITEMS_GetGroundRemovalTime(pGame, pItem);

    if (pUnit)
    {
        QUESTS_ItemDropped(pGame, pUnit, pItem);
    }
}

// 0x00558B40
void __fastcall ITEMS_RemoveItemFromGame(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (!pItem)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
    if (pRoom)
    {
        DUNGEON_AllocDrlgDelete(pRoom, pItem->dwUnitType, pItem->dwUnitId);
        UNITS_FreeCollisionPath(pItem);
        UNITROOM_RemoveUnitFromRoom(pItem);
    }

    pItem->dwFlags &= ~2u;
    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
    SUNIT_RemoveUnit(pGame, pItem);
}

// 0x00558B90
void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct)
{
    if (!pGame->pAct[nAct])
    {
        return;
    }

    const int nGameFrame = pGame->dwGameFrame;
    for (D2ActiveRoomStrc* i = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]); i; i = i->pRoomNext)
    {
        D2UnitStrc* pNext = i->pUnitFirst;
        while (pNext)
        {
            D2UnitStrc* pItem = pNext;
            pNext = pItem->ptRoomNext;
            if (pItem->dwUnitType == UNIT_ITEM)
            {
                const int nDeletionFrame = pItem->pItemData->dwActionStamp;
                if (nDeletionFrame && nDeletionFrame <= nGameFrame)
                {
                    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pItem);
                    if (pRoom)
                    {
                        DUNGEON_AllocDrlgDelete(pRoom, pItem->dwUnitType, pItem->dwUnitId);
                        UNITS_FreeCollisionPath(pItem);
                        UNITROOM_RemoveUnitFromRoom(pItem);
                    }

                    pItem->dwFlags &= ~UNITFLAG_TARGETABLE;
                    SUNIT_IterateLivingPlayers(pGame, ITEMS_PlayerIterateCallback_RemoveItem, pItem);
                    SUNIT_RemoveUnit(pGame, pItem);
                }
            }
        }
    }
}

// 0x00558C50
void __fastcall ITEMS_DestroyRunewordStatList(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    if (!pItem || pItem->dwUnitType != UNIT_ITEM || !(ITEMS_GetItemFlags(pItem) & IFLAG_RUNEWORD))
    {
        return;
    }

    ITEMS_SetItemFlag(pItem, IFLAG_RUNEWORD, 0);
    ITEMS_AssignPrefix(pItem, 0, 0);

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateOrFlag(pItem, STATE_RUNEWORD, 0x40);
    if (pStatList)
    {
        D2Common_10474(pItem, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
}

#include "gen/data/Source/D2Game/ITEMS/Items.inc"
