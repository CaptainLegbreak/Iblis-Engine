#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2GameAux.h"
#include "D2Txt.h"
#include "D2Constants.h"
#include "D2UnitData.h"
#include "D2ItemsWorld.h"
#include "D2GameRecords.h"
#include "D2LevelTxt.h"
#include "D2MonModes.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x007419A4

#define STATEMASK_REMHIT 6

struct D2GameStrc;

struct D2UnitStrc;

#define UNITFLAG_SKSRVDOFUNC 0x40

#define AISPECIALSTATE_NONE 0

#define SKILLDRUID_MIN(a, b) ((a) < (b) ? (a) : (b))
#define SKILLDRUID_MAX(a, b) ((a) < (b) ? (b) : (a))

struct D2SummonArgStrc;

struct D2SkillsTxt;

union D2SeedStrc;

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

int __fastcall D2GAME_GetSummonIdFromSkill_6FD15580(D2UnitStrc* pUnit, int bFromMonster, int nSkillId, int nSkillLevel, int* pSpawnMode, int* pX, int* pY); // 0x0056E620

D2UnitStrc* __fastcall D2GAME_SummonPet_6FD14430(D2GameStrc* pGame, D2SummonArgStrc* pSummonArg); // 0x0056D940

void __fastcall D2GAME_UpdateSummonAI_6FC401F0(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int nNodeIndex); // 0x005B1900

int __fastcall D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nPetLevelArg, int nSkillLevel); // 0x005C49E0

void __fastcall D2GAME_SetSummonPassiveStats_6FD0C530(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel); // 0x005C4470

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStat, int nValue, int nLayer); // 0x00627260

void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0

int __fastcall SKILLS_RemoveStatesInGroup(D2UnitStrc* pUnit, int nState, int a3); // 0x0056C740

void __fastcall SKILLS_ApplySkillDelay(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x0056F020

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0

void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0

void __fastcall SKILLS_RemoveStateAndRestoreSkillMode(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList); // 0x005C6C50

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc* pStatList, int nStatId, int nValue, int nLayer); // 0x00627150

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900

void __fastcall SUNITDMG_DrainItemDurability(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int a4); // 0x0057D4F0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

extern "C" void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, unsigned int dwValue); // 0x006252D0

extern "C" void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, unsigned int dwValue); // 0x00625CE0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

extern "C" void __stdcall STATLIST_SetListExpireFrame(D2StatListStrc* pStatList, int nValue); // 0x006260B0

void __stdcall STATES_ToggleGfxStateFlag(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639E30

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetParam1(D2SkillStrc* pSkill); // 0x006444A0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __fastcall SKILLS_GetProgressiveSkillMissileId(D2UnitStrc* pUnit, int nSkillId); // 0x005D3CF0

D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams); // 0x0059FA30

void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710

void __stdcall MISSILE_SetTargetY(D2UnitStrc* pMissile, int nTargetY); // 0x0064A760

int __stdcall SKILLS_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel); // 0x005C7B10

typedef void(__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nInitSeed);

unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390

int __fastcall D2GAME_GetXAndYFromTargetUnit_6FD14020(D2GameStrc* pGame, D2UnitStrc* pUnit, int* pX, int* pY); // 0x0056D2C0

int __fastcall SKILLS_IsMissileTargetPositionClear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMissileId); // 0x0056E450

void __fastcall SUNITMSG_QueueSkillEvent(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char a7); // 0x00571AA0

enum
{
    EVENTTYPE_ACTIVESTATE = 5,
    EVENTTYPE_REMOVESTATE = 12,
};

void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId); // 0x00540E60

void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740

D2UnitStrc* __fastcall D2GAME_CreateMissile_6FD115E0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId, int nX, int nY); // 0x0056EDE0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

void __stdcall STATLIST_FreeStatList(D2StatListStrc* pStatList); // 0x00626CD0

void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

int __stdcall D2Common_11026(int nX, int nY, D2UnitStrc* pUnit, int nMask); // 0x00645950

unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned short nMask); // 0x0064CB30

int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor); // 0x00483360

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define DAMAGERESULTFLAG_SUCCESSFULHIT 1

struct D2StaticPathStrc;

D2UnitStrc* __fastcall SKILLS_CreateMissileAtOffset(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int bCheckItemQuantity); // 0x0056ECB0

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall SKILLS_GetToHitFactor(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x006449F0

unsigned short __fastcall SUNITDMG_GetResultFlags(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int nStatValue, int nRangeOffset); // 0x0057EC10

void __fastcall SUNITDMG_AllocCombat(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, unsigned char nFlags); // 0x0057DBF0

enum D2C_Z09SkillConstants
{
    UNITFLAG_TARGETFLAGS = 0x0E,
    EVENTTYPE_ENDANIM = 1,
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

void __fastcall SUNITDMG_KillMonster(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker, int bSendMsg); // 0x0057CCB0

D2AiControlStrc* __fastcall AIGENERAL_GetAiControlFromUnit(D2UnitStrc* pUnit);                              // 0x00541860

int __stdcall SKILLS_GetParam2(D2SkillStrc* pSkill);                                                        // 0x006444D0

int __stdcall SKILLS_GetParam3(D2SkillStrc* pSkill);                                                        // 0x00644500

int __stdcall SKILLS_GetParam4(D2SkillStrc* pSkill);                                                        // 0x00644530

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue);                                            // 0x00644660

void __fastcall SUNIT_RewindAnimationByFrames(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3);                                 // 0x00553C70

void __stdcall PATH_SetType(D2DynamicPathStrc* pDynamicPath, int nPathType);                                // 0x00648CF0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);               // 0x00649970

int __stdcall SKILLS_GetConcentrationDamageBonus(D2UnitStrc* pUnit, int nSkillId);                          // 0x006461D0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

D2StatListStrc* __fastcall SKILLS_ApplyStateEffect(D2CurseStrc* pCurse);                                               // 0x0056E970

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60

void __fastcall SUNIT_SetUninterruptable(D2UnitStrc* pUnit, int a2);                                                    // 0x005544B0

int __stdcall PATH_GetUnitCollisionPattern(D2UnitStrc* pUnit);                                              // 0x00649180

void __stdcall COLLISION_ResetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EC10

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0

void __stdcall UNITS_SetAnimationFrame(D2UnitStrc* pUnit, int nFrame);                                      // 0x006212C0

void __stdcall PATH_SetNewDistance(D2DynamicPathStrc* pDynamicPath, unsigned char nNewDistance);            // 0x00648E70

void __stdcall PATH_SetStepNum(D2DynamicPathStrc* pDynamicPath, unsigned char nSteps);                      // 0x00649070

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

int __fastcall SKILLS_GetBaseWalkVelocity(D2UnitStrc* pUnit);                                                             // 0x0056E5B0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

unsigned short __fastcall SKILLS_SetDamageResultFlagsFromSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage, int a8); // 0x0056E680

int __fastcall D2GAME_RollElementalDamage_6FD14DD0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E0C0

void __fastcall SKILLS_SetElementalDurationFromSkill(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nLength, int nSkillId);         // 0x0056C840

int __stdcall SKILLS_GetElementalLength(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bFlag);       // 0x00644F20

#define HIT_SUCCESS 1

#define HIT_FLAG 2

#define SOURCE_DAMAGE 128

void __fastcall SUNITDMG_FillDamageValues(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage, int a5, unsigned char nSrcDam); // 0x0057B7D0

enum D2C_F39Constants
{
    MISSILESFLAGINDEX_RETURNFIRE = 9,
    UNITFLAG_NOXP = 0x4000000,
    DAMAGERESULTFLAG_WILLDIE = 2,
    SKILLSFLAGINDEX_01 = 1,
    UNITFLAG_NOTC = 0x20000,
    STATLIST_FLAG_8 = 8,
};

struct D2MonsterRegionStrc;


typedef int (__fastcall* AURACALLBACK)(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId);                                      // 0x0045C4B0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc* pGame, D2UnitStrc* pUnit);                                // 0x00552FD0

D2GameStrc* __fastcall SUNIT_GetGameFromUnit(D2UnitStrc* pUnit);                                            // 0x00554010

void __fastcall SUNIT_SetAlignment(D2UnitStrc* pUnit, unsigned char nAlignNew, int a3);                           // 0x005543B0

int __fastcall SUNIT_AreUnitsHostile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget);                    // 0x00554200

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit);                                                             // 0x005541B0

int __fastcall SUNIT_AreUnitsAligned(D2GameStrc* pGame, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2);           // 0x00554DE0

int __fastcall SKILLS_ApplyAuraToSelf(D2GameStrc* pGame, D2UnitStrc* pUnit, AURACALLBACK pCallback, void* pArgs); // 0x0056B740

int __fastcall SUNIT_TeleportUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int nX, int nY, int a6, int a7); // 0x00554EA0

void __fastcall SKILLS_IterateAuraTargets(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, unsigned int nAuraFilter, AURACALLBACK pCallback, void* pCallbackArgs, int bCheckMonAuraFlag, const char* szFile, int nLine); // 0x0056B7E0

void __fastcall SKILLS_AddElementalDamage(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nElementalType, int nDamage, int nElementalLength, int* pStatId, int* pElementalType); // 0x0056C8E0

int __fastcall SKILL_ComputePeriodicRate(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x0056CD50

D2UnitEventStrc* __fastcall SKILLS_RegisterUnitEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnitEventType, int nSkillId, int nSkillLevel, int nEventFunc, int a7, int a8); // 0x0056E740

int __fastcall D2GAME_SKILLMANA_AuraConsume_6FD10C90(D2UnitStrc* pUnit, int nManaCost); // 0x0056C110

D2UnitFindDataStrc* __fastcall SKILLS_AllocUnitSearch(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSize, int nX, int nY); // 0x0056C210

D2UnitStrc* __fastcall SKILLS_CreateMissileFromOrigin(D2GameStrc* pGame, int nMissileId, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nTargetX, int nTargetY, int a10); // 0x0056EE90

int __fastcall SUNITDMG_ApplyDamageBonuses(D2UnitStrc* pUnit, int bGetStats, D2UnitStrc* pItem, int nMinDmg, int nMaxDmg, int nDamagePercent, int nDamage, unsigned char nSrcDam); // 0x0057B420

void __fastcall SUNITDMG_ExecuteEvents(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int bMissile, D2DamageStrc* pDamage); // 0x0057C6C0

void __fastcall SUNITDMG_ExecuteMissileDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage); // 0x0057CEE0

void __fastcall SUNITEVENT_Unregister(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimerQueueNo, int a4);    // 0x005C0B50

void __fastcall SKILLS_ApplyPassiveStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6DC0

D2DamageStrc* __fastcall SUNITDMG_GetDamageFromUnits(D2UnitStrc* pUnit, D2UnitStrc* pTarget);               // 0x0057D690

void __fastcall SUNITDMG_RollSuckBloodDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, D2DamageStrc* pDamage); // 0x0057E270

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

int __fastcall MONSTERSPAWN_SpawnBonePrison(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int a3, int a4, D2UnitStrc* pTargetUnit, int a6, short a7); // 0x005B34C0

int __fastcall SKILLS_SrvSt32_Conversion_Bash_Stun_Concentrate_BearSmite(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7EA0

void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom, int bDebug); // 0x00545CD0

void __fastcall MONSTERREGION_UndoMonsterKill(D2MonsterRegionStrc** ppMonsterRegion, D2UnitStrc* pUnit);                     // 0x00547E90

void __fastcall MONSTER_UpdateAiCallbackEvent(D2GameStrc* pGame, D2UnitStrc* pUnit);                        // 0x00573780

int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3);         // 0x005A7C20

void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange);  // 0x005A7E60

int __fastcall MONSTERSPAWN_GetResurrectMode(D2UnitStrc* pUnit, int a2);                                    // 0x005FD7B0

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit);                                         // 0x0058F0D0

void __fastcall AIGENERAL_AllocCommandsForMinions(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiCmdStrc* pAiCmd); // 0x0058F730

int __fastcall SKILLS_SrvDo098_MonTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005CCC80

void __fastcall SKILLS_AttachImpToMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel); // 0x005D18E0

void __fastcall SKILLS_DetachImpFromMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel); // 0x005D19D0

D2DifficultyLevelsTxt* __stdcall DATATBLS_GetDifficultyLevelsTxtRecord(int nDifficulty);                   // 0x00611D30

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit);                                       // 0x00620C10

int __stdcall STATES_CheckStateMaskHideOnUnit(D2UnitStrc* pUnit);                                          // 0x0063A320

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit);                                                // 0x0063EE90

int __stdcall MONSTERS_IsDead(D2UnitStrc* pMonster);                                                        // 0x0063EA40

int __stdcall UNITS_GetDirectionToCoords(D2UnitStrc* pUnit, int nNewX, int nNewY);                          // 0x00621DC0

int __stdcall UNITS_IsInMeleeRange(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nRangeBonus);              // 0x00622C40

void __stdcall UNITS_SetOverlay(D2UnitStrc* pUnit, int nOverlay, int a3);                                   // 0x00621E40

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndFlag(D2UnitStrc* pUnit, int nFlag);               // 0x00625760

int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc* pUnit);                                               // 0x00625D10

void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex);                               // 0x0063E7A0

void __stdcall INVENTORY_GetDirectionDelta(unsigned char nDirection, int* pX, int* pY);                  // 0x0063E7E0

void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue);                                           // 0x006445A0

void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue);                                           // 0x006445E0

void __stdcall SKILLS_SetParam4(D2SkillStrc* pSkill, int nValue);                                           // 0x00644620

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath);                           // 0x00648A10

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910

void __stdcall COLLISION_SetMaskWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, int nMask); // 0x0064EA90

int __stdcall PATH_HasEnteredNewSubtile(D2DynamicPathStrc* pPath);                                         // 0x006505C0

int __stdcall DATATBLS_GetMonsterChainInfo(int nMonsterId, int* pMaxChainId, int* pChainId); // 0x006510C0

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

void __fastcall D2GAME_RollPhysicalDamage_6FD14EC0(D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel); // 0x0056E170

int __fastcall SKILLS_ApplyAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY, int nAuraRange, D2DamageStrc* pDamage, unsigned int nAuraFilter); // 0x0056BAD0

int __fastcall SKILLS_DoInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nMissileId); // 0x005C8CA0

void __fastcall SKILLS_StatRemoveCallback_RemoveState(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C8BF0

void __fastcall SKILLS_CurseStateCallback_DefensiveBuff(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x005C9420

int __stdcall PATH_ComputeSquaredDistance(int nX1, int nY1, int nX2, int nY2);                              // 0x006492A0

void __stdcall UNITS_SetAnimationSpeed(D2UnitStrc* pUnit, int nSpeed);                                      // 0x00621780

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

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

int __fastcall SKILLS_AuraCallback_BasicAura(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005CEDC0

int __fastcall SKILLS_AuraCallback_Redemption(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pUnit);        // 0x005D0D70

int __fastcall SKILLS_ResurrectUnit(D2GameStrc* pGame, D2UnitStrc* pUnit);                                  // 0x005CC960

int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender);   // 0x005C96A0

int __fastcall PLAYER_IsBusy(D2UnitStrc* pUnit); // 0x00535060

int __fastcall SKILLDESC_GetSkillParamTwo(int nSkillId); // 0x004EFC20

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

int __fastcall D2GAME_PickupItem_6FC43340(D2GameStrc* pGame, D2UnitStrc* pUnit, int nItemGUID, int* pItemStatus); // 0x00563560

int __fastcall OBJECTS_OperateHandler(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned short nObjectType, int nObjectGUID, int* pResult); // 0x00584420

extern const int gnHydraOffsetX[]; // 0x006E312C

extern const int gnHydraOffsetY[]; // 0x006E3120

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

int __stdcall PATH_GetNumberOfPathPoints(D2DynamicPathStrc* pDynamicPath); // 0x00648780

int __fastcall SUNIT_TeleportUnit(Game*,D2UnitStrc*,D2ActiveRoomStrc*,int,int,int,int); // 0x00554EA0

enum { UNIT_FLAGS = 0xE };

struct D2MissilesTxt;

struct Monster;

enum D2C_Y09ImpInfernoConstants
{
    EVENTTYPE_MODECHANGE = 0,
    EVENTTYPE_AITHINK = 2,
};

void __fastcall SKILLS_SetInfernoFrame(D2SkillsTxt* pSkillsTxtRecord, D2UnitStrc* pUnit); // 0x005CC440

struct Game
{
    unsigned char pad[28];
    void* pool;
};


extern "C" int __stdcall sub_00646CA0_Evaluate(D2UnitStrc*, unsigned int, int, int); // 0x00646CA0

struct D2PlayerDataStrc;

struct D2AiCmdStrc;

struct D2MonStatsTxt;

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

__forceinline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

inline int SKILLS_IsValidPetType(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

// 0x005C6910
int __fastcall SKILLS_SrvDo114_Raven(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType((signed char)pSkillsTxtRecord->nPetType))
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    pPet->dwFlags &= 0xFFFFFFFBu;
    STATLIST_SetUnitStat(pPet, STAT_HPREGEN, 0, 0);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C6A80
int __fastcall SKILLS_SrvDo115_Vines(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType((signed char)pSkillsTxtRecord->nPetType))
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.pOwner = pUnit;
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.nMonMode = 8;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);
    STATES_ToggleState(pPet, STATE_VINE_BEAST, 1);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    STATLIST_SetUnitStat(pPet, STAT_LEVEL, nLevel, 0);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C6BF0
int __fastcall SKILLS_GetConvertedMode(D2UnitStrc* pUnit, int nMode)
{
    int nUnitType;
    int nClassId;
    int nNewMode = nMode;

    int nTypeValue;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
        if (nTypeValue == 0)
        {
            return nMode;
        }
    }
    else
    {
        nTypeValue = 6;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nNewMode, gszSkillDruidSourceFile, 156);
    return nNewMode;
}

// 0x005C6C50
void __fastcall SKILLS_RemoveStateAndRestoreSkillMode(D2UnitStrc* pUnit, int nStateId, D2StatListStrc* pStatList)
{
    SKILLS_RemoveStatesInGroup(pUnit, nStateId, 1);

    if (!pStatList)
    {
        return;
    }

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (!pSkill)
    {
        return;
    }

    SKILLS_SetSkillMode(pSkill, SKILLS_GetConvertedMode(pUnit, 10));
    STATES_ToggleState(pUnit, nStateId, 0);
}

// 0x005C6CB0
void __fastcall SKILLS_RemoveAllStatesInGroup(D2UnitStrc* pUnit, int nState)
{
    SKILLS_RemoveStatesInGroup(pUnit, nState, 1);
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

// 0x005C6CC0
void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pStatList)
    {
        return;
    }

    if (!pSkillsTxtRecord)
    {
        pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    }

    if (!pSkillsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 6; ++i)
    {
        const int nStatId = pSkillsTxtRecord->wAuraStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        }

        if (pItemStatCostTxtRecord)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraStatCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStatValue(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_ATTACKRATE)
                {
                    STATLIST_SetStat(pStatList, STAT_OTHER_ANIMRATE, nValue, 0);
                }
            }
        }
    }

    UnitUpdateAnimRateAndVel(pUnit, gszSkillDruidSourceFile, 248);
}

// 0x005C6DC0
void __fastcall SKILLS_ApplyPassiveStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pStatList)
    {
        return;
    }

    if (!pSkillsTxtRecord)
    {
        pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    }

    if (!pSkillsTxtRecord)
    {
        return;
    }

    for (int i = 0; i < 5; ++i)
    {
        const int nStatId = pSkillsTxtRecord->nPassiveStat[i];
        D2ItemStatCostTxt* pItemStatCostTxtRecord = 0;
        if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
        {
            pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        }

        if (pItemStatCostTxtRecord)
        {
            const int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPassiveCalc[i], nSkillId, nSkillLevel);
            if (nValue)
            {
                STATLIST_SetStatValue(pStatList, nStatId, nValue, 0);
                if (nStatId == STAT_ATTACKRATE)
                {
                    STATLIST_SetStat(pStatList, STAT_OTHER_ANIMRATE, nValue, 0);
                }
            }
        }
    }

    UnitUpdateAnimRateAndVel(pUnit, gszSkillDruidSourceFile, 300);
}

// 0x005C6EC0
int __fastcall SKILLS_SrvDo116_Wearwolf_Wearbear(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    if (SKILLS_RemoveStatesInGroup(pUnit, pSkillsTxtRecord->nAuraState, 1))
    {
        SKILLS_ApplySkillDelay(pGame, pUnit, nSkillId, nSkillLevel);
        return 0;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }

    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, pGame->dwGameFrame + nLength, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
    STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRestoreSkillMode);
    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
    STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, pGame->dwGameFrame + nLength, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    if (pSkill)
    {
        SKILLS_SetSkillMode(pSkill, 10);
    }

    return 1;
}

// 0x005C7040
int __fastcall SKILLS_CreateMissileSpread(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int a7)
{
    if (a7)
    {
        SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        --nSubMissiles;
        if (nSubMissiles <= 0)
        {
            return 1;
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 33;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitXInline(pUnit);
    missileParams.nY = CLIENTS_GetUnitYInline(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 1;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

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

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

static inline int SKILLS_CreateSubMissilesInline(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSubMissiles, int nMissileId, int nSkillId, int nSkillLevel, int a7)
{
    if (a7)
    {
        SKILLS_CreateMissileAtOffset(pGame, nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
        --nSubMissiles;
        if (nSubMissiles <= 0)
        {
            return 1;
        }
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x21;
    missileParams.pOwner = pUnit;
    missileParams.nX = UNITS_GetUnitXPositionInline(pUnit);
    missileParams.nY = UNITS_GetUnitYPositionInline(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;

    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nTargetX, &missileParams.nTargetY))
    {
        return 1;
    }

    for (int i = 0; i < nSubMissiles; ++i)
    {
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005C7160
int __fastcall SKILLS_SrvDo117_Firestorm(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nParam <= 0)
    {
        return 0;
    }

    return SKILLS_CreateSubMissilesInline(pGame, pUnit, nParam, nMissileId, nSkillId, nSkillLevel, 1);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x005C72F0
int __fastcall SKILLS_SrvDo118_Twister_Tornado(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nParam <= 0)
    {
        return 0;
    }

    return SKILLS_CreateMissileSpread(pGame, pUnit, nParam, nMissileId, nSkillId, nSkillLevel, 0);
}

inline int SKILLS_IsValidPetType_Inline(int nPetType)
{
    return nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount;
}

// 0x005C7390
int __fastcall SKILLS_SrvDo119_DruidSummon(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType_Inline((signed char)pSkillsTxtRecord->nPetType))
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    int nX;
    int nY;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nX, &nY))
    {
        return 0;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C7520
int __fastcall SKILLS_SummonDruidPetAtOwner(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nSpawnMode;
    const int nSummonId = D2GAME_GetSummonIdFromSkill_6FD15580(pUnit, 0, nSkillId, nSkillLevel, &nSpawnMode, 0, 0);
    if (nSummonId < 0 || !SKILLS_IsValidPetType((signed char)pSkillsTxtRecord->nPetType))
    {
        return 0;
    }

    unsigned char nPetType = pSkillsTxtRecord->nPetType;
    if (nPetType >= sgptDataTables->nPetTypeTxtRecordCount)
    {
        nPetType = 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2SummonArgStrc summonArg = {};
    summonArg.nHcIdx = nSummonId;
    summonArg.dwFlags = 0;
    summonArg.nAiSpecialState = AISPECIALSTATE_NONE;
    summonArg.pOwner = pUnit;
    summonArg.nMonMode = nSpawnMode;
    summonArg.nPetType = nPetType;
    summonArg.nPetMax = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwPetMax, nSkillId, nSkillLevel);

    D2UnitStrc* pPet = D2GAME_SummonPet_6FD14430(pGame, &summonArg);
    if (!pPet)
    {
        return 0;
    }

    D2GAME_UpdateSummonAI_6FC401F0(pGame, pPet, 0, pUnit->dwNodeIndex);

    int nLevel = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nLevel < 1)
    {
        nLevel = 1;
    }

    D2GAME_SKILLS_SetSummonBaseStats_6FD0CB10(pGame, pUnit, pPet, nLevel, nSkillLevel);
    D2GAME_SetSummonPassiveStats_6FD0C530(pGame, pUnit, pPet, nSkillId, nSkillLevel, 0);
    return 1;
}

// 0x005C7690
int __fastcall SKILLS_SrvSt56_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));

    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        if (pSkillsTxtRecord->nEType > 0)
        {
            damage.dwConvPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
            if (damage.dwConvPct > 0)
            {
                damage.nConvType = pSkillsTxtRecord->nEType;
            }
        }
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    }

    unsigned char nSrcDam = pSkillsTxtRecord->nSrcDam;
    if (!nSrcDam)
    {
        nSrcDam = 0x80;
    }

    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);

    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        SKILLS_SetParam1(pSkill, 1);
    }
    else
    {
        SKILLS_SetParam1(pSkill, 0);
    }

    return 1;
}

// 0x005C77C0
int __fastcall SKILLS_SrvDo120_FeralRage_Maul(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 0x2AF) != nSkillId)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    if (!SKILLS_GetParam1(pSkill))
    {
        return 1;
    }

    const int nLength = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    const int nExpireFrame = pGame->dwGameFrame + nLength;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;

        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 1;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    STATLIST_SetListExpireFrame(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, 0xC, nExpireFrame, 0, 0);
    STATES_ToggleGfxStateFlag(pUnit, pSkillsTxtRecord->nAuraState, 1);

    const int nParam = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    const int nValue = SKILLDRUID_MIN(nParam, STATLIST_GetStatValue(pStatList, STAT_SKILL_FRENZY, 0) + 1);

    STATLIST_SetStatIfListIsValid(pStatList, STAT_SKILL_FRENZY, nValue, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nValue);
    return 1;
}

// 0x005C79E0
int __fastcall SKILLS_SrvSt57_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 753) != nSkillId)
    {
        return 0;
    }
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }
    if (pSkillsTxtRecord->nAuraState >= 0 && pSkillsTxtRecord->nAuraState < sgptDataTables->nStatesTxtRecordCount && !STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        return 0;
    }
    SKILLS_SetParam1(pSkill, 0);
    D2DamageStrc damage;
    D2DamageStrc* pDamage = &damage;
    pDamage->wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel), 0);
    if (!(pDamage->wResultFlags & 1))
    {
        return 0;
    }
    SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (pSkillsTxtRecord->nEType > 0)
    {
        SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[3], nSkillId, nSkillLevel);
    }
    SKILLS_SetParam1(pSkill, 1);
    return 1;
}

// 0x005C7B10
int __stdcall SKILLS_ApplyAuraTargetState(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (pSkillsTxtRecord->wAuraTargetState < 0 || pSkillsTxtRecord->wAuraTargetState > sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    const int nExpireFrame = pGame->dwGameFrame + nTimeout;
    if (STATLIST_GetStatListFromUnitAndState(pTarget, pSkillsTxtRecord->wAuraTargetState))
    {
        return 0;
    }

    const unsigned int nUnitGUID = !pTarget ? -1 : pTarget->dwUnitId;
    const int nUnitType = !pTarget ? 6 : pTarget->dwUnitType;

    D2StatListStrc* pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2u, nExpireFrame, nUnitType, nUnitGUID);
    if (!pStatList)
    {
        return 0;
    }

    STATLIST_SetState(pStatList, pSkillsTxtRecord->wAuraTargetState);
    STATLIST_SetStatRemoveCallback(pStatList, (unsigned int)SKILLS_RemoveStateAndRefreshPassives);
    D2COMMON_10475_PostStatToStatList(pTarget, pStatList, 1);
    STATES_ToggleState(pTarget, pSkillsTxtRecord->wAuraTargetState, 1);
    STATLIST_SetListExpireFrame(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pTarget, 0xC, nExpireFrame, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    return 1;
}

// 0x005C7C20
static void __stdcall SKILLS_ApplyRabiesDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nLength, int nSkillLevel)
{
    if (nLength < 10)
    {
        nLength = 10;
    }

    D2DamageStrc damage = {};
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    }

    SKILLS_SetElementalDurationFromSkill(pUnit, &damage, nLength, nSkillId);
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 128);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
}

// 0x005C7CE0
static void __stdcall SKILLS_CreateTargetAuraMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTimeout, int nSkillLevel, D2UnitStrc* pTarget, int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0)
    {
        return;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 0x8000;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pTarget;
    missileParams.pOrigin = pTarget;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nRange = nTimeout;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return;
    }

    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    MISSILE_SetTargetX(pMissile, nUnitType);
    MISSILE_SetTargetY(pMissile, !pUnit ? -1 : pUnit->dwUnitId);
}

// 0x005C7DB0
int __fastcall SKILLS_ApplyTargetAuraAndMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nTimeout, int nSkillId, int nSkillLevel)
{
    if (nSkillLevel <= 0)
    {
        return 0;
    }

    if (SKILLS_ApplyAuraTargetState(pGame, pUnit, pTarget, nTimeout, nSkillId, nSkillLevel))
    {
        SKILLS_CreateTargetAuraMissile(pGame, pUnit, nTimeout, nSkillLevel, pTarget, nSkillId);
    }
    return 1;
}

// 0x005C8AD0
int __fastcall SKILLS_SrvDo121_Rabies(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, gszSkillDruidSourceFile, 967) != nSkillId || !SKILLS_GetParam1(pSkill))
    {
        return 0;
    }

    SKILLS_SetParam1(pSkill, 0);
    sub_6FD00370(pGame, pUnit, nSkillLevel);
    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);

    const int nLength = SKILLS_GetElementalLength(pUnit, nSkillId, nSkillLevel, 1);
    SKILLS_ApplyTargetAuraAndMissile(pGame, pUnit, pTarget, nLength, nSkillId, nSkillLevel);
    SKILLS_ApplyRabiesDamage(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nLength, nSkillLevel);
    return 1;
}

// 0x005C8BC0
extern "C" int __fastcall SKILLS_GetSkillsTxtParam7(int nSkillId)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    return pSkillsTxtRecord->dwParam[6];
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
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

inline unsigned char UNITS_GetMonsterComponent(D2UnitStrc* pUnit, int nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent[nComponent];
    }

    return 0;
}

static inline D2SkillsTxt* GetRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline int DeleteEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 5, nSkillId);
    return 0;
}

int __fastcall SKILLS_AuraCallback_StaticField(D2AuraCallbackStrc* pAuraCallback, D2UnitStrc* pDefender); // 0x005C96A0
inline int m12_Abs(int n)
{
    return n < 0 ? -n : n;
}

// 0x005C7E00
int __fastcall SKILLS_SrvSt58_FireClaws(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord) return 0;
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget) return 0;
    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & HIT_SUCCESS)
    {
        damage.dwHitFlags |= HIT_FLAG;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        damage.dwEnDmgPct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, SOURCE_DAMAGE);
    }
    return 1;
}

// 0x005C7F10
int __fastcall SKILLS_SrvDo122_Hunger(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & 1)
    {
        damage.dwHitFlags |= 2;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        SUNITDMG_FillDamageValues(pGame, pUnit, pTarget, &damage, 0, pSkillsTxtRecord->nSrcDam);
        D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
        const int nDamagePct = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage += DATATBLS_ApplyRatio(damage.dwPhysDamage, nDamagePct, 100);
        const int nLifeLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        const int nManaLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        damage.dwLifeLeech += nLifeLeech;
        damage.dwManaLeech += nManaLeech;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
        SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    }

    return 1;
}

// 0x005C8080
int __fastcall SKILLS_SrvDo123_Volcano(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
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

    if (!SKILLS_IsMissileTargetPositionClear(pGame, pUnit, nMissileId))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const unsigned char nRand = (unsigned char)SEED_RollLimitedRandomNumber(&pUnit->pSeed, 256);

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 1;
    missileParams.pOwner = pUnit;
    missileParams.nX = nX;
    missileParams.nY = nY;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nSkill = nSkillId;
    missileParams.nMissile = nMissileId;

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, nRand);
    SUNITMSG_QueueSkillEvent(pUnit, 0, nSkillId, nSkillLevel, nX, nY, nRand);
    return 1;
}

// 0x005C8190
int __fastcall SKILLS_SrvDo124_Armageddon_Hurricane(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\SKILLS\\SkillDruid.cpp", 1163) != nSkillId)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nParam = SEED_RollLimitedRandomNumber(&pUnit->pSeed, 0x10000);
    int nDuration = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nSkillLevel);
    if (nDuration < 1)
    {
        nDuration = 1;
    }

    const int nExpireFrame = pGame->dwGameFrame + nDuration;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
    if (!pStatList)
    {
        const unsigned int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
        const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
        pStatList = STATLIST_AllocStatList(pGame->pMemoryPool, 2, nExpireFrame, nUnitType, nUnitGUID);
        if (!pStatList)
        {
            return 0;
        }

        STATLIST_SetState(pStatList, pSkillsTxtRecord->nAuraState);
        STATLIST_SetStatRemoveCallback(pStatList, SKILLS_RemoveStateAndRefreshPassives);
        D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 1);
    }

    D2COMMON_10476(pStatList, nExpireFrame);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_REMOVESTATE, nExpireFrame, 0, 0);
    SKILLS_ApplyAuraStatsToStatList(pUnit, pStatList, pSkillsTxtRecord, nSkillId, nSkillLevel);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_SKILL, nSkillId, 0);
    STATLIST_SetStatIfListIsValid(pStatList, STAT_MODIFIERLIST_LEVEL, nSkillLevel, 0);

    const int nFrame = SKILLDESC_GetSkillParamFour(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nFrame, nSkillId, nSkillLevel);
    SKILLS_SetParam1(pSkill, nParam);
    return 1;
}

// 0x005C8380
int __fastcall SKILLS_SrvDo145_PeriodicAreaDamage(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord || nSkillLevel <= 0 || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        return 0;
    }

    if (!STATES_CheckState(pUnit, pSkillsTxtRecord->nAuraState))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        return 0;
    }

    if (!(pSkillsTxtRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, pSkillsTxtRecord->nAuraState);
            if (pStatList)
            {
                D2Common_10474(pUnit, pStatList);
                STATLIST_FreeStatList(pStatList);
            }

            STATES_ToggleState(pUnit, pSkillsTxtRecord->nAuraState, 0);
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
            return 0;
        }
    }

    const int nRange = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    if (nRange <= 0)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        return 0;
    }

    const int nFrame = SKILLDESC_GetSkillParamFour(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
    EVENT_SetEvent(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nFrame, nSkillId, nSkillLevel);

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom))
    {
        return 0;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    D2GAME_RollPhysicalDamage_6FD14EC0(pUnit, &damage, nSkillId, nSkillLevel);
    D2GAME_RollElementalDamage_6FD14DD0(pUnit, &damage, nSkillId, nSkillLevel);
    damage.wResultFlags |= pSkillsTxtRecord->wResultFlags;
    damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
    SKILLS_ApplyAreaDamage(pGame, pUnit, 0, 0, nRange, &damage, pSkillsTxtRecord->dwAuraFilter);
    return 1;
}

static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

// 0x005C8520
int __fastcall SKILLS_SrvDo146_PeriodicRandomMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pRecord = GetRecord(nSkillId);
    if (!pRecord || nSkillLevel <= 0 || pRecord->nAuraState < 0 || pRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!STATES_CheckState(pUnit, pRecord->nAuraState))
        return DeleteEvent(pGame, pUnit, nSkillId);
    if (!(pRecord->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            D2StatListStrc* pList = STATLIST_GetStatListFromUnitAndState(pUnit, pRecord->nAuraState);
            if (pList)
            {
                D2Common_10474(pUnit, pList);
                STATLIST_FreeStatList(pList);
            }
            STATES_ToggleState(pUnit, pRecord->nAuraState, 0);
            return DeleteEvent(pGame, pUnit, nSkillId);
        }
    }
    int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);
    if (nMissileId <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId);
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSkill || !pSeed) return DeleteEvent(pGame, pUnit, nSkillId);
    int nRange = SKILLS_EvaluateSkillFormula(pUnit, pRecord->dwAuraRangeCalc, nSkillId, nSkillLevel);
    if (nRange <= 0) return DeleteEvent(pGame, pUnit, nSkillId);
    int nFrame = SKILLDESC_GetSkillParamFour(nSkillId) + pGame->dwGameFrame;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 5, nSkillId);
    EVENT_SetEvent(pGame, pUnit, 5, nFrame, nSkillId, nSkillLevel);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
    SEED_InitLowSeed(pSeed, SKILLS_GetParam1(pSkill));
    SKILLS_SetParam1(pSkill, SEED_RollLimitedRandomNumber(pSeed, 1000000));
    CLIENTS_GetUnitX(pUnit);
    CLIENTS_GetUnitY(pUnit);
    int nX, nY;
    int i = 0;
    for (; i < 5; ++i)
    {
        int nMax = 2 * nRange + 1;
        nX = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nX += CLIENTS_GetUnitX(pUnit);
        nY = SEED_RollLimitedRandomNumber(pSeed, nMax) - nRange;
        nY += CLIENTS_GetUnitY(pUnit);
        if (D2Common_11026(nX, nY, pUnit, 0x805))
        {
            pRoom = sub_00463740_FindRoomAtPoint(pRoom, nX, nY);
            if (pRoom && !COLLISION_CheckMask(pRoom, nX, nY, 1)) break;
        }
    }
    if (i >= 5) return 0;
    D2GAME_CreateMissile_6FD115E0(pGame, pUnit, nSkillId, nSkillLevel, nMissileId, nX, nY);
    SUNITMSG_QueueSkillEvent(pUnit, 0, nSkillId, nSkillLevel, nX, nY, 0);
    return 1;
}

// 0x005C8780
static int SKILLS_SubtractAbsorbedDamage(int* pDamage, int nValue)
{
    if (nValue <= *pDamage)
    {
        *pDamage -= nValue;
        return 0;
    }

    nValue -= *pDamage;
    *pDamage = 0;
    return nValue;
}

// 0x005C87A0
int __fastcall SKILLS_EventFunc25_AbsorbElementalDamage(D2GameStrc* pGame, int nEvent, D2UnitStrc* pAttacker, D2UnitStrc* pUnit, D2DamageStrc* pDamage, int nSkillId, int nSkillLevel)
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
    if (!pSkillsTxtRecord || pSkillsTxtRecord->nAuraState < 0 || pSkillsTxtRecord->nAuraState >= sgptDataTables->nStatesTxtRecordCount)
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
    if (nValue0)
    {
        if (pDamage->dwFireDamage > 0)
        {
            nValue0 = SKILLS_SubtractAbsorbedDamage(&pDamage->dwFireDamage, nValue0);
        }
        if (pDamage->dwColdDamage > 0)
        {
            nValue0 = SKILLS_SubtractAbsorbedDamage(&pDamage->dwColdDamage, nValue0);
        }
        if (pDamage->dwLtngDamage > 0)
        {
            nValue0 = SKILLS_SubtractAbsorbedDamage(&pDamage->dwLtngDamage, nValue0);
        }
        STATLIST_SetStatIfListIsValid(pStatList, nStat0, nValue0, 0);
    }

    if (nValue0 > 0)
    {
        const int nNewParamValue = DATATBLS_ApplyRatio(nValue0, 100, nValue1);
        const int nOldParamValue = STATLIST_GetStatValue(pStatList, STAT_UNSENTPARAM1, 0);
        if (m12_Abs(nNewParamValue - nOldParamValue >= 5))
        {
            STATES_ToggleGfxStateFlag(pAttacker, pSkillsTxtRecord->nAuraState, 1);
            STATLIST_SetStatIfListIsValid(pStatList, STAT_UNSENTPARAM1, nNewParamValue, 0);
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

// 0x005C8980
int __fastcall SKILLS_AllocTransformSkillCombat(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillLevel)
{
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (!pTarget)
    {
        return 0;
    }

    int nToHit = 0;
    unsigned char nSrcDam = 0x80;
    for (int i = 0; i < sgptDataTables->nTransformStates; i += 1)
    {
        const short nState = sgptDataTables->pTransformStates[i];
        if (STATES_CheckState(pUnit, nState) && DATATBLS_GetStatesTxtRecordInline(nState))
        {
            D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
            if (pStatList)
            {
                const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
                if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                {
                    nToHit += SKILLS_GetToHitFactor(pUnit, nSkillId, nSkillLevel);
                    D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
                    if (pSkillsTxtRecord && pSkillsTxtRecord->nSrcDam)
                    {
                        nSrcDam = pSkillsTxtRecord->nSrcDam;
                    }
                }
            }
        }
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.wResultFlags = SUNITDMG_GetResultFlags(pGame, pUnit, pTarget, nToHit, 0);
    damage.dwHitClass = 1;
    SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, nSrcDam);
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

static inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord_Inline(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

int __fastcall SKILLS_SrvDo073_BlessedHammer(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D0040

int __fastcall SKILLS_SrvDo048_BladeFury(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D68A0
int __fastcall SKILLS_SrvSt28_BladeShield(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D7A00

int __fastcall SKILLS_ApplyWarcryStats(D2GameStrc* pGame, D2UnitStrc* a2, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8290
int __fastcall SKILLS_SrvDo071_Taunt(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D8570
struct D2ActiveRoomStrc;

static __forceinline void HIRELING_StepAside(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pUnit, unsigned char nSteps)
{
    D2DynamicPathStrc* pPath = pOwner->pDynamicPath;
    UNITS_GetPlayerData(pOwner);
    int nX = PATH_GetFinalTargetX(pPath);
    int nY = PATH_GetFinalTargetY(pPath);
    AITACTICS_SetAiParam(pUnit, 7, 0, 0);
    if (D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, nSteps)) return;
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
    if (AITACTICS_WalkAwayFromTarget(pGame, pUnit, pOwner, nSteps, 1)) return;
    AITACTICS_SetAiParam(pUnit, 0, 0, 40);
    AITACTICS_WalkToTargetCoordinates(pGame, pUnit, nX, nY);
}

int __fastcall SKILLS_SrvDo011_ChargedStrike(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005DB850
int __fastcall SKILLS_SrvDo036_ClawsOfThunder_ProgressiveFn2(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D4DB0

int __fastcall SKILLS_SrvDo040_RoyalStrike_ProgressiveFn1(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D5010
int __fastcall SKILLS_SrvDo043_ShockField(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005D5D70

// 0x005E52D0
void __fastcall AITHINK_Fn061_Hireable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2AiTickParamStrc* pTick)
{
    int nMonsterId;
    if (!pUnit) nMonsterId = -1;
    else nMonsterId = pUnit->dwClassId;
    D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
    if (!pOwner)
    {
        if (nMonsterId == MONSTER_ROGUEHIRE)
        {
            AITHINK_ExecuteAiFn(pGame, pUnit, pTick->pAiControl, 5);
        }
        else
        {
            AITHINK_ExecuteAiFn(pGame, pUnit, pTick->pAiControl, 6);
        }
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (pOwner->dwUnitType != UNIT_PLAYER)
    {
        if (nMonsterId == MONSTER_ROGUEHIRE)
        {
            D2AiControlStrc* pControl = pTick->pAiControl;
            AITHINK_ExecuteAiFn(pGame, pUnit, pControl, 5);
            AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
            return;
        }
        D2AiControlStrc* pControl = pTick->pAiControl;
        AITHINK_ExecuteAiFn(pGame, pUnit, pControl, 6);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 10);
        return;
    }
    if (STATES_CheckState(pUnit, STATE_INFERNO)) STATES_ToggleState(pUnit, 12, 0);
    int nMode;
    if (!pUnit) nMode = 0;
    else nMode = pUnit->dwAnimMode;
    if (nMode == 2 || nMode == 15) return;
    D2AiControlStrc* pAi = pTick->pAiControl;
    D2SeedStrc* pSeed = &pUnit->pSeed;
    AIGENERAL_GetCurrentAiCommandFromUnit(pUnit);
    int nFar;
    unsigned int nNear;
    int nSteps;
    if (pAi->dwAiParam[0] > 16 && pAi->dwAiParam[0] < 20)
    {
        nFar = 2 * pAi->dwAiParam[0];
        nNear = pAi->dwAiParam[0];
        nSteps = pAi->dwAiParam[0] >> 1;
    }
    else { nFar = 24; nNear = 16; nSteps = 5; }
    unsigned int nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    int nOwnerMode = pOwner->dwAnimMode;
    if (nDistance > 100)
    {
        AITHINK_PetMove(pGame, pOwner, pUnit, 3, 0, 0, 0);
        return;
    }
    if (nDistance > (unsigned int)nFar)
    {
        AITHINK_PetMove(pGame, pOwner, pUnit, 1, 1, 60, 0);
        return;
    }
    if (nDistance > nNear)
    {
        if (nOwnerMode == 2 || nOwnerMode == 6)
        {
            AITHINK_PetMove(pGame, pOwner, pUnit, 0, 0, 0, 0);
            return;
        }
        if (nOwnerMode == 3)
        {
            AITHINK_PetMove(pGame, pOwner, pUnit, 0, 1, 60, 0);
            return;
        }
    }
    if (nMode != 1)
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 2, 0);
        AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
        return;
    }
    int bRanged;
    switch (nMonsterId)
    {
    case MONSTER_ACT2HIRE: case MONSTER_ACT5HIRE1: case MONSTER_ACT5HIRE2: bRanged = 0; break;
    default: bRanged = 1; break;
    }
    int bBlocked = 0;
    int nPattern = PATH_GetUnitCollisionPattern(pUnit);
    if (COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nPattern, 0x40))
    {
        bBlocked = 1;
        int nChance = 6;
        if (bRanged) nChance = 12;
        if (sub_00472210_SeedRollMasked(pSeed, 128) < nChance)
        {
            AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
            return;
        }
    }
    if (!DUNGEON_IsRoomInTown(UNITS_GetRoom(pUnit)))
    {
        int bCombat;
        D2UnitStrc* pTarget = AIUTIL_SelectAiTargetWithCollisionCheck(pGame, pUnit, &nDistance, &bCombat);
        if (pTarget && nDistance < 25)
        {
            AITHINK_HirelingCombat(pGame, pUnit, nMonsterId, pOwner, pTarget, pSeed, pTick);
            return;
        }
    }
    if (bBlocked)
    {
        AITACTICS_WalkCloseToUnit(pGame, pUnit, 5);
        return;
    }
    int nRegion = D2Common_10095(UNITS_GetRoom(pOwner), CLIENTS_GetUnitX(pOwner), CLIENTS_GetUnitY(pOwner));
    if (D2Common_10095(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)) != nRegion)
    {
        AITHINK_PetMove(pGame, pOwner, pUnit, 0, 1, 60, 0);
        return;
    }
    nDistance = AIUTIL_GetDistanceToCoordinates_FullUnitSize(pUnit, pOwner);
    if (nDistance <= 1)
    {
        HIRELING_StepAside(pGame, pOwner, pUnit, nSteps - 1);
        return;
    }
    if ((int)SEED_RollLimitedRandomNumber(pSeed, 100) < 5) D2GAME_AICORE_WalkToOwner_6FCD0B60(pGame, pUnit, pOwner, nNear);
    else AITACTICS_IdleInNeutralMode(pGame, pUnit, 5);
}

