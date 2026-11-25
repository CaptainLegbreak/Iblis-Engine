#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2CmpTypes.h"
#include "D2GameAux.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2StatIds.h"
#include "D2MonStatsInit.h"

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

#define UNITFLAG_SKSRVDOFUNC 0x40

#define ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE 9

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))


struct D2CofDataStrc;

struct SMSGHANDLER_PARAMS;

struct D2UnkNecSkillStrc3;

struct D2StaticPathStrc;

struct D2CurseStrc;


struct D2UnkNecSkillStrc2;

struct D2AuraCallbackStrc;

struct D2SkillsTxt;

struct D2WinImageClickRectStrc;

struct D2CofNodeStrc;

struct D2SummonArgStrc;

struct D2DifficultyLevelsTxt;

struct D2MonLvlTxt;

struct D2MonStatsTxt;

union D2SeedStrc;


struct D2ModeChangeStrc;

struct D2GameStrc;

struct D2UnitStrc;

struct D2DamageStrc;

struct D2DataTablesStrc;

struct Unit;

struct D2CoordStrc;

struct D2ItemStatCostTxt;

struct D2UnkNecSkillStrc3
{
    D2GameStrc* pGame;
    D2UnitStrc* pUnit;
    int nSkillId;
    int nSkillLevel;
    unsigned char nUnitType;
    unsigned char pad0x11;
    unsigned short pad0x12;
    int nUnitGUID;
    int nLength;
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall D2COMMON_11021(D2UnitStrc* pUnit); // 0x00645680

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __fastcall SKILLS_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C31F0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0


struct D2UnkNecSkillStrc2
{
    D2DamageStrc* pDamage;
    int nX;
    int nY;
    int nSquaredRange;
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nFlags); // 0x0057DBF0

int __fastcall SKILLS_IsValidTerrorTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C3D50

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __fastcall TARGETS_InsertUnitNode(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int a4); // 0x005B1990

void __fastcall SKILLS_CurseStateCallback_ResetAlignment(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3DB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int a7, int a8, int a9); // 0x005A9370

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall SKILLS_CanSwitchAi(D2UnitStrc* pUnit, int nAiSpecialState); // 0x0056E2F0

struct D2WinImageClickRectStrc
{
    int nX;
    int nY;
    int nWidth;
    int nHeight;
    int unk0x10;
    int (__stdcall* pCallback)(SMSGHANDLER_PARAMS* pMsg);
};

extern D2CofNodeStrc* gpCofNodeList; // 0x0087E83C

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

struct Unit
{
    int type;
    int classId;
    void* pool;
    int id;
    unsigned char unk_10[0xB4];
    unsigned flags;
};

extern int __fastcall sub_0046C140_TestMode(int,int);

extern int __fastcall sub_005A0180_TestMonType(Unit*,int);

extern int __fastcall sub_005541B0_IsDead(Unit*);

extern int __fastcall sub_00554200_CheckTarget(Game*,Unit*,Unit*);

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

int __fastcall SKILLS_AuraCallback_ApplyCurse(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs); // 0x005C35C0

D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940

void __fastcall SKILLS_SetGolemStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel); // 0x005C50C0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall sub_6FC3E200(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053CDF0

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

int __stdcall sub_00625480(Unit*,int,unsigned short); // 0x00625480

D2StatListStrc* __stdcall sub_006251F0(void*,unsigned,unsigned,int,int); // 0x006251F0

void __stdcall sub_00626E10(Unit*,D2StatListStrc*,int); // 0x00626E10

void __stdcall sub_00627150(D2StatListStrc*,int,int,int); // 0x00627150

enum D2C_Y09SummonConstants
{
    MONLVL_AC = 0,
    MONLVL_TH = 2,
};

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x006272B0

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

int __fastcall SKILLS_ExplodeCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005C4DF0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

D2MonStatsTxt* __fastcall sub_0055B7E0_GetMonStatsTxtFromUnit(D2UnitStrc* pUnit); // 0x0055B7E0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

D2UnitStrc* __fastcall PLAYERPETS_GetFirstPetByType(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nPetType, int a4); // 0x00574EC0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId); // 0x004F4110

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __fastcall SKILLS_ClearMonsterMinionOwnership(D2UnitStrc* pUnit); // 0x0056E580

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc* pGame, D2UnitStrc* pUnit, int nOwnerGUID, int nOwnerType, int bSetFlag1, int bSetFlag2); // 0x0058F030

void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x005DD330

void __fastcall MONSTERAI_ClearTargetOverride(D2UnitStrc* pUnit); // 0x00573120

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUMod, int bUnique); // 0x005A4850

int __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

int __stdcall DATATBLS_CalculateMonsterStatsByLevel(int nMonsterId, int nGameType, int nDifficulty, int nLevel, short nFlags, D2MonStatsInitStrc* pMonStatsInit); // 0x006538A0

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

#define SLOW_STAT 150

#define SMALL_CAP 50

#define LARGE_CAP 90

#define UNITMASK_MONSTER 12

#define CURSE_DURATION 750

#define STAT_A 67

#define STAT_B 68

#define STAT_C 69

#define CURSE_STATE 24

#define SOURCE_LINE 0xB62

struct D2StatListStrc;

struct Unit005A0180;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern "C" int __fastcall sub_005A0180(Unit005A0180* pUnit, unsigned short wMask);                         // 0x005A0180

void __stdcall UnitUpdateAnimRateAndVel(D2UnitStrc* pUnit, const char* szFile, int nLine);           // 0x00623F50

int __stdcall STATLIST_SetStatValue(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x006270B0

enum D2C_Q05SkillConstants
{
    AISPECIALSTATE_NONE = 0,
};

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet);                          // 0x00639E30

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList);                              // 0x006277E0

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList);                                            // 0x00626CD0

int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0

struct D2MonsterDataStrc;

struct D2NecroSkeletonComponentStrc;

enum D2SkillNecConstants
{
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
};

int __fastcall SKILLS_CanApplyCurseToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x005C3420

void __fastcall SKILLS_CurseStateCallback_ResetAi(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3370

void __fastcall SKILLS_ExecuteCurseTargetAi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005C34B0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50

D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740

int __fastcall SKILLS_IterateTargetsAroundTarget(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs); // 0x0056E780

int __fastcall sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs); // 0x005C35C0

int __fastcall SKILLS_AuraCallback_ApplyConfuse(D2UnitStrc* pUnit, void* pArgs); // 0x005C3DE0

int __fastcall SKILLS_AuraCallback_SetAttractTarget(D2UnitStrc* pUnit, void* pArg); // 0x005C3B30

void __fastcall SKILLS_CurseStateCallback_EndAttract(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C3B00

extern const D2NecroSkeletonComponentStrc gaNecroSkeletonComponents[]; // 0x00741940

void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70

static void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel); // 0x005C4180

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner); // 0x00621CE0

void __stdcall sub_006488A0_SetDirection(D2PathRecordStrc* pPath, int nDirection); // 0x006488A0

int __stdcall STATLIST_GetOwnerGUID(D2StatListStrc* pStatList); // 0x006252B0

int __stdcall STATLIST_GetOwnerType(D2StatListStrc* pStatList); // 0x00625250

int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc*, D2MissileStrc*); // 0x0059FA30

void __stdcall MISSILE_SetTargetX(D2UnitStrc*, int); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc*, int); // 0x0064A760

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

void __fastcall D2GAME_AssignSkill_6FD13800(D2UnitStrc*, int, int, int); // 0x005701B0

void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005D6B60

D2StatListStrc* __stdcall STATLIST_AllocStatList(void*, unsigned int, unsigned int, int, int); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10

int __fastcall ITEMMODE_EquipCursorItem(D2GameStrc*, D2UnitStrc*, int, unsigned char, int, int*); // 0x005606B0

int __fastcall SKILLS_SrvSt20_IronGolem(D2GameStrc*, D2UnitStrc*, int, int); // 0x005C32A0

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc*, int, int); // 0x0061A270

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc*); // 0x00623830

void __stdcall UNITS_ChangeAnimMode(D2UnitStrc*, int); // 0x00624690

void __stdcall ITEMS_GetAllowedBodyLocations(D2UnitStrc*, unsigned char*, unsigned char*); // 0x0062EA80

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc*); // 0x0064C370

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall D2GAME_SetSummonResistance_6FD0C2E0(D2UnitStrc* pUnit, D2UnitStrc* pPet); // 0x005C40D0

void __fastcall SKILLS_SetNecroPetComponents(D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel); // 0x005C4430

int __fastcall SKILLS_SrvSt21_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

static int __stdcall SKILLS_RelocateRevivedTarget(D2GameStrc* pGame, D2UnitStrc* pTarget);

static void __stdcall SKILLS_InitializeRevivedMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMonster, int nSkillId, int nSkillLevel);

int __fastcall SKILLS_SrvDo058_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

static int SKILLS_CanReviveCorpse(D2UnitStrc* pUnit);

typedef int (__fastcall *AURACALLBACK)(D2AuraCallbackStrc*, D2UnitStrc*);

extern const char gszSkillNecSourceFile[]; // 0x006E3034

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc*, D2UnitStrc*, int, int, int, unsigned int, AURACALLBACK, void*, int, const char*, int); // 0x0056B7E0

void __fastcall SKILLS_AddElementalDamage(D2UnitStrc*, D2DamageStrc*, int, int, int, int*, int*); // 0x0056C8E0

int __fastcall SKILLS_AuraCallback_ApplyCorpseExplosionDamage(D2AuraCallbackStrc*, D2UnitStrc*); // 0x005C4D10

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0

int __stdcall SKILLS_GetElementalLength(D2UnitStrc*, int, int, int); // 0x00644F20

static int SKILLS_ApplyAiCurseDivisor(unsigned char nDifficulty, int nLength);

int __fastcall SKILLS_SrvDo059_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

static void __stdcall SKILLS_SetSkeletonComponents(D2UnitStrc* pPet, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId);

static void __stdcall SKILLS_SetSkeletonMageComponents(D2UnitStrc* pPet, D2UnitStrc* pUnit);

static D2UnitStrc* __stdcall SKILLS_SpawnBonePrisonPet(D2GameStrc* pGame, int nSkillId, D2UnitStrc* pUnit, int nX, int nY, int nSkillLevel);

static int SKILLS_AddLifeAndGetGain(D2UnitStrc* pUnit, int nValue);

int __fastcall SKILLS_SrvDo062_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

int __fastcall SKILLS_EventFunc04_ReflectPhysicalDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel);

// build: symbol ?IMAGE_IsInClickRect@* 0x004FD5A0
static inline int IMAGE_IsInClickRect(const D2WinImageClickRectStrc* pClickRect, int nX, int nY)
{
    const int nTop = pClickRect->nY;
    if (nX >= pClickRect->nX && nY >= nTop - pClickRect->nHeight && nX < pClickRect->nX + pClickRect->nWidth && nY < nTop)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?D2COMP_FindCofNode@* 0x00503310
static inline D2CofNodeStrc* D2COMP_FindCofNode(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nClass == nClass && pNode->dwWeaponClass == dwWeaponClass)
        {
            ++pNode->nRefCount;
            return pNode;
        }
    }
    return 0;
}

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820

// 0x005C3070
int __fastcall SKILLS_SrvSt15_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005C30A0
int __fastcall SKILLS_SrvSt16_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }

            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        }
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!pSkillsTxtRecord->nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
    return 1;
}

// 0x005C31C0
int __fastcall SKILLS_SrvSt17_Poison_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return D2COMMON_11021(pTarget);
}

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

// 0x005C31F0
int __fastcall SKILLS_IsValidAttractTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != 0)
    {
        return 0;
    }

    if (!SKILLS_CanSwitchAi(pTarget, 19))
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    return SUNIT_AreUnitsHostile(pGame, pUnit, pTarget) != 0;
}

// 0x005C3260
int __fastcall SKILLS_SrvSt18_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return 1;
}

// 0x005C3270
int __fastcall SKILLS_SrvSt19_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    return !DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget));
}

// 0x005C32A0
int __fastcall SKILLS_SrvSt20_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    if (pTarget->dwUnitType != UNIT_ITEM)
    {
        return 0;
    }

    if (pTarget->dwAnimMode != 3)
    {
        return 0;
    }

    if (!ITEMS_IsMetalItem(pTarget->dwClassId))
    {
        return 0;
    }

    if (!ITEMS_CheckItemFlag(pTarget, 0x10, 256, ".\\SKILLS\\SkillNec.cpp"))
    {
        return 0;
    }

    return !STATLIST_GetOwner(pTarget, 0);
}

// 0x005C3300
static int SKILLS_CanReviveCorpse(D2UnitStrc* pUnit)
{
    if ((pUnit ? pUnit->dwUnitType : UNIT_INVALID) != 1)
    {
        return 0;
    }

// build: symbol ?MONSTERREGION_CheckMonStats2Flag@* 0x004638A0
    if (!MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, 8))
    {
        return 0;
    }

    if (!SUNIT_IsDead(pUnit))
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pUnit, 0))
    {
        return 0;
    }

    return SKILLS_CanSwitchAi(pUnit, 7) != 0;
}

static int sub_005C3300_CanReviveTarget(D2UnitStrc* pTarget)
{
    if (!pTarget)
    {
        return 0;
    }
    if (pTarget->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    if (!MONSTERREGION_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }
    if (!SUNIT_IsDead(pTarget))
    {
        return 0;
    }
    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }
    return SKILLS_CanSwitchAi(pTarget, 7) != 0;
}

// 0x005C3350
int __fastcall SKILLS_SrvSt21_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    return sub_005C3300_CanReviveTarget(pTarget);
}

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005C3370
void __fastcall SKILLS_CurseStateCallback_ResetAi(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    if (pUnit)
    {
        SUNITEVENT_Unregister(SUNIT_GetGameFromUnit(pUnit), pUnit, 1, nState);

        const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (nType == 1)
        {
            AITHINK_ExecuteAiFn(SUNIT_GetGameFromUnit(pUnit), pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), 0);
        }

        SKILLS_RemoveStateAndRefreshPassives(pUnit, nState, pStatList);
    }
}

// 0x005C33D0
int __fastcall SKILLS_GetSkillValue(int nSkillId)
{
    switch (nSkillId)
    {
    case SKILL_PENETRATE:
        return 0xA;
    case SKILL_IMMOLATIONARROW:
        return 0xC;
    case SKILL_METEOR:
        return 0xB;
    }
    return 0;
}

// 0x005C3400
extern "C" __declspec(dllexport) int __fastcall SKILLS_IsDimVisionOrTerrorState(int nValue) {
    if (nValue != 0x17) {
        return nValue == 0x38;
    }
    return 1;
}

inline int TestFlag(Unit* unit,unsigned mask)
{
    if (unit) return (unit->flags&mask)!=0;
    return 0;
}

static inline int GetType(Unit* unit)
{
    int type=6;
    if (unit) type=unit->type;
    return type;
}

// 0x005C3420
int __fastcall SKILLS_CanApplyCurseToTarget(Game* game,Unit* unit,Unit* target)
{
    if (!target) return 0;
    if (GetType(target)==1) {
        if (!sub_0046C140_TestMode(target->classId,2)) return 0;
        if (sub_005A0180_TestMonType(target,0x20)) return 0;
    }
    if (!TestFlag(target,4)) return 0;
    if (!TestFlag(target,8)) return 0;
    if (!TestFlag(target,2)) return 0;
    if (sub_005541B0_IsDead(target)) return 0;
    return sub_00554200_CheckTarget(game,unit,target)!=0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

static inline int AiSpecialStateFromAuraState(int nAuraState)
{
    switch (nAuraState)
    {
    case STATE_DIMVISION: return AISPECIALSTATE_DIMVISION;
    case STATE_TERROR: return AISPECIALSTATE_TERROR;
    case STATE_TAUNT: return AISPECIALSTATE_TAUNT;
    default: return AISPECIALSTATE_NONE;
    }
}

// 0x005C34B0
void __fastcall SKILLS_ExecuteCurseTargetAi(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxtRecord)
    {
        AITHINK_ExecuteAiFn(pGame, pTarget, AIGENERAL_GetAiControlFromUnitInline(pTarget), AiSpecialStateFromAuraState(pSkillsTxtRecord->wAuraTargetState));
    }
}

// 0x005C3540
int __fastcall SKILLS_ApplyResistanceImmunityPenalty(D2UnitStrc* pUnit, int nStatId, int nResist)
{
    switch (nStatId)
    {
    case STAT_DAMAGERESIST:
    case STAT_MAGICRESIST:
    case STAT_FIRERESIST:
    case STAT_LIGHTRESIST:
    case STAT_COLDRESIST:
    case STAT_POISONRESIST:
        if (nResist > 0 || pUnit && pUnit->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pUnit) || STATLIST_GetUnitBaseStat(pUnit, nStatId, 0) < 100)
        {
            break;
        }

        return nResist / 5;

    default:
        break;
    }

    return nResist;
}

// 0x005C35C0
int __fastcall SKILLS_AuraCallback_ApplyCurse(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs)
{
    if (pArgs->bResetAi)
    {
        const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (nType != UNIT_MONSTER)
        {
            return 0;
        }

        if (STATLIST_GetUnitAlignment(pUnit) == 1)
        {
            return 0;
        }

        if (!SKILLS_CanSwitchAi(pUnit, AiSpecialStateFromAuraState(pArgs->nAuraTargetState)))
        {
            return 0;
        }
    }

    int nValue = 0;
    if (pArgs->nAuraStat[0] >= 0)
    {
        nValue = SKILLS_ApplyResistanceImmunityPenalty(pUnit, pArgs->nAuraStat[0], pArgs->nAuraStatCalc[0]);
        if (!nValue)
        {
            return 0;
        }
    }

    if (!SKILLS_CanApplyCurseToTarget(pArgs->pGame, pArgs->pUnit, pUnit))
    {
        return 0;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pArgs->pUnit;
    curse.pTarget = pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = pArgs->nAuraStat[0];
    curse.nStatValue = nValue;
    curse.nState = pArgs->nAuraTargetState;
    curse.pStateRemoveCallback = pArgs->bResetAi ? SKILLS_CurseStateCallback_ResetAi : 0;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    if (pArgs->bResetAi)
    {
        SKILLS_ExecuteCurseTargetAi(pArgs->pGame, pArgs->pUnit, pUnit, pArgs->nSkillId, pArgs->nSkillLevel);
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pArgs->nAuraStat[i] >= 0 && pArgs->nAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nStatValue = SKILLS_ApplyResistanceImmunityPenalty(pUnit, pArgs->nAuraStat[i], pArgs->nAuraStatCalc[i]);
            if (nStatValue)
            {
                STATLIST_SetStatIfListIsValid(pStatList, pArgs->nAuraStat[i], nStatValue, 0);
            }
        }
    }

    if (pArgs->bUpdateAnimRate)
    {
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillNec.cpp", 582);
    }

    if (pArgs->nAuraEvent[0] >= 0 && pArgs->nAuraEventFunc[0] > 0)
    {
        SUNITEVENT_Unregister(pArgs->pGame, pUnit, 1, pArgs->nAuraTargetState);

        for (int i = 0; i < 3; ++i)
        {
            if (pArgs->nAuraEvent[0] >= 0 && pArgs->nAuraEventFunc[0] > 0)
            {
                SKILLS_RegisterUnitEvent(pArgs->pGame, pUnit, pArgs->nAuraEvent[i], pArgs->nSkillId, pArgs->nSkillLevel, pArgs->nAuraEventFunc[i], 1, pArgs->nAuraTargetState);
            }
        }
    }

    return 1;
}

int __fastcall sub_005C3400_IsDimVisionOrTerror(int nState)
{
    if (nState != 23)
    {
        return nState == 56;
    }
    return 1;
}

// 0x005C37A0
static int SKILLS_ApplyAiCurseDivisor(unsigned char nDifficulty, int nLength)
{
    D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(nDifficulty);
    if (pDifficultyLevelsTxtRecord && pDifficultyLevelsTxtRecord->dwAiCurseDivisor)
    {
        return nLength / pDifficultyLevelsTxtRecord->dwAiCurseDivisor;
    }
    return nLength;
}

// 0x005C37C0
int __fastcall SKILLS_SrvDo030_Curse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int bIsDimVisionOrTerrorCurse = sub_005C3400_IsDimVisionOrTerror(pSkillsTxtRecord->wAuraTargetState);
    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (bIsDimVisionOrTerrorCurse)
    {
        nLength = SKILLS_ApplyAiCurseDivisor(pGame->nDifficulty, nLength);
    }

    D2UnkNecSkillStrc args = {};
    args.pGame = pGame;
    args.pUnit = pUnit;
    args.bResetAi = bIsDimVisionOrTerrorCurse;
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = nLength;
    args.bUpdateAnimRate = 0;

    for (int i = 0; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] < 0 || pSkillsTxtRecord->wAuraStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            args.nAuraStat[i] = -1;
            break;
        }

// build: symbol ?PLAYER_GetItemStatCostTxtRecord@* 0x0045C4F0
        D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pSkillsTxtRecord->wAuraStat[i]);
        if (!pItemStatCostTxtRecord)
        {
            break;
        }

        if (pItemStatCostTxtRecord->nItemStatFlags[1] & gdwBitMasks[1])
        {
            args.bUpdateAnimRate = 1;
        }

        args.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        args.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
    }

    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    for (int i = 0; i < 3; ++i)
    {
        args.nAuraEvent[i] = pSkillsTxtRecord->wAuraEvent[i];
        args.nAuraEventFunc[i] = pSkillsTxtRecord->wAuraEventFunc[i];
    }

    return SKILLS_IterateTargetsAroundTarget(pGame, pSkillsTxtRecord->dwAuraFilter, pUnit, nRange, sub_6FD0B450, &args);
}

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x005C39C0
void __fastcall SKILLS_ApplyDimVisionToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(SKILL_DIMVISION);
    if (pSkillsTxtRecord)
    {
        int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, SKILL_DIMVISION, nSkillLevel);

        D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(pGame->nDifficulty);
        if (pDifficultyLevelsTxtRecord && pDifficultyLevelsTxtRecord->dwAiCurseDivisor)
        {
            nLength /= pDifficultyLevelsTxtRecord->dwAiCurseDivisor;
        }

        D2UnkNecSkillStrc args;
        memset(&args, 0, sizeof(args));
        args.nDuration = nLength;
        args.pGame = pGame;
        args.pUnit = pUnit;
        args.bResetAi = 1;
        args.nSkillId = SKILL_DIMVISION;
        args.nSkillLevel = nSkillLevel;
        args.bUpdateAnimRate = 0;

        for (int i = 0; i < 6; ++i)
        {
            const short nStatId = pSkillsTxtRecord->wAuraStat[i];
            if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            {
                args.nAuraStat[i] = -1;
                break;
            }

            D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
            if (!pItemStatCostTxtRecord)
            {
                break;
            }

            if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE & 7])
            {
                args.bUpdateAnimRate = 1;
            }

            args.nAuraStat[i] = nStatId;
            args.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], SKILL_DIMVISION, nSkillLevel);
        }

        args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
        SKILLS_AuraCallback_ApplyCurse(pTarget, &args);
    }
}

// 0x005C3B00
void __fastcall SKILLS_CurseStateCallback_EndAttract(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNIT_SetAlignment(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

// 0x005C3DB0
void __fastcall SKILLS_CurseStateCallback_ResetAlignment(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    SUNIT_SetAlignment(pUnit, 0, 1);
    STATES_ToggleState(pUnit, nState, 0);
    sub_005B1A90(SUNIT_GetGameFromUnit(pUnit), pUnit);
}

// calling-convention shim (not game code)
int __fastcall sub_005C3300_Shim(D2UnitStrc* pUnit)
{
    return SKILLS_CanReviveCorpse(pUnit);
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

static inline unsigned int SEED_RollRandomNumber_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

static inline int sub_0044BE50_Inline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x005C3B90
int __fastcall SKILLS_SrvDo059_Attract(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!SKILLS_IsValidAttractTarget(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    SUNIT_SetAlignment(pTarget, 1, 1);
    TARGETS_InsertUnitNode(pGame, pTarget, 0, 9);
    SKILLS_ClearMonsterMinionOwnership(pTarget);

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    const int nBaseLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const int nLength = SKILLS_ApplyAiCurseDivisor(pGame->nDifficulty, nBaseLength);

    D2UnkNecSkillStrc3 arg;
    arg.pGame = pGame;
    arg.pUnit = pUnit;
    arg.nSkillId = nSkillId;
    arg.nSkillLevel = nSkillLevel;
    arg.nLength = nLength;
    arg.nUnitType = sub_0044BE50_Inline(pTarget);
    arg.nUnitGUID = UNITS_GetUnitId(pTarget);
    SKILLS_IterateTargetsAroundTarget(pGame, pSkillsTxtRecord->dwAuraFilter, pUnit, nRange, SKILLS_AuraCallback_SetAttractTarget, &arg);

    D2CurseStrc curse = {};
    curse.pUnit = pUnit;
    curse.pTarget = pTarget;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nSkillLevel;
    curse.nDuration = nLength;
    curse.nStat = -1;
    curse.nState = pSkillsTxtRecord->wAuraTargetState;
    curse.pStateRemoveCallback = SKILLS_CurseStateCallback_EndAttract;
    SKILLS_ApplyStateEffect(&curse);
    return 1;
}

// 0x005C3D50
int __fastcall SKILLS_IsValidTerrorTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    if (STATLIST_GetUnitAlignment(pTarget) != 0)
    {
        return 0;
    }

    if (!SUNIT_AreUnitsHostile(pGame, pUnit, pTarget))
    {
        return 0;
    }

    if (SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    return SKILLS_CanSwitchAi(pTarget, 11) != 0;
}

// 0x005C3B30
int __fastcall SKILLS_AuraCallback_SetAttractTarget(D2UnitStrc* pUnit, void* pArg)
{
    D2UnkNecSkillStrc3* pParam = (D2UnkNecSkillStrc3*)pArg;
    if (!SKILLS_IsValidAttractTarget(pParam->pGame, pParam->pUnit, pUnit))
    {
        return 0;
    }

    if (pParam->nUnitType == 0)
    {
        sub_6FC61E30(pUnit, 1, pParam->nUnitGUID);
    }
    else
    {
        sub_6FC61E30(pUnit, 2, pParam->nUnitGUID);
    }

    EVENT_SetEvent(pParam->pGame, pUnit, 0x0A, pParam->pGame->dwGameFrame + pParam->nLength, 0, 0);
    return 1;
}

// 0x005C3DE0
int __fastcall SKILLS_AuraCallback_ApplyConfuse(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs)
{
    if (!SKILLS_IsValidTerrorTarget(pArgs->pGame, pArgs->pUnit, pUnit))
    {
        return 0;
    }

    int nStatId = pArgs->nAuraStat[0];
    const int nValue = SKILLS_ApplyResistanceImmunityPenalty(pUnit, nStatId, pArgs->nAuraStatCalc[0]);
    if (!nValue)
    {
        nStatId = -1;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pArgs->pUnit;
    curse.nSkill = pArgs->nSkillId;
    curse.nSkillLevel = pArgs->nSkillLevel;
    curse.pTarget = pUnit;
    curse.nDuration = pArgs->nDuration;
    curse.nStat = nStatId;
    curse.nStatValue = nValue;
    curse.nState = pArgs->nAuraTargetState;
    curse.pStateRemoveCallback = SKILLS_CurseStateCallback_ResetAlignment;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
    {
        return 0;
    }

    for (int i = 1; i < 6; ++i)
    {
        if (pArgs->nAuraStat[i] >= 0 && pArgs->nAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            const int nStatValue = SKILLS_ApplyResistanceImmunityPenalty(pUnit, pArgs->nAuraStat[i], pArgs->nAuraStatCalc[i]);
            if (nStatValue)
            {
                STATLIST_SetStat(pStatList, pArgs->nAuraStat[i], nStatValue, 0);
            }
        }
    }

    if (pArgs->bUpdateAnimRate)
    {
        UnitUpdateAnimRateAndVel(pUnit, ".\\SKILLS\\SkillNec.cpp", 983);
    }

    SUNIT_SetAlignment(pUnit, 1, 1);
    TARGETS_InsertUnitNode(pArgs->pGame, pUnit, 0, 9);
    sub_6FC61E30(pUnit, 3, 0);
    EVENT_SetEvent(pArgs->pGame, pUnit, EVENTTYPE_AIRESET, pArgs->pGame->dwGameFrame + pArgs->nDuration, 0, 0);
    return 1;
}

// 0x005C3F20
int __fastcall SKILLS_SrvDo061_Confuse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraStat[0] < -1 || pSkillsTxtRecord->wAuraStat[0] >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    nLength = SKILLS_ApplyAiCurseDivisor(pGame->nDifficulty, nLength);

    D2UnkNecSkillStrc args = {};
    args.pGame = pGame;
    args.pUnit = pUnit;
    args.nDuration = nLength;
    args.nSkillId = nSkillId;
    args.nSkillLevel = nSkillLevel;
    args.bUpdateAnimRate = 0;

    for (int i = 1; i < 6; ++i)
    {
        if (pSkillsTxtRecord->wAuraStat[i] < 0 || pSkillsTxtRecord->wAuraStat[i] >= sgptDataTables->nItemStatCostTxtRecordCount)
        {
            args.nAuraStat[i] = -1;
            break;
        }

        D2ItemStatCostTxt* pItemStatCostTxtRecord = PLAYER_GetItemStatCostTxtRecord(pSkillsTxtRecord->wAuraStat[i]);
        if (!pItemStatCostTxtRecord)
        {
            break;
        }

        if (pItemStatCostTxtRecord->nItemStatFlags[1] & gdwBitMasks[1])
        {
            args.bUpdateAnimRate = 1;
        }

        args.nAuraStat[i] = pSkillsTxtRecord->wAuraStat[i];
        args.nAuraStatCalc[i] = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
    }

    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;
    return SKILLS_IterateTargetsAroundTarget(pGame, pSkillsTxtRecord->dwAuraFilter, pUnit, nRange, SKILLS_AuraCallback_ApplyConfuse, &args);
}

// 0x005C40D0
void __fastcall SKILLS_SetSummonResistance(Unit* unit,Unit* pet)
{
    int resist=sub_00625480(unit,349,0);
    if (!resist) return;
    D2StatListStrc* list=sub_006251F0(!pet ? 0 : pet->pool,0,0,!pet ? 6 : pet->type,!pet ? -1 : pet->id);
    if (!list) return;
    sub_00626E10(pet,list,1);
    if(sub_00625480(pet,142,0)<=0) sub_00627150(list,39,resist,0);
    if(sub_00625480(pet,144,0)<=0) sub_00627150(list,41,resist,0);
    if(sub_00625480(pet,148,0)<=0) sub_00627150(list,43,resist,0);
    sub_00627150(list,45,resist,0);
}

inline D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterDataInl(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}

inline void MONSTERS_SetComponentInl(D2UnitStrc* pUnit, int nComponent, unsigned char nValue)
{
    D2MonsterDataStrc* pMonsterData = MONSTERUNIQUE_GetMonsterDataInl(pUnit);
    if (pMonsterData)
    {
        pMonsterData->nComponent[nComponent] = nValue;
    }
}

// 0x005C4180
static void __stdcall D2GAME_SetUnitComponent_6FD0C3A0(int bHasShield, int bSpecial, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nLevel)
{
    if (nLevel > 10)
    {
        nLevel = 10;
    }

    const char nHead = gaNecroSkeletonComponents[nLevel].nHead;
    MONSTERS_SetComponentInl(pPet, 0, nHead);
    const char nTorso = gaNecroSkeletonComponents[nLevel].nTorso;
    MONSTERS_SetComponentInl(pPet, 1, nTorso);
    const char nSpecial1 = gaNecroSkeletonComponents[nLevel].nSpecial1;
    MONSTERS_SetComponentInl(pPet, 8, nSpecial1);
    const char nSpecial2 = gaNecroSkeletonComponents[nLevel].nSpecial2;
    MONSTERS_SetComponentInl(pPet, 9, nSpecial2);
    const char nLegs = gaNecroSkeletonComponents[nLevel].nLegs;
    MONSTERS_SetComponentInl(pPet, 2, nLegs);
    const char nRightArm = gaNecroSkeletonComponents[nLevel].nRightArm;
    MONSTERS_SetComponentInl(pPet, 3, nRightArm);
    const char nLeftArm = gaNecroSkeletonComponents[nLevel].nLeftArm;
    MONSTERS_SetComponentInl(pPet, 4, nLeftArm);

    if (bHasShield)
    {
        const char nShield = gaNecroSkeletonComponents[nLevel].nShield;
        MONSTERS_SetComponentInl(pPet, 7, nShield);
    }

    if (bSpecial)
    {
        const int nComponent = SEED_RollRandomNumber_Inline(&pUnit->pSeed) & 3;
        MONSTERS_SetComponentInl(pPet, 11, nComponent);
        MONSTERS_SetComponentInl(pPet, 12, nComponent);
        AITHINK_SetAiControlParams(pPet && pPet->dwUnitType == UNIT_MONSTER && pPet->pMonsterData ? pPet->pMonsterData->pAiControl : 0, 1, 0, -666);
    }
    else
    {
        const char nRightHand = gaNecroSkeletonComponents[nLevel].nRightHand;
        MONSTERS_SetComponentInl(pPet, 5, nRightHand);
    }
}

static void SKILLS_SetMonsterComponent_Inline(D2UnitStrc* pMonster, int nIndex, char nComponent)
{
    if (pMonster && pMonster->dwUnitType == UNIT_MONSTER && pMonster->pMonsterData)
    {
        pMonster->pMonsterData->nComponent[nIndex] = nComponent;
    }
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005C4300
static void __stdcall SKILLS_SetSkeletonComponents(D2UnitStrc* pPet, int nSkillLevel, D2UnitStrc* pUnit, int nSkillId)
{
    int nLevel = 1;
    if (STATES_CheckState(pUnit, STATE_ITEMFULLSET))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_ITEMFULLSET);
        if (pStatList)
        {
            STATLIST_GetStatValue(pStatList, 0x15E, 0);
            nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        }
    }

    int bHasShield = 0;
    if (nSkillLevel > 2)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inline(nSkillId);
        const int nParam = !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[0];
        const int nRoll = SEED_RollRandomNumber_Inline(&pUnit->pSeed) % 100;
        if (nRoll < nParam)
        {
            bHasShield = 1;
        }
    }

    D2GAME_SetUnitComponent_6FD0C3A0(bHasShield, 0, pUnit, pPet, nLevel);
}

// 0x005C43D0
static void __stdcall SKILLS_SetSkeletonMageComponents(D2UnitStrc* pPet, D2UnitStrc* pUnit)
{
    int nLevel = 1;
    if (STATES_CheckState(pUnit, STATE_ITEMFULLSET))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_ITEMFULLSET);
        if (pStatList)
        {
            STATLIST_GetStatValue(pStatList, 0x15E, 0);
            nLevel = STATLIST_GetStatValue(pStatList, 0x15F, 0);
        }
    }

    D2GAME_SetUnitComponent_6FD0C3A0(0, 1, pUnit, pPet, nLevel);
}

// 0x005C4430
void __fastcall SKILLS_SetNecroPetComponents(D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel)
{
    switch (!pPet ? -1 : pPet->dwClassId)
    {
    case 0x16B:
        SKILLS_SetSkeletonComponents(pPet, nSkillLevel, pUnit, nSkillId);
        break;
    case 0x16C:
        SKILLS_SetSkeletonMageComponents(pPet, pUnit);
        break;
    }
}

inline D2ItemStatCostTxt* GetItemStatCost(int nStat) {
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount) return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}

static inline int ApplyRatio(int nValue, int nMultiplier, int nDivisor) {
    if (!nDivisor) return 0;
    if (nValue > 0x100000) {
        if ((nValue & ~15) < nDivisor * 16) return (int)(nValue * (__int64)nMultiplier / nDivisor);
        return (nValue / nDivisor) * nMultiplier;
    }
    if (nMultiplier > 0x10000) {
        if ((nMultiplier & ~15) < nDivisor * 16) return (int)(nValue * (__int64)nMultiplier / nDivisor);
        return (nMultiplier / nDivisor) * nValue;
    }
    return nValue * nMultiplier / nDivisor;
}

// 0x005C4470
int __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel)
{
    D2SkillsTxt* pSkill = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId) return 0;
    for (int i = 0; i < 5; ++i) {
        if (pSkill->nPassiveStat[i] >= 0 && pSkill->nPassiveStat[i] < sgptDataTables->nItemStatCostTxtRecordCount) {
            int nStat = pSkill->nPassiveStat[i];
            D2ItemStatCostTxt* pCost = GetItemStatCost(nStat);
            if (pCost) {
                int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwPassiveCalc[i], nSkillId, nSkillLevel);
                STATLIST_AddUnitStat(pPet, nStat, nValue, 0);
                if (pCost->wItemEvent[0] > 0 && !SUNITEVENT_GetEvent(pGame, pPet, 2, GAME_GetUnitGUID(pPet), nStat)) {
                    SKILLS_RegisterUnitEvent(pGame, pPet, pCost->wItemEvent[0], nStat << 16, 0, pCost->wItemEventFunc[0], 2, GAME_GetUnitGUID(pPet));
                    const short nSecondEvent = pCost->wItemEvent[1];
                    if (nSecondEvent > 0) SKILLS_RegisterUnitEvent(pGame, pPet, nSecondEvent, nStat << 16, 0, pCost->wItemEventFunc[1], 2, GAME_GetUnitGUID(pPet));
                }
            }
        }
    }
    D2StatListStrc* pList = 0;
    for (int i = 0; i < 6; ++i) {
        if (pSkill->wAuraStat[i] >= 0 && pSkill->wAuraStat[i] < sgptDataTables->nItemStatCostTxtRecordCount) {
            int nStat = pSkill->wAuraStat[i];
            D2ItemStatCostTxt* pCost = GetItemStatCost(nStat);
            if (pCost) {
                int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwAuraStatCalc[i], nSkillId, nSkillLevel);
                if (nValue) {
                    if (!pList) {
                        pList = STATLIST_AllocStatList(pGame->pMemoryPool, 0, 0, GAME_GetUnitTypeOrInvalid(pPet), GAME_GetUnitGUID(pPet));
                        if (!pList) return 0;
                        D2COMMON_10475_PostStatToStatList(pPet, pList, 1);
                    }
                    STATLIST_SetStat(pList, nStat, nValue, 0);
                    if (pCost->wItemEvent[0] > 0 && !SUNITEVENT_GetEvent(pGame, pPet, 2, GAME_GetUnitGUID(pPet), nStat)) {
                        SKILLS_RegisterUnitEvent(pGame, pPet, pCost->wItemEvent[0], nStat << 16, 0, pCost->wItemEventFunc[0], 2, GAME_GetUnitGUID(pPet));
                        const short nSecondEvent = pCost->wItemEvent[1];
                    if (nSecondEvent > 0) SKILLS_RegisterUnitEvent(pGame, pPet, nSecondEvent, nStat << 16, 0, pCost->wItemEventFunc[1], 2, GAME_GetUnitGUID(pPet));
                    }
                }
            }
        }
    }
    if (pSkill->nAuraState > 0 && pSkill->nAuraState <= sgptDataTables->nStatesTxtRecordCount) {
        STATES_ToggleState(pPet, pSkill->nAuraState, 1);
        if (pList) STATLIST_SetState(pList, pSkill->nAuraState);
    }
    int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwCalc[0], nSkillId, nSkillLevel);
    int nLife = STATLIST_GetMaxLifeFromUnit(pPet);
    nLife += ApplyRatio(nLife, nPercent, 100);
    STATLIST_SetUnitStat(pPet, 7, nLife, 0);
    STATLIST_SetUnitStat(pPet, STAT_HITPOINTS, nLife, 0);
    for (int i = 0; i < 5; ++i) {
        if (pSkill->wSumSkill[i] > 0 && pSkill->wSumSkill[i] < sgptDataTables->nSkillsTxtRecordCount) {
            int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkill->dwSumSkCalc[i], nSkillId, nSkillLevel);
            if (nLevel > 0) {
                D2SkillsTxt* pSumSkill = SKILLS_GetSkillsTxtRecord(pSkill->wSumSkill[i]);
                if (pSumSkill) {
                    D2GAME_SetSkills_6FD14C60(pPet, pSkill->wSumSkill[i], nLevel, 0);
                    if (pSumSkill->nFlags[0] & (unsigned char)gdwBitMasks[5]) D2GAME_AssignSkill_6FD13800(pPet, 0, pSkill->wSumSkill[i], -1);
                }
            }
        }
    }
    if (pSkill->wAuraEvent[0] >= 0) {
        SUNITEVENT_Unregister(pGame, pPet, 1, pSkill->nAuraState);
        for (int i = 0; i < 3 && pSkill->wAuraEvent[i] >= 0; ++i) {
            SKILLS_RegisterUnitEvent(pGame, pPet, pSkill->wAuraEvent[i], nSkillId, nSkillLevel, pSkill->wAuraEventFunc[i], 1, pSkill->nAuraState);
        }
    }
    if (pSkill->wSumUMod > 0 && pSkill->wSumUMod < 43) D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, pSkill->wSumUMod, 1);
    if (pSkill->wSumOverlay > 0 && pSkill->wSumOverlay < sgptDataTables->nOverlayTxtRecordCount) UNITS_SetOverlay(pPet, pSkill->wSumOverlay, 0);
    int nLevel = nItemLevel;
    if (!nLevel) {
        int nOwnerLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        nLevel = 3 * nSkillLevel;
        nLevel = MAXIMUM(nLevel, 1) < nOwnerLevel ? MAXIMUM(nLevel, 1) : nOwnerLevel;
    }
    SKILLS_EquipMonsterFromTable(pGame, pUnit, pPet, nSkillId, nSkillLevel, nLevel, 0);
    return 1;
}

inline D2MonLvlTxt* DATATBLS_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

// 0x005C49E0
int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel)
{
    int nPetLevel = nPetLevelArg;
    if (nPetLevelArg <= 0)
    {
        const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
        nPetLevel = nSkillLevel + 3 * nUnitLevel / 4;
        nPetLevel = D2_MIN(D2_MAX(nPetLevel, 1), nUnitLevel);
    }

    if (nPetLevel)
    {
        STATLIST_SetUnitStat(pPet, STAT_LEVEL, nPetLevel, 0);
    }

    if (nPetLevel >= sgptDataTables->nMonLvlTxtRecordCount - 1)
    {
        nPetLevel = sgptDataTables->nMonLvlTxtRecordCount - 1;
    }

    D2MonLvlTxt* pMonLvlTxtRecord = DATATBLS_GetMonLvlTxtRecord(nPetLevel);
    if (!pMonLvlTxtRecord)
    {
        return 0;
    }

    const int nDifficulty = D2_MIN(D2_MAX(pGame->nDifficulty, 0), 2);
    const int nGameType = pGame->nGameType || pGame->dwGameType;
    STATLIST_AddUnitStat(pPet, STAT_ARMORCLASS, pMonLvlTxtRecord->nValues[MONLVL_AC + nGameType][nDifficulty], 0);
    STATLIST_AddUnitStat(pPet, STAT_TOHIT, pMonLvlTxtRecord->nValues[MONLVL_TH + nGameType][nDifficulty], 0);
    return 1;
}

// 0x005C4B00
int __fastcall SKILLS_SrvDo031_RaiseSkeleton_Mage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SummonArgStrc summonArg;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget && D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        SKILLS_DamagePaladinCaster(pGame, pUnit, nSkillId, nSkillLevel);

        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            int nSpawnMode;
            const int nMonsterId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
            if (nMonsterId >= 0)
            {
                const int nPetType = (signed char)pSkillsTxtRecord->nPetType;
                if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
                {
                    const int nX = CLIENTS_GetUnitX(pTarget);
                    const int nY = CLIENTS_GetUnitY(pTarget);
                    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pTarget), !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
                    SUNIT_RemoveUnit(pGame, pTarget);
                    memset(&summonArg, 0, sizeof(summonArg));
                    summonArg.nHcIdx = nMonsterId;
                    summonArg.nAiSpecialState = 0;
                    summonArg.nMonMode = nSpawnMode;
                    summonArg.dwFlags = 1;
                    summonArg.pOwner = pUnit;
                    summonArg.pPosition.nX = nX;
                    summonArg.pPosition.nY = nY;
                    summonArg.nPetType = nPetType;
                    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

                    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
                    if (pPet)
                    {
                        D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
                        SKILLS_SetNecroPetComponents(pUnit, pPet, nSkillId, nSkillLevel);
                        D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
                        D2GAME_SetSummonResistance_6FD0C2E0(pUnit, pPet);
                        D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

// 0x005C4CD0
int __fastcall SKILLS_SrvDo032_PoisonDagger(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005C4D10
int __fastcall SKILLS_AuraCallback_ApplyCorpseExplosionDamage(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit)
{
    D2UnkNecSkillStrc2* pArg = (D2UnkNecSkillStrc2*)pAuraCallback->pArgs;
    if (!pArg)
    {
        return 0;
    }

    D2DamageStrc damage = *pArg->pDamage;
    if (pArg->nSquaredRange < PATH_ComputeSquaredDistance(pArg->nX, pArg->nY, CLIENTS_GetUnitXInline(pUnit), CLIENTS_GetUnitYInline(pUnit)))
    {
        damage.dwPhysDamage = 0;
    }

    SUNITDMG_ExecuteEvents(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pAuraCallback->pGame, pAuraCallback->pOwner, pUnit, &damage);
    return 1;
}

// 0x005C4DF0
int __fastcall SKILLS_ExplodeCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget || !D2COMMON_11021(pTarget))
        return 0;
    STATES_ToggleState(pTarget, 104, 1);
    UNITROOM_RefreshUnit(pTarget);
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
        return 0;
    int nLife = STATLIST_GetUnitBaseStat(pTarget, 7, 0);
    if ((!pTarget ? 6 : pTarget->dwUnitType) == 1)
    {
        int nGameType;
        if (pGame->nGameType || pGame->dwGameType)
            nGameType = 1;
        else
            nGameType = 0;
        D2MonStatsInitStrc monStats;
        memset(&monStats, 0, sizeof(monStats));
        const int nMonsterId = pTarget->dwClassId;
        DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, nGameType, pGame->nDifficulty, STATLIST_UnitGetStatValue(pTarget, STAT_LEVEL, 0), 1, &monStats);
        nLife = (monStats.nMinHP + monStats.nMaxHP) << 7;
    }
    int nX = CLIENTS_GetUnitX(pTarget);
    int nY = CLIENTS_GetUnitY(pTarget);
    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwAuraRangeCalc, nSkillId, nSkillLevel);
    int nPhysicalRange = nRange / 2;
    int nElementalRange = (nRange + 1) / 2;
    int nMinDamage = DATATBLS_ApplyRatio(SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[0], nSkillId, nSkillLevel), nLife, 100);
    int nMaxDamage = DATATBLS_ApplyRatio(SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[1], nSkillId, nSkillLevel), nLife, 100);
    int nDamage = nMinDamage + ITEMS_RollLimitedRandomNumber(&pTarget->pSeed, nMaxDamage - nMinDamage);
    int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, STAT_LEVEL, 0);
    int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    if (nTargetLevel && nLevel < nTargetLevel)
        nDamage = DATATBLS_ApplyRatio(nDamage, nLevel, nTargetLevel);
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    int nPct = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[2], nSkillId, nSkillLevel);
    nPct = nPct > 0 ? nPct : 0;
    if (nPct >= 100)
        nPct = 100;
    if (nPct > 0 && pSkills->nEType)
    {
        const int nElementalLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        SKILLS_AddElementalDamage(pUnit, &damage, pSkills->nEType, DATATBLS_ApplyRatio(nDamage, nPct, 100), nElementalLength, 0, 0);
        nDamage = DATATBLS_ApplyRatio(nDamage, 100 - nPct, 100);
    }
    damage.dwPhysDamage = nDamage;
    D2UnkNecSkillStrc2 args;
    args.pDamage = &damage;
    args.nSquaredRange = nPhysicalRange * nPhysicalRange;
    args.nX = nX;
    args.nY = nY;
    SKILLS_IterateAuraTargets(pGame, pUnit, nX, nY, nElementalRange, pSkills->dwAuraFilter, SKILLS_AuraCallback_ApplyCorpseExplosionDamage, &args, 0, gszSkillNecSourceFile, 0x69E);
    return 1;
}

// 0x005C50B0
int __fastcall SKILLS_SrvDo055_CorpseExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return SKILLS_ExplodeCorpse(pGame, pUnit, nSkillId, nSkillLevel);
}

// 0x005C50C0
void __fastcall SKILLS_SetGolemStats(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel)
{
    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, 0, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    D2GAME_SetSummonResistance_6FD0C2E0(pUnit, pPet);
}

// 0x005C5100
int __fastcall SKILLS_SrvDo056_Golem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId || pSkillsTxtRecord->wSummon < 0 || pSkillsTxtRecord->wSummon >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    unsigned char nSumMode = pSkillsTxtRecord->nSumMode;
    if (pSkillsTxtRecord->nSumMode >= 16)
    {
        nSumMode = 1;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.dwFlags = 0;
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = pSkillsTxtRecord->wSummon;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSumMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    SKILLS_SetGolemStats(pGame, pUnit, pPet, nSkillId, nSkillLevel);
    sub_6FC3E200(UnitGetClient(pUnit, ".\\SKILLS\\SkillNec.cpp", 1787), pPet);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
}

// 0x005C5250
int __fastcall SKILLS_SrvDo057_IronGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_SrvSt20_IronGolem(pGame, pUnit, nSkillId, nSkillLevel))
        return 0;
    if (pUnit)
        pUnit->dwFlags |= 0x40;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
        return 0;
    int nSpawnMode;
    int nMonsterId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nMonsterId < 0)
        return 0;
    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
        nPetType = 0;
    D2SummonArgStrc summonArg = {};
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nMonsterId;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.dwFlags = 1;
    summonArg.nPetType = nPetType;
    summonArg.pPosition.nX = CLIENTS_GetUnitX(pUnit);
    summonArg.pPosition.nY = CLIENTS_GetUnitY(pUnit);
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        summonArg.pPosition.nX = CLIENTS_GetUnitX(pTarget);
        summonArg.pPosition.nY = CLIENTS_GetUnitY(pTarget);
    }
    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
        return 0;
    if (pTarget)
    {
        DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pTarget), !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId);
        UNITS_FreeCollisionPath(pTarget);
        UNITROOM_RemoveUnitFromRoom(pTarget);
        unsigned char nBodyLoc1;
        unsigned char nBodyLoc2;
        ITEMS_GetAllowedBodyLocations(pTarget, &nBodyLoc1, &nBodyLoc2);
        UNITS_ChangeAnimMode(pTarget, 4);
        ITEMMODE_EquipCursorItem(pGame, pPet, !pTarget ? -1 : pTarget->dwUnitId, nBodyLoc1, 1, 0);
    }
    SKILLS_SetGolemStats(pGame, pUnit, pPet, nSkillId, nSkillLevel);
    sub_6FC3E200(UnitGetClient(pUnit, ".\\SKILLS\\SkillNec.cpp", 1871), pPet);
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    return 1;
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

// 0x005C5430
static int __stdcall SKILLS_RelocateRevivedTarget(D2GameStrc* pGame, D2UnitStrc* pTarget)
{
    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pTarget), UNITS_GetUnitXPosition(pTarget), UNITS_GetUnitYPosition(pTarget), PATH_GetUnitCollisionPattern(pTarget), 0x8000);
    D2CoordStrc tCoords;
    tCoords.nX = UNITS_GetUnitXPosition(pTarget);
    tCoords.nY = UNITS_GetUnitYPosition(pTarget);
    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pTarget), &tCoords, UNITS_GetUnitSizeX(pTarget), 0x3C01, 1);
    if (!pRoom)
    {
        return 0;
    }
    pTarget->dwFlags |= 0x402000E;
    MONSTER_UpdateAiCallbackEvent(pGame, pTarget);
    D2ModeChangeStrc tModeChange = {};
    MONSTERMODE_GetModeChangeInfo(pTarget, 1, &tModeChange);
    D2GAME_ModeChange_6FC65220(pGame, &tModeChange, 1);
    SKILLS_ClearMonsterMinionOwnership(pTarget);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pTarget, 8, 0);
    if (UNITS_GetRightSkill(pTarget))
    {
        SKILLS_SetRightActiveSkill(pTarget, SKILL_ATTACK, -1);
    }
    return SUNIT_TeleportUnit(pGame, pTarget, pRoom, tCoords.nX, tCoords.nY, 0, 0);
}

// 0x005C55C0
static void __stdcall SKILLS_InitializeRevivedMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMonster, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (nSkillId)
    {
        AIGENERAL_SetOwnerData(pGame, pMonster, !pUnit ? -1 : pUnit->dwUnitId, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, 0, 0);
        AIUTIL_SetOwnerGUIDAndType(pMonster, (pUnit));
        D2GAME_EVENTS_Delete_6FC34840(pGame, pMonster, 2, 0);
        EVENT_SetEvent(pGame, pMonster, 2, pGame->dwGameFrame + 15, 0, 0);
        SUNIT_SetAlignment(pMonster, 2, 0);
        MONSTERAI_ClearTargetOverride(pMonster);

        if (pMonster)
        {
            pMonster->dwFlags |= 0x80000000;
        }

        STATES_ToggleState(pMonster, 0x60, 1);

        const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        if (nDuration > 0)
        {
            D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pMonster, 0x15, 0);
            EVENT_SetEvent(pGame, pMonster, 7, nDuration + pGame->dwGameFrame, 0, 0);
        }
    }
}

// 0x005C56C0
int __fastcall SKILLS_SrvDo058_Revive(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
    {
        return 0;
    }
    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (!sub_005C3300_CanReviveTarget(pTarget))
    {
        return 0;
    }
    SKILLS_DamagePaladinCaster(pGame, pUnit, nSkillId, nSkillLevel);
    SKILLS_RelocateRevivedTarget(pGame, pTarget);
    const int bExpansion = pGame->nGameType || pGame->dwGameType;
    D2MonStatsInitStrc tMonStatsInit;
    memset(&tMonStatsInit, 0, sizeof(tMonStatsInit));
    const int nClassId = pTarget->dwClassId;
    DATATBLS_CalculateMonsterStatsByLevel(nClassId, bExpansion, pGame->nDifficulty, STATLIST_UnitGetStatValue(pTarget, STAT_LEVEL, 0), 1, &tMonStatsInit);
    const int nNewHp = (ITEMS_RollLimitedRandomNumber(&pTarget->pSeed, tMonStatsInit.nMaxHP - tMonStatsInit.nMinHP + 1) + tMonStatsInit.nMinHP) << 8;
    STATLIST_SetUnitStat(pTarget, 7, nNewHp, 0);
    STATLIST_SetUnitStat(pTarget, STAT_HITPOINTS, nNewHp, 0);
    const int nUnitLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    const int nTargetLevel = STATLIST_UnitGetStatValue(pTarget, STAT_LEVEL, 0);
    if (nTargetLevel && nUnitLevel < nTargetLevel)
    {
        int nHitpoints = DATATBLS_ApplyRatio(nNewHp, nUnitLevel, nTargetLevel);
        if (nHitpoints < 1)
        {
            nHitpoints = 1;
        }
        STATLIST_SetUnitStat(pTarget, 7, nHitpoints, 0);
        STATLIST_SetUnitStat(pTarget, STAT_HITPOINTS, nHitpoints, 0);
        STATLIST_SetUnitStat(pTarget, STAT_LEVEL, nUnitLevel, 0);
    }
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pTarget, nSkillId, nSkillLevel, 0);
    SKILLS_InitializeRevivedMonster(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    sub_6FC7D7A0(pGame, pUnit, pTarget, nPetType, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel));
    D2GAME_UpdateSummonAI_6FC401F0(pGame, pTarget, 0, pUnit->dwNodeIndex);
    D2Common_10214(pTarget);
    return 1;
}

static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecordForceInline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x005C58B0
int __fastcall SKILLS_SrvDo060_BoneWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;
    int nLength;
    D2MissileStrc missile;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY)) return 0;
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
    if (pUnit) pUnit->dwFlags |= 0x40;
    D2SkillsTxt* pSkills = SKILLS_GetSkillsTxtRecordForceInline(nSkillId);
    if (!nSkillId) return 0;
    int nSpawnMode;
    int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0) return 0;
    unsigned char nPetType = pSkills->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount) nPetType = 0;
    D2SummonArgStrc summon = {};
    summon.nHcIdx = nSummonId;
    summon.nAiSpecialState = 0;
    summon.dwFlags = 9;
    summon.pOwner = pUnit;
    summon.nMonMode = nSpawnMode;
    summon.pPosition.nX = nX;
    summon.pPosition.nY = nY;
    summon.nPetType = nPetType;
    summon.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwPetMax, nSkillId, nSkillLevel);
    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summon);
    if (!pPet) return 0;
    AIGENERAL_SetOwnerData(pGame, pPet, sub_00451F50(pUnit), sub_0044BE50(pUnit), 0, 1);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 15, 0);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    TARGETS_InsertUnitNode(pGame, pPet, 0, 9);
    nX = CLIENTS_GetUnitX(pPet);
    nY = CLIENTS_GetUnitY(pPet);
    if (!DUNGEON_IsRoomInTown(pRoom))
    {
        nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkills->dwCalc[1], nSkillId, nSkillLevel) / 2;
        if (nLength > 1 && pSkills->wSrvMissileA >= 0 && pSkills->wSrvMissileA < sgptDataTables->nMissilesTxtRecordCount)
        {
            memset(&missile, 0, sizeof(missile));
            missile.dwFlags = 0x21;
            missile.pOwner = pUnit;
            missile.nX = nX;
            missile.nY = nY;
            missile.nSkill = nSkillId;
            missile.nSkillLevel = nSkillLevel;
            missile.nMissile = pSkills->wSrvMissileA;
            int nDeltaX = CLIENTS_GetUnitX(pUnit) - nX;
            int nDeltaY = CLIENTS_GetUnitY(pUnit) - nY;
            if (!nDeltaX && !nDeltaY) nDeltaX = 1;
            missile.nTargetX = nX - nDeltaY;
            missile.nTargetY = nY + nDeltaX;
            D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missile);
            if (pMissile)
            {
                MISSILE_SetTargetX(pMissile, sub_00451F50(pPet));
                MISSILE_SetTargetY(pMissile, nLength);
            }
            missile.nTargetX = nX + nDeltaY;
            missile.nTargetY = nY - nDeltaX;
            pMissile = MISSILES_CreateMissileFromParams(pGame, &missile);
            if (pMissile)
            {
                MISSILE_SetTargetX(pMissile, sub_00451F50(pPet));
                MISSILE_SetTargetY(pMissile, nLength);
            }
        }
        return 1;
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

    return pUnit->pDynamicPath ? sub_006488C0_PathGetX((D2PathRecordStrc*)pUnit->pDynamicPath) : 0;
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

    return pUnit->pDynamicPath ? sub_00648900_PathGetY((D2PathRecordStrc*)pUnit->pDynamicPath) : 0;
}

// 0x005C5BC0
static D2UnitStrc* __stdcall SKILLS_SpawnBonePrisonPet(D2GameStrc* pGame, int nSkillId, D2UnitStrc* pUnit, int nX, int nY, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
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

    if (DUNGEON_IsRoomInTown(sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY)))
    {
        return 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.dwFlags = 9;
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nSummonId;
    summonArg.nAiSpecialState = 0;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.pPosition.nX = nX;
    summonArg.pPosition.nY = nY;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(pGame, pPet, 15, 0);
    TARGETS_InsertUnitNode(pGame, pPet, 0, 9);
    return pPet;
}

// 0x005C5D00
int __fastcall SKILLS_SrvDo062_BonePrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pOwner = 0;
    for (int i = 0; i < 12; ++i)
    {
// build: symbol ?gnBonePrisonOffsetX@* 0x006E304C
// build: symbol ?gnBonePrisonOffsetY@* 0x006E307C
        D2UnitStrc* pPet = SKILLS_SpawnBonePrisonPet(pGame, nSkillId, pUnit, nTargetX + gnBonePrisonOffsetX[i], nTargetY + gnBonePrisonOffsetY[i], nSkillLevel);
        if (pPet)
        {
            if (!pOwner)
            {
                pOwner = pPet;
                AIGENERAL_SetOwnerData(pGame, pPet, GAME_GetUnitGUID(pUnit), GAME_GetUnitTypeOrInvalid(pUnit), 0, 1);
            }
            else
            {
                AIGENERAL_SetOwnerData(pGame, pPet, !pOwner ? -1 : pOwner->dwUnitId, !pOwner ? 6 : pOwner->dwUnitType, 0, 0);
                AIGENERAL_AllocMinionList(pGame, pOwner, pPet);
            }

            UNITS_StoreOwner(pPet, pUnit);
            sub_006488A0_SetDirection((D2PathRecordStrc*)pPet->pDynamicPath, PATH_ComputeDirection(UNITS_GetXPositionInline(pPet), UNITS_GetYPositionInline(pPet), nTargetX, nTargetY));
        }
    }

    return 1;
}

// 0x005C5E60
int __fastcall SKILLS_SrvDo063_PoisonExplosion(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId)
    {
        return 0;
    }

    const short nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
        if (!pTarget || !D2COMMON_11021(pTarget))
        {
            return 0;
        }

        STATES_ToggleState(pTarget, STATE_CORPSE_NOSELECT, 1);
        UNITROOM_RefreshUnit(pTarget);
        MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, pUnit, pTarget, pSkillsTxtRecord->wSrvMissileA, nSkillId, nSkillLevel, 0, 2, 0);
    }

    return 1;
}

// 0x005C5F10
static int SKILLS_AddLifeAndGetGain(D2UnitStrc* pUnit, int nValue)
{
    if (nValue <= 0)
    {
        return 0;
    }

    int nNewHp = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
    nNewHp += nValue;
    if (nNewHp > nMaxHp)
    {
        nValue += (nMaxHp - nNewHp);
        nNewHp = nMaxHp;
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);
    return nValue;
}

// 0x005C5F50
int __fastcall SKILLS_EventFunc04_ReflectPhysicalDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pAttacker)
    {
        return 0;
    }

    if (pAttacker->dwUnitType == UNIT_PLAYER || pAttacker->dwUnitType == UNIT_MONSTER)
    {
        goto Alive;
    }
    return 0;

Alive:
    if (SUNIT_IsDead(pAttacker) || !pDamage || pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (nLevel < 0)
    {
        nLevel = 1;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount || !STATES_CheckState(pAttacker, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        return 0;
    }

    D2UnitStrc* pStatListOwner = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
    int nDamagePercent = 0;
    if (pAttacker->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pAttacker))
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        }
        else
        {
            nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[2], nSkillId, nLevel);
        }
    }
    else
    {
        nDamagePercent = SKILLS_EvaluateSkillFormula(pStatListOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
    }

    D2DamageStrc damage = {};
    damage.dwPhysDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nDamagePercent, 100);
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags | 0x20;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
    SUNITDMG_ExecuteEvents(pGame, pUnit, pAttacker, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pAttacker, &damage);

    if ((!pUnit ? 6 : pUnit->dwUnitType) != UNIT_MONSTER || pUnit->dwClassId != 0x122)
    {
        return 1;
    }

    unsigned char nDrain = 100;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
        if (!pMonStatsTxtRecord)
        {
            return 1;
        }

        nDrain = pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
        if (nDrain <= 0)
        {
            return 1;
        }
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 1;
    }

    int nBaseDamage = damage.dwPhysDamage;
    if (nDrain != 100)
    {
        nBaseDamage = DATATBLS_ApplyRatio(damage.dwPhysDamage, nDrain, 100);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (pOwner && SUNIT_IsDead(pOwner) || SUNIT_IsDead(pAttacker))
    {
        return 1;
    }

    int nDamage = DATATBLS_ApplyRatio(nBaseDamage, 20, 100);
    if (nDamage <= 0)
    {
        return 1;
    }

    if (pOwner)
    {
        nDamage -= SKILLS_AddLifeAndGetGain(pOwner, DATATBLS_ApplyRatio(nDamage, 50, 100));
    }

    nDamage -= SKILLS_AddLifeAndGetGain(pAttacker, nDamage);
    if (pOwner && nDamage > 0)
    {
        SKILLS_AddLifeAndGetGain(pOwner, nDamage);
    }

    UNITS_SetOverlay(pAttacker, 0x97, 0);
    if (pOwner)
    {
        UNITS_SetOverlay(pOwner, 0x97, 0);
    }

    return 1;
}

// 0x005C61E0
int __fastcall SKILLS_EventFunc05_LifeTap(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit)
    {
        return 0;
    }
    if (pAttacker->dwUnitType != UNIT_PLAYER && pAttacker->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    if ((pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER) || SUNIT_IsDead(pUnit) || !pDamage || pDamage->dwPhysDamage <= 0)
    {
        return 0;
    }

    int nLevel = nSkillLevel;
    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    if (nSkillLevel < 0)
    {
        nLevel = 1;
    }
    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount || !STATES_CheckState(pAttacker, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        return 0;
    }

    D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, STATLIST_GetOwnerType(pStatList), STATLIST_GetOwnerGUID(pStatList));
    const int nPercent = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
    const int nLifeGain = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercent, 100);
    int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nLife <= 0 || nMaxLife <= 0)
    {
        return 0;
    }
    nLife += nLifeGain;
    nLife = D2_MIN(nLife < 1 ? 1 : nLife, nMaxLife);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nLife, 0);
    if (pSkillsTxtRecord->wPrgOverlay > 0 && pSkillsTxtRecord->wPrgOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pUnit, pSkillsTxtRecord->wPrgOverlay, 0);
    }
    return 1;
}

inline int SKILLS_IsValidPetType_Inline(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

// 0x005C6370
int __fastcall SKILLS_EventFunc22_AbsorbPhysicalDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker)
    {
        return 0;
    }

    if (!pDamage)
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

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pAttacker, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        return 0;
    }

    const int nStat1 = pSkillsTxtRecord->wAuraStat[1];
    if (nStat1 < 0 || nStat1 >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    const int nValue1 = STATLIST_GetStatValue(pStatList, nStat1, 0);
    if (nValue1 <= 0)
    {
        return 0;
    }

    const int nStat0 = pSkillsTxtRecord->wAuraStat[0];
    if (nStat0 < 0 || nStat0 >= sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return 0;
    }

    int nValue0 = STATLIST_GetStatValue(pStatList, nStat0, 0);
    if (nValue0 > 0)
    {
        if (nValue0 <= pDamage->dwPhysDamage)
        {
            pDamage->dwPhysDamage -= nValue0;
            nValue0 = 0;
        }
        else
        {
            nValue0 -= pDamage->dwPhysDamage;
            pDamage->dwPhysDamage = 0;
        }

        STATLIST_SetStat(pStatList, nStat0, nValue0, 0);
    }

    if (nValue0)
    {
        const int nParam = DATATBLS_ApplyRatio(nValue0, 100, nValue1);
        int nDiff = nParam - STATLIST_GetStatValue(pStatList, STAT_UNSENTPARAM1, 0);
        nDiff = nDiff < 0 ? -nDiff : nDiff;
        if (nDiff >= 5)
        {
            STATES_ToggleGfxStateFlag(pAttacker, pSkillsTxtRecord->nAuraState, 1);
            STATLIST_SetStat(pStatList, STAT_UNSENTPARAM1, nParam, 0);
        }
    }
    else
    {
        STATES_ToggleState(pAttacker, pSkillsTxtRecord->nAuraState, 0);
        D2Common_10474(pAttacker, pStatList);
        STATLIST_FreeStatList(pStatList);
    }

    return 1;
}

int __fastcall sub_005C6870_FeedBloodGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nValue)
{
    if (!pUnit)
    {
        return nValue;
    }

    D2UnitStrc* pGolem = PLAYERPETS_GetFirstPetByType(pGame, pUnit, 3, 0);
    if (!pGolem)
    {
        return nValue;
    }
    if (pGolem->dwUnitType != UNIT_MONSTER)
    {
        return nValue;
    }
    const int nClassId = pGolem->dwClassId;
    if (nClassId != 0x122)
    {
        return nValue;
    }

    if (nValue)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nSkill[0] >= 0)
        {
            nValue -= SKILLS_AddLifeAndGetGain(pGolem, SKILLDESC_GetSkillParamSix(pMonStatsTxtRecord->nSkill[0]) * nValue / 100);
        }
    }
    else
    {
        STATLIST_SetUnitStat(pGolem, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pGolem), 0);
    }

    return nValue;
}

// 0x005C6530
int __fastcall D2GAME_EventFunc23_6FD0F1F0(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pUnit || !pDamage)
    {
        return 0;
    }

    if (pUnit->dwUnitType != UNIT_PLAYER)
    {
        if (pUnit->dwUnitType != UNIT_MONSTER)
        {
            return 0;
        }
    }

    unsigned char nDrain = 100;
    if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = sub_0055B7E0_GetMonStatsTxtFromUnit(pUnit);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }

        nDrain = pMonStatsTxtRecord->nDrain[pGame->nDifficulty];
        if (nDrain <= 0)
        {
            return 0;
        }
    }

    if (STATLIST_GetUnitAlignment(pUnit))
    {
        return 0;
    }

    int nDamage = pDamage->dwPhysDamage;
    if (nDrain != 100)
    {
        nDamage = DATATBLS_ApplyRatio(nDamage, nDrain, 100);
    }

    if (nDamage >= STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0))
    {
        nDamage = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pAttacker);
    if (pOwner && SUNIT_IsDead(pOwner) || SUNIT_IsDead(pAttacker))
    {
        return 0;
    }

    const int nPercentage = D2Common_11034(nSkillLevel, nSkillId);
    if (nPercentage <= 0)
    {
        return 0;
    }

    int nBaseDamage = DATATBLS_ApplyRatio(nDamage, nPercentage, 100);
    if (nBaseDamage <= 0)
    {
        return 0;
    }

    const int nParam = SKILLDESC_GetSkillParamThree(nSkillId);
    if (pOwner && nParam > 0)
    {
        nBaseDamage -= SKILLS_AddLifeAndGetGain(pOwner, DATATBLS_ApplyRatio(nBaseDamage, nParam, 100));
    }

    const int nFinalDamage = nBaseDamage - SKILLS_AddLifeAndGetGain(pAttacker, nBaseDamage);
    if (pOwner && nFinalDamage > 0)
    {
        SKILLS_AddLifeAndGetGain(pOwner, nFinalDamage);
    }

    UNITS_SetOverlay(pAttacker, 0x97, 0);

    if (nParam > 0 && pOwner)
    {
        UNITS_SetOverlay(pOwner, 0x97, 0);
    }

    return 1;
}

// 0x005C6690
int __fastcall SKILLS_EventFunc26_ShareDamageWithOwner(D2GameStrc* pGame, int nEvent, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pDamage)
    {
        return 0;
    }

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    if (pDamage->dwDmgTotal <= 0)
    {
        return 0;
    }

    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        return 0;
    }

    if (SUNIT_IsDead(pOwner))
    {
        return 0;
    }

    int nLife = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
    if (nLife < 0x100)
    {
        return 0;
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    if (pMonStatsTxtRecord->nSkill[0] >= 0)
    {
        const int nDamage = DATATBLS_ApplyRatio(pDamage->dwDmgTotal, SKILLDESC_GetSkillParamFive(pMonStatsTxtRecord->nSkill[0]), 100);
        nLife -= nDamage;
        if (nLife < 0x100)
        {
            nLife = 0x100;
        }

        STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nLife, 0);
        pDamage->dwDmgTotal -= nDamage;
        pDamage->dwDmgTotal = pDamage->dwDmgTotal > 0 ? pDamage->dwDmgTotal : 0;
        return 1;
    }

    return 0;
}

// 0x005C6760
int __fastcall SKILLS_EventFunc27_Slow(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pTarget, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
{
    if (!pAttacker || !pTarget)
        return 0;
    int nSlow = STATLIST_UnitGetItemStatOrSkillStatValue(pAttacker, SLOW_STAT, 0);
    if (!nSlow)
        return 0;
    if (pTarget->dwUnitType == UNIT_PLAYER)
    {
        if (nSlow >= SMALL_CAP)
            nSlow = SMALL_CAP;
    }
    else if (pTarget->dwUnitType == UNIT_MONSTER)
    {
        if (sub_005A0180((Unit005A0180*)pTarget, UNITMASK_MONSTER))
        {
            if (nSlow >= SMALL_CAP)
                nSlow = SMALL_CAP;
        }
        else if (nSlow >= LARGE_CAP)
            nSlow = LARGE_CAP;
    }
    else
        return 0;
    D2CurseStrc curse = {};
    nSlow = -nSlow;
    curse.pUnit = pAttacker;
    curse.pTarget = pTarget;
    curse.nSkill = 0;
    curse.nSkillLevel = 1;
    curse.nDuration = CURSE_DURATION;
    curse.nStat = STAT_A;
    curse.nStatValue = nSlow;
    curse.nState = CURSE_STATE;
    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (!pStatList)
        return 0;
    STATLIST_SetStatValue(pStatList, STAT_B, nSlow, 0);
    STATLIST_SetStatValue(pStatList, STAT_C, nSlow, 0);
    UnitUpdateAnimRateAndVel(pTarget, ".\\SKILLS\\SkillNec.cpp", SOURCE_LINE);
    return 1;
}

static inline int sub_IsBloodGolem(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_MONSTER && (!pUnit ? -1 : pUnit->dwClassId) == 290;
}

// 0x005C6870
int __fastcall SKILLS_SharePotionLifeWithBloodGolem(D2GameStrc* pGame, D2UnitStrc* pUnit, int nLife)
{
    if (!pUnit)
    {
        return nLife;
    }

    D2UnitStrc* pBloodGolem = PLAYERPETS_GetFirstPetByType(pGame, pUnit, 3, 0);
    if (!sub_IsBloodGolem(pBloodGolem))
    {
        return nLife;
    }

    if (nLife)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pBloodGolem->dwClassId);
        if (pMonStatsTxtRecord && pMonStatsTxtRecord->nSkill[0] >= 0)
        {
            const int nParam = SKILLDESC_GetSkillParamSix(pMonStatsTxtRecord->nSkill[0]);
            const int nResult = nLife - SKILLS_AddLifeAndGetGain(pBloodGolem, nParam * nLife / 100);

            return nResult;
        }
    }
    else
    {
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pBloodGolem);
        STATLIST_SetUnitStat(pBloodGolem, STAT_HITPOINTS, nMaxHp, 0);
    }

    return nLife;
}

#include "gen/data/Source/D2Game/SKILLS/SkillNec.inc"
