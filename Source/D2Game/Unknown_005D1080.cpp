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
// build: symbol _gaszLanguageNames 0x00741A94

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

struct Seed
{
    unsigned int low;
    unsigned int high;
};

struct Unit
{
    int type;
    int classId;
    unsigned int unknown08;
    int id;
    int mode;
    Monster* monster;
    unsigned int unknown18;
    void* pool;
    Seed seed;
};

struct AuraRequest
{
    Unit* owner;
    Unit* target;
    int skill;
    int level;
    int duration;
    int stat;
    int amount;
    int state;
    void* callback;
};

struct ModeRequest
{
    int mode;
    Unit* target;
    unsigned int field08;
    unsigned int field0C;
    unsigned int field10;
    unsigned int f_14;
    unsigned int f_18;
    unsigned int field1C;
};

extern "C" int __stdcall sub_00646CA0_Evaluate(Unit*, unsigned int, int, int); // 0x00646CA0

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

static inline D2AiControlStrc* AIGENERAL_GetAiControlFromUnitInline(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->pAiControl;
    }

    return 0;
}

// 0x005D1080
static inline int SKILLS_GetThornsPercent(D2UnitStrc* pDefender, D2UnitStrc* pAttacker)
{
    const int nThornsPercent = STATLIST_UnitGetStatValue(pDefender, STAT_THORNS_PERCENT, 0);
    if (nThornsPercent <= 0)
    {
        return 0;
    }
    if (!(pAttacker && pAttacker->dwUnitType == UNIT_PLAYER) && !MONSTERS_GetHirelingTypeId(pAttacker))
    {
        return nThornsPercent;
    }
    return (nThornsPercent + 4) / 8;
}

// 0x005D10C0
void __fastcall SKILLS_ApplyThornsDamage(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, D2DamageStrc* pDamage)
{
    int nPercent;
    const int nThornsPercent = STATLIST_UnitGetStatValue(pDefender, STAT_THORNS_PERCENT, 0);
    if (nThornsPercent <= 0)
    {
        return;
    }

    if (pAttacker && pAttacker->dwUnitType == UNIT_PLAYER || MONSTERS_GetHirelingTypeId(pAttacker))
    {
        nPercent = (nThornsPercent + 4) / 8;
    }
    else
    {
        nPercent = nThornsPercent;
    }

    if (nPercent <= 0)
    {
        return;
    }

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    damage.dwPhysDamage = DATATBLS_ApplyRatio(pDamage->dwPhysDamage, nPercent, 100);
    damage.dwHitClass = 0x8D;
    damage.wResultFlags = 0x4021;
    SUNITDMG_ExecuteEvents(pGame, pDefender, pAttacker, 1, &damage);
    SUNITDMG_ExecuteMissileDamage(pGame, pDefender, pAttacker, &damage);
}

int __stdcall sub_M121_Emit_005D1080(D2UnitStrc* pDefender, D2UnitStrc* pAttacker) { return SKILLS_GetThornsPercent(pDefender, pAttacker); }

// 0x005D1170
int __fastcall SKILLS_SrvDo125_WakeOfDestruction(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    const int nMissileId = SKILLS_GetProgressiveSkillMissileId(pUnit, nSkillId);

    int nTargetX;
    int nTargetY;
    if (nMissileId < 0 || nMissileId >= sgptDataTables->nMissilesTxtRecordCount || !D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 2;
    missileParams.nMissile = nMissileId;
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nTargetX = nTargetX - CLIENTS_GetUnitX(pUnit);
    missileParams.nTargetY = nTargetY - CLIENTS_GetUnitY(pUnit);

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (!pMissile)
    {
        return 0;
    }

    MISSILE_SetTargetX(pMissile, -missileParams.nTargetY);
    MISSILE_SetTargetY(pMissile, missileParams.nTargetX);
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

// 0x005D1280
int __fastcall SKILLS_SrvSt59_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nTimeout < 1)
    {
        nTimeout = 1;
    }

    SKILLS_SetParam1(pSkill, nTimeout + pGame->dwGameFrame);

    if (!STATES_CheckState(pUnit, STATE_INFERNO))
    {
        STATES_ToggleState(pUnit, STATE_INFERNO, 1);
    }

    return 1;
}

// 0x005D1320
static inline void SKILLS_ResetEventsAndScheduleAiThink(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, 0, 0);
    EVENT_SetEvent(pGame, pUnit, 2, pGame->dwGameFrame + 13, 0, 0);
}

void __stdcall sub_M121_Emit_005D1320(D2GameStrc* pGame, D2UnitStrc* pUnit) { SKILLS_ResetEventsAndScheduleAiThink(pGame, pUnit); }

// 0x005D1350
int __fastcall SKILLS_SrvDo126_ImpInferno(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissileId];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pTarget)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        if (pPath)
        {
            D2COMMON_10170_PathSetTargetPos(pPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget));
            UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        }
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.dwFlags = 0x25;
    missileParams.pOwner = pUnit;
    missileParams.nX = CLIENTS_GetUnitX(pUnit);
    missileParams.nY = CLIENTS_GetUnitY(pUnit);
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissileId;
    missileParams.nVelocity = pMissilesTxtRecord->nVel + nSkillLevel * pMissilesTxtRecord->nVelLev / 8;
    missileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    missileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);

    D2UnitStrc* pMissile = MISSILES_CreateMissileFromParams(pGame, &missileParams);
    if (pMissile)
    {
        const int nFrame = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel) + pMissilesTxtRecord->dwParam[1];
        PATH_SetNewDistance(pMissile->pDynamicPath, nFrame);
        MISSILE_SetTotalFrames(pMissile, nFrame);
        MISSILE_SetCurrentFrame(pMissile, nFrame);
    }

    SKILLS_SetInfernoFrame(pSkillsTxtRecord, pUnit);

    if (pGame->dwGameFrame < SKILLS_GetParam1(pSkill) && STATES_CheckState(pUnit, STATE_INFERNO))
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ENDANIM, 0);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_MODECHANGE, pGame->dwGameFrame + 3, 0, 0);
    }
    else
    {
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_MODECHANGE, 0);
        EVENT_SetEvent(pGame, pUnit, EVENTTYPE_AITHINK, pGame->dwGameFrame + 13, 0, 0);
    }

    return 1;
}

int __fastcall D2GAME_GetSummonIdFromSkill(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7); // 0x0056E620

// 0x005D1570
int __fastcall SKILLS_SrvSt60_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2DamageStrc damage;
    memset(&damage, 0, sizeof(damage));
    SKILLS_SetDamageResultFlagsFromSkill(pGame, pUnit, pTarget, pSkillsTxtRecord, nSkillId, nSkillLevel, &damage, 0);
    if (damage.wResultFlags & DAMAGERESULTFLAG_SUCCESSFULHIT)
    {
        damage.dwHitFlags |= 2;
        damage.dwHitFlags |= pSkillsTxtRecord->dwHitFlags;
        if (pSkillsTxtRecord->dwHitClass)
        {
            damage.dwHitClass = pSkillsTxtRecord->dwHitClass;
        }

        SUNITDMG_RollSuckBloodDamage(pGame, pUnit, pTarget, nSkillId, nSkillLevel, &damage);
        const int nPercent = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
        damage.dwPhysDamage += DATATBLS_ApplyRatio(damage.dwPhysDamage, nPercent, 100);
        const int nLifeLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
        const int nManaLeech = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[2], nSkillId, nSkillLevel);
        damage.dwLifeLeech += nLifeLeech;
        damage.dwManaLeech += nManaLeech;
        SUNITDMG_AllocCombat(pGame, pUnit, pTarget, &damage, 0x80);
    }

    return 1;
}

static inline int SKILLDRUID_GetUnitType(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }
    return pUnit->dwUnitType;
}

// 0x005D16A0
int __fastcall SKILLS_SrvDo127_SuckBlood(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
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
        pUnit->dwFlags |= 0x40;
    }

    D2DamageStrc* pDamage = SUNITDMG_GetDamageFromUnits(pUnit, pTarget);
    if (!pDamage)
    {
        return 0;
    }

    if (pDamage->wResultFlags & 1)
    {
        D2UnitStrc* pOwner = 0;
        if (SKILLDRUID_GetUnitType(pUnit) == 1)
        {
            pOwner = AIGENERAL_GetMinionOwner(pUnit);
            if (!pOwner)
            {
                pOwner = pUnit;
            }
        }

        int nLife = STATLIST_UnitGetStatValue(pOwner, STAT_HITPOINTS, 0);
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pOwner);
        const int nAmount = SKILLDRUID_MIN(pDamage->dwPhysDamage, STATLIST_UnitGetStatValue(pTarget, STAT_HITPOINTS, 0));
        nLife += DATATBLS_ApplyRatio(nAmount, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel), 100);
        nLife = SKILLDRUID_MIN(SKILLDRUID_MAX(nLife, 1), nMaxLife);
        STATLIST_SetUnitStat(pOwner, STAT_HITPOINTS, nLife, 0);
    }

    SUNITDMG_DrainItemDurability(pGame, pUnit, pTarget, 0);
    return 1;
}

// 0x005D1800
int __fastcall SKILLS_SrvDo128_CryHelp(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return 0;
    }

    D2AiCmdStrc aiCmd;
    aiCmd.nCmdParam[0] = 1;
    aiCmd.nCmdParam[1] = pTarget->dwUnitType;
    aiCmd.nCmdParam[2] = pTarget->dwUnitId;

    int nTimeout = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nTimeout < 1)
    {
        nTimeout = 1;
    }

    aiCmd.nCmdParam[3] = nTimeout + pGame->dwGameFrame;
    AIGENERAL_AllocCommandsForMinions(pGame, pUnit, &aiCmd);

    if (pSkillsTxtRecord->wSrvOverlay > 0 && pSkillsTxtRecord->wSrvOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        UNITS_SetOverlay(pTarget, pSkillsTxtRecord->wSrvOverlay, 0);
    }

    return 1;
}

// 0x005D18E0
void __fastcall SKILLS_AttachImpToMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pTarget)
    {
        return;
    }

    const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
    if (nBaseId < 0)
    {
        return;
    }

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    if (nBaseId >= nMonStatsCount || nBaseId != MONSTER_IMP1)
    {
        return;
    }

    int nTargetBaseId = CUNIT_GetMonsterBaseId(pTarget);
    if (nTargetBaseId < 0 || nTargetBaseId >= nMonStatsCount)
    {
        nTargetBaseId = -1;
    }

    switch (nTargetBaseId)
    {
    case MONSTER_BARRICADETOWER:
    case MONSTER_SIEGEBEAST1:
        STATES_ToggleState(pUnit, STATE_ATTACHED, 1);
        UNITS_StoreOwner(pUnit, pTarget);
        UNITS_StoreOwner(pTarget, pUnit);
        D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
        sub_6FC35570(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId, nSkillLevel);
        pUnit->dwFlags &= ~UNITFLAG_TARGETFLAGS;
        AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnitInline(pUnit), AISPECIALSTATE_MOUNTING_UNIT);
        break;
    }
}

// 0x005D19D0
void __fastcall SKILLS_DetachImpFromMonster(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pOwner, int nSkillId, int nSkillLevel)
{
    if (!pUnit || !pOwner)
    {
        return;
    }

    const int nBaseId = CUNIT_GetMonsterBaseId(pUnit);
    if (nBaseId < 0)
    {
        return;
    }

    const int nMonStatsCount = sgptDataTables->nMonStatsTxtRecordCount;
    if (nBaseId >= nMonStatsCount || nBaseId != MONSTER_IMP1)
    {
        return;
    }

    int nOwnerBaseId = CUNIT_GetMonsterBaseId(pOwner);
    if (nOwnerBaseId < 0 || nOwnerBaseId >= nMonStatsCount)
    {
        nOwnerBaseId = -1;
    }

    switch (nOwnerBaseId)
    {
    case MONSTER_BARRICADETOWER:
    case MONSTER_SIEGEBEAST1:
        STATES_ToggleState(pUnit, STATE_ATTACHED, 0);
        UNITS_StoreOwner(pUnit, 0);
        UNITS_StoreOwner(pOwner, 0);
        if (UNITS_GetCurrentLifePercentage(pUnit) < 10)
        {
            SUNITDMG_KillMonster(pGame, pUnit, 0, 1);
        }
        else
        {
            pUnit->dwFlags |= UNITFLAG_TARGETFLAGS;
            D2GAME_EVENTS_Delete_6FC34840(pGame, pUnit, EVENTTYPE_ACTIVESTATE, nSkillId);
            AITHINK_ExecuteAiFn(pGame, pUnit, AIGENERAL_GetAiControlFromUnit(pUnit), AISPECIALSTATE_NONE);
        }
        break;
    }
}

// 0x005D1AB0
int __fastcall SKILLS_SrvDo129_ImpTeleport(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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

    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pUnit);
    D2UnitStrc* pTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    if (pOwner)
    {
        int nTargetX;
        int nTargetY;
        D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &nTargetX, &nTargetY);
        SUNIT_TeleportUnit(pGame, pUnit, 0, nTargetX, nTargetY, 0, 0);
        SKILLS_DetachImpFromMonster(pGame, pUnit, pOwner, nSkillId, nSkillLevel);
        return 1;
    }

    if (!pTarget)
    {
        return SKILLS_SrvDo098_MonTeleport(pGame, pUnit, nSkillId, nSkillLevel);
    }

    if (SUNIT_GetOwner(pGame, pTarget) || SUNIT_IsDead(pTarget) || !SUNIT_TeleportUnit(pGame, pUnit, UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 1, 0))
    {
        return 0;
    }

    SKILLS_AttachImpToMonster(pGame, pUnit, pTarget, nSkillId, nSkillLevel);
    return 1;
}

// 0x005D1BF0
int __fastcall SKILLS_SrvSt61_SelfResurrect(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkill, int nLevel)
{
    const unsigned int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
        return 0;
    SKILLS_ResurrectUnit(pGame, pUnit);
    pUnit->dwFlags &= ~14;
    PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 256);
    return 1;
}

// 0x005D1C30
static int __stdcall SKILLS_CreateMissileVolley(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCount, int nMissile, int nSkillId, int nSkillLevel)
{
    D2MissileStrc missileParams = {};
    missileParams.dwFlags = 3;
    missileParams.pOwner = pUnit;
    missileParams.nSkill = nSkillId;
    missileParams.nSkillLevel = nSkillLevel;
    missileParams.nMissile = nMissile;
    missileParams.pInitFunc = SKILLS_MissileInit_ChargedBolt;
    if (!D2GAME_GetXAndYFromTargetUnit_6FD14020(pGame, pUnit, &missileParams.nX, &missileParams.nY))
    {
        return 0;
    }

    for (int i = 0; i < nCount; ++i)
    {
// build: symbol ?gnVolleyOffsetX@* 0x006E3254
        missileParams.nTargetX = gnVolleyOffsetX[i & 3];
// build: symbol ?gnVolleyOffsetY@* 0x006E3264
        missileParams.nTargetY = gnVolleyOffsetY[i & 3];
        missileParams.nInitArg = i;
        MISSILES_CreateMissileFromParams(pGame, &missileParams);
    }

    return 1;
}

// 0x005D1CD0
int __fastcall SKILLS_SrvDo130_VineAttack(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wSrvMissileA;
    if (nMissile <= 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    const int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return 0;
    }

    SKILLS_CreateMissileVolley(pGame, pUnit, nCount, nMissile, nSkillId, nSkillLevel);
    return 1;
}

static inline SkillRecord* GetSkillRecord(int skill)
{
    if (skill < 0)
        return 0;
    if (skill >= gVar_00744304->skillCount)
        return 0;
    return &gVar_00744304->skills[skill];
}

static inline int GetUnitType(Unit* unit)
{
    return unit ? unit->type : 6;
}

static inline AiState* GetAiState(Unit* unit)
{
    if (GetUnitType(unit) == 1 && unit->monster)
        return unit->monster->ai;
    return 0;
}

static inline int SkillChanceSucceeds(Unit* owner, SkillRecord* record, int skill, int level)
{
    int chance = sub_00646CA0_Evaluate(owner, record->chance, skill, level);
    return sub_0045C390_Roll(&owner->seed, 100) < chance;
}

// 0x005D1D70
static void __stdcall SKILLS_ApplyAuraStateToTarget(Unit* owner, Unit* target, int level, int skill)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return;
    AuraRequest request;
    memset(&request, 0, sizeof(request));
    request.owner = owner;
    request.target = target;
    request.skill = skill;
    request.level = level;
    request.duration = sub_00646CA0_Evaluate(owner, record->calc, skill, level);
    request.stat = -1;
    request.state = record->state;
    D2StatListStrc* list = sub_0056E970_Apply(&request);
    if (list)
        sub_005C6CC0_Configure(owner, list, record, skill, level);
}

// 0x005D1E10
static void __stdcall SKILLS_ApplyShapeshift(Unit* owner, int level, int skill, Game* game, Unit* target)
{
    SkillRecord* record = 0;
    if (skill >= 0 && skill < gVar_00744304->skillCount)
        record = &gVar_00744304->skills[skill];
    if (!record)
        return;

    int selected = sub_0056E620_Select(owner, 0, skill, level, &level, 0, 0);
    if (selected < 0)
        return;
    if (GetUnitType(target) != 1)
        return;

    int variant;
    sub_006510C0_ClassInfo(!target ? -1 : target->classId, 0, &variant);
    int resolved = sub_0054DA60_Resolve(selected, variant);
    sub_00574370_Change(game, target, resolved, level);

    AiState* ai;
    if (target->type == 1 && target->monster)
        ai = target->monster->ai;
    else
        ai = 0;
    sub_005B0E00_Ai(game, target, ai, 15);

    ModeRequest mode;
    sub_005A7E60_FillMode(target, level, &mode);
    sub_005A7C20_SetMode(game, &mode, 1);
    sub_00639DB0_SetState(target, 142, 1);

    int ownerType;
    unsigned int ownerId;
    if (owner == 0)
    {
        ownerId = -1;
        ownerType = 6;
    }
    else
    {
        ownerId = owner->id;
        ownerType = owner->type;
    }
    D2StatListStrc* list = sub_006251F0_Allocate(game->pool, 0, 0, ownerType, ownerId);
    if (list)
    {
        sub_00626E10_Attach(target, list, 1);
        sub_006252D0_State(list, 142);
        sub_00627150_Stat(list, 355, resolved, 0);
    }

    if (record->effect > 0 && record->effect < 43)
        sub_005A4850_Effect(game, target, record->effect, 0);
}

// 0x005D1F70
extern "C" int __fastcall SKILLS_SrvDo131_OverseerWhip(Game* game, Unit* owner, int skill, int level)
{
    SkillRecord* record = GetSkillRecord(skill);
    if (!record)
        return 0;
    if (record->state < 0)
        return 0;
    if (record->state >= gVar_00744304->stateCount)
        return 0;
    Unit* target = sub_00553540_Target(game, owner);
    if (target && !sub_005541B0_Inactive(target))
    {
        const int type = GetUnitType(target);
        int bSkip = 1;
        if (type == 1 && sub_00463900_ValidateClass(sub_00463860_BaseClass(target)) == 453)
        {
            bSkip = SkillChanceSucceeds(owner, record, skill, level);
        }
        if (bSkip)
        {
            SKILLS_ApplyAuraStateToTarget(owner, target, level, skill);
        }
        else if (sub_00639DF0_HasState(target, record->state))
        {
            SKILLS_ApplyAuraStateToTarget(owner, target, level, skill);
        }
        else
        {
            SKILLS_ApplyShapeshift(owner, level, skill, game, target);
        }
        return 1;
    }
    return 0;
}

static inline unsigned int AI_RollUnitSeed(D2UnitStrc* pUnit)
{
    const unsigned __int64 lSeed = pUnit->pSeed.nHighSeed + 0x6AC690C5i64 * pUnit->pSeed.nLowSeed;
    pUnit->pSeed.nHighSeed = (unsigned int)(lSeed >> 32);
    pUnit->pSeed.nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int UNITS_TestIgnoreTargetFlag(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlags >> 30) & 1;
    return bResult;
}


// 0x005D2090
int __fastcall SKILLS_SrvDo132_ImpFireMissile(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
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
        pUnit->dwFlags |= UNITFLAG_SKSRVDOFUNC;
    }

    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;

    int nMissileOffset;
    DATATBLS_GetMonsterChainInfo(nClassId, 0, &nMissileOffset);
    SKILLS_CreateMissileAtOffset(pGame, nMissileOffset + nMissileId, pUnit, nSkillId, nSkillLevel, 0, 0, 0, 0, 0);
    return 1;
}

// 0x005D2140
int __fastcall SKILLS_CanImpregnateTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget)
{
    if (!pTarget || pTarget->dwUnitType != UNIT_MONSTER || SUNIT_IsDead(pTarget))
    {
        return 0;
    }

    int nBaseId = CUNIT_GetMonsterBaseId(pTarget);
    if (nBaseId < 0 || nBaseId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        nBaseId = -1;
    }

    switch (nBaseId)
    {
    case MONSTER_PUTRIDDEFILER1:
    case MONSTER_PAINWORM1:
        return 0;
    }

    if (STATES_CheckState(pTarget, STATE_PREGNANT))
    {
        return 0;
    }

    return STATLIST_GetUnitAlignment(pTarget) != 2;
}

#include "gen/data/Source/D2Game/Unknown_005D1080.inc"
