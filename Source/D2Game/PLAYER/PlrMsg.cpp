#include "D2GameEvents.h"
#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2GameStrc.h"
#include "D2PlayerModes.h"
#include "D2ItemModes.h"
#include "D2Packets.h"
#include "D2GameServer.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"

struct D2PoolSystemStrc;
struct D2ClientStrc;

struct D2InventoryStrc;

#define UNIT_OBJECT 2

#define UNIT_MISSILE 3

#define UNIT_TILE 5

#define UNIT_TYPES_COUNT 6

#define UNIT_ITEM 4

#define MAX_QUEST_STATUS 42

#define QFLAG_UPDATEQUESTLOG 12

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define UNIT_PLAYER 0

#define UNITFLAGEX_TELEPORTED 0x10000

struct D2SkillsTxt;


struct D2GSPacketClt15;

struct D2PlayerDataStrc;

struct D2StaticPathStrc;

struct D2UnkPlrMsgStrc;

struct D2CharStatsTxt;

struct D2ClientPlayerDataStrc;

struct D2MonsterDataStrc;

struct D2MonStatsTxt;


struct D2GSPacketSrv26Args;

struct D2AiCmdStrc;

struct D2DynamicPathStrc;

struct D2CoordStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

// Item-location checks of the game object (defined with the quest code); called with the game in ECX.
struct D2GameItemChecks
{
    int PLRMSG_CheckCursorItem(D2UnitStrc* pUnit, int nItemGUID); // 0x005490E0
    int PLRMSG_CheckStoredItem(D2UnitStrc* pUnit, int nItemGUID); // 0x00549150
    int PLRMSG_CheckStoredOrEquippedItem(D2UnitStrc* pUnit, int nItemGUID); // 0x005491B0
    int PLRMSG_CheckBeltItem(D2UnitStrc* pUnit, int nItemGUID); // 0x005492F0
};


extern D2UnkPlrMsgStrc gaUnitModeMessages[20]; // 0x007319E8

#include "D2GameFuncs.h"
#include "D2CommonApi3.h"
#include "D2ClientApi.h"
#include "D2GSPacketsClt.h"


int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20


void __fastcall SCMD_SendSkillUseOnUnit(D2ClientStrc* pClient, unsigned char nSourceUnitType, int nSourceUnitGUID, int nUnitType, int nUnitGUID, unsigned short nSkillId, unsigned short nSkillParam, unsigned char nSkillLevel, int bQueued); // 0x0053D530


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540


int __fastcall PLAYER_CanModifyInventory(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00535610

void __fastcall PLRMSG_SendCantDoThat(D2UnitStrc* pUnit); // 0x00549A60

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID); // 0x00552F60


int __fastcall ITEMMODE_ReplaceOppositeHandItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pItemStatus); // 0x00563D20

void __fastcall D2GAME_NPC_IdentifyBoughtItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00578640


unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250


struct D2ClientPlayerDataStrc
{
    int dwInactivityTime;
    unsigned short nHitPoints;
    unsigned short nManaPoints;
    unsigned short nStaminaPoints;
    unsigned char nPotionLifePercent;
    unsigned char nPotionManaPercent;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned short nTargetOffsetX;
    unsigned short nTargetOffsetY;
    int dwBeltGold;
    int dwExperience;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60


int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090


void* __fastcall CLIENTS_GetClientPlayerData(D2ClientStrc* pClient); // 0x00539330

void __fastcall SCMD_SendVitalsAndPotionPrediction(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned char nPotionLifePercent, unsigned char nPotionManaPercent, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C230

void __fastcall SCMD_SendVitals(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C320

void __fastcall D2GAME_PACKETS_SendPacket0x96_WalkVerify(D2ClientStrc* pClient, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY); // 0x0053C3F0

void __fastcall D2GAME_PACKETS_SendPacket0x19(D2ClientStrc* pClient, int nValue, int nPreviousGold); // 0x0053E9B0

void __fastcall D2GAME_PACKETS_SendPacket0x1A_B_C(D2ClientStrc* pClient, int nExperience, int nPreviousExperience); // 0x0053BDD0

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char gszPlrMsgSourceFile[]; // 0x006E1050

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit); // 0x00535E80


void __fastcall QUESTS_UseClueItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID); // 0x00544840


void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190


unsigned int __fastcall PLAYERLIST_GetHostileDelay(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B6C0


int __fastcall sub_0055E9A0_Return0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055E9A0


int __fastcall ITEMMODE_UseItemOnItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetGUID, int nUseItemGUID, int* pItemStatus); // 0x00561ED0


int __fastcall ITEMMODE_PlaceItemInCube(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int nCubeGUID, int* pItemStatus); // 0x005628C0


void __fastcall PLRTRADE_TryToTrade(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x00566E60


void __fastcall MONSTERAI_ActivateNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572E60

void __fastcall MONSTERAI_EndNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc, D2MonsterInteractStrc* pMonInteract); // 0x00572F20

void __fastcall MONSTERAI_StartNpcInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2MonsterInteractStrc* pMonInteract, char nQuestFlags); // 0x00573020

int __fastcall NPC_HandleDialogMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nType, int nNpcGUID, int nItemGUID); // 0x00579D60

void __fastcall PLRMODE_RecoverCorpse(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pDeadBody); // 0x0057FB70


int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectType, int nObjectGUID);

void __fastcall OBJMODE_UpdateDoorModeFromCollision(D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID); // 0x005845D0


int __fastcall OBJMODE_MainObeliskHandler(D2GameStrc* pGame, int nPlayerGUID, int nObjectGUID, int nItemGUID, short nState); // 0x005852E0


D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0


int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400



void __fastcall UNITS_SetInteractData(D2UnitStrc* pUnit, int nMode, int nArg1, int nArg2); // 0x00641F20


D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140


void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620


int __stdcall SKILLS_GetUseState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00647960

void __stdcall D2Common_10153(D2DynamicPathStrc* pDynamicPath); // 0x00648730


int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180


int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320


int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210

int __stdcall INVENTORY_PlaceItemInBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nSlot); // 0x0063C4F0

int __stdcall INVENTORY_GetFreeBeltSlot(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int* pFreeSlotId); // 0x0063C600


void __stdcall CHAT_SetLangIdInHoverMsg(D2HoverTextStrc* pHoverMsg, unsigned char nLangId); // 0x00661230

int __fastcall D2GAME_CheckSkillIfUnitsClassSkill(D2UnitStrc* pUnit, int nSkillId); // 0x0056C700

int __stdcall SKILLS_CheckRequiredSkills(D2UnitStrc* pUnit, int nSkillId); // 0x006447D0

int __stdcall SKILLS_CheckRequiredAttributes(D2UnitStrc* pUnit, int nSkillId); // 0x00644920


void __fastcall sub_0055F4F0_Nop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused); // 0x0055F4F0

struct D2GSPacketSrv26Args
{
    D2GSPacketSrv26* pPacket26;
    D2GSPacketClt15* pPacket15;
    int nUnitId;
};


int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pInteractUnitType, int* pInteractUnitGUID); // 0x00554100


typedef void (__fastcall *ClientCallback)(D2ClientStrc*, void*);

extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);

void __fastcall GAME_ForEachIngameClient(D2GameStrc*, ClientCallback, void*); // 0x0052DED0

void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage(D2ClientStrc*, void*); // 0x0054A5C0


typedef char H15_CheckInventoryOffset[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

typedef char H15_CheckGameFrameOffset[(int)&((D2GameStrc*)0)->dwGameFrame == 0xA8 ? 1 : -1];


int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0


D2InventoryStrc* __stdcall INVENTORY_AllocInventory(D2PoolSystemStrc* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0


void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

void __fastcall D2GAME_ITEMS_UpdateTransferredProperties(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730




static int __stdcall PLRMSG_CheckSameAct(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00548A80

static int __stdcall PLRMSG_CheckDistanceToPoint(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance); // 0x00548EF0

static int __stdcall PLRMSG_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID);

static inline int PLRMSG_CheckSkillLevel(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID);


void __stdcall sub_0063BE30_Return(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30


static int __stdcall PLRMSG_TakeMercItemToCursor(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc);

struct D2BuyItemPacketStrc;

int __stdcall STATLIST_GetListExpireFrame(D2StatListStrc* pStatList); // 0x00626090

static unsigned char PLRMSG_GetPotionLifePercent(D2UnitStrc* pUnit);

int __fastcall sub_0055E9A0_Return0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x0055E9A0

int __fastcall OBJMODE_OperateObjectInRange(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned short nObjectType, int nObjectGUID); // 0x00584540

void __fastcall OBJMODE_TravelViaWaypoint(D2GameStrc* pGame, D2UnitStrc* pUnit, int nWaypointGUID, int nLevelId); // 0x00584F60


static void __stdcall PLRMSG_RunToUnitAndInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID);

void __fastcall j_D2GAME_SendPacket0x5A(D2ClientStrc*, void*); // 0x0054AA30

int __fastcall ITEMMODE_ReplaceHandItemsWithCursorItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int* pFailure); // 0x00561220

#pragma pack(push, 1)

struct D2BuyItemPacketStrc
{
    unsigned char nHeader;
    int nNpcUnitId;
    int nItemId;
    unsigned int nTransactionType;
    int nCost;
};

#pragma pack(pop)

int __fastcall D2GAME_NPC_BuyItemHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId, int nItemId, int nItemMode, int nTransactionType, int nCost, int bMultibuy); // 0x00577F30

#define PLRMODE_WALK 2

#define PLRMODE_RUN 3

#define PLRMODE_DEAD 17

#define BODYLOC_BELT 8


#define EVENTTYPE_PLAYERLEFT 3

#define CLIENTSAVEFLAG_HARDCORE 4

#define UNITFLAG_TARGETABLE 2

#define MONSTATSFLAGINDEX_NPC 8

#define MONSTATSFLAGINDEX_INTERACT 9

static int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange); // 0x00549BA0


int __fastcall PLAYER_SetSkillHotKey(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nHotkeyId, short nSkillId, int nHand, int nFlags); // 0x005356B0


int __fastcall ARENA_IsActive(D2GameStrc* pGame); // 0x0053FD10

int __fastcall ARENA_Return0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053FDF0

void __fastcall PLRMSG_SendGetHitMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode); // 0x00548350

void __fastcall D2GAME_UpdateAttribute(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

int __fastcall ITEMMODE_SwapCursorAndBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCursorItemGUID, int nBeltItemGUID, int* pItemStatus); // 0x0055EB30


int __fastcall ITEMMODE_SwapCursorAndBodyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, unsigned char nBodyLoc, int bSkipRequirementCheck, int* pFailed); // 0x00560F00

int __fastcall ITEMMODE_SwapWeaponSets(D2GameStrc* pGame, D2UnitStrc* pUnit, int* status); // 0x005616A0

int __fastcall ITEMMODE_RemoveBeltItemToCursor(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00562250


int __fastcall PLRTRADE_IsTradeInventoryEmpty(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00567840

void __fastcall SKILLS_HandleTransmogrify(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x0056C6A0


int __fastcall PLAYERSTATS_SpendStatPoint(D2UnitStrc* pUnit, int nStatId); // 0x00570D60

int __fastcall PARTYSCREEN_CommandHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCommand, int nArg, int nArg2); // 0x005A6000


int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char nAct); // 0x0061AB70

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549D00

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549D80

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549E00

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549FC0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A040

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A0C0

struct D2GSPacketClt15 { unsigned char nHeader; unsigned char nType; unsigned char nColor; char szMessage[256]; char szName[16]; };

typedef void (__fastcall* D2ClientCallback)(D2ClientStrc*, void*);

extern "C" void* __cdecl memset(void*, int, unsigned int);

extern int gbWhispReceiverNotListening; // 0x008846E0

extern int gbWhispReceiverInGame; // 0x008846E4

void __fastcall D2GAME_PACKETS_HandlePlayerMessage(D2ClientStrc*, void*); // 0x0054A470

void __fastcall D2GAME_PACKETS_HandleWhisper(D2ClientStrc*, void*); // 0x0054A510

#define EVENTTYPE_CANTDOTHAT 14

#define STRCOLOR_RED 1

union D2SeedStrc;


struct D2WarpDelayStrc;

typedef void(__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc* pClient, void* pContext);


void __fastcall QUESTS_StatusCallback(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00546040


int __fastcall D2GAME_NPC_Repair(D2GameStrc* pGame, D2UnitStrc* pUnit, int nNpcGUID, int nItemGUID, unsigned short nUnused, int nRepairFlags); // 0x00578050

int __fastcall D2GAME_STORES_SellItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID, int nItemGUID, unsigned short nItemMode, int unused); // 0x00579510

struct D2WarpDelayStrc
{
    int nChance;
    int nDelay;
};

extern const D2WarpDelayStrc gaWarpDelays[3]; // 0x006E1064

void __fastcall CLIENTS_NotifyWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00539360

int __fastcall CLIENTS_ShouldDelayWarpAttempt(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005393F0


int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int bSkipCollisionSearch, int bSyncOtherPlayersOnly); // 0x00554EA0

extern "C" void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

unsigned int __stdcall PATH_GetLastPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A40

unsigned int __stdcall PATH_GetLastPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A60

void __stdcall PATH_SetTargetPos(D2DynamicPathStrc* pDynamicPath, unsigned short nX, unsigned short nY); // 0x00648AD0

extern "C" void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

extern "C" unsigned int __stdcall PATH_GetMoveTestCollisionMask(D2DynamicPathStrc* pPath); // 0x00648CD0

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648CE0


void __fastcall sub_0054CC30_StatRemoveCallback_ToggleStateOff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2PacketTableStrc;

static int __stdcall PLRMSG_CheckWaypointObject(D2GameStrc* pGame, unsigned short nLevelId, D2UnitStrc* pUnit, int nObjectGUID);

typedef int (__fastcall* PacketCallback)(D2GameStrc*,D2UnitStrc*,unsigned char*,int);

struct D2PacketTableStrc { PacketCallback pfCallback; int nSize; };

extern D2PacketTableStrc sgcptIncomingMessageChart[]; // 0x006E0D18

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void*); // 0x006CC34C


#define D2_MAYBE_UNUSED(x) (void)(x)

int __fastcall ITEMMODE_SwapCursorAndStoredItem(D2GameStrc*, D2UnitStrc*, int, int, int, int, int*); // 0x00561B00

static int __stdcall PLRMSG_CheckOwnedItem(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pUnit);

static int __stdcall PLRMSG_CheckItemInReach(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pPlayer);

static int __stdcall PLRMSG_CheckOrificeObject(int nItemGUID, unsigned short nState, D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID);

static int __stdcall PLRMSG_ReadCoordinatePacket(D2GameStrc* pGame, int nPacketSize, unsigned short* pX, unsigned short* pY, D2UnitStrc* pUnit, void* pPacket);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x01_Walk(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x005497E0

static int __stdcall PLRMSG_ReadTargetUnitPacket(D2GameStrc* pGame, int nPacketSize, int* pUnitType, int* pUnitGUID, D2UnitStrc* pUnit, void* pPacket);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x02_WalkToEntity(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549890

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x03_Run(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x005498D0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x04_RunToEntity(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549920

static D2SkillStrc* __stdcall PLRMSG_SelectDualWieldSkill(D2SkillStrc* pSkill, D2UnitStrc* pUnit);

static int __stdcall PLRMSG_UseSkillAtPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x08_ShiftLeftSkillHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549E80

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x09_LeftSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549EE0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0A_ShiftLeftSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x00549F40

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0F_RightSkillHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A140

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x10_RightSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A1A0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x11_ShiftRightSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054A200

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054AD90

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x27_UseItemAction(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B280

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x21_StackItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B300

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x22_UnstackItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B380

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x26_UseBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B560

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x29_ScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B710

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2A_ItemToCubeIndirect(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B790

static int __stdcall PLRMSG_GetInteractNpc(int bCheckRange, D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppNpc, int nNpcGUID);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B930

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x30_TerminateEntityChat(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B9F0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x38_EntityAction(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054BCA0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3D_HighlightADoor(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054BF10

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x44_StaffInOrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054C380

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054C5D0

int gbWhispReceiverNotListening; // 0x008846E0

int gbWhispReceiverInGame; // 0x008846E4

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize); // 0x0054C5D0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x20_UseGridItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054B1E0

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3E_ActivateInifussScroll(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize); // 0x0054BF60

static int __stdcall D2GAME_MERCS_EquipItem(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2GameStrc* pGame, D2UnitStrc* pMerc);

static int __stdcall PLRMSG_TryEquipMercItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, D2UnitStrc* pItem);

int __fastcall D2GAME_PACKETCALLBACK_Rcv0x61_DropPickupMercItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize);


// 0x00547F50
D2WaypointDataStrc* __fastcall PLRMSG_GetWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pWaypointData[pGame->nDifficulty];
}

// 0x00547F70
void __fastcall PLRMSG_SendKnockbackStatus(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const char nHitType = pUnit->dwLastHitClass;
    const unsigned char nLife = UNITS_GetCurrentLifePercentage(pUnit);
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
    D2GAME_PACKETS_SendPacket0x0D(pClient, 0x0D, 0, nUnitId, 19, nX, nY, nHitType, nLife);
}

static inline int UNITS_GetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ((D2StaticPathStrc*)pUnit->pDynamicPath)->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int UNITS_GetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return ((D2StaticPathStrc*)pUnit->pDynamicPath)->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x00548010
void __fastcall PLRMSG_SendUnitPosition(D2UnitStrc* pUnit, D2ClientStrc* pClient, unsigned char bReassign)
{
    const int nY = UNITS_GetYPosition(pUnit);
    const int nX = UNITS_GetXPosition(pUnit);
    const unsigned int nUnitGUID = (pUnit ? pUnit->dwUnitId : -1);
    const int nUnitType = (pUnit ? pUnit->dwUnitType : UNIT_INVALID);
    D2GAME_PACKETS_SendPacket0x15(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, bReassign);
}

// 0x00548090
void __fastcall PLRMSG_SendSkillMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill && (SKILLS_GetFlags(pSkill) & 4 || pUnit != CLIENTS_GetPlayerFromClient(pClient, 0)))
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 207);
        const char nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);

        if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
        {
            SCMD_SendSkillUseOnUnit(pClient, 0, nUnitGUID, !pTarget ? UNIT_TYPES_COUNT : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId, nSkillId, 0, nSkillLevel, 0);
        }
        else
        {
            SCMD_SendUnitActionAtPosition(pClient, 0, nUnitGUID, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), (unsigned short)nSkillId, 0, nSkillLevel, 0);
        }
    }
}


// 0x00548180
void __fastcall PLRMSG_SendWalkMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    if (pUnit != CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
        {
            const int nTargetGUID = pTarget->dwUnitId;
            const int nTargetType = pTarget->dwUnitType;
            const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
            D2GAME_PACKETS_SendPacket0x10(pClient, 0x10, 0, nUnitGUID, (unsigned char)gaUnitModeMessages[nAnimMode].nTargetMode, nTargetType, nTargetGUID, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit));
        }
        else
        {
            D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
            int nY;
            if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
                nY = pUnit->pStaticPath->tGameCoords.nY;
            else
                nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
            int nX;
            if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
                nX = pUnit->pStaticPath->tGameCoords.nX;
            else
                nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
            const int nUnitId = pUnit->dwUnitId;
            D2GAME_PACKETS_SendPacket0x0F(pClient, 0x0F, 0, nUnitId, (unsigned char)gaUnitModeMessages[nAnimMode].nLocationMode, D2COMMON_10175_PathGetFirstPointX(pPath), D2COMMON_10176_PathGetFirstPointY(pPath), 0, nX, nY);
        }
    }
}

// calling-convention shim (not game code)
int __stdcall sub_005485B0_Shim(D2UnitStrc* pUnit)
{
	return PLRMSG_GetPotionLifePercent(pUnit);
}

// 0x005482A0
void __fastcall PLRMSG_SendKnockbackMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const char nHitClass = pUnit->dwLastHitClass;
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    const int nUnitId = pUnit->dwUnitId;
    D2GAME_PACKETS_SendPacket0x0F(pClient, 0x0F, 0, nUnitId, (unsigned char)gaUnitModeMessages[nAnimMode].nLocationMode, D2COMMON_10175_PathGetFirstPointX(pPath), D2COMMON_10176_PathGetFirstPointY(pPath), nHitClass, nX, nY);
}

// 0x00548350
void __fastcall PLRMSG_SendGetHitMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    const int nField = gaUnitModeMessages[nAnimMode].nLocationMode;
    const char nHitClass = pUnit->dwLastHitClass;
    const char nLife = UNITS_GetCurrentLifePercentage(pUnit);
    int nY;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nY = pUnit->pStaticPath->tGameCoords.nY;
    else
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    int nX;
    if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
        nX = pUnit->pStaticPath->tGameCoords.nX;
    else
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    D2GAME_PACKETS_SendPacket0x0D(pClient, 0x0D, 0, !pUnit ? -1 : pUnit->dwUnitId, nField, nX, nY, nHitClass, nLife);
}

// 0x00548400
void __fastcall PLRMSG_SendNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    if (pUnit != CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        const unsigned char nLife = UNITS_GetCurrentLifePercentage(pUnit);
        const int nHitClass = gaUnitModeMessages[nAnimMode].nLocationMode;
        int nY;
        if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
            nY = pUnit->pStaticPath->tGameCoords.nY;
        else
            nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        int nX;
        if (pUnit->dwUnitType == UNIT_OBJECT || (pUnit->dwUnitType > UNIT_MISSILE && pUnit->dwUnitType <= UNIT_TILE))
            nX = pUnit->pStaticPath->tGameCoords.nX;
        else
            nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        const int nUnitId = (pUnit ? pUnit->dwUnitId : -1);
        D2GAME_PACKETS_SendPacket0x0D(pClient, 0x0D, 0, nUnitId, nHitClass, nX, nY, 0, nLife);
    }
}

typedef int (__stdcall* FARPROC)();

// 0x005484B0
void __fastcall PLRMSG_SendUnitMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const int nAnimMode = !pUnit ? 0 : pUnit->dwAnimMode;

    PlrMsgFunc pfSendMode = gaUnitModeMessages[nAnimMode].pfSendMode;
    if (pfSendMode)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pfSendMode), 328);
        pfSendMode(pGame, pUnit, pClient, nAnimMode);
    }
}

inline int PLRMSG_IsBodyLocValid(int nBodyLoc)
{
    return nBodyLoc > 0 && nBodyLoc < 11;
}

// 0x00548520
void __fastcall D2GAME_UpdateAttribute(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer)
{
    D2ClientStrc* hClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrMsg.cpp", 339);
    D2_ASSERT(hClient, 340);

    if (pUnit == pPlayer)
    {
        D2GAME_PACKETS_SendPacket0x1D_E_F(hClient, nStat, nNewValue);
    }
    else
    {
        SCMD_SendUnitStat(hClient, 0x20, !pUnit ? -1 : pUnit->dwUnitId, nStat, nNewValue);
    }
}

static inline int PoisonStat_GetPerFrame(D2StatListStrc* pStatList)
{
	if (pStatList)
	{
		return STATLIST_GetStatValue(pStatList, STAT_HPREGEN, 0);
	}
	return 0;
}

// 0x005485B0
static unsigned char PLRMSG_GetPotionLifePercent(D2UnitStrc* pUnit)
{
	const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
	const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
	D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HEALTHPOT);
	if (!pStatList || !nMaxLife)
	{
		return 0;
	}

	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nFrames = STATLIST_GetListExpireFrame(pStatList) - pGame->dwGameFrame;
	const unsigned char nPercent = (unsigned char)((((PoisonStat_GetPerFrame(pStatList) * nFrames + nHitpoints) >> 8) * 100) / nMaxLife);
	const int nClamped = nPercent > 100 ? 100 : nPercent;
	return (unsigned char)nClamped;
}

static unsigned char sub_005485B0_GetPotionLifePercent(D2UnitStrc* pUnit)
{
    D2StatListStrc* pHealthPotStatList;
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nShiftedMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    pHealthPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_HEALTHPOT);
    if (pHealthPotStatList && nShiftedMaxHp)
    {
        D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
        const int nFrameDiff = D2COMMON_10473(pHealthPotStatList) - pGame->dwGameFrame;
        const unsigned char nPotionLifePercent = 100 * ((nHitpoints + nFrameDiff * STATLIST_GetStatValue(pHealthPotStatList, STAT_HPREGEN, 0)) >> 8) / nShiftedMaxHp;
        return nPotionLifePercent > 100 ? 100 : nPotionLifePercent;
    }

    return 0;
}

static D2CharStatsTxt* sub_00548640_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00548640
static unsigned char PLRMSG_GetPotionManaPercent(D2UnitStrc* pUnit)
{
    const int nMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    D2StatListStrc* pManaPotStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_MANAPOT);
    if (!pManaPotStatList || !nMaxMana)
    {
        return 0;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = sub_00548640_GetCharStatsTxtRecord(pUnit ? pUnit->dwClassId : -1);
    if (!pCharStatsTxtRecord)
    {
        return 0;
    }

    int nManaRegen = 25 * pCharStatsTxtRecord->nManaRegen;
    if (!nManaRegen)
    {
        nManaRegen = 7500;
    }

    const int nQuotient = nMaxMana / nManaRegen;
    const int nManaMultiplier = nQuotient < 1 ? 1 : nQuotient;
    const int nRecoveryBonus = STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERYBONUS, 0);
    const int nRecovery = STATLIST_UnitGetStatValue(pUnit, STAT_MANARECOVERY, 0);
    const int nFrameMultiplier = nManaMultiplier * (nRecoveryBonus + 100) / 100 + nRecovery;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    const unsigned char nPotionManaPercent = 100 * (nMana + nFrameMultiplier * (D2COMMON_10473(pManaPotStatList) - pGame->dwGameFrame)) / nMaxMana;
    return nPotionManaPercent > 100 ? 100 : nPotionManaPercent;
}

// 0x00548760
int __fastcall PLRMSG_SendPlayerStatUpdates(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int bSkipHpCheck)
{
    if (!pPlayer || !pUnit)
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrMsg.cpp", 0x1B0);
    if (!pClient)
    {
        return 0;
    }

    D2ClientPlayerDataStrc* pClientPlayerData = (D2ClientPlayerDataStrc*)CLIENTS_GetClientPlayerData(pClient);
    if (!pClientPlayerData)
    {
        return 0;
    }

    const int nShiftedHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >> 8;
    const int nShiftedMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    if (nShiftedMaxHp <= 0)
    {
        return 0;
    }

    int nHpDiff = (unsigned short)pClientPlayerData->nHitPoints - nShiftedHitpoints;
    if (nHpDiff < 0)
    {
        nHpDiff = -nHpDiff;
    }

    if (!bSkipHpCheck && (100 * nHpDiff / nShiftedMaxHp < 10 || !nShiftedHitpoints && pClientPlayerData->nHitPoints))
    {
        return 0;
    }

    const int nUnitX = (unsigned short)CLIENTS_GetUnitX(pUnit);
    const int nUnitY = (unsigned short)CLIENTS_GetUnitY(pUnit);
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    unsigned char nX = 0;
    unsigned char nY = 0;
    if (pPath)
    {
        nX = nUnitX - D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = nUnitY - D2COMMON_10176_PathGetFirstPointY(pPath);
    }

    const int nShiftedMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) >> 8;
    const int nStamina = STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0) >> 8;
    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    const int nExperience = STATLIST_UnitGetStatValue(pUnit, STAT_EXPERIENCE, 0);
    const unsigned char nPotionLifePercent = sub_005485B0_GetPotionLifePercent(pUnit);
    const unsigned char nPotionManaPercent = PLRMSG_GetPotionManaPercent(pUnit);

    int bSent = 1;
    if (pClientPlayerData->nPotionLifePercent == nPotionLifePercent && pClientPlayerData->nPotionManaPercent == nPotionManaPercent)
    {
        if (pClientPlayerData->nHitPoints == (unsigned short)nShiftedHitpoints && pClientPlayerData->nManaPoints == (unsigned short)nShiftedMana)
        {
            if (pClientPlayerData->nStaminaPoints == (unsigned short)nStamina)
            {
                if (pClientPlayerData->dwInactivityTime <= 3)
                {
                    bSent = 0;
                }
                else
                {
                    int nXDiff = pClientPlayerData->nPosX - (unsigned short)nUnitX;
                    if (nXDiff < 0)
                    {
                        nXDiff = -nXDiff;
                    }

                    if (nXDiff < 2)
                    {
                        int nYDiff = pClientPlayerData->nPosY - (unsigned short)nUnitY;
                        if (nYDiff < 0)
                        {
                            nYDiff = -nYDiff;
                        }

                        if (nYDiff < 2)
                        {
                            bSent = 0;
                        }
                    }
                }
            }

            if (bSent)
            {
                D2GAME_PACKETS_SendPacket0x96_WalkVerify(pClient, nStamina, nUnitX, nUnitY, nX, nY);
            }
        }
        else
        {
            SCMD_SendVitals(pClient, nShiftedHitpoints, nShiftedMana, nStamina, nUnitX, nUnitY, nX, nY);
        }
    }
    else
    {
        SCMD_SendVitalsAndPotionPrediction(pClient, nShiftedHitpoints, nShiftedMana, nStamina, nPotionLifePercent, nPotionManaPercent, nUnitX, nUnitY, nX, nY);
    }

    if (bSent)
    {
        pClientPlayerData->nPosX = nUnitX;
        pClientPlayerData->nPosY = nUnitY;
        pClientPlayerData->nTargetOffsetX = nX;
        pClientPlayerData->nTargetOffsetY = nY;
        pClientPlayerData->dwInactivityTime = 0;
    }
    else
    {
        ++pClientPlayerData->dwInactivityTime;
    }

    if (nGold != pClientPlayerData->dwBeltGold)
    {
        D2GAME_PACKETS_SendPacket0x19(pClient, nGold, pClientPlayerData->dwBeltGold);
        pClientPlayerData->dwBeltGold = nGold;
    }

    if (nExperience != pClientPlayerData->dwExperience)
    {
        D2GAME_PACKETS_SendPacket0x1A_B_C(pClient, nExperience, pClientPlayerData->dwExperience);
        pClientPlayerData->dwExperience = nExperience;
    }

    pClientPlayerData->nHitPoints = nShiftedHitpoints;
    pClientPlayerData->nStaminaPoints = nStamina;
    pClientPlayerData->nManaPoints = nShiftedMana;
    pClientPlayerData->nPotionLifePercent = nPotionLifePercent;
    pClientPlayerData->nPotionManaPercent = nPotionManaPercent;
    return 1;
}


// 0x005489F0
void __fastcall PLRMSG_SendUnitBaseStats(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer != pUnit)
    {
        for (int i = 0; gnBaseStatIdsToSend[i] != -1; ++i)
        {
            const int nStatId = gnBaseStatIdsToSend[i];
            const int nValue = STATLIST_GetUnitBaseStat(pUnit, nStatId, 0);
            D2GAME_UpdateAttribute(pUnit, nStatId, nValue, pPlayer);
        }
    }
}

// 0x00548A50
static void __stdcall PLRMSG_RunToUnitAndInteract(int nInteractSkill, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    StartModeID(pGame, pPlayer, 0, 3, nUnitType, nUnitGUID, 0);
    UNITS_SetInteractData(pPlayer, nInteractSkill, nUnitType, nUnitGUID);
}

// 0x00548A80
static int __stdcall PLRMSG_CheckSameAct(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget))))
    {
        return 0;
    }

    return 2;
}

inline int sub_00548AC0_GetActMismatchStatus(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    if (nAct == DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOther))))
    {
        return 0;
    }
    return 2;
}

// 0x00548AC0
int __fastcall PLRMSG_IsUnitInOtherAct(D2UnitStrc* pUnit, D2UnitStrc* pOther)
{
    return sub_00548AC0_GetActMismatchStatus(pUnit, pOther) != 0;
}

static inline D2MonsterInteractStrc* PLRMSG_GetMonInteract(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pMonInteract;
    }

    return 0;
}

static __forceinline int PLRMSG_GetUnitX(D2UnitStrc* pUnit)
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

static __forceinline int PLRMSG_GetUnitY(D2UnitStrc* pUnit)
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

// 0x00548B00
int __fastcall PLRMSG_InteractWithUnit(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame)
{
    switch (nUnitType)
    {
    case 2:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 2, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        D2_ASSERT(DATATBLS_GetObjectsTxtRecord(!pUnit ? -1 : pUnit->dwClassId), 703);

        if (pUnit->dwAnimMode >= 8)
        {
            return 3;
        }

        if (D2Common_10399(pPlayer, pUnit) > 50)
        {
            return 1;
        }

        if (UNITS_IsObjectInInteractRange(pPlayer, pUnit) && !UNITS_TestCollisionBetweenInteractingUnits(pPlayer, pUnit, 0x804))
        {
            D2Common_10153(pPlayer->pDynamicPath);
            if (!OBJMODE_OperateObjectInRange(pGame, pPlayer, 2, nUnitGUID))
            {
                return 3;
            }
        }
        else
        {
            PLRMSG_RunToUnitAndInteract(a4 ? -2 : -1, pGame, pPlayer, 2, nUnitGUID);
        }

        return 0;
    }
    case 5:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 5, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance > 4)
        {
            PLRMSG_RunToUnitAndInteract(a4 ? -2 : -1, pGame, pPlayer, 5, nUnitGUID);
        }
        else
        {
            SUNIT_WarpPlayer(pGame, pPlayer, pUnit);
        }

        return 0;
    }
    case 4:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 4, nUnitGUID);
        const int nAnimMode = pUnit ? pUnit->dwAnimMode : 0;
        if (!pUnit)
        {
            return 1;
        }
        if (nAnimMode != 3)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance <= 4 && !UNITS_TestCollisionBetweenInteractingUnits(pPlayer, pUnit, 0x804))
        {
            int bFailed;
            if (a4)
            {
                D2GAME_PickupItemEx(pGame, pPlayer, nUnitGUID, &bFailed);
            }
            else
            {
                D2GAME_PickupItem(pGame, pPlayer, nUnitGUID, &bFailed);
            }

            if (bFailed)
            {
                return 3;
            }
        }
        else
        {
            PLRMSG_RunToUnitAndInteract(a4 ? -2 : -1, pGame, pPlayer, 4, nUnitGUID);
        }

        return 0;
    }
    case 1:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 1, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[1] && pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
        {
            D2Common_10153(pUnit->pDynamicPath);
            AIGENERAL_SetAiControlParam(pUnit, 1, 40);
            D2GAME_EVENTS_Delete(pGame, pUnit, 2, 0);
            EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 1, 0, 0);
        }

        if (nDistance > 6)
        {
            if (nDistance >= 9)
            {
                return 0;
            }

            PLRMSG_RunToUnitAndInteract(a4 ? -2 : -1, pGame, pPlayer, 1, nUnitGUID);
            return 0;
        }
        else if (!PLAYER_IsBusy(pPlayer))
        {
            D2Common_10153(pPlayer->pDynamicPath);
            MONSTERAI_StartNpcInteraction(pGame, pPlayer, pUnit, sub_00535E80_GetMonInteract(pUnit), 0);
        }

        return 0;
    }
    case 0:
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 0, nUnitGUID);
        if (!pUnit)
        {
            return 1;
        }

        const unsigned int nDistance = D2Common_10399(pPlayer, pUnit);
        if (nDistance > 50)
        {
            return 1;
        }

        if (nDistance > 8)
        {
            PLRMSG_RunToUnitAndInteract(a4 ? -2 : -1, pGame, pPlayer, 0, nUnitGUID);
            return 0;
        }

        if (pUnit->dwAnimMode == 17 && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pPlayer, 1) && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
        {
            PLRMODE_RecoverCorpse(pGame, pPlayer, pUnit);
        }
        else
        {
            PLRTRADE_TryToTrade(pGame, pPlayer, pUnit);
        }

        return 0;
    }
    }

    return 1;
}

// 0x00548EB0
static int __stdcall PLRMSG_CheckValuesEqual(int nValue, int nExpected)
{
    return nValue == nExpected ? 0 : 3;
}

int __fastcall sub_K10_EmitCompareValues(int a, int b)
{
    return PLRMSG_CheckValuesEqual(a, b) + PLRMSG_CheckValuesEqual(b, a + 1);
}

inline int UNITS_GetUnitTypeOrInvalid(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }

    return nType;
}

// 0x00548ED0
int __stdcall PLRMSG_CheckUnitType(unsigned int nValue)
{
    return nValue < 6 ? 0 : 2;
}

// 0x00548EF0
static int __stdcall PLRMSG_CheckDistanceToPoint(unsigned short nX, unsigned short nY, D2UnitStrc* pUnit, int nMaxDistance)
{
    const int nUnitX = PLRMSG_GetUnitX(pUnit);
    const int nUnitY = PLRMSG_GetUnitY(pUnit);

    int nXDiff = nUnitX - nX;
    if (nXDiff < 0)
    {
        nXDiff = -nXDiff;
    }

    if (nXDiff <= nMaxDistance)
    {
        int nYDiff = nUnitY - nY;
        if (nYDiff < 0)
        {
            nYDiff = -nYDiff;
        }

        if (nYDiff <= nMaxDistance)
        {
            return 0;
        }
    }

    return 1;
}

// 0x00548F80
static int __stdcall PLRMSG_CheckTargetUnit(int nMaxDistance, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID)
{
    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pTarget)
    {
        return 1;
    }

    if (nUnitType == 4 && ITEMS_IsInPlayersInventory(pPlayer, pTarget, 0))
    {
        return 0;
    }

    const unsigned char nPlayerAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pPlayer)));
    if (nPlayerAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pTarget))))
    {
        return 2;
    }

    const int nX = PLRMSG_GetUnitX(pTarget);
    return PLRMSG_CheckDistanceToPoint(nX, PLRMSG_GetUnitY(pTarget), pPlayer, nMaxDistance);
}

// 0x00549080
static inline int PLRMSG_CheckLeftSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetLeftSkill(pUnit) ? 0 : 3;
}

// 0x005490A0
static inline int PLRMSG_CheckRightSkill(D2UnitStrc* pUnit)
{
    return UNITS_GetRightSkill(pUnit) ? 0 : 3;
}

// 0x005490C0
static inline int PLRMSG_CheckName(const char* szName)
{
    if (!szName[0xFF])
    {
        return SStrChr(szName, -1) ? 2 : 0;
    }
    return 2;
}

// 0x005490E0
int __fastcall PLRMSG_CheckCursorItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1123);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem && pItem->dwAnimMode == IMODE_ONCURSOR && INVENTORY_GetCursorItem(pUnit->pInventory) == pItem)
    {
        return 0;
    }

    return 1;
}

// 0x00549150
int __fastcall PLRMSG_CheckStoredItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1146);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem && pItem->dwAnimMode == IMODE_STORED && INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem))
    {
        return 0;
    }

    return 1;
}

// 0x005491B0
int __fastcall PLRMSG_CheckStoredOrEquippedItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1169);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (pItem->dwAnimMode != IMODE_STORED && pItem->dwAnimMode != IMODE_EQUIP)
    {
        return 1;
    }

    return !INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem);
}

// 0x00549220
static int __stdcall PLRMSG_CheckOwnedItem(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 1192);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem))
    {
        return 0;
    }

    return INVENTORY_GetCursorItem(pUnit->pInventory) != pItem;
}

// 0x00549290
static inline int PLRMSG_CheckValueInRange(int nValue)
{
    return (unsigned int)(nValue - 1) > 9 ? 2 : 0;
}

// 0x005492A0
static inline int PLRMSG_CheckBodyLocOccupied(D2UnitStrc* pUnit, int nBodyLoc)
{
    return INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc) ? 0 : 1;
}

int __stdcall sub_M114_Emit_00549080(D2UnitStrc* pUnit, const char* szName, int a, int b)
{
    return PLRMSG_CheckLeftSkill(pUnit) + PLRMSG_CheckRightSkill(pUnit) + PLRMSG_CheckName(szName)
        + PLRMSG_CheckValueInRange(a) + PLRMSG_CheckBodyLocOccupied(pUnit, b) + PLRMSG_CheckSkillLevel(pUnit, a, b);
}

// 0x005492C0
static int __stdcall PLRMSG_IsHandBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    if (nBodyLoc != BODYLOC_RARM && nBodyLoc != BODYLOC_LARM)
    {
        return 3;
    }
    return !INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
}

// 0x005492F0
int __fastcall PLRMSG_CheckBeltItem(D2GameStrc* pGame, int nUnused, D2UnitStrc* pUnit, int nItemGUID)
{
    D2_ASSERT(pGame, 1256);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (pItem->dwAnimMode != IMODE_INBELT)
    {
        return 1;
    }

    return !INVENTORY_CompareWithItemsParentInventory(pUnit->pInventory, pItem);
}

// 0x00549350
static int __stdcall PLRMSG_CheckItemInReach(int nItemGUID, D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2_ASSERT(pGame, 1283);

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    int nResult = 0;
    switch (pItem->dwAnimMode)
    {
    case IMODE_ONGROUND:
    {
        nResult = PLRMSG_CheckSameAct(pPlayer, pItem);
        if (nResult)
        {
            return nResult;
        }

        const int nX = CLIENTS_GetUnitX(pItem);
        nResult = PLRMSG_CheckDistanceToPoint(nX, CLIENTS_GetUnitY(pItem), pPlayer, 10);
        if (nResult)
        {
            return nResult;
        }
        break;
    }
    case IMODE_STORED:
    case IMODE_EQUIP:
    case IMODE_INBELT:
    case IMODE_ONCURSOR:
        nResult = PLRMSG_CheckOwnedItem(nItemGUID, pGame, pPlayer);
        if (nResult)
        {
            return nResult;
        }
        break;
    default:
        return 1;
    }

    return 0;
}

// 0x00549410
static int __stdcall PLRMSG_GetInteractNpc(int bCheckRange, D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc** ppNpc, int nNpcGUID)
{
    *ppNpc = SUNIT_GetServerUnit(pGame, 1, nNpcGUID);
    if (!*ppNpc)
    {
        return 1;
    }

    if (!PLRMSG_GetMonInteract(*ppNpc))
    {
        return 3;
    }

    const int nResult = PLRMSG_CheckSameAct(pUnit, *ppNpc);
    if (nResult)
    {
        return nResult;
    }

    if (bCheckRange)
    {
        const int nX = CLIENTS_GetUnitX(*ppNpc);
        const int nRange = PLRMSG_CheckDistanceToPoint(nX, CLIENTS_GetUnitY(*ppNpc), pUnit, 10);
        if (nRange)
        {
            return nRange;
        }
    }

    return 0;
}

int __fastcall sub_K10_EmitIsHandBodyLocFree(D2UnitStrc* pUnit, int nBodyLoc)
{
    return PLRMSG_IsHandBodyLocFree(pUnit, nBodyLoc);
}

// 0x00549490
static int PLRMSG_CheckSkillAllocation(D2UnitStrc* pUnit, int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 2;
    }
    if (!D2GAME_CheckSkillIfUnitsClassSkill(pUnit, nSkillId))
    {
        return 3;
    }
    if (!SKILLS_CheckRequiredSkills(pUnit, nSkillId))
    {
        return 3;
    }
    return SKILLS_CheckRequiredAttributes(pUnit, nSkillId) ? 0 : 3;
}

// 0x005494E0
static inline int PLRMSG_CheckSkillLevel(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 3;
    }
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill)
    {
        return 3;
    }
    return SKILLS_GetSkillLevel(pUnit, pSkill, 1) ? 0 : 3;
}

// 0x00549520
static int __stdcall PLRMSG_CheckOrificeObject(int nItemGUID, unsigned short nState, D2GameStrc* pGame, D2UnitStrc* pUnit, int nObjectGUID)
{
    const int nResult = PLRMSG_CheckTargetUnit(50, pGame, pUnit, 2, nObjectGUID);
    if (nResult)
    {
        return nResult;
    }

    switch (nState)
    {
    case 2:
        return 0;
    case 3:
        return ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    default:
        return 2;
    }
}

static inline int PLRMSG_J07_GetUnitX(D2UnitStrc* pUnit)
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

static inline int PLRMSG_J07_GetUnitY(D2UnitStrc* pUnit)
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

// 0x00549570
static int __stdcall PLRMSG_CheckWaypointObject(D2GameStrc* pGame, unsigned short nLevelId, D2UnitStrc* pUnit, int nObjectGUID)
{
    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
    if (!pObject)
    {
        return 1;
    }

    const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pObject))))
    {
        return 2;
    }

    struct
    {
        unsigned short nWaypointNo;
        int nX;
    } tLocal;
    switch (pObject->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        tLocal.nX = pObject->pStaticPath->nXPos;
        break;
    default:
        if (pObject->pDynamicPath)
            tLocal.nX = PATH_GetXPosition(pObject->pDynamicPath);
        else
            tLocal.nX = 0;
        break;
    }
    const int nY = PLRMSG_J07_GetUnitY(pObject);
    int nMaxDistance = 0xA;
    if (pUnit && pUnit->dwClassId == 1)
    {
        nMaxDistance = 0x16;
    }

    const int nResult = PLRMSG_CheckDistanceToPoint(tLocal.nX, nY, pUnit, nMaxDistance);
    if (nResult)
    {
        return nResult;
    }

    if (!nLevelId)
    {
        return 0;
    }

    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount)
    {
        return 3;
    }

    D2_ASSERT(UNITS_GetPlayerData(pUnit), 0x632);

    if (WAYPOINTS_GetWaypointNoFromLevelId(nLevelId, &tLocal.nWaypointNo))
    {
        return WAYPOINTS_IsActivated(PLRMSG_GetWaypointData(pGame, pUnit), tLocal.nWaypointNo) ? 0 : 2;
    }

    return 3;
}

// 0x005496F0
static int __stdcall PLRMSG_ReadCoordinatePacket(D2GameStrc* pGame, int nPacketSize, unsigned short* pX, unsigned short* pY, D2UnitStrc* pUnit, void* pPacket)
{
    const D2GSPacketClt01* pPacket01 = (const D2GSPacketClt01*)pPacket;
    *pX = 0;
    *pY = 0;

    if (nPacketSize != 5)
    {
        return 3;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    if (!pPlayerData)
    {
        return 2;
    }

    const unsigned short nX = pPacket01->nPosX;
    const unsigned short nY = pPacket01->nPosY;

    const int nResult = PLRMSG_CheckDistanceToPoint(nX, nY, pUnit, 50);
    if (nResult)
    {
        if (pGame->dwGameFrame - pPlayerData->dwGameFrame > 25)
        {
            D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1639);
            if (pClient)
            {
                D2GAME_PACKETS_SendPacket0x15(pClient, 0x15, 0, !pUnit ? -1 : pUnit->dwUnitId, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1);
            }
        }

        return nResult;
    }

    pPlayerData->dwGameFrame = pGame->dwGameFrame;
    *pX = nX;
    *pY = nY;
    return 0;
}

// 0x005497E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x01_Walk(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = PLRMSG_ReadCoordinatePacket(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, 2, nX, nY, 0);
    return 0;
}

// 0x00549830
static int __stdcall PLRMSG_ReadTargetUnitPacket(D2GameStrc* pGame, int nPacketSize, int* pUnitType, int* pUnitGUID, D2UnitStrc* pUnit, void* pPacket)
{
    const D2GSPacketClt06* pPacket06 = (const D2GSPacketClt06*)pPacket;
    *pUnitType = 0;
    *pUnitGUID = 0;

    if (nPacketSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = pPacket06->dwUnitType;
    const int nUnitGUID = pPacket06->dwUnitGUID;
    if (nUnitType >= 6)
    {
        return 2;
    }

    const int nResult = PLRMSG_CheckTargetUnit(50, pGame, pUnit, nUnitType, nUnitGUID);
    if (nResult)
    {
        return nResult;
    }

    *pUnitType = nUnitType;
    *pUnitGUID = nUnitGUID;
    return 0;
}

// 0x00549890
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x02_WalkToEntity(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    StartModeID(pGame, pUnit, 0, 2, nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x005498D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x03_Run(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = PLRMSG_ReadCoordinatePacket(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, 3, nX, nY, 0);
    return 0;
}

// 0x00549920
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x04_RunToEntity(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    StartModeID(pGame, pUnit, 0, 3, nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x00549960
static D2SkillStrc* __stdcall PLRMSG_SelectDualWieldSkill(D2SkillStrc* pSkill, D2UnitStrc* pUnit)
{
    D2SkillStrc* pUsedSkill = pSkill;
    if (!SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 1804))
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (pRightWeapon && (!ITEMS_CanBeEquipped(pRightWeapon) || ITEMS_GetItemType(pRightWeapon) == ITEMTYPE_MISSILE_POTION))
        {
            pRightWeapon = 0;
        }

        D2UnitStrc* pLeftWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (pLeftWeapon && (!ITEMS_CanBeEquipped(pLeftWeapon) || ITEMS_GetItemType(pLeftWeapon) == ITEMTYPE_MISSILE_POTION))
        {
            pLeftWeapon = 0;
        }

        if (pRightWeapon && pLeftWeapon && ITEMSIsA(pRightWeapon, 45) && ITEMSIsA(pLeftWeapon, 45))
        {
            if (!SKILLS_GetParam4(pSkill))
            {
                pUsedSkill = SKILLS_GetSkillById(pUnit, SKILL_LEFTHANDSWING, -1);
                D2_ASSERT(pUsedSkill, 1829);
                SKILLS_SetParam4(pSkill, 5);
            }
            else
            {
                SKILLS_SetParam4(pSkill, 0);
            }
        }
    }

    return pUsedSkill;
}

// 0x00549A60
void __fastcall PLRMSG_SendCantDoThat(D2UnitStrc* pUnit)
{
    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nColor = STRCOLOR_RED;
    *(int*)&packet5A.dwParam = 0;
    packet5A.nType = EVENTTYPE_CANTDOTHAT;
    D2GAME_PACKETS_SendPacket0x5A(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 1852), &packet5A);
}

// 0x00549AD0
static int __stdcall PLRMSG_UseSkillAtPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY)
{
    if (!pUnit || pUnit->dwAnimMode == 0 || pUnit->dwAnimMode == 17)
    {
        return 2;
    }

    D2SkillStrc* pUsedSkill = pSkill;
    if (UNITS_CanDualWield(pUnit))
    {
        pUsedSkill = PLRMSG_SelectDualWieldSkill(pSkill, pUnit);
    }

    int nSkillUseState = SKILLS_GetUseState(pUnit, pUsedSkill);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pUsedSkill);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    if (nSkillUseState > 0 && (nSkillUseState <= 2 || nSkillUseState == 4) && pSkillsTxtRecord->nFlags[3] & gdwBitMasks[4])
    {
        pUsedSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
        nSkillUseState = SKILLS_GetUseState(pUnit, pUsedSkill);
    }

    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pUnit, pUsedSkill);
    if (!nSkillMode)
    {
        return 2;
    }

    if (nSkillUseState != 0)
    {
        if (nSkillUseState == 1)
        {
            PLRMSG_SendCantDoThat(pUnit);
        }

        return 2;
    }

    PLRMODE_ChangeModeToCoords(pGame, pUnit, pUsedSkill, nSkillMode, nX, nY, 0);
    return 0;
}

// 0x00549BA0
static int __stdcall PLRMSG_UseSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nUnitType, int nUnitGUID, int bCheckRange)
{
    if (UNITS_CanDualWield(pUnit))
    {
        pSkill = PLRMSG_SelectDualWieldSkill(pSkill, pUnit);
    }

    int nUseState = SKILLS_GetUseState(pUnit, pSkill);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    if (nUseState > 0 && (nUseState <= 2 || nUseState == 4) && pSkillsTxtRecord->nFlags[3] & gdwBitMasks[4])
    {
        pSkill = SKILLS_GetSkillById(pUnit, SKILL_ATTACK, -1);
        nUseState = SKILLS_GetUseState(pUnit, pSkill);
    }

    if (nUseState)
    {
        return 2;
    }

    const int nSkillMode = SKILLS_GetSkillModeFromUnit(pUnit, pSkill);
    if (!nSkillMode)
    {
        return 2;
    }

    if (!(pSkillsTxtRecord->nFlags[3] & gdwBitMasks[3]) && (nUnitType < 0 || nUnitType > 1 && nUnitType != 3))
    {
        return 2;
    }

    D2UnitStrc* pOtherUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (pOtherUnit && STATES_CheckState(pOtherUnit, STATE_ATTACHED))
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pOtherUnit);
        if (pOwner)
        {
            nUnitType = pOwner->dwUnitType;
            pOtherUnit = pOwner;
            nUnitGUID = pOwner->dwUnitId;
        }
    }

    if (bCheckRange && pOtherUnit)
    {
        switch (D2Common_11016(pUnit, pSkill))
        {
        case 1:
            if (UNITS_IsInMeleeRange(pUnit, pOtherUnit, UNITS_IsInMovingModeEx(pOtherUnit)))
            {
                break;
            }

        case 4:
            PLRMSG_RunToUnitAndInteract(SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrMsg.cpp", 2013), pGame, pUnit, nUnitType, nUnitGUID);
            return 0;
        }
    }

    StartModeID(pGame, pUnit, pSkill, nSkillMode, nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x00549D00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = PLRMSG_ReadCoordinatePacket(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillAtPosition(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nX, nY);
    return 0;
}

// 0x00549D80
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nUnitType, nUnitGUID, 1);
    return 0;
}

// 0x00549E00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetLeftSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x00549E80
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x08_ShiftLeftSkillHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = PLRMSG_ReadCoordinatePacket(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x05_ShiftLeftClickSkill(pGame, pUnit, pPacket, nSize);
    return 0;
}

// 0x00549EE0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x09_LeftSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x06_LeftSkillOnUnit(pGame, pUnit, pPacket, nSize);
    return 0;
}

// 0x00549F40
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0A_ShiftLeftSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetLeftSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x07_ShiftLeftSkillOnUnit(pGame, pUnit, pPacket, nSize);
    return 0;
}

// 0x00549FA0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0B(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return nSize != 1 ? 3 : 0;
}

// 0x00549FC0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = PLRMSG_ReadCoordinatePacket(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillAtPosition(pGame, pUnit, UNITS_GetRightSkill(pUnit), nX, nY);
    return 0;
}

// 0x0054A040
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetRightSkill(pUnit), nUnitType, nUnitGUID, 1);
    return 0;
}

// 0x0054A0C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    PLRMSG_UseSkillOnUnit(pGame, pUnit, UNITS_GetRightSkill(pUnit), nUnitType, nUnitGUID, 0);
    return 0;
}

// 0x0054A140
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x0F_RightSkillHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    unsigned short nX;
    unsigned short nY;

    const int nResult = PLRMSG_ReadCoordinatePacket(pGame, nSize, &nX, &nY, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0C_RightSkill(pGame, pUnit, pPacket, nSize);
    return 0;
}

// 0x0054A1A0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x10_RightSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0D_RightSkillOnUnit(pGame, pUnit, pPacket, nSize);
    return 0;
}

// 0x0054A200
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x11_ShiftRightSkillOnUnitHold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    int nUnitType;
    int nUnitGUID;

    const int nResult = PLRMSG_ReadTargetUnitPacket(pGame, nSize, &nUnitType, &nUnitGUID, pUnit, pPacket);
    if (nResult)
    {
        return nResult;
    }

    if (!UNITS_GetRightSkill(pUnit))
    {
        return 3;
    }

    D2GAME_PACKETCALLBACK_Rcv0x0E_ShiftRightSkillOnUnit(pGame, pUnit, pPacket, nSize);
    return 0;
}

// 0x0054A260
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x12(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    STATES_ToggleState(pUnit, STATE_INFERNO, 0);
    return 0;
}

// 0x0054A290
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x14_HandleOverheadChat(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize < 4 || nSize > 275)
    {
        return 3;
    }

    const int nStringLength = SStrLen((char*)pPacket + 3);
    if (nStringLength <= 0)
    {
        return 0;
    }

    char szText[256];
    SStrCopy(szText, (char*)pPacket + 3, sizeof(szText));
    if (nStringLength >= 256)
    {
        return 2;
    }

    char szName[16];
    SStrCopy(szName, (char*)pPacket + nStringLength + 4, sizeof(szName));

    if (SStrChr(szText, -1))
    {
        return 0;
    }

    if (pUnit && pUnit->pHoverText)
    {
        CHAT_FreeHoverMsg(pGame->pMemoryPool, pUnit->pHoverText);
        pUnit->pHoverText = 0;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(pGame->pMemoryPool, szText, pGame->dwGameFrame);
    if (!pHoverText)
    {
        return 0;
    }

    CHAT_SetLangIdInHoverMsg(pHoverText, *((unsigned char*)pPacket + 2));

    if (pUnit)
    {
        pUnit->pHoverText = pHoverText;
    }

    UNITROOM_RefreshUnit(pUnit);

    if (pUnit)
    {
        pUnit->dwFlags |= 0x100;
    }

    EVENT_SetEvent(pGame, pUnit, 6, D2_MAX(pGame->dwGameFrame + 1, CHAT_GetTimeoutFromHoverMsg(pHoverText)), 0, 0);
    return 0;
}

// 0x0054A420
static int __stdcall PLRMSG_CheckInteractUnit(D2GameStrc* pGame, D2UnitStrc* pExpected, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID) && nUnitType == UNIT_PLAYER)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID);
        if (pInteractUnit && pInteractUnit != pExpected)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0054A470
void __fastcall D2GAME_PACKETS_HandlePlayerMessage(D2ClientStrc* pClient, void* pArgs)
{
    D2GSPacketSrv26Args* pPacket26Args = (D2GSPacketSrv26Args*)pArgs;
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2GSPacketSrv26* pPacket26 = pPacket26Args->pPacket26;

    if (pPacket26Args->nUnitId != -1)
    {
        D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, pPacket26Args->nUnitId);
        D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pOtherPlayer && pLocalPlayer && pOtherPlayer != pLocalPlayer)
        {
            if (PLAYERLIST_CheckFlag(pLocalPlayer, pOtherPlayer, 4) || PLAYERLIST_CheckFlag(pOtherPlayer, pLocalPlayer, 2)
                || PLRMSG_CheckInteractUnit(pGame, pLocalPlayer, pOtherPlayer) || PLRMSG_CheckInteractUnit(pGame, pOtherPlayer, pLocalPlayer))
            {
                return;
            }
        }
    }

    D2GAME_PACKETS_SendPacket0x26_ServerMessage(pClient, pPacket26);
}

// 0x0054A510
void __fastcall D2GAME_PACKETS_HandleWhisper(D2ClientStrc* pClient, void* pArgs)
{
    D2GSPacketSrv26Args* pPacket26Args = (D2GSPacketSrv26Args*)pArgs;
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    D2GSPacketSrv26* pPacket26 = pPacket26Args->pPacket26;
    const char* szClientName = CLIENTS_GetName(pClient);
    if (!SStrCmpI(szClientName, pPacket26Args->pPacket15->szName, 0x7FFFFFFF))
    {
        const int nUnitGUID = pPacket26Args->nUnitId;
        if (nUnitGUID != -1)
        {
            D2UnitStrc* pReceiver = SUNIT_GetServerUnit(pGame, UNIT_PLAYER, nUnitGUID);
            D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pReceiver && pLocalPlayer)
            {
                if (PLAYERLIST_CheckFlag(pLocalPlayer, pReceiver, 4))
                {
                    gbWhispReceiverNotListening = 1;
                    return;
                }

                if (PLAYERLIST_CheckFlag(pReceiver, pLocalPlayer, 2))
                {
                    gbWhispReceiverNotListening = 1;
                    return;
                }
            }
        }

        gbWhispReceiverInGame = 1;
        D2GAME_PACKETS_SendPacket0x26_ServerMessage(pClient, pPacket26);
    }
}

// 0x0054A5C0
void __fastcall j_D2GAME_PACKETS_SendPacket0x26_ServerMessage(D2ClientStrc* pClient, void* pMsg)
{
    D2GAME_PACKETS_SendPacket0x26_ServerMessage(pClient, (D2GSPacketSrv26*)pMsg);
}

// 0x0054A5D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x15_HandleChatMessage(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nSize)
{
    D2GSPacketClt15 packet15;
    memset(&packet15, 0, sizeof(packet15));
    packet15.nHeader = pBuffer[0];
    packet15.nType = pBuffer[1];
    packet15.nColor = pBuffer[2];
    const char* pText = (const char*)pBuffer + 3;
    SStrCopy(packet15.szMessage, pText, 256);
    const int nLength = SStrLen(pText);
    if (nLength >= 256 || nLength + 4 >= nSize) return 2;
    pText += nLength + 1;
    SStrCopy(packet15.szName, pText, 16);
    SStrLen(pText);
    D2GSPacketSrv26 packet26;
    const char* pName = CLIENTS_GetName(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x9E7));
    if (SStrLen(pName) > 0) SStrCopy(packet26.szName, pName, 0x7FFFFFFF);
    else packet26.szName[0] = 0;
    const int nReceiverLength = SStrLen(packet15.szName);
    const int bWhisper = nReceiverLength > 0 && nReceiverLength <= 15;
    packet26.nNameColor = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    packet15.szName[15] = 0;
    if (packet15.szMessage[255]) goto MalformedChat;
    if (SStrChr(packet15.szMessage, -1)) {
MalformedChat:
        return 0;
    }
    memcpy(packet26.szMessage, packet15.szMessage, 256);
    packet26.nLang = packet15.nColor;
    packet26.nMessageColor = 0;
    packet26.nHeader = 0x26;
    packet26.dwUnitGUID = 0;
    packet26.nUnitType = 2;
    D2ClientCallback pCallback;
    if (bWhisper) { packet26.nMessageType = 2; pCallback = D2GAME_PACKETS_HandleWhisper; }
    else { packet26.nMessageType = 1; pCallback = D2GAME_PACKETS_HandlePlayerMessage; }
    gbWhispReceiverInGame = 0;
    gbWhispReceiverNotListening = 0;
    D2GSPacketSrv26Args args;
    args.pPacket26 = &packet26;
    args.pPacket15 = &packet15;
    args.nUnitId = pUnit && pUnit->dwUnitType == UNIT_PLAYER ? pUnit->dwUnitId : -1;
    GAME_ForEachIngameClient(pGame, pCallback, &args);
    if (packet26.nMessageType == 2)
    {
        if (gbWhispReceiverNotListening)
        {
            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nColor = 0;
            packet5A.dwParam = 0;
            SStrCopy(packet5A.szText, packet15.szName, 0x7FFFFFFF);
            packet5A.nType = 13;
            packet5A.szText[15] = 0;
            D2GAME_PACKETS_SendPacket0x5A(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0xA2C), &packet5A);
        }
        else if (!gbWhispReceiverInGame)
        {
            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nColor = 0;
            packet5A.dwParam = 0;
            SStrCopy(packet5A.szText, packet15.szName, 0x7FFFFFFF);
            packet5A.nType = 4;
            packet5A.szText[15] = 0;
            D2GAME_PACKETS_SendPacket0x5A(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0xA38), &packet5A);
        }
        else
        {
        D2GSPacketSrv26 reply;
        reply.nHeader = 0x26;
        reply.nMessageType = 6;
        reply.dwUnitGUID = 0;
        reply.nUnitType = 2;
        reply.nMessageColor = 0;
        SStrCopy(reply.szName, packet15.szName, 0x7FFFFFFF);
        reply.szName[15] = 0;
        reply.nLang = 0;
        memcpy(reply.szMessage, packet15.szMessage, 256);
        D2GAME_PACKETS_SendPacket0x26_ServerMessage(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0xA46), &reply);
        }
    }
    return 0;
}

// 0x0054A930
void __fastcall PLRMSG_BroadcastChatMessage(D2GameStrc* game, const char* message, unsigned char color)
{
    D2GSPacketSrv26 packet;
    packet.nHeader = 0x26;
    packet.nMessageType = 1;
    packet.nUnitType = 2;
    packet.dwUnitGUID = 0;
    packet.nMessageColor = color;
    packet.szName[0] = 0;
    packet.nLang = 0;
    memcpy(packet.szMessage, message, sizeof(packet.szMessage));
    GAME_ForEachIngameClient(game, j_D2GAME_PACKETS_SendPacket0x26_ServerMessage, &packet);
}

// 0x0054A9B0
void __fastcall PLRMSG_BroadcastSystemMessage(D2GameStrc* pGame, const char* szMessage, unsigned char nColor)
{
    D2GSPacketSrv26 packet26;
    packet26.nMessageColor = nColor;
    packet26.nHeader = 0x26;
    packet26.nMessageType = 4;
    packet26.dwUnitGUID = 0;
    packet26.nUnitType = UNIT_PLAYER;
    memcpy(packet26.szMessage, szMessage, sizeof(packet26.szMessage));
    packet26.nLang = 0;
    GAME_ForEachIngameClient(pGame, j_D2GAME_PACKETS_SendPacket0x26_ServerMessage, &packet26);
}

// 0x0054AA30
void __fastcall j_D2GAME_SendPacket0x5A(D2ClientStrc* pClient, void* pPacket)
{
    D2GAME_PACKETS_SendPacket0x5A(pClient, (D2GSPacketSrv5A*)pPacket);
}

// 0x0054AA40
void __fastcall PLRMSG_BroadcastEventMessage(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket)
{
    const char* szName = pPacket->szText;
    int i;
    for (i = 0; i < 16; ++i)
    {
        if (!szName[i])
        {
            break;
        }
    }
    if (i < 16)
        GAME_ForEachIngameClient(pGame, j_D2GAME_SendPacket0x5A, pPacket);
}

// 0x0054AA90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x13_InteractWithEntity(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt13* pPacket13 = (const D2GSPacketClt13*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = pPacket13->dwUnitType;
    const int nUnitGUID = pPacket13->dwUnitGUID;
    if (nUnitType >= 6)
    {
        return 2;
    }

    return PLRMSG_InteractWithUnit(pUnit, nUnitType, nUnitGUID, 0, pGame);
}

// 0x0054AAD0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x16_PickItemOnGround(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt16* pPacket16 = (const D2GSPacketClt16*)pPacket;
    if (nSize != 13)
    {
        return 3;
    }

    const unsigned int nUnitType = pPacket16->dwUnitType;
    const int nUnitGUID = pPacket16->dwUnitGUID;
    const int nArg = pPacket16->bCursor;
    if (nUnitType >= 6)
    {
        return 2;
    }

    if ((!pUnit ? -1 : pUnit->dwUnitId) != nUnitGUID || nUnitType != 0)
    {
        return PLRMSG_InteractWithUnit(pUnit, nUnitType, nUnitGUID, nArg, pGame);
    }

    return 3;
}

// 0x0054AB40
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x17_DropItemOnGround(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt17* pPacket17 = (const D2GSPacketClt17*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket17->dwItemGUID;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 0))
    {
        return 3;
    }

    ITEMMODE_DropCursorItem(pGame, pUnit, nItemGUID);
    return 0;
}

// 0x0054ABB0
int __fastcall sInsertItemGrid(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt18* pPacket18 = (const D2GSPacketClt18*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    const int nItemGUID = pPacket18->dwItemGUID;
    const int nX = pPacket18->dwPosX;
    const int nY = pPacket18->dwPosY;
    const unsigned int nInvPage = pPacket18->dwInvPage;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (!PLAYER_IsBusy(pUnit) && nInvPage)
        {
            return 2;
        }

        if (nInvPage == 4)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
            {
                return 3;
            }
        }
        else
        {
            if (nInvPage != 3 && nInvPage != 2 && nInvPage != 0)
            {
                return 2;
            }

            if (nInvPage == 2 && !D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
            {
                return 3;
            }
        }
    }
    else if (nInvPage >= 5)
    {
        return 2;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (pItem)
    {
        ITEMS_SetInvPage(pItem, nInvPage);
        return D2GAME_PlaceItem(".\\PLAYER\\PlrMsg.cpp", 3062, pGame, pUnit, nItemGUID, nX, nY, 0, 1, 0) ? 0 : 3;
    }

    return 2;
}

inline int PLRMSG_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int PLRMSG_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x0054ACD0
int __fastcall sRemoveItemGrid(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt19* pPacket19 = (const D2GSPacketClt19*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket19->dwItemGUID;
    int nItemStatus;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        PLRMSG_SendCantDoThat(pUnit);
        return 2;
    }

    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem)
    {
        return 2;
    }

    if (ITEMS_GetInvPage(pItem) == 1)
    {
        return 3;
    }

    if (PLAYER_CanModifyInventory(pGame, pUnit, pItem))
    {
        nItemStatus = 0;
        if (!ITEMMODE_RemoveStoredItem(pGame, pUnit, nItemGUID, &nItemStatus, 1, 0, 0, 0) && nItemStatus)
        {
            return 3;
        }
    }

    return 0;
}

// 0x0054AD90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt1A* pPacket1A = (const D2GSPacketClt1A*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = pPacket1A->nItemGUID;
    const unsigned char nBodyLoc = pPacket1A->nBodyLoc;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int nItemStatus = 0;
    if (ITEMMODE_EquipCursorItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    char szName[32];
    D2_MAYBE_UNUSED(szName);
    return 3;
}

// 0x0054AE30
int __fastcall sInsertItemBodyRmvOpp(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt1B* pPacket1B = (const D2GSPacketClt1B*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = pPacket1B->nItemGUID;
    const unsigned char nBodyLoc = pPacket1B->nBodyLoc;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    int nItemStatus = 0;
    if (ITEMMODE_ReplaceOppositeHandItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054AEC0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1C_RemoveBodyItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt1C* pPacket1C = (const D2GSPacketClt1C*)pPacket;
    if (nSize != 3)
    {
        return 3;
    }

    const int nBodyLoc = pPacket1C->nBodyLoc;
    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
    if (PLAYER_CanModifyInventory(pGame, pUnit, pItem) && (nBodyLoc != BODYLOC_BELT || PLRTRADE_IsTradeInventoryEmpty(pGame, pUnit)))
    {
        int nItemStatus = 0;
        if (!ITEMMODE_UnequipBodyItem(pGame, pUnit, nBodyLoc, 0, &nItemStatus) && nItemStatus)
        {
            return 3;
        }
    }

    return 0;
}

// 0x0054AF50
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1D_SwapCursorItemWithBody(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt1D* pPacket1D = (const D2GSPacketClt1D*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = pPacket1D->nItemGUID;
    const unsigned char nBodyLoc = pPacket1D->nBodyLoc;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLRMSG_IsBodyLocValid(nBodyLoc))
    {
        return 2;
    }

    if (!INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc))
    {
        return 1;
    }

    if (nBodyLoc == BODYLOC_BELT && !PLRTRADE_IsTradeInventoryEmpty(pGame, pUnit))
    {
        return 0;
    }

    if (!PLAYER_CanModifyInventory(pGame, pUnit, INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc)))
    {
        return 0;
    }

    int nFailed = 0;
    if (ITEMMODE_SwapCursorAndBodyItem(pGame, pUnit, nItemGUID, nBodyLoc, 0, &nFailed) || !nFailed)
    {
        return 0;
    }

    return 3;
}

// 0x0054B030
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1E_SwapTwo1HandedWithOne2HandedItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt1E* pPacket1E = (const D2GSPacketClt1E*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = pPacket1E->nItemGUID;
    const unsigned char nBodyLoc = pPacket1E->nBodyLoc;
    int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    const int nLoc = nBodyLoc;
    if (!PLRMSG_IsBodyLocValid(nLoc))
    {
        return 2;
    }

    if (nLoc != BODYLOC_RARM && nLoc != BODYLOC_LARM)
    {
        return 3;
    }

    nResult = (INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nLoc) ? -1 : 0) + 1;
    if (nResult)
    {
        return nResult;
    }

    if (!PLAYER_CanModifyInventory(pGame, pUnit, INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nLoc)))
    {
        return 0;
    }

    int nFailure;
    if (ITEMMODE_ReplaceHandItemsWithCursorItem(pGame, pUnit, nItemGUID, nBodyLoc, &nFailure) || !nFailure)
    {
        return 0;
    }

    return 3;
}

// 0x0054B0F0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x1F_SwapCursorBufferItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    D2GSPacketClt1F* pPacket1F = (D2GSPacketClt1F*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    const int nCursorItemGUID = pPacket1F->nCursorItemGUID;
    const int nInventoryItemGUID = pPacket1F->nInventoryItemGUID;
    const int nX = pPacket1F->nPosX;
    const int nY = pPacket1F->nPosY;
    D2UnitStrc* pInventoryItem;
    int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nCursorItemGUID);
    if (!nResult)
    {
        nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckStoredItem(pUnit, nInventoryItemGUID);
        if (!nResult)
        {
            pInventoryItem = SUNIT_GetServerUnit(pGame, 4, nInventoryItemGUID);
        }
    }
    if (nResult)
    {
        return nResult;
    }

    if (!pInventoryItem)
    {
        return 2;
    }

    if (ITEMS_GetInvPage(pInventoryItem) == 1)
    {
        return 3;
    }
    if (ITEMS_GetInvPage(pInventoryItem) == 2)
    {
        return 3;
    }

    int bPlaced;
    if (PLAYER_CanModifyInventory(pGame, pUnit, pInventoryItem) && !ITEMMODE_SwapCursorAndStoredItem(pGame, pUnit, nCursorItemGUID, nInventoryItemGUID, nX, nY, &bPlaced) && bPlaced)
    {

        SUNIT_GetServerUnit(pGame, 4, nCursorItemGUID);
        char szName[32];
        char szCursorItemName[32];
        D2_MAYBE_UNUSED(szName);
        D2_MAYBE_UNUSED(szCursorItemName);
        return 3;
    }

    return 0;
}

// 0x0054B1E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x20_UseGridItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    D2GSPacketClt20* pPacket20 = (D2GSPacketClt20*)pPacket;

    if (nSize != 13)
    {
        return 3;
    }

    const int nItemGUID = pPacket20->nItemGUID;
    const int nX = pPacket20->nPosX;
    const int nY = pPacket20->nPosY;
    int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = PLRMSG_CheckDistanceToPoint(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    int nStatus = 0;
    if (ITEMMODE_UseStoredItemAtCoordinates(pGame, pUnit, nItemGUID, nX, nY, &nStatus) || !nStatus)
    {
        return 0;
    }

    SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    char szName[32];
    D2_MAYBE_UNUSED(szName);
    return 3;
}

// 0x0054B280
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x27_UseItemAction(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt27* pPacket27 = (const D2GSPacketClt27*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nTargetItemGUID = pPacket27->nTargetItemGUID;
    const int nUseItemGUID = pPacket27->nUseItemGUID;
    int nResult = PLRMSG_CheckOwnedItem(nTargetItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = PLRMSG_CheckOwnedItem(nUseItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_UseItemOnItem(pGame, pUnit, nTargetItemGUID, nUseItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B300
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x21_StackItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt21* pPacket21 = (const D2GSPacketClt21*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID1 = pPacket21->nCursorItemGUID;
    const int nItemGUID2 = pPacket21->nTargetItemGUID;
    int nResult = PLRMSG_CheckOwnedItem(nItemGUID1, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = PLRMSG_CheckOwnedItem(nItemGUID2, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    if (nItemGUID1 == nItemGUID2)
    {
        return 3;
    }

    int nItemStatus;
    if (ITEMMODE_MergeItemStacks(pGame, pUnit, nItemGUID1, nItemGUID2, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B380
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x22_UnstackItems(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt22* pPacket22 = (const D2GSPacketClt22*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket22->nItemGUID;
    const int nResult = PLRMSG_CheckOwnedItem(nItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus;
    if (sub_0055E9A0_Return0(pGame, pUnit, nItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B3E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x23_ItemToBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt23* pPacket23 = (const D2GSPacketClt23*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = pPacket23->nCursorItemGUID;
    const int nBeltSlot = pPacket23->nBeltSlotId;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_PlaceCursorItemInBelt(pGame, pUnit, nItemGUID, nBeltSlot, 0, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B450
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x24_ItemFromBelt(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt24* pPacket24 = (const D2GSPacketClt24*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket24->nItemGUID;
    const int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckBeltItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (!PLAYER_CanModifyInventory(pGame, pUnit, 0))
    {
        return 0;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        return 2;
    }

    int nItemStatus = 0;
    if (ITEMMODE_RemoveBeltItemToCursor(pGame, pUnit, nItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B4E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x25_SwitchBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt25* pPacket25 = (const D2GSPacketClt25*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nCursorItemGUID = pPacket25->nCursorItemGUID;
    const int nBeltItemGUID = pPacket25->nBeltItemGUID;
    int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckBeltItem(pUnit, nBeltItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_SwapCursorAndBeltItem(pGame, pUnit, nCursorItemGUID, nBeltItemGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B560
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x26_UseBeltItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt26* pPacket26 = (const D2GSPacketClt26*)pPacket;
    if (nSize != 13)
    {
        return 3;
    }

    const int nItemGUID = pPacket26->nItemGUID;
    const int bUseOnMerc = pPacket26->bUseOnMerc;
    const int nX = PLRMSG_GetUnitX(pUnit);
    const int nY = PLRMSG_GetUnitY(pUnit);
    int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckBeltItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = PLRMSG_CheckDistanceToPoint(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_UseBeltItem(pGame, pUnit, nItemGUID, nX, nY, &nItemStatus, bUseOnMerc) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B650
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x28_SocketItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt28* pPacket28 = (const D2GSPacketClt28*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nCursorItemGUID = pPacket28->nCursorItemGUID;
    const int nSocketableItemGUID = pPacket28->nTargetItemGUID;
    int nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckCursorItem(pUnit, nCursorItemGUID);
    if (nResult)
    {
        return nResult;
    }

    nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckStoredOrEquippedItem(pUnit, nSocketableItemGUID);
    if (nResult)
    {
        return nResult;
    }

    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (pInteractUnit && pInteractUnit->dwUnitType == UNIT_PLAYER)
        {
            return 0;
        }
    }

    int bPlaced = 0;
    if (D2GAME_ITEMSOCKET_PlaceItem(pGame, pUnit, nCursorItemGUID, nSocketableItemGUID, &bPlaced, 1, 1, 1, 1) || !bPlaced)
    {
        return 0;
    }

    return 3;
}

// 0x0054B710
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x29_ScrollToBook(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt29* pPacket29 = (const D2GSPacketClt29*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nScrollGUID = pPacket29->nScrollGUID;
    const int nBookGUID = pPacket29->nBookGUID;
    int nResult = PLRMSG_CheckItemInReach(nScrollGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckStoredItem(pUnit, nBookGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_AddScrollToBook(pGame, pUnit, nScrollGUID, nBookGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B790
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2A_ItemToCubeIndirect(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt2A* pPacket2A = (const D2GSPacketClt2A*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nItemGUID = pPacket2A->dwItemGUID;
    const int nCubeGUID = pPacket2A->dwCubeGUID;
    int nResult = PLRMSG_CheckItemInReach(nItemGUID, pGame, pUnit);
    if (nResult)
    {
        return nResult;
    }

    nResult = ((D2GameItemChecks*)pGame)->PLRMSG_CheckStoredItem(pUnit, nCubeGUID);
    if (nResult)
    {
        return nResult;
    }

    int nItemStatus = 0;
    if (ITEMMODE_PlaceItemInCube(pGame, pUnit, nItemGUID, nCubeGUID, &nItemStatus) || !nItemStatus)
    {
        return 0;
    }

    return 3;
}

// 0x0054B810
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2C_2D_52(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054B820
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2D_Rejected(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054B830
void __fastcall D2GAME_PlayerChangeAct(D2GameStrc* pGame, D2UnitStrc* pUnit, int dwDestLvl, int nTileCalc)
{
    const unsigned char nDestAct = DRLG_GetActNoFromLevelId(dwDestLvl);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const unsigned char nSourceAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));

    if (!dwDestLvl)
    {
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nSourceAct);
        LEVEL_WarpUnit(pGame, pUnit, nTownLevelId, nTileCalc);
        return;
    }

    if (nDestAct == nSourceAct)
    {
        const int nX = PLRMSG_GetUnitXInline(pUnit) - 5;
        const int nY = PLRMSG_GetUnitYInline(pUnit);
        D2GAME_CreatePortalObject(pGame, pUnit, pRoom, nX, nY, dwDestLvl, 0, OBJECT_TOWN_PORTAL, 0);
    }
    else
    {
        LEVEL_WarpUnit(pGame, pUnit, dwDestLvl, nTileCalc);
    }
}

// 0x0054B920
int __stdcall D2GAME_PACKETCALLBACK_Rcv0x2E_Ignored(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0054B930
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt2F* pPacket2F = (const D2GSPacketClt2F*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    D2UnitStrc* pNpc;
    const int nResult = PLRMSG_GetInteractNpc(1, pGame, pUnit, &pNpc, pPacket2F->nUnitGUID);
    if (!nResult)
    {
        MONSTERAI_ActivateNpcInteraction(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
        return 0;
    }

    return nResult;
}

// 0x0054B9F0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x30_TerminateEntityChat(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt30* pPacket30 = (const D2GSPacketClt30*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    D2UnitStrc* pNpc;
    const int nResult = PLRMSG_GetInteractNpc(0, pGame, pUnit, &pNpc, pPacket30->nUnitGUID);
    if (nResult)
    {
        return nResult;
    }

    MONSTERAI_EndNpcInteraction(pGame, pUnit, pNpc, PLRMSG_GetMonInteract(pNpc));
    return 0;
}

// 0x0054BA90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x31_QuestMessage(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt31* pPacket31 = (const D2GSPacketClt31*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    QUESTS_NPCMessage(pGame, pUnit, pPacket31->nNpcGUID, pPacket31->nMessageId);
    return 0;
}

// 0x0054BAC0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x32_BuyItemFromNpcBuffer(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2BuyItemPacketStrc* pPacket, int nSize)
{
    if (nSize != sizeof(D2BuyItemPacketStrc))
        return 3;

    unsigned int nTransactionType = pPacket->nTransactionType;
    const int nNpcUnitId = pPacket->nNpcUnitId;
    const int nItemId = pPacket->nItemId;
    const int nCost = pPacket->nCost;
    const int bMultibuy = nTransactionType & 0x80000000;
    nTransactionType &= 0x7FFFFFFF;
    return D2GAME_NPC_BuyItemHandler(pGame, pPlayer, nNpcUnitId, nItemId,
        nTransactionType >> 16, nTransactionType, nCost, bMultibuy);
}

// 0x0054BB20
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x33_SellItemToNpcBuffer(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt33* pPacket33 = (const D2GSPacketClt33*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    const int nNpcGUID = pPacket33->dwMonGUID;
    const int nItemGUID = pPacket33->dwItemGUID;
    const unsigned short nItemMode = pPacket33->nTab;
    const int nCost = pPacket33->dwGold;
    return D2GAME_STORES_SellItem(pGame, pUnit, nNpcGUID, nItemGUID, nItemMode, nCost);
}

// 0x0054BB60
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x35_Repair(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt35* pPacket35 = (const D2GSPacketClt35*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    D2GAME_NPC_Repair(pGame, pUnit, pPacket35->nNpcGUID, pPacket35->nItemGUID, pPacket35->nItemMode, pPacket35->nRepairFlags);
    return 0;
}


// 0x0054BBA0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x34_IdentifyItemsWithNpc(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt34* pPacket34 = (const D2GSPacketClt34*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    D2GAME_NPC_IdentifyAllItems(pGame, pUnit, pPacket34->nNpcGUID);
    return 0;
}

// 0x0054BBD0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x36_HireMerc(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt36* pPacket36 = (const D2GSPacketClt36*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    D2GAME_NPC_HireMerc(pGame, pUnit, pPacket36->nNpcGUID, pPacket36->nHirelingId);
    return 0;
}


// 0x0054BC00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x62_ResurrectMerc(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt62* pPacket62 = (const D2GSPacketClt62*)pPacket;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (nSize != 5)
    {
        return 3;
    }

    D2GAME_NPC_ResurrectMerc(pGame, pUnit, pPacket62->nNpcGUID);
    return 0;
}

// 0x0054BC30
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x37_IdentifyFromGamble(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt37* pPacket37 = (const D2GSPacketClt37*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket37->nItemGUID;
    if (!SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID))
    {
        return 2;
    }

    const int nBoughtItemId = UNITS_GetPlayerData(pUnit)->dwBoughtItemId;
    if (nBoughtItemId != nItemGUID)
    {
        return 3;
    }

    D2GAME_NPC_IdentifyBoughtItem(pGame, pUnit, nItemGUID);
    return 0;
}

// 0x0054BCA0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x38_EntityAction(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt38* pPacket38 = (const D2GSPacketClt38*)pPacket;
    if (nSize != 13)
    {
        return 3;
    }

    const int nAction = pPacket38->nAction;
    const int nNpcGUID = pPacket38->nNpcGUID;
    const int nItemGUID = pPacket38->nItemGUID;
    const int nResult = PLRMSG_CheckTargetUnit(50, pGame, pUnit, 1, nNpcGUID);
    if (nResult)
    {
        return nResult;
    }

    return NPC_HandleDialogMessage(pGame, pUnit, nAction, nNpcGUID, nItemGUID);
}

// 0x0054BD00
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x39_PurchaseLife(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054BD10
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3A_AddStatPoint(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt3A* pPacket3A = (const D2GSPacketClt3A*)pPacket;
    if (nSize != 3)
    {
        return 3;
    }

    const unsigned short nValue = pPacket3A->nStat;
    int nCount = (nValue >> 8) + 1;
    const int nStatId = nValue & 0xFF;
    if (nStatId <= -1 || nStatId >= 16 || nCount < 1 || nCount > 100)
    {
        return 3;
    }

    while (nCount)
    {
        --nCount;
        if (!PLAYERSTATS_SpendStatPoint(pUnit, nStatId))
        {
            return 2;
        }
    }

    return 0;
}

// 0x0054BD90
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3B_AddSkillPoint(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 3)
    {
        return 3;
    }
    const int nSkillId = ((D2GSPacketClt3B*)pPacket)->nSkill;
    const int nResult = PLRMSG_CheckSkillAllocation(pUnit, nSkillId);
    if (nResult)
    {
        if (nResult == 2)
        {
            D2GAME_PACKETS_SendPacket0x21_UpdateSkills(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x114F), pUnit, 0, 1, 0);
        }
        return nResult;
    }
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    if (pSkill && SKILLS_GetSkillLevel(pUnit, pSkill, 0) >= SPELLSEL_GetSkillMaxLevel(nSkillId))
    {
        D2GAME_PACKETS_SendPacket0x21_UpdateSkills(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1159), pUnit, 0, 1, 0);
        return 2;
    }
    if (!SKILLS_TryIncreaseSkillLevel(pUnit, nSkillId))
    {
        return 2;
    }
    sub_0055F4F0_Nop(pGame, pUnit, 1);
    SKILLS_RefreshPassivesAndPetLimits(pUnit);
    return 0;
}

// 0x0054BE70
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3C_SelectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt3C* pPacket3C = (const D2GSPacketClt3C*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nValue = pPacket3C->nSkill;
    const int nOwnerGUID = pPacket3C->nOwnerGUID;
    const int bLeftSkill = (unsigned int)nValue >> 31;
    const int nSkillId = nValue & 0x7FFFFFFF;
    if (nSkillId < 0)
    {
        return 3;
    }

    if (nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 3;
    }

    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID);
    if (!pSkill)
    {
        return 3;
    }

    if (!SKILLS_GetSkillLevel(pUnit, pSkill, 1))
    {
        return 3;
    }

    D2GAME_AssignSkill(pUnit, bLeftSkill, nSkillId, nOwnerGUID);
    if (bLeftSkill)
    {
        UNITS_InitLeftSkill(pUnit);
    }
    else
    {
        UNITS_InitRightSkill(pUnit);
    }

    return 0;
}

// 0x0054BF10
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3D_HighlightADoor(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt3D* pPacket3D = (const D2GSPacketClt3D*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nObjectGUID = pPacket3D->nDoorGUID;
    const int nResult = PLRMSG_CheckTargetUnit(10, pGame, pUnit, 2, nObjectGUID);
    if (nResult)
    {
        return nResult;
    }

    OBJMODE_UpdateDoorModeFromCollision(pGame, pUnit, nObjectGUID);
    return 0;
}

// 0x0054BF60
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3E_ActivateInifussScroll(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt3E* pPacket3E = (const D2GSPacketClt3E*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket3E->nItemGUID;
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, 4, nItemGUID);
    if (!pItem)
    {
        return 1;
    }

    if (!ITEMS_IsInPlayersInventory(pUnit, pItem, 0))
    {
        const unsigned char nUnitAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
        if (nUnitAct != DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pItem))))
        {
            return 2;
        }

        const int nX = PLRMSG_GetUnitX(pItem);
        const int nResult = PLRMSG_CheckDistanceToPoint(nX, PLRMSG_GetUnitY(pItem), pUnit, 10);
        if (nResult)
        {
            return nResult;
        }
    }

    QUESTS_UseClueItem(pGame, pUnit, nItemGUID);
    return 0;
}

static inline int HasSoundFlag(D2UnitStrc* pUnit)
{
    return pUnit ? (pUnit->dwFlags >> 10) & 1 : 0;
}

// 0x0054C070
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x3F_PlayAudio(D2GameStrc* pGame, D2UnitStrc* pUnit, const unsigned char* pPacket, int nSize)
{
    if (nSize != 3)
        return 3;
    unsigned int nSound = *(const unsigned short*)(pPacket + 1);
    if (nSound >= 25 && nSound <= 32)
    {
        if (!HasSoundFlag(pUnit))
            SUNIT_AttachSound(pUnit, nSound, 0);
        else
            return 1;
    }
    return 0;
}

// 0x0054C0C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x40_RequestQuestData(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    QUESTS_StatusCallback(pGame, pUnit);
    return 0;
}

// 0x0054C0E0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x41_Resurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!pUnit || pUnit->dwAnimMode != PLRMODE_DEAD)
    {
        return 0;
    }

    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 4579);
    if (CLIENTS_CheckFlag(pClient, CLIENTSAVEFLAG_HARDCORE))
    {
        SrvDisconnectClient(pGame, pClient, EVENTTYPE_PLAYERLEFT);
        return 0;
    }

    const int n0 = ARENA_Return0(pGame, pUnit);
    D2GAME_RefreshPassiveSkills(pUnit);

    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pUnit);
    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxLife, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMaxMana, 0);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);
    D2GAME_UpdateAttribute(pUnit, STAT_HITPOINTS, nMaxLife, pUnit);
    D2GAME_UpdateAttribute(pUnit, STAT_MANA, nMaxMana, pUnit);
    D2GAME_UpdateAttribute(pUnit, STAT_STAMINA, nMaxStamina, pUnit);

    pUnit->dwFlags |= UNITFLAG_TARGETABLE;

    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, 1);
    STATES_ToggleState(pUnit, STATE_UNINTERRUPTABLE, 0);

    DRLG_GetActNoFromLevelId(0);
    const unsigned char nSourceAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit)));
    const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nSourceAct);
    LEVEL_WarpUnit(pGame, pUnit, nTownLevelId, n0);

    PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, 1, 0, 0, 1);

    D2SkillStrc* pLeftSkill = UNITS_GetLeftSkill(pUnit);
    if (pLeftSkill)
    {
        D2GAME_AssignSkill(pUnit, 1, SKILLS_GetSkillIdFromSkill(pLeftSkill, ".\\PLAYER\\PlrMsg.cpp", 4617), SKILLS_GetOwnerGUIDFromSkill(pLeftSkill));
    }

    D2SkillStrc* pRightSkill = UNITS_GetRightSkill(pUnit);
    if (pRightSkill)
    {
        D2GAME_AssignSkill(pUnit, 0, SKILLS_GetSkillIdFromSkill(pRightSkill, ".\\PLAYER\\PlrMsg.cpp", 4622), SKILLS_GetOwnerGUIDFromSkill(pRightSkill));
    }

    return 0;
}

// 0x0054C2A0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5D_SquelchHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt5D* pPacket5D = (const D2GSPacketClt5D*)pPacket;
    if (nSize != 7)
    {
        return 3;
    }

    if (ARENA_IsActive(pGame))
    {
        return 3;
    }

    const unsigned char nCommand = pPacket5D->nType;
    const int nArg = pPacket5D->dwPlayerGUID;
    if (nCommand > 10)
    {
        return 2;
    }

    return PARTYSCREEN_CommandHandler(pGame, pUnit, nCommand, nArg, pPacket5D->nToggle);
}

// 0x0054C300
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5E_InviteToParty(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt5E* pPacket5E = (const D2GSPacketClt5E*)pPacket;
    if (nSize != 6)
    {
        return 3;
    }

    if (ARENA_IsActive(pGame))
    {
        return 3;
    }

    const unsigned char nCommand = pPacket5E->nType;
    if (nCommand > 10)
    {
        return 2;
    }

    PARTYSCREEN_CommandHandler(pGame, pUnit, nCommand, pPacket5E->dwPlayerGUID, 0);
    return 0;
}

// 0x0054C360
int __stdcall D2GAME_PACKETCALLBACK_Rcv0x42_Ignored(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0054C370
int __stdcall D2GAME_PACKETCALLBACK_Rcv0x43_Ignored(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0054C380
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x44_StaffInOrifice(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt44* pPacket44 = (const D2GSPacketClt44*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    const int nObjectGUID = pPacket44->nAnvilInteractGUID;
    const int nItemGUID = pPacket44->nItemGUID;
    const unsigned short nState = pPacket44->nState;
    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    const int nResult = PLRMSG_CheckOrificeObject(nItemGUID, nState, pGame, pUnit, nObjectGUID);
    if (!nResult)
    {
        OBJMODE_MainObeliskHandler(pGame, !pUnit ? -1 : pUnit->dwUnitId, nObjectGUID, nItemGUID, nState);
    }

    return nResult;
}

// 0x0054C420
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x45_ChangeTpLocation(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

static inline int sub_E03_PlrGetUnitX(D2UnitStrc* pUnit)
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

static inline int sub_E03_PlrGetUnitY(D2UnitStrc* pUnit)
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

// 0x0054C430
static int __stdcall PLRMSG_CommandMerc(int nParam1, int nParam2, int nCommand, D2GameStrc* pGame, D2UnitStrc* pUnit, int nMercGUID)
{
    D2UnitStrc* pMerc = SUNIT_GetServerUnit(pGame, 1, nMercGUID);
    if (!pMerc)
    {
        return 1;
    }

    if (PLAYERPETS_GetFirstPetByType(pGame, pUnit, 7, 0) != pMerc)
    {
        return 1;
    }

    AIGENERAL_FreeAllAiCommands(pGame, pMerc);

    D2AiCmdStrc aiCmd;
    aiCmd.nCmdParam[0] = nCommand;
    aiCmd.nCmdParam[1] = nParam1;
    aiCmd.nCmdParam[2] = nParam2;
    AIGENERAL_CopyAiCommand(pGame, pMerc, &aiCmd);

    SUNIT_AttachSound(pMerc, 0xF, pUnit);
    return 0;
}

// 0x0054C4B0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x46_MercInteract(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nMercGUID = *(int*)(pPacket + 1);
    const unsigned int nUnitType = *(unsigned int*)(pPacket + 9);
    const int nItemGUID = *(int*)(pPacket + 5);
    if (nUnitType >= 6)
    {
        return 2;
    }

    const int nResult = PLRMSG_CheckTargetUnit(50, pGame, pUnit, nUnitType, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    return PLRMSG_CommandMerc(nItemGUID, nUnitType, 12, pGame, pUnit, nMercGUID);
}

// 0x0054C520
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x47_MoveMerc(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 13)
    {
        return 3;
    }

    const int nMercGUID = *(int*)(pPacket + 1);
    const unsigned short nX = *(unsigned short*)(pPacket + 5);
    const unsigned short nY = *(unsigned short*)(pPacket + 9);

    const int nResult = PLRMSG_CheckDistanceToPoint(nX, nY, pUnit, 50);
    if (nResult)
    {
        return nResult;
    }

    PLRMSG_CommandMerc(nX, nY, 13, pGame, pUnit, nMercGUID);
    return 0;
}


// 0x0054C590
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x48_TurnOffBusyState(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!UNITS_GetPlayerData(pUnit)->bBusy)
    {
        return 2;
    }

    PLAYER_ResetBusyState(pUnit);
    return 0;
}

// 0x0054C5D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x49_TakeOrCloseWp(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pPacket, int nSize)
{
    if (nSize != 9)
    {
        return 3;
    }

    const int nWaypointGUID = *(int*)(pPacket + 1);
    const int nLevelId = *(unsigned short*)(pPacket + 5);
    const unsigned int nTick = PLAYERLIST_GetHostileDelay(pUnit, 0) + 0x2710;
    if (nTick > GetTickCount())
    {
        SUNIT_AttachSound(pUnit, 0x13, pUnit);
        SUNIT_ResetInteractInfo(pUnit);
        return 1;
    }

    const int nResult = PLRMSG_CheckWaypointObject(pGame, nLevelId, pUnit, nWaypointGUID);
    if (nResult)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetInteractUnit(pGame, pUnit);
        D2UnitStrc* pWaypoint = SUNIT_GetServerUnit(pGame, 2, nWaypointGUID);
        if (pWaypoint && pWaypoint == pInteractUnit)
        {
            SUNIT_ResetInteractInfo(pUnit);
        }

        return nResult;
    }

    OBJMODE_TravelViaWaypoint(pGame, pUnit, nWaypointGUID, nLevelId);
    return 0;
}


// 0x0054C690
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4D_PlayNpcMessage(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt4D* pPacket4D = (const D2GSPacketClt4D*)pPacket;
    if (nSize != 3)
    {
        return 3;
    }

    const int nMonsterId = pPacket4D->nMonStatsId;
    if (nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 2;
    }

    PLRINTRO_MaskNpcIntroFlag(pGame, pUnit, nMonsterId);
    return 0;
}

// 0x0054C6D0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4B_RequestEntityUpdate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt4B* pPacket4B = (const D2GSPacketClt4B*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nUnitType = pPacket4B->nUnitType;
    const int nUnitGUID = pPacket4B->nUnitGUID;
    if (nUnitType >= UNIT_TYPES_COUNT)
    {
        return 2;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (nUnitType == UNIT_PLAYER && pTarget != pUnit)
    {
        return 3;
    }

    if (!pTarget)
    {
        return 1;
    }

    if (!UNITFINDS_AreUnitsInNeighboredRooms(pUnit, pTarget))
    {
        return 1;
    }

    UNITROOM_RefreshUnit(pTarget);
    pTarget->dwFlagEx |= UNITFLAGEX_TELEPORTED;
    return 0;
}

// 0x0054C760
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4C_Transmogrify(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt4C* pPacket4C = (const D2GSPacketClt4C*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket4C->nItemGUID;
    D2UnitStrc* pItem = SUNIT_GetServerUnit(pGame, UNIT_ITEM, nItemGUID);
    if (!pItem && nItemGUID != -1)
    {
        return 1;
    }

    SKILLS_HandleTransmogrify(pGame, pUnit, pItem);
    return 0;
}

// 0x0054C7C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x4F_ClickButton(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt4F* pPacket4F = (const D2GSPacketClt4F*)pPacket;
    if (nSize != 7)
    {
        return 3;
    }

    const unsigned short nButton = pPacket4F->nButtonId;
    const unsigned short nHigh = pPacket4F->nParam1;
    const unsigned short nLow = pPacket4F->nParam2;
    return PLRTRADE_HandleTradeButton(pGame, pUnit, nButton, (nHigh << 16) | nLow);
}

// 0x0054C800
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x50_DropGold(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt50* pPacket50 = (const D2GSPacketClt50*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const int nUnitGUID = pPacket50->nUnitGUID;
    const int nGoldValue = pPacket50->nGold;
    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    return PLAYER_DropGold(pGame, pUnit, nUnitGUID, nGoldValue) ? 0 : 3;
}

// 0x0054C870
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x51_BindHotkeyToSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt51* pPacket51 = (const D2GSPacketClt51*)pPacket;
    if (nSize != 9)
    {
        return 3;
    }

    const unsigned int nValue = pPacket51->nSkillId;
    const int nOwnerGUID = pPacket51->nOwnerGUID;
    const unsigned int nHotKeyId = nValue >> 16;
    if (nHotKeyId <= 15)
    {
        int nSkillId = nValue & 0x7FFF;
        if (nSkillId > sgptDataTables->nSkillsTxtRecordCount)
        {
            nSkillId = -1;
        }
        else if (nSkillId != -1)
        {
            if (nSkillId < 0)
            {
                return 3;
            }

            if (nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
            {
                return 3;
            }

            if (!SKILLS_GetSkillById(pUnit, nSkillId, nOwnerGUID))
            {
                return 3;
            }
        }

        return PLAYER_SetSkillHotKey(pGame, pUnit, nHotKeyId, nSkillId, (nValue >> 15) & 1, nOwnerGUID) ? 0 : 3;
    }

    return 3;
}

// 0x0054C930
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x52_Rejected(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    return 3;
}

// 0x0054C940
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x53_TurnStaminaOn(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == PLRMODE_WALK)
    {
        if (STATLIST_UnitGetStatValue(pUnit, STAT_STAMINA, 0))
        {
            UNITS_ChangeAnimMode(pUnit, PLRMODE_RUN);
        }
    }

    return 0;
}

// 0x0054C990
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x54_TurnStaminaOff(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == PLRMODE_RUN)
    {
        UNITS_ChangeAnimMode(pUnit, PLRMODE_WALK);
    }

    return 0;
}

// 0x0054C9C0
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x58_QuestCompleted(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt58* pPacket58 = (const D2GSPacketClt58*)pPacket;
    if (nSize != 3)
    {
        return 3;
    }

    const int nQuestId = pPacket58->nQuest;
    if (nQuestId < MAX_QUEST_STATUS)
    {
        D2BitBufferStrc* pQuestData = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestData, nQuestId, QFLAG_UPDATEQUESTLOG);
        return 0;
    }

    return 2;
}

// 0x0054CA10
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x59_MakeEntityMove(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt59* pPacket59 = (const D2GSPacketClt59*)pPacket;
    if (nSize != 17)
    {
        return 3;
    }

    const unsigned int nUnitType = pPacket59->nUnitType;
    const int nUnitGUID = pPacket59->dwUnitGUID;
    const int nParam2Value = pPacket59->dwTargetX;
    const int nParam3Value = pPacket59->dwTargetY;
    if (nUnitType >= 6)
    {
        return 2;
    }

    D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (pNpc && D2Common_10399(pUnit, pNpc) <= 50)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pNpc->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_INTERACT >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_INTERACT & 7] && pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_NPC >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_NPC & 7])
        {
            if (pNpc->pDynamicPath)
            {
                D2Common_10153(pNpc->pDynamicPath);
            }

            D2GAME_EVENTS_Delete(pGame, pNpc, EVENTTYPE_AITHINK, 0);
            EVENT_SetEvent(pGame, pNpc, EVENTTYPE_AITHINK, pGame->dwGameFrame + 1, 0, 0);
            AIGENERAL_SetAiControlParam(pNpc, 1, 40);
            AIGENERAL_SetAiControlParam(pNpc, 2, nParam2Value);
            AIGENERAL_SetAiControlParam(pNpc, 3, nParam3Value);
            return 0;
        }
    }

    return 1;
}

// 0x0054CB10
static int __stdcall PLRMSG_TestPathToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!COLLISION_GetRoomBySubTileCoordinates(pRoom, nX, nY))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_SYNC_WARPED))
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    const int nMask = PATH_GetMoveTestCollisionMask(pPath);
    const int nPathType = PATH_GetType(pPath);
    const unsigned char nNewDistance = PATH_GetMaxDistance(pPath);
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    const int nFirstX = D2COMMON_10175_PathGetFirstPointX(pPath);
    const int nFirstY = D2COMMON_10176_PathGetFirstPointY(pPath);

    PATH_SetMoveTestCollisionMask(pPath, 0x409);
    PATH_SetType(pPath, 15);
    PATH_SetNewDistance(pPath, 77);
    PATH_SetTargetPos(pPath, nX, nY);

    int bResult = D2Common_10142(pPath, pUnit, 0);
    if (bResult)
    {
        if (nX == PATH_GetLastPointX(pPath) && nY == PATH_GetLastPointY(pPath))
        {
            bResult = 1;
        }
        else
        {
            bResult = 0;
        }
    }

    PATH_SetMoveTestCollisionMask(pPath, nMask);
    PATH_SetType(pPath, nPathType);
    PATH_SetNewDistance(pPath, nNewDistance);

    if (pTargetUnit)
    {
        PATH_SetPathTarget(pPath, pTargetUnit);
    }
    else
    {
        PATH_SetTargetPos(pPath, nFirstX, nFirstY);
    }

    return bResult;
}

// 0x0054CC30
void __fastcall PLRMSG_ToggleStateOffCallback(D2UnitStrc* unit, int state, int unused)
{
    STATES_ToggleState(unit, state, 0);
}

// 0x0054CC40
static int __stdcall PLRMSG_WarpToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY)
{
    if (!SUNIT_TeleportUnit(pGame, pUnit, 0, nX, nY, 0, 1))
    {
        return 0;
    }

    CLIENTS_NotifyWarpAttempt(pGame, pUnit);

    int nDelay = 125;
    if (CLIENTS_ShouldDelayWarpAttempt(pGame, pUnit) && !pGame->nGameType)
    {
        D2SeedStrc* pSeed = &pUnit->pSeed;
        const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
        pSeed->lSeed = lSeed;
        int nRand = (unsigned int)lSeed % 100;
        for (int i = 0; i < 3; ++i)
        {
            if (nRand < gaWarpDelays[i].nChance)
            {
                nDelay = gaWarpDelays[i].nDelay;
                break;
            }

            nRand -= gaWarpDelays[i].nChance;
        }
    }

    const int nEndFrame = pGame->dwGameFrame + nDelay;
    STATES_ToggleState(pUnit, STATE_SYNC_WARPED, 1);

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nEndFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    STATLIST_SetState(pStatList, STATE_SYNC_WARPED);
    STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)sub_0054CC30_StatRemoveCallback_ToggleStateOff);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    EVENT_SetEvent(pGame, pUnit, 12, nEndFrame, 0, 0);
    return 1;
}

// 0x0054CD50
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x5F_UpdatePlayerPos(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != sizeof(D2GSPacketClt5F))
    {
        return 3;
    }

    const int nX = ((D2GSPacketClt5F*)pPacket)->nX;
    const int nY = ((D2GSPacketClt5F*)pPacket)->nY;

    D2ClientStrc* hClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 5654);
    D2_ASSERT(hClient, 5655);

    if (UNITS_GetUsedSkill(pUnit) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    const int nDistance = DRLG_GetDistanceToXY(pUnit, nX, nY);
    if (nDistance < 5)
    {
        return 0;
    }

    if (!STATES_CheckState(pUnit, STATE_SYNC_WARPED) && nDistance >= 15 && nDistance <= 45)
    {
        if (!PLRMSG_TestPathToCoords(pGame, pUnit, nX, nY) || !PLRMSG_WarpToCoords(pGame, pUnit, nX, nY))
        {
            PLRMSG_SendUnitPosition(pUnit, hClient, 0);
        }

        return 0;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        PLRMODE_ChangeModeToCoords(pGame, pUnit, 0, ((!pUnit ? 0 : pUnit->dwAnimMode) == 3) + 2, nX, nY, 0);
    }

    return 0;
}

// 0x0054CE70
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x60_SwapWeapons(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    if (nSize != 1)
    {
        return 3;
    }

    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (UNITS_GetUsedSkill(pUnit) || SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    int nStatus = 0;
    if (ITEMMODE_SwapWeaponSets(pGame, pUnit, &nStatus) || !nStatus)
    {
        return 0;
    }

    return 3;
}

static inline int UNITS_GetAnimMode_H15(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwAnimMode : 0;
}

// 0x0054CED0
static int __stdcall D2GAME_MERCS_EquipItem(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2GameStrc* pGame, D2UnitStrc* pMerc)
{
    if (!pGame->bExpansion)
    {
        return 3;
    }

    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    if (!pPlayerInventory)
    {
        return 0;
    }

    if (!pMerc->pInventory)
    {
        INVENTORY_AllocInventory(0, pMerc);
    }

    D2InventoryStrc* pMercInventory = pMerc->pInventory;
    if (!pMercInventory)
    {
        return 0;
    }

    unsigned char nBodyLoc2;
    unsigned char nBodyLoc1;
    ITEMS_GetAllowedBodyLocations(pItem, &nBodyLoc1, &nBodyLoc2);

    D2UnitStrc* pItem1 = INVENTORY_GetItemFromBodyLoc(pMercInventory, nBodyLoc1);
    D2UnitStrc* pItem2 = INVENTORY_GetItemFromBodyLoc(pMercInventory, nBodyLoc2);

    D2UnitStrc* pExchangeItem;
    int nTargetBodyLoc;
    if (pMerc->dwClassId == MONSTER_ACT3HIRE && ITEMSIsA(pItem, 2))
    {
        pExchangeItem = pItem2;
        nTargetBodyLoc = nBodyLoc2;
    }
    else
    {
        pExchangeItem = pItem1;
        nTargetBodyLoc = nBodyLoc1;
    }

    if (pExchangeItem)
    {
        if (pExchangeItem != INVENTORY_RemoveItemFromInventory(pMercInventory, pExchangeItem))
        {
            return 0;
        }

        sub_0063BE30(pMercInventory, nTargetBodyLoc);
        D2GAME_ITEMS_UpdateTransferredProperties(pGame, pExchangeItem, pMerc, 0, 0);
        D2GAME_ITEMS_UpdateInventoryItems(pGame, pMerc, 0, 0);

        if (!ITEMS_CheckRequirements(pItem, pMerc, 0, 0, 0, 0))
        {
            sub_0063BDB0(pMercInventory, pExchangeItem, nTargetBodyLoc);
            INVENTORY_PlaceItemInSocket(pMercInventory, pExchangeItem, 3);
            ITEMS_SetBodyLocation(pExchangeItem, nTargetBodyLoc);
            UNITS_ChangeAnimMode(pExchangeItem, 1);
            ITEMS_SetInvPage(pExchangeItem, 0xFF);
            ITEMMODE_UpdateItemStatlist(pGame, pExchangeItem, pMerc, 0);
            sub_0055F4F0_Nop(pGame, pMerc, 0);
            return 0;
        }

        ITEMS_SetItemCMDFlag(pExchangeItem, 0x10, 1);
        INVENTORY_AddItemToTradeInventory(pMercInventory, pExchangeItem);
        ITEMS_SetItemFlag(pExchangeItem, 0x20, 1);
        UNITS_RefreshInventory(pMerc, 1);
    }

    D2UnitStrc* pDupeItem = ITEMS_Duplicate(pGame, pItem, pMerc, 1);
    UNITS_ChangeAnimMode(pDupeItem, 4);

    const int nItemGUID = pItem->dwUnitId;
    D2GAME_EVENTS_Delete(pGame, pMerc, 9, nItemGUID);
    D2GAME_EVENTS_Delete(pGame, pPlayer, 9, nItemGUID);

    int nUnused;
    ITEMMODE_EquipCursorItem(pGame, pMerc, !pDupeItem ? -1 : pDupeItem->dwUnitId, nTargetBodyLoc, 1, &nUnused);

    D2GAME_RemoveItemIfOnCursor(pGame, pPlayer, pItem);
    INVENTORY_SetCursorItem(pPlayerInventory, 0);

    if (pExchangeItem)
    {
        D2UnitStrc* pCursorItem = ITEMS_Duplicate(pGame, pExchangeItem, pPlayer, 1);
        INVENTORY_SetCursorItem(pPlayerInventory, pCursorItem);
        ITEMMODE_MarkItemOnCursor(pGame, pPlayer, pCursorItem);
    }

    D2GAME_ITEMS_UpdateInventoryItems(pGame, pMerc, 0, 0);
    sub_0055F4F0_Nop(pGame, pMerc, 0);
    D2GAME_EVENTS_Delete(pGame, pMerc, 3, 0);
    EVENT_SetEvent(pGame, pMerc, 3, pGame->dwGameFrame + 1, 0, 0);
    return 1;
}

static inline int sub_RemoveEquippedItem(D2UnitStrc* pMerc, D2UnitStrc* pItem)
{
    return pItem && (!pItem ? -1 : pItem->dwAnimMode) == 1 && pItem == INVENTORY_RemoveItemFromInventory(pMerc->pInventory, pItem);
}

// 0x0054D130
static int __stdcall PLRMSG_TakeMercItemToCursor(D2GameStrc* pGame, D2UnitStrc* pMerc, D2UnitStrc* pPlayer, int nBodyLoc)
{
    D2InventoryStrc* pPlayerInventory = pPlayer->pInventory;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (!pMerc->pInventory || nBodyLoc < 1 || nBodyLoc > 10)
    {
        return 3;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pMerc->pInventory, nBodyLoc);
    if (!sub_RemoveEquippedItem(pMerc, pItem))
    {
        return 2;
    }

    sub_0063BE30_Return(pMerc->pInventory, nBodyLoc);
    D2GAME_ITEMS_UpdateTransferredProperties(pGame, pItem, pMerc, 0, 0);
    ITEMS_SetItemCMDFlag(pItem, 16, 1);
    INVENTORY_AddItemToTradeInventory(pMerc->pInventory, pItem);
    UNITS_RefreshInventory(pMerc, 1);

    D2UnitStrc* pCursorItem = ITEMS_Duplicate(pGame, pItem, pPlayer, 1);
    INVENTORY_SetCursorItem(pPlayerInventory, pCursorItem);
    ITEMMODE_MarkItemOnCursor(pGame, pPlayer, pCursorItem);
    ITEMS_SetItemFlag(pItem, 0x20, 1);
    D2GAME_ITEMS_UpdateInventoryItems(pGame, pMerc, 0, 0);
    D2GAME_UpdatePlayerVitals(pGame, pMerc);
    sub_0055F4F0_Nop(pGame, pMerc, 0);
    return 0;
}

// 0x0054D230
static int __stdcall PLRMSG_TryEquipMercItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, D2UnitStrc* pItem)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    if (!pGame->bExpansion)
    {
        return 3;
    }

    if (!ITEMS_CheckItemFlag(pItem, 0x10, 0x1728, ".\\PLAYER\\PlrMsg.cpp") || ITEMS_CheckItemFlag(pItem, 0x100, 0x172B, ".\\PLAYER\\PlrMsg.cpp"))
    {
        return 0;
    }

    if (ITEMSIsA(pItem, 0x4C) || ITEMSIsA(pItem, 0x51) || ITEMSIsA(pItem, 0x50))
    {
        SKILLITEM_pSpell_Handler(pGame, pMerc, pItem, pItem, 0, 0);
        D2GAME_RemoveItemIfOnCursor(pGame, pPlayer, pItem);
        INVENTORY_SetCursorItem(pInventory, 0);
        return 1;
    }

    int bCanBeEquipped = 0;
    if (ITEMSIsA(pItem, 3) || ITEMSIsA(pItem, 0x25))
    {
        bCanBeEquipped = 1;
    }

    switch (!pMerc ? -1 : (unsigned int)pMerc->dwClassId)
    {
    case 0x10F:
        if (ITEMSIsA(pItem, 0x1B))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x152:
        if (ITEMSIsA(pItem, 0x21) || ITEMSIsA(pItem, 0x22))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x167:
        if (!(ITEMSIsA(pItem, 2) || ITEMSIsA(pItem, 0x1E) && !ITEMS_CheckWeaponIfTwoHanded(pItem)))
        {
            break;
        }

        bCanBeEquipped = 1;
        break;

    case 0x230:
        if (ITEMSIsA(pItem, 0x1C) && !ITEMS_CheckWeaponIfTwoHanded(pItem))
        {
            bCanBeEquipped = 1;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bCanBeEquipped = 1;
        }
        break;

    case 0x231:
        if (ITEMSIsA(pItem, 0x1E))
        {
            bCanBeEquipped = 1;
        }
        if (ITEMSIsA(pItem, 0x47))
        {
            bCanBeEquipped = 1;
        }
        break;
    }

    if (!bCanBeEquipped || !ITEMS_CheckRequirements(pItem, pMerc, 0, 0, 0, 0))
    {
        SUNIT_AttachSound(pMerc, 0x55, pPlayer);
        return 0;
    }

    if (D2GAME_MERCS_EquipItem(pPlayer, pItem, pGame, pMerc))
    {
        SUNIT_AttachSound(pMerc, 0x57, pPlayer);
        return 1;
    }

    SUNIT_AttachSound(pMerc, 0x56, pPlayer);
    return 0;
}

// 0x0054D430
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x61_DropPickupMercItem(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt61* pPacket61 = (const D2GSPacketClt61*)pPacket;
    if (nSize != 3)
    {
        return 3;
    }

    if (!pGame->bExpansion)
    {
        return 3;
    }

    const unsigned short nBodyLoc = pPacket61->nBodyLoc;

    if (PLAYER_IsBusy(pUnit) && D2GAME_PLRTRADE_IsInteractingWithPlayer(pGame, pUnit, 1))
    {
        return 3;
    }

    if (UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pMerc = PLAYERPETS_GetFirstPetByType(pGame, pUnit, 7, 0);
    if (!pMerc)
    {
        return 0;
    }

    if (SUNIT_IsDead(pMerc))
    {
        return 0;
    }

    if (!UNITFINDS_AreUnitsInNeighboredRooms(pMerc, pUnit))
    {
        return 0;
    }

    if (!pUnit->pInventory)
    {
        return 3;
    }

    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pUnit->pInventory);
    if (!pItem)
    {
        if (nBodyLoc <= 0)
        {
            return 0;
        }
        return PLRMSG_TakeMercItemToCursor(pGame, pMerc, pUnit, nBodyLoc);
    }

    if (ITEMS_IsQuestItem(pItem))
    {
        return 0;
    }

    PLRMSG_TryEquipMercItem(pGame, pUnit, pMerc, pItem);
    return 0;
}

// 0x0054D520
int __fastcall D2GAME_PACKETCALLBACK_Rcv0x63_ShiftLeftClickItemToBelt(D2GameStrc* ptGame, D2UnitStrc* pUnit, void* pPacket, int nSize)
{
    const D2GSPacketClt63* pPacket63 = (const D2GSPacketClt63*)pPacket;
    if (nSize != 5)
    {
        return 3;
    }

    const int nItemGUID = pPacket63->dwItemGUID;

    const int nResult = ((D2GameItemChecks*)ptGame)->PLRMSG_CheckStoredItem(pUnit, nItemGUID);
    if (nResult)
    {
        return nResult;
    }

    if (INVENTORY_GetCursorItem(pUnit->pInventory))
    {
        PLRMSG_SendCantDoThat(pUnit);
        return 2;
    }

    D2UnitStrc* hItem = SUNIT_GetServerUnit(ptGame, 4, nItemGUID);
    if (!hItem)
    {
        return 2;
    }

    if (!ITEMS_CheckIfBeltable(hItem))
    {
        return 2;
    }

    if (ITEMS_GetInvPage(hItem))
    {
        return 3;
    }

    unsigned char nPage;
    int nFreeSlotId = 0;
    if (INVENTORY_GetFreeBeltSlot(pUnit->pInventory, hItem, &nFreeSlotId) && nFreeSlotId >= 0 && PLAYER_CanModifyInventory(ptGame, pUnit, hItem))
    {
        D2InventoryStrc* hInventory = pUnit->pInventory;
        D2_ASSERT(hInventory, 0x1821);

        if (ITEMS_GetInvPage(hItem) || hItem->dwAnimMode != IMODE_STORED)
        {
            return 2;
        }

        D2UnitStrc* hRemove = INVENTORY_RemoveItemFromInventory(hInventory, hItem);
        D2_ASSERT(hRemove, 0x182A);
        D2_ASSERT(hItem == hRemove, 0x182B);

        nPage = ITEMS_GetInvPage(hItem);
        const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, ptGame->bExpansion);
        INVENTORY_Return(".\\PLAYER\\PlrMsg.cpp", 0x1830, hInventory, CLIENTS_GetUnitX(hItem), CLIENTS_GetUnitY(hItem), nInventoryRecordId, 0, nPage);
        ITEMS_SetItemCell(hItem, nPage);
        ITEMS_SetInvPage(hItem, 0xFF);

        D2GAME_UpdateClientItem(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1834), pUnit, hItem, 0);

        UNITS_ChangeAnimMode(hItem, 4);

        hItem->dwFlags &= ~2u;

        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(hItem, &nWidth, &nHeight, ".\\PLAYER\\PlrMsg.cpp", 0x183B);

        if (INVENTORY_PlaceItemInBeltSlot(hInventory, hItem, nFreeSlotId))
        {
            ITEMS_SetInvPage(hItem, 0xFF);

            if (INVENTORY_PlaceItemInSocket(hInventory, hItem, 2))
            {
                UNITS_ChangeAnimMode(hItem, 2);
                D2GAME_SendP0x9C_ItemAction_PutInBelt(UnitGetClient(pUnit, ".\\PLAYER\\PlrMsg.cpp", 0x1842), pUnit, hItem, 0);
            }
        }

        UNITS_RefreshInventory(pUnit, 1);
    }

    return 0;
}

// 0x0054D740
int __stdcall D2GAME_PACKETCALLBACK_Rcv0x66_Ignored(int nUnused1, int nUnused2)
{
    return 0;
}

// 0x0054D750
int __fastcall D2GAME_PACKET_Handler(D2GameStrc* pGame,D2UnitStrc* pUnit,unsigned char* pPacket,int nSize)
{
    unsigned char nHeader = *pPacket;
    if (!nHeader || nHeader >= 103) return 3;
    if (!sgcptIncomingMessageChart[nHeader].pfCallback) return 3;
    int bIgnore;
    switch (nHeader)
    {
    case 20: case 21: case 60: case 67: case 102:
        bIgnore = 0;
        break;
    case 32: case 38:
        bIgnore = !PLRMODE_CanInterruptCurrentMode(pGame,pUnit,1,0,0);
        break;
    case 65:
        bIgnore = 1;
        if (pUnit && pUnit->dwAnimMode == 17) bIgnore = 0;
        break;
    default:
        bIgnore = !PLRMODE_CanInterruptCurrentMode(pGame,pUnit,1,0,0);
        break;
    }
    if (!bIgnore)
    {
        if (pGame->nSyncTimer > 1) pGame->nSyncTimer = SYSTEM_GetSyncTime();
        if (IsBadCodePtr((void*)sgcptIncomingMessageChart[nHeader].pfCallback))
        {
            FOG_DisplayHalt("",sub_00408090(),6564);
            exit(-1);
        }
        return sgcptIncomingMessageChart[nHeader].pfCallback(pGame,pUnit,pPacket,nSize);
    }
    return 0;
}

// 0x0054D8A0
void __fastcall D2GAME_PLRMSG_Last(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender)
{
    const bool bDefenderIsPlayer = pDefender && pDefender->dwUnitType == UNIT_PLAYER;
    D2_ASSERT(bDefenderIsPlayer, 0x19B4);

    if (pAttacker && pAttacker->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER)
        {
            pAttacker = pOwner;
        }
    }

    D2GSPacketSrv5A packet5A = {};
    packet5A.nHeader = 0x5A;
    packet5A.nType = 6;
    packet5A.nColor = 4;
    const int nClassId = !pAttacker ? -1 : pAttacker->dwClassId;
    packet5A.dwParam = nClassId;
    packet5A.nParam = UNITS_GetUnitTypeOrInvalid(pAttacker);
    packet5A.szText[16] = 0;

    const char* szDefenderName = CLIENTS_GetName(UnitGetClient(pDefender, ".\\PLAYER\\PlrMsg.cpp", 0x19C9));
    if (SStrLen(szDefenderName))
    {
        SStrCopy(packet5A.szText, szDefenderName, 16);
    }
    else
    {
        packet5A.szText[0] = 0;
    }

    switch (UNITS_GetUnitTypeOrInvalid(pAttacker))
    {
    case 0:
    {
        char szName[16];
        SStrCopy(szName, CLIENTS_GetName(UnitGetClient(pAttacker, ".\\PLAYER\\PlrMsg.cpp", 0x19DB)), 16);
        if (SStrLen(szName))
        {
            SStrCopy(&packet5A.szText[16], szName, 16);
        }
        break;
    }
    case 1:
        if (MONSTERUNIQUE_CheckMonTypeFlag(pAttacker, 2))
        {
            *(unsigned short*)&packet5A.szText[16] = MONSTERUNIQUE_GetBossHcIdx(pAttacker);
        }
        break;
    }

    PLRMSG_BroadcastEventMessage(pGame, &packet5A);
}

// 0x0054DA10
void __fastcall PLRMSG_SendDeathMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode)
{
    PLRMSG_SendGetHitMode(pGame, pUnit, pClient, nAnimMode);

    if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0))
    {
        const int nValue = STATLIST_UnitGetStatValue(pUnit, STAT_GOLDLOST, 0);
        D2GAME_UpdateAttribute(pUnit, STAT_GOLDLOST, nValue, pUnit);
    }
}

extern "C" void __cdecl D2GAME_PACKETCALLBACK_Rcv0x61_DropPickupMercItem_0054D430(); // 0x0054D430
extern "C" void __cdecl sub_005497E0(); // 0x005497E0
extern "C" void __cdecl sub_00549890(); // 0x00549890
extern "C" void __cdecl sub_005498D0(); // 0x005498D0
extern "C" void __cdecl sub_00549920(); // 0x00549920
extern "C" void __cdecl sub_00549D00(); // 0x00549D00
extern "C" void __cdecl sub_00549D80(); // 0x00549D80
extern "C" void __cdecl sub_00549E00(); // 0x00549E00
extern "C" void __cdecl sub_00549E80(); // 0x00549E80
extern "C" void __cdecl sub_00549EE0(); // 0x00549EE0
extern "C" void __cdecl sub_00549F40(); // 0x00549F40
extern "C" void __cdecl sub_00549FC0(); // 0x00549FC0
extern "C" void __cdecl sub_0054A040(); // 0x0054A040
extern "C" void __cdecl sub_0054A0C0(); // 0x0054A0C0
extern "C" void __cdecl sub_0054A140(); // 0x0054A140
extern "C" void __cdecl sub_0054A1A0(); // 0x0054A1A0
extern "C" void __cdecl sub_0054A200(); // 0x0054A200
extern "C" void __cdecl sub_0054A260(); // 0x0054A260
extern "C" void __cdecl sub_0054A290(); // 0x0054A290
extern "C" void __cdecl sub_0054AAD0(); // 0x0054AAD0
extern "C" void __cdecl sub_0054AB40(); // 0x0054AB40
extern "C" void __cdecl sub_0054ABB0(); // 0x0054ABB0
extern "C" void __cdecl sub_0054ACD0(); // 0x0054ACD0
extern "C" void __cdecl sub_0054AD90(); // 0x0054AD90
extern "C" void __cdecl sub_0054AE30(); // 0x0054AE30
extern "C" void __cdecl sub_0054AEC0(); // 0x0054AEC0
extern "C" void __cdecl sub_0054AF50(); // 0x0054AF50
extern "C" void __cdecl sub_0054B0F0(); // 0x0054B0F0
extern "C" void __cdecl sub_0054B1E0(); // 0x0054B1E0
extern "C" void __cdecl sub_0054B280(); // 0x0054B280
extern "C" void __cdecl sub_0054B300(); // 0x0054B300
extern "C" void __cdecl sub_0054B380(); // 0x0054B380
extern "C" void __cdecl sub_0054B3E0(); // 0x0054B3E0
extern "C" void __cdecl sub_0054B450(); // 0x0054B450
extern "C" void __cdecl sub_0054B4E0(); // 0x0054B4E0
extern "C" void __cdecl sub_0054B560(); // 0x0054B560
extern "C" void __cdecl sub_0054B650(); // 0x0054B650
extern "C" void __cdecl sub_0054B710(); // 0x0054B710
extern "C" void __cdecl sub_0054B790(); // 0x0054B790
extern "C" void __cdecl sub_0054B810(); // 0x0054B810
extern "C" void __cdecl sub_0054B930(); // 0x0054B930
extern "C" void __cdecl sub_0054B9F0(); // 0x0054B9F0
extern "C" void __cdecl sub_0054BA90(); // 0x0054BA90
extern "C" void __cdecl sub_0054BB20(); // 0x0054BB20
extern "C" void __cdecl sub_0054BB60(); // 0x0054BB60
extern "C" void __cdecl sub_0054BC30(); // 0x0054BC30
extern "C" void __cdecl sub_0054BCA0(); // 0x0054BCA0
extern "C" void __cdecl sub_0054BD00(); // 0x0054BD00
extern "C" void __cdecl sub_0054BD10(); // 0x0054BD10
extern "C" void __cdecl sub_0054BD90(); // 0x0054BD90
extern "C" void __cdecl sub_0054BE70(); // 0x0054BE70
extern "C" void __cdecl sub_0054BF10(); // 0x0054BF10
extern "C" void __cdecl sub_0054BF60(); // 0x0054BF60
extern "C" void __cdecl sub_0054C0C0(); // 0x0054C0C0
extern "C" void __cdecl sub_0054C0E0(); // 0x0054C0E0
extern "C" void __cdecl sub_0054C2A0(); // 0x0054C2A0
extern "C" void __cdecl sub_0054C300(); // 0x0054C300
extern "C" void __cdecl sub_0054C380(); // 0x0054C380
extern "C" void __cdecl sub_0054C4B0(); // 0x0054C4B0
extern "C" void __cdecl sub_0054C520(); // 0x0054C520
extern "C" void __cdecl sub_0054C5D0(); // 0x0054C5D0
extern "C" void __cdecl sub_0054C6D0(); // 0x0054C6D0
extern "C" void __cdecl sub_0054C760(); // 0x0054C760
extern "C" void __cdecl sub_0054C7C0(); // 0x0054C7C0
extern "C" void __cdecl sub_0054C800(); // 0x0054C800
extern "C" void __cdecl sub_0054C870(); // 0x0054C870
extern "C" void __cdecl sub_0054C940(); // 0x0054C940
extern "C" void __cdecl sub_0054C9C0(); // 0x0054C9C0
extern "C" void __cdecl sub_0054CA10(); // 0x0054CA10
extern "C" void __cdecl sub_0054CD50(); // 0x0054CD50
extern "C" void __cdecl sub_0054CE70(); // 0x0054CE70
extern "C" void __cdecl sub_0054D520(); // 0x0054D520

extern "C" const D2PacketTableStrc gData_006E0D18[103]; // 0x006E0D18

extern D2UnkPlrMsgStrc gaUnitModeMessages[20] = {
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendDeathMode, 8, 8 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendNeutralMode, 7, 7 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendWalkMode, 1 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendWalkMode, 23, 24 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendGetHitMode, 6, 6 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendNeutralMode, 7, 7 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendWalkMode, 1 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendGetHitMode, 18, 18 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendGetHitMode, 9, 9 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendSkillMode, 21, 22 },
    { (void (__fastcall *)(D2GameStrc *, D2UnitStrc *, D2ClientStrc *, int))&PLRMSG_SendKnockbackMode, 20, 20 }
}; // 0x007319E8

extern int gnBaseStatIdsToSend[6] = { 67, 68, 12, 0, 2, -1 }; // 0x00731AD8

extern const D2WarpDelayStrc gaWarpDelays[3] = {
    { 50, 1500 },
    { 25, 3000 },
    { 25, 4500 }
}; // 0x006E1064

extern "C" const D2PacketTableStrc gData_006E0D18[103] = {
    { 0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_005497E0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549890 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_005498D0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549920 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549D00 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549D80 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549E00 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549E80 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549EE0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549F40 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x0B },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_00549FC0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054A040 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054A0C0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054A140 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054A1A0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054A200 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054A260 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x13_InteractWithEntity, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054A290 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x15_HandleChatMessage },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054AAD0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054AB40, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054ABB0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054ACD0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054AD90, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054AE30, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054AEC0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054AF50, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x1E_SwapTwo1HandedWithOne2HandedItem, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B0F0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B1E0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B300, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B380, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B3E0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B450, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B4E0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B560, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B280, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B650, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B710, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B790, 1 },
    { 0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B810 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x2D_Rejected },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x2E_Ignored, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B930, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054B9F0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BA90 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x32_BuyItemFromNpcBuffer, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BB20, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x34_IdentifyItemsWithNpc, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BB60, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x36_HireMerc, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BC30, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BCA0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BD00 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BD10 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BD90 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BE70 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BF10, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054BF60 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x3F_PlayAudio },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C0C0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C0E0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x42_Ignored, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x43_Ignored, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C380, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x45_ChangeTpLocation, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C4B0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C520 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x48_TurnOffBusyState, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C5D0 },
    { 0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C6D0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C760, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x4D_PlayNpcMessage },
    { 0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C7C0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C800, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C870 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x52_Rejected, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C940 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x54_TurnStaminaOff },
    { 0, 1 },
    { 0, 1 },
    { 0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C9C0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054CA10 },
    { 0, 1 },
    { 0, 1 },
    { 0, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C2A0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054C300 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054CD50 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054CE70, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x61_DropPickupMercItem_0054D430, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x62_ResurrectMerc, 1 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&sub_0054D520, 1 },
    { 0 },
    { 0 },
    { (int (__fastcall *)(D2GameStrc *, D2UnitStrc *, unsigned char*, int))&D2GAME_PACKETCALLBACK_Rcv0x66_Ignored }
}; // 0x006E0D18
#pragma comment(linker, "/alternatename:?sgcptIncomingMessageChart@@3PAUD2PacketTableStrc@@A=_gData_006E0D18")
