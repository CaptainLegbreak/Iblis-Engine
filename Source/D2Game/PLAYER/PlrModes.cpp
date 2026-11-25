#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2Txt.h"
#include "D2PlayerModes.h"
#include "D2ItemModes.h"
#include "D2SkillIds.h"
#include "D2LanguageNames.h"

#define EVENTTYPE_ENDANIM 1

#define STAT_HITPOINTS 6

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define STAT_DEXTERITY 2

#define STAT_LEVEL 12

#define STAT_ATTACKRATE 68

#define IFLAG_BROKEN 0x100

#define UNITFLAG_DOUPDATE 0x00000001

#define UNITFLAGEX_TELEPORTED 0x00010000

#define UNITFLAG_HASTXTMSG 0x00000100

struct D2CorpseStrc;

struct D2PlayerDataStrc;

struct D2SkillsTxt;

struct D2PlayerModeChartStrc;

struct D2UnkPlrModeStrc2;

struct D2CharStatsTxt;

struct D2ClientStrc;

struct D2InventoryStrc;

struct D2ActiveRoomStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2CoordStrc;

union D2SeedStrc;

struct D2CorpsePositionStrc;

struct D2ItemsTxt;

typedef void(__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCustomId, int nCustomParam);

extern const EventCallbackFunction gpfnPlayerEventCallbacks[15]; // 0x006E1810

int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent); // 0x005415A0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef void (__fastcall* PLRMODESTARTXY)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY);

typedef void (__fastcall* PLRMODESTARTID)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, D2UnitStrc* pTarget);

struct D2PlayerModeChartStrc
{
    PLRMODESTARTXY pfnStartXY;
    PLRMODESTARTID pfnStartID;
};

extern D2PlayerModeChartStrc gaPlayerModeChart[]; // 0x006E1740

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __fastcall PLRMODE_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057ED70

int __fastcall PLRMODE_CanInterruptCurrentMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int a4, D2SkillStrc* pSkill); // 0x0057EEC0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __cdecl LOG_11100(int nA, int nB, int nC, int nFlags, const char* szFile, int nLine, const char* szFormat, ...); // 0x006248E0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

void __fastcall PLRMODE_HandleDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580310

void __fastcall PLRMODE_BreakDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00580380

void __fastcall PLRMODE_StartXY_Dead(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY); // 0x0057FCA0

void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY); // 0x0057F020

int __stdcall D2COMMON_11079_Return0(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0062A360

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

void __fastcall sub_6FC45930(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x005608C0

void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

void __stdcall ITEMS_SetItemCMDFlag(D2UnitStrc* pItem, int nFlag, int bSet); // 0x00628170

void __stdcall INVENTORY_AddItemToTradeInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063CC70

void __fastcall sub_0055D930(D2UnitStrc* pUnit, D2UnitStrc* pItem, int nUnused); // 0x0055D930

int __stdcall ITEMS_UpdateSets(D2UnitStrc* pUnit, D2UnitStrc* pItem, int a3, int a4); // 0x00663CC0

void __stdcall UNITS_RefreshInventory(D2UnitStrc* pUnit, int bSetFlag); // 0x00621000

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x42_6FC3EE40(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D2E0

void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

D2UnitStrc* __fastcall ITEMS_Duplicate(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pUnit, int bAddToGame); // 0x0055A2A0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

unsigned int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __fastcall PLAYER_DropGold(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, int nValue); // 0x00535510

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc* pInventory); // 0x0063D570

D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc* pCorpse); // 0x0063D610

int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc* pCorpse); // 0x0063D630

int __stdcall INVENTORY_FreeCorpse(D2InventoryStrc* pInventory, unsigned int nUnitId, unsigned int a3); // 0x0063D4E0

int __stdcall INVENTORY_GetOwnerId(D2InventoryStrc* pInventory); // 0x0063D450

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __fastcall SUNITDMG_AddExperience(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nExperience); // 0x0057EAB0

int __fastcall ITEMMODE_RecoverCorpseItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody); // 0x00562F30

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

struct D2UnkPlrModeStrc2
{
    int nRightSkillId;
    int nLeftSkillId;
    int nRightSkillOwnerGUID;
    int nLeftSkillOwnerGUID;
};

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50

int __fastcall ITEMMODE_FindFreeBodyLocation(D2UnitStrc* pPlayer, D2UnitStrc* pItem, int* pBodyLoc, int a4); // 0x0055D710

void __stdcall UNITS_SetWeaponGUID(D2UnitStrc* pUnit, D2UnitStrc* hWeapon); // 0x006233A0

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __fastcall ITEMMODE_BreakItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0055F850

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* a5); // 0x00560CD0

D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pPreviousItem); // 0x0063CD80

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc* pUnit, int a2, int nSkillId, int nFlags); // 0x005701B0

static void __stdcall sRestoreWeapon(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pWeapon); // 0x00580030

typedef void(__fastcall* STATLIST_UpdateFn)(D2UnitStrc* pUnit, int nValue, int nStatId, D2UnitStrc* pOther);

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

void __fastcall D2GAME_SendPacket0x47_6FC3EEE0(D2ClientStrc* pClient, D2UnitStrc* pPlayer); // 0x0053D370

void __fastcall D2GAME_SendPacket0x48_6FC3EF40(D2ClientStrc* pClient, D2UnitStrc* pPlayer, int a3); // 0x0053D3C0

void __fastcall PLRMSG_SendKnockbackStatus(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00547F70

void __fastcall PLRMSG_SendUnitMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005484B0

void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, int nValue, int nStatId, D2UnitStrc* pOther); // 0x00548520

void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer); // 0x00571580

void __fastcall SUNITMSG_SendOverlay(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005715A0

void __fastcall SUNITMSG_SendHoverText(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620

void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740

void __fastcall SUNITMSG_SendQueuedMessages(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0

void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg); // 0x00597890

void __stdcall D2Common_10512(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int nStatId, STATLIST_UpdateFn pfCallback); // 0x00625870

int __stdcall ITEMS_HasDurability(D2UnitStrc* pItem); // 0x00629930

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent); // 0x00571A10

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

static int EVENTS_HpRegen(D2UnitStrc* pUnit); // 0x00580610

static void EVENTS_StaminaRegen(D2UnitStrc* pUnit); // 0x00580500

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

void __fastcall PARTY_SynchronizeWithClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005406A0

void __fastcall PLAYERPETS_UpdatePetStates(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575630

static void __stdcall PLRMODE_DropItemsOnCorpseOverflow(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern "C" const char gszPlrModesSourceFile[]; // 0x006E17E0

unsigned int __stdcall INVENTORY_GetCorpseCount(D2InventoryStrc*); // 0x0063D5F0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*,int,int); // 0x00463740

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int,int,int,int,D2GameStrc*,D2ActiveRoomStrc*,char,int,unsigned int); // 0x00555230

void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc*,D2ClientStrc*); // 0x00553180

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830

unsigned int __stdcall UNITS_SetNameInPlayerData(D2UnitStrc* ptUnit, char* szName); // 0x006220F0

void __fastcall SUNIT_InitSeed(D2UnitStrc* ptUnit, D2SeedStrc* pSeed); // 0x00552DF0

void __stdcall STATES_ToggleState(D2UnitStrc*,int,int); // 0x00639DB0

int __fastcall CLIENTS_GetExperienceLoss(D2ClientStrc*); // 0x00539210

void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc*,int); // 0x005391E0

void __stdcall INVENTORY_SetOwnerId(D2InventoryStrc*,int); // 0x0063D430

void __stdcall ITEMS_SetInvPage(D2UnitStrc*,unsigned char); // 0x00628280

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* hUnit, int nInvPage, int bLoD); // 0x00621050

int __stdcall INVENTORY_PlaceItemAtFreePosition(D2InventoryStrc*,D2UnitStrc*,int,int,unsigned char,const char*,int); // 0x0063B950

int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc*,D2UnitStrc*,int); // 0x0063B210

void __fastcall QUESTS_ItemPickedUp(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x00543D80

int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc*,D2UnitStrc*,int); // 0x0063BDB0

void __stdcall ITEMS_SetBodyLocation(D2UnitStrc*,unsigned char); // 0x00627D70

void __fastcall SUNITDMG_DropCorpseGold(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int); // 0x0057F390

void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(D2GameStrc*,int,int,int); // 0x0053DF80

struct D2CorpsePositionStrc { D2CoordStrc coords; D2ActiveRoomStrc* room; };

static int __stdcall PLRMODE_FreeStaleCorpses(D2GameStrc* pGame, D2UnitStrc* pUnit);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

extern const unsigned char gbMask_006CE284; // 0x006CE284

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __fastcall sub_0057F240_EmitWalk(D2UnitStrc* pPlayer);

static int PLRMODE_DrainRunStamina(D2UnitStrc* pPlayer);

static void __stdcall PLRMODE_RestoreWeapon(D2GameStrc* pGame, unsigned char nBodyLoc, D2UnitStrc* pPlayer); // 0x0057FF70

struct D2ServerCallbackFunctions;

struct D2StaticPathStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __fastcall PLRMSG_InteractWithUnit(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00

void __fastcall SUNIT_ValidateTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553490

void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode); // 0x00553570

void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553990

int __fastcall SUNIT_UpdateUnitPath(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554CA0

void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70

void __fastcall SKILLS_CreateBlazeMissile(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C9D90

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall SKILLS_GetSkillModeFromUnit(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00643860

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

extern "C" void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTarget); // 0x00648B90

extern D2ServerCallbackFunctions* gpD2EventCallbackTable; // 0x00883D50

void __fastcall D2GAME_SetClientDead_6FC33830(D2ClientStrc* ptClient, const int* pDeathInfo); // 0x00538260

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

D2UnitStrc* __fastcall PLRMODE_CreateDeadBody(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2ActiveRoomStrc* pRoom); // 0x0057F700

void __fastcall D2GAME_KillPlayerPets(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00575BC0

void __fastcall CLIENTS_ToggleFlag(D2ClientStrc* pClient, unsigned short nFlag, int bSet); // 0x00538650

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag); // 0x00538670

int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400

void __fastcall PLAYER_ApplyDeathPenalty(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pAttacker); // 0x00535AB0

void __fastcall ITEMS_DropPlayerEar(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055A200

void __fastcall D2GAME_PLRMSG_Last_6FC89450(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0054D8A0

void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0053F720

void __fastcall PLAYER_CloseInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005350F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                        // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);         // 0x00625500

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, unsigned short nLayer);                // 0x00627260

static void __stdcall PLRMODE_StartMovement(D2GameStrc*, D2UnitStrc*, int); // 0x0057F090

void __fastcall PLRMODE_StartID_WalkRunKnockback(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* pTargetUnit);

void __fastcall PLRMODE_StartXY_WalkRunKnockback(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY);

int __fastcall PLRMODE_UpdateMovement(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nEventCustomId, int nEventCustomParam);

// 0x0057ED70
int __fastcall PLRMODE_IsEndAnimDue(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return pGame->dwGameFrame <= EVENT_GetEventFrame(pGame, pUnit, EVENTTYPE_ENDANIM) + 5;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x0057ED90
static int PLRMODE_CanEndSequence(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxtRecord && pSkillsTxtRecord->nSeqInput > 0)
        {
            return 1;
        }
    }

    return pGame->dwGameFrame <= EVENT_GetEventFrame(pGame, pUnit, 1) + 0x05;
}

// 0x0057EDD0
static int PLRMODE_CanStartMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode)
{
    if (pUnit->pInventory && INVENTORY_GetCursorItem(pUnit->pInventory) && nMode != 0 && nMode != 17)
    {
        return 0;
    }

    switch (nMode)
    {
    case 0:
    case 1:
    case 5:
    case 17:
        return 1;

    default:
        break;
    }

    switch (pUnit->dwAnimMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
        if (PLRMODE_IsEndAnimDue(pGame, pUnit) || nMode == 4 || nMode == 9)
        {
            return 1;
        }
        return 0;

    case 0:
    case 4:
    case 9:
    case 17:
        return 0;

    case 12:
        return PLRMODE_IsEndAnimDue(pGame, pUnit) ? 1 : 0;

    case 13:
        if (pUnit->dwClassId == 0)
        {
            return 0;
        }
        break;

    case 15:
        if (pUnit->dwClassId == 5)
        {
            return 0;
        }
        break;

    case 18:
        return PLRMODE_CanEndSequence(pGame, pUnit);

    default:
        break;
    }

    return 1;
}

static inline int sub_GetConcStat(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONCENTRATION);
    return STATLIST_GetStatValue(pStatList, STAT_SKILL_CONCENTRATION, 0);
}

static inline int sub_GetAnimMode(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->dwAnimMode;
}

// 0x0057EEC0
int __fastcall PLRMODE_CanInterruptCurrentMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int bCheckUsedSkill, D2SkillStrc* pSkill)
{
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 17)
    {
        return 0;
    }

    if (nMode == 0 || !bCheckUsedSkill)
    {
        return 1;
    }

    D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
    if (!pUsedSkill)
    {
        return 1;
    }

    const int nUsedSkillId = SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\PLAYER\\PlrModes.cpp", 185);

    D2SkillsTxt* pUsedSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nUsedSkillId);
    if (!pUsedSkillsTxtRecord)
    {
        return 1;
    }

    if (pSkill == pUsedSkill && (pUsedSkillsTxtRecord->wSrvDoFunc == 67 || pUsedSkillsTxtRecord->wSrvDoFunc == 76))
    {
        return 1;
    }

    if (pUsedSkillsTxtRecord->nFlags[3] & gbMask_006CE284)
    {
        if ((STATES_CheckState(pUnit, STATE_CONCENTRATION)
            && (int)(SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100)) < sub_GetConcStat(pUnit))
            || STATES_CheckState(pUnit, STATE_CONCENTRATE))
        {
            if (sub_GetAnimMode(pUnit) == 1)
            {
                PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, 1, 0, 0, 1);
                return 1;
            }

            return 0;
        }

        return 1;
    }

    if (sub_GetAnimMode(pUnit) == 1)
    {
        PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, 1, 0, 0, 1);
        return 1;
    }

    switch (nMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
    case 13:
    case 18:
        if (PLRMODE_IsEndAnimDue(pGame, pUnit) != 0)
        {
            return 1;
        }
        break;

    default:
        break;
    }

    return 0;
}

// 0x0057F020
void __fastcall PLRMODE_StartXY_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        nMode = DUNGEON_IsRoomInTown(pRoom) != 0 ? PLRMODE_TOWNNEUTRAL : PLRMODE_NEUTRAL;
    }

    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    UNITS_SetUsedSkill(pPlayer, 0);
}

// 0x0057F070
int __fastcall PLRMODE_ModeCheck_Death(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

// 0x0057F080
int __fastcall PLRMODE_ModeCheck_Neutral(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

static inline int sub_F05_PlrGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_PlrGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_GetInteractAction(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == UNIT_PLAYER ? pPlayer->pPlayerData->nMode : 0;
}

static inline int sub_F05_GetInteractUnitType(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData ? pPlayer->pPlayerData->nArg1 : 0;
}

static inline int sub_F05_GetInteractUnitGUID(D2UnitStrc* pPlayer)
{
    return pPlayer->dwUnitType == UNIT_PLAYER ? (pPlayer->pPlayerData ? pPlayer->pPlayerData->nArg2 : 0) : 0;
}

static inline int sub_F05_IsInteracting(D2UnitStrc* pPlayer)
{
    if (pPlayer)
    {
        switch (pPlayer->dwUnitType)
        {
        case UNIT_PLAYER:
            if (pPlayer->pPlayerData)
            {
                return pPlayer->pPlayerData->nState;
            }
            break;
        case UNIT_MONSTER:
        case UNIT_OBJECT:
        case UNIT_MISSILE:
        case UNIT_ITEM:
        case UNIT_TILE:
            return 0;
        }
    }

    return 0;
}

static inline void sub_F05_SetInteractFlag(D2UnitStrc* pPlayer, int nFlag)
{
    if (pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
    {
        pPlayer->pPlayerData->nState = nFlag;
    }
}

static inline D2CharStatsTxt* sub_F05_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x0057F090
static void __stdcall PLRMODE_StartMovement(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nMode)
{
    D2_ASSERT(ptGame, 0x138);

    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    PATH_ResetToPreviousType(pPath);

    switch (nMode)
    {
    case 3:
        if (STATLIST_UnitGetStatValue(pPlayer, STAT_STAMINA, 0))
        {
            break;
        }
    case 2:
    case 6:
        nMode = DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)) != 0 ? 6 : 2;
        break;

    case 19:
        PATH_SetType(pPath, 8);
        D2COMMON_10190_PATH_SetDistance(pPath, 5);
        break;
    }

    D2Common_10142(pPath, pPlayer, 0);
    UNITS_SetUsedSkill(pPlayer, 0);

    if (!PATH_GetNumberOfPathPoints(pPath))
    {
        PLRMODE_StartXY_Neutral(ptGame, pPlayer, 1, 0, 0);
    }
    else
    {
        SUNIT_SetCombatMode(ptGame, pPlayer, nMode);
        D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(ptGame, pPlayer);
        SUNIT_ResetRecurringModeChangeEvent(ptGame, pPlayer);
    }
}

// 0x0057F1F0
void __fastcall PLRMODE_StartXY_WalkRunKnockback(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(ptGame, 0x17C);

    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    PLRMODE_StartMovement(ptGame, pPlayer, nMode);
}

// 0x0057F330
static void PLRMODE_FinalizeDeath(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, 0, 0);
    D2Common_10469(pPlayer);
    STATES_UpdateStayDeathFlags(pPlayer, 0);
    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrModes.cpp", 0x234);
    D2GAME_SetClientDead_6FC33830(pClient, 0);
    PATH_SetUnitDeadCollision(pPlayer, 1);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 0x08, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPlayer, 0x09, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
}

#define GOLD_PILE_COUNT 32

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

void __fastcall ITEMS_DropGoldPiles(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int nAmount, D2UnitStrc** ppGold, int* pCount, int nMaxCount); // 0x0055A090

void __stdcall ITEMS_SetOwnerId(D2UnitStrc* pItem, int nOwnerGUID); // 0x00629ED0

// 0x0057F390
void __fastcall SUNITDMG_DropCorpseGold(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody, int nGold, int nUnused)
{
    if (nGold > 0)
    {
        D2UnitStrc* pGoldPiles[GOLD_PILE_COUNT];
        int nCount = 0;
        ITEMS_DropGoldPiles(pGame, pDeadBody, nGold, pGoldPiles, &nCount, GOLD_PILE_COUNT);

        for (int i = 0; i < nCount; ++i)
        {
            D2UnitStrc* pGold = pGoldPiles[i];
            D2_ASSERT(ITEMS_GetItemType(pGold) == ITEMTYPE_GOLD, 588);
            ITEMS_SetOwnerId(pGold, GAME_GetUnitGUID(pPlayer));
        }
    }
}

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x0057F240
static int PLRMODE_DrainRunStamina(D2UnitStrc* pPlayer)
{
    if (!pPlayer)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pPlayer)))
    {
        return 1;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nStaminaLost = 2 * pCharStatsTxtRecord->nRunDrain;
    if (!pPlayer->pInventory)
    {
        return 0;
    }

    D2UnitStrc* pTorsoArmor = INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, 3);
    if (pTorsoArmor)
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pTorsoArmor ? -1 : pTorsoArmor->dwClassId);
        if (pItemsTxtRecord)
        {
            int nSpeed = pItemsTxtRecord->dwSpeed;
            nSpeed = nSpeed / 10 + 1;
            nStaminaLost *= nSpeed;
        }
    }

    const int nStaminaDrainPct = STATLIST_UnitGetItemStatOrSkillStatValue(pPlayer, STAT_ITEM_STAMINADRAINPCT, 0);
    if (nStaminaDrainPct)
    {
        nStaminaLost += nStaminaLost * nStaminaDrainPct / -100;
    }

    if (nStaminaLost < 1)
    {
        nStaminaLost = 1;
    }

    STATLIST_AddUnitStat(pPlayer, STAT_STAMINA, -nStaminaLost, 0);

    if (STATLIST_UnitGetStatValue(pPlayer, STAT_STAMINA, 0) <= 0)
    {
        STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, 0, 0);
        return 0;
    }

    return 1;
}

inline int CLIENTS_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 0x02:
    case 0x04:
    case 0x05:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int CLIENTS_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case 0x02:
    case 0x04:
    case 0x05:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x0057F410
static void __stdcall PLRMODE_RemoveEquippedItemForCorpse(D2GameStrc* pGame, int nBodyloc, D2UnitStrc* hItem, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    const int bUpdateSets = D2COMMON_11079_Return0(pUnit, hItem);
    INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, hItem);
    D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(pInventory, hItem);

    D2_ASSERT(hRemove, 0x25D);
    D2_ASSERT(hItem == hRemove, 0x25E);

    sub_0063BE30(pInventory, nBodyloc);

    if (ITEMS_GetItemType(hItem) == ITEMTYPE_BELT)
    {
        sub_6FC45930(pGame, pUnit, 0);
    }

    if (hItem)
    {
        hItem->dwFlags &= ~0x02;
    }

    D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, hItem, pUnit, 0, 1);
    ITEMS_SetItemFlag(hItem, 0x20, 1);
    ITEMS_SetItemCMDFlag(hItem, 1, 1);
    ITEMS_SetItemCMDFlag(hItem, 0x10, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, hItem);

    if (bUpdateSets)
    {
        sub_0055D930(pUnit, hItem, 0);
    }

    ITEMS_UpdateSets(pUnit, hItem, 1, 1);
    UNITS_RefreshInventory(pUnit, 1);
}

// 0x0057F4F0
static void PLRMODE_RemoveCursorItemForCorpse(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pPlayer)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrModes.cpp", 0x27D);
    D2GAME_PACKETS_SendPacket0x42_6FC3EE40(pClient, pPlayer);
    INVENTORY_SetCursorItem(pInventory, 0);
    ITEMS_SetItemCMDFlag(pItem, 1, 1);
    INVENTORY_AddItemToTradeInventory(pInventory, pItem);
    UNITS_RefreshInventory(pPlayer, 1);
}

// 0x0057F190
void __fastcall PLRMODE_StartID_WalkRunKnockback(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* pTargetUnit)
{
    D2_ASSERT(ptGame, 0x16E);

    const int nCurMode = nMode;
    D2DynamicPathStrc* pPath = pPlayer->pDynamicPath;
    if (nCurMode != 19 || pPlayer->dwAnimMode != nCurMode)
    {
        PATH_SetPathTarget(pPath, pTargetUnit);
        PLRMODE_StartMovement(ptGame, pPlayer, nCurMode);
    }
}


// 0x0057F540
static void __stdcall PLRMODE_DropItemsOnCorpseOverflow(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    for (int nBodyLoc = -1; nBodyLoc < 0x0D; ++nBodyLoc)
    {
        D2UnitStrc* pItem = 0;
        if (nBodyLoc == -1)
        {
            pItem = INVENTORY_GetCursorItem(pInventory);
        }
        else
        {
            pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        }

        if (pItem)
        {
            if (nBodyLoc == -1)
            {
                PLRMODE_RemoveCursorItemForCorpse(pGame, pItem, pUnit);
            }
            else
            {
                D2_ASSERT(pItem->dwAnimMode == IMODE_EQUIP, 0x2A8);
                PLRMODE_RemoveEquippedItemForCorpse(pGame, nBodyLoc, pItem, pUnit);
            }

            D2UnitStrc* pDupedItem = ITEMS_Duplicate(pGame, pItem, pUnit, 1);
            D2CoordStrc tCoord;
            UNITS_GetCoords(pUnit, &tCoord);
            D2CoordStrc tReturnCoords;
            D2ActiveRoomStrc* pFreeRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &tCoord, &tReturnCoords, 1, 1);
            D2GAME_DropItem_6FC52260(pGame, pUnit, pDupedItem, pFreeRoom, tReturnCoords.nX, tReturnCoords.nY);
        }
    }

    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        UNITS_GetInventoryGoldLimit(pUnit);
    }
    STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
    const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
    PLAYER_DropGold(pGame, pUnit, nUnitId, nGold);
}

// 0x0057F690
static int __stdcall PLRMODE_FreeStaleCorpses(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return 0;
    }

    int nCount = 0;

    D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pInventory);
    while (pCorpse)
    {
        D2CorpseStrc* pNextCorpse = INVENTORY_GetNextCorpse(pCorpse);
        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
        if (!SUNIT_GetServerUnit(pGame, 0, nCorpseGUID))
        {
            INVENTORY_FreeCorpse(pInventory, nCorpseGUID, 1);
        }
        else
        {
            ++nCount;
        }
        pCorpse = pNextCorpse;
    }

    return nCount;
}

static inline int ApplyRatio(int nValue,int nMultiplier,int nDivisor)
{
 if(!nDivisor) return 0;
 if(nValue>0x100000) {
  if(nDivisor>(nValue>>4)) return (int)(nValue*(__int64)nMultiplier/nDivisor);
  return nMultiplier*(nValue/nDivisor);
 }
 if(nMultiplier>0x10000) {
  if(nDivisor<=(nMultiplier>>4)) return nValue*(nMultiplier/nDivisor);
  return (int)(nValue*(__int64)nMultiplier/nDivisor);
 }
 return nMultiplier*nValue/nDivisor;
}

// 0x0057F700
D2UnitStrc* __fastcall PLRMODE_CreateDeadBody(D2GameStrc* pGame,D2UnitStrc* pUnit,int nX,int nY,D2ActiveRoomStrc* pRoom)
{
 D2ActiveRoomStrc* pInitialRoom=pRoom;
 PLRMODE_FreeStaleCorpses(pGame,pUnit);
 D2InventoryStrc* pInventory=pUnit->pInventory;
 if(INVENTORY_GetCorpseCount(pInventory)>15) {PLRMODE_DropItemsOnCorpseOverflow(pGame,pUnit);return 0;}
 D2_ASSERT(pInitialRoom,0x2FD);
 D2ActiveRoomStrc* pCorpseRoom=sub_00463740_FindRoomAtPoint(pInitialRoom,nX,nY);
 if (!pCorpseRoom) {

  char szMessage[256];
  D2_MAYBE_UNUSED(szMessage);
  FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x2FF); exit(-1);
 }
 D2UnitStrc* pCorpse=SUNIT_AllocUnitData(0,pUnit->dwClassId,nX,nY,pGame,pCorpseRoom,1,17,0);
 D2_ASSERT(pCorpse,0x304);
 D2ClientStrc* pClient=UnitGetClient(pUnit,gszPlrModesSourceFile,0x306);
 pCorpse->dwFlags&=~4;
 SUNIT_InitClientInPlayerData(pCorpse,pClient);
 UNITS_SetNameInPlayerData(pCorpse,CLIENTS_GetName(pClient));
 SUNIT_InitSeed(pCorpse,&pGame->pGameSeed);
 UNITS_ChangeAnimMode(pCorpse,17);
 STATES_ToggleState(pCorpse,7,1);
 pCorpse->dwFlagEx|=0x1000;
 pCorpse->dwFlags|=2;
 int nExperience=ApplyRatio(CLIENTS_GetExperienceLoss(pClient),75,100);
 CLIENTS_SetExperienceLoss(pClient,0);
 STATLIST_SetUnitStat(pCorpse,STAT_EXPERIENCE,nExperience,0);
 INVENTORY_CreateCorpseForPlayer(pInventory,!pCorpse ? -1 : pCorpse->dwUnitId,0,1);
 D2InventoryStrc* pCorpseInventory=pCorpse->pInventory;
 D2_ASSERT((!pCorpse ? -1 : pCorpse->dwUnitId)!=(!pUnit ? -1 : pUnit->dwUnitId),0x31A);
 INVENTORY_SetOwnerId(pCorpseInventory,!pUnit ? -1 : pUnit->dwUnitId);
 for(int nBodyLoc=-1;nBodyLoc<13;++nBodyLoc) {
  D2UnitStrc* hItem=0;
  if(nBodyLoc==-1) hItem=INVENTORY_GetCursorItem(pInventory);
  else hItem=INVENTORY_GetItemFromBodyLoc(pInventory,nBodyLoc);
  if(!hItem) continue;
  if(nBodyLoc==-1) PLRMODE_RemoveCursorItemForCorpse(pGame,hItem,pUnit);
  else {
   D2_ASSERT(hItem->dwAnimMode==IMODE_EQUIP,0x339);
   PLRMODE_RemoveEquippedItemForCorpse(pGame,nBodyLoc,hItem,pUnit);
  }
  ITEMS_SetInvPage(hItem,0);
  D2UnitStrc* pDupedItem=ITEMS_Duplicate(pGame,hItem,pUnit,1);
  if(nBodyLoc==-1) {
   int nRecord=UNITS_GetInventoryRecordId(pCorpse,0,pGame->bExpansion);
   if(INVENTORY_PlaceItemAtFreePosition(pCorpseInventory,pDupedItem,nRecord,0,0,gszPlrModesSourceFile,0x349) && INVENTORY_PlaceItemInSocket(pCorpseInventory,pDupedItem,1)) {
    if(pDupedItem) pDupedItem->dwFlags&=~2;
    UNITS_ChangeAnimMode(pDupedItem,0);
    if(pDupedItem) pDupedItem->dwFlags&=~0x02000000;
    ITEMS_SetItemCMDFlag(pDupedItem,2,1);
    INVENTORY_AddItemToTradeInventory(pCorpseInventory,pDupedItem);
    UNITS_RefreshInventory(pCorpse,1);
    QUESTS_ItemPickedUp(pGame,pCorpse,pDupedItem);
    continue;
   }
  } else {
   if(INVENTORY_PlaceItemInBodyLoc(pCorpseInventory,pDupedItem,nBodyLoc)) {
    int nPage=3;
    if(nBodyLoc==11||nBodyLoc==12) nPage=4;
    if(INVENTORY_PlaceItemInSocket(pCorpseInventory,pDupedItem,nPage)) {
     ITEMS_SetBodyLocation(pDupedItem,(unsigned char)nBodyLoc);
     if(pDupedItem) pDupedItem->dwFlags&=~2;
     UNITS_ChangeAnimMode(pDupedItem,1);
     ITEMS_SetInvPage(pDupedItem,255);
     ITEMS_SetItemCMDFlag(pDupedItem,8,1);
     if(pDupedItem) pDupedItem->dwFlags&=~0x02000000;
     INVENTORY_AddItemToTradeInventory(pCorpseInventory,pDupedItem);
     UNITS_RefreshInventory(pCorpse,1);
     QUESTS_ItemPickedUp(pGame,pCorpse,pDupedItem);
     continue;
    }
   }
  }
  D2CoordStrc coords,returned;
  UNITS_GetCoords(pUnit,&coords);
  D2ActiveRoomStrc* pFreeRoom=D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit),&coords,&returned,1,1);
  D2GAME_DropItem_6FC52260(pGame,pUnit,pDupedItem,pFreeRoom,returned.nX,returned.nY);
 }
 int nGold=STATLIST_UnitGetStatValue(pUnit,STAT_GOLD,0);
 if(pUnit->dwUnitType==UNIT_PLAYER) UNITS_GetInventoryGoldLimit(pUnit);
 STATLIST_SetUnitStat(pUnit,STAT_GOLD,0,0);
 SUNITDMG_DropCorpseGold(pGame,pUnit,pCorpse,nGold,1);
 D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame,!pUnit ? -1 : pUnit->dwUnitId,!pCorpse ? -1 : pCorpse->dwUnitId,1);
 return pCorpse;
}


// 0x0057FAF0
static int __stdcall PLRMODE_CanPickUpCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody)
{
    D2_ASSERT(pPlayer, 909);
    D2_ASSERT(pDeadBody, 910);
    D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 911);
    const int nOwnerGUID = INVENTORY_GetOwnerId(pDeadBody->pInventory);
    if (pPlayer->dwUnitId == nOwnerGUID)
    {
        return 1;
    }
    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nOwnerGUID);
    if (pOwner)
    {
        return PLAYERLIST_CheckFlag(pOwner, pPlayer, 1);
    }
    return 0;
}

// 0x0057FB70
void __fastcall PLRMODE_RecoverCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody)
{
    if (!STATES_CheckState(pDeadBody, STATE_PLAYERBODY))
    {
        return;
    }
    if (!PLRMODE_CanPickUpCorpse(pGame, pPlayer, pDeadBody))
    {
        return;
    }
    D2InventoryStrc* const pBodyInventory = pDeadBody->pInventory;
    const int nOwnerGUID = INVENTORY_GetOwnerId(pBodyInventory);
    if ((!pPlayer ? -1 : pPlayer->dwUnitId) == nOwnerGUID)
    {
        const int nExperience = STATLIST_UnitGetStatValue(pDeadBody, STAT_EXPERIENCE, 0);
        if (nExperience)
        {
            STATLIST_SetUnitStat(pDeadBody, STAT_EXPERIENCE, 0, 0);
            SUNITDMG_AddExperience(pGame, pPlayer, nExperience);
        }
    }
    if (ITEMMODE_RecoverCorpseItems(pGame, pPlayer, pDeadBody))
    {
        const int nCorpseGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        D2InventoryStrc* const pInventory = pPlayer->pInventory;
        INVENTORY_FreeCorpse(pInventory, nCorpseGUID, 1);
        const int nBodyGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        const int nBodyType = !pDeadBody ? 6 : pDeadBody->dwUnitType;
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pDeadBody), nBodyType, nBodyGUID);
        const int nDeadGUID = !pDeadBody ? -1 : pDeadBody->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers_6FC3F9B0(pGame, pPlayer->dwUnitId, nDeadGUID, 0);
        UNITS_FreeCollisionPath(pDeadBody);
        SUNIT_RemoveUnit(pGame, pDeadBody);
        SUNIT_AttachSound(pPlayer, 0x5D, pPlayer);
    }
    else
    {
        SUNIT_AttachSound(pPlayer, 0x17, pPlayer);
    }
}

// 0x0057FC60
static inline int PLRMODE_IsOtherPlayerOrMinion(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pUnit || !pTarget || pUnit->dwUnitType != UNIT_PLAYER || pUnit == pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType == UNIT_PLAYER)
    {
        return 1;
    }

    if (pTarget->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pTarget);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && pOwner != pUnit)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0057FCA0
void __fastcall PLRMODE_StartXY_Dead(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode, int nX, int nY)
{
    PLRMODE_CreateDeadBody(pGame, pUnit, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), UNITS_GetRoom(pUnit));
    D2GAME_KillPlayerPets(pGame, pUnit);

    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrModes.cpp", 0x434);
    CLIENTS_ToggleFlag(pClient, 0x08, 1);

    if (!gpD2EventCallbackTable || CLIENTS_CheckFlag(pClient, 0x04))
    {
        D2GAME_SAVE_WriteFile_6FC8A500(pGame, pUnit, CLIENTS_GetName(UnitGetClient(pUnit, ".\\PLAYER\\PlrModes.cpp", 0x43A)), 0);
    }

    SUNIT_SetCombatMode(pGame, pUnit, 0x11);
    sub_6FCBC4D0(pUnit);
    PLRMODE_FinalizeDeath(pGame, pUnit);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pUnit);
}

// 0x0057FDC0
void __fastcall PLRMODE_StartXY_Block(D2GameStrc* pGame, D2UnitStrc* hPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(hPlayer, 1095);

    SUNIT_SetCombatMode(pGame, hPlayer, nMode);
    sub_6FCBC4D0(hPlayer);
    UNITS_SetUsedSkill(hPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, hPlayer);
    sub_6FCBCE70(pGame, hPlayer);
}

// 0x0057FE20
int __fastcall PLRMODE_ModeCheck_GetHit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

// 0x0057FE30
void __fastcall PLRMODE_StartXY_GetHit(D2GameStrc* pGame, D2UnitStrc* hPlayer, int nMode, int nX, int nY)
{
    D2_ASSERT(hPlayer, 1136);

    SUNIT_SetCombatMode(pGame, hPlayer, nMode);
    sub_6FCBC4D0(hPlayer);
    UNITS_SetUsedSkill(hPlayer, 0);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, hPlayer);
    sub_6FCBCE70(pGame, hPlayer);
}

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

int __fastcall SKILLS_StartUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FAF0

#define UNITFLAG_SKSRVDOFUNC 0x00000040

// 0x0057FE90
void __fastcall PLRMODE_StartXY_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, int nX, int nY)
{
    D2COMMON_10170_PathSetTargetPos(pPlayer->pDynamicPath, nX, nY);
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);
    UNITS_SetTargetUnitForDynamicUnit(pPlayer, 0);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);
    pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    SKILLS_StartUsedSkill(pGame, pPlayer);
}

// 0x0057FEF0
void __fastcall PLRMODE_StartID_AttackCastThrowKickSpecialSequence(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nMode, D2UnitStrc* hTarget)
{
    SUNIT_SetCombatMode(pGame, pPlayer, nMode);

    D2_ASSERT(hTarget, 1215);

    UNITS_SetTargetUnitForDynamicUnit(pPlayer, hTarget);
    sub_6FCBC4D0(pPlayer);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pPlayer);
    sub_6FCBCE70(pGame, pPlayer);

    if (pPlayer)
    {
        pPlayer->dwFlags &= ~UNITFLAG_SKSRVDOFUNC;
    }

    SKILLS_StartUsedSkill(pGame, pPlayer);
}

int __fastcall sub_M120_Emit_0057FC60(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    return PLRMODE_IsOtherPlayerOrMinion(pUnit, pTarget);
}

// 0x0057FF70
static void __stdcall PLRMODE_RestoreWeapon(D2GameStrc* pGame, unsigned char nBodyLoc, D2UnitStrc* pPlayer)
{
    int nNewBodyLoc = nBodyLoc;
    const int nWeaponGUID = UNITS_GetWeaponGUID(pPlayer);
    if (!nWeaponGUID)
    {
        return;
    }

    D2UnitStrc* pWeaponItem = SUNIT_GetServerUnit(pGame, 0x04, nWeaponGUID);
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (pWeaponItem && pInventory && !ITEMS_GetInvPage(pWeaponItem) && INVENTORY_CompareWithItemsParentInventory(pInventory, pWeaponItem) && ITEMMODE_FindFreeBodyLocation(pPlayer, pWeaponItem, &nNewBodyLoc, 0))
    {
        nBodyLoc = nNewBodyLoc;
        D2_ASSERT(!INVENTORY_GetItemFromBodyLoc(pInventory, nNewBodyLoc), 0x4EA);

        sub_6FC49F80(pGame, pPlayer, nWeaponGUID, nBodyLoc);
    }

    UNITS_SetWeaponGUID(pPlayer, 0);
}

// 0x00580030
static void __stdcall sRestoreWeapon(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pWeapon)
{
    if ((ITEMS_CheckIfStackable(pWeapon) || ITEMS_CheckIfThrowable(pWeapon) || STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_THROWABLE, 0)) && STATLIST_UnitGetStatValue(pWeapon, STAT_QUANTITY, 0) <= 0)
    {
        if (STATLIST_UnitGetItemStatOrSkillStatValue(pWeapon, STAT_ITEM_THROWABLE, 0))
        {
            STATLIST_SetUnitStat(pWeapon, STAT_QUANTITY, 0, 0);
            return;
        }

        if (ITEMSIsA(pWeapon, 0x2D) && ITEMS_IsMagSetRarUniCrfOrTmp(pWeapon))
        {
            if (!ITEMS_CheckItemFlag(pWeapon, 0x100, 0x513, gszPlrModesSourceFile))
            {
                ITEMMODE_BreakItem(pGame, pPlayer, pWeapon);
            }
            return;
        }

        const int bReload = ITEMS_GetReload(pWeapon);
        const int nItemType = ITEMS_GetItemType(pWeapon);
        unsigned char nBodyLoc = ITEMS_GetBodyLocation(pWeapon);
        const int bReEquip = ITEMS_GetReEquip(pWeapon);
        UNITS_ChangeAnimMode(pPlayer, 1);

        int a5;
        ITEMMODE_UnequipBodyItem(pGame, pPlayer, nBodyLoc, 1, &a5);
        ITEMS_SetItemCMDFlag(pWeapon, 1, 1);

        if (bReload)
        {
            D2UnitStrc* pItem = 0;
            while ((pItem = INVENTORY_GetBackPackItemByType(pPlayer->pInventory, nItemType, pItem)) != 0)
            {
                const int nItemClassId = !pItem ? -1 : pItem->dwClassId;
// build: symbol ?GAME_GetUnitClassId@* 0x00451F60
                if (GAME_GetUnitClassId(pWeapon) == nItemClassId && !ITEMS_CheckItemFlag(pItem, 0x100, 0x531, gszPlrModesSourceFile))
                {
                    break;
                }
            }

            if (pItem)
            {
                const int nWeaponClassId = !pWeapon ? -1 : pWeapon->dwClassId;
                if (nWeaponClassId == pItem->dwClassId && !INVENTORY_GetItemFromBodyLoc(pPlayer->pInventory, nBodyLoc) && sub_6FC49F80(pGame, pPlayer, !pItem ? -1 : pItem->dwUnitId, nBodyLoc))
                {
                    return;
                }
            }
        }

        if (bReEquip)
        {
            PLRMODE_RestoreWeapon(pGame, nBodyLoc, pPlayer);
        }
    }
}

// 0x005801E0
static void PLRMODE_SaveActiveSkills(D2UnitStrc* pUnit, D2UnkPlrModeStrc2* pSkills)
{
    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        pSkills->nLeftSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pLeftSkill);
        pSkills->nLeftSkillId = SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\PLAYER\\PlrModes.cpp", 0x56E);
    }
    else
    {
        pSkills->nLeftSkillOwnerGUID = -1;
        pSkills->nLeftSkillId = 0;
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        pSkills->nRightSkillOwnerGUID = SKILLS_GetOwnerGUIDFromSkill(pRightSkill);
        pSkills->nRightSkillId = SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\PLAYER\\PlrModes.cpp", 0x57A);
    }
    else
    {
        pSkills->nRightSkillOwnerGUID = -1;
        pSkills->nRightSkillId = 0;
    }
}

// 0x00580260
static int PLRMODE_IsSkillUsable(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    switch (SKILLS_GetUseState(pUnit, pSkill))
    {
    case 0x02:
    case 0x07:
        return 0;
    }

    return 1;
}

// 0x00580280
static void PLRMODE_RestoreWeaponSkills(D2UnitStrc* pUnit, D2UnkPlrModeStrc2* pSkills)
{
    if (pSkills->nLeftSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pSkills->nLeftSkillId, pSkills->nLeftSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetLeftSkill(pUnit) && PLRMODE_IsSkillUsable(pUnit, pSkill))
        {
            D2GAME_AssignSkill_6FD13800(pUnit, 1, pSkills->nLeftSkillId, pSkills->nLeftSkillOwnerGUID);
        }
    }

    if (pSkills->nRightSkillId)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, pSkills->nRightSkillId, pSkills->nRightSkillOwnerGUID);
        if (pSkill && pSkill != UNITS_GetRightSkill(pUnit) && PLRMODE_IsSkillUsable(pUnit, pSkill))
        {
            D2GAME_AssignSkill_6FD13800(pUnit, 0, pSkills->nRightSkillId, pSkills->nRightSkillOwnerGUID);
        }
    }
}

// 0x00580C20
int __fastcall PLRMODE_UpdateMovement(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nEventCustomId, int nEventCustomParam)
{
    SUNIT_ValidateTargetUnit(pGame, pPlayer);

    if (STATES_CheckState(pPlayer, STATE_BLAZE))
    {
        SKILLS_CreateBlazeMissile(pGame, pPlayer);
    }

    if (pPlayer && pPlayer->dwAnimMode == PLRMODE_RUN && !PLRMODE_DrainRunStamina(pPlayer))
    {
        PLRMODE_StartMovement(pGame, pPlayer, 2);
    }

    int nPathResult = SUNIT_UpdateUnitPath(pGame, pPlayer);
    const unsigned int nTickCount = GetTickCount();
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (nTickCount > pPlayerData->dwPositionHistoryTick + 25)
    {
        const unsigned char nHistoryIndex = pPlayerData->nPositionHistoryIndex;
        unsigned char nPreviousIndex;
        if (!nHistoryIndex)
        {
            nPreviousIndex = 19;
        }
        else
        {
            if (nPathResult) nPreviousIndex = nHistoryIndex - 1; else nPreviousIndex = nHistoryIndex - 1;
        }

        const int nPlayerX = sub_F05_PlrGetUnitX(pPlayer);
        const int nPlayerY = sub_F05_PlrGetUnitY(pPlayer);
        const int nPrevX = pPlayerData->pPositionHistory[nPreviousIndex].nX;
        const int nPrevY = pPlayerData->pPositionHistory[nPreviousIndex].nY;
        if (PATH_ComputeSquaredDistance(nPlayerX, nPlayerY, nPrevX, nPrevY) > 45)
        {
            pPlayerData->pPositionHistory[nHistoryIndex].nX = nPlayerX;
            pPlayerData->pPositionHistory[nHistoryIndex].nY = nPlayerY;
            pPlayerData->dwPositionHistoryTick = nTickCount;

            ++pPlayerData->nPositionHistoryIndex;
            if (pPlayerData->nPositionHistoryIndex >= 20)
            {
                pPlayerData->nPositionHistoryIndex = 0;
            }
        }
    }

    if (nPathResult == 2)
    {
        if (sub_F05_IsInteracting(pPlayer))
        {
            int nResult;
            const int nAction = sub_F05_GetInteractAction(pPlayer);
            if (nAction >= 0)
            {
                D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, nAction);
                if (pSkill)
                {
                    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pPlayer, pSkill);
                    StartModeID(pGame, pPlayer, pSkill, nSkillMode, sub_F05_GetInteractUnitType(pPlayer), sub_F05_GetInteractUnitGUID(pPlayer), 0);
                    nPathResult = 1;
                }
                else
                {
                    PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
                }
                nResult = nPathResult;
            }
            else
            {
                PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
                PLRMSG_InteractWithUnit(pPlayer, sub_F05_GetInteractUnitType(pPlayer), sub_F05_GetInteractUnitGUID(pPlayer), nAction == -2, pGame);
                nResult = *(volatile int*)&nPathResult; // volatile only gives nPathResult the original's stack slot
            }

            if (nPathResult) sub_F05_SetInteractFlag(pPlayer, 0); else sub_F05_SetInteractFlag(pPlayer, 0);
            return nResult;
        }

        PLRMODE_StartXY_Neutral(pGame, pPlayer, 1, 0, 0);
    }

    return nPathResult;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00580310
void __fastcall PLRMODE_HandleDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        if (pInventory)
        {
            D2UnkPlrModeStrc2 tSkills;
            PLRMODE_SaveActiveSkills(pUnit, &tSkills);

            D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 0x04);
            if (pRightWeapon)
            {
                sRestoreWeapon(pGame, pUnit, pRightWeapon);
            }

            D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 0x05);
            if (pLeftWeapon)
            {
                sRestoreWeapon(pGame, pUnit, pLeftWeapon);
            }

            PLRMODE_RestoreWeaponSkills(pUnit, &tSkills);
        }
    }
}

static inline unsigned char UNITS_GetHpPercent_Inline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
        if (nMaxLife > 0 && nHitpoints < nMaxLife)
            return (nHitpoints << 7) / nMaxLife;
    }
    return 0x80;
}

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord_Inline(int nClassId)
{
    if (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount)
        return &sgptDataTables->pCharStatsTxt[nClassId];
    return 0;
}

// 0x00580380
void __fastcall PLRMODE_BreakDepletedWeapons(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        D2InventoryStrc* pInventory = pPlayer->pInventory;
        D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
        int bChangedToNeutral = 0;
        while (pItem)
        {
            if (INVENTORY_GetItemNodePage(pItem) == 3)
            {
                D2UnitStrc* pWeapon = INVENTORY_UnitIsItem(pItem);
                if (ITEMSIsA(pWeapon, ITEMTYPE_WEAPON) && ITEMS_HasDurability(pWeapon)
                    && STATLIST_UnitGetStatValue(pWeapon, STAT_DURABILITY, 0) <= 0
                    && !ITEMS_CheckItemFlag(pWeapon, IFLAG_BROKEN, 1513, ".\\PLAYER\\PlrModes.cpp"))
                {
                    if (!bChangedToNeutral)
                    {
                        UNITS_ChangeAnimMode(pPlayer, PLRMODE_NEUTRAL);
                        bChangedToNeutral = 1;
                    }

                    ITEMMODE_BreakItem(pGame, pPlayer, pWeapon);
                    pItem = INVENTORY_GetFirstItem(pInventory);
                    continue;
                }
            }

            pItem = INVENTORY_GetNextItem(pItem);
        }
    }
}

#define UNITFLAG_SKSRVDOFUNC 0x00000040

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

void __fastcall SKILLS_ExecuteUsedSkill(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0056FC50

// 0x00580460
int __fastcall PLRMODE_UpdateSkill(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pPlayer);
    if (!pSkill)
    {
        return 2;
    }

    UNITS_SetAnimationFrame(pPlayer, nSkillLevel);

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    if (nSkillFlags & 1 && (SUNIT_ValidateTargetUnit(pGame, pPlayer), SUNIT_UpdateUnitPath(pGame, pPlayer) == 2))
    {
        SKILLS_SetFlags(pSkill, nSkillFlags | 2);
    }
    else
    {
        if (pPlayer && UNIT_HasFlag(pPlayer, UNITFLAG_SKSRVDOFUNC) || nSkillId != SKILL_KICK && nSkillId != SKILL_THROW)
        {
            return (SUNIT_IsDead(pPlayer) != 0) + 1;
        }
    }

    SKILLS_ExecuteUsedSkill(pGame, pPlayer);
    return (SUNIT_IsDead(pPlayer) != 0) + 1;
}

// 0x00580500
static void EVENTS_StaminaRegen(D2UnitStrc* pUnit)
{
    int nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0);
    int nShift = 8;
    const int nStaminaRecoveryBonus = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINARECOVERYBONUS, 0);

    int nAnimMode;
    if (!pUnit)
        nAnimMode = 0;
    else
        nAnimMode = pUnit->dwAnimMode;

    switch (nAnimMode)
    {
    case 6:
        nShift = 9;
        break;

    case 2:
        nShift = 9;
        if (nStamina >> 8)
            break;
        return;

    case 1:
    case 5:
        break;

    default:
        if (nStaminaRecoveryBonus < 1000)
            return;
        break;
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    if (nStamina < nMaxStamina)
    {
        int nAdd = nMaxStamina >> nShift;
        if (nStaminaRecoveryBonus)
            nAdd += (nStaminaRecoveryBonus * nAdd) / 100;

        nStamina += nAdd;
        if (nStamina > nMaxStamina)
            nStamina = nMaxStamina;

        STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nStamina, 0);
    }
}

// 0x005805D0
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0x80;
    }

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nMaxHp > 0 && nHitpoints < nMaxHp)
    {
        return (nHitpoints << 7) / nMaxHp;
    }

    return 0x80;
}

// 0x00580610
static int EVENTS_HpRegen(D2UnitStrc* pUnit)
{
    const int nHpRegen = STATLIST_UnitGetStatValue(pUnit, STAT_HPREGEN, 0);
    if (!nHpRegen)
        return 1;

    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    int nLife = nHpRegen + nHitpoints;
    if (nLife > nMaxHp)
    {
        nLife = nMaxHp;
        D2StatListStrc* pHealthPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HEALTHPOT);
        if (pHealthPotStatList)
        {
            D2Common_10474(pUnit, pHealthPotStatList);
            STATLIST_FreeStatList(pHealthPotStatList);
        }
    }

    if (nLife < 0x100)
        nLife = 0x100;

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nLife, 0);

    const unsigned char nLastSentHpPct = STATLIST_UnitGetStatValue(pUnit, STAT_LAST_SENT_HP_PCT, 0);
    const unsigned char nHpPct = UNITS_GetHpPercent_Inline(pUnit);

    int nHpPctDiff = nLastSentHpPct - nHpPct;
    if (nHpPctDiff < 0)
        nHpPctDiff = -nHpPctDiff;

    if (nHpPctDiff > 4)
    {
        SUNITMSG_QueueLifeUpdate(pUnit, nHpPct);
        STATLIST_SetUnitStat(pUnit, STAT_LAST_SENT_HP_PCT, nHpPct, 0);
    }
    return 1;
}

// 0x005806F0
static void EVENTS_ManaRegen(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);

        int nManaRecovery = 0;
        if (!STATES_CheckState(pUnit, STATE_NOMANAREGEN))
        {
            D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord_Inline(pUnit->dwClassId);
            if (!pCharStatsTxtRecord)
                return;

            int nManaRegen = 25 * pCharStatsTxtRecord->nManaRegen;
            if (!nManaRegen)
                nManaRegen = 7500;

            int nManaMultiplier = nMaxMana / nManaRegen;
            if (nManaMultiplier < 1)
                nManaMultiplier = 1;

            nManaRecovery = DATATBLS_ApplyRatio(nManaMultiplier, STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERYBONUS, 0) + 100, 100);
        }

        nManaRecovery += STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERY, 0);
        if (nMaxMana <= nMana && nManaRecovery > 0)
        {
            D2StatListStrc* pManaPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_MANAPOT);
            if (pManaPotStatList)
            {
                D2Common_10474(pUnit, pManaPotStatList);
                STATLIST_FreeStatList(pManaPotStatList);
            }
        }

        if (nManaRecovery > nMaxMana - nMana)
            nManaRecovery = nMaxMana - nMana;

        if (nManaRecovery < -nMana)
            nManaRecovery = -nMana;

        if (nManaRecovery)
            STATLIST_AddUnitStat(pUnit, STAT_MANA, nManaRecovery, 0);
    }
}

// 0x00580800
void __fastcall MONSTERMODE_EventUpdateStatListExpirations(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    STATLIST_UpdateStatListsExpiration(pUnit, pGame->dwGameFrame);
}

// 0x00580810
void __fastcall D2GAME_EVENTS_StatRegen_6FC80F80(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventCustomId, int nEventCustomParam)
{
    EVENT_SetEvent(pGame, pUnit, 3, pGame->dwGameFrame + 1, nEventCustomId, nEventCustomParam);
    if (SUNIT_IsDead(pUnit))
        return;

    if (EVENTS_HpRegen(pUnit))
    {
        EVENTS_StaminaRegen(pUnit);
        EVENTS_ManaRegen(pUnit);
    }
}

// 0x00581020
void __fastcall PLRMODE_EndAnimation(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;
    switch (nAnimMode)
    {
    case 7:
    case 8:
    case 11:
        PLRMODE_HandleDepletedWeapons(pGame, pUnit);
        PLRMODE_BreakDepletedWeapons(pGame, pUnit);
        break;

    default:
        D2SkillStrc* pUsedSkill = UNITS_GetUsedSkill(pUnit);
        if (!pUsedSkill)
        {
            goto done;
        }

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordInline(SKILLS_GetSkillIdFromSkill(pUsedSkill, ".\\PLAYER\\PlrModes.cpp", 0x779));
        if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[0x12 >> 3] & gdwBitMasks[0x12 & 7]))
        {
            goto done;
        }

        PLRMODE_HandleDepletedWeapons(pGame, pUnit);
        PLRMODE_BreakDepletedWeapons(pGame, pUnit);
        break;
    }

done:
    switch (nAnimMode)
    {
    case 0:
        PLRMODE_StartXY_Dead(pGame, pUnit, 17, 0, 0);
        return;

    case 19:
        break;

    default:
        PLRMODE_StartXY_Neutral(pGame, pUnit, 1, 0, 0);
        return;
    }

    D2_ASSERT(pGame, 0x805);

    if (pUnit->pInventory && INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return;
    }

    switch (pUnit->dwAnimMode)
    {
    case 7:
    case 8:
    case 10:
    case 11:
        PLRMODE_IsEndAnimDue(pGame, pUnit);
        break;

    case 0:
    case 4:
    case 9:
    case 17:
        return;

    case 12:
        if (PLRMODE_IsEndAnimDue(pGame, pUnit))
        {
            break;
        }
        return;

    case 13:
        if (pUnit->dwClassId == 0)
        {
            return;
        }
        break;

    case 15:
        if (pUnit->dwClassId == 5)
        {
            return;
        }
        break;

    case 18:
        if (!PLRMODE_CanEndSequence(pGame, pUnit))
        {
            return;
        }
        break;

    default:
        break;
    }

    if (!PLRMODE_CanInterruptCurrentMode(pGame, pUnit, 4, 1, 0))
    {
        return;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)gaPlayerModeChart[4].pfnStartXY), 0x812);

    gaPlayerModeChart[4].pfnStartXY(pGame, pUnit, 4, -1, 0);
}

typedef int (__fastcall* D2ModeCheckFn)(D2GameStrc*, D2UnitStrc*, int, int);

extern D2ModeCheckFn gpfnModeChecks[]; // 0x00732C10

// 0x005811D0
void __fastcall PLRMODE_EventModeUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nMode = !pUnit ? 0 : pUnit->dwAnimMode;
    if (gpfnModeChecks[!pUnit ? 0 : pUnit->dwAnimMode])
    {
        if (gpfnModeChecks[nMode](pGame, pUnit, nSkillId, nSkillLevel) == 2)
        {
            PLRMODE_EndAnimation(pGame, pUnit, nSkillId, nSkillLevel);
        }
    }
}

// 0x00581220
void __fastcall D2GAME_EVENTS_Callback_6FC81BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam)
{
    if ((unsigned int)nEvent <= 14 && gpfnPlayerEventCallbacks[nEvent])
    {
        gpfnPlayerEventCallbacks[nEvent](pGame, pUnit, nCustomId, nCustomParam);
    }
}

// 0x00580860
void __fastcall PLRMODE_SendPlayerUpdates(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient, int a4)
{
    D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        if (UNIT_HasFlagEx(pPlayer, UNITFLAGEX_TELEPORTED))
        {
            sub_6FC81CA0(pPlayer, pClient, 1);
        }
        else if (UNIT_HasFlagEx(pPlayer, 0x800) && pPlayer != pOtherPlayer)
        {
            sub_6FC81CA0(pPlayer, pClient, 0);
        }
    }

    if (!a4 && pPlayer && UNIT_HasFlagEx(pPlayer, UNITFLAGEX_HASINV))
    {
        D2GAME_INVMODE_First_6FC40FB0(pGame, pPlayer, pClient, 0);
        D2GAME_SendPacket0x47_6FC3EEE0(pClient, pPlayer);
        D2GAME_SendPacket0x48_6FC3EF40(pClient, pPlayer, 0);
    }

    if (pPlayer && UNIT_HasFlag(pPlayer, UNITFLAG_DOUPDATE))
    {
        PLRMSG_SendUnitMode(pGame, pPlayer, pClient);
    }

    SUNITMSG_SendQueuedMessages(pPlayer, pClient);

    if (pPlayer)
    {
        if (UNIT_HasFlag(pPlayer, 0x400))
        {
            D2GAME_UpdateUnit_6FCC6080(pPlayer, pClient);
        }

        if (UNIT_HasFlag(pPlayer, 0x100))
        {
            SUNITMSG_SendHoverText(pPlayer, pClient);
        }

        if (UNIT_HasFlag(pPlayer, 0x8000))
        {
            PLRMSG_SendKnockbackStatus(pPlayer, pClient);
        }
    }

    if (STATES_IsAnyGfxStateFlagSet(pPlayer))
    {
        D2GAME_STATES_SendStates_6FCC5F00(pPlayer, pClient, 0);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pPlayer))
    {
        SUNITMSG_SendOverlay(pPlayer, pClient);
    }

    D2Common_10512(pPlayer, pOtherPlayer, STAT_VELOCITYPERCENT, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_ATTACKRATE, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_LEVEL, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_STRENGTH, D2GAME_UpdateAttribute_6FC822D0);
    D2Common_10512(pPlayer, pOtherPlayer, STAT_DEXTERITY, D2GAME_UpdateAttribute_6FC822D0);
}

// 0x005809D0
void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7)
{
    D2_ASSERT(ptGame, 0x805);

    if (PLRMODE_CanStartMode(ptGame, pUnit, nMode) && (a7 || PLRMODE_CanInterruptCurrentMode(ptGame, pUnit, nMode, 1, pUsedSkill)))
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gaPlayerModeChart[nMode].pfnStartXY), 0x812);

        if (pUsedSkill)
        {
            UNITS_SetUsedSkill(pUnit, pUsedSkill);
        }

        gaPlayerModeChart[nMode].pfnStartXY(ptGame, pUnit, nMode, nX, nY);
    }
}

// 0x00580A70
void __fastcall StartModeID(D2GameStrc* ptGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter)
{
    D2_ASSERT(ptGame, 0x835);

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(ptGame, nUnitType, nTargetGUID);
    if (!pTarget)
    {
        LOG_11100(1, 2, 4, 4, ".\\PLAYER\\PlrModes.cpp", 0x83A, "StartModeID: Bad Target");
        return;
    }

    if (PLRMODE_CanStartMode(ptGame, pPlayer, nMode) && (bAllowReEnter || PLRMODE_CanInterruptCurrentMode(ptGame, pPlayer, nMode, 1, pSkill)))
    {
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nMode = 0;
        }

        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
        }

        D2_ASSERT(!IsBadCodePtr((FARPROC)gaPlayerModeChart[nMode].pfnStartID), 0x853);

        if (pSkill)
        {
            UNITS_SetUsedSkill(pPlayer, pSkill);
        }

        gaPlayerModeChart[nMode].pfnStartID(ptGame, pPlayer, nMode, pTarget);
    }
}

// 0x00580B70
void __fastcall PLRMODE_EventFreeHoverText(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    if (!pUnit)
    {
        return;
    }

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
    {
        return;
    }

    const unsigned int nTimeout = CHAT_GetTimeoutFromHoverMsg(pHoverText);
    if (nTimeout <= pGame->dwGameFrame)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pHoverText);
        pUnit->pHoverText = 0;
        UNITROOM_RefreshUnit(pUnit);
        pUnit->dwFlags |= UNITFLAG_HASTXTMSG;
    }
    else
    {
        EVENT_SetEvent(pGame, pUnit, 6, nTimeout, 0, 0);
    }
}

// 0x00580BE0
void __fastcall PLRMODE_EventSynchronizePartyAndPets(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4)
{
    PARTY_SynchronizeWithClient(pGame, pUnit);
    PLAYERPETS_UpdatePetStates(pGame, pUnit);
    EVENT_SetEvent(pGame, pUnit, 11, pGame->dwGameFrame + 30, 0, 0);
}

// 0x00580EC0
void __fastcall PLRMODE_StartID_Death(D2GameStrc* pGame, D2UnitStrc* pDefender, int nMode, D2UnitStrc* pAttacker)
{
    bool bIsDruid = false;
    if (pDefender && pDefender->dwUnitType == UNIT_PLAYER && pDefender->dwClassId == 0x05)
    {
        bIsDruid = true;
    }

    if (SKILLS_RemoveTransformStatesFromShapeshiftedUnit(pDefender) && bIsDruid)
    {
        D2_ASSERT(pGame, 0x805);

        if (pDefender->pInventory && INVENTORY_GetCursorItem(pDefender->pInventory))
        {
            return;
        }

        D2_ASSERT(!IsBadCodePtr((FARPROC)gaPlayerModeChart[1].pfnStartXY), 0x812);

        gaPlayerModeChart[1].pfnStartXY(pGame, pDefender, 1, 0, 0);
        return;
    }

    PLAYER_ApplyDeathPenalty(pGame, pDefender, pAttacker);
    SUNIT_SetCombatMode(pGame, pDefender, 0);
    D2ClientStrc* pClient = UnitGetClient(pDefender, ".\\PLAYER\\PlrModes.cpp", 0x40B);
    CLIENTS_ToggleFlag(pClient, 0x08, 1);
    sub_6FCBC4D0(pDefender);
    PLRMODE_FinalizeDeath(pGame, pDefender);
    D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(pGame, pDefender);
    sub_6FCBCE70(pGame, pDefender);

    if (!STATES_CheckState(pDefender, STATE_PLAYERBODY) && pDefender)
    {
        pDefender->dwFlags &= ~0x02;
    }

    if (pDefender && pAttacker && pDefender->dwUnitType == UNIT_PLAYER && pDefender != pAttacker)
    {
        D2UnitStrc* pOwner;
        if (pAttacker->dwUnitType == UNIT_PLAYER
            || pAttacker->dwUnitType == UNIT_MONSTER && (pOwner = AIGENERAL_GetMinionOwner(pAttacker)) != 0 && pOwner->dwUnitType == UNIT_PLAYER && pOwner != pDefender)
        {
            ITEMS_DropPlayerEar(pGame, pDefender);
        }
    }

    if (pAttacker)
    {
        D2GAME_PLRMSG_Last_6FC89450(pGame, pAttacker, pDefender);
        ARENA_ProcessKillEvent(pGame, pAttacker, pDefender);
    }

    PLAYER_CloseInteraction(pGame, pDefender);
}

#define PREFIX

#define HOVER_FLAG 0x100

#define HOVER_EVENT 6

#include "gen/data/Source/D2Game/PLAYER/PlrModes.inc"
