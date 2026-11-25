#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2MonModes.h"
#include "D2ObjModes.h"
#include "D2StatIds.h"
#include "D2MissileIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2ItemsWorld.h"
#include "D2QuestData.h"
#include "D2GameServer.h"
#include "D2TxtItems.h"
#include "D2GameObjs.h"
#include "D2TxtTables.h"
#include "D2LevelTxt.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
#include "D2GameCallbackArgs.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNITFLAGEX_0x40000 0x40000

#define PATHTYPE_CHARGEDBOLT 10

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

#define QUEST_A5Q6_BAAL 36

#define UNITFLAG_ISMERC 0x00000200

#define UNITFLAG_NOTC 0x00020000

struct D2MonsterDataStrc;

struct D2ModeChangeStrc;

struct D2MonStatsTxt;

struct D2MissilesTxt;

struct D2StaticPathStrc;

struct D2HitFunc22ParamStrc;

struct D2AuraCallbackStrc;

union D2SeedStrc;

struct D2SkillsTxt;

enum D2MiscConstants
{
    EVENTTYPE_MONUMOD = 7,
    ELEMTYPE_NONE = 0,
    ELEMTYPE_FIRE = 1,
    ELEMTYPE_LTNG = 2,
    ELEMTYPE_MAGIC = 3,
    ELEMTYPE_COLD = 4,
    ELEMTYPE_POIS = 5,
    ELEMTYPE_LIFE = 6,
    ELEMTYPE_MANA = 7,
    ELEMTYPE_STAMINA = 8,
    ELEMTYPE_STUN = 9,
    ELEMTYPE_RAND = 10,
    ELEMTYPE_BURN = 11,
    ELEMTYPE_FREEZE = 12,
};

typedef void (__fastcall* UModInitFunc)(D2UnitStrc* pUnit, int nUMod, int bUnique);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" UModInitFunc gpfnUModInitFunctions[]; // 0x0073C008

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __fastcall PLAYERLIST_AllocPlayerList(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B140

void __fastcall PLAYERLIST_ToggleFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags, int bSet); // 0x0055B260

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

unsigned char __stdcall MISSILE_GetElemTypeFromMissileId(int nMissileId); // 0x0064B0C0

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile); // 0x0064A730

void __fastcall MISSMODE_CreateCairnPortal(D2GameStrc* pGame, D2UnitStrc* pMissile, int nParam); // 0x005A9930

void __stdcall DUNGEON_ToggleHasPortalFlag(D2ActiveRoomStrc* pRoom, int bSet); // 0x0061AED0

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nUnused);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall MISSILE_GetLevel(D2UnitStrc* pMissile); // 0x0064A210

int __stdcall MISSILE_GetSkill(D2UnitStrc* pMissile); // 0x0064A280

struct D2HitFunc22ParamStrc
{
    D2UnitStrc* pOwner;
    D2UnitStrc* pOrigin;
    int nSkillId;
    int nLevel;
    int nParam;
    int nHitSubMissile;
};

int __fastcall D2GAME_CreatePortalObject_6FD13DF0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int nDestLevel, D2UnitStrc** ppSourceUnit, int nObjectId, int bPerm); // 0x0056D130

int __fastcall SUNITDMG_IsHitSuccessful(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int bMissile); // 0x0057D9B0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath);

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection);

void __stdcall D2COMMON_10203_PATH_SetRotateFlag(D2DynamicPathStrc* pPath, int bClear); // 0x00649030

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __cdecl VIEW_ClearGlobals(); // 0x00476AF0

int __fastcall MONSTERSPAWN_SpawnRandomMonsterForLevel(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x005B3570

extern const int gnSrvHit52_XOffsets[8]; // 0x006E2A58

extern const int gnSrvHit52_YOffsets[8]; // 0x006E2A38

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile); // 0x0064A3B0

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __fastcall SKILLS_CreateMissilesAroundTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nMissileId, int nCount, int nRange, int nSkillId, int nSkillLevel); // 0x005D5BF0

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops); // 0x005A9370

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __fastcall SKILLS_ExecuteServerDoFunction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nDoFunc, int nSkillId, int nSkillLevel); // 0x0056D810

int __stdcall QUESTS_CheckNotIntroQuest(D2GameStrc* pGame, int nQuestId); // 0x005444B0

void __fastcall ACT5Q6_SpawnTyrael(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, D2UnitStrc* pMissile); // 0x0058E920

int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int a4); // 0x005ADF10

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3); // 0x00621E40

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647BC0

int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647D00

int __stdcall MISSILE_EvaluateMissileFormula(D2UnitStrc* pMissile, D2UnitStrc* pOwner, unsigned int nCalc, int nMissileId, int nLevel); // 0x0064B7C0

void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage); // 0x005A9270

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel); // 0x004E6CA0

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag); // 0x00644F20

void __fastcall MISSMODE_SrvDmg05_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD2F0

int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A8C70

int __stdcall MONSTERS_IsDemon(D2UnitStrc* pMonster); // 0x0063E940

typedef int(__fastcall* MISSILESRVHITFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit);

extern MISSILESRVHITFN gpfMissileSrvHitFn[]; // 0x0073C840

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

enum
{
    MISSILESFLAGINDEX_TOWN = 10,
    MISSILESFLAGINDEX_SRCTOWN = 11,
};

typedef int(__fastcall* MISSMODE_SRVDO)(D2GameStrc* pGame, D2UnitStrc* pMissile);

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern MISSMODE_SRVDO gpfnMissileSrvDoFunctions[]; // 0x0073C768

extern int gnMissileSrvDoFuncCount; // 0x0073C71C

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

typedef int(__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

int __fastcall SKILLDESC_GetSkillParamSix(int nSkillId); // 0x004F4110

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0

int __fastcall MISSMODE_LightningFury_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget); // 0x005AB2A0

void __fastcall AIUTIL_ApplyTerrorCurseState(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId, int nDuration, int nParam); // 0x005DDD00

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2); // 0x006492A0

int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc* pPath); // 0x006505C0

typedef void (__fastcall* MISSILESRVDMGFN)(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage);

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern MISSILESRVDMGFN gpfnMissileSrvDmgFunctions[]; // 0x0073C960

void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005AD730

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall SUNITEVENT_Trigger(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage); // 0x005C0C30

void __fastcall MISSMODE_FillDamageParams(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A89A0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit);             // 0x00554DE0

int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);                     // 0x0056E900

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse);                                               // 0x0056E970

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

void __fastcall sub_005A8F20_SetElementalLength(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength); // 0x005A8F20

int __fastcall MISSMODE_SrvHit44_ExplodingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x005A9E10

int __fastcall MISSMODE_CreatePantherPotGreenSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nStep); // 0x005AB700

void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame);                                 // 0x006260B0

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet);                          // 0x00639E30

int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc* pMissile);                                        // 0x0064A380

#define EVENTTYPE_REMOVESTATE 12

enum D2C_Q05MissModeConstants
{
    EVENTTYPE_ENDANIM = 1,
};

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode);                                           // 0x00624690

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90

void __fastcall SKILLS_ApplyTargetAuraAndMissile(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nFrame, int nSkillId, int nSkillLevel); // 0x005C7DB0

int __fastcall MISSMODE_FistOfTheHeavensDelay_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget); // 0x005AB630

int __stdcall MISSILE_GetTargetY(D2UnitStrc* pMissile);                                                     // 0x0064A780

static void __fastcall MISSMODE_ApplyDamageFlagsAndTargetAc(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005ADCD0

static int MISSMODE_IsUnitTypeValidForMissileMode(int nMissileMode, D2UnitStrc* pUnit); // 0x005ADA40

enum D2C_M11MeteorConstants
{
    MONSTATS2FLAGINDEX_LARGE = 11,
};

int __fastcall MISSILE_GetSkillMissileRange(int nSkillId, int nLevel); // 0x004CC7C0

struct D2AiParamStrc;

struct D2PlayerDataStrc;

struct D2DoorObjectAiCallbackArgStrc;

struct D2UnkMonCreateStrc;

struct D2Act3Quest5Strc;

struct D2Act4Quest1Strc;

struct D2Act4Quest3Strc;

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10


extern "C" const char gszAct3Q2SourceFile[]; // 0x006E2E84

int __fastcall SKILLS_ApplyRedemptionEffect(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillId, int nSkillLevel, int bSkipChanceRoll); // 0x005D0C40

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __fastcall PLRINTRO_GetQuestIntroFlag(D2UnitStrc* pUnit, D2GameStrc* pGame, int nNpcId); // 0x005723C0

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nSoundId, D2UnitStrc* pOrigin); // 0x00553380

int __fastcall SKILLS_SrvDo142_ApplyAreaCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7CE0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

#define D2_MIN(a,b) ((a) < (b) ? (a) : (b))

void __fastcall MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage); // 0x005A91C0

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2DamageStrc* pDamage); // 0x0057CEE0

int __fastcall SUNITDMG_ApplyBlockOrDodge(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bAvoid, int bBlock); // 0x0057DFB0

void __fastcall D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x005A5560

int __stdcall MISSILE_GetHitClass(D2UnitStrc* pMissile); // 0x0064A5A0

static int MISSMODE_GetPierceFlags(D2UnitStrc* pMissile);

static void __fastcall MISSMODE_SetJustHitState(D2UnitStrc* pMissile, D2UnitStrc* pUnit); // 0x005ADB00

enum D2C_DamageFlags
{
    DAMAGEHITFLAG_BYPASSUNDEAD = 0x100,
    DAMAGEHITFLAG_BYPASSDEMON = 0x200,
    DAMAGEHITFLAG_BYPASSBEASTS = 0x400,
    DAMAGERESULTFLAG_CRITICALSTRIKE = 0x2000,
};

int __fastcall SUNITDMG_CheckMonType(int nMonType1, int nMonType2); // 0x0057A830

int __fastcall SUNIT_CanPetBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pPet, int nSkillId); // 0x005542C0

int __fastcall SUNIT_CanAllyBeTargetedBySkill(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, int nSkillId); // 0x00554D20


struct Damage {
    unsigned int hitFlags; unsigned short resultFlags,extra;
    int physical,enhancedPercent,fire,burn,burnLength,lightning,magic,cold,poison,
        poisonLength,coldLength,freezeLength,lifeLeech,manaLeech,staminaLeech,stunLength;
};

enum { ZERO_DAMAGE=0 };

static int __stdcall MISSMODE_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY);

void __fastcall SEED_InitSeed(D2SeedStrc*, int); // 0x00650E40

int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc*, D2UnitStrc*); // 0x005AE1F0

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __stdcall sub_00650BE0_PlaceUnit(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00650BE0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

void __fastcall MISSMODE_CreateImmolationArrowHitSubmissiles(D2GameStrc*, D2UnitStrc*, int, int, int); // 0x005A9530

int __fastcall sub_0056BAD0_ApplyAreaDamage(D2GameStrc*, D2UnitStrc*, int, int, int, D2DamageStrc*, unsigned int); // 0x0056BAD0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY); // 0x006417F0

D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10

unsigned short __stdcall D2Common_10201(D2DynamicPathStrc* pDynamicPath); // 0x00648EB0

int __fastcall SKILLDESC_GetSkillParamTwo(int); // 0x004EFC20

int __fastcall SKILLDESC_GetSummonLevel(int, int); // 0x004EFCB0

typedef char D2MissilesTxt_size_check[sizeof(D2MissilesTxt) == 0x1A4 ? 1 : -1];

static void __stdcall MISSMODE_SetGuidedMissileTarget(D2UnitStrc* pTarget, D2UnitStrc* pMissile);

static int __stdcall MISSMODE_FindGuidedMissileTarget(D2GameStrc* pGame, D2UnitStrc* pMissile);

int __fastcall MISSMODE_SrvHit10_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit);

struct D2PathPointStrc;

struct D2MissileUnitFindTableStrc;

struct D2MissileFindArgStrc;

struct D2MissileFindArgStrc
{
    D2GameStrc* pGame;
    D2UnitStrc* pMissile;
    D2UnitStrc* pOwner;
    D2MissilesTxt* pMissilesTxtRecord;
};

extern D2MissileUnitFindTableStrc gtMissileCollisionModes[]; // 0x0073C720

int __fastcall SUNIT_UpdateUnitPath(D2GameStrc*, D2UnitStrc*); // 0x00554CA0

int __stdcall PATH_GetVelocity(D2DynamicPathStrc*); // 0x006486C0

int __stdcall MISSILE_GetCurrentFrame(D2UnitStrc*); // 0x0064A380

int __stdcall MISSILE_GetActivateFrame(D2UnitStrc*); // 0x0064A640

int __stdcall D2COMMON_10198_PathGetSaveStep(D2DynamicPathStrc*, D2PathPointStrc**); // 0x00648F40

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc*, int, int, int, int); // 0x0064D9B0

D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc*, int, int, void*, void*, int); // 0x00641CB0

void __fastcall MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int nMissileId, int nRange, int nLoops); // 0x005A9720

void __fastcall SUNIT_ValidateTargetUnit(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x00553490

int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc* pUnit); // 0x00625D60

void __stdcall COLLISION_SetMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB90

int __fastcall MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AF540

int __stdcall D2COMMON_10473(D2StatListStrc* pStatList); // 0x00626090

int __fastcall MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE780

static void MISSMODE_PlacePathAtOwner(D2GameStrc* pGame, D2UnitStrc* pMissile);

struct D2DataTables;

struct D2SummonArgs;

struct D2DataTables
{
    char pad[0xb64];
    D2MissilesTxt* missiles;
    int unknown;
    int count;
};

extern D2DataTables* gpDataTables; // 0x00744304

int __fastcall sub_0045C3E0_RollLimited(D2SeedStrc*,int); // 0x0045C3E0

void __stdcall COLLISION_SetMaskWithSize(D2ActiveRoomStrc*,int,int,int,unsigned short); // 0x0064EA00

struct D2SummonArgs
{
    int mode;
    D2UnitStrc* owner;
    int monsterId;
    int unknown;
    int variant;
    int x;
    int y;
    int petType;
    int flags;
};

int __stdcall sub_0064A780_GetCount(D2UnitStrc*); // 0x0064A780

int __stdcall PATH_HasEnteredNewSubtile(void*); // 0x006505C0

int __stdcall sub_0064A280_GetSkill(D2UnitStrc*); // 0x0064A280

int __stdcall sub_0064A210_GetSkillLevel(D2UnitStrc*); // 0x0064A210

int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc*,int,int,int,int*,int,int); // 0x0056E620

int __stdcall sub_0064A730_GetUnitId(D2UnitStrc*); // 0x0064A730

D2UnitStrc* __fastcall sub_0056D940_Summon(D2GameStrc*,D2SummonArgs*); // 0x0056D940

void __fastcall AIGENERAL_SetOwnerData(D2GameStrc*,D2UnitStrc*,int,int,int,int); // 0x0058F030

void __fastcall AIGENERAL_AllocMinionList(D2GameStrc*,D2UnitStrc*,D2UnitStrc*); // 0x0058F100

void __fastcall D2GAME_BOSSES_AssignUMod_6FC6FF10(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850

void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc*,D2UnitStrc*,D2UnitStrc*,int,int,int); // 0x005C4470

void __stdcall UNITS_StoreOwner(D2UnitStrc*,D2UnitStrc*); // 0x00621CE0

void __fastcall TARGETS_InsertUnitNode(D2GameStrc*,D2UnitStrc*,int,int); // 0x005B1990

static void __stdcall MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(D2GameStrc* pGame, int nMissileId, int nRange, int nStep, D2UnitStrc* pMissile);

struct D2ObjectControlStrc;

struct D2ObjOperateFnStrc;

void __fastcall OBJMODE_OpenTowerChest(D2ObjOperateFnStrc* pOp); // 0x00585E00

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

D2ActiveRoomStrc* __fastcall D2GAME_GetFreeSpaceEx_6FC4BF00(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoords, D2CoordStrc* pReturnCoords, int nUnitSize, unsigned char bAllowNeighborRooms); // 0x00555DA0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2UnitStrc* __fastcall D2GAME_CreateItemEx_6FC4ED80(D2GameStrc* pGame, D2ItemDropStrc* pItemDrop, int bUseSeed); // 0x00558D90

void __fastcall SKILLS_ApplyAreaEffectAtCoordinates(D2GameStrc* pGame, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, void* pArg8); // 0x0056DDE0

int __fastcall MISSMODE_RadamentDeathAreaEffectCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused); // 0x005AD8F0

int __fastcall MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused); // 0x005AD910

unsigned int __fastcall SEED_GetLowSeed(D2SeedStrc* pSeed); // 0x00650E50

int __fastcall MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);

int __fastcall MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile); // 0x005AE480

int __fastcall MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile);

#define MONSTATSFLAGINDEX_OPENDOORS 3

struct D2MonStats2Txt;

typedef D2UnitStrc* (__fastcall* AITARGETCALLBACK)(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, void*);

typedef void (__fastcall* AIPARAMFN)(D2GameStrc*, D2UnitStrc*, D2AiTickParamStrc*);

struct SynCoord;

struct SynStatic;

struct SynUnit;

struct SynCoord
{
    int nX;
    int nY;
};

struct SynStatic
{
    char unk0[0x0C];
    SynCoord tGameCoords;
};

struct SynUnit { int dwUnitType; char unk4[0x28]; union { SynStatic* pStaticPath; D2DynamicPathStrc* pDynamicPath; }; };

int __stdcall sub_00620510_UNITS_GetUnitSizeX(SynUnit* pUnit); // 0x00620510

static D2UnitStrc* __stdcall MISSMODE_CreateMissileWithCollisionCheck(D2GameStrc* pGame, int nRange, int nMissileId, unsigned short nMask, D2UnitStrc* pMissile, int nRate); // 0x005A9820

int __fastcall MISSMODE_SrvDo08_MonBlizzCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

int __fastcall MISSMODE_SrvDo10_BlizzardCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

int __fastcall MISSMODE_SrvDo25_EruptionCenter(D2GameStrc* pGame, D2UnitStrc* pMissile);

static int sub_005ADA80_GetPierceFlags(D2UnitStrc* pMissile); // 0x005ADA80

extern "C" int __stdcall MISSILE_GetMissileTargetStatus(D2UnitStrc* pMissile); // 0x0064A730

extern "C" int __stdcall MISSILE_targetValue(D2UnitStrc* pMissile); // 0x0064A780

int __stdcall MISSILE_GetRemainingFrames(D2UnitStrc* pMissile); // 0x0064A3B0

#define MONTYPEFLAG_LIGHTNINGUNIQUE 0x100

struct D2MonLvlTxt;

struct D2MonUModTxt;

enum D2C_H16ElemConstants
{
    MONLVL_DM = 6,
};


static D2MonStatsTxt* MONSTERMODE_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static int D2GAME_GetMonsterBaseId_6FC64B10(D2UnitStrc* pUnit)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType == UNIT_MONSTER)
    {
        D2MonStatsTxt* pMonStatsTxtRecord = MONSTERMODE_GetMonStatsTxtRecord(pUnit->dwClassId);
        if (pMonStatsTxtRecord)
        {
            return pMonStatsTxtRecord->nBaseId;
        }

        return pUnit->dwClassId;
    }

    return -1;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    }

    return 0;
}

// 0x005A8910
static int __stdcall MISSMODE_RollDamageValue(D2UnitStrc* pUnit, int nMinDamStat, int nMasteryStat, int nMaxDamStat)
{
    int nMaxDam = STATLIST_UnitGetStatValue(pUnit, nMaxDamStat, 0);
    if (nMaxDam <= 0)
    {
        return 0;
    }

    int nMinDam = STATLIST_UnitGetStatValue(pUnit, nMinDamStat, 0);
    if (nMinDam <= 0)
    {
        return 0;
    }

    if (nMinDam > nMaxDam)
    {
        const int nTemp = nMinDam;
        nMinDam = nMaxDam;
        nMaxDam = nTemp;
    }

    if (nMasteryStat != -1)
    {
        const int nMastery = STATLIST_UnitGetStatValue(pUnit, nMasteryStat, 0);
        if (nMastery)
        {
            nMinDam += DATATBLS_ApplyRatio(nMinDam, nMastery, 100);
            nMaxDam += DATATBLS_ApplyRatio(nMaxDam, nMastery, 100);
        }
    }

    return nMinDam + ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMaxDam - nMinDam);
}

// 0x005A9370
int __fastcall MISSMODE_CreatePoisonCloudHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nSubStep, int nMainStep, int nLoops)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pOwner || !pOrigin)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x17;
    if (nLoops > 0)
    {
        missileParams.dwFlags = 0x1F;
        missileParams.nLoops = nLoops;
    }

    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = CLIENTS_GetUnitX(pOrigin);
    missileParams.nY = CLIENTS_GetUnitY(pOrigin);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    if (nMainStep < 1)
    {
        nMainStep = 1;
    }

    static const int xOffsets[16] = { 0, 1, 2, 2, 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1 };
    static const int yOffsets[16] = { 2, 2, 2, 1, 0, -1, -2, -2, -2, -2, -2, -1, 0, 1, 2, 2 };

    for (int i = 0; i < 16; i += nMainStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    if (nSubStep)
    {
        missileParams.nVelocity = pMissilesTxtRecord->dwParam[1] << 7;

        for (int i = 0; i < 15; i += nSubStep)
        {
            missileParams.nTargetX = xOffsets[i + 1];
            missileParams.nTargetY = yOffsets[i + 1];
            MISSILES_CreateMissileFromParams(pGame, &missileParams);
        }
    }

    return 1;
}

// 0x005A94C0
static int __stdcall MISSMODE_CheckDistanceAndLineOfSight(int nMaxDistanceSq, int nX, int nY, D2ActiveRoomStrc* pRoom, int nOffsetX, int nOffsetY)
{
    if (!pRoom)
    {
        return 0;
    }

    if (nOffsetX * nOffsetX + nOffsetY * nOffsetY > nMaxDistanceSq)
    {
        return 0;
    }

    D2CoordStrc begin;
    begin.nX = nX;
    begin.nY = nY;
    D2CoordStrc end;
    end.nX = nX + nOffsetX;
    end.nY = nY + nOffsetY;
    return !COLLISION_RayTrace(pRoom, &begin, &end, 4);
}

// 0x005A9D80
int __fastcall MISSMODE_SrvHit02_PlagueJavelin_PoisonPotion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 3;
    }

    D2UnitStrc* pOrigin = pUnit;
    if (!pUnit)
    {
        pOrigin = pMissile;
    }

    MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, SUNIT_GetOwner(pGame, pMissile), pOrigin, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->dwHitPar[0], pMissilesTxtRecord->dwHitPar[1], pMissilesTxtRecord->dwHitPar[2]);
    return 3;
}

// 0x005A9F90
int __fastcall MISSMODE_SrvHit03_ExplosivePotion_BombOnGround(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return MISSMODE_SrvHit44_ExplodingJavelin(pGame, pMissile, 0);
    }

    return 0;
}

// 0x005AA1C0
int __fastcall MISSMODE_SrvHit06_SpawnMonster(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;

    pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->dwHitPar[0] >= 0 && pMissilesTxtRecord->dwHitPar[0] < sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nSpawnMode = MONMODE_NEUTRAL;
        if (pMissilesTxtRecord->dwHitPar[1] >= 0 && pMissilesTxtRecord->dwHitPar[1] < 16)
        {
            nSpawnMode = pMissilesTxtRecord->dwHitPar[1];
        }

        D2GAME_SpawnPresetMonster_6FC66560(pGame, UNITS_GetRoom(pMissile), pMissilesTxtRecord->dwHitPar[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), nSpawnMode);
    }

    return 1;
}

// 0x005AA650
int __fastcall MISSMODE_SrvHit10_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (DUNGEON_IsRoomInTown(UNITS_GetRoom(pMissile)))
    {
        return 1;
    }

    const int v8 = MISSILE_GetTargetX(pMissile);
    if (!pUnit && v8 & 4)
    {
        return 1;
    }

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    const unsigned short v9 = D2Common_10201(pPath);
    if (!pUnit && v9 & 4)
    {
        return 1;
    }

    if (v8 & 1)
    {
        if (pUnit && pUnit != SUNIT_GetTargetUnit(pGame, pMissile))
        {
            return 4;
        }

        return 3;
    }

    if (v8 & 2)
    {
        if (sub_0064A380_GetRemainingFrames(pMissile) <= 0)
        {
            return MISSMODE_FindGuidedMissileTarget(pGame, pMissile) ? 1 : 4;
        }

        return (v8 & 4) ? 3 : 4;
    }

    return 3;
}

// 0x005AB0B0
int __fastcall MISSMODE_SrvHit18_Shout_BattleCommand_BattleOrders(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (pUnit && SUNIT_AreUnitsAligned(pGame, pOwner, pUnit))
    {
        SKILLS_ApplyWarcryStats(pGame, pUnit, pOwner, MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile));
    }

    return 0;
}

// 0x005AB820
int __fastcall MISSMODE_SrvHit25_PantherPotGreen(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        pUnit = pMissile;
    }

    int nHitPar = pMissilesTxtRecord->dwHitPar[0];
    if (nHitPar < 1)
    {
        nHitPar = 1;
    }

    MISSMODE_CreatePantherPotGreenSubmissiles(pGame, pOwner, pUnit, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nHitPar);
    return 3;
}

// 0x005ABA00
int __fastcall MISSMODE_SrvHit27_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    return 1;
}

// 0x005ABD70
int __fastcall MISSMODE_SrvHit31_FireHead(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    D2DamageStrc damage = {};
    const int nDamage = MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    const int nHeal = nDamage < 0 ? 0 : nDamage;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pOwner);
    const int nHp = nHeal + STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
    const int nNewHp = nHp < nMaxHp ? nHp : nMaxHp;
    STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nNewHp, 0);

    if (pMissilesTxtRecord->nCollideKill)
    {
        return 3;
    }

    return 2;
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

// build: symbol ?xOffsets@?7??MISSMODE_CreatePantherPotGreenSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHH@Z@4QBHB 0x006E2618
// build: symbol ?xOffsets@?BB@??MISSMODE_CreatePoisonCloudHitSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHHHH@Z@4QBHB 0x006E2510
// build: symbol ?yOffsets@?7??MISSMODE_CreatePantherPotGreenSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHH@Z@4QBHB 0x006E25F8
// build: symbol ?yOffsets@?BB@??MISSMODE_CreatePoisonCloudHitSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1HHHHHH@Z@4QBHB 0x006E24D0
// 0x005A8F20
void __fastcall MISSMODE_SetElementalLength(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused, D2DamageStrc* pDamage, int nValue)
{
    if (pMissile)
    {
        switch (MISSILE_GetElemTypeFromMissileId(!pMissile ? -1 : pMissile->dwClassId))
        {
        case 4:
            pDamage->dwColdLen = nValue;
            break;
        case 5:
            pDamage->dwPoisLen = nValue;
            break;
        case 9:
            pDamage->dwStunLen = nValue;
            break;
        case 11:
            pDamage->dwBurnLen = nValue;
            break;
        case 12:
            pDamage->dwFrzLen = nValue;
            break;
        }
    }
}

static inline D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

inline D2MissilesTxt* GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static inline D2MissilesTxt* GetMissilesTxtRecordFromUnit(D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        return GetMissilesTxtRecord(pMissile->dwClassId);
    }
    return 0;
}

// 0x005A89A0
void __stdcall MISSMODE_FillDamageParams(D2UnitStrc* pMissile, D2UnitStrc* pTarget, D2DamageStrc* pDamage)
{
    memset(pDamage, 0x00, sizeof(*pDamage));

    pDamage->dwPhysDamage = MISSMODE_RollDamageValue(pMissile, STAT_MINDAMAGE, -1, STAT_MAXDAMAGE);
    pDamage->dwFireDamage = MISSMODE_RollDamageValue(pMissile, STAT_FIREMINDAM, STAT_PASSIVE_FIRE_MASTERY, STAT_FIREMAXDAM);
    pDamage->dwMagDamage = MISSMODE_RollDamageValue(pMissile, STAT_MAGICMINDAM, STAT_PASSIVE_MAG_MASTERY, STAT_MAGICMAXDAM);
    pDamage->dwLtngDamage = MISSMODE_RollDamageValue(pMissile, STAT_LIGHTMINDAM, STAT_PASSIVE_LTNG_MASTERY, STAT_LIGHTMAXDAM);
    pDamage->dwColdDamage = MISSMODE_RollDamageValue(pMissile, STAT_COLDMINDAM, STAT_PASSIVE_COLD_MASTERY, STAT_COLDMAXDAM);
    pDamage->dwColdLen = STATLIST_UnitGetStatValue(pMissile, STAT_COLDLENGTH, 0);
    pDamage->dwPoisDamage = MISSMODE_RollDamageValue(pMissile, STAT_POISONMINDAM, STAT_PASSIVE_POIS_MASTERY, STAT_POISONMAXDAM);
    pDamage->dwPoisLen = STATLIST_UnitGetStatValue(pMissile, STAT_POISONLENGTH, 0);

    const int nPoisonCount = STATLIST_UnitGetStatValue(pMissile, STAT_POISON_COUNT, 0);
    if (nPoisonCount > 1)
    {
        pDamage->dwPoisLen /= nPoisonCount;
    }

    pDamage->dwManaLeech = STATLIST_UnitGetStatValue(pMissile, STAT_MANADRAINMINDAM, 0);
    pDamage->dwLifeLeech = STATLIST_UnitGetStatValue(pMissile, STAT_LIFEDRAINMINDAM, 0);
    pDamage->dwStamLeech = STATLIST_UnitGetStatValue(pMissile, STAT_STAMDRAINMINDAM, 0);
    pDamage->dwBurnDamage = MISSMODE_RollDamageValue(pMissile, STAT_BURNINGMIN, STAT_PASSIVE_FIRE_MASTERY, STAT_BURNINGMAX);
    pDamage->dwBurnLen = STATLIST_UnitGetStatValue(pMissile, STAT_FIRELENGTH, 0);
    pDamage->dwStunLen = STATLIST_UnitGetStatValue(pMissile, STAT_STUNLENGTH, 0);

    if (pTarget)
    {
        int nDamagePercent = STATLIST_UnitGetStatValue(pMissile, STAT_DAMAGEPERCENT, 0);
        if (MONSTERS_IsDemon(pTarget))
        {
            nDamagePercent += STATLIST_UnitGetStatValue(pMissile, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
        }

        if (MONSTERS_IsUndead(pTarget))
        {
            nDamagePercent += STATLIST_UnitGetStatValue(pMissile, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
        }

        if (pTarget->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = GetMonStatsTxtRecord(pTarget->dwClassId);
            if (pMonStatsTxtRecord && pMonStatsTxtRecord->wMonType > 0)
            {
                const int nMonType = pMonStatsTxtRecord->wMonType;
                D2StatStrc statBuffer[128];
                const int nStats = STATLIST_CopyStats(pMissile, STAT_DAMAGE_VS_MONTYPE, statBuffer, 128);
                for (int i = 0; i < nStats; ++i)
                {
                    if (SUNITDMG_CheckMonType(statBuffer[i].nLayer, nMonType))
                    {
                        nDamagePercent += statBuffer[i].nValue;
                    }
                }
            }
        }

        if (nDamagePercent <= -90)
        {
            nDamagePercent = -90;
        }

        pDamage->dwPhysDamage += nDamagePercent * pDamage->dwPhysDamage / 100;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_ITEM_DEADLYSTRIKE, 0))
    {
        pDamage->dwPhysDamage *= 2;
        pDamage->wResultFlags |= DAMAGERESULTFLAG_CRITICALSTRIKE;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_SKILL_BYPASS_UNDEAD, 0))
    {
        pDamage->dwHitFlags |= DAMAGEHITFLAG_BYPASSUNDEAD;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_SKILL_BYPASS_DEMONS, 0))
    {
        pDamage->dwHitFlags |= DAMAGEHITFLAG_BYPASSDEMON;
    }

    if (STATLIST_UnitGetStatValue(pMissile, STAT_SKILL_BYPASS_BEASTS, 0))
    {
        pDamage->dwHitFlags |= DAMAGEHITFLAG_BYPASSBEASTS;
    }
}

// 0x005A8C70
int __fastcall MISSMODE_GetDamageValue(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (!pAttacker)
    {
        return 0;
    }

    switch (MISSILE_GetElemTypeFromMissileId(!pAttacker ? -1 : pAttacker->dwClassId))
    {
    case 0:
    {
        pDamage->dwPhysDamage = MISSMODE_RollDamageValue(pAttacker, STAT_MINDAMAGE, -1, STAT_MAXDAMAGE);

        if (pDefender)
        {
            int nDamagePercent = STATLIST_UnitGetStatValue(pAttacker, STAT_DAMAGEPERCENT, 0);
            if (MONSTERS_IsDemon(pDefender))
            {
                nDamagePercent += STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_DEMONDAMAGE_PERCENT, 0);
            }

            if (MONSTERS_IsUndead(pDefender))
            {
                nDamagePercent += STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_UNDEADDAMAGE_PERCENT, 0);
            }

            if (nDamagePercent <= -90)
            {
                nDamagePercent = -90;
            }

            int nPhysicalBase = pDamage->dwPhysDamage;
            nDamagePercent = nPhysicalBase * nDamagePercent / 100;
            nDamagePercent += nPhysicalBase;
            pDamage->dwPhysDamage = nDamagePercent;
        }

        if (STATLIST_UnitGetStatValue(pAttacker, STAT_ITEM_DEADLYSTRIKE, 0))
        {
            pDamage->dwPhysDamage *= 2;
            pDamage->wResultFlags |= DAMAGERESULTFLAG_CRITICALSTRIKE;
        }

        return pDamage->dwPhysDamage;
    }
    case 1:
    {
        pDamage->dwFireDamage = MISSMODE_RollDamageValue(pAttacker, STAT_FIREMINDAM, STAT_PASSIVE_FIRE_MASTERY, STAT_FIREMAXDAM);
        return pDamage->dwFireDamage;
    }
    case 2:
    {
        pDamage->dwLtngDamage = MISSMODE_RollDamageValue(pAttacker, STAT_LIGHTMINDAM, STAT_PASSIVE_LTNG_MASTERY, STAT_LIGHTMAXDAM);
        return pDamage->dwLtngDamage;
    }
    case 3:
    {
        pDamage->dwMagDamage = MISSMODE_RollDamageValue(pAttacker, STAT_MAGICMINDAM, STAT_PASSIVE_MAG_MASTERY, STAT_MAGICMAXDAM);
        return pDamage->dwMagDamage;
    }
    case 4:
    {
        pDamage->dwColdDamage = MISSMODE_RollDamageValue(pAttacker, STAT_COLDMINDAM, STAT_PASSIVE_COLD_MASTERY, STAT_COLDMAXDAM);
        pDamage->dwColdLen = STATLIST_UnitGetStatValue(pAttacker, STAT_COLDLENGTH, 0);
        return pDamage->dwColdDamage;
    }
    case 5:
    {
        pDamage->dwPoisDamage = MISSMODE_RollDamageValue(pAttacker, STAT_POISONMINDAM, STAT_PASSIVE_POIS_MASTERY, STAT_POISONMAXDAM);
        pDamage->dwPoisLen = STATLIST_UnitGetStatValue(pAttacker, STAT_POISONLENGTH, 0);

        const int nPoisonCount = STATLIST_UnitGetStatValue(pAttacker, STAT_POISON_COUNT, 0);
        if (nPoisonCount > 1)
        {
            pDamage->dwPoisLen /= nPoisonCount;
        }
        return 25 * pDamage->dwPoisDamage;
    }
    case 6:
    {
        pDamage->dwLifeLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_LIFEDRAINMINDAM, 0);
        return 0;
    }
    case 7:
    {
        pDamage->dwManaLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_MANADRAINMINDAM, 0);
        return 0;
    }
    case 8:
    {
        pDamage->dwStamLeech = STATLIST_UnitGetStatValue(pAttacker, STAT_STAMDRAINMINDAM, 0);
        return 0;
    }
    case 9:
    {
        pDamage->dwStunLen = STATLIST_UnitGetStatValue(pAttacker, STAT_STUNLENGTH, 0);
        return 0;
    }
    case 11:
    {
        pDamage->dwBurnDamage = MISSMODE_RollDamageValue(pAttacker, STAT_BURNINGMIN, STAT_PASSIVE_FIRE_MASTERY, STAT_BURNINGMAX);
        pDamage->dwBurnLen = STATLIST_UnitGetStatValue(pAttacker, STAT_FIRELENGTH, 0);
        return 25 * pDamage->dwBurnDamage;
    }
    case 12:
    {
        pDamage->dwColdDamage = MISSMODE_RollDamageValue(pAttacker, STAT_COLDMINDAM, STAT_PASSIVE_COLD_MASTERY, STAT_COLDMAXDAM);
        pDamage->dwFrzLen = STATLIST_UnitGetStatValue(pAttacker, STAT_COLDLENGTH, 0);
        return pDamage->dwColdDamage;
    }
    default:
        break;
    }

    return 0;
}

// 0x005A91C0
void __fastcall MISSMODE_ResetDamageParams(D2GameStrc* pGame, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pUnit)
    {
        return;
    }

    pDamage->dwHitFlags &= ~0x700;
    pDamage->dwPhysDamage = 0;
    pDamage->dwFireDamage = 0;
    pDamage->dwLtngDamage = 0;
    pDamage->dwMagDamage = 0;
    pDamage->dwColdDamage = 0;
    pDamage->dwPoisDamage = 0;
    pDamage->dwLifeLeech = 0;
    pDamage->dwManaLeech = 0;
    pDamage->dwStamLeech = 0;
    pDamage->dwStunLen = 0;
    pDamage->dwBurnDamage = 0;

    switch (MISSILE_GetElemTypeFromMissileId(pUnit->dwClassId))
    {
    case ELEMTYPE_POIS:
        pDamage->dwColdLen = 0;
        pDamage->dwFrzLen = 0;
        pDamage->dwBurnLen = 0;
        break;

    case ELEMTYPE_BURN:
        pDamage->dwColdLen = 0;
        pDamage->dwPoisLen = 0;
        pDamage->dwFrzLen = 0;
        break;

    default:
        pDamage->dwColdLen = 0;
        pDamage->dwFrzLen = 0;

    case ELEMTYPE_COLD:
        pDamage->dwPoisLen = 0;
        pDamage->dwBurnLen = 0;
        break;

    case ELEMTYPE_FREEZE:
        pDamage->dwPoisLen = 0;
        pDamage->dwBurnLen = 0;
        break;
    }
}

// 0x005A9270
void __fastcall MISSMODE_AddDamageValue(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nDamage)
{
    if (!pMissile)
    {
        return;
    }

    switch (MISSILE_GetElemTypeFromMissileId(pMissile->dwClassId))
    {
    case ELEMTYPE_NONE:
        pDamage->dwPhysDamage += nDamage;
        break;
    case ELEMTYPE_FIRE:
        pDamage->dwFireDamage += nDamage;
        break;
    case ELEMTYPE_LTNG:
        pDamage->dwLtngDamage += nDamage;
        break;
    case ELEMTYPE_MAGIC:
        pDamage->dwMagDamage += nDamage;
        break;
    case ELEMTYPE_COLD:
        pDamage->dwColdDamage += nDamage;
        break;
    case ELEMTYPE_POIS:
        pDamage->dwPoisDamage += nDamage;
        break;
    case ELEMTYPE_LIFE:
        pDamage->dwLifeLeech += nDamage;
        break;
    case ELEMTYPE_MANA:
        pDamage->dwManaLeech += nDamage;
        break;
    case ELEMTYPE_STAMINA:
        pDamage->dwStamLeech += nDamage;
        break;
    case ELEMTYPE_STUN:
        pDamage->dwStunLen += nDamage;
        break;
    case ELEMTYPE_BURN:
        pDamage->dwBurnDamage += nDamage;
        break;
    case ELEMTYPE_FREEZE:
        pDamage->dwColdDamage = nDamage;
        break;
    default:
        break;
    }
}

static inline int GetClassId(D2UnitStrc* unit) { return unit->dwClassId; }

// 0x005A8FB0
void __fastcall MISSMODE_SetDamageValue(Game* game,D2UnitStrc* missile,D2UnitStrc* owner,Damage* damage,int value)
{
    if (!missile) return;
    switch (MISSILE_GetElemTypeFromMissileId(GetClassId(missile))) {
    case 0: damage->physical=value; break;
    case 1: damage->fire=value; break;
    case 2: damage->lightning=value; break;
    case 3: damage->magic=value; break;
    case 4: damage->cold=value; if (value<=ZERO_DAMAGE) damage->coldLength=0; break;
    case 5: damage->poison=value; if (value<=ZERO_DAMAGE) damage->poisonLength=0; break;
    case 6: damage->lifeLeech=value; break;
    case 7: damage->manaLeech=value; break;
    case 8: damage->staminaLeech=value; break;
    case 9: damage->stunLength=value; break;
    case 11: damage->burn=value; if (value<=ZERO_DAMAGE) damage->burnLength=0; break;
    case 12: damage->cold=value; if (value<=ZERO_DAMAGE) damage->freezeLength=0; break;
    }
}

// 0x005A90E0
int __fastcall MISSMODE_GetStoredDamageValue(D2GameStrc* game, D2UnitStrc* missile, D2UnitStrc* unit, D2DamageStrc* damage, int unused)
{
 if (!missile) return 0;
 switch (MISSILE_GetElemTypeFromMissileId(!missile ? -1 : missile->dwClassId)) {
 case 0: return damage->dwPhysDamage;
 case 1: return damage->dwFireDamage;
 case 2: return damage->dwLtngDamage;
 case 3: return damage->dwMagDamage;
 case 4: return damage->dwColdDamage;
 case 5: return damage->dwPoisDamage;
 case 6: return damage->dwLifeLeech;
 case 7: return damage->dwManaLeech;
 case 8: return damage->dwStamLeech;
 case 9: return damage->dwStunLen;
 case 11: return damage->dwBurnDamage;
 case 12: return damage->dwColdDamage;
 default: return 0;
 }
}

// 0x005A9720
void __fastcall MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOrigin, int nMissileId, int nRange, int nLoops)
{
    if (!PATH_HasEnteredNewSubtile(pOrigin->pDynamicPath))
    {
        return;
    }

    D2MissileStrc missileParams = {};

    missileParams.dwFlags = 5;
    if (nRange > 0)
    {
        missileParams.nRange = nRange;
        missileParams.dwFlags = 0x8005;
    }

    if (nLoops > 0)
    {
        missileParams.nLoops = nLoops;
        missileParams.dwFlags |= 8;
    }

    missileParams.pOwner = SUNIT_GetOwner(pGame, pOrigin);
    if (!missileParams.pOwner)
    {
        return;
    }

    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = UNITS_GetXPositionInline(pOrigin);
    missileParams.nY = UNITS_GetYPositionInline(pOrigin);
    missileParams.nSkill = MISSILE_GetSkill(pOrigin);
    const int nLevel = MISSILE_GetLevel(pOrigin);
    missileParams.nLoops = 2 * (nLevel - 1);
    missileParams.nSkillLevel = nLevel;

    MISSILES_CreateMissileFromParams(pGame, &missileParams);
}

// 0x005A9930
void __fastcall MISSMODE_CreateCairnPortal(D2GameStrc* pGame, D2UnitStrc* pMissile, int nParam)
{
    MISSILE_SetTargetX(pMissile, 1);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    D2GAME_CreatePortalObject_6FD13DF0(pGame, pOwner, UNITS_GetRoom(pMissile), UNITS_GetXPositionInline(pMissile), UNITS_GetYPositionInline(pMissile), nParam, 0, 60, 1);
    DUNGEON_ToggleHasPortalFlag(UNITS_GetRoom(pMissile), 1);
}

// 0x005A99E0
static void MISSMODE_PlacePathAtOwner(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (pOwner && pPath)
    {
        sub_00650BE0_PlaceUnit(pPath, pMissile, UNITS_GetRoom(pOwner), UNITS_GetXPositionInline(pOwner), UNITS_GetYPositionInline(pOwner));
    }
}

// 0x005ABE50
int __fastcall MISSMODE_SrvHit32_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit && !MISSILE_GetTargetX(pMissile))
    {
        MISSMODE_CreateCairnPortal(pGame, pMissile, pMissilesTxtRecord->dwParam[3]);
    }

    return 0;
}

static inline int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
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

static inline int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
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

// 0x005A9530
void __fastcall MISSMODE_CreateImmolationArrowHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pMissile, int nRadius, int nMissileId, int nRange)
{
    if (!UNITS_GetRoom(pMissile))
    {
        return;
    }

    int x = 0;
    int y = 0;
    nRange = nRange < 0 ? 0 : nRange;

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 1;
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = nMissileId;
    if (nRange)
    {
        missileParams.dwFlags |= 0x8000;
    }

    const int nUnitX = UNITS_GetUnitXPosition(pMissile);
    const int nUnitY = UNITS_GetUnitYPosition(pMissile);
    const int nMaxDistanceSq = nRadius * nRadius;
    for (x = -nRadius; x <= nRadius; ++x)
    {
        for (y = -nRadius; y <= nRadius; ++y)
        {
            const int nY = nUnitY + y;
            if (MISSMODE_CheckDistanceAndLineOfSight(nMaxDistanceSq, nUnitX + x, nY, UNITS_GetRoom(pMissile), x, y))
            {
                D2ActiveRoomStrc* pTargetRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pMissile), nUnitX + x, nY);
                if (pTargetRoom && !DUNGEON_IsRoomInTown(pTargetRoom))
                {
                    if (nRange)
                    {
                        missileParams.nRange = nRange;
                    }
                    missileParams.nX = nUnitX + x;
                    missileParams.nY = nY;
                    MISSILES_CreateMissileFromParams(pGame, &missileParams);
                }
            }
        }
    }
}

// 0x005A9FB0
int __fastcall MISSMODE_SrvHit07_HolyBolt_FistOfTheHeavenBolt(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pMissilesTxtRecord->dwHitPar[0] && pOwner
        && (SUNIT_CanPetBeTargetedBySkill(pGame, pOwner, pUnit, nSkillId) || SUNIT_CanAllyBeTargetedBySkill(pGame, pOwner, pUnit, nSkillId)))
    {
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord)
        {
            const int nMin = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel) << 8;
            const int nMax = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel) << 8;
            int nRand = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin) + nMin;
            if (nRand <= 0)
            {
                nRand = MISSMODE_RollDamageValue(pMissile, STAT_MINDAMAGE, -1, STAT_MAXDAMAGE);
            }

            int nNewHp = nRand + STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
            const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (nNewHp >= nMaxHp)
            {
                nNewHp = nMaxHp;
            }
            STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nNewHp, 0);

            const short nOverlay = pMissilesTxtRecord->wProgOverlay;
            if (nOverlay > 0)
            {
                UNITS_SetOverlay(pUnit, nOverlay, 0);
            }
        }
        return 1;
    }

    switch (pUnit->dwUnitType)
    {
    case UNIT_MONSTER:
        switch (pMissilesTxtRecord->dwHitPar[1])
        {
        case 0:
            return 3;

        case 2:
            if (MONSTERS_IsDemon(pUnit))
            {
                return 3;
            }
            break;

        default:
            if (MONSTERS_IsUndead(pUnit))
            {
                return 3;
            }
            break;
        }
        break;

    case UNIT_PLAYER:
        if (!pMissilesTxtRecord->dwHitPar[1])
        {
            return 3;
        }
        break;
    }

    return 4;
}

static D2MissilesTxt* GetMissileRecord(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}

static D2SkillsTxt* GetSkillRecord(int nSkill)
{
    if (nSkill >= 0 && nSkill < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkill];
    return 0;
}

// 0x005A9820
static D2UnitStrc* __stdcall MISSMODE_CreateMissileWithCollisionCheck(
    D2GameStrc* pGame, int nRange, int nMissileId, unsigned short nMask, D2UnitStrc* pMissile, int nRate)
{
    D2MissileStrc params;
    if (!nRate)
        return 0;
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nRate)
        return 0;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return 0;
    if (!UNITS_GetRoom(pMissile))
        return 0;
    D2SeedStrc* pSeed = &pMissile->pSeed;
    int nSeed = CLIENTS_GetUnitX(pMissile);
    nSeed += sub_0064A3B0_GetElapsedFrames(pMissile);
    SEED_InitSeed(pSeed, nSeed);
    memset(&params, 0, sizeof(params));
    params.dwFlags = 3;
    params.pOwner = pOwner;
    params.nSkill = MISSILE_GetSkill(pMissile);
    params.nSkillLevel = MISSILE_GetLevel(pMissile);
    params.nMissile = nMissileId;
    --nRange;
    int nSpan = 2 * nRange;
    int nXOffset = ITEMS_RollLimitedRandomNumber(pSeed, nSpan) - nRange;
    int nYOffset = ITEMS_RollLimitedRandomNumber(pSeed, nSpan) - nRange;
    params.nX = CLIENTS_GetUnitX(pMissile) + nXOffset;
    params.nY = CLIENTS_GetUnitY(pMissile) + nYOffset;
    if (COLLISION_CheckMask(UNITS_GetRoom(pMissile), params.nX, params.nY, nMask))
        return 0;
    return MISSILES_CreateMissileFromParams(pGame, &params);
}

// 0x005AA730
int __fastcall MISSMODE_SrvHit12_ChainLightning_LightningStrike(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pPrevious;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 3;
    }

    if (!pUnit)
    {
        return 3;
    }

    const int nParam = MISSILE_GetTargetX(pMissile);
    if (nParam <= 1)
    {
        return 3;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 3;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    pPrevious = pUnit;
    pUnit = SKILLS_FindNextAuraTarget(pGame, pOwner, nX, nY, nRange, 0x88583, !pUnit ? -1 : pUnit->dwUnitId, 0);
    if (!pUnit)
    {
        return 3;
    }

    if (pUnit == pPrevious)
    {
        return 3;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pOwner;
    missileParams.pTarget = pUnit;
    missileParams.nMissile = pMissile->dwClassId;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nTargetX = CLIENTS_GetUnitX(pUnit);
    missileParams.nTargetY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    D2UnitStrc* pSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pSubMissile)
    {
        MISSILE_SetTargetX(pSubMissile, nParam - 1);
    }

    return 3;
}

// 0x005AAD40
int __fastcall MISSMODE_SrvHit15_SpiderGooLay(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pOwner;
    missileParams.nX = CLIENTS_GetUnitX(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    return 0;
}

// build: symbol ?xOffsets@?L@??MISSMODE_SrvHit05_CreateRadialSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2938
// build: symbol ?xOffsets@?O@??MISSMODE_SrvHit29_FrozenOrb@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2738
// build: symbol ?yOffsets@?L@??MISSMODE_SrvHit05_CreateRadialSubmissiles@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2838
// build: symbol ?yOffsets@?O@??MISSMODE_SrvHit29_FrozenOrb@@YIHPAUD2GameStrc@@PAUD2UnitStrc@@1@Z@4QBHB 0x006E2638
static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005A9A70
int __fastcall MISSMODE_SrvHit01_Fireball_ExplodingArrow_FreezingArrowExplosion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    SKILLS_ApplyAreaDamage(pGame, pOwner, nX, nY, nParam, &damage, 0);
    return 1;
}

// 0x005A9BF0
int __fastcall MISSMODE_SrvHit24_PantherPotOrange(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    SKILLS_ApplyAreaDamage(pGame, pOwner, nX, nY, nParam, &damage, 0);
    return 1;
}

// 0x005A9E10
int __fastcall MISSMODE_SrvHit44_ExplodingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (!nRange)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;

    if (SKILLS_ApplyAreaDamage(pGame, pOwner, nX, nY, nRange, &damage, 0))
    {
        return 1;
    }

    return 3;
}

static D2MonsterDataStrc* MONSTERUNIQUE_GetMonsterDataInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        return pUnit->pMonsterData;
    }

    return 0;
}

// 0x005AA8B0
int __fastcall MISSMODE_SrvHit13_GlacialSpike_HellMeteorDown(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nLength = pMissilesTxtRecord->dwHitPar[1];
    if (nLength <= 0)
    {
        nLength = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);

    if (nLength > 0)
    {
        sub_005A8F20_SetElementalLength(pGame, pMissile, pUnit, &damage, nLength);
    }

    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;

    if (SKILLS_ApplyAreaDamage(pGame, SUNIT_GetOwner(pGame, pMissile), nX, nY, nRange, &damage, 0))
    {
        return 1;
    }

    return 3;
}

// 0x005AAE10
int __fastcall MISSMODE_SrvHit16_SpiderGoo_VinesTrail_VinesWither(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nLength = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
    if (nLength < 5)
    {
        nLength = 5;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        const int nOwnerId = pOwner->dwUnitId;
        const int nOwnerType = pOwner->dwUnitType;
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nLength + pGame->dwGameFrame, nOwnerType, nOwnerId);
        if (!pNewStatList)
        {
            return 1;
        }

        STATLIST_SetState(pNewStatList, pSkillsTxtRecord->wAuraTargetState);
        STATLIST_SetStatRemoveCallback(pNewStatList, SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pNewStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    }

    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    D2COMMON_10476(pStatList, nLength + pGame->dwGameFrame);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nLength + pGame->dwGameFrame, 0, 0);
    return 0;
}

// 0x005AAFB0
int __fastcall MISSMODE_SrvHit17_Howl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pTarget)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxt = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pSkillsTxt = &sgptDataTables->pSkillsTxt[nSkillId];
    if (!pSkillsTxt)
        return 1;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return 1;
    if (pTarget && (!pTarget ? 6 : pTarget->dwUnitType) == 1)
    {
        const short nState = pSkillsTxt->wAuraTargetState;
        if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
            return 1;
        if (!STATES_CheckState(pTarget, nState))
        {
            const int nMaxLevel = STATLIST_UnitGetStatValue(pOwner, 12, 0) + nSkillLevel + SKILLDESC_GetSkillParamTwo(nSkillId);
            if (nMaxLevel > STATLIST_UnitGetStatValue(pTarget, 12, 0))
                AIUTIL_ApplyTerrorCurseState(pGame, pOwner, pTarget, nSkillId, MISSILE_GetSkillMissileRange(nSkillId, nSkillLevel), SKILLDESC_GetSummonLevel(nSkillId, nSkillLevel));
        }
    }
    return 0;
}

// 0x005AB110
int __fastcall MISSMODE_SrvHit19_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nLength = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    if (nLength < 5)
    {
        nLength = 5;
    }

    const int nTimeout = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->wAuraTargetState);
    if (!pStatList)
    {
        const int nOwnerId = pOwner->dwUnitId;
        const int nOwnerType = pOwner->dwUnitType;
        D2StatListStrc* pNewStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nTimeout, nOwnerType, nOwnerId);
        if (!pNewStatList)
        {
            return 1;
        }

        STATLIST_SetState(pNewStatList, pSkillsTxtRecord->wAuraTargetState);
        STATLIST_SetStatRemoveCallback(pNewStatList, SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pNewStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    }

    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->wAuraTargetState, 1);
    D2COMMON_10476(pStatList, nTimeout);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nTimeout, 0, 0);
    return 3;
}

// 0x005AB2A0
int __fastcall MISSMODE_LightningFury_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget)
{
    D2HitFunc22ParamStrc* pParams = (D2HitFunc22ParamStrc*)pAuraCallback->pArgs;
    if (pAuraCallback->nCounter >= pParams->nParam)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pParams->pOwner;
    missileParams.pOrigin = pParams->pOrigin;
    missileParams.nSkill = pParams->nSkillId;
    missileParams.nSkillLevel = pParams->nLevel;
    missileParams.nMissile = pParams->nHitSubMissile;
    missileParams.nTargetX = UNITS_GetXPositionInline(pTarget);
    missileParams.nTargetY = UNITS_GetYPositionInline(pTarget);
    MISSILES_CreateMissileFromParams(pAuraCallback->pGame, &missileParams);

    return 1;
}

static D2MissilesTxt* GetMissilesTxt(D2UnitStrc* pMissile)
{
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    return 0;
}

static D2SkillsTxt* SkillsRecordFor(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static int GetX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nXPos; }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int GetY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType) { case UNIT_OBJECT: case UNIT_ITEM: case UNIT_TILE: return pUnit->pStaticPath->nYPos; }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005AA250
int __fastcall MISSMODE_SrvHit09_ImmolationArrow(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxt(pMissile);
    if (!pMissilesTxtRecord) return 1;
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SkillsRecordFor(nSkillId);
    if (!pSkillsTxtRecord) return 1;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pMissilesTxtRecord->wHitSubMissile[0] >= 0)
    {
        STATLIST_SetUnitStat(pMissile, STAT_COLDLENGTH, 0, 0);
        STATLIST_SetUnitStat(pMissile, 0x86, 0, 0);
        int nCount = pMissilesTxtRecord->dwHitPar[0];
        if (nCount <= 0)
        {
            nCount = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
            if (nCount < 1) nCount = 1;
        }
        const int nValue = MISSILE_EvaluateMissileFormula(pMissile, pOwner, pMissilesTxtRecord->dwHitCalc, !pMissile ? -1 : pMissile->dwClassId, nLevel);
        MISSMODE_CreateImmolationArrowHitSubmissiles(pGame, pMissile, nCount, pMissilesTxtRecord->wHitSubMissile[0], nValue);
    }
    int nRange = pMissilesTxtRecord->dwHitPar[1];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[1], nSkillId, nLevel);
        if (nRange < 1) nRange = 1;
    }
    D2DamageStrc damage = {};
    MISSMODE_GetDamageValue(pGame, pMissile, pUnit, &damage);
    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    sub_0056BAD0_ApplyAreaDamage(pGame, SUNIT_GetOwner(pGame, pMissile), GetX(pMissile), GetY(pMissile), nRange, &damage, 0);
    return 3;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
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
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static inline D2MissilesTxt* MISSILE_GetMissilesTxtRecord_Inline(D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return 0;
    }

    const int nMissileId = pMissile->dwClassId;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

// 0x005AA460
static void __stdcall MISSMODE_SetGuidedMissileTarget(D2UnitStrc* pTarget, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    if (pTarget && SUNIT_IsDead(pTarget))
    {
        pTarget = 0;
    }

    const int nFrames = pMissilesTxtRecord->wRange + pMissilesTxtRecord->wLevRange * (MISSILE_GetLevel(pMissile) - 1);
    MISSILE_SetTotalFrames(pMissile, nFrames);
    MISSILE_SetCurrentFrame(pMissile, nFrames);

    int nDistance;
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
        MISSILE_SetTargetX(pMissile, 5);
        nDistance = DRLG_UnitEdgeDistance(pMissile, pTarget);
    }
    else
    {
        const unsigned int nParam = MISSILE_GetTargetY(pMissile);
        const unsigned int nParamHigh = nParam >> 16;
        const int nX = CLIENTS_GetUnitXInline(pMissile) + (short)nParam;
        const int nY = CLIENTS_GetUnitYInline(pMissile) + (short)nParamHigh;
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        MISSILE_SetTargetX(pMissile, 6);
        nDistance = DRLG_GetDistanceToXY(pMissile, nX, nY);
    }

    if (nDistance < 25)
    {
        D2Common_10142(pPath, pMissile, 0);
    }
}

// 0x005AA5B0
static int __stdcall MISSMODE_FindGuidedMissileTarget(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nParam = pMissilesTxtRecord->dwParam[1];
    if (MISSILE_GetTargetX(pMissile) & 4)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    MISSMODE_SetGuidedMissileTarget(SKILLS_FindNextAuraTarget(pGame, pOwner, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), nParam, 3, -1, 0), pMissile);
    return 0;
}

// 0x005AAA90
static void __stdcall MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(D2GameStrc* pGame, int nMissileId, int nRange, int nStep, D2UnitStrc* pMissile)
{
    if (nMissileId < 0)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitXInline(pMissile);
    const int nY = CLIENTS_GetUnitYInline(pMissile);

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    const int nSkill = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    if (nRange > 0)
    {
        missileParams.dwFlags = 0x8001;
        missileParams.nRange = nRange;
    }

    missileParams.nSkill = nSkill;
    missileParams.pOwner = pOwner;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;

    if (nStep < 1)
    {
        nStep = 1;
    }

    for (int i = 0; i < 18; i += nStep)
    {
// build: symbol ?gnMeteorSubmissileOffsetsX@* 0x006E2550
        missileParams.nX = nX + gnMeteorSubmissileOffsetsX[i];
// build: symbol ?gnMeteorSubmissileOffsetsY@* 0x006E2598
        missileParams.nY = nY + gnMeteorSubmissileOffsetsY[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
}

// 0x005AB370
int __fastcall MISSMODE_SrvHit20_LightningFury(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwHitPar[0];
    if (nAuraRange <= 0)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nAuraRange < 1)
        {
            nAuraRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    int nAuraFilter = pSkillsTxtRecord->dwAuraFilter;
    if (!nAuraFilter)
    {
        nAuraFilter = 0xA783;
    }

    D2HitFunc22ParamStrc params;
    params.pOwner = pOwner;
    params.pOrigin = pMissile;
    params.nSkillId = nSkillId;
    params.nLevel = nLevel;
    params.nParam = nParam;
    params.nHitSubMissile = pMissilesTxtRecord->wHitSubMissile[0];

    SKILLS_IterateAuraTargets(pGame, pOwner, nX, nY, nAuraRange, nAuraFilter, MISSMODE_LightningFury_AuraCallback, &params, 1, ".\\MISSILES\\MissMode.cpp", 3779);
    return 3;
}

// 0x005AB500
int __fastcall MISSMODE_SrvHit21_BattleCry(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState > sgptDataTables->nStatesTxtRecordCount)
    {
        return 1;
    }

    int nAuraFilter = pSkillsTxtRecord->dwAuraFilter;
    if (nAuraFilter)
    {
        nAuraFilter = 0xA783;
    }

    if (!sub_6FD0FA00(pOwner, pUnit, nAuraFilter))
    {
        return 1;
    }

    D2CurseStrc curse = {};
    curse.pUnit = pOwner;
    curse.pTarget = pUnit;
    curse.nSkill = nSkillId;
    curse.nSkillLevel = nLevel;
    curse.nDuration = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    curse.nState = pSkillsTxtRecord->wAuraTargetState;
    curse.pStateRemoveCallback = 0;

    D2StatListStrc* pStatList = SKILLS_ApplyStateEffect(&curse);
    if (pStatList)
    {
        SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nLevel);
    }

    return 0;
}

// 0x005AB630
int __fastcall MISSMODE_FistOfTheHeavensDelay_AuraCallback(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pTarget)
{
    D2HitFunc22ParamStrc* pParams = (D2HitFunc22ParamStrc*)pAuraCallback->pArgs;
    if (pParams->nParam > 0 && pAuraCallback->nCounter >= pParams->nParam)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pParams->pOwner;
    missileParams.pOrigin = pParams->pOrigin;
    missileParams.nSkill = pParams->nSkillId;
    missileParams.nSkillLevel = pParams->nLevel;
    missileParams.nMissile = pParams->nHitSubMissile;
    missileParams.nTargetX = UNITS_GetXPositionInline(pTarget);
    missileParams.nTargetY = UNITS_GetYPositionInline(pTarget);
    MISSILES_CreateMissileFromParams(pAuraCallback->pGame, &missileParams);

    return 1;
}

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005AABB0
int __fastcall MISSMODE_SrvHit14_MeteorCenter_CatapultMeteor_RoyalStrikeMeteor(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    D2DamageStrc damage = {};
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);

    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;

    int nResult = 1;
    if (!SKILLS_ApplyAreaDamage(pGame, pOwner, nX, nY, nRange, &damage, 0))
    {
        nResult = 3;
    }

    const short nHitSubMissile = pMissilesTxtRecord->wHitSubMissile[0];
    if (nHitSubMissile >= 0)
    {
        const int nMissileRange = MISSILE_GetSkillMissileRange(nSkillId, nLevel);
        int nParam = pMissilesTxtRecord->dwHitPar[1];
        if (nParam < 1)
        {
            nParam = 1;
        }

        MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(pGame, nHitSubMissile, nMissileRange, nParam, pMissile);
    }

    return nResult;
}

// 0x005AB700
int __fastcall MISSMODE_CreatePantherPotGreenSubmissiles(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nStep)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    }

    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x1F;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pOrigin;
    missileParams.nMissile = nMissileId;
    missileParams.nX = UNITS_GetXPositionInline(pOrigin);
    missileParams.nY = UNITS_GetYPositionInline(pOrigin);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = nSkillLevel - 1;
    missileParams.nVelocity = pMissilesTxtRecord->dwParam[0] << 7;

    static const int xOffsets[8] = { 0, 2, 2, 2, 0, -2, -2, -2 };
    static const int yOffsets[8] = { 2, 2, 0, -2, -2, -2, 0, 2 };

    for (int i = 0; i < 8; i += nStep)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005AB8D0
int __fastcall MISSMODE_SrvHit26_GrimWardStart(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = sub_0064A280(pMissile);
    const int nSkillLevel = sub_0064A210(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        if (nRange < 5)
        {
            nRange = 5;
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x8001;
    missileParams.pOwner = pOwner;
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nRange = nRange;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nX = CLIENTS_GetUnitX(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005ABA10
int __fastcall MISSMODE_SrvHit28_GrimWardScare(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    if (!SUNIT_GetOwner(pGame, pMissile))
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    if (pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 1;
    }

    D2UnitStrc* pSubMissile = SUNIT_GetServerUnit(pGame, UNIT_MISSILE, MISSILE_GetTargetX(pMissile));
    if (!pSubMissile)
    {
        return 1;
    }

    const int nDistance = SKILLDESC_GetSkillParamByLevel(nSkillId, nLevel);
    if (PATH_ComputeSquaredDistance(CLIENTS_GetUnitX(pSubMissile), CLIENTS_GetUnitY(pSubMissile), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)) < nDistance * nDistance)
    {
        AIUTIL_ApplyTerrorCurseState(pGame, pSubMissile, pUnit, nSkillId, SKILLDESC_GetSkillParamFive(nSkillId), SKILLDESC_GetSkillParamSix(nSkillId));
    }

    return 1;
}

// 0x005ABB00
int __fastcall MISSMODE_SrvHit29_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (sub_0064A380_GetRemainingFrames(pMissile))
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    static const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nParam)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, xOffsets[i]);
            MISSILE_SetTargetY(pHitSubMissile, yOffsets[i]);
        }
    }

    return 3;
}

// 0x005ABC40
int __fastcall MISSMODE_SrvHit05_CreateRadialSubmissiles(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    static const int xOffsets[64] =
    {
        30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2, 0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29,
        -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2, 0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29
    };

    static const int yOffsets[64] =
    {
        0, 2, 5, 8, 11, 14, 16, 19, 21, 23, 24, 26, 27, 28, 29, 29, 30, 29, 29, 28, 27, 26, 24, 23, 21, 19, 16, 14, 11, 8, 5, 2,
        0, -2, -5, -8, -11, -14, -16, -19, -21, -23, -24, -26, -27, -28, -29, -29, -30, -29, -29, -28, -27, -26, -24, -23, -21, -19, -16, -14, -11, -8, -5, -2
    };

    for (int i = 0; i < 64; i += nParam)
    {
        missileParams.nTargetX = xOffsets[i];
        missileParams.nTargetY = yOffsets[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, xOffsets[i]);
            MISSILE_SetTargetY(pHitSubMissile, yOffsets[i]);
        }
    }

    return 3;
}

// 0x005ABEB0
int __fastcall MISSMODE_SrvHit33_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (pRoom)
        {
            DUNGEON_ToggleHasPortalFlag(pRoom, 1);
        }
    }

    return 0;
}

// 0x005ABEE0
int __fastcall MISSMODE_SrvHit35_OrbMist(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 0;
    }

    D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, MISSILE_GetTargetX(pMissile));
    if (!pObject)
    {
        return 0;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pObject);
    if (pRoom)
    {
        DUNGEON_ToggleHasPortalFlag(pRoom, 1);
    }

    if (pObject->dwAnimMode == OBJMODE_NEUTRAL)
    {
        UNITS_ChangeAnimMode(pObject, 1);
        const int nClassId = pObject->dwClassId;
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        if (pObjectsTxtRecord)
        {
            EVENT_SetEvent(pGame, pObject, EVENTTYPE_ENDANIM, pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
        }
    }

    return 1;
}

// 0x005ABF70
int __fastcall MISSMODE_SrvHit36_MissileInAir(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    if (pUnit)
    {
        return 0;
    }

    D2UnitStrc* pHitSubMissile = D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->wHitSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    if (pHitSubMissile)
    {
        MISSILE_SetTargetX(pHitSubMissile, MISSILE_GetTargetX(pMissile));
    }

    return 1;
}

// 0x005AC020
int __fastcall MISSMODE_SrvHit37_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 2;
    }

    return 0;
}

// 0x005AC040
void __fastcall MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc(D2UnitStrc* pMissile, int nUnused)
{
    if (!pMissile)
        return;

    const int nRange = MISSILE_GetTotalFrames(pMissile) > 255 ? 255 : MISSILE_GetTotalFrames(pMissile);
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    SEED_InitLowSeed(&pMissile->pSeed, D2COMMON_10175_PathGetFirstPointX(pPath));
    PATH_SetType(pPath, PATHTYPE_CHARGEDBOLT);
    PATH_SetNewDistance(pPath, nRange);
    D2Common_10142(pPath, pMissile, 0);
}

// 0x005AC0A0
int __fastcall MISSMODE_SrvHit38_CatapultChargedBall(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = CLIENTS_GetUnitX(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.pOwner = pOwner;
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.pInitFunc = MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc;

    int nCalc = pMissilesTxtRecord->dwHitPar[0] + pMissilesTxtRecord->dwHitPar[1] * (MISSILE_GetLevel(pMissile) - 1);
    if (nCalc <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        const int nLevel = MISSILE_GetLevel(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nCalc < 1)
        {
            nCalc = 1;
        }
    }

    sub_6FD14260(pGame, nCalc, &missileParams);
    return 1;
}

// 0x005AC1D0
int __fastcall MISSMODE_SrvHit39_ImpSpawnMonsters(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    MONSTERSPAWN_SpawnRandomMonsterForLevel(pGame, UNITS_GetRoom(pMissile), UNITS_GetXPositionInline(pMissile), UNITS_GetYPositionInline(pMissile));
    return 1;
}

// 0x005AC350
int __fastcall MISSMODE_SrvHit43_HealingVortex(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (!pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nSkillLevel = MISSILE_GetLevel(pMissile);
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 1;
    }

    const int nMin = SKILLS_GetMinPhysDamage(SUNIT_GetOwner(pGame, pMissile), nSkillId, nSkillLevel, 1);
    const int nMax = SKILLS_GetMaxPhysDamage(SUNIT_GetOwner(pGame, pMissile), nSkillId, nSkillLevel, 1);
    const int nHeal = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, nMax - nMin) + nMin;

    int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
    const int nMaxHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nHitpoints != nMaxHitpoints && (short)pMissilesTxtRecord->wProgOverlay > 0)
    {
        UNITS_SetOverlay(pUnit, (short)pMissilesTxtRecord->wProgOverlay, 0);
    }

    nHitpoints += nHeal;
    if (nHitpoints >= nMaxHitpoints)
    {
        nHitpoints = nMaxHitpoints;
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    return pMissilesTxtRecord->nCollideKill != 0;
}

// 0x005AC480
int __fastcall MISSMODE_SrvHit45_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0 || pMissilesTxtRecord->dwHitPar[0] <= 0)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.nX = CLIENTS_GetUnitX(pMissile);
    missileParams.nY = CLIENTS_GetUnitY(pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    if (pMissilesTxtRecord->dwHitPar[1])
    {
        missileParams.pInitFunc = MISSMODE_CatapultChargedBall_LightningTrailingJavelin_SubmissileInitFunc;
    }

    sub_6FD14260(pGame, pMissilesTxtRecord->dwHitPar[0], &missileParams);
    return 1;
}

// 0x005ACA50
int __fastcall MISSMODE_SrvHit53_RabiesContagion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nFrame = MISSILE_GetTargetX(pMissile) - pGame->dwGameFrame;
    if (nFrame < 10 || nFrame > SKILLS_GetElementalLength(pOwner, nSkillId, nLevel, 1))
    {
        return 1;
    }

    SKILLS_ApplyTargetAuraAndMissile(pGame, pOwner, pUnit, nFrame, nSkillId, nLevel);
    return 2;
}

// 0x005ACAF0
int __fastcall MISSMODE_SrvHit54_BaalSpawnMonsters(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pOwner)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pOwner, MISSILE_GetSkill(pMissile));
        if (pSkill)
        {
            const int nMonsterId = SKILLS_GetParam1(pSkill);
            D2GAME_SpawnPresetMonster_6FC66560(pGame, UNITS_GetRoom(pMissile), nMonsterId, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), MONMODE_NEUTRAL);
        }
    }

    return 1;
}

// 0x005AD3E0
void __fastcall MISSMODE_SrvDmg07_Warcry_ShockWave(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    int nStunLength = pMissilesTxtRecord->dwDmgParam[0];
    if (nStunLength <= 0)
    {
        nStunLength = SKILLDESC_GetSkillParamByLevel(nSkillId, nLevel);
    }

    pDamage->dwStunLen = nStunLength;
    pDamage->dwHitClass = 0x60;
}

// 0x005AD450
void __fastcall MISSMODE_SrvDmg08_EruptionCrack(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord && pUnit && pMissilesTxtRecord->wProgOverlay > 0)
    {
        UNITS_SetOverlay(pUnit, pMissilesTxtRecord->wProgOverlay, 0);
    }
}

// 0x005AD4A0
void __fastcall MISSMODE_SrvDmg09_Twister(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    int nStunLength = pMissilesTxtRecord->dwDmgParam[0];
    if (nStunLength <= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        nStunLength = !pSkillsTxtRecord ? 0 : pSkillsTxtRecord->dwParam[1];
    }

    pDamage->dwStunLen = nStunLength;
    pDamage->dwHitClass = 0x60;
}

// 0x005AD530
void __fastcall MISSMODE_SrvDmg11_RabiesContagion(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pUnit)
    {
        pDamage->dwPoisDamage = 0;
        pDamage->dwPoisLen = 0;
        return;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nPoisonLength = MISSILE_GetTargetX(pMissile) - pGame->dwGameFrame;
    if (nPoisonLength < 10 || nPoisonLength > SKILLS_GetElementalLength(pOwner, nSkillId, nLevel, 1))
    {
        pDamage->dwPoisDamage = 0;
        pDamage->dwPoisLen = 0;
        return;
    }

    pDamage->dwPoisLen = nPoisonLength;
}

// 0x005AD5C0
void __fastcall MISSMODE_SrvDmg13_BlessedHammerEx(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
        if (pOwner)
        {
            pDamage->dwPhysDamage += pDamage->dwPhysDamage * STATLIST_UnitGetStatValue(pOwner, STAT_DAMAGEPERCENT, 0) / 100;
        }

        MISSMODE_SrvDmg05_BlessedHammer(pGame, pMissile, pUnit, pDamage);
    }
}

// 0x005AD8F0
int __fastcall MISSMODE_RadamentDeathAreaEffectCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused)
{
    return SKILLS_ApplyRedemptionEffect(pGame, pUnit, pCorpse, 124, nSkillLevel, 0);
}

static inline D2MissilesTxt* CLTMISS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// build: symbol ?MISSILE_InitFromOwner@* 0x004CC870
void __fastcall MISSILE_InitFromOwner(D2UnitStrc* pMissile, int nInitArg)
{
    D2UnitStrc* pOwner = (D2UnitStrc*)nInitArg;
    if (!pMissile)
        return;

    D2MissilesTxt* pMissilesTxtRecord = CLTMISS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pOwner)
        return;

    int nOffset = 0;
    if (pMissilesTxtRecord->dwCltParam[1] > 0)
        nOffset = SEED_RollLimitedRandomNumber(&pOwner->pSeed, pMissilesTxtRecord->dwCltParam[1]) - pMissilesTxtRecord->dwCltParam[1] / 2;

    GFXUTIL_SetMotionVectorA(pMissile, 0, 0, nOffset);
    PATH_SetDirection(pMissile->pDynamicPath, PATH_GetDirection(pOwner->pDynamicPath));
    D2COMMON_10203_PATH_SetRotateFlag(pMissile->pDynamicPath, 0);
    pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissilesTxtRecord->nAnimLen) << 8;
}

// build: symbol ?MISSILE_CltHitFlagOwner@* 0x004CCCA0
int __fastcall MISSILE_CltHitFlagOwner(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pMissile);
    if (pOwner)
        pOwner->dwFlagEx |= UNITFLAGEX_0x40000;
    return 1;
}

// 0x005AD910
int __fastcall MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pCorpse, int nSkillLevel, int nUnused)
{
    return SKILLS_ApplyRedemptionEffect(pGame, pUnit, pCorpse, 124, nSkillLevel, 1);
}

// 0x005AD930
static inline void MISSMODE_BaalFxOpenPortal(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    MISSILE_SetTargetX(pMissile, 1);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (QUESTS_CheckNotIntroQuest(pGame, QUEST_A5Q6_BAAL))
    {
        ACT5Q6_SpawnTyrael(pGame, pRoom, pMissile);
    }

    DUNGEON_ToggleHasPortalFlag(pRoom, 1);
}

// build: symbol ?MISSILE_CltHitClearGlobals@* 0x004CCF00
int __fastcall MISSILE_CltHitClearGlobals(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        VIEW_ClearGlobals();
        return 1;
    }
    return 0;
}

// 0x005AD970
int __fastcall MISSMODE_SrvHit57_BaalFxControl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit && !MISSILE_GetTargetX(pMissile))
    {
        MISSILE_SetTargetX(pMissile, 1);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (QUESTS_CheckNotIntroQuest(pGame, QUEST_A5Q6_BAAL))
        {
            ACT5Q6_SpawnTyrael(pGame, pRoom, pMissile);
        }

        DUNGEON_ToggleHasPortalFlag(pRoom, 1);
    }

    return 0;
}

static D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

static inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord_005B01F0(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AC250
int __fastcall MISSMODE_SrvHit40_CatapultSpikeBall(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pMissile)
    {
        return 1;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    int nCalc = pMissilesTxtRecord->dwHitPar[0] + (nLevel - 1) * pMissilesTxtRecord->dwHitPar[1];
    if (nCalc <= 0)
    {
        const int nSkillId = MISSILE_GetSkill(pMissile);
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nCalc = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nCalc < 1)
        {
            nCalc = 1;
        }
    }

    SKILLS_CreateMissilesAroundTarget(pGame, pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->wHitSubMissile[0], nCalc, nCalc / 4, MISSILE_GetSkill(pMissile), nLevel);
    return 1;
}

struct D2GameStrc;

struct D2UnitStrc;

// 0x005AD2F0
void __fastcall MISSMODE_SrvDmg05_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    const int nBaseDamage = MISSMODE_GetDamageValue(pGame, pMissile, pUnit, pDamage);
    if (pMissilesTxtRecord->dwDmgParam[0] > 0 && MONSTERS_IsUndead(pUnit))
    {
        MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, DATATBLS_ApplyRatio(nBaseDamage, pMissilesTxtRecord->dwDmgParam[0], 100));
    }

    if (pMissilesTxtRecord->dwDmgParam[1] > 0 && MONSTERS_IsDemon(pUnit))
    {
        MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, DATATBLS_ApplyRatio(nBaseDamage, pMissilesTxtRecord->dwDmgParam[1], 100));
    }
}

// 0x005AA180
int __fastcall MISSMODE_SrvHit08_Blaze(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pExpectedOwner)
{
    int nResult = 2;
    if (!pExpectedOwner)
        return nResult;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    if (pOwner && pExpectedOwner == pOwner)
    {
        if (STATES_CheckState(pOwner, STATE_BLAZE))
            nResult = 0;
    }
    return nResult;
}

// 0x005AC550
int __fastcall MISSMODE_SrvHit47_MoltenBoulder(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = MISSILE_GetMissilesTxtRecord_Inline(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int bValidTarget = 1;
// build: symbol ?MONSTERREGION_CheckMonStats2Flag@* 0x004638A0
    if (pUnit && (pUnit->dwUnitType != UNIT_MONSTER || !MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, MONSTATS2FLAGINDEX_LARGE)))
    {
        bValidTarget = 0;
    }

    if (bValidTarget)
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);

        int nResult = 1;

        D2DamageStrc damage = {};
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &damage);

        int nRange = pMissilesTxtRecord->dwHitPar[0];
        if (nRange <= 0)
        {
            const int nSkillId = sub_0064A280(pMissile);
            const int nLevel = sub_0064A210(pMissile);
            D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
            if (!pSkillsTxtRecord)
            {
                return 1;
            }

            nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
            if (nRange < 1)
            {
                nRange = 1;
            }
        }

        damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
        damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;

        if (!SKILLS_ApplyAreaDamage(pGame, pOwner, nX, nY, nRange, &damage, 0))
        {
            nResult = 3;
        }

        int nParam = pMissilesTxtRecord->dwHitPar[1];
        if (nParam < 1)
        {
            nParam = 1;
        }

        MISSMODE_CreateMeteor_MoltenBoulderSubmissiles(pGame, pMissilesTxtRecord->wHitSubMissile[0], nRange, nParam, pMissile);
        return nResult;
    }

    return 2;
}

// 0x005AC6D0
int __fastcall MISSMODE_SrvHit48_MoltenBoulderEmerge(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    const int nX = UNITS_GetXPositionInline(pMissile);
    const int nY = UNITS_GetYPositionInline(pMissile);

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath);
    missileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath);
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005AC800
int __fastcall MISSMODE_SrvHit50_PlagueVinesTrail(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pUnit)
    {
        const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
        if (nFrames < MISSILE_GetTotalFrames(pMissile) - pMissilesTxtRecord->dwHitPar[0])
        {
            return 2;
        }
    }

    return 0;
}

// 0x005AC870
int __fastcall MISSMODE_SrvHit51_VolcanoDebris(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    if (pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    MISSILES_CreateMissileFromParams(pGame, &missileParams);

    if (pMissilesTxtRecord->wHitSubMissile[1] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[1];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    if (pMissilesTxtRecord->wHitSubMissile[2] >= 0)
    {
        missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[2];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005AC940
int __fastcall MISSMODE_SrvHit52_BladeFury(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    int nParam = pMissilesTxtRecord->dwHitPar[0];
    if (nParam < 1)
    {
        nParam = 1;
    }

    for (int i = 0; i < 8; i += nParam)
    {
        missileParams.nTargetX = gnSrvHit52_XOffsets[i];
        missileParams.nTargetY = gnSrvHit52_YOffsets[i];

        D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pHitSubMissile)
        {
            MISSILE_SetTargetX(pHitSubMissile, gnSrvHit52_XOffsets[i]);
            MISSILE_SetTargetY(pHitSubMissile, gnSrvHit52_YOffsets[i]);
        }
    }

    return 1;
}

// 0x005ACB60
int __fastcall MISSMODE_SrvHit55_Baalnferno(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        return 2;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->dwHitPar[0] <= 0)
    {
        return 1;
    }

    const int nCurrentMana = STATLIST_UnitGetStatValue(pUnit, STAT_MANA, 0);
    if (nCurrentMana <= 0)
    {
        return 1;
    }

    const int nPercentage = D2_MIN(D2_MAX(pMissilesTxtRecord->dwHitPar[0], 1), 100);
    int nLostMana = DATATBLS_ApplyRatio(nCurrentMana, nPercentage, 100);
    nLostMana = D2_MIN(D2_MAX(nLostMana, 1), nCurrentMana);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nCurrentMana - nLostMana, 0);
    return 2;
}

// 0x005AD630
void __fastcall MISSMODE_SrvDmg14_MoltenBoulder(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (!pMissile || pMissile->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || !pUnit)
    {
        return;
    }

    int nChance = 0;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        if (pMissilesTxtRecord->dwDmgParam[0] < 1)
        {
            return;
        }
        nChance = pMissilesTxtRecord->dwDmgParam[1];
    }
    else if (pUnit->dwUnitType == UNIT_MONSTER)
    {
        const int nParam = pMissilesTxtRecord->dwDmgParam[0];
        if (nParam < 1)
        {
            if (!MONSTERREGION_CheckMonStats2Flag(pUnit->dwClassId, 10))
            {
                return;
            }
            nChance = pMissilesTxtRecord->dwDmgParam[1];
        }
        else if (nParam == 1)
        {
            const int nClassId = pUnit->dwClassId;
            if (MONSTERREGION_CheckMonStats2Flag(nClassId, 10))
            {
                nChance = 2 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else if (!MONSTERREGION_CheckMonStats2Flag(nClassId, 11))
            {
                nChance = pMissilesTxtRecord->dwDmgParam[1];
            }
            else
            {
                return;
            }
        }
        else if (nParam > 1)
        {
            const int nClassId = pUnit->dwClassId;
            if (MONSTERREGION_CheckMonStats2Flag(nClassId, 10))
            {
                nChance = 3 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else if (!MONSTERREGION_CheckMonStats2Flag(nClassId, 11))
            {
                nChance = 2 * pMissilesTxtRecord->dwDmgParam[1];
            }
            else
            {
                nChance = pMissilesTxtRecord->dwDmgParam[1];
            }
        }
        else
        {
            return;
        }
    }
    else
    {
        return;
    }

    if (nChance > 0 && (int)SEED_RollLimitedRandomNumber(&pMissile->pSeed, 100) < nChance)
    {
        pDamage->wResultFlags |= 8;
    }
}

// 0x005ACFC0
int __fastcall MISSMODE_SrvHit23_ExecuteSkillDo(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    if (nSkillId > 0 && nLevel > 0 && SUNIT_GetOwner(pGame, pMissile))
    {
        if (pUnit)
        {
            UNITS_SetTargetUnitForDynamicUnit(pMissile, pUnit);
        }

        SKILLS_ExecuteServerDoFunction(pGame, pMissile, pMissilesTxtRecord->dwHitPar[0], nSkillId, nLevel);
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

// 0x005ACC50
int __fastcall MISSMODE_SrvHit56_ArmageddonControl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nX = CLIENTS_GetUnitX_Local(pMissile);
    const int nY = CLIENTS_GetUnitY_Local(pMissile);

    D2DamageStrc damage;
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, 0, &damage);

    int nRange = pMissilesTxtRecord->dwHitPar[0];
    if (nRange <= 0)
    {
        D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
        if (!pSkillsTxtRecord)
        {
            return 1;
        }

        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
    damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
    SKILLS_ApplyAreaDamage(pGame, pOwner, nX, nY, nRange, &damage, 0);

    if (pMissilesTxtRecord->wHitSubMissile[0] >= 0)
    {
        D2GAME_CreateMissile_6FD115E0(pGame, pOwner, nSkillId, nLevel, pMissilesTxtRecord->wHitSubMissile[0], nX, nY);
    }

    return 1;
}

// 0x005ACDF0
int __fastcall MISSMODE_SrvHit58_BaalTauntLightningControl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSeedX = CLIENTS_GetUnitX(pMissile);
    SEED_InitLowSeed(&pMissile->pSeed, nSeedX);
    const int nParam = D2_MAX(1, pMissilesTxtRecord->dwHitPar[0]);

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);
    const int nTargetX = nX + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nParam + 1) - nParam;
    const int nTargetY = nY + SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nParam + 1) - nParam;

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 32;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = sub_0064A280(pMissile);
    missileParams.nSkillLevel = sub_0064A210(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[0];
    missileParams.nTargetX = nTargetX;
    missileParams.nTargetY = nTargetY;

    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005ACF20
int __fastcall MISSMODE_SrvHit59_BaalTauntPoisonControl(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    int nHitPar = pMissilesTxtRecord->dwHitPar[0];
    if (nHitPar < 1)
    {
        nHitPar = 1;
    }

    MISSMODE_CreatePoisonCloudHitSubmissiles(pGame, pOwner, pMissile, pMissilesTxtRecord->wHitSubMissile[0], MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), nHitPar, 2, 0);
    return 1;
}

// 0x005AD050
void __fastcall MISSMODE_SrvDmg01_FireArrow_MagicArrow_ColdArrow(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->dwDmgCalc, -1, -1);
    if (nPercentage <= 0)
    {
        return;
    }

    nPercentage = D2_MIN(nPercentage, 100);

    const int nPhysDamage = pDamage->dwPhysDamage;
    int nDamageReduction = DATATBLS_ApplyRatio(nPhysDamage, nPercentage, 100);
    nDamageReduction = D2_MIN(nDamageReduction, nPhysDamage);
    pDamage->dwPhysDamage = nPhysDamage - nDamageReduction;
    MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, nDamageReduction);
}

// 0x005AD0F0
void __fastcall MISSMODE_SrvDmg12_LightningJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return;
    }
    int nPercentage = MISSILE_EvaluateMissileFormula(pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->dwDmgCalc, -1, -1);
    if (nPercentage <= 0)
    {
        return;
    }
    nPercentage = D2_MIN(nPercentage, 100);
    int nDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercentage, 100);
    nDamage = D2_MIN(nDamage, pDamage->dwPhysDamage);
    nDamage += MISSMODE_GetDamageValue(pGame, pMissile, pUnit, pDamage);
    MISSMODE_ResetDamageParams(pGame, pMissile, pDamage);
    MISSMODE_AddDamageValue(pGame, pMissile, pUnit, pDamage, nDamage);
}

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

// 0x005AD1B0
void __fastcall MISSMODE_SrvDmg02_IceArrow_RoyalStrikeChaos(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const int nColdLength = STATLIST_UnitGetStatValue(pMissile, STAT_COLDLENGTH, 0);
        pDamage->dwFrzLen = DATATBLS_ApplyRatio(nColdLength, pMissilesTxtRecord->dwDmgParam[0] < 0 ? 0 : pMissilesTxtRecord->dwDmgParam[0], 100);
        pDamage->dwColdLen = 0;
    }
}

// 0x005AD290
void __fastcall MISSMODE_SrvDmg04_IceBlast(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    pDamage->dwFrzLen = pDamage->dwColdLen;
    pDamage->dwColdLen = 0;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nLowSeed = (unsigned int)lSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollRandomNumber_005B01F0(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

// 0x005AD220
void __fastcall MISSMODE_SrvDmg03_Blaze_FireWall_ImmolationFire_MeteorFire(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (pMissilesTxtRecord)
    {
        const int nRand = SEED_RollRandomNumber(&pMissile->pSeed) & 127;
        if (nRand < pMissilesTxtRecord->dwDmgParam[0])
        {
            pDamage->wResultFlags |= 0x4000;
        }
    }
}

inline int UNITS_IsValidTargetInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 3) & 1;
}

inline int UNITS_CanBeAttackedInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> 2) & 1;
}

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

// build: symbol ?MONSTERMODE_CanCollideWithUnit@* 0x005A8730
static int __stdcall MONSTERMODE_CanCollideWithUnit(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2UnitStrc* pOwner, D2MissilesTxt* pMissilesTxtRecord)
{
    if (!UNITS_IsValidTargetInline(pUnit))
    {
        return 0;
    }

    if (!UNITS_CanBeAttackedInline(pUnit))
    {
        return 0;
    }

    if (pMissilesTxtRecord->nNextHit && STATES_CheckState(pUnit, STATE_JUSTHIT))
    {
        return 0;
    }

    if (MISSILE_CheckUnitIfOwner(pMissile, pUnit) || (pOwner && !SUNIT_AreUnitsHostile(pGame, pOwner, pUnit) && !pMissilesTxtRecord->nCollideFriend))
    {
        return 0;
    }

    return 1;
}

// 0x005A87B0
int __fastcall MISSMODE_UnitFindCallback_CanCollideWithMonster(D2UnitStrc* pUnit, void* pArgument)
{
    D2MissileUnitFindArgStrc* pArg = (D2MissileUnitFindArgStrc*)pArgument;
    if (!pArg || !pArg->pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }

    return MONSTERMODE_CanCollideWithUnit(pArg->pGame, pArg->pMissile, pUnit, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x005A87F0
int __fastcall MISSMODE_UnitFindCallback_CanCollideWithGoodAlignmentUnit(D2UnitStrc* pUnit, void* pArgument)
{
    D2MissileUnitFindArgStrc* pArg = (D2MissileUnitFindArgStrc*)pArgument;
    if (!pArg || !pArg->pMissilesTxtRecord)
    {
        return 0;
    }

    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    switch (nType)
    {
    case 0:
        break;
    case 1:
        if (STATLIST_GetUnitAlignment(pUnit) != 2)
        {
            return 0;
        }
        break;
    default:
        return 0;
    }

    return MONSTERMODE_CanCollideWithUnit(pArg->pGame, pArg->pMissile, pUnit, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x005A8850
int __fastcall MISSMODE_UnitFindCallback_CanCollideWithPlayerOrMonster(D2UnitStrc* pUnit, void* pArgument)
{
    D2MissileUnitFindArgStrc* pArg = (D2MissileUnitFindArgStrc*)pArgument;
    if (!pArg || !pArg->pMissilesTxtRecord)
    {
        return 0;
    }

    if (!pUnit || pUnit->dwUnitType < 0 || pUnit->dwUnitType > 1)
    {
        return 0;
    }

    return MONSTERMODE_CanCollideWithUnit(pArg->pGame, pArg->pMissile, pUnit, pArg->pOwner, pArg->pMissilesTxtRecord) != 0;
}

// 0x005A8890
int __fastcall MISSMODE_UnitFindCallback_CanMissileDestroy(D2UnitStrc* pUnit, void* pArgument)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pUnit->dwClassId);
    if (!pMissilesTxtRecord || !(pMissilesTxtRecord->nMissileFlags[4 >> 3] & gdwBitMasks[4 & 7]))
    {
        return 0;
    }

    return 1;
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecordInline(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x005AD2B0
void __fastcall MISSMODE_SrvDmg10_BladesOfIceCubes(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (pMissile && DATATBLS_GetMissilesTxtRecordInline(pMissile->dwClassId))
    {
        pDamage->dwFrzLen = pDamage->dwColdLen;
    }
}

// 0x005A88E0
int __fastcall MISSMODE_RollMissileHit(D2UnitStrc* pMissile, int nUnused, D2UnitStrc* pOwner, D2UnitStrc* pUnit)
{
    int nToHit = 0;
    if (pMissile)
    {
        nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
    }

    return SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1) != 0;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

// 0x005AD3A0
void __fastcall MISSMODE_SrvDmg06_MarkTargetNoTreasureClass(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (pOwner && !UNIT_HasFlag(pOwner, UNITFLAG_ISMERC) && pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_NOTC;
    }
}

static inline void MISSMODE_SetMissileHitFlags(D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    if (MISSILE_GetFlags(pUnit) & 1)
    {
        pDamage->dwHitFlags |= 0x20;
    }

    if (MISSILE_GetFlags(pUnit) & 2)
    {
        pDamage->dwHitFlags |= 0x80;
    }

    pDamage->dwPiercePct = STATLIST_UnitGetStatValue(pUnit, 0x147, 0);
}

// 0x005AD730
void __fastcall MISSMODE_SetDamageFlags(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    if (!pMissile || pMissile->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return;
    }

    pDamage->wResultFlags |= 1;

    if (!STATES_CheckState(pDefender, STATE_UNINTERRUPTABLE))
    {
        if (pMissilesTxtRecord->nMissileFlags[0] & gdwBitMasks[6])
        {
            pDamage->wResultFlags |= 4;
        }
        else if (pMissilesTxtRecord->nMissileFlags[0] & gdwBitMasks[7])
        {
            pDamage->wResultFlags |= 0x4000;
        }

        if (pMissilesTxtRecord->nKnockBack > 0 && (int)SEED_RollLimitedRandomNumber(&pMissile->pSeed, 100) < pMissilesTxtRecord->nKnockBack)
        {
            pDamage->wResultFlags |= 8;
        }
    }

    unsigned int nBlockFlags = SUNITDMG_ApplyBlockOrDodge(pGame, pOwner, pDefender, 1, pDamage->dwPhysDamage != 0);
    if (nBlockFlags & 0x1F && !(pMissilesTxtRecord->nMissileFlags[0] & gdwBitMasks[6]) && !pMissilesTxtRecord->nKnockBack)
    {
        pDamage->wResultFlags = pDamage->wResultFlags & (unsigned short)~1 | 0x4000;
        nBlockFlags &= 0xFFFFFFE0;
    }

    if (nBlockFlags & 8)
    {
        pDamage->wResultFlags |= 0x200;
    }

    if (nBlockFlags & 2)
    {
        pDamage->wResultFlags |= 0x100;
    }

    if (nBlockFlags & 0x11)
    {
        pDamage->wResultFlags |= 0x10;
    }

    if (nBlockFlags)
    {
        pDamage->wResultFlags &= (unsigned short)~1;
    }

    const unsigned int* pdwHitClass = &pDamage->dwHitClass;
    pDamage->dwHitClass = *pdwHitClass & 0xF0 | MISSILE_GetHitClass(pMissile);

    if (*pdwHitClass & 0xF0)
    {
        pDamage->nHitClassActiveSet = 1;
    }

    D2GAME_MONSTER_ApplyCriticalDamage_6FC62E70(pOwner, pDefender, pDamage);

    MISSMODE_SetMissileHitFlags(pMissile, pDamage);

    if (pDamage->wResultFlags & 1)
    {
        SUNITDMG_ExecuteEvents(pGame, pOwner, pDefender, 1, pDamage);
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pOwner, pDefender, pDamage);
}

void __fastcall sub_M250_Emit_005AD930(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    MISSMODE_BaalFxOpenPortal(pGame, pMissile);
}

inline D2MissilesTxt* DATATBLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }
    return 0;
}

// 0x005AD9D0
void __fastcall MISSMODE_HitAndRemoveMissile(D2GameStrc* pGame, D2UnitStrc* pMissile, int bHit)
{
    const int nMissileId = !pMissile ? -1 : pMissile->dwClassId;
    if (bHit)
    {
        const short nHitFunc = DATATBLS_GetMissilesTxtRecord(nMissileId)->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, 0);
        }
    }

    SUNIT_RemoveUnit(pGame, pMissile);
}

// 0x005ADA40
static int MISSMODE_IsUnitTypeValidForMissileMode(int nMissileMode, D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    switch (nMissileMode)
    {
    case 0:
        return 0;
    case 1:
        if (nUnitType != 0)
            return 0;
        break;
    case 2:
        if (nUnitType != 1)
            return 0;
        break;
    case 3:
        return 1;
    }
    return 1;
}

// 0x005ADA80
static int MISSMODE_GetPierceFlags(D2UnitStrc* pMissile)
{
    int nResult = 3;

    D2MissilesTxt* pMissilesTxtRecord = DATATBLS_GetMissilesTxtRecord(pMissile ? pMissile->dwClassId : -1);
    if (pMissilesTxtRecord->nMissileFlags[2 >> 3] & gdwBitMasks[2 & 7])
    {
        const int nPierceIndex = STATLIST_UnitGetStatValue(pMissile, 328, 0);
        if (nPierceIndex)
        {
            nResult = 2;
            STATLIST_SetUnitStat(pMissile, 328, nPierceIndex - 1, 0);
        }
    }

    return nResult;
}

// 0x005ADAF0
void __fastcall SKILLDESC_ToggleStateOffCallback(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList)
{
    STATES_ToggleState(pUnit, nState, 0);
}

// 0x005ADB00
static void __fastcall MISSMODE_SetJustHitState(D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if (!pTxt->nNextHit || !pUnit)
        return;

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pMissile);
    const int nDelay = pTxt->nNextDelay + pGame->dwGameFrame;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nDelay, pUnit->dwUnitType, pUnit->dwUnitId);
    if (!pStatList)
        return;

    EVENT_SetEvent(pGame, pUnit, 0xC, nDelay, 0, 0);
    STATLIST_SetState(pStatList, STATE_JUSTHIT);
    STATLIST_SetStatRemoveCallback(pStatList, MISSMODE_ToggleStateOff);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATES_ToggleState(pUnit, 0x56, 1);
}

static __forceinline int IsUnitInTown(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    return pRoom && DUNGEON_IsRoomInTown(pRoom);
}

// 0x005ADBB0
static void __stdcall MISSMODE_SrvDoHandler(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || (short)pMissilesTxtRecord->wSrvDoFunc <= 0 || (short)pMissilesTxtRecord->wSrvDoFunc >= gnMissileSrvDoFuncCount)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (!pRoom)
    {
        pRoom = sub_00463740_FindRoomAtPoint(0, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if ((pMissilesTxtRecord->nMissileFlags[MISSILESFLAGINDEX_SRCTOWN >> 3] & gdwBitMasks[MISSILESFLAGINDEX_SRCTOWN & 7]) && pOwner && IsUnitInTown(pOwner)
        || pOwner && pOwner->dwUnitType == UNIT_PLAYER && IsUnitInTown(pOwner)
        || !(pMissilesTxtRecord->nMissileFlags[MISSILESFLAGINDEX_TOWN >> 3] & gdwBitMasks[MISSILESFLAGINDEX_TOWN & 7]) && DUNGEON_IsRoomInTown(pRoom)
        || gpfnMissileSrvDoFunctions[(short)pMissilesTxtRecord->wSrvDoFunc](pGame, pMissile) == 2)
    {
        SUNIT_RemoveUnit(pGame, pMissile);
    }
}

// 0x005ADCC0
void __fastcall MISSMODE_SrvDoEventCallback(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnused)
{
    MISSMODE_SrvDoHandler(pGame, pMissile);
}

// 0x005ADCD0
static void __fastcall MISSMODE_ApplyDamageFlagsAndTargetAc(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, D2DamageStrc* pDamage)
{
    MISSMODE_SetDamageFlags(pGame, pMissile, pUnit, pDamage);
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pUnit))
    {
        const int nDamageTargetAc = STATLIST_UnitGetStatValue(pMissile, 0x78, 0);
        if (nDamageTargetAc)
        {
            int nArmor = nDamageTargetAc + STATLIST_UnitGetStatValue(pUnit, 0x1F, 0);
            if (nArmor < 0)
                nArmor = 0;
            STATLIST_SetUnitStat(pUnit, 0x1F, nArmor, 0);
        }
    }
}

static int sub_005ADA80_GetPierceFlags(D2UnitStrc* pMissile)
{
    int nResult = 3;
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord(pMissile->dwClassId) : 0;
    if ((pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[2]))
    {
        const int nPierce = STATLIST_UnitGetStatValue(pMissile, 0x148, 0);
        if (nPierce)
        {
            nResult = 2;
            STATLIST_SetUnitStat(pMissile, 0x148, nPierce - 1, 0);
        }
    }
    return nResult;
}

static int sub_005ADA80_GetPierceFlags_005B01F0(D2UnitStrc* pMissile)
{
    int nResult = 3;
    D2MissilesTxt* pTxt = pMissile ? SKILLS_GetMissilesTxtRecord_005B01F0(pMissile->dwClassId) : 0;
    if ((pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[2]))
    {
        const int nPierce = STATLIST_UnitGetStatValue(pMissile, STAT_PIERCE_IDX, 0);
        if (nPierce)
        {
            nResult = 2;
            STATLIST_SetUnitStat(pMissile, STAT_PIERCE_IDX, nPierce - 1, 0);
        }
    }
    return nResult;
}

__declspec(noinline) int __fastcall MISSMODE_SrvDmgHitHandler(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int bForceCollision)
{
    D2MissilesTxt* pTxt = 0;
    if (pMissile)
    {
        pTxt = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    int nHitResult = 2;
    int nPierceFlags = 3;
    if (pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[1])
    {
        nHitResult = 0;
    }

    if (pUnit)
    {
        if ((pTxt->nNextHit && STATES_CheckState(pUnit, STATE_JUSTHIT)) || MISSILE_CheckUnitIfOwner(pMissile, pUnit))
        {
            return 1;
        }

        MISSILE_SetOwner(pMissile, pUnit);
        if (!MISSMODE_IsUnitTypeValidForMissileMode(!pMissile ? 0 : pMissile->dwMissileMode, pUnit))
        {
            return 1;
        }

        if (pOwner && !SUNIT_AreUnitsHostile(pGame, pOwner, pUnit) && !pTxt->nCollideFriend)
        {
            return 1;
        }
    }

    if (pOwner && pUnit && (pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[2])
        && (STATLIST_UnitGetStatValue(pOwner, 0xA6, 0) || STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, 0x9C, 0)))
    {
        nPierceFlags = sub_005ADA80_GetPierceFlags(pMissile);
    }

    if (pTxt->nCollideKill)
    {
        nHitResult |= 1;
    }

    if (pUnit)
    {
        if (pTxt->nToHit)
        {
            int nToHit = 0;
            if (pMissile)
            {
                nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
            }

            if (!SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1))
            {
                MISSMODE_SetJustHitState(pMissile, pUnit);
                SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
                if (pTxt->nAlwaysExplode)
                {
                    const short nHitFunc = pTxt->wSrvHitFunc;
                    if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
                    {
                        if (gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit) & 4)
                        {
                            return 1;
                        }
                    }
                }
                return 2;
            }
        }
    }
    else if (!bForceCollision && !pTxt->nAlwaysExplode)
    {
        if (!(nHitResult & 1) && !bForceCollision || !(nPierceFlags & 1))
        {
            return 1;
        }

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (pRoom)
        {
            COLLISION_ResetMaskWithSize(pRoom, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
        }
        return 2;
    }

    if (nPierceFlags & 2)
    {
        MISSMODE_SetJustHitState(pMissile, pUnit);
        SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
        const short nHitFunc = pTxt->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            nHitResult = gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit);
            if (nHitResult & 4)
            {
                return 1;
            }
        }
    }

    if (pUnit && (nHitResult & 2))
    {
        D2DamageStrc tDamage;
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &tDamage);
        const short nDmgFunc = pTxt->wSrvDmgFunc;
// build: symbol ?gnMissileSrvDmgFnCount@* 0x0073C95C
        if (nDmgFunc > 0 && nDmgFunc < gnMissileSrvDmgFnCount)
        {
            gpfnMissileSrvDmgFunctions[nDmgFunc](pGame, pMissile, pUnit, &tDamage);
        }
        MISSMODE_ApplyDamageFlagsAndTargetAc(pGame, pMissile, pUnit, &tDamage);
    }

    if (!(nHitResult & 1) && !bForceCollision || !(nPierceFlags & 1))
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (pRoom)
    {
        COLLISION_ResetMaskWithSize(pRoom, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
    }
    return 2;
}

static inline int __fastcall MISSMODE_SrvDmgHitHandler_005B01F0(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit, int bForceCollision)
{
    D2MissilesTxt* pTxt = 0;
    if (pMissile)
    {
        pTxt = SKILLS_GetMissilesTxtRecord_005B01F0(pMissile->dwClassId);
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    int nHitResult = 2;
    int nPierceFlags = 3;
    if (pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[1])
    {
        nHitResult = 0;
    }

    if (pUnit)
    {
        if ((pTxt->nNextHit && STATES_CheckState(pUnit, STATE_JUSTHIT)) || MISSILE_CheckUnitIfOwner(pMissile, pUnit))
        {
            return 1;
        }

        MISSILE_SetOwner(pMissile, pUnit);
        if (!MISSMODE_IsUnitTypeValidForMissileMode(!pMissile ? 0 : pMissile->dwMissileMode, pUnit))
        {
            return 1;
        }

        if (pOwner && !SUNIT_AreUnitsHostile(pGame, pOwner, pUnit) && !pTxt->nCollideFriend)
        {
            return 1;
        }
    }

    if (pOwner && pUnit && (pTxt->nMissileFlags[0] & gdwBitMasks_006CE268[2])
        && (STATLIST_UnitGetStatValue(pOwner, STAT_SKILL_PIERCE, 0) || STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_PIERCE, 0)))
    {
        nPierceFlags = sub_005ADA80_GetPierceFlags_005B01F0(pMissile);
    }

    if (pTxt->nCollideKill)
    {
        nHitResult |= 1;
    }

    if (pUnit)
    {
        if (pTxt->nToHit)
        {
            int nToHit = 0;
            if (pMissile)
            {
                nToHit = STATLIST_UnitGetStatValue(pMissile, STAT_TOHIT, 0);
            }

            if (!SUNITDMG_IsHitSuccessful(pOwner, pUnit, nToHit, 1))
            {
                MISSMODE_SetJustHitState(pMissile, pUnit);
                SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
                if (pTxt->nAlwaysExplode)
                {
                    const short nHitFunc = pTxt->wSrvHitFunc;
                    if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
                    {
                        if (gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit) & 4)
                        {
                            return 1;
                        }
                    }
                }
                return 2;
            }
        }
    }
    else if (!bForceCollision && !pTxt->nAlwaysExplode)
    {
        goto CollisionCleanup;
    }

    if (nPierceFlags & 2)
    {
        MISSMODE_SetJustHitState(pMissile, pUnit);
        SUNITEVENT_Trigger(pGame, 0, pUnit, pMissile, 0);
        const short nHitFunc = pTxt->wSrvHitFunc;
        if (nHitFunc > 0 && nHitFunc < gnMissileSrvHitFnCount)
        {
            nHitResult = gpfMissileSrvHitFn[nHitFunc](pGame, pMissile, pUnit);
            if (nHitResult & 4)
            {
                return 1;
            }
        }
    }

    if (pUnit && (nHitResult & 2))
    {
        D2DamageStrc tDamage;
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &tDamage);
        const short nDmgFunc = pTxt->wSrvDmgFunc;
        if (nDmgFunc > 0 && nDmgFunc < gnMissileSrvDmgFnCount)
        {
            gpfnMissileSrvDmgFunctions[nDmgFunc](pGame, pMissile, pUnit, &tDamage);
        }
        MISSMODE_ApplyDamageFlagsAndTargetAc(pGame, pMissile, pUnit, &tDamage);
    }

CollisionCleanup:
    if (!(nHitResult & 1) && !bForceCollision || !(nPierceFlags & 1))
    {
        return 1;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
    if (pRoom)
    {
        COLLISION_ResetMaskWithSize(pRoom, CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile), UNITS_GetUnitSizeX(pMissile), 0x40);
    }
    return 2;
}

static D2SkillsTxt* MISSMODE_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005AE1F0
int __fastcall MISSMODE_HandleMissileCollision(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = GetMissilesTxt(pMissile);
    if (!pMissilesTxtRecord) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    if (PATH_GetVelocity(pMissile->pDynamicPath) && SUNIT_UpdateUnitPath(pGame, pMissile) == 2)
        return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    const int nFrame = MISSILE_GetCurrentFrame(pMissile) - 1;
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    if (nFrame <= 0) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
    const int nMode = pMissile->dwAnimMode;
    if (nMode)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        if (!pRoom || !pPath) return 2;
        unsigned short nCollision = D2Common_10201(pPath);
        if (nCollision & 5) return 2;
        if (nMode != 6 && MISSILE_GetCurrentFrame(pMissile) <= MISSILE_GetActivateFrame(pMissile) && nCollision)
        {
            if (!gtMissileCollisionModes[nMode].pfUnitFindCallback) return 2;
            D2MissileFindArgStrc tFindArg;
            tFindArg.pGame = pGame;
            tFindArg.pMissile = pMissile;
            tFindArg.pOwner = SUNIT_GetOwner(pGame, pMissile);
            tFindArg.pMissilesTxtRecord = pMissilesTxtRecord;
            const int nSize = UNITS_GetUnitSizeX(pMissile);
            D2PathPointStrc* pPoints;
            const int nPoints = D2COMMON_10198_PathGetSaveStep(pPath, &pPoints);
            for (int i = 0; i < nPoints; ++i)
            {
                const int nX = pPoints[i].X;
                const int nY = pPoints[i].Y;
                nCollision = COLLISION_CheckMaskWithSize(pRoom, nX, nY, nSize, gtMissileCollisionModes[nMode].nCollisionMask);
                if (nCollision)
                {
                    D2UnitStrc* pTarget = D2Common_10407(pRoom, nX, nY, gtMissileCollisionModes[nMode].pfUnitFindCallback, &tFindArg, nSize);
                    if (pTarget) return MISSMODE_SrvDmgHitHandler(pGame, pMissile, pTarget, 0);
                    if (nCollision & 4)
                    {
                        MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
                        return 2;
                    }
                }
            }
        }
    }
    return 1;
}

// 0x005AE400
int __fastcall MISSMODE_SrvDo02_PlagueJavelin_PoisonJavelin_PoisonTrap(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (pMissile)
    {
        const int nMissileId = pMissile->dwClassId;
        D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
        if (pMissilesTxtRecord && pMissilesTxtRecord->wSubMissile[0] >= 0)
        {
            MISSMODE_CreatePlagueJavelin_PoisonJavelin_PoisonTrapHitSubmissiles(pGame, pMissile, pMissilesTxtRecord->wSubMissile[0], 0, MISSILE_EvaluateMissileFormula(pMissile, SUNIT_GetOwner(pGame, pMissile), pMissilesTxtRecord->dwSrvCalc, nMissileId, MISSILE_GetLevel(pMissile)));
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AE480
int __fastcall MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (pMissile->pDynamicPath && PATH_GetVelocity(pMissile->pDynamicPath))
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    COLLISION_SetMask(UNITS_GetRoom(pMissile), CLIENTS_GetUnitXInline(pMissile), CLIENTS_GetUnitYInline(pMissile), 0x40);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AE520
int __fastcall MISSMODE_SrvDo05_FireWall_ImmolationFire_MeteorFire_MoltenBoulderFirePath(D2GameStrc* game,D2UnitStrc* unit)
{
 D2MissilesTxt* rec;
 if(unit && unit->dwClassId>=0 && unit->dwClassId<gpDataTables->count) rec=&gpDataTables->missiles[unit->dwClassId];
 else rec=0;
 if(!rec) return MISSMODE_HandleMissileCollision(game,unit);
 int frame=unit->nSeqCurrentFramePrecise>>8;
 COLLISION_SetMaskWithSize(UNITS_GetRoom(unit),GetX(unit),GetY(unit),UNITS_GetUnitSizeX(unit),0x40);
 if(frame==rec->nSubStart-1) {
  unit->nSeqCurrentFramePrecise=(frame+sub_0045C3E0_RollLimited(&unit->pSeed,rec->nSubStop-rec->nSubStart))<<8;
 }
 else if(sub_0064A380_GetRemainingFrames(unit)==rec->nSubStart) {
  unit->nSeqCurrentFramePrecise=(rec->nSubStart-3)<<8;
 }
 else if(sub_0064A380_GetRemainingFrames(unit)<rec->nSubStart) {
  frame-=2; if(frame<0)frame=0; unit->nSeqCurrentFramePrecise=frame<<8;
 }
 return MISSMODE_HandleMissileCollision(game,unit);
}

// 0x005AE680
int __fastcall MISSMODE_SrvDo06_MoltenBoulder_FireWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || !pMissile)
    {
        return 2;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0 || !pMissile->pDynamicPath)
    {
        return 2;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);

        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pOwner;
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AE780
int __fastcall MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner) || DUNGEON_IsRoomInTown(UNITS_GetRoom(pMissile)))
    {
        return 2;
    }

    if (MISSILE_GetTargetX(pMissile) & 1)
    {
        SUNIT_ValidateTargetUnit(pGame, pMissile);

        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pMissile);
        if (pTarget && (SUNIT_IsDead(pTarget) || !SUNIT_AreUnitsHostile(pGame, pOwner, pTarget)))
        {
            pTarget = 0;
        }

        int nParam = pMissilesTxtRecord->dwParam[0];
        if (nParam <= 0)
        {
            nParam = 5;
        }

        if (pTarget && !(MISSILE_GetCurrentFrame(pMissile) % nParam))
        {
            const int nDistance = DRLG_UnitEdgeDistance(pMissile, pTarget);
            if (nDistance > 3 && nDistance < 25)
            {
                D2Common_10142(pPath, pMissile, 0);
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AEA60
int __fastcall MISSMODE_SrvDo10_BlizzardCenter(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecord(pMissile);
    if (!pRecord && pRecord->wSubMissile[0] < 0)
        return 2;
    int nSkill = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkill = GetSkillRecord(nSkill);
    if (!pSkill)
        return 2;
    int nLevel = MISSILE_GetLevel(pMissile);
    int nRange = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[0], nSkill, nLevel);
    int nRate = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[1], nSkill, nLevel);
    MISSMODE_CreateMissileWithCollisionCheck(pGame, nRange, pRecord->wSubMissile[0], 5, pMissile, nRate);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

static D2MissilesTxt* GetMissileRecordById(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nMissileId];
    return 0;
}

// 0x005AE8A0
int __fastcall MISSMODE_SrvDo08_MonBlizzCenter(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecordById(!pMissile ? -1 : pMissile->dwClassId);
    if (!pRecord && pRecord->wSubMissile[0] < 0)
        return 2;
    int nLevel = MISSILE_GetLevel(pMissile);
    int nDivisor = pRecord->dwParam[2];
    if (nDivisor < 1)
        nDivisor = 1;
    int nQuotient = nLevel / nDivisor;
    int nRange = pRecord->dwParam[0] + (nQuotient < 2 ? 2 : nQuotient);
    MISSMODE_CreateMissileWithCollisionCheck(pGame, nRange, pRecord->wSubMissile[0], 5, pMissile, pRecord->dwParam[1] - nQuotient < 3 ? 3 : pRecord->dwParam[1] - nQuotient);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

inline int UNITS_InlineGetXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;

    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

inline int UNITS_InlineGetYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;

    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005AE940
int __fastcall MISSMODE_SrvDo09_BatLightningBolt(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissileStrc missileParams;
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord && pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    const int nX = UNITS_InlineGetXPosition(pMissile);
    const int nY = UNITS_InlineGetYPosition(pMissile);
    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 1;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AEB60
int __fastcall MISSMODE_SrvDo11_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pMissile);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pTarget && pOwner)
    {
        pTarget = SUNIT_GetTargetUnit(pGame, pOwner);
    }

    if (pTarget)
    {
        int nFrames = pMissilesTxtRecord->dwParam[0];
        if (nFrames <= 0)
        {
            nFrames = 5;
        }

        if (!(MISSILE_GetCurrentFrame(pMissile) % nFrames) && DRLG_UnitEdgeDistance(pMissile, pTarget) <= pMissilesTxtRecord->dwParam[1])
        {
            const int nMissileX = CLIENTS_GetUnitX(pMissile);
            const int nMissileY = CLIENTS_GetUnitY(pMissile);
            const int nTargetX = CLIENTS_GetUnitX(pTarget);
            const int nTargetY = CLIENTS_GetUnitY(pTarget);

            int nParam = pMissilesTxtRecord->dwParam[2];
            if (nParam < 1)
            {
                nParam = 1;
            }

            int nX = 0;
            int nY = 0;
            if (nTargetX > nMissileX)
            {
                nX = nParam;
            }
            else if (nTargetX < nMissileX)
            {
                nX = -nParam;
            }

            if (nTargetY > nMissileY)
            {
                nY = nParam;
            }
            else if (nTargetY < nMissileY)
            {
                nY = -nParam;
            }

            D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, nX + CLIENTS_GetUnitX(pMissile), nY + CLIENTS_GetUnitY(pMissile));
            D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AECA0
int __fastcall MISSMODE_SrvDo12_DiabWallMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    if (!SUNIT_GetOwner(pGame, pMissile))
    {
        return 2;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        const int nX = CLIENTS_GetUnitX(pMissile);
        const int nY = CLIENTS_GetUnitY(pMissile);

        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nTargetX = nX;
        missileParams.nTargetY = nY;
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AEDA0
int __fastcall MISSMODE_SrvDo13_BoneWallMaker(D2GameStrc* game,D2UnitStrc* unit)
{
 if(!SUNIT_GetOwner(game,unit) || !sub_0064A780_GetCount(unit)) return 2;
 if(PATH_HasEnteredNewSubtile(unit->pDynamicPath)) {
  D2UnitStrc* owner=SUNIT_GetOwner(game,unit);
  int skillId,skillLevel;
  D2SkillsTxt* skill;
  if(!owner) return 2;
  skillId=sub_0064A280_GetSkill(unit);
  skillLevel=sub_0064A210_GetSkillLevel(unit);
  skill=sub_0045C4B0_GetSkillsTxtRecord(skillId);
  if(!skill) return 2;
  int variant;
  int monsterId=D2GAME_GetSummonIdFromSkill(owner,0,skillId,skillLevel,&variant,0,0);
  if(monsterId<0) return 0;
  unsigned char petType=skill->nPetType;
  if(petType>=sgptDataTables->nPetTypeTxtRecordCount) petType=0;
  D2UnitStrc* target=SUNIT_GetServerUnit(game,1,sub_0064A730_GetUnitId(unit));
  if(target) {
   D2SummonArgs args;
   memset(&args,0,sizeof(args));
   args.mode=13;args.owner=owner;args.monsterId=monsterId;args.unknown=0;args.variant=variant;
   args.x=CLIENTS_GetUnitX(unit);args.y=CLIENTS_GetUnitY(unit);args.petType=petType;
   D2UnitStrc* summoned=sub_0056D940_Summon(game,&args);
   if(summoned) {
    AIGENERAL_SetOwnerData(game,summoned,!target ? -1 : target->dwUnitId,1,0,0);
    AIGENERAL_AllocMinionList(game,target,summoned);
    D2GAME_BOSSES_AssignUMod_6FC6FF10(game,summoned,15,0);
    D2GAME_SetSummonPassiveStats_6FD0C530(game,owner,summoned,skillId,skillLevel,0);
    UNITS_StoreOwner(summoned,owner);
    TARGETS_InsertUnitNode(game,summoned,0,9);
    int count=sub_0064A780_GetCount(unit);--count;MISSILE_SetTargetY(unit,count);
   }
  }
 }
 return MISSMODE_HandleMissileCollision(game,unit);
}

// 0x005AEF70
int __fastcall MISSMODE_SrvDo14_GrimWard(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nParam = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nParam)
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    if (nSkillId > 0 && nLevel > 0)
    {
        SKILLS_ExecuteServerDoFunction(pGame, pMissile, pMissilesTxtRecord->dwParam[1], nSkillId, nLevel);
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    return 2;
}

// 0x005AF030
int __fastcall MISSMODE_SrvDo15_FrozenOrb(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 2;
    }

    const int nFrames = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (sub_0064A3B0_GetElapsedFrames(pMissile) % nFrames > 0)
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 2;
    missileParams.pOwner = pOwner;
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];

    int nIndex = MISSILE_GetTargetX(pMissile) % 64;
    nIndex = nIndex < 0 ? -nIndex : nIndex;
// build: symbol ?gnSrvDo15_XPositions@* 0x006E2B78
    missileParams.nTargetX = gnSrvDo15_XPositions[nIndex];
// build: symbol ?gnSrvDo15_YPositions@* 0x006E2A78
    missileParams.nTargetY = gnSrvDo15_YPositions[nIndex];
    MISSILE_SetTargetX(pMissile, (nIndex + pMissilesTxtRecord->dwParam[1]) % 64);
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF170
int __fastcall MISSMODE_SrvDo16_FrozenOrbNova(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pRecord) return 2;
    const int nPeriod = pRecord->dwParam[1] < 1 ? 1 : pRecord->dwParam[1];
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames < pRecord->dwParam[0] && !(nFrames % nPeriod))
    {
        int nNewX = sub_0064A730_GetUnitId(pMissile);
        int nNewY = sub_0064A780_GetCount(pMissile);
        const int nOldX = nNewX;
        const int nNegY = -nNewY;
        __assume(nNegY != (-2147483647 - 1)); // __assume only keeps the original neg+add for x - y (written plainly it compiles to mov/sub)
        nNewX = (nNegY + nNewX) / 2;
        nNewY = (nOldX + nNewY) / 2;
        D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, CLIENTS_GetUnitX(pMissile) + nNewX, CLIENTS_GetUnitY(pMissile) + nNewY);
        D2Common_10142(pMissile->pDynamicPath, pMissile, 0);
        MISSILE_SetTargetX(pMissile, nNewX);
        MISSILE_SetTargetY(pMissile, nNewY);
    }
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF240
int __fastcall MISSMODE_SrvDo17_CairnStones(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecord(pMissile);
    if (!pRecord)
        return 2;
    int nRemaining = sub_0064A380_GetRemainingFrames(pMissile);
    if (pRecord->wSubMissile[0] > 0 && nRemaining < pRecord->wRange - pRecord->dwParam[0] && nRemaining > pRecord->dwParam[0])
        MISSMODE_CreateMissileWithCollisionCheck(pGame, pRecord->dwParam[2], pRecord->wSubMissile[0], 5, pMissile, pRecord->dwParam[1]);
    if (pRecord->dwParam[3] >= 0 && !MISSILE_GetTargetX(pMissile) && nRemaining <= pRecord->dwParam[4] + pRecord->dwParam[0])
        sub_005A9930_CreateAtMissile(pGame, pMissile, pRecord->dwParam[3]);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF300
int __fastcall MISSMODE_SrvDo18_TowerChestSpawner(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxt = 0;
    if (pMissile && pMissile->dwClassId >= 0 && pMissile->dwClassId < sgptDataTables->nMissilesTxtRecordCount)
        pMissilesTxt = &sgptDataTables->pMissilesTxt[pMissile->dwClassId];
    if (!pMissilesTxt) return 2;
    const int nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    if (nCurrentFrame == 1)
    {
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, MISSILE_GetTargetX(pMissile));
        if (pObject) SUNIT_AttachSound(pObject, 92, 0);
    }
    if (nCurrentFrame == pMissilesTxt->wRange - pMissilesTxt->dwParam[0])
    {
        const int nObjectGUID = MISSILE_GetTargetX(pMissile);
        D2ObjOperateFnStrc op;
        op.pGame = pGame;
        op.hPlayer = 0;
        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, 2, nObjectGUID);
        if (pObject)
        {
            op.pObjectregion = (D2ObjectControlStrc*)&pObject->pSeed;
            op.hObject = pObject;
            op.nObjectIdx = pObject->dwClassId;
            OBJMODE_OpenTowerChest(&op);
        }
        MISSILE_SetTargetY(pMissile, 1);
    }
    if (MISSILE_GetTargetY(pMissile))
    {
        int nFrequency = 2 * pMissilesTxt->dwParam[1];
        nFrequency *= 2;
        if (nFrequency < 1) nFrequency = 1;
        if (!(nCurrentFrame % nFrequency))
        {
            D2CoordStrc coords;
            UNITS_GetCoords(pMissile, &coords);
            const int nRange = pMissilesTxt->dwParam[2];
            D2SeedStrc* pSeed = &pMissile->pSeed;
            coords.nX += ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;
            coords.nY += ITEMS_RollLimitedRandomNumber(pSeed, 2 * nRange + 1) - nRange;
            D2CoordStrc returnCoords;
            D2ActiveRoomStrc* pRoom = D2GAME_GetFreeSpaceEx_6FC4BF00(UNITS_GetRoom(pMissile), &coords, &returnCoords, 1, 1);
            if (pRoom)
            {
                const int nItemLevel = DATATBLS_GetMonsterLevelInArea(DUNGEON_GetLevelIdFromRoom(pRoom), pGame->nDifficulty, pGame->bExpansion);
                D2ItemDropStrc drop;
                memset(&drop, 0, sizeof(drop));
                drop.pUnit = pMissile;
                drop.pSeed = 0;
                drop.pGame = pGame;
                drop.wItemFormat = pGame->wItemFormat;
                drop.nId = DATATBLS_GetItemIdFromItemCode(0x20646C67);
                drop.nSpawnType = 3;
                drop.nX = returnCoords.nX;
                drop.nY = returnCoords.nY;
                drop.pRoom = pRoom;
                drop.wUnitInitFlags = 1;
                drop.nQuality = 2;
                drop.nItemLvl = nItemLevel;
                D2GAME_CreateItemEx_6FC4ED80(pGame, &drop, 0);
            }
        }
    }
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF540
int __fastcall MISSMODE_SrvDo20_BladeCreeper(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
        return 2;
    }

    MISSMODE_PlacePathAtOwner(pGame, pMissile);
    MISSILE_SetCurrentFrame(pMissile, 10);
    MISSMODE_HandleMissileCollision(pGame, pMissile);
    return 1;
}

// 0x005AF590
int __fastcall MISSMODE_SrvDo21_Distraction(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    if (pMissilesTxtRecord->wSubMissile[0] && PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->wSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    return MISSMODE_SrvDo20_BladeCreeper(pGame, pMissile);
}

// 0x005AF620
int __fastcall MISSMODE_SrvDo22_LightningTrailingJavelin(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    D2DynamicPathStrc* pPath;
    if (!pMissilesTxtRecord || !pMissilesTxtRecord->wSubMissile[0] || (pPath = pMissile->pDynamicPath) == 0)
    {
        return 2;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    if (sub_0064A3B0_GetElapsedFrames(pMissile) < 2)
    {
        const int nParam1 = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath) - nX;
        const int nParam2 = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath) - nY;
        MISSILE_SetTargetX(pMissile, -nParam2);
        MISSILE_SetTargetY(pMissile, nParam1);
    }

    if (PATH_HasEnteredNewSubtile(pPath))
    {
        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 11;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nLoops = pMissilesTxtRecord->dwParam[0];
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.nTargetX = MISSILE_GetTargetX(pMissile);
        missileParams.nTargetY = MISSILE_GetTargetY(pMissile);
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
        missileParams.nTargetX = -MISSILE_GetTargetX(pMissile);
        missileParams.nTargetY = -MISSILE_GetTargetY(pMissile);
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF790
int __fastcall MISSMODE_SrvDo23_24_SuccFireBall_FirestormMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || !pMissilesTxtRecord->wSubMissile[0])
    {
        return 2;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 1;
        if (pMissilesTxtRecord->dwParam[0] > 0)
        {
            missileParams.dwFlags = 9;
            missileParams.nLoops = pMissilesTxtRecord->dwParam[0];
        }

        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.nX = CLIENTS_GetUnitX(pMissile);
        missileParams.nY = CLIENTS_GetUnitY(pMissile);
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF880
int __fastcall MISSMODE_SrvDo25_EruptionCenter(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pRecord = GetMissileRecord(pMissile);
    if (!pRecord || !pRecord->wSubMissile[0])
        return 2;
    int nSkill = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkill = GetSkillRecord(nSkill);
    if (!pSkill)
        return 2;
    int nLevel = MISSILE_GetLevel(pMissile);
    int nRange = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[0], nSkill, nLevel);
    int nRate = SKILLS_EvaluateSkillFormula(SUNIT_GetOwner(pGame, pMissile), pSkill->dwCalc[1], nSkill, nLevel);
    MISSMODE_CreateMissileWithCollisionCheck(pGame, nRange, pRecord->wSubMissile[0], 0x45, pMissile, nRate);
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AF980
int __fastcall MISSMODE_SrvDo26_Vines_PlagueVines(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] == 0)
    {
        return 2;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    const int nParam = pMissilesTxtRecord->dwParam[0] >= 1 ? pMissilesTxtRecord->dwParam[0] : 1;

    if (!(nFrames % nParam))
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile), pMissilesTxtRecord->wSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AFA30
int __fastcall MISSMODE_SrvDo27_Tornado(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);
    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nParam0 = pMissilesTxtRecord->dwParam[0];
    if (nParam0 <= 0)
    {
        nParam0 = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nParam0 < 1)
        {
            nParam0 = 1;
        }
    }

    if (!(nFrames % nParam0))
    {
        D2DamageStrc damage;
        MISSMODE_FillDamageParams(pGame, pOwner, pMissile, 0, &damage);

        int nParam1 = pMissilesTxtRecord->dwParam[1];
        if (nParam1 <= 0)
        {
            nParam1 = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
            if (nParam1 < 1)
            {
                nParam1 = 1;
            }
        }

        damage.dwHitFlags |= pMissilesTxtRecord->dwHitFlags;
        damage.wResultFlags |= pMissilesTxtRecord->wResultFlags;
        SKILLS_ApplyAreaDamage(pGame, pMissile, 0, 0, nParam1, &damage, pSkillsTxtRecord->dwAuraFilter);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AFB80
int __fastcall MISSMODE_SrvDo28_Volcano(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!(pOwner))
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    int nRange = pMissilesTxtRecord->dwParam[1];
    if (nRange <= 0)
    {
        nRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nRange < 1)
        {
            nRange = 1;
        }
    }

    int nFrequency = pMissilesTxtRecord->dwParam[0];
    if (nFrequency <= 0)
    {
        nFrequency = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nFrequency < 1)
        {
            nFrequency = 1;
        }
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);
    if (nFrames > pMissilesTxtRecord->dwParam[2] && nFrames < pMissilesTxtRecord->dwParam[3] && !(nFrames % nFrequency))
    {
        SEED_InitLowSeed(&pMissile->pSeed, MISSILE_GetTargetX(pMissile));
        nFrequency = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1) - nRange;
        nRange = SEED_RollLimitedRandomNumber(&pMissile->pSeed, 2 * nRange + 1) - nRange;
        int const tArg9 = SEED_GetLowSeed(&pMissile->pSeed);
        MISSILE_SetTargetX(pMissile, tArg9);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x520;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nTargetX = CLIENTS_GetUnitX(pMissile) + nFrequency;
        missileParams.nTargetY = CLIENTS_GetUnitY(pMissile) + nRange;
        missileParams.nGfxArg = pMissilesTxtRecord->dwParam[4];
        missileParams.nSkill = nSkillId;
        missileParams.nSkillLevel = nLevel;
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AFD70
int __fastcall MISSMODE_SrvDo29_RecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }
    {
        const int nLevel = MISSILE_GetLevel(pMissile);
        if (sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
        {
            int nHitpoints = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0) >> 8;
            const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pOwner) >> 8;
            if (nHitpoints < nMaxHp)
            {
                nHitpoints += DATATBLS_ApplyRatio(nMaxHp, SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel), 100);
                if (nHitpoints >= nMaxHp)
                {
                    nHitpoints = nMaxHp;
                }

                STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nHitpoints << 8, 0);

                if (pMissilesTxtRecord->wProgOverlay > 0 && pMissilesTxtRecord->wProgOverlay < sgptDataTables->nOverlayTxtRecordCount)
                {
                    UNITS_SetOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 0);
                }
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005AFEC0
int __fastcall MISSMODE_SrvDo33_VineRecyclerDelay(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner || SUNIT_IsDead(pOwner))
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    const int nLevel = MISSILE_GetLevel(pMissile);
    if (sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
    {
        int nMana = STATLIST_UnitGetStatValue(pOwner, STAT_MANA, 0) >> 8;
        const int nMaxMana = STATLIST_GetMaxManaFromUnit(pOwner) >> 8;
        if (nMana < nMaxMana)
        {
            nMana += DATATBLS_ApplyRatio(nMaxMana, SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[0], nSkillId, nLevel), 100);
            if (nMana >= nMaxMana)
            {
                nMana = nMaxMana;
            }

            STATLIST_SetUnitStat(pOwner, STAT_MANA, nMana << 8, 0);

            if (pMissilesTxtRecord->wProgOverlay > 0 && pMissilesTxtRecord->wProgOverlay < sgptDataTables->nOverlayTxtRecordCount)
            {
                UNITS_SetOverlay(pOwner, pMissilesTxtRecord->wProgOverlay, 0);
            }
        }
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005B0010
int __fastcall MISSMODE_SrvDo30_RabiesPlague(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(MISSILE_GetSkill(pMissile));
    if (!pSkillsTxtRecord)
    {
        return 2;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, MISSILE_GetTargetX(pMissile), MISSILE_GetTargetY(pMissile));
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pTarget || !pOwner || SUNIT_IsDead(pOwner) || MISSILE_GetCurrentFrame(pMissile) < 0)
    {
        MISSMODE_SrvDmgHitHandler(pGame, pMissile, 0, 1);
        return 2;
    }

    MISSMODE_PlacePathAtOwner(pGame, pMissile);

    const int nFrames = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (!(sub_0064A3B0_GetElapsedFrames(pMissile) % nFrames))
    {
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.pOwner = pTarget;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

        const int nRange = pMissilesTxtRecord->dwParam[1];
        missileParams.nTargetX = SEED_RollLimitedRandomNumber(&pTarget->pSeed, 2 * nRange + 1) - nRange;
        missileParams.nTargetY = SEED_RollLimitedRandomNumber(&pTarget->pSeed, 2 * nRange + 1) - nRange;

        D2UnitStrc* pSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
        if (pSkillsTxtRecord->wAuraTargetState > 0)
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pOwner, pSkillsTxtRecord->wAuraTargetState);
            if (pSubMissile && pStatList)
            {
                MISSILE_SetTargetX(pSubMissile, D2COMMON_10473(pStatList));
            }
        }
    }

    MISSMODE_HandleMissileCollision(pGame, pMissile);
    return 1;
}

// 0x005B01F0
int __fastcall MISSMODE_SrvDo31_WakeOfDestructionMaker_BaalColdMaker(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        MISSMODE_SrvDmgHitHandler_005B01F0(pGame, pMissile, 0, 0);
        return 2;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        const int nTargetX = MISSILE_GetMissileTargetStatus(pMissile);
        const int nTargetY = MISSILE_targetValue(pMissile);

        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 2;
        missileParams.pOwner = pOwner;
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        missileParams.nTargetX = nTargetX;
        missileParams.nTargetY = nTargetY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);

        missileParams.nTargetX = -nTargetX;
        missileParams.nTargetY = -nTargetY;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005B03E0
int __fastcall MISSMODE_SrvDo32_TigerFury(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->wSubMissile[0] < 0)
    {
        return 2;
    }

    if (PATH_HasEnteredNewSubtile(pMissile->pDynamicPath))
    {
        D2MissileStrc missileParams = {};
        missileParams.dwFlags = 1;
        missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
        missileParams.pOrigin = pMissile;
        missileParams.nSkill = MISSILE_GetSkill(pMissile);
        missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
        missileParams.nMissile = pMissilesTxtRecord->wSubMissile[0];
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return MISSMODE_SrvDo07_GuidedArrow_BoneSpirit(pGame, pMissile);
}

// 0x005B0640
int __fastcall MISSMODE_SrvDo35_RoyalStrikeChaosIce(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord_005B01F0(pMissile ? pMissile->dwClassId : -1);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nUpdateInterval = pMissilesTxtRecord->dwParam[0] < 1 ? 1 : pMissilesTxtRecord->dwParam[0];
    if (MISSILE_GetRemainingFrames(pMissile) % nUpdateInterval)
    {
        return MISSMODE_HandleMissileCollision(pGame, pMissile);
    }

    D2SeedStrc* pSeed = &pMissile->pSeed;
    if (!pSeed)
    {
        return 2;
    }

    SEED_InitLowSeed(pSeed, MISSILE_GetTargetX(pMissile));

    const unsigned int nPackedOffset = MISSILE_GetTargetY(pMissile);
    const int nPreviousOffsetX = (short)nPackedOffset;
    const int nPreviousOffsetY = (short)(nPackedOffset >> 16);

    int nSignedOffsetX;
    int nSignedOffsetY;
    if (SEED_RollRandomNumber_005B01F0(pSeed) & 1)
    {
        nSignedOffsetX = nPreviousOffsetX;
        nSignedOffsetY = -nPreviousOffsetY;
    }
    else
    {
        nSignedOffsetX = -nPreviousOffsetX;
        nSignedOffsetY = nPreviousOffsetY;
    }

    int nNextOffsetX = (nSignedOffsetY + 4 * nPreviousOffsetX) / 4;
    int nNextOffsetY = (nSignedOffsetX + 4 * nPreviousOffsetY) / 4;
    if (!nNextOffsetX)
    {
        nNextOffsetX = 1;
    }

    if (!nNextOffsetY)
    {
        nNextOffsetY = 1;
    }

    D2COMMON_10170_PathSetTargetPos(pMissile->pDynamicPath, nNextOffsetX + CLIENTS_GetUnitX(pMissile), nNextOffsetY + CLIENTS_GetUnitY(pMissile));
    D2Common_10142(pMissile->pDynamicPath, pMissile, 0);

    MISSILE_SetTargetX(pMissile, SEED_GetLowSeed(pSeed));
    const unsigned short nPackedOffsetX = (unsigned short)nNextOffsetX;
    const unsigned short nPackedOffsetY = (unsigned short)nNextOffsetY;
    MISSILE_SetTargetY(pMissile, nPackedOffsetX + (nPackedOffsetY << 16));

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

static inline unsigned int MISSMODE_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static __forceinline unsigned int MISSMODE_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return MISSMODE_RollRandomNumber(pSeed) % nMax;
    }

    return MISSMODE_RollRandomNumber(pSeed) & (nMax - 1);
}

static __forceinline int MISSMODE_GetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005B04A0
int __fastcall MISSMODE_SrvDo34_BaalTauntControl(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    const int nFrames = sub_0064A3B0_GetElapsedFrames(pMissile);

    int nCounter = 0;
    do
    {
        if (pMissilesTxtRecord->wSubMissile[nCounter] < 0 || pMissilesTxtRecord->dwParam[nCounter + 1] <= 0)
        {
            break;
        }

        ++nCounter;
    }
    while (nCounter < 3);

    if (nCounter <= 0)
    {
        return 2;
    }

    if (nFrames < pMissilesTxtRecord->dwParam[0])
    {
        return MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(pGame, pMissile);
    }

    SEED_InitLowSeed(&pMissile->pSeed, MISSMODE_GetUnitX(pMissile));

    const int nIndex = MISSMODE_RollLimitedRandomNumber(&pMissile->pSeed, nCounter);
    if (nFrames % pMissilesTxtRecord->dwParam[nIndex + 1])
    {
        return MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(pGame, pMissile);
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);
    missileParams.nMissile = pMissilesTxtRecord->wSubMissile[nIndex];

    D2UnitStrc* pSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pSubMissile)
    {
        MISSMODE_SrvDmgHitHandler(pGame, pSubMissile, 0, 1);
    }

    return MISSMODE_SrvDo03_PoisonCloud_Blizzard_ThunderStorm_HandOfGod(pGame, pMissile);
}

// 0x005B07A0
int __fastcall MISSMODE_SrvHit04_ExplodingArrow_FreezingArrow_RoyalStrikeMeteorCenter(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    for (int i = 0; i < 4; ++i)
    {
        if (pMissilesTxtRecord->wHitSubMissile[i] > 0)
        {
            missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[i];

            D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
            if (pHitSubMissile && pMissilesTxtRecord->dwHitPar[0] > 0)
            {
                MISSMODE_SrvDmgHitHandler(pGame, pHitSubMissile, pUnit, 1);
            }
        }
    }

    return 3;
}

// 0x005B0870
int __fastcall MISSMODE_SrvHit11_CreateHitSubmissiles(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 1;
    }

    D2MissileStrc missileParams = {};
    missileParams.pOwner = SUNIT_GetOwner(pGame, pMissile);
    missileParams.pOrigin = pMissile;
    missileParams.nSkill = MISSILE_GetSkill(pMissile);
    missileParams.nSkillLevel = MISSILE_GetLevel(pMissile);

    for (int i = 0; i < 4; ++i)
    {
        if (pMissilesTxtRecord->wHitSubMissile[i] > 0)
        {
            missileParams.nMissile = pMissilesTxtRecord->wHitSubMissile[i];

            D2UnitStrc* pHitSubMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
            if (pHitSubMissile && pMissilesTxtRecord->dwHitPar[0] > 0)
            {
                MISSMODE_SrvDmgHitHandler(pGame, pHitSubMissile, pUnit, 1);
            }
        }
    }

    return 1;
}

// 0x005ADD20
int __fastcall MISSMODE_SrvHit22_FistOfTheHeavensDelay(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pUnit)
{
    D2MissilesTxt* pMissilesTxtRecord = 0;
    if (pMissile)
    {
        pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(pMissile->dwClassId);
    }

    if (!pMissilesTxtRecord || pMissilesTxtRecord->wHitSubMissile[0] < 0)
    {
        return 1;
    }

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
    {
        return 1;
    }

    const int nSkillId = MISSILE_GetSkill(pMissile);
    const int nLevel = MISSILE_GetLevel(pMissile);

    D2SkillsTxt* pSkillsTxtRecord = MISSMODE_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 1;
    }

    pUnit = SUNIT_GetServerUnit(pGame, MISSILE_GetTargetX(pMissile), MISSILE_GetTargetY(pMissile));
    if (!pUnit)
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pMissile);
    const int nY = CLIENTS_GetUnitY(pMissile);

    int nAuraRange = pMissilesTxtRecord->dwHitPar[0];
    if (nAuraRange <= 0)
    {
        nAuraRange = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nLevel);
        if (nAuraRange < 1)
        {
            nAuraRange = 1;
        }
    }

    int nParam = pMissilesTxtRecord->dwHitPar[1];
    if (nParam <= 0)
    {
        nParam = SKILLS_EvaluateSkillFormula(pOwner, pSkillsTxtRecord->dwCalc[3], nSkillId, nLevel);
        if (nParam < 1)
        {
            nParam = 1;
        }
    }

    D2DamageStrc tDamage;
    MISSMODE_FillDamageParams(pGame, pOwner, pMissile, pUnit, &tDamage);
    MISSMODE_ApplyDamageFlagsAndTargetAc(pGame, pMissile, pUnit, &tDamage);

    int nAuraFilter = pSkillsTxtRecord->dwAuraFilter;
    if (!nAuraFilter)
    {
        nAuraFilter = 0xA683;
    }

    D2HitFunc22ParamStrc params;
    params.pOwner = pOwner;
    params.pOrigin = pMissile;
    params.nSkillId = nSkillId;
    params.nLevel = nLevel;
    params.nHitSubMissile = pMissilesTxtRecord->wHitSubMissile[0];
    params.nParam = nParam;

    SKILLS_IterateAuraTargets(pGame, pOwner, nX, nY, nAuraRange, nAuraFilter, MISSMODE_FistOfTheHeavensDelay_AuraCallback, &params, 0, ".\\MISSILES\\MissMode.cpp", 0xF65);
    return 1;
}

static inline int MISSMODE_GetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

// 0x005B0940
int __fastcall MISSMODE_SrvDo19_RadamentDeath(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    const int nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    if (nCurrentFrame > 1 && nCurrentFrame < 25)
    {
        SKILLS_ApplyAreaEffectAtCoordinates(pGame, 0x3002, MISSMODE_GetUnitX(pMissile), MISSMODE_GetUnitY(pMissile), (int)pMissile, 124, 1, (void*)MISSMODE_RadamentDeathAreaEffectCallback);
    }
    else if (nCurrentFrame == 1)
    {
        SKILLS_ApplyAreaEffectAtCoordinates(pGame, 0x3002, MISSMODE_GetUnitX(pMissile), MISSMODE_GetUnitY(pMissile), (int)pMissile, 124, 1, (void*)MISSMODE_RadamentDeathAreaEffectCallbackFirstFrame);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005B0A40
int __fastcall MISSMODE_SrvDo36_BaalFxControl(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    const int nFrame = MISSILE_GetCurrentFrame(pMissile);
    if (!MISSILE_GetTargetX(pMissile) && nFrame <= 100)
    {
        MISSILE_SetTargetX(pMissile, 1);
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pMissile);
        if (QUESTS_CheckNotIntroQuest(pGame, 36))
        {
            ACT5Q6_SpawnTyrael(pGame, pRoom, pMissile);
        }

        DUNGEON_ToggleHasPortalFlag(pRoom, 1);
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005B0AA0
int __fastcall MISSMODE_SrvDo37_CreateTimedSubmissiles(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecordFromUnit(pMissile);
    if (!pMissilesTxtRecord)
    {
        return 2;
    }

    if (pMissilesTxtRecord->wSubMissile[0] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[0])
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile),
                                      pMissilesTxtRecord->wSubMissile[0], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    if (pMissilesTxtRecord->wSubMissile[1] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[1])
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile),
                                      pMissilesTxtRecord->wSubMissile[1], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    if (pMissilesTxtRecord->wSubMissile[2] > 0 && sub_0064A3B0_GetElapsedFrames(pMissile) == pMissilesTxtRecord->dwParam[2])
    {
        D2GAME_CreateMissile_6FD115E0(pGame, SUNIT_GetOwner(pGame, pMissile), MISSILE_GetSkill(pMissile), MISSILE_GetLevel(pMissile),
                                      pMissilesTxtRecord->wSubMissile[2], CLIENTS_GetUnitX(pMissile), CLIENTS_GetUnitY(pMissile));
    }

    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

// 0x005B0BC0
int __fastcall MISSMODE_SrvDo01_BasicMissile(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    return MISSMODE_HandleMissileCollision(pGame, pMissile);
}

struct D2LevelsTxt;

static inline int synh_GetUnitX(SynUnit* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static inline int synh_GetUnitY(SynUnit* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}



// calling-convention shim (not game code)
int __fastcall sub_005ADA80_Shim(D2UnitStrc* pMissile)
{
    return MISSMODE_GetPierceFlags(pMissile);
}

#include "gen/data/Source/D2Game/MISSILES/MissMode.inc"
