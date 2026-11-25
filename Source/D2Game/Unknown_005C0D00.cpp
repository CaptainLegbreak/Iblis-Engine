#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2AnimData.h"
#include "D2Path.h"
#include "D2ItemModes.h"
#include "D2Records.h"
#include "D2GameAux.h"
#include "D2BookDataTbl.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x007418C4

#define IFLAG_TARGETING 4

#define UPDATEUI_CLOSEALL 17

#define UPDATEUI_OPENCUBE 21

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

struct D2ItemsTxt;

struct D2MonStatsTxt;

struct D2BooksTxt;


struct D2CurseStrc;

struct D2SkillsTxt;

struct Unit005A0180;

union D2SeedStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2DamageStrc;

struct D2AnimSeqTxt;

struct D2ItemStatCostTxt;

void __stdcall ITEMS_SetItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int bSet); // 0x006280D0

int __stdcall ITEMS_GetSpellIcon(D2UnitStrc* pItem); // 0x0062BB20

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

int __fastcall D2GAME_PLRTRADE_IsInteractingWithPlayer(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x005678A0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590



extern D2pSpellTblStrc gaPSpellTable[]; // 0x00741790

void __fastcall D2GAME_PACKETS_SendPacketSize06_6FC3C850(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

unsigned short __stdcall ITEMS_GetSuffixId(D2UnitStrc* pItem, int nSuffixNo); // 0x00627F80

D2BooksTxt* __stdcall DATATBLS_GetBooksTxtRecord(int nIndex); // 0x006374B0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);

enum D2C_Z09ItemConstants
{
    EVENTTYPE_REMOVESTATE = 0x0C,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall ITEMMODS_EvaluateItemFormula(D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int nCalc); // 0x00627C20

int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nStateId, int a3); // 0x0056C740

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __fastcall SKILLITEM_pSpell09_StaminaPotion(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY, int nSkillId); // 0x005BEDA0

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem); // 0x00629DA0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

D2UnitStrc* __fastcall SUNIT_GetInteractUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00554D00

void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190

void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui_6FC3E0B0(D2ClientStrc* pClient, unsigned char nUiNo); // 0x0053CAB0

void __stdcall SUNIT_SetInteractInfo(D2UnitStrc* pUnit, int nInteractUnitType, int nInteractUnitGUID); // 0x00554120

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int a5); // 0x005FDCA0

int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int a6); // 0x005FDD60

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall ITEMMODE_UseStoredItemAtCoordinates(D2GameStrc* ptGame, D2UnitStrc* hUnit, int itemId, int x, int y, int* status); // 0x0055E170

int __fastcall ITEMMODE_UseBeltItem(D2GameStrc* ptGame, D2UnitStrc* hUnit, int nItemGUID, int nX, int nY, int* pItemStatus, int bUseOnMerc); // 0x00562390

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pHireling); // 0x0063EE90

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

enum D2C_Y09SkillConstants
{
    SKILLSFLAGINDEX_AURA = 5,
    SKILLSFLAGINDEX_IMMEDIATE = 15,
    EVENTTYPE_PERIODICSTATS = 9,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50

int __fastcall sub_0056F7F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5, int a6, int a7); // 0x0056F7F0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __fastcall SKILLITEM_CalculateOpenWoundsHpRegen(int nLevel, const int* pValues); // 0x005BFDA0

extern "C" int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask); // 0x005A0180

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __fastcall MONSTER_GetHpBonus(int nPlayerCount); // 0x005738F0

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50

int __fastcall GAME_GetUnitGUID(D2UnitStrc*); // 0x00451F50

int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc*,D2UnitStrc*,int); // 0x005C6870

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005805D0

void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc*,unsigned char); // 0x00571A10

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall SKILLS_ApplyDimVisionToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel); // 0x005C39C0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_ITEM 4

#define UNIT_INVALID 6

#define MONSTATS2FLAGINDEX_SMALL 10

#define MONSTATS2FLAGINDEX_LARGE 11

struct D2MonStats2Txt;

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

static void SKILLITEM_ClearTargetingItems(D2UnitStrc* pUnit);

int __fastcall SKILLITEM_pSpell_Handler(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2UnitStrc* pTarget, int nX, int nY);

enum D2C_J10SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    DAMAGERESULTFLAG_GETHIT = 4,
    DAMAGEHITFLAG_0x20 = 0x20,
    SKILLSFLAGINDEX_ITEMTGTDO = 29,
};

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc* pSeed, int nMax);                                     // 0x00472210

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax);                                   // 0x0045C3E0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int nDuration, int nParam); // 0x005DDD00

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* room); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int level); // 0x006427F0

int __stdcall DUNGEON_GetTownLevelIdFromActNo(unsigned char act); // 0x0061AB70

void __fastcall PLAYER_RemoveTownPortal(D2GameStrc* game,D2UnitStrc* unit); // 0x00535430

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* game,D2UnitStrc* unit,D2ActiveRoomStrc* room,int x,int y,int level,D2UnitStrc** out,int object,int permanent); // 0x0056D130

void __fastcall sub_00553380_SendEvent(D2UnitStrc* unit,int event,D2UnitStrc* other); // 0x00553380

void __fastcall PLAYER_SetUniqueIdInPlayerData(D2UnitStrc* unit,int id); // 0x005353B0

void __fastcall OBJECTS_SetUnitIdInTimerArg(D2UnitStrc* unit,int id); // 0x00552AF0

D2UnitStrc* __fastcall SUNIT_GetPortalOwner(D2GameStrc* game,D2UnitStrc* unit); // 0x00553720

void __fastcall ACT5Q5_OnPortalOpened(D2GameStrc* game,D2UnitStrc* unit); // 0x0058CF00

D2ClientStrc* __fastcall sub_005531C0_GetClient(D2UnitStrc* unit,const char* file,int line,int type,int id); // 0x005531C0

void __fastcall sub_0053B3D0_SendByte(D2ClientStrc* client,unsigned char code); // 0x0053B3D0

int __stdcall ITEMS_GetBonusLifeBasedOnClass(D2UnitStrc*, int); // 0x0062A5D0

int __stdcall ITEMS_GetBonusManaBasedOnClass(D2UnitStrc*, int); // 0x0062A620

static inline int GetUnitType(D2UnitStrc* unit) { return unit?unit->dwUnitType:UNIT_INVALID; }

struct D2AiControlStrc;

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

struct D2SkillStrc;

struct D2StatListStrc;


enum D2C_G4Constants
{
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAGEX_TELEPORTED = 0x10000,
    UNITEVENTFLAG_IN_CALLBACK = 1,
    UNITEVENTFLAG_SHOULD_BE_FREED = 2,
    ITEMDROPFLAG_STAFFMODUSEILVL = 0x20,
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};



void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);           // 0x0040B430

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0);            // 0x0040B480

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);            // 0x00463740

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400

int __fastcall SKILLS_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5);   // 0x0056F640

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

void __stdcall ITEMS_AssignLegacyStaffMods(D2UnitStrc* pItem, int nItemLevel, int nClassFirstSkillId);                    // 0x005C0D70

void __stdcall ITEMS_AssignModernStaffMods(D2UnitStrc* pItem, int nItemLvl, int nClassFirstSkillId, int nItemDropLvl);   // 0x005C0F90

short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex); // 0x005C12F0

short __stdcall ITEMS_RollMagicAffixesNew(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup); // 0x005C1560

void __fastcall D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet);                   // 0x005C40D0

void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0

int __fastcall SKILLS_GetConvertedMode(D2UnitStrc* pUnit, int nMode);                                 // 0x005C6BF0

int __fastcall SKILLS_CreateMissileSpread(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int a7); // 0x005C7040

int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8CA0

int __fastcall SKILLS_StartInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5); // 0x005C8E30

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId);                       // 0x005D3CF0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId);                                           // 0x0061DB70

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit);                                               // 0x00620250

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0

void __stdcall UNITS_GetShiftedFrameMetrics(D2UnitStrc* pUnit, int* pFrameNo, int* pFrameCount);           // 0x00621810

int __stdcall UNITS_TestCollisionByCoordinates(D2UnitStrc* pUnit, int nX, int nY, int nCollisionMask);      // 0x006229F0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

unsigned short __stdcall ITEMS_GetItemFormat(D2UnitStrc* pItem);                                            // 0x0062A670

int __stdcall ITEMS_GetStaffMods(D2UnitStrc* pItem);                                                        // 0x0062BBD0

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId);         // 0x006439F0

void __stdcall SKILLS_SetSkillMode(D2SkillStrc* pSkill, int nMode);                                         // 0x00644340

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue);                                           // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

int __stdcall SKILLS_GetClassSkillId(int nClassId, int nPosition);                                          // 0x006460F0

int __stdcall SKILLS_GetPlayerSkillCount(int nClassId);                                                     // 0x00646140

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel);                       // 0x00663270

D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0

int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit);                                          // 0x006633D0

void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent);        // 0x006634C0

struct D2ModeChangeStrc;

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit); // 0x00541860

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nType, int nGUID); // 0x00552F60

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int nFlag1, int nFlag2); // 0x0058F030

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pMode, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pMode); // 0x005A7E60

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNode); // 0x005B1900

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330

void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x00620210

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pPath, unsigned char nStep); // 0x00649070

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nPattern, int nMask); // 0x0064EC10

enum D2C_SkillItemConstants
{
    UNITEVENT_13 = 13,
};

int __fastcall SKILLITEM_TimerCallback_ReanimateMonster(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2); // 0x005C07A0

D2UnitEventStrc* __fastcall SUNITEVENT_Register(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEvent, int nGUID1, int nGUID2, D2UnitEventCallbackFunction pCallback, unsigned int nQueueNo, int a8); // 0x005C0AD0

struct D2AffixIndexAndPtrStrc
{
    int nIndex;
    D2MagicAffixTxt* pAffix;
};

D2MagicAffixDataTbl* __stdcall DATATBLS_GetMagicAffixDataTables(); // 0x00633ED0

D2SeedStrc* __stdcall ITEMS_GetItemSeed(D2UnitStrc*); // 0x00627D90

int __stdcall ITEMS_GetItemLevel(D2UnitStrc*); // 0x006281E0

int __stdcall ITEMMODS_CanItemHaveMagicAffix(D2UnitStrc*, const D2MagicAffixTxt*); // 0x0065E620

int __fastcall sub_00472280(D2SeedStrc*, int, int); // 0x00472280

void __stdcall ITEMMODS_AssignProperty(int, D2UnitStrc*, D2UnitStrc*, const void*, int, int); // 0x0065FEC0

static inline int ClampLevel(int v) { if (v <= 1) return 1; if (v >= 99) return 99; return v; }

struct D2AiCmdStrc;

struct D2StaticPathStrc;

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE080

D2AiCmdStrc* __fastcall AIGENERAL_GetAiCommandFromParam(D2UnitStrc* pUnit, int nCmdParam, int bSet); // 0x0058EEF0

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*, int, int, int, unsigned short); // 0x0064D9B0

D2UnitStrc* __fastcall SKILLS_FindCorpseNearTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x0056E390

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

D2UnitStrc* __fastcall SUNIT_GetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553010

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

void __fastcall SUNITMSG_QueueItemSkillOnUnit(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, unsigned char nUnitType, int nUnitGUID, unsigned char a6); // 0x005717C0

int __fastcall SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int a7); // 0x005FDA80

struct D2MagicAffixTxt;


struct D2SkillPairStrc;

struct D2RareAffixIndexAndPtrStrc;

struct D2SetItemsTxt;


D2MagicAffixTxt* __stdcall DATATBLS_GetMagicAffixTxtRecord(int nIndex); // 0x00633EE0

struct D2SkillPairStrc
{
    int nA;
    int nB;
};

void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc*); // 0x004DC0B0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0

extern "C" void __stdcall sub_00627EF0(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0

extern "C" void __stdcall sub_00627FB0(D2UnitStrc* pItem, unsigned short nSuffix, int nSuffixNo); // 0x00627FB0

void __stdcall ITEMS_AssignRarePrefix(D2UnitStrc* pItem, unsigned short nPrefix); // 0x00628010

extern "C" void __stdcall sub_00628070(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070

int __stdcall sub_005C2740_RollLegacySetItem(D2UnitStrc* pItem); // 0x005C2740

void __stdcall ITEMS_SetFileIndex(D2UnitStrc* pItem, unsigned int dwFileIndex); // 0x00629DF0

int __fastcall ITEMS_ApplyLegacyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2AF0

int __fastcall ITEMS_ApplyLowQuality(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop); // 0x005C2D40

static int ITEMMODS_HasAffixWithGroup(D2UnitStrc* pItem, int nGroup);

// 0x005C0D00
static int __stdcall ITEMS_AddPotentialMagicAffix(int nAffixId, D2MagicAffixTxt* pRecord, D2MagicAffixIndexAndPtrStrc* pAffixes, int nCount)
{
    if (nCount < 0x1FF)
    {
        pAffixes[nCount].pMagicAffixRecord = pRecord;
        pAffixes[nCount].nAffixId = nAffixId;
        ++nCount;
    }

    return nCount;
}

int __stdcall sub_M11_Emit_005C0D00(D2UnitStrc* pItem, D2MagicAffixTxt* pFirst, int nRecords, int nBase)
{
    D2MagicAffixIndexAndPtrStrc tAffixes[0x200];
    int nCount = 0;
    for (int i = 0; i < nRecords; ++i)
    {
        D2MagicAffixTxt* pRecord = &pFirst[i];
        if (ITEMMODS_HasAffixWithGroup(pItem, pRecord->dwGroup))
        {
            continue;
        }

        nCount = ITEMS_AddPotentialMagicAffix(i + nBase, pRecord, tAffixes, nCount);
    }

    return nCount ? tAffixes[nCount - 1].nAffixId : 0;
}

// 0x005C0D20
static D2SkillPairStrc* __stdcall ITEMS_GetSkillPairEntry(int nCount, D2SkillPairStrc* pArray, int nIndex)
{
    if (nIndex >= nCount)
    {
        return 0;
    }
    return &pArray[nIndex];
}

D2SkillPairStrc* __stdcall sub_K13_Emit_005C0D20(D2SkillPairStrc* pArray, int nIndex, int nCount)
{
    return ITEMS_GetSkillPairEntry(nCount, pArray, nIndex);
}

// 0x005C0D40
static int __stdcall SKILLITEM_PercentWithMinimum(int nPercent, int nValue, int nMin)
{
    const int nResult = nValue * nPercent / 100;
    if (nResult < nMin)
    {
        return nMin;
    }
    return nResult;
}

int __stdcall sub_K13_Emit_005C0D40(int nValue, int nPercent)
{
    return SKILLITEM_PercentWithMinimum(nPercent, nValue, 2);
}

static inline unsigned int RollSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005C0D70
void __stdcall ITEMS_AssignLegacyStaffMods(D2UnitStrc* pItem, int nItemLevel, int nClassFirstSkillId)
{
    int nSkills[3] = { -1, -1, -1 };
    int nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
    int nSkillCount;
    if (nRoll > 90)
        nSkillCount = 3;
    else if (nRoll > 70)
        nSkillCount = 2;
    else if (nRoll > 30)
        nSkillCount = 1;
    else
        return;
    int nBaseTier = 1;
    if (nItemLevel > 24)
        nBaseTier = 4;
    else if (nItemLevel > 18)
        nBaseTier = 3;
    else if (nItemLevel > 11)
        nBaseTier = 2;
    for (int i = 0; i < nSkillCount; ++i)
    {
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        int nTier = nBaseTier;
        if (nRoll > 80)
            nTier = nBaseTier + 1;
        else if (nRoll <= 30)
        {
            if (nRoll > 10)
                nTier = nBaseTier - 1;
            else
                nTier = nBaseTier - 2;
        }
        nItemLevel = nTier;
        if (nItemLevel < 1)
            nItemLevel = 1;
        int nSkillId;
        do
        {
            const int nSkillRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 5;
            nSkillId = nClassFirstSkillId + 5 * (nItemLevel - 1) + nSkillRoll;
        }
        while (nSkillId == SKILL_POISONDAGGER || nSkillId == nSkills[0] || nSkillId == nSkills[1] || nSkillId == nSkills[2]);
        nSkills[i] = nSkillId;
        nItemLevel = 1;
        nRoll = RollSeed(ITEMS_GetItemSeed(pItem)) % 100;
        if (nRoll >= 90)
            nItemLevel = 3;
        else if (nRoll >= 60)
            nItemLevel = 2;
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pItem, 0, 0x40);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(sub_004DC0B0_GetUnitMemoryPool(pItem), 0x40, 0, 4, GAME_GetUnitGUID(pItem));
            D2COMMON_10475_PostStatToStatList(pItem, pStatList, 1);
        }
        if (pStatList)
            STATLIST_SetStatIfListIsValid(pStatList, STAT_ITEM_SINGLESKILL, nItemLevel, nSkillId);
    }
}

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

static inline D2SkillsTxt* GetSkillsRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}

// 0x005C0F90
void __stdcall ITEMS_AssignModernStaffMods(D2UnitStrc* pUnit, int nItemLvl, int nClassFirstSkillId, int nItemDropLvl)
{
    int skillIds[3] = { -1, -1, -1 };
    int nRand = nItemDropLvl + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
    int nCount = 0;
    if (nRand > 90)
    {
        nCount = 3;
    }
    else if (nRand > 70)
    {
        nCount = 2;
    }
    else if (nRand > 30 || nItemDropLvl)
    {
        nCount = 1;
    }
    else
    {
        return;
    }

    int nBase = 1;
    if (nItemLvl > 36 && ITEMS_GetItemFormat(pUnit) >= 100u)
    {
        nBase = 5;
    }
    else if (nItemLvl > 24)
    {
        nBase = 4;
    }
    else if (nItemLvl > 18)
    {
        nBase = 3;
    }
    else if (nItemLvl > 11)
    {
        nBase = 2;
    }

    for (int j = 0; j < nCount; ++j)
    {
        nRand = RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
        int nBaseLayer = 0;
        if (nRand > 80)
        {
            nBaseLayer = nBase + 1;
        }
        else if (nRand > 30)
        {
            nBaseLayer = nBase;
        }
        else if (nRand > 10)
        {
            nBaseLayer = nBase - 1;
        }
        else
        {
            nBaseLayer = nBase - 2;
        }

        if (nBaseLayer < 1)
        {
            nBaseLayer = 1;
        }

        if (ITEMS_GetItemQuality(pUnit) == 1 && nBaseLayer >= 4)
        {
            nBaseLayer = 4;
        }

        int nSkillId;
        int nTries = 6;
        do
        {
            const int nRoll = RollSeed(ITEMS_GetItemSeed(pUnit)) % 5;
            nSkillId = nRoll + 5 * (nBaseLayer - 1) + nClassFirstSkillId;

            D2SkillsTxt* pSkillsTxtRecord = GetSkillsRecord(nSkillId);
            if (!pSkillsTxtRecord || pSkillsTxtRecord->nITypeA[0] <= 0 || ITEMSIsA(pUnit, pSkillsTxtRecord->nITypeA[0]))
            {
                if (nSkillId != skillIds[0] && nSkillId != skillIds[1] && nSkillId != skillIds[2])
                {
                    skillIds[j] = nSkillId;
                    break;
                }
                --nTries;
            }
            else
            {
                --nTries;
            }
        }
        while (nTries > 0);

        int nValue = 1;
        if (ITEMS_GetItemFormat(pUnit) < 100u || ITEMS_GetItemQuality(pUnit) != 1)
        {
            nRand = nItemDropLvl / 2 + RollSeed(ITEMS_GetItemSeed(pUnit)) % 100;
            if (nRand >= 90)
            {
                nValue = 3;
            }
            else if (nRand >= 60)
            {
                nValue = 2;
            }
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40u);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(sub_004DC0B0_GetUnitMemoryPool(pUnit), 0x40u, 0, 4, GAME_GetUnitGUID(pUnit));
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }

        if (pStatList)
        {
            STATLIST_SetStatIfListIsValid(pStatList, STAT_ITEM_SINGLESKILL, nValue, nSkillId);
        }
    }
}

// 0x005C1260
void __fastcall ITEMS_AssignStaffModsForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    const int nClassId = ITEMS_GetStaffMods(pItem);
    if (nClassId < 0 || nClassId >= NUMBER_OF_PLAYERCLASSES)
    {
        return;
    }

    if (SKILLS_GetPlayerSkillCount(nClassId) <= 0)
    {
        return;
    }

    const int nSkillId = SKILLS_GetClassSkillId(nClassId, 0);
    const int nItemLevel = pItemDrop->nItemLvl;
    if (!ITEMS_GetItemFormat(pItem))
    {
        ITEMS_AssignLegacyStaffMods(pItem, nItemLevel, nSkillId);
    }
    else
    {
        ITEMS_AssignModernStaffMods(pItem, nItemLevel, nSkillId, pItemDrop->dwFlags2 & ITEMDROPFLAG_STAFFMODUSEILVL ? pItemDrop->nItemLvl : 0);
    }
}

// 0x005C12F0
short __stdcall ITEMS_RollMagicAffixesOld(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    D2AffixIndexAndPtrStrc tAffixes[512];
    D2MagicAffixDataTbl* pTable = DATATBLS_GetMagicAffixDataTables();
    if (!pTable) return 0;
    D2MagicAffixTxt* pRecord;
    int nCount;
    if (bPrefix) { pRecord = pTable->pMagicPrefix; nCount = pTable->pAutoMagic - pRecord; }
    else { pRecord = pTable->pMagicSuffix; nCount = pTable->pMagicPrefix - pRecord; }
    if (!pRecord) return 0;
    const int nFirstIndex = pRecord - pTable->pMagicAffixTxt;
    int nIndex = -1;
    int nMax = 0;
    const unsigned int nRoll = RollSeed(ITEMS_GetItemSeed(pItem));
    const unsigned short nFormat = ITEMS_GetItemFormat(pItem);
    if ((nRoll & 1) || bForceAffixRoll)
    {
        int nLevel = ITEMS_GetItemLevel(pItem) + 2;
        nLevel = D2_MIN(D2_MAX(nLevel, 1), 99);
        for (int i = 0; i < nCount; ++i)
        {
            if ((!bRequireSpawnableAffix || pRecord[i].bSpawnable) && (pRecord[i].wVersion < 100 || nFormat >= 100) && pRecord[i].nLevel <= nLevel && ITEMMODS_CanItemHaveMagicAffix(pItem, &pRecord[i]) && nMax < 511)
            {
                tAffixes[nMax].pAffix = &pRecord[i];
                tAffixes[nMax].nIndex = nFirstIndex + i;
                ++nMax;
            }
        }
        if (nMax <= 0) return 0;
        const int nRandom = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
        if (nRandom >= nMax) return 0;
        D2AffixIndexAndPtrStrc* pAffix = &tAffixes[nRandom];
        if (!pAffix) return 0;
        nIndex = pAffix->nIndex;
        if (nPreferredAffixIndex > 0)
        {
            nPreferredAffixIndex += nFirstIndex;
            if (nPreferredAffixIndex > 0)
            {
                for (int i = 0; i < nMax; ++i)
                {
                    D2AffixIndexAndPtrStrc* pCurrent = &tAffixes[i];
                    if (pCurrent->nIndex == nPreferredAffixIndex - 1)
                    {
                        nIndex = pCurrent->nIndex;
                        pAffix = pCurrent;
                        goto ApplyProperties;
                    }
                }
                nIndex = -1;
            }
        }
ApplyProperties:
        if (bAssignProperties) ITEMMODS_AssignProperty(0, 0, pItem, pAffix->pAffix, 0, 0);
    }
    return nIndex + 1;
}

// build: symbol ?ITEMS_RollMagicAffixes@@YIGPAUD2UnitStrc@@HHHHH@Z 0x005C18E0
unsigned short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

// build: symbol ?ITEMS_RollMagicAffixes@@YIFPAUD2UnitStrc@@HHHHHH@Z 0x005C1940
short __fastcall ITEMS_RollMagicAffixes(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefixes, int nPreferredAffixIndex, int nAutoMagicGroup)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex, nAutoMagicGroup);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefixes, nPreferredAffixIndex);
}

// 0x005C1500
static int ITEMMODS_HasAffixWithGroup(D2UnitStrc* pItem, int nGroup)
{
    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    for (int i = 0; i < 3; ++i)
    {
        D2MagicAffixTxt* pAffix = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, i));
        if (!pAffix)
        {
            break;
        }

        if (pAffix->dwGroup == nGroup)
        {
            return 1;
        }
    }

    return 0;
}

// 0x005C19A0
static unsigned short __stdcall SKILLITEM_RollRareAffixLegacy(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            tAffixes[nMax].nIndex = nAffixIndex + i;
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

// 0x005C1AB0
static unsigned short __stdcall SKILLITEM_RollRareAffix(D2UnitStrc* pItem, int bPrefix)
{
    D2RareAffixIndexAndPtrStrc tAffixes[512];

    D2RareAffixDataTbl* pRareAffixDataTbl = DATATBLS_GetRareAffixDataTables();
    D2RareAffixTxt* pRareAffixTxtRecord = 0;
    if (bPrefix)
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        pRareAffixTxtRecord = pRareAffixDataTbl->pRareSuffix;
    }

    if (!pRareAffixTxtRecord)
    {
        return 0;
    }

    const int nAffixIndex = pRareAffixTxtRecord - pRareAffixDataTbl->pRareAffixTxt;
    int nCount = 0;
    if (bPrefix)
    {
        nCount = &pRareAffixDataTbl->pRareAffixTxt[pRareAffixDataTbl->nRareAffixTxtRecordCount] - pRareAffixDataTbl->pRarePrefix;
    }
    else
    {
        nCount = pRareAffixDataTbl->pRarePrefix - pRareAffixDataTbl->pRareSuffix;
    }

    int nMax = 0;
    for (int i = 0; i < nCount; ++i)
    {
        if (ITEMMODS_CanItemHaveRareAffix(pItem, &pRareAffixTxtRecord[i]) && nMax < 511)
        {
            tAffixes[nMax].pRareAffixRecord = &pRareAffixTxtRecord[i];
            tAffixes[nMax].nIndex = nAffixIndex + i;
            ++nMax;
        }
    }

    if (!nMax)
    {
        return 0;
    }

    const int nIndex = sub_00472280(ITEMS_GetItemSeed(pItem), 0, nMax);
    if (nIndex >= nMax)
    {
        return 0;
    }

    D2RareAffixIndexAndPtrStrc* pAffix = &tAffixes[nIndex];
    if (!pAffix)
    {
        return 0;
    }

    return pAffix->nIndex + 1;
}

// 0x005C1BC0
unsigned short __fastcall ITEMS_RollTemperedItemAffix(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return SKILLITEM_RollRareAffix(pItem, bPrefix);
    }

    return SKILLITEM_RollRareAffixLegacy(pItem, bPrefix);
}

void __stdcall ITEMS_AssignPrefix(D2UnitStrc* pItem, unsigned short nPrefix, int nPrefixNo); // 0x00627EF0

void __stdcall ITEMS_AssignRareSuffix(D2UnitStrc* pItem, unsigned short nSuffix); // 0x00628070

int __stdcall ITEMS_GetItemType(D2UnitStrc* pItem); // 0x0062B400

extern const int gnRareAffixCounts[]; // 0x006E3014

static inline unsigned short D2GAME_RollRareAffixInline(D2UnitStrc* pItem, int bPrefix)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return SKILLITEM_RollRareAffix(pItem, bPrefix);
    }

    return SKILLITEM_RollRareAffixLegacy(pItem, bPrefix);
}

static __forceinline void ITEMS_ApplyRareAffixesInline(D2UnitStrc* pItem)
{
    ITEMS_SetItemFlag(pItem, 0x10, 0);

    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        if (D2MagicAffixTxt* pPrefixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetPrefixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pPrefixRecord, 0, 0);
        }

        if (D2MagicAffixTxt* pSuffixRecord = DATATBLS_GetMagicAffixTxtRecord(ITEMS_GetSuffixId(pItem, nAffixSlot)))
        {
            ITEMMODS_AssignProperty(0, 0, pItem, pSuffixRecord, 0, 0);
        }
    }
}

static inline unsigned int sub_RareSeedRoll(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int sub_RareSeedRollLimited(D2SeedStrc* pSeed, int nMax)
{
    if (nMax > 0)
    {
        if ((nMax - 1) & nMax)
        {
            return sub_RareSeedRoll(pSeed) % nMax;
        }
        else
        {
            return sub_RareSeedRoll(pSeed) & (nMax - 1);
        }
    }

    return 0;
}

// 0x005C1BF0
static int __stdcall sub_005C1BF0_RollRareItemNew(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int bSuffixesDone = 0;
    int bPrefixesDone = 0;

    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    ITEMS_AssignRareSuffix(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    int nAffixCount = 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_JEWEL)
    {
        nAffixCount = sub_00472280(pSeed, 3, 2);
    }
    else
    {
        nAffixCount = gnRareAffixCounts[sub_RareSeedRollLimited(pSeed, 8)];
    }

    for (int i = 0; i < nAffixCount; ++i)
    {
        if (bPrefixesDone && bSuffixesDone)
        {
            break;
        }

        int bSuffix;
        if (bPrefixesDone)
        {
            bSuffix = 1;
        }
        else if (bSuffixesDone)
        {
            bSuffix = 0;
        }
        else
        {
            bSuffix = sub_RareSeedRoll(pSeed) & 1;
        }

        if (!bSuffix)
        {
            D2_ASSERT(nPrefixes < 3, 0x31D);

            const unsigned short nPrefix = ITEMS_RollMagicAffixesNew(pItem, 1, 1, 0, 1, pItemDrop->nPrefix[nPrefixes], 0);
            if (nPrefix > 0)
            {
                ITEMS_AssignPrefix(pItem, nPrefix, nPrefixes);
                ++nPrefixes;
                if (nPrefixes >= 3)
                {
                    bPrefixesDone = 1;
                }
            }
            else
            {
                bPrefixesDone = 1;
                --i;
            }
        }
        else
        {
            D2_ASSERT(nSuffixes < 3, 0x32E);

            const unsigned short nSuffix = ITEMS_RollMagicAffixesNew(pItem, 1, 1, 0, 0, pItemDrop->nSuffix[nSuffixes], 0);
            if (nSuffix > 0)
            {
                ITEMS_AssignSuffix(pItem, nSuffix, nSuffixes);
                ++nSuffixes;
                if (nSuffixes >= 3)
                {
                    bSuffixesDone = 1;
                }
            }
            else
            {
                bSuffixesDone = 1;
                --i;
            }
        }
    }

    if (!nPrefixes && !nSuffixes)
    {
        return 0;
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}

static int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem); // 0x005C1E80

static __forceinline bool ITEMS_HasAffixOrGroupInline(D2UnitStrc* pItem, unsigned short nAffix, int bPrefix)
{
    for (int nAffixSlot = 0; nAffixSlot < 3; ++nAffixSlot)
    {
        const unsigned short nSlotAffix = bPrefix ? ITEMS_GetPrefixId(pItem, nAffixSlot) : ITEMS_GetSuffixId(pItem, nAffixSlot);
        if (D2MagicAffixTxt* pSlotRecord = DATATBLS_GetMagicAffixTxtRecord(nSlotAffix))
        {
            D2MagicAffixTxt* pAffixRecord = DATATBLS_GetMagicAffixTxtRecord(nAffix);
            if (nAffix == nSlotAffix || pAffixRecord->dwGroup == pSlotRecord->dwGroup)
            {
                return true;
            }
        }
    }

    return false;
}

static inline short ITEMS_RollMagicAffixesInline(D2UnitStrc* pItem, int bRequireSpawnableAffix, int bForceAffixRoll, int bAssignProperties, int bPrefix, int nPreferredAffixIndex)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_RollMagicAffixesNew(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex, 0);
    }

    return ITEMS_RollMagicAffixesOld(pItem, bRequireSpawnableAffix, bForceAffixRoll, bAssignProperties, bPrefix, nPreferredAffixIndex);
}

// 0x005C1E80
static int __stdcall ITEMS_RollLegacyRareItem(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    ITEMS_AssignRareSuffix(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    unsigned int nAffixCount = 0;
    if (ITEMS_GetItemType(pItem) == ITEMTYPE_JEWEL)
    {
        nAffixCount = sub_00472280(pSeed, 3, 2);
    }
    else
    {
        nAffixCount = sub_00472280(pSeed, 4, 3);
    }

    for (unsigned int i = 0; i < nAffixCount; ++i)
    {
        int bSuffix = sub_RareSeedRoll(pSeed) & 1;
        if (nPrefixes == 3)
        {
            bSuffix = 1;
        }
        else if (nSuffixes == 3)
        {
            bSuffix = 0;
        }

        if (!bSuffix)
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nPrefix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 1, 0);
                if (nPrefix <= 0)
                {
                    break;
                }

                if (ITEMS_HasAffixOrGroupInline(pItem, nPrefix, 1))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignPrefix(pItem, 0, nPrefixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignPrefix(pItem, nPrefix, nPrefixes);
                    ++nPrefixes;
                    break;
                }
            }
        }
        else
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nSuffix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 0, 0);
                if (nSuffix <= 0)
                {
                    break;
                }

                if (ITEMS_HasAffixOrGroupInline(pItem, nSuffix, 0))
                {
                    if (nAttempt++ > 250)
                    {
                        ITEMS_AssignSuffix(pItem, 0, nSuffixes);
                        break;
                    }
                }
                else
                {
                    ITEMS_AssignSuffix(pItem, nSuffix, nSuffixes);
                    ++nSuffixes;
                    break;
                }
            }
        }
    }

    if (!nPrefixes && !nSuffixes)
    {
        return 0;
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}

// 0x005C21A0
int __fastcall D2GAME_RollRareItem_6FC53360(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (!ITEMS_CanBeRare(pItem))
    {
        return 0;
    }

    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C1BF0_RollRareItemNew(pItemDrop, pItem);
    }

    return ITEMS_RollLegacyRareItem(pItemDrop, pItem);
}

// 0x005C21D0
int __fastcall ITEMS_RollCraftedItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    const unsigned short nRarePrefix = D2GAME_RollRareAffixInline(pItem, 1);
    const unsigned short nRareSuffix = D2GAME_RollRareAffixInline(pItem, 0);
    if (!nRarePrefix || !nRareSuffix)
    {
        return 0;
    }

    ITEMS_AssignRarePrefix(pItem, nRarePrefix);
    sub_00628070(pItem, nRareSuffix);

    int nPrefixes = 0;
    int nSuffixes = 0;
    D2SeedStrc* pSeed = ITEMS_GetItemSeed(pItem);

    const int nItemLvl = pItemDrop->nItemLvl;
    int nMinAffixes = 1;
    if (nItemLvl > 30)
    {
        nMinAffixes = 2;
    }
    if (nItemLvl > 50)
    {
        nMinAffixes = 3;
    }
    if (nItemLvl > 70)
    {
        nMinAffixes = 4;
    }

    unsigned int nAffixCount = sub_RareSeedRollLimited(pSeed, 5);
    if ((unsigned int)nMinAffixes > nAffixCount)
    {
        nAffixCount = nMinAffixes;
    }

    for (unsigned int i = 0; i < nAffixCount; ++i)
    {
        int bSuffix = sub_RareSeedRoll(pSeed) & 1;
        if (nPrefixes == 3)
        {
            bSuffix = 1;
        }
        else if (nSuffixes == 3)
        {
            bSuffix = 0;
        }

        if (!bSuffix)
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nPrefix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 1, pItemDrop->nPrefix[nPrefixes]);
                if (ITEMS_HasAffixOrGroupInline(pItem, nPrefix, 1))
                {
                    if (nAttempt++ > 250)
                    {
                        sub_00627EF0(pItem, 0, nPrefixes);
                        break;
                    }
                }
                else
                {
                    sub_00627EF0(pItem, nPrefix, nPrefixes);
                    ++nPrefixes;
                    break;
                }
            }
        }
        else
        {
            int nAttempt = 0;
            while (1)
            {
                const unsigned short nSuffix = ITEMS_RollMagicAffixesInline(pItem, 1, 1, 0, 0, pItemDrop->nSuffix[nSuffixes]);
                if (ITEMS_HasAffixOrGroupInline(pItem, nSuffix, 0))
                {
                    if (nAttempt++ > 250)
                    {
                        sub_00627FB0(pItem, 0, nSuffixes);
                        break;
                    }
                }
                else
                {
                    sub_00627FB0(pItem, nSuffix, nSuffixes);
                    ++nSuffixes;
                    break;
                }
            }
        }
    }

    ITEMS_ApplyRareAffixesInline(pItem);
    ITEMS_AssignStaffModsForFormat(pItem, pItemDrop);
    return 1;
}

int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll); // 0x005C2540

struct D2BookDataTbl;


D2BookDataTbl* __fastcall DATATBLS_GetBookDataTables(); // 0x006374A0

// 0x005C2540
int __fastcall ITEMS_FindBookRecordIndex(D2UnitStrc* pItem, int bScroll)
{
    D2BookDataTbl* pBookDataTbl = DATATBLS_GetBookDataTables();
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(!pItem ? -1 : pItem->dwClassId);
    if (!pBookDataTbl)
    {
        return -1;
    }

    if (!pItemsTxtRecord)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    if (!pBookDataTbl->pBooksTxt)
    {
        return pBookDataTbl->nBooksTxtRecordCount;
    }

    int nIndex = -1;
    for (int i = 0; i < pBookDataTbl->nBooksTxtRecordCount; ++i)
    {
        if (bScroll)
        {
            if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwScrollSpellCode)
            {
                nIndex = i;
                break;
            }
        }
        else if (pItemsTxtRecord->dwCode == pBookDataTbl->pBooksTxt[i].dwBookSpellCode)
        {
            nIndex = i;
            break;
        }
    }

    if (nIndex < 0)
    {
        nIndex = pBookDataTbl->nBooksTxtRecordCount;
    }
    return nIndex;
}

static int __stdcall sub_005C25C0_RollSetItemRecord(D2ItemDropStrc* pItemDrop, D2UnitStrc* pItem)
{
    int nLegibleSets = 0;
    int nAccumulatedRarity = 0;
    int nIndex = -1;
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pItem ? pItem->dwClassId : -1);
    if (!pItemsTxtRecord)
    {
        return 0;
    }

    const int nItemFormat = ITEMS_GetItemFormat(pItem);
    const unsigned int dwCode = pItemsTxtRecord->dwCode;
    const int nItemLevel = ITEMS_GetItemLevel(pItem);
    int rarityData[512];

    for (int i = 0; i < sgptDataTables->nSetItemsTxtRecordCount; ++i)
    {
        D2SetItemsTxt* pSetItemsTxtRecord = &sgptDataTables->pSetItemsTxt[i];
        if ((pSetItemsTxtRecord->wVersion < 100 || nItemFormat >= 100) && pSetItemsTxtRecord->wLvl <= nItemLevel
            && dwCode == pSetItemsTxtRecord->dwItemCode
            && (pSetItemsTxtRecord->nSetId != 29 || pItemDrop->dwFlags2 & 1))
        {
            if (pItemDrop->nItemIndex && pItemDrop->nItemIndex - 1 == i)
            {
                nIndex = i;
            }

            rarityData[2 * nLegibleSets] = i;
            rarityData[2 * nLegibleSets + 1] = pSetItemsTxtRecord->dwRarity;
            if (!pSetItemsTxtRecord->dwRarity)
            {
                rarityData[2 * nLegibleSets + 1] = 1;
            }

            nAccumulatedRarity += rarityData[2 * nLegibleSets + 1];
            ++nLegibleSets;
        }
    }

    int nFileIndex = nIndex;
    if (nIndex < 0)
    {
        if (!nAccumulatedRarity)
        {
            return 0;
        }

        int nChance = ITEMS_RollLimitedRandomNumber(ITEMS_GetItemSeed(pItem), nAccumulatedRarity);
        int nCounter = 0;
        while (nCounter < nLegibleSets)
        {
            if (nChance < rarityData[2 * nCounter + 1])
            {
                break;
            }

            nChance -= rarityData[2 * nCounter + 1];
            ++nCounter;
        }

        if (nCounter < 0 || nCounter >= nLegibleSets)
        {
            return 0;
        }

        nFileIndex = rarityData[2 * nCounter];
    }

    ITEMS_SetFileIndex(pItem, nFileIndex);
    ITEMS_SetItemFlag(pItem, 0x10, 0);
    ITEMMODS_AssignProperty(4, 0, pItem, 0, 0, 0);
    return 1;
}

// 0x005C2940
int __fastcall ITEMS_RollSetItem(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return sub_005C25C0_RollSetItemRecord(pItemDrop, pItem);
    }

    return sub_005C2740_RollLegacySetItem(pItem);
}

// 0x005C2FB0
int __fastcall ITEMS_ApplyLowQualityForFormat(D2UnitStrc* pItem, D2ItemDropStrc* pItemDrop)
{
    if (ITEMS_GetItemFormat(pItem) >= 1u)
    {
        return ITEMS_ApplyLowQuality(pItem, pItemDrop);
    }

    return ITEMS_ApplyLegacyLowQuality(pItem, pItemDrop);
}

// 0x005C2FE0
int __cdecl sub_005C2FE0()
{
    return 43;
}

// 0x005C2FF0
void __fastcall SKILLS_DamagePaladinCaster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwClassId == PCLASS_PALADIN)
    {
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);

        D2DamageStrc damage;
        memset(&damage, 0x00, sizeof(damage));

        damage.dwHitFlags |= 0x1000;
        damage.wResultFlags |= 4;
        damage.dwPhysDamage = nMaxHp / 8;
        damage.dwDmgTotal = nMaxHp / 8;

        SUNITDMG_ExecuteEvents(pGame, pUnit, pUnit, 0, &damage);
        SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pUnit, &damage);
    }
}


#include "gen/data/Source/D2Game/Unknown_005C0D00.inc"
