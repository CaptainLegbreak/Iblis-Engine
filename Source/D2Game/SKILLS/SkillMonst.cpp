#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2MonModes.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ItemsWorld.h"
#include "D2GameAux.h"
#include "D2LevelTxt.h"
#include "D2GameRecords.h"
#include "D2SkillIds.h"
#include "D2LanguageNames.h"
#include "D2AnimData.h"
// build: symbol _gaszLanguageNames 0x00741A1C

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2StaticPathStrc;

struct D2SkillsTxt;

struct D2MissilesTxt;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2MissileStrc;

struct D2DamageStrc;

enum D2C_M54SkillMonstConstants
{
    PATHTYPE_ASTAR = 1,
    PATHTYPE_TOWARD = 2,
};

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType); // 0x00648CF0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance); // 0x00648E70

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames); // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x005CC440

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170

unsigned short __fastcall SKILLS_SetDamageResultFlagsFromSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame); // 0x006212C0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus); // 0x00622C40

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill); // 0x006444D0

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

int __stdcall SKILLS_GetElementalLength(D2UnitStrc*, int, int, int); // 0x00644F20

void __stdcall UNITS_SetOverlay(D2UnitStrc*, int, int); // 0x00621E40

static int __stdcall SKILLS_UpdateInfernoAnimationParameters(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel);

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId);

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId);


#define UNIT_TYPES 6

#define COLLIDE_MASK_PLAYER_PATH 0x1C09

union D2SeedStrc;

struct D2ModeChangeStrc;

int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit); // 0x00625D10

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60

int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005CC960

int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int a2); // 0x005FD7B0

int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit); // 0x0063A320

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster); // 0x0063EA40

extern "C" void __stdcall PATH_SetPathTarget(D2DynamicPathStrc* pPath, D2UnitStrc* pTargetUnit); // 0x00648B90

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit); // 0x00649180

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc*, int);

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

struct D2ActiveRoomStrc;

struct D2UnkCallRecordStrc;

struct D2MonsterRegionStrc;

struct D2MonsterDataStrc;

struct D2CurseStrc;

struct D2AuraCallbackStrc;

struct D2StaticFieldCallbackArgStrc;

struct D2BasicAuraParamStrc;

struct D2DamageAuraParamStrc;

struct D2UnkPalSkillStrc2;

struct D2AiCmdStrc;

struct D2DifficultyLevelsTxt;

enum D2C_F39Constants
{
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_WILLDIE = 2,
    SKILLSFLAGINDEX_01 = 1,
    UNITFLAG_NOTC = 0x20000,
    EVENTTYPE_ENDANIM = 1,
    STATLIST_FLAG_8 = 8,
};

typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

extern unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00552FD0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit); // 0x00554010

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3); // 0x005543B0

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x00554200

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2); // 0x00554DE0

int __fastcall SKILLS_ApplyAuraToSelf(void* pArg1, void* pArg2, int (__fastcall* pfnCallback)(D2UnkCallRecordStrc*), int nArg4); // 0x0056B740

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0

void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0

int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50

int __fastcall SKILLS_IsMissileTargetPositionClear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x0056E450

D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse); // 0x0056E970

int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110

D2UnitFindDataStrc* __fastcall SKILLS_AllocUnitSearch(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY); // 0x0056C210

D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056ECB0

int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420

void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4); // 0x005C0B50

void __fastcall SKILLS_ApplyPassiveStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0

int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget); // 0x0057D690

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int nFlags); // 0x0057DBF0

void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E270

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

int __fastcall MONSTERSPAWN_SpawnBonePrison(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7); // 0x005B34C0

int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0

void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug); // 0x00545CD0

void __fastcall MONSTERREGION_UndoMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit); // 0x00547E90

void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* pUnit, int a2); // 0x005544B0

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00573780

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730

int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005CCC80

void __fastcall SKILLS_AttachImpToMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D18E0

void __fastcall SKILLS_DetachImpFromMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel); // 0x005D19D0

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty); // 0x00611D30

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY); // 0x00621DC0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag); // 0x00625760

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

void __stdcall INVENTORY_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY); // 0x0063E7E0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue); // 0x00644620

int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill); // 0x00644500

int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill); // 0x00644530

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask); // 0x00648C30

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc* pPath); // 0x006505C0

int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0

int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005CEDC0

int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit); // 0x005D0D70

int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender); // 0x005C96A0

void __fastcall D2GAME_RefreshPassiveSkills_6FD14CC0(D2UnitStrc* pUnit); // 0x0056DFA0

void __fastcall SKILLS_ClampVitalsAndUpdateAnimRate(D2UnitStrc* pUnit); // 0x0056B6C0

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

void __fastcall SKILLS_MissileInit_DiabWall(D2UnitStrc* pMissile, int nInitSeed);                           // 0x005CD110

struct D2GfxLightStrc;

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit);                                        // 0x004639D0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820

int __fastcall CUNIT_IsHostileTo(D2UnitStrc* pUnit, D2UnitStrc* pOther);                           // 0x00465C60

void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390

void __fastcall GFX_RefreshPathTarget(D2UnitStrc* pUnit);                                          // 0x00480420

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY);                         // 0x004C52E0

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

void __fastcall MISSILE_CltDoDefault(D2UnitStrc* pMissile);                                            // 0x004CD390

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams);                          // 0x004CD540

void __fastcall MISSILE_CltDoCommon(D2UnitStrc* pMissile);                                             // 0x004D30C0

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg);                                // 0x004E2ED0

int __fastcall SKILLDESC_GetCltMissileId(D2UnitStrc* pUnit, int nSkillId);                               // 0x004F21B0

int __cdecl D2GFX_IsHardwareRenderMode();                                                                 // 0x004F51C0

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther);                         // 0x006416D0

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0

int __stdcall sub_0064A3B0_GetElapsedFrames(D2UnitStrc* pMissile);                                          // 0x0064A3B0

int __stdcall MISSILE_GetTargetX(D2UnitStrc* pMissile);                                                     // 0x0064A730

D2UnitStrc* __fastcall sub_0059FA30(D2GameStrc*,D2MissileStrc*);  // 0x0059FA30

extern const int gnPrimePoisonNovaY[16]; // 0x006E31A8

extern const int gnPrimePoisonNovaX[16]; // 0x006E31E8

typedef char chk_D2SkillsTxt_size[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

#define STATEMASK_REMHIT 6

#define UNITFLAG_SKSRVDOFUNC 0x40

#define AISPECIALSTATE_NONE 0

#define SKILLDRUID_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2SummonArgStrc;

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0

void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nState, int a3); // 0x0056C740

void __fastcall SKILLS_ApplySkillDelay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056F020

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __fastcall SKILLS_RemoveStateAndRestoreSkillMode(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList); // 0x005C6C50

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

extern "C" void __stdcall STATLIST_SetListExpireFrame(D2StatListStrc* pStatList, int nValue); // 0x006260B0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

int __stdcall SKILLS_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel); // 0x005C7B10

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

void __fastcall SUNITMSG_QueueSkillEvent(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0

enum
{
    EVENTTYPE_ACTIVESTATE = 5,
    EVENTTYPE_REMOVESTATE = 12,
};

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nMask); // 0x00645950

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30


enum D2C_Z09SkillConstants
{
    UNITFLAG_TARGETFLAGS = 0x0E,
    AISPECIALSTATE_MOUNTING_UNIT = 0x10,
    PATHTYPE_BLESSEDHAMMER = 0x0E,
    PATHTYPE_KNOCKBACK_SERVER = 0x08,
    PATHTYPE_LEAP = 0x09,
    PATHTYPE_MON_OTHER_2 = 0x65,
};

int __fastcall SKILLS_EvaluateProgressiveSkillCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);       // 0x005D3DA0

void __fastcall SKILLS_CreateMissileRing(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOrigin, int nMissileId, int nSkillId, int nSkillLevel, int nVelocity); // 0x0056D400

int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290

int __fastcall SKILLS_CreateMissilesAroundTarget(D2GameStrc* pGame, D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nMissileId, int nCalc, int nRange, int nSkillId, int nSkillLevel); // 0x005D5BF0

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender); // 0x0057C9F0

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit);                                                             // 0x00463860

int __fastcall CUNIT_ValidateMonsterId(int nMonsterId);                                             // 0x00463900

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0

void __fastcall AITHINK_ExecuteAiFn(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiControlStrc* pAiControl, int nAiSpecialState); // 0x005B0E00

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit);                                            // 0x00621F20

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit);                              // 0x00541860

void __fastcall SUNIT_RewindAnimationByFrames(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x00553C70

int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId);                          // 0x006461D0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps);                      // 0x00649070

int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit);                                                             // 0x0056E5B0

void __fastcall SKILLS_SetElementalDurationFromSkill(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId);         // 0x0056C840

#define HIT_SUCCESS 1

#define HIT_FLAG 2

#define SOURCE_DAMAGE 128

void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0


int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8CA0

void __fastcall SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C8BF0

void __fastcall SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C9420

void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc);             // 0x0063BDE0

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType);                                      // 0x00629BB0

int __fastcall SKILLS_SrvDo034_TigerStrike_CobraStrike_RoyalStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D3490

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                    // 0x006442A0

int __fastcall SKILLDESC_GetSkillParamByLevel(int nSkillId, int nSkillLevel);                           // 0x004E6CA0

int __stdcall STATES_CheckStateMaskRemHitOnUnit(D2UnitStrc* pUnit);                                         // 0x0063A360

unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc* pUnit);                              // 0x0063A100

int __stdcall sub_004111A0_GetLowestSetBit(unsigned int nValue);                                                  // 0x004111A0

unsigned short __fastcall SKILLS_SetDamageResultFlags(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned short wResultFlags, int a5, D2DamageStrc* pDamage, int a7); // 0x0056E6F0

D2UnitStrc* __fastcall SKILLS_FindNextAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, int a7, int* a8); // 0x0056BD10

int __fastcall SKILLS_Callback_FindTargetForTaunt(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005D8510

D2UnitStrc* __fastcall SKILLS_FindAuraTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nAuraRange, int (__fastcall* pCallback)(D2GameStrc*, D2UnitStrc*)); // 0x0056BBC0

int __fastcall SKILLS_AuraCallback_ApplyCurse(D2UnitStrc* pUnit, D2UnkNecSkillStrc* pArgs); // 0x005C35C0

void __fastcall AITHINK_SetAiControlParams(D2AiControlStrc* pAiControl, int nParam0, int nParam1, int nParam2); // 0x005B0D70

void __fastcall AIUTIL_SetOwnerGUIDAndType(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                          // 0x005DD330

void __fastcall SUNITMSG_QueueSkillStop(D2UnitStrc* pUnit, int nSkillId);                                  // 0x00571B70

void __stdcall UNITFINDS_InitializeUnitFindData(void* pMemPool, D2UnitFindDataStrc* pUnitFindData, D2ActiveRoomStrc* pRoom, int nX, int nY, int nSize, void* pfnUnitTest, D2UnitFindArgStrc* pUnitFindArg); // 0x0065A950

int __stdcall UNITFINDS_FindAllMatchingUnitsInNeighboredRooms(D2UnitFindDataStrc* pUnitFindData); // 0x0065AC70

void __stdcall UNITFINDS_FreeUnitFindData(D2UnitFindDataStrc* pUnitFindData);                               // 0x0065AA00

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560

int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420

extern const int gnHydraOffsetX[]; // 0x006E312C

extern const int gnHydraOffsetY[]; // 0x006E3120

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __fastcall SUNIT_TeleportUnit(Game*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0

enum { UNIT_FLAGS = 0xE };

struct Monster;

enum D2C_Y09ImpInfernoConstants
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_AITHINK = 2,
};

struct Game
{
    unsigned char pad[28];
    void* pool;
};



extern "C" int __stdcall sub_00646CA0_Evaluate(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0

struct D2PlayerDataStrc;

int __fastcall AIUTIL_GetDistanceToCoordinates_FullUnitSize(D2UnitStrc*, D2UnitStrc*); // 0x005DC380

int __fastcall AIUTIL_HasClearApproachToTarget(D2UnitStrc*, D2UnitStrc*); // 0x005DC640

D2UnitStrc* __fastcall sub_6FCF2110(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*); // 0x005DD7F0

D2UnitStrc* __fastcall AITACTICS_FindTargetInRange(D2GameStrc*, D2UnitStrc*, D2AiControlStrc*, int*, int*, int); // 0x005DDE50

int __fastcall AITACTICS_ChangeModeAndTargetUnit(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*); // 0x005DDF90

void __fastcall AITACTICS_IdleInNeutralMode(D2GameStrc*, D2UnitStrc*, int); // 0x005DE080

void __fastcall AITACTICS_SetAiParam(D2UnitStrc* pUnit, int nParam, int nValue, int nArg); // 0x005DE190

int __fastcall AITACTICS_WalkToTargetWithPathType13(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DED40

int __fastcall AITACTICS_WanderToTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned char nMaxDistance); // 0x005DF400

int __fastcall D2GAME_AI_PetMove_6FCE2BA0(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3EA0

int __fastcall AITHINK_TryPetFollowOwner(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, D2UnitStrc*, int, D2AiTickParamStrc*, int, int); // 0x005E45D0

int __fastcall sub_00472210_SeedRollMasked(D2SeedStrc*, int); // 0x00472210

D2AiCmdStrc* __fastcall AIGENERAL_GetCurrentAiCommandFromUnit(D2UnitStrc*); // 0x0058EE80

D2UnitStrc* __fastcall AIUTIL_SelectAiTargetWithCollisionCheck(D2GameStrc*, D2UnitStrc*, unsigned int*, int*); // 0x005DDC30

int __fastcall AITACTICS_WalkCloseToUnit(D2GameStrc*, D2UnitStrc*, unsigned char); // 0x005DE200

int __fastcall AITACTICS_WalkToTargetCoordinates(D2GameStrc*, D2UnitStrc*, int, int); // 0x005DED90

int __fastcall AITACTICS_WalkAwayFromTarget(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char, int); // 0x005DEFE0

int __fastcall D2GAME_AICORE_WalkToOwner_6FCD0B60(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x005DF530

int __fastcall AITHINK_PetMove(D2GameStrc*, D2UnitStrc*, D2UnitStrc*, int, int, int, int); // 0x005E3930

void __fastcall AITHINK_HirelingCombat(D2GameStrc*, D2UnitStrc*, int, D2UnitStrc*, D2UnitStrc*, D2SeedStrc*, D2AiTickParamStrc*); // 0x005E5050

int __stdcall D2Common_10095(D2ActiveRoomStrc*, int, int); // 0x0061B130

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc*); // 0x006221A0

int __stdcall PATH_GetFinalTargetX(D2DynamicPathStrc*); // 0x00648A20

int __stdcall PATH_GetFinalTargetY(D2DynamicPathStrc*); // 0x00648A30

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

__forceinline int UNITS_GetUnitXPositionInline(D2UnitStrc* pUnit)
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

__forceinline int UNITS_GetUnitYPositionInline(D2UnitStrc* pUnit)
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

int __fastcall SKILLS_StartSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int a5);   // 0x0056F640

// 0x005CAE40
int __fastcall SKILLS_SrvSt42_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (!pUnit || pUnit->dwUnitType != UNIT_PLAYER)
    {
        D2DamageStrc damage;
        memset(&damage, 0, sizeof(damage));
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
        if (damage.wResultFlags & 1)
        {
            damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
            damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
            if (pSkillsTxtRecord->dwHitClass)
            {
                damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
            }

            sub_6FC627B0(pUnit, 8);
        }

        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);

        return 1;
    }

    return SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(pGame, pUnit, nSkillId, nSkillLevel);
}

// 0x005CAF30
int __fastcall SKILLS_SrvDo083_FireHit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    SUNITDMG_FreeAttackerDefenderCombatList(pGame, pUnit, pTarget);
    return SKILLS_StartSkill(pGame, pUnit, nSkillId, nSkillLevel, 0);
}

// 0x005CAF80
int __fastcall SKILLS_SrvSt43_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    PATH_SetUnitDeadCollision(pUnit, 1);
    return 1;
}

// 0x005CAFA0
int __fastcall SKILLS_SrvDo084_MaggotEgg(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 1, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    if (!UNITS_GetUsedSkill(pUnit))
    {
        return 0;
    }

    pUnit->dwSeqSpeed = 0;

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount > 0)
    {
        int nCounter1 = 0;
        D2UnitStrc* pSummon = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nSummonId, nSpawnMode, -1, 0);
        if (pSummon)
        {
            nCounter1 = 1;
            pSummon->dwFlags |= UNITFLAG_NOXP;
        }

        int nCounter2 = 1;
        for (int i = 0; nCounter1 < nCount; i += 1)
        {
            if (nCounter2 >= 5 || i >= 2 * nCount)
            {
                break;
            }

            pSummon = MONSTERSPAWN_SpawnAtUnit(pGame, pUnit, nSummonId, MONMODE_SKILL1, nCounter2, 0);
            if (pSummon)
            {
                pSummon->dwFlags |= UNITFLAG_NOXP;
                nCounter1 += 1;
            }
            else
            {
                nCounter2 += 1;
            }
        }
    }

    SUNITDMG_KillMonster(pGame, pUnit, pUnit, 1);
    return 1;
}

// 0x005CB0C0
int __fastcall SKILLS_SrvDo085_UnholyBolt_ShamanFire(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    int nMissileOffset;
    DATATBLS_GetMonsterChainInfo(nClassId, 0, &nMissileOffset);
    nMissileId += nMissileOffset;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    return 1;
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

// 0x005CB170
int __fastcall SKILLS_SrvSt44_MaggotUp(Game* game,D2UnitStrc* unit,int skillId,int level)
{
    if(!SUNIT_TeleportUnit(game,unit,UNITS_GetRoom(unit),UNITS_GetUnitXPosition(unit),UNITS_GetUnitYPosition(unit),0,0)) return 0;
    unit->dwFlags |= UNIT_FLAGS;
    COLLISION_SetMaskWithPattern(UNITS_GetRoom(unit),UNITS_GetUnitXPosition(unit),UNITS_GetUnitYPosition(unit),1,0x1000);
    return 1;
}

// 0x005CB270
int __fastcall SKILLS_SrvSt45_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), UNITS_GetUnitXPositionInline(pUnit), UNITS_GetUnitYPositionInline(pUnit), 5, 0x1000);
    return 1;
}

// 0x005CB300
int __fastcall SKILLS_SrvDo086_MaggotDown(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    const int nPercentage = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nPercentage > 0)
    {
        int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
        const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pUnit);
        nHitpoints += DATATBLS_ApplyRatio(nHitpoints, nPercentage, 100);
        if (nHitpoints >= nMaxHp)
        {
            nHitpoints = nMaxHp;
        }

        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    }

    return 1;
}

// 0x005CB3C0
int __fastcall SKILLS_SrvDo087_MaggotLay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 1, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const unsigned char nDirection = UNITS_GetDirectionToCoords(pUnit, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
    const int nIndex = INVENTORY_GetEightWayDirection(nDirection) % 8;

    int nOffsetX;
    int nOffsetY;
// build: symbol ?gnMaggotLayDirections@* 0x006E3138
    INVENTORY_GetDirectionDelta(gnMaggotLayDirections[(unsigned char)nIndex], &nOffsetX, &nOffsetY);

    const int nX = CLIENTS_GetUnitX(pUnit) + nOffsetX;
    const int nY = CLIENTS_GetUnitY(pUnit) + nOffsetY;
    pUnit->nActionFrame = 0;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2UnitStrc* pSummon = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nSummonId, nSpawnMode, -1, 0);
    if (!pSummon)
    {
        return 0;
    }

    pSummon->dwFlags |= UNITFLAG_NOXP;
    return 1;
}

// 0x005CB4D0
int __fastcall SKILLS_SrvSt46_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, UNITS_GetUnitXPositionInline(pTarget));
    SKILLS_SetParam2(pSkill, UNITS_GetUnitYPositionInline(pTarget));
    return 1;
}

// 0x005CB580
int __fastcall SKILLS_SrvDo088_AndrialSpray(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam1(pSkill);
    int nY = SKILLS_GetParam2(pSkill);
    if (!nX || !nY)
    {
        if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
        {
            return 0;
        }
    }

    unsigned char nDirection = UNITS_GetDirectionToCoords(pUnit, nX, nY);
    const unsigned char nIndex = INVENTORY_GetEightWayDirection(nDirection) & 7;

    nX = CLIENTS_GetUnitX(pUnit);
    nY = CLIENTS_GetUnitY(pUnit);

    int nOffsetX;
    int nOffsetY;
// build: symbol ?gnAndrialSprayDirections@* 0x006E3188
    INVENTORY_GetDirectionDelta(gnAndrialSprayDirections[nIndex], &nOffsetX, &nOffsetY);
    nX += nOffsetX;
    nY += nOffsetY;

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    nFrame -= 4;
    const int nClampedFrame = nFrame > 0 ? nFrame : 0;
    nFrame = nClampedFrame < 8 ? nClampedFrame : 8;

// build: symbol ?gnAndrialSprayOffsets@* 0x006E3140
    const unsigned char nSprayDirection = gnAndrialSprayOffsets[9 * nIndex + nFrame];
    if (nSprayDirection != 99)
    {
        INVENTORY_GetDirectionDelta(nSprayDirection, &nOffsetX, &nOffsetY);
        nX += nOffsetX;
        nY += nOffsetY;
    }

    D2MissileStrc missileParams = {};
    missileParams.nTargetX = nX;
    missileParams.nTargetY = nY;
    missileParams.dwFlags = 0x20;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
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

// 0x005CB730
int __fastcall SKILLS_SrvSt47_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord_Inline(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_FREEZE))
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nX;
    int nY;
    if (!pTarget)
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
        SKILLS_SetParam4(pSkill, -1);
    }
    else
    {
        const int nTargetX = CLIENTS_GetUnitX(pTarget);
        const int nTargetY = CLIENTS_GetUnitY(pTarget);
        nX = 2 * nTargetX - CLIENTS_GetUnitX(pUnit);
        nY = 2 * nTargetY - CLIENTS_GetUnitY(pUnit);
    }

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    if (pTarget)
    {
        D2DamageStrc damage = {};
        damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
        if (damage.wResultFlags & 1)
        {
            damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
            damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
            if (pSkillsTxtRecord->dwHitClass)
            {
                damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
            }
            damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
            D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        }

        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
        SKILLS_SetParam3(pSkill, !pTarget ? 6 : pTarget->dwUnitType);
        SKILLS_SetParam4(pSkill, !pTarget ? -1 : pTarget->dwUnitId);
    }
    else
    {
        SKILLS_SetParam4(pSkill, -1);
    }

    COLLISION_SetMaskWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
    SUNIT_SetUninterruptable(pUnit, 1);
    SKILLS_SetParam1(pSkill, nX);
    SKILLS_SetParam2(pSkill, nY);
    SKILLS_SetFlags(pSkill, 0x80);
    return 1;
}

inline int SKILLS_IsValidPetType(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

// 0x005CB940
int __fastcall SKILLS_SrvDo089_Jump(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);

    if (pUnit->nActionFrame == 2)
    {
        pUnit->nActionFrame = 0;

        D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam4(pSkill));
        if (pTarget)
        {
            SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
        }

        return 1;
    }

    const int nSkillFlags = SKILLS_GetFlags(pSkill);
    const int nX = SKILLS_GetParam1(pSkill);
    const int nY = SKILLS_GetParam2(pSkill);
    if (nSkillFlags & 0x100)
    {
        if (CLIENTS_GetUnitX(pUnit) == nX && CLIENTS_GetUnitY(pUnit) == nY)
        {
            SKILLS_SetFlags(pSkill, 0);
            SUNIT_SetUninterruptable(pUnit, 0);
            COLLISION_ResetMaskWithPattern(UNITS_GetRoom(pUnit), nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x100);
            PATH_SetFootprintCollisionMask(pPath, 0x100);
            PATH_SetMoveTestCollisionMask(pPath, 0x3C01);
            PATH_SetType(pPath, PATHTYPE_MON_OTHER_2);

            if (CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit)) == MONSTER_SANDLEAPER1)
            {
                D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam4(pSkill));
                if (pTarget)
                {
                    SKILLS_SetFlags(pSkill, 1);
                    UNITS_SetAnimationFrame(pUnit, 12);
                    pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
                    PATH_RecacheRoomIfNeeded(pPath);
                    PATH_SetNewDistance(pPath, 5);
                    PATH_SetStepNum(pPath, 1);
                    PATH_SetTargetUnit(pPath, 0);
                    const int nTargetX = 3 * nX - 2 * CLIENTS_GetUnitX(pTarget);
                    const int nTargetY = 3 * nY - 2 * CLIENTS_GetUnitY(pTarget);
                    D2COMMON_10170_PathSetTargetPos(pPath, nTargetX, nTargetY);
                    PATH_SetType(pPath, PATHTYPE_KNOCKBACK_SERVER);
                    D2COMMON_10190_PATH_SetDistance(pPath, 5);
                    D2Common_10142(pPath, pUnit, 0);
                }
            }
        }
        else
        {
            int nFrame = 0;
            if (CUNIT_ValidateMonsterId(CUNIT_GetMonsterBaseId(pUnit)) == MONSTER_SANDLEAPER1)
            {
                nFrame = 8;
            }

            UNITS_SetAnimationFrame(pUnit, nFrame);
            pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
        }

        return 1;
    }

    if (nSkillFlags & 0x80)
    {
        SKILLS_SetFlags(pSkill, 0x101);
        PATH_SetMoveTestCollisionMask(pPath, 0);
        PATH_SetFootprintCollisionMask(pPath, 0);
        D2COMMON_10170_PathSetTargetPos(pPath, nX, nY);
        PATH_SetType(pPath, PATHTYPE_LEAP);
        PATH_SetVelocity(pPath, SKILLS_GetBaseWalkVelocity(pUnit), ".\\SKILLS\\SkillMonst.cpp", 0x282);
        D2Common_10142(pPath, pUnit, 0);
    }
    else
    {
        SKILLS_SetFlags(pSkill, 0);
    }

    return 1;
}

// 0x005CBBF0
int __fastcall SKILLS_SrvSt48_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    D2DynamicPathStrc* pDynamicPath = pUnit->pDynamicPath;
    if (!pDynamicPath)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    PATH_SetNewDistance(pDynamicPath, 5);

    PATH_SetType(pDynamicPath, PATHTYPE_TOWARD);
    D2Common_10142(pDynamicPath, pUnit, 0);
    if (!PATH_GetNumberOfPathPoints(pDynamicPath))
    {
        PATH_SetType(pDynamicPath, PATHTYPE_ASTAR);
        D2Common_10142(pDynamicPath, pUnit, 0);
        if (!PATH_GetNumberOfPathPoints(pDynamicPath))
        {
            return 0;
        }
    }

    SKILLS_SetFlags(pSkill, 1);
    return 1;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005CBC80
int __fastcall SKILLS_SrvDo090_SwarmMove(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel));
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

inline unsigned char UNITS_GetMonsterComponent(D2UnitStrc* pUnit, int nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[nComponent];
    }

    return 0;
}

// 0x005CBD10
int __fastcall SKILLS_SrvSt49_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nSpawnMode;
    int nX;
    int nY;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 1, nSkillId, nSkillLevel, &nSpawnMode, &nX, &nY);
    if (nSummonId < 0)
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, nSummonId);
    SKILLS_SetParam2(pSkill, nX);
    SKILLS_SetParam3(pSkill, nY);
    SKILLS_SetParam4(pSkill, nSpawnMode);

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, 1, 0x100);
    SUNIT_SetUninterruptable(pUnit, 1);
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
    return 1;
}

// 0x005CBE00
int __fastcall SKILLS_SrvDo091_Nest_EvilHutSpawner(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
    SUNIT_SetUninterruptable(pUnit, 0);
    const int nMonsterId = SKILLS_GetParam1(pSkill);
    const int nX = SKILLS_GetParam2(pSkill);
    const int nY = SKILLS_GetParam3(pSkill);
    const int nAnimMode = SKILLS_GetParam4(pSkill);

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    if (!pRoom || !nX || !nY)
    {
        return 0;
    }

    COLLISION_ResetMaskWithPattern(pRoom, nX, nY, 1, 0x100);

    D2UnitStrc* pSummon = D2GAME_SpawnMonster_6FC69F10(pGame, pRoom, nX, nY, nMonsterId, nAnimMode, 1, 0);
    if (!pSummon)
    {
        return 0;
    }

    pSummon->dwFlags |= UNITFLAG_NOXP | UNITFLAG_NOTC;

    if (pSkillsTxtRecord->wSumOverlay >= 0 && pSkillsTxtRecord->wSumOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pSummon, pSkillsTxtRecord->wSumOverlay, 0);
    }

    return 1;
}

// 0x005CBF30
int __fastcall SKILLS_SrvSt50_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0x00, sizeof(damage));
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    return 1;
}

// 0x005CBF90
int __fastcall SKILLS_SrvDo092_QuickStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    SUNITDMG_FreeAttackerDefenderCombatList(pGame, pUnit, pTarget);

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0)
    {
        if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        {
            nMissileId = D2Common_11050(pUnit, 1);
        }

        if (nMissileId < 0)
        {
            return 0;
        }
    }

    if (nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 1);
        return 1;
    }

    return 0;
}

static inline D2SkillsTxt* GetSkillsTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nId];
    return 0;
}

static int SKILLS_Abs(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x005CC050
int __fastcall SKILLS_SrvDo093_GargoyleTrap(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
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
    const int nTargetX = CLIENTS_GetUnitX(pTarget);
    const int nTargetY = CLIENTS_GetUnitY(pTarget);
    const int nUnitX = CLIENTS_GetUnitX(pUnit);
    const int nUnitY = CLIENTS_GetUnitY(pUnit);

    int nY = nTargetY;
    int nX = nTargetX;
    int i = 4;
    if (SKILLS_Abs(nTargetX - nUnitX) < SKILLS_Abs(nTargetY - nUnitY))
    {
        nX = nUnitX;
        do
        {
            if (nX > nTargetX)
            {
                --nX;
            }
            else if (nX < nTargetX)
            {
                ++nX;
            }
        }
        while (--i > 0);
    }
    else
    {
        nY = nUnitY;
        do
        {
            if (nY > nTargetY)
            {
                --nY;
            }
            else if (nY < nTargetY)
            {
                ++nY;
            }
        }
        while (--i > 0);
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    const int nDX = nX - nUnitX;
    const int nDY = nY - nUnitY;
    missileParams.nX = nUnitX + nDX / 6 - 1;
    missileParams.nY = nUnitY + nDY / 6 - 1;
    missileParams.nSkill = nSkillId;
    missileParams.dwFlags = 3;
    missileParams.nTargetX = nDX;
    missileParams.nTargetY = nDY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return 1;
}

// 0x005CC1D0
int __fastcall SKILLS_SrvSt51_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags &= 0xFFFFFFF1;
    }

    return 1;
}

// 0x005CC1F0
int __fastcall SKILLS_SrvDo094_Submerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;

    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

// 0x005CC220
int __fastcall SKILLS_SrvSt52_Emerge(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (pUnit)
    {
        pUnit->dwFlags |= 0x0E;
    }
    return 1;
}

// 0x005CC240
int __fastcall SKILLS_SrvSt53_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nDelay = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nDelay < 1)
    {
        nDelay = 1;
    }

    SKILLS_SetParam1(pSkill, nDelay + pGame->dwGameFrame);

    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 1);
    }

    return 1;
}

// 0x005CC2E0
static int __stdcall SKILLS_UpdateInfernoAnimationParameters(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(!pMissile ? -1 : pMissile->dwClassId);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    int nFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nFrame <= 0)
    {
        nFrame = pMissilesTxtRecord->dwParam[1] + nSkillLevel - 1;
    }

    nFrame = D2_MIN(D2_MAX(nFrame, 1), 0xFF);
    PATH_SetNewDistance(pMissile->pDynamicPath, nFrame);
    sub_00621780_SetMissileArg(pMissile, (pMissilesTxtRecord->nAnimLen << 8) / nFrame);
    MISSILE_SetTotalFrames(pMissile, nFrame);
    MISSILE_SetCurrentFrame(pMissile, nFrame);
    return 1;
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

__forceinline D2MonStats2Txt* MONSTERREGION_GetMonStats2TxtRecord(int nMonsterId)
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

// 0x005CC3B0
static int SKILLS_ScheduleInfernoEndAnim(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nAnimLength = 11;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            nAnimLength = pMonStats2TxtRecord->nInfernoLen;
        }
    }

    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
    EVENT_SetEvent(pGame, pUnit, 1, pGame->dwGameFrame + nAnimLength, 0, 0);
    return 1;
}

// 0x005CC440
void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType == UNIT_MONSTER)
    {
        D2MonStats2Txt* pMonStats2TxtRecord = MONSTERREGION_GetMonStats2TxtRecord(pUnit->dwClassId);
        if (pMonStats2TxtRecord)
        {
            if (pSkillsTxtRecord->nMonAnim == MONMODE_SEQUENCE)
            {
                UNITS_SetAnimationFrame(pUnit, pMonStats2TxtRecord->nInfernoAnim - 1);
                pUnit->dwFrameCountPrecise = (pMonStats2TxtRecord->nInfernoAnim + 1) << 8;
            }
            else
            {
                pUnit->nSeqCurrentFramePrecise = pMonStats2TxtRecord->nInfernoAnim << 8;
            }
        }
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, 8);
        pUnit->dwFrameCountPrecise = 0x500;
    }
}

// 0x005CC4E0
int __fastcall SKILLS_SrvDo095_MonInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(nMissile);
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x25;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissile;
    missileParams.nVelocity = pMissilesTxtRecord->nVel + nSkillLevel * pMissilesTxtRecord->nVelLev / 8;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        SKILLS_ScheduleInfernoEndAnim(pGame, pUnit);
        return 0;
    }

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        SKILLS_ScheduleInfernoEndAnim(pGame, pUnit);
        return 0;
    }

    SKILLS_UpdateInfernoAnimationParameters(pUnit, pMissile, nSkillId, nSkillLevel);
    SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);

    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, STATE_INFERNO))
    {
        int nAnimLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        if (nAnimLength < 1)
        {
            nAnimLength = 1;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + nAnimLength, 0, 0);
    }
    else
    {
        SKILLS_ScheduleInfernoEndAnim(pGame, pUnit);
    }

    return 1;
}

// 0x005CC690
int __fastcall SKILLS_SrvDo152_DiabLight(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(nMissile);
    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x25;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissile;
    missileParams.nVelocity = pMissilesTxtRecord->nVel + nSkillLevel * pMissilesTxtRecord->nVelLev / 8;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        SKILLS_ScheduleInfernoEndAnim(pGame, pUnit);
        return 0;
    }

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        SKILLS_ScheduleInfernoEndAnim(pGame, pUnit);
        return 0;
    }

    SKILLS_UpdateInfernoAnimationParameters(pUnit, pMissile, nSkillId, nSkillLevel);
    SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);

    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, STATE_INFERNO))
    {
        int nAnimLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        if (nAnimLength < 1)
        {
            nAnimLength = 1;
        }

        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 1, 0);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
        EVENT_SetEvent(pGame, pUnit, 0, pGame->dwGameFrame + nAnimLength, 0, 0);
    }
    else
    {
        SKILLS_ScheduleInfernoEndAnim(pGame, pUnit);
    }

    return 1;
}

// 0x005CC840
int __fastcall SKILLS_SrvDo096_ZakarumHeal_Bestow(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nMaxRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    const int nMax = D2_MIN(D2_MAX(nMaxRaw, 0), 100);

    const int nMinRaw = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    const int nMin = D2_MIN(D2_MAX(nMinRaw, 0), nMax);

    const int nPercentage = ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, nMax - nMin) + nMin;
    const int nMaxHp = STATLIST_GetMaxLifeFromUnit(pTarget);
    int nNewHp = DATATBLS_ApplyRatio(nMaxHp, nPercentage, 100) + STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0);
    nNewHp = D2_MIN(D2_MAX(nNewHp, 1), nMaxHp);
    STATLIST_SetUnitStat(pTarget, STAT_HITPOINTS, nNewHp, 0);
    return 1;
}

// 0x005CC960
int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nMaxHp = STATLIST_UnitGetStatValue(pUnit, STAT_MAXHP, 0);
    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nMaxHp, 0);

    if (pUnit)
    {
        pUnit->dwFlags |= 0xE;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        pUnit->dwFlags |= UNITFLAG_NOXP | UNITFLAG_NOTC;
        MONSTER_UpdateAiCallbackEvent(pGame, pUnit);
        MONSTERREGION_UndoMonsterKill(pGame->pMonReg, pUnit);
        QUESTS_AttachLevelChainRecord(pGame, pUnit, pRoom, 0);
        PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x100);
        D2Common_10214(pUnit);
        COLLISION_SetMaskWithPattern(pRoom, UNITS_GetUnitXPositionInline(pUnit), UNITS_GetUnitYPositionInline(pUnit), PATH_GetUnitCollisionPattern(pUnit), 0x100);
    }
    else
    {
        PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x80);
        D2Common_10214(pUnit);
        COLLISION_SetMaskWithPattern(pRoom, UNITS_GetUnitXPositionInline(pUnit), UNITS_GetUnitYPositionInline(pUnit), PATH_GetUnitCollisionPattern(pUnit), 0x80);
    }

    return 1;
}

// 0x005CCB10
int __fastcall SKILLS_SrvDo097_Resurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (!MONSTERS_IsDead(pTarget) || STATES_CheckStateMaskHideOnUnit(pTarget))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pTarget);
    const int nY = CLIENTS_GetUnitY(pTarget);
    const int nUnitType = pTarget->dwUnitType;
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (!pRoom)
    {
        return 0;
    }

    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pTarget);
    if (COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, nCollisionPattern, nUnitType != UNIT_PLAYER ? COLLIDE_MASK_MONSTER_PATH : COLLIDE_MASK_PLAYER_PATH))
    {
        return 0;
    }

    PATH_SetPathTarget(pUnit->pDynamicPath, pTarget);
    SKILLS_ResurrectUnit(pGame, pTarget);

    const int nTargetType = pTarget ? pTarget->dwUnitType : UNIT_TYPES;
    if (nTargetType == UNIT_MONSTER)
    {
        const int nMode = MONSTERSPAWN_GetResurrectMode(pTarget, 1);
        D2ModeChangeStrc tModeChange;
        MONSTERMODE_GetModeChangeInfo(pTarget, nMode, &tModeChange);
        MONSTERSPAWN_GetResurrectMode(pTarget, 1);
        D2GAME_ModeChange_6FC65220(pGame, &tModeChange, nMode != MONMODE_SEQUENCE);
    }

    if (pSkillsTxtRecord->wSrvOverlay >= 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
    }

    return 1;
}

enum D2C_G4Constants
{
    UNITFLAGEX_TELEPORTED = 0x10000,
};

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit);                                                     // 0x0064C040

// 0x005CCC80
int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const int nX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    const int nY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
    if (!pRoom)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner)
        {
            pRoom = UNITS_GetRoom(pOwner);
        }
    }

    if (!SUNIT_TeleportUnit(pGame, pUnit, pRoom, nX, nY, 0, 0))
    {
        return 0;
    }

    UNITROOM_RefreshUnit(pUnit);
    pUnit->dwFlagEx |= UNITFLAGEX_TELEPORTED;
    return 1;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }
    return 0;
}

// 0x005CCD10
int __fastcall SKILLS_SrvDo099_PrimePoisonNova(D2GameStrc* game,D2UnitStrc* unit,int skill,int level)
{
 D2MissileStrc params;
 D2SkillsTxt* record=SKILLS_GetSkillsTxtRecord(skill);
 if(!record) return 0;
 const int missileId=record->wSrvMissileA;
 D2MissilesTxt* missileRecord=SKILLS_GetMissilesTxtRecord(missileId);
 if(missileRecord) {
  if(unit) unit->dwFlags|=0x40;
  memset(&params,0,sizeof(params));
  params.dwFlags=31;
  params.pOwner=unit;
  params.pOrigin=unit;
  params.nMissile=missileId;
  params.nX=CLIENTS_GetUnitX(unit);
  params.nY=CLIENTS_GetUnitY(unit);
  params.nSkillLevel=level;
  params.nLoops=SKILLS_EvaluateSkillFormula(unit,record->dwCalc[0],skill,level);
  params.nVelocity=missileRecord->dwParam[0]<<6;
  int step=SKILLS_EvaluateSkillFormula(unit,record->dwCalc[1],skill,level);
  if(step<1) step=1;
  for(int i=0;i<16;i+=2) {
   params.nTargetX=gnPrimePoisonNovaX[i];
   params.nTargetY=gnPrimePoisonNovaY[i];
   sub_0059FA30(game,&params);
  }
  params.nVelocity=missileRecord->dwParam[1]<<6;
  if(step>1) {
   for(int i=0;i<15;i+=step) {
    params.nTargetX=gnPrimePoisonNovaX[i+1];
    params.nTargetY=gnPrimePoisonNovaY[i+1];
    sub_0059FA30(game,&params);
   }
  }
  return 1;
 }
 return 0;
}

// 0x005CCE80
int __fastcall SKILLS_SrvDo100_DiabCold(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2DamageStrc damage;
    D2SkillsTxt* pSkillsTxt = GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxt)
        return 0;
    if (pUnit)
        pUnit->dwFlags |= 0x40;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        memset(&damage, 0, sizeof(damage));
        damage.wResultFlags |= 1;
        damage.wResultFlags |= *(unsigned short*)&pSkillsTxt->wResultFlags;
        damage.dwHitFlags |= pSkillsTxt->dwHitFlags;
        if (pSkillsTxt->dwHitClass)
            damage.dwHitClass = pSkillsTxt->dwHitClass;
        damage.dwFrzLen = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
        if (!STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0))
            damage.wResultFlags |= 2;
        SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
        if (pSkillsTxt->wSrvOverlay > 0 && pSkillsTxt->wSrvOverlay <= sgptDataTables->nOverlayTxtRecordCount)
            UNITS_SetOverlay(pTarget, pSkillsTxt->wSrvOverlay, 0);
    }
    return 1;
}

// 0x005CCFA0
int __fastcall SKILLS_SrvDo101_FingerMageSpider(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.nMissile = nMissile;
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        missileParams.nTargetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        missileParams.nTargetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }
    else
    {
        missileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath) - CLIENTS_GetUnitX(pUnit);
        missileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath) - CLIENTS_GetUnitY(pUnit);
    }

    MISSILES_CreateMissileFromParams(pGame, &missileParams);
    return pMissilesTxtRecord ? 1 : 0;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->lSeed = lSeed;
    return (unsigned int)lSeed;
}

// 0x005CD110
void __fastcall SKILLS_MissileInit_DiabWall(D2UnitStrc* pMissile, int nInitSeed)
{
    if (pMissile)
    {
        int nFrames = MISSILE_GetTotalFrames(pMissile);
        if (nFrames >= 78)
        {
            nFrames = 77;
            MISSILE_SetTotalFrames(pMissile, 77);
            MISSILE_SetCurrentFrame(pMissile, 77);
        }

        D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
        SEED_InitLowSeed(&pMissile->pSeed, nInitSeed + D2COMMON_10175_PathGetFirstPointX(pPath));

        if ((int)(SEED_RollRandomNumber(&pMissile->pSeed) % 100) >= 20)
        {
            PATH_SetType(pPath, 10);
            PATH_SetNewDistance(pPath, nFrames);
            D2Common_10142(pPath, pMissile, 0);
        }
    }
}

// 0x005CD1C0
int __fastcall SKILLS_SrvDo102_DiabWall(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nSubMissiles = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nMissile = nMissileId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.pInitFunc = SKILLS_MissileInit_DiabWall;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 0;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
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

inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return pUnit ? pUnit->dwUnitType : UNIT_INVALID;
}

// 0x005CD2C0
int __fastcall SKILLS_SrvSt54_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    SKILLS_SetFlags(pSkill, 0);
    SKILLS_SetParam1(pSkill, sub_00451F50(pTarget));
    const int nTargetType = sub_0044BE50(pTarget);
    SKILLS_SetParam2(pSkill, nTargetType);
    PATH_SetTargetUnit(pUnit->pDynamicPath, 0);
    D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, CLIENTS_GetUnitXInline(pTarget), CLIENTS_GetUnitYInline(pTarget));
    return 1;
}

// 0x005CD380
int __fastcall SKILLS_SrvDo103_DiabRun(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[0] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[1]);
        return 1;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);

    if (nFrame == pSkillsTxtRecord->dwParam[2])
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!pPath)
        {
            return 0;
        }

        int nBaseVelocity = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel) << 8;
        if (nBaseVelocity <= 256)
        {
            nBaseVelocity = 256;
        }

        const int nVelocityPct = STATLIST_UnitGetStatValue(pUnit, STAT_VELOCITYPERCENT, 0);
        PATH_SetVelocity(pPath, DATATBLS_ApplyRatio(nBaseVelocity, nVelocityPct, 100), ".\\SKILLS\\SkillMonst.cpp", 1841);
        PATH_SetType(pPath, PATHTYPE_ASTAR);
        D2Common_10142(pPath, pUnit, 0);
        SKILLS_SetFlags(pSkill, 1);
        return 1;
    }

    if (nFrame == pSkillsTxtRecord->dwParam[3])
    {
        pUnit->dwFrameCountPrecise = pSkillsTxtRecord->dwParam[4] << 8;
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[5]);
        return 1;
    }

    if (pUnit->nActionFrame == 1)
    {
        D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam2(pSkill), SKILLS_GetParam1(pSkill));
        if (pTarget)
        {
            if (UNITS_IsInMeleeRange(pUnit, pTarget, 0))
            {
                D2DamageStrc damage;
                pUnit->nActionFrame = 0;
                memset(&damage, 0, sizeof(damage));
                SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);

                if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
                {
                    damage.dwHitFlags = pSkillsTxtRecord->dwHitFlags | 0x20;
                    if (pSkillsTxtRecord->dwHitClass)
                    {
                        damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
                    }

                    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
                    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
                    SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);

                    if (!STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0))
                    {
                        damage.wResultFlags |= 2u;
                    }

                    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
                }
            }
        }
    }

    return 1;
}

// 0x005CD5D0
int __fastcall SKILLS_SrvDo104_DiabPrison(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (!pPath || D2COMMON_10176_PathGetFirstPointY(pPath) != UNIT_OBJECT)
        {
            return 0;
        }

        D2UnitStrc* pObject = SUNIT_GetServerUnit(pGame, UNIT_OBJECT, D2COMMON_10175_PathGetFirstPointX(pPath));
        if (!pObject)
        {
            return 0;
        }

        pTarget = pObject;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pTarget);
    if (pRoom && !DUNGEON_IsRoomInTown(pRoom))
    {
        MONSTERSPAWN_SpawnBonePrison(pGame, UNITS_GetRoom(pTarget), 0, 0, pTarget, nSummonId, 0);
        return 1;
    }

    return 0;
}

// 0x005CD6A0
int __fastcall SKILLS_SrvDo105_DesertTurret(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    int nTargetX;
    int nTargetY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    int nOffsetX = nTargetX - nX;
    int nOffsetY = nTargetY - nY;
    if (!nOffsetX && !nOffsetY)
    {
        return 0;
    }

    int nBaseX = 0;
    int nBaseY = 0;
    if (nOffsetX < 0 && nOffsetY < 0)
    {
        nBaseX = 2;
        nBaseY = -2;
    }
    else if (nOffsetX == 0 && nOffsetY < 0)
    {
        nBaseX = 2;
    }
    else if (nOffsetX > 0 && nOffsetY < 0)
    {
        nBaseX = 2;
        nBaseY = 2;
    }
    else if (nOffsetX > 0 && nOffsetY == 0)
    {
        nBaseY = 2;
    }
    else if (nOffsetX > 0 && nOffsetY > 0)
    {
        nBaseX = -2;
        nBaseY = 2;
    }
    else if (nOffsetX == 0 && nOffsetY > 0)
    {
        nBaseX = -2;
    }
    else if (nOffsetX < 0 && nOffsetY > 0)
    {
        nBaseX = -2;
        nBaseY = -2;
    }
    else if (nOffsetX < 0 && nOffsetY == 0)
    {
        nBaseY = -2;
    }

    const int nSubMissiles = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    nOffsetX -= nSubMissiles / 2 * nBaseX;
    nOffsetY -= nSubMissiles / 2 * nBaseY;

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 3;
    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.pOwner = pUnit;
        missileParams.nX = nX + nOffsetX / 6;
        missileParams.nY = nY + nOffsetX / 6;
        missileParams.nTargetX = nOffsetX;
        missileParams.nTargetY = nOffsetY;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nMissile = nMissileId;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
        nOffsetX += nBaseX;
        nOffsetY += nBaseY;
    }

    return 1;
}

int __stdcall DATATBLS_GetMissileVelocityFromMissilesTxt(int nMissileId, int nLevel);                       // 0x00663270

// 0x005CD870
int __fastcall SKILLS_SrvDo106_ArcaneTower(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    SKILLS_CreateMissileRing(pGame, pUnit, pUnit, nMissileId, nSkillId, nSkillLevel, DATATBLS_GetMissileVelocityFromMissilesTxt(nMissileId, nSkillLevel));
    return 1;
}

struct MissileRecord;

struct MonsterData;

struct Skills;


D2UnitStrc* __stdcall sub_00553540(Game*, D2UnitStrc*); // 0x00553540

void __fastcall SUNITDMG_FreeAttackerDefenderCombatList(Game*, D2UnitStrc*, D2UnitStrc*); // 0x0057C9F0

int __fastcall SKILLS_GetMonFrenzySequenceFrame(D2UnitStrc*); // 0x005CDD30

int __fastcall SKILLS_StartSkill(Game*, D2UnitStrc*, int, int, int); // 0x0056F640

int __fastcall SKILLS_RollMonFrenzyDamage(Game*, D2UnitStrc*, D2UnitStrc*, int, int); // 0x005CDDD0

int __stdcall SKILLS_GetParam1(Skill*); // 0x006444A0

int __fastcall SKILLS_ApplyFrenzyStats(Game*, D2UnitStrc*, int, int); // 0x005D8C70

enum { UNIT_FLAG = 0x40 };

struct MonsterData { char pad0[0xE]; unsigned char variant; };

struct Skills { char pad0[4]; unsigned char flags[4]; char pad8[0x40]; short missile; char pad4A[0x1F2]; };

struct Tables { char pad0[0xB6C]; int missileCount; char padB70[0x28]; Skills* skills; void* linker; int skillCount; };

extern unsigned bitMasks[]; // 0x006CE268

D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(Game*,int,D2UnitStrc*,int,int,int,int,int,int,int); // 0x0056EE90

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(Game*,int,D2UnitStrc*,int,int,int,int,int,int,int); // 0x0056ECB0

typedef char D2SkillsTxtSizeCheck[sizeof(D2SkillsTxt) == 0x23C ? 1 : -1];

typedef char D2UnkNecSkillStrcSizeCheck[sizeof(D2UnkNecSkillStrc) == 0x68 ? 1 : -1];

extern const int gaMonCurseIds[5]; // 0x006E3228

int __fastcall SKILLS_IterateTargetsAroundTarget(D2GameStrc* pGame, unsigned int nFlags, D2UnitStrc* pUnit, int nDistance, int (__fastcall* pCallback)(D2UnitStrc*, void*), void* pArgs); // 0x0056E780

int __fastcall sub_6FD0B450(D2UnitStrc* pUnit, void* pArgs); // 0x005C35C0

unsigned char __stdcall PATH_GetNewDirection(D2DynamicPathStrc*); // 0x00648810

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

// 0x005CD910
int __fastcall SKILLS_SrvSt55_Mosquito(D2GameStrc* pGame,D2UnitStrc* pUnit,int nSkillId,int nSkillLevel)
{
    D2SkillsTxt* pRecord=SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pRecord) return 0;
    D2SkillStrc* pSkill=UNITS_GetUsedSkill(pUnit);
    if (!pSkill) return 0;
    D2UnitStrc* pTarget=SUNIT_GetTargetUnit(pGame,pUnit);
    if (!pTarget) return 0;
    D2SeedStrc seed;
    SEED_InitSeed(&seed);
    SEED_InitLowSeed(&seed,(!pUnit ? -1 : pUnit->dwUnitId)+(!pTarget ? -1 : pTarget->dwUnitId));
    const int minimum=SKILLS_EvaluateSkillFormula(pUnit,pRecord->dwCalc[0],nSkillId,nSkillLevel);
    const int maximum=SKILLS_EvaluateSkillFormula(pUnit,pRecord->dwCalc[1],nSkillId,nSkillLevel);
    int value=ITEMS_RollLimitedRandomNumber(&seed,maximum-minimum)+minimum;
    if (value<1) value=1;
    SKILLS_SetParam1(pSkill,value);
    SKILLS_SetParam2(pSkill,pTarget->dwUnitId);
    const int type=(pTarget ? pTarget->dwUnitType : UNIT_INVALID);
    SKILLS_SetParam3(pSkill,type);
    return 1;
}

int __stdcall SKILLS_GetMinPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647BC0

int __stdcall SKILLS_GetMaxPhysDamage(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bAddWeaponDamage); // 0x00647D00

// 0x005CDA00
int __fastcall SKILLS_SrvDo107_Mosquito(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetServerUnit(pGame, SKILLS_GetParam3(pSkill), SKILLS_GetParam2(pSkill));
    if (!pTarget)
    {
        return 0;
    }

    if (!UNITS_IsInMeleeRange(pUnit, pTarget, 0))
    {
        return 0;
    }

    int nCount = SKILLS_GetParam1(pSkill);
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed)
    {
        return 0;
    }

    const int nMin = SKILLS_GetMinPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    const int nMax = SKILLS_GetMaxPhysDamage(pUnit, nSkillId, nSkillLevel, 1) >> 8;
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    damage.dwPoisDamage = 2 * (ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin) + nMin);
    damage.dwPoisLen = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    damage.dwManaLeech = (ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin) + nMin) << 8;
    damage.dwStamLeech = (ITEMS_RollLimitedRandomNumber(pSeed, nMax - nMin) + nMin) << 8;
    damage.wResultFlags = 1;

    const int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
    const int nHeal = DATATBLS_ApplyRatio(damage.dwPhysDamage, nPercent, 100);
    int nLife = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0) + nHeal;
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pUnit);
    if (nLife >= nMaxLife)
    {
        nLife = nMaxLife;
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nLife, 0);
    SUNITDMG_ExecuteEvents(pGame, pUnit, pTarget, 1, &damage);
    if (!STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0))
    {
        damage.wResultFlags |= 2;
    }

    SUNITDMG_ExecuteMissileDamage(pGame, pUnit, pTarget, &damage);
    --nCount;
    if (nCount > 0)
    {
        SKILLS_SetParam1(pSkill, nCount);
        UNITS_SetAnimationFrame(pUnit, pSkillsTxtRecord->dwParam[0]);
        pUnit->dwFrameCountPrecise = (pUnit->dwFrameCountPrecise & 0xFFFFFF00) + 0x100;
    }

    return 1;
}

void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID);              // 0x0061A270

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                     // 0x00555600

// 0x005CDC10
int __fastcall SKILLS_ConsumeCorpse(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
        if (nType == UNIT_MONSTER && !MONSTERS_GetHirelingTypeId(pTarget) && pTarget->dwAnimMode == 12)
        {
            const int nCorpseLife = STATLIST_GetMaxLifeFromUnit(pTarget);
            DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pTarget), UNIT_MONSTER, !pTarget ? -1 : pTarget->dwUnitId);
            SUNIT_RemoveUnit(pGame, pTarget);

            int nHitpoints = STATLIST_UnitGetStatValue(pUnit, STAT_HITPOINTS, 0);
            const int nMaxHitpoints = STATLIST_GetMaxLifeFromUnit(pUnit);
            if (nCorpseLife > 0)
            {
                nHitpoints += DATATBLS_ApplyRatio(nCorpseLife, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel), 100);
                nHitpoints = D2_MIN(D2_MAX(nHitpoints, 1), nMaxHitpoints);
                STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
            }

            return 1;
        }
    }

    return 0;
}

struct D2AnimSeqTxt;

D2AnimSeqTxt* __stdcall DATATBLS_GetMonSeqTxtRecordFromUnit(D2UnitStrc* pUnit);                             // 0x006633B0

int __stdcall DATATBLS_GetSeqFramePointsCount(D2UnitStrc* pUnit);                                          // 0x006633D0

void __stdcall DATATBLS_GetSequenceEvent(D2AnimSeqTxt* pMonSeqTxt, int nSeqFramePoint, int* pEvent);        // 0x006634C0

// 0x005CDD30
int __fastcall SKILLS_GetMonFrenzySequenceFrame(D2UnitStrc* pUnit)
{
    if (DATATBLS_GetMonSeqTxtRecordFromUnit(pUnit))
    {
        const int nMax = DATATBLS_GetSeqFramePointsCount(pUnit) >> 8;
        const int nCurrent = pUnit->dwSeqFrame >> 8;
        for (int i = nCurrent + 1; i < nMax; ++i)
        {
            int nEvent;
            DATATBLS_GetSequenceEvent(pUnit->pAnimSeq, nCurrent << 8, &nEvent);
            if (nEvent)
            {
                return nEvent;
            }
        }
    }
    else
    {
        const int nMax = pUnit->dwFrameCountPrecise >> 8;
        const int nCurrent = pUnit->nSeqCurrentFramePrecise >> 8;
        if (nMax > pUnit->pAnimData->dwFrames)
        {
            return 0;
        }

        for (int i = nCurrent + 1; i < nMax; ++i)
        {
            if (pUnit->pAnimData->pFrameFlags[nCurrent])
            {
                return pUnit->pAnimData->pFrameFlags[nCurrent];
            }
        }
    }

    return 0;
}


// 0x005CDDD0
int __fastcall SKILLS_RollMonFrenzyDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!pTargetUnit)
    {
        return 0;
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTargetUnit);

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTargetUnit, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTargetUnit, &damage, 0x80);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTargetUnit, 0);

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (pSkill)
    {
        if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
        {
            SKILLS_SetParam1(pSkill, 1);
            return 1;
        }

        SKILLS_SetParam1(pSkill, 0);
    }

    return 1;
}

// 0x005CDF00
int __fastcall SKILLS_HasTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return SUNIT_GetTargetUnit(pGame, pUnit) != 0;
}

// 0x005CE0B0
int __fastcall SKILLS_SrvDo149_NecromageMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    int nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    const unsigned char nComponent = (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) ? pUnit->pMonsterData->nComponent[11] : 0;
    nMissileId += nComponent;
    if (nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !sub_0046ACE0(nMissileId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_01 >> 3] & gdwBitMasks[SKILLSFLAGINDEX_01 & 7])
    {
        SKILLS_CreateMissileFromOrigin(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    }
    else
    {
        SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    }

    return 1;
}

// 0x005CE1B0
int __fastcall SKILLS_SrvDo110_Hireable_RogueMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    int nMissileId = D2COMMON_11039_CheckWeaponIsMissileBased(pUnit, &nSkillLevel);
    if (nMissileId && nMissileId != MISSILE_BOLT)
    {
        if (sub_0046ACE0(nMissileId))
        {
            SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
            return 1;
        }

        return 0;
    }

    nMissileId = pSkillsTxtRecord->wSrvMissileA;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !sub_0046ACE0(nMissileId))
    {
        return 0;
    }

    if (pSkillsTxtRecord->nFlags[1 >> 3] & gdwBitMasks[1 & 7])
    {
        SKILLS_CreateMissileFromOrigin(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        return 1;
    }

    SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    return 1;
}

// 0x005CE2B0
int __fastcall SKILLS_SrvDo112_MonCurseCast(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    const unsigned int nIndex = SEED_RollRandomNumber(&pUnit->pSeed) % 5;
    const int nCurseSkillId = gaMonCurseIds[nIndex];

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nCurseSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nCurseSkillId, nSkillLevel);
    const int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nCurseSkillId, nSkillLevel);

    D2UnkNecSkillStrc args;
    memset(&args, 0, sizeof(args));
    args.pGame = pGame;
    args.pUnit = pUnit;
    args.bResetAi = 0;
    args.nSkillId = nCurseSkillId;
    args.nSkillLevel = nSkillLevel;
    args.nDuration = nDuration;
    args.bUpdateAnimRate = 0;
    args.nAuraTargetState = pSkillsTxtRecord->wAuraTargetState;

    int i = 0;
    do
    {
        args.nAuraStat[i] = -1;
        args.nAuraStatCalc[i] = 0;
        ++i;
    } while (i < 6);

    switch (nIndex)
    {
    case 0u:
    {
        args.nAuraStat[0] = 36;
        args.nAuraStatCalc[0] = -100;
        break;
    }
    case 1u:
    {
        args.nAuraStat[0] = 25;
        args.nAuraStatCalc[0] = -50;
        break;
    }
    case 2u:
    {
        args.nAuraEvent[0] = 5;
        args.nAuraEventFunc[0] = 4;
        break;
    }
    case 3u:
    {
        args.nAuraEvent[0] = 1;
        args.nAuraEventFunc[0] = 5;
        args.nAuraEvent[1] = 2;
        args.nAuraEventFunc[1] = 5;
        break;
    }
    case 4u:
    {
        args.bUpdateAnimRate = 1;
        args.nAuraStat[0] = 67;
        args.nAuraStatCalc[0] = pSkillsTxtRecord->dwParam[6];
        args.nAuraStat[1] = 25;
        args.nAuraStatCalc[1] = -50;
        args.nAuraStat[2] = 36;
        args.nAuraStatCalc[2] = -50;
        args.nAuraStat[3] = 68;
        args.nAuraStatCalc[3] = pSkillsTxtRecord->dwParam[6];
        break;
    }
    default:
    {
        const int nResSubstraction = D2COMMON_11036_GetMonCurseResistanceSubtraction(nSkillLevel, nCurseSkillId);
        args.nAuraStat[0] = 37;
        args.nAuraStatCalc[0] = -nResSubstraction;
        args.nAuraStat[1] = 39;
        args.nAuraStatCalc[1] = -nResSubstraction;
        args.nAuraStat[2] = 41;
        args.nAuraStatCalc[2] = -nResSubstraction;
        args.nAuraStat[3] = 43;
        args.nAuraStatCalc[3] = -nResSubstraction;
        args.nAuraStat[4] = 45;
        args.nAuraStatCalc[4] = -nResSubstraction;
        break;
    }
    }

    return SKILLS_IterateTargetsAroundTarget(pGame, 3, pUnit, nRange, sub_6FD0B450, &args);
}

// 0x005CE4F0
D2UnitStrc* __fastcall SKILLS_CreateSpiderLayMissile(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2UnitStrc* pMissile = 0;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    if (pPath && PATH_HasEnteredNewSubtile(pPath))
    {
        int nXOffset;
        int nYOffset;
        {
            unsigned char spiderLayDirections[8] = { 10, 8, 22, 20, 18, 16, 14, 12 };
            const unsigned char nLayDirection = spiderLayDirections[INVENTORY_GetEightWayDirection(PATH_GetNewDirection(pPath))];
            INVENTORY_GetDirectionDelta(nLayDirection, &nXOffset, &nYOffset);
        }
        const int nSkillLevel = SKILLS_GetSkillLevel(pUnit, SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, SKILL_SPIDERLAY), 1);
        const int nUnitX = UNITS_GetXPositionInline(pUnit);
        const int nUnitY = UNITS_GetYPositionInline(pUnit);
        const int nX = nUnitX + nXOffset;
        const int nY = nUnitY + nYOffset;
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
        D2MissileStrc missileParams;
        memset(&missileParams, 0, sizeof(missileParams));
        missileParams.dwFlags = 0x21;
        missileParams.pOwner = pUnit;
        missileParams.nX = nX;
        missileParams.nY = nY;
        missileParams.nTargetX = nX + 2 * nXOffset;
        missileParams.nTargetY = nY + 2 * nYOffset;
        missileParams.nVelocity = 3;
        missileParams.nSkill = 173;
        missileParams.nSkillLevel = nSkillLevel;
        missileParams.nMissile = MISSILE_SPIDERGOOLAY;
        pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }
    return pMissile;
}

// 0x005CE670
int __fastcall SKILLS_SrvDo111_FetishAura(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    const int nSize = pSkillsTxtRecord->dwParam[3] + 2 * nSkillLevel;
    D2UnitFindDataStrc* pUnitFindData = SKILLS_AllocUnitSearch(pGame, pUnit, nSize, nX, nY);
    for (int i = 0; i < pUnitFindData->nIndex; ++i)
    {
        D2UnitStrc* pFoundUnit = pUnitFindData->pUnitsArray[i];
        if (!SUNIT_AreUnitsHostile(pGame, pUnit, pFoundUnit) && pFoundUnit)
        {
            switch ((unsigned int)pFoundUnit->dwClassId)
            {
            case MONSTER_FETISH1:
            case MONSTER_FETISH2:
            case MONSTER_FETISH3:
            case MONSTER_FETISH4:
            case MONSTER_FETISH5:
            case MONSTER_FETISHBLOW1:
            case MONSTER_FETISHBLOW2:
            case MONSTER_FETISHBLOW3:
            case MONSTER_FETISHBLOW4:
            case MONSTER_FETISHBLOW5:
                if (sub_6FD0B2B0(pGame, pUnit, pFoundUnit))
                {
                    sub_6FD11260(pUnit, pFoundUnit, nSkillId, nSkillLevel, STAT_ATTACKRATE, STATE_FETISHAURA, 0);
                }
                break;
            }
        }
    }

    sub_6FD10E20(pGame, pUnitFindData);
    return 1;
}

#include "gen/data/Source/D2Game/SKILLS/SkillMonst.inc"
