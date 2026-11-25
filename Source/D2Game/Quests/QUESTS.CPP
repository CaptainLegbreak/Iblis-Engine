#include "D2ObjectIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2ObjModes.h"
#include "D2ItemModes.h"
#include "D2Game.h"
#include "D2GameObjs.h"
#include "D2ItemsWorld.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2Packets.h"
#include "D2QuestData.h"
#include "D2LanguageNames.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define QUEST_A2Q3_TAINTEDSUN 10

#define QUEST_A2Q4_HORAZONTOME 11

#define QUEST_A3Q1_LAMESENTOME 15

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

struct D2QuestChainStrc;

struct D2QuestInfoStrc;

struct D2ObjectControlStrc;

struct D2PlayerDataStrc;

struct D2SuperUniquesTxt;

struct D2ObjInitFnStrc;


struct D2NPCMessageTableStrc;

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2QuestTimerStrc;

struct D2ItemsTxt;

struct D2LevelsTxt;


struct D2MonsterRegionStrc;


struct D2PackedGuidStrc;

struct D2MessageStrc;

struct D2GSPacketSrv27;


struct D2UnkPlrMsgStrc;

struct D2QuestGUIDStrc;

struct D2MonStatsTxt;

struct D2QuestInitTableStrc;


struct D2GSPacketSrv91;

struct Obj00545290;

struct Obj005452C0;

struct D2DrlgCoordsStrc;

struct D2ObjOperateFnStrc;

struct D2Unk00545D40Rec;

struct D2QuestChainStrc
{
    D2QuestDataStrc* pQuestData;
    D2QuestChainStrc* pNext;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

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

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F380

void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F440

void __fastcall ACT2Q3_InitAltarObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059A3F0

void __fastcall ACT3Q1_InitTomeObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x005B7310

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690


struct D2NPCMessageTableStrc
{
    D2NPCMessageStrc pMessages[16];
    int nMessages;
};

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

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

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


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

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

struct Obj00545290
{
    unsigned int dwValues[32];
    unsigned short wCount80;
};

struct Obj005452C0
{
    unsigned char bUnknown00[0x1C];
    unsigned int dwValues1C[32];
    unsigned short wCount9C;
};

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

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

struct D2Unk00545D40Rec
{
    int nFirst;
    int nSecond;
    unsigned char nKind;
    unsigned char bActive;
    unsigned char b0A;
    unsigned char b0B;
    char unk0x0C[0x90];
    unsigned short w9C;
    char unk0x9E[0x5A];
};

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

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed);                                                           // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

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

void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc* pSeed, D2MonRegDataStrc* pMonRegData, int nCount); // 0x005BDB20

// 0x00543520
D2BitBufferStrc* __fastcall sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x00543540
D2PlrIntroStrc* __fastcall QUESTS_GetPlayerIntro(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
}

// 0x00543560
int __fastcall QUESTS_GetSuperUniqueHcIdx(int nSuperUnique)
{
    if (nSuperUnique >= 0 && nSuperUnique < sgptDataTables->nSuperUniquesTxtRecordCount)
    {
        return sgptDataTables->pSuperUniquesTxt[nSuperUnique].dwHcIdx;
    }
    return -1;
}

// 0x00543590
void __fastcall QUESTS_FreeChainRecord(D2GameStrc* pGame, D2QuestChainStrc* pRecord)
{
    while (pRecord)
    {
        D2QuestChainStrc* pNext = pRecord->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pRecord, gszQuestsSourceFile, 80, 0);
        pRecord = pNext;
    }
}

// 0x005435C0
static int __stdcall QUESTS_AddQuestToUnitEventList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2QuestDataStrc* pQuestData)
{
    D2QuestChainStrc* i = pUnit->pQuestEventList;
    D2_ASSERT(pQuestData, 93);
    for (; i; i = i->pNext)
    {
        if (!i->pQuestData)
        {
            break;
        }
        if (i->pQuestData == pQuestData)
        {
            return 0;
        }
    }
    D2QuestChainStrc* pNew = (D2QuestChainStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2QuestChainStrc), gszQuestsSourceFile, 104, 0);
    pNew->pQuestData = pQuestData;
    pNew->pNext = pUnit->pQuestEventList;
    pUnit->pQuestEventList = pNew;
    return 1;
}

// 0x00543640
D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);

    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

// 0x00543690
D2QuestDataStrc* __fastcall QUESTS_FindQuestEvent(D2UnitStrc* pUnit, int nQuestId)
{
    for (D2QuestChainStrc* i = pUnit->pQuestEventList; i; i = i->pNext)
    {
        if (!i->pQuestData)
        {
            break;
        }

        if (i->pQuestData->nQuestNo == nQuestId)
        {
            return i->pQuestData;
        }
    }

    return 0;
}

// 0x005436B0
int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuest)
{
    D2_ASSERT(nQuest >= 0, 224);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, nQuest);
    if (pQuestData)
    {
        int nUnitType = UNIT_INVALID;
        if (pUnit)
        {
            nUnitType = pUnit->dwUnitType;
        }
        if (nQuest == QUEST_A1Q4_CAIN)
        {
            if (nUnitType == UNIT_OBJECT && pUnit && pUnit->dwClassId == OBJECT_INVISIBLE_OBJECT)
            {
                ACT1Q4_SetInvisibleObjectGUID(pGame, pQuestData, pUnit);
            }
        }
        else if (nQuest == QUEST_A2Q1_RADAMENT)
        {
            if (nUnitType == UNIT_MONSTER && pUnit && pUnit->dwClassId == MONSTER_RADAMENT)
            {
                ACT2Q1_OnRadamentCreated(pGame, pQuestData, pUnit);
            }
        }
        else if (nQuest == QUEST_A2Q5_SUMMONER)
        {
            if (nUnitType == UNIT_MONSTER && pUnit && pUnit->dwClassId == MONSTER_SUMMONER)
            {
                ACT2Q5_OnSummonerCreated(pGame, pQuestData, pUnit);
            }
        }
        return QUESTS_AddQuestToUnitEventList(pGame, pUnit, pQuestData);
    }
    return 0;
}

// 0x00544070
void __fastcall QUESTS_DebugOutput(D2GameStrc* pGame, const char* szMessage, const char* szFile, int nLine)
{
    if (dword_6FD4DC34)
    {
        PLRMSG_BroadcastChatMessage(pGame, szMessage, STRCOLOR_DARK_GOLD);
    }
}

// 0x00544090
void __fastcall QUESTS_SetQuestDebugFlag(int nValue)
{
    dword_6FD4DC34 = nValue;
}

// 0x005440A0
static void __stdcall QUESTS_DeleteItemEx(D2InventoryStrc* pInventory, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 0x534);
    int nFlags = 0;
    ITEMS_SetOrRemoveFlag(&nFlags, 0x20, 1);
    const int nAnimMode = !pItem ? 0 : pItem->dwAnimMode;
    switch (nAnimMode)
    {
    case 0:
        ITEMS_SetItemCell(pItem, ITEMS_GetInvPage(pItem));
        D2GAME_UpdateClientItem_6FC3E9D0(pClient, pPlayer, pItem, nFlags);
        D2GAME_RemoveItem(pGame, pPlayer, pItem, 0);
        break;
    case 1:
    {
        const int nBodyLoc = INVENTORY_GetItemsXPosition(pInventory, pItem);
        int a5;
        ITEMMODE_UnequipBodyItem(pGame, pPlayer, nBodyLoc, 1, &a5);
        break;
    }
    case 4:
        D2GAME_RemoveItemIfOnCursor_6FC49760(pGame, pPlayer, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        break;
    }
}

// 0x00544160
void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode)
{
    D2UnitStrc* pItem = ITEMS_FindQuestItem(pGame, pPlayer, dwCode);
    if (pItem)
    {
        QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
    }
}

// 0x00543790
void __fastcall QUESTS_InitScrollTextChain(D2QuestDataStrc* pQuest, D2TextHeaderStrc* pTextControl, int nNPCID, int nIndex)
{
    D2NPCMessageTableStrc* pTables = (D2NPCMessageTableStrc*)pQuest->pNPCMessages;

    for (int i = 0; i < pTables[nIndex].nMessages; ++i)
    {
        if (pTables[nIndex].pMessages[i].nNPCNo == nNPCID)
        {
            int nMenu = pTables[nIndex].pMessages[i].nMenu;
            if (nMenu == 1)
            {
                nMenu = 0;
            }

            TEXT_AddNodeToTextList(pTextControl, pTables[nIndex].pMessages[i].nStringIndex, nMenu);
        }
    }
}

static inline int DATATBLS_GetSuperUniqueHcIdx_Inline(int nSuperUniqueId)
{
    if (nSuperUniqueId >= 0 && nSuperUniqueId < sgptDataTables->nSuperUniquesTxtRecordCount)
    {
        return sgptDataTables->pSuperUniquesTxt[nSuperUniqueId].dwHcIdx;
    }
    return -1;
}

// 0x00543800
void __fastcall QUESTS_QuestFree(D2GameStrc* pGame)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;
    D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest;
    while (pQuestData)
    {
        D2QuestDataStrc* pPrevQuestData = pQuestData->pPrev;
        if (pQuestData->pQuestDataEx)
            FOG_FreeServerMemory(pGame->pMemoryPool, pQuestData->pQuestDataEx, gszQuestsSourceFile, 0x1DF, 0);
        FOG_FreeServerMemory(pGame->pMemoryPool, pQuestData, gszQuestsSourceFile, 0x1E1, 0);
        pQuestData = pPrevQuestData;
    }
    D2QuestTimerStrc* pTimer = pQuestControl->pTimer;
    while (pTimer)
    {
        D2QuestTimerStrc* pNextTimer = pTimer->pNext;
        FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x1E8, 0);
        pTimer = pNextTimer;
    }
    QUESTRECORD_FreeRecord(pGame->pMemoryPool, pQuestControl->pQuestFlags);
    FOG_FreeServerMemory(pGame->pMemoryPool, pQuestControl, gszQuestsSourceFile, 0x1EC, 0);
}

// 0x005438B0
D2SeedStrc* __fastcall QUESTS_GetGlobalSeed(D2GameStrc* pGame)
{
    if (pGame->pQuestControl)
    {
        return &pGame->pQuestControl->pSeed;
    }

    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 507);
    exit(-1);
}

static inline int QUESTS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwClassId;
}

static inline D2QuestDataStrc* QUESTS_GetQuestDataInline(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);
    if (!pControl)
    {
        return 0;
    }
    for (D2QuestDataStrc* pQuestData = pControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
        {
            return pQuestData;
        }
    }
    return 0;
}

// 0x005438E0
static void __stdcall QUESTS_EventCallback(bool bCheckActive, unsigned char bCheckAct, D2QuestArgStrc* pArgs)
{
    D2QuestInfoStrc* pQuestControl = pArgs->pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }
    unsigned char nAct = 0xFF;
    D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest;
    if (bCheckAct == 1)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pArgs->pPlayer);
        if (pRoom)
        {
            nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        }
    }
    while (pQuestData)
    {
        if (pQuestData->pCallback[pArgs->nEvent] && (bCheckActive || pQuestData->bActive == 1) && (nAct == 0xFF || nAct == pQuestData->nActNo))
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pCallback[pArgs->nEvent]), 550);
            pQuestData->pCallback[pArgs->nEvent](pQuestData, pArgs);
        }
        pQuestData = pQuestData->pPrev;
    }
}

// 0x005439A0
static void __stdcall QUESTS_StatusCycler(bool bForceActive, D2QuestArgStrc* pArgs)
{
    for (D2QuestChainStrc* i = pArgs->pTarget->pQuestEventList; i; i = i->pNext)
    {
        if (i->pQuestData->pCallback[pArgs->nEvent] && (i->pQuestData->bActive == 1 || bForceActive))
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)i->pQuestData->pCallback[pArgs->nEvent]), 0x23E);
            i->pQuestData->pCallback[pArgs->nEvent](i->pQuestData, pArgs);
        }
    }
}

// 0x00543A30
void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    if (!pDefender->pQuestEventList)
    {
        return;
    }
    if (pGame->nGameType == 3 && !pAttacker)
    {
        D2ClientStrc* pClient = sub_00539070_GetClientList(pGame);
        if (pClient)
        {
            pAttacker = CLIENTS_GetPlayerFromClient(pClient, 0);
        }
    }
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 8;
    pArgs.pTarget = pDefender;
    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER)
    {
        pArgs.pPlayer = pAttacker;
    }
    else
    {
        pArgs.pPlayer = 0;
        if (pAttacker && pAttacker->dwUnitType == UNIT_MONSTER)
        {
            int nOwnerType;
            int nOwnerId;
            AIGENERAL_GetOwnerData(pAttacker, &nOwnerId, &nOwnerType);
            if (nOwnerType == 0)
            {
                pArgs.pPlayer = SUNIT_GetServerUnit(pGame, 0, nOwnerId);
            }
        }
    }
    bool bForceActive = 0;
    if (MONSTERUNIQUE_CheckMonTypeFlag(pDefender, 2))
    {
        const int nSuperUniqueId = MONSTERUNIQUE_GetBossHcIdx(pDefender);
        switch (DATATBLS_GetSuperUniqueHcIdx_Inline(nSuperUniqueId))
        {
        case 26:
        case 27:
        case 29:
        case 36:
        case 37:
        case 38:
        case 39:
        case 42:
        case 43:
        case 44:
        case 45:
        case 60:
            bForceActive = 1;
            break;
        }
    }
    switch ((unsigned int)pDefender->dwClassId)
    {
    case 0xF2:
    case 0xF3:
    case 0x187:
    case 0x220:
        bForceActive = 1;
        break;
    }
    QUESTS_StatusCycler(bForceActive, &pArgs);
}

// 0x00543B90
void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nOldLevelId, int nTargetLevelId, D2UnitStrc* pUnit)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = pGame;
    tArgs.nEvent = QUESTEVENT_CHANGEDLEVEL;
    tArgs.nOldLevel = nOldLevelId;
    tArgs.nNewLevel = nTargetLevelId;
    tArgs.pPlayer = pUnit;
    QUESTS_EventCallback(true, false, &tArgs);
}

// 0x00543BD0
void __fastcall QUESTS_PlayerDroppedWithQuestItem(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2QuestArgStrc tArgs;
    tArgs.pPlayer = pPlayer;
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    tArgs.pGame = pGame;
    tArgs.nEvent = QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM;
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pUnit = INVENTORY_UnitIsItem(pItem);
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(QUESTS_GetClassIdInline(pUnit));
        if (pItemsTxtRecord && pItemsTxtRecord->nQuest)
        {
            D2QuestDataStrc* pQuestInfo = QUESTS_GetQuestDataInline(pGame, pItemsTxtRecord->nQuest - 1);
            tArgs.pTarget = pUnit;
            if (pQuestInfo && pQuestInfo->pCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM])
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestInfo->pCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM]), 734);
                pQuestInfo->pCallback[QUESTEVENT_PLAYERDROPPEDWITHQUESTITEM](pQuestInfo, &tArgs);
            }
        }
    }
    tArgs.nEvent = QUESTEVENT_PLAYERLEAVESGAME;
    QUESTS_EventCallback(true, false, &tArgs);
}

// 0x00543CE0
void __fastcall QUESTS_StatusCycleNpcActivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 0;
    pArgs.pTarget = pTarget;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

// 0x00543D10
void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = CLIENTS_GetGame(pClient);
    tArgs.nEvent = QUESTEVENT_NPCACTIVATE;
    tArgs.pTarget = pTarget;
    tArgs.pPlayer = pPlayer;
    tArgs.pTextControl = pTextControl;
    QUESTS_EventCallback(true, true, &tArgs);
}

// 0x00543D50
void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = pGame;
    tArgs.pTarget = pNPC;
    tArgs.pPlayer = pPlayer;
    tArgs.nEvent = QUESTEVENT_NPCDEACTIVATE;
    QUESTS_EventCallback(true, true, &tArgs);
}

// 0x00543D80
void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 4;
    pArgs.pTarget = pItem;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

static D2QuestDataStrc* QUESTS_GetQuestData_Inlined(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(nId >= 0, 119);

    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

inline D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static int QUESTS_QuickCheckPlayerGUID_Inlined(D2QuestGUIDStrc* pGUIDs, int dwGUID)
{
    for (int i = 0; i < pGUIDs->nPlayerCount; ++i)
    {
        if (pGUIDs->nPlayerGUIDs[i] == dwGUID)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00543DB0
void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 5;
    pArgs.pTarget = pItem;
    pArgs.pPlayer = pPlayer;
    QUESTS_StatusCycler(0, &pArgs);
}

static inline D2QuestDataStrc* QUESTS_GetQuestData_Inl(D2GameStrc* pGame, int nId)
{
    D2_ASSERT(nId >= 0, 119);
    if (!pGame->pQuestControl)
        return 0;
    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
            return pQuestData;
    }
    return 0;
}

// 0x00543DE0
void __fastcall QUESTS_StatusCycleObjectReset(D2GameStrc* pGame, D2UnitStrc* pTarget)
{
    D2QuestArgStrc pArgs;
    pArgs.pGame = pGame;
    pArgs.nEvent = 6;
    pArgs.pTarget = pTarget;
    pArgs.pPlayer = 0;
    QUESTS_StatusCycler(0, &pArgs);
}

// 0x00543E10
void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;
    ++pQuestControl->dwTick;
    if (pQuestControl->dwTick == -1)
    {
        for (D2QuestTimerStrc* i = pQuestControl->pTimer; i; i = i->pNext)
            i->dwTicks = -1 - i->dwTicks;
    }
    pQuestControl->bExecuting = 1;
    D2QuestTimerStrc* pTimer = pQuestControl->pTimer;
    D2QuestTimerStrc* pPrev = 0;
    while (pTimer)
    {
        D2QuestTimerStrc* pNext = pTimer->pNext;
        if (pTimer->dwTicks < pQuestControl->dwTick)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)pTimer->pfUpdate), 0x3F0);
            if (pTimer->pfUpdate(pGame, pTimer->pQuest) == 1)
            {
                if (!pPrev)
                {
                    pQuestControl->pTimer = pTimer->pNext;
                    FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x3F7, 0);
                    pTimer = 0;
                }
                else
                {
                    pPrev->pNext = pTimer->pNext;
                    FOG_FreeServerMemory(pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 0x3FE, 0);
                    pTimer = pPrev;
                }
            }
            else
            {
                pTimer->dwTicks = pQuestControl->dwTick + pTimer->dwTimeout;
            }
        }
        pPrev = pTimer;
        pTimer = pNext;
    }
    pQuestControl->bExecuting = 0;
}

// 0x00543F10
void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks)
{
    D2QuestInfoStrc* pQuestControl = pQuest->pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }

    D2_ASSERT(!pQuestControl->bExecuting, 1047);

    D2QuestTimerStrc* pPrevious = pQuestControl->pTimer;
    D2QuestTimerStrc* pQuestTimer = (D2QuestTimerStrc*)sub_0040B430(pQuest->pGame->pMemoryPool, sizeof(D2QuestTimerStrc), gszQuestsSourceFile, 1050, 0);
    pQuestTimer->pNext = pPrevious;
    pQuestTimer->pfUpdate = pfnCallback;
    pQuestTimer->pQuest = pQuest;
    pQuestTimer->dwTicks = nTicks + pQuestControl->dwTick;
    pQuestTimer->dwTimeout = nTicks;
    pQuestControl->pTimer = pQuestTimer;
}

// 0x00543F90
void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pStatus, D2BitBufferStrc* pFlags)
{
    const int bCompletedBefore = QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, 14);
    if (pQuest->fState >= (unsigned char)pQuest->nInitNo)
    {
        if (QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, 13) == 1)
        {
            if (pQuest->eFilter >= 41)
            {
                FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1109);
                exit(-1);
            }
            *pStatus = pQuest->fLastState;
            return;
        }
        if (pQuest->nQuestNo == 4 && bCompletedBefore)
        {
            if (pQuest->fState == 6)
            {
                *pStatus = 12;
                return;
            }
            *pStatus = pQuest->fLastState;
            return;
        }
        if (pQuest->nQuestNo == 10)
        {
            *pStatus = pQuest->fLastState == 4 ? 4 : 12;
            return;
        }
        goto status12;
    }
    if (bCompletedBefore)
        goto status12;
    if (pQuest->nQuestNo == 4 && pQuest->fLastState == 6 && !QUESTRECORD_GetQuestState(pFlags, pQuest->eFilter, 13))
        goto status12;
    *pStatus = pQuest->fLastState;
    return;
status12:
    *pStatus = 12;
}

static inline D2QuestDataStrc* GetQuest(D2GameStrc* game,int id) {
 D2QuestInfoStrc* control=game->pQuestControl;
 D2_ASSERT(id>=0,119);
 if(!control) return 0;
 for(D2QuestDataStrc* quest=control->pLastQuest;quest;quest=quest->pPrev)
  if(quest->nQuestNo==id) return quest;
 return 0;
}

// 0x00544190
void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id)
{
 D2QuestDataStrc* pQuestInfo=GetQuest(game,id);
 if(!pQuestInfo) return;
 D2ClientStrc* client=UnitGetClient(player,gszQuestsSourceFile,1406);
 D2ActiveRoomStrc* room=UNITS_GetRoom(player);
 if(!room) return;
 int level=DUNGEON_GetLevelIdFromRoom(room);
 if(level && pQuestInfo->nActNo==DRLG_GetActNoFromLevelId(level)) {
  D2GSPacketSrv5D packet;
  memset(&packet,0,sizeof(packet));
  packet.nHeader=0x5D;packet.nFlags=(unsigned char)pQuestInfo->dwFlags;packet.nQuestId=id;packet.nState=0;
  D2BitBufferStrc* flags=UNITS_GetPlayerData(player)->pQuestData[game->nDifficulty];
  if(!pQuestInfo->pfStatusFilter) QUESTS_RefreshStatus(pQuestInfo,&packet.nState,flags);
  else {
   unsigned char state=0;
   D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestInfo->pfStatusFilter),1429);
   if(pQuestInfo->pfStatusFilter(pQuestInfo,player,game->pQuestControl->pQuestFlags,flags,&state)==1)
    packet.nState=state;
  }
  if(pQuestInfo->eFilter==1) packet.field_4=ACT1Q1_GetMonstersToBeKilled(pQuestInfo);
  else if(pQuestInfo->eFilter==36) packet.field_4=ACT5Q2_GetBarbsToBeRescued(pQuestInfo);
  SCMD_SendPacket0x5D(client,&packet);
 }
}

// 0x00544300
void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, int(__fastcall* pfIterate)(D2GameStrc*, D2UnitStrc*, void*), bool bIterate)
{
    pQuest->fLastState = nIterateState;
    if (bIterate == 1)
    {
        if (pfIterate)
        {
            SUNIT_IterateUnitsOfType(pQuest->pGame, UNIT_PLAYER, pUnit, pfIterate);
            return;
        }

        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1464);
        exit(-1);
    }
}

// 0x00544350
void __fastcall QUESTS_StateDebug(D2QuestDataStrc* pQuestData, int nState, const char* szFile, int nLine)
{
    char szMsg[128];
    pQuestData->fState = nState;
    wsprintfA(szMsg, "changing state to %d\n", nState);
    if (dword_6FD4DC34)
    {
        PLRMSG_BroadcastChatMessage(pQuestData->pGame, szMsg, STRCOLOR_DARK_GOLD);
    }
}

// 0x005443B0
void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage)
{
    D2QuestArgStrc tArgs;
    tArgs.pGame = pGame;
    tArgs.nEvent = QUESTEVENT_SCROLLMESSAGE;
    tArgs.pPlayer = pPlayer;
    tArgs.nOldLevel = 0;
    if (dwNPCGUID == -1)
    {
        tArgs.pTarget = 0;
    }
    else
    {
        tArgs.pTarget = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, dwNPCGUID);
        if (tArgs.pTarget)
        {
            tArgs.nOldLevel = tArgs.pTarget->dwClassId;
        }
    }
    tArgs.nNewLevel = nMessage;
    QUESTS_EventCallback(true, true, &tArgs);
}

// 0x00544410
static void QUESTS_ClearQuestIntroState(D2GameStrc* pGame, int nChainNo)
{
    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, nChainNo);
    D2_ASSERT(pQuest, 0x5F3);
    pQuest->bNotIntro = 0;
    pQuest->bActive = 0;
    pQuest->fLastState = 0;
}

// 0x00544470
int __stdcall QUESTS_CheckFirstPickedSet(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 1971);

    if (!pGame->pQuestControl)
    {
        return 0;
    }

    return pGame->pQuestControl->bPickedSet;
}

// 0x005444B0
int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* ptGame, int nQuestId)
{
    D2_ASSERT(ptGame, 1987);
    D2_ASSERT(ptGame->pQuestControl->bPickedSet, 1989);

    for (D2QuestDataStrc* pQuestData = ptGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nQuestId)
        {
            return pQuestData->bNotIntro == 1;
        }
    }

    return 1;
}

// 0x00544520
__declspec(noinline) void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2QuestInfoStrc* pQuestHead = pGame->pQuestControl;
    D2_ASSERT(pQuestHead->bPickedSet, 2013);

    D2GSPacketSrv29 packet29;
    packet29.nHeader = 0x29;
    QUESTRECORD_CopyRecordToBuffer(pQuestHead->pQuestFlags, packet29.pData, sizeof(packet29.pData), 0);
    D2GAME_PACKETS_SendPacket0x29_6FC3F370(pClient, &packet29);
}

static inline int sub_00544590_CheckMonStatsFlag(int nMonsterId, int nFlag)
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

// 0x00544590
int __fastcall QUESTS_ActiveCycler(D2GameStrc* pGame, D2UnitStrc* hPlayer, D2UnitStrc* pNPC)
{
    const bool bIsPlayer = hPlayer && hPlayer->dwUnitType == UNIT_PLAYER;
    D2_ASSERT(bIsPlayer, 2028);

    const int nNPCType = pNPC ? pNPC->dwUnitType : UNIT_INVALID;
    D2_ASSERT(nNPCType == 1, 2029);

    const int nNpcId = pNPC->dwClassId;
    if (!sub_00544590_CheckMonStatsFlag(nNpcId, 9))
    {
        return 0;
    }

    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    D2_ASSERT(pQuestControl->bPickedSet, 2036);

    const unsigned char nAct = CLIENTS_GetActNo(UnitGetClient(hPlayer, gszQuestsSourceFile, 2038));

    for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (nAct == pQuestData->nActNo)
        {
            if (pQuestData->pfActiveFilter)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pfActiveFilter), 2050);
                D2_ASSERT(UNITS_GetPlayerData(hPlayer), 2051);
                D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(hPlayer)->pQuestData[pGame->nDifficulty];
                D2_ASSERT(pQuestFlags, 2053);

                if (pQuestData->pfActiveFilter(pQuestData, nNpcId, hPlayer, pQuestFlags, pNPC))
                {
                    D2GSPacketSrv8A tPacket8A;
                    tPacket8A.nHeader = 0x8A;
                    tPacket8A.nUnitType = 1;
                    tPacket8A.dwUnitGUID = pNPC->dwUnitId;
                    D2GAME_SendPacket0x8A_6FC3FA60(UnitGetClient(hPlayer, gszQuestsSourceFile, 2061), &tPacket8A);
                    return 1;
                }
            }
            else
            {
                D2_ASSERT(false, 2067);
            }
        }
    }

    return 0;
}

// 0x00544720
void __fastcall QUESTS_SetGlobalState(D2GameStrc* pGame, int nQuestId, int nState)
{
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 2080);

    QUESTRECORD_SetQuestState(pGame->pQuestControl->pQuestFlags, nQuestId, nState);
}

// 0x00544760
int __fastcall QUESTS_GetGlobalState(D2GameStrc* pGame, int nQuestId, int nState)
{
    D2_ASSERT(pGame->pQuestControl->bPickedSet, 2092);

    return QUESTRECORD_GetQuestState(pGame->pQuestControl->pQuestFlags, nQuestId, nState);
}

// 0x005447A0
void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, D2UnitStrc* pWarriv, int nXpos, int nYpos, int nWarrivID)
{
    if (nWarrivID >= 0 && nWarrivID < sgptDataTables->nMonStatsTxtRecordCount)
    {
        switch (nWarrivID)
        {
        case MONSTER_JERHYN:
            sub_0059B6C0_JerhynSpawnHook(pGame, pWarriv, nXpos, nYpos);
            break;
        case MONSTER_ACT2GUARD2:
            sub_0059B6D0_Act2Guard2SpawnHook(pGame, pWarriv, nXpos, nYpos);
            break;
        }
    }
}

// 0x005447F0
int __fastcall QUESTS_IsAndarielKilled(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData_Inl(pGame, 6);
    D2_ASSERT(pQuestData, 0x85C);
    return ACT1Q6_IsAndarielKilled(pQuestData);
}

// 0x00544840
void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitId)
{
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nUnitId);
    if (!pItem || !ITEMS_IsInPlayersInventory(pUnit, pItem, 0))
    {
        return;
    }

    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (!pItemsTxtRecord)
    {
        return;
    }

    if (pItemsTxtRecord->dwCode == ' dkb')
    {
        ACT1Q4_SendStoneOrderToClient(pGame, pUnit);
    }
    else if (pItemsTxtRecord->dwCode == ' srt')
    {
        ACT2Q6_SendTombIdToClient(pGame, pUnit);
    }
}

// 0x005448B0
void __fastcall OBJECTS_InitFunction18_JerhynPosition(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (pQuestData)
    {
        ACT2Q4_InitializeJerhynStartObject(pQuestData, pOp);
    }
}

// 0x005448E0
void __fastcall OBJECTS_InitFunction19_JerhynPositionEx(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q4_HORAZONTOME);
    if (pQuestData)
    {
        ACT2Q4_InitializeJerhynPalaceObject(pQuestData, pOp);
    }
}

// 0x00544910
void __fastcall OBJECTS_InitFunction20_TaintedAltar(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pOp->pGame, QUEST_A2Q3_TAINTEDSUN);
    if (pQuestData)
    {
        ACT2Q3_InitAltarObject(pQuestData, pOp);
        return;
    }

    int nAnimMode = 0;
    if (pOp->pObject)
    {
        nAnimMode = pOp->pObject->dwAnimMode;
    }

    if (nAnimMode != OBJMODE_OPENED)
    {
        UNITS_ChangeAnimMode(pOp->pObject, OBJMODE_OPENED);
    }
}

static inline D2QuestDataStrc* QUESTS_FindQuestData(D2GameStrc* pGame, int nId)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (pQuestControl)
    {
        for (D2QuestDataStrc* pQuestData = pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
        {
            if (pQuestData->nQuestNo == nId)
            {
                return pQuestData;
            }
        }
    }

    return 0;
}

// 0x00544950
void __fastcall OBJECTS_InitFunction15_MalusStand(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_FindQuestData(pOp->pGame, 3);
    if (pQuestData)
    {
        ACT1Q3_ACT1Q3_InitMalusObject(pQuestData, pOp);
        return;
    }

    if (!pOp->pObject || pOp->pObject->dwAnimMode != OBJMODE_OPENED)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x00544990
void __fastcall OBJECTS_InitFunction07_CainGibbet(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestData = QUESTS_FindQuestData(pOp->pGame, 4);
    if (pQuestData)
    {
        ACT1Q4_InitCainGibbet(pQuestData, pOp);
        return;
    }

    if (!pOp->pObject || pOp->pObject->dwAnimMode != OBJMODE_OPENED)
    {
        UNITS_ChangeAnimMode(pOp->pObject, 2);
    }
}

// 0x005449D0
void __cdecl QUESTS_DisableSequences()
{
// build: symbol ?gbQuestStateInitializationEnabled@* 0x0073150C
    gbQuestStateInitializationEnabled = 0;
}

struct D2GameStrc;

struct D2UnitStrc;

// 0x005449E0
void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);

    switch (nClassId)
    {
    case 131:
    {
        if (pRoom)
        {
            if (pUnit && pUnit->dwAnimMode == 1)
            {
                UNITS_ChangeAnimMode(pUnit, 2);
            }

            switch (DUNGEON_GetLevelIdFromRoom(pRoom))
            {
            case LEVEL_CHAOSSANCTUM:
                ACT4Q2_SpawnSealBoss(pGame, pUnit);
                break;

            case LEVEL_SPIDERFOREST:
                MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, MONSTER_VILECHILD1, 1, -1, 0);
                break;
            }
        }
        break;
    }
    case 122:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 11);
        if (pQuestData)
        {
            ACT2Q4_InitializeHaremBlockerObject(pQuestData, pUnit);
        }
        break;
    }
    case 26:
    {
        ACT1Q4_SpawnCainInTristram(pGame, pUnit);
        break;
    }
    case 189:
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (!DRLG_GetActNoFromLevelId(nLevelId))
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
            if (pQuestData)
            {
                ACT1Q4_UpdatePortalInTown(pQuestData, pUnit);
            }
        }
        else if (nLevelId != LEVEL_HARROGATH && nLevelId < 113)
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 32);
            if (pQuestData)
            {
                ACT5Q2_UpdatePortalMode(pQuestData, pUnit);
            }
        }
        else
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 33);
            if (pQuestData)
            {
                ACT5Q3_UpdateDrehyaPortalMode(pQuestData, pUnit);
            }
        }
        break;
    }
    case 341:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 20);
        if (pQuestData)
        {
            ACT3Q6_UpdateHellGatePortal(pQuestData, pUnit);
        }
        break;
    }
    case 268:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 4);
        if (pQuestData)
        {
            ACT1Q4_DropWirtsBodyGold(pQuestData, pUnit);
        }
        break;
    }
    case 367:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 16);
        if (pQuestData)
        {
            ACT3Q2_OpenSewerStairs(pQuestData, pUnit);
        }
        break;
    }
    case 376:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 24);
        if (pQuestData)
        {
            ACT4Q3_CreateReward(pQuestData, pUnit);
        }
        break;
    }
    case 474:
    case 475:
    case 476:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 35);
        if (pQuestData)
        {
            ACT5Q5_SpawnAncientMonsters(pQuestData, pUnit);
        }
        break;
    }
    case 461:
    {
        ACT5Q3_RemoveNihlathakFromTown(pGame, pUnit);
        break;
    }
    case 459:
    {
        ACT5Q4_RetryDrehyaPortal(pGame, pUnit);
        break;
    }
    case 460:
    {
        ACT5Q3_SpawnFrozenDrehya(pGame, pUnit);
        break;
    }
    case 371:
    {
        D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 5);
        if (pQuestData)
        {
            ACT1Q5_SpawnChestMissilesAndEvent(pQuestData, pUnit);
        }
        break;
    }
    }
}

// 0x00544E30
void __fastcall OBJECTS_InitFunction23_LamEsenTomeStand(D2ObjInitFnStrc* pOp)
{
    D2QuestDataStrc* pQuestInfo = QUESTS_GetQuestData(pOp->pGame, QUEST_A3Q1_LAMESENTOME);
    D2_ASSERT(pQuestInfo, 2435);

    ACT3Q1_InitTomeObject(pQuestInfo, pOp);
}

// 0x00544E80
void __fastcall QUESTS_SetJadeFigurineBoss(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_III)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData_Inlined(pGame, QUEST_A3Q4_GOLDENBIRD);

    if (!pUnit)
    {
        return;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (pMonStatsTxtRecord && pQuestData && pQuestData->bNotIntro == 1 && pUnit->dwClassId != MONSTER_FETISH11
        && !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_FLYING >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_FLYING & 7]))
    {
        ACT3Q4_UnitIterate_SetGoldenBirdBoss(pQuestData, pUnit);
    }
}

// 0x00544F20
void __fastcall QUESTS_SetGoldenBirdSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2QuestChainStrc* pQuestChain = pUnit->pQuestEventList;
    if (!pQuestChain)
    {
        return;
    }

    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) != ACT_III)
    {
        return;
    }

    D2QuestDataStrc* pQuestData = pQuestChain->pQuestData;
    if (pQuestData->eFilter != 20 || pQuestData->bActive != 1)
    {
        return;
    }

    ACT3Q4_CheckGoldenBirdBoss(pQuestData, pUnit);
}

// 0x00544F60
static void __stdcall QUESTS_SetIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, const int* pNPCs, int nNPCs)
{
    D2PlrIntroStrc* pPlayerIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
    for (int i = 0; i < nNPCs; ++i)
    {
        PLRINTRO_SetNpcIntroFlag(pPlayerIntro, pNPCs[i]);
    }
}

void __fastcall sub_K10_EmitSetIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    static const int aNpcs[2] = { 1, 2 };
    QUESTS_SetIntroFlags(pGame, pPlayer, aNpcs, 2);
}

// 0x00544FA0
static void QUESTS_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    switch (nAct)
    {
    case 0:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 6; ++i)
// build: symbol ?gnAct1NpcIds@* 0x007318B0
            PLRINTRO_SetNpcIntroFlag(pIntro, gnAct1NpcIds[i]);
        break;
    }
    case 1:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 11; ++i)
// build: symbol ?gnAct2NpcIds@* 0x007318C8
            PLRINTRO_SetNpcIntroFlag(pIntro, gnAct2NpcIds[i]);
        break;
    }
    case 2:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
// build: symbol ?gnAct3NpcIds@* 0x007318F4
            PLRINTRO_SetNpcIntroFlag(pIntro, gnAct3NpcIds[i]);
        break;
    }
    case 4:
    {
        D2PlrIntroStrc* pIntro = UNITS_GetPlayerData(pPlayer)->pPlayerIntro[pGame->nDifficulty];
        for (int i = 0; i < 7; ++i)
// build: symbol ?gnAct5NpcIds@* 0x00731910
            PLRINTRO_SetNpcIntroFlag(pIntro, gnAct5NpcIds[i]);
        break;
    }
    }
}

// 0x00545090
static int __stdcall QUESTS_FillNpcIntroFlags(D2PlrIntroStrc* pIntroFlags, const int* pNpcIds, int nCount, D2GSPacketSrv91* pPacket)
{
    int bUpdate = 0;
    memset(pPacket->pNPCFlags, -1, sizeof(pPacket->pNPCFlags));
    int nFound = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (PLRINTRO_GetNpcIntroFlag(pIntroFlags, pNpcIds[i]))
        {
            pPacket->pNPCFlags[nFound] = (unsigned short)pNpcIds[i];
            ++nFound;
            bUpdate = 1;
        }
    }
    return bUpdate;
}

// 0x00545CD0
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId)
    {
        return;
    }

    const unsigned char nQuestId = DATATBLS_GetLevelsTxtRecord(nLevelId)->nQuest;
    if (!nQuestId)
    {
        return;
    }

    if (bDebug)
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 0)
        {
            return;
        }
    }
    else
    {
        if (QUESTS_CreateChainRecord(pGame, pUnit, nQuestId) != 1)
        {
            return;
        }
    }

    if (dword_6FD4DC34)
    {
        PLRMSG_BroadcastChatMessage(pGame, "Error attaching to unit", STRCOLOR_DARK_GOLD);
    }
}

// 0x00545D40
static void __stdcall QUESTS_InitRecord(D2Unk00545D40Rec* pRec, int nSecond, int nFirst, unsigned char nKind)
{
    memset(pRec, 0, sizeof(D2Unk00545D40Rec));
    pRec->nFirst = nFirst;
    pRec->nSecond = nSecond;
    pRec->b0A = 0;
    pRec->b0B = 0;
    pRec->bActive = 1;
    pRec->nKind = nKind;
    pRec->w9C = 0;
}

// 0x00545100
void __fastcall QUESTS_UpdateNPCIntros(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    D2GSPacketSrv91 packet91;
    D2PlrIntroStrc* pIntroFlags = UNITS_GetPlayerData(pUnit)->pPlayerIntro[pGame->nDifficulty];
    int bUpdate;
    switch (nAct)
    {
    case 0:
        bUpdate = QUESTS_FillNpcIntroFlags(pIntroFlags, gnAct1NpcIds, 6, &packet91);
        break;
    case 1:
        bUpdate = QUESTS_FillNpcIntroFlags(pIntroFlags, gnAct2NpcIds, 11, &packet91);
        break;
    case 2:
        bUpdate = QUESTS_FillNpcIntroFlags(pIntroFlags, gnAct3NpcIds, 7, &packet91);
        break;
    case 4:
        bUpdate = QUESTS_FillNpcIntroFlags(pIntroFlags, gnAct5NpcIds, 7, &packet91);
        break;
    default:
        return;
    }
    if (bUpdate)
    {
        packet91.nHeader = 0x91;
        packet91.nAct = nAct;
        D2GAME_PACKETS_SendPacket0x91(UnitGetClient(pUnit, gszQuestsSourceFile, 0xAB7), &packet91);
    }
}

// 0x005451B0
int __fastcall QUESTS_HasFlaggedItem(D2UnitStrc* pUnit)
{
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        if (*(unsigned char*)&DATATBLS_GetItemsTxtRecord(!pCheckedItem ? -1 : pCheckedItem->dwClassId)->dwBitField1 & 2)
        {
            return 1;
        }
    }

    return 0;
}

// 0x00545200
void __fastcall QUESTS_AddPlayerGUID(D2QuestGUIDStrc* pQuestGUID, int dwGUID)
{
    if (pQuestGUID->nPlayerCount >= NUM_QUEST_PLAYER_GUIDS)
    {
        return;
    }

    if (QUESTS_QuickCheckPlayerGUID_Inlined(pQuestGUID, dwGUID))
    {
        return;
    }

    pQuestGUID->nPlayerGUIDs[pQuestGUID->nPlayerCount] = dwGUID;
    ++pQuestGUID->nPlayerCount;
}

// 0x00545240
int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID)
{
    for (int i = 0; i < pGUIDs->nPlayerCount; ++i)
    {
        if (pGUIDs->nPlayerGUIDs[i] == dwGUID)
        {
            if (i != pGUIDs->nPlayerCount - 1)
            {
                pGUIDs->nPlayerGUIDs[i] = pGUIDs->nPlayerGUIDs[pGUIDs->nPlayerCount - 1];
            }

            --pGUIDs->nPlayerCount;
            return 1;
        }
    }

    return 0;
}

// 0x00545290
extern "C" __declspec(dllexport) int __fastcall QUESTS_QuickCheckPlayerGUID(Obj00545290* pObj, unsigned int dwValue) {
    int nCount = pObj->wCount80;
    for (int i = 0; i < nCount; i++) {
        if (pObj->dwValues[i] == dwValue) {
            return 1;
        }
    }
    return 0;
}

// 0x005452C0
extern "C" __declspec(dllexport) int __fastcall QUESTS_CheckPlayerGUID(Obj005452C0* pObj, unsigned int dwValue) {
    int nCount = pObj->wCount9C;
    for (int i = 0; i < nCount; i++) {
        if (pObj->dwValues1C[i] == dwValue) {
            return 1;
        }
    }
    return 0;
}

// 0x005452F0
int __fastcall QUESTS_GetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs)
{
    return pGUIDs->nPlayerCount;
}

// 0x00545300
void __fastcall QUESTS_ResetPlayerGUIDCount(D2QuestGUIDStrc* pGUIDs)
{
    pGUIDs->nPlayerCount = 0;
}

// 0x00545310
void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg)
{
    if (pQuest->tPlayerGUIDs.nPlayerCount > 0)
    {
        QUESTS_FastRemovePlayerGUID(&pQuest->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
    }
}

// 0x00545340
void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius)
{
    D2CoordStrc tCenter;
    tCenter.nX = pCoord->nX - (nSize >> 1);
    tCenter.nY = pCoord->nY - (nSize >> 1);

    D2CoordStrc tPos;
    tPos.nX = tCenter.nX;

    D2DrlgCoordsStrc drlgCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &drlgCoords);

    for (int j = 1; j < nRadius; ++j)
    {
        const int i = -j;
        for (int y = j; y > i; y -= 2)
        {
            tPos.nY = y + tCenter.nY;

            D2ActiveRoomStrc* pRoom1 = pRoom;
            if (tPos.nY < drlgCoords.nSubtileY || tPos.nY >= drlgCoords.nSubtileY + drlgCoords.nSubtileHeight)
            {
                pRoom1 = sub_00463740_FindRoomAtPoint(pRoom, tPos.nX, tPos.nY);
            }

            if (pRoom1)
            {
                for (int x = i; x < j; x += 2)
                {
                    D2ActiveRoomStrc* pRoom2 = pRoom1;
                    DUNGEON_GetRoomCoordinates(pRoom2, &drlgCoords);

                    tPos.nX = x + tCenter.nX;

                    if (tPos.nX < drlgCoords.nSubtileX || tPos.nY >= drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
                    {
                        pRoom2 = sub_00463740_FindRoomAtPoint(pRoom1, tPos.nX, tPos.nY);
                    }

                    if (pRoom2 && !COLLISION_CheckMaskWithSizeXY(pRoom2, tPos.nX, tPos.nY, 2 * nSize + 1, 2 * nSize + 1, fCollision)
                        && (unsigned int)tPos.nX >= (unsigned int)drlgCoords.nSubtileX && (unsigned int)tPos.nX < (unsigned int)(drlgCoords.nSubtileX + drlgCoords.nSubtileWidth)
                        && (unsigned int)tPos.nY >= (unsigned int)drlgCoords.nSubtileY && (unsigned int)tPos.nY < (unsigned int)(drlgCoords.nSubtileY + drlgCoords.nSubtileHeight))
                    {
                        pCoord->nX = (nSize >> 1) + tPos.nX;
                        pCoord->nY = (nSize >> 1) + tPos.nY;
                        *ppRoom = sub_00463740_FindRoomAtPoint(pRoom, pCoord->nX, pCoord->nY);
                        return;
                    }
                }
            }
        }
    }

    *ppRoom = 0;
}

// 0x005454E0
void __fastcall QUESTS_RemoveItemFromRoom(D2GameStrc* pGame, D2UnitStrc* pItem)
{
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pItem), !pItem ? 6 : pItem->dwUnitType, !pItem ? -1 : pItem->dwUnitId);
    UNITS_FreeCollisionPath(pItem);
    UNITROOM_RemoveUnitFromRoom(pItem);
    if (pItem)
        pItem->dwFlags &= ~2;
    ITEMS_RemoveFromAllPlayers(pGame, pItem);
}

// 0x00545530
void __fastcall QUESTS_RemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pArgs)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pArgs->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDPENDING) == 1 && QUESTRECORD_GetQuestState(pQuestFlags, pQuest->eFilter, QFLAG_REWARDGRANTED)
        && pQuest->tPlayerGUIDs.nPlayerCount > 0)
    {
        QUESTS_FastRemovePlayerGUID(&pQuest->tPlayerGUIDs, !pArgs->pPlayer ? -1 : pArgs->pPlayer->dwUnitId);
    }
}

// 0x005455B0
void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2GAME_SendPacket0x28_6FC3F2F0(UnitGetClient(pUnit, gszQuestsSourceFile, 3239), QUEST_FLAGS_PACKET, QUEST_FLAGS_KIND, 0, pQuestFlags, 0);
}

// 0x005455F0
void __fastcall QUESTS_GUIDUpdate(D2GameStrc* pGame, D2QuestGUIDStrc* pQuestGUID, int nQuest, int nSoundCMD)
{
    for (int i = 0; i < pQuestGUID->nPlayerCount; ++i)
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pQuestGUID->nPlayerGUIDs[i]);
        if (pUnit)
        {
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
            if (QUESTRECORD_GetQuestState(pQuestFlags, nQuest, QFLAG_REWARDGRANTED) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, nQuest, QFLAG_REWARDPENDING) != 1)
            {
                QUESTRECORD_SetQuestState(pQuestFlags, nQuest, QFLAG_PRIMARYGOALDONE);
                QUESTRECORD_SetQuestState(pQuestFlags, nQuest, QFLAG_REWARDPENDING);

                if (nSoundCMD)
                {
                    SUNIT_AttachSound(pUnit, nSoundCMD, pUnit);
                }
            }
        }
    }
}

// 0x005456A0
void __fastcall QUESTS_SendScrollMessage(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, unsigned short nMessage)
{
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 3274);

    D2GSPacketSrv27 packet27;
    packet27.nHeader = 0x27;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    memcpy(&packet27.dwUnitGUID, &nUnitGUID, sizeof(nUnitGUID));
    packet27.nUnitType = UNIT_OBJECT;
    packet27.tMessageList.pMessages[0].nMenu = 0;
    packet27.tMessageList.pMessages[0].nStringId = nMessage;
    packet27.tMessageList.bCount = 1;
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &packet27);
}

static inline int QUESTS_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }

    return pUnit->dwUnitId;
}

static inline int QUESTS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return UNIT_INVALID;
    }

    return pUnit->dwUnitType;
}

// 0x00545760
void __fastcall QUESTS_TriggerFX(D2GameStrc* pGame, unsigned char a2)
{
    pGame->pQuestControl->unk0x20 = a2;
    SUNIT_IterateUnitsOfType(pGame, 0, 0, QUESTS_FXIterate);
}

// 0x005456F0
int __fastcall QUESTS_FXIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg)
{
    D2GSPacketSrv89 packet89;
    packet89.nHeader = 0x89;
    packet89.nEvent = pGame->pQuestControl->unk0x20;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    D2GAME_SendPacket0x28_6FC3F2F0(UnitGetClient(pUnit, gszQuestsSourceFile, 3239), QUEST_FLAGS_PACKET, QUEST_FLAGS_KIND, 0, pQuestFlags, 0);
    D2GAME_PACKETS_SendPacket0x89(UnitGetClient(pUnit, gszQuestsSourceFile, 3342), &packet89);
    return 0;
}

// 0x00545780
void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget)
{
    D2TextHeaderStrc* pTextHeader = TEXT_AllocTextHeader(pGame->pMemoryPool);
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 3362);

    D2QuestArgStrc tArgs;
    tArgs.pGame = CLIENTS_GetGame(pClient);
    tArgs.nEvent = QUESTEVENT_NPCACTIVATE;
    tArgs.pTarget = pTarget;
    tArgs.pPlayer = pPlayer;
    tArgs.pTextControl = pTextHeader;
    QUESTS_EventCallback(true, true, &tArgs);

    D2GSPacketSrv27 tPacket27;
    tPacket27.nHeader = 0x27;
    tPacket27.dwUnitGUID = QUESTS_GetUnitGUIDInline(pTarget);
    tPacket27.nUnitType = QUESTS_GetUnitTypeInline(pTarget);
    TEXT_CreateMessageListFromTextHeader(pTextHeader, &tPacket27.tMessageList);
    D2GAME_PACKETS_SendPacket0x27_6FC3DF20(pClient, &tPacket27);
    TEXT_FreeTextHeader(pTextHeader);
    QUESTS_SendCurrentFlags(pGame, pClient);
}

// 0x00545830
int __fastcall QUESTS_PortalCheck(D2GameStrc* pGame, D2CoordStrc* pCoord, int nLevel, D2ActiveRoomStrc** ppRoom)
{
    if (nLevel == LEVEL_DURIELSLAIR)
    {
        return ACT2Q6_ActivateTomb(pGame, pCoord, ppRoom);
    }

    return 0;
}

// 0x00545850
int __fastcall QUESTS_SetObjectSelection(D2ObjOperateFnStrc* pOp)
{
    int bCanOperate = 1;
    if (pOp->hObject && pOp->hObject->dwAnimMode != OBJMODE_NEUTRAL)
    {
        bCanOperate = 0;
    }

    if (bCanOperate)
    {
        D2CoordStrc tCoords;
        UNITS_GetCoords(pOp->hObject, &tCoords);

        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pOp->nObjectIdx);
        if (pObjectsTxtRecord->nMode[1])
        {
            UNITS_ChangeAnimMode(pOp->hObject, 1);
            EVENT_SetEvent(pOp->pGame, pOp->hObject, 1, (pObjectsTxtRecord->dwFrameCnt[1] >> 8) + pOp->pGame->dwGameFrame, 0, 0);
        }
        else
        {
            UNITS_ChangeAnimMode(pOp->hObject, 2);
        }

        D2UnitStrc* pObject = pOp->hObject;
        if (pObject)
        {
            pObject->dwFlags &= ~UNITFLAG_TARGETABLE;
        }
        return 1;
    }

    return 0;
}

// 0x005458E0
void __fastcall QUESTS_SendLogUpdate(D2UnitStrc* pUnit, unsigned char nQuestId)
{
    D2GSPacketSrv5D packet5D = {};

    packet5D.nHeader = QUEST_LOG_PACKET;
    packet5D.nQuestId = nQuestId;
    packet5D.nFlags = QUEST_LOG_FLAGS;

    D2ClientStrc* pClient = UnitGetClient(pUnit, gszQuestsSourceFile, 3433);
    SCMD_SendPacket0x5D(pClient, &packet5D);
}

// 0x00545920
void __fastcall QUESTS_SendLogUpdateEx(D2UnitStrc* pPlayer, int nQuestId, unsigned char nAct)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nLevelId == 0 || DRLG_GetActNoFromLevelId(nLevelId) < nAct)
        {
            return;
        }
    }

    D2GSPacketSrv5D packet5D = {};
    packet5D.nHeader = 0x5D;
    packet5D.nFlags = 0;
    packet5D.nQuestId = nQuestId;
    packet5D.nState = 12;
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 3458);
    SCMD_SendPacket0x5D(pClient, &packet5D);
}

// 0x00545990
void __stdcall D2Game_10034_Return(int nUnused)
{
}

// 0x005459A0
D2UnitStrc* __fastcall QUESTS_SpawnCriticalMonster(D2GameStrc* pGame, int nX, int nY, D2ActiveRoomStrc* pRoom, int bQuestFlags, int nMonsterId)
{
    D2ActiveRoomStrc* pFreeRoom = pRoom;
    D2DrlgCoordsStrc tRoomCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tRoomCoords);

    D2CoordStrc tCoord;
    tCoord.nX = nX;
    tCoord.nY = nY;
    int nCounter = 0;
    while (tCoord.nX < tRoomCoords.nSubtileX || tCoord.nY < tRoomCoords.nSubtileY || tCoord.nX >= tRoomCoords.nSubtileX + tRoomCoords.nSubtileWidth - 1 || tCoord.nY >= tRoomCoords.nSubtileY + tRoomCoords.nSubtileHeight - 1)
    {
        ++nCounter;
        ++tCoord.nX;
        ++tCoord.nY;
        if (nCounter > 20)
        {
            tCoord.nX = nY;
            break;
        }
    }

    QUESTS_GetFreePosition(pRoom, &tCoord, 2, 0x100u, &pFreeRoom, 6, 100);

    D2ActiveRoomStrc* pSpawnRoom = pFreeRoom;
    int nSpawnX;
    int nSpawnY;
    if (!pFreeRoom)
    {
        pSpawnRoom = pRoom;
        nSpawnX = nX;
        nSpawnY = nY;
    }
    else
    {
        nSpawnY = tCoord.nY;
        nSpawnX = tCoord.nX;
    }

    D2UnitStrc* pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nSpawnX, nSpawnY, nMonsterId, 1, -1, 0);
    if (!pMonster)
    {
        pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nSpawnX, nSpawnY, nMonsterId, 1, 5, 0);
    }

    if (!pMonster)
    {
        int nTries = 0;
        int nTryX = nSpawnX;
        int nTryY = nSpawnY;
        do
        {
            ++nTryX;
            ++nTryY;
            tCoord.nX = nTryX;
            tCoord.nY = nTryY;
            pFreeRoom = sub_00463740_FindRoomAtPoint(pSpawnRoom, nTryX, nTryY);
            if (!pFreeRoom)
            {
                pFreeRoom = pRoom;
                tCoord.nX = nX;
                tCoord.nY = nY;
            }

            QUESTS_GetFreePosition(pFreeRoom, &tCoord, 2, 0x100u, &pFreeRoom, 7, 100);
            pSpawnRoom = pFreeRoom;
            if (!pFreeRoom)
            {
                pSpawnRoom = pRoom;
                nTryX = nX;
                nTryY = nY;
            }
            else
            {
                nTryY = tCoord.nY;
                nTryX = tCoord.nX;
            }

            ++nTries;
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pSpawnRoom, nTryX, nTryY, nMonsterId, 1, 10, 0);
        }
        while (!pMonster && nTries < 20);

        if (!pMonster)
        {
            pMonster = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, 1, 15, 0);
        }
    }

    if (pMonster && bQuestFlags)
    {
        pMonster->dwFlags |= 0x3000000;
    }

    return pMonster;
}

// 0x00545B50
void __fastcall QUESTS_MonsterSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)) < LEVEL_FIRST_COUNCIL_LIMIT)
    {
        ACT3Q5_SpawnCouncil(pGame, pUnit);
    }
    else
    {
        sub_0058CFD0(pGame, pUnit);
    }
}

// 0x00545B80
int __fastcall QUESTS_LevelWarpCheck(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSourceLevel, int nTargetLevel)
{
    switch (nTargetLevel)
    {
    case LEVEL_DURIELSLAIR:
        return ACT2Q6_IsDurielsLairClosed(pGame, pPlayer);

    case LEVEL_DURANCEOFHATELEV1:
        return ACT3Q5_IsDuranceOfHateClosed(pGame, pPlayer);

    case LEVEL_GLACIALCAVESLEV1:
    case LEVEL_THEWORLDSTONEKEEPLEV1:
        if (nSourceLevel != LEVEL_ROCKYSUMMIT)
        {
            return 0;
        }
        return ACT5Q5_IsArreatSummitClosed(pGame, pPlayer, nTargetLevel);

    case LEVEL_THEWORLDSTONECHAMBER:
        return ACT5Q6_IsWorldStoneChamberClosed(pGame, pPlayer);

    default:
        return 0;
    }
}

// 0x00545C30
D2UnitStrc* __fastcall QUESTS_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2CoordStrc* pPosition, int nType, int nIndex)
{
    int nClassId = DATATBLS_MapSuperUniqueId(nType, nIndex);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), pPosition->nX, pPosition->nY);
    if (pRoom)
    {
        return D2GAME_SpawnPresetMonster_6FC66560(pGame, pRoom, nClassId, pPosition->nX, pPosition->nY, 1);
    }

    return 0;
}

// 0x00545C90
void __fastcall QUESTS_MapPresetSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != UNIT_OBJECT)
    {
        return;
    }

    switch (pUnit->dwClassId)
    {
    case OBJECT_DREHYA_START_IN_TOWN:
        ACT5Q3_ChangeDrehyaMapAI(pGame, pUnit, pMapAI);
        break;

    case OBJECT_NIHLATHAK_START_IN_TOWN:
        ACT5Q3_ChangeNihlathakMapAI(pGame, pUnit, pMapAI);
        break;

    case OBJECT_LARZUK_STANDARD:
        ACT5Q1_ChangeLarzukMapAI(pGame, pUnit, pMapAI);
        break;

    default:
        break;
    }
}

void __fastcall sub_K10_EmitInitRecord(D2Unk00545D40Rec* pRec, int n)
{
    QUESTS_InitRecord(pRec, n, n + 1, 2);
}

#pragma function(memset)

static inline void QUESTS_InitQuestData(D2QuestDataStrc* pQuestData, D2GameStrc* pGame, int nChainNo, unsigned char nAct)
{
    memset(pQuestData, 0, sizeof(D2QuestDataStrc));
    pQuestData->nQuestNo = nChainNo;
    pQuestData->pGame = pGame;
    pQuestData->bActive = 0;
    pQuestData->fLastState = 0;
    pQuestData->bNotIntro = 1;
    pQuestData->nActNo = nAct;
    pQuestData->tPlayerGUIDs.nPlayerCount = 0;
}

// 0x00545D80
void __fastcall QUESTS_QuestInit(D2GameStrc* pGame)
{
    D2QuestDataStrc* pPrev = 0;
    D2QuestDataStrc* pCurrent = 0;
    int i;

    for (i = 0; i < gnQuestInitTableCount; ++i)
    {
        pCurrent = (D2QuestDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2QuestDataStrc), gszQuestsSourceFile, 0x195, 0);
        QUESTS_InitQuestData(pCurrent, pGame, sgQuestInit[i].nChainNo, sgQuestInit[i].bAct);
        pCurrent->pPrev = pPrev;
        pPrev = pCurrent;

        if (sgQuestInit[i].pfInit)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)sgQuestInit[i].pfInit), 0x19B);
            ((QUESTINIT)sgQuestInit[i].pfInit)(pCurrent);
        }
    }

    for (i = 0; i < gnQuestIntroTableCount; ++i)
    {
        pCurrent = (D2QuestDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2QuestDataStrc), gszQuestsSourceFile, 0x1A1, 0);
        memset(pCurrent, 0, sizeof(D2QuestDataStrc));

        pCurrent->nQuestNo = i + 37;
        pCurrent->pGame = pGame;
        pCurrent->bActive = 1;
        pCurrent->fLastState = 0;
        pCurrent->bNotIntro = 0;
        pCurrent->nActNo = sgQuestIntro[i].nAct;
        pCurrent->pPrev = pPrev;
        pPrev = pCurrent;

        if (sgQuestIntro[i].pfInit)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)sgQuestIntro[i].pfInit), 0x1AD);
            sgQuestIntro[i].pfInit(pCurrent);
        }
    }

    D2QuestInfoStrc* pQuestInfo = (D2QuestInfoStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2QuestInfoStrc), gszQuestsSourceFile, 0x1B2, 0);
    pQuestInfo->bPickedSet = 0;
    pQuestInfo->pLastQuest = pCurrent;
    pQuestInfo->pTimer = 0;
    pQuestInfo->dwTick = 0;

    SEED_InitSeed(&pQuestInfo->pSeed);
    unsigned int nLow;
    QUESTS_SEED_STEP_HIGH_FIRST(&pGame->pGameSeed, nLow);
    SEED_InitLowSeed(&pQuestInfo->pSeed, nLow);
    pQuestInfo->bExecuting = 0;

    pQuestInfo->pQuestFlags = QUESTRECORD_AllocRecord(pGame->pMemoryPool);

    pGame->pQuestControl = pQuestInfo;
}

#pragma intrinsic(memset)

// 0x00545FA0
void __fastcall QUESTS_RemoveTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfUpdate)
{
    D2GameStrc* pGame = pQuest->pGame;
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
        return;

    D2_ASSERT(!pQuestControl->bExecuting, 1068);

    D2QuestTimerStrc* pPrev = 0;
    for (D2QuestTimerStrc* pTimer = pQuestControl->pTimer; pTimer; pTimer = pTimer->pNext)
    {
        if (pTimer->pfUpdate == pfUpdate && pTimer->pQuest == pQuest)
        {
            if (!pPrev)
                pQuestControl->pTimer = pTimer->pNext;
            else
                pPrev->pNext = pTimer->pNext;
            FOG_FreeServerMemory(pQuest->pGame->pMemoryPool, pTimer, gszQuestsSourceFile, 1086, 0);
            return;
        }
        pPrev = pTimer;
    }

    if (dword_6FD4DC34)
        PLRMSG_BroadcastChatMessage(pGame, "Error in timer usage", 4);
}

// 0x00546040
void __fastcall QUESTS_StatusCallback(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    QUESTS_UpdatePlayerFlags(pGame, pUnit);

    D2ClientStrc* pClient = UnitGetClient(pUnit, gszQuestsSourceFile, LINE_STATUS_CLIENT);
    D2GSPacketSrv52 packet52 = { PACKET_QUESTSTATUS };

    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl)
    {
        return;
    }

    D2QuestDataStrc* pQuest = pQuestControl->pLastQuest;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    for (; pQuest; pQuest = pQuest->pPrev)
    {
        D2_ASSERT(pQuest->nQuestNo < MAX_QUEST_STATUS, LINE_STATUS_QUESTNO);

        if (pQuest->fLastState)
        {
            if (!pQuest->pfStatusFilter)
            {
                QUESTS_RefreshStatus(pQuest, &packet52.pQuestList[pQuest->eFilter], pQuestFlags);
            }
            else
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfStatusFilter), LINE_STATUS_FILTER);

                unsigned char nStatus;
                if (pQuest->pfStatusFilter(pQuest, pUnit, pQuestControl->pQuestFlags, pQuestFlags, &nStatus) == 1)
                {
                    packet52.pQuestList[pQuest->eFilter] = nStatus;
                }
            }
        }
    }

    bool bSendPacket0x50 = false;
    D2GSPacketSrv50 packet50 = {};
    if (packet52.pQuestList[QUESTSTATEFLAG_A1Q1] && pGame->pQuestControl)
    {
        D2QuestDataStrc* pQuestData1 = pGame->pQuestControl->pLastQuest;
        while (pQuestData1 && pQuestData1->nQuestNo != QUEST_A1Q1_DENOFEVIL)
        {
            pQuestData1 = pQuestData1->pPrev;
        }

        if (pQuestData1)
        {
            bSendPacket0x50 = true;
            packet50.nParams[0] = ACT1Q1_GetMonstersToBeKilled(pQuestData1);
        }
    }

    if (packet52.pQuestList[QUESTSTATEFLAG_A5Q2] && pGame->pQuestControl)
    {
        D2QuestDataStrc* pQuestData32 = pGame->pQuestControl->pLastQuest;
        while (pQuestData32 && pQuestData32->nQuestNo != QUEST_A5Q2_RESCUESOLDIERS)
        {
            pQuestData32 = pQuestData32->pPrev;
        }

        if (pQuestData32)
        {
            bSendPacket0x50 = true;
            packet50.nParams[2] = ACT5Q2_GetBarbsToBeRescued(pQuestData32);
        }
    }

    if ((QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_REWARDGRANTED) || QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A2Q4, QFLAG_PRIMARYGOALDONE)) && pGame->pAct[ACT_II])
    {
        bSendPacket0x50 = true;
        packet50.nParams[1] = DUNGEON_GetHoradricStaffTombLevelId(pGame->pAct[ACT_II]) - LEVEL_TALRASHASTOMB1;
    }

    if (bSendPacket0x50)
    {
        packet50.nHeader = PACKET_QUESTPROGRESS;
        packet50.nQuestId = QUEST_A1Q1_DENOFEVIL;
        D2GAME_SendPacket0x50_6FC3F440(pClient, &packet50);
    }

    D2GAME_SendPacket0x52(pClient, &packet52);
}

// 0x00546270
void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int bGameEnter)
{
    D2QuestInfoStrc* pQuestControl = pGame->pQuestControl;
    if (!pQuestControl->bPickedSet)
    {
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
        int anActQuests[5];
        memset(anActQuests, 0, sizeof(anActQuests));
        pQuestControl->bPickedSet = 1;
        if (!bGameEnter)
        {
            if (gbQuestStateInitializationEnabled)
            {
                for (int i = 0; i < gnQuestInitTableCount; ++i)
                {
                    D2QuestInitTableStrc* pQuestInit = &sgQuestInit[i];
                    D2_ASSERT(pQuestInit->bAct < 5, 0x637);
                    if (!pQuestInit->bNoSetState
                        && (QUESTRECORD_GetQuestState(pQuestFlags, pQuestInit->nQuestNo, 0)
                            || QUESTRECORD_GetQuestState(pQuestFlags, pQuestInit->nQuestNo, 15)))
                    {
                        QUESTS_ClearQuestIntroState(pGame, pQuestInit->nChainNo);
                        ++anActQuests[pQuestInit->bAct];
                        QUESTRECORD_SetQuestState(pQuestControl->pQuestFlags, sgQuestInit[i].nQuestNo, 15);
                    }
                }
            }
            for (D2QuestDataStrc* pQuest = pQuestControl->pLastQuest; pQuest; pQuest = pQuest->pPrev)
            {
                if (pQuest->pCallback[13])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pCallback[13]), 0x640);
                    D2QuestArgStrc pArgs;
                    pArgs.pGame = pGame;
                    pArgs.pPlayer = pPlayer;
                    pArgs.nEvent = 13;
                    pQuest->pCallback[13](pQuest, &pArgs);
                }
            }
        }
        D2QuestDataStrc* pQuestSeq0 = QUESTS_GetQuestData(pGame, 1);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq0->pfSeqFilter), 0x64D);
        pQuestSeq0->pfSeqFilter(pQuestSeq0);
        D2QuestDataStrc* pQuestSeq1 = QUESTS_GetQuestData(pGame, 8);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq1->pfSeqFilter), 0x650);
        pQuestSeq1->pfSeqFilter(pQuestSeq1);
        D2QuestDataStrc* pQuestSeq2 = QUESTS_GetQuestData(pGame, 18);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq2->pfSeqFilter), 0x653);
        pQuestSeq2->pfSeqFilter(pQuestSeq2);
        D2QuestDataStrc* pQuestSeq3 = QUESTS_GetQuestData(pGame, 22);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq3->pfSeqFilter), 0x656);
        pQuestSeq3->pfSeqFilter(pQuestSeq3);
        D2QuestDataStrc* pQuestSeq4 = QUESTS_GetQuestData(pGame, 31);
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestSeq4->pfSeqFilter), 0x65A);
        pQuestSeq4->pfSeqFilter(pQuestSeq4);
    }
    else
    {
        for (D2QuestDataStrc* pQuest = pQuestControl->pLastQuest; pQuest; pQuest = pQuest->pPrev)
        {
            if (pQuest->pCallback[14])
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pCallback[14]), 0x666);
                D2QuestArgStrc pArgs;
                pArgs.pGame = pGame;
                pArgs.nEvent = 14;
                pArgs.pPlayer = pPlayer;
                pQuest->pCallback[14](pQuest, &pArgs);
            }
        }
    }

    D2GSPacketSrv5E packet5E;
    packet5E.nHeader = 0x5E;
    for (int i = 0; i < gnQuestInitTableCount; ++i)
    {
        D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pGame, sgQuestInit[i].nChainNo);
        D2_ASSERT(pQuest, 0x67C);
        packet5E.nQuestIntroFlags[i] = pQuest->bNotIntro;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 0x681);
    D2GAME_PACKETS_SendPacket0x5E(pClient, &packet5E);
    QUESTS_UpdatePlayerFlags(pGame, pPlayer);
    QUESTS_SendCurrentFlags(pGame, pClient);

    D2QuestDataStrc* pQuestData1 = QUESTS_GetQuestData(pGame, 1);
    if (pQuestData1 && ACT1Q1_CanClientFXBeTriggered(pQuestData1))
    {
        D2GSPacketSrv89 packet89;
        packet89.nHeader = 0x89;
        packet89.nEvent = 0;
        D2GAME_PACKETS_SendPacket0x89(pClient, &packet89);
    }
}

// 0x005466B0
D2UnitStrc* __fastcall QUESTS_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned int dwCode, int nLevel, int nQuality, int bDroppable)
{
    int nItemId;
    if (DATATBLS_GetItemRecordFromItemCode(dwCode, &nItemId))
    {
        int nItemLevel = ITEMS_GetItemLevelForNewItem(pPlayer, 0);
        if (nLevel)
            nItemLevel = nLevel;

        D2UnitStrc* pItem = D2GAME_CreateItemUnit_6FC501A0(pPlayer, nItemId, pGame, 4, nQuality, 0, 1, nItemLevel, 0, 0, 0);
        if (!pItem)
            return 0;

        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (nMaxDurability > 0)
            STATLIST_SetUnitStat(pItem, STAT_DURABILITY, nMaxDurability, 0);

        ITEMS_SetInvPage(pItem, 0);

        if (D2GAME_PlaceItem_6FC44410(".\\QUESTS\\QUESTS.CPP", 0x9CF, pGame, pPlayer, (!pItem ? -1 : pItem->dwUnitId), 0, 0, 1, 1, 0))
        {
            if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x9D2, ".\\QUESTS\\QUESTS.CPP"))
                D2GAME_ITEMS_Identify_6FC49670(pGame, pPlayer, pItem);
            return pItem;
        }

        if (bDroppable)
        {
            D2CoordStrc tCoord;
            UNITS_GetCoords(pPlayer, &tCoord);
            D2ActiveRoomStrc* pRoom;
            QUESTS_GetFreePosition(UNITS_GetRoom(pPlayer), &tCoord, 1, 0x3E01, &pRoom, 5, 100);
            D2GAME_DropItem_6FC52260(pGame, 0, pItem, pRoom, tCoord.nX, tCoord.nY);
            return pItem;
        }

        ITEMS_RemoveFromAllPlayers(pGame, pItem);
    }
    return 0;
}

static inline D2QuestDataStrc* QUESTS_GetQuestDataInl_B08(D2GameStrc* pGame, int nId)
{
    if (!pGame->pQuestControl)
    {
        return 0;
    }
    for (D2QuestDataStrc* pQuestData = pGame->pQuestControl->pLastQuest; pQuestData; pQuestData = pQuestData->pPrev)
    {
        if (pQuestData->nQuestNo == nId)
        {
            return pQuestData;
        }
    }
    return 0;
}

// 0x005467E0
void __fastcall QUESTS_ActChange_HirelingChangeAct(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pVendor, unsigned int dwDestLvl, unsigned int nUnused)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    const int nVendorType = pVendor ? pVendor->dwUnitType : UNIT_INVALID;
    if (nVendorType != 1)
    {
        return;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    switch (pVendor->dwClassId)
    {
    case 0x9B:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 7, 0))
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 7, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 7, 13);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = UnitGetClient(pUnit, gszQuestsSourceFile, 0xAD3);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                D2GAME_PACKETS_SendPacket0x61(pClient, 2);
            }
            QUESTS_SetActNpcIntroFlags(pGame, pUnit, 0);
        }

        if (QUESTRECORD_GetQuestState(pQuestFlags, 6, 13) == 1 && QUESTRECORD_GetQuestState(pQuestFlags, 6, 0) == 1)
        {
            D2QuestDataStrc* pQuestData = QUESTS_GetQuestDataInl_B08(pGame, 6);
            if (pQuestData && pQuestData->bNotIntro)
            {
                D2QuestArgStrc tArgs;
                tArgs.pGame = pGame;
                tArgs.nEvent = 3;
                tArgs.nOldLevel = 1;
                tArgs.nNewLevel = 40;
                tArgs.pPlayer = pUnit;
                if (pQuestData->pCallback[3])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)pQuestData->pCallback[3]), 0xAEE);
                    pQuestData->pCallback[3](pQuestData, &tArgs);
                }
            }
        }

        ACT1Q4_UpdateQuestStateOnActChange(pGame, pUnit);
        break;

    case 0xD2:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 15, 0))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 10, 0))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 10, 0);
                QUESTRECORD_SetQuestState(pQuestFlags, 10, 13);
                QUESTS_DeleteItem(pGame, pUnit, ' fsm');
                QUESTS_DeleteItem(pGame, pUnit, ' piv');
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 15, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 15, 13);
            QUESTS_SetActNpcIntroFlags(pGame, pUnit, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = UnitGetClient(pUnit, gszQuestsSourceFile, 0xB0F);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                D2GAME_PACKETS_SendPacket0x61(pClient, 3);
            }
        }
        break;

    case 0x16F:
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 28, 0) && pGame->bExpansion)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 28, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 28, 13);
            QUESTS_SetActNpcIntroFlags(pGame, pUnit, 1);
            QUESTS_UpdatePlayerFlags(pGame, pUnit);
            D2ClientStrc* pClient = UnitGetClient(pUnit, gszQuestsSourceFile, 0xB1F);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                D2GSPacketSrv5D packet5D = {};
                packet5D.nHeader = 0x5D;
                packet5D.nQuestId = 23;
                packet5D.nFlags = 2;
                SCMD_SendPacket0x5D(pClient, &packet5D);
                D2GAME_PACKETS_SendPacket0x61(pClient, 5);
            }
        }
        break;
    }
}

// 0x00546AC0
void __fastcall QUESTS_HellPortalActChange(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nLevel, D2UnitStrc* pObject)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (nLevel == 0x66)
    {
        if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x17, 0))
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 0x12, 0))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 0x12, 0);
                QUESTRECORD_SetQuestState(pQuestFlags, 0x12, 13);

                D2UnitStrc* pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' yeq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' rhq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' rbq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' 1fq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }

                pItem = ITEMS_FindQuestItem(pGame, pPlayer, ' 2fq');
                if (pItem)
                {
                    QUESTS_DeleteItemEx(pPlayer->pInventory, pGame, pPlayer, pItem);
                }
            }

            QUESTRECORD_SetQuestState(pQuestFlags, 0x17, 0);
            QUESTRECORD_SetQuestState(pQuestFlags, 0x17, 13);
            QUESTS_SetActNpcIntroFlags(pGame, pPlayer, 2);
            D2BitBufferStrc* pPlayerFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
            D2GAME_SendPacket0x28_6FC3F2F0(UnitGetClient(pPlayer, gszQuestsSourceFile, 0xCA7), 0x28, 6, 0, pPlayerFlags, 0);
            D2ClientStrc* pClient = UnitGetClient(pPlayer, gszQuestsSourceFile, 0xB56);
            if (pPlayerData->bBusy != 1)
            {
                pPlayerData->bBusy = 1;
                D2GAME_PACKETS_SendPacket0x61(pClient, 4);
            }
        }
    }
    else
    {
        ACT3Q6_SetObjectModes(pGame, pObject);
    }
}

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

static inline D2MonsterRegionStrc* MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId)
{
    return ppMonsterRegion[nLevelId];
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

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

#include "gen/data/Source/D2Game/Quests/QUESTS.inc"
