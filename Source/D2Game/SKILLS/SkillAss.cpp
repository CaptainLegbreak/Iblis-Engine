#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Path.h"
#include "D2GameStrc.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2GameRecords.h"
#include "D2LevelTxt.h"
#include "D2LanguageNames.h"

struct D2StatListStrc;

struct D2UnitStrc;

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

#define PATHTYPE_CHARGEDBOLT 10

#define MAX(a, b) ((a) > (b) ? (a) : (b))

#define MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2StaticPathStrc;

struct D2MonsterDataStrc;

struct D2CurseStrc;

struct D2UnitFindArgStrc;

struct D2AuraCallbackStrc;

struct D2SrvDo47Strc;

struct D2SrvDo51Strc;

struct D2SrvDo142Strc;

struct D2MonStats2Txt;

struct D2AiCmdStrc;

struct D2SkillsTxt;

union D2SeedStrc;

struct D2MonEquipTxt;

struct D2MonsterItemCodeStrc;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

struct D2SrvDo51Strc
{
    D2DamageStrc* pDamage;
    int nMonCurseResSubstraction;
    int nParam1;
    int nParam2;
};

struct D2SrvDo142Strc
{
    D2DamageStrc* pDamage;
    int nToHit;
    unsigned short nResultFlags;
    unsigned short unk0x0A;
    unsigned int nHitFlags;
    unsigned char nSrcDam;
    unsigned char unk0x11;
    unsigned short unk0x12;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall STATLIST_GetSkillId(D2StatListStrc* pStatList); // 0x006260E0

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnLevelVariantAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B2490

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

D2StatListStrc* __fastcall SKILLS_ApplyTimedState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nState, int nSkillId, int nSkillLevel); // 0x00570590

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall SKILLS_EnlargeVector(int* pX, int* pY); // 0x0056D370

void __fastcall SKILLS_MakeShortPerpendicularVector(int* pX, int* pY); // 0x0056D3B0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall SUNITMSG_QueueSkillEvent(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __fastcall SKILLS_ApplyAreaEffect(D2GameStrc* pGame, D2EffectStrc* pEffect); // 0x0056DCC0

int __fastcall SKILLS_AreaEffect_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel, int nUnused); // 0x005D2E50

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, int a7, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData); // 0x0065AA00

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20

void __fastcall SKILLS_ApplyDamageToTarget(D2GameStrc* pGame, D2UnitStrc* pAttackerArg, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nUnused); // 0x0056B9C0

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3DA0

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int (__fastcall* pCallback)(D2AuraCallbackStrc*, D2UnitStrc*), void* pArgs, int a9, const char* szFile, int nLine); // 0x0056B7E0

void __fastcall SKILLS_CurseStateCallback_ResetAi(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3370

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

int __fastcall SKILLS_CanSwitchAi(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620

D2UnitStrc* __fastcall SKILLS_SummonSkillMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005D5E10

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __fastcall AIGENERAL_CopyAiCommand(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058EF40

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760

int __fastcall SKILLS_AuraCallback_MindBlast(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D7680

int __fastcall SKILLS_AuraCallback_AllocSkillCombat(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D7C40

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

D2UnitStrc* __fastcall PLAYER_GetWeaponForSkill(D2UnitStrc* pUnit); // 0x00535BC0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboredRooms); // 0x0064E7B0

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nSrcDam); // 0x0057DBF0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

int __fastcall UNITS_GetWeaponClass(D2UnitStrc* pUnit); // 0x00623C60

void __fastcall SKILLS_AddDamagePercentBonus(D2UnitStrc* pUnit, int nBonus); // 0x005DB6A0

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __fastcall SKILLS_MissileInit_SeededChargedBolt(D2UnitStrc* pMissile, int nInitSeed);

void __fastcall SKILLS_MissileInit_CurvingPath(D2UnitStrc* pMissile, int nInitSeed); // 0x005D4680

static void __stdcall SKILLS_CreateChargedBoltMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, int nLowSeed); // 0x005D4150

void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3AC0

void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0

void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005D3BA0

struct D2MonEquipTxt
{
    short nMonster;
    short wLevel;
    unsigned char nOnInit;
    char unk0x05[3];
    unsigned int dwItem[3];
    char nLoc[3];
    char nMod[3];
    char unk0x1A[2];
};

struct D2MonsterItemCodeStrc
{
    unsigned int nItemCode;
    unsigned char nBodyLoc;
    unsigned char unk0x05;
};

typedef char D2MonEquipTxt_size_check[sizeof(D2MonEquipTxt) == 0x1C ? 1 : -1];

typedef char D2UnitStrc_inventory_check[(int)&((D2UnitStrc*)0)->pInventory == 0x60 ? 1 : -1];

D2MonEquipTxt* __fastcall SKILLITEM_GetMonEquipTxtRecord(int nMonsterId); // 0x005D30A0

unsigned int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem); // 0x00628590

void __fastcall MONSTERAI_CreateAndEquipItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MonsterItemCodeStrc* pItemCode, int nItemLevel, int nMod); // 0x00573B20

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit); // 0x0056E580

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

void __fastcall SKILLS_StatRemoveCallback_MindBlast(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005D7310

typedef int (__fastcall *SkillDoFunc)(D2GameStrc*, D2UnitStrc*, int, int);

extern const int gnSkillSrvDoFnCount; // 0x006E1274

extern SkillDoFunc gpfnSkillSrvDoFunctions[]; // 0x007322B0

unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc*); // 0x0045C370

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int); // 0x0045C4B0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc*, D2UnitStrc*, int); // 0x00622C40

int __stdcall UNITS_IsInMovingMode(D2UnitStrc*); // 0x00622D00

void __stdcall STATES_UpdatePgsvFlags(D2UnitStrc*); // 0x0063A2D0

void __fastcall sub_00650E60(D2SeedStrc*, unsigned int, unsigned int); // 0x00650E60

void __fastcall sub_00650E70(D2SeedStrc*, unsigned int*, unsigned int*); // 0x00650E70

#define BURST_CENTER 20

#define MISSILE_FLAGS 3

struct D2GameStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed);                                                 // 0x00650E50

struct D2MonStatsTxt;

struct D2LevelsTxt;

int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647BC0

int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647D00

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

void __fastcall SKILLS_RewindUnitAnimation(D2UnitStrc* pUnit, int nArg); // 0x0056E210

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

int __fastcall SKILLS_AuraCallback_CloakOfShadows(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D6520

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

enum D2C_Z09St26Constants
{
    EVENTTYPE_REMOVESTATE = 0x0C,
};

void __fastcall SUNIT_RewindAnimationByFrames(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x00553C70

int __fastcall SKILLS_SrvDo048_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D68A0

int __fastcall SKILLS_ConsumeSkillMana(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel); // 0x0056BFE0

void __fastcall SKILLS_StatRemoveCallback_BladeFury(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005D69B0

struct D2SummonArgStrc;

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850

D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940

int __fastcall SKILLDESC_GetSummonLevel(int nSkillId, int nSkillLevel); // 0x004EFCB0

int __stdcall DATATBLS_GetMaxLevel(int nClass); // 0x00611830

void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nLevel, int a7); // 0x005D6B60

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

#define SKILLSFLAGINDEX_INTOWN 8

struct D2PathPointStrc;

struct D2ModeChangeStrc;

extern int gnSrvChargedBoltTurnEvery; // 0x00741B0C

extern int gnSrvChargedBoltTurnBase; // 0x00741B10

extern const int gnCurvingPathOffsetY[]; // 0x006E328C

extern const int gnCurvingPathOffsetX[]; // 0x006E32AC

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

void __stdcall PATH_SetNumberOfPathPoints(D2DynamicPathStrc* pPath, int nPoints); // 0x00648790

int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pPath, D2PathPointStrc** ppPathPoints); // 0x006487D0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pPath, int nDistance); // 0x00648E70

D2UnitStrc* __fastcall sub_0059FA30_CreateMissile(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

static void __stdcall SKILLS_FillKickDamage(D2GameStrc* pGame, D2DamageStrc* pDamage, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit);

static void __stdcall SKILLS_AllocDragonTalonCombat(D2GameStrc* pGame, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecordArg, int nSkillLevel, int bKnockback, int nSkillId, D2UnitStrc* pUnit);

int __fastcall SKILLS_SrvSt24_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

int __fastcall SKILLS_SrvDo042_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

int __fastcall SKILLS_SrvDo052_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

int __fastcall SKILLS_SrvSt27_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

struct D2ActiveRoomStrc;

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct Skills;

struct Unit
{
    char pad0[0xC4];
    unsigned flags;
};

struct Skills
{
    char pad0[0xE6];
    short overlay;
    char padE8[0x154];
};

struct Tables
{
    char pad0[0xB98];
    Skills* skills;
    void* linker;
    int skillCount;
    char padBA4[0x1C];
    int overlayCount;
};

int __stdcall SKILLS_GetParam1(Skill*); // 0x006444A0

int __stdcall SKILLS_GetParam2(Skill*); // 0x006444D0

int __stdcall SKILLS_GetParam3(Skill*); // 0x00644500

int __stdcall SKILLS_GetParam4(Skill*); // 0x00644530

Room* __fastcall sub_00463740(Room*,int,int); // 0x00463740

Unit* __fastcall D2GAME_SpawnMonster_6FC69F10(Game*,Room*,int,int,int,int,int,int); // 0x005B2F20

void __stdcall UNITS_StoreOwner(Unit*,Unit*); // 0x00621CE0

void __stdcall UNITS_SetOverlay(Unit*,int,int); // 0x00621E40

enum { MINION_FLAGS = 0x4020000 };

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

void __stdcall D2Common_10235_PATH_UpdateRiderPath(D2UnitStrc* pRiderUnit, D2UnitStrc* pMountUnit); // 0x006505E0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

void __fastcall AITACTICS_Idle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nFrames); // 0x005DE0F0

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_PROGRESSIVE = 2,
};

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0

void __stdcall SKILLS_ApplyProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3790

void __stdcall SKILLS_ApplyProgressiveElementalDamage(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3880

static int __stdcall SKILLS_AddProgressiveCharge(D2GameStrc* pGame, int nSkillId, int nSkillLevel, int nAuraState, int nAuraStat, D2UnitStrc* pUnit);

int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3490

D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nUnitSize); // 0x005D2F80

int __stdcall STATLIST_GetSkillId(D2StatListStrc* pStatList); // 0x006260E0

void __stdcall SKILLS_ApplyProgressiveElementalConversion(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage); // 0x005D3970

// volatile only reproduces the original reloading the table pointer at each access in this loop
#define VOLATILE_DATATABLES (*(D2DataTablesStrc* volatile*)&sgptDataTables)

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

static int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

inline int SKILLS_GetLinearParam45(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[4] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[5];
}

inline int SKILLS_GetParam3FromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[2];
}

inline int SKILLS_GetParam4FromSkillId(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

// 0x005D21B0
void __fastcall SKILLS_RemovePregnantStateAndSpawnMonster(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nStateId, 0);

    int nSummonId = 551;
    int nMonMode = 1;
    if (pStatList)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(STATLIST_GetSkillId(pStatList));
        if (pSkillsTxtRecord)
        {
            if (pSkillsTxtRecord->wSummon > 0 && pSkillsTxtRecord->wSummon < sgptDataTables->nMonStatsTxtRecordCount)
            {
                nSummonId = pSkillsTxtRecord->wSummon;
            }

            if ((signed char)pSkillsTxtRecord->nSumMode >= 0 && (signed char)pSkillsTxtRecord->nSumMode < 16)
            {
                nMonMode = (signed char)pSkillsTxtRecord->nSumMode;
            }
        }
    }

    if (SUNIT_IsDead(pUnit))
    {
        MONSTERSPAWN_SpawnLevelVariantAtUnit(SUNIT_GetGameFromUnit(pUnit), pUnit, nSummonId, nMonMode, 1, 0);
    }
}

// 0x005D2250
int __fastcall SKILLS_SrvDo133_Impregnate(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!sub_6FD01910(pUnit, pTarget))
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nStat = -1;
    curse.nState = 110;
    curse.pStateRemoveCallback = SKILLS_RemovePregnantStateAndSpawnMonster;
    SKILLS_ApplyStateEffect(&curse);
    return 1;
}

// 0x005D2320
int __fastcall SKILLS_SrvDo134_SiegeBeastStomp(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwHitFlags |= 1;
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    if (pSkillsTxtRecord->dwHitClass)
    {
        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    }

    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_ApplyAreaDamage(pGame, pUnit, 0, 0, nRange, &damage, 0);
    return 1;
}

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620

// 0x005D2420
int __fastcall SKILLS_SrvSt62_MinionSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nSpawnMode;
    int nX;
    int nY;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 1, nSkillId, nSkillLevel, &nSpawnMode, &nX, &nY);
    SKILLS_SetParam1(pSkill, nSummonId);
    SKILLS_SetParam2(pSkill, nX);
    SKILLS_SetParam3(pSkill, nY);
    SKILLS_SetParam4(pSkill, nSpawnMode);
    return 1;
}

inline Skills* GetSkills(int skillId)
{
    if(skillId>=0 && skillId<tables->skillCount) return &tables->skills[skillId];
    return 0;
}

// 0x005D2490
int __fastcall SKILLS_SrvDo135_MinionSpawner(Game* game,Unit* unit,int skillId,int level)
{
    Skills* record=GetSkills(skillId);
    if(!record) return 0;
    Skill* skill=sub_00620250(unit);
    if(!skill) return 0;
    int monsterId=SKILLS_GetParam1(skill);
    int x=SKILLS_GetParam2(skill);
    int y=SKILLS_GetParam3(skill);
    int mode=SKILLS_GetParam4(skill);
    Room* room=sub_00463740(sub_00620BB0(unit),x,y);
    if(!room) return 0;
    Unit* monster=D2GAME_SpawnMonster_6FC69F10(game,room,x,y,monsterId,mode,-1,0);
    if(!monster) {
        monster=D2GAME_SpawnMonster_6FC69F10(game,room,x,y,monsterId,mode,4,0);
        if(!monster) return 0;
    }
    monster->flags |= MINION_FLAGS;
    UNITS_StoreOwner(monster,unit);
    if(record->overlay>=0 && record->overlay<tables->overlayCount) UNITS_SetOverlay(monster,record->overlay,0);
    return 1;
}

#define UNITFLAG_SKSRVDOFUNC 0x40

void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

// 0x005D25B0
int __fastcall SKILLS_SrvDo136_DeathMaul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2UnitStrc* pMissile = D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    const int nSpeed = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nSpeed > 0)
    {
        UNITS_SetAnimationSpeed(pMissile, nSpeed);
    }

    const int nTotalFrames = MISSILE_GetTotalFrames(pMissile);
    int nDistance = DRLG_GetDistanceToXY(pUnit, nX, nY);
    if (nDistance < 1)
    {
        nDistance = 1;
    }

    int nFrame;
    if (nDistance >= 10)
    {
        nFrame = nTotalFrames * nDistance / 12;
    }
    else
    {
        nFrame = nTotalFrames * nDistance / 24 + nTotalFrames / 2;
    }

    MISSILE_SetTotalFrames(pMissile, nFrame);
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    return 1;
}

// 0x005D26F0
int __fastcall SKILLS_SrvDo137_FenrisRage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (!D2COMMON_11018(pTarget))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 104, 1);
    UNITROOM_RefreshUnit(pTarget);
    SKILLS_ApplyTimedState(pGame, pUnit, pUnit, pSkillsTxtRecord->nAuraState, nSkillId, nSkillLevel);
    return 1;
}

// 0x005D27B0
int __fastcall SKILLS_SrvDo138_CreatePerpendicularMissileLine(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 1;
    }

    int nXDiff = nX - CLIENTS_GetUnitX(pUnit);
    int nYDiff = nY - CLIENTS_GetUnitY(pUnit);
    SKILLS_EnlargeVector(&nXDiff, &nYDiff);
    SKILLS_MakeShortPerpendicularVector(&nXDiff, &nYDiff);
    const int nSubMissiles = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    nX += nXDiff * nSubMissiles / -2;
    nY += nYDiff * nSubMissiles / -2;
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nRange = nRange;

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
        nX += nXDiff;
        nY += nYDiff;
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        UNITS_SetAnimationFrame(pUnit, 8);
        pUnit->dwFrameCountPrecise = 0x600;
    }

    return 1;
}

// 0x005D2940
int __fastcall SKILLS_SrvDo139_BaalColdMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nDiffX = nTargetX - CLIENTS_GetUnitX(pUnit);
    const int nDiffY = nTargetY - CLIENTS_GetUnitY(pUnit);
    D2UnitStrc* pMissile = SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -nDiffY);
    MISSILE_SetTargetY(pMissile, nDiffX);
    return 1;
}

// 0x005D2A10
int __fastcall SKILLS_SrvSt63_Corpse_VineCycler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId <= 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || STATES_CheckState(pTarget, STATE_CORPSE_NOSELECT))
    {
        return 0;
    }

    STATES_ToggleState(pTarget, 118, 1);
    UNITROOM_RefreshUnit(pTarget);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pTarget;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    SUNITMSG_QueueSkillEvent(pUnit, pTarget, nSkillId, 1, 0, 0, 0);
    return 1;
}

// 0x005D2B20
int __fastcall SKILLS_SrvDo147_UpdateRiderPath(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (pOwner)
    {
        D2Common_10235_PATH_UpdateRiderPath(pUnit, pOwner);
    }
    return 1;
}

// 0x005D2B40
static inline void SKILLS_RemoveBloodManaState(D2UnitStrc* pUnit)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_BLOOD_MANA);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
}

// 0x005D2B60
int __fastcall D2GAME_SKILLS_BloodMana_6FD025E0(D2UnitStrc* pUnit, int nManaCost)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_BLOOD_MANA);
    const int nSkillId = STATLIST_GetSkillId(pStatList);
    if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) >= nManaCost)
    {
        STATLIST_AddUnitStat(pUnit, STAT_HITPOINTS, -nManaCost, 0);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) < (pSkillsTxtRecord->dwParam[4] << 8))
        {
            pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_BLOOD_MANA);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }
        }
        return 1;
    }
    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_BLOOD_MANA);
    if (pStatList)
    {
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, 256, 0);
    return 0;
}

void __stdcall sub_M121_Emit_005D2B40(D2UnitStrc* pUnit) { SKILLS_RemoveBloodManaState(pUnit); }

static inline int CLIENTS_GetUnitXForceInline(D2UnitStrc* pUnit)
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

static inline int CLIENTS_GetUnitYForceInline(D2UnitStrc* pUnit)
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

// 0x005D30F0
int __fastcall SKILLS_SrvSt22_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTargetUnit && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)) && !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTargetUnit)))
    {
        switch (pTargetUnit->dwUnitType)
        {
        case UNIT_PLAYER:
        case UNIT_MONSTER:
            return 1;
        default:
            return 0;
        }
    }

    return 0;
}

void __fastcall SUNITDMG_RollDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E240

// 0x005D3140
int __fastcall SKILLS_SrvDo033_PsychicHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!SKILLS_SrvSt22_PsychicHammer(pGame, pUnit, nSkillId, nSkillLevel))
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    SUNITDMG_RollDamage(pUnit, nSkillId, nSkillLevel, &damage);
    SUNITDMG_ExecuteEvents(pGame, pUnit, pTargetUnit, 1, &damage);
    damage.wResultFlags |= 1;

    const int nTargetLevel = STATLIST_UnitGetStatValue(pTargetUnit, STAT_LEVEL, 0);
    int nLevel = nTargetLevel + nSkillLevel - STATLIST_UnitGetStatValue(pTargetUnit, STAT_LEVEL, 0);
    nLevel = D2_MIN(D2_MAX(nLevel, 1), nSkillLevel);

    int nChance;
    if (!(pTargetUnit && pTargetUnit->dwUnitType == UNIT_PLAYER) && !MONSTERS_GetHirelingTypeId(pTargetUnit))
    {
        if (MONSTERS_IsBoss(0, pTargetUnit))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nLevel);
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pTargetUnit, 8))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        }
        else
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        }
    }
    else
    {
        nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
    }

    if (nChance > 0)
    {
        unsigned __int64 lSeed = (unsigned __int64)pUnit->pSeed.nHighSeed + (unsigned __int64)pUnit->pSeed.nLowSeed * 0x6AC690C5;
        pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
        pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
        if ((int)((unsigned int)lSeed % 100) < nChance)
        {
            damage.wResultFlags |= 8;
        }
    }

    if (!(STATLIST_UnitGetStatValue(pTargetUnit, STAT_HITPOINTS, 0) & 0xFFFFFF00))
    {
        damage.wResultFlags |= 2;
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTargetUnit, &damage);
    return 1;
}

// 0x005D32F0
int __fastcall SKILLS_SrvSt23_AssasinChargeStrikes(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        return 0;
    }

    return UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0);
}

// 0x005D3310
void __fastcall SKILLDESC_ToggleStateOffCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005D3320
static int __stdcall SKILLS_AddProgressiveCharge(D2GameStrc* pGame, int nSkillId, int nSkillLevel, int nAuraState, int nAuraStat, D2UnitStrc* pUnit)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const int nExpireFrame = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nAuraState);
    if (!pStatList)
    {
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_ProgressiveStrike);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
        STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
    }

    D2COMMON_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);

    const int nOldValue = STATLIST_GetStatValue(pStatList, nAuraStat, 0);
    int nNewValue = nOldValue + 1;
    if (nNewValue > 3)
    {
        nNewValue = 3;
    }

    if (nOldValue != nNewValue)
    {
        STATLIST_SetStat(pStatList, nAuraStat, nNewValue, 0);
        const short nAuraStat1 = pSkillsTxtRecord->wAuraStat[1];
        if (nAuraStat1 >= 0 && nAuraStat1 < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
            STATLIST_AddStat(pStatList, nAuraStat1, nValue, 0);
        }

        STATES_ToggleState(pUnit, nAuraState, 1);
        STATES_ToggleGfxStateFlag(pUnit, nAuraState, 1);
    }

    return 1;
}

// 0x005D3490
int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    D2DamageStrc damage = {};
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80;
    }
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (pDamage && pDamage->wResultFlags & 1)
    {
        SKILLS_AddProgressiveCharge(pGame, nSkillId, nSkillLevel, pSkillsTxtRecord->nAuraState, pSkillsTxtRecord->wAuraStat[0], pUnit);
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005D35D0
int __fastcall SKILLS_SrvDo035_FistsOfFire_ClawsOfThunder_BladesOfIce(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (pInventory)
    {
        D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pLeft = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (pRight == pLeft || !pRight || !pLeft || !ITEMS_CanBeEquipped(pRight) || !ITEMS_CanBeEquipped(pLeft) || !ITEMSIsA(pRight, 45) || !ITEMSIsA(pLeft, 45))
        {
            pUnit->dwFlags |= 0x40;
            SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
            return 1;
        }
    }
    const int nFrame = pUnit->dwSeqFrame >> 8;
    if (nFrame % 2 == 0)
    {
        pUnit->dwFlags &= ~0x40;
        SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
        return 1;
    }

    pUnit->dwFlags |= 0x40;
    SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(pGame, pUnit, nSkillId, nSkillLevel);
    return 1;
}

// 0x005D3680
static void __stdcall SKILLS_ApplyProgressiveDamageBonus(D2StatListStrc* pStatList, D2DamageStrc* pDamage, D2UnitStrc* pUnit)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    const int nMaxLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nMaxLevel > nSkillLevel)
    {
        nSkillLevel = nMaxLevel;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    nValue *= SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    pDamage->dwEnDmgPct += nValue;

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(SUNIT_GetGameFromUnit(pUnit), pUnit);
    if (pTarget && pSkillsTxtRecord->wTgtOverlay > 0 && pSkillsTxtRecord->wTgtOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wTgtOverlay, 0);
    }
}

// 0x005D3880
void __stdcall SKILLS_ApplyProgressiveElementalDamage(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    const int nMaxSkillLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nMaxSkillLevel > nSkillLevel)
    {
        nSkillLevel = nMaxSkillLevel;
    }

    if (nSkillLevel <= 0 || pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType == 4)
    {
        switch (nValue)
        {
        case 2:
        case 3:
        {
            const int nDivisor = SKILLDESC_GetSkillParamTwo(nSkillId);
            if (nDivisor)
            {
                pDamage->dwFrzLen += pDamage->dwColdLen / nDivisor;
            }
            break;
        }
        }
    }

    pDamage->wResultFlags |= 0x4000;
}

inline int SKILLS_GetProgressiveState(int nIndex)
{
    return sgptDataTables->pProgressiveStates[nIndex];
}

// 0x005D2C20
int __fastcall SKILLS_SrvDo140_BaalTentacle(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!pUnit)
    {
        return 0;
    }

    unsigned __int64 lSeed;
    const int nMinionCount = pGame->nDifficulty + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 3 + 2;

    int nMinionSpawnMode;
    int nMinionId;
    int nMinionX;
    int nMinionY;
    MONSTERS_GetMinionSpawnInfo(pUnit, &nMinionId, &nMinionX, &nMinionY, &nMinionSpawnMode, pGame->nDifficulty, 0);

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    const int nX = pTarget ? CLIENTS_GetUnitXForceInline(pTarget) : CLIENTS_GetUnitXForceInline(pUnit);
    const int nY = pTarget ? CLIENTS_GetUnitYForceInline(pTarget) : CLIENTS_GetUnitYForceInline(pUnit);

    for (int i = 0; i < nMinionCount; ++i)
    {
        nMinionX = nX + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 18 - 9;
        nMinionY = nY + SKILLS_ROLL_SEED(&pUnit->pSeed, lSeed) % 18 - 9;

        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nMinionX, nMinionY);
        if (pRoom)
        {
            sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nMinionX, nMinionY);
            D2UnitStrc* pMinion = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nMinionX, nMinionY, nMinionId, nMinionSpawnMode, -1, 0);
            if (pMinion)
            {
                pMinion->dwFlags |= 0x4020000;
                AITACTICS_Idle(pGame, pMinion, 15);
                UNITS_StoreOwner(pMinion, pUnit);
            }
        }
    }

    return 1;
}

int __fastcall SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005C50B0

// 0x005D2E50
int __fastcall SKILLS_AreaEffect_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel, int nUnused)
{
    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    return SKILLS_SrvDo055_CorpseExplosion(pGame, pUnit, 285, nSkillLevel);
}

static inline D2SkillsTxt* GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005D3790
static void __stdcall SKILLS_ApplyProgressiveLeech(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return;
    const int nItemLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    const int nCurrentLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    const int nSkillLevel = nCurrentLevel > nItemLevel ? nCurrentLevel : nItemLevel;
    if (nSkillLevel <= 0)
        return;
    if (pSkillsTxt->wAuraStat[0] < 0 || pSkillsTxt->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        return;
    const int nCharges = STATLIST_GetStatValue(pStatList, pSkillsTxt->wAuraStat[0], 0);
    if (nCharges <= 0)
        return;
    int nLeech = SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel);
    switch (nCharges)
    {
    case 1:
        pDamage->dwLifeLeech += nLeech;
        break;
    case 2:
        pDamage->dwLifeLeech += nLeech;
        pDamage->dwManaLeech += nLeech;
        break;
    case 3:
        nLeech *= 2;
        pDamage->dwLifeLeech += nLeech;
        pDamage->dwManaLeech += nLeech;
        break;
    default:
        break;
    }
}

// 0x005D2E80
int __fastcall SKILLS_SrvDo141_BaalCorpseExplode(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2EffectStrc effect = {};
    effect.nFlags = 0x3002;
    effect.nX = UNITS_GetXPositionInline(pUnit);
    effect.nY = UNITS_GetYPositionInline(pUnit);
    effect.pUnit = pUnit;
    effect.nSkillId = 285;
    effect.nSkillLevel = nSkillLevel;
    effect.pfAreaEffect = SKILLS_AreaEffect_BaalCorpseExplode;
    effect.nParam = SKILLS_GetLinearParam45(nSkillId, nSkillLevel);
    SKILLS_ApplyAreaEffect(pGame, &effect);
    return 1;
}

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

// 0x005D2F80
D2UnitStrc* __fastcall SKILLS_FindUseableCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nUnitSize)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nX = UNITS_GetUnitXPositionInline(pUnit);
    const int nY = UNITS_GetUnitYPositionInline(pUnit);

    D2UnitFindArgStrc unitFindArg;
    memset(&unitFindArg, 0, sizeof(unitFindArg));
    unitFindArg.nFlags = 0x1002;
    unitFindArg.pUnit = pUnit;
    unitFindArg.nX = nX;
    unitFindArg.nY = nY;
    unitFindArg.nSize = nUnitSize;

    D2UnitFindDataStrc unitFindData;
    UNITFINDS_InitializeUnitFindData(pGame->pMemoryPool, &unitFindData, pRoom, nX, nY, nUnitSize, 0, &unitFindArg);
    UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(&unitFindData);

    for (int i = 0; i < unitFindData.nIndex; ++i)
    {
        D2UnitStrc* pResult = unitFindData.pUnitsArray[i];
        if (UNITS_IsCorpseUseable(pResult) && SUNIT_AreUnitsHostile(pGame, pUnit, pResult))
        {
            UNITFINDS_FreeUnitFindData(&unitFindData);
            return pResult;
        }
    }

    UNITFINDS_FreeUnitFindData(&unitFindData);
    return 0;
}

// 0x005D30A0
D2MonEquipTxt* __fastcall SKILLITEM_GetMonEquipTxtRecord(int nMonsterId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nMonEquipTxtRecordId < 0)
    {
        return 0;
    }

    return &sgptDataTables->pMonEquipTxt[pMonStatsTxtRecord->nMonEquipTxtRecordId];
}

void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage);
// 0x005D3970
static void __stdcall SKILLS_ApplyProgressiveElementalConversion(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2DamageStrc* pDamage)
{
    const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    const int nLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId), 1);
    if (nLevel > nSkillLevel)
    {
        nSkillLevel = nLevel;
    }

    if (nSkillLevel <= 0)
    {
        return;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
    if (nValue <= 0)
    {
        return;
    }

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType == 4 && nValue == 3)
    {
        const int nDivisor = SKILLDESC_GetSkillParamFive(nSkillId);
        if (nDivisor)
        {
            pDamage->dwFrzLen += pDamage->dwColdLen / nDivisor;
        }
    }

    pDamage->wResultFlags |= 0x4000;

    int nPercentage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercentage > 0)
    {
        if (nPercentage >= 100)
        {
            nPercentage = 100;
        }

        const int nBaseDamage = pDamage->dwPhysDamage;
        int nDamage = DATATBLS_ApplyRatio(nBaseDamage, nPercentage, 100);
        if (nDamage >= nBaseDamage)
        {
            nDamage = nBaseDamage;
        }

        pDamage->dwPhysDamage = nBaseDamage - nDamage;
        SKILLS_AddElementalDamage(pUnit, pDamage, pSkillsTxtRecord->nEType, nDamage, 0, 0, 0);
    }
}

// 0x005D3AC0
void __fastcall sub_005D3AC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < VOLATILE_DATATABLES->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, VOLATILE_DATATABLES->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, VOLATILE_DATATABLES->pProgressiveStates[i]);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId > 0 && nSkillId < VOLATILE_DATATABLES->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord)
                    {
                        switch (pSkillsTxtRecord->nPrgDamage)
                        {
                        case 1:
                            SKILLS_ApplyProgressiveDamageBonus(pStatList, pDamage, pUnit);
                            break;
                        }
                    }
                }
            }
        }
    }
}

// 0x005D3BA0
void __fastcall SKILLS_ApplyProgressiveLeechAndElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {

        // volatile only reproduces the original reloading the table pointer here instead of reusing the loop test's load
        if (STATES_CheckState(pUnit, (*(D2DataTablesStrc* volatile*)&sgptDataTables)->pProgressiveStates[i]))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, SKILLS_GetProgressiveState(i));
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord)
                    {
                        switch (pSkillsTxtRecord->nPrgDamage)
                        {
                        case 2:
                            SKILLS_ApplyProgressiveLeech(pUnit, pStatList, pDamage);
                            break;

                        case 3:
                            SKILLS_ApplyProgressiveElementalDamage(pUnit, pStatList, pDamage);
                            break;

                        case 4:
                            SKILLS_ApplyProgressiveElementalConversion(pUnit, pStatList, pDamage);
                            break;
                        }
                    }
                }
            }
        }
    }
}

// 0x005D3CB0
int __fastcall SKILLS_AuraCallback_ApplyCopiedDamage(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2DamageStrc damage = *(D2DamageStrc*)pAuraCallback->pArgs;
    SKILLS_ApplyDamageToTarget(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0);
    return 1;
}

// 0x005D3CF0
int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return -1;
    }

    if (pSkillsTxtRecord->nFlags[2 >> 3] & gdwBitMasks[2 & 7] && pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] >= 0 && pSkillsTxtRecord->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
                nIndex = MIN(MAX(nIndex, 1), 3);

                return (&pSkillsTxtRecord->wSrvMissile)[nIndex];
            }
        }
    }

    return pSkillsTxtRecord->wSrvMissileA;
}

// 0x005D3DA0
int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PROGRESSIVE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE & 7]))
    {
        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
    }

    if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        if (pSkillsTxtRecord->wAuraStat[0] < 0 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
        }

        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
        if (!pStatList)
        {
            return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
        }

        int nIndex = STATLIST_GetStatValue(pStatList, pSkillsTxtRecord->wAuraStat[0], 0);
        nIndex = D2_MIN(D2_MAX(nIndex, 1), 3);
        return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[nIndex - 1], nSkillId, nSkillLevel);
    }

    return SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPrgCalc[0], nSkillId, nSkillLevel);
}

// 0x005D3E80
int __fastcall SKILLS_SrvDo038_FistsOfFire_BladesOfIce_ProgressiveFn2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    damage.wResultFlags |= 1;
    damage.dwHitFlags |= 1;
    SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_ApplyCopiedDamage, &damage, 0, ".\\SKILLS\\SkillAss.cpp", 772);
    return 1;
}

static inline unsigned int SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005D3F90
int __fastcall SKILLS_SrvDo039_FistsOfFire_BladesOfIce_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nRand = SEED_RollRandomNumberInline(&pUnit->pSeed);

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2MissileStrc missileParams = {};

    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nMissile = nMissileId;

    D2SeedStrc seed;
    SEED_InitLowSeed(&seed, nRand);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    const int nArea = nRange * nRange;
    for (int i = 0; i < nArea; ++i)
    {
        const int nX = nRange - SEED_RollLimitedRandomNumber(&seed, 2 * nRange);
        const int nY = nRange - SEED_RollLimitedRandomNumber(&seed, 2 * nRange);

        if (nX * nX + nY * nY <= nArea)
        {
            missileParams.nX = nTargetX + nX;
            missileParams.nY = nTargetY + nY;

            if (sub_00463740_FindRoomAtPoint(pRoom, missileParams.nX, missileParams.nY))
            {
                MISSILES_CreateMissileFromParams(pGame, &missileParams);
            }
        }
    }

    return 1;
}

// 0x005D40F0
void __fastcall SKILLS_MissileInit_SeededChargedBolt(D2UnitStrc* pMissile, int nLowSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nTotalFrames = MISSILE_GetTotalFrames(pMissile);
    if (nTotalFrames >= 78)
    {
        nTotalFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, nLowSeed);
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nTotalFrames);
    D2Common_10142(pPath, pMissile, 0);
}

// 0x005D4150
static void __stdcall SKILLS_CreateChargedBoltMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, int nLowSeed)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, nLowSeed);

    D2MissileStrc missileParams = {};
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.pOwner = pUnit;
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pInitFunc = SKILLS_MissileInit_SeededChargedBolt;

    const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        const unsigned __int64 lSeed = tSeed.nHighSeed + 0x6AC690C5i64 * tSeed.nLowSeed;
        tSeed.lSeed = lSeed;
        missileParams.nInitArg = (unsigned int)lSeed;

        D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        MISSILE_SetTargetX(pMissile, SKILLDESC_GetSkillParamTwo(SKILL_ROYALSTRIKE) + 1);
    }
}

static inline unsigned int SEED_RollFromInline(const D2SeedStrc* pSrc, D2SeedStrc* pDst)
{
    const unsigned __int64 lSeed = pSrc->nHighSeed + 0x6AC690C5i64 * pSrc->nLowSeed;
    pDst->nLowSeed = (unsigned int)lSeed;
    pDst->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLowInline(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->nXPos;
        break;
    default:
        nX = pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nX;
}

static inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->nYPos;
        break;
    default:
        nY = pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
        break;
    }
    return nY;
}

// 0x005D4680
void __fastcall SKILLS_MissileInit_CurvingPath(D2UnitStrc* pMissile, int nInitSeed)
{
    if (!pMissile)
    {
        return;
    }

    int nFrames = MISSILE_GetTotalFrames(pMissile);
    if (nFrames >= 78)
    {
        nFrames = 77;
        MISSILE_SetTotalFrames(pMissile, 77);
        MISSILE_SetCurrentFrame(pMissile, 77);
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    D2SeedStrc* const pSeed = &pMissile->pSeed;
    SEED_InitLowSeed(pSeed, nInitSeed);
    PATH_SetType(pPath, 10);
    PATH_SetNewDistance(pPath, nFrames);

    D2PathPointStrc* pPathPoints;
    PATH_GetPathPoints(pPath, &pPathPoints);

    int nX = CLIENTS_GetUnitXInline(pMissile);
    int nY = CLIENTS_GetUnitYInline(pMissile);
    int nDirection = (unsigned char)UNITS_GetDirectionToCoords(pMissile, D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath));

    D2SeedStrc tSeed;
    int nSign = (SEED_RollFromInline(pSeed, &tSeed) & 1) ? 1 : -1;
    const unsigned int nRoll = SEED_RollLowInline(&tSeed);
    pSeed->nHighSeed = tSeed.nHighSeed;
    pSeed->nLowSeed = tSeed.nLowSeed;
    int nStep = nRoll % 3 + *(volatile int*)&gnSrvChargedBoltTurnBase; // volatile only reproduces the original re-reading the turn base at each use
    for (int i = 0; i < nFrames; ++i)
    {
        nDirection += nSign * nStep;
        const unsigned char nIndex = INVENTORY_GetEightWayDirection(nDirection & 63);
        nX += gnCurvingPathOffsetX[nIndex];
        nY += gnCurvingPathOffsetY[nIndex];
        pPathPoints[i].X = nX;
        pPathPoints[i].Y = nY;

        if (!(i % gnSrvChargedBoltTurnEvery))
        {
            nSign = -nSign;
            nStep = SEED_RollRandomNumberInline(pSeed) % 3 + *(volatile int*)&gnSrvChargedBoltTurnBase;
        }
    }

    PATH_SetNumberOfPathPoints(pPath, nFrames);
}

// 0x005D4870
static void __stdcall SKILLS_CreateCurvingMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId, int nX, int nY, int nSkillId, int nSkillLevel, int nStep, unsigned int nLowSeed)
{
    D2SeedStrc seed;
    SEED_InitLowSeed(&seed, nLowSeed);

    D2MissileStrc missileParams = {};
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.pOwner = pUnit;
    missileParams.nMissile = nMissileId;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.dwFlags = 3;
    missileParams.pInitFunc = SKILLS_MissileInit_CurvingPath;

    const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29,
    };

    const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2,
    };

    for (int i = 0; i < 64; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        missileParams.nInitArg = SEED_RollRandomNumberInline(&seed);

        D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pMissile && nMissileId == MISSILE_ROYALSTRIKECHAINLIGHTNING)
        {
            MISSILE_SetTargetX(pMissile, SKILLDESC_GetSkillParamTwo(SKILL_ROYALSTRIKE) + 1);
        }
    }
}

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0
void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0
void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400
int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nState, int a3); // 0x0056C740

// 0x005D4DB0
int __fastcall SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nVelocity = DATATBLS_GetMissileVelocityFromMissilesTxt(nMissileId, nSkillLevel);
    nVelocity += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    SKILLS_CreateMissileRing(pGame, pUnit, pTarget, nMissileId, nSkillId, nSkillLevel, nVelocity);
    return 1;
}

// 0x005D4E70
int __fastcall SKILLS_SrvDo037_ClawsOfThunder_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nLowSeed = SEED_RollRandomNumberInline(&pUnit->pSeed);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nAuraRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nAuraRange)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    SKILLS_CreateChargedBoltMissileRing(pGame, pUnit, nMissileId, nX, nY, nSkillId, nSkillLevel, nAuraRange, nLowSeed);
    return 1;
}

// 0x005D4F40
int __fastcall SKILLS_SrvDo143_FistsOfFire_RoyalStrike_ProgressiveFn(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nLowSeed = SEED_RollRandomNumberInline(&pUnit->pSeed);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nAuraRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nAuraRange)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    SKILLS_CreateCurvingMissileRing(pGame, pUnit, nMissileId, nX, nY, nSkillId, nSkillLevel, nAuraRange, nLowSeed);
    return 1;
}

// 0x005D5010
int __fastcall SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return 0;
    }

    D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, nX, nY);
    return 1;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005D5080
int __fastcall SKILLS_SrvDo041_RoyalStrike_ProgressiveFn3(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, SEED_RollRandomNumberInline(&pUnit->pSeed));
    if (!SKILLS_GetSkillsTxtRecordInline(nSkillId)) return 0;
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY)) return 0;
    const int nMissile = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissile <= 0) return 0;
    const int nCount = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nCount) return 0;
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nX = nX;
    tMissileParams.dwFlags = MISSILE_FLAGS;
    tMissileParams.nY = nY;
    tMissileParams.pOwner = pUnit;
    tMissileParams.nMissile = nMissile;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    for (int i = 0; i < nCount; ++i)
    {
        tMissileParams.nTargetX = SEED_RollRandomNumberInline(&tSeed) % 40 - BURST_CENTER;
        tMissileParams.nTargetY = SEED_RollRandomNumberInline(&tSeed) % 40 - BURST_CENTER;
        if (!tMissileParams.nTargetX && !tMissileParams.nTargetY) tMissileParams.nTargetX = BURST_CENTER;
        D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &tMissileParams);
        if (pMissile)
        {
            MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(&tSeed));
            MISSILE_SetTargetY(pMissile, ((unsigned short)tMissileParams.nTargetY << 16) + (unsigned short)tMissileParams.nTargetX);
        }
    }
    return 1;
}

// 0x005D5220
void __fastcall SKILLS_ReleaseProgressiveCharges(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
        return;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
        return;
    UNITS_IsInMovingMode(pTarget);
    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
        return;
    if (pUnit)
        pUnit->dwFlags |= 0x40;
    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (!STATES_CheckState(pUnit, sgptDataTables->pProgressiveStates[i]))
            continue;
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, sgptDataTables->pProgressiveStates[i]);
        if (!pStatList)
            continue;
        int nSkill = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
        D2SkillsTxt* pSkills = sub_0045C4B0_GetSkillsTxtRecord(nSkill);
        if (pSkills)
        {
            int nLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
            int nCurrentLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkill), 1);
            if (nCurrentLevel > nLevel)
                nLevel = nCurrentLevel;
            if (nLevel > 0 && pSkills->wAuraStat[0] >= 0 && pSkills->wAuraStat[0] < sgptDataTables->nItemStatCostTxtRecordCount)
            {
                int nCharges = STATLIST_GetStatValue(pStatList, pSkills->wAuraStat[0], 0);
                nCharges = D2_MIN(D2_MAX(nCharges,1),3);
                unsigned int nLowSeed, nHighSeed;
                sub_00650E70(&pUnit->pSeed, &nLowSeed, &nHighSeed);
                int nSeed = (int)SEED_RollRandomNumber(&pUnit->pSeed);
                sub_00650E60(&pUnit->pSeed, nLowSeed, nHighSeed);
                --nCharges;
                if (pSkills->nFlags[0] & (unsigned char)gdwBitMasks[7])
                {
                    for (int j = 0; j < nCharges; ++j)
                    {
                        if (pSkills->wProgFunc[j] > 0 && pSkills->wProgFunc[j] < gnSkillSrvDoFnCount)
                        {
                            STATLIST_SetStat(pStatList, pSkills->wAuraStat[0], j + 1, 0);
                            SkillDoFunc pDo = gpfnSkillSrvDoFunctions[pSkills->wProgFunc[j]];
                            if (pDo)
                                pDo(pGame, pUnit, nSkill, nLevel);
                        }
                    }
                    STATLIST_SetStat(pStatList, pSkills->wAuraStat[0], nCharges + 1, 0);
                }
                if (pSkills->wProgFunc[nCharges] > 0 && pSkills->wProgFunc[nCharges] < gnSkillSrvDoFnCount)
                {
                    SkillDoFunc pDo = gpfnSkillSrvDoFunctions[pSkills->wProgFunc[nCharges]];
                    if (pDo)
                        pDo(pGame, pUnit, nSkill, nLevel);
                }
                SUNITMSG_QueueSkillEvent(pUnit, pTarget, (short)nSkill, (short)nLevel, nSeed, 0, (unsigned char)(nCharges + 1));
            }
        }
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }
    STATES_UpdatePgsvFlags(pUnit);
}

static inline D2SkillsTxt* GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static inline int GetSkillParamByLevel_Inline(int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nSkillLevel <= 0)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[0] + (nSkillLevel - 1) * pSkillsTxtRecord->dwParam[1];
}

static inline int ApplyRatio_Inline(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor > (nValue >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nMultiplier * (nValue / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor <= (nMultiplier >> 4))
        {
            return nValue * (nMultiplier / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x005D54B0
static void __stdcall SKILLS_FillKickDamage(D2GameStrc* pGame, D2DamageStrc* pDamage, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2UnitStrc* pUnit)
{
    sub_005D3AC0(pUnit, pDamage);
    pDamage->dwHitFlags |= 3;

    int nMinDamage = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
    int nMaxDamage = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 0);
    nMinDamage += ApplyRatio_Inline(nMinDamage, pDamage->dwEnDmgPct, 100);
    nMaxDamage += ApplyRatio_Inline(nMaxDamage, pDamage->dwEnDmgPct, 100);

    int nMinKickDamage = 0;
    int nMaxKickDamage = 0;
    int nDamagePercent = pDamage->dwEnDmgPct;
    SKILLS_CalculateKickDamage(pUnit, &nMinKickDamage, &nMaxKickDamage, &nDamagePercent);

    nMinKickDamage <<= 8;
    nMaxKickDamage <<= 8;
    nMinKickDamage += ApplyRatio_Inline(nMinKickDamage, nDamagePercent, 100);
    nMaxKickDamage += ApplyRatio_Inline(nMaxKickDamage, nDamagePercent, 100);
    nMinKickDamage += nMinDamage;
    nMaxKickDamage += nMaxDamage;
    const int nRange = nMaxKickDamage - nMinKickDamage;
    unsigned int nRoll;
    SEED_ROLL_LIMITED_INLINE(&pUnit->pSeed, nRange, nRoll);
    pDamage->dwPhysDamage += nRoll + nMinKickDamage;

    D2GAME_RollElementalDamage_6FD14DD0(pUnit, pDamage, nSkillId, nSkillLevel);

    D2InventoryStrc* pInventory = pUnit->pInventory;
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pMainWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
    D2UnitStrc* pSecondaryWeapon = 0;
    if (pMainWeapon)
    {
        const int nBodyLoc = ITEMS_GetBodyLocation(pMainWeapon);
        pSecondaryWeapon = INVENTORY_GetItemFromBodyLoc(pInventory, (nBodyLoc == 4) ? 5 : 4);
    }

    if (ITEMSIsA(pMainWeapon, 0x2D) && ITEMS_CanBeEquipped(pMainWeapon) && STATLIST_GetOwner(pMainWeapon, 0))
    {
        STATLIST_MergeStatLists(pUnit, pMainWeapon, 0);
    }
    else
    {
        pMainWeapon = 0;
    }

    if (pSecondaryWeapon && pSecondaryWeapon != pMainWeapon && ITEMSIsA(pSecondaryWeapon, 0x2D) && ITEMS_CanBeEquipped(pSecondaryWeapon) && STATLIST_GetOwner(pSecondaryWeapon, 0))
    {
        STATLIST_MergeStatLists(pUnit, pSecondaryWeapon, 0);
    }

    SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, pDamage, 1, 0x80);
    sub_6FCF5870(pUnit, pDamage);

    if (pMainWeapon)
    {
        STATLIST_MergeStatLists(pUnit, pMainWeapon, 1);
    }
}

// 0x005D5880
static void __stdcall SKILLS_AllocDragonTalonCombat(D2GameStrc* pGame, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecordArg, int nSkillLevel, int bKnockback, int nSkillId, D2UnitStrc* pUnit)
{
    D2DamageStrc damage;

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);

    if (damage.wResultFlags & 1)
    {
        if (bKnockback)
        {
            damage.wResultFlags |= 0x0C;
        }

        damage.dwEnDmgPct = GetSkillParamByLevel_Inline(nSkillId, nSkillLevel);

        SKILLS_FillKickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);
    }

    damage.dwHitClass = 1;

    unsigned char nSrcDam = pSkillsTxtRecordArg->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
}

// 0x005D5970
int __fastcall SKILLS_SrvSt24_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord;
    if (nSkillId < 0 || nSkillId >= sgptDataTables->nSkillsTxtRecordCount || !(pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId]))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTargetUnit = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTargetUnit)
    {
        SKILLS_SetParam1(pSkill, 0);
        return 0;
    }

    if (!UNITS_IsInMeleeRange(pUnit, pTargetUnit, 0))
    {
        return 0;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) - 1;
    SKILLS_SetParam1(pSkill, nParam);
    SKILLS_AllocDragonTalonCombat(pGame, pTargetUnit, pSkillsTxtRecord, nSkillLevel, nParam == 0, nSkillId, pUnit);
    return 1;
}

// 0x005D5A30
int __fastcall SKILLS_SrvDo042_DragonTalon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    sub_6FCF77E0(pGame, pUnit, SUNITDMG_GetDamageFromUnits(pUnit, pTarget));
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nParam = SKILLS_GetParam1(pSkill) - 1;
    if (nParam < 0)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, nParam);

    int bKnockback = 0;
    if (nParam <= 0)
    {
        int nChance = 100;
        const int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, 0x0C, 0);
        int nLevel = nSkillLevel + nTargetLevel - STATLIST_UnitGetStatValue(pTarget, 0x0C, 0);
        nLevel = MIN(MAX(nLevel, 1), nSkillLevel);

        if (pTarget->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pTarget))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        }
        else if (MONSTERS_IsBoss(0, pTarget))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nLevel);
        }
        else if (MONSTERUNIQUE_CheckMonTypeFlag(pTarget, 8))
        {
            nChance = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        }

        if (nChance > 0 && (int)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 100) < nChance)
        {
            bKnockback = 1;
        }
    }

    SKILLS_AllocDragonTalonCombat(pGame, pTarget, pSkillsTxtRecord, nSkillLevel, bKnockback, nSkillId, pUnit);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    if (nParam > 0)
    {
        if (pUnit)
        {
            pUnit->dwFlags &= ~0x40;
        }

        SKILLS_RewindUnitAnimation(pUnit, 100);
    }

    return 1;
}

static inline unsigned __int64 SEED_RollRandomNumberInline64(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumberInline(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if (((unsigned int)nMax - 1) & (unsigned int)nMax)
        return (unsigned int)SEED_RollRandomNumberInline64(pSeed) % nMax;

    return SEED_RollRandomNumberInline64(pSeed) & (nMax - 1);
}

// 0x0045C3E0
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    return SEED_RollLimitedRandomNumberInline(pSeed, nMax);
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x005D5BF0
int __fastcall SKILLS_CreateMissilesAroundTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMissileId, int nCount, int nRange, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    SEED_InitLowSeed(&pUnit->pSeed, nX);

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pOwner;
    tMissile.dwFlags = 0x420;
    tMissile.pOrigin = pUnit;
    tMissile.nSkill = nSkillId;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissileId;

    if (nCount <= 1 || nRange < 2)
    {
        tMissile.nTargetX = nX;
        tMissile.nTargetY = nY;
        sub_0059FA30_CreateMissile(pGame, &tMissile);
        return 1;
    }

    for (int i = 0; i < nCount; ++i)
    {
        tMissile.nTargetX = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) + nX - nRange;
        tMissile.nTargetY = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, 2 * nRange) + nY - nRange;
        if (PATH_ComputeSquaredDistance(UNITS_GetUnitXPosition(pUnit), UNITS_GetUnitYPosition(pUnit), tMissile.nTargetX, tMissile.nTargetY) >= 4)
        {
            sub_0059FA30_CreateMissile(pGame, &tMissile);
        }
    }

    return 1;
}

// 0x005D5D70
int __fastcall SKILLS_SrvDo043_ShockField(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0)
    {
        return 0;
    }

    const int nSubMissiles = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (nSubMissiles <= 0)
    {
        return 0;
    }

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    return SKILLS_CreateMissilesAroundTarget(pGame, pUnit, pUnit, nMissileId, nSubMissiles, nAuraRange, nSkillId, nSkillLevel);
}

static inline int UNITS_GetUnitType_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x005D5E10
D2UnitStrc* __fastcall SKILLS_SummonSkillMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    int nSpawnMode;
    const int nMonsterId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    int nPetType = (signed char)pSkillsTxtRecord->nPetType;
    if (nPetType < 0 || nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    const int nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
    if (!nX || !nY)
    {
        nX = UNITS_GetXPositionInline(pUnit);
        nY = UNITS_GetYPositionInline(pUnit);
    }

    while (UNITS_GetUnitType_Inline(pUnit) == UNIT_MONSTER)
    {
        pUnit = AIGENERAL_GetMinionOwner(pUnit);
        if (!pUnit)
        {
            return 0;
        }
    }

    if ((!nX || !nY) && !D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_INTOWN >> 3] & gdwBitMasks[SKILLSFLAGINDEX_INTOWN & 7]) && DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nMonsterId;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nAiSpecialState = 0;
    summonArg.dwFlags = 1;
    summonArg.pOwner = pUnit;
    summonArg.nPetType = nPetType;
    summonArg.pPosition.nX = nX;
    summonArg.pPosition.nY = nY;
    summonArg.nPetMax = nPetMax;

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    SUNIT_SetAlignment(pPet, 2, 1);

    D2ModeChangeStrc modeChange;
    MONSTERMODE_GetModeChangeInfo(pPet, nSpawnMode, &modeChange);
    D2GAME_ModeChange_6FC65220(pGame, &modeChange, 1);
    return pPet;
}

// 0x005D6020
int __fastcall SKILLS_SrvDo044_BladeSentinel(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    if (D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0) < 0)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2UnitStrc* pMonster = SKILLS_SummonSkillMonster(pGame, pUnit, 0, 0, pSkillsTxtRecord, nSkillId, nSkillLevel);
    if (!pMonster)
    {
        return 0;
    }

    STATLIST_SetUnitStat(pMonster, 12, STATLIST_UnitGetStatValue(pUnit, 12, 0), 0);
    SUNIT_TeleportUnit(pGame, pMonster, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 0);

    D2AiCmdStrc aiCmd = {};
    aiCmd.nCmdParam[0] = 0;
    aiCmd.nCmdParam[1] = CLIENTS_GetUnitX(pUnit);
    aiCmd.nCmdParam[2] = CLIENTS_GetUnitY(pUnit);
    aiCmd.nCmdParam[3] = nTargetX;
    aiCmd.nCmdParam[4] = nTargetY;
    AIGENERAL_CopyAiCommand(pGame, pMonster, &aiCmd);

    D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 2, 0);
    EVENT_SetEvent(pGame, pMonster, 2, pGame->dwGameFrame + 1, 0, 0);
    pMonster->dwFlags &= 0xFFFFFFF7;
    return 1;
}

// 0x005D6170
int __fastcall SKILLS_SrvDo045_Sentry(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    return SKILLS_SummonSkillMonster(pGame, pUnit, nX, nY, pSkillsTxtRecord, nSkillId, nSkillLevel) != 0;
}

// 0x005D6200
static void __stdcall SKILLS_AllocDragonClawCombat(D2GameStrc* pGame, D2UnitStrc* pTarget, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 325, 0);
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= 2;
        sub_005D3AC0(pUnit, &damage);
        damage.dwEnDmgPct += SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        }
        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        SKILLS_ApplyProgressiveLeechAndElementalDamage(pUnit, &damage);
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
}

// 0x005D6330
int __fastcall SKILLS_SrvSt25_64_DragonClaw_MonFrenzy(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return SUNIT_GetTargetUnit(pGame, pUnit) != 0;
}

// 0x005D6340
int __fastcall SKILLS_SrvDo046_DragonClaw(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if ((pUnit->dwSeqFrame >> 8) % 2 == 0)
    {
        SKILLS_AllocDragonClawCombat(pGame, pTarget, nSkillLevel, pUnit, nSkillId);
        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (pDamage)
        {
            sub_6FCF77E0(pGame, pUnit, pDamage);
        }
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        pUnit->dwFlags &= ~0x40;
    }
    else
    {
        SKILLS_AllocDragonClawCombat(pGame, pTarget, nSkillLevel, pUnit, nSkillId);
        D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
        if (pDamage)
        {
            sub_6FCF77E0(pGame, pUnit, pDamage);
        }
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        pUnit->dwFlags |= 0x40;
    }

    return 1;
}

#define STATEMASK_REMHIT 6

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0

int __stdcall STATES_CheckStateMaskRemHitOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A360

unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc* pUnit);                              // 0x0063A100

int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue);                                                  // 0x004111A0

// 0x005D6410
void __fastcall SKILLS_RemoveStatesOnHit(D2UnitStrc* pDefender)
{
    if (!STATES_CheckStateMaskRemHitOnUnit(pDefender))
    {
        return;
    }

    const unsigned int* pStatFlags = D2COMMON_10494_STATES_GetStatFlags(pDefender);
    const int nRecords = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;

    unsigned int nFlags[8];
    memcpy(nFlags, pStatFlags, sizeof(unsigned int) * nRecords);

    int nBase = 0;
    for (int i = 0; i < nRecords; ++i, nBase += 32)
    {
        unsigned int* pFlag = &nFlags[i];
        unsigned int nFlag = *pFlag;
        int nBit = sub_004111A0_GetLowestSetBit(nFlag);
        if (nBit >= 0)
        {
            do
            {
                nFlag &= ~(1 << nBit);
                const int nStateId = nBit + nBase;
                if (sgptDataTables->fStateMasks[STATEMASK_REMHIT][nStateId >> 5] & gdwBitMasks[nStateId & 31])
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pDefender, nStateId);
                    if (pStatList)
                    {
                        D2Common_10474(pDefender, pStatList);
                        STATLIST_FreeStatList(pStatList);
                    }

                    STATES_ToggleState(pDefender, nStateId, 0);
                }

                nBit = sub_004111A0_GetLowestSetBit(nFlag);
            }
            while (nBit >= 0);

            *pFlag = nFlag;
        }
    }
}

// 0x005D6630
int __fastcall SKILLS_SrvDo047_CloakOfShadows(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount || STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = pSkillsTxtRecord->nPassiveStat[0];
    curse.nStatValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[0], nSkillId, nSkillLevel);
    curse.nState = pSkillsTxtRecord->nAuraState;
    curse.pStateRemoveCallback = SKILLS_RemoveStateAndRefreshPassives;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    for (int i = 1; i < 5; ++i)
    {
        if (pSkillsTxtRecord->nPassiveStat[i] >= 0)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, 0);
            }
        }
    }

    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SrvDo47Strc args;
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = curse.nDuration;
    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;

    for (int i = 0; i < 6; ++i)
    {
        args.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        args.nAuraStatCalcValue[i] = 0;
        if (pSkillsTxtRecord->wAuraStat[i] >= 0)
        {
            args.nAuraStatCalcValue[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
        }
    }

    const int nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_CloakOfShadows, &args, 1, ".\\SKILLS\\SkillAss.cpp", 2164);
    return 1;
}

// 0x005D68A0
int __fastcall SKILLS_SrvDo048_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0)
    {
        return 0;
    }

    const int nDuration = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel) - 1;
    if (nDuration <= 0)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFBF;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nNextFrame = SKILLS_GetParam1(pSkill);
    int bMissileCreated = 0;
    if (nNextFrame < pGame->dwGameFrame)
    {
        D2MissileStrc missileParams = {};
        missileParams.nMissile = nMissileId;
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nTargetX = nTargetX;
        missileParams.dwFlags = 0x20;
        missileParams.pOwner = pUnit;
        missileParams.pOrigin = pUnit;
        missileParams.nTargetY = nTargetY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);

        bMissileCreated = 1;

        SKILLS_SetParam1(pSkill, nDuration + pGame->dwGameFrame);
    }

    if (STATES_CheckState(pUnit, STATE_INFERNO))
    {
        SUNIT_RewindAnimationByFrames(pGame, pUnit, 1);
    }

    return bMissileCreated;
}

// 0x005D6520
int __fastcall SKILLS_AuraCallback_CloakOfShadows(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2SrvDo47Strc* pArgs = (D2SrvDo47Strc*)pAuraCallback->pArgs;
    if (SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pAuraCallback->pOwner;
    curse.pTarget = pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = pArgs->nAuraStat[0];
    if (curse.nStat <= 0)
    {
        curse.nStat = -1;
    }
    curse.nStatValue = pArgs->nAuraStatCalcValue[0];
    curse.nState = pArgs->nAuraTargetState;
    curse.pStateRemoveCallback = SKILLS_CurseStateCallback_ResetAi;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pArgs->nAuraStat[i] >= 0)
        {
            STATLIST_SetStatIfListIsValid(pStatList, pArgs->nAuraStat[i], pArgs->nAuraStatCalcValue[i], 0);
        }
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && SKILLS_CanSwitchAi(pUnit, 10))
    {
        AITHINK_ExecuteAiFn(pAuraCallback->pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 10);
    }

    return 1;
}

// 0x005D69B0
void __fastcall SKILLS_StatRemoveCallback_BladeFury(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }
}

// 0x005D69D0
int __fastcall SKILLS_SrvSt26_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId) < 0)
    {
        return 0;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (!pSkill)
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_INFERNO);
    if (!pStatList)
    {
        if (pSkillsTxtRecord->wStartMana > 0 && STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0) < (int)pSkillsTxtRecord->wStartMana << 8)
        {
            return 0;
        }

        const int nExpireFrame = pGame->dwGameFrame + 21;
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_StatRemoveCallback_BladeFury);
        STATLIST_SetState(pStatList, STATE_INFERNO);
        STATES_ToggleState(pUnit, STATE_INFERNO, 1);
        SKILLS_SetParam1(pSkill, 0);
        return 1;
    }

    const int nExpireFrame = pGame->dwGameFrame + 7;
    D2COMMON_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);

    if (SKILLS_GetParam1(pSkill) > pGame->dwGameFrame)
    {
        SUNIT_RewindAnimationByFrames(pGame, pUnit, 1);
        return 1;
    }

    const int nResult = SKILLS_SrvDo048_BladeFury(pGame, pUnit, nSkillId, nSkillLevel);
    if (nResult)
    {
        SKILLS_ConsumeSkillMana(pGame, pUnit, nSkillId, nSkillLevel);
    }

    return nResult;
}

// 0x005D6B60
void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel, int bCheckOnInit)
{
    const int nType = pPet ? pPet->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    const int nClassId = pPet->dwClassId;
    D2MonEquipTxt* pRecord = SKILLITEM_GetMonEquipTxtRecord(nClassId);
    if (!pRecord)
    {
        return;
    }

    if (bCheckOnInit && !pRecord->nOnInit)
    {
        return;
    }

    D2InventoryStrc* pInventory = pPet->pInventory;
    if (!pInventory)
    {
        return;
    }

    while (pRecord->nMonster == nClassId && pRecord->wLevel > nSkillLevel)
    {
        ++pRecord;
    }

    for (; pRecord->nMonster == nClassId; ++pRecord)
    {
        int nMax = 0;
        while (nMax < 3 && pRecord->nLoc[nMax] > 0 && pRecord->nLoc[nMax] < 11)
        {
            ++nMax;
        }

        if (nMax <= 0)
        {
            continue;
        }

        unsigned int nIndex;
        if ((nMax - 1) & nMax)
        {
            const unsigned __int64 lSeed = pPet->pSeed.nHighSeed + 0x6AC690C5i64 * pPet->pSeed.nLowSeed;
            pPet->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pPet->pSeed.nLowSeed = (unsigned int)lSeed;
            nIndex = (unsigned int)lSeed % nMax;
        }
        else
        {
            const unsigned __int64 lSeed = pPet->pSeed.nHighSeed + 0x6AC690C5i64 * pPet->pSeed.nLowSeed;
            pPet->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
            pPet->pSeed.nLowSeed = (unsigned int)lSeed;
            nIndex = (unsigned int)lSeed & (nMax - 1);
        }

        const int nBodyLoc = pRecord->nLoc[nIndex];
        if (INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc))
        {
            continue;
        }

        int nMod = pRecord->nMod[nIndex];
        if (nMod < 0 || nMod >= 8)
        {
            nMod = 0;
        }

        unsigned int nItemCode = pRecord->dwItem[nIndex];
        if (nItemCode == 0x20202020 && pUnit)
        {
            if (!pUnit->pInventory)
            {
                continue;
            }

            D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pUnit->pInventory, nBodyLoc);
            if (!pItem)
            {
                continue;
            }

            nItemCode = ITEMS_GetBaseCode(pItem);
        }

        D2MonsterItemCodeStrc tItemCode;
        tItemCode.nItemCode = nItemCode;
        tItemCode.nBodyLoc = nBodyLoc;
        tItemCode.unk0x05 = 1;
        MONSTERAI_CreateAndEquipItem(pGame, pPet, &tItemCode, nItemLevel, nMod);
    }
}

// 0x005D6CF0
static void __stdcall SKILLS_ScaleSummonedPetStats(D2GameStrc* pGame, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2UnitStrc* pPet)
{
    if (nSkillLevel <= 1)
    {
        return;
    }

    D2SkillsTxt* pSkillsRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    const int nParam = !pSkillsRecord ? 0 : pSkillsRecord->dwParam[0];
    int nHp = STATLIST_GetMaxLifeFromUnit(pPet);
    nHp += DATATBLS_ApplyRatio(nHp, (nSkillLevel - 1) * nParam, 100);
    STATLIST_SetUnitStat(pPet, 7, nHp, 0);
    STATLIST_SetUnitStat(pPet, 6, nHp, 0);

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, !pPet ? 6 : pPet->dwUnitType, !pPet ? -1 : pPet->dwUnitId);
    if (!pStatList)
    {
        return;
    }

    D2COMMON_10475_PostStatToStatList(pPet, pStatList, 1);

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] >= 0 && pSkillsTxtRecord->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pPet, pSkillsTxtRecord->dwAuraStatCalc[1], nSkillId, nSkillLevel);
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->wAuraStat[i], nValue, 0);
        }
    }

    for (int i = 0; i < 5; ++i)
    {
        if (pSkillsTxtRecord->nPassiveStat[i] >= 0 && pSkillsTxtRecord->nPassiveStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pPet, pSkillsTxtRecord->dwPassiveCalc[1], nSkillId, nSkillLevel);
            STATLIST_SetStat(pStatList, pSkillsTxtRecord->nPassiveStat[i], nValue, 0);
        }
    }

    if (pSkillsTxtRecord->wSumUMod > 0 && pSkillsTxtRecord->wSumUMod < 43)
    {
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, pSkillsTxtRecord->wSumUMod, 1);
    }
}

// 0x005D6E70
int __fastcall SKILLS_SrvDo049_ShadowWarrior_Master(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = 0;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    STATLIST_SetUnitStat(pPet, 12, STATLIST_UnitGetStatValue(pUnit, 12, 0), 0);
    SKILLS_ScaleSummonedPetStats(pGame, pSkillsTxtRecord, nSkillId, nSkillLevel, pPet);

    int nLevel = SKILLDESC_GetSummonLevel(nSkillId, nSkillLevel);
    nLevel = D2_MAX(nLevel, 1) < DATATBLS_GetMaxLevel(0) ? D2_MAX(nLevel, 1) : DATATBLS_GetMaxLevel(0);
    SKILLS_EquipMonsterFromTable(pGame, pUnit, pPet, nSkillId, nSkillLevel, nLevel, 0);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pPet, 2, 0);
    EVENT_SetEvent(pGame, pPet, 2, pGame->dwGameFrame + 20, 0, 0);

    if (pSkillsTxtRecord->nAuraState > 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount)
    {
        STATES_ToggleState(pPet, pSkillsTxtRecord->nAuraState, 1);
    }

    UNITS_StoreOwner(pPet, pUnit);

    const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (nDuration > 0)
    {
        EVENT_SetEvent(pGame, pPet, 7, pGame->dwGameFrame + nDuration, 0, 0);
        D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 21, 0);
    }

    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}

static inline int GetSkillParam3ById_Inline(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[3];
}

int __fastcall SKILLS_SrvDo006_InnerSight_SlowMissiles(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005DB1C0

int __fastcall SKILLS_SrvDo010_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005DB6D0
// 0x005D7090
int __fastcall SKILLS_SrvSt27_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    sub_6FD15470(pUnit, GetSkillParam3ById_Inline(nSkillId));

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (!(damage.wResultFlags & 1))
    {
        return 0;
    }

    SKILLS_FillKickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}

// 0x005D7180
int __fastcall SKILLS_SrvDo050_DragonTail(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (!pDamage)
    {
        return 0;
    }

    D2DamageStrc physDamage = *pDamage;
    sub_6FCF77E0(pGame, pUnit, pDamage);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    if (SUNIT_IsDead(pUnit))
    {
        return 1;
    }

    D2DamageStrc fireDamage;
    memset(&fireDamage, 0, sizeof(fireDamage));
    fireDamage.dwFireDamage = DATATBLS_ApplyRatio(physDamage.dwPhysDamage, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 329, 0), 100);
    fireDamage.wResultFlags = 9;
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    SKILLS_ApplyAreaDamage(pGame, pUnit, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nRange, &fireDamage, 0);
    return 1;
}

// 0x005D72B0
static int __stdcall SKILLS_CanMindBlastConvertTarget(D2UnitStrc* pOwner, int nChance, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    if (MONSTERS_GetHirelingTypeId(pUnit))
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 0;
    }

    if (!SKILLS_CanSwitchAi(pUnit, 11))
    {
        return 0;
    }

    return (int)SEED_RollLimitedRandomNumber(&pOwner->pSeed, 100) <= nChance;
}

// 0x005D7310
void __fastcall SKILLS_StatRemoveCallback_MindBlast(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNIT_SetAlignment(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONVERSION_SAVE);
    if (pStatList)
    {
        const int nLevel = STATLIST_GetStatValue(pStatList, 176, 0);
        const int nConversionMaxHp = STATLIST_GetStatValue(pStatList, 177, 0);
        const int nNewHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
        int nHp = DATATBLS_ApplyRatio(nConversionMaxHp, STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8, nNewHp);
        nHp = D2_MIN(D2_MAX(nHp, 1), nNewHp);

        STATLIST_SetUnitStat(pUnit, 12, nLevel, 0);
        STATLIST_SetUnitStat(pUnit, 6, nHp << 8, 0);
        STATLIST_SetUnitStat(pUnit, 7, nConversionMaxHp << 8, 0);
        D2Common_10474(pUnit, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    for (D2StatListStrc* pList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8); pList; pList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8))
    {
        D2Common_10474(pUnit, pList);
        STATLIST_FreeStatList(pList);
    }
}

// 0x005D7430
static int __stdcall SKILLS_ApplyMindBlastConversion(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, D2SrvDo51Strc* pArgs)
{
    if (!SKILLS_CanMindBlastConvertTarget(pOwner, pArgs->nMonCurseResSubstraction, pUnit))
    {
        return 0;
    }

    const int nExpireFrame = SEED_RollLimitedRandomNumber(&pOwner->pSeed, pArgs->nParam2) + pGame->dwGameFrame + pArgs->nParam1;
    D2StatListStrc* pConversionStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONVERSION);
    if (!pConversionStatList)
    {
        const int nUnitGUID = !pOwner ? -1 : pOwner->dwUnitId;
        const int nUnitType = !pOwner ? 6 : pOwner->dwUnitType;

        pConversionStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0x802, nExpireFrame, nUnitType, nUnitGUID);
        if (!pConversionStatList)
        {
            return 0;
        }

        STATLIST_SetState(pConversionStatList, STATE_CONVERSION);
        STATLIST_SetStatRemoveCallback(pConversionStatList, SKILLS_StatRemoveCallback_MindBlast);
        D2COMMON_10475_PostStatToStatList(pUnit, pConversionStatList, 1);
        STATES_ToggleState(pUnit, 0x35, 1);
    }

    D2COMMON_10476(pConversionStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, 12, nExpireFrame, 0, 0);
    SKILLS_ClearMonsterMinionOwnership(pUnit);
    SUNIT_SetAlignment(pUnit, 2, 1);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pUnit, 0, pOwner->dwNodeIndex);

    for (D2StatListStrc* i = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8); i; i = STATLIST_GetStatListFromUnitAndFlag(pUnit, 8))
    {
        D2Common_10474(pUnit, i);
        STATLIST_FreeStatList(i);
    }

    UNITS_SetTargetUnitForDynamicUnit(pOwner, 0);

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 12, 0);
    const int nOwnerLevel = STATLIST_UnitGetStatValue(pOwner, 12, 0);
    if (!nLevel || nOwnerLevel >= nLevel || STATLIST_GetStatListFromUnitAndState(pUnit, STATE_CONVERSION_SAVE))
    {
        return 1;
    }

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

    D2StatListStrc* pConversionSaveStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, nUnitType, nUnitGUID);
    if (!pConversionSaveStatList)
    {
        return 1;
    }

    STATLIST_SetState(pConversionSaveStatList, STATE_CONVERSION_SAVE);
    D2COMMON_10475_PostStatToStatList(pUnit, pConversionSaveStatList, 1);
    const int nHitpoints = STATLIST_UnitGetStatValue(pUnit, 6, 0) >> 8;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit) >> 8;
    STATLIST_SetStat(pConversionSaveStatList, 0xB0, nLevel, 0);
    STATLIST_SetStat(pConversionSaveStatList, 0xB1, nMaxHp, 0);

    int nNewHitpoints = DATATBLS_ApplyRatio(nHitpoints, nOwnerLevel, nLevel) << 8;
    int nNewMaxHp = DATATBLS_ApplyRatio(nMaxHp, nOwnerLevel, nLevel) << 8;
    if (nNewMaxHp < 1)
    {
        nNewMaxHp = 1;
    }

    nNewHitpoints = MIN(MAX(nNewHitpoints, 1), nNewMaxHp);

    STATLIST_SetUnitStat(pUnit, 12, nOwnerLevel, 0);
    STATLIST_SetUnitStat(pUnit, 6, nNewHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, 7, nNewMaxHp, 0);
    return 1;
}

// 0x005D7680
int __fastcall SKILLS_AuraCallback_MindBlast(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2SrvDo51Strc* pArgs = (D2SrvDo51Strc*)pAuraCallback->pArgs;

    if (!SKILLS_ApplyMindBlastConversion(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, pArgs))
    {
        D2DamageStrc damage = *pArgs->pDamage;
        SUNITDMG_ExecuteEvents(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, 1, &damage);
        SUNITDMG_ExecuteMissileDamage(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage);
    }

    return 1;
}

// 0x005D76E0
int __fastcall SKILLS_SrvDo051_MindBlast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;

    D2SrvDo51Strc args;
    args.pDamage = &damage;
    args.nMonCurseResSubstraction = D2COMMON_11036_GetMonCurseResistanceSubtraction(nSkillLevel, nSkillId);
    args.nParam1 = SKILLS_GetParam3FromSkillId(nSkillId);
    args.nParam2 = SKILLS_GetParam4FromSkillId(nSkillId);

    SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_MindBlast, &args, 0, ".\\SKILLS\\SkillAss.cpp", 2883);
    return 1;
}

// 0x005D7850
int __fastcall SKILLS_SrvDo052_DragonFlight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (((pUnit->dwSeqFrame >> 8) % 2) == 0)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (!pRoom)
        {
            return 0;
        }

        pUnit->dwFlags &= ~0x40;

        int nX;
        int nY;
        if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }

        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
        if (!pLevelsTxtRecord || pLevelsTxtRecord->nTeleport == 0 || (pLevelsTxtRecord->nTeleport == 2 && UNITS_TestCollisionByCoordinates(pUnit, nX, nY, 0x804)))
        {
            return 0;
        }

        SUNIT_TeleportUnit(pGame, pUnit, 0, nX, nY, 0, 0);
        return 1;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    const int nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel) + STATLIST_UnitGetStatValue(pUnit, 0x145, 0);
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwEnDmgPct = SKILLDESC_GetSkillParamByLevel(nSkillId, nSkillLevel);
        SKILLS_FillKickDamage(pGame, &damage, pTarget, nSkillId, nSkillLevel, pUnit);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    sub_6FCF77E0(pGame, pUnit, SUNITDMG_GetDamageFromUnits(pUnit, pTarget));
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005D7A00
int __fastcall SKILLS_SrvSt28_BladeShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || !SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId) || SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId) <= 0 || SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel) <= 0)
    {
        return 0;
    }

    if (pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    SKILLS_RemoveStatesInGroup(pUnit, pSkillsTxtRecord->nAuraState, 0);

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->nAuraState;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStat(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);
    return 1;
}

// 0x005D7B60
int __fastcall SKILLS_SrvDo053_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nAuraRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nAuraRange)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwHitFlags = 2;
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->dwHitClass)
    {
        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    }

    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nAuraRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_ApplyCopiedDamage, &damage, 0, ".\\SKILLS\\SkillAss.cpp", 3066);
    return 1;
}

struct D2Do142ArgsStrc
{
    D2DamageStrc* pDamage;
    int nToHit;
    unsigned short wResultFlags;
    unsigned short unk0x0A;
    unsigned int dwHitFlags;
    unsigned char nSrcDam;
    unsigned char unk0x11[3];
};

unsigned short __fastcall SKILLS_SetDamageResultFlags(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned short wResultFlags, int a5, D2DamageStrc* pDamage, int a7); // 0x0056E6F0

// 0x005D7C40
int __fastcall SKILLS_AuraCallback_AllocSkillCombat(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2Do142ArgsStrc* pArgs = (D2Do142ArgsStrc*)pAuraCallback->pArgs;
    D2DamageStrc damage = *pArgs->pDamage;

    SKILLS_SetDamageResultFlags(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, pArgs->wResultFlags, pArgs->nToHit, &damage, 1);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= pArgs->dwHitFlags;
        if (pArgs->nSrcDam)
        {
            SUNITDMG_FillDamageValues(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0, pArgs->nSrcDam);
        }

        SUNITDMG_AllocCombat(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage, 0x80);
        SUNITDMG_DrainItemDurability(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, 0);
    }

    return 1;
}

// 0x005D7CE0
int __fastcall SKILLS_SrvDo142_ApplyAreaCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nRange = SKILLS_EvaluateProgressiveSkillCalc(pUnit, nSkillId, nSkillLevel);
    if (!nRange)
    {
        nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwHitFlags = 2;
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->dwHitClass)
    {
        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    }

    D2SrvDo142Strc args;
    args.pDamage = &damage;
    args.nResultFlags = pSkillsTxtRecord->wResultFlags;
    args.nHitFlags = pSkillsTxtRecord->dwHitFlags;
    args.nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!(pSkillsTxtRecord->wResultFlags & 1))
    {
        args.nToHit = SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
    }

    SKILLS_IterateAuraTargets(pGame, pUnit, 0, 0, nRange, pSkillsTxtRecord->dwAuraFilter, SKILLS_AuraCallback_AllocSkillCombat, &args, 0, ".\\SKILLS\\SkillAss.cpp", 3151);
    return 1;
}

// 0x005D7E10
int __fastcall SKILLS_SrvDo054_BladeShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount || !SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId))
    {
        return 0;
    }

    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        SKILLS_SrvDo142_ApplyAreaCombat(pGame, pUnit, nSkillId, nSkillLevel);
    }

    return 1;
}

void __fastcall sub_6FCF5870(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pDamage || !(pDamage->wResultFlags & 1))
    {
        return;
    }

    for (int i = 0; i < sgptDataTables->nProgressiveStates; ++i)
    {
        if (STATES_CheckState(pUnit, SKILLS_GetProgressiveState(i)))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, SKILLS_GetProgressiveState(i));
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId > 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord)
                    {
                        switch (pSkillsTxtRecord->nPrgDamage)
                        {
                        case 2:
                            SKILLS_ApplyProgressiveLeech(pUnit, pStatList, pDamage);
                            break;
                        case 3:
                            SKILLS_ApplyProgressiveElementalDamage(pUnit, pStatList, pDamage);
                            break;
                        case 4:
                            SKILLS_ApplyProgressiveElementalConversion(pUnit, pStatList, pDamage);
                            break;
                        }
                    }
                }
            }
        }
    }
}

#include "gen/data/Source/D2Game/SKILLS/SkillAss.inc"
