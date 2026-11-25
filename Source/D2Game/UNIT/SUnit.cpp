#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Structs.h"
#include "D2ItemsWorld.h"
#include "D2GameStrc.h"
#include "D2Path.h"
#include "D2GameObjs.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2AnimData.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2ItemModes.h"

#include "D2TxtTables.h"
#include "D2GameServer.h"
#include "D2GameTypes.h"
#include "D2LanguageNames.h"
#include "D2ItemDataTbl.h"
// build: symbol _gaszLanguageNames 0x00731ED4
struct D2MapAIStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define NUM_UNIT_TYPES 6

#define UNITFLAGEX_STORELASTATTACKER 0x20000

#define UNITFLAG_HASEVENTSOUND 0x400

#define EVENTTYPE_MODECHANGE 0

#define EVENTTYPE_ENDANIM 1

#define COLLISION_PATTERN_SMALL_NO_PRESENCE 5

#define COLLIDE_CORPSE 0x8000

#define UNITFLAGEX_HASBEENDELETED 0x100

#define SKILLSFLAGINDEX_TARGETPET 25

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_GOOD 2

#define UNIT_NUM_ALIGNMENT 3

#define STAT_ALIGNMENT 172

#define EVENTTYPE_REMOVESKILLCOOLDOWN 14

struct D2MonsterRegionStrc;

struct D2QuestChainStrc;

struct D2ItemsTxt;

union D2SeedStrc;

struct D2PlayerDataStrc;


struct D2ItemDataStrc;

struct D2StaticPathStrc;

struct D2ObjectDataStrc;

struct D2DrlgCoordsStrc;

struct Pad40_00553970;

struct Obj00553970;

struct Obj00554100;

struct Obj00554190;

struct D2SkillsTxt;

struct Obj00554650;

struct D2MonsterDataStrc;

struct D2MonStatsTxt;


struct D2PresetUnitStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall SUNIT_ValidateTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553490

void __fastcall SUNITDMG_FreeAttackerCombatList(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0057C980

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __stdcall ITEMS_InitItemSeed(D2UnitStrc* pItem); // 0x00627DC0

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc* pItem); // 0x00627D90

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

D2UnitStrc* __stdcall sub_K11_EmitUse(D2UnitStrc** ppList);

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __stdcall PATH_GetTargetTypeAndGUID(D2DynamicPathStrc* pPath, int* pUnitType, int* pUnitGUID); // 0x00648BB0

typedef int (__fastcall* SUNIT_ITERATEFN)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __stdcall PATH_AllocDynamicPath(void* pMemPool, D2ActiveRoomStrc* pRoom, int nX, int nY, D2UnitStrc* pUnit, int bSetFlag); // 0x00649D00

void __fastcall PLAYER_InitializePosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x00534AD0

int __fastcall MONSTER_SetVelocityAndPosition(D2GameStrc* pGame, D2UnitStrc* pMonster, int nX, int nY, int a5); // 0x005735A0

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

void __stdcall UNITS_BlockCollisionPath(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00620A70

int __stdcall UNITROOM_AddUnitToRoomEx(D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nUnused); // 0x0064C2C0

void __fastcall SUNIT_AddToUnitList(D2UnitStrc* pUnit, D2GameStrc* pGame); // 0x00553060

void __stdcall UNITS_SetCurrentRoomInvalid(D2UnitStrc* pUnit, int a2); // 0x00620FA0

void __stdcall PATH_FreeDynamicPath(void* pMemPool, D2DynamicPathStrc* pDynamicPath); // 0x00648460

int __stdcall PATH_RemoveCollisionFootprintForUnit(D2UnitStrc* pUnit, int bForce); // 0x00649560

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

int __fastcall ITEMS_GetGroundRemovalTime(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00558A10

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

struct Pad40_00553970 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Obj00553970 {
    Pad40_00553970 tPad000;
    Pad40_00553970 tPad040;
    Pad40_00553970 tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwUnknownC4;
    unsigned int dwUnknownC8;
    unsigned int dwUnknownCC;
    unsigned int dwUnknownD0;
    unsigned int dwUnknownD4;
    unsigned int dwUnknownD8;
    unsigned int dwValueDC;
};

unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* ptGame, D2UnitStrc* pUnit); // 0x00540710

struct Obj00554100 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    int nValue64;
    int nValue68;
    unsigned char nValue6C;
};

struct Obj00554190 {
    unsigned int dwUnknown00;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    unsigned int dwUnknown14;
    unsigned int dwUnknown18;
    unsigned int dwUnknown1C;
    unsigned int dwUnknown20;
    unsigned int dwUnknown24;
    unsigned int dwUnknown28;
    unsigned int dwUnknown2C;
    unsigned int dwUnknown30;
    unsigned int dwUnknown34;
    unsigned int dwUnknown38;
    unsigned int dwUnknown3C;
    unsigned int dwUnknown40;
    unsigned int dwUnknown44;
    unsigned int dwUnknown48;
    unsigned int dwUnknown4C;
    unsigned int dwUnknown50;
    unsigned int dwUnknown54;
    unsigned int dwUnknown58;
    unsigned int dwUnknown5C;
    unsigned int dwUnknown60;
    int nValue64;
    int nValue68;
    unsigned char nValue6C;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090

void __fastcall MONSTERREGION_UpdateSpawnCountForAlignmentChange(D2MonsterRegionStrc** pMonReg, D2UnitStrc* pUnit, int nAlignment, int nAlignNew); // 0x00547DD0

void __stdcall DUNGEON_IncreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619EE0

void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619F20

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

typedef int (__fastcall* EventTimerCallback)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int a4, int a5);

void __fastcall EVENT_DeleteTimersByCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, EventTimerCallback pCallback); // 0x00540EA0

struct Obj00554650 { unsigned char bUnknown00[0x60]; unsigned int dwFlags60; };

D2ActiveRoomStrc* __fastcall SUNIT_GetValidNextRoom(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005545C0

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

void __fastcall SUNITMSG_SendUnitToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571F90

void __fastcall SUNITMSG_SendRemoveObject(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600

void __stdcall PATH_SetCurrentRoomInvalid(D2DynamicPathStrc* pPath, int bValue); // 0x00648B40


void __fastcall SUNIT_SynchronizeRoomClients(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670

int __stdcall D2Common_10226(D2UnitStrc* pUnit, int nFlag); // 0x00650840

void __fastcall SUNIT_DetachUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int bKeepInRoom); // 0x00555580

void __fastcall QUESTS_FreeChainRecord(D2GameStrc* pGame, D2QuestChainStrc* pChain); // 0x00543590

void __fastcall D2GAME_FreeUnitNode_6FC40310(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B1A20

void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x00535430

void __fastcall PARTY_LeaveParty(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005407A0

void __fastcall PLAYER_Destroy(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005349D0

void __fastcall MONSTER_Free(D2GameStrc* pGame, D2UnitStrc* pMonster); // 0x005736A0

void __fastcall OBJECTS_FreeHoverMessage(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00552A00

void __stdcall UNITS_FreeStaticPath(D2UnitStrc* pUnit); // 0x00623570

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

void __fastcall MISSILES_Free(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x0059F8E0

void __fastcall ITEMS_FreeSocketInventoryAndTimers(D2GameStrc* pGame, D2UnitStrc* pItem); // 0x00557EE0

void __stdcall ITEMS_FreeItemData(void* pMemPool, D2UnitStrc* pItem); // 0x00627D00

void __fastcall SUNITEVENT_FreeEventList(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005C0A90

void __fastcall D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(D2UnitStrc* pUnit); // 0x00571F40

void __stdcall UNITS_FreeUnit(D2UnitStrc* pUnit); // 0x00620300

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall QUESTS_MapPresetSpawn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAI); // 0x00545C90

D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags); // 0x005557D0

D2MapAIStrc* __stdcall AIGENERAL_GetMapAiFromUnit(D2UnitStrc* pUnit); // 0x0058F000

D2MapAIStrc* __fastcall DRLGPRESET_ChangeMapAI(D2MapAIStrc** ppMapAI1, D2MapAIStrc* pMapAI2); // 0x00666120

void __fastcall D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(D2GameStrc* pGame, D2UnitStrc* pItem, D2UnitStrc* pTarget, int bUpdateStatList, int bUpdateVitals); // 0x0055C730

int __stdcall UNITS_GetInventoryRecordId(D2UnitStrc* pUnit, unsigned char nInvPage, int bLoD); // 0x00621050

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

int __stdcall ITEMS_IsCharmUsable(D2UnitStrc* pItem, D2UnitStrc* pPlayer); // 0x0062FF70

D2UnitStrc* __stdcall INVENTORY_RemoveItemFromInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD90

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

void __stdcall sub_0063BE30(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BE30

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

// build: base-profile

struct D2GameStrc;

extern const int gnUnitListOffsets[6]; // 0x006E10E0

#define UNIT_TILE 5

#define D2_MAYBE_UNUSED(x) (void)(x)

struct D2LvlWarpTxt;

D2UnitStrc* __stdcall DUNGEON_GetWarpTileFromRoomAndSourceLevelId(D2ActiveRoomStrc*,int,D2LvlWarpTxt**); // 0x006195A0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc*); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc*,D2CoordStrc*,int,unsigned int,int); // 0x0064E7B0

int __fastcall QUESTS_LevelWarpCheck(D2GameStrc*,D2UnitStrc*,int,int); // 0x00545B80

int __fastcall SUNIT_TeleportUnit(D2GameStrc*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc*,const char*,int); // 0x005531C0

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc*,D2UnitStrc*,D2SkillStrc*,int,int,int,int); // 0x005809D0

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc*); // 0x00621F20

void __fastcall D2GAME_PACKETS_SendPacket0x0D_6FC3C920(D2ClientStrc*,unsigned char,unsigned char,int,unsigned char,unsigned short,unsigned short,unsigned char,unsigned char); // 0x0053B4B0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

D2UnitStrc* __fastcall OBJECTS_SpawnPresetObject(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054F490

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

int __fastcall D2GAME_InitItemStats_6FC4E520(D2GameStrc* pGame, D2UnitStrc** ppItem, D2ItemDropStrc* pItemDrop, int a4); // 0x00557AB0

struct D2DynamicPathStrc;

struct D2ActiveRoomStrc;

struct D2ObjectsTxt;

struct D2DrlgActStrc;

enum D2C_M192SUnitAlloc
{
    MONSTATSFLAGINDEX_ENABLED = 25,
    MONSTATS2FLAGINDEX_DEADCOL = 0x13,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_INITSEEDSET = 0x00000010,
    UNITFLAGEX_ISEXPANSION = 0x02000000,
    UNITFLAGEX_SERVERUNIT = 0x04000000,
};

#pragma function(memset)

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

void __fastcall PLAYER_Create(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPlayerGUID);                     // 0x005348C0

void __fastcall OBJECTS_InitHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitGUID, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x0054F5D0

void __fastcall SUNIT_InitSeed(D2UnitStrc* ptUnit, D2SeedStrc* pSeed); // 0x00552DF0

void __fastcall SUNIT_InitItemSeeds(D2UnitStrc* pItem, D2SeedStrc* pGameSeed); // 0x00552E90

int __fastcall SUNIT_GetNewUnitGUID(D2GameStrc* pGame, int nUnitType);                             // 0x00552EE0

void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int bSkipRoomUpdate); // 0x00554850

void __fastcall ITEMMODE_InitializeItemUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int nUnitGUID, D2ActiveRoomStrc* pRoom);  // 0x00555D20

void __fastcall MONSTER_Initialize(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pUnit, int nUnitGUID); // 0x00574250

void __fastcall MISSILES_Initialize(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnitGUID);                 // 0x0059F8A0

void __fastcall TARGETS_AllocPlayerNode(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                 // 0x005B1880

D2UnitStrc* __stdcall UNITS_AllocUnit(void* pMemPool, int nUnitType);                                       // 0x00620290

void __stdcall UNITS_AllocStaticPath(D2UnitStrc* pUnit);                                                    // 0x00623520

void __stdcall ITEMS_AllocItemData(void* pMemPool, D2UnitStrc* pItem);                                      // 0x00627C90

extern "C" void __stdcall PATH_SetUnitCollisionPattern(D2UnitStrc* pUnit, int nCollisionPattern);           // 0x00649190

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

// build: symbol ??__EgnUnitInitSeed_008846E8@@YAXXZ 0x006CAF60
// build: symbol ?gnUnitInitSeed_008846E8@@3HA 0x008846E8
int gnUnitInitSeed_008846E8 = GetTickCount(); // 0x008846E8

struct D2UnitStrc;

#define ITEMQUAL_UNIQUE 7

#define SKILLSFLAGINDEX_TARGETALLY 26

struct D2AnimDataRecordStrc;


void __fastcall MONSTERAI_RemoveInteractInfoFor(D2GameStrc* pGame, D2UnitStrc* pMonster, D2MonsterInteractStrc* pMonInteract); // 0x00572E00

void __fastcall SUNITPROXY_FreeVendorChain(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNpc); // 0x00536B50

void __fastcall OBJMODE_ResetObjectInteraction(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x00585550

void __stdcall D2Common_10228(D2UnitStrc* pUnit); // 0x00649F50

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370


extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

void __stdcall UNITS_InitializeSequence(D2UnitStrc* pUnit); // 0x00621260

void __stdcall UNITS_SetAnimData(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nAnimMode); // 0x00620F00

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

void __fastcall D2GAME_PACKETS_SendPacket0x07_6FC3D120(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50

void __fastcall EVENT_SetEventWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, EventTimerCallback pCallback, int nCustomId, int nCustomParam); // 0x00541800

int __fastcall SUNIT_EventClearTeleportCoordinates(D2GameStrc* pGame, D2UnitStrc* pPlayer, int a3, int a4, int a5); // 0x00554570

int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

enum D2C_M108SUnitConstants
{
    OBJECT_GOLD_PLACEHOLDER = 26,
    OBJECT_WIRTSBODY = 268,
    OBJECT_CAINGIBBET = 269,
    OBJECT_SPARKLY_CHEST = 397,
    OBJECT_VALLEY_WAYPOINT = 402,
};

D2PresetUnitStrc* __stdcall DUNGEON_GetPresetUnitsFromRoom(D2ActiveRoomStrc* pRoom); // 0x00619FD0

void __fastcall SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit); // 0x00555910

#define UNITFLAG_DOUPDATE           0x00000001

#define UNITFLAG_INITSEEDSET        0x00000010

#define UNITFLAG_HASTXTMSG          0x00000100

#define UNITFLAG_SUMMONER           0x00000800

#define UNITFLAGEX_TELEPORTED       0x00010000

struct D2AnimFrameTableStrc;

void __stdcall STATLIST_FreeModStats(D2UnitStrc* pUnit); // 0x00625960

void __stdcall STATES_ClearGfxStateFlags(D2UnitStrc* pUnit); // 0x00639EE0

void __fastcall D2GAME_INVMODE_Last_6FC416D0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597B00

void __stdcall STATLIST_RemoveAllStatsFromOverlay(D2UnitStrc* pUnit); // 0x00627410

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __fastcall ARENA_ClearUnitUpdateScore(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0053FA90

void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int bSet, int bUpdate); // 0x00573570

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0

D2ActiveRoomStrc* __stdcall DUNGEON_StreamRoomAtCoords(D2DrlgActStrc* pAct, int nX, int nY); // 0x0061A140

void __fastcall GAME_ActivateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0052D0F0

struct D2AnimFrameTableStrc
{
    char unk0x00[0x10];
    unsigned char pFrameFlags[144];
};

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);

D2ActiveRoomStrc* __stdcall PATH_GetNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AA0

void __stdcall PATH_ClearNextRoom(D2DynamicPathStrc* pDynamicPath); // 0x00648AB0

struct Data00552D60 { unsigned char bUnknown00[0x50]; unsigned int dwValue50; };

struct Unit00552D60 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data00552D60* pData;
};

// 0x00552D60
extern "C" __declspec(dllexport) void __fastcall SUNIT_SetMonsterVision(Unit00552D60* pUnit, unsigned int dwValue) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        pUnit->pData->dwValue50 = dwValue;
    }
}

// 0x00552D80
void __fastcall SUNIT_SetListNext(D2UnitStrc* pUnit, D2UnitStrc* pNext)
{
    D2_ASSERT(pUnit, 211);
    pUnit->pListNext = pNext;
}

// 0x00552DB0
D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 222);

    return ptUnit->pListNext;
}

// 0x00552DE0
static inline void SUNIT_AssignUnitId(D2UnitStrc* pUnit, int nValue)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 2;
        pUnit->dwUnitId = nValue;
    }
}

void __stdcall sub_M127_EmitSink(D2UnitStrc* pUnit);

void __fastcall sub_M127_Emit_00552DE0(D2UnitStrc* pUnit, int nValue)
{
    SUNIT_AssignUnitId(pUnit, nValue);
    sub_M127_EmitSink(pUnit);
}

inline unsigned __int64 ITEMS_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x00552DF0
void __fastcall SUNIT_InitSeed(D2UnitStrc* ptUnit, D2SeedStrc* pSeed)
{
    D2_ASSERT(ptUnit, 415);

    SEED_InitSeed(&ptUnit->pSeed);

    if (pSeed)
    {
        ptUnit->dwInitSeed = (unsigned int)ITEMS_RollRandomNumberInline(pSeed);
    }
    else
    {
        ptUnit->dwInitSeed = SEED_GetRandomValue(2 * gnUnitInitSeed_008846E8++);
    }

    SEED_InitLowSeed(&ptUnit->pSeed, ptUnit->dwInitSeed);
}

// 0x00552E90
void __fastcall SUNIT_InitItemSeeds(D2UnitStrc* pItem, D2SeedStrc* pGameSeed)
{
    ITEMS_InitItemSeed(pItem);
    ITEMS_SetItemStartSeed(pItem, (unsigned int)ITEMS_RollRandomNumberInline(pGameSeed));
    SEED_InitLowSeed(ITEMS_GetItemSeed(pItem), ITEMS_GetItemStartSeed(pItem));
}

// 0x00552EE0
int __fastcall SUNIT_GetNewUnitGUID(D2GameStrc* pGame, int nUnitType)
{
    D2_ASSERT(nUnitType < NUM_UNIT_TYPES, 452);

    int nUnitGUID = pGame->dwLastUsedUnitGUID[nUnitType] + 1;
    if (nUnitGUID == -1)
    {
        nUnitGUID = 1;
    }

    pGame->dwLastUsedUnitGUID[nUnitType] = nUnitGUID;
    return nUnitGUID;
}

// 0x00552F20
int __fastcall SUNIT_GetUnitListIndex(int nUnitGUID)
{
    return nUnitGUID & UNIT_LIST_MASK;
}

// 0x00552F30
static D2UnitStrc** __stdcall SUNIT_GetUnitList(D2GameStrc* pGame, int nUnitType, int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
    {
        return (D2UnitStrc**)((char*)pGame + gnUnitListOffsets[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }
    return 0;
}

D2UnitStrc* __fastcall sub_K11_Emit00552F30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    return sub_K11_EmitUse(SUNIT_GetUnitList(pGame, pUnit->dwUnitType, pUnit->dwUnitId));
}

// 0x00555770
void __fastcall SUNIT_RemoveAllTiles(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x12D);
    D2UnitStrc* pTile = pGame->pTileList;
    while (pTile)
    {
        D2UnitStrc* pCurrent = pTile;
        pTile = pTile->pListNext;
        SUNIT_RemoveUnit(pGame, pCurrent);
    }
    pGame->pTileList = 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x00552FD0
D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!UNIT_HasFlagEx(pUnit, UNITFLAGEX_STOREOWNERINFO))
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x00553010
D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 800);

    if (pUnit->dwFlagEx & UNITFLAGEX_STORELASTATTACKER)
    {
        return SUNIT_GetServerUnit(pGame, pUnit->dwKillerType, pUnit->dwKillerGUID);
    }

    return 0;
}

static inline D2UnitStrc** SUNIT_GetUnitList_Inline(D2GameStrc* pGame, int nUnitType, unsigned int nUnitGUID)
{
    if (nUnitType >= 0 && nUnitType <= 4)
        return (D2UnitStrc**)((char*)pGame + gnUnitListOffsets[nUnitType]) + (nUnitGUID & 0x7F);
    return 0;
}

// 0x00553160
static int SUNIT_RoomHasClients(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    return pRoom->nNumClients != 0;
}

// 0x005530F0
static void SUNIT_RemoveFromUnitList(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc** ppUnitList;
    if (pUnit->dwUnitType == UNIT_TILE)
    {
        ppUnitList = &pGame->pTileList;
    }
    else
    {
        ppUnitList = SUNIT_GetUnitList_Inline(pGame, pUnit->dwUnitType, pUnit->dwUnitId);
    }

    D2UnitStrc* pPrevious = 0;
    D2UnitStrc* i;
    for (i = *ppUnitList; i; i = i->pListNext)
    {
        if (i == pUnit)
        {
            break;
        }
        pPrevious = i;
    }

    if (i)
    {
        if (!pPrevious)
        {
            *ppUnitList = i->pListNext;
        }
        else
        {
            pPrevious->pListNext = i->pListNext;
        }
    }
}

// 0x00553060
void __fastcall SUNIT_AddToUnitList(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    D2UnitStrc** ppUnitList;
    if (pUnit->dwUnitType == UNIT_TILE)
        ppUnitList = (D2UnitStrc**)((char*)pGame + 0x1B20);
    else
        ppUnitList = SUNIT_GetUnitList_Inline(pGame, pUnit->dwUnitType, pUnit->dwUnitId);

    D2UnitStrc* i = *ppUnitList;
    D2UnitStrc* pPrevious = 0;
    while (i)
    {
        if (i->dwUnitId <= pUnit->dwUnitId)
        {
            if (i->dwUnitId == pUnit->dwUnitId)
            {
                char szMessage[256];
                D2_MAYBE_UNUSED(szMessage);
                FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x355);
                exit(-1);
            }
            break;
        }
        pPrevious = i;
        i = i->pListNext;
    }

    pUnit->pListNext = i;
    if (pPrevious)
        pPrevious->pListNext = pUnit;
    else
        *ppUnitList = pUnit;
}

// 0x00553180
void __fastcall SUNIT_InitClientInPlayerData(D2UnitStrc* hUnit, D2ClientStrc* pClient)
{
    D2_ASSERT(hUnit, 1210);
    D2_ASSERT(hUnit->dwUnitType == UNIT_PLAYER, 1211);

    UNITS_GetPlayerData(hUnit)->pClient = pClient;
}

// 0x005533D0
void __fastcall SUNIT_InitializeAnimation(D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0x561);

    ptUnit->nActionFrame = 0;

    int bPlayerSequence = 0;
    if (ptUnit->dwUnitType == UNIT_PLAYER && ptUnit->dwAnimMode == PLRMODE_SEQUENCE)
    {
        bPlayerSequence = 1;
    }

    if ((ptUnit->dwUnitType == UNIT_MONSTER && ptUnit->dwAnimMode == MONMODE_SEQUENCE || bPlayerSequence) && DATATBLS_GetMonSeqTxtRecordFromUnit(ptUnit))
    {
        UNITS_InitializeSequence(ptUnit);
        UnitUpdateAnimRateAndVel(ptUnit, ".\\UNIT\\SUnit.cpp", 0x570);
        return;
    }

    ptUnit->pAnimSeq = 0;
    ptUnit->nSeqCurrentFramePrecise = 0;
    if (ptUnit->pDynamicPath)
    {
        UnitUpdateAnimRateAndVel(ptUnit, ".\\UNIT\\SUnit.cpp", 0x578);
    }
    else
    {
        UNITS_SetAnimData(ptUnit, ptUnit->dwUnitType, ptUnit->dwClassId, ptUnit->dwAnimMode);
    }

    ptUnit->dwFrameCountPrecise = ptUnit->pAnimData->dwFrames << 8;
}

__forceinline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x00553220
void __fastcall SUNIT_ClearUpdateData(D2GameStrc* pGame, D2UnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 1304);

    STATLIST_FreeModStats(ptUnit);
    D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(ptUnit);
    ptUnit->dwFlags &= ~(UNITFLAG_DOUPDATE | UNITFLAG_INITSEEDSET);
    UNITS_SetCurrentRoomInvalid(ptUnit, 0);
    ptUnit->dwFlags &= ~(UNITFLAG_HASEVENTSOUND | UNITFLAG_UPGRLIFENHITCLASS);
    ptUnit->dwFlagEx &= 0xFFDEE7FF;
    STATES_ClearGfxStateFlags(ptUnit);
    D2GAME_INVMODE_Last_6FC416D0(pGame, ptUnit);

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(ptUnit))
    {
        STATLIST_RemoveAllStatsFromOverlay(ptUnit);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(ptUnit))
    {
        STATLIST_RemoveAllStatsFromOverlay(ptUnit);
    }

    switch (ptUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        STATLIST_SetUnitStat(ptUnit, STAT_LASTEXP, -1, 0);
        ptUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        ARENA_ClearUnitUpdateScore(pGame, ptUnit);
        return;

    case UNIT_OBJECT:
        ptUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        return;

    case UNIT_MONSTER:
        ptUnit->dwFlags &= ~UNITFLAG_HASTXTMSG;
        if (UNIT_HasFlag(ptUnit, UNITFLAG_SUMMONER))
        {
            ptUnit->dwFlags &= ~UNITFLAG_SUMMONER;
            MONSTER_ToggleSummonerFlag(ptUnit, 1, 0);
        }
        ptUnit->dwFlagEx &= ~UNITFLAGEX_TELEPORTED;
        return;

    case UNIT_MISSILE:
        return;

    case UNIT_ITEM:
        ptUnit->dwFlags &= ~UNITFLAG_SENDREFRESHMSG;
        break;
    }

    if (ptUnit->dwUnitType == UNIT_ITEM)
    {
        ITEMS_SetItemFlag(ptUnit, 0x20, 0);
        ITEMS_SetItemFlag(ptUnit, 0x2000, 0);
    }
}

// 0x00553380
void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit)
{
    D2_ASSERT(pUnit, 1367);

    pUnit->nUpdateType = nUpdateType;
    pUnit->pUpdateUnit = pUpdateUnit;
    UNITROOM_RefreshUnit(pUnit);
    pUnit->dwFlags |= UNITFLAG_HASEVENTSOUND;
}

static int SUNIT_GetUnitX_Inlined(D2UnitStrc* pUnit)
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

static int SUNIT_GetUnitY_Inlined(D2UnitStrc* pUnit)
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

// 0x005557D0
D2UnitStrc* __fastcall SUNIT_CreatePresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId, int nX, int nY, int nMode, int nUnitFlags)
{
    D2UnitStrc* pUnit = 0;

    switch (nUnitType)
    {
    case 2:
        if (nClassId > 573)
        {
            pUnit = OBJECTS_SpawnPresetObject(pGame, pRoom, nClassId, nX, nY, nMode);
            break;
        }
        if (nClassId == 573)
        {
            return 0;
        }

    default:
        pUnit = SUNIT_AllocUnitData(nUnitType, nClassId, nX, nY, pGame, pRoom, 1, nMode, 0);
        if (nUnitType == 4 && pUnit)
        {
            D2ItemDropStrc itemDrop;
            memset(&itemDrop, 0, sizeof(itemDrop));
            itemDrop.nQuality = 2;
            itemDrop.nItemLvl = DUNGEON_GetLevelIdFromRoom(pRoom);
            if (!D2GAME_InitItemStats_6FC4E520(pGame, &pUnit, &itemDrop, 1))
            {
                SUNIT_RemoveUnit(pGame, pUnit);
                return 0;
            }
        }
        if (pUnit)
        {
            pUnit->dwFlags |= 0x3000000;
        }
        return pUnit;

    case 1:
        pUnit = D2GAME_SpawnPresetMonster_6FC66560(pGame, pRoom, nClassId, nX, nY, nMode);
        break;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x3000000;
    }

    return pUnit;
}

// 0x00553490
void __fastcall SUNIT_ValidateTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 1792);
    D2_ASSERT(pGame, 1793);

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2_ASSERT(pPath, 1796);

    if (!PATH_GetTargetUnit(pPath))
    {
        return;
    }

    int nTargetType;
    int nTargetGUID;
    PATH_GetTargetTypeAndGUID(pPath, &nTargetType, &nTargetGUID);

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, nTargetType, nTargetGUID);
    if (pTarget != PATH_GetTargetUnit(pPath))
    {
        PATH_SetTargetUnit(pPath, 0);
    }

    if (!pTarget || pTarget->dwUnitType != UNIT_ITEM)
    {
        return;
    }

    const int nAnimMode = pTarget->dwAnimMode;
    if (nAnimMode == IMODE_INBELT || nAnimMode == IMODE_EQUIP)
    {
        PATH_SetTargetUnit(pPath, 0);
    }
}

// 0x00553540
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    SUNIT_ValidateTargetUnit(pGame, pUnit);
    D2UnitStrc* pTargetUnit = PATH_GetTargetUnit(pUnit->pDynamicPath);
    if (pTargetUnit != pUnit)
    {
        return pTargetUnit;
    }

    return 0;
}

// 0x00554CA0
int __fastcall SUNIT_UpdateUnitPath(D2GameStrc* ptGame, D2UnitStrc* pMissile)
{
    D2_ASSERT(ptGame, 1838);

    SUNIT_ValidateTargetUnit(ptGame, pMissile);
    const int v4 = D2Common_10226(pMissile, 1024) ? 1 : 2;
    if (UNITS_IsCurrentRoomInvalid(pMissile))
    {
        SUNIT_SynchronizeRoomClients(ptGame, pMissile, 0);
    }

    return v4;
}

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

// 0x00553570
void __fastcall SUNIT_SetCombatMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMode)
{
    SUNITDMG_FreeAttackerCombatList(pGame, pUnit);
    UNITS_ChangeAnimMode(pUnit, nMode);
}

// 0x00553590
void __fastcall SUNIT_LinkPortalCoordinates(D2UnitStrc* ptFirst, D2UnitStrc* ptSecond)
{
    D2_ASSERT(ptFirst, 1875);
    D2_ASSERT(ptSecond, 1877);

    ptFirst->pObjectData->DestPortalCoords.nX = CLIENTS_GetUnitX_Inline(ptSecond);
    ptFirst->pObjectData->DestPortalCoords.nY = CLIENTS_GetUnitY_Inline(ptSecond);

    ptSecond->pObjectData->DestPortalCoords.nX = CLIENTS_GetUnitX_Inline(ptFirst);
    ptSecond->pObjectData->DestPortalCoords.nY = CLIENTS_GetUnitY_Inline(ptFirst);

    D2ActiveRoomStrc* pSecondRoom = UNITS_GetRoom(ptSecond);
    if (pSecondRoom)
    {
        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pSecondRoom, &drlgCoords);
        ptFirst->pObjectData->DestRoomCooords.nX = drlgCoords.nTileXPos;
        ptFirst->pObjectData->DestRoomCooords.nY = drlgCoords.nTileYPos;
    }

    D2ActiveRoomStrc* pFirstRoom = UNITS_GetRoom(ptFirst);
    if (pFirstRoom)
    {
        D2DrlgCoordsStrc drlgCoords;
        DUNGEON_GetRoomCoordinates(pFirstRoom, &drlgCoords);
        ptSecond->pObjectData->DestRoomCooords.nX = drlgCoords.nTileXPos;
        ptSecond->pObjectData->DestRoomCooords.nY = drlgCoords.nTileYPos;
    }
}

struct D2W11RoomTileRecordStrc;

struct D2W11RoomTileOwnerStrc;

struct D2W11RoomTileRecordStrc
{
    char unk0x00[0x18];
    int nTileX;
    int nTileY;
    int nArg1;
    int nArg2;
};

struct D2W11RoomTileOwnerStrc
{
    char unk0x00[0x14];
    D2W11RoomTileRecordStrc* pRecord;
};

#define EVENTTYPE_AITHINK 2

#define DAMAGERESULTFLAG_WILLDIE 0x02

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

// 0x005536E0
void __fastcall SUNIT_StoreRoomTile(D2W11RoomTileOwnerStrc* pOwner, D2ActiveRoomStrc* pRoom, int nArg1, int nArg2)
{
    pOwner->pRecord->nArg1 = nArg1;
    pOwner->pRecord->nArg2 = nArg2;
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    pOwner->pRecord->nTileX = tCoords.nTileXPos;
    pOwner->pRecord->nTileY = tCoords.nTileYPos;
}

// 0x00553720
D2UnitStrc* __fastcall SUNIT_GetPortalOwner(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 1930); exit(-1); }
    const unsigned char nLevelId = pUnit->pObjectData->InteractType;
    const int nAct = DRLG_GetActNoFromLevelId(nLevelId);
    const int nX = pUnit->pObjectData->DestRoomCooords.nX;
    const int nY = pUnit->pObjectData->DestRoomCooords.nY;

    if (!DUNGEON_FindRoomBySubtileCoordinates(pGame->pAct[nAct], nX, nY))
    {
        D2ActiveRoomStrc* pRoom = DUNGEON_StreamRoomAtCoords(pGame->pAct[nAct], nX, nY);
        if (pRoom)
            GAME_ActivateRoom(pGame, pRoom);
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x005537D0
D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* ptGame, int nType, void* pArg, SUNIT_ITERATEFN pfIterate)
{
    D2_ASSERT(ptGame, 1970);
    D2_ASSERT(pfIterate, 1971);

    D2UnitStrc** ppUnitList;
    if (nType == UNIT_PLAYER)
    {
        ppUnitList = ptGame->pUnitList[0];
    }
    else if (nType == UNIT_MONSTER)
    {
        ppUnitList = ptGame->pUnitList[1];
    }
    else
    {
        return 0;
    }

    D2_ASSERT(!IsBadCodePtr((FARPROC)pfIterate), 1991);

    for (int i = 0; i < 128; ++i, ++ppUnitList)
    {
        for (D2UnitStrc* ptUnit = *ppUnitList; ptUnit; ptUnit = ptUnit->pListNext)
        {
            if (!STATES_CheckState(ptUnit, STATE_PLAYERBODY) && pfIterate(ptGame, ptUnit, pArg) == 1)
            {
                return ptUnit;
            }

            D2_ASSERT(ptUnit, 222);
        }
    }

    return 0;
}

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall sub_00538410_RemoveUnitIfNotAdjacent2(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x00538410

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

// 0x005538D0
void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* ptGame, SUNIT_IterateFn pfIterate, void* pArg)
{
    D2UnitStrc** ppSlot = ptGame->pUnitList[0];
    SUNIT_IterateFn pfCallback = pfIterate;
    D2_ASSERT(ptGame && pfCallback, 2022);

    for (int i = 0; i < 128; ++i, ++ppSlot)
    {
        for (D2UnitStrc* ptUnit = *ppSlot; ptUnit; ptUnit = ptUnit->pListNext)
        {
            if (!STATES_CheckState(ptUnit, STATE_PLAYERBODY))
            {
                pfCallback(ptGame, ptUnit, pArg);
            }

            D2_ASSERT(ptUnit, 222);
        }
    }
}

// 0x00553970
extern "C" __declspec(dllexport) void __fastcall SUNIT_SetTimerOnUnit(Obj00553970* pObj, unsigned int dwValue) {
    if (pObj) {
        pObj->dwValueDC = dwValue;
    }
}

// 0x00553980
D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return pUnit->pTimer;
}

// 0x00553990
void __fastcall D2GAME_DeletePlayerPerFrameEvents_6FCBCE50(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
}

// 0x005539B0
void __fastcall SUNIT_ScheduleAnimationEvents(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nFrame = pGame->dwGameFrame;
    const int nFrameBonus = UNITS_GetFrameBonus(pUnit) << 8;
    int nAnimFrame = nFrameBonus;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    D2AnimFrameTableStrc* pAnimData = (D2AnimFrameTableStrc*)pUnit->pAnimData;
    int nIndex = nFrameBonus >> 8;
    int nParam = 0;
    while (nAnimFrame + nAnimSpeed < nFrameCount)
    {
        ++nFrame;
        nAnimFrame += nAnimSpeed;
        for (int i = nAnimFrame >> 8; nIndex <= i; ++nIndex)
        {
            if (nIndex >= 144)
            {
                break;
            }

            D2AnimSeqTxt* pSequence = (D2AnimSeqTxt*)pUnit->pAnimSeq;
            int nEvent;
            if (pSequence)
            {
                DATATBLS_GetSequenceEvent(pSequence, nIndex << 8, &nEvent);
            }
            else
            {
                nEvent = pAnimData->pFrameFlags[nIndex];
            }

            if (nEvent)
            {
                switch (nEvent)
                {
                case 1:
                case 2:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, nParam);
                    ++nParam;
                    break;

                case 3:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }
            }
        }
    }

    if (nFrame == pGame->dwGameFrame)
    {
        ++nFrame;
    }

    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    pUnit->nSeqCurrentFramePrecise = pGame->dwGameFrame << 8;
}

// 0x00553B10
void __fastcall SUNIT_RewindAnimationByPercentage(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    const int nCalc = (100 - a3) * (nFrame - (pUnit->nSeqCurrentFramePrecise >> 8)) / 100;
    pUnit->nSeqCurrentFramePrecise = (nFrame - nCalc) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        D2AnimDataRecordStrc* pAnimData = (D2AnimDataRecordStrc*)pUnit->pAnimData;
        int nIndex = nCalc - 1;
        int nAnimFrame = nCalc << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

// 0x00553C70
void __fastcall SUNIT_RewindAnimationByFrames(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    if (a3 <= 0)
    {
        return;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    const int nCalc = nFrame - (pUnit->nSeqCurrentFramePrecise >> 8) - a3;
    pUnit->nSeqCurrentFramePrecise = (nFrame - nCalc) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        D2AnimDataRecordStrc* pAnimData = (D2AnimDataRecordStrc*)pUnit->pAnimData;
        int nIndex = nCalc - 1;
        int nAnimFrame = nCalc << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

// 0x00553DC0
void __fastcall D2GAME_SKILLS_RewindSkillEx_6FCBD260(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    int nFrame = pGame->dwGameFrame;
    pUnit->nSeqCurrentFramePrecise = (nFrame - a3) << 8;

    int nAnimSpeed;
    int nFrameCount;
    if (pUnit->pAnimSeq)
    {
        nAnimSpeed = pUnit->dwSeqSpeed;
        nFrameCount = pUnit->dwSeqFrameCount;
    }
    else
    {
        nAnimSpeed = pUnit->wAnimSpeed;
        nFrameCount = pUnit->dwFrameCountPrecise;
    }

    if (!nAnimSpeed)
    {
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, pGame->dwGameFrame + 1, 0, 0);
        return;
    }

    {
        D2AnimDataRecordStrc* pAnimData = (D2AnimDataRecordStrc*)pUnit->pAnimData;
        int nIndex = a3 - 1;
        int nAnimFrame = a3 << 8;
        while (nAnimFrame + nAnimSpeed < nFrameCount)
        {
            ++nFrame;
            nAnimFrame += nAnimSpeed;

            while (nIndex <= (nAnimFrame >> 8))
            {
                int nEvent;
                if (pUnit->pAnimSeq)
                {
                    DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nIndex << 8, &nEvent);
                }
                else
                {
                    nEvent = pAnimData->pFrameFlags[nIndex];
                }

                switch (nEvent)
                {
                case 1:
                case 2:
                case 3:
                case 4:
                    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, nFrame, nEvent, 0);
                    break;
                }

                ++nIndex;
            }
        }

        if (nFrame == pGame->dwGameFrame)
        {
            ++nFrame;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ENDANIM, nFrame + 1, 0, 0);
    }
}

// 0x00553F00
void __fastcall SUNIT_ResetRecurringModeChangeEvent(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
    sub_6FC35570(pGame, pUnit, EVENTTYPE_MODECHANGE, 0, 0);
}

// 0x00553F30
void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* ptInfo)
{
    D2_ASSERT(ptInfo, 0x9AA);
    D2_ASSERT(pUnit, 0x9AB);

    D2PlayerDataStrc* pPlayerData;
    if (pUnit->dwUnitType == UNIT_PLAYER && (pPlayerData = UNITS_GetPlayerData(pUnit)) != 0)
    {
        strcpy(ptInfo->szDescription, pPlayerData->szName);
    }
    else
    {
        ptInfo->szDescription[0] = 0;
    }

    ptInfo->nUnitType = pUnit->dwUnitType;
    ptInfo->nClassId = pUnit->dwClassId;
    ptInfo->nUnitGUID = pUnit->dwUnitId;
    ptInfo->nAnimMode = pUnit->dwAnimMode;
    ptInfo->nX = SUNIT_GetUnitX_Inlined(pUnit);
    ptInfo->nY = SUNIT_GetUnitY_Inlined(pUnit);
    ptInfo->nOwnerType = pUnit->dwOwnerType;
    ptInfo->nOwnerGUID = pUnit->dwOwnerGUID;
}

// 0x00554D00
D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType = pUnit->dwInteractType;
    int nUnitGUID = pUnit->dwInteractGUID;
    if (pUnit->nInteract)
    {
        return SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    }

    return 0;
}

// 0x00555CC0
int __cdecl SUNIT_GetItemsTxtCount()
{
    D2ItemDataTbl* pItemDataTbl = DATATBLS_GetItemDataTables();
    if (!pItemDataTbl)
        return 0;
    return pItemDataTbl->nItemsTxtRecordCount;
}

// 0x00554010
D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 2601);

    return hUnit->pGame;
}

// 0x00554040
void __fastcall SUNIT_SetTrackedSummonGUID(D2UnitStrc* hUnit, int nFlag)
{
    D2_ASSERT(hUnit, 2610);

    hUnit->pPlayerData->nNecropetFlag = nFlag;
}

// 0x00554070
unsigned int __fastcall SUNIT_GetTrackedSummonGUID(D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 2620);

    return hUnit->pPlayerData->nNecropetFlag;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount)
    {
        return 0;
    }

    return &sgptDataTables->pSkillsTxt[nSkillId];
}

static inline int SUNIT_GetUnitGUIDInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitId;
    }

    return -1;
}

// 0x005540A0
void __fastcall D2GAME_SetSparkChest_6FCBD7C0(D2UnitStrc* pUnit, unsigned char nSparkChest)
{
    D2_ASSERT(pUnit, 2631);

    pUnit->bSparkChest = nSparkChest;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

__forceinline D2UnitStrc* __fastcall SUNIT_GetOwner_Inline(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    if (!UNIT_HasFlagEx(pUnit, UNITFLAGEX_STOREOWNERINFO))
    {
        return 0;
    }

    return SUNIT_GetServerUnit(pGame, pUnit->dwOwnerType, pUnit->dwOwnerGUID);
}

// 0x005540D0
unsigned char __fastcall D2GAME_CheckIfSparklyChest_6FCBD7F0(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 2640);

    return pUnit->bSparkChest;
}

// 0x00554100
extern "C" __declspec(dllexport) int __stdcall sub_00554100(Obj00554100* pObj, int* pOut68, int* pOut64) {
    *pOut64 = pObj->nValue64;
    *pOut68 = pObj->nValue68;
    return pObj->nValue6C;
}

// 0x00554120
void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID)
{
    if (pUnit->nInteract)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
            if (pPlayerData)
            {
                char szMessage[80];
                sprintf(szMessage, "Player %s attempted to operate while busy\n", pPlayerData->szName);
            }
        }
    }
    else
    {
        pUnit->dwInteractGUID = nInteractUnitGUID;
        pUnit->dwInteractType = nInteractUnitType;
        pUnit->nInteract = 1;
    }
}

// 0x00554190
extern "C" __declspec(dllexport) void __stdcall SUNIT_ResetInteractInfo(Obj00554190* pObj) {
    pObj->nValue64 = -1;
    pObj->nValue68 = 6;
    pObj->nValue6C = 0;
}

// 0x005541B0
int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 1;
    }

    int bFlag = 0;
    if (pUnit)
    {
        bFlag = (pUnit->dwFlags >> 16) & 1;
    }

    if (bFlag)
    {
        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        if (pUnit->dwAnimMode == PLRMODE_DEATH || pUnit->dwAnimMode == PLRMODE_DEAD)
        {
            return 1;
        }
        return 0;

    case UNIT_MONSTER:
        if (pUnit->dwAnimMode == MONMODE_DEATH || pUnit->dwAnimMode == MONMODE_DEAD)
        {
            return 1;
        }
        return 0;
    }

    return 1;
}

// 0x00554200
int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (pUnit)
    {
        D2UnitStrc* pOwner = 0;
        if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            pOwner = AIGENERAL_GetMinionOwner(pUnit);
        }
        else if (pUnit->dwUnitType == UNIT_MISSILE)
        {
            pOwner = SUNIT_GetOwner_Inline(pGame, pUnit);
        }

        if (pOwner)
        {
            pUnit = pOwner;
        }
    }

    D2UnitStrc* i = pTarget;
    while (sub_0044BE50(i) == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(i);
        if (!pOwner || pOwner == i)
        {
            break;
        }

        i = pOwner;
    }

    if (pUnit == i)
    {
        return 0;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && i && i->dwUnitType == UNIT_PLAYER)
    {
        return PLAYERLIST_CheckFlag(pUnit, i, 8);
    }

    return STATLIST_AreUnitsAligned(pUnit, i) == 0;
}

// 0x005542C0
int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId)
{
    if (!pOwner || !pPet)
    {
        return 0;
    }

    const int nOwnerUnitType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerUnitType != UNIT_PLAYER && pPet->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETPET >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETPET & 7]))
    {
        return 0;
    }

    int nOwnerGUID;
    int nOwnerType;
    AIGENERAL_GetOwnerData(pPet, &nOwnerGUID, &nOwnerType);
    if (nOwnerType != UNIT_PLAYER || nOwnerGUID != SUNIT_GetUnitGUIDInline(pOwner))
    {
        return 0;
    }

    return 1;
}

// 0x00554340
static void __stdcall SUNIT_UpdateAlignmentRegion(D2UnitStrc* pUnit, int nAlignment, int nAlignNew, int bUpdate)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pGame)
    {
        return;
    }
    if (bUpdate)
    {
        MONSTERREGION_UpdateSpawnCountForAlignmentChange(pUnit->pGame->pMonReg, pUnit, nAlignment, nAlignNew);
    }
    if (nAlignment == nAlignNew)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }
    if (nAlignNew == UNIT_ALIGNMENT_GOOD)
    {
        DUNGEON_IncreaseAlliedCountOfRoom(pRoom);
    }
    else if (nAlignment == UNIT_ALIGNMENT_GOOD)
    {
        DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
    }
    if (!MONSTERS_IsDead(pUnit))
    {
        D2Common_10214(pUnit);
    }
}

static inline D2MonsterDataStrc* sub_00554670_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x00555500
static void SUNIT_ClearPlayerInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nInteractGUID = pUnit->dwInteractGUID;
    const int nInteractType = pUnit->dwInteractType;
    if (pUnit->nInteract)
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nInteractType, nInteractGUID);
        if (pInteractUnit)
        {
            switch (pInteractUnit->dwUnitType)
            {
            case UNIT_MONSTER:
                MONSTERAI_RemoveInteractInfoFor(pGame, pUnit, !pInteractUnit->pMonsterData ? 0 : pInteractUnit->pMonsterData->pMonInteract);
                SUNITPROXY_FreeVendorChain(pGame, pUnit, pInteractUnit);
                break;
            case UNIT_OBJECT:
                OBJMODE_ResetObjectInteraction(pGame, pInteractUnit);
                break;
            }

            pUnit->dwInteractGUID = -1;
            pUnit->dwInteractType = UNIT_INVALID;
            pUnit->nInteract = 0;
        }
    }
}

// 0x00552F60
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* ptGame, int nUnitType, int nUnitGUID)
{
    D2_ASSERT(ptGame, 722);

    D2UnitStrc** ppUnitList;
    if (nUnitType == UNIT_TILE)
    {
        ppUnitList = &ptGame->pTileList;
    }
    else if (nUnitType >= 0 && nUnitType <= 4)
    {
        ppUnitList = (D2UnitStrc**)((char*)ptGame + gnUnitListOffsets[nUnitType]) + (nUnitGUID & UNIT_LIST_MASK);
    }
    else
    {
        ppUnitList = 0;
    }

    for (D2UnitStrc* pUnit = *ppUnitList; pUnit; pUnit = pUnit->pListNext)
    {
        if (pUnit->dwUnitId == nUnitGUID)
        {
            return pUnit;
        }
    }

    return 0;
}

// 0x00554670
void __fastcall SUNIT_SynchronizeRoomClients(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    if (!UNITS_IsCurrentRoomInvalid(pUnit))
    {
        return;
    }

    D2ActiveRoomStrc* pCurrentRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        pRoom = SUNIT_GetValidNextRoom(pGame, pUnit);
    }
    if (pRoom && pCurrentRoom == pRoom)
    {
        return;
    }

    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = sub_00554670_GetMonsterData(pUnit);
        if (pMonsterData)
        {
            pMonsterData->pVision = 0;
        }
    }

    D2ClientStrc** ppNewClients = 0;
    unsigned int nNewClients = 0;
    if (pCurrentRoom)
    {
        ppNewClients = pCurrentRoom->ppClients;
        nNewClients = pCurrentRoom->nNumClients;
    }

    D2ClientStrc** ppOldClients = 0;
    unsigned int nOldClients = 0;
    if (pRoom)
    {
        ppOldClients = pRoom->ppClients;
        nOldClients = pRoom->nNumClients;
    }

    unsigned int i = 0;
    unsigned int j = 0;
    while (i < nNewClients && j < nOldClients)
    {
        D2_ASSERT(ppNewClients, 262);
        D2_ASSERT(ppOldClients, 263);
        D2ClientStrc* pNewClient = ppNewClients[i];
        D2ClientStrc* pOldClient = ppOldClients[j];
        if (pNewClient < pOldClient)
        {
            if (pUnit != CLIENTS_GetPlayerFromClient(pNewClient, 0))
            {
                SUNITMSG_SendUnitToClient(pGame, pUnit, ppNewClients[i]);
            }
            ++i;
        }
        else if (pNewClient > pOldClient)
        {
            if (pUnit != CLIENTS_GetPlayerFromClient(pOldClient, 0))
            {
                SUNITMSG_SendRemoveObject(pUnit, ppOldClients[j]);
            }
            ++j;
        }
        else
        {
            ++i;
            ++j;
        }
    }

    while (i < nNewClients)
    {
        D2_ASSERT(ppNewClients, 283);
        if (pUnit != CLIENTS_GetPlayerFromClient(ppNewClients[i], 0))
        {
            SUNITMSG_SendUnitToClient(pGame, pUnit, ppNewClients[i]);
        }
        ++i;
    }

    while (j < nOldClients)
    {
        D2_ASSERT(ppOldClients, 289);
        if (pUnit != CLIENTS_GetPlayerFromClient(ppOldClients[j], 0))
        {
            SUNITMSG_SendRemoveObject(pUnit, ppOldClients[j]);
        }
        ++j;
    }

    PATH_SetCurrentRoomInvalid(pUnit->pDynamicPath, 0);
}

// 0x00554A30
void __fastcall SUNIT_Restore(D2GameStrc* ptGame, D2UnitStrc* hUnit, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2_ASSERT(ptGame, 0x45C);
    D2_ASSERT(hUnit, 0x45D);

    hUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    hUnit->pDrlgAct = ptGame->pAct[hUnit->nAct];
    hUnit->dwFlagEx &= ~UNITFLAGEX_HASBEENDELETED;

    switch (hUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PATH_FreeDynamicPath(ptGame->pMemoryPool, hUnit->pDynamicPath);
        hUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(ptGame->pMemoryPool, pRoom, nX, nY, hUnit, 0);
        PLAYER_InitializePosition(ptGame, hUnit, nX, nY);
        if (hUnit->dwAnimMode == PLRMODE_DEAD || hUnit->dwAnimMode == PLRMODE_DEATH)
        {
            PATH_RemoveCollisionFootprintForUnit(hUnit, 1);
            sub_00649190_SetPathMode(hUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
            PATH_SetFootprintCollisionMask(hUnit->pDynamicPath, COLLIDE_CORPSE);
        }
        break;

    case UNIT_MONSTER:
        PATH_FreeDynamicPath(ptGame->pMemoryPool, hUnit->pDynamicPath);
        hUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(ptGame->pMemoryPool, pRoom, nX, nY, hUnit, 0);
        MONSTER_SetVelocityAndPosition(ptGame, hUnit, nX, nY, 0);
        if (SUNIT_RoomHasClients(hUnit))
        {
            MONSTER_UpdateAiCallbackEvent(ptGame, hUnit);
        }
        else
        {
            sub_00553220(ptGame, hUnit);
        }

        if (MONSTERS_IsDead(hUnit))
        {
            PATH_RemoveCollisionFootprintForUnit(hUnit, 1);
            sub_00649190_SetPathMode(hUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
            PATH_SetFootprintCollisionMask(hUnit->pDynamicPath, COLLIDE_CORPSE);
        }
        break;

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(hUnit->dwClassId);
        UNITS_InitializeStaticPath(hUnit, pRoom, nX, nY);
        if (pObjectsTxtRecord->nHasCollision[hUnit->dwAnimMode])
        {
            UNITS_BlockCollisionPath(hUnit, pRoom, nX, nY);
        }

        UNITROOM_AddUnitToRoom(hUnit, pRoom);
        break;
    }
    case UNIT_ITEM:
        if (hUnit->dwAnimMode == IMODE_ONGROUND)
        {
            UNITS_InitializeStaticPath(hUnit, pRoom, nX, nY);
            UNITS_BlockCollisionPath(hUnit, pRoom, nX, nY);
            UNITROOM_AddUnitToRoom(hUnit, pRoom);
            hUnit->pItemData->dwActionStamp = ITEMS_GetGroundRemovalTime(ptGame, hUnit);
        }
        break;

    case UNIT_MISSILE:
        PATH_FreeDynamicPath(ptGame->pMemoryPool, hUnit->pDynamicPath);
        hUnit->pDynamicPath = 0;
        PATH_AllocDynamicPath(ptGame->pMemoryPool, pRoom, nX, nY, hUnit, 0);
        break;

    case UNIT_TILE:
        UNITS_InitializeStaticPath(hUnit, pRoom, nX, nY);
        UNITS_BlockCollisionPath(hUnit, pRoom, nX, nY);
        UNITROOM_AddUnitToRoom(hUnit, pRoom);
        break;

    default:
        D2_ASSERT(0, 0x4AA);
        break;
    }

    if (UNITS_GetRoom(hUnit))
    {
        UNITROOM_RefreshUnit(hUnit);
    }

    UNITS_SetCurrentRoomInvalid(hUnit, 1);
}

// 0x00555910
void __fastcall SUNIT_SpawnPresetUnit(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2PresetUnitStrc* pPresetUnit)
{
    D2DrlgCoordsStrc pCoord;

    DUNGEON_GetRoomCoordinates(pRoom, &pCoord);

    const int nX = pPresetUnit->nXpos + pCoord.nSubtileX;
    const int nY = pPresetUnit->nYpos + pCoord.nSubtileY;
    D2UnitStrc* pUnit = SUNIT_CreatePresetUnit(pGame, pRoom, pPresetUnit->nUnitType, pPresetUnit->nIndex, nX, nY, pPresetUnit->nMode, 0);
    if (!pUnit)
    {
        return;
    }

    if (pPresetUnit->nUnitType == UNIT_MONSTER)
    {
        D2MapAIStrc** ppPresetMapAI = &pPresetUnit->pMapAI;
        D2MapAIStrc* pMapAI = AIGENERAL_GetMapAiFromUnit(pUnit);
        if (*ppPresetMapAI)
        {
            DRLGPRESET_ChangeMapAI(ppPresetMapAI, pMapAI);
        }
    }
    else if (pPresetUnit->nUnitType == UNIT_OBJECT)
    {
        QUESTS_MapPresetSpawn(pGame, pUnit, pPresetUnit->pMapAI);
    }
}

// 0x005559A0
void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    if (!pGame)
        return;

    D2PresetUnitStrc* pPresetUnit = DUNGEON_GetPresetUnitsFromRoom(pRoom);
    int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);

    for (D2PresetUnitStrc* i = pPresetUnit; i; i = i->pNext)
    {
        if (i->nUnitType != UNIT_MONSTER && !(i->bSpawned & 1))
        {
            if (nLevelId == LEVEL_PANDEMONIUMFINALE)
            {
                if (i->nUnitType != UNIT_OBJECT || (i->nIndex != OBJECT_WIRTSBODY && i->nIndex != OBJECT_GOLD_PLACEHOLDER && i->nIndex != OBJECT_CAINGIBBET))
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);

                if (i->nIndex == OBJECT_GOLD_PLACEHOLDER)
                    DUNGEON_GetLevelIdFromRoom(pRoom);
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN1)
            {
                if (i->nUnitType != UNIT_OBJECT || i->nIndex != OBJECT_SPARKLY_CHEST)
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN2)
            {
                if (i->nUnitType != UNIT_OBJECT)
                {
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
                }
                else if (i->nIndex != OBJECT_VALLEY_WAYPOINT)
                {
                    pGame->dwUberSandsCounter++;
                    if (pGame->dwUberSandsCounter != (pGame->dwInitSeed % 3) + 3)
                        SUNIT_SpawnPresetUnit(pGame, pRoom, i);
                }
            }
            else if (nLevelId == LEVEL_PANDEMONIUMRUN3)
            {
                if (i->nUnitType != UNIT_OBJECT || i->nIndex != OBJECT_SPARKLY_CHEST)
                    SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
            else
            {
                SUNIT_SpawnPresetUnit(pGame, pRoom, i);
            }
        }
    }

    D2PresetUnitStrc* pMonster = pPresetUnit;
    if (nLevelId == LEVEL_PANDEMONIUMFINALE)
        return;

    for (; pMonster; pMonster = pMonster->pNext)
    {
        if (pMonster->nUnitType == UNIT_MONSTER && !(pMonster->bSpawned & 1))
            SUNIT_SpawnPresetUnit(pGame, pRoom, pMonster);
    }
}

static inline int UNIT_TypeOrInvalid(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

static inline unsigned short SUNIT_GetPartyId_Inline(D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->pGame && pPlayer->dwUnitType == UNIT_PLAYER)
        return PARTY_GetPartyIdForUnitOwner(pPlayer->pGame, pPlayer);
    return 0xFFFF;
}

// 0x00555600
void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pGame, 0x59);
    D2_ASSERT(pUnit, 0x5C);
    D2_ASSERT(pUnit->dwUnitType < NUM_UNIT_TYPES, 0x61);

    SUNIT_DetachUnit(pUnit, pGame, 0);

    if (pUnit->pQuestEventList)
    {
        QUESTS_FreeChainRecord(pGame, pUnit->pQuestEventList);
        pUnit->pQuestEventList = 0;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        D2GAME_FreeUnitNode_6FC40310(pGame, pUnit);
        PLAYER_RemoveTownPortal(pGame, pUnit);
        PARTY_LeaveParty(pGame, pUnit);
        PLAYER_Destroy(pGame, pUnit);

        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }
        break;

    case UNIT_MONSTER:
        sub_005B1A90(pGame, pUnit);

        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }

        MONSTER_Free(pGame, pUnit);
        break;

    case UNIT_OBJECT:
        OBJECTS_FreeHoverMessage(pGame, pUnit);
        UNITS_FreeStaticPath(pUnit);
        FOG_FreePool(pGame->pMemoryPool, pUnit->pPlayerData, ".\\UNIT\\SUnit.cpp", 0xA4, 0);
        break;

    case UNIT_MISSILE:
        if (pUnit->pDynamicPath)
        {
            PATH_FreeDynamicPath(pGame->pMemoryPool, pUnit->pDynamicPath);
            pUnit->pDynamicPath = 0;
        }

        MISSILES_Free(pGame, pUnit);
        break;

    case UNIT_ITEM:
        ITEMS_FreeSocketInventoryAndTimers(pGame, pUnit);
        ITEMS_FreeItemData(pGame->pMemoryPool, pUnit);
        UNITS_FreeStaticPath(pUnit);
        break;

    case UNIT_TILE:
        UNITS_FreeStaticPath(pUnit);
        break;
    }

    SUNITEVENT_FreeEventList(pGame, pUnit);
    D2GAME_SUNITMSG_FreeUnitMessages_6FCC6790(pUnit);
    UNITS_FreeUnit(pUnit);
}

// 0x00555580
void __fastcall SUNIT_DetachUnit(D2UnitStrc* pUnit, D2GameStrc* pGame, int bKeepInRoom)
{
    D2_ASSERT(pUnit, 940);
    D2_ASSERT(pUnit->dwUnitType < 6, 941);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        SUNIT_ClearPlayerInteraction(pGame, pUnit);
        D2Common_10228(pUnit);
        break;
    case UNIT_MONSTER:
        D2Common_10228(pUnit);
        break;
    case UNIT_OBJECT:
        D2Common_10228(pUnit);
        break;
    case UNIT_MISSILE:
        D2Common_10228(pUnit);
        break;
    }

    if (!bKeepInRoom)
    {
        UNITROOM_RemoveUnitFromRoom(pUnit);
    }

    SUNIT_RemoveFromUnitList(pGame, pUnit);
}

static inline int GetClassId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwClassId;
}

// 0x005550B0
void __fastcall SUNIT_WarpPlayer(D2GameStrc* ptGame,D2UnitStrc* hUnit,D2UnitStrc* pTile)
{
    D2_ASSERT(ptGame,329);
    D2_ASSERT(hUnit,330);
    D2ActiveRoomStrc* pOldRoom = UNITS_GetRoom(pTile);
    int nLevel = GetClassId(pTile);
    D2LvlWarpTxt* pWarp;
    D2UnitStrc* pDestination = DUNGEON_GetWarpTileFromRoomAndSourceLevelId(pOldRoom,nLevel,&pWarp);
    if (!pDestination) return;
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pDestination);
    D2CoordStrc point;
    point.nX = CLIENTS_GetUnitX(pDestination);
    point.nY = CLIENTS_GetUnitY(pDestination);
    D2_ASSERT(hUnit->dwUnitType == UNIT_PLAYER,348);
    D2ActiveRoomStrc* pFreeRoom = COLLISION_GetFreeCoordinates(pTargetRoom,&point,UNITS_GetUnitSizeX(hUnit),0x1C09,1);
    if (!pFreeRoom) return;
    int nOldLevel = DUNGEON_GetLevelIdFromRoom(pOldRoom);
    int nNewLevel = DUNGEON_GetLevelIdFromRoom(pFreeRoom);
    if (nNewLevel == 73 || nNewLevel == 128 || nNewLevel == 132 || nNewLevel == 118 || nNewLevel == 100)
        if (QUESTS_LevelWarpCheck(ptGame,hUnit,nOldLevel,nNewLevel)) return;
    int nX = point.nX;
    int nY = point.nY;
    if (SUNIT_TeleportUnit(ptGame,hUnit,pTargetRoom,nX,nY,0,0))
    {
        D2ClientStrc* pClient = UnitGetClient(hUnit,".\\UNIT\\SUnit.cpp",376);
        int nDestX = pWarp->dwExitWalkX + nX;
        int nDestY = pWarp->dwExitWalkY + nY;
        PLRMODE_ChangeModeToCoords(ptGame,hUnit,0,2,nDestX,nDestY,0);
        unsigned char nLife = UNITS_GetCurrentLifePercentage(hUnit);
        D2GAME_PACKETS_SendPacket0x0D_6FC3C920(pClient,0x0D,!hUnit ? 6 : hUnit->dwUnitType,!hUnit ? -1 : hUnit->dwUnitId,1,nDestX,nDestY,0,nLife);
    }
}

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x00555230
D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID)
{
    switch (nUnitType)
    {
    case UNIT_PLAYER:
        if ((unsigned int)nClassId >= 7)
        {
            return 0;
        }
        break;

    case UNIT_MONSTER:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        if (!pMonStatsTxtRecord || !(pMonStatsTxtRecord->nMonStatsFlags[MONSTATSFLAGINDEX_ENABLED >> 3] & gdwBitMasks[MONSTATSFLAGINDEX_ENABLED & 7]))
        {
            return 0;
        }
        break;
    }
    }

    D2UnitStrc* pUnit = UNITS_AllocUnit(pGame->pMemoryPool, nUnitType);
    if (!pUnit)
    {
        return 0;
    }

    pUnit->dwUnitType = nUnitType;
    pUnit->dwClassId = nClassId;
    pUnit->pMemoryPool = pGame->pMemoryPool;
    pUnit->pGame = pGame;

    if (pGame->bExpansion)
    {
        pUnit->dwFlagEx |= UNITFLAGEX_ISEXPANSION;
    }
    else
    {
        pUnit->dwFlagEx &= ~UNITFLAGEX_ISEXPANSION;
    }
    pUnit->dwFlagEx |= UNITFLAGEX_SERVERUNIT;

    pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    pUnit->pDrlgAct = pGame->pAct[pUnit->nAct];
    pUnit->pQuestEventList = 0;

    if (nUnitType)
    {
        SUNIT_InitSeed(pUnit, &pGame->pGameSeed);

        if (nUnitType == UNIT_ITEM)
        {
            ITEMS_AllocItemData(pGame->pMemoryPool, pUnit);
            SUNIT_InitItemSeeds(pUnit, &pGame->pGameSeed);
        }
    }

    pUnit->dwFlags |= UNITFLAG_INITSEEDSET;
    pUnit->dwNodeIndex = 11;

    int nUnitGUID;
    if (nUnitType == UNIT_MONSTER && (nAllocFlags & 2))
    {
        nUnitGUID = nOverrideUnitGUID;
    }
    else
    {
        nUnitGUID = SUNIT_GetNewUnitGUID(pGame, nUnitType);
    }

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        PLAYER_Create(pGame, pUnit, nUnitGUID);
        if (nMode != PLRMODE_DEAD)
        {
            TARGETS_AllocPlayerNode(pGame, pUnit, 0);
        }
        break;

    case UNIT_MONSTER:
        pUnit->dwAnimMode = nMode;
        MONSTER_Initialize(pGame, pRoom, pUnit, nUnitGUID);
        break;

    case UNIT_OBJECT:
        pUnit->pObjectData = (D2ObjectDataStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ObjectDataStrc), ".\\UNIT\\SUnit.cpp", 612, 0);
        memset(pUnit->pObjectData, 0, sizeof(D2ObjectDataStrc));
        pUnit->pObjectData->pObjectTxt = DATATBLS_GetObjectsTxtRecord(nClassId);
        pUnit->dwAnimMode = nMode;
        UNITS_AllocStaticPath(pUnit);
        OBJECTS_InitHandler(pGame, pUnit, nUnitGUID, pRoom, nX, nY);
        break;

    case UNIT_ITEM:
        pUnit->dwAnimMode = nMode;
        UNITS_AllocStaticPath(pUnit);
        ITEMMODE_InitializeItemUnit(pUnit, pGame, nUnitGUID, pRoom);
        break;

    case UNIT_MISSILE:
        pUnit->dwAnimMode = nMode;
        MISSILES_Initialize(pGame, pUnit, nUnitGUID);
        break;

    case UNIT_TILE:
        UNITS_AllocStaticPath(pUnit);
        pUnit->dwFlags |= UNITFLAG_TARGETABLE;
        pUnit->dwUnitId = nUnitGUID;
        break;
    }

    if (nAllocFlags & 1)
    {
        SUNIT_Add(pUnit, nX, nY, pGame, pRoom, 1);

        switch (nUnitType)
        {
        case UNIT_PLAYER:
            if (pUnit->dwAnimMode == PLRMODE_DEAD || pUnit->dwAnimMode == PLRMODE_DEATH)
            {
                PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
                PATH_SetUnitCollisionPattern(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
                PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
            }
            break;

        case UNIT_MONSTER:
            if (MONSTERS_IsDead(pUnit) && !MONSTERREGION_CheckMonStats2Flag(nClassId, MONSTATS2FLAGINDEX_DEADCOL))
            {
                PATH_RemoveCollisionFootprintForUnit(pUnit, 1);
                PATH_SetUnitCollisionPattern(pUnit, COLLISION_PATTERN_SMALL_NO_PRESENCE);
                PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, COLLIDE_CORPSE);
                return pUnit;
            }
            break;
        }
    }

    return pUnit;
}

// 0x00554850
void __fastcall SUNIT_Add(D2UnitStrc* pUnit, int nX, int nY, D2GameStrc* ptGame, D2ActiveRoomStrc* hRoom, int bSkipRoomUpdate)
{
    D2_ASSERT(ptGame, 0x3FF);
    D2_ASSERT(pUnit, 0x403);

    pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(hRoom));
    pUnit->pDrlgAct = ptGame->pAct[pUnit->nAct];

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PATH_AllocDynamicPath(ptGame->pMemoryPool, hRoom, nX, nY, pUnit, 0);
        PLAYER_InitializePosition(ptGame, pUnit, nX, nY);
        break;

    case UNIT_MONSTER:
        PATH_AllocDynamicPath(ptGame->pMemoryPool, hRoom, nX, nY, pUnit, 0);
        MONSTER_SetVelocityAndPosition(ptGame, pUnit, nX, nY, bSkipRoomUpdate);
        if (SUNIT_RoomHasClients(pUnit))
        {
            MONSTER_UpdateAiCallbackEvent(ptGame, pUnit);
        }
        else
        {
            sub_00553220(ptGame, pUnit);
        }
        break;

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pUnit->dwClassId);
        UNITS_InitializeStaticPath(pUnit, hRoom, nX, nY);
        if (pObjectsTxtRecord->nHasCollision[pUnit->dwAnimMode])
        {
            UNITS_BlockCollisionPath(pUnit, hRoom, nX, nY);
        }

        D2_ASSERT(hRoom, 0x420);
        UNITROOM_AddUnitToRoom(pUnit, hRoom);
        break;
    }
    case UNIT_ITEM:
        if (pUnit->dwAnimMode == IMODE_ONGROUND)
        {
            UNITS_InitializeStaticPath(pUnit, hRoom, nX, nY);
            UNITS_BlockCollisionPath(pUnit, hRoom, nX, nY);
            if (hRoom)
            {
                UNITROOM_AddUnitToRoomEx(pUnit, hRoom, 0);
            }
        }
        break;

    case UNIT_MISSILE:
        PATH_AllocDynamicPath(ptGame->pMemoryPool, hRoom, nX, nY, pUnit, 0);
        break;

    case UNIT_TILE:
        UNITS_InitializeStaticPath(pUnit, hRoom, nX, nY);
        UNITS_BlockCollisionPath(pUnit, hRoom, nX, nY);
        D2_ASSERT(hRoom, 0x442);
        UNITROOM_AddUnitToRoom(pUnit, hRoom);
        break;

    default:
        D2_ASSERT(0, 0x447);
        break;
    }

    SUNIT_AddToUnitList(pUnit, ptGame);

    if (UNITS_GetRoom(pUnit))
    {
        UNITROOM_RefreshUnit(pUnit);
    }

    if (!bSkipRoomUpdate)
    {
        UNITS_SetCurrentRoomInvalid(pUnit, 1);
    }
}

// 0x005531C0
D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    return UNITS_GetPlayerData(pPlayer)->pClient;
}

// 0x005531E0
void __fastcall SUNIT_UpdateClientIfRoomInvalid(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (UNITS_IsCurrentRoomInvalid(pUnit))
    {
        int bFlag = 0;
        if (pUnit)
        {
            bFlag = (pUnit->dwFlags >> 4) & 1;
        }

        if (!bFlag)
        {
            sub_00538410_RemoveUnitIfNotAdjacent2(pClient, pUnit);
        }
    }
}

// 0x00554630
short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer)
{
    if (pPlayer && pPlayer->pGame && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        return PARTY_GetPartyIdForUnitOwner(pPlayer->pGame, pPlayer);
    }

    return -1;
}

// 0x00554D20
int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId)
{
    if (!pOwner || !pPet)
    {
        return 0;
    }

    const int nOwnerUnitType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    if (nOwnerUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    const int nPetType = pPet->dwUnitType;
    int nUnitType = nPetType;
    if (nPetType != UNIT_PLAYER && nPetType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_TARGETALLY >> 3] & gdwBitMasks[SKILLSFLAGINDEX_TARGETALLY & 7]))
    {
        return 0;
    }

    int nUnitGUID = pPet->dwUnitId;
    if (nPetType == UNIT_MONSTER)
    {
        AIGENERAL_GetOwnerData(pPet, &nUnitGUID, &nUnitType);
        if (nUnitGUID == -1 || nUnitType != UNIT_PLAYER)
        {
            return 0;
        }
    }

    const unsigned short nPartyId = SUNIT_GetPartyId(pOwner);
    if (nPartyId == 0xFFFF)
    {
        return 0;
    }

    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
    if (!pOtherPlayer)
    {
        return 0;
    }

    return nPartyId == (unsigned short)SUNIT_GetPartyId(pOtherPlayer);
}

// 0x00554DE0
int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2)
{
    if (pUnit1 && pUnit1->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit1);
        if (pOwner)
        {
            pUnit1 = pOwner;
        }
    }
    if (pUnit2 && (!pUnit2 ? 6 : pUnit2->dwUnitType) == 1)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit2);
        if (pOwner)
        {
            pUnit2 = pOwner;
        }
    }
    if (pUnit1 == pUnit2)
    {
        return 1;
    }
    if (UNIT_TypeOrInvalid(pUnit1) == 0 && UNIT_TypeOrInvalid(pUnit2) == 0)
    {
        const unsigned int nPartyId1 = SUNIT_GetPartyId_Inline(pUnit1);
        const unsigned int nPartyId2 = SUNIT_GetPartyId_Inline(pUnit2);
        return nPartyId1 == nPartyId2 && nPartyId2 != 0xFFFF;
    }
    return STATLIST_AreUnitsAligned(pUnit1, pUnit2);
}

// 0x00554EA0
int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* hUnit, D2ActiveRoomStrc* pInputRoom, int nX, int nY, int a6, int a7)
{
    D2_ASSERT(hUnit, 0xC21);
    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(hUnit);
    D2DynamicPathStrc* hPath = hUnit->pDynamicPath;
    D2_ASSERT(hPath, 0xC25);

    D2ActiveRoomStrc* pRoom = pInputRoom;
    D2CoordStrc tCoords;
    tCoords.nX = nX;
    tCoords.nY = nY;
    if (!pRoom)
    {
        pRoom = sub_00463740_FindRoomAtPoint(0, tCoords.nX, tCoords.nY);
        if (!pRoom)
        {
            pRoom = sub_00463740_FindRoomAtPoint(pUnitRoom, tCoords.nX, tCoords.nY);
        }
    }

    if (!pRoom)
    {
        return 0;
    }

    if (!a6)
    {
        pRoom = COLLISION_GetFreeCoordinates(pRoom, &tCoords, UNITS_GetUnitSizeX(hUnit), 0x1C09, 0);
    }

    if (!pRoom)
    {
        return 0;
    }

    if (!sub_00650BE0_PlaceUnit(hPath, hUnit, pRoom, tCoords.nX, tCoords.nY))
    {
        return 0;
    }

    if (hUnit->dwUnitType == UNIT_PLAYER)
    {
        D2ClientStrc* pClient = UnitGetClient(hUnit, ".\\UNIT\\SUnit.cpp", 0xC3C);
        D2DrlgCoordsStrc tDrlgCoords;
        DUNGEON_GetRoomCoordinates(pRoom, &tDrlgCoords);
        D2GAME_PACKETS_SendPacket0x07_6FC3D120(pClient, DUNGEON_GetLevelIdFromRoom(pRoom), (unsigned short)tDrlgCoords.nTileXPos, (unsigned short)tDrlgCoords.nTileYPos);

        UNITROOM_RefreshUnit(hUnit);
        if (a7)
        {
            hUnit->dwFlagEx |= 0x800;
        }
        else
        {
            hUnit->dwFlagEx |= 0x10000;
        }

        SUNIT_SynchronizeRoomClients(pGame, hUnit, 0);

        D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(hUnit);
        const unsigned char nIndex = pPlayerData->nPositionHistoryIndex;
        pPlayerData->nSkillCooldown148 = tCoords.nX;
        pPlayerData->nSkillCooldown14C = tCoords.nY;
        pPlayerData->dwPositionHistoryTick = GetTickCount();
        pPlayerData->pPositionHistory[nIndex].nX = tCoords.nX;
        pPlayerData->pPositionHistory[nIndex].nY = tCoords.nY;
        pPlayerData->nPositionHistoryIndex += 1;
        if (pPlayerData->nPositionHistoryIndex >= 20)
        {
            pPlayerData->nPositionHistoryIndex = 0;
        }

        EVENT_SetEventWithCallback(pGame, hUnit, 14, pGame->dwGameFrame + 50, SUNIT_EventClearTeleportCoordinates, 0, 0);
        sub_6FC7E310(pGame, hUnit, tCoords.nX, tCoords.nY);
    }
    else
    {
        UNITROOM_RefreshUnit(hUnit);
        if (a7)
        {
            hUnit->dwFlagEx |= 0x800;
        }
        else
        {
            hUnit->dwFlagEx |= 0x10000;
        }

        SUNIT_SynchronizeRoomClients(pGame, hUnit, 0);
    }

    return 1;
}

// 0x005543B0
void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int bUpdate)
{
    const int eAlignNew = nAlignNew;
    int nAlignment = UNIT_ALIGNMENT_UNASSIGNED;
    if (!pUnit)
    {
        return;
    }
    D2_ASSERT(eAlignNew < UNIT_NUM_ALIGNMENT, 2994);
    const int nClassId = pUnit->dwClassId;
    if (nClassId != MONSTER_HYDRA1 && nClassId != MONSTER_HYDRA2 && nClassId != MONSTER_HYDRA3 && eAlignNew == UNIT_ALIGNMENT_EVIL && sub_00451F30_TestUnitFlag(pUnit, 0x80000000))
    {
        return;
    }
    D2StatListStrc* hList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_ALIGNMENT);
    if (!hList)
    {
        hList = STATLIST_AllocStatList(pUnit->pMemoryPool, 0, 0, pUnit->dwUnitType, pUnit->dwUnitId);
        D2_ASSERT(hList, 3012);
        STATLIST_SetState(hList, STATE_ALIGNMENT);
        D2COMMON_10475_PostStatToStatList(pUnit, hList, 1);
        STATES_ToggleState(pUnit, STATE_ALIGNMENT, 1);
    }
    else
    {
        nAlignment = STATLIST_GetStatValue(hList, STAT_ALIGNMENT, 0);
    }
    STATLIST_SetStat(hList, STAT_ALIGNMENT, eAlignNew, 0);
    STATES_ToggleGfxStateFlag(pUnit, STATE_ALIGNMENT, 1);
    SUNIT_UpdateAlignmentRegion(pUnit, nAlignment, eAlignNew, bUpdate);
}

// 0x005544B0
void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* hUnit, int bSetUninterruptable)
{
    STATES_ToggleState(hUnit, STATE_UNINTERRUPTABLE, bSetUninterruptable);

    D2_ASSERT(hUnit, 2601);
    D2GameStrc* pGame = hUnit->pGame;
    if (!pGame)
    {
        return;
    }

    if (!bSetUninterruptable && STATES_CheckState(hUnit, STATE_DEATH_DELAY))
    {
        STATES_ToggleState(hUnit, STATE_DEATH_DELAY, 0);

        D2UnitStrc* pAttacker = SUNIT_GetLastAttacker(pGame, hUnit);
        if (pAttacker)
        {
            D2DamageStrc damage;
            memset(&damage, 0, sizeof(damage));
            damage.wResultFlags |= DAMAGERESULTFLAG_WILLDIE;
            SUNITDMG_ExecuteMissileDamage(pGame, pAttacker, hUnit, &damage);
        }
        else
        {
            SUNITDMG_KillMonster(pGame, hUnit, 0, 1);
        }
    }

    if (hUnit->dwUnitType == UNIT_MONSTER)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, hUnit, EVENTTYPE_AITHINK, 0);
    }
}

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

// 0x00555AE0
void __fastcall SUNIT_RemoveAllItemsFromInventory(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0x9D6);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* i = INVENTORY_GetFirstItem(pInventory);
    while (i)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(i);

        D2UnitStrc* hItem = INVENTORY_UnitIsItem(i);
        D2_ASSERT(hItem, 0x9E9);

        if (hItem->dwUnitType == UNIT_ITEM)
        {
            D2GAME_ITEMS_UpdateTransferredProperties_6FC424E0(pGame, hItem, pUnit, 0, 1);

            if (INVENTORY_GetItemNodePage(i) == 3)
            {
                sub_0063BE30(pInventory, INVENTORY_GetBodyLocFromEquippedItem(pInventory, hItem));
            }
            else if (ITEMS_IsCharmUsable(hItem, pUnit))
            {
                const unsigned char nPage = ITEMS_GetInvPage(hItem);
                const int nInventoryRecordId = UNITS_GetInventoryRecordId(pUnit, nPage, pGame->bExpansion);
                INVENTORY_Return(".\\UNIT\\SUnit.cpp", 0xA03, pInventory, UNITS_GetUnitXPosition(hItem), UNITS_GetUnitYPosition(hItem), nInventoryRecordId, 0, nPage);
            }
        }

        D2_ASSERT(INVENTORY_RemoveItemFromInventory(pInventory, hItem), 0xA07);

        if (hItem->dwUnitType < UNIT_TYPES_COUNT)
        {
            SUNIT_RemoveUnit(pGame, hItem);
        }

        i = pNext;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (pCursorItem && pCursorItem->dwUnitType < UNIT_TYPES_COUNT)
    {
        SUNIT_RemoveUnit(pGame, pCursorItem);
    }
}

// 0x00555C90
extern "C" D2ItemTypesTxt* __fastcall SUNIT_GetTableRow(int index)
{
    if (index < 0 || index >= sgptDataTables->nItemTypesTxtRecordCount) return 0;
    return &sgptDataTables->pItemTypesTxt[index];
}

// 0x00554570
int __fastcall SUNIT_EventClearTeleportCoordinates(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nEventType, int a4, int a5)
{
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        return 0;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }

    pPlayerData->nSkillCooldown148 = 0;
    pPlayerData->nSkillCooldown14C = 0;
    EVENT_DeleteTimersByCallback(pGame, pPlayer, EVENTTYPE_REMOVESKILLCOOLDOWN, SUNIT_EventClearTeleportCoordinates);
    return 1;
}

// 0x005545C0
D2ActiveRoomStrc* __fastcall SUNIT_GetValidNextRoom(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    D2ActiveRoomStrc* pNextRoom = PATH_GetNextRoom(pDynamicPath);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
    if (nLevelId)
    {
        for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[DRLG_GetActNoFromLevelId(nLevelId)]); pRoom; pRoom = pRoom->pRoomNext)
        {
            if (pRoom == pNextRoom)
            {
                return pNextRoom;
            }
        }
    }

    PATH_ClearNextRoom(pDynamicPath);
    return 0;
}

// 0x00554650
extern "C" __declspec(dllexport) int __fastcall SUNITDMG_SetHitClass(Obj00554650* pObj, unsigned int dwBits) {
    unsigned int dwFlags = pObj->dwFlags60;
    if (dwFlags & 0xF0) {
        return 0;
    }
    pObj->dwFlags60 = dwFlags | dwBits;
    return 1;
}

#include "gen/data/Source/D2Game/UNIT/SUnit.inc"
