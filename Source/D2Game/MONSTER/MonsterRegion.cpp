#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2ObjectIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2ObjModes.h"
#include "D2ItemModes.h"
#include "D2Packets.h"
#include "D2QuestData.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00731968

struct D2DifficultyLevelsTxt;

struct D2MonsterRegionStrc;

union D2SeedStrc;

struct D2MonRegDataStrc;

struct D2LevelsTxt;

struct D2MonStatsTxt;

struct D2DataTablesStrc;

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const char gszMonsterRegion[]; // 0x006E0CF8

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char*,const char*,int); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09

extern "C" void* __cdecl memset(void*,int,unsigned int); // 0x00681EF0

void* __fastcall FOG_AllocPool(void*,int,const char*,int,int); // 0x0040B430

void __fastcall SEED_InitLowSeed(D2SeedStrc*,unsigned int); // 0x00650E40

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int); // 0x0061DB70

void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc*,D2MonRegDataStrc*,int); // 0x005BDB20

static void __stdcall MONSTERREGION_SelectMonsters(D2SeedStrc* pSeed, int bHigher, D2LevelsTxt* pLevels, D2MonsterRegionStrc* pRegion); // 0x005475E0

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QUEST_A2Q3_TAINTEDSUN 10

#define QUEST_A2Q4_HORAZONTOME 11

#define QUEST_A3Q1_LAMESENTOME 15

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_OBJECT 2

#define UNIT_MISSILE 3

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define UNIT_INVALID 6

#define STRCOLOR_DARK_GOLD 4

#define OBJRGN_WELL_DISTANCE 100

#define OBJRGN_SHRINE_DISTANCE 50

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_NEUTRAL 1

#define UNIT_ALIGNMENT_GOOD 2

#define MONTYPEFLAG_OTHER 1

#define ACT_III 2

#define MONSTATSFLAGINDEX_FLYING 14

#define NUM_QUEST_PLAYER_GUIDS 32

#define LEVEL_FIRST_COUNCIL_LIMIT 108

#define QUEST_LOG_FLAGS 2

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_PRIMARYGOALDONE 13

#define UNITFLAG_TARGETABLE 0x00000002


struct D2QuestInfoStrc;

struct D2ObjectControlStrc;

struct D2PlayerDataStrc;

struct D2SuperUniquesTxt;

struct D2ObjInitFnStrc;


struct D2StaticPathStrc;

struct D2QuestTimerStrc;

struct D2ItemsTxt;


struct D2PackedGuidStrc;

struct D2MessageStrc;

struct D2GSPacketSrv27;


struct D2UnkPlrMsgStrc;

struct D2QuestGUIDStrc;

struct D2QuestInitTableStrc;


struct D2GSPacketSrv91;

struct Obj00545290;

struct Obj005452C0;

struct D2DrlgCoordsStrc;

struct D2ObjOperateFnStrc;


D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    D2QuestTimerStrc* pTimer;
    unsigned int dwTick;
    D2SeedStrc pSeed;
    unsigned char unk0x20;
    unsigned char unk_21[0x3];
};

void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F380

void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F440

void __fastcall ACT2Q3_InitAltarObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059A3F0

void __fastcall ACT3Q1_InitTomeObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x005B7310

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690


void __stdcall TEXT_AddNodeToTextList(D2TextHeaderStrc* pTextHeader, short nStringId, int nMenu); // 0x006612F0

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0




#pragma pack(push, 1)

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    D2MessageListStrc tMessageList;
};

#pragma pack(pop)



extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x00681CE0

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4

int dword_6FD4DC34; // 0x008846DC

extern const D2UnkPlrMsgStrc gaUnitModeMessages[]; // 0x007319E8

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall PLRMSG_BroadcastChatMessage(D2GameStrc* pGame, const char* szMessage, unsigned char nColor); // 0x0054A930

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*)); // 0x005537D0

void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket); // 0x0053D700

int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593CB0

void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059D6A0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __fastcall SCMD_SendPacket0x5D(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710

int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059DB20

int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BBFA0

int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel); // 0x0058D090

int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058E640

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AD80

void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AE10

void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x00587950

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId); // 0x00573500

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue); // 0x0053BE40

void __fastcall SCMD_SendUnitStat(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short nStatId, int nValue); // 0x0053C1D0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50

extern unsigned int gdwBitMasks[]; // 0x006CE268

void __fastcall sub_0059B6C0_JerhynSpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6C0

void __fastcall sub_0059B6D0_Act2Guard2SpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6D0

int __fastcall ACT3Q4_UnitIterate_SetGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BAC70

void __fastcall ACT3Q4_CheckGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BACF0

void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010

void __fastcall D2GAME_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10

int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C150

int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* pItemStatus); // 0x00560CD0

int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0

void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

extern "C" const char gszObjRgnSourceFile[]; // 0x006E0C40

extern "C" const char gszPlrMsgSourceFile[]; // 0x006E1050


void __fastcall D2GAME_PACKETS_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket); // 0x0053D830

void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670

void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00544520

void __fastcall D2GAME_PACKETS_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket); // 0x0053DFE0

extern D2QuestInitTableStrc sgQuestInit[]; // 0x00731510

int __fastcall QUESTS_FXIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005456F0

int __fastcall ACT2Q6_ActivateTomb(D2GameStrc* pGame, D2CoordStrc* pCoord, D2ActiveRoomStrc** ppRoom); // 0x0059DFD0

void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BB550

void __fastcall sub_0058CFD0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058CFD0

void __fastcall ACT1Q3_ACT1Q3_InitMalusObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00592090

void __fastcall ACT1Q4_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00594060

void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00588CA0

void __fastcall ACT5Q3_RemoveNihlathakFromTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00589540

void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A500

void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058A730

void __fastcall ACT5Q4_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058B940

void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058C0E0

void __fastcall ACT1Q4_SpawnCainInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593290

void __fastcall ACT1Q4_UpdatePortalInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005942C0

void __fastcall ACT1Q4_DropWirtsBodyGold(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00594630

void __fastcall ACT1Q5_SpawnChestMissilesAndEvent(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005956C0

void __fastcall ACT2Q4_InitializeHaremBlockerObject(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059B710

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

void __fastcall ACT4Q2_SpawnSealBoss(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B5750

void __fastcall ACT4Q3_CreateReward(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B6710

void __fastcall ACT3Q2_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B85E0

void __fastcall ACT3Q6_UpdateHellGatePortal(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BCAC0

void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572420

int __fastcall PLRINTRO_GetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572470

void __fastcall D2GAME_PACKETS_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket); // 0x0053E060

struct Obj00545290 { unsigned int dwValues[32]; unsigned short wCount80; };

struct Obj005452C0 { unsigned char bUnknown00[0x1C]; unsigned int dwValues1C[32]; unsigned short wCount9C; };

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0


void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0

struct D2QuestDataStrc;

#define QUEST_A1Q4_CAIN 4

#define QUEST_A2Q1_RADAMENT 8

#define QUEST_A2Q5_SUMMONER 12

#define MAX_QUEST_STATUS 41

#define QUESTSTATEFLAG_A1Q1 1

#define QUESTSTATEFLAG_A2Q4 12

#define QUEST_A1Q1_DENOFEVIL 1

#define ACT_II 1

#define PACKET_QUESTSTATUS 0x52

#define PACKET_QUESTPROGRESS 0x50

#define LINE_UPDATEFLAGS_CLIENT 0xCA7

#define LINE_STATUS_CLIENT 0x49A

#define LINE_STATUS_QUESTNO 0x4B3

#define LINE_STATUS_FILTER 0x4CB


typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00592F80

void __fastcall ACT2Q1_OnRadamentCreated(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005991B0

void __fastcall ACT2Q5_OnSummonerCreated(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059C3B0

int __fastcall ACT1Q6_IsAndarielKilled(D2QuestDataStrc* pQuestData); // 0x005968C0

unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0

void __fastcall D2GAME_SendPacket0x8A_6FC3FA60(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket); // 0x0053DFF0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0

void __fastcall D2GAME_SendPacket0x52(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket); // 0x0053D840

void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pQuestList, D2BitBufferStrc* pQuestFlags); // 0x00543F90

int __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData); // 0x00588C50

unsigned short __fastcall ACT1Q1_GetMonstersToBeKilled(D2QuestDataStrc* pQuestData); // 0x005901E0

void __fastcall D2GAME_PACKETS_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940

void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597310

void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x005BCFD0

struct D2MessageListStrc;

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0

void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMessageList); // 0x00661480

static void __stdcall QUESTS_StatusCycler(bool bForceActive, D2QuestArgStrc* pArgs);

static void __stdcall QUESTS_EventCallback(bool bCheckActive, unsigned char bCheckAct, D2QuestArgStrc* pArgs);

void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nOldLevelId, int nTargetLevelId, D2UnitStrc* pUnit);

struct D2ActiveRoomStrc;

struct D2RoomStrc;

void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

struct D2BitBufferStrc;

typedef char QUESTINIT_check_data[sizeof(D2QuestDataStrc) == 0xF8 ? 1 : -1];

typedef char QUESTINIT_check_info[sizeof(D2QuestInfoStrc) == 0x24 ? 1 : -1];

typedef void (__fastcall* QUESTINIT)(D2QuestDataStrc* pQuestData);

struct D2QuestIntroTableStrc
{
    QUESTINIT pfInit;
    unsigned char nAct;
    unsigned char pad0x05[3];
};

extern int gnQuestInitTableCount;                                                                  // 0x00731888

extern D2QuestIntroTableStrc sgQuestIntro[];                                                  // 0x0073188C

extern int gnQuestIntroTableCount;                                                                 // 0x007318AC

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30

D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool);                                         // 0x0065C430

#define QUESTS_SEED_STEP_HIGH_FIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

static void QUESTS_ClearQuestIntroState(D2GameStrc* pGame, int nChainNo);

struct D2CoordStrc;

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId); // 0x00558200

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0

int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200

void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

void __fastcall QUESTS_StatusCycleNpcActivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

void __fastcall QUESTS_StatusCycleObjectReset(D2GameStrc* pGame, D2UnitStrc* pTarget);

void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl);

void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC);

void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage);

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker);

void __fastcall QUESTS_PlayerDroppedWithQuestItem(D2GameStrc* pGame, D2UnitStrc* pPlayer);

void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int bGameEnter);

static void __stdcall QUESTS_DeleteItemEx(D2InventoryStrc* pInventory, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);

static void QUESTS_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct);

#define SUMMONER_FLAG 2

void __fastcall MONSTERREGION_InitializeAll(void* pool,D2MonsterRegionStrc** regions,D2SeedStrc* seed,unsigned int lowSeed,unsigned char difficulty,int expansion); // 0x005479C0

void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int a5); // 0x0040B480

void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00573570

void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490

extern const unsigned char gnSpawnMask; // 0x006CE268

extern const unsigned char gnRangedMask; // 0x006CE278

extern "C" void* __cdecl memmove(void*,const void*,unsigned int); // 0x00683840

static inline unsigned __int64 Roll(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int RollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;
    return (unsigned int)((((unsigned int)nMax - 1) & (unsigned int)nMax) ? (unsigned int)Roll(pSeed) % nMax : Roll(pSeed) & (nMax - 1));
}

static inline D2MonStatsTxt* MonStats(int id) {
 if(id<0||id>=sgptDataTables->nMonStatsTxtRecordCount)return 0;
 return &sgptDataTables->pMonStatsTxt[id];
}

// 0x005475E0
static void __stdcall MONSTERREGION_SelectMonsters(D2SeedStrc* pSeed, int bHigher, D2LevelsTxt* pLevels, D2MonsterRegionStrc* pRegion)
{
    int nToSpawn = pLevels->nNumMon;
    if (nToSpawn > 13)
        nToSpawn = 13;

    int nAvailable = pLevels->nNumNormalMonsters;
    if (bHigher)
        nAvailable = pLevels->nNumNightmareHellMonsters;

    if (nToSpawn > nAvailable)
        nToSpawn = nAvailable;

    short nMonsterIds[25];
    D2MonRegDataStrc* pMonData = pRegion->pMonData;
    if (bHigher)
    {
        for (int i = 0; i < pLevels->nNumNightmareHellMonsters; ++i)
            nMonsterIds[i] = pLevels->wNightmareHellMonsters[i];
    }
    else
    {
        for (int i = 0; i < pLevels->nNumNormalMonsters; ++i)
            nMonsterIds[i] = pLevels->wNormalMonsters[i];
    }

    for (int i = 0; i < nToSpawn && nAvailable > 0; ++i)
    {
        int nIndex = RollLimited(pSeed, nAvailable);
        short nMonsterId = nMonsterIds[nIndex];
        if (!i && pLevels->nRangedSpawn)
        {
            for (int j = 0; j < 20; ++j)
            {
                D2MonStatsTxt* pMonStatsTxtRecord = MonStats(nMonsterId);
                if (pMonStatsTxtRecord && (pMonStatsTxtRecord->nMonStatsFlags[3] & gnRangedMask))
                    break;

                nIndex = RollLimited(pSeed, nAvailable);
                nMonsterId = nMonsterIds[nIndex];
            }
        }

        --nAvailable;
        if (nIndex < nAvailable)
            memmove(&nMonsterIds[nIndex], &nMonsterIds[nIndex + 1], 2 * (nAvailable - nIndex));

        D2MonStatsTxt* pMonStatsTxtRecord = MonStats(nMonsterId);
        if (pMonStatsTxtRecord && (pMonStatsTxtRecord->nMonStatsFlags[0] & gnSpawnMask))
        {
            pMonData->nMonHcIdx = nMonsterId;
            pMonData->nRarity = pMonStatsTxtRecord->rarity;
            pRegion->nTotalRarity += pMonStatsTxtRecord->rarity;
            ++pRegion->nSpawnCount;
            ++pRegion->nMonCount;
            ++pMonData;
        }
    }
}

// 0x005479C0
void __fastcall MONSTERREGION_InitializeAll(void* pool,D2MonsterRegionStrc** regions,D2SeedStrc* seed,unsigned int lowSeed,unsigned char difficulty,int expansion)
{
 SEED_InitLowSeed(seed,lowSeed);
 ++regions;
 if(!DATATBLS_GetDifficultyLevelsTxtRecord(difficulty)) {
  FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),0x83);exit(-1);
 }
 for(int level=1;level<sgptDataTables->nLevelsTxtRecordCount;++level) {
  D2MonsterRegionStrc* region=(D2MonsterRegionStrc*)FOG_AllocPool(pool,sizeof(D2MonsterRegionStrc),gszMonsterRegion,0x87,0);
  memset(region,0,sizeof(D2MonsterRegionStrc));
  D2LevelsTxt* levels=DATATBLS_GetLevelsTxtRecord(level);
  region->nAct=levels->nAct;region->dwlevel=level;
  region->nMonsterCount=levels->dwMonDen[difficulty];region->nBossMin=levels->nMonUMin[difficulty];region->nBossMax=levels->nMonUMax[difficulty];
  region->nMonWander=levels->nWandering;region->nQuest=levels->nQuest;region->nTrapVariant=-1;region->nMonsterRegionLevel=-1;
  if(expansion) {region->nDungeonLevel=levels->wMonLvlEx[difficulty];region->nDungeonLevelEx=levels->wMonLvlEx[difficulty];}
  else {region->nDungeonLevel=(short)levels->wMonLvl[difficulty];region->nDungeonLevelEx=(short)levels->wMonLvl[difficulty];}
  MONSTERREGION_SelectMonsters(seed,difficulty>0,levels,region);
  D2MonRegDataStrc* entry=region->pMonData;
  for(int i=0;i<region->nMonCount;++i){MONSTERCHOOSE_GenerateComponentVariants(seed,entry,3);++entry;}
  *regions=region;++regions;
 }
}

// 0x00547B50
void __fastcall MONSTERREGION_FreeAll(void* pMemPool, D2MonsterRegionStrc** ppMonsterRegion)
{
    ++ppMonsterRegion;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; ++i, ++ppMonsterRegion)
    {
        if (*ppMonsterRegion)
        {
            FOG_FreeServerMemory(pMemPool, *ppMonsterRegion, ".\\MONSTER\\MonsterRegion.cpp", 197, 0);
        }
    }
}

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00547BB0
D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId)
{
    return ppMonsterRegion[nLevelId];
}

void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc* pSeed, D2MonRegDataStrc* pMonRegData, int nCount); // 0x005BDB20

static inline int MONSTERREGION_SanitizeMonsterId(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return nMonsterId;
    }

    return -1;
}

static __forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }

    return 0;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

// 0x00547BC0
D2MonRegDataStrc* __fastcall MONSTERREGION_GetMonsterComponentData(D2MonsterRegionStrc** ppMonsterRegion, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit)
{
    const short nClassId = UNITS_GetWeaponClass(pUnit);

    switch (MONSTERREGION_SanitizeMonsterId(nClassId))
    {
    case 195:
    case 196:
    case 294:
    case 296:
        return 0;
    default:
        break;
    }

    D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(ppMonsterRegion, DUNGEON_GetLevelIdFromRoom(pRoom));
    if (!pMonsterRegion)
    {
        return 0;
    }

    D2MonRegDataStrc* pMonsterRegionData = pMonsterRegion->pMonData;
    int nCounter = 0;
    while (nCounter < pMonsterRegion->nSpawnCount)
    {
        if ((unsigned short)pMonsterRegionData->nMonHcIdx == (unsigned short)nClassId)
        {
            return pMonsterRegionData;
        }

        ++pMonsterRegionData;
        ++nCounter;
    }

    if (nCounter >= 13)
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(nClassId);
    if (pMonStats2TxtRecord && pMonStats2TxtRecord->nTotalPieces > 2u)
    {
        pMonsterRegionData->nMonHcIdx = nClassId;
        ++pMonsterRegion->nSpawnCount;
        MONSTERCHOOSE_GenerateComponentVariants(&pUnit->pSeed, pMonsterRegionData, 3);
    }

    return pMonsterRegionData;
}

// 0x00547D20
void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame)
{
    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);

    const int nSeed = (unsigned int)ITEMS_RollRandomNumberInline(&pGame->pGameSeed);
    SEED_InitLowSeed(&tSeed, nSeed);
    pGame->dwMonSeed = nSeed;
    MONSTERREGION_InitializeAll(pGame->pMemoryPool, pGame->pMonReg, &tSeed, nSeed, pGame->nDifficulty, pGame->bExpansion);
}

// 0x00547D90
void __fastcall MONSTERREGION_RegisterSpawnedMonster(D2MonsterRegionStrc** ppMonsterRegion, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int bToggleFlag)
{
    if (bToggleFlag)
    {
        MONSTER_ToggleSummonerFlag(pUnit, SUMMONER_FLAG, 1);
    }
    else
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[DUNGEON_GetLevelIdFromRoom(pRoom)];
        ++pMonsterRegion->dwMonSpawnCount;
    }
}

// 0x00547DD0
void __fastcall MONSTERREGION_UpdateSpawnCountForAlignmentChange(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit, int nPreviousAlignment, int nNewAlignment)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER && !SUNIT_IsDead(pUnit) && !MONSTER_CheckSummonerFlag(pUnit, 2))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (pMonsterRegion && !pMonsterRegion->nQuest && nPreviousAlignment != nNewAlignment)
        {
            if (nPreviousAlignment == UNIT_ALIGNMENT_EVIL && (nNewAlignment == UNIT_ALIGNMENT_NEUTRAL || nNewAlignment == UNIT_ALIGNMENT_GOOD))
            {
                --pMonsterRegion->dwMonSpawnCount;
            }

            if (nNewAlignment == UNIT_ALIGNMENT_EVIL && nPreviousAlignment != UNIT_ALIGNMENT_UNASSIGNED)
            {
                ++pMonsterRegion->dwMonSpawnCount;
            }
        }
    }
}

// 0x00547E50
void __fastcall MONSTERREGION_RecordMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, SUMMONER_FLAG))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            ++pMonsterRegion->dwMonKillCount;
        }
    }
}

// 0x00547E90
void __fastcall MONSTERREGION_UndoMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, SUMMONER_FLAG))
    {
        D2MonsterRegionStrc* pMonsterRegion = ppMonsterRegion[MONSTER_GetLevelId(pUnit)];
        if (!STATLIST_GetUnitAlignment(pUnit))
        {
            --pMonsterRegion->dwMonKillCount;
        }
    }
}

// 0x00547ED0
void __fastcall MONSTERREGION_AdjustCountsForInactiveMonster(D2MonsterRegionStrc** ppMonRegion, int nLevelId1, int nLevelId2, int nAlignment, int bDead, int a6, D2UnitStrc* pUnit)
{
    D2MonsterRegionStrc* pMonsterRegion1 = ppMonRegion[nLevelId1];
    D2MonsterRegionStrc* pMonsterRegion2 = ppMonRegion[nLevelId2];
    if (pUnit)
    {
        if (pMonsterRegion2 != pMonsterRegion1)
        {
            MONSTER_SetLevelId(pUnit, nLevelId1);
        }

        if (!a6 && STATLIST_GetUnitAlignment(pUnit) == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion2->dwMonSpawnCount;

            if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_OTHER))
            {
                --pMonsterRegion2->dwUniqueCount;
            }
        }
    }
    else
    {
        if (!a6 && !bDead && nAlignment == UNIT_ALIGNMENT_EVIL)
        {
            --pMonsterRegion1->dwMonSpawnCount;
        }
    }
}

