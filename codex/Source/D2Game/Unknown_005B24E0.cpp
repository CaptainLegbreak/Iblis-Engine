#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"
#include "D2LevelTxt.h"
#include "D2GameObjs.h"
#include "D2DrlgMaps.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"
#include "D2Win32Base.h"
#include "D2Packets.h"
#include "D2GameAux.h"
#include "D2LanguageNames.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2StaticPathStrc;

struct D2UnkMonCreateStrc3;

struct D2UnkMonCreateStrc;

union D2SeedStrc;

struct D2LevelsTxt;

struct D2MonStatsTxt;

struct D2PlayerDataStrc;

struct D2Act4Quest1Strc;

struct D2QuestGUIDStrc;

struct D2ObjOperateFnStrc;


struct D2Act4Quest2Strc;

struct D2Act4Quest3Strc;

struct D2Act3Quest1Strc;

struct D2Act3Quest3Strc;

struct D2Act3Quest4Strc;

struct D2Act3Quest5Strc;

struct D2Act3Quest6Strc;

struct D2Act3Quest7Strc;

struct D2UnkMonCreateStrc2
{
    int nRecordCount;
    int unk0x04;
    unsigned char unk0x08;
    unsigned char pad0x09[3];
    D2UnkMonCreateStrc3 records[4];
};

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall D2Common_11063(D2ActiveRoomStrc* pRoom, int nMonsterId); // 0x0063EC70

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030

void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

extern D2UnkMonCreateStrc2 gtBonePrisonSpawnInfo; // 0x0073D4F0

D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster(D2UnkMonCreateStrc*); // 0x005B2A00

enum D2C_SpawnRandomConstants
{
    MONSTATSFLAGINDEX_ISSPAWN = 0,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern char gpAct4Q0NpcMessages[]; // 0x0073D580

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

void __stdcall QUESTRECORD_ResetIntermediateStateFlags(D2BitBufferStrc* pQuestRecord, int nQuest); // 0x0065C3E0

void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex); // 0x00543790

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct); // 0x00545920

void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(void* pAct, int a2, int a3); // 0x00619DA0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

bool __fastcall ACT4Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B3750

bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B3740

int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData); // 0x005B3940

void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190



void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C3A0

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10

void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine); // 0x00544070

void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode); // 0x00544160

void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine); // 0x00544350

void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544720

int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState); // 0x00544760

void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID); // 0x00545200

int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0

void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget); // 0x00545780

D2UnitStrc* __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable); // 0x005466B0

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

D2UnitStrc* __fastcall D2GAME_DropItemAtUnit_6FC4FEC0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuality, int* pItemLevel, D2ItemDropStrc* pItemDrop, int a6, int a7); // 0x00559A30

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

void __fastcall PLAYER_CloseInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005351C0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

void __fastcall LEVEL_WarpUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nDestinationLevelId, int nTileCalc); // 0x0053AEC0

void __fastcall SCMD_SendPacket0x5D(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710

void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0

void __fastcall D2GAME_PACKETS_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940

void __fastcall D2GAME_PlayerChangeAct_6FC867C0(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc); // 0x0054B830

void __stdcall ACT4Q2_ActivateHarrogathWaypoint(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005B4FF0

bool __fastcall ACT3Q5_IsOrbNotSmashed(D2GameStrc* pGame); // 0x005BBF80

int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3CD0

int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3DE0

bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest); // 0x005B3E60

int __fastcall ACT4Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3F20

int __fastcall ACT4Q3_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B59C0

int __fastcall ACT3Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B7340

void __fastcall ACT3Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B7740

int __fastcall ACT3Q5_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BAF70

int __fastcall ACT3Q6_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005BC210

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510

void __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3D70


#define CENTER 3

#define MASK_A 0x100

#define MASK_B 0x1c09

#define OFFSET_BASE (g_006E2D50_offsets)


struct D2TileLibraryEntryStrc;

extern D2CoordStrc g_006E2D50_offsets[4];  // 0x006E2D50

D2DrlgTileDataStrc* __stdcall sub_00619660_GetFloorTiles(D2ActiveRoomStrc*,int*); // 0x00619660

int __stdcall TileGetFlags(D2TileLibraryEntryStrc*); // 0x00604BC0

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc*,int,int,unsigned short); // 0x0064CB30

struct D2GameStrc;

#define MONSTATSFLAGINDEX_SETBOSS 4

#define MONSTATSFLAGINDEX_BOSSXFER 5

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall PLAYER_GetBaseIdFromMonsterId(int nMonsterId); // 0x00463830

int __fastcall MISSILE_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790

int __fastcall sub_005B2570_SpawnMinionsAround(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nCount, int nOffset, short nFlags); // 0x005B2570

int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0

static void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit); // 0x005B2830

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithOwnerData(D2GameStrc* pGame, void* pRoom, int a1, int a2, int a3, int a4, int a5, int a6, unsigned short a7); // 0x005B3130

int __fastcall sub_005B31B0_SpawnMinionsAt(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags); // 0x005B31B0

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

extern unsigned char gbNeverCount_006CE270; // 0x006CE270

extern unsigned int gdwSetBoss_006CE278; // 0x006CE278

extern unsigned int gdwBossTransfer_006CE27C; // 0x006CE27C

extern "C" __declspec(dllimport) int __stdcall PtInRect(const tagRECT*,tagPOINT);

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc*,D2DrlgCoordsStrc*); // 0x00619730

void __stdcall SKILLS_GameTileToSubtileCoords(int*,int*); // 0x00643560

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*,int,int); // 0x00463740

int __stdcall D2Common_10095(D2ActiveRoomStrc*,int,int); // 0x0061B130

int __fastcall sub_005FD350_CanSpawn(int,D2ActiveRoomStrc*,int,int,int); // 0x005FD350

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*,int,int,int,unsigned short); // 0x0064D9B0

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int,int,int,int,D2GameStrc*,D2ActiveRoomStrc*,char,int,unsigned int); // 0x00555230

void __fastcall sub_00547D90_RegisterSpawn(D2MonsterRegionStrc**,D2ActiveRoomStrc*,D2UnitStrc*,int); // 0x00547D90

D2RoomCoordListStrc* __stdcall D2Common_10096(D2ActiveRoomStrc*,int,int); // 0x0061AD30

void __fastcall sub_00552D60_SetVision(D2UnitStrc*,D2RoomCoordListStrc*); // 0x00552D60

void __fastcall SUNIT_SetAlignment(D2UnitStrc*,unsigned char,int); // 0x005543B0

static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc*,D2UnitStrc*); // 0x005B21B0

static void MONSTERSPAWN_SetupBossMods(D2UnkMonCreateStrc*,D2UnitStrc*); // 0x005B1CF0

static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc*); // 0x005B1C50

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer);                        // 0x00625480

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640

void __fastcall MONSTERAI_CreateAndEquipItem(D2GameStrc* pGame, D2UnitStrc* pUnit, struct D2MonsterEquipmentStrc* pItemInfo, int nLevel, unsigned int nFlags); // 0x00573B20

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId);                // 0x005436B0

void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet);                         // 0x00573570

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, void* pRoom, int nXpos, int nYpos, int nWarrivId);    // 0x005447A0


extern const D2MonsterEquipmentStrc gtAncientEquipment[12]; // 0x006E2C90

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" const char gszAct4Q2SourceFile[]; // 0x006E2DA4

extern char gpAct4Q1NpcMessages[]; // 0x0073D708

void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310

int __fastcall ACT4Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B3860

void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3E30

void __fastcall ACT4Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B4020

void __fastcall ACT4Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3BB0

void __fastcall ACT4Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B39A0

void __fastcall ACT4Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT4Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC); // 0x005B37F0

bool __fastcall ACT4Q1_SeqCallback(D2QuestDataStrc* pQuestData); // 0x005B38E0

void __fastcall ACT4Q2_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData); // 0x005B4DA0

void __fastcall QUESTS_SendLogUpdate(D2UnitStrc*, int); // 0x005458E0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0

extern "C" const char gszAct4Q3SourceFile[];

extern char gpAct4Q3NpcMessages[];

extern char gpAct4Q4NpcMessages[];

extern char gpAct3IntroNpcMessages[];

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID);                            // 0x00545240

int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);

int __fastcall ACT4Q3_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

bool __fastcall ACT4Q3_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

bool __fastcall ACT4Q3_SeqCallback(D2QuestDataStrc* pQuestData);

void __fastcall ACT4Q3_Callback04_ItemPickedUp(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT4Q3_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT4Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

bool __fastcall ACT4Q4_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

void __fastcall ACT3Intro_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);

bool __fastcall ACT3Intro_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

bool __fastcall ACT3Intro_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

inline int CLIENTS_GetUnitX_Inline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitY_Inline(D2UnitStrc* pUnit)
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

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLevelVariantAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490

// 0x005B23C0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = UNITS_GetRoom(pUnit);
    monCreate.nMaxSearchRings = a5;
    monCreate.nFlags = nFlags;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nX = CLIENTS_GetUnitX_Inline(pUnit);
    monCreate.nY = CLIENTS_GetUnitY_Inline(pUnit);
    return D2GAME_SpawnNormalMonster(&monCreate);
}

// 0x005B2F70
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnitInCoordList(D2GameStrc* pGame, D2RoomCoordListStrc* pRoomCoordList, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a6, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = UNITS_GetRoom(pUnit);
    monCreate.nMaxSearchRings = a6;
    monCreate.nFlags = nFlags;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = pRoomCoordList;
    monCreate.nX = CLIENTS_GetUnitX_Inline(pUnit);
    monCreate.nY = CLIENTS_GetUnitY_Inline(pUnit);
    return D2GAME_SpawnNormalMonster(&monCreate);
}

// 0x005B2490
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLevelVariantAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!DUNGEON_GetLevelIdFromPopulatedRoom(pRoom))
    {
        return 0;
    }

    const int nSpawnMonsterId = D2Common_11063(pRoom, nMonsterId);
    return MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nSpawnMonsterId, nAnimMode, a5, nFlags);
}

// 0x005B2F20
D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags)
{
    D2UnkMonCreateStrc monCreate;

    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.nMaxSearchRings = nMaxSearchRings;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;

    return D2GAME_SpawnNormalMonster(&monCreate);
}

// 0x005B3090
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtCoordinates(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nMaxSearchRings = -1;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return D2GAME_SpawnNormalMonster(&monCreate);
}

// 0x005B30E0
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithUnitId(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nUnitGUID, int a8, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = nUnitGUID;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.nMaxSearchRings = a8;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = 0;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return D2GAME_SpawnNormalMonster(&monCreate);
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x005B3040
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnInCoordList(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2RoomCoordListStrc* pCoordList, int nX, int nY, int nMonsterId, int nAnimMode, int a8, short nFlags)
{
    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = nAnimMode;
    monCreate.pRoom = pRoom;
    monCreate.nMaxSearchRings = a8;
    monCreate.pGame = pGame;
    monCreate.pRoomCoordList = pCoordList;
    monCreate.nFlags = nFlags;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return D2GAME_SpawnNormalMonster(&monCreate);
}

static inline int MONSTERREGION_SanitizeMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

// 0x005B21B0
static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    const int nMonsterId = pMonCreate->nMonsterId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    const int nBaseId = !pMonStatsTxtRecord ? nMonsterId : pMonStatsTxtRecord->nBaseId;

    switch (MONSTERREGION_SanitizeMonsterId_Inline(nBaseId))
    {
    case 0x5B:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x14, 0);
        break;
    case 0x18:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xD, 0);
        break;
    case 0x60:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xA, 0);
        break;
    case 0x146:
    case 0x147:
    case 0x148:
    case 0x149:
    case 0x14A:
    case 0x162:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xE, 0);
        break;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xF, 0);
        break;
    case 0x1CD:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x21, 0);
        break;
    case 0x1B4:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x22, 0);
        break;
    case 0x1F5:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x23, 0);
        break;
    case 0xD3:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xB, 0);
    case 0x21C:
    case 0x21D:
    case 0x21E:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        break;
    }
}

// 0x005B1C50
static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit)
{
	const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
	const D2MonsterEquipmentStrc* pItemInfo = &gtAncientEquipment[nClassId - 540];

	int nItemId;
	int nCount = 4;
	do
	{
		D2MonsterEquipmentStrc itemInfo = *pItemInfo;
		D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemInfo->nItemCode, &nItemId);
		switch (pGame->nDifficulty)
		{
		case 1:
			itemInfo.nItemCode = pItemsTxtRecord->dwUberCode;
			break;

		case 2:
			itemInfo.nItemCode = pItemsTxtRecord->dwUltraCode;
			break;
		}

		MONSTERAI_CreateAndEquipItem(pGame, pUnit, &itemInfo, nLevel, 4);
		pItemInfo += 3;
		--nCount;
	}
	while (nCount);
}

static inline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline int MONSTERS_ValidateMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

static inline void MONSTERUNIQUE_ToggleUnitFlag_Inline(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

// 0x005B1CF0
static void MONSTERSPAWN_SetupBossMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    void* pRoom = pMonCreate->pRoom;
    const int nMonsterId = pMonCreate->nMonsterId;

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERS_GetMonStatsTxtRecord_Inline(nMonsterId);
    int nBaseId;
    if (!pMonStatsTxtRecord)
    {
        nBaseId = nMonsterId;
    }
    else
    {
        nBaseId = pMonStatsTxtRecord->nBaseId;
    }

    switch (MONSTERS_ValidateMonsterId_Inline(nBaseId))
    {
    case 0xD3:
        if (nMonsterId != MONSTER_UBERDURIEL)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0xD);
            QUESTS_CreateChainRecord(pGame, pUnit, 9);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0xAF:
    {
        const int nWarrivId = MONSTERS_ValidateMonsterId_Inline(MONSTER_WARRIV2);
        QUESTS_WarrivSpawn(pGame, pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nWarrivId);
        return;
    }
    case 0xFA:
        QUESTS_CreateChainRecord(pGame, pUnit, 0xC);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x800);
        MONSTER_ToggleSummonerFlag(pUnit, 1, 1);
        return;
    case 0xF3:
        if (nMonsterId != MONSTER_UBERDIABLO)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x17);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x16E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x13);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        return;
    case 0xF2:
        if (nMonsterId != MONSTER_UBERMEPHISTO)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x14);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1E, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x11, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    case 0x9C:
        if (nMonsterId != MONSTER_UBERANDARIEL)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 6);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1D, 1);
        return;
    case 0x199:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x18);
        return;
    case 0x100:
        if (nMonsterId != MONSTER_UBERIZUAL)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x16);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        return;
    case 0x197:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x11);
        return;
    case 0xE5:
        QUESTS_CreateChainRecord(pGame, pUnit, 8);
        return;
    case 0x10B:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0xC, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        QUESTS_CreateChainRecord(pGame, pUnit, 2);
        STATES_ToggleState(pUnit, 0x76, 1);
        return;
    case 0x11C:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x124:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x1F, 0);
        return;
    case 0x192:
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x1B2:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x20);
        return;
    case 0x20E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x22);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        return;
    case 0x21C:
        MONSTERSPAWN_EquipAncientBarbarians(pUnit);
        return;
    case 0x220:
        if (nMonsterId != MONSTER_UBERBAAL)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x24);
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 0x12, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pUnit, 6, 1);
        return;
    }
}

static inline D2MonStats2Txt* GetMonStats2(int nId)
{
    if(nId<0 || nId>=sgptDataTables->nMonStatsTxtRecordCount) return 0;
    int nIndex=sgptDataTables->pMonStatsTxt[nId].wMonStatsEx;
    if(nIndex<0 || nIndex>=sgptDataTables->nMonStats2TxtRecordCount) return 0;
    return &sgptDataTables->pMonStats2Txt[nIndex];
}

static inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int ITEMS_RollRandomNumber(D2SeedStrc* pSeed)
{
    return (unsigned int)SEED_RollRandomNumber(pSeed);
}

// 0x005B3130
D2UnitStrc* __fastcall MONSTERSPAWN_SpawnWithOwnerData(D2GameStrc* pGame, void* pRoom, int a1, int a2, int a3, int a4, int a5, int a6, unsigned short a7)
{
    D2UnkMonCreateStrc tRequest;
    tRequest.nUnitGUID = 0;
    tRequest.nMonsterId = a3;
    tRequest.nAnimMode = a4;
    tRequest.pGame = pGame;
    tRequest.pRoom = (D2ActiveRoomStrc*)pRoom;
    tRequest.pRoomCoordList = 0;
    tRequest.nMaxSearchRings = a5;
    tRequest.nFlags = a7;
    tRequest.nX = a1;
    tRequest.nY = a2;
    D2UnitStrc* pUnit = D2GAME_SpawnNormalMonster(&tRequest);
    if (pUnit)
    {
        AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, a6);
    }
    return pUnit;
}

struct D2BitBufferStrc;

struct D2QuestDataStrc;

struct D2UnitStrc;

// 0x005B24E0
int __fastcall MONSTERSPAWN_SpawnLinkedMinionsAtCoordinates(D2GameStrc* pGame, D2UnitStrc* pOwner, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags)
{
    if (!pOwner)
        return 0;

    int nResult = 0;
    const int nOwnerId = pOwner->dwUnitId;
    for (int i = 0; i < nCount; ++i)
    {
        D2UnitStrc* pMinion = MONSTERSPAWN_SpawnAtUnit(pGame, pOwner, nMonsterId, nAnimMode, a5, nFlags);
        if (pMinion)
        {
            nResult = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nOwnerId, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pOwner, pMinion);
        }
    }
    return nResult;
}

extern const D2CoordStrc gaMinionSpawnOffsets[3][6];                                               // 0x006E2CF0

inline int UNITS_GetUnitXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetUnitYPositionInline(D2UnitStrc* pUnit)
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

// 0x005B2570
int __fastcall sub_005B2570_SpawnMinionsAround(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int nCount, int nOffset, short nFlags)
{
    if (!pUnit)
    {
        return 0;
    }

    if (nOffset < 0 || nOffset > 2)
    {
        nOffset = 0;
    }

    int bSpawned = 0;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nUnitGUID = pUnit->dwUnitId;
    const int nX = UNITS_GetUnitXPositionInline(pUnit);
    const int nY = UNITS_GetUnitYPositionInline(pUnit);
    int nDirection = ITEMS_RollRandomNumber(&pUnit->pSeed) % 6;

    for (int i = 0; i < nCount; ++i)
    {
        const int nSpawnX = nX + gaMinionSpawnOffsets[nOffset][nDirection].nX;
        const int nSpawnY = nY + gaMinionSpawnOffsets[nOffset][nDirection].nY;
        nDirection = (nDirection + 5) % 6;

        D2UnitStrc* pMinion = MONSTERSPAWN_SpawnAtCoordinates(pGame, pRoom, nSpawnX, nSpawnY, nMonsterId, nAnimMode, nFlags);
        if (pMinion)
        {
            bSpawned = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nUnitGUID, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pUnit, pMinion);
        }
    }

    return bSpawned;
}

// 0x005B2700
int __stdcall MONSTERSPAWN_FindFloorPosition(D2ActiveRoomStrc* room,int* outX,int* outY)
{
    int count;
    D2DrlgTileDataStrc* tiles=sub_00619660_GetFloorTiles(room,&count);
    if (!tiles) return 0;
    if (!count) return 0;
    unsigned start=ITEMS_RollLimitedRandomNumber(room?&room->pSeed:0,count);
    if (!start) start=1;
    D2DrlgCoordsStrc bounds;
    DUNGEON_GetRoomCoordinates(room,&bounds);
    unsigned index=start;
    unsigned stop=start-1;
    while (index!=stop) {
        D2DrlgTileDataStrc* tile=&tiles[index];
        if (tile->pTile && (TileGetFlags(tile->pTile)&2)) {
            int x=5*(tile->nPosX+bounds.nTileXPos)+CENTER;
            int y=5*(tile->nPosY+bounds.nTileYPos)+CENTER;
            if (!COLLISION_CheckMask(room,x,y,MASK_A)) {
                D2CoordStrc* offset=OFFSET_BASE;
                do {
                    if (!COLLISION_CheckMaskWithSize(room,x+offset->nX,y+offset->nY,2,MASK_B)) {
                        *outX=x;
                        *outY=y;
                        return 1;
                    }
                    ++offset;
                } while ((int)offset < (int)(OFFSET_BASE+4));
            }
        }
        index=(index+1)%(unsigned)count;
    }
    return 0;
}

// 0x005B2830
static void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    const int nMonsterId = pMonCreate->nMonsterId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    int nChainId;
    DATATBLS_GetMonsterChainInfo(nMonsterId, 0, &nChainId);

    D2GameStrc* pGame = pMonCreate->pGame;
    const unsigned short nFlags = pMonCreate->nFlags;
    const short nMinion = pMonStatsTxtRecord->wMinion[0];
    if (nMinion < 0)
    {
        return;
    }
    const int nCount = *(volatile int*)&sgptDataTables->nMonStatsTxtRecordCount; // volatile only fixes where the original reads the count
    if (nMinion >= nCount)
    {
        return;
    }

    const int nBaseId = PLAYER_GetBaseIdFromMonsterId(nMonsterId);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount || nBaseId != MONSTER_TENTACLEHEAD1)
    {
        if (pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_SETBOSS])
        {
            AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_BOSSXFER]);
        }

        int nMinionIndex = 0;
        int nThreshold = 0;
        if (pMonStatsTxtRecord->wMinion[1] >= 0 && pMonStatsTxtRecord->wMinion[1] < sgptDataTables->nMonStatsTxtRecordCount)
        {
            nThreshold = 1;
        }

        const int nMinions = MISSILE_RollRange(&pUnit->pSeed, pMonStatsTxtRecord->nPartyMin, pMonStatsTxtRecord->nPartyMax);
        for (int i = 0; i < nMinions; ++i)
        {
            D2UnitStrc* pMonster = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, pMonStatsTxtRecord->wMinion[nMinionIndex], 1, 4, 0x40);
            if (pMonster && (pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_SETBOSS]))
            {
                AIGENERAL_SetOwnerData(pGame, pMonster, GAME_GetUnitGUID(pUnit), 1, 0, 0);
                AIGENERAL_AllocMinionList(pGame, pUnit, pMonster);
            }

            ++nMinionIndex;
            if (nMinionIndex > nThreshold)
            {
                nMinionIndex = 0;
            }
        }
    }
    else
    {
        AIGENERAL_SetOwnerData(pGame, pUnit, !pUnit ? -1 : pUnit->dwUnitId, 1, 1, pMonStatsTxtRecord->nMonStatsFlags[0] & gdwBitMasks[MONSTATSFLAGINDEX_BOSSXFER]);
        const int nMinions = MISSILE_RollRange(&pUnit->pSeed, pMonStatsTxtRecord->nPartyMin, pMonStatsTxtRecord->nPartyMax);
        const unsigned int bNonWaterSpawn = ~((unsigned int)nFlags >> 2) & 1;
        sub_005B2570_SpawnMinionsAround(pGame, pUnit, pMonStatsTxtRecord->wMinion[0], 1, nMinions, bNonWaterSpawn, 0x40);
    }
}

// 0x005B2A00
D2UnitStrc* __fastcall D2GAME_SpawnNormalMonster(D2UnkMonCreateStrc* pCreate)
{
    D2MonStatsTxt* pRecord=DATATBLS_GetMonStatsTxtRecord_Inline(pCreate->nMonsterId);
    if(!pRecord) return 0;
    D2MonStats2Txt* pRecord2=GetMonStats2(pCreate->nMonsterId);
    if(!pRecord2) return 0;
    const unsigned short nFlags=pCreate->nFlags;
    D2ActiveRoomStrc* pRoom=pCreate->pRoom;
    unsigned int nCollisionMask;
    switch(pRecord2->nSpawnCol)
    {
    case 1:nCollisionMask=0x1c0;break;
    case 2:nCollisionMask=0x3f11;break;
    case 3:nCollisionMask=0;break;
    case 0:nCollisionMask=0x3c01;break;
    default:nCollisionMask=0x3c01;break;
    }
    tagRECT area;
    int nAreaTile,bCheckTile;
    if(!pCreate->pRoomCoordList)
    {
        D2DrlgCoordsStrc coords;
        DUNGEON_GetRoomCoordinates(pRoom,&coords);
        area.bottom=coords.nSubtileY+coords.nSubtileHeight;area.left=coords.nSubtileX;area.right=coords.nSubtileX+coords.nSubtileWidth;area.top=coords.nSubtileY;
        nAreaTile=0;bCheckTile=0;
    }
    else
    {
        CopyRect(&area,&pCreate->pRoomCoordList->pBox[1]);
        SKILLS_GameTileToSubtileCoords((int*)&area.left,(int*)&area.top);
        SKILLS_GameTileToSubtileCoords((int*)&area.right,(int*)&area.bottom);
        nAreaTile=pCreate->pRoomCoordList->nIndex;bCheckTile=1;
    }
    if (!pRoom)
        return 0;
    if (!&pRoom->pSeed)
        return 0;
    int nRadius,nMaxRadius;
    if(pCreate->nMaxSearchRings<0) nRadius=0; else nRadius=3;
    if(!nRadius) nMaxRadius=0; else nMaxRadius=3*pCreate->nMaxSearchRings;
    {
    int nSpawnY=0,nSpawnX=0;
    if(pRecord2->nSpawnCol==1 && !(pCreate->nMonsterId>=0x102 && pCreate->nMonsterId<=0x107) && pCreate->nMonsterId!=MONSTER_HELLMETEOR)
    {
        MONSTERSPAWN_FindFloorPosition(pRoom,&nSpawnX,&nSpawnY);
        pRoom=sub_00463740_FindRoomAtPoint(pRoom,nSpawnX,nSpawnY);
    }
    else
    {
        if(nRadius>nMaxRadius) return 0;
        do
        {
            D2SeedStrc* pSeed=&pRoom->pSeed;
            int nX=pCreate->nX,nY=pCreate->nY;
            const int nDiameter=2*nRadius;
            int nOffsetX,nOffsetY,nStepX,nStepY;
            if(ITEMS_RollRandomNumber(pSeed)&1)
            {
                nOffsetX=nRadius; if (nX) nOffsetY=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1); else nOffsetY=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1); nStepX=0; nStepY=1;
            }
            else
            {
                if (nX && nRadius) nOffsetX=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1); else nOffsetX=ITEMS_RollLimitedRandomNumber(pSeed,nDiameter>>1);nOffsetY=nRadius;nStepX=1;nStepY=0;
            }
            if(ITEMS_RollRandomNumber(pSeed)&1) nOffsetX=-nOffsetX;
            if(ITEMS_RollRandomNumber(pSeed)&1) nOffsetY=-nOffsetY;
            nX+=nOffsetX;nY+=nOffsetY;
            const int nMinX=pCreate->nX-nRadius,nMaxX=nMinX+nDiameter;
            const int nMinY=pCreate->nY-nRadius,nMaxY=nMinY+nDiameter;
            int nSteps=4*nDiameter;
            if(!nSteps) nSteps=1;
            while(nSteps>0)
            {
                if(nX==nMinX && nY==nMinY) {nStepX=1;nStepY=0;}
                if(nX==nMaxX)
                {
                    if(nY==nMinY) {nStepX=0;nStepY=1;}
                    if(nY==nMaxY) {nStepX=-1;nStepY=0;}
                }
                if(nX==nMinX)
                {
                    if(nY==nMaxY) {nStepX=0;nStepY=-1;}
                    if(nY==nMinY && nX==nMaxX && nY==nMaxY) {nStepX=0;nStepY=0;}
                }
                nX+=nStepX;nY+=nStepY;
                tagPOINT point;point.x=nX;point.y=nY;
                if(PtInRect(&area,point) && (!bCheckTile || D2Common_10095(pRoom,nX,nY)==nAreaTile)
                    && sub_005FD350_CanSpawn(pCreate->nMonsterId,pRoom,nX,nY,1)
                    && (!COLLISION_CheckMaskWithSize(pRoom,nX,nY,pRecord2->nSizeX,nCollisionMask) || (pCreate->nFlags&0x80)))
                {
                    nSpawnX=nX;nSpawnY=nY;nRadius=nMaxRadius;break;
                }
                --nSteps;
            }
            const int nNext=nRadius+3;
            *(int volatile*)&nRadius=nNext; // volatile only keeps nRadius (and nSpawnY below) in memory, as the original does
            if(nStepX && nStepY && nFlags){if(nNext>nMaxRadius)break;}else{if(nNext>nMaxRadius)break;}
        }while(1);
    }
    if(!nSpawnX || !nSpawnY) return 0;
    if(nFlags&1) return (D2UnitStrc*)1;
    int nAllocFlags=1;if(nFlags&0x20)nAllocFlags=3;
    D2UnitStrc* pMonster=SUNIT_AllocUnitData(1,pCreate->nMonsterId,nSpawnX,*(int volatile*)&nSpawnY,pCreate->pGame,pRoom,nAllocFlags,pCreate->nAnimMode,pCreate->nUnitGUID);
    if(pMonster)
    {
        int bNeverCount=nFlags&8;
        if(pRecord->nMonStatsFlags[2]&gbNeverCount_006CE270) bNeverCount=1;
        sub_00547D90_RegisterSpawn(pCreate->pGame->pMonReg,pRoom,pMonster,bNeverCount);
        D2RoomCoordListStrc* pList=pCreate->pRoomCoordList;
        if(!pList) pList=D2Common_10096(pRoom,nSpawnX,nSpawnY);
        sub_00552D60_SetVision(pMonster,pList);
        switch(pRecord->nAlign)
        {
        default:SUNIT_SetAlignment(pMonster,0,1);break;
        case 2:SUNIT_SetAlignment(pMonster,1,1);break;
        case 1:SUNIT_SetAlignment(pMonster,2,1);pMonster->dwFlags|=0x20000;break;
        }
        if(!(nFlags&2)) MONSTERSPAWN_SetupNormalMods(pCreate,pMonster);
        MONSTERSPAWN_SetupBossMods(pCreate,pMonster);
        if(!(nFlags&0x40)) MONSTERSPAWN_SpawnMinionParty(pCreate,pMonster);
    }
    return pMonster;
    }
}

// 0x005B31B0
int __fastcall sub_005B31B0_SpawnMinionsAt(D2GameStrc* pGame, D2UnitStrc* pOwner, int nX, int nY, int nMonsterId, int nAnimMode, int a5, int nCount, short nFlags)
{
    int nResult = 0;
    if (!pOwner)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pOwner);
    const int nOwnerId = pOwner->dwUnitId;
    for (int i = 0; i < nCount; ++i)
    {
        D2UnkMonCreateStrc monCreate;
        monCreate.nUnitGUID = 0;
        monCreate.nMonsterId = nMonsterId;
        monCreate.nAnimMode = nAnimMode;
        monCreate.pGame = pGame;
        monCreate.pRoomCoordList = 0;
        monCreate.pRoom = pRoom;
        monCreate.nMaxSearchRings = a5;
        monCreate.nFlags = nFlags;
        monCreate.nX = nX;
        monCreate.nY = nY;

        D2UnitStrc* pMinion = D2GAME_SpawnNormalMonster(&monCreate);
        if (pMinion)
        {
            nResult = 1;
            AIGENERAL_SetOwnerData(pGame, pMinion, nOwnerId, 1, 0, 0);
            AIGENERAL_AllocMinionList(pGame, pOwner, pMinion);
        }
    }

    return nResult;
}


// 0x005B3270
int __fastcall MONSTERSPAWN_SpawnFormation(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pOwner, int nClassId, int nAnimMode, D2UnkMonCreateStrc2* pInfo, short nFlags)
{
    int nResult = 0;
    D2UnitStrc* pLeader = 0;
    int bForce = 0;
    int bIncrement = 0;
    if (pInfo->unk0x08 & 1) bIncrement = 1;
    if (nFlags & 1) bForce = 1;
    const int nCount = pInfo->nRecordCount;
    for (int i = 0; i < nCount; ++i)
    {
        pInfo = (D2UnkMonCreateStrc2*)pInfo->records;
        D2UnkMonCreateStrc3* pRecord = (D2UnkMonCreateStrc3*)pInfo;
        switch (bForce ? 4 : pRecord->nSpawnType)
        {
        case 1:
            pLeader = MONSTERSPAWN_SpawnWithOwnerData(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0, 0);
            if (pLeader) nResult = 1;
            break;
        case 2:
            pLeader = MONSTERSPAWN_SpawnWithOwnerData(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0);
            if (pLeader) nResult = 1;
            break;
        case 5:
            if (pOwner)
            {
                D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 0);
                if (pMinion)
                {
                    AIGENERAL_SetOwnerData(pGame, pMinion, GAME_GetUnitGUID(pOwner), GAME_GetUnitTypeOrInvalid(pOwner), 0, 0);
                    nResult = 1;
                }
            }
            break;
        case 3:
            if (pLeader && sub_005B31B0_SpawnMinionsAt(pGame, pLeader, nX + pRecord->nXOffset, nY + pRecord->nYOffset, nClassId, nAnimMode, -1, 1, 0)) nResult = 1;
            break;
        case 0:
        {
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.nMaxSearchRings = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (D2GAME_SpawnNormalMonster(&monCreate)) nResult = 1;
            break;
        }
        case 4:
        {
            nResult = 1;
            D2UnkMonCreateStrc monCreate;
            monCreate.nUnitGUID = 0;
            monCreate.nMonsterId = nClassId;
            monCreate.nAnimMode = nAnimMode;
            monCreate.nMaxSearchRings = -1;
            monCreate.pGame = pGame;
            monCreate.pRoomCoordList = 0;
            monCreate.pRoom = pRoom;
            monCreate.nFlags = nFlags;
            monCreate.nX = nX + pRecord->nXOffset;
            monCreate.nY = nY + pRecord->nYOffset;
            if (!D2GAME_SpawnNormalMonster(&monCreate)) return 0;
            break;
        }
        }
        if (bIncrement) ++nClassId;
    }
    return nResult;
}

// 0x005B34C0
int __fastcall MONSTERSPAWN_SpawnBonePrison(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7)
{
    int nResult = 0;
    if (a6 == 340)
    {
        if (!pTargetUnit)
            return 0;

        const int nX = CLIENTS_GetUnitX_Inline(pTargetUnit);
        const int nY = CLIENTS_GetUnitY_Inline(pTargetUnit);
        nResult = sub_005B3270(pGame, pRoom, nX, nY, 0, 340, 8, &gtBonePrisonSpawnInfo, a7);
    }
    return nResult;
}

static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x005B3570
int __fastcall MONSTERSPAWN_SpawnRandomMonsterForLevel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
    D2_ASSERT(pLevelsTxtRecord->nNumNormalMonsters, 1264);

    int nIndex = ITEMS_RollLimitedRandomNumber(pRoom ? &pRoom->pSeed : 0, pLevelsTxtRecord->nNumNormalMonsters);
    int nMonsterId = -1;
    int nCounter = 0;
    for (nCounter = 0; nCounter < pLevelsTxtRecord->nNumNormalMonsters; ++nCounter)
    {
        ++nIndex;
        if (nIndex >= pLevelsTxtRecord->nNumNormalMonsters)
        {
            nIndex = 0;
        }

        nMonsterId = pLevelsTxtRecord->wNormalMonsters[nIndex];
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
        if (pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_ISSPAWN >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_ISSPAWN & 7])
        {
            break;
        }
    }

    if (nMonsterId == -1)
    {
        return 0;
    }

    D2_ASSERT(nCounter < pLevelsTxtRecord->nNumNormalMonsters, 1287);

    D2UnkMonCreateStrc monCreate;
    monCreate.nUnitGUID = 0;
    monCreate.nMonsterId = nMonsterId;
    monCreate.nAnimMode = 1;
    monCreate.pRoom = pRoom;
    monCreate.pRoomCoordList = 0;
    monCreate.nMaxSearchRings = 5;
    monCreate.pGame = pGame;
    monCreate.nFlags = 0;
    monCreate.nX = nX;
    monCreate.nY = nY;
    return D2GAME_SpawnNormalMonster(&monCreate) != 0;
}

#include "gen/data/Source/D2Game/Unknown_005B24E0.inc"
