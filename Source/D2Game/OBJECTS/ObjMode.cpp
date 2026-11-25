#include "D2ObjectIds.h"
#include "D2MissileIds.h"
#include "D2ItemTypes.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2ObjModes.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2TxtItems.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"
#include "D2GameTypes.h"
#include "D2GameRecords.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define EVENTTYPE_FREEHOVER 6

#define UNITFLAG_DOUPDATE 0x00000001

#define UNITFLAG_HASTXTMSG 0x00000100


#define UNITFLAGEX_TELEPORTED 0x10000

#define UNITFLAG_TARGETABLE 0x00000002


#define STATE_FREEZE 1

#define STATE_POISON 2

#define EVENTTYPE_AITHINK 2

#define EVENTTYPE_MODECHANGE 0

#define EVENTTYPE_PERIODICSTATS 9


struct D2ObjectControlStrc;

union D2SeedStrc;

struct D2MonStatsTxt;

struct D2ObjOperateFnStrc;

struct D2ObjectDataStrc;

struct D2DrlgCoordsStrc;

struct D2ContextDataStrc;

struct D2ContextStrc;

struct D2MonStats2Txt;


struct D2PlayerDataStrc;

struct D2ItemsTxt;

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2CharStatsTxt;

struct D2ShrineTableStrc;

struct D2CurseStrc;

struct D2SkillContext00583BF0Strc;

struct D2Event00583BF0Strc;

struct D2EventState00583BF0Strc;

struct D2TimerArg2Strc;

struct D2ObeliskPowerUpStrc;

struct D2PortalFlags00585580Strc;

struct D2ObjectsTxt;

struct D2UnitStrc;

struct D2GameStrc;

struct D2ActiveRoomStrc;

struct D2CoordStrc;

struct D2ItemDropStrc;

struct D2DataTablesStrc;

struct D2ShrinesTxt;

struct D2TimerArgStrc;

typedef int(__stdcall* FARPROC)();

typedef void(__fastcall* ObjTrapHandlerFunction)(D2GameStrc* pGame, D2UnitStrc* pObject);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern ObjTrapHandlerFunction sgObjectTrapHandlers[10]; // 0x00732CEC

extern int gnObjectTrapHandlers_00732D14; // 0x00732D14

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall OBJEVAL_ApplyTrapObjectDamage(D2GameStrc* pGame, D2UnitStrc* pSrcUnit, D2UnitStrc* pTargetUnit, int nDamageType); // 0x005DFA00

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall UNITS_IsShrine(D2UnitStrc* pUnit); // 0x00621B00

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005449E0

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall UNITS_GetUnitSizeY(D2UnitStrc* pUnit); // 0x006205A0

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int a2); // 0x00558200

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int a3); // 0x00558D90

struct D2ContextDataStrc
{
    unsigned char padding[16];
    unsigned int state;
};

struct D2ContextStrc
{
    int unknown;
    D2ContextDataStrc* data;
};

int __fastcall sub_00581F60_HandleState(D2ContextStrc* context, void* argument); // 0x00581F60

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit); // 0x0055B7E0

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

void __fastcall D2GAME_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket); // 0x0053D8D0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

extern "C" char* __cdecl _strrev(char* szString); // 0x00687860

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2UnitStrc* __stdcall INVENTORY_GetBackPackItemByType(D2InventoryStrc* pInventory, int nItemType, D2UnitStrc* pLastItem); // 0x0063CD80

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010

void __fastcall D2GAME_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nCell); // 0x00628320

void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0

static int __stdcall OBJMODE_DropShrineGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer);

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

D2UnitStrc* __stdcall UNITFINDS_GetNearestTestedUnit(D2UnitStrc* pUnit, int nX, int nY, int nSize, int (__fastcall* pfnUnitTest)(D2UnitStrc*, D2UnitStrc*)); // 0x0065A800

int __fastcall OBJMODE_IsMonsterShrineCandidate(D2UnitStrc* pMonster, D2UnitStrc* pUnit1); // 0x00582750

void __fastcall MONSTERUNIQUE_PromoteToUnique(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005A4940

typedef void(__fastcall* ObjShrineFunction)(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2ShrineTableStrc
{
    ObjShrineFunction pfShrineCallback;
    int unk0x04;
    int unk0x08;
};

extern const D2ShrineTableStrc sgcptShrineChart[]; // 0x006E1850

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

int __stdcall SKILLS_GetWeaponMasteryBonus(D2UnitStrc* pUnit, D2UnitStrc* pItem, D2SkillStrc* pSkill, int nType); // 0x00645830

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory); // 0x0063D340

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

D2StatListStrc* __fastcall OBJMODE_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback); // 0x00582800

void __fastcall OBJMODE_RemoveStaminaShrine(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x00583A40

static int __stdcall OBJMODE_CalculateShrineStatBonus(int nStatId, int nValue, D2UnitStrc* pUnit); // 0x00583840

struct D2SkillContext00583BF0Strc
{
    unsigned char unk_00[4];
    D2UnitStrc* pUnit;
    D2UnitStrc* pTarget;
};

struct D2Event00583BF0Strc
{
    unsigned char nType;
    unsigned char unk_01[0x0B];
    int nDuration;
};

struct D2EventState00583BF0Strc
{
    int nState;
    int unk_04[2];
};

extern D2EventState00583BF0Strc gaShrineSkillBoostStates[]; // 0x006E1858

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

void __fastcall SKILLS_RefreshPassivesAndPetLimits(D2UnitStrc* pUnit); // 0x0056DE40

void __fastcall OBJMODE_RemoveSkillShrine(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x00583BD0

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp); // 0x00584330

enum
{
    ARCANE_TILECALC = 11,
};

void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0

void __fastcall ACT2Q4_SetPortalMode(D2GameStrc* pGame, int nLevelId); // 0x0059BAF0

struct D2TimerArg2Strc
{
    int nUnitGUID;
};

struct D2TimerArgStrc
{
    D2TimerArg2Strc* pArg;
    int dwUnitId;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

typedef int (__fastcall* ObjOperateFunction)(D2ObjOperateFnStrc* pOp, int nOperate);

typedef int (__fastcall* ObjOperateCallFunction)(D2ObjOperateFnStrc* pOp);

extern ObjOperateFunction gpfnObjOperateFunctions[]; // 0x00732D18

int __fastcall OBJECTS_OperateFunction23_Waypoint(D2ObjOperateFnStrc* pOp, int nOperate); // 0x00584E30

void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife); // 0x0053B4B0

void __fastcall OBJRGN_AllocObjectRoomCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00547170

D2WaypointDataStrc* __fastcall sub_00547F50(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00547F50

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* ptGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00

int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, int nWaypointNo); // 0x00660E50

typedef int(__fastcall* ObeliskPowerUpFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue);

struct D2ObeliskPowerUpStrc
{
    ObeliskPowerUpFunction pPowerUpCallback;
    unsigned int nChance;
    int nValue;
};

extern D2ObeliskPowerUpStrc gaObeliskPowerUps[21]; // 0x00732EB0

struct D2PortalFlags00585580Strc
{
    unsigned char nFlags;
};

D2UnitStrc* __fastcall SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553720

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

D2UnitStrc* __fastcall D2GAME_CreateLinkPortal_6FD13B20(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPortal, unsigned char nDestLevel, int nSourceLevel); // 0x0056CF40

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __stdcall UNITS_SetObjectPortalFlags(D2UnitStrc* pUnit, unsigned char nPortalFlag); // 0x00622300

int __stdcall UNITS_CheckObjectPortalFlag(D2UnitStrc* pUnit, unsigned char nFlag); // 0x00622350

typedef void (__fastcall* PetIterateCallback)(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pPet, void* pArg);

void __fastcall D2GAME_UpdateAttribute_6FC822D0(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

unsigned char __fastcall OBJECTS_GetRegenerateMax(D2ObjectsTxt* pObjectsTxtRecord); // 0x00552AA0

unsigned char __fastcall OBJECTS_GetRegenerateSteps(); // 0x00552AB0

void __fastcall PLAYERPETS_IteratePets(D2GameStrc* pGame, D2UnitStrc* pPlayer, PetIterateCallback pCallback, void* pArg); // 0x00574DE0

int __fastcall D2GAME_NPC_RemoveStates_6FCCAF30(D2UnitStrc* pUnit); // 0x00578C20

void __fastcall OBJMODE_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pUnit2, void* pUnitHealed); // 0x005856A0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

D2TCExShortStrc* __stdcall DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(int nDifficulty, int nAct, int nTCIndex); // 0x00654E80

extern const int gnChestActLevelIds[10]; // 0x006E1988

D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00546FA0

D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality); // 0x00585B90

void __fastcall D2GAME_SHRINES_SkillBoost(D2SkillContext00583BF0Strc* pContext, D2Event00583BF0Strc* pEvent);

D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

struct D2SkillStrc;

struct D2StatListStrc;


typedef void(__fastcall* PlayerPetCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, void* pArg);

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);         // 0x006CC468

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                       // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

void __fastcall sub_0053D960_SendPacket0x63(D2ClientStrc* pClient, D2GSPacketSrv63* pPacket);               // 0x0053D960

void __fastcall QUESTS_HellPortalActChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nLevelId, D2UnitStrc* pObject); // 0x00546AC0

int __fastcall OBJECTS_GetUnitIdFromTimerArg(D2UnitStrc* pUnit);                                            // 0x00552B10

int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID);                     // 0x00554100

int __fastcall ITEMS_GetHealthPotionDropCode(D2UnitStrc* pUnit); // 0x00558450

int __fastcall ITEMS_GetManaPotionDropCode(D2UnitStrc* pUnit); // 0x005584C0

void __fastcall SUNIT_WarpPlayer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTile);                // 0x005550B0

int __fastcall D2GAME_DoKeyCheck_6FC4A4B0(D2GameStrc* pGame, D2UnitStrc* pPlayer);                          // 0x0055F140

void __fastcall D2GAME_SHRINES_Refill_6FC76730(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);   // 0x005828E0

void __fastcall OBJMODE_ClearSteegStoneGUID(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00584820

int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, unsigned short nState); // 0x005852E0

D2ActiveRoomStrc* __stdcall DUNGEON_FindActSpawnLocationEx(D2DrlgActStrc* pAct, int nLevelId, int a3, int* pX, int* pY, int nUnitSize); // 0x0061B060

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory);                                // 0x0063C1E0

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState);             // 0x0065C310

void __stdcall WAYPOINTS_ActivateWaypoint(D2WaypointDataStrc* pData, unsigned short wField);                // 0x00660EC0


#define EVENTTYPE_ENDANIM 1

#define EVENTTYPE_ACTIVESTATE 5


#define QFLAG_REWARDGRANTED 0

#define QFLAG_PRIMARYGOALDONE 13

struct D2ObjOperateStrc;

void __fastcall D2GAME_PACKETS_SendPacket0x0E_6FC3C8E0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char a6, int nAnimMode); // 0x0053B470

void __fastcall SCMD_SendUnitActionAtPosition(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0

void __fastcall SCMD_SendPortalState(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053D900

extern "C" const char gszObjModeSourceFile[]; // 0x006E1970

struct D2ObjOperateStrc
{
    D2GameStrc* game;
    D2UnitStrc* object;
    D2UnitStrc* player;
};

unsigned int __stdcall sub_00620510(D2UnitStrc*); // 0x00620510

int __stdcall SUNIT_Dummy_00582AC0(D2UnitStrc* pUnit, int nValue);

static void __stdcall OBJMODE_GetToHitPercentage(int* pToHit, int nSkillLevel, D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2UnitStrc* pWeapon); // 0x00583740

int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0

void __fastcall ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pObject); // 0x0059DD80

static int __stdcall OBJMODE_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer); // 0x00585240

#define D2_ASSERT(expr,line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PortalQuestStrc;

struct D2PortalQuestStrc
{
    int nQuest;
    int nExpansionQuest;
};

int __fastcall PLAYER_HasHostilePlayer(D2GameStrc*, D2UnitStrc*); // 0x00535B10

void __fastcall ACT5Q5_OnPortalClosed(D2GameStrc*, D2UnitStrc*); // 0x0058CF50

D2PortalQuestStrc* __fastcall DATATBLS_GetLevelDefRecord(int); // 0x0061E470

int __fastcall PLAYER_GetUniqueIdFromPlayerData(D2UnitStrc* pPlayer); // 0x005353F0

void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nSourceLevelId, int nDestinationLevelId, D2UnitStrc* pPlayer); // 0x00543B90

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B6C0

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

struct D2RoomCoordListStrc;

#define EVENTTYPE_TRAP 4

#define UNITFLAG_TARGETABLE 2


struct D2MonRegDataStrc;

struct D2MonsterRegionStrc;

struct D2MonStatsCountStrc;

int __fastcall OBJRGN_GetTrapMonsterId(D2ObjOperateFnStrc* pOp); // 0x005474C0

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0

void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* pUnit, int nUnitId); // 0x00552AF0

void __fastcall StartModeID(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SkillStrc* pSkill, int nMode, int nUnitType, int nTargetGUID, int bAllowReEnter); // 0x00580A70

D2UnitStrc* __fastcall MONSTERUNIQUE_SpawnUniqueGroup(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pRoomCoordList, int nClassId, int bAllowChampion, unsigned short nX, unsigned short nY, int bAvoidWarps); // 0x005A43E0

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLevelVariantAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

int __stdcall SKILLS_GetSkillMode(D2SkillStrc* pSkill); // 0x00644360

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

struct D2SfxStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pObject;
    D2UnitStrc* pOwner;
};

struct D2SfxArgStrc
{
    int unk, nDamagePct, nRadius;
};

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pFind, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnTest, D2UnitFindArgStrc* pArg); // 0x0065A950

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pFind); // 0x0065AA00

int __fastcall OBJMODE_IsLivingPlayerOrMonster(D2UnitStrc* unit, void* unused); // 0x00582710


struct D2InventoryStrc;

extern int gnShrineTableCount;                                                                     // 0x00732EAC

int __stdcall UNITS_GetAttackRate(D2UnitStrc* pAttacker);                                                   // 0x00622560

D2UnitStrc* __stdcall D2Common_10434(D2UnitStrc* pUnit, int a2);                                            // 0x00623990

int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0

extern "C" void _ReadWriteBarrier();

#pragma intrinsic(_ReadWriteBarrier)

D2TimerArgStrc* __fastcall UNITS_GetTimerArg(D2UnitStrc* pUnit); // 0x006234F0

static int __stdcall OBJMODE_IsTrapMonsterAllowed(D2ActiveRoomStrc* pRoom, int nMonsterId);

static void D2GAME_SpawnTrapMonster_6FC75B40(D2ObjOperateFnStrc* pOp, int nMonsterId, int nAnimMode);

void __fastcall D2GAME_OBJECTS_TrapHandler8_9_6FC75AC0(D2GameStrc* pGame, D2UnitStrc* pUnit);

static void __stdcall D2GAME_SetTrapCallback_6FC764B0(unsigned char nTrapType, D2ObjOperateFnStrc* pOp);

int __fastcall OBJECTS_OperateFunction51_JungleStash(D2ObjOperateFnStrc* pOp, int nOperate);

int __fastcall OBJECTS_OperateFunction01_Casket(D2ObjOperateFnStrc* pOp, int nOperate);

int __fastcall OBJECTS_OperateFunction68_EvilUrn(D2ObjOperateFnStrc* pOp, int nOperate);

int __fastcall OBJECTS_OperateFunction03_Urn_Basket_Jar(D2ObjOperateFnStrc* pOp, int nOperate);

int __fastcall OBJECTS_OperateFunction14_Corpse(D2ObjOperateFnStrc* pOp, int nOperate);

int __fastcall OBJECTS_OperateFunction05_Barrel(D2ObjOperateFnStrc* pOp, int nOperate);

unsigned char __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit); // 0x005540D0

void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient);                       // 0x00571740

D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality); // 0x00585970

int __fastcall OBJECTS_OperateFunction27_TeleportPad(D2ObjOperateFnStrc* pOp, int nOperate);

void __fastcall D2GAME_SHRINES_Gem(D2ObjOperateFnStrc* pOp, int nOperate);

void __fastcall D2GAME_SHRINES_CombatBoost_6FC77690(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);

void __fastcall D2GAME_SHRINES_Stamina_6FC779C0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);

void __fastcall D2GAME_SHRINES_DefensiveBoost_6FC77AE0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord);

static int OBJMODE_ExplodeBarrel(D2ObjOperateFnStrc* pOp);

void __fastcall OBJMODE_UpdateTrappedSoul(D2GameStrc* pGame, D2UnitStrc* pObject);

static void __stdcall OBJMODE_DamagePlayersInRange(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00581680

void __fastcall OBJMODE_UpdateTrapProximity(D2GameStrc* pGame, D2UnitStrc* pObject);

void __fastcall sub_0045D0A0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

void __fastcall sub_0045D0B0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

void __fastcall sub_0045D0C0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

void __fastcall sub_0045D0D0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

void __fastcall sub_0045D0E0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

void __fastcall sub_0045D130_PacketNop(const unsigned char* pPacket)
{
}

void __fastcall sub_0045D140_PacketNop(const unsigned char* pPacket)
{
}

void __fastcall sub_0045D150_PacketNop(const unsigned char* pPacket)
{
}

inline void SetUnitFlagMask(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

inline int UNIT_GetAnimMode(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwAnimMode;
    }
    return 0;
}

int __stdcall ENVIRONMENT_GetPeriodOfDayFromAct(D2DrlgActStrc* pAct, int* pBaseTime); // 0x0061C100

static inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00581250
void __fastcall OBJMODE_ObjectTimer_Light(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nMode = !pObject ? 0 : pObject->dwAnimMode;
    if (pObject && pObject->dwClassId == 0x18F)
    {
        switch ((unsigned short)nMode)
        {
        case 0:
        case 2:
        {
            D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + (unsigned int)SEED_RollRandomNumber(&pObjectControl->pSeed) % 250 + 25, 0, 0);
            UNITS_ChangeAnimMode(pObject, 1);
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
            EVENT_SetEvent(pGame, pObject, 1, (pObjectsTxt->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            break;
        }
        }
        return;
    }

    switch (ENVIRONMENT_GetPeriodOfDayFromAct(pGame->pAct[0], 0))
    {
    case 0:
        if ((unsigned short)nMode == 2 || (unsigned short)nMode == 1)
        {
            UNITS_ChangeAnimMode(pObject, 0);
        }
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 1000, 0, 0);
        return;

    case 1:
    case 2:
    case 3:
        if (!(unsigned short)nMode)
        {
            UNITS_ChangeAnimMode(pObject, 1);
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
            EVENT_SetEvent(pGame, pObject, 1, (pObjectsTxt->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
        }
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 1000, 0, 0);
        return;

    default:
        EVENT_SetEvent(pGame, pObject, 8, pGame->dwGameFrame + 600, 0, 0);
        return;
    }
}

struct D2PortalFlags00581410Strc;

struct D2PortalFlags00581410Strc
{
    unsigned char nFlags;
};

// 0x00581410
void __fastcall OBJMODE_OpenLinkPortal(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    int nPortalLevel = 0x7F;
    switch (nLevelId)
    {
    case LEVEL_ID_ACT5_BARRICADE_1:
        nPortalLevel = 0x7D;
        break;
    case LEVEL_ARREATPLATEAU:
        nPortalLevel = 0x7E;
        break;
    }
    D2UnitStrc* pPortal = D2GAME_CreateLinkPortal_6FD13B20(pGame, 0, pUnit, nPortalLevel, nLevelId);
    if (pPortal)
    {
        D2PortalFlags00581410Strc tFlags;
        tFlags.nFlags = UNITS_GetObjectPortalFlags(pPortal) | 3;
        UNITS_SetObjectPortalFlags(pPortal, tFlags.nFlags);
    }
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pUnit), 0);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pPortal), 0);
}

// 0x00581490
void __fastcall OBJMODE_CompleteObjectAnimation(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && (unsigned short)pObject->dwAnimMode == OBJMODE_OPERATING)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pObject->dwClassId);
        if (pObjectsTxtRecord->nMode[2])
        {
            pObject->dwAnimMode = OBJMODE_OPENED;
            if (!pObjectsTxtRecord->nHasCollision[2])
            {
                UNITS_FreeCollisionPath(pObject);
            }
        }
    }
}

// 0x005817A0
void __fastcall OBJMODE_DispatchTrap(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject));
    const unsigned char nTrapType = pObject->pObjectData->InteractType & 0x7F;
    if (nTrapType >= gnObjectTrapHandlers_00732D14)
    {
        return;
    }

    if (nTrapType == 8)
    {
        if (nLevelId >= 75)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)sgObjectTrapHandlers[2]), 0x161);
            sgObjectTrapHandlers[2](pGame, pObject);
            return;
        }
    }
    else if (nTrapType == 3)
    {
        if (nLevelId < 40 && nLevelId != LEVEL_TOWERCELLARLEV5)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)sgObjectTrapHandlers[2]), 0x16C);
            sgObjectTrapHandlers[2](pGame, pObject);
            return;
        }
    }
    else if ((nTrapType == 1 || nTrapType == 4) && nLevelId < 40)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)sgObjectTrapHandlers[2]), 0x176);
        sgObjectTrapHandlers[2](pGame, pObject);
        return;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)sgObjectTrapHandlers[nTrapType]), 0x17B);
    sgObjectTrapHandlers[nTrapType](pGame, pObject);
}

inline D2HoverTextStrc* UNIT_GetHoverText(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->pHoverText;
    }

    return 0;
}

inline void UNIT_SetHoverText(D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText)
{
    if (pUnit)
    {
        pUnit->pHoverText = pHoverText;
    }
}

static __forceinline D2BitBufferStrc* PLAYER_GetQuestFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

inline D2WaypointDataStrc* PLAYER_GetWaypointFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pWaypointData[pGame->nDifficulty];
}

// 0x00581510
void __fastcall OBJMODE_RegenerateWell(D2GameStrc* pGame, D2UnitStrc* pObject)
{

    unsigned char nLeft = pObject->pObjectData->InteractType;
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pObject);
    if (nLeft / pObjectsTxtRecord->dwParm[2] >= OBJECTS_GetRegenerateSteps())
    {
        D2_ASSERT(nLeft / pObjectsTxtRecord->dwParm[2] < OBJECTS_GetRegenerateSteps(), 220);
    }
    else
    {
        const unsigned char nNewLeft = nLeft + 1;
        pObject->pObjectData->InteractType = nNewLeft;

        if (OBJECTS_GetRegenerateMax(pObjectsTxtRecord) - nLeft < 0)
        {
            pObject->pObjectData->InteractType = OBJECTS_GetRegenerateMax(pObjectsTxtRecord);
            D2_ASSERT(OBJECTS_GetRegenerateMax(pObjectsTxtRecord) - nLeft >= 0, 227);
        }
        else
        {
            const unsigned char nMax = OBJECTS_GetRegenerateMax(pObjectsTxtRecord);
            if (nNewLeft <= nMax && !(nNewLeft % (unsigned char)(nMax / OBJECTS_GetRegenerateSteps())))
            {
                UNITS_ChangeAnimMode(pObject, OBJECTS_GetRegenerateSteps() - nNewLeft / pObjectsTxtRecord->dwParm[2]);
            }

            UNITROOM_RefreshUnit(pObject);
            pObject->dwFlags |= UNITFLAG_DOUPDATE;
        }
    }
}

// 0x00581620
void __fastcall OBJMODE_ExpireHoverText(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (!pObject)
    {
        return;
    }

    D2HoverTextStrc* pHoverText = pObject->pHoverText;
    if (pHoverText)
    {
        const unsigned int nTimeout = CHAT_GetTimeoutFromHoverMsg(pHoverText);
        if (nTimeout <= pGame->dwGameFrame)
        {
            CHAT_FreeHoverMsg(pGame->pMemoryPool, pHoverText);
            pObject->pHoverText = 0;
            UNITROOM_RefreshUnit(pObject);
            pObject->dwFlags |= UNITFLAG_HASTXTMSG;
        }
        else
        {
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_FREEHOVER, nTimeout, 0, 0);
        }
    }
}

// 0x00581680
static void __stdcall OBJMODE_DamagePlayersInRange(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    D2CoordStrc tCoord;
    UNITS_GetCoords(pObject, &tCoord);
    for (D2UnitStrc* i = pRoom->pUnitFirst; i; i = i->ptRoomNext)
    {
        const int nType = (i ? i->dwUnitType : UNIT_INVALID);
        const int nMode = (i ? i->dwAnimMode : 0);
        if (nType == UNIT_PLAYER && nMode != PLRMODE_DEAD && DRLG_UnitEdgeDistance(pObject, i) <= pObjectsTxtRecord->dwParm[0] + 1)
        {
            OBJEVAL_ApplyTrapObjectDamage(pGame, pObject, i, 1);
        }
    }
}

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x00581700
void __fastcall OBJMODE_UpdateTrapProximity(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (pObject && pObject->dwAnimMode == OBJMODE_OPERATING)
    {
        pObject->dwAnimMode = 2;
    }

    D2ObjectControlStrc* pObjectControl = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
    OBJMODE_DamagePlayersInRange(pGame, pObject);
    EVENT_SetEvent(pGame, pObject, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + SEED_RollRandomNumber_Inline(&pObjectControl->pSeed) % 35 + 15, 0, 0);
}

// 0x005818B0
void __fastcall D2GAME_SpikeTraps_6FC74F60(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    int nAnimMode = !pObject ? 0 : pObject->dwAnimMode;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);

    int bArmed = 0;
    switch (pObject->pObjectData->InteractType)
    {
    case 1:
        bArmed = 1;
    case 0:
    {
        D2CoordStrc tCoord;
        UNITS_GetCoords(pObject, &tCoord);

        int bWarningTriggered = 0;
        int bDamageTriggered = 0;
        D2UnitStrc* pUnit = pRoom->pUnitFirst;
        if (pUnit)
        {
            do
            {
                const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
                const int nUnitMode = pUnit ? pUnit->dwAnimMode : 0;
                if (nUnitType == 0 && nUnitMode != 17 && DRLG_UnitEdgeDistance(pObject, pUnit) <= 0)
                {
                    if (bArmed)
                    {
                        OBJEVAL_ApplyTrapObjectDamage(pGame, pObject, pUnit, 0);
                        bDamageTriggered = 1;
                    }
                    else
                    {
                        SUNIT_AttachSound(pObject, 13, 0);
                        bWarningTriggered = 1;
                    }
                }

                pUnit = pUnit->ptRoomNext;
            }
            while (pUnit);

            if (bWarningTriggered)
            {
                pObject->pObjectData->InteractType = 1;
                EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 25, 0, 0);
                return;
            }
        }

        if (bArmed)
        {
            if (bDamageTriggered == 1)
            {
                pObject->pObjectData->InteractType = 2;
                UNITS_ChangeAnimMode(pObject, 1);
            }
            else
            {
                pObject->pObjectData->InteractType = 0;
            }

            EVENT_SetEvent(pGame, pObject, 3, (DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId)->dwFrameCnt[1] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            return;
        }
        break;
    }
    case 2:
        if (nAnimMode)
        {
            UNITS_ChangeAnimMode(pObject, 0);
            pObject->pObjectData->InteractType = 0;
        }
        EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 15, 0, 0);
        return;
    }

    EVENT_SetEvent(pGame, pObject, 3, pGame->dwGameFrame + 15, 0, 0);
}

// 0x00581A10
void __fastcall OBJMODE_HandleQuestObjectEvent(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    QUESTS_ObjectEvents(pGame, pObject);
}

// 0x005814D0
void __fastcall OBJMODE_ResetShrine(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (UNITS_IsShrine(pObject))
    {
        UNITROOM_RefreshUnit(pObject);
        SetUnitFlagMask(pObject, UNITFLAG_DOUPDATE);
        UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
        pObject->pObjectData->dwOperateGUID = 0;
    }
}

// 0x00586850
void __fastcall OBJMODE_DropJungleStashItems(D2GameStrc* pGame, D2UnitStrc* pUnit)
{

    D2ObjOperateFnStrc op;
    op.pGame = pGame;
    op.hObject = pUnit;
    op.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pUnit));
    op.hPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, OBJECTS_GetUnitIdFromTimerArg(pUnit));
    OBJMODE_DropFromChestTCWithQuality(&op, 0);
}

// 0x00581A20
void __fastcall OBJMODE_SendObjectModeAndShrineUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x0E_6FC3C8E0(pClient, 0x0E, UNIT_OBJECT, !pUnit ? -1 : pUnit->dwUnitId, 3, !pUnit ? 0 : (pUnit->dwFlags >> 1) & 1, (unsigned short)pUnit->dwAnimMode);

    const unsigned char nSubClass = DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId)->nSubClass;
    if (nSubClass)
    {
        if (nSubClass & 4)
        {
            SCMD_SendPortalState(pClient, pUnit);
        }
        else if (pUnit->dwAnimMode == 1 && nSubClass & 1)
        {
            const D2ShrinesTxt* const pShrineTxt = UNITS_GetShrineTxtRecordFromObject(pUnit);
            unsigned char nCode = 0;
            if (pShrineTxt)
            {
                nCode = pShrineTxt->bCode;
            }

            const int nOperateGUID = pUnit->pObjectData->dwOperateGUID;
            if (nOperateGUID)
            {
                SCMD_SendUnitActionAtPosition(pClient, 2, !pUnit ? -1 : pUnit->dwUnitId, 0, 0, nOperateGUID - 1, 0, nCode, 0);
            }
        }
    }
}

#define UNITFLAG_HASEVENTSOUND 0x00000400

void __fastcall SUNITMSG_SendHoverText(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620

void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg); // 0x00597890

void __fastcall SUNITMSG_SendQueuedMessages(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0

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

// 0x00581AD0
void __fastcall OBJMODE_SendObjectUpdates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (pUnit)
    {
        if (UNIT_HasFlag(pUnit, UNITFLAG_DOUPDATE))
        {
            OBJMODE_SendObjectModeAndShrineUpdate(pUnit, pClient);
        }

        if (UNIT_HasFlag(pUnit, UNITFLAG_HASEVENTSOUND))
        {
            D2GAME_UpdateUnit_6FCC6080(pUnit, pClient);
        }

        if (UNIT_HasFlag(pUnit, UNITFLAG_HASTXTMSG))
        {
            SUNITMSG_SendHoverText(pUnit, pClient);
        }

        if (UNIT_HasFlagEx(pUnit, UNITFLAGEX_HASINV))
        {
            D2GAME_INVMODE_First_6FC40FB0(pGame, pUnit, pClient, 0);
        }
    }

    SUNITMSG_SendQueuedMessages(pUnit, pClient);
}

// 0x00581B50
static void OBJMODE_TeleportToUnit(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ActiveRoomStrc* pRoom)
{
    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);
    if (COLLISION_GetFreeCoordinates(pRoom, &tCoord, 3, 0x1C09, 0) && SUNIT_TeleportUnit(SUNIT_GetGameFromUnit(pPlayer), pPlayer, pRoom, tCoord.nX, tCoord.nY, 0, 0))
    {
        D2DrlgCoordsStrc tRoomCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(UnitGetClient(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 865), DUNGEON_GetLevelIdFromRoom(pRoom), tRoomCoords.nTileXPos, tRoomCoords.nTileYPos);
        UNITROOM_RefreshUnit(pPlayer);
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= UNITFLAGEX_TELEPORTED;
        }
    }
}

// 0x00585120
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseMana(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    const int nNewValue = (nValue << 8) + STATLIST_GetMaxManaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nNewValue, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXMANA, nNewValue, 0);
    return 1;
}

// 0x00585160
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseEnergy(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 1, nValue, 0);
    return 1;
}

// 0x00585180
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseDexterity(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 2, nValue, 0);
    return 1;
}

// 0x005851A0
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseVitality(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 3, nValue, 0);
    return 1;
}

// 0x005851C0
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseStrength(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 0, nValue, 0);
    return 1;
}

static inline unsigned int GetAnimMode(D2UnitStrc* unit) { if(!unit) return 0; return unit->dwAnimMode; }

// 0x005851E0
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseHitpoints(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    const int nNewValue = (nValue << 8) + STATLIST_GetMaxLifeFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewValue, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MAXHP, nNewValue, 0);
    return 1;
}

// 0x00585220
int __fastcall OBJMODE_ObeliskPowerUp_IncreaseSkillpoints(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    sub_006272B0_UnitStatListCall(pUnit, 5, nValue, 0);
    return 1;
}

// 0x005856A0
void __fastcall OBJMODE_PetIterate_Heal(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pUnit2, void* pUnitHealed)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit2, STAT_HITPOINTS, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit2);
    if (nHitpoints < nMaxHp)
    {
        STATLIST_SetUnitStat(pUnit2, STAT_HITPOINTS, nMaxHp, 0);
        *(unsigned char*)pUnitHealed = 1;
    }

    D2StatListStrc* pPoisonStatList = STATLIST_GetStatListFromUnitAndState(pUnit2, STATE_POISON);
    if (pPoisonStatList)
    {
        D2Common_10474(pUnit2, pPoisonStatList);
        STATLIST_FreeStatList(pPoisonStatList);
    }

    D2StatListStrc* pFreezeStatList = STATLIST_GetStatListFromUnitAndState(pUnit2, STATE_FREEZE);
    if (pFreezeStatList)
    {
        D2Common_10474(pUnit2, pFreezeStatList);
        STATLIST_FreeStatList(pFreezeStatList);
    }

    D2GAME_NPC_RemoveStates_6FCCAF30(pUnit2);
}

// 0x00585720
static int __stdcall OBJMODE_WellHeal(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ObjectsTxt* pObjectsTxtRecord)
{
    int bUsed = 0;

    const unsigned int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer);
    const unsigned int nLife = STATLIST_UnitGetStatValue(pPlayer, STAT_HITPOINTS, 0);
    const int nFlags = pObjectsTxtRecord->dwParm[3];
    if (nLife < nMaxLife && (nFlags & 2))
    {
        unsigned int nNewLife = nLife + (nMaxLife * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewLife > nMaxLife)
        {
            nNewLife = nMaxLife;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nNewLife, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_HITPOINTS, nNewLife, pPlayer);
        bUsed = 1;
    }

    const unsigned int nMaxMana = STATLIST_GetMaxManaFromUnit(pPlayer);
    const unsigned int nMana = STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0);
    if (nMana < nMaxMana && (nFlags & 1))
    {
        unsigned int nNewMana = nMana + (nMaxMana * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewMana > nMaxMana)
        {
            nNewMana = nMaxMana;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_MANA, nNewMana, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_MANA, nNewMana, pPlayer);
        bUsed = 1;
    }

    const unsigned int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pPlayer);
    const unsigned int nStamina = STATLIST_UnitGetStatValue(pPlayer, STAT_STAMINA, 0);
    if (nStamina < nMaxStamina)
    {
        unsigned int nNewStamina = nStamina + (nMaxStamina * pObjectsTxtRecord->dwParm[1] >> 8);
        if (nNewStamina > nMaxStamina)
        {
            nNewStamina = nMaxStamina;
        }
        STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, nNewStamina, 0);
        D2GAME_UpdateAttribute_6FC822D0(pPlayer, STAT_STAMINA, nNewStamina, pPlayer);
        bUsed = 1;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, STATE_POISON);
    if (pStatList)
    {
        D2Common_10474(pPlayer, pStatList);
        STATLIST_FreeStatList(pStatList);
        bUsed = 1;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pPlayer, STATE_FREEZE);
    if (pStatList)
    {
        D2Common_10474(pPlayer, pStatList);
        STATLIST_FreeStatList(pStatList);
        bUsed = 1;
    }

    if (D2GAME_NPC_RemoveStates_6FCCAF30(pPlayer))
    {
        bUsed = 1;
    }

    PLAYERPETS_IteratePets(pGame, pPlayer, OBJMODE_PetIterate_Heal, &bUsed);
    return bUsed;
}

// 0x00585970
D2UnitStrc* __fastcall OBJMODE_DropItemWithCodeAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwCode, int nItemQuality)
{

    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    if (nItemId != -1)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pUnit, &pCoord);

        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.wItemFormat = pGame->wItemFormat;
            itemDrop.nId = nItemId;
            itemDrop.pUnit = pUnit;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pGame;
            itemDrop.nSpawnType = 3;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = nItemQuality;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

            return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
        }
    }

    return 0;
}

// 0x00585A80
D2UnitStrc* __fastcall OBJMODE_DropItemWithIdAndQuality(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemId, int nItemQuality)
{
    if (nItemId < 0)
    {
        return 0;
    }

    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);

    D2CoordStrc pReturnCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pUnit), &pCoord, &pReturnCoords, 1, 1);
    if (!pRoom)
    {
        return 0;
    }

    D2ItemDropStrc itemDrop;
    memset(&itemDrop, 0, sizeof(itemDrop));
    itemDrop.wItemFormat = pGame->wItemFormat;
    itemDrop.nId = nItemId;
    itemDrop.pUnit = pUnit;
    itemDrop.pSeed = 0;
    itemDrop.pGame = pGame;
    itemDrop.nSpawnType = 3;
    itemDrop.nX = pReturnCoords.nX;
    itemDrop.nY = pReturnCoords.nY;
    itemDrop.pRoom = pRoom;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.nQuality = nItemQuality;
    itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pUnit, 0);

    return D2GAME_CreateItemEx_6FC4ED80(pGame, &itemDrop, 0);
}

// 0x00583C70
int __fastcall OBJECTS_OperateFunction02_Shrine(D2ObjOperateFnStrc* pOp, int nOperate)
{

    D2UnitStrc* pPlayer = pOp->hPlayer;
    D2UnitStrc* pObject = pOp->hObject;
    D2ObjectDataStrc* pObjectData = pObject->pObjectData;

    if (pObjectData->dwOperateGUID)
    {
        return 0;
    }

    if (pObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        return 0;
    }

    pObjectData->dwOperateGUID = (!pPlayer ? -1 : pPlayer->dwUnitId) + 1;
    UNITROOM_RefreshUnit(pObject);

    pObject->dwFlags |= UNITFLAG_DOUPDATE;
    UNITS_ChangeAnimMode(pObject, OBJMODE_OPERATING);

    D2HoverTextStrc* pOldHoverText = UNIT_GetHoverText(pOp->hObject);
    if (pOldHoverText)
    {
        CHAT_FreeHoverMsg(pOp->pGame->pMemoryPool, pOldHoverText);
    }

    char szText[20];
// build: symbol ?gszFormatD@* 0x006D57BC
    wsprintfA(szText, gszFormatD, (unsigned short)(pOp->hObject->pObjectData->InteractType + 3683));

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(pOp->pGame->pMemoryPool, szText, pOp->pGame->dwGameFrame);
    if (pHoverText)
    {
        UNIT_SetHoverText(pOp->hObject, pHoverText);
        UNITROOM_RefreshUnit(pOp->hObject);
        SetUnitFlagMask(pOp->hObject, UNITFLAG_HASTXTMSG);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_FREEHOVER, pOp->pGame->dwGameFrame + 300, 0, 0);
    }

    D2ShrinesTxt* pShrinesTxtRecord = UNITS_GetShrineTxtRecordFromObject(pObject);

    const int nId = pShrinesTxtRecord->bCode;
    if (nId >= 0 && nId < gnShrineTableCount && sgcptShrineChart[nId].pfShrineCallback)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)sgcptShrineChart[nId].pfShrineCallback), 2653);
        sgcptShrineChart[nId].pfShrineCallback(pOp, pShrinesTxtRecord);
    }
    else
    {
        D2GAME_SHRINES_Refill_6FC76730(pOp, pShrinesTxtRecord);
    }

    if (pShrinesTxtRecord->nResetTimeInMins)
    {
        EVENT_SetEvent(pOp->pGame, pObject, EVENTTYPE_ACTIVESTATE, 1200 * pShrinesTxtRecord->nResetTimeInMins + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    if (pObject->dwAnimMode == OBJMODE_OPERATING)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        if (!pObjectsTxtRecord->nCycleAnim[1] && pObjectsTxtRecord->nMode[2])
        {
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
    }

    return 1;
}

#define EVENTTYPE_QUESTFN 7

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest); // 0x005540A0

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130

D2UnitStrc* __fastcall D2GAME_DropArmor_6FC4F830(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x005594C0

D2UnitStrc* __fastcall D2GAME_DropWeapon_6FC4FA50(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, int a4, int a5, D2UnitStrc* pUnit); // 0x00559630

int __stdcall UNITS_IsObjectInInteractRange(D2UnitStrc* pUnit, D2UnitStrc* pObject); // 0x00623660

// 0x00583E70
int __fastcall OBJECTS_OperateFunction33_WirtsBody(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        pOp->hObject->dwDropItemCode = ' gel';

        int nItemLevel;
        if (D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0))
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);

            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_QUESTFN, pOp->pGame->dwGameFrame + 10, 0, 0);
        }
    }

    return 1;
}

// 0x00586B30
int __fastcall OBJMODE_GetSuperUniqueId(unsigned int nIndex)
{
    if (nIndex <= 65)
    {
        return sgptDataTables->nSuperUniqueIds[nIndex];
    }

    return -1;
}

// 0x00581D40
int __fastcall OBJECTS_OperateFunction08_Door(D2ObjOperateStrc* context,int unused)
{
 D2ActiveRoomStrc* room=UNITS_GetRoom(context->object);
 D2CoordStrc coords;
 UNITS_GetCoords(context->object,&coords);
 unsigned int sizeX=sub_00620510(context->object);
 unsigned int sizeY=UNITS_GetUnitSizeY(context->object);
 unsigned int tick=GetTickCount();
 unsigned int mode=GetAnimMode(context->object);
 if(tick<context->object->dwTickCount+500) return 1;
 switch(mode) {
 case 6:
  if(!D2GAME_DoKeyCheck_6FC4A4B0(context->game,context->player)) {
   SUNIT_AttachSound(context->player,22,context->player);
   return 1;
  }
 case 0:
  UNITS_FreeCollisionPath(context->object);
  UNITS_ChangeAnimMode(context->object,2);
  context->object->dwTickCount=tick;
  return 1;
 case 2:
 case 5:
  if(!COLLISION_CheckMaskWithSizeXY(room,coords.nX,coords.nY,sizeX,sizeY,0x8180)) {
   UNITS_BlockCollisionPath(context->object,room,coords.nX,coords.nY);
   UNITS_ChangeAnimMode(context->object,0);
   context->object->dwTickCount=tick;
   return 1;
  }
  if(!COLLISION_CheckMaskWithSizeXY(room,coords.nX,coords.nY,sizeX,sizeY,0x8000)) {
   if(mode!=5) {
    UNITS_ChangeAnimMode(context->object,5);
    context->object->dwTickCount=tick;
    break;
   }
  } else {
   UNITS_ChangeAnimMode(context->object,4);
   context->object->dwTickCount=tick;
   return 1;
  }
 }
 return 1;
}

// 0x00581EB0
int __fastcall OBJECTS_OperateFunction16_TrapDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->hObject, &pCoord);
    const int nSizeX = UNITS_GetUnitSizeX(pOp->hObject);
    const int nSizeY = UNITS_GetUnitSizeY(pOp->hObject);

    switch (!pOp->hObject ? 0 : pOp->hObject->dwAnimMode)
    {
    case OBJMODE_NEUTRAL:
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
        break;

    case OBJMODE_OPENED:
    {
        D2UnitStrc* hUnit = UNITS_GetRoom(pOp->hObject)->pUnitFirst;
        while (hUnit && hUnit->dwUnitType != UNIT_TILE)
        {
            hUnit = hUnit->ptRoomNext;
        }

        D2_ASSERT(hUnit, 1038);

        SUNIT_WarpPlayer(pOp->pGame, pOp->hPlayer, hUnit);
        return 1;
    }
    }

    return 1;
}

// 0x00581F60
int __fastcall OBJECTS_OperateFunction47_Stair(D2ObjOperateFnStrc* pOp)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
    D2CoordStrc coords;
    UNITS_GetCoords(pOp->hObject, &coords);
    UNITS_GetUnitSizeX(pOp->hObject);
    UNITS_GetUnitSizeY(pOp->hObject);
    switch (!pOp->hObject ? 0 : pOp->hObject->dwAnimMode)
    {
    case 0:
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        {
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxt->dwFrameCnt[1] >> 8) + 1, 0, 0);
        }
        break;
    case 2:
        {
            D2UnitStrc* pTile = pRoom->pUnitFirst;
            while (pTile)
            {
                if ((!pTile ? 6 : pTile->dwUnitType) == 5) goto found;
                pTile = pTile->ptRoomNext;
            }
            D2ActiveRoomStrc** ppRooms;
            unsigned int nRooms;
            DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
            unsigned int i = 0;
            if (i >= nRooms) goto done;
            do
            {
                if (ppRooms[i] != pRoom)
                {
                    pTile = ppRooms[i]->pUnitFirst;
                    while (pTile)
                    {
                        if ((!pTile ? 6 : pTile->dwUnitType) == 5) goto found;
                        pTile = pTile->ptRoomNext;
                    }
                }
            } while (++i < nRooms);
            return 1;
        found:
            SUNIT_WarpPlayer(pOp->pGame, pOp->hPlayer, pTile);
            return 1;
        }
        break;
    }
done:
    return 1;
}

// 0x005825B0
static int OBJMODE_HasItemOfType(D2UnitStrc* pUnit, int nItemType)
{
    D2_ASSERT(pUnit->pInventory, 1747);
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (ITEMSIsA(pCheckedItem, nItemType))
        {
            return 1;
        }
    }
    return 0;
}

// 0x00582610
int __fastcall OBJECTS_OperateFunction17_Obelisk(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pOp->pGame, pOp->hPlayer);
    D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, ".\\OBJECTS\\ObjMode.cpp", 1772);
    const int nAnimMode = !pOp->hObject ? 0 : pOp->hObject->dwAnimMode;
    if (nAnimMode)
    {
        if (nAnimMode == OBJMODE_SPECIAL1 && pInteractUnit == pOp->hObject)
        {
            SUNIT_ResetInteractInfo(pOp->hPlayer);
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
            return 1;
        }
        return 1;
    }

    if (PLAYER_IsBusy(pOp->hPlayer) == 1)
    {
        return 1;
    }

    if (!OBJMODE_HasItemOfType(pOp->hPlayer, ITEMTYPE_GEM))
    {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 1;
    }

    SUNIT_SetInteractInfo(pOp->hPlayer, UNIT_OBJECT, !pOp->hObject ? -1 : pOp->hObject->dwUnitId);
    UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_SPECIAL1);

    D2GSPacketSrv58 packet58;
    packet58.nHeader = 0x58;
    const int nUnitId = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
    packet58.nUnitId = nUnitId;
    packet58.nAction = 0;
    D2GAME_SendPacket0x58(pClient, &packet58);
    return 1;
}

// 0x00582710
int __fastcall OBJMODE_IsLivingPlayerOrMonster(D2UnitStrc* unit, void* unused)
{
    int result = 1;
    if (!unit)
        result = 0;
    else if (unit->dwUnitType == UNIT_MONSTER)
    {
        if (MONSTERS_IsDead(unit))
            result = 0;
    }
    else if (unit->dwUnitType != UNIT_PLAYER || !unit->dwAnimMode || unit->dwAnimMode == 17)
        result = 0;
    return result;
}

// 0x00582860
void __fastcall D2GAME_SHRINES_Health_6FC766B0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nDiff = STATLIST_GetMaxLifeFromUnit(pOp->hPlayer) - STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_HITPOINTS, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pOp->hPlayer, STAT_HITPOINTS, nDiff, 0);
    }
}

// 0x005828A0
void __fastcall D2GAME_SHRINES_FillMana_6FC766F0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nDiff = STATLIST_GetMaxManaFromUnit(pOp->hPlayer) - STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_MANA, 0);
    if (nDiff)
    {
        STATLIST_AddUnitStat(pOp->hPlayer, STAT_MANA, nDiff, 0);
    }
}

// 0x005828E0
void __fastcall D2GAME_SHRINES_Refill_6FC76730(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nHpDiff = STATLIST_GetMaxLifeFromUnit(pOp->hPlayer) - STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_HITPOINTS, 0);
    if (nHpDiff)
    {
        STATLIST_AddUnitStat(pOp->hPlayer, STAT_HITPOINTS, nHpDiff, 0);
    }

    const int nManaDiff = STATLIST_GetMaxManaFromUnit(pOp->hPlayer) - STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_MANA, 0);
    if (nManaDiff)
    {
        STATLIST_AddUnitStat(pOp->hPlayer, STAT_MANA, nManaDiff, 0);
    }
}

// 0x00582940
void __fastcall D2GAME_SHRINES_ExchangeHealth_6FC76790(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nHitpoints = STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_HITPOINTS, 0) >> 8;
    const unsigned int nValue = pShrinesTxtRecord->dwArg0 * (unsigned int)nHitpoints / 100 << 8;
    STATLIST_AddUnitStat(pOp->hPlayer, STAT_HITPOINTS, -(int)nValue, 0);
    STATLIST_AddUnitStat(pOp->hPlayer, STAT_MANA, nValue * pShrinesTxtRecord->dwArg1 / 100, 0);
}

// 0x005829A0
void __fastcall D2GAME_SHRINES_ExchangeMana_6FC767F0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nMana = STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_MANA, 0);
    const unsigned int nValue = pShrinesTxtRecord->dwArg0 * (unsigned int)nMana / 100;
    STATLIST_AddUnitStat(pOp->hPlayer, STAT_MANA, -(int)nValue, 0);
    STATLIST_AddUnitStat(pOp->hPlayer, STAT_HITPOINTS, nValue * pShrinesTxtRecord->dwArg1 / 100, 0);
}

// 0x00582A00
void __fastcall D2GAME_SHRINES_Enirhs_6FC76850(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    char* szName = UNITS_GetPlayerData(pOp->hPlayer)->szName;
    if (szName)
    {
        strncpy(szName, _strrev(szName), 16);
    }
}

// 0x00582A30
void __fastcall D2GAME_SHRINES_Portal_6FC76880(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hPlayer);

    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->hPlayer, &pCoord);

    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    const int nTownId = DUNGEON_GetTownLevelIdFromActNo(nAct);

    if (COLLISION_GetFreeCoordinates(UNITS_GetRoom(pOp->hPlayer), &pCoord, 3, 0x1C09, 0))
    {
        D2GAME_CreatePortalObject_6FD13DF0(pOp->pGame, pOp->hPlayer, pRoom, pCoord.nX + 5, pCoord.nY + 5, nTownId, 0, OBJECT_TOWN_PORTAL, 0);
    }
}

// 0x00582AC0
static int __stdcall OBJMODE_DropShrineGem(D2UnitStrc* pItem, int nItemId, D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    int bResult = 0;
    D2CoordStrc tCoords;
    UNITS_GetCoords(pPlayer, &tCoords);

    D2CoordStrc tFreeCoords;
    D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pPlayer), &tCoords, &tFreeCoords, 1, 1);
    if (pRoom)
    {
        D2ItemDropStrc tItemDrop;
        memset(&tItemDrop, 0, sizeof(tItemDrop));
        tItemDrop.pUnit = 0;
        tItemDrop.pSeed = 0;
        tItemDrop.wItemFormat = pGame->wItemFormat;
        tItemDrop.nId = nItemId;
        tItemDrop.nX = tFreeCoords.nX;
        tItemDrop.pGame = pGame;
        tItemDrop.nSpawnType = 3;
        tItemDrop.nY = tFreeCoords.nY;
        tItemDrop.pRoom = pRoom;
        tItemDrop.wUnitInitFlags = 1;
        tItemDrop.nQuality = 2;
        tItemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
        D2UnitStrc* pNewItem = D2GAME_CreateItemEx_6FC4ED80(pGame, &tItemDrop, 0);
        STATLIST_SetUnitStat(pNewItem, STAT_QUANTITY, 1, 0);
        UNITROOM_RefreshUnit(pNewItem);
        if (pNewItem)
        {
            pNewItem->dwFlags |= 1;
        }

        bResult = 1;
        if (pItem)
        {
            int nFlags = 0;
            ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
            ITEMS_SetItemCell(pItem, ITEMS_GetInvPage(pItem));
            D2GAME_UpdateClientItem_6FC3E9D0(UnitGetClient(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 0x80F), pPlayer, pItem, (unsigned int)nFlags);
            D2GAME_RemoveItem(pGame, pPlayer, pItem, 0);
        }

    }

    return bResult;
}

// 0x00581BF0
int __fastcall OBJECTS_OperateFunction27_TeleportPad(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
    if (pRoom)
    {
        const int nUnitId = !pOp->hObject ? -1 : pOp->hObject->dwClassId;

        D2UnitStrc* pUnit = pRoom->pUnitFirst;
        while (pUnit && ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_OBJECT || pUnit == pOp->hObject || (!pUnit ? -1 : pUnit->dwClassId) != nUnitId))
        {
            pUnit = pUnit->ptRoomNext;
        }

        if (pUnit)
        {
            OBJMODE_TeleportToUnit(pUnit, pOp->hPlayer, pRoom);
            return 0;
        }

        D2ActiveRoomStrc** ppRoomList;
        unsigned int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] != pRoom)
            {
                pUnit = ppRoomList[i]->pUnitFirst;
                while (pUnit && ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_OBJECT || pUnit == pOp->hObject || (!pUnit ? -1 : pUnit->dwClassId) != nUnitId))
                {
                    pUnit = pUnit->ptRoomNext;
                }

                if (pUnit)
                {
                    OBJMODE_TeleportToUnit(pUnit, pOp->hPlayer, ppRoomList[i]);
                    return 0;
                }
            }
        }
    }

    return 0;
}

// 0x00581CD0
int __fastcall OBJECTS_OperateFunction30_ExplodingChest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->hObject, pOp->hPlayer, 0);
        OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->hObject, pOp->hPlayer, 1);
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    return 0;
}

// 0x00583FF0
int __fastcall OBJECTS_OperateFunction18_SecretDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        UNITS_FreeCollisionPath(pOp->hObject);
    }

    return 1;
}

// 0x00582080
int __fastcall OBJECTS_OperateFunction61_HarrogathMainGate(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
    D2CoordStrc pCoord;
    UNITS_GetCoords(pOp->hObject, &pCoord);
    const int nSizeX = UNITS_GetUnitSizeX(pOp->hObject);
    const int nSizeY = UNITS_GetUnitSizeY(pOp->hObject);
    const unsigned int nTickCount = GetTickCount();
    const int nAnimMode = !pOp->hObject ? 0 : pOp->hObject->dwAnimMode;

    if (nTickCount < pOp->hObject->dwTickCount + 500)
    {
        return 1;
    }

    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
    switch (nAnimMode)
    {
    case 0:
        UNITS_FreeCollisionPath(pOp->hObject);
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        pOp->hObject->dwTickCount = nTickCount;
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        break;

    case 2:
        UNITS_BlockCollisionPath(pOp->hObject, pRoom, pCoord.nX, pCoord.nY);
        UNITS_ChangeAnimMode(pOp->hObject, 0);
        pOp->hObject->dwTickCount = nTickCount;
        break;
    }

    return 1;
}

// 0x00582180
int __fastcall OBJECTS_OperateFunction50_Stair(D2ContextStrc* context, void* argument)
{
    if (context->data)
    {
        unsigned int state = context->data->state;
        if ((short)state && (short)state == 2)
            return sub_00581F60_HandleState(context, argument);
    }
    return 0;
}

// 0x005821A0
int __fastcall OBJECTS_OperateFunction29_SlimeDoor(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        UNITS_FreeCollisionPath(pOp->hObject);

        const int nMode = !pOp->hObject ? 0 : pOp->hObject->dwAnimMode;
        const int bSelectable = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->nSelectable[nMode];
        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            if (bSelectable)
            {
                pObject->dwFlags |= UNITFLAG_TARGETABLE;
            }
            else
            {
                pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
            }
        }

        if (DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->nMode[2])
        {
            EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx)->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
    }

    return 1;
}

// 0x00582250
static int __stdcall OBJMODE_IsTrapMonsterAllowed(D2ActiveRoomStrc* pRoom, int nMonsterId)
{
    if (nMonsterId == MONSTER_FLYINGSCIMITAR && pRoom && DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) == ACT_I)
    {
        return 0;
    }

    return 1;
}

inline int CLIENTS_GetUnitX_Local(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitY_Local(D2UnitStrc* pUnit)
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

// 0x005843A0
int __fastcall OBJECTS_OperateFunction13_TorchTiki(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->hObject;
    switch (!pObject ? 0 : pObject->dwAnimMode)
    {
    case 0:
        UNITS_ChangeAnimMode(pObject, 1);
        break;
    case 1:
        UNITS_ChangeAnimMode(pObject, 0);
        break;
    }
    return 0;
}

static inline int CLIENTS_GetUnitX_Shrine(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitY_Shrine(D2UnitStrc* pUnit)
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

// 0x00583050
void __fastcall D2GAME_SHRINES_Monster_6FC76ED0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    D2UnitStrc* pMonster = UNITFINDS_GetNearestTestedUnit(pOp->hPlayer, CLIENTS_GetUnitX_Shrine(pOp->hPlayer), CLIENTS_GetUnitY_Shrine(pOp->hPlayer), 0, OBJMODE_IsMonsterShrineCandidate);
    if (pMonster)
    {
        MONSTERUNIQUE_PromoteToUnique(pOp->pGame, pMonster);
    }
}

static inline unsigned int SEED_RollRandomNumber32(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5 + pSeed->nHighSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber32(pSeed) % nMax;
    }

    return SEED_RollRandomNumber32(pSeed) & (nMax - 1);
}

// 0x005858A0
int __fastcall OBJECTS_OperateFunction22_Well(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pOp->hObject);
    unsigned char nType = pOp->hObject->pObjectData->InteractType;
    if (nType)
    {
        if (OBJMODE_WellHeal(pOp->pGame, pOp->hPlayer, pObjectsTxtRecord))
        {
            nType -= 1;
            const unsigned char nMax = OBJECTS_GetRegenerateMax(pObjectsTxtRecord);
            if (nType <= nMax && !(nType % (unsigned char)(nMax / OBJECTS_GetRegenerateSteps())))
            {
                UNITS_ChangeAnimMode(pOp->hObject, OBJECTS_GetRegenerateSteps() - nType / pObjectsTxtRecord->dwParm[2]);
            }

            pOp->hObject->pObjectData->InteractType = nType;
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_AITHINK, pOp->pGame->dwGameFrame + pObjectsTxtRecord->dwParm[0] + 1, 0, 0);
        }
    }
    return 0;
}

// 0x00582750
int __fastcall OBJMODE_IsMonsterShrineCandidate(D2UnitStrc* pMonster, D2UnitStrc* pUnit1)
{
    if (pMonster == pUnit1)
    {
        return 0;
    }
    const int nUnitType = pMonster ? pMonster->dwUnitType : UNIT_INVALID;
    if (!pMonster || nUnitType != 1)
    {
        return 0;
    }
    if (STATLIST_AreUnitsAligned(pUnit1, pMonster) == 1)
    {
        return 0;
    }
    if (STATLIST_GetUnitAlignment(pMonster) != 0)
    {
        return 0;
    }
    if (MONSTERS_IsDead(pMonster))
    {
        return 0;
    }
    const int nAnimMode = pMonster->dwAnimMode;
    if (nAnimMode != 1 && nAnimMode != 2)
    {
        return 0;
    }
    const int nClassId = pMonster->dwClassId;
    if (!sub_0046C140_TestMonModeFlag(nClassId, 2))
    {
        return 0;
    }
    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
    if (!pMonStats2TxtRecord || !pMonStats2TxtRecord->nType)
    {
        return 0;
    }
    D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pMonster);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    if (MONSTERS_IsBoss(pMonStatsTxtRecord, pMonster))
    {
        return 0;
    }
    if (MONSTERS_IsPrimeEvil(pMonster))
    {
        return 0;
    }
    return MONSTERUNIQUE_CheckMonTypeFlag(pMonster, 31) == 0;
}

// 0x00582800
D2StatListStrc* __fastcall OBJMODE_ApplyShrineCurse(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nDuration, int nStatValue, int nStat, int nState, StatListRemoveCallback pStateRemoveCallback)
{
    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.nSkill = 0;
    curse.nSkillLevel = 0;
    curse.pTarget = pTarget;
    curse.nDuration = nDuration;
    curse.nStat = nStat;
    curse.nStatValue = nStatValue;
    curse.nState = nState;
    curse.pStateRemoveCallback = pStateRemoveCallback;
    return SKILLS_ApplyStateEffect(&curse);
}

static inline D2CharStatsTxt* sub_00583740_GetCharStatsRecord(int nClassId)
{
    return (nClassId >= 0 && nClassId < sgptDataTables->nCharStatsTxtRecordCount) ? &sgptDataTables->pCharStatsTxt[nClassId] : 0;
}

// 0x00582280
static void D2GAME_SpawnTrapMonster_6FC75B40(D2ObjOperateFnStrc* pOp, int nMonsterId, int nAnimMode)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
        if (nMonsterId != MONSTER_FLYINGSCIMITAR || !pRoom || DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)) != ACT_I)
        {
            if (!MONSTERSPAWN_SpawnLevelVariantAtUnit(pOp->pGame, pOp->hObject, nMonsterId, nAnimMode, (-1), 0)
                && !MONSTERSPAWN_SpawnLevelVariantAtUnit(pOp->pGame, pOp->hObject, nMonsterId, nAnimMode, 1, 0))
            {
                MONSTERSPAWN_SpawnLevelVariantAtUnit(pOp->pGame, pOp->hObject, nMonsterId, nAnimMode, 3, 0);
            }
        }
    }
}

// 0x00582510
static void __stdcall D2GAME_SetTrapCallback_6FC764B0(unsigned char bTrapType, D2ObjOperateFnStrc* pOp)
{
// build: symbol ?gnObjectTrapHandlerCount@* 0x00732D14
    if (bTrapType < gnObjectTrapHandlerCount && sgObjectTrapHandlers[bTrapType])
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)sgObjectTrapHandlers[bTrapType]), 0x56C);

        if (sgObjectTrapHandlers[bTrapType] == D2GAME_OBJECTS_TrapHandler8_9_6FC75AC0
            && !OBJMODE_IsTrapMonsterAllowed(UNITS_GetRoom(pOp->hObject), OBJRGN_GetTrapMonsterId(pOp)))
        {
            return;
        }

        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_TRAP, pOp->pGame->dwGameFrame + 35, 0, 0);
        SUNIT_AttachSound(pOp->hObject, 13, 0);
    }
}

static inline int OBJMODE_GetToHitPercentageValue(D2UnitStrc* pUnit, D2UnitStrc* pWeapon, D2SkillStrc* pSkill)
{
    int nPercentage;
    OBJMODE_GetToHitPercentage(&nPercentage, 1, pUnit, pSkill, pWeapon);
    return nPercentage;
}

static inline int OBJMODE_GetMinDamagePercentage(D2UnitStrc* pUnit, D2UnitStrc* pWeapon)
{
    int bTwoHanded = 0;
    if (D2Common_10434(pUnit, 1) || pWeapon)
    {
        bTwoHanded = INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2;
    }

    if (bTwoHanded)
    {
        return STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
    }
    return STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
}

// 0x005822F0
void __fastcall D2GAME_OBJECTS_TrapHandler8_9_6FC75AC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ObjOperateFnStrc op;
    op.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pUnit));
    op.hObject = pUnit;
    op.pGame = pGame;

    const int nMonsters = (SEED_RollRandomNumber_Inline(&op.pObjectregion->pSeed) & 1) + 1;

    const int nMonsterId = OBJRGN_GetTrapMonsterId(&op);
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        for (int i = 0; i < nMonsters; ++i)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(&op, nMonsterId, 8);
        }
    }
}

// 0x00582380
void __fastcall D2GAME_OBJECTS_TrapHandler5_7_6FC75BC0(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2CoordStrc pCoord;
    UNITS_GetCoords(pUnit, &pCoord);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2UnitStrc* pFireLarge = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_LARGE, pCoord.nX, pCoord.nY, pGame, pRoom, 1, 1, 0);
    if (pFireLarge)
    {
        D2GAME_SetSparkChest_6FCBD7C0(pFireLarge, 2);
    }

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    const int nX = pCoord.nX + 1;
    if (nX >= drlgCoords.nSubtileX && nX < drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
    {
        D2UnitStrc* pFireSmall = SUNIT_AllocUnitData(UNIT_OBJECT, OBJECT_FIRE_SMALL, nX, pCoord.nY, pGame, UNITS_GetRoom(pUnit), 1, 1, 0);
        D2GAME_SetSparkChest_6FCBD7C0(pFireSmall, 2);
    }
}

// 0x00582420
static void OBJMODE_SpawnTrapMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId)
{
    D2CoordStrc tCoord;
    UNITS_GetCoords(pUnit, &tCoord);

    if (!sub_6FC6A090(pGame, UNITS_GetRoom(pUnit), tCoord.nX, tCoord.nY, nMonsterId, 1, 136))
    {
        D2ActiveRoomStrc* pRoom;
        D2Common_10136(UNITS_GetRoom(pUnit), &tCoord, 0, COLLIDE_MASK_PLACEMENT, &pRoom);
        if (pRoom)
        {
            D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, tCoord.nX, tCoord.nY, nMonsterId, 1, 3, 8);
        }
    }
}

// 0x00582490
void __fastcall D2GAME_OBJECTS_TrapHandler1_6FC75C70(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    OBJMODE_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_LIGHTNING);
}

// 0x005824B0
void __fastcall D2GAME_OBJECTS_TrapHandler2_6_6FC75D00(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    OBJMODE_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_FIREBOLT);
}

// 0x005824D0
void __fastcall D2GAME_OBJECTS_TrapHandler3_6FC75D90(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    OBJMODE_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_POISONCLOUD);
}

// 0x005824F0
void __fastcall D2GAME_OBJECTS_TrapHandler4_6FC75E20(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    OBJMODE_SpawnTrapMonster(pGame, pUnit, MONSTER_TRAP_NOVA);
}

inline void UNIT_ClearFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags &= ~nFlag;
    }
}

// 0x00583F10
int __fastcall OBJECTS_OperateFunction51_JungleStash(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_AIRESET, pOp->pGame->dwGameFrame + pObjectsTxtRecord->dwParm[1] + 1, 0, 0);

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
        OBJECTS_SetUnitIdInTimerArg(pOp->hObject, !pOp->hPlayer ? -1 : pOp->hPlayer->dwUnitId);
    }

    return 1;
}

// 0x00586680
D2UnitStrc* __fastcall OBJMODE_RollChestDrop(D2ObjOperateFnStrc* pOp)
{
    if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
    {
        return OBJMODE_DropFromChestTCWithQuality(pOp, 0);
    }
    return 0;
}

// 0x00585240
static int __stdcall OBJMODE_ApplyObeliskPowerUp(D2GameStrc* pGame, unsigned char nSubType, D2UnitStrc* pPlayer)
{
// build: symbol ?gnObeliskPowerUpCount@* 0x00732FAC
    if (nSubType < gnObeliskPowerUpCount)
    {
        const unsigned __int64 lSeed = pPlayer->pSeed.nHighSeed + 0x6AC690C5i64 * pPlayer->pSeed.nLowSeed;
        pPlayer->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pPlayer->pSeed.nLowSeed = (unsigned int)lSeed;
        if ((unsigned int)lSeed % 100 < gaObeliskPowerUps[nSubType].nChance)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gaObeliskPowerUps[nSubType].pPowerUpCallback), 4341);
            return gaObeliskPowerUps[nSubType].pPowerUpCallback(pGame, pPlayer, gaObeliskPowerUps[nSubType].nValue);
        }
    }

    return 0;
}

static inline int OBJECTS_IsNeutralExplodingBarrel(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwClassId == OBJECT_EXPLODINGBARREL && pUnit->dwAnimMode == OBJMODE_NEUTRAL;
}

// 0x00585CE0
void __fastcall OBJMODE_UpdateTrappedSoul(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    const int nMode = !pObject ? 0 : pObject->dwAnimMode;
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pObject ? -1 : pObject->dwClassId);
    switch (nMode)
    {
    case 1:
        EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 10, 0, 0);
        break;

    case 2:
    {
        D2ObjectDataStrc* pObjectData = pObject->pObjectData;
        const unsigned char nInteract = pObjectData->InteractType + 1;
        pObjectData->InteractType = nInteract;
        if (nInteract > 1)
        {
            D2ObjOperateFnStrc tOp;
            tOp.pGame = pGame;
            tOp.hObject = pObject;
            tOp.hPlayer = 0;
            tOp.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            tOp.nObjectIdx = pObject->dwClassId;
            if (OBJMODE_DropFromChestTCWithQuality(&tOp, 0))
            {
                UNITS_ChangeAnimMode(pObject, 3);
                EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, (pObjectsTxtRecord->dwFrameCnt[3] >> 8) + pGame->dwGameFrame + 1, 0, 0);
            }
        }
        else
        {
            OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
            OBJMODE_DamagePlayersInRange(pGame, pObject);
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_PERIODICSTATS, pGame->dwGameFrame + 25, 0, 0);
        }
        break;
    }

    case 3:
        UNITS_ChangeAnimMode(pObject, 4);
        break;
    }
}

// 0x00585E00
void __fastcall OBJMODE_OpenTowerChest(D2ObjOperateFnStrc* pOp)
{

    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hObject, &pCoord);

        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);
        OBJMODE_DropFromChestTCWithQuality(pOp, ITEMQUAL_MAGIC);

        unsigned int dwCode = ITEMS_GetHealthPotionDropCode(pOp->hObject);
        D2_ASSERT(dwCode, 1428);

        pOp->hObject->dwDropItemCode = dwCode;

        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);

        dwCode = ITEMS_GetManaPotionDropCode(pOp->hObject);
        D2_ASSERT(dwCode, 1433);

        pOp->hObject->dwDropItemCode = dwCode;

        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);

        if (pObjectsTxtRecord->nMode[1])
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);
        }

        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);
    }
}

// 0x00584420
int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult)
{

    *pResult = 1;

    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, nObjectType, nObjectGUID);
    const int nClassId = !pObject ? -1 : pObject->dwClassId;
    D2ObjectsTxt* pObjectTxtRecord = UNITS_GetObjectTxtRecordFromObject(pObject);

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        int nInteractType;
        if (SUNIT_GetInteractInfo(pPlayer, &nInteractType, &nObjectGUID) || UNITS_GetPlayerData(pPlayer)->bBusy)
        {
            return 0;
        }

        D2InventoryStrc* pInventory = pPlayer->pInventory;
        if (INVENTORY_GetCursorItem(pInventory) && nClassId != OBJECT_STASH)
        {
            return 0;
        }
    }

    if (pObjectTxtRecord->nOperateFn < 101 && nClassId != OBJECT_JERHYN_PLACEHOLDER1 && nClassId != OBJECT_JERHYN_PLACEHOLDER2 && nClassId != OBJECT_STONETHETA
        && gpfnObjOperateFunctions[pObjectTxtRecord->nOperateFn])
    {
        D2ObjOperateFnStrc pObjOperate;
        pObjOperate.pGame = pGame;
        pObjOperate.hObject = pObject;
        pObjOperate.hPlayer = pPlayer;
        pObjOperate.pObjectregion = OBJRGN_GetObjectControlFromGame(pGame, UNITS_GetRoom(pObject));
        pObjOperate.nObjectIdx = nClassId;
        return ((ObjOperateCallFunction)gpfnObjOperateFunctions[pObjectTxtRecord->nOperateFn])(&pObjOperate);
    }

    D2_ASSERT(pObjectTxtRecord->nOperateFn < 101, 3320);
    return 0;
}

// 0x00584540
int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nObjectType, int nObjectGUID)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, nObjectType, nObjectGUID);
    if (!pObject)
    {
        return 0;
    }

    const int nClassId = pObject->dwClassId;
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && !DATATBLS_GetObjectsTxtRecord(nClassId)->nMonsterOK)
        {
            return 1;
        }

        if (!UNITS_IsObjectInInteractRange(pUnit, pObject))
        {
            return 1;
        }
    }

    int nResult = 1;
    OBJECTS_OperateHandler(pGame, pUnit, nObjectType, nObjectGUID, &nResult);
    return nResult;
}

// 0x005845D0
void __fastcall OBJMODE_UpdateDoorModeFromCollision(D2GameStrc* pGame, D2UnitStrc* pUnused, int nObjectGUID)
{

    D2UnitStrc* hObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, nObjectGUID);
    D2_ASSERT(hObject, 3383);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(hObject);
    D2CoordStrc pCoord;
    UNITS_GetCoords(hObject, &pCoord);
    const int nSizeX = UNITS_GetUnitSizeX(hObject);
    const int nSizeY = UNITS_GetUnitSizeY(hObject);

    const int nAnimMode = hObject->dwAnimMode;
    switch (nAnimMode)
    {
    case OBJMODE_NEUTRAL:
        COLLISION_CheckMaskWithSizeXY(pRoom, pCoord.nX, pCoord.nY, nSizeX, nSizeY, 0x8180);
        break;

    case OBJMODE_OPENED:
    case OBJMODE_SPECIAL3:
        if (!COLLISION_CheckMaskWithSizeXY(pRoom, pCoord.nX, pCoord.nY, nSizeX, nSizeY, 0x8180))
        {
            if (nAnimMode != OBJMODE_OPENED)
            {
                UNITS_ChangeAnimMode(hObject, OBJMODE_OPENED);
            }
        }
        else
        {
            if (nAnimMode != OBJMODE_SPECIAL3)
            {
                UNITS_ChangeAnimMode(hObject, OBJMODE_SPECIAL3);
            }
        }
        break;
    }
}

// 0x00584820
void __fastcall OBJMODE_ClearSteegStoneGUID(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{
    if (pObject && pObject->dwClassId == OBJECT_STEEG_STONE)
    {
        D2TimerArg2Strc* pArg = UNITS_GetTimerArg(pObject)->pArg;
        if (!pUnit || (pArg && SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pArg->nUnitGUID) == pUnit))
        {
            if (pArg)
            {
                pArg->nUnitGUID = -1;
            }
        }
    }
}

// 0x005852E0
int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, unsigned short nState)
{
    D2GSPacketSrv58 packet58;
    D2UnitStrc* hObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, nPlayerGUID);
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (pPlayer)
    {
        if (!hObject)
        {
            return 1;
        }

        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszObjModeSourceFile, 0x1135);
        packet58.nHeader = 0x58;
        packet58.nUnitId = nObjectGUID;
        const int nAnimMode = hObject->dwAnimMode;
        switch (nState)
        {
        case 2:

            if (nAnimMode == 3)
            {
                packet58.nAction = 1;
                D2GAME_SendPacket0x58(pClient, &packet58);
                UNITS_ChangeAnimMode(hObject, 0);
                SUNIT_ResetInteractInfo(pPlayer);
            }
            else
            {
                packet58.nAction = 1;
                D2GAME_SendPacket0x58(pClient, &packet58);
                UNITS_ChangeAnimMode(hObject, 0);
                SUNIT_ResetInteractInfo(pPlayer);
            }
            break;

        case 3:
        {
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
            if ((!hObject ? -1 : hObject->dwClassId) == 0x98)
            {
                if (pItemsTxtRecord->dwCode != 0x20747368)
                {
                    packet58.nAction = 4;
                    D2GAME_SendPacket0x58(pClient, &packet58);
                    return 1;
                }
            }
            else if (!D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem))
            {
                packet58.nAction = 4;
                D2GAME_SendPacket0x58(pClient, &packet58);
                return 1;
            }

            packet58.nAction = 5;
            SUNIT_ResetInteractInfo(pPlayer);
            if (hObject->dwClassId == 0x98)
            {
                packet58.nResult = 1;
            }
            else
            {
                packet58.nResult = OBJMODE_ApplyObeliskPowerUp(pGame, pItemsTxtRecord->nSubType, pPlayer);
            }

            D2GAME_SendPacket0x58(pClient, &packet58);
            if (packet58.nResult == 1)
            {
                UNITS_ChangeAnimMode(hObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!hObject ? -1 : hObject->dwClassId);
                if (hObject->dwClassId == 0x98)
                {
                    UNITS_ChangeAnimMode(hObject, 2);
                    ACT2Q6_DeleteAllHoradricItemsAndOpenTomb(pGame, pPlayer, hObject);
                    break;
                }

                EVENT_SetEvent(pGame, hObject, 1, pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + 1, 0, 0);
                break;
            }

            UNITS_ChangeAnimMode(hObject, 0);
            break;
        }
        }

        return 1;
    }

    D2_ASSERT(hObject, 0x1109);
    return 1;
}

// 0x005854D0
void __fastcall OBJMODE_CloseObjectInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pObject)
{

    if (pObject)
    {
        const int nClassId = pObject->dwClassId;
        if ((unsigned short)nClassId == OBJECT_OBELISK || (unsigned short)nClassId == OBJECT_DESERT_OBELISK)
        {
            const int nObjectGUID = pObject->dwUnitId;
            OBJMODE_MainObeliskHandler(pGame, !pUnit ? -1 : pUnit->dwUnitId, nObjectGUID, 0, 2);
        }
        else if ((unsigned short)nClassId == OBJECT_STEEG_STONE)
        {
            OBJMODE_ClearSteegStoneGUID(pGame, pUnit, pObject);
        }
        else if ((unsigned short)nClassId == OBJECT_ORIFICE)
        {
            UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
        }
    }

    SUNIT_ResetInteractInfo(pUnit);
}

// 0x00585580
void __fastcall OBJMODE_RelocateTownPortal(D2GameStrc* ptGame, D2UnitStrc* pPlayer, int nPortalGUID, int nDestLevel)
{
    D2_ASSERT(ptGame, 0x11DD);

    D2UnitStrc* pPortal = SUNIT_GetServerUnit(ptGame, 2, nPortalGUID);
    if ((pPortal ? pPortal->dwClassId : -1) != 0x3B || UNITS_CheckObjectPortalFlag(pPortal, 1))
    {
        return;
    }

    D2UnitStrc* pPair = SUNIT_GetPortalOwner(ptGame, pPortal);
    if (!pPair)
    {
        return;
    }

    D2_ASSERT(pPair->dwClassId == 0x3B, 0x11EA);
    D2_ASSERT((unsigned char)nDestLevel <= 0xFF, 0x11EC);

    pPortal->pObjectData->InteractType = (unsigned char)nDestLevel;
    D2PortalFlags00585580Strc tFlags;
    tFlags.nFlags = UNITS_GetObjectPortalFlags(pPortal) | 1;
    UNITS_SetObjectPortalFlags(pPortal, tFlags.nFlags);
    UNITS_ChangeAnimMode(pPortal, 3);

    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPair), 2, !pPair ? -1 : pPair->dwUnitId);
    SUNIT_RemoveUnit(ptGame, pPair);

    D2UnitStrc* hDstPortal = D2GAME_CreateLinkPortal_6FD13B20(ptGame, pPlayer, pPortal, nDestLevel, DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPortal)));
    D2_ASSERT(hDstPortal, 0x11FB);

    tFlags.nFlags = UNITS_GetObjectPortalFlags(hDstPortal) | 3;
    UNITS_SetObjectPortalFlags(hDstPortal, tFlags.nFlags);
}

// 0x00585B90
D2UnitStrc* __fastcall OBJMODE_DropFromChestTCWithQuality(D2ObjOperateFnStrc* pOp, int nItemQuality)
{
    D2_ASSERT(pOp->hObject, 0x1313);

    D2GameStrc* ptGame = SUNIT_GetGameFromUnit(pOp->hObject);

    D2_ASSERT(ptGame, 0x1315);
    D2_ASSERT(UNITS_GetObjectTxtRecordFromObject(pOp->hObject), 0x1317);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOp->hObject);
    if (!pRoom)
        return 0;

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nLevelId);

    const int nCurrentMonsterLevel = DATATBLS_GetMonsterLevelInArea(nLevelId, ptGame->nDifficulty, ptGame->bExpansion);
    const int nMinMonsterLevel = DATATBLS_GetMonsterLevelInArea(gnChestActLevelIds[2 * nAct], ptGame->nDifficulty, ptGame->bExpansion);
    const int nMaxMonsterLevel = DATATBLS_GetMonsterLevelInArea(gnChestActLevelIds[2 * nAct + 1], ptGame->nDifficulty, ptGame->bExpansion);

    int nMonsterLevelDiff = nMaxMonsterLevel - nMinMonsterLevel;
    if (nMonsterLevelDiff < 0)
        nMonsterLevelDiff = -nMonsterLevelDiff;

    const int nOffset = (nMonsterLevelDiff + 1) / 3;
    int nTCIndex;
    if (nCurrentMonsterLevel < nOffset + nMinMonsterLevel)
        nTCIndex = 0;
    else
        nTCIndex = (nCurrentMonsterLevel >= nMinMonsterLevel + 2 * nOffset) + 1;

    D2TCExShortStrc* pTCExRecord = DATATBLS_GetTreasureClassExRecordFromActAndDifficulty(ptGame->nDifficulty, nAct, nTCIndex);
    if (!pTCExRecord)
        return 0;

    int nItemDropCount = 0;
    D2UnitStrc* ppDroppableItems[6] = {};
    D2GAME_DropTC_6FC51360(ptGame, pOp->hObject, pOp->hPlayer, pTCExRecord, nItemQuality, nTCIndex, 0, ppDroppableItems, &nItemDropCount, 6);
    return ppDroppableItems[0];
}

static inline int UNIT_GetId(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }

static inline int UNIT_GetType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

static inline int UNIT_GetClass(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwClassId; }

// 0x00586410
int __fastcall OBJECTS_OperateFunction01_Casket(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL && OBJMODE_DropFromChestTCWithQuality(pOp, 0))
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000 & 0xFFFFE000)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(pOp, OBJRGN_GetTrapMonsterId(pOp), 8);
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x00585F60
int __fastcall OBJECTS_OperateFunction04_Chest(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) != 0) return 1;
    DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
    D2ObjectsTxt* pRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
    unsigned int nDropCount = 0;
    const unsigned char nInteractType = pOp->hObject->pObjectData->InteractType;
    if (nInteractType & 0x80) {
        int bOpen = 1;
        if (!pOp->hPlayer || pOp->hPlayer->dwClassId != 6) bOpen = D2GAME_DoKeyCheck_6FC4A4B0(pOp->pGame, pOp->hPlayer);
        if (!bOpen) {
            SUNIT_AttachSound(pOp->hPlayer, 22, pOp->hPlayer);
            return 1;
        }
        SUNIT_AttachSound(pOp->hPlayer, 11, pOp->hPlayer);
        D2GAME_UpdateUnit_6FCC6080(pOp->hPlayer, UnitGetClient(pOp->hPlayer, gszObjModeSourceFile, 0x5D4));
        nDropCount = 1;
    }
    ++nDropCount;
    D2CoordStrc coords;
    UNITS_GetCoords(pOp->hObject, &coords);
    int nItemCount = 0;
    int nQuality;
    if (D2GAME_CheckIfSparklyChest_6FCBD7F0(pOp->hObject) & 1) {
        nQuality = (int)(SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100) < 5 ? 6 : 4;
        nItemCount = 1;
    } else nQuality = 0;
    if (pOp->hObject && pOp->hObject->dwClassId == 397) {
        nQuality = 0;
        nItemCount = 0;
        const int nRoll = SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000;
        if (nRoll < 200) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 7);
            if (!pItem) goto Default;
            {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
                pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 7);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
            }
        } else if (nRoll < 600) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 5);
            if (!pItem) goto Default;
            {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
                pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 5);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
            }
        } else if (nRoll < 1200) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 6);
            if (!pItem) goto Default;
            {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
                pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 6);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) goto Finish;
            }
        } else if (nRoll < 3200) {
            for (int i = 0; i < 10; ++i) {
                D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 4);
                if (pItem) {
                    if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) ++nQuality;
                    ++nItemCount;
                }
                if (nQuality >= 3) break;
            }
            if (!nItemCount) goto Default;
            goto Finish;
        } else if (nRoll < 6200) {
            for (int i = 0; i < 10; ++i) {
                D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 4);
                if (pItem) {
                    if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) ++nQuality;
                    else ++nItemCount;
                }
                if (nQuality >= 2) break;
            }
            if (!nItemCount) {
                if (OBJMODE_DropFromChestTCWithQuality(pOp, 0)) nItemCount = 1;
            } else if (nItemCount >= 7) goto Finish;
            for (int i = 0; i < 7 - nItemCount; ++i)
                OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, 0x20646C67, 0);
            goto Finish;
        }
    Default:
        for (int i = 0; i < 10; ++i) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, 4);
            if (pItem) {
                if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) break;
                ++nItemCount;
            }
        }
        if (nItemCount < 4) {
            for (int i = 0; i < 4 - nItemCount; ++i) OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }
        for (int i = 0; i < 5; ++i) OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, 0x20646C67, 0);
        for (int i = 0; i < 2; ++i) OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, 0x20337068, 0);
        for (int i = 0; i < 2; ++i) OBJMODE_DropItemWithCodeAndQuality(pOp->pGame, pOp->hObject, 0x2033706D, 0);
    } else if ((int)(SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100) >= 25 || nItemCount || nInteractType & 0x80) {
        unsigned int nSuccess = 0;
        for (unsigned int i = 0; i < nDropCount; ++i) {
            D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, nQuality);
            if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) ++nSuccess;
        }
        if (nItemCount && !nSuccess) {
            for (unsigned int i = 0; i < 10; ++i) {
                D2UnitStrc* pItem = OBJMODE_DropFromChestTCWithQuality(pOp, nQuality);
                if (pItem && ITEMS_IsMagSetRarUniCrfOrTmp(pItem)) break;
            }
        }
    }
Finish:
    if (pRecord->nMode[1]) {
        UNITS_ChangeAnimMode(pOp->hObject, 1);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    } else UNITS_ChangeAnimMode(pOp->hObject, 2);
    UNIT_ClearFlag(pOp->hObject, 2);
    if (pOp->hObject->dwDropItemCode) {
        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, 2, &nItemLevel, 0, -1, 1);
    }
    D2GAME_SetTrapCallback_6FC764B0(nInteractType & ~0x80, pOp);
    return 1;
}

// 0x005868A0
int __fastcall OBJECTS_OperateFunction05_Barrel(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));

        if (pOp->hPlayer && pOp->hPlayer->dwUnitType == UNIT_PLAYER)
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(pOp->hPlayer, SKILL_KICK, -1);
            if (pSkill)
            {
                UNITS_SetTargetUnitForDynamicUnit(pOp->hPlayer, pOp->hObject);
                StartModeID(pOp->pGame, pOp->hPlayer, pSkill, SKILLS_GetSkillMode(pSkill), UNIT_OBJECT, !pOp->hObject ? -1 : pOp->hObject->dwUnitId, 0);
            }
        }

        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);
        UNITS_FreeCollisionPath(pOp->hObject);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 10000 & 0xFFFFE000)
        {
            D2GAME_SpawnTrapMonster_6FC75B40(pOp, OBJRGN_GetTrapMonsterId(pOp), 8);
        }

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
        {
            OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }

    return 0;
}

static inline int sub_F05_WpGetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

// 0x00584F60
void __fastcall OBJMODE_TravelViaWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nWaypointGUID, int nLevelId)
{
    D2UnitStrc* pWaypoint = SUNIT_GetServerUnit(pGame, 2, nWaypointGUID);
    if (!pWaypoint)
    {
        return;
    }

    D2ObjectsTxt* pObjectsTxtRecord = UNITS_GetObjectTxtRecordFromObject(pWaypoint);
    if (!pObjectsTxtRecord)
    {
        return;
    }

    const unsigned char nOperateFn = pObjectsTxtRecord->nOperateFn;
    if (nOperateFn >= 0x65 || gpfnObjOperateFunctions[nOperateFn] != OBJECTS_OperateFunction23_Waypoint)
    {
        return;
    }

    const int nDestLevelId = (unsigned short)nLevelId;
    const int nWaypointLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pWaypoint));
    SUNIT_ResetInteractInfo(pPlayer);

    if (nWaypointLevelId == nDestLevelId || !(unsigned short)nLevelId)
    {
        return;
    }

    D2WaypointDataStrc* pWaypointData = sub_00547F50(pGame, pPlayer);
    int nWaypointNo;
    if (!WAYPOINTS_GetWaypointNoFromLevelId(nDestLevelId, (unsigned short*)&nWaypointNo) || !WAYPOINTS_IsActivated(pWaypointData, nWaypointNo))
    {
        return;
    }

    int nTileIndex;
    if (DUNGEON_IsTownLevelId(nDestLevelId) || nDestLevelId == LEVEL_CANYONOFTHEMAGI || nDestLevelId == LEVEL_ARCANESANCTUARY || nDestLevelId == LEVEL_PANDEMONIUMRUN1
        || nDestLevelId == LEVEL_PANDEMONIUMRUN2 || nDestLevelId == LEVEL_PANDEMONIUMRUN3 || nDestLevelId == LEVEL_PANDEMONIUMFINALE)
    {
        nTileIndex = 13;
    }
    else
    {
        nTileIndex = 0;
    }

    LEVEL_WarpUnit(pGame, pPlayer, nDestLevelId, nTileIndex);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    int nX;
    int nY;
    if (pRoom && pRoom == DUNGEON_FindActSpawnLocation(pGame->pAct[DRLG_GetActNoFromLevelId(nDestLevelId)], nDestLevelId, nTileIndex, &nX, &nY))
    {
        D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\OBJECTS\\ObjMode.cpp", 0x1072);
        const int nUnitGUID = sub_F05_WpGetUnitId(pPlayer);
        D2CoordStrc tCoord;
        UNITS_GetCoords(pPlayer, &tCoord);
        PLRMODE_ChangeModeToCoords(pGame, pPlayer, 0, 2, tCoord.nX, tCoord.nY, 0);
        D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 13, 0, nUnitGUID, 1, tCoord.nX + 3, tCoord.nY + 3, 0, 0);
    }

    OBJRGN_AllocObjectRoomCoords(pGame, pPlayer, pRoom);
}

// 0x005869F0
int __fastcall OBJECTS_OperateFunction48_TrappedSoul(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->hObject ? -1 : pOp->hObject->dwClassId);

        if ((int)(SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100) < 90)
        {
            if (OBJMODE_DropFromChestTCWithQuality(pOp, 0))
            {
                UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_SPECIAL3);
            }
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_PERIODICSTATS, pOp->pGame->dwGameFrame + 20, 0, 0);
        }
    }

    return 0;
}

typedef void (__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);

extern EventCallbackFunction gpfnObjectEventFunctions[15]; // 0x006E19B0

// 0x00586AD0
void __fastcall D2GAME_OBJMODE_InvokeEventFunction_6FC75250(D2GameStrc* pGame, D2UnitStrc* pObject, int eEventType)
{
    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnObjectEventFunctions[eEventType]), 576);
    gpfnObjectEventFunctions[eEventType](pGame, pObject);
}

// 0x00584870
int __fastcall OBJECTS_OperateFunction15_Portal(D2ObjOperateFnStrc* pOp)
{
    if (PLAYER_IsBusy(pOp->hPlayer))
        return 0;
    if (PLAYER_HasHostilePlayer(pOp->pGame, pOp->hPlayer)
        && UNIT_GetId(pOp->hPlayer) != OBJECTS_GetUnitIdFromTimerArg(pOp->hObject))
        return 0;
    if (PLAYERLIST_GetHostileDelay(pOp->hPlayer, 0) + 5000 > GetTickCount()) {
        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
        return 0;
    }
    const int nOwnerId = OBJECTS_GetUnitIdFromTimerArg(pOp->hObject);
    D2UnitStrc* pPlayer = pOp->hPlayer;
    if (nOwnerId != -1 && nOwnerId != UNIT_GetId(pPlayer)) {
        if (SUNIT_GetPartyId(pPlayer) == -1) {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }
        D2UnitStrc* pOwner = SUNIT_GetServerUnit(pOp->pGame, 0, nOwnerId);
        if (pOwner && SUNIT_GetPartyId(pPlayer) != SUNIT_GetPartyId(pOwner)) {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }
    }
    D2_ASSERT((pOp->hPlayer ? pOp->hPlayer->dwUnitType : UNIT_INVALID) == 0, 0xED8);
    D2UnitStrc* pOtherPortal = SUNIT_GetPortalOwner(pOp->pGame, pOp->hObject);
    if (pOtherPortal && pOtherPortal->dwUnitType != UNIT_OBJECT) pOtherPortal = 0;
    if (UNITS_GetRoom(pOp->hObject)) {
        D2BitBufferStrc* pQuestFlags = PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer);
        if (!pQuestFlags) {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }
        const int nLevelId = pOp->hObject->pObjectData->InteractType;
        D2PortalQuestStrc* pPortalQuest = DATATBLS_GetLevelDefRecord(nLevelId);
        if (!pPortalQuest) {
            SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
            return 0;
        }
        if (pOp->nObjectIdx == 59) {
            const int nPortalId = PLAYER_GetUniqueIdFromPlayerData(pOp->hPlayer);
            if (nPortalId != UNIT_GetId(pOp->hObject) && pOtherPortal && nPortalId != GAME_GetUnitGUID(pOtherPortal)) {
                if (pOp->pGame->bExpansion) {
                    if (pPortalQuest->nExpansionQuest > 0 && !QUESTRECORD_GetQuestState(pQuestFlags, pPortalQuest->nExpansionQuest, 0)) {
                        SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
                        return 0;
                    }
                } else if (pPortalQuest->nQuest > 0 && !QUESTRECORD_GetQuestState(pQuestFlags, pPortalQuest->nQuest, 0)) {
                    SUNIT_AttachSound(pOp->hPlayer, 19, pOp->hPlayer);
                    return 0;
                }
            }
        }
    }
    D2ActiveRoomStrc* pRoom;
    D2CoordStrc coords;
    if (!pOtherPortal) {
        const int nLevelId = pOp->hObject->pObjectData->InteractType;
        int nX, nY;
        pRoom = DUNGEON_FindActSpawnLocationEx(pOp->pGame->pAct[DRLG_GetActNoFromLevelId(nLevelId)], nLevelId, 0, &nX, &nY, 3);
        coords.nX = nX; coords.nY = nY;
    } else {
        coords.nX = CLIENTS_GetUnitX(pOtherPortal);
        coords.nY = CLIENTS_GetUnitY(pOtherPortal);
        pRoom = UNITS_GetRoom(pOtherPortal);
    }
    unsigned char nFlags = UNITS_GetObjectPortalFlags(pOp->hObject) | 5;
    UNITS_SetObjectPortalFlags(pOp->hObject, nFlags);
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pOp->hPlayer))) {
        QUESTS_ChangeLevel(pOp->pGame, DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hPlayer)), DUNGEON_GetLevelIdFromRoom(pRoom), pOp->hPlayer);
    }
    pRoom = COLLISION_GetFreeCoordinates(pRoom, &coords, UNITS_GetUnitSizeX(pOp->hPlayer), 0x1C09, 0);
    if (!pRoom)
        return 0;
    int nX = coords.nX, nY = coords.nY;
    D2_ASSERT(SUNIT_TeleportUnit(pOp->pGame, pOp->hPlayer, pRoom, nX, nY, 0, 0), 0xF52);
    D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, gszObjModeSourceFile, 0xF54);
    SUNIT_AttachSound(pOp->hPlayer, 8, 0);
    PLRMODE_ChangeModeToCoords(pOp->pGame, pOp->hPlayer, 0, 2, nX + 5, nY + 5, 0);
    D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient, 0x0D, UNIT_GetType(pOp->hPlayer), UNIT_GetId(pOp->hPlayer), 1, nX + 5, nY + 5, 0, 0);
    const int nClassId = UNIT_GetClass(pOp->hObject);
    if (pOtherPortal && (unsigned short)nClassId != 60) {
        if (PLAYER_GetUniqueIdFromPlayerData(pOp->hPlayer) == pOtherPortal->dwUnitId) {
            D2UnitStrc* pObject = pOp->hObject;
            pRoom = UNITS_GetRoom(pObject);
            DUNGEON_AllocDrlgDelete(pRoom, 2, UNIT_GetId(pOp->hObject));
            SUNIT_RemoveUnit(pOp->pGame, pOp->hObject);
            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
            ACT5Q5_OnPortalClosed(pOp->pGame, pOtherPortal);
            pRoom = UNITS_GetRoom(pOtherPortal);
            DUNGEON_AllocDrlgDelete(pRoom, 2, pOtherPortal->dwUnitId);
            SUNIT_RemoveUnit(pOp->pGame, pOtherPortal);
            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
        }
    } else if (pOp->hObject && pOp->hObject->dwAnimMode == OBJMODE_OPERATING) {
        D2ObjectsTxt* pRecord = DATATBLS_GetObjectsTxtRecord((unsigned short)nClassId);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    const int nFrame = pOp->pGame->dwGameFrame + 75;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pOp->pGame->pMemoryPool, 2, nFrame, 0, UNIT_GetType(pOp->hPlayer));
    if (pStatList) {
        EVENT_SetEvent(pOp->pGame, pOp->hPlayer, 12, nFrame, 0, 0);
        STATES_ToggleState(pOp->hPlayer, 102, 1);
        STATLIST_SetState(pStatList, 102);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pOp->hPlayer, pStatList, 1);
    }
    return 0;
}

// 0x00584060
int __fastcall OBJECTS_OperateFunction26_BookShelf(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hObject, &pCoord);

        int nRand = (unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) % 20;
        if (nRand > 12)
        {
            if ((unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) & 1)
            {
                pOp->hObject->dwDropItemCode = ' kbi';
            }
            else
            {
                pOp->hObject->dwDropItemCode = ' kbt';
            }
        }
        else
        {
            if ((unsigned int)SEED_RollRandomNumber(&pOp->pObjectregion->pSeed) & 1)
            {
                pOp->hObject->dwDropItemCode = ' csi';
            }
            else
            {
                pOp->hObject->dwDropItemCode = ' cst';
            }
        }

        int nItemLevel;
        D2GAME_DropItemAtUnit_6FC4FEC0(pOp->pGame, pOp->hObject, ITEMQUAL_NORMAL, &nItemLevel, 0, -1, 0);
    }

    return 1;
}

// 0x00584160
int __fastcall OBJECTS_OperateFunction19_ArmorStand(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hObject, &pCoord);
        D2GAME_DropArmor_6FC4F830(pOp->pGame, UNITS_GetRoom(pOp->hObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x005841D0
int __fastcall OBJECTS_OperateFunction20_WeaponRack(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hObject, &pCoord);
        D2GAME_DropWeapon_6FC4FA50(pOp->pGame, UNITS_GetRoom(pOp->hObject), &pCoord, -1, 0, 0);
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPENED);

        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x00584240
static int OBJMODE_ExplodeBarrel(D2ObjOperateFnStrc* pOp)
{
    D2ObjOperateFnStrc tNewOp = *pOp;
    D2CoordStrc tCoord;
    UNITS_GetCoords(pOp->hObject, &tCoord);
    for (D2UnitStrc* pUnit = UNITS_GetRoom(pOp->hObject)->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        const int nAnimMode = pUnit ? pUnit->dwAnimMode : 0;
        if (pUnit != pOp->hObject && nUnitType != UNIT_TILE)
        {
            if (nUnitType == UNIT_PLAYER)
            {
                if (nAnimMode != PLRMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->hObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_MONSTER)
            {
                if (nAnimMode != MONMODE_DEAD && UNITS_IsInRange(pUnit, &tCoord, 3))
                {
                    OBJEVAL_ApplyTrapObjectDamage(pOp->pGame, pOp->hObject, pUnit, 0);
                }
            }
            else if (nUnitType == UNIT_OBJECT)
            {
                if (OBJECTS_IsNeutralExplodingBarrel(pUnit) && DRLG_UnitEdgeDistance(pOp->hObject, pUnit) <= 2)
                {
                    tNewOp.hObject = pUnit;
                    OBJECTS_OperateFunction07_ExplodingBarrel(&tNewOp);
                }
            }
        }
    }
    return 0;
}

// 0x00584330
int __fastcall OBJECTS_OperateFunction07_ExplodingBarrel(D2ObjOperateFnStrc* pOp)
{
    if ((!pOp->hObject ? 0 : pOp->hObject->dwAnimMode) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);
        OBJMODE_ExplodeBarrel(pOp);
        UNITS_FreeCollisionPath(pOp->hObject);
        D2ObjectsTxt* pTxt = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pTxt->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    return 0;
}

inline int __fastcall GetObjectClass(D2UnitStrc* pObject)
{
    if (!pObject) return -1;
    int nClass = pObject->dwClassId;
    _ReadWriteBarrier();
    return nClass;
}

// 0x00585550
void __fastcall OBJMODE_ResetObjectInteraction(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    if (GetObjectClass(pObject) == 337)
    {
        D2TimerArg2Strc* pArg = UNITS_GetTimerArg(pObject)->pArg;
        if (pArg) pArg->nUnitGUID = -1;
    }
    else
    {
        UNITS_ChangeAnimMode(pObject, 0);
    }
}

// 0x005843D0
int __fastcall OBJECTS_OperateFunction11_Torch(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2UnitStrc* pObject = pOp->hObject;
    if (pObject && pObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        switch (pObject->dwAnimMode)
        {
        case OBJMODE_OPERATING:
        case OBJMODE_OPENED:
            UNITS_ChangeAnimMode(pObject, OBJMODE_NEUTRAL);
            break;
        }
    }
    else
    {
        UNITS_ChangeAnimMode(pObject, OBJMODE_OPERATING);
        pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
    }

    return 1;
}

// 0x005846B0
int __fastcall OBJECTS_OperateFunction34_ArcaneSanctuaryPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));

    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    else if (nLevelId == LEVEL_ARCANESANCTUARY)
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, LEVEL_PALACECELLARLEV3, 0);
        ACT2Q4_SetPortalMode(pOp->pGame, LEVEL_ARCANESANCTUARY);
    }
    else if (nLevelId == LEVEL_PALACECELLARLEV3)
    {
        LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, LEVEL_ARCANESANCTUARY, ARCANE_TILECALC);
        ACT2Q4_SetPortalMode(pOp->pGame, LEVEL_PALACECELLARLEV3);
    }

    return 0;
}

// 0x00584D00
int __fastcall OBJECTS_OperateFunction43_DurielPortal(D2ObjOperateFnStrc* pOp, int nOperate)
{

    D2_ASSERT((pOp->hPlayer ? pOp->hPlayer->dwUnitType : UNIT_INVALID) == UNIT_PLAYER, 4019);

    const unsigned char nPortalFlags = UNITS_GetObjectPortalFlags(pOp->hObject) | 5;
    UNITS_SetObjectPortalFlags(pOp->hObject, nPortalFlags);

    int nLevel = 0;
    D2UnitStrc* pObject = pOp->hObject;
    if (pObject)
    {
        switch (pObject->dwClassId)
        {
        case OBJECT_PORTAL_TO_DURIELS_LAIR:
            nLevel = LEVEL_DURIELSLAIR;
            break;

        case OBJECT_GUILD_PORTAL:
            nLevel = pObject->pObjectData->InteractType;
            break;
        }
    }

    int nX = 0;
    int nY = 0;
    const unsigned char bAct = DRLG_GetActNoFromLevelId(nLevel);
    D2_ASSERT(bAct < 5, 4043);

    D2ActiveRoomStrc* pRoom = DUNGEON_FindActSpawnLocationEx(pOp->pGame->pAct[bAct], nLevel, 0, &nX, &nY, UNITS_GetUnitSizeX(pOp->hPlayer));
    D2_ASSERT(pRoom, 4045);

    D2CoordStrc pCoord;
    pCoord.nX = nX;
    pCoord.nY = nY;

    pRoom = COLLISION_GetFreeCoordinates(pRoom, &pCoord, UNITS_GetUnitSizeX(pOp->hPlayer), 0x1C09, 0);
    if (pRoom)
    {
        D2_ASSERT(SUNIT_TeleportUnit(pOp->pGame, pOp->hPlayer, pRoom, pCoord.nX, pCoord.nY, 0, 0), 4057);
    }

    return 0;
}

// 0x00584E30
int __fastcall OBJECTS_OperateFunction23_Waypoint(D2ObjOperateFnStrc* pOp, int nOperate)
{

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
    D2WaypointDataStrc* pWaypointFlags = PLAYER_GetWaypointFlags(pOp->pGame, pOp->hPlayer);
    unsigned short nWpNo;
    if (WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &nWpNo))
    {
        WAYPOINTS_ActivateWaypoint(pWaypointFlags, nWpNo);
    }

    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
    }
    else if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_OPENED || UNIT_GetAnimMode(pOp->hObject) == OBJMODE_OPERATING)
    {
        if (!PLAYER_IsBusy(pOp->hPlayer))
        {
            D2GSPacketSrv63 packet63;
            packet63.nHeader = 0x63;
            const int nUnitId = !pOp->hObject ? -1 : pOp->hObject->dwUnitId;
            *(int*)packet63.dwUnitId = nUnitId;
            WAYPOINTS_ValidateAndCopyWaypointData(pWaypointFlags, (D2WaypointDataStrc*)packet63.pData);

            D2ClientStrc* pClient = UnitGetClient(pOp->hPlayer, ".\\OBJECTS\\ObjMode.cpp", 4126);
            sub_0053D960_SendPacket0x63(pClient, &packet63);

            SUNIT_SetInteractInfo(pOp->hPlayer, UNIT_OBJECT, !pOp->hObject ? -1 : pOp->hObject->dwUnitId);
        }
    }

    return 1;
}

// 0x00584750
int __fastcall OBJECTS_OperateFunction46_HellGatePortal(D2ObjOperateFnStrc* pOp, int nOperate)
{

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));

    if (!pOp->hObject || pOp->hObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        return 0;
    }

    if (QUESTRECORD_GetQuestState(PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_PRIMARYGOALDONE)
        || QUESTRECORD_GetQuestState(PLAYER_GetQuestFlags(pOp->pGame, pOp->hPlayer), QUESTSTATEFLAG_A3Q6, QFLAG_REWARDGRANTED))
    {
        QUESTS_HellPortalActChange(pOp->pGame, pOp->hPlayer, nLevelId, pOp->hObject);
        if (nLevelId == LEVEL_DURANCEOFHATELEV3)
        {
            D2WaypointDataStrc* pWaypointFlags = PLAYER_GetWaypointFlags(pOp->pGame, pOp->hPlayer);
            unsigned short nWpNo;
            if (WAYPOINTS_GetWaypointNoFromLevelId(LEVEL_THEPANDEMONIUMFORTRESS, &nWpNo))
            {
                WAYPOINTS_ActivateWaypoint(pWaypointFlags, nWpNo);
            }

            LEVEL_WarpUnit(pOp->pGame, pOp->hPlayer, LEVEL_THEPANDEMONIUMFORTRESS, 0);
        }
    }

    return 0;
}

// 0x00586520
int __fastcall OBJECTS_OperateFunction68_EvilUrn(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL && OBJMODE_DropFromChestTCWithQuality(pOp, 0))
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 255 <= pObjectsTxtRecord->dwParm[7])
        {
            D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pOp->pGame->pMonReg, nLevelId);
            const int nMonCount = pMonsterRegion->nMonCount;
            for (int i = 0; i < nMonCount; ++i)
            {
                const int nMonsterId = pMonsterRegion->pMonData[i].nMonHcIdx;
                if (sub_0046C140_TestMonModeFlag(nMonsterId, MONMODE_WALK))
                {
                    MONSTERUNIQUE_SpawnUniqueGroup(pOp->pGame, UNITS_GetRoom(pOp->hObject), 0, nMonsterId, 1, 0, 0, 1);
                    break;
                }
            }
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005866C0
int __fastcall OBJECTS_OperateFunction03_Urn_Basket_Jar(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);

        if (SEED_RollRandomNumber_Inline(&pOp->pObjectregion->pSeed) % 100 <= 20)
        {
            OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        }

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x005867A0
int __fastcall OBJECTS_OperateFunction14_Corpse(D2ObjOperateFnStrc* pOp, int nOperate)
{
    if (UNIT_GetAnimMode(pOp->hObject) == OBJMODE_NEUTRAL)
    {
        OBJMODE_DropFromChestTCWithQuality(pOp, 0);
        DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        UNITS_ChangeAnimMode(pOp->hObject, OBJMODE_OPERATING);
        EVENT_SetEvent(pOp->pGame, pOp->hObject, EVENTTYPE_ENDANIM, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame + 1, 0, 0);
        UNIT_ClearFlag(pOp->hObject, UNITFLAG_TARGETABLE);

        if (!pObjectsTxtRecord->nHasCollision[1])
        {
            UNITS_FreeCollisionPath(pOp->hObject);
        }

        D2GAME_SetTrapCallback_6FC764B0(pOp->hObject->pObjectData->InteractType & ~OBJECT_INTERACT_TRAPPED, pOp);
    }

    return 1;
}

// 0x00583B30
void __fastcall D2GAME_SHRINES_DefensiveBoost_6FC77AE0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* ptShrineData)
{
    D2_ASSERT(ptShrineData->bCode < gnShrineTableCount, 0x9F9);

    const D2ShrineTableStrc* pShrineRecord = &sgcptShrineChart[ptShrineData->bCode];
    const int nStatValue = pShrineRecord->unk0x04 != -1 ? OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, ptShrineData->dwArg0, pOp->hPlayer) : 0;

    OBJMODE_ApplyShrineCurse(pOp->hObject, pOp->hPlayer, ptShrineData->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, 0);
}

// 0x00583BC0
void __fastcall OBJMODE_RefreshPassives(D2UnitStrc* pUnit)
{
    sub_6FD14C30(pUnit);
}

// 0x00583BD0
void __fastcall OBJMODE_RemoveSkillShrine(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SKILLS_RemoveStateAndRefreshPassives(pUnit, nState, pStatList);
    sub_6FD14C30(pUnit);
}

// 0x005839B0
void __fastcall D2GAME_SHRINES_CombatBoost_6FC77690(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* ptShrineData)
{
    D2_ASSERT(ptShrineData->bCode < gnShrineTableCount, 0x9C1);

    const D2ShrineTableStrc* pShrineRecord = &sgcptShrineChart[ptShrineData->bCode];
    const int nValue = OBJMODE_CalculateShrineStatBonus(0x13, ptShrineData->dwArg0, pOp->hPlayer);
    D2StatListStrc* pStatList = OBJMODE_ApplyShrineCurse(pOp->hObject, pOp->hPlayer, ptShrineData->dwDurationInFrames, ptShrineData->dwArg1, 0x19, pShrineRecord->unk0x08, 0);
    STATLIST_SetStatValue(pStatList, 0x13, nValue, 0);
}

// 0x00583A40
void __fastcall OBJMODE_RemoveStaminaShrine(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SKILLS_RemoveStateAndRefreshPassives(pUnit, nState, pStatList);
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
}

// 0x00583BF0
void __fastcall D2GAME_SHRINES_SkillBoost(D2SkillContext00583BF0Strc* pContext, D2Event00583BF0Strc* pEvent)
{
    D2CurseStrc tCurse = {};
    tCurse.pUnit = pContext->pUnit;
    tCurse.pTarget = pContext->pTarget;
    tCurse.nSkill = 0;
    tCurse.nSkillLevel = 0;
    tCurse.nDuration = pEvent->nDuration;
    tCurse.nStat = 11;
    tCurse.nStatValue = 0;
    tCurse.nState = gaShrineSkillBoostStates[pEvent->nType].nState;
    tCurse.pStateRemoveCallback = OBJMODE_RemoveSkillShrine;
    SKILLS_ApplyStateEffect(&tCurse);
    SKILLS_RefreshPassivesAndPetLimits(pContext->pTarget);
}

// 0x00583A70
void __fastcall D2GAME_SHRINES_Stamina_6FC779C0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* ptShrineData)
{
    D2_ASSERT(ptShrineData->bCode < gnShrineTableCount, 0x9E7);

    const D2ShrineTableStrc* pShrineRecord = &sgcptShrineChart[ptShrineData->bCode];
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pOp->hPlayer);
    STATLIST_SetUnitStat(pOp->hPlayer, STAT_STAMINA, nMaxStamina, 0);
    const int nStatValue = OBJMODE_CalculateShrineStatBonus(pShrineRecord->unk0x04, ptShrineData->dwArg0, pOp->hPlayer);
    D2StatListStrc* pStatList = OBJMODE_ApplyShrineCurse(pOp->hObject, pOp->hPlayer, ptShrineData->dwDurationInFrames, nStatValue, pShrineRecord->unk0x04, pShrineRecord->unk0x08, OBJMODE_RemoveStaminaShrine);
    STATLIST_SetStatValue(pStatList, 0x0A, 2 * nStatValue, 0);
    STATLIST_SetStatValue(pStatList, 0x1C, 1000, 0);
}

// 0x00582C40
void __fastcall D2GAME_SHRINES_Gem(D2ObjOperateFnStrc* pOp, int nOperate)
{
    D2InventoryStrc* pInventory = pOp->hPlayer->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetBackPackItemByType(pInventory, ITEMTYPE_GEM, 0);
    int bUpgraded = 0;
    while (pItem)
    {
        if (bUpgraded)
        {
            return;
        }

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
        if (pItemsTxtRecord->dwUpgradeCode != ' non')
        {
            const int nItemId = DATATBLS_GetItemIdFromItemCode(pItemsTxtRecord->dwUpgradeCode);
            D2_ASSERT(nItemId != -1, 0x823);
            if (OBJMODE_DropShrineGem(pItem, nItemId, pOp->pGame, pOp->hPlayer))
            {
                bUpgraded = 1;
                pItem = 0;
            }
        }

        pItem = INVENTORY_GetBackPackItemByType(pInventory, ITEMTYPE_GEM, pItem);
    }

    if (bUpgraded)
    {
        return;
    }

    D2SeedStrc* pSeed = &pOp->hPlayer->pSeed;
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;

    unsigned int dwCode;
    switch ((unsigned int)lSeed % 6)
    {
    case 0: dwCode = ' wcg'; break;
    case 1: dwCode = ' rcg'; break;
    case 2: dwCode = ' gcg'; break;
    case 3: dwCode = ' bcg'; break;
    case 4: dwCode = ' ycg'; break;
    default: dwCode = ' vcg'; break;
    }

    const int nItemId = DATATBLS_GetItemIdFromItemCode(dwCode);
    D2_ASSERT(nItemId != -1, 0x84C);
    OBJMODE_DropShrineGem(0, nItemId, pOp->pGame, pOp->hPlayer);
}

// 0x00582DA0
void __fastcall D2GAME_SHRINES_Storm(D2SfxStrc* pSfx, D2SfxArgStrc* pArgs)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pSfx->pObject);
    int nX = CLIENTS_GetUnitX_Local(pSfx->pObject);
    int nY = CLIENTS_GetUnitY_Local(pSfx->pObject);
    D2UnitFindArgStrc arg;
    memset(&arg, 0, sizeof(arg));
    arg.nFlags = 0x583;
    arg.nX = nX;
    arg.nY = nY;
    arg.nSize = pArgs->nRadius;
    D2UnitFindDataStrc data;
    UNITFINDS_InitializeUnitFindData(pSfx->pGame->pMemoryPool, &data, pRoom, nX, nY, pArgs->nRadius, (void*)OBJMODE_IsLivingPlayerOrMonster, &arg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&data);
    for (int i = 0; i < data.nIndex; ++i)
    {
        D2UnitStrc* pUnit = data.pUnitsArray[i];
        if (pUnit && (pUnit->dwUnitType == UNIT_MONSTER || pUnit->dwUnitType == UNIT_PLAYER) && !SUNIT_IsDead(pUnit))
        {
            int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
            STATLIST_AddUnitStat(pUnit, STAT_HITPOINTS, (pArgs->nDamagePct * nLife / -100) << 8, 0);
        }
    }
    UNITFINDS_FreeUnitFindData(&data);
    for (int i = 1; i < 5; ++i)
    {
        for (int j = 1; j < 5; ++j)
        {
            D2MissileStrc missile;
            memset(&missile, 0, sizeof(missile));
            missile.dwFlags = 3;
            missile.nX = CLIENTS_GetUnitX_Local(pSfx->pObject);
            missile.nY = CLIENTS_GetUnitY_Local(pSfx->pObject);
            missile.nTargetX = (i & 1) ? 5 * i : -5 * i;
            missile.nTargetY = (j & 1) ? 5 * j : -5 * j;
            missile.pOwner = pSfx->pOwner;
            missile.nMissile = MISSILE_FIREBALL;
            int nSkillLevel = STATLIST_UnitGetStatValue(pSfx->pOwner, STAT_LEVEL, 0) / 5;
            if (nSkillLevel < 1) nSkillLevel = 1;
            else if (nSkillLevel > 8) nSkillLevel = 8;
            missile.nSkillLevel = nSkillLevel;
            MISSILES_CreateMissileFromParams(pSfx->pGame, &missile);
        }
    }
}

// 0x005830E0
void __fastcall D2GAME_SHRINES_Exploding_6FC770D0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nItemsToDrop = ITEMS_RollLimitedRandomNumber(&pOp->hObject->pSeed, pShrinesTxtRecord->dwArg1 - pShrinesTxtRecord->dwArg0) + pShrinesTxtRecord->dwArg0;
    for (int i = 0; i < nItemsToDrop; ++i)
    {
        const int nItemIndex = DATATBLS_GetItemIdFromItemCode(' mpo');

        D2_ASSERT(nItemIndex != -1, 2226);

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hPlayer, &pCoord);
        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pOp->hPlayer), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = 0;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pOp->pGame;
            itemDrop.wItemFormat = pOp->pGame->wItemFormat;
            itemDrop.nId = nItemIndex;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 0;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pOp->hPlayer, 0);
            itemDrop.nQtyOverride = 1;

            D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pOp->pGame, &itemDrop, 0);

            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 1, 0);
            UNITROOM_RefreshUnit(pItem);

            if (pItem)
            {
                pItem->dwFlags |= 1;
            }
        }
    }

    int nXOffsets[] = { -6, -6, 0, 0, 6, 6 };
    int nYOffsets[] = { 6, -6, 6, -6, 6, -6 };

    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1312;
        missileParams.nX = CLIENTS_GetUnitX_Shrine(pOp->hObject);
        missileParams.nY = CLIENTS_GetUnitY_Shrine(pOp->hObject);
        missileParams.nTargetX = missileParams.nX + nXOffsets[i];
        missileParams.nTargetY = missileParams.nY + nYOffsets[i];
        missileParams.pOwner = pOp->hPlayer;
        missileParams.pOrigin = pOp->hObject;
        missileParams.nGfxArg = 1;
        missileParams.nMissile = MISSILE_EXPLOSIVEPOTION;

        int nSkillLevel = STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_LEVEL, 0) / 5;
        if (nSkillLevel < 1)
        {
            nSkillLevel = 1;
        }
        else if (nSkillLevel > 8)
        {
            nSkillLevel = 8;
        }
        missileParams.nSkillLevel = nSkillLevel;

        MISSILES_CreateMissileFromParams(pOp->pGame, &missileParams);
    }
}

// 0x00583410
void __fastcall D2GAME_SHRINES_Poison_6FC773B0(D2ObjOperateFnStrc* pOp, D2ShrinesTxt* pShrinesTxtRecord)
{
    const int nItemsToDrop = ITEMS_RollLimitedRandomNumber(&pOp->hObject->pSeed, pShrinesTxtRecord->dwArg1 - pShrinesTxtRecord->dwArg0) + pShrinesTxtRecord->dwArg0;
    for (int i = 0; i < nItemsToDrop; ++i)
    {
        const int nItemIndex = DATATBLS_GetItemIdFromItemCode(' mpg');

        D2_ASSERT(nItemIndex != -1, 2292);

        D2CoordStrc pCoord;
        UNITS_GetCoords(pOp->hPlayer, &pCoord);
        D2CoordStrc pReturnCoords;
        D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pOp->hPlayer), &pCoord, &pReturnCoords, 1, 1);
        if (pRoom)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.pUnit = 0;
            itemDrop.pSeed = 0;
            itemDrop.pGame = pOp->pGame;
            itemDrop.wItemFormat = pOp->pGame->wItemFormat;
            itemDrop.nId = nItemIndex;
            itemDrop.nSpawnType = ITEMSPAWN_GROUND;
            itemDrop.nX = pReturnCoords.nX;
            itemDrop.nY = pReturnCoords.nY;
            itemDrop.pRoom = pRoom;
            itemDrop.wUnitInitFlags = 1;
            itemDrop.nQuality = 0;
            itemDrop.nItemLvl = ITEMS_GetItemLevelForNewItem(pOp->hPlayer, 0);
            itemDrop.nQtyOverride = 1;

            D2UnitStrc* pItem = D2GAME_CreateItemEx_6FC4ED80(pOp->pGame, &itemDrop, 0);

            STATLIST_SetUnitStat(pItem, STAT_QUANTITY, 1, 0);
            UNITROOM_RefreshUnit(pItem);

            if (pItem)
            {
                pItem->dwFlags |= 1;
            }
        }
    }

    int nXOffsets[] = { -6, -6, 0, 0, 6, 6 };
    int nYOffsets[] = { 6, -6, 6, -6, 6, -6 };

    for (int i = 0; i < 6; ++i)
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1312;
        missileParams.nX = CLIENTS_GetUnitX_Shrine(pOp->hObject);
        missileParams.nY = CLIENTS_GetUnitY_Shrine(pOp->hObject);
        missileParams.nTargetX = missileParams.nX + nXOffsets[i];
        missileParams.nTargetY = missileParams.nY + nYOffsets[i];
        missileParams.pOwner = pOp->hPlayer;
        missileParams.pOrigin = pOp->hObject;
        missileParams.nGfxArg = 1;
        missileParams.nMissile = MISSILE_CHOKINGGASPOITION;

        int nSkillLevel = STATLIST_UnitGetStatValue(pOp->hPlayer, STAT_LEVEL, 0) / 5;
        if (nSkillLevel < 1)
        {
            nSkillLevel = 1;
        }
        else if (nSkillLevel > 8)
        {
            nSkillLevel = 8;
        }
        missileParams.nSkillLevel = nSkillLevel;

        MISSILES_CreateMissileFromParams(pOp->pGame, &missileParams);
    }
}

// 0x00583740
static void __stdcall OBJMODE_GetToHitPercentage(int* pToHit, int nSkillLevel, D2UnitStrc* pUnit, D2SkillStrc* pSkill, D2UnitStrc* pWeapon)
{
    *pToHit = UNITS_GetAttackRate(pUnit);
    D2_ASSERT(pSkill, 0x963);

    if (!pWeapon)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        pWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    }

    if (pWeapon && ITEMS_GetItemType(pWeapon) == ITEMTYPE_MISSILE_POTION)
    {
        *pToHit = 0;
    }

    const int nBonus = SKILLS_GetWeaponMasteryBonus(pUnit, pWeapon, pSkill, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pUnit, STAT_ITEM_TOHIT_PERCENT, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    const int nToHit = *pToHit;
    *pToHit = nToHit + nToHit * (pSkillsTxtRecord->dwToHit + (nSkillLevel - 1) * pSkillsTxtRecord->dwLevToHit + nBonus) / 100;

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == 0)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = sub_00583740_GetCharStatsRecord(pUnit->dwClassId);

        if (pCharStatsTxtRecord)
        {
            *pToHit += pCharStatsTxtRecord->dwToHitFactor;
        }
    }
}

// 0x00583840
static int __stdcall OBJMODE_CalculateShrineStatBonus(int nStatId, int nValue, D2UnitStrc* pUnit)
{
    D2UnitStrc* pWeapon = 0;
    if (pUnit && pUnit->pInventory)
    {
        pWeapon = INVENTORY_GetLeftHandWeapon(pUnit->pInventory);
    }

    int nStatValue;
    switch (nStatId)
    {
    case 0x0B:
    case 0x1B:
    case 0x27:
    case 0x29:
    case 0x2B:
    case 0x2D:
    case 0x55:
    case 0xAB:
        return nValue;

    case 0x13:
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
        OBJMODE_GetToHitPercentage(&nStatValue, 1, pUnit, pSkill, pWeapon);
        return nValue * nStatValue / 100;
    }

    case 0x15:
    {
        int bTwoHanded = 0;
        if (D2Common_10434(pUnit, 1) || pWeapon)
        {
            bTwoHanded = INVENTORY_GetWieldType(pUnit, pUnit->pInventory) == 2;
        }

        if (bTwoHanded)
        {
            nStatValue = STATLIST_UnitGetStatValue(pUnit, STAT_SECONDARY_MINDAMAGE, 0);
        }
        else
        {
            nStatValue = STATLIST_UnitGetStatValue(pUnit, STAT_MINDAMAGE, 0);
        }
        return nValue * nStatValue / 100;
    }

    default:
        nStatValue = STATLIST_UnitGetStatValue(pUnit, nStatId, 0);
        break;
    }

    return nValue * nStatValue / 100;
}

#include "gen/data/Source/D2Game/OBJECTS/ObjMode.inc"
