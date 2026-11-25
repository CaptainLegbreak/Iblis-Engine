#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameAux.h"
#include "D2TxtItems.h"
#include "D2Win32Types.h"
#include "D2GameObjs.h"
#include "D2UnitData.h"
#include "D2Records.h"
#include "D2Path.h"
#include "D2ItemsWorld.h"
#include "D2ItemModes.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00732048

struct D2ClientStrc;

struct D2GameStrc;

struct D2UnitStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define INVPAGE_CUBE 3

#define STRCOLOR_WHITE 0

#define EVENTTYPE_PLAYERISBUSY 8

#define EVENTTYPE_PLEASEWAIT 9

struct D2ObjectControlStrc;

struct D2PlayerTradeStrc;

struct D2ObjOperateFnStrc;

struct D2PlayerDataStrc;

struct D2CubeItemStrc;


struct Item;

struct ItemRecordTable;

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00568640

enum
{
    UPDATEUI_OPENSTASH = 0x10,
};

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall GetLocalTime(D2SystemTimeStrc* pSystemTime); // 0x006CC1D4

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int gbEnableAllCubeRecipes; // 0x0088CAC0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int __fastcall PLRSAVE_WriteUnitItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7); // 0x00531BB0

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag); // 0x00538670

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830

void __fastcall D2GAME_PACKETS_SendPacket0x63_WaypointMenu(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket); // 0x0053CAD0

void __fastcall D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(D2ClientStrc* pClient, int nGold, char bOwnGold); // 0x0053CBE0

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010

void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue); // 0x0053FF00

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0

void __fastcall ITEMS_HandleGoldTransaction(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nValue); // 0x0055B060

void __fastcall D2GAME_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10

int __fastcall D2GAME_CheckHasFilledSockets(D2UnitStrc* pItem, const char* szFile, int nLine); // 0x0055F590

void __fastcall ITEMMODE_ResetBookScrollSkillQuantity(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F9C0

int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200

int __fastcall ITEMMODE_DuplicateSocketFillers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pSocketable, int bRefresh); // 0x00563350

D2UnitStrc* __fastcall PLRTRADE_CreateCubeOutputs(D2GameStrc* game,D2UnitStrc* player,D2CubeMainTxt* recipe,D2CubeItemStrc* inputs,int unused); // 0x00565AB0

int __fastcall PLRTRADE_CheckCubeInput(D2GameStrc* pGame, D2InventoryStrc* pInventory, D2CubeMainTxt* pCubeMainTxtRecord, int nInputIndex, D2CubeItemStrc* pCubeItem, int* pUsedItems); // 0x00565010

void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00566BF0

void __fastcall PLRTRADE_CancelTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2, int nTradeState); // 0x005679E0

int __fastcall INVMODE_IsTradeBusy(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597A20

int __fastcall ACT4Q2_HasDiabloBeenKilled(D2GameStrc* pGame); // 0x005B5810

void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320

int __stdcall ITEMS_GetEarLevel(D2UnitStrc* pItem); // 0x006283A0

void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

static void __stdcall PLRTRADE_HandleCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005665F0

struct Seed { unsigned low,high; };

struct Game { char pad0[0x78]; unsigned short format; char pad7A[0x56]; Seed seed; };

struct Item { char pad0[0xF6]; unsigned short format; char padF8[5]; unsigned char level; char padFE[0x35]; unsigned char spawnable; char pad134[0x74]; };

struct ItemRecordTable { int count; Item* records; };

ItemRecordTable* __stdcall sub_00633590(); // 0x00633590

unsigned __fastcall sub_0045C3E0(Seed*,int); // 0x0045C3E0

int __stdcall ITEMS_CheckItemTypeIdByItemId(int,int); // 0x00629A90

enum { EXPANSION_FORMAT = 100 };

int __fastcall ACT1Q4_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00594140

int __fastcall ACT1Q4_CreateUberRunPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00594270

int __fastcall ACT1Q4_CreateUberFinalePortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00594280

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

void __fastcall D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket); // 0x0053C850

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource); // 0x00566D90

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

void __fastcall ITEMMODE_RemoveInventoryItemProperties(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0055FCC0

void __fastcall PLRTRADE_IterateCallback_SendInventoryReset(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg); // 0x00566C80

void __fastcall PLRTRADE_RestoreTradeSnapshot(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00566CC0

void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170

void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70

struct D2CubeInputItem;

struct D2ItemsTxt;

struct D2CubeItemStrc
{
    D2UnitStrc* pItem;
    int nClassId;
    int nItemLevel;
};

int __stdcall STATLIST_GetFullStatsCountFromUnit(D2UnitStrc* pUnit); // 0x00625290

int __stdcall STATLIST_GetUnitStatBonus(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625560

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned int __stdcall ITEMS_GetItemFlags(D2UnitStrc* pItem); // 0x00628110

int __stdcall ITEMS_GetItemLevel(D2UnitStrc* pItem); // 0x006281E0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

unsigned char __stdcall ITEMS_GetSockets(D2UnitStrc* pItem); // 0x006299B0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

unsigned char __stdcall ITEMS_GetMaxSockets(D2UnitStrc* pItem); // 0x0062BC20

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __stdcall FOG_GetLinkIndex(void* pLink, unsigned int dwCode, int bLogError); // 0x006BD130

static void __stdcall PLRTRADE_HandleStashButton(D2GameStrc* pGame, unsigned short nButton, D2UnitStrc* pPlayer, int nUnitGUID, int nGold); // 0x00564D50

static int PLRTRADE_CountCubeItems(D2InventoryStrc* pInventory); // 0x00564FD0

static int __stdcall PLRTRADE_CheckCubeInputs(D2GameStrc* pGame, D2CubeItemStrc* pCubeItem, D2CubeMainTxt* pCubeMainTxtRecord, D2InventoryStrc* pInventory); // 0x005658C0

static void PLRTRADE_HandleCubeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton); // 0x00566AE0

static bool PLRTRADE_AllocPlayerTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00566B30


static void __stdcall PLRTRADE_CopyEarData(int bHardcore, D2UnitStrc* pItem, D2UnitStrc* pDupeItem); // 0x00567070

static bool __stdcall PLRTRADE_TransferItems(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x005670E0

static int __stdcall PLRTRADE_CanPickUpTradeItems(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pReceiver); // 0x005672D0


static void __stdcall PLRTRADE_AcceptTrade(D2GameStrc* pGame, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData, D2UnitStrc* pPlayer); // 0x00567C70

void __fastcall PLRTRADE_RefreshTradeSnapshot(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00568D10

int __fastcall sub_00463720_TestUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask);                         // 0x00463720

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode);  // 0x00558110

#define CUBE_MAX(a,b) ((a)>(b)?(a):(b))

#define CUBE_MIN(a,b) ((a)<(b)?(a):(b))

union D2SeedStrc;

struct D2CubeParam;

struct D2CubeOutputItem;

struct D2PropertyStrc;

typedef int (__fastcall *CubeOutputFunc)(D2GameStrc*,D2UnitStrc*);

extern const CubeOutputFunc gpfnCubeOutputFunctions[]; // 0x006E11C8

extern const unsigned gdwBitMasks[]; // 0x006CE268

extern const unsigned gdwInvBitMasks[]; // 0x006CE2E8

extern const char gszPlrTradeCpp[]; // 0x006E11D8

void __fastcall SUNIT_RemoveUnit(D2GameStrc*,D2UnitStrc*); // 0x00555600

int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int bQuestItem); // 0x00557AB0

void __fastcall ITEMS_DestroyRunewordStatList(D2GameStrc*,D2UnitStrc*); // 0x00558C50

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc*,D2ItemDropStrc*,int); // 0x00558D90

void __fastcall D2GAME_RepairBrokenItem(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0055F900

int __fastcall D2GAME_RechargeItem_6FC4BD50(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055FE80

unsigned short __fastcall PLRTRADE_RollRandomItemClassOfSameType(D2GameStrc*,int,int); // 0x00565930

void __fastcall ACT2Q2_UpdateHoradricItemCounts(D2GameStrc*,D2UnitStrc*); // 0x0059E5C0

void __fastcall ACT3Q2_UpdateKhalimItemCounts(D2GameStrc*,D2UnitStrc*); // 0x005B86E0

unsigned short __fastcall ITEMS_RollTemperedItemAffix(D2UnitStrc*,int); // 0x005C1BC0

int __stdcall DATATBLS_GetMaxLevel(int); // 0x00611830

void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,unsigned short); // 0x00627260

void __stdcall ITEMS_SetItemQuality(D2UnitStrc*,int); // 0x00627EA0

void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc*,unsigned short); // 0x00628010

void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc*,unsigned short); // 0x00628070

int __stdcall ITEMS_GetTotalMaxStack(D2UnitStrc*); // 0x006295B0

void __stdcall ITEMS_AddSockets(D2UnitStrc*,int); // 0x0062BCB0

void __stdcall ITEMMODS_AddCraftPropertyList(D2UnitStrc*,D2PropertyStrc*,int); // 0x00660240

static int __stdcall PLRTRADE_RemoveCubeInputs(D2GameStrc* game,D2UnitStrc* unit,D2ClientStrc* client);

extern "C" const char szPlrTradeCpp[];                                                                      // 0x006E11D8

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit);                           // 0x00557FD0

int __fastcall ITEMMODE_RemoveStoredItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* a4, int a5, int bSetQuantityFlag, D2InventoryStrc* pInventoryArg, int a8); // 0x00560420

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath);                                           // 0x00648900

int __fastcall ITEMMODE_DuplicateSocketFillers(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pSocketable, int bRefresh);

static void __stdcall PLRTRADE_AddItemTrade(D2GameStrc* pGame, int nItemGUID1, int nItemGUID2, D2UnitStrc* pPlayer); // 0x00567350

// build: base-profile

struct D2InventoryStrc;

struct D2ActiveRoomStrc;

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit);                                                 // 0x00451F60

D2ItemStatCostTxt* __fastcall PLAYER_GetItemStatCostTxtRecord(int nStatId);                           // 0x0045C4F0

int __fastcall ITEMMODE_CanPickUpItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem);             // 0x0055CC90

void __fastcall ITEMMODE_RebuildBookScrollSkillQuantities(D2GameStrc* pGame, D2UnitStrc* pUnit);                                         // 0x0055FA40

void __fastcall sPlayerRestoreInventoryCopy(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x005678F0

int __stdcall UNITS_GetStashGoldLimit(D2UnitStrc* pUnit);                                                   // 0x00623460

char* __stdcall ITEMS_GetEarName(D2UnitStrc* pItem);                                                        // 0x00628340

void __stdcall ITEMS_SetEarName(D2UnitStrc* pItem, char* szName);                                           // 0x00628370

void __stdcall ITEMS_SetEarLevel(D2UnitStrc* pItem, unsigned char nLevel); // 0x006283D0

int __stdcall INVENTORY_CanItemsBeTraded(void* pMemPool, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, int* pTradeState); // 0x0063E370

D2CubeMainTxt* __stdcall DATATBLS_GetCubemainTxtRecord(int nIndex);                                         // 0x0066A1B0

int __fastcall DATATBLS_GetCubemainTxtRecordCount();                                                        // 0x0066A200

int __fastcall PLRTRADE_HandleTradeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton, unsigned int nGold);

static void __stdcall PLRTRADE_AddItemTrade(D2GameStrc*, int, int, D2UnitStrc*); // 0x00567350

static char __stdcall PLRTRADE_FindItemTrade(int*, int, D2UnitStrc*); // 0x005673C0

static int PLRTRADE_CountCubeItems(D2InventoryStrc* pInventory); // 0x00564FD0

static int __stdcall PLRTRADE_CheckCubeInputs(D2GameStrc* pGame, D2CubeItemStrc* pCubeItem, D2CubeMainTxt* pCubeMainTxtRecord, D2InventoryStrc* pInventory); // 0x005658C0

int __fastcall PLRTRADE_PrepareItemChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

static void __stdcall PLRTRADE_ResetTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2); // 0x00567B00


static char __stdcall PLRTRADE_FindItemTrade(int* pItemGUID2, int nItemGUID1, D2UnitStrc* pPlayer); // 0x005673C0

void __fastcall PLRTRADE_RemoveItemFromTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

static void PLRTRADE_WalkItemTrade(D2UnitStrc* pPlayer);

void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

static void PLRTRADE_HandleCubeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton); // 0x00566AE0

static bool PLRTRADE_AllocPlayerTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00566B30

static void __stdcall PLRTRADE_CopyEarData(int bHardcore, D2UnitStrc* pItem, D2UnitStrc* pDupeItem); // 0x00567070

static int __stdcall PLRTRADE_CanPickUpTradeItems(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pReceiver); // 0x005672D0

static void __stdcall PLRTRADE_AcceptTrade(D2GameStrc* pGame, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData, D2UnitStrc* pPlayer); // 0x00567C70

static int PLRTRADE_HasItemsInCube(D2UnitStrc* pPlayer);


int __fastcall PLRTRADE_HandleTradeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton, unsigned int nGold);

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

#define PACKETSIZE06_HEADER 0x92

// 0x00564CB0
void __fastcall sub_00564CB0_Nop(D2UnitStrc* pUnit)
{
}

struct D2TaskStrc;

// 0x00564CC0
void __fastcall TASK_SetType(D2TaskStrc* pTask, int nType)
{
    if (pTask)
    {
        pTask->nType = nType;
    }
}

// 0x00564CD0
int __fastcall OBJECTS_OperateFunction32_Bank(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (pOp->nObjectIdx == OBJECT_STASH)
    {
        D2ActiveRoomStrc* pPlayerRoom = UNITS_GetRoom(pOp->hPlayer);
        if (pPlayerRoom && DUNGEON_IsRoomInTown(pPlayerRoom))
        {
            D2ActiveRoomStrc* pObjectRoom = UNITS_GetRoom(pOp->hObject);
            if (pObjectRoom && DUNGEON_IsRoomInTown(pObjectRoom))
            {
                SUNIT_SetInteractInfo(pOp->hPlayer, UNIT_OBJECT, !pOp->hObject ? -1 : pOp->hObject->dwUnitId);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pOp->hPlayer, ".\\PLAYER\\PlrTrade.cpp", 101), UPDATEUI_OPENSTASH);
                sub_6FC4B830(pOp->pGame, pOp->hPlayer);
            }
        }
    }

    return 0;
}

// 0x00564D50
static void __stdcall PLRTRADE_HandleStashButton(D2GameStrc* pGame, unsigned short nButton, D2UnitStrc* pPlayer, int nUnitGUID, int nGold)
{
    int nUnitType;
    int nGUID;
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nUnitGUID);
    if (!pObject || pObject->dwClassId != OBJECT_STASH)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
    {
        return;
    }

    pRoom = UNITS_GetRoom(pObject);
    if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
    {
        return;
    }

    switch (nButton)
    {
    case 0x12:
    {
        if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nGUID) && nUnitType == 2)
        {
            SUNIT_ResetInteractInfo(pPlayer);
        }
        sub_6FC4B830(pGame, pPlayer);
        break;
    }
    case 0x13:
    {
        if (nGold > 0 && nGold <= STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDBANK, 0))
        {
            if (STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0) + nGold <= UNITS_GetInventoryGoldLimit(pPlayer))
            {
                ITEMS_HandleGoldTransaction(pGame, pPlayer, nGold);
                PLRTRADE_AddGold(pPlayer, 0xF, -nGold);
            }
            else
            {
                SUNIT_AttachSound(pPlayer, 0x13, pPlayer);
            }
        }
        break;
    }
    case 0x14:
    {
        if (nGold > 0 && nGold <= STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0))
        {
            const unsigned int nStashGoldLimit = UNITS_GetStashGoldLimit(pPlayer);
            const unsigned int nGoldBank = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDBANK, 0);
            if (nGoldBank + nGold > nStashGoldLimit)
            {
                if (nGoldBank < nStashGoldLimit)
                {
                    PLRTRADE_AddGold(pPlayer, 0xF, nStashGoldLimit - nGoldBank);
                    PLRTRADE_AddGold(pPlayer, 0xE, nGoldBank - nStashGoldLimit);
                }
            }
            else
            {
                PLRTRADE_AddGold(pPlayer, 0xE, -nGold);
                PLRTRADE_AddGold(pPlayer, 0xF, nGold);
            }
        }
        break;
    }
    }
}

// 0x00564F00
int __cdecl OBJECTS_CompareDescending(const unsigned int* pValue1, const unsigned int* pValue2)
{
    const unsigned int nValue1 = *pValue1;
    const unsigned int nValue2 = *pValue2;
    if (nValue1 > nValue2)
    {
        return -1;
    }

    return nValue1 != nValue2;
}

// 0x00564F30
static int __stdcall PLRTRADE_RemoveCubeInputs(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (!pUnit->pInventory)
    {
        return 0;
    }

    int nCount = 0;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pCheckedItem && ITEMS_GetInvPage(pCheckedItem) == INVPAGE_CUBE)
        {
            int nFlags = 0;
            ITEMS_SetOrRemoveFlag(&nFlags, 32, 1);
            ITEMS_SetItemCell(pCheckedItem, INVPAGE_CUBE);
            D2GAME_UpdateClientItem_6FC3E9D0(pClient, pUnit, pCheckedItem, nFlags);
            D2GAME_RemoveItem(pGame, pUnit, pCheckedItem, 0);
            nCount += 1;
        }
    }

    return nCount;
}

// 0x00564FD0
static int PLRTRADE_CountCubeItems(D2InventoryStrc* pInventory)
{
    int nCount = 0;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(pCheckedItem) == 3)
        {
            ++nCount;
        }
    }
    return nCount;
}

// 0x00565010
int __fastcall PLRTRADE_CheckCubeInput(D2GameStrc* pGame, D2InventoryStrc* pInventory, D2CubeMainTxt* pCubeMainTxt, int nInputIndex, D2CubeItemStrc* pCubeItem, int* pUsedItems)
{
    if (!pInventory)
    {
        return 0;
    }

    if (!(pCubeMainTxt->pInputItem[nInputIndex].wInputFlags & 3))
    {
        return 1;
    }

    int bNoStack = 1;
    int nItemCountWithStacks = 0;
    int nQuantity = pCubeMainTxt->pInputItem[nInputIndex].nQuantity;
    if (nQuantity <= 0)
    {
        nQuantity = 1;
    }

    D2ItemsTxt* pInputItemTxtRecord = 0;
    if ((pCubeMainTxt->pInputItem[nInputIndex].wInputFlags & 1) && pCubeMainTxt->pInputItem[nInputIndex].wItem != 0xFFFF)
    {
        pInputItemTxtRecord = DATATBLS_GetItemsTxtRecord(pCubeMainTxt->pInputItem[nInputIndex].wItem);
    }

    D2UnitStrc* pItem;
    D2ItemsTxt* pItemsTxtRecord;
    D2ItemStatCostTxt* pItemStatCostTxtRecord;
    int nStatId;
    int nValue;
    unsigned int dwItemCode;
    int nItemsInCube = 0;
    D2UnitStrc* pNext = INVENTORY_GetFirstItem(pInventory);
    while (pNext)
    {
        D2CubeMainTxt* pRecord = pCubeMainTxt;
        pItem = INVENTORY_UnitIsItem(pNext);
        pNext = INVENTORY_GetNextItem(pNext);
        if (!pItem || ITEMS_GetInvPage(pItem) != 3)
        {
            continue;
        }

        ++nItemsInCube;

        const int nItemClassId = pItem->dwClassId;
        pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nItemClassId);
        if (!pItemsTxtRecord)
        {
            continue;
        }

        dwItemCode = ITEMS_GetBaseCode(pItem);

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 1)
        {
            if (pRecord->pInputItem[nInputIndex].wItem != 0xFFFF)
            {
                if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x80)
                {
                    if (dwItemCode == pItemsTxtRecord->dwNormCode)
                    {
                        if (pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwNormCode)
                        {
                            continue;
                        }
                    }
                    else if (dwItemCode == pItemsTxtRecord->dwUberCode)
                    {
                        if (pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwNormCode && pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwUberCode)
                        {
                            continue;
                        }
                    }
                    else if (dwItemCode == pItemsTxtRecord->dwUltraCode)
                    {
                        if (pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwNormCode && pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwUberCode && pInputItemTxtRecord->dwCode != pItemsTxtRecord->dwUltraCode)
                        {
                            continue;
                        }
                    }
                    else
                    {
                        continue;
                    }
                }
                else if (pRecord->pInputItem[nInputIndex].wItem != (!pItem ? -1 : pItem->dwClassId))
                {
                    continue;
                }
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 2)
        {
            if (!ITEMSIsA(pItem, pRecord->pInputItem[nInputIndex].wItem))
            {
                continue;
            }
        }

        if (pCubeMainTxt->pInputItem[nInputIndex].nQuality && ITEMS_GetItemQuality(pItem) != pCubeMainTxt->pInputItem[nInputIndex].nQuality)
        {
            if (pCubeMainTxt->pInputItem[nInputIndex].nQuality == 9)
            {
                STATLIST_GetFullStatsCountFromUnit(pItem);
            }
            continue;
        }

        if ((pRecord->pInputItem[nInputIndex].wInputFlags & 0x40) && ITEMS_GetFileIndex(pItem) != pRecord->pInputItem[nInputIndex].wItemID - 1)
        {
            continue;
        }

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 4)
        {
            if (ITEMS_GetSockets(pItem) > 0)
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 8)
        {
            if (ITEMS_GetSockets(pItem) <= 0)
            {
                continue;
            }
        }

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x20)
        {
            if (ITEMS_IsEthereal(pItem))
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x10)
        {
            if (!ITEMS_IsEthereal(pItem))
            {
                continue;
            }
        }

        if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x100)
        {
            if (dwItemCode != pItemsTxtRecord->dwNormCode)
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x200)
        {
            if (dwItemCode != pItemsTxtRecord->dwUberCode)
            {
                continue;
            }
        }
        else if (pRecord->pInputItem[nInputIndex].wInputFlags & 0x400)
        {
            if (dwItemCode != pItemsTxtRecord->dwUltraCode)
            {
                continue;
            }
        }

        if ((pRecord->pInputItem[nInputIndex].wInputFlags & 0x800) && (ITEMS_GetItemFlags(pItem) & 0x4000000))
        {
            continue;
        }

        if (pRecord->nOp == 28 && pItemsTxtRecord->nQuest && pItemsTxtRecord->nQuestDiffCheck && STATLIST_UnitGetStatValue(pItem, STAT_QUESTITEMDIFFICULTY, 0) < pGame->nDifficulty)
        {
            continue;
        }

        if (!nInputIndex && (pRecord->pOutputItem[0].nType == 255 || pRecord->pOutputItem[0].nType == 254) && (pRecord->pOutputItem[0].wItemFlags & 2) && !ITEMS_GetMaxSockets(pItem))
        {
            continue;
        }

        if (nItemsInCube < 48 && pUsedItems[nItemsInCube - 1])
        {
            continue;
        }

        if (!nInputIndex)
        {
            if (pRecord->nOp)
            {
                switch (pRecord->nOp)
                {
                case 15:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) < nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 16:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) > nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 17:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) == nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 18:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_UnitGetStatValue(pItem, nStatId, 0) != nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 19:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) < nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 20:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) > nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 21:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) == nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 22:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitBaseStat(pItem, nStatId, 0) != nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 23:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) < nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 24:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) > nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 25:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) == nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 26:
                {
                    nStatId = pRecord->nParam;
                    if (nStatId >= 0 && nStatId <= sgptDataTables->nItemStatCostTxtRecordCount)
                    {
                        pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(nStatId);
                        if (!pItemStatCostTxtRecord)
                        {
                            continue;
                        }

                        nValue = pRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        if (STATLIST_GetUnitStatBonus(pItem, nStatId, 0) != nValue)
                        {
                            continue;
                        }
                    }
                    break;
                }
                case 27:
                {
                    if (ITEMS_GetFileIndex(pItem) == pRecord->nValue)
                    {
                        continue;
                    }
                    break;
                }
                default:
                    break;
                }
            }

            for (int i = 0; i < 3; ++i)
            {
                pCubeItem[i].nItemLevel = ITEMS_GetItemLevel(pItem);

                if (pRecord->pOutputItem[0].wItemFlags & 1)
                {
                    pCubeItem[i].pItem = pItem;
                }

                if (pRecord->pOutputItem[0].nType == 255)
                {
                    pCubeItem[i].pItem = pItem;
                    pCubeItem[i].nClassId = GAME_GetUnitClassId(pItem);

                    if (pRecord->pOutputItem[0].wItemFlags & 0x80)
                    {
                        if (pItemsTxtRecord->dwUberCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUberCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                    else if (pRecord->pOutputItem[0].wItemFlags & 0x100)
                    {
                        if (pItemsTxtRecord->dwUltraCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUltraCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                }
                else if (pRecord->pOutputItem[0].nType == 254)
                {
                    pCubeItem[i].pItem = pItem;
                    pCubeItem[i].nClassId = -1;

                    if (pRecord->pOutputItem[0].wItemFlags & 0x80)
                    {
                        if (pItemsTxtRecord->dwUberCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUberCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                    else if (pRecord->pOutputItem[0].wItemFlags & 0x100)
                    {
                        if (pItemsTxtRecord->dwUltraCode != 0x20202020)
                        {
                            const int nClassId = FOG_GetLinkIndex(sgptDataTables->pItemsLinker, pItemsTxtRecord->dwUltraCode, 0);
                            if (nClassId >= 0)
                            {
                                D2ItemsTxt* pLinkItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                                if (pLinkItemsTxtRecord && (pGame->bExpansion || pLinkItemsTxtRecord->wVersion < 100))
                                {
                                    pCubeItem[i].nClassId = nClassId;
                                }
                            }
                        }
                    }
                }
            }
        }

        if (nItemsInCube < 48)
        {
            pUsedItems[nItemsInCube - 1] = 1;
        }

        ++nItemCountWithStacks;
        if (ITEMS_CheckIfStackable(pItem))
        {
            bNoStack = 0;
        }
    }

    if (!bNoStack)
    {
        return nItemCountWithStacks >= nQuantity;
    }

    return nItemCountWithStacks == nQuantity;
}

// 0x005658C0
static int __stdcall PLRTRADE_CheckCubeInputs(D2GameStrc* pGame, D2CubeItemStrc* pCubeItem, D2CubeMainTxt* pCubeMainTxtRecord, D2InventoryStrc* pInventory)
{
    if (!pInventory || !pCubeMainTxtRecord)
    {
        return 0;
    }

    int anUsedItems[48];
    memset(anUsedItems, 0, sizeof(anUsedItems));
    for (int nInput = 0; nInput < 7; ++nInput)
    {
        if (!PLRTRADE_CheckCubeInput(pGame, pInventory, pCubeMainTxtRecord, nInput, pCubeItem, anUsedItems))
        {
            return 0;
        }
    }
    return 1;
}

// 0x00565930
short __fastcall PLRTRADE_RollRandomItemClassOfSameType(Game* game,int level,int type)
{
    short choices[256];
    ItemRecordTable* table=sub_00633590();
    int count=0;
    if(!table) { FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x384); exit(-1); }
    int start=sub_0045C3E0(&game->seed,table->count);
    int stop=start-1;
    if(stop<0) stop=table->count-1;
    int index=start;
    while(index!=stop) {
        if(count>=256) break;
        if(ITEMS_CheckItemTypeIdByItemId(index,type)) {
            Item* record=&table->records[index];
            if(record->spawnable && (record->format<EXPANSION_FORMAT || game->format>=EXPANSION_FORMAT) && record->level<=level) {
                choices[count++]=(short)index;
            }
        }
        ++index;
        if(index>=table->count) index=0;
    }
    if(!count) return 0;
    return choices[sub_0045C3E0(&game->seed,count)];
}

// 0x00565A80
int __fastcall PLRTRADE_CreateCowPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateCowPortal(pGame, pUnit);
}

// 0x00565A90
int __fastcall PLRTRADE_CreateUberRunPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateUberRunPortal(pGame, pUnit);
}

// 0x00565AA0
int __fastcall PLRTRADE_CreateUberFinalePortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return ACT1Q4_CreateUberFinalePortal(pGame, pUnit);
}

static inline int CubePercentage(int value,int multiplier,int divisor)
{
 if(!divisor) return 0;
 int result;
 if(value>0x100000) {
  if(divisor>(value>>4)) result=(int)((__int64)value*multiplier/divisor);
  else result=(value/divisor)*multiplier;
 } else if(multiplier>0x10000) {
  if(divisor>(multiplier>>4)) result=(int)((__int64)value*multiplier/divisor);
  else result=(multiplier/divisor)*value;
 } else result=(int)((unsigned)value*(unsigned)multiplier)/divisor;
 return result;
}

static inline unsigned RollCubeSeed(D2SeedStrc* seed)
{
 unsigned __int64 n=0x6AC690C5ui64*seed->nLowSeed+seed->nHighSeed;
 seed->nHighSeed=(unsigned)(n>>32);seed->nLowSeed=(unsigned)n;return (unsigned)n;
}

// 0x00565AB0
D2UnitStrc* __fastcall PLRTRADE_CreateCubeOutputs(D2GameStrc* game,D2UnitStrc* player,D2CubeMainTxt* recipe,D2CubeItemStrc* inputs,int unused)
{
 int nSocketables=0,bSuccess=0,bAddCraftStats=1;
 D2UnitStrc* socketables[18];
 D2UnitStrc* outputs[3]={0,0,0};
 int remove[3]={0,0,0};
 {
 for (int index=0; index<3; ++index)
 {
  D2CubeOutputItem* out=&recipe->pOutputItem[index];
  outputs[index]=0;
  if((out->wItemFlags&0x10)||(out->wItemFlags&0x20)) remove[index]=1;
  int level=0;
  if(out->nLvl) level=out->nLvl;
  else {
   if(out->nPLvl) level=CubePercentage(STATLIST_UnitGetStatValue(player,STAT_LEVEL,0),out->nPLvl,100);
   if(out->nILvl) level+=CubePercentage(inputs[index].nItemLevel,out->nILvl,100);
  }
  level=CUBE_MIN(CUBE_MAX(level,1),DATATBLS_GetMaxLevel(0));
  if(out->nType && out->nType<4) {
   CubeOutputFunc f=gpfnCubeOutputFunctions[out->nType];
   if(f) bSuccess=f(game,player);
  }
  if(out->wItemFlags&1) {
   D2UnitStrc* original=inputs[index].pItem;
   ITEMS_SetInvPage(original,255);UNITS_ChangeAnimMode(original,4);
   D2UnitStrc* item=ITEMS_Duplicate(game,original,0,remove[index]==0);
   int id=0;
   if(out->nType==254) { if(inputs[index].nClassId>=0) id=inputs[index].nClassId; }
   else if(out->nType==255) id=inputs[index].nClassId;
   else if(out->nType==252) id=out->wBaseItemId;
   else if(out->nType==253) id=PLRTRADE_RollRandomItemClassOfSameType(game,level,out->wBaseItemId);
   if(item) item->dwClassId=id;
   D2GAME_InitItemStats_6FC4E520(game,&item,0,0);outputs[index]=item;
   UNITS_ChangeAnimMode(item,4);ITEMS_SetInvPage(original,3);
  } else if(out->nType==254) {
   D2UnitStrc* original=inputs[index].pItem;
   ITEMS_SetInvPage(original,255);UNITS_ChangeAnimMode(original,4);
   D2UnitStrc* item=ITEMS_Duplicate(game,original,0,remove[index]==0);
   outputs[index]=item;UNITS_ChangeAnimMode(item,4);ITEMS_SetInvPage(original,3);
   if(out->nQuality==9) {
    unsigned short prefix=ITEMS_RollTemperedItemAffix(item,1);
    unsigned short suffix=ITEMS_RollTemperedItemAffix(item,0);
    if(prefix&&suffix) { ITEMS_SetItemQuality(item,9);ITEMS_AssignRarePrefix(item,prefix);ITEMS_AssignRareSuffix(item,suffix); }
    else bAddCraftStats=0;
   }
  } else {
   unsigned char quality=out->nQuality;
   unsigned short itemIndex=out->wItemID;
   int bCreate=0;int unique=-1,id;
   if(out->nType==255) {
    bCreate=1;
    id=inputs[index].nClassId;
    if(out->wItemFlags&0x40) {
     D2UnitStrc* item=inputs[index].pItem;
     if(item) {
      quality=(unsigned char)ITEMS_GetItemQuality(item);
      int file=ITEMS_GetFileIndex(item);itemIndex=(unsigned short)(file+1);
      level=ITEMS_GetItemLevel(item);
      if(quality==7 && !(game->dwUniqueFlags[file>>5]&gdwBitMasks[file&31])) unique=file;
     }
    }
   } else if(out->nType==252) { bCreate=1; id=out->wBaseItemId; }
   else if(out->nType==253) { bCreate=1; id=PLRTRADE_RollRandomItemClassOfSameType(game,level,out->wBaseItemId); }
   if(bCreate) {
    D2ItemDropStrc drop;memset(&drop,0,sizeof(drop));
    drop.pUnit=player;drop.wItemFormat=game->wItemFormat;drop.nId=id;drop.nQuality=quality;drop.nItemIndex=itemIndex;drop.nItemLvl=level;drop.pGame=game;
    drop.nSpawnType=4;drop.nX=0;drop.nY=0;drop.pRoom=0;drop.wUnitInitFlags=1;
    for(int i=0;3 > i;++i) drop.nPrefix[i]=out->wPrefixId[i];
    for(int i=0;3 > i;++i) drop.nSuffix[i]=out->wSuffixId[i];
    if((out->wItemFlags&2)&&!out->nQuantity) drop.dwFlags2|=16;else drop.dwFlags2|=8;
    if(out->wItemFlags&4) drop.dwFlags2|=4;else drop.dwFlags2|=2;
    outputs[index]=D2GAME_CreateItemEx_6FC4ED80(game,&drop,0);
    if(unique>=0) game->dwUniqueFlags[unique>>5]&=gdwInvBitMasks[unique&31];
   }
  }
  D2UnitStrc* current=outputs[index];
  if(current) {
  bSuccess=1;
  if(remove[index]) {
   ITEMS_DestroyRunewordStatList(game,current);
   if(out->wItemFlags&0x20) {
    D2UnitStrc* input=inputs[index].pItem;
    if(input && input->pInventory) {
     D2UnitStrc* item=INVENTORY_GetFirstItem(input->pInventory);
     while(item) {
      D2UnitStrc* next=INVENTORY_GetNextItem(item);
      D2UnitStrc* checked=INVENTORY_UnitIsItem(item);
      if(checked) {
       D2UnitStrc* copy=ITEMS_Duplicate(game,checked,0,1);
       if(copy) {ITEMS_SetInvPage(copy,255);UNITS_ChangeAnimMode(copy,4);socketables[nSocketables++]=copy;}
      }
      item=next;
     }
    }
   }
  }
  if(bAddCraftStats) for(int i=0;i<5;++i) {
   D2CubeParam* param=&out->pParam[i];
   if(param->nMod>=0 && (param->nModChance<=0 || param->nModChance>=100 || (int)(RollCubeSeed(&current->pSeed)%100)<=param->nModChance)) {
    D2PropertyStrc property;
    property.nProperty=param->nMod;property.nLayer=param->nModParam;property.nMin=param->nModMin;property.nMax=param->nModMax;
    ITEMMODS_AddCraftPropertyList(current,&property,game->bExpansion);
   }
  }
  if(out->wItemFlags&0x200) {
   if(ITEMS_CheckIfStackable(current) && out->nQuantity>0) {
    int n=ITEMS_GetTotalMaxStack(current);if(n>=out->nQuantity)n=out->nQuantity;
    STATLIST_SetUnitStat(current,STAT_QUANTITY,n,0);
   }
   if(ITEMS_CheckItemFlag(current,0x100,0x504,gszPlrTradeCpp)) D2GAME_RepairBrokenItem(game,player,current);
   else {
    int max=STATLIST_UnitGetStatValue(current,STAT_MAXDURABILITY,0);
    if(STATLIST_GetUnitBaseStat(current,STAT_DURABILITY,0)<max)STATLIST_SetUnitStat(current,STAT_DURABILITY,max,0);
   }
  }
  if(out->wItemFlags&0x400)D2GAME_RechargeItem_6FC4BD50(game,player,current);
  if(out->wItemFlags&2) {
   if(out->nQuantity && !STATLIST_UnitGetStatValue(current,STAT_ITEM_NUMSOCKETS,0) && !(ITEMS_GetItemFlags(current)&0x800)) {
    int n=ITEMS_GetMaxSockets(current);if(n>=out->nQuantity)n=out->nQuantity;
    switch(ITEMS_GetItemQuality(current)) {
     case ITEMQUAL_MAGIC:case ITEMQUAL_TEMPERED:if(n>3)n=3;break;
     case ITEMQUAL_SET:case ITEMQUAL_RARE:case ITEMQUAL_UNIQUE:case ITEMQUAL_CRAFT:if(n>1)n=1;break;
    }
    if(n>0){ITEMS_SetItemFlag(current,0x800,1);ITEMS_AddSockets(current,n);}
   }
  } else if(out->nQuantity && ITEMS_CheckIfStackable(current)) {
   int n=ITEMS_GetTotalMaxStack(current);if(n>=out->nQuantity)n=out->nQuantity;
   STATLIST_SetUnitStat(current,STAT_QUANTITY,n,0);
  }
 }
 }
 }
 if(bSuccess) {
  PLRTRADE_RemoveCubeInputs(game,player,UnitGetClient(player,gszPlrTradeCpp,0x54e));
  SUNIT_AttachSound(player,4,player);
  for(int i=0;i<3;++i) {
   D2UnitStrc* item=outputs[i];if(!item)continue;
   ITEMS_SetInvPage(item,3);
   if(!sub_00560200_PlaceItem(gszPlrTradeCpp,0x55b,game,player,!item ? -1 : item->dwUnitId,0,0,1,1,0))SUNIT_RemoveUnit(game,item);
   else {
    ITEMS_SetItemFlag(item,16,1);
    D2ItemsTxt* record=DATATBLS_GetItemsTxtRecord(!item ? -1 : item->dwClassId);
    if(record->nQuest) {
     if(record->dwCode==' tsh') ACT2Q2_UpdateHoradricItemCounts(game,player);
    else if(record->dwCode==' 2fq') ACT3Q2_UpdateKhalimItemCounts(game,player);
    }
   }
  }
  for(int i=0;i<nSocketables;++i) {
   D2UnitStrc* item=socketables[i];if(!item)continue;
   ITEMS_SetInvPage(item,3);
   if(!sub_00560200_PlaceItem(gszPlrTradeCpp,0x57c,game,player,!item ? -1 : item->dwUnitId,0,0,1,1,0))SUNIT_RemoveUnit(game,item);
   else ITEMS_SetItemFlag(item,16,1);
  }
  return outputs[0];
 }
 return 0;
}

struct D2LocalDateStrc;

struct D2LocalDateStrc
{
    int nDayOfWeek;
    int f_4;
    int nDay;
    int f_C;
};

// 0x005665B0
void __stdcall PLRTRADE_GetLocalDate(D2LocalDateStrc* pDate)
{
    D2SystemTimeStrc systemTime;
    GetLocalTime(&systemTime);
    pDate->nDayOfWeek = systemTime.wDayOfWeek + 1;
    pDate->f_4 = systemTime.wMonth;
    pDate->nDay = systemTime.wDay;
    pDate->f_C = systemTime.wYear;
}

// 0x005665F0
static void __stdcall PLRTRADE_HandleCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    const int nCubeMainTxtRecordCount = DATATBLS_GetCubemainTxtRecordCount();

    const int nItemsInCube = PLRTRADE_CountCubeItems(pUnit->pInventory);
    if (nItemsInCube <= 0)
    {
        return;
    }

    D2SystemTimeStrc systemTime;
    GetLocalTime(&systemTime);
    struct
    {
        int nDayOfWeek;
        int nDay;
        int nShifted;
        int nStatId;
    } tOp;
    tOp.nDayOfWeek = systemTime.wDayOfWeek + 1;

    for (int nId = 0; nId < nCubeMainTxtRecordCount; ++nId)
    {
        D2CubeMainTxt* pCubeMainTxtRecord = DATATBLS_GetCubemainTxtRecord(nId);
        if (!pCubeMainTxtRecord)
        {
            return;
        }

        if ((pCubeMainTxtRecord->nEnabled || gbEnableAllCubeRecipes)
            && (pGame->bExpansion || pCubeMainTxtRecord->wVersion < 100)
            && (pGame->nGameType || pGame->dwGameType || !pCubeMainTxtRecord->nLadder)
            && pCubeMainTxtRecord->nMinDiff <= pGame->nDifficulty
            && (pCubeMainTxtRecord->nClass == 0xFF || pCubeMainTxtRecord->nClass == GAME_GetUnitClassId(pUnit))
            && pCubeMainTxtRecord->nNumInputs == nItemsInCube)
        {
            int bOpConditionsFulfilled = 0;

            switch (pCubeMainTxtRecord->nOp)
            {
            case 1:
            {
                tOp.nDay = systemTime.wDay;
                if (pCubeMainTxtRecord->nParam <= tOp.nDay && pCubeMainTxtRecord->nValue >= tOp.nDay)
                {
                    bOpConditionsFulfilled = 1;
                }
                break;
            }
            case 2:
            {
                if (pCubeMainTxtRecord->nValue == tOp.nDayOfWeek)
                {
                    bOpConditionsFulfilled = 1;
                }
                break;
            }
            case 3:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_UnitGetStatValue(pUnit, tOp.nStatId, 0) >= tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 4:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_UnitGetStatValue(pUnit, tOp.nStatId, 0) <= tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 5:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_UnitGetStatValue(pUnit, tOp.nStatId, 0) != tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 6:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_UnitGetStatValue(pUnit, tOp.nStatId, 0) == tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 7:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_GetUnitBaseStat(pUnit, tOp.nStatId, 0) >= tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 8:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_GetUnitBaseStat(pUnit, tOp.nStatId, 0) <= tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 9:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_GetUnitBaseStat(pUnit, tOp.nStatId, 0) != tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 10:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (STATLIST_GetUnitBaseStat(pUnit, tOp.nStatId, 0) == tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 11:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (sub_00625560(pUnit, tOp.nStatId, 0) >= tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 12:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (sub_00625560(pUnit, tOp.nStatId, 0) <= tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 13:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (sub_00625560(pUnit, tOp.nStatId, 0) != tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            case 14:
            {
                if (pCubeMainTxtRecord->nParam < 0 || pCubeMainTxtRecord->nParam > sgptDataTables->nItemStatCostTxtRecordCount)
                {
                    bOpConditionsFulfilled = 1;
                }
                else
                {
                    D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pCubeMainTxtRecord->nParam);
                    if (pItemStatCostTxtRecord)
                    {
                        tOp.nShifted = pCubeMainTxtRecord->nValue >> pItemStatCostTxtRecord->nValShift;
                        tOp.nStatId = pCubeMainTxtRecord->nParam;
                        if (sub_00625560(pUnit, tOp.nStatId, 0) == tOp.nShifted)
                        {
                            bOpConditionsFulfilled = 1;
                        }
                    }
                }
                break;
            }
            default:
                bOpConditionsFulfilled = 1;
                break;
            }

            if (bOpConditionsFulfilled)
            {
                D2CubeItemStrc cubeItems[3] = {};
                if (PLRTRADE_CheckCubeInputs(pGame, cubeItems, pCubeMainTxtRecord, pUnit->pInventory))
                {
                    PLRTRADE_CreateCubeOutputs(pGame, pUnit, pCubeMainTxtRecord, cubeItems, 1);
                    return;
                }
            }
        }
    }
}

// 0x00566AE0
static void PLRTRADE_HandleCubeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton)
{
    switch (nButton)
    {
    case 0x17:
    {
        int nUnitType;
        int nGUID;
        if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nGUID) && nUnitType == 4)
        {
            SUNIT_ResetInteractInfo(pPlayer);
        }
        sub_6FC4B830(pGame, pPlayer);
        break;
    }
    case 0x18:
        PLRTRADE_HandleCubeInteraction(pGame, pPlayer);
        break;
    }
}

// 0x00566B30
static bool PLRTRADE_AllocPlayerTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData->hTrade)
    {
    D2PlayerTradeStrc* ptTradeRecord = (D2PlayerTradeStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2PlayerTradeStrc), ".\\PLAYER\\PlrTrade.cpp", 0x806, 0);
    ptTradeRecord->pSaveData = (unsigned char*)FOG_AllocPool(pGame->pMemoryPool, 0x2000, ".\\PLAYER\\PlrTrade.cpp", 0x807, 0);
    ptTradeRecord->nSaveLength = PLRSAVE_WriteUnitItems(pGame, pPlayer, ptTradeRecord->pSaveData, 0x2000, 0, 0, 0);
    D2_ASSERT(ptTradeRecord->nSaveLength > 0, 0x809);
    ptTradeRecord->pItemTrade = 0;
    ptTradeRecord->nGoldInTrade = 0;
    ptTradeRecord->nNextUpdateTick = 0;
    ptTradeRecord->nGoldInTradeOtherPlayer = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0);
    pPlayerData->hTrade = ptTradeRecord;
    return true;
    }

    return false;
}

// 0x00566BF0
void __fastcall PLRTRADE_Free(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2PlayerTradeStrc* pTrade = pPlayerData->hTrade;
    if (pTrade)
    {
        FOG_FreePool(pGame->pMemoryPool, pTrade->pSaveData, ".\\PLAYER\\PlrTrade.cpp", 2082, 0);

        D2ItemTradeStrc* pItemTrade = (D2ItemTradeStrc*)pTrade->pItemTrade;
        while (pItemTrade)
        {
            D2ItemTradeStrc* pNext = pItemTrade->pNext;
            FOG_FreePool(pGame->pMemoryPool, pItemTrade, ".\\PLAYER\\PlrTrade.cpp", 2087, 0);
            pItemTrade = pNext;
        }

        pTrade->pItemTrade = 0;
        FOG_FreePool(pGame->pMemoryPool, pTrade, ".\\PLAYER\\PlrTrade.cpp", 2091, 0);
        pPlayerData->hTrade = 0;
    }
}

// 0x00566D90
void __fastcall PLRTRADE_SendEventPacketToPlayer(D2UnitStrc* pPlayer, unsigned char nType, char* szSource)
{
    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nType = nType;
    packet5A.nColor = STRCOLOR_WHITE;
    packet5A.dwParam = 0;

    if (szSource)
    {
        SStrCopy(packet5A.szText, szSource, 0x7FFFFFFF);
        packet5A.szText[15] = 0;
    }
    else
    {
        packet5A.szText[0] = 0;
    }

    D2GAME_PACKETS_SendPacket0x5A_6FC3DEC0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2254), &packet5A);
}

// 0x00566E20
static int PLRTRADE_HasItemsInCube(D2UnitStrc* pPlayer)
{
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer->pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(INVENTORY_UnitIsItem(pItem)) == 3)
        {
            return 1;
        }
    }
    return 0;
}

// 0x00566E60
void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    if (PLAYER_IsBusy(pPlayer1) || ACT4Q2_HasDiabloBeenKilled(pGame))
    {
        return;
    }

    const unsigned int nTickCount = GetTickCount();

    D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pPlayer2);
    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer1);
    if (PLAYER_IsBusy(pPlayer2))
    {
        if (nTickCount - *(unsigned int*)pPlayerData1->dwLastTradeTick <= 1000)
        {
            return;
        }

        PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLAYERISBUSY, pPlayerData2->szName);
        *(unsigned int*)pPlayerData1->dwLastTradeTick = nTickCount;
        return;
    }

    if (nTickCount - pPlayerData2->dwAcceptTradeTick < 5000)
    {
        if (*(unsigned int*)pPlayerData1->dwLastTradeTick + 1000 < nTickCount)
        {
            *(unsigned int*)pPlayerData1->dwLastTradeTick = nTickCount;
            PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLEASEWAIT, pPlayerData2->szName);
        }
    }
    else
    {
        if (!pPlayerData1->dwTradeState && !pPlayerData2->dwTradeState)
        {
            if (nTickCount - pPlayerData1->dwAcceptTradeTick < 5000)
            {
                if (nTickCount > *(unsigned int*)pPlayerData1->dwLastTradeTick + 1000)
                {
                    PLRTRADE_SendEventPacketToPlayer(pPlayer1, EVENTTYPE_PLEASEWAIT, 0);
                    *(unsigned int*)pPlayerData1->dwLastTradeTick = nTickCount;
                }
                return;
            }

            if (DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer1))) && DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer2))))
            {
                SUNIT_SetInteractInfo(pPlayer1, 0, !pPlayer2 ? -1 : pPlayer2->dwUnitId);
                SUNIT_SetInteractInfo(pPlayer2, 0, !pPlayer1 ? -1 : pPlayer1->dwUnitId);

                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 2375), 0);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 2376), 1);

                pPlayerData1->dwTradeState = 1;
                pPlayerData2->dwTradeState = 2;
            }
            else
            {
                SUNIT_ResetInteractInfo(pPlayer1);
                SUNIT_ResetInteractInfo(pPlayer2);
            }
        }
    }
}

// 0x00567070
static void __stdcall PLRTRADE_CopyEarData(int bHardcore, D2UnitStrc* pItem, D2UnitStrc* pDupeItem)
{
    if (ITEMS_GetItemType(pDupeItem) == ITEMTYPE_PLAYER_BODY_PART)
    {
        ITEMS_SetEarName(pDupeItem, ITEMS_GetEarName(pItem));
        ITEMS_SetEarLevel(pDupeItem, ITEMS_GetEarLevel(pItem));
        ITEMS_SetItemFlag(pDupeItem, 0x8000, bHardcore);
    }
    else if (ITEMS_CheckItemFlag(pDupeItem, 0x1000000, 0x9AD, ".\\PLAYER\\PlrTrade.cpp"))
    {
        ITEMS_SetEarName(pDupeItem, ITEMS_GetEarName(pItem));
    }
}

// 0x00567020
static void __stdcall PLRTRADE_SetTradeAccepted(D2UnitStrc* pPlayer, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData)
{
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2422), 6);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 2423), 6);

    pPlayerData->dwTradeState = 3;
    pInteractPlayerData->dwTradeState = 3;
}

// 0x005670E0

static bool __stdcall PLRTRADE_TransferItems(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2)
{
    const int bHardcore = CLIENTS_CheckFlag(UnitGetClient(pPlayer1, szPlrTradeCpp, 0x9BB), 4);
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pPlayer1->pInventory);
    if (pItem)
    {
        do
        {
            D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
            D2UnitStrc* pNextItem = INVENTORY_GetNextItem(pItem);
            if (ITEMS_GetInvPage(pCheckedItem) == 2)
            {
                D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pCheckedItem, 0, 0);
                if (pDupeItem)
                {
                    PLRTRADE_CopyEarData(bHardcore, pCheckedItem, pDupeItem);
                    UNITS_ChangeAnimMode(pDupeItem, 4);
                    ITEMS_SetInvPage(pDupeItem, 0);
                    const int nDupeId = pDupeItem->dwUnitId;
                    if (!D2GAME_PlaceItem_6FC44410(szPlrTradeCpp, 0x9CF, pGame, pPlayer2, nDupeId, 0, 0, 1, 1, 0))
                    {
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer1, szPlrTradeCpp, 0x9D1), 0xA);
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer2, szPlrTradeCpp, 0x9D2), 9);
                        return false;
                    }

                    if (D2GAME_CheckHasFilledSockets(pCheckedItem, szPlrTradeCpp, 0x9D5) && !ITEMMODE_DuplicateSocketFillers(pGame, pPlayer2, pCheckedItem, pDupeItem, 1))
                    {
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer1, szPlrTradeCpp, 0x9D9), 0xA);
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer2, szPlrTradeCpp, 0x9DA), 9);
                        return false;
                    }
                }
            }
            pItem = pNextItem;
        } while (pItem);
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer1, szPlrTradeCpp, 0x9E4);
    pItem = INVENTORY_GetFirstItem(pPlayer1->pInventory);
    while (pItem)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        const unsigned char nInvPage = ITEMS_GetInvPage(pCheckedItem);
        int nFlags;
        if (nInvPage == 1 || nInvPage == 2)
        {
            if (nInvPage == 2)
            {
                ITEMMODE_ResetBookScrollSkillQuantity(pPlayer1, pCheckedItem);
            }
            nFlags = 0;
            ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
            ITEMS_SetItemCell(pCheckedItem, nInvPage);
            D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer1, pCheckedItem, nFlags);
            D2GAME_RemoveItem(pGame, pPlayer1, pCheckedItem, 0);
        }
        pItem = pNext;
    }
    return true;
}

// 0x005672D0
static int __stdcall PLRTRADE_CanPickUpTradeItems(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pReceiver)
{
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pOwner->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (ITEMS_GetInvPage(pCheckedItem) == 2 && !ITEMMODE_CanPickUpItem(pGame, pReceiver, pCheckedItem))
        {
            return 0;
        }
    }
    return 1;
}

// 0x005679E0
void __fastcall PLRTRADE_CancelTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2, int nTradeState)
{
    UNITS_RefreshInventory(pPlayer1, 1);
    UNITS_RefreshInventory(pPlayer2, 1);

    if (pPlayer1)
    {
        pPlayer1->dwFlagEx |= 0x800000;
    }

    if (pPlayer2)
    {
        pPlayer2->dwFlagEx |= 0x800000;
    }

    SUNIT_ResetInteractInfo(pPlayer1);
    SUNIT_ResetInteractInfo(pPlayer2);

    sub_6FC90AE0(pGame, pPlayer1, 1);
    sub_6FC90AE0(pGame, pPlayer2, 1);

    PLRTRADE_Free(pGame, pPlayer1);
    PLRTRADE_Free(pGame, pPlayer2);

    pPlayerData1->dwTradeState = nTradeState;
    pPlayerData2->dwTradeState = 9;

    sub_6FC4B830(pGame, pPlayer1);
    sub_6FC4B830(pGame, pPlayer2);

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x969), 0xC);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x96A), 0xC);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer1, 0xD, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer2, 0xD, 0);

    EVENT_SetEvent(pGame, pPlayer1, 0xD, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pPlayer2, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00567B00
static void __stdcall PLRTRADE_ResetTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, D2PlayerDataStrc* pPlayerData1, D2PlayerDataStrc* pPlayerData2)
{
    sub_6FC4B830(pGame, pPlayer1);
    sub_6FC4B830(pGame, pPlayer2);
    UNITS_RefreshInventory(pPlayer1, 1);
    UNITS_RefreshInventory(pPlayer2, 1);
    if (pPlayer1)
    {
        pPlayer1->dwFlagEx |= 0x800000;
    }
    if (pPlayer2)
    {
        pPlayer2->dwFlagEx |= 0x800000;
    }
    pPlayerData1->hTrade->nGoldInTrade = 0;
    pPlayerData2->hTrade->nGoldInTrade = 0;
    sub_6FC90AE0(pGame, pPlayer1, 1);
    sub_6FC90AE0(pGame, pPlayer2, 1);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x991), 0, 0);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x992), 0, 1);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x993), 0, 0);
    D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x994), 0, 1);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer1, ".\\PLAYER\\PlrTrade.cpp", 0x995), 6);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer2, ".\\PLAYER\\PlrTrade.cpp", 0x996), 6);
    pPlayerData1->dwTradeState = 5;
    pPlayerData2->dwTradeState = 5;
    sub_6FC4B830(pGame, pPlayer1);
    sub_6FC4B830(pGame, pPlayer2);
    EVENT_SetEvent(pGame, pPlayer1, 0xD, pGame->dwGameFrame + 1, 0, 0);
    EVENT_SetEvent(pGame, pPlayer2, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00567C70
static void __stdcall PLRTRADE_AcceptTrade(D2GameStrc* pGame, D2UnitStrc* pInteractPlayer, D2PlayerDataStrc* pPlayerData, D2PlayerDataStrc* pInteractPlayerData, D2UnitStrc* pPlayer)
{
    {
        D2PlayerTradeStrc* pTrade = pPlayerData->hTrade;
        if (pTrade->nGoldInTrade)
        {
            if (STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0) < pTrade->nGoldInTrade)
            {
                PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
                return;
            }

            if ((unsigned int)(STATLIST_UnitGetStatValue(pInteractPlayer, STAT_GOLD, 0) + pTrade->nGoldInTrade) > (unsigned int)UNITS_GetInventoryGoldLimit(pInteractPlayer))
            {
                PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA2D), 0xA);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA2E), 9);
                return;
            }
        }
    }

    {
        D2PlayerTradeStrc* pTrade = pInteractPlayerData->hTrade;
        if (pTrade->nGoldInTrade)
        {
            if (STATLIST_UnitGetStatValue(pInteractPlayer, STAT_GOLD, 0) < pTrade->nGoldInTrade)
            {
                PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
                return;
            }

            if ((unsigned int)(STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0) + pTrade->nGoldInTrade) > (unsigned int)UNITS_GetInventoryGoldLimit(pPlayer))
            {
                PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA41), 9);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA42), 0xA);
                return;
            }
        }
    }

    int nTradeState = 0;
    if (!INVENTORY_CanItemsBeTraded(pGame->pMemoryPool, pPlayer, pInteractPlayer, &nTradeState))
    {
        D2PlayerDataStrc* pFailedPartnerData = pInteractPlayerData;
        pPlayerData->hTrade->nGoldInTrade = 0;
        pFailedPartnerData->hTrade->nGoldInTrade = 0;
        if (nTradeState)
        {
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA51), 9);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA52), 0xA);
        }
        else
        {
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA56), 0xA);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA57), 9);
        }
        PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pFailedPartnerData);
        return;
    }

    if (PLRTRADE_CanPickUpTradeItems(pGame, pPlayer, pInteractPlayer) && PLRTRADE_CanPickUpTradeItems(pGame, pInteractPlayer, pPlayer))
    {
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= 0x800000;
        }
        if (pInteractPlayer)
        {
            pInteractPlayer->dwFlagEx |= 0x800000;
        }
        pPlayerData->dwTradeState = 9;
        pInteractPlayerData->dwTradeState = 9;
        EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
        EVENT_SetEvent(pGame, pInteractPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);

        if (!PLRTRADE_TransferItems(pGame, pPlayer, pInteractPlayer))
        {
            PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
            return;
        }

        if (!PLRTRADE_TransferItems(pGame, pInteractPlayer, pPlayer))
        {
            PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
            return;
        }

        {
            D2PlayerTradeStrc* pTrade = pPlayerData->hTrade;
            if (pTrade->nGoldInTrade)
            {
                if (STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0) >= pTrade->nGoldInTrade)
                {
                    PLRTRADE_AddGold(pPlayer, 0xE, -pTrade->nGoldInTrade);
                }
                ITEMS_HandleGoldTransaction(pGame, pInteractPlayer, pTrade->nGoldInTrade);
            }

            pTrade = pInteractPlayerData->hTrade;
            if (pTrade->nGoldInTrade)
            {
                if (STATLIST_UnitGetStatValue(pInteractPlayer, STAT_GOLD, 0) >= pTrade->nGoldInTrade)
                {
                    PLRTRADE_AddGold(pInteractPlayer, 0xE, -pTrade->nGoldInTrade);
                }
                ITEMS_HandleGoldTransaction(pGame, pPlayer, pTrade->nGoldInTrade);
            }

            SUNIT_ResetInteractInfo(pPlayer);
            SUNIT_ResetInteractInfo(pInteractPlayer);
            PLRTRADE_Free(pGame, pPlayer);
            PLRTRADE_Free(pGame, pInteractPlayer);
            ITEMMODE_RebuildBookScrollSkillQuantities(pGame, pPlayer);
            ITEMMODE_RebuildBookScrollSkillQuantities(pGame, pInteractPlayer);
            D2ClientStrc* const tArg13 = UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA9C);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(tArg13, 0xD);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xA9D), 0xD);
            return;
        }
    }

    PLRTRADE_ResetTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
}

// 0x00568640
void __fastcall PLRTRADE_StopAllPlayerInteractions(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    int nUnitType;
    int nUnitGUID;
    if (!SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) || nUnitType != 0)
    {
        return;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
    if (!pOtherPlayer)
    {
        return;
    }

    SUNIT_ResetInteractInfo(pPlayer);

    if (!SUNIT_GetInteractInfo(pOtherPlayer, &nUnitType, &nUnitGUID) || nUnitType != 0)
    {
        return;
    }

    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    if (nUnitGUID != nPlayerGUID)
    {
        return;
    }

    UNITS_GetPlayerData(pPlayer)->dwTradeState = 9;
    EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);

    sub_6FC90AE0(pGame, pPlayer, 0);
    sub_6FC90AE0(pGame, pOtherPlayer, 1);

    PLRTRADE_Free(pGame, pPlayer);
    PLRTRADE_Free(pGame, pOtherPlayer);

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC2F), 0xC);
    SUNIT_ResetInteractInfo(pOtherPlayer);

    UNITS_GetPlayerData(pOtherPlayer)->dwTradeState = 9;
    EVENT_SetEvent(pGame, pOtherPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00568760
void __fastcall PLRTRADE_StopInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    PLRTRADE_StopAllPlayerInteractions(pGame, pUnit);
}

// 0x00567330
void __fastcall PLRTRADE_CloseCubeInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_ResetInteractInfo(pUnit);
    sub_6FC4B830(pGame, pUnit);
}

inline int PLRTRADE_GetUnitX(D2UnitStrc* pUnit)
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

inline int PLRTRADE_GetUnitY(D2UnitStrc* pUnit)
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

// 0x005678F0
void __fastcall sPlayerRestoreInventoryCopy(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused)
{
    if (!UNITS_GetPlayerData(pUnit)->hTrade)
    {
        return;
    }

    D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pUnit, ".\\PLAYER\\PlrTrade.cpp", 0x84F), 0x92, 0, !pUnit ? -1 : pUnit->dwUnitId);
    SUNIT_IterateLivingPlayers(pGame, PLRTRADE_IterateCallback_SendInventoryReset, pUnit);

    D2UnitStrc* pNext;
    for (D2UnitStrc* pCurrent = INVENTORY_GetFirstItem(pUnit->pInventory); pCurrent; pCurrent = pNext)
    {
        D2UnitStrc* pItem = INVENTORY_UnitIsItem(pCurrent);
        pNext = INVENTORY_GetNextItem(pCurrent);
        if (pItem && pItem->dwUnitType == UNIT_ITEM)
        {
            if (pItem->dwAnimMode == IMODE_STORED)
            {
                ITEMMODE_ResetBookScrollSkillQuantity(pUnit, pItem);
            }

            INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pItem);
            ITEMS_SetItemCMDFlag(pItem, 1, 1);
        }
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pUnit->pInventory);
    if (pCursorItem && pCursorItem->dwUnitType == UNIT_ITEM)
    {
        INVENTORY_AddItemToTradeInventory(pUnit->pInventory, pCursorItem);
        ITEMS_SetItemCMDFlag(pCursorItem, 1, 1);
    }

    ITEMMODE_RemoveInventoryItemProperties(pGame, pUnit);
    PLRTRADE_RestoreTradeSnapshot(pGame, pUnit);
}

// 0x00566C80
void __fastcall PLRTRADE_IterateCallback_SendInventoryReset(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pArg)
{
    D2UnitStrc* pOtherPlayer = (D2UnitStrc*)pArg;
    if (pPlayer != pOtherPlayer)
    {
        D2GAME_PACKETS_SendPacketSize06_6FC3C850(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 2107), PACKETSIZE06_HEADER, 0, !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId);
    }
}

int __fastcall PLRSAVE_ReadItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize); // 0x005337F0

void __stdcall sub_0063BE30_Return(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

// 0x00566CC0
void __fastcall PLRTRADE_RestoreTradeSnapshot(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(pPlayerData, 0x880);

    for (int i = 1; i < 13; ++i)
    {
        sub_0063BE30_Return(pPlayer->pInventory, i);
    }

    D2PlayerTradeStrc* ptTradeRecord = pPlayerData->hTrade;
    D2_ASSERT(ptTradeRecord, 0x888);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 9, 0);

    int nUnused;
    PLRSAVE_ReadItemSection(pGame, pPlayer, ptTradeRecord->pSaveData, 0x60, 0x2000, 0, &nUnused);

    const int nGold = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0);
    const int nMode = pPlayer->dwAnimMode;
    if (nGold > 0 && nMode != 0 && nMode != 17)
    {
        PLRTRADE_AddGold(pPlayer, 14, -nGold);
        PLRTRADE_AddGold(pPlayer, 14, ptTradeRecord->nGoldInTradeOtherPlayer);
    }
}

// 0x00568060
int __fastcall PLRTRADE_HandleTradeButton(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nButton, unsigned int nGold)
{
    if (!pPlayer)
    {
        return 1;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        if (nButton >= 0x12 && nButton <= 0x14)
        {
            if (nUnitType != 2)
            {
                return 1;
            }

            PLRTRADE_HandleStashButton(pGame, nButton, pPlayer, nUnitGUID, nGold);
            return 0;
        }

        if (nButton >= 0x17 && nButton <= 0x18)
        {
            if (nUnitType != 4)
            {
                return 3;
            }

            PLRTRADE_HandleCubeButton(pGame, pPlayer, nButton);
            return 0;
        }

        if (nUnitType != 0)
        {
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB31), 0xD);
            return 3;
        }

        D2UnitStrc* pInteractPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (pInteractPlayer)
        {
            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
            D2PlayerDataStrc* pInteractPlayerData = UNITS_GetPlayerData(pInteractPlayer);
            switch (nButton)
            {
            case 2:
            {
                if (pPlayerData->dwTradeState != 2 && pPlayerData->dwTradeState != 1 || pInteractPlayerData->dwTradeState != 2 && pInteractPlayerData->dwTradeState != 1)
                {
                    if (INVMODE_IsTradeBusy(pGame, pPlayer) || INVMODE_IsTradeBusy(pGame, pInteractPlayer))
                    {
                        return 0;
                    }

                    PLRTRADE_CancelTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    const unsigned int nTickCount = GetTickCount();
                    pInteractPlayerData->dwAcceptTradeTick = nTickCount;
                    pPlayerData->dwAcceptTradeTick = nTickCount;
                }
                else
                {
                    PLRTRADE_CancelTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    const unsigned int nTickCount = GetTickCount();
                    pInteractPlayerData->dwAcceptTradeTick = nTickCount;
                    pPlayerData->dwAcceptTradeTick = nTickCount;
                }
                break;
            }
            case 3:
            {
                if (INVMODE_IsTradeBusy(pGame, pPlayer) || INVMODE_IsTradeBusy(pGame, pInteractPlayer))
                {
                    const int nTradeState = pPlayerData->dwTradeState;
                    if (nTradeState == 7)
                    {
                        pPlayerData->dwTradeState = 0xE;
                    }
                    else if (nTradeState == 8)
                    {
                        pPlayerData->dwTradeState = 0xF;
                    }
                    else
                    {
                        PLRTRADE_CancelTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 0xC);
                    }
                    return 0;
                }

                if (ACT4Q2_HasDiabloBeenKilled(pGame))
                {
                    PLRTRADE_CancelTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    return 0;
                }

                if (pPlayerData->dwTradeState != 2 || pInteractPlayerData->dwTradeState != 1)
                {
                    PLRTRADE_CancelTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 0xC);
                    return 0;
                }

                PLRTRADE_SetTradeAccepted(pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData);
                if (!PLRTRADE_AllocPlayerTrade(pGame, pPlayer))
                {
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB65), 0xC);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB66), 0xC);
                    return 0;
                }

                if (!PLRTRADE_AllocPlayerTrade(pGame, pInteractPlayer))
                {
                    PLRTRADE_Free(pGame, pPlayer);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB6D), 0xC);
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB6E), 0xC);
                    return 0;
                }

                D2GSPacketSrv78 tPacket78;
                tPacket78.nHeader = 0x78;
                memcpy(tPacket78.szName, CLIENTS_GetName(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB76)), sizeof(tPacket78.szName));
                tPacket78.szName[15] = 0;
                tPacket78.dwPlayerGUID = pInteractPlayer->dwUnitId;
                D2GAME_PACKETS_SendPacket0x63_WaypointMenu(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB79), &tPacket78);

                memcpy(tPacket78.szName, CLIENTS_GetName(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB7A)), sizeof(tPacket78.szName));
                tPacket78.szName[15] = 0;
                tPacket78.dwPlayerGUID = pPlayer->dwUnitId;
                D2GAME_PACKETS_SendPacket0x63_WaypointMenu(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xB7D), &tPacket78);
                break;
            }
            case 8:
            {
                if (nGold > (unsigned int)STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0))
                {
                    if (!INVMODE_IsTradeBusy(pGame, pPlayer) && !INVMODE_IsTradeBusy(pGame, pInteractPlayer))
                    {
                        PLRTRADE_CancelTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                    }
                }
                else
                {
                    const unsigned int nInventoryGoldLimit = UNITS_GetInventoryGoldLimit(pInteractPlayer);
                    const unsigned int nCurrentGold = STATLIST_UnitGetStatValue(pInteractPlayer, STAT_GOLD, 0);
                    if (nCurrentGold + nGold > nInventoryGoldLimit)
                    {
                        nGold = nInventoryGoldLimit - nCurrentGold;
                    }

                    D2PlayerTradeStrc* pTrade = pPlayerData->hTrade;
                    if (pTrade)
                    {
                        pTrade->nGoldInTrade = nGold;
                        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBC3), nGold, 0);
                        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBC4), nGold, 1);
                    }
                }
                break;
            }
            case 4:
            {
                if (!INVMODE_IsTradeBusy(pGame, pPlayer) && !INVMODE_IsTradeBusy(pGame, pInteractPlayer))
                {
                    if (ACT4Q2_HasDiabloBeenKilled(pGame))
                    {
                        PLRTRADE_CancelTrade(pGame, pPlayer, pInteractPlayer, pPlayerData, pInteractPlayerData, 9);
                        return 0;
                    }

                    if (pPlayerData->dwTradeState != 3)
                    {
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBD2), 6);
                        return 0;
                    }

                    if (INVENTORY_GetCursorItem(pPlayer->pInventory))
                    {
                        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBD7), 6);
                        return 0;
                    }

                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBDC), 5);
                    if (pPlayerData->dwTradeState != 3)
                    {
                        return 0;
                    }

                    pPlayerData->dwTradeState = 4;
                    if (pInteractPlayerData->dwTradeState != 4)
                    {
                        return 0;
                    }

                    PLRTRADE_AcceptTrade(pGame, pInteractPlayer, pPlayerData, pInteractPlayerData, pPlayer);
                    const unsigned int nTickCount = GetTickCount();
                    pInteractPlayerData->dwAcceptTradeTick = nTickCount;
                    pPlayerData->dwAcceptTradeTick = nTickCount;
                }
                else
                {
                    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBEE), 6);
                }
                break;
            }
            case 7:
            {
                if (pPlayerData->dwTradeState == 4)
                {
                    pPlayerData->dwTradeState = 3;
                }
                if (pInteractPlayerData->dwTradeState == 4)
                {
                    pInteractPlayerData->dwTradeState = 3;
                }
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBFD), 6);
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pInteractPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xBFE), 6);
                break;
            }
            default:
                break;
            }
        }
        else
        {
            if (!INVMODE_IsTradeBusy(pGame, pPlayer))
            {
                D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC06), 0xC);
            }
        }
        return 0;
    }

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC0C), 0xC);
    return 0;
}

// 0x00567350
static void __stdcall PLRTRADE_AddItemTrade(D2GameStrc* pGame, int nItemGUID1, int nItemGUID2, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2PlayerTradeStrc* pTrade = pPlayerData->hTrade;
        if (pTrade)
        {
            D2ItemTradeStrc* pItemTrade = (D2ItemTradeStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2ItemTradeStrc), ".\\PLAYER\\PlrTrade.cpp", 0xC5B, 0);
            pItemTrade->nItemGUID1 = nItemGUID1;
            pItemTrade->nItemGUID2 = nItemGUID2;
            pItemTrade->pNext = (D2ItemTradeStrc*)pTrade->pItemTrade;
            pTrade->pItemTrade = pItemTrade;
        }
    }
}

// 0x005673A0
static void PLRTRADE_WalkItemTrade(D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData && pPlayerData->hTrade)
    {
        for (D2ItemTradeStrc* pItemTrade = (D2ItemTradeStrc*)pPlayerData->hTrade->pItemTrade; pItemTrade; pItemTrade = pItemTrade->pNext)
        {
        }
    }
}

// 0x005673C0
static char __stdcall PLRTRADE_FindItemTrade(int* pItemGUID2, int nItemGUID1, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData && pPlayerData->hTrade)
    {
        for (D2ItemTradeStrc* pItemTrade = (D2ItemTradeStrc*)pPlayerData->hTrade->pItemTrade; pItemTrade; pItemTrade = pItemTrade->pNext)
        {
            if (pItemTrade->nItemGUID1 == nItemGUID1)
            {
                *pItemGUID2 = pItemTrade->nItemGUID2;
                return 1;
            }
        }
    }

    return 0;
}

// 0x00568770
void __fastcall PLRTRADE_AddItemToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xC99), 0xC);
        return;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
    if (!pOtherPlayer)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCA1), 0xC);
        return;
    }

    D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pItem, 0, 0);
    const int nX = PLRTRADE_GetUnitX(pItem);
    const int nY = PLRTRADE_GetUnitY(pItem);
    UNITS_ChangeAnimMode(pDupeItem, 4);
    ITEMS_SetInvPage(pDupeItem, 1);

    if (!D2GAME_PlaceItem_6FC44410(".\\PLAYER\\PlrTrade.cpp", 0xCAD, pGame, pOtherPlayer, !pDupeItem ? -1 : pDupeItem->dwUnitId, nX, nY, 0, 1, 0))
    {
        ITEMS_RemoveFromAllPlayers(pGame, pDupeItem);
        D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
        D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
        PLRTRADE_CancelTrade(pGame, pPlayer, pOtherPlayer, pPlayerData1, pPlayerData2, 9);
        return;
    }

    if (D2GAME_CheckHasFilledSockets(pItem, ".\\PLAYER\\PlrTrade.cpp", 0xCB9))
    {
        ITEMMODE_DuplicateSocketFillers(pGame, pOtherPlayer, pItem, pDupeItem, 1);
    }

    const int nDupeItemGUID = !pDupeItem ? -1 : pDupeItem->dwUnitId;
    const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
    PLRTRADE_AddItemTrade(pGame, nItemGUID, nDupeItemGUID, pPlayer);

    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
    D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
    if (pPlayerData1->dwTradeState == 4 || pPlayerData2->dwTradeState == 4)
    {
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCC7), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCC8), 0, 1);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCC9), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCCA), 0, 1);
        PLRTRADE_SetTradeAccepted(pPlayer, pOtherPlayer, pPlayerData1, pPlayerData2);
    }
}

// 0x005689D0
void __fastcall PlayerTradeUpdate(D2GameStrc* game,D2UnitStrc* player,int unused1,int unused2)
{
    D2PlayerDataStrc* data=UNITS_GetPlayerData(player);
    if (data->dwTradeState<=4) return;
    if (data->dwTradeState==7) {
        data->dwTradeState=8;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    }
    if (data->dwTradeState==14) {
        data->dwTradeState=15;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    }
    D2PlayerTradeStrc* trade=data->hTrade;
    if (data->dwTradeState==8) {
        if (player) player->dwFlagEx &= ~0x00400000u;
        if (trade->nNextUpdateTick) {
            data->dwTradeState=11;
            EVENT_SetEvent(game,player,0xD,game->dwGameFrame+125,0,0);
        } else {
            data->dwTradeState=3;
        }
        return;
    }
    if (data->dwTradeState==15) {
        if (player) player->dwFlagEx &= ~0x00400000u;
        data->dwTradeState=16;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+5,0,0);
        return;
    }
    if (data->dwTradeState==16) {
        int type,id;
        if (SUNIT_GetInteractInfo(player,&type,&id) && type==0) {
            D2UnitStrc* other=SUNIT_GetServerUnit(game,0,id);
            if (other) {
                D2PlayerDataStrc* first=UNITS_GetPlayerData(player);
                D2PlayerDataStrc* second=UNITS_GetPlayerData(other);
                if ((first->dwTradeState==2 || first->dwTradeState==1)
                    && (second->dwTradeState==2 || second->dwTradeState==1)) {
                    PLRTRADE_CancelTrade(game,player,other,first,second,12);
                    const unsigned int tick=GetTickCount();
                    second->dwAcceptTradeTick=tick;
                    first->dwAcceptTradeTick=tick;
                    return;
                } else if (!INVMODE_IsTradeBusy(game,player) && !INVMODE_IsTradeBusy(game,other)) {
                    PLRTRADE_CancelTrade(game,player,other,first,second,12);
                    const unsigned int tick=GetTickCount();
                    second->dwAcceptTradeTick=tick;
                    first->dwAcceptTradeTick=tick;
                    return;
                }
            }
        }
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+5,0,0);
        return;
    }
    switch (data->dwTradeState) {
    case 11:
        if (trade->nNextUpdateTick < GetTickCount()) {
            data->dwTradeState=3;
            if (player) player->dwFlagEx &= ~0x00C00000u;
            trade->nNextUpdateTick=0;
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(player,".\\PLAYER\\PlrTrade.cpp",0xE95),15);
            return;
        }
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+25,0,0);
        return;
    case 9:
        data->dwTradeState=10;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    case 5:
        data->dwTradeState=6;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+1,0,0);
        return;
    case 6:
        data->dwTradeState=3;
        if (player) player->dwFlagEx &= ~0x00C00000u;
        return;
    case 12:
        data->dwTradeState=13;
        EVENT_SetEvent(game,player,0xD,game->dwGameFrame+4,0,0);
        return;
    case 10:
    case 13:
        data->dwTradeState=0;
        if (player) player->dwFlagEx &= ~0x00C00000u;
        return;
    }
}

// 0x00568D10
void __fastcall PLRTRADE_RefreshTradeSnapshot(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    PLRTRADE_AllocPlayerTrade(pGame, pPlayer);
    UNITS_RefreshInventory(pPlayer, 1);
    sub_6FC90AE0(pGame, pPlayer, 1);
    PLRTRADE_Free(pGame, pPlayer);
    sub_6FC4B830(pGame, pPlayer);
    EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
}

// 0x00568D70
int __cdecl AITACTICS_GetHighestClassSkillCount()
{
    return sgptDataTables->nHighestClassSkillCount;
}

// 0x00568D80
int __fastcall PLRTRADE_FindTerminator(const char* szText, int nSize)
{
    const char* pStart = szText;
    const char* pEnd = szText + nSize;
    while (szText < pEnd && *szText)
    {
        ++szText;
    }

    if (szText >= pEnd)
    {
        return -1;
    }

    return szText - pStart;
}

// 0x00567400
void __fastcall PLRTRADE_RemoveItemFromTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    int nUnitGUID;
    int nUnitType;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID) && nUnitType)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCDC), 0xC);
        return;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
    if (!pOtherPlayer)
    {
        D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCE4), 0xC);
        return;
    }

    const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
    if (PLRTRADE_FindItemTrade(&nUnitGUID, nItemGUID, pPlayer))
    {
        int nUnused;
        if (ITEMMODE_RemoveStoredItem(pGame, pOtherPlayer, nUnitGUID, &nUnused, 1, 1, 0, 1))
        {
            PLRTRADE_WalkItemTrade(pPlayer);
        }
    }

    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
    D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
    D2PlayerTradeStrc* pTrade1 = pPlayerData1->hTrade;
    D2PlayerTradeStrc* pTrade2 = pPlayerData2->hTrade;
    const unsigned int nTickCount = GetTickCount() + 10000;
    pTrade1->nNextUpdateTick = nTickCount;
    pTrade2->nNextUpdateTick = nTickCount;

    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCF9), 0xE);
    D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCFA), 0xE);

    if (pPlayerData1->dwTradeState == 4 || pPlayerData2->dwTradeState == 4)
    {
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xCFF), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD00), 0, 1);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD01), 0, 0);
        D2GAME_PACKETS_SendPacket0x79_6FC3E1D0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD02), 0, 1);
        PLRTRADE_SetTradeAccepted(pPlayer, pOtherPlayer, pPlayerData1, pPlayerData2);
    }
}

// 0x005675E0
int __fastcall PLRTRADE_CopyTradeSaveDataToBuffer(D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize)
{
    D2PlayerTradeStrc* pTrade = UNITS_GetPlayerData(pUnit)->hTrade;
    if (!pTrade)
    {
        return 0;
    }

    if (nBufferSize < pTrade->nSaveLength)
    {
        return 0;
    }

    memcpy(pBuffer, pTrade->pSaveData, pTrade->nSaveLength);
    return pTrade->nSaveLength;
}

// 0x00567620
int __fastcall PLRTRADE_PrepareItemChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2PlayerDataStrc* pPlayerData1 = UNITS_GetPlayerData(pPlayer);
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pPlayer, &nUnitType, &nUnitGUID))
    {
        if (nUnitType != 0)
        {
            return 1;
        }
        D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (pOtherPlayer)
        {
            D2PlayerDataStrc* pPlayerData2 = UNITS_GetPlayerData(pOtherPlayer);
            if (!pPlayerData2->hTrade)
            {
                return 0;
            }
            if (ACT4Q2_HasDiabloBeenKilled(pGame))
            {
                return 0;
            }
            if (sub_00463720_TestUnitFlagEx(pPlayer, 0x800000) || sub_00463720_TestUnitFlagEx(pOtherPlayer, 0x800000))
            {
                return 0;
            }
            D2_ASSERT(pPlayerData1->hTrade, 0xD3C);
            int nResult = 1;
            if (pPlayerData1->dwTradeState == 4)
            {
                nResult = 0;
            }
            if (pItem && pItem->dwUnitType == UNIT_ITEM)
            {
                int nClassId = pItem->dwClassId;
                D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
                if (pItemsTxtRecord->nQuest)
                {
                    if (pItemsTxtRecord->dwCode == 0x20786F62)
                    {
                        if (PLRTRADE_HasItemsInCube(pPlayer))
                        {
                            nResult = 0;
                            PLRTRADE_SendEventPacketToPlayer(pPlayer, 0xA, 0);
                        }
                    }
                    if (ITEMS_FindQuestItem(pGame, pOtherPlayer, pItemsTxtRecord->dwCode))
                    {
                        nResult = 0;
                    }
                }
                else
                {
                    if (ITEMS_CheckItemFlag(pItem, 0x1000, 0xD58, ".\\PLAYER\\PlrTrade.cpp"))
                    {
                        nResult = 0;
                    }
                    else
                    {
                        ITEMS_GetItemQuality(pItem);
                    }
                }
            }
            if (pPlayer)
            {
                pPlayer->dwFlagEx |= 0x400000;
            }
            pPlayerData1->dwTradeState = 7;
            pPlayerData2->dwTradeState = 7;
            EVENT_SetEvent(pGame, pPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pGame, pOtherPlayer, 0xD, pGame->dwGameFrame + 1, 0, 0);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD6E), 6);
            D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(UnitGetClient(pOtherPlayer, ".\\PLAYER\\PlrTrade.cpp", 0xD6F), 6);
            return nResult;
        }
    }
    return pPlayerData1->dwTradeState <= 4;
}

// 0x00567840
int __fastcall PLRTRADE_IsTradeInventoryEmpty(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (!SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) || nUnitType != UNIT_PLAYER)
    {
        return 1;
    }

    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        if (INVENTORY_GetItemNodePage(pItem) == INVPAGE_TRADE)
        {
            return 0;
        }
    }

    return 1;
}

// 0x005678A0
int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    int nUnitType;
    int nUnitGUID;

    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && nUnitType == UNIT_PLAYER && SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID))
    {
        return 1;
    }

    return 0;
}

#include "gen/data/Source/D2Game/PLAYER/PlrTrade.inc"
